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
 * @file    TMRv1/hal_pwm_lld.h
 * @brief   AT32 PWM subsystem low level driver header.
 *
 * @addtogroup PWM
 * @{
 */

#ifndef HAL_PWM_LLD_H
#define HAL_PWM_LLD_H

#if HAL_USE_PWM || defined(__DOXYGEN__)

#include "at32_tmr.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Number of PWM channels per PWM driver.
 */
#define PWM_CHANNELS                            AT32_TMR_MAX_CHANNELS

/**
 * @name    AT32-specific PWM complementary output mode macros
 * @{
 */
/**
 * @brief   Complementary output modes mask.
 * @note    This is an AT32-specific setting.
 */
#define PWM_COMPLEMENTARY_OUTPUT_MASK           0xF0

/**
 * @brief   Complementary output not driven.
 * @note    This is an AT32-specific setting.
 */
#define PWM_COMPLEMENTARY_OUTPUT_DISABLED       0x00

/**
 * @brief   Complementary output, active is logic level one.
 * @note    This is an AT32-specific setting.
 * @note    This setting is only available if the timer supports the
 *          BRK register.
 */
#define PWM_COMPLEMENTARY_OUTPUT_ACTIVE_HIGH    0x10

/**
 * @brief   Complementary output, active is logic level zero.
 * @note    This is an AT32-specific setting.
 * @note    This setting is only available if the timer supports the
 *          BRK register.
 */
#define PWM_COMPLEMENTARY_OUTPUT_ACTIVE_LOW     0x20
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
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_PWM_USE_TMR1) || defined(__DOXYGEN__)
#define AT32_PWM_USE_TMR1                   FALSE
#endif

/**
 * @brief   PWMD2 driver enable switch.
 * @details If set to @p TRUE the support for PWMD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_PWM_USE_TMR2) || defined(__DOXYGEN__)
#define AT32_PWM_USE_TMR2                   FALSE
#endif

/**
 * @brief   PWMD3 driver enable switch.
 * @details If set to @p TRUE the support for PWMD3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_PWM_USE_TMR3) || defined(__DOXYGEN__)
#define AT32_PWM_USE_TMR3                   FALSE
#endif

/**
 * @brief   PWMD4 driver enable switch.
 * @details If set to @p TRUE the support for PWMD4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_PWM_USE_TMR4) || defined(__DOXYGEN__)
#define AT32_PWM_USE_TMR4                   FALSE
#endif

/**
 * @brief   PWMD5 driver enable switch.
 * @details If set to @p TRUE the support for PWMD5 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_PWM_USE_TMR5) || defined(__DOXYGEN__)
#define AT32_PWM_USE_TMR5                   FALSE
#endif

/**
 * @brief   PWMD9 driver enable switch.
 * @details If set to @p TRUE the support for PWMD9 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_PWM_USE_TMR9) || defined(__DOXYGEN__)
#define AT32_PWM_USE_TMR9                   FALSE
#endif

/**
 * @brief   PWMD10 driver enable switch.
 * @details If set to @p TRUE the support for PWMD10 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_PWM_USE_TMR10) || defined(__DOXYGEN__)
#define AT32_PWM_USE_TMR10                  FALSE
#endif

/**
 * @brief   PWMD11 driver enable switch.
 * @details If set to @p TRUE the support for PWMD11 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_PWM_USE_TMR11) || defined(__DOXYGEN__)
#define AT32_PWM_USE_TMR11                  FALSE
#endif

/**
 * @brief   PWMD1 interrupt priority level setting.
 */
#if !defined(AT32_PWM_TMR1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_PWM_TMR1_IRQ_PRIORITY          7
#endif

/**
 * @brief   PWMD2 interrupt priority level setting.
 */
#if !defined(AT32_PWM_TMR2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_PWM_TMR2_IRQ_PRIORITY          7
#endif

/**
 * @brief   PWMD3 interrupt priority level setting.
 */
#if !defined(AT32_PWM_TMR3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_PWM_TMR3_IRQ_PRIORITY          7
#endif

/**
 * @brief   PWMD4 interrupt priority level setting.
 */
#if !defined(AT32_PWM_TMR4_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_PWM_TMR4_IRQ_PRIORITY          7
#endif

/**
 * @brief   PWMD5 interrupt priority level setting.
 */
#if !defined(AT32_PWM_TMR5_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_PWM_TMR5_IRQ_PRIORITY          7
#endif

/**
 * @brief   PWMD9 interrupt priority level setting.
 */
#if !defined(AT32_PWM_TMR9_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_PWM_TMR9_IRQ_PRIORITY          7
#endif

/**
 * @brief   PWMD10 interrupt priority level setting.
 */
#if !defined(AT32_PWM_TMR10_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_PWM_TMR10_IRQ_PRIORITY         7
#endif

/**
 * @brief   PWMD11 interrupt priority level setting.
 */
#if !defined(AT32_PWM_TMR11_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_PWM_TMR11_IRQ_PRIORITY         7
#endif
/** @} */

/*===========================================================================*/
/* Configuration checks.                                                     */
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

#if AT32_PWM_USE_TMR1 && !AT32_HAS_TMR1
#error "TMR1 not present in the selected device"
#endif

#if AT32_PWM_USE_TMR2 && !AT32_HAS_TMR2
#error "TMR2 not present in the selected device"
#endif

#if AT32_PWM_USE_TMR3 && !AT32_HAS_TMR3
#error "TMR3 not present in the selected device"
#endif

#if AT32_PWM_USE_TMR4 && !AT32_HAS_TMR4
#error "TMR4 not present in the selected device"
#endif

#if AT32_PWM_USE_TMR5 && !AT32_HAS_TMR5
#error "TMR5 not present in the selected device"
#endif

#if AT32_PWM_USE_TMR9 && !AT32_HAS_TMR9
#error "TMR9 not present in the selected device"
#endif

#if AT32_PWM_USE_TMR10 && !AT32_HAS_TMR10
#error "TMR10 not present in the selected device"
#endif

#if AT32_PWM_USE_TMR11 && !AT32_HAS_TMR11
#error "TMR11 not present in the selected device"
#endif

#if !AT32_PWM_USE_TMR1  && !AT32_PWM_USE_TMR2  &&                           \
    !AT32_PWM_USE_TMR3  && !AT32_PWM_USE_TMR4  &&                           \
    !AT32_PWM_USE_TMR5  && !AT32_PWM_USE_TMR9  &&                           \
    !AT32_PWM_USE_TMR10 && !AT32_PWM_USE_TMR11
#error "PWM driver activated but no TMR peripheral assigned"
#endif

/* Checks on allocation of TMRx units.*/
#if AT32_PWM_USE_TMR1
#if defined(AT32_TMR1_IS_USED)
#error "PWMD1 requires TMR1 but the timer is already used"
#else
#define AT32_TMR1_IS_USED
#endif
#endif

#if AT32_PWM_USE_TMR2
#if defined(AT32_TMR2_IS_USED)
#error "PWMD2 requires TMR2 but the timer is already used"
#else
#define AT32_TMR2_IS_USED
#endif
#endif

#if AT32_PWM_USE_TMR3
#if defined(AT32_TMR3_IS_USED)
#error "PWMD3 requires TMR3 but the timer is already used"
#else
#define AT32_TMR3_IS_USED
#endif
#endif

#if AT32_PWM_USE_TMR4
#if defined(AT32_TMR4_IS_USED)
#error "PWMD4 requires TMR4 but the timer is already used"
#else
#define AT32_TMR4_IS_USED
#endif
#endif

#if AT32_PWM_USE_TMR5
#if defined(AT32_TMR5_IS_USED)
#error "PWMD5 requires TMR5 but the timer is already used"
#else
#define AT32_TMR5_IS_USED
#endif
#endif

#if AT32_PWM_USE_TMR9
#if defined(AT32_TMR9_IS_USED)
#error "PWMD9 requires TMR9 but the timer is already used"
#else
#define AT32_TMR9_IS_USED
#endif
#endif

#if AT32_PWM_USE_TMR10
#if defined(AT32_TMR10_IS_USED)
#error "PWMD10 requires TMR10 but the timer is already used"
#else
#define AT32_TMR10_IS_USED
#endif
#endif

#if AT32_PWM_USE_TMR11
#if defined(AT32_TMR11_IS_USED)
#error "PWMD11 requires TMR11 but the timer is already used"
#else
#define AT32_TMR11_IS_USED
#endif
#endif

/* IRQ priority checks.*/
#if AT32_PWM_USE_TMR1 && !defined(AT32_TMR1_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_PWM_TMR1_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR1"
#endif

#if AT32_PWM_USE_TMR2 && !defined(AT32_TMR2_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_PWM_TMR2_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR2"
#endif

#if AT32_PWM_USE_TMR3 && !defined(AT32_TMR3_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_PWM_TMR3_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR3"
#endif

#if AT32_PWM_USE_TMR4 && !defined(AT32_TMR4_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_PWM_TMR4_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR4"
#endif

#if AT32_PWM_USE_TMR5 && !defined(AT32_TMR5_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_PWM_TMR5_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR5"
#endif

#if AT32_PWM_USE_TMR9 && !defined(AT32_TMR9_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_PWM_TMR9_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR9"
#endif

#if AT32_PWM_USE_TMR10 && !defined(AT32_TMR10_SUPPRESS_ISR) &&              \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_PWM_TMR10_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR10"
#endif

#if AT32_PWM_USE_TMR11 && !defined(AT32_TMR11_SUPPRESS_ISR) &&              \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_PWM_TMR11_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR11"
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
   * @brief TMR CTRL2 register initialization data.
   * @note  The value of this field should normally be equal to zero.
   */
  uint32_t                  ctrl2;
  /**
   * @brief TMR BRK (break & dead-time) register initialization data.
   * @note  The value of this field should normally be equal to zero.
   */                                                                     \
   uint32_t                 brk;
   /**
    * @brief TMR IDEN register initialization data.
    * @note  The value of this field should normally be equal to zero.
    * @note  Only the DMA-related bits can be specified in this field.
    */
   uint32_t                 iden;
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
   * @brief Presence of BRK register.
   */
  bool                      has_brk;
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
  ((pwmp)->tmr->PR = ((period) - 1))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if AT32_PWM_USE_TMR1 && !defined(__DOXYGEN__)
extern PWMDriver PWMD1;
#endif

#if AT32_PWM_USE_TMR2 && !defined(__DOXYGEN__)
extern PWMDriver PWMD2;
#endif

#if AT32_PWM_USE_TMR3 && !defined(__DOXYGEN__)
extern PWMDriver PWMD3;
#endif

#if AT32_PWM_USE_TMR4 && !defined(__DOXYGEN__)
extern PWMDriver PWMD4;
#endif

#if AT32_PWM_USE_TMR5 && !defined(__DOXYGEN__)
extern PWMDriver PWMD5;
#endif

#if AT32_PWM_USE_TMR9 && !defined(__DOXYGEN__)
extern PWMDriver PWMD9;
#endif

#if AT32_PWM_USE_TMR10 && !defined(__DOXYGEN__)
extern PWMDriver PWMD10;
#endif

#if AT32_PWM_USE_TMR11 && !defined(__DOXYGEN__)
extern PWMDriver PWMD11;
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
