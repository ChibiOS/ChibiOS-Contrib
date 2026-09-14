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
 * @file    SK32F0xx/hal_rtc_lld.h
 * @brief   SK32F0xx RTC subsystem low level driver header.
 * @details The SK32 RTC is a calendar unit of the backup domain, register
 *          compatible with the STM32F0 RTCv2 class with the following
 *          differences:
 *          - a single alarm comparator is present (ALRMAR, no ALRMBR),
 *          - the tamper/alternate function register is named TAFCR,
 *          - a single interrupt vector is shared by all the RTC events
 *            (no separate alarm/wakeup vectors, no EXTI routing).
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
 * @{
 */
/**
 * @brief   Callback support in the driver.
 */
#define RTC_SUPPORTS_CALLBACKS      TRUE

/**
 * @brief   Number of alarms available (only alarm A is present).
 */
#define RTC_ALARMS                  1

/**
 * @brief   Presence of a local persistent storage.
 * @note    The backup registers are not part of the SK32 RTC register block.
 */
#define RTC_HAS_STORAGE             FALSE

/**
 * @brief   The RTC has a sub-second counter (SSR register).
 */
#define SK32_RTC_HAS_SUBSECONDS     TRUE
/** @} */

/**
 * @brief   RTC PRER register initializer.
 */
#define RTC_PRER(a, s)              ((((a) - 1) << 16) | ((s) - 1))

/**
 * @name    Alarm helper macros
 * @{
 */
#define RTC_ALRM_MSK4               (1U << 31)
#define RTC_ALRM_WDSEL              (1U << 30)
#define RTC_ALRM_DT(n)              ((n) << 28)
#define RTC_ALRM_DU(n)              ((n) << 24)
#define RTC_ALRM_MSK3               (1U << 23)
#define RTC_ALRM_HT(n)              ((n) << 20)
#define RTC_ALRM_HU(n)              ((n) << 16)
#define RTC_ALRM_MSK2               (1U << 15)
#define RTC_ALRM_MNT(n)             ((n) << 12)
#define RTC_ALRM_MNU(n)             ((n) << 8)
#define RTC_ALRM_MSK1               (1U << 7)
#define RTC_ALRM_ST(n)              ((n) << 4)
#define RTC_ALRM_SU(n)              ((n) << 0)
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   Use the LSE oscillator as RTC clock source.
 * @details If set to @p TRUE the 32768Hz LSE crystal is used, otherwise the
 *          internal LSI oscillator (about 40kHz on this family).
 * @note    The default is @p FALSE.
 */
#if !defined(SK32_RTC_USE_LSE) || defined(__DOXYGEN__)
#define SK32_RTC_USE_LSE                    FALSE
#endif

/**
 * @brief   RTC PRER asynchronous prescaler value.
 * @note    Defaults to a 32768Hz clock when the LSE is used, to a 40kHz
 *          clock otherwise. Both values give a 1Hz calendar.
 */
#if !defined(SK32_RTC_PRESA_VALUE) || defined(__DOXYGEN__)
#if SK32_RTC_USE_LSE
#define SK32_RTC_PRESA_VALUE                32
#else
#define SK32_RTC_PRESA_VALUE                125
#endif
#endif

/**
 * @brief   RTC PRER synchronous prescaler value.
 */
#if !defined(SK32_RTC_PRESS_VALUE) || defined(__DOXYGEN__)
#if SK32_RTC_USE_LSE
#define SK32_RTC_PRESS_VALUE                1024
#else
#define SK32_RTC_PRESS_VALUE                320
#endif
#endif

/**
 * @brief   RTC CR register initialization value.
 * @note    Use this value to initialize features not directly handled by
 *          the RTC driver.
 */
#if !defined(SK32_RTC_CR_INIT) || defined(__DOXYGEN__)
#define SK32_RTC_CR_INIT                    0
#endif

/**
 * @brief   RTC TAFCR register initialization value.
 */
#if !defined(SK32_RTC_TAFCR_INIT) || defined(__DOXYGEN__)
#define SK32_RTC_TAFCR_INIT                 0
#endif

/**
 * @brief   RTC interrupt priority.
 */
#if !defined(SK32_RTC_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SK32_RTC_IRQ_PRIORITY               3
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !SK32_HAS_RTC
#error "RTC not present in the selected device"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(SK32_RTC_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to SK32_RTC_IRQ_PRIORITY"
#endif

#if (SK32_RTC_PRESA_VALUE < 1) || (SK32_RTC_PRESA_VALUE > 128)
#error "invalid SK32_RTC_PRESA_VALUE, range is 1..128"
#endif

#if (SK32_RTC_PRESS_VALUE < 1) || (SK32_RTC_PRESS_VALUE > 32768)
#error "invalid SK32_RTC_PRESS_VALUE, range is 1..32768"
#endif

#if SK32_RTC_USE_LSE
#define SK32_RTC_CLOCK_SOURCE               RCC_BDCR_RTCSEL_LSE
#else
#define SK32_RTC_CLOCK_SOURCE               RCC_BDCR_RTCSEL_LSI
#endif

/**
 * @brief   Initialization value for the RTC_PRER register.
 */
#define SK32_RTC_PRER_BITS                  RTC_PRER(SK32_RTC_PRESA_VALUE,   \
                                                     SK32_RTC_PRESS_VALUE)

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of an RTC event.
 */
typedef enum {
  RTC_EVENT_ALARM_A     = 0,            /**< Alarm A.                       */
  RTC_EVENT_ALARM_B     = 1,            /**< Alarm B (not present).         */
  RTC_EVENT_TS          = 2,            /**< Time stamp.                    */
  RTC_EVENT_TS_OVF      = 3,            /**< Time stamp overflow.           */
  RTC_EVENT_TAMP1       = 4,            /**< Tamper 1 (not present).        */
  RTC_EVENT_TAMP2       = 5,            /**< Tamper 2 (not present).        */
  RTC_EVENT_TAMP3       = 6,            /**< Tamper 3 (not present).        */
  RTC_EVENT_WAKEUP      = 7             /**< Wakeup.                        */
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
   * @brief   Type of an alarm as encoded in the ALRMAR register.
   */
  uint32_t                  alrmr;
} RTCAlarm;

/**
 * @brief   Implementation-specific @p RTCDriver fields.
 */
#define rtc_lld_driver_fields                                               \
  /* Pointer to the RTC registers block.*/                                  \
  RTC_TypeDef               *rtc;                                           \
  /* Callback pointer.*/                                                    \
  rtccb_t                   callback;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void rtc_lld_init(void);
  void rtc_lld_set_time(RTCDriver *rtcp, const RTCDateTime *timespec);
  void rtc_lld_get_time(RTCDriver *rtcp, RTCDateTime *timespec);
#if RTC_SUPPORTS_CALLBACKS == TRUE
  void rtc_lld_set_callback(RTCDriver *rtcp, rtccb_t callback);
#endif
#if RTC_ALARMS > 0
  void rtc_lld_set_alarm(RTCDriver *rtcp,
                         rtcalarm_t alarm,
                         const RTCAlarm *alarmspec);
  void rtc_lld_get_alarm(RTCDriver *rtcp,
                         rtcalarm_t alarm,
                         RTCAlarm *alarmspec);
#endif
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_RTC */

#endif /* HAL_RTC_LLD_H */

/** @} */
