/**********************************************************************************
 *
 * @file    md_iwdt.h
 * @brief   header file of md_iwdt.c
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov 2021     Ginger          the first version
 *          24 Mar 2022     AE Team         Modify MD Driver
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
#ifndef __MD_IWDT_H
#define __MD_IWDT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_IWDT IWDT
  * @brief IWDT micro driver
  * @{
  */

/** @defgroup MD_IWDT_Public_Macros IWDT Public Macros
  * @{
  */

/**
  * @brief MD_IWDT_Key IWDT Key
  */
#define IWDT_KEY_RELOAD                 0x0000AAAAU               /*!< IWDT Reload Counter Enable   */
#define IWDT_KEY_ENABLE                 0x0000CCCCU               /*!< IWDT Peripheral Enable       */
#define IWDT_KEY_WR_ACCESS_ENABLE       0x00005555U               /*!< IWDT KR Write Access Enable  */

/**
  * @brief MD_IWDT_Prescaler IWDT Prescaler
  */
#define IWDT_PRESCALER_4                0x00000000U                     /*!< Divider by 4   */
#define IWDT_PRESCALER_8                0x00000001U                     /*!< Divider by 8   */
#define IWDT_PRESCALER_16               0x00000002U                     /*!< Divider by 16  */
#define IWDT_PRESCALER_32               0x00000003U                     /*!< Divider by 32  */
#define IWDT_PRESCALER_64               0x00000004U                     /*!< Divider by 64  */
#define IWDT_PRESCALER_128              0x00000005U                     /*!< Divider by 128 */
#define IWDT_PRESCALER_256              0x00000006U                     /*!< Divider by 256 */
/**
  * @}
  */

/** @defgroup MD_IWDT_Public_Functions IWDT Public Functions
  * @{
  */

/** @defgroup MD_IWDT_Public_Functions_Group2 BKKR
  * @{
  */

/**
  * @brief  Start the Independent Watchdog
  * @note   if the hardware watchdog option is selected
  * @param  IWDTx IWDT Instance
  * @retval None
  */
__STATIC_INLINE void md_iwdt_set_start(IWDT_TypeDef *IWDTx)
{
    WRITE_REG(IWDT->BKKR, IWDT_KEY_ENABLE);
}

/**
  * @brief  Reload the Independent Watchdog
  * @note   if the hardware watchdog option is selected
  * @param  IWDTx IWDT Instance
  * @retval None
  */
__STATIC_INLINE void md_iwdt_set_reload_counter(IWDT_TypeDef *IWDTx)
{
    WRITE_REG(IWDT->BKKR, IWDT_KEY_RELOAD);
}

/**
  * @brief  Enable write access the Independent Watchdog
  * @note   if the hardware watchdog option is selected
  * @param  IWDTx IWDT Instance
  * @retval None
  */
__STATIC_INLINE void md_iwdt_set_enable_write_access(IWDT_TypeDef *IWDTx)
{
    WRITE_REG(IWDT->BKKR, IWDT_KEY_WR_ACCESS_ENABLE);
}

/**
  * @}
  */

/** @defgroup MD_IWDT_Public_Functions_Group3 BKPR
  * @{
  */

/**
  * @brief  Select the prescaler of the IWDT
  * @param  IWDTx IWDT Instance
  * @param  Prescaler This parameter can be one of the following values:
  *         @arg @ref IWDT_PRESCALER_4
  *         @arg @ref IWDT_PRESCALER_8
  *         @arg @ref IWDT_PRESCALER_16
  *         @arg @ref IWDT_PRESCALER_32
  *         @arg @ref IWDT_PRESCALER_64
  *         @arg @ref IWDT_PRESCALER_128
  *         @arg @ref IWDT_PRESCALER_256
  * @retval None
  */
__STATIC_INLINE void md_iwdt_set_prescaler(IWDT_TypeDef *IWDTx, uint32_t Prescaler)
{
    WRITE_REG(IWDTx->BKPR, Prescaler);
}

/**
  * @brief  Get the selected prescaler of the IWDT
  * @param  IWDTx IWDT Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref IWDT_PRESCALER_4
  *         @arg @ref IWDT_PRESCALER_8
  *         @arg @ref IWDT_PRESCALER_16
  *         @arg @ref IWDT_PRESCALER_32
  *         @arg @ref IWDT_PRESCALER_64
  *         @arg @ref IWDT_PRESCALER_128
  *         @arg @ref IWDT_PRESCALER_256
  */
__STATIC_INLINE uint32_t md_iwdt_get_prescaler(IWDT_TypeDef *IWDTx)
{
    return (uint32_t)(READ_REG(IWDTx->BKPR));
}
/**
  * @}
  */

/** @defgroup MD_IWDT_Public_Functions_Group4 BKRLR
  * @{
  */

/**
  * @brief  Specify the IWDT down-counter reload value
  * @param  IWDTx IWDT Instance
  * @param  Counter Value between Min_Data=0 and Max_Data=0x0FFF
  * @retval None
  */
__STATIC_INLINE void md_iwdt_set_reload(IWDT_TypeDef *IWDTx, uint32_t Counter)
{
    WRITE_REG(IWDTx->BKRLR, Counter);
}

/**
  * @brief  Get the specified IWDT down-counter reload value
  * @param  IWDTx IWDT Instance
  * @retval Value between Min_Data=0 and Max_Data=0x0FFF
  */
__STATIC_INLINE uint32_t md_iwdt_get_reload(IWDT_TypeDef *IWDTx)
{
    return (uint32_t)(READ_REG(IWDTx->BKRLR));
}
/**
  * @}
  */

/** @defgroup MD_IWDT_Public_Functions_Group5 BKFR
  * @{
  */

/**
  * @brief  Get Register update
  * @param  IWDTx IWDT Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_iwdt_is_active_flag_busy(IWDT_TypeDef *IWDTx)
{
    return (READ_REG(IWDTx->BKFR));
}
/**
  * @}
  */

/** @defgroup MD_IWDT_Public_Functions_Group6 BKWINR
  * @{
  */

/**
  * @brief  Specify high limit of the window value to be compared to the down-counter.
  * @param  IWDTx IWDT Instance
  * @param  Window Value between Min_Data=0 and Max_Data=0x0FFF
  * @retval None
  */
__STATIC_INLINE void md_iwdt_set_window(IWDT_TypeDef *IWDTx, uint32_t Window)
{
    WRITE_REG(IWDTx->BKWINR, Window);
}

/**
  * @brief  Get the high limit of the window value specified.
  * @param  IWDTx IWDT Instance
  * @retval Value between Min_Data=0 and Max_Data=0x0FFF
  */
__STATIC_INLINE uint32_t md_iwdt_get_window(IWDT_TypeDef *IWDTx)
{
    return (uint32_t)(READ_REG(IWDTx->BKWINR));
}
/**
  * @}
  */

/** @defgroup MD_IWDT_Public_Functions_Group7 BKSR
  * @{
  */

/**
  * @brief  Get 12-bit counter.
  * @param  IWDTx IWDT Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_iwdt_get_count_value(IWDT_TypeDef *IWDTx)
{
    return (uint32_t)(READ_REG(IWDTx->BKSR));
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
  * @}  Micro_Driver
  */

#ifdef __cplusplus
}
#endif
#endif

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
