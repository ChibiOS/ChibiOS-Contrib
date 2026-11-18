/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    Copyright (C) 2026 QMK

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
 * @file    SK32F0xx/hal_rtc_lld.c
 * @brief   SK32F0xx RTC low level driver.
 *
 * @addtogroup RTC
 * @{
 */

#include "hal.h"

#if HAL_USE_RTC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define RTC_TR_HT_OFFSET                    20
#define RTC_TR_HU_OFFSET                    16
#define RTC_TR_MNT_OFFSET                   12
#define RTC_TR_MNU_OFFSET                   8
#define RTC_TR_ST_OFFSET                    4
#define RTC_TR_SU_OFFSET                    0

#define RTC_DR_YT_OFFSET                    20
#define RTC_DR_YU_OFFSET                    16
#define RTC_DR_WDU_OFFSET                   13
#define RTC_DR_MT_OFFSET                    12
#define RTC_DR_MU_OFFSET                    8
#define RTC_DR_DT_OFFSET                    4
#define RTC_DR_DU_OFFSET                    0

#define RTC_CR_BKP_OFFSET                   18

/* Write protection keys of the WPR register.*/
#define SK32_RTC_WPR_KEY1                   0xCAU
#define SK32_RTC_WPR_KEY2                   0x53U

/* Bounded polling count used while waiting for the oscillator or the RTC
   state machine, prevents a deadlock if the clock source is not populated.*/
#define SK32_RTC_TIMEOUT                    0x000FFFFFU

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   RTC driver identifier.
 */
RTCDriver RTCD1;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Beginning of configuration procedure.
 *
 * @notapi
 */
static void rtc_enter_init(void) {
  uint32_t n;

  RTCD1.rtc->ISR |= RTC_ISR_INIT;
  for (n = 0U; ((RTCD1.rtc->ISR & RTC_ISR_INITF) == 0U) &&
               (n < SK32_RTC_TIMEOUT); n++) {
  }
}

/**
 * @brief   Finalizing of configuration procedure.
 *
 * @notapi
 */
static inline void rtc_exit_init(void) {

  RTCD1.rtc->ISR &= ~RTC_ISR_INIT;
}

/**
 * @brief   Converts time from TR register encoding to timespec.
 *
 * @param[in] tr        TR register value
 * @param[out] timespec pointer to a @p RTCDateTime structure
 *
 * @notapi
 */
static void rtc_decode_time(uint32_t tr, RTCDateTime *timespec) {
  uint32_t n;

  n  = ((tr >> RTC_TR_HT_OFFSET) & 3)   * 36000000;
  n += ((tr >> RTC_TR_HU_OFFSET) & 15)  * 3600000;
  n += ((tr >> RTC_TR_MNT_OFFSET) & 7)  * 600000;
  n += ((tr >> RTC_TR_MNU_OFFSET) & 15) * 60000;
  n += ((tr >> RTC_TR_ST_OFFSET) & 7)   * 10000;
  n += ((tr >> RTC_TR_SU_OFFSET) & 15)  * 1000;
  timespec->millisecond = n;
}

/**
 * @brief   Converts date from DR register encoding to timespec.
 *
 * @param[in] dr        DR register value
 * @param[out] timespec pointer to a @p RTCDateTime structure
 *
 * @notapi
 */
static void rtc_decode_date(uint32_t dr, RTCDateTime *timespec) {

  timespec->year  = (((dr >> RTC_DR_YT_OFFSET) & 15) * 10) +
                     ((dr >> RTC_DR_YU_OFFSET) & 15);
  timespec->month = (((dr >> RTC_DR_MT_OFFSET) & 1) * 10) +
                     ((dr >> RTC_DR_MU_OFFSET) & 15);
  timespec->day   = (((dr >> RTC_DR_DT_OFFSET) & 3) * 10) +
                     ((dr >> RTC_DR_DU_OFFSET) & 15);
  timespec->dayofweek = (dr >> RTC_DR_WDU_OFFSET) & 7;
}

/**
 * @brief   Converts time from timespec to TR register encoding.
 *
 * @param[in] timespec  pointer to a @p RTCDateTime structure
 * @return              the TR register encoding.
 *
 * @notapi
 */
static uint32_t rtc_encode_time(const RTCDateTime *timespec) {
  uint32_t n, tr = 0;

  /* Subseconds cannot be set.*/
  n = timespec->millisecond / 1000;

  /* Seconds conversion.*/
  tr = tr | ((n % 10) << RTC_TR_SU_OFFSET);
  n /= 10;
  tr = tr | ((n % 6) << RTC_TR_ST_OFFSET);
  n /= 6;

  /* Minutes conversion.*/
  tr = tr | ((n % 10) << RTC_TR_MNU_OFFSET);
  n /= 10;
  tr = tr | ((n % 6) << RTC_TR_MNT_OFFSET);
  n /= 6;

  /* Hours conversion.*/
  tr = tr | ((n % 10) << RTC_TR_HU_OFFSET);
  n /= 10;
  tr = tr | (n << RTC_TR_HT_OFFSET);

  return tr;
}

/**
 * @brief   Converts a date from timespec to DR register encoding.
 *
 * @param[in] timespec  pointer to a @p RTCDateTime structure
 * @return              the DR register encoding.
 *
 * @notapi
 */
static uint32_t rtc_encode_date(const RTCDateTime *timespec) {
  uint32_t n, dr = 0;

  /* Year conversion. Note, only years last two digits are considered.*/
  n = timespec->year;
  dr = dr | ((n % 10) << RTC_DR_YU_OFFSET);
  n /= 10;
  dr = dr | ((n % 10) << RTC_DR_YT_OFFSET);

  /* Months conversion.*/
  n = timespec->month;
  dr = dr | ((n % 10) << RTC_DR_MU_OFFSET);
  n /= 10;
  dr = dr | ((n % 10) << RTC_DR_MT_OFFSET);

  /* Days conversion.*/
  n = timespec->day;
  dr = dr | ((n % 10) << RTC_DR_DU_OFFSET);
  n /= 10;
  dr = dr | ((n % 10) << RTC_DR_DT_OFFSET);

  /* Days of week conversion.*/
  dr = dr | (timespec->dayofweek << RTC_DR_WDU_OFFSET);

  return dr;
}

/**
 * @brief   Backup domain and RTC clock initialization.
 * @details Unlocks the backup domain, selects the RTC clock source and
 *          enables the RTC clock.  The backup domain is reset only when no
 *          clock source is programmed yet, an already running RTC is left
 *          untouched so the calendar is preserved across resets.
 *
 * @notapi
 */
static void rtc_clock_init(void) {
  uint32_t n;

  /* The backup domain is write protected until DBP is set.*/
  rccEnablePWRInterface();
  PWR->CR |= PWR_CR_DBP;

  /* If no clock source has been selected yet the backup domain is reset so
     that a new selection can be written.*/
  if ((RCC->BDCR & RCC_BDCR_RTCSEL) == 0U) {
    RCC->BDCR |= RCC_BDCR_BDRST;
    RCC->BDCR &= ~RCC_BDCR_BDRST;
  }

  /* Start the oscillator used as RTC clock source.*/
#if SK32_RTC_USE_LSE
  RCC->BDCR |= RCC_BDCR_LSEON;
  for (n = 0U; ((RCC->BDCR & RCC_BDCR_LSERDY) == 0U) &&
               (n < SK32_RTC_TIMEOUT); n++) {
  }
#else
  RCC->CSR |= RCC_CSR_LSION;
  for (n = 0U; ((RCC->CSR & RCC_CSR_LSIRDY) == 0U) &&
               (n < SK32_RTC_TIMEOUT); n++) {
  }
#endif

  /* Clock source selection and RTC clock enable.*/
  RCC->BDCR = (RCC->BDCR & ~RCC_BDCR_RTCSEL) | SK32_RTC_CLOCK_SOURCE;
  RCC->BDCR |= RCC_BDCR_RTCEN;
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if !defined(SK32_RTC_SUPPRESS_ISR)
#if !defined(SK32_RTC_HANDLER)
#error "SK32_RTC_HANDLER not defined"
#endif
/**
 * @brief   RTC interrupt handler.
 * @details All the RTC events (alarm A, wakeup, timestamp) share this vector.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SK32_RTC_HANDLER) {
  uint32_t isr, clear;

  OSAL_IRQ_PROLOGUE();

  clear = (0U
           | RTC_ISR_ALRAF
           | RTC_ISR_WUTF
           | RTC_ISR_TSF
           | RTC_ISR_TSOVF
          );

  isr = RTCD1.rtc->ISR;

  /* The event flags are cleared by writing zeroes into them.*/
  RTCD1.rtc->ISR = isr & ~clear;

  if (RTCD1.callback != NULL) {
    uint32_t cr = RTCD1.rtc->CR;

    if (((cr & RTC_CR_ALRAIE) != 0U) && ((isr & RTC_ISR_ALRAF) != 0U)) {
      RTCD1.callback(&RTCD1, RTC_EVENT_ALARM_A);
    }

    if (((cr & RTC_CR_WUTIE) != 0U) && ((isr & RTC_ISR_WUTF) != 0U)) {
      RTCD1.callback(&RTCD1, RTC_EVENT_WAKEUP);
    }

    if ((cr & RTC_CR_TSIE) != 0U) {
      if ((isr & RTC_ISR_TSF) != 0U) {
        RTCD1.callback(&RTCD1, RTC_EVENT_TS);
      }
      if ((isr & RTC_ISR_TSOVF) != 0U) {
        RTCD1.callback(&RTCD1, RTC_EVENT_TS_OVF);
      }
    }
  }

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(SK32_RTC_SUPPRESS_ISR) */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level RTC driver initialization.
 *
 * @notapi
 */
void rtc_lld_init(void) {

  /* RTC object initialization.*/
  rtcObjectInit(&RTCD1);

  /* RTC pointer initialization.*/
  RTCD1.rtc = RTC;

  /* Backup domain unlock and RTC clock source setup.*/
  rtc_clock_init();

  /* Disable write protection.*/
  RTCD1.rtc->WPR = SK32_RTC_WPR_KEY1;
  RTCD1.rtc->WPR = SK32_RTC_WPR_KEY2;

  /* If the calendar has not been initialized yet then proceed with the
     initial setup.*/
  if ((RTCD1.rtc->ISR & RTC_ISR_INITS) == 0U) {

    rtc_enter_init();

    RTCD1.rtc->CR    = SK32_RTC_CR_INIT | RTC_CR_BYPSHAD;
    RTCD1.rtc->TAFCR = SK32_RTC_TAFCR_INIT;
    RTCD1.rtc->ISR   = RTC_ISR_INIT;  /* Clearing all but RTC_ISR_INIT.    */
    RTCD1.rtc->PRER  = SK32_RTC_PRER_BITS & 0x7FFFU;
    RTCD1.rtc->PRER  = SK32_RTC_PRER_BITS;

    rtc_exit_init();
  }
  else {
    RTCD1.rtc->ISR &= ~RTC_ISR_RSF;
  }

  /* Callback initially disabled.*/
  RTCD1.callback = NULL;

  /* IRQ vector permanently assigned to this driver.*/
  nvicEnableVector(SK32_RTC_NUMBER, SK32_RTC_IRQ_PRIORITY);
}

/**
 * @brief   Set current time.
 * @note    Fractional part will be silently ignored. There is no possibility
 *          to set it on this platform.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp      pointer to RTC driver structure
 * @param[in] timespec  pointer to a @p RTCDateTime structure
 *
 * @notapi
 */
void rtc_lld_set_time(RTCDriver *rtcp, const RTCDateTime *timespec) {
  uint32_t dr, tr;
  syssts_t sts;

  tr = rtc_encode_time(timespec);
  dr = rtc_encode_date(timespec);

  /* Entering a reentrant critical zone.*/
  sts = osalSysGetStatusAndLockX();

  /* Writing the registers.*/
  rtc_enter_init();
  rtcp->rtc->TR = tr;
  rtcp->rtc->DR = dr;
  rtcp->rtc->CR = (rtcp->rtc->CR & ~(1U << RTC_CR_BKP_OFFSET)) |
                  (timespec->dstflag << RTC_CR_BKP_OFFSET);
  rtc_exit_init();

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
void rtc_lld_get_time(RTCDriver *rtcp, RTCDateTime *timespec) {
  uint32_t cr, dr, tr, prev_dr, prev_tr;
  uint32_t subs;
#if SK32_RTC_HAS_SUBSECONDS
  uint32_t ssr, prev_ssr;
#endif
  syssts_t sts;

  /* Entering a reentrant critical zone.*/
  sts = osalSysGetStatusAndLockX();

  /* Repeated registers read until two matching sets are found.*/
#if SK32_RTC_HAS_SUBSECONDS
  ssr = 0U;
  tr  = 0U;
  dr  = 0U;
  do {
    prev_ssr = ssr;
    prev_tr  = tr;
    prev_dr  = dr;
    ssr = rtcp->rtc->SSR;
    tr  = rtcp->rtc->TR;
    dr  = rtcp->rtc->DR;
  } while ((ssr != prev_ssr) || (tr != prev_tr) || (dr != prev_dr));
#else
  tr  = 0U;
  dr  = 0U;
  do {
    prev_tr  = tr;
    prev_dr  = dr;
    tr  = rtcp->rtc->TR;
    dr  = rtcp->rtc->DR;
  } while ((tr != prev_tr) || (dr != prev_dr));
#endif

  /* DST bit is in CR, no need to poll on this one.*/
  cr  = rtcp->rtc->CR;

  /* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);

  /* Decoding day time, this starts the atomic read sequence, see "Reading
     the calendar" in the RTC documentation.*/
  rtc_decode_time(tr, timespec);

  /* If the RTC is capable of sub-second counting then the value is
     normalized in milliseconds and added to the time.*/
#if SK32_RTC_HAS_SUBSECONDS
  subs = (((SK32_RTC_PRESS_VALUE - 1U) - ssr) * 1000U) / SK32_RTC_PRESS_VALUE;
#else
  subs = 0;
#endif
  timespec->millisecond += subs;

  /* Decoding date, this concludes the atomic read sequence.*/
  rtc_decode_date(dr, timespec);

  /* Retrieving the DST bit.*/
  timespec->dstflag = (cr >> RTC_CR_BKP_OFFSET) & 1;
}

#if (RTC_ALARMS > 0) || defined(__DOXYGEN__)
/**
 * @brief   Set alarm time.
 * @note    Default value after BKP domain reset for the comparator is 0.
 * @note    Function does not performs any checks of alarm time validity.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp      pointer to RTC driver structure
 * @param[in] alarm     alarm identifier, only 0 (alarm A) is supported
 * @param[in] alarmspec pointer to a @p RTCAlarm structure
 *
 * @notapi
 */
void rtc_lld_set_alarm(RTCDriver *rtcp,
                       rtcalarm_t alarm,
                       const RTCAlarm *alarmspec) {
  syssts_t sts;

  /* Entering a reentrant critical zone.*/
  sts = osalSysGetStatusAndLockX();

  if (alarm == 0) {
    if (alarmspec != NULL) {
      rtcp->rtc->CR &= ~RTC_CR_ALRAE;
      while (!(rtcp->rtc->ISR & RTC_ISR_ALRAWF))
        ;
      rtcp->rtc->ALRMAR = alarmspec->alrmr;
      rtcp->rtc->CR |= RTC_CR_ALRAE;
      rtcp->rtc->CR |= RTC_CR_ALRAIE;
    }
    else {
      rtcp->rtc->CR &= ~RTC_CR_ALRAIE;
      rtcp->rtc->CR &= ~RTC_CR_ALRAE;
    }
  }

  /* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);
}

/**
 * @brief   Get alarm time.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp       pointer to RTC driver structure
 * @param[in] alarm      alarm identifier, only 0 (alarm A) is supported
 * @param[out] alarmspec pointer to a @p RTCAlarm structure
 *
 * @notapi
 */
void rtc_lld_get_alarm(RTCDriver *rtcp,
                       rtcalarm_t alarm,
                       RTCAlarm *alarmspec) {

  if (alarm == 0)
    alarmspec->alrmr = rtcp->rtc->ALRMAR;
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
void rtc_lld_set_callback(RTCDriver *rtcp, rtccb_t callback) {

  rtcp->callback = callback;
}

#endif /* HAL_USE_RTC */

/** @} */
