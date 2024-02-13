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
 * @file    SYSTICKv1/hal_st_lld.h
 * @brief   ST Driver subsystem low level driver header.
 * @details This header is designed to be include-able without having to
 *          include other files from the HAL.
 *
 * @addtogroup ST
 * @{
 */

#ifndef HAL_ST_LLD_H
#define HAL_ST_LLD_H

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
 * @brief   SysTick timer IRQ priority.
 */
#if !defined(AT32_ST_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_ST_IRQ_PRIORITY                8
#endif

/**
 * @brief   TIMx unit (by number) to be used for free running operations.
 * @note    You must select a 32 bits timer if a 32 bits @p systick_t type
 *          is required.
 * @note    Timers 2, 3, 4, 5, 9, 10 and 11 are supported.
 */
#if !defined(AT32_ST_USE_TIMER) || defined(__DOXYGEN__)
#define AT32_ST_USE_TIMER                   2
#endif

/**
 * @brief   Overrides the number of supported alarms.
 * @note    The default number of alarms is equal to the number of
 *          comparators in the timer, overriding it to one makes
 *          the driver a little faster and smaller. The kernel itself
 *          only needs one alarm, additional features could need more.
 * @note    Zero means do not override.
 * @note    This setting is only meaningful in free running mode, in
 *          tick mode there are no alarms.
 */
#if !defined(AT32_ST_OVERRIDE_ALARMS) || defined(__DOXYGEN__)
#define AT32_ST_OVERRIDE_ALARMS             1
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* This has to go after transition to shared handlers is complete for all
   platforms.*/
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
/* End of checks to be removed.*/

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING

#if AT32_ST_USE_TIMER == 2

#if defined(AT32_TMR2_IS_USED)
#error "ST requires TMR2 but the timer is already used"
#else
#define AT32_TMR2_IS_USED
#endif

#if defined(AT32_TMR2_SUPPRESS_ISR)
#define AT32_SYSTICK_SUPPRESS_ISR
#endif

#define AT32_ST_TMR                         AT32_TMR2
#define ST_LLD_NUM_ALARMS                   AT32_TMR2_CHANNELS
#define AT32_ST_USE_SYSTICK                 FALSE
#define AT32_ST_USE_TMR2                    TRUE
#define AT32_ST_USE_TMR3                    FALSE
#define AT32_ST_USE_TMR4                    FALSE
#define AT32_ST_USE_TMR5                    FALSE
#define AT32_ST_USE_TMR9                    FALSE
#define AT32_ST_USE_TMR10                   FALSE
#define AT32_ST_USE_TMR11                   FALSE

#elif AT32_ST_USE_TIMER == 3

#if defined(AT32_TMR3_IS_USED)
#error "ST requires TMR3 but the timer is already used"
#else
#define AT32_TMR3_IS_USED
#endif

#if defined(AT32_TMR3_SUPPRESS_ISR)
#define AT32_SYSTICK_SUPPRESS_ISR
#endif

#define AT32_ST_TMR                         AT32_TMR3
#define ST_LLD_NUM_ALARMS                   AT32_TMR3_CHANNELS
#define AT32_ST_USE_SYSTICK                 FALSE
#define AT32_ST_USE_TMR2                    FALSE
#define AT32_ST_USE_TMR3                    TRUE
#define AT32_ST_USE_TMR4                    FALSE
#define AT32_ST_USE_TMR5                    FALSE
#define AT32_ST_USE_TMR9                    FALSE
#define AT32_ST_USE_TMR10                   FALSE
#define AT32_ST_USE_TMR11                   FALSE

#elif AT32_ST_USE_TIMER == 4

#if defined(AT32_TMR4_IS_USED)
#error "ST requires TMR4 but the timer is already used"
#else
#define AT32_TMR4_IS_USED
#endif

#if defined(AT32_TMR4_SUPPRESS_ISR)
#define AT32_SYSTICK_SUPPRESS_ISR
#endif

#define AT32_ST_TMR                         AT32_TMR4
#define ST_LLD_NUM_ALARMS                   AT32_TMR4_CHANNELS
#define AT32_ST_USE_SYSTICK                 FALSE
#define AT32_ST_USE_TMR2                    FALSE
#define AT32_ST_USE_TMR3                    FALSE
#define AT32_ST_USE_TMR4                    TRUE
#define AT32_ST_USE_TMR5                    FALSE
#define AT32_ST_USE_TMR9                    FALSE
#define AT32_ST_USE_TMR10                   FALSE
#define AT32_ST_USE_TMR11                   FALSE

#elif AT32_ST_USE_TIMER == 5

#if defined(AT32_TMR5_IS_USED)
#error "ST requires TMR5 but the timer is already used"
#else
#define AT32_TMR5_IS_USED
#endif

#if defined(AT32_TMR5_SUPPRESS_ISR)
#define AT32_SYSTICK_SUPPRESS_ISR
#endif

#define AT32_ST_TMR                         AT32_TMR5
#define ST_LLD_NUM_ALARMS                   AT32_TMR5_CHANNELS
#define AT32_ST_USE_SYSTICK                 FALSE
#define AT32_ST_USE_TMR2                    FALSE
#define AT32_ST_USE_TMR3                    FALSE
#define AT32_ST_USE_TMR4                    FALSE
#define AT32_ST_USE_TMR5                    TRUE
#define AT32_ST_USE_TMR9                    FALSE
#define AT32_ST_USE_TMR10                   FALSE
#define AT32_ST_USE_TMR11                   FALSE

#elif AT32_ST_USE_TIMER == 9

#if defined(AT32_TMR9_IS_USED)
#error "ST requires TMR9 but the timer is already used"
#else
#define AT32_TMR9_IS_USED
#endif

#if defined(AT32_TMR9_SUPPRESS_ISR)
#define AT32_SYSTICK_SUPPRESS_ISR
#endif

#define AT32_ST_TMR                         AT32_TMR9
#define ST_LLD_NUM_ALARMS                   AT32_TMR9_CHANNELS
#define AT32_ST_USE_SYSTICK                 FALSE
#define AT32_ST_USE_TMR2                    FALSE
#define AT32_ST_USE_TMR3                    FALSE
#define AT32_ST_USE_TMR4                    FALSE
#define AT32_ST_USE_TMR5                    FALSE
#define AT32_ST_USE_TMR9                    TRUE
#define AT32_ST_USE_TMR10                   FALSE
#define AT32_ST_USE_TMR11                   FALSE

#elif AT32_ST_USE_TIMER == 10

#if defined(AT32_TMR10_IS_USED)
#error "ST requires TMR10 but the timer is already used"
#else
#define AT32_TMR10_IS_USED
#endif

#if defined(AT32_TMR10_SUPPRESS_ISR)
#define AT32_SYSTICK_SUPPRESS_ISR
#endif

#define AT32_ST_TMR                         AT32_TMR10
#define ST_LLD_NUM_ALARMS                   AT32_TMR10_CHANNELS
#define AT32_ST_USE_SYSTICK                 FALSE
#define AT32_ST_USE_TMR2                    FALSE
#define AT32_ST_USE_TMR3                    FALSE
#define AT32_ST_USE_TMR4                    FALSE
#define AT32_ST_USE_TMR5                    FALSE
#define AT32_ST_USE_TMR9                    FALSE
#define AT32_ST_USE_TMR10                   TRUE
#define AT32_ST_USE_TMR11                   FALSE

#elif AT32_ST_USE_TIMER == 11

#if defined(AT32_TMR11_IS_USED)
#error "ST requires TMR11 but the timer is already used"
#else
#define AT32_TMR11_IS_USED
#endif

#if defined(AT32_TMR11_SUPPRESS_ISR)
#define AT32_SYSTICK_SUPPRESS_ISR
#endif

#define AT32_ST_TMR                         AT32_TMR11
#define ST_LLD_NUM_ALARMS                   AT32_TMR11_CHANNELS
#define AT32_ST_USE_SYSTICK                 FALSE
#define AT32_ST_USE_TMR2                    FALSE
#define AT32_ST_USE_TMR3                    FALSE
#define AT32_ST_USE_TMR4                    FALSE
#define AT32_ST_USE_TMR5                    FALSE
#define AT32_ST_USE_TMR9                    FALSE
#define AT32_ST_USE_TMR10                   FALSE
#define AT32_ST_USE_TMR11                   TRUE

#else
#error "AT32_ST_USE_TIMER specifies an unsupported timer"
#endif

#if (AT32_ST_OVERRIDE_ALARMS < 0) ||                                        \
    (AT32_ST_OVERRIDE_ALARMS > ST_LLD_NUM_ALARMS)
#error "invalid AT32_ST_OVERRIDE_ALARMS value"
#endif

#if AT32_ST_OVERRIDE_ALARMS > 0
#undef ST_LLD_NUM_ALARMS
#define ST_LLD_NUM_ALARMS                   AT32_ST_OVERRIDE_ALARMS
#endif

#elif OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC

#define AT32_ST_USE_SYSTICK                 TRUE
#define AT32_ST_USE_TMR2                    FALSE
#define AT32_ST_USE_TMR3                    FALSE
#define AT32_ST_USE_TMR4                    FALSE
#define AT32_ST_USE_TMR5                    FALSE
#define AT32_ST_USE_TMR9                    FALSE
#define AT32_ST_USE_TMR10                   FALSE
#define AT32_ST_USE_TMR11                   FALSE

#else

#define AT32_ST_USE_SYSTICK                 FALSE
#define AT32_ST_USE_TMR2                    FALSE
#define AT32_ST_USE_TMR3                    FALSE
#define AT32_ST_USE_TMR4                    FALSE
#define AT32_ST_USE_TMR5                    FALSE
#define AT32_ST_USE_TMR9                    FALSE
#define AT32_ST_USE_TMR10                   FALSE
#define AT32_ST_USE_TMR11                   FALSE

#endif

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
  void st_lld_init(void);
  void st_lld_serve_interrupt(void);
#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Driver inline functions.                                                  */
/*===========================================================================*/

#if (OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING) || defined(__DOXYGEN__)

/**
 * @brief   Returns the time counter value.
 *
 * @return              The counter value.
 *
 * @notapi
 */
static inline systime_t st_lld_get_counter(void) {

  return (systime_t)AT32_ST_TMR->CVAL;
}

/**
 * @brief   Starts the alarm.
 * @note    Makes sure that no spurious alarms are triggered after
 *          this call.
 *
 * @param[in] abstime   the time to be set for the first alarm
 *
 * @notapi
 */
static inline void st_lld_start_alarm(systime_t abstime) {

  AT32_ST_TMR->CDT[0] = (uint32_t)abstime;
  AT32_ST_TMR->ISTS   = 0;
#if ST_LLD_NUM_ALARMS == 1
  AT32_ST_TMR->IDEN   = AT32_TMR_IDEN_C1IEN;
#else
  AT32_ST_TMR->IDEN  |= AT32_TMR_IDEN_C1IEN;
#endif
}

/**
 * @brief   Stops the alarm interrupt.
 *
 * @notapi
 */
static inline void st_lld_stop_alarm(void) {

#if ST_LLD_NUM_ALARMS == 1
  AT32_ST_TMR->IDEN = 0U;
#else
  AT32_ST_TMR->IDEN &= ~AT32_TMR_IDEN_C1IEN;
#endif
}

/**
 * @brief   Sets the alarm time.
 *
 * @param[in] abstime   the time to be set for the next alarm
 *
 * @notapi
 */
static inline void st_lld_set_alarm(systime_t abstime) {

  AT32_ST_TMR->CDT[0] = (uint32_t)abstime;
}

/**
 * @brief   Returns the current alarm time.
 *
 * @return              The currently set alarm time.
 *
 * @notapi
 */
static inline systime_t st_lld_get_alarm(void) {

  return (systime_t)AT32_ST_TMR->CDT[0];
}

/**
 * @brief   Determines if the alarm is active.
 *
 * @return              The alarm status.
 * @retval false        if the alarm is not active.
 * @retval true         is the alarm is active
 *
 * @notapi
 */
static inline bool st_lld_is_alarm_active(void) {

  return (bool)((AT32_ST_TMR->IDEN & AT32_TMR_IDEN_C1IEN) != 0);
}

#if (ST_LLD_NUM_ALARMS > 1) || defined(__DOXYGEN__)
/**
 * @brief   Starts an alarm.
 * @note    Makes sure that no spurious alarms are triggered after
 *          this call.
 * @note    This functionality is only available in free running mode, the
 *          behavior in periodic mode is undefined.
 *
 * @param[in] abstime   the time to be set for the first alarm
 * @param[in] alarm     alarm channel number
 *
 * @notapi
 */
static inline void st_lld_start_alarm_n(unsigned alarm, systime_t abstime) {

  AT32_ST_TMR->CDT[alarm] = (uint32_t)abstime;
  AT32_ST_TMR->ISTS       = 0;
  AT32_ST_TMR->IDEN      |= (AT32_TMR_IDEN_C1IEN << alarm);
}

/**
 * @brief   Stops an alarm interrupt.
 * @note    This functionality is only available in free running mode, the
 *          behavior in periodic mode is undefined.
 *
 * @param[in] alarm     alarm channel number
 *
 * @notapi
 */
static inline void st_lld_stop_alarm_n(unsigned alarm) {

  AT32_ST_TMR->IDEN &= ~(AT32_TMR_IDEN_C1IEN << alarm);
}

/**
 * @brief   Sets an alarm time.
 * @note    This functionality is only available in free running mode, the
 *          behavior in periodic mode is undefined.
 *
 * @param[in] alarm     alarm channel number
 * @param[in] abstime   the time to be set for the next alarm
 *
 * @notapi
 */
static inline void st_lld_set_alarm_n(unsigned alarm, systime_t abstime) {

  AT32_ST_TMR->CDT[alarm] = (uint32_t)abstime;
}

/**
 * @brief   Returns an alarm current time.
 * @note    This functionality is only available in free running mode, the
 *          behavior in periodic mode is undefined.
 *
 * @param[in] alarm     alarm channel number
 * @return              The currently set alarm time.
 *
 * @notapi
 */
static inline systime_t st_lld_get_alarm_n(unsigned alarm) {

  return (systime_t)AT32_ST_TMR->CDT[alarm];
}

/**
 * @brief   Determines if an alarm is active.
 *
 * @param[in] alarm     alarm channel number
 * @return              The alarm status.
 * @retval false        if the alarm is not active.
 * @retval true         is the alarm is active
 *
 * @notapi
 */
static inline bool st_lld_is_alarm_active_n(unsigned alarm) {

  return (bool)((AT32_ST_TMR->IDEN & (AT32_TMR_IDEN_C1IEN << alarm)) != 0);
}
#endif /* ST_LLD_NUM_ALARMS > 1 */

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#endif /* HAL_ST_LLD_H */

/** @} */
