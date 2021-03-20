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
 * @file    TIM/stm32_tim22.inc
 * @brief   Shared TIM22 handler.
 *
 * @addtogroup GD32_TIM22_HANDLER
 * @{
 */

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Registry checks for robustness.*/
#if !defined(GD32_HAS_TIM22)
#error "GD32_HAS_TIM22 not defined in registry"
#endif

/* Driver checks for robustness, undefined USE macros are defaulted to
   FALSE. This makes this module independent from drivers implementation.*/
#if !defined(GD32_GPT_USE_TIM22)
#define GD32_GPT_USE_TIM22                 FALSE
#endif
#if !defined(GD32_ICU_USE_TIM22)
#define GD32_ICU_USE_TIM22                 FALSE
#endif
#if !defined(GD32_PWM_USE_TIM22)
#define GD32_PWM_USE_TIM22                 FALSE
#endif
#if !defined(GD32_ST_USE_TIM22)
#define GD32_ST_USE_TIM22                  FALSE
#endif

#if GD32_HAS_TIM22

/* Priority settings checks.*/
#if !defined(GD32_IRQ_TIM22_PRIORITY)
#error "GD32_IRQ_TIM22_PRIORITY not defined in mcuconf.h"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(GD32_IRQ_TIM22_PRIORITY)
#error "Invalid IRQ priority assigned to GD32_IRQ_TIM22_PRIORITY"
#endif

#endif /* GD32_HAS_TIM22 */

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline void tim22_irq_init(void) {
#if defined(GD32_TIM22_IS_USED)
  eclicEnableVector(GD32_TIM22_NUMBER, GD32_IRQ_TIM22_PRIORITY, GD32_IRQ_TIM22_TRIGGER);
#endif
}

static inline void tim22_irq_deinit(void) {
#if defined(GD32_TIM22_IS_USED)
  eclicDisableVector(GD32_TIM22_NUMBER);
#endif
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(GD32_TIM22_IS_USED) || defined(__DOXYGEN__)
/**
 * @brief   TIM22 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(GD32_TIM22_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
#if GD32_GPT_USE_TIM22
  gpt_lld_serve_interrupt(&GPTD22);
#endif
#endif
#if HAL_USE_ICU
#if GD32_ICU_USE_TIM22
  icu_lld_serve_interrupt(&ICUD22);
#endif
#endif
#if HAL_USE_PWM
#if GD32_PWM_USE_TIM22
  pwm_lld_serve_interrupt(&PWMD22);
#endif
#endif
#if 1
#if GD32_ST_USE_TIM22
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
