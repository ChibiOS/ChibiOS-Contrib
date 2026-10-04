/**********************************************************************************
 *
 * @file    md_syscfg.h
 * @brief   SYSCFG module driver.
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

#ifndef __MD_SYSCFG_H__
#define __MD_SYSCFG_H__

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/* Includes ------------------------------------------------------------------ */
#include "md_utils.h"

/* Exported Constants -------------------------------------------------------- */

/* Exported Variables -------------------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_SYSCFG SYSCFG
  * @brief SYSCFG module driver
  * @{
  */

/* Exported Macros ----------------------------------------------------------- */

/** @defgroup MD_SYSCFG_Public_Macros SYSCFG Public Macros
  * @{
  */
#define MD_SYSCFG_LOCK()       (WRITE_REG(SYSCFG->PROT, 0x0U))
#define MD_SYSCFG_UNLOCK()     (WRITE_REG(SYSCFG->PROT, 0x55AA6996U))
#define MD_GET_SYSCFG_LOCK()   (READ_BIT(SYSCFG->PROT, SYSCFG_PROT_PROT_MSK))

/* Exported Types ------------------------------------------------------------ */

/**
  * @brief PIS IO Select
  */
typedef enum
{
    MD_SYSCFG_PISIOCFG_PA = 0x0U,
    MD_SYSCFG_PISIOCFG_PB = 0x1U,
    MD_SYSCFG_PISIOCFG_PC = 0x2U,
    MD_SYSCFG_PISIOCFG_PD = 0x3U,
} md_syscfg_pisiocfg_t;

/**
  * @}
  */

/* Exported Functions -------------------------------------------------------- */

/** @defgroup MD_SYSCFG_Public_Functions SYSCFG Public Functions
  * @{
  */
/** @defgroup MD_SYSCFG_Public_Functions_Group2 BTADDR
  * @{
  */
/**
  * @brief  Set cpu boot address
  * @param  addr: cpu boot address
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_cpu_boot_addr(uint32_t addr)
{
    WRITE_REG(SYSCFG->BTADDR, addr);
}

/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group3 TBKCFG
  * @{
  */
/**
  * @brief  Enable clock safety event as the timer brake source
  * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_cssbke(void)
{
    SET_BIT(SYSCFG->TBKCFG, SYSCFG_TBKCFG_CCSBKE_MSK);
}

/**
  * @brief  Disable clock safety event as the timer brake source
  * @retval None
  */
__STATIC_INLINE void md_syscfg_disable_cssbke(void)
{
    CLEAR_BIT(SYSCFG->TBKCFG, SYSCFG_TBKCFG_CCSBKE_MSK);
}

/**
  * @brief  Whether clock safety event is the timer brake source
  * @retval 1-enable, 0-disable
  */
__STATIC_INLINE uint32_t md_syscfg_is_enable_cssbke(void)
{
    return READ_BITS(SYSCFG->TBKCFG, SYSCFG_TBKCFG_CCSBKE_MSK, SYSCFG_TBKCFG_CCSBKE_POS);
}

/**
  * @brief  Enable LVD event as the timer brake source
  * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_lvdbke(void)
{
    SET_BIT(SYSCFG->TBKCFG, SYSCFG_TBKCFG_LVDBKE_MSK);
}

/**
  * @brief  Disable LVD event as the timer brake source
  * @retval None
  */
__STATIC_INLINE void md_syscfg_disable_lvdbke(void)
{
    CLEAR_BIT(SYSCFG->TBKCFG, SYSCFG_TBKCFG_LVDBKE_MSK);
}

/**
  * @brief  Whether LVD event is the timer brake source
  * @retval 1-enable, 0-disable
  */
__STATIC_INLINE uint32_t md_syscfg_is_enable_lvdbke(void)
{
    return READ_BITS(SYSCFG->TBKCFG, SYSCFG_TBKCFG_LVDBKE_MSK, SYSCFG_TBKCFG_LVDBKE_POS);
}

/**
  * @brief  Enable CPU lock event as the timer brake source
  * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_clubke(void)
{
    SET_BIT(SYSCFG->TBKCFG, SYSCFG_TBKCFG_CLUBKE_MSK);
}

/**
  * @brief  Disable CPU lock as the timer brake source
  * @retval None
  */
__STATIC_INLINE void md_syscfg_disable_clubke(void)
{
    CLEAR_BIT(SYSCFG->TBKCFG, SYSCFG_TBKCFG_CLUBKE_MSK);
}

/**
  * @brief  Whether CPU lock is the timer brake source
  * @retval 1-enable, 0-disable
  */
__STATIC_INLINE uint32_t md_syscfg_is_enable_clubke(void)
{
    return READ_BITS(SYSCFG->TBKCFG, SYSCFG_TBKCFG_CLUBKE_MSK, SYSCFG_TBKCFG_CLUBKE_POS);
}

/**
  * @brief  Select PIS producer IO15
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io15sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO15SEL_MSK, io << SYSCFG_PISIOCFG_IO15SEL_POSS);
}

/**
  * @brief  Get PIS producer IO15
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io15sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO15SEL_MSK));
}

/**
  * @brief  Select PIS producer IO14
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io14sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO14SEL_MSK, io << SYSCFG_PISIOCFG_IO14SEL_POSS);
}

/**
  * @brief  Get PIS producer IO14
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io14sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO14SEL_MSK));
}

/**
  * @brief  Select PIS producer IO13
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io13sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO13SEL_MSK, io << SYSCFG_PISIOCFG_IO13SEL_POSS);
}

/**
  * @brief  Get PIS producer IO13
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io13sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO13SEL_MSK));
}

/**
  * @brief  Select PIS producer IO12
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io12sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO12SEL_MSK, io << SYSCFG_PISIOCFG_IO12SEL_POSS);
}

/**
  * @brief  Get PIS producer IO12
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io12sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO12SEL_MSK));
}

/**
  * @brief  Select PIS producer IO11
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io11sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO11SEL_MSK, io << SYSCFG_PISIOCFG_IO11SEL_POSS);
}

/**
  * @brief  Get PIS producer IO11
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io11sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO11SEL_MSK));
}

/**
  * @brief  Select PIS producer IO10
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io10sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO10SEL_MSK, io << SYSCFG_PISIOCFG_IO10SEL_POSS);
}

/**
  * @brief  Get PIS producer IO10
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io10sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO10SEL_MSK));
}

/**
  * @brief  Select PIS producer IO9
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io9sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO9SEL_MSK, io << SYSCFG_PISIOCFG_IO9SEL_POSS);
}

/**
  * @brief  Get PIS producer IO9
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io9sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO9SEL_MSK));
}

/**
  * @brief  Select PIS producer IO8
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io8sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO8SEL_MSK, io << SYSCFG_PISIOCFG_IO8SEL_POSS);
}

/**
  * @brief  Get PIS producer IO8
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io8sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO8SEL_MSK));
}

/**
  * @brief  Select PIS producer IO7
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io7sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO7SEL_MSK, io << SYSCFG_PISIOCFG_IO7SEL_POSS);
}

/**
  * @brief  Get PIS producer IO7
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io7sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO7SEL_MSK));
}

/**
  * @brief  Select PIS producer IO6
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io6sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO6SEL_MSK, io << SYSCFG_PISIOCFG_IO6SEL_POSS);
}

/**
  * @brief  Get PIS producer IO6
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io6sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO6SEL_MSK));
}

/**
  * @brief  Select PIS producer IO5
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io5sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO5SEL_MSK, io << SYSCFG_PISIOCFG_IO5SEL_POSS);
}

/**
  * @brief  Get PIS producer IO5
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io5sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO5SEL_MSK));
}

/**
  * @brief  Select PIS producer IO4
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io4sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO4SEL_MSK, io << SYSCFG_PISIOCFG_IO4SEL_POSS);
}

/**
  * @brief  Get PIS producer IO4
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io4sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO4SEL_MSK));
}

/**
  * @brief  Select PIS producer IO3
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io3sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO3SEL_MSK, io << SYSCFG_PISIOCFG_IO3SEL_POSS);
}

/**
  * @brief  Get PIS producer IO3
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io3sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO3SEL_MSK));
}

/**
  * @brief  Select PIS producer IO2
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io2sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO2SEL_MSK, io << SYSCFG_PISIOCFG_IO2SEL_POSS);
}

/**
  * @brief  Get PIS producer IO2
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io2sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO2SEL_MSK));
}

/**
  * @brief  Select PIS producer IO1
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io1sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO1SEL_MSK, io << SYSCFG_PISIOCFG_IO1SEL_POSS);
}

/**
  * @brief  Get PIS producer IO1
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io1sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO1SEL_MSK));
}

/**
  * @brief  Select PIS producer IO0
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @param  io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  * @retval None
  */
__STATIC_INLINE void md_syscfg_pisiocfg_io0sel(SYSCFG_TypeDef *SYSCFGx, md_syscfg_pisiocfg_t io)
{
    MODIFY_REG(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO0SEL_MSK, io << SYSCFG_PISIOCFG_IO0SEL_POSS);
}

/**
  * @brief  Get PIS producer IO0
  * @note
  * @param  SYSCFGx: SYSCFG Instance
  * @retval io: This parameter can be one of the following values:
  *         @arg @ref PA
  *         @arg @ref PB
  *         @arg @ref PC
  *         @arg @ref PD
  */
__STATIC_INLINE uint32_t md_syscfg_get_pisiocfg_io0sel(SYSCFG_TypeDef *SYSCFGx)
{
    return (READ_BIT(SYSCFGx->PISIOCFG, SYSCFG_PISIOCFG_IO0SEL_MSK));
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
/**
  * @}
  */
/**
  * @}
  */
#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __MD_SYSCFG_H__ */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
