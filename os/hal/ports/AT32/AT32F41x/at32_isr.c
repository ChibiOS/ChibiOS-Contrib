/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023 HorrorTroll
    ChibiOS - Copyright (C) 2023 Zhaqian

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
 * @file    AT32F41x/at32_isr.c
 * @brief   AT32F41x ISR handler code.
 *
 * @addtogroup AT32F41x_ISR
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

#define exint_serve_irq(intsts, channel) {                                  \
                                                                            \
  if ((intsts) & (1U << (channel))) {                                       \
    _pal_isr_code(channel);                                                 \
  }                                                                         \
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if (HAL_USE_PAL && (PAL_USE_WAIT || PAL_USE_CALLBACKS)) || defined(__DOXYGEN__)
#if !defined(AT32_DISABLE_EXINT0_HANDLER)
/**
 * @brief   EXINT[0] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector58) {
  uint32_t intsts;

  OSAL_IRQ_PROLOGUE();

  intsts = EXINT->INTSTS;
  intsts &= EXINT->INTEN & (1U << 0);
  EXINT->INTSTS = intsts;

  exint_serve_irq(intsts, 0);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXINT1_HANDLER)
/**
 * @brief   EXINT[1] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector5C) {
  uint32_t intsts;

  OSAL_IRQ_PROLOGUE();

  intsts = EXINT->INTSTS;
  intsts &= EXINT->INTEN & (1U << 1);
  EXINT->INTSTS = intsts;

  exint_serve_irq(intsts, 1);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXINT2_HANDLER)
/**
 * @brief   EXINT[2] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector60) {
  uint32_t intsts;

  OSAL_IRQ_PROLOGUE();

  intsts = EXINT->INTSTS;
  intsts &= EXINT->INTEN & (1U << 2);
  EXINT->INTSTS = intsts;

  exint_serve_irq(intsts, 2);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXINT3_HANDLER)
/**
 * @brief   EXINT[3] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector64) {
  uint32_t intsts;

  OSAL_IRQ_PROLOGUE();

  intsts = EXINT->INTSTS;
  intsts &= EXINT->INTEN & (1U << 3);
  EXINT->INTSTS = intsts;

  exint_serve_irq(intsts, 3);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXINT4_HANDLER)
/**
 * @brief   EXINT[4] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector68) {
  uint32_t intsts;

  OSAL_IRQ_PROLOGUE();

  intsts = EXINT->INTSTS;
  intsts &= EXINT->INTEN & (1U << 4);
  EXINT->INTSTS = intsts;

  exint_serve_irq(intsts, 4);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXINT5_9_HANDLER)
/**
 * @brief   EXINT[5]...EXINT[9] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector9C) {
  uint32_t intsts;

  OSAL_IRQ_PROLOGUE();

  intsts = EXINT->INTSTS;
  intsts &= EXINT->INTEN & ((1U << 5) | (1U << 6) | (1U << 7) |
                            (1U << 8) | (1U << 9));
  EXINT->INTSTS = intsts;

  exint_serve_irq(intsts, 5);
  exint_serve_irq(intsts, 6);
  exint_serve_irq(intsts, 7);
  exint_serve_irq(intsts, 8);
  exint_serve_irq(intsts, 9);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXINT10_15_HANDLER)
/**
 * @brief   EXINT[10]...EXINT[15] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(VectorE0) {
  uint32_t intsts;

  OSAL_IRQ_PROLOGUE();

  intsts = EXINT->INTSTS;
  intsts &= EXINT->INTEN & ((1U << 10) | (1U << 11) | (1U << 12) |
                            (1U << 13) | (1U << 14) | (1U << 15));
  EXINT->INTSTS = intsts;

  exint_serve_irq(intsts, 10);
  exint_serve_irq(intsts, 11);
  exint_serve_irq(intsts, 12);
  exint_serve_irq(intsts, 13);
  exint_serve_irq(intsts, 14);
  exint_serve_irq(intsts, 15);

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

#if HAL_USE_PAL
  nvicEnableVector(EXINT0_IRQn, AT32_IRQ_EXINT0_PRIORITY);
  nvicEnableVector(EXINT1_IRQn, AT32_IRQ_EXINT1_PRIORITY);
  nvicEnableVector(EXINT2_IRQn, AT32_IRQ_EXINT2_PRIORITY);
  nvicEnableVector(EXINT3_IRQn, AT32_IRQ_EXINT3_PRIORITY);
  nvicEnableVector(EXINT4_IRQn, AT32_IRQ_EXINT4_PRIORITY);
  nvicEnableVector(EXINT9_5_IRQn, AT32_IRQ_EXINT5_9_PRIORITY);
  nvicEnableVector(EXINT15_10_IRQn, AT32_IRQ_EXINT10_15_PRIORITY);
#endif
}

/**
 * @brief   Disables IRQ sources.
 *
 * @notapi
 */
void irqDeinit(void) {

#if HAL_USE_PAL
  nvicDisableVector(EXINT0_IRQn);
  nvicDisableVector(EXINT1_IRQn);
  nvicDisableVector(EXINT2_IRQn);
  nvicDisableVector(EXINT3_IRQn);
  nvicDisableVector(EXINT4_IRQn);
  nvicDisableVector(EXINT9_5_IRQn);
  nvicDisableVector(EXINT15_10_IRQn);
#endif
}

/** @} */
