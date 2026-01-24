/*
    Copyright (C) 2025 Dimitris Mantzouranis

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
/*
   Concepts and parts of this file have been contributed by Uladzimir Pylinsky
   aka barthess.
 */

/**
 * @file    RTC/hal_rtc_lld.c
 * @brief   SN32 RTC subsystem low level driver header.
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
static void rtc_decode(uint32_t tv_sec,
                       uint32_t tv_msec,
                       RTCDateTime *timespec) {
  struct tm tim;
  struct tm *t;
  const time_t time = (const time_t)tv_sec;   /* Could be 64 bits.*/

  /* If the conversion is successful the function returns a pointer
     to the object the result was written into.*/
#if defined(__GNUC__) || defined(__CC_ARM)
  t = localtime_r(&time, &tim);
  osalDbgAssert(t != NULL, "conversion failed");
#else
  t = localtime(&time);
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

  if (flags & mskRTC_SECIF)
    RTCD1.callback(&RTCD1, RTC_EVENT_SECOND);

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

  /* Clock activation.*/
  sys1EnableRTC();

  /* All interrupts initially disabled.*/
  RTCD1.rtc->IE = 0;

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
  time_t tv_sec = rtc_encode(timespec);

  rtcSN32SetSec(rtcp, tv_sec);
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
  uint32_t tv_sec;

  rtcSN32GetSec(rtcp, &tv_sec);
  rtc_decode(tv_sec, 0, timespec);
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
 * @brief   Get seconds from RTC.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp      pointer to RTC driver structure
 * @param[out] tv_sec   pointer to seconds value
 *
 * @api
 */
void rtcSN32GetSec(RTCDriver *rtcp, uint32_t *tv_sec) {
  uint32_t time_frac;
  syssts_t sts;

  osalDbgCheck((NULL != tv_sec) && (NULL != rtcp));

  /* Entering a reentrant critical zone.*/
  sts = osalSysGetStatusAndLockX();

  *tv_sec = rtcp->rtc->SECCNT;

  /* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);
}

/**
 * @brief   Set seconds in RTC.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp      pointer to RTC driver structure
 * @param[in] tv_sec    seconds value
 *
 * @api
 */
void rtcSN32SetSec(RTCDriver *rtcp, uint32_t tv_sec) {
  syssts_t sts;

  osalDbgCheck(NULL != rtcp);

  /* Entering a reentrant critical zone.*/
  sts = osalSysGetStatusAndLockX();

  uint32_t reg_value = rtcp->rtc->SECCNTV;    // Read current value
  reg_value &= ~0xFFFFF;                      // Clear the lower 20 bits
  reg_value |= ((tv_sec >> 16) & 0xFFFFF);    // Set the new 20-bit value
  rtcp->rtc->SECCNTV = reg_value;             // Write back the updated value

  /* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);
}

#endif /* HAL_USE_RTC */

/** @} */
