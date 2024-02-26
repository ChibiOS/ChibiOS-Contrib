/*
    Copyright (C) 2024 Hansem Ro <hansemro@outlook.com>

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
 * @file    hal_gpt_lld.h
 * @brief   PLATFORM GPT subsystem low level driver header.
 *
 * @addtogroup GPT
 * @{
 */

#ifndef HAL_GPT_LLD_H
#define HAL_GPT_LLD_H

#if (HAL_USE_GPT == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    PLATFORM configuration options
 * @{
 */
/**
 * @brief   GPTD0 driver enable switch.
 * @details If set to @p TRUE the support for GPTD0 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(NUC123_GPT_USE_TIMER0) || defined(__DOXYGEN__)
#define NUC123_GPT_USE_TIMER0                   FALSE
#endif

/**
 * @brief   GPTD1 driver enable switch.
 * @details If set to @p TRUE the support for GPTD1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(NUC123_GPT_USE_TIMER1) || defined(__DOXYGEN__)
#define NUC123_GPT_USE_TIMER1                   FALSE
#endif

/**
 * @brief   GPTD2 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(NUC123_GPT_USE_TIMER2) || defined(__DOXYGEN__)
#define NUC123_GPT_USE_TIMER2                   FALSE
#endif

/**
 * @brief   GPTD3 driver enable switch.
 * @details If set to @p TRUE the support for GPTD3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(NUC123_GPT_USE_TIMER3) || defined(__DOXYGEN__)
#define NUC123_GPT_USE_TIMER3                   FALSE
#endif

/**
 * @brief   GPTD0 interrupt priority level setting.
 */
#if !defined(NUC123_GPT_TIMER0_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define NUC123_GPT_TIMER0_IRQ_PRIORITY          3
#endif

/**
 * @brief   GPTD1 interrupt priority level setting.
 */
#if !defined(NUC123_GPT_TIMER1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define NUC123_GPT_TIMER1_IRQ_PRIORITY          3
#endif

/**
 * @brief   GPTD2 interrupt priority level setting.
 */
#if !defined(NUC123_GPT_TIMER2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define NUC123_GPT_TIMER2_IRQ_PRIORITY          3
#endif

/**
 * @brief   GPTD3 interrupt priority level setting.
 */
#if !defined(NUC123_GPT_TIMER3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define NUC123_GPT_TIMER3_IRQ_PRIORITY          3
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

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
typedef uint16_t gptcnt_t;

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
   */
  gptcallback_t             callback;
  /* End of the mandatory fields.*/
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
  TIMER_T *TIMER;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Changes the interval of GPT peripheral.
 * @details This function changes the interval of a running GPT unit.
 * @pre     The GPT unit must have been activated using @p gptStart().
 * @pre     The GPT unit must have been running in continuous mode using
 *          @p gptStartContinuous().
 * @post    The GPT unit interval is changed to the new value.
 * @note    The function has effect at the next cycle start.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @param[in] interval  new cycle time in timer ticks
 * @notapi
 */
#define gpt_lld_change_interval(gptp, interval) \
  ((gptp)->TIMER->TCMPR = (NUC123_HCLK / (gptp)->config->frequency) * (interval))

/**
 * @brief   Returns the interval of GPT peripheral.
 * @pre     The GPT unit must be running in continuous mode.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @return              The current interval.
 * @notapi
 */
#define gpt_lld_get_interval(gptp) \
  ((gptcnt_t)(gptp)->TIMER->TCMPR / (NUC122_HCLK / (gptp)->config->frequency))

/**
 * @brief   Returns the counter value of GPT peripheral.
 * @pre     The GPT unit must be running in continuous mode.
 * @note    The nature of the counter is not defined, it may count upward
 *          or downward, it could be continuously running or not.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @return              The current counter value.
 * @notapi
 */
#define gpt_lld_get_counter(gptp) \
  ((gptcnt_t)((gptp)->TIMER->TDR / (NUC123_HCLK / (gptp)->config->frequency)))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (NUC123_GPT_USE_TIMER0 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD0;
#endif
#if (NUC123_GPT_USE_TIMER1 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD1;
#endif
#if (NUC123_GPT_USE_TIMER2 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD2;
#endif
#if (NUC123_GPT_USE_TIMER3 == TRUE) && !defined(__DOXYGEN__)
extern GPTDriver GPTD3;
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
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_GPT == TRUE */

#endif /* HAL_GPT_LLD_H */

/** @} */
