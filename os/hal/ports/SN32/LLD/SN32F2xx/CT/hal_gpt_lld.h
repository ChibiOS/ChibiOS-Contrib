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
 * @file    CT/hal_gpt_lld.h
 * @brief   SN32 GPT subsystem low level driver header.
 *
 * @addtogroup GPT
 * @{
 */

#ifndef HAL_GPT_LLD_H
#define HAL_GPT_LLD_H

#include "sn32_ct.h"

#if HAL_USE_GPT || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   GPTD1 driver enable switch.
 * @details If set to @p TRUE the support for GPTD1 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(SN32_GPT_USE_CT16B0) || defined(__DOXYGEN__)
#define SN32_GPT_USE_CT16B0                  FALSE
#endif

/**
 * @brief   GPTD2 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(SN32_GPT_USE_CT16B1) || defined(__DOXYGEN__)
#define SN32_GPT_USE_CT16B1                  FALSE
#endif

/**
 * @brief   GPTD1 interrupt priority level setting.
 */
#if !defined(SN32_GPT_CT16B0_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SN32_GPT_CT16B0_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPTD2 interrupt priority level setting.
 */
#if !defined(SN32_GPT_CT16B1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SN32_GPT_CT16B1_IRQ_PRIORITY         3
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !defined(SN32_HAS_CT16B0)
#define SN32_HAS_CT16B0                      FALSE
#endif

#if !defined(SN32_HAS_CT16B1)
#define SN32_HAS_CT16B1                      FALSE
#endif

#if SN32_GPT_USE_CT16B0 && !SN32_HAS_CT16B0
#error "CT16B0 not present in the selected device"
#endif

#if SN32_GPT_USE_CT16B1 && !SN32_HAS_CT16B1
#error "CT16B1 not present in the selected device"
#endif

#if !SN32_GPT_USE_CT16B0 && !SN32_GPT_USE_CT16B0 &&                           \
    !SN32_GPT_USE_CT16B1 && !SN32_GPT_USE_CT16B1
#error "GPT driver activated but no CT16 peripheral assigned"
#endif

/* Checks on allocation of CT16Bx units.*/
#if SN32_GPT_USE_CT16B0
#if defined(SN32_CT16B0_IS_USED)
#error "GPTD1 requires CT16B0 but the timer is already used"
#else
#define SN32_CT16B0_IS_USED
#endif
#endif

#if SN32_GPT_USE_CT16B1
#if defined(SN32_CT16B1_IS_USED)
#error "GPTD2 requires CT16B1 but the timer is already used"
#else
#define SN32_CT16B1_IS_USED
#endif
#endif

/* IRQ priority checks.*/
#if SN32_GPT_USE_CT16B0 && !defined(SN32_CT16B0_SUPPRESS_ISR) &&              \
    !OSAL_IRQ_IS_VALID_PRIORITY(SN32_GPT_CT16B0_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to CT16B0"
#endif

#if SN32_GPT_USE_CT16B1 && !defined(SN32_CT16B1_SUPPRESS_ISR) &&              \
    !OSAL_IRQ_IS_VALID_PRIORITY(SN32_GPT_CT16B1_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to CT16B1"
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
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /**
   * @brief   Timer clock in Hz.
   * @note    The low level can use assertions in order to catch invalid
   *          frequency specifications.
   */
  gptfreq_t                 frequency;
  /**
   * @brief   Timer callback pointer.
   * @note    This callback is invoked on GPT counter events.
   * @note    This callback can be set to @p NULL but in that case the
   *          one-shot mode cannot be used.
   */
  gptcallback_t             callback;
  /* End of the mandatory fields.*/
  /**
   * @brief CT16 CNTCTRL register initialization data.
   * @note  The value of this field should normally be equal to zero.
   */
  uint32_t                  cntctrl;
} GPTConfig;

/**
 * @brief   Structure representing a GPT driver.
 */
struct GPTDriver {
  /**
   * @brief Driver state.
   */
  gptstate_t                state;
  /**
   * @brief Current configuration data.
   */
  const GPTConfig           *config;
#if defined(GPT_DRIVER_EXT_FIELDS)
  GPT_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief Timer base clock.
   */
  uint32_t                  clock;
  /**
   * @brief Pointer to the CT registers block.
   */
  sn32_ct_t               *ct;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Changes the interval of GPT peripheral.
 * @details This function changes the interval of a running GPT unit.
 * @pre     The GPT unit must be running in continuous mode.
 * @post    The GPT unit interval is changed to the new value.
 * @note    The function has effect at the next cycle start.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @param[in] interval  new cycle time in timer ticks
 *
 * @notapi
 */
#define gpt_lld_change_interval(gptp, interval)                             \
  ((gptp)->ct->MR0 = (uint32_t)((interval) - 1U))

/**
 * @brief   Returns the interval of GPT peripheral.
 * @pre     The GPT unit must be running in continuous mode.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @return              The current interval.
 *
 * @notapi
 */
#define gpt_lld_get_interval(gptp) ((gptcnt_t)((gptp)->ct->MR0 + 1U))

/**
 * @brief   Returns the counter value of GPT peripheral.
 * @pre     The GPT unit must be running in continuous mode.
 * @note    The nature of the counter is not defined, it may count upward
 *          or downward, it could be continuously running or not.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @return              The current counter value.
 *
 * @notapi
 */
#define gpt_lld_get_counter(gptp) ((gptcnt_t)(gptp)->ct->TC)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if SN32_GPT_USE_CT16B0 && !defined(__DOXYGEN__)
extern GPTDriver GPTD1;
#endif

#if SN32_GPT_USE_CT16B1 && !defined(__DOXYGEN__)
extern GPTDriver GPTD2;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void gpt_lld_init(void);
  void gpt_lld_start(GPTDriver *gptp);
  void gpt_lld_stop(GPTDriver *gptp);
  void gpt_lld_start_timer(GPTDriver *gptp, gptcnt_t period);
  void gpt_lld_stop_timer(GPTDriver *gptp);
  void gpt_lld_polled_delay(GPTDriver *gptp, gptcnt_t interval);
  void gpt_lld_serve_interrupt(GPTDriver *gptp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_GPT */

#endif /* HAL_GPT_LLD_H */

/** @} */
