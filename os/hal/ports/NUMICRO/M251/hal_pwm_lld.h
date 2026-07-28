/*
    Copyright (C) 2020 Alex Lewontin
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
 * @file    M251/hal_pwm_lld.h
 * @brief   M251/M252 PWM subsystem low level driver header.
 *
 * @addtogroup PWM
 * @{
 */

#ifndef HAL_PWM_LLD_H
#define HAL_PWM_LLD_H

#if (HAL_USE_PWM == TRUE) || defined(__DOXYGEN__)

#include "m251_registry.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Number of PWM channels per PWM driver.
 */
#define PWM_CHANNELS                        6U

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    M251 PWM configuration options
 * @{
 */

/**
 * @brief   PWMD1 driver enable switch.
 * @details If set to @p TRUE the support for BPWM0 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(M251_PWM_USE_BPWM0) || defined(__DOXYGEN__)
#define M251_PWM_USE_BPWM0                       FALSE
#endif

/**
 * @brief   PWMD2 driver enable switch.
 * @details If set to @p TRUE the support for BPWM1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(M251_PWM_USE_BPWM1) || defined(__DOXYGEN__)
#define M251_PWM_USE_BPWM1                       FALSE
#endif

/**
 * @brief   BPWM0 interrupt priority.
 * @note    The default is 3.
 */
#if !defined(M251_PWM_BPWM0_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define M251_PWM_BPWM0_IRQ_PRIORITY              3
#endif

/**
 * @brief   BPWM1 interrupt priority.
 * @note    The default is 3.
 */
#if !defined(M251_PWM_BPWM1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define M251_PWM_BPWM1_IRQ_PRIORITY              3
#endif
/** @}*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if M251_PWM_USE_BPWM0 && !M251_HAS_BPWM0
#error "BPWM0 not present in the selected device"
#endif

#if M251_PWM_USE_BPWM1 && !M251_HAS_BPWM1
#error "BPWM1 not present in the selected device"
#endif

#if !(M251_PWM_USE_BPWM0 || M251_PWM_USE_BPWM1)
#error "PWM driver activated but no BPWM peripheral assigned"
#endif

#if M251_PWM_USE_BPWM0 &&                                                   \
    !OSAL_IRQ_IS_VALID_PRIORITY(M251_PWM_BPWM0_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to BPWM0"
#endif

#if M251_PWM_USE_BPWM1 &&                                                   \
    !OSAL_IRQ_IS_VALID_PRIORITY(M251_PWM_BPWM1_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to BPWM1"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/** @brief Type of a PWM mode.*/
typedef uint32_t pwmmode_t;

/** @brief Type of a PWM channel.*/
typedef uint8_t pwmchannel_t;

/** @brief Type of a channel mask.*/
typedef uint32_t pwmchnmsk_t;

/** @brief Type of a PWM counter.*/
typedef uint32_t pwmcnt_t;

/**
 * @brief   Type of a structure representing a PWM driver.
 */
typedef struct PWMDriver PWMDriver;

/**
 * @brief   PWM notification callback type.
 *
 * @param[in] pwmp      pointer to the @p PWMDriver object
 */
typedef void (*pwmcallback_t)(PWMDriver *pwmp);

/**
 * @brief   Type of a PWM channel configuration structure.
 */
typedef struct {
  /** @brief Channel active logic level.*/
  pwmmode_t     mode;
  /**
   * @brief   Channel callback pointer.
   * @note    This callback is invoked on the channel compare event.
   */
  pwmcallback_t callback;
} PWMChannelConfig;

/**
 * @brief   Type of a PWM driver configuration structure.
 */
typedef struct {
  /** @brief Timer clock in Hz.*/
  uint32_t        frequency;
  /** @brief PWM period in ticks.*/
  pwmcnt_t        period;
  /**
   * @brief   Periodic callback pointer.
   * @note    This callback is invoked on PWM counter reset.
   */
  pwmcallback_t   callback;
  /** @brief Channel configurations.*/
  PWMChannelConfig channels[PWM_CHANNELS];
} PWMConfig;

/**
 * @brief   Structure representing a PWM driver.
 */
struct PWMDriver {
  /** @brief Driver state.*/
  pwmstate_t         state;
  /** @brief Current driver configuration data.*/
  const PWMConfig    *config;
  /** @brief Current PWM period in ticks.*/
  pwmcnt_t           period;
  /** @brief Mask of the enabled channels.*/
  pwmchnmsk_t        enabled;
  /** @brief Number of channels in this instance.*/
  pwmchannel_t       channels;
  /** @brief Pointer to the associated BPWM registers.*/
  BPWM_T             *bpwm;
  /** @brief BPWM input clock in Hz.*/
  uint32_t           clock;
  /** @brief BPWM clock divider.*/
  uint16_t           clock_divisor;
};

#if (M251_PWM_USE_BPWM0 == TRUE) || defined(__DOXYGEN__)
extern PWMDriver PWMD1;
#endif

#if (M251_PWM_USE_BPWM1 == TRUE) || defined(__DOXYGEN__)
extern PWMDriver PWMD2;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void pwm_lld_init(void);
  void pwm_lld_start(PWMDriver *pwmp);
  void pwm_lld_stop(PWMDriver *pwmp);
  void pwm_lld_change_period(PWMDriver *pwmp, pwmcnt_t period);
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
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_PWM == TRUE */

#endif /* HAL_PWM_LLD_H */

/** @}*/
