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
 * @file    SPIv1/hal_spi_v2_lld.c
 * @brief   AT32 SPI (v2) subsystem low level driver source.
 *
 * @addtogroup SPI
 * @{
 */

#include "hal.h"

#if HAL_USE_SPI || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief SPI1 driver identifier.*/
#if AT32_SPI_USE_SPI1 || defined(__DOXYGEN__)
SPIDriver SPID1;
#endif

/** @brief SPI2 driver identifier.*/
#if AT32_SPI_USE_SPI2 || defined(__DOXYGEN__)
SPIDriver SPID2;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void spi_lld_configure(SPIDriver *spip) {
  uint32_t ctrl1, ctrl2;

  /* Disabling SPI during (re)configuration.*/
  spip->spi->CTRL1 = 0U;

  /* Common CTRL1 and CTRL2 options.*/
  ctrl1 = spip->config->ctrl1 & ~(SPI_CTRL1_MSTEN | SPI_CTRL1_SPIEN);
  ctrl2 = spip->config->ctrl2 | SPI_CTRL2_DMAREN | SPI_CTRL2_DMATEN;

  /* SPI setup.*/
  if (spip->config->slave == false) {
    ctrl1 |= SPI_CTRL1_SWCSEN | SPI_CTRL1_SWCSIL | SPI_CTRL1_MSTEN;
    ctrl2 |= SPI_CTRL2_HWCSOE;
  }

  /* New configuration.*/
  spip->spi->CTRL2 = ctrl2;
  spip->spi->CTRL1 = ctrl1;
  spip->spi->CTRL1 = ctrl1 | SPI_CTRL1_SPIEN;
}

/**
 * @brief   Stopping the SPI transaction.
 * @note    This is done nicely or by brutally resetting it depending on
 *          the mode and settings.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 */
static msg_t spi_lld_stop_abort(SPIDriver *spip) {

  if (!spip->config->slave) {
    /* Master mode, stopping gracefully.*/

    /* Stopping TX DMA channel.*/
    dmaStreamDisable(spip->dmatx);

    /* Waiting for current frame completion then stop SPI.*/
    while ((spip->spi->STS & SPI_STS_BF) != 0U) {
    }

    /* Now it is idle, stopping RX DMA channel.*/
    dmaStreamDisable(spip->dmarx);
  }
  else {
    /* Slave mode, this will not be nice.*/

    /* Stopping DMAs.*/
    dmaStreamDisable(spip->dmatx);
    dmaStreamDisable(spip->dmarx);

    /* Resetting SPI, this will stop it for sure and leave it
       in a clean state.*/
    if (false) {
    }

#if AT32_SPI_USE_SPI1
    else if (&SPID1 == spip) {
      crmResetSPI1();
    }
#endif

#if AT32_SPI_USE_SPI2
    else if (&SPID2 == spip) {
      crmResetSPI2();
    }
#endif

    else {
      osalDbgAssert(false, "invalid SPI instance");
    }

    /* Reconfiguring SPI.*/
    spi_lld_configure(spip);
  }

  return HAL_RET_SUCCESS;
}

/**
 * @brief   Shared end-of-rx service routine.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] flags     pre-shifted content of the STS register
 */
static void spi_lld_serve_rx_interrupt(SPIDriver *spip, uint32_t flags) {

  /* DMA errors handling.*/
  if ((flags & AT32_DMA_STS_DTERRF) != 0) {
#if defined(AT32_SPI_DMA_ERROR_HOOK)
    /* Hook first, if defined.*/
    AT32_SPI_DMA_ERROR_HOOK(spip);
#endif

    /* Aborting the transfer.*/
    (void) spi_lld_stop_abort(spip);

    /* Reporting the failure.*/
    __spi_isr_error_code(spip, HAL_RET_HW_FAILURE);
  }
  else if (spip->config->circular) {
    if ((flags & AT32_DMA_STS_HDTF) != 0U) {
      /* Half buffer interrupt.*/
      __spi_isr_half_code(spip);
    }
    if ((flags & AT32_DMA_STS_FDTF) != 0U) {
      /* End buffer interrupt.*/
      __spi_isr_full_code(spip);
    }
  }
  else {
    /* Stopping the transfer.*/
    (void) spi_lld_stop_abort(spip);

    /* Operation finished interrupt.*/
    __spi_isr_complete_code(spip);
  }
}

/**
 * @brief   Shared end-of-tx service routine.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] flags     pre-shifted content of the STS register
 */
static void spi_lld_serve_tx_interrupt(SPIDriver *spip, uint32_t flags) {

  /* DMA errors handling.*/
  if ((flags & AT32_DMA_STS_DTERRF) != 0) {
#if defined(AT32_SPI_DMA_ERROR_HOOK)
    /* Hook first, if defined.*/
    AT32_SPI_DMA_ERROR_HOOK(spip);
#endif

    /* Aborting the transfer.*/
    (void) spi_lld_stop_abort(spip);

    /* Reporting the failure.*/
    __spi_isr_error_code(spip, HAL_RET_HW_FAILURE);
  }
}

/**
 * @brief   DMA streams allocation.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] rxstream  stream to be allocated for RX
 * @param[in] txstream  stream to be allocated for TX
 * @param[in] priority  streams IRQ priority
 * @return              The operation status.
 */
static msg_t spi_lld_get_dma(SPIDriver *spip, uint32_t rxstream,
                             uint32_t txstream, uint32_t priority) {

  spip->dmarx = dmaStreamAllocI(rxstream, priority,
                               (at32_dmasts_t)spi_lld_serve_rx_interrupt,
                               (void *)spip);
  if (spip->dmarx == NULL) {
    return HAL_RET_NO_RESOURCE;
  }

  spip->dmatx = dmaStreamAllocI(txstream, priority,
                               (at32_dmasts_t)spi_lld_serve_tx_interrupt,
                               (void *)spip);
  if (spip->dmatx == NULL) {
    dmaStreamFreeI(spip->dmarx);
    return HAL_RET_NO_RESOURCE;
  }

  return HAL_RET_SUCCESS;
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level SPI driver initialization.
 *
 * @notapi
 */
void spi_lld_init(void) {

#if AT32_SPI_USE_SPI1
  spiObjectInit(&SPID1);
  SPID1.spi       = SPI1;
  SPID1.dmarx     = NULL;
  SPID1.dmatx     = NULL;
  SPID1.rxdmamode = AT32_DMA_CCTRL_CHPL(AT32_SPI_SPI1_DMA_PRIORITY) |
                    AT32_DMA_CCTRL_DTD_P2M |
                    AT32_DMA_CCTRL_FDTIEN |
                    AT32_DMA_CCTRL_DTERRIEN;
  SPID1.txdmamode = AT32_DMA_CCTRL_CHPL(AT32_SPI_SPI1_DMA_PRIORITY) |
                    AT32_DMA_CCTRL_DTD_M2P |
                    AT32_DMA_CCTRL_DTERRIEN;
#endif

#if AT32_SPI_USE_SPI2
  spiObjectInit(&SPID2);
  SPID2.spi       = SPI2;
  SPID2.dmarx     = NULL;
  SPID2.dmatx     = NULL;
  SPID2.rxdmamode = AT32_DMA_CCTRL_CHPL(AT32_SPI_SPI2_DMA_PRIORITY) |
                    AT32_DMA_CCTRL_DTD_P2M |
                    AT32_DMA_CCTRL_FDTIEN |
                    AT32_DMA_CCTRL_DTERRIEN;
  SPID2.txdmamode = AT32_DMA_CCTRL_CHPL(AT32_SPI_SPI2_DMA_PRIORITY) |
                    AT32_DMA_CCTRL_DTD_M2P |
                    AT32_DMA_CCTRL_DTERRIEN;
#endif
}

/**
 * @brief   Configures and activates the SPI peripheral.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @return              The operation status.
 *
 * @notapi
 */
msg_t spi_lld_start(SPIDriver *spip) {
  msg_t msg;

  /* Resetting TX pattern source.*/
  spip->txsource = (uint32_t)AT32_SPI_FILLER_PATTERN;

  /* If in stopped state then enables the SPI and DMA clocks.*/
  if (spip->state == SPI_STOP) {
    if (false) {
    }

#if AT32_SPI_USE_SPI1
    else if (&SPID1 == spip) {
      msg = spi_lld_get_dma(spip,
                            AT32_SPI_SPI1_RX_DMA_STREAM,
                            AT32_SPI_SPI1_TX_DMA_STREAM,
                            AT32_SPI_SPI1_IRQ_PRIORITY);
      if (msg != HAL_RET_SUCCESS) {
        return msg;
      }
      crmEnableSPI1(true);
      crmResetSPI1();
#if AT32_DMA_SUPPORTS_DMAMUX
      dmaSetRequestSource(spip->dmarx, AT32_SPI_SPI1_RX_DMAMUX_CHANNEL, AT32_DMAMUX_SPI1_RX);
      dmaSetRequestSource(spip->dmatx, AT32_SPI_SPI1_TX_DMAMUX_CHANNEL, AT32_DMAMUX_SPI1_TX);
#endif
    }
#endif

#if AT32_SPI_USE_SPI2
    else if (&SPID2 == spip) {
      msg = spi_lld_get_dma(spip,
                            AT32_SPI_SPI2_RX_DMA_STREAM,
                            AT32_SPI_SPI2_TX_DMA_STREAM,
                            AT32_SPI_SPI2_IRQ_PRIORITY);
      if (msg != HAL_RET_SUCCESS) {
        return msg;
      }
      crmEnableSPI2(true);
      crmResetSPI2();
#if AT32_DMA_SUPPORTS_DMAMUX
      dmaSetRequestSource(spip->dmarx, AT32_SPI_SPI2_RX_DMAMUX_CHANNEL, AT32_DMAMUX_SPI2_RX);
      dmaSetRequestSource(spip->dmatx, AT32_SPI_SPI2_TX_DMAMUX_CHANNEL, AT32_DMAMUX_SPI2_TX);
#endif
    }
#endif

    else {
      osalDbgAssert(false, "invalid SPI instance");
    }

    /* DMA setup.*/
    dmaStreamSetPeripheral(spip->dmarx, &spip->spi->DT);
    dmaStreamSetPeripheral(spip->dmatx, &spip->spi->DT);
  }

  /* Configuration-specific DMA setup.*/
  if ((spip->config->ctrl1 & SPI_CTRL1_FBN) == 0) {
    /* Frame width is 8 bits or smaller.*/
    spip->rxdmamode = (spip->rxdmamode & ~AT32_DMA_CCTRL_SIZE_MASK) |
                      AT32_DMA_CCTRL_PWIDTH_BYTE | AT32_DMA_CCTRL_MWIDTH_BYTE;
    spip->txdmamode = (spip->txdmamode & ~AT32_DMA_CCTRL_SIZE_MASK) |
                      AT32_DMA_CCTRL_PWIDTH_BYTE | AT32_DMA_CCTRL_MWIDTH_BYTE;
  }
  else {
    /* Frame width is larger than 8 bits.*/
    spip->rxdmamode = (spip->rxdmamode & ~AT32_DMA_CCTRL_SIZE_MASK) |
                      AT32_DMA_CCTRL_PWIDTH_HWORD | AT32_DMA_CCTRL_MWIDTH_HWORD;
    spip->txdmamode = (spip->txdmamode & ~AT32_DMA_CCTRL_SIZE_MASK) |
                      AT32_DMA_CCTRL_PWIDTH_HWORD | AT32_DMA_CCTRL_MWIDTH_HWORD;
  }

  if (spip->config->circular) {
    spip->rxdmamode |= (AT32_DMA_CCTRL_LM | AT32_DMA_CCTRL_HDTIEN);
    spip->txdmamode |= (AT32_DMA_CCTRL_LM | AT32_DMA_CCTRL_HDTIEN);
  }
  else {
    spip->rxdmamode &= ~(AT32_DMA_CCTRL_LM | AT32_DMA_CCTRL_HDTIEN);
    spip->txdmamode &= ~(AT32_DMA_CCTRL_LM | AT32_DMA_CCTRL_HDTIEN);
  }

  /* SPI setup.*/
  spi_lld_configure(spip);

  return HAL_RET_SUCCESS;
}

/**
 * @brief   Deactivates the SPI peripheral.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_stop(SPIDriver *spip) {

  /* If in ready state then disables the SPI clock.*/
  if (spip->state == SPI_READY) {

    /* Just in case this has been called uncleanly.*/
    (void) spi_lld_stop_abort(spip);

    /* SPI cleanup.*/
    spip->spi->CTRL1 = 0;
    spip->spi->CTRL2 = 0;

    /* DMA channels release.*/
    dmaStreamFreeI(spip->dmatx);
    dmaStreamFreeI(spip->dmarx);
    spip->dmarx = NULL;
    spip->dmatx = NULL;

    /* Clock shutdown.*/
    if (false) {
    }

#if AT32_SPI_USE_SPI1
    else if (&SPID1 == spip) {
      crmDisableSPI1();
    }
#endif

#if AT32_SPI_USE_SPI2
    else if (&SPID2 == spip) {
      crmDisableSPI2();
    }
#endif

    else {
      osalDbgAssert(false, "invalid SPI instance");
    }
  }
}

#if (SPI_SELECT_MODE == SPI_SELECT_MODE_LLD) || defined(__DOXYGEN__)
/**
 * @brief   Asserts the slave select signal and prepares for transfers.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_select(SPIDriver *spip) {

  /* No implementation on AT32.*/
}

/**
 * @brief   Deasserts the slave select signal.
 * @details The previously selected peripheral is unselected.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_unselect(SPIDriver *spip) {

  /* No implementation on AT32.*/
}
#endif

/**
 * @brief   Ignores data on the SPI bus.
 * @details This synchronous function performs the transmission of a series of
 *          idle words on the SPI bus and ignores the received data.
 * @pre     In order to use this function the option @p SPI_USE_SYNCHRONIZATION
 *          must be enabled.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of words to be ignored
 * @return              The operation status.
 *
 * @notapi
 */
msg_t spi_lld_ignore(SPIDriver *spip, size_t n) {

  osalDbgAssert(n <= AT32_DMA_MAX_TRANSFER, "unsupported DMA transfer size");

  dmaStreamSetMemory0(spip->dmarx, &spip->rxsink);
  dmaStreamSetTransactionSize(spip->dmarx, n);
  dmaStreamSetMode(spip->dmarx, spip->rxdmamode);

  dmaStreamSetMemory0(spip->dmatx, &spip->txsource);
  dmaStreamSetTransactionSize(spip->dmatx, n);
  dmaStreamSetMode(spip->dmatx, spip->txdmamode);

  dmaStreamEnable(spip->dmarx);
  dmaStreamEnable(spip->dmatx);

  return HAL_RET_SUCCESS;
}

/**
 * @brief   Exchanges data on the SPI bus.
 * @details This asynchronous function starts a simultaneous transmit/receive
 *          operation.
 * @post    At the end of the operation the configured callback is invoked.
 * @note    The buffers are organized as uint8_t arrays for data sizes below or
 *          equal to 8 bits else it is organized as uint16_t arrays.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of words to be exchanged
 * @param[in] txbuf     the pointer to the transmit buffer
 * @param[out] rxbuf    the pointer to the receive buffer
 * @return              The operation status.
 *
 * @notapi
 */
msg_t spi_lld_exchange(SPIDriver *spip, size_t n,
                       const void *txbuf, void *rxbuf) {

  osalDbgAssert(n <= AT32_DMA_MAX_TRANSFER, "unsupported DMA transfer size");

  dmaStreamSetMemory0(spip->dmarx, rxbuf);
  dmaStreamSetTransactionSize(spip->dmarx, n);
  dmaStreamSetMode(spip->dmarx, spip->rxdmamode | AT32_DMA_CCTRL_MINCM);

  dmaStreamSetMemory0(spip->dmatx, txbuf);
  dmaStreamSetTransactionSize(spip->dmatx, n);
  dmaStreamSetMode(spip->dmatx, spip->txdmamode | AT32_DMA_CCTRL_MINCM);

  dmaStreamEnable(spip->dmarx);
  dmaStreamEnable(spip->dmatx);

  return HAL_RET_SUCCESS;
}

/**
 * @brief   Sends data over the SPI bus.
 * @details This asynchronous function starts a transmit operation.
 * @post    At the end of the operation the configured callback is invoked.
 * @note    The buffers are organized as uint8_t arrays for data sizes below or
 *          equal to 8 bits else it is organized as uint16_t arrays.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of words to send
 * @param[in] txbuf     the pointer to the transmit buffer
 * @return              The operation status.
 *
 * @notapi
 */
msg_t spi_lld_send(SPIDriver *spip, size_t n, const void *txbuf) {

  osalDbgAssert(n <= AT32_DMA_MAX_TRANSFER, "unsupported DMA transfer size");

  dmaStreamSetMemory0(spip->dmarx, &spip->rxsink);
  dmaStreamSetTransactionSize(spip->dmarx, n);
  dmaStreamSetMode(spip->dmarx, spip->rxdmamode);

  dmaStreamSetMemory0(spip->dmatx, txbuf);
  dmaStreamSetTransactionSize(spip->dmatx, n);
  dmaStreamSetMode(spip->dmatx, spip->txdmamode | AT32_DMA_CCTRL_MINCM);

  dmaStreamEnable(spip->dmarx);
  dmaStreamEnable(spip->dmatx);

  return HAL_RET_SUCCESS;
}

/**
 * @brief   Receives data from the SPI bus.
 * @details This asynchronous function starts a receive operation.
 * @post    At the end of the operation the configured callback is invoked.
 * @note    The buffers are organized as uint8_t arrays for data sizes below or
 *          equal to 8 bits else it is organized as uint16_t arrays.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of words to receive
 * @param[out] rxbuf    the pointer to the receive buffer
 * @return              The operation status.
 *
 * @notapi
 */
msg_t spi_lld_receive(SPIDriver *spip, size_t n, void *rxbuf) {

  osalDbgAssert(n <= AT32_DMA_MAX_TRANSFER, "unsupported DMA transfer size");

  dmaStreamSetMemory0(spip->dmarx, rxbuf);
  dmaStreamSetTransactionSize(spip->dmarx, n);
  dmaStreamSetMode(spip->dmarx, spip->rxdmamode | AT32_DMA_CCTRL_MINCM);

  dmaStreamSetMemory0(spip->dmatx, &spip->txsource);
  dmaStreamSetTransactionSize(spip->dmatx, n);
  dmaStreamSetMode(spip->dmatx, spip->txdmamode);

  dmaStreamEnable(spip->dmarx);
  dmaStreamEnable(spip->dmatx);

  return HAL_RET_SUCCESS;
}

/**
 * @brief   Aborts the ongoing SPI operation, if any.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[out] sizep    pointer to the counter of frames not yet transferred
 *                      or @p NULL
 * @return              The operation status.
 *
 * @notapi
 */
msg_t spi_lld_stop_transfer(SPIDriver *spip, size_t *sizep) {
  msg_t msg;

  /* Stopping everything.*/
  msg = spi_lld_stop_abort(spip);

  if (sizep != NULL) {
    *sizep = dmaStreamGetTransactionSize(spip->dmarx);
  }

  return msg;
}

/**
 * @brief   Exchanges one frame using a polled wait.
 * @details This synchronous function exchanges one frame using a polled
 *          synchronization method. This function is useful when exchanging
 *          small amount of data on high speed channels, usually in this
 *          situation is much more efficient just wait for completion using
 *          polling than suspending the thread waiting for an interrupt.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] frame     the data frame to send over the SPI bus
 * @return              The received data frame from the SPI bus.
 */
uint16_t spi_lld_polled_exchange(SPIDriver *spip, uint16_t frame) {

  spip->spi->DT = frame;
  while ((spip->spi->STS & SPI_STS_RDBF) == 0U)
    ;
  return spip->spi->DT;
}

#endif /* HAL_USE_SPI */

/** @} */
