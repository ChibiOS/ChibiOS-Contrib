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
 * @file    EXINTv1/at32_exint10_15.inc
 * @brief   Shared EXINT10_15 handler.
 *
 * @addtogroup AT32_EXINT10_15_HANDLER
 * @{
 */

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Priority settings checks.*/
#if !defined(AT32_IRQ_EXINT10_15_PRIORITY)
#error "AT32_IRQ_EXINT10_15_PRIORITY not defined in mcuconf.h"
#endif

#if !defined(AT32_DISABLE_EXINT10_15_HANDLER) &&                            \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_EXINT10_15_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_EXINT10_15_PRIORITY"
#endif

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline void exint10_15_irq_init(void) {
#if (HAL_USE_PAL && (PAL_USE_WAIT || PAL_USE_CALLBACKS))
  nvicEnableVector(AT32_EXINT10_15_NUMBER, AT32_IRQ_EXINT10_15_PRIORITY);
#endif
}

static inline void exint10_15_irq_deinit(void) {
#if (HAL_USE_PAL && (PAL_USE_WAIT || PAL_USE_CALLBACKS))
  nvicDisableVector(AT32_EXINT10_15_NUMBER);
#endif
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if (HAL_USE_PAL && (PAL_USE_WAIT || PAL_USE_CALLBACKS)) || defined(__DOXYGEN__)
#if !defined(AT32_DISABLE_EXINT10_15_HANDLER)
/**
 * @brief   EXINT[10]..EXINT[15] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXINT10_15_HANDLER) {
  uint32_t intsts;

  OSAL_IRQ_PROLOGUE();

  exintGetAndClearGroup1((1U << 10) | (1U << 11) | (1U << 12) | (1U << 13) |
                         (1U << 14) | (1U << 15), intsts);

  exint_serve_irq(intsts, 10);
  exint_serve_irq(intsts, 11);
  exint_serve_irq(intsts, 12);
  exint_serve_irq(intsts, 13);
  exint_serve_irq(intsts, 14);
  exint_serve_irq(intsts, 15);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/** @} */
