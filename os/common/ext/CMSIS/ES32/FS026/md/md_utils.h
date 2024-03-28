/**********************************************************************************
 *
 * @file    md_utils.h
 * @brief   Header file of UTILS module driver.
 *
 * @date    30 Apri 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          30 Apri 2021    yanght          the first version
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


#ifndef __MD_UTILS_H__
#define __MD_UTILS_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------ */
#include <stdlib.h>
//#include "md_conf.h"
#include "type.h"
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @addtogroup MD_UTILS
  * @{
  */

/** @defgroup MD_UTILS_Public_Types UTILS Public Types
  * @{
  */
/**
  * @brief  MD Status structures definition
  */
typedef enum
{
    MD_OK      = 0x0U,  /**< Status: OK */
    MD_ERROR   = 0x1U,  /**< Status: ERROR */
    MD_BUSY    = 0x2U,  /**< Status: BUSY */
    MD_TIMEOUT = 0x3U,  /**< Status: TIMEOUT */
} md_status_t;
/**
  * @}
  */
/** @defgroup MD_Private_Macros Public Macros
  * @{
  */
#define MD_MCU_UID0_ADDR    0x000109E0U
#define MD_MCU_UID1_ADDR    0x000109E8U
#define MD_MCU_UID2_ADDR    0x000109F0U
#define MD_MCU_CHIPID_ADDR  0x00010BF8U
/**
  * @}
  */
/** @addtogroup MD_UTILS_Public_Functions
  * @{
  */
void md_init_1ms_tick(void);
void md_inc_tick(void);
__WEAK void md_systick_irq_cbk(void);
uint32_t md_get_tick(void);
void md_delay_1ms(__IO uint32_t delay);
void md_delay_1us(__IO uint32_t delay);
void md_mcu_irq_config(IRQn_Type irq, uint8_t prio, TypeFunc status);
uint32_t md_mcu_get_cpu_id(void);
void md_mcu_get_uid(uint8_t *buf);
uint32_t md_mcu_get_chipid(void);
/**
  * @}
  */
/**
  * @}
  */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif
#endif

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
