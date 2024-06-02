/**********************************************************************************
 *
 * @file    reg_adc.h
 * @brief   ADC Head File
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

#ifndef __ADC_H__
#define __ADC_H__


/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/

/*  Support for anonymous structures and unions.  */
//#pragma anon_unions

/****************** Bit definition for ADC_IER register ************************/

# define  ADC_IER_TO_POS 15U
# define  ADC_IER_TO_MSK BIT(ADC_IER_TO_POS)
# define  ADC_IER_TO     ADC_IER_TO_MSK

# define  ADC_IER_AWDF_POS 7U
# define  ADC_IER_AWDF_MSK BIT(ADC_IER_AWDF_POS)
# define  ADC_IER_AWDF     ADC_IER_AWDF_MSK

# define  ADC_IER_ISE_POS 6U
# define  ADC_IER_ISE_MSK BIT(ADC_IER_ISE_POS)
# define  ADC_IER_ISE     ADC_IER_ISE_MSK

# define  ADC_IER_ICHE_POS 5U
# define  ADC_IER_ICHE_MSK BIT(ADC_IER_ICHE_POS)
# define  ADC_IER_ICHE     ADC_IER_ICHE_MSK

# define  ADC_IER_OVR_POS 4U
# define  ADC_IER_OVR_MSK BIT(ADC_IER_OVR_POS)
# define  ADC_IER_OVR     ADC_IER_OVR_MSK

# define  ADC_IER_NSE_POS 3U
# define  ADC_IER_NSE_MSK BIT(ADC_IER_NSE_POS)
# define  ADC_IER_NSE     ADC_IER_NSE_MSK

# define  ADC_IER_NCHE_POS 2U
# define  ADC_IER_NCHE_MSK BIT(ADC_IER_NCHE_POS)
# define  ADC_IER_NCHE     ADC_IER_NCHE_MSK

# define  ADC_IER_SMPE_POS 1U
# define  ADC_IER_SMPE_MSK BIT(ADC_IER_SMPE_POS)
# define  ADC_IER_SMPE     ADC_IER_SMPE_MSK

# define  ADC_IER_ARDY_POS 0U
# define  ADC_IER_ARDY_MSK BIT(ADC_IER_ARDY_POS)
# define  ADC_IER_ARDY     ADC_IER_ARDY_MSK

/****************** Bit definition for ADC_IDR register ************************/

# define  ADC_IDR_TO_POS 15U
# define  ADC_IDR_TO_MSK BIT(ADC_IDR_TO_POS)
# define  ADC_IDR_TO     ADC_IDR_TO_MSK

# define  ADC_IDR_AWDF_POS 7U
# define  ADC_IDR_AWDF_MSK BIT(ADC_IDR_AWDF_POS)
# define  ADC_IDR_AWDF     ADC_IDR_AWDF_MSK

# define  ADC_IDR_ISE_POS 6U
# define  ADC_IDR_ISE_MSK BIT(ADC_IDR_ISE_POS)
# define  ADC_IDR_ISE     ADC_IDR_ISE_MSK

# define  ADC_IDR_ICHE_POS 5U
# define  ADC_IDR_ICHE_MSK BIT(ADC_IDR_ICHE_POS)
# define  ADC_IDR_ICHE     ADC_IDR_ICHE_MSK

# define  ADC_IDR_OVR_POS 4U
# define  ADC_IDR_OVR_MSK BIT(ADC_IDR_OVR_POS)
# define  ADC_IDR_OVR     ADC_IDR_OVR_MSK

# define  ADC_IDR_NSE_POS 3U
# define  ADC_IDR_NSE_MSK BIT(ADC_IDR_NSE_POS)
# define  ADC_IDR_NSE     ADC_IDR_NSE_MSK

# define  ADC_IDR_NCHE_POS 2U
# define  ADC_IDR_NCHE_MSK BIT(ADC_IDR_NCHE_POS)
# define  ADC_IDR_NCHE     ADC_IDR_NCHE_MSK

# define  ADC_IDR_SMPE_POS 1U
# define  ADC_IDR_SMPE_MSK BIT(ADC_IDR_SMPE_POS)
# define  ADC_IDR_SMPE     ADC_IDR_SMPE_MSK

# define  ADC_IDR_ARDY_POS 0U
# define  ADC_IDR_ARDY_MSK BIT(ADC_IDR_ARDY_POS)
# define  ADC_IDR_ARDY     ADC_IDR_ARDY_MSK

/****************** Bit definition for ADC_IVS register ************************/

# define  ADC_IVS_TO_POS 15U
# define  ADC_IVS_TO_MSK BIT(ADC_IVS_TO_POS)
# define  ADC_IVS_TO     ADC_IVS_TO_MSK

# define  ADC_IVS_AWDF_POS 7U
# define  ADC_IVS_AWDF_MSK BIT(ADC_IVS_AWDF_POS)
# define  ADC_IVS_AWDF     ADC_IVS_AWDF_MSK

# define  ADC_IVS_ISE_POS 6U
# define  ADC_IVS_ISE_MSK BIT(ADC_IVS_ISE_POS)
# define  ADC_IVS_ISE     ADC_IVS_ISE_MSK

# define  ADC_IVS_ICHE_POS 5U
# define  ADC_IVS_ICHE_MSK BIT(ADC_IVS_ICHE_POS)
# define  ADC_IVS_ICHE     ADC_IVS_ICHE_MSK

# define  ADC_IVS_OVR_POS 4U
# define  ADC_IVS_OVR_MSK BIT(ADC_IVS_OVR_POS)
# define  ADC_IVS_OVR     ADC_IVS_OVR_MSK

# define  ADC_IVS_NSE_POS 3U
# define  ADC_IVS_NSE_MSK BIT(ADC_IVS_NSE_POS)
# define  ADC_IVS_NSE     ADC_IVS_NSE_MSK

# define  ADC_IVS_NCHE_POS 2U
# define  ADC_IVS_NCHE_MSK BIT(ADC_IVS_NCHE_POS)
# define  ADC_IVS_NCHE     ADC_IVS_NCHE_MSK

# define  ADC_IVS_SMPE_POS 1U
# define  ADC_IVS_SMPE_MSK BIT(ADC_IVS_SMPE_POS)
# define  ADC_IVS_SMPE     ADC_IVS_SMPE_MSK

# define  ADC_IVS_ARDY_POS 0U
# define  ADC_IVS_ARDY_MSK BIT(ADC_IVS_ARDY_POS)
# define  ADC_IVS_ARDY     ADC_IVS_ARDY_MSK

/****************** Bit definition for ADC_RIF register ************************/

# define  ADC_RIF_TO_POS 15U
# define  ADC_RIF_TO_MSK BIT(ADC_RIF_TO_POS)
# define  ADC_RIF_TO     ADC_RIF_TO_MSK

# define  ADC_RIF_AWDF_POS 7U
# define  ADC_RIF_AWDF_MSK BIT(ADC_RIF_AWDF_POS)
# define  ADC_RIF_AWDF     ADC_RIF_AWDF_MSK

# define  ADC_RIF_ISE_POS 6U
# define  ADC_RIF_ISE_MSK BIT(ADC_RIF_ISE_POS)
# define  ADC_RIF_ISE     ADC_RIF_ISE_MSK

# define  ADC_RIF_ICHE_POS 5U
# define  ADC_RIF_ICHE_MSK BIT(ADC_RIF_ICHE_POS)
# define  ADC_RIF_ICHE     ADC_RIF_ICHE_MSK

# define  ADC_RIF_OVR_POS 4U
# define  ADC_RIF_OVR_MSK BIT(ADC_RIF_OVR_POS)
# define  ADC_RIF_OVR     ADC_RIF_OVR_MSK

# define  ADC_RIF_NSE_POS 3U
# define  ADC_RIF_NSE_MSK BIT(ADC_RIF_NSE_POS)
# define  ADC_RIF_NSE     ADC_RIF_NSE_MSK

# define  ADC_RIF_NCHE_POS 2U
# define  ADC_RIF_NCHE_MSK BIT(ADC_RIF_NCHE_POS)
# define  ADC_RIF_NCHE     ADC_RIF_NCHE_MSK

# define  ADC_RIF_SMPE_POS 1U
# define  ADC_RIF_SMPE_MSK BIT(ADC_RIF_SMPE_POS)
# define  ADC_RIF_SMPE     ADC_RIF_SMPE_MSK

# define  ADC_RIF_ARDY_POS 0U
# define  ADC_RIF_ARDY_MSK BIT(ADC_RIF_ARDY_POS)
# define  ADC_RIF_ARDY     ADC_RIF_ARDY_MSK

/****************** Bit definition for ADC_IFM register ************************/

# define  ADC_IFM_TO_POS 15U
# define  ADC_IFM_TO_MSK BIT(ADC_IFM_TO_POS)
# define  ADC_IFM_TO     ADC_IFM_TO_MSK

# define  ADC_IFM_AWDF_POS 7U
# define  ADC_IFM_AWDF_MSK BIT(ADC_IFM_AWDF_POS)
# define  ADC_IFM_AWDF     ADC_IFM_AWDF_MSK

# define  ADC_IFM_ISE_POS 6U
# define  ADC_IFM_ISE_MSK BIT(ADC_IFM_ISE_POS)
# define  ADC_IFM_ISE     ADC_IFM_ISE_MSK

# define  ADC_IFM_ICHE_POS 5U
# define  ADC_IFM_ICHE_MSK BIT(ADC_IFM_ICHE_POS)
# define  ADC_IFM_ICHE     ADC_IFM_ICHE_MSK

# define  ADC_IFM_OVR_POS 4U
# define  ADC_IFM_OVR_MSK BIT(ADC_IFM_OVR_POS)
# define  ADC_IFM_OVR     ADC_IFM_OVR_MSK

# define  ADC_IFM_NSE_POS 3U
# define  ADC_IFM_NSE_MSK BIT(ADC_IFM_NSE_POS)
# define  ADC_IFM_NSE     ADC_IFM_NSE_MSK

# define  ADC_IFM_NCHE_POS 2U
# define  ADC_IFM_NCHE_MSK BIT(ADC_IFM_NCHE_POS)
# define  ADC_IFM_NCHE     ADC_IFM_NCHE_MSK

# define  ADC_IFM_SMPE_POS 1U
# define  ADC_IFM_SMPE_MSK BIT(ADC_IFM_SMPE_POS)
# define  ADC_IFM_SMPE     ADC_IFM_SMPE_MSK

# define  ADC_IFM_ARDY_POS 0U
# define  ADC_IFM_ARDY_MSK BIT(ADC_IFM_ARDY_POS)
# define  ADC_IFM_ARDY     ADC_IFM_ARDY_MSK

/****************** Bit definition for ADC_ICR register ************************/

# define  ADC_ICR_TO_POS 15U
# define  ADC_ICR_TO_MSK BIT(ADC_ICR_TO_POS)
# define  ADC_ICR_TO     ADC_ICR_TO_MSK

# define  ADC_ICR_AWDF_POS 7U
# define  ADC_ICR_AWDF_MSK BIT(ADC_ICR_AWDF_POS)
# define  ADC_ICR_AWDF     ADC_ICR_AWDF_MSK

# define  ADC_ICR_ISE_POS 6U
# define  ADC_ICR_ISE_MSK BIT(ADC_ICR_ISE_POS)
# define  ADC_ICR_ISE     ADC_ICR_ISE_MSK

# define  ADC_ICR_ICHE_POS 5U
# define  ADC_ICR_ICHE_MSK BIT(ADC_ICR_ICHE_POS)
# define  ADC_ICR_ICHE     ADC_ICR_ICHE_MSK

# define  ADC_ICR_OVR_POS 4U
# define  ADC_ICR_OVR_MSK BIT(ADC_ICR_OVR_POS)
# define  ADC_ICR_OVR     ADC_ICR_OVR_MSK

# define  ADC_ICR_NSE_POS 3U
# define  ADC_ICR_NSE_MSK BIT(ADC_ICR_NSE_POS)
# define  ADC_ICR_NSE     ADC_ICR_NSE_MSK

# define  ADC_ICR_NCHE_POS 2U
# define  ADC_ICR_NCHE_MSK BIT(ADC_ICR_NCHE_POS)
# define  ADC_ICR_NCHE     ADC_ICR_NCHE_MSK

# define  ADC_ICR_SMPE_POS 1U
# define  ADC_ICR_SMPE_MSK BIT(ADC_ICR_SMPE_POS)
# define  ADC_ICR_SMPE     ADC_ICR_SMPE_MSK

# define  ADC_ICR_ARDY_POS 0U
# define  ADC_ICR_ARDY_MSK BIT(ADC_ICR_ARDY_POS)
# define  ADC_ICR_ARDY     ADC_ICR_ARDY_MSK

/****************** Bit definition for ADC_CON register ************************/

# define  ADC_CON_ADCAL_POS 31U
# define  ADC_CON_ADCAL_MSK BIT(ADC_CON_ADCAL_POS)
# define  ADC_CON_ADCAL     ADC_CON_ADCAL_MSK

# define  ADC_CON_DLYDATA_POS 7U
# define  ADC_CON_DLYDATA_MSK BIT(ADC_CON_DLYDATA_POS)
# define  ADC_CON_DLYDATA     ADC_CON_DLYDATA_MSK

# define  ADC_CON_ISTPC_POS 5U
# define  ADC_CON_ISTPC_MSK BIT(ADC_CON_ISTPC_POS)
# define  ADC_CON_ISTPC     ADC_CON_ISTPC_MSK

# define  ADC_CON_NSTPC_POS 4U
# define  ADC_CON_NSTPC_MSK BIT(ADC_CON_NSTPC_POS)
# define  ADC_CON_NSTPC     ADC_CON_NSTPC_MSK

# define  ADC_CON_ISTART_POS 3U
# define  ADC_CON_ISTART_MSK BIT(ADC_CON_ISTART_POS)
# define  ADC_CON_ISTART     ADC_CON_ISTART_MSK

# define  ADC_CON_NSTART_POS 2U
# define  ADC_CON_NSTART_MSK BIT(ADC_CON_NSTART_POS)
# define  ADC_CON_NSTART     ADC_CON_NSTART_MSK

# define  ADC_CON_ADCDIS_POS 1U
# define  ADC_CON_ADCDIS_MSK BIT(ADC_CON_ADCDIS_POS)
# define  ADC_CON_ADCDIS     ADC_CON_ADCDIS_MSK

# define  ADC_CON_ADCEN_POS 0U
# define  ADC_CON_ADCEN_MSK BIT(ADC_CON_ADCEN_POS)
# define  ADC_CON_ADCEN     ADC_CON_ADCEN_MSK

/****************** Bit definition for ADC_CFG register ************************/

# define  ADC_CFG_AWDCH_POSS 26U
# define  ADC_CFG_AWDCH_POSE 30U
# define  ADC_CFG_AWDCH_MSK  BITS(ADC_CFG_AWDCH_POSS, ADC_CFG_AWDCH_POSE)
# define  ADC_CFG_AWDCH      ADC_CFG_AWDCH_MSK

# define  ADC_CFG_IAUTO_POS 25U
# define  ADC_CFG_IAUTO_MSK BIT(ADC_CFG_IAUTO_POS)
# define  ADC_CFG_IAUTO     ADC_CFG_IAUTO_MSK

# define  ADC_CFG_IAWDEN_POS 24U
# define  ADC_CFG_IAWDEN_MSK BIT(ADC_CFG_IAWDEN_POS)
# define  ADC_CFG_IAWDEN     ADC_CFG_IAWDEN_MSK

# define  ADC_CFG_NAWDEN_POS 23U
# define  ADC_CFG_NAWDEN_MSK BIT(ADC_CFG_NAWDEN_POS)
# define  ADC_CFG_NAWDEN     ADC_CFG_NAWDEN_MSK

# define  ADC_CFG_AWDSGL_POS 22U
# define  ADC_CFG_AWDSGL_MSK BIT(ADC_CFG_AWDSGL_POS)
# define  ADC_CFG_AWDSGL     ADC_CFG_AWDSGL_MSK

# define  ADC_CFG_ICHDCEN_POS 20U
# define  ADC_CFG_ICHDCEN_MSK BIT(ADC_CFG_ICHDCEN_POS)
# define  ADC_CFG_ICHDCEN     ADC_CFG_ICHDCEN_MSK

# define  ADC_CFG_ETRGN_POSS 17U
# define  ADC_CFG_ETRGN_POSE 19U
# define  ADC_CFG_ETRGN_MSK  BITS(ADC_CFG_ETRGN_POSS, ADC_CFG_ETRGN_POSE)
# define  ADC_CFG_ETRGN      ADC_CFG_ETRGN_MSK

# define  ADC_CFG_NCHDCEN_POS 16U
# define  ADC_CFG_NCHDCEN_MSK BIT(ADC_CFG_NCHDCEN_POS)
# define  ADC_CFG_NCHDCEN     ADC_CFG_NCHDCEN_MSK

# define  ADC_CFG_AUTOFF_POS 15U
# define  ADC_CFG_AUTOFF_MSK BIT(ADC_CFG_AUTOFF_POS)
# define  ADC_CFG_AUTOFF     ADC_CFG_AUTOFF_MSK

# define  ADC_CFG_AUTODLY_POS 14U
# define  ADC_CFG_AUTODLY_MSK BIT(ADC_CFG_AUTODLY_POS)
# define  ADC_CFG_AUTODLY     ADC_CFG_AUTODLY_MSK

# define  ADC_CFG_CM_POS 13U
# define  ADC_CFG_CM_MSK BIT(ADC_CFG_CM_POS)
# define  ADC_CFG_CM     ADC_CFG_CM_MSK

# define  ADC_CFG_OVRMOD_POS 12U
# define  ADC_CFG_OVRMOD_MSK BIT(ADC_CFG_OVRMOD_POS)
# define  ADC_CFG_OVRMOD     ADC_CFG_OVRMOD_MSK

# define  ADC_CFG_NETS_POSS 10U
# define  ADC_CFG_NETS_POSE 11U
# define  ADC_CFG_NETS_MSK  BITS(ADC_CFG_NETS_POSS, ADC_CFG_NETS_POSE)
# define  ADC_CFG_NETS      ADC_CFG_NETS_MSK

# define  ADC_CFG_NEXTSEL_POSS 6U
# define  ADC_CFG_NEXTSEL_POSE 9U
# define  ADC_CFG_NEXTSEL_MSK  BITS(ADC_CFG_NEXTSEL_POSS, ADC_CFG_NEXTSEL_POSE)
# define  ADC_CFG_NEXTSEL      ADC_CFG_NEXTSEL_MSK

# define  ADC_CFG_ALIGN_POS 5U
# define  ADC_CFG_ALIGN_MSK BIT(ADC_CFG_ALIGN_POS)
# define  ADC_CFG_ALIGN     ADC_CFG_ALIGN_MSK

# define  ADC_CFG_RSEL_POSS 3U
# define  ADC_CFG_RSEL_POSE 4U
# define  ADC_CFG_RSEL_MSK  BITS(ADC_CFG_RSEL_POSS, ADC_CFG_RSEL_POSE)
# define  ADC_CFG_RSEL      ADC_CFG_RSEL_MSK

# define  ADC_CFG_DMAEN_POS 0U
# define  ADC_CFG_DMAEN_MSK BIT(ADC_CFG_DMAEN_POS)
# define  ADC_CFG_DMAEN     ADC_CFG_DMAEN_MSK

/****************** Bit definition for ADC_SMPT1 register ************************/

# define  ADC_SMPT1_CHTy_POSS 8U
# define  ADC_SMPT1_CHTy_POSE 31U
# define  ADC_SMPT1_CHTy_MSK  BITS(ADC_SMPT1_CHTy_POSS, ADC_SMPT1_CHTy_POSE)
# define  ADC_SMPT1_CHTy      ADC_SMPT1_CHTy_MSK

# define  ADC_SMPT1_CHT2_POSS 24U
# define  ADC_SMPT1_CHT2_POSE 31U
# define  ADC_SMPT1_CHT2_MSK  BITS(ADC_SMPT1_CHT2_POSS, ADC_SMPT1_CHT2_POSE)
# define  ADC_SMPT1_CHT2      ADC_SMPT1_CHT2_MSK

# define  ADC_SMPT1_CHT1_POSS 16U
# define  ADC_SMPT1_CHT1_POSE 23U
# define  ADC_SMPT1_CHT1_MSK  BITS(ADC_SMPT1_CHT1_POSS, ADC_SMPT1_CHT1_POSE)
# define  ADC_SMPT1_CHT1      ADC_SMPT1_CHT1_MSK

# define  ADC_SMPT1_CHT0_POSS 8U
# define  ADC_SMPT1_CHT0_POSE 15U
# define  ADC_SMPT1_CHT0_MSK  BITS(ADC_SMPT1_CHT0_POSS, ADC_SMPT1_CHT0_POSE)
# define  ADC_SMPT1_CHT0      ADC_SMPT1_CHT0_MSK

# define  ADC_SMPT1_CKDIV_POSS 0U
# define  ADC_SMPT1_CKDIV_POSE 2U
# define  ADC_SMPT1_CKDIV_MSK  BITS(ADC_SMPT1_CKDIV_POSS, ADC_SMPT1_CKDIV_POSE)
# define  ADC_SMPT1_CKDIV      ADC_SMPT1_CKDIV_MSK

/****************** Bit definition for ADC_SMPT2 register ************************/

# define  ADC_SMPT2_CHTy_POSS 0U
# define  ADC_SMPT2_CHTy_POSE 31U
# define  ADC_SMPT2_CHTy_MSK  BITS(ADC_SMPT2_CHTy_POSS, ADC_SMPT2_CHTy_POSE)
# define  ADC_SMPT2_CHTy      ADC_SMPT2_CHTy_MSK

# define  ADC_SMPT2_CHT6_POSS 24U
# define  ADC_SMPT2_CHT6_POSE 31U
# define  ADC_SMPT2_CHT6_MSK  BITS(ADC_SMPT2_CHT6_POSS, ADC_SMPT2_CHT6_POSE)
# define  ADC_SMPT2_CHT6      ADC_SMPT2_CHT6_MSK

# define  ADC_SMPT2_CHT5_POSS 16U
# define  ADC_SMPT2_CHT5_POSE 23U
# define  ADC_SMPT2_CHT5_MSK  BITS(ADC_SMPT2_CHT5_POSS, ADC_SMPT2_CHT5_POSE)
# define  ADC_SMPT2_CHT5      ADC_SMPT2_CHT5_MSK

# define  ADC_SMPT2_CHT4_POSS 8U
# define  ADC_SMPT2_CHT4_POSE 15U
# define  ADC_SMPT2_CHT4_MSK  BITS(ADC_SMPT2_CHT4_POSS, ADC_SMPT2_CHT4_POSE)
# define  ADC_SMPT2_CHT4      ADC_SMPT2_CHT4_MSK

# define  ADC_SMPT2_CHT3_POSS 0U
# define  ADC_SMPT2_CHT3_POSE 7U
# define  ADC_SMPT2_CHT3_MSK  BITS(ADC_SMPT2_CHT3_POSS, ADC_SMPT2_CHT3_POSE)
# define  ADC_SMPT2_CHT3      ADC_SMPT2_CHT3_MSK

/****************** Bit definition for ADC_SMPT3 register ************************/

# define  ADC_SMPT3_CHTy_POSS 0U
# define  ADC_SMPT3_CHTy_POSE 31U
# define  ADC_SMPT3_CHTy_MSK  BITS(ADC_SMPT3_CHTy_POSS, ADC_SMPT3_CHTy_POSE)
# define  ADC_SMPT3_CHTy      ADC_SMPT3_CHTy_MSK

# define  ADC_SMPT3_CHT10_POSS 24U
# define  ADC_SMPT3_CHT10_POSE 31U
# define  ADC_SMPT3_CHT10_MSK  BITS(ADC_SMPT3_CHT10_POSS, ADC_SMPT3_CHT10_POSE)
# define  ADC_SMPT3_CHT10      ADC_SMPT3_CHT10_MSK

# define  ADC_SMPT3_CHT9_POSS 16U
# define  ADC_SMPT3_CHT9_POSE 23U
# define  ADC_SMPT3_CHT9_MSK  BITS(ADC_SMPT3_CHT9_POSS, ADC_SMPT3_CHT9_POSE)
# define  ADC_SMPT3_CHT9      ADC_SMPT3_CHT9_MSK

# define  ADC_SMPT3_CHT8_POSS 8U
# define  ADC_SMPT3_CHT8_POSE 15U
# define  ADC_SMPT3_CHT8_MSK  BITS(ADC_SMPT3_CHT8_POSS, ADC_SMPT3_CHT8_POSE)
# define  ADC_SMPT3_CHT8      ADC_SMPT3_CHT8_MSK

# define  ADC_SMPT3_CHT7_POSS 0U
# define  ADC_SMPT3_CHT7_POSE 7U
# define  ADC_SMPT3_CHT7_MSK  BITS(ADC_SMPT3_CHT7_POSS, ADC_SMPT3_CHT7_POSE)
# define  ADC_SMPT3_CHT7      ADC_SMPT3_CHT7_MSK

/****************** Bit definition for ADC_SMPT4 register ************************/

# define  ADC_SMPT4_CHTy_POSS 0U
# define  ADC_SMPT4_CHTy_POSE 31U
# define  ADC_SMPT4_CHTy_MSK  BITS(ADC_SMPT4_CHTy_POSS, ADC_SMPT4_CHTy_POSE)
# define  ADC_SMPT4_CHTy      ADC_SMPT4_CHTy_MSK

# define  ADC_SMPT4_CHT14_POSS 24U
# define  ADC_SMPT4_CHT14_POSE 31U
# define  ADC_SMPT4_CHT14_MSK  BITS(ADC_SMPT4_CHT14_POSS, ADC_SMPT4_CHT14_POSE)
# define  ADC_SMPT4_CHT14      ADC_SMPT4_CHT14_MSK

# define  ADC_SMPT4_CHT13_POSS 16U
# define  ADC_SMPT4_CHT13_POSE 23U
# define  ADC_SMPT4_CHT13_MSK  BITS(ADC_SMPT4_CHT13_POSS, ADC_SMPT4_CHT13_POSE)
# define  ADC_SMPT4_CHT13      ADC_SMPT4_CHT13_MSK

# define  ADC_SMPT4_CHT12_POSS 8U
# define  ADC_SMPT4_CHT12_POSE 15U
# define  ADC_SMPT4_CHT12_MSK  BITS(ADC_SMPT4_CHT12_POSS, ADC_SMPT4_CHT12_POSE)
# define  ADC_SMPT4_CHT12      ADC_SMPT4_CHT12_MSK

# define  ADC_SMPT4_CHT11_POSS 0U
# define  ADC_SMPT4_CHT11_POSE 7U
# define  ADC_SMPT4_CHT11_MSK  BITS(ADC_SMPT4_CHT11_POSS, ADC_SMPT4_CHT11_POSE)
# define  ADC_SMPT4_CHT11      ADC_SMPT4_CHT11_MSK

/****************** Bit definition for ADC_SMPT5 register ************************/

# define  ADC_SMPT5_CHTy_POSS 0U
# define  ADC_SMPT5_CHTy_POSE 31U
# define  ADC_SMPT5_CHTy_MSK  BITS(ADC_SMPT5_CHTy_POSS, ADC_SMPT5_CHTy_POSE)
# define  ADC_SMPT5_CHTy      ADC_SMPT5_CHTy_MSK

# define  ADC_SMPT5_CHT18_POSS 24U
# define  ADC_SMPT5_CHT18_POSE 31U
# define  ADC_SMPT5_CHT18_MSK  BITS(ADC_SMPT5_CHT18_POSS, ADC_SMPT5_CHT18_POSE)
# define  ADC_SMPT5_CHT18      ADC_SMPT5_CHT18_MSK

# define  ADC_SMPT5_CHT17_POSS 16U
# define  ADC_SMPT5_CHT17_POSE 23U
# define  ADC_SMPT5_CHT17_MSK  BITS(ADC_SMPT5_CHT17_POSS, ADC_SMPT5_CHT17_POSE)
# define  ADC_SMPT5_CHT17      ADC_SMPT5_CHT17_MSK

# define  ADC_SMPT5_CHT16_POSS 8U
# define  ADC_SMPT5_CHT16_POSE 15U
# define  ADC_SMPT5_CHT16_MSK  BITS(ADC_SMPT5_CHT16_POSS, ADC_SMPT5_CHT16_POSE)
# define  ADC_SMPT5_CHT16      ADC_SMPT5_CHT16_MSK

# define  ADC_SMPT5_CHT15_POSS 0U
# define  ADC_SMPT5_CHT15_POSE 7U
# define  ADC_SMPT5_CHT15_MSK  BITS(ADC_SMPT5_CHT15_POSS, ADC_SMPT5_CHT15_POSE)
# define  ADC_SMPT5_CHT15      ADC_SMPT5_CHT15_MSK

/****************** Bit definition for ADC_WDTH register ************************/

# define  ADC_WDTH_HT_POSS 16U
# define  ADC_WDTH_HT_POSE 27U
# define  ADC_WDTH_HT_MSK  BITS(ADC_WDTH_HT_POSS, ADC_WDTH_HT_POSE)
# define  ADC_WDTH_HT      ADC_WDTH_HT_MSK

# define  ADC_WDTH_LT_POSS 0U
# define  ADC_WDTH_LT_POSE 11U
# define  ADC_WDTH_LT_MSK  BITS(ADC_WDTH_LT_POSS, ADC_WDTH_LT_POSE)
# define  ADC_WDTH_LT      ADC_WDTH_LT_MSK

/****************** Bit definition for ADC_NCHS1 register ************************/

# define  ADC_NCHS1_NS4_POSS 24U
# define  ADC_NCHS1_NS4_POSE 28U
# define  ADC_NCHS1_NS4_MSK  BITS(ADC_NCHS1_NS4_POSS, ADC_NCHS1_NS4_POSE)
# define  ADC_NCHS1_NS4      ADC_NCHS1_NS4_MSK

# define  ADC_NCHS1_NS3_POSS 18U
# define  ADC_NCHS1_NS3_POSE 22U
# define  ADC_NCHS1_NS3_MSK  BITS(ADC_NCHS1_NS3_POSS, ADC_NCHS1_NS3_POSE)
# define  ADC_NCHS1_NS3      ADC_NCHS1_NS3_MSK

# define  ADC_NCHS1_NS2_POSS 12U
# define  ADC_NCHS1_NS2_POSE 16U
# define  ADC_NCHS1_NS2_MSK  BITS(ADC_NCHS1_NS2_POSS, ADC_NCHS1_NS2_POSE)
# define  ADC_NCHS1_NS2      ADC_NCHS1_NS2_MSK

# define  ADC_NCHS1_NS1_POSS 6U
# define  ADC_NCHS1_NS1_POSE 10U
# define  ADC_NCHS1_NS1_MSK  BITS(ADC_NCHS1_NS1_POSS, ADC_NCHS1_NS1_POSE)
# define  ADC_NCHS1_NS1      ADC_NCHS1_NS1_MSK

# define  ADC_NCHS1_NSL_POSS 0U
# define  ADC_NCHS1_NSL_POSE 3U
# define  ADC_NCHS1_NSL_MSK  BITS(ADC_NCHS1_NSL_POSS, ADC_NCHS1_NSL_POSE)
# define  ADC_NCHS1_NSL      ADC_NCHS1_NSL_MSK

/****************** Bit definition for ADC_NCHS2 register ************************/

# define  ADC_NCHS2_NS9_POSS 24U
# define  ADC_NCHS2_NS9_POSE 28U
# define  ADC_NCHS2_NS9_MSK  BITS(ADC_NCHS2_NS9_POSS, ADC_NCHS2_NS9_POSE)
# define  ADC_NCHS2_NS9      ADC_NCHS2_NS9_MSK

# define  ADC_NCHS2_NS8_POSS 18U
# define  ADC_NCHS2_NS8_POSE 22U
# define  ADC_NCHS2_NS8_MSK  BITS(ADC_NCHS2_NS8_POSS, ADC_NCHS2_NS8_POSE)
# define  ADC_NCHS2_NS8      ADC_NCHS2_NS8_MSK

# define  ADC_NCHS2_NS7_POSS 12U
# define  ADC_NCHS2_NS7_POSE 16U
# define  ADC_NCHS2_NS7_MSK  BITS(ADC_NCHS2_NS7_POSS, ADC_NCHS2_NS7_POSE)
# define  ADC_NCHS2_NS7      ADC_NCHS2_NS7_MSK

# define  ADC_NCHS2_NS6_POSS 6U
# define  ADC_NCHS2_NS6_POSE 10U
# define  ADC_NCHS2_NS6_MSK  BITS(ADC_NCHS2_NS6_POSS, ADC_NCHS2_NS6_POSE)
# define  ADC_NCHS2_NS6      ADC_NCHS2_NS6_MSK

# define  ADC_NCHS2_NS5_POSS 0U
# define  ADC_NCHS2_NS5_POSE 4U
# define  ADC_NCHS2_NS5_MSK  BITS(ADC_NCHS2_NS5_POSS, ADC_NCHS2_NS5_POSE)
# define  ADC_NCHS2_NS5      ADC_NCHS2_NS5_MSK

/****************** Bit definition for ADC_NCHS3 register ************************/

# define  ADC_NCHS3_NS14_POSS 24U
# define  ADC_NCHS3_NS14_POSE 28U
# define  ADC_NCHS3_NS14_MSK  BITS(ADC_NCHS3_NS14_POSS, ADC_NCHS3_NS14_POSE)
# define  ADC_NCHS3_NS14      ADC_NCHS3_NS14_MSK

# define  ADC_NCHS3_NS13_POSS 18U
# define  ADC_NCHS3_NS13_POSE 22U
# define  ADC_NCHS3_NS13_MSK  BITS(ADC_NCHS3_NS13_POSS, ADC_NCHS3_NS13_POSE)
# define  ADC_NCHS3_NS13      ADC_NCHS3_NS13_MSK

# define  ADC_NCHS3_NS12_POSS 12U
# define  ADC_NCHS3_NS12_POSE 16U
# define  ADC_NCHS3_NS12_MSK  BITS(ADC_NCHS3_NS12_POSS, ADC_NCHS3_NS12_POSE)
# define  ADC_NCHS3_NS12      ADC_NCHS3_NS12_MSK

# define  ADC_NCHS3_NS11_POSS 6U
# define  ADC_NCHS3_NS11_POSE 10U
# define  ADC_NCHS3_NS11_MSK  BITS(ADC_NCHS3_NS11_POSS, ADC_NCHS3_NS11_POSE)
# define  ADC_NCHS3_NS11      ADC_NCHS3_NS11_MSK

# define  ADC_NCHS3_NS10_POSS 0U
# define  ADC_NCHS3_NS10_POSE 4U
# define  ADC_NCHS3_NS10_MSK  BITS(ADC_NCHS3_NS10_POSS, ADC_NCHS3_NS10_POSE)
# define  ADC_NCHS3_NS10      ADC_NCHS3_NS10_MSK

/****************** Bit definition for ADC_NCHS4 register ************************/

# define  ADC_NCHS4_NS16_POSS 6U
# define  ADC_NCHS4_NS16_POSE 10U
# define  ADC_NCHS4_NS16_MSK  BITS(ADC_NCHS4_NS16_POSS, ADC_NCHS4_NS16_POSE)
# define  ADC_NCHS4_NS16      ADC_NCHS4_NS16_MSK

# define  ADC_NCHS4_NS15_POSS 0U
# define  ADC_NCHS4_NS15_POSE 4U
# define  ADC_NCHS4_NS15_MSK  BITS(ADC_NCHS4_NS15_POSS, ADC_NCHS4_NS15_POSE)
# define  ADC_NCHS4_NS15      ADC_NCHS4_NS15_MSK

/****************** Bit definition for ADC_NCHDR register ************************/

# define  ADC_NCHDR_VAL_POSS 0U
# define  ADC_NCHDR_VAL_POSE 15U
# define  ADC_NCHDR_VAL_MSK  BITS(ADC_NCHDR_VAL_POSS, ADC_NCHDR_VAL_POSE)
# define  ADC_NCHDR_VAL      ADC_NCHDR_VAL_MSK

/****************** Bit definition for ADC_ICHS register ************************/

# define  ADC_ICHS_IS4_POSS 26U
# define  ADC_ICHS_IS4_POSE 30U
# define  ADC_ICHS_IS4_MSK  BITS(ADC_ICHS_IS4_POSS, ADC_ICHS_IS4_POSE)
# define  ADC_ICHS_IS4      ADC_ICHS_IS4_MSK

# define  ADC_ICHS_IS3_POSS 20U
# define  ADC_ICHS_IS3_POSE 24U
# define  ADC_ICHS_IS3_MSK  BITS(ADC_ICHS_IS3_POSS, ADC_ICHS_IS3_POSE)
# define  ADC_ICHS_IS3      ADC_ICHS_IS3_MSK

# define  ADC_ICHS_IS2_POSS 14U
# define  ADC_ICHS_IS2_POSE 18U
# define  ADC_ICHS_IS2_MSK  BITS(ADC_ICHS_IS2_POSS, ADC_ICHS_IS2_POSE)
# define  ADC_ICHS_IS2      ADC_ICHS_IS2_MSK

# define  ADC_ICHS_IS1_POSS 8U
# define  ADC_ICHS_IS1_POSE 12U
# define  ADC_ICHS_IS1_MSK  BITS(ADC_ICHS_IS1_POSS, ADC_ICHS_IS1_POSE)
# define  ADC_ICHS_IS1      ADC_ICHS_IS1_MSK

# define  ADC_ICHS_IETS_POSS 6U
# define  ADC_ICHS_IETS_POSE 7U
# define  ADC_ICHS_IETS_MSK  BITS(ADC_ICHS_IETS_POSS, ADC_ICHS_IETS_POSE)
# define  ADC_ICHS_IETS      ADC_ICHS_IETS_MSK

# define  ADC_ICHS_IEXTSEL_POSS 2U
# define  ADC_ICHS_IEXTSEL_POSE 5U
# define  ADC_ICHS_IEXTSEL_MSK  BITS(ADC_ICHS_IEXTSEL_POSS, ADC_ICHS_IEXTSEL_POSE)
# define  ADC_ICHS_IEXTSEL      ADC_ICHS_IEXTSEL_MSK

# define  ADC_ICHS_ISL_POSS 0U
# define  ADC_ICHS_ISL_POSE 1U
# define  ADC_ICHS_ISL_MSK  BITS(ADC_ICHS_ISL_POSS, ADC_ICHS_ISL_POSE)
# define  ADC_ICHS_ISL      ADC_ICHS_ISL_MSK

/****************** Bit definition for ADC_OFF1 register ************************/

# define  ADC_OFF1_OFFEN_POS 31U
# define  ADC_OFF1_OFFEN_MSK BIT(ADC_OFF1_OFFEN_POS)
# define  ADC_OFF1_OFFEN     ADC_OFF1_OFFEN_MSK

# define  ADC_OFF1_OFFCH_POSS 26U
# define  ADC_OFF1_OFFCH_POSE 30U
# define  ADC_OFF1_OFFCH_MSK  BITS(ADC_OFF1_OFFCH_POSS, ADC_OFF1_OFFCH_POSE)
# define  ADC_OFF1_OFFCH      ADC_OFF1_OFFCH_MSK

# define  ADC_OFF1_SATEN_POS 25U
# define  ADC_OFF1_SATEN_MSK BIT(ADC_OFF1_SATEN_POS)
# define  ADC_OFF1_SATEN     ADC_OFF1_SATEN_MSK

# define  ADC_OFF1_OFFPEN_POS 24U
# define  ADC_OFF1_OFFPEN_MSK BIT(ADC_OFF1_OFFPEN_POS)
# define  ADC_OFF1_OFFPEN     ADC_OFF1_OFFPEN_MSK

# define  ADC_OFF1_OFF_POSS 0U
# define  ADC_OFF1_OFF_POSE 11U
# define  ADC_OFF1_OFF_MSK  BITS(ADC_OFF1_OFF_POSS, ADC_OFF1_OFF_POSE)
# define  ADC_OFF1_OFF      ADC_OFF1_OFF_MSK

/****************** Bit definition for ADC_OFF2 register ************************/

# define  ADC_OFF2_OFFEN_POS 31U
# define  ADC_OFF2_OFFEN_MSK BIT(ADC_OFF2_OFFEN_POS)
# define  ADC_OFF2_OFFEN     ADC_OFF2_OFFEN_MSK

# define  ADC_OFF2_OFFCH_POSS 26U
# define  ADC_OFF2_OFFCH_POSE 30U
# define  ADC_OFF2_OFFCH_MSK  BITS(ADC_OFF2_OFFCH_POSS, ADC_OFF2_OFFCH_POSE)
# define  ADC_OFF2_OFFCH      ADC_OFF2_OFFCH_MSK

# define  ADC_OFF2_SATEN_POS 25U
# define  ADC_OFF2_SATEN_MSK BIT(ADC_OFF2_SATEN_POS)
# define  ADC_OFF2_SATEN     ADC_OFF2_SATEN_MSK

# define  ADC_OFF2_OFFPEN_POS 24U
# define  ADC_OFF2_OFFPEN_MSK BIT(ADC_OFF2_OFFPEN_POS)
# define  ADC_OFF2_OFFPEN     ADC_OFF2_OFFPEN_MSK

# define  ADC_OFF2_OFF_POSS 0U
# define  ADC_OFF2_OFF_POSE 11U
# define  ADC_OFF2_OFF_MSK  BITS(ADC_OFF2_OFF_POSS, ADC_OFF2_OFF_POSE)
# define  ADC_OFF2_OFF      ADC_OFF2_OFF_MSK

/****************** Bit definition for ADC_OFF3 register ************************/

# define  ADC_OFF3_OFFEN_POS 31U
# define  ADC_OFF3_OFFEN_MSK BIT(ADC_OFF3_OFFEN_POS)
# define  ADC_OFF3_OFFEN     ADC_OFF3_OFFEN_MSK

# define  ADC_OFF3_OFFCH_POSS 26U
# define  ADC_OFF3_OFFCH_POSE 30U
# define  ADC_OFF3_OFFCH_MSK  BITS(ADC_OFF3_OFFCH_POSS, ADC_OFF3_OFFCH_POSE)
# define  ADC_OFF3_OFFCH      ADC_OFF3_OFFCH_MSK

# define  ADC_OFF3_SATEN_POS 25U
# define  ADC_OFF3_SATEN_MSK BIT(ADC_OFF3_SATEN_POS)
# define  ADC_OFF3_SATEN     ADC_OFF3_SATEN_MSK

# define  ADC_OFF3_OFFPEN_POS 24U
# define  ADC_OFF3_OFFPEN_MSK BIT(ADC_OFF3_OFFPEN_POS)
# define  ADC_OFF3_OFFPEN     ADC_OFF3_OFFPEN_MSK

# define  ADC_OFF3_OFF_POSS 0U
# define  ADC_OFF3_OFF_POSE 11U
# define  ADC_OFF3_OFF_MSK  BITS(ADC_OFF3_OFF_POSS, ADC_OFF3_OFF_POSE)
# define  ADC_OFF3_OFF      ADC_OFF3_OFF_MSK

/****************** Bit definition for ADC_OFF4 register ************************/

# define  ADC_OFF4_OFFEN_POS 31U
# define  ADC_OFF4_OFFEN_MSK BIT(ADC_OFF4_OFFEN_POS)
# define  ADC_OFF4_OFFEN     ADC_OFF4_OFFEN_MSK

# define  ADC_OFF4_OFFCH_POSS 26U
# define  ADC_OFF4_OFFCH_POSE 30U
# define  ADC_OFF4_OFFCH_MSK  BITS(ADC_OFF4_OFFCH_POSS, ADC_OFF4_OFFCH_POSE)
# define  ADC_OFF4_OFFCH      ADC_OFF4_OFFCH_MSK

# define  ADC_OFF4_SATEN_POS 25U
# define  ADC_OFF4_SATEN_MSK BIT(ADC_OFF4_SATEN_POS)
# define  ADC_OFF4_SATEN     ADC_OFF4_SATEN_MSK

# define  ADC_OFF4_OFFPEN_POS 24U
# define  ADC_OFF4_OFFPEN_MSK BIT(ADC_OFF4_OFFPEN_POS)
# define  ADC_OFF4_OFFPEN     ADC_OFF4_OFFPEN_MSK

# define  ADC_OFF4_OFF_POSS 0U
# define  ADC_OFF4_OFF_POSE 11U
# define  ADC_OFF4_OFF_MSK  BITS(ADC_OFF4_OFF_POSS, ADC_OFF4_OFF_POSE)
# define  ADC_OFF4_OFF      ADC_OFF4_OFF_MSK

/****************** Bit definition for ADC_ICHDR1 register ************************/

# define  ADC_ICHDR1_VAL_POSS 0U
# define  ADC_ICHDR1_VAL_POSE 15U
# define  ADC_ICHDR1_VAL_MSK  BITS(ADC_ICHDR1_VAL_POSS, ADC_ICHDR1_VAL_POSE)
# define  ADC_ICHDR1_VAL      ADC_ICHDR1_VAL_MSK

/****************** Bit definition for ADC_ICHDR2 register ************************/

# define  ADC_ICHDR2_VAL_POSS 0U
# define  ADC_ICHDR2_VAL_POSE 15U
# define  ADC_ICHDR2_VAL_MSK  BITS(ADC_ICHDR2_VAL_POSS, ADC_ICHDR2_VAL_POSE)
# define  ADC_ICHDR2_VAL      ADC_ICHDR2_VAL_MSK

/****************** Bit definition for ADC_ICHDR3 register ************************/

# define  ADC_ICHDR3_VAL_POSS 0U
# define  ADC_ICHDR3_VAL_POSE 15U
# define  ADC_ICHDR3_VAL_MSK  BITS(ADC_ICHDR3_VAL_POSS, ADC_ICHDR3_VAL_POSE)
# define  ADC_ICHDR3_VAL      ADC_ICHDR3_VAL_MSK

/****************** Bit definition for ADC_ICHDR4 register ************************/

# define  ADC_ICHDR4_VAL_POSS 0U
# define  ADC_ICHDR4_VAL_POSE 15U
# define  ADC_ICHDR4_VAL_MSK  BITS(ADC_ICHDR4_VAL_POSS, ADC_ICHDR4_VAL_POSE)
# define  ADC_ICHDR4_VAL      ADC_ICHDR4_VAL_MSK

/****************** Bit definition for ADC_CALCR register ************************/

# define  ADC_CALCR_OCOMCOE_POSS 16U
# define  ADC_CALCR_OCOMCOE_POSE 23U
# define  ADC_CALCR_OCOMCOE_MSK  BITS(ADC_CALCR_OCOMCOE_POSS, ADC_CALCR_OCOMCOE_POSE)
# define  ADC_CALCR_OCOMCOE      ADC_CALCR_OCOMCOE_MSK

# define  ADC_CALCR_GCOMCOE_POSS 0U
# define  ADC_CALCR_GCOMCOE_POSE 11U
# define  ADC_CALCR_GCOMCOE_MSK BITS(ADC_CALCR_GCOMCOE_POSS, ADC_CALCR_GCOMCOE_POSE)
# define  ADC_CALCR_GCOMCOE     ADC_CALCR_GCOMCOE_MSK

/****************** Bit definition for ADC_CCR register ************************/

# define  ADC_CCR_REFINTS_POSS 24U
# define  ADC_CCR_REFINTS_POSE 26U
# define  ADC_CCR_REFINTS_MSK  BITS(ADC_CCR_REFINTS_POSS, ADC_CCR_REFINTS_POSE)
# define  ADC_CCR_REFINTS      ADC_CCR_REFINTS_MSK

/****************** Bit definition for ADC_SR register ************************/

# define  ADC_SR_NDRE_POS 2U
# define  ADC_SR_NDRE_MSK BIT(ADC_SR_NDRE_POS)
# define  ADC_SR_NDRE     ADC_SR_NDRE_MSK

typedef struct
{
    __O  uint32_t IER;                      // 0x000
    __O  uint32_t IDR;                      // 0x004
    __I  uint32_t IVS;                      // 0x008
    __I  uint32_t RIF;                      // 0x00c
    __I  uint32_t IFM;                      // 0x010
    __O  uint32_t ICR;                      // 0x014
    __IO uint32_t CON;                      // 0x018
    __IO uint32_t CFG;                      // 0x01c
    __IO uint32_t SMPT1;                    // 0x020
    __IO uint32_t SMPT2;                    // 0x024
    __IO uint32_t SMPT3;                    // 0x028
    __IO uint32_t SMPT4;                    // 0x02c
    __IO uint32_t SMPT5;                    // 0x030
    __IO uint32_t RESERVED0[2];             // 0x034-0x038
    __IO uint32_t WDTH;                     // 0x03c
    __IO uint32_t NCHS1;                    // 0x040
    __IO uint32_t NCHS2;                    // 0x044
    __IO uint32_t NCHS3;                    // 0x048
    __IO uint32_t NCHS4;                    // 0x04c
    __I  uint32_t NCHDR;                    // 0x050
    __IO uint32_t ICHS;                     // 0x054
    __IO uint32_t OFF1;                     // 0x058
    __IO uint32_t OFF2;                     // 0x05c
    __IO uint32_t OFF3;                     // 0x060
    __IO uint32_t OFF4;                     // 0x064
    __I  uint32_t ICHDR1;                   // 0x068
    __I  uint32_t ICHDR2;                   // 0x06c
    __I  uint32_t ICHDR3;                   // 0x070
    __I  uint32_t ICHDR4;                   // 0x074
    __IO uint32_t CALCR;                    // 0x078
    __IO uint32_t CCR;                      // 0x07c
    __I  uint32_t SR;                       // 0x080
} ADC_TypeDef;


#endif
