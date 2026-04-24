/**********************************************************************************
 *
 * @file    md_adc.c
 * @brief   ADC module driver.
 *
 * @date    26 Dec. 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          26 Dec. 2022    Lisq            the first version
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

/* Includes ------------------------------------------------------------------ */
#include "md_adc.h"
#include "md_cmu.h"

/* Private Macros ------------------------------------------------------------ */
/* Private Variables --------------------------------------------------------- */
/* Public Variables ---------------------------------------------------------- */
/* Private Constants --------------------------------------------------------- */
/* Private function prototypes ----------------------------------------------- */

/* Private Function ---------------------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */

/** @addtogroup MD_ADC
  * @{
  */

/** @addtogroup MD_ADC_Public_Functions
  * @{
  */
/** @addtogroup MD_ADC_Public_Functions_Group1
  * @{
  */
/**
  * @brief  Initializes the ADC peripheral according to
  *         parameters specified in structure ADC_TypeDef.
  * @param  ADCx: adc peripheral
  * @param  init: Pointer to a md_adc_init_t structure that contains
  *         the configuration information for the specified ADC module.
  * @retval md_status_t, see @ref md_status_t.
  */
md_status_t md_adc_init(ADC_TypeDef *ADCx, md_adc_init_t *init)
{
    MD_ADC_DISABLE(ADCx);
    MODIFY_REG(ADCx->CON1, ADC_CON1_ALIGN_MSK, init->align << ADC_CON1_ALIGN_POS);
    MODIFY_REG(ADCx->CON0, ADC_CON0_RSEL_MSK, init->data_bit << ADC_CON0_RSEL_POSS);

    /* Enable discontinuous mode only if continuous mode is disable */
    if (init->disc == MD_ADC_NCH_DISC_EN)
    {
        init->scan = ENABLE;
        init->cont = DISABLE;
        SET_BIT(ADCx->CON0, ADC_CON0_NCHDCEN_MSK);
        MODIFY_REG(ADCx->CON0, ADC_CON0_ETRGN_MSK, init->disc_nr << ADC_CON0_ETRGN_POSS);
    }
    else if (init->disc == MD_ADC_ICH_DISC_EN)
    {
        init->scan = ENABLE;
        init->cont = DISABLE;
        SET_BIT(ADCx->CON0, ADC_CON0_ICHDCEN_MSK);
        MODIFY_REG(ADCx->CON0, ADC_CON0_ETRGN_MSK, init->disc_nr << ADC_CON0_ETRGN_POSS);
    }
    else
    {
        CLEAR_BIT(ADCx->CON0, ADC_CON0_NCHDCEN_MSK);
        CLEAR_BIT(ADCx->CON0, ADC_CON0_ICHDCEN_MSK);
    }

    if ((init->scan == ENABLE) || (init->disc == MD_ADC_NCH_DISC_EN))
        MODIFY_REG(ADCx->CHSL, ADC_CHSL_NSL_MSK, init->nch_nr << ADC_CHSL_NSL_POSS);

    MODIFY_REG(ADCx->CON1, ADC_CON1_CM_MSK, init->cont << ADC_CON1_CM_POS);
    MODIFY_REG(ADCx->CON0, ADC_CON0_SCANEN_MSK, init->scan << ADC_CON0_SCANEN_POS);

    /* if the ADC clock less than 1MHz,PWRMOD should be disable*/
    MODIFY_REG(ADCx->CCR, ADC_CCR_PWRMODSEL_MSK, DISABLE << ADC_CCR_PWRMODSEL_POS);
    MODIFY_REG(ADCx->CCR, ADC_CCR_VREFEN_MSK, ENABLE << ADC_CCR_VREFEN_POS);
    MODIFY_REG(ADCx->CCR, ADC_CCR_IREFEN_MSK, ENABLE << ADC_CCR_IREFEN_POS);
    MODIFY_REG(ADCx->CCR, ADC_CCR_POSDIV_MSK, init->div << ADC_CCR_POSDIV_POSS);
    MODIFY_REG(ADCx->CCR, ADC_CCR_VRNSEL_MSK, init->n_ref << ADC_CCR_VRNSEL_POS);
    MODIFY_REG(ADCx->CCR, ADC_CCR_VRPSEL_MSK, init->p_ref << ADC_CCR_VRPSEL_POS);
    MODIFY_REG(ADCx->CON1, ADC_CON1_NCHESEL_MSK, init->nche_sel << ADC_CON1_NCHESEL_POS);

    MD_ADC_ENABLE(ADCx);

    return MD_OK;
}

/**
  * @brief  Set each @ref md_adc_init_t field to default value.
  * @param  init: Pointer to a @ref md_adc_init_t structure
  *                 whose fields will be set to default values.
  * @retval None
  */
void md_adc_struct_init(md_adc_init_t *init)
{
    init->align    = MD_ADC_DATAALIGN_RIGHT;
    init->scan     = DISABLE;
    init->cont     = DISABLE;
    init->nch_nr   = MD_ADC_NCH_NR_1;
    init->disc     = MD_ADC_ALL_DISABLE;
    init->disc_nr  = MD_ADC_DISC_NR_1;
    init->data_bit = MD_ADC_CONV_BIT_12;
    init->div      = MD_ADC_POSDIV_128;
    init->nche_sel = MD_ADC_NCHESEL_MODE_ALL;
    init->n_ref    = MD_ADC_NEG_REF_VSS;
    init->p_ref    = MD_ADC_POS_REF_VDD;

    return;
}

/**
  * @brief  Initializes the ADC peripheral and normal group according to
  *         parameters specified in structure ADC_TypeDef.
  * @param  ADCx: adc peripheral
  * @param  config: Pointer to a md_adc_nch_conf_t structure that contains
  *         the configuration information for the specified ADC module.
  * @retval md_status_t, see @ref md_status_t.
  */
md_status_t md_adc_normal_channel_config(ADC_TypeDef *ADCx, md_adc_nch_conf_t *config)
{
    if (config->idx <= MD_ADC_NCH_IDX_4)
    {
        ADCx->NCHS1 &= ~(0x1f << (uint32_t)((config->idx - 1) << 3));
        ADCx->NCHS1 |= (config->ch << (uint32_t)((config->idx - 1) << 3));
    }
    else if (config->idx <= MD_ADC_NCH_IDX_8)
    {
        ADCx->NCHS2 &= ~(0x1f << (uint32_t)((config->idx - 5) << 3));
        ADCx->NCHS2 |= (config->ch << (uint32_t)((config->idx - 5) << 3));
    }
    else if (config->idx <= MD_ADC_NCH_IDX_12)
    {
        ADCx->NCHS3 &= ~(0x1f << (uint32_t)((config->idx - 9) << 3));
        ADCx->NCHS3 |= (config->ch << (uint32_t)((config->idx - 9) << 3));
    }
    else
    {
        ADCx->NCHS4 &= ~(0x1f << (uint32_t)((config->idx - 13) << 3));
        ADCx->NCHS4 |= (config->ch << (uint32_t)((config->idx - 13) << 3));
    }

    if (config->ch < 8)
    {
        ADCx->SMPT1 &= ~(0x0f << (uint32_t)(config->ch << 2));
        ADCx->SMPT1 |= config->samp << (uint32_t)(config->ch << 2);
    }
    else if (config->ch < 16)
    {
        ADCx->SMPT2 &= ~(0x0f << (uint32_t)((config->ch - 8) << 2));
        ADCx->SMPT2 |= config->samp << (uint32_t)((config->ch - 8) << 2);
    }
    else
    {
        ADCx->SMPT3 &= ~(0x0f << (uint32_t)((config->ch - 16) << 2));
        ADCx->SMPT3 |= config->samp << (uint32_t)((config->ch - 16) << 2);
    }

    return MD_OK;
}

/**
  * @brief  Set each @ref md_adc_nch_conf_t field to default value.
  * @param  config: Pointer to a @ref md_adc_nch_conf_t structure
  *                 whose fields will be set to default values.
  * @retval None
  */
void md_adc_normal_struct_init(md_adc_nch_conf_t *config)
{
    config->ch   = MD_ADC_CHANNEL_0;
    config->idx  = MD_ADC_NCH_IDX_1;
    config->samp = MD_ADC_SAMPLETIME_4;

    return;
}

/**
  * @brief  Initializes the ADC insert group according to
  *         parameters specified in structure ADC_TypeDef.
  * @param  ADCx: adc peripheral
  * @param  config: Pointer to a md_adc_ich_conf_t structure that contains
  *         the configuration information for the specified ADC module.
  * @retval md_status_t, see @ref md_status_t.
  */
md_status_t md_adc_insert_channel_config(ADC_TypeDef *ADCx, md_adc_ich_conf_t *config)
{
    MODIFY_REG(ADCx->CHSL, ADC_CHSL_ISL_MSK, config->nr << ADC_CHSL_ISL_POSS);
    ADCx->ICHS &= ~(0x1f << (uint32_t)((config->idx - 1) << 3));
    ADCx->ICHS |= config->ch << (uint32_t)((config->idx - 1) << 3);

    if (config->auto_m == ENABLE)
        SET_BIT(ADCx->CON0, ADC_CON0_IAUTO_MSK);
    else
        CLEAR_BIT(ADCx->CON0, ADC_CON0_IAUTO_MSK);

    if (config->ch < 8)
    {
        ADCx->SMPT1 &=  ~(0x0f << (uint32_t)(config->ch << 2));
        ADCx->SMPT1 |= config->samp << (uint32_t)(config->ch << 2);
    }
    else if (config->ch < 16)
    {
        ADCx->SMPT2 &=  ~(0x0f << (uint32_t)((config->ch - 8) << 2));
        ADCx->SMPT2 |= config->samp << (uint32_t)((config->ch - 8) << 2);
    }
    else
    {
        ADCx->SMPT3 &=  ~(0x0f << (uint32_t)((config->ch - 16) << 2));
        ADCx->SMPT3 |= config->samp << (uint32_t)((config->ch - 16) << 2);
    }

    switch (config->idx)
    {
        case MD_ADC_ICH_IDX_1:
            ADCx->ICHOFF1 = config->offset;
            break;

        case MD_ADC_ICH_IDX_2:
            ADCx->ICHOFF2 = config->offset;
            break;

        case MD_ADC_ICH_IDX_3:
            ADCx->ICHOFF3 = config->offset;
            break;

        case MD_ADC_ICH_IDX_4:
            ADCx->ICHOFF4 = config->offset;
            break;

        default:
            break;
    }

    return MD_OK;
}

/**
  * @brief  Set each @ref md_adc_ich_conf_t field to default value.
  * @param  config: Pointer to a @ref md_adc_ich_conf_t structure
  *                   whose fields will be set to default values.
  * @retval None
  */
void md_adc_insert_struct_init(md_adc_ich_conf_t *config)
{
    config->ch     = MD_ADC_CHANNEL_2;
    config->idx    = MD_ADC_ICH_IDX_1;
    config->samp   = MD_ADC_SAMPLETIME_4;
    config->offset = 0;
    config->nr     = MD_ADC_ICH_NR_1;
    config->auto_m = DISABLE;

    return;
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
 * @}
 */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
