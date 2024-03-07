/**********************************************************************************
 *
 * @file    utils.h
 * @brief   header file of utils.c
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __UTILS_H__
#define __UTILS_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <stdint.h>
#include "fs026.h"

/** @addtogroup
  * @{
  */

/** @addtogroup UTILS UTILS
  * @brief UTILS module driver
  * @{
  */

/** @defgroup ALD_Public_Types Public Types
  * @{
  */

/**
  * @brief  ALD Status structures definition
  */
typedef enum
{
    OK      = 0x0,
    Error   = 0x1,
    BUSY    = 0x2,
    TIMEOUT = 0x3,
} ald_status_t;

/**
  * @brief  SysTick interval definition
  */
typedef enum
{
    SYSTICK_INTERVAL_1MS     = 1000,
    SYSTICK_INTERVAL_10MS    = 100,
    SYSTICK_INTERVAL_100MS   = 10,
    SYSTICK_INTERVAL_1000MS  = 1,
} systick_interval_t;
/**
  * @} ALD_Public_Types
  */

/** @defgroup ALD_Public_Macros Public Macros
  * @{
  */
#define TICK_INT_PRIORITY 3
#define ALD_MAX_DELAY  0xFFFFFFFF
#define UNUSED(x)   ((void)(x))
#define IS_BIT_SET(reg, bit)  (((reg) & (bit)) != RESET)
#define IS_BIT_CLR(reg, bit)  (((reg) & (bit)) == RESET)
#define RESET_HANDLE_STATE(x)  ((x)->state = 0)
#define __LOCK(x)        \
    do {          \
        if ((x)->lock == LOCK) {  \
            return BUSY;    \
        }        \
        else {        \
            (x)->lock = LOCK;  \
        }        \
    } while (0)

#define __UNLOCK(x)        \
    do {          \
        (x)->lock = UNLOCK;    \
    } while (0)

/**
  * @}
  */

/** @defgroup ALD_Private_Macros Private Macros
  * @{
  */
#define IS_PRIO(x)  ((x) < 4)
#define IS_SYSTICK_INTERVAL(x)  (((x) == SYSTICK_INTERVAL_1MS)   || \
                                 ((x) == SYSTICK_INTERVAL_10MS)  || \
                                 ((x) == SYSTICK_INTERVAL_100MS) || \
                                 ((x) == SYSTICK_INTERVAL_1000MS))
/**
  * @}ALD_Private_Macros
  */

/** @addtogroup ALD_Public_Functions
  * @{
  */

/** @addtogroup ALD_Public_Functions_Group1
  * @{
  */

/* Initialization functions */
void ald_init(void);
void __init_tick(uint32_t prio);
void systick_interval_select(systick_interval_t value);

/**
  * @} ALD_Public_Functions_Group1
  */

/** @addtogroup ALD_Public_Functions_Group2
  * @{
  */
/* Peripheral Control functions */
void __inc_tick(void);
void __delay_ms(__IO uint32_t delay);
uint32_t __get_tick(void);
void __suspend_tick(void);
void __resume_tick(void);
void systick_irq_cbk(void);
uint32_t get_lib_version(void);
ald_status_t __wait_flag(uint32_t *reg, uint32_t bit, FlagStatus status, uint32_t timeout);
void mcu_irq_config(IRQn_Type irq, uint8_t prio, TypeFunc status);
uint32_t mcu_get_tick(void);
uint32_t mcu_get_cpu_id(void);
void __clear_tick(void);
/**
  * @} ALD_Public_Functions_Group2
  */

/**
  * @} ALD_Public_Functions
  */

/**
  * @} UTILS
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif
/******************* (C) COPYRIGHT Eastsoft Microelectronics END OF FILE****/

