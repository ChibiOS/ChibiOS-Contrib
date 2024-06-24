
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

/**
 * @brief   Low level SPI driver initialization.
 *
 * @notapi
 */
void spi_lld_init(void) {
#if SAM_SPI_USE_SERCOM0 == TRUE
  /* Driver initialization.*/
  spiObjectInit(&SPID1);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM0_Msk;
  SPID1.spi = &SERCOM0_REGS->SPIM;
  SPID1.clock = SAM_SERCOM0_GCLK_FREQ;
  SPID1.is_qspi = false;
#endif
#if SAM_SPI_USE_SERCOM1 == TRUE
  /* Driver initialization.*/
  spiObjectInit(&SPID2);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM1_Msk;
  SPID2.spi = &SERCOM1_REGS->SPIM;
  SPID2.clock = SAM_SERCOM1_GCLK_FREQ;
  SPID2.is_qspi = false;
#endif
#if SAM_SPI_USE_SERCOM2 == TRUE
  /* Driver initialization.*/
  spiObjectInit(&SPID3);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM2_Msk;
  SPID3.spi = &SERCOM2_REGS->SPIM;
  SPID3.clock = SAM_SERCOM2_GCLK_FREQ;
  SPID3.is_qspi = false;
#endif
#if SAM_SPI_USE_SERCOM3 == TRUE
  /* Driver initialization.*/
  spiObjectInit(&SPID4);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM3_Msk;
  SPID4.spi = &SERCOM3_REGS->SPIM;
  SPID4.clock = SAM_SERCOM3_GCLK_FREQ;
  SPID4.is_qspi = false;
#endif
#if SAM_SPI_USE_SERCOM4 == TRUE
  /* Driver initialization.*/
  spiObjectInit(&SPID5);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM4_Msk;
  SPID5.spi = &SERCOM4_REGS->SPIM;
  SPID5.clock = SAM_SERCOM4_GCLK_FREQ;
  SPID5.is_qspi = false;
#endif
#if SAM_SPI_USE_SERCOM5 == TRUE
  /* Driver initialization.*/
  spiObjectInit(&SPID6);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM5_Msk;
  SPID6.spi = &SERCOM5_REGS->SPIM;
  SPID6.clock = SAM_SERCOM5_GCLK_FREQ;
  SPID6.is_qspi = false;
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
msg_t sercom_spi_lld_start(SPIDriver* spip) {

  if (spip->state == SPI_STOP) {

    /* Enables the peripheral.*/
    if (false) {
    }

#if SAM_SPI_USE_SERCOM0 == TRUE
    else if (&SPID1 == spip) {
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM0_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM0_CORE_Val,
                   1);
      msg_t msg = sercom_spi_lld_get_dma(spip, SAM_SPI0_DMARX_CHANNEL,
                                  SAM_SPI0_DMATX_CHANNEL, SAM_SPI0_DMA_PRIO);
      if (msg != HAL_RET_SUCCESS) {
        return msg;
      }
      dmacChnlSetTrigSrc(spip->dmaTxId, SERCOM0_TX);
      dmacChnlSetTrigAct(spip->dmaTxId, BEAT);
      dmacChnlSetTrigSrc(spip->dmaRxId, SERCOM0_RX);
      dmacChnlSetTrigAct(spip->dmaRxId, BEAT);
    }
#endif

#if SAM_SPI_USE_SERCOM1 == TRUE
    else if (&SPID2 == spip) {
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM1_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM1_CORE_Val,
                   1);
      msg_t msg = sercom_spi_lld_get_dma(spip, SAM_SPI1_DMARX_CHANNEL,
                                  SAM_SPI1_DMATX_CHANNEL, SAM_SPI1_DMA_PRIO);
      if (msg != HAL_RET_SUCCESS) {
        return msg;
      }
      dmacChnlSetTrigSrc(spip->dmaTxId, SERCOM1_TX);
      dmacChnlSetTrigAct(spip->dmaTxId, BEAT);
      dmacChnlSetTrigSrc(spip->dmaRxId, SERCOM1_RX);
      dmacChnlSetTrigAct(spip->dmaRxId, BEAT);
    }
#endif

#if SAM_SPI_USE_SERCOM2 == TRUE
    else if (&SPID3 == spip) {
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM2_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM2_CORE_Val,
                   1);
      msg_t msg = sercom_spi_lld_get_dma(spip, SAM_SPI2_DMARX_CHANNEL,
                                  SAM_SPI2_DMATX_CHANNEL, SAM_SPI2_DMA_PRIO);
      if (msg != HAL_RET_SUCCESS) {
        return msg;
      }
      dmacChnlSetTrigSrc(spip->dmaTxId, SERCOM2_TX);
      dmacChnlSetTrigAct(spip->dmaTxId, BEAT);
      dmacChnlSetTrigSrc(spip->dmaRxId, SERCOM2_RX);
      dmacChnlSetTrigAct(spip->dmaRxId, BEAT);
    }
#endif

#if SAM_SPI_USE_SERCOM3 == TRUE
    else if (&SPID4 == spip) {
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM3_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM3_CORE_Val,
                   1);
      msg_t msg = sercom_spi_lld_get_dma(spip, SAM_SPI3_DMARX_CHANNEL,
                                  SAM_SPI3_DMATX_CHANNEL, SAM_SPI3_DMA_PRIO);
      if (msg != HAL_RET_SUCCESS) {
        return msg;
      }
      dmacChnlSetTrigSrc(spip->dmaTxId, SERCOM3_TX);
      dmacChnlSetTrigAct(spip->dmaTxId, BEAT);
      dmacChnlSetTrigSrc(spip->dmaRxId, SERCOM3_RX);
      dmacChnlSetTrigAct(spip->dmaRxId, BEAT);
    }
#endif

#if SAM_SPI_USE_SERCOM4 == TRUE
    else if (&SPID5 == spip) {
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM4_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM4_CORE_Val,
                   1);
      msg_t msg = sercom_spi_lld_get_dma(spip, SAM_SPI4_DMARX_CHANNEL,
                                  SAM_SPI4_DMATX_CHANNEL, SAM_SPI4_DMA_PRIO);
      if (msg != HAL_RET_SUCCESS) {
        return msg;
      }
      dmacChnlSetTrigSrc(spip->dmaTxId, SERCOM4_TX);
      dmacChnlSetTrigAct(spip->dmaTxId, BEAT);
      dmacChnlSetTrigSrc(spip->dmaRxId, SERCOM4_RX);
      dmacChnlSetTrigAct(spip->dmaRxId, BEAT);
    }
#endif

#if SAM_SPI_USE_SERCOM5 == TRUE
    else if (&SPID6 == spip) {
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM5_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM5_CORE_Val,
                   1);
      msg_t msg = sercom_spi_lld_get_dma(spip, SAM_SPI5_DMARX_CHANNEL,
                                  SAM_SPI5_DMATX_CHANNEL, SAM_SPI5_DMA_PRIO);
      if (msg != HAL_RET_SUCCESS) {
        return msg;
      }
      dmacChnlSetTrigSrc(spip->dmaTxId, SERCOM5_TX);
      dmacChnlSetTrigAct(spip->dmaTxId, BEAT);
      dmacChnlSetTrigSrc(spip->dmaRxId, SERCOM5_RX);
      dmacChnlSetTrigAct(spip->dmaRxId, BEAT);
    }
#endif
    else {
      osalDbgAssert(false, "invalid SPI instance");
    }
  } else {
    sercom_spi_lld_disable(spip);
  }
  spip->spi->SERCOM_CTRLA = SERCOM_SPIM_CTRLA_SWRST_Msk;
  while (spip->spi->SERCOM_SYNCBUSY != 0)
    ;
  uint32_t baud_val = spip->clock / (2U * spip->config->sercom_cfg.freq) - 1;
  if (baud_val > 255) {
    baud_val = 255;
  }
  spip->spi->SERCOM_BAUD = baud_val;
  spip->spi->SERCOM_CTRLB =
      (spip->config->sercom_cfg.ctrlb &
       ~(SERCOM_SPIM_CTRLB_MSSEN_Msk | SERCOM_SPIM_CTRLB_AMODE_Msk)) |
      SERCOM_SPIM_CTRLB_RXEN_Msk;
  while (spip->spi->SERCOM_SYNCBUSY != 0)
    ;
  uint32_t ctrla = (spip->config->sercom_cfg.ctrla &
       ~SERCOM_SPIM_CTRLA_FORBIDDEN) |
       SERCOM_SPIM_CTRLA_DIPO(spip->config->sercom_cfg.dipo) |
       SERCOM_SPIM_CTRLA_DOPO(spip->config->sercom_cfg.dopo) |
      (spip->config->slave ? SERCOM_SPIM_CTRLA_MODE_SPI_SLAVE
                           : SERCOM_SPIM_CTRLA_MODE_SPI_MASTER) |
      SERCOM_SPIM_CTRLA_ENABLE_Msk;
  spip->spi->SERCOM_CTRLA = ctrla;
      
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
void sercom_spi_lld_stop(SPIDriver* spip) {

  if (spip->state == SPI_READY) {
    uint8_t id = 0;
    uint8_t id_val = 0;
    /* Disables the peripheral.*/
    if (false) {
    }
#if SAM_SPI_USE_SERCOM0 == TRUE
    else if (&SPID1 == spip) {
      id = SAM_SERCOM0_GCLK_SRC_ID;
      id_val = GCLK_CLKCTRL_ID_SERCOM0_CORE_Val;
    }
#endif
#if SAM_SPI_USE_SERCOM1 == TRUE
    else if (&SPID2 == spip) {
      id = SAM_SERCOM1_GCLK_SRC_ID;
      id_val = GCLK_CLKCTRL_ID_SERCOM1_CORE_Val;
    }
#endif
#if SAM_SPI_USE_SERCOM2 == TRUE
    else if (&SPID3 == spip) {
      id = SAM_SERCOM2_GCLK_SRC_ID;
      id_val = GCLK_CLKCTRL_ID_SERCOM2_CORE_Val;
    }
#endif
#if SAM_SPI_USE_SERCOM3 == TRUE
    else if (&SPID4 == spip) {
      id = SAM_SERCOM3_GCLK_SRC_ID;
      id_val = GCLK_CLKCTRL_ID_SERCOM3_CORE_Val;
    }
#endif
#if SAM_SPI_USE_SERCOM4 == TRUE
    else if (&SPID5 == spip) {
      id = SAM_SERCOM4_GCLK_SRC_ID;
      id_val = GCLK_CLKCTRL_ID_SERCOM4_CORE_Val;
    }
#endif
#if SAM_SPI_USE_SERCOM5 == TRUE
    else if (&SPID6 == spip) {
      id = SAM_SERCOM5_GCLK_SRC_ID;
      id_val = GCLK_CLKCTRL_ID_SERCOM5_CORE_Val;
    }
#endif
    else {
      osalDbgAssert(false, "invalid SPI instance");
    }
    sercom_spi_lld_disable(spip);
    dmacChnlFreeI(spip->dmaRxId);
    dmacChnlFreeI(spip->dmaTxId);
    sam_gclk_mux(id, id_val, 0);
  }
}
