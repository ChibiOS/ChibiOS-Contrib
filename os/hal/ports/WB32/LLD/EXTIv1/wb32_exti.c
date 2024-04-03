/*
    Copyright (C) 2023 Westberry Technology Corp., Ltd

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
 * @file    EXTIv1/WB32_exti.c
 * @brief   EXTI helper driver code.
 *
 * @addtogroup WB32_EXTI
 * @details EXTI sharing helper driver.
 * @{
 */

#include "hal.h"

/* The following macro is only defined if some driver requiring EXTI services
   has been enabled.*/
#if defined(WB32_EXTI_REQUIRED) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

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
 * @brief   WB32 EXTI group 1 lines initialization.
 *
 * @param[in] mask      mask of group 1 lines to be initialized
 * @param[in] mode      initialization mode
 *
 * @api
 */
void extiEnable(uint32_t mask, extimode_t mode) {
  uint32_t cmask;
  /* Enable EXTI clock.*/
  rccEnableEXTI();

  /* Mask including only configurable lines.*/
  cmask = mask & ~WB32_EXTI_IMR1_MASK;

  if ((mode & EXTI_MODE_EDGES_MASK) == 0U) {
    /* Disabling channels.*/
    EXTI->IMR  &= ~mask;
    EXTI->EMR  &= ~mask;
    EXTI->RTSR &= ~cmask;
    EXTI->FTSR &= ~cmask;
    EXTI->PR   =  cmask;
  } else {
    /* Programming edge registers.*/
    if (mode & EXTI_MODE_RISING_EDGE) {
      EXTI->RTSR |= cmask;
    }
    else {
      EXTI->RTSR &= ~cmask;
    }
    if (mode & EXTI_MODE_FALLING_EDGE) {
      EXTI->FTSR |= cmask;
    }
    else {
      EXTI->FTSR &= ~cmask;
    }

    /* Programming interrupt and event registers.*/
    if ((mode & EXTI_MODE_ACTION_MASK) == EXTI_MODE_ACTION_INTERRUPT) {
      EXTI->IMR |= mask;
      EXTI->EMR &= ~mask;
    }
    else {
      EXTI->EMR |= mask;
      EXTI->IMR &= ~mask;
    }
  }
  
  if ((!EXTI->IMR) && (!EXTI->EMR)) {
    /* Disable EXTI clock.*/
    rccDisableEXTI();
  }
}

/**
 * @brief   WB32 EXTI line initialization.
 *
 * @param[in] line      line to be initialized
 * @param[in] mode      initialization mode
 *
 * @api
 */
void extiEnableLine(extiline_t line, extimode_t mode) {
  uint32_t mask = (1U << (line & 0x1FU));

  osalDbgCheck(line < WB32_EXTI_NUM_LINES);
  osalDbgCheck((mode & ~EXTI_MODE_MASK) == 0U);

  extiEnable(mask, mode);
}

/**
 * @brief   WB32 EXTI line IRQ status clearing.
 *
 * @param[in] line      line to be initialized
 *
 * @api
 */
void extiClearLine(extiline_t line) {
  uint32_t mask = (1U << (line & 0x1FU));

  osalDbgCheck(line < WB32_EXTI_NUM_LINES);

  extiClear(mask);
}

#endif /* WB32_EXTI_REQUIRED */

/** @} */
