/*
    ChibiOS/RT - Copyright (C) 2006-2013 Giovanni Di Sirio

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
/*
   Rewritten by Emil Fresk (1/5 - 2014) for extended input capture
   functionality. And fix for spurious callbacks in the interrupt handler.
*/
   
#ifndef __EICU_LLD_H
#define __EICU_LLD_H

#include "stm32_tim.h"

#if HAL_USE_EICU || defined(__DOXYGEN__)

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
 * @brief   EICUD1 driver enable switch.
 * @details If set to @p TRUE the support for EICUD1 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(STM32_EICU_USE_TIM1) || defined(__DOXYGEN__)
#define STM32_EICU_USE_TIM1                  FALSE
#endif

/**
 * @brief   EICUD2 driver enable switch.
 * @details If set to @p TRUE the support for EICUD2 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(STM32_EICU_USE_TIM2) || defined(__DOXYGEN__)
#define STM32_EICU_USE_TIM2                  FALSE
#endif

/**
 * @brief   EICUD3 driver enable switch.
 * @details If set to @p TRUE the support for EICUD3 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(STM32_EICU_USE_TIM3) || defined(__DOXYGEN__)
#define STM32_EICU_USE_TIM3                  FALSE
#endif

/**
 * @brief   EICUD4 driver enable switch.
 * @details If set to @p TRUE the support for EICUD4 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(STM32_EICU_USE_TIM4) || defined(__DOXYGEN__)
#define STM32_EICU_USE_TIM4                  FALSE
#endif

/**
 * @brief   EICUD5 driver enable switch.
 * @details If set to @p TRUE the support for EICUD5 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(STM32_EICU_USE_TIM5) || defined(__DOXYGEN__)
#define STM32_EICU_USE_TIM5                  FALSE
#endif

/**
 * @brief   EICUD8 driver enable switch.
 * @details If set to @p TRUE the support for EICUD8 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(STM32_EICU_USE_TIM8) || defined(__DOXYGEN__)
#define STM32_EICU_USE_TIM8                  FALSE
#endif

/**
 * @brief   EICUD9 driver enable switch.
 * @details If set to @p TRUE the support for EICUD9 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(STM32_EICU_USE_TIM9) || defined(__DOXYGEN__)
#define STM32_EICU_USE_TIM9                  FALSE
#endif

/**
 * @brief   EICUD12 driver enable switch.
 * @details If set to @p TRUE the support for EICUD12 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(STM32_EICU_USE_TIM12) || defined(__DOXYGEN__)
#define STM32_EICU_USE_TIM12                 FALSE
#endif

/**
 * @brief   EICUD1 interrupt priority level setting.
 */
#if !defined(STM32_EICU_TIM1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define STM32_EICU_TIM1_IRQ_PRIORITY         7
#endif

/**
 * @brief   EICUD2 interrupt priority level setting.
 */
#if !defined(STM32_EICU_TIM2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define STM32_EICU_TIM2_IRQ_PRIORITY         7
#endif

/**
 * @brief   EICUD3 interrupt priority level setting.
 */
#if !defined(STM32_EICU_TIM3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define STM32_EICU_TIM3_IRQ_PRIORITY         7
#endif

/**
 * @brief   EICUD4 interrupt priority level setting.
 */
#if !defined(STM32_EICU_TIM4_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define STM32_EICU_TIM4_IRQ_PRIORITY         7
#endif

/**
 * @brief   EICUD5 interrupt priority level setting.
 */
#if !defined(STM32_EICU_TIM5_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define STM32_EICU_TIM5_IRQ_PRIORITY         7
#endif

/**
 * @brief   EICUD8 interrupt priority level setting.
 */
#if !defined(STM32_EICU_TIM8_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define STM32_EICU_TIM8_IRQ_PRIORITY         7
#endif

/**
 * @brief   EICUD9 interrupt priority level setting.
 */
#if !defined(STM32_EICU_TIM9_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define STM32_EICU_TIM9_IRQ_PRIORITY         7
#endif

/**
 * @brief   EICUD12 interrupt priority level setting.
 */
#if !defined(STM32_EICU_TIM12_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define STM32_EICU_TIM12_IRQ_PRIORITY        7
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if STM32_EICU_USE_TIM1 && !STM32_HAS_TIM1
#error "TIM1 not present in the selected device"
#endif

#if STM32_EICU_USE_TIM2 && !STM32_HAS_TIM2
#error "TIM2 not present in the selected device"
#endif

#if STM32_EICU_USE_TIM3 && !STM32_HAS_TIM3
#error "TIM3 not present in the selected device"
#endif

#if STM32_EICU_USE_TIM4 && !STM32_HAS_TIM4
#error "TIM4 not present in the selected device"
#endif

#if STM32_EICU_USE_TIM5 && !STM32_HAS_TIM5
#error "TIM5 not present in the selected device"
#endif

#if STM32_EICU_USE_TIM8 && !STM32_HAS_TIM8
#error "TIM8 not present in the selected device"
#endif

#if STM32_EICU_USE_TIM9 && !STM32_HAS_TIM9
#error "TIM9 not present in the selected device"
#endif

#if STM32_EICU_USE_TIM12 && !STM32_HAS_TIM12
#error "TIM12 not present in the selected device"
#endif

#if !STM32_EICU_USE_TIM1 && !STM32_EICU_USE_TIM2 &&                          \
    !STM32_EICU_USE_TIM3 && !STM32_EICU_USE_TIM4 &&                          \
    !STM32_EICU_USE_TIM5 && !STM32_EICU_USE_TIM8 &&                          \
    !STM32_EICU_USE_TIM9 && !STM32_EICU_USE_TIM12
#error "EICU driver activated but no TIM peripheral assigned"
#endif

#if STM32_EICU_USE_TIM1 &&                                                   \
    !CORTEX_IS_VALID_KERNEL_PRIORITY(STM32_EICU_TIM1_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TIM1"
#endif

#if STM32_EICU_USE_TIM2 &&                                                   \
    !CORTEX_IS_VALID_KERNEL_PRIORITY(STM32_EICU_TIM2_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TIM2"
#endif

#if STM32_EICU_USE_TIM3 &&                                                   \
    !CORTEX_IS_VALID_KERNEL_PRIORITY(STM32_EICU_TIM3_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TIM3"
#endif

#if STM32_EICU_USE_TIM4 &&                                                   \
    !CORTEX_IS_VALID_KERNEL_PRIORITY(STM32_EICU_TIM4_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TIM4"
#endif

#if STM32_EICU_USE_TIM5 &&                                                   \
    !CORTEX_IS_VALID_KERNEL_PRIORITY(STM32_EICU_TIM5_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TIM5"
#endif

#if STM32_EICU_USE_TIM8 &&                                                   \
    !CORTEX_IS_VALID_KERNEL_PRIORITY(STM32_EICU_TIM8_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TIM8"
#endif

#if STM32_EICU_USE_TIM9 &&                                                   \
    !CORTEX_IS_VALID_KERNEL_PRIORITY(STM32_EICU_TIM9_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TIM9"
#endif

#if STM32_EICU_USE_TIM12 &&                                                  \
    !CORTEX_IS_VALID_KERNEL_PRIORITY(STM32_EICU_TIM12_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TIM12"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/
/**
 * @brief   EICU driver mode.
 */
typedef enum {
  /**
   * @brief   Captures high speed signals.
   * @note    Only one input per timer possible.
   * @note    Needs at least 2 capture/compare channels in timer.
   */
  EICU_FAST,
  /**
   * @brief   Captures low speed signals.
   * @details Suggested for example for PWM or PPM signals from RC receiver.
   * @note    Only one input per capture/compare channel needed.
   */
  EICU_SLOW
} eicumode_t;

/**
 * @brief   Active level selector.
 */
typedef enum {
  EICU_INPUT_ACTIVE_HIGH = 0,       /**< Trigger on rising edge.            */
  EICU_INPUT_ACTIVE_LOW = 1,        /**< Trigger on falling edge.           */
} eicuactivelevel_t;

/**
 * @brief   Input type selector.
 */
typedef enum {
  EICU_INPUT_EDGE = 0,        /**< Measures time between consequent edges.*/
  EICU_INPUT_PULSE = 1,       /**< Measures pulse width.*/
  EICU_INPUT_BOTH = 2         /**< Measures both period and width. */
} eicucapturemode_t;

/**
 * @brief   EICU frequency type.
 */
typedef uint32_t eicufreq_t;

/**
 * @brief   EICU counter type.
 */
typedef uint32_t eicucnt_t;

/** 
 * @brief EICU captured width and (or) period.
 */
typedef struct {
  /**
   * @brief   Pulse width.
   */
  eicucnt_t               width;
  /**
   * @brief   Pulse period.
   */
  eicucnt_t               period;
} eicuresult_t;

/**
 * @brief EICU Capture Channel Config structure definition.
 */
typedef struct {
  /**
   * @brief   Specifies the active level of the input signal.
   */
  eicuactivelevel_t       alvl;
  /**
   * @brief   Specifies the channel capture mode.
   */
  eicucapturemode_t       mode;
  /**
   * @brief   Capture event callback. Used for PWM width, pulse width and
   *          pulse period capture event.
   */
  eicucallback_t          capture_cb;
} EICUChannelConfig;

/** 
 * @brief EICU Capture Channel Config structure definition.
 */
typedef struct {
  /**
   * @brief   Channel state for the internal state machine.
   */
  eicuchannelstate_t      state;
  /**
   * @brief   Cached value for pulse width calculation.
   */
  eicucnt_t               last_active;
  /**
   * @brief   Cached value for period calculation.
   */
  eicucnt_t               last_idle;
  /**
   * @brief   Pointer to Input Capture channel configuration.
   */
  const EICUChannelConfig *config;
  /**
   * @brief   CCR registers for width capture.
   */
  volatile uint32_t       *wccrp;
} EICUChannelDriver;

/**
 * @brief EICU Config structure definition.
 */
typedef struct {
  /**
   * @brief   Specifies the EICU capture mode.
   */
  eicumode_t              mode;
  /**
   * @brief   Specifies the Timer clock in Hz.
   */
  eicufreq_t              frequency;
  /**
   * @brief   Pointer to each Input Capture channel configuration.
   * @note    A NULL parameter indicates the channel as unused. 
   * @note    In PWM mode, only Channel 1 OR Channel 2 may be used.
   */
  const EICUChannelConfig *iccfgp[EICU_CHANNEL_ENUM_END];
  /**
   * @brief   Timer overflow event callback.
   * @note    Meaningful only when in @p EICU_FAST mode
   */
  eicucallback_t          overflow_cb;
  /**
   * @brief   TIM DIER register initialization data.
   */
  uint32_t                dier;
} EICUConfig;

/** 
 * @brief EICU Driver structure definition
 */
struct EICUDriver {
  /**
   * @brief   STM32 timer peripheral for Input Capture.
   */
  stm32_tim_t             *tim;
  /**
   * @brief   Driver state for the internal state machine.
   */
  eicustate_t             state;
  /**
   * @brief   Channels' data structures.
   */
  EICUChannelDriver       channel[EICU_CHANNEL_ENUM_END];
  /**
   * @brief   Timer base clock.
   */
  uint32_t                clock;
  /**
   * @brief   Pointer to configuration for the driver.
   */
  const EICUConfig        *config;
//  /**
//   * @brief   CCR registers for width capture.
//   */
//  volatile uint32_t       *wccrp[4];
  /**
   * @brief   CCR register for period capture.
   * @note    Only one is needed since only one PWM input per timer is allowed.
   */
  volatile uint32_t       *pccrp;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the width of the latest cycle.
 * @details The cycle width is defined as number of ticks between a start
 *          edge and the next start edge.
 *
 * @param[in] eicup     Pointer to the EICUDriver object.
 * @return              The number of ticks.
 *
 * @notapi
 */
#define eicu_lld_get_period_fast(eicup) (*((eicup)->pccrp) + 1)

/**
 * @brief   Returns the compare value of the latest cycle.
 *
 * @param[in] chp       Pointer to channel structure that fired the interrupt.
 * @return              The number of ticks.
 *
 * @notapi
 */
#define eicu_lld_get_compare(chp) (*((chp)->wccrp) + 1)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/
#if STM32_EICU_USE_TIM1 && !defined(__DOXYGEN__)
extern EICUDriver EICUD1;
#endif

#if STM32_EICU_USE_TIM2 && !defined(__DOXYGEN__)
extern EICUDriver EICUD2;
#endif

#if STM32_EICU_USE_TIM3 && !defined(__DOXYGEN__)
extern EICUDriver EICUD3;
#endif

#if STM32_EICU_USE_TIM4 && !defined(__DOXYGEN__)
extern EICUDriver EICUD4;
#endif

#if STM32_EICU_USE_TIM5 && !defined(__DOXYGEN__)
extern EICUDriver EICUD5;
#endif

#if STM32_EICU_USE_TIM8 && !defined(__DOXYGEN__)
extern EICUDriver EICUD8;
#endif

#if STM32_EICU_USE_TIM9 && !defined(__DOXYGEN__)
extern EICUDriver EICUD9;
#endif

#if STM32_EICU_USE_TIM12 && !defined(__DOXYGEN__)
extern EICUDriver EICUD12;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void eicu_lld_init(void);
  void eicu_lld_start(EICUDriver *eicup);
  void eicu_lld_stop(EICUDriver *eicup);
  void eicu_lld_enable(EICUDriver *eicup);
  void eicu_lld_disable(EICUDriver *eicup);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_EICU */

#endif /* __EICU_LLD_H */
