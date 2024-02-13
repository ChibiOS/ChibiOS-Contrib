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
 * @file    USART/at32_usart3.inc
 * @brief   Shared USART3 handler.
 *
 * @addtogroup AT32_USART3_HANDLER
 * @{
 */

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Registry checks for robustness.*/
#if !defined(AT32_HAS_USART3)
#error "AT32_HAS_USART3 not defined in registry"
#endif

#if AT32_HAS_USART3

/* Priority settings checks.*/
#if !defined(AT32_IRQ_USART3_PRIORITY)
#error "AT32_IRQ_USART3_PRIORITY not defined in mcuconf.h"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_USART3_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_USART3_PRIORITY"
#endif

#endif /* AT32_HAS_USART3 */

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline void usart3_irq_init(void) {
#if defined(AT32_USART3_IS_USED)
  nvicEnableVector(AT32_USART3_NUMBER, AT32_IRQ_USART3_PRIORITY);
#endif
}

static inline void usart3_irq_deinit(void) {
#if defined(AT32_USART3_IS_USED)
  nvicDisableVector(AT32_USART3_NUMBER);
#endif
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(AT32_USART3_IS_USED) || defined(__DOXYGEN__)
/**
 * @brief   USART3 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_USART3_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_SERIAL
#if AT32_SERIAL_USE_USART3
  sd_lld_serve_interrupt(&SD3);
#endif
#endif

#if HAL_USE_UART
#if AT32_UART_USE_USART3
  uart_lld_serve_interrupt(&UARTD3);
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/** @} */
