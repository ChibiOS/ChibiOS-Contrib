/*
    Copyright (C) 2024 Dimitris Mantzouranis

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
 * @file    UART/hal_uart_lld.c
 * @brief   SN32 low level UART driver code.
 *
 * @addtogroup UART
 * @{
 */

#include "hal.h"

#if HAL_USE_UART || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief UART0 UART driver identifier.*/
#if SN32_UART_USE_UART0 || defined(__DOXYGEN__)
UARTDriver UARTD0;
#endif

/** @brief UART1 UART driver identifier.*/
#if SN32_UART_USE_UART1 || defined(__DOXYGEN__)
UARTDriver UARTD1;
#endif

/** @brief UART2 UART driver identifier.*/
#if SN32_UART_USE_UART2 || defined(__DOXYGEN__)
UARTDriver UARTD2;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Status bits translation.
 *
 * @param[in] ls        UART LS register value
 *
 * @return  The error flags.
 */
static uartflags_t translate_errors(uint32_t ls) {
  uartflags_t sts = 0;

  if (ls & UART_LineStatus_OE)
    sts |= UART_OVERRUN_ERROR;
  if (ls & UART_LineStatus_PE)
    sts |= UART_PARITY_ERROR;
  if (ls & UART_LineStatus_FE)
    sts |= UART_FRAMING_ERROR;
  if (ls & UART_LineStatus_BI)
    sts |= UART_BREAK_DETECTED;
  if (ls & UART_LineStatus_RDR)
    sts |= UART_NOISE_ERROR;
  return sts;
}

/**
 * @brief   Puts the receiver in the UART_RX_IDLE state.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 */
static void uart_enter_rx_idle_loop(UARTDriver *uartp) {

  uartp->xfer.rx_len = 1;
  uartp->xfer.rx_buf = (uint8_t *)&uartp->rxbuf;

  uartp->uart->IE |= UART_ReceiveDataAvailable;
}

/**
 * @brief   UART de-initialization.
 * @details This function must be invoked with interrupts disabled.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 */
static void uart_stop(UARTDriver *uartp) {

  /* Disable the UART Interrupt.*/
  uartp->uart->IE &= ~(0x7FF);
}

/**
 * @brief   UART initialization.
 * @details This function must be invoked with interrupts disabled.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 */
static void uart_start(UARTDriver *uartp) {
  uint32_t divider, apbclock;
  uint8_t dlm, dll, divaddval, mulval, oversampling;
  sn32_uart_t *u = uartp->uart;

  uart_stop(uartp);

  u->ABCTRL = uartp->config->UART_AutoBaudControl;

  apbclock = SN32_HCLK;

  // Default to oversampling by 16
  oversampling = (config->UART_Oversampling == UART_Oversample_8) ? 8 : 16;

  // Check constraints based on oversampling value
  if (oversampling == 8) {
      chDbgAssert(oversampling * uartp->config->UART_BaudRate <= apbclock / 8,
                  "Invalid oversampling configuration for requested baud rate");
  } else if (oversampling == 16) {
      chDbgAssert(oversampling * uartp->config->UART_BaudRate <= apbclock / 16,
                  "Invalid oversampling configuration for requested baud rate");
  }

  // Calculate divider
  uint32_t rounded_sum = apbclock + (uartp->config->UART_BaudRate >> 1);
  divider = rounded_sum / (uartp->config->UART_BaudRate * oversampling);

  // Calculate DLM and DLL
  dlm = (uint8_t)(divider >> 8);
  dll = (uint8_t)(divider & 0xFF);

  // Calculate fractional part
  uint32_t fractional_part = (rounded_sum % (uartp->config->UART_BaudRate *
         oversampling)) * (uartp->config->UART_WordLength + 1) * oversampling;

  // Calculate DIVADDVAL and MULVAL
  divaddval = (uint8_t)((fractional_part >> 4) & 0x0F);
  mulval = (uint8_t)(fractional_part & 0x0F);

  // Check and adjust DLL value if needed
  if (divaddval > 0 && dlm == 0 && dll < 3) {
      dll = 3;  // Set to the minimum value
  }

  // Check and adjust MULVAL if needed
  if (mulval - divaddval == 2) {
      mulval++;  // Adjust mulval to satisfy the condition
  }

  // Update the registers
  u->LC = UART_Divisor_Latch_Access_Enable;
  u->LC |= (config->UART_WordLength
          | config->UART_StopBits
          | config->UART_Parity
          | UART_Break_Control_Disable);

  u->FD_b.MULVAL = mulval;
  u->FD_b.DIVADDVAL = divaddval;
  u->FD_b.OVER8 = (oversampling == 8) ? 1 : 0;
  u->DLM = dlm;
  u->DLL = dll;

  u->LC &= ~(UART_Divisor_Latch_Access_Enable);
  // Configure full or half duplex mode
  u->HDEN = config->UART_HalfDuplexMode;

  // Set RX trigger level
  u->FIFOCTRL |= uartp->config->UART_FIFOControl;

  // AutoBaud reset and init
  u->ABCTRL |= (UART_AutoBaudControl_Timeout | UART_AutoBaudControl_Timeout |
                  UART_AutoBaudControl_Restart | UART_AutoBaudControl_Start);

  // Reset FIFO and enable
  u->FIFOCTRL |= (UART_TxFIFO_Reset | UART_RxFIFO_Reset | UART_FIFO_Enable);

  // Enable AutoBaud Interrupts
  u->IE |= (UART_AutoBaudTimeout | UART_AutoBaudEnd);

  // Enable UART
  u->CTRL = (UART_TxEnable | UART_RxEnable | UART_Enable);

  /* Starting the receiver idle loop.*/
  uart_enter_rx_idle_loop(uartp);
}

/**
 * @brief   UART common service routine.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 */
static void serve_uart_irq(UARTDriver *uartp) {
  sn32_uart_t *u = uartp->uart;
  uint32_t ls;
  uint8_t rbyte;
  uint32_t int_ii;

  int_ii = u->II;
  // Check for pending interrupts
  while((int_ii & UART_Interrupt_Status) == UART_Interrupt_Pending) {
    // Check INTID
    switch ((int_ii>>1) & UART_InterruptID_Status) {
      case UART_InterruptID_RLS:
        ls = (uint32_t)u->LS;
        if (ls & (UART_LineStatus_PE | UART_LineStatus_FE | UART_LineStatus_OE |
                  UART_LineStatus_RDR | UART_LineStatus_BI)) {
          _uart_rx_error_isr_code(uartp, translate_errors(ls));
        }
        break;
      case UART_InterruptID_RDA:
        /* Receive One Byte.*/
        rbyte = (uint16_t)u->RB;
        if (uartp->xfer.rx_len) {
          *uartp->xfer.rx_buf = rbyte;
          uartp->xfer.rx_buf++;
          uartp->xfer.rx_len--;
          if (uartp->xfer.rx_len == 0) {
            if (uartp->rxstate == UART_RX_IDLE) {
              /* Receiver in idle state, a callback is generated, if enabled,
                 for each received character and then the driver stays in the
                 same state.*/
              _uart_rx_idle_code(uartp);
            }
            else {
              _uart_rx_complete_isr_code(uartp);
            }
          }
        }
        break;
      case UART_InterruptID_CTI:
        /* FIFO Time out.*/
        while ((u->LS & UART_LineStatus_RDR) == UART_LineStatus_RDR) {
          rbyte = (uint16_t)u->RB;
          if (uartp->xfer.rx_len) {
            *uartp->xfer.rx_buf = rbyte;
            uartp->xfer.rx_buf++;
            uartp->xfer.rx_len--;
            if (uartp->xfer.rx_len == 0) {
              if (uartp->rxstate == UART_RX_IDLE) {
                /* Receiver in idle state, a callback is generated,
                   if enabled, for each received character and then the
                   driver stays in the same state.*/
                _uart_rx_idle_code(uartp);
              }
              else {
                _uart_rx_complete_isr_code(uartp);
              }
            }
          }
        }
        /* Timeout interrupt sources are only checked if enabled in IE.*/
        _uart_timeout_isr_code(uartp);
        break;
      case UART_InterruptID_THRE:
        /* Send One Byte.*/
        if (uartp->xfer.tx_len) {
          u->TH = (uint16_t)*uartp->xfer.tx_buf;
          uartp->xfer.tx_buf++;
          uartp->xfer.tx_len--;
          if (uartp->xfer.tx_len == 0) {
            /* A callback is generated, if enabled, after a completed
               transfer.*/
            _uart_tx1_isr_code(uartp);
            /* End of transmission, a callback is generated.*/
            _uart_tx2_isr_code(uartp);
            /* Disable tx interrupt.*/
            u->IE &= ~UART_TransmitterHoldingEmpty;
          }
        }
        break;
      case UART_InterruptID_TEMT:
        /* Physical transmission end.*/
        /* A callback is generated, if enabled, after a completed
           transfer.*/
        _uart_tx1_isr_code(uartp);
        /* End of transmission, a callback is generated.*/
        _uart_tx2_isr_code(uartp);
        break;
      default:
        break;
    }
    // Update II status
    int_ii = u->II;
  }
  // AutoBaud interrupts
  if ((int_ii & UART_AutoBaudEnd) == UART_InterruptEnable)
    u->ABCTRL |= UART_AutoBaudControl_End;
  else if((int_ii & UART_AutoBaudTimeout) == UART_InterruptEnable)
    u->ABCTRL |= UART_AutoBaudControl_Timeout;
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if SN32_UART_USE_UART0 || defined(__DOXYGEN__)
#if !defined(SN32_UART0_HANDLER)
#error "SN32_UART0_HANDLER not defined"
#endif
/**
 * @brief   UART0 IRQ handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SN32_UART0_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  serve_uart_irq(&UARTD0);

  OSAL_IRQ_EPILOGUE();
}
#endif /* SN32_UART_USE_UART0 */

#if SN32_UART_USE_UART1 || defined(__DOXYGEN__)
#if !defined(SN32_UART1_HANDLER)
#error "SN32_UART0_HANDLER not defined"
#endif
/**
 * @brief   UART1 IRQ handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SN32_UART1_IRQ_VECTOR) {

  OSAL_IRQ_PROLOGUE();

  serve_uart_irq(&UARTD1);

  OSAL_IRQ_EPILOGUE();
}
#endif /* SN32_UART_USE_UART1 */

#if SN32_UART_USE_UART2 || defined(__DOXYGEN__)
#if !defined(SN32_UART2_HANDLER)
#error "SN32_UART2_HANDLER not defined"
#endif
/**
 * @brief   UART2 IRQ handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SN32_UART2_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  serve_uart_irq(&UARTD2);

  OSAL_IRQ_EPILOGUE();
}
#endif /* SN32_UART_USE_UART2 */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level UART driver initialization.
 *
 * @notapi
 */
void uart_lld_init(void) {

#if SN32_UART_USE_UART0
  uartObjectInit(&UARTD0);
  UARTD0.uart = SN32_UART0;
#endif

#if SN32_UART_USE_UART1
  uartObjectInit(&UARTD1);
  UARTD1.uart = SN32_UART1;
#endif

#if SN32_UART_USE_UART2
  uartObjectInit(&UARTD2);
  UARTD2.uart = SN32_UART2;
#endif
}

/**
 * @brief   Configures and activates the UART peripheral.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 *
 * @notapi
 */
void uart_lld_start(UARTDriver *uartp) {

  if (uartp->state == UART_STOP) {
#if SN32_UART_USE_UART0
    if (&UARTD0 == uartp) {
      /* UART0 clock enable.*/
      sys1EnableUART0();
      nvicClearPending(SN32_UART0_NUMBER);
      nvicEnableVector(SN32_UART0_NUMBER, SN32_UART_UART0_IRQ_PRIORITY);
    }
#endif

#if SN32_UART_USE_UART1
    if (&UARTD1 == uartp) {
      /* UART1 clock enable.*/
      sys1EnableUART1();
      nvicClearPending(SN32_UART1_NUMBER);
      nvicEnableVector(SN32_UART1_NUMBER, SN32_UART_UART1_IRQ_PRIORITY);
    }
#endif

#if SN32_UART_USE_UART2
    if (&UARTD2 == uartp) {
      /* UART2 clock enable.*/
      sys1EnableUART2();
      nvicClearPending(SN32_UART2_NUMBER);
      nvicEnableVector(SN32_UART2_NUMBER, SN32_UART_UART2_IRQ_PRIORITY);
    }
#endif
  }
  uartp->rxstate = UART_RX_IDLE;
  uartp->txstate = UART_TX_IDLE;
  uart_start(uartp);
}

/**
 * @brief   Deactivates the UART peripheral.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 *
 * @notapi
 */
void uart_lld_stop(UARTDriver *uartp) {

  if (uartp->state == UART_READY) {
    uartp->xfer.tx_len = 0;
    uartp->xfer.rx_len = 0;
    uartp->xfer.tx_buf = NULL;
    uartp->xfer.rx_buf = NULL;
    uartp->xfer.tx_abrt_source = 0;

    uart_stop(uartp);

#if SN32_UART_USE_UART0
    if (&UARTD0 == uartp) {
      nvicDisableVector(SN32_UART0_NUMBER);
      sys1DisableUART0();
      return;
    }
#endif

#if SN32_UART_USE_UART1
    if (&UARTD1 == uartp) {
      nvicDisableVector(SN32_UART1_NUMBER);
      sys1DisableUART1();
      return;
    }
#endif

#if SN32_UART_USE_UART2
    if (&UARTD2 == uartp) {
      nvicDisableVector(SN32_UART2_NUMBER);
      sys1DisableUART2();
      return;
    }
#endif
  }
}

/**
 * @brief   Starts a transmission on the UART peripheral.
 * @note    The buffers are organized as uint8_t arrays for data sizes below
 *          or equal to 8 bits else it is organized as uint16_t arrays.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 * @param[in] n         number of data frames to send
 * @param[in] txbuf     the pointer to the transmit buffer
 *
 * @notapi
 */
void uart_lld_start_send(UARTDriver *uartp, size_t n, const void *txbuf) {

  uartp->xfer.tx_len = n;
  uartp->xfer.tx_buf = txbuf;

  uartp->uart->IE |= UART_TransmitterHoldingEmpty;
}

/**
 * @brief   Stops any ongoing transmission.
 * @note    Stopping a transmission also suppresses the transmission callbacks.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 *
 * @return              The number of data frames not transmitted by the
 *                      stopped transmit operation.
 *
 * @notapi
 */
size_t uart_lld_stop_send(UARTDriver *uartp) {

  uartp->uart->IE &= ~(UART_TransmitterHoldingEmpty);

  return (size_t)(uartp->xfer.tx_len);
}

/**
 * @brief   Starts a receive operation on the UART peripheral.
 * @note    The buffers are organized as uint8_t arrays for data sizes below
 *          or equal to 8 bits else it is organized as uint16_t arrays.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 * @param[in] n         number of data frames to send
 * @param[out] rxbuf    the pointer to the receive buffer
 *
 * @notapi
 */
void uart_lld_start_receive(UARTDriver *uartp, size_t n, void *rxbuf) {

  uartp->xfer.rx_len = n;
  uartp->xfer.rx_buf = rxbuf;

  uartp->uart->IE |= UART_ReceiveDataAvailable;
}

/**
 * @brief   Stops any ongoing receive operation.
 * @note    Stopping a receive operation also suppresses the receive callbacks.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 *
 * @return              The number of data frames not received by the
 *                      stopped receive operation.
 *
 * @notapi
 */
size_t uart_lld_stop_receive(UARTDriver *uartp) {
  uartp->uart->IE &= ~(UART_ReceiveDataAvailable);

  return (size_t)(uartp->xfer.rx_len);
}

#endif /* HAL_USE_UART */

/** @} */