/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian

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
 * @file    SDIOv1/hal_sdc_lld.c
 * @brief   AT32 SDC subsystem low level driver source.
 *
 * @addtogroup SDC
 * @{
 */

#include <string.h>

#include "hal.h"

#if HAL_USE_SDC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*
 * The following definitions are missing from some implementations, fixing
 * as zeroed masks.
 */
#if !defined(SDIO_STS_SBITERR)
#define SDIO_STS_SBITERR        0
#endif

#if !defined(SDIO_INTCLR_SBITERR)
#define SDIO_INTCLR_SBITERR     0
#endif

#if !defined(SDIO_INTEN_SBITERRIEN)
#define SDIO_INTEN_SBITERRIEN   0
#endif

#define SDIO_INTCLR_ALL_FLAGS   0xFFFFFFFFU

#define SDIO_STS_ERROR_MASK                                                 \
  (SDIO_STS_CMDFAIL    | SDIO_STS_DTFAIL    |                               \
   SDIO_STS_CMDTIMEOUT | SDIO_STS_DTTIMEOUT |                               \
   SDIO_STS_TXERRU     | SDIO_STS_RXERRO)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief SDCD1 driver identifier.*/
SDCDriver SDCD1;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/**
 * @brief   SDIO default configuration.
 */
static const SDCConfig sdc_default_cfg = {
  SDC_MODE_4BIT,
  0U
};

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Calculates a clock divider for the specified frequency.
 * @note    The divider is calculated to not exceed the required frequency
 *          in case of non-integer division.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] f         required frequency
 * @return              The CLKCTRL value.
 */
static uint32_t sdc_lld_clkdiv(SDCDriver *sdcp, uint32_t f) {
  uint32_t div;

#if defined(AT32_SDC_MAX_CLOCK)
  /* Optional enforcement of an arbitrary frequency limit.*/
  if (f > AT32_SDC_MAX_CLOCK) {
    f = AT32_SDC_MAX_CLOCK;
  }
#endif

  div = sdcp->config->slowdown + ((48000000U + f - 1U) / f);
  if (div == 1U) {
    return SDIO_CLKCTRL_BYPSEN;
  }

  return  div - 2U;
}

/**
 * @brief   Calculates the value to be put in DTTMR for timeout.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] ms        timeout in milliseconds
 * @return              The DTTMR value.
 */
__STATIC_FORCEINLINE uint32_t sdc_lld_get_timeout(SDCDriver *sdcp,
                                                  uint32_t ms) {
  uint32_t div, clkctrl;

  clkctrl = sdcp->sdio->CLKCTRL;
  if ((clkctrl & SDIO_CLKCTRL_BYPSEN) != 0U) {
    div = 1U;
  }
  else {
    div = (clkctrl & SDIO_CLKCTRL_CLKDIV_Msk) + 2U;
  }
  return (((48000000U / (div * 2U)) / 1000U) * ms);
}

/**
 * @brief   Prepares to handle read transaction.
 * @details Designed for read special registers from card.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[out] buf      pointer to the read buffer
 * @param[in] bytes     number of bytes to read
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @notapi
 */
static bool sdc_lld_prepare_read_bytes(SDCDriver *sdcp,
                                       uint8_t *buf, uint32_t bytes) {
  osalDbgCheck(bytes < 0x1000000);

  sdcp->sdio->DTTMR = sdc_lld_get_timeout(sdcp, AT32_SDC_READ_TIMEOUT_MS);

  /* Checks for errors and waits for the card to be ready for reading.*/
  if (_sdc_wait_for_transfer_state(sdcp))
    return HAL_FAILED;

  /* Prepares the DMA channel for writing.*/
  dmaStreamSetMemory0(sdcp->dma, buf);
  dmaStreamSetTransactionSize(sdcp->dma, bytes / sizeof (uint32_t));
  dmaStreamSetMode(sdcp->dma, sdcp->dmamode | AT32_DMA_CCTRL_DTD_P2M);
  dmaStreamEnable(sdcp->dma);

  /* Setting up data transfer.*/
  sdcp->sdio->INTCLR = SDIO_INTCLR_ALL_FLAGS;
  sdcp->sdio->INTEN  = SDIO_INTEN_DTFAILIEN |
                       SDIO_INTEN_DTTIMEOUTIEN |
                       SDIO_INTEN_SBITERRIEN |
                       SDIO_INTEN_RXERROIEN |
                       SDIO_INTEN_DTCMPLIEN;
  sdcp->sdio->DTLEN  = bytes;

  /* Transaction starts just after TFREN bit setting.*/
  sdcp->sdio->DTCTRL = SDIO_DTCTRL_TFRDIR |
                       SDIO_DTCTRL_TFRMODE | /* Multibyte data transfer.*/
                       SDIO_DTCTRL_DMAEN |
                       SDIO_DTCTRL_TFREN;

  return HAL_SUCCESS;
}

/**
 * @brief   Prepares card to handle read transaction.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] startblk  first block to read
 * @param[in] n         number of blocks to read
 * @param[in] resp      pointer to the response buffer
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @notapi
 */
static bool sdc_lld_prepare_read(SDCDriver *sdcp, uint32_t startblk,
                                 uint32_t n, uint32_t *resp) {

  /* Driver handles data in 512 bytes blocks (just like HC cards). But if we
     have not HC card than we must convert address from blocks to bytes.*/
  if (!(sdcp->cardmode & SDC_MODE_HIGH_CAPACITY))
    startblk *= MMCSD_BLOCK_SIZE;

  if (n > 1U) {
    /* Send read multiple blocks command to card.*/
    if (sdc_lld_send_cmd_short_crc(sdcp, MMCSD_CMD_READ_MULTIPLE_BLOCK,
                                   startblk, resp) || MMCSD_R1_ERROR(resp[0])) {
      return HAL_FAILED;
    }
  }
  else {
    /* Send read single block command.*/
    if (sdc_lld_send_cmd_short_crc(sdcp, MMCSD_CMD_READ_SINGLE_BLOCK,
                                   startblk, resp) || MMCSD_R1_ERROR(resp[0])) {
      return HAL_FAILED;
    }
  }

  return HAL_SUCCESS;
}

/**
 * @brief   Prepares card to handle write transaction.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] startblk  first block to read
 * @param[in] n         number of blocks to write
 * @param[in] resp      pointer to the response buffer
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @notapi
 */
static bool sdc_lld_prepare_write(SDCDriver *sdcp, uint32_t startblk,
                                  uint32_t n, uint32_t *resp) {

  /* Driver handles data in 512 bytes blocks (just like HC cards). But if we
     have not HC card than we must convert address from blocks to bytes.*/
  if (!(sdcp->cardmode & SDC_MODE_HIGH_CAPACITY))
    startblk *= MMCSD_BLOCK_SIZE;

  if (n > 1U) {
    /* Write multiple blocks command.*/
    if (sdc_lld_send_cmd_short_crc(sdcp, MMCSD_CMD_WRITE_MULTIPLE_BLOCK,
                                   startblk, resp) || MMCSD_R1_ERROR(resp[0])) {
      return HAL_FAILED;
    }
  }
  else {
    /* Write single block command.*/
    if (sdc_lld_send_cmd_short_crc(sdcp, MMCSD_CMD_WRITE_BLOCK,
                                   startblk, resp) || MMCSD_R1_ERROR(resp[0])) {
      return HAL_FAILED;
    }
  }

  return HAL_SUCCESS;
}

/**
 * @brief   Wait end of data transaction and performs finalizations.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] n         number of blocks in transaction
 * @param[in] resp      pointer to the response buffer
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 */
static bool sdc_lld_wait_transaction_end(SDCDriver *sdcp, uint32_t n,
                                         uint32_t *resp) {

  /* Note the mask is checked before going to sleep because the interrupt
     may have occurred before reaching the critical zone.*/
  osalSysLock();

  if (sdcp->sdio->INTEN != 0U) {
    osalThreadSuspendS(&sdcp->thread);
  }

  /* Stopping operations, waiting for transfer completion at DMA level, then
     the stream is disabled and cleared.*/
  dmaWaitCompletion(sdcp->dma);
  sdcp->sdio->INTEN  = 0U;
  sdcp->sdio->DTCTRL = 0U;

  if ((sdcp->sdio->STS & SDIO_STS_DTCMPL) == 0) {
    osalSysUnlock();
    return HAL_FAILED;
  }

  /* Clearing status.*/
  sdcp->sdio->INTCLR = SDIO_INTCLR_ALL_FLAGS;

  osalSysUnlock();

  /* Finalize transaction.*/
  if (n > 1U)
    return sdc_lld_send_cmd_short_crc(sdcp, MMCSD_CMD_STOP_TRANSMISSION, 0, resp);

  return HAL_SUCCESS;
}

/**
 * @brief   Gets SDC errors.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] sts       value of the STS register
 *
 * @notapi
 */
static void sdc_lld_collect_errors(SDCDriver *sdcp, uint32_t sts) {
  uint32_t errors = SDC_NO_ERROR;

  if (sts & SDIO_STS_CMDFAIL)
    errors |= SDC_CMD_CRC_ERROR;
  if (sts & SDIO_STS_DTFAIL)
    errors |= SDC_DATA_CRC_ERROR;
  if (sts & SDIO_STS_CMDTIMEOUT)
    errors |= SDC_COMMAND_TIMEOUT;
  if (sts & SDIO_STS_DTTIMEOUT)
    errors |= SDC_DATA_TIMEOUT;
  if (sts & SDIO_STS_TXERRU)
    errors |= SDC_TX_UNDERRUN;
  if (sts & SDIO_STS_RXERRO)
    errors |= SDC_RX_OVERRUN;
  if (sts & SDIO_STS_SBITERR)
    errors |= SDC_STARTBIT_ERROR;

  sdcp->errors |= errors;
}

/**
 * @brief   Performs clean transaction stopping in case of errors.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] n         number of blocks in transaction
 * @param[in] resp      pointer to the response buffer
 *
 * @notapi
 */
static void sdc_lld_error_cleanup(SDCDriver *sdcp,
                                  uint32_t n,
                                  uint32_t *resp) {
  uint32_t sts;

  dmaStreamDisable(sdcp->dma);

  /* Clearing status.*/
  sts                = sdcp->sdio->STS;
  sdcp->sdio->INTCLR = sts;
  sdcp->sdio->DTCTRL = 0U;
  sdc_lld_collect_errors(sdcp, sts);

  if (n > 1U) {
    sdc_lld_send_cmd_short_crc(sdcp, MMCSD_CMD_STOP_TRANSMISSION, 0, resp);
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if !defined(AT32_SDIO_HANDLER)
#error "AT32_SDIO_HANDLER not defined"
#endif
/**
 * @brief   SDIO IRQ handler.
 * @details It just wakes transaction thread, errors handling is performed in
 *          there.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_SDIO_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  osalSysLockFromISR();

  /* Disables the source but the status flags are not reset because the
     read/write functions needs to check them.*/
  SDIO->INTEN = 0U;

  osalThreadResumeI(&SDCD1.thread, MSG_OK);

  osalSysUnlockFromISR();

  OSAL_IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level SDC driver initialization.
 *
 * @notapi
 */
void sdc_lld_init(void) {

  sdcObjectInit(&SDCD1);
  SDCD1.thread = NULL;
  SDCD1.dma    = NULL;
  SDCD1.sdio   = SDIO;
  nvicEnableVector(AT32_SDIO_NUMBER, AT32_SDC_SDIO_IRQ_PRIORITY);
}

/**
 * @brief   Configures and activates the SDC peripheral.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 *
 * @notapi
 */
void sdc_lld_start(SDCDriver *sdcp) {

  /* Checking configuration, using a default if NULL has been passed.*/
  if (sdcp->config == NULL) {
    sdcp->config = &sdc_default_cfg;
  }

  sdcp->dmamode = AT32_DMA_CCTRL_CHPL(AT32_SDC_SDIO_DMA_PRIORITY) |
                  AT32_DMA_CCTRL_PWIDTH_WORD |
                  AT32_DMA_CCTRL_MWIDTH_WORD |
                  AT32_DMA_CCTRL_MINCM;

  /* If in stopped state then clocks are enabled and DMA initialized.*/
  if (sdcp->state == BLK_STOP) {
    sdcp->dma = dmaStreamAllocI(AT32_SDC_SDIO_DMA_STREAM,
                                AT32_SDC_SDIO_IRQ_PRIORITY,
                                NULL,
                                NULL);
    osalDbgAssert(sdcp->dma != NULL, "unable to allocate stream");

#if AT32_DMA_SUPPORTS_DMAMUX
    dmaSetRequestSource(sdcp->dma, AT32_SDC_SDIO_DMAMUX_CHANNEL, AT32_DMAMUX_SDIO);
#endif

    dmaStreamSetPeripheral(sdcp->dma, &sdcp->sdio->BUF);
    crmEnableSDIO(true);
  }

  /* Configuration, card clock is initially stopped.*/
  sdcp->sdio->PWRCTRL = 0U;
  sdcp->sdio->CLKCTRL = 0U;
  sdcp->sdio->DTCTRL  = 0U;
  sdcp->sdio->DTTMR   = 0U;
  sdcp->sdio->INTCLR  = SDIO_INTCLR_ALL_FLAGS;
}

/**
 * @brief   Deactivates the SDC peripheral.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 *
 * @notapi
 */
void sdc_lld_stop(SDCDriver *sdcp) {

  if (sdcp->state != BLK_STOP) {

    /* SDIO deactivation.*/
    sdcp->sdio->PWRCTRL = 0U;
    sdcp->sdio->CLKCTRL = 0U;
    sdcp->sdio->DTCTRL  = 0U;
    sdcp->sdio->DTTMR   = 0U;

    /* DMA stream released.*/
    dmaStreamFreeI(sdcp->dma);
    sdcp->dma = NULL;

    /* Clock deactivation.*/
    crmDisableSDIO();
  }
}

/**
 * @brief   Starts the SDIO clock and sets it to init mode (400kHz or less).
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 *
 * @notapi
 */
void sdc_lld_start_clk(SDCDriver *sdcp) {

  /* Initial clock setting: 400kHz, 1bit mode.*/
  sdcp->sdio->CLKCTRL  = sdc_lld_clkdiv(sdcp, 400000);
  sdcp->sdio->PWRCTRL |= SDIO_PWRCTRL_PS_0 | SDIO_PWRCTRL_PS_1;
  sdcp->sdio->CLKCTRL |= SDIO_CLKCTRL_CLKOEN;

  /* Clock activation delay.*/
  osalThreadSleep(OSAL_MS2I(AT32_SDC_CLOCK_ACTIVATION_DELAY));
}

/**
 * @brief   Sets the SDIO clock to data mode (25/50 MHz or less).
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] clk       the clock mode
 *
 * @notapi
 */
void sdc_lld_set_data_clk(SDCDriver *sdcp, sdcbusclk_t clk) {

  if (SDC_CLK_50MHz == clk) {
    sdcp->sdio->CLKCTRL = (sdcp->sdio->CLKCTRL & ~(SDIO_CLKCTRL_BYPSEN_Msk |
                                                   SDIO_CLKCTRL_PWRSVEN_Msk |
                                                   SDIO_CLKCTRL_CLKDIV_Msk)) |
#if AT32_SDC_SDIO_PWRSVEN
                         sdc_lld_clkdiv(sdcp, 50000000) | SDIO_CLKCTRL_PWRSVEN;
#else
                         sdc_lld_clkdiv(sdcp, 50000000);
#endif
  }
  else {
    sdcp->sdio->CLKCTRL = (sdcp->sdio->CLKCTRL & ~(SDIO_CLKCTRL_BYPSEN_Msk |
                                                   SDIO_CLKCTRL_PWRSVEN_Msk |
                                                   SDIO_CLKCTRL_CLKDIV_Msk)) |
#if AT32_SDC_SDIO_PWRSVEN
                         sdc_lld_clkdiv(sdcp, 25000000) | SDIO_CLKCTRL_PWRSVEN;
#else
                         sdc_lld_clkdiv(sdcp, 25000000);
#endif
  }
}

/**
 * @brief   Stops the SDIO clock.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 *
 * @notapi
 */
void sdc_lld_stop_clk(SDCDriver *sdcp) {

  sdcp->sdio->CLKCTRL = 0U;
  sdcp->sdio->PWRCTRL = 0U;
}

/**
 * @brief   Switches the bus to 1, 4 or 8 bits mode.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] mode      bus mode
 *
 * @notapi
 */
void sdc_lld_set_bus_mode(SDCDriver *sdcp, sdcbusmode_t mode) {
  uint32_t clk = sdcp->sdio->CLKCTRL & ~SDIO_CLKCTRL_BUSWS;

  switch (mode) {
  case SDC_MODE_1BIT:
    sdcp->sdio->CLKCTRL = clk;
    break;
  case SDC_MODE_4BIT:
    sdcp->sdio->CLKCTRL = clk | SDIO_CLKCTRL_BUSWS_0;
    break;
  case SDC_MODE_8BIT:
    sdcp->sdio->CLKCTRL = clk | SDIO_CLKCTRL_BUSWS_1;
    break;
  }
}

/**
 * @brief   Sends an SDIO command with no response expected.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] cmd       card command
 * @param[in] arg       command argument
 *
 * @notapi
 */
void sdc_lld_send_cmd_none(SDCDriver *sdcp, uint8_t cmd, uint32_t arg) {

  sdcp->sdio->ARG = arg;
  sdcp->sdio->CMD = (uint32_t)cmd | SDIO_CMD_CCSMEN;
  while ((sdcp->sdio->STS & SDIO_STS_CMDCMPL) == 0)
    ;
  sdcp->sdio->INTCLR = SDIO_INTCLR_CMDCMPL;
}

/**
 * @brief   Sends an SDIO command with a short response expected.
 * @note    The CRC is not verified.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] cmd       card command
 * @param[in] arg       command argument
 * @param[out] resp     pointer to the response buffer (one word)
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @notapi
 */
bool sdc_lld_send_cmd_short(SDCDriver *sdcp, uint8_t cmd, uint32_t arg,
                            uint32_t *resp) {
  uint32_t sts;

  sdcp->sdio->ARG = arg;
  sdcp->sdio->CMD = (uint32_t)cmd | SDIO_CMD_RSPWT_0 | SDIO_CMD_CCSMEN;
  while (((sts = sdcp->sdio->STS) & (SDIO_STS_CMDRSPCMPL | SDIO_STS_CMDTIMEOUT |
                                     SDIO_STS_CMDFAIL)) == 0)
    ;
  sdcp->sdio->INTCLR = sts & (SDIO_STS_CMDRSPCMPL | SDIO_STS_CMDTIMEOUT |
                              SDIO_STS_CMDFAIL);
  if ((sts & (SDIO_STS_CMDTIMEOUT)) != 0) {
    sdc_lld_collect_errors(sdcp, sts);
    return HAL_FAILED;
  }
  *resp = sdcp->sdio->RSP1;
  return HAL_SUCCESS;
}

/**
 * @brief   Sends an SDIO command with a short response expected and CRC.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] cmd       card command
 * @param[in] arg       command argument
 * @param[out] resp     pointer to the response buffer (one word)
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @notapi
 */
bool sdc_lld_send_cmd_short_crc(SDCDriver *sdcp, uint8_t cmd, uint32_t arg,
                                uint32_t *resp) {
  uint32_t sts;

  sdcp->sdio->ARG = arg;
  sdcp->sdio->CMD = (uint32_t)cmd | SDIO_CMD_RSPWT_0 | SDIO_CMD_CCSMEN;
  while (((sts = sdcp->sdio->STS) & (SDIO_STS_CMDRSPCMPL | SDIO_STS_CMDTIMEOUT |
                                     SDIO_STS_CMDFAIL)) == 0)
    ;
  sdcp->sdio->INTCLR = sts & (SDIO_STS_CMDRSPCMPL | SDIO_STS_CMDTIMEOUT |
                              SDIO_STS_CMDFAIL);
  if ((sts & (SDIO_STS_CMDTIMEOUT | SDIO_STS_CMDFAIL)) != 0) {
    sdc_lld_collect_errors(sdcp, sts);
    return HAL_FAILED;
  }
  *resp = sdcp->sdio->RSP1;
  return HAL_SUCCESS;
}

/**
 * @brief   Sends an SDIO command with a long response expected and CRC.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] cmd       card command
 * @param[in] arg       command argument
 * @param[out] resp     pointer to the response buffer (four words)
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @notapi
 */
bool sdc_lld_send_cmd_long_crc(SDCDriver *sdcp, uint8_t cmd, uint32_t arg,
                               uint32_t *resp) {
  uint32_t sts;

  (void)sdcp;

  sdcp->sdio->ARG = arg;
  sdcp->sdio->CMD = (uint32_t)cmd | SDIO_CMD_RSPWT_0 | SDIO_CMD_RSPWT_1 |
                                    SDIO_CMD_CCSMEN;
  while (((sts = sdcp->sdio->STS) & (SDIO_STS_CMDRSPCMPL | SDIO_STS_CMDTIMEOUT |
                                     SDIO_STS_CMDFAIL)) == 0)
    ;
  sdcp->sdio->INTCLR = sts & (SDIO_STS_CMDRSPCMPL | SDIO_STS_CMDTIMEOUT |
                              SDIO_STS_CMDFAIL);
  if ((sts & (SDIO_STS_ERROR_MASK)) != 0) {
    sdc_lld_collect_errors(sdcp, sts);
    return HAL_FAILED;
  }
  /* Save bytes in reverse order because MSB in response comes first.*/
  *resp++ = sdcp->sdio->RSP4;
  *resp++ = sdcp->sdio->RSP3;
  *resp++ = sdcp->sdio->RSP2;
  *resp   = sdcp->sdio->RSP1;
  return HAL_SUCCESS;
}

/**
 * @brief   Reads special registers using data bus.
 * @details Needs only during card detection procedure.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[out] buf      pointer to the read buffer
 * @param[in] bytes     number of bytes to read
 * @param[in] cmd       card command
 * @param[in] arg       argument for command
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @notapi
 */
bool sdc_lld_read_special(SDCDriver *sdcp, uint8_t *buf, size_t bytes,
                          uint8_t cmd, uint32_t arg) {
  uint32_t resp[1];

  if (sdc_lld_prepare_read_bytes(sdcp, buf, bytes))
    goto error;

  if (sdc_lld_send_cmd_short_crc(sdcp, cmd, arg, resp)
                                 || MMCSD_R1_ERROR(resp[0]))
    goto error;

  if (sdc_lld_wait_transaction_end(sdcp, 1, resp))
    goto error;

  return HAL_SUCCESS;

error:
  sdc_lld_error_cleanup(sdcp, 1, resp);
  return HAL_FAILED;
}

/**
 * @brief   Reads one or more blocks.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] startblk  first block to read
 * @param[out] buf      pointer to the read buffer
 * @param[in] blocks    number of blocks to read
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @notapi
 */
bool sdc_lld_read_aligned(SDCDriver *sdcp, uint32_t startblk,
                          uint8_t *buf, uint32_t blocks) {
  uint32_t resp[1];

  osalDbgCheck(blocks < 0x1000000 / MMCSD_BLOCK_SIZE);

  sdcp->sdio->DTTMR = sdc_lld_get_timeout(sdcp, AT32_SDC_READ_TIMEOUT_MS);

  /* Checks for errors and waits for the card to be ready for reading.*/
  if (_sdc_wait_for_transfer_state(sdcp))
    return HAL_FAILED;

  /* Prepares the DMA channel for reading.*/
  dmaStreamSetMemory0(sdcp->dma, buf);
  dmaStreamSetTransactionSize(sdcp->dma,
                              (blocks * MMCSD_BLOCK_SIZE) / sizeof (uint32_t));
  dmaStreamSetMode(sdcp->dma, sdcp->dmamode | AT32_DMA_CCTRL_DTD_P2M);
  dmaStreamEnable(sdcp->dma);

  /* Setting up data transfer.*/
  sdcp->sdio->INTCLR = SDIO_INTCLR_ALL_FLAGS;
  sdcp->sdio->INTEN  = SDIO_INTEN_DTFAILIEN |
                       SDIO_INTEN_DTTIMEOUTIEN |
                       SDIO_INTEN_SBITERRIEN |
                       SDIO_INTEN_RXERROIEN |
                       SDIO_INTEN_DTCMPLIEN;
  sdcp->sdio->DTLEN  = blocks * MMCSD_BLOCK_SIZE;

  /* Transaction starts just after TFREN bit setting.*/
  sdcp->sdio->DTCTRL = SDIO_DTCTRL_TFRDIR |
                       SDIO_DTCTRL_BLKSIZE_3 |
                       SDIO_DTCTRL_BLKSIZE_0 |
                       SDIO_DTCTRL_DMAEN |
                       SDIO_DTCTRL_TFREN;

  if (sdc_lld_prepare_read(sdcp, startblk, blocks, resp) == true)
    goto error;

  if (sdc_lld_wait_transaction_end(sdcp, blocks, resp) == true)
    goto error;

  return HAL_SUCCESS;

error:
  sdc_lld_error_cleanup(sdcp, blocks, resp);
  return HAL_FAILED;
}

/**
 * @brief   Writes one or more blocks.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] startblk  first block to write
 * @param[out] buf      pointer to the write buffer
 * @param[in] n         number of blocks to write
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @notapi
 */
bool sdc_lld_write_aligned(SDCDriver *sdcp, uint32_t startblk,
                           const uint8_t *buf, uint32_t blocks) {
  uint32_t resp[1];

  osalDbgCheck(blocks < 0x1000000 / MMCSD_BLOCK_SIZE);

  sdcp->sdio->DTTMR = sdc_lld_get_timeout(sdcp, AT32_SDC_WRITE_TIMEOUT_MS);

  /* Checks for errors and waits for the card to be ready for writing.*/
  if (_sdc_wait_for_transfer_state(sdcp))
    return HAL_FAILED;

  /* Prepares the DMA channel for writing.*/
  dmaStreamSetMemory0(sdcp->dma, buf);
  dmaStreamSetTransactionSize(sdcp->dma,
                             (blocks * MMCSD_BLOCK_SIZE) / sizeof (uint32_t));
  dmaStreamSetMode(sdcp->dma, sdcp->dmamode | AT32_DMA_CCTRL_DTD_M2P);
  dmaStreamEnable(sdcp->dma);

  /* Setting up data transfer.*/
  sdcp->sdio->INTCLR = SDIO_INTCLR_ALL_FLAGS;
  sdcp->sdio->INTEN  = SDIO_INTEN_DTFAILIEN |
                       SDIO_INTEN_DTTIMEOUTIEN |
                       SDIO_INTEN_SBITERRIEN |
                       SDIO_INTEN_TXERRUIEN |
                       SDIO_INTEN_DTCMPLIEN;
  sdcp->sdio->DTLEN  = blocks * MMCSD_BLOCK_SIZE;

  /* Talk to card what we want from it.*/
  if (sdc_lld_prepare_write(sdcp, startblk, blocks, resp) == true)
    goto error;

  /* Transaction starts just after TFREN bit setting.*/
  sdcp->sdio->DTCTRL = SDIO_DTCTRL_BLKSIZE_3 |
                       SDIO_DTCTRL_BLKSIZE_0 |
                       SDIO_DTCTRL_DMAEN |
                       SDIO_DTCTRL_TFREN;

  if (sdc_lld_wait_transaction_end(sdcp, blocks, resp) == true)
    goto error;

  return HAL_SUCCESS;

error:
  sdc_lld_error_cleanup(sdcp, blocks, resp);
  return HAL_FAILED;
}

/**
 * @brief   Reads one or more blocks.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] startblk  first block to read
 * @param[out] buf      pointer to the read buffer
 * @param[in] blocks    number of blocks to read
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @notapi
 */
bool sdc_lld_read(SDCDriver *sdcp, uint32_t startblk,
                  uint8_t *buf, uint32_t blocks) {

#if AT32_SDC_SDIO_UNALIGNED_SUPPORT
  if (((unsigned)buf & 3U) != 0U) {
    uint32_t i;
    for (i = 0U; i < blocks; i++) {
      if (sdc_lld_read_aligned(sdcp, startblk, sdcp->buf, 1)) {
        return HAL_FAILED;
      }
      memcpy(buf, sdcp->buf, MMCSD_BLOCK_SIZE);
      buf += MMCSD_BLOCK_SIZE;
      startblk++;
    }
    return HAL_SUCCESS;
  }
#else /* !AT32_SDC_SDIO_UNALIGNED_SUPPORT */
  osalDbgAssert((((unsigned)buf & 3U) == 0U), "unaligned buffer");
#endif /* !AT32_SDC_SDIO_UNALIGNED_SUPPORT */
  return sdc_lld_read_aligned(sdcp, startblk, buf, blocks);
}

/**
 * @brief   Writes one or more blocks.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] startblk  first block to write
 * @param[out] buf      pointer to the write buffer
 * @param[in] blocks    number of blocks to write
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @notapi
 */
bool sdc_lld_write(SDCDriver *sdcp, uint32_t startblk,
                   const uint8_t *buf, uint32_t blocks) {

#if AT32_SDC_SDIO_UNALIGNED_SUPPORT
  if (((unsigned)buf & 3U) != 0U) {
    uint32_t i;
    for (i = 0U; i < blocks; i++) {
      memcpy(sdcp->buf, buf, MMCSD_BLOCK_SIZE);
      buf += MMCSD_BLOCK_SIZE;
      if (sdc_lld_write_aligned(sdcp, startblk, sdcp->buf, 1))
        return HAL_FAILED;
      startblk++;
    }
    return HAL_SUCCESS;
  }
#else /* !AT32_SDC_SDIO_UNALIGNED_SUPPORT */
  osalDbgAssert((((unsigned)buf & 3U) == 0U), "unaligned buffer");
#endif /* !AT32_SDC_SDIO_UNALIGNED_SUPPORT */
  return sdc_lld_write_aligned(sdcp, startblk, buf, blocks);
}

/**
 * @brief   Waits for card idle condition.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  the operation succeeded.
 * @retval HAL_FAILED   the operation failed.
 *
 * @api
 */
bool sdc_lld_sync(SDCDriver *sdcp) {

  /* CHTODO: Implement.*/
  (void)sdcp;
  return HAL_SUCCESS;
}

#endif /* HAL_USE_SDC */

/** @} */
