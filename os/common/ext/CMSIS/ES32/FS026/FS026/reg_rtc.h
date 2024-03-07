/**********************************************************************************
 *
 * @file    reg_rtc.h
 * @brief   RTC Head File
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov 2021     Ginger          the first version
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

#ifndef __RTC_H__
#define __RTC_H__


/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/

/*  Support for anonymous structures and unions.  */
//#pragma anon_unions

/****************** Bit definition for RTC_CTRL register ************************/

#define  RTC_CTRL_SCALE_POSS    16U
#define  RTC_CTRL_SCALE_POSE    23U
#define  RTC_CTRL_SCALE_MSK     BITS(RTC_CTRL_SCALE_POSS,RTC_CTRL_SCALE_POSE)
#define  RTC_CTRL_SCALE         RTC_CTRL_SCALE_MSK

#define  RTC_CTRL_PSCALE_POSS   8U
#define  RTC_CTRL_PSCALE_POSE   14U
#define  RTC_CTRL_PSCALE_MSK    BITS(RTC_CTRL_PSCALE_POSS,RTC_CTRL_PSCALE_POSE)
#define  RTC_CTRL_PSCALE        RTC_CTRL_PSCALE_MSK

#define  RTC_CTRL_CKSEL_POSS    2U
#define  RTC_CTRL_CKSEL_POSE    3U
#define  RTC_CTRL_CKSEL_MSK     BITS(RTC_CTRL_CKSEL_POSS,RTC_CTRL_CKSEL_POSE)
#define  RTC_CTRL_CKSEL         RTC_CTRL_CKSEL_MSK

#define  RTC_CTRL_RTCEN_POS     0U
#define  RTC_CTRL_RTCEN_MSK     BIT(RTC_CTRL_RTCEN_POS)
#define  RTC_CTRL_RTCEN         RTC_CTRL_RTCEN_MSK

/****************** Bit definition for RTC_WKUP register ************************/

#define  RTC_WKUP_WKSCAL_POSS   26U
#define  RTC_WKUP_WKSCAL_POSE   29U
#define  RTC_WKUP_WKSCAL_MSK    BITS(RTC_WKUP_WKSCAL_POSS,RTC_WKUP_WKSCAL_POSE)
#define  RTC_WKUP_WKSCAL        RTC_WKUP_WKSCAL_MSK

#define  RTC_WKUP_WKSEL_POSS    24U
#define  RTC_WKUP_WKSEL_POSE    25U
#define  RTC_WKUP_WKSEL_MSK     BITS(RTC_WKUP_WKSEL_POSS,RTC_WKUP_WKSEL_POSE)
#define  RTC_WKUP_WKSEL         RTC_WKUP_WKSEL_MSK

#define  RTC_WKUP_WKCAL_POSS    0U
#define  RTC_WKUP_WKCAL_POSE    23U
#define  RTC_WKUP_WKCAL_MSK     BITS(RTC_WKUP_WKCAL_POSS,RTC_WKUP_WKCAL_POSE)
#define  RTC_WKUP_WKCAL         RTC_WKUP_WKCAL_MSK

/****************** Bit definition for RTC_TIME register ************************/

#define  RTC_TIME_WEEK_POSS     24U
#define  RTC_TIME_WEEK_POSE     26U
#define  RTC_TIME_WEEK_MSK      BITS(RTC_TIME_WEEK_POSS,RTC_TIME_WEEK_POSE)
#define  RTC_TIME_WEEK          RTC_TIME_WEEK_MSK

#define  RTC_TIME_HOUR_T_POSS   20U
#define  RTC_TIME_HOUR_T_POSE   21U
#define  RTC_TIME_HOUR_T_MSK    BITS(RTC_TIME_HOUR_T_POSS,RTC_TIME_HOUR_T_POSE)
#define  RTC_TIME_HOUR_T        RTC_TIME_HOUR_T_MSK

#define  RTC_TIME_HOUR_U_POSS   16U
#define  RTC_TIME_HOUR_U_POSE   19U
#define  RTC_TIME_HOUR_U_MSK    BITS(RTC_TIME_HOUR_U_POSS,RTC_TIME_HOUR_U_POSE)
#define  RTC_TIME_HOUR_U        RTC_TIME_HOUR_U_MSK

#define  RTC_TIME_MIN_T_POSS    12U
#define  RTC_TIME_MIN_T_POSE    14U
#define  RTC_TIME_MIN_T_MSK     BITS(RTC_TIME_MIN_T_POSS,RTC_TIME_MIN_T_POSE)
#define  RTC_TIME_MIN_T         RTC_TIME_MIN_T_MSK

#define  RTC_TIME_MIN_U_POSS    8U
#define  RTC_TIME_MIN_U_POSE    11U
#define  RTC_TIME_MIN_U_MSK     BITS(RTC_TIME_MIN_U_POSS,RTC_TIME_MIN_U_POSE)
#define  RTC_TIME_MIN_U         RTC_TIME_MIN_U_MSK

#define  RTC_TIME_SEC_T_POSS    4U
#define  RTC_TIME_SEC_T_POSE    6U
#define  RTC_TIME_SEC_T_MSK     BITS(RTC_TIME_SEC_T_POSS,RTC_TIME_SEC_T_POSE)
#define  RTC_TIME_SEC_T         RTC_TIME_SEC_T_MSK

#define  RTC_TIME_SEC_U_POSS    0U
#define  RTC_TIME_SEC_U_POSE    3U
#define  RTC_TIME_SEC_U_MSK     BITS(RTC_TIME_SEC_U_POSS,RTC_TIME_SEC_U_POSE)
#define  RTC_TIME_SEC_U         RTC_TIME_SEC_U_MSK

/****************** Bit definition for RTC_CAL register ************************/

#define  RTC_CAL_YEAR_T_POSS    20U
#define  RTC_CAL_YEAR_T_POSE    23U
#define  RTC_CAL_YEAR_T_MSK     BITS(RTC_CAL_YEAR_T_POSS,RTC_CAL_YEAR_T_POSE)
#define  RTC_CAL_YEAR_T         RTC_CAL_YEAR_T_MSK

#define  RTC_CAL_YEAR_U_POSS    16U
#define  RTC_CAL_YEAR_U_POSE    19U
#define  RTC_CAL_YEAR_U_MSK     BITS(RTC_CAL_YEAR_U_POSS,RTC_CAL_YEAR_U_POSE)
#define  RTC_CAL_YEAR_U         RTC_CAL_YEAR_U_MSK

#define  RTC_CAL_MON_T_POS      12U
#define  RTC_CAL_MON_T_MSK      BIT(RTC_CAL_MON_T_POS)
#define  RTC_CAL_MON_T          RTC_CAL_MON_T_MSK

#define  RTC_CAL_MON_U_POSS     8U
#define  RTC_CAL_MON_U_POSE     11U
#define  RTC_CAL_MON_U_MSK      BITS(RTC_CAL_MON_U_POSS,RTC_CAL_MON_U_POSE)
#define  RTC_CAL_MON_U          RTC_CAL_MON_U_MSK

#define  RTC_CAL_DATE_T_POSS    4U
#define  RTC_CAL_DATE_T_POSE    5U
#define  RTC_CAL_DATE_T_MSK     BITS(RTC_CAL_DATE_T_POSS,RTC_CAL_DATE_T_POSE)
#define  RTC_CAL_DATE_T         RTC_CAL_DATE_T_MSK

#define  RTC_CAL_DATE_U_POSS    0U
#define  RTC_CAL_DATE_U_POSE    3U
#define  RTC_CAL_DATE_U_MSK     BITS(RTC_CAL_DATE_U_POSS,RTC_CAL_DATE_U_POSE)
#define  RTC_CAL_DATE_U         RTC_CAL_DATE_U_MSK

/****************** Bit definition for RTC_CALIB register ************************/

#define  RTC_CALIB_CALIB_POSS   16U
#define  RTC_CALIB_CALIB_POSE   31U
#define  RTC_CALIB_CALIB_MSK    BITS(RTC_CALIB_CALIB_POSS,RTC_CALIB_CALIB_POSE)
#define  RTC_CALIB_CALIB        RTC_CALIB_CALIB_MSK

#define  RTC_CALIB_MODE_POS     1U
#define  RTC_CALIB_MODE_MSK     BIT(RTC_CALIB_MODE_POS)
#define  RTC_CALIB_MODE         RTC_CALIB_MODE_MSK

#define  RTC_CALIB_CALIBEN_POS  0U
#define  RTC_CALIB_CALIBEN_MSK  BIT(RTC_CALIB_CALIBEN_POS)
#define  RTC_CALIB_CALIBEN      RTC_CALIB_CALIBEN_MSK

/****************** Bit definition for RTC_ALTIME register ************************/

#define  RTC_ALTIME_WEEK_POSS       24U
#define  RTC_ALTIME_WEEK_POSE       26U
#define  RTC_ALTIME_WEEK_MSK        BITS(RTC_ALTIME_WEEK_POSS,RTC_ALTIME_WEEK_POSE)
#define  RTC_ALTIME_WEEK            RTC_ALTIME_WEEK_MSK

#define  RTC_ALTIME_HOUR_T_POSS     20U
#define  RTC_ALTIME_HOUR_T_POSE     21U
#define  RTC_ALTIME_HOUR_T_MSK      BITS(RTC_ALTIME_HOUR_T_POSS,RTC_ALTIME_HOUR_T_POSE)
#define  RTC_ALTIME_HOUR_T          RTC_ALTIME_HOUR_T_MSK

#define  RTC_ALTIME_HOUR_U_POSS     16U
#define  RTC_ALTIME_HOUR_U_POSE     19U
#define  RTC_ALTIME_HOUR_U_MSK      BITS(RTC_ALTIME_HOUR_U_POSS,RTC_ALTIME_HOUR_U_POSE)
#define  RTC_ALTIME_HOUR_U          RTC_ALTIME_HOUR_U_MSK

#define  RTC_ALTIME_MIN_T_POSS      12U
#define  RTC_ALTIME_MIN_T_POSE      14U
#define  RTC_ALTIME_MIN_T_MSK       BITS(RTC_ALTIME_MIN_T_POSS,RTC_ALTIME_MIN_T_POSE)
#define  RTC_ALTIME_MIN_T           RTC_ALTIME_MIN_T_MSK

#define  RTC_ALTIME_MIN_U_POSS      8U
#define  RTC_ALTIME_MIN_U_POSE      11U
#define  RTC_ALTIME_MIN_U_MSK       BITS(RTC_ALTIME_MIN_U_POSS,RTC_ALTIME_MIN_U_POSE)
#define  RTC_ALTIME_MIN_U           RTC_ALTIME_MIN_U_MSK

#define  RTC_ALTIME_SEC_T_POSS      4U
#define  RTC_ALTIME_SEC_T_POSE      6U
#define  RTC_ALTIME_SEC_T_MSK       BITS(RTC_ALTIME_SEC_T_POSS,RTC_ALTIME_SEC_T_POSE)
#define  RTC_ALTIME_SEC_T           RTC_ALTIME_SEC_T_MSK

#define  RTC_ALTIME_SEC_U_POSS      0U
#define  RTC_ALTIME_SEC_U_POSE      3U
#define  RTC_ALTIME_SEC_U_MSK       BITS(RTC_ALTIME_SEC_U_POSS,RTC_ALTIME_SEC_U_POSE)
#define  RTC_ALTIME_SEC_U           RTC_ALTIME_SEC_U_MSK

/****************** Bit definition for RTC_ALCAL register ************************/

#define  RTC_ALCAL_YEAR_T_POSS  20U
#define  RTC_ALCAL_YEAR_T_POSE  23U
#define  RTC_ALCAL_YEAR_T_MSK   BITS(RTC_ALCAL_YEAR_T_POSS,RTC_ALCAL_YEAR_T_POSE)
#define  RTC_ALCAL_YEAR_T       RTC_ALCAL_YEAR_T_MSK

#define  RTC_ALCAL_YEAR_U_POSS  16U
#define  RTC_ALCAL_YEAR_U_POSE  19U
#define  RTC_ALCAL_YEAR_U_MSK   BITS(RTC_ALCAL_YEAR_U_POSS,RTC_ALCAL_YEAR_U_POSE)
#define  RTC_ALCAL_YEAR_U       RTC_ALCAL_YEAR_U_MSK

#define  RTC_ALCAL_MON_T_POS    12U
#define  RTC_ALCAL_MON_T_MSK    BIT(RTC_ALCAL_MON_T_POS)
#define  RTC_ALCAL_MON_T        RTC_ALCAL_MON_T_MSK

#define  RTC_ALCAL_MON_U_POSS   8U
#define  RTC_ALCAL_MON_U_POSE   11U
#define  RTC_ALCAL_MON_U_MSK    BITS(RTC_ALCAL_MON_U_POSS,RTC_ALCAL_MON_U_POSE)
#define  RTC_ALCAL_MON_U        RTC_ALCAL_MON_U_MSK

#define  RTC_ALCAL_DATE_T_POSS  4U
#define  RTC_ALCAL_DATE_T_POSE  5U
#define  RTC_ALCAL_DATE_T_MSK   BITS(RTC_ALCAL_DATE_T_POSS,RTC_ALCAL_DATE_T_POSE)
#define  RTC_ALCAL_DATE_T       RTC_ALCAL_DATE_T_MSK

#define  RTC_ALCAL_DATE_U_POSS  0U
#define  RTC_ALCAL_DATE_U_POSE  3U
#define  RTC_ALCAL_DATE_U_MSK   BITS(RTC_ALCAL_DATE_U_POSS,RTC_ALCAL_DATE_U_POSE)
#define  RTC_ALCAL_DATE_U       RTC_ALCAL_DATE_U_MSK

/****************** Bit definition for RTC_ALEN register ************************/

#define  RTC_ALEN_YEAR_POS  6U
#define  RTC_ALEN_YEAR_MSK  BIT(RTC_ALEN_YEAR_POS)
#define  RTC_ALEN_YEAR      RTC_ALEN_YEAR_MSK

#define  RTC_ALEN_MONTH_POS 5U
#define  RTC_ALEN_MONTH_MSK BIT(RTC_ALEN_MONTH_POS)
#define  RTC_ALEN_MONTH     RTC_ALEN_MONTH_MSK

#define  RTC_ALEN_DATE_POS  4U
#define  RTC_ALEN_DATE_MSK  BIT(RTC_ALEN_DATE_POS)
#define  RTC_ALEN_DATE      RTC_ALEN_DATE_MSK

#define  RTC_ALEN_WEEK_POS  3U
#define  RTC_ALEN_WEEK_MSK  BIT(RTC_ALEN_WEEK_POS)
#define  RTC_ALEN_WEEK      RTC_ALEN_WEEK_MSK

#define  RTC_ALEN_HOUR_POS  2U
#define  RTC_ALEN_HOUR_MSK  BIT(RTC_ALEN_HOUR_POS)
#define  RTC_ALEN_HOUR      RTC_ALEN_HOUR_MSK

#define  RTC_ALEN_MIN_POS   1U
#define  RTC_ALEN_MIN_MSK   BIT(RTC_ALEN_MIN_POS)
#define  RTC_ALEN_MIN       RTC_ALEN_MIN_MSK

#define  RTC_ALEN_SEC_POS   0U
#define  RTC_ALEN_SEC_MSK   BIT(RTC_ALEN_SEC_POS)
#define  RTC_ALEN_SEC       RTC_ALEN_SEC_MSK

/****************** Bit definition for RTC_TRIG register ************************/

#define  RTC_TRIG_WKTM_POS      16U
#define  RTC_TRIG_WKTM_MSK      BIT(RTC_TRIG_WKTM_POS)
#define  RTC_TRIG_WKTM          RTC_TRIG_WKTM_MSK

#define  RTC_TRIG_F1HZ_POS      15U
#define  RTC_TRIG_F1HZ_MSK      BIT(RTC_TRIG_F1HZ_POS)
#define  RTC_TRIG_F1HZ          RTC_TRIG_F1HZ_MSK

#define  RTC_TRIG_RYEAR_POS     14U
#define  RTC_TRIG_RYEAR_MSK     BIT(RTC_TRIG_RYEAR_POS)
#define  RTC_TRIG_RYEAR         RTC_TRIG_RYEAR_MSK

#define  RTC_TRIG_RMON_POS      13U
#define  RTC_TRIG_RMON_MSK      BIT(RTC_TRIG_RMON_POS)
#define  RTC_TRIG_RMON          RTC_TRIG_RMON_MSK

#define  RTC_TRIG_RDATE_POS     12U
#define  RTC_TRIG_RDATE_MSK     BIT(RTC_TRIG_RDATE_POS)
#define  RTC_TRIG_RDATE         RTC_TRIG_RDATE_MSK

#define  RTC_TRIG_RWEEK_POS     11U
#define  RTC_TRIG_RWEEK_MSK     BIT(RTC_TRIG_RWEEK_POS)
#define  RTC_TRIG_RWEEK         RTC_TRIG_RWEEK_MSK

#define  RTC_TRIG_RHOUR_POS     10U
#define  RTC_TRIG_RHOUR_MSK     BIT(RTC_TRIG_RHOUR_POS)
#define  RTC_TRIG_RHOUR         RTC_TRIG_RHOUR_MSK

#define  RTC_TRIG_RMIN_POS      9U
#define  RTC_TRIG_RMIN_MSK      BIT(RTC_TRIG_RMIN_POS)
#define  RTC_TRIG_RMIN          RTC_TRIG_RMIN_MSK

#define  RTC_TRIG_RSEC_POS      8U
#define  RTC_TRIG_RSEC_MSK      BIT(RTC_TRIG_RSEC_POS)
#define  RTC_TRIG_RSEC          RTC_TRIG_RSEC_MSK

#define  RTC_TRIG_AMALL_POS     7U
#define  RTC_TRIG_AMALL_MSK     BIT(RTC_TRIG_AMALL_POS)
#define  RTC_TRIG_AMALL         RTC_TRIG_AMALL_MSK

#define  RTC_TRIG_AYEAR_POS     6U
#define  RTC_TRIG_AYEAR_MSK     BIT(RTC_TRIG_AYEAR_POS)
#define  RTC_TRIG_AYEAR         RTC_TRIG_AYEAR_MSK

#define  RTC_TRIG_AMONTH_POS    5U
#define  RTC_TRIG_AMONTH_MSK    BIT(RTC_TRIG_AMONTH_POS)
#define  RTC_TRIG_AMONTH        RTC_TRIG_AMONTH_MSK

#define  RTC_TRIG_ADTAE_POS     4U
#define  RTC_TRIG_ADTAE_MSK     BIT(RTC_TRIG_ADTAE_POS)
#define  RTC_TRIG_ADTAE         RTC_TRIG_ADTAE_MSK

#define  RTC_TRIG_AWEEK_POS     3U
#define  RTC_TRIG_AWEEK_MSK     BIT(RTC_TRIG_AWEEK_POS)
#define  RTC_TRIG_AWEEK         RTC_TRIG_AWEEK_MSK

#define  RTC_TRIG_AHOUR_POS     2U
#define  RTC_TRIG_AHOUR_MSK     BIT(RTC_TRIG_AHOUR_POS)
#define  RTC_TRIG_AHOUR         RTC_TRIG_AHOUR_MSK

#define  RTC_TRIG_AMIN_POS      1U
#define  RTC_TRIG_AMIN_MSK      BIT(RTC_TRIG_AMIN_POS)
#define  RTC_TRIG_AMIN          RTC_TRIG_AMIN_MSK

#define  RTC_TRIG_ASEC_POS      0U
#define  RTC_TRIG_ASEC_MSK      BIT(RTC_TRIG_ASEC_POS)
#define  RTC_TRIG_ASEC          RTC_TRIG_ASEC_MSK

/****************** Bit definition for RTC_IER register ************************/

#define  RTC_IER_WKTM_POS   16U
#define  RTC_IER_WKTM_MSK   BIT(RTC_IER_WKTM_POS)
#define  RTC_IER_WKTM       RTC_IER_WKTM_MSK

#define  RTC_IER_F1HZ_POS   15U
#define  RTC_IER_F1HZ_MSK   BIT(RTC_IER_F1HZ_POS)
#define  RTC_IER_F1HZ       RTC_IER_F1HZ_MSK

#define  RTC_IER_RYEAR_POS  14U
#define  RTC_IER_RYEAR_MSK  BIT(RTC_IER_RYEAR_POS)
#define  RTC_IER_RYEAR      RTC_IER_RYEAR_MSK

#define  RTC_IER_RMON_POS   13U
#define  RTC_IER_RMON_MSK   BIT(RTC_IER_RMON_POS)
#define  RTC_IER_RMON       RTC_IER_RMON_MSK

#define  RTC_IER_RDATE_POS  12U
#define  RTC_IER_RDATE_MSK  BIT(RTC_IER_RDATE_POS)
#define  RTC_IER_RDATE      RTC_IER_RDATE_MSK

#define  RTC_IER_RWEEK_POS  11U
#define  RTC_IER_RWEEK_MSK  BIT(RTC_IER_RWEEK_POS)
#define  RTC_IER_RWEEK      RTC_IER_RWEEK_MSK

#define  RTC_IER_RHOUR_POS  10U
#define  RTC_IER_RHOUR_MSK  BIT(RTC_IER_RHOUR_POS)
#define  RTC_IER_RHOUR      RTC_IER_RHOUR_MSK

#define  RTC_IER_RMIN_POS   9U
#define  RTC_IER_RMIN_MSK   BIT(RTC_IER_RMIN_POS)
#define  RTC_IER_RMIN       RTC_IER_RMIN_MSK

#define  RTC_IER_RSEC_POS   8U
#define  RTC_IER_RSEC_MSK   BIT(RTC_IER_RSEC_POS)
#define  RTC_IER_RSEC       RTC_IER_RSEC_MSK

#define  RTC_IER_AMALL_POS  7U
#define  RTC_IER_AMALL_MSK  BIT(RTC_IER_AMALL_POS)
#define  RTC_IER_AMALL      RTC_IER_AMALL_MSK

#define  RTC_IER_AYEAR_POS  6U
#define  RTC_IER_AYEAR_MSK  BIT(RTC_IER_AYEAR_POS)
#define  RTC_IER_AYEAR      RTC_IER_AYEAR_MSK

#define  RTC_IER_AMONTH_POS 5U
#define  RTC_IER_AMONTH_MSK BIT(RTC_IER_AMONTH_POS)
#define  RTC_IER_AMONTH     RTC_IER_AMONTH_MSK

#define  RTC_IER_ADTAE_POS  4U
#define  RTC_IER_ADTAE_MSK  BIT(RTC_IER_ADTAE_POS)
#define  RTC_IER_ADTAE      RTC_IER_ADTAE_MSK

#define  RTC_IER_AWEEK_POS  3U
#define  RTC_IER_AWEEK_MSK  BIT(RTC_IER_AWEEK_POS)
#define  RTC_IER_AWEEK      RTC_IER_AWEEK_MSK

#define  RTC_IER_AHOUR_POS  2U
#define  RTC_IER_AHOUR_MSK  BIT(RTC_IER_AHOUR_POS)
#define  RTC_IER_AHOUR      RTC_IER_AHOUR_MSK

#define  RTC_IER_AMIN_POS   1U
#define  RTC_IER_AMIN_MSK   BIT(RTC_IER_AMIN_POS)
#define  RTC_IER_AMIN       RTC_IER_AMIN_MSK

#define  RTC_IER_ASEC_POS   0U
#define  RTC_IER_ASEC_MSK   BIT(RTC_IER_ASEC_POS)
#define  RTC_IER_ASEC       RTC_IER_ASEC_MSK

/****************** Bit definition for RTC_IDR register ************************/

#define  RTC_IDR_WKTM_POS   16U
#define  RTC_IDR_WKTM_MSK   BIT(RTC_IDR_WKTM_POS)
#define  RTC_IDR_WKTM       RTC_IDR_WKTM_MSK

#define  RTC_IDR_F1HZ_POS   15U
#define  RTC_IDR_F1HZ_MSK   BIT(RTC_IDR_F1HZ_POS)
#define  RTC_IDR_F1HZ       RTC_IDR_F1HZ_MSK

#define  RTC_IDR_RYEAR_POS  14U
#define  RTC_IDR_RYEAR_MSK  BIT(RTC_IDR_RYEAR_POS)
#define  RTC_IDR_RYEAR      RTC_IDR_RYEAR_MSK

#define  RTC_IDR_RMON_POS   13U
#define  RTC_IDR_RMON_MSK   BIT(RTC_IDR_RMON_POS)
#define  RTC_IDR_RMON       RTC_IDR_RMON_MSK

#define  RTC_IDR_RDATE_POS  12U
#define  RTC_IDR_RDATE_MSK  BIT(RTC_IDR_RDATE_POS)
#define  RTC_IDR_RDATE      RTC_IDR_RDATE_MSK

#define  RTC_IDR_RWEEK_POS  11U
#define  RTC_IDR_RWEEK_MSK  BIT(RTC_IDR_RWEEK_POS)
#define  RTC_IDR_RWEEK      RTC_IDR_RWEEK_MSK

#define  RTC_IDR_RHOUR_POS  10U
#define  RTC_IDR_RHOUR_MSK  BIT(RTC_IDR_RHOUR_POS)
#define  RTC_IDR_RHOUR      RTC_IDR_RHOUR_MSK

#define  RTC_IDR_RMIN_POS   9U
#define  RTC_IDR_RMIN_MSK   BIT(RTC_IDR_RMIN_POS)
#define  RTC_IDR_RMIN       RTC_IDR_RMIN_MSK

#define  RTC_IDR_RSEC_POS   8U
#define  RTC_IDR_RSEC_MSK   BIT(RTC_IDR_RSEC_POS)
#define  RTC_IDR_RSEC       RTC_IDR_RSEC_MSK

#define  RTC_IDR_AMALL_POS  7U
#define  RTC_IDR_AMALL_MSK  BIT(RTC_IDR_AMALL_POS)
#define  RTC_IDR_AMALL      RTC_IDR_AMALL_MSK

#define  RTC_IDR_AYEAR_POS  6U
#define  RTC_IDR_AYEAR_MSK  BIT(RTC_IDR_AYEAR_POS)
#define  RTC_IDR_AYEAR      RTC_IDR_AYEAR_MSK

#define  RTC_IDR_AMONTH_POS 5U
#define  RTC_IDR_AMONTH_MSK BIT(RTC_IDR_AMONTH_POS)
#define  RTC_IDR_AMONTH     RTC_IDR_AMONTH_MSK

#define  RTC_IDR_ADTAE_POS  4U
#define  RTC_IDR_ADTAE_MSK  BIT(RTC_IDR_ADTAE_POS)
#define  RTC_IDR_ADTAE      RTC_IDR_ADTAE_MSK

#define  RTC_IDR_AWEEK_POS  3U
#define  RTC_IDR_AWEEK_MSK  BIT(RTC_IDR_AWEEK_POS)
#define  RTC_IDR_AWEEK      RTC_IDR_AWEEK_MSK

#define  RTC_IDR_AHOUR_POS  2U
#define  RTC_IDR_AHOUR_MSK  BIT(RTC_IDR_AHOUR_POS)
#define  RTC_IDR_AHOUR      RTC_IDR_AHOUR_MSK

#define  RTC_IDR_AMIN_POS   1U
#define  RTC_IDR_AMIN_MSK   BIT(RTC_IDR_AMIN_POS)
#define  RTC_IDR_AMIN       RTC_IDR_AMIN_MSK

#define  RTC_IDR_ASEC_POS   0U
#define  RTC_IDR_ASEC_MSK   BIT(RTC_IDR_ASEC_POS)
#define  RTC_IDR_ASEC       RTC_IDR_ASEC_MSK
/****************** Bit definition for RTC_IVS register ************************/

#define  RTC_IVS_WKTM_POS   16U
#define  RTC_IVS_WKTM_MSK   BIT(RTC_IVS_WKTM_POS)
#define  RTC_IVS_WKTM       RTC_IVS_WKTM_MSK

#define  RTC_IVS_F1HZ_POS   15U
#define  RTC_IVS_F1HZ_MSK   BIT(RTC_IVS_F1HZ_POS)
#define  RTC_IVS_F1HZ       RTC_IVS_F1HZ_MSK

#define  RTC_IVS_RYEAR_POS  14U
#define  RTC_IVS_RYEAR_MSK  BIT(RTC_IVS_RYEAR_POS)
#define  RTC_IVS_RYEAR      RTC_IVS_RYEAR_MSK

#define  RTC_IVS_RMON_POS   13U
#define  RTC_IVS_RMON_MSK   BIT(RTC_IVS_RMON_POS)
#define  RTC_IVS_RMON       RTC_IVS_RMON_MSK

#define  RTC_IVS_RDATE_POS  12U
#define  RTC_IVS_RDATE_MSK  BIT(RTC_IVS_RDATE_POS)
#define  RTC_IVS_RDATE      RTC_IVS_RDATE_MSK

#define  RTC_IVS_RWEEK_POS  11U
#define  RTC_IVS_RWEEK_MSK  BIT(RTC_IVS_RWEEK_POS)
#define  RTC_IVS_RWEEK      RTC_IVS_RWEEK_MSK

#define  RTC_IVS_RHOUR_POS  10U
#define  RTC_IVS_RHOUR_MSK  BIT(RTC_IVS_RHOUR_POS)
#define  RTC_IVS_RHOUR      RTC_IVS_RHOUR_MSK

#define  RTC_IVS_RMIN_POS   9U
#define  RTC_IVS_RMIN_MSK   BIT(RTC_IVS_RMIN_POS)
#define  RTC_IVS_RMIN       RTC_IVS_RMIN_MSK

#define  RTC_IVS_RSEC_POS   8U
#define  RTC_IVS_RSEC_MSK   BIT(RTC_IVS_RSEC_POS)
#define  RTC_IVS_RSEC       RTC_IVS_RSEC_MSK

#define  RTC_IVS_AMALL_POS  7U
#define  RTC_IVS_AMALL_MSK  BIT(RTC_IVS_AMALL_POS)
#define  RTC_IVS_AMALL      RTC_IVS_AMALL_MSK

#define  RTC_IVS_AYEAR_POS  6U
#define  RTC_IVS_AYEAR_MSK  BIT(RTC_IVS_AYEAR_POS)
#define  RTC_IVS_AYEAR      RTC_IVS_AYEAR_MSK

#define  RTC_IVS_AMONTH_POS 5U
#define  RTC_IVS_AMONTH_MSK BIT(RTC_IVS_AMONTH_POS)
#define  RTC_IVS_AMONTH     RTC_IVS_AMONTH_MSK

#define  RTC_IVS_ADTAE_POS  4U
#define  RTC_IVS_ADTAE_MSK  BIT(RTC_IVS_ADTAE_POS)
#define  RTC_IVS_ADTAE      RTC_IVS_ADTAE_MSK

#define  RTC_IVS_AWEEK_POS  3U
#define  RTC_IVS_AWEEK_MSK  BIT(RTC_IVS_AWEEK_POS)
#define  RTC_IVS_AWEEK      RTC_IVS_AWEEK_MSK

#define  RTC_IVS_AHOUR_POS  2U
#define  RTC_IVS_AHOUR_MSK  BIT(RTC_IVS_AHOUR_POS)
#define  RTC_IVS_AHOUR      RTC_IVS_AHOUR_MSK

#define  RTC_IVS_AMIN_POS   1U
#define  RTC_IVS_AMIN_MSK   BIT(RTC_IVS_AMIN_POS)
#define  RTC_IVS_AMIN       RTC_IVS_AMIN_MSK

#define  RTC_IVS_ASEC_POS   0U
#define  RTC_IVS_ASEC_MSK   BIT(RTC_IVS_ASEC_POS)
#define  RTC_IVS_ASEC       RTC_IVS_ASEC_MSK

/****************** Bit definition for RTC_RIF register ************************/

#define  RTC_RIF_WKTM_POS   16U
#define  RTC_RIF_WKTM_MSK   BIT(RTC_RIF_WKTM_POS)
#define  RTC_RIF_WKTM       RTC_RIF_WKTM_MSK

#define  RTC_RIF_F1HZ_POS   15U
#define  RTC_RIF_F1HZ_MSK   BIT(RTC_RIF_F1HZ_POS)
#define  RTC_RIF_F1HZ       RTC_RIF_F1HZ_MSK

#define  RTC_RIF_RYEAR_POS  14U
#define  RTC_RIF_RYEAR_MSK  BIT(RTC_RIF_RYEAR_POS)
#define  RTC_RIF_RYEAR      RTC_RIF_RYEAR_MSK

#define  RTC_RIF_RMON_POS   13U
#define  RTC_RIF_RMON_MSK   BIT(RTC_RIF_RMON_POS)
#define  RTC_RIF_RMON       RTC_RIF_RMON_MSK

#define  RTC_RIF_RDATE_POS  12U
#define  RTC_RIF_RDATE_MSK  BIT(RTC_RIF_RDATE_POS)
#define  RTC_RIF_RDATE      RTC_RIF_RDATE_MSK

#define  RTC_RIF_RWEEK_POS  11U
#define  RTC_RIF_RWEEK_MSK  BIT(RTC_RIF_RWEEK_POS)
#define  RTC_RIF_RWEEK      RTC_RIF_RWEEK_MSK

#define  RTC_RIF_RHOUR_POS  10U
#define  RTC_RIF_RHOUR_MSK  BIT(RTC_RIF_RHOUR_POS)
#define  RTC_RIF_RHOUR      RTC_RIF_RHOUR_MSK

#define  RTC_RIF_RMIN_POS   9U
#define  RTC_RIF_RMIN_MSK   BIT(RTC_RIF_RMIN_POS)
#define  RTC_RIF_RMIN       RTC_RIF_RMIN_MSK

#define  RTC_RIF_RSEC_POS   8U
#define  RTC_RIF_RSEC_MSK   BIT(RTC_RIF_RSEC_POS)
#define  RTC_RIF_RSEC       RTC_RIF_RSEC_MSK

#define  RTC_RIF_AMALL_POS  7U
#define  RTC_RIF_AMALL_MSK  BIT(RTC_RIF_AMALL_POS)
#define  RTC_RIF_AMALL      RTC_RIF_AMALL_MSK

#define  RTC_RIF_AYEAR_POS  6U
#define  RTC_RIF_AYEAR_MSK  BIT(RTC_RIF_AYEAR_POS)
#define  RTC_RIF_AYEAR      RTC_RIF_AYEAR_MSK

#define  RTC_RIF_AMONTH_POS 5U
#define  RTC_RIF_AMONTH_MSK BIT(RTC_RIF_AMONTH_POS)
#define  RTC_RIF_AMONTH     RTC_RIF_AMONTH_MSK

#define  RTC_RIF_ADTAE_POS  4U
#define  RTC_RIF_ADTAE_MSK  BIT(RTC_RIF_ADTAE_POS)
#define  RTC_RIF_ADTAE      RTC_RIF_ADTAE_MSK

#define  RTC_RIF_AWEEK_POS  3U
#define  RTC_RIF_AWEEK_MSK  BIT(RTC_RIF_AWEEK_POS)
#define  RTC_RIF_AWEEK      RTC_RIF_AWEEK_MSK

#define  RTC_RIF_AHOUR_POS  2U
#define  RTC_RIF_AHOUR_MSK  BIT(RTC_RIF_AHOUR_POS)
#define  RTC_RIF_AHOUR      RTC_RIF_AHOUR_MSK

#define  RTC_RIF_AMIN_POS   1U
#define  RTC_RIF_AMIN_MSK   BIT(RTC_RIF_AMIN_POS)
#define  RTC_RIF_AMIN       RTC_RIF_AMIN_MSK

#define  RTC_RIF_ASEC_POS   0U
#define  RTC_RIF_ASEC_MSK   BIT(RTC_RIF_ASEC_POS)
#define  RTC_RIF_ASEC       RTC_RIF_ASEC_MSK

/****************** Bit definition for RTC_IFM register ************************/

#define  RTC_IFM_WKTM_POS   16U
#define  RTC_IFM_WKTM_MSK   BIT(RTC_IFM_WKTM_POS)
#define  RTC_IFM_WKTM       RTC_IFM_WKTM_MSK

#define  RTC_IFM_F1HZ_POS   15U
#define  RTC_IFM_F1HZ_MSK   BIT(RTC_IFM_F1HZ_POS)
#define  RTC_IFM_F1HZ       RTC_IFM_F1HZ_MSK

#define  RTC_IFM_RYEAR_POS  14U
#define  RTC_IFM_RYEAR_MSK  BIT(RTC_IFM_RYEAR_POS)
#define  RTC_IFM_RYEAR      RTC_IFM_RYEAR_MSK

#define  RTC_IFM_RMON_POS   13U
#define  RTC_IFM_RMON_MSK   BIT(RTC_IFM_RMON_POS)
#define  RTC_IFM_RMON       RTC_IFM_RMON_MSK

#define  RTC_IFM_RDATE_POS  12U
#define  RTC_IFM_RDATE_MSK  BIT(RTC_IFM_RDATE_POS)
#define  RTC_IFM_RDATE      RTC_IFM_RDATE_MSK

#define  RTC_IFM_RWEEK_POS  11U
#define  RTC_IFM_RWEEK_MSK  BIT(RTC_IFM_RWEEK_POS)
#define  RTC_IFM_RWEEK      RTC_IFM_RWEEK_MSK

#define  RTC_IFM_RHOUR_POS  10U
#define  RTC_IFM_RHOUR_MSK  BIT(RTC_IFM_RHOUR_POS)
#define  RTC_IFM_RHOUR      RTC_IFM_RHOUR_MSK

#define  RTC_IFM_RMIN_POS   9U
#define  RTC_IFM_RMIN_MSK   BIT(RTC_IFM_RMIN_POS)
#define  RTC_IFM_RMIN       RTC_IFM_RMIN_MSK

#define  RTC_IFM_RSEC_POS   8U
#define  RTC_IFM_RSEC_MSK   BIT(RTC_IFM_RSEC_POS)
#define  RTC_IFM_RSEC       RTC_IFM_RSEC_MSK

#define  RTC_IFM_AMALL_POS  7U
#define  RTC_IFM_AMALL_MSK  BIT(RTC_IFM_AMALL_POS)
#define  RTC_IFM_AMALL      RTC_IFM_AMALL_MSK

#define  RTC_IFM_AYEAR_POS  6U
#define  RTC_IFM_AYEAR_MSK  BIT(RTC_IFM_AYEAR_POS)
#define  RTC_IFM_AYEAR      RTC_IFM_AYEAR_MSK

#define  RTC_IFM_AMONTH_POS 5U
#define  RTC_IFM_AMONTH_MSK BIT(RTC_IFM_AMONTH_POS)
#define  RTC_IFM_AMONTH     RTC_IFM_AMONTH_MSK

#define  RTC_IFM_ADTAE_POS  4U
#define  RTC_IFM_ADTAE_MSK  BIT(RTC_IFM_ADTAE_POS)
#define  RTC_IFM_ADTAE      RTC_IFM_ADTAE_MSK

#define  RTC_IFM_AWEEK_POS  3U
#define  RTC_IFM_AWEEK_MSK  BIT(RTC_IFM_AWEEK_POS)
#define  RTC_IFM_AWEEK      RTC_IFM_AWEEK_MSK

#define  RTC_IFM_AHOUR_POS  2U
#define  RTC_IFM_AHOUR_MSK  BIT(RTC_IFM_AHOUR_POS)
#define  RTC_IFM_AHOUR      RTC_IFM_AHOUR_MSK

#define  RTC_IFM_AMIN_POS   1U
#define  RTC_IFM_AMIN_MSK   BIT(RTC_IFM_AMIN_POS)
#define  RTC_IFM_AMIN       RTC_IFM_AMIN_MSK

#define  RTC_IFM_ASEC_POS   0U
#define  RTC_IFM_ASEC_MSK   BIT(RTC_IFM_ASEC_POS)
#define  RTC_IFM_ASEC       RTC_IFM_ASEC_MSK

/****************** Bit definition for RTC_ICR register ************************/

#define  RTC_ICR_WKTM_POS   16U
#define  RTC_ICR_WKTM_MSK   BIT(RTC_ICR_WKTM_POS)
#define  RTC_ICR_WKTM       RTC_ICR_WKTM_MSK

#define  RTC_ICR_F1HZ_POS   15U
#define  RTC_ICR_F1HZ_MSK   BIT(RTC_ICR_F1HZ_POS)
#define  RTC_ICR_F1HZ       RTC_ICR_F1HZ_MSK

#define  RTC_ICR_RYEAR_POS  14U
#define  RTC_ICR_RYEAR_MSK  BIT(RTC_ICR_RYEAR_POS)
#define  RTC_ICR_RYEAR      RTC_ICR_RYEAR_MSK

#define  RTC_ICR_RMON_POS   13U
#define  RTC_ICR_RMON_MSK   BIT(RTC_ICR_RMON_POS)
#define  RTC_ICR_RMON       RTC_ICR_RMON_MSK

#define  RTC_ICR_RDATE_POS  12U
#define  RTC_ICR_RDATE_MSK  BIT(RTC_ICR_RDATE_POS)
#define  RTC_ICR_RDATE      RTC_ICR_RDATE_MSK

#define  RTC_ICR_RWEEK_POS  11U
#define  RTC_ICR_RWEEK_MSK  BIT(RTC_ICR_RWEEK_POS)
#define  RTC_ICR_RWEEK      RTC_ICR_RWEEK_MSK

#define  RTC_ICR_RHOUR_POS  10U
#define  RTC_ICR_RHOUR_MSK  BIT(RTC_ICR_RHOUR_POS)
#define  RTC_ICR_RHOUR      RTC_ICR_RHOUR_MSK

#define  RTC_ICR_RMIN_POS   9U
#define  RTC_ICR_RMIN_MSK   BIT(RTC_ICR_RMIN_POS)
#define  RTC_ICR_RMIN       RTC_ICR_RMIN_MSK

#define  RTC_ICR_RSEC_POS   8U
#define  RTC_ICR_RSEC_MSK   BIT(RTC_ICR_RSEC_POS)
#define  RTC_ICR_RSEC       RTC_ICR_RSEC_MSK

#define  RTC_ICR_AMALL_POS  7U
#define  RTC_ICR_AMALL_MSK  BIT(RTC_ICR_AMALL_POS)
#define  RTC_ICR_AMALL      RTC_ICR_AMALL_MSK

#define  RTC_ICR_AYEAR_POS  6U
#define  RTC_ICR_AYEAR_MSK  BIT(RTC_ICR_AYEAR_POS)
#define  RTC_ICR_AYEAR      RTC_ICR_AYEAR_MSK

#define  RTC_ICR_AMONTH_POS 5U
#define  RTC_ICR_AMONTH_MSK BIT(RTC_ICR_AMONTH_POS)
#define  RTC_ICR_AMONTH     RTC_ICR_AMONTH_MSK

#define  RTC_ICR_ADTAE_POS  4U
#define  RTC_ICR_ADTAE_MSK  BIT(RTC_ICR_ADTAE_POS)
#define  RTC_ICR_ADTAE      RTC_ICR_ADTAE_MSK

#define  RTC_ICR_AWEEK_POS  3U
#define  RTC_ICR_AWEEK_MSK  BIT(RTC_ICR_AWEEK_POS)
#define  RTC_ICR_AWEEK      RTC_ICR_AWEEK_MSK

#define  RTC_ICR_AHOUR_POS  2U
#define  RTC_ICR_AHOUR_MSK  BIT(RTC_ICR_AHOUR_POS)
#define  RTC_ICR_AHOUR      RTC_ICR_AHOUR_MSK

#define  RTC_ICR_AMIN_POS   1U
#define  RTC_ICR_AMIN_MSK   BIT(RTC_ICR_AMIN_POS)
#define  RTC_ICR_AMIN       RTC_ICR_AMIN_MSK

#define  RTC_ICR_ASEC_POS   0U
#define  RTC_ICR_ASEC_MSK   BIT(RTC_ICR_ASEC_POS)
#define  RTC_ICR_ASEC       RTC_ICR_ASEC_MSK

/****************** Bit definition for RTC_STA register ************************/

#define  RTC_STA_SYNDONE_POS    1U
#define  RTC_STA_SYNDONE_MSK    BIT(RTC_STA_SYNDONE_POS)
#define  RTC_STA_SYNDONE        RTC_STA_SYNDONE_MSK

#define  RTC_STA_EMPTY_POS      0U
#define  RTC_STA_EMPTY_MSK      BIT(RTC_STA_EMPTY_POS)
#define  RTC_STA_EMPTY          RTC_STA_EMPTY_MSK

/****************** Bit definition for RTC_BKEN register ************************/

#define  RTC_BKEN_BKEN_POS  0U
#define  RTC_BKEN_BKEN_MSK  BIT(RTC_BKEN_BKEN_POS)
#define  RTC_BKEN_BKEN      RTC_BKEN_BKEN_MSK

typedef struct
{
    __IO uint32_t CTRL;
    __IO uint32_t WKUP;
    __IO uint32_t TIME;
    __IO uint32_t CAL;
    __IO uint32_t CALIB;
    uint32_t RESERVED14;
    uint32_t RESERVED18;
    uint32_t RESERVED1C;
    __IO uint32_t ALTIME;
    __IO uint32_t ALCAL;
    __IO uint32_t ALEN;
    __IO uint32_t TRIG;
    __O uint32_t  IER;
    __O uint32_t  IDR;
    __I uint32_t  IVS;
    __I uint32_t  RIF;
    __I uint32_t  IFM;
    __O uint32_t  ICR;
    uint32_t RESERVED48;
    uint32_t RESERVED4C;
    __I uint32_t  STA;
    __IO uint32_t BKEN;
} RTC_TypeDef;

#endif
