/*
    Copyright (C) 2021 Westberry Technology (ChangZhou) Corp., Ltd

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
 * @file    SPIv1/hal_spi_lld.c
 * @brief   WB32 SPI subsystem low level driver source.
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

/** @brief QSPI driver identifier.*/
#if WB32_SPI_USE_QSPI || defined(__DOXYGEN__)
SPIDriver SPIDQ;
#endif

/** @brief SPIM2 driver identifier.*/
#if WB32_SPI_USE_SPIM2 || defined(__DOXYGEN__)
SPIDriver SPIDM2;
#endif

/** @brief SPIS1 driver identifier.*/
#if WB32_SPI_USE_SPIS1 || defined(__DOXYGEN__)
SPIDriver SPIDS1;
#endif

/** @brief SPIS2 driver identifier.*/
#if WB32_SPI_USE_SPIS2 || defined(__DOXYGEN__)
SPIDriver SPIDS2;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

static const uint16_t dummytx = 0xFFFFU;
static uint16_t dummyrx;

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   SPI shared ISR code.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
static void spi_lld_serve_event_interrupt(SPIDriver *spip) {
  SPI_TypeDef *spi = spip->spi;
  uint16_t rx_byte, tx_byte;

  if (spi->ISR & SPI_IT_RXF) {
    while (spi->SR & SPI_SR_RFNE) {
      rx_byte = (uint16_t)spi->DR;
      if (spip->g_spi_xfer_info.rx_len) {
        spip->g_spi_xfer_info.rx_len--;
        *spip->g_spi_xfer_info.rx_buf = rx_byte;
        if (!spip->g_spi_xfer_info.rx_dummy) {
          spip->g_spi_xfer_info.rx_buf++;
        }
      }
      if (spip->g_spi_xfer_info.rx_len == RESET) {
        break;
      }
    }
    if (spip->g_spi_xfer_info.rx_len == RESET) {
      spip->g_spi_xfer_info.rx_dummy = FALSE;
      /* Disable the selected SPI interrupt.*/
      spi->IER &= ~SPI_IT_RXF;
      /* Portable SPI ISR code defined in the high level driver.*/
      _spi_isr_code(spip);
    }
  }

  if (spi->ISR & SPI_IT_TXE) {
    while (spi->SR & SPI_SR_TFNF) {
      if (spip->g_spi_xfer_info.tx_len) {
        spip->g_spi_xfer_info.tx_len--;
        tx_byte = *spip->g_spi_xfer_info.tx_buf;
        spi->DR = tx_byte;
        if (!spip->g_spi_xfer_info.tx_dummy) {
          spip->g_spi_xfer_info.tx_buf++;
        }
      }
      if (spip->g_spi_xfer_info.tx_len == RESET) {
        break;
      }
    }
    if (spip->g_spi_xfer_info.tx_len == RESET) {
      spip->g_spi_xfer_info.tx_dummy = FALSE;
      /* Disable the selected SPI interrupt.*/
      spi->IER &= ~SPI_IT_TXE;
    }
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/
#if WB32_SPI_USE_QSPI || defined(__DOXYGEN__)

#if defined(WB32_QSPI_IRQ_VECTOR)
/**
 * @brief   QSPI event interrupt handler.
 *
 * @notapi
 */
OSAL_IRQ_HANDLER(WB32_QSPI_IRQ_VECTOR) {

  OSAL_IRQ_PROLOGUE();

  spi_lld_serve_event_interrupt(&SPIDQ);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif /* WB32_SPI_USE_QSPI */

#if WB32_SPI_USE_SPIM2 || defined(__DOXYGEN__)

#if defined(WB32_SPIM2_IRQ_VECTOR)
/**
 * @brief   SPIM2 event interrupt handler.
 *
 * @notapi
 */
OSAL_IRQ_HANDLER(WB32_SPIM2_IRQ_VECTOR) {

  OSAL_IRQ_PROLOGUE();

  spi_lld_serve_event_interrupt(&SPIDM2);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif /* WB32_SPI_USE_SPIM2 */

#if WB32_SPI_USE_SPIS1 || defined(__DOXYGEN__)

#if defined(WB32_SPIS1_IRQ_VECTOR)
/**
 * @brief   SPIS1 event interrupt handler.
 *
 * @notapi
 */
OSAL_IRQ_HANDLER(WB32_SPIS1_IRQ_VECTOR) {

  OSAL_IRQ_PROLOGUE();

  spi_lld_serve_event_interrupt(&SPIDS1);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif /* WB32_SPI_USE_SPIS1 */

#if WB32_SPI_USE_SPIS2 || defined(__DOXYGEN__)

#if defined(WB32_SPIS2_IRQ_VECTOR)
/**
 * @brief   SPIS2 event interrupt handler.
 *
 * @notapi
 */
OSAL_IRQ_HANDLER(WB32_SPIS2_IRQ_VECTOR) {

  OSAL_IRQ_PROLOGUE();

  spi_lld_serve_event_interrupt(&SPIDS2);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif /* WB32_SPI_USE_SPIS2 */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level SPI driver initialization.
 *
 * @notapi
 */
void spi_lld_init(void) {

#if WB32_SPI_USE_QSPI
  spiObjectInit(&SPIDQ);
  SPIDQ.spi = QSPI;
#endif

#if WB32_SPI_USE_SPIM2
  spiObjectInit(&SPIDM2);
  SPIDM2.spi = SPIM2;
#endif

#if WB32_SPI_USE_SPIS1
  spiObjectInit(&SPIDS1);
  SPIDS1.spi = SPIS1;
#endif

#if WB32_SPI_USE_SPIS2
  spiObjectInit(&SPIDS2);
  SPIDS2.spi = SPIS2;
#endif
}

/**
 * @brief   Configures and activates the SPI peripheral.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_start(SPIDriver *spip) {

  /* If in stopped state then enables the SPI and DMA clocks.*/
  if (spip->state == SPI_STOP) {
#if WB32_SPI_USE_QSPI
    if (&SPIDQ == spip) {
      /* Enable the QSPI clock.*/
      rccEnableQSPI();
      /* Deinit the QSPI.*/
      rccResetQSPI();

      nvicEnableVector(QSPI_IRQn, WB32_SPI_QSPI_IRQ_PRIORITY);

      spip->spi->BAUDR = spip->config->SPI_BaudRatePrescaler;
      spip->spi->SER |= spip->config->SPI_NSS;
    }
#endif
#if WB32_SPI_USE_SPIM2
    if (&SPIDM2 == spip) {
      /* Enable the SPIM2 clock.*/
      rccEnableSPIM2();
      /* Deinit the SPIM2.*/
      rccResetSPIM2();

      nvicEnableVector(SPIM2_IRQn, WB32_SPI_SPIM2_IRQ_PRIORITY);

      spip->spi->BAUDR = spip->config->SPI_BaudRatePrescaler;
      spip->spi->SER |= spip->config->SPI_NSS;
    }
#endif
#if WB32_SPI_USE_SPIS1
    if (&SPIDS1 == spip) {
      /* Enable the SPIS1 clock.*/
      rccEnableSPIS1();
      /* Deinit the SPIS1.*/
      rccResetSPIS1();

      nvicEnableVector(SPIS1_IRQn, WB32_SPI_SPIS1_IRQ_PRIORITY);
    }
#endif
#if WB32_SPI_USE_SPIS2
    if (&SPIDS2 == spip) {
      /* Enable the SPIS2 clock.*/
      rccEnableSPIS2();
      /* Deinit the SPIS2.*/
      rccResetSPIS2();

      nvicEnableVector(SPIS2_IRQn, WB32_SPI_SPIS2_IRQ_PRIORITY);
    }
#endif
  }
#if (SPI_SUPPORTS_CIRCULAR == TRUE) || defined(__DOXYGEN__)
  osalDbgAssert(spip->config->circular != FALSE, "unsupported circular");
#endif

  spip->spi->CR0 = (spip->config->SPI_DataSize | spip->config->SPI_FrameFormat |
                    spip->config->SPI_CPHA | spip->config->SPI_CPOL |
                    spip->config->SPI_TransferMode);

  spip->spi->TXFTLR = 2;

  /* Disable all SPI interrupt.*/
  spip->spi->IER &= ~0xFF;
  /* Clear all SPI's interrupt pending bits.*/
  (void)spip->spi->ICR;
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
    /* SPI disable.*/
    spip->spi->SPIENR = 0x00;

    /* Disable all SPI interrupt.*/
    spip->spi->IER &= ~0xFF;
    /* Clear all SPI's interrupt pending bits.*/
    (void)spip->spi->ICR;

#if WB32_SPI_USE_QSPI
    if (&SPIDQ == spip) {
      nvicDisableVector(QSPI_IRQn);
      /* Disable the QSPI clock.*/
      rccDisableQSPI();
    }
#endif
#if WB32_SPI_USE_SPIM2
    if (&SPIDM2 == spip) {
      nvicDisableVector(SPIM2_IRQn);
      /* Disable the SPIM2 clock.*/
      rccDisableSPIM2();
    }
#endif
#if WB32_SPI_USE_SPIS1
    if (&SPIDS1 == spip) {
      nvicDisableVector(SPIS1_IRQn);
      /* Disable the SPIS1 clock.*/
      rccDisableSPIS1();
    }
#endif
#if WB32_SPI_USE_SPIS2
    if (&SPIDS2 == spip) {
      nvicDisableVector(SPIS2_IRQn);
      /* Disable the SPIS2 clock.*/
      rccDisableSPIS2();
    }
#endif
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

  /* No implementation on WB32.*/
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

  /* No implementation on WB32.*/
}
#endif

/**
 * @brief   Ignores data on the SPI bus.
 * @details This asynchronous function starts the transmission of a series of
 *          idle words on the SPI bus and ignores the received data.
 * @post    At the end of the operation the configured callback is invoked.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of words to be ignored
 *
 * @notapi
 */
void spi_lld_ignore(SPIDriver *spip, size_t n) {

  spip->g_spi_xfer_info.tx_dummy = TRUE;
  spip->g_spi_xfer_info.rx_dummy = TRUE;

  spip->g_spi_xfer_info.tx_buf = (uint8_t *)&dummytx;
  spip->g_spi_xfer_info.rx_buf = (uint8_t *)&dummyrx;

  spip->g_spi_xfer_info.tx_len = n;
  spip->g_spi_xfer_info.rx_len = n;

  spip->spi->IER |= (spip->config->SPI_IT);
  spip->spi->SPIENR = 0x01;
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
 *
 * @notapi
 */
void spi_lld_exchange(SPIDriver *spip,
                      size_t n,
                      const void *txbuf,
                      void *rxbuf) {

  spip->g_spi_xfer_info.tx_buf = txbuf;
  spip->g_spi_xfer_info.tx_len = n;
  spip->g_spi_xfer_info.tx_dummy = FALSE;

  spip->g_spi_xfer_info.rx_buf = rxbuf;
  spip->g_spi_xfer_info.rx_len = n;
  spip->g_spi_xfer_info.rx_dummy = FALSE;

  spip->spi->IER |= (spip->config->SPI_IT);
  spip->spi->SPIENR = 0x01;
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
 *
 * @notapi
 */
void spi_lld_send(SPIDriver *spip, size_t n, const void *txbuf) {

  spip->g_spi_xfer_info.tx_buf = txbuf;
  spip->g_spi_xfer_info.tx_len = n;
  spip->g_spi_xfer_info.tx_dummy = FALSE;

  spip->g_spi_xfer_info.rx_buf = (uint8_t *)&dummyrx;
  spip->g_spi_xfer_info.rx_len = n;
  spip->g_spi_xfer_info.rx_dummy = TRUE;

  spip->spi->IER |= (spip->config->SPI_IT);
  spip->spi->SPIENR = 0x01;
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
 *
 * @notapi
 */
void spi_lld_receive(SPIDriver *spip, size_t n, void *rxbuf) {

  spip->g_spi_xfer_info.tx_buf = (const uint8_t *)&dummytx;
  spip->g_spi_xfer_info.tx_len = n;
  spip->g_spi_xfer_info.tx_dummy = TRUE;

  spip->g_spi_xfer_info.rx_buf = rxbuf;
  spip->g_spi_xfer_info.rx_len = n;
  spip->g_spi_xfer_info.rx_dummy = FALSE;

  spip->spi->IER |= (spip->config->SPI_IT);
  spip->spi->SPIENR = 0x01;
}

#if (SPI_SUPPORTS_CIRCULAR == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   Aborts the ongoing SPI operation, if any.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_abort(SPIDriver *spip) {

  /* SPI disable.*/
  spip->spi->SPIENR = 0x00;

  /* Disable all SPI interrupt.*/
  spip->spi->IER &= ~0xFF;
  /* Clear all SPI's interrupt pending bits.*/
  (void)spip->spi->ICR;
}
#endif /* SPI_SUPPORTS_CIRCULAR == TRUE */

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

  while ((spip->spi->SR & SPI_SR_TFE) == 0)
    ;
  spip->spi->DR = frame;
  while ((spip->spi->SR & SPI_SR_RFNE) == 0)
    ;
  return spip->spi->DR;
}

#endif /* HAL_USE_SPI */

/** @} */
