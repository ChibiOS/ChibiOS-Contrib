/**********************************************************************************
 *
 * @file    md_tick.h
 * @brief   header file of md_tick.c
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
#ifndef __MD_SYST_H__
#define __MD_SYST_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_TICK TICK
  * @brief TICK micro driver
  * @{
  */

/** @defgroup MD_SYST_Public_Macros TICK Public Macros
  * @{
  */

/**
  * @brief MD_SYST_CLKSRC System Tick clock source selection
  */
#define MD_SYSTICK_CLKSRC_HCLK_DIV8         (0x00000000UL)  /** @brief The clock source is an external reference clock. */
#define MD_SYSTICK_CLKSRC_HCLK              (0x00000001UL)  /** @brief The core clock is used for SysTick. */
/**
  * @}
  */

/** @defgroup MD_SYST_Public_Functions TICK Public Functions
  * @{
  */

/** @defgroup MD_SYST_Public_Functions_Group2 CSR
  * @{
  */
/**
  * @brief  Set TICK CSR Register
  * @param  tick TICK Instance
  * @param  csr
  *     @arg Max Value 0x7
  *     @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_tick_set_csr(SYST_TypeDef *tick, uint32_t csr)
{
    WRITE_REG(tick->CSR, csr);
}

/**
  * @brief  Get TICK CSR Register
  * @param  tick TICK Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_tick_get_csr(SYST_TypeDef *tick)
{
    return (uint32_t)(READ_REG(tick->CSR));
}

/**
  * @brief  Get TICK CSR Count Flag
  * @param  tick TICK Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_tick_is_active_flag_csr_count(SYST_TypeDef *tick)
{
    return (READ_BIT(tick->CSR, SYST_CSR_COUNT) == (SYST_CSR_COUNT));
}

/**
  * @brief  Set TICK CSR Clock Source
  * @param  tick TICK Instance
  * @param  ClkSource System Tick clock source selection
  *         @arg @ref MD_SYSTICK_CLKSRC_HCLK_DIV8
  *         @arg @ref MD_SYSTICK_CLKSRC_HCLK
  * @retval None
  */
__STATIC_INLINE void md_tick_set_csr_clksrc(SYST_TypeDef *tick, uint32_t ClkSource)
{
    MODIFY_REG(tick->CSR, SYST_CSR_CLKSRC, ClkSource << SYST_CSR_CLKSRC_POS);
}

/**
  * @brief  Get TICK CSR Clock Source
  * @param  tick TICK Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_SYSTICK_CLKSRC_HCLK_DIV8
  *         @arg @ref MD_SYSTICK_CLKSRC_HCLK
  */
__STATIC_INLINE uint32_t md_tick_get_csr_clksource(SYST_TypeDef *tick)
{
    return (uint32_t)(READ_BIT(tick->CSR, SYST_CSR_CLKSRC) >> SYST_CSR_CLKSRC_POS);
}

/**
  * @brief  Enable TICK CSR Tick Interrupt
  * @param  tick TICK Instance
  * @retval None
  */
__STATIC_INLINE void md_tick_enable_csr_tickie(SYST_TypeDef *tick)
{
    SET_BIT(tick->CSR, SYST_CSR_TICKIE);
}

/**
  * @brief  Disable TICK CSR Tick Interrupt
  * @param  tick TICK Instance
  * @retval None
  */
__STATIC_INLINE void md_tick_disable_csr_tickie(SYST_TypeDef *tick)
{
    CLEAR_BIT(tick->CSR, SYST_CSR_TICKIE);
}

/**
  * @brief  is TICK CSR Tick Interrupt Enabled
  * @param  tick TICK Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_tick_is_enabled_csr_tickie(SYST_TypeDef *tick)
{
    return (READ_BIT(tick->CSR, SYST_CSR_TICKIE) == (SYST_CSR_TICKIE));
}

/**
  * @brief  Enable TICK CSR Enable
  * @param  tick TICK Instance
  * @retval None
  */
__STATIC_INLINE void md_tick_enable_csr_enable(SYST_TypeDef *tick)
{
    SET_BIT(tick->CSR, SYST_CSR_ENABLE);
}

/**
  * @brief  Disable TICK CSR Enable
  * @param  tick TICK Instance
  * @retval None
  */
__STATIC_INLINE void md_tick_disable_csr_enable(SYST_TypeDef *tick)
{
    CLEAR_BIT(tick->CSR, SYST_CSR_ENABLE);
}

/**
  * @brief  is TICK CSR Enable Enabled
  * @param  None
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_tick_is_enabled_csr_enable(SYST_TypeDef *tick)
{
    return (READ_BIT(tick->CSR, SYST_CSR_ENABLE) == (SYST_CSR_ENABLE));
}
/**
  * @}
  */

/** @defgroup MD_SYST_Public_Functions_Group3 RVR
  * @{
  */
/**
  * @brief  Set TICK RVR Register
  * @param  tick TICK Instance
  * @param  rvr
  *         @arg Max Value 0xffffff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_tick_set_rvr(SYST_TypeDef *tick, uint32_t rvr)
{
    WRITE_REG(tick->RVR, rvr);
}

/**
  * @brief  Get TICK RVR Register
  * @param  tick TICK Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xffffff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_tick_get_rvr(SYST_TypeDef *tick)
{
    return (uint32_t)(READ_REG(tick->RVR));
}

/**
  * @brief  Set TICK RVR Reload
  * @param  tick TICK Instance
  * @param  Reload
  *         @arg Max Value 0xffffff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_tick_set_rvr_reload(SYST_TypeDef *tick, uint32_t Reload)
{
    MODIFY_REG(tick->RVR, SYST_RVR_RELOAD, Reload);
}

/**
  * @brief  Get TICK RVR Reload
  * @param  tick TICK Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xfffffff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_tick_get_rvr_reload(SYST_TypeDef *tick)
{
    return (uint32_t)(READ_BIT(tick->RVR, SYST_RVR_RELOAD));
}
/**
  * @}
  */

/** @defgroup MD_SYST_Public_Functions_Group4 CVR
  * @{
  */
/**
  * @brief  Set TICK CVR Register
  * @param  tick TICK Instance
  * @param  cvr
  *         @arg Max Value 0xffffff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_tick_set_cvr(SYST_TypeDef *tick, uint32_t cvr)
{
    WRITE_REG(tick->CVR, cvr);
}

/**
  * @brief  Get TICK CVR Register
  * @param  tick TICK Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xffffff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_tick_get_cvr(SYST_TypeDef *tick)
{
    return (uint32_t)(READ_REG(tick->CVR));
}

/**
  * @brief  Set TICK CVR Current
  * @param  tick TICK Instance
  * @param  Current
  *         @arg Max Value 0xffffff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_tick_set_cvr_current(SYST_TypeDef *tick, uint32_t Current)
{
    MODIFY_REG(tick->CVR, SYST_CVR_CURRENT, Current);
}

/**
  * @brief  Get TICK CVR Current
  * @param  tick TICK Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xfffffff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_tick_get_cvr_current(SYST_TypeDef *tick)
{
    return (uint32_t)(READ_BIT(tick->CVR, SYST_CVR_CURRENT));
}

/**
  * @}
  */

/** @defgroup MD_SYST_Public_Functions_Group1 Initialization
  * @{
  */
void    md_tick_init(uint8_t);
uint32_t    md_tick_get_mscnt(void);
uint32_t    md_tick_get_100uscnt(void);
uint32_t    md_tick_get_10uscnt(void);
void    md_tick_waitms(uint8_t Unit, uint16_t msCnt);
void    md_tick_wait100us(uint16_t Unit, uint16_t usCnt);
void    md_tick_wait10us(uint16_t Unit, uint16_t usCnt);
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
  * @} Micro_Driver
  */


#ifdef __cplusplus
}
#endif
#endif

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
