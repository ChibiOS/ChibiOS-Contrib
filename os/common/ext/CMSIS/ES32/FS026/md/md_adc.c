/**********************************************************************************
 *
 * @file    md_adc.c
 * @brief   md_adc C file
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

/* Includes -------------------------------------------------------------------*/
#include "md_adc.h"
#include "md_syscfg.h"
#include <stdio.h>
#include "md_fc.h"
#define ADC_DMA

/** @addtogroup Micro_Driver
  * @{
  */


/** @defgroup ADC ADC
  * @brief ADC micro driver
  * @{
  */

/* Private types --------------------------------------------------------------*/
/* Private variables ----------------------------------------------------------*/
/* Private constants ----------------------------------------------------------*/
/* Private macros -------------------------------------------------------------*/
/* Private function prototypes ------------------------------------------------*/

void (*md_adc_nchs_sample[])(ADC_TypeDef *, uint32_t) =
{
    md_adc_set_normal_sequence_selection_1th,
    md_adc_set_normal_sequence_selection_2th,
    md_adc_set_normal_sequence_selection_3th,
    md_adc_set_normal_sequence_selection_4th,
    md_adc_set_normal_sequence_selection_5th,
    md_adc_set_normal_sequence_selection_6th,
    md_adc_set_normal_sequence_selection_7th,
    md_adc_set_normal_sequence_selection_8th,
    md_adc_set_normal_sequence_selection_9th,
    md_adc_set_normal_sequence_selection_10th,
    md_adc_set_normal_sequence_selection_11th,
    md_adc_set_normal_sequence_selection_12th,
    md_adc_set_normal_sequence_selection_13th,
    md_adc_set_normal_sequence_selection_14th,
    md_adc_set_normal_sequence_selection_15th,
    md_adc_set_normal_sequence_selection_16th
};

void (*md_adc_ichs_sample[])(ADC_TypeDef *, uint32_t) =
{
    md_adc_set_inj_sequence_selection_1th,
    md_adc_set_inj_sequence_selection_2th,
    md_adc_set_inj_sequence_selection_3th,
    md_adc_set_inj_sequence_selection_4th,
};

/* Public functions -----------------------------------------------------------*/
/** @defgroup ADC_PUB_FUNC ADC Public Functions
  * @brief ADC Public Functions
  * @{
  */

/**
  * @brief  ADC Initialization Function.
  * @param  ADC Instance.
  * @param  ADC_InitStruct.
  * @retval None
  */
void md_adc_init(ADC_TypeDef *ADCx, md_adc_initial *ADC_InitStruct)
{
    while (md_adc_is_enabled_calibration(ADCx));

    md_adc_set_adc_clock_predivider(ADC, ADC_InitStruct->CKDIV);

    md_adc_enable_adcpower(ADCx);

    while (!md_adc_is_active_flag_adc_ready(ADCx));

    while ((md_adc_get_start_inj(ADCx) == MD_ADC_CON_ISTART_START_INJECTED));

    while ((md_adc_get_start_normal(ADCx) == MD_ADC_CON_NSTART_START_REGULAR));

    md_adc_set_data_alignment(ADCx, ADC_InitStruct->ALIGN);
    md_adc_set_resolution_selection(ADCx, ADC_InitStruct->RSEL);
    md_adc_set_convsersion_mode(ADCx, ADC_InitStruct->Regular_CM);

#ifdef ADC_DMA
    md_adc_enable_dma_access(ADCx);
#else
    md_adc_disable_dma_access(ADCx);
#endif

}

/**
  * @brief  ADC conversion Function.
  * @param  ADC Instance.
  * @param  ADC_InitStruct.
  * @param  sample_seq_channel
  * @retval None
  */
void md_adc_sequence_conversion(ADC_TypeDef *ADCx, md_adc_initial *ADC_InitStruct, uint32_t *sample_seq_channel)
{
    uint8_t i;

    if (ADC_InitStruct->Regular_Injected == MD_ADC_MODE_NCHS)
    {
        md_adc_set_normal_sequence_length(ADCx, ADC_InitStruct->Cnt);

        for (i = 0; i <= ADC_InitStruct->Cnt; i++)
            md_adc_nchs_sample[i](ADCx, sample_seq_channel[i]);

//    md_adc_set_start_normal(ADCx, MD_ADC_CON_NSTART_START_REGULAR);
    }
    else
    {
        md_adc_set_inj_sequence_length(ADCx, ADC_InitStruct->Cnt);

        for (i = 0; i <= ADC_InitStruct->Cnt; i++)
            md_adc_ichs_sample[i](ADCx, sample_seq_channel[i]);

//    md_adc_set_start_inj(ADCx, MD_ADC_CON_ISTART_START_INJECTED);
    }

}

/**
  * @brief  ADC software calibration
  * @param  ADC Instance.
  * @retval  An ErrorStatus enumeration value:
  *          - SUCCESS: calibration success
  *          - ERROR: calibration fail
  */
ErrorStatus md_adc_software_calibration(ADC_TypeDef *ADCx, md_adc_initial *ADC_InitStruct)
{
    //ADC input APB clock 12MHz
    uint8_t clkdiv;
    uint16_t adc_data_1 = 0;
    uint16_t adc_data_15 = 0;

    int16_t adc_offset = 0;
    uint16_t adc_gain = 0;

    float temp_adc_offset = 0.0f;

    md_syscfg_set_vref_source(SYSCFG, MD_SYSCFG_PWR_VDDA); // VRES choose VDDA
    md_syscfg_enable_vref(SYSCFG);
    //ADC Setting
    md_adc_set_convsersion_mode(ADC, MD_ADC_CFG_CM_SINGLE);                 // 1:Continuous
    md_adc_set_resolution_selection(ADC, MD_ADC_CFG_RSEL_12BIT);            // 12-bit resolution
    md_adc_set_normal_sequence_selection_1th(ADC, MD_ADC_NCHS1_NS1_CH18);   // channel number(16:Temperature)
    md_adc_set_adc_clock_predivider(ADC, ADC_InitStruct->CKDIV);

    if (ADC_InitStruct->CKDIV == MD_ADC_SMPT1_CKDIV_DIV1)
        clkdiv = 1;
    else if (ADC_InitStruct->CKDIV == MD_ADC_SMPT1_CKDIV_DIV2)
        clkdiv = 2;
    else if (ADC_InitStruct->CKDIV == MD_ADC_SMPT1_CKDIV_DIV4)
        clkdiv = 4;
    else if (ADC_InitStruct->CKDIV == MD_ADC_SMPT1_CKDIV_DIV6)
        clkdiv = 6;
    else if (ADC_InitStruct->CKDIV == MD_ADC_SMPT1_CKDIV_DIV8)
        clkdiv = 8;

    if ((SystemFrequency_APBClk / clkdiv) <= 12000000)
        md_adc_set_sampletime_channel_18(ADCx, 0x40); //Sample Time Cycle
    else
        md_adc_set_sampletime_channel_18(ADCx, 0x80); //Sample Time Cycle

    //CLEAR CALCR
    md_adc_set_gain_factor(ADCx, 1024);
    md_adc_set_offset_factor(ADCx, 0);

    //ADC ENABLE
    md_adc_enable_adcpower(ADCx);

    while (!md_adc_is_active_flag_adc_ready(ADCx));

    // --------------------------------------------------------
    // 1/16 Sample
    md_adc_set_vref_level(ADCx, MD_ADC_CCR_REFINTS_1DIV16);
    md_adc_set_start_normal(ADCx, MD_ADC_CON_NSTART_START_REGULAR);

    while (md_adc_is_active_flag_normal_status(ADCx));

    adc_data_1 = md_adc_get_normal_data(ADCx);

    // --------------------------------------------------------
    // 15/16 Sample
    md_adc_set_vref_level(ADCx, MD_ADC_CCR_REFINTS_15DIV16);
    md_adc_set_start_normal(ADCx, MD_ADC_CON_NSTART_START_REGULAR);

    while (md_adc_is_active_flag_normal_status(ADCx));

    adc_data_15 = md_adc_get_normal_data(ADCx);

    // --------------------------------------------------------



    temp_adc_offset = (float)((15 * adc_data_1) - adc_data_15) / 14;

    if (temp_adc_offset > 0)
    {
        adc_offset = (int16_t)(temp_adc_offset + 0.5);
    }
    else
    {
        adc_offset = (int16_t)(temp_adc_offset - 0.5);
    }



    adc_gain   = (uint16_t)((3584 * 1024) / (float)(adc_data_15 - adc_data_1) + 0.5);




//  printf("adc_data_1:%d\r\n",adc_data_1);
//  printf("adc_data_15:%d\r\n",adc_data_15);
//  printf("adc_offset:%d\r\n",adc_offset);
//  printf("adc_gain:%d\r\n",adc_gain);

    md_adc_set_gain_factor(ADCx, adc_gain);
    md_adc_set_offset_factor(ADCx, adc_offset);

    // --------------------------------------------------------
    // Reset the used register to default
    md_adc_set_convsersion_mode(ADCx, 0);
    md_adc_set_resolution_selection(ADCx, MD_ADC_CFG_RSEL_6BIT);
    md_adc_set_normal_sequence_selection_1th(ADCx, MD_ADC_NCHS1_NS1_CH0);
    md_adc_set_adc_clock_predivider(ADCx, MD_ADC_SMPT1_CKDIV_DIV1);
    md_adc_set_sampletime_channel_18(ADCx, 0);
    md_adc_set_icr(ADCx, 0xFFFE);

    return SUCCESS;
}

ErrorStatus md_adc_optionbyte_calibration(ADC_TypeDef *ADCx, md_adc_initial *ADC_InitStruct)
{
    int8_t              adc_offset = 0;
    uint32_t            adc_gain = 1024;
    uint32_t            cal_value = 0;
    md_fc_read_info(ADC_CALIBRATION_ADDR, &cal_value);

    adc_gain = (cal_value & 0xFFF);
    adc_offset = (cal_value >> 16) & 0xFF;

    //ADC ENABLE
    md_adc_enable_adcpower(ADCx);
    md_adc_set_gain_factor(ADCx, adc_gain);
    md_adc_set_offset_factor(ADCx, adc_offset);
    return SUCCESS;
}

/**
  * @brief  Get ADC calibration Coefficient
  * @param  OCOMCOE.
  * @param  GCOMCOE.
  * @retval None
  */
void md_adc_get_calibration(ADC_TypeDef *ADCx, uint8_t *OCOMCOE, uint16_t *GCOMCOE)
{
    *OCOMCOE = (uint8_t)md_adc_get_offset_factor(ADCx);
    *GCOMCOE = (uint16_t)md_adc_get_gain_factor(ADCx);
}

/**
  * @brief  Set ADC calibration Mode
  * @param  ADC Instance.
  * @param  ADC_InitStruct.
  * @param
  * @retval None
  */
ErrorStatus md_adc_calibration(ADC_TypeDef *ADCx, md_adc_initial *ADC_InitStruct)
{
    uint32_t            cal_value = 0;
    md_fc_read_info(ADC_CALIBRATION_ADDR, &cal_value);


    if (cal_value == 0xFFFFFFFF)
    {
        return md_adc_software_calibration(ADCx, ADC_InitStruct);
    }
    else
    {
        return md_adc_optionbyte_calibration(ADCx, ADC_InitStruct);
    }

}

/**
  * @brief  Get the ADC data
  * @param  ADC Instance.
  * @retval adc data
  */
uint16_t md_adc_get_data(ADC_TypeDef *ADCx)
{
    uint16_t adc_data;

    adc_data = md_adc_get_normal_data(ADCx);

    return  adc_data;
}


/**
  * @} ADC_PUB_FUNC ADC Public Functions
  */

/**
  * @} ADC
  */

/**
  * @} Micro_Driver
  */

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
