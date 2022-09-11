/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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
#include "sam_clk.h"
/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/
#if HAL_USE_RTC == TRUE && OSAL_ST_MODE != OSAL_ST_MODE_NONE
#error "SYSTICKv1 already uses RTC"
#endif
#if OSAL_ST_RESOLUTION != 32
#error "SYSTICKv1 already requires OSAL_ST_RESOLUTION == 32"
#endif
/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/
#if SAM_RTC_GCLK_SRC_ID == 0
#define SAM_RTC_GCLK_GENDIV SAM_GCLK0_GENDIV
#define SAM_RTC_GCLK_SRC_FREQ SAM_GCLK0_SRC_FREQ
#elif SAM_RTC_GCLK_SRC_ID == 1
#define SAM_RTC_GCLK_GENDIV SAM_GCLK1_GENDIV
#define SAM_RTC_GCLK_SRC_FREQ SAM_GCLK1_SRC_FREQ
#elif SAM_RTC_GCLK_SRC_ID == 2
#define SAM_RTC_GCLK_GENDIV SAM_GCLK2_GENDIV
#define SAM_RTC_GCLK_SRC_FREQ SAM_GCLK2_SRC_FREQ
#elif SAM_RTC_GCLK_SRC_ID == 3
#define SAM_RTC_GCLK_GENDIV SAM_GCLK3_GENDIV
#define SAM_RTC_GCLK_SRC_FREQ SAM_GCLK3_SRC_FREQ
#elif SAM_RTC_GCLK_SRC_ID == 4
#define SAM_RTC_GCLK_GENDIV SAM_GCLK4_GENDIV
#define SAM_RTC_GCLK_SRC_FREQ SAM_GCLK4_SRC_FREQ
#elif SAM_RTC_GCLK_SRC_ID == 5
#define SAM_RTC_GCLK_GENDIV SAM_GCLK5_GENDIV
#define SAM_RTC_GCLK_SRC_FREQ SAM_GCLK5_SRC_FREQ
#elif SAM_RTC_GCLK_SRC_ID == 6
#define SAM_RTC_GCLK_GENDIV SAM_GCLK6_GENDIV
#define SAM_RTC_GCLK_SRC_FREQ SAM_GCLK6_SRC_FREQ
#elif SAM_RTC_GCLK_SRC_ID == 7
#define SAM_RTC_GCLK_GENDIV SAM_GCLK7_GENDIV
#define SAM_RTC_GCLK_SRC_FREQ SAM_GCLK7_SRC_FREQ
#elif SAM_RTC_GCLK_SRC_ID == 8
#define SAM_RTC_GCLK_GENDIV SAM_GCLK8_GENDIV
#define SAM_RTC_GCLK_SRC_FREQ SAM_GCLK8_SRC_FREQ
#endif
#if SAM_RTC_GCLK_GENDIV == 0
#error SAM_RTC_GCLK_GENDIV cannot be 0
#elif (SAM_RTC_GCLK_GENDIV * OSAL_ST_FREQUENCY * (1UL << SAM_RTC_DIV)) != SAM_RTC_GCLK_SRC_FREQ
#error SAM_RTC_DIV and SAM_RTC_GCLK_SRC_FREQ does not satisfy for OSAL_ST_FREQUENCY
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
extern "C"
{
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

static inline systime_t st_lld_get_counter(void)
{
  RTC_REGS->MODE0.RTC_READREQ = RTC_READREQ_RREQ_Msk | RTC_READREQ_ADDR(0x10U);
  while ((RTC_REGS->MODE0.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
    ;
  uint32_t counter = (RTC_REGS->MODE0.RTC_COUNT);
  return counter;
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
static inline void st_lld_start_alarm(systime_t abstime)
{
  RTC_REGS->MODE0.RTC_CTRL &= (uint16_t)(~(RTC_MODE0_CTRL_ENABLE_Msk));
  while ((RTC_REGS->MODE0.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
    ;
  RTC_REGS->MODE0.RTC_COMP = (uint32_t)abstime;
  while ((RTC_REGS->MODE0.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
    ;
  RTC_REGS->MODE0.RTC_CTRL |= (uint16_t)(RTC_MODE0_CTRL_ENABLE_Msk);
  while ((RTC_REGS->MODE0.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
    ;
  RTC_REGS->MODE0.RTC_INTENSET = 1;
}

/**
 * @brief   Stops the alarm interrupt.
 *
 * @notapi
 */
static inline void st_lld_stop_alarm(void)
{
  RTC_REGS->MODE0.RTC_CTRL &= (uint16_t)(~(RTC_MODE0_CTRL_ENABLE_Msk));
  while ((RTC_REGS->MODE0.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
    ;
  RTC_REGS->MODE0.RTC_INTENCLR = 1;
}

/**
 * @brief   Sets the alarm time.
 *
 * @param[in] abstime   the time to be set for the next alarm
 *
 * @notapi
 */
static inline void st_lld_set_alarm(systime_t abstime)
{
  st_lld_start_alarm(abstime);
}

/**
 * @brief   Returns the current alarm time.
 *
 * @return              The currently set alarm time.
 *
 * @notapi
 */
static inline systime_t st_lld_get_alarm(void)
{
  return ((RTC_REGS->MODE0.RTC_COMP));
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
static inline bool st_lld_is_alarm_active(void)
{
  if (RTC_REGS->MODE0.RTC_CTRL & RTC_MODE0_CTRL_ENABLE_Msk)
  {
    return true;
  }
  return false;
}

#endif /* HAL_ST_LLD_H */

/** @} */
