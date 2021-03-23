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
 * @file    GD32F1xx/gd32_isr.c
 * @brief   GD32F1xx ISR handler code.
 *
 * @addtogroup GD32F1xx_ISR
 * @{
 */

#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

#define exti_serve_irq(pr, channel)                                            \
  {                                                                            \
                                                                               \
    if ((pr) & (1U << (channel))) {                                            \
      _pal_isr_code(channel);                                                  \
    }                                                                          \
  }

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if (HAL_USE_PAL && (PAL_USE_WAIT || PAL_USE_CALLBACKS)) || defined(__DOXYGEN__)
#if !defined(GD32_DISABLE_EXTI0_HANDLER)
/**
 * @brief   EXTI[0] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(vector25) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXTI->PR;
  pr &= EXTI->IMR & (1U << 0);
  EXTI->PR = pr;

  exti_serve_irq(pr, 0);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(GD32_DISABLE_EXTI1_HANDLER)
/**
 * @brief   EXTI[1] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(vector26) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXTI->PR;
  pr &= EXTI->IMR & (1U << 1);
  EXTI->PR = pr;

  exti_serve_irq(pr, 1);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(GD32_DISABLE_EXTI2_HANDLER)
/**
 * @brief   EXTI[2] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(vector27) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXTI->PR;
  pr &= EXTI->IMR & (1U << 2);
  EXTI->PR = pr;

  exti_serve_irq(pr, 2);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(GD32_DISABLE_EXTI3_HANDLER)
/**
 * @brief   EXTI[3] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(vector28) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXTI->PR;
  pr &= EXTI->IMR & (1U << 3);
  EXTI->PR = pr;

  exti_serve_irq(pr, 3);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(GD32_DISABLE_EXTI4_HANDLER)
/**
 * @brief   EXTI[4] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(vector29) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXTI->PR;
  pr &= EXTI->IMR & (1U << 4);
  EXTI->PR = pr;

  exti_serve_irq(pr, 4);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(GD32_DISABLE_EXTI5_9_HANDLER)
/**
 * @brief   EXTI[5]...EXTI[9] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector9C) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXTI->PR;
  pr &= EXTI->IMR & ((1U << 5) | (1U << 6) | (1U << 7) | (1U << 8) | (1U << 9));
  EXTI->PR = pr;

  exti_serve_irq(pr, 5);
  exti_serve_irq(pr, 6);
  exti_serve_irq(pr, 7);
  exti_serve_irq(pr, 8);
  exti_serve_irq(pr, 9);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(GD32_DISABLE_EXTI10_15_HANDLER)
/**
 * @brief   EXTI[10]...EXTI[15] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(vector59) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXTI->PR;
  pr &= EXTI->IMR & ((1U << 10) | (1U << 11) | (1U << 12) | (1U << 13) |
                     (1U << 14) | (1U << 15));
  EXTI->PR = pr;

  exti_serve_irq(pr, 10);
  exti_serve_irq(pr, 11);
  exti_serve_irq(pr, 12);
  exti_serve_irq(pr, 13);
  exti_serve_irq(pr, 14);
  exti_serve_irq(pr, 15);

  OSAL_IRQ_EPILOGUE();
}
#endif

#endif /* HAL_USE_PAL */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Enables IRQ sources.
 *
 * @notapi
 */
void irqInit(void) {
  /* Disable interrupts during init */
  __disable_irq();

  /* Reset eclic configuration registers */
  ECLIC->CFG = 0;
  ECLIC->MTH = 0;

  /* Reset eclic interrupt registers */
  for (int32_t i = 0; i < SOC_INT_MAX; i++){
    ECLIC->CTRL[0].INTIP = 0;
    ECLIC->CTRL[0].INTIE = 0;
    ECLIC->CTRL[0].INTATTR = 0;
    ECLIC->CTRL[0].INTCTRL = 0;
  }

  /* Set 4 bits for interrupt level and 0 bits for priority */
  __ECLIC_SetCfgNlbits(4);
  
  /* Enable interrupts globaly */
  __enable_irq();

#if HAL_USE_PAL
  eclicEnableVector(EXTI0_IRQn, GD32_IRQ_EXTI0_PRIORITY, GD32_IRQ_EXTI0_TRIGGER);
  eclicEnableVector(EXTI1_IRQn, GD32_IRQ_EXTI1_PRIORITY, GD32_IRQ_EXTI1_TRIGGER);
  eclicEnableVector(EXTI2_IRQn, GD32_IRQ_EXTI2_PRIORITY, GD32_IRQ_EXTI2_TRIGGER);
  eclicEnableVector(EXTI3_IRQn, GD32_IRQ_EXTI3_PRIORITY, GD32_IRQ_EXTI3_TRIGGER);
  eclicEnableVector(EXTI4_IRQn, GD32_IRQ_EXTI4_PRIORITY, GD32_IRQ_EXTI4_TRIGGER);
  eclicEnableVector(EXTI5_9_IRQn, GD32_IRQ_EXTI5_9_PRIORITY, GD32_IRQ_EXTI5_9_TRIGGER);
  eclicEnableVector(EXTI10_15_IRQn, GD32_IRQ_EXTI10_15_PRIORITY, GD32_IRQ_EXTI10_15_TRIGGER);
#endif
}

/**
 * @brief   Disables IRQ sources.
 *
 * @notapi
 */
void irqDeinit(void) {

#if HAL_USE_PAL
  eclicDisableVector(EXTI0_IRQn);
  eclicDisableVector(EXTI1_IRQn);
  eclicDisableVector(EXTI2_IRQn);
  eclicDisableVector(EXTI3_IRQn);
  eclicDisableVector(EXTI4_IRQn);
  eclicDisableVector(EXTI5_9_IRQn);
  eclicDisableVector(EXTI10_15_IRQn);
#endif
}

/** @} */