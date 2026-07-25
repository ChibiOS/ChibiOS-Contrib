/*
    Copyright (C) 2026 Belonit

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
 * @file    M251/hal_spi_lld.c
 * @brief   M251/M252 SPI subsystem low level driver source.
 *
 * @addtogroup SPI
 * @{
 */

#include "hal.h"

#if (HAL_USE_SPI == TRUE) || defined(__DOXYGEN__)

#include "m251_isr.h"

#define M251_SPI_CLOCK                    __HIRC
#define M251_SPI_CLKSEL_HIRC              3U
#define M251_SPI_IDLE_FRAME               0xFFU
#define M251_SPI_FIFO_DEPTH               4U
#define M251_SPI_FIFO_RX_THRESHOLD        2U
#define M251_SPI_FIFO_TX_THRESHOLD        1U

#define M251_SPI_MODE_MASK                                        \
  (SPI_CTL_RXNEG_Msk | SPI_CTL_TXNEG_Msk | SPI_CTL_CLKPOL_Msk)

#define M251_SPI_IRQ_MASK                                         \
  (SPI_FIFOCTL_RXTHIEN_Msk | SPI_FIFOCTL_TXTHIEN_Msk |            \
   SPI_FIFOCTL_RXTOIEN_Msk | SPI_FIFOCTL_RXOVIEN_Msk)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   SPID0 driver identifier.
 */
#if M251_SPI_USE_SPI0 || defined(__DOXYGEN__)
SPIDriver SPID0;
#endif

/**
 * @brief   SPID1 driver identifier.
 */
#if M251_SPI_USE_SPI1 || defined(__DOXYGEN__)
SPIDriver SPID1;
#endif

static void spi_lld_reset_fifo(SPIDriver *spip) {
  uint32_t timeout = 0x10000U;

  spip->spi->FIFOCTL = SPI_FIFOCTL_RXRST_Msk | SPI_FIFOCTL_TXRST_Msk;
  while (((spip->spi->STATUS & SPI_STATUS_TXRXRST_Msk) != 0U) &&
         (timeout > 0U)) {
    timeout--;
  }
  if (timeout == 0U) {
    osalSysHalt("SPI FIFO reset timeout");
  }
}

static void spi_lld_fill_tx(SPIDriver *spip) {
  uint32_t tx_count = (spip->spi->STATUS & SPI_STATUS_TXCNT_Msk) >>
                      SPI_STATUS_TXCNT_Pos;
  uint32_t slots = M251_SPI_FIFO_DEPTH - tx_count;

  while ((spip->txcnt > 0U) && (slots > 0U)) {
    uint8_t value = M251_SPI_IDLE_FRAME;

    if (spip->txptr != NULL) {
      value = *spip->txptr++;
    }
    spip->spi->TX = value;
    spip->txcnt--;
    slots--;
  }
}

static void spi_lld_drain_rx(SPIDriver *spip) {
  uint32_t available = (spip->spi->STATUS & SPI_STATUS_RXCNT_Msk) >>
                       SPI_STATUS_RXCNT_Pos;

  while ((spip->rxcnt > 0U) && (available > 0U)) {
    uint8_t value = (uint8_t)spip->spi->RX;

    if (spip->rxptr != NULL) {
      *spip->rxptr++ = value;
    }
    spip->rxcnt--;
    available--;
  }
}

static void spi_lld_arm_interrupts(SPIDriver *spip) {
  uint32_t fifoctl = spip->spi->FIFOCTL & ~M251_SPI_IRQ_MASK;

  if (spip->rxcnt > 0U) {
    fifoctl |= SPI_FIFOCTL_RXTHIEN_Msk | SPI_FIFOCTL_RXOVIEN_Msk;
    if (spip->txcnt > 0U) {
      fifoctl |= SPI_FIFOCTL_TXTHIEN_Msk;
    }
    else {
      fifoctl |= SPI_FIFOCTL_RXTOIEN_Msk;
    }
  }
  spip->spi->FIFOCTL = fifoctl;
}

static void spi_lld_serve_interrupt(SPIDriver *spip) {
  uint32_t status = spip->spi->STATUS;

  spip->spi->FIFOCTL &= ~M251_SPI_IRQ_MASK;

  if (spip->state != SPI_ACTIVE) {
    if ((status & SPI_STATUS_RXOVIF_Msk) != 0U) {
      spip->spi->STATUS = SPI_STATUS_RXOVIF_Msk;
    }
    if ((status & SPI_STATUS_RXTOIF_Msk) != 0U) {
      spip->spi->STATUS = SPI_STATUS_RXTOIF_Msk;
    }
    return;
  }

  if ((status & SPI_STATUS_RXOVIF_Msk) != 0U) {
    spip->spi->STATUS = SPI_STATUS_RXOVIF_Msk;
    spip->overrun = true;
    spip->txcnt = 0U;
    spip->rxcnt = 0U;
    _spi_isr_code(spip);
    return;
  }

  spi_lld_drain_rx(spip);
  if ((status & SPI_STATUS_RXTOIF_Msk) != 0U) {
    spip->spi->STATUS = SPI_STATUS_RXTOIF_Msk;
  }
  spi_lld_fill_tx(spip);

  if (spip->rxcnt == 0U) {
    _spi_isr_code(spip);
  }
  else {
    spi_lld_arm_interrupts(spip);
  }
}

#if M251_SPI_USE_SPI0 || defined(__DOXYGEN__)
/**
 * @brief   SPI0 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_SPI0_HANDLER) {

  OSAL_IRQ_PROLOGUE();
  spi_lld_serve_interrupt(&SPID0);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if M251_SPI_USE_SPI1 || defined(__DOXYGEN__)
/**
 * @brief   SPI1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_SPI1_HANDLER) {

  OSAL_IRQ_PROLOGUE();
  spi_lld_serve_interrupt(&SPID1);
  OSAL_IRQ_EPILOGUE();
}
#endif

static void spi_lld_configure_clock(SPIDriver *spip) {
  uint32_t divider;

  osalDbgAssert((spip->config->frequency > 0U) &&
                (spip->config->frequency <= M251_SPI_CLOCK),
                "invalid SPI frequency");

  divider = (M251_SPI_CLOCK + spip->config->frequency - 1U) /
            spip->config->frequency;
  if (divider < 1U) {
    divider = 1U;
  }
  osalDbgAssert(divider <= 512U, "SPI frequency below divider range");
  spip->spi->CLKDIV = divider - 1U;
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level SPI driver initialization.
 *
 * @notapi
 */
void spi_lld_init(void) {

#if M251_SPI_USE_SPI0
  spiObjectInit(&SPID0);
  SPID0.spi = SPI0;
#endif

#if M251_SPI_USE_SPI1
  spiObjectInit(&SPID1);
  SPID1.spi = SPI1;
#endif
}

/**
 * @brief   Configures and activates the SPI peripheral.
 *
 * @param[in] spip      pointer to a @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_start(SPIDriver *spip) {
  uint32_t timeout;

  if (spip->state == SPI_STOP) {
#if M251_SPI_USE_SPI0
    if (spip == &SPID0) {
      m251_lld_unlock();
      CLK->CLKSEL2 = (CLK->CLKSEL2 & ~CLK_CLKSEL2_SPI0SEL_Msk) |
                     (M251_SPI_CLKSEL_HIRC << CLK_CLKSEL2_SPI0SEL_Pos);
      CLK->APBCLK0 |= CLK_APBCLK0_SPI0CKEN_Msk;
      SYS->IPRST1 |= SYS_IPRST1_SPI0RST_Msk;
      SYS->IPRST1 &= ~SYS_IPRST1_SPI0RST_Msk;
      m251_lld_lock();
      nvicEnableVector(M251_SPI0_NUMBER, M251_SPI_SPI0_IRQ_PRIORITY);
    }
#endif
#if M251_SPI_USE_SPI1
    if (spip == &SPID1) {
      m251_lld_unlock();
      CLK->CLKSEL2 = (CLK->CLKSEL2 & ~CLK_CLKSEL2_SPI1SEL_Msk) |
                     (M251_SPI_CLKSEL_HIRC << CLK_CLKSEL2_SPI1SEL_Pos);
      CLK->APBCLK0 |= CLK_APBCLK0_SPI1CKEN_Msk;
      SYS->IPRST1 |= SYS_IPRST1_SPI1RST_Msk;
      SYS->IPRST1 &= ~SYS_IPRST1_SPI1RST_Msk;
      m251_lld_lock();
      nvicEnableVector(M251_SPI1_NUMBER, M251_SPI_SPI1_IRQ_PRIORITY);
    }
#endif
  }

  spip->spi->CTL &= ~SPI_CTL_SPIEN_Msk;
  timeout = 0x10000U;
  while (((spip->spi->STATUS & SPI_STATUS_SPIENSTS_Msk) != 0U) &&
         (timeout > 0U)) {
    timeout--;
  }
  if (timeout == 0U) {
    osalSysHalt("SPI disable timeout");
  }

  spi_lld_reset_fifo(spip);
  osalDbgAssert((spip->config->mode & ~M251_SPI_MODE_MASK) == 0U,
                "invalid SPI mode");
  spip->spi->I2SCTL = 0U;
  spip->spi->SSCTL = 0U;
  spip->spi->PDMACTL = 0U;
  spip->spi->FIFOCTL = 0U;
  spi_lld_configure_clock(spip);
  spip->spi->CTL = SPI_CTL_SPIEN_Msk |
                   (8U << SPI_CTL_DWIDTH_Pos) |
                   spip->config->mode;
}

/**
 * @brief   Deactivates the SPI peripheral.
 *
 * @param[in] spip      pointer to a @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_stop(SPIDriver *spip) {

  if (spip->state != SPI_STOP) {
    spip->spi->FIFOCTL = 0U;
    spip->spi->CTL = 0U;

#if M251_SPI_USE_SPI0
    if (spip == &SPID0) {
      nvicDisableVector(M251_SPI0_NUMBER);
      m251_lld_unlock();
      SYS->IPRST1 |= SYS_IPRST1_SPI0RST_Msk;
      SYS->IPRST1 &= ~SYS_IPRST1_SPI0RST_Msk;
      CLK->APBCLK0 &= ~CLK_APBCLK0_SPI0CKEN_Msk;
      m251_lld_lock();
    }
#endif
#if M251_SPI_USE_SPI1
    if (spip == &SPID1) {
      nvicDisableVector(M251_SPI1_NUMBER);
      m251_lld_unlock();
      SYS->IPRST1 |= SYS_IPRST1_SPI1RST_Msk;
      SYS->IPRST1 &= ~SYS_IPRST1_SPI1RST_Msk;
      CLK->APBCLK0 &= ~CLK_APBCLK0_SPI1CKEN_Msk;
      m251_lld_lock();
    }
#endif
  }
}

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void spi_lld_start_transfer(SPIDriver *spip, size_t n,
                                   const void *txbuf, void *rxbuf) {

  spip->txptr = (const uint8_t *)txbuf;
  spip->rxptr = (uint8_t *)rxbuf;
  spip->txcnt = n;
  spip->rxcnt = n;
  spip->overrun = false;

  spip->spi->FIFOCTL =
      (M251_SPI_FIFO_RX_THRESHOLD << SPI_FIFOCTL_RXTH_Pos) |
      (M251_SPI_FIFO_TX_THRESHOLD << SPI_FIFOCTL_TXTH_Pos);
  spi_lld_fill_tx(spip);
  spi_lld_arm_interrupts(spip);
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Receives data while transmitting idle frames.
 *
 * @param[in] spip      pointer to a @p SPIDriver object
 * @param[in] n         number of frames to exchange
 *
 * @notapi
 */
void spi_lld_ignore(SPIDriver *spip, size_t n) {

  spi_lld_start_transfer(spip, n, NULL, NULL);
}

/**
 * @brief   Exchanges data over SPI.
 *
 * @param[in] spip      pointer to a @p SPIDriver object
 * @param[in] n         number of frames to exchange
 * @param[in] txbuf     pointer to the transmit buffer
 * @param[out] rxbuf    pointer to the receive buffer
 *
 * @notapi
 */
void spi_lld_exchange(SPIDriver *spip, size_t n,
                      const void *txbuf, void *rxbuf) {

  spi_lld_start_transfer(spip, n, txbuf, rxbuf);
}

/**
 * @brief   Sends data over SPI.
 *
 * @param[in] spip      pointer to a @p SPIDriver object
 * @param[in] n         number of frames to send
 * @param[in] txbuf     pointer to the transmit buffer
 *
 * @notapi
 */
void spi_lld_send(SPIDriver *spip, size_t n, const void *txbuf) {

  spi_lld_start_transfer(spip, n, txbuf, NULL);
}

/**
 * @brief   Receives data over SPI.
 *
 * @param[in] spip      pointer to a @p SPIDriver object
 * @param[in] n         number of frames to receive
 * @param[out] rxbuf    pointer to the receive buffer
 *
 * @notapi
 */
void spi_lld_receive(SPIDriver *spip, size_t n, void *rxbuf) {

  spi_lld_start_transfer(spip, n, NULL, rxbuf);
}

/**
 * @brief   Exchanges one frame using polling.
 *
 * @param[in] spip      pointer to a @p SPIDriver object
 * @param[in] frame     frame to transmit
 * @return              The received frame.
 *
 * @notapi
 */
uint16_t spi_lld_polled_exchange(SPIDriver *spip, uint16_t frame) {
  uint32_t timeout = 0x100000U;

  spip->spi->TX = (uint8_t)frame;
  while (((spip->spi->STATUS & SPI_STATUS_RXEMPTY_Msk) != 0U) &&
         (timeout > 0U)) {
    timeout--;
  }
  if (timeout == 0U) {
    osalSysHalt("SPI polled exchange timeout");
  }
  return (uint16_t)(uint8_t)spip->spi->RX;
}

#endif /* HAL_USE_SPI == TRUE */

/** @} */
