/*
    Copyright (C) 2026 Dimitris Mantzouranis

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
 * @file    RTC/hal_rtc_lld.c
 * @brief   SN32 RTC subsystem low level driver source.
 *
 * @addtogroup RTC
 * @{
 */

#include "hal.h"

#if HAL_USE_RTC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief RTC driver identifier.
 */
RTCDriver RTCD1;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/**
 * @brief   Software-maintained RTC time.
 * @note    The SN32 RTC only provides a periodic second interrupt. Absolute
 *          time is maintained entirely in software.
 */
static volatile time_t rtc_time;

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Converts time from timespec to seconds counter.
 *
 * @param[in] timespec  pointer to a @p RTCDateTime structure
 * @return              the TR register encoding.
 *
 * @notapi
 */
static time_t rtc_encode(const RTCDateTime *timespec) {
  struct tm tim;

  rtcConvertDateTimeToStructTm(timespec, &tim, NULL);
  return mktime(&tim);
}

/**
 * @brief   Converts time from seconds/milliseconds to timespec.
 *
 * @param[in] tv_sec      seconds value
 * @param[in] tv_msec     milliseconds value
 * @param[out] timespec   pointer to a @p RTCDateTime structure
 *
 * @notapi
 */
static void rtc_decode(time_t tv_sec,
                       uint32_t tv_msec,
                       RTCDateTime *timespec) {
  struct tm tim;
  struct tm *t;

  /* If the conversion is successful the function returns a pointer
     to the object the result was written into.*/
#if defined(__GNUC__) || defined(__CC_ARM)
  t = localtime_r(&tv_sec, &tim);
  osalDbgAssert(t != NULL, "conversion failed");
#else
  t = localtime(&tv_sec);
  osalDbgAssert(t != NULL, "conversion failed");
  memcpy(&tim, t, sizeof(struct tm));
#endif

  rtcConvertStructTmToDateTime(&tim, tv_msec, timespec);
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/**
 * @brief   RTC interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SN32_RTC_HANDLER) {
  uint32_t flags;

  OSAL_IRQ_PROLOGUE();

  flags = RTCD1.rtc->RIS;
  RTCD1.rtc->IC = flags;

  if (flags & mskRTC_SECIF) {
    rtc_time++;

    if (RTCD1.callback != NULL) {
      RTCD1.callback(&RTCD1, RTC_EVENT_SECOND);
    }
  }

  OSAL_IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Initialize RTC.
 *
 * @notapi
 */
void rtc_lld_init(void) {

  /* RTC object initialization.*/
  rtcObjectInit(&RTCD1);

  /* RTC pointer initialization.*/
  RTCD1.rtc = SN_RTC;
  rtc_time = (time_t)0;

  /* Clock activation.*/
  sys1EnableRTC();

  /* All interrupts initially disabled.*/
  RTCD1.rtc->IE = 0;

#if SN32_RTC_CLK_SOURCE == SN32_RTC_CLK_SRC_XTAL
  RTCD1.rtc->CLKS |= 1U;
#else
  RTCD1.rtc->CLKS &= ~1U;
#endif

  /*
   * Configure a 1 Hz period.
   * The Sonix RTC is a periodic counter rather than a calendar RTC.
   */
  rtc_lld_set_period(&RTCD1, SN32_RTC_PERIOD_DEFAULT);

  /* Callback initially disabled.*/
  RTCD1.callback = NULL;

  /* IRQ vector permanently assigned to this driver.*/
  nvicEnableVector(SN32_RTC_NUMBER, SN32_RTC_IRQ_PRIORITY);

  RTCD1.rtc->CTRL |= mskRTC_RTCEN_ENABLE;
}

/**
 * @brief   Set current time.
 * @note    Fractional part will be silently ignored. There is no possibility
 *          to change it on SN32F1xx platform.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp      pointer to RTC driver structure
 * @param[in] timespec  pointer to a @p RTCDateTime structure
 *
 * @notapi
 */
void rtc_lld_set_time(RTCDriver *rtcp, const RTCDateTime *timespec) {
  syssts_t sts;

  (void)rtcp;

  sts = osalSysGetStatusAndLockX();
  rtc_time = rtc_encode(timespec);
  osalSysRestoreStatusX(sts);
}

/**
 * @brief   Get current time.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp      pointer to RTC driver structure
 * @param[in] timespec  pointer to a @p RTCDateTime structure
 *
 * @notapi
 */
void rtc_lld_get_time(RTCDriver *rtcp, RTCDateTime *timespec) {
  syssts_t sts;
  time_t t;

  (void)rtcp;

  sts = osalSysGetStatusAndLockX();
  t = rtc_time;
  osalSysRestoreStatusX(sts);

  rtc_decode(t, 0, timespec);
}


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
  syssts_t sts;

  /* Entering a reentrant critical zone.*/
  sts = osalSysGetStatusAndLockX();

  if (callback != NULL) {

    /* IRQ sources enabled only after setting up the callback.*/
    rtcp->callback = callback;

    rtcp->rtc->IC = mskRTC_SECIC;
    rtcp->rtc->IE = mskRTC_SECIE;
  }
  else {
    rtcp->rtc->IE = 0;

    /* Callback set to NULL only after disabling the IRQ sources.*/
    rtcp->callback = NULL;
  }

  /* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);
}

/**
 * @brief   Set RTC second counter period.
 * @details The period value controls the number of RTC clock cycles before
 *          a second event is generated.
 * @note    The SN32 RTC period register is limited to 20 bits.
 *          Values exceeding the maximum are silently clamped.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp      pointer to RTC driver structure
 * @param[in] period    second counter reload value
 *
 * @notapi
 */
void rtc_lld_set_period(RTCDriver *rtcp, uint32_t period) {
  syssts_t sts;

  if (period > SN32_RTC_PERIOD_MAX) {
    period = SN32_RTC_PERIOD_MAX;
  }

  sts = osalSysGetStatusAndLockX();

  rtcp->period = period;
  rtcp->rtc->SECCNTV = period;

  osalSysRestoreStatusX(sts);
}

/**
 * @brief   Gets RTC second counter period.
 *
 * @param[in] rtcp      pointer to RTC driver structure
 *
 * @return              the current RTC period value.
 *
 * @notapi
 */
uint32_t rtc_lld_get_period(RTCDriver *rtcp) {
  uint32_t period;
  syssts_t sts;

  sts = osalSysGetStatusAndLockX();

  period = rtcp->period;

  osalSysRestoreStatusX(sts);

  return period;
}

#endif /* HAL_USE_RTC */

/** @} */