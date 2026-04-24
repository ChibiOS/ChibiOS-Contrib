/**
  *********************************************************************************
  *
  * @file    md_i2s.c
  * @brief   I2S module driver.
  *
  * @version V1.0
  * @date    9 Jan. 2023
  * @author  AE Team
  * @note
  *          Change Logs:
  *          Date            Author          Notes
  *          9 Jan. 2023     Shiwa         The first version
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
  **********************************************************************************
  */

/* Includes ------------------------------------------------------------------ */

#include "md_cmu.h"
#include "md_i2s.h"

/* Private Macros ------------------------------------------------------------ */
/* Private Variables --------------------------------------------------------- */
/* Public Variables ---------------------------------------------------------- */
/* Private Constants --------------------------------------------------------- */
/* Private function prototypes ----------------------------------------------- */

/* Private Function ---------------------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */
/** @addtogroup MD_I2S
  * @{
  */

/** @addtogroup MD_I2S_Public_Functions
  * @{
  */
/** @addtogroup MD_I2S_Public_Functions_Group1
  * @{
  */
/**
  * @brief  Reset the I2S specificed.
  * @param  I2Sx: I2S Instance.
  * @retval None
  */
void md_i2s_reset(SPI_I2S_TypeDef *I2Sx)
{
    I2Sx->I2SCFG = 0x0;
    I2Sx->I2SPR  = 0x0;

    return;
}

/**
  * @brief  Initialize the I2S registers according to the specified parameters in init.
  * @param  I2Sx: I2S Instance.
  * @param  init pointer to a @ref md_i2s_init_t structure
  * @retval An ErrorStatus enumeration value.
  */
md_status_t md_i2s_init(SPI_I2S_TypeDef *I2Sx, md_i2s_init_t *init)
{
    uint32_t tmp = 0U, clk, _div;

    if ((I2Sx == NULL) || (init == NULL))
        return MD_ERROR;

    md_i2s_reset(I2Sx);

    tmp |= (init->ext_clk_en << SPI_I2SPR_EXTCKEN_POS);

    /* Get I2S clock */
    if (init->ext_clk_en)
        clk = init->ext_clk;
    else
        clk = md_cmu_get_pclk_clock();

    if (init->mck_en)
    {
        _div = (clk + ((init->sampling) << 7)) / ((init->sampling) << 8);
        tmp |= SPI_I2SPR_MCKOE_MSK;
    }
    else
    {
        if (init->ch_len == MD_I2S_WIDE_16)
            _div = ((clk / init->sampling) >> 5);
        else
            _div = ((clk / init->sampling) >> 6);
    }

    if (_div & 0x1)
    {
        SET_BIT(tmp, SPI_I2SPR_ODD_MSK);
        --_div;
    }
    else
    {
        CLEAR_BIT(tmp, SPI_I2SPR_ODD_MSK);
    }

    if (init->standard != MD_I2S_STD_PCM)
        MODIFY_REG(tmp, SPI_I2SPR_I2SDIV_MSK, (_div >> 1) << SPI_I2SPR_I2SDIV_POSS);
    else
        MODIFY_REG(tmp, SPI_I2SPR_I2SDIV_MSK, _div << SPI_I2SPR_I2SDIV_POSS);

    I2Sx->I2SPR = tmp;

    tmp  = I2Sx->I2SCFG;
    tmp |= ((init->ch_len << SPI_I2SCFG_CHLEN_POS) | (init->data_len << SPI_I2SCFG_DATLEN_POSS) |
            (init->polarity << SPI_I2SCFG_CKPOL_POS) | (init->standard << SPI_I2SCFG_I2SSTD_POSS) |
            (1 << SPI_I2SCFG_I2SMOD_POS));
    I2Sx->I2SCFG = tmp;

    if (init->standard == MD_I2S_STD_PCM)
        I2Sx->I2SCFG |= (init->pcm_frame << SPI_I2SCFG_PCMSYNC_POS);

    return MD_OK;
}

/**
  * @brief  Set each @ref md_i2s_init_t field to default value.
  * @param  init pointer to a @ref md_i2s_init_t structure
  *           whose fields will be set to default values.
  * @retval None
  */
void md_i2s_struct_init(md_i2s_init_t *init)
{
    init->ch_len     = MD_I2S_WIDE_16;
    init->data_len   = MD_I2S_LEN_16;
    init->polarity   = MD_I2S_INACTIVE_LOW;
    init->standard   = MD_I2S_STD_PHI;
    init->pcm_frame  = MD_I2S_FRAME_SHORT;
    init->ext_clk_en = DISABLE;
    init->ext_clk    = 0x0;
    init->mck_en     = DISABLE;
    init->sampling   = 96 * 1024;

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
