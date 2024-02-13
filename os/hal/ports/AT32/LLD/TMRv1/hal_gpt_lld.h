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
 * @file    TMRv1/hal_gpt_lld.h
 * @brief   AT32 GPT subsystem low level driver header.
 *
 * @addtogroup GPT
 * @{
 */

#ifndef HAL_GPT_LLD_H
#define HAL_GPT_LLD_H

#include "at32_tmr.h"

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
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_GPT_USE_TMR1) || defined(__DOXYGEN__)
#define AT32_GPT_USE_TMR1                   FALSE
#endif

/**
 * @brief   GPTD2 driver enable switch.
 * @details If set to @p TRUE the support for GPTD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_GPT_USE_TMR2) || defined(__DOXYGEN__)
#define AT32_GPT_USE_TMR2                   FALSE
#endif

/**
 * @brief   GPTD3 driver enable switch.
 * @details If set to @p TRUE the support for GPTD3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_GPT_USE_TMR3) || defined(__DOXYGEN__)
#define AT32_GPT_USE_TMR3                   FALSE
#endif

/**
 * @brief   GPTD4 driver enable switch.
 * @details If set to @p TRUE the support for GPTD4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_GPT_USE_TMR4) || defined(__DOXYGEN__)
#define AT32_GPT_USE_TMR4                   FALSE
#endif

/**
 * @brief   GPTD5 driver enable switch.
 * @details If set to @p TRUE the support for GPTD5 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_GPT_USE_TMR5) || defined(__DOXYGEN__)
#define AT32_GPT_USE_TMR5                   FALSE
#endif

/**
 * @brief   GPTD9 driver enable switch.
 * @details If set to @p TRUE the support for GPTD9 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_GPT_USE_TMR9) || defined(__DOXYGEN__)
#define AT32_GPT_USE_TMR9                   FALSE
#endif

/**
 * @brief   GPTD10 driver enable switch.
 * @details If set to @p TRUE the support for GPTD10 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_GPT_USE_TMR10) || defined(__DOXYGEN__)
#define AT32_GPT_USE_TMR10                  FALSE
#endif

/**
 * @brief   GPTD11 driver enable switch.
 * @details If set to @p TRUE the support for GPTD11 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_GPT_USE_TMR11) || defined(__DOXYGEN__)
#define AT32_GPT_USE_TMR11                  FALSE
#endif

/**
 * @brief   GPTD1 interrupt priority level setting.
 */
#if !defined(AT32_GPT_TMR1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_GPT_TMR1_IRQ_PRIORITY          7
#endif

/**
 * @brief   GPTD2 interrupt priority level setting.
 */
#if !defined(AT32_GPT_TMR2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_GPT_TMR2_IRQ_PRIORITY          7
#endif

/**
 * @brief   GPTD3 interrupt priority level setting.
 */
#if !defined(AT32_GPT_TMR3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_GPT_TMR3_IRQ_PRIORITY          7
#endif

/**
 * @brief   GPTD4 interrupt priority level setting.
 */
#if !defined(AT32_GPT_TMR4_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_GPT_TMR4_IRQ_PRIORITY          7
#endif

/**
 * @brief   GPTD5 interrupt priority level setting.
 */
#if !defined(AT32_GPT_TMR5_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_GPT_TMR5_IRQ_PRIORITY          7
#endif

/**
 * @brief   GPTD9 interrupt priority level setting.
 */
#if !defined(AT32_GPT_TMR9_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_GPT_TMR9_IRQ_PRIORITY          7
#endif

/**
 * @brief   GPTD10 interrupt priority level setting.
 */
#if !defined(AT32_GPT_TMR10_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_GPT_TMR10_IRQ_PRIORITY         7
#endif

/**
 * @brief   GPTD11 interrupt priority level setting.
 */
#if !defined(AT32_GPT_TMR11_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_GPT_TMR11_IRQ_PRIORITY         7
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !defined(AT32_HAS_TMR1)
#define AT32_HAS_TMR1                       FALSE
#endif

#if !defined(AT32_HAS_TMR2)
#define AT32_HAS_TMR2                       FALSE
#endif

#if !defined(AT32_HAS_TMR3)
#define AT32_HAS_TMR3                       FALSE
#endif

#if !defined(AT32_HAS_TMR4)
#define AT32_HAS_TMR4                       FALSE
#endif

#if !defined(AT32_HAS_TMR5)
#define AT32_HAS_TMR5                       FALSE
#endif

#if !defined(AT32_HAS_TMR9)
#define AT32_HAS_TMR9                       FALSE
#endif

#if !defined(AT32_HAS_TMR10)
#define AT32_HAS_TMR10                      FALSE
#endif

#if !defined(AT32_HAS_TMR11)
#define AT32_HAS_TMR11                      FALSE
#endif

#if AT32_GPT_USE_TMR1 && !AT32_HAS_TMR1
#error "TMR1 not present in the selected device"
#endif

#if AT32_GPT_USE_TMR2 && !AT32_HAS_TMR2
#error "TMR2 not present in the selected device"
#endif

#if AT32_GPT_USE_TMR3 && !AT32_HAS_TMR3
#error "TMR3 not present in the selected device"
#endif

#if AT32_GPT_USE_TMR4 && !AT32_HAS_TMR4
#error "TMR4 not present in the selected device"
#endif

#if AT32_GPT_USE_TMR5 && !AT32_HAS_TMR5
#error "TMR5 not present in the selected device"
#endif

#if AT32_GPT_USE_TMR9 && !AT32_HAS_TMR9
#error "TMR9 not present in the selected device"
#endif

#if AT32_GPT_USE_TMR10 && !AT32_HAS_TMR10
#error "TMR10 not present in the selected device"
#endif

#if AT32_GPT_USE_TMR11 && !AT32_HAS_TMR11
#error "TMR11 not present in the selected device"
#endif

#if !AT32_GPT_USE_TMR1  && !AT32_GPT_USE_TMR2 &&                            \
    !AT32_GPT_USE_TMR3  && !AT32_GPT_USE_TMR4 &&                            \
    !AT32_GPT_USE_TMR5  && !AT32_GPT_USE_TMR9 &&                            \
    !AT32_GPT_USE_TMR10 && !AT32_GPT_USE_TMR11
#error "GPT driver activated but no TMR peripheral assigned"
#endif

/* Checks on allocation of TMRx units.*/
#if AT32_GPT_USE_TMR1
#if defined(AT32_TMR1_IS_USED)
#error "GPTD1 requires TMR1 but the timer is already used"
#else
#define AT32_TMR1_IS_USED
#endif
#endif

#if AT32_GPT_USE_TMR2
#if defined(AT32_TMR2_IS_USED)
#error "GPTD2 requires TMR2 but the timer is already used"
#else
#define AT32_TMR2_IS_USED
#endif
#endif

#if AT32_GPT_USE_TMR3
#if defined(AT32_TMR3_IS_USED)
#error "GPTD3 requires TMR3 but the timer is already used"
#else
#define AT32_TMR3_IS_USED
#endif
#endif

#if AT32_GPT_USE_TMR4
#if defined(AT32_TMR4_IS_USED)
#error "GPTD4 requires TMR4 but the timer is already used"
#else
#define AT32_TMR4_IS_USED
#endif
#endif

#if AT32_GPT_USE_TMR5
#if defined(AT32_TMR5_IS_USED)
#error "GPTD5 requires TMR5 but the timer is already used"
#else
#define AT32_TMR5_IS_USED
#endif
#endif

#if AT32_GPT_USE_TMR9
#if defined(AT32_TMR9_IS_USED)
#error "GPTD9 requires TMR9 but the timer is already used"
#else
#define AT32_TMR9_IS_USED
#endif
#endif

#if AT32_GPT_USE_TMR10
#if defined(AT32_TMR10_IS_USED)
#error "GPTD10 requires TMR10 but the timer is already used"
#else
#define AT32_TMR10_IS_USED
#endif
#endif

#if AT32_GPT_USE_TMR11
#if defined(AT32_TMR11_IS_USED)
#error "GPTD11 requires TMR11 but the timer is already used"
#else
#define AT32_TMR11_IS_USED
#endif
#endif

/* IRQ priority checks.*/
#if AT32_GPT_USE_TMR1 && !defined(AT32_TMR1_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_GPT_TMR1_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR1"
#endif

#if AT32_GPT_USE_TMR2 && !defined(AT32_TMR2_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_GPT_TMR2_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR2"
#endif

#if AT32_GPT_USE_TMR3 && !defined(AT32_TMR3_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_GPT_TMR3_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR3"
#endif

#if AT32_GPT_USE_TMR4 && !defined(AT32_TMR4_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_GPT_TMR4_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR4"
#endif

#if AT32_GPT_USE_TMR5 && !defined(AT32_TMR5_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_GPT_TMR5_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR5"
#endif

#if AT32_GPT_USE_TMR9 && !defined(AT32_TMR9_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_GPT_TMR9_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR9"
#endif

#if AT32_GPT_USE_TMR10 && !defined(AT32_TMR10_SUPPRESS_ISR) &&              \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_GPT_TMR10_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR10"
#endif

#if AT32_GPT_USE_TMR11 && !defined(AT32_TMR11_SUPPRESS_ISR) &&              \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_GPT_TMR11_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR11"
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
   * @brief TMR CTRL2 register initialization data.
   * @note  The value of this field should normally be equal to zero.
   */
  uint32_t                  ctrl2;
  /**
   * @brief TMR IDEN register initialization data.
   * @note  The value of this field should normally be equal to zero.
   * @note  Only the DMA-related bits can be specified in this field.
   */
  uint32_t                  iden;
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
   * @brief Presence of plus mode.
   */
  bool                      has_plus_mode;
  /**
   * @brief Pointer to the TMRx registers block.
   */
  at32_tmr_t                *tmr;
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
  ((gptp)->tmr->PR = (uint32_t)((interval) - 1U))

/**
 * @brief   Returns the interval of GPT peripheral.
 * @pre     The GPT unit must be running in continuous mode.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @return              The current interval.
 *
 * @notapi
 */
#define gpt_lld_get_interval(gptp) ((gptcnt_t)((gptp)->tmr->PR + 1U))

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
#define gpt_lld_get_counter(gptp) ((gptcnt_t)(gptp)->tmr->CVAL)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if AT32_GPT_USE_TMR1 && !defined(__DOXYGEN__)
extern GPTDriver GPTD1;
#endif

#if AT32_GPT_USE_TMR2 && !defined(__DOXYGEN__)
extern GPTDriver GPTD2;
#endif

#if AT32_GPT_USE_TMR3 && !defined(__DOXYGEN__)
extern GPTDriver GPTD3;
#endif

#if AT32_GPT_USE_TMR4 && !defined(__DOXYGEN__)
extern GPTDriver GPTD4;
#endif

#if AT32_GPT_USE_TMR5 && !defined(__DOXYGEN__)
extern GPTDriver GPTD5;
#endif

#if AT32_GPT_USE_TMR9 && !defined(__DOXYGEN__)
extern GPTDriver GPTD9;
#endif

#if AT32_GPT_USE_TMR10 && !defined(__DOXYGEN__)
extern GPTDriver GPTD10;
#endif

#if AT32_GPT_USE_TMR11 && !defined(__DOXYGEN__)
extern GPTDriver GPTD11;
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
