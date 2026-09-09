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
 * @file    SK32F0xx/hal_spi_lld.c
 * @brief   SK32F0xx low level SPI driver code.
 * @details The SK32F0xx SPI is a legacy CR1/CR2/SR/DR unit (SPIv1 class,
 *          no FIFO).  Transfers are driven by the RXNE/TXE interrupts, the
 *          end of a transfer is detected on the reception of the last
 *          frame, this is more reliable than watching the TXE flag because
 *          the data register goes empty before the last frame is shifted
 *          out.
 *
 * @addtogroup SPI
 * @{
 */

#include "hal.h"

#if HAL_USE_SPI || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   CR2 bits owned by this driver (interrupt enables).
 */
#define SK32_SPI_CR2_IE_MASK     ((uint16_t)(SPI_CR2_RXNEIE  |              \
                                             SPI_CR2_TXEIE  |              \
                                             SPI_CR2_ERRIE))

/**
 * @brief   CR2 bits owned by this driver including the DMA request bits
 *          that the interrupt-driven driver never uses.
 */
#define SK32_SPI_CR2_OWNED_MASK  ((uint16_t)(SK32_SPI_CR2_IE_MASK |         \
                                             SPI_CR2_RXDMAEN |              \
                                             SPI_CR2_TXDMAEN))

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief SPI1 driver identifier.*/
#if SK32_SPI_USE_SPI1 || defined(__DOXYGEN__)
SPIDriver SPID1;
#endif

/** @brief SPI2 driver identifier.*/
#if SK32_SPI_USE_SPI2 || defined(__DOXYGEN__)
SPIDriver SPID2;
#endif

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Starts a transfer.
 * @note    This function is meant to be called with interrupts disabled.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of frames to be transferred
 * @param[in] txbuf     the pointer to the transmit buffer or @p NULL
 * @param[out] rxbuf    the pointer to the receive buffer or @p NULL
 */
static void spi_lld_transfer_start(SPIDriver *spip, size_t n,
                                   const void *txbuf, void *rxbuf) {

  spip->txbuf = txbuf;
  spip->rxbuf = rxbuf;
  spip->txidx = 0U;
  spip->rxidx = 0U;
  spip->count = n;

  /* Enabling the sources, the first TXE interrupt writes the first frame
     into the data register starting the transfer.*/
  spip->spi->CR2 |= SK32_SPI_CR2_IE_MASK;
}

/**
 * @brief   Common IRQ handler.
 * @note    The data register must always be read on RXNE even when there is
 *          no receive buffer, leaving received frames unread would raise an
 *          overrun condition.
 *
 * @param[in] spip      communication channel associated to the SPI
 */
static void spi_lld_serve_interrupt(SPIDriver *spip) {
  SPI_TypeDef *spi = spip->spi;
  uint16_t cr2 = spi->CR2;
  uint16_t sr = spi->SR;

  /* Error conditions detection, the transfer is aborted.  Both the overrun
     and the mode fault conditions are cleared by the SR read above followed
     by a data register read (OVR) or a CR1 write (MODF).*/
  if (((cr2 & SPI_CR2_ERRIE) != 0U) &&
      ((sr & (SPI_SR_OVR | SPI_SR_MODF)) != 0U)) {
    if ((sr & SPI_SR_OVR) != 0U) {
      (void)spi->DR;
    }
    if ((sr & SPI_SR_MODF) != 0U) {
      spi->CR1 = spi->CR1;
    }
    spi->CR2 &= (uint16_t)~SK32_SPI_CR2_IE_MASK;
    SK32_SPI_ERROR_HOOK(spip);
    return;
  }

  /* Data received.  The transfer is complete when the last frame has been
     received, the RXNE counter is the reliable completion indicator on
     units without a FIFO.*/
  if (((cr2 & SPI_CR2_RXNEIE) != 0U) && ((sr & SPI_SR_RXNE) != 0U)) {
    uint16_t dr = spi->DR;

    if (spip->rxbuf != NULL) {
      if ((spi->CR1 & SPI_CR1_DFF) != 0U) {
        ((uint16_t *)spip->rxbuf)[spip->rxidx] = dr;
      }
      else {
        ((uint8_t *)spip->rxbuf)[spip->rxidx] = (uint8_t)dr;
      }
    }
    spip->rxidx++;
    if (spip->rxidx >= spip->count) {
      spi->CR2 &= (uint16_t)~SK32_SPI_CR2_IE_MASK;
      _spi_isr_code(spip);
      return;
    }
  }

  /* Data to be transmitted.  When there is no transmit buffer a dummy
     all-ones frame is sent (receive-only and ignore operations).*/
  if (((cr2 & SPI_CR2_TXEIE) != 0U) && ((sr & SPI_SR_TXE) != 0U)) {
    if (spip->txidx < spip->count) {
      uint16_t frame = 0xFFFFU;

      if (spip->txbuf != NULL) {
        if ((spi->CR1 & SPI_CR1_DFF) != 0U) {
          frame = ((const uint16_t *)spip->txbuf)[spip->txidx];
        }
        else {
          frame = ((const uint8_t *)spip->txbuf)[spip->txidx];
        }
      }
      spi->DR = frame;
      spip->txidx++;
    }
    else {
      /* All the frames have been queued, waiting for the last reception
         to complete the operation.*/
      spi->CR2 &= (uint16_t)~(uint16_t)SPI_CR2_TXEIE;
    }
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if SK32_SPI_USE_SPI1 || defined(__DOXYGEN__)
#if !defined(SK32_SPI1_SUPPRESS_ISR)
#if !defined(SK32_SPI1_HANDLER)
#error "SK32_SPI1_HANDLER not defined"
#endif
/**
 * @brief   SPI1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SK32_SPI1_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  spi_lld_serve_interrupt(&SPID1);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif

#if SK32_SPI_USE_SPI2 || defined(__DOXYGEN__)
#if !defined(SK32_SPI2_SUPPRESS_ISR)
#if !defined(SK32_SPI2_HANDLER)
#error "SK32_SPI2_HANDLER not defined"
#endif
/**
 * @brief   SPI2 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SK32_SPI2_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  spi_lld_serve_interrupt(&SPID2);

  OSAL_IRQ_EPILOGUE();
}
#endif
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

#if SK32_SPI_USE_SPI1
  spiObjectInit(&SPID1);
  SPID1.spi = SPI1;
#if !defined(SK32_SPI1_SUPPRESS_ISR) && defined(SK32_SPI1_NUMBER)
  nvicEnableVector(SK32_SPI1_NUMBER, SK32_SPI_SPI1_PRIORITY);
#endif
#endif

#if SK32_SPI_USE_SPI2
  spiObjectInit(&SPID2);
  SPID2.spi = SPI2;
#if !defined(SK32_SPI2_SUPPRESS_ISR) && defined(SK32_SPI2_NUMBER)
  nvicEnableVector(SK32_SPI2_NUMBER, SK32_SPI_SPI2_PRIORITY);
#endif
#endif
}

/**
 * @brief   Configures and activates the SPI peripheral.
 * @note    Master mode with software slave management is forced on, the
 *          NSS pin is therefore available as a generic I/O pin and the
 *          chip select is handled by the upper driver (if configured).
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_start(SPIDriver *spip) {

  /* If in stopped state then enables the SPI clock.*/
  if (spip->state == SPI_STOP) {
#if SK32_SPI_USE_SPI1
    if (&SPID1 == spip) {
      rccEnableSPI1(true);
    }
#endif
#if SK32_SPI_USE_SPI2
    if (&SPID2 == spip) {
      rccEnableSPI2(true);
    }
#endif
  }

  /* SPI setup and enable.*/
  spip->spi->CR1 &= (uint16_t)~SPI_CR1_SPE;
  spip->spi->CR1  = spip->config->cr1 | SPI_CR1_MSTR | SPI_CR1_SSM |
                                  SPI_CR1_SSI;
  spip->spi->CR2  = spip->config->cr2 & (uint16_t)~SK32_SPI_CR2_OWNED_MASK;
  spip->spi->CR1 |= SPI_CR1_SPE;

  /* Making sure that no stale received frame can fool the next transfer
     into reading a spurious byte as its first frame.*/
  (void)spip->spi->SR;
  (void)spip->spi->DR;
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
    spip->spi->CR1 &= (uint16_t)~SPI_CR1_SPE;
    spip->spi->CR1  = 0U;
    spip->spi->CR2  = 0U;

#if SK32_SPI_USE_SPI1
    if (&SPID1 == spip) {
      rccDisableSPI1();
    }
#endif
#if SK32_SPI_USE_SPI2
    if (&SPID2 == spip) {
      rccDisableSPI2();
    }
#endif
  }
}

/**
 * @brief   Ignores data on the SPI bus.
 * @details This asynchronous function starts an receive process and ignores
 *          the received data.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of frames to send and discard
 *
 * @notapi
 */
void spi_lld_ignore(SPIDriver *spip, size_t n) {

  spi_lld_transfer_start(spip, n, NULL, NULL);
}

/**
 * @brief   Exchanges data on the SPI bus.
 * @details This asynchronous function starts a simultaneous transmit/receive
 *          operation.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of frames to send and receive
 * @param[in] txbuf     the pointer to the transmit buffer
 * @param[out] rxbuf    the pointer to the receive buffer
 *
 * @notapi
 */
void spi_lld_exchange(SPIDriver *spip, size_t n,
                      const void *txbuf, void *rxbuf) {

  spi_lld_transfer_start(spip, n, txbuf, rxbuf);
}

/**
 * @brief   Sends data over the SPI bus.
 * @details This asynchronous function starts a transmit operation.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of frames to send
 * @param[in] txbuf     the pointer to the transmit buffer
 *
 * @notapi
 */
void spi_lld_send(SPIDriver *spip, size_t n, const void *txbuf) {

  spi_lld_transfer_start(spip, n, txbuf, NULL);
}

/**
 * @brief   Receives data from the SPI bus.
 * @details This asynchronous function starts a receive operation.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of frames to receive
 * @param[out] rxbuf    the pointer to the receive buffer
 *
 * @notapi
 */
void spi_lld_receive(SPIDriver *spip, size_t n, void *rxbuf) {

  spi_lld_transfer_start(spip, n, NULL, rxbuf);
}

/**
 * @brief   Exchanges one frame using a polled wait.
 * @details This synchronous function exchanges one frame using a polled
 *          synchronization method.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] frame     the data frame to send over the SPI bus
 * @return              The received data frame from the SPI bus.
 *
 * @notapi
 */
uint16_t spi_lld_polled_exchange(SPIDriver *spip, uint16_t frame) {

  spip->spi->DR = frame;
  while ((spip->spi->SR & SPI_SR_RXNE) == 0U)
    ;
  return spip->spi->DR;
}

#endif /* HAL_USE_SPI */

/** @} */
