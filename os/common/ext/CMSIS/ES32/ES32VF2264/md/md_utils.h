/**********************************************************************************
 *
 * @file    md_utils.h
 * @brief   Header file of UTILS module driver.
 *
 * @date    13 Dec. 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          13 Dec. 2022    Lisq            the first version
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
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------ */
#include <stdlib.h>
#include "es32vf2264.h"
#include "type.h"

/* Exported Constants -------------------------------------------------------- */

/* Exported Variables -------------------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */

/** @addtogroup MD_UTILS
  * @{
  */

/* Exported Types ------------------------------------------------------------ */
/** @defgroup MD_UTILS_Public_Types Utils Public Types
  * @{
  */

/* Exported Types ------------------------------------------------------------ */

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

/** @defgroup MD_UTILS_Public_Macros Utils Public Macros
  * @{
  */

/* Exported Macros ----------------------------------------------------------- */

/**
  * @brief  Nested IRQ start : Save CSR and enable global interrupt.
  */
#ifdef NEST_INT_ENABLE
    #define MD_NEST_INT_START(); \
    uint32_t val_mcause, val_mepc, val_mstatus; \
    __ASM volatile("csrr %0, mcause" : "=r"(val_mcause)); \
    __ASM volatile("csrr %0, mepc" : "=r"(val_mepc)); \
    __ASM volatile("csrr %0, mstatus" : "=r"(val_mstatus)); \
    __enable_irq();
#else
    #define MD_NEST_INT_START();
#endif /* NEST_INT_ENABLE */

/**
  * @brief  Nested IRQ end : Restore CSR and disable global interrupt.
  */
#ifdef NEST_INT_ENABLE
    #define MD_NEST_INT_END(); \
    __disable_irq(); \
    __ASM volatile("csrw mstatus, %0" : : "r"(val_mstatus)); \
    __ASM volatile("csrw mepc, %0" : : "r"(val_mepc)); \
    __ASM volatile("csrw mcause, %0" : : "r"(val_mcause));
#else
    #define MD_NEST_INT_END();
#endif /* NEST_INT_ENABLE */

/**
  * @}
  */
/* Exported Functions -------------------------------------------------------- */

/** @addtogroup MD_UTILS_Public_Functions
  * @{
  */
extern void md_init_1ms_tick(void);
extern void md_inc_tick(void);
extern __weak void md_systick_irq_cbk(void);
extern uint32_t md_get_tick(void);
extern void md_delay_1ms(__IO uint32_t delay);
extern void md_delay_1us(__IO uint32_t delay);
extern void md_mcu_irq_config(IRQn_Type irq, uint8_t prio, type_func_t status);
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
#endif /* __cplusplus */
#endif /* __MD_UTILS_H__ */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
