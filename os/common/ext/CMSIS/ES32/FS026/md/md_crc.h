/**********************************************************************************
 *
 * @file    md_crc.h
 * @brief   header file of md_crc.c
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
#ifndef __MD_CRC_H__
#define __MD_CRC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_CRC CRC
  * @brief CRC micro driver
  * @{
  */

/** @defgroup MD_CRC_Pubulic_Types CRC Pubulic Types
  * @{
  */

/**
  * @brief CRC init structure
  */
typedef struct
{
    uint32_t xorout;
    uint32_t refout;
    uint32_t refin;
    uint32_t byte;
    uint32_t mode;
    uint32_t req;
    uint32_t ds;
    uint32_t rst;
} md_crc_init_typedef;
/**
  * @}
  */

/** @defgroup MD_CRC_Public_Macros CRC Public Macros
  * @{
  */
#define MD_CRC_CON_MSB_ON             (1) /*!<  User can set this bit to change the 'byte' order of input data.     */
#define MD_CRC_CON_MSB_OFF            (0) /*!<  User can set this bit to change the 'byte' order of input data.     */

#define MD_CRC_CON_SIZE_POLY32        (0) /*!<  This allow user to select polynomial size.                          */
#define MD_CRC_CON_SIZE_POLY16        (1) /*!<  This allow user to select polynomial size.                          */
#define MD_CRC_CON_SIZE_POLY8         (2) /*!<  This allow user to select polynomial size.                          */

#define MD_CRC_CON_MODE_COMP_DISABLE  (0) /*!<  This allow user to check CRC result.                                */
#define MD_CRC_CON_MODE_COMP_ZERO     (1) /*!<  This allow user to check CRC result.                                */
#define MD_CRC_CON_MODE_COMP_ENABLE   (2) /*!<  This allow user to check CRC result.                                */

#define MD_CRC_CON_RESET  1               /*!<  User can set this bit to reset CRC function.                        */
/**
  * @}
  */

/** @defgroup MD_CRC_Public_Functions CRC Public Functions
  * @{
  */

/** @defgroup MD_CRC_Public_Functions_Group2 INIT
  * @{
  */
/**
  * @brief  This register is used to write the CRC initial data.
  * @param  CRC Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x00000000
  *         @arg Maximum 0xFFFFFFFF
  * @retval None.
  */
__STATIC_INLINE void md_crc_set_initial_data(CRC_TypeDef *crc, uint32_t value)
{
    WRITE_REG(crc->INIT, value);
}

/**
  * @brief  This register is used to read the CRC initial data.
  * @param  CRC Instance
  * @retval value 0x00000000 ~ 0xffffffff.
  */
__STATIC_INLINE uint32_t md_crc_get_initial_data(CRC_TypeDef *crc)
{
    return (uint32_t)(READ_REG(crc->INIT));
}
/**
  * @}
  */

/** @defgroup MD_CRC_Public_Functions_Group3 POLY
  * @{
  */
/**
  * @brief  This register is used to write the coefficient of the CRC polynomial. Default coefficient is for CRC32.
  * @param  CRC Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x00000000
  *         @arg Maximum 0xFFFFFFFF
  * @retval None.
  */
__STATIC_INLINE void md_crc_set_polynomial_coef(CRC_TypeDef *crc, uint32_t value)
{
    WRITE_REG(crc->POLY, value);
}

/**
  * @brief  This register is used to read the coefficient of the CRC polynomial. Default coefficient is for CRC32.
  * @param  CRC Instance
  * @retval value 0x00000000 ~ 0xffffffff.
  */
__STATIC_INLINE uint32_t md_crc_get_polynomial_coef(CRC_TypeDef *crc)
{
    return (uint32_t)(READ_REG(crc->POLY));
}
/**
  * @}
  */

/** @defgroup MD_CRC_Public_Functions_Group4 DATA
  * @{
  */
/**
  * @brief  This register is used to write word CRC input data. CRC will start to calculate result after this register is written.
  * @param  CRC Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x00000000
  *         @arg Maximum 0xFFFFFFFF
  * @retval None.
  */
__STATIC_INLINE void md_crc_set_input_data32(CRC_TypeDef *crc, uint32_t value)
{
    WRITE_REG(crc->DATA, value);
}

/**
  * @brief  This register is used to read word CRC input data. CRC will start to calculate result after this register is written.
  * @param  CRC Instance
  * @retval value 0x00000000 ~ 0xffffffff.
  */
__STATIC_INLINE uint32_t md_crc_get_input_data32(CRC_TypeDef *crc)
{
    return (uint32_t)(READ_REG(crc->DATA));
}

/**
  * @brief  This register is used to write half word CRC input data. CRC will start to calculate result after this register is written.
  * @param  CRC Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x0000
  *         @arg Maximum 0xFFFF
  * @retval None.
  */
__STATIC_INLINE void md_crc_set_input_data16(CRC_TypeDef *crc, uint16_t value)
{
    //In order to write after conversion
    WRITE_REG(*(uint16_t *) & (crc->DATA), value);
}

/**
  * @brief  This register is used to read half word CRC input data. CRC will start to calculate result after this register is written.
  * @param  CRC Instance
  * @retval value 0x0000 ~ 0xffff.
  */
__STATIC_INLINE uint16_t md_crc_get_input_data16(CRC_TypeDef *crc)
{
    return (uint16_t)(READ_REG(crc->DATA));
}

/**
  * @brief  This register is used to write byte CRC input data. CRC will start to calculate result after this register is written.
  * @param  CRC Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x00
  *         @arg Maximum 0xFF
  * @retval None.
  */
__STATIC_INLINE void md_crc_set_input_data8(CRC_TypeDef *crc, uint8_t value)
{
    //In order to write after conversion
    WRITE_REG(*(uint8_t *) & (crc->DATA), value);
}

/**
  * @brief  This register is used to read byte CRC input data. CRC will start to calculate result after this register is written.
  * @param  CRC Instance
  * @retval value 0x00 ~ 0xff.
  */
__STATIC_INLINE uint8_t md_crc_get_input_data8(CRC_TypeDef *crc)
{
    return (uint8_t)(READ_REG(crc->DATA));
}
/**
  * @}
  */

/** @defgroup MD_CRC_Public_Functions_Group5 COMP
  * @{
  */
/**
  * @brief  This register is used to compare with the CRC output data.
  * @param  CRC Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x00000000
  *         @arg Maximum 0xFFFFFFFF
  * @retval None.
  */
__STATIC_INLINE void md_crc_set_compare_data(CRC_TypeDef *crc, uint32_t value)
{
    WRITE_REG(crc->COMP, value);
}

/**
  * @brief  This register is used to compare with the CRC output data.
  * @param  CRC Instance
  * @retval value 0x00000000 ~ 0xffffffff.
  */
__STATIC_INLINE uint32_t md_crc_get_compare_data(CRC_TypeDef *crc)
{
    return (uint32_t)(READ_REG(crc->COMP));
}
/**
  * @}
  */

/** @defgroup MD_CRC_Public_Functions_Group6 REMA
  * @{
  */
/**
  * @brief  This register is used to set a parameter to do exclusive OR with CRC output data.
  * @param  CRC Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x00000000
  *         @arg Maximum 0xFFFFFFFF
  * @retval None.
  */
__STATIC_INLINE void md_crc_set_remainder_data(CRC_TypeDef *crc, uint32_t value)
{
    WRITE_REG(crc->REMA, value);
}

/**
  * @brief  This register is used to set a parameter to do exclusive OR with CRC output data.
  * @param  CRC Instance
  * @retval value 0x00000000 ~ 0xffffffff.
  */
__STATIC_INLINE uint32_t md_crc_get_remainder_data(CRC_TypeDef *crc)
{
    return (uint32_t)(READ_REG(crc->REMA));
}
/**
  * @}
  */

/** @defgroup MD_CRC_Public_Functions_Group7 CON
  * @{
  */
/**
  * @brief  This register is used to set a parameter.
  * @param  CRC Instance
  * @param  value
  * @retval None.
  */
__STATIC_INLINE void md_crc_set_control(CRC_TypeDef *crc, uint32_t value)
{
    WRITE_REG(crc->CON, value);
}

/**
  * @brief  This register is used to get a parameter.
  * @param  CRC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_crc_get_control(CRC_TypeDef *crc)
{
    return (uint32_t)READ_REG(READ_REG(crc->CON));
}

/**
  * @brief  This function allow user to enable DMA function enable.
  * @param  CRC Instance
  * @retval None.
  */
__STATIC_INLINE void md_crc_enable_dma(CRC_TypeDef *crc)
{
    SET_BIT(crc->CON, CRC_CON_DMA);
}

/**
  * @brief  This function allow user to enable DMA function disable.
  * @param  CRC Instance
  * @retval None.
  */
__STATIC_INLINE void md_crc_disable_dma(CRC_TypeDef *crc)
{
    CLEAR_BIT(crc->CON, CRC_CON_DMA);
}

/**
  * @brief  This function allow user to enable DMA function.
  * @param  CRC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_crc_is_enabled_dma(CRC_TypeDef *crc)
{
    return (READ_BIT(crc->CON, CRC_CON_DMA) == (CRC_CON_DMA));
}

/**
  * @brief  User can set this bit to change the 'byte' order of input data.
  * @param  CRC Instance
  * @param  value This parameter can be one of the following values:
  *         @arg @ref MD_CRC_CON_MSB_ON
  *         @arg @ref MD_CRC_CON_MSB_OFF
  * @retval None.
  */
__STATIC_INLINE void md_crc_set_input_data_msb(CRC_TypeDef *crc, uint32_t value)
{
    MODIFY_REG(crc->CON, CRC_CON_MSB, value << CRC_CON_MSB_POS);
}

/**
  * @brief  User can set this bit to change the 'byte' order of input data.
  * @param  CRC Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_CRC_CON_MSB_ON
  *         @arg @ref MD_CRC_CON_MSB_OFF
  */
__STATIC_INLINE uint32_t md_crc_get_input_data_msb(CRC_TypeDef *crc)
{
    return (uint32_t)(READ_BIT(crc->CON, CRC_CON_MSB) >> CRC_CON_MSB_POS);
}

/**
  * @brief  This function allow user to reverse the order of CRC output data enable.
  * @param  CRC Instance
  * @retval None.
  */
__STATIC_INLINE void md_crc_enable_output_data_reverse(CRC_TypeDef *crc)
{
    SET_BIT(crc->CON, CRC_CON_REOUT);
}

/**
  * @brief  This function allow user to reverse the order of CRC output data disable.
  * @param  CRC Instance
  * @retval None.
  */
__STATIC_INLINE void md_crc_disable_output_data_reverse(CRC_TypeDef *crc)
{
    CLEAR_BIT(crc->CON, CRC_CON_REOUT);
}

/**
  * @brief  This function allow user to reverse the order of CRC output data.
  * @param  CRC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_crc_is_enabled_output_data_reverse(CRC_TypeDef *crc)
{
    return (READ_BIT(crc->CON, CRC_CON_REOUT) == (CRC_CON_REOUT));
}

/**
  * @brief  This function allow user to reverse the order of CRC input data enable.
  * @param  CRC Instance
  * @retval None.
  */
__STATIC_INLINE void md_crc_enable_input_data_reverse(CRC_TypeDef *crc)
{
    SET_BIT(crc->CON, CRC_CON_REIN);
}

/**
  * @brief  This function allow user to reverse the order of CRC input data disable.
  * @param  CRC Instance
  * @retval None.
  */
__STATIC_INLINE void md_crc_disable_input_data_reverse(CRC_TypeDef *crc)
{
    CLEAR_BIT(crc->CON, CRC_CON_REIN);
}

/**
  * @brief  User can set this bit to change the 'byte' order of input data.
  * @param  CRC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_crc_is_enabled_input_data_reverse(CRC_TypeDef *crc)
{
    return ((READ_BIT(crc->CON, CRC_CON_REIN) == (CRC_CON_REIN)));
}

/**
  * @brief  User can set this bit to change the 'byte' order of input data.
  * @param  CRC Instance
  * @param  value This parameter can be one of the following values:
  *         @arg @ref MD_CRC_CON_SIZE_POLY32
  *         @arg @ref MD_CRC_CON_SIZE_POLY16
  *         @arg @ref MD_CRC_CON_SIZE_POLY8
  * @retval None.
  */
__STATIC_INLINE void md_crc_set_polynomial_size(CRC_TypeDef *crc, uint32_t value)
{
    MODIFY_REG(crc->CON, CRC_CON_SIZE, value << CRC_CON_SIZE_POSS);
}

/**
  * @brief  User can set this bit to change the 'byte' order of input data.
  * @param  CRC Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_CRC_CON_SIZE_POLY32
  *         @arg @ref MD_CRC_CON_SIZE_POLY16
  *         @arg @ref MD_CRC_CON_SIZE_POLY8
  */
__STATIC_INLINE uint32_t md_crc_get_polynomial_size(CRC_TypeDef *crc)
{
    return (uint32_t)(READ_BIT(crc->CON, CRC_CON_SIZE) >> CRC_CON_SIZE_POSS);
}

/**
  * @brief  This function allow user to check CRC result. If CRC result is not correct, the status “FAIL” in CRC_STA will be set to 1.
  * @param  CRC Instance
  * @param  value This parameter can be one of the following values:
  *         @arg @ref MD_CRC_CON_MODE_COMP_DISABLE
  *         @arg @ref MD_CRC_CON_MODE_COMP_ZERO
  *         @arg @ref MD_CRC_CON_MODE_COMP_ENABLE
  * @retval None.
  */
__STATIC_INLINE void md_crc_set_compare_mode(CRC_TypeDef *crc, uint32_t value)
{
    MODIFY_REG(crc->CON, CRC_CON_MODE, value << CRC_CON_MODE_POSS);
}

/**
  * @brief  This function allow user to check CRC result. If CRC result is not correct, the status “FAIL” in CRC_STA will be set to 1.
  * @param  CRC Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_CRC_CON_MODE_COMP_DISABLE
  *         @arg @ref MD_CRC_CON_MODE_COMP_ZERO
  *         @arg @ref MD_CRC_CON_MODE_COMP_ENABLE
  */
__STATIC_INLINE uint32_t md_crc_get_compare_mode(CRC_TypeDef *crc)
{
    return (uint32_t)(READ_BIT(crc->CON, CRC_CON_MODE) >> CRC_CON_MODE_POSS);
}

/**
  * @brief  User can set this bit to reset CRC function. This bit will be cleared by itself.
  * @param  CRC Instance
  * @retval None.
  */
__STATIC_INLINE void md_crc_trigger_reset(CRC_TypeDef *crc)
{
    SET_BIT(crc->CON, CRC_CON_RESET);
}
/**
  * @}
  */

/** @defgroup MD_CRC_Public_Functions_Group8 DOUT
  * @{
  */
/**
  * @brief  This register is used to show the CRC calculation result.
  * @param  CRC Instance
  * @retval value: 0x00000000 ~ 0xffffffff.
  */
__STATIC_INLINE uint32_t md_crc_get_output_data(CRC_TypeDef *crc)
{
    return (uint32_t)(READ_REG(crc->DOUT));
}
/**
  * @}
  */

/** @defgroup MD_CRC_Public_Functions_Group9 DOUT_XOR
  * @{
  */
/**
  * @brief  This register is used to show the CRC calculation exculsive OR result.
  * @param  CRC Instance
  * @retval value: 0x00000000 ~ 0xffffffff.
  */
__STATIC_INLINE uint32_t md_crc_get_output_data_xor(CRC_TypeDef *crc)
{
    return (uint32_t)(READ_REG(crc->DOUT_XOR));
}
/**
  * @}
  */

/** @defgroup MD_CRC_Public_Functions_Group10 STAT
  * @{
  */
/**
  * @brief  This register is used to show the CRC calculation exculsive OR result.
  * @param  CRC Instance
  * @retval value: 0x00000000 ~ 0xffffffff.
  */
__STATIC_INLINE uint32_t md_crc_get_status(CRC_TypeDef *crc)
{
    return (uint32_t)(READ_REG(crc->STAT));
}

/**
  * @brief  This bit is set when CRC result is not correct.
  * @param  CRC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_crc_is_active_flag_compare_fail(CRC_TypeDef *crc)
{
    return (READ_BIT(crc->STAT, CRC_STAT_FAIL) == (CRC_STAT_FAIL));
}

/**
  * @brief  This bit is cleaned after an CRC calculation.
  * @param  CRC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_crc_is_active_flag_empty(CRC_TypeDef *crc)
{
    return (READ_BIT(crc->STAT, CRC_STAT_EMPTY) == (CRC_STAT_EMPTY));
}

/**
  * @brief  This bit is set when CRC module is calculating result.
  * @param  CRC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_crc_is_active_flag_busy(CRC_TypeDef *crc)
{
    return (READ_BIT(crc->STAT, CRC_STAT_BUSY) == (CRC_STAT_BUSY));
}

/**
  * @brief  This bit is set when CRC module is calculating result.
  * @param  CRC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_crc_is_active_flag_done(CRC_TypeDef *crc)
{
    return (READ_BIT(crc->STAT, CRC_STAT_DONE) == (CRC_STAT_DONE));
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
