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

/**
 * @file    RTC/hal_rtc_lld.h
 * @brief   SN32 RTC subsystem low level driver header.
 *
 * @addtogroup RTC
 * @{
 */

#ifndef HAL_RTC_LLD_H
#define HAL_RTC_LLD_H

#if HAL_USE_RTC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Implementation capabilities
 */
/**
 * @brief   This RTC implementation supports callbacks.
 */
#define RTC_SUPPORTS_CALLBACKS      TRUE

/**
 * @brief   No alarm comparator available.
 */
#define RTC_ALARMS                  0

/**
 * @brief   Presence of a local persistent storage.
 */
#define RTC_HAS_STORAGE             FALSE
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/*
 * RTC driver system settings.
 */
#define SN32_RTC_IRQ_PRIORITY      3
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if HAL_USE_RTC && !SN32_HAS_RTC
#error "RTC not present in the selected device"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of an RTC event.
 */
typedef enum {
  RTC_EVENT_SECOND = 0                  /** Triggered every second.         */
} rtcevent_t;

/**
 * @brief   Type of a generic RTC callback.
 */
typedef void (*rtccb_t)(RTCDriver *rtcp, rtcevent_t event);

/**
 * @brief   Type of a structure representing an RTC alarm time stamp.
 */
typedef struct hal_rtc_alarm {
  /**
   * @brief Seconds since UNIX epoch.
   */
  uint32_t          tv_sec;
} RTCAlarm;

/**
 * @brief   Implementation-specific @p RTCDriver fields.
 */
#define rtc_lld_driver_fields                                               \
  /* Pointer to the RTC registers block.*/                                  \
  RTC_TypeDef               *rtc;                                           \
  /* Callback pointer.*/                                                    \
  rtccb_t           callback

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/
  #define mskRTC_RTCEN_ENABLE     1
  #define mskRTC_SECIF            (0x1 << 0)       //Interrupt flag for Second   
  #define mskRTC_SECIC            mskRTC_SECIF
  #define mskRTC_SECIE            mskRTC_SECIF 
/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void rtc_lld_init(void);
  void rtc_lld_set_time(RTCDriver *rtcp, const RTCDateTime *timespec);
  void rtc_lld_get_time(RTCDriver *rtcp, RTCDateTime *timespec);
  void rtc_lld_set_callback(RTCDriver *rtcp, rtccb_t callback);
  void rtcSN32GetSec(RTCDriver *rtcp, uint32_t *tv_sec);
  void rtcSN32SetSec(RTCDriver *rtcp, uint32_t tv_sec);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_RTC */

#endif /* HAL_RTC_LLD_H */

/** @} */
