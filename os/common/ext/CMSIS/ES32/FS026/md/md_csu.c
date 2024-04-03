/**********************************************************************************
 *
 * @file    md_csu.c
 * @brief   md_csu C file
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov  2021    Ginger          the first version
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

/* Includes -------------------------------------------------------------------*/
#include "system_fs026.h"
#include "md_csu.h"
#include "md_rcu.h"
/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup CSU CSU
  * @brief CSU micro driver
  * @{
  */

/* Private types --------------------------------------------------------------*/
/* Private variables ----------------------------------------------------------*/
/* Private constants ----------------------------------------------------------*/
/* Private macros -------------------------------------------------------------*/
/* Private function prototypes ------------------------------------------------*/

/* Public functions -----------------------------------------------------------*/

/** @defgroup CSU_PUB_FUNC CSU Public Functions
  * @brief CSU Public Functions
  * @{
  */

/**
  * @brief  CSU Initialization
  * @param  csu CSU Instance
  * @param  CSU Init Structure
  * @retval None
  */
void md_csu_init(CSU_TypeDef *csu, md_csu_init_typedef *CSU_InitStruct)
{
    md_csu_set_trim_source(csu, CSU_InitStruct->TrimSel);
    md_csu_set_sync_polarity(csu, CSU_InitStruct->PolSel);
    md_csu_set_sync_source(csu, CSU_InitStruct->SyncSrc);
    md_csu_set_sync_source_div(csu, CSU_InitStruct->SyncDiv);
}

/**
  * @brief  Set CSU Count tolerance and Counter reload value
  * @param  csu CSU Instance
  * @param  CSU_InitStruct
  * @param  clksrc  Clock Source
            @arg @ref CSU_CLKSRC_GPIO
            @arg @ref CSU_CLKSRC_LOSC
            @arg @ref CSU_CLKSRC_USB_SOF
  * @retval None
  */
void md_csu_set(CSU_TypeDef *csu, md_csu_init_typedef *CSU_InitStruct, uint16_t clksrc)
{
    uint8_t cntth, div;
    uint16_t reload, fsync;

    div = 1 << (CSU_InitStruct->SyncDiv >> CSU_CFG_SYNCDIV_POSS);

    fsync = clksrc / div;

    reload = ((__HRC48 / fsync) - 1);
    cntth = (__HRC48 / fsync / 5 / 100 / 2);

    md_csu_set_trim_counter_tolerance(csu, cntth);
    md_csu_set_trim_counter_reload(csu, reload);

    md_csu_enable_trim_counter(csu);
    md_csu_enable_trim_auto(csu);
}


/**
  * @} CSU_PUB_FUNC CSU Public Functions
  */

/**
  * @} CSU
  */

/**
  * @} Micro_Driver
  */

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
