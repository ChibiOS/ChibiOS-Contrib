/**********************************************************************************
 *
 * @file    md_adc.h
 * @brief   header file of md_adc.c
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov 2021     Ginger          the first version
 *          28 Mar 2022     AE Team         Modify MD Driver
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
#ifndef __MD_ADC_H__
#define __MD_ADC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_ADC ADC
  * @brief ADC micro driver
  * @{
  */

/** @defgroup MD_ADC_Pubulic_Types ADC Pubulic Types
  * @{
  */

/**
  * @brief ADC Init structure.
  */
typedef struct
{
    uint8_t ALIGN;
    uint32_t RSEL;
    uint8_t Regular_Injected  ;
    uint16_t Regular_CM;
    uint8_t Cnt;
    uint8_t CKDIV;
} md_adc_initial;
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Macros ADC Public Macros
  * @{
  */

#define  MD_ADC_CON_ADCAL_CALIBRATION_COMPLETE  (0x00000000U)
#define  MD_ADC_CON_ADCAL_CALIBRATION           (0x00000001U)

#define  MD_ADC_CON_ISTPC_NOSTOP_INJECTED       (0x00000000U)
#define  MD_ADC_CON_ISTPC_STOP_INJECTED         (0x00000001U)

#define  MD_ADC_CON_NSTPC_NOSTOP_REGULAR        (0x00000000U)
#define  MD_ADC_CON_NSTPC_STOP_REGULAR          (0x00000001U)

#define  MD_ADC_CON_ISTART_NOADC_INJECTED       (0x00000000U)
#define  MD_ADC_CON_ISTART_START_INJECTED       (0x00000001U)

#define  MD_ADC_CON_NSTART_NOADC_REGULAR        (0x00000000U)
#define  MD_ADC_CON_NSTART_START_REGULAR        (0x00000001U)

#define  MD_ADC_CON_ADCEN_DISABLE               (0x00000000U)
#define  MD_ADC_CON_ADCEN_ENABLE                (0x00000001U)


#define  MD_ADC_CFG_AWDCH_CH0           (0x00000000U)
#define  MD_ADC_CFG_AWDCH_CH1           (0x00000001U)
#define  MD_ADC_CFG_AWDCH_CH2           (0x00000002U)
#define  MD_ADC_CFG_AWDCH_CH3           (0x00000003U)
#define  MD_ADC_CFG_AWDCH_CH4           (0x00000004U)
#define  MD_ADC_CFG_AWDCH_CH5           (0x00000005U)
#define  MD_ADC_CFG_AWDCH_CH6           (0x00000006U)
#define  MD_ADC_CFG_AWDCH_CH7           (0x00000007U)
#define  MD_ADC_CFG_AWDCH_CH8           (0x00000008U)
#define  MD_ADC_CFG_AWDCH_CH9           (0x00000009U)
#define  MD_ADC_CFG_AWDCH_CH10          (0x0000000AU)
#define  MD_ADC_CFG_AWDCH_CH11          (0x0000000BU)
#define  MD_ADC_CFG_AWDCH_CH12          (0x0000000CU)
#define  MD_ADC_CFG_AWDCH_CH13          (0x0000000DU)
#define  MD_ADC_CFG_AWDCH_CH14          (0x0000000EU)
#define  MD_ADC_CFG_AWDCH_CH15          (0x0000000FU)
#define  MD_ADC_CFG_AWDCH_CH16          (0x00000010U)
#define  MD_ADC_CFG_AWDCH_CH17          (0x00000011U)
#define  MD_ADC_CFG_AWDCH_CH18          (0x00000012U)

#define  MD_ADC_CFG_AWDSGL_ALL_CH       (0x00000000U)
#define  MD_ADC_CFG_AWDSGL_SINGLE_CH    (0x00000001U)

#define  MD_ADC_CFG_ETRGN_1CH           (0x00000000U)
#define  MD_ADC_CFG_ETRGN_2CH           (0x00000001U)
#define  MD_ADC_CFG_ETRGN_3CH           (0x00000002U)
#define  MD_ADC_CFG_ETRGN_4CH           (0x00000003U)
#define  MD_ADC_CFG_ETRGN_5CH           (0x00000004U)
#define  MD_ADC_CFG_ETRGN_6CH           (0x00000005U)
#define  MD_ADC_CFG_ETRGN_7CH           (0x00000006U)
#define  MD_ADC_CFG_ETRGN_8CH           (0x00000007U)

#define  MD_ADC_CFG_CM_SINGLE           (0x00000000U)
#define  MD_ADC_CFG_CM_CONTINUOUS       (0x00000001U)

#define  MD_ADC_CFG_OVRMOD_PRESERVED    (0x00000000U)
#define  MD_ADC_CFG_OVRMOD_OVERWRITTEN  (0x00000001U)

#define  MD_ADC_CFG_NETS_DISABLE        (0x00000000U)
#define  MD_ADC_CFG_NETS_RISING         (0x00000001U)
#define  MD_ADC_CFG_NETS_FALLING        (0x00000002U)
#define  MD_ADC_CFG_NETS_BOTH           (0x00000003U)

#define  MD_ADC_CFG_NEXTSEL_AD16C4T1_CH1        (0x00000000U)
#define  MD_ADC_CFG_NEXTSEL_AD16C4T1_CH2        (0x00000001U)
#define  MD_ADC_CFG_NEXTSEL_AD16C4T1_CH3        (0x00000002U)
#define  MD_ADC_CFG_NEXTSEL_GP32C4T1_CH2        (0x00000003U)
#define  MD_ADC_CFG_NEXTSEL_GP32C4T1_CH3        (0x00000004U)
#define  MD_ADC_CFG_NEXTSEL_GP32C4T1_CH4        (0x00000005U)
#define  MD_ADC_CFG_NEXTSEL_GP32C4T1_TRGOUT     (0x00000006U)
#define  MD_ADC_CFG_NEXTSEL_GP16C4T1_CH1        (0x00000007U)
#define  MD_ADC_CFG_NEXTSEL_GP16C4T1_TRGOUT     (0x00000008U)
#define  MD_ADC_CFG_NEXTSEL_GP16C4T2_CH4        (0x00000009U)
#define  MD_ADC_CFG_NEXTSEL_GP16C4T3_CH1        (0x0000000AU)
#define  MD_ADC_CFG_NEXTSEL_GP16C4T3_CH2        (0x0000000BU)
#define  MD_ADC_CFG_NEXTSEL_GP16C4T3_CH3        (0x0000000CU)
#define  MD_ADC_CFG_NEXTSEL_BS16T1_TRGOUT       (0x0000000DU)
#define  MD_ADC_CFG_NEXTSEL_RTC                 (0x0000000EU)
#define  MD_ADC_CFG_NEXTSEL_EXTI_TRG0           (0x0000000FU)

#define  MD_ADC_CFG_ALIGN_RIGHT         (0x00000000U)
#define  MD_ADC_CFG_ALIGN_LEFT          (0x00000001U)

#define  MD_ADC_CFG_RSEL_6BIT           (0x00000000U)
#define  MD_ADC_CFG_RSEL_8BIT           (0x00000001U)
#define  MD_ADC_CFG_RSEL_10BIT          (0x00000002U)
#define  MD_ADC_CFG_RSEL_12BIT          (0x00000003U)

#define  MD_ADC_SMPT1_CKDIV_DIV1        (0x00000000U)
#define  MD_ADC_SMPT1_CKDIV_DIV2        (0x00000001U)
#define  MD_ADC_SMPT1_CKDIV_DIV4        (0x00000002U)
#define  MD_ADC_SMPT1_CKDIV_DIV6        (0x00000003U)
#define  MD_ADC_SMPT1_CKDIV_DIV8        (0x00000004U)

#define  MD_ADC_NCHS1_NS4_CH0      (0x00000000U)
#define  MD_ADC_NCHS1_NS4_CH1      (0x00000001U)
#define  MD_ADC_NCHS1_NS4_CH2      (0x00000002U)
#define  MD_ADC_NCHS1_NS4_CH3      (0x00000003U)
#define  MD_ADC_NCHS1_NS4_CH4      (0x00000004U)
#define  MD_ADC_NCHS1_NS4_CH5      (0x00000005U)
#define  MD_ADC_NCHS1_NS4_CH6      (0x00000006U)
#define  MD_ADC_NCHS1_NS4_CH7      (0x00000007U)
#define  MD_ADC_NCHS1_NS4_CH8      (0x00000008U)
#define  MD_ADC_NCHS1_NS4_CH9      (0x00000009U)
#define  MD_ADC_NCHS1_NS4_CH10     (0x0000000AU)
#define  MD_ADC_NCHS1_NS4_CH11     (0x0000000BU)
#define  MD_ADC_NCHS1_NS4_CH12     (0x0000000CU)
#define  MD_ADC_NCHS1_NS4_CH13     (0x0000000DU)
#define  MD_ADC_NCHS1_NS4_CH14     (0x0000000EU)
#define  MD_ADC_NCHS1_NS4_CH15     (0x0000000FU)
#define  MD_ADC_NCHS1_NS4_CH16     (0x00000010U)
#define  MD_ADC_NCHS1_NS4_CH17     (0x00000011U)
#define  MD_ADC_NCHS1_NS4_CH18     (0x00000012U)

#define  MD_ADC_NCHS1_NS3_CH0      (0x00000000U)
#define  MD_ADC_NCHS1_NS3_CH1      (0x00000001U)
#define  MD_ADC_NCHS1_NS3_CH2      (0x00000002U)
#define  MD_ADC_NCHS1_NS3_CH3      (0x00000003U)
#define  MD_ADC_NCHS1_NS3_CH4      (0x00000004U)
#define  MD_ADC_NCHS1_NS3_CH5      (0x00000005U)
#define  MD_ADC_NCHS1_NS3_CH6      (0x00000006U)
#define  MD_ADC_NCHS1_NS3_CH7      (0x00000007U)
#define  MD_ADC_NCHS1_NS3_CH8      (0x00000008U)
#define  MD_ADC_NCHS1_NS3_CH9      (0x00000009U)
#define  MD_ADC_NCHS1_NS3_CH10     (0x0000000AU)
#define  MD_ADC_NCHS1_NS3_CH11     (0x0000000BU)
#define  MD_ADC_NCHS1_NS3_CH12     (0x0000000CU)
#define  MD_ADC_NCHS1_NS3_CH13     (0x0000000DU)
#define  MD_ADC_NCHS1_NS3_CH14     (0x0000000EU)
#define  MD_ADC_NCHS1_NS3_CH15     (0x0000000FU)
#define  MD_ADC_NCHS1_NS3_CH16     (0x00000010U)
#define  MD_ADC_NCHS1_NS3_CH17     (0x00000011U)
#define  MD_ADC_NCHS1_NS3_CH18     (0x00000012U)

#define  MD_ADC_NCHS1_NS2_CH0      (0x00000000U)
#define  MD_ADC_NCHS1_NS2_CH1      (0x00000001U)
#define  MD_ADC_NCHS1_NS2_CH2      (0x00000002U)
#define  MD_ADC_NCHS1_NS2_CH3      (0x00000003U)
#define  MD_ADC_NCHS1_NS2_CH4      (0x00000004U)
#define  MD_ADC_NCHS1_NS2_CH5      (0x00000005U)
#define  MD_ADC_NCHS1_NS2_CH6      (0x00000006U)
#define  MD_ADC_NCHS1_NS2_CH7      (0x00000007U)
#define  MD_ADC_NCHS1_NS2_CH8      (0x00000008U)
#define  MD_ADC_NCHS1_NS2_CH9      (0x00000009U)
#define  MD_ADC_NCHS1_NS2_CH10     (0x0000000AU)
#define  MD_ADC_NCHS1_NS2_CH11     (0x0000000BU)
#define  MD_ADC_NCHS1_NS2_CH12     (0x0000000CU)
#define  MD_ADC_NCHS1_NS2_CH13     (0x0000000DU)
#define  MD_ADC_NCHS1_NS2_CH14     (0x0000000EU)
#define  MD_ADC_NCHS1_NS2_CH15     (0x0000000FU)
#define  MD_ADC_NCHS1_NS2_CH16     (0x00000010U)
#define  MD_ADC_NCHS1_NS2_CH17     (0x00000011U)
#define  MD_ADC_NCHS1_NS2_CH18     (0x00000012U)

#define  MD_ADC_NCHS1_NS1_CH0      (0x00000000U)
#define  MD_ADC_NCHS1_NS1_CH1      (0x00000001U)
#define  MD_ADC_NCHS1_NS1_CH2      (0x00000002U)
#define  MD_ADC_NCHS1_NS1_CH3      (0x00000003U)
#define  MD_ADC_NCHS1_NS1_CH4      (0x00000004U)
#define  MD_ADC_NCHS1_NS1_CH5      (0x00000005U)
#define  MD_ADC_NCHS1_NS1_CH6      (0x00000006U)
#define  MD_ADC_NCHS1_NS1_CH7      (0x00000007U)
#define  MD_ADC_NCHS1_NS1_CH8      (0x00000008U)
#define  MD_ADC_NCHS1_NS1_CH9      (0x00000009U)
#define  MD_ADC_NCHS1_NS1_CH10     (0x0000000AU)
#define  MD_ADC_NCHS1_NS1_CH11     (0x0000000BU)
#define  MD_ADC_NCHS1_NS1_CH12     (0x0000000CU)
#define  MD_ADC_NCHS1_NS1_CH13     (0x0000000DU)
#define  MD_ADC_NCHS1_NS1_CH14     (0x0000000EU)
#define  MD_ADC_NCHS1_NS1_CH15     (0x0000000FU)
#define  MD_ADC_NCHS1_NS1_CH16     (0x00000010U)
#define  MD_ADC_NCHS1_NS1_CH17     (0x00000011U)
#define  MD_ADC_NCHS1_NS1_CH18     (0x00000012U)

#define  MD_ADC_NCHS1_NSL_1CON     (0x00000000U)
#define  MD_ADC_NCHS1_NSL_2CON     (0x00000001U)
#define  MD_ADC_NCHS1_NSL_3CON     (0x00000002U)
#define  MD_ADC_NCHS1_NSL_4CON     (0x00000003U)
#define  MD_ADC_NCHS1_NSL_5CON     (0x00000004U)
#define  MD_ADC_NCHS1_NSL_6CON     (0x00000005U)
#define  MD_ADC_NCHS1_NSL_7CON     (0x00000006U)
#define  MD_ADC_NCHS1_NSL_8CON     (0x00000007U)
#define  MD_ADC_NCHS1_NSL_9CON     (0x00000008U)
#define  MD_ADC_NCHS1_NSL_10CON    (0x00000009U)
#define  MD_ADC_NCHS1_NSL_11CON    (0x0000000AU)
#define  MD_ADC_NCHS1_NSL_12CON    (0x0000000BU)
#define  MD_ADC_NCHS1_NSL_13CON    (0x0000000CU)
#define  MD_ADC_NCHS1_NSL_14CON    (0x0000000DU)
#define  MD_ADC_NCHS1_NSL_15CON    (0x0000000EU)
#define  MD_ADC_NCHS1_NSL_16CON    (0x0000000FU)

#define  MD_ADC_NCHS2_NS9_CH0      (0x00000000U)
#define  MD_ADC_NCHS2_NS9_CH1      (0x00000001U)
#define  MD_ADC_NCHS2_NS9_CH2      (0x00000002U)
#define  MD_ADC_NCHS2_NS9_CH3      (0x00000003U)
#define  MD_ADC_NCHS2_NS9_CH4      (0x00000004U)
#define  MD_ADC_NCHS2_NS9_CH5      (0x00000005U)
#define  MD_ADC_NCHS2_NS9_CH6      (0x00000006U)
#define  MD_ADC_NCHS2_NS9_CH7      (0x00000007U)
#define  MD_ADC_NCHS2_NS9_CH8      (0x00000008U)
#define  MD_ADC_NCHS2_NS9_CH9      (0x00000009U)
#define  MD_ADC_NCHS2_NS9_CH10     (0x0000000AU)
#define  MD_ADC_NCHS2_NS9_CH11     (0x0000000BU)
#define  MD_ADC_NCHS2_NS9_CH12     (0x0000000CU)
#define  MD_ADC_NCHS2_NS9_CH13     (0x0000000DU)
#define  MD_ADC_NCHS2_NS9_CH14     (0x0000000EU)
#define  MD_ADC_NCHS2_NS9_CH15     (0x0000000FU)
#define  MD_ADC_NCHS2_NS9_CH16     (0x00000010U)
#define  MD_ADC_NCHS2_NS9_CH17     (0x00000011U)
#define  MD_ADC_NCHS2_NS9_CH18     (0x00000012U)

#define  MD_ADC_NCHS2_NS8_CH0      (0x00000000U)
#define  MD_ADC_NCHS2_NS8_CH1      (0x00000001U)
#define  MD_ADC_NCHS2_NS8_CH2      (0x00000002U)
#define  MD_ADC_NCHS2_NS8_CH3      (0x00000003U)
#define  MD_ADC_NCHS2_NS8_CH4      (0x00000004U)
#define  MD_ADC_NCHS2_NS8_CH5      (0x00000005U)
#define  MD_ADC_NCHS2_NS8_CH6      (0x00000006U)
#define  MD_ADC_NCHS2_NS8_CH7      (0x00000007U)
#define  MD_ADC_NCHS2_NS8_CH8      (0x00000008U)
#define  MD_ADC_NCHS2_NS8_CH9      (0x00000009U)
#define  MD_ADC_NCHS2_NS8_CH10     (0x0000000AU)
#define  MD_ADC_NCHS2_NS8_CH11     (0x0000000BU)
#define  MD_ADC_NCHS2_NS8_CH12     (0x0000000CU)
#define  MD_ADC_NCHS2_NS8_CH13     (0x0000000DU)
#define  MD_ADC_NCHS2_NS8_CH14     (0x0000000EU)
#define  MD_ADC_NCHS2_NS8_CH15     (0x0000000FU)
#define  MD_ADC_NCHS2_NS8_CH16     (0x00000010U)
#define  MD_ADC_NCHS2_NS8_CH17     (0x00000011U)
#define  MD_ADC_NCHS2_NS8_CH18     (0x00000012U)

#define  MD_ADC_NCHS2_NS7_CH0      (0x00000000U)
#define  MD_ADC_NCHS2_NS7_CH1      (0x00000001U)
#define  MD_ADC_NCHS2_NS7_CH2      (0x00000002U)
#define  MD_ADC_NCHS2_NS7_CH3      (0x00000003U)
#define  MD_ADC_NCHS2_NS7_CH4      (0x00000004U)
#define  MD_ADC_NCHS2_NS7_CH5      (0x00000005U)
#define  MD_ADC_NCHS2_NS7_CH6      (0x00000006U)
#define  MD_ADC_NCHS2_NS7_CH7      (0x00000007U)
#define  MD_ADC_NCHS2_NS7_CH8      (0x00000008U)
#define  MD_ADC_NCHS2_NS7_CH9      (0x00000009U)
#define  MD_ADC_NCHS2_NS7_CH10     (0x0000000AU)
#define  MD_ADC_NCHS2_NS7_CH11     (0x0000000BU)
#define  MD_ADC_NCHS2_NS7_CH12     (0x0000000CU)
#define  MD_ADC_NCHS2_NS7_CH13     (0x0000000DU)
#define  MD_ADC_NCHS2_NS7_CH14     (0x0000000EU)
#define  MD_ADC_NCHS2_NS7_CH15     (0x0000000FU)
#define  MD_ADC_NCHS2_NS7_CH16     (0x00000010U)
#define  MD_ADC_NCHS2_NS7_CH17     (0x00000011U)
#define  MD_ADC_NCHS2_NS7_CH18     (0x00000012U)

#define  MD_ADC_NCHS2_NS6_CH0      (0x00000000U)
#define  MD_ADC_NCHS2_NS6_CH1      (0x00000001U)
#define  MD_ADC_NCHS2_NS6_CH2      (0x00000002U)
#define  MD_ADC_NCHS2_NS6_CH3      (0x00000003U)
#define  MD_ADC_NCHS2_NS6_CH4      (0x00000004U)
#define  MD_ADC_NCHS2_NS6_CH5      (0x00000005U)
#define  MD_ADC_NCHS2_NS6_CH6      (0x00000006U)
#define  MD_ADC_NCHS2_NS6_CH7      (0x00000007U)
#define  MD_ADC_NCHS2_NS6_CH8      (0x00000008U)
#define  MD_ADC_NCHS2_NS6_CH9      (0x00000009U)
#define  MD_ADC_NCHS2_NS6_CH10     (0x0000000AU)
#define  MD_ADC_NCHS2_NS6_CH11     (0x0000000BU)
#define  MD_ADC_NCHS2_NS6_CH12     (0x0000000CU)
#define  MD_ADC_NCHS2_NS6_CH13     (0x0000000DU)
#define  MD_ADC_NCHS2_NS6_CH14     (0x0000000EU)
#define  MD_ADC_NCHS2_NS6_CH15     (0x0000000FU)
#define  MD_ADC_NCHS2_NS6_CH16     (0x00000010U)
#define  MD_ADC_NCHS2_NS6_CH17     (0x00000011U)
#define  MD_ADC_NCHS2_NS6_CH18     (0x00000012U)

#define  MD_ADC_NCHS2_NS5_CH0      (0x00000000U)
#define  MD_ADC_NCHS2_NS5_CH1      (0x00000001U)
#define  MD_ADC_NCHS2_NS5_CH2      (0x00000002U)
#define  MD_ADC_NCHS2_NS5_CH3      (0x00000003U)
#define  MD_ADC_NCHS2_NS5_CH4      (0x00000004U)
#define  MD_ADC_NCHS2_NS5_CH5      (0x00000005U)
#define  MD_ADC_NCHS2_NS5_CH6      (0x00000006U)
#define  MD_ADC_NCHS2_NS5_CH7      (0x00000007U)
#define  MD_ADC_NCHS2_NS5_CH8      (0x00000008U)
#define  MD_ADC_NCHS2_NS5_CH9      (0x00000009U)
#define  MD_ADC_NCHS2_NS5_CH10     (0x0000000AU)
#define  MD_ADC_NCHS2_NS5_CH11     (0x0000000BU)
#define  MD_ADC_NCHS2_NS5_CH12     (0x0000000CU)
#define  MD_ADC_NCHS2_NS5_CH13     (0x0000000DU)
#define  MD_ADC_NCHS2_NS5_CH14     (0x0000000EU)
#define  MD_ADC_NCHS2_NS5_CH15     (0x0000000FU)
#define  MD_ADC_NCHS2_NS5_CH16     (0x00000010U)
#define  MD_ADC_NCHS2_NS5_CH17     (0x00000011U)
#define  MD_ADC_NCHS2_NS5_CH18     (0x00000012U)

#define  MD_ADC_NCHS3_NS14_CH0      (0x00000000U)
#define  MD_ADC_NCHS3_NS14_CH1      (0x00000001U)
#define  MD_ADC_NCHS3_NS14_CH2      (0x00000002U)
#define  MD_ADC_NCHS3_NS14_CH3      (0x00000003U)
#define  MD_ADC_NCHS3_NS14_CH4      (0x00000004U)
#define  MD_ADC_NCHS3_NS14_CH5      (0x00000005U)
#define  MD_ADC_NCHS3_NS14_CH6      (0x00000006U)
#define  MD_ADC_NCHS3_NS14_CH7      (0x00000007U)
#define  MD_ADC_NCHS3_NS14_CH8      (0x00000008U)
#define  MD_ADC_NCHS3_NS14_CH9      (0x00000009U)
#define  MD_ADC_NCHS3_NS14_CH10     (0x0000000AU)
#define  MD_ADC_NCHS3_NS14_CH11     (0x0000000BU)
#define  MD_ADC_NCHS3_NS14_CH12     (0x0000000CU)
#define  MD_ADC_NCHS3_NS14_CH13     (0x0000000DU)
#define  MD_ADC_NCHS3_NS14_CH14     (0x0000000EU)
#define  MD_ADC_NCHS3_NS14_CH15     (0x0000000FU)
#define  MD_ADC_NCHS3_NS14_CH16     (0x00000010U)
#define  MD_ADC_NCHS3_NS14_CH17     (0x00000011U)
#define  MD_ADC_NCHS3_NS14_CH18     (0x00000012U)

#define  MD_ADC_NCHS3_NS13_CH0      (0x00000000U)
#define  MD_ADC_NCHS3_NS13_CH1      (0x00000001U)
#define  MD_ADC_NCHS3_NS13_CH2      (0x00000002U)
#define  MD_ADC_NCHS3_NS13_CH3      (0x00000003U)
#define  MD_ADC_NCHS3_NS13_CH4      (0x00000004U)
#define  MD_ADC_NCHS3_NS13_CH5      (0x00000005U)
#define  MD_ADC_NCHS3_NS13_CH6      (0x00000006U)
#define  MD_ADC_NCHS3_NS13_CH7      (0x00000007U)
#define  MD_ADC_NCHS3_NS13_CH8      (0x00000008U)
#define  MD_ADC_NCHS3_NS13_CH9      (0x00000009U)
#define  MD_ADC_NCHS3_NS13_CH10     (0x0000000AU)
#define  MD_ADC_NCHS3_NS13_CH11     (0x0000000BU)
#define  MD_ADC_NCHS3_NS13_CH12     (0x0000000CU)
#define  MD_ADC_NCHS3_NS13_CH13     (0x0000000DU)
#define  MD_ADC_NCHS3_NS13_CH14     (0x0000000EU)
#define  MD_ADC_NCHS3_NS13_CH15     (0x0000000FU)
#define  MD_ADC_NCHS3_NS13_CH16     (0x00000010U)
#define  MD_ADC_NCHS3_NS13_CH17     (0x00000011U)
#define  MD_ADC_NCHS3_NS13_CH18     (0x00000012U)

#define  MD_ADC_NCHS3_NS12_CH0      (0x00000000U)
#define  MD_ADC_NCHS3_NS12_CH1      (0x00000001U)
#define  MD_ADC_NCHS3_NS12_CH2      (0x00000002U)
#define  MD_ADC_NCHS3_NS12_CH3      (0x00000003U)
#define  MD_ADC_NCHS3_NS12_CH4      (0x00000004U)
#define  MD_ADC_NCHS3_NS12_CH5      (0x00000005U)
#define  MD_ADC_NCHS3_NS12_CH6      (0x00000006U)
#define  MD_ADC_NCHS3_NS12_CH7      (0x00000007U)
#define  MD_ADC_NCHS3_NS12_CH8      (0x00000008U)
#define  MD_ADC_NCHS3_NS12_CH9      (0x00000009U)
#define  MD_ADC_NCHS3_NS12_CH10     (0x0000000AU)
#define  MD_ADC_NCHS3_NS12_CH11     (0x0000000BU)
#define  MD_ADC_NCHS3_NS12_CH12     (0x0000000CU)
#define  MD_ADC_NCHS3_NS12_CH13     (0x0000000DU)
#define  MD_ADC_NCHS3_NS12_CH14     (0x0000000EU)
#define  MD_ADC_NCHS3_NS12_CH15     (0x0000000FU)
#define  MD_ADC_NCHS3_NS12_CH16     (0x00000010U)
#define  MD_ADC_NCHS3_NS12_CH17     (0x00000011U)
#define  MD_ADC_NCHS3_NS12_CH18     (0x00000012U)

#define  MD_ADC_NCHS3_NS11_CH0      (0x00000000U)
#define  MD_ADC_NCHS3_NS11_CH1      (0x00000001U)
#define  MD_ADC_NCHS3_NS11_CH2      (0x00000002U)
#define  MD_ADC_NCHS3_NS11_CH3      (0x00000003U)
#define  MD_ADC_NCHS3_NS11_CH4      (0x00000004U)
#define  MD_ADC_NCHS3_NS11_CH5      (0x00000005U)
#define  MD_ADC_NCHS3_NS11_CH6      (0x00000006U)
#define  MD_ADC_NCHS3_NS11_CH7      (0x00000007U)
#define  MD_ADC_NCHS3_NS11_CH8      (0x00000008U)
#define  MD_ADC_NCHS3_NS11_CH9      (0x00000009U)
#define  MD_ADC_NCHS3_NS11_CH10     (0x0000000AU)
#define  MD_ADC_NCHS3_NS11_CH11     (0x0000000BU)
#define  MD_ADC_NCHS3_NS11_CH12     (0x0000000CU)
#define  MD_ADC_NCHS3_NS11_CH13     (0x0000000DU)
#define  MD_ADC_NCHS3_NS11_CH14     (0x0000000EU)
#define  MD_ADC_NCHS3_NS11_CH15     (0x0000000FU)
#define  MD_ADC_NCHS3_NS11_CH16     (0x00000010U)
#define  MD_ADC_NCHS3_NS11_CH17     (0x00000011U)
#define  MD_ADC_NCHS3_NS11_CH18     (0x00000012U)

#define  MD_ADC_NCHS3_NS10_CH0      (0x00000000U)
#define  MD_ADC_NCHS3_NS10_CH1      (0x00000001U)
#define  MD_ADC_NCHS3_NS10_CH2      (0x00000002U)
#define  MD_ADC_NCHS3_NS10_CH3      (0x00000003U)
#define  MD_ADC_NCHS3_NS10_CH4      (0x00000004U)
#define  MD_ADC_NCHS3_NS10_CH5      (0x00000005U)
#define  MD_ADC_NCHS3_NS10_CH6      (0x00000006U)
#define  MD_ADC_NCHS3_NS10_CH7      (0x00000007U)
#define  MD_ADC_NCHS3_NS10_CH8      (0x00000008U)
#define  MD_ADC_NCHS3_NS10_CH9      (0x00000009U)
#define  MD_ADC_NCHS3_NS10_CH10     (0x0000000AU)
#define  MD_ADC_NCHS3_NS10_CH11     (0x0000000BU)
#define  MD_ADC_NCHS3_NS10_CH12     (0x0000000CU)
#define  MD_ADC_NCHS3_NS10_CH13     (0x0000000DU)
#define  MD_ADC_NCHS3_NS10_CH14     (0x0000000EU)
#define  MD_ADC_NCHS3_NS10_CH15     (0x0000000FU)
#define  MD_ADC_NCHS3_NS10_CH16     (0x00000010U)
#define  MD_ADC_NCHS3_NS10_CH17     (0x00000011U)
#define  MD_ADC_NCHS3_NS10_CH18     (0x00000012U)

#define  MD_ADC_NCHS4_NS16_CH0      (0x00000000U)
#define  MD_ADC_NCHS4_NS16_CH1      (0x00000001U)
#define  MD_ADC_NCHS4_NS16_CH2      (0x00000002U)
#define  MD_ADC_NCHS4_NS16_CH3      (0x00000003U)
#define  MD_ADC_NCHS4_NS16_CH4      (0x00000004U)
#define  MD_ADC_NCHS4_NS16_CH5      (0x00000005U)
#define  MD_ADC_NCHS4_NS16_CH6      (0x00000006U)
#define  MD_ADC_NCHS4_NS16_CH7      (0x00000007U)
#define  MD_ADC_NCHS4_NS16_CH8      (0x00000008U)
#define  MD_ADC_NCHS4_NS16_CH9      (0x00000009U)
#define  MD_ADC_NCHS4_NS16_CH10     (0x0000000AU)
#define  MD_ADC_NCHS4_NS16_CH11     (0x0000000BU)
#define  MD_ADC_NCHS4_NS16_CH12     (0x0000000CU)
#define  MD_ADC_NCHS4_NS16_CH13     (0x0000000DU)
#define  MD_ADC_NCHS4_NS16_CH14     (0x0000000EU)
#define  MD_ADC_NCHS4_NS16_CH15     (0x0000000FU)
#define  MD_ADC_NCHS4_NS16_CH16     (0x00000010U)
#define  MD_ADC_NCHS4_NS16_CH17     (0x00000011U)
#define  MD_ADC_NCHS4_NS16_CH18     (0x00000012U)

#define  MD_ADC_NCHS4_NS15_CH0      (0x00000000U)
#define  MD_ADC_NCHS4_NS15_CH1      (0x00000001U)
#define  MD_ADC_NCHS4_NS15_CH2      (0x00000002U)
#define  MD_ADC_NCHS4_NS15_CH3      (0x00000003U)
#define  MD_ADC_NCHS4_NS15_CH4      (0x00000004U)
#define  MD_ADC_NCHS4_NS15_CH5      (0x00000005U)
#define  MD_ADC_NCHS4_NS15_CH6      (0x00000006U)
#define  MD_ADC_NCHS4_NS15_CH7      (0x00000007U)
#define  MD_ADC_NCHS4_NS15_CH8      (0x00000008U)
#define  MD_ADC_NCHS4_NS15_CH9      (0x00000009U)
#define  MD_ADC_NCHS4_NS15_CH10     (0x0000000AU)
#define  MD_ADC_NCHS4_NS15_CH11     (0x0000000BU)
#define  MD_ADC_NCHS4_NS15_CH12     (0x0000000CU)
#define  MD_ADC_NCHS4_NS15_CH13     (0x0000000DU)
#define  MD_ADC_NCHS4_NS15_CH14     (0x0000000EU)
#define  MD_ADC_NCHS4_NS15_CH15     (0x0000000FU)
#define  MD_ADC_NCHS4_NS15_CH16     (0x00000010U)
#define  MD_ADC_NCHS4_NS15_CH17     (0x00000011U)
#define  MD_ADC_NCHS4_NS15_CH18     (0x00000012U)

#define  MD_ADC_ICHS_IS4_CH0      (0x00000000U)
#define  MD_ADC_ICHS_IS4_CH1      (0x00000001U)
#define  MD_ADC_ICHS_IS4_CH2      (0x00000002U)
#define  MD_ADC_ICHS_IS4_CH3      (0x00000003U)
#define  MD_ADC_ICHS_IS4_CH4      (0x00000004U)
#define  MD_ADC_ICHS_IS4_CH5      (0x00000005U)
#define  MD_ADC_ICHS_IS4_CH6      (0x00000006U)
#define  MD_ADC_ICHS_IS4_CH7      (0x00000007U)
#define  MD_ADC_ICHS_IS4_CH8      (0x00000008U)
#define  MD_ADC_ICHS_IS4_CH9      (0x00000009U)
#define  MD_ADC_ICHS_IS4_CH10     (0x0000000AU)
#define  MD_ADC_ICHS_IS4_CH11     (0x0000000BU)
#define  MD_ADC_ICHS_IS4_CH12     (0x0000000CU)
#define  MD_ADC_ICHS_IS4_CH13     (0x0000000DU)
#define  MD_ADC_ICHS_IS4_CH14     (0x0000000EU)
#define  MD_ADC_ICHS_IS4_CH15     (0x0000000FU)
#define  MD_ADC_ICHS_IS4_CH16     (0x00000010U)
#define  MD_ADC_ICHS_IS4_CH17     (0x00000011U)
#define  MD_ADC_ICHS_IS4_CH18     (0x00000012U)

#define  MD_ADC_ICHS_IS3_CH0      (0x00000000U)
#define  MD_ADC_ICHS_IS3_CH1      (0x00000001U)
#define  MD_ADC_ICHS_IS3_CH2      (0x00000002U)
#define  MD_ADC_ICHS_IS3_CH3      (0x00000003U)
#define  MD_ADC_ICHS_IS3_CH4      (0x00000004U)
#define  MD_ADC_ICHS_IS3_CH5      (0x00000005U)
#define  MD_ADC_ICHS_IS3_CH6      (0x00000006U)
#define  MD_ADC_ICHS_IS3_CH7      (0x00000007U)
#define  MD_ADC_ICHS_IS3_CH8      (0x00000008U)
#define  MD_ADC_ICHS_IS3_CH9      (0x00000009U)
#define  MD_ADC_ICHS_IS3_CH10     (0x0000000AU)
#define  MD_ADC_ICHS_IS3_CH11     (0x0000000BU)
#define  MD_ADC_ICHS_IS3_CH12     (0x0000000CU)
#define  MD_ADC_ICHS_IS3_CH13     (0x0000000DU)
#define  MD_ADC_ICHS_IS3_CH14     (0x0000000EU)
#define  MD_ADC_ICHS_IS3_CH15     (0x0000000FU)
#define  MD_ADC_ICHS_IS3_CH16     (0x00000010U)
#define  MD_ADC_ICHS_IS3_CH17     (0x00000011U)
#define  MD_ADC_ICHS_IS3_CH18     (0x00000012U)

#define  MD_ADC_ICHS_IS2_CH0      (0x00000000U)
#define  MD_ADC_ICHS_IS2_CH1      (0x00000001U)
#define  MD_ADC_ICHS_IS2_CH2      (0x00000002U)
#define  MD_ADC_ICHS_IS2_CH3      (0x00000003U)
#define  MD_ADC_ICHS_IS2_CH4      (0x00000004U)
#define  MD_ADC_ICHS_IS2_CH5      (0x00000005U)
#define  MD_ADC_ICHS_IS2_CH6      (0x00000006U)
#define  MD_ADC_ICHS_IS2_CH7      (0x00000007U)
#define  MD_ADC_ICHS_IS2_CH8      (0x00000008U)
#define  MD_ADC_ICHS_IS2_CH9      (0x00000009U)
#define  MD_ADC_ICHS_IS2_CH10     (0x0000000AU)
#define  MD_ADC_ICHS_IS2_CH11     (0x0000000BU)
#define  MD_ADC_ICHS_IS2_CH12     (0x0000000CU)
#define  MD_ADC_ICHS_IS2_CH13     (0x0000000DU)
#define  MD_ADC_ICHS_IS2_CH14     (0x0000000EU)
#define  MD_ADC_ICHS_IS2_CH15     (0x0000000FU)
#define  MD_ADC_ICHS_IS2_CH16     (0x00000010U)
#define  MD_ADC_ICHS_IS2_CH17     (0x00000011U)
#define  MD_ADC_ICHS_IS2_CH18     (0x00000012U)

#define  MD_ADC_ICHS_IS1_CH0      (0x00000000U)
#define  MD_ADC_ICHS_IS1_CH1      (0x00000001U)
#define  MD_ADC_ICHS_IS1_CH2      (0x00000002U)
#define  MD_ADC_ICHS_IS1_CH3      (0x00000003U)
#define  MD_ADC_ICHS_IS1_CH4      (0x00000004U)
#define  MD_ADC_ICHS_IS1_CH5      (0x00000005U)
#define  MD_ADC_ICHS_IS1_CH6      (0x00000006U)
#define  MD_ADC_ICHS_IS1_CH7      (0x00000007U)
#define  MD_ADC_ICHS_IS1_CH8      (0x00000008U)
#define  MD_ADC_ICHS_IS1_CH9      (0x00000009U)
#define  MD_ADC_ICHS_IS1_CH10     (0x0000000AU)
#define  MD_ADC_ICHS_IS1_CH11     (0x0000000BU)
#define  MD_ADC_ICHS_IS1_CH12     (0x0000000CU)
#define  MD_ADC_ICHS_IS1_CH13     (0x0000000DU)
#define  MD_ADC_ICHS_IS1_CH14     (0x0000000EU)
#define  MD_ADC_ICHS_IS1_CH15     (0x0000000FU)
#define  MD_ADC_ICHS_IS1_CH16     (0x00000010U)
#define  MD_ADC_ICHS_IS1_CH17     (0x00000011U)
#define  MD_ADC_ICHS_IS1_CH18     (0x00000012U)

#define  MD_ADC_ICHS_IETS_DISABLE (0x00000000U)
#define  MD_ADC_ICHS_IETS_RISING  (0x00000001U)
#define  MD_ADC_ICHS_IETS_FALLING (0x00000002U)
#define  MD_ADC_ICHS_IETS_BOTH    (0x00000003U)

#define  MD_ADC_ICHS_IEXTSEL_AD16C4T1_CH4       (0x00000000U)
#define  MD_ADC_ICHS_IEXTSEL_AD16C4T1_TRGOUT    (0x00000001U)
#define  MD_ADC_ICHS_IEXTSEL_GP32C4T1_CH1       (0x00000002U)
#define  MD_ADC_ICHS_IEXTSEL_GP32C4T1_TRGOUT    (0x00000003U)
#define  MD_ADC_ICHS_IEXTSEL_GP16C4T1_CH2       (0x00000004U)
#define  MD_ADC_ICHS_IEXTSEL_GP16C4T1_CH3       (0x00000005U)
#define  MD_ADC_ICHS_IEXTSEL_GP16C4T1_CH4       (0x00000006U)
#define  MD_ADC_ICHS_IEXTSEL_GP16C4T2_CH1       (0x00000007U)
#define  MD_ADC_ICHS_IEXTSEL_GP16C4T2_CH2       (0x00000008U)
#define  MD_ADC_ICHS_IEXTSEL_GP16C4T2_CH3       (0x00000009U)
#define  MD_ADC_ICHS_IEXTSEL_GP16C4T2_TRGOUT    (0x0000000AU)
#define  MD_ADC_ICHS_IEXTSEL_GP16C4T3_CH4       (0x0000000BU)
#define  MD_ADC_ICHS_IEXTSEL_GP16C4T3_TRGOUT    (0x0000000CU)
#define  MD_ADC_ICHS_IEXTSEL_GP16C2T1_TRGOUT    (0x0000000DU)
#define  MD_ADC_ICHS_IEXTSEL_GP16C2T2_TRGOUT    (0x0000000EU)
#define  MD_ADC_ICHS_IEXTSEL_EXTI_TRG1          (0x0000000FU)

#define  MD_ADC_ICHS_ISL_1CON       (0x00000000U)
#define  MD_ADC_ICHS_ISL_2CON       (0x00000001U)
#define  MD_ADC_ICHS_ISL_3CON       (0x00000002U)
#define  MD_ADC_ICHS_ISL_4CON       (0x00000003U)

#define  MD_ADC_OFF1_OFFCH_CH0      (0x00000000U)
#define  MD_ADC_OFF1_OFFCH_CH1      (0x00000001U)
#define  MD_ADC_OFF1_OFFCH_CH2      (0x00000002U)
#define  MD_ADC_OFF1_OFFCH_CH3      (0x00000003U)
#define  MD_ADC_OFF1_OFFCH_CH4      (0x00000004U)
#define  MD_ADC_OFF1_OFFCH_CH5      (0x00000005U)
#define  MD_ADC_OFF1_OFFCH_CH6      (0x00000006U)
#define  MD_ADC_OFF1_OFFCH_CH7      (0x00000007U)
#define  MD_ADC_OFF1_OFFCH_CH8      (0x00000008U)
#define  MD_ADC_OFF1_OFFCH_CH9      (0x00000009U)
#define  MD_ADC_OFF1_OFFCH_CH10     (0x0000000AU)
#define  MD_ADC_OFF1_OFFCH_CH11     (0x0000000BU)
#define  MD_ADC_OFF1_OFFCH_CH12     (0x0000000CU)
#define  MD_ADC_OFF1_OFFCH_CH13     (0x0000000DU)
#define  MD_ADC_OFF1_OFFCH_CH14     (0x0000000EU)
#define  MD_ADC_OFF1_OFFCH_CH15     (0x0000000FU)
#define  MD_ADC_OFF1_OFFCH_CH16     (0x00000010U)
#define  MD_ADC_OFF1_OFFCH_CH17     (0x00000011U)
#define  MD_ADC_OFF1_OFFCH_CH18     (0x00000012U)

#define  MD_ADC_OFF1_OFFPEN_NEGATIVE        (0x00000000U)
#define  MD_ADC_OFF1_OFFPEN_POSITIVE        (0x00000001U)

#define  MD_ADC_OFF2_OFFCH_CH0      (0x00000000U)
#define  MD_ADC_OFF2_OFFCH_CH1      (0x00000001U)
#define  MD_ADC_OFF2_OFFCH_CH2      (0x00000002U)
#define  MD_ADC_OFF2_OFFCH_CH3      (0x00000003U)
#define  MD_ADC_OFF2_OFFCH_CH4      (0x00000004U)
#define  MD_ADC_OFF2_OFFCH_CH5      (0x00000005U)
#define  MD_ADC_OFF2_OFFCH_CH6      (0x00000006U)
#define  MD_ADC_OFF2_OFFCH_CH7      (0x00000007U)
#define  MD_ADC_OFF2_OFFCH_CH8      (0x00000008U)
#define  MD_ADC_OFF2_OFFCH_CH9      (0x00000009U)
#define  MD_ADC_OFF2_OFFCH_CH10     (0x0000000AU)
#define  MD_ADC_OFF2_OFFCH_CH11     (0x0000000BU)
#define  MD_ADC_OFF2_OFFCH_CH12     (0x0000000CU)
#define  MD_ADC_OFF2_OFFCH_CH13     (0x0000000DU)
#define  MD_ADC_OFF2_OFFCH_CH14     (0x0000000EU)
#define  MD_ADC_OFF2_OFFCH_CH15     (0x0000000FU)
#define  MD_ADC_OFF2_OFFCH_CH16     (0x00000010U)
#define  MD_ADC_OFF2_OFFCH_CH17     (0x00000011U)
#define  MD_ADC_OFF2_OFFCH_CH18     (0x00000012U)

#define  MD_ADC_OFF2_OFFPEN_NEGATIVE        (0x00000000U)
#define  MD_ADC_OFF2_OFFPEN_POSITIVE        (0x00000001U)

#define  MD_ADC_OFF3_OFFCH_CH0      (0x00000000U)
#define  MD_ADC_OFF3_OFFCH_CH1      (0x00000001U)
#define  MD_ADC_OFF3_OFFCH_CH2      (0x00000002U)
#define  MD_ADC_OFF3_OFFCH_CH3      (0x00000003U)
#define  MD_ADC_OFF3_OFFCH_CH4      (0x00000004U)
#define  MD_ADC_OFF3_OFFCH_CH5      (0x00000005U)
#define  MD_ADC_OFF3_OFFCH_CH6      (0x00000006U)
#define  MD_ADC_OFF3_OFFCH_CH7      (0x00000007U)
#define  MD_ADC_OFF3_OFFCH_CH8      (0x00000008U)
#define  MD_ADC_OFF3_OFFCH_CH9      (0x00000009U)
#define  MD_ADC_OFF3_OFFCH_CH10     (0x0000000AU)
#define  MD_ADC_OFF3_OFFCH_CH11     (0x0000000BU)
#define  MD_ADC_OFF3_OFFCH_CH12     (0x0000000CU)
#define  MD_ADC_OFF3_OFFCH_CH13     (0x0000000DU)
#define  MD_ADC_OFF3_OFFCH_CH14     (0x0000000EU)
#define  MD_ADC_OFF3_OFFCH_CH15     (0x0000000FU)
#define  MD_ADC_OFF3_OFFCH_CH16     (0x00000010U)
#define  MD_ADC_OFF3_OFFCH_CH17     (0x00000011U)
#define  MD_ADC_OFF3_OFFCH_CH18     (0x00000012U)

#define  MD_ADC_OFF3_OFFPEN_NEGATIVE        (0x00000000U)
#define  MD_ADC_OFF3_OFFPEN_POSITIVE        (0x00000001U)

#define  MD_ADC_OFF4_OFFCH_CH0      (0x00000000U)
#define  MD_ADC_OFF4_OFFCH_CH1      (0x00000001U)
#define  MD_ADC_OFF4_OFFCH_CH2      (0x00000002U)
#define  MD_ADC_OFF4_OFFCH_CH3      (0x00000003U)
#define  MD_ADC_OFF4_OFFCH_CH4      (0x00000004U)
#define  MD_ADC_OFF4_OFFCH_CH5      (0x00000005U)
#define  MD_ADC_OFF4_OFFCH_CH6      (0x00000006U)
#define  MD_ADC_OFF4_OFFCH_CH7      (0x00000007U)
#define  MD_ADC_OFF4_OFFCH_CH8      (0x00000008U)
#define  MD_ADC_OFF4_OFFCH_CH9      (0x00000009U)
#define  MD_ADC_OFF4_OFFCH_CH10     (0x0000000AU)
#define  MD_ADC_OFF4_OFFCH_CH11     (0x0000000BU)
#define  MD_ADC_OFF4_OFFCH_CH12     (0x0000000CU)
#define  MD_ADC_OFF4_OFFCH_CH13     (0x0000000DU)
#define  MD_ADC_OFF4_OFFCH_CH14     (0x0000000EU)
#define  MD_ADC_OFF4_OFFCH_CH15     (0x0000000FU)
#define  MD_ADC_OFF4_OFFCH_CH16     (0x00000010U)
#define  MD_ADC_OFF4_OFFCH_CH17     (0x00000011U)
#define  MD_ADC_OFF4_OFFCH_CH18     (0x00000012U)

#define  MD_ADC_OFF4_OFFPEN_NEGATIVE        (0x00000000U)
#define  MD_ADC_OFF4_OFFPEN_POSITIVE        (0x00000001U)

#define  MD_ADC_CCR_REFINTS_4DIV16        (0x00000000U)
#define  MD_ADC_CCR_REFINTS_8DIV16        (0x00000001U)
#define  MD_ADC_CCR_REFINTS_12DIV16       (0x00000002U)
#define  MD_ADC_CCR_REFINTS_16DIV16       (0x00000003U)
#define  MD_ADC_CCR_REFINTS_1DIV16        (0x00000004U)
#define  MD_ADC_CCR_REFINTS_15DIV16       (0x00000005U)


#define  MD_ADC_MODE_NCHS        0x00000000U
#define  MD_ADC_MODE_ICHS        0x00000001U

#define  MD_ADC_CHANNEL_0       0x0U
#define  MD_ADC_CHANNEL_1       0x1U
#define  MD_ADC_CHANNEL_2       0x2U
#define  MD_ADC_CHANNEL_3       0x3U
#define  MD_ADC_CHANNEL_4       0x4U
#define  MD_ADC_CHANNEL_5       0x5U
#define  MD_ADC_CHANNEL_6       0x6U
#define  MD_ADC_CHANNEL_7       0x7U
#define  MD_ADC_CHANNEL_8       0x8U
#define  MD_ADC_CHANNEL_9       0x9U
#define  MD_ADC_CHANNEL_10      0xAU
#define  MD_ADC_CHANNEL_11      0xBU
#define  MD_ADC_CHANNEL_12      0xCU
#define  MD_ADC_CHANNEL_13      0xDU
#define  MD_ADC_CHANNEL_14      0xEU
#define  MD_ADC_CHANNEL_15      0xFU
#define  MD_ADC_CHANNEL_16      0x10U
#define  MD_ADC_CHANNEL_17      0x11U
#define  MD_ADC_CHANNEL_18      0x12U

//ADC calibration choose
#define MD_ADC_CALIBRATION 0x1U
#define MD_ADC_NONE_CALIBRATION     0x2U

//ADC option byte address
#define ADC_CALIBRATION_ADDR 0x874

/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions ADC Public Functions
  * @{
  */

/** @defgroup MD_ADC_Public_Functions_Group2 IER
  * @{
  */

/**
  * @brief  Set ADC_IER Register
  * @param  ADCx ADC Instance
  * @param  ier
  */
__STATIC_INLINE void md_adc_set_ier(ADC_TypeDef *ADCx, uint32_t ier)
{
    WRITE_REG(ADCx->IER, ier);
}

/**
  * @brief  ADC Timeout Interrupt Enable.
  * @note   User can set this bit to enable timeout Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_enable_it_timeout(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_TO);
}

/**
  * @brief  Analog Watchdog Interrupt Enable.
  * @note   User can set this bit to enable Analog Watchdog Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_enable_it_awd(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_AWDF);
}

/**
  * @brief  End of Injected Sequence of Conversions Interrupt Enable.
  * @note   User can set this bit to enable End of Injected Sequence of Conversions Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_enable_it_inj_sequence_done(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_ISE);
}

/**
  * @brief  End of Injected Conversion Interrupt Enable.
  * @note   User can set this bit to enable End of Injected Conversion Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_enable_it_inj_conversion_done(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_ICHE);
}

/**
  * @brief  ADC Overrun Interrupt Enable.
  * @note   User can set this bit to enable ADC Overrun Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_enable_it_overflow(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_OVR);
}

/**
  * @brief  End of Regular Sequence of Conversions Interrupt Enable.
  * @note   User can set this bit to enable End of Regular Sequence of Conversions Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_enable_it_normal_sequence_done(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_NSE);
}

/**
  * @brief  End of Regular Conversion Interrupt Enable.
  * @note   User can set this bit to enable End of Regular Conversion Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_enable_it_normal_conversion_done(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_NCHE);
}

/**
  * @brief  End of Sampling Flag Interrupt Enable for Regular Conversions.
  * @note   User can set this bit to enable End of Sampling Flag Interrupt Enable for Regular Conversions Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_enable_it_sample_done(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_SMPE);
}

/**
  * @brief  ADC Ready Interrupt Enable.
  * @note   User can set this bit to enable ADC Ready Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_enable_it_adc_ready(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_ARDY);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group3 IDR
  * @{
  */
/**
  * @brief  Set ADC_IDR Register
  * @param  ADCx ADC Instance
  * @param  ier
  */
__STATIC_INLINE void md_adc_set_idr(ADC_TypeDef *ADCx, uint32_t idr)
{
    WRITE_REG(ADCx->IDR, idr);
}

/**
  * @brief  ADC Timeout Interrupt Disable.
  * @note   User can set this bit to Disable timeout Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_disable_it_timeout(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IDR, ADC_IDR_TO);
}

/**
  * @brief  Analog Watchdog Interrupt Disable.
  * @note   User can set this bit to Disable Analog Watchdog Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_disable_it_awd(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IDR, ADC_IDR_AWDF);
}

/**
  * @brief  End of Injected Sequence of Conversions Interrupt Disable.
  * @note   User can set this bit to Disable End of Injected Sequence of Conversions Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_disable_it_inj_sequence_done(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IDR, ADC_IDR_ISE);
}

/**
  * @brief  End of Injected Conversion Interrupt Disable.
  * @note   User can set this bit to Disable End of Injected Conversion Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_disable_it_inj_conversion_done(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IDR, ADC_IDR_ICHE);
}

/**
  * @brief  ADC Overrun Interrupt Disable.
  * @note   User can set this bit to Disable ADC Overrun Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_disable_it_overflow(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IDR, ADC_IDR_OVR);
}

/**
  * @brief  End of Regular Sequence of Conversions Interrupt Disable.
  * @note   User can set this bit to Disable End of Regular Sequence of Conversions Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_disable_it_normal_sequence_done(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IDR, ADC_IDR_NSE);
}

/**
  * @brief  End of Regular Conversion Interrupt Disable.
  * @note   User can set this bit to Disable End of Regular Conversion Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_disable_it_normal_conversion_done(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IDR, ADC_IDR_NCHE);
}

/**
  * @brief  End of Sampling Flag Interrupt Disable for Regular Conversions.
  * @note   User can set this bit to Disable End of Sampling Flag Interrupt Disable for Regular Conversions function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_disable_it_sample_done(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IDR, ADC_IDR_SMPE);
}

/**
  * @brief  ADC Ready Interrupt Disable.
  * @note   User can set this bit to Disable ADC Ready Interrupt function.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_disable_it_adc_ready(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->IDR, ADC_IDR_ARDY);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group4 IVS
  * @{
  */
/**
  * @brief  Get ADC_IVS Register
  * @param  ADCx ADC Instance
  * @param  ier
  */
__STATIC_INLINE uint32_t md_adc_get_ivs(ADC_TypeDef *ADCx)
{
    return (uint32_t)READ_REG(ADCx->IVS);
}

/**
  * @brief  Check if ADC Timeout Interrupt is Enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_it_timeout(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IVS, ADC_IVS_TO) == (ADC_IVS_TO));
}

/**
  * @brief  Check if ADC Analog Watchdog Interrupt is Enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_it_awd(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IVS, ADC_IVS_AWDF) == (ADC_IVS_AWDF));
}

/**
  * @brief  Check if ADC End of Injected Sequence of Conversions Interrupt is Enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_it_inj_sequence_done(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IVS, ADC_IVS_ISE) == (ADC_IVS_ISE));
}

/**
  * @brief  Check if ADC End of Injected Conversion Interrupt is Enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_it_inj_conversion_done(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IVS, ADC_IVS_ICHE) == (ADC_IVS_ICHE));
}

/**
  * @brief  Check if ADC ADC Overrun Interrupt is Enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_it_overflow(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IVS, ADC_IVS_OVR) == (ADC_IVS_OVR));
}

/**
  * @brief  Check if ADC ADC End of Regular Sequence of Conversions Interrupt is Enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_it_normal_sequence_done(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IVS, ADC_IVS_NSE) == (ADC_IVS_NSE));
}

/**
  * @brief  Check if ADC End of Regular Conversion Interrupt is Enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_it_normal_conversion_done(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IVS, ADC_IVS_NCHE) == (ADC_IVS_NCHE));
}

/**
  * @brief  Check if ADC End of Sampling Flag Interrupt is Enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_it_sample_done(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IVS, ADC_IVS_SMPE) == (ADC_IVS_SMPE));
}

/**
  * @brief  Check if ADC Ready Interrupt is Enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_it_adc_ready(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IVS, ADC_IVS_ARDY) == (ADC_IVS_ARDY));
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group5 RIF
  * @{
  */

/**
  * @brief  Get ADC_RIF Register
  * @param  ADCx ADC Instance
  * @param  ier
  */
__STATIC_INLINE uint32_t md_adc_get_rif(ADC_TypeDef *ADCx)
{
    return (uint32_t)READ_REG(ADCx->RIF);
}

/**
  * @brief  Check Timeout Interrupt Flag Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_active_flag_timeout(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->RIF, ADC_RIF_TO) == (ADC_RIF_TO));
}

/**
  * @brief  Check Analog Watchdog Interrupt Flag Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_active_flag_awd(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->RIF, ADC_RIF_AWDF) == (ADC_RIF_AWDF));
}

/**
  * @brief  Check End of Injected Sequence of Conversions Interrupt Flag Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_active_flag_inj_sequence_done(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->RIF, ADC_RIF_ISE) == (ADC_RIF_ISE));
}

/**
  * @brief  Check End of Injected Conversion Interrupt Flag Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_active_flag_inj_conversion_done(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->RIF, ADC_RIF_ICHE) == (ADC_RIF_ICHE));
}

/**
  * @brief  Check ADC Overrun Interrupt Flag Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_active_flag_overflow(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->RIF, ADC_RIF_OVR) == (ADC_RIF_OVR));
}

/**
  * @brief  Check End of Regular Sequence of Conversions Interrupt Flag Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_active_flag_normal_sequence_done(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->RIF, ADC_RIF_NSE) == (ADC_RIF_NSE));
}

/**
  * @brief  Check End of Regular Conversion Interrupt Flag Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_active_flag_normal_conversion_done(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->RIF, ADC_RIF_NCHE) == (ADC_RIF_NCHE));
}

/**
  * @brief  Check End of Sampling Flag Interrupt Flag Status for Regular Conversions.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_active_flag_sample_done(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->RIF, ADC_RIF_SMPE) == (ADC_RIF_SMPE));
}

/**
  * @brief  Check ADC Ready Interrupt Flag Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_active_flag_adc_ready(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->RIF, ADC_RIF_ARDY) == (ADC_RIF_ARDY));
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group6 IFM
  * @{
  */
/**
  * @brief  Get ADC_IFM Register
  * @param  ADCx ADC Instance
  * @param  ier
  */
__STATIC_INLINE uint32_t md_adc_get_ifm(ADC_TypeDef *ADCx)
{
    return (uint32_t)READ_REG(ADCx->IFM);
}

/**
  * @brief  Check Timeout Interrupt Flag Masked Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_masked_it_timeout(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IFM, ADC_IFM_TO) == (ADC_IFM_TO));
}

/**
  * @brief  Check Analog Watchdog Interrupt Flag Masked Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_masked_it_awd(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IFM, ADC_IFM_AWDF) == (ADC_IFM_AWDF));
}

/**
  * @brief  Check End of Injected Sequence of Conversions Interrupt Flag Masked Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_masked_it_inj_sequence_done(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IFM, ADC_IFM_ISE) == (ADC_IFM_ISE));
}

/**
  * @brief  Check End of Injected Conversion Interrupt Flag Masked Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_masked_it_inj_conversion_done(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IFM, ADC_IFM_ICHE) == (ADC_IFM_ICHE));
}

/**
  * @brief  Check ADC Overrun Interrupt Flag Masked Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_masked_it_overflow(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IFM, ADC_IFM_OVR) == (ADC_IFM_OVR));
}

/**
  * @brief  Check End of Regular Sequence of Conversions Interrupt Flag Masked Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_masked_it_normal_sequence_done(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IFM, ADC_IFM_NSE) == (ADC_IFM_NSE));
}

/**
  * @brief  Check End of Regular Conversion Interrupt Flag Masked Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_masked_it_normal_conversion_done(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IFM, ADC_IFM_NCHE) == (ADC_IFM_NCHE));
}

/**
  * @brief  Check End of Sampling Flag Interrupt Flag Masked Status for Regular Conversions.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_masked_it_sample_done(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IFM, ADC_IFM_SMPE) == (ADC_IFM_SMPE));
}

/**
  * @brief  Check ADC Ready Interrupt Flag Masked Status.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_masked_it_adc_ready(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->IFM, ADC_IFM_ARDY) == (ADC_IFM_ARDY));
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group7 ICR
  * @{
  */
/**
  * @brief  Set ADC_ICR Register
  * @param  ADCx ADC Instance
  * @param  ier
  */
__STATIC_INLINE void md_adc_set_icr(ADC_TypeDef *ADCx, uint32_t icr)
{
    WRITE_REG(ADCx->ICR, icr);
}

/**
  * @brief  ADC Timeout Interrupt Clear.
  * @note   User can set this bit to clear timeout interrupt status.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_clear_it_timeout(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->ICR, ADC_ICR_TO);
}

/**
  * @brief  ADC Analog Watchdog Interrupt Clear.
  * @note   User can set this bit to clear Analog Watchdog interrupt status.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_clear_it_awd(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->ICR, ADC_ICR_AWDF);
}

/**
  * @brief  ADC End of Injected Sequence of Conversions Interrupt Clear.
  * @note   User can set this bit to clear End of Injected Sequence of Conversions interrupt status.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_clear_it_inj_sequence_done(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->ICR, ADC_ICR_ISE);
}

/**
  * @brief  ADC End of Injected Conversion Interrupt Clear.
  * @note   User can set this bit to clear End of Injected Conversion interrupt status.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_clear_it_inj_conversion_done(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->ICR, ADC_ICR_ICHE);
}

/**
  * @brief  ADC Overrun Interrupt Clear.
  * @note   User can set this bit to clear Overrun interrupt status.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_clear_it_overflow(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->ICR, ADC_ICR_OVR);
}

/**
  * @brief  ADC End of Regular Sequence of Conversions Interrupt Clear.
  * @note   User can set this bit to clear End of Regular Sequence of Conversions interrupt status.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_clear_it_normal_sequence_done(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->ICR, ADC_ICR_NSE);
}

/**
  * @brief  ADC End of Regular Conversion Interrupt Clear.
  * @note   User can set this bit to clear End of Regular Conversion interrupt status.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_clear_it_normal_conversion_done(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->ICR, ADC_ICR_NCHE);
}

/**
  * @brief  ADC End of Sampling Flag Interrupt Clear for Regular Conversions.
  * @note   User can set this bit to clear End of Sampling Flag status.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_clear_it_sample_done(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->ICR, ADC_ICR_SMPE);
}

/**
  * @brief  ADC Ready Interrupt Clear.
  * @note   User can set this bit to clear Ready interrupt status.
  * @param  ADCx ADC Instance
  * @retval None.
  */
__STATIC_INLINE void md_adc_clear_it_adc_ready(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->ICR, ADC_ICR_ARDY);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group8 CON
  * @{
  */
/**
  * @brief  Set ADC_CON Register
  * @param  ADCx ADC Instance
  * @param  ier
  */
__STATIC_INLINE void md_adc_set_con(ADC_TypeDef *ADCx, uint32_t con)
{
    WRITE_REG(ADCx->CON, con);
}

/**
  * @brief  Get ADC_CON Register
  * @param  ADCx ADC Instance
  */
__STATIC_INLINE uint32_t md_adc_get_con(ADC_TypeDef *ADCx)
{
    return (uint32_t)READ_REG(ADCx->CON);
}

/**
  * @brief  Set ADC calibration.
  * @param  ADCx ADC Instance
  * @param  adcal
            @arg @ref MD_ADC_CON_ADCAL_CALIBRATION_COMPLETE
            @arg @ref MD_ADC_CON_ADCAL_CALIBRATION
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_calibration(ADC_TypeDef *ADCx, uint32_t adcal)
{
    MODIFY_REG(ADCx->CON, ADC_CON_ADCAL, adcal << ADC_CON_ADCAL_POS);
}

/**
  * @brief  Get ADC calibration.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CON_ADCAL_CALIBRATION_COMPLETE
            @arg @ref MD_ADC_CON_ADCAL_CALIBRATION
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_calibration(ADC_TypeDef *ADCx)
{
    return ((READ_BIT(ADCx->CON, ADC_CON_ADCAL)) == (ADC_CON_ADCAL));
}

/**
  * @brief  Set ADC stop of injected conversion command.
  * @param  ADCx ADC Instance
  * @param  istpc
            @arg @ref MD_ADC_CON_ISTPC_NOSTOP_INJECTED
            @arg @ref MD_ADC_CON_ISTPC_STOP_INJECTED
  * @retval None
  */
__STATIC_INLINE void md_adc_set_stop_inj(ADC_TypeDef *ADCx, uint32_t istpc)
{
    MODIFY_REG(ADCx->CON, ADC_CON_ISTPC, istpc << ADC_CON_ISTPC_POS);
}

/**
  * @brief  Get ADC stop of injected conversion command.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CON_ISTPC_NOSTOP_INJECTED
            @arg @ref MD_ADC_CON_ISTPC_STOP_INJECTED
  */
__STATIC_INLINE uint32_t md_adc_get_stop_inj(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CON, ADC_CON_ISTPC)) >> ADC_CON_ISTPC_POS);
}

/**
  * @brief  Set ADC stop of regular conversion command.
  * @param  ADCx ADC Instance
  * @param  nstpc
            @arg @ref MD_ADC_CON_NSTPC_NOSTOP_REGULAR
            @arg @ref MD_ADC_CON_NSTPC_STOP_REGULAR
  * @retval None
  */
__STATIC_INLINE void md_adc_set_stop_normal(ADC_TypeDef *ADCx, uint32_t nstpc)
{
    MODIFY_REG(ADCx->CON, ADC_CON_NSTPC, nstpc << ADC_CON_NSTPC_POS);
}

/**
  * @brief  Get ADC stop of regular conversion command.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CON_NSTPC_NOSTOP_REGULAR
            @arg @ref MD_ADC_CON_NSTPC_STOP_REGULAR
  */
__STATIC_INLINE uint32_t md_adc_get_stop_normal(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CON, ADC_CON_NSTPC)) >> ADC_CON_NSTPC_POS);
}

/**
  * @brief  Set ADC start of injected conversion.
  * @param  ADCx ADC Instance
  * @param  istart
            @arg @ref MD_ADC_CON_ISTART_NOADC_INJECTED
            @arg @ref MD_ADC_CON_ISTART_START_INJECTED
  * @retval None
  */
__STATIC_INLINE void md_adc_set_start_inj(ADC_TypeDef *ADCx, uint32_t istart)
{
    MODIFY_REG(ADCx->CON, ADC_CON_ISTART, istart << ADC_CON_ISTART_POS);
}

/**
  * @brief  Get ADC start of injected conversion.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CON_ISTART_NOADC_INJECTED
            @arg @ref MD_ADC_CON_ISTART_START_INJECTED
  */
__STATIC_INLINE uint32_t md_adc_get_start_inj(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CON, ADC_CON_ISTART)));
}

/**
  * @brief  Set ADC start of regular conversion.
  * @param  ADCx ADC Instance
  * @param  nstart
            @arg @ref MD_ADC_CON_NSTART_NOADC_REGULAR
            @arg @ref MD_ADC_CON_NSTART_START_REGULAR
  * @retval None
  */
__STATIC_INLINE void md_adc_set_start_normal(ADC_TypeDef *ADCx, uint32_t nstart)
{
    MODIFY_REG(ADCx->CON, ADC_CON_NSTART, nstart << ADC_CON_NSTART_POS);
}

/**
  * @brief  Get ADC start of regular conversion.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CON_NSTART_NOADC_REGULAR
            @arg @ref MD_ADC_CON_NSTART_START_REGULAR
  */
__STATIC_INLINE uint32_t md_adc_get_start_normal(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CON, ADC_CON_NSTART)) >> ADC_CON_NSTART_POS);
}

/**
  * @brief  Set ADC disable command.
  * @param  ADCx ADC Instance
  * @param  adcdis
            @arg @ref MD_ADC_CON_ADCDIS_NODISABLE
            @arg @ref MD_ADC_CON_ADCDIS_DISABLE
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_adcpower(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->CON, ADC_CON_ADCDIS);
}

/**
  * @brief  Set ADC enable control.
  * @param  ADCx ADC Instance
  * @param  adcen
            @arg @ref MD_ADC_CON_ADCEN_DISABLE
            @arg @ref MD_ADC_CON_ADCEN_ENABLE
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_adcpower(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->CON, ADC_CON_ADCEN);
}

/**
  * @brief  Get ADC enable control.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CON_ADCEN_DISABLE
            @arg @ref MD_ADC_CON_ADCEN_ENABLE
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_adcpower(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->CON, ADC_CON_ADCEN) == (ADC_CON_ADCEN));
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group9 CFG
  * @{
  */
/**
  * @brief  Set ADC_CFG Register
  * @param  ADCx ADC Instance
  * @param  ier
  */
__STATIC_INLINE void md_adc_set_cfg(ADC_TypeDef *ADCx, uint32_t cfg)
{
    WRITE_REG(ADCx->CFG, cfg);
}

/**
  * @brief  Get ADC_CFG Register
  * @param  ADCx ADC Instance
  */
__STATIC_INLINE uint32_t md_adc_get_cfg(ADC_TypeDef *ADCx)
{
    return (uint32_t)READ_REG(ADCx->CFG);
}

/**
  * @brief  Set Analog watchdog channel selectione.
  * @param  ADCx ADC Instance
  * @param  awdch
            @arg @ref MD_ADC_CFG_AWDCH_CH0
            @arg @ref MD_ADC_CFG_AWDCH_CH1
            @arg @ref MD_ADC_CFG_AWDCH_CH2
            @arg @ref MD_ADC_CFG_AWDCH_CH3
            @arg @ref MD_ADC_CFG_AWDCH_CH4
            @arg @ref MD_ADC_CFG_AWDCH_CH5
            @arg @ref MD_ADC_CFG_AWDCH_CH6
            @arg @ref MD_ADC_CFG_AWDCH_CH7
            @arg @ref MD_ADC_CFG_AWDCH_CH8
            @arg @ref MD_ADC_CFG_AWDCH_CH9
            @arg @ref MD_ADC_CFG_AWDCH_CH10
            @arg @ref MD_ADC_CFG_AWDCH_CH11
            @arg @ref MD_ADC_CFG_AWDCH_CH12
            @arg @ref MD_ADC_CFG_AWDCH_CH13
            @arg @ref MD_ADC_CFG_AWDCH_CH14
            @arg @ref MD_ADC_CFG_AWDCH_CH15
            @arg @ref MD_ADC_CFG_AWDCH_CH16
            @arg @ref MD_ADC_CFG_AWDCH_CH17
            @arg @ref MD_ADC_CFG_AWDCH_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_awd_monit_channel(ADC_TypeDef *ADCx, uint32_t awdch)
{
    MODIFY_REG(ADCx->CFG, ADC_CFG_AWDCH, awdch << ADC_CFG_AWDCH_POSS);
}

/**
  * @brief  Get Analog watchdog channel selectione.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CFG_AWDCH_CH0
            @arg @ref MD_ADC_CFG_AWDCH_CH1
            @arg @ref MD_ADC_CFG_AWDCH_CH2
            @arg @ref MD_ADC_CFG_AWDCH_CH3
            @arg @ref MD_ADC_CFG_AWDCH_CH4
            @arg @ref MD_ADC_CFG_AWDCH_CH5
            @arg @ref MD_ADC_CFG_AWDCH_CH6
            @arg @ref MD_ADC_CFG_AWDCH_CH7
            @arg @ref MD_ADC_CFG_AWDCH_CH8
            @arg @ref MD_ADC_CFG_AWDCH_CH9
            @arg @ref MD_ADC_CFG_AWDCH_CH10
            @arg @ref MD_ADC_CFG_AWDCH_CH11
            @arg @ref MD_ADC_CFG_AWDCH_CH12
            @arg @ref MD_ADC_CFG_AWDCH_CH13
            @arg @ref MD_ADC_CFG_AWDCH_CH14
            @arg @ref MD_ADC_CFG_AWDCH_CH15
            @arg @ref MD_ADC_CFG_AWDCH_CH16
            @arg @ref MD_ADC_CFG_AWDCH_CH17
            @arg @ref MD_ADC_CFG_AWDCH_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_awd_monit_channel(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CFG, ADC_CFG_AWDCH)) >> ADC_CFG_AWDCH_POSS);
}

/**
  * @brief  ADC Automatic injected group conversion Enable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_inj_auto_convert(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->CFG, ADC_CFG_IAUTO);
}

/**
  * @brief  ADC Automatic injected group conversion Disable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_inj_auto_convert(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->CFG, ADC_CFG_IAUTO);
}

/**
  * @brief  Check if ADC Automatic injected group conversion is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_inj_auto_convert(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->CFG, ADC_CFG_IAUTO) == (ADC_CFG_IAUTO));
}

/**
  * @brief  ADC Analog watchdog enable on injected channels.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_inj_awd(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->CFG, ADC_CFG_IAWDEN);
}

/**
  * @brief  ADC Analog watchdog disable on injected channels.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_inj_awd(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->CFG, ADC_CFG_IAWDEN);
}

/**
  * @brief  Check if ADC Analog watchdog enable on injected channels is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_inj_awd(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->CFG, ADC_CFG_IAWDEN) == (ADC_CFG_IAWDEN));
}

/**
  * @brief  ADC Analog watchdog enable on regular channels.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_normal_awd(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->CFG, ADC_CFG_NAWDEN);
}

/**
  * @brief  ADC Analog watchdog disable on regular channels.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_normal_awd(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->CFG, ADC_CFG_NAWDEN);
}

/**
  * @brief  Check if ADC Analog watchdog enable on regular channels is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_normal_awd(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->CFG, ADC_CFG_NAWDEN) == (ADC_CFG_NAWDEN));
}

/**
  * @brief  Set the watchdog on a single channel or on all channels.
  * @param  ADCx ADC Instance
  * @param  awdsgl
            @arg @ref MD_ADC_CFG_AWDSGL_ALL_CH
            @arg @ref MD_ADC_CFG_AWDSGL_SINGLE_CH
  * @retval None
  */
__STATIC_INLINE void md_adc_set_awd_singlechannel(ADC_TypeDef *ADCx, uint32_t awdsgl)
{
    MODIFY_REG(ADCx->CFG, ADC_CFG_AWDSGL, awdsgl << ADC_CFG_AWDSGL_POS);
}

/**
  * @brief  Get Enable the watchdog on a single channel or on all channels.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CFG_AWDSGL_ALL_CH
            @arg @ref MD_ADC_CFG_AWDSGL_SINGLE_CH
  */
__STATIC_INLINE uint32_t md_adc_get_awd_singlechannel(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CFG, ADC_CFG_AWDSGL)) >> ADC_CFG_AWDSGL_POS);
}

/**
  * @brief  Discontinuous mode on injected channels Enable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_inj_discontinous(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->CFG, ADC_CFG_ICHDCEN);
}

/**
  * @brief  Discontinuous mode on injected channels Disable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_inj_discontinous(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->CFG, ADC_CFG_ICHDCEN);
}

/**
  * @brief  Check if Discontinuous mode on injected channels is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_inj_discontinous(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->CFG, ADC_CFG_ICHDCEN) == (ADC_CFG_ICHDCEN));
}

/**
  * @brief  Set Discontinuous mode channel number.
  * @param  ADCx ADC Instance
  * @param  etrgn
            @arg @ref MD_ADC_CFG_ETRGN_1CH
            @arg @ref MD_ADC_CFG_ETRGN_2CH
            @arg @ref MD_ADC_CFG_ETRGN_3CH
            @arg @ref MD_ADC_CFG_ETRGN_4CH
            @arg @ref MD_ADC_CFG_ETRGN_5CH
            @arg @ref MD_ADC_CFG_ETRGN_6CH
            @arg @ref MD_ADC_CFG_ETRGN_7CH
            @arg @ref MD_ADC_CFG_ETRGN_8CH
  * @retval None
  */
__STATIC_INLINE void md_adc_set_external_trigger_amount(ADC_TypeDef *ADCx, uint32_t etrgn)
{
    MODIFY_REG(ADCx->CFG, ADC_CFG_ETRGN, etrgn << ADC_CFG_ETRGN_POSS);
}

/**
  * @brief  Get Discontinuous mode channel number.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CFG_ETRGN_1CH
            @arg @ref MD_ADC_CFG_ETRGN_2CH
            @arg @ref MD_ADC_CFG_ETRGN_3CH
            @arg @ref MD_ADC_CFG_ETRGN_4CH
            @arg @ref MD_ADC_CFG_ETRGN_5CH
            @arg @ref MD_ADC_CFG_ETRGN_6CH
            @arg @ref MD_ADC_CFG_ETRGN_7CH
            @arg @ref MD_ADC_CFG_ETRGN_8CH
  */
__STATIC_INLINE uint32_t md_adc_get_external_trigger_amount(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CFG, ADC_CFG_ETRGN)) >> ADC_CFG_ETRGN_POSS);
}

/**
  * @brief  Discontinuous mode for regular channels Enable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_normal_discontinous(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->CFG, ADC_CFG_NCHDCEN);
}

/**
  * @brief  Discontinuous mode for regular channels Disable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_normal_discontinous(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->CFG, ADC_CFG_NCHDCEN);
}

/**
  * @brief  Check if Discontinuous mode for regular channels is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_normal_discontinous(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->CFG, ADC_CFG_NCHDCEN) == (ADC_CFG_NCHDCEN));
}

/**
  * @brief  Auto Off Transition Mode Enable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_auto_off_transition_mode(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->CFG, ADC_CFG_AUTOFF);
}

/**
  * @brief  Auto Off Transition Mode Disable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_auto_off_transition_mode(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->CFG, ADC_CFG_AUTOFF);
}

/**
  * @brief  Check if Auto Off Transition Mode is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_auto_off_transition_mode(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->CFG, ADC_CFG_AUTOFF) == (ADC_CFG_AUTOFF));
}

/**
  * @brief  Delayed conversion mode Enable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_auto_delay_mode(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->CFG, ADC_CFG_AUTODLY);
}

/**
  * @brief  Delayed conversion mode Disable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_auto_delay_mode(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->CFG, ADC_CFG_AUTODLY);
}

/**
  * @brief  Check if Delayed conversion mode is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_auto_delay_mode(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->CFG, ADC_CFG_AUTODLY) == (ADC_CFG_AUTODLY));
}

/**
  * @brief  Set Single/continuous conversion mode for regular conversions.
  * @param  ADCx ADC Instance
  * @param  cm
            @arg @ref MD_ADC_CFG_CM_SINGLE
            @arg @ref MD_ADC_CFG_CM_CONTINUOUS
  * @retval None
  */
__STATIC_INLINE void md_adc_set_convsersion_mode(ADC_TypeDef *ADCx, uint32_t cm)
{
    MODIFY_REG(ADCx->CFG, ADC_CFG_CM, cm << ADC_CFG_CM_POS);
}

/**
  * @brief  Get Single/continuous conversion mode for regular conversions.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CFG_CM_SINGLE
            @arg @ref MD_ADC_CFG_CM_CONTINUOUS
  */
__STATIC_INLINE uint32_t md_adc_get_convsersion_mode(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CFG, ADC_CFG_CM)) >> ADC_CFG_CM_POS);
}

/**
  * @brief  Set Overrun Mode.
  * @param  ADCx ADC Instance
  * @param  overmod
            @arg @ref MD_ADC_CFG_OVRMOD_PRESERVED
            @arg @ref MD_ADC_CFG_OVRMOD_OVERWRITTEN
  * @retval None
  */
__STATIC_INLINE void md_adc_set_overflow_mode(ADC_TypeDef *ADCx, uint32_t overmod)
{
    MODIFY_REG(ADCx->CFG, ADC_CFG_OVRMOD, overmod << ADC_CFG_OVRMOD_POS);
}

/**
  * @brief  Get Overrun Mode.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CFG_OVRMOD_PRESERVED
            @arg @ref MD_ADC_CFG_OVRMOD_OVERWRITTEN
  */
__STATIC_INLINE uint32_t md_adc_get_overflow_mode(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CFG, ADC_CFG_OVRMOD)) >> ADC_CFG_OVRMOD_POS);
}

/**
  * @brief  Set External trigger enable and polarity selection for regular channels.
  * @param  ADCx ADC Instance
  * @param  nets
            @arg @ref MD_ADC_CFG_NETS_DISABLE
            @arg @ref MD_ADC_CFG_NETS_RISING
            @arg @ref MD_ADC_CFG_NETS_FALLING
            @arg @ref MD_ADC_CFG_NETS_BOTH
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_external_trigger_mode(ADC_TypeDef *ADCx, uint32_t nets)
{
    MODIFY_REG(ADCx->CFG, ADC_CFG_NETS, nets << ADC_CFG_NETS_POSS);
}

/**
  * @brief  Get External trigger enable and polarity selection for regular channels.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CFG_NETS_DISABLE
            @arg @ref MD_ADC_CFG_NETS_RISING
            @arg @ref MD_ADC_CFG_NETS_FALLING
            @arg @ref MD_ADC_CFG_NETS_BOTH
  */
__STATIC_INLINE uint32_t md_adc_get_normal_external_trigger_mode(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CFG, ADC_CFG_NETS)) >> ADC_CFG_NETS_POSS);
}

/**
  * @brief  Set External trigger selection for regular group.
  * @param  ADCx ADC Instance
  * @param  nextsel
            @arg @ref MD_ADC_CFG_NEXTSEL_AD16C4T1_CH1
            @arg @ref MD_ADC_CFG_NEXTSEL_AD16C4T1_CH2
            @arg @ref MD_ADC_CFG_NEXTSEL_AD16C4T1_CH3
            @arg @ref MD_ADC_CFG_NEXTSEL_GP32C4T1_CH2
            @arg @ref MD_ADC_CFG_NEXTSEL_GP32C4T1_CH3
            @arg @ref MD_ADC_CFG_NEXTSEL_GP32C4T1_CH4
            @arg @ref MD_ADC_CFG_NEXTSEL_GP32C4T1_TRGOUT
            @arg @ref MD_ADC_CFG_NEXTSEL_GP16C4T1_CH1
            @arg @ref MD_ADC_CFG_NEXTSEL_GP16C4T1_TRGOUT
            @arg @ref MD_ADC_CFG_NEXTSEL_GP16C4T2_CH4
            @arg @ref MD_ADC_CFG_NEXTSEL_GP16C4T3_CH1
            @arg @ref MD_ADC_CFG_NEXTSEL_GP16C4T3_CH2
            @arg @ref MD_ADC_CFG_NEXTSEL_GP16C4T3_CH3
            @arg @ref MD_ADC_CFG_NEXTSEL_BS16T1_TRGOUT
            @arg @ref MD_ADC_CFG_NEXTSEL_RTC
            @arg @ref MD_ADC_CFG_NEXTSEL_EXTI_TRG0
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_external_trigger_source(ADC_TypeDef *ADCx, uint32_t nextsel)
{
    MODIFY_REG(ADCx->CFG, ADC_CFG_NEXTSEL, nextsel << ADC_CFG_NEXTSEL_POSS);
}

/**
  * @brief  Get External trigger selection for regular group.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CFG_NEXTSEL_AD16C4T1_CH1
            @arg @ref MD_ADC_CFG_NEXTSEL_AD16C4T1_CH2
            @arg @ref MD_ADC_CFG_NEXTSEL_AD16C4T1_CH3
            @arg @ref MD_ADC_CFG_NEXTSEL_GP32C4T1_CH2
            @arg @ref MD_ADC_CFG_NEXTSEL_GP32C4T1_CH3
            @arg @ref MD_ADC_CFG_NEXTSEL_GP32C4T1_CH4
            @arg @ref MD_ADC_CFG_NEXTSEL_GP32C4T1_TRGOUT
            @arg @ref MD_ADC_CFG_NEXTSEL_GP16C4T1_CH1
            @arg @ref MD_ADC_CFG_NEXTSEL_GP16C4T1_TRGOUT
            @arg @ref MD_ADC_CFG_NEXTSEL_GP16C4T2_CH4
            @arg @ref MD_ADC_CFG_NEXTSEL_GP16C4T3_CH1
            @arg @ref MD_ADC_CFG_NEXTSEL_GP16C4T3_CH2
            @arg @ref MD_ADC_CFG_NEXTSEL_GP16C4T3_CH3
            @arg @ref MD_ADC_CFG_NEXTSEL_BS16T1_TRGOUT
            @arg @ref MD_ADC_CFG_NEXTSEL_RTC
            @arg @ref MD_ADC_CFG_NEXTSEL_EXTI_TRG0
  */
__STATIC_INLINE uint32_t md_adc_get_normal_external_trigger_source(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CFG, ADC_CFG_NEXTSEL)) >> ADC_CFG_NEXTSEL_POSS);
}

/**
  * @brief  Set Data alignment.
  * @param  ADCx ADC Instance
  * @param  align
            @arg @ref MD_ADC_CFG_ALIGN_RIGHT
            @arg @ref MD_ADC_CFG_ALIGN_LEFT
  * @retval None
  */
__STATIC_INLINE void md_adc_set_data_alignment(ADC_TypeDef *ADCx, uint32_t align)
{
    MODIFY_REG(ADCx->CFG, ADC_CFG_ALIGN, align << ADC_CFG_ALIGN_POS);
}

/**
  * @brief  Get Data alignment.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CFG_ALIGN_RIGHT
            @arg @ref MD_ADC_CFG_ALIGN_LEFT
  */
__STATIC_INLINE uint32_t md_adc_get_data_alignment(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CFG, ADC_CFG_ALIGN)) >> ADC_CFG_ALIGN_POS);
}

/**
  * @brief  Set Data resolution.
  * @param  ADCx ADC Instance
  * @param  rsel
            @arg @ref MD_ADC_CFG_RSEL_6BIT
            @arg @ref MD_ADC_CFG_RSEL_8BIT
            @arg @ref MD_ADC_CFG_RSEL_10BIT
            @arg @ref MD_ADC_CFG_RSEL_12BIT
  * @retval None
  */
__STATIC_INLINE void md_adc_set_resolution_selection(ADC_TypeDef *ADCx, uint32_t rsel)
{
    MODIFY_REG(ADCx->CFG, ADC_CFG_RSEL, rsel << ADC_CFG_RSEL_POSS);
}

/**
  * @brief  Get Data resolution.
  * @param  ADCx ADC Instance
  * @retval None
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CFG_RSEL_6BIT
            @arg @ref MD_ADC_CFG_RSEL_8BIT
            @arg @ref MD_ADC_CFG_RSEL_10BIT
            @arg @ref MD_ADC_CFG_RSEL_12BIT
  */
__STATIC_INLINE uint32_t md_adc_get_resolution_selection(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CFG, ADC_CFG_RSEL)) >> ADC_CFG_RSEL_POSS);
}

/**
  * @brief  Direct memory access enable Enable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_dma_access(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->CFG, ADC_CFG_DMAEN);
}

/**
  * @brief  Direct memory access enable Disable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_dma_access(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->CFG, ADC_CFG_DMAEN);
}

/**
  * @brief  Check if Direct memory access enable is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_enabled_dma_access(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->CFG, ADC_CFG_DMAEN) == (ADC_CFG_DMAEN));
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group10 SMPT1
  * @{
  */
/**
  * @brief  Set ADC_SMPT1 Register
  * @param  ADCx ADC Instance
  * @param  ier
  */
__STATIC_INLINE void md_adc_set_smpt1(ADC_TypeDef *ADCx, uint32_t smpt1)
{
    WRITE_REG(ADCx->SMPT1, smpt1);
}

/**
  * @brief  Get ADC_SMPT1 Register
  * @param  ADCx ADC Instance
  */
__STATIC_INLINE uint32_t md_adc_get_smpt1(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_REG(ADCx->SMPT1));
}

/**
  * @brief  Set Channel 2 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_2(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT1, ADC_SMPT1_CHT2, sample_time << ADC_SMPT1_CHT2_POSS);
}

/**
  * @brief  Get Channel 2 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 2 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_2(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT1, ADC_SMPT1_CHT2) >> ADC_SMPT1_CHT2_POSS));
}

/**
  * @brief  Set Channel 1 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_1(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT1, ADC_SMPT1_CHT1, sample_time << ADC_SMPT1_CHT1_POSS);
}

/**
  * @brief  Get Channel 0 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 0 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_1(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT1, ADC_SMPT1_CHT1) >> ADC_SMPT1_CHT1_POSS));
}

/**
  * @brief  Set Channel 0 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_0(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT1, ADC_SMPT1_CHT0, sample_time << ADC_SMPT1_CHT0_POSS);
}

/**
  * @brief  Get Channel 0 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 0 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_0(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT1, ADC_SMPT1_CHT0) >> ADC_SMPT1_CHT0_POSS));
}

/**
  * @brief  Set ADC Converter Clock Division.
  * @param  ADCx ADC Instance
  * @param  ckdiv
            @arg @ref MD_ADC_SMPT1_CKDIV_DIV1
            @arg @ref MD_ADC_SMPT1_CKDIV_DIV2
            @arg @ref MD_ADC_SMPT1_CKDIV_DIV4
            @arg @ref MD_ADC_SMPT1_CKDIV_DIV6
            @arg @ref MD_ADC_SMPT1_CKDIV_DIV8
  * @retval None
  */
__STATIC_INLINE void md_adc_set_adc_clock_predivider(ADC_TypeDef *ADCx, uint32_t ckdiv)
{
    MODIFY_REG(ADCx->SMPT1, ADC_SMPT1_CKDIV, ckdiv << ADC_SMPT1_CKDIV_POSS);
}

/**
  * @brief  Get ADC Converter Clock Division.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_SMPT1_CKDIV_DIV1
            @arg @ref MD_ADC_SMPT1_CKDIV_DIV2
            @arg @ref MD_ADC_SMPT1_CKDIV_DIV4
            @arg @ref MD_ADC_SMPT1_CKDIV_DIV6
            @arg @ref MD_ADC_SMPT1_CKDIV_DIV8
  */
__STATIC_INLINE uint32_t md_adc_get_adc_clock_predivider(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT1, ADC_SMPT1_CKDIV)) >> ADC_SMPT1_CKDIV_POSS);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group11 SMPT2
  * @{
  */
/**
  * @brief  Set ADC_SMPT2 Register
  * @param  ADCx ADC Instance
  * @param  smpt2
  * @retval None
  */
__STATIC_INLINE void md_adc_set_smpt2(ADC_TypeDef *ADCx, uint32_t smpt2)
{
    WRITE_REG(ADCx->SMPT2, smpt2);
}

/**
  * @brief  Get ADC_SMPT2 Register
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_smpt2(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_REG(ADCx->SMPT2));
}

/**
  * @brief  Set Channel 6 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_6(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT2, ADC_SMPT2_CHT6, sample_time << ADC_SMPT2_CHT6_POSS);
}

/**
  * @brief  Get Channel 6 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 6 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_6(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT2, ADC_SMPT2_CHT6) >> ADC_SMPT2_CHT6_POSS));
}

/**
  * @brief  Set Channel 6 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_5(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT2, ADC_SMPT2_CHT5, sample_time << ADC_SMPT2_CHT5_POSS);
}

/**
  * @brief  Get Channel 5 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 5 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_5(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT2, ADC_SMPT2_CHT5) >> ADC_SMPT2_CHT5_POSS));
}

/**
  * @brief  Set Channel 4 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_4(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT2, ADC_SMPT2_CHT4, sample_time << ADC_SMPT2_CHT4_POSS);
}

/**
  * @brief  Get Channel 4 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 6 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_4(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT2, ADC_SMPT2_CHT4) >> ADC_SMPT2_CHT4_POSS));
}

/**
  * @brief  Set Channel 3 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_3(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT2, ADC_SMPT2_CHT3, sample_time << ADC_SMPT2_CHT3_POSS);
}

/**
  * @brief  Get Channel 3 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 6 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_3(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT2, ADC_SMPT2_CHT3) >> ADC_SMPT2_CHT3_POSS));
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group12 SMPT3
  * @{
  */
/**
  * @brief  Set ADC_SMPT3 Register
  * @param  ADCx ADC Instance
  * @param  smpt3
  * @retval None
  */
__STATIC_INLINE void md_adc_set_smpt3(ADC_TypeDef *ADCx, uint32_t smpt3)
{
    WRITE_REG(ADCx->SMPT3, smpt3);
}

/**
  * @brief  Get ADC_SMPT3 Register
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_smpt3(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_REG(ADCx->SMPT3));
}

/**
  * @brief  Set Channel 3 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_10(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT3, ADC_SMPT3_CHT10, sample_time << ADC_SMPT3_CHT10_POSS);
}

/**
  * @brief  Get Channel 3 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 3 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_10(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT3, ADC_SMPT3_CHT10) >> ADC_SMPT3_CHT10_POSS));
}

/**
  * @brief  Set Channel 9 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_9(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT3, ADC_SMPT3_CHT9, sample_time << ADC_SMPT3_CHT9_POSS);
}

/**
  * @brief  Get Channel 9 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 9 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_9(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT3, ADC_SMPT3_CHT9) >> ADC_SMPT3_CHT9_POSS));
}

/**
  * @brief  Set Channel 8 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_8(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT3, ADC_SMPT3_CHT8, sample_time << ADC_SMPT3_CHT8_POSS);
}

/**
  * @brief  Get Channel 8 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 8 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_8(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT3, ADC_SMPT3_CHT8) >> ADC_SMPT3_CHT8_POSS));
}

/**
  * @brief  Set Channel 7 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_7(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT3, ADC_SMPT3_CHT7, sample_time << ADC_SMPT3_CHT7_POSS);
}

/**
  * @brief  Get Channel 7 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 7 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_7(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT3, ADC_SMPT3_CHT7) >> ADC_SMPT3_CHT7_POSS));
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group13 SMPT4
  * @{
  */
/**
  * @brief  Set ADC_SMPT4 Register
  * @param  ADCx ADC Instance
  * @param  smpt4
  * @retval None
  */
__STATIC_INLINE void md_adc_set_smpt4(ADC_TypeDef *ADCx, uint32_t smpt4)
{
    WRITE_REG(ADCx->SMPT4, smpt4);
}

/**
  * @brief  Get ADC_SMPT4 Register
  * @param  ADCx ADC Instance
  */
__STATIC_INLINE uint32_t md_adc_get_smpt4(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_REG(ADCx->SMPT4));
}

/**
  * @brief  Set Channel 14 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_14(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT4, ADC_SMPT4_CHT14, sample_time << ADC_SMPT4_CHT14_POSS);
}

/**
  * @brief  Get Channel 14 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 14 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_14(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT4, ADC_SMPT4_CHT14) >> ADC_SMPT4_CHT14_POSS));
}

/**
  * @brief  Set Channel 13 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_13(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT4, ADC_SMPT4_CHT13, sample_time << ADC_SMPT4_CHT13_POSS);
}

/**
  * @brief  Get Channel 13 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 13 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_13(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT4, ADC_SMPT4_CHT13) >> ADC_SMPT4_CHT13_POSS));
}

/**
  * @brief  Set Channel 12 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_12(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT4, ADC_SMPT4_CHT12, sample_time << ADC_SMPT4_CHT12_POSS);
}

/**
  * @brief  Get Channel 12 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 12 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_12(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT4, ADC_SMPT4_CHT12) >> ADC_SMPT4_CHT12_POSS));
}

/**
  * @brief  Set Channel 11 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_11(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT4, ADC_SMPT4_CHT11, sample_time << ADC_SMPT4_CHT11_POSS);
}

/**
  * @brief  Get Channel 11 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 11 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_11(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT4, ADC_SMPT4_CHT11) >> ADC_SMPT4_CHT11_POSS));
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group14 SMPT5
  * @{
  */
/**
  * @brief  Set ADC_SMPT5 Register
  * @param  ADCx ADC Instance
  * @param  smpt5
  * @retval None
  */
__STATIC_INLINE void md_adc_set_smpt5(ADC_TypeDef *ADCx, uint32_t smpt5)
{
    WRITE_REG(ADCx->SMPT5, smpt5);
}

/**
  * @brief  Get ADC_SMPT5 Register
  * @param  ADCx ADC Instance
  */
__STATIC_INLINE uint32_t md_adc_get_smpt5(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_REG(ADCx->SMPT5));
}

/**
  * @brief  Set Channel 18 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_18(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT5, ADC_SMPT5_CHT18, sample_time << ADC_SMPT5_CHT18_POSS);
}

/**
  * @brief  Get Channel 18 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 18 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_18(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT5, ADC_SMPT5_CHT18) >> ADC_SMPT5_CHT18_POSS));
}

/**
  * @brief  Set Channel 17 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_17(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT5, ADC_SMPT5_CHT17, sample_time << ADC_SMPT5_CHT17_POSS);
}

/**
  * @brief  Get Channel 17 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 17 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_17(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT5, ADC_SMPT5_CHT17) >> ADC_SMPT5_CHT17_POSS));
}

/**
  * @brief  Set Channel 16 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_16(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT5, ADC_SMPT5_CHT16, sample_time << ADC_SMPT5_CHT16_POSS);
}

/**
  * @brief  Get Channel 16 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 16 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_16(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT5, ADC_SMPT5_CHT16) >> ADC_SMPT5_CHT16_POSS));
}

/**
  * @brief  Set Channel 15 sampling time.
  * @param  ADCx ADC Instance
  * @param  sample_time
  * @retval None
  */
__STATIC_INLINE void md_adc_set_sampletime_channel_15(ADC_TypeDef *ADCx, uint32_t sample_time)
{
    MODIFY_REG(ADCx->SMPT5, ADC_SMPT5_CHT15, sample_time << ADC_SMPT5_CHT15_POSS);
}

/**
  * @brief  Get Channel 15 sampling time.
  * @param  ADCx ADC Instance
  * @retval Channel 15 sampling time
  */
__STATIC_INLINE uint32_t md_adc_get_sampletime_channel_15(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->SMPT5, ADC_SMPT5_CHT15) >> ADC_SMPT5_CHT15_POSS));
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group15 WDTH
  * @{
  */
/**
  * @brief  Set ADC_WDTH Register
  * @param  ADCx ADC Instance
  * @param  wdth
  * @retval None
  */
__STATIC_INLINE void md_adc_set_wdth(ADC_TypeDef *ADCx, uint32_t wdth)
{
    WRITE_REG(ADCx->WDTH, wdth);
}

/**
  * @brief  Get ADC_WDTH Register
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_wdth(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_REG(ADCx->WDTH));
}

/**
  * @brief  Set Analog watchdog higher threshold.
  * @param  ADCx ADC Instance
  * @param  ht
  * @retval None
  */
__STATIC_INLINE void md_adc_set_awdg_high_threshold(ADC_TypeDef *ADCx, uint32_t ht)
{
    MODIFY_REG(ADCx->WDTH, ADC_WDTH_HT, ht << ADC_WDTH_HT_POSS);
}

/**
  * @brief  Get Analog watchdog higher threshold.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_awdg_high_threshold(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->WDTH, ADC_WDTH_HT)) >> ADC_WDTH_HT_POSS);
}

/**
  * @brief  Set Analog watchdog lower threshold.
  * @param  ADCx ADC Instance
  * @param  lt
  * @retval None
  */
__STATIC_INLINE void md_adc_set_awdg_low_threshold(ADC_TypeDef *ADCx, uint32_t lt)
{
    MODIFY_REG(ADCx->WDTH, ADC_WDTH_LT, lt << ADC_WDTH_LT_POSS);
}

/**
  * @brief  Get Analog watchdog lower threshold.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_awdg_low_threshold(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->WDTH, ADC_WDTH_LT)) >> ADC_WDTH_LT_POSS);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group16 NCHS1
  * @{
  */
/**
  * @brief  Set ADC_NCHS1 Register
  * @param  ADCx ADC Instance
  * @param  nchs1
  * @retval None
  */
__STATIC_INLINE void md_adc_set_nchs1(ADC_TypeDef *ADCx, uint32_t nchs1)
{
    WRITE_REG(ADCx->NCHS1, nchs1);
}

/**
  * @brief  Get ADC_NCHS1 Register
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_nchs1(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_REG(ADCx->NCHS1));
}

/**
  * @brief  Set 4th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @param  ns4
            @arg @ref MD_ADC_NCHS1_NS4_CH0
            @arg @ref MD_ADC_NCHS1_NS4_CH1
            @arg @ref MD_ADC_NCHS1_NS4_CH2
            @arg @ref MD_ADC_NCHS1_NS4_CH3
            @arg @ref MD_ADC_NCHS1_NS4_CH4
            @arg @ref MD_ADC_NCHS1_NS4_CH5
            @arg @ref MD_ADC_NCHS1_NS4_CH6
            @arg @ref MD_ADC_NCHS1_NS4_CH7
            @arg @ref MD_ADC_NCHS1_NS4_CH8
            @arg @ref MD_ADC_NCHS1_NS4_CH9
            @arg @ref MD_ADC_NCHS1_NS4_CH10
            @arg @ref MD_ADC_NCHS1_NS4_CH11
            @arg @ref MD_ADC_NCHS1_NS4_CH12
            @arg @ref MD_ADC_NCHS1_NS4_CH13
            @arg @ref MD_ADC_NCHS1_NS4_CH14
            @arg @ref MD_ADC_NCHS1_NS4_CH15
            @arg @ref MD_ADC_NCHS1_NS4_CH16
            @arg @ref MD_ADC_NCHS1_NS4_CH17
            @arg @ref MD_ADC_NCHS1_NS4_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_4th(ADC_TypeDef *ADCx, uint32_t ns4)
{
    MODIFY_REG(ADCx->NCHS1, ADC_NCHS1_NS4, ns4 << ADC_NCHS1_NS4_POSS);
}

/**
  * @brief  Get 4th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS1_NS4_CH0
            @arg @ref MD_ADC_NCHS1_NS4_CH1
            @arg @ref MD_ADC_NCHS1_NS4_CH2
            @arg @ref MD_ADC_NCHS1_NS4_CH3
            @arg @ref MD_ADC_NCHS1_NS4_CH4
            @arg @ref MD_ADC_NCHS1_NS4_CH5
            @arg @ref MD_ADC_NCHS1_NS4_CH6
            @arg @ref MD_ADC_NCHS1_NS4_CH7
            @arg @ref MD_ADC_NCHS1_NS4_CH8
            @arg @ref MD_ADC_NCHS1_NS4_CH9
            @arg @ref MD_ADC_NCHS1_NS4_CH10
            @arg @ref MD_ADC_NCHS1_NS4_CH11
            @arg @ref MD_ADC_NCHS1_NS4_CH12
            @arg @ref MD_ADC_NCHS1_NS4_CH13
            @arg @ref MD_ADC_NCHS1_NS4_CH14
            @arg @ref MD_ADC_NCHS1_NS4_CH15
            @arg @ref MD_ADC_NCHS1_NS4_CH16
            @arg @ref MD_ADC_NCHS1_NS4_CH17
            @arg @ref MD_ADC_NCHS1_NS4_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_4th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS1, ADC_NCHS1_NS4)) >> ADC_NCHS1_NS4_POSS);
}

/**
  * @brief  Set 3th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @param  ns3
            @arg @ref MD_ADC_NCHS1_NS3_CH0
            @arg @ref MD_ADC_NCHS1_NS3_CH1
            @arg @ref MD_ADC_NCHS1_NS3_CH2
            @arg @ref MD_ADC_NCHS1_NS3_CH3
            @arg @ref MD_ADC_NCHS1_NS3_CH4
            @arg @ref MD_ADC_NCHS1_NS3_CH5
            @arg @ref MD_ADC_NCHS1_NS3_CH6
            @arg @ref MD_ADC_NCHS1_NS3_CH7
            @arg @ref MD_ADC_NCHS1_NS3_CH8
            @arg @ref MD_ADC_NCHS1_NS3_CH9
            @arg @ref MD_ADC_NCHS1_NS3_CH10
            @arg @ref MD_ADC_NCHS1_NS3_CH11
            @arg @ref MD_ADC_NCHS1_NS3_CH12
            @arg @ref MD_ADC_NCHS1_NS3_CH13
            @arg @ref MD_ADC_NCHS1_NS3_CH14
            @arg @ref MD_ADC_NCHS1_NS3_CH15
            @arg @ref MD_ADC_NCHS1_NS3_CH16
            @arg @ref MD_ADC_NCHS1_NS3_CH17
            @arg @ref MD_ADC_NCHS1_NS3_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_3th(ADC_TypeDef *ADCx, uint32_t ns3)
{
    MODIFY_REG(ADCx->NCHS1, ADC_NCHS1_NS3, ns3 << ADC_NCHS1_NS3_POSS);
}

/**
  * @brief  Get 3th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS1_NS3_CH0
            @arg @ref MD_ADC_NCHS1_NS3_CH1
            @arg @ref MD_ADC_NCHS1_NS3_CH2
            @arg @ref MD_ADC_NCHS1_NS3_CH3
            @arg @ref MD_ADC_NCHS1_NS3_CH4
            @arg @ref MD_ADC_NCHS1_NS3_CH5
            @arg @ref MD_ADC_NCHS1_NS3_CH6
            @arg @ref MD_ADC_NCHS1_NS3_CH7
            @arg @ref MD_ADC_NCHS1_NS3_CH8
            @arg @ref MD_ADC_NCHS1_NS3_CH9
            @arg @ref MD_ADC_NCHS1_NS3_CH10
            @arg @ref MD_ADC_NCHS1_NS3_CH11
            @arg @ref MD_ADC_NCHS1_NS3_CH12
            @arg @ref MD_ADC_NCHS1_NS3_CH13
            @arg @ref MD_ADC_NCHS1_NS3_CH14
            @arg @ref MD_ADC_NCHS1_NS3_CH15
            @arg @ref MD_ADC_NCHS1_NS3_CH16
            @arg @ref MD_ADC_NCHS1_NS3_CH17
            @arg @ref MD_ADC_NCHS1_NS3_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_3th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS1, ADC_NCHS1_NS3)) >> ADC_NCHS1_NS3_POSS);
}

/**
  * @brief  Set 2th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @param  ns2
            @arg @ref MD_ADC_NCHS1_NS2_CH0
            @arg @ref MD_ADC_NCHS1_NS2_CH1
            @arg @ref MD_ADC_NCHS1_NS2_CH2
            @arg @ref MD_ADC_NCHS1_NS2_CH3
            @arg @ref MD_ADC_NCHS1_NS2_CH4
            @arg @ref MD_ADC_NCHS1_NS2_CH5
            @arg @ref MD_ADC_NCHS1_NS2_CH6
            @arg @ref MD_ADC_NCHS1_NS2_CH7
            @arg @ref MD_ADC_NCHS1_NS2_CH8
            @arg @ref MD_ADC_NCHS1_NS2_CH9
            @arg @ref MD_ADC_NCHS1_NS2_CH10
            @arg @ref MD_ADC_NCHS1_NS2_CH11
            @arg @ref MD_ADC_NCHS1_NS2_CH12
            @arg @ref MD_ADC_NCHS1_NS2_CH13
            @arg @ref MD_ADC_NCHS1_NS2_CH14
            @arg @ref MD_ADC_NCHS1_NS2_CH15
            @arg @ref MD_ADC_NCHS1_NS2_CH16
            @arg @ref MD_ADC_NCHS1_NS2_CH17
            @arg @ref MD_ADC_NCHS1_NS2_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_2th(ADC_TypeDef *ADCx, uint32_t ns2)
{
    MODIFY_REG(ADCx->NCHS1, ADC_NCHS1_NS2, ns2 << ADC_NCHS1_NS2_POSS);
}

/**
  * @brief  Get 2th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS1_NS2_CH0
            @arg @ref MD_ADC_NCHS1_NS2_CH1
            @arg @ref MD_ADC_NCHS1_NS2_CH2
            @arg @ref MD_ADC_NCHS1_NS2_CH3
            @arg @ref MD_ADC_NCHS1_NS2_CH4
            @arg @ref MD_ADC_NCHS1_NS2_CH5
            @arg @ref MD_ADC_NCHS1_NS2_CH6
            @arg @ref MD_ADC_NCHS1_NS2_CH7
            @arg @ref MD_ADC_NCHS1_NS2_CH8
            @arg @ref MD_ADC_NCHS1_NS2_CH9
            @arg @ref MD_ADC_NCHS1_NS2_CH10
            @arg @ref MD_ADC_NCHS1_NS2_CH11
            @arg @ref MD_ADC_NCHS1_NS2_CH12
            @arg @ref MD_ADC_NCHS1_NS2_CH13
            @arg @ref MD_ADC_NCHS1_NS2_CH14
            @arg @ref MD_ADC_NCHS1_NS2_CH15
            @arg @ref MD_ADC_NCHS1_NS2_CH16
            @arg @ref MD_ADC_NCHS1_NS2_CH17
            @arg @ref MD_ADC_NCHS1_NS2_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_2th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS1, ADC_NCHS1_NS2)) >> ADC_NCHS1_NS2_POSS);
}

/**
  * @brief  Set 1th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @param  ns1
            @arg @ref MD_ADC_NCHS1_NS1_CH0
            @arg @ref MD_ADC_NCHS1_NS1_CH1
            @arg @ref MD_ADC_NCHS1_NS1_CH2
            @arg @ref MD_ADC_NCHS1_NS1_CH3
            @arg @ref MD_ADC_NCHS1_NS1_CH4
            @arg @ref MD_ADC_NCHS1_NS1_CH5
            @arg @ref MD_ADC_NCHS1_NS1_CH6
            @arg @ref MD_ADC_NCHS1_NS1_CH7
            @arg @ref MD_ADC_NCHS1_NS1_CH8
            @arg @ref MD_ADC_NCHS1_NS1_CH9
            @arg @ref MD_ADC_NCHS1_NS1_CH10
            @arg @ref MD_ADC_NCHS1_NS1_CH11
            @arg @ref MD_ADC_NCHS1_NS1_CH12
            @arg @ref MD_ADC_NCHS1_NS1_CH13
            @arg @ref MD_ADC_NCHS1_NS1_CH14
            @arg @ref MD_ADC_NCHS1_NS1_CH15
            @arg @ref MD_ADC_NCHS1_NS1_CH16
            @arg @ref MD_ADC_NCHS1_NS1_CH17
            @arg @ref MD_ADC_NCHS1_NS1_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_1th(ADC_TypeDef *ADCx, uint32_t ns1)
{
    MODIFY_REG(ADCx->NCHS1, ADC_NCHS1_NS1, ns1 << ADC_NCHS1_NS1_POSS);
}

/**
  * @brief  Get 1th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS1_NS1_CH0
            @arg @ref MD_ADC_NCHS1_NS1_CH1
            @arg @ref MD_ADC_NCHS1_NS1_CH2
            @arg @ref MD_ADC_NCHS1_NS1_CH3
            @arg @ref MD_ADC_NCHS1_NS1_CH4
            @arg @ref MD_ADC_NCHS1_NS1_CH5
            @arg @ref MD_ADC_NCHS1_NS1_CH6
            @arg @ref MD_ADC_NCHS1_NS1_CH7
            @arg @ref MD_ADC_NCHS1_NS1_CH8
            @arg @ref MD_ADC_NCHS1_NS1_CH9
            @arg @ref MD_ADC_NCHS1_NS1_CH10
            @arg @ref MD_ADC_NCHS1_NS1_CH11
            @arg @ref MD_ADC_NCHS1_NS1_CH12
            @arg @ref MD_ADC_NCHS1_NS1_CH13
            @arg @ref MD_ADC_NCHS1_NS1_CH14
            @arg @ref MD_ADC_NCHS1_NS1_CH15
            @arg @ref MD_ADC_NCHS1_NS1_CH16
            @arg @ref MD_ADC_NCHS1_NS1_CH17
            @arg @ref MD_ADC_NCHS1_NS1_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_1th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS1, ADC_NCHS1_NS1)) >> ADC_NCHS1_NS1_POSS);
}

/**
  * @brief  Set Regular channel sequence length.
  * @param  ADCx ADC Instance
  * @param  nsl
            @arg @ref MD_ADC_NCHS1_NSL_1CON
            @arg @ref MD_ADC_NCHS1_NSL_2CON
            @arg @ref MD_ADC_NCHS1_NSL_3CON
            @arg @ref MD_ADC_NCHS1_NSL_4CON
            @arg @ref MD_ADC_NCHS1_NSL_5CON
            @arg @ref MD_ADC_NCHS1_NSL_6CON
            @arg @ref MD_ADC_NCHS1_NSL_7CON
            @arg @ref MD_ADC_NCHS1_NSL_8CON
            @arg @ref MD_ADC_NCHS1_NSL_9CON
            @arg @ref MD_ADC_NCHS1_NSL_10CON
            @arg @ref MD_ADC_NCHS1_NSL_11CON
            @arg @ref MD_ADC_NCHS1_NSL_12CON
            @arg @ref MD_ADC_NCHS1_NSL_13CON
            @arg @ref MD_ADC_NCHS1_NSL_14CON
            @arg @ref MD_ADC_NCHS1_NSL_15CON
            @arg @ref MD_ADC_NCHS1_NSL_16CON
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_length(ADC_TypeDef *ADCx, uint32_t nsl)
{
    MODIFY_REG(ADCx->NCHS1, ADC_NCHS1_NSL, nsl << ADC_NCHS1_NSL_POSS);
}

/**
  * @brief  Get Regular channel sequence length.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS1_NSL_1CON
            @arg @ref MD_ADC_NCHS1_NSL_2CON
            @arg @ref MD_ADC_NCHS1_NSL_3CON
            @arg @ref MD_ADC_NCHS1_NSL_4CON
            @arg @ref MD_ADC_NCHS1_NSL_5CON
            @arg @ref MD_ADC_NCHS1_NSL_6CON
            @arg @ref MD_ADC_NCHS1_NSL_7CON
            @arg @ref MD_ADC_NCHS1_NSL_8CON
            @arg @ref MD_ADC_NCHS1_NSL_9CON
            @arg @ref MD_ADC_NCHS1_NSL_10CON
            @arg @ref MD_ADC_NCHS1_NSL_11CON
            @arg @ref MD_ADC_NCHS1_NSL_12CON
            @arg @ref MD_ADC_NCHS1_NSL_13CON
            @arg @ref MD_ADC_NCHS1_NSL_14CON
            @arg @ref MD_ADC_NCHS1_NSL_15CON
            @arg @ref MD_ADC_NCHS1_NSL_16CON
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_length(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS1, ADC_NCHS1_NSL)) >> ADC_NCHS1_NSL_POSS);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group17 NCHS2
  * @{
  */
/**
  * @brief  Set ADC_NCHS2 Register
  * @param  ADCx ADC Instance
  * @param  nchs2
  * @retval None
  */
__STATIC_INLINE void md_adc_set_nchs2(ADC_TypeDef *ADCx, uint32_t nchs2)
{
    WRITE_REG(ADCx->NCHS2, nchs2);
}

/**
  * @brief  Get ADC_NCHS2 Register
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_nchs2(ADC_TypeDef *ADCx)
{
    return (uint32_t)READ_REG(ADCx->NCHS2);
}

/**
  * @brief  Set 9th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @param  ns9
            @arg @ref MD_ADC_NCHS2_NS9_CH0
            @arg @ref MD_ADC_NCHS2_NS9_CH1
            @arg @ref MD_ADC_NCHS2_NS9_CH2
            @arg @ref MD_ADC_NCHS2_NS9_CH3
            @arg @ref MD_ADC_NCHS2_NS9_CH4
            @arg @ref MD_ADC_NCHS2_NS9_CH5
            @arg @ref MD_ADC_NCHS2_NS9_CH6
            @arg @ref MD_ADC_NCHS2_NS9_CH7
            @arg @ref MD_ADC_NCHS2_NS9_CH8
            @arg @ref MD_ADC_NCHS2_NS9_CH9
            @arg @ref MD_ADC_NCHS2_NS9_CH10
            @arg @ref MD_ADC_NCHS2_NS9_CH11
            @arg @ref MD_ADC_NCHS2_NS9_CH12
            @arg @ref MD_ADC_NCHS2_NS9_CH13
            @arg @ref MD_ADC_NCHS2_NS9_CH14
            @arg @ref MD_ADC_NCHS2_NS9_CH15
            @arg @ref MD_ADC_NCHS2_NS9_CH16
            @arg @ref MD_ADC_NCHS2_NS9_CH17
            @arg @ref MD_ADC_NCHS2_NS9_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_9th(ADC_TypeDef *ADCx, uint32_t ns9)
{
    MODIFY_REG(ADCx->NCHS2, ADC_NCHS2_NS9, ns9 << ADC_NCHS2_NS9_POSS);
}

/**
  * @brief  Get 9th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS2_NS9_CH0
            @arg @ref MD_ADC_NCHS2_NS9_CH1
            @arg @ref MD_ADC_NCHS2_NS9_CH2
            @arg @ref MD_ADC_NCHS2_NS9_CH3
            @arg @ref MD_ADC_NCHS2_NS9_CH4
            @arg @ref MD_ADC_NCHS2_NS9_CH5
            @arg @ref MD_ADC_NCHS2_NS9_CH6
            @arg @ref MD_ADC_NCHS2_NS9_CH7
            @arg @ref MD_ADC_NCHS2_NS9_CH8
            @arg @ref MD_ADC_NCHS2_NS9_CH9
            @arg @ref MD_ADC_NCHS2_NS9_CH10
            @arg @ref MD_ADC_NCHS2_NS9_CH11
            @arg @ref MD_ADC_NCHS2_NS9_CH12
            @arg @ref MD_ADC_NCHS2_NS9_CH13
            @arg @ref MD_ADC_NCHS2_NS9_CH14
            @arg @ref MD_ADC_NCHS2_NS9_CH15
            @arg @ref MD_ADC_NCHS2_NS9_CH16
            @arg @ref MD_ADC_NCHS2_NS9_CH17
            @arg @ref MD_ADC_NCHS2_NS9_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_9th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS2, ADC_NCHS2_NS9)) >> ADC_NCHS2_NS9_POSS);
}

/**
  * @brief  Set 8th conversion in regular sequence.
  * @param  ADCx ADC Instance
            @arg @ref MD_ADC_NCHS2_NS8_CH0
            @arg @ref MD_ADC_NCHS2_NS8_CH1
            @arg @ref MD_ADC_NCHS2_NS8_CH2
            @arg @ref MD_ADC_NCHS2_NS8_CH3
            @arg @ref MD_ADC_NCHS2_NS8_CH4
            @arg @ref MD_ADC_NCHS2_NS8_CH5
            @arg @ref MD_ADC_NCHS2_NS8_CH6
            @arg @ref MD_ADC_NCHS2_NS8_CH7
            @arg @ref MD_ADC_NCHS2_NS8_CH8
            @arg @ref MD_ADC_NCHS2_NS8_CH9
            @arg @ref MD_ADC_NCHS2_NS8_CH10
            @arg @ref MD_ADC_NCHS2_NS8_CH11
            @arg @ref MD_ADC_NCHS2_NS8_CH12
            @arg @ref MD_ADC_NCHS2_NS8_CH13
            @arg @ref MD_ADC_NCHS2_NS8_CH14
            @arg @ref MD_ADC_NCHS2_NS8_CH15
            @arg @ref MD_ADC_NCHS2_NS8_CH16
            @arg @ref MD_ADC_NCHS2_NS8_CH17
            @arg @ref MD_ADC_NCHS2_NS8_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_8th(ADC_TypeDef *ADCx, uint32_t ns8)
{
    MODIFY_REG(ADCx->NCHS2, ADC_NCHS2_NS8, ns8 << ADC_NCHS2_NS8_POSS);
}

/**
  * @brief  Get 8th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS2_NS8_CH0
            @arg @ref MD_ADC_NCHS2_NS8_CH1
            @arg @ref MD_ADC_NCHS2_NS8_CH2
            @arg @ref MD_ADC_NCHS2_NS8_CH3
            @arg @ref MD_ADC_NCHS2_NS8_CH4
            @arg @ref MD_ADC_NCHS2_NS8_CH5
            @arg @ref MD_ADC_NCHS2_NS8_CH6
            @arg @ref MD_ADC_NCHS2_NS8_CH7
            @arg @ref MD_ADC_NCHS2_NS8_CH8
            @arg @ref MD_ADC_NCHS2_NS8_CH9
            @arg @ref MD_ADC_NCHS2_NS8_CH10
            @arg @ref MD_ADC_NCHS2_NS8_CH11
            @arg @ref MD_ADC_NCHS2_NS8_CH12
            @arg @ref MD_ADC_NCHS2_NS8_CH13
            @arg @ref MD_ADC_NCHS2_NS8_CH14
            @arg @ref MD_ADC_NCHS2_NS8_CH15
            @arg @ref MD_ADC_NCHS2_NS8_CH16
            @arg @ref MD_ADC_NCHS2_NS8_CH17
            @arg @ref MD_ADC_NCHS2_NS8_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_8th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS2, ADC_NCHS2_NS8)) >> ADC_NCHS2_NS8_POSS);
}

/**
  * @brief  Set 7th conversion in regular sequence.
  * @param  ADCx ADC Instance
            @arg @ref MD_ADC_NCHS2_NS7_CH0
            @arg @ref MD_ADC_NCHS2_NS7_CH1
            @arg @ref MD_ADC_NCHS2_NS7_CH2
            @arg @ref MD_ADC_NCHS2_NS7_CH3
            @arg @ref MD_ADC_NCHS2_NS7_CH4
            @arg @ref MD_ADC_NCHS2_NS7_CH5
            @arg @ref MD_ADC_NCHS2_NS7_CH6
            @arg @ref MD_ADC_NCHS2_NS7_CH7
            @arg @ref MD_ADC_NCHS2_NS7_CH8
            @arg @ref MD_ADC_NCHS2_NS7_CH9
            @arg @ref MD_ADC_NCHS2_NS7_CH10
            @arg @ref MD_ADC_NCHS2_NS7_CH11
            @arg @ref MD_ADC_NCHS2_NS7_CH12
            @arg @ref MD_ADC_NCHS2_NS7_CH13
            @arg @ref MD_ADC_NCHS2_NS7_CH14
            @arg @ref MD_ADC_NCHS2_NS7_CH15
            @arg @ref MD_ADC_NCHS2_NS7_CH16
            @arg @ref MD_ADC_NCHS2_NS7_CH17
            @arg @ref MD_ADC_NCHS2_NS7_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_7th(ADC_TypeDef *ADCx, uint32_t ns7)
{
    MODIFY_REG(ADCx->NCHS2, ADC_NCHS2_NS7, ns7 << ADC_NCHS2_NS7_POSS);
}

/**
  * @brief  Get 7th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS2_NS7_CH0
            @arg @ref MD_ADC_NCHS2_NS7_CH1
            @arg @ref MD_ADC_NCHS2_NS7_CH2
            @arg @ref MD_ADC_NCHS2_NS7_CH3
            @arg @ref MD_ADC_NCHS2_NS7_CH4
            @arg @ref MD_ADC_NCHS2_NS7_CH5
            @arg @ref MD_ADC_NCHS2_NS7_CH6
            @arg @ref MD_ADC_NCHS2_NS7_CH7
            @arg @ref MD_ADC_NCHS2_NS7_CH8
            @arg @ref MD_ADC_NCHS2_NS7_CH9
            @arg @ref MD_ADC_NCHS2_NS7_CH10
            @arg @ref MD_ADC_NCHS2_NS7_CH11
            @arg @ref MD_ADC_NCHS2_NS7_CH12
            @arg @ref MD_ADC_NCHS2_NS7_CH13
            @arg @ref MD_ADC_NCHS2_NS7_CH14
            @arg @ref MD_ADC_NCHS2_NS7_CH15
            @arg @ref MD_ADC_NCHS2_NS7_CH16
            @arg @ref MD_ADC_NCHS2_NS7_CH17
            @arg @ref MD_ADC_NCHS2_NS7_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_7th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS2, ADC_NCHS2_NS7)) >> ADC_NCHS2_NS7_POSS);
}

/**
  * @brief  Set 6th conversion in regular sequence.
  * @param  ADCx ADC Instance
            @arg @ref MD_ADC_NCHS2_NS6_CH0
            @arg @ref MD_ADC_NCHS2_NS6_CH1
            @arg @ref MD_ADC_NCHS2_NS6_CH2
            @arg @ref MD_ADC_NCHS2_NS6_CH3
            @arg @ref MD_ADC_NCHS2_NS6_CH4
            @arg @ref MD_ADC_NCHS2_NS6_CH5
            @arg @ref MD_ADC_NCHS2_NS6_CH6
            @arg @ref MD_ADC_NCHS2_NS6_CH7
            @arg @ref MD_ADC_NCHS2_NS6_CH8
            @arg @ref MD_ADC_NCHS2_NS6_CH9
            @arg @ref MD_ADC_NCHS2_NS6_CH10
            @arg @ref MD_ADC_NCHS2_NS6_CH11
            @arg @ref MD_ADC_NCHS2_NS6_CH12
            @arg @ref MD_ADC_NCHS2_NS6_CH13
            @arg @ref MD_ADC_NCHS2_NS6_CH14
            @arg @ref MD_ADC_NCHS2_NS6_CH15
            @arg @ref MD_ADC_NCHS2_NS6_CH16
            @arg @ref MD_ADC_NCHS2_NS6_CH17
            @arg @ref MD_ADC_NCHS2_NS6_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_6th(ADC_TypeDef *ADCx, uint32_t ns6)
{
    MODIFY_REG(ADCx->NCHS2, ADC_NCHS2_NS6, ns6 << ADC_NCHS2_NS6_POSS);
}

/**
  * @brief  Get 6th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS2_NS6_CH0
            @arg @ref MD_ADC_NCHS2_NS6_CH1
            @arg @ref MD_ADC_NCHS2_NS6_CH2
            @arg @ref MD_ADC_NCHS2_NS6_CH3
            @arg @ref MD_ADC_NCHS2_NS6_CH4
            @arg @ref MD_ADC_NCHS2_NS6_CH5
            @arg @ref MD_ADC_NCHS2_NS6_CH6
            @arg @ref MD_ADC_NCHS2_NS6_CH7
            @arg @ref MD_ADC_NCHS2_NS6_CH8
            @arg @ref MD_ADC_NCHS2_NS6_CH9
            @arg @ref MD_ADC_NCHS2_NS6_CH10
            @arg @ref MD_ADC_NCHS2_NS6_CH11
            @arg @ref MD_ADC_NCHS2_NS6_CH12
            @arg @ref MD_ADC_NCHS2_NS6_CH13
            @arg @ref MD_ADC_NCHS2_NS6_CH14
            @arg @ref MD_ADC_NCHS2_NS6_CH15
            @arg @ref MD_ADC_NCHS2_NS6_CH16
            @arg @ref MD_ADC_NCHS2_NS6_CH17
            @arg @ref MD_ADC_NCHS2_NS6_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_6th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS2, ADC_NCHS2_NS6)) >> ADC_NCHS2_NS6_POSS);
}

/**
  * @brief  Set 5th conversion in regular sequence.
  * @param  ADCx ADC Instance
            @arg @ref MD_ADC_NCHS2_NS5_CH0
            @arg @ref MD_ADC_NCHS2_NS5_CH1
            @arg @ref MD_ADC_NCHS2_NS5_CH2
            @arg @ref MD_ADC_NCHS2_NS5_CH3
            @arg @ref MD_ADC_NCHS2_NS5_CH4
            @arg @ref MD_ADC_NCHS2_NS5_CH5
            @arg @ref MD_ADC_NCHS2_NS5_CH6
            @arg @ref MD_ADC_NCHS2_NS5_CH7
            @arg @ref MD_ADC_NCHS2_NS5_CH8
            @arg @ref MD_ADC_NCHS2_NS5_CH9
            @arg @ref MD_ADC_NCHS2_NS5_CH10
            @arg @ref MD_ADC_NCHS2_NS5_CH11
            @arg @ref MD_ADC_NCHS2_NS5_CH12
            @arg @ref MD_ADC_NCHS2_NS5_CH13
            @arg @ref MD_ADC_NCHS2_NS5_CH14
            @arg @ref MD_ADC_NCHS2_NS5_CH15
            @arg @ref MD_ADC_NCHS2_NS5_CH16
            @arg @ref MD_ADC_NCHS2_NS5_CH17
            @arg @ref MD_ADC_NCHS2_NS5_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_5th(ADC_TypeDef *ADCx, uint32_t ns5)
{
    MODIFY_REG(ADCx->NCHS2, ADC_NCHS2_NS5, ns5 << ADC_NCHS2_NS5_POSS);
}

/**
  * @brief  Get 5th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS2_NS5_CH0
            @arg @ref MD_ADC_NCHS2_NS5_CH1
            @arg @ref MD_ADC_NCHS2_NS5_CH2
            @arg @ref MD_ADC_NCHS2_NS5_CH3
            @arg @ref MD_ADC_NCHS2_NS5_CH4
            @arg @ref MD_ADC_NCHS2_NS5_CH5
            @arg @ref MD_ADC_NCHS2_NS5_CH6
            @arg @ref MD_ADC_NCHS2_NS5_CH7
            @arg @ref MD_ADC_NCHS2_NS5_CH8
            @arg @ref MD_ADC_NCHS2_NS5_CH9
            @arg @ref MD_ADC_NCHS2_NS5_CH10
            @arg @ref MD_ADC_NCHS2_NS5_CH11
            @arg @ref MD_ADC_NCHS2_NS5_CH12
            @arg @ref MD_ADC_NCHS2_NS5_CH13
            @arg @ref MD_ADC_NCHS2_NS5_CH14
            @arg @ref MD_ADC_NCHS2_NS5_CH15
            @arg @ref MD_ADC_NCHS2_NS5_CH16
            @arg @ref MD_ADC_NCHS2_NS5_CH17
            @arg @ref MD_ADC_NCHS2_NS5_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_5th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS2, ADC_NCHS2_NS5)) >> ADC_NCHS2_NS5_POSS);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group18 NCHS3
  * @{
  */
/**
  * @brief  Set ADC_NCHS3 Register
  * @param  ADCx ADC Instance
  * @param  nchs3
  * @retval None
  */
__STATIC_INLINE void md_adc_set_nchs3(ADC_TypeDef *ADCx, uint32_t nchs3)
{
    WRITE_REG(ADCx->NCHS3, nchs3);
}

/**
  * @brief  Get ADC_NCHS3 Register
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_nchs3(ADC_TypeDef *ADCx)
{
    return (uint32_t)READ_REG(ADCx->NCHS3);
}

/**
  * @brief  Set 14th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @param  ns14
            @arg @ref MD_ADC_NCHS3_NS14_CH0
            @arg @ref MD_ADC_NCHS3_NS14_CH1
            @arg @ref MD_ADC_NCHS3_NS14_CH2
            @arg @ref MD_ADC_NCHS3_NS14_CH3
            @arg @ref MD_ADC_NCHS3_NS14_CH4
            @arg @ref MD_ADC_NCHS3_NS14_CH5
            @arg @ref MD_ADC_NCHS3_NS14_CH6
            @arg @ref MD_ADC_NCHS3_NS14_CH7
            @arg @ref MD_ADC_NCHS3_NS14_CH8
            @arg @ref MD_ADC_NCHS3_NS14_CH9
            @arg @ref MD_ADC_NCHS3_NS14_CH10
            @arg @ref MD_ADC_NCHS3_NS14_CH11
            @arg @ref MD_ADC_NCHS3_NS14_CH12
            @arg @ref MD_ADC_NCHS3_NS14_CH13
            @arg @ref MD_ADC_NCHS3_NS14_CH14
            @arg @ref MD_ADC_NCHS3_NS14_CH15
            @arg @ref MD_ADC_NCHS3_NS14_CH16
            @arg @ref MD_ADC_NCHS3_NS14_CH17
            @arg @ref MD_ADC_NCHS3_NS14_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_14th(ADC_TypeDef *ADCx, uint32_t ns14)
{
    MODIFY_REG(ADCx->NCHS3, ADC_NCHS3_NS14, ns14 << ADC_NCHS3_NS14_POSS);
}

/**
  * @brief  Get 14th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS3_NS14_CH0
            @arg @ref MD_ADC_NCHS3_NS14_CH1
            @arg @ref MD_ADC_NCHS3_NS14_CH2
            @arg @ref MD_ADC_NCHS3_NS14_CH3
            @arg @ref MD_ADC_NCHS3_NS14_CH4
            @arg @ref MD_ADC_NCHS3_NS14_CH5
            @arg @ref MD_ADC_NCHS3_NS14_CH6
            @arg @ref MD_ADC_NCHS3_NS14_CH7
            @arg @ref MD_ADC_NCHS3_NS14_CH8
            @arg @ref MD_ADC_NCHS3_NS14_CH9
            @arg @ref MD_ADC_NCHS3_NS14_CH10
            @arg @ref MD_ADC_NCHS3_NS14_CH11
            @arg @ref MD_ADC_NCHS3_NS14_CH12
            @arg @ref MD_ADC_NCHS3_NS14_CH13
            @arg @ref MD_ADC_NCHS3_NS14_CH14
            @arg @ref MD_ADC_NCHS3_NS14_CH15
            @arg @ref MD_ADC_NCHS3_NS14_CH16
            @arg @ref MD_ADC_NCHS3_NS14_CH17
            @arg @ref MD_ADC_NCHS3_NS14_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_14th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS3, ADC_NCHS3_NS14)) >> ADC_NCHS3_NS14_POSS);
}

/**
  * @brief  Set 13th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @param  ns13
            @arg @ref MD_ADC_NCHS3_NS13_CH0
            @arg @ref MD_ADC_NCHS3_NS13_CH1
            @arg @ref MD_ADC_NCHS3_NS13_CH2
            @arg @ref MD_ADC_NCHS3_NS13_CH3
            @arg @ref MD_ADC_NCHS3_NS13_CH4
            @arg @ref MD_ADC_NCHS3_NS13_CH5
            @arg @ref MD_ADC_NCHS3_NS13_CH6
            @arg @ref MD_ADC_NCHS3_NS13_CH7
            @arg @ref MD_ADC_NCHS3_NS13_CH8
            @arg @ref MD_ADC_NCHS3_NS13_CH9
            @arg @ref MD_ADC_NCHS3_NS13_CH10
            @arg @ref MD_ADC_NCHS3_NS13_CH11
            @arg @ref MD_ADC_NCHS3_NS13_CH12
            @arg @ref MD_ADC_NCHS3_NS13_CH13
            @arg @ref MD_ADC_NCHS3_NS13_CH14
            @arg @ref MD_ADC_NCHS3_NS13_CH15
            @arg @ref MD_ADC_NCHS3_NS13_CH16
            @arg @ref MD_ADC_NCHS3_NS13_CH17
            @arg @ref MD_ADC_NCHS3_NS13_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_13th(ADC_TypeDef *ADCx, uint32_t ns13)
{
    MODIFY_REG(ADCx->NCHS3, ADC_NCHS3_NS13, ns13 << ADC_NCHS3_NS13_POSS);
}

/**
  * @brief  Get 13th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS3_NS13_CH0
            @arg @ref MD_ADC_NCHS3_NS13_CH1
            @arg @ref MD_ADC_NCHS3_NS13_CH2
            @arg @ref MD_ADC_NCHS3_NS13_CH3
            @arg @ref MD_ADC_NCHS3_NS13_CH4
            @arg @ref MD_ADC_NCHS3_NS13_CH5
            @arg @ref MD_ADC_NCHS3_NS13_CH6
            @arg @ref MD_ADC_NCHS3_NS13_CH7
            @arg @ref MD_ADC_NCHS3_NS13_CH8
            @arg @ref MD_ADC_NCHS3_NS13_CH9
            @arg @ref MD_ADC_NCHS3_NS13_CH10
            @arg @ref MD_ADC_NCHS3_NS13_CH11
            @arg @ref MD_ADC_NCHS3_NS13_CH12
            @arg @ref MD_ADC_NCHS3_NS13_CH13
            @arg @ref MD_ADC_NCHS3_NS13_CH14
            @arg @ref MD_ADC_NCHS3_NS13_CH15
            @arg @ref MD_ADC_NCHS3_NS13_CH16
            @arg @ref MD_ADC_NCHS3_NS13_CH17
            @arg @ref MD_ADC_NCHS3_NS13_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_13th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS3, ADC_NCHS3_NS13)) >> ADC_NCHS3_NS13_POSS);
}

/**
  * @brief  Set 12th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @param  ns12
            @arg @ref MD_ADC_NCHS3_NS12_CH0
            @arg @ref MD_ADC_NCHS3_NS12_CH1
            @arg @ref MD_ADC_NCHS3_NS12_CH2
            @arg @ref MD_ADC_NCHS3_NS12_CH3
            @arg @ref MD_ADC_NCHS3_NS12_CH4
            @arg @ref MD_ADC_NCHS3_NS12_CH5
            @arg @ref MD_ADC_NCHS3_NS12_CH6
            @arg @ref MD_ADC_NCHS3_NS12_CH7
            @arg @ref MD_ADC_NCHS3_NS12_CH8
            @arg @ref MD_ADC_NCHS3_NS12_CH9
            @arg @ref MD_ADC_NCHS3_NS12_CH10
            @arg @ref MD_ADC_NCHS3_NS12_CH11
            @arg @ref MD_ADC_NCHS3_NS12_CH12
            @arg @ref MD_ADC_NCHS3_NS12_CH13
            @arg @ref MD_ADC_NCHS3_NS12_CH14
            @arg @ref MD_ADC_NCHS3_NS12_CH15
            @arg @ref MD_ADC_NCHS3_NS12_CH16
            @arg @ref MD_ADC_NCHS3_NS12_CH17
            @arg @ref MD_ADC_NCHS3_NS12_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_12th(ADC_TypeDef *ADCx, uint32_t ns12)
{
    MODIFY_REG(ADCx->NCHS3, ADC_NCHS3_NS12, ns12 << ADC_NCHS3_NS12_POSS);
}

/**
  * @brief  Get 12th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS3_NS12_CH0
            @arg @ref MD_ADC_NCHS3_NS12_CH1
            @arg @ref MD_ADC_NCHS3_NS12_CH2
            @arg @ref MD_ADC_NCHS3_NS12_CH3
            @arg @ref MD_ADC_NCHS3_NS12_CH4
            @arg @ref MD_ADC_NCHS3_NS12_CH5
            @arg @ref MD_ADC_NCHS3_NS12_CH6
            @arg @ref MD_ADC_NCHS3_NS12_CH7
            @arg @ref MD_ADC_NCHS3_NS12_CH8
            @arg @ref MD_ADC_NCHS3_NS12_CH9
            @arg @ref MD_ADC_NCHS3_NS12_CH10
            @arg @ref MD_ADC_NCHS3_NS12_CH11
            @arg @ref MD_ADC_NCHS3_NS12_CH12
            @arg @ref MD_ADC_NCHS3_NS12_CH13
            @arg @ref MD_ADC_NCHS3_NS12_CH14
            @arg @ref MD_ADC_NCHS3_NS12_CH15
            @arg @ref MD_ADC_NCHS3_NS12_CH16
            @arg @ref MD_ADC_NCHS3_NS12_CH17
            @arg @ref MD_ADC_NCHS3_NS12_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_12th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS3, ADC_NCHS3_NS12)) >> ADC_NCHS3_NS12_POSS);
}

/**
  * @brief  Set 11th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @param  ns11
            @arg @ref MD_ADC_NCHS3_NS11_CH0
            @arg @ref MD_ADC_NCHS3_NS11_CH1
            @arg @ref MD_ADC_NCHS3_NS11_CH2
            @arg @ref MD_ADC_NCHS3_NS11_CH3
            @arg @ref MD_ADC_NCHS3_NS11_CH4
            @arg @ref MD_ADC_NCHS3_NS11_CH5
            @arg @ref MD_ADC_NCHS3_NS11_CH6
            @arg @ref MD_ADC_NCHS3_NS11_CH7
            @arg @ref MD_ADC_NCHS3_NS11_CH8
            @arg @ref MD_ADC_NCHS3_NS11_CH9
            @arg @ref MD_ADC_NCHS3_NS11_CH10
            @arg @ref MD_ADC_NCHS3_NS11_CH11
            @arg @ref MD_ADC_NCHS3_NS11_CH12
            @arg @ref MD_ADC_NCHS3_NS11_CH13
            @arg @ref MD_ADC_NCHS3_NS11_CH14
            @arg @ref MD_ADC_NCHS3_NS11_CH15
            @arg @ref MD_ADC_NCHS3_NS11_CH16
            @arg @ref MD_ADC_NCHS3_NS11_CH17
            @arg @ref MD_ADC_NCHS3_NS11_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_11th(ADC_TypeDef *ADCx, uint32_t ns11)
{
    MODIFY_REG(ADCx->NCHS3, ADC_NCHS3_NS11, ns11 << ADC_NCHS3_NS11_POSS);
}

/**
  * @brief  Get 11th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS3_NS11_CH0
            @arg @ref MD_ADC_NCHS3_NS11_CH1
            @arg @ref MD_ADC_NCHS3_NS11_CH2
            @arg @ref MD_ADC_NCHS3_NS11_CH3
            @arg @ref MD_ADC_NCHS3_NS11_CH4
            @arg @ref MD_ADC_NCHS3_NS11_CH5
            @arg @ref MD_ADC_NCHS3_NS11_CH6
            @arg @ref MD_ADC_NCHS3_NS11_CH7
            @arg @ref MD_ADC_NCHS3_NS11_CH8
            @arg @ref MD_ADC_NCHS3_NS11_CH9
            @arg @ref MD_ADC_NCHS3_NS11_CH10
            @arg @ref MD_ADC_NCHS3_NS11_CH11
            @arg @ref MD_ADC_NCHS3_NS11_CH12
            @arg @ref MD_ADC_NCHS3_NS11_CH13
            @arg @ref MD_ADC_NCHS3_NS11_CH14
            @arg @ref MD_ADC_NCHS3_NS11_CH15
            @arg @ref MD_ADC_NCHS3_NS11_CH16
            @arg @ref MD_ADC_NCHS3_NS11_CH17
            @arg @ref MD_ADC_NCHS3_NS11_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_11th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS3, ADC_NCHS3_NS11)) >> ADC_NCHS3_NS11_POSS);
}

/**
  * @brief  Set 10th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @param  ns10
            @arg @ref MD_ADC_NCHS3_NS10_CH0
            @arg @ref MD_ADC_NCHS3_NS10_CH1
            @arg @ref MD_ADC_NCHS3_NS10_CH2
            @arg @ref MD_ADC_NCHS3_NS10_CH3
            @arg @ref MD_ADC_NCHS3_NS10_CH4
            @arg @ref MD_ADC_NCHS3_NS10_CH5
            @arg @ref MD_ADC_NCHS3_NS10_CH6
            @arg @ref MD_ADC_NCHS3_NS10_CH7
            @arg @ref MD_ADC_NCHS3_NS10_CH8
            @arg @ref MD_ADC_NCHS3_NS10_CH9
            @arg @ref MD_ADC_NCHS3_NS10_CH10
            @arg @ref MD_ADC_NCHS3_NS10_CH11
            @arg @ref MD_ADC_NCHS3_NS10_CH12
            @arg @ref MD_ADC_NCHS3_NS10_CH13
            @arg @ref MD_ADC_NCHS3_NS10_CH14
            @arg @ref MD_ADC_NCHS3_NS10_CH15
            @arg @ref MD_ADC_NCHS3_NS10_CH16
            @arg @ref MD_ADC_NCHS3_NS10_CH17
            @arg @ref MD_ADC_NCHS3_NS10_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_10th(ADC_TypeDef *ADCx, uint32_t ns10)
{
    MODIFY_REG(ADCx->NCHS3, ADC_NCHS3_NS10, ns10 << ADC_NCHS3_NS10_POSS);
}

/**
  * @brief  Get 10th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS3_NS10_CH0
            @arg @ref MD_ADC_NCHS3_NS10_CH1
            @arg @ref MD_ADC_NCHS3_NS10_CH2
            @arg @ref MD_ADC_NCHS3_NS10_CH3
            @arg @ref MD_ADC_NCHS3_NS10_CH4
            @arg @ref MD_ADC_NCHS3_NS10_CH5
            @arg @ref MD_ADC_NCHS3_NS10_CH6
            @arg @ref MD_ADC_NCHS3_NS10_CH7
            @arg @ref MD_ADC_NCHS3_NS10_CH8
            @arg @ref MD_ADC_NCHS3_NS10_CH9
            @arg @ref MD_ADC_NCHS3_NS10_CH10
            @arg @ref MD_ADC_NCHS3_NS10_CH11
            @arg @ref MD_ADC_NCHS3_NS10_CH12
            @arg @ref MD_ADC_NCHS3_NS10_CH13
            @arg @ref MD_ADC_NCHS3_NS10_CH14
            @arg @ref MD_ADC_NCHS3_NS10_CH15
            @arg @ref MD_ADC_NCHS3_NS10_CH16
            @arg @ref MD_ADC_NCHS3_NS10_CH17
            @arg @ref MD_ADC_NCHS3_NS10_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_10th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS3, ADC_NCHS3_NS10)) >> ADC_NCHS3_NS10_POSS);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group19 NCHS4
  * @{
  */
/**
  * @brief  Set ADC_NCHS4 Register
  * @param  ADCx ADC Instance
  * @param  nchs4
  * @retval None
  */
__STATIC_INLINE void md_adc_set_nchs4(ADC_TypeDef *ADCx, uint32_t nchs4)
{
    WRITE_REG(ADCx->NCHS4, nchs4);
}

/**
  * @brief  Get ADC_NCHS4 Register
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_nchs4(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_REG(ADCx->NCHS4));
}

/**
  * @brief  Set 16th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @param  ns15
            @arg @ref MD_ADC_NCHS4_NS16_CH0
            @arg @ref MD_ADC_NCHS4_NS16_CH1
            @arg @ref MD_ADC_NCHS4_NS16_CH2
            @arg @ref MD_ADC_NCHS4_NS16_CH3
            @arg @ref MD_ADC_NCHS4_NS16_CH4
            @arg @ref MD_ADC_NCHS4_NS16_CH5
            @arg @ref MD_ADC_NCHS4_NS16_CH6
            @arg @ref MD_ADC_NCHS4_NS16_CH7
            @arg @ref MD_ADC_NCHS4_NS16_CH8
            @arg @ref MD_ADC_NCHS4_NS16_CH9
            @arg @ref MD_ADC_NCHS4_NS16_CH10
            @arg @ref MD_ADC_NCHS4_NS16_CH11
            @arg @ref MD_ADC_NCHS4_NS16_CH12
            @arg @ref MD_ADC_NCHS4_NS16_CH13
            @arg @ref MD_ADC_NCHS4_NS16_CH14
            @arg @ref MD_ADC_NCHS4_NS16_CH15
            @arg @ref MD_ADC_NCHS4_NS16_CH16
            @arg @ref MD_ADC_NCHS4_NS16_CH17
            @arg @ref MD_ADC_NCHS4_NS16_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_16th(ADC_TypeDef *ADCx, uint32_t ns16)
{
    MODIFY_REG(ADCx->NCHS4, ADC_NCHS4_NS16, ns16 << ADC_NCHS4_NS16_POSS);
}

/**
  * @brief  Get 16th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS4_NS16_CH0
            @arg @ref MD_ADC_NCHS4_NS16_CH1
            @arg @ref MD_ADC_NCHS4_NS16_CH2
            @arg @ref MD_ADC_NCHS4_NS16_CH3
            @arg @ref MD_ADC_NCHS4_NS16_CH4
            @arg @ref MD_ADC_NCHS4_NS16_CH5
            @arg @ref MD_ADC_NCHS4_NS16_CH6
            @arg @ref MD_ADC_NCHS4_NS16_CH7
            @arg @ref MD_ADC_NCHS4_NS16_CH8
            @arg @ref MD_ADC_NCHS4_NS16_CH9
            @arg @ref MD_ADC_NCHS4_NS16_CH10
            @arg @ref MD_ADC_NCHS4_NS16_CH11
            @arg @ref MD_ADC_NCHS4_NS16_CH12
            @arg @ref MD_ADC_NCHS4_NS16_CH13
            @arg @ref MD_ADC_NCHS4_NS16_CH14
            @arg @ref MD_ADC_NCHS4_NS16_CH15
            @arg @ref MD_ADC_NCHS4_NS16_CH16
            @arg @ref MD_ADC_NCHS4_NS16_CH17
            @arg @ref MD_ADC_NCHS4_NS16_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_16th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS4, ADC_NCHS4_NS16)) >> ADC_NCHS4_NS16_POSS);
}

/**
  * @brief  Set 15th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @param  ns15
            @arg @ref MD_ADC_NCHS4_NS15_CH0
            @arg @ref MD_ADC_NCHS4_NS15_CH1
            @arg @ref MD_ADC_NCHS4_NS15_CH2
            @arg @ref MD_ADC_NCHS4_NS15_CH3
            @arg @ref MD_ADC_NCHS4_NS15_CH4
            @arg @ref MD_ADC_NCHS4_NS15_CH5
            @arg @ref MD_ADC_NCHS4_NS15_CH6
            @arg @ref MD_ADC_NCHS4_NS15_CH7
            @arg @ref MD_ADC_NCHS4_NS15_CH8
            @arg @ref MD_ADC_NCHS4_NS15_CH9
            @arg @ref MD_ADC_NCHS4_NS15_CH10
            @arg @ref MD_ADC_NCHS4_NS15_CH11
            @arg @ref MD_ADC_NCHS4_NS15_CH12
            @arg @ref MD_ADC_NCHS4_NS15_CH13
            @arg @ref MD_ADC_NCHS4_NS15_CH14
            @arg @ref MD_ADC_NCHS4_NS15_CH15
            @arg @ref MD_ADC_NCHS4_NS15_CH16
            @arg @ref MD_ADC_NCHS4_NS15_CH17
            @arg @ref MD_ADC_NCHS4_NS15_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_normal_sequence_selection_15th(ADC_TypeDef *ADCx, uint32_t ns15)
{
    MODIFY_REG(ADCx->NCHS4, ADC_NCHS4_NS15, ns15 << ADC_NCHS4_NS15_POSS);
}

/**
  * @brief  Get 15th conversion in regular sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_NCHS4_NS15_CH0
            @arg @ref MD_ADC_NCHS4_NS15_CH1
            @arg @ref MD_ADC_NCHS4_NS15_CH2
            @arg @ref MD_ADC_NCHS4_NS15_CH3
            @arg @ref MD_ADC_NCHS4_NS15_CH4
            @arg @ref MD_ADC_NCHS4_NS15_CH5
            @arg @ref MD_ADC_NCHS4_NS15_CH6
            @arg @ref MD_ADC_NCHS4_NS15_CH7
            @arg @ref MD_ADC_NCHS4_NS15_CH8
            @arg @ref MD_ADC_NCHS4_NS15_CH9
            @arg @ref MD_ADC_NCHS4_NS15_CH10
            @arg @ref MD_ADC_NCHS4_NS15_CH11
            @arg @ref MD_ADC_NCHS4_NS15_CH12
            @arg @ref MD_ADC_NCHS4_NS15_CH13
            @arg @ref MD_ADC_NCHS4_NS15_CH14
            @arg @ref MD_ADC_NCHS4_NS15_CH15
            @arg @ref MD_ADC_NCHS4_NS15_CH16
            @arg @ref MD_ADC_NCHS4_NS15_CH17
            @arg @ref MD_ADC_NCHS4_NS15_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_normal_sequence_selection_15th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHS4, ADC_NCHS4_NS15)) >> ADC_NCHS4_NS15_POSS);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group20 NCHDR
  * @{
  */
/**
  * @brief  Get Regular data converted.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_normal_data(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->NCHDR, ADC_NCHDR_VAL)));
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group21 ICHS
  * @{
  */
/**
  * @brief  Set ADC_ICHS Register
  * @param  ADCx ADC Instance
  * @param  ichs
  * @retval None
  */
__STATIC_INLINE void md_adc_set_ichs(ADC_TypeDef *ADCx, uint32_t ichs)
{
    WRITE_REG(ADCx->ICHS, ichs);
}

/**
  * @brief  Get ADC_ICHS Register
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_ichs(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_REG(ADCx->ICHS));
}

/**
  * @brief  Set 4th conversion in the injected sequence.
  * @param  ADCx ADC Instance
  * @param  is4
            @arg @ref MD_ADC_ICHS_IS4_CH0
            @arg @ref MD_ADC_ICHS_IS4_CH1
            @arg @ref MD_ADC_ICHS_IS4_CH2
            @arg @ref MD_ADC_ICHS_IS4_CH3
            @arg @ref MD_ADC_ICHS_IS4_CH4
            @arg @ref MD_ADC_ICHS_IS4_CH5
            @arg @ref MD_ADC_ICHS_IS4_CH6
            @arg @ref MD_ADC_ICHS_IS4_CH7
            @arg @ref MD_ADC_ICHS_IS4_CH8
            @arg @ref MD_ADC_ICHS_IS4_CH9
            @arg @ref MD_ADC_ICHS_IS4_CH10
            @arg @ref MD_ADC_ICHS_IS4_CH11
            @arg @ref MD_ADC_ICHS_IS4_CH12
            @arg @ref MD_ADC_ICHS_IS4_CH13
            @arg @ref MD_ADC_ICHS_IS4_CH14
            @arg @ref MD_ADC_ICHS_IS4_CH15
            @arg @ref MD_ADC_ICHS_IS4_CH16
            @arg @ref MD_ADC_ICHS_IS4_CH17
            @arg @ref MD_ADC_ICHS_IS4_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_inj_sequence_selection_4th(ADC_TypeDef *ADCx, uint32_t is4)
{
    MODIFY_REG(ADCx->ICHS, ADC_ICHS_IS4, is4 << ADC_ICHS_IS4_POSS);
}

/**
  * @brief  Get 4th conversion in the injected sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_ICHS_IS4_CH0
            @arg @ref MD_ADC_ICHS_IS4_CH1
            @arg @ref MD_ADC_ICHS_IS4_CH2
            @arg @ref MD_ADC_ICHS_IS4_CH3
            @arg @ref MD_ADC_ICHS_IS4_CH4
            @arg @ref MD_ADC_ICHS_IS4_CH5
            @arg @ref MD_ADC_ICHS_IS4_CH6
            @arg @ref MD_ADC_ICHS_IS4_CH7
            @arg @ref MD_ADC_ICHS_IS4_CH8
            @arg @ref MD_ADC_ICHS_IS4_CH9
            @arg @ref MD_ADC_ICHS_IS4_CH10
            @arg @ref MD_ADC_ICHS_IS4_CH11
            @arg @ref MD_ADC_ICHS_IS4_CH12
            @arg @ref MD_ADC_ICHS_IS4_CH13
            @arg @ref MD_ADC_ICHS_IS4_CH14
            @arg @ref MD_ADC_ICHS_IS4_CH15
            @arg @ref MD_ADC_ICHS_IS4_CH16
            @arg @ref MD_ADC_ICHS_IS4_CH17
            @arg @ref MD_ADC_ICHS_IS4_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_inj_sequence_selection_4th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->ICHS, ADC_ICHS_IS4)) >> ADC_ICHS_IS4_POSS);
}

/**
  * @brief  Set 3th conversion in the injected sequence.
  * @param  ADCx ADC Instance
  * @param  is3
            @arg @ref MD_ADC_ICHS_IS3_CH0
            @arg @ref MD_ADC_ICHS_IS3_CH1
            @arg @ref MD_ADC_ICHS_IS3_CH2
            @arg @ref MD_ADC_ICHS_IS3_CH3
            @arg @ref MD_ADC_ICHS_IS3_CH4
            @arg @ref MD_ADC_ICHS_IS3_CH5
            @arg @ref MD_ADC_ICHS_IS3_CH6
            @arg @ref MD_ADC_ICHS_IS3_CH7
            @arg @ref MD_ADC_ICHS_IS3_CH8
            @arg @ref MD_ADC_ICHS_IS3_CH9
            @arg @ref MD_ADC_ICHS_IS3_CH10
            @arg @ref MD_ADC_ICHS_IS3_CH11
            @arg @ref MD_ADC_ICHS_IS3_CH12
            @arg @ref MD_ADC_ICHS_IS3_CH13
            @arg @ref MD_ADC_ICHS_IS3_CH14
            @arg @ref MD_ADC_ICHS_IS3_CH15
            @arg @ref MD_ADC_ICHS_IS3_CH16
            @arg @ref MD_ADC_ICHS_IS3_CH17
            @arg @ref MD_ADC_ICHS_IS3_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_inj_sequence_selection_3th(ADC_TypeDef *ADCx, uint32_t is3)
{
    MODIFY_REG(ADCx->ICHS, ADC_ICHS_IS3, is3 << ADC_ICHS_IS3_POSS);
}

/**
  * @brief  Get 3th conversion in the injected sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_ICHS_IS3_CH0
            @arg @ref MD_ADC_ICHS_IS3_CH1
            @arg @ref MD_ADC_ICHS_IS3_CH2
            @arg @ref MD_ADC_ICHS_IS3_CH3
            @arg @ref MD_ADC_ICHS_IS3_CH4
            @arg @ref MD_ADC_ICHS_IS3_CH5
            @arg @ref MD_ADC_ICHS_IS3_CH6
            @arg @ref MD_ADC_ICHS_IS3_CH7
            @arg @ref MD_ADC_ICHS_IS3_CH8
            @arg @ref MD_ADC_ICHS_IS3_CH9
            @arg @ref MD_ADC_ICHS_IS3_CH10
            @arg @ref MD_ADC_ICHS_IS3_CH11
            @arg @ref MD_ADC_ICHS_IS3_CH12
            @arg @ref MD_ADC_ICHS_IS3_CH13
            @arg @ref MD_ADC_ICHS_IS3_CH14
            @arg @ref MD_ADC_ICHS_IS3_CH15
            @arg @ref MD_ADC_ICHS_IS3_CH16
            @arg @ref MD_ADC_ICHS_IS3_CH17
            @arg @ref MD_ADC_ICHS_IS3_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_inj_sequence_selection_3th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->ICHS, ADC_ICHS_IS3)) >> ADC_ICHS_IS3_POSS);
}

/**
  * @brief  Set 2th conversion in the injected sequence.
  * @param  ADCx ADC Instance
  * @param  is2
            @arg @ref MD_ADC_ICHS_IS2_CH0
            @arg @ref MD_ADC_ICHS_IS2_CH1
            @arg @ref MD_ADC_ICHS_IS2_CH2
            @arg @ref MD_ADC_ICHS_IS2_CH3
            @arg @ref MD_ADC_ICHS_IS2_CH4
            @arg @ref MD_ADC_ICHS_IS2_CH5
            @arg @ref MD_ADC_ICHS_IS2_CH6
            @arg @ref MD_ADC_ICHS_IS2_CH7
            @arg @ref MD_ADC_ICHS_IS2_CH8
            @arg @ref MD_ADC_ICHS_IS2_CH9
            @arg @ref MD_ADC_ICHS_IS2_CH10
            @arg @ref MD_ADC_ICHS_IS2_CH11
            @arg @ref MD_ADC_ICHS_IS2_CH12
            @arg @ref MD_ADC_ICHS_IS2_CH13
            @arg @ref MD_ADC_ICHS_IS2_CH14
            @arg @ref MD_ADC_ICHS_IS2_CH15
            @arg @ref MD_ADC_ICHS_IS2_CH16
            @arg @ref MD_ADC_ICHS_IS2_CH17
            @arg @ref MD_ADC_ICHS_IS2_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_inj_sequence_selection_2th(ADC_TypeDef *ADCx, uint32_t is2)
{
    MODIFY_REG(ADCx->ICHS, ADC_ICHS_IS2, is2 << ADC_ICHS_IS2_POSS);
}

/**
  * @brief  Get 2th conversion in the injected sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_ICHS_IS2_CH0
            @arg @ref MD_ADC_ICHS_IS2_CH1
            @arg @ref MD_ADC_ICHS_IS2_CH2
            @arg @ref MD_ADC_ICHS_IS2_CH3
            @arg @ref MD_ADC_ICHS_IS2_CH4
            @arg @ref MD_ADC_ICHS_IS2_CH5
            @arg @ref MD_ADC_ICHS_IS2_CH6
            @arg @ref MD_ADC_ICHS_IS2_CH7
            @arg @ref MD_ADC_ICHS_IS2_CH8
            @arg @ref MD_ADC_ICHS_IS2_CH9
            @arg @ref MD_ADC_ICHS_IS2_CH10
            @arg @ref MD_ADC_ICHS_IS2_CH11
            @arg @ref MD_ADC_ICHS_IS2_CH12
            @arg @ref MD_ADC_ICHS_IS2_CH13
            @arg @ref MD_ADC_ICHS_IS2_CH14
            @arg @ref MD_ADC_ICHS_IS2_CH15
            @arg @ref MD_ADC_ICHS_IS2_CH16
            @arg @ref MD_ADC_ICHS_IS2_CH17
            @arg @ref MD_ADC_ICHS_IS2_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_inj_sequence_selection_2th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->ICHS, ADC_ICHS_IS2)) >> ADC_ICHS_IS2_POSS);
}

/**
  * @brief  Set 1th conversion in the injected sequence.
  * @param  ADCx ADC Instance
  * @param  is1
            @arg @ref MD_ADC_ICHS_IS1_CH0
            @arg @ref MD_ADC_ICHS_IS1_CH1
            @arg @ref MD_ADC_ICHS_IS1_CH2
            @arg @ref MD_ADC_ICHS_IS1_CH3
            @arg @ref MD_ADC_ICHS_IS1_CH4
            @arg @ref MD_ADC_ICHS_IS1_CH5
            @arg @ref MD_ADC_ICHS_IS1_CH6
            @arg @ref MD_ADC_ICHS_IS1_CH7
            @arg @ref MD_ADC_ICHS_IS1_CH8
            @arg @ref MD_ADC_ICHS_IS1_CH9
            @arg @ref MD_ADC_ICHS_IS1_CH10
            @arg @ref MD_ADC_ICHS_IS1_CH11
            @arg @ref MD_ADC_ICHS_IS1_CH12
            @arg @ref MD_ADC_ICHS_IS1_CH13
            @arg @ref MD_ADC_ICHS_IS1_CH14
            @arg @ref MD_ADC_ICHS_IS1_CH15
            @arg @ref MD_ADC_ICHS_IS1_CH16
            @arg @ref MD_ADC_ICHS_IS1_CH17
            @arg @ref MD_ADC_ICHS_IS1_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_set_inj_sequence_selection_1th(ADC_TypeDef *ADCx, uint32_t is1)
{
    MODIFY_REG(ADCx->ICHS, ADC_ICHS_IS1, is1 << ADC_ICHS_IS1_POSS);
}

/**
  * @brief  Get 1th conversion in the injected sequence.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_ICHS_IS1_CH0
            @arg @ref MD_ADC_ICHS_IS1_CH1
            @arg @ref MD_ADC_ICHS_IS1_CH2
            @arg @ref MD_ADC_ICHS_IS1_CH3
            @arg @ref MD_ADC_ICHS_IS1_CH4
            @arg @ref MD_ADC_ICHS_IS1_CH5
            @arg @ref MD_ADC_ICHS_IS1_CH6
            @arg @ref MD_ADC_ICHS_IS1_CH7
            @arg @ref MD_ADC_ICHS_IS1_CH8
            @arg @ref MD_ADC_ICHS_IS1_CH9
            @arg @ref MD_ADC_ICHS_IS1_CH10
            @arg @ref MD_ADC_ICHS_IS1_CH11
            @arg @ref MD_ADC_ICHS_IS1_CH12
            @arg @ref MD_ADC_ICHS_IS1_CH13
            @arg @ref MD_ADC_ICHS_IS1_CH14
            @arg @ref MD_ADC_ICHS_IS1_CH15
            @arg @ref MD_ADC_ICHS_IS1_CH16
            @arg @ref MD_ADC_ICHS_IS1_CH17
            @arg @ref MD_ADC_ICHS_IS1_CH18
  */
__STATIC_INLINE uint32_t md_adc_get_inj_sequence_selection_1th(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->ICHS, ADC_ICHS_IS1)) >> ADC_ICHS_IS1_POSS);
}

/**
  * @brief  Set External Trigger Enable and Polarity Selection for injected channels.
  * @param  ADCx ADC Instance
  * @param  iets
            @arg @ref MD_ADC_ICHS_IETS_DISABLE
            @arg @ref MD_ADC_ICHS_IETS_RISING
            @arg @ref MD_ADC_ICHS_IETS_FALLING
            @arg @ref MD_ADC_ICHS_IETS_BOTH
  * @retval None
  */
__STATIC_INLINE void md_adc_set_inj_external_trigger_mode(ADC_TypeDef *ADCx, uint32_t iets)
{
    MODIFY_REG(ADCx->ICHS, ADC_ICHS_IETS, iets << ADC_ICHS_IETS_POSS);
}

/**
  * @brief  Get External Trigger Enable and Polarity Selection for injected channels.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_ICHS_IETS_DISABLE
            @arg @ref MD_ADC_ICHS_IETS_RISING
            @arg @ref MD_ADC_ICHS_IETS_FALLING
            @arg @ref MD_ADC_ICHS_IETS_BOTH
  */
__STATIC_INLINE uint32_t md_adc_get_inj_external_trigger_mode(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->ICHS, ADC_ICHS_IETS)) >> ADC_ICHS_IETS_POSS);
}

/**
  * @brief  Set External Trigger Selection for injected group.
  * @param  ADCx ADC Instance
  * @param  iextsel
            @arg @ref MD_ADC_ICHS_IEXTSEL_AD16C4T1_CH4
            @arg @ref MD_ADC_ICHS_IEXTSEL_AD16C4T1_TRGOUT
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP32C4T1_CH1
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP32C4T1_TRGOUT
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T1_CH2
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T1_CH3
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T1_CH4
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T2_CH1
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T2_CH2
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T2_CH3
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T2_TRGOUT
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T3_CH4
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T3_TRGOUT
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C2T1_TRGOUT
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C2T2_TRGOUT
            @arg @ref MD_ADC_ICHS_IEXTSEL_EXTI_TRG1
  * @retval None
  */
__STATIC_INLINE void md_adc_set_inj_external_trigger_source(ADC_TypeDef *ADCx, uint32_t iextsel)
{
    MODIFY_REG(ADCx->ICHS, ADC_ICHS_IEXTSEL, iextsel << ADC_ICHS_IEXTSEL_POSS);
}

/**
  * @brief  Get External Trigger Selection for injected group.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_ICHS_IEXTSEL_AD16C4T1_CH4
            @arg @ref MD_ADC_ICHS_IEXTSEL_AD16C4T1_TRGOUT
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP32C4T1_CH1
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP32C4T1_TRGOUT
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T1_CH2
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T1_CH3
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T1_CH4
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T2_CH1
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T2_CH2
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T2_CH3
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T2_TRGOUT
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T3_CH4
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C4T3_TRGOUT
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C2T1_TRGOUT
            @arg @ref MD_ADC_ICHS_IEXTSEL_GP16C2T2_TRGOUT
            @arg @ref MD_ADC_ICHS_IEXTSEL_EXTI_TRG1
  */
__STATIC_INLINE uint32_t md_adc_get_inj_external_trigger_source(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->ICHS, ADC_ICHS_IEXTSEL)) >> ADC_ICHS_IEXTSEL_POSS);
}

/**
  * @brief  Set Injected channel sequence length.
  * @param  ADCx ADC Instance
  * @param  isl
            @arg @ref MD_ADC_ICHS_ISL_1CON
            @arg @ref MD_ADC_ICHS_ISL_2CON
            @arg @ref MD_ADC_ICHS_ISL_3CON
            @arg @ref MD_ADC_ICHS_ISL_4CON
  * @retval None
  */
__STATIC_INLINE void md_adc_set_inj_sequence_length(ADC_TypeDef *ADCx, uint32_t isl)
{
    MODIFY_REG(ADCx->ICHS, ADC_ICHS_ISL, isl << ADC_ICHS_ISL_POSS);
}

/**
  * @brief  Get Injected channel sequence length.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_ICHS_ISL_1CON
            @arg @ref MD_ADC_ICHS_ISL_2CON
            @arg @ref MD_ADC_ICHS_ISL_3CON
            @arg @ref MD_ADC_ICHS_ISL_4CON
  */
__STATIC_INLINE uint32_t md_adc_get_inj_sequence_length(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->ICHS, ADC_ICHS_ISL)) >> ADC_ICHS_ISL_POSS);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group22 OFF1
  * @{
  */
/**
  * @brief  Set ADC_OFF1 Register
  * @param  ADCx ADC Instance
  * @param  off1
  * @retval None
  */
__STATIC_INLINE void md_adc_set_off1(ADC_TypeDef *ADCx, uint32_t off1)
{
    WRITE_REG(ADCx->OFF1, off1);
}

/**
  * @brief  Get ADC_OFF1 Register
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_off1(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_REG(ADCx->OFF1));
}

/**
  * @brief  Offset enable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_offset_compensation_1(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->OFF1, ADC_OFF1_OFFEN);
}

/**
  * @brief  Offset Disable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_offset_compensation_1(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->OFF1, ADC_OFF1_OFFEN);
}

/**
  * @brief  Check if Offset is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_disableb_offset_compensation_1(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->OFF1, ADC_OFF1_OFFEN) == (ADC_OFF1_OFFEN));
}

/**
  * @brief  Set Channel selection for the data offset.
  * @param  ADCx ADC Instance
  * @param  offch
            @arg @ref MD_ADC_OFF1_OFFCH_CH0
            @arg @ref MD_ADC_OFF1_OFFCH_CH1
            @arg @ref MD_ADC_OFF1_OFFCH_CH2
            @arg @ref MD_ADC_OFF1_OFFCH_CH3
            @arg @ref MD_ADC_OFF1_OFFCH_CH4
            @arg @ref MD_ADC_OFF1_OFFCH_CH5
            @arg @ref MD_ADC_OFF1_OFFCH_CH6
            @arg @ref MD_ADC_OFF1_OFFCH_CH7
            @arg @ref MD_ADC_OFF1_OFFCH_CH8
            @arg @ref MD_ADC_OFF1_OFFCH_CH9
            @arg @ref MD_ADC_OFF1_OFFCH_CH10
            @arg @ref MD_ADC_OFF1_OFFCH_CH11
            @arg @ref MD_ADC_OFF1_OFFCH_CH12
            @arg @ref MD_ADC_OFF1_OFFCH_CH13
            @arg @ref MD_ADC_OFF1_OFFCH_CH14
            @arg @ref MD_ADC_OFF1_OFFCH_CH15
            @arg @ref MD_ADC_OFF1_OFFCH_CH16
            @arg @ref MD_ADC_OFF1_OFFCH_CH17
            @arg @ref MD_ADC_OFF1_OFFCH_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_compensation_channel_selection_1(ADC_TypeDef *ADCx, uint32_t offch)
{
    MODIFY_REG(ADCx->OFF1, ADC_OFF1_OFFCH, offch << ADC_OFF1_OFFCH_POSS);
}

/**
  * @brief  Get Channel selection for the data offset.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_OFF1_OFFCH_CH0
            @arg @ref MD_ADC_OFF1_OFFCH_CH1
            @arg @ref MD_ADC_OFF1_OFFCH_CH2
            @arg @ref MD_ADC_OFF1_OFFCH_CH3
            @arg @ref MD_ADC_OFF1_OFFCH_CH4
            @arg @ref MD_ADC_OFF1_OFFCH_CH5
            @arg @ref MD_ADC_OFF1_OFFCH_CH6
            @arg @ref MD_ADC_OFF1_OFFCH_CH7
            @arg @ref MD_ADC_OFF1_OFFCH_CH8
            @arg @ref MD_ADC_OFF1_OFFCH_CH9
            @arg @ref MD_ADC_OFF1_OFFCH_CH10
            @arg @ref MD_ADC_OFF1_OFFCH_CH11
            @arg @ref MD_ADC_OFF1_OFFCH_CH12
            @arg @ref MD_ADC_OFF1_OFFCH_CH13
            @arg @ref MD_ADC_OFF1_OFFCH_CH14
            @arg @ref MD_ADC_OFF1_OFFCH_CH15
            @arg @ref MD_ADC_OFF1_OFFCH_CH16
            @arg @ref MD_ADC_OFF1_OFFCH_CH17
            @arg @ref MD_ADC_OFF1_OFFCH_CH18
  */
__STATIC_INLINE uint32_t md_adc_disable_compensation_channel_selection_1(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->OFF1, ADC_OFF1_OFFCH) >> ADC_OFF1_OFFCH_POSS);
}

/**
  * @brief  Saturation enable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_compensation_saturation_1(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->OFF1, ADC_OFF1_SATEN);
}

/**
  * @brief  Saturation Disable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_compensation_saturation_1(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->OFF1, ADC_OFF1_SATEN);
}

/**
  * @brief  Check if Saturation is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_disabled_compensation_saturation_1(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->OFF1, ADC_OFF1_SATEN) == (ADC_OFF1_SATEN));
}

/**
  * @brief  Set Positive offset.
  * @param  ADCx ADC Instance
  * @param  offpen
            @arg @ref MD_ADC_OFF1_OFFPEN_NEGATIVE
            @arg @ref MD_ADC_OFF1_OFFPEN_POSITIVE
  * @retval None
  */
__STATIC_INLINE void md_adc_set_compensation_polarity_1(ADC_TypeDef *ADCx, uint32_t offpen)
{
    MODIFY_REG(ADCx->OFF1, ADC_OFF1_OFFPEN, offpen << ADC_OFF1_OFFPEN_POS);
}

/**
  * @brief  Get Positive offset.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_OFF1_OFFPEN_NEGATIVE
            @arg @ref MD_ADC_OFF1_OFFPEN_POSITIVE
  */
__STATIC_INLINE uint32_t md_adc_get_compensation_polarity_1(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->OFF1, ADC_OFF1_OFFPEN)) >> ADC_OFF1_OFFPEN_POS);
}

/**
  * @brief  Set Data offset y for the channel programmed into bits OFFCH[4:0].
  * @param  ADCx ADC Instance
  * @param  off
  * @retval None
  */
__STATIC_INLINE void md_adc_set_compensation_value_1(ADC_TypeDef *ADCx, uint32_t off)
{
    MODIFY_REG(ADCx->OFF1, ADC_OFF1_OFF, off << ADC_OFF1_OFF_POSS);
}

/**
  * @brief  Get Data offset y for the channel programmed into bits OFFCH[4:0].
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_compensation_value_1(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->OFF1, ADC_OFF1_OFF)) >> ADC_OFF1_OFF_POSS);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group23 OFF2
  * @{
  */
/**
  * @brief  Set ADC_OFF2 Register
  * @param  ADCx ADC Instance
  * @param  off2
  * @retval None
  */
__STATIC_INLINE void md_adc_set_off2(ADC_TypeDef *ADCx, uint32_t off2)
{
    WRITE_REG(ADCx->OFF2, off2);
}

/**
  * @brief  Get ADC_OFF2 Register
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_off2(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_REG(ADCx->OFF2));
}

/**
  * @brief  Offset enable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_offset_compensation_2(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->OFF2, ADC_OFF2_OFFEN);
}

/**
  * @brief  Offset Disable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_offset_compensation_2(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->OFF2, ADC_OFF2_OFFEN);
}

/**
  * @brief  Check if Offset is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_disableb_offset_compensation_2(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->OFF2, ADC_OFF2_OFFEN) == (ADC_OFF2_OFFEN));
}

/**
  * @brief  Set Channel selection for the data offset.
  * @param  ADCx ADC Instance
  * @param  offch
            @arg @ref MD_ADC_OFF2_OFFCH_CH0
            @arg @ref MD_ADC_OFF2_OFFCH_CH1
            @arg @ref MD_ADC_OFF2_OFFCH_CH2
            @arg @ref MD_ADC_OFF2_OFFCH_CH3
            @arg @ref MD_ADC_OFF2_OFFCH_CH4
            @arg @ref MD_ADC_OFF2_OFFCH_CH5
            @arg @ref MD_ADC_OFF2_OFFCH_CH6
            @arg @ref MD_ADC_OFF2_OFFCH_CH7
            @arg @ref MD_ADC_OFF2_OFFCH_CH8
            @arg @ref MD_ADC_OFF2_OFFCH_CH9
            @arg @ref MD_ADC_OFF2_OFFCH_CH10
            @arg @ref MD_ADC_OFF2_OFFCH_CH11
            @arg @ref MD_ADC_OFF2_OFFCH_CH12
            @arg @ref MD_ADC_OFF2_OFFCH_CH13
            @arg @ref MD_ADC_OFF2_OFFCH_CH14
            @arg @ref MD_ADC_OFF2_OFFCH_CH15
            @arg @ref MD_ADC_OFF2_OFFCH_CH16
            @arg @ref MD_ADC_OFF2_OFFCH_CH17
            @arg @ref MD_ADC_OFF2_OFFCH_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_compensation_channel_selection_2(ADC_TypeDef *ADCx, uint32_t offch)
{
    MODIFY_REG(ADCx->OFF2, ADC_OFF2_OFFCH, offch << ADC_OFF2_OFFCH_POSS);
}

/**
  * @brief  Get Channel selection for the data offset.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_OFF2_OFFCH_CH0
            @arg @ref MD_ADC_OFF2_OFFCH_CH1
            @arg @ref MD_ADC_OFF2_OFFCH_CH2
            @arg @ref MD_ADC_OFF2_OFFCH_CH3
            @arg @ref MD_ADC_OFF2_OFFCH_CH4
            @arg @ref MD_ADC_OFF2_OFFCH_CH5
            @arg @ref MD_ADC_OFF2_OFFCH_CH6
            @arg @ref MD_ADC_OFF2_OFFCH_CH7
            @arg @ref MD_ADC_OFF2_OFFCH_CH8
            @arg @ref MD_ADC_OFF2_OFFCH_CH9
            @arg @ref MD_ADC_OFF2_OFFCH_CH10
            @arg @ref MD_ADC_OFF2_OFFCH_CH11
            @arg @ref MD_ADC_OFF2_OFFCH_CH12
            @arg @ref MD_ADC_OFF2_OFFCH_CH13
            @arg @ref MD_ADC_OFF2_OFFCH_CH14
            @arg @ref MD_ADC_OFF2_OFFCH_CH15
            @arg @ref MD_ADC_OFF2_OFFCH_CH16
            @arg @ref MD_ADC_OFF2_OFFCH_CH17
            @arg @ref MD_ADC_OFF2_OFFCH_CH18
  */
__STATIC_INLINE uint32_t md_adc_disable_compensation_channel_selection_2(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->OFF2, ADC_OFF2_OFFCH) >> ADC_OFF2_OFFCH_POSS);
}

/**
  * @brief  Saturation enable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_compensation_saturation_2(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->OFF2, ADC_OFF2_SATEN);
}

/**
  * @brief  Saturation Disable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_compensation_saturation_2(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->OFF2, ADC_OFF2_SATEN);
}

/**
  * @brief  Check if Saturation is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_disabled_compensation_saturation_2(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->OFF2, ADC_OFF2_SATEN) == (ADC_OFF2_SATEN));
}

/**
  * @brief  Set Positive offset.
  * @param  ADCx ADC Instance
  * @param  offpen
            @arg @ref MD_ADC_OFF2_OFFPEN_NEGATIVE
            @arg @ref MD_ADC_OFF2_OFFPEN_POSITIVE
  * @retval None
  */
__STATIC_INLINE void md_adc_set_compensation_polarity_2(ADC_TypeDef *ADCx, uint32_t offpen)
{
    MODIFY_REG(ADCx->OFF2, ADC_OFF2_OFFPEN, offpen << ADC_OFF2_OFFPEN_POS);
}

/**
  * @brief  Get Positive offset.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_OFF2_OFFPEN_NEGATIVE
            @arg @ref MD_ADC_OFF2_OFFPEN_POSITIVE
  */
__STATIC_INLINE uint32_t md_adc_get_compensation_polarity_2(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->OFF2, ADC_OFF2_OFFPEN)) >> ADC_OFF2_OFFPEN_POS);
}

/**
  * @brief  Set Data offset y for the channel programmed into bits OFFCH[4:0].
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_set_compensation_value_2(ADC_TypeDef *ADCx, uint32_t off)
{
    MODIFY_REG(ADCx->OFF2, ADC_OFF2_OFF, off << ADC_OFF2_OFF_POSS);
}

/**
  * @brief  Get Data offset y for the channel programmed into bits OFFCH[4:0].
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_compensation_value_2(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->OFF2, ADC_OFF2_OFF)) >> ADC_OFF2_OFF_POSS);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group24 OFF3
  * @{
  */
/**
  * @brief  Set ADC_OFF3 Register
  * @param  ADCx ADC Instance
  * @param  off3
  * @retval None
  */
__STATIC_INLINE void md_adc_set_off3(ADC_TypeDef *ADCx, uint32_t off3)
{
    WRITE_REG(ADCx->OFF3, off3);
}

/**
  * @brief  Get ADC_OFF3 Register
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_off3(ADC_TypeDef *ADCx)
{
    return (uint32_t)READ_REG(ADCx->OFF3);
}

/**
  * @brief  Offset enable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_offset_compensation_3(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->OFF3, ADC_OFF3_OFFEN);
}

/**
  * @brief  Offset Disable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_offset_compensation_3(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->OFF3, ADC_OFF3_OFFEN);
}

/**
  * @brief  Check if Offset is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_disableb_offset_compensation_3(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->OFF3, ADC_OFF3_OFFEN) == (ADC_OFF3_OFFEN));
}

/**
  * @brief  Set Channel selection for the data offset.
  * @param  ADCx ADC Instance
  * @param  offch
            @arg @ref MD_ADC_OFF3_OFFCH_CH0
            @arg @ref MD_ADC_OFF3_OFFCH_CH1
            @arg @ref MD_ADC_OFF3_OFFCH_CH2
            @arg @ref MD_ADC_OFF3_OFFCH_CH3
            @arg @ref MD_ADC_OFF3_OFFCH_CH4
            @arg @ref MD_ADC_OFF3_OFFCH_CH5
            @arg @ref MD_ADC_OFF3_OFFCH_CH6
            @arg @ref MD_ADC_OFF3_OFFCH_CH7
            @arg @ref MD_ADC_OFF3_OFFCH_CH8
            @arg @ref MD_ADC_OFF3_OFFCH_CH9
            @arg @ref MD_ADC_OFF3_OFFCH_CH10
            @arg @ref MD_ADC_OFF3_OFFCH_CH11
            @arg @ref MD_ADC_OFF3_OFFCH_CH12
            @arg @ref MD_ADC_OFF3_OFFCH_CH13
            @arg @ref MD_ADC_OFF3_OFFCH_CH14
            @arg @ref MD_ADC_OFF3_OFFCH_CH15
            @arg @ref MD_ADC_OFF3_OFFCH_CH16
            @arg @ref MD_ADC_OFF3_OFFCH_CH17
            @arg @ref MD_ADC_OFF3_OFFCH_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_compensation_channel_selection_3(ADC_TypeDef *ADCx, uint32_t offch)
{
    MODIFY_REG(ADCx->OFF3, ADC_OFF3_OFFCH, offch << ADC_OFF3_OFFCH_POSS);
}

/**
  * @brief  Get Channel selection for the data offset.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_OFF3_OFFCH_CH0
            @arg @ref MD_ADC_OFF3_OFFCH_CH1
            @arg @ref MD_ADC_OFF3_OFFCH_CH2
            @arg @ref MD_ADC_OFF3_OFFCH_CH3
            @arg @ref MD_ADC_OFF3_OFFCH_CH4
            @arg @ref MD_ADC_OFF3_OFFCH_CH5
            @arg @ref MD_ADC_OFF3_OFFCH_CH6
            @arg @ref MD_ADC_OFF3_OFFCH_CH7
            @arg @ref MD_ADC_OFF3_OFFCH_CH8
            @arg @ref MD_ADC_OFF3_OFFCH_CH9
            @arg @ref MD_ADC_OFF3_OFFCH_CH10
            @arg @ref MD_ADC_OFF3_OFFCH_CH11
            @arg @ref MD_ADC_OFF3_OFFCH_CH12
            @arg @ref MD_ADC_OFF3_OFFCH_CH13
            @arg @ref MD_ADC_OFF3_OFFCH_CH14
            @arg @ref MD_ADC_OFF3_OFFCH_CH15
            @arg @ref MD_ADC_OFF3_OFFCH_CH16
            @arg @ref MD_ADC_OFF3_OFFCH_CH17
            @arg @ref MD_ADC_OFF3_OFFCH_CH18
  */
__STATIC_INLINE uint32_t md_adc_disable_compensation_channel_selection_3(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->OFF3, ADC_OFF3_OFFCH) >> ADC_OFF3_OFFCH_POSS);
}

/**
  * @brief  Saturation enable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_compensation_saturation_3(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->OFF3, ADC_OFF3_SATEN);
}

/**
  * @brief  Saturation Disable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_compensation_saturation_3(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->OFF3, ADC_OFF3_SATEN);
}

/**
  * @brief  Check if Saturation is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_disabled_compensation_saturation_3(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->OFF3, ADC_OFF3_SATEN) == (ADC_OFF3_SATEN));
}

/**
  * @brief  Set Positive offset.
  * @param  ADCx ADC Instance
  * @param  offpen
            @arg @ref MD_ADC_OFF3_OFFPEN_NEGATIVE
            @arg @ref MD_ADC_OFF3_OFFPEN_POSITIVE
  * @retval None
  */
__STATIC_INLINE void md_adc_set_compensation_polarity_3(ADC_TypeDef *ADCx, uint32_t offpen)
{
    MODIFY_REG(ADCx->OFF3, ADC_OFF3_OFFPEN, offpen << ADC_OFF3_OFFPEN_POS);
}

/**
  * @brief  Get Positive offset.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_OFF3_OFFPEN_NEGATIVE
            @arg @ref MD_ADC_OFF3_OFFPEN_POSITIVE
  */
__STATIC_INLINE uint32_t md_adc_get_compensation_polarity_3(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->OFF3, ADC_OFF3_OFFPEN)) >> ADC_OFF3_OFFPEN_POS);
}

/**
  * @brief  Set Data offset y for the channel programmed into bits OFFCH[4:0].
  * @param  ADCx ADC Instance
  * @param  off
  * @retval None
  */
__STATIC_INLINE void md_adc_set_compensation_value_3(ADC_TypeDef *ADCx, uint32_t off)
{
    MODIFY_REG(ADCx->OFF3, ADC_OFF3_OFF, off << ADC_OFF3_OFF_POSS);
}

/**
  * @brief  Get Data offset y for the channel programmed into bits OFFCH[4:0].
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_compensation_value_3(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->OFF3, ADC_OFF3_OFF)) >> ADC_OFF3_OFF_POSS);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group25 OFF4
  * @{
  */
/**
  * @brief  Set ADC_OFF4 Register
  * @param  ADCx ADC Instance
  * @param  off4
  * @retval None
  */
__STATIC_INLINE void md_adc_set_off4(ADC_TypeDef *ADCx, uint32_t off4)
{
    WRITE_REG(ADCx->OFF4, off4);
}

/**
  * @brief  Get ADC_OFF4 Register
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_off4(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_REG(ADCx->OFF4));
}

/**
  * @brief  Offset enable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_offset_compensation_4(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->OFF4, ADC_OFF4_OFFEN);
}

/**
  * @brief  Offset Disable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_offset_compensation_4(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->OFF4, ADC_OFF4_OFFEN);
}

/**
  * @brief  Check if Offset is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_disableb_offset_compensation_4(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->OFF4, ADC_OFF4_OFFEN) == (ADC_OFF4_OFFEN));
}

/**
  * @brief  Set Channel selection for the data offset.
  * @param  ADCx ADC Instance
  * @param  offch
            @arg @ref MD_ADC_OFF4_OFFCH_CH0
            @arg @ref MD_ADC_OFF4_OFFCH_CH1
            @arg @ref MD_ADC_OFF4_OFFCH_CH2
            @arg @ref MD_ADC_OFF4_OFFCH_CH3
            @arg @ref MD_ADC_OFF4_OFFCH_CH4
            @arg @ref MD_ADC_OFF4_OFFCH_CH5
            @arg @ref MD_ADC_OFF4_OFFCH_CH6
            @arg @ref MD_ADC_OFF4_OFFCH_CH7
            @arg @ref MD_ADC_OFF4_OFFCH_CH8
            @arg @ref MD_ADC_OFF4_OFFCH_CH9
            @arg @ref MD_ADC_OFF4_OFFCH_CH10
            @arg @ref MD_ADC_OFF4_OFFCH_CH11
            @arg @ref MD_ADC_OFF4_OFFCH_CH12
            @arg @ref MD_ADC_OFF4_OFFCH_CH13
            @arg @ref MD_ADC_OFF4_OFFCH_CH14
            @arg @ref MD_ADC_OFF4_OFFCH_CH15
            @arg @ref MD_ADC_OFF4_OFFCH_CH16
            @arg @ref MD_ADC_OFF4_OFFCH_CH17
            @arg @ref MD_ADC_OFF4_OFFCH_CH18
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_compensation_channel_selection_4(ADC_TypeDef *ADCx, uint32_t offch)
{
    MODIFY_REG(ADCx->OFF4, ADC_OFF4_OFFCH, offch << ADC_OFF4_OFFCH_POSS);
}

/**
  * @brief  Get Channel selection for the data offset.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_OFF4_OFFCH_CH0
            @arg @ref MD_ADC_OFF4_OFFCH_CH1
            @arg @ref MD_ADC_OFF4_OFFCH_CH2
            @arg @ref MD_ADC_OFF4_OFFCH_CH3
            @arg @ref MD_ADC_OFF4_OFFCH_CH4
            @arg @ref MD_ADC_OFF4_OFFCH_CH5
            @arg @ref MD_ADC_OFF4_OFFCH_CH6
            @arg @ref MD_ADC_OFF4_OFFCH_CH7
            @arg @ref MD_ADC_OFF4_OFFCH_CH8
            @arg @ref MD_ADC_OFF4_OFFCH_CH9
            @arg @ref MD_ADC_OFF4_OFFCH_CH10
            @arg @ref MD_ADC_OFF4_OFFCH_CH11
            @arg @ref MD_ADC_OFF4_OFFCH_CH12
            @arg @ref MD_ADC_OFF4_OFFCH_CH13
            @arg @ref MD_ADC_OFF4_OFFCH_CH14
            @arg @ref MD_ADC_OFF4_OFFCH_CH15
            @arg @ref MD_ADC_OFF4_OFFCH_CH16
            @arg @ref MD_ADC_OFF4_OFFCH_CH17
            @arg @ref MD_ADC_OFF4_OFFCH_CH18
  */
__STATIC_INLINE uint32_t md_adc_disable_compensation_channel_selection_4(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->OFF4, ADC_OFF4_OFFCH) >> ADC_OFF4_OFFCH_POSS);
}

/**
  * @brief  Saturation enable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_enable_compensation_saturation_4(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->OFF4, ADC_OFF4_SATEN);
}

/**
  * @brief  Saturation Disable.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE void md_adc_disable_compensation_saturation_4(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->OFF4, ADC_OFF4_SATEN);
}

/**
  * @brief  Check if Saturation is enabled.
  * @param  ADCx ADC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_adc_is_disabled_compensation_saturation_4(ADC_TypeDef *ADCx)
{
    return (READ_BIT(ADCx->OFF4, ADC_OFF4_SATEN) == (ADC_OFF4_SATEN));
}

/**
  * @brief  Set Positive offset.
  * @param  ADCx ADC Instance
  * @param  offpen
            @arg @ref MD_ADC_OFF3_OFFPEN_NEGATIVE
            @arg @ref MD_ADC_OFF3_OFFPEN_POSITIVE
  * @retval None
  */
__STATIC_INLINE void md_adc_set_compensation_polarity_4(ADC_TypeDef *ADCx, uint32_t offpen)
{
    MODIFY_REG(ADCx->OFF4, ADC_OFF4_OFFPEN, offpen);
}

/**
  * @brief  Get Positive offset.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_OFF3_OFFPEN_NEGATIVE
            @arg @ref MD_ADC_OFF3_OFFPEN_POSITIVE
  */
__STATIC_INLINE uint32_t md_adc_get_compensation_polarity_4(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->OFF4, ADC_OFF4_OFFPEN)));
}

/**
  * @brief  Set Data offset y for the channel programmed into bits OFFCH[4:0].
  * @param  ADCx ADC Instance
  * @param  off
  * @retval None
  */
__STATIC_INLINE void md_adc_set_compensation_value_4(ADC_TypeDef *ADCx, uint32_t off)
{
    MODIFY_REG(ADCx->OFF4, ADC_OFF4_OFF, off << ADC_OFF4_OFF_POSS);
}

/**
  * @brief  Get Data offset y for the channel programmed into bits OFFCH[4:0].
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_compensation_value_4(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->OFF4, ADC_OFF4_OFF)) >> ADC_OFF4_OFF_POSS);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group26 ICHDR1
  * @{
  */
/**
  * @brief  Get Injected data.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_inj_data_1(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ICHDR1, ADC_ICHDR1_VAL));
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group27 ICHDR2
  * @{
  */
/**
  * @brief  Get Injected data.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_inj_data_2(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ICHDR2, ADC_ICHDR2_VAL));
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group28 ICHDR3
  * @{
  */
/**
  * @brief  Get Injected data.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_inj_data_3(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ICHDR3, ADC_ICHDR3_VAL));
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group29 ICHDR4
  * @{
  */
/**
  * @brief  Get Injected data.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_inj_data_4(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ICHDR4, ADC_ICHDR4_VAL));
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group30 CALCR
  * @{
  */
/**
  * @brief  Set ADC_CALCR Register
  * @param  ADCx ADC Instance
  * @param  calcr
  * @retval None
  */
__STATIC_INLINE void md_adc_set_calcr(ADC_TypeDef *ADCx, uint32_t calcr)
{
    WRITE_REG(ADCx->CALCR, calcr);
}

/**
  * @brief  Get ADC_CALCR Register
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_calcr(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_REG(ADCx->CALCR));
}

/**
  * @brief  Set Offset Compensation Coefficient.
  * @param  ADCx ADC Instance
  * @param  ocomcoe
  * @retval None
  */
__STATIC_INLINE void md_adc_set_offset_factor(ADC_TypeDef *ADCx, uint32_t ocomcoe)
{
    MODIFY_REG(ADCx->CALCR, ADC_CALCR_OCOMCOE, ocomcoe << ADC_CALCR_OCOMCOE_POSS);
}

/**
  * @brief  Get Offset Compensation Coefficient.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_offset_factor(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CALCR, ADC_CALCR_OCOMCOE)) >> ADC_CALCR_OCOMCOE_POSS);
}

/**
  * @brief  Set Gain Compensation Coefficient.
  * @param  ADCx ADC Instance
  * @param  gcomcoe
  * @retval None
  */
__STATIC_INLINE void md_adc_set_gain_factor(ADC_TypeDef *ADCx, uint32_t gcomcoe)
{
    MODIFY_REG(ADCx->CALCR, ADC_CALCR_GCOMCOE, gcomcoe << ADC_CALCR_GCOMCOE_POSS);
}

/**
  * @brief  Get Gain Compensation Coefficient.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_get_gain_factor(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CALCR, ADC_CALCR_GCOMCOE)) >> ADC_CALCR_GCOMCOE_POSS);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group31 CCR
  * @{
  */
/**
  * @brief  Set Internal reference voltage scaling output selection.
  * @param  ADCx ADC Instance
  * @param  refints
            @arg @ref MD_ADC_CCR_REFINTS_4DIV16
            @arg @ref MD_ADC_CCR_REFINTS_8DIV16
            @arg @ref MD_ADC_CCR_REFINTS_12DIV16
            @arg @ref MD_ADC_CCR_REFINTS_16DIV16
            @arg @ref MD_ADC_CCR_REFINTS_1DIV16
            @arg @ref MD_ADC_CCR_REFINTS_15DIV16
  * @retval None
  */
__STATIC_INLINE void md_adc_set_vref_level(ADC_TypeDef *ADCx, uint32_t refints)
{
    MODIFY_REG(ADCx->CCR, ADC_CCR_REFINTS, refints << ADC_CCR_REFINTS_POSS);
}

/**
  * @brief  Get Internal reference voltage scaling output selection.
  * @param  ADCx ADC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_ADC_CCR_REFINTS_4DIV16
            @arg @ref MD_ADC_CCR_REFINTS_8DIV16
            @arg @ref MD_ADC_CCR_REFINTS_12DIV16
            @arg @ref MD_ADC_CCR_REFINTS_16DIV16
            @arg @ref MD_ADC_CCR_REFINTS_1DIV16
            @arg @ref MD_ADC_CCR_REFINTS_15DIV16
  */
__STATIC_INLINE uint32_t md_adc_get_vref_level(ADC_TypeDef *ADCx)
{
    return (uint32_t)((READ_BIT(ADCx->CCR, ADC_CCR_REFINTS)) >> ADC_CCR_REFINTS_POSS);
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group32 SR
  * @{
  */
/**
  * @brief  Get Injected data.
  * @param  ADCx ADC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_adc_is_active_flag_normal_status(ADC_TypeDef *ADCx)
{
    return ((READ_BIT(ADCx->SR, ADC_SR_NDRE)) == (ADC_SR_NDRE));
}
/**
  * @}
  */

/** @defgroup MD_ADC_Public_Functions_Group1 Initialization
  * @{
  */
void md_adc_init(ADC_TypeDef *, md_adc_initial *);
void md_adc_sequence_conversion(ADC_TypeDef *, md_adc_initial *, uint32_t *);

ErrorStatus md_adc_calibration(ADC_TypeDef *, md_adc_initial *);
void md_adc_get_calibration(ADC_TypeDef *, uint8_t *, uint16_t *);
uint16_t md_adc_get_data(ADC_TypeDef *);

ErrorStatus md_adc_software_calibration(ADC_TypeDef *ADCx, md_adc_initial *);
ErrorStatus md_adc_optionbyte_calibration(ADC_TypeDef *ADCx, md_adc_initial *ADC_InitStruct);
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
