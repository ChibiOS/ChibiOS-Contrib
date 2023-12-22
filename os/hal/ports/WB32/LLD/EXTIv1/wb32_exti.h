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
 * @file    EXTIv1/WB32_exti.h
 * @brief   EXTI helper driver header.
 *
 * @addtogroup WB32_EXTI
 * @{
 */

#ifndef WB32_EXTI_H
#define WB32_EXTI_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/* EXTI attributes.*/
#define WB32_EXTI_IMR1_MASK         0xFFF00000U

/**
 * @name    EXTI channel modes
 * @{
 */
#define EXTI_MODE_MASK              7U  /**< @brief Mode parameter mask.    */
#define EXTI_MODE_EDGES_MASK        3U  /**< @brief Edges field mask.       */
#define EXTI_MODE_DISABLED          0U  /**< @brief Channel disabled.       */
#define EXTI_MODE_RISING_EDGE       1U  /**< @brief Rising edge callback.   */
#define EXTI_MODE_FALLING_EDGE      2U  /**< @brief Falling edge callback.  */
#define EXTI_MODE_BOTH_EDGES        3U  /**< @brief Both edges callback.    */
#define EXTI_MODE_ACTION_MASK       4U  /**< @brief Action field mask.      */
#define EXTI_MODE_ACTION_INTERRUPT  0U  /**< @brief Interrupt mode.         */
#define EXTI_MODE_ACTION_EVENT      4U  /**< @brief Event mode.             */
/** @} */


/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !defined(WB32_EXTI_NUM_LINES)
#error "WB32_EXTI_NUM_LINES not defined in registry"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of an EXTI line identifier.
 */
typedef uint32_t extiline_t;

/**
 * @brief   Type of an EXTI line mode.
 */
typedef uint32_t extimode_t;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   From group 1 line number to mask.
 *
 * @param[in] line      line number in range 0..31
 */
#define EXTI_MASK(line) (uint32_t)(1U << (line))

/**
 * @brief   WB32 EXTI group 1 IRQ status clearing.
 *
 * @param[in] mask      mask of group 1 lines to be initialized
 *
 * @special
 */

#define extiClear(mask) do {                                               \
  osalDbgAssert(((mask) & WB32_EXTI_IMR1_MASK) == 0U, "fixed lines");      \
  EXTI->PR = (uint32_t)(mask);                                             \
} while (false)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void extiEnable(uint32_t mask, extimode_t mode);
  void extiEnableLine(extiline_t line, extimode_t mode);
  void extiClearLine(extiline_t line);
  #ifdef __cplusplus
}
#endif

#endif /* WB32_EXTI_H */

/** @} */
