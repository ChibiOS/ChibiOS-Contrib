/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian

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
 * @file    USARTv1/hal_uart_lld.c
 * @brief   AT32 low level UART driver code.
 *
 * @addtogroup UART
 * @{
 */

#include "hal.h"

#if HAL_USE_UART || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define AT32_UART_CTRL2_CHECK_MASK                                          \
  (USART_CTRL2_STOPBN_0 | USART_CTRL2_CLKEN | USART_CTRL2_CLKPOL |          \
   USART_CTRL2_CLKPHA | USART_CTRL2_LBCP)

#define AT32_UART_CTRL3_CHECK_MASK                                          \
  (USART_CTRL3_CTSCFIEN | USART_CTRL3_CTSEN | USART_CTRL3_RTSEN |           \
   USART_CTRL3_SCMEN | USART_CTRL3_SCNACKEN)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief USART1 UART driver identifier.*/
#if AT32_UART_USE_USART1 || defined(__DOXYGEN__)
UARTDriver UARTD1;
#endif

/** @brief USART2 UART driver identifier.*/
#if AT32_UART_USE_USART2 || defined(__DOXYGEN__)
UARTDriver UARTD2;
#endif

/** @brief USART3 UART driver identifier.*/
#if AT32_UART_USE_USART3 || defined(__DOXYGEN__)
UARTDriver UARTD3;
#endif

/** @brief UART4 UART driver identifier.*/
#if AT32_UART_USE_UART4 || defined(__DOXYGEN__)
UARTDriver UARTD4;
#endif

/** @brief UART5 UART driver identifier.*/
#if AT32_UART_USE_UART5 || defined(__DOXYGEN__)
UARTDriver UARTD5;
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
 * @param[in] sts       USART STS register value
 *
 * @return  The error flags.
 */
static uartflags_t translate_errors(uint16_t sts) {
  uartflags_t status = 0;

  if (sts & USART_STS_ROERR)
    status |= UART_OVERRUN_ERROR;
  if (sts & USART_STS_PERR)
    status |= UART_PARITY_ERROR;
  if (sts & USART_STS_FERR)
    status |= UART_FRAMING_ERROR;
  if (sts & USART_STS_NERR)
    status |= UART_NOISE_ERROR;
  if (sts & USART_STS_BFF)
    status |= UART_BREAK_DETECTED;
  return status;
}

/**
 * @brief   Puts the receiver in the UART_RX_IDLE state.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 */
static void uart_enter_rx_idle_loop(UARTDriver *uartp) {
  uint32_t mode;

  /* RX DMA channel preparation, if the char callback is defined then the
     FDTIEN interrupt is enabled too.*/
  if (uartp->config->rxchar_cb == NULL)
    mode = AT32_DMA_CCTRL_DTD_P2M | AT32_DMA_CCTRL_LM;
  else
    mode = AT32_DMA_CCTRL_DTD_P2M | AT32_DMA_CCTRL_LM | AT32_DMA_CCTRL_FDTIEN;
  dmaStreamSetMemory0(uartp->dmarx, &uartp->rxbuf);
  dmaStreamSetTransactionSize(uartp->dmarx, 1);
  dmaStreamSetMode(uartp->dmarx, uartp->dmarxmode | mode);
  dmaStreamEnable(uartp->dmarx);
}

/**
 * @brief   USART de-initialization.
 * @details This function must be invoked with interrupts disabled.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 */
static void usart_stop(UARTDriver *uartp) {

  /* Stops RX and TX DMA channels.*/
  dmaStreamDisable(uartp->dmarx);
  dmaStreamDisable(uartp->dmatx);

  /* Stops USART operations.*/
  uartp->usart->CTRL1 = 0;
  uartp->usart->CTRL2 = 0;
  uartp->usart->CTRL3 = 0;
}

/**
 * @brief   USART initialization.
 * @details This function must be invoked with interrupts disabled.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 */
static void usart_start(UARTDriver *uartp) {
  uint32_t baudr;
  uint16_t ctrl1;
  USART_TypeDef *u = uartp->usart;

  /* Defensive programming, starting from a clean state.*/
  usart_stop(uartp);

  /* Baud rate setting.*/
  baudr = (uint32_t)((uartp->clock + uartp->config->speed/2) / uartp->config->speed);

  /* Correcting USARTDIV when oversampling by 8 instead of 16.
     Fraction is still 4 bits wide, but only lower 3 bits used.
     Mantissa is doubled, but Fraction is left the same.*/
#if defined(USART_CTRL1_OVER8)
  if (uartp->config->ctrl1 & USART_CTRL1_OVER8)
    baudr = ((baudr & ~7) * 2) | (baudr & 7);
#endif
  u->BAUDR = baudr;

  /* Resetting eventual pending status flags.*/
  (void)u->STS; /* STS reset step 1.*/
  (void)u->DT;  /* STS reset step 2.*/
  u->STS = 0;

  /* Note that some bits are enforced because required for correct driver
     operations.*/
  u->CTRL2 = uartp->config->ctrl2 | USART_CTRL2_BFIEN;
  u->CTRL3 = uartp->config->ctrl3 | USART_CTRL3_DMATEN | USART_CTRL3_DMAREN |
                                    USART_CTRL3_ERRIEN;

  /* Mustn't ever set FDTIEN here - if done, it causes an immediate
     interrupt.*/
  ctrl1 = USART_CTRL1_UEN | USART_CTRL1_PERRIEN | USART_CTRL1_TEN | USART_CTRL1_REN;
  u->CTRL1 = uartp->config->ctrl1 | ctrl1;

  /* Starting the receiver idle loop.*/
  uart_enter_rx_idle_loop(uartp);
}

/**
 * @brief   RX DMA common service routine.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 * @param[in] flags     pre-shifted content of the ISR register
 */
static void uart_lld_serve_rx_end_irq(UARTDriver *uartp, uint32_t flags) {

  /* DMA errors handling.*/
#if defined(AT32_UART_DMA_ERROR_HOOK)
  if ((flags & AT32_DMA_STS_DTERRF) != 0) {
    AT32_UART_DMA_ERROR_HOOK(uartp);
  }
#else
  (void)flags;
#endif

  if (uartp->rxstate == UART_RX_IDLE) {
    /* Receiver in idle state, a callback is generated, if enabled, for each
       received character and then the driver stays in the same state.*/
    _uart_rx_idle_code(uartp);
  }
  else {
    /* Receiver in active state, a callback is generated, if enabled, after
       a completed transfer.*/
    dmaStreamDisable(uartp->dmarx);
    _uart_rx_complete_isr_code(uartp);
  }
}

/**
 * @brief   TX DMA common service routine.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 * @param[in] flags     pre-shifted content of the ISR register
 */
static void uart_lld_serve_tx_end_irq(UARTDriver *uartp, uint32_t flags) {

  /* DMA errors handling.*/
#if defined(AT32_UART_DMA_ERROR_HOOK)
  if ((flags & AT32_DMA_STS_DTERRF) != 0) {
    AT32_UART_DMA_ERROR_HOOK(uartp);
  }
#else
  (void)flags;
#endif

  dmaStreamDisable(uartp->dmatx);

  /* A callback is generated, if enabled, after a completed transfer.*/
  _uart_tx1_isr_code(uartp);
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if AT32_UART_USE_USART1 || defined(__DOXYGEN__)
#if !defined(AT32_USART1_SUPPRESS_ISR)
#if !defined(AT32_USART1_HANDLER)
#error "AT32_USART1_HANDLER not defined"
#endif
/**
 * @brief   USART1 IRQ handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_USART1_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  uart_lld_serve_interrupt(&UARTD1);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif /* AT32_UART_USE_USART1 */

#if AT32_UART_USE_USART2 || defined(__DOXYGEN__)
#if !defined(AT32_USART2_SUPPRESS_ISR)
#if !defined(AT32_USART2_HANDLER)
#error "AT32_USART2_HANDLER not defined"
#endif
/**
 * @brief   USART2 IRQ handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_USART2_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  uart_lld_serve_interrupt(&UARTD2);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif /* AT32_UART_USE_USART2 */

#if AT32_UART_USE_USART3 || defined(__DOXYGEN__)
#if !defined(AT32_USART3_SUPPRESS_ISR)
#if !defined(AT32_USART3_HANDLER)
#error "AT32_USART3_HANDLER not defined"
#endif
/**
 * @brief   USART3 IRQ handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_USART3_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  uart_lld_serve_interrupt(&UARTD3);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif /* AT32_UART_USE_USART3 */

#if AT32_UART_USE_UART4 || defined(__DOXYGEN__)
#if !defined(AT32_UART4_SUPPRESS_ISR)
#if !defined(AT32_UART4_HANDLER)
#error "AT32_UART4_HANDLER not defined"
#endif
/**
 * @brief   UART4 IRQ handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_UART4_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  uart_lld_serve_interrupt(&UARTD4);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif /* AT32_UART_USE_UART4 */

#if AT32_UART_USE_UART5 || defined(__DOXYGEN__)
#if !defined(AT32_UART5_SUPPRESS_ISR)
#if !defined(AT32_UART5_HANDLER)
#error "AT32_UART5_HANDLER not defined"
#endif
/**
 * @brief   UART5 IRQ handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_UART5_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  uart_lld_serve_interrupt(&UARTD5);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif /* AT32_UART_USE_UART5 */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level UART driver initialization.
 *
 * @notapi
 */
void uart_lld_init(void) {

#if AT32_UART_USE_USART1
  uartObjectInit(&UARTD1);
  UARTD1.usart   = USART1;
  UARTD1.clock   = AT32_PCLK2;
  UARTD1.dmarxmode = AT32_DMA_CCTRL_DTERRIEN;
  UARTD1.dmatxmode = AT32_DMA_CCTRL_DTERRIEN;
  UARTD1.dmarx   = NULL;
  UARTD1.dmatx   = NULL;
#endif

#if AT32_UART_USE_USART2
  uartObjectInit(&UARTD2);
  UARTD2.usart   = USART2;
  UARTD2.clock   = AT32_PCLK1;
  UARTD2.dmarxmode = AT32_DMA_CCTRL_DTERRIEN;
  UARTD2.dmatxmode = AT32_DMA_CCTRL_DTERRIEN;
  UARTD2.dmarx   = NULL;
  UARTD2.dmatx   = NULL;
#endif

#if AT32_UART_USE_USART3
  uartObjectInit(&UARTD3);
  UARTD3.usart   = USART3;
  UARTD3.clock   = AT32_PCLK1;
  UARTD3.dmarxmode = AT32_DMA_CCTRL_DTERRIEN;
  UARTD3.dmatxmode = AT32_DMA_CCTRL_DTERRIEN;
  UARTD3.dmarx   = NULL;
  UARTD3.dmatx   = NULL;
#endif

#if AT32_UART_USE_UART4
  uartObjectInit(&UARTD4);
  UARTD4.usart   = UART4;
  UARTD4.clock   = AT32_PCLK1;
  UARTD4.dmarxmode = AT32_DMA_CCTRL_DTERRIEN;
  UARTD4.dmatxmode = AT32_DMA_CCTRL_DTERRIEN;
  UARTD4.dmarx   = NULL;
  UARTD4.dmatx   = NULL;
#endif

#if AT32_UART_USE_UART5
  uartObjectInit(&UARTD5);
  UARTD5.usart   = UART5;
  UARTD5.clock   = AT32_PCLK1;
  UARTD5.dmarxmode = AT32_DMA_CCTRL_DTERRIEN;
  UARTD5.dmatxmode = AT32_DMA_CCTRL_DTERRIEN;
  UARTD5.dmarx   = NULL;
  UARTD5.dmatx   = NULL;
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
#if AT32_UART_USE_USART1
    if (&UARTD1 == uartp) {
      uartp->dmarx = dmaStreamAllocI(AT32_UART_USART1_RX_DMA_STREAM,
                                     AT32_UART_USART1_IRQ_PRIORITY,
                                     (at32_dmasts_t)uart_lld_serve_rx_end_irq,
                                     (void *)uartp);
      osalDbgAssert(uartp->dmarx != NULL, "unable to allocate stream");
      uartp->dmatx = dmaStreamAllocI(AT32_UART_USART1_TX_DMA_STREAM,
                                     AT32_UART_USART1_IRQ_PRIORITY,
                                     (at32_dmasts_t)uart_lld_serve_tx_end_irq,
                                     (void *)uartp);
      osalDbgAssert(uartp->dmatx != NULL, "unable to allocate stream");

#if AT32_DMA_SUPPORTS_DMAMUX
      dmaSetRequestSource(uartp->dmarx, AT32_UART_USART1_RX_DMAMUX_CHANNEL, AT32_DMAMUX_USART1_RX);
      dmaSetRequestSource(uartp->dmatx, AT32_UART_USART1_TX_DMAMUX_CHANNEL, AT32_DMAMUX_USART1_TX);
#endif

      crmEnableUSART1(true);
      nvicEnableVector(AT32_USART1_NUMBER, AT32_UART_USART1_IRQ_PRIORITY);

      uartp->dmarxmode |= AT32_DMA_CCTRL_CHPL(AT32_UART_USART1_DMA_PRIORITY);
      uartp->dmatxmode |= AT32_DMA_CCTRL_CHPL(AT32_UART_USART1_DMA_PRIORITY);
    }
#endif

#if AT32_UART_USE_USART2
    if (&UARTD2 == uartp) {
      uartp->dmarx = dmaStreamAllocI(AT32_UART_USART2_RX_DMA_STREAM,
                                     AT32_UART_USART2_IRQ_PRIORITY,
                                     (at32_dmasts_t)uart_lld_serve_rx_end_irq,
                                     (void *)uartp);
      osalDbgAssert(uartp->dmarx != NULL, "unable to allocate stream");
      uartp->dmatx = dmaStreamAllocI(AT32_UART_USART2_TX_DMA_STREAM,
                                     AT32_UART_USART2_IRQ_PRIORITY,
                                     (at32_dmasts_t)uart_lld_serve_tx_end_irq,
                                     (void *)uartp);
      osalDbgAssert(uartp->dmatx != NULL, "unable to allocate stream");

#if AT32_DMA_SUPPORTS_DMAMUX
      dmaSetRequestSource(uartp->dmarx, AT32_UART_USART2_RX_DMAMUX_CHANNEL, AT32_DMAMUX_USART2_RX);
      dmaSetRequestSource(uartp->dmatx, AT32_UART_USART2_TX_DMAMUX_CHANNEL, AT32_DMAMUX_USART2_TX);
#endif

      crmEnableUSART2(true);
      nvicEnableVector(AT32_USART2_NUMBER, AT32_UART_USART2_IRQ_PRIORITY);

      uartp->dmarxmode |= AT32_DMA_CCTRL_CHPL(AT32_UART_USART2_DMA_PRIORITY);
      uartp->dmatxmode |= AT32_DMA_CCTRL_CHPL(AT32_UART_USART2_DMA_PRIORITY);
    }
#endif

#if AT32_UART_USE_USART3
    if (&UARTD3 == uartp) {
      uartp->dmarx = dmaStreamAllocI(AT32_UART_USART3_RX_DMA_STREAM,
                                     AT32_UART_USART3_IRQ_PRIORITY,
                                     (at32_dmasts_t)uart_lld_serve_rx_end_irq,
                                     (void *)uartp);
      osalDbgAssert(uartp->dmarx != NULL, "unable to allocate stream");
      uartp->dmatx = dmaStreamAllocI(AT32_UART_USART3_TX_DMA_STREAM,
                                     AT32_UART_USART3_IRQ_PRIORITY,
                                     (at32_dmasts_t)uart_lld_serve_tx_end_irq,
                                     (void *)uartp);
      osalDbgAssert(uartp->dmatx != NULL, "unable to allocate stream");

#if AT32_DMA_SUPPORTS_DMAMUX
      dmaSetRequestSource(uartp->dmarx, AT32_UART_USART3_RX_DMAMUX_CHANNEL, AT32_DMAMUX_USART3_RX);
      dmaSetRequestSource(uartp->dmatx, AT32_UART_USART3_TX_DMAMUX_CHANNEL, AT32_DMAMUX_USART3_TX);
#endif

      crmEnableUSART3(true);
      nvicEnableVector(AT32_USART3_NUMBER, AT32_UART_USART3_IRQ_PRIORITY);

      uartp->dmarxmode |= AT32_DMA_CCTRL_CHPL(AT32_UART_USART3_DMA_PRIORITY);
      uartp->dmatxmode |= AT32_DMA_CCTRL_CHPL(AT32_UART_USART3_DMA_PRIORITY);
    }
#endif

#if AT32_UART_USE_UART4
    if (&UARTD4 == uartp) {

      osalDbgAssert((uartp->config->ctrl2 & AT32_UART_CTRL2_CHECK_MASK) == 0,
                    "specified invalid bits in UART4 CTRL2 register settings");
      osalDbgAssert((uartp->config->ctrl3 & AT32_UART_CTRL3_CHECK_MASK) == 0,
                    "specified invalid bits in UART4 CTRL3 register settings");

      uartp->dmarx = dmaStreamAllocI(AT32_UART_UART4_RX_DMA_STREAM,
                                     AT32_UART_UART4_IRQ_PRIORITY,
                                     (at32_dmasts_t)uart_lld_serve_rx_end_irq,
                                     (void *)uartp);
      osalDbgAssert(uartp->dmarx != NULL, "unable to allocate stream");
      uartp->dmatx = dmaStreamAllocI(AT32_UART_UART4_TX_DMA_STREAM,
                                     AT32_UART_UART4_IRQ_PRIORITY,
                                     (at32_dmasts_t)uart_lld_serve_tx_end_irq,
                                     (void *)uartp);
      osalDbgAssert(uartp->dmatx != NULL, "unable to allocate stream");

#if AT32_DMA_SUPPORTS_DMAMUX
      dmaSetRequestSource(uartp->dmarx, AT32_UART_UART4_RX_DMAMUX_CHANNEL, AT32_DMAMUX_UART4_RX);
      dmaSetRequestSource(uartp->dmatx, AT32_UART_UART4_TX_DMAMUX_CHANNEL, AT32_DMAMUX_UART4_TX);
#endif

      crmEnableUART4(true);
      nvicEnableVector(AT32_UART4_NUMBER, AT32_UART_UART4_IRQ_PRIORITY);

      uartp->dmarxmode |= AT32_DMA_CCTRL_CHPL(AT32_UART_UART4_DMA_PRIORITY);
      uartp->dmatxmode |= AT32_DMA_CCTRL_CHPL(AT32_UART_UART4_DMA_PRIORITY);
    }
#endif

#if AT32_UART_USE_UART5
    if (&UARTD5 == uartp) {

      osalDbgAssert((uartp->config->ctrl2 & AT32_UART_CTRL2_CHECK_MASK) == 0,
                    "specified invalid bits in UART5 CTRL2 register settings");
      osalDbgAssert((uartp->config->ctrl3 & AT32_UART_CTRL3_CHECK_MASK) == 0,
                    "specified invalid bits in UART5 CTRL3 register settings");

      uartp->dmarx = dmaStreamAllocI(AT32_UART_UART5_RX_DMA_STREAM,
                                     AT32_UART_UART5_IRQ_PRIORITY,
                                     (at32_dmasts_t)uart_lld_serve_rx_end_irq,
                                     (void *)uartp);
      osalDbgAssert(uartp->dmarx != NULL, "unable to allocate stream");
      uartp->dmatx = dmaStreamAllocI(AT32_UART_UART5_TX_DMA_STREAM,
                                     AT32_UART_UART5_IRQ_PRIORITY,
                                     (at32_dmasts_t)uart_lld_serve_tx_end_irq,
                                     (void *)uartp);
      osalDbgAssert(uartp->dmatx != NULL, "unable to allocate stream");

#if AT32_DMA_SUPPORTS_DMAMUX
      dmaSetRequestSource(uartp->dmarx, AT32_UART_UART5_RX_DMAMUX_CHANNEL, AT32_DMAMUX_UART5_RX);
      dmaSetRequestSource(uartp->dmatx, AT32_UART_UART5_TX_DMAMUX_CHANNEL, AT32_DMAMUX_UART5_TX);
#endif

      crmEnableUART5(true);
      nvicEnableVector(AT32_UART5_NUMBER, AT32_UART_UART5_IRQ_PRIORITY);

      uartp->dmarxmode |= AT32_DMA_CCTRL_CHPL(AT32_UART_UART5_DMA_PRIORITY);
      uartp->dmatxmode |= AT32_DMA_CCTRL_CHPL(AT32_UART_UART5_DMA_PRIORITY);
    }
#endif

    /* Static DMA setup, the transfer size depends on the USART settings,
       it is 16 bits if M=1 and PEN=0 else it is 8 bits.*/
    if ((uartp->config->ctrl1 & (USART_CTRL1_DBN | USART_CTRL1_PEN)) == USART_CTRL1_DBN) {
      uartp->dmarxmode |= AT32_DMA_CCTRL_PWIDTH_HWORD | AT32_DMA_CCTRL_MWIDTH_HWORD;
      uartp->dmatxmode |= AT32_DMA_CCTRL_PWIDTH_HWORD | AT32_DMA_CCTRL_MWIDTH_HWORD;
    }
    dmaStreamSetPeripheral(uartp->dmarx, &uartp->usart->DT);
    dmaStreamSetPeripheral(uartp->dmatx, &uartp->usart->DT);
    uartp->rxbuf = 0;
  }

  uartp->rxstate = UART_RX_IDLE;
  uartp->txstate = UART_TX_IDLE;
  usart_start(uartp);
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
    usart_stop(uartp);
    dmaStreamFreeI(uartp->dmarx);
    dmaStreamFreeI(uartp->dmatx);
    uartp->dmarx = NULL;
    uartp->dmatx = NULL;

#if AT32_UART_USE_USART1
    if (&UARTD1 == uartp) {
      nvicDisableVector(AT32_USART1_NUMBER);
      crmDisableUSART1();
      return;
    }
#endif

#if AT32_UART_USE_USART2
    if (&UARTD2 == uartp) {
      nvicDisableVector(AT32_USART2_NUMBER);
      crmDisableUSART2();
      return;
    }
#endif

#if AT32_UART_USE_USART3
    if (&UARTD3 == uartp) {
      nvicDisableVector(AT32_USART3_NUMBER);
      crmDisableUSART3();
      return;
    }
#endif

#if AT32_UART_USE_UART4
    if (&UARTD4 == uartp) {
      nvicDisableVector(AT32_UART4_NUMBER);
      crmDisableUART4();
      return;
    }
#endif

#if AT32_UART_USE_UART5
    if (&UARTD5 == uartp) {
      nvicDisableVector(AT32_UART5_NUMBER);
      crmDisableUART5();
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

  /* TX DMA channel preparation.*/
  dmaStreamSetMemory0(uartp->dmatx, txbuf);
  dmaStreamSetTransactionSize(uartp->dmatx, n);
  dmaStreamSetMode(uartp->dmatx, uartp->dmatxmode     | AT32_DMA_CCTRL_DTD_M2P |
                                 AT32_DMA_CCTRL_MINCM | AT32_DMA_CCTRL_FDTIEN);

  /* Only enable TDC interrupt if there's a callback attached to it or
     if called from uartSendFullTimeout(). Also we need to clear TDC flag
     which could be set before.*/
#if UART_USE_WAIT == TRUE
  if ((uartp->config->txend2_cb != NULL) || (uartp->early == false)) {
#else
  if (uartp->config->txend2_cb != NULL) {
#endif
    uartp->usart->STS = ~USART_STS_TDC;
    uartp->usart->CTRL1 |= USART_CTRL1_TDCIEN;
  }

  /* Starting transfer.*/
  dmaStreamEnable(uartp->dmatx);
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

  dmaStreamDisable(uartp->dmatx);

  return dmaStreamGetTransactionSize(uartp->dmatx);
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

  /* Stopping previous activity (idle state).*/
  dmaStreamDisable(uartp->dmarx);

  /* RX DMA channel preparation.*/
  dmaStreamSetMemory0(uartp->dmarx, rxbuf);
  dmaStreamSetTransactionSize(uartp->dmarx, n);
  dmaStreamSetMode(uartp->dmarx, uartp->dmarxmode     | AT32_DMA_CCTRL_DTD_P2M |
                                 AT32_DMA_CCTRL_MINCM | AT32_DMA_CCTRL_FDTIEN);

  /* Starting transfer.*/
  dmaStreamEnable(uartp->dmarx);
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
  size_t n;

  dmaStreamDisable(uartp->dmarx);
  n = dmaStreamGetTransactionSize(uartp->dmarx);
  uart_enter_rx_idle_loop(uartp);

  return n;
}

/**
 * @brief   USART common service routine.
 *
 * @param[in] uartp     pointer to the @p UARTDriver object
 */
void uart_lld_serve_interrupt(UARTDriver *uartp) {
  uint16_t sts;
  USART_TypeDef *u = uartp->usart;
  uint32_t ctrl1 = u->CTRL1;

  sts = u->STS; /* STS reset step 1.*/

  if (sts & (USART_STS_BFF  | USART_STS_ROERR | USART_STS_NERR |
             USART_STS_FERR | USART_STS_PERR)) {

    (void)u->DT;  /* STS reset step 2 - clear ROERR.*/

    u->STS = ~USART_STS_BFF;
    _uart_rx_error_isr_code(uartp, translate_errors(sts));
  }

  if ((sts & USART_STS_TDC) && (ctrl1 & USART_CTRL1_TDCIEN)) {
    /* TDC interrupt cleared and disabled.*/
    u->STS = ~USART_STS_TDC;
    u->CTRL1 = ctrl1 & ~USART_CTRL1_TDCIEN;

    /* End of transmission, a callback is generated.*/
    _uart_tx2_isr_code(uartp);
  }

  /* Timeout interrupt sources are only checked if enabled in CTRL1.*/
  if ((ctrl1 & USART_CTRL1_IDLEIEN) && (sts & USART_STS_IDLEF)) {
    _uart_timeout_isr_code(uartp);
  }
}

#endif /* HAL_USE_UART */

/** @} */
