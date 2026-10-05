/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    Copyright (C) 2026 QMK

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    SK32F0xx/hal_sled_lld.c
 * @brief   SK32F0xx serial LED (SLED) subsystem low level driver code.
 * @details This driver implements the transfer side of the 3Think SLED
 *          controller: the register programming (CR/SR/CDR/TCR/FCR) mirrors
 *          the SK32F0xx_StdPeriph_Driver (sk32f0xx_sled.c) while the DMA
 *          side is built on the native SK32 DMA helper (sk32_dma.c).  Each
 *          of the two SLED groups owns one DMA1 channel (channel 1 for SLED1
 *          and channel 2 for SLED2) that must be routed to the SLED request
 *          line through the SYSCFG CFGR3 remapping, exactly like the vendor
 *          SYSCFG_DMAChannelConfig() API does.
 * @note    The transfers are memory-to-peripheral operations that push a raw
 *          color byte stream into the group data register (SLED->DR[x]);
 *          the write width is selected by the caller and controls how the
 *          hardware fills each 32 bits wide FIFO entry, which determines how
 *          the four output channels of a group are driven:
 *          - @p SLED_WIDTH_8BIT: every byte is replicated 4 times into the
 *            FIFO entry, so all four channels carry the same byte stream (one
 *            light effect, smallest RAM footprint);
 *          - @p SLED_WIDTH_16BIT: every half word is replicated twice, so
 *            CH0 == CH2 and CH1 == CH3 each carry their own stream (two
 *            effects);
 *          - @p SLED_WIDTH_32BIT: every word is stored directly, so each of
 *            the four channels carries its own byte (four effects).
 *          The byte-to-channel mapping is little endian (byte_i of a FIFO
 *          entry is serialized on channel i).
 * @note    The transfer is synchronous: the function waits for the previous
 *          frame (including its reset pulse) to be completely shifted out,
 *          reloads the DMA channel with the requested width, arms the reset
 *          code (CR RSTSTRx) and waits until the hardware reports the reset
 *          completed, so every call produces one complete, self contained
 *          WS2812 frame.  No SLED interrupt is used, the completion is
 *          detected by polling the DMA channel counter and the SLED reset
 *          flag.
 *
 * @addtogroup SK32F0xx_SLED
 * @{
 */

#include "hal.h"
#include "hal_sled_lld.h"

#if HAL_USE_SLED || defined(__DOXYGEN__)

/* The SLED driver allocates two DMA1 channels, so the DMA helper code of
   sk32_dma.c (and dmaInit()) must be part of the build.  The platform
   header (hal_lld.h) defines SK32_DMA_REQUIRED automatically whenever
   HAL_USE_SLED is TRUE, this check only protects direct/standalone uses.*/
#if !defined(SK32_DMA_REQUIRED)
#error "the SLED low level driver requires SK32_DMA_REQUIRED to be defined"
#endif

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   DMA channel identifier used by SLED1 (DMA1 channel 1).
 */
#define SK32_SLED1_DMA_STREAM            SK32_DMA_STREAM_ID(1, 1)

/**
 * @brief   DMA channel identifier used by SLED2 (DMA1 channel 2).
 */
#define SK32_SLED2_DMA_STREAM            SK32_DMA_STREAM_ID(1, 2)

/**
 * @brief   SYSCFG CFGR3 DMA request code of the SLED1 group (group "G1").
 * @note    The request codes are 6 bit values placed in the low 6 bits of
 *          the 8 bits wide per-channel slot of CFGR3, see the vendor
 *          SYSCFG_DMAChannelConfig() (SYSCFG_DMARemap_SLED_G1).
 */
#define SK32_SLED1_DMA_REQ_CODE          0x2FU

/**
 * @brief   SYSCFG CFGR3 DMA request code of the SLED2 group (group "G2").
 */
#define SK32_SLED2_DMA_REQ_CODE          0x30U

/**
 * @brief   Mask of the request code bits inside a CFGR3 channel slot.
 */
#define SK32_SLED_DMA_REQ_MASK           0x3FU

/**
 * @brief   Position of the DMA1 channel request slot in CFGR3.
 * @note    The request code of a channel occupies the low 6 bits of an 8
 *          bits wide slot whose base address is ((channel - 1) * 8):
 *          channel 1 uses bits 0..5, channel 2 bits 8..13 and so on, the
 *          same layout used by the vendor SYSCFG_DMAChannelConfig() and by
 *          the SYSCFG_CFGR3_DMA_CHxREQ field masks of the device header.
 *
 * @param[in] channel   the physical DMA1 channel number (1..4 for CFGR3)
 */
#define SK32_SLED_DMA_SLOT_SHIFT(channel)  (((channel) - 1U) * 8U)

/**
 * @brief   Maximum time in milliseconds waited for the SLED to complete a
 *          frame (shift out plus reset pulse) before the operation is
 *          aborted with @p MSG_TIMEOUT.
 */
#if !defined(SK32_SLED_BUSY_TIMEOUT) || defined(__DOXYGEN__)
#define SK32_SLED_BUSY_TIMEOUT           100
#endif

/**
 * @brief   CCR mode of the SLED DMA transfers base (memory to peripheral,
 *          memory pointer increment, no peripheral increment, priority).
 * @note    The access width bits (PSIZE/MSIZE) are added per transfer from
 *          the selected write width in @p sled_lld_send().
 */
#define SK32_SLED_DMA_MODE               (SK32_DMA_CR_DIR_M2P    |          \
                                          SK32_DMA_CR_MINC        |          \
                                          SK32_DMA_CR_PL(SK32_SLED_DMA_PRIORITY))

/**
 * @brief   Builds the CCR PSIZE/MSIZE access width bits for a SLED write
 *          width.  The memory and peripheral access sizes are kept in sync
 *          so that every DMA beat pushes one FIFO entry of the selected
 *          width.
 *
 * @param[in] width     the SLED write width (@p sled_width_t)
 * @return              The PSIZE | MSIZE bit pattern to OR into the CCR mode.
 */
#define SK32_SLED_DMA_SIZE_MODE(width)                                     \
  ((width) == SLED_WIDTH_16BIT ? (SK32_DMA_CR_PSIZE_HWORD |                \
                                  SK32_DMA_CR_MSIZE_HWORD) :               \
   (width) == SLED_WIDTH_32BIT ? (SK32_DMA_CR_PSIZE_WORD  |                \
                                  SK32_DMA_CR_MSIZE_WORD) :                \
                                 (SK32_DMA_CR_PSIZE_BYTE |                 \
                                  SK32_DMA_CR_MSIZE_BYTE))

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/**
 * @brief   SLED1/SLED2 DMA stream descriptors, one per group.
 */
static const sk32_dma_stream_t *sled_streams[2];

/**
 * @brief   @p TRUE when the driver is started (SLED enabled and DMA
 *          channels allocated).
 */
static bool sled_started;

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Waits for the SLED to terminate the reset pulse of a group.
 * @note    The RSTSTRx bit is set by software to arm the reset code that
 *          the hardware emits once the FIFO and the shift registers have
 *          been drained; the bit is cleared by the hardware when the reset
 *          pulse has been completed.
 *
 * @param[in] group     the SLED group index
 * @retval              The operation result.
 * @retval MSG_OK       the SLED is ready.
 * @retval MSG_TIMEOUT  the reset did not complete in time.
 */
static msg_t sled_lld_wait_reset_done(sled_group_t group) {
  uint32_t mask = sled_lld_rststr_mask(group);
  int      tmo  = SK32_SLED_BUSY_TIMEOUT;

  while ((SLED->CR & mask) != 0U) {
    if (tmo-- <= 0) {
      return MSG_TIMEOUT;
    }
    chThdSleepMilliseconds(1);
  }

  return MSG_OK;
}

/**
 * @brief   Routes a DMA1 channel to the SLED group request line.
 * @note    The remapping code is written into the 6 request bits of the
 *          channel slot of the SYSCFG CFGR3 register, following the vendor
 *          SYSCFG_DMAChannelConfig() register layout (channel 1 uses the
 *          slot at bits 0..5, channel 2 the slot at bits 8..13, ...).
 *
 * @param[in] channel    the physical DMA1 channel number (1..4)
 * @param[in] code       the 6 bit request selection code
 */
static void sled_lld_remap(uint32_t channel, uint32_t code) {
  uint32_t shift = SK32_SLED_DMA_SLOT_SHIFT(channel);

  SYSCFG->CFGR3 = (SYSCFG->CFGR3 & ~(SK32_SLED_DMA_REQ_MASK << shift)) |
                  (code << shift);
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Initializes the SLED driver.
 * @note    The function is idempotent and can be called multiple times
 *          without issues.
 *
 * @init
 */
void sled_lld_init(void) {

  sled_streams[0] = NULL;
  sled_streams[1] = NULL;
  sled_started    = false;
}

/**
 * @brief   Starts the SLED peripheral.
 * @details The SLED APB2 clock and the SYSCFG clock are enabled, the
 *          time-code/baud/polarity registers are programmed, the DMA
 *          channels of the enabled groups are allocated and routed to the
 *          SLED request lines and finally the peripheral is enabled.
 * @note    The output pads must be configured in alternate function 14 by
 *          the application/board code, this driver does not touch the GPIO.
 * @note    The values programmed through @p config match the vendor 3Think
 *          RGBKeyboardSTK reference implementation (T0H = 4, T1H = 15,
 *          TRST = 80, clock divided by 4, baud divided by 32).
 *
 * @param[in] config    pointer to the @p SLEDConfig structure
 *
 * @init
 */
void sled_lld_start(const SLEDConfig *config) {
  uint32_t cr;

  osalDbgCheck(config != NULL);

  if (sled_started) {
    return;
  }

  /* Enabling the SLED APB2 clock and the SYSCFG APB2 clock (the latter is
     needed for the DMA request remapping).*/
  rccEnableAPB2(RCC_APB2ENR_SLEDEN | RCC_APB2ENR_SYSCFGEN, true);
  rccResetAPB2(RCC_APB2ENR_SLEDRST);

  /* FIFO reset.*/
  SLED->FCR = SLED_FCR_FRST;
  SLED->FCR = 0U;

  /* Time codes and clock dividers (they must be programmed before the EN
     bit is set, the same order used by the vendor demonstration code).*/
  SLED->TCR = (uint32_t)((uint32_t)(config->trst_cycles << 16) |            \
                         (uint32_t)(config->t1h_cycles << 8)  |             \
                         (uint32_t)(config->t0h_cycles << 0));
  SLED->CDR = (uint32_t)((uint32_t)(config->baud_prescaler << 8) |          \
                         (uint32_t)(config->prescaler << 0));

  /* Idle and reset polarities, no sync, no interrupts.  The DMA request
     lines of the enabled groups are switched on (DMAEN1/DMAEN2).*/
  cr = SLED->CR;
  cr &= ~(uint32_t)(SLED_CR_EN | SLED_CR_SYNCEN | SLED_CR_RSTSTS |          \
                    SLED_CR_IDLESTS | SLED_CR_SYNCSTS |                     \
                    SLED_CR_DMAEN1 | SLED_CR_INTEN1 |                       \
                    SLED_CR_DMAEN2 | SLED_CR_INTEN2);
  cr |= (config->reset_polarity != SLED_POLARITY_LOW) ? SLED_CR_RSTSTS  : 0U;
  cr |= (config->idle_polarity != SLED_POLARITY_LOW) ? SLED_CR_IDLESTS : 0U;
#if SK32_SLED_USE_SLED1
  cr |= SLED_CR_DMAEN1;
#endif
#if SK32_SLED_USE_SLED2
  cr |= SLED_CR_DMAEN2;
#endif
  SLED->CR = cr;

  /* DMA channels allocation and SYSCFG request remapping.*/
#if SK32_SLED_USE_SLED1
  sled_streams[SLED1] = dmaStreamAlloc(SK32_SLED1_DMA_STREAM,
                                       SK32_SLED_DMA_PRIORITY, NULL, NULL);
  osalDbgAssert(sled_streams[SLED1] != NULL, "SLED1 DMA channel busy");
  sled_lld_remap(1, SK32_SLED1_DMA_REQ_CODE);
#endif

#if SK32_SLED_USE_SLED2
  sled_streams[SLED2] = dmaStreamAlloc(SK32_SLED2_DMA_STREAM,
                                       SK32_SLED_DMA_PRIORITY, NULL, NULL);
  osalDbgAssert(sled_streams[SLED2] != NULL, "SLED2 DMA channel busy");
  sled_lld_remap(2, SK32_SLED2_DMA_REQ_CODE);
#endif

  /* DMA channel base configuration (peripheral address and mode).*/
  if (sled_streams[SLED1] != NULL) {
    dmaStreamSetPeripheral(sled_streams[SLED1], &SLED->DR[0]);
    dmaStreamSetMode(sled_streams[SLED1], SK32_SLED_DMA_MODE);
  }
  if (sled_streams[SLED2] != NULL) {
    dmaStreamSetPeripheral(sled_streams[SLED2], &SLED->DR[1]);
    dmaStreamSetMode(sled_streams[SLED2], SK32_SLED_DMA_MODE);
  }

  /* SLED enable, data written to the FIFO after this point is serialized
     on the configured outputs.*/
  SLED->CR |= SLED_CR_EN;

  sled_started = true;
}

/**
 * @brief   Stops the SLED peripheral.
 * @details The peripheral is disabled, the DMA channels are freed and the
 *          SLED clock is gated off.
 *
 * @init
 */
void sled_lld_stop(void) {

  if (!sled_started) {
    return;
  }

  /* Peripheral disabled and DMA requests gated off.*/
  SLED->CR &= ~(uint32_t)(SLED_CR_EN | SLED_CR_DMAEN1 | SLED_CR_DMAEN2);

  /* DMA channels released.*/
#if SK32_SLED_USE_SLED1
  if (sled_streams[SLED1] != NULL) {
    dmaStreamFree(sled_streams[SLED1]);
    sled_streams[SLED1] = NULL;
  }
#endif
#if SK32_SLED_USE_SLED2
  if (sled_streams[SLED2] != NULL) {
    dmaStreamFree(sled_streams[SLED2]);
    sled_streams[SLED2] = NULL;
  }
#endif

  rccDisableAPB2(RCC_APB2ENR_SLEDEN);

  sled_started = false;
}

/**
 * @brief   Sends one complete frame on a SLED group.
 * @details The function is synchronous: it waits for any previous frame
 *          (data plus reset pulse) to be completely shifted out, reloads
 *          the DMA channel with the new stream using the selected write
 *          width, arms the trailing reset code and waits until the hardware
 *          reports that the whole frame has been transmitted, so every call
 *          produces one complete, self contained WS2812 frame.
 * @note    The write width selects how the hardware fills each FIFO entry
 *          and therefore which output channels are driven:
 *          - @p SLED_WIDTH_8BIT:  every byte is replicated on all four
 *            channels (same effect, GRB/GRB/... programs one LED per 3
 *            bytes) and @p size is a byte count;
 *          - @p SLED_WIDTH_16BIT: the low byte of each half word drives
 *            CH0/CH2 and the high byte CH1/CH3, so @p data must hold
 *            @p size/2 half words (GRB stream of two effects interleaved);
 *          - @p SLED_WIDTH_32BIT: byte_i of each word drives CH_i, so
 *            @p data must hold @p size/4 words (GRB streams of four effects
 *            interleaved).
 *          In every case the byte to channel mapping is little endian
 *          (byte_i -> CH_i of the FIFO entry).
 * @note    The transfer size is limited to
 *          @p SK32_SLED_MAX_TRANSFER_BYTES bytes by the 16 bit DMA counter
 *          and must be an integer number of the selected width.
 * @note    The buffer is not modified by the driver and only needs to stay
 *          valid until the function returns (the transfer is synchronous).
 *
 * @param[in] group     the SLED group identifier (@p SLED1 or @p SLED2)
 * @param[in] width     the data register write width (@p sled_width_t)
 * @param[in] data      pointer to the byte stream to be transmitted
 * @param[in] size      number of bytes of @p data
 * @return              The operation result.
 * @retval MSG_OK       the frame has been transmitted.
 * @retval MSG_RESET    the driver or the group is not started, or the size
 *                      is not a multiple of the selected width.
 * @retval MSG_TIMEOUT  the SLED did not become ready in time.
 *
 * @api
 */
msg_t sled_lld_send(sled_group_t group, sled_width_t width,
                    const uint8_t *data, size_t size) {
  const sk32_dma_stream_t *dmastp;
  uint32_t                 mode;
  msg_t                    ret;
  int                      tmo;
  size_t                   beats;

  osalDbgCheck(SK32_SLED_IS_VALID_GROUP(group));
  osalDbgCheck((width == SLED_WIDTH_8BIT) ||
               (width == SLED_WIDTH_16BIT) ||
               (width == SLED_WIDTH_32BIT));
  osalDbgCheck((data != NULL) || (size == 0U));

  if (!sled_started) {
    return MSG_RESET;
  }

  dmastp = sled_streams[group];
  if ((dmastp == NULL) || (data == NULL)) {
    return MSG_RESET;
  }

  if (size == 0U) {
    return MSG_OK;
  }
  if (size > SK32_SLED_MAX_TRANSFER_BYTES) {
    return MSG_RESET;
  }

  /* The byte stream must be an integer number of the selected data width
     (1, 2 or 4 bytes per FIFO entry).*/
  beats = size / (1U << ((unsigned)width));
  if (beats * (1U << ((unsigned)width)) != size) {
    return MSG_RESET;
  }

  /* Waiting for the previous frame (data plus its trailing reset pulse) to
     be completed: the RSTSTRx bit is cleared by the hardware when the reset
     code has been emitted.  This is the same synchronization used by the
     vendor SLED_updata() (while (SLED->CR & RSTSTRx) ;).  Note that the BUSY
     flag is not suited for this wait: per the user guide the block keeps
     outputting the IDLE code with BUSY stuck high when the FIFO and the
     shift register are empty and RSTSTR is 0.*/
  ret = sled_lld_wait_reset_done(group);
  if (ret != MSG_OK) {
    return ret;
  }

  /* DMA channel reload with the access size matching the write width.*/
  mode = SK32_SLED_DMA_MODE | SK32_SLED_DMA_SIZE_MODE(width);
  dmaStreamDisable(dmastp);
  dmaStreamSetTransactionSize(dmastp, beats);
  dmaStreamSetMemory0(dmastp, data);
  dmaStreamSetMode(dmastp, mode);
  dmaStreamEnable(dmastp);

  /* Arming the reset code that terminates the frame: the hardware starts
     the reset pulse only after the FIFO and the shift registers have been
     drained (the same sequence used by the vendor demonstration code).*/
  SLED->CR |= sled_lld_rststr_mask(group);

  /* Waiting for the DMA to push every FIFO entry into the SLED FIFO.*/
  tmo = SK32_SLED_BUSY_TIMEOUT;
  while (dmaStreamGetTransactionSize(dmastp) != 0U) {
    if (tmo-- <= 0) {
      dmaStreamDisable(dmastp);
      return MSG_TIMEOUT;
    }
    chThdSleepMilliseconds(1);
  }
  dmaStreamDisable(dmastp);

  /* Waiting for the reset pulse to complete: when RSTSTRx is cleared by the
     hardware the whole frame (data plus reset) has been transmitted.*/
  ret = sled_lld_wait_reset_done(group);
  if (ret != MSG_OK) {
    return ret;
  }

  /* Clearing any stale interrupt flag of the group (write-1-to-clear).*/
  SLED->SR = (group == SLED1) ? SLED_SR_INT1 : SLED_SR_INT2;

  return MSG_OK;
}

/**
 * @brief   Sends one complete frame on a SLED group using byte wide (8 bit)
 *          writes.
 * @details Equivalent to @p sled_lld_send(group, SLED_WIDTH_8BIT, data,
 *          size): every byte is replicated on all four output channels of
 *          the group, so the four channels carry the same light effect.
 *
 * @param[in] group     the SLED group identifier (@p SLED1 or @p SLED2)
 * @param[in] data      pointer to the byte stream to be transmitted
 * @param[in] size      number of bytes to be transmitted
 * @return              The operation result.
 * @retval MSG_OK       the frame has been transmitted.
 * @retval MSG_RESET    the driver or the group is not started.
 * @retval MSG_TIMEOUT  the SLED did not become ready in time.
 *
 * @api
 */
msg_t sled_lld_send_bytes(sled_group_t group, const uint8_t *data,
                          size_t size) {

  return sled_lld_send(group, SLED_WIDTH_8BIT, data, size);
}

#endif /* HAL_USE_SLED == TRUE */

/** @} */
