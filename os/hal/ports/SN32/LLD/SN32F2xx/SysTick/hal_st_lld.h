/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

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
 * @brief   PLATFORM ST subsystem low level driver header.
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
#if !defined(SN32_ST_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SN32_ST_IRQ_PRIORITY               8
#endif

/**
 * @brief   CT16Bx unit (by number) to be used for free running operations.
 * @note    You must select a 16 bits timer if a 16 bits @p systick_t type
 *          is required.
 * @note    Timers CT16B0 and CT16B1 are supported.
 */
#if !defined(SN32_ST_USE_TIMER) || defined(__DOXYGEN__)
#define SN32_ST_USE_TIMER                  CT16B0
#endif
/** @} */
/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/
#if !defined(SN32_HAS_CT16B0)
#define SN32_HAS_CT16B0                      FALSE
#endif

#if !defined(SN32_HAS_CT16B1)
#define SN32_HAS_CT16B1                      FALSE
#endif
#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING

#if SN32_ST_USE_TIMER == CT16B0

#if defined(SN32_CT16B0_IS_USED)
#error "ST requires CT16B0 but the timer is already used"
#else
#define SN32_CT16B0_IS_USED
#endif

#define SN32_ST_TIM                         SN32_CT16B0
#define ST_LLD_NUM_ALARMS                   1

#elif SN32_ST_USE_TIMER == CT16B1

#if defined(SN32_CT16B1_IS_USED)
#error "ST requires CT16B1 but the timer is already used"
#else
#define SN32_CT16B1_IS_USED
#endif

#define SN32_ST_TIM                         SN32_CT16B1
#define ST_LLD_NUM_ALARMS                   1

#else
#error "SN32_ST_USE_TIMER specifies an unsupported timer"
#endif

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
  return (systime_t)(SN32_ST_TIM->TC & 0x0000FFFF);
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

  /* The requested delay in OSAL_ST_FREQUENCY ticks, decreased by 1 to bring it
   * into the 0...0xFFFF range instead of 1...0x10000. */
  uint32_t delay = ((uint32_t)abstime - SN32_ST_TIM->TC - 1U) & 0xFFFF;

  /* The conversion factor between the SN32_ST_TIM and SysTick clock
   * frequencies (SN32_HCLK / OSAL_ST_FREQUENCY).
   * TODO: Actually use (SN32_HCLK / OSAL_ST_FREQUENCY) instead of reading the
   * value from a hardware register (this requires making SN32_HCLK a compile
   * time constant). */
  uint32_t prescale = (SN32_ST_TIM->PRE & 0xFF) + 1;

  /* The requested delay in the SysTick clock ticks.  The maximum possible
   * value with prescale=256 is 0xFFFFFF, which just fits into the 24-bit
   * SysTick timer registers. */
  uint32_t systick_delay = delay * prescale + (prescale - 1);

  /* Start SysTick to generate an interrupt after systick_delay. */
  SysTick->LOAD = systick_delay;
  SysTick->VAL = 0;
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                  SysTick_CTRL_ENABLE_Msk |
                  SysTick_CTRL_TICKINT_Msk;

  /* Save the alarm time in a timer register.  This is needed only to make
   * st_lld_get_alarm() work. */
  SN32_ST_TIM->MR0 = (uint32_t)abstime;
}

/**
 * @brief   Stops the alarm interrupt.
 *
 * @notapi
 */
static inline void st_lld_stop_alarm(void) {
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk;
  SCB->ICSR = SCB_ICSR_PENDSTCLR_Msk;
}

/**
 * @brief   Sets the alarm time.
 *
 * @param[in] abstime   the time to be set for the next alarm
 *
 * @notapi
 */
static inline void st_lld_set_alarm(systime_t abstime) {
  st_lld_stop_alarm();
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
  return (systime_t)(SN32_ST_TIM->MR0 & 0x0000FFFF);
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
  return (bool)((SysTick->CTRL & SysTick_CTRL_ENABLE_Msk) != 0);
}

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#endif /* HAL_ST_LLD_H */

/** @} */
