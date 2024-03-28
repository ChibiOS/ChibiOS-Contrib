/**********************************************************************************
 *
 * @file    md_calc.h
 * @brief   header file of md_calc.c
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
#ifndef __MD_CALC_H__
#define __MD_CALC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_CALC CALC
  * @brief CALC micro driver
  * @{
  */

/** @defgroup MD_CALC_Public_Macros CALC Public Macros
  * @{
  */

#define MD_CALC_TRM_DIVDR   (0x00000000UL)
#define MD_CALC_TRM_DIVSR   (0x00000001UL)

#define MD_CALC_SIGN_USIGN   (0x00000000UL)
#define MD_CALC_SIGN_SIGN    (0x00000001UL)

#define MD_CALC_DZ_NONZERO   (0x00000000UL)
#define MD_CALC_DZ_ZERO      (0x00000001UL)

#define MD_CALC_BUSY_DONE     (0x00000000UL)
#define MD_CALC_BUSY_ONGOING  (0x00000001UL)

/**
  * @}
  */

/** @defgroup MD_CALC_Public_Functions CALC Public Functions
  * @{
  */

/** @defgroup MD_CALC_Public_Functions_Group2 DIVDR
  * @{
  */
/**
  * @brief  Set CALC_DIVDR Register
  * @note   This register is given the dividend of divider before calculation starting
  * @param  calc CALC Instance
  * @param  divdr
            @arg Max Value 0xffffffff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_calc_set_dividend(CALC_TypeDef *calc, uint32_t divdr)
{
    WRITE_REG(calc->DIVDR, divdr);
}

/**
  * @brief  Get CALC_DIVDR Register
  * @note   This register is given the dividend of divider before calculation starting
  * @param  calc CALC Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xffffffff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_calc_get_dividend(CALC_TypeDef *calc)
{
    return (uint32_t)(READ_REG(calc->DIVDR));
}
/**
  * @}
  */

/** @defgroup MD_CALC_Public_Functions_Group3 DIVSR
  * @{
  */
/**
  * @brief  Set CALC_DIVSR Register
  * @note   This register is given the divisor of divider before calculation starts
  * @param  calc CALC Instance
  * @param  divsr
            @arg Max Value 0xffffffff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_calc_set_divisor(CALC_TypeDef *calc, uint32_t divsr)
{
    WRITE_REG(calc->DIVSR, divsr);
}

/**
  * @brief  Get CALC_DIVSR Register
  * @note   This register is given the divisor of divider before calculation starts
  * @param  calc CALC Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xffffffff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_calc_get_divisor(CALC_TypeDef *calc)
{
    return (uint32_t)(READ_REG(calc->DIVSR));
}
/**
  * @}
  */

/** @defgroup MD_CALC_Public_Functions_Group4 DIVQR
  * @{
  */
/**
  * @brief  Get CALC_DIVQR Register
  * @note   This register holds the quotient result of divider after calculation complete
  * @param  calc CALC Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xffffffff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_calc_get_quotient(CALC_TypeDef *calc)
{
    return (uint32_t)(READ_REG(calc->DIVQR));
}
/**
  * @}
  */

/** @defgroup MD_CALC_Public_Functions_Group5 DIVRR
  * @{
  */
/**
  * @brief  Get CALC_DIVRR Register
  * @note   This register holds the remainder result of divider after calculation complete
  * @param  calc CALC Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xffffffff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_calc_get_remainder(CALC_TypeDef *calc)
{
    return (uint32_t)(READ_REG(calc->DIVRR));
}
/**
  * @}
  */

/** @defgroup MD_CALC_Public_Functions_Group6 DIVCON
  * @{
  */
/**
  * @brief  Set CALC_DIVCON Register
  * @note   Division Operation Control Register
  * @param  calc CALC Instance
  * @param  divcon
  * @retval None
  */
__STATIC_INLINE void md_calc_set_control(CALC_TypeDef *calc, uint32_t divcon)
{
    WRITE_REG(calc->DIVCON, divcon);
}

/**
  * @brief  Get CALC_DIVCON Register
  * @note   Division Operation Control Register
  * @param  calc CALC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_calc_get_control(CALC_TypeDef *calc)
{
    return (uint32_t)(READ_REG(calc->DIVCON));
}

/**
  * @brief  Set Division operation trigger mode selection
  * @param  calc CALC Instance
  * @param  trm trigger mode
            @arg @ref MD_CALC_TRM_DIVDR
            @arg @ref MD_CALC_TRM_DIVSR
  * @retval None
  */
__STATIC_INLINE void md_calc_set_trigger_mode(CALC_TypeDef *calc, uint32_t trm)
{
    MODIFY_REG(calc->DIVCON, CALC_DIVCON_TRM, trm << CALC_DIVCON_TRM_POS);
}

/**
  * @brief  Get Division operation trigger mode selection
  * @param  calc CALC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_CALC_TRM_DIVDR
            @arg @ref MD_CALC_TRM_DIVSR
  */
__STATIC_INLINE uint32_t md_calc_get_trigger_mode(CALC_TypeDef *calc)
{
    return (uint32_t)(READ_BIT(calc->DIVCON, CALC_DIVCON_TRM) >> CALC_DIVCON_TRM_POS);
}

/**
  * @brief  Set Division operation symbol selection
  * @param  calc CALC Instance
  * @param  sign Division operation
            @arg @ref MD_CALC_SIGN_USIGN
            @arg @ref MD_CALC_SIGN_SIGN
  * @retval None
  */
__STATIC_INLINE void md_calc_set_operation_mode(CALC_TypeDef *calc, uint32_t sign)
{
    MODIFY_REG(calc->DIVCON, CALC_DIVCON_SIGN, sign << CALC_DIVCON_SIGN_POS);
}

/**
  * @brief  Get Division operation symbol selection
  * @param  calc CALC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_CALC_SIGN_USIGN
            @arg @ref MD_CALC_SIGN_SIGN
  */
__STATIC_INLINE uint32_t md_calc_get_operation_mode(CALC_TypeDef *calc)
{
    return (uint32_t)(READ_BIT(calc->DIVCON, CALC_DIVCON_SIGN) >> CALC_DIVCON_SIGN_POS);
}
/**
  * @}
  */

/** @defgroup MD_CALC_Public_Functions_Group7 RDCND
  * @{
  */
/**
  * @brief  Set CALC_RDCND Register
  * @param  calc CALC Instance
  * @param  rdcnd Number of square roots
  * @retval None
  */
__STATIC_INLINE void md_calc_set_radicand(CALC_TypeDef *calc, uint32_t rdcnd)
{
    WRITE_REG(calc->RDCND, rdcnd);
}

/**
  * @brief  Get CALC_RDCND Register
  * @param  calc CALC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_calc_get_radicand(CALC_TypeDef *calc)
{
    return (uint32_t)(READ_REG(calc->RDCND));
}
/**
  * @}
  */

/** @defgroup MD_CALC_Public_Functions_Group8 SQRTRES
  * @{
  */
/**
  * @brief  Get CALC_SQRTRES RESULT
  * @note   Get Square root operation result value
  * @param  calc CALC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_calc_get_square_root(CALC_TypeDef *calc)
{
    return (uint32_t)(READ_REG(calc->SQRTRES));
}
/**
  * @}
  */

/** @defgroup MD_CALC_Public_Functions_Group9 STAT
  * @{
  */
/**
  * @brief  Get CALC_STAT Register
  * @note   CALC operation status register
  * @param  calc CALC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_calc_get_status(CALC_TypeDef *calc)
{
    return (uint32_t)(READ_REG(calc->STAT));
}

/**
  * @brief  Get CALC_STAT DZ
  * @note   Divide by zero warning
  * @param  calc CALC Instance
  * @retval The retval can be one of the following values:
  *         @arg MD_CALC_DZ_NONZERO
  *         @arg MD_CALC_DZ_NONZERO
  */
__STATIC_INLINE uint8_t md_calc_is_active_flag_divisor_zero(CALC_TypeDef *calc)
{
    return (READ_BIT(calc->STAT, CALC_STAT_DZ) == (CALC_STAT_DZ));
}

/**
  * @brief  Get CALC_STAT BUSY
  * @note   Operation status bit
  * @param  calc CALC Instance
  * @retval The retval can be one of the following values:
  *         @arg MD_CALC_BUSY_DONE
  *         @arg MD_CALC_BUSY_ONGOING
  */
__STATIC_INLINE uint8_t md_calc_is_active_flag_busy(CALC_TypeDef *calc)
{
    return (READ_BIT(calc->STAT, CALC_STAT_BUSY) == (CALC_STAT_BUSY));
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
