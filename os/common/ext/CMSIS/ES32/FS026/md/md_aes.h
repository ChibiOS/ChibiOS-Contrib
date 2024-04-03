/**********************************************************************************
 *
 * @file    md_aes.h
 * @brief   header file of md_aes.c
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov 2021     Ginger          the first version
 *          28 Mar 2022     AE Team         Modify MD Driver
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
#ifndef __MD_AES_H__
#define __MD_AES_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_AES AES
  * @brief AES micro driver
  * @{
  */

/** @defgroup MD_AES_Pubulic_Types AES Pubulic Types
  * @{
  */

/**
  * @brief  MD_AES_INIT AES init structure
  * @
  */
typedef struct
{
    volatile uint8_t aes_ctrl_bl;
    volatile uint8_t aes_ctrl_mode;
    volatile uint32_t aes_key[4];
    volatile uint32_t aes_iv[4];
    volatile uint32_t aes_din[4];
    volatile uint32_t aes_dout[4];
} md_aes_init_typedef;
/**
  * @}
  */

/** @defgroup MD_AES_Public_Macros AES Public Macros
  * @{
  */

#define MD_AES_CON_READY_BUSY             (0) /*!<  This allow user to read AES Encryption/Decryption Ready Status.       */
#define MD_AES_CON_READY_READY            (1) /*!<  This allow user to read AES Encryption/Decryption Ready Status.       */

#define MD_AES_CON_OT_DEPTH_0             (0) /*!<  This allow user to read AES DIO data depth status (X=0).              */
#define MD_AES_CON_OT_DEPTH_1             (1) /*!<  This allow user to read AES DIO data depth status (X=1).              */
#define MD_AES_CON_OT_DEPTH_2             (2) /*!<  This allow user to read AES DIO data depth status (X=2).              */
#define MD_AES_CON_OT_DEPTH_3             (3) /*!<  This allow user to read AES DIO data depth status (X=3).              */

#define MD_AES_CON_IT_DEPTH_0             (0) /*!<  This allow user to read AES DIO data depth status (X=0).              */
#define MD_AES_CON_IT_DEPTH_1             (1) /*!<  This allow user to read AES DIO data depth status (X=1).              */
#define MD_AES_CON_IT_DEPTH_2             (2) /*!<  This allow user to read AES DIO data depth status (X=2).              */
#define MD_AES_CON_IT_DEPTH_3             (3) /*!<  This allow user to read AES DIO data depth status (X=3).              */

#define MD_AES_CON_DMA_EN_INPUT_ENABLE    ((1 << 0)) /*!<  This allow user to set AES DMA Function Enable. 0:AES input DMA disable   */
#define MD_AES_CON_DMA_EN_INPUT_DISABLE   ((0 << 0)) /*!<  This allow user to set AES DMA Function Enable. 1:AES input DMA enable    */

#define MD_AES_CON_DMA_EN_OUTPUT_ENABLE   ((1 << 1)) /*!<  This allow user to set AES DMA Function Enable. 0:AES output DMA disable */
#define MD_AES_CON_DMA_EN_OUTPUT_DISABLE  ((0 << 1)) /*!<  This allow user to set AES DMA Function Enable. 1:AES outut DMA enable    */

#define MD_AES_CON_BL_CBC                 (0) /*!<  This allow user to set Block Cipher Encryption / Decryption Mode. 000:CBC      */
#define MD_AES_CON_BL_CFB                 (1) /*!<  This allow user to set Block Cipher Encryption / Decryption Mode. 001:CFB      */
#define MD_AES_CON_BL_OFB                 (2) /*!<  This allow user to set Block Cipher Encryption / Decryption Mode. 010:OFB      */
#define MD_AES_CON_BL_CTR                 (3) /*!<  This allow user to set Block Cipher Encryption / Decryption Mode. 011:CTR      */
#define MD_AES_CON_BL_ECB                 (4) /*!<  This allow user to set Block Cipher Encryption / Decryption Mode. 100:ECB      */
#define MD_AES_CON_BL_GCM                 (5) /*!<  This allow user to set Block Cipher Encryption / Decryption Mode. 101:GCM      */

#define MD_AES_CON_MODE_ENCRYPT           (0) /*!<  This allow user to set AES Mode Control. 0:Encryption Mode      */
#define MD_AES_CON_MODE_DECRYPT           (1) /*!<  This allow user to set AES Mode Control. 1:Decryption Mode      */

#define MD_AES_CON_START                  1   /*!<  This allow user to set AES Start. AES function will start after this bit is set to 1.      */

/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions AES Public Functions
  * @{
  */

/** @defgroup MD_AES_Public_Functions_Group2 CON
  * @{
  */

/**
  * @brief  AES Control Register
  * @param  AES Instance
  * @param  value
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_control(AES_TypeDef *aes, uint32_t value)
{
    WRITE_REG(aes->CON, value);
}

/**
  * @brief  AES Control Register
  * @param  AES Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_aes_get_control(AES_TypeDef *aes)
{
    return (uint32_t)(READ_REG(aes->CON));
}

/**
  * @brief  AES Encryption / Decryption Ready Status
  * @param  AES Instance
  * @retval value This parameter can be one of the following values:
  *         @arg @ref MD_AES_CON_READY_BUSY
  *         @arg @ref MD_AES_CON_READY_READY
  */
__STATIC_INLINE uint32_t md_aes_get_ready(AES_TypeDef *aes)
{
    return (uint32_t)(READ_BIT(aes->CON, AES_CON_READY) >> AES_CON_READY_POS);
}

/**
  * @brief  AES DMA Output Status
  * @param  AES Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_aes_is_enabled_output_dma(AES_TypeDef *aes)
{
    return (READ_BIT(aes->CON, AES_CON_OT_DMA_ST) == (AES_CON_OT_DMA_ST));
}

/**
  * @brief  AES DMA Intput Status
  * @param  AES Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_aes_is_enabled_input_dma(AES_TypeDef *aes, uint32_t value)
{
    return (READ_BIT(aes->CON, AES_CON_IT_DMA_ST) == (AES_CON_IT_DMA_ST));
}

/**
  * @brief  AES DIO data depth status (X=0,1,2,3)
  * @param  AES Instance
  * @retval value This parameter can be one of the following values:
  *         @arg @ref MD_AES_CON_OT_DEPTH_0
  *         @arg @ref MD_AES_CON_OT_DEPTH_1
  *         @arg @ref MD_AES_CON_OT_DEPTH_2
  *         @arg @ref MD_AES_CON_OT_DEPTH_3
  */
__STATIC_INLINE uint32_t md_aes_get_output_data_depth(AES_TypeDef *aes)
{
    return (uint32_t)(READ_BIT(aes->CON, AES_CON_OT_DEPTH) >> AES_CON_OT_DEPTH_POSS);
}

/**
  * @brief  AES DIO data depth status (X=0,1,2,3)
  * @param  AES Instance
  * @retval value This parameter can be one of the following values:
  *         @arg @ref MD_AES_CON_IT_DEPTH_0
  *         @arg @ref MD_AES_CON_IT_DEPTH_1
  *         @arg @ref MD_AES_CON_IT_DEPTH_2
  *         @arg @ref MD_AES_CON_IT_DEPTH_3
  */
__STATIC_INLINE uint32_t md_aes_get_input_data_depth(AES_TypeDef *aes)
{
    return (uint32_t)(READ_BIT(aes->CON, AES_CON_IT_DEPTH) >> AES_CON_IT_DEPTH_POSS);
}

/**
  * @brief  AES Re-initial
  * @param  AES Instance
  * @retval None.
  */
__STATIC_INLINE void md_aes_trigger_initial(AES_TypeDef *aes)
{
    SET_BIT(aes->CON, AES_CON_RE_INIT);
}

/**
  * @brief  AES DMA Function Enable
  * @param  AES Instance
  * @param  value This parameter can be one of the following values:
  *         @arg @ref MD_AES_CON_DMA_EN_INPUT_ENABLE
  *         @arg @ref MD_AES_CON_DMA_EN_INPUT_DISABLE
  *         @arg @ref MD_AES_CON_DMA_EN_OUTPUT_ENABLE
  *         @arg @ref MD_AES_CON_DMA_EN_OUTPUT_DISABLE
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_dma_en(AES_TypeDef *aes, uint32_t value)
{
    MODIFY_REG(aes->CON, AES_CON_DMA_EN, value << AES_CON_DMA_EN_POSS);
}

/**
  * @brief  AES DMA Function Enable
  * @param  AES Instance
  * @retval value This parameter can be one of the following values:
  *         @arg @ref MD_AES_CON_DMA_EN_INPUT_ENABLE
  *         @arg @ref MD_AES_CON_DMA_EN_INPUT_DISABLE
  *         @arg @ref MD_AES_CON_DMA_EN_OUTPUT_ENABLE
  *         @arg @ref MD_AES_CON_DMA_EN_OUTPUT_DISABLE
  */
__STATIC_INLINE uint32_t md_aes_get_dma_en(AES_TypeDef *aes)
{
    return (uint32_t)(READ_BIT(aes->CON, AES_CON_DMA_EN) >> AES_CON_DMA_EN_POSS);
}

/**
  * @brief  Block Cipher Encryption / Decryption Mode
  * @param  AES Instance
  * @param  value This parameter can be one of the following values:
  *         @arg @ref MD_AES_CON_BL_CBC
  *         @arg @ref MD_AES_CON_BL_CFB
  *         @arg @ref MD_AES_CON_BL_OFB
  *         @arg @ref MD_AES_CON_BL_CTR
  *         @arg @ref MD_AES_CON_BL_ECB
  *         @arg @ref MD_AES_CON_BL_GCM
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_block_mode(AES_TypeDef *aes, uint32_t value)
{
    MODIFY_REG(aes->CON, AES_CON_BL, value << AES_CON_BL_POSS);
}

/**
  * @brief  Block Cipher Encryption / Decryption Mode
  * @param  AES Instance
  * @retval value This parameter can be one of the following values:
  *         @arg @ref MD_AES_CON_BL_CBC
  *         @arg @ref MD_AES_CON_BL_CFB
  *         @arg @ref MD_AES_CON_BL_OFB
  *         @arg @ref MD_AES_CON_BL_CTR
  *         @arg @ref MD_AES_CON_BL_ECB
  *         @arg @ref MD_AES_CON_BL_GCM
  */
__STATIC_INLINE uint32_t md_aes_get_block_mode(AES_TypeDef *aes)
{
    return (uint32_t)(READ_BIT(aes->CON, AES_CON_BL) >> AES_CON_BL_POSS);
}

/**
  * @brief  AES Mode Control
  * @param  AES Instance
  * @param  value This parameter can be one of the following values:
  *         @arg @ref MD_AES_CON_MODE_ENCRYPT
  *         @arg @ref MD_AES_CON_MODE_DECRYPT
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_direction(AES_TypeDef *aes, uint32_t value)
{
    MODIFY_REG(aes->CON, AES_CON_MODE, value << AES_CON_MODE_POS);
}

/**
  * @brief  AES Mode Control
  * @param  AES Instance
  * @retval value This parameter can be one of the following values:
  *         @arg @ref MD_AES_CON_MODE_ENCRYPT
  *         @arg @ref MD_AES_CON_MODE_DECRYPT
  */
__STATIC_INLINE uint32_t md_aes_get_direction(AES_TypeDef *aes)
{
    return (uint32_t)(READ_BIT(aes->CON, AES_CON_MODE) >> AES_CON_MODE_POS);
}

/**
  * @brief  AES Start
  * @param  AES Instance
  * @retval None.
  */
__STATIC_INLINE void md_aes_trigger_start(AES_TypeDef *aes)
{
    SET_BIT(aes->CON, AES_CON_START);
}
/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions_Group3 IER
  * @{
  */
/**
  * @brief  AES Interrupt Enable Register
  * @param  AES Instance
  * @param  value
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_ier(AES_TypeDef *aes, uint32_t value)
{
    WRITE_REG(aes->IER, value);
}

/**
  * @brief  AES Decryption Interrupt Enable
  * @param  AES Instance
  * @retval None.
  */
__STATIC_INLINE void md_aes_enable_it_dec(AES_TypeDef *aes)
{
    SET_BIT(aes->IER, AES_IER_DEC);
}

/**
  * @brief  AES Encryption Interrupt Enable
  * @param  AES Instance
  * @retval None.
  */
__STATIC_INLINE void md_aes_enable_it_enc(AES_TypeDef *aes)
{
    SET_BIT(aes->IER, AES_IER_ENC);
}
/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions_Group4 IDR
  * @{
  */
/**
  * @brief  AES Interrupt Disable Register
  * @param  AES Instance
  * @param  value
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_idr(AES_TypeDef *aes, uint32_t value)
{
    WRITE_REG(aes->IDR, value);
}

/**
  * @brief  AES Decryption Interrupt Disable
  * @param  AES Instance
  * @retval None.
  */
__STATIC_INLINE void md_aes_disable_it_dec(AES_TypeDef *aes)
{
    SET_BIT(aes->IDR, AES_IDR_DEC);
}

/**
  * @brief  AES Encryption Interrupt Disable
  * @param  AES Instance
  * @retval None.
  */
__STATIC_INLINE void md_aes_disable_it_enc(AES_TypeDef *aes)
{
    SET_BIT(aes->IDR, AES_IDR_DEC);
}
/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions_Group5 IVS
  * @{
  */
/**
  * @brief  AES Interrupt Valid Status Register
  * @param  AES Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_aes_get_ivs(AES_TypeDef *aes)
{
    return (uint32_t)(READ_REG(aes->IVS));
}

/**
  * @brief  AES Decryption Interrupt Valid Status
  * @param  AES Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE bool md_aes_is_enabled_it_dec(AES_TypeDef *aes)
{
    return (READ_BIT(aes->IVS, AES_IVS_DEC) == (AES_IVS_DEC));
}

/**
  * @brief  AES Encryption Interrupt Valid Status
  * @param  AES Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE bool md_aes_is_enabled_it_enc(AES_TypeDef *aes)
{
    return (READ_BIT(aes->IVS, AES_IVS_ENC) == (AES_IVS_ENC));
}
/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions_Group6 RIF
  * @{
  */
/**
  * @brief  AES Raw Interrupt Flag Status
  * @param  AES Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_aes_get_rif(AES_TypeDef *aes)
{
    return (uint32_t)(READ_REG(aes->RIF));
}

/**
  * @brief  AES Encryption Raw Interrupt Flag Status
  * @param  AES Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE bool md_aes_is_active_it_dec(AES_TypeDef *aes)
{
    return (READ_BIT(aes->RIF, AES_RIF_DEC) == (AES_RIF_DEC));
}

/**
  * @brief  AES Encryption Raw Interrupt Flag Status
  * @param  AES Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE bool md_aes_is_active_it_enc(AES_TypeDef *aes)
{
    return (READ_BIT(aes->RIF, AES_RIF_ENC) == (AES_RIF_ENC));
}
/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions_Group7 IFM
  * @{
  */
/**
  * @brief  AES Interrupt Flag Mask Status Register
  * @param  AES Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_aes_get_ifm(AES_TypeDef *aes)
{
    return (uint32_t)(READ_REG(aes->IFM));
}

/**
  * @brief  AES Interrupt Flag Mask Status Register
  * @param  AES Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE bool md_aes_is_masked_it_dec(AES_TypeDef *aes)
{
    return (READ_BIT(aes->IFM, AES_IFM_DEC) == (AES_IFM_DEC));
}

/**
  * @brief  AES Interrupt Flag Mask Status Register
  * @param  AES Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE bool md_aes_is_masked_it_enc(AES_TypeDef *aes)
{
    return (READ_BIT(aes->IFM, AES_IFM_ENC) == (AES_IFM_ENC));
}
/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions_Group8 ICR
  * @{
  */
/**
  * @brief  AES Interrupt Clear Register
  * @param  AES Instance
  * @param  value
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_icr(AES_TypeDef *aes, uint32_t value)
{
    WRITE_REG(aes->ICR, value);
}

/**
  * @brief  AES Decryption Interrupt Clear
  * @param  AES Instance
  * @retval None.
  */
__STATIC_INLINE void md_aes_clear_it_dec(AES_TypeDef *aes)
{
    SET_BIT(aes->ICR, AES_ICR_DEC);
}

/**
  * @brief  AES Encryption Interrupt Clear
  * @param  AES Instance
  * @retval None.
  */
__STATIC_INLINE void md_aes_clear_it_enc(AES_TypeDef *aes)
{
    SET_BIT(aes->ICR, AES_ICR_ENC);
}
/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions_Group9 DIO
  * @{
  */
/**
  * @brief  AES 128-bit Input / Ouput Data Register
  * @param  AES Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_data(AES_TypeDef *aes, uint32_t value)
{
    WRITE_REG(aes->DIO, value);
}

/**
  * @brief  AES 128-bit Input / Ouput Data Register
  * @param  AES Instance
  * @retval value
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  */

__STATIC_INLINE uint32_t md_aes_get_data(AES_TypeDef *aes)
{
    return (uint32_t)(READ_REG(aes->DIO));
}
/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions_Group10 KEY0
  * @{
  */
/**
  * @brief  AES 128-bit Keyword Register 0
  * @param  AES Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_key0(AES_TypeDef *aes, uint32_t value)
{
    WRITE_REG(aes->KEY0, value);
}

/**
  * @brief  AES 128-bit Keyword Register 0
  * @param  AES Instance
  * @retval value
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  */
__STATIC_INLINE uint32_t md_aes_get_key0(AES_TypeDef *aes)
{
    return (uint32_t)(READ_REG(aes->KEY0));
}
/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions_Group11 KEY1
  * @{
  */
/**
  * @brief  AES 128-bit Keyword Register 1
  * @param  AES Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_key1(AES_TypeDef *aes, uint32_t value)
{
    WRITE_REG(aes->KEY1, value);
}

/**
  * @brief  AES 128-bit Keyword Register 1
  * @param  AES Instance
  * @retval value
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  */
__STATIC_INLINE uint32_t md_aes_get_key1(AES_TypeDef *aes)
{
    return (READ_REG(aes->KEY1));
}
/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions_Group12 KEY2
  * @{
  */
/**
  * @brief  AES 128-bit Keyword Register 2
  * @param  AES Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_key2(AES_TypeDef *aes, uint32_t value)
{
    WRITE_REG(aes->KEY2, value);
}

/**
  * @brief  AES 128-bit Keyword Register 2
  * @param  AES Instance
  * @retval value
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  */
__STATIC_INLINE uint32_t md_aes_get_key2(AES_TypeDef *aes)
{
    return (READ_REG(aes->KEY2));
}
/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions_Group13 KEY3
  * @{
  */
/**
  * @brief  AES 128-bit Keyword Register 3
  * @param  AES Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_key3(AES_TypeDef *aes, uint32_t value)
{
    WRITE_REG(aes->KEY3, value);
}

/**
  * @brief  AES 128-bit Keyword Register 3
  * @param  AES Instance
  * @retval value
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  */
__STATIC_INLINE uint32_t md_aes_get_key3(AES_TypeDef *aes)
{
    return (READ_REG(aes->KEY3));
}
/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions_Group14 IV0
  * @{
  */
/**
  * @brief  AES 128-bit Initial Vector Register 0
  * @param  AES Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_initial_vector0(AES_TypeDef *aes, uint32_t value)
{
    WRITE_REG(aes->IV0, value);
}

/**
  * @brief  AES 128-bit Initial Vector Register 0
  * @param  AES Instance
  * @retval value
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  */
__STATIC_INLINE uint32_t md_aes_get_initial_vector0(AES_TypeDef *aes)
{
    return (uint32_t)(READ_REG(aes->IV0));
}
/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions_Group15 IV1
  * @{
  */
/**
  * @brief  AES 128-bit Initial Vector Register 1
  * @param  AES Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_initial_vector1(AES_TypeDef *aes, uint32_t value)
{
    WRITE_REG(aes->IV1, value);
}

/**
  * @brief  AES 128-bit Initial Vector Register 1
  * @param  AES Instance
  * @retval value
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  */
__STATIC_INLINE uint32_t md_aes_get_initial_vector1(AES_TypeDef *aes)
{
    return (uint32_t)(READ_REG(aes->IV1));
}
/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions_Group16 IV2
  * @{
  */
/**
  * @brief  AES 128-bit Initial Vector Register 2
  * @param  AES Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_initial_vector2(AES_TypeDef *aes, uint32_t value)
{
    WRITE_REG(aes->IV2, value);
}

/**
  * @brief  AES 128-bit Initial Vector Register 2
  * @param  AES Instance
  * @retval value
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  */
__STATIC_INLINE uint32_t md_aes_get_initial_vector2(AES_TypeDef *aes)
{
    return (uint32_t)(READ_REG(aes->IV2));
}
/**
  * @}
  */

/** @defgroup MD_AES_Public_Functions_Group17 IV3
  * @{
  */
/**
  * @brief  AES 128-bit Initial Vector Register 3
  * @param  AES Instance
  * @param  value This parameter can be one of the following values:
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  * @retval None.
  */
__STATIC_INLINE void md_aes_set_initial_vector3(AES_TypeDef *aes, uint32_t value)
{
    WRITE_REG(aes->IV3, value);
}

/**
  * @brief  AES 128-bit Initial Vector Register 3
  * @param  AES Instance
  * @retval value
  *         @arg Minimum 0x0000000
  *         @arg Maximum 0xFFFFFFF
  */
__STATIC_INLINE uint32_t md_aes_get_initial_vector3(AES_TypeDef *aes)
{
    return (uint32_t)(READ_REG(aes->IV3));
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
  * @} Micro_Driver
  */

#ifdef __cplusplus
}
#endif
#endif

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
