/*
    ChibiOS - Copyright (C) 2024 Xael South

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

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define USART_IEN_CFG_FORBIDDEN             (EUSART_IF_TXFL            | \
                                             EUSART_IF_TXC             | \
                                             EUSART_IF_RXFL            | \
                                             SIO_LLD_ISR_RX_ERRORS)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   SIO1 driver identifier.
 */
#if (EFR32_SIO_USE_EUSART1 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD1;
#endif

/**
 * @brief   SIO2 driver identifier.
 */
#if (EFR32_SIO_USE_EUSART2 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD2;
#endif

/**
 * @brief   SIO3 driver identifier.
 */
#if (EFR32_SIO_USE_EUSART3 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD3;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

__STATIC_INLINE uint32_t _sio_lld_get_clkdiv(uint32_t clock, uint32_t ovs, uint32_t bitrate) {

  uint32_t clkdiv;

  /* Avoid oveflow by mutliply by 32 instead of 256. */
  clkdiv = (32U * clock) / (ovs * bitrate) - 32U;
  clkdiv *= 8;

  return clkdiv;
}

__STATIC_INLINE uint32_t _sio_lld_get_ovs(uint32_t val) {

  switch (val) {
    case 0b000:
      return 16;
    case 0b001:
      return 8;
    case 0b010:
      return 6;
    case 0b011:
      return 4;
    case 0b100:
      return 1;
    default:
      break;
  }

  osalDbgAssert((false), "invalid oversampling value");

  /* Return something that _could_ work in most cases. */
  return 4;
}

__STATIC_INLINE void _sio_lld_reg_masked_write(volatile uint32_t* address,
                                               uint32_t mask,
                                               uint32_t value) {

  *address = (*address & ~mask) | (value & mask);
}


__STATIC_INLINE void _sio_lld_start(SIODriver* siop) {

  EUSART_TypeDef* usart = siop->usart;
  const SIOConfig* config = siop->config;
  uint32_t ovs, clkdiv;

  osalDbgAssert((siop->clock / config->baud >= 3), "invalid baudrate");

  ovs = _sio_lld_get_ovs((config->cfg0 & _EUSART_CFG0_OVS_MASK) >> _EUSART_CFG0_OVS_SHIFT);
  clkdiv = _sio_lld_get_clkdiv(siop->clock, ovs, config->baud);

  osalDbgAssert((clkdiv <= _EUSART_CLKDIV_MASK), "invalid clkdiv");

  _sio_lld_reg_masked_write(&(usart->CFG0), _EUSART_CFG0_MASK, config->cfg0);

  _sio_lld_reg_masked_write(&(usart->FRAMECFG), _EUSART_FRAMECFG_MASK, config->framecfg);

  /* Enable module before writing into CLKDIV register. */
  usart->EN_SET = EUSART_EN_EN;

  _sio_lld_reg_masked_write(&(usart->CLKDIV), _EUSART_CLKDIV_MASK, clkdiv);

  usart->IF_CLR = USART_IEN_CFG_FORBIDDEN;

  usart->CMD_SET = EUSART_CMD_RXEN | EUSART_CMD_TXEN | EUSART_CMD_CLEARTX;
  while ((usart->SYNCBUSY & _EUSART_SYNCBUSY_MASK) != 0U);
}

__STATIC_INLINE void _sio_lld_stop(SIODriver* siop) {

  EUSART_TypeDef* usart = siop->usart;

  usart->CMD_CLR = EUSART_CMD_RXEN | EUSART_CMD_TXEN | EUSART_CMD_CLEARTX;
  while ((usart->SYNCBUSY & _EUSART_SYNCBUSY_MASK) != 0U);

  usart->IF_CLR = USART_IEN_CFG_FORBIDDEN;

  usart->EN_CLR = EUSART_EN_EN;
}

__STATIC_INLINE void usart_enable_rx_irq(SIODriver* siop) {

  if ((siop->enabled & SIO_EV_RXNOTEMPY) != 0U) {
    siop->usart->IEN_SET = EUSART_IEN_RXFL;
  }
}

__STATIC_INLINE void usart_enable_rx_errors_irq(SIODriver* siop) {

  uint32_t ien = 0U;

  ien |= __sio_reloc_field(siop->enabled, SIO_EV_FRAMING_ERR, SIO_EV_FRAMING_ERR_POS, _EUSART_IEN_FERR_SHIFT);
  ien |= __sio_reloc_field(siop->enabled, SIO_EV_PARITY_ERR,  SIO_EV_PARITY_ERR_POS,  _EUSART_IEN_PERR_SHIFT);
  ien |= __sio_reloc_field(siop->enabled, SIO_EV_OVERRUN_ERR, SIO_EV_OVERRUN_ERR_POS, _EUSART_IEN_RXOF_SHIFT);

  /* The following 3 are grouped.*/
  if ((siop->enabled & (SIO_EV_FRAMING_ERR |
                        SIO_EV_PARITY_ERR  |
                        SIO_EV_OVERRUN_ERR)) != 0U) {
    siop->usart->IEN_SET = ien;
  }
}

__STATIC_INLINE void usart_enable_tx_irq(SIODriver* siop) {

  if ((siop->enabled & SIO_EV_TXNOTFULL) != 0U) {
    siop->usart->IEN_SET = EUSART_IEN_TXFL;
  }
}

__STATIC_INLINE void usart_enable_tx_end_irq(SIODriver* siop) {

  if ((siop->enabled & SIO_EV_TXDONE) != 0U) {
    siop->usart->IEN_SET = EUSART_IEN_TXC;
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/
#if (EFR32_SIO_USE_EUSART1 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   EFR32_EUSART1_RX_HANDLER interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(EFR32_EUSART1_RX_HANDLER) {

  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD1);
  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   EFR32_EUSART1_TX_HANDLER interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(EFR32_EUSART1_TX_HANDLER) {

  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD1);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if (EFR32_SIO_USE_EUSART2 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   EFR32_EUSART2_RX_HANDLER interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(EFR32_EUSART2_RX_HANDLER) {

  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD2);
  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   EFR32_EUSART2_TX_HANDLER interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(EFR32_EUSART2_TX_HANDLER) {

  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD2);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if (EFR32_SIO_USE_EUSART3 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   EFR32_EUSART3_RX_HANDLER interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(EFR32_EUSART3_RX_HANDLER) {

  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD3);
  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   EFR32_EUSART3_TX_HANDLER interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(EFR32_EUSART3_TX_HANDLER) {

  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD3);
  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level SIO driver initialization.
 *
 * @notapi
 */
void sio_lld_init(void) {

  /* Driver initialization.*/
#if EFR32_SIO_USE_EUSART1 == TRUE
  sioObjectInit(&SIOD1);
  SIOD1.usart = EUSART0;
  SIOD1.clock = EFR32_EUSART1CLK;
#endif

#if EFR32_SIO_USE_EUSART2 == TRUE
  sioObjectInit(&SIOD2);
  SIOD2.usart = EUSART1;
  SIOD2.clock = EFR32_EUSART23CLK;
#endif

#if EFR32_SIO_USE_EUSART3 == TRUE
  sioObjectInit(&SIOD3);
  SIOD3.usart = EUSART2;
  SIOD3.clock = EFR32_EUSART23CLK;
#endif
}

/**
 * @brief   Configures and activates the SIO peripheral.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The operation status.
 *
 * @notapi
 */
msg_t sio_lld_start(SIODriver* siop) {

  osalDbgAssert((siop->config != NULL), "invalid config");

  if (siop->state == SIO_STOP) {
    /* Enables the peripheral.*/
    /* Configures the peripheral.*/
#if EFR32_SIO_USE_EUSART1 == TRUE
    if (&SIOD1 == siop) {
      CMU->CLKEN1_SET = CMU_CLKEN1_EUSART0;

      _sio_lld_start(siop);

      nvicEnableVector(EFR32_EUSART1_RX_NUMBER, EFR32_EUSART1_RX_IRQ_PRIORITY);
      nvicEnableVector(EFR32_EUSART1_TX_NUMBER, EFR32_EUSART1_TX_IRQ_PRIORITY);
    }
#endif

#if EFR32_SIO_USE_EUSART2 == TRUE
    if (&SIOD2 == siop) {
      CMU->CLKEN1_SET = CMU_CLKEN1_EUSART1;

      _sio_lld_start(siop);

      nvicEnableVector(EFR32_EUSART2_RX_NUMBER, EFR32_EUSART2_RX_IRQ_PRIORITY);
      nvicEnableVector(EFR32_EUSART2_TX_NUMBER, EFR32_EUSART2_TX_IRQ_PRIORITY);
    }
#endif

#if EFR32_SIO_USE_EUSART3 == TRUE
    if (&SIOD3 == siop) {
      CMU->CLKEN1_SET = CMU_CLKEN1_EUSART2;

      _sio_lld_start(siop);

      nvicEnableVector(EFR32_EUSART3_RX_NUMBER, EFR32_EUSART3_RX_IRQ_PRIORITY);
      nvicEnableVector(EFR32_EUSART3_TX_NUMBER, EFR32_EUSART3_TX_IRQ_PRIORITY);
    }
#endif
  }

  return HAL_RET_SUCCESS;
}

/**
 * @brief   Deactivates the SIO peripheral.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 *
 * @notapi
 */
void sio_lld_stop(SIODriver* siop) {

  if (siop->state == SIO_READY) {
    /* Resets the peripheral.*/
    /* Disables the peripheral.*/
#if EFR32_SIO_USE_EUSART1 == TRUE
    if (&SIOD1 == siop) {
      _sio_lld_stop(siop);
      CMU->CLKEN1_CLR = CMU_CLKEN1_EUSART0;
    }
#endif

#if EFR32_SIO_USE_EUSART2 == TRUE
    if (&SIOD2 == siop) {
      _sio_lld_stop(siop);
      CMU->CLKEN1_CLR = CMU_CLKEN1_EUSART1;
    }
#endif

#if EFR32_SIO_USE_EUSART3 == TRUE
    if (&SIOD3 == siop) {
      _sio_lld_stop(siop);
      CMU->CLKEN1_CLR = CMU_CLKEN1_EUSART2;
    }
#endif
  }
}

/**
 * @brief   Enable flags change notification.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 */
void sio_lld_update_enable_flags(SIODriver* siop) {

  uint32_t ien;

  ien = siop->usart->IF & ~(SIO_LLD_ISR_RX_ERRORS |
                            EUSART_IF_RXFL        |
                            EUSART_IF_TXFL        |
                            EUSART_IF_TXC);

  ien |= __sio_reloc_field(siop->enabled, SIO_EV_FRAMING_ERR, SIO_EV_FRAMING_ERR_POS, _EUSART_IEN_FERR_SHIFT);
  ien |= __sio_reloc_field(siop->enabled, SIO_EV_PARITY_ERR,  SIO_EV_PARITY_ERR_POS,  _EUSART_IEN_PERR_SHIFT);
  ien |= __sio_reloc_field(siop->enabled, SIO_EV_OVERRUN_ERR, SIO_EV_OVERRUN_ERR_POS, _EUSART_IEN_RXOF_SHIFT);
  ien |= __sio_reloc_field(siop->enabled, SIO_EV_RXNOTEMPY,   SIO_EV_RXNOTEMPY_POS,   _EUSART_IEN_RXFL_SHIFT);
  ien |= __sio_reloc_field(siop->enabled, SIO_EV_TXNOTFULL,   SIO_EV_TXNOTFULL_POS,   _EUSART_IEN_TXFL_SHIFT);
  ien |= __sio_reloc_field(siop->enabled, SIO_EV_TXDONE,      SIO_EV_TXDONE_POS,      _EUSART_IEN_TXC_SHIFT);

  /* Setting up the operation.*/
  siop->usart->IEN_SET = ien;
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

  uint32_t isr;
  sioevents_t errors;

  /* Getting all error ISR flags (and only those).*/
  isr = siop->usart->IF & (SIO_LLD_ISR_RX_ERRORS);

  /* Clearing captured events.*/
  siop->usart->IF_CLR = isr;

  /* Status flags cleared, now the error-related interrupts can be
     enabled again.*/
  usart_enable_rx_errors_irq(siop);

  /* Translating the status flags in SIO events.*/
  errors = __sio_reloc_field(isr, _EUSART_IF_FERR_MASK, _EUSART_IF_FERR_SHIFT, SIO_EV_FRAMING_ERR_POS) |
           __sio_reloc_field(isr, _EUSART_IF_PERR_MASK, _EUSART_IF_PERR_SHIFT, SIO_EV_PARITY_ERR_POS) |
           __sio_reloc_field(isr, _EUSART_IF_RXOF_MASK, _EUSART_IF_RXOF_SHIFT, SIO_EV_OVERRUN_ERR_POS);

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

  uint32_t isr, status;
  sioevents_t events;

  /* Getting all ISR flags.*/
  isr = siop->usart->IF & (SIO_LLD_ISR_RX_ERRORS |
                           EUSART_IF_RXFL        |
                           EUSART_IF_TXFL        |
                           EUSART_IF_TXC);

  status = siop->usart->STATUS & EUSART_STATUS_RXIDLE;

  /* Clearing captured events.*/
  siop->usart->IF_CLR = isr;

  /* Status flags cleared, now the RX-related interrupts can be
     enabled again.*/
  usart_enable_rx_irq(siop);
  usart_enable_rx_errors_irq(siop);

  /* Translating the status flags in SIO events.*/
  events = __sio_reloc_field(isr, _EUSART_IF_FERR_MASK, _EUSART_IF_FERR_SHIFT, SIO_EV_FRAMING_ERR_POS) |
           __sio_reloc_field(isr, _EUSART_IF_PERR_MASK, _EUSART_IF_PERR_SHIFT, SIO_EV_PARITY_ERR_POS) |
           __sio_reloc_field(isr, _EUSART_IF_RXOF_MASK, _EUSART_IF_RXOF_SHIFT, SIO_EV_OVERRUN_ERR_POS) |
           __sio_reloc_field(isr, _EUSART_IF_RXFL_MASK, _EUSART_IF_RXFL_SHIFT, SIO_EV_RXNOTEMPY_POS) |
           __sio_reloc_field(isr, _EUSART_IF_TXFL_MASK, _EUSART_IF_TXFL_SHIFT, SIO_EV_TXNOTFULL_POS) |
           __sio_reloc_field(isr, _EUSART_IF_TXC_MASK,  _EUSART_IF_TXC_SHIFT,  SIO_EV_TXDONE_POS) |
           __sio_reloc_field(status, _EUSART_STATUS_RXIDLE_MASK, _EUSART_STATUS_RXIDLE_SHIFT, SIO_EV_RXIDLE_POS);

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

  uint32_t isr, status;
  sioevents_t events;

  /* Getting all ISR flags.*/
  isr = siop->usart->IF & (SIO_LLD_ISR_RX_ERRORS |
                           EUSART_IF_RXFL        |
                           EUSART_IF_TXFL        |
                           EUSART_IF_TXC);

  status = siop->usart->STATUS & EUSART_STATUS_RXIDLE;

  /* Translating the status flags in SIO events.*/
  events = __sio_reloc_field(isr, _EUSART_IF_FERR_MASK, _EUSART_IF_FERR_SHIFT, SIO_EV_FRAMING_ERR_POS) |
           __sio_reloc_field(isr, _EUSART_IF_PERR_MASK, _EUSART_IF_PERR_SHIFT, SIO_EV_PARITY_ERR_POS) |
           __sio_reloc_field(isr, _EUSART_IF_RXOF_MASK, _EUSART_IF_RXOF_SHIFT, SIO_EV_OVERRUN_ERR_POS) |
           __sio_reloc_field(isr, _EUSART_IF_RXFL_MASK, _EUSART_IF_RXFL_SHIFT, SIO_EV_RXNOTEMPY_POS) |
           __sio_reloc_field(isr, _EUSART_IF_TXFL_MASK, _EUSART_IF_TXFL_SHIFT, SIO_EV_TXNOTFULL_POS) |
           __sio_reloc_field(isr, _EUSART_IF_TXC_MASK,  _EUSART_IF_TXC_SHIFT,  SIO_EV_TXDONE_POS) |
           __sio_reloc_field(status, _EUSART_STATUS_RXIDLE_MASK, _EUSART_STATUS_RXIDLE_SHIFT, SIO_EV_RXIDLE_POS);

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

    /* If the RX FIFO has been emptied then the RX FIFO and IDLE interrupts
       are enabled again.*/
    if (sio_lld_is_rx_empty(siop)) {
      usart_enable_rx_irq(siop);
      break;
    }

    /* Buffer filled condition.*/
    if (rd >= n) {
      break;
    }

    *buffer++ = (uint8_t)siop->usart->RXDATA;
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

    siop->usart->TXDATA = (uint32_t)*buffer++;
    wr++;
  }

  /* The transmit complete interrupt is always re-enabled on write.*/
  usart_enable_tx_end_irq(siop);

  return wr;
}

/**
 * @brief   Returns one frame from the RX FIFO.
 * @note    If the FIFO is empty then the returned value is MSG_TIMEOUT.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The frame from RX FIFO.
 *
 * @notapi
 */
msg_t sio_lld_get(SIODriver* siop) {

  msg_t msg;

  /* If the RX FIFO has been emptied then the interrupt is enabled again.*/
  if (sio_lld_is_rx_empty(siop)) {
    usart_enable_rx_irq(siop);
    msg = MSG_TIMEOUT;
  } else {
    msg = (msg_t)siop->usart->RXDATA;
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

  siop->usart->TXDATA = data;

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

  EUSART_TypeDef* u = siop->usart;
  sioevents_t events;
  uint32_t ien = u->IEN;

  osalDbgAssert(siop->state == SIO_READY, "invalid state");

  /* Events to be processed.*/
  events = sio_lld_get_events(siop) & siop->enabled;
  if (events != 0U) {

    /* Error events handled as a group.*/
    if ((events & SIO_EV_ALL_ERRORS) != 0U) {

      /* All RX-related interrupt sources disabled.*/
      ien &= ~(EUSART_IEN_RXFL | SIO_LLD_ISR_RX_ERRORS);

      /* Waiting thread woken, if any.*/
      __sio_wakeup_errors(siop);
    }
    /* If there are no errors then we check for the other RX events.*/
    else {
      /* Idle RX event.*/
      if ((events & SIO_EV_RXIDLE) != 0U) {

        /* There is no interrupt source to disable.*/

        /* Waiting thread woken, if any.*/
        __sio_wakeup_rxidle(siop);
      }

      /* RX FIFO is non-empty.*/
      if ((events & SIO_EV_RXNOTEMPY) != 0U) {

        /* Interrupt source disabled.*/
        ien &= ~(EUSART_IEN_RXFL);

        /* Waiting thread woken, if any.*/
        __sio_wakeup_rx(siop);
      }
    }

    /* TX FIFO is non-full.*/
    if ((events & SIO_EV_TXNOTFULL) != 0U) {

      /* Interrupt source disabled.*/
      ien &= ~(EUSART_IEN_TXFL);

      /* Waiting thread woken, if any.*/
      __sio_wakeup_tx(siop);
    }

    /* Physical transmission end.*/
    if ((events & SIO_EV_TXDONE) != 0U) {

      /* Interrupt source disabled.*/
      ien &= ~(EUSART_IEN_TXC);

      /* Waiting thread woken, if any.*/
      __sio_wakeup_txend(siop);
    }

    /* Updating control registers, some sources could have been disabled.*/
    u->IEN = ien;

    /* The callback is invoked.*/
    __sio_callback(siop);
  } else {
//    osalDbgAssert(false, "spurious interrupt");
  }
}

#endif /* HAL_USE_SIO == TRUE */

/** @} */