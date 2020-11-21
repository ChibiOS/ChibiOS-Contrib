/*
    Copyright (C) 2019 /u/KeepItUnder

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
 * @file    TIMv1/hal_pwm_lld.h
 * @brief   PWM subsystem low level driver header.
 *
 * @addtogroup PWM
 * @{
 */

#ifndef HAL_PWM_LLD_H
#define HAL_PWM_LLD_H

// #if HAL_USE_PWM || defined(__DOXYGEN__)

// #include "stm32_tim.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Number of PWM channels per PWM driver.
 */
#define PWM_CHANNELS                            (4)

#define PWM_CH0                                 0x0ul
#define PWM_CH1                                 0x1ul
#define PWM_CH2                                 0x2ul
#define PWM_CH3                                 0x3ul

#define PWM_EDGE_ALIGNED                        (0x0ul)                     /*!< Edge aligned */
#define PWM_CENTER_ALIGNED                      (0x01ul)                    /*!< Center aligned */

#define PWM_CLK_DIV_1                           (0x04ul)                    /*!< Divide by 1 */
#define PWM_CLK_DIV_2                           (0x0ul)                     /*!< Divide by 2 */
#define PWM_CLK_DIV_4                           (0x01ul)                    /*!< Divide by 4 */
#define PWM_CLK_DIV_8                           (0x02ul)                    /*!< Divide by 8 */
#define PWM_CLK_DIV_16                          (0x03ul)                    /*!< Divide by 16 */

#define PWM_PERIOD_INT_UNDERFLOW                (0)                         /*!< Period interrupt - counter underflow */
#define PWM_PERIOD_INT_MATCH_CNR                (PWM_PIER_INT01TYPE_Msk)    /*!< Period interrupt - counter matches CNR */
#define PWM_CAPTURE_INT_RISING_LATCH            (PWM_CCR0_CRL_IE0_Msk)      /*!< Capture interrupt - rising latch */
#define PWM_CAPTURE_INT_FALLING_LATCH           (PWM_CCR0_CFL_IE0_Msk)      /*!< Capture interrupt - falling latch */

/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/


/*===========================================================================*/
/* Configuration checks.                                                     */
/*===========================================================================*/


/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/


/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/


/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/


#ifdef __cplusplus
extern "C" {
#endif
  // void pwm_lld_init(void);
  // void pwm_lld_start(PWMDriver *pwmp);
  // void pwm_lld_stop(PWMDriver *pwmp);
  // void pwm_lld_enable_channel(PWMDriver *pwmp,
  //                             pwmchannel_t channel,
  //                             pwmcnt_t width);
  // void pwm_lld_disable_channel(PWMDriver *pwmp, pwmchannel_t channel);
  // void pwm_lld_enable_periodic_notification(PWMDriver *pwmp);
  // void pwm_lld_disable_periodic_notification(PWMDriver *pwmp);
  // void pwm_lld_enable_channel_notification(PWMDriver *pwmp,
  //                                          pwmchannel_t channel);
  // void pwm_lld_disable_channel_notification(PWMDriver *pwmp,
  //                                           pwmchannel_t channel);
  // void pwm_lld_serve_interrupt(PWMDriver *pwmp);

  void pwm_lld_enable_period_int(PWM_T *pwm, uint32_t pwmChannel,  uint32_t periodType);
  void pwm_lld_disable_period_int(PWM_T *pwm, uint32_t pwmChannel);
  void pwm_lld_start(PWM_T *pwm, uint32_t mask);
  void pwm_lld_clear_period_int(PWM_T *pwm, uint32_t pwmChannel);
  uint32_t pwm_lld_get_period_int(PWM_T *pwm, uint32_t pwmChannel);
  uint32_t pwm_lld_config_output_channel(PWM_T *pwm, uint32_t channel, uint32_t freq, uint32_t duty);

#ifdef __cplusplus
}
#endif

// #endif /* HAL_USE_PWM */

#endif /* HAL_PWM_LLD_H */

/** @} */
