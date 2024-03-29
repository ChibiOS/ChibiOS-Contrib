/**********************************************************************************
 *
 * @file    md_crc.c
 * @brief   md_crc C file
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
#include "system_fs026.h"
#include "md_crc.h"
#include "md_rcu.h"

/** @addtogroup Micro_Driver
  * @{
  */


/** @defgroup CRC CRC
  * @brief CRC micro driver
  * @{
  */


/* Private types --------------------------------------------------------------*/
/* Private variables ----------------------------------------------------------*/
/* Private constants ----------------------------------------------------------*/
/* Private macros -------------------------------------------------------------*/
/** @defgroup MD_CRC_Private_Macros CRC Private Macros
  * @{
  */


/**
  * @} MD_CRC_Private_Macros
  */

/* Private function prototypes ------------------------------------------------*/

/* Public functions -----------------------------------------------------------*/
/** @addtogroup MD_CRC_Public_Functions CRC Public Functions
  * @{
  */

/**
  * @brief  De-initialize CRC registers (Registers restored to their default values).
  * @param  crc CRC Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: CRC registers are de-initialized
  *          - ERROR: CRC registers are not de-initialized
  */
ErrorStatus md_crc_deinit(CRC_TypeDef *crc)
{
    ErrorStatus status = SUCCESS;

    if (crc == CRC)
    {
        /* Force CRC reset */
        md_rcu_enable_crc_reset(RCU);

        /* Release CRC reset */
        md_rcu_disable_crc_reset(RCU);
    }
    else
    {
        status = ERROR;
    }

    return (status);
}

/**
  * @} MD_RCU_Public_Functions
  */

/**
  * @} RCU
  */

/**
  * @} Micro_Driver
  */

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
