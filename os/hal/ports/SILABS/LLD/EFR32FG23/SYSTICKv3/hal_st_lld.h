/*
    ChibiOS - Copyright (C) 2023 Xael South

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
 * @file    SYSTICKv3/hal_st_lld.h
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

/**
 * @brief   Counter registry initial value.
 */
#if (OSAL_ST_RESOLUTION == 32)
  #define ST_INIT_VALUE                        0x00FFFFFFUL
#else
  #define ST_INIT_VALUE                        0x0000FFFFUL
#endif

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   LETIM1x unit (by number) to be used for free running operations.
 * @note    You must select a 16 bits timer if a 16 bits @p systick_t type
 *          is required.
 * @note    Timer 1 supported.
 */
#if !defined(EFR32_ST_USE_TIMER) || defined(__DOXYGEN__)
  #define EFR32_ST_USE_TIMER                   1
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if (OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING)
#if !defined(EFR32_HAS_LETIM1)
  #define EFR32_HAS_LETIM1                     FALSE
#endif

#if EFR32_ST_USE_TIMER == 1
  #if defined(EFR32_LETIM1_IS_USED)
    #error "ST requires LETIM1 but the timer is already used"
  #else
    #define EFR32_LETIM1_IS_USED
  #endif

  #define EFR32_ST_TIM                         LETIMER0
#endif
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */

/**
 * @brief   ST Alarms number.
 */
#define ST_LLD_NUM_ALARMS                     2

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

  return ((systime_t)(ST_INIT_VALUE - EFR32_ST_TIM->CNT));
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

  EFR32_ST_TIM->IEN_CLR = LETIMER_IEN_COMP0;

  #if (OSAL_ST_RESOLUTION == 32)
  EFR32_ST_TIM->COMP0 = (uint32_t)ST_INIT_VALUE - (uint32_t)abstime;
  #else
  EFR32_ST_TIM->COMP0 = (uint16_t)ST_INIT_VALUE - (uint16_t)abstime;
  #endif

  EFR32_ST_TIM->IEN_SET = LETIMER_IEN_COMP0;
}

/**
 * @brief   Stops the alarm interrupt.
 *
 * @notapi
 */
static inline void st_lld_stop_alarm(void) {

  EFR32_ST_TIM->IEN_CLR = LETIMER_IEN_COMP0;
}

/**
 * @brief   Sets the alarm time.
 *
 * @param[in] abstime   the time to be set for the next alarm
 *
 * @notapi
 */
static inline void st_lld_set_alarm(systime_t abstime) {

  st_lld_start_alarm(abstime);
}

/**
 * @brief   Returns the current alarm time.
 *
 * @return              The currently set alarm time.
 *
 * @notapi
 */
static inline systime_t st_lld_get_alarm(void) {

  return ((systime_t)(ST_INIT_VALUE - EFR32_ST_TIM->COMP0));
}

/**
 * @brief   Determines if the alarm is active.
 *
 * @return              The alarm status.
 *
 * @retval false        if the alarm is not active.
 * @retval true         is the alarm is active
 *
 * @notapi
 */
static inline bool st_lld_is_alarm_active(void) {

  return ((EFR32_ST_TIM->IEN & LETIMER_IEN_COMP0) != 0U);
}

#if (ST_LLD_NUM_ALARMS > 1) || defined(__DOXYGEN__)

/**
 * @brief   Starts an alarm.
 * @note    Makes sure that no spurious alarms are triggered after
 *          this call.
 * @note    This functionality is only available in free running mode, the
 *          behavior in periodic mode is undefined.
 * @param[in] abstime   the time to be set for the first alarm
 * @param[in] alarm     alarm channel number
 * @notapi
 */
static inline void st_lld_start_alarm_n(unsigned alarm, systime_t abstime) {

  (void)alarm;

  EFR32_ST_TIM->IEN_CLR = LETIMER_IEN_COMP1;

  #if (OSAL_ST_RESOLUTION == 32)
  EFR32_ST_TIM->COMP1 = (uint32_t)ST_INIT_VALUE - (uint32_t)abstime;
  #else
  EFR32_ST_TIM->COMP1 = (uint16_t)ST_INIT_VALUE - (uint16_t)abstime;
  #endif

  EFR32_ST_TIM->IEN_SET = LETIMER_IEN_COMP1;
}

/**
 * @brief   Stops an alarm interrupt.
 * @note    This functionality is only available in free running mode, the
 *          behavior in periodic mode is undefined.
 * @param[in] alarm     alarm channel number
 * @notapi
 */
static inline void st_lld_stop_alarm_n(unsigned alarm) {

  (void)alarm;
  EFR32_ST_TIM->IEN_CLR = LETIMER_IEN_COMP1;
}

/**
 * @brief   Sets an alarm time.
 * @note    This functionality is only available in free running mode, the
 *          behavior in periodic mode is undefined.
 * @param[in] alarm     alarm channel number
 * @param[in] abstime   the time to be set for the next alarm
 * @notapi
 */
static inline void st_lld_set_alarm_n(unsigned alarm, systime_t abstime) {

  (void)alarm;
  st_lld_start_alarm_n(alarm, abstime);
}

/**
 * @brief   Returns an alarm current time.
 * @note    This functionality is only available in free running mode, the
 *          behavior in periodic mode is undefined.
 * @param[in] alarm     alarm channel number
 *
 * @return              The currently set alarm time.
 *
 * @notapi
 */
static inline systime_t st_lld_get_alarm_n(unsigned alarm) {

  (void)alarm;
  return ((systime_t)(ST_INIT_VALUE - EFR32_ST_TIM->COMP1));
}

/**
 * @brief   Determines if an alarm is active.
 * @param[in] alarm     alarm channel number
 *
 * @return              The alarm status.
 *
 * @retval false        if the alarm is not active.
 * @retval true         is the alarm is active
 * @notapi
 */
static inline bool st_lld_is_alarm_active_n(unsigned alarm) {

  (void)alarm;
  return ((EFR32_ST_TIM->IEN & LETIMER_IEN_COMP1) != 0U);
}
#endif /* ST_LLD_NUM_ALARMS > 1 */

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#endif /* HAL_ST_LLD_H */

/** @} */
