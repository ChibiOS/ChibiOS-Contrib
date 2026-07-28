/*
    Copyright (C) 2019 /u/KeepItUnder
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
 * @file    M251/hal_st_lld.h
 * @brief   M251/M252 ST subsystem low level driver header.
 *
 * @addtogroup ST
 * @{
 */

#ifndef HAL_ST_LLD_H
#define HAL_ST_LLD_H

/**
 * @name    M251 system timer configuration options
 * @{
 */

/**
 * @brief   System timer interrupt priority.
 * @note    The default is 3.
 */
#if !defined(M251_ST_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define M251_ST_IRQ_PRIORITY                3
#endif

/**
 * @brief   SysTick input clock.
 * @note    The default is @p M251_HCLK.
 * @note    This setting is used only in periodic mode.
 */
#if !defined(M251_ST_CLK) || defined(__DOXYGEN__)
#define M251_ST_CLK                         M251_HCLK
#endif

/**
 * @brief   TIMER unit used by the free-running system timer.
 * @details Valid values are 0 through 3, selecting TIMER0 through TIMER3.
 * @note    The default is TIMER1.
 */
#if !defined(M251_ST_USE_TIMER) || defined(__DOXYGEN__)
#define M251_ST_USE_TIMER                   1
#endif

/** @} */

#if !OSAL_IRQ_IS_VALID_PRIORITY(M251_ST_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to ST"
#endif

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC

#if M251_ST_CLK % OSAL_ST_FREQUENCY != 0
#error "OSAL_ST_FREQUENCY is not an integer divisor of M251_ST_CLK"
#endif

#if ((M251_ST_CLK / OSAL_ST_FREQUENCY) - 1U) > 0xFFFFFFU
#error "the selected ST frequency is not obtainable using SysTick"
#endif

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING

#if OSAL_ST_RESOLUTION != 16
#error "M251 free-running ST requires 16-bit resolution"
#endif

#if (M251_ST_USE_TIMER < 0) || (M251_ST_USE_TIMER > 3)
#error "M251_ST_USE_TIMER must select TIMER0 through TIMER3"
#endif

#if (M251_ST_USE_TIMER == 0) && !M251_HAS_TIM0
#error "TIMER0 not present in the selected device"
#elif (M251_ST_USE_TIMER == 1) && !M251_HAS_TIM1
#error "TIMER1 not present in the selected device"
#elif (M251_ST_USE_TIMER == 2) && !M251_HAS_TIM2
#error "TIMER2 not present in the selected device"
#elif (M251_ST_USE_TIMER == 3) && !M251_HAS_TIM3
#error "TIMER3 not present in the selected device"
#endif

#if (M251_ST_USE_TIMER == 0) && (M251_GPT_USE_TMR0 == TRUE)
#error "TIMER0 is already used by ST"
#elif (M251_ST_USE_TIMER == 1) && (M251_GPT_USE_TMR1 == TRUE)
#error "TIMER1 is already used by ST"
#elif (M251_ST_USE_TIMER == 2) && (M251_GPT_USE_TMR2 == TRUE)
#error "TIMER2 is already used by ST"
#elif (M251_ST_USE_TIMER == 3) && (M251_GPT_USE_TMR3 == TRUE)
#error "TIMER3 is already used by ST"
#endif

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#if (OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING) || defined(__DOXYGEN__)

#if M251_ST_USE_TIMER == 0
#define M251_ST_TIM                         TIMER0
#define M251_ST_TIMER_HANDLER               M251_TMR0_HANDLER
#define M251_ST_TIMER_NUMBER                M251_TMR0_NUMBER
#elif M251_ST_USE_TIMER == 1
#define M251_ST_TIM                         TIMER1
#define M251_ST_TIMER_HANDLER               M251_TMR1_HANDLER
#define M251_ST_TIMER_NUMBER                M251_TMR1_NUMBER
#elif M251_ST_USE_TIMER == 2
#define M251_ST_TIM                         TIMER2
#define M251_ST_TIMER_HANDLER               M251_TMR2_HANDLER
#define M251_ST_TIMER_NUMBER                M251_TMR2_NUMBER
#else
#define M251_ST_TIM                         TIMER3
#define M251_ST_TIMER_HANDLER               M251_TMR3_HANDLER
#define M251_ST_TIMER_NUMBER                M251_TMR3_NUMBER
#endif

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING || __DOXYGEN__ */

#ifdef __cplusplus
extern "C" {
#endif
  void st_lld_init(void);
#ifdef __cplusplus
}
#endif

#if (OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING) || defined(__DOXYGEN__)

/**
 * @brief   Returns the time counter value.
 *
 * @return              The counter value.
 *
 * @notapi
 */
static inline systime_t st_lld_get_counter(void) {

  return (systime_t)M251_ST_TIM->PWMCNT;
}

/**
 * @brief   Starts the alarm.
 * @note    Makes sure that no spurious alarms are triggered after this call.
 *
 * @param[in] abstime   the time to be set for the first alarm
 *
 * @notapi
 */
static inline void st_lld_start_alarm(systime_t abstime) {

  M251_ST_TIM->PWMCMPDAT = (uint32_t)abstime;
  M251_ST_TIM->PWMINTEN0 = 0U;
  M251_ST_TIM->PWMINTSTS0 = TIMER_PWMINTSTS0_PIF_Msk |
                            TIMER_PWMINTSTS0_CMPUIF_Msk;
  /* CMPUIF is not generated when the comparator equals the period.*/
  M251_ST_TIM->PWMINTEN0 = abstime == TIME_MAX_SYSTIME
                           ? TIMER_PWMINTEN0_PIEN_Msk
                           : TIMER_PWMINTEN0_CMPUIEN_Msk;
}

/**
 * @brief   Stops the alarm interrupt.
 *
 * @notapi
 */
static inline void st_lld_stop_alarm(void) {

  M251_ST_TIM->PWMINTEN0 = 0U;
}

/**
 * @brief   Sets the alarm time.
 *
 * @param[in] abstime   the time to be set for the next alarm
 *
 * @notapi
 */
static inline void st_lld_set_alarm(systime_t abstime) {

  M251_ST_TIM->PWMINTEN0 = 0U;
  M251_ST_TIM->PWMCMPDAT = (uint32_t)abstime;
  M251_ST_TIM->PWMINTSTS0 = TIMER_PWMINTSTS0_PIF_Msk |
                            TIMER_PWMINTSTS0_CMPUIF_Msk;
  /* CMPUIF is not generated when the comparator equals the period.*/
  M251_ST_TIM->PWMINTEN0 = abstime == TIME_MAX_SYSTIME
                           ? TIMER_PWMINTEN0_PIEN_Msk
                           : TIMER_PWMINTEN0_CMPUIEN_Msk;
}

/**
 * @brief   Returns the current alarm time.
 *
 * @return              The currently set alarm time.
 *
 * @notapi
 */
static inline systime_t st_lld_get_alarm(void) {

  return (systime_t)M251_ST_TIM->PWMCMPDAT;
}

/**
 * @brief   Determines if the alarm is active.
 *
 * @return              The alarm status.
 * @retval false        if the alarm is not active
 * @retval true         if the alarm is active
 *
 * @notapi
 */
static inline bool st_lld_is_alarm_active(void) {

  return (M251_ST_TIM->PWMINTEN0 & (TIMER_PWMINTEN0_PIEN_Msk |
                                    TIMER_PWMINTEN0_CMPUIEN_Msk)) != 0U;
}

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#endif /* HAL_ST_LLD_H */

/** @} */
