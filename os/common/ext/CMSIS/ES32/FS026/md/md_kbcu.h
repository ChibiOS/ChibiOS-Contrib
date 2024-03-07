/**********************************************************************************
 *
 * @file    md_kbcu.h
 * @brief   header file of md_kbcu.c
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov 2021     Ginger          the first version
 *          23 Mar 2022     AE Team         Modify MD Driver
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
#ifndef __MD_KBCU_H__
#define __MD_KBCU_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_KBCU KBCU
  * @brief KBCU micro driver
  * @{
  */

/** @defgroup MD_KBCU_Public_Macros KBCU Public Macros
  * @{
  */


/**
  * @brief MD_KBCU_CON1_COL_CTRL Column Control
  */
#define MD_KBCU_CON1_COL_CTRL_DEF_H                     0x00000000U                           /*!< Column Default Output High. Output Low when enabled. */
#define MD_KBCU_CON1_COL_CTRL_DEF_L                     KBCU_CON1_COL_CTRL                 /*!< Column Default Output Low. Output High when enabled. */

/**
  * @brief MD_KBCU_CON1_LED_CTRL LED Control
  */
#define MD_KBCU_CON1_LED_CTRL_DEF_L                     0x00000000U                           /*!< PWM Default Output Low. Output High to Drive LED. */
#define MD_KBCU_CON1_LED_CTRL_DEF_H                     KBCU_CON1_LED_CTRL                 /*!< PWM Default Output High. Output Low to Drive LED. */

/**
  * @brief MD_KBCU_CON1_KEY_CTRL KEY Control
  */
#define MD_KBCU_CON1_KEY_CTRL_DETECT_L                  0x00000000U                           /*!< Key Detect when Input Low. */
#define MD_KBCU_CON1_KEY_CTRL_DETECT_H                  KBCU_CON1_KEY_CTRL                 /*!< Key Detect when Input High. */

/**
  * @brief MD_KBCU_CON1_COLUMN_SEL Number of Column
  */
#define MD_KBCU_CON1_COLUMN_SEL_15                      (0U)                /*!< 15 columns*/
#define MD_KBCU_CON1_COLUMN_SEL_16                      (1U)                /*!< 16 columns*/
#define MD_KBCU_CON1_COLUMN_SEL_17                      (2U)                /*!< 17 columns*/
#define MD_KBCU_CON1_COLUMN_SEL_18                      (3U)                /*!< 18 columns*/
#define MD_KBCU_CON1_COLUMN_SEL_19                      (4U)                /*!< 19 columns*/
#define MD_KBCU_CON1_COLUMN_SEL_20                      (5U)                /*!< 20 columns*/
#define MD_KBCU_CON1_COLUMN_SEL_21                      (6U)                /*!< 21 columns*/
#define MD_KBCU_CON1_COLUMN_SEL_22                      (7U)                /*!< 22 columns*/
#define MD_KBCU_CON1_COLUMN_SEL_23                      (8U)                /*!< 23 columns*/
#define MD_KBCU_CON1_COLUMN_SEL_24                      (9U)                /*!< 24 columns*/

/**
  * @brief MD_KBCU_CON2_COLVALUE Number of Cycle in one Column
  */
#define MD_KBCU_CON2_COLVALUE_1                      (0U )               /*!< 1 cycle in one column*/
#define MD_KBCU_CON2_COLVALUE_2                      (1U )               /*!< 2 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_3                      (2U )               /*!< 3 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_4                      (3U )               /*!< 4 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_5                      (4U )               /*!< 5 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_6                      (5U )               /*!< 6 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_7                      (6U )               /*!< 7 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_8                      (7U )               /*!< 8 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_9                      (8U )               /*!< 9 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_10                     (9U )               /*!< 10 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_11                     (10U)               /*!< 11 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_12                     (11U)               /*!< 12 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_13                     (12U)               /*!< 13 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_14                     (13U)               /*!< 14 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_15                     (14U)               /*!< 15 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_16                     (15U)               /*!< 16 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_17                     (16U)               /*!< 17 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_18                     (17U)               /*!< 18 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_19                     (18U)               /*!< 19 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_20                     (19U)               /*!< 20 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_21                     (20U)               /*!< 21 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_22                     (21U)               /*!< 22 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_23                     (22U)               /*!< 23 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_24                     (23U)               /*!< 24 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_25                     (24U)               /*!< 25 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_26                     (25U)               /*!< 26 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_27                     (26U)               /*!< 27 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_28                     (27U)               /*!< 28 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_29                     (28U)               /*!< 29 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_30                     (29U)               /*!< 30 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_31                     (30U)               /*!< 31 cycles in one column*/
#define MD_KBCU_CON2_COLVALUE_32                     (31U)               /*!< 32 cycles in one column*/

/**
  * @brief MD_KBCU_CON2_DTVALUE Dead Time Value
  */
#define MD_KBCU_CON2_DTVALUE_NONE                    (0U)                /*!< None Dead Time*/
#define MD_KBCU_CON2_DTVALUE_1                       (1U)                /*!< 1 Dead Time*/
#define MD_KBCU_CON2_DTVALUE_2                       (2U)                /*!< 2 Dead Time*/
#define MD_KBCU_CON2_DTVALUE_3                       (3U)                /*!< 3 Dead Time*/
#define MD_KBCU_CON2_DTVALUE_4                       (4U)                /*!< 4 Dead Time*/
#define MD_KBCU_CON2_DTVALUE_5                       (5U)                /*!< 5 Dead Time*/
#define MD_KBCU_CON2_DTVALUE_6                       (6U)                /*!< 6 Dead Time*/
#define MD_KBCU_CON2_DTVALUE_7                       (7U)                /*!< 7 Dead Time*/

/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions KBCU Public Functions
  * @{
  */

/** @defgroup MD_KBCU_Public_Functions_Group2 IER
  * @{
  */
/**
  * @brief  KBCU Set IER
  * @param  KBCUx KBCU Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_ier(KBCU_TypeDef *KBCUx, uint32_t Reg_Value)
{
    WRITE_REG(KBCUx->IER, Reg_Value);
}

/**
  * @brief  Enable key interrupt
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_it_key(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->IER, KBCU_IER_KEY);
}

/**
  * @brief  Enable column interrupt
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_it_column(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->IER, KBCU_IER_COLUMN);
}

/**
  * @brief  Enable frame interrupt
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_it_frame(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->IER, KBCU_IER_FRAME);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group3 IDR
  * @{
  */
/**
  * @brief  KBCU Set IDR
  * @param  KBCUx KBCU Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_idr(KBCU_TypeDef *KBCUx, uint32_t Reg_Value)
{
    WRITE_REG(KBCUx->IDR, Reg_Value);
}

/**
  * @brief  Disable key interrupt
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_it_key(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->IDR, KBCU_IDR_KEY);
}

/**
  * @brief  Disable column interrupt
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_it_column(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->IDR, KBCU_IDR_COLUMN);
}

/**
  * @brief  Disable frame interrupt
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_it_frame(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->IDR, KBCU_IDR_FRAME);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group4 IVS
  * @{
  */
/**
  * @brief  Get KBCU IVS
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_ivs(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->IVS));
}

/**
  * @brief  Check if key interrupt is enabled
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_it_key(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->IVS, KBCU_IVS_KEY) == (KBCU_IVS_KEY));
}

/**
  * @brief  Check if column interrupt is enabled
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_it_column(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->IVS, KBCU_IVS_COLUMN) == (KBCU_IVS_COLUMN));
}

/**
  * @brief  Check if frame interrupt is enabled
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_it_frame(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->IVS, KBCU_IVS_FRAME) == (KBCU_IVS_FRAME));
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group5 RIF
  * @{
  */
/**
  * @brief  Get KBCU RIF
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_rif(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->RIF));
}

/**
  * @brief  Get key raw interrupt flag
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_active_flag_key(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->RIF, KBCU_RIF_KEY) == (KBCU_RIF_KEY));
}

/**
  * @brief  Get column raw interrupt flag
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_active_flag_column(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->RIF, KBCU_RIF_COLUMN) == (KBCU_RIF_COLUMN));
}

/**
  * @brief  Get frame raw interrupt flag
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_active_flag_frame(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->RIF, KBCU_RIF_FRAME) == (KBCU_RIF_FRAME));
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group6 IFM
  * @{
  */
/**
  * @brief  Get KBCU IFM
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_ifm(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->IFM));
}

/**
  * @brief  Get key interrupt flag massked status
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_masked_it_key(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->IFM, KBCU_IFM_KEY) == (KBCU_IFM_KEY));
}

/**
  * @brief  Get column interrupt flag massked status
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_masked_it_column(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->IFM, KBCU_IFM_COLUMN) == (KBCU_IFM_COLUMN));
}

/**
  * @brief  Get frame interrupt flag massked status
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_masked_it_frame(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->IFM, KBCU_IFM_FRAME) == (KBCU_IFM_FRAME));
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group7 ICR
  * @{
  */
/**
  * @brief  Set KBCU ICR
  * @note   None
  * @param  KBCUx KBCU Instance
  * @param  icr
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_icr(KBCU_TypeDef *KBCUx, uint32_t icr)
{
    WRITE_REG(KBCUx->ICR, icr);
}

/**
  * @brief  Clear key raw interrupt flag
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_clear_it_key(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->ICR, KBCU_ICR_KEY);
}

/**
  * @brief  Clear column raw interrupt flag
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_clear_it_column(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->ICR, KBCU_ICR_COLUMN);
}

/**
  * @brief  Clear frame raw interrupt flag
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_clear_it_frame(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->ICR, KBCU_ICR_FRAME);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group8 CON1
  * @{
  */
/**
  * @brief  Set KBCU CON1
  * @note   None
  * @param  KBCUx KBCU Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_con1(KBCU_TypeDef *KBCUx, uint32_t Reg_Value)
{
    WRITE_REG(KBCUx->CON1, Reg_Value);
}

/**
  * @brief  Get KBCU CON1
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_con1(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->CON1));
}

/**
  * @brief  Set KBCU col_ctrl bit
  * @param  KBCUx KBCU Instance
  * @param  col_ctrl
  *         @arg @ref MD_KBCU_CON1_COL_CTRL_DEF_H
  *         @arg @ref MD_KBCU_CON1_COL_CTRL_DEF_L
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_con1_col_ctrl(KBCU_TypeDef *KBCUx, uint32_t col_ctrl)
{
    MODIFY_REG(KBCUx->CON1, KBCU_CON1_COL_CTRL, col_ctrl);
}

/**
  * @brief  Get KBCU col_ctrl bit
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_KBCU_CON1_COL_CTRL_DEF_H
  *         @arg @ref MD_KBCU_CON1_COL_CTRL_DEF_L
  */
__STATIC_INLINE uint32_t md_kbcu_get_con1_col_ctrl(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->CON1, KBCU_CON1_COL_CTRL));
}

/**
  * @brief  Set KBCU led_ctrl bit
  * @param  KBCUx KBCU Instance
  * @param  led_ctrl
  *         @arg @ref MD_KBCU_CON1_LED_CTRL_DEF_L
  *         @arg @ref MD_KBCU_CON1_LED_CTRL_DEF_H
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_con1_led_ctrl(KBCU_TypeDef *KBCUx, uint32_t led_ctrl)
{
    MODIFY_REG(KBCUx->CON1, KBCU_CON1_LED_CTRL, led_ctrl);
}

/**
  * @brief  Get KBCU led_ctrl bit
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_KBCU_CON1_LED_CTRL_DEF_L
  *         @arg @ref MD_KBCU_CON1_LED_CTRL_DEF_H
  */
__STATIC_INLINE uint32_t md_kbcu_get_con1_led_ctrl(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->CON1, KBCU_CON1_LED_CTRL));
}

/**
  * @brief  Set KBCU key_ctrl bit
  * @param  KBCUx KBCU Instance
  * @param  key_ctrl
  *         @arg @ref MD_KBCU_CON1_KEY_CTRL_DETECT_L
  *         @arg @ref MD_KBCU_CON1_KEY_CTRL_DETECT_H
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_con1_key_ctrl(KBCU_TypeDef *KBCUx, uint32_t key_ctrl)
{
    MODIFY_REG(KBCUx->CON1, KBCU_CON1_KEY_CTRL, key_ctrl);
}

/**
  * @brief  Get KBCU key_ctrl bit
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_KBCU_CON1_KEY_CTRL_DETECT_L
  *         @arg @ref MD_KBCU_CON1_KEY_CTRL_DETECT_H
  */
__STATIC_INLINE uint32_t md_kbcu_get_con1_key_ctrl(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->CON1, KBCU_CON1_KEY_CTRL));
}

/**
  * @brief  Get column switch flag
  * @note   The flag is clear when KBCU_LEDn is written. n=0~6.
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_active_flag_con1_col_flag(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->CON1, KBCU_CON1_COL_FLAG) == (KBCU_CON1_COL_FLAG));
}

/**
  * @brief  Set KBCU column mask number
  * @note   It is useless when the value of col_mask is bigger than that of colvalue.
  * @param  KBCUx KBCU Instance
  * @param  column_mask
  *         @arg Max Value 0x1F
  *         @arg Min Value 0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_con1_col_mask(KBCU_TypeDef *KBCUx, uint32_t column_mask)
{
    MODIFY_REG(KBCUx->CON1, KBCU_CON1_COL_MASK, column_mask << KBCU_CON1_COL_MASK_POSS);
}

/**
  * @brief  Get KBCU column mask number
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0x1F
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_con1_col_mask(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->CON1, KBCU_CON1_COL_MASK) >> KBCU_CON1_COL_MASK_POSS);
}

/**
  * @brief  Set KBCU number of column
  * @note   It will disable the column output when column_sel is written unexpected value.
  * @param  KBCUx KBCU Instance
  * @param  column_sel
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_15
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_16
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_17
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_18
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_19
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_20
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_21
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_22
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_23
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_24
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_con1_column_sel(KBCU_TypeDef *KBCUx, uint32_t column_sel)
{
    MODIFY_REG(KBCUx->CON1, KBCU_CON1_COLUMN_SEL, column_sel << KBCU_CON1_COLUMN_SEL_POSS);
}

/**
  * @brief  Get KBCU number of column
  * @param  KBCUx KBCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_15
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_16
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_17
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_18
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_19
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_20
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_21
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_22
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_23
  *         @arg @ref MD_KBCU_CON1_COLUMN_SEL_24
  */
__STATIC_INLINE uint32_t md_kbcu_get_con1_column_sel(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->CON1, KBCU_CON1_COL_MASK) >> KBCU_CON1_COLUMN_SEL_POSS);
}

/**
  * @brief  Enable KBCU blink function
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_con1_blink(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->CON1, KBCU_CON1_BLINK);
}

/**
  * @brief  Disable KBCU blink function
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_con1_blink(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->CON1, KBCU_CON1_BLINK);
}

/**
  * @brief  Indicate if KBCU blink is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_con1_blink(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->CON1, KBCU_CON1_BLINK) == (KBCU_CON1_BLINK));
}

/**
  * @brief  Enable KBCU
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_con1_kben(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->CON1, KBCU_CON1_KBEN);
}

/**
  * @brief  Disable KBCU
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_con1_kben(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->CON1, KBCU_CON1_KBEN);
}

/**
  * @brief  Indicate if KBCU is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_con1_kben(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->CON1, KBCU_CON1_KBEN) == (KBCU_CON1_KBEN));
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group9 CON2
  * @{
  */
/**
  * @brief  Set KBCU CON2
  * @param  KBCUx KBCU Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_con2(KBCU_TypeDef *KBCUx, uint32_t Reg_Value)
{
    WRITE_REG(KBCUx->CON2, Reg_Value);
}

/**
  * @brief  Get KBCU CON2
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_con2(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->CON2));
}

/**
  * @brief  Set KBCU the value of cycle in one column
  * @note   None
  * @param  KBCUx KBCU Instance
  * @param  colvalue
  *         @arg @ref MD_KBCU_CON2_COLVALUE_1
  *         @arg @ref MD_KBCU_CON2_COLVALUE_2
  *         @arg @ref MD_KBCU_CON2_COLVALUE_3
  *         @arg @ref MD_KBCU_CON2_COLVALUE_4
  *         @arg @ref MD_KBCU_CON2_COLVALUE_5
  *         @arg @ref MD_KBCU_CON2_COLVALUE_6
  *         @arg @ref MD_KBCU_CON2_COLVALUE_7
  *         @arg @ref MD_KBCU_CON2_COLVALUE_8
  *         @arg @ref MD_KBCU_CON2_COLVALUE_9
  *         @arg @ref MD_KBCU_CON2_COLVALUE_10
  *         @arg @ref MD_KBCU_CON2_COLVALUE_11
  *         @arg @ref MD_KBCU_CON2_COLVALUE_12
  *         @arg @ref MD_KBCU_CON2_COLVALUE_13
  *         @arg @ref MD_KBCU_CON2_COLVALUE_14
  *         @arg @ref MD_KBCU_CON2_COLVALUE_15
  *         @arg @ref MD_KBCU_CON2_COLVALUE_16
  *         @arg @ref MD_KBCU_CON2_COLVALUE_17
  *         @arg @ref MD_KBCU_CON2_COLVALUE_18
  *         @arg @ref MD_KBCU_CON2_COLVALUE_19
  *         @arg @ref MD_KBCU_CON2_COLVALUE_20
  *         @arg @ref MD_KBCU_CON2_COLVALUE_21
  *         @arg @ref MD_KBCU_CON2_COLVALUE_22
  *         @arg @ref MD_KBCU_CON2_COLVALUE_23
  *         @arg @ref MD_KBCU_CON2_COLVALUE_24
  *         @arg @ref MD_KBCU_CON2_COLVALUE_25
  *         @arg @ref MD_KBCU_CON2_COLVALUE_26
  *         @arg @ref MD_KBCU_CON2_COLVALUE_27
  *         @arg @ref MD_KBCU_CON2_COLVALUE_28
  *         @arg @ref MD_KBCU_CON2_COLVALUE_29
  *         @arg @ref MD_KBCU_CON2_COLVALUE_30
  *         @arg @ref MD_KBCU_CON2_COLVALUE_31
  *         @arg @ref MD_KBCU_CON2_COLVALUE_32
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_con2_colvalue(KBCU_TypeDef *KBCUx, uint32_t colvalue)
{
    MODIFY_REG(KBCUx->CON2, KBCU_CON2_COLVALUE, colvalue << KBCU_CON2_COLVALUE_POSS);
}

/**
  * @brief  Get KBCU the value of cycle in one column
  * @param  KBCUx KBCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_KBCU_CON2_COLVALUE_1
  *         @arg @ref MD_KBCU_CON2_COLVALUE_2
  *         @arg @ref MD_KBCU_CON2_COLVALUE_3
  *         @arg @ref MD_KBCU_CON2_COLVALUE_4
  *         @arg @ref MD_KBCU_CON2_COLVALUE_5
  *         @arg @ref MD_KBCU_CON2_COLVALUE_6
  *         @arg @ref MD_KBCU_CON2_COLVALUE_7
  *         @arg @ref MD_KBCU_CON2_COLVALUE_8
  *         @arg @ref MD_KBCU_CON2_COLVALUE_9
  *         @arg @ref MD_KBCU_CON2_COLVALUE_10
  *         @arg @ref MD_KBCU_CON2_COLVALUE_11
  *         @arg @ref MD_KBCU_CON2_COLVALUE_12
  *         @arg @ref MD_KBCU_CON2_COLVALUE_13
  *         @arg @ref MD_KBCU_CON2_COLVALUE_14
  *         @arg @ref MD_KBCU_CON2_COLVALUE_15
  *         @arg @ref MD_KBCU_CON2_COLVALUE_16
  *         @arg @ref MD_KBCU_CON2_COLVALUE_17
  *         @arg @ref MD_KBCU_CON2_COLVALUE_18
  *         @arg @ref MD_KBCU_CON2_COLVALUE_19
  *         @arg @ref MD_KBCU_CON2_COLVALUE_20
  *         @arg @ref MD_KBCU_CON2_COLVALUE_21
  *         @arg @ref MD_KBCU_CON2_COLVALUE_22
  *         @arg @ref MD_KBCU_CON2_COLVALUE_23
  *         @arg @ref MD_KBCU_CON2_COLVALUE_24
  *         @arg @ref MD_KBCU_CON2_COLVALUE_25
  *         @arg @ref MD_KBCU_CON2_COLVALUE_26
  *         @arg @ref MD_KBCU_CON2_COLVALUE_27
  *         @arg @ref MD_KBCU_CON2_COLVALUE_28
  *         @arg @ref MD_KBCU_CON2_COLVALUE_29
  *         @arg @ref MD_KBCU_CON2_COLVALUE_30
  *         @arg @ref MD_KBCU_CON2_COLVALUE_31
  *         @arg @ref MD_KBCU_CON2_COLVALUE_32
  */
__STATIC_INLINE uint32_t md_kbcu_get_con2_colvalue(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->CON2, KBCU_CON2_COLVALUE) >> KBCU_CON2_COLVALUE_POSS);
}

/**
  * @brief  Set KBCU dead time value
  * @note   None
  * @param  KBCUx KBCU Instance
  * @param  dtvalue
  *         @arg @ref MD_KBCU_CON2_DTVALUE_NONE
  *         @arg @ref MD_KBCU_CON2_DTVALUE_1
  *         @arg @ref MD_KBCU_CON2_DTVALUE_2
  *         @arg @ref MD_KBCU_CON2_DTVALUE_3
  *         @arg @ref MD_KBCU_CON2_DTVALUE_4
  *         @arg @ref MD_KBCU_CON2_DTVALUE_5
  *         @arg @ref MD_KBCU_CON2_DTVALUE_6
  *         @arg @ref MD_KBCU_CON2_DTVALUE_7
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_con2_dtvalue(KBCU_TypeDef *KBCUx, uint32_t dtvalue)
{
    MODIFY_REG(KBCUx->CON2, KBCU_CON2_DTVALUE, dtvalue << KBCU_CON2_DTVALUE_POSS);
}

/**
  * @brief  Get KBCU dead time value
  * @param  KBCUx KBCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_KBCU_CON2_DTVALUE_NONE
  *         @arg @ref MD_KBCU_CON2_DTVALUE_1
  *         @arg @ref MD_KBCU_CON2_DTVALUE_2
  *         @arg @ref MD_KBCU_CON2_DTVALUE_3
  *         @arg @ref MD_KBCU_CON2_DTVALUE_4
  *         @arg @ref MD_KBCU_CON2_DTVALUE_5
  *         @arg @ref MD_KBCU_CON2_DTVALUE_6
  *         @arg @ref MD_KBCU_CON2_DTVALUE_7
  */
__STATIC_INLINE uint32_t md_kbcu_get_con2_dtvalue(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->CON2, KBCU_CON2_DTVALUE) >> KBCU_CON2_DTVALUE_POSS);
}

/**
  * @brief  Set KBCU the number of frame to trigger frame interrupt
  * @note   None
  * @param  KBCUx KBCU Instance
  * @param  fcvalue
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_con2_fcvalue(KBCU_TypeDef *KBCUx, uint32_t fcvalue)
{
    MODIFY_REG(KBCUx->CON2, KBCU_CON2_FCVALUE, fcvalue << KBCU_CON2_FCVALUE_POSS);
}

/**
  * @brief  Get KBCU the number of frame to trigger frame interrupt
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_con2_fcvalue(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->CON2, KBCU_CON2_FCVALUE) >> KBCU_CON2_FCVALUE_POSS);
}

/**
  * @brief  Set KBCU the divider of HCLK
  * @note   None
  * @param  KBCUx KBCU Instance
  * @param  frdiv
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_con2_frdiv(KBCU_TypeDef *KBCUx, uint32_t frdiv)
{
    MODIFY_REG(KBCUx->CON2, KBCU_CON2_FRDIV, frdiv << KBCU_CON2_FRDIV_POSS);
}

/**
  * @brief  Get KBCU the divider of HCLK
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_con2_frdiv(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->CON2, KBCU_CON2_FRDIV) >> KBCU_CON2_FRDIV_POSS);
}

/**
  * @brief  Set KBCU the auto reload value
  * @note   None
  * @param  KBCUx KBCU Instance
  * @param  arvalue
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_con2_arvalue(KBCU_TypeDef *KBCUx, uint32_t arvalue)
{
    MODIFY_REG(KBCUx->CON2, KBCU_CON2_ARVALUE, arvalue << KBCU_CON2_ARVALUE_POSS);
}

/**
  * @brief  Get KBCU the auto reload value
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_con2_arvalue(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->CON2, KBCU_CON2_ARVALUE) >> KBCU_CON2_ARVALUE_POSS);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group10 SCAN0
  * @{
  */
/**
  * @brief  Get KBCU SCAN0
  * @note   Reading SCAN0 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan0(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->SCAN0));
}

/**
  * @brief  Get KBCU the position of pressed keys in column3
  * @note   Reading SCAN0 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan0_column3(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN0, KBCU_SCAN0_COLUMN3) >> KBCU_SCAN0_COLUMN3_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column2
  * @note   Reading SCAN0 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan0_column2(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN0, KBCU_SCAN0_COLUMN2) >> KBCU_SCAN0_COLUMN2_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column1
  * @note   Reading SCAN0 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan0_column1(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN0, KBCU_SCAN0_COLUMN1) >> KBCU_SCAN0_COLUMN1_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column0
  * @note   Reading SCAN0 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan0_column0(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN0, KBCU_SCAN0_COLUMN0) >> KBCU_SCAN0_COLUMN0_POSS);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group11 SCAN1
  * @{
  */
/**
  * @brief  Get KBCU SCAN1
  * @note   Reading SCAN1 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan1(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->SCAN1));
}

/**
  * @brief  Get KBCU the position of pressed keys in column7
  * @note   Reading SCAN1 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan1_column7(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN1, KBCU_SCAN1_COLUMN7) >> KBCU_SCAN1_COLUMN7_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column6
  * @note   Reading SCAN1 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan1_column6(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN1, KBCU_SCAN1_COLUMN6) >> KBCU_SCAN1_COLUMN6_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column5
  * @note   Reading SCAN1 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan1_column5(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN1, KBCU_SCAN1_COLUMN5) >> KBCU_SCAN1_COLUMN5_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column4
  * @note   Reading SCAN1 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan1_column4(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN1, KBCU_SCAN1_COLUMN4) >> KBCU_SCAN1_COLUMN4_POSS);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group12 SCAN2
  * @{
  */
/**
  * @brief  Get KBCU SCAN2
  * @note   Reading SCAN2 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan2(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->SCAN2));
}

/**
  * @brief  Get KBCU the position of pressed keys in column11
  * @note   Reading SCAN2 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan2_column11(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN2, KBCU_SCAN2_COLUMN11) >> KBCU_SCAN2_COLUMN11_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column10
  * @note   Reading SCAN2 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan2_column10(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN2, KBCU_SCAN2_COLUMN10) >> KBCU_SCAN2_COLUMN10_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column9
  * @note   Reading SCAN2 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan2_column9(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN2, KBCU_SCAN2_COLUMN9) >> KBCU_SCAN2_COLUMN9_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column8
  * @note   Reading SCAN2 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan2_column8(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN2, KBCU_SCAN2_COLUMN8) >> KBCU_SCAN2_COLUMN8_POSS);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group13 SCAN3
  * @{
  */
/**
  * @brief  Get KBCU SCAN3
  * @note   Reading SCAN3 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan3(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->SCAN3));
}

/**
  * @brief  Get KBCU the position of pressed keys in column15
  * @note   Reading SCAN3 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan3_column15(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN3, KBCU_SCAN3_COLUMN15) >> KBCU_SCAN3_COLUMN15_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column14
  * @note   Reading SCAN3 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan3_column14(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN3, KBCU_SCAN3_COLUMN14) >> KBCU_SCAN3_COLUMN14_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column13
  * @note   Reading SCAN3 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan3_column13(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN3, KBCU_SCAN3_COLUMN13) >> KBCU_SCAN3_COLUMN13_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column12
  * @note   Reading SCAN3 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan3_column12(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN3, KBCU_SCAN3_COLUMN12) >> KBCU_SCAN3_COLUMN12_POSS);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group14 SCAN4
  * @{
  */
/**
  * @brief  Get KBCU SCAN4
  * @note   Reading SCAN4 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan4(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->SCAN4));
}

/**
  * @brief  Get KBCU the position of pressed keys in column19
  * @note   Reading SCAN4 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan4_column19(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN4, KBCU_SCAN4_COLUMN19) >> KBCU_SCAN4_COLUMN19_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column18
  * @note   Reading SCAN4 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan4_column18(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN4, KBCU_SCAN4_COLUMN18) >> KBCU_SCAN4_COLUMN18_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column17
  * @note   Reading SCAN4 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan4_column17(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN4, KBCU_SCAN4_COLUMN17) >> KBCU_SCAN4_COLUMN17_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column16
  * @note   Reading SCAN4 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan4_column16(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN4, KBCU_SCAN4_COLUMN16) >> KBCU_SCAN4_COLUMN16_POSS);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group15 SCAN5
  * @{
  */
/**
  * @brief  Get KBCU SCAN5
  * @note   Reading SCAN5 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan5(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->SCAN5));
}

/**
  * @brief  Get KBCU the position of pressed keys in column23
  * @note   Reading SCAN5 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan5_column23(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN5, KBCU_SCAN5_COLUMN23) >> KBCU_SCAN5_COLUMN23_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column22
  * @note   Reading SCAN5 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan5_column22(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN5, KBCU_SCAN5_COLUMN22) >> KBCU_SCAN5_COLUMN22_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column21
  * @note   Reading SCAN5 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan5_column21(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN5, KBCU_SCAN5_COLUMN21) >> KBCU_SCAN5_COLUMN21_POSS);
}

/**
  * @brief  Get KBCU the position of pressed keys in column20
  * @note   Reading SCAN5 automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Row0
  *         Bit1 mapping Row1
  *         Bit2 mapping Row2
  *         Bit3 mapping Row3
  *         Bit4 mapping Row4
  *         Bit5 mapping Row5
  *         Bit6 mapping Row6
  */
__STATIC_INLINE uint32_t md_kbcu_get_scan5_column20(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->SCAN5, KBCU_SCAN5_COLUMN20) >> KBCU_SCAN5_COLUMN20_POSS);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group16 STAT
  * @{
  */
/**
  * @brief  Get KBCU STAT
  * @note   Reading STAT automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_stat(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->STAT));
}

/**
  * @brief  Get KBCU which columns where there are pressed keys are detected.
  * @note   Reading STAT automatically clears it to 0.
  * @param  KBCUx KBCU Instance
  * @retval Bitmap:
  *         Bit0 mapping Column0
  *         Bit1 mapping Column1
  *         Bit2 mapping Column2
  *                   .
  *                   .
  *                   .
  *         Bit21 mapping Column21
  *         Bit22 mapping Column22
  *         Bit23 mapping Column23
  */
__STATIC_INLINE uint32_t md_kbcu_get_stat_column(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->STAT, KBCU_STAT_COLUMN) >> KBCU_STAT_COLUMN_POSS);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group17 LED0
  * @{
  */
/**
  * @brief  Set KBCU LED0
  * @param  KBCUx KBCU Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led0(KBCU_TypeDef *KBCUx, uint32_t Reg_Value)
{
    WRITE_REG(KBCUx->LED0, Reg_Value);
}

/**
  * @brief  Get KBCU LED0
  * @note   None.
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_led0(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->LED0));
}

/**
  * @brief  Set KBCU the PWM mask in one column in Row0
  * @note   None
  * @param  KBCUx KBCU Instance
  * @param  mask
  *         @arg Max Value 0x1F
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led0_mask(KBCU_TypeDef *KBCUx, uint32_t mask)
{
    MODIFY_REG(KBCUx->LED0, KBCU_LED0_MASK, mask << KBCU_LED0_MASK_POSS);
}

/**
  * @brief  Get KBCU the PWM mask in one column in Row0
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0x1F
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led0_mask(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED0, KBCU_LED0_MASK) >> KBCU_LED0_MASK_POSS);
}

/**
  * @brief  Enable KBCU Row0 PWM2 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led0_duty2_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED0, KBCU_LED0_DUTY2_H);
}

/**
  * @brief  Disable KBCU Row0 PWM2 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led0_duty2_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED0, KBCU_LED0_DUTY2_H);
}

/**
  * @brief  Indicate if Row0 PWM2 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led0_duty2_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED0, KBCU_LED0_DUTY2_H) == (KBCU_LED0_DUTY2_H));
}

/**
  * @brief  Enable KBCU Row0 PWM1 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led0_duty1_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED0, KBCU_LED0_DUTY1_H);
}

/**
  * @brief  Disable KBCU Row0 PWM1 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led0_duty1_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED0, KBCU_LED0_DUTY1_H);
}

/**
  * @brief  Indicate if Row0 PWM1 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led0_duty1_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED0, KBCU_LED0_DUTY1_H) == (KBCU_LED0_DUTY1_H));
}

/**
  * @brief  Enable KBCU Row0 PWM0 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led0_duty0_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED0, KBCU_LED0_DUTY0_H);
}

/**
  * @brief  Disable KBCU Row0 PWM0 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led0_duty0_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED0, KBCU_LED0_DUTY0_H);
}

/**
  * @brief  Indicate if Row0 PWM0 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led0_duty0_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED0, KBCU_LED0_DUTY0_H) == (KBCU_LED0_DUTY0_H));
}

/**
  * @brief  Set KBCU a duty cycle of PWM2 determined by the value of the DUTY2
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row0.
  * @param  KBCUx KBCU Instance
  * @param  duty2
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led0_duty2(KBCU_TypeDef *KBCUx, uint32_t duty2)
{
    MODIFY_REG(KBCUx->LED0, KBCU_LED0_DUTY2, duty2 << KBCU_LED0_DUTY2_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM2 determined by the value of the DUTY2
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row0.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led0_duty2(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED0, KBCU_LED0_DUTY2) >> KBCU_LED0_DUTY2_POSS);
}

/**
  * @brief  Set KBCU a duty cycle of PWM1 determined by the value of the DUTY1
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row0.
  * @param  KBCUx KBCU Instance
  * @param  duty1
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led0_duty1(KBCU_TypeDef *KBCUx, uint32_t duty1)
{
    MODIFY_REG(KBCUx->LED0, KBCU_LED0_DUTY1, duty1 << KBCU_LED0_DUTY1_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM1 determined by the value of the DUTY1
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row0.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led0_duty1(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED0, KBCU_LED0_DUTY1) >> KBCU_LED0_DUTY1_POSS);
}

/**
  * @brief  Set KBCU a duty cycle of PWM0 determined by the value of the DUTY0
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row0.
  * @param  KBCUx KBCU Instance
  * @param  duty0
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led0_duty0(KBCU_TypeDef *KBCUx, uint32_t duty0)
{
    MODIFY_REG(KBCUx->LED0, KBCU_LED0_DUTY0, duty0 << KBCU_LED0_DUTY0_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM0 determined by the value of the DUTY0
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row0.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led0_duty0(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED0, KBCU_LED0_DUTY0) >> KBCU_LED0_DUTY0_POSS);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group18 LED1
  * @{
  */
/**
  * @brief  Set KBCU LED1
  * @param  KBCUx KBCU Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led1(KBCU_TypeDef *KBCUx, uint32_t Reg_Value)
{
    WRITE_REG(KBCUx->LED1, Reg_Value);
}

/**
  * @brief  Get KBCU LED1
  * @note   None.
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_led1(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->LED1));
}

/**
  * @brief  Set KBCU the PWM mask in one column in Row1
  * @note   None
  * @param  KBCUx KBCU Instance
  * @param  mask
  *         @arg Max Value 0x1F
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led1_mask(KBCU_TypeDef *KBCUx, uint32_t mask)
{
    MODIFY_REG(KBCUx->LED1, KBCU_LED1_MASK, mask << KBCU_LED1_MASK_POSS);
}

/**
  * @brief  Get KBCU the PWM mask in one column in Row1
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0x1F
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led1_mask(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED1, KBCU_LED1_MASK) >> KBCU_LED1_MASK_POSS);
}

/**
  * @brief  Enable KBCU Row1 PWM2 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led1_duty2_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED1, KBCU_LED1_DUTY2_H);
}

/**
  * @brief  Disable KBCU Row1 PWM2 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led1_duty2_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED1, KBCU_LED1_DUTY2_H);
}

/**
  * @brief  Indicate if Row1 PWM2 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led1_duty2_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED1, KBCU_LED1_DUTY2_H) == (KBCU_LED1_DUTY2_H));
}

/**
  * @brief  Enable KBCU Row1 PWM1 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led1_duty1_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED1, KBCU_LED1_DUTY1_H);
}

/**
  * @brief  Disable KBCU Row1 PWM1 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led1_duty1_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED1, KBCU_LED1_DUTY1_H);
}

/**
  * @brief  Indicate if Row1 PWM1 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led1_duty1_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED1, KBCU_LED1_DUTY1_H) == (KBCU_LED1_DUTY1_H));
}

/**
  * @brief  Enable KBCU Row1 PWM0 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led1_duty0_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED1, KBCU_LED1_DUTY0_H);
}

/**
  * @brief  Disable KBCU Row1 PWM0 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led1_duty0_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED1, KBCU_LED1_DUTY0_H);
}

/**
  * @brief  Indicate if Row1 PWM0 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led1_duty0_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED1, KBCU_LED1_DUTY0_H) == (KBCU_LED1_DUTY0_H));
}

/**
  * @brief  Set KBCU a duty cycle of PWM2 determined by the value of the DUTY2
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row1.
  * @param  KBCUx KBCU Instance
  * @param  duty2
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led1_duty2(KBCU_TypeDef *KBCUx, uint32_t duty2)
{
    MODIFY_REG(KBCUx->LED1, KBCU_LED1_DUTY2, duty2 << KBCU_LED1_DUTY2_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM2 determined by the value of the DUTY2
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row1.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led1_duty2(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED1, KBCU_LED1_DUTY2) >> KBCU_LED1_DUTY2_POSS);
}

/**
  * @brief  Set KBCU a duty cycle of PWM1 determined by the value of the DUTY1
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row1.
  * @param  KBCUx KBCU Instance
  * @param  duty1
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led1_duty1(KBCU_TypeDef *KBCUx, uint32_t duty1)
{
    MODIFY_REG(KBCUx->LED1, KBCU_LED1_DUTY1, duty1 << KBCU_LED1_DUTY1_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM1 determined by the value of the DUTY1
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row1.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led1_duty1(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED1, KBCU_LED1_DUTY1) >> KBCU_LED1_DUTY1_POSS);
}

/**
  * @brief  Set KBCU a duty cycle of PWM0 determined by the value of the DUTY0
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row1.
  * @param  KBCUx KBCU Instance
  * @param  duty0
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led1_duty0(KBCU_TypeDef *KBCUx, uint32_t duty0)
{
    MODIFY_REG(KBCUx->LED1, KBCU_LED1_DUTY0, duty0 << KBCU_LED1_DUTY0_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM0 determined by the value of the DUTY0
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row1.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led1_duty0(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED1, KBCU_LED1_DUTY0) >> KBCU_LED1_DUTY0_POSS);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group19 LED2
  * @{
  */
/**
  * @brief  Set KBCU LED2
  * @param  KBCUx KBCU Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led2(KBCU_TypeDef *KBCUx, uint32_t Reg_Value)
{
    WRITE_REG(KBCUx->LED2, Reg_Value);
}

/**
  * @brief  Get KBCU LED2
  * @note   None.
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_led2(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->LED2));
}

/**
  * @brief  Set KBCU the PWM mask in one column in Row2
  * @note   None
  * @param  KBCUx KBCU Instance
  * @param  mask
  *         @arg Max Value 0x1F
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led2_mask(KBCU_TypeDef *KBCUx, uint32_t mask)
{
    MODIFY_REG(KBCUx->LED2, KBCU_LED2_MASK, mask << KBCU_LED2_MASK_POSS);
}

/**
  * @brief  Get KBCU the PWM mask in one column in Row2
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0x1F
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led2_mask(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED2, KBCU_LED2_MASK) >> KBCU_LED2_MASK_POSS);
}

/**
  * @brief  Enable KBCU Row2 PWM2 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led2_duty2_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED2, KBCU_LED2_DUTY2_H);
}

/**
  * @brief  Disable KBCU Row2 PWM2 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led2_duty2_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED2, KBCU_LED2_DUTY2_H);
}

/**
  * @brief  Indicate if Row2 PWM2 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led2_duty2_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED2, KBCU_LED2_DUTY2_H) == (KBCU_LED2_DUTY2_H));
}

/**
  * @brief  Enable KBCU Row2 PWM1 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led2_duty1_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED2, KBCU_LED2_DUTY1_H);
}

/**
  * @brief  Disable KBCU Row2 PWM1 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led2_duty1_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED2, KBCU_LED2_DUTY1_H);
}

/**
  * @brief  Indicate if Row2 PWM1 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led2_duty1_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED2, KBCU_LED2_DUTY1_H) == (KBCU_LED2_DUTY1_H));
}

/**
  * @brief  Enable KBCU Row2 PWM0 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led2_duty0_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED2, KBCU_LED2_DUTY0_H);
}

/**
  * @brief  Disable KBCU Row2 PWM0 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led2_duty0_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED2, KBCU_LED2_DUTY0_H);
}

/**
  * @brief  Indicate if Row2 PWM0 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led2_duty0_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED2, KBCU_LED2_DUTY0_H) == (KBCU_LED2_DUTY0_H));
}

/**
  * @brief  Set KBCU a duty cycle of PWM2 determined by the value of the DUTY2
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row2.
  * @param  KBCUx KBCU Instance
  * @param  duty2
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led2_duty2(KBCU_TypeDef *KBCUx, uint32_t duty2)
{
    MODIFY_REG(KBCUx->LED2, KBCU_LED2_DUTY2, duty2 << KBCU_LED2_DUTY2_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM2 determined by the value of the DUTY2
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row2.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led2_duty2(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED2, KBCU_LED2_DUTY2) >> KBCU_LED2_DUTY2_POSS);
}

/**
  * @brief  Set KBCU a duty cycle of PWM1 determined by the value of the DUTY1
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row2.
  * @param  KBCUx KBCU Instance
  * @param  duty1
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led2_duty1(KBCU_TypeDef *KBCUx, uint32_t duty1)
{
    MODIFY_REG(KBCUx->LED2, KBCU_LED2_DUTY1, duty1 << KBCU_LED2_DUTY1_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM1 determined by the value of the DUTY1
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row2.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led2_duty1(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED2, KBCU_LED2_DUTY1) >> KBCU_LED2_DUTY1_POSS);
}

/**
  * @brief  Set KBCU a duty cycle of PWM0 determined by the value of the DUTY0
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row2.
  * @param  KBCUx KBCU Instance
  * @param  duty0
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led2_duty0(KBCU_TypeDef *KBCUx, uint32_t duty0)
{
    MODIFY_REG(KBCUx->LED2, KBCU_LED2_DUTY0, duty0 << KBCU_LED2_DUTY0_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM0 determined by the value of the DUTY0
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row2.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led2_duty0(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED2, KBCU_LED2_DUTY0) >> KBCU_LED2_DUTY0_POSS);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group20 LED3
  * @{
  */
/**
  * @brief  Set KBCU LED3
  * @param  KBCUx KBCU Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led3(KBCU_TypeDef *KBCUx, uint32_t Reg_Value)
{
    WRITE_REG(KBCUx->LED3, Reg_Value);
}

/**
  * @brief  Get KBCU LED3
  * @note   None.
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_led3(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->LED3));
}

/**
  * @brief  Set KBCU the PWM mask in one column in Row3
  * @note   None
  * @param  KBCUx KBCU Instance
  * @param  mask
  *         @arg Max Value 0x1F
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led3_mask(KBCU_TypeDef *KBCUx, uint32_t mask)
{
    MODIFY_REG(KBCUx->LED3, KBCU_LED3_MASK, mask << KBCU_LED3_MASK_POSS);
}

/**
  * @brief  Get KBCU the PWM mask in one column in Row3
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0x1F
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led3_mask(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED3, KBCU_LED3_MASK) >> KBCU_LED3_MASK_POSS);
}

/**
  * @brief  Enable KBCU Row3 PWM2 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led3_duty2_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED3, KBCU_LED3_DUTY2_H);
}

/**
  * @brief  Disable KBCU Row3 PWM2 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led3_duty2_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED3, KBCU_LED3_DUTY2_H);
}

/**
  * @brief  Indicate if Row3 PWM2 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led3_duty2_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED3, KBCU_LED3_DUTY2_H) == (KBCU_LED3_DUTY2_H));
}

/**
  * @brief  Enable KBCU Row3 PWM1 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led3_duty1_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED3, KBCU_LED3_DUTY1_H);
}

/**
  * @brief  Disable KBCU Row3 PWM1 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led3_duty1_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED3, KBCU_LED3_DUTY1_H);
}

/**
  * @brief  Indicate if Row3 PWM1 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led3_duty1_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED3, KBCU_LED3_DUTY1_H) == (KBCU_LED3_DUTY1_H));
}

/**
  * @brief  Enable KBCU Row3 PWM0 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led3_duty0_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED3, KBCU_LED3_DUTY0_H);
}

/**
  * @brief  Disable KBCU Row3 PWM0 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led3_duty0_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED3, KBCU_LED3_DUTY0_H);
}

/**
  * @brief  Indicate if Row3 PWM0 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led3_duty0_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED3, KBCU_LED3_DUTY0_H) == (KBCU_LED3_DUTY0_H));
}

/**
  * @brief  Set KBCU a duty cycle of PWM2 determined by the value of the DUTY2
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row3.
  * @param  KBCUx KBCU Instance
  * @param  duty2
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led3_duty2(KBCU_TypeDef *KBCUx, uint32_t duty2)
{
    MODIFY_REG(KBCUx->LED3, KBCU_LED3_DUTY2, duty2 << KBCU_LED3_DUTY2_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM2 determined by the value of the DUTY2
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row3.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led3_duty2(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED3, KBCU_LED3_DUTY2) >> KBCU_LED3_DUTY2_POSS);
}

/**
  * @brief  Set KBCU a duty cycle of PWM1 determined by the value of the DUTY1
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row3.
  * @param  KBCUx KBCU Instance
  * @param  duty1
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led3_duty1(KBCU_TypeDef *KBCUx, uint32_t duty1)
{
    MODIFY_REG(KBCUx->LED3, KBCU_LED3_DUTY1, duty1 << KBCU_LED3_DUTY1_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM1 determined by the value of the DUTY1
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row3.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led3_duty1(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED3, KBCU_LED3_DUTY1) >> KBCU_LED3_DUTY1_POSS);
}

/**
  * @brief  Set KBCU a duty cycle of PWM0 determined by the value of the DUTY0
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row3.
  * @param  KBCUx KBCU Instance
  * @param  duty0
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led3_duty0(KBCU_TypeDef *KBCUx, uint32_t duty0)
{
    MODIFY_REG(KBCUx->LED3, KBCU_LED3_DUTY0, duty0 << KBCU_LED3_DUTY0_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM0 determined by the value of the DUTY0
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row3.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led3_duty0(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED3, KBCU_LED3_DUTY0) >> KBCU_LED3_DUTY0_POSS);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group21 LED4
  * @{
  */
/**
  * @brief  Set KBCU LED4
  * @param  KBCUx KBCU Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led4(KBCU_TypeDef *KBCUx, uint32_t Reg_Value)
{
    WRITE_REG(KBCUx->LED4, Reg_Value);
}

/**
  * @brief  Get KBCU LED4
  * @note   None.
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_led4(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->LED4));
}

/**
  * @brief  Set KBCU the PWM mask in one column in Row4
  * @note   None
  * @param  KBCUx KBCU Instance
  * @param  mask
  *         @arg Max Value 0x1F
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led4_mask(KBCU_TypeDef *KBCUx, uint32_t mask)
{
    MODIFY_REG(KBCUx->LED4, KBCU_LED4_MASK, mask << KBCU_LED4_MASK_POSS);
}

/**
  * @brief  Get KBCU the PWM mask in one column in Row4
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0x1F
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led4_mask(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED4, KBCU_LED4_MASK) >> KBCU_LED4_MASK_POSS);
}

/**
  * @brief  Enable KBCU Row4 PWM2 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led4_duty2_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED4, KBCU_LED4_DUTY2_H);
}

/**
  * @brief  Disable KBCU Row4 PWM2 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led4_duty2_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED4, KBCU_LED4_DUTY2_H);
}

/**
  * @brief  Indicate if Row4 PWM2 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led4_duty2_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED4, KBCU_LED4_DUTY2_H) == (KBCU_LED4_DUTY2_H));
}

/**
  * @brief  Enable KBCU Row4 PWM1 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led4_duty1_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED4, KBCU_LED4_DUTY1_H);
}

/**
  * @brief  Disable KBCU Row4 PWM1 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led4_duty1_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED4, KBCU_LED4_DUTY1_H);
}

/**
  * @brief  Indicate if Row4 PWM1 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led4_duty1_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED4, KBCU_LED4_DUTY1_H) == (KBCU_LED4_DUTY1_H));
}

/**
  * @brief  Enable KBCU Row4 PWM0 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led4_duty0_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED4, KBCU_LED4_DUTY0_H);
}

/**
  * @brief  Disable KBCU Row4 PWM0 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led4_duty0_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED4, KBCU_LED4_DUTY0_H);
}

/**
  * @brief  Indicate if Row4 PWM0 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led4_duty0_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED4, KBCU_LED4_DUTY0_H) == (KBCU_LED4_DUTY0_H));
}

/**
  * @brief  Set KBCU a duty cycle of PWM2 determined by the value of the DUTY2
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row4.
  * @param  KBCUx KBCU Instance
  * @param  duty2
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led4_duty2(KBCU_TypeDef *KBCUx, uint32_t duty2)
{
    MODIFY_REG(KBCUx->LED4, KBCU_LED4_DUTY2, duty2 << KBCU_LED4_DUTY2_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM2 determined by the value of the DUTY2
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row4.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led4_duty2(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED4, KBCU_LED4_DUTY2) >> KBCU_LED4_DUTY2_POSS);
}

/**
  * @brief  Set KBCU a duty cycle of PWM1 determined by the value of the DUTY1
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row4.
  * @param  KBCUx KBCU Instance
  * @param  duty1
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led4_duty1(KBCU_TypeDef *KBCUx, uint32_t duty1)
{
    MODIFY_REG(KBCUx->LED4, KBCU_LED4_DUTY1, duty1 << KBCU_LED4_DUTY1_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM1 determined by the value of the DUTY1
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row4.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led4_duty1(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED4, KBCU_LED4_DUTY1) >> KBCU_LED4_DUTY1_POSS);
}

/**
  * @brief  Set KBCU a duty cycle of PWM0 determined by the value of the DUTY0
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row4.
  * @param  KBCUx KBCU Instance
  * @param  duty0
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led4_duty0(KBCU_TypeDef *KBCUx, uint32_t duty0)
{
    MODIFY_REG(KBCUx->LED4, KBCU_LED4_DUTY0, duty0 << KBCU_LED4_DUTY0_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM0 determined by the value of the DUTY0
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row4.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led4_duty0(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED4, KBCU_LED4_DUTY0) >> KBCU_LED4_DUTY0_POSS);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group22 LED5
  * @{
  */
/**
  * @brief  Set KBCU LED5
  * @param  KBCUx KBCU Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led5(KBCU_TypeDef *KBCUx, uint32_t Reg_Value)
{
    WRITE_REG(KBCUx->LED5, Reg_Value);
}

/**
  * @brief  Get KBCU LED5
  * @note   None.
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_led5(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->LED5));
}

/**
  * @brief  Set KBCU the PWM mask in one column in Row5
  * @note   None
  * @param  KBCUx KBCU Instance
  * @param  mask
  *         @arg Max Value 0x1F
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led5_mask(KBCU_TypeDef *KBCUx, uint32_t mask)
{
    MODIFY_REG(KBCUx->LED5, KBCU_LED5_MASK, mask << KBCU_LED5_MASK_POSS);
}

/**
  * @brief  Get KBCU the PWM mask in one column in Row5
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0x1F
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led5_mask(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED5, KBCU_LED5_MASK) >> KBCU_LED5_MASK_POSS);
}

/**
  * @brief  Enable KBCU Row5 PWM2 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led5_duty2_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED5, KBCU_LED5_DUTY2_H);
}

/**
  * @brief  Disable KBCU Row5 PWM2 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led5_duty2_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED5, KBCU_LED5_DUTY2_H);
}

/**
  * @brief  Indicate if Row5 PWM2 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led5_duty2_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED5, KBCU_LED5_DUTY2_H) == (KBCU_LED5_DUTY2_H));
}

/**
  * @brief  Enable KBCU Row5 PWM1 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led5_duty1_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED5, KBCU_LED5_DUTY1_H);
}

/**
  * @brief  Disable KBCU Row5 PWM1 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led5_duty1_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED5, KBCU_LED5_DUTY1_H);
}

/**
  * @brief  Indicate if Row5 PWM1 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led5_duty1_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED5, KBCU_LED5_DUTY1_H) == (KBCU_LED5_DUTY1_H));
}

/**
  * @brief  Enable KBCU Row5 PWM0 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led5_duty0_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED5, KBCU_LED5_DUTY0_H);
}

/**
  * @brief  Disable KBCU Row5 PWM0 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led5_duty0_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED5, KBCU_LED5_DUTY0_H);
}

/**
  * @brief  Indicate if Row5 PWM0 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led5_duty0_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED5, KBCU_LED5_DUTY0_H) == (KBCU_LED5_DUTY0_H));
}

/**
  * @brief  Set KBCU a duty cycle of PWM2 determined by the value of the DUTY2
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row5.
  * @param  KBCUx KBCU Instance
  * @param  duty2
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led5_duty2(KBCU_TypeDef *KBCUx, uint32_t duty2)
{
    MODIFY_REG(KBCUx->LED5, KBCU_LED5_DUTY2, duty2 << KBCU_LED5_DUTY2_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM2 determined by the value of the DUTY2
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row5.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led5_duty2(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED5, KBCU_LED5_DUTY2) >> KBCU_LED5_DUTY2_POSS);
}

/**
  * @brief  Set KBCU a duty cycle of PWM1 determined by the value of the DUTY1
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row5.
  * @param  KBCUx KBCU Instance
  * @param  duty1
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led5_duty1(KBCU_TypeDef *KBCUx, uint32_t duty1)
{
    MODIFY_REG(KBCUx->LED5, KBCU_LED5_DUTY1, duty1 << KBCU_LED5_DUTY1_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM1 determined by the value of the DUTY1
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row5.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led5_duty1(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED5, KBCU_LED5_DUTY1) >> KBCU_LED5_DUTY1_POSS);
}

/**
  * @brief  Set KBCU a duty cycle of PWM0 determined by the value of the DUTY0
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row5.
  * @param  KBCUx KBCU Instance
  * @param  duty0
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led5_duty0(KBCU_TypeDef *KBCUx, uint32_t duty0)
{
    MODIFY_REG(KBCUx->LED5, KBCU_LED5_DUTY0, duty0 << KBCU_LED5_DUTY0_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM0 determined by the value of the DUTY0
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row5.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led5_duty0(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED5, KBCU_LED5_DUTY0) >> KBCU_LED5_DUTY0_POSS);
}
/**
  * @}
  */

/** @defgroup MD_KBCU_Public_Functions_Group23 LED6
  * @{
  */
/**
  * @brief  Set KBCU LED6
  * @param  KBCUx KBCU Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led6(KBCU_TypeDef *KBCUx, uint32_t Reg_Value)
{
    WRITE_REG(KBCUx->LED6, Reg_Value);
}

/**
  * @brief  Get KBCU LED6
  * @note   None.
  * @param  KBCUx KBCU Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_kbcu_get_led6(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_REG(KBCUx->LED6));
}

/**
  * @brief  Set KBCU the PWM mask in one column in Row6
  * @note   None
  * @param  KBCUx KBCU Instance
  * @param  mask
  *         @arg Max Value 0x1F
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led6_mask(KBCU_TypeDef *KBCUx, uint32_t mask)
{
    MODIFY_REG(KBCUx->LED6, KBCU_LED6_MASK, mask << KBCU_LED6_MASK_POSS);
}

/**
  * @brief  Get KBCU the PWM mask in one column in Row6
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0x1F
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led6_mask(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED6, KBCU_LED6_MASK) >> KBCU_LED6_MASK_POSS);
}

/**
  * @brief  Enable KBCU Row6 PWM2 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led6_duty2_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED6, KBCU_LED6_DUTY2_H);
}

/**
  * @brief  Disable KBCU Row6 PWM2 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led6_duty2_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED6, KBCU_LED6_DUTY2_H);
}

/**
  * @brief  Indicate if Row6 PWM2 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led6_duty2_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED6, KBCU_LED6_DUTY2_H) == (KBCU_LED6_DUTY2_H));
}

/**
  * @brief  Enable KBCU Row6 PWM1 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led6_duty1_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED6, KBCU_LED6_DUTY1_H);
}

/**
  * @brief  Disable KBCU Row6 PWM1 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led6_duty1_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED6, KBCU_LED6_DUTY1_H);
}

/**
  * @brief  Indicate if Row6 PWM1 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led6_duty1_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED6, KBCU_LED6_DUTY1_H) == (KBCU_LED6_DUTY1_H));
}

/**
  * @brief  Enable KBCU Row6 PWM0 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_enable_led6_duty0_h(KBCU_TypeDef *KBCUx)
{
    SET_BIT(KBCUx->LED6, KBCU_LED6_DUTY0_H);
}

/**
  * @brief  Disable KBCU Row6 PWM0 Duty-Cycle 100%
  * @note   None
  * @param  KBCUx KBCU Instance
  * @retval None
  */
__STATIC_INLINE void md_kbcu_disable_led6_duty0_h(KBCU_TypeDef *KBCUx)
{
    CLEAR_BIT(KBCUx->LED6, KBCU_LED6_DUTY0_H);
}

/**
  * @brief  Indicate if Row6 PWM0 Duty-Cycle 100% function is enabled
  * @param  KBCUx KBCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_kbcu_is_enabled_led6_duty0_h(KBCU_TypeDef *KBCUx)
{
    return (READ_BIT(KBCUx->LED6, KBCU_LED6_DUTY0_H) == (KBCU_LED6_DUTY0_H));
}

/**
  * @brief  Set KBCU a duty cycle of PWM2 determined by the value of the DUTY2
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row6.
  * @param  KBCUx KBCU Instance
  * @param  duty2
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led6_duty2(KBCU_TypeDef *KBCUx, uint32_t duty2)
{
    MODIFY_REG(KBCUx->LED6, KBCU_LED6_DUTY2, duty2 << KBCU_LED6_DUTY2_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM2 determined by the value of the DUTY2
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row6.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led6_duty2(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED6, KBCU_LED6_DUTY2) >> KBCU_LED6_DUTY2_POSS);
}

/**
  * @brief  Set KBCU a duty cycle of PWM1 determined by the value of the DUTY1
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row6.
  * @param  KBCUx KBCU Instance
  * @param  duty1
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led6_duty1(KBCU_TypeDef *KBCUx, uint32_t duty1)
{
    MODIFY_REG(KBCUx->LED6, KBCU_LED6_DUTY1, duty1 << KBCU_LED6_DUTY1_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM1 determined by the value of the DUTY1
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row6.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led6_duty1(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED6, KBCU_LED6_DUTY1) >> KBCU_LED6_DUTY1_POSS);
}

/**
  * @brief  Set KBCU a duty cycle of PWM0 determined by the value of the DUTY0
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row6.
  * @param  KBCUx KBCU Instance
  * @param  duty0
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_kbcu_set_led6_duty0(KBCU_TypeDef *KBCUx, uint32_t duty0)
{
    MODIFY_REG(KBCUx->LED6, KBCU_LED6_DUTY0, duty0 << KBCU_LED6_DUTY0_POSS);
}

/**
  * @brief  Get KBCU a duty cycle of PWM0 determined by the value of the DUTY0
  * @note   It is a PWM signal with a frequency determined by ARVALUE in Row6.
  * @param  KBCUx KBCU Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_kbcu_get_led6_duty0(KBCU_TypeDef *KBCUx)
{
    return (uint32_t)(READ_BIT(KBCUx->LED6, KBCU_LED6_DUTY0) >> KBCU_LED6_DUTY0_POSS);
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
