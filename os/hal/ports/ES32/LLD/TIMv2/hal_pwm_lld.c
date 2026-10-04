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
 * @file    hal_pwm_lld.c
 * @brief   ES32 PWM subsystem low level driver source.
 *
 * @addtogroup PWM
 * @{
 */

#include "hal.h"

#if (HAL_USE_PWM == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   PWM_AD16C4T1 driver identifier.
 * @note    The driver PWM_AD16C4T1 allocates the complex timer AD16C4T1 when enabled.
 */
#if ES32_PWM_USE_AD16C4T1 || defined(__DOXYGEN__)
PWMDriver PWM_AD16C4T1;
#endif

/**
 * @brief   PWM_GP32C4T1 driver identifier.
 * @note    The driver PWM_GP32C4T1 allocates the timer GP32C4T1 when enabled.
 */
#if ES32_PWM_USE_GP32C4T1 || defined(__DOXYGEN__)
PWMDriver PWM_GP32C4T1;
#endif

/**
 * @brief   PWM_GP16C4T1 driver identifier.
 * @note    The driver PWM_GP16C4T1 allocates the timer GP16C4T1 when enabled.
 */
#if ES32_PWM_USE_GP16C4T1 || defined(__DOXYGEN__)
PWMDriver PWM_GP16C4T1;
#endif

/**
 * @brief   PWM_GP16C4T2 driver identifier.
 * @note    The driver PWM_GP16C4T2 allocates the timer GP16C4T2 when enabled.
 */
#if ES32_PWM_USE_GP16C4T2 || defined(__DOXYGEN__)
PWMDriver PWM_GP16C4T2;
#endif

/**
 * @brief   PWM_GP16C4T3 driver identifier.
 * @note    The driver PWM_GP16C4T3 allocates the timer GP16C4T3 when enabled.
 */
#if ES32_PWM_USE_GP16C4T3 || defined(__DOXYGEN__)
PWMDriver PWM_GP16C4T3;
#endif

/**
 * @brief   PWM_GP16C2T1 driver identifier.
 * @note    The driver PWM_GP16C2T1 allocates the timer GP16C2T1 when enabled.
 */
#if ES32_PWM_USE_GP16C2T1 || defined(__DOXYGEN__)
PWMDriver PWM_GP16C2T1;
#endif

/**
 * @brief   PWM_GP16C2T2 driver identifier.
 * @note    The driver PWM_GP16C2T2 allocates the timer GP16C2T2 when enabled.
 */
#if ES32_PWM_USE_GP16C2T2 || defined(__DOXYGEN__)
PWMDriver PWM_GP16C2T2;
#endif

/**
 * @brief   PWM_GP16C2T3 driver identifier.
 * @note    The driver PWM_GP16C2T3 allocates the timer GP16C2T3 when enabled.
 */
#if ES32_PWM_USE_GP16C2T3 || defined(__DOXYGEN__)
PWMDriver PWM_GP16C2T3;
#endif

/**
 * @brief   PWM_GP16C2T4 driver identifier.
 * @note    The driver PWM_GP16C2T4 allocates the timer GP16C2T4 when enabled.
 */
#if ES32_PWM_USE_GP16C2T4 || defined(__DOXYGEN__)
PWMDriver PWM_GP16C2T4;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level PWM driver initialization.
 *
 * @notapi
 */
void pwm_lld_init(void) {

}

/**
 * @brief   Configures and activates the PWM peripheral.
 * @note    Starting a driver that is already in the @p PWM_READY state
 *          disables all the active channels.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_start(PWMDriver *pwmp) {
  
}

/**
 * @brief   Deactivates the PWM peripheral.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_stop(PWMDriver *pwmp) {

}

/**
 * @brief   Enables a PWM channel.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @post    The channel is active using the specified configuration.
 * @note    The function has effect at the next cycle start.
 * @note    Channel notification is not enabled.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 * @param[in] width     PWM pulse width as clock pulses number
 *
 * @notapi
 */
void pwm_lld_enable_channel(PWMDriver *pwmp,
                            pwmchannel_t channel,
                            pwmcnt_t width) {
						
}

/**
 * @brief   Disables a PWM channel and its notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @post    The channel is disabled and its output line returned to the
 *          idle state.
 * @note    The function has effect at the next cycle start.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 *
 * @notapi
 */
void pwm_lld_disable_channel(PWMDriver *pwmp, pwmchannel_t channel) {

}

/**
 * @brief   Enables the periodic activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @note    If the notification is already enabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_enable_periodic_notification(PWMDriver *pwmp) {
	
}

/**
 * @brief   Disables the periodic activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @note    If the notification is already disabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_disable_periodic_notification(PWMDriver *pwmp) {
	
}

/**
 * @brief   Enables a channel de-activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @pre     The channel must have been activated using @p pwmEnableChannel().
 * @note    If the notification is already enabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 *
 * @notapi
 */
void pwm_lld_enable_channel_notification(PWMDriver *pwmp,
                                         pwmchannel_t channel) {
											 
}

/**
 * @brief   Disables a channel de-activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @pre     The channel must have been activated using @p pwmEnableChannel().
 * @note    If the notification is already disabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 *
 * @notapi
 */
void pwm_lld_disable_channel_notification(PWMDriver *pwmp,
                                          pwmchannel_t channel) {
											  
}

/**
 * @brief   Common TIM2...TIM5,TIM9 IRQ handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_serve_interrupt(PWMDriver *pwmp) {
	
}

#endif /* HAL_USE_PWM == TRUE */

/** @} */
