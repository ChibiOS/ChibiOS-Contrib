/**********************************************************************************
 *
 * @file    md_dma.h
 * @brief   Header file of DMA module driver.
 *
 * @date    19 July 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          19 July 2022    Shiwa           the first version
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


#ifndef __MD_DMA_H__
#define __MD_DMA_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------ */
#include "md_utils.h"
/** @addtogroup Micro_Driver
  * @{
  */
/** @defgroup MD_DMA DMA
  * @brief DMA micro driver
  * @{
  */

/* Exported Constants -------------------------------------------------------- */

/* Exported Variables -------------------------------------------------------- */

/* Exported Types ------------------------------------------------------------ */

/** @defgroup MD_DMA_Public_Types DMA Public Types
  * @{
  */
/**
  * @brief Input source to DMA channel
  */
typedef enum
{
    MD_DMA_MSEL_NONE    = 0x0U, /**< NONE */
    MD_DMA_MSEL_GPIO    = 0x1U, /**< GPIO */
    MD_DMA_MSEL_ADC     = 0x2U, /**< ADC */
    MD_DMA_MSEL_CRC     = 0x3U, /**< CRC */
    MD_DMA_MSEL_EUART0  = 0x4U, /**< EUART0 */
    MD_DMA_MSEL_EUART1  = 0x5U, /**< EUART1 */
    MD_DMA_MSEL_CUART0  = 0x6U, /**< CUART0 */
    MD_DMA_MSEL_CUART1  = 0x7U, /**< CUART1 */
    MD_DMA_MSEL_CUART2  = 0x8U, /**< CUART2 */
    MD_DMA_MSEL_SPI0    = 0x9U, /**< SPI */
    MD_DMA_MSEL_SPI1    = 0xAU, /**< SPI */
    MD_DMA_MSEL_I2C0    = 0xBU, /**< I2C0 */
    MD_DMA_MSEL_I2C1    = 0xCU, /**< I2C1 */
    MD_DMA_MSEL_AD16C4T = 0xDU, /**< AD16C4T */
    MD_DMA_MSEL_GP16C2T0 = 0xEU, /**< GP16C2T0 */
    MD_DMA_MSEL_GP16C2T1 = 0xFU, /**< GP16C2T1 */
    MD_DMA_MSEL_GP16C2T2 = 0x10U, /**< GP16C2T2 */
    MD_DMA_MSEL_PIS     = 0x11U,/**< PIS */
    MD_DMA_MSEL_BSTIM0  = 0x12U,/**< BSTIM0 */
} md_dma_msel_t;

/**
  * @brief Input signal to DMA channel
  */
typedef enum
{
    MD_DMA_MSIGSEL_NONE           = 0x0U,   /**< NONE */
    MD_DMA_MSIGSEL_EXTI_0         = 0x0U,   /**< External interrupt 0 */
    MD_DMA_MSIGSEL_EXTI_1         = 0x1U,   /**< External interrupt 1 */
    MD_DMA_MSIGSEL_EXTI_2         = 0x2U,   /**< External interrupt 2 */
    MD_DMA_MSIGSEL_EXTI_3         = 0x3U,   /**< External interrupt 3 */
    MD_DMA_MSIGSEL_EXTI_4         = 0x4U,   /**< External interrupt 4 */
    MD_DMA_MSIGSEL_EXTI_5         = 0x5U,   /**< External interrupt 5 */
    MD_DMA_MSIGSEL_EXTI_6         = 0x6U,   /**< External interrupt 6 */
    MD_DMA_MSIGSEL_EXTI_7         = 0x7U,   /**< External interrupt 7 */
    MD_DMA_MSIGSEL_EXTI_8         = 0x8U,   /**< External interrupt 8 */
    MD_DMA_MSIGSEL_EXTI_9         = 0x9U,   /**< External interrupt 9 */
    MD_DMA_MSIGSEL_EXTI_10        = 0xAU,   /**< External interrupt 10 */
    MD_DMA_MSIGSEL_EXTI_11        = 0xBU,   /**< External interrupt 11 */
    MD_DMA_MSIGSEL_EXTI_12        = 0xCU,   /**< External interrupt 12 */
    MD_DMA_MSIGSEL_EXTI_13        = 0xDU,   /**< External interrupt 13 */
    MD_DMA_MSIGSEL_EXTI_14        = 0xEU,   /**< External interrupt 14 */
    MD_DMA_MSIGSEL_EXTI_15        = 0xFU,   /**< External interrupt 15 */
    MD_DMA_MSIGSEL_ADC            = 0x0U,   /**< ADC mode */
    MD_DMA_MSIGSEL_CRC            = 0x0U,   /**< CRC */
    MD_DMA_MSIGSEL_UART_RNR       = 0x0U,   /**< UART reveive */
    MD_DMA_MSIGSEL_UART_TXEMPTY   = 0x1U,   /**< UART transmit */
    MD_DMA_MSIGSEL_SPI_RNR        = 0x0U,   /**< SPI receive */
    MD_DMA_MSIGSEL_SPI_TXEMPTY    = 0x1U,   /**< SPI transmit */
    MD_DMA_MSIGSEL_I2C_RNR        = 0x0U,   /**< I2C receive */
    MD_DMA_MSIGSEL_I2C_TXEMPTY    = 0x1U,   /**< I2C transmit */
    MD_DMA_MSIGSEL_TIMER_CH1      = 0x0U,   /**< TIM channal 1 */
    MD_DMA_MSIGSEL_TIMER_CH2      = 0x1U,   /**< TIM channal 2 */
    MD_DMA_MSIGSEL_TIMER_CH3      = 0x2U,   /**< TIM channal 3 */
    MD_DMA_MSIGSEL_TIMER_CH4      = 0x3U,   /**< TIM channal 4 */
    MD_DMA_MSIGSEL_TIMER_TRI      = 0x4U,   /**< TIM trigger */
    MD_DMA_MSIGSEL_TIMER_COMP     = 0x5U,   /**< TIM compare */
    MD_DMA_MSIGSEL_TIMER_UPDATE   = 0x6U,   /**< TIM update */
    MD_DMA_MSIGSEL_BSTIM0         = 0x0U,   /**< BSTIM0 */
    MD_DMA_MSIGSEL_PIS_CH0        = 0x0U,   /**< PIS channal 0 */
    MD_DMA_MSIGSEL_PIS_CH1        = 0x1U,   /**< PIS channal 1 */
    MD_DMA_MSIGSEL_PIS_CH2        = 0x2U,   /**< PIS channal 2 */
    MD_DMA_MSIGSEL_PIS_CH3        = 0x3U,   /**< PIS channal 3 */
    MD_DMA_MSIGSEL_PIS_CH4        = 0x4U,   /**< PIS channal 4 */
    MD_DMA_MSIGSEL_PIS_CH5        = 0x5U,   /**< PIS channal 5 */
    MD_DMA_MSIGSEL_PIS_CH6        = 0x6U,   /**< PIS channal 6 */
    MD_DMA_MSIGSEL_PIS_CH7        = 0x7U,   /**< PIS channal 7 */
} md_dma_msigsel_t;
/**
  * @brief Priority of DMA channel
  */
typedef enum
{
    MD_DMA_LOW_PRIORITY     = 0,
    MD_DMA_MEDIUM_PRIORITY  = 1,
    MD_DMA_HIGH_PRIORUTY    = 2,
    MD_DMA_HIGHEST_PRIORITY = 3
} md_dma_priority_t;

/**
  * @brief data increment
  */
typedef enum
{
    MD_DMA_DATA_INC_DISABLE  = 0x0U,
    MD_DMA_DATA_INC_ENABLE   = 0x1U,
} md_dma_data_inc_t;

/**
  * @brief Data size
  */
typedef enum
{
    MD_DMA_DATA_SIZE_BYTE     = 0x0U,   /**< Byte */
    MD_DMA_DATA_SIZE_HALFWORD = 0x1U,   /**< Halfword */
    MD_DMA_DATA_SIZE_WORD     = 0x2U,   /**< Word */
} md_dma_data_size_t;

/**
  * @brief Control how many DMA transfers can occur
  *        before the controller re-arbitrates
  */
typedef enum
{
    MD_DMA_R_POWER_1    = 0x0U, /**< Arbitrates after each DMA transfer */
    MD_DMA_R_POWER_2    = 0x1U, /**< Arbitrates after 2 DMA transfer */
    MD_DMA_R_POWER_4    = 0x2U, /**< Arbitrates after 4 DMA transfer */
    MD_DMA_R_POWER_8    = 0x3U, /**< Arbitrates after 8 DMA transfer */
    MD_DMA_R_POWER_16   = 0x4U, /**< Arbitrates after 16 DMA transfer */
    MD_DMA_R_POWER_32   = 0x5U, /**< Arbitrates after 32 DMA transfer */
    MD_DMA_R_POWER_64   = 0x6U, /**< Arbitrates after 64 DMA transfer */
    MD_DMA_R_POWER_128  = 0x7U, /**< Arbitrates after 128 DMA transfer */
    MD_DMA_R_POWER_256  = 0x8U, /**< Arbitrates after 256 DMA transfer */
    MD_DMA_R_POWER_512  = 0x9U, /**< Arbitrates after 512 DMA transfer */
    MD_DMA_R_POWER_1024 = 0xAU, /**< Arbitrates after 1024 DMA transfer */
} md_dma_arbiter_config_t;

/**
  * @brief DMA channal configure structure
  */
typedef struct
{
    void *src;              /**< Source data begin pointer */
    void *dst;              /**< Destination data begin pointer */
    uint16_t size;              /**< The total number of DMA transfers that DMA cycle contains */
    md_dma_data_size_t src_data_width;      /**< Source data width */
    md_dma_data_size_t dst_data_width;      /**< Dest data width */
    TypeFunc src_inc;      /**< Source increment type */
    TypeFunc dst_inc;      /**< Destination increment type */
    md_dma_arbiter_config_t R_power;    /**< Control how many DMA transfers can occur before re-arbitrates */
    md_dma_priority_t priority;         /**< High priority or default priority */
    TypeFunc mem_to_mem;    /**< Enable/disable memory to memory mode */
    TypeFunc circle_mode;   /**< Enable/disable circular mode */
    md_dma_msel_t msel;         /**< Input source to DMA channel */
    md_dma_msigsel_t msigsel;       /**< Input signal to DMA channel */
    uint8_t channel;            /**< Channel index */
} md_dma_config_t;
/**
  * @}
  */

/* Exported Macros ----------------------------------------------------------- */

/** @defgroup MD_DMA_Public_Macros DMA Public Macros
  * @{
  */
/**
  * brief MD_DMA_CHANNEL DMA channel
  */
#define MD_DMA_CH_0 0x0U   /**< Channel 0 */
#define MD_DMA_CH_1 0x1U   /**< Channel 1 */
#define MD_DMA_CH_2 0x2U   /**< Channel 2 */
#define MD_DMA_CH_3 0x3U   /**< Channel 3 */
#define MD_DMA_CH_4 0x4U   /**< Channel 4 */
#define MD_DMA_CH_5 0x5U   /**< Channel 5 */
#define MD_DMA_CH_6 0x6U   /**< Channel 6 */

/**
  * @brief DMA interrupt flag
  */
#define MD_DMA_CH0_TC DMA_CH0_TC_MSK   /**< interrupt mask 1 */
#define MD_DMA_CH0_HT DMA_CH0_HT_MSK   /**< interrupt mask 2 */
#define MD_DMA_CH1_TC DMA_CH1_TC_MSK   /**< interrupt mask 3 */
#define MD_DMA_CH1_HT DMA_CH1_HT_MSK   /**< interrupt mask 4 */
#define MD_DMA_CH2_TC DMA_CH2_TC_MSK   /**< interrupt mask 5 */
#define MD_DMA_CH2_HT DMA_CH2_HT_MSK   /**< interrupt mask 6 */
#define MD_DMA_CH3_TC DMA_CH3_TC_MSK   /**< interrupt mask 7 */
#define MD_DMA_CH3_HT DMA_CH3_HT_MSK   /**< interrupt mask 8 */
#define MD_DMA_CH4_TC DMA_CH4_TC_MSK   /**< interrupt mask 9 */
#define MD_DMA_CH4_HT DMA_CH4_HT_MSK   /**< interrupt mask 10 */
#define MD_DMA_CH5_TC DMA_CH5_TC_MSK   /**< interrupt mask 11 */
#define MD_DMA_CH5_HT DMA_CH5_HT_MSK   /**< interrupt mask 12 */
#define MD_DMA_CH6_TC DMA_CH6_TC_MSK   /**< interrupt mask 13 */
#define MD_DMA_CH6_HT DMA_CH6_HT_MSK   /**< interrupt mask 14 */
/**
  * @}
  */

/* Exported Functions -------------------------------------------------------- */

/** @defgroup MD_DMA_Public_Functions DMA Public Functions
  * @{
  */
/** @defgroup MD_DMA_Public_Functions_Group2 STATUS
  * @{
  */

/**
  * @brief  Check if DMA peripheral is enabled
  * @param ch: DMA channel (0-6)
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */

/**
  * @brief  Check if DMA peripheral is enabled
  * @param ch: DMA channel (0-6)
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_dma_is_enabled(uint32_t ch)
{
    return READ_BIT(DMA->CHANNEL[ch].CON, DMA_CON_CHEN_POS);
}
/**
  * @}
  */
/** @defgroup MD_DMA_Public_Functions_Group3 Enable/Disable
  * @{
  */
/**
  * @brief  Enable DMA peripheral
  * @param ch: DMA channel(0-6)
  * @retval None
  */
__STATIC_INLINE void md_dma_enable_channel(uint32_t ch)
{
    SET_BIT(DMA->CHANNEL[ch].CON, DMA_CON_CHEN_MSK);
}

/**
  * @brief  Disable DMA peripheral
  * @param ch: DMA channel(0-6)
  * @retval None
  */
__STATIC_INLINE void md_dma_disable_channel(uint32_t ch)
{
    CLEAR_BIT(DMA->CHANNEL[ch].CON, DMA_CON_CHEN_MSK);
}

/**
  * @}
  */

/** @defgroup MD_DMA_Public_Functions_Group4 SAR
  * @{
  */
/**
  * @brief  Set DMA source data address
  * @param  ch: DMA channel
  * @param  addr: Source data address
  * @retval None
  */
__STATIC_INLINE void md_dma_set_source_addr(uint32_t ch, void *addr)
{
    WRITE_REG(DMA->CHANNEL[ch].SAR, (uint32_t)addr);
}

/**
  * @brief  Get DMA source data address
  * @param  ch: DMA channel
  * @retval DMA source data address
  */
__STATIC_INLINE void *md_dma_get_source_addr(uint32_t ch)
{
    return (void *)DMA->CHANNEL[ch].SAR;
}
/**
  * @}
  */

/** @defgroup MD_DMA_Public_Functions_Group5 DAR
  * @{
  */

/**
  * @brief  Set DMA destination data address
  * @param  ch: DMA channel
  * @param  addr: DMA destination data address
  * @retval None
  */
__STATIC_INLINE void md_dma_set_dest_addr(uint32_t ch, void *addr)
{
    WRITE_REG(DMA->CHANNEL[ch].DAR, (uint32_t)addr);
}

/**
  * @brief  Get DMA destination data address
  * @param  ch: DMA channel
  * @retval The destination data address
  */
__STATIC_INLINE void *md_dma_get_dest_addr(uint32_t ch)
{
    return (void *)DMA->CHANNEL[ch].DAR;
}

/**
  * @}
  */

/** @defgroup MD_DMA_Public_Functions_Group6 CON
  * @{
  */

/**
  * @brief  Sets DMA source data width
  * @param  ch: DMA channel
  * @param  data_width: This parameter can be one of the @ref md_dma_data_size_t
  * @retval None
  */
__STATIC_INLINE void md_dma_set_source_width(uint32_t ch, uint32_t data_width)
{
    MODIFY_REG(DMA->CHANNEL[ch].CON, DMA_CON_SDWSEL_MSK, data_width << DMA_CON_SDWSEL_POSS);
}

/**
  * @brief  Gets DMA source data width
  * @param  ch: DMA channel
  * @retval The return data width, see @ref md_dma_data_size_t
  */
__STATIC_INLINE uint32_t md_dma_get_source_width(uint32_t ch)
{
    return READ_BITS(DMA->CHANNEL[ch].CON, DMA_CON_SDWSEL_MSK, DMA_CON_SDWSEL_POSS);
}

/**
  * @brief  Set DMA source data increment
  * @param  ch: DMA channel
  * @param  src_inc: ENABLE(1) or DISABLE(0)
  * @retval None
  */
__STATIC_INLINE void md_dma_set_source_inc(uint32_t ch, uint32_t src_inc)
{
    MODIFY_REG(DMA->CHANNEL[ch].CON, DMA_CON_SINC_MSK, src_inc << DMA_CON_SINC_POS);
}

/**
  * @brief  Get DMA source data increment
  * @param  ch: DMA channel
  * @retval ENABLE(1) or DISABLE(0)
  */
__STATIC_INLINE uint32_t md_dma_get_source_inc(uint32_t ch)
{
    return READ_BIT(DMA->CHANNEL[ch].CON, DMA_CON_SINC_POS);
}

/**
  * @brief  Sets DMA dest data width
  * @param  ch: DMA channel
  * @param  data_width: This parameter can be one of the @ref md_dma_data_size_t
  * @retval None
  */
__STATIC_INLINE void md_dma_set_dest_width(uint32_t ch, uint32_t data_width)
{
    MODIFY_REG(DMA->CHANNEL[ch].CON, DMA_CON_DDWSEL_MSK, data_width << DMA_CON_DDWSEL_POSS);
}

/**
  * @brief  Gets DMA dest data width
  * @param  ch: DMA channel
  * @retval The return data width, see @ref md_dma_data_size_t
  */
__STATIC_INLINE uint32_t md_dma_get_dest_width(uint32_t ch)
{
    return READ_BITS(DMA->CHANNEL[ch].CON, DMA_CON_DDWSEL_MSK, DMA_CON_DDWSEL_POSS);
}
/**
  * @brief  Set DMA destination data increment
  * @param  ch: DMA channel
  * @param  dst_inc This parameter can be one of the @ref md_dma_data_inc_t
  * @retval None
  */
__STATIC_INLINE void md_dma_set_dest_inc(uint32_t ch, uint32_t dst_inc)
{
    MODIFY_REG(DMA->CHANNEL[ch].CON, DMA_CON_DINC_MSK, dst_inc << DMA_CON_DINC_POS);
}

/**
  * @brief  Get DMA destination data increment
  * @param  ch: DMA channel
  * @retval The return destination data increment, see @ref md_dma_data_inc_t
  */
__STATIC_INLINE uint32_t md_dma_get_dest_inc(uint32_t ch)
{
    return READ_BIT(DMA->CHANNEL[ch].CON, DMA_CON_SINC_POS);
}

/**
  * @brief  Set how many DMA transfers can occur before the controller rearbitrates
  * @param  ch: DMA channel
  * @param  r_power: The r_power value, see @ref md_dma_arbiter_config_t
  * @retval None
  */
__STATIC_INLINE void md_dma_set_r_power(uint32_t ch, uint32_t r_power)
{
    MODIFY_REG(DMA->CHANNEL[ch].CON, DMA_CON_MAX_BURST_MSK, r_power << DMA_CON_MAX_BURST_POSS);
}

/**
  * @brief  Get how many DMA transfers can occur before the controller rearbitrates
  * @param  ch: DMA channel
  * @retval The r_power value, see @ref md_dma_arbiter_config_t
  */
__STATIC_INLINE uint32_t md_dma_get_r_power(uint32_t ch)
{
    return READ_BITS(DMA->CHANNEL[ch].CON, DMA_CON_MAX_BURST_MSK, DMA_CON_MAX_BURST_POSS);
}

/**
  * @brief  Enable or disable DMA memory to memory transfer mode
  * @param  ch: DMA channel
  * @param  enable: 1-Enable,0-Disable
  * @retval None
  */
__STATIC_INLINE void md_dma_set_mem_to_mem(uint32_t ch, uint32_t enable)
{
    MODIFY_REG(DMA->CHANNEL[ch].CON, DMA_CON_M2M_MSK, enable << DMA_CON_M2M_POS);
}
/**
  * @brief  Get whether DMA memory to memory transfer is enabled
  * @param  ch: DMA channel
  * @retval 1-Enable,0-Disable
  */
__STATIC_INLINE uint32_t md_dma_get_mem_to_mem(uint32_t ch)
{
    return (READ_BIT(DMA->CHANNEL[ch].CON, DMA_CON_M2M_MSK) == DMA_CON_M2M_MSK);
}

/**
  * @brief  Set DMA data transfer direction (However,NO actual effect)
  * @param  ch: DMA channel
  * @param  dir: 0-peri->mem,1-mem->peri
  * @retval None
  */
__STATIC_INLINE void md_dma_set_data_dir(uint32_t ch, uint32_t dir)
{
    MODIFY_REG(DMA->CHANNEL[ch].CON, DMA_CON_DIR_MSK, dir << DMA_CON_DIR_POS);
}
/**
  * @brief  Get DMA data transfer direction (However,NO actual effect)
  * @param  ch: DMA channel
  * @retval 0-peri->mem,1-mem->peri
  */
__STATIC_INLINE uint32_t md_dma_get_data_dir(uint32_t ch)
{
    return (READ_BIT(DMA->CHANNEL[ch].CON, DMA_CON_DIR_MSK) == DMA_CON_DIR_MSK);
}

/**
  * @brief  Set DMA data transfer direction
  * @param  ch: DMA channel
  * @param  enable: 1-Enable,0-Disable
  * @retval None
  */
__STATIC_INLINE void md_dma_set_circle_mode(uint32_t ch, uint32_t enable)
{
    MODIFY_REG(DMA->CHANNEL[ch].CON, DMA_CON_CIRC_MSK, enable << DMA_CON_CIRC_POS);
}
/**
  * @brief  Get whether DMA mem to mem transfer is enabled
  * @param  ch: DMA channel
  * @retval 1-Enable,0-Disable
  */
__STATIC_INLINE uint32_t md_dma_get_circle_mode(uint32_t ch)
{
    return (READ_BIT(DMA->CHANNEL[ch].CON, DMA_CON_CIRC_MSK) == DMA_CON_CIRC_MSK);
}
/**
  * @brief  Set channel priority
  * @param  ch: DMA channel
  * @param  priority: Priority of DMA channel see @ref md_dma_priority_t
  * @retval None
  */
__STATIC_INLINE void md_dma_set_priority(uint32_t ch, uint32_t priority)
{
    MODIFY_REG(DMA->CHANNEL[ch].CON, DMA_CON_CHPRI_MSK, priority << DMA_CON_CHPRI_POSS);
}
/**
  * @brief  Get channel priority
  * @param  ch: DMA channel
  * @retval Priority of DMA channel see @ref md_dma_priority_t
  */
__STATIC_INLINE uint32_t md_dma_get_priority(uint32_t ch)
{
    return READ_BITS(DMA->CHANNEL[ch].CON, DMA_CON_CHPRI_MSK, DMA_CON_CHPRI_POSS);
}
/**
  * @}
  */
/** @defgroup MD_DMA_Public_Functions_Group7 NDT
  * @{
  */
/**
  * @brief  Set the total numbers of DMA transfers
  * @param  ch: DMA channel
  * @param  n: The size of DMA transfers
  * @retval None
  */
__STATIC_INLINE void md_dma_set_transfer_size(uint32_t ch, uint16_t n)
{
    MODIFY_REG(DMA->CHANNEL[ch].NDT, DMA_NDT_TNDT_MSK, n << DMA_NDT_TNDT_POSS);
}

/**
  * @brief  Get the total numbers of DMA transfers
  * @param  ch: DMA channel
  * @retval The size
  */
__STATIC_INLINE uint32_t md_dma_get_transfer_size(uint32_t ch)
{
    return READ_BITS(DMA->CHANNEL[ch].NDT, DMA_NDT_TNDT_MSK, DMA_NDT_TNDT_POSS);
}
/**
  * @brief  Get the total numbers of DMA remaining data transfers
  * @param  ch: DMA channel
  * @retval The size
  */
__STATIC_INLINE uint32_t md_dma_get_remaining_size(uint32_t ch)
{
    return READ_BITS(DMA->CHANNEL[ch].NDT, DMA_NDT_NRDT_MSK, DMA_NDT_NRDT_POSS);
}
/**
  * @}
  */

/** @defgroup MD_DMA_Public_Functions_Group8 IFM
  * @{
  */
/**
  * @brief  Get DMA flag
  * @param  ch_flag: This parameter can be one or combined of the following values:
  *         @arg @ref MD_DMA_CH0_TC
  *         @arg @ref MD_DMA_CH0_HT
  *         @arg @ref MD_DMA_CH1_TC
  *         @arg @ref MD_DMA_CH1_HT
  *         @arg @ref MD_DMA_CH2_TC
  *         @arg @ref MD_DMA_CH2_HT
  *         @arg @ref MD_DMA_CH3_TC
  *         @arg @ref MD_DMA_CH3_HT
  *         @arg @ref MD_DMA_CH4_TC
  *         @arg @ref MD_DMA_CH4_HT
  *         @arg @ref MD_DMA_CH5_TC
  *         @arg @ref MD_DMA_CH5_HT
  *         @arg @ref MD_DMA_CH6_TC
  *         @arg @ref MD_DMA_CH6_HT
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_dma_is_active_flag(uint32_t ch_flag)
{
    return (READ_BIT(DMA->IFM, ch_flag) == ch_flag);
}
/**
  * @brief  Get DMA transfer complete flag
  * @param  ch: DMA channel
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_dma_is_active_flag_tc(uint32_t ch)
{
    return md_dma_is_active_flag(MD_DMA_CH0_TC << (ch * 2));
}
/**
  * @brief  Get DMA half transfer flag
  * @param  ch: DMA channel
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_dma_is_active_flag_ht(uint32_t ch)
{
    return md_dma_is_active_flag(MD_DMA_CH0_HT << (ch * 2));
}
/**
  * @}
  */
/** @defgroup MD_DMA_Public_Functions_Group9 ICR
  * @{
  */
/**
  * @brief  Clear DMA flag
  * @param  ch_flag: This parameter can be one or combined of the following values:
  *         @arg @ref MD_DMA_CH0_TC
  *         @arg @ref MD_DMA_CH0_HT
  *         @arg @ref MD_DMA_CH1_TC
  *         @arg @ref MD_DMA_CH1_HT
  *         @arg @ref MD_DMA_CH2_TC
  *         @arg @ref MD_DMA_CH2_HT
  *         @arg @ref MD_DMA_CH3_TC
  *         @arg @ref MD_DMA_CH3_HT
  *         @arg @ref MD_DMA_CH4_TC
  *         @arg @ref MD_DMA_CH4_HT
  *         @arg @ref MD_DMA_CH5_TC
  *         @arg @ref MD_DMA_CH5_HT
  *         @arg @ref MD_DMA_CH6_TC
  *         @arg @ref MD_DMA_CH6_HT
  * @retval None
  */
__STATIC_INLINE void md_dma_clear_flag(uint32_t ch_flag)
{
    SET_BIT(DMA->ICR, ch_flag);
}
/**
  * @brief  Clear DMA transfer complete flag
  * @param  ch: DMA channel
  * @retval None
  */
__STATIC_INLINE void md_dma_clear_flag_tc(uint32_t ch)
{
    md_dma_clear_flag(MD_DMA_CH0_TC << (ch * 2));
}
/**
  * @brief  Clear DMA half transfer flag
  * @param  ch: DMA channel
  * @retval None
  */
__STATIC_INLINE void md_dma_clear_flag_ht(uint32_t ch)
{
    md_dma_clear_flag(MD_DMA_CH0_HT << (ch * 2));
}

/**
  * @}
  */
/** @defgroup MD_DMA_Public_Functions_Group10 IER
  * @{
  */
/**
  * @brief  Enable DMA CHx interrupt
  * @param  ch_flag: This parameter can be one or combined of the following values:
  *         @arg @ref MD_DMA_CH0_TC
  *         @arg @ref MD_DMA_CH0_HT
  *         @arg @ref MD_DMA_CH1_TC
  *         @arg @ref MD_DMA_CH1_HT
  *         @arg @ref MD_DMA_CH2_TC
  *         @arg @ref MD_DMA_CH2_HT
  *         @arg @ref MD_DMA_CH3_TC
  *         @arg @ref MD_DMA_CH3_HT
  *         @arg @ref MD_DMA_CH4_TC
  *         @arg @ref MD_DMA_CH4_HT
  *         @arg @ref MD_DMA_CH5_TC
  *         @arg @ref MD_DMA_CH5_HT
  *         @arg @ref MD_DMA_CH6_TC
  *         @arg @ref MD_DMA_CH6_HT
  * @retval None
  */
__STATIC_INLINE void md_dma_enable_it(uint32_t ch_flag)
{
    SET_BIT(DMA->IER, ch_flag);
}
/**
  * @brief  Enable DMA transfer complete interrupt
  * @param  ch: DMA channel
  * @retval None
  */
__STATIC_INLINE void md_dma_enable_it_tc(uint32_t ch)
{
    md_dma_enable_it(MD_DMA_CH0_TC << (ch * 2));
}
/**
  * @brief  Enable DMA half transfer interrupt
  * @param  ch: DMA channel
  * @retval None
  */
__STATIC_INLINE void md_dma_enable_it_ht(uint32_t ch)
{
    md_dma_enable_it(MD_DMA_CH0_HT << (ch * 2));
}
/**
  * @}
  */
/** @defgroup MD_DMA_Public_Functions_Group11 IDR
  * @{
  */
/**
  * @brief  Disable DMA CHx interrupt
  * @param  ch_flag: This parameter can be one or combined of the following values:
  *         @arg @ref MD_DMA_CH0_TC
  *         @arg @ref MD_DMA_CH0_HT
  *         @arg @ref MD_DMA_CH1_TC
  *         @arg @ref MD_DMA_CH1_HT
  *         @arg @ref MD_DMA_CH2_TC
  *         @arg @ref MD_DMA_CH2_HT
  *         @arg @ref MD_DMA_CH3_TC
  *         @arg @ref MD_DMA_CH3_HT
  *         @arg @ref MD_DMA_CH4_TC
  *         @arg @ref MD_DMA_CH4_HT
  *         @arg @ref MD_DMA_CH5_TC
  *         @arg @ref MD_DMA_CH5_HT
  *         @arg @ref MD_DMA_CH6_TC
  *         @arg @ref MD_DMA_CH6_HT
  * @retval None
  */
__STATIC_INLINE void md_dma_disable_it(uint32_t ch_flag)
{
    SET_BIT(DMA->IDR, ch_flag);
}
/**
  * @brief  Disable DMA transfer complete interrupt
  * @param  ch: DMA channel
  * @retval None
  */
__STATIC_INLINE void md_dma_disable_it_tc(uint32_t ch)
{
    md_dma_disable_it(MD_DMA_CH0_TC << (ch * 2));
}
/**
  * @brief  Disable DMA half transfer interrupt
  * @param  ch: DMA channel
  * @retval None
  */
__STATIC_INLINE void md_dma_disable_it_ht(uint32_t ch)
{
    md_dma_disable_it(MD_DMA_CH0_HT << (ch * 2));
}
/**
  * @}
  */
/** @defgroup MD_DMA_Public_Functions_Group12 IVS
  * @{
  */
/**
  * @brief  Check if DMA CHx interrupt is enabled
  * @param  ch_flag: This parameter can be one or combined of the following values:
  *         @arg @ref MD_DMA_CH0_TC
  *         @arg @ref MD_DMA_CH0_HT
  *         @arg @ref MD_DMA_CH1_TC
  *         @arg @ref MD_DMA_CH1_HT
  *         @arg @ref MD_DMA_CH2_TC
  *         @arg @ref MD_DMA_CH2_HT
  *         @arg @ref MD_DMA_CH3_TC
  *         @arg @ref MD_DMA_CH3_HT
  *         @arg @ref MD_DMA_CH4_TC
  *         @arg @ref MD_DMA_CH4_HT
  *         @arg @ref MD_DMA_CH5_TC
  *         @arg @ref MD_DMA_CH5_HT
  *         @arg @ref MD_DMA_CH6_TC
  *         @arg @ref MD_DMA_CH6_HT
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_dma_is_enabled_it(uint32_t ch_flag)
{
    return (READ_BIT(DMA->IVS, ch_flag) == ch_flag);
}
/**
  * @brief  Check if DMA transfer complete interrupt is enabled
  * @param  ch: DMA channel
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_dma_is_enabled_it_tc(uint32_t ch)
{
    return md_dma_is_enabled_it(MD_DMA_CH0_TC << (ch * 2));
}
/**
  * @brief  Check if DMA half transfer interrupt is enabled
  * @param  ch: DMA channel
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_dma_is_enabled_it_ht(uint32_t ch)
{
    return md_dma_is_enabled_it(MD_DMA_CH0_HT << (ch * 2));
}
/**
  * @}
  */
/** @defgroup MD_DMA_Public_Functions_Group13 RIF
  * @{
  */
/**
  * @brief  Check if DMA CHx interrupt is enabled
  * @param  ch_flag: This parameter can be one or combined of the following values:
  *         @arg @ref MD_DMA_CH0_TC
  *         @arg @ref MD_DMA_CH0_HT
  *         @arg @ref MD_DMA_CH1_TC
  *         @arg @ref MD_DMA_CH1_HT
  *         @arg @ref MD_DMA_CH2_TC
  *         @arg @ref MD_DMA_CH2_HT
  *         @arg @ref MD_DMA_CH3_TC
  *         @arg @ref MD_DMA_CH3_HT
  *         @arg @ref MD_DMA_CH4_TC
  *         @arg @ref MD_DMA_CH4_HT
  *         @arg @ref MD_DMA_CH5_TC
  *         @arg @ref MD_DMA_CH5_HT
  *         @arg @ref MD_DMA_CH6_TC
  *         @arg @ref MD_DMA_CH6_HT
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_dma_is_active_rif(uint32_t ch_flag)
{
    return (READ_BIT(DMA->RIF, ch_flag) == ch_flag);
}
/**
  * @brief  Check if DMA transfer complete interrupt is enabled
  * @param  ch: DMA channel
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_dma_is_active_rif_tc(uint32_t ch)
{
    return md_dma_is_active_rif(MD_DMA_CH0_TC << (ch * 2));
}
/**
  * @brief  Check if DMA half transfer interrupt is enabled
  * @param  ch: DMA channel
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_dma_is_active_rif_ht(uint32_t ch)
{
    return md_dma_is_active_rif(MD_DMA_CH0_HT << (ch * 2));
}
/**
  * @}
  */
/** @defgroup MD_DMA_Public_Functions_Group14 DMA_CH_SELCON
  * @{
  */
/**
  * @brief  Set channel msel
  * @param  ch: DMA channel
  * @param  msel: This parameter can be one of the @ref md_dma_msel_t
  * @retval None
  */
__STATIC_INLINE void md_dma_set_channel_msel(uint32_t ch, uint32_t msel)
{
    MODIFY_REG(DMA_MUX->CH_SELCON[ch], DMA_SELCON_MSEL_MSK, msel << DMA_SELCON_MSEL_POSS);
}

/**
  * @brief  get channel msel
  * @param  ch: DMA channel
  * @retval The msel, see @ref md_dma_msel_t
  */
__STATIC_INLINE uint32_t md_dma_get_channel_msel(uint32_t ch)
{
    return READ_BITS(DMA_MUX->CH_SELCON[ch], DMA_SELCON_MSEL_MSK, DMA_SELCON_MSEL_POSS);
}

/**
  * @brief  Set channel msigsel
  * @param  ch: DMA channel
  * @param  msigsel: This parameter can be one of the @ref md_dma_msigsel_t
  * @retval None
  */
__STATIC_INLINE void md_dma_set_channel_msigsel(uint32_t ch, uint32_t msigsel)
{
    MODIFY_REG(DMA_MUX->CH_SELCON[ch], DMA_SELCON_MSIGSEL_MSK, msigsel << DMA_SELCON_MSIGSEL_POSS);
}

/**
  * @brief  get channel msigsel
  * @param  ch: DMA channel
  * @retval The msigsel, see @ref md_dma_msigsel_t
  */
__STATIC_INLINE uint32_t md_dma_get_channel_msigsel(uint32_t ch)
{
    return READ_BITS(DMA_MUX->CH_SELCON[ch], DMA_SELCON_MSIGSEL_MSK, DMA_SELCON_MSIGSEL_POSS);
}
/**
  * @}
  */
/** @defgroup MD_DMA_Public_Functions_Group1 Initialization
  * @{
  */
void md_dma_reset(void);
void md_dma_init(uint32_t ch, md_dma_config_t *config);
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
#endif /* __cplusplus */
#endif /* __MD_DMA_H__ */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
