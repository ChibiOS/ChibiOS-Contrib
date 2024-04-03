/*
    Copyright (C) 2020

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
 * @file    hal_pwm_lld.h
 * @brief   ES32 PWM subsystem low level driver header.
 *
 * @addtogroup PWM
 * @{
 */

#ifndef HAL_PWM_LLD_H
#define HAL_PWM_LLD_H

#if (HAL_USE_PWM == TRUE) || defined(__DOXYGEN__)


/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Number of PWM channels per PWM driver.
 */
#define PWM_CHANNELS                            4

/**
 * @name    ES32-specific PWM complementary output mode macros
 * @{
 */
/**
 * @brief   Complementary output modes mask.
 * @note    This is an ES32-specific setting.
 */
#define PWM_COMPLEMENTARY_OUTPUT_MASK           0xF0

/**
 * @brief   Complementary output not driven.
 * @note    This is an ES32-specific setting.
 */
#define PWM_COMPLEMENTARY_OUTPUT_DISABLED       0x00

/**
 * @brief   Complementary output, active is logic level one.
 * @note    This is an ES32-specific setting.
 * @note    This setting is only available if the timer supports the
 *          BDTR register.
 */
#define PWM_COMPLEMENTARY_OUTPUT_ACTIVE_HIGH    0x10

/**
 * @brief   Complementary output, active is logic level zero.
 * @note    This is an ES32-specific setting.
 * @note    This setting is only available if the timer supports the
 *          BDTR register.
 */
#define PWM_COMPLEMENTARY_OUTPUT_ACTIVE_LOW    0x20


#define PWM_COMPLEMENTARY_INTERRUPT_MASK       (TIMER_IFM_UPD  | TIMER_IFM_CH1  | \
                                                TIMER_IFM_CH2  | TIMER_IFM_CH3  | \
                                                TIMER_IFM_CH4  | TIMER_IFM_COM  | \
                                                TIMER_IFM_TRGI | TIMER_IFM_BRK  | \
                                                TIMER_IFM_CH1OV| TIMER_IFM_CH2OV| \
                                                TIMER_IFM_CH3OV| TIMER_IFM_CH4OV)
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */

/**
 * @brief   PWM_AD16C4T1 driver enable switch.
 * @details If set to @p TRUE the support for PWM_AD16C4T1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(ES32_PWM_USE_AD16C4T1) || defined(__DOXYGEN__)
#define ES32_PWM_USE_AD16C4T1                  FALSE
#endif

/**
 * @brief   PWM_GP32C4T1 driver enable switch.
 * @details If set to @p TRUE the support for PWM_GP32C4T1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(ES32_PWM_USE_GP32C4T1) || defined(__DOXYGEN__)
#define ES32_PWM_USE_GP32C4T1                  FALSE
#endif

/**
 * @brief   PWM_GP16C4T1 driver enable switch.
 * @details If set to @p TRUE the support for PWM_GP16C4T1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(ES32_PWM_USE_GP16C4T1) || defined(__DOXYGEN__)
#define ES32_PWM_USE_GP16C4T1                  FALSE
#endif

/**
 * @brief   PWM_GP16C4T2 driver enable switch.
 * @details If set to @p TRUE the support for PWM_GP16C4T2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(ES32_PWM_USE_GP16C4T2) || defined(__DOXYGEN__)
#define ES32_PWM_USE_GP16C4T2                  FALSE
#endif

/**
 * @brief   PWM_GP16C4T3 driver enable switch.
 * @details If set to @p TRUE the support for PWM_GP16C4T3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(ES32_PWM_USE_GP16C4T3) || defined(__DOXYGEN__)
#define ES32_PWM_USE_GP16C4T3                  FALSE
#endif

/**
 * @brief   PWM_GP16C2T1 driver enable switch.
 * @details If set to @p TRUE the support for PWM_GP16C2T1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(ES32_PWM_USE_GP16C2T1) || defined(__DOXYGEN__)
#define ES32_PWM_USE_GP16C2T1                  FALSE
#endif

/**
 * @brief   PWM_GP16C2T2 driver enable switch.
 * @details If set to @p TRUE the support for PWM_GP16C2T2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(ES32_PWM_USE_GP16C2T2) || defined(__DOXYGEN__)
#define ES32_PWM_USE_GP16C2T2                  FALSE
#endif

/**
 * @brief   PWM_GP16C2T3 driver enable switch.
 * @details If set to @p TRUE the support for PWM_GP16C2T3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(ES32_PWM_USE_GP16C2T3) || defined(__DOXYGEN__)
#define ES32_PWM_USE_GP16C2T3                  FALSE
#endif

/**
 * @brief   PWM_GP16C2T4 driver enable switch.
 * @details If set to @p TRUE the support for PWM_GP16C2T4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(ES32_PWM_USE_GP16C2T4) || defined(__DOXYGEN__)
#define ES32_PWM_USE_GP16C2T4                  FALSE
#endif

/**
 * @brief   PWM_AD16C4T1 interrupt priority level setting.
 */
#if !defined(ES32_PWM_AD16C4T1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define ES32_PWM_AD16C4T1_IRQ_PRIORITY         7
#endif

/**
 * @brief   PWM_GP32C4T1 interrupt priority level setting.
 */
#if !defined(ES32_PWM_GP32C4T1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define ES32_PWM_GP32C4T1_IRQ_PRIORITY         7
#endif

/**
 * @brief   PWM_GP16C4T1 interrupt priority level setting.
 */
#if !defined(ES32_PWM_GP16C4T1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define ES32_PWM_GP16C4T1_IRQ_PRIORITY         7
#endif

/**
 * @brief   PWM_GP16C4T2 interrupt priority level setting.
 */
#if !defined(ES32_PWM_GP16C4T2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define ES32_PWM_GP16C4T2_IRQ_PRIORITY         7
#endif

/**
 * @brief   PWM_GP16C4T3 interrupt priority level setting.
 */
#if !defined(ES32_PWM_GP16C4T3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define ES32_PWM_GP16C4T3_IRQ_PRIORITY         7
#endif

/**
 * @brief   PWM_GP16C2T1 interrupt priority level setting.
 */
#if !defined(ES32_PWM_GP16C2T1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define ES32_PWM_GP16C2T1_IRQ_PRIORITY         7
#endif

/**
 * @brief   PWM_GP16C2T2 interrupt priority level setting.
 */
#if !defined(ES32_PWM_GP16C2T2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define ES32_PWM_GP16C2T2_IRQ_PRIORITY         7
#endif

/**
 * @brief   PWM_GP16C2T3 interrupt priority level setting.
 */
#if !defined(ES32_PWM_GP16C2T3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define ES32_PWM_GP16C2T3_IRQ_PRIORITY        7
#endif

/**
 * @brief   PWM_GP16C2T4 interrupt priority level setting.
 */
#if !defined(ES32_PWM_GP16C2T4_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define ES32_PWM_GP16C2T4_IRQ_PRIORITY        7
#endif

/*===========================================================================*/
/* Configuration checks.                                                     */
/*===========================================================================*/

#if !defined(ES32_HAS_AD16C4T1)
#define ES32_HAS_AD16C4T1                      TRUE
#endif

#if !defined(ES32_HAS_GP32C4T1)
#define ES32_HAS_GP32C4T1                      TRUE
#endif

#if !defined(ES32_HAS_GP16C4T1)
#define ES32_HAS_GP16C4T1                      TRUE
#endif

#if !defined(ES32_HAS_GP16C4T2)
#define ES32_HAS_GP16C4T2                      TRUE
#endif

#if !defined(ES32_HAS_GP16C4T3)
#define ES32_HAS_GP16C4T3                      TRUE
#endif

#if !defined(ES32_HAS_GP16C2T1)
#define ES32_HAS_GP16C2T1                      TRUE
#endif

#if !defined(ES32_HAS_GP16C2T2)
#define ES32_HAS_GP16C2T2                      TRUE
#endif

#if !defined(ES32_HAS_GP16C2T3)
#define ES32_HAS_GP16C2T3                      TRUE
#endif

#if !defined(ES32_HAS_GP16C2T4)
#define ES32_HAS_GP16C2T4                      TRUE
#endif

#if ES32_PWM_USE_AD16C4T1 && !ES32_HAS_AD16C4T1
#error "AD16C4T1 not present in the selected device"
#endif

#if ES32_PWM_USE_GP32C4T1 && !ES32_HAS_GP32C4T1
#error "GP32C4T1 not present in the selected device"
#endif

#if ES32_PWM_USE_GP16C4T1 && !ES32_HAS_GP16C4T1
#error "GP16C4T1 not present in the selected device"
#endif

#if ES32_PWM_USE_GP16C4T2 && !ES32_HAS_GP16C4T2
#error "GP16C4T2 not present in the selected device"
#endif

#if ES32_PWM_USE_GP16C4T3 && !ES32_HAS_GP16C4T3
#error "GP16C4T3 not present in the selected device"
#endif

#if ES32_PWM_USE_GP16C2T1 && !ES32_HAS_GP16C2T1
#error "GP16C2T1 not present in the selected device"
#endif

#if ES32_PWM_USE_GP16C2T2 && !ES32_HAS_GP16C2T2
#error "GP16C2T2 not present in the selected device"
#endif

#if ES32_PWM_USE_GP16C2T3 && !ES32_HAS_GP16C2T3
#error "GP16C2T3 not present in the selected device"
#endif

#if ES32_PWM_USE_GP16C2T4 && !ES32_HAS_GP16C2T4
#error "GP16C2T4 not present in the selected device"
#endif

#if !ES32_PWM_USE_AD16C4T1  && !ES32_PWM_USE_GP32C4T1  &&                         \
    !ES32_PWM_USE_GP16C4T1  && !ES32_PWM_USE_GP16C4T2  &&                         \
    !ES32_PWM_USE_GP16C4T3  && !ES32_PWM_USE_GP16C2T1  &&                         \
    !ES32_PWM_USE_GP16C2T2  && !ES32_PWM_USE_GP16C2T3  &&                         \
    !ES32_PWM_USE_GP16C2T4
#error "PWM driver activated but no TIM peripheral assigned"
#endif

/* Checks on allocation of TIMx units.*/
#if ES32_PWM_USE_AD16C4T1
#if defined(ES32_AD16C4T1_IS_USED)
#error "PWM_AD16C4T1 requires AD16C4T1 but the timer is already used"
#else
#define ES32_AD16C4T1_IS_USED
#endif
#endif

#if ES32_PWM_USE_GP32C4T1
#if defined(ES32_GP32C4T1_IS_USED)
#error "PWM_GP32C4T1 requires GP32C4T1 but the timer is already used"
#else
#define ES32_GP32C4T1_IS_USED
#endif
#endif

#if ES32_PWM_USE_GP16C4T1
#if defined(ES32_GP16C4T1_IS_USED)
#error "PWM_GP16C4T1 requires GP16C4T1 but the timer is already used"
#else
#define ES32_GP16C4T1_IS_USED
#endif
#endif

#if ES32_PWM_USE_GP16C4T2
#if defined(ES32_GP16C4T2_IS_USED)
#error "PWM_GP16C4T2 requires GP16C4T2 but the timer is already used"
#else
#define ES32_GP16C4T2_IS_USED
#endif
#endif

#if ES32_PWM_USE_GP16C4T3
#if defined(ES32_GP16C4T3_IS_USED)
#error "PWM_GP16C4T3 requires GP16C4T3 but the timer is already used"
#else
#define ES32_GP16C4T3_IS_USED
#endif
#endif

#if ES32_PWM_USE_GP16C2T1
#if defined(ES32_GP16C2T1_IS_USED)
#error "PWM_GP16C2T1 requires GP16C2T1 but the timer is already used"
#else
#define ES32_GP16C2T1_IS_USED
#endif
#endif

#if ES32_PWM_USE_GP16C2T2
#if defined(ES32_GP16C2T2_IS_USED)
#error "PWM_GP16C2T2 requires GP16C2T2 but the timer is already used"
#else
#define ES32_GP16C2T2_IS_USED
#endif
#endif

#if ES32_PWM_USE_GP16C2T3
#if defined(ES32_GP16C2T3_IS_USED)
#error "PWM_GP16C2T3 requires GP16C2T3 but the timer is already used"
#else
#define ES32_GP16C2T3_IS_USED
#endif
#endif

#if ES32_PWM_USE_GP16C2T4
#if defined(ES32_GP16C2T4_IS_USED)
#error "PWM_GP16C2T4 requires GP16C2T4 but the timer is already used"
#else
#define ES32_GP16C2T4_IS_USED
#endif
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a PWM mode.
 */
typedef uint32_t pwmmode_t;

/**
 * @brief   Type of a PWM channel.
 */
typedef uint8_t pwmchannel_t;

/**
 * @brief   Type of a channels mask.
 */
typedef uint32_t pwmchnmsk_t;

/**
 * @brief   Type of a PWM counter.
 */
typedef uint32_t pwmcnt_t;

/**
 * @brief   Type of a PWM driver channel configuration structure.
 */
typedef struct {
  /**
   * @brief Channel active logic level.
   */
  pwmmode_t                 mode;
  /**
   * @brief Channel callback pointer.
   * @note  This callback is invoked on the channel compare event. If set to
   *        @p NULL then the callback is disabled.
   */
  pwmcallback_t             callback;
  /* End of the mandatory fields.*/
} PWMChannelConfig;

/**
 * @brief   Type of a PWM driver configuration structure.
 */
typedef struct {
  /**
   * @brief   Timer clock in Hz.
   * @note    The low level can use assertions in order to catch invalid
   *          frequency specifications.
   */
  uint32_t                  frequency;
  /**
   * @brief   PWM period in ticks.
   * @note    The low level can use assertions in order to catch invalid
   *          period specifications.
   */
  pwmcnt_t                  period;
  /**
   * @brief Periodic callback pointer.
   * @note  This callback is invoked on PWM counter reset. If set to
   *        @p NULL then the callback is disabled.
   */
  pwmcallback_t             callback;
  /**
   * @brief Channels configurations.
   */
  PWMChannelConfig          channels[PWM_CHANNELS];
  /* End of the mandatory fields.*/
  /**
   * @brief TIM CON2 register initialization data.
   * @note  The value of this field should normally be equal to zero.
   */
  uint32_t                  con2;
  /**
   * @brief TIM BDCFG (break & dead-time) register initialization data.
   * @note  The value of this field should normally be equal to zero.
   */                                                                     \
   uint32_t                 bdcfg;
   /**
    * @brief TIM DMAEN register initialization data.
    * @note  The value of this field should normally be equal to zero.
    * @note  Only the DMA-related bits can be specified in this field.
    */
   uint32_t                 dmaen;
} PWMConfig;

/**
 * @brief   Structure representing a PWM driver.
 */
struct PWMDriver {
  /**
   * @brief Driver state.
   */
  pwmstate_t                state;
  /**
   * @brief Current driver configuration data.
   */
  const PWMConfig           *config;
  /**
   * @brief   Current PWM period in ticks.
   */
  pwmcnt_t                  period;
  /**
   * @brief   Mask of the enabled channels.
   */
  pwmchnmsk_t               enabled;
  /**
   * @brief   Number of channels in this instance.
   */
  pwmchannel_t              channels;
#if defined(PWM_DRIVER_EXT_FIELDS)
  PWM_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief Timer base clock.
   */
  /*
  uint32_t                  clock;
  */
  /**
   * @brief Presence of BDCFG register.
   */
  bool                      has_bdcfg;
  /**
   * @brief Pointer to the TIMx registers block.
   */
  TIMER_TypeDef             *tim;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Changes the period the PWM peripheral.
 * @details This function changes the period of a PWM unit that has already
 *          been activated using @p pwmStart().
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @post    The PWM unit period is changed to the new value.
 * @note    The function has effect at the next cycle start.
 * @note    If a period is specified that is shorter than the pulse width
 *          programmed in one of the channels then the behavior is not
 *          guaranteed.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] period    new cycle time in ticks
 *
 * @notapi
 */
#define pwm_lld_change_period(pwmp, period)                                 \
  ((pwmp)->tim->AR = ((period) - 1))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if ES32_PWM_USE_AD16C4T1 && !defined(__DOXYGEN__)
extern PWMDriver PWM_AD16C4T1;
#endif

#if ES32_PWM_USE_GP32C4T1 && !defined(__DOXYGEN__)
extern PWMDriver PWM_GP32C4T1;
#endif

#if ES32_PWM_USE_GP16C4T1 && !defined(__DOXYGEN__)
extern PWMDriver PWM_GP16C4T1;
#endif

#if ES32_PWM_USE_GP16C4T2 && !defined(__DOXYGEN__)
extern PWMDriver PWM_GP16C4T2;
#endif

#if ES32_PWM_USE_GP16C4T3 && !defined(__DOXYGEN__)
extern PWMDriver PWM_GP16C4T3;
#endif

#if ES32_PWM_USE_GP16C2T1 && !defined(__DOXYGEN__)
extern PWMDriver PWM_GP16C2T1;
#endif

#if ES32_PWM_USE_GP16C2T2 && !defined(__DOXYGEN__)
extern PWMDriver PWM_GP16C2T2;
#endif

#if ES32_PWM_USE_GP16C2T3 && !defined(__DOXYGEN__)
extern PWMDriver PWM_GP16C2T3;
#endif

#if ES32_PWM_USE_GP16C2T4 && !defined(__DOXYGEN__)
extern PWMDriver PWM_GP16C2T4;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void pwm_lld_init(void);
  void pwm_lld_start(PWMDriver *pwmp);
  void pwm_lld_stop(PWMDriver *pwmp);
  void pwm_lld_enable_channel(PWMDriver *pwmp,
                              pwmchannel_t channel,
                              pwmcnt_t width);
  void pwm_lld_disable_channel(PWMDriver *pwmp, pwmchannel_t channel);
  void pwm_lld_enable_periodic_notification(PWMDriver *pwmp);
  void pwm_lld_disable_periodic_notification(PWMDriver *pwmp);
  void pwm_lld_enable_channel_notification(PWMDriver *pwmp,
                                           pwmchannel_t channel);
  void pwm_lld_disable_channel_notification(PWMDriver *pwmp,
                                            pwmchannel_t channel);
  void pwm_lld_serve_interrupt(PWMDriver *pwmp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_PWM == TRUE */

#endif /* HAL_PWM_LLD_H */

/** @} */
