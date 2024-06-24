/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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
 * @file    hal_spi_v2_lld.c
 * @brief   PLATFORM SPI (v2) subsystem low level driver source.
 *
 * @addtogroup SPI_V2
 * @{
 */

#include "hal.h"
#include "sercom_clk.h"

#if HAL_USE_SPI || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/
#define SERCOM_SPIM_CTRLA_FORBIDDEN (SERCOM_SPIM_CTRLA_SWRST_Msk | \ 
                                      SERCOM_SPIM_CTRLA_MODE_Msk | \
                                      SERCOM_SPIM_CTRLA_DIPO_Msk | \
                                      SERCOM_SPIM_CTRLA_DOPO_Msk)
/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/


/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/
/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/
static void sercom_spi_lld_disable(SPIDriver* spip) {
  dmacChnlDisable(spip->dmaTxId);
  spip->spi->SERCOM_CTRLA &= ~SERCOM_SPIM_CTRLA_ENABLE_Msk;
  dmacChnlDisable(spip->dmaRxId);
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

static void sercom_spi_lld_serve_rx_interrupt(SPIDriver* spip, uint8_t flag) {
  if (flag & DMAC_CHINTFLAG_TERR_Msk) {
    /* Stopping DMAs.*/
    dmacChnlDisable(spip->dmaTxId);
    dmacChnlDisable(spip->dmaRxId);

    /* Reporting the failure.*/
    __spi_isr_error_code(spip, HAL_RET_HW_FAILURE);
  }
  if (flag & DMAC_CHINTFLAG_TCMPL_Msk) {
    /* Stopping DMAs.*/
    dmacChnlDisable(spip->dmaTxId);
    dmacChnlDisable(spip->dmaRxId);

    /* Operation finished interrupt.*/
    __spi_isr_complete_code(spip);
  }
}

static void sercom_spi_lld_serve_tx_interrupt(SPIDriver* spip, uint8_t flag) {
  if (flag & DMAC_CHINTFLAG_TERR_Msk) {
    /* Stopping DMAs.*/
    dmacChnlDisable(spip->dmaTxId);
    dmacChnlDisable(spip->dmaRxId);

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
static msg_t sercom_spi_lld_get_dma(SPIDriver* spip, uint8_t rxstream,
                             uint8_t txstream, uint8_t priority) {
  int8_t dmacId =
      dmacChnlAllocI(rxstream, priority,
                     (sam_dmaisr_t)sercom_spi_lld_serve_rx_interrupt, (void*)spip);
  if (dmacId < 0) {
    return HAL_RET_NO_RESOURCE;
  }
  spip->dmaRxId = (uint8_t)dmacId;

  dmacId =
      dmacChnlAllocI(txstream, priority,
                     (sam_dmaisr_t)sercom_spi_lld_serve_tx_interrupt, (void*)spip);
  if (dmacId < 0) {
    dmacChnlFreeI(spip->dmaRxId);
    return HAL_RET_NO_RESOURCE;
  }
  spip->dmaTxId = (uint8_t)dmacId;

  return HAL_RET_SUCCESS;
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/
#if defined(SAMD21_MCUCONF)
#include "hal_spi_v2_lld_sercom_samd2x.inc"
#elif defined(SAME54_MCUCONF)
#include "hal_spi_v2_lld_sercom_same5x.inc"
#endif



#if (SPI_SELECT_MODE == SPI_SELECT_MODE_LLD) || defined(__DOXYGEN__)
/**
 * @brief   Asserts the slave select signal and prepares for transfers.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void sercom_spi_lld_select(SPIDriver* spip) {

  (void)spip;
}

/**
 * @brief   Deasserts the slave select signal.
 * @details The previously selected peripheral is unselected.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void sercom_spi_lld_unselect(SPIDriver* spip) {

  (void)spip;
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
msg_t sercom_spi_lld_ignore(SPIDriver* spip, size_t n) {
  if ((spip->config->sercom_cfg.ctrlb & SERCOM_SPIM_CTRLB_CHSIZE_Msk) ==
      SERCOM_SPIM_CTRLB_CHSIZE_9_BIT) {
    dmacChnlSetBtCtrl(spip->dmaTxId, DMAC_BTCTRL_BLOCKACT_INT |
                                         DMAC_BTCTRL_BEATSIZE_HWORD |
                                         DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId, DMAC_BTCTRL_BLOCKACT_INT |
                                         DMAC_BTCTRL_BEATSIZE_HWORD |
                                         DMAC_BTCTRL_VALID_Msk);
  } else {
    dmacChnlSetBtCtrl(spip->dmaTxId,
                      DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId,
                      DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_VALID_Msk);
  }
  dmacChnlSetDir(spip->dmaTxId, (uint32_t)&spip->spi->SERCOM_DATA,
                 (uint32_t)&spip->txsource, n);
  dmacChnlSetDir(spip->dmaRxId, (uint32_t)&spip->rxsink,
                 (uint32_t)&spip->spi->SERCOM_DATA, n);
  dmacChnlEnableIRQn(spip->dmaTxId);
  dmacChnlEnableIRQn(spip->dmaRxId);
  dmacChnlEnable(spip->dmaRxId);
  dmacChnlEnable(spip->dmaTxId);
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
msg_t sercom_spi_lld_exchange(SPIDriver* spip, size_t n, const void* txbuf,
                       void* rxbuf) {
  if ((spip->config->sercom_cfg.ctrlb &
      SERCOM_SPIM_CTRLB_CHSIZE_Msk) == SERCOM_SPIM_CTRLB_CHSIZE_9_BIT) {
    dmacChnlSetBtCtrl(spip->dmaTxId,
                      DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_HWORD |
                          DMAC_BTCTRL_SRCINC_Msk | DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId,
                      DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_HWORD |
                          DMAC_BTCTRL_DSTINC_Msk | DMAC_BTCTRL_VALID_Msk);
  } else {
    dmacChnlSetBtCtrl(spip->dmaTxId,
                      DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_BYTE |
                          DMAC_BTCTRL_SRCINC_Msk | DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId,
                      DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_BYTE |
                          DMAC_BTCTRL_DSTINC_Msk | DMAC_BTCTRL_VALID_Msk);
  }
  dmacChnlSetDir(spip->dmaTxId, (uint32_t)&spip->spi->SERCOM_DATA,
                 (uint32_t)txbuf, n);
  dmacChnlSetDir(spip->dmaRxId, (uint32_t)rxbuf,
                 (uint32_t)&spip->spi->SERCOM_DATA, n);
  dmacChnlEnableIRQn(spip->dmaTxId);
  dmacChnlEnableIRQn(spip->dmaRxId);
  dmacChnlEnable(spip->dmaRxId);
  dmacChnlEnable(spip->dmaTxId);
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
msg_t sercom_spi_lld_send(SPIDriver* spip, size_t n, const void* txbuf) {
  if ((spip->config->sercom_cfg.ctrlb &
      SERCOM_SPIM_CTRLB_CHSIZE_Msk) == SERCOM_SPIM_CTRLB_CHSIZE_9_BIT) {
    dmacChnlSetBtCtrl(spip->dmaTxId,
                      DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_HWORD |
                          DMAC_BTCTRL_SRCINC_Msk | DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId, DMAC_BTCTRL_BLOCKACT_INT |
                                         DMAC_BTCTRL_BEATSIZE_HWORD |
                                         DMAC_BTCTRL_VALID_Msk);
  } else {
    dmacChnlSetBtCtrl(spip->dmaTxId,
                      DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_BYTE |
                          DMAC_BTCTRL_SRCINC_Msk | DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId, DMAC_BTCTRL_BLOCKACT_INT |
                                         DMAC_BTCTRL_BEATSIZE_BYTE |
                                         DMAC_BTCTRL_VALID_Msk);
  }
  dmacChnlSetDir(spip->dmaTxId, (uint32_t)&spip->spi->SERCOM_DATA,
                 (uint32_t)txbuf, n);
  dmacChnlSetDir(spip->dmaRxId, (uint32_t)&spip->rxsink,
                 (uint32_t)&spip->spi->SERCOM_DATA, n);
  dmacChnlEnableIRQn(spip->dmaTxId);
  dmacChnlEnableIRQn(spip->dmaRxId);
  dmacChnlEnable(spip->dmaRxId);
  dmacChnlEnable(spip->dmaTxId);
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
msg_t sercom_spi_lld_receive(SPIDriver* spip, size_t n, void* rxbuf) {
  if ((spip->config->sercom_cfg.ctrlb &
      SERCOM_SPIM_CTRLB_CHSIZE_Msk) == SERCOM_SPIM_CTRLB_CHSIZE_9_BIT) {
    dmacChnlSetBtCtrl(spip->dmaTxId, DMAC_BTCTRL_BLOCKACT_INT |
                                         DMAC_BTCTRL_BEATSIZE_HWORD |
                                         DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId,
                      DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_HWORD |
                          DMAC_BTCTRL_DSTINC_Msk | DMAC_BTCTRL_VALID_Msk);
  } else {
    dmacChnlSetBtCtrl(spip->dmaTxId, DMAC_BTCTRL_BLOCKACT_INT |
                                         DMAC_BTCTRL_BEATSIZE_BYTE |
                                         DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId,
                      DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_BYTE |
                          DMAC_BTCTRL_DSTINC_Msk | DMAC_BTCTRL_VALID_Msk);
  }
  dmacChnlSetDir(spip->dmaTxId, (uint32_t)&spip->spi->SERCOM_DATA,
                 (uint32_t)&spip->txsource, n);
  dmacChnlSetDir(spip->dmaRxId, (uint32_t)rxbuf,
                 (uint32_t)&spip->spi->SERCOM_DATA, n);
  dmacChnlEnableIRQn(spip->dmaTxId);
  dmacChnlEnableIRQn(spip->dmaRxId);
  dmacChnlEnable(spip->dmaRxId);
  dmacChnlEnable(spip->dmaTxId);
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
msg_t sercom_spi_lld_stop_transfer(SPIDriver* spip, size_t* sizep) {

  dmacChnlDisable(spip->dmaTxId);
  sercom_spim_registers_t *spid = spip->spi;
  while (!(spid->SERCOM_INTFLAG & SERCOM_SPIM_INTFLAG_TXC_Msk))
    ;
  /* Size of unprocessed data.*/
  if (sizep != NULL) {
    *sizep = dmacChnlGetTransferred(spip->dmaRxId);
  }
  dmacChnlDisable(spip->dmaRxId);
  return HAL_RET_SUCCESS;
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
uint16_t sercom_spi_lld_polled_exchange(SPIDriver* spip, uint16_t frame) {
  if ((spip->config->sercom_cfg.ctrlb &
      SERCOM_SPIM_CTRLB_CHSIZE_Msk) == SERCOM_SPIM_CTRLB_CHSIZE_9_BIT) {
    volatile uint16_t* dr16p = (volatile uint16_t*)&spip->spi->SERCOM_DATA;
    *dr16p = (uint16_t)frame;
    while ((spip->spi->SERCOM_INTFLAG & SERCOM_SPIM_INTFLAG_RXC_Msk) == 0U) {
      /* Waiting frame transfer.*/
    }
    frame = (uint16_t)*dr16p;
  } else {
    volatile uint8_t* dr8p = (volatile uint8_t*)&spip->spi->SERCOM_DATA;
    *dr8p = (uint8_t)frame;
    while ((spip->spi->SERCOM_INTFLAG & SERCOM_SPIM_INTFLAG_RXC_Msk) == 0U) {
      /* Waiting frame transfer.*/
    }
    frame = (uint16_t)*dr8p;
  }
  return frame;
}

#endif /* HAL_USE_SPI */

/** @} */
