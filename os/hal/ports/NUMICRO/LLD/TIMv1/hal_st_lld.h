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
 * @file    hal_st_lld.h
 * @brief   ST Driver subsystem low level driver header.
 * @details This header is designed to be include-able without having to
 *          include other files from the HAL.
 *
 * @addtogroup ST
 * @{
 */

#ifndef HAL_ST_LLD_H
#define HAL_ST_LLD_H

#include "mcuconf.h"
//#include "nuc123_tim.h"

/*
 * Registry definitions.
 */
#include "nuc123_registry.h"

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
#if !defined(NUC123_ST_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define NUC123_ST_IRQ_PRIORITY               8
#endif

/**
 * @brief   TIMx unit (by number) to be used for free running operations.
 * @note    You must select a 32 bits timer if a 32 bits @p systick_t type
 *          is required.
 * @note    Timers 2, 3 and 4 are supported.
 */
#if !defined(NUC123_ST_USE_TIMER) || defined(__DOXYGEN__)
#define NUC123_ST_USE_TIMER                  2
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if NUC123_ST_USE_TIMER == 2
#if !NUC123_HAS_TIM2
#error "TIM2 not present"
#endif
#define NUC123_ST_TIM                              TIMER1

#elif NUC123_ST_USE_TIMER == 3
#if !NUC123_HAS_TIM3
#error "TIM3 not present"
#endif
#define NUC123_ST_TIM                              TIMER2

#elif NUC123_ST_USE_TIMER == 4
#if !NUC123_HAS_TIM4
#error "TIM4 not present"
#endif
#define NUC123_ST_TIM                              TIMER3

#else
#error "NUC123_ST_USE_TIMER specifies an unsupported timer"
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
#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Driver inline functions.                                                  */
/*===========================================================================*/

/**
 * @brief   Returns the time counter value.
 *
 * @return              The counter value.
 *
 * @notapi
 */
static inline systime_t st_lld_get_counter(void) {

  return (systime_t)NUC123_ST_TIM->TDR;
}

/**
 * @brief   Starts the alarm.
 * @note    Makes sure that no spurious alarms are triggered after
 *          this call.
 *
 * @param[in] time      the time to be set for the first alarm
 *
 * @notapi
 */
static inline void st_lld_start_alarm(systime_t time) {

  //NUC123_ST_TIM->TCMP = (uint32_t)time;
  //NUC123_ST_TIM->SR     = 0;
  //NUC123_ST_TIM->DIER   = NUC123_TIM_DIER_CC1IE;
  TIMER_Open(NUC123_ST_TIM, TIMER_CONTINUOUS_MODE | TIMER_TCSR_TDR_EN_Msk, TIMER_GetModuleClock(NUC123_ST_TIM));
  TIMER_SET_CMP_VALUE(NUC123_ST_TIM, (uint32_t)time);
  TIMER_SET_PRESCALE_VALUE(NUC123_ST_TIM, 0);
  TIMER_Start(NUC123_ST_TIM);
}

/**
 * @brief   Stops the alarm interrupt.
 *
 * @notapi
 */
static inline void st_lld_stop_alarm(void) {

  TIMER_DisableInt(NUC123_ST_TIM);
}

/**
 * @brief   Sets the alarm time.
 *
 * @param[in] time      the time to be set for the next alarm
 *
 * @notapi
 */
static inline void st_lld_set_alarm(systime_t time) {

  TIMER_SET_CMP_VALUE(NUC123_ST_TIM, (uint32_t)time);
}

/**
 * @brief   Returns the current alarm time.
 *
 * @return              The currently set alarm time.
 *
 * @notapi
 */
static inline systime_t st_lld_get_alarm(void) {

  return (systime_t)NUC123_ST_TIM->TCMPR;
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

  return (bool)((TIMER_GetIntFlag(NUC123_ST_TIM) & TIMER_IS_ACTIVE(NUC123_ST_TIM)) != 0);
}

#endif /* HAL_ST_LLD_H */

/** @} */
