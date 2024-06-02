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
 * @file    EXINTv1/at32_exint.c
 * @brief   EXINT helper driver code.
 *
 * @addtogroup AT32_EXINT
 * @details EXINT sharing helper driver.
 * @{
 */

#include "hal.h"

/* The following macro is only defined if some driver requiring EXINT services
   has been enabled.*/
#if defined(AT32_EXINT_REQUIRED) || defined(__DOXYGEN__)

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
 * @brief   AT32 EXINT group 1 lines initialization.
 *
 * @param[in] mask      mask of group 1 lines to be initialized
 * @param[in] mode      initialization mode
 *
 * @api
 */
void exintEnableGroup1(uint32_t mask, exintmode_t mode) {
  uint32_t cmask;

  /* Mask including only configurable lines.*/
  cmask = mask & ~AT32_EXINT_INTEN_MASK;

  if ((mode & EXINT_MODE_EDGES_MASK) == 0U) {
    /* Disabling channels.*/
    EXINT->INTEN   &= ~mask;
    EXINT->EVTEN   &= ~mask;
    EXINT->POLCFG1 &= ~cmask;
    EXINT->POLCFG2 &= ~cmask;
    EXINT->INTSTS   =  cmask;
  }
  else {
    /* Programming edge registers.*/
    if (mode & EXINT_MODE_RISING_EDGE) {
      EXINT->POLCFG1 |= cmask;
    }
    else {
      EXINT->POLCFG1 &= ~cmask;
    }
    if (mode & EXINT_MODE_FALLING_EDGE) {
      EXINT->POLCFG2 |= cmask;
    }
    else {
      EXINT->POLCFG2 &= ~cmask;
    }

    /* Programming interrupt and event registers.*/
    if ((mode & EXINT_MODE_ACTION_MASK) == EXINT_MODE_ACTION_INTERRUPT) {
      EXINT->INTEN |= mask;
      EXINT->EVTEN &= ~mask;
    }
    else {
      EXINT->EVTEN |= mask;
      EXINT->INTEN &= ~mask;
    }
  }
}

/**
 * @brief   AT32 EXINT line initialization.
 *
 * @param[in] line      line to be initialized
 * @param[in] mode      initialization mode
 *
 * @api
 */
void exintEnableLine(exintline_t line, exintmode_t mode) {
  uint32_t mask = (1U << (line & 0x1FU));

  osalDbgCheck(line < AT32_EXINT_NUM_LINES);
  osalDbgCheck((mode & ~EXINT_MODE_MASK) == 0U);

  exintEnableGroup1(mask, mode);
}

/**
 * @brief   AT32 EXINT line IRQ status clearing.
 *
 * @param[in] line      line to be initialized
 *
 * @api
 */
void exintClearLine(exintline_t line) {
  uint32_t mask = (1U << (line & 0x1FU));

  osalDbgCheck(line < AT32_EXINT_NUM_LINES);

  exintClearGroup1(mask);
}

#endif /* AT32_EXINT_REQUIRED */

/** @} */
