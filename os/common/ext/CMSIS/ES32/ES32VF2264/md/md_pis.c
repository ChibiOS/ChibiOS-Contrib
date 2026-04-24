/**********************************************************************************
 *
 * @file    md_pis.c
 * @brief   PIS module driver.
 *
 * @date    19 July 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          19 July 2022    Lisq            the first version
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
#include "md_pis.h"

/* Private Macros ------------------------------------------------------------ */
/* Private Variables --------------------------------------------------------- */
/* Public Variables ---------------------------------------------------------- */
/* Private Constants --------------------------------------------------------- */
/* Private function prototypes ----------------------------------------------- */

/* Private Function ---------------------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */

/** @addtogroup MD_PIS
  * @{
  */

/** @addtogroup MD_PIS_Public_Functions
  * @{
  */
/** @addtogroup MD_PIS_Public_Functions_Group1
  * @{
  */
/**
  * @brief  Reset the PIS register
  * @retval None
  */
void md_pis_reset(void)
{
    uint32_t i;

    for (i = 0; i < 8; ++i)
        WRITE_REG(PIS->CH_CON[i], 0x0);

    WRITE_REG(PIS->CH_OER, 0x0);
    WRITE_REG(PIS->TAR_CON0, 0x0);
    WRITE_REG(PIS->TAR_CON1, 0x0);
    WRITE_REG(PIS->UART0_TXMCR, 0x0);
    WRITE_REG(PIS->UART1_TXMCR, 0x0);
    WRITE_REG(PIS->UART2_TXMCR, 0x0);
    WRITE_REG(PIS->UART3_TXMCR, 0x0);
    WRITE_REG(PIS->UART4_TXMCR, 0x0);

    return;
}

/**
  * @brief  Initializes the PIS mode according to the specified parameters in
  *         the md_pis_init_t.
  * @param  init: Pointer to a md_pis_init_t structure that contains
  *         the configuration information for the specified PIS module.
  * @retval Status, see @ref md_status_t.
  */
md_status_t md_pis_init(md_pis_init_t *init)
{
    uint8_t ch, c_idx, shift;

    if (init == NULL)
        return MD_ERROR;

    ch    = init->c_trig & 0xF;
    c_idx = (init->c_trig >> 4) & 0xF;
    shift = (init->c_trig >> 8) & 0xFF;

    MODIFY_REG(PIS->CH_CON[ch], PIS_CH0_CON_SRCS_MSK, ((init->p_src) >> 4) << PIS_CH0_CON_SRCS_POSS);
    MODIFY_REG(PIS->CH_CON[ch], PIS_CH0_CON_MSIGS_MSK, ((init->p_src) & 0xF) << PIS_CH0_CON_MSIGS_POSS);

    if (init->p_clk == init->c_clk)
    {
        MODIFY_REG(PIS->CH_CON[ch], PIS_CH0_CON_SYNCSEL_MSK, MD_PIS_SYN_DIRECT << PIS_CH0_CON_SYNCSEL_POSS);
    }
    else
    {
        if (init->p_output == MD_PIS_OUT_LEVEL)
        {
            if (init->c_clk == MD_PIS_CLK_PCLK)
                MODIFY_REG(PIS->CH_CON[ch], PIS_CH0_CON_SYNCSEL_MSK, MD_PIS_SYN_LEVEL_ASY_APB << PIS_CH0_CON_SYNCSEL_POSS);

            if (init->c_clk == MD_PIS_CLK_PCLK)
                MODIFY_REG(PIS->CH_CON[ch], PIS_CH0_CON_SYNCSEL_MSK, MD_PIS_SYN_LEVEL_ASY_APB << PIS_CH0_CON_SYNCSEL_POSS);

            if (init->c_clk == MD_PIS_CLK_HCLK)
                MODIFY_REG(PIS->CH_CON[ch], PIS_CH0_CON_SYNCSEL_MSK, MD_PIS_SYN_LEVEL_ASY_AHB << PIS_CH0_CON_SYNCSEL_POSS);
        }

        if (init->p_output == MD_PIS_OUT_PULSE)
        {
            if (init->c_clk == MD_PIS_CLK_PCLK)
                MODIFY_REG(PIS->CH_CON[ch], PIS_CH0_CON_SYNCSEL_MSK, MD_PIS_SYN_PULSE_ASY_APB << PIS_CH0_CON_SYNCSEL_POSS);

            if (init->c_clk == MD_PIS_CLK_PCLK)
                MODIFY_REG(PIS->CH_CON[ch], PIS_CH0_CON_SYNCSEL_MSK, MD_PIS_SYN_PULSE_ASY_APB << PIS_CH0_CON_SYNCSEL_POSS);

            if (init->c_clk == MD_PIS_CLK_HCLK)
                MODIFY_REG(PIS->CH_CON[ch], PIS_CH0_CON_SYNCSEL_MSK, MD_PIS_SYN_PULSE_ASY_AHB << PIS_CH0_CON_SYNCSEL_POSS);
        }
    }

    MODIFY_REG(PIS->CH_CON[ch], PIS_CH0_CON_TSCKS_MSK, (init->c_clk) << PIS_CH0_CON_TSCKS_POSS);
    MODIFY_REG(PIS->CH_CON[ch], PIS_CH0_CON_EDGS_MSK, init->p_edge << PIS_CH0_CON_EDGS_POSS);

    switch (c_idx)
    {
        case 0:
            PIS->TAR_CON0 |= (1 << shift);
            break;

        case 1:
            PIS->TAR_CON1 |= (1 << shift);
            break;

        default:
            break;
    }

    return MD_OK;
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
