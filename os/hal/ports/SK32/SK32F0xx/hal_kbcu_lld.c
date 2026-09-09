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
 * @file    SK32F0xx/hal_kbcu_lld.c
 * @brief   SK32F0xx KBCU subsystem low level driver source.
 * @details Implements the KBCU (Keyboard Control Unit) peripheral driver in
 *          independent scan mode.  The key matrix is scanned by the hardware
 *          and the statuses are read back through the KSR registers, an
 *          optional interrupt aborts the current cycle and lets the driver
 *          snapshot the key statuses and fire a user callback.  The RGB
 *          (LED) data is streamed through a DMA1 channel in memory to
 *          peripheral mode targeting the @p KBCU->DMAR register.
 *
 * @addtogroup KBCU
 * @{
 */

#include "hal.h"
#include "hal_kbcu_lld.h"

#if HAL_USE_KBCU || defined(__DOXYGEN__)

/* The KBCU driver allocates a DMA1 channel for the RGB (LED) burst, so the
   DMA helper code of sk32_dma.c (and dmaInit()) must be part of the build.
   The platform header (hal_lld.h) defines SK32_DMA_REQUIRED automatically
   whenever HAL_USE_KBCU is TRUE, this check only protects direct/standalone
   uses.*/
#if !defined(SK32_DMA_REQUIRED)
#error "the KBCU low level driver requires SK32_DMA_REQUIRED to be defined"
#endif

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   Maximum number of LED row registers.
 */
#define SK32_KBCU_LED_ROWS               8U

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/**
 * @brief   @p TRUE when the driver is started.
 */
static bool     kbcu_started;

/**
 * @brief   DMA1 channel used to stream the RGB frame to the KBCU.
 */
static const sk32_dma_stream_t *kbcu_stream;

/**
 * @brief   Key status callback, invoked from the KBCU ISR.
 */
static kbcu_key_cb kbcu_cb;

/**
 * @brief   Snapshot of the 6 KSR registers taken inside the ISR.
 */
static uint32_t kbcu_ksr[SK32_KBCU_KSRS];

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Routes the DMA1 channel 4 request line to the KBCU.
 * @note    The remapping code is written into the 6 request bits of the
 *          channel slot of the SYSCFG CFGR3 register, following the vendor
 *          SYSCFG_DMAChannelConfig() register layout (channel 4 uses the
 *          slot at bits 24..29).
 *
 * @param[in] code       the 6 bit request selection code
 */
static void kbcu_remap(uint32_t code) {
  SYSCFG->CFGR3 = (SYSCFG->CFGR3 & ~(SK32_KBCU_DMA_REQ_MASK <<
                                     SK32_KBCU_DMA_SLOT_SHIFT)) |
                  (code << SK32_KBCU_DMA_SLOT_SHIFT);
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if !defined(SK32_KBCU_HANDLER)
#error "SK32_KBCU_HANDLER not defined"
#endif
/**
 * @brief   KBCU interrupt handler.
 * @details Clears the frame/key flags, snapshots the key statuses and fires
 *          the user callback when a key status change was detected.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SK32_KBCU_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  if (KBCU->SR & KBCU_SR_FRAMEF) {
    KBCU->SR &= ~KBCU_SR_FRAMEF;
  }

  if (KBCU->SR & KBCU_SR_KEYF) {
    KBCU->SR &= ~KBCU_SR_KEYF;

    for (uint8_t i = 0U; i < SK32_KBCU_KSRS; i++) {
      kbcu_ksr[i] = KBCU->KSR[i];
    }

    if (kbcu_cb != NULL) {
      kbcu_cb(kbcu_ksr);
    }
  }

  OSAL_IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Initializes the KBCU driver.
 * @note    The function is idempotent and can be called multiple times
 *          without issues.
 *
 * @init
 */
void kbcu_lld_init(void) {

  kbcu_started = false;
  kbcu_stream  = NULL;
  kbcu_cb      = NULL;
}

/**
 * @brief   Starts the KBCU peripheral in independent scan mode.
 * @details Enables the KBCU APB1 clock, programs the CR0/CR1/CR2 fields for
 *          independent mode (the multiplexing field is kept cleared), enables
 *          the KBCU NVIC interrupt and finally sets the @p EN bit.
 * @note    The column/KEY pads must be configured in alternate function mode
 *          by the application/board code, this driver does not touch the GPIO.
 * @note    The interrupt configuration (which sources are enabled) is left to
 *          @p kbcu_lld_itconfig() so that @p kbcu_lld_start() stays minimal.
 *
 * @param[in] config    pointer to the @p KBCUConfig structure
 *
 * @init
 */
void kbcu_lld_start(const KBCUConfig *config) {
  uint32_t cr0;

  osalDbgCheck(config != NULL);

  if (kbcu_started) {
    return;
  }

  /* Enabling the KBCU APB1 clock and resetting the peripheral.*/
  rccEnableKBCU(true);
  rccResetKBCU();

  /* CR0: columns, key/columns effective levels, column mask and cycle
     value.  Independent mode, the managed bits are cleared first.*/
  cr0 = (config->key_effective_level == KBCU_KEY_LEVEL_HIGH) ?
        KBCU_CR0_KIP : 0U;
  cr0 |= (config->columns_effective_level == KBCU_COLUMN_LEVEL_HIGH) ?
         KBCU_CR0_COP : 0U;
  cr0 |= ((uint32_t)((config->columns_num - 15U) << 2)) & KBCU_CR0_CS;
  cr0 |= ((uint32_t)config->column_mask << 16) & KBCU_CR0_CMASK;
  cr0 |= ((uint32_t)config->columns_cycle_value << 24) & KBCU_CR0_CCR;
  KBCU->CR0 = (KBCU->CR0 & ~SK32_KBCU_CR0_OWNED_MASK) | cr0;

  /* CR1: cycle count, clock division, flicker length and dead time.*/
  KBCU->CR1 = (KBCU->CR1 & ~SK32_KBCU_CR1_OWNED_MASK) |
              (uint32_t)config->columns_cycle_count |
              ((uint32_t)config->clock_division << 8) |
              ((uint32_t)config->flicker_length << 16) |
              ((uint32_t)config->dead_time << 24);

  /* Independent scan mode (the multiplexing field stays cleared).*/
  KBCU->CR2 &= ~KBCU_CR2_SM;

  /* NVIC vector; the actual IER sources are programmed by itconfig().*/
  nvicEnableVector(SK32_KBCU_NUMBER, SK32_IRQ_KBCU_PRIORITY);

  /* Peripheral enable.*/
  KBCU->CR0 |= KBCU_CR0_EN;

  kbcu_started = true;
}

/**
 * @brief   Stops the KBCU peripheral.
 * @details Disables any pending RGB DMA, clears all the managed CR0 bits,
 *          disables the NVIC vector and the peripheral clock.
 *
 * @init
 */
void kbcu_lld_stop(void) {

  if (!kbcu_started) {
    return;
  }

  kbcu_lld_led_dma_stop();

  KBCU->CR0 &= ~SK32_KBCU_CR0_OWNED_MASK;
  nvicDisableVector(SK32_KBCU_NUMBER);
  rccDisableKBCU();

  kbcu_started = false;
}

/**
 * @brief   Enables the KBCU peripheral (sets the EN bit).
 */
void kbcu_lld_enable(void) {
  KBCU->CR0 |= KBCU_CR0_EN;
}

/**
 * @brief   Disables the KBCU peripheral (clears the EN bit).
 */
void kbcu_lld_disable(void) {
  KBCU->CR0 &= ~KBCU_CR0_EN;
}

/**
 * @brief   Configures the KBCU interrupt sources and frame count.
 *
 * @param[in] it         OR of the enabled sources (@p kbcu_it_t)
 * @param[in] frame_count frame count value (0x00..0xFF)
 */
void kbcu_lld_itconfig(kbcu_it_t it, uint8_t frame_count) {
  uint32_t ier = (KBCU->IER & ~SK32_KBCU_IER_OWNED_MASK);

  ier |= (uint32_t)it & (KBCU_IER_FRAMEIE | KBCU_IER_COLIE | KBCU_IER_KEYIE);
  ier |= (uint32_t)frame_count << 16;

  KBCU->IER = ier;
}

/**
 * @brief   Installs a key status callback.
 * @note    The callback is invoked from the KBCU ISR context.
 *
 * @param[in] cb         callback function or @p NULL to remove it
 */
void kbcu_lld_set_callback(kbcu_key_cb cb) {
  kbcu_cb = cb;
}

/**
 * @brief   Returns the 8 row statuses of a column.
 *
 * @param[in] column     column index (0..23)
 * @return              The 8 row status bits
 */
uint8_t kbcu_lld_get_column(uint8_t column) {
  return (uint8_t)((KBCU->KSR[column / 4U] >> ((column % 4U) * 8U)) & 0xFFU);
}

/**
 * @brief   Returns the status of a single key.
 *
 * @param[in] column     column index (0..23)
 * @param[in] row        row index (0..7)
 * @retval              @p true if the key is pressed
 * @retval              @p false otherwise
 */
bool kbcu_lld_get_key(uint8_t column, uint8_t row) {
  return (KBCU->KSR[column / 4U] >> (((column % 4U) * 8U) + row)) & 1U;
}

/**
 * @brief   Reads the six KSR registers.
 *
 * @param[out] ksr      pointer to an array of at least 6 elements
 */
void kbcu_lld_read_ksr(uint32_t ksr[SK32_KBCU_KSRS]) {
  for (uint8_t i = 0U; i < SK32_KBCU_KSRS; i++) {
    ksr[i] = KBCU->KSR[i];
  }
}

/**
 * @brief   Returns the key flag register content.
 *
 * @return              The @p SR key flags (KBCU_SR_KEYF bits)
 */
uint32_t kbcu_lld_get_key_flag(void) {
  return KBCU->SR & KBCU_SR_KEYF;
}

/**
 * @brief   Programs a single LED row register.
 * @note    This is the CPU driven path, useful while the DMA channel is not
 *          allocated yet or for small/static outputs.
 *
 * @param[in] row        LED register index (0..7)
 * @param[in] r          red duty
 * @param[in] g          green duty
 * @param[in] b          blue duty
 * @param[in] mask       brightness mask field
 */
void kbcu_lld_led_set(uint8_t row, uint8_t r, uint8_t g, uint8_t b,
                      uint8_t mask) {
  if (row < SK32_KBCU_LED_ROWS) {
    KBCU->LEDR[row] = (uint32_t)r | ((uint32_t)g << 8) |
                      ((uint32_t)b << 16) | ((uint32_t)mask << 24);
  }
}

/**
 * @brief   Configures the KBCU DMA burst base and length.
 * @note    Mirrors the vendor KBCU_DMAConfig() : the base is a word index
 *          into the register window (see @p kbcu_dmabase_t), the burst
 *          length must be between 0x00 and 0x1F.
 *
 * @param[in] base       DMA base address (@p kbcu_dmabase_t)
 * @param[in] burst_length DMA burst length (0x00..0x1F)
 */
void kbcu_lld_dma_config(kbcu_dmabase_t base, uint16_t burst_length) {
  KBCU->DCR = (uint32_t)base | ((uint32_t)burst_length << 8);
}

/**
 * @brief   Starts a memory to peripheral DMA transfer of an RGB frame into
 *          the KBCU (LED) registers.
 * @details On the first call the DMA1 channel is allocated, the SYSCFG
 *          request line is routed to the KBCU and the peripheral clock of the
 *          output path is enabled.  A burst is then programmed by writing the
 *          DCR register (base + burst length) and the channel is armed.  The
 *          application updates the framebuffer in RAM and calls this function
 *          again to reload the frame; the DMA runs in single-shot mode.
 *
 * @param[in] base       DMA base address (@p kbcu_dmabase_t)
 * @param[in] burst_length DMA burst length (0x00..0x1F)
 * @param[in] framebuf   pointer to the RGB frame buffer in RAM
 * @param[in] size       number of bytes to transfer
 */
void kbcu_lld_led_dma_start(kbcu_dmabase_t base, uint16_t burst_length,
                            const uint8_t *framebuf, size_t size) {
  osalDbgCheck(framebuf != NULL);
  osalDbgCheck(size > 0U);

  if (kbcu_stream == NULL) {
    /* Enabling the SYSCFG clock (needed for the request remapping) and the
       KBCU APB1 clock.*/
    rccEnableAPB2(RCC_APB2ENR_SYSCFGEN, true);
    if (!kbcu_started) {
      rccEnableKBCU(true);
    }

    kbcu_remap(SK32_KBCU_DMA_REQ_CODE);

    kbcu_stream = dmaStreamAlloc(SK32_KBCU_DMA_STREAM,
                                 SK32_KBCU_DMA_PRIORITY, NULL, NULL);
    osalDbgAssert(kbcu_stream != NULL, "KBCU DMA channel busy");
  }

  kbcu_lld_dma_config(base, burst_length);

  dmaStreamSetPeripheral(kbcu_stream, &KBCU->DMAR);
  dmaStreamSetMemory0(kbcu_stream, framebuf);
  dmaStreamSetTransactionSize(kbcu_stream, (uint32_t)size);
  dmaStreamSetMode(kbcu_stream, SK32_KBCU_DMA_MODE);

  /* Enabling the KBCU DMA burst (BEN) then arming the channel.*/
  KBCU->CR0 |= KBCU_CR0_BEN;
  dmaStreamEnable(kbcu_stream);
}

/**
 * @brief   Stops and releases the KBCU RGB DMA channel.
 */
void kbcu_lld_led_dma_stop(void) {
  if (kbcu_stream != NULL) {
    dmaStreamDisable(kbcu_stream);
    dmaStreamFree(kbcu_stream);
    kbcu_stream = NULL;
  }
  KBCU->CR0 &= ~KBCU_CR0_BEN;
}

#endif /* HAL_USE_KBCU */

/** @} */