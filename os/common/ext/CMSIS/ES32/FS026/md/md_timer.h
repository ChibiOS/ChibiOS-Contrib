/**********************************************************************************
 *
 * @file    md_timer.h
 * @brief   header file of md_timer.c
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov 2021     Ginger          the first version
 *          25 Mar 2022     AE Team         Modify MD Driver
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
#ifndef __MD_TIMER_H_
#define __MD_TIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------*/
#include "fs026.h"


/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_TIMER TIMER
  * @brief TIMER micro driver
  * @{
  */


// Bob,Kevin ADD
/** @defgroup TIMER_LL_Private_Variables TIM Private Variables
  * @{
  */
static const uint8_t OFFSET_TAB_CHMRx[] =
{
    0x00U,        /* 0: timx_CH1  */
    0x00U,        /* 1: timx_CH1N */
    0x00U,        /* 2: timx_CH2  */
    0x00U,        /* 3: timx_CH2N */
    0x04U,        /* 4: timx_CH3  */
    0x04U,        /* 5: timx_CH3N */
    0x04U,        /* 6: timx_CH4  */
    0x04U,        /* 7: timx_CH4N */
};

static const uint8_t SHIFT_TAB_OCxx[] =
{
    0U,           /* 0: CH1MOD, CH1FEN, CH1PEN */
    0U,           /* 1: - NA */
    8U,           /* 2: CH2MOD, CH2FEN, CH2PEN */
    0U,           /* 3: - NA */
    0U,           /* 4: CH3MOD, CH3FEN, CH3PEN */
    0U,           /* 5: - NA */
    8U,           /* 6: CH4MOD, CH4FEN, CH4PEN */
    0U,           /* 7: - NA */
};

static const uint8_t SHIFT_TAB_ICxx[] =
{
    0U,           /* 0: CC1SSEL, I1PRES, I1FLT */
    0U,           /* 1: - NA */
    8U,           /* 2: CC2SSEL, I2PRES, I2FLT */
    0U,           /* 3: - NA */
    0U,           /* 4: CC3SSEL, I3PRES, I3FLT */
    0U,           /* 5: - NA */
    8U,           /* 6: CC4SSEL, I4PRES, I4FLT */
    0U,           /* 7: - NA */
};

static const uint8_t SHIFT_TAB_CCxP[] =
{
    0U,           /* 0: CC1POL */
    2U,           /* 1: CC1NPOL */
    4U,           /* 2: CC2POL */
    6U,           /* 3: CC2NPOL */
    8U,           /* 4: CC3POL */
    10U,          /* 5: CC3NPOL */
    12U,          /* 6: CC4POL */
    14U,          /* 7: CC4NPOL */
};

static const uint8_t SHIFT_TAB_OISx[] =
{
    0U,           /* 0: OISS1 */
    1U,           /* 1: OISS1N */
    2U,           /* 2: OISS2 */
    3U,           /* 3: OISS2N */
    4U,           /* 4: OISS3 */
    5U,           /* 5: OISS3N */
    6U,           /* 6: OISS4 */
};

/**
  * @brief TIMER_LL_EC_CHANNEL Channel
  */
#define LL_TIMER_CHANNEL_CH1                TIMER_CCEP_CC1EN     /*!< Timer input/output channel 1 */
#define LL_TIMER_CHANNEL_CH1N               TIMER_CCEP_CC1NEN    /*!< Timer complementary output channel 1 */
#define LL_TIMER_CHANNEL_CH2                TIMER_CCEP_CC2EN     /*!< Timer input/output channel 2 */
#define LL_TIMER_CHANNEL_CH2N               TIMER_CCEP_CC2NEN    /*!< Timer complementary output channel 2 */
#define LL_TIMER_CHANNEL_CH3                TIMER_CCEP_CC3EN     /*!< Timer input/output channel 3 */
#define LL_TIMER_CHANNEL_CH3N               TIMER_CCEP_CC3NEN    /*!< Timer complementary output channel 3 */
#define LL_TIMER_CHANNEL_CH4                TIMER_CCEP_CC4EN     /*!< Timer input/output channel 4 */


/**
  * @brief TIMER_LL_Private_Macros TIM Private Macros
  */
/** @brief  Convert channel id into channel index.
  * @param  __CHANNEL__ This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH1N
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH2N
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH3N
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval none
  */
#define TIMER_GET_CHANNEL_INDEX( __CHANNEL__) \
    (((__CHANNEL__) == LL_TIMER_CHANNEL_CH1)  ? 0U :\
     ((__CHANNEL__) == LL_TIMER_CHANNEL_CH1N) ? 1U :\
     ((__CHANNEL__) == LL_TIMER_CHANNEL_CH2)  ? 2U :\
     ((__CHANNEL__) == LL_TIMER_CHANNEL_CH2N) ? 3U :\
     ((__CHANNEL__) == LL_TIMER_CHANNEL_CH3)  ? 4U :\
     ((__CHANNEL__) == LL_TIMER_CHANNEL_CH3N) ? 5U :\
     ((__CHANNEL__) == LL_TIMER_CHANNEL_CH4)  ? 6U :7U)


// Bob,Kevin ADDEND
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Macros TIMER Public Macros
  * @{
  */

/* TIMER_CON1 macros define*/
#define MD_TIMER_DEBUGSELECT_INPUT          (0) /*!<  Channel input*/
#define MD_TIMER_DEBUGSELECT_OUTPUT         (1) /*!<  Channel output*/

#define MD_TIMER_CLOCKDIVSION_DIV1          (0) /*!<  tDTS=tCK_INT*/
#define MD_TIMER_CLOCKDIVSION_DIV2          (1) /*!<  tDTS=2*tCK_INT*/
#define MD_TIMER_CLOCKDIVSION_DIV4          (2) /*!<  tDTS=4*tCK_INT*/

#define MD_TIMER_CENTERALIGNED_DISABLE      (0) /*!<  Edge-aligned mode*/
#define MD_TIMER_CENTERALIGNED_DOWN         (1) /*!<  Center-aligned mode 1*/
#define MD_TIMER_CENTERALIGNED_UP           (2) /*!<  Center-aligned mode 2*/
#define MD_TIMER_CENTERALIGNED_BOTH         (3) /*!<  Center-aligned mode 3*/

#define MD_TIMER_UPCOUNTER                  (0) /*!<  Counter used as upcounter*/
#define MD_TIMER_DOWNCOUNTER                (1) /*!<  Counter used as downcounter*/

#define MD_TIMER_UPDATESOURCE_NORMAL        (0) /*!<  Counter overflow/underflow, Setting the UG bit, Update generation through the slave mode controller generate an update interrupt*/
#define MD_TIMER_UPDATESOURCE_COUNTER       (1) /*!<  Only counter overflow/underflow generates an update interrupt or DMA request if Enabled*/

/* TIMER_CON2 macros define*/
#define MD_TIMER_OISS4_IDLEOUTPUT_LOW       (0) /*!<  OISS4=0 (after a dead-time if CH4ON is implemented) when GOEN=0*/
#define MD_TIMER_OISS4_IDLEOUTPUT_HIGH      (1) /*!<  OISS4=1 (after a dead-time if CH4ON is implemented) when GOEN=0*/

#define MD_TIMER_OISS3N_IDLEOUTPUT_LOW      (0) /*!<  OISS3N=0 (after a dead-time if CH3ON is implemented) when GOEN=0*/
#define MD_TIMER_OISS3N_IDLEOUTPUT_HIGH     (1) /*!<  OISS3N=1 (after a dead-time if CH3ON is implemented) when GOEN=0*/

#define MD_TIMER_OISS3_IDLEOUTPUT_LOW       (0) /*!<  OISS3=0 (after a dead-time if CH3ON is implemented) when GOEN=0*/
#define MD_TIMER_OISS3_IDLEOUTPUT_HIGH      (1) /*!<  OISS3=1 (after a dead-time if CH3ON is implemented) when GOEN=0*/

#define MD_TIMER_OISS2N_IDLEOUTPUT_LOW      (0) /*!<  OISS2N=0 (after a dead-time if CH2ON is implemented) when GOEN=0*/
#define MD_TIMER_OISS2N_IDLEOUTPUT_HIGH     (1) /*!<  OISS2N=1 (after a dead-time if CH2ON is implemented) when GOEN=0*/

#define MD_TIMER_OISS2_IDLEOUTPUT_LOW       (0) /*!<  OISS2=0 (after a dead-time if CH2ON is implemented) when GOEN=0*/
#define MD_TIMER_OISS2_IDLEOUTPUT_HIGH      (1) /*!<  OISS2=1 (after a dead-time if CH2ON is implemented) when GOEN=0*/

#define MD_TIMER_OISS1N_IDLEOUTPUT_LOW      (0) /*!<  OISS1N=0 (after a dead-time if CH1ON is implemented) when GOEN=0*/
#define MD_TIMER_OISS1N_IDLEOUTPUT_HIGH     (1) /*!<  OISS1N=1 (after a dead-time if CH1ON is implemented) when GOEN=0*/

#define MD_TIMER_OISS1_IDLEOUTPUT_LOW       (0) /*!<  OISS1=0 (after a dead-time if CH1ON is implemented) when GOEN=0*/
#define MD_TIMER_OISS1_IDLEOUTPUT_HIGH      (1) /*!<  OISS1=1 (after a dead-time if CH1ON is implemented) when GOEN=0*/

#define MD_TIMER_TI1INPUT_CH1               (0) /*!<  The timx_CH1 pin is connected to TI1 input*/
#define MD_TIMER_TI1INPUT_XOR               (1) /*!<  The timx_CH1, CH2 and CH3 pins are connected to the TI1 input (XOR combination)*/

#define MD_TIMER_MASTERMODE_RESET           (0) /*!<  Reset mode*/
#define MD_TIMER_MASTERMODE_ENABLE          (1) /*!<  Enable mode*/
#define MD_TIMER_MASTERMODE_UPDATE          (2) /*!<  Update mode*/
#define MD_TIMER_MASTERMODE_COMPAREPULSE    (3) /*!<  Compare Pulse mode*/
#define MD_TIMER_MASTERMODE_COMPARE1        (4) /*!<  Compare 1 mode*/
#define MD_TIMER_MASTERMODE_COMPARE2        (5) /*!<  Compare 2 mode*/
#define MD_TIMER_MASTERMODE_COMPARE3        (6) /*!<  Compare 3 mode*/
#define MD_TIMER_MASTERMODE_COMPARE4        (7) /*!<  Compare 4 mode*/

#define MD_TIMER_DMASELECTION_COMPARE       (0) /*!<  CCx DMA request sent when CCx event occurs*/
#define MD_TIMER_DMASELECTION_UPDATE        (1) /*!<  CCx DMA requests sent when update event occurs*/

#define MD_TIMER_UPDATESELECTION_COMG       (0) /*!<  When capture/compare control bits are preloaded (CCPC=1), they are updated by setting the COMG bit only*/
#define MD_TIMER_UPDATESELECTION_BOTH       (1) /*!<  When capture/compare control bits are preloaded (CCPC=1), they are updated by setting the COMG bit or when an rising edge occurs on TRGI*/

/* TIMER_SMCON macros define*/
#define MD_TIMER_TRIGGER_IT0                ((0x0 >> 3) << TIMER_SMCON_TSSEL2_POSS |  (0x0 & 0x7) << TIMER_SMCON_TSSEL1_POSS)    /*!<  Internal Trigger 0*/
#define MD_TIMER_TRIGGER_IT1                ((0x1 >> 3) << TIMER_SMCON_TSSEL2_POSS |  (0x1 & 0x7) << TIMER_SMCON_TSSEL1_POSS)    /*!<  Internal Trigger 1*/
#define MD_TIMER_TRIGGER_IT2                ((0x2 >> 3) << TIMER_SMCON_TSSEL2_POSS |  (0x2 & 0x7) << TIMER_SMCON_TSSEL1_POSS)    /*!<  Internal Trigger 2*/
#define MD_TIMER_TRIGGER_IT3                ((0x3 >> 3) << TIMER_SMCON_TSSEL2_POSS |  (0x3 & 0x7) << TIMER_SMCON_TSSEL1_POSS)    /*!<  Internal Trigger 3*/
#define MD_TIMER_TRIGGER_I1F_ED             ((0x4 >> 3) << TIMER_SMCON_TSSEL2_POSS |  (0x4 & 0x7) << TIMER_SMCON_TSSEL1_POSS)    /*!<  TI1 Edge Detector*/
#define MD_TIMER_TRIGGER_I1F                ((0x5 >> 3) << TIMER_SMCON_TSSEL2_POSS |  (0x5 & 0x7) << TIMER_SMCON_TSSEL1_POSS)    /*!<  Filtered Timer Input 1*/
#define MD_TIMER_TRIGGER_I2F                ((0x6 >> 3) << TIMER_SMCON_TSSEL2_POSS |  (0x6 & 0x7) << TIMER_SMCON_TSSEL1_POSS)    /*!<  Filtered Timer Input 2*/
#define MD_TIMER_TRIGGER_ETF                ((0x7 >> 3) << TIMER_SMCON_TSSEL2_POSS |  (0x7 & 0x7) << TIMER_SMCON_TSSEL1_POSS)    /*!<  External Trigger input*/
#define MD_TIMER_TRIGGER_IT4                ((0x8 >> 3) << TIMER_SMCON_TSSEL2_POSS |  (0x8 & 0x7) << TIMER_SMCON_TSSEL1_POSS)    /*!<  Internal Trigger 4*/
#define MD_TIMER_TRIGGER_IT5                ((0x9 >> 3) << TIMER_SMCON_TSSEL2_POSS |  (0x9 & 0x7) << TIMER_SMCON_TSSEL1_POSS)    /*!<  Internal Trigger 5*/
#define MD_TIMER_TRIGGER_IT6                ((0xA >> 3) << TIMER_SMCON_TSSEL2_POSS |  (0xA & 0x7) << TIMER_SMCON_TSSEL1_POSS)    /*!<  Internal Trigger 6*/
#define MD_TIMER_TRIGGER_IT7                ((0xB >> 3) << TIMER_SMCON_TSSEL2_POSS |  (0xB & 0x7) << TIMER_SMCON_TSSEL1_POSS)    /*!<  Internal Trigger 7*/
#define MD_TIMER_TRIGGER_IT8                ((0xC >> 3) << TIMER_SMCON_TSSEL2_POSS |  (0xC & 0x7) << TIMER_SMCON_TSSEL1_POSS)    /*!<  Internal Trigger 8*/

#define MD_TIMER_ETRPOLARITY_NONINVERTED    (0) /*!<  ETR is non-inverted*/
#define MD_TIMER_ETRPOLARITY_INVERTED       (1) /*!<  ETR is inverted*/

#define MD_TIMER_ETRPRESCALER_DISABLE       (0) /*!<  Prescaler OFF*/
#define MD_TIMER_ETRPRESCALER_DIV2          (1) /*!<  ETR frequency divided by 2*/
#define MD_TIMER_ETRPRESCALER_DIV4          (2) /*!<  ETR frequency divided by 4*/
#define MD_TIMER_ETRPRESCALER_DIV8          (3) /*!<  ETR frequency divided by 8*/

#define MD_TIMER_ETRFILTER_FDIV1            (0 ) /*!<  No filter*/
#define MD_TIMER_ETRFILTER_FDIV1N2          (1 ) /*!<  fSAMPLING = fCK_INT, N = 2*/
#define MD_TIMER_ETRFILTER_FDIV1N4          (2 ) /*!<  fSAMPLING = fCK_INT, N = 4*/
#define MD_TIMER_ETRFILTER_FDIV1N8          (3 ) /*!<  fSAMPLING = fCK_INT, N = 8*/
#define MD_TIMER_ETRFILTER_FDIV2N6          (4 ) /*!<  fSAMPLING = fDTS / 2, N = 6*/
#define MD_TIMER_ETRFILTER_FDIV2N8          (5 ) /*!<  fSAMPLING = fDTS / 2, N = 8*/
#define MD_TIMER_ETRFILTER_FDIV4N6          (6 ) /*!<  fSAMPLING = fDTS / 4, N = 6*/
#define MD_TIMER_ETRFILTER_FDIV4N8          (7 ) /*!<  fSAMPLING = fDTS / 4, N = 8*/
#define MD_TIMER_ETRFILTER_FDIV8N6          (8 ) /*!<  fSAMPLING = fDTS / 8, N = 6*/
#define MD_TIMER_ETRFILTER_FDIV8N8          (9 ) /*!<  fSAMPLING = fDTS / 8, N = 8*/
#define MD_TIMER_ETRFILTER_FDIV16N5         (10) /*!<  fSAMPLING = fDTS / 16, N = 5*/
#define MD_TIMER_ETRFILTER_FDIV16N6         (11) /*!<  fSAMPLING = fDTS / 16, N = 6*/
#define MD_TIMER_ETRFILTER_FDIV16N8         (12) /*!<  fSAMPLING = fDTS / 16, N = 8*/
#define MD_TIMER_ETRFILTER_FDIV32N5         (13) /*!<  fSAMPLING = fDTS / 32, N = 5*/
#define MD_TIMER_ETRFILTER_FDIV32N6         (14) /*!<  fSAMPLING = fDTS / 32, N = 6*/
#define MD_TIMER_ETRFILTER_FDIV32N8         (15) /*!<  fSAMPLING = fDTS / 32, N = 8*/

#define MD_TIMER_SLAVEMODE_DISABLE          (0) /*!<  Slave mode disabled*/
#define MD_TIMER_SLAVEMODE_ENCODER1         (1) /*!<  Encoder mode 1*/
#define MD_TIMER_SLAVEMODE_ENCODER2         (2) /*!<  Encoder mode 2*/
#define MD_TIMER_SLAVEMODE_ENCODER3         (3) /*!<  Encoder mode 3*/
#define MD_TIMER_SLAVEMODE_RESET            (4) /*!<  Reset Mode*/
#define MD_TIMER_SLAVEMODE_GATED            (5) /*!<  Gated Mode*/
#define MD_TIMER_SLAVEMODE_TRIGGER          (6) /*!<  Trigger Mode*/
#define MD_TIMER_SLAVEMODE_EXTERNALCLOCK    (7) /*!<  External Clock Mode 1*/

/* TIMER_CHMR1 and TIMER_CHMR2 output macros define*/
#define MD_TIMER_OUTPUTMODE_DISABLE         (0) /*!<  Frozen*/
#define MD_TIMER_OUTPUTMODE_HIGHONMSTCH     (1) /*!<  Set channel 1 to active level on match*/
#define MD_TIMER_OUTPUTMODE_LOWONMSTCH      (2) /*!<  Set channel 1 to inactive level on match*/
#define MD_TIMER_OUTPUTMODE_TOGGLE          (3) /*!<  Toggle*/
#define MD_TIMER_OUTPUTMODE_FORCELOW        (4) /*!<  Force inactive level*/
#define MD_TIMER_OUTPUTMODE_FORCEHIGH       (5) /*!<  Force active level*/
#define MD_TIMER_OUTPUTMODE_PWMMODE1        (6) /*!<  PWM mode 1*/
#define MD_TIMER_OUTPUTMODE_PWMMODE2        (7)

/* TIMER_CHMR1 and TIMER_CHMR2 input macros define*/
#define MD_TIMER_INPUTFILTER_FDIV1          (0 )    /*!<  No filter*/
#define MD_TIMER_INPUTFILTER_FDIV1N2        (1 )    /*!<  fSAMPLING = fCK_INT, N = 2*/
#define MD_TIMER_INPUTFILTER_FDIV1N4        (2 )    /*!<  fSAMPLING = fCK_INT, N = 4*/
#define MD_TIMER_INPUTFILTER_FDIV1N8        (3 )    /*!<  fSAMPLING = fCK_INT, N = 8*/
#define MD_TIMER_INPUTFILTER_FDIV2N6        (4 )    /*!<  fSAMPLING = fDTS / 2, N = 6*/
#define MD_TIMER_INPUTFILTER_FDIV2N8        (5 )    /*!<  fSAMPLING = fDTS / 2, N = 8*/
#define MD_TIMER_INPUTFILTER_FDIV4N6        (6 )    /*!<  fSAMPLING = fDTS / 4, N = 6*/
#define MD_TIMER_INPUTFILTER_FDIV4N8        (7 )    /*!<  fSAMPLING = fDTS / 4, N = 8*/
#define MD_TIMER_INPUTFILTER_FDIV8N6        (8 )    /*!<  fSAMPLING = fDTS / 8, N = 6*/
#define MD_TIMER_INPUTFILTER_FDIV8N8        (9 )    /*!<  fSAMPLING = fDTS / 8, N = 8*/
#define MD_TIMER_INPUTFILTER_FDIV16N5       (10)    /*!<  fSAMPLING = fDTS / 16, N = 5*/
#define MD_TIMER_INPUTFILTER_FDIV16N6       (11)    /*!<  fSAMPLING = fDTS / 16, N = 6*/
#define MD_TIMER_INPUTFILTER_FDIV16N8       (12)    /*!<  fSAMPLING = fDTS / 16, N = 8*/
#define MD_TIMER_INPUTFILTER_FDIV32N5       (13)    /*!<  fSAMPLING = fDTS / 32, N = 5*/
#define MD_TIMER_INPUTFILTER_FDIV32N6       (14)    /*!<  fSAMPLING = fDTS / 32, N = 6*/
#define MD_TIMER_INPUTFILTER_FDIV32N8       (15)    /*!<  fSAMPLING = fDTS / 32, N = 8*/

#define MD_TIMER_INPUTPRESCALE_DIV1         (0)     /*!<  no prescaler*/
#define MD_TIMER_INPUTPRESCALE_DIV2         (1)     /*!<  capture is done once every 2 events*/
#define MD_TIMER_INPUTPRESCALE_DIV4         (2)     /*!<  capture is done once every 4 events*/
#define MD_TIMER_INPUTPRESCALE_DIV8         (3)     /*!<  capture is done once every 8 events*/

/* TIMER_CHMR1/CHMR2 input/output macros define*/
#define MD_TIMER_CHMODE_OUTPUT              (0)     /*!<  CCx channel is configured as output*/
#define MD_TIMER_CHMODE_INPUT_DIRECT        (1)     /*!<  CCx channel is configured as input, ICx is mapped direct*/
#define MD_TIMER_CHMODE_INPUT_INDIRECT      (2)     /*!<  CCx channel is configured as input, ICx is mapped indirect*/
#define MD_TIMER_CHMODE_INPUT_TRC           (3)     /*!<  CCx channel is configured as input, ICx is mapped TRC*/

/* TIMER_CCEP input macros define*/
#define MD_TIMER_OUTPUTPOLARITY_HIGH        (0)     /*!<  active high*/
#define MD_TIMER_OUTPUTPOLARITY_LOW         (1)     /*!<  active low*/

/* TIMER_BDCFG input macros define*/
#define MD_TIMER_BREAKPOLARITY_LOW          (0)     /*!<  Break input BRK is active low*/
#define MD_TIMER_BREAKPOLARITY_HIGH         (1)     /*!<  Break input BRK is active high */

#define MD_TIMER_OFFSTATERUN_DISABLE        (0)     /*!<  This bit is used when MOE=1, when inactive, OC/OCN outputs are disabled*/
#define MD_TIMER_OFFSTATERUN_ENABLE         (1)     /*!<  This bit is used when MOE=1, when inactive, OC/OCN outputs are enabled*/

#define MD_TIMER_OFFSTATEIDLE_DISABLE       (0)     /*!<  This bit is used when MOE=0, when inactive, OC/OCN outputs are disabled*/
#define MD_TIMER_OFFSTATEIDLE_ENABLE        (1)     /*!<  This bit is used when MOE=0, when inactive, OC/OCN outputs are forced*/

#define MD_TIMER_LOCKLEVEL_0                (0)     /*!<  LOCK OFF*/
#define MD_TIMER_LOCKLEVEL_1                (1)     /*!<  LOCK Level 1*/
#define MD_TIMER_LOCKLEVEL_2                (2)     /*!<  LOCK Level 2*/
#define MD_TIMER_LOCKLEVEL_3                (3)     /*!<  LOCK Level 3*/

/* TIMER_OPTR input macros define*/
#define MD_TIMER_ETRRMP_ETR                 (0)     /*!<  Timer ETR*/
#define MD_TIMER_ETRRMP_CMP1                (1)     /*!<  CMP1 output*/
#define MD_TIMER_ETRRMP_CMP2                (2)     /*!<  CMP2 output*/
#define MD_TIMER_ETRRMP_ADCAWD              (3)     /*!<  ADC watchdog*/

#define MD_TIMER_CH4RMP_CH4                 (0)     /*!<  Timer channel 4*/

#define MD_TIMER_CH3RMP_CH3                 (0)     /*!<  Timer channel 3*/

#define MD_TIMER_CH2RMP_CH2                 (0)     /*!<  Timer channel 2*/
#define MD_TIMER_CH2RMP_CMP2                (1)     /*!<  CMP2 output*/

#define MD_TIMER_CH1RMP_CH1                 (0)     /*!<  Timer channel 1*/
#define MD_TIMER_CH1RMP_CMP1                (1)     /*!<  CMP1 output*/

/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions TIMER Public Functions
  * @{
  */

/** @defgroup MD_TIMER_Public_Functions_Group2 CON1
  * @{
  */
/**
  * @brief  Timer CON1 setup.
  * @param  timx TIMER instance
  * @param  value (DBGSEL | DFCKSEL | ARPEN | CMSEL | DIRSEL | SPMEN | UERSEL | DISUE | CNTEN)
  * @retval None
  */

__STATIC_INLINE void md_timer_set_con1(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->CON1, value);
}

/**
  * @brief  GET Timer CON1 register value.
  * @param  timx TIMER instance
  * @retval Timer CON1 register value.
  */

__STATIC_INLINE uint32_t md_timer_get_con1(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->CON1));
}

/**
  * @brief  Timer debug mode keep output enable.
  * @param  timx TIMER instance
  * @param  DebugSelect Debug mode output select
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_debug_keep_output(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CON1, TIMER_CON1_DBGSEL);
}

/**
  * @brief  Timer debug mode keep output disable.
  * @param  timx TIMER instance
  * @param  DebugSelect Debug mode output select
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_debug_keep_output(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CON1, TIMER_CON1_DBGSEL);
}

/**
  * @brief  Timer debug mode keep output is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_debug_keep_output(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CON1, TIMER_CON1_DBGSEL) == (TIMER_CON1_DBGSEL));
}

/**
  * @brief  Timer clock division setup.
  * @param  timx TIMER instance
  * @param  ClockDivision Clock division
            @arg @ref MD_TIMER_CLOCKDIVSION_DIV1
            @arg @ref MD_TIMER_CLOCKDIVSION_DIV2
            @arg @ref MD_TIMER_CLOCKDIVSION_DIV4
  * @retval None
  */

__STATIC_INLINE void md_timer_set_df_clock_dfcksel(TIMER_TypeDef *timx, uint32_t ClockDivision)
{
    MODIFY_REG(timx->CON1, TIMER_CON1_DFCKSEL, ClockDivision << TIMER_CON1_DFCKSEL_POSS);
}

/**
  * @brief  Get timer Clock division.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_CLOCKDIVSION_DIV1
            @arg @ref MD_TIMER_CLOCKDIVSION_DIV2
            @arg @ref MD_TIMER_CLOCKDIVSION_DIV4
  */

__STATIC_INLINE uint32_t md_timer_get_df_clock_dfcksel(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CON1, TIMER_CON1_DFCKSEL) >> TIMER_CON1_DFCKSEL_POSS);
}

/**
  * @brief  Timer auto-reload preload enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_autoreload_preload_arpen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CON1, TIMER_CON1_ARPEN);
}

/**
  * @brief  Timer auto-reload preload disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_autoreload_preload_arpen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CON1, TIMER_CON1_ARPEN);
}

/**
  * @brief  Indicates whether the timer auto-reload preload is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_autoreload_preload_arpen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CON1, TIMER_CON1_ARPEN) == (TIMER_CON1_ARPEN));
}

/**
  * @brief  Timer center-aligned mode selection setup.
  * @param  timx TIMER instance
  * @param  CenterAlignedMode center-aligned mode selection
            @arg @ref MD_TIMER_CENTERALIGNED_DISABLE
            @arg @ref MD_TIMER_CENTERALIGNED_DOWN
            @arg @ref MD_TIMER_CENTERALIGNED_UP
            @arg @ref MD_TIMER_CENTERALIGNED_BOTH
  * @retval None
  */

__STATIC_INLINE void md_timer_set_counter_aligned_mode_cmsel(TIMER_TypeDef *timx, uint32_t CenterAlignedMode)
{
    MODIFY_REG(timx->CON1, TIMER_CON1_CMSEL, CenterAlignedMode << TIMER_CON1_CMSEL_POSS);
}

/**
  * @brief  Get timer center-aligned mode selection.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_CENTERALIGNED_DISABLE
            @arg @ref MD_TIMER_CENTERALIGNED_DOWN
            @arg @ref MD_TIMER_CENTERALIGNED_UP
            @arg @ref MD_TIMER_CENTERALIGNED_BOTH
  */

__STATIC_INLINE uint32_t md_timer_get_counter_aligned_mode_cmsel(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CON1, TIMER_CON1_CMSEL) >> TIMER_CON1_CMSEL_POSS);
}

/**
  * @brief  Timer counting direction setup.
  * @param  timx TIMER instance
  * @param  direction Counting direction
            @arg @ref MD_TIMER_UPCOUNTER
            @arg @ref MD_TIMER_DOWNCOUNTER
  * @retval None
  */

__STATIC_INLINE void md_timer_set_counter_direction_dirsel(TIMER_TypeDef *timx, uint32_t direction)
{
    MODIFY_REG(timx->CON1, TIMER_CON1_DIRSEL, direction << TIMER_CON1_DIRSEL_POS);
}

/**
  * @brief  Get timer counting direction.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_UPCOUNTER
            @arg @ref MD_TIMER_DOWNCOUNTER
  */

__STATIC_INLINE uint32_t md_timer_get_counter_direction_dirsel(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CON1, TIMER_CON1_DIRSEL) >> TIMER_CON1_DIRSEL_POS);
}

/**
  * @brief  Timer one pulse mode enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_onepulse_spmen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CON1, TIMER_CON1_SPMEN);
}

/**
  * @brief  Timer one pulse mode disable.
  * @param  timx TIMER instance
  * @retval None.
  */

__STATIC_INLINE void md_timer_disable_onepulse_spmen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CON1, TIMER_CON1_SPMEN);
}

/**
  * @brief  Indicates whether the timer one pulse mode is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_onepulse_spmen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CON1, TIMER_CON1_SPMEN) == (TIMER_CON1_SPMEN));
}

/**
  * @brief  Timer update request source setup.
  * @param  timx TIMER instance
  * @param  UpdateSource Update request source select
            @arg @ref MD_TIMER_UPDATESOURCE_NORMAL
            @arg @ref MD_TIMER_UPDATESOURCE_COUNTER
  * @retval None
  */

__STATIC_INLINE void md_timer_set_update_source_uersel(TIMER_TypeDef *timx, uint32_t UpdateSource)
{
    MODIFY_REG(timx->CON1, TIMER_CON1_UERSEL, UpdateSource << TIMER_CON1_UERSEL_POS);
}

/**
  * @brief  Get timer update request source.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_UPDATESOURCE_NORMAL
            @arg @ref MD_TIMER_UPDATESOURCE_COUNTER
  */

__STATIC_INLINE uint32_t md_timer_get_update_source_uersel(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CON1, TIMER_CON1_UERSEL) >> TIMER_CON1_UERSEL_POS);
}

/**
  * @brief  Timer update event enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_update_disue(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CON1, TIMER_CON1_DISUE);
}

/**
  * @brief  Timer update event disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_update_disue(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CON1, TIMER_CON1_DISUE);
}

/**
  * @brief  Indicates whether the timer update event is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_update_disue(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CON1, TIMER_CON1_DISUE) == (TIMER_CON1_DISUE));
}

/**
  * @brief  Timer counter enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_counter_cnten(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CON1, TIMER_CON1_CNTEN);
}

/**
  * @brief  Timer counter disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_counter_cnten(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CON1, TIMER_CON1_CNTEN);
}

/**
  * @brief  Indicates whether the timer counter is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_counter_cnten(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CON1, TIMER_CON1_CNTEN) == (TIMER_CON1_CNTEN));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group3 CON2
  * @{
  */
/**
  * @brief  Timer CON2 setup.
  * @param  timx TIMER instance
  * @param  value (OISS4 | OISS3N | OISS3 | OISS2N | OISS2 | OISS1N | OISS1 | I1SEL | MMSEL | CCDMASEL | CCUSEL | CCPCEN)
  * @retval None
  */

__STATIC_INLINE void md_timer_set_con2(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->CON2, value);
}

/**
  * @brief  GET Timer CON2 register value.
  * @param  timx TIMER instance
  * @retval Timer CON2 register value.
  */

__STATIC_INLINE uint32_t md_timer_get_con2(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->CON2));
}

/**
  * @brief  Timer output idle state 4 setup.
  * @param  timx TIMER instance
  * @param  IdleOutput Output idle state
            @arg @ref MD_TIMER_OISS4_IDLEOUTPUT_LOW
            @arg @ref MD_TIMER_OISS4_IDLEOUTPUT_HIGH
  * @retval None
  */

__STATIC_INLINE void md_timer_set_ch4o_idle_select_oiss4(TIMER_TypeDef *timx, uint32_t IdleOutput)
{
    MODIFY_REG(timx->CON2, TIMER_CON2_OISS4, IdleOutput << TIMER_CON2_OISS4_POS);
}

/**
  * @brief  Get timer output idle state 4.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_OISS4_IDLEOUTPUT_LOW
            @arg @ref MD_TIMER_OISS4_IDLEOUTPUT_HIGH
  */

__STATIC_INLINE uint32_t md_timer_get_ch4o_idle_select_oiss4(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CON2, TIMER_CON2_OISS4) >> TIMER_CON2_OISS4_POS);
}

/**
  * @brief  Timer output idle state 3N setup.
  * @param  timx TIMER instance
  * @param  IdleOutput Output idle state
            @arg @ref MD_TIMER_OISS3N_IDLEOUTPUT_LOW
            @arg @ref MD_TIMER_OISS3N_IDLEOUTPUT_HIGH
  * @retval None
  */

__STATIC_INLINE void md_timer_set_ch3on_idle_select_oiss3n(TIMER_TypeDef *timx, uint32_t IdleOutput)
{
    MODIFY_REG(timx->CON2, TIMER_CON2_OISS3N, IdleOutput << TIMER_CON2_OISS3N_POS);
}

/**
  * @brief  Get timer output idle state 3N.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_OISS3N_IDLEOUTPUT_LOW
            @arg @ref MD_TIMER_OISS3N_IDLEOUTPUT_HIGH
  */

__STATIC_INLINE uint32_t md_timer_get_ch3on_idle_select_oiss3n(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CON2, TIMER_CON2_OISS3N) >> TIMER_CON2_OISS3N_POS);
}

/**
  * @brief  Timer output idle state 3 setup.
  * @param  timx TIMER instance
  * @param  IdleOutput Output idle state
            @arg @ref MD_TIMER_OISS3_IDLEOUTPUT_LOW
            @arg @ref MD_TIMER_OISS3_IDLEOUTPUT_HIGH
  * @retval None
  */

__STATIC_INLINE void md_timer_set_ch3o_idle_select_oiss3(TIMER_TypeDef *timx, uint32_t IdleOutput)
{
    MODIFY_REG(timx->CON2, TIMER_CON2_OISS3, IdleOutput << TIMER_CON2_OISS3_POS);
}

/**
  * @brief  Get timer output idle state 3.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_OISS3_IDLEOUTPUT_LOW
            @arg @ref MD_TIMER_OISS3_IDLEOUTPUT_HIGH
  */

__STATIC_INLINE uint32_t md_timer_get_ch3o_idle_select_oiss3(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CON2, TIMER_CON2_OISS3) >> TIMER_CON2_OISS3_POS);
}

/**
  * @brief  Timer output idle state 2N setup.
  * @param  timx TIMER instance
  * @param  IdleOutput Output idle state
            @arg @ref MD_TIMER_OISS2N_IDLEOUTPUT_LOW
            @arg @ref MD_TIMER_OISS2N_IDLEOUTPUT_HIGH
  * @retval None
  */

__STATIC_INLINE void md_timer_set_ch2on_idle_select_oiss2n(TIMER_TypeDef *timx, uint32_t IdleOutput)
{
    MODIFY_REG(timx->CON2, TIMER_CON2_OISS2N, IdleOutput << TIMER_CON2_OISS2N_POS);
}

/**
  * @brief  Get timer output idle state 2N.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_OISS2N_IDLEOUTPUT_LOW
            @arg @ref MD_TIMER_OISS2N_IDLEOUTPUT_HIGH
  */

__STATIC_INLINE uint32_t md_timer_get_ch2on_idle_select_oiss2n(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CON2, TIMER_CON2_OISS2N) >> TIMER_CON2_OISS2N_POS);
}

/**
  * @brief  Timer output idle state 2 setup.
  * @param  timx TIMER instance
  * @param  IdleOutput Output idle state
            @arg @ref MD_TIMER_OISS2_IDLEOUTPUT_LOW
            @arg @ref MD_TIMER_OISS2_IDLEOUTPUT_HIGH
  * @retval None
  */

__STATIC_INLINE void md_timer_set_ch2o_idle_select_oiss2(TIMER_TypeDef *timx, uint32_t IdleOutput)
{
    MODIFY_REG(timx->CON2, TIMER_CON2_OISS2, IdleOutput << TIMER_CON2_OISS2_POS);
}

/**
  * @brief  Get timer output idle state 2.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_OISS2_IDLEOUTPUT_LOW
            @arg @ref MD_TIMER_OISS2_IDLEOUTPUT_HIGH
  */

__STATIC_INLINE uint32_t md_timer_get_ch2o_idle_select_oiss2(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CON2, TIMER_CON2_OISS2) >> TIMER_CON2_OISS2_POS);
}

/**
  * @brief  Timer output idle state 1N setup.
  * @param  timx TIMER instance
  * @param  IdleOutput Output idle state
            @arg @ref MD_TIMER_OISS1N_IDLEOUTPUT_LOW
            @arg @ref MD_TIMER_OISS1N_IDLEOUTPUT_HIGH
  * @retval None
  */

__STATIC_INLINE void md_timer_set_ch1on_idle_select_oiss1n(TIMER_TypeDef *timx, uint32_t IdleOutput)
{
    MODIFY_REG(timx->CON2, TIMER_CON2_OISS1N, IdleOutput << TIMER_CON2_OISS1N_POS);
}

/**
  * @brief  Get timer output idle state 1N.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_OISS1N_IDLEOUTPUT_LOW
            @arg @ref MD_TIMER_OISS1N_IDLEOUTPUT_HIGH
  */

__STATIC_INLINE uint32_t md_timer_get_ch1on_idle_select_oiss1n(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CON2, TIMER_CON2_OISS1N) >> TIMER_CON2_OISS1N_POS);
}

/**
  * @brief  Timer output idle state 1 setup.
  * @param  timx TIMER instance
  * @param  IdleOutput Output idle state
            @arg @ref MD_TIMER_OISS1_IDLEOUTPUT_LOW
            @arg @ref MD_TIMER_OISS1_IDLEOUTPUT_HIGH
  * @retval None
  */

__STATIC_INLINE void md_timer_set_ch1o_idle_select_oiss1(TIMER_TypeDef *timx, uint32_t IdleOutput)
{
    MODIFY_REG(timx->CON2, TIMER_CON2_OISS1, IdleOutput << TIMER_CON2_OISS1_POS);
}

/**
  * @brief  Get timer output idle state 1.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_OISS1_IDLEOUTPUT_LOW
            @arg @ref MD_TIMER_OISS1_IDLEOUTPUT_HIGH
  */

__STATIC_INLINE uint32_t md_timer_get_ch1o_idle_select_oiss1(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CON2, TIMER_CON2_OISS1) >> TIMER_CON2_OISS1_POS);
}

/**
  * @brief  Timer TI1 selection setup.
  * @param  timx TIMER instance
  * @param  TI1Input TI1 input select
            @arg @ref MD_TIMER_TI1INPUT_CH1
            @arg @ref MD_TIMER_TI1INPUT_XOR
  * @retval None
  */

__STATIC_INLINE void md_timer_set_i1_func_select_i1sel(TIMER_TypeDef *timx, uint32_t TI1Input)
{
    MODIFY_REG(timx->CON2, TIMER_CON2_I1SEL, TI1Input << TIMER_CON2_I1SEL_POS);
}

/**
  * @brief  Get timer TI1 selection.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_TI1INPUT_CH1
            @arg @ref MD_TIMER_TI1INPUT_XOR
  */

__STATIC_INLINE uint32_t md_timer_get_i1_func_select_i1sel(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CON2, TIMER_CON2_I1SEL) >> TIMER_CON2_I1SEL_POS);
}

/**
  * @brief  Timer master mode selection setup.
  * @param  timx TIMER instance
  * @param  MasterMode Master mode selection
            @arg @ref MD_TIMER_MASTERMODE_RESET
            @arg @ref MD_TIMER_MASTERMODE_ENABLE
            @arg @ref MD_TIMER_MASTERMODE_UPDATE
            @arg @ref MD_TIMER_MASTERMODE_COMPAREPULSE
            @arg @ref MD_TIMER_MASTERMODE_COMPARE1
            @arg @ref MD_TIMER_MASTERMODE_COMPARE2
            @arg @ref MD_TIMER_MASTERMODE_COMPARE3
            @arg @ref MD_TIMER_MASTERMODE_COMPARE4
  * @retval None
  */

__STATIC_INLINE void md_timer_set_master_trgout_select_mmsel(TIMER_TypeDef *timx, uint32_t MasterMode)
{
    MODIFY_REG(timx->CON2, TIMER_CON2_MMSEL, MasterMode << TIMER_CON2_MMSEL_POSS);
}

/**
  * @brief  Get timer master mode selection.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_MASTERMODE_RESET
            @arg @ref MD_TIMER_MASTERMODE_ENABLE
            @arg @ref MD_TIMER_MASTERMODE_UPDATE
            @arg @ref MD_TIMER_MASTERMODE_COMPAREPULSE
            @arg @ref MD_TIMER_MASTERMODE_COMPARE1
            @arg @ref MD_TIMER_MASTERMODE_COMPARE2
            @arg @ref MD_TIMER_MASTERMODE_COMPARE3
            @arg @ref MD_TIMER_MASTERMODE_COMPARE4
  */

__STATIC_INLINE uint32_t md_timer_get_master_trgout_select_mmsel(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CON2, TIMER_CON2_MMSEL) >> TIMER_CON2_MMSEL_POSS);
}

/**
  * @brief  Timer capture/compare DMA selection setup.
  * @param  timx TIMER instance
  * @param  DMASelection Capture/compare DMA selection
            @arg @ref MD_TIMER_DMASELECTION_COMPARE
            @arg @ref MD_TIMER_DMASELECTION_UPDATE
  * @retval None
  */

__STATIC_INLINE void md_timer_set_cc_dma_select_ccdmasel(TIMER_TypeDef *timx, uint32_t DMASelection)
{
    MODIFY_REG(timx->CON2, TIMER_CON2_CCDMASEL, DMASelection << TIMER_CON2_CCDMASEL_POS);
}

/**
  * @brief  Get timer capture/compare DMA selection.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_DMASELECTION_COMPARE
            @arg @ref MD_TIMER_DMASELECTION_UPDATE
  */

__STATIC_INLINE uint32_t md_timer_get_cc_dma_select_ccdmasel(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CON2, TIMER_CON2_CCDMASEL) >> TIMER_CON2_CCDMASEL_POS);
}

/**
  * @brief  Timer capture/compare control update selection setup.
  * @param  timx TIMER instance
  * @param  UpdateSelection Capture/compare control update selection
            @arg @ref MD_TIMER_UPDATESELECTION_COMG
            @arg @ref MD_TIMER_UPDATESELECTION_BOTH
  * @retval None
  */

__STATIC_INLINE void md_timer_set_cc_update_select_ccusel(TIMER_TypeDef *timx, uint32_t UpdateSelection)
{
    MODIFY_REG(timx->CON2, TIMER_CON2_CCUSEL, UpdateSelection << TIMER_CON2_CCUSEL_POS);
}

/**
  * @brief  Get timer capture/compare control update selection.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_UPDATESELECTION_COMG
            @arg @ref MD_TIMER_UPDATESELECTION_BOTH
 */

__STATIC_INLINE uint32_t md_timer_get_cc_update_select_ccusel(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CON2, TIMER_CON2_CCUSEL) >> TIMER_CON2_CCUSEL_POS);
}

/**
  * @brief  Timer capture/compare preloaded control enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_cc_preload_ccpcen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CON2, TIMER_CON2_CCPCEN);
}

/**
  * @brief  Timer capture/compare preloaded control disable.
  * @param  timx TIMER instance
  * @retval None.
  */

__STATIC_INLINE void md_timer_disable_cc_preload_ccpcen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CON2, TIMER_CON2_CCPCEN);
}

/**
  * @brief  Indicates whether the timer capture/compare preloaded control is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_cc_preload_ccpcen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CON2, TIMER_CON2_CCPCEN) == (TIMER_CON2_CCPCEN));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group4 SMCON
  * @{
  */
/**
  * @brief  Timer SMCON setup.
  * @param  timx TIMER instance
  * @param  value (TSSEL2 | ETPOL | ECM2EN | ETPRES | ETFLT | MSCFG | TSSEL1 | SMODS)
  * @retval None
  */

__STATIC_INLINE void md_timer_set_smcon(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->SMCON, value);
}

/**
  * @brief  GET Timer SMCON register value.
  * @param  timx TIMER instance
  * @retval Timer SMCON register value.
  */

__STATIC_INLINE uint32_t md_timer_get_smcon(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->SMCON));
}

/**
  * @brief  Timer trigger selection setup.
  * @param  timx TIMER instance
  * @param  TrigerSelect External trigger selection
            @arg @ref MD_TIMER_TRIGGER_IT0
            @arg @ref MD_TIMER_TRIGGER_IT1
            @arg @ref MD_TIMER_TRIGGER_IT2
            @arg @ref MD_TIMER_TRIGGER_IT3
            @arg @ref MD_TIMER_TRIGGER_I1F_ED
            @arg @ref MD_TIMER_TRIGGER_I1F
            @arg @ref MD_TIMER_TRIGGER_I2F
            @arg @ref MD_TIMER_TRIGGER_ETF
            @arg @ref MD_TIMER_TRIGGER_IT4
            @arg @ref MD_TIMER_TRIGGER_IT5
            @arg @ref MD_TIMER_TRIGGER_IT6
            @arg @ref MD_TIMER_TRIGGER_IT7
            @arg @ref MD_TIMER_TRIGGER_IT8
  * @retval None
  */

__STATIC_INLINE void md_timer_set_slave_trigger_tssel(TIMER_TypeDef *timx, uint32_t TrigerSelect)
{
    MODIFY_REG(timx->SMCON, (TIMER_SMCON_TSSEL2 | TIMER_SMCON_TSSEL1), TrigerSelect);
}

/**
  * @brief  Get timer trigger selection setup.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_TRIGGER_IT0
            @arg @ref MD_TIMER_TRIGGER_IT1
            @arg @ref MD_TIMER_TRIGGER_IT2
            @arg @ref MD_TIMER_TRIGGER_IT3
            @arg @ref MD_TIMER_TRIGGER_I1F_ED
            @arg @ref MD_TIMER_TRIGGER_I1F
            @arg @ref MD_TIMER_TRIGGER_I2F
            @arg @ref MD_TIMER_TRIGGER_ETF
            @arg @ref MD_TIMER_TRIGGER_IT4
            @arg @ref MD_TIMER_TRIGGER_IT5
            @arg @ref MD_TIMER_TRIGGER_IT6
            @arg @ref MD_TIMER_TRIGGER_IT7
            @arg @ref MD_TIMER_TRIGGER_IT8
  */

__STATIC_INLINE uint32_t md_timer_get_slave_trigger_tssel(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->SMCON, (TIMER_SMCON_TSSEL2 | TIMER_SMCON_TSSEL1)));
}

/**
  * @brief  Timer external trigger polarity setup.
  * @param  timx TIMER instance
  * @param  ETRPolarity External trigger polarity
            @arg @ref MD_TIMER_ETRPOLARITY_NONINVERTED
            @arg @ref MD_TIMER_ETRPOLARITY_INVERTED
  * @retval None
  */

__STATIC_INLINE void md_timer_set_external_trigger_polarity_etpol(TIMER_TypeDef *timx, uint32_t ETRPolarity)
{
    MODIFY_REG(timx->SMCON, TIMER_SMCON_ETPOL, ETRPolarity << TIMER_SMCON_ETPOL_POS);
}

/**
  * @brief  Timer external trigger polarity setup.
  * @param  timx TIMER instance
  * @param  ETRPolarity External trigger polarity
  * @retval None
  */

__STATIC_INLINE uint32_t md_timer_get_external_trigger_polarity_etpol(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->SMCON, TIMER_SMCON_ETPOL) >> TIMER_SMCON_ETPOL_POS);
}

/**
  * @brief  Timer external clock enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_external_clk2mode_ecm2en(TIMER_TypeDef *timx)
{
    SET_BIT(timx->SMCON, TIMER_SMCON_ECM2EN);
}


/**
  * @brief  Timer external clock disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_external_clk2mode_ecm2en(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->SMCON, TIMER_SMCON_ECM2EN);
}

/**
  * @brief  Indicates whether the timer external clock is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_external_clk2mode_ecm2en(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->SMCON, TIMER_SMCON_ECM2EN) == (TIMER_SMCON_ECM2EN));
}

/**
  * @brief  Timer external trigger prescaler setup.
  * @param  timx TIMER instance
  * @param  ETRPrescale External trigger prescaler
            @arg @ref MD_TIMER_ETRPRESCALER_DISABLE
            @arg @ref MD_TIMER_ETRPRESCALER_DIV2
            @arg @ref MD_TIMER_ETRPRESCALER_DIV4
            @arg @ref MD_TIMER_ETRPRESCALER_DIV8
  * @retval None
  */

__STATIC_INLINE void md_timer_set_external_trigger_prescaler_etpres(TIMER_TypeDef *timx, uint32_t ETRPrescale)
{
    MODIFY_REG(timx->SMCON, TIMER_SMCON_ETPRES, ETRPrescale << TIMER_SMCON_ETPRES_POSS);
}

/**
  * @brief  Get Timer external trigger prescaler setup.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_ETRPRESCALER_DISABLE
            @arg @ref MD_TIMER_ETRPRESCALER_DIV2
            @arg @ref MD_TIMER_ETRPRESCALER_DIV4
            @arg @ref MD_TIMER_ETRPRESCALER_DIV8
  */

__STATIC_INLINE uint32_t md_timer_get_external_trigger_prescaler_etpres(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->SMCON, TIMER_SMCON_ETPRES) >> TIMER_SMCON_ETPRES_POSS);
}

/**
  * @brief  Timer external trigger filter setup.
  * @param  timx TIMER instance
  * @param  ETRFilter External trigger filter
            @arg @ref MD_TIMER_ETRFILTER_FDIV1
            @arg @ref MD_TIMER_ETRFILTER_FDIV1N2
            @arg @ref MD_TIMER_ETRFILTER_FDIV1N4
            @arg @ref MD_TIMER_ETRFILTER_FDIV1N8
            @arg @ref MD_TIMER_ETRFILTER_FDIV2N6
            @arg @ref MD_TIMER_ETRFILTER_FDIV2N8
            @arg @ref MD_TIMER_ETRFILTER_FDIV4N6
            @arg @ref MD_TIMER_ETRFILTER_FDIV4N8
            @arg @ref MD_TIMER_ETRFILTER_FDIV8N6
            @arg @ref MD_TIMER_ETRFILTER_FDIV8N8
            @arg @ref MD_TIMER_ETRFILTER_FDIV16N5
            @arg @ref MD_TIMER_ETRFILTER_FDIV16N6
            @arg @ref MD_TIMER_ETRFILTER_FDIV16N8
            @arg @ref MD_TIMER_ETRFILTER_FDIV32N5
            @arg @ref MD_TIMER_ETRFILTER_FDIV32N6
            @arg @ref MD_TIMER_ETRFILTER_FDIV32N8
  * @retval None
  */

__STATIC_INLINE void md_timer_set_external_trigger_filter_etflt(TIMER_TypeDef *timx, uint32_t ETRFilter)
{
    MODIFY_REG(timx->SMCON, TIMER_SMCON_ETFLT, ETRFilter << TIMER_SMCON_ETFLT_POSS);
}

/**
  * @brief  Get timer external trigger filter.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_ETRFILTER_FDIV1
            @arg @ref MD_TIMER_ETRFILTER_FDIV1N2
            @arg @ref MD_TIMER_ETRFILTER_FDIV1N4
            @arg @ref MD_TIMER_ETRFILTER_FDIV1N8
            @arg @ref MD_TIMER_ETRFILTER_FDIV2N6
            @arg @ref MD_TIMER_ETRFILTER_FDIV2N8
            @arg @ref MD_TIMER_ETRFILTER_FDIV4N6
            @arg @ref MD_TIMER_ETRFILTER_FDIV4N8
            @arg @ref MD_TIMER_ETRFILTER_FDIV8N6
            @arg @ref MD_TIMER_ETRFILTER_FDIV8N8
            @arg @ref MD_TIMER_ETRFILTER_FDIV16N5
            @arg @ref MD_TIMER_ETRFILTER_FDIV16N6
            @arg @ref MD_TIMER_ETRFILTER_FDIV16N8
            @arg @ref MD_TIMER_ETRFILTER_FDIV32N5
            @arg @ref MD_TIMER_ETRFILTER_FDIV32N6
            @arg @ref MD_TIMER_ETRFILTER_FDIV32N8
  */

__STATIC_INLINE uint32_t md_timer_get_external_trigger_filter_etflt(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->SMCON, TIMER_SMCON_ETFLT) >> TIMER_SMCON_ETFLT_POSS);
}

/**
  * @brief  Timer master/slave mode synchronize enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_master_mode_mscfg(TIMER_TypeDef *timx)
{
    SET_BIT(timx->SMCON, TIMER_SMCON_MSCFG);
}

/**
  * @brief  Timer master/slave mode synchronize disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_master_mode_mscfg(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->SMCON, TIMER_SMCON_MSCFG);
}

/**
  * @brief  Get timer master/slave mode.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_master_mode_mscfg(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->SMCON, TIMER_SMCON_MSCFG) == TIMER_SMCON_MSCFG);
}

/**
  * @brief  Timer slave mode selection setup.
  * @param  timx TIMER instance
  * @param  SlaveMode Slave mode selection
            @arg @ref MD_TIMER_SLAVEMODE_DISABLE
            @arg @ref MD_TIMER_SLAVEMODE_ENCODER1
            @arg @ref MD_TIMER_SLAVEMODE_ENCODER2
            @arg @ref MD_TIMER_SLAVEMODE_ENCODER3
            @arg @ref MD_TIMER_SLAVEMODE_RESET
            @arg @ref MD_TIMER_SLAVEMODE_GATED
            @arg @ref MD_TIMER_SLAVEMODE_TRIGGER
            @arg @ref MD_TIMER_SLAVEMODE_EXTERNALCLOCK
  * @retval None
  */

__STATIC_INLINE void md_timer_set_slave_mode_smods(TIMER_TypeDef *timx, uint32_t SlaveMode)
{
    MODIFY_REG(timx->SMCON, TIMER_SMCON_SMODS, SlaveMode << TIMER_SMCON_SMODS_POSS);
}

/**
  * @brief  Get timer slave mode selection.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_SLAVEMODE_DISABLE
            @arg @ref MD_TIMER_SLAVEMODE_ENCODER1
            @arg @ref MD_TIMER_SLAVEMODE_ENCODER2
            @arg @ref MD_TIMER_SLAVEMODE_ENCODER3
            @arg @ref MD_TIMER_SLAVEMODE_RESET
            @arg @ref MD_TIMER_SLAVEMODE_GATED
            @arg @ref MD_TIMER_SLAVEMODE_TRIGGER
            @arg @ref MD_TIMER_SLAVEMODE_EXTERNALCLOCK
  */

__STATIC_INLINE uint32_t md_timer_get_slave_mode_smods(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->SMCON, TIMER_SMCON_SMODS) >> TIMER_SMCON_SMODS_POSS);
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group5 IER
  * @{
  */
/**
  * @brief  Timer IER setup.
  * @param  timx TIMER instance
  * @param  value (CH4OV | CH3OV | CH2OV | CH1OV | BRK | TRGI | COM | CH4 | CH3 | CH2 | CH1 | UPD)
  * @retval None
  */

__STATIC_INLINE void md_timer_set_ier(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->IER, value);
}

/**
  * @brief  Timer cpture/compare 4 overcapture interrupt enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_it_ch4ov(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IER, TIMER_IER_CH4OV);
}

/**
  * @brief  Timer cpture/compare 3 overcapture interrupt enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_it_ch3ov(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IER, TIMER_IER_CH3OV);
}

/**
  * @brief  Timer cpture/compare 2 overcapture interrupt enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_it_ch2ov(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IER, TIMER_IER_CH2OV);
}

/**
  * @brief  Timer cpture/compare 1 overcapture interrupt enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_it_ch1ov(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IER, TIMER_IER_CH1OV);
}

/**
  * @brief  Timer break interrupt enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_it_brk(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IER, TIMER_IER_BRK);
}

/**
  * @brief  Timer trigger interrupt enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_it_trgi(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IER, TIMER_IER_TRGI);
}

/**
  * @brief  Timer COM interrupt enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_it_com(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IER, TIMER_IER_COM);
}

/**
  * @brief  Timer capture/compare 4 interrupt enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_it_ch4(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IER, TIMER_IER_CH4);
}

/**
  * @brief  Timer capture/compare 3 interrupt enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_it_ch3(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IER, TIMER_IER_CH3);
}

/**
  * @brief  Timer capture/compare 2 interrupt enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_it_ch2(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IER, TIMER_IER_CH2);
}

/**
  * @brief  Timer capture/compare 1 interrupt enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_it_ch1(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IER, TIMER_IER_CH1);
}

/**
  * @brief  Timer update interrupt enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_it_upd(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IER, TIMER_IER_UPD);
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group6 IDR
  * @{
  */
/**
  * @brief  Timer IDR setup.
  * @param  timx TIMER instance
  * @param  value (CH4OV | CH3OV | CH2OV | CH1OV | BRK | TRGI | COM | CH4 | CH3 | CH2 | CH1 | UPD)
  * @retval None
  */

__STATIC_INLINE void md_timer_set_idr(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->IDR, value);
}

/**
  * @brief  Timer cpture/compare 4 overcapture interrupt disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_it_ch4ov(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IDR, TIMER_IDR_CH4OV);
}

/**
  * @brief  Timer cpture/compare 3 overcapture interrupt disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_it_ch3ov(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IDR, TIMER_IDR_CH3OV);
}

/**
  * @brief  Timer cpture/compare 2 overcapture interrupt disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_it_ch2ov(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IDR, TIMER_IDR_CH2OV);
}

/**
  * @brief  Timer cpture/compare 1 overcapture interrupt disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_it_ch1ov(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IDR, TIMER_IDR_CH1OV);
}

/**
  * @brief  Timer break interrupt disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_it_brk(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IDR, TIMER_IDR_BRK);
}

/**
  * @brief  Timer trigger interrupt disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_it_trgi(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IDR, TIMER_IDR_TRGI);
}

/**
  * @brief  Timer COM interrupt disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_it_com(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IDR, TIMER_IDR_COM);
}

/**
  * @brief  Timer capture/compare 4 interrupt disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_it_ch4(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IDR, TIMER_IDR_CH4);
}

/**
  * @brief  Timer capture/compare 3 interrupt disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_it_ch3(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IDR, TIMER_IDR_CH3);
}

/**
  * @brief  Timer capture/compare 2 interrupt disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_it_ch2(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IDR, TIMER_IDR_CH2);
}

/**
  * @brief  Timer capture/compare 1 interrupt disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_it_ch1(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IDR, TIMER_IDR_CH1);
}

/**
  * @brief  Timer update interrupt disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_it_upd(TIMER_TypeDef *timx)
{
    SET_BIT(timx->IDR, TIMER_IDR_UPD);
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group7 IVS
  * @{
  */
/**
  * @brief  Get timer IVS setup.
  * @param  timx TIMER instance
  * @retval Timer IVS setup.
  */

__STATIC_INLINE uint32_t md_timer_get_ivs(TIMER_TypeDef *timx)
{
    return (READ_REG(timx->IVS));
}

/**
  * @brief  Indicates whether the timer capture/compare 4 overcapture interrupt is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_it_ch4ov(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IVS, TIMER_IVS_CH4OV) == (TIMER_IVS_CH4OV));
}

/**
  * @brief  Indicates whether the timer capture/compare 3 overcapture interrupt is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_it_ch3ov(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IVS, TIMER_IVS_CH3OV) == (TIMER_IVS_CH3OV));
}

/**
  * @brief  Indicates whether the timer cpture/compare 2 overcapture interrupt is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_it_ch2ov(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IVS, TIMER_IVS_CH2OV) == (TIMER_IVS_CH2OV));
}

/**
  * @brief  Indicates whether the timer capture/compare 1 overcapture interrupt is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_it_ch1ov(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IVS, TIMER_IVS_CH1OV) == (TIMER_IVS_CH1OV));
}

/**
  * @brief  Indicates whether the timer break interrupt is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_it_brk(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IVS, TIMER_IVS_BRK) == (TIMER_IVS_BRK));
}

/**
  * @brief  Indicates whether the timer trigger interrupt is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_it_trgi(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IVS, TIMER_IVS_TRGI) == (TIMER_IVS_TRGI));
}

/**
  * @brief  Indicates whether the timer COM interrupt is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_it_com(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IVS, TIMER_IVS_COM) == (TIMER_IVS_COM));
}

/**
  * @brief  Indicates whether the timer Capture/Compare 4 interrupt is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_it_ch4(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IVS, TIMER_IVS_CH4) == (TIMER_IVS_CH4));
}

/**
  * @brief  Indicates whether the timer Capture/Compare 3 interrupt is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_it_ch3(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IVS, TIMER_IVS_CH3) == (TIMER_IVS_CH3));
}

/**
  * @brief  Indicates whether the timer Capture/Compare 2 interrupt is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_it_ch2(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IVS, TIMER_IVS_CH2) == (TIMER_IVS_CH2));
}

/**
  * @brief  Indicates whether the timer Capture/Compare 1 interrupt is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_it_ch1(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IVS, TIMER_IVS_CH1) == (TIMER_IVS_CH1));
}

/**
  * @brief  Indicates whether the timer update interrupt is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_it_upd(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IVS, TIMER_IVS_UPD) == (TIMER_IVS_UPD));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group8 RIF
  * @{
  */
/**
  * @brief  Get timer RIF flag.
  * @param  timx TIMER instance
  * @retval Timer RIF flag.
  */

__STATIC_INLINE uint32_t md_timer_get_rif(TIMER_TypeDef *timx)
{
    return (READ_REG(timx->RIF));
}

/**
  * @brief  Get timer capture/compare 4 overcapture interrupt flag.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_active_it_ch4ov(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->RIF, TIMER_RIF_CH4OV) == (TIMER_RIF_CH4OV));
}

/**
  * @brief  Get timer capture/compare 3 overcapture interrupt flag.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_active_it_ch3ov(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->RIF, TIMER_RIF_CH3OV) == (TIMER_RIF_CH3OV));
}

/**
  * @brief  Get timer capture/compare 2 overcapture interrupt flag.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_active_it_ch2ov(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->RIF, TIMER_RIF_CH2OV) == (TIMER_RIF_CH2OV));
}

/**
  * @brief  Get timer capture/compare 1 overcapture interrupt flag.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_active_it_ch1ov(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->RIF, TIMER_RIF_CH1OV) == (TIMER_RIF_CH1OV));
}

/**
  * @brief  Get timer break interrupt flag.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_active_it_brk(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->RIF, TIMER_RIF_BRK) == (TIMER_RIF_BRK));
}

/**
  * @brief  Get timer trigger interrupt flag.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_active_it_trgi(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->RIF, TIMER_RIF_TRGI) == (TIMER_RIF_TRGI));
}

/**
  * @brief  Get timer COM interrupt flag.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_active_it_com(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->RIF, TIMER_RIF_COM) == (TIMER_RIF_COM));
}

/**
  * @brief  Get timer capture/compare 4 interrupt flag.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_active_it_ch4(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->RIF, TIMER_RIF_CH4) == (TIMER_RIF_CH4));
}

/**
  * @brief  Get timer capture/compare 3 interrupt flag.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_active_it_ch3(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->RIF, TIMER_RIF_CH3) == (TIMER_RIF_CH3));
}

/**
  * @brief  Get timer capture/compare 2 interrupt flag.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_active_it_ch2(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->RIF, TIMER_RIF_CH2) == (TIMER_RIF_CH2));
}

/**
  * @brief  Get timer capture/compare 1 interrupt flag.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_active_it_ch1(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->RIF, TIMER_RIF_CH1) == (TIMER_RIF_CH1));
}

/**
  * @brief  Get timer update interrupt flag.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_active_it_upd(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->RIF, TIMER_RIF_UPD) == (TIMER_RIF_UPD));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group9 IFM
  * @{
  */
/**
  * @brief  Get timer IFM flag.
  * @param  timx TIMER instance
  * @retval Timer IFM flag.
  */

__STATIC_INLINE uint32_t md_timer_get_ifm(TIMER_TypeDef *timx)
{
    return (READ_REG(timx->IFM));
}

/**
  * @brief  Get timer capture/compare 4 overcapture interrupt flag masked.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_masked_it_ch4ov(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IFM, TIMER_IFM_CH4OV) == (TIMER_IFM_CH4OV));
}

/**
  * @brief  Get timer capture/compare 3 overcapture interrupt flag masked.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_masked_it_ch3ov(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IFM, TIMER_IFM_CH3OV) == (TIMER_IFM_CH3OV));
}

/**
  * @brief  Get timer capture/compare 2 overcapture interrupt flag masked.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_masked_it_ch2ov(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IFM, TIMER_IFM_CH2OV) == (TIMER_IFM_CH2OV));
}

/**
  * @brief  Get timer capture/compare 1 overcapture interrupt flag masked.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_masked_it_ch1ov(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IFM, TIMER_IFM_CH1OV) == (TIMER_IFM_CH1OV));
}

/**
  * @brief  Get timer break interrupt flag masked.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_masked_it_brk(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IFM, TIMER_IFM_BRK) == (TIMER_IFM_BRK));
}

/**
  * @brief  Get timer trigger interrupt flag masked.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_masked_it_trgi(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IFM, TIMER_IFM_TRGI) == (TIMER_IFM_TRGI));
}

/**
  * @brief  Get timer COM interrupt flag masked.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_masked_it_com(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IFM, TIMER_IFM_COM) == (TIMER_IFM_COM));
}

/**
  * @brief  Get timer capture/compare 4 interrupt flag masked.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_masked_it_ch4(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IFM, TIMER_IFM_CH4) == (TIMER_IFM_CH4));
}

/**
  * @brief  Get timer capture/compare 3 interrupt flag masked.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_masked_it_ch3(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IFM, TIMER_IFM_CH3) == (TIMER_IFM_CH3));
}

/**
  * @brief  Get timer capture/compare 2 interrupt flag masked.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_masked_it_ch2(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IFM, TIMER_IFM_CH2) == (TIMER_IFM_CH2));
}

/**
  * @brief  Get timer capture/compare 1 interrupt flag masked.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_masked_it_ch1(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IFM, TIMER_IFM_CH1) == (TIMER_IFM_CH1));
}

/**
  * @brief  Get timer update interrupt flag masked.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_timer_is_masked_it_upd(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->IFM, TIMER_IFM_UPD) == (TIMER_IFM_UPD));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group10 ICR
  * @{
  */
/**
  * @brief  Timer ICR setup.
  * @param  timx TIMER instance
  * @param  value (CH4OV | CH3OV | CH2OV | CH1OV | BRK | TRGI | COM | CH4 | CH3 | CH2 | CH1 | UPD)
  * @retval None
  */

__STATIC_INLINE void md_timer_set_icr(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->ICR, value);
}

/**
  * @brief  Clear timer cpture/compare 4 overcapture interrupt flag.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_clear_it_ch4ov(TIMER_TypeDef *timx)
{
    SET_BIT(timx->ICR, TIMER_ICR_CH4OV);
}

/**
  * @brief  Clear timer cpture/compare 3 overcapture interrupt flag.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_clear_it_ch3ov(TIMER_TypeDef *timx)
{
    SET_BIT(timx->ICR, TIMER_ICR_CH3OV);
}

/**
  * @brief  Clear timer cpture/compare 2 overcapture interrupt flag.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_clear_it_ch2ov(TIMER_TypeDef *timx)
{
    SET_BIT(timx->ICR, TIMER_ICR_CH2OV);
}

/**
  * @brief  Clear timer cpture/compare 1 overcapture interrupt flag.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_clear_it_ch1ov(TIMER_TypeDef *timx)
{
    SET_BIT(timx->ICR, TIMER_ICR_CH1OV);
}

/**
  * @brief  Clear timer break interrupt flag.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_clear_it_brk(TIMER_TypeDef *timx)
{
    SET_BIT(timx->ICR, TIMER_ICR_BRK);
}

/**
  * @brief  Clear timer trigger interrupt flag.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_clear_it_trgi(TIMER_TypeDef *timx)
{
    SET_BIT(timx->ICR, TIMER_ICR_TRGI);
}

/**
  * @brief  Clear timer COM interrupt flag.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_clear_it_com(TIMER_TypeDef *timx)
{
    SET_BIT(timx->ICR, TIMER_ICR_COM);
}

/**
  * @brief  Clear timer capture/compare 4 interrupt flag.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_clear_it_ch4(TIMER_TypeDef *timx)
{
    SET_BIT(timx->ICR, TIMER_ICR_CH4);
}

/**
  * @brief  Clear timer capture/compare 3 interrupt flag.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_clear_it_ch3(TIMER_TypeDef *timx)
{
    SET_BIT(timx->ICR, TIMER_ICR_CH3);
}

/**
  * @brief  Clear timer capture/compare 2 interrupt flag.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_clear_it_ch2(TIMER_TypeDef *timx)
{
    SET_BIT(timx->ICR, TIMER_ICR_CH2);
}

/**
  * @brief  Clear timer capture/compare 1 interrupt flag.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_clear_it_ch1(TIMER_TypeDef *timx)
{
    SET_BIT(timx->ICR, TIMER_ICR_CH1);
}

/**
  * @brief  Clear timer upadte flag.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_clear_it_upd(TIMER_TypeDef *timx)
{
    SET_BIT(timx->ICR, TIMER_ICR_UPD);
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group11 SGE
  * @{
  */
/**
  * @brief  Timer SGE setup.
  * @param  timx TIMER instance
  * @param  value (SGBRK | SGTRGI | SGCOM | SGCH4 | SGCH3 | SGCH2 | SGCH1 | SGUPD)
  * @retval None
  */

__STATIC_INLINE void md_timer_set_sge(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->SGE, value);
}

/**
  * @brief  Timer break generation.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_trigger_sgbrk(TIMER_TypeDef *timx)
{
    SET_BIT(timx->SGE, TIMER_SGE_SGBRK);
}

/**
  * @brief  Timer trigger generation.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_trigger_sgtrgi(TIMER_TypeDef *timx)
{
    SET_BIT(timx->SGE, TIMER_SGE_SGTRGI);
}

/**
  * @brief  Timer COM generation.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_trigger_sgcom(TIMER_TypeDef *timx)
{
    SET_BIT(timx->SGE, TIMER_SGE_SGCOM);
}

/**
  * @brief  Timer Capture/Compare 4 generation.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_trigger_sgch4(TIMER_TypeDef *timx)
{
    SET_BIT(timx->SGE, TIMER_SGE_SGCH4);
}

/**
  * @brief  Timer Capture/Compare 3 generation.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_trigger_sgch3(TIMER_TypeDef *timx)
{
    SET_BIT(timx->SGE, TIMER_SGE_SGCH3);
}

/**
  * @brief  Timer Capture/Compare 2 generation.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_trigger_sgch2(TIMER_TypeDef *timx)
{
    SET_BIT(timx->SGE, TIMER_SGE_SGCH2);
}

/**
  * @brief  Timer Capture/Compare 1 generation.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_trigger_sgch1(TIMER_TypeDef *timx)
{
    SET_BIT(timx->SGE, TIMER_SGE_SGCH1);
}

/**
  * @brief  Timer update generation.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_trigger_sgupd(TIMER_TypeDef *timx)
{
    SET_BIT(timx->SGE, TIMER_SGE_SGUPD);
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group12 CHMR1
  * @{
  */
/**
  * @brief  Timer CHMR1 setup.
  * @param  timx TIMER instance
  * @param  value output (CH2OCLREN | CH2MOD | CH2PEN | CH2FEN | CC2SSEL | CH1OCLREN | CH1MOD | CH1PEN | CH1FEN | CC1SSEL)
  *               input  (I2FLT | I2PRES | CC2SSEL | I1FLT | I1PRES | CC1SSEL)
  * @retval None
  */

__STATIC_INLINE void md_timer_set_chmr1(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->CHMR1, value);
}

/**
  * @brief  GET Timer CHMR1 register value.
  * @param  timx TIMER instance
  * @retval Timer CHMR1 register value.
  */

__STATIC_INLINE uint32_t md_timer_get_chmr1(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->CHMR1));
}

/**
  * @brief  Timer output compare 2 clear enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_output_compare2_clear_ch2oclren(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH2OCLREN);
}

/**
  * @brief  Timer output compare 2 clear disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_output_compare2_clear_ch2oclren(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH2OCLREN);
}

/**
  * @brief  Indicates whether the timer output compare 2 clear is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_output_compare2_clear_ch2oclren(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH2OCLREN) == (TIMER_CHMR1_OUTPUT_CH2OCLREN));
}

/**
  * @brief  Timer output compare 2 mode setup.
  * @param  timx TIMER instance
  * @param  OutputMode Output compare mode
            @arg @ref MD_TIMER_OUTPUTMODE_DISABLE
            @arg @ref MD_TIMER_OUTPUTMODE_HIGHONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_LOWONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_TOGGLE
            @arg @ref MD_TIMER_OUTPUTMODE_FORCELOW
            @arg @ref MD_TIMER_OUTPUTMODE_FORCEHIGH
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE1
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE2
  * @retval None
  */

__STATIC_INLINE void md_timer_set_output_compare2_mode_ch2mod(TIMER_TypeDef *timx, uint32_t OutputMode)
{
    MODIFY_REG(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH2MOD, OutputMode << TIMER_CHMR1_OUTPUT_CH2MOD_POSS);
}

/**
  * @brief  Get timer output compare 2 mode.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_OUTPUTMODE_DISABLE
            @arg @ref MD_TIMER_OUTPUTMODE_HIGHONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_LOWONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_TOGGLE
            @arg @ref MD_TIMER_OUTPUTMODE_FORCELOW
            @arg @ref MD_TIMER_OUTPUTMODE_FORCEHIGH
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE1
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE2
  */

__STATIC_INLINE uint32_t md_timer_get_output_compare2_mode_ch2mod(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH2MOD) >> TIMER_CHMR1_OUTPUT_CH2MOD_POSS);
}

/**
  * @brief  Timer output compare 2 preload enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_output_compare2_preload_ch2pen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH2PEN);
}

/**
  * @brief  Timer output compare 2 preload disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_output_compare2_preload_ch2pen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH2PEN);
}

/**
  * @brief  Indicates whether the timer output compare 2 preload is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_output_compare2_preload_ch2pen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH2PEN) == (TIMER_CHMR1_OUTPUT_CH2PEN));
}

/**
  * @brief  Timer output compare 2 fast enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_output_compare2_fast_ch2fen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH2FEN);
}

/**
  * @brief  Timer output compare 2 fast disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_output_compare2_fast_ch2fen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH2FEN);
}

/**
  * @brief  Indicates whether the timer output compare 2 fast is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_output_compare2_fast_ch2fen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH2FEN) == (TIMER_CHMR1_OUTPUT_CH2FEN));
}

/**
  * @brief  Timer cpture/compare 2 selection setup.
  * @param  timx TIMER instance
  * @param  ChannelMode Channel mode selection
            @arg @ref MD_TIMER_CHMODE_OUTPUT
            @arg @ref MD_TIMER_CHMODE_INPUT_DIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_INDIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_TRC
  * @retval None
  */

__STATIC_INLINE void md_timer_set_cc2_func_cc2ssel(TIMER_TypeDef *timx, uint32_t ChannelMode)
{
    MODIFY_REG(timx->CHMR1, TIMER_CHMR1_OUTPUT_CC2SSEL, (ChannelMode << TIMER_CHMR1_OUTPUT_CC2SSEL_POSS));
}

/**
  * @brief  Get timer cpture/compare 2 selection.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_CHMODE_OUTPUT
            @arg @ref MD_TIMER_CHMODE_INPUT_DIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_INDIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_TRC
  */

__STATIC_INLINE uint32_t md_timer_get_cc2_func_cc2ssel(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CC2SSEL) >> TIMER_CHMR1_OUTPUT_CC2SSEL_POSS);
}


/**
  * @brief  Timer output compare 1 clear enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_output_compare1_clear_ch1oclren(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH1OCLREN);
}

/**
  * @brief  Timer output compare 1 clear disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_output_compare1_clear_ch1oclren(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH1OCLREN);
}

/**
  * @brief  Indicates whether the timer output compare 1 clear is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_output_compare1_clear_ch1oclren(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH1OCLREN) == (TIMER_CHMR1_OUTPUT_CH1OCLREN));
}

/**
  * @brief  Timer output compare 1 mode setup.
  * @param  timx TIMER instance
  * @param  OutputMode Output compare mode
            @arg @ref MD_TIMER_OUTPUTMODE_DISABLE
            @arg @ref MD_TIMER_OUTPUTMODE_HIGHONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_LOWONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_TOGGLE
            @arg @ref MD_TIMER_OUTPUTMODE_FORCELOW
            @arg @ref MD_TIMER_OUTPUTMODE_FORCEHIGH
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE1
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE2
  * @retval None
  */

__STATIC_INLINE void md_timer_set_output_compare1_mode_ch1mod(TIMER_TypeDef *timx, uint32_t OutputMode)
{
    MODIFY_REG(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH1MOD, OutputMode << TIMER_CHMR1_OUTPUT_CH1MOD_POSS);
}

/**
  * @brief  Get timer output compare 1 mode.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_OUTPUTMODE_DISABLE
            @arg @ref MD_TIMER_OUTPUTMODE_HIGHONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_LOWONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_TOGGLE
            @arg @ref MD_TIMER_OUTPUTMODE_FORCELOW
            @arg @ref MD_TIMER_OUTPUTMODE_FORCEHIGH
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE1
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE2
  */

__STATIC_INLINE uint32_t md_timer_get_output_compare1_mode_ch1mod(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH1MOD) >> TIMER_CHMR1_OUTPUT_CH1MOD_POSS);
}

/**
  * @brief  Timer output compare 1 preload enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_output_compare1_preload_ch1pen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH1PEN);
}

/**
  * @brief  Timer output compare 1 preload disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_output_compare1_preload_ch1pen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH1PEN);
}

/**
  * @brief  Indicates whether the timer output compare 1 preload is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_output_compare1_preload_ch1pen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH1PEN) == (TIMER_CHMR1_OUTPUT_CH1PEN));
}

/**
  * @brief  Timer output compare 1 fast enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_output_compare1_fast_ch1fen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH1FEN);
}

/**
  * @brief  Timer output compare 1 fast disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_output_compare1_fast_ch1fen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH1FEN);
}

/**
  * @brief  Indicates whether the timer output compare 1 fast is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_output_compare1_fast_ch1fen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CH1FEN) == (TIMER_CHMR1_OUTPUT_CH1FEN));
}

/**
  * @brief  Timer cpture/compare 1 selection setup.
  * @param  timx TIMER instance
  * @param  ChannelMode Channel mode selection
            @arg @ref MD_TIMER_CHMODE_OUTPUT
            @arg @ref MD_TIMER_CHMODE_INPUT_DIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_INDIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_TRC
  * @retval None
  */

__STATIC_INLINE void md_timer_set_cc1_func_cc1ssel(TIMER_TypeDef *timx, uint32_t sel)
{
    MODIFY_REG(timx->CHMR1, TIMER_CHMR1_OUTPUT_CC1SSEL, sel << TIMER_CHMR1_OUTPUT_CC1SSEL_POSS);
}

/**
  * @brief  Get timer cpture/compare 1 selection.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_CHMODE_OUTPUT
            @arg @ref MD_TIMER_CHMODE_INPUT_DIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_INDIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_TRC
  */

__STATIC_INLINE uint32_t md_timer_get_cc1_func_cc1ssel(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR1, TIMER_CHMR1_OUTPUT_CC1SSEL) >> TIMER_CHMR1_OUTPUT_CC1SSEL_POSS);
}

/**
  * @brief  Timer input capture 2 filter setup.
  * @param  timx TIMER instance
  * @param  InputFliter Input capture filter
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N2
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N4
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N8
  * @retval None
  */

__STATIC_INLINE void md_timer_set_input_capture2_filter_i2flt(TIMER_TypeDef *timx, uint32_t InputFliter)
{
    MODIFY_REG(timx->CHMR1, TIMER_CHMR1_INPUT_I2FLT, InputFliter << TIMER_CHMR1_INPUT_I2FLT_POSS);
}

/**
  * @brief  Get timer input capture 2 filter.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N2
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N4
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N8
  */

__STATIC_INLINE uint32_t md_timer_get_input_capture2_filter_i2flt(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR1, TIMER_CHMR1_INPUT_I2FLT) >> TIMER_CHMR1_INPUT_I2FLT_POSS);
}

/**
  * @brief  Timer input capture 2 prescaler setup.
  * @param  timx TIMER instance
  * @param  InputPrescale Input capture prescaler
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV1
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV2
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV4
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV8
  * @retval None
  */

__STATIC_INLINE void md_timer_set_input_capture2_prescaler_ic2pres(TIMER_TypeDef *timx, uint32_t InputPrescale)
{
    MODIFY_REG(timx->CHMR1, TIMER_CHMR1_INPUT_I2PRES, InputPrescale << TIMER_CHMR1_INPUT_I2PRES_POSS);
}

/**
  * @brief  Get timer input capture 2 prescaler.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV1
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV2
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV4
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV8
  */

__STATIC_INLINE uint32_t md_timer_get_input_capture2_prescaler_ic2pres(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR1, TIMER_CHMR1_INPUT_I2PRES) >> TIMER_CHMR1_INPUT_I2PRES_POSS);
}

/**
  * @brief  Timer input capture 1 filter setup.
  * @param  timx TIMER instance
  * @param  InputFliter Input capture filter
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N2
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N4
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N8
  * @retval None
  */

__STATIC_INLINE void md_timer_set_input_capture1_filter_i1flt(TIMER_TypeDef *timx, uint32_t InputFliter)
{
    MODIFY_REG(timx->CHMR1, TIMER_CHMR1_INPUT_I1FLT, InputFliter << TIMER_CHMR1_INPUT_I1FLT_POSS);
}

/**
  * @brief  Get timer input capture 1 filter.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N2
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N4
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N8
  */

__STATIC_INLINE uint32_t md_timer_get_input_capture1_filter_i1flt(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR1, TIMER_CHMR1_INPUT_I1FLT) >> TIMER_CHMR1_INPUT_I1FLT_POSS);
}

/**
  * @brief  Timer input capture 1 prescaler setup.
  * @param  timx TIMER instance
  * @param  InputPrescale Input capture prescaler
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV1
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV2
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV4
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV8
  * @retval None
  */

__STATIC_INLINE void md_timer_set_input_capture1_prescaler_ic1pres(TIMER_TypeDef *timx, uint32_t InputPrescale)
{
    MODIFY_REG(timx->CHMR1, TIMER_CHMR1_INPUT_I1PRES, InputPrescale << TIMER_CHMR1_INPUT_I1PRES_POSS);
}

/**
  * @brief  Get timer input capture 1 prescaler.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV1
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV2
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV4
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV8
  */

__STATIC_INLINE uint32_t md_timer_get_input_capture1_prescaler_ic1pres(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR1, TIMER_CHMR1_INPUT_I1PRES) >> TIMER_CHMR1_INPUT_I1PRES_POSS);
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group13 CHMR2
  * @{
  */
/**
  * @brief  Timer CHMR2 setup.

  * @param  timx TIMER instance
  * @param  value output (CH4OCLREN | CH4MOD | CH4PEN | CH4FEN | CC4SSEL | CH3OCLREN | CH3MOD | CH3PEN | CH3FEN | CC3SSEL)
  *               input  (I4FLT | I4PRES | CC4SSEL | I3FLT | I3PRES | CC3SSEL)
  * @retval None
  */

__STATIC_INLINE void md_timer_set_chmr2(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->CHMR2, value);
}

/**
  * @brief  GET Timer CHMR2 register value.
  * @param  timx TIMER instance
  * @retval Timer CHMR2 register value.
  */

__STATIC_INLINE uint32_t md_timer_get_chmr2(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->CHMR2));
}

/**
  * @brief  Timer output compare 4 clear enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_output_compare4_clear_ch4oclren(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH4OCLREN);
}

/**
  * @brief  Timer output compare 4 clear disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_output_compare4_clear_ch4oclren(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH4OCLREN);
}

/**
  * @brief  Indicates whether the timer output compare 4 clear is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_output_compare4_clear_ch4oclren(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH4OCLREN) == (TIMER_CHMR2_OUTPUT_CH4OCLREN));
}

/**
  * @brief  Timer output compare 4 mode setup.
  * @param  timx TIMER instance
  * @param  OutputMode Output compare mode
            @arg @ref MD_TIMER_OUTPUTMODE_DISABLE
            @arg @ref MD_TIMER_OUTPUTMODE_HIGHONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_LOWONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_TOGGLE
            @arg @ref MD_TIMER_OUTPUTMODE_FORCELOW
            @arg @ref MD_TIMER_OUTPUTMODE_FORCEHIGH
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE1
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE2
  * @retval None
  */

__STATIC_INLINE void md_timer_set_output_compare4_mode_ch4mod(TIMER_TypeDef *timx, uint32_t OutputMode)
{
    MODIFY_REG(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH4MOD, OutputMode << TIMER_CHMR2_OUTPUT_CH4MOD_POSS);
}

/**
  * @brief  Get timer output compare 4 mode.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_OUTPUTMODE_DISABLE
            @arg @ref MD_TIMER_OUTPUTMODE_HIGHONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_LOWONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_TOGGLE
            @arg @ref MD_TIMER_OUTPUTMODE_FORCELOW
            @arg @ref MD_TIMER_OUTPUTMODE_FORCEHIGH
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE1
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE2
  */

__STATIC_INLINE uint32_t md_timer_get_output_compare4_mode_ch4mod(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH4MOD) >> TIMER_CHMR2_OUTPUT_CH4MOD_POSS);
}

/**
  * @brief  Timer output compare 4 preload enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_output_compare4_preload_ch4pen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH4PEN);
}

/**
  * @brief  Timer output compare 4 preload disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_output_compare4_preload_ch4pen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH4PEN);
}

/**
  * @brief  Indicates whether the timer output compare 4 preload is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_output_compare4_preload_ch4pen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH4PEN) == (TIMER_CHMR2_OUTPUT_CH4PEN));
}

/**
  * @brief  Timer output compare 4 fast enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_output_compare4_fast_ch4fen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH4FEN);
}

/**
  * @brief  Timer output compare 4 fast disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_output_compare4_fast_ch4fen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH4FEN);
}

/**
  * @brief  Indicates whether the timer output compare 4 fast is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_output_compare4_fast_ch4fen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH4FEN) == (TIMER_CHMR2_OUTPUT_CH4FEN));
}

/**
  * @brief  Timer cpture/compare 4 selection setup.
  * @param  timx TIMER instance
  * @param  ChannelMode Channel mode selection
            @arg @ref MD_TIMER_CHMODE_OUTPUT
            @arg @ref MD_TIMER_CHMODE_INPUT_DIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_INDIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_TRC
  * @retval None
  */

__STATIC_INLINE void md_timer_set_cc4_func_cc4ssel(TIMER_TypeDef *timx, uint32_t ChannelMode)
{
    MODIFY_REG(timx->CHMR2, TIMER_CHMR2_OUTPUT_CC4SSEL, (ChannelMode << TIMER_CHMR2_OUTPUT_CC4SSEL_POSS));
}

/**
  * @brief  Get timer cpture/compare 4 selection.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_CHMODE_OUTPUT
            @arg @ref MD_TIMER_CHMODE_INPUT_DIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_INDIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_TRC
  */

__STATIC_INLINE uint32_t md_timer_get_cc4_func_cc4ssel(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CC4SSEL) >> TIMER_CHMR2_OUTPUT_CC4SSEL_POSS);
}

/**
  * @brief  Timer output compare 3 clear enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_output_compare3_clear_ch3oclren(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH3OCLREN);
}

/**
  * @brief  Timer output compare 3 clear disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_output_compare3_clear_ch3oclren(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH3OCLREN);
}

/**
  * @brief  Indicates whether the timer output compare 3 clear is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_output_compare3_clear_ch3oclren(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH3OCLREN) == (TIMER_CHMR2_OUTPUT_CH3OCLREN));
}

/**
  * @brief  Timer output compare 3 mode setup.
  * @param  timx TIMER instance
  * @param  OutputMode Output compare mode
            @arg @ref MD_TIMER_OUTPUTMODE_DISABLE
            @arg @ref MD_TIMER_OUTPUTMODE_HIGHONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_LOWONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_TOGGLE
            @arg @ref MD_TIMER_OUTPUTMODE_FORCELOW
            @arg @ref MD_TIMER_OUTPUTMODE_FORCEHIGH
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE1
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE2
  * @retval None
  */

__STATIC_INLINE void md_timer_set_output_compare3_mode_ch3mod(TIMER_TypeDef *timx, uint32_t OutputMode)
{
    MODIFY_REG(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH3MOD, OutputMode << TIMER_CHMR2_OUTPUT_CH3MOD_POSS);
}

/**
  * @brief  Get timer output compare 3 mode.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_OUTPUTMODE_DISABLE
            @arg @ref MD_TIMER_OUTPUTMODE_HIGHONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_LOWONMSTCH
            @arg @ref MD_TIMER_OUTPUTMODE_TOGGLE
            @arg @ref MD_TIMER_OUTPUTMODE_FORCELOW
            @arg @ref MD_TIMER_OUTPUTMODE_FORCEHIGH
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE1
            @arg @ref MD_TIMER_OUTPUTMODE_PWMMODE2
  */

__STATIC_INLINE uint32_t md_timer_get_output_compare3_mode_ch3mod(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH3MOD) >> TIMER_CHMR2_OUTPUT_CH3MOD_POSS);
}

/**
  * @brief  Timer output compare 3 preload enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_output_compare3_preload_ch3pen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH3PEN);
}

/**
  * @brief  Timer output compare 3 preload disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_output_compare3_preload_ch3pen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH3PEN);
}

/**
  * @brief  Indicates whether the timer output compare 3 preload is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_output_compare3_preload_ch3pen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH3PEN) == (TIMER_CHMR2_OUTPUT_CH3PEN));
}

/**
  * @brief  Timer output compare 3 fast enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_output_compare3_fast_ch3fen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH3FEN);
}

/**
  * @brief  Timer output compare 3 fast disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_output_compare3_fast_ch3fen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH3FEN);
}

/**
  * @brief  Indicates whether the timer output compare 3 fast is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_output_compare3_fast_ch3fen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CH3FEN) == (TIMER_CHMR2_OUTPUT_CH3FEN));
}

/**
  * @brief  Timer cpture/compare 3 selection setup.
  * @param  timx TIMER instance
  * @param  ChannelMode Channel mode selection
            @arg @ref MD_TIMER_CHMODE_OUTPUT
            @arg @ref MD_TIMER_CHMODE_INPUT_DIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_INDIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_TRC
  * @retval None
  */

__STATIC_INLINE void md_timer_set_cc3_func_cc3ssel(TIMER_TypeDef *timx, uint32_t ChannelMode)
{
    MODIFY_REG(timx->CHMR2, TIMER_CHMR2_OUTPUT_CC3SSEL, (ChannelMode << TIMER_CHMR2_OUTPUT_CC3SSEL_POSS));
}

/**
  * @brief  Get timer cpture/compare 3 selection.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_CHMODE_OUTPUT
            @arg @ref MD_TIMER_CHMODE_INPUT_DIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_INDIRECT
            @arg @ref MD_TIMER_CHMODE_INPUT_TRC
  */

__STATIC_INLINE uint32_t md_timer_get_cc3_func_cc3ssel(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR2, TIMER_CHMR2_OUTPUT_CC3SSEL) >> TIMER_CHMR2_OUTPUT_CC3SSEL_POSS);
}

/**
  * @brief  Timer input capture 4 filter setup.
  * @param  timx TIMER instance
  * @param  InputFliter Input capture filter
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N2
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N4
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N8
  * @retval None
  */

__STATIC_INLINE void md_timer_set_input_capture4_filter_i4flt(TIMER_TypeDef *timx, uint32_t InputFliter)
{
    MODIFY_REG(timx->CHMR2, TIMER_CHMR2_INPUT_I4FLT, InputFliter << TIMER_CHMR2_INPUT_I4FLT_POSS);
}

/**
  * @brief  Get timer input capture 4 filter.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N2
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N4
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N8
  */

__STATIC_INLINE uint32_t md_timer_get_input_capture4_filter_i4flt(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR2, TIMER_CHMR2_INPUT_I4FLT) >> TIMER_CHMR2_INPUT_I4FLT_POSS);
}

/**
  * @brief  Timer input capture 4 prescaler setup.
  * @param  timx TIMER instance
  * @param  InputPrescale Input capture prescaler
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV1
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV2
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV4
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV8
  * @retval None
  */

__STATIC_INLINE void md_timer_set_input_capture4_prescaler_ic4pres(TIMER_TypeDef *timx, uint32_t InputPrescale)
{
    MODIFY_REG(timx->CHMR2, TIMER_CHMR2_INPUT_I4PRES, InputPrescale << TIMER_CHMR2_INPUT_I4PRES_POSS);
}

/**
  * @brief  Get timer input capture 4 prescaler.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV1
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV2
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV4
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV8
  */

__STATIC_INLINE uint32_t md_timer_get_input_capture4_prescaler_ic4pres(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR2, TIMER_CHMR2_INPUT_I4PRES) >> TIMER_CHMR2_INPUT_I4PRES_POSS);
}


/**
  * @brief  Timer input capture 3 filter setup.
  * @param  timx TIMER instance
  * @param  InputFliter Input capture filter
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N2
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N4
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N8
  * @retval None
  */

__STATIC_INLINE void md_timer_set_input_capture3_filter_i3flt(TIMER_TypeDef *timx, uint32_t InputFliter)
{
    MODIFY_REG(timx->CHMR2, TIMER_CHMR2_INPUT_I3FLT, InputFliter << TIMER_CHMR2_INPUT_I3FLT_POSS);
}

/**
  * @brief  Get timer input capture 3 filter.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N2
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N4
            @arg @ref MD_TIMER_INPUTFILTER_FDIV1N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV2N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV4N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV8N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV16N8
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N5
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N6
            @arg @ref MD_TIMER_INPUTFILTER_FDIV32N8
  */

__STATIC_INLINE uint32_t md_timer_get_input_capture3_filter_i3flt(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR2, TIMER_CHMR2_INPUT_I3FLT) >> TIMER_CHMR2_INPUT_I3FLT_POSS);
}

/**
  * @brief  Timer input capture 3 prescaler setup.
  * @param  timx TIMER instance
  * @param  InputPrescale Input capture prescaler
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV1
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV2
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV4
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV8
  * @retval None
  */

__STATIC_INLINE void md_timer_set_input_capture3_prescaler_ic3pres(TIMER_TypeDef *timx, uint32_t InputPrescale)
{
    MODIFY_REG(timx->CHMR2, TIMER_CHMR2_INPUT_I3PRES, InputPrescale << TIMER_CHMR2_INPUT_I3PRES_POSS);
}

/**
  * @brief  Get timer input capture 3 prescaler.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV1
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV2
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV4
            @arg @ref MD_TIMER_INPUTPRESCALE_DIV8
  */

__STATIC_INLINE uint32_t md_timer_get_input_capture3_prescaler_ic3pres(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CHMR2, TIMER_CHMR2_INPUT_I3PRES) >> TIMER_CHMR2_INPUT_I3PRES_POSS);
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group14 CCEP
  * @{
  */
/**
  * @brief  Timer CCEP setup.
  * @param  timx TIMER instance
  * @param  value (CC4NPOL | CC4POL | CC4EN | CC3NPOL | CC3NEN | CC3POL | CC3EN | CC2NPOL |
  *                CC2NEN | CC2POL | CC2EN | CC1NPOL | CC1NEN | CC1POL | CC1EN )
  * @retval None
  */

__STATIC_INLINE void md_timer_set_ccep(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->CCEP, value);
}

/**
  * @brief  GET Timer CCEP register value.
  * @param  timx TIMER instance
  * @retval Timer CCEP register value.
  */

__STATIC_INLINE uint32_t md_timer_get_ccep(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->CCEP));
}

/**
  * @brief  Timer capture/compare 4 complementary output polarity setup.
  * @param  timx TIMER instance
  * @param  OutputPolarity Output polarity
            @arg @ref MD_TIMER_OUTPUTPOLARITY_HIGH
            @arg @ref MD_TIMER_OUTPUTPOLARITY_LOW
  * @retval None
  */

__STATIC_INLINE void md_timer_set_cc4_complementary_polarity_cc4npol(TIMER_TypeDef *timx, uint32_t OutputPolarity)
{
    MODIFY_REG(timx->CCEP, TIMER_CCEP_CC4NPOL, (OutputPolarity << TIMER_CCEP_CC4NPOL_POS));
}

/**
  * @brief  Get timer capture/compare 4 complementary output polarity.
  * @param  timx TIMER instance
  * @retval Timer capture/compare 4 complementary output polarity.
  */

__STATIC_INLINE uint32_t md_timer_get_cc4_complementary_polarity_cc4npol(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CCEP, TIMER_CCEP_CC4NPOL));
}

/**
  * @brief  Timer capture/compare 4 output polarity setup.
  * @param  timx TIMER instance
  * @param  OutputPolarity Output polarity
            @arg @ref MD_TIMER_OUTPUTPOLARITY_HIGH
            @arg @ref MD_TIMER_OUTPUTPOLARITY_LOW
  * @retval None
  */

__STATIC_INLINE void md_timer_set_cc4_output_polarity_cc4pol(TIMER_TypeDef *timx, uint32_t OutputPolarity)
{
    MODIFY_REG(timx->CCEP, TIMER_CCEP_CC4POL, (OutputPolarity << TIMER_CCEP_CC4POL_POS));
}

__STATIC_INLINE void md_timer_set_cc4_input_edge_cc4pol(TIMER_TypeDef *timx, uint32_t OutputPolarity)
{
    MODIFY_REG(timx->CCEP, TIMER_CCEP_CC4POL, (OutputPolarity << TIMER_CCEP_CC4POL_POS));
}

/**
  * @brief  Get timer capture/compare 4 output polarity.
  * @param  timx TIMER instance
  * @retval Timer capture/compare 4 output polarity.
  */

__STATIC_INLINE uint32_t md_timer_get_cc4_output_polarity_cc4pol(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CCEP, TIMER_CCEP_CC4POL));
}

__STATIC_INLINE uint32_t md_timer_get_cc4_input_edge_cc4pol(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CCEP, TIMER_CCEP_CC4POL));
}

/**
  * @brief  Timer Capture/Compare 4 output enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_cc4_output_cc4en(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CCEP, TIMER_CCEP_CC4EN);
}

__STATIC_INLINE void md_timer_enable_cc4_input_cc4en(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CCEP, TIMER_CCEP_CC4EN);
}

/**
  * @brief  Timer Capture/Compare 4 output disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_cc4_output_cc4en(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CCEP, TIMER_CCEP_CC4EN);
}

__STATIC_INLINE void md_timer_disable_cc4_input_cc4en(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CCEP, TIMER_CCEP_CC4EN);
}

/**
  * @brief  Indicates whether the timer Capture/Compare 4 output is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_cc4_output_cc4en(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CCEP, TIMER_CCEP_CC4EN) == (TIMER_CCEP_CC4EN));
}

__STATIC_INLINE uint32_t md_timer_is_enabled_cc4_input_cc4en(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CCEP, TIMER_CCEP_CC4EN) == (TIMER_CCEP_CC4EN));
}

/**
  * @brief  Timer capture/compare 3 complementary output polarity setup.
  * @param  timx TIMER instance
  * @param  OutputPolarity Output polarity
            @arg @ref MD_TIMER_OUTPUTPOLARITY_HIGH
            @arg @ref MD_TIMER_OUTPUTPOLARITY_LOW
  * @retval None
  */

__STATIC_INLINE void md_timer_set_cc3_complementary_polarity_cc3npol(TIMER_TypeDef *timx, uint32_t OutputPolarity)
{
    MODIFY_REG(timx->CCEP, TIMER_CCEP_CC3NPOL, OutputPolarity << TIMER_CCEP_CC3NPOL_POS);
}

/**
  * @brief  Get timer capture/compare 3 complementary output polarity.
  * @param  timx TIMER instance
  * @retval Timer capture/compare 3 complementary output polarity.
  */

__STATIC_INLINE uint32_t md_timer_get_cc3_complementary_polarity_cc3npol(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CCEP, TIMER_CCEP_CC3NPOL) >> TIMER_CCEP_CC3NPOL_POS);
}

/**
  * @brief  Timer Capture/Compare 3 complementary output enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_cc3_complementary_cc3nen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CCEP, TIMER_CCEP_CC3NEN);
}

/**
  * @brief  Timer Capture/Compare 3 complementary output disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_cc3_complementary_cc3nen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CCEP, TIMER_CCEP_CC3NEN);
}

/**
  * @brief  Indicates whether the timer Capture/Compare 3 complementary output is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_cc3_complementary_cc3nen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CCEP, TIMER_CCEP_CC3NEN) == (TIMER_CCEP_CC3NEN));
}

/**
  * @brief  Timer capture/compare 3 output polarity setup.
  * @param  timx TIMER instance
  * @param  OutputPolarity Output polarity
            @arg @ref MD_TIMER_OUTPUTPOLARITY_HIGH
            @arg @ref MD_TIMER_OUTPUTPOLARITY_LOW
  * @retval None
  */

__STATIC_INLINE void md_timer_set_cc3_output_polarity_cc3pol(TIMER_TypeDef *timx, uint32_t OutputPolarity)
{
    MODIFY_REG(timx->CCEP, TIMER_CCEP_CC3POL, (OutputPolarity << TIMER_CCEP_CC3POL_POS));
}

__STATIC_INLINE void md_timer_set_cc3_input_edge_cc3pol(TIMER_TypeDef *timx, uint32_t OutputPolarity)
{
    MODIFY_REG(timx->CCEP, TIMER_CCEP_CC3POL, (OutputPolarity << TIMER_CCEP_CC3POL_POS));
}

/**
  * @brief  Get timer capture/compare 3 output polarity.
  * @param  timx TIMER instance
  * @retval Timer capture/compare 3 output polarity.
  */

__STATIC_INLINE uint32_t md_timer_get_cc3_output_polarity_cc3pol(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CCEP, TIMER_CCEP_CC3POL));
}

__STATIC_INLINE uint32_t md_timer_get_cc3_input_edge_cc3pol(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CCEP, TIMER_CCEP_CC3POL));
}

/**
  * @brief  Timer Capture/Compare 3 output enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_cc3_output_cc3en(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CCEP, TIMER_CCEP_CC3EN);
}

__STATIC_INLINE void md_timer_enable_cc3_input_cc3en(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CCEP, TIMER_CCEP_CC3EN);
}

/**
  * @brief  Timer Capture/Compare 3 output disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_cc3_output_cc3en(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CCEP, TIMER_CCEP_CC3EN);
}

__STATIC_INLINE void md_timer_disable_cc3_input_cc3en(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CCEP, TIMER_CCEP_CC3EN);
}

/**
  * @brief  Indicates whether the timer Capture/Compare 3 output is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_cc3_output_cc3en(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CCEP, TIMER_CCEP_CC3EN) == (TIMER_CCEP_CC3EN));
}

__STATIC_INLINE uint32_t md_timer_is_enabled_cc3_input_cc3en(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CCEP, TIMER_CCEP_CC3EN) == (TIMER_CCEP_CC3EN));
}

/**
  * @brief  Timer capture/compare 2 complementary output polarity setup.
  * @param  timx TIMER instance
  * @param  OutputPolarity Output polarity
            @arg @ref MD_TIMER_OUTPUTPOLARITY_HIGH
            @arg @ref MD_TIMER_OUTPUTPOLARITY_LOW
  * @retval None
  */

__STATIC_INLINE void md_timer_set_cc2_complementary_polarity_cc2npol(TIMER_TypeDef *timx, uint32_t OutputPolarity)
{
    MODIFY_REG(timx->CCEP, TIMER_CCEP_CC2NPOL, (OutputPolarity << TIMER_CCEP_CC2NPOL_POS));
}

/**
  * @brief  Get timer capture/compare 2 complementary output polarity.
  * @param  timx TIMER instance
  * @retval Timer capture/compare 2 complementary output polarity.
  */

__STATIC_INLINE uint32_t md_timer_get_cc2_complementary_polarity_cc2npol(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CCEP, TIMER_CCEP_CC2NPOL));
}

/**
  * @brief  Timer Capture/Compare 2 complementary output enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_cc2_complementary_cc2nen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CCEP, TIMER_CCEP_CC2NEN);
}

/**
  * @brief  Timer Capture/Compare 2 complementary output disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_cc2_complementary_cc2nen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CCEP, TIMER_CCEP_CC2NEN);
}

/**
  * @brief  Indicates whether the timer Capture/Compare 2 complementary output is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_cc2_complementary_cc2nen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CCEP, TIMER_CCEP_CC2NEN) == (TIMER_CCEP_CC2NEN));
}

/**
  * @brief  Timer capture/compare 2 output polarity setup.
  * @param  timx TIMER instance
  * @param  OutputPolarity Output polarity
            @arg @ref MD_TIMER_OUTPUTPOLARITY_HIGH
            @arg @ref MD_TIMER_OUTPUTPOLARITY_LOW
  * @retval None
  */

__STATIC_INLINE void md_timer_set_cc2_output_polarity_cc2pol(TIMER_TypeDef *timx, uint32_t OutputPolarity)
{
    MODIFY_REG(timx->CCEP, TIMER_CCEP_CC2POL, (OutputPolarity << TIMER_CCEP_CC2POL_POS));
}

__STATIC_INLINE void md_timer_set_cc2_input_edge_cc2pol(TIMER_TypeDef *timx, uint32_t OutputPolarity)
{
    MODIFY_REG(timx->CCEP, TIMER_CCEP_CC2POL, (OutputPolarity << TIMER_CCEP_CC2POL_POS));
}

/**
  * @brief  Get timer capture/compare 2 output polarity.
  * @param  timx TIMER instance
  * @retval Timer capture/compare 2 output polarity.
  */

__STATIC_INLINE uint32_t md_timer_get_cc2_output_polarity_cc2pol(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CCEP, TIMER_CCEP_CC2POL) >> TIMER_CCEP_CC2POL_POS);
}

__STATIC_INLINE uint32_t md_timer_get_cc2_input_edge_cc2pol(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CCEP, TIMER_CCEP_CC2POL) >> TIMER_CCEP_CC2POL_POS);
}

/**
  * @brief  Timer Capture/Compare 2 output enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_cc2_output_cc2en(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CCEP, TIMER_CCEP_CC2EN);
}

__STATIC_INLINE void md_timer_enable_cc2_input_cc2en(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CCEP, TIMER_CCEP_CC2EN);
}

/**
  * @brief  Timer Capture/Compare 2 output disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_cc2_output_cc2en(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CCEP, TIMER_CCEP_CC2EN);
}

__STATIC_INLINE void md_timer_disable_cc2_input_cc2en(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CCEP, TIMER_CCEP_CC2EN);
}

/**
  * @brief  Indicates whether the timer Capture/Compare 2 output is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_cc2_output_cc2en(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CCEP, TIMER_CCEP_CC2EN) == (TIMER_CCEP_CC2EN));
}

__STATIC_INLINE uint32_t md_timer_is_enabled_cc2_input_cc2en(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CCEP, TIMER_CCEP_CC2EN) == (TIMER_CCEP_CC2EN));
}

/**
  * @brief  Timer capture/compare 1 complementary output polarity setup.
  * @param  timx TIMER instance
  * @param  OutputPolarity Output polarity
            @arg @ref MD_TIMER_OUTPUTPOLARITY_HIGH
            @arg @ref MD_TIMER_OUTPUTPOLARITY_LOW
  * @retval None
  */

__STATIC_INLINE void md_timer_set_cc1_complementary_polarity_cc1npol(TIMER_TypeDef *timx, uint32_t OutputPolarity)
{
    MODIFY_REG(timx->CCEP, TIMER_CCEP_CC1NPOL, (OutputPolarity << TIMER_CCEP_CC1NPOL_POS));
}

/**
  * @brief  Get timer capture/compare 1 complementary output polarity.
  * @param  timx TIMER instance
  * @retval Timer capture/compare 1 complementary output polarity.
  */

__STATIC_INLINE uint32_t md_timer_get_cc1_complementary_polarity_cc1npol(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CCEP, TIMER_CCEP_CC1NPOL));
}

/**
  * @brief  Timer Capture/Compare 1 complementary output enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_cc1_complementary_cc1nen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CCEP, TIMER_CCEP_CC1NEN);
}

/**
  * @brief  Timer Capture/Compare 1 complementary output disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_cc1_complementary_cc1nen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CCEP, TIMER_CCEP_CC1NEN);
}

/**
  * @brief  Indicates whether the timer Capture/Compare 1 complementary output is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_cc1_complementary_cc1nen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CCEP, TIMER_CCEP_CC1NEN) == (TIMER_CCEP_CC1NEN));
}

/**
  * @brief  Timer capture/compare 1 output polarity setup.
  * @param  timx TIMER instance
  * @param  OutputPolarity Output polarity
            @arg @ref MD_TIMER_OUTPUTPOLARITY_HIGH
            @arg @ref MD_TIMER_OUTPUTPOLARITY_LOW
  * @retval None
  */

__STATIC_INLINE void md_timer_set_cc1_output_polarity_cc1pol(TIMER_TypeDef *timx, uint32_t OutputPolarity)
{
    MODIFY_REG(timx->CCEP, TIMER_CCEP_CC1POL, (OutputPolarity << TIMER_CCEP_CC1POL_POS));
}

__STATIC_INLINE void md_timer_set_cc1_input_edge_cc1pol(TIMER_TypeDef *timx, uint32_t OutputPolarity)
{
    MODIFY_REG(timx->CCEP, TIMER_CCEP_CC1POL, (OutputPolarity << TIMER_CCEP_CC1POL_POS));
}

/**
  * @brief  Get timer capture/compare 1 output polarity.
  * @param  timx TIMER instance
  * @retval Timer capture/compare 1 output polarity.
  */

__STATIC_INLINE uint32_t md_timer_get_cc1_output_polarity_cc1pol(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CCEP, TIMER_CCEP_CC1POL));
}

__STATIC_INLINE uint32_t md_timer_get_cc1_input_edge_cc1pol(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->CCEP, TIMER_CCEP_CC1POL));
}

/**
  * @brief  Timer Capture/Compare 1 output enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_cc1_output_cc1en(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CCEP, TIMER_CCEP_CC1EN);
}

__STATIC_INLINE void md_timer_enable_cc1_input_cc1en(TIMER_TypeDef *timx)
{
    SET_BIT(timx->CCEP, TIMER_CCEP_CC1EN);
}

/**
  * @brief  Timer Capture/Compare 1 output disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_cc1_output_cc1en(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CCEP, TIMER_CCEP_CC1EN);
}

__STATIC_INLINE void md_timer_disable_cc1_input_cc1en(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->CCEP, TIMER_CCEP_CC1EN);
}

/**
  * @brief  Indicates whether the timer Capture/Compare 1 output is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_cc1_output_cc1en(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CCEP, TIMER_CCEP_CC1EN) == (TIMER_CCEP_CC1EN));
}

__STATIC_INLINE uint32_t md_timer_is_enabled_cc1_input_cc1en(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->CCEP, TIMER_CCEP_CC1EN) == (TIMER_CCEP_CC1EN));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group15 COUNT
  * @{
  */
/**
  * @brief  Timer COUNT setup.
  * @param  timx TIMER instance
  * @param  value COUNT
  * @retval None
  */

__STATIC_INLINE void md_timer_set_counter_value_cntv(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->COUNT, value);
}

/**
  * @brief  GET Timer COUNT register value.
  * @param  timx TIMER instance
  * @retval Timer COUNT register value.
  */

__STATIC_INLINE uint32_t md_timer_get_counter_value_cntv(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->COUNT));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group16 PRES
  * @{
  */
/**
  * @brief  Timer PRES setup.
  * @param  timx TIMER instance
  * @param  value PRES
  * @retval None
  */

__STATIC_INLINE void md_timer_set_prescaler_value_pscv(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->PRES, value);
}

/**
  * @brief  GET Timer PRES register value.
  * @param  timx TIMER instance
  * @retval Timer PRES register value.
  */

__STATIC_INLINE uint32_t md_timer_get_prescaler_value_pscv(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->PRES));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group17 AR
  * @{
  */
/**
  * @brief  Timer AR setup.
  * @param  timx TIMER instance
  * @param  value AR
  * @retval None
  */

__STATIC_INLINE void md_timer_set_auto_reload_value_arrv(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->AR, value);
}

/**
  * @brief  GET Timer AR register value.
  * @param  timx TIMER instance
  * @retval Timer AR register value.
  */

__STATIC_INLINE uint32_t md_timer_get_auto_reload_value_arrv(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->AR));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group18 REPAR
  * @{
  */
/**
  * @brief  Timer REPAR setup.
  * @param  timx TIMER instance
  * @param  value REPAR
  * @retval None
  */

__STATIC_INLINE void md_timer_set_repetition_counter_value_repv(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->REPAR, value);
}

/**
  * @brief  GET Timer REPAR register value.
  * @param  timx TIMER instance
  * @retval Timer REPAR register value.
  */

__STATIC_INLINE uint32_t md_timer_get_repetition_counter_value_repv(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->REPAR));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group19 CCVAL1
  * @{
  */
/**
  * @brief  Timer CCVAL1 setup.
  * @param  timx TIMER instance
  * @param  value CCVAL1
  * @retval None
  */

__STATIC_INLINE void md_timer_set_capture_compare1_value_ccrv1(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->CCVAL1, value);
}

/**
  * @brief  GET Timer CCVAL1 register value.
  * @param  timx TIMER instance
  * @retval Timer CCVAL1 register value.
  */

__STATIC_INLINE uint32_t md_timer_get_capture_compare1_value_ccrv1(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->CCVAL1));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group20 CCVAL2
  * @{
  */
/**
  * @brief  Timer CCVAL2 setup.
  * @param  timx TIMER instance
  * @param  value CCVAL2
  * @retval None
  */

__STATIC_INLINE void md_timer_set_capture_compare2_value_ccrv2(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->CCVAL2, value);
}

/**
  * @brief  GET Timer CCVAL2 register value.
  * @param  timx TIMER instance
  * @retval Timer CCVAL2 register value.
  */

__STATIC_INLINE uint32_t md_timer_get_capture_compare2_value_ccrv2(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->CCVAL2));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group21 CCVAL3
  * @{
  */
/**
  * @brief  Timer CCVAL3 setup.
  * @param  timx TIMER instance
  * @param  value CCVAL3
  * @retval None
  */

__STATIC_INLINE void md_timer_set_capture_compare3_value_ccrv3(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->CCVAL3, value);
}

/**
  * @brief  GET Timer CCVAL3 register value.
  * @param  timx TIMER instance
  * @retval Timer CCVAL3 register value.
  */

__STATIC_INLINE uint32_t md_timer_get_capture_compare3_value_ccrv3(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->CCVAL3));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group22 CCVAL4
  * @{
  */
/**
  * @brief  Timer CCVAL4 setup.
  * @param  timx TIMER instance
  * @param  value CCVAL4
  * @retval None
  */

__STATIC_INLINE void md_timer_set_capture_compare4_value_ccrv4(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->CCVAL4, value);
}

/**
  * @brief  GET Timer CCVAL4 register value.
  * @param  timx TIMER instance
  * @retval Timer CCVAL4 register value.
  */

__STATIC_INLINE uint32_t md_timer_get_capture_compare4_value_ccrv4(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->CCVAL4));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group23 BDCFG
  * @{
  */
/**
  * @brief  Timer BDCFG setup.
  * @param  timx TIMER instance
  * @param  value (GOEN | AOEN | BRKP | BRKEN | OFFSSR | OFFSSI | LOCKLVL | DT)
  * @retval None
  */

__STATIC_INLINE void md_timer_set_bdcfg(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->BDCFG, value);
}

/**
  * @brief  GET Timer BDCFG register value.
  * @param  timx TIMER instance
  * @retval Timer BDCFG register value.
  */

__STATIC_INLINE uint32_t md_timer_get_bdcfg(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->BDCFG));
}

/**
  * @brief  Timer main output enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_main_output_goen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->BDCFG, TIMER_BDCFG_GOEN);
}

/**
  * @brief  Timer main output disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_main_output_goen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->BDCFG, TIMER_BDCFG_GOEN);
}

/**
  * @brief  Indicates whether the timer main output is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_main_output_goen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->BDCFG, TIMER_BDCFG_GOEN) == (TIMER_BDCFG_GOEN));
}

/**
  * @brief  Timer automatic output enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_auto_output_aoen(TIMER_TypeDef *timx)
{
    SET_BIT(timx->BDCFG, TIMER_BDCFG_AOEN);
}

/**
  * @brief  Timer automatic output disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_auto_output_aoen(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->BDCFG, TIMER_BDCFG_AOEN);
}

/**
  * @brief  Indicates whether the timer automatic output is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_auto_output_aoen(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->BDCFG, TIMER_BDCFG_AOEN) == (TIMER_BDCFG_AOEN));
}

/**
  * @brief  Timer break polarity setup.
  * @param  timx TIMER instance
  * @param  BreakPolarity Break polarity
  *         @arg @ref MD_TIMER_BREAKPOLARITY_LOW
  *         @arg @ref MD_TIMER_BREAKPOLARITY_HIGH
  * @retval None
  */

__STATIC_INLINE void md_timer_set_break_polarity_brkp(TIMER_TypeDef *timx, uint32_t BreakPolarity)
{
    MODIFY_REG(timx->BDCFG, TIMER_BDCFG_BRKP, BreakPolarity << TIMER_BDCFG_BRKP_POS);
}

/**
  * @brief  Get timer break polarity.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_TIMER_BREAKPOLARITY_LOW
  *         @arg @ref MD_TIMER_BREAKPOLARITY_HIGH
  */

__STATIC_INLINE uint32_t md_timer_get_break_polarity_brkp(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->BDCFG, TIMER_BDCFG_BRKP) >> TIMER_BDCFG_BRKP_POS);
}

/**
  * @brief  Timer break enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_break_brken(TIMER_TypeDef *timx)
{
    SET_BIT(timx->BDCFG, TIMER_BDCFG_BRKEN);
}

/**
  * @brief  Timer break disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_break_brken(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->BDCFG, TIMER_BDCFG_BRKEN);
}

/**
  * @brief  Indicates whether the timer break is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_break_brken(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->BDCFG, TIMER_BDCFG_BRKEN) == (TIMER_BDCFG_BRKEN));
}

/**
  * @brief  Timer off-state selection for run mode setup.
  * @param  timx TIMER instance
  * @param  OffStateRun Off-state selection for run mode
  *         @arg @ref MD_TIMER_OFFSTATERUN_DISABLE
  *         @arg @ref MD_TIMER_OFFSTATERUN_ENABLE
  * @retval None
  */

__STATIC_INLINE void md_timer_set_offstate_run_selection_offssr(TIMER_TypeDef *timx, uint32_t OffStateRun)
{
    MODIFY_REG(timx->BDCFG, TIMER_BDCFG_OFFSSR, OffStateRun << TIMER_BDCFG_OFFSSR_POS);
}

/**
  * @brief  Get timer off-state selection for run mode.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_TIMER_OFFSTATERUN_DISABLE
  *         @arg @ref MD_TIMER_OFFSTATERUN_ENABLE
  */

__STATIC_INLINE uint32_t md_timer_get_offstate_run_selection_offssr(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->BDCFG, TIMER_BDCFG_OFFSSR) >> TIMER_BDCFG_OFFSSR_POS);
}

/**
  * @brief  Timer off-state selection for idle mode setup.
  * @param  timx TIMER instance
  * @param  OffStateIdle Off-state selection for idle mode
  *         @arg @ref MD_TIMER_OFFSTATEIDLE_DISABLE
  *         @arg @ref MD_TIMER_OFFSTATEIDLE_ENABLE
  * @retval None
  */

__STATIC_INLINE void md_timer_set_offstate_idle_selection_offssi(TIMER_TypeDef *timx, uint32_t OffStateIdle)
{
    MODIFY_REG(timx->BDCFG, TIMER_BDCFG_OFFSSI, OffStateIdle << TIMER_BDCFG_OFFSSI_POS);
}

/**
  * @brief  Get timer off-state selection for idle mode.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_TIMER_OFFSTATEIDLE_DISABLE
  *         @arg @ref MD_TIMER_OFFSTATEIDLE_ENABLE
  */

__STATIC_INLINE uint32_t md_timer_get_offstate_idle_selection_offssi(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->BDCFG, TIMER_BDCFG_OFFSSI) >> TIMER_BDCFG_OFFSSI_POS);
}

/**
  * @brief  Timer lock configuration setup.
  * @param  timx TIMER instance
  * @param  LockLevel Lock configuration
  *         @arg @ref MD_TIMER_LOCKLEVEL_0
  *         @arg @ref MD_TIMER_LOCKLEVEL_1
  *         @arg @ref MD_TIMER_LOCKLEVEL_2
  *         @arg @ref MD_TIMER_LOCKLEVEL_3
  * @retval None
  */

__STATIC_INLINE void md_timer_set_lock_config_locklvl(TIMER_TypeDef *timx, uint32_t LockLevel)
{
    MODIFY_REG(timx->BDCFG, TIMER_BDCFG_LOCKLVL, LockLevel << TIMER_BDCFG_LOCKLVL_POSS);
}

/**
  * @brief  Get timer lock configuration.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_TIMER_LOCKLEVEL_0
  *         @arg @ref MD_TIMER_LOCKLEVEL_1
  *         @arg @ref MD_TIMER_LOCKLEVEL_2
  *         @arg @ref MD_TIMER_LOCKLEVEL_3
  */

__STATIC_INLINE uint32_t md_timer_get_lock_config_locklvl(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->BDCFG, TIMER_BDCFG_LOCKLVL) >> TIMER_BDCFG_LOCKLVL_POSS);
}

/**
  * @brief  Timer dead-time generator setup.
  * @param  timx TIMER instance
  * @param  DeadTime Dead-time generator (between Min_Data=0 and Max_Data=0xFF)
  * @retval None
  */

__STATIC_INLINE void md_timer_set_dead_time_duration_dt(TIMER_TypeDef *timx, uint32_t DeadTime)
{
    MODIFY_REG(timx->BDCFG, TIMER_BDCFG_DT, DeadTime);
}

/**
  * @brief  Get timer dead-time generator.
  * @param  timx TIMER instance
  * @retval Timer dead-time generator.
  */

__STATIC_INLINE uint32_t md_timer_get_dead_time_duration_dt(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->BDCFG, TIMER_BDCFG_DT));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group24 DMAEN
  * @{
  */
/**
  * @brief  Timer DMAEN setup.
  * @param  timx TIMER instance
  * @param  value (TRGI | COM | CH4 | CH3 | CH2 | CH1 | UPD)
  * @retval None
  */

__STATIC_INLINE void md_timer_set_dmaen(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->DMAEN, value);
}

/**
  * @brief  GET Timer DMAEN register value.
  * @param  timx TIMER instance
  * @retval Timer DMAEN register value.
  */

__STATIC_INLINE uint32_t md_timer_get_dmaen(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->DMAEN));
}

/**
  * @brief  Timer trigger DMA request enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_dma_trgi(TIMER_TypeDef *timx)
{
    SET_BIT(timx->DMAEN, TIMER_DMAEN_TRGI);
}

/**
  * @brief  Timer trigger DMA request disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_dma_trgi(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->DMAEN, TIMER_DMAEN_TRGI);
}

/**
  * @brief  Indicates whether the timer trigger DMA request is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_dma_trgi(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->DMAEN, TIMER_DMAEN_TRGI) == (TIMER_DMAEN_TRGI));
}

/**
  * @brief  Timer COM DMA request enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_dma_com(TIMER_TypeDef *timx)
{
    SET_BIT(timx->DMAEN, TIMER_DMAEN_COM);
}

/**
  * @brief  Timer COM DMA request disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_dma_com(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->DMAEN, TIMER_DMAEN_COM);
}

/**
  * @brief  Indicates whether the timer trigger COM request is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_dma_com(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->DMAEN, TIMER_DMAEN_COM) == (TIMER_DMAEN_COM));
}

/**
  * @brief  Timer Capture/Compare 4 DMA request enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_dma_ch4(TIMER_TypeDef *timx)
{
    SET_BIT(timx->DMAEN, TIMER_DMAEN_CH4);
}

/**
  * @brief  Timer Capture/Compare 4 DMA request disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_dma_ch4(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->DMAEN, TIMER_DMAEN_CH4);
}

/**
  * @brief  Indicates whether the timer Capture/Compare 4 DMA request is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_dma_ch4(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->DMAEN, TIMER_DMAEN_CH4) == (TIMER_DMAEN_CH4));
}

/**
  * @brief  Timer Capture/Compare 3 DMA request enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_dma_ch3(TIMER_TypeDef *timx)
{
    SET_BIT(timx->DMAEN, TIMER_DMAEN_CH3);
}

/**
  * @brief  Timer Capture/Compare 3 DMA request disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_dma_ch3(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->DMAEN, TIMER_DMAEN_CH3);
}

/**
  * @brief  Indicates whether the timer Capture/Compare 3 DMA request is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_dma_ch3(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->DMAEN, TIMER_DMAEN_CH3) == (TIMER_DMAEN_CH3));
}

/**
  * @brief  Timer Capture/Compare 2 DMA request enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_dma_ch2(TIMER_TypeDef *timx)
{
    SET_BIT(timx->DMAEN, TIMER_DMAEN_CH2);
}

/**
  * @brief  Timer Capture/Compare 2 DMA request disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_dma_ch2(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->DMAEN, TIMER_DMAEN_CH2);
}

/**
  * @brief  Indicates whether the timer Capture/Compare 2 DMA request is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_dma_ch2(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->DMAEN, TIMER_DMAEN_CH2) == (TIMER_DMAEN_CH2));
}

/**
  * @brief  Timer Capture/Compare 1 DMA request enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_dma_ch1(TIMER_TypeDef *timx)
{
    SET_BIT(timx->DMAEN, TIMER_DMAEN_CH1);
}

/**
  * @brief  Timer Capture/Compare 1 DMA request disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_dma_ch1(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->DMAEN, TIMER_DMAEN_CH1);
}

/**
  * @brief  Indicates whether the timer Capture/Compare 1 DMA request is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_dma_ch1(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->DMAEN, TIMER_DMAEN_CH1) == (TIMER_DMAEN_CH1));
}

/**
  * @brief  Timer update DMA request enable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_enable_dma_upd(TIMER_TypeDef *timx)
{
    SET_BIT(timx->DMAEN, TIMER_DMAEN_UPD);
}

/**
  * @brief  Timer update DMA request disable.
  * @param  timx TIMER instance
  * @retval None
  */

__STATIC_INLINE void md_timer_disable_dma_upd(TIMER_TypeDef *timx)
{
    CLEAR_BIT(timx->DMAEN, TIMER_DMAEN_UPD);
}

/**
  * @brief  Indicates whether the timer Capture/Compare update DMA request is enabled.
  * @param  timx TIMER instance
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_timer_is_enabled_dma_upd(TIMER_TypeDef *timx)
{
    return (READ_BIT(timx->DMAEN, TIMER_DMAEN_UPD) == (TIMER_DMAEN_UPD));
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group25 OPTR
  * @{
  */
/**
  * @brief  Timer OPTR setup.
  * @param  timx TIMER instance
  * @param  value (ETR_RMP | CH4_RMP | CH3_RMP | CH2_RMP | CH1_RMP)
  * @retval None
  */

__STATIC_INLINE void md_timer_set_optr(TIMER_TypeDef *timx, uint32_t value)
{
    WRITE_REG(timx->OPTR, value);
}

/**
  * @brief  GET Timer OPTR register value.
  * @param  timx TIMER instance
  * @retval Timer OPTR register value.
  */

__STATIC_INLINE uint32_t md_timer_get_optr(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_REG(timx->OPTR));
}

/**
  * @brief  Timer ETR input remap setup.
  * @param  timx TIMER instance
  * @param  ETRInputSel ETR input selection
            @arg @ref MD_TIMER_ETRRMP_ETR
            @arg @ref MD_TIMER_ETRRMP_CMP1
            @arg @ref MD_TIMER_ETRRMP_CMP2
            @arg @ref MD_TIMER_ETRRMP_ADCAWD
  * @retval None
  */

__STATIC_INLINE void md_timer_set_external_trigger_select(TIMER_TypeDef *timx, uint32_t ETRInputSel)
{
    MODIFY_REG(timx->OPTR, TIMER_OPTR_ETR_RMP, ETRInputSel << TIMER_OPTR_ETR_RMP_POSS);
}

/**
  * @brief  Get timer ETR input remap.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_ETRRMP_ETR
            @arg @ref MD_TIMER_ETRRMP_CMP1
            @arg @ref MD_TIMER_ETRRMP_CMP2
            @arg @ref MD_TIMER_ETRRMP_ADCAWD
  */

__STATIC_INLINE uint32_t md_timer_get_external_trigger_select(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->OPTR, TIMER_OPTR_ETR_RMP) >> TIMER_OPTR_ETR_RMP_POSS);
}

/**
  * @brief  Timer channel 4 input remap setup.
  * @param  timx TIMER instance
  * @param  CH4InputSel channel 4 input selection
            @arg @ref MD_TIMER_CH4RMP_CH4
  * @retval None
  */

__STATIC_INLINE void md_timer_set_input_capture4_select(TIMER_TypeDef *timx, uint32_t CH4InputSel)
{
    MODIFY_REG(timx->OPTR, TIMER_OPTR_CH4_RMP, CH4InputSel << TIMER_OPTR_CH4_RMP_POSS);
}

/**
  * @brief  Get timer channel 4 input remap.
  * @param  timx TIMER instance
  * @retval timer channel 4 input remap.
  */

__STATIC_INLINE uint32_t md_timer_get_input_capture4_select(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->OPTR, TIMER_OPTR_CH4_RMP) >> TIMER_OPTR_CH4_RMP_POSS);
}

/**
  * @brief  Timer channel 3 input remap setup.
  * @param  timx TIMER instance
  * @param  CH3InputSel channel 3 input selection
            @arg @ref MD_TIMER_CH3RMP_CH3
  * @retval None
  */

__STATIC_INLINE void md_timer_set_input_capture3_select(TIMER_TypeDef *timx, uint32_t CH3InputSel)
{
    MODIFY_REG(timx->OPTR, TIMER_OPTR_CH3_RMP, CH3InputSel << TIMER_OPTR_CH3_RMP_POSS);
}

/**
  * @brief  Get timer channel 3 input remap.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_CH3RMP_CH3
*/

__STATIC_INLINE uint32_t md_timer_get_input_capture3_select(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->OPTR, TIMER_OPTR_CH3_RMP) >> TIMER_OPTR_CH3_RMP_POSS);
}

/**
  * @brief  Timer channel 2 input remap setup.
  * @param  timx TIMER instance
  * @param  CH2InputSel channel 2 input selection
            @arg @ref MD_TIMER_CH2RMP_CH2
            @arg @ref MD_TIMER_CH2RMP_CMP2
  * @retval None
  */

__STATIC_INLINE void md_timer_set_input_capture2_select(TIMER_TypeDef *timx, uint32_t CH2InputSel)
{
    MODIFY_REG(timx->OPTR, TIMER_OPTR_CH2_RMP, CH2InputSel << TIMER_OPTR_CH2_RMP_POSS);
}

/**
  * @brief  Get timer channel 2 input remap.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_CH2RMP_CH2
            @arg @ref MD_TIMER_CH2RMP_CMP2
  */

__STATIC_INLINE uint32_t md_timer_get_input_capture2_select(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->OPTR, TIMER_OPTR_CH2_RMP) >> TIMER_OPTR_CH2_RMP_POSS);
}

/**
  * @brief  Timer channel 1 input remap setup.
  * @param  timx TIMER instance
  * @param  CH1InputSel channel 1 input selection
            @arg @ref MD_TIMER_CH1RMP_CH1
            @arg @ref MD_TIMER_CH1RMP_CMP1
  * @retval None
  */

__STATIC_INLINE void md_timer_set_input_capture1_select(TIMER_TypeDef *timx, uint32_t CH1InputSel)
{
    MODIFY_REG(timx->OPTR, TIMER_OPTR_CH1_RMP, CH1InputSel << TIMER_OPTR_CH1_RMP_POSS);
}

/**
  * @brief  Get timer channel 1 input remap.
  * @param  timx TIMER instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_TIMER_CH1RMP_CH1
            @arg @ref MD_TIMER_CH1RMP_CMP1
  */

__STATIC_INLINE uint32_t md_timer_get_input_capture1_select(TIMER_TypeDef *timx)
{
    return (uint32_t)(READ_BIT(timx->OPTR, TIMER_OPTR_CH1_RMP) >> TIMER_OPTR_CH1_RMP_POSS);
}
/**
  * @}
  */

/** @defgroup MD_TIMER_Public_Functions_Group26 LL
  * @{
  */

/**
  * @brief  Enable capture/compare channels.
  * @rmtoll CCEP         CC1EN          LL_TIMER_CC_EnableChannel\n
  *         CCEP         CC1NEN         LL_TIMER_CC_EnableChannel\n
  *         CCEP         CC2EN          LL_TIMER_CC_EnableChannel\n
  *         CCEP         CC2NEN         LL_TIMER_CC_EnableChannel\n
  *         CCEP         CC3EN          LL_TIMER_CC_EnableChannel\n
  *         CCEP         CC3NEN         LL_TIMER_CC_EnableChannel\n
  *         CCEP         CC4EN          LL_TIMER_CC_EnableChannel\n
  *         CCEP         CC4NE         LL_TIMER_CC_EnableChannel\n
  * @param  timx Timer instance
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH1N
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH2N
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH3N
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_CC_EnableChannel(TIMER_TypeDef *timx, uint32_t Channels)
{
    SET_BIT(timx->CCEP, Channels);
}

/**
  * @brief  Disable capture/compare channels.
  * @rmtoll CCEP         CC1EN          LL_TIMER_CC_DisableChannel\n
  *         CCEP         CC1NEN         LL_TIMER_CC_DisableChannel\n
  *         CCEP         CC2EN          LL_TIMER_CC_DisableChannel\n
  *         CCEP         CC2NEN         LL_TIMER_CC_DisableChannel\n
  *         CCEP         CC3EN          LL_TIMER_CC_DisableChannel\n
  *         CCEP         CC3NEN         LL_TIMER_CC_DisableChannel\n
  *         CCEP         CC4EN          LL_TIMER_CC_DisableChannel\n
  * @param  timx Timer instance
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH1N
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH2N
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH3N
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_CC_DisableChannel(TIMER_TypeDef *timx, uint32_t Channels)
{
    CLEAR_BIT(timx->CCEP, Channels);
}

/**
  * @brief  Indicate whether channel(s) is(are) enabled.
  * @rmtoll CCEP         CC1EN          LL_TIMER_CC_IsEnabledChannel\n
  *         CCEP         CC1NEN         LL_TIMER_CC_IsEnabledChannel\n
  *         CCEP         CC2EN          LL_TIMER_CC_IsEnabledChannel\n
  *         CCEP         CC2NEN         LL_TIMER_CC_IsEnabledChannel\n
  *         CCEP         CC3EN          LL_TIMER_CC_IsEnabledChannel\n
  *         CCEP         CC3NEN         LL_TIMER_CC_IsEnabledChannel\n
  *         CCEP         CC4EN          LL_TIMER_CC_IsEnabledChannel\n
  * @param  timx Timer instance
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH1N
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH2N
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH3N
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_TIMER_CC_IsEnabledChannel(TIMER_TypeDef *timx, uint32_t Channels)
{
    return ((READ_BIT(timx->CCEP, Channels) == (Channels)) ? 1UL : 0UL);
}


/**
  * @brief  Configure an output channel.
  * @rmtoll CHMR1        CC1SSEL          LL_TIMER_OC_ConfigOutput\n
  *         CHMR1        CC2SSEL          LL_TIMER_OC_ConfigOutput\n
  *         CHMR2        CC3SSEL          LL_TIMER_OC_ConfigOutput\n
  *         CHMR2        CC4SSEL          LL_TIMER_OC_ConfigOutput\n
  *         CCEP         CC1POL          LL_TIMER_OC_ConfigOutput\n
  *         CCEP         CC2POL          LL_TIMER_OC_ConfigOutput\n
  *         CCEP         CC3POL          LL_TIMER_OC_ConfigOutput\n
  *         CCEP         CC4POL          LL_TIMER_OC_ConfigOutput\n
  *         CON2          OISS1          LL_TIMER_OC_ConfigOutput\n
  *         CON2          OISS2          LL_TIMER_OC_ConfigOutput\n
  *         CON2          OISS3          LL_TIMER_OC_ConfigOutput\n
  *         CON2          OISS4          LL_TIMER_OC_ConfigOutput\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @param  Configuration This parameter must be a combination of all the following values:
  *         @arg @ref LL_TIMER_OCPOLARITY_HIGH or @ref LL_TIMER_OCPOLARITY_LOW
  *         @arg @ref LL_TIMER_OCIDLESTATE_LOW or @ref LL_TIMER_OCIDLESTATE_HIGH
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_OC_ConfigOutput(TIMER_TypeDef *timx, uint32_t Channel, uint32_t Configuration)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);

    __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));

    CLEAR_BIT(*pReg, (TIMER_CHMR1_OUTPUT_CC1SSEL << SHIFT_TAB_OCxx[iChannel]));

    MODIFY_REG(timx->CCEP, (TIMER_CCEP_CC1POL << SHIFT_TAB_CCxP[iChannel]), (Configuration & TIMER_CCEP_CC1POL) << SHIFT_TAB_CCxP[iChannel]);

    MODIFY_REG(timx->CON2, (TIMER_CON2_OISS1 << SHIFT_TAB_OISx[iChannel]), (Configuration & TIMER_CON2_OISS1) << SHIFT_TAB_OISx[iChannel]);
}

/**
  * @brief  Define the behavior of the output reference signal OCxREF from which
  *         OCx and OCxN (when relevant) are derived.
  * @rmtoll CHMR1        CH1MOD          LL_TIMER_OC_SetMode\n
  *         CHMR1        CH2MOD          LL_TIMER_OC_SetMode\n
  *         CHMR2        CH3MOD          LL_TIMER_OC_SetMode\n
  *         CHMR2        CH4MOD          LL_TIMER_OC_SetMode\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_OCMODE_FROZEN
  *         @arg @ref LL_TIMER_OCMODE_ACTIVE
  *         @arg @ref LL_TIMER_OCMODE_INACTIVE
  *         @arg @ref LL_TIMER_OCMODE_TOGGLE
  *         @arg @ref LL_TIMER_OCMODE_FORCED_INACTIVE
  *         @arg @ref LL_TIMER_OCMODE_FORCED_ACTIVE
  *         @arg @ref LL_TIMER_OCMODE_PWM1
  *         @arg @ref LL_TIMER_OCMODE_PWM2
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_OC_SetMode(TIMER_TypeDef *timx, uint32_t Channel, uint32_t Mode)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    MODIFY_REG(*pReg, ((TIMER_CHMR1_OUTPUT_CH1MOD  | TIMER_CHMR1_OUTPUT_CC1SSEL) << SHIFT_TAB_OCxx[iChannel]),  Mode << SHIFT_TAB_OCxx[iChannel]);
}

/**
  * @brief  Get the output compare mode of an output channel.
  * @rmtoll CHMR1        CH1MOD          LL_TIMER_OC_GetMode\n
  *         CHMR1        CH2MOD          LL_TIMER_OC_GetMode\n
  *         CHMR2        CH3MOD          LL_TIMER_OC_GetMode\n
  *         CHMR2        CH4MOD          LL_TIMER_OC_GetMode\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_TIMER_OCMODE_FROZEN
  *         @arg @ref LL_TIMER_OCMODE_ACTIVE
  *         @arg @ref LL_TIMER_OCMODE_INACTIVE
  *         @arg @ref LL_TIMER_OCMODE_TOGGLE
  *         @arg @ref LL_TIMER_OCMODE_FORCED_INACTIVE
  *         @arg @ref LL_TIMER_OCMODE_FORCED_ACTIVE
  *         @arg @ref LL_TIMER_OCMODE_PWM1
  *         @arg @ref LL_TIMER_OCMODE_PWM2
  */
__STATIC_INLINE uint32_t LL_TIMER_OC_GetMode(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    const __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    return (READ_BIT(*pReg, ((TIMER_CHMR1_OUTPUT_CH1MOD  | TIMER_CHMR1_OUTPUT_CC1SSEL) << SHIFT_TAB_OCxx[iChannel])) >> SHIFT_TAB_OCxx[iChannel]);
}

/**
  * @brief  Set the polarity of an output channel.
  * @rmtoll CCEP         CC1POL          LL_TIMER_OC_SetPolarity\n
  *         CCEP         CC1NPOL         LL_TIMER_OC_SetPolarity\n
  *         CCEP         CC2POL          LL_TIMER_OC_SetPolarity\n
  *         CCEP         CC2NPOL         LL_TIMER_OC_SetPolarity\n
  *         CCEP         CC3POL          LL_TIMER_OC_SetPolarity\n
  *         CCEP         CC3NPOL         LL_TIMER_OC_SetPolarity\n
  *         CCEP         CC4POL          LL_TIMER_OC_SetPolarity\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH1N
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH2N
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH3N
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @param  Polarity This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_OCPOLARITY_HIGH
  *         @arg @ref LL_TIMER_OCPOLARITY_LOW
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_OC_SetPolarity(TIMER_TypeDef *timx, uint32_t Channel, uint32_t Polarity)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    MODIFY_REG(timx->CCEP, (TIMER_CCEP_CC1POL << SHIFT_TAB_CCxP[iChannel]),  Polarity << SHIFT_TAB_CCxP[iChannel]);
}

/**
  * @brief  Get the polarity of an output channel.
  * @rmtoll CCEP         CC1POL          LL_TIMER_OC_GetPolarity\n
  *         CCEP         CC1NPOL         LL_TIMER_OC_GetPolarity\n
  *         CCEP         CC2POL          LL_TIMER_OC_GetPolarity\n
  *         CCEP         CC2NPOL         LL_TIMER_OC_GetPolarity\n
  *         CCEP         CC3POL          LL_TIMER_OC_GetPolarity\n
  *         CCEP         CC3NPOL         LL_TIMER_OC_GetPolarity\n
  *         CCEP         CC4POL          LL_TIMER_OC_GetPolarity\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH1N
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH2N
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH3N
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_TIMER_OCPOLARITY_HIGH
  *         @arg @ref LL_TIMER_OCPOLARITY_LOW
  */
__STATIC_INLINE uint32_t LL_TIMER_OC_GetPolarity(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    return (READ_BIT(timx->CCEP, (TIMER_CCEP_CC1POL << SHIFT_TAB_CCxP[iChannel])) >> SHIFT_TAB_CCxP[iChannel]);
}

/**
  * @brief  Set the IDLE state of an output channel
  * @note This function is significant only for the timer instances
  *       supporting the break feature. Macro IS_TIMER_BREAK_INSTANCE(timx)
  *       can be used to check whether or not a timer instance provides
  *       a break input.
  * @rmtoll CON2         OISS1          LL_TIMER_OC_SetIdleState\n
  *         CON2         OISS2N         LL_TIMER_OC_SetIdleState\n
  *         CON2         OISS2          LL_TIMER_OC_SetIdleState\n
  *         CON2         OISS2N         LL_TIMER_OC_SetIdleState\n
  *         CON2         OISS3          LL_TIMER_OC_SetIdleState\n
  *         CON2         OISS3N         LL_TIMER_OC_SetIdleState\n
  *         CON2         OISS4          LL_TIMER_OC_SetIdleState\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH1N
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH2N
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH3N
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @param  IdleState This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_OCIDLESTATE_LOW
  *         @arg @ref LL_TIMER_OCIDLESTATE_HIGH
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_OC_SetIdleState(TIMER_TypeDef *timx, uint32_t Channel, uint32_t IdleState)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    MODIFY_REG(timx->CON2, (TIMER_CON2_OISS1 << SHIFT_TAB_OISx[iChannel]),  IdleState << SHIFT_TAB_OISx[iChannel]);
}

/**
  * @brief  Get the IDLE state of an output channel
  * @rmtoll CON2         OISS1          LL_TIMER_OC_GetIdleState\n
  *         CON2         OISS2N         LL_TIMER_OC_GetIdleState\n
  *         CON2         OISS2          LL_TIMER_OC_GetIdleState\n
  *         CON2         OISS2N         LL_TIMER_OC_GetIdleState\n
  *         CON2         OISS3          LL_TIMER_OC_GetIdleState\n
  *         CON2         OISS3N         LL_TIMER_OC_GetIdleState\n
  *         CON2         OISS4          LL_TIMER_OC_GetIdleState\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH1N
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH2N
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH3N
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_TIMER_OCIDLESTATE_LOW
  *         @arg @ref LL_TIMER_OCIDLESTATE_HIGH
  */
__STATIC_INLINE uint32_t LL_TIMER_OC_GetIdleState(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    return (READ_BIT(timx->CON2, (TIMER_CON2_OISS1 << SHIFT_TAB_OISx[iChannel])) >> SHIFT_TAB_OISx[iChannel]);
}

/**
  * @brief  Enable fast mode for the output channel.
  * @note Acts only if the channel is configured in PWM1 or PWM2 mode.
  * @rmtoll CHMR1        CH1FEN          LL_TIMER_OC_EnableFast\n
  *         CHMR1        CH2FEN          LL_TIMER_OC_EnableFast\n
  *         CHMR2        CH3FEN          LL_TIMER_OC_EnableFast\n
  *         CHMR2        CH4FEN          LL_TIMER_OC_EnableFast\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_OC_EnableFast(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    SET_BIT(*pReg, (TIMER_CHMR1_OUTPUT_CH1FEN << SHIFT_TAB_OCxx[iChannel]));

}

/**
  * @brief  Disable fast mode for the output channel.
  * @rmtoll CHMR1        CH1FEN          LL_TIMER_OC_DisableFast\n
  *         CHMR1        CH2FEN          LL_TIMER_OC_DisableFast\n
  *         CHMR2        CH3FEN          LL_TIMER_OC_DisableFast\n
  *         CHMR2        CH4FEN          LL_TIMER_OC_DisableFast\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_OC_DisableFast(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    CLEAR_BIT(*pReg, (TIMER_CHMR1_OUTPUT_CH1FEN << SHIFT_TAB_OCxx[iChannel]));

}

/**
  * @brief  Indicates whether fast mode is enabled for the output channel.
  * @rmtoll CHMR1        CH1FEN          LL_TIMER_OC_IsEnabledFast\n
  *         CHMR1        CH2FEN          LL_TIMER_OC_IsEnabledFast\n
  *         CHMR2        CH3FEN          LL_TIMER_OC_IsEnabledFast\n
  *         CHMR2        CH4FEN          LL_TIMER_OC_IsEnabledFast\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_TIMER_OC_IsEnabledFast(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    const __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    uint32_t bitfield = TIMER_CHMR1_OUTPUT_CH1FEN << SHIFT_TAB_OCxx[iChannel];
    return ((READ_BIT(*pReg, bitfield) == bitfield) ? 1UL : 0UL);
}

/**
  * @brief  Enable compare register (timx_CCRx) preload for the output channel.
  * @rmtoll CHMR1        CH1PEN          LL_TIMER_OC_EnablePreload\n
  *         CHMR1        CH2PEN          LL_TIMER_OC_EnablePreload\n
  *         CHMR2        CH3PEN          LL_TIMER_OC_EnablePreload\n
  *         CHMR2        CH4PEN          LL_TIMER_OC_EnablePreload\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_OC_EnablePreload(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    SET_BIT(*pReg, (TIMER_CHMR1_OUTPUT_CH1PEN << SHIFT_TAB_OCxx[iChannel]));
}

/**
  * @brief  Disable compare register (timx_CCRx) preload for the output channel.
  * @rmtoll CHMR1        CH1PEN          LL_TIMER_OC_DisablePreload\n
  *         CHMR1        CH2PEN          LL_TIMER_OC_DisablePreload\n
  *         CHMR2        CH3PEN          LL_TIMER_OC_DisablePreload\n
  *         CHMR2        CH4PEN          LL_TIMER_OC_DisablePreload\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_OC_DisablePreload(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    CLEAR_BIT(*pReg, (TIMER_CHMR1_OUTPUT_CH1PEN << SHIFT_TAB_OCxx[iChannel]));
}

/**
  * @brief  Indicates whether compare register (timx_CCRx) preload is enabled for the output channel.
  * @rmtoll CHMR1        CH1PEN          LL_TIMER_OC_IsEnabledPreload\n
  *         CHMR1        CH2PEN          LL_TIMER_OC_IsEnabledPreload\n
  *         CHMR2        CH3PEN          LL_TIMER_OC_IsEnabledPreload\n
  *         CHMR2        CH4PEN          LL_TIMER_OC_IsEnabledPreload\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_TIMER_OC_IsEnabledPreload(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    const __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    uint32_t bitfield = TIMER_CHMR1_OUTPUT_CH1PEN << SHIFT_TAB_OCxx[iChannel];
    return ((READ_BIT(*pReg, bitfield) == bitfield) ? 1UL : 0UL);
}

/**
  * @brief  Enable clearing the output channel on an external event.
  * @note This function can only be used in Output compare and PWM modes. It does not work in Forced mode.
  * @note Macro IS_TIMER_OCXREF_CLEAR_INSTANCE(timx) can be used to check whether
  *       or not a timer instance can clear the OCxREF signal on an external event.
  * @rmtoll CHMR1        CH1OCLREN          LL_TIMER_OC_EnableClear\n
  *         CHMR1        CH2OCLREN          LL_TIMER_OC_EnableClear\n
  *         CHMR2        CH3OCLREN          LL_TIMER_OC_EnableClear\n
  *         CHMR2        CH4OCLREN          LL_TIMER_OC_EnableClear\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_OC_EnableClear(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    SET_BIT(*pReg, (TIMER_CHMR1_OUTPUT_CH1OCLREN << SHIFT_TAB_OCxx[iChannel]));
}

/**
  * @brief  Disable clearing the output channel on an external event.
  * @note Macro IS_TIMER_OCXREF_CLEAR_INSTANCE(timx) can be used to check whether
  *       or not a timer instance can clear the OCxREF signal on an external event.
  * @rmtoll CHMR1        CH1OCLREN          LL_TIMER_OC_DisableClear\n
  *         CHMR1        CH2OCLREN          LL_TIMER_OC_DisableClear\n
  *         CHMR2        CH3OCLREN          LL_TIMER_OC_DisableClear\n
  *         CHMR2        CH4OCLREN          LL_TIMER_OC_DisableClear\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_OC_DisableClear(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    CLEAR_BIT(*pReg, (TIMER_CHMR1_OUTPUT_CH1OCLREN << SHIFT_TAB_OCxx[iChannel]));
}

/**
  * @brief  Indicates clearing the output channel on an external event is enabled for the output channel.
  * @note This function enables clearing the output channel on an external event.
  * @note This function can only be used in Output compare and PWM modes. It does not work in Forced mode.
  * @note Macro IS_TIMER_OCXREF_CLEAR_INSTANCE(timx) can be used to check whether
  *       or not a timer instance can clear the OCxREF signal on an external event.
  * @rmtoll CHMR1        CH1OCLREN          LL_TIMER_OC_IsEnabledClear\n
  *         CHMR1        CH2OCLREN          LL_TIMER_OC_IsEnabledClear\n
  *         CHMR2        CH3OCLREN          LL_TIMER_OC_IsEnabledClear\n
  *         CHMR2        CH4OCLREN          LL_TIMER_OC_IsEnabledClear\n
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_TIMER_OC_IsEnabledClear(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    const __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    uint32_t bitfield = TIMER_CHMR1_OUTPUT_CH1OCLREN << SHIFT_TAB_OCxx[iChannel];
    return ((READ_BIT(*pReg, bitfield) == bitfield) ? 1UL : 0UL);
}

/**
  * @brief  Configure input channel.
  * @rmtoll CHMR1        CC1SSEL        LL_TIMER_IC_Config\n
  *         CHMR1        I1PRES         LL_TIMER_IC_Config\n
  *         CHMR1        I1FLT          LL_TIMER_IC_Config\n
  *         CHMR1        CC2SSEL        LL_TIMER_IC_Config\n
  *         CHMR1        I2PRES         LL_TIMER_IC_Config\n
  *         CHMR1        I2FLT          LL_TIMER_IC_Config\n
  *         CHMR2        CC3SSEL        LL_TIMER_IC_Config\n
  *         CHMR2        I3PRES         LL_TIMER_IC_Config\n
  *         CHMR2        I3FLT          LL_TIMER_IC_Config\n
  *         CHMR2        CC4SSEL        LL_TIMER_IC_Config\n
  *         CHMR2        I4PRES         LL_TIMER_IC_Config\n
  *         CHMR2        I4FLT          LL_TIMER_IC_Config\n
  *         CCEP         CC1POL         LL_TIMER_IC_Config\n
  *         CCEP         CC1NPOL        LL_TIMER_IC_Config\n
  *         CCEP         CC2POL         LL_TIMER_IC_Config\n
  *         CCEP         CC2NPOL        LL_TIMER_IC_Config\n
  *         CCEP         CC3POL         LL_TIMER_IC_Config\n
  *         CCEP         CC3NPOL        LL_TIMER_IC_Config\n
  *         CCEP         CC4POL         LL_TIMER_IC_Config\n
  *         CCEP         CC4NPOL        LL_TIMER_IC_Config
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @param  Configuration This parameter must be a combination of all the following values:
  *         @arg @ref LL_TIMER_ACTIVEINPUT_DIRECTTI or @ref LL_TIMER_ACTIVEINPUT_INDIRECTTI or @ref LL_TIMER_ACTIVEINPUT_TRC
  *         @arg @ref LL_TIMER_ICPSC_DIV1 or ... or @ref LL_TIMER_ICPSC_DIV8
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV1 or ... or @ref LL_TIMER_IC_FILTER_FDIV32_N8
  *         @arg @ref LL_TIMER_IC_POLARITY_RISING or @ref LL_TIMER_IC_POLARITY_FALLING or @ref LL_TIMER_IC_POLARITY_BOTHEDGE
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_IC_Config(TIMER_TypeDef *timx, uint32_t Channel, uint32_t Configuration)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    MODIFY_REG(*pReg, ((TIMER_CHMR1_INPUT_I1FLT | TIMER_CHMR1_INPUT_I1PRES | TIMER_CHMR1_INPUT_CC1SSEL) << SHIFT_TAB_ICxx[iChannel]),
               ((Configuration >> 16U) & (TIMER_CHMR1_INPUT_I1FLT | TIMER_CHMR1_INPUT_I1PRES | TIMER_CHMR1_INPUT_CC1SSEL))  << SHIFT_TAB_ICxx[iChannel]);
    MODIFY_REG(timx->CCEP, ((TIMER_CCEP_CC1NPOL | TIMER_CCEP_CC1POL) << SHIFT_TAB_CCxP[iChannel]),
               (Configuration & (TIMER_CCEP_CC1NPOL | TIMER_CCEP_CC1POL)) << SHIFT_TAB_CCxP[iChannel]);
}

/**
  * @brief  Set the active input.
  * @rmtoll CHMR1        CC1SSEL          LL_TIMER_IC_SetActiveInput\n
  *         CHMR1        CC2SSEL          LL_TIMER_IC_SetActiveInput\n
  *         CHMR2        CC3SSEL          LL_TIMER_IC_SetActiveInput\n
  *         CHMR2        CC4SSEL          LL_TIMER_IC_SetActiveInput
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @param  ICActiveInput This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_ACTIVEINPUT_DIRECTTI
  *         @arg @ref LL_TIMER_ACTIVEINPUT_INDIRECTTI
  *         @arg @ref LL_TIMER_ACTIVEINPUT_TRC
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_IC_SetActiveInput(TIMER_TypeDef *timx, uint32_t Channel, uint32_t ICActiveInput)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    MODIFY_REG(*pReg, ((TIMER_CHMR1_INPUT_CC1SSEL) << SHIFT_TAB_ICxx[iChannel]), (ICActiveInput >> 16U) << SHIFT_TAB_ICxx[iChannel]);
}

/**
  * @brief  Get the current active input.
  * @rmtoll CHMR1        CC1SSEL          LL_TIMER_IC_GetActiveInput\n
  *         CHMR1        CC2SSEL          LL_TIMER_IC_GetActiveInput\n
  *         CHMR2        CC3SSEL          LL_TIMER_IC_GetActiveInput\n
  *         CHMR2        CC4SSEL          LL_TIMER_IC_GetActiveInput
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_TIMER_ACTIVEINPUT_DIRECTTI
  *         @arg @ref LL_TIMER_ACTIVEINPUT_INDIRECTTI
  *         @arg @ref LL_TIMER_ACTIVEINPUT_TRC
  */
__STATIC_INLINE uint32_t LL_TIMER_IC_GetActiveInput(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    const __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    return ((READ_BIT(*pReg, ((TIMER_CHMR1_INPUT_CC1SSEL) << SHIFT_TAB_ICxx[iChannel])) >> SHIFT_TAB_ICxx[iChannel]) << 16U);
}

/**
  * @brief  Set the prescaler of input channel.
  * @rmtoll CHMR1        I1PRES        LL_TIMER_IC_SetPrescaler\n
  *         CHMR1        I2PRES        LL_TIMER_IC_SetPrescaler\n
  *         CHMR2        I3PRES        LL_TIMER_IC_SetPrescaler\n
  *         CHMR2        I4PRES        LL_TIMER_IC_SetPrescaler
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @param  ICPrescaler This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_ICPSC_DIV1
  *         @arg @ref LL_TIMER_ICPSC_DIV2
  *         @arg @ref LL_TIMER_ICPSC_DIV4
  *         @arg @ref LL_TIMER_ICPSC_DIV8
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_IC_SetPrescaler(TIMER_TypeDef *timx, uint32_t Channel, uint32_t ICPrescaler)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    MODIFY_REG(*pReg, ((TIMER_CHMR1_INPUT_I1PRES) << SHIFT_TAB_ICxx[iChannel]), (ICPrescaler >> 16U) << SHIFT_TAB_ICxx[iChannel]);
}

/**
  * @brief  Get the current prescaler value acting on an  input channel.
  * @rmtoll CHMR1        I1PRES        LL_TIMER_IC_GetPrescaler\n
  *         CHMR1        I2PRES        LL_TIMER_IC_GetPrescaler\n
  *         CHMR2        I3PRES        LL_TIMER_IC_GetPrescaler\n
  *         CHMR2        I4PRES        LL_TIMER_IC_GetPrescaler
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_TIMER_ICPSC_DIV1
  *         @arg @ref LL_TIMER_ICPSC_DIV2
  *         @arg @ref LL_TIMER_ICPSC_DIV4
  *         @arg @ref LL_TIMER_ICPSC_DIV8
  */
__STATIC_INLINE uint32_t LL_TIMER_IC_GetPrescaler(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    const __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    return ((READ_BIT(*pReg, ((TIMER_CHMR1_INPUT_I1PRES) << SHIFT_TAB_ICxx[iChannel])) >> SHIFT_TAB_ICxx[iChannel]) << 16U);
}

/**
  * @brief  Set the input filter duration.
  * @rmtoll CHMR1        I1FLT          LL_TIMER_IC_SetFilter\n
  *         CHMR1        I2FLT          LL_TIMER_IC_SetFilter\n
  *         CHMR2        I3FLT          LL_TIMER_IC_SetFilter\n
  *         CHMR2        I4FLT          LL_TIMER_IC_SetFilter
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @param  ICFilter This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV1
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV1_N2
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV1_N4
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV1_N8
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV2_N6
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV2_N8
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV4_N6
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV4_N8
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV8_N6
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV8_N8
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV16_N5
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV16_N6
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV16_N8
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV32_N5
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV32_N6
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV32_N8
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_IC_SetFilter(TIMER_TypeDef *timx, uint32_t Channel, uint32_t ICFilter)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    MODIFY_REG(*pReg, ((TIMER_CHMR1_INPUT_I1FLT) << SHIFT_TAB_ICxx[iChannel]), (ICFilter >> 16U) << SHIFT_TAB_ICxx[iChannel]);
}

/**
  * @brief  Get the input filter duration.
  * @rmtoll CHMR1        I1FLT          LL_TIMER_IC_GetFilter\n
  *         CHMR1        I2FLT          LL_TIMER_IC_GetFilter\n
  *         CHMR2        I3FLT          LL_TIMER_IC_GetFilter\n
  *         CHMR2        I4FLT          LL_TIMER_IC_GetFilter
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV1
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV1_N2
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV1_N4
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV1_N8
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV2_N6
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV2_N8
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV4_N6
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV4_N8
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV8_N6
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV8_N8
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV16_N5
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV16_N6
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV16_N8
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV32_N5
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV32_N6
  *         @arg @ref LL_TIMER_IC_FILTER_FDIV32_N8
  */
__STATIC_INLINE uint32_t LL_TIMER_IC_GetFilter(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    const __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)(&timx->CHMR1) + OFFSET_TAB_CHMRx[iChannel]));
    return ((READ_BIT(*pReg, ((TIMER_CHMR1_INPUT_I1FLT) << SHIFT_TAB_ICxx[iChannel])) >> SHIFT_TAB_ICxx[iChannel]) << 16U);
}

/**
  * @brief  Set the input channel polarity.
  * @rmtoll CCEP         CC1POL          LL_TIMER_IC_SetPolarity\n
  *         CCEP         CC1NPOL         LL_TIMER_IC_SetPolarity\n
  *         CCEP         CC2POL          LL_TIMER_IC_SetPolarity\n
  *         CCEP         CC2NPOL         LL_TIMER_IC_SetPolarity\n
  *         CCEP         CC3POL          LL_TIMER_IC_SetPolarity\n
  *         CCEP         CC3NPOL         LL_TIMER_IC_SetPolarity\n
  *         CCEP         CC4POL          LL_TIMER_IC_SetPolarity\n
  *         CCEP         CC4NPOL         LL_TIMER_IC_SetPolarity
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @param  ICPolarity This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_IC_POLARITY_RISING
  *         @arg @ref LL_TIMER_IC_POLARITY_FALLING
  *         @arg @ref LL_TIMER_IC_POLARITY_BOTHEDGE
  * @retval None
  */
__STATIC_INLINE void LL_TIMER_IC_SetPolarity(TIMER_TypeDef *timx, uint32_t Channel, uint32_t ICPolarity)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    MODIFY_REG(timx->CCEP, ((TIMER_CCEP_CC1NPOL | TIMER_CCEP_CC1POL) << SHIFT_TAB_CCxP[iChannel]),
               ICPolarity << SHIFT_TAB_CCxP[iChannel]);
}

/**
  * @brief  Get the current input channel polarity.
  * @rmtoll CCEP         CC1POL          LL_TIMER_IC_GetPolarity\n
  *         CCEP         CC1NPOL         LL_TIMER_IC_GetPolarity\n
  *         CCEP         CC2POL          LL_TIMER_IC_GetPolarity\n
  *         CCEP         CC2NPOL         LL_TIMER_IC_GetPolarity\n
  *         CCEP         CC3POL          LL_TIMER_IC_GetPolarity\n
  *         CCEP         CC3NPOL         LL_TIMER_IC_GetPolarity\n
  *         CCEP         CC4POL          LL_TIMER_IC_GetPolarity\n
  *         CCEP         CC4NPOL         LL_TIMER_IC_GetPolarity
  * @param  timx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_TIMER_CHANNEL_CH1
  *         @arg @ref LL_TIMER_CHANNEL_CH2
  *         @arg @ref LL_TIMER_CHANNEL_CH3
  *         @arg @ref LL_TIMER_CHANNEL_CH4
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_TIMER_IC_POLARITY_RISING
  *         @arg @ref LL_TIMER_IC_POLARITY_FALLING
  *         @arg @ref LL_TIMER_IC_POLARITY_BOTHEDGE
  */
__STATIC_INLINE uint32_t LL_TIMER_IC_GetPolarity(TIMER_TypeDef *timx, uint32_t Channel)
{
    uint8_t iChannel = TIMER_GET_CHANNEL_INDEX(Channel);
    return (READ_BIT(timx->CCEP, ((TIMER_CCEP_CC1NPOL | TIMER_CCEP_CC1POL) << SHIFT_TAB_CCxP[iChannel])) >>
            SHIFT_TAB_CCxP[iChannel]);
}
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

