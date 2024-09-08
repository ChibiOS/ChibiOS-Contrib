/*
    ChibiOS - Copyright (C) 2024 Xael South

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
 * @file    hal_rtc_lld.c
 * @brief   EFR32 RTC subsystem low level driver source.
 *
 * @addtogroup RTC
 * @{
 */

#include "hal.h"

#if (HAL_USE_RTC == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief Shortcut only that is not intended to use
 * elsewhere except for EFR32_OVERFLOW_SCALE macro.
 */
#define _EFR32_OVERFLOW_VALUE     (_BURTC_CNT_CNT_MASK >> _BURTC_CNT_CNT_SHIFT)

/**
 * EFR32_RTCCLK_DIV is more or less arbitrary. The smaller the value
 * the often overflow interrupt will occur. To avoid frequent occurance
 * of interrupts set the value as high as possible.
 */

#if EFR32_RTC_HAS_SUBSECONDS

#if EFR32_BURTCCLK % 32U == 0U
#define EFR32_RTCCLK_DIV 32U
#define EFR32_BURTC_CFG_CNTPRESC  BURTC_CFG_CNTPRESC_DIV32
#elif EFR32_BURTCCLK % 16U == 0U
#define EFR32_RTCCLK_DIV 16U
#define EFR32_BURTC_CFG_CNTPRESC  BURTC_CFG_CNTPRESC_DIV16
#elif EFR32_BURTCCLK % 8U == 0U
#define EFR32_RTCCLK_DIV 8U
#define EFR32_BURTC_CFG_CNTPRESC  BURTC_CFG_CNTPRESC_DIV8
#elif EFR32_BURTCCLK % 4U == 0U
#define EFR32_RTCCLK_DIV 4U
#define EFR32_BURTC_CFG_CNTPRESC  BURTC_CFG_CNTPRESC_DIV4
#elif EFR32_BURTCCLK % 2U == 0U
#define EFR32_RTCCLK_DIV 2U
#define EFR32_BURTC_CFG_CNTPRESC  BURTC_CFG_CNTPRESC_DIV2
#elif EFR32_BURTCCLK % 1U == 0U
#define EFR32_RTCCLK_DIV 1U
#define EFR32_BURTC_CFG_CNTPRESC  BURTC_CFG_CNTPRESC_DIV1
#else
#error "EFR32_RTCCLK_DIV is not obtainable"
#endif

#else

#if EFR32_BURTCCLK % 32768U == 0U
#define EFR32_RTCCLK_DIV 32768U
#define EFR32_BURTC_CFG_CNTPRESC  BURTC_CFG_CNTPRESC_DIV32768
#else
#error "EFR32_RTCCLK_DIV is not obtainable"
#endif

#endif

#define EFR32_RTCCLK              (EFR32_BURTCCLK / EFR32_RTCCLK_DIV)

#define EFR32_OVERFLOW_SCALE(val)                                             \
  ((val) * ((_EFR32_OVERFLOW_VALUE - (EFR32_RTCCLK - 1U)) / EFR32_RTCCLK + 1U))

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief RTC driver identifier.
 */
#if (EFR32_RTC_USE_RTC1 == TRUE) && !defined(__DOXYGEN__)
RTCDriver RTCD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

static const int day_offset_by_month[12] = {
  0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
};

static const int rtc_day_of_the_week[7] = {
  RTC_DAY_SUNDAY, RTC_DAY_MONDAY, RTC_DAY_TUESDAY, RTC_DAY_WEDNESDAY,
  RTC_DAY_THURSDAY, RTC_DAY_FRIDAY, RTC_DAY_SATURDAY
};

/*
 * @brief   Global DAC-related data structures.
 *          Structure remains initialised after reboot.
 */
CC_SECTION(".ram0")
static struct {
  uint32_t                 ovf_counter; /**< BURTC overflow counter. */
} rtc;

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

#define isleap(y) ((((y) % 4) == 0 && ((y) % 100) != 0) || ((y) % 400) == 0)

/**
 * @brief   Return day of week according by implementing Zeller's congruence.
 *
 * @param[in] year      Year, e.g. 1969
 * @param[in] month     Months 1..12.
 * @param[in] day       Day of the month 1..31
 * @return              Day of week 0 .. 6, Sun .. Sat.
 *
 */
__STATIC_INLINE int _rtc_lld_wday(int year, int month, int day) {

  int adjustment, mm, yy, wday;

  adjustment = (14 - month) / 12;
  mm = month + 12 * adjustment - 2;
  yy = year - adjustment;

  /* wday in range from 0 .. 6: Sun to Sat */
  wday = (day + (13 * mm - 1) / 5 +
          yy + yy / 4 - yy / 100 + yy / 400) % 7;

  return wday;
}

__STATIC_INLINE void _rtc_lld_to_timespec(uint32_t tv_sec, RTCDateTime* timespec, uint32_t tv_msec) {

  int year;
  int month;
  int day = tv_sec / 86400;

  /* Seconds left after all days are subtracted. */
  tv_sec -= day * 86400;

  year = day / 365;

  /* Days left after all years are subtracted, which works only
     during the next thousend years. */
  day -= year * 365;

  int last_year = RTC_BASE_YEAR + year - 1;
  /* Number of leap corrections to apply up to end of last year. */
  int leap_days_to_last_year = (last_year / 4 - last_year / 100 + last_year / 400);
  leap_days_to_last_year -= ((RTC_BASE_YEAR - 1) / 4 - (RTC_BASE_YEAR - 1) / 100 + (RTC_BASE_YEAR - 1) / 400);

  day -= leap_days_to_last_year;

  for (month = 0; month < 12; month++) {

    if (day_offset_by_month[month] > day)
      break;
  }

  day -= day_offset_by_month[month - 1];

  if (month > 2) {
    /* Are we past 29 February? */
    day -= isleap(RTC_BASE_YEAR + year);
  }

  timespec->millisecond = tv_sec * 1000 + tv_msec;
  timespec->dstflag = 0;
  timespec->year = year;
  timespec->month = month;
  timespec->day = day + 1 /* 0 .. 30 -> 1 .. 31 */;
  int dayofweek = _rtc_lld_wday(RTC_BASE_YEAR + year,
                                timespec->month,
                                timespec->day);
  /* wday 0 .. 6: Sun .. Sat -> 1 .. 7: Mon .. Sun */
  timespec->dayofweek = rtc_day_of_the_week[dayofweek];
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if !defined(EFR32_RTC_SUPPRESS_ISR)
/**
 * @brief   RTC common interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(EFR32_BURTC_HANDLER) {

  uint32_t isr;

  OSAL_IRQ_PROLOGUE();

  isr = BURTC->IF & _BURTC_IF_MASK;
  BURTC->IF_CLR = isr;

  if ((isr & _BURTC_IF_OF_MASK) == BURTC_IF_OF) {
    rtc.ovf_counter += 1U;

    if (RTCD1.callback != NULL) {
      RTCD1.callback(&RTCD1, RTC_EVENT_TS_OVF);
    }
  }

  if ((isr & _BURTC_IF_COMP_MASK) == BURTC_IF_COMP) {
    /* Disable alarm. */
    BURTC->IEN_CLR = BURTC_IEN_COMP;

    if (RTCD1.callback != NULL) {
      RTCD1.callback(&RTCD1, RTC_EVENT_ALARM);
    }
  }

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(EFR32_RTC_SUPPRESS_ISR) */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Enable access to registers.
 *
 * @notapi
 */
void rtc_lld_init(void) {

  /* RTC object initialization.*/
#if EFR32_RTC_USE_RTC1 == TRUE
  rtcObjectInit(&RTCD1);

  /* Callback initially disabled. */
  RTCD1.callback = NULL;
#endif

  CMU->CLKEN0_SET = CMU_CLKEN0_BURTC;

  /* After reboot the BURTC must remain enabled.
     Check this before changing its configuration. */
  if ((BURTC->EN & _BURTC_EN_MASK) == BURTC_EN_EN) {

    /* Disable BURTC if cfg prescaler is not set as wanted. */
    if ((BURTC->CFG & _BURTC_CFG_CNTPRESC_MASK) != EFR32_BURTC_CFG_CNTPRESC) {
      BURTC->CMD_CLR = BURTC_CMD_STOP;
      while ((BURTC->SYNCBUSY & _BURTC_SYNCBUSY_MASK) != 0U);

      BURTC->EN_CLR = BURTC_EN_EN;
      while ((BURTC->EN & _BURTC_EN_DISABLING_MASK) == BURTC_EN_DISABLING);
    }
  }

  /* If calendar has not been initialized yet, then proceed with the
     initial setup.*/
  if ((BURTC->EN & _BURTC_EN_MASK) != BURTC_EN_EN) {

    /* Note that the CFG register can only be written when BURTC
       is disabled. */
    BURTC->CFG = (BURTC->CFG & ~_BURTC_CFG_CNTPRESC_MASK) | EFR32_BURTC_CFG_CNTPRESC;

    /* Enable BURTC. */
    BURTC->EN_SET = BURTC_EN_EN;

    /* Clear all counter. */
    BURTC->PRECNT_CLR = _BURTC_PRECNT_PRECNT_MASK;
    BURTC->CNT_CLR = _BURTC_CNT_CNT_MASK;
    rtc.ovf_counter = 0U;

    /* Clear interrupt flags. */
    BURTC->IF_CLR = _BURTC_IF_MASK;

    /* Enable interrupts. */
    BURTC->IEN_CLR = _BURTC_IEN_MASK;
    BURTC->IEN_SET = BURTC_IEN_OF;
  } else {

    /* Clear interrupt flags. */
    BURTC->IF_CLR = _BURTC_IF_MASK;

    /* If BURTC was enabled before, the interrupts ae still enabled
       but inactive because BURTC is not started yet. */
  }

  /* Start BURTC. */
  BURTC->CMD_SET = BURTC_CMD_START;
  while ((BURTC->SYNCBUSY & _BURTC_SYNCBUSY_MASK) != 0U);

  /* IRQ vectors permanently assigned to this driver.*/
  nvicEnableVector(EFR32_BURTC_NUMBER, EFR32_BURTC_PRIORITY);
}

/**
 * @brief   Set current time.
 * @note    Fractional part of second will be silently ignored.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp      pointer to RTC driver structure
 * @param[in] timespec  pointer to a @p RTCDateTime structure
 *
 * @notapi
 */
void rtc_lld_set_time(RTCDriver* rtcp, const RTCDateTime* timespec) {

  (void)rtcp;
  syssts_t sts;

  uint32_t ovf_counter;
  uint32_t tv_sec, tv_msec;
  uint32_t cnt, precnt;

  int last_year = RTC_BASE_YEAR + timespec->year - 1;
  /* Number of leap corrections to apply up to end of last year. */
  int leap_days_to_last_year = (last_year / 4 - last_year / 100 + last_year / 400);
  leap_days_to_last_year -= ((RTC_BASE_YEAR - 1) / 4 - (RTC_BASE_YEAR - 1) / 100 + (RTC_BASE_YEAR - 1) / 400);
  int month = timespec->month - 1;

  int days = timespec->day - 1; /* 1 .. 31 -> 0 .. 30 */

  if (month >= 2) {
    /* Are we past 29 February? */
    days += isleap(RTC_BASE_YEAR + timespec->year);
  }

  days += timespec->year * 365 + leap_days_to_last_year +
          day_offset_by_month[month];

  tv_sec = days * 86400 + timespec->millisecond / 1000;
  tv_msec = timespec->millisecond % 1000;

  ovf_counter = tv_sec / EFR32_OVERFLOW_SCALE(1);

  tv_sec -= ovf_counter * EFR32_OVERFLOW_SCALE(1);

  cnt = tv_sec * EFR32_RTCCLK;
  precnt = tv_msec * ((_BURTC_PRECNT_PRECNT_MASK >> _BURTC_PRECNT_PRECNT_SHIFT) + 1U) / 1000U;

  /* Entering a reentrant critical zone.*/
  sts = osalSysGetStatusAndLockX();

  /* Following note ist in the reference manual:
   * "Writing to the BURTC_PRECNT register may alter the frequency of the ticks
   * for the BURTC_CNT register." Following that PRECNT must be written before CNT.
   */
  BURTC->PRECNT = precnt;
  BURTC->CNT = cnt;
  rtc.ovf_counter = ovf_counter;

  while ((BURTC->SYNCBUSY & _BURTC_SYNCBUSY_MASK) != 0U);

  if (RTCD1.callback != NULL) {
    RTCD1.callback(&RTCD1, RTC_EVENT_TIME_SET);
  }

  /* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);
}

/**
 * @brief   Get current time.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp      pointer to RTC driver structure
 * @param[out] timespec pointer to a @p RTCDateTime structure
 *
 * @notapi
 */
void rtc_lld_get_time(RTCDriver* rtcp, RTCDateTime* timespec) {

  (void)rtcp;
  syssts_t sts;
  uint32_t cnt, precnt;
  uint32_t ovf_counter, tv_sec, tv_msec;

  /* Entering a reentrant critical zone.*/
  sts = osalSysGetStatusAndLockX();

  /* Cache overflow counter. */
  ovf_counter = rtc.ovf_counter;

  /* Repeated registers read until both registers are corellated. */
  #if EFR32_RTC_HAS_SUBSECONDS
  do {
    cnt = BURTC->CNT;
    precnt = BURTC->PRECNT;
  }
  while ((cnt != BURTC->CNT) && (precnt != BURTC->PRECNT));
  #else
  cnt = BURTC->CNT;
  precnt = 0U;
  #endif

  /* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);

  cnt = (cnt & _BURTC_CNT_CNT_MASK) >> _BURTC_CNT_CNT_SHIFT;
  precnt = (precnt & _BURTC_PRECNT_PRECNT_MASK) >> _BURTC_PRECNT_PRECNT_SHIFT;

  tv_sec = EFR32_OVERFLOW_SCALE(ovf_counter) + cnt / EFR32_RTCCLK;
  tv_msec = 1000U * precnt / ((_BURTC_PRECNT_PRECNT_MASK >> _BURTC_PRECNT_PRECNT_SHIFT) + 1U);

  _rtc_lld_to_timespec(tv_sec, timespec, tv_msec);
}

#if (RTC_ALARMS > 0) || defined(__DOXYGEN__)
/**
 * @brief   Set alarm time.
 * @note    Default value after BKP domain reset for both comparators is 0.
 * @note    Function does not performs any checks of alarm time validity.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp      pointer to RTC driver structure.
 * @param[in] alarm     alarm identifier. Can only be 0.
 * @param[in] alarmspec pointer to a @p RTCAlarm structure.
 *
 * @notapi
 */
void rtc_lld_set_alarm(RTCDriver* rtcp,
                       rtcalarm_t alarm,
                       const RTCAlarm* alarmspec) {

  (void)rtcp;
  syssts_t sts;
  uint32_t cnt;

  osalDbgAssert(alarm == 0, "unknown alarm");

  if (alarm == 0) {

    /* Entering a reentrant critical zone.*/
    sts = osalSysGetStatusAndLockX();

    if (alarmspec != NULL) {
      /* Enable alarm. */

      cnt = BURTC->CNT;
      cnt = (cnt & _BURTC_CNT_CNT_MASK) >> _BURTC_CNT_CNT_SHIFT;

      /* Can overflow but don't care. */
      cnt = (cnt / EFR32_RTCCLK + alarmspec->sec) * EFR32_RTCCLK;

      BURTC->COMP = cnt;
      BURTC->IEN_SET = BURTC_IEN_COMP;
    } else {
      /* Disable alarm. */
      BURTC->IEN_CLR = BURTC_IEN_COMP;
    }

    BURTC->IF_CLR = BURTC_IF_COMP;

    /* Leaving a reentrant critical zone.*/
    osalSysRestoreStatusX(sts);
  }
}

/**
 * @brief   Get alarm time.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp       pointer to RTC driver structure
 * @param[in] alarm      alarm identifier
 * @param[out] alarmspec pointer to a @p RTCAlarm structure
 *
 * @notapi
 */
void rtc_lld_get_alarm(RTCDriver* rtcp,
                       rtcalarm_t alarm,
                       RTCAlarm* alarmspec) {

  (void)rtcp;
  syssts_t sts;
  uint32_t cnt, comp;

  if (alarm == 0) {
    /* Entering a reentrant critical zone.*/
    sts = osalSysGetStatusAndLockX();

    comp = BURTC->COMP;
    comp = (comp & _BURTC_COMP_COMP_MASK) >> _BURTC_COMP_COMP_SHIFT;

    cnt = BURTC->CNT;
    cnt = (cnt & _BURTC_CNT_CNT_MASK) >> _BURTC_CNT_CNT_SHIFT;

    /* Leaving a reentrant critical zone.*/
    osalSysRestoreStatusX(sts);

    if (comp > cnt) {
      alarmspec->sec = (comp - cnt) / EFR32_RTCCLK;
    } else {
      alarmspec->sec = 0;
    }
  }
}
#endif /* RTC_ALARMS > 0 */

/**
 * @brief   Enables or disables RTC callbacks.
 * @details This function enables or disables callbacks, use a @p NULL pointer
 *          in order to disable a callback.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp      pointer to RTC driver structure
 * @param[in] callback  callback function pointer or @p NULL
 *
 * @notapi
 */
void rtc_lld_set_callback(RTCDriver* rtcp, rtccb_t callback) {

  rtcp->callback = callback;
}

#endif /* HAL_USE_RTC */

/** @} */