/**********************************************************************************
 *
 * @file    md_wwdt.c
 * @brief   md_wwdt C file
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov  2021    Ginger          the first version
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
#include "md_rcu.h"
#include "md_wwdt.h"

/** @addtogroup Micro_Driver
  * @{
  */

#if defined (WWDT)

/** @defgroup WWDT WWDT
  * @brief WWDT micro driver
  * @{
  */

/* Private types --------------------------------------------------------------*/
/* Private variables ----------------------------------------------------------*/
/* Private constants ----------------------------------------------------------*/
/* Private macros -------------------------------------------------------------*/

/* Public functions -----------------------------------------------------------*/
/** @addtogroup MD_WWDT_Public_Functions WWDT Public Functions
  * @{
  */
/**
  * @brief  WWDT Initialization
  * @param  WWDT Init Structure
  * @retval None
  */
void md_wwdt_init(WWDT_TypeDef *WWD, md_wwdt_inittypedef *WWDT_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_MD_WWDT_ALL_INSTANCE(WWDT));
    assert_param(IS_MD_WWDT_PRESCALER(WWDT_InitStruct->Prescaler));
    assert_param(IS_MD_WWDT_WINDOW(WWDT_InitStruct->Window));
    assert_param(IS_MD_WWDT_COUNTER(WWDT_InitStruct->Counter));
    assert_param(IS_MD_WWDT_EWI_MODE(WWDT_InitStruct->EWIMode));

    if (WWDT_InitStruct->EWIMode == WWDT_EWI_ENABLE)
        md_wwdt_enable_it_ewi(WWD);
    else
        md_wwdt_disable_it_ewi(WWD);

    md_wwdt_set_count_value(WWD, WWDT_InitStruct->Counter);
    md_wwdt_set_prescaler(WWD, WWDT_InitStruct->Prescaler);
    md_wwdt_set_window(WWD, WWDT_InitStruct->Window);
    md_wwdt_enable(WWD);
}

/**
  * @} WWDT_PUB_FUNC WWDT Public Functions
  */

/**
  * @} GPIO
  */
#endif

/**
  * @} Micro_Driver
  */

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
