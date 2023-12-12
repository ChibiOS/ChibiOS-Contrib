/*
    ChibiOS - Copyright (C) 2023 1Conan

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
 * @brief   SN32 SPI (v2) subsystem low level driver source.
 *
 * @addtogroup SPI_V2
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

/**
 * @brief   SPI0 driver identifier.
 */
#if (SN32_SPI_USE_SPI0 == TRUE) || defined(__DOXYGEN__)
SPIDriver SPID0;
#endif

/**
 * @brief   SPI1 driver identifier.
 */
#if (SN32_SPI_USE_SPI1 == TRUE) || defined(__DOXYGEN__)
SPIDriver SPID1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void spi_lld_configure(SPIDriver *spip) {
  spip->spi->CTRL0 = spip->config->ctrl0;
  spip->spi->CTRL1 = spip->config->ctrl1;
  spip->spi->CLKDIV = spip->config->clkdiv;

  spip->spi->CTRL0 |= (spip->config->slave << 3);
  spip->spi->CTRL0_b.SDODIS = false;

#if SPI_SELECT_MODE == SPI_SELECT_MODE_LLD
  // Use hardware Auto-SEL
  spip->spi->CTRL0_b.SELDIS = false;
#endif

  uint32_t sn32_spi_clock = (SN32_HCLK / ((2 * spip->config->clkdiv) + 2));
  if (sn32_spi_clock > 6000000) {
    spip->spi->DFDLY = true;
  }

  SPI_FIFO_FRESET(spip);

  spip->spi->IC = 0b1111;
  // enable RX FIFO threshold interrupt
  spip->spi->IE = 0b0100;

  spip->spi->CTRL0_b.SPIEN = true;
}

static inline void spi_lld_irq_handler(SPIDriver *spip) {
  if (spip->spi->RIS_b.RXFIFOTHIF) {
    chSysLockFromISR();
    uint16_t data = spip->spi->DATA;
    spip->spi->IC_b.RXFIFOTHIC = true;
    chSysUnlockFromISR();

    if (spip->rxbuf) spip->rxbuf[spip->idx] = data;

    if (++(spip->idx) >= spip->count) {
      __spi_isr_complete_code(spip);
    } else {
      spip->spi->DATA = spip->txbuf ? spip->txbuf[spip->idx] : 0x00;
    }
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if SN32_SPI_USE_SPI0
OSAL_IRQ_HANDLER(SN32_SPI0_HANDLER) {
  OSAL_IRQ_PROLOGUE();

  spi_lld_irq_handler(&SPID0);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if SN32_SPI_USE_SPI1
OSAL_IRQ_HANDLER(SN32_SPI1_HANDLER) {
  OSAL_IRQ_PROLOGUE();

  spi_lld_irq_handler(&SPID1);

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level SPI driver initialization.
 *
 * @notapi
 */
void spi_lld_init(void) {

#if SN32_SPI_USE_SPI0 == TRUE
  /* Driver initialization.*/
  spiObjectInit(&SPID0);
  SPID0.spi = SN32_SPI0;
#endif

#if SN32_SPI_USE_SPI1 == TRUE
  /* Driver initialization.*/
  spiObjectInit(&SPID1);
  SPID1.spi = SN32_SPI1;
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

  if (spip->state == SPI_STOP) {

    /* Enables the peripheral.*/

#if SN32_SPI_USE_SPI0 == TRUE
    if (&SPID0 == spip) {
      sys1EnableSPI0();
      nvicClearPending(SN32_SPI0_NUMBER);
      nvicEnableVector(SN32_SPI0_NUMBER, SN32_SPI_SPI0_IRQ_PRIORITY);
    }
#endif

#if SN32_SPI_USE_SPI1 == TRUE
    if (&SPID1 == spip) {
      sys1EnableSPI1();
      nvicClearPending(SN32_SPI1_NUMBER);
      nvicEnableVector(SN32_SPI1_NUMBER, SN32_SPI_SPI1_IRQ_PRIORITY);
    }
#endif

    else {
      osalDbgAssert(false, "invalid SPI instance");
    }
  }

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

  if (spip->state == SPI_READY) {

    /* Disables the peripheral.*/

    SPI_FIFO_FRESET(spip);

    spip->spi->CTRL0_b.SPIEN = false;

#if SN32_SPI_USE_SPI0 == TRUE
    if (&SPID0 == spip) {
      sys1DisableSPI0();
      nvicDisableVector(SN32_SPI0_NUMBER);
    }
#endif

#if SN32_SPI_USE_SPI1 == TRUE
    if (&SPID1 == spip) {
      sys1DisableSPI1();
      nvicDisableVector(SN32_SPI1_NUMBER);
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

  (void)spip;
  // noop - hardware auto-sel
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

  (void)spip;
  // noop - hardware auto-sel
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
  return spi_lld_exchange(spip, n, NULL, NULL);
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

  spip->txbuf = txbuf;
  spip->rxbuf = rxbuf;
  spip->count = n;
  spip->idx = 0;

  spip->spi->DATA = spip->txbuf ? spip->txbuf[0] : 0x00;

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
  return spi_lld_exchange(spip, n, txbuf, NULL);
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
  return spi_lld_exchange(spip, n, NULL, rxbuf);
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

  SPI_FIFO_FRESET(spip);

  if (sizep != NULL) {
    *sizep = spip->count - spip->idx;
  }

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
uint16_t spi_lld_polled_exchange(SPIDriver *spip, uint16_t frame) {
  spip->spi->DATA = frame;
  while (spip->spi->STAT_b.RX_EMPTY);

  return spip->spi->DATA;
}

#endif /* HAL_USE_SPI */

/** @} */
