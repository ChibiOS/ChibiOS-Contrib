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
 * @file    CT/hal_pwm_lld.h
 * @brief   SN32 PWM subsystem low level driver header.
 *
 * @addtogroup PWM
 * @{
 */

#ifndef HAL_PWM_LLD_H
#define HAL_PWM_LLD_H

#if HAL_USE_PWM || defined(__DOXYGEN__)

#include "sn32_ct.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Number of PWM channels per PWM driver.
 */
#define PWM_CHANNELS                 SN32_CT16B1_CHANNELS

/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   PWMD1 driver enable switch.
 * @details If set to @p TRUE the support for PWMD1 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(SN32_PWM_USE_CT16B1) || defined(__DOXYGEN__)
#define SN32_PWM_USE_CT16B1                  FALSE
#endif

/**
 * @brief   PWMD1 interrupt priority level setting.
 */
#if !defined(SN32_PWM_CT16B1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SN32_PWM_CT16B1_IRQ_PRIORITY         2
#endif
/** @} */

/*===========================================================================*/
/* Configuration checks.                                                     */
/*===========================================================================*/

#if !defined(SN32_HAS_CT16B1)
#define SN32_HAS_CT16B1                      FALSE
#endif

#if SN32_PWM_USE_CT16B1 && !SN32_HAS_CT16B1
#error "CT16B1 not present in the selected device"
#endif

#if !SN32_PWM_USE_CT16B1
#error "PWM driver activated but no CT peripheral assigned"
#endif

/* Checks on allocation of CT units.*/
#if SN32_PWM_USE_CT16B1
#if defined(SN32_CT16B1_IS_USED)
#error "PWMD1 requires CT16B1 but the timer is already used"
#else
#define SN32_CT16B1_IS_USED
#endif
#endif

/* IRQ priority checks.*/
#if SN32_PWM_USE_CT16B1 && !defined(SN32_CT16B1_SUPPRESS_ISR) &&              \
    !OSAL_IRQ_IS_VALID_PRIORITY(SN32_PWM_CT16B1_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to CT16B1"
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
  /**
   * @brief CT16 PFPA register initialization data.
   * @note  The value of this field should normally be equal to zero.
   */
  uint8_t                  pfpamsk;
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
   * @brief CT16 CNTCTRL register initialization data.
   * @note  The value of this field should normally be equal to zero.
   */
  uint32_t                  cntctrl;
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
 * @brief   Changes the period of the PWM peripheral.
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
#if PWM_CHANNELS > 23
#define pwm_lld_change_period(pwmp, period)                                 \
  ((pwmp)->ct->MR24 = ((period) - 1))
#else
#define pwm_lld_change_period(pwmp, period)                                 \
  ((pwmp)->ct->MR23 = ((period) - 1))
#endif

/**
 * @brief   Changes the timer counter of the PWM peripheral.
 * @details This function changes the timer counter of a PWM unit that has
 *          already been activated using @p pwmStart().
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @post    The PWM unit timer counter is changed to the new value.
 * @note    The function overrides the TC value of the PWM peripheral
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] counter   new timer counter value in bits
 *
 * @notapi
 */
#define pwm_lld_change_counter(pwmp, counter)                                 \
  ((pwmp)->ct->TC = (counter))
/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if SN32_PWM_USE_CT16B1 && !defined(__DOXYGEN__)
extern PWMDriver PWMD1;
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

#endif /* HAL_USE_PWM */

#endif /* HAL_PWM_LLD_H */

/** @} */
