/**********************************************************************************
 *
 * @file    md_timer.c
 * @brief   TIMER module driver.
 *
 * @date    08 July 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          08 July 2022    Lisq            the first version
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
#include "md_timer.h"

/* Private Macros ------------------------------------------------------------ */
/* Private Variables --------------------------------------------------------- */
/* Public Variables ---------------------------------------------------------- */
/* Private Constants --------------------------------------------------------- */

/* Private function prototypes ----------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */

/** @addtogroup MD_TIMER
  * @{
  */

/** @addtogroup MD_TIMER_Private_Functions
  * @{
  */
static md_status_t oc1_config(TIMER_TypeDef *TIMERx, md_timer_oc_init_t *init);
static md_status_t oc2_config(TIMER_TypeDef *TIMERx, md_timer_oc_init_t *init);
static md_status_t oc3_config(TIMER_TypeDef *TIMERx, md_timer_oc_init_t *init);
static md_status_t oc4_config(TIMER_TypeDef *TIMERx, md_timer_oc_init_t *init);
static md_status_t ic1_config(TIMER_TypeDef *TIMERx, md_timer_ic_init_t *init);
static md_status_t ic2_config(TIMER_TypeDef *TIMERx, md_timer_ic_init_t *init);
static md_status_t ic3_config(TIMER_TypeDef *TIMERx, md_timer_ic_init_t *init);
static md_status_t ic4_config(TIMER_TypeDef *TIMERx, md_timer_ic_init_t *init);
/**
 * @}
 */

/* Private Function ---------------------------------------------------------- */

/** @addtogroup MD_TIMER_Public_Functions
  * @{
  */
/** @addtogroup MD_TIMER_Public_Functions_Group1
  * @{
  */
/**
  * @brief  Timer Base configuration
  * @param  TIMERx: TIMER periherl
  * @param  init: TIMER Base configuration structure
  * @retval None
  */
void md_timer_base_set_config(TIMER_TypeDef *TIMERx, md_timer_base_init_t *init)
{
    if (init->mode == MD_TIMER_CNT_MODE_UP || init->mode == MD_TIMER_CNT_MODE_DOWN)
    {
        CLEAR_BIT(TIMERx->CON1, TIMER_CON1_CMSEL_MSK);
        MODIFY_REG(TIMERx->CON1, TIMER_CON1_DIRSEL_MSK, init->mode << TIMER_CON1_DIRSEL_POS);
    }
    else
    {
        MODIFY_REG(TIMERx->CON1, TIMER_CON1_CMSEL_MSK, (init->mode - 1) << TIMER_CON1_CMSEL_POSS);
    }

    if (MD_IS_TIMER_CLOCK_DIVISION_INSTANCE(TIMERx))
        MODIFY_REG(TIMERx->CON1, TIMER_CON1_DFCKSEL_MSK, init->clk_div << TIMER_CON1_DFCKSEL_POSS);

    md_timer_set_auto_reload_value_arrv(TIMERx, init->period);
    md_timer_set_prescaler_value_pscv(TIMERx, init->prescaler);

    if (MD_IS_TIMER_REPETITION_COUNTER_INSTANCE(TIMERx))
        md_timer_set_repetition_counter_value_repv(TIMERx, init->re_cnt);

    /* Generate an update event to reload the pareameters */
    md_timer_enable_update_disue(TIMERx);
    return;
}

/**
  * @brief  Set the fields of the time base unit configuration data structure
  *         to their default values.
  * @param  init pointer to a @ref md_timer_base_init_t structure
  * @retval None
  */
void md_timer_base_struct_init(md_timer_base_init_t *init)
{
    /* Set the default configuration */
    init->prescaler = (uint16_t)0x0000;
    init->mode      = MD_TIMER_CNT_MODE_UP;
    init->period    = 0xFFFFFFFFU;
    init->clk_div   = MD_TIMER_CLOCK_DIV1;
    init->re_cnt    = (uint8_t)0x00;
}

/**
  * @brief  Set the fields of the TIMERx output channel configuration data
  *         structure to their default values.
  * @param  init pointer to a @ref md_timer_oc_init_t structure
  * @retval None
  */
void md_timer_oc_struct_init(md_timer_oc_init_t *init)
{
    /* Set the default configuration */
    init->ocstate      = MD_TIMER_OCSTATE_DISABLE;
    init->ocnstate     = MD_TIMER_OCSTATE_DISABLE;
    init->oc_mode      = MD_TIMER_OC_MODE_TIMERING;
    init->pulse        = 0x00000000;
    init->oc_polarity  = MD_TIMER_OC_POLARITY_HIGH;
    init->ocn_polarity = MD_TIMER_OCN_POLARITY_HIGH;
    init->oc_idle      = MD_TIMER_OC_IDLE_RESET;
    init->ocn_idle     = MD_TIMER_OCN_IDLE_RESET;
}

/**
  * @brief  Configure the TIMERx output channel.
  * @param  TIMERx Timer Instance
  * @param  channel This parameter can be one of @ref md_timer_channel_t
  * @param  init pointer to a @ref md_timer_oc_init_t structure
  * @retval An md_status_t enumeration value:
  *          - MD_OK: TIMERx output channel is initialized
  *          - MD_ERROR: TIMERx output channel is not initialized
  */
md_status_t md_timer_oc_init(TIMER_TypeDef *TIMERx, md_timer_channel_t channel, md_timer_oc_init_t *init)
{
    md_status_t result = MD_ERROR;

    switch (channel)
    {
        case MD_TIMER_CHANNEL_1:
            result = oc1_config(TIMERx, init);
            break;

        case MD_TIMER_CHANNEL_2:
            result = oc2_config(TIMERx, init);
            break;

        case MD_TIMER_CHANNEL_3:
            result = oc3_config(TIMERx, init);
            break;

        case MD_TIMER_CHANNEL_4:
            result = oc4_config(TIMERx, init);
            break;

        default:
            break;
    }

    return result;
}

/**
  * @brief  Set the fields of the TIMERx input channel configuration data
  *         structure to their default values.
  * @param  init pointer to a @ref md_timer_ic_init_t structure
  * @retval None
  */
void md_timer_ic_struct_init(md_timer_ic_init_t *init)
{
    /* Set the default configuration */
    init->polarity = MD_TIMER_IC_POLARITY_RISE;
    init->sel      = MD_TIMER_IC_SEL_DIRECT;
    init->psc      = MD_TIMER_IC_PSC_DIV1;
    init->filter   = 0;
}

/**
  * @brief  Configure the TIMERx input channel.
  * @param  TIMERx Timer Instance
  * @param  Channel This parameter can be one of @ref md_timer_channel_t
  * @param  init pointer to a @ref md_timer_ic_init_t structure
  * @retval An md_status_t enumeration value:
  *          - MD_OK: TIMERx output channel is initialized
  *          - MD_ERROR: TIMERx output channel is not initialized
  */
md_status_t md_timer_ic_init(TIMER_TypeDef *TIMERx, md_timer_channel_t Channel, md_timer_ic_init_t *init)
{
    md_status_t result = MD_ERROR;

    switch (Channel)
    {
        case MD_TIMER_CHANNEL_1:
            result = ic1_config(TIMERx, init);
            break;

        case MD_TIMER_CHANNEL_2:
            result = ic2_config(TIMERx, init);
            break;

        case MD_TIMER_CHANNEL_3:
            result = ic3_config(TIMERx, init);
            break;

        case MD_TIMER_CHANNEL_4:
            result = ic4_config(TIMERx, init);
            break;

        default:
            break;
    }

    return result;
}

/**
  * @brief  Fills each timer_encoder_init_struct field with its default value
  * @param  init pointer to a @ref md_timer_encoder_init_t structure
  * @retval None
  */
void timer_encoder_struct_init(md_timer_encoder_init_t *init)
{
    /* Set the default configuration */
    init->mode         = MD_TIMER_ENC_MODE_TI1;
    init->ic1_polarity = MD_TIMER_IC_POLARITY_RISE;
    init->ic1_sel      = MD_TIMER_IC_SEL_DIRECT;
    init->ic1_psc      = MD_TIMER_IC_PSC_DIV1;
    init->ic1_filter   = 0;
    init->ic2_polarity = MD_TIMER_IC_POLARITY_RISE;
    init->ic2_sel      = MD_TIMER_IC_SEL_DIRECT;
    init->ic2_psc      = MD_TIMER_IC_PSC_DIV1;
    init->ic2_filter   = 0;
}

/**
  * @brief  Configure the encoder interface of the timer instance.
  * @param  TIMERx Timer Instance
  * @param  init pointer to a @ref md_timer_encoder_init_t structure
  * @retval An md_status_t enumeration value:
  *          - MD_OK: TIMERx registers are de-initialized
  *          - MD_ERROR: not applicable
  */
md_status_t timer_encoder_init(TIMER_TypeDef *TIMERx, md_timer_encoder_init_t *init)
{
    uint32_t tmpchmr1 = 0U;
    uint32_t tmpccep = 0U;

    /* Disable the CC1 and CC2: Reset the CC1E and CC2E Bits */
    TIMERx->CCEP &= (uint32_t)~(TIMER_CCEP_CC1EN_MSK | TIMER_CCEP_CC2EN_MSK);

    /* Get the TIMERx CCMR1 register value */
    tmpchmr1 = READ_REG(TIMERx->CHMR1);

    /* Get the TIMERx CCER register value */
    tmpccep = READ_REG(TIMERx->CCEP);

    /* Configure TI1 */
    tmpchmr1 &= (uint32_t)~(TIMER_CHMR1_CC1SSEL_MSK | TIMER_CHMR1_I1FLT_MSK  | TIMER_CHMR1_IC1PRES_MSK);
    tmpchmr1 |= (uint32_t)(init->ic1_sel << 0U);
    tmpchmr1 |= (uint32_t)(init->ic1_filter << 4U);
    tmpchmr1 |= (uint32_t)(init->ic1_psc << 2U);

    /* Configure TI2 */
    tmpchmr1 &= (uint32_t)~(TIMER_CHMR1_CC2SSEL_MSK | TIMER_CHMR1_I2FLT_MSK  | TIMER_CHMR1_IC2PRES_MSK);
    tmpchmr1 |= (uint32_t)(init->ic2_sel << 8U);
    tmpchmr1 |= (uint32_t)(init->ic2_filter << 12U);
    tmpchmr1 |= (uint32_t)(init->ic2_psc << 10U);

    /* Set TI1 and TI2 polarity and enable TI1 and TI2 */
    tmpccep &= (uint32_t)~(TIMER_CCEP_CC1POL_MSK | TIMER_CCEP_CC1NPOL_MSK | TIMER_CCEP_CC2POL_MSK | TIMER_CCEP_CC2NPOL_MSK);
    tmpccep |= (uint32_t)(init->ic1_polarity << 1U);
    tmpccep |= (uint32_t)(init->ic2_polarity << 5U);
    tmpccep |= (uint32_t)(TIMER_CCEP_CC1EN_MSK | TIMER_CCEP_CC2EN_MSK);

    /* Set encoder mode */
    md_timer_set_slave_mode_smods(TIMERx, init->mode);

    /* Write to TIMERx CCMR1 */
    WRITE_REG(TIMERx->CHMR1, tmpchmr1);

    /* Write to TIMERx CCER */
    WRITE_REG(TIMERx->CCEP, tmpccep);

    return MD_OK;
}

/**
  * @brief  Set the fields of the TIMERx Hall sensor interface configuration data
  *         structure to their default values.
  * @param  init pointer to a @ref md_timer_hall_sensor_init_t structure
  * @retval None
  */
void timer_hallsensor_struct_init(md_timer_hall_sensor_init_t *init)
{
    /* Set the default configuration */
    init->polarity = MD_TIMER_IC_POLARITY_RISE;
    init->psc      = MD_TIMER_IC_PSC_DIV1;
    init->filter   = 0U;
    init->delay    = 0U;
}

/**
  * @brief  Configure the Hall sensor interface of the timer instance.
  * @note TIMERx CH1, CH2 and CH3 inputs connected through a XOR
  *       to the TI1 input channel
  * @param  TIMERx Timer Instance
  * @param  init pointer to a @ref md_timer_hall_sensor_init_t structure
  * @retval An md_status_t enumeration value:
  *          - MD_OK: TIMERx registers are de-initialized
  *          - MD_ERROR: not applicable
  */
md_status_t timer_hallsensor_init(TIMER_TypeDef *TIMERx, md_timer_hall_sensor_init_t *init)
{
    uint32_t tmpcon2 = 0U;
    uint32_t tmpchmr1 = 0U;
    uint32_t tmpccep = 0U;
    uint32_t tmpsmcon = 0U;

    /* Disable the CC1 and CC2: Reset the CC1E and CC2E Bits */
    TIMERx->CCEP &= (uint32_t)~(TIMER_CCEP_CC1EN_MSK | TIMER_CCEP_CC2EN_MSK);

    /* Get the TIMERx CON2 register value */
    tmpcon2 = READ_REG(TIMERx->CON2);

    /* Get the TIMERx CHMR1 register value */
    tmpchmr1 = READ_REG(TIMERx->CHMR1);

    /* Get the TIMERx CCER register value */
    tmpccep = READ_REG(TIMERx->CCEP);

    /* Get the TIMERx SMCON register value */
    tmpsmcon = READ_REG(TIMERx->SMCON);

    /* Connect TIMx_CH1, CH2 and CH3 pins to the TI1 input */
    tmpcon2 |= TIMER_CON2_I1FSEL_MSK;

    /* OC2REF signal is used as trigger output (TRGO) */
    tmpcon2 |= (0x4U << TIMER_CON2_TRGOSEL_POSS) | (0x1U << TIMER_CON2_TRGOSEL_POSS);

    /* Configure the slave mode controller */
    tmpsmcon &= (uint32_t)~(TIMER_SMCON_TSSEL_MSK | TIMER_SMCON_SMODS_MSK);
    tmpsmcon |= (0x4U << TIMER_SMCON_TSSEL_POSS);
    tmpsmcon |= (0x4U << TIMER_SMCON_SMODS_POSS);

    /* Configure input channel 1 */
    tmpchmr1 &= (uint32_t)~(TIMER_CHMR1_CC1SSEL_POSS | TIMER_CHMR1_I1FLT_MSK  | TIMER_CHMR1_IC1PRES_MSK);
    tmpchmr1 |= (uint32_t)(TIMER_CHMR1_CC1SSEL_MSK);
    tmpchmr1 |= (uint32_t)(init->filter << TIMER_CHMR1_I1FLT_POSS);
    tmpchmr1 |= (uint32_t)(init->psc << TIMER_CHMR1_IC1PRES_POSS);

    /* Configure input channel 2 */
    tmpchmr1 &= (uint32_t)~(TIMER_CHMR1_CH2OMOD_MSK | TIMER_CHMR1_CH2OFEN_MSK  | TIMER_CHMR1_CH2OPEN_MSK  | TIMER_CHMR1_CH2OCLREN_MSK);
    tmpchmr1 |= (uint32_t)(0x7U << TIMER_CHMR1_CH1OMOD_POSS);

    /* Set Channel 1 polarity and enable Channel 1 and Channel2 */
    tmpccep &= (uint32_t)~(TIMER_CCEP_CC1POL_MSK | TIMER_CCEP_CC1NPOL_MSK | TIMER_CCEP_CC2POL_MSK | TIMER_CCEP_CC2NPOL_MSK);
    tmpccep |= (uint32_t)(init->polarity << TIMER_CCEP_CC1POL_POS);
    tmpccep |= (uint32_t)(TIMER_CCEP_CC1EN_MSK | TIMER_CCEP_CC2EN_MSK);

    /* Write to TIMERx CON2 */
    WRITE_REG(TIMERx->CON2, tmpcon2);

    /* Write to TIMERx SMCON */
    WRITE_REG(TIMERx->SMCON, tmpsmcon);

    /* Write to TIMERx CHMR1 */
    WRITE_REG(TIMERx->CHMR1, tmpchmr1);

    /* Write to TIMERx CCEP */
    WRITE_REG(TIMERx->CCEP, tmpccep);

    /* Write to TIMERx CCR2 */
    md_timer_set_capture_compare2_value_ccrv2(TIMERx, init->delay);

    return MD_OK;
}

/**
  * @brief  Set the fields of the Break and Dead Time configuration data structure
  *         to their default values.
  * @param  init pointer to a @ref md_timer_break_dead_time_t structure (Break and Dead Time configuration data structure)
  * @retval None
  */
void timer_bdtr_struct_init(md_timer_break_dead_time_t *init)
{
    /* Set the default configuration */
    init->off_run     = DISABLE;
    init->off_idle    = DISABLE;
    init->lock_level  = MD_TIMER_LOCK_LEVEL_OFF;
    init->dead_time   = (uint8_t)0x00;
    init->break_state = DISABLE;
    init->polarity    = MD_TIMER_BREAK_POLARITY_LOW;
    init->auto_out    = DISABLE;
}

/**
  * @brief  Configure the Break and Dead Time feature of the timer instance.
  * @param  TIMERx Timer Instance
  * @param  init pointer to a @ref md_timer_break_dead_time_t structure
  * @retval An md_status_t enumeration value:
  *          - MD_OK: Break and Dead Time is initialized
  *          - MD_ERROR: not applicable
  */
md_status_t timer_bdtr_init(TIMER_TypeDef *TIMERx, md_timer_break_dead_time_t *init)
{
    uint32_t tmpbdcfg = 0U;

    /* Set the Lock level, the Break enable Bit and the Polarity, the OSSR State,
    the OSSI State, the dead time value and the Automatic Output Enable Bit */

    /* Set the BDTR bits */
    MODIFY_REG(tmpbdcfg, TIMER_BDCFG_DT_MSK, (init->dead_time << TIMER_BDCFG_DT_POSS));
    MODIFY_REG(tmpbdcfg, TIMER_BDCFG_LOCKLVL_MSK, (init->lock_level << TIMER_BDCFG_LOCKLVL_POSS));
    MODIFY_REG(tmpbdcfg, TIMER_BDCFG_OFFSSI_MSK, (init->off_idle << TIMER_BDCFG_OFFSSI_POS));
    MODIFY_REG(tmpbdcfg, TIMER_BDCFG_OFFSSR_MSK, (init->off_run << TIMER_BDCFG_OFFSSR_POS));
    MODIFY_REG(tmpbdcfg, TIMER_BDCFG_BRKEN_MSK, (init->break_state << TIMER_BDCFG_BRKEN_POS));
    MODIFY_REG(tmpbdcfg, TIMER_BDCFG_BRKP_MSK, (init->polarity << TIMER_BDCFG_BRKP_POS));
    MODIFY_REG(tmpbdcfg, TIMER_BDCFG_AOEN_MSK, (init->auto_out << TIMER_BDCFG_AOEN_POS));
    MODIFY_REG(tmpbdcfg, TIMER_BDCFG_GOEN_MSK, (init->auto_out << TIMER_BDCFG_GOEN_POS));

    /* Set TIMx_BDTR */
    WRITE_REG(TIMERx->BDCFG, tmpbdcfg);
    return MD_OK;
}
/**
 * @}
 */
/**
  * @}
  */
/** @defgroup MD_TIMER_Private_Functions TIMER Private Functions
  * @{
  */
/**
  * @brief  Configure the TIMERx input channel 1.
  * @param  TIMERx Timer Instance
  * @param  init pointer to the the TIMERx input channel 1 configuration data structure
  * @retval An md_status_t enumeration value:
  *          - MD_OK: TIMERx registers are de-initialized
  *          - MD_ERROR: not applicable
  */
static md_status_t ic1_config(TIMER_TypeDef *TIMERx, md_timer_ic_init_t *init)
{
    /* Disable the Channel 1: Reset the CC1E Bit */
    TIMERx->CCEP &= (uint32_t)~TIMER_CCEP_CC1EN_MSK;

    /* Select the Input and set the filter and the prescaler value */
    MODIFY_REG(TIMERx->CHMR1,
               (TIMER_CHMR1_CC1SSEL_MSK | TIMER_CHMR1_I1FLT_MSK | TIMER_CHMR1_IC1PRES_MSK),
               (init->sel << 0U) | (init->filter << 4U) | (init->psc << 2U));

    /* Select the Polarity and set the CC1E Bit */
    MODIFY_REG(TIMERx->CCEP,
               (TIMER_CCEP_CC1POL_MSK | TIMER_CCEP_CC1NPOL_MSK),
               (init->polarity << 1U) | (TIMER_CCEP_CC1EN_MSK));

    return MD_OK;
}

/**
  * @brief  Configure the TIMERx input channel 2.
  * @param  TIMERx Timer Instance
  * @param  init pointer to the the TIMERx input channel 2 configuration data structure
  * @retval An md_status_t enumeration value:
  *          - MD_OK: TIMERx registers are de-initialized
  *          - MD_ERROR: not applicable
  */
static md_status_t ic2_config(TIMER_TypeDef *TIMERx, md_timer_ic_init_t *init)
{
    /* Disable the Channel 2: Reset the CC2E Bit */
    TIMERx->CCEP &= (uint32_t)~TIMER_CCEP_CC2EN_MSK;

    /* Select the Input and set the filter and the prescaler value */
    MODIFY_REG(TIMERx->CHMR1,
               (TIMER_CHMR1_CC2SSEL_MSK | TIMER_CHMR1_I2FLT_MSK | TIMER_CHMR1_IC2PRES_MSK),
               (init->sel << 8U) | (init->filter << 12U) | (init->psc << 10U));

    /* Select the Polarity and set the CC2E Bit */
    MODIFY_REG(TIMERx->CCEP,
               (TIMER_CCEP_CC2POL_MSK | TIMER_CCEP_CC2NPOL_MSK),
               (init->polarity << 5U) | (TIMER_CCEP_CC2EN_MSK));

    return MD_OK;
}

/**
  * @brief  Configure the TIMERx input channel 3.
  * @param  TIMERx Timer Instance
  * @param  init pointer to the the TIMERx input channel 3 configuration data structure
  * @retval An md_status_t enumeration value:
  *          - MD_OK: TIMERx registers are de-initialized
  *          - MD_ERROR: not applicable
  */
static md_status_t ic3_config(TIMER_TypeDef *TIMERx, md_timer_ic_init_t *init)
{
    /* Disable the Channel 3: Reset the CC3E Bit */
    TIMERx->CCEP &= (uint32_t)~TIMER_CCEP_CC3EN_MSK;

    /* Select the Input and set the filter and the prescaler value */
    MODIFY_REG(TIMERx->CHMR2,
               (TIMER_CHMR2_CC3SSEL_MSK | TIMER_CHMR2_I3FLT_MSK | TIMER_CHMR2_IC3PRES_MSK),
               (init->sel << 0U) | (init->filter << 4U) | (init->psc << 2U));

    /* Select the Polarity and set the CC3E Bit */
    MODIFY_REG(TIMERx->CCEP,
               (TIMER_CCEP_CC3POL_MSK | TIMER_CCEP_CC3NPOL_MSK),
               (init->polarity << 9U) | (TIMER_CCEP_CC3EN_MSK));

    return MD_OK;
}

/**
  * @brief  Configure the TIMERx input channel 4.
  * @param  TIMERx Timer Instance
  * @param  init pointer to the the TIMERx input channel 4 configuration data structure
  * @retval An md_status_t enumeration value:
  *          - MD_OK: TIMERx registers are de-initialized
  *          - MD_ERROR: not applicable
  */
static md_status_t ic4_config(TIMER_TypeDef *TIMERx, md_timer_ic_init_t *init)
{
    /* Disable the Channel 4: Reset the CC4E Bit */
    TIMERx->CCEP &= (uint32_t)~TIMER_CCEP_CC4EN_MSK;

    /* Select the Input and set the filter and the prescaler value */
    MODIFY_REG(TIMERx->CHMR2,
               (TIMER_CHMR2_CC4SSEL_MSK | TIMER_CHMR2_I4FLT_MSK | TIMER_CHMR2_IC4PRES_MSK),
               (init->sel << 8U) | (init->filter << 12U) | (init->psc << 10U));

    /* Select the Polarity and set the CC4E Bit */
    MODIFY_REG(TIMERx->CCEP,
               TIMER_CCEP_CC4POL_MSK,
               (init->polarity << 13U) | (TIMER_CCEP_CC4EN_MSK));

    return MD_OK;
}

/**
  * @brief  Configure the TIMERx output channel 1.
  * @param  TIMERx Timer Instance
  * @param  init pointer to the the TIMERx output channel 1 configuration data structure
  * @retval An md_status_t enumeration value:
  *          - MD_OK: TIMERx registers are de-initialized
  *          - MD_ERROR: not applicable
  */
static md_status_t oc1_config(TIMER_TypeDef *TIMERx, md_timer_oc_init_t *init)
{
    uint32_t tmpchmr1 = 0U;
    uint32_t tmpccep = 0U;
    uint32_t tmpcon2 = 0U;

    /* Disable the Channel 1: Reset the CC1E Bit */
    CLEAR_BIT(TIMERx->CCEP, TIMER_CCEP_CC1EN_MSK);

    /* Get the TIMERx CCEP register value */
    tmpccep = READ_REG(TIMERx->CCEP);

    /* Get the TIMERx CON2 register value */
    tmpcon2 = READ_REG(TIMERx->CON2);

    /* Get the TIMERx CHMR1 register value */
    tmpchmr1 = READ_REG(TIMERx->CHMR1);

    /* Reset Capture/Compare selection Bits */
    CLEAR_BIT(tmpchmr1, TIMER_CHMR1_CC1SSEL_MSK);

    /* Set the Output Compare Mode */
    MODIFY_REG(tmpchmr1, TIMER_CHMR1_CH1OMOD_MSK, init->oc_mode << 4U);

    /* Set the Output Compare Polarity */
    MODIFY_REG(tmpccep, TIMER_CCEP_CC1POL_MSK, init->oc_polarity << 1U);

    /* Set the Output State */
    MODIFY_REG(tmpccep, TIMER_CCEP_CC1EN_MSK, init->ocstate);

    /* Set the complementary output Polarity */
    MODIFY_REG(tmpccep, TIMER_CCEP_CC1NPOL_MSK, init->ocn_polarity << 3U);

    /* Set the complementary output State */
    MODIFY_REG(tmpccep, TIMER_CCEP_CC1NE_MSK, init->ocnstate << 2U);

    /* Set the Output Idle state */
    MODIFY_REG(tmpcon2, TIMER_CON2_OISS1_MSK, init->oc_idle << 8U);

    /* Set the complementary output Idle state */
    MODIFY_REG(tmpcon2, TIMER_CON2_OISS1N_MSK, init->ocn_idle << 9U);

    /* Write to TIMERx CON2 */
    WRITE_REG(TIMERx->CON2, tmpcon2);

    /* Write to TIMERx CHMR1 */
    WRITE_REG(TIMERx->CHMR1, tmpchmr1);

    /* Set the Capture Compare Register value */
    md_timer_set_capture_compare1_value_ccrv1(TIMERx, init->pulse);

    /* Write to TIMERx CCEP */
    WRITE_REG(TIMERx->CCEP, tmpccep);

    return MD_OK;
}

/**
  * @brief  Configure the TIMERx output channel 1.
  * @param  TIMERx Timer Instance
  * @param  init pointer to the the TIMERx output channel 1 configuration data structure
  * @retval An md_status_t enumeration value:
  *          - MD_OK: TIMERx registers are de-initialized
  *          - MD_ERROR: not applicable
  */
static md_status_t oc2_config(TIMER_TypeDef *TIMERx, md_timer_oc_init_t *init)
{
    uint32_t tmpchmr1 = 0U;
    uint32_t tmpccep = 0U;
    uint32_t tmpcon2 = 0U;

    /* Disable the Channel 2: Reset the CC2E Bit */
    CLEAR_BIT(TIMERx->CCEP, TIMER_CCEP_CC2EN_MSK);

    /* Get the TIMERx CCEP register value */
    tmpccep = READ_REG(TIMERx->CCEP);

    /* Get the TIMERx CON2 register value */
    tmpcon2 = READ_REG(TIMERx->CON2);

    /* Get the TIMERx CHMR1 register value */
    tmpchmr1 = READ_REG(TIMERx->CHMR1);

    /* Reset Capture/Compare selection Bits */
    CLEAR_BIT(tmpchmr1, TIMER_CHMR1_CC2SSEL_MSK);

    /* Set the Output Compare Mode */
    MODIFY_REG(tmpchmr1, TIMER_CHMR1_CH2OMOD_MSK, init->oc_mode << 12U);

    /* Set the Output Compare Polarity */
    MODIFY_REG(tmpccep, TIMER_CCEP_CC2POL_MSK, init->oc_polarity << 5U);

    /* Set the Output State */
    MODIFY_REG(tmpccep, TIMER_CCEP_CC2EN_MSK, init->ocstate << 4U);

    /* Set the complementary output Polarity */
    MODIFY_REG(tmpccep, TIMER_CCEP_CC2NPOL_MSK, init->ocn_polarity << 7U);

    /* Set the complementary output State */
    MODIFY_REG(tmpccep, TIMER_CCEP_CC2NE_MSK, init->ocnstate << 6U);

    /* Set the Output Idle state */
    MODIFY_REG(tmpcon2, TIMER_CON2_OISS2_MSK, init->oc_idle << 10U);

    /* Set the complementary output Idle state */
    MODIFY_REG(tmpcon2, TIMER_CON2_OISS2N_MSK, init->ocn_idle << 11U);

    /* Write to TIMERx CON2 */
    WRITE_REG(TIMERx->CON2, tmpcon2);

    /* Write to TIMERx CHMR1 */
    WRITE_REG(TIMERx->CHMR1, tmpchmr1);

    /* Set the Capture Compare Register value */
    md_timer_set_capture_compare2_value_ccrv2(TIMERx, init->pulse);

    /* Write to TIMERx CCEP */
    WRITE_REG(TIMERx->CCEP, tmpccep);

    return MD_OK;
}

/**
  * @brief  Configure the TIMERx output channel 1.
  * @param  TIMERx Timer Instance
  * @param  init pointer to the the TIMERx output channel 1 configuration data structure
  * @retval An md_status_t enumeration value:
  *          - MD_OK: TIMERx registers are de-initialized
  *          - MD_ERROR: not applicable
  */
static md_status_t oc3_config(TIMER_TypeDef *TIMERx, md_timer_oc_init_t *init)
{
    uint32_t tmpchmr2 = 0U;
    uint32_t tmpccep = 0U;
    uint32_t tmpcon2 = 0U;

    /* Disable the Channel 3: Reset the CC3E Bit */
    CLEAR_BIT(TIMERx->CCEP, TIMER_CCEP_CC3EN_MSK);

    /* Get the TIMERx CCEP register value */
    tmpccep = READ_REG(TIMERx->CCEP);

    /* Get the TIMERx CON2 register value */
    tmpcon2 = READ_REG(TIMERx->CON2);

    /* Get the TIMERx CHMR2 register value */
    tmpchmr2 = READ_REG(TIMERx->CHMR2);

    /* Reset Capture/Compare selection Bits */
    CLEAR_BIT(tmpchmr2, TIMER_CHMR2_CC3SSEL_MSK);

    /* Set the Output Compare Mode */
    MODIFY_REG(tmpchmr2, TIMER_CHMR2_CH3OMOD_MSK, init->oc_mode << 4U);

    /* Set the Output Compare Polarity */
    MODIFY_REG(tmpccep, TIMER_CCEP_CC3POL_MSK, init->oc_polarity << 9U);

    /* Set the Output State */
    MODIFY_REG(tmpccep, TIMER_CCEP_CC3EN_MSK, init->ocstate << 8U);

    /* Set the complementary output Polarity */
    MODIFY_REG(tmpccep, TIMER_CCEP_CC3NPOL_MSK, init->ocn_polarity << 11U);

    /* Set the complementary output State */
    MODIFY_REG(tmpccep, TIMER_CCEP_CC3NE_MSK, init->ocnstate << 10U);

    /* Set the Output Idle state */
    MODIFY_REG(tmpcon2, TIMER_CON2_OISS3_MSK, init->oc_idle << 12U);

    /* Set the complementary output Idle state */
    MODIFY_REG(tmpcon2, TIMER_CON2_OISS3N_MSK, init->ocn_idle << 13U);

    /* Write to TIMERx CON2 */
    WRITE_REG(TIMERx->CON2, tmpcon2);

    /* Write to TIMERx CHMR1 */
    WRITE_REG(TIMERx->CHMR2, tmpchmr2);

    /* Set the Capture Compare Register value */
    md_timer_set_capture_compare3_value_ccrv3(TIMERx, init->pulse);

    /* Write to TIMERx CCEP */
    WRITE_REG(TIMERx->CCEP, tmpccep);

    return MD_OK;
}

/**
  * @brief  Configure the TIMERx output channel 1.
  * @param  TIMERx Timer Instance
  * @param  init pointer to the the TIMERx output channel 1 configuration data structure
  * @retval An md_status_t enumeration value:
  *          - MD_OK: TIMERx registers are de-initialized
  *          - MD_ERROR: not applicable
  */
static md_status_t oc4_config(TIMER_TypeDef *TIMERx, md_timer_oc_init_t *init)
{
    uint32_t tmpchmr2 = 0U;
    uint32_t tmpccep = 0U;
    uint32_t tmpcon2 = 0U;

    /* Disable the Channel 4: Reset the CC4E Bit */
    CLEAR_BIT(TIMERx->CCEP, TIMER_CCEP_CC4EN_MSK);

    /* Get the TIMERx CCEP register value */
    tmpccep = READ_REG(TIMERx->CCEP);

    /* Get the TIMERx CON2 register value */
    tmpcon2 = READ_REG(TIMERx->CON2);

    /* Get the TIMERx CHMR2 register value */
    tmpchmr2 = READ_REG(TIMERx->CHMR2);

    /* Reset Capture/Compare selection Bits */
    CLEAR_BIT(tmpchmr2, TIMER_CHMR2_CC4SSEL_MSK);

    /* Set the Output Compare Mode */
    MODIFY_REG(tmpchmr2, TIMER_CHMR2_CH4OMOD_MSK, init->oc_mode << 12U);

    /* Set the Output Compare Polarity */
    MODIFY_REG(tmpccep, TIMER_CCEP_CC4POL_MSK, init->oc_polarity << 13U);

    /* Set the Output State */
    MODIFY_REG(tmpccep, TIMER_CCEP_CC4EN_MSK, init->ocstate << 12U);

    /* Set the Output Idle state */
    MODIFY_REG(tmpcon2, TIMER_CON2_OISS4_MSK, init->oc_idle << 14U);

    /* Write to TIMERx CON2 */
    WRITE_REG(TIMERx->CON2, tmpcon2);

    /* Write to TIMERx CHMR1 */
    WRITE_REG(TIMERx->CHMR2, tmpchmr2);

    /* Set the Capture Compare Register value */
    md_timer_set_capture_compare4_value_ccrv4(TIMERx, init->pulse);

    /* Write to TIMERx CCEP */
    WRITE_REG(TIMERx->CCEP, tmpccep);

    return MD_OK;
}
/**
  * @}
  */

/**
  * @} MD_TIMER
  */
/**
  * @} Micro_Driver
  */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
