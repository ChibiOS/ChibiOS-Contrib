/**********************************************************************************
 *
 * @file    md_rtc.c
 * @brief   md_rtc C file
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov  2021    Ginger          the first version
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

/* Includes -------------------------------------------------------------------*/
#include "system_fs026.h"
#include "md_rtc.h"
#include "md_rcu.h"
/** @addtogroup Micro_Driver
  * @{
  */


/** @defgroup RTC RTC
  * @brief RTC micro driver
  * @{
  */


/* Private types --------------------------------------------------------------*/
/* Private variables ----------------------------------------------------------*/
/* Private constants ----------------------------------------------------------*/
/* Private macros -------------------------------------------------------------*/
/* Private function prototypes ------------------------------------------------*/

/* Public functions -----------------------------------------------------------*/
/** @addtogroup MD_RTC_Public_Functions RTC Public Functions
  * @{
  */

/**
  * @brief  De-initialize RTC registers (Registers restored to their default values).
  * @param  rtc RTC Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: CRC registers are de-initialized
  *          - ERROR: CRC registers are not de-initialized
  */
ErrorStatus md_rtc_deinit(RTC_TypeDef *rtc)
{
    ErrorStatus status = SUCCESS;

    if (rtc == RTC)
    {
        md_rtc_disable_rtc(rtc);

        /* Force CRC reset */
        md_rcu_enable_rtc_reset(RCU);

        /* Release CRC reset */
        md_rcu_disable_rtc_reset(RCU);
    }
    else
    {
        status = ERROR;
    }

    return (status);
}

/**
  * @brief  Initializes the RTC registers according to the specified parameters
  *         in RTC_InitStruct.
  * @param  rtc RTC Instance
  * @param  RTC_InitStruct pointer to a @ref md_rtc_inittypedef structure that contains
  *         the configuration information for the RTC peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC registers are initialized
  *          - ERROR: RTC registers are not initialized
  */
ErrorStatus md_rtc_init(RTC_TypeDef *rtc, md_rtc_inittypedef *RTC_InitStruct)
{
    ErrorStatus status = ERROR;

    md_rtc_set_scale(rtc, RTC_InitStruct->Scale);
    md_rtc_set_prescale(rtc, RTC_InitStruct->Pre_Scale);
    md_rtc_set_ref_clock(rtc, RTC_InitStruct->Clock_Sel);

    status = SUCCESS;

    return status;
}

/**
  * @brief  Set each @ref md_rtc_inittypedef field to default value.
  * @param  RTC_InitStruct pointer to a @ref md_rtc_inittypedef structure which will be initialized.
  * @retval None
  */
void md_rtc_structinit(md_rtc_inittypedef *RTC_InitStruct)
{
    /* Set RTC_InitStruct fields to default values */
    RTC_InitStruct->Scale      = 0xFF;
    RTC_InitStruct->Pre_Scale  = 0x7F;
    RTC_InitStruct->Clock_Sel  = MD_RTC_CTRL_CKSEL_LRC;
}

/**
  * @brief  Set the RTC current time.
  * @param  rtc RTC Instance
  * @param  RTC_TimeStruct pointer to a md_rtc_timetypedef structure that contains
  *                        the time configuration information for the RTC.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC Time register is configured
  *          - ERROR: RTC Time register is not configured
  */
ErrorStatus md_rtc_time_init(RTC_TypeDef *rtc, md_rtc_timetypedef *RTC_TimeStruct)
{
    ErrorStatus status = ERROR;

    md_rtc_set_date_weekday(rtc, RTC_TimeStruct->Week);
    md_rtc_set_time_hour(rtc, RTC_TimeStruct->Hour);
    md_rtc_set_time_minute(rtc, RTC_TimeStruct->Min);
    md_rtc_set_time_second(rtc, RTC_TimeStruct->Sec);

    status = SUCCESS;

    return status;
}

/**
  * @brief  Set each @ref md_rtc_timetypedef field to default value (Time = 01w:00h:00min:00sec).
  * @param  RTC_TimeStruct pointer to a @ref md_rtc_timetypedef structure which will be initialized.
  * @retval None
  */
void md_rtc_time_structinit(md_rtc_timetypedef *RTC_TimeStruct)
{
    /* Time = 01w:00h:00min:00sec */
    RTC_TimeStruct->Week      = 1U;
    RTC_TimeStruct->Hour      = 0U;
    RTC_TimeStruct->Min       = 0U;
    RTC_TimeStruct->Sec       = 0U;
}

/**
  * @brief  Set the RTC current date.
  * @param  rtc RTC Instance
  * @param  RTC_DateStruct pointer to a md_rtc_datetypedef structure that contains
  *                        the time configuration information for the RTC.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC Time register is configured
  *          - ERROR: RTC Time register is not configured
  */
ErrorStatus md_rtc_date_init(RTC_TypeDef *rtc, md_rtc_datetypedef *RTC_DateStruct)
{
    ErrorStatus status = ERROR;

    md_rtc_set_date_year(rtc, RTC_DateStruct->Year);
    md_rtc_set_date_month(rtc, RTC_DateStruct->Month);
    md_rtc_set_date_day(rtc, RTC_DateStruct->Date);

    status = SUCCESS;

    return status;
}

/**
  * @brief  Set each @ref md_rtc_datetypedef field to default value (Date = xx00 01 01 ).
  * @param  RTC_DateStruct pointer to a @ref md_rtc_datetypedef structure which will be initialized.
  * @retval None
  */
void md_rtc_date_structinit(md_rtc_datetypedef *RTC_DateStruct)
{
    /* Date = xx00 01 01 */
    RTC_DateStruct->Year      = 0U;
    RTC_DateStruct->Month     = 1U;
    RTC_DateStruct->Date      = 1U;
}

/**
  * @brief  Set the RTC Alarm.
  * @param  rtc RTC Instance
  * @param  RTC_AlarmStruct pointer to a md_rtc_alarmtypedef structure that contains
  *                        the alarm configuration information for the RTC.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC Time register is configured
  *          - ERROR: RTC Time register is not configured
  */
ErrorStatus md_rtc_alarm_init(RTC_TypeDef *rtc, md_rtc_alarmtypedef *RTC_AlarmStruct)
{
    ErrorStatus status = ERROR;

    md_rtc_set_alarm_weekday(rtc, RTC_AlarmStruct->AlarmWeek);
    md_rtc_set_alarm_hour(rtc, RTC_AlarmStruct->AlarmHour);
    md_rtc_set_alarm_minute(rtc, RTC_AlarmStruct->AlarmMin);
    md_rtc_set_alarm_second(rtc, RTC_AlarmStruct->AlarmSec);

    md_rtc_set_alarm_year(rtc, RTC_AlarmStruct->AlarmYear);
    md_rtc_set_alarm_month(rtc, RTC_AlarmStruct->AlarmMonth);
    md_rtc_set_alarm_day(rtc, RTC_AlarmStruct->AlarmDate);

    md_rtc_set_alarmen(rtc, RTC_AlarmStruct->AlarmMask);
    md_rtc_set_ier(rtc, RTC_AlarmStruct->AlarmInterrupt);

    status = SUCCESS;

    return status;
}

/**
  * @brief  Set each @ref md_rtc_alarmenabletypedef of ALARMA field to default value.
  * @param  RTC_AlarmEnableStruct pointer to a @ref md_rtc_alarmenabletypedef structure which will be initialized.
  * @retval None
  */
void md_rtc_alarm_structinit(md_rtc_alarmtypedef *RTC_AlarmStruct)
{
    RTC_AlarmStruct->AlarmWeek     = 1U;
    RTC_AlarmStruct->AlarmHour     = 0U;
    RTC_AlarmStruct->AlarmMin      = 0U;
    RTC_AlarmStruct->AlarmSec      = 0U;

    RTC_AlarmStruct->AlarmYear     = 0U;
    RTC_AlarmStruct->AlarmMonth    = 1U;
    RTC_AlarmStruct->AlarmDate     = 1U;

    RTC_AlarmStruct->AlarmMask     = MD_RTC_ALEN_NONE;
}

/**
  * @brief  Enters the RTC Initialization mode.
  * @param  RTCx RTC Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC is closed
  *          - ERROR: Not applicable
  */
ErrorStatus md_rtc_disable(RTC_TypeDef *rtc)
{
    md_rtc_disable_rtc(rtc);

    return SUCCESS;
}

/**
  * @brief  Exit the RTC Initialization mode.
  * @param  RTCx RTC Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC starts
  *          - ERROR: Not applicable
  */
ErrorStatus md_rtc_enable(RTC_TypeDef *rtc)
{
    md_rtc_enable_rtc(rtc);

    return SUCCESS;
}



/** @addtogroup MD_RTC_Init
  * @{
  */


/**
  * @} MD_RTC_Init
  */


/**
  * @} MD_RTC_Public_Functions
  */

/**
  * @} RTC
  */

/**
  * @} Micro_Driver
  */

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
