/**********************************************************************************
 *
 * @file    md_cmu.h
 * @brief   Header file of CSU module driver.
 *
 * @date    2023.02.13
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          2023.02.13      liuhy           the first version
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

#ifndef __MD_CSU_H__
#define __MD_CSU_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------ */
#include "md_utils.h"
#include "md_syscfg.h"

/* Exported Constants -------------------------------------------------------- */

/* Exported Variables -------------------------------------------------------- */

/* Exported Types ------------------------------------------------------------ */

/* Exported Macros ----------------------------------------------------------- */

/* Exported Functions -------------------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_CSU CSU
  * @brief CSU micro driver

  * @{
  */


/** @defgroup MD_CSU_Public_Functions CSU Public Functions
  * @{
  */
/** @defgroup MD_CSU_Public_Functions_Group2 CON
  * @{
  */

/**
  * @brief  Enable CSU_CON_AUTOEN
  * @retval NONE
  */
__STATIC_INLINE void md_csu_enable_auto(void)
{
    SET_BIT(CSU->CON, CSU_CON_AUTOEN_MSK);
}

/**
  * @brief  Disable CSU_CON_AUTOEN
  * @retval NONE
  */
__STATIC_INLINE void md_csu_disable_auto(void)
{
    CLEAR_BIT(CSU->CON, CSU_CON_AUTOEN_MSK);
}

/**
  * @brief  Enable CSU_CON_CNTEN
  * @retval NONE
  */
__STATIC_INLINE void md_csu_enable_cnt(void)
{
    SET_BIT(CSU->CON, CSU_CON_CNTEN_MSK);
}

/**
  * @brief  Disable CSU_CON_CNTEN
  * @retval NONE
  */
__STATIC_INLINE void md_csu_disable_cnt(void)
{
    CLEAR_BIT(CSU->CON, CSU_CON_CNTEN_MSK);
}

/**
  * @}
  */
/** @defgroup MD_CSU_Public_Functions_Group1 Initialization and Get BUS Clock value
  * @{
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
/**
  * @}
  */
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __MD_CSU_H__ */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
