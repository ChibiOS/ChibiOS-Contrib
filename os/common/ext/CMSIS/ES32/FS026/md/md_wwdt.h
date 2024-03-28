/**********************************************************************************
 *
 * @file    md_wwdt.h
 * @brief   header file of md_wwdt.c
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
#ifndef __MD_WWDT_H__
#define __MD_WWDT_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_WWDT WWDT
  * @brief WWDT micro driver
  * @{
  */

/** @defgroup MD_WWDT_Pubulic_Types WWDT Pubulic Types
  * @{
  */

/**
  * @brief   WWDT Init Structure.
  */
typedef struct
{
    uint32_t Prescaler;     /*!< Specifies the prescaler value of the WWDT.
                               This parameter can be a value of @ref WWDT_Prescaler */

    uint32_t Window;        /*!< Specifies the WWDT window value to be compared to the downcounter.
                               This parameter must be a number a minimum, 0x40 and a maximum, 0x7F */

    uint32_t Counter;       /*!< Specifies the WWDT free-running downcounter  value.
                               This parameter must be a number between a minimum, 0x40 and a maximum, 0x7F */

    uint32_t EWIMode ;      /*!< Specifies if WWDT Early Wakeup Interupt is enable or not.
                               This parameter can be a value of @ref WWDT_EWI_Mode */

} md_wwdt_inittypedef;
/**
  * @}
  */

/** @defgroup MD_WWDT_Public_Macros WWDT Public Macros
  * @{
  */

/**
  * @brief MD_WWDT_Prescaler WWDT Prescaler
  */
#define WWDT_PRESCALER_1                    0x00000000U    /*!< WWDT counter clock = (PCLK1/4096)/1 */
#define WWDT_PRESCALER_2                    0x00000001U    /*!< WWDT counter clock = (PCLK1/4096)/2, WWDT_CFG_WDGTB_POSS = 7 */
#define WWDT_PRESCALER_4                    0x00000002U    /*!< WWDT counter clock = (PCLK1/4096)/4, WWDT_CFG_WDGTB_POSS = 7 */
#define WWDT_PRESCALER_8                    0x00000003U    /*!< WWDT counter clock = (PCLK1/4096)/8, WWDT_CFG_WDGTB  = 3<<7 */

/**
  * @brief WWDT_EWI_Mode WWDT Early Wakeup Interrupt Mode
  */
#define WWDT_EWI_DISABLE                    0x00000000U    /*!< EWI Disable */
#define WWDT_EWI_ENABLE                     0x00000001U    /*!< EWI Enable, WWDT_CON_WDGA  = 1<<7 */

/**
  * @}
  */

/** @defgroup MD_WWDT_Public_Functions WWDT Public Functions
  * @{
  */

/** @defgroup MD_WWDT_Public_Functions_Group2 CON
  * @{
  */
/**
  * @brief  Set the WWDT_CON value
  * @note   A write of 0 in bit 7 has no effect.
  * @param  wwdt WWDT Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_wwdt_set_con(WWDT_TypeDef *wwdt, uint32_t Reg_Value)
{
    WRITE_REG(wwdt->CON, Reg_Value);
}

/**
  * @brief  Get the WWDT_CON value
  * @note   None.
  * @param  wwdt WWDT Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_wwdt_get_con(WWDT_TypeDef *wwdt)
{
    return (uint32_t)(READ_REG(wwdt->CON));
}

/**
  * @brief  WWDT WDGA Enable
  * @note   This bit is set by software and only cleared by hardware after a reset.
  *         A write of 0 has no effect. When WDGA=1, the watchdog can generate a reset.
  * @param  wwdt WWDT Instance
  * @retval None
  */
__STATIC_INLINE void md_wwdt_enable(WWDT_TypeDef *wwdt)
{
    SET_BIT(wwdt->CON, WWDT_CON_WDGA);
}

/**
  * @brief  Indicate if WWDT WDGA is enabled
  * @note   This bit is set by software and only cleared by hardware after a reset.
  *         A write of 0 has no effect. When WDGA=1, the watchdog can generate a reset.
  * @param  wwdt WWDT Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_wwdt_is_enabled(WWDT_TypeDef *wwdt)
{
    return (READ_BIT(wwdt->CON, WWDT_CON_WDGA) == (WWDT_CON_WDGA));
}

/**
  * @brief  Set WWDT T 7-bit counter
  * @note   These bits contain the value of the watchdog counter.
  *         It is decremented every (4096 x 2^WDGTB[1:0]) PCLK cycles.
  *         A reset is produced when it is decremented from 0x40 to 0x3F(T6 becomes cleared),
  *         and when it is renewed on the condition the value is more than the window value and the WDGA bit is enabled.
  * @param  wwdt WWDT Instance
  * @param  counter is a 7-bit number
  *         @arg Max Value 0x7F
  *         @arg Min Value 0x40
  * @retval None
  */
__STATIC_INLINE void md_wwdt_set_count_value(WWDT_TypeDef *wwdt, uint32_t counter)
{
    MODIFY_REG(wwdt->CON, WWDT_CON_T, counter);
}

/**
  * @brief  Get WWDT T 7-bit counter
  * @note   These bits contain the value of the watchdog counter.
  *         It is decremented every (4096 x 2^WDGTB[1:0]) PCLK cycles.
  *         A reset is produced when it is decremented from 0x40 to 0x3F(T6 becomes cleared),
  *         and when it is renewed on the condition the value is more than the window value and the WDGA bit is enabled.
  * @param  wwdt WWDT Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0x7F
  *         @arg Min Value 0x40
  */
__STATIC_INLINE uint32_t md_wwdt_get_count_value(WWDT_TypeDef *wwdt)
{
    return (uint32_t)(READ_BIT(wwdt->CON, WWDT_CON_T) >> WWDT_CON_T_POSS);
}
/**
  * @}
  */

/** @defgroup MD_WWDT_Public_Functions_Group3 CFG
  * @{
  */
/**
  * @brief  Set the WWDT_CFG value
  * @note   None.
  * @param  wwdt WWDT Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_wwdt_set_cfg(WWDT_TypeDef *wwdt, uint32_t Reg_Value)
{
    WRITE_REG(wwdt->CFG, Reg_Value);
}

/**
  * @brief  Get the WWDT_CFG value
  * @note   None.
  * @param  wwdt WWDT Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_wwdt_get_cfg(WWDT_TypeDef *wwdt)
{
    return (uint32_t)(READ_REG(wwdt->CFG));
}

/**
  * @brief  Set WWDT WDGTB 2-bit prescaler value
  * @note   The time base of the prescaler can be modified as follows:
  *         00: CK Counter Clock (PCLK div 4096) div 1
  *         01: CK Counter Clock (PCLK div 4096) div 2
  *         10: CK Counter Clock (PCLK div 4096) div 4
  *         11: CK Counter Clock (PCLK div 4096) div 8
  * @param  wwdt WWDT Instance
  * @param  prescaler is a 2-bit number
  *         @arg @ref WWDT_PRESCALER_1
  *         @arg @ref WWDT_PRESCALER_2
  *         @arg @ref WWDT_PRESCALER_4
  *         @arg @ref WWDT_PRESCALER_8
  * @retval None
  */
__STATIC_INLINE void md_wwdt_set_prescaler(WWDT_TypeDef *wwdt, uint32_t prescaler)
{
    MODIFY_REG(wwdt->CFG, WWDT_CFG_WDGTB, prescaler << WWDT_CFG_WDGTB_POSS);
}

/**
  * @brief  Get WWDT WDGTB 2-bit prescaler value
  * @note   The time base of the prescaler can be modified as follows:
            00: CK Counter Clock (PCLK div 4096) div 1
            01: CK Counter Clock (PCLK div 4096) div 2
            10: CK Counter Clock (PCLK div 4096) div 4
            11: CK Counter Clock (PCLK div 4096) div 8
  * @param  wwdt WWDT Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref WWDT_PRESCALER_1
  *         @arg @ref WWDT_PRESCALER_2
  *         @arg @ref WWDT_PRESCALER_4
  *         @arg @ref WWDT_PRESCALER_8
  */
__STATIC_INLINE uint32_t md_wwdt_get_prescaler(WWDT_TypeDef *wwdt)
{
    return (uint32_t)(READ_BIT(wwdt->CFG, WWDT_CFG_WDGTB) >> WWDT_CFG_WDGTB_POSS);
}

/**
  * @brief  Set WWDT W 7-bit window
  * @note   These bits contain the window value to be compared to the downcounter.
  * @param  wwdt WWDT Instance
  * @param  window is a 7-bit number
  *         @arg Max Value 0x7F
  *         @arg Min Value 0x40
  * @retval None
  */
__STATIC_INLINE void md_wwdt_set_window(WWDT_TypeDef *wwdt, uint32_t window)
{
    MODIFY_REG(wwdt->CFG, WWDT_CFG_W, window);
}

/**
  * @brief  Get WWDT W 7-bit window
  * @note   These bits contain the window value to be compared to the downcounter.
  * @param  wwdt WWDT Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0x7F
  *         @arg Min Value 0x40
  */
__STATIC_INLINE uint32_t md_wwdt_get_window(WWDT_TypeDef *wwdt)
{
    return (uint32_t)(READ_BIT(wwdt->CFG, WWDT_CFG_W) >> WWDT_CFG_W_POSS);
}
/**
  * @}
  */

/** @defgroup MD_WWDT_Public_Functions_Group4 IER
  * @{
  */
/**
  * @brief  Set WWDT IER Register
  * @param  wwdt WWDT Instance
  * @param  ier
  * @retval None
  */
__STATIC_INLINE void md_wwdt_set_ier(WWDT_TypeDef *wwdt, uint32_t ier)
{
    WRITE_REG(wwdt->IER, ier);
}

/**
  * @brief  WWDT Early wakeup interrupt Enable
  * @note   A write of 1 in IER to enable this interrupt.
  * @param  wwdt WWDT Instance
  * @retval None
  */
__STATIC_INLINE void md_wwdt_enable_it_ewi(WWDT_TypeDef *wwdt)
{
    SET_BIT(wwdt->IER, WWDT_IER_EWI);
}
/**
  * @}
  */

/** @defgroup MD_WWDT_Public_Functions_Group5 IDR
  * @{
  */
/**
  * @brief  Set WWDT IDR Register
  * @param  wwdt WWDT Instance
  * @param  idr
  * @retval None
  */
__STATIC_INLINE void md_wwdt_set_idr(WWDT_TypeDef *wwdt, uint32_t idr)
{
    WRITE_REG(wwdt->IDR, idr);
}

/**
  * @brief  WWDT Early wakeup interrupt Disable
  * @note   A write of 1 in IDR to disable this interrupt.
  * @param  wwdt WWDT Instance
  * @retval None
  */
__STATIC_INLINE void md_wwdt_disable_it_ewi(WWDT_TypeDef *wwdt)
{
    SET_BIT(wwdt->IDR, WWDT_IDR_EWI);
}
/**
  * @}
  */

/** @defgroup MD_WWDT_Public_Functions_Group6 IVS
  * @{
  */
/**
  * @brief  Get WWDT IVS Register
  * @param  wwdt WWDT Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_wwdt_get_ivs(WWDT_TypeDef *wwdt)
{
    return (uint32_t)(READ_REG(wwdt->IVS));
}

/**
  * @brief  Indicate if WWDT EWI is enabled
  * @note   To check EWI enable or not.
  * @param  wwdt WWDT Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_wwdt_is_enabled_it_ewi(WWDT_TypeDef *wwdt)
{
    return (READ_BIT(wwdt->IVS, WWDT_IVS_EWI) == (WWDT_IVS_EWI));
}
/**
  * @}
  */

/** @defgroup MD_WWDT_Public_Functions_Group7 RIF
  * @{
  */
/**
  * @brief  Get WWDT RIF Register
  * @param  wwdt WWDT Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_wwdt_get_rif(WWDT_TypeDef *wwdt)
{
    return (uint32_t)(READ_REG(wwdt->RIF));
}

/**
  * @brief  Get the early wakeup interrupt flag status
  * @note   This bit is set by hardware when the counter has reached the value 0x40.
            It can be cleared by software by writing 1 in WWDT_ICR. This bit is
            also set if the interrupt is not enabled.
  * @param  wwdt WWDT Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_wwdt_is_active_it_ewi(WWDT_TypeDef *wwdt)
{
    return (READ_BIT(wwdt->RIF, WWDT_RIF_EWI) == (WWDT_RIF_EWI));
}
/**
  * @}
  */

/** @defgroup MD_WWDT_Public_Functions_Group8 IFM
  * @{
  */
/**
  * @brief  Get WWDT IFM Register
  * @param  wwdt WWDT Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_wwdt_get_ifm(WWDT_TypeDef *wwdt)
{
    return (uint32_t)(READ_REG(wwdt->IFM));
}

/**
  * @brief  Get the early wakeup interrupt flag masked status
  * @note   This bit is set by hardware when the counter has reached the value 0x40
            and the interrupt is enabled.
  * @param  wwdt WWDT Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_wwdt_is_masked_it_ewi(WWDT_TypeDef *wwdt)
{
    return (READ_BIT(wwdt->IFM, WWDT_IFM_EWI) == (WWDT_IFM_EWI));
}
/**
  * @}
  */

/** @defgroup MD_WWDT_Public_Functions_Group9 ICR
  * @{
  */
/**
  * @brief  Set WWDT ICR Register
  * @param  wwdt WWDT Instance
  * @param  icr
  * @retval None
  */
__STATIC_INLINE void md_wwdt_set_icr(WWDT_TypeDef *wwdt, uint32_t icr)
{
    WRITE_REG(wwdt->ICR, icr);
}

/**
  * @brief  Clear the early wakeup interrupt flag
  * @param  wwdt WWDT Instance
  * @retval None
  */
__STATIC_INLINE void md_wwdt_clear_it_ewi(WWDT_TypeDef *wwdt)
{
    SET_BIT(wwdt->ICR, WWDT_ICR_EWI);
}
/**
  * @}
  */

/** @defgroup MD_WWDT_Public_Functions_Group1 Initialization
  * @{
  */
void md_wwdt_init(WWDT_TypeDef *wwdt, md_wwdt_inittypedef *WWDT_InitStruct);
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup MD_WWDT_Private_Macros WWDT Private Macros
  * @{
  */
#define IS_MD_WWDT_ALL_INSTANCE(__INSTANCE__) (__INSTANCE__ == WWDT)

#define IS_MD_WWDT_PRESCALER(__VALUE__)       (((__VALUE__) == WWDT_PRESCALER_1)   \
        ||  ((__VALUE__) == WWDT_PRESCALER_2)   \
        ||  ((__VALUE__) == WWDT_PRESCALER_4)   \
        ||  ((__VALUE__) == WWDT_PRESCALER_8))

#define IS_MD_WWDT_WINDOW(__VALUE__)          (((__VALUE__) >= 0x40) && ((__VALUE__) <= 0x7F))

#define IS_MD_WWDT_COUNTER(__VALUE__)         (((__VALUE__) >= 0x40) && ((__VALUE__) <= 0x7F))

#define IS_MD_WWDT_EWI_MODE(__VALUE__)        (((__VALUE__) == WWDT_EWI_ENABLE)    \
        ||  ((__VALUE__) == WWDT_EWI_DISABLE))
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
