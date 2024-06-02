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
 * @file    TMRv1/at32_tmr1_9_10_11.inc
 * @brief   Shared TMR1, TMR9, TMR10, TMR11 handler.
 *
 * @addtogroup AT32_TMR1_TMR9_TMR10_TMR11_HANDLER
 * @{
 */

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Registry checks for robustness.*/
#if !defined(AT32_HAS_TMR1)
#error "AT32_HAS_TMR1 not defined in registry"
#endif

#if !defined(AT32_HAS_TMR9)
#error "AT32_HAS_TMR9 not defined in registry"
#endif

#if !defined(AT32_HAS_TMR10)
#error "AT32_HAS_TMR10 not defined in registry"
#endif

#if !defined(AT32_HAS_TMR11)
#error "AT32_HAS_TMR11 not defined in registry"
#endif

/* Driver checks for robustness, undefined USE macros are defaulted to
   FALSE. This makes this module independent from drivers implementation.*/
#if !defined(AT32_GPT_USE_TMR1)
#define AT32_GPT_USE_TMR1                   FALSE
#endif
#if !defined(AT32_ICU_USE_TMR1)
#define AT32_ICU_USE_TMR1                   FALSE
#endif
#if !defined(AT32_PWM_USE_TMR1)
#define AT32_PWM_USE_TMR1                   FALSE
#endif
#if !defined(AT32_ST_USE_TMR1)
#define AT32_ST_USE_TMR1                    FALSE
#endif

#if !defined(AT32_GPT_USE_TMR9)
#define AT32_GPT_USE_TMR9                   FALSE
#endif
#if !defined(AT32_ICU_USE_TMR9)
#define AT32_ICU_USE_TMR9                   FALSE
#endif
#if !defined(AT32_PWM_USE_TMR9)
#define AT32_PWM_USE_TMR9                   FALSE
#endif
#if !defined(AT32_ST_USE_TMR9)
#define AT32_ST_USE_TMR9                    FALSE
#endif

#if !defined(AT32_GPT_USE_TMR10)
#define AT32_GPT_USE_TMR10                  FALSE
#endif
#if !defined(AT32_ICU_USE_TMR10)
#define AT32_ICU_USE_TMR10                  FALSE
#endif
#if !defined(AT32_PWM_USE_TMR10)
#define AT32_PWM_USE_TMR10                  FALSE
#endif
#if !defined(AT32_ST_USE_TMR10)
#define AT32_ST_USE_TMR10                   FALSE
#endif

#if !defined(AT32_GPT_USE_TMR11)
#define AT32_GPT_USE_TMR11                  FALSE
#endif
#if !defined(AT32_ICU_USE_TMR11)
#define AT32_ICU_USE_TMR11                  FALSE
#endif
#if !defined(AT32_PWM_USE_TMR11)
#define AT32_PWM_USE_TMR11                  FALSE
#endif
#if !defined(AT32_ST_USE_TMR11)
#define AT32_ST_USE_TMR11                   FALSE
#endif

#if AT32_HAS_TMR1 || AT32_HAS_TMR9 || AT32_HAS_TMR10 || AT32_HAS_TMR11

/* Priority settings checks.*/
#if !defined(AT32_IRQ_TMR1_BRK_TMR9_PRIORITY)
#error "AT32_IRQ_TMR1_BRK_TMR9_PRIORITY not defined in mcuconf.h"
#endif

#if !defined(AT32_IRQ_TMR1_OVF_TMR10_PRIORITY)
#error "AT32_IRQ_TMR1_OVF_TMR10_PRIORITY not defined in mcuconf.h"
#endif

#if !defined(AT32_IRQ_TMR1_HALL_TMR11_PRIORITY)
#error "AT32_IRQ_TMR1_HALL_TMR11_PRIORITY not defined in mcuconf.h"
#endif

#if !defined(AT32_IRQ_TMR1_CH_PRIORITY)
#error "AT32_IRQ_TMR1_CH_PRIORITY not defined in mcuconf.h"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TMR1_BRK_TMR9_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TMR1_BRK_TMR9_PRIORITY"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TMR1_OVF_TMR10_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TMR1_OVF_TMR10_PRIORITY"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TMR1_HALL_TMR11_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TMR1_HALL_TMR11_PRIORITY"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TMR1_CH_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TMR1_CH_PRIORITY"
#endif

#endif /* AT32_HAS_TMR1 || AT32_HAS_TMR9 || AT32_HAS_TMR10 || AT32_HAS_TMR11 */

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline void tmr1_tmr9_tmr10_tmr11_irq_init(void) {
#if defined(AT32_TMR1_IS_USED) || defined(AT32_TMR9_IS_USED)
  nvicEnableVector(AT32_TMR1_BRK_TMR9_NUMBER,
                   AT32_IRQ_TMR1_BRK_TMR9_PRIORITY);
#endif
#if defined(AT32_TMR1_IS_USED) || defined(AT32_TMR10_IS_USED)
  nvicEnableVector(AT32_TMR1_OVF_TMR10_NUMBER,
                   AT32_IRQ_TMR1_OVF_TMR10_PRIORITY);
#endif
#if defined(AT32_TMR1_IS_USED) || defined(AT32_TMR11_IS_USED)
  nvicEnableVector(AT32_TMR1_HALL_TMR11_NUMBER,
                   AT32_IRQ_TMR1_HALL_TMR11_PRIORITY);
#endif
#if defined(AT32_TMR1_IS_USED)
  nvicEnableVector(AT32_TMR1_CH_NUMBER,
                   AT32_IRQ_TMR1_CH_PRIORITY);
#endif
}

static inline void tmr1_tmr9_tmr10_tmr11_irq_deinit(void) {
#if defined(AT32_TMR1_IS_USED) || defined(AT32_TMR9_IS_USED)
  nvicDisableVector(AT32_TMR1_BRK_TMR9_NUMBER);
#endif
#if defined(AT32_TMR1_IS_USED) || defined(AT32_TMR10_IS_USED)
  nvicDisableVector(AT32_TMR1_OVF_TMR10_NUMBER);
#endif
#if defined(AT32_TMR1_IS_USED) || defined(AT32_TMR11_IS_USED)
  nvicDisableVector(AT32_TMR1_HALL_TMR11_NUMBER);
#endif
#if defined(AT32_TMR1_IS_USED)
  nvicDisableVector(AT32_TMR1_CH_NUMBER);
#endif
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(AT32_TMR1_IS_USED) || defined(AT32_TMR9_IS_USED)  ||          \
    defined(__DOXYGEN__)
/**
 * @brief   TMR1-BRK, TMR9 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR1_BRK_TMR9_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
#if AT32_GPT_USE_TMR9
  gpt_lld_serve_interrupt(&GPTD9);
#endif
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TMR9
  icu_lld_serve_interrupt(&ICUD9);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TMR9
  pwm_lld_serve_interrupt(&PWMD9);
#endif
#endif
#if 1
#if AT32_ST_USE_TMR9
  st_lld_serve_interrupt();
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

#if defined(AT32_TMR1_IS_USED) || defined(AT32_TMR10_IS_USED)  ||         \
    defined(__DOXYGEN__)
/**
 * @brief   TMR1-OVF, TMR10 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR1_OVF_TMR10_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
#if AT32_GPT_USE_TMR1
  gpt_lld_serve_interrupt(&GPTD1);
#endif
#if AT32_GPT_USE_TMR10
  gpt_lld_serve_interrupt(&GPTD10);
#endif
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TMR1
  icu_lld_serve_interrupt(&ICUD1);
#endif
#if AT32_ICU_USE_TMR10
  icu_lld_serve_interrupt(&ICUD10);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TMR1
  pwm_lld_serve_interrupt(&PWMD1);
#endif
#if AT32_PWM_USE_TMR10
  pwm_lld_serve_interrupt(&PWMD10);
#endif
#endif
#if 1
#if AT32_ST_USE_TMR1
  st_lld_serve_interrupt();
#endif
#if AT32_ST_USE_TMR10
  st_lld_serve_interrupt();
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

#if defined(AT32_TMR1_IS_USED) || defined(AT32_TMR11_IS_USED)  ||         \
    defined(__DOXYGEN__)
/**
 * @brief   TMR1-TRG-HALL, TMR11 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR1_HALL_TMR11_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
#if AT32_GPT_USE_TMR11
  gpt_lld_serve_interrupt(&GPTD11);
#endif
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TMR11
  icu_lld_serve_interrupt(&ICUD11);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TMR11
  pwm_lld_serve_interrupt(&PWMD11);
#endif
#endif
#if 1
#if AT32_ST_USE_TMR11
  st_lld_serve_interrupt();
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

#if defined(AT32_TMR1_IS_USED)
/**
 * @brief   TMR1-CH interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR1_CH_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
  /* Not used by GPT.*/
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TMR1
  icu_lld_serve_interrupt(&ICUD1);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TMR1
  pwm_lld_serve_interrupt(&PWMD1);
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/** @} */
