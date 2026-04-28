/**********************************************************************************
 *
 * @file    md_i2c.c
 * @brief   I2C module driver.
 *
 * @date    13 July 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          13 July 2022    Lisq            the first version
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
#include <string.h>
#include "md_i2c.h"
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
/** @defgroup MD_I2C I2C
  * @{
  */

/** @addtogroup MD_I2C_Public_Functions
  * @{
  */

/** @addtogroup MD_I2C_Public_Functions_Group1
  * @{
  */
/**
 * @brief  I2C Configuration Speed function.
  * @param  I2Cx: I2C instance.
  * @param  init: Pointer to a i2c_init_t structure that contains
  *                the configuration information for the specified I2C.
 * @param  clk: I2C Peripheral bus clock
 * @retval Status, see @ref md_status_t.
 */
static void _i2c_speed_init(I2C_TypeDef *I2Cx, md_i2c_init_t *init, uint32_t clk)
{
    int32_t t_scl, t_pre, tmp;

    if (init->module == MD_I2C_MODULE_SLAVE)
    {
        init->clk_speed = 450000UL;
    }

    if (init->clk_speed <= 100000UL)
    {
        tmp = clk / 4000000UL;
        clk = (tmp >= 16UL) ? (clk >> 4UL) : 4000000UL;
    }
    else
    {
        tmp = clk / 8000000UL;
        clk = (tmp >= 16UL) ? (clk >> 4UL) : 8000000UL;
    }

    tmp = tmp >= 16UL ? 15UL : tmp;
    MODIFY_REG(I2Cx->TIMINGR, I2C_TIMINGR_PRESC_MSK, tmp << I2C_TIMINGR_PRESC_POSS);

    t_scl = 1000000000 / init->clk_speed;
    t_pre = 1000000000 / clk;

    tmp = (t_scl * 10) / (t_pre << 1UL);
    tmp = (tmp % 10) >= 5 ? (tmp / 10 + 1) : tmp / 10;
    tmp = tmp >= 255UL ? 255UL : tmp;

    MODIFY_REG(I2Cx->TIMINGR, I2C_TIMINGR_SCLL_MSK, (tmp - 1UL) << I2C_TIMINGR_SCLL_POSS);

    if (init->clk_speed > 100000UL)
    {
        if ((tmp - 1UL) > 3UL)
        {
            MODIFY_REG(I2Cx->TIMINGR, I2C_TIMINGR_SCLDEL_MSK, ((tmp - 1UL) / 3UL) << I2C_TIMINGR_SCLDEL_POSS);
            MODIFY_REG(I2Cx->TIMINGR, I2C_TIMINGR_SDADEL_MSK, ((((tmp - 1UL) / 3UL) >= 3) ? 3 : (((tmp - 1UL) / 3UL) % 3)) << I2C_TIMINGR_SDADEL_POSS);
        }
        else
        {
            MODIFY_REG(I2Cx->TIMINGR, I2C_TIMINGR_SCLDEL_MSK, 1UL << I2C_TIMINGR_SCLDEL_POSS);
            MODIFY_REG(I2Cx->TIMINGR, I2C_TIMINGR_SDADEL_MSK, 1UL << I2C_TIMINGR_SDADEL_POSS);
        }
    }
    else
    {
        MODIFY_REG(I2Cx->TIMINGR, I2C_TIMINGR_SDADEL_MSK, 2UL << I2C_TIMINGR_SDADEL_POSS);
        MODIFY_REG(I2Cx->TIMINGR, I2C_TIMINGR_SCLDEL_MSK, 4UL << I2C_TIMINGR_SCLDEL_POSS);
    }

    tmp = t_scl - (tmp + READ_BITS(I2Cx->TIMINGR, I2C_TIMINGR_SCLDEL_MSK, I2C_TIMINGR_SCLDEL_POSS) + \
                   READ_BITS(I2Cx->TIMINGR, I2C_TIMINGR_SDADEL_MSK, I2C_TIMINGR_SDADEL_POSS) + 1UL) * t_pre;

    tmp = (tmp * 10) / t_pre;
    tmp = (tmp % 10) >= 5 ? (tmp / 10 + 1) : tmp / 10;
    tmp = tmp >= 255UL ? 255UL : tmp;
    /* tscll >= 3*tsclh */
    tmp = (tmp - 1) <= (READ_BITS(I2Cx->TIMINGR, I2C_TIMINGR_SCLL_MSK, I2C_TIMINGR_SCLL_POSS) / 3) ? (READ_BITS(I2Cx->TIMINGR, I2C_TIMINGR_SCLL_MSK, I2C_TIMINGR_SCLL_POSS) / 3) + 1 : tmp;
    MODIFY_REG(I2Cx->TIMINGR, I2C_TIMINGR_SCLH_MSK, (tmp - 1UL) << I2C_TIMINGR_SCLH_POSS);

}

/**
  * @brief  Initializes the I2C according to the specified parameters
  *         in the i2c_init_t and initialize the associated handle.
  * @param  I2Cx: I2C instance.
  * @param  init: Pointer to a i2c_init_t structure that contains
  *                the configuration information for the specified I2C.
  * @retval Status, see @ref md_status_t.
  */
md_status_t md_i2c_init(I2C_TypeDef *I2Cx, md_i2c_init_t *init)
{
    uint32_t freq;

    if ((I2Cx == NULL) || (init == NULL))
        return MD_ERROR;

    freq = md_cmu_get_pclk_clock();
    MD_I2C_DISABLE(I2Cx);

    _i2c_speed_init(I2Cx, init, freq);
    MODIFY_REG(I2Cx->CON1, I2C_CON1_NOSTRETCH_MSK, (init->no_stretch) << I2C_CON1_NOSTRETCH_POS);
    MODIFY_REG(I2Cx->CON1, I2C_CON1_GCEN_MSK, (init->general_call) << I2C_CON1_GCEN_POS);

    if (init->dual_addr == MD_I2C_DUALADDR_ENABLE)
    {
        CLEAR_BIT(I2Cx->ADDR1, I2C_ADDR1_OA1EN_MSK);
        MODIFY_REG(I2Cx->ADDR1, I2C_ADDR1_OA1_MSK, (init->own_addr1 & 0x3FF) << I2C_ADDR1_OA1_POSS);
        SET_BIT(I2Cx->ADDR1, I2C_ADDR1_OA1EN_MSK);

        CLEAR_BIT(I2Cx->ADDR2, I2C_ADDR2_OA2EN_MSK);
        MODIFY_REG(I2Cx->ADDR2, I2C_ADDR2_OA2_MSK, (init->own_addr2 & 0x7F) << I2C_ADDR2_OA2_POSS);
        SET_BIT(I2Cx->ADDR2, I2C_ADDR2_OA2EN_MSK);
    }
    else
    {
        if (init->addr_mode == MD_I2C_ADDR_10BIT)
        {
            CLEAR_BIT(I2Cx->ADDR1, I2C_ADDR1_OA1EN_MSK);
            SET_BIT(I2Cx->ADDR1, I2C_ADDR1_OA1MODE_MSK);
            MODIFY_REG(I2Cx->ADDR1, I2C_ADDR1_OA1_MSK, (init->own_addr1 & 0x3FF) << I2C_ADDR1_OA1_POSS);
            SET_BIT(I2Cx->ADDR1, I2C_ADDR1_OA1EN_MSK);
        }
        else
        {
            CLEAR_BIT(I2Cx->ADDR2, I2C_ADDR2_OA2EN_MSK);
            MODIFY_REG(I2Cx->ADDR2, I2C_ADDR2_OA2_MSK, (init->own_addr2 & 0x7F) << I2C_ADDR2_OA2_POSS);
            SET_BIT(I2Cx->ADDR2, I2C_ADDR2_OA2EN_MSK);
        }
    }

    MD_I2C_ENABLE(I2Cx);
    return MD_OK;
}

/**
  * @brief  Set each @ref md_i2c_init_t field to default value.
  * @param  init Pointer to a @ref md_i2c_init_t structure.
  * @retval None
  */
void md_i2c_struct_init(md_i2c_init_t *init)
{
    init->module       = MD_I2C_MODULE_MASTER;
    init->clk_speed    = MD_I2C_STANDARD_MODE_MAX_CLK;
    init->own_addr1    = 0xA0;
    init->addr_mode    = MD_I2C_ADDR_7BIT;
    init->dual_addr    = MD_I2C_DUALADDR_DISABLE;
    init->own_addr2    = 0x0;
    init->general_call = MD_I2C_GENERALCALL_DISABLE;
    init->no_stretch   = MD_I2C_NOSTRETCH_ENABLE;
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
