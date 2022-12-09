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

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   SPI1 driver identifier.
 */
#if (SAM_SPI_USE_SERCOM0 == TRUE) || defined(__DOXYGEN__)
SPIDriver SPID1;
#endif

/**
 * @brief   SPI2 driver identifier.
 */
#if (SAM_SPI_USE_SERCOM1 == TRUE) || defined(__DOXYGEN__)
SPIDriver SPID2;
#endif

/**
 * @brief   SPI3 driver identifier.
 */
#if (SAM_SPI_USE_SERCOM2 == TRUE) || defined(__DOXYGEN__)
SPIDriver SPID3;
#endif

/**
 * @brief   SPI4 driver identifier.
 */
#if (SAM_SPI_USE_SERCOM3 == TRUE) || defined(__DOXYGEN__)
SPIDriver SPID4;
#endif

/**
 * @brief   SPI5 driver identifier.
 */
#if (SAM_SPI_USE_SERCOM4 == TRUE) || defined(__DOXYGEN__)
SPIDriver SPID5;
#endif

/**
 * @brief   SPI6 driver identifier.
 */
#if (SAM_SPI_USE_SERCOM5 == TRUE) || defined(__DOXYGEN__)
SPIDriver SPID6;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/
static const uint16_t dummytx = 0xFFFFU;
static uint16_t dummyrx;
/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/
static void spi_lld_disable(SPIDriver *spip)
{
  dmacChnlDisable(spip->dmaTxId);
  spip->spi->SERCOM_CTRLA &= ~SERCOM_SPIM_CTRLA_ENABLE_Msk;
  dmacChnlDisable(spip->dmaRxId);
}
/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

static void spi_lld_serve_rx_interrupt(SPIDriver *spip, uint8_t flag)
{
  if (flag & DMAC_CHINTFLAG_TERR_Msk)
  {
    /* Stopping DMAs.*/
    dmacChnlDisable(spip->dmaTxId);
    dmacChnlDisable(spip->dmaRxId);

    /* Reporting the failure.*/
    __spi_isr_error_code(spip, HAL_RET_HW_FAILURE);
  }
  if (flag & DMAC_CHINTFLAG_TCMPL_Msk)
  {
    /* Stopping DMAs.*/
    dmacChnlDisable(spip->dmaTxId);
    dmacChnlDisable(spip->dmaRxId);

    /* Operation finished interrupt.*/
    __spi_isr_complete_code(spip);
  }
}

static void spi_lld_serve_tx_interrupt(SPIDriver *spip, uint8_t flag)
{
  if (flag & DMAC_CHINTFLAG_TERR_Msk)
  {
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
static msg_t spi_lld_get_dma(SPIDriver *spip, uint8_t rxstream,
                             uint8_t txstream, uint8_t priority)
{
  int8_t dmacId = dmacChnlAllocI(rxstream, priority,
                                 (sam_dmaisr_t)spi_lld_serve_rx_interrupt,
                                 (void *)spip);
  if (dmacId < 0)
  {
    return HAL_RET_NO_RESOURCE;
  }
  spip->dmaRxId = (uint8_t)dmacId;

  dmacId = dmacChnlAllocI(txstream, priority,
                          (sam_dmaisr_t)spi_lld_serve_tx_interrupt,
                          (void *)spip);
  if (dmacId < 0)
  {
    dmacChnlFreeI(spip->dmaRxId);
    return HAL_RET_NO_RESOURCE;
  }
  spip->dmaTxId = (uint8_t)dmacId;

  return HAL_RET_SUCCESS;
}
/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level SPI driver initialization.
 *
 * @notapi
 */
void spi_lld_init(void)
{
#if SAM_SPI_USE_SERCOM0 == TRUE
  /* Driver initialization.*/
  spiObjectInit(&SPID1);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM0_Msk;
  SPID1.spi = &SERCOM0_REGS->SPIM;
  SPID1.clock = SAM_SERCOM0_GCLK_SRC_FREQ;
#endif
#if SAM_SPI_USE_SERCOM1 == TRUE
  /* Driver initialization.*/
  spiObjectInit(&SPID2);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM1_Msk;
  SPID2.spi = &SERCOM1_REGS->SPIM;
  SPID2.clock = SAM_SERCOM1_GCLK_SRC_FREQ;
#endif
#if SAM_SPI_USE_SERCOM2 == TRUE
  /* Driver initialization.*/
  spiObjectInit(&SPID3);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM2_Msk;
  SPID3.spi = &SERCOM2_REGS->SPIM;
  SPID3.clock = SAM_SERCOM2_GCLK_SRC_FREQ;
#endif
#if SAM_SPI_USE_SERCOM3 == TRUE
  /* Driver initialization.*/
  spiObjectInit(&SPID4);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM3_Msk;
  SPID4.spi = &SERCOM3_REGS->SPIM;
  SPID4.clock = SAM_SERCOM3_GCLK_SRC_FREQ;
#endif
#if SAM_SPI_USE_SERCOM4 == TRUE
  /* Driver initialization.*/
  spiObjectInit(&SPID5);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM4_Msk;
  SPID5.spi = &SERCOM4_REGS->SPIM;
  SPID5.clock = SAM_SERCOM4_GCLK_SRC_FREQ;
#endif
#if SAM_SPI_USE_SERCOM5 == TRUE
  /* Driver initialization.*/
  spiObjectInit(&SPID6);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM5_Msk;
  SPID6.spi = &SERCOM5_REGS->SPIM;
  SPID6.clock = SAM_SERCOM5_GCLK_SRC_FREQ;
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
msg_t spi_lld_start(SPIDriver *spip)
{

  if (spip->state == SPI_STOP)
  {

    /* Enables the peripheral.*/
    if (false)
    {
    }

#if SAM_SPI_USE_SERCOM0 == TRUE
    else if (&SPID1 == spip)
    {
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM0_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM0_CORE_Val, 1);
      msg_t msg = spi_lld_get_dma(spip,
                                  SAM_SPI0_DMARX_CHANNEL,
                                  SAM_SPI0_DMATX_CHANNEL,
                                  SAM_SPI0_DMA_PRIO);
      if (msg != HAL_RET_SUCCESS)
      {
        return msg;
      }
      dmacChnlSetTrigSrc(spip->dmaTxId, SERCOM0_TX);
      dmacChnlSetTrigAct(spip->dmaTxId, BEAT);
      dmacChnlSetTrigSrc(spip->dmaRxId, SERCOM0_RX);
      dmacChnlSetTrigAct(spip->dmaRxId, BEAT);
    }
#endif

#if SAM_SPI_USE_SERCOM1 == TRUE
    else if (&SPID2 == spip)
    {
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM1_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM1_CORE_Val, 1);
      msg_t msg = spi_lld_get_dma(spip,
                                  SAM_SPI1_DMARX_CHANNEL,
                                  SAM_SPI1_DMATX_CHANNEL,
                                  SAM_SPI1_DMA_PRIO);
      if (msg != HAL_RET_SUCCESS)
      {
        return msg;
      }
      dmacChnlSetTrigSrc(spip->dmaTxId, SERCOM1_TX);
      dmacChnlSetTrigAct(spip->dmaTxId, BEAT);
      dmacChnlSetTrigSrc(spip->dmaRxId, SERCOM1_RX);
      dmacChnlSetTrigAct(spip->dmaRxId, BEAT);
    }
#endif

#if SAM_SPI_USE_SERCOM2 == TRUE
    else if (&SPID3 == spip)
    {
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM2_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM2_CORE_Val, 1);
      msg_t msg = spi_lld_get_dma(spip,
                                  SAM_SPI2_DMARX_CHANNEL,
                                  SAM_SPI2_DMATX_CHANNEL,
                                  SAM_SPI2_DMA_PRIO);
      if (msg != HAL_RET_SUCCESS)
      {
        return msg;
      }
      dmacChnlSetTrigSrc(spip->dmaTxId, SERCOM2_TX);
      dmacChnlSetTrigAct(spip->dmaTxId, BEAT);
      dmacChnlSetTrigSrc(spip->dmaRxId, SERCOM2_RX);
      dmacChnlSetTrigAct(spip->dmaRxId, BEAT);
    }
#endif

#if SAM_SPI_USE_SERCOM3 == TRUE
    else if (&SPID4 == spip)
    {
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM3_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM3_CORE_Val, 1);
      msg_t msg = spi_lld_get_dma(spip,
                                  SAM_SPI3_DMARX_CHANNEL,
                                  SAM_SPI3_DMATX_CHANNEL,
                                  SAM_SPI3_DMA_PRIO);
      if (msg != HAL_RET_SUCCESS)
      {
        return msg;
      }
      dmacChnlSetTrigSrc(spip->dmaTxId, SERCOM3_TX);
      dmacChnlSetTrigAct(spip->dmaTxId, BEAT);
      dmacChnlSetTrigSrc(spip->dmaRxId, SERCOM3_RX);
      dmacChnlSetTrigAct(spip->dmaRxId, BEAT);
    }
#endif

#if SAM_SPI_USE_SERCOM4 == TRUE
    else if (&SPID5 == spip)
    {
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM4_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM4_CORE_Val, 1);
      msg_t msg = spi_lld_get_dma(spip,
                                  SAM_SPI4_DMARX_CHANNEL,
                                  SAM_SPI4_DMATX_CHANNEL,
                                  SAM_SPI4_DMA_PRIO);
      if (msg != HAL_RET_SUCCESS)
      {
        return msg;
      }
      dmacChnlSetTrigSrc(spip->dmaTxId, SERCOM4_TX);
      dmacChnlSetTrigAct(spip->dmaTxId, BEAT);
      dmacChnlSetTrigSrc(spip->dmaRxId, SERCOM4_RX);
      dmacChnlSetTrigAct(spip->dmaRxId, BEAT);
    }
#endif

#if SAM_SPI_USE_SERCOM5 == TRUE
    else if (&SPID6 == spip)
    {
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM5_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM5_CORE_Val, 1);
      msg_t msg = spi_lld_get_dma(spip,
                                  SAM_SPI5_DMARX_CHANNEL,
                                  SAM_SPI5_DMATX_CHANNEL,
                                  SAM_SPI5_DMA_PRIO);
      if (msg != HAL_RET_SUCCESS)
      {
        return msg;
      }
      dmacChnlSetTrigSrc(spip->dmaTxId, SERCOM5_TX);
      dmacChnlSetTrigAct(spip->dmaTxId, BEAT);
      dmacChnlSetTrigSrc(spip->dmaRxId, SERCOM5_RX);
      dmacChnlSetTrigAct(spip->dmaRxId, BEAT);
    }
#endif

    else
    {
      osalDbgAssert(false, "invalid SPI instance");
    }
  }
  else
  {
    spi_lld_disable(spip);
  }
  spip->spi->SERCOM_CTRLA = SERCOM_SPIM_CTRLA_SWRST_Msk;
  while (spip->spi->SERCOM_SYNCBUSY != 0)
    ;
  uint32_t baud_val = spip->clock / (2U * spip->config->freq) - 1;
  if (baud_val > 255)
  {
    baud_val = 255;
  }
  spip->spi->SERCOM_BAUD = baud_val;
  spip->spi->SERCOM_CTRLB = (spip->config->ctrlb & ~(SERCOM_SPIM_CTRLB_MSSEN_Msk | SERCOM_SPIM_CTRLB_AMODE_Msk)) | SERCOM_SPIM_CTRLB_RXEN_Msk;
  while (spip->spi->SERCOM_SYNCBUSY != 0)
    ;
  spip->spi->SERCOM_CTRLA = (spip->config->ctrla & ~(SERCOM_SPIM_CTRLA_SWRST_Msk | SERCOM_SPIM_CTRLA_MODE_Msk)) |
                            (spip->config->slave ? SERCOM_SPIM_CTRLA_MODE_SPI_SLAVE : SERCOM_SPIM_CTRLA_MODE_SPI_MASTER) |
                            SERCOM_SPIM_CTRLA_ENABLE_Msk;
  while (spip->spi->SERCOM_SYNCBUSY != 0)
    ;
  return HAL_RET_SUCCESS;
}

/**
 * @brief   Deactivates the SPI peripheral.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_stop(SPIDriver *spip)
{

  if (spip->state == SPI_READY)
  {
    uint8_t id = 0;
    uint8_t id_val = 0;
    /* Disables the peripheral.*/
    if (false)
    {
    }
#if SAM_SPI_USE_SERCOM0 == TRUE
    else if (&SPID1 == spip)
    {
      id = SAM_SERCOM0_GCLK_SRC_ID;
      id_val = GCLK_CLKCTRL_ID_SERCOM0_CORE_Val;
    }
#endif
#if SAM_SPI_USE_SERCOM1 == TRUE
    else if (&SPID2 == spip)
    {
      id = SAM_SERCOM1_GCLK_SRC_ID;
      id_val = GCLK_CLKCTRL_ID_SERCOM1_CORE_Val;
    }
#endif
#if SAM_SPI_USE_SERCOM2 == TRUE
    else if (&SPID3 == spip)
    {
      id = SAM_SERCOM2_GCLK_SRC_ID;
      id_val = GCLK_CLKCTRL_ID_SERCOM2_CORE_Val;
    }
#endif
#if SAM_SPI_USE_SERCOM3 == TRUE
    else if (&SPID4 == spip)
    {
      id = SAM_SERCOM3_GCLK_SRC_ID;
      id_val = GCLK_CLKCTRL_ID_SERCOM3_CORE_Val;
    }
#endif
#if SAM_SPI_USE_SERCOM4 == TRUE
    else if (&SPID5 == spip)
    {
      id = SAM_SERCOM4_GCLK_SRC_ID;
      id_val = GCLK_CLKCTRL_ID_SERCOM4_CORE_Val;
    }
#endif
#if SAM_SPI_USE_SERCOM5 == TRUE
    else if (&SPID6 == spip)
    {
      id = SAM_SERCOM5_GCLK_SRC_ID;
      id_val = GCLK_CLKCTRL_ID_SERCOM5_CORE_Val;
    }
#endif
    else
    {
      osalDbgAssert(false, "invalid SPI instance");
    }
    spi_lld_disable(spip);
    dmacChnlFreeI(spip->dmaRxId);
    dmacChnlFreeI(spip->dmaTxId);
    sam_gclk_mux(id, id_val, 0);
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
void spi_lld_select(SPIDriver *spip)
{

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
void spi_lld_unselect(SPIDriver *spip)
{

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
msg_t spi_lld_ignore(SPIDriver *spip, size_t n)
{
  if ((spip->config->ctrlb & SERCOM_SPIM_CTRLB_CHSIZE_Msk) == SERCOM_SPIM_CTRLB_CHSIZE_9_BIT)
  {
    dmacChnlSetBtCtrl(spip->dmaTxId, DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_HWORD | DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId, DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_HWORD | DMAC_BTCTRL_VALID_Msk);
  }
  else
  {
    dmacChnlSetBtCtrl(spip->dmaTxId, DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId, DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_VALID_Msk);
  }
  dmacChnlSetDir(spip->dmaTxId, (uint32_t)&spip->spi->SERCOM_DATA, (uint32_t)&spip->txsource, n);
  dmacChnlSetDir(spip->dmaRxId, (uint32_t)&spip->rxsink, (uint32_t)&spip->spi->SERCOM_DATA, n);
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
msg_t spi_lld_exchange(SPIDriver *spip, size_t n,
                       const void *txbuf, void *rxbuf)
{
  if (spip->config->ctrlb & SERCOM_SPIM_CTRLB_CHSIZE_Msk == SERCOM_SPIM_CTRLB_CHSIZE_9_BIT)
  {
    dmacChnlSetBtCtrl(spip->dmaTxId, DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_HWORD | DMAC_BTCTRL_SRCINC_Msk | DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId, DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_HWORD | DMAC_BTCTRL_DSTINC_Msk | DMAC_BTCTRL_VALID_Msk);
  }
  else
  {
    dmacChnlSetBtCtrl(spip->dmaTxId, DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_SRCINC_Msk | DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId, DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_DSTINC_Msk | DMAC_BTCTRL_VALID_Msk);
  }
  dmacChnlSetDir(spip->dmaTxId, (uint32_t)&spip->spi->SERCOM_DATA, (uint32_t)txbuf, n);
  dmacChnlSetDir(spip->dmaRxId, (uint32_t)rxbuf, (uint32_t)&spip->spi->SERCOM_DATA, n);
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
msg_t spi_lld_send(SPIDriver *spip, size_t n, const void *txbuf)
{
  if (spip->config->ctrlb & SERCOM_SPIM_CTRLB_CHSIZE_Msk == SERCOM_SPIM_CTRLB_CHSIZE_9_BIT)
  {
    dmacChnlSetBtCtrl(spip->dmaTxId, DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_HWORD | DMAC_BTCTRL_SRCINC_Msk | DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId, DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_HWORD | DMAC_BTCTRL_VALID_Msk);
  }
  else
  {
    dmacChnlSetBtCtrl(spip->dmaTxId, DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_SRCINC_Msk | DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId, DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_VALID_Msk);
  }
  dmacChnlSetDir(spip->dmaTxId, (uint32_t)&spip->spi->SERCOM_DATA, (uint32_t)txbuf, n);
  dmacChnlSetDir(spip->dmaRxId, (uint32_t)&spip->rxsink, (uint32_t)&spip->spi->SERCOM_DATA, n);
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
msg_t spi_lld_receive(SPIDriver *spip, size_t n, void *rxbuf)
{
  if (spip->config->ctrlb & SERCOM_SPIM_CTRLB_CHSIZE_Msk == SERCOM_SPIM_CTRLB_CHSIZE_9_BIT)
  {
    dmacChnlSetBtCtrl(spip->dmaTxId, DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_HWORD | DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId, DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_HWORD | DMAC_BTCTRL_DSTINC_Msk | DMAC_BTCTRL_VALID_Msk);
  }
  else
  {
    dmacChnlSetBtCtrl(spip->dmaTxId, DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_VALID_Msk);
    dmacChnlSetBtCtrl(spip->dmaRxId, DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_DSTINC_Msk | DMAC_BTCTRL_VALID_Msk);
  }
  dmacChnlSetDir(spip->dmaTxId, (uint32_t)&spip->spi->SERCOM_DATA, (uint32_t)&spip->txsource, n);
  dmacChnlSetDir(spip->dmaRxId, (uint32_t)rxbuf, (uint32_t)&spip->spi->SERCOM_DATA, n);
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
msg_t spi_lld_stop_transfer(SPIDriver *spip, size_t *sizep)
{

  dmacChnlDisable(spip->dmaTxId);
  while (!(spip->spi->SERCOM_INTFLAG & SERCOM_SPIM_INTFLAG_TXC_Msk))
    ;
  /* Size of unprocessed data.*/
  if (sizep != NULL)
  {
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
uint16_t spi_lld_polled_exchange(SPIDriver *spip, uint16_t frame)
{
  if (spip->config->ctrlb & SERCOM_SPIM_CTRLB_CHSIZE_Msk == SERCOM_SPIM_CTRLB_CHSIZE_9_BIT)
  {
    volatile uint16_t *dr16p = (volatile uint16_t *)&spip->spi->SERCOM_DATA;
    *dr16p = (uint16_t)frame;
    while ((spip->spi->SERCOM_INTFLAG & SERCOM_SPIM_INTFLAG_RXC_Msk) == 0U)
    {
      /* Waiting frame transfer.*/
    }
    frame = (uint16_t)*dr16p;
  }
  else
  {
    volatile uint8_t *dr8p = (volatile uint8_t *)&spip->spi->SERCOM_DATA;
    *dr8p = (uint8_t)frame;
    while ((spip->spi->SERCOM_INTFLAG & SERCOM_SPIM_INTFLAG_RXC_Msk) == 0U)
    {
      /* Waiting frame transfer.*/
    }
    frame = (uint16_t)*dr8p;
  }
  return frame;
}

#endif /* HAL_USE_SPI */

/** @} */
