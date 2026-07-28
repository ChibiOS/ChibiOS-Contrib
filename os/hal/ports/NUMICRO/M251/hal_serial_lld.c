/*
    Copyright (C) 2020 Alex Lewontin
    Modifications copyright (C) 2026 Belonit

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
 * @file    M251/hal_serial_lld.c
 * @brief   M251/M252 Serial subsystem low level driver source.
 *
 * @addtogroup SERIAL
 * @{
 */

#include "hal.h"

#if (HAL_USE_SERIAL == TRUE) || defined(__DOXYGEN__)

#include "M251/stddriver/clk.h"
#include "M251/stddriver/uart.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define M251_UART_FIFO_RESET_MASK         (UART_FIFO_RXRST_Msk |            \
                                           UART_FIFO_TXRST_Msk)
#define M251_UART_ERROR_MASK              (UART_FIFOSTS_BIF_Msk |           \
                                           UART_FIFOSTS_FEF_Msk |           \
                                           UART_FIFOSTS_PEF_Msk |           \
                                           UART_FIFOSTS_RXOVIF_Msk |        \
                                           UART_FIFOSTS_TXOVIF_Msk)
#define M251_UART_RX_IRQ_MASK             (UART_INTEN_RDAIEN_Msk |          \
                                           UART_INTEN_RLSIEN_Msk |          \
                                           UART_INTEN_RXTOIEN_Msk |         \
                                           UART_INTEN_BUFERRIEN_Msk)
#define M251_UART_RX_INT_MASK             (UART_INTSTS_RDAINT_Msk |         \
                                           UART_INTSTS_RXTOINT_Msk)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   SD0 driver identifier.
 */
#if M251_SERIAL_USE_UART0 || defined(__DOXYGEN__)
SerialDriver SD0;
#endif

/**
 * @brief   SD1 driver identifier.
 */
#if M251_SERIAL_USE_UART1 || defined(__DOXYGEN__)
SerialDriver SD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

static const SerialConfig default_config = {
  SERIAL_DEFAULT_BITRATE,
  UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1
};

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void uart_clock_enable(SerialDriver *sdp) {

#if M251_SERIAL_USE_UART0
  if (sdp == &SD0) {
    CLK->CLKSEL1 = (CLK->CLKSEL1 & ~CLK_CLKSEL1_UART0SEL_Msk) |
                   CLK_CLKSEL1_UART0SEL_HIRC;
    CLK->CLKDIV0 = (CLK->CLKDIV0 & ~CLK_CLKDIV0_UART0DIV_Msk) |
                   CLK_CLKDIV0_UART0(1U);
    CLK->APBCLK0 |= CLK_APBCLK0_UART0CKEN_Msk;
    SYS->IPRST1 |= SYS_IPRST1_UART0RST_Msk;
    SYS->IPRST1 &= ~SYS_IPRST1_UART0RST_Msk;
    return;
  }
#endif

#if M251_SERIAL_USE_UART1
  if (sdp == &SD1) {
    CLK->CLKSEL1 = (CLK->CLKSEL1 & ~CLK_CLKSEL1_UART1SEL_Msk) |
                   CLK_CLKSEL1_UART1SEL_HIRC;
    CLK->CLKDIV0 = (CLK->CLKDIV0 & ~CLK_CLKDIV0_UART1DIV_Msk) |
                   CLK_CLKDIV0_UART1(1U);
    CLK->APBCLK0 |= CLK_APBCLK0_UART1CKEN_Msk;
    SYS->IPRST1 |= SYS_IPRST1_UART1RST_Msk;
    SYS->IPRST1 &= ~SYS_IPRST1_UART1RST_Msk;
    return;
  }
#endif
}

static void uart_clock_disable(SerialDriver *sdp) {

#if M251_SERIAL_USE_UART0
  if (sdp == &SD0) {
    CLK->APBCLK0 &= ~CLK_APBCLK0_UART0CKEN_Msk;
    return;
  }
#endif

#if M251_SERIAL_USE_UART1
  if (sdp == &SD1) {
    CLK->APBCLK0 &= ~CLK_APBCLK0_UART1CKEN_Msk;
    return;
  }
#endif
}

static void uart_start(SerialDriver *sdp, const SerialConfig *config) {
  uint32_t brd;
  uint32_t timeout = 0x10000U;

  osalDbgAssert(config->speed > 0U, "invalid UART baud rate");

  brd = UART_BAUD_MODE2_DIVIDER(M251_SERIAL_CLK, config->speed);
  osalDbgAssert(brd <= (UART_BAUD_BRD_Msk >> UART_BAUD_BRD_Pos),
                "invalid UART baud rate");

  sdp->uart->INTEN = 0U;
  sdp->uart->FUNCSEL = UART_FUNCSEL_UART | UART_FUNCSEL_TXRXDIS_Msk;
  sdp->uart->FIFO = M251_UART_FIFO_RESET_MASK;
  while (((sdp->uart->FIFO & M251_UART_FIFO_RESET_MASK) != 0U) &&
         (timeout > 0U)) {
    timeout--;
  }
  if (timeout == 0U) {
    osalSysHalt("UART FIFO reset timeout");
  }

  sdp->uart->LINE = config->line;
  sdp->uart->BAUD = UART_BAUD_MODE2 | brd;
  sdp->uart->FIFO = 0U;
  sdp->uart->FIFOSTS = M251_UART_ERROR_MASK;
  sdp->uart->FUNCSEL = UART_FUNCSEL_UART;
  sdp->uart->INTEN = M251_UART_RX_IRQ_MASK;
}

static void uart_stop(SerialDriver *sdp) {

  sdp->uart->INTEN = 0U;
  sdp->uart->FUNCSEL = UART_FUNCSEL_UART | UART_FUNCSEL_TXRXDIS_Msk;
}

static void set_error(SerialDriver *sdp, uint32_t fifosts) {
  eventflags_t flags = 0;

  if ((fifosts & (UART_FIFOSTS_RXOVIF_Msk | UART_FIFOSTS_TXOVIF_Msk)) != 0U) {
    flags |= SD_OVERRUN_ERROR;
  }
  if ((fifosts & UART_FIFOSTS_PEF_Msk) != 0U) {
    flags |= SD_PARITY_ERROR;
  }
  if ((fifosts & UART_FIFOSTS_FEF_Msk) != 0U) {
    flags |= SD_FRAMING_ERROR;
  }
  if ((fifosts & UART_FIFOSTS_BIF_Msk) != 0U) {
    flags |= SD_BREAK_DETECTED;
  }

  if (flags != 0U) {
    osalSysLockFromISR();
    chnAddFlagsI(sdp, flags);
    osalSysUnlockFromISR();
  }
}

#if M251_SERIAL_USE_UART0 || defined(__DOXYGEN__)
static void notify0(io_queue_t *qp) {

  (void)qp;
  UART0->INTEN |= UART_INTEN_THREIEN_Msk;
}
#endif

#if M251_SERIAL_USE_UART1 || defined(__DOXYGEN__)
static void notify1(io_queue_t *qp) {

  (void)qp;
  UART1->INTEN |= UART_INTEN_THREIEN_Msk;
}
#endif

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if M251_SERIAL_USE_UART0 || defined(__DOXYGEN__)
/**
 * @brief   UART0 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_UART0_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  sd_lld_serve_interrupt(&SD0);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if M251_SERIAL_USE_UART1 || defined(__DOXYGEN__)
/**
 * @brief   UART1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_UART1_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  sd_lld_serve_interrupt(&SD1);

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level serial driver initialization.
 *
 * @notapi
 */
void sd_lld_init(void) {

#if M251_SERIAL_USE_UART0
  sdObjectInit(&SD0, NULL, notify0);
  SD0.uart = UART0;
  nvicEnableVector(M251_UART0_NUMBER, M251_SERIAL_UART0_IRQ_PRIORITY);
#endif

#if M251_SERIAL_USE_UART1
  sdObjectInit(&SD1, NULL, notify1);
  SD1.uart = UART1;
  nvicEnableVector(M251_UART1_NUMBER, M251_SERIAL_UART1_IRQ_PRIORITY);
#endif
}

/**
 * @brief   Configures and activates the serial peripheral.
 *
 * @param[in] sdp       pointer to a @p SerialDriver object
 * @param[in] config    pointer to a @p SerialConfig object or @p NULL
 *
 * @notapi
 */
void sd_lld_start(SerialDriver *sdp, const SerialConfig *config) {

  if (config == NULL) {
    config = &default_config;
  }

  if (sdp->state == SD_STOP) {
    SystemUnlockReg();
    uart_clock_enable(sdp);
    SystemLockReg();
  }

  uart_start(sdp, config);
}

/**
 * @brief   Deactivates the serial peripheral.
 *
 * @param[in] sdp       pointer to a @p SerialDriver object
 *
 * @notapi
 */
void sd_lld_stop(SerialDriver *sdp) {

  if (sdp->state == SD_READY) {
    uart_stop(sdp);
    SystemUnlockReg();
    uart_clock_disable(sdp);
    SystemLockReg();
  }
}

/**
 * @brief   Serves a serial interrupt.
 *
 * @param[in] sdp       pointer to a @p SerialDriver object
 *
 * @notapi
 */
void sd_lld_serve_interrupt(SerialDriver *sdp) {
  uint32_t intsts;
  uint32_t fifosts;

  intsts = sdp->uart->INTSTS;
  fifosts = sdp->uart->FIFOSTS;

  if ((intsts & (UART_INTSTS_RLSINT_Msk | UART_INTSTS_BUFERRINT_Msk |
                 UART_INTSTS_HWRLSINT_Msk | UART_INTSTS_HWBUFEINT_Msk)) != 0U) {
    set_error(sdp, fifosts);
    sdp->uart->FIFOSTS = fifosts & M251_UART_ERROR_MASK;
  }

  if ((intsts & M251_UART_RX_INT_MASK) != 0U) {
    while ((sdp->uart->FIFOSTS & UART_FIFOSTS_RXEMPTY_Msk) == 0U) {
      osalSysLockFromISR();
      sdIncomingDataI(sdp, (uint8_t)sdp->uart->DAT);
      osalSysUnlockFromISR();
    }
  }

  if ((sdp->uart->INTEN & UART_INTEN_THREIEN_Msk) != 0U) {
    while ((sdp->uart->FIFOSTS & UART_FIFOSTS_TXFULL_Msk) == 0U) {
      msg_t b;

      osalSysLockFromISR();
      b = sdRequestDataI(sdp);
      if (b < MSG_OK) {
        sdp->uart->INTEN &= ~UART_INTEN_THREIEN_Msk;
        osalSysUnlockFromISR();
        break;
      }
      osalSysUnlockFromISR();

      sdp->uart->DAT = (uint32_t)b;
    }
  }

  if ((sdp->uart->FIFOSTS & UART_FIFOSTS_TXEMPTYF_Msk) != 0U) {
    osalSysLockFromISR();
    if (oqIsEmptyI(&sdp->oqueue)) {
      chnAddFlagsI(sdp, CHN_TRANSMISSION_END);
    }
    osalSysUnlockFromISR();
  }
}

#endif /* HAL_USE_SERIAL == TRUE */

/** @} */
