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
 * @file    TMRv1/at32_tmr20.inc
 * @brief   Shared TMR20 handler.
 *
 * @addtogroup AT32_TMR20_HANDLER
 * @{
 */

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Registry checks for robustness.*/
#if !defined(AT32_HAS_TMR20)
#error "AT32_HAS_TMR20 not defined in registry"
#endif

/* Driver checks for robustness, undefined USE macros are defaulted to
   FALSE. This makes this module independent from drivers implementation.*/
#if !defined(AT32_GPT_USE_TMR20)
#define AT32_GPT_USE_TMR20                  FALSE
#endif
#if !defined(AT32_ICU_USE_TMR20)
#define AT32_ICU_USE_TMR20                  FALSE
#endif
#if !defined(AT32_PWM_USE_TMR20)
#define AT32_PWM_USE_TMR20                  FALSE
#endif
#if !defined(AT32_ST_USE_TMR20)
#define AT32_ST_USE_TMR20                   FALSE
#endif

#if AT32_HAS_TMR20

/* Priority settings checks.*/
#if !defined(AT32_IRQ_TMR20_BRK_PRIORITY)
#error "AT32_IRQ_TMR20_BRK_PRIORITY not defined in mcuconf.h"
#endif

#if !defined(AT32_IRQ_TMR20_OVF_PRIORITY)
#error "AT32_IRQ_TMR20_OVF_PRIORITY not defined in mcuconf.h"
#endif

#if !defined(AT32_IRQ_TMR20_TRG_HALL_PRIORITY)
#error "AT32_IRQ_TMR20_TRG_HALL_PRIORITY not defined in mcuconf.h"
#endif

#if !defined(AT32_IRQ_TMR20_CH_PRIORITY)
#error "AT32_IRQ_TMR20_CH_PRIORITY not defined in mcuconf.h"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TMR20_BRK_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TMR20_BRK_PRIORITY"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TMR20_OVF_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TMR20_OVF_PRIORITY"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TMR20_TRG_HALL_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TMR20_TRG_HALL_PRIORITY"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TMR20_CH_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TMR20_CH_PRIORITY"
#endif

#endif /* AT32_HAS_TMR20 */

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline void tmr20_irq_init(void) {
#if defined(AT32_TMR20_IS_USED)
  nvicEnableVector(AT32_TMR20_BRK_NUMBER,
                   AT32_IRQ_TMR20_BRK_PRIORITY);
  nvicEnableVector(AT32_TMR20_OVF_NUMBER,
                   AT32_IRQ_TMR20_OVF_PRIORITY);
  nvicEnableVector(AT32_TMR20_TRG_HALL_NUMBER,
                   AT32_IRQ_TMR20_TRG_HALL_PRIORITY);
  nvicEnableVector(AT32_TMR20_CH_NUMBER,
                   AT32_IRQ_TMR20_CH_PRIORITY);
#endif
}

static inline void tmr20_irq_deinit(void) {
#if defined(AT32_TMR20_IS_USED)
  nvicDisableVector(AT32_TMR20_BRK_NUMBER);
  nvicDisableVector(AT32_TMR20_OVF_NUMBER);
  nvicDisableVector(AT32_TMR20_TRG_HALL_NUMBER);
  nvicDisableVector(AT32_TMR20_CH_NUMBER);
#endif
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(AT32_TMR20_IS_USED) || defined(__DOXYGEN__)
/**
 * @brief   TMR20-BRK interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR20_BRK_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  OSAL_IRQ_EPILOGUE();
}
#endif

#if defined(AT32_TMR20_IS_USED) || defined(__DOXYGEN__)
/**
 * @brief   TMR20-OVF interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR20_OVF_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
#if AT32_GPT_USE_TMR20
  gpt_lld_serve_interrupt(&GPTD8);
#endif
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TMR20
  icu_lld_serve_interrupt(&ICUD8);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TMR20
  pwm_lld_serve_interrupt(&PWMD8);
#endif
#endif
#if 1
#if AT32_ST_USE_TMR20
  st_lld_serve_interrupt();
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

#if defined(AT32_TMR20_IS_USED) || defined(__DOXYGEN__)
/**
 * @brief   TMR20-TRG-HALL interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR20_TRG_HALL_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  OSAL_IRQ_EPILOGUE();
}
#endif

#if defined(AT32_TMR20_IS_USED) || defined(__DOXYGEN__)
/**
 * @brief   TMR20-CH interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR20_CH_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
  /* Not used by GPT.*/
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TMR20
  icu_lld_serve_interrupt(&ICUD8);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TMR20
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
