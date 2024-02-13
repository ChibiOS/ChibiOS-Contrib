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
 * @file    TMRv1/at32_tmr4.inc
 * @brief   Shared TMR4 handler.
 *
 * @addtogroup AT32_TMR4_HANDLER
 * @{
 */

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Registry checks for robustness.*/
#if !defined(AT32_HAS_TMR4)
#error "AT32_HAS_TMR4 not defined in registry"
#endif

/* Driver checks for robustness, undefined USE macros are defaulted to
   FALSE. This makes this module independent from drivers implementation.*/
#if !defined(AT32_GPT_USE_TMR4)
#define AT32_GPT_USE_TMR4                   FALSE
#endif
#if !defined(AT32_ICU_USE_TMR4)
#define AT32_ICU_USE_TMR4                   FALSE
#endif
#if !defined(AT32_PWM_USE_TMR4)
#define AT32_PWM_USE_TMR4                   FALSE
#endif
#if !defined(AT32_ST_USE_TMR4)
#define AT32_ST_USE_TMR4                    FALSE
#endif

#if AT32_HAS_TMR4

/* Priority settings checks.*/
#if !defined(AT32_IRQ_TMR4_PRIORITY)
#error "AT32_IRQ_TMR4_PRIORITY not defined in mcuconf.h"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TMR4_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TMR4_PRIORITY"
#endif

#endif /* AT32_HAS_TMR4 */

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline void tmr4_irq_init(void) {
#if defined(AT32_TMR4_IS_USED)
  nvicEnableVector(AT32_TMR4_NUMBER, AT32_IRQ_TMR4_PRIORITY);
#endif
}

static inline void tmr4_irq_deinit(void) {
#if defined(AT32_TMR4_IS_USED)
  nvicDisableVector(AT32_TMR4_NUMBER);
#endif
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(AT32_TMR4_IS_USED) || defined(__DOXYGEN__)
/**
 * @brief   TMR4 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR4_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
#if AT32_GPT_USE_TMR4
  gpt_lld_serve_interrupt(&GPTD4);
#endif
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TMR4
  icu_lld_serve_interrupt(&ICUD4);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TMR4
  pwm_lld_serve_interrupt(&PWMD4);
#endif
#endif
#if 1
#if AT32_ST_USE_TMR4
  st_lld_serve_interrupt();
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/** @} */
