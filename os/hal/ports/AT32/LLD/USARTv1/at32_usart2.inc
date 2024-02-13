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
 * @file    USART/at32_usart2.inc
 * @brief   Shared USART2 handler.
 *
 * @addtogroup AT32_USART2_HANDLER
 * @{
 */

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Registry checks for robustness.*/
#if !defined(AT32_HAS_USART2)
#error "AT32_HAS_USART2 not defined in registry"
#endif

#if AT32_HAS_USART2

/* Priority settings checks.*/
#if !defined(AT32_IRQ_USART2_PRIORITY)
#error "AT32_IRQ_USART2_PRIORITY not defined in mcuconf.h"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_USART2_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_USART2_PRIORITY"
#endif

#endif /* AT32_HAS_USART2 */

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline void usart2_irq_init(void) {
#if defined(AT32_USART2_IS_USED)
  nvicEnableVector(AT32_USART2_NUMBER, AT32_IRQ_USART2_PRIORITY);
#endif
}

static inline void usart2_irq_deinit(void) {
#if defined(AT32_USART2_IS_USED)
  nvicDisableVector(AT32_USART2_NUMBER);
#endif
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(AT32_USART2_IS_USED) || defined(__DOXYGEN__)
/**
 * @brief   USART2 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_USART2_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_SERIAL
#if AT32_SERIAL_USE_USART2
  sd_lld_serve_interrupt(&SD2);
#endif
#endif

#if HAL_USE_UART
#if AT32_UART_USE_USART2
  uart_lld_serve_interrupt(&UARTD2);
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/** @} */
