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
 * @file    hal_sio_lld.c
 * @brief   PLATFORM SIO subsystem low level driver source.
 *
 * @addtogroup SIO
 * @{
 */

#include "hal.h"

#if (HAL_USE_SIO == TRUE) || defined(__DOXYGEN__)
#include "sercom_clk.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define SERCOM_UART_CTRLA_FORBIDDEN                                       \
  (SERCOM_USART_INT_CTRLA_ENABLE_Msk | SERCOM_USART_INT_CTRLA_SWRST_Msk | \
   SERCOM_USART_INT_CTRLA_TXPO_Msk | SERCOM_USART_INT_CTRLA_RXPO_Msk)

#define SERCOM_UART_CTRLB_FORBIDDEN (SERCOM_USART_INT_CTRLB_ENC_Msk)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline uint16_t usart_baud_calc(SIODriver* siop) {
  return (uint16_t)(65536U -
                    (uint32_t)(((uint64_t)65536U * 16U * siop->config->baud) /
                               siop->clock));
  // return (uint16_t)(65536ul * (siop->clock - 16 * siop->config->baud) / siop->clock);
}

static inline void usart_reset(SIODriver* siop) {
  siop->usart->SERCOM_CTRLA = SERCOM_USART_INT_CTRLA_SWRST_Msk;
  while ((siop->usart->SERCOM_SYNCBUSY & SERCOM_USART_INT_SYNCBUSY_SWRST_Msk) !=
         0U)
    ;
}

static inline void usart_init(SIODriver* siop) {
  siop->usart->SERCOM_BAUD =
      (uint16_t)(SERCOM_USART_INT_BAUD_BAUD(usart_baud_calc(siop)));
  siop->usart->SERCOM_CTRLA =
      (siop->config->ctrla & ~(SERCOM_UART_CTRLA_FORBIDDEN)) |
      SERCOM_USART_INT_CTRLA_TXPO(siop->config->txpo) |
      SERCOM_USART_INT_CTRLA_RXPO(siop->config->rxpo) |
      SERCOM_USART_INT_CTRLA_ENABLE_Msk;
  while ((siop->usart->SERCOM_SYNCBUSY &
          SERCOM_USART_INT_SYNCBUSY_ENABLE_Msk) != 0U)
    ;
  siop->usart->SERCOM_CTRLB =
      (siop->config->ctrlb & ~(SERCOM_UART_CTRLB_FORBIDDEN)) |
      SERCOM_USART_INT_CTRLB_RXEN_Msk | SERCOM_USART_INT_CTRLB_TXEN_Msk;
  while ((siop->usart->SERCOM_SYNCBUSY & SERCOM_USART_INT_SYNCBUSY_CTRLB_Msk) !=
         0U)
    ;
}

static inline void usart_enable_rx_errors_irq(SIODriver* siop) {
  uint8_t intenset =
      __sio_reloc_field(siop->enabled, SIO_EV_OVERRUN_ERR,
                        SIO_EV_OVERRUN_ERR_POS,
                        SERCOM_USART_INT_INTENSET_ERROR_Pos) |
      __sio_reloc_field(siop->enabled, SIO_EV_RXBREAK, SIO_EV_RXBREAK_POS,
                        SERCOM_USART_INT_INTENSET_RXBRK_Pos) |
      __sio_reloc_field(siop->enabled, SIO_EV_PARITY_ERR, SIO_EV_PARITY_ERR_POS,
                        SERCOM_USART_INT_INTENSET_ERROR_Pos) |
      __sio_reloc_field(siop->enabled, SIO_EV_FRAMING_ERR,
                        SIO_EV_FRAMING_ERR_POS,
                        SERCOM_USART_INT_INTENSET_ERROR_Pos);
  siop->usart->SERCOM_INTENSET = intenset;
}

static inline void usart_enable_rx_irq(SIODriver* siop) {
  if ((siop->enabled & SIO_EV_RXNOTEMPY) != 0U) {
    siop->usart->SERCOM_INTENSET |= SERCOM_USART_INT_INTENSET_RXC_Msk;
  }
}

static inline void usart_enable_tx_irq(SIODriver* siop) {
  if ((siop->enabled & SIO_EV_TXNOTFULL) != 0U) {
    siop->usart->SERCOM_INTENSET |= SERCOM_USART_INT_INTENSET_DRE_Msk;
  }
}

static inline void usart_enable_tx_end_irq(SIODriver* siop) {
  if ((siop->enabled & SIO_EV_TXDONE) != 0U) {
    siop->usart->SERCOM_INTENSET |= SERCOM_USART_INT_INTENSET_TXC_Msk;
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(SAMD21_MCUCONF)
#include "hal_sio_lld_samd2x.inc"
#elif defined(SAME54_MCUCONF)
#include "hal_sio_lld_same5x.inc"
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Enable flags change notification.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 */
void sio_lld_update_enable_flags(SIODriver* siop) {
  uint8_t intenset;

  // osalDbgAssert((siop->enabled & SIO_EV_RXIDLE) == 0U, "unsupported event");

  intenset =
      __sio_reloc_field(siop->enabled, SIO_EV_RXNOTEMPY, SIO_EV_RXNOTEMPY_POS,
                        SERCOM_USART_INT_INTENSET_RXC_Pos) |
      __sio_reloc_field(siop->enabled, SIO_EV_TXNOTFULL, SIO_EV_TXNOTFULL_POS,
                        SERCOM_USART_INT_INTENSET_DRE_Pos) |
      __sio_reloc_field(siop->enabled, SIO_EV_OVERRUN_ERR,
                        SIO_EV_OVERRUN_ERR_POS,
                        SERCOM_USART_INT_INTENSET_ERROR_Pos) |
      __sio_reloc_field(siop->enabled, SIO_EV_RXBREAK, SIO_EV_RXBREAK_POS,
                        SERCOM_USART_INT_INTENSET_RXBRK_Pos) |
      __sio_reloc_field(siop->enabled, SIO_EV_PARITY_ERR, SIO_EV_PARITY_ERR_POS,
                        SERCOM_USART_INT_INTENSET_ERROR_Pos) |
      __sio_reloc_field(siop->enabled, SIO_EV_FRAMING_ERR,
                        SIO_EV_FRAMING_ERR_POS,
                        SERCOM_USART_INT_INTENSET_ERROR_Pos) |
      __sio_reloc_field(siop->enabled, SIO_EV_TXDONE, SIO_EV_TXDONE_POS,
                        SERCOM_USART_INT_INTENSET_TXC_Pos);

  /* Setting up the operation.*/
  siop->usart->SERCOM_INTENSET = intenset;
}

/**
 * @brief   Get and clears SIO error event flags.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The pending event flags.
 *
 * @notapi
 */
sioevents_t sio_lld_get_and_clear_errors(SIODriver* siop) {
  sioevents_t errors = 0U;
  uint8_t status = 0;
  uint8_t irq_status = 0;
  status = (uint8_t)(siop->usart->SERCOM_STATUS);
  irq_status = (uint8_t)(siop->usart->SERCOM_INTFLAG);
  siop->usart->SERCOM_STATUS |= SERCOM_USART_INT_STATUS_BUFOVF_Msk |
                                SERCOM_USART_INT_STATUS_FERR_Msk |
                                SERCOM_USART_INT_STATUS_PERR_Msk;
  siop->usart->SERCOM_INTFLAG |= SERCOM_USART_INT_INTFLAG_RXBRK_Msk;
  errors = __sio_reloc_field(irq_status, SERCOM_USART_INT_INTFLAG_RXBRK_Msk,
                             SERCOM_USART_INT_INTFLAG_RXBRK_Pos,
                             SIO_EV_RXBREAK_POS) |
           __sio_reloc_field(status, SERCOM_USART_INT_STATUS_BUFOVF_Msk,
                             SERCOM_USART_INT_STATUS_BUFOVF_Pos,
                             SIO_EV_OVERRUN_ERR_POS) |
           __sio_reloc_field(status, SERCOM_USART_INT_STATUS_FERR_Msk,
                             SERCOM_USART_INT_STATUS_FERR_Pos,
                             SIO_EV_FRAMING_ERR_POS) |
           __sio_reloc_field(status, SERCOM_USART_INT_STATUS_PERR_Msk,
                             SERCOM_USART_INT_STATUS_PERR_Pos,
                             SIO_EV_PARITY_ERR_POS);

  return errors;
}

/**
 * @brief   Get and clears SIO event flags.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The pending event flags.
 *
 * @notapi
 */
sioevents_t sio_lld_get_and_clear_events(SIODriver* siop) {
  sioevents_t events = 0U;
  uint8_t status = 0;
  uint8_t irq_status = 0;
  status = (uint8_t)(siop->usart->SERCOM_STATUS);
  irq_status = (uint8_t)(siop->usart->SERCOM_INTFLAG);
  // clear both status and intflag
  siop->usart->SERCOM_STATUS = SERCOM_USART_INT_STATUS_Msk;
  siop->usart->SERCOM_INTFLAG = SERCOM_USART_INT_INTFLAG_Msk;
  events |=
      __sio_reloc_field(irq_status, SERCOM_USART_INT_INTFLAG_RXC_Msk,
                        SERCOM_USART_INT_INTFLAG_RXC_Pos,
                        SIO_EV_RXNOTEMPY_POS) |
      __sio_reloc_field(irq_status, SERCOM_USART_INT_INTFLAG_DRE_Msk,
                        SERCOM_USART_INT_INTFLAG_DRE_Pos,
                        SIO_EV_TXNOTFULL_POS) |
      __sio_reloc_field(irq_status, SERCOM_USART_INT_INTFLAG_TXC_Msk,
                        SERCOM_USART_INT_INTFLAG_TXC_Pos, SIO_EV_TXDONE_POS) |
      __sio_reloc_field(irq_status, SERCOM_USART_INT_INTFLAG_RXBRK_Msk,
                        SERCOM_USART_INT_INTFLAG_RXBRK_Pos,
                        SIO_EV_RXBREAK_POS) |
      __sio_reloc_field(status, SERCOM_USART_INT_STATUS_BUFOVF_Msk,
                        SERCOM_USART_INT_STATUS_BUFOVF_Pos,
                        SIO_EV_OVERRUN_ERR_POS) |
      __sio_reloc_field(status, SERCOM_USART_INT_STATUS_FERR_Msk,
                        SERCOM_USART_INT_STATUS_FERR_Pos,
                        SIO_EV_FRAMING_ERR_POS) |
      __sio_reloc_field(status, SERCOM_USART_INT_STATUS_PERR_Msk,
                        SERCOM_USART_INT_STATUS_PERR_Pos,
                        SIO_EV_PARITY_ERR_POS);

  return events;
}

/**
 * @brief   Returns the pending SIO event flags.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The pending event flags.
 *
 * @notapi
 */

sioevents_t sio_lld_get_events(SIODriver* siop) {
  sioevents_t events = 0U;
  uint8_t status = 0;
  uint8_t irq_status = 0;
  status = (uint8_t)(siop->usart->SERCOM_STATUS);
  irq_status = (uint8_t)(siop->usart->SERCOM_INTFLAG);
  events |=
      __sio_reloc_field(irq_status, SERCOM_USART_INT_INTFLAG_RXC_Msk,
                        SERCOM_USART_INT_INTFLAG_RXC_Pos,
                        SIO_EV_RXNOTEMPY_POS) |
      __sio_reloc_field(irq_status, SERCOM_USART_INT_INTFLAG_DRE_Msk,
                        SERCOM_USART_INT_INTFLAG_DRE_Pos,
                        SIO_EV_TXNOTFULL_POS) |
      __sio_reloc_field(irq_status, SERCOM_USART_INT_INTFLAG_TXC_Msk,
                        SERCOM_USART_INT_INTFLAG_TXC_Pos, SIO_EV_TXDONE_POS) |
      __sio_reloc_field(irq_status, SERCOM_USART_INT_INTFLAG_RXBRK_Msk,
                        SERCOM_USART_INT_INTFLAG_RXBRK_Pos,
                        SIO_EV_RXBREAK_POS) |
      __sio_reloc_field(status, SERCOM_USART_INT_STATUS_BUFOVF_Msk,
                        SERCOM_USART_INT_STATUS_BUFOVF_Pos,
                        SIO_EV_OVERRUN_ERR_POS) |
      __sio_reloc_field(status, SERCOM_USART_INT_STATUS_FERR_Msk,
                        SERCOM_USART_INT_STATUS_FERR_Pos,
                        SIO_EV_FRAMING_ERR_POS) |
      __sio_reloc_field(status, SERCOM_USART_INT_STATUS_PERR_Msk,
                        SERCOM_USART_INT_STATUS_PERR_Pos,
                        SIO_EV_PARITY_ERR_POS);
  return events;
}

/**
 * @brief   Reads data from the RX FIFO.
 * @details The function is not blocking, it writes frames until there
 *          is space available without waiting.
 *
 * @param[in] siop          pointer to an @p SIODriver structure
 * @param[in] buffer        pointer to the buffer for read frames
 * @param[in] n             maximum number of frames to be read
 * @return                  The number of frames copied from the buffer.
 * @retval 0                if the TX FIFO is full.
 */
size_t sio_lld_read(SIODriver* siop, uint8_t* buffer, size_t n) {

  size_t rd;

  rd = 0U;
  while (true) {

    /* If the RX FIFO has been emptied then the interrupt is enabled again.*/
    if (sio_lld_is_rx_empty(siop)) {
      usart_enable_rx_irq(siop);
      break;
    }

    /* Buffer filled condition.*/
    if (rd > n) {
      break;
    }

    *buffer++ = (uint8_t)siop->usart->SERCOM_DATA;
    rd++;
  }

  return rd;
}

/**
 * @brief   Writes data into the TX FIFO.
 * @details The function is not blocking, it writes frames until there
 *          is space available without waiting.
 *
 * @param[in] siop          pointer to an @p SIODriver structure
 * @param[in] buffer        pointer to the buffer for read frames
 * @param[in] n             maximum number of frames to be written
 * @return                  The number of frames copied from the buffer.
 * @retval 0                if the TX FIFO is full.
 */
size_t sio_lld_write(SIODriver* siop, const uint8_t* buffer, size_t n) {

  size_t wr;

  wr = 0U;
  while (true) {

    /* If the TX FIFO has been filled then the interrupt is enabled again.*/
    if (sio_lld_is_tx_full(siop)) {
      usart_enable_tx_irq(siop);
      break;
    }

    /* Buffer emptied condition.*/
    if (wr >= n) {
      break;
    }
    uint8_t data = *buffer++;
    siop->usart->SERCOM_DATA = data;
    wr++;
  }

  /* The transmit complete interrupt is always re-enabled on write.*/
  usart_enable_tx_end_irq(siop);

  return wr;
}

/**
 * @brief   Returns one frame from the RX FIFO.
 * @note    If the FIFO is empty then the returned value is unpredictable.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The frame from RX FIFO.
 *
 * @notapi
 */
msg_t sio_lld_get(SIODriver* siop) {
  msg_t msg;

  msg = (uint8_t)(siop->usart->SERCOM_DATA);

  /* If the RX FIFO has been emptied then the interrupt is enabled again.*/
  if (sio_lld_is_rx_empty(siop)) {
    usart_enable_rx_irq(siop);
  }

  return msg;
}

/**
 * @brief   Pushes one frame into the TX FIFO.
 * @note    If the FIFO is full then the behavior is unpredictable.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @param[in] data      frame to be written
 *
 * @notapi
 */
void sio_lld_put(SIODriver* siop, uint_fast16_t data) {

  siop->usart->SERCOM_DATA = (uint8_t)data;

  /* If the TX FIFO has been filled then the interrupt is enabled again.*/
  if (sio_lld_is_tx_full(siop)) {
    usart_enable_tx_irq(siop);
  }

  /* The transmit complete interrupt is always re-enabled on write.*/
  usart_enable_tx_end_irq(siop);
}

/**
 * @brief   Control operation on a serial port.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @param[in] operation control operation code
 * @param[in,out] arg   operation argument
 *
 * @return              The control operation status.
 * @retval MSG_OK       in case of success.
 * @retval MSG_TIMEOUT  in case of operation timeout.
 * @retval MSG_RESET    in case of operation reset.
 *
 * @notapi
 */
msg_t sio_lld_control(SIODriver* siop, unsigned int operation, void* arg) {

  (void)siop;
  (void)operation;
  (void)arg;

  return MSG_OK;
}

/**
 * @brief   Serves an UART interrupt.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 *
 * @notapi
 */
void sio_lld_serve_interrupt(SIODriver* siop) {
  osalDbgAssert(siop->state == SIO_READY, "invalid state");
  uint8_t intflag = siop->usart->SERCOM_INTFLAG;
  uint8_t intenclr = 0;
  uint8_t evtmask = intflag & (SERCOM_USART_INT_INTFLAG_ERROR_Msk |
                               SERCOM_USART_INT_INTFLAG_RXBRK_Msk);
  siop->usart->SERCOM_INTFLAG = SERCOM_USART_INT_INTFLAG_Msk;
  if (evtmask != 0) {
    __sio_wakeup_errors(siop);
    intenclr |= (SERCOM_USART_INT_INTENCLR_ERROR_Msk |
                 SERCOM_USART_INT_INTENCLR_RXBRK_Msk);
  }
  if (intflag & SERCOM_USART_INT_INTFLAG_RXC_Msk) {
    __sio_wakeup_rx(siop);

    /* Called once then the interrupt source is disabled.*/
    intenclr |= SERCOM_USART_INT_INTENCLR_RXC_Msk;
  }
  /* TX FIFO is non-full.*/
  if (intflag & SERCOM_USART_INT_INTFLAG_DRE_Msk) {

    /* Waiting thread woken, if any.*/
    __sio_wakeup_tx(siop);

    /* Called once then the interrupt is disabled.*/
    intenclr |= SERCOM_USART_INT_INTENCLR_DRE_Msk;
  }

  /* Physical transmission end.*/
  if (intflag & SERCOM_USART_INT_INTFLAG_TXC_Msk) {

    /* Waiting thread woken, if any.*/
    __sio_wakeup_txend(siop);

    /* Called once then the interrupt is disabled.*/
    intenclr |= SERCOM_USART_INT_INTENCLR_TXC_Msk;
  }
  siop->usart->SERCOM_INTENCLR = intenclr;
  __sio_callback(siop);
}

#endif /* HAL_USE_SIO == TRUE */

/** @} */
