/*
    ChibiOS - Copyright (C) 2006..2017 Giovanni Di Sirio
              Copyright (C) 2017 Fabien Poussin (fabien.poussin (at) google's mail)

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
 * @file    STM32/hal_comp_lld.c
 * @brief   STM32 Comp subsystem low level driver header.
 *
 * @addtogroup COMP
 * @{
 */

#include "hal.h"

#if HAL_USE_COMP || defined(__DOXYGEN__)

#include "hal_comp.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   COMPD1 driver identifier.
 * @note    The driver COMPD1 allocates the comparator COMP1 when enabled.
 */
#if STM32_COMP_USE_COMP1 || defined(__DOXYGEN__)
COMPDriver COMPD1;
#endif

/**
 * @brief   COMPD2 driver identifier.
 * @note    The driver COMPD2 allocates the comparator COMP2 when enabled.
 */
#if STM32_COMP_USE_COMP2 || defined(__DOXYGEN__)
COMPDriver COMPD2;
#endif

/**
 * @brief   COMPD3 driver identifier.
 * @note    The driver COMPD3 allocates the comparator COMP3 when enabled.
 */
#if STM32_COMP_USE_COMP3 || defined(__DOXYGEN__)
COMPDriver COMPD3;
#endif

/**
 * @brief   COMPD4 driver identifier.
 * @note    The driver COMPD4 allocates the comparator COMP4 when enabled.
 */
#if STM32_COMP_USE_COMP4 || defined(__DOXYGEN__)
COMPDriver COMPD4;
#endif

/**
 * @brief   COMPD5 driver identifier.
 * @note    The driver COMPD5 allocates the comparator COMP5 when enabled.
 */
#if STM32_COMP_USE_COMP5 || defined(__DOXYGEN__)
COMPDriver COMPD5;
#endif

/**
 * @brief   COMPD6 driver identifier.
 * @note    The driver COMPD6 allocates the comparator COMP6 when enabled.
 */
#if STM32_COMP_USE_COMP6 || defined(__DOXYGEN__)
COMPDriver COMPD6;
#endif

/**
 * @brief   COMPD7 driver identifier.
 * @note    The driver COMPD7 allocates the comparator COMP7 when enabled.
 */
#if STM32_COMP_USE_COMP7 || defined(__DOXYGEN__)
COMPDriver COMPD7;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/


/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/


/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level COMP driver initialization.
 *
 * @notapi
 */
void comp_lld_init(void) {

#if STM32_COMP_USE_COMP1
  /* Driver initialization.*/
  compObjectInit(&COMPD1);
  COMPD1.reg = COMP;
  COMPD1.reg->CSR = 0;
#if STM32_COMP_USE_INTERRUPTS
  nvicEnableVector(COMP1_2_3_IRQn, STM32_COMP_1_2_3_IRQ_PRIORITY);
#endif
#endif

#if STM32_COMP_USE_COMP2
  /* Driver initialization.*/
  compObjectInit(&COMPD2);
  COMPD2.reg = COMP2;
  COMPD2.reg->CSR = 0;
#if STM32_COMP_USE_INTERRUPTS
  nvicEnableVector(COMP1_2_3_IRQn, STM32_COMP_1_2_3_IRQ_PRIORITY);
#endif
#endif

#if STM32_COMP_USE_COMP3
  /* Driver initialization.*/
  compObjectInit(&COMPD3);
  COMPD3.reg = COMP3;
  COMPD3.reg->CSR = 0;
#if STM32_COMP_USE_INTERRUPTS
  nvicEnableVector(COMP1_2_3_IRQn, STM32_COMP_1_2_3_IRQ_PRIORITY);
#endif
#endif

#if STM32_COMP_USE_COMP4
  /* Driver initialization.*/
  compObjectInit(&COMPD4);
  COMPD4.reg = COMP4;
  COMPD4.reg->CSR = 0;
#if STM32_COMP_USE_INTERRUPTS
  nvicEnableVector(COMP4_5_6_IRQn, STM32_COMP_1_2_3_IRQ_PRIORITY);
#endif
#endif

#if STM32_COMP_USE_COMP5
  /* Driver initialization.*/
  compObjectInit(&COMPD5);
  COMPD5.reg = COMP5;
  COMPD5.reg->CSR = 0;
#if STM32_COMP_USE_INTERRUPTS
  nvicEnableVector(COMP4_5_6_IRQn, STM32_COMP_1_2_3_IRQ_PRIORITY);
#endif
#endif

#if STM32_COMP_USE_COMP6
  /* Driver initialization.*/
  compObjectInit(&COMPD6);
  COMPD6.reg = COMP6;
  COMPD6.reg->CSR = 0;
#if STM32_COMP_USE_INTERRUPTS
  nvicEnableVector(COMP4_5_6_IRQn, STM32_COMP_1_2_3_IRQ_PRIORITY);
#endif
#endif

#if STM32_COMP_USE_COMP7
  /* Driver initialization.*/
  compObjectInit(&COMPD7);
  COMPD7.reg = COMP7;
  COMPD7.reg->CSR = 0;
#if STM32_COMP_USE_INTERRUPTS
  nvicEnableVector(COMP7_IRQn, STM32_COMP_7_IRQ_PRIORITY);
#endif
#endif

}

/**
 * @brief  COMP1, COMP2, COMP3 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector140) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXTI->PR;
  pr &= EXTI->IMR & ((1U << 21) | (1U << 22) | (1U << 29));
  EXTI->PR = pr;
#if STM32_COMP_USE_COMP1
  if (pr & (1U << 21) && COMPD1.config->cb != NULL)
    COMPD1.config->cb(&COMPD1);
#endif
#if STM32_COMP_USE_COMP2
  if (pr & (1U << 22) && COMPD2.config->cb != NULL)
    COMPD2.config->cb(&COMPD2);
#endif
#if STM32_COMP_USE_COMP3
  if (pr & (1U << 29) && COMPD3.config->cb != NULL)
    COMPD3.config->cb(&COMPD3);
#endif

  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   COMP4, COMP5, COMP6 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector144) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXTI->PR;
  pr &= EXTI->IMR & ((1U << 30) | (1U << 31));
  EXTI->PR = pr;
#if STM32_COMP_USE_COMP4
  if (pr & (1U << 30) && COMPD4.config->cb != NULL)
    COMPD4.config->cb(&COMPD4);
#endif
#if STM32_COMP_USE_COMP5
  if (pr & (1U << 31) && COMPD5.config->cb != NULL)
    COMPD5.config->cb(&COMPD5);
#endif

#if STM32_COMP_USE_COMP6
  pr = EXTI->PR2 & EXTI->IMR2 & (1U << 0);
  EXTI->PR2 = pr;
  if (pr & (1U << 0) && COMPD6.config->cb != NULL)
    COMPD6.config->cb(&COMPD6);
#endif

  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   COMP7 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector148) {
  uint32_t pr2;

  OSAL_IRQ_PROLOGUE();

  pr2 = EXTI->PR2;
  pr2 = EXTI->IMR & (1U << 1);
  EXTI->PR2 = pr2;
#if STM32_COMP_USE_COMP7
  if (pr2 & (1U << 1) && COMPD7.config->cb != NULL)
    COMPD7.config->cb(&COMPD7);
#endif

  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   Configures and activates the COMP peripheral.
 *
 * @param[in] compp      pointer to the @p COMPDriver object
 *
 * @notapi
 */
void comp_lld_start(COMPDriver *compp) {

  // Apply CSR Execpt the enable bit.
  compp->reg->CSR = compp->config->csr & ~COMP_CSR_COMPxEN;

  // Inverted output
  if (compp->config->mode == COMP_OUTPUT_INVERTED)
    compp->reg->CSR |= COMP_CSR_COMPxPOL;

}

/**
 * @brief   Deactivates the comp peripheral.
 *
 * @param[in] compp      pointer to the @p COMPDriver object
 *
 * @notapi
 */
void comp_lld_stop(COMPDriver *compp) {

  if (compp->state == COMP_READY) {

    compp->reg->CSR = 0;
  }
}

/**
 * @brief   Enables the output.
 *
 * @param[in] compp      pointer to the @p COMPDriver object
 *
 * @notapi
 */
void comp_lld_enable(COMPDriver *compp) {

   compp->reg->CSR |= COMP_CSR_COMPxEN; /* Enable */
}

/**
 * @brief   Disables the output.
 *
 * @param[in] compp      pointer to the @p COMPDriver object
 *
 * @notapi
 */
void comp_lld_disable(COMPDriver *compp) {

  compp->reg->CSR &= ~COMP_CSR_COMPxEN; /* Disable */
}

#endif /* HAL_USE_COMP */

/** @} */
