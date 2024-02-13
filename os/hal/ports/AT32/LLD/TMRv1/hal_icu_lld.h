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
 * @file    TMRv1/hal_icu_lld.h
 * @brief   AT32 ICU subsystem low level driver header.
 *
 * @addtogroup ICU
 * @{
 */

#ifndef HAL_ICU_LLD_H
#define HAL_ICU_LLD_H

#if HAL_USE_ICU || defined(__DOXYGEN__)

#include "at32_tmr.h"

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
 * @brief   ICUD1 driver enable switch.
 * @details If set to @p TRUE the support for ICUD1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_ICU_USE_TMR1) || defined(__DOXYGEN__)
#define AT32_ICU_USE_TMR1                   FALSE
#endif

/**
 * @brief   ICUD2 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_ICU_USE_TMR2) || defined(__DOXYGEN__)
#define AT32_ICU_USE_TMR2                   FALSE
#endif

/**
 * @brief   ICUD3 driver enable switch.
 * @details If set to @p TRUE the support for ICUD3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_ICU_USE_TMR3) || defined(__DOXYGEN__)
#define AT32_ICU_USE_TMR3                   FALSE
#endif

/**
 * @brief   ICUD4 driver enable switch.
 * @details If set to @p TRUE the support for ICUD4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_ICU_USE_TMR4) || defined(__DOXYGEN__)
#define AT32_ICU_USE_TMR4                   FALSE
#endif

/**
 * @brief   ICUD5 driver enable switch.
 * @details If set to @p TRUE the support for ICUD5 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_ICU_USE_TMR5) || defined(__DOXYGEN__)
#define AT32_ICU_USE_TMR5                   FALSE
#endif

/**
 * @brief   ICUD9 driver enable switch.
 * @details If set to @p TRUE the support for ICUD9 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_ICU_USE_TMR9) || defined(__DOXYGEN__)
#define AT32_ICU_USE_TMR9                   FALSE
#endif

/**
 * @brief   ICUD10 driver enable switch.
 * @details If set to @p TRUE the support for ICUD10 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_ICU_USE_TMR10) || defined(__DOXYGEN__)
#define AT32_ICU_USE_TMR10                  FALSE
#endif

/**
 * @brief   ICUD11 driver enable switch.
 * @details If set to @p TRUE the support for ICUD11 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_ICU_USE_TMR11) || defined(__DOXYGEN__)
#define AT32_ICU_USE_TMR11                  FALSE
#endif

/**
 * @brief   ICUD1 interrupt priority level setting.
 */
#if !defined(AT32_ICU_TMR1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_ICU_TMR1_IRQ_PRIORITY          7
#endif

/**
 * @brief   ICUD2 interrupt priority level setting.
 */
#if !defined(AT32_ICU_TMR2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_ICU_TMR2_IRQ_PRIORITY          7
#endif

/**
 * @brief   ICUD3 interrupt priority level setting.
 */
#if !defined(AT32_ICU_TMR3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_ICU_TMR3_IRQ_PRIORITY          7
#endif

/**
 * @brief   ICUD4 interrupt priority level setting.
 */
#if !defined(AT32_ICU_TMR4_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_ICU_TMR4_IRQ_PRIORITY          7
#endif

/**
 * @brief   ICUD5 interrupt priority level setting.
 */
#if !defined(AT32_ICU_TMR5_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_ICU_TMR5_IRQ_PRIORITY          7
#endif

/**
 * @brief   ICUD9 interrupt priority level setting.
 */
#if !defined(AT32_ICU_TMR9_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_ICU_TMR9_IRQ_PRIORITY          7
#endif

/**
 * @brief   ICUD10 interrupt priority level setting.
 */
#if !defined(AT32_ICU_TMR10_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_ICU_TMR10_IRQ_PRIORITY         7
#endif

/**
 * @brief   ICUD11 interrupt priority level setting.
 */
#if !defined(AT32_ICU_TMR11_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_ICU_TMR11_IRQ_PRIORITY         7
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

#if AT32_ICU_USE_TMR1 && !AT32_HAS_TMR1
#error "TMR1 not present in the selected device"
#endif

#if AT32_ICU_USE_TMR2 && !AT32_HAS_TMR2
#error "TMR2 not present in the selected device"
#endif

#if AT32_ICU_USE_TMR3 && !AT32_HAS_TMR3
#error "TMR3 not present in the selected device"
#endif

#if AT32_ICU_USE_TMR4 && !AT32_HAS_TMR4
#error "TMR4 not present in the selected device"
#endif

#if AT32_ICU_USE_TMR5 && !AT32_HAS_TMR5
#error "TMR5 not present in the selected device"
#endif

#if AT32_ICU_USE_TMR9 && !AT32_HAS_TMR9
#error "TMR9 not present in the selected device"
#endif

#if AT32_ICU_USE_TMR10 && !AT32_HAS_TMR10
#error "TMR10 not present in the selected device"
#endif

#if AT32_ICU_USE_TMR11 && !AT32_HAS_TMR11
#error "TMR11 not present in the selected device"
#endif

#if !AT32_ICU_USE_TMR1  && !AT32_ICU_USE_TMR2  &&                           \
    !AT32_ICU_USE_TMR3  && !AT32_ICU_USE_TMR4  &&                           \
    !AT32_ICU_USE_TMR5  && !AT32_ICU_USE_TMR9  &&                           \
    !AT32_ICU_USE_TMR10 && !AT32_ICU_USE_TMR11
#error "ICU driver activated but no TMR peripheral assigned"
#endif

/* Checks on allocation of TMRx units.*/
#if AT32_ICU_USE_TMR1
#if defined(AT32_TMR1_IS_USED)
#error "ICUD1 requires TMR1 but the timer is already used"
#else
#define AT32_TMR1_IS_USED
#endif
#endif

#if AT32_ICU_USE_TMR2
#if defined(AT32_TMR2_IS_USED)
#error "ICUD2 requires TMR2 but the timer is already used"
#else
#define AT32_TMR2_IS_USED
#endif
#endif

#if AT32_ICU_USE_TMR3
#if defined(AT32_TMR3_IS_USED)
#error "ICUD3 requires TMR3 but the timer is already used"
#else
#define AT32_TMR3_IS_USED
#endif
#endif

#if AT32_ICU_USE_TMR4
#if defined(AT32_TMR4_IS_USED)
#error "ICUD4 requires TMR4 but the timer is already used"
#else
#define AT32_TMR4_IS_USED
#endif
#endif

#if AT32_ICU_USE_TMR5
#if defined(AT32_TMR5_IS_USED)
#error "ICUD5 requires TMR5 but the timer is already used"
#else
#define AT32_TMR5_IS_USED
#endif
#endif

#if AT32_ICU_USE_TMR9
#if defined(AT32_TMR9_IS_USED)
#error "ICUD9 requires TMR9 but the timer is already used"
#else
#define AT32_TMR9_IS_USED
#endif
#endif

#if AT32_ICU_USE_TMR10
#if defined(AT32_TMR10_IS_USED)
#error "ICUD10 requires TMR10 but the timer is already used"
#else
#define AT32_TMR10_IS_USED
#endif
#endif

#if AT32_ICU_USE_TMR11
#if defined(AT32_TMR11_IS_USED)
#error "ICUD11 requires TMR11 but the timer is already used"
#else
#define AT32_TMR11_IS_USED
#endif
#endif

/* IRQ priority checks.*/
#if AT32_ICU_USE_TMR1 && !defined(AT32_TMR1_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_ICU_TMR1_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR1"
#endif

#if AT32_ICU_USE_TMR2 && !defined(AT32_TMR2_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_ICU_TMR2_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR2"
#endif

#if AT32_ICU_USE_TMR3 && !defined(AT32_TMR3_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_ICU_TMR3_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR3"
#endif

#if AT32_ICU_USE_TMR4 && !defined(AT32_TMR4_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_ICU_TMR4_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR4"
#endif

#if AT32_ICU_USE_TMR5 && !defined(AT32_TMR5_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_ICU_TMR5_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR5"
#endif

#if AT32_ICU_USE_TMR9 && !defined(AT32_TMR9_SUPPRESS_ISR) &&                \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_ICU_TMR9_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR9"
#endif

#if AT32_ICU_USE_TMR10 && !defined(AT32_TMR10_SUPPRESS_ISR) &&              \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_ICU_TMR10_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR10"
#endif

#if AT32_ICU_USE_TMR11 && !defined(AT32_TMR11_SUPPRESS_ISR) &&              \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_ICU_TMR11_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to TMR11"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   ICU driver mode.
 */
typedef enum {
  ICU_INPUT_ACTIVE_HIGH = 0,        /**< Trigger on rising edge.            */
  ICU_INPUT_ACTIVE_LOW = 1,         /**< Trigger on falling edge.           */
} icumode_t;

/**
 * @brief   ICU frequency type.
 */
typedef uint32_t icufreq_t;

/**
 * @brief   ICU channel type.
 */
typedef enum {
  ICU_CHANNEL_1 = 0,              /**< Use TMRxCH1.      */
  ICU_CHANNEL_2 = 1,              /**< Use TMRxCH2.      */
} icuchannel_t;

/**
 * @brief   ICU counter type.
 */
typedef uint32_t icucnt_t;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /**
   * @brief   Driver mode.
   */
  icumode_t                 mode;
  /**
   * @brief   Timer clock in Hz.
   * @note    The low level can use assertions in order to catch invalid
   *          frequency specifications.
   */
  icufreq_t                 frequency;
  /**
   * @brief   Callback for pulse width measurement.
   */
  icucallback_t             width_cb;
  /**
   * @brief   Callback for cycle period measurement.
   */
  icucallback_t             period_cb;
  /**
   * @brief   Callback for timer overflow.
   */
  icucallback_t             overflow_cb;
  /* End of the mandatory fields.*/
  /**
   * @brief   Timer input channel to be used.
   * @note    Only inputs TMRx 1 and 2 are supported.
   */
  icuchannel_t              channel;
  /**
   * @brief TMR IDEN register initialization data.
   * @note  The value of this field should normally be equal to zero.
   * @note  Only the DMA-related bits can be specified in this field.
   */
  uint32_t                  iden;
  /**
   * @brief TMR PR register initialization data.
   * @note  The value of this field should normally be equal to 0xFFFFFFFFU.
   */
  uint32_t                  pr;
} ICUConfig;

/**
 * @brief   Structure representing an ICU driver.
 */
struct ICUDriver {
  /**
   * @brief Driver state.
   */
  icustate_t                state;
  /**
   * @brief Current configuration data.
   */
  const ICUConfig           *config;
#if defined(ICU_DRIVER_EXT_FIELDS)
  ICU_DRIVER_EXT_FIELDS
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
  /**
   * @brief CDT register used for width capture.
   */
  volatile uint32_t         *wccrp;
  /**
   * @brief CDT register used for period capture.
   */
  volatile uint32_t         *pccrp;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the width of the latest pulse.
 * @details The pulse width is defined as number of ticks between the start
 *          edge and the stop edge.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 * @return              The number of ticks.
 *
 * @notapi
 */
#define icu_lld_get_width(icup) (*((icup)->wccrp) + 1)

/**
 * @brief   Returns the width of the latest cycle.
 * @details The cycle width is defined as number of ticks between a start
 *          edge and the next start edge.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 * @return              The number of ticks.
 *
 * @notapi
 */
#define icu_lld_get_period(icup) (*((icup)->pccrp) + 1)

/**
 * @brief   Check on notifications status.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 * @return              The notifications status.
 * @retval false        if notifications are not enabled.
 * @retval true         if notifications are enabled.
 *
 * @notapi
 */
#define icu_lld_are_notifications_enabled(icup)                             \
  (bool)(((icup)->tmr->IDEN & AT32_TMR_IDEN_IRQ_MASK) != 0)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if AT32_ICU_USE_TMR1 && !defined(__DOXYGEN__)
extern ICUDriver ICUD1;
#endif

#if AT32_ICU_USE_TMR2 && !defined(__DOXYGEN__)
extern ICUDriver ICUD2;
#endif

#if AT32_ICU_USE_TMR3 && !defined(__DOXYGEN__)
extern ICUDriver ICUD3;
#endif

#if AT32_ICU_USE_TMR4 && !defined(__DOXYGEN__)
extern ICUDriver ICUD4;
#endif

#if AT32_ICU_USE_TMR5 && !defined(__DOXYGEN__)
extern ICUDriver ICUD5;
#endif

#if AT32_ICU_USE_TMR9 && !defined(__DOXYGEN__)
extern ICUDriver ICUD9;
#endif

#if AT32_ICU_USE_TMR10 && !defined(__DOXYGEN__)
extern ICUDriver ICUD10;
#endif

#if AT32_ICU_USE_TMR11 && !defined(__DOXYGEN__)
extern ICUDriver ICUD11;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void icu_lld_init(void);
  void icu_lld_start(ICUDriver *icup);
  void icu_lld_stop(ICUDriver *icup);
  void icu_lld_start_capture(ICUDriver *icup);
  bool icu_lld_wait_capture(ICUDriver *icup);
  void icu_lld_stop_capture(ICUDriver *icup);
  void icu_lld_enable_notifications(ICUDriver *icup);
  void icu_lld_disable_notifications(ICUDriver *icup);
  void icu_lld_serve_interrupt(ICUDriver *icup);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_ICU */

#endif /* HAL_ICU_LLD_H */

/** @} */
