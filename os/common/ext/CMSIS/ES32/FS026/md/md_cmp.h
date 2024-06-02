/**********************************************************************************
 *
 * @file    md_cmp.h
 * @brief   header file of md_cmp.c
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov  2021    Ginger          the first version
 *          24 Mar  2022    AE Team         Modify MD Driver
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
#ifndef __MD_CMP_H__
#define __MD_CMP_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_CMP CMP
  * @brief CMP micro driver
  * @{
  */


/** @defgroup MD_CMP_Public_Macros CMP Public Macros
  * @{
  */
#define MD_CMP_CFG1_LOCK_READ_WRITE              (0x00000000UL)       /*!< @brief CMP_CFG1[31:0] bits can be read and written normally        */
#define MD_CMP_CFG1_LOCK_ONLY_READ               (0x00000001UL)       /*!< @brief The CMP_CFG1[31:0] bits are for read operations only.        */

#define MD_CMP_CFG1_VALUE_OUTPUT_LOW_LEVEL       (0x00000000UL)       /*!< @brief CMP output is low level.        */
#define MD_CMP_CFG1_VALUE_OUTPUT_HIGH_LEVEL      (0x00000001UL)       /*!< @brief CMP output is high level.        */

#define MD_CMP_CFG1_BLANKSEL_CLOSE               (0x00000000UL)       /*!< @brief 00000:Close        */
#define MD_CMP_CFG1_BLANKSEL_AD16C4T1_OC4        (0x00000001UL)       /*!< @brief xxxx1:AD16C4T1_OC4 */
#define MD_CMP_CFG1_BLANKSEL_GP32C4T1_OC4        (0x00000002UL)       /*!< @brief xxx1x:GP32C4T1_OC4 */
#define MD_CMP_CFG1_BLANKSEL_GP16C4T1_OC4        (0x00000004UL)       /*!< @brief xx1xx:GP16C4T1_OC4 */
#define MD_CMP_CFG1_BLANKSEL_GP16C4T2_OC4        (0x00000008UL)       /*!< @brief x1xxx:GP16C4T2_OC4 */
#define MD_CMP_CFG1_BLANKSEL_GP16C2T1_OC2        (0x00000010UL)       /*!< @brief 1xxxx:GP16C2T1_OC2 */

#define MD_CMP_CFG1_POLARITY_NO_INVERTED         (0x00000000UL)       /*!< @brief The output is not inverted.*/
#define MD_CMP_CFG1_POLARITY_INVERTED            (0x00000001UL)       /*!< @brief The output is inverted.        */

#define MD_CMP_CFG1_OUTSEL_NO                    (0x00000000UL)       /*!< @brief 000:NO            */
#define MD_CMP_CFG1_OUTSEL_AD16C4T1_BKIN         (0x00000001UL)       /*!< @brief 001:AD16C4T1_BKIN */
#define MD_CMP_CFG1_OUTSEL_GP16C2T1_BKIN         (0x00000002UL)       /*!< @brief 010:GP16C4T1_BKIN */
#define MD_CMP_CFG1_OUTSEL_GP16C2T2_BKIN         (0x00000003UL)       /*!< @brief 011:GP16C4T2_BKIN */
#define MD_CMP_CFG1_OUTSEL_GP16C2T3_BKIN         (0x00000004UL)       /*!< @brief 100:GP16C4T3_BKIN */
#define MD_CMP_CFG1_OUTSEL_GP16C2T4_BKIN         (0x00000005UL)       /*!< @brief 101:GP16C4T4_BKIN */

#define MD_CMP_CFG1_INNSEL_1DIV4_Vres            (0x00000000UL)       /*!< @brief 000:1/4 Vres     */
#define MD_CMP_CFG1_INNSEL_1DIV2_Vres            (0x00000001UL)       /*!< @brief 001:1/2 Vres     */
#define MD_CMP_CFG1_INNSEL_3DIV4_Vres            (0x00000002UL)       /*!< @brief 010:3/4 Vres     */
#define MD_CMP_CFG1_INNSEL_Vres                  (0x00000003UL)       /*!< @brief 011:Vres_src     */
#define MD_CMP_CFG1_INNSEL_PA04                  (0x00000004UL)       /*!< @brief 100:PA04         */
#define MD_CMP_CFG1_INNSEL_PA05                  (0x00000005UL)       /*!< @brief 101:PA05         */
#define MD_CMP_CFG1_INNSEL_PA00                  (0x00000006UL)       /*!< @brief 110:PA00         */

#define MD_CMP_CFG2_LOCK_READ_WRITE              (0x00000000UL)       /*!< @brief CMP_CFG2[31:0] bits can be read and written normally        */
#define MD_CMP_CFG2_LOCK_ONLY_READ               (0x00000001UL)       /*!< @brief The CMP_CFG2[31:0] bits are for read operations only.        */

#define MD_CMP_CFG2_VALUE_OUTPUT_LOW_LEVEL       (0x00000000UL)       /*!< @brief CMP output is low level.        */
#define MD_CMP_CFG2_VALUE_OUTPUT_HIGH_LEVEL      (0x00000001UL)       /*!< @brief CMP output is high level.        */

#define MD_CMP_CFG2_BLANKSEL_CLOSE               (0x00000000UL)       /*!< @brief 00000:Close        */
#define MD_CMP_CFG2_BLANKSEL_AD16C4T1_OC4        (0x00000001UL)       /*!< @brief xxxx1:AD16C4T1_OC4 */
#define MD_CMP_CFG2_BLANKSEL_GP32C4T1_OC4        (0x00000002UL)       /*!< @brief xxx1x:GP32C4T1_OC4 */
#define MD_CMP_CFG2_BLANKSEL_GP16C4T1_OC4        (0x00000004UL)       /*!< @brief xx1xx:GP16C4T1_OC4 */
#define MD_CMP_CFG2_BLANKSEL_GP16C4T2_OC4        (0x00000008UL)       /*!< @brief x1xxx:GP16C4T2_OC4 */
#define MD_CMP_CFG2_BLANKSEL_GP16C2T1_OC2        (0x00000010UL)       /*!< @brief 1xxxx:GP16C2T1_OC2 */

#define MD_CMP_CFG2_POLARITY_NO_INVERTED         (0x00000000UL)       /*!< @brief The output is not inverted.*/
#define MD_CMP_CFG2_POLARITY_INVERTED            (0x00000001UL)       /*!< @brief The output is inverted.        */

#define MD_CMP_CFG2_OUTSEL_NO                    (0x00000000UL)       /*!< @brief 000:NO            */
#define MD_CMP_CFG2_OUTSEL_AD16C4T1_BKIN         (0x00000001UL)       /*!< @brief 001:AD16C4T1_BKIN */
#define MD_CMP_CFG2_OUTSEL_GP16C2T1_BKIN         (0x00000002UL)       /*!< @brief 010:GP16C4T1_BKIN */
#define MD_CMP_CFG2_OUTSEL_GP16C2T2_BKIN         (0x00000003UL)       /*!< @brief 011:GP16C4T2_BKIN */
#define MD_CMP_CFG2_OUTSEL_GP16C2T3_BKIN         (0x00000004UL)       /*!< @brief 100:GP16C4T3_BKIN */
#define MD_CMP_CFG2_OUTSEL_GP16C2T4_BKIN         (0x00000005UL)       /*!< @brief 101:GP16C4T4_BKIN */

#define MD_CMP_CFG2_INNSEL_1DIV4_Vres            (0x00000000UL)       /*!< @brief 000:1/4 Vres     */
#define MD_CMP_CFG2_INNSEL_1DIV2_Vres            (0x00000001UL)       /*!< @brief 001:1/2 Vres     */
#define MD_CMP_CFG2_INNSEL_3DIV4_Vres            (0x00000002UL)       /*!< @brief 010:3/4 Vres     */
#define MD_CMP_CFG2_INNSEL_Vres                  (0x00000003UL)       /*!< @brief 011:Vres_src     */
#define MD_CMP_CFG2_INNSEL_PA04                  (0x00000004UL)       /*!< @brief 100:PA04         */
#define MD_CMP_CFG2_INNSEL_PA05                  (0x00000005UL)       /*!< @brief 101:PA05         */
#define MD_CMP_CFG2_INNSEL_PA02                  (0x00000006UL)       /*!< @brief 110:PA02         */

/**
  * @}
  */

/** @defgroup MD_CMP_Public_Functions CMP Public Functions
  * @{
  */

/** @defgroup MD_CMP_Public_Functions_Group2 CFG1
  * @{
  */
/**
  * @brief  Set CMP control register (CMP_CFG1)
  * @param  cmp CMP Instance
  * @param  value The value write in CMP_CFG1
  * @retval None
  */
__STATIC_INLINE void md_cmp_set_cfg1(CMP_TypeDef *cmp, uint32_t value)
{
    WRITE_REG(cmp->CFG1, value);
}

/**
  * @brief  Get CMP control register (CMP_CFG1)
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_cmp_get_cfg1(CMP_TypeDef *cmp)
{
    return (uint32_t)(READ_REG(cmp->CFG1));
}

/**
  * @brief  Comparator 1 locked W/R
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp1_enable_lock(CMP_TypeDef *cmp)
{
    SET_BIT(cmp->CFG1, CMP_CFG1_LOCK);
}

/**
  * @brief  Get Comparator 1 locked
  * @param  cmp CMP Instance
  * @retval The retval can be a value of the value:
            @arg @ref MD_CMP_CFG1_LOCK_READ_WRITE
            @arg @ref MD_CMP_CFG1_LOCK_ONLY_READ
  */
__STATIC_INLINE uint32_t md_cmp1_is_enabled_lock(CMP_TypeDef *cmp)
{
    return (READ_BIT(cmp->CFG1, CMP_CFG1_LOCK) == (CMP_CFG1_LOCK));
}

/**
  * @brief  Get Comparator 1 output
  * @param  cmp CMP Instance
  * @retval The retval can be a value of the value:
            @arg @ref MD_CMP_CFG1_VALUE_OUTPUT_LOW_LEVEL
            @arg @ref MD_CMP_CFG1_VALUE_OUTPUT_HIGH_LEVEL
  */
__STATIC_INLINE uint32_t md_cmp1_get_output_level(CMP_TypeDef *cmp)
{
    return (uint32_t)(READ_BIT(cmp->CFG1, CMP_CFG1_VALUE) >> CMP_CFG1_VALUE_POS);
}

/**
  * @brief  Set Comparator 1 masking function
  * @param  cmp CMP Instance
  * @param  blanksel This parameter can be one of the following values:
  *         @arg MD_CMP_CFG1_BLANKSEL_CLOSE
  *         @arg MD_CMP_CFG1_BLANKSEL_AD16C4T1_OC4
  *         @arg MD_CMP_CFG1_BLANKSEL_GP32C4T1_OC4
  *         @arg MD_CMP_CFG1_BLANKSEL_GP16C4T1_OC4
  *         @arg MD_CMP_CFG1_BLANKSEL_GP16C4T2_OC4
  *         @arg MD_CMP_CFG1_BLANKSEL_GP16C2T1_OC2
  * @retval None
  */
__STATIC_INLINE void md_cmp1_set_blanking_source(CMP_TypeDef *cmp, uint32_t blanksel)
{
    MODIFY_REG(cmp->CFG1, CMP_CFG1_BLANKSEL, blanksel << CMP_CFG1_BLANKSEL_POSS);
}

/**
  * @brief  Return Comparator 1 masking function
  * @param  cmp CMP Instance
  * @retval The retval can be a value of the value:
  *         @arg MD_CMP_CFG1_BLANKSEL_CLOSE
  *         @arg MD_CMP_CFG1_BLANKSEL_AD16C4T1_OC4
  *         @arg MD_CMP_CFG1_BLANKSEL_GP32C4T1_OC4
  *         @arg MD_CMP_CFG1_BLANKSEL_GP16C4T1_OC4
  *         @arg MD_CMP_CFG1_BLANKSEL_GP16C4T2_OC4
  *         @arg MD_CMP_CFG1_BLANKSEL_GP16C2T1_OC2
  */
__STATIC_INLINE uint32_t md_cmp1_get_blanking_source(CMP_TypeDef *cmp)
{
    return (uint32_t)(READ_BIT(cmp->CFG1, CMP_CFG1_BLANKSEL) >> CMP_CFG1_BLANKSEL_POSS);
}

/**
  * @brief  Enable Comparator 1 filter function
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp1_enable_filter(CMP_TypeDef *cmp)
{
    SET_BIT(cmp->CFG1, CMP_CFG1_FILT);
}
/**
  * @brief  Disable Comparator 1 filter function
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp1_disable_filter(CMP_TypeDef *cmp)
{
    CLEAR_BIT(cmp->CFG1, CMP_CFG1_FILT);
}

/**
  * @brief  Check if Comparator 1 filter function select is enable
  * @param  cmp CMP Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_cmp1_is_enabled_filter(CMP_TypeDef *cmp)
{
    return (READ_BIT(cmp->CFG1, CMP_CFG1_FILT) == (CMP_CFG1_FILT));
}

/**
  * @brief  Enable Comparator 1 hysteresis function
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp1_enable_hysteresis(CMP_TypeDef *cmp)
{
    SET_BIT(cmp->CFG1, CMP_CFG1_HYST);
}
/**
  * @brief  Disable Comparator 1 hysteresis function
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp1_disable_hysteresis(CMP_TypeDef *cmp)
{
    CLEAR_BIT(cmp->CFG1, CMP_CFG1_HYST);
}

/**
  * @brief  Check if Comparator 1 hysteresis function
  * @param  cmp CMP Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_cmp1_is_enabled_hysteresis(CMP_TypeDef *cmp)
{
    return (READ_BIT(cmp->CFG1, CMP_CFG1_HYST) == (CMP_CFG1_HYST));
}

/**
  * @brief  Enable Comparator 1 output polarity
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp1_enable_polarity(CMP_TypeDef *cmp)
{
    SET_BIT(cmp->CFG1, CMP_CFG1_POLARITY);
}

/**
  * @brief  Disable Comparator 1 output polarity
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp1_disable_polarity(CMP_TypeDef *cmp)
{
    CLEAR_BIT(cmp->CFG1, CMP_CFG1_POLARITY);
}

/**
  * @brief  Check if Comparator 1 output polarity
  * @param  cmp CMP Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_cmp1_is_enabled_polarity(CMP_TypeDef *cmp)
{
    return (READ_BIT(cmp->CFG1, CMP_CFG1_POLARITY) == (CMP_CFG1_POLARITY));
}

/**
  * @brief  Set Comparator 1 output trigger selection
  * @param  cmp CMP Instance
  * @param  outsel
  * @param  outsel This parameter can be one of the following values:
  *         @arg MD_CMP_OUTSEL_NO
  *         @arg MD_CMP_CFG1_OUTSEL_AD16C4T1_BKIN
  *         @arg MD_CMP_CFG1_OUTSEL_GP16C4T1_BKIN
  *         @arg MD_CMP_CFG1_OUTSEL_GP16C4T2_BKIN
  *         @arg MD_CMP_CFG1_OUTSEL_GP16C4T3_BKIN
  *         @arg MD_CMP_CFG1_OUTSEL_GP16C4T4_BKIN
  * @retval None
  */
__STATIC_INLINE void md_cmp1_set_output_trigger_select(CMP_TypeDef *cmp, uint32_t outsel)
{
    MODIFY_REG(cmp->CFG1, CMP_CFG1_OUTSEL, outsel << CMP_CFG1_OUTSEL_POSS);
}

/**
  * @brief  Return Comparator 1 output trigger selection
  * @param  cmp CMP Instance
  * @retval The retval can be a value of the value:
  *         @arg MD_CMP_OUTSEL_NO
  *         @arg MD_CMP_CFG1_OUTSEL_AD16C4T1_BKIN
  *         @arg MD_CMP_CFG1_OUTSEL_GP16C4T1_BKIN
  *         @arg MD_CMP_CFG1_OUTSEL_GP16C4T2_BKIN
  *         @arg MD_CMP_CFG1_OUTSEL_GP16C4T3_BKIN
  *         @arg MD_CMP_CFG1_OUTSEL_GP16C4T4_BKIN
  */
__STATIC_INLINE uint32_t md_cmp1_get_output_trigger_select(CMP_TypeDef *cmp)
{
    return (uint32_t)(READ_BIT(cmp->CFG1, CMP_CFG1_OUTSEL) >> CMP_CFG1_OUTSEL_POSS);
}

/**
  * @brief  Set Comparator 1 negative input selection
  * @param  cmp CMP Instance
  * @param  innsel This parameter can be one of the following values:
  *         @arg MD_CMP_CFG1_INNSEL_1DIV4_Vres
  *         @arg MD_CMP_CFG1_INNSEL_1DIV2_Vres
  *         @arg MD_CMP_CFG1_INNSEL_3DIV4_Vres
  *         @arg MD_CMP_CFG1_INNSEL_Vres      
  *         @arg MD_CMP_CFG1_INNSEL_PA04      
  *         @arg MD_CMP_CFG1_INNSEL_PA05      
  *         @arg MD_CMP_CFG1_INNSEL_PA00      
  * @retval None
  */
__STATIC_INLINE void md_cmp1_set_input_negative_select(CMP_TypeDef *cmp, uint32_t innsel)
{
    MODIFY_REG(cmp->CFG1, CMP_CFG1_INNSEL, innsel << CMP_CFG1_INNSEL_POSS);
}

/**
  * @brief  Return Comparator 1 negative input selection
  * @param  cmp CMP Instance
  * @retval The retval can be a value of the value:
  *         @arg MD_CMP_CFG1_INNSEL_1DIV4_Vres
  *         @arg MD_CMP_CFG1_INNSEL_1DIV2_Vres
  *         @arg MD_CMP_CFG1_INNSEL_3DIV4_Vres
  *         @arg MD_CMP_CFG1_INNSEL_Vres      
  *         @arg MD_CMP_CFG1_INNSEL_PA04      
  *         @arg MD_CMP_CFG1_INNSEL_PA05      
  *         @arg MD_CMP_CFG1_INNSEL_PA00      
  */
__STATIC_INLINE uint32_t md_cmp1_get_input_negative_select(CMP_TypeDef *cmp)
{
    return (uint32_t)(READ_BIT(cmp->CFG1, CMP_CFG1_INNSEL) >> CMP_CFG1_INNSEL_POSS);
}

/**
  * @brief  Enable Comparator 1 switch
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp1_enable(CMP_TypeDef *cmp)
{
    SET_BIT(cmp->CFG1, CMP_CFG1_EN);
}
/**
  * @brief  Disable Comparator 1 switch
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp1_disable(CMP_TypeDef *cmp)
{
    CLEAR_BIT(cmp->CFG1, CMP_CFG1_EN);
}

/**
  * @brief  Get Comparator 1 switch
  * @param  cmp CMP Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_cmp1_is_enabled(CMP_TypeDef *cmp)
{
    return (READ_BIT(cmp->CFG1, CMP_CFG1_EN) == (CMP_CFG1_EN));
}
/**
  * @}
  */

/** @defgroup MD_CMP_Public_Functions_Group3 CFG2
  * @{
  */
/**
  * @brief  Set CMP control register (CMP_CFG2)
  * @param  cmp CMP Instance
  * @param  value The value write in CMP_CFG2
  * @retval None
  */
__STATIC_INLINE void md_cmp_set_cfg2(CMP_TypeDef *cmp, uint32_t value)
{
    WRITE_REG(cmp->CFG2, value);
}

/**
  * @brief  Get CMP control register (CMP_CFG1)
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_cmp_get_cfg2(CMP_TypeDef *cmp)
{
    return (uint32_t)(READ_REG(cmp->CFG2));
}

/**
  * @brief  Comparator 2 locked W/R
  * @param  cmp CMP Instance
  * @param  lock
            @arg @ref MD_CMP_CFG2_LOCK_READ_WRITE
            @arg @ref MD_CMP_CFG2_LOCK_ONLY_READ
  * @retval None
  */
__STATIC_INLINE void md_cmp2_enable_lock(CMP_TypeDef *cmp)
{
    SET_BIT(cmp->CFG1, CMP_CFG2_LOCK);
}

/**
  * @brief  Get Comparator 2 locked
  * @param  cmp CMP Instance
  * @retval The retval can be a value of the value:
            @arg @ref MD_CMP_CFG2_LOCK_READ_WRITE
            @arg @ref MD_CMP_CFG2_LOCK_ONLY_READ
  */
__STATIC_INLINE uint32_t md_cmp2_is_enabled_lock(CMP_TypeDef *cmp)
{
    return (READ_BIT(cmp->CFG2, CMP_CFG2_LOCK) == (CMP_CFG2_LOCK));
}

/**
  * @brief  Get Comparator 2 output
  * @param  cmp CMP Instance
  * @retval The retval can be a value of the value:
            @arg @ref MD_CMP_CFG2_VALUE_OUTPUT_LOW_LEVEL
            @arg @ref MD_CMP_CFG2_VALUE_OUTPUT_HIGH_LEVEL
  */
__STATIC_INLINE uint32_t md_cmp2_get_output_level(CMP_TypeDef *cmp)
{
    return (uint32_t)(READ_BIT(cmp->CFG2, CMP_CFG2_VALUE) >> CMP_CFG2_VALUE_POS);
}

/**
  * @brief  Set Comparator 2 masking function
  * @param  cmp CMP Instance
  * @param  blanksel This parameter can be one of the following values:
  *         @arg MD_CMP_CFG2_BLANKSEL_CLOSE
  *         @arg MD_CMP_CFG2_BLANKSEL_AD16C4T1_OC4
  *         @arg MD_CMP_CFG2_BLANKSEL_GP32C4T1_OC4
  *         @arg MD_CMP_CFG2_BLANKSEL_GP16C4T1_OC4
  *         @arg MD_CMP_CFG2_BLANKSEL_GP16C4T2_OC4
  *         @arg MD_CMP_CFG2_BLANKSEL_GP16C2T1_OC2
  * @retval None
  */
__STATIC_INLINE void md_cmp2_set_blanking_source(CMP_TypeDef *cmp, uint32_t blanksel)
{
    MODIFY_REG(cmp->CFG2, CMP_CFG2_BLANKSEL, blanksel << CMP_CFG2_BLANKSEL_POSS);
}

/**
  * @brief  Return Comparator 2 masking function
  * @param  cmp CMP Instance
  * @retval None
  *         @arg MD_CMP_CFG2_BLANKSEL_CLOSE
  *         @arg MD_CMP_CFG2_BLANKSEL_AD16C4T1_OC4
  *         @arg MD_CMP_CFG2_BLANKSEL_GP32C4T1_OC4
  *         @arg MD_CMP_CFG2_BLANKSEL_GP16C4T1_OC4
  *         @arg MD_CMP_CFG2_BLANKSEL_GP16C4T2_OC4
  *         @arg MD_CMP_CFG2_BLANKSEL_GP16C2T1_OC2
  */
__STATIC_INLINE uint32_t md_cmp2_get_blanking_source(CMP_TypeDef *cmp)
{
    return (uint32_t)(READ_BIT(cmp->CFG2, CMP_CFG2_BLANKSEL) >> CMP_CFG2_BLANKSEL_POSS);
}

/**
  * @brief  Enable Comparator 2 filter function
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp2_enable_filter(CMP_TypeDef *cmp)
{
    SET_BIT(cmp->CFG2, CMP_CFG2_FILT);
}
/**
  * @brief  Disable Comparator 2 filter function
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp2_disable_filter(CMP_TypeDef *cmp)
{
    CLEAR_BIT(cmp->CFG2, CMP_CFG2_FILT);
}

/**
  * @brief  Check if Comparator 2 filter function select is enable
  * @param  cmp CMP Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_cmp2_is_enabled_filter(CMP_TypeDef *cmp)
{
    return (READ_BIT(cmp->CFG2, CMP_CFG2_FILT) == (CMP_CFG2_FILT));
}

/**
  * @brief  Enable Comparator 2 hysteresis function
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp2_enable_hysteresis(CMP_TypeDef *cmp)
{
    SET_BIT(cmp->CFG2, CMP_CFG2_HYST);
}
/**
  * @brief  Disable Comparator 2 hysteresis function
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp2_disable_hysteresis(CMP_TypeDef *cmp)
{
    CLEAR_BIT(cmp->CFG2, CMP_CFG2_HYST);
}

/**
  * @brief  Check if Comparator 2 hysteresis function
  * @param  cmp CMP Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_cmp2_is_enabled_hysteresis(CMP_TypeDef *cmp)
{
    return (READ_BIT(cmp->CFG2, CMP_CFG2_HYST) == (CMP_CFG2_HYST));
}

/**
  * @brief  Enable Comparator 2 output polarity
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp2_enable_polarity(CMP_TypeDef *cmp)
{
    SET_BIT(cmp->CFG2, CMP_CFG2_POLARITY);
}

/**
  * @brief  Disable Comparator 2 output polarity
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp2_disable_polarity(CMP_TypeDef *cmp)
{
    CLEAR_BIT(cmp->CFG2, CMP_CFG2_POLARITY);
}

/**
  * @brief  Check if Comparator 2 output polarity
  * @param  cmp CMP Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_cmp2_is_enabled_polarity(CMP_TypeDef *cmp)
{
    return (READ_BIT(cmp->CFG2, CMP_CFG2_POLARITY) == (CMP_CFG2_POLARITY));
}

/**
  * @brief  Set Comparator 2 output trigger selection
  * @param  cmp CMP Instance
  * @param  outsel This parameter can be one of the following values:
  *         @arg MD_CMP_CFG2_OUTSEL_NO
  *         @arg MD_CMP_CFG2_OUTSEL_AD16C4T1_BKIN
  *         @arg MD_CMP_CFG2_OUTSEL_GP16C4T1_BKIN
  *         @arg MD_CMP_CFG2_OUTSEL_GP16C4T2_BKIN
  *         @arg MD_CMP_CFG2_OUTSEL_GP16C4T3_BKIN
  *         @arg MD_CMP_CFG2_OUTSEL_GP16C4T4_BKIN
  * @retval None
  */
__STATIC_INLINE void md_cmp2_set_output_trigger_select(CMP_TypeDef *cmp, uint32_t outsel)
{
    MODIFY_REG(cmp->CFG2, CMP_CFG2_OUTSEL, outsel << CMP_CFG2_OUTSEL_POSS);
}

/**
  * @brief  Return Comparator 2 output trigger selection
  * @param  cmp CMP Instance
  * @retval The retval can be one of the following values:
  *         @arg MD_CMP_CFG2_OUTSEL_NO
  *         @arg MD_CMP_CFG2_OUTSEL_AD16C4T1_BKIN
  *         @arg MD_CMP_CFG2_OUTSEL_GP16C4T1_BKIN
  *         @arg MD_CMP_CFG2_OUTSEL_GP16C4T2_BKIN
  *         @arg MD_CMP_CFG2_OUTSEL_GP16C4T3_BKIN
  *         @arg MD_CMP_CFG2_OUTSEL_GP16C4T4_BKIN
  */
__STATIC_INLINE uint32_t md_cmp2_get_output_trigger_select(CMP_TypeDef *cmp)
{
    return (uint32_t)(READ_BIT(cmp->CFG2, CMP_CFG2_OUTSEL) >> CMP_CFG2_OUTSEL_POSS);
}

/**
  * @brief  Enable Comparator 2 window output mode
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp_enable_window_out(CMP_TypeDef *cmp)
{
    SET_BIT(cmp->CFG2, CMP_CFG2_WINOUT);
}
/**
  * @brief  Disable Comparator 2 window output mode
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp_disable_window_out(CMP_TypeDef *cmp)
{
    CLEAR_BIT(cmp->CFG2, CMP_CFG2_WINOUT);
}

/**
  * @brief  Get Comparator 2 window output mode
  * @param  cmp CMP Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_cmp_is_enabled_window_out(CMP_TypeDef *cmp)
{
    return (READ_BIT(cmp->CFG2, CMP_CFG2_WINOUT) == (CMP_CFG2_WINOUT));
}

/**
  * @brief  Enable Comparator 2 window monitor mode
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp_enable_window_mode(CMP_TypeDef *cmp)
{
    SET_BIT(cmp->CFG2, CMP_CFG2_WINMODE);
}
/**
  * @brief  Disable Comparator 2 window monitor mode
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp_disable_window_mode(CMP_TypeDef *cmp)
{
    CLEAR_BIT(cmp->CFG2, CMP_CFG2_WINMODE);
}

/**
  * @brief  Get Comparator 2 window monitor mode
  * @param  cmp CMP Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_cmp_is_enabled_window_mode(CMP_TypeDef *cmp)
{
    return (READ_BIT(cmp->CFG2, CMP_CFG2_WINMODE) == (CMP_CFG2_WINMODE));
}

/**
  * @brief  Set Comparator 2 negative input selection
  * @param  cmp CMP Instance
  * @param  blanksel This parameter can be one of the following values:
  *         @arg MD_CMP_CFG2_INNSEL_1DIV4_Vres
  *         @arg MD_CMP_CFG2_INNSEL_1DIV2_Vres
  *         @arg MD_CMP_CFG2_INNSEL_3DIV4_Vres
  *         @arg MD_CMP_CFG2_INNSEL_Vres      
  *         @arg MD_CMP_CFG2_INNSEL_PA04      
  *         @arg MD_CMP_CFG2_INNSEL_PA05      
  *         @arg MD_CMP_CFG2_INNSEL_PA02      
  * @retval None
  */
__STATIC_INLINE void md_cmp2_set_input_negative_select(CMP_TypeDef *cmp, uint32_t innsel)
{
    MODIFY_REG(cmp->CFG2, CMP_CFG2_INNSEL, innsel << CMP_CFG2_INNSEL_POSS);
}

/**
  * @brief  Return Comparator 2 negative input selection
  * @param  cmp CMP Instance
  * @retval The retval can be one of the following values:
  *         @arg MD_CMP_CFG2_INNSEL_1DIV4_Vres
  *         @arg MD_CMP_CFG2_INNSEL_1DIV2_Vres
  *         @arg MD_CMP_CFG2_INNSEL_3DIV4_Vres
  *         @arg MD_CMP_CFG2_INNSEL_Vres      
  *         @arg MD_CMP_CFG2_INNSEL_PA04      
  *         @arg MD_CMP_CFG2_INNSEL_PA05      
  *         @arg MD_CMP_CFG2_INNSEL_PA02      
  */
__STATIC_INLINE uint32_t md_cmp2_get_input_negative_select(CMP_TypeDef *cmp)
{
    return (uint32_t)(READ_BIT(cmp->CFG2, CMP_CFG2_INNSEL) >> CMP_CFG2_INNSEL_POSS);
}

/**
  * @brief  Enable Comparator 2 switch
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp2_enable(CMP_TypeDef *cmp)
{
    SET_BIT(cmp->CFG2, CMP_CFG2_EN);
}
/**
  * @brief  Disable Comparator 2 switch
  * @param  cmp CMP Instance
  * @retval None
  */
__STATIC_INLINE void md_cmp2_disable(CMP_TypeDef *cmp)
{
    CLEAR_BIT(cmp->CFG2, CMP_CFG2_EN);
}

/**
  * @brief  Get Comparator 2 switch
  * @param  cmp CMP Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_cmp2_is_enabled(CMP_TypeDef *cmp)
{
    return (READ_BIT(cmp->CFG2, CMP_CFG2_EN) == (CMP_CFG2_EN));
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
