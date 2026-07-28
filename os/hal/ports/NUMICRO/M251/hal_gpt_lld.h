/*
    Copyright (C) 2024 Hansem Ro <hansemro@outlook.com>
    Modifications copyright (C) 2026 Belonit

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
 * @file    M251/hal_gpt_lld.h
 * @brief   M251/M252 GPT subsystem low level driver header.
 *
 * @addtogroup GPT
 * @{
 */

#ifndef HAL_GPT_LLD_H
#define HAL_GPT_LLD_H

#if (HAL_USE_GPT == TRUE) || defined(__DOXYGEN__)

#include "m251_registry.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    M251 GPT configuration options
 * @{
 */

/**
 * @brief   GPTD1 driver enable switch.
 * @details If set to @p TRUE the support for TMR0 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(M251_GPT_USE_TMR0) || defined(__DOXYGEN__)
#define M251_GPT_USE_TMR0                       FALSE
#endif

/**
 * @brief   GPTD2 driver enable switch.
 * @details If set to @p TRUE the support for TMR1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(M251_GPT_USE_TMR1) || defined(__DOXYGEN__)
#define M251_GPT_USE_TMR1                       FALSE
#endif

/**
 * @brief   GPTD3 driver enable switch.
 * @details If set to @p TRUE the support for TMR2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(M251_GPT_USE_TMR2) || defined(__DOXYGEN__)
#define M251_GPT_USE_TMR2                       FALSE
#endif

/**
 * @brief   GPTD4 driver enable switch.
 * @details If set to @p TRUE the support for TMR3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(M251_GPT_USE_TMR3) || defined(__DOXYGEN__)
#define M251_GPT_USE_TMR3                       FALSE
#endif

/**
 * @brief   TMR0 interrupt priority.
 * @note    The default is 3.
 */
#if !defined(M251_GPT_TMR0_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define M251_GPT_TMR0_IRQ_PRIORITY              3
#endif

/**
 * @brief   TMR1 interrupt priority.
 * @note    The default is 3.
 */
#if !defined(M251_GPT_TMR1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define M251_GPT_TMR1_IRQ_PRIORITY              3
#endif

/**
 * @brief   TMR2 interrupt priority.
 * @note    The default is 3.
 */
#if !defined(M251_GPT_TMR2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define M251_GPT_TMR2_IRQ_PRIORITY              3
#endif

/**
 * @brief   TMR3 interrupt priority.
 * @note    The default is 3.
 */
#if !defined(M251_GPT_TMR3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define M251_GPT_TMR3_IRQ_PRIORITY              3
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#define M251_GPT_DRIVER_COUNT                                             \
  ((M251_GPT_USE_TMR0 == TRUE) +                                          \
   (M251_GPT_USE_TMR1 == TRUE) +                                          \
   (M251_GPT_USE_TMR2 == TRUE) +                                          \
   (M251_GPT_USE_TMR3 == TRUE))

#if M251_GPT_USE_TMR0 && !M251_HAS_TIM0
#error "TMR0 not present in the selected device"
#endif

#if M251_GPT_USE_TMR1 && !M251_HAS_TIM1
#error "TMR1 not present in the selected device"
#endif

#if M251_GPT_USE_TMR2 && !M251_HAS_TIM2
#error "TMR2 not present in the selected device"
#endif

#if M251_GPT_USE_TMR3 && !M251_HAS_TIM3
#error "TMR3 not present in the selected device"
#endif

#if M251_GPT_DRIVER_COUNT == 0U
#error "GPT driver activated but no timer peripheral assigned"
#endif

#if M251_GPT_USE_TMR0 &&                                                   \
    !OSAL_IRQ_IS_VALID_PRIORITY(M251_GPT_TMR0_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR0"
#endif

#if M251_GPT_USE_TMR1 &&                                                   \
    !OSAL_IRQ_IS_VALID_PRIORITY(M251_GPT_TMR1_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR1"
#endif

#if M251_GPT_USE_TMR2 &&                                                   \
    !OSAL_IRQ_IS_VALID_PRIORITY(M251_GPT_TMR2_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR2"
#endif

#if M251_GPT_USE_TMR3 &&                                                   \
    !OSAL_IRQ_IS_VALID_PRIORITY(M251_GPT_TMR3_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR3"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   GPT frequency type.
 */
typedef uint32_t gptfreq_t;

/**
 * @brief   GPT counter type.
 */
typedef uint32_t gptcnt_t;

/**
 * @brief   Type of a structure representing a GPT driver.
 */
typedef struct GPTDriver GPTDriver;

/**
 * @brief   GPT notification callback type.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 */
typedef void (*gptcallback_t)(GPTDriver *gptp);

/**
 * @brief   Driver configuration structure.
 */
typedef struct {
  /**
   * @brief   Timer clock in Hz.
   */
  gptfreq_t     frequency;
  /**
   * @brief   Timer callback pointer.
   * @note    This callback is invoked on GPT counter events.
   */
  gptcallback_t callback;
} GPTConfig;

/**
 * @brief   Structure representing a GPT driver.
 */
struct GPTDriver {
  /**
   * @brief   Driver state.
   */
  gptstate_t      state;
  /**
   * @brief   Current configuration data.
   */
  const GPTConfig *config;
  /**
   * @brief   Pointer to the associated timer registers.
   */
  TIMER_T         *tim;
  /**
   * @brief   Timer input clock in Hz.
   */
  uint32_t        clock;
  /**
   * @brief   Hardware prescaler value.
   */
  uint8_t         psc;
};

#if (M251_GPT_USE_TMR0 == TRUE) || defined(__DOXYGEN__)
extern GPTDriver GPTD1;
#endif
#if (M251_GPT_USE_TMR1 == TRUE) || defined(__DOXYGEN__)
extern GPTDriver GPTD2;
#endif
#if (M251_GPT_USE_TMR2 == TRUE) || defined(__DOXYGEN__)
extern GPTDriver GPTD3;
#endif
#if (M251_GPT_USE_TMR3 == TRUE) || defined(__DOXYGEN__)
extern GPTDriver GPTD4;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void gpt_lld_init(void);
  void gpt_lld_start(GPTDriver *gptp);
  void gpt_lld_stop(GPTDriver *gptp);
  void gpt_lld_start_timer(GPTDriver *gptp, gptcnt_t interval);
  void gpt_lld_stop_timer(GPTDriver *gptp);
  void gpt_lld_polled_delay(GPTDriver *gptp, gptcnt_t interval);
  void gpt_lld_change_interval(GPTDriver *gptp, gptcnt_t interval);
  gptcnt_t gpt_lld_get_interval(GPTDriver *gptp);
  gptcnt_t gpt_lld_get_counter(GPTDriver *gptp);
  void gpt_lld_serve_interrupt(GPTDriver *gptp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_GPT == TRUE */

#endif /* HAL_GPT_LLD_H */

/** @} */
