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

#if (HAL_USE_RTC == TRUE) && (HAL_USE_BURAM == TRUE) || defined(__DOXYGEN__)

#include "hal_buram.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/**
 * EFR32_RTCCLK_DIV is more or less arbitrary. The smaller the value
 * the often overflow interrupt will occur. To avoid frequent occurance
 * of interrupts set the value as high as possible.
 */

#if EFR32_BURTCCLK == 1000U /* Clock source is ULFRCO. */
#define EFR32_RTCCLK_DIV 1U
#define EFR32_BURTC_CFG_CNTPRESC  BURTC_CFG_CNTPRESC_DIV1
#elif EFR32_BURTCCLK == 32768U /* Clock source is LFXO or LFRCO. */
#define EFR32_RTCCLK_DIV 1U
#define EFR32_BURTC_CFG_CNTPRESC  BURTC_CFG_CNTPRESC_DIV1
#else
#error "EFR32_RTCCLK_DIV is not obtainable"
#endif

#define EFR32_RTCCLK                (EFR32_BURTCCLK / EFR32_RTCCLK_DIV)

#define EFR32_RTC_OVERFLOW_VALUE    ((_BURTC_CNT_CNT_MASK >> _BURTC_CNT_CNT_SHIFT) + 1UL)

#define EFR32_RTC_OVERFLOW_INTERVAL (EFR32_RTC_OVERFLOW_VALUE / EFR32_RTCCLK)

#define EFR32_RTC_OVERFLOW_INTERVAL_REMAINDER \
                                    (EFR32_RTC_OVERFLOW_VALUE % EFR32_RTCCLK)

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

static const int rtc_day_offset_by_month[2][12] = {
  [0] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 },
  [1] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 }
};

static const int rtc_day_of_the_week[7] = {
  RTC_DAY_SUNDAY, RTC_DAY_MONDAY, RTC_DAY_TUESDAY, RTC_DAY_WEDNESDAY,
  RTC_DAY_THURSDAY, RTC_DAY_FRIDAY, RTC_DAY_SATURDAY
};

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

__STATIC_INLINE void _rtc_lld_to_timespec_slow(uint32_t tv_sec, uint32_t tv_msec, RTCDateTime* timespec, uint32_t dstflag) {

  int year = RTC_BASE_YEAR;
  int day = tv_sec / 86400;

  /* Seconds left after all days are subtracted. */
  tv_sec = tv_sec % 86400;

  /* Calculate year in 4 years steps. */
  do {
    int days_in_4years = isleap(year) ? (1 + 4 * 365) : (4 * 365);

    if (day < days_in_4years)
      break;

    day -= days_in_4years;
    year += 4;
  }
  while (true);

  /* Further calculate year in 1 years steps. */
  do {
    int days_in_1year = isleap(year) ? (1 + 1 * 365) : (1 * 365);

    if (day < days_in_1year)
      break;

    day -= days_in_1year;
    year += 1;
  }
  while (true);

  /* Calculate month. */
  int month = 0;
  const int *day_offset_by_month = isleap(year) ?
                                   &rtc_day_offset_by_month[1][0] :
                                   &rtc_day_offset_by_month[0][0];  
  for (int end = 12; month != end;) {
    int mid = (month + end) / 2;

    if (day_offset_by_month[mid] <= day) {
      month = mid + 1;
    }
    else {
      end = mid;
    }
  }

  day -= day_offset_by_month[month - 1];

  day += 1; /* 0 .. 30 -> 1 .. 31 */;

  timespec->millisecond = tv_sec * 1000U + tv_msec;
  timespec->dstflag = dstflag;
  timespec->year = year  - RTC_BASE_YEAR;
  timespec->month = month;
  timespec->day = day;
  int dayofweek = _rtc_lld_wday(year, month, day);
  /* wday 0 .. 6: Sun .. Sat -> 1 .. 7: Mon .. Sun */
  timespec->dayofweek = rtc_day_of_the_week[dayofweek];
}

__STATIC_INLINE void _rtc_lld_to_timespec_approx(uint32_t tv_sec, uint32_t tv_msec, RTCDateTime* timespec, uint32_t dstflag) {

  int day = tv_sec / 86400;

  /* Seconds left after subtracting of all days. */
  tv_sec -= day * 86400;

  /* Every fourth year from 1980 to 2096 is leap year, so we can use that
     formula for the next 70 years. */
  int year = (day * 4) / (365 * 4 + 1);

  day -= year * 365 + (year + 3) / 4;

  year += RTC_BASE_YEAR;

  /* Calculate month. */
  const int *day_offset_by_month = isleap(year) ?
                                   &rtc_day_offset_by_month[1][0] :
                                   &rtc_day_offset_by_month[0][0];
  int month = 0;
  for (int end = 12; month != end;) {
    int mid = (month + end) / 2;

    if (day_offset_by_month[mid] <= day) {
      month = mid + 1;
    }
    else {
      end = mid;
    }
  }

  day -= day_offset_by_month[month - 1];

  day += 1; /* 0 .. 30 -> 1 .. 31 */;

  timespec->millisecond = tv_sec * 1000U + tv_msec;
  timespec->dstflag = dstflag;
  timespec->year = year - RTC_BASE_YEAR;
  timespec->month = month;
  timespec->day = day;
  int dayofweek = _rtc_lld_wday(year, month, day);
  /* wday 0 .. 6: Sun .. Sat -> 1 .. 7: Mon .. Sun */
  timespec->dayofweek = rtc_day_of_the_week[dayofweek];
}

__STATIC_INLINE void _rtc_lld_to_timespec(uint32_t tv_sec, uint32_t tv_msec, RTCDateTime* timespec, uint32_t dstflag) {

  return _rtc_lld_to_timespec_approx(tv_sec, tv_msec, timespec, dstflag);
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

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
    #if EFR32_RTC_USE_RTC1 == TRUE
    /* Increment overflow counter in order of tracking time. */
    *(RTCD1.ovf_counter) += 1U;

    if (RTCD1.callback != NULL) {
      RTCD1.callback(&RTCD1, RTC_EVENT_TS_OVF);
    }
    #endif
  }

  if ((isr & _BURTC_IF_COMP_MASK) == BURTC_IF_COMP) {
    /* Disable alarm. */
    BURTC->IEN_CLR = BURTC_IEN_COMP;

    #if EFR32_RTC_USE_RTC1 == TRUE
    if (RTCD1.callback != NULL) {
      RTCD1.callback(&RTCD1, RTC_EVENT_ALARM);
    }
    #endif
  }

  OSAL_IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Enable access to registers.
 *
 * @notapi
 */
void rtc_lld_init(void) {

#if EFR32_RTC_USE_RTC1 == TRUE
  /* RTC object initialization. */
  rtcObjectInit(&RTCD1);

  /* Callback initially disabled. */
  RTCD1.callback = NULL;

  /* Get data from backup RAM which survives restart. */
  RTCD1.ovf_counter = buramAllocateAtI(&BURAMD1, 0, 4);
  RTCD1.tv_sec = buramAllocateAtI(&BURAMD1, 4, 4);
  RTCD1.tv_msec = buramAllocateAtI(&BURAMD1, 8, 4);
  RTCD1.dstflag = buramAllocateAtI(&BURAMD1, 12, 4);
#endif

  /* Enable clock. */
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

    /* Clear counter. */
    BURTC->CNT_CLR = _BURTC_CNT_CNT_MASK;

    #if EFR32_RTC_USE_RTC1 == TRUE
    *(RTCD1.ovf_counter) = 0U;
    *(RTCD1.tv_sec) = 0U;
    *(RTCD1.tv_msec) = 0U;
    *(RTCD1.dstflag) = 0U;
    #endif

    /* Clear interrupt flags. */
    BURTC->IF_CLR = _BURTC_IF_MASK;

    /* Enable interrupts. */
    BURTC->IEN_CLR = _BURTC_IEN_MASK;
    BURTC->IEN_SET = BURTC_IEN_OF;
  }
  else {

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

__STATIC_INLINE void rtc_lld_set_time_slow(RTCDriver* rtcp, const RTCDateTime* timespec) {

  syssts_t sts;
  uint32_t tv_sec, tv_msec;

  /* Number of leap corrections to apply up to end of last year. */
  const int leap_days_to_rtc_base_year = (RTC_BASE_YEAR - 1) / 4 -
                                         (RTC_BASE_YEAR - 1) / 100 +
                                         (RTC_BASE_YEAR - 1) / 400;

  const int last_year = (RTC_BASE_YEAR - 1) + timespec->year;

  const int leap_days_to_last_year = last_year / 4 -
                                     last_year / 100 +
                                     last_year / 400 -
                                     leap_days_to_rtc_base_year;

  const int month = timespec->month - 1; /* 1 .. 12 -> 0 .. 11 */

  int day = timespec->day - 1; /* 1 .. 31 -> 0 .. 30 */

  const int *day_offset_by_month = isleap(RTC_BASE_YEAR + timespec->year) ?
                                   &rtc_day_offset_by_month[1][0] :
                                   &rtc_day_offset_by_month[0][0];

  day += timespec->year * 365 + leap_days_to_last_year +
         day_offset_by_month[month];

  tv_sec = day * 86400 + timespec->millisecond / 1000;
  tv_msec = timespec->millisecond % 1000;

  /* Entering a reentrant critical zone. */
  sts = osalSysGetStatusAndLockX();

  /* Clear all counters resetting the overflow counter as well. */
  BURTC->CNT_CLR = _BURTC_CNT_CNT_MASK;

  *(rtcp->ovf_counter) = 0U;
  *(rtcp->tv_sec) = tv_sec;
  *(rtcp->tv_msec) = tv_msec;
  *(rtcp->dstflag) = timespec->dstflag;

  while ((BURTC->SYNCBUSY & _BURTC_SYNCBUSY_MASK) != 0U);

  if (rtcp->callback != NULL) {
    rtcp->callback(rtcp, RTC_EVENT_TIME_SET);
  }

/* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);
}

__STATIC_INLINE void rtc_lld_set_time_approx(RTCDriver *rtcp, const RTCDateTime *timespec) {

  syssts_t sts;
  uint32_t tv_sec, tv_msec;

  int year = timespec->year;

  const int *day_offset_by_month = isleap(RTC_BASE_YEAR + year) ?
                                   &rtc_day_offset_by_month[1][0] :
                                   &rtc_day_offset_by_month[0][0];

  int month = timespec->month - 1; /* 1 .. 12 -> 0 .. 11 */

  int day = timespec->day - 1; /* 1 .. 31 -> 0 .. 30 */

  day += year * 365 + (year + 3) / 4 + day_offset_by_month[month];

  tv_sec = day * 86400 + timespec->millisecond / 1000;
  tv_msec = timespec->millisecond % 1000;

  /* Entering a reentrant critical zone. */
  sts = osalSysGetStatusAndLockX();

  /* Clear all counters resetting the overflow counter as well. */
  BURTC->CNT_CLR = _BURTC_CNT_CNT_MASK;

  *(rtcp->ovf_counter) = 0U;
  *(rtcp->tv_sec) = tv_sec;
  *(rtcp->tv_msec) = tv_msec;
  *(rtcp->dstflag) = timespec->dstflag;

  while ((BURTC->SYNCBUSY & _BURTC_SYNCBUSY_MASK) != 0U);

  if (rtcp->callback != NULL) {
    rtcp->callback(rtcp, RTC_EVENT_TIME_SET);
  }

/* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);
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
void rtc_lld_set_time(RTCDriver *rtcp, const RTCDateTime *timespec) {

  return rtc_lld_set_time_approx(rtcp, timespec);
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

  syssts_t sts;
  uint32_t cnt;
  uint32_t ovf_counter, tv_sec, tv_msec, dstflag;

  /* Entering a reentrant critical zone.*/
  sts = osalSysGetStatusAndLockX();

  /* Cache overflow counter. */
  ovf_counter = *(rtcp->ovf_counter);
  tv_sec = *(rtcp->tv_sec);
  tv_msec = *(rtcp->tv_msec);
  dstflag = *(rtcp->dstflag);

  /* Read counter. */
  cnt = BURTC->CNT;

  /* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);

  tv_sec += (ovf_counter * EFR32_RTC_OVERFLOW_INTERVAL) +
            (ovf_counter * EFR32_RTC_OVERFLOW_INTERVAL_REMAINDER) / EFR32_RTCCLK +
            (cnt / EFR32_RTCCLK);

  tv_msec += (cnt % EFR32_RTCCLK * 1000U) / EFR32_RTCCLK;

  tv_sec += tv_msec / 1000U;
  tv_msec = tv_msec % 1000U;

  _rtc_lld_to_timespec(tv_sec, tv_msec, timespec, dstflag);
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

      /* Can overflow but don't care. */
      cnt += (alarmspec->tv_sec * EFR32_RTCCLK) +
             (alarmspec->tv_usec * EFR32_RTCCLK) / 1000000U;

      BURTC->COMP = cnt;

      /* Enable alarm. */
      BURTC->IEN_SET = BURTC_IEN_COMP;
    }
    else {
      /* Disable alarm. */
      BURTC->IEN_CLR = BURTC_IEN_COMP;
    }

    /* Clear alarm interrupt flag. */
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

    cnt = BURTC->CNT;

    /* Leaving a reentrant critical zone.*/
    osalSysRestoreStatusX(sts);

    uint32_t diff_comp_cnt = comp - cnt;

    if (diff_comp_cnt > 0U) {
      alarmspec->tv_sec = diff_comp_cnt / EFR32_RTCCLK;
      alarmspec->tv_usec = (diff_comp_cnt % EFR32_RTCCLK * 1000000U) / EFR32_RTCCLK;
    }
    else {
      alarmspec->tv_sec = 0;
      alarmspec->tv_usec = 0;
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

  syssts_t sts;

  /* Entering a reentrant critical zone.*/
  sts = osalSysGetStatusAndLockX();

  rtcp->callback = callback;

  /* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);
}

#endif /* HAL_USE_RTC */

/** @} */
