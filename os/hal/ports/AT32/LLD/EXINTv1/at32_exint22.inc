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
 * @file    EXINTv1/at32_exint22.inc
 * @brief   Shared EXINT22 handler.
 *
 * @addtogroup AT32_EXINT22_HANDLER
 * @{
 */

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Priority settings checks.*/
#if !defined(AT32_IRQ_EXINT22_PRIORITY)
#error "AT32_IRQ_EXINT22_PRIORITY not defined in mcuconf.h"
#endif

#if !defined(AT32_DISABLE_EXINT22_HANDLER) &&                               \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_EXINT22_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_EXINT22_PRIORITY"
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

static inline void exint22_irq_init(void) {
#if defined(AT32_EXINT22_IS_USED)
  nvicEnableVector(AT32_EXINT22_NUMBER, AT32_IRQ_EXINT22_PRIORITY);
#endif
}

static inline void exint22_irq_deinit(void) {
#if defined(AT32_EXINT22_IS_USED)
  nvicDisableVector(AT32_EXINT22_NUMBER);
#endif
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(AT32_EXINT22_IS_USED) || defined(__DOXYGEN__)
#if !defined(AT32_DISABLE_EXINT22_HANDLER)
/**
 * @brief   EXINT[22] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXINT22_HANDLER) {
  uint32_t intsts;

  OSAL_IRQ_PROLOGUE();

  exintGetAndClearGroup1(1U << 22, intsts);

  /* Could be unused.*/
  (void)intsts;

#if defined(AT32_EXINT22_ISR)
  AT32_EXINT22_ISR(intsts, 22);
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/** @} */
