/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    Copyright (C) 2026 QMK

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
 * @file    SK32F0xx/hal_gpt_lld.h
 * @brief   SK32F0xx GPT subsystem low level driver header.
 * @details The SK32F0xx general purpose timers (TIM3 on the APB1 bus and
 *          the basic/general purpose TIM16/TIM17 on the APB2 bus) use the
 *          classic 16-bit CR1/CR2/SMCR/DIER/SR/EGR + 32-bit CNT/ARR/CCRx
 *          register layout (TIMv1 class).  This driver is written directly
 *          against the vendor CMSIS header (@p sk32f0xx.h), no STM32 port
 *          code is involved.
 *
 * @addtogroup GPT
 * @{
 */

#ifndef HAL_GPT_LLD_H
#define HAL_GPT_LLD_H

#if HAL_USE_GPT || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    TIM DIER register masks
 * @{
 */
#define SK32_TIM_DIER_IRQ_MASK          (TIM_DIER_UIE   |                   \
                                         TIM_DIER_CC1IE |                   \
                                         TIM_DIER_CC2IE |                   \
                                         TIM_DIER_CC3IE |                   \
                                         TIM_DIER_CC4IE |                   \
                                         TIM_DIER_COMIE |                   \
                                         TIM_DIER_TIE   |                   \
                                         TIM_DIER_BIE)
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   GPTD3 driver enable switch.
 * @details If set to @p TRUE the support for GPTD3 (TIM3) is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SK32_GPT_USE_TIM3) || defined(__DOXYGEN__)
#define SK32_GPT_USE_TIM3                   FALSE
#endif

/**
 * @brief   GPTD16 driver enable switch.
 * @details If set to @p TRUE the support for GPTD16 (TIM16) is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SK32_GPT_USE_TIM16) || defined(__DOXYGEN__)
#define SK32_GPT_USE_TIM16                  FALSE
#endif

/**
 * @brief   GPTD17 driver enable switch.
 * @details If set to @p TRUE the support for GPTD17 (TIM17) is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SK32_GPT_USE_TIM17) || defined(__DOXYGEN__)
#define SK32_GPT_USE_TIM17                  FALSE
#endif

/**
 * @brief   GPTD3 interrupt priority level setting.
 * @note    ARMv6-M (Cortex-M0) implements only 2 priority bits, the valid
 *          priority range is 0 (highest) .. 3 (lowest).
 */
#if !defined(SK32_GPT_TIM3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SK32_GPT_TIM3_IRQ_PRIORITY          3
#endif

/**
 * @brief   GPTD16 interrupt priority level setting.
 */
#if !defined(SK32_GPT_TIM16_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SK32_GPT_TIM16_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPTD17 interrupt priority level setting.
 */
#if !defined(SK32_GPT_TIM17_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SK32_GPT_TIM17_IRQ_PRIORITY         3
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !defined(SK32_HAS_TIM3)
#define SK32_HAS_TIM3                       FALSE
#endif
#if !defined(SK32_HAS_TIM16)
#define SK32_HAS_TIM16                      FALSE
#endif
#if !defined(SK32_HAS_TIM17)
#define SK32_HAS_TIM17                      FALSE
#endif

#if SK32_GPT_USE_TIM3 && !SK32_HAS_TIM3
#error "TIM3 not present in the selected device"
#endif

#if SK32_GPT_USE_TIM16 && !SK32_HAS_TIM16
#error "TIM16 not present in the selected device"
#endif

#if SK32_GPT_USE_TIM17 && !SK32_HAS_TIM17
#error "TIM17 not present in the selected device"
#endif

#if !SK32_GPT_USE_TIM3 && !SK32_GPT_USE_TIM16 && !SK32_GPT_USE_TIM17
#error "GPT driver activated but no TIM peripheral assigned"
#endif

/* Checks on allocation of TIMx units.*/
#if SK32_GPT_USE_TIM3
#if defined(SK32_TIM3_IS_USED)
#error "GPTD3 requires TIM3 but the timer is already used"
#else
#define SK32_TIM3_IS_USED
#endif
#endif

#if SK32_GPT_USE_TIM16
#if defined(SK32_TIM16_IS_USED)
#error "GPTD16 requires TIM16 but the timer is already used"
#else
#define SK32_TIM16_IS_USED
#endif
#endif

#if SK32_GPT_USE_TIM17
#if defined(SK32_TIM17_IS_USED)
#error "GPTD17 requires TIM17 but the timer is already used"
#else
#define SK32_TIM17_IS_USED
#endif
#endif

/* IRQ priority checks.*/
#if SK32_GPT_USE_TIM3 && !defined(SK32_TIM3_SUPPRESS_ISR) &&                 \
    !OSAL_IRQ_IS_VALID_PRIORITY(SK32_GPT_TIM3_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TIM3"
#endif

#if SK32_GPT_USE_TIM16 && !defined(SK32_TIM16_SUPPRESS_ISR) &&               \
    !OSAL_IRQ_IS_VALID_PRIORITY(SK32_GPT_TIM16_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TIM16"
#endif

#if SK32_GPT_USE_TIM17 && !defined(SK32_TIM17_SUPPRESS_ISR) &&               \
    !OSAL_IRQ_IS_VALID_PRIORITY(SK32_GPT_TIM17_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TIM17"
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
   * @brief TIM CR2 register initialization data.
   * @note  The value of this field should normally be equal to zero.
   */
  uint16_t                  cr2;
  /**
   * @brief TIM DIER register initialization data.
   * @note  The value of this field should normally be equal to zero.
   * @note  Only the DMA-related bits can be specified in this field.
   */
  uint16_t                  dier;
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
   * @brief Pointer to the TIMx registers block.
   */
  TIM_TypeDef               *tim;
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
  ((gptp)->tim->ARR = (uint32_t)((interval) - 1U))

/**
 * @brief   Returns the interval of GPT peripheral.
 * @pre     The GPT unit must be running in continuous mode.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @return              The current interval.
 *
 * @notapi
 */
#define gpt_lld_get_interval(gptp) ((gptcnt_t)((gptp)->tim->ARR + 1U))

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
#define gpt_lld_get_counter(gptp) ((gptcnt_t)(gptp)->tim->CNT)

/**
 * @brief   Returns the TIM associated with a GPT.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 * @return              The TIM reference.
 *
 * @notapi
 */
#define gpt_lld_get_timer(gptp) ((gptp)->tim)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if SK32_GPT_USE_TIM3 && !defined(__DOXYGEN__)
extern GPTDriver GPTD3;
#endif

#if SK32_GPT_USE_TIM16 && !defined(__DOXYGEN__)
extern GPTDriver GPTD16;
#endif

#if SK32_GPT_USE_TIM17 && !defined(__DOXYGEN__)
extern GPTDriver GPTD17;
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
