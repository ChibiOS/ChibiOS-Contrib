#include "hal.h"
#if HAL_USE_SPI || defined(__DOXYGEN__)


/**
 * @brief   SPI9 driver identifier.
 */
#if (SAM_SPI_USE_QSPI1 == TRUE) || defined(__DOXYGEN__)
SPIDriver SPID9;
#endif

// Use SPI Mode
// DATALEN = 8
#define QSPI_CTRLB_FORBIDDEN (QSPI_CTRLB_MODE_Msk | QSPI_CTRLB_DATALEN_Msk)

static inline void qspi_spi_lld_enable_irq(SPIDriver* spip) {
  qspi_registers_t *qspi = spip->qspi;
  qspi->QSPI_INTENSET = QSPI_INTENSET_CSRISE_Msk | QSPI_INTENSET_ERROR_Msk;
}
static inline void qspi_spi_lld_disable_irq(SPIDriver* spip) {
  qspi_registers_t *qspi = spip->qspi;
  qspi->QSPI_INTENCLR = QSPI_INTENCLR_CSRISE_Msk | QSPI_INTENCLR_ERROR_Msk;
}

static inline void qspi_spi_lld_err_irq(SPIDriver* spip) {
  /* Stopping DMAs.*/
  dmacChnlDisable(spip->dmaTxId);
  dmacChnlDisable(spip->dmaRxId);

  /* Reporting the failure.*/
  __spi_isr_error_code(spip, HAL_RET_HW_FAILURE);
}
static void qspi_spi_lld_serve_interrupt(SPIDriver* spip) {
  qspi_registers_t *qspi = spip->qspi;
  uint32_t intflag = qspi->QSPI_INTFLAG;
  // Clear intflag
  qspi->QSPI_INTFLAG = intflag; 
  if (intflag & QSPI_INTFLAG_ERROR_Msk){
    // Handle error
    qspi_spi_lld_err_irq(spip);
  }
  if (intflag & QSPI_INTFLAG_CSRISE_Msk) {
    /* Stopping DMAs.*/
    dmacChnlDisable(spip->dmaTxId);
    dmacChnlDisable(spip->dmaRxId);
    qspi_spi_lld_disable_irq(spip);
    /* Operation finished interrupt.*/
    __spi_isr_complete_code(spip);
  }
}

static void qspi_spi_dma_lld_serve_rx_interrupt(SPIDriver* spip, uint8_t flag) {
  if (flag & DMAC_CHINTFLAG_TERR_Msk) {
    qspi_spi_lld_err_irq(spip);
  }
  else if(flag & DMAC_CHINTFLAG_TCMPL_Msk) {
    qspi_spi_lld_enable_irq(spip);
  }
}

static void qspi_spi_lld_dma_serve_tx_interrupt(SPIDriver* spip, uint8_t flag) {
  if (flag & DMAC_CHINTFLAG_TERR_Msk) {
    qspi_spi_lld_err_irq(spip);
  }
}

static inline void qspi_spi_lld_disable(SPIDriver* spip) {
  dmacChnlDisable(spip->dmaTxId);
  spip->qspi->QSPI_CTRLA &= ~QSPI_CTRLA_ENABLE_Msk;
  while((spip->qspi->QSPI_STATUS & QSPI_STATUS_ENABLE_Msk) == QSPI_STATUS_ENABLE_Msk);
  dmacChnlDisable(spip->dmaRxId);
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
static msg_t qspi_spi_lld_get_dma(SPIDriver* spip, uint8_t rxstream,
                             uint8_t txstream, uint8_t priority) {
  int8_t dmacId =
      dmacChnlAllocI(rxstream, priority,
                     (sam_dmaisr_t)qspi_spi_dma_lld_serve_rx_interrupt, (void*)spip);
  if (dmacId < 0) {
    return HAL_RET_NO_RESOURCE;
  }
  spip->dmaRxId = (uint8_t)dmacId;

  dmacId =
      dmacChnlAllocI(txstream, priority,
                     (sam_dmaisr_t)qspi_spi_lld_dma_serve_tx_interrupt, (void*)spip);
  if (dmacId < 0) {
    dmacChnlFreeI(spip->dmaRxId);
    return HAL_RET_NO_RESOURCE;
  }
  spip->dmaTxId = (uint8_t)dmacId;

  return HAL_RET_SUCCESS;
}

void qspi_spi_lld_init(void)
{
#if SAM_SPI_USE_QSPI1 == TRUE
  /* Driver initialization.*/
  spiObjectInit(&SPID9);
  SPID9.qspi = QSPI_REGS;
  SPID9.clock = SAM_CPU_FREQ;
  SPID9.is_qspi = true;
#endif
}

msg_t qspi_spi_lld_start(SPIDriver* spip)
{
  qspi_registers_t *qspi = spip->qspi;
  uint32_t ctrlb = 0;
  uint32_t baud_val = 0;
  if (spip->state == SPI_STOP) {
    if(false) {

    }
    #if SAM_SPI_USE_QSPI1 == TRUE
    else if(&SPID9 == spip) {
      MCLK_REGS->MCLK_AHBMASK |= (MCLK_AHBMASK_QSPI_Msk);
      MCLK_REGS->MCLK_APBCMASK |= MCLK_APBCMASK_QSPI_Msk;
      msg_t msg = qspi_spi_lld_get_dma(spip, SAM_QSPI1_DMARX_CHANNEL,
                                  SAM_QSPI1_DMATX_CHANNEL, SAM_QSPI1_DMA_PRIO);
      if (msg != HAL_RET_SUCCESS) {
        return msg;
      }
      dmacChnlSetTrigSrc(spip->dmaTxId, QSPI_TX);
      dmacChnlSetTrigAct(spip->dmaTxId, BURST);
      dmacChnlSetTrigSrc(spip->dmaRxId, QSPI_RX);
      dmacChnlSetTrigAct(spip->dmaRxId, BURST);
      nvicEnableVector(QSPI_IRQn, SAM_QSPI_IRQ_PRIORITY);
    }
    
  }
  else {
    qspi_spi_lld_disable(spip);
  }
  #endif
  if (spip->config->slave) {
    osalDbgAssert(false, "Slave config is not supported on QSPI SPI mode");
  }
  qspi->QSPI_CTRLA = QSPI_CTRLA_SWRST_Msk;

  //TODO: Work on this 
  baud_val = (spip->clock / (spip->config->qspi_cfg.freq)) - 1;
  if (baud_val > 255) {
    baud_val = 255;
  }
  qspi->QSPI_BAUD = QSPI_BAUD_BAUD(baud_val) | QSPI_BAUD_CPHA(spip->config->qspi_cfg.cpha) | QSPI_BAUD_CPOL(spip->config->qspi_cfg.cpol);
  ctrlb = (spip->config->qspi_cfg.ctrlb & ~(QSPI_CTRLB_FORBIDDEN));
  qspi->QSPI_CTRLB = ctrlb;
  qspi->QSPI_CTRLA = QSPI_CTRLA_ENABLE_Msk;
  while((qspi->QSPI_STATUS & QSPI_STATUS_ENABLE_Msk) != QSPI_STATUS_ENABLE_Msk);
  return HAL_RET_SUCCESS;
}
void qspi_spi_lld_stop(SPIDriver* spip)
{
  qspi_registers_t *qspi = spip->qspi;
  if (spip->state == SPI_READY) {
    qspi_spi_lld_disable(spip);
    dmacChnlFreeI(spip->dmaRxId);
    dmacChnlFreeI(spip->dmaTxId);
    nvicDisableVector(QSPI_IRQn);
    if(false) {

    }
    #if SAM_SPI_USE_QSPI1 == TRUE
    else if(&SPID9 == spip) {
      MCLK_REGS->MCLK_AHBMASK &= ~MCLK_AHBMASK_QSPI_Msk;
      MCLK_REGS->MCLK_APBCMASK &= ~MCLK_APBCMASK_QSPI_Msk;
    }
  }
  #endif
}
#if (SPI_SELECT_MODE == SPI_SELECT_MODE_LLD) || defined(__DOXYGEN__)
void qspi_spi_lld_select(SPIDriver* spip)
{
  qspi_registers_t *qspi = spip->qspi;
}
void qspi_spi_lld_unselect(SPIDriver* spip)
{
  qspi_registers_t *qspi = spip->qspi;
}
#endif

msg_t qspi_spi_lld_ignore(SPIDriver* spip, size_t n)
{
  qspi_registers_t *qspi = spip->qspi;
  dmacChnlSetBtCtrl(spip->dmaTxId,
                    DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_VALID_Msk);
  dmacChnlSetBtCtrl(spip->dmaRxId,
                    DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_VALID_Msk);
  dmacChnlSetDir(spip->dmaTxId, (uint32_t)&qspi->QSPI_RXDATA,
                 (uint32_t)&spip->txsource, n);
  dmacChnlSetDir(spip->dmaRxId, (uint32_t)&spip->rxsink,
                 (uint32_t)&qspi->QSPI_RXDATA, n);
  dmacChnlEnableIRQn(spip->dmaTxId);
  dmacChnlEnableIRQn(spip->dmaRxId);
  dmacChnlEnable(spip->dmaRxId);
  dmacChnlEnable(spip->dmaTxId);
  return HAL_RET_SUCCESS;
}
msg_t qspi_spi_lld_exchange(SPIDriver* spip, size_t n, const void* txbuf,
                       void* rxbuf)
{
  qspi_registers_t *qspi = spip->qspi;

  dmacChnlSetBtCtrl(spip->dmaTxId,
                    DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_BYTE |
                        DMAC_BTCTRL_SRCINC_Msk | DMAC_BTCTRL_VALID_Msk);
  dmacChnlSetBtCtrl(spip->dmaRxId,
                    DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_BYTE |
                        DMAC_BTCTRL_DSTINC_Msk | DMAC_BTCTRL_VALID_Msk);
  dmacChnlSetDir(spip->dmaTxId, (uint32_t)&qspi->QSPI_TXDATA,
                 (uint32_t)txbuf, n);
  dmacChnlSetDir(spip->dmaRxId, (uint32_t)rxbuf,
                 (uint32_t)&qspi->QSPI_RXDATA, n);
  dmacChnlEnableIRQn(spip->dmaTxId);
  dmacChnlEnableIRQn(spip->dmaRxId);
  dmacChnlEnable(spip->dmaRxId);
  dmacChnlEnable(spip->dmaTxId);
  return HAL_RET_SUCCESS;
}
msg_t qspi_spi_lld_send(SPIDriver* spip, size_t n, const void* txbuf)
{
  qspi_registers_t *qspi = spip->qspi;
  dmacChnlSetBtCtrl(spip->dmaTxId,
                    DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_BYTE |
                        DMAC_BTCTRL_SRCINC_Msk | DMAC_BTCTRL_VALID_Msk);
  dmacChnlSetBtCtrl(spip->dmaRxId, DMAC_BTCTRL_BLOCKACT_INT |
                                        DMAC_BTCTRL_BEATSIZE_BYTE |
                                        DMAC_BTCTRL_VALID_Msk);
  dmacChnlSetDir(spip->dmaTxId, (uint32_t)&qspi->QSPI_TXDATA,
                 (uint32_t)txbuf, n);
  dmacChnlSetDir(spip->dmaRxId, (uint32_t)&spip->rxsink,
                 (uint32_t)&qspi->QSPI_RXDATA, n);
  dmacChnlEnableIRQn(spip->dmaTxId);
  dmacChnlEnableIRQn(spip->dmaRxId);
  dmacChnlEnable(spip->dmaRxId);
  dmacChnlEnable(spip->dmaTxId);
  return HAL_RET_SUCCESS;
}
msg_t qspi_spi_lld_receive(SPIDriver* spip, size_t n, void* rxbuf)
{
  qspi_registers_t *qspi = spip->qspi;
  dmacChnlSetBtCtrl(spip->dmaTxId, DMAC_BTCTRL_BLOCKACT_INT |
                                      DMAC_BTCTRL_BEATSIZE_BYTE |
                                      DMAC_BTCTRL_VALID_Msk);
  dmacChnlSetBtCtrl(spip->dmaRxId,
                    DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_BEATSIZE_BYTE |
                        DMAC_BTCTRL_DSTINC_Msk | DMAC_BTCTRL_VALID_Msk);
  dmacChnlSetDir(spip->dmaTxId, (uint32_t)&qspi->QSPI_TXDATA,
                 (uint32_t)&spip->txsource, n);
  dmacChnlSetDir(spip->dmaRxId, (uint32_t)rxbuf,
                 (uint32_t)&qspi->QSPI_RXDATA, n);
  dmacChnlEnableIRQn(spip->dmaTxId);
  dmacChnlEnableIRQn(spip->dmaRxId);
  dmacChnlEnable(spip->dmaRxId);
  dmacChnlEnable(spip->dmaTxId);
  return HAL_RET_SUCCESS;
}
msg_t qspi_spi_lld_stop_transfer(SPIDriver* spip, size_t* sizep)
{   
  qspi_registers_t *qspi = spip->qspi;
  dmacChnlDisable(spip->dmaTxId);
  
  while (!(qspi->QSPI_INTFLAG & QSPI_INTFLAG_TXC_Msk))
  /* Size of unprocessed data.*/
  if (sizep != NULL) {
    *sizep = dmacChnlGetTransferred(spip->dmaRxId);
  }
  dmacChnlDisable(spip->dmaRxId);
  qspi_spi_lld_disable_irq(spip);
  return HAL_RET_SUCCESS;
}
uint16_t qspi_spi_lld_polled_exchange(SPIDriver* spip, uint16_t frame)
{
  qspi_registers_t *qspi = spip->qspi;
  qspi->QSPI_TXDATA = frame;
  while ((qspi->QSPI_INTFLAG & QSPI_INTFLAG_RXC_Msk) == 0U) {
    /* Waiting frame transfer.*/
  }
  frame = qspi->QSPI_RXDATA;
  return frame;
}

#if SAM_SPI_USE_QSPI1 == TRUE
OSAL_IRQ_HANDLER(SAM_QSPI_HANDLER)
{
  OSAL_IRQ_EPILOGUE();
  qspi_spi_lld_serve_interrupt(&SPID9);
  OSAL_IRQ_PROLOGUE();
}
#endif
#endif /* HAL_USE_SPI */

/** @} */