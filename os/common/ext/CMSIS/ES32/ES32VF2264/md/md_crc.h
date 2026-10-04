/**********************************************************************************
 *
 * @file    md_crc.h
 * @brief   Header file of CRC module driver.
 *
 * @date    20 July 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          20 July 2022    Lisq            the first version
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


#ifndef __MD_CRC_H__
#define __MD_CRC_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------ */
#include "md_utils.h"

/* Exported Constants -------------------------------------------------------- */

/* Exported Variables -------------------------------------------------------- */

/* Exported Types ------------------------------------------------------------ */

/** @addtogroup Micro_Driver
  * @{
  */
/** @defgroup MD_CRC CRC
  * @brief CRC micro driver
  * @{
  */
/**
  * @defgroup MD_CRC_Public_Macros CRC Public Macros
  * @{
  */
/**
  * @brief CRC check byte order select
  */
typedef enum
{
    MD_CRC_BYTORD_LOW  = 0x0U,  /**< LSB first */
    MD_CRC_BYTORD_HIGH = 0x1U,  /**< MSB first */
} md_crc_bytord_t;

/**
  * @brief CRC data length select
  */
typedef enum
{
    MD_CRC_LEN_AUTO    = 0x0U,  /**< Auto */
    MD_CRC_DATASIZE_8  = 0x1U,  /**< Byte */
    MD_CRC_DATASIZE_16 = 0x2U,  /**< Half word */
    MD_CRC_DATASIZE_32 = 0x3U,  /**< Word */
} md_crc_data_bits_t;
/**
  * @brief CRC Mode
  */
typedef enum
{
    MD_CRC_MODE_CCITT = 0x0U,   /**< CRC-CCITT */
    MD_CRC_MODE_8     = 0x1U,   /**< CRC-8 */
    MD_CRC_MODE_16    = 0x2U,   /**< CRC-16 */
    MD_CRC_MODE_32    = 0x3U,   /**< CRC-32 */
} md_crc_mode_t;
/**
  * @}
  */
/**
  * @defgroup MD_CRC_Public_Types CRC Public Types
  * @{
  */
/**
  * @brief CRC init structure definition
  */
typedef struct
{
    md_crc_mode_t mode; /**< CRC mode */
    md_crc_data_bits_t len; /**< Data length */
    md_crc_bytord_t order;  /**< Byte order for checking */
    type_func_t data_rev;   /**< CRC data reverse or no */
    type_func_t data_inv;   /**< CRC data inverse or no */
    type_func_t chs_rev;    /**< CRC check sum reverse or no */
    type_func_t chs_inv;    /**< CRC check sum inverse or no */
    uint32_t seed;      /**< CRC seed */
} md_crc_init_t;
/**
  * @}
  */

/* Exported Macros ----------------------------------------------------------- */

/** @defgroup MD_CRC_Public_Macros CRC Public Macros
  * @{
  */
#define MD_CRC_ENABLE()         (SET_BIT(CRC->CR, CRC_CR_EN_MSK))
#define MD_CRC_DISABLE()        (CLEAR_BIT(CRC->CR, CRC_CR_EN_MSK))
#define MD_CRC_RESET()          (SET_BIT(CRC->CR, CRC_CR_RST_MSK))
#define MD_CRC_DMA_ENABLE()         (SET_BIT(CRC->CR, CRC_CR_DMAEN_MSK))
#define MD_CRC_DMA_DISABLE()        (CLEAR_BIT(CRC->CR, CRC_CR_DMAEN_MSK))
#define MD_CRC_CLEAR_ERROR_FLAG()   (SET_BIT(CRC->CR, CRC_CR_WERR_MSK))
/**
  * @}
  */

/* Exported Functions -------------------------------------------------------- */

/** @defgroup MD_CRC_Public_Functions CRC Public Functions
  * @{
  */
/** @defgroup MD_CRC_Public_Functions_Group2 CR
  * @{
  */
/**
  * @brief  CRC Enable
  * @param  CRCx: CRC Peripheral
  * @retval NONE
  */
__STATIC_INLINE void md_crc_enable(CRC_TypeDef *CRCx)
{
    SET_BIT(CRCx->CR, CRC_CR_EN_MSK);
}

/**
  * @brief  CRC Disable
  * @param  CRCx: CRC Peripheral
  * @retval NONE
  */
__STATIC_INLINE void md_crc_disable(CRC_TypeDef *CRCx)
{
    CLEAR_BIT(CRCx->CR, CRC_CR_EN_MSK);
}

/**
  * @brief  Indicate if CRC is enabled
  * @param  CRCx: CRC Peripheral
  * @retval State.
  */
__STATIC_INLINE uint32_t md_crc_is_enabled(CRC_TypeDef *CRCx)
{
    return (READ_BIT(CRCx->CR, CRC_CR_EN_MSK) == (CRC_CR_EN_MSK));
}

/**
  * @brief  Reset CRC
  * @param  CRCx: CRC Peripheral
  * @retval NONE
  */
__STATIC_INLINE void md_crc_reset(CRC_TypeDef *CRCx)
{
    SET_BIT(CRCx->CR, CRC_CR_RST_MSK);
}

/**
  * @brief  Indicate if the CRC write data error flag is set or not
  * @param  CRCx: CRC Peripheral
  * @retval State.
  */
__STATIC_INLINE uint32_t md_crc_get_flag_error(CRC_TypeDef *CRCx)
{
    return (READ_BIT(CRCx->CR, CRC_CR_WERR_MSK) == (CRC_CR_WERR_MSK));
}

/**
  * @brief  Clear CRC write data error flag
  * @param  CRCx: CRC Peripheral
  * @retval NONE
  */
__STATIC_INLINE void md_crc_clear_flag_error(CRC_TypeDef *CRCx)
{
    SET_BIT(CRCx->CR, CRC_CR_CWERR_MSK);
}

/**
  * @brief  CRC DMA Enable
  * @param  CRCx: CRC Peripheral
  * @retval NONE
  */
__STATIC_INLINE void md_crc_enable_dma(CRC_TypeDef *CRCx)
{
    SET_BIT(CRCx->CR, CRC_CR_DMAEN_MSK);
}

/**
  * @brief  CRC DMA Disable
  * @param  CRCx: CRC Peripheral
  * @retval NONE
  */
__STATIC_INLINE void md_crc_disable_dma(CRC_TypeDef *CRCx)
{
    CLEAR_BIT(CRCx->CR, CRC_CR_DMAEN_MSK);
}

/**
  * @brief  Indicate if CRC DMA is enabled
  * @param  CRCx: CRC Peripheral
  * @retval State.
  */
__STATIC_INLINE uint32_t md_crc_is_enabled_dma(CRC_TypeDef *CRCx)
{
    return (READ_BIT(CRCx->CR, CRC_CR_DMAEN_MSK) == (CRC_CR_DMAEN_MSK));
}

/**
  * @brief  CRC write data reverse  Enable
  * @param  CRCx: CRC Peripheral
  * @retval NONE
  */
__STATIC_INLINE void md_crc_enable_data_reverse(CRC_TypeDef *CRCx)
{
    SET_BIT(CRCx->CR, CRC_CR_DATREV_MSK);
}

/**
  * @brief  CRC write data reverse Disable
  * @param  CRCx: CRC Peripheral
  * @retval NONE
  */
__STATIC_INLINE void md_crc_disable_data_reverse(CRC_TypeDef *CRCx)
{
    CLEAR_BIT(CRCx->CR, CRC_CR_DATREV_MSK);
}

/**
  * @brief  Indicate if CRC write data reverse is enabled
  * @param  CRCx: CRC Peripheral
  * @retval State.
  */
__STATIC_INLINE uint32_t md_crc_is_enabled_data_reverse_(CRC_TypeDef *CRCx)
{
    return (READ_BIT(CRCx->CR, CRC_CR_DATREV_MSK) == (CRC_CR_DATREV_MSK));
}

/**
  * @brief  CRC checksum reverse Enable
  * @param  CRCx: CRC Peripheral
  * @retval NONE
  */
__STATIC_INLINE void md_crc_enable_result_reverse(CRC_TypeDef *CRCx)
{
    SET_BIT(CRCx->CR, CRC_CR_CHSREV_MSK);
}

/**
  * @brief  CRC checksum reverse Disable
  * @param  CRCx: CRC Peripheral
  * @retval NONE
  */
__STATIC_INLINE void md_crc_disable_result_reverse(CRC_TypeDef *CRCx)
{
    CLEAR_BIT(CRCx->CR, CRC_CR_CHSREV_MSK);
}

/**
  * @brief  Indicate if CRC checksum reverse is enabled
  * @param  CRCx: CRC Peripheral
  * @retval State.
  */
__STATIC_INLINE uint32_t md_crc_is_enabled_result_reverse(CRC_TypeDef *CRCx)
{
    return (READ_BIT(CRCx->CR, CRC_CR_CHSREV_MSK) == (CRC_CR_CHSREV_MSK));
}

/**
  * @brief  CRC write data invert Enable
  * @param  CRCx: CRC Peripheral
  * @retval NONE
  */
__STATIC_INLINE void md_crc_enable_data_invert(CRC_TypeDef *CRCx)
{
    SET_BIT(CRCx->CR, CRC_CR_DATINV_MSK);
}

/**
  * @brief  CRC data invert Disable
  * @param  CRCx: CRC Peripheral
  * @retval NONE
  */
__STATIC_INLINE void md_crc_disable_data_invert(CRC_TypeDef *CRCx)
{
    CLEAR_BIT(CRCx->CR, CRC_CR_DATINV_MSK);
}

/**
  * @brief  Indicate if CRC data invert is enabled
  * @param  CRCx: CRC Peripheral
  * @retval State.
  */
__STATIC_INLINE uint32_t md_crc_is_enabled_data_invert(CRC_TypeDef *CRCx)
{
    return (READ_BIT(CRCx->CR, CRC_CR_DATINV_MSK) == (CRC_CR_DATINV_MSK));
}

/**
  * @brief  CRC checksum invert  Enable
  * @param  CRCx: CRC Peripheral
  * @retval NONE
  */
__STATIC_INLINE void md_crc_enable_result_invert(CRC_TypeDef *CRCx)
{
    SET_BIT(CRCx->CR, CRC_CR_CHSINV_MSK);
}

/**
  * @brief  CRC checksum invert Disable
  * @param  CRCx: CRC Peripheral
  * @retval NONE
  */
__STATIC_INLINE void md_crc_disable_result_invert(CRC_TypeDef *CRCx)
{
    CLEAR_BIT(CRCx->CR, CRC_CR_CHSINV_MSK);
}

/**
  * @brief  Indicate if CRC checksum invert is enabled
  * @param  CRCx: CRC Peripheral
  * @retval State.
  */
__STATIC_INLINE uint32_t md_crc_is_enabled_result_invert(CRC_TypeDef *CRCx)
{
    return (READ_BIT(CRCx->CR, CRC_CR_CHSINV_MSK) == (CRC_CR_CHSINV_MSK));
}

/**
  * @brief  Set the mode of CRC
  * @param  CRCx: CRC Peripheral
  * @param  mode This parameter can be one of the following values:
  *         @arg @ref MD_CRC_MODE_CCITT
  *         @arg @ref MD_CRC_MODE_8
  *         @arg @ref MD_CRC_MODE_16
  *         @arg @ref MD_CRC_MODE_32
  * @retval NONE
  */
__STATIC_INLINE void md_crc_set_mode(CRC_TypeDef *CRCx, uint32_t mode)
{
    MODIFY_REG(CRCx->CR, CRC_CR_MODE_MSK, mode << CRC_CR_MODE_POSS);
}

/**
  * @brief  Get the mode of CRC
  * @param  CRCx: CRC Peripheral
  * @retval Returned value can be one of the following values:
  *         @arg @ref MD_CRC_MODE_CCITT
  *         @arg @ref MD_CRC_MODE_8
  *         @arg @ref MD_CRC_MODE_16
  *         @arg @ref MD_CRC_MODE_32
  */
__STATIC_INLINE uint32_t md_crc_get_mode(CRC_TypeDef *CRCx)
{
    return (READ_BITS(CRCx->CR, CRC_CR_MODE_MSK, CRC_CR_MODE_POSS));
}

/**
  * @brief  Set the data length of CRC
  * @param  CRCx: CRC Peripheral
  * @param  data_bits This parameter can be one of the following values:
  *         @arg @ref MD_CRC_LEN_AUTO
  *         @arg @ref MD_CRC_DATASIZE_8
  *         @arg @ref MD_CRC_DATASIZE_16
  *         @arg @ref MD_CRC_DATASIZE_32
  * @retval NONE
  */
__STATIC_INLINE void md_crc_set_data_bits(CRC_TypeDef *CRCx, uint32_t data_bits)
{
    MODIFY_REG(CRCx->CR, CRC_CR_DATLEN_MSK, data_bits << CRC_CR_DATLEN_POSS);
}

/**
  * @brief  Get the data length of CRC
  * @param  CRCx: CRC Peripheral
  * @retval Returned value can be one of the following values:
  *         @arg @ref MD_CRC_LEN_AUTO
  *         @arg @ref MD_CRC_DATASIZE_8
  *         @arg @ref MD_CRC_DATASIZE_16
  *         @arg @ref MD_CRC_DATASIZE_32
  */
__STATIC_INLINE uint32_t md_crc_get_data_bits(CRC_TypeDef *CRCx)
{
    return (READ_BITS(CRCx->CR, CRC_CR_DATLEN_MSK, CRC_CR_DATLEN_POSS));
}

/**
  * @brief  Set the check byte order of CRC
  * @param  CRCx: CRC Peripheral
  * @param  order This parameter can be one of the following values:
  *         @arg @ref MD_CRC_BYTORD_LOW
  *         @arg @ref MD_CRC_BYTORD_HIGH
  * @retval NONE
  */
__STATIC_INLINE void md_crc_set_check_order(CRC_TypeDef *CRCx, uint32_t order)
{
    MODIFY_REG(CRCx->CR, CRC_CR_BYTORD_MSK, order << CRC_CR_BYTORD_POS);
}

/**
  * @brief  Get the checksum byte order of CRC
  * @param  CRCx: CRC Peripheral
  * @retval Returned value can be one of the following values:
  *         @arg @ref MD_CRC_BYTORD_LOW
  *         @arg @ref MD_CRC_BYTORD_HIGH
  */
__STATIC_INLINE uint32_t md_crc_get_check_order(CRC_TypeDef *CRCx)
{
    return (READ_BITS(CRCx->CR, CRC_CR_BYTORD_MSK, CRC_CR_BYTORD_POS));
}
/**
  * @}
  */
/** @defgroup MD_CRC_Public_Functions_Group3 DATA
  * @{
  */
/**
  * @brief  write data of CRC
  * @param  CRCx: CRC Peripheral
  * @param  data: Original data
  * @retval NONE
  */
__STATIC_INLINE void md_crc_write_data(CRC_TypeDef *CRCx, uint32_t data)
{
    WRITE_REG(CRCx->DATA, data);
}

/**
  * @brief  Get the original data of CRC
  * @param  CRCx: CRC Peripheral
  * @retval writed data
  */
__STATIC_INLINE uint32_t md_crc_get_original_data(CRC_TypeDef *CRCx)
{
    return READ_REG(CRCx->DATA);
}
/**
  * @}
  */
/** @defgroup MD_CRC_Public_Functions_Group4 SEED
  * @{
  */
/**
  * @brief  Set the seed of CRC
  * @param  CRCx: CRC Peripheral
  * @param  seed: This parameter can be 0~0xFFFFFFFF
  * @retval NONE
  */
__STATIC_INLINE void md_crc_set_seed(CRC_TypeDef *CRCx, uint32_t seed)
{
    WRITE_REG(CRCx->SEED, seed);
}

/**
  * @brief  Get the seed of CRC
  * @param  CRCx: CRC Peripheral
  * @retval seed
  */
__STATIC_INLINE uint32_t md_crc_get_seed(CRC_TypeDef *CRCx)
{
    return READ_REG(CRCx->SEED);
}
/**
  * @}
  */
/** @defgroup MD_CRC_Public_Functions_Group5 CHECKSUM
  * @{
  */
/**
  * @brief  Get the CRC check result
  * @param  CRCx: CRC Peripheral
  * @retval CRC check result
  */
__STATIC_INLINE uint32_t md_crc_get_check_result(CRC_TypeDef *CRCx)
{
    return READ_REG(CRCx->CHECKSUM);
}
/**
  * @}
  */
/** @addtogroup MD_CRC_Public_Functions_Group1
  * @{
  */

extern void md_crc_reset_reg(void);
extern void md_crc_init(md_crc_init_t *init);
extern void md_crc_init_struct(md_crc_init_t *init);

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
#endif /* __MD_CRC_H__ */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
