/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIENS OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    TMRv1/at32_tmr8_12_13_14.inc
 * @brief   Shared TMR8, TMR12, TMR13, TMR14 handler.
 *
 * @addtogroup AT32_TMR8_TMR12_TMR13_TMR14_HANDLER
 * @{
 */

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Registry checks for robustness.*/
#if !defined(AT32_HAS_TMR8)
#error "AT32_HAS_TMR8 not defined in registry"
#endif

#if !defined(AT32_HAS_TMR12)
#error "AT32_HAS_TMR12 not defined in registry"
#endif

#if !defined(AT32_HAS_TMR13)
#error "AT32_HAS_TMR13 not defined in registry"
#endif

#if !defined(AT32_HAS_TMR14)
#error "AT32_HAS_TMR14 not defined in registry"
#endif

/* Driver checks for robustness, undefined USE macros are defaulted to
   FALSE. This makes this module independent from drivers implementation.*/
#if !defined(AT32_GPT_USE_TMR8)
#define AT32_GPT_USE_TMR8                  FALSE
#endif
#if !defined(AT32_ICU_USE_TMR8)
#define AT32_ICU_USE_TMR8                  FALSE
#endif
#if !defined(AT32_PWM_USE_TMR8)
#define AT32_PWM_USE_TMR8                  FALSE
#endif
#if !defined(AT32_ST_USE_TMR8)
#define AT32_ST_USE_TMR8                   FALSE
#endif

#if !defined(AT32_GPT_USE_TMR12)
#define AT32_GPT_USE_TMR12                 FALSE
#endif
#if !defined(AT32_ICU_USE_TMR12)
#define AT32_ICU_USE_TMR12                 FALSE
#endif
#if !defined(AT32_PWM_USE_TMR12)
#define AT32_PWM_USE_TMR12                 FALSE
#endif
#if !defined(AT32_ST_USE_TMR12)
#define AT32_ST_USE_TMR12                  FALSE
#endif

#if !defined(AT32_GPT_USE_TMR13)
#define AT32_GPT_USE_TMR13                 FALSE
#endif
#if !defined(AT32_ICU_USE_TMR13)
#define AT32_ICU_USE_TMR13                 FALSE
#endif
#if !defined(AT32_PWM_USE_TMR13)
#define AT32_PWM_USE_TMR13                 FALSE
#endif
#if !defined(AT32_ST_USE_TMR13)
#define AT32_ST_USE_TMR13                  FALSE
#endif

#if !defined(AT32_GPT_USE_TMR14)
#define AT32_GPT_USE_TMR14                 FALSE
#endif
#if !defined(AT32_ICU_USE_TMR14)
#define AT32_ICU_USE_TMR14                 FALSE
#endif
#if !defined(AT32_PWM_USE_TMR14)
#define AT32_PWM_USE_TMR14                 FALSE
#endif
#if !defined(AT32_ST_USE_TMR14)
#define AT32_ST_USE_TMR14                  FALSE
#endif

#if AT32_HAS_TMR8 || AT32_HAS_TMR12 || AT32_HAS_TMR13 || AT32_HAS_TMR14

/* Priority settings checks.*/
#if !defined(AT32_IRQ_TMR8_BRK_TMR12_PRIORITY)
#error "AT32_IRQ_TMR8_BRK_TMR12_PRIORITY not defined in mcuconf.h"
#endif

#if !defined(AT32_IRQ_TMR8_OVF_TMR13_PRIORITY)
#error "AT32_IRQ_TMR8_OVF_TMR13_PRIORITY not defined in mcuconf.h"
#endif

#if !defined(AT32_IRQ_TMR8_TRG_HALL_TMR14_PRIORITY)
#error "AT32_IRQ_TMR8_TRG_HALL_TMR14_PRIORITY not defined in mcuconf.h"
#endif

#if !defined(AT32_IRQ_TMR8_CH_PRIORITY)
#error "AT32_IRQ_TMR8_CH_PRIORITY not defined in mcuconf.h"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TMR8_BRK_TMR12_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TMR8_BRK_TMR12_PRIORITY"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TMR8_OVF_TMR13_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TMR8_OVF_TMR13_PRIORITY"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TMR8_TRG_HALL_TMR14_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TMR8_TRG_HALL_TMR14_PRIORITY"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TMR8_CH_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TMR8_CH_PRIORITY"
#endif

#endif /* AT32_HAS_TMR8 || AT32_HAS_TMR12 || AT32_HAS_TMR13 || AT32_HAS_TMR14 */

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline void tmr8_tmr12_tmr13_tmr14_irq_init(void) {
#if defined(AT32_TMR8_IS_USED) || defined(AT32_TMR12_IS_USED)
  nvicEnableVector(AT32_TMR8_BRK_TMR12_NUMBER,
                   AT32_IRQ_TMR8_BRK_TMR12_PRIORITY);
#endif
#if defined(AT32_TMR8_IS_USED) || defined(AT32_TMR13_IS_USED)
  nvicEnableVector(AT32_TMR8_OVF_TMR13_NUMBER,
                   AT32_IRQ_TMR8_OVF_TMR13_PRIORITY);
#endif
#if defined(AT32_TMR8_IS_USED) || defined(AT32_TMR14_IS_USED)
  nvicEnableVector(AT32_TMR8_TRG_HALL_TMR14_NUMBER,
                   AT32_IRQ_TMR8_TRG_HALL_TMR14_PRIORITY);
#endif
#if defined(AT32_TMR8_IS_USED)
  nvicEnableVector(AT32_TMR8_CH_NUMBER,
                   AT32_IRQ_TMR8_CH_PRIORITY);
#endif
}

static inline void tmr8_tmr12_tmr13_tmr14_irq_deinit(void) {
#if defined(AT32_TMR8_IS_USED) || defined(AT32_TMR12_IS_USED)
  nvicDisableVector(AT32_TMR8_BRK_TMR12_NUMBER);
#endif
#if defined(AT32_TMR8_IS_USED) || defined(AT32_TMR13_IS_USED)
  nvicDisableVector(AT32_TMR8_OVF_TMR13_NUMBER);
#endif
#if defined(AT32_TMR8_IS_USED) || defined(AT32_TMR14_IS_USED)
  nvicDisableVector(AT32_TMR8_TRG_HALL_TMR14_NUMBER);
#endif
#if defined(AT32_TMR8_IS_USED)
  nvicDisableVector(AT32_TMR8_CH_NUMBER);
#endif
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(AT32_TMR8_IS_USED) || defined(AT32_TMR12_IS_USED)  ||         \
    defined(__DOXYGEN__)
/**
 * @brief   TMR8-BRK, TMR12 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR8_BRK_TMR12_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
#if AT32_GPT_USE_TMR12
  gpt_lld_serve_interrupt(&GPTD12);
#endif
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TMR12
  icu_lld_serve_interrupt(&ICUD12);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TMR12
  pwm_lld_serve_interrupt(&PWMD12);
#endif
#endif
#if 1
#if AT32_ST_USE_TMR12
  st_lld_serve_interrupt();
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

#if defined(AT32_TMR8_IS_USED) || defined(AT32_TMR13_IS_USED)  ||         \
    defined(__DOXYGEN__)
/**
 * @brief   TMR8-OVF, TMR13 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR8_OVF_TMR13_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
#if AT32_GPT_USE_TMR8
  gpt_lld_serve_interrupt(&GPTD8);
#endif
#if AT32_GPT_USE_TMR13
  gpt_lld_serve_interrupt(&GPTD13);
#endif
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TMR8
  icu_lld_serve_interrupt(&ICUD8);
#endif
#if AT32_ICU_USE_TMR13
  icu_lld_serve_interrupt(&ICUD13);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TMR8
  pwm_lld_serve_interrupt(&PWMD8);
#endif
#if AT32_PWM_USE_TMR13
  pwm_lld_serve_interrupt(&PWMD13);
#endif
#endif
#if 1
#if AT32_ST_USE_TMR8
  st_lld_serve_interrupt();
#endif
#if AT32_ST_USE_TMR13
  st_lld_serve_interrupt();
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

#if defined(AT32_TMR8_IS_USED) || defined(AT32_TMR14_IS_USED)  ||         \
    defined(__DOXYGEN__)
/**
 * @brief   TMR8-TRG-HALL, TMR14 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR8_TRG_HALL_TMR14_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
#if AT32_GPT_USE_TMR14
  gpt_lld_serve_interrupt(&GPTD14);
#endif
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TMR14
  icu_lld_serve_interrupt(&ICUD14);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TMR14
  pwm_lld_serve_interrupt(&PWMD14);
#endif
#endif
#if 1
#if AT32_ST_USE_TMR14
  st_lld_serve_interrupt();
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

#if defined(AT32_TMR8_IS_USED) || defined(__DOXYGEN__)
/**
 * @brief   TMR8-CH interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR8_CH_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
  /* Not used by GPT.*/
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TMR8
  icu_lld_serve_interrupt(&ICUD8);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TMR8
  pwm_lld_serve_interrupt(&PWMD8);
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/** @} */
