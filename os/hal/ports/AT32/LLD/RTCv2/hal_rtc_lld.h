/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian

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
 * @file    RTCv2/hal_rtc_lld.h
 * @brief   AT32 ERTC low level driver header.
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
 * @brief   Callback support int the driver.
 */
#define RTC_SUPPORTS_CALLBACKS      TRUE

/**
 * @brief   Number of alarms available.
 */
#define RTC_ALARMS                  AT32_ERTC_NUM_ALARMS

/**
 * @brief   Presence of a local persistent storage.
 */
#define RTC_HAS_STORAGE             (AT32_ERTC_STORAGE_SIZE > 0)
/** @} */

/**
 * @brief   ERTC DIV register initializer.
 */
#define ERTC_DIV(a, s)              ((((a) - 1) << 16) | ((s) - 1))

/**
 * @name    Alarm helper macros
 * @{
 */
#define ERTC_ALRM_MASK4             (1U << 31)
#define ERTC_ALRM_WKSEL             (1U << 30)
#define ERTC_ALRM_DT(n)             ((n) << 28)
#define ERTC_ALRM_DU(n)             ((n) << 24)
#define ERTC_ALRM_MASK3             (1U << 23)
#define ERTC_ALRM_HT(n)             ((n) << 20)
#define ERTC_ALRM_HU(n)             ((n) << 16)
#define ERTC_ALRM_MASK2             (1U << 15)
#define ERTC_ALRM_MT(n)             ((n) << 12)
#define ERTC_ALRM_MU(n)             ((n) << 8)
#define ERTC_ALRM_MASK1             (1U << 7)
#define ERTC_ALRM_ST(n)             ((n) << 4)
#define ERTC_ALRM_SU(n)             ((n) << 0)
/** @} */

/* Requires services from the EXINT driver.*/
#if !defined(AT32_EXINT_REQUIRED)
#define AT32_EXINT_REQUIRED
#endif

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   ERTC DIVA register initialization.
 * @note    The default is calculated for a 32768Hz clock.
 */
#if !defined(AT32_ERTC_DIVA_VALUE) || defined(__DOXYGEN__)
#define AT32_ERTC_DIVA_VALUE                32
#endif

/**
 * @brief   ERTC DIVB divider initialization.
 * @note    The default is calculated for a 32768Hz clock.
 */
#if !defined(AT32_ERTC_DIVB_VALUE) || defined(__DOXYGEN__)
#define AT32_ERTC_DIVB_VALUE                1024
#endif

/**
 * @brief   ERTC CTRL register initialization value.
 * @note    Use this value to initialize features not directly handled by
 *          the ERTC driver.
 */
#if !defined(AT32_ERTC_CTRL_INIT) || defined(__DOXYGEN__)
#define AT32_ERTC_CTRL_INIT                 0
#endif

/**
 * @brief   ERTC TAMP register initialization value.
 * @note    Use this value to initialize features not directly handled by
 *          the ERTC driver.
 * @note    On some devices this values goes in the similar TAMP register.
 */
#if !defined(AT32_ERTC_TAMP_INIT) || defined(__DOXYGEN__)
#define AT32_ERTC_TAMP_INIT                 0
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if HAL_USE_RTC && !AT32_HAS_ERTC
#error "ERTC not present in the selected device"
#endif

#if !defined(AT32_ERTCCLK)
#error "ERTC clock not exported by HAL layer"
#endif

#if AT32_PCLK1 < (AT32_ERTCCLK * 7)
#error "AT32_PCLK1 frequency is too low"
#endif

/**
 * @brief   Initialization for the ERTC_DIV register.
 */
#define AT32_ERTC_DIV_BITS                  ERTC_DIV(AT32_ERTC_DIVA_VALUE, \
                                                     AT32_ERTC_DIVB_VALUE)

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of an ERTC event.
 */
typedef enum {
  ERTC_EVENT_ALARM_A     = 0,           /** Alarm A.                        */
  ERTC_EVENT_ALARM_B     = 1,           /** Alarm B.                        */
  ERTC_EVENT_TS          = 2,           /** Time stamp.                     */
  ERTC_EVENT_TS_OVF      = 3,           /** Time stamp overflow.            */
  ERTC_EVENT_TAMP1       = 4,           /** Tamper 1.                       */
  ERTC_EVENT_TAMP2       = 5,           /** Tamper 2.                       */
  ERTC_EVENT_WAKEUP      = 6            /** Wakeup.                         */
 } ertcevent_t;

/**
 * @brief   Type of a generic ERTC callback.
 */
typedef void (*rtccb_t)(RTCDriver *rtcp, ertcevent_t event);

/**
 * @brief   Type of a structure representing an ERTC alarm time stamp.
 */
typedef struct hal_ertc_alarm {
  /**
   * @brief   Type of an alarm as encoded in ERTC ALx registers.
   */
  uint32_t                  alrmr;
} RTCAlarm;

#if AT32_ERTC_HAS_PERIODIC_WAKEUPS
/**
 * @brief   Type of a wakeup as encoded in ERTC WAT register.
 */
typedef struct hal_ertc_wakeup {
  /**
   * @brief   Wakeup as encoded in ERTC WAT register.
   * @note    ((WAT == 0) || (WATCLK == 3)) are a forbidden combination.
   * @note    Bits 16..18 are copied in the CTRL bits 0..2 (WATCLK).
   */
  uint32_t                  wat;
} ERTCWakeup;
#endif

/**
 * @brief   Implementation-specific @p RTCDriver fields.
 */
#define rtc_lld_driver_fields                                               \
  /* Pointer to the ERTC registers block.*/                                 \
  ERTC_TypeDef              *ertc;                                          \
  /* Callback pointer.*/                                                    \
  rtccb_t                   callback

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
#if AT32_ERTC_HAS_PERIODIC_WAKEUPS
  void ertcAT32SetPeriodicWakeup(RTCDriver *rtcp, const ERTCWakeup *wakeupspec);
  void ertcAT32GetPeriodicWakeup(RTCDriver *rtcp, ERTCWakeup *wakeupspec);
#endif /* AT32_ERTC_HAS_PERIODIC_WAKEUPS */
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_RTC */

#endif /* HAL_RTC_LLD_H */

/** @} */
