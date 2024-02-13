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
 * @file    EXINTv1/at32_exint.h
 * @brief   EXINT helper driver header.
 *
 * @addtogroup AT32_EXINT
 * @{
 */

#ifndef AT32_EXINT_H
#define AT32_EXINT_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    EXINT channel modes
 * @{
 */
#define EXINT_MODE_MASK             7U  /**< @brief Mode parameter mask.    */
#define EXINT_MODE_EDGES_MASK       3U  /**< @brief Edges field mask.       */
#define EXINT_MODE_DISABLED         0U  /**< @brief Channel disabled.       */
#define EXINT_MODE_RISING_EDGE      1U  /**< @brief Rising edge callback.   */
#define EXINT_MODE_FALLING_EDGE     2U  /**< @brief Falling edge callback.  */
#define EXINT_MODE_BOTH_EDGES       3U  /**< @brief Both edges callback.    */
#define EXINT_MODE_ACTION_MASK      4U  /**< @brief Action field mask.      */
#define EXINT_MODE_ACTION_INTERRUPT 0U  /**< @brief Interrupt mode.         */
#define EXINT_MODE_ACTION_EVENT     4U  /**< @brief Event mode.             */
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !defined(AT32_EXINT_NUM_LINES)
#error "AT32_EXINT_NUM_LINES not defined in registry"
#endif

#if (AT32_EXINT_NUM_LINES < 0) || (AT32_EXINT_NUM_LINES > 23)
#error "invalid AT32_EXINT_NUM_LINES value"
#endif

#if !defined(AT32_EXINT_INTEN_MASK)
#error "AT32_EXINT_INTEN_MASK not defined in registry"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of an EXINT line identifier.
 */
typedef uint32_t exintline_t;

/**
 * @brief   Type of an EXINT line mode.
 */
typedef uint32_t exintmode_t;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   From group 1 line number to mask.
 *
 * @param[in] line      line number in range 0..31
 */
#define EXINT_MASK1(line) (uint32_t)(1U << (line))

/**
 * @brief   AT32 EXINT group 1 IRQ status clearing.
 *
 * @param[in] mask      mask of group 1 lines to be initialized
 *
 * @special
 */
#define exintClearGroup1(mask) do {                                         \
  osalDbgAssert(((mask) & AT32_EXINT_INTEN_MASK) == 0U, "fixed lines");     \
  EXINT->INTSTS = (uint32_t)(mask);                                         \
} while (false)

/**
 * @brief   Serves an EXINT interrupt in group 1.
 *
 * @param[in] mask      mask of lines to be cleared
 * @param[out] out      mask of lines needing processing
 *
 * @special
 */
#define exintGetAndClearGroup1(mask, out) do {                              \
  uint32_t intsts;                                                          \
                                                                            \
  intsts = EXINT->INTSTS & (mask);                                          \
  (out) = intsts;                                                           \
  EXINT->INTSTS = intsts;                                                   \
} while (false)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void exintEnableGroup1(uint32_t mask, exintmode_t mode);
  void exintEnableLine(exintline_t line, exintmode_t mode);
  void exintClearLine(exintline_t line);
  #ifdef __cplusplus
}
#endif

#endif /* AT32_EXINT_H */

/** @} */
