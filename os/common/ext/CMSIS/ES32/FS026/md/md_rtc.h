/**********************************************************************************
 *
 * @file    md_rtc.h
 * @brief   header file of md_rtc.c
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov 2021     Ginger          the first version
 *          24 Mar 2022     AE Team         Modify MD Driver
 *
 * Copyright (C) Shanghai Eastsoft Microelectronics Co. Ltd. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 **********************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MD_RTC_H__
#define __MD_RTC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include <stdbool.h>
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_RTC RTC
  * @brief RTC micro driver
  * @{
  */

/** @defgroup MD_RTC_Pubulic_Types RTC Pubulic Types
  * @{
  */

/**
  * @brief  RTC Init structures definition
  */
typedef struct
{
    uint32_t Scale;       /*!< Specifies the RTC count frequency division.
                        This parameter must be a number between Min_Data = 0x00 and Max_Data = 0xFF*/

    uint32_t Pre_Scale;   /*!< Specifies the RTC count pre-divider.
                        This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x7F*/

    uint32_t Clock_Sel;   /*!< Specifies the RTC clock source selection.
                        This parameter can be a value of @ref MD_RTC_CTRL_CKSEL_LOSC
                                                         @ref MD_RTC_CTRL_CKSEL_LRC   */
} md_rtc_inittypedef;

/**
  * @brief  RTC Time structures definition
  */
typedef struct
{
    uint32_t Week;        /*!< Specifies the RTC Weekday.
                            This parameter must be a number between Min_Data = 0x01 and Max_Data = 0x7*/

    uint32_t Hour;        /*!< Specifies the RTC Hour.
                            This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x23*/

    uint32_t Min;         /*!< Specifies the RTC Minute.
                            This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x59*/

    uint32_t Sec;         /*!< Specifies the RTC Second.
                            This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x59*/
} md_rtc_timetypedef;

/**
  * @brief  RTC Date structures definition
  */
typedef struct
{
    uint32_t Year;       /*!< Specifies the RTC Year.
                           This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x99*/

    uint32_t Month;      /*!< Specifies the RTC Month.
                           This parameter must be a number between Min_Data = 0x01 and Max_Data = 0x12*/

    uint32_t Date;       /*!< Specifies the RTC Date.
                           This parameter must be a number between Min_Data = 0x01 and Max_Data = 0x31*/

} md_rtc_datetypedef;


/**
  * @brief  RTC Alarm structures definition
  */
typedef struct
{
    uint32_t AlarmYear;       /*!< Specifies the RTC Alarm Year.
                           This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x99*/

    uint32_t AlarmMonth;      /*!< Specifies the RTC Alarm Month.
                           This parameter must be a number between Min_Data = 0x01 and Max_Data = 0x12*/

    uint32_t AlarmDate;       /*!< Specifies the RTC Alarm Date.
                           This parameter must be a number between Min_Data = 0x01 and Max_Data = 0x31*/

    uint32_t AlarmWeek;        /*!< Specifies the RTC Alarm Weekday.
                            This parameter must be a number between Min_Data = 0x01 and Max_Data = 0x7*/

    uint32_t AlarmHour;        /*!< Specifies the RTC Alarm Hour.
                            This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x23*/

    uint32_t AlarmMin;         /*!< Specifies the RTC Alarm Minute.
                            This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x59*/

    uint32_t AlarmSec;         /*!< Specifies the RTC Alarm Second.
                            This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x59*/

    uint32_t AlarmMask;                   /*!< Specifies the RTC Alarm Masks.
                                             This parameter can be a value of  @ref MD_RTC_ALEN_NONE
                                                                               @ref MD_RTC_ALEN_YEAR
                                                                               @ref MD_RTC_ALEN_MONTH
                                                                               @ref MD_RTC_ALEN_DATE
                                                                               @ref MD_RTC_ALEN_WEEK
                                                                               @ref MD_RTC_ALEN_HOUR
                                                                               @ref MD_RTC_ALEN_MIN
                                                                               @ref MD_RTC_ALEN_SEC
                                                                               @ref MD_RTC_ALEN_ALL  */
    uint32_t AlarmInterrupt;              /*!< Specifies the RTC Alarm Masks.
                                             This parameter can be a value of  @ref MD_RTC_EVENT_AMALL
                                                                               @ref MD_RTC_EVENT_AYEAR
                                                                               @ref MD_RTC_EVENT_AMONTH
                                                                               @ref MD_RTC_EVENT_ADATE
                                                                               @ref MD_RTC_EVENT_AWEEK
                                                                               @ref MD_RTC_EVENT_AHOUR
                                                                               @ref MD_RTC_EVENT_AMIN
                                                                               @ref MD_RTC_EVENT_ASEC */

} md_rtc_alarmtypedef;
/**
  * @}
  */


/** @defgroup MD_RTC_Public_Macros RTC Public Macros
  * @{
  */


/**
  * @brief MD_RTC_CTRL_CKSEL_ RTC Clock Source Selection
  */
#define MD_RTC_CTRL_CKSEL_LOSC   (0X00000001UL)    /** @brief LOSC oscillator clock used as RTC clock */
#define MD_RTC_CTRL_CKSEL_LRC    (0x00000002UL)    /** @brief LRC oscillator clock used as RTC clock */

/**
  * @brief MD_RTC_WKUP_WKSCAL RTC Wakeup Counter Scale Value
  */
#define MD_RTC_WKUP_WKSCAL_DIV1   (0x00000000UL)    /** @brief Divide 1, wakeup counter will count each second. */
#define MD_RTC_WKUP_WKSCAL_DIV2   (0X00000001UL)    /** @brief Divide 2, wakeup counter will count each 1/2 second. */
#define MD_RTC_WKUP_WKSCAL_DIV4   (0x00000002UL)    /** @brief Divide 4, wakeup counter will count each 1/4 second. */
#define MD_RTC_WKUP_WKSCAL_DIV8   (0X00000003UL)    /** @brief Divide 8, wakeup counter will count each 1/8 second. */
#define MD_RTC_WKUP_WKSCAL_DIV16  (0X00000004UL)    /** @brief Divide 16, wakeup counter will count each 1/16 second. */

/**
  * @brief MD_RTC_WKUP_WKSEL RTC Wakeup Counter Events Select
  */
#define MD_RTC_WKUP_WKSEL_OFF     (0x00000000UL)    /** @brief OFF */
#define MD_RTC_WKUP_WKSEL_RTC     (0X00000001UL)    /** @brief Start counter when RTC start. */
#define MD_RTC_WKUP_WKSEL_SLEEP   (0x00000002UL)    /** @brief Start counter when receive sleep flag. */

/**
  * @brief MD_RTC_CALIB_MODE_ RTC Clock Calibration Mode
  */
#define MD_RTC_CON_MODE_INCR      (0x00000000UL)    /** @brief Increase calibration value when match calibration cycle. */
#define MD_RTC_CON_MODE_DECR      (0X00000001UL)    /** @brief DMA Decrease calibration value when match calibration cycle. */

/**
  * @brief MD_RTC_STAT_SYNDONE RTC Calendar Synchronization status
  */
#define MD_RTC_STA_SYNDONE_UNDER  (0x00000000UL)    /** @brief RTC is under Synchronization procedure */
#define MD_RTC_STA_SYNDONE_CMP    (0X00000001UL)    /** @brief RTC Synchronization procedure is Completed */

/**
  * @brief MD_RTC_BKEN_BKEN Read RTC Backup Register Enable
  */
#define MD_RTC_BKEN_RTC_REGISTER        (0x00000000UL)    /** @brief Read RTCTIME & RTCCAL From control register. */
#define MD_RTC_BKEN_BACKUP_REGISTER     (0X00000001UL)    /** @brief Read RTCTIME & RTCCAL From backup register. */

/**
  * @brief MD_RTC_ALEN Alarm switch register
  */
#define MD_RTC_ALEN_NONE      0x00000000U         /** @brief None alarm.        */
#define MD_RTC_ALEN_YEAR      (RTC_ALEN_YEAR)     /** @brief Year alarm switch. */
#define MD_RTC_ALEN_MONTH     (RTC_ALEN_MONTH)    /** @brief Month alarm switch.*/
#define MD_RTC_ALEN_DATE      (RTC_ALEN_DATE)     /** @brief Date alarm switch. */
#define MD_RTC_ALEN_WEEK      (RTC_ALEN_WEEK)     /** @brief Week alarm switch. */
#define MD_RTC_ALEN_HOUR      (RTC_ALEN_HOUR)     /** @brief Hour alarm switch. */
#define MD_RTC_ALEN_MIN       (RTC_ALEN_MIN)      /** @brief Min alarm switch.  */
#define MD_RTC_ALEN_SEC       (RTC_ALEN_SEC)      /** @brief Sec alarm switch.  */
#define MD_RTC_ALEN_ALL       (RTC_ALEN_YEAR | RTC_ALEN_MONTH | RTC_ALEN_DATE | RTC_ALEN_WEEK | RTC_ALEN_HOUR | RTC_ALEN_MIN | RTC_ALEN_SEC)    /** @brief All alarm switch. */

/**
  * @brief MD_RTC_EVENT RTC_TRIG/RTC_IER/RTC_IDR/RTC_IVS/RTC_RIF/RTC_IFM/RTC_ICR
  */
#define MD_RTC_EVENT_WKTM      (1 << 16 )    /** @brief The RTC wake-up counter has finished counting. */
#define MD_RTC_EVENT_F1HZ      (1 << 15 )    /** @brief RTC 1Hz. */
#define MD_RTC_EVENT_RYEAR     (1 << 14 )    /** @brief RTC cross the century. */
#define MD_RTC_EVENT_RMON      (1 << 13 )    /** @brief RTC cross the year. */
#define MD_RTC_EVENT_RDATE     (1 << 12 )    /** @brief RTC cross the month. */
#define MD_RTC_EVENT_RWEEK     (1 << 11 )    /** @brief RTC cross the week. */
#define MD_RTC_EVENT_RHOUR     (1 << 10 )    /** @brief RTC cross the day. */
#define MD_RTC_EVENT_RMIN      (1 <<  9 )    /** @brief RTC cross the hour. */
#define MD_RTC_EVENT_RSEC      (1 <<  8 )    /** @brief RTC cross the min. */
#define MD_RTC_EVENT_AMALL     (1 <<  7 )    /** @brief RTC full alarm clock. */
#define MD_RTC_EVENT_AYEAR     (1 <<  6 )    /** @brief RTC year alarm clock. */
#define MD_RTC_EVENT_AMONTH    (1 <<  5 )    /** @brief RTC month alarm clock. */
#define MD_RTC_EVENT_ADATE     (1 <<  4 )    /** @brief RTC date alarm clock. */
#define MD_RTC_EVENT_AWEEK     (1 <<  3 )    /** @brief RTC week alarm clock. */
#define MD_RTC_EVENT_AHOUR     (1 <<  2 )    /** @brief RTC hour alarm clock. */
#define MD_RTC_EVENT_AMIN      (1 <<  1 )    /** @brief RTC min alarm clock. */
#define MD_RTC_EVENT_ASEC      (1 <<  0 )    /** @brief RTC sec alarm clock. */

/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions RTC Public Functions
  * @{
  */

/** @defgroup MD_RTC_Public_Functions_Group2 CTRL
  * @{
  */
/**
  * @brief  Set RTC_CTRL Register
  * @param  rtc RTC Instance
  * @param  ctrl
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_contrl(RTC_TypeDef *rtc, uint32_t ctrl)
{
    WRITE_REG(RTC->CTRL, ctrl);
}

/**
  * @brief  Get RTC_CTRL Register
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_get_contrl(RTC_TypeDef *rtc)
{
    return (uint32_t) READ_REG(RTC->CTRL);
}

/**
  * @brief  Set RTC Clock Counter Scale
  * @param  rtc RTC Instance
  * @param  scale Max divider of This counter is (SCALE+1).
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_scale(RTC_TypeDef *rtc, uint32_t scale)
{
    MODIFY_REG(rtc->CTRL, RTC_CTRL_SCALE, (scale << RTC_CTRL_SCALE_POSS));
}

/**
  * @brief  Get RTC Clock Counter Scale
  * @param  rtc RTC Instance
  * @retval Max divider of This counter is (SCALE+1).
  */
__STATIC_INLINE uint32_t md_rtc_get_scale(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->CTRL, RTC_CTRL_SCALE) >> RTC_CTRL_SCALE_POSS);
}

/**
  * @brief  Set RTC Clock Counter Prescale
  * @param  rtc RTC Instance
  * @param  pscale Max divider of This counter is (PSCALE+1).
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_prescale(RTC_TypeDef *rtc, uint32_t pscale)
{
    MODIFY_REG(rtc->CTRL, RTC_CTRL_PSCALE, (pscale << RTC_CTRL_PSCALE_POSS));
}

/**
  * @brief  Get RTC Clock Counter Prescale
  * @param  rtc RTC Instance
  * @retval Max divider of This counter is (PSCALE+1).
  */
__STATIC_INLINE uint32_t md_rtc_get_prescale(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->CTRL, RTC_CTRL_PSCALE) >> RTC_CTRL_PSCALE_POSS);
}

/**
  * @brief  Set RTC Clock Source Selection
  * @param  rtc RTC Instance
  * @param  cksel This parameter can be one of the following values:
  *         @arg @ref MD_RTC_CTRL_CKSEL_LOSC
  *         @arg @ref MD_RTC_CTRL_CKSEL_LRC
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_ref_clock(RTC_TypeDef *rtc, uint32_t cksel)
{
    MODIFY_REG(rtc->CTRL, RTC_CTRL_CKSEL, cksel << RTC_CTRL_CKSEL_POSS);
}
/**
  * @brief  Get RTC Clock Source Selection
  * @param  rtc RTC Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RTC_CTRL_CKSEL_LOSC
  *         @arg @ref MD_RTC_CTRL_CKSEL_LRC
  */
__STATIC_INLINE uint32_t md_rtc_get_ref_clock(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->CTRL, RTC_CTRL_CKSEL) >> RTC_CTRL_CKSEL_POSS);
}
/**
  * @brief  Set RTC Counter Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_rtc(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->CTRL, RTC_CTRL_RTCEN);
}

/**
  * @brief  Set RTC Counter Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_rtc(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->CTRL, RTC_CTRL_RTCEN);
}

/**
  * @brief  Get Enable or Disable
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_rtc(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->CTRL, RTC_CTRL_RTCEN) == (RTC_CTRL_RTCEN));
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group3 WKUP
  * @{
  */
/**
  * @brief  Set RTC_WKUP Register
  * @param  rtc RTC Instance
  * @param  ctrl
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_wakeup(RTC_TypeDef *rtc, uint32_t wkup)
{
    WRITE_REG(RTC->WKUP, wkup);
}

/**
  * @brief  Get RTC_WKUP Register
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_get_wakeup(RTC_TypeDef *rtc)
{
    return (uint32_t) READ_REG(RTC->WKUP);
}

/**
  * @brief  Set RTC Wakeup Counter Scale Value
  * @param  rtc RTC Instance
  * @param  wkscal This parameter can be one of the following values:
  *         @arg @ref MD_RTC_WKUP_WKSCAL_DIV1
  *         @arg @ref MD_RTC_WKUP_WKSCAL_DIV2
  *         @arg @ref MD_RTC_WKUP_WKSCAL_DIV4
  *         @arg @ref MD_RTC_WKUP_WKSCAL_DIV8
  *         @arg @ref MD_RTC_WKUP_WKSCAL_DIV16
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_wakeup_count_clock(RTC_TypeDef *rtc, uint32_t wkscal)
{
    MODIFY_REG(rtc->WKUP, RTC_WKUP_WKSCAL, wkscal << RTC_WKUP_WKSCAL_POSS);
}
/**
  * @brief  Get RTC Wakeup Counter Scale Value
  * @param  rtc RTC Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RTC_WKUP_WKSCAL_DIV1
  *         @arg @ref MD_RTC_WKUP_WKSCAL_DIV2
  *         @arg @ref MD_RTC_WKUP_WKSCAL_DIV4
  *         @arg @ref MD_RTC_WKUP_WKSCAL_DIV8
  *         @arg @ref MD_RTC_WKUP_WKSCAL_DIV16
  */
__STATIC_INLINE uint32_t md_rtc_get_wakeup_count_clock(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->WKUP, RTC_WKUP_WKSCAL) >> RTC_WKUP_WKSCAL_POSS);
}
/**
  * @brief  Set RTC Wakeup Counter Events Select
  * @param  rtc RTC Instance
  * @param  wksel This parameter can be one of the following values:
  *         @arg @ref MD_RTC_WKUP_WKSEL_OFF
  *         @arg @ref MD_RTC_WKUP_WKSEL_RTC
  *         @arg @ref MD_RTC_WKUP_WKSEL_SLEEP
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_wakeup_count_event(RTC_TypeDef *rtc, uint32_t wksel)
{
    MODIFY_REG(rtc->WKUP, RTC_WKUP_WKSEL, wksel << RTC_WKUP_WKSEL_POSS);
}
/**
  * @brief  Get RTC Wakeup Counter Events Select
  * @param  rtc RTC Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RTC_WKUP_WKSEL_OFF
  *         @arg @ref MD_RTC_WKUP_WKSEL_RTC
  *         @arg @ref MD_RTC_WKUP_WKSEL_SLEEP
  */
__STATIC_INLINE uint32_t md_rtc_get_wakeup_count_event(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->WKUP, RTC_WKUP_WKSEL) >> RTC_WKUP_WKSEL_POSS);
}
/**
  * @brief  Set RTC Wakeup Counter setting value
  * @param  rtc RTC Instance
  * @param  wkcal Max value is WKCAL seconds
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_wakeup_count_reload(RTC_TypeDef *rtc, uint32_t wkcal)
{
    MODIFY_REG(rtc->WKUP, RTC_WKUP_WKCAL, wkcal);
}
/**
  * @brief  Get RTC Wakeup Counter setting value
  * @param  rtc RTC Instance
  * @retval Max value is WKCAL seconds
  */
__STATIC_INLINE uint32_t md_rtc_get_wakeup_count_reload(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->WKUP, RTC_WKUP_WKCAL));
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group4 TIME
  * @{
  */
/**
  * @brief  Set RTC_TIME Register
  * @param  rtc RTC Instance
  * @param  ctrl
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_time(RTC_TypeDef *rtc, uint32_t time)
{
    WRITE_REG(RTC->TIME, time);
}

/**
  * @brief  Get RTC_TIME Register
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_get_time(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_REG(RTC->TIME));
}

/**
  * @brief  Set Week Value
  * @param  rtc RTC Instance
  * @param  week value in RTC timer, in BCD format.
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_date_weekday(RTC_TypeDef *rtc, uint32_t week)
{
    MODIFY_REG(rtc->TIME, RTC_TIME_WEEK, (week << RTC_TIME_WEEK_POSS));
}
/**
  * @brief  Get Week Value
  * @param  rtc RTC Instance
  * @retval Week value in RTC timer, in BCD format.
  */
__STATIC_INLINE uint32_t md_rtc_get_date_weekday(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->TIME, RTC_TIME_WEEK) >> RTC_TIME_WEEK_POSS);
}

/**
  * @brief  Set Hour Value
  * @param  rtc RTC Instance
  * @param  hour Hour value in RTC timer, in BCD format.
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_time_hour(RTC_TypeDef *rtc, uint32_t hour)
{
    MODIFY_REG(rtc->TIME, (RTC_TIME_HOUR_T | RTC_TIME_HOUR_U), (hour << RTC_TIME_HOUR_U_POSS));
}

/**
  * @brief  Get Hour Value
  * @param  rtc RTC Instance
  * @retval Hour value in RTC timer, in BCD format.
  */
__STATIC_INLINE uint32_t md_rtc_get_time_hour(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->TIME, (RTC_TIME_HOUR_T | RTC_TIME_HOUR_U)) >> RTC_TIME_HOUR_U_POSS);
}

/**
  * @brief  Set Minute Value
  * @param  rtc RTC Instance
  * @param  min Minute value in RTC timer, in BCD format.
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_time_minute(RTC_TypeDef *rtc, uint32_t min)
{
    MODIFY_REG(rtc->TIME, (RTC_TIME_MIN_T | RTC_TIME_MIN_U), (min << RTC_TIME_MIN_U_POSS));
}
/**
  * @brief  Get Minute Value
  * @param  rtc RTC Instance
  * @retval Minute value in RTC timer, in BCD format.
  */
__STATIC_INLINE uint32_t md_rtc_get_time_minute(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->TIME, (RTC_TIME_MIN_T | RTC_TIME_MIN_U)) >> RTC_TIME_MIN_U_POSS);
}

/**
  * @brief  Set Second Value
  * @param  rtc RTC Instance
  * @param  sec Second value in RTC timer, in BCD format.
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_time_second(RTC_TypeDef *rtc, uint32_t sec)
{
    MODIFY_REG(rtc->TIME, (RTC_TIME_SEC_T | RTC_TIME_SEC_U), (sec << RTC_TIME_SEC_U_POSS));
}

/**
  * @brief  Get Second Value
  * @param  rtc RTC Instance
  * @retval Second value in RTC timer, in BCD format.
  */
__STATIC_INLINE uint32_t md_rtc_get_time_second(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->TIME, (RTC_TIME_SEC_T | RTC_TIME_SEC_U)) >> RTC_TIME_SEC_U_POSS);
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group5 CAL
  * @{
  */
/**
  * @brief  Set RTC_CAL Register
  * @param  rtc RTC Instance
  * @param  ctrl
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_date(RTC_TypeDef *rtc, uint32_t cal)
{
    WRITE_REG(RTC->CAL, cal);
}

/**
  * @brief  Get RTC_CAL Register
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_get_date(RTC_TypeDef *rtc)
{
    return (uint32_t) READ_REG(RTC->CAL);
}

/**
  * @brief  Set Year Value
  * @param  rtc RTC Instance
  * @param  year Year value in RTC timer, in BCD format.
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_date_year(RTC_TypeDef *rtc, uint32_t year)
{
    MODIFY_REG(rtc->CAL, (RTC_CAL_YEAR_T | RTC_CAL_YEAR_U), (year << RTC_CAL_YEAR_U_POSS));
}

/**
  * @brief  Get Year Value
  * @param  rtc RTC Instance
  * @retval Year value in RTC timer, in BCD format.
  */
__STATIC_INLINE uint32_t md_rtc_get_date_year(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->CAL, (RTC_CAL_YEAR_T | RTC_CAL_YEAR_U)) >> RTC_CAL_YEAR_U_POSS);
}

/**
  * @brief  Set Month Value
  * @param  rtc RTC Instance
  * @param  mon Month value in RTC timer, in BCD format.
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_date_month(RTC_TypeDef *rtc, uint32_t mon)
{
    MODIFY_REG(rtc->CAL, (RTC_CAL_MON_T | RTC_CAL_MON_U), (mon << RTC_CAL_MON_U_POSS));
}

/**
  * @brief  Get Month Value
  * @param  rtc RTC Instance
  * @retval Month value in RTC timer, in BCD format.
  */
__STATIC_INLINE uint32_t md_rtc_get_date_month(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->CAL, (RTC_CAL_MON_T | RTC_CAL_MON_U)) >> RTC_CAL_MON_U_POSS);
}

/**
  * @brief  Set Date Value
  * @param  rtc RTC Instance
  * @param  date Date value in RTC timer, in BCD format.
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_date_day(RTC_TypeDef *rtc, uint32_t date)
{
    MODIFY_REG(rtc->CAL, (RTC_CAL_DATE_T | RTC_CAL_DATE_U), (date << RTC_CAL_DATE_U_POSS));
}
/**
  * @brief  Get Date Value
  * @param  rtc RTC Instance
  * @retval Date value in RTC timer, in BCD format.
  */
__STATIC_INLINE uint32_t md_rtc_get_date_day(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->CAL, (RTC_CAL_DATE_T | RTC_CAL_DATE_U)) >> RTC_CAL_DATE_U_POSS);
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group6 CALIB
  * @{
  */
/**
  * @brief  Set RTC_CALIB Register
  * @param  rtc RTC Instance
  * @param  ctrl
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_calibration(RTC_TypeDef *rtc, uint32_t calib)
{
    WRITE_REG(RTC->CALIB, calib);
}

/**
  * @brief  Get RTC_CALIB Register
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_get_calibration(RTC_TypeDef *rtc)
{
    return (uint32_t) READ_REG(RTC->CALIB);
}

/**
  * @brief  Set RTC 1Hz Calibration value
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_calibration_value(RTC_TypeDef *rtc, uint32_t calib)
{
    MODIFY_REG(rtc->CALIB, RTC_CALIB_CALIB, (calib << RTC_CALIB_CALIB_POSS));
}
/**
  * @brief  Get RTC 1Hz Calibration value
  * @param  rtc RTC Instance
  */
__STATIC_INLINE uint32_t md_rtc_get_calibration_value(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->CALIB, RTC_CALIB_CALIB) >> RTC_CALIB_CALIB_POSS);
}

/**
  * @brief  Set RTC Clock Calibration Mode
  * @param  rtc RTC Instance
  * @param  mode can be one of the following values:
  *         @arg @ref MD_RTC_CON_MODE_INCR
  *         @arg @ref MD_RTC_CON_MODE_DECR
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_calibration_mode(RTC_TypeDef *rtc, uint32_t mode)
{
    MODIFY_REG(rtc->CALIB, RTC_CALIB_MODE, mode << RTC_CALIB_MODE_POS);
}
/**
  * @brief  Get RTC Clock Calibration Mode
  * @param  rtc RTC Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RTC_CON_MODE_INCR
  *         @arg @ref MD_RTC_CON_MODE_DECR
  */
__STATIC_INLINE uint32_t md_rtc_get_calibration_mode(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->CALIB, RTC_CALIB_MODE) >> RTC_CALIB_MODE_POS);
}

/**
  * @brief  Set RTC Calibration enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_calibration(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->CALIB, RTC_CALIB_CALIBEN);
}

/**
  * @brief  Set RTC Calibration disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_calibration(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->CALIB, RTC_CALIB_CALIBEN);
}

/**
  * @brief  Get RTC Calibration enable or disable
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_calibration(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->CALIB, RTC_CALIB_CALIBEN) == (RTC_CALIB_CALIBEN));
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group7 ALTIME
  * @{
  */
/**
  * @brief  Set RTC_ALTIME Register
  * @param  rtc RTC Instance
  * @param  ctrl
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_alarm_time(RTC_TypeDef *rtc, uint32_t altime)
{
    WRITE_REG(RTC->ALTIME, altime);
}

/**
  * @brief  Get RTC_ALTIME Register
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_get_alarm_time(RTC_TypeDef *rtc)
{
    return (uint32_t) READ_REG(RTC->ALTIME);
}

/**
  * @brief  Set Alarm Week Value
  * @param  rtc RTC Instance
  * @param  week Alarm Week value in RTC timer, in BCD format.
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_alarm_weekday(RTC_TypeDef *rtc, uint32_t week)
{
    MODIFY_REG(rtc->ALTIME, RTC_ALTIME_WEEK, (week << RTC_ALTIME_WEEK_POSS));
}

/**
  * @brief  Get Alarm Week Value
  * @param  rtc RTC Instance
  * @retval Alarm Week value in RTC timer, in BCD format.
  */
__STATIC_INLINE uint32_t md_rtc_get_alarm_weekday(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->ALTIME, RTC_ALTIME_WEEK) >> RTC_ALTIME_WEEK_POSS);
}

/**
  * @brief  Set Alarm Hour Value
  * @param  rtc RTC Instance
  * @param  hour Alarm Hour value in RTC timer, in BCD format.
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_alarm_hour(RTC_TypeDef *rtc, uint32_t hour)
{
    MODIFY_REG(rtc->ALTIME, (RTC_ALTIME_HOUR_T | RTC_ALTIME_HOUR_U), (hour << RTC_ALTIME_HOUR_U_POSS));
}

/**
  * @brief  Get Alarm Hour Value
  * @param  rtc RTC Instance
  * @retval Alarm Hour value in RTC timer, in BCD format.
  */
__STATIC_INLINE uint32_t md_rtc_get_alarm_hour(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->ALTIME, (RTC_ALTIME_HOUR_T | RTC_ALTIME_HOUR_U)) >> RTC_ALTIME_HOUR_U_POSS);
}

/**
  * @brief  Set Alarm Minute Value
  * @param  rtc RTC Instance
  * @param  min Alarm Minute value in RTC timer, in BCD format.
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_alarm_minute(RTC_TypeDef *rtc, uint32_t min)
{
    MODIFY_REG(rtc->ALTIME, (RTC_ALTIME_MIN_T | RTC_ALTIME_MIN_U), (min << RTC_ALTIME_MIN_U_POSS));
}

/**
  * @brief  Get Alarm Minute Value
  * @param  rtc RTC Instance
  * @retval Alarm Minute value in RTC timer, in BCD format.
  */
__STATIC_INLINE uint32_t md_rtc_get_alarm_minute(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->ALTIME, (RTC_ALTIME_MIN_T | RTC_ALTIME_MIN_U)) >> RTC_ALTIME_MIN_U_POSS);
}

/**
  * @brief  Set Alarm Second Value
  * @param  rtc RTC Instance
  * @param  sec Alarm Second value in RTC timer, in BCD format.
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_alarm_second(RTC_TypeDef *rtc, uint32_t sec)
{
    MODIFY_REG(rtc->ALTIME, (RTC_ALTIME_SEC_T | RTC_ALTIME_SEC_U), (sec << RTC_ALTIME_SEC_U_POSS));
}

/**
  * @brief  Get Alarm Second Value
  * @param  rtc RTC Instance
  * @retval Alarm Second value in RTC timer, in BCD format.
  */
__STATIC_INLINE uint32_t md_rtc_get_alarm_second(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->ALTIME, (RTC_ALTIME_SEC_T | RTC_ALTIME_SEC_U)) >> RTC_ALTIME_SEC_U_POSS);
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group8 ALCAL
  * @{
  */
/**
  * @brief  Set RTC_ALCAL Register
  * @param  rtc RTC Instance
  * @param  ctrl
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_alarm_date(RTC_TypeDef *rtc, uint32_t alcal)
{
    WRITE_REG(RTC->ALCAL, alcal);
}

/**
  * @brief  Get RTC_ALCAL Register
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_get_alarm_date(RTC_TypeDef *rtc)
{
    return (uint32_t) READ_REG(RTC->ALCAL);
}

/**
  * @brief  Set Alarm Year Value
  * @param  rtc RTC Instance
  * @param  year Alarm Year value in RTC timer, in BCD format.
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_alarm_year(RTC_TypeDef *rtc, uint32_t year)
{
    MODIFY_REG(rtc->ALCAL, (RTC_ALCAL_YEAR_T | RTC_ALCAL_YEAR_U), (year << RTC_ALCAL_YEAR_U_POSS));
}

/**
  * @brief  Get Alarm Year Value
  * @param  rtc RTC Instance
  * @retval Alarm Year value in RTC timer, in BCD format.
  */
__STATIC_INLINE uint32_t md_rtc_get_alarm_year(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->ALCAL, (RTC_ALCAL_YEAR_T | RTC_ALCAL_YEAR_U)) >> RTC_ALCAL_YEAR_U_POSS);
}


/**
  * @brief  Set Alarm Month Value
  * @param  rtc RTC Instance
  * @param  mon Alarm Month value in RTC timer, in BCD format.
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_alarm_month(RTC_TypeDef *rtc, uint32_t mon)
{
    MODIFY_REG(rtc->ALCAL, (RTC_ALCAL_MON_T | RTC_ALCAL_MON_U), (mon << RTC_ALCAL_MON_U_POSS));
}

/**
  * @brief  Get Alarm Month Value
  * @param  rtc RTC Instance
  * @retval Alarm Month value in RTC timer, in BCD format.
  */
__STATIC_INLINE uint32_t md_rtc_get_alarm_month_tens(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->ALCAL, (RTC_ALCAL_MON_T | RTC_ALCAL_MON_U)) >> RTC_ALCAL_MON_U_POSS);
}

/**
  * @brief  Set Alarm Date Value
  * @param  rtc RTC Instance
  * @param  date Alarm Date value in RTC timer, in BCD format.
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_alarm_day(RTC_TypeDef *rtc, uint32_t date)
{
    MODIFY_REG(rtc->ALCAL, (RTC_ALCAL_DATE_T | RTC_ALCAL_DATE_U), (date << RTC_ALCAL_DATE_U_POSS));
}

/**
  * @brief  Get Alarm Date Value
  * @param  rtc RTC Instance
  * @retval Alarm Date value in RTC timer, in BCD format.
  */
__STATIC_INLINE uint32_t md_rtc_get_alarm_day(RTC_TypeDef *rtc)
{
    return (uint32_t)(READ_BIT(rtc->ALCAL, (RTC_ALCAL_DATE_T | RTC_ALCAL_DATE_U)) >> RTC_ALCAL_DATE_U_POSS);
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group9 ALEN
  * @{
  */
/**
  * @brief  Set RTC_ALEN Register
  * @param  rtc RTC Instance
  * @param  ctrl
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_alarmen(RTC_TypeDef *rtc, uint32_t alen)
{
    WRITE_REG(RTC->ALEN, alen);
}

/**
  * @brief  Get RTC_ALEN Register
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_get_alarmen(RTC_TypeDef *rtc)
{
    return (uint32_t) READ_REG(RTC->ALEN);
}

/**
  * @brief  Set Year Alarm Function Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_alarm_year(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ALEN, RTC_ALEN_YEAR);
}

/**
  * @brief  Set Year Alarm Function Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_alarm_year(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->ALEN, RTC_ALEN_YEAR);
}

/**
  * @brief  Get Year Alarm Function Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_alarm_year(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->ALEN, RTC_ALEN_YEAR) == (RTC_ALEN_YEAR));
}

/**
  * @brief  Set Month Alarm Function Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_alarm_month(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ALEN, RTC_ALEN_MONTH);
}

/**
  * @brief  Set Month Alarm Function Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_alarm_month(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->ALEN, RTC_ALEN_MONTH);
}

/**
  * @brief  Get Month Alarm Function Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_alarm_month(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->ALEN, RTC_ALEN_MONTH) == (RTC_ALEN_MONTH));
}

/**
  * @brief  Set Date Alarm Function Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_alarm_day(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ALEN, RTC_ALEN_DATE);
}

/**
  * @brief  Set Date Alarm Function Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_alarm_day(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->ALEN, RTC_ALEN_DATE);
}

/**
  * @brief  Get Date Alarm Function Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_alarm_day(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->ALEN, RTC_ALEN_DATE) == (RTC_ALEN_DATE));
}

/**
  * @brief  Set Week Alarm Function Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_alarm_weekday(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ALEN, RTC_ALEN_WEEK);
}

/**
  * @brief  Set Week Alarm Function Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_alarm_weekday(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->ALEN, RTC_ALEN_WEEK);
}

/**
  * @brief  Get Week Alarm Function Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_alarm_weekday(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->ALEN, RTC_ALEN_WEEK) == (RTC_ALEN_WEEK));
}

/**
  * @brief  Set Hour Alarm Function Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_alarm_hour(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ALEN, RTC_ALEN_HOUR);
}

/**
  * @brief  Set Hour Alarm Function Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_alarm_hour(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->ALEN, RTC_ALEN_HOUR);
}

/**
  * @brief  Get Hour Alarm Function Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_alarm_hour(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->ALEN, RTC_ALEN_HOUR) == (RTC_ALEN_HOUR));
}

/**
  * @brief  Set Minute Alarm Function Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_alarm_minute(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ALEN, RTC_ALEN_MIN);
}

/**
  * @brief  Set Minute Alarm Function Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_alarm_minute(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->ALEN, RTC_ALEN_MIN);
}

/**
  * @brief  Get Minute Alarm Function Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_alarm_minute(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->ALEN, RTC_ALEN_MIN) == (RTC_ALEN_MIN));
}

/**
  * @brief  Set Second Alarm Function Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_alarm_second(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ALEN, RTC_ALEN_SEC);
}

/**
  * @brief  Set Second Alarm Function Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_alarm_second(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->ALEN, RTC_ALEN_SEC);
}

/**
  * @brief  Get Second Alarm Function Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_alarm_second(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->ALEN, RTC_ALEN_SEC) == (RTC_ALEN_SEC));
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group10 TRIG
  * @{
  */
/**
  * @brief  Set RTC_TRIG Register
  * @param  rtc RTC Instance
  * @param  ctrl
  * @retval None
  */
__STATIC_INLINE void md_rtc_set_trig(RTC_TypeDef *rtc, uint32_t trig)
{
    WRITE_REG(RTC->TRIG, trig);
}

/**
  * @brief  Get RTC_TRIG Register
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_get_trig(RTC_TypeDef *rtc)
{
    return (uint32_t) READ_REG(RTC->TRIG);
}

/**
  * @brief  Set RTC Wakeup Counter Match Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_wakeup_count_match(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_WKTM);
}

/**
  * @brief  Set RTC Wakeup Counter Match Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_wakeup_count_match(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_WKTM);
}

/**
  * @brief  Get RTC Wakeup Counter Match Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_wakeuptimer_count_match(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_WKTM) == (RTC_TRIG_WKTM));
}

/**
  * @brief  Set RTC 1 Hz Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_freq1hz(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_F1HZ);
}

/**
  * @brief  Set RTC 1 Hz Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_freq1hz(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_F1HZ);
}

/**
  * @brief  Get RTC 1 Hz Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_freq1hz(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_F1HZ) == (RTC_TRIG_F1HZ));
}

/**
  * @brief  Set RTC Year Roll Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_rollover_year(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_RYEAR);
}

/**
  * @brief  Set RTC Year Roll Alarm Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_rollover_year(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_RYEAR);
}

/**
  * @brief  Get RTC Year Roll Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_rollover_year(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_RYEAR) == (RTC_TRIG_RYEAR));
}

/**
  * @brief  Set RTC Month Roll Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_rollover_month(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_RMON);
}

/**
  * @brief  Set RTC Month Roll Alarm Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_rollover_month(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_RMON);
}

/**
  * @brief  Get RTC Month Roll Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_rollover_month(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_RMON) == (RTC_TRIG_RMON));
}

/**
  * @brief  Set RTC Date Roll Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_rollover_day(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_RDATE);
}

/**
  * @brief  Set RTC Date Roll Alarm Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_rollover_day(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_RDATE);
}

/**
  * @brief  Get RTC Date Roll Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_rollover_day(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_RDATE) == (RTC_TRIG_RDATE));
}

/**
  * @brief  Set RTC Week Roll Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_rollover_weekday(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_RWEEK);
}

/**
  * @brief  Set RTC Week Roll Alarm Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_rollover_weekday(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_RWEEK);
}

/**
  * @brief  Get RTC Week Roll Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_rollover_weekday(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_RWEEK) == (RTC_TRIG_RWEEK));
}

/**
  * @brief  Set RTC Hour Roll Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_rollover_hour(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_RHOUR);
}

/**
  * @brief  Set RTC Hour Roll Alarm Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disble_trig_rollover_hour(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_RHOUR);
}

/**
  * @brief  Get RTC Hour Roll Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_rollover_hour(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_RHOUR) == (RTC_TRIG_RHOUR));
}

/**
  * @brief  Set RTC Minute Roll Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_rollover_minute(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_RMIN);
}

/**
  * @brief  Set RTC Minute Roll Alarm Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_rollover_minute(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_RMIN);
}

/**
  * @brief  Get RTC Minute Roll Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_rollover_minute(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_RMIN) == (RTC_TRIG_RMIN));
}

/**
  * @brief  Set RTC Second Roll Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_rollover_second(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_RSEC);
}

/**
  * @brief  Set RTC Second Roll Alarm Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_rollover_second(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_RSEC);
}

/**
  * @brief  Get RTC Second Roll Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_rollover_second(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_RSEC) == (RTC_TRIG_RSEC));
}

/**
  * @brief  Set RTC Match All Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_alarm_all(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_AMALL);
}

/**
  * @brief  Set RTC Match All Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_alarm_all(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_AMALL);
}

/**
  * @brief  Get RTC Match All Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_alarm_all(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_AMALL) == (RTC_TRIG_AMALL));
}

/**
  * @brief  Set RTC Match Year Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_alarm_year(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_AYEAR);
}

/**
  * @brief  Set RTC Match Year Alarm Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_alarm_year(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_AYEAR);
}

/**
  * @brief  Get RTC Match Year Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_alarm_year(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_AYEAR) == (RTC_TRIG_AYEAR));
}

/**
  * @brief  Set RTC Match Month Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_alarm_month(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_AMONTH);
}

/**
  * @brief  Set RTC Match Month Alarm Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_alarm_month(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_AMONTH);
}

/**
  * @brief  Get RTC Match Month Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_alarm_month(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_AMONTH) == (RTC_TRIG_AMONTH));
}

/**
  * @brief  Set RTC Match Date Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_alarm_day(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_ADTAE);
}

/**
  * @brief  Set RTC Match Date Alarm Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_alarm_day(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_ADTAE);
}

/**
  * @brief  Get RTC Match Date Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_alarm_day(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_ADTAE) == (RTC_TRIG_ADTAE));
}

/**
  * @brief  Set RTC Match Week Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_alarm_weekday(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_AWEEK);
}

/**
  * @brief  Set RTC Match Week Alarm Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_alarm_weekday(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_AWEEK);
}

/**
  * @brief  Get RTC Match Week Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_alarm_weekday(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_AWEEK) == (RTC_TRIG_AWEEK));
}

/**
  * @brief  Set RTC Match Hour Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_alarm_hour(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_AHOUR);
}

/**
  * @brief  Set RTC Match Hour Alarm Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_alarm_hour(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_AHOUR);
}

/**
  * @brief  Get RTC Match Hour Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_alarm_hour(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_AHOUR) == (RTC_TRIG_AHOUR));
}

/**
  * @brief  Set RTC Match Minute Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_alarm_minute(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_AMIN);
}

/**
  * @brief  Set RTC Match Minute Alarm Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_alarm_minute(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_AMIN);
}

/**
  * @brief  Get RTC Match Minute Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_alarm_minute(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_AMIN) == (RTC_TRIG_AMIN));
}

/**
  * @brief  Set RTC Match Second Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_trig_alarm_second(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->TRIG, RTC_TRIG_ASEC);
}

/**
  * @brief  Set RTC Match Second Alarm Trigger Disable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_trig_alarm_second(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->TRIG, RTC_TRIG_ASEC);
}

/**
  * @brief  Get RTC Match Second Alarm Trigger Enable
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_trig_alarm_second(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->TRIG, RTC_TRIG_ASEC) == (RTC_TRIG_ASEC));
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group11 IER
  * @{
  */
/**
  * @brief  Set RTC_IER Register
  * @param  rtc RTC Instance
  * @param  ier
  */
__STATIC_INLINE void md_rtc_set_ier(RTC_TypeDef *rtc, uint32_t ier)
{
    WRITE_REG(RTC->IER, ier);
}

/**
  * @brief  Set RTC Wakeup Counter Match Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_wakeup_count_match(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_WKTM);
}

/**
  * @brief  Set RTC 1 Hz Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_freq1hz(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_F1HZ);
}

/**
  * @brief  Set RTC Year Roll Alarm Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_rollover_year(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_RYEAR);
}

/**
  * @brief  Set RTC Month Roll Alarm Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_rollover_month(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_RMON);
}

/**
  * @brief  Set RTC Date Roll Alarm Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_rollover_day(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_RDATE);
}

/**
  * @brief  Set RTC Week Roll Alarm Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_rollover_weekday(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_RWEEK);
}

/**
  * @brief  Set RTC Hour Roll Alarm Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_rollover_hour(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_RHOUR);
}

/**
  * @brief  Set RTC Minute Roll Alarm Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_rollover_minute(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_RMIN);
}

/**
  * @brief  Set RTC Second Roll Alarm Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_rollover_second(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_RSEC);
}

/**
  * @brief  Set RTC Match All Alarm Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_alarm_all(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_AMALL);
}

/**
  * @brief  Set RTC Match Year Alarm Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_alarm_year(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_AYEAR);
}

/**
  * @brief  Set RTC Match Month Alarm Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_alarm_month(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_AMONTH);
}

/**
  * @brief  Set RTC Match Date Alarm Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_alarm_day(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_ADTAE);
}

/**
  * @brief  Set RTC Match Week Alarm Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_alarm_weekday(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_AWEEK);
}

/**
  * @brief  Set RTC Match Hour Alarm Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_alarm_hour(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_AHOUR);
}

/**
  * @brief  Set RTC Match Minute Alarm Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_alarm_minute(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_AMIN);
}

/**
  * @brief  Set RTC Match Second Alarm Interrupt Enable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_it_alarm_second(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IER, RTC_IER_ASEC);
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group12 IDR
  * @{
  */
/**
  * @brief  Set RTC_IER Register
  * @param  rtc RTC Instance
  * @param  idr
  */
__STATIC_INLINE void md_rtc_set_idr(RTC_TypeDef *rtc, uint32_t idr)
{
    WRITE_REG(RTC->IDR, idr);
}

/**
  * @brief  Set RTC Wakeup Counter Match Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_wakeup_count_match(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_WKTM);
}

/**
  * @brief  Set RTC 1 Hz Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_freq1hz(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_F1HZ);
}

/**
  * @brief  Set RTC Year Roll Alarm Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_rollover_year(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_RYEAR);
}

/**
  * @brief  Set RTC Month Roll Alarm Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_rollover_month(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_RMON);
}

/**
  * @brief  Set RTC Date Roll Alarm Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_rollover_day(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_RDATE);
}

/**
  * @brief  Set RTC Week Roll Alarm Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_rollover_weekday(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_RWEEK);
}

/**
  * @brief  Set RTC Hour Roll Alarm Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_rollover_hour(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_RHOUR);
}

/**
  * @brief  Set RTC Minute Roll Alarm Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_rollover_minute(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_RMIN);
}

/**
  * @brief  Set RTC Second Roll Alarm Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_rollover_second(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_RSEC);
}

/**
  * @brief  Set RTC Match All Alarm Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_alarm_all(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_AMALL);
}

/**
  * @brief  Set RTC Match Year Alarm Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_alarm_year(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_AYEAR);
}

/**
  * @brief  Set RTC Match Month Alarm Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_alarm_month(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_AMONTH);
}

/**
  * @brief  Set RTC Match Date Alarm Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_alarm_day(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_ADTAE);
}

/**
  * @brief  Set RTC Match Week Alarm Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_alarm_weekday(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_AWEEK);
}

/**
  * @brief  Set RTC Match Hour Alarm Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_alarm_hour(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_AHOUR);
}

/**
  * @brief  Set RTC Match Minute Alarm Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_alarm_minute(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_AMIN);
}

/**
  * @brief  Set RTC Match Second Alarm Interrupt Disable bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_it_alarm_second(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->IDR, RTC_IDR_ASEC);
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group13 IVS
  * @{
  */
/**
  * @brief  Get RTC_IVS Register
  * @param  rtc RTC Instance
  */
__STATIC_INLINE uint32_t md_rtc_get_ivs(RTC_TypeDef *rtc)
{
    return (uint32_t)READ_REG(RTC->IVS);
}

/**
  * @brief  Get RTC Wakeup Counter Match Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_wakeup_count_match(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_WKTM) == (RTC_IVS_WKTM));
}

/**
  * @brief  Get RTC 1 Hz Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_freq1hz(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_F1HZ) == (RTC_IVS_F1HZ));
}

/**
  * @brief  Get RTC Year Roll Alarm Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_rollover_year(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_RYEAR) == (RTC_IVS_RYEAR));
}

/**
  * @brief  Get RTC Month Roll Alarm Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_rollover_month(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_RMON) == (RTC_IVS_RMON));
}

/**
  * @brief  Get RTC Date Roll Alarm Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_rollover_day(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_RDATE) == (RTC_IVS_RDATE));
}

/**
  * @brief  Get RTC Week Roll Alarm Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_rollover_weekday(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_RWEEK) == (RTC_IVS_RWEEK));
}

/**
  * @brief  Get RTC Hour Roll Alarm Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_rollover_hour(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_RHOUR) == (RTC_IVS_RHOUR));
}

/**
  * @brief  Get RTC Minute Roll Alarm Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_rollover_minute(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_RMIN) == (RTC_IVS_RMIN));
}

/**
  * @brief  Get RTC Second Roll Alarm Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_rollover_second(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_RSEC) == (RTC_IVS_RSEC));
}

/**
  * @brief  Get RTC Match All Alarm Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_alarm_all(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_AMALL) == (RTC_IVS_AMALL));
}

/**
  * @brief  Get RTC Match Year Alarm Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_alarm_year(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_AYEAR) == (RTC_IVS_AYEAR));
}

/**
  * @brief  Get RTC Match Month Alarm Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_alarm_month(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_AMONTH) == (RTC_IVS_AMONTH));
}

/**
  * @brief  Get RTC Match Date Alarm Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_alarm_day(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_ADTAE) == (RTC_IVS_ADTAE));
}

/**
  * @brief  Get RTC Match Week Alarm Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_alarm_weekday(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_AWEEK) == (RTC_IVS_AWEEK));
}

/**
  * @brief  Get RTC Match Hour Alarm Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_alarm_hour(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_AHOUR) == (RTC_IVS_AHOUR));
}

/**
  * @brief  Get RTC Match Minute Alarm Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_alarm_minute(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_AMIN) == (RTC_IVS_AMIN));
}

/**
  * @brief  Get RTC Match Second Alarm Interrupt Valid Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_it_alarm_second(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IVS, RTC_IVS_ASEC) == (RTC_IVS_ASEC));
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group14 RIF
  * @{
  */
/**
  * @brief  Get RTC_RIF Register
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_get_rif(RTC_TypeDef *rtc)
{
    return (uint32_t)READ_REG(RTC->RIF);
}

/**
  * @brief  Get RTC Wakeup Counter Match Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_wakeup_count_match(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_WKTM) == (RTC_RIF_WKTM));
}

/**
  * @brief  Get RTC 1 Hz Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_freq1hz(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_F1HZ) == (RTC_RIF_F1HZ));
}

/**
  * @brief  Get RTC Year Roll Alarm Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_rollover_year(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_RYEAR) == (RTC_RIF_RYEAR));
}
/**
  * @brief  Get RTC Month Roll Alarm Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_rollover_month(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_RMON) == (RTC_RIF_RMON));
}
/**
  * @brief  Get RTC Date Roll Alarm Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_rollover_day(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_RDATE) == (RTC_RIF_RDATE));
}
/**
  * @brief  Get RTC Week Roll Alarm Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_rollover_weekday(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_RWEEK) == (RTC_RIF_RWEEK));
}
/**
  * @brief  Get RTC Hour Roll Alarm Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_rollover_hour(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_RHOUR) == (RTC_RIF_RHOUR));
}
/**
  * @brief  Get RTC Minute Roll Alarm Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_rollover_minute(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_RMIN) == (RTC_RIF_RMIN));
}
/**
  * @brief  Get RTC Second Roll Alarm Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_rollover_second(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_RSEC) == (RTC_RIF_RSEC));
}
/**
  * @brief  Get RTC Match All Alarm Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_alarm_all(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_AMALL) == (RTC_RIF_AMALL));
}
/**
  * @brief  Get RTC Match Year Alarm Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_alarm_year(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_AYEAR) == (RTC_RIF_AYEAR));
}
/**
  * @brief  Get RTC Match Month Alarm Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_alarm_month(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_AMONTH) == (RTC_RIF_AMONTH));
}
/**
  * @brief  Get RTC Match Date Alarm Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_alarm_day(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_ADTAE) == (RTC_RIF_ADTAE));
}
/**
  * @brief  Get RTC Match Week Alarm Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_alarm_weekday(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_AWEEK) == (RTC_RIF_AWEEK));
}
/**
  * @brief  Get RTC Match Hour Alarm Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_alarm_hour(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_AHOUR) == (RTC_RIF_AHOUR));
}
/**
  * @brief  Get RTC Match Minute Alarm Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_alarm_minute(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_AMIN) == (RTC_RIF_AMIN));
}
/**
  * @brief  Get RTC Match Second Alarm Raw Interrupt Flag Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_it_alarm_second(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->RIF, RTC_RIF_ASEC) == (RTC_RIF_ASEC));
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group15 IFM
  * @{
  */
/**
  * @brief  Get RTC_RIF Register
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rtc_get_ifm(RTC_TypeDef *rtc)
{
    return (uint32_t)READ_REG(RTC->IFM);
}

/**
  * @brief  Get RTC Wakeup Counter Match Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_wakeup_count_match(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_WKTM) == (RTC_IFM_WKTM));
}

/**
  * @brief  Get RTC 1 Hz Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_freq1hz(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_F1HZ) == (RTC_IFM_F1HZ));
}

/**
  * @brief  Get RTC Year Roll Alarm Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_rollover_year(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_RYEAR) == (RTC_IFM_RYEAR));
}

/**
  * @brief  Get RTC Month Roll Alarm Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_rollover_month(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_RMON) == (RTC_IFM_RMON));
}

/**
  * @brief  Get RTC Date Roll Alarm Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_rollover_day(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_RDATE) == (RTC_IFM_RDATE));
}

/**
  * @brief  Get RTC Week Roll Alarm Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_rollover_weekday(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_RWEEK) == (RTC_IFM_RWEEK));
}

/**
  * @brief  Get RTC Hour Roll Alarm Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_rollover_hour(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_RHOUR) == (RTC_IFM_RHOUR));
}

/**
  * @brief  Get RTC Minute Roll Alarm Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_rollover_minute(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_RMIN) == (RTC_IFM_RMIN));
}

/**
  * @brief  Get RTC Second Roll Alarm Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_rollover_second(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_RSEC) == (RTC_IFM_RSEC));
}

/**
  * @brief  Get RTC Match All Alarm Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_alarm_all(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_AMALL) == (RTC_IFM_AMALL));
}

/**
  * @brief  Get RTC Match Year Alarm Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_alarm_year(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_AYEAR) == (RTC_IFM_AYEAR));
}

/**
  * @brief  Get RTC Match Month Alarm Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_alarm_month(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_AMONTH) == (RTC_IFM_AMONTH));
}

/**
  * @brief  Get RTC Match Date Alarm Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_alarm_day(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_ADTAE) == (RTC_IFM_ADTAE));
}

/**
  * @brief  Get RTC Match Week Alarm Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_alarm_weekday(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_AWEEK) == (RTC_IFM_AWEEK));
}

/**
  * @brief  Get RTC Match Hour Alarm Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_alarm_hour(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_AHOUR) == (RTC_IFM_AHOUR));
}

/**
  * @brief  Get RTC Match Minute Alarm Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_alarm_minute(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_AMIN) == (RTC_IFM_AMIN));
}

/**
  * @brief  Get RTC Match Second Alarm Interrupt Flag Masked Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_masked_it_alarm_second(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->IFM, RTC_IFM_ASEC) == (RTC_IFM_ASEC));
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group16 ICR
  * @{
  */
/**
  * @brief  Get RTC_ICR Register
  * @param  rtc RTC Instance
  * @param  icr
  * @retval None
  */
__STATIC_INLINE void md_rtc_get_icr(RTC_TypeDef *rtc, uint32_t icr)
{
    WRITE_REG(RTC->ICR, icr);
}

/**
  * @brief  Set RTC Wakeup Counter Match Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_wakeup_count_match(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_WKTM);
}
/**
  * @brief  Set RTC 1 Hz Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_freq1hz(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_F1HZ);
}
/**
  * @brief  Set RTC Year Roll Alarm Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_rollover_year(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_RYEAR);
}
/**
  * @brief  Set RTC Month Roll Alarm Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_rollover_month(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_RMON);
}
/**
  * @brief  Set RTC Date Roll Alarm Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_rollover_day(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_RDATE);
}
/**
  * @brief  Set RTC Week Roll Alarm Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_rollover_weekday(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_RWEEK);
}
/**
  * @brief  Set RTC Hour Roll Alarm Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_rollover_hour(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_RHOUR);
}
/**
  * @brief  Set RTC Minute Roll Alarm Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_rollover_minute(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_RMIN);
}
/**
  * @brief  Set RTC Second Roll Alarm Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_rollover_second(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_RSEC);
}
/**
  * @brief  Set RTC Match All Alarm Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_alarm_all(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_AMALL);
}
/**
  * @brief  Set RTC Match Year Alarm Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_alarm_year(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_AYEAR);
}
/**
  * @brief  Set RTC Match Month Alarm Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_alarm_month(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_AMONTH);
}
/**
  * @brief  Set RTC Match Date Alarm Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_alarm_day(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_ADTAE);
}
/**
  * @brief  Set RTC Match Week Alarm Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_alarm_weekday(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_AWEEK);
}
/**
  * @brief  Set RTC Match Hour Alarm Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_alarm_hour(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_AHOUR);
}
/**
  * @brief  Set RTC Match Minute Alarm Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_alarm_minute(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_AMIN);
}
/**
  * @brief  Set RTC Match Second Alarm Interrupt Clear bit
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_clear_it_alarm_second(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->ICR, RTC_ICR_ASEC);
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group17 STA
  * @{
  */
/**
  * @brief  Get RTC Calendar Synchronization status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_flag_sync_done(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->STA, RTC_STA_SYNDONE) == (RTC_STA_SYNDONE));
}
/**
  * @brief  Get RTC Calendar Status bit
  * @param  rtc RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rtc_is_active_flag_empty(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->STA, RTC_STA_EMPTY) == (RTC_STA_EMPTY));
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group18 BKEN
  * @{
  */
/**
  * @brief  Enable RTC backup register to read
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_enable_bkreg_bypass(RTC_TypeDef *rtc)
{
    SET_BIT(rtc->BKEN, RTC_BKEN_BKEN);
}

/**
  * @brief  Disable RTC backup register to read
  * @param  rtc RTC Instance
  * @retval None
  */
__STATIC_INLINE void md_rtc_disable_bkreg_bypass(RTC_TypeDef *rtc)
{
    CLEAR_BIT(rtc->BKEN, RTC_BKEN_BKEN);
}

/**
  * @brief  Get RTC backup register read enable or disable
  * @param  rtc RTC Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RTC_BKEN_RTC_REGISTER
  *         @arg @ref MD_RTC_BKEN_BACKUP_REGISTER
  */
__STATIC_INLINE uint32_t md_rtc_is_enabled_bkreg_bypass(RTC_TypeDef *rtc)
{
    return (READ_BIT(rtc->BKEN, RTC_BKEN_BKEN) == (RTC_BKEN_BKEN));
}
/**
  * @}
  */

/** @defgroup MD_RTC_Public_Functions_Group1 Initialization
  * @{
  */
ErrorStatus md_rtc_deinit(RTC_TypeDef *);
ErrorStatus md_rtc_init(RTC_TypeDef *, md_rtc_inittypedef *);
void        md_rtc_structinit(md_rtc_inittypedef *);
ErrorStatus md_rtc_time_init(RTC_TypeDef *, md_rtc_timetypedef *);
void        md_rtc_time_structinit(md_rtc_timetypedef *);
ErrorStatus md_rtc_date_init(RTC_TypeDef *rtc, md_rtc_datetypedef *);
void        md_rtc_date_structinit(md_rtc_datetypedef *);
ErrorStatus md_rtc_alarm_init(RTC_TypeDef *rtc, md_rtc_alarmtypedef *);
void        md_rtc_alarm_structinit(md_rtc_alarmtypedef *);
ErrorStatus md_rtc_enable(RTC_TypeDef *rtc);
ErrorStatus md_rtc_disable(RTC_TypeDef *rtc);
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @} Micro_Driver
  */


#ifdef __cplusplus
}
#endif
#endif

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
