/**
  *********************************************************************************
  *
  * @file    md_i2s.h
  * @brief   Header file of I2S module driver.
  *
  * @version V1.0
  * @date    02 Aug 2022
  * @author  AE Team
  * @note
  *          Change Logs:
  *          Date            Author          Notes
  *          02 Aug 2022     shiwa         The first version
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
  **********************************************************************************
  */

#ifndef __MD_I2S_H__
#define __MD_I2S_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------ */

#include "md_utils.h"

/* Exported Constants -------------------------------------------------------- */

/* Exported Variables -------------------------------------------------------- */

/* Exported Macros ----------------------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_I2S I2S
  * @brief I2S micro driver
  * @{
  */

/* Exported Types ------------------------------------------------------------ */

/** @defgroup MD_I2S_Public_Types I2S Public Types
  * @{
  */
/**
  * @brief Channel length
  */
typedef enum
{
    MD_I2S_WIDE_16 = 0x0U,  /**< Channel length is 16 */
    MD_I2S_WIDE_32 = 0x1U,  /**< Channel length is 32 */
} md_i2s_chlen_t;

/**
  * @brief Data length
  */
typedef enum
{
    MD_I2S_LEN_16 = 0x0U,   /**< Data length is 16 */
    MD_I2S_LEN_24 = 0x1U,   /**< Data length is 24 */
    MD_I2S_LEN_32 = 0x2U,   /**< Data length is 32 */
} md_i2s_datalen_t;

/**
  * @brief Inactive state clock polarity
  */
typedef enum
{
    MD_I2S_INACTIVE_LOW  = 0x0U,    /**< Inactive state is low */
    MD_I2S_INACTIVE_HIGH = 0x1U,    /**< Inactive state is high */
} md_i2s_cpol_t;

/**
  * @brief I2s standard
  */
typedef enum
{
    MD_I2S_STD_PHI = 0x0U,  /**< Philips standard */
    MD_I2S_STD_MSB = 0x1U,  /**< MSB standard */
    MD_I2S_STD_LSB = 0x2U,  /**< LSB standard */
    MD_I2S_STD_PCM = 0x3U,  /**< PCM standard */
} md_i2s_standard_t;

/**
  * @brief I2s configuration mode
  */
typedef enum
{
    MD_I2S_SLAVE_DUPLEX    = 0x0U,  /**< I2S slave full duplex mode */
    MD_I2S_SLAVE_RECEIVE   = 0x1U,  /**< I2S slave receive mode */
    MD_I2S_SLAVE_TRANSMIT  = 0x2U,  /**< I2S slave transmit mode */
    MD_I2S_MASTER_DUPLEX   = 0x4U,  /**< I2S master full duplex mode */
    MD_I2S_MASTER_TRANSMIT = 0x5U,  /**< I2S master transmit mode */
    MD_I2S_MASTER_RECEIVE  = 0x6U,  /**< I2S master receive mode */
} md_i2s_cfg_t;

/**
  * @brief Pcm frame synchronization
  */
typedef enum
{
    MD_I2S_FRAME_SHORT = 0x0U,  /**< I2S PCM short frame */
    MD_I2S_FRAME_LONG  = 0x1U,  /**< I2S PCM long frame */
} md_i2s_pcms_t;

/**
  * @brief Channel side
  */
typedef enum
{
    MD_I2S_SIDE_LEFT  = 0U, /**< Sound channel is left */
    MD_I2S_SIDE_RIGHT = 1U, /**< Sound channel is right */
} md_i2s_ch_side_t;


/**
  * @brief I2S init structure definition
  */
typedef struct
{
    md_i2s_chlen_t ch_len;      /**< Channel length choose */
    md_i2s_datalen_t data_len;  /**< Data length choose */
    md_i2s_cpol_t polarity;     /**< Inactive clock polarity */
    md_i2s_standard_t standard; /**< Standard choose */
    md_i2s_pcms_t pcm_frame;    /**< PCM frame synchronization */
    type_func_t ext_clk_en;     /**< Choose external clock or APB1 clock */
    uint32_t ext_clk;       /**< External clock, unit is Hz */
    type_func_t mck_en;     /**< Main clock output function */
    uint32_t sampling;      /**< Sampling rate. eg. 192KHz/96KHz/48KHz */
} md_i2s_init_t;
/**
  * @}
  */

/* Exported Functions -------------------------------------------------------- */

/** @defgroup MD_I2S_Public_Functions I2S Public Functions
  * @{
  */
/** @defgroup MD_I2S_Public_Functions_Group2 CON2
  * @{
  */
/**
  * @brief  Set I2S receive fifo threshold.
  * @param  I2Sx: I2S Instance.
  * @param  rxth: rx fifo threshold(1, 4, 8, 11)
  *               - 0: 1 char
  *               - 1: 4 chars
  *               - 2: 8 chars
  *               - 3: 14 chars
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_rxfifo_threshold(SPI_I2S_TypeDef *I2Sx, uint8_t rxth)
{
    MODIFY_REG(I2Sx->CON2, SPI_CON2_RXFTH_MSK, (rxth << SPI_CON2_RXFTH_POSS));
}

/**
  * @brief  Get I2S receive fifo threshold.
  * @param  I2Sx: I2S Instance.
  * @retval RX fifo threshold.
  *           - 0: 1 char
  *           - 1: 4 chars
  *           - 2: 8 chars
  *           - 3: 14 chars
  */
__STATIC_INLINE uint8_t md_i2s_get_rxfifo_threshold(SPI_I2S_TypeDef *I2Sx)
{
    return READ_BITS(I2Sx->CON2, SPI_CON2_RXFTH_MSK, SPI_CON2_RXFTH_POSS);
}

/**
  * @brief  Set I2S transmit fifo threshold.
  * @param  I2Sx: I2S Instance.
  * @param  txth: RX fifo threshold(1, 4, 8, 11)
  *               - 0: 1 char
  *               - 1: 4 chars
  *               - 2: 8 chars
  *               - 3: 14 chars
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_txfifo_threshold(SPI_I2S_TypeDef *I2Sx, uint8_t txth)
{
    MODIFY_REG(I2Sx->CON2, SPI_CON2_TXFTH_MSK, (txth << SPI_CON2_TXFTH_POSS));
}

/**
  * @brief  Get spi transmit fifo threshold.
  * @param  I2Sx: SPI Instance.
  * @retval TX fifo threshold.
  *               - 0: 1 char
  *               - 1: 4 chars
  *               - 2: 8 chars
  *               - 3: 14 chars
  */
__STATIC_INLINE uint8_t md_i2s_get_txfifo_threshold(SPI_I2S_TypeDef *I2Sx)
{
    return READ_BITS(I2Sx->CON2, SPI_CON2_TXFTH_MSK, SPI_CON2_TXFTH_POSS);
}

/**
  * @brief  Enable I2S tx_dma function.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_enable_txdma(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->CON2, SPI_CON2_TXDMA_MSK);
}

/**
  * @brief  Disable I2S error interrupt.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_disable_txdma(SPI_I2S_TypeDef *I2Sx)
{
    CLEAR_BIT(I2Sx->CON2, SPI_CON2_TXDMA_MSK);
}

/**
  * @brief  Check if I2S is enable txdma.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enable_txdma(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->CON2, SPI_CON2_TXDMA_MSK) == SPI_CON2_TXDMA_MSK);
}

/**
  * @brief  Enable I2S rx_dma function.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_enable_rxdma(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->CON2, SPI_CON2_RXDMA_MSK);
}

/**
  * @brief  Disable I2S rx_dma function.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_disable_rxdma(SPI_I2S_TypeDef *I2Sx)
{
    CLEAR_BIT(I2Sx->CON2, SPI_CON2_RXDMA_MSK);
}

/**
  * @brief  Check if I2S is enable rxdma.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enable_rxdma(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->CON2, SPI_CON2_RXDMA_MSK) == SPI_CON2_RXDMA_MSK);
}
/**
  * @}
  */
/** @defgroup MD_I2S_Public_Functions_Group3 STAT
  * @{
  */
/**
  * @brief  Get I2S rxfifo value.
  * @param  I2Sx: I2S Instance.
  * @retval rxfifo threshold.
  */
__STATIC_INLINE uint32_t md_i2s_get_rxfifo_value(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BITS(I2Sx->STAT, SPI_STAT_RXFLV_MSK, SPI_STAT_RXFLV_POSS));
}

/**
  * @brief  Get I2S txfifo value.
  * @param  I2Sx: I2S Instance.
  * @retval txfifo threshold.
  */
__STATIC_INLINE uint32_t  md_i2s_get_txfifo_value(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BITS(I2Sx->STAT, SPI_STAT_TXFLV_MSK, SPI_STAT_TXFLV_POSS));
}

/**
  * @brief  Get I2S busy flag.
  * @param  I2Sx: I2S Instance.
  * @retval State I2S bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_busy(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->STAT, SPI_STAT_BUSY_MSK) == SPI_STAT_BUSY_MSK);
}

/**
  * @brief  Get I2S channel side flag.
  * @param  I2Sx: I2S Instance.
  * @retval channel flag (0: left or 1: right).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_chside(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->STAT, SPI_STAT_CHSIDE_MSK) == SPI_STAT_CHSIDE_MSK);
}

/**
  * @brief  Get I2S rx threshold flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_rxth(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->STAT, SPI_STAT_RXTH_MSK) == SPI_STAT_RXTH_MSK);
}

/**
  * @brief  Get I2S rx under flow flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_get_flag_rxud(SPI_I2S_TypeDef *I2Sx)
{
    return ((I2Sx->STAT, SPI_STAT_RXUD_MSK) == SPI_STAT_RXUD_MSK);
}

/**
  * @brief  Get I2S rx over flow flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_get_flag_rxov(SPI_I2S_TypeDef *I2Sx)
{
    return ((I2Sx->STAT, SPI_STAT_RXOV_MSK) == SPI_STAT_RXOV_MSK);
}

/**
  * @brief  Get I2S rx buffer full flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_rxf(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->STAT, SPI_STAT_RXF_MSK) == SPI_STAT_RXF_MSK);
}

/**
  * @brief  Get I2S rx buffer empty flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_rxne(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->STAT, SPI_STAT_RXNE_MSK) == SPI_STAT_RXNE_MSK);
}

/**
  * @brief  Get I2S tx threshold flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_txth(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->STAT, SPI_STAT_TXTH_MSK) == SPI_STAT_TXTH_MSK);
}

/**
  * @brief  Get I2S tx under flow flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_get_flag_txud(SPI_I2S_TypeDef *I2Sx)
{
    return ((I2Sx->STAT, SPI_STAT_TXUD_MSK) == SPI_STAT_TXUD_MSK);
}

/**
  * @brief  Get I2S tx over flow flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_get_flag_txov(SPI_I2S_TypeDef *I2Sx)
{
    return ((I2Sx->STAT, SPI_STAT_TXOV_MSK) == SPI_STAT_TXOV_MSK);
}

/**
  * @brief  Get I2S tx buffer full flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_txf(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->STAT, SPI_STAT_TXF_MSK) == SPI_STAT_TXF_MSK);
}

/**
  * @brief  Get I2S tx buffer empty flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_txe(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->STAT, SPI_STAT_TXE_MSK) == SPI_STAT_TXE_MSK);
}
/**
  * @}
  */
/** @defgroup MD_I2S_Public_Functions_Group4 DATA
  * @{
  */
/**
  * @brief  Set I2S data register value.
  * @param  I2Sx: I2S Instance.
  * @param  data: tx data.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_data_reg(SPI_I2S_TypeDef *I2Sx, uint32_t data)
{
    WRITE_REG(I2Sx->DATA, data);
}

/**
  * @brief  Get I2S data register value.
  * @param  I2Sx: I2S Instance.
  * @retval data: value for data register.
  */
__STATIC_INLINE uint32_t md_i2s_get_data_reg_value(SPI_I2S_TypeDef *I2Sx)
{
    return READ_REG(I2Sx->DATA);
}
/**
  * @}
  */
/** @defgroup MD_I2S_Public_Functions_Group5 I2SCFG
  * @{
  */
/**
  * @brief  Set I2S mode.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_chose_i2s(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->I2SCFG, SPI_I2SCFG_I2SMOD_MSK);
}

/**
  * @brief  Check is set I2S mode.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (0:SPI or 1:I2S).
  */
__STATIC_INLINE uint32_t md_i2s_is_set_i2s_mode(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->I2SCFG, SPI_I2SCFG_I2SMOD_MSK) == SPI_I2SCFG_I2SMOD_MSK);
}

/**
  * @brief  Enable I2S module.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_enable(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->I2SCFG, SPI_I2SCFG_I2SE_MSK);
}

/**
  * @brief  Disable I2S module.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_disable(SPI_I2S_TypeDef *I2Sx)
{
    CLEAR_BIT(I2Sx->I2SCFG, SPI_I2SCFG_I2SE_MSK);
}

/**
  * @brief  Check if I2S is enable.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enable(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->I2SCFG, SPI_I2SCFG_I2SE_MSK) == SPI_I2SCFG_I2SE_MSK);
}

/**
  * @brief  Set TX/RX mode.
  * @param  I2Sx: I2S Instance.
  * @param  mode: 0x2 - TX, 0x3 - RX.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_mode(SPI_I2S_TypeDef *I2Sx, uint32_t mode)
{
    MODIFY_REG(I2Sx->I2SCFG, SPI_I2SCFG_I2SCFG_MSK, mode << SPI_I2SCFG_I2SCFG_POSS);
}

/**
  * @brief  Get TX/RX mode.
  * @param  I2Sx: I2S Instance.
  * @retval Mode:
  *           - 0x2: TX
  *           - 0x3: RX
  */
__STATIC_INLINE uint32_t md_i2s_get_mode(SPI_I2S_TypeDef *I2Sx)
{
    return READ_BITS(I2Sx->I2SCFG, SPI_I2SCFG_I2SCFG_MSK, SPI_I2SCFG_I2SCFG_POSS);
}

/**
  * @brief  Set PCM short frame.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_short_frame(SPI_I2S_TypeDef *I2Sx)
{
    CLEAR_BIT(I2Sx->I2SCFG, SPI_I2SCFG_PCMSYNC_MSK);
}

/**
  * @brief  Set PCM long frame.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_long_frame(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->I2SCFG, SPI_I2SCFG_PCMSYNC_MSK);
}

/**
  * @brief  Get PCM frame mode.
  * @param  I2Sx: I2S Instance.
  * @retval PCM frame mode:
  *           -0: Short frame
  *           -1: Long frame
  */
__STATIC_INLINE uint32_t md_i2s_get_frame_mode(SPI_I2S_TypeDef *I2Sx)
{
    return READ_BITS(I2Sx->I2SCFG, SPI_I2SCFG_PCMSYNC_MSK, SPI_I2SCFG_PCMSYNC_POS);
}

/**
  * @brief  Set I2S standard.
  * @param  I2Sx: I2S Instance.
  * @param  std: I2S standard, @ref md_i2s_standard_t
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_standard(SPI_I2S_TypeDef *I2Sx, md_i2s_standard_t std)
{
    MODIFY_REG(I2Sx->I2SCFG, SPI_I2SCFG_I2SSTD_MSK, std << SPI_I2SCFG_I2SSTD_POSS);
}

/**
  * @brief  Get I2S standard.
  * @param  I2Sx: I2S Instance.
  * @retval I2S standard, @ref md_i2s_standard_t
  */
__STATIC_INLINE md_i2s_standard_t md_i2s_get_standard(SPI_I2S_TypeDef *I2Sx)
{
    return (md_i2s_standard_t)READ_BITS(I2Sx->I2SCFG, SPI_I2SCFG_I2SSTD_MSK, SPI_I2SCFG_I2SSTD_POSS);
}

/**
  * @brief  Set I2S clock polarity.
  * @param  I2Sx: I2S Instance.
  * @param  pol: 0 - low, 1 - high.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_inactive_polarity(SPI_I2S_TypeDef *I2Sx, uint32_t pol)
{
    MODIFY_REG(I2Sx->I2SCFG, SPI_I2SCFG_CKPOL_MSK, pol << SPI_I2SCFG_CKPOL_POS);
}

/**
  * @brief  Get I2S clock polarity.
  * @param  I2Sx: I2S Instance.
  * @retval I2S polarity:
  *           - 0: low
  *           - 1: high
  */
__STATIC_INLINE uint32_t md_i2s_get_inactive_polarity(SPI_I2S_TypeDef *I2Sx)
{
    return READ_BITS(I2Sx->I2SCFG, SPI_I2SCFG_CKPOL_MSK, SPI_I2SCFG_CKPOL_POS);
}

/**
  * @brief  Set I2S data length.
  * @param  I2Sx: I2S Instance.
  * @param  length:
  *           - 0: 16-bits
  *           - 1: 24-bits
  *           - 2: 32-bits
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_data_length(SPI_I2S_TypeDef *I2Sx, uint32_t length)
{
    MODIFY_REG(I2Sx->I2SCFG, SPI_I2SCFG_DATLEN_MSK, length << SPI_I2SCFG_DATLEN_POSS);
}

/**
  * @brief  Get I2S data length.
  * @param  I2Sx: I2S Instance.
  * @retval Data length:
  *           - 0: 16-bits
  *           - 1: 24-bits
  *           - 2: 32-bits
  */
__STATIC_INLINE uint32_t md_i2s_get_data_length(SPI_I2S_TypeDef *I2Sx)
{
    return READ_BITS(I2Sx->I2SCFG, SPI_I2SCFG_DATLEN_MSK, SPI_I2SCFG_DATLEN_POSS);
}

/**
  * @brief  Set I2S channel length.
  * @param  I2Sx: I2S Instance.
  * @param  length:
  *           - 0: 16-bits
  *           - 1: 32-bits
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_channel_length(SPI_I2S_TypeDef *I2Sx, uint32_t length)
{
    MODIFY_REG(I2Sx->I2SCFG, SPI_I2SCFG_CHLEN_MSK, length << SPI_I2SCFG_CHLEN_POS);
}

/**
  * @brief  Get I2S channel length.
  * @param  I2Sx: I2S Instance.
  * @retval Channel length:
  *           - 0: 16-bits
  *           - 1: 32-bits
  */
__STATIC_INLINE uint32_t md_i2s_get_channel_length(SPI_I2S_TypeDef *I2Sx)
{
    return READ_BITS(I2Sx->I2SCFG, SPI_I2SCFG_CHLEN_MSK, SPI_I2SCFG_CHLEN_POS);
}
/**
  * @}
  */
/** @defgroup MD_I2S_Public_Functions_Group6 I2SPR
  * @{
  */
/**
  * @brief  Set I2S clock source.
  * @param  I2Sx: I2S Instance.
  * @param  clk: Clock source
  *           - 0: APB1
  *           - 1: Extend clock
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_clock_cource(SPI_I2S_TypeDef *I2Sx, uint32_t clk)
{
    MODIFY_REG(I2Sx->I2SPR, SPI_I2SPR_EXTCKEN_MSK, clk << SPI_I2SPR_EXTCKEN_POS);
}

/**
  * @brief  Get I2S clock source.
  * @param  I2Sx: I2S Instance.
  * @retval Clock source:
  *           - 0: APB1
  *           - 1: Extend clock
  */
__STATIC_INLINE uint32_t md_i2s_get_clock_cource(SPI_I2S_TypeDef *I2Sx)
{
    return READ_BITS(I2Sx->I2SPR, SPI_I2SPR_EXTCKEN_MSK, SPI_I2SPR_EXTCKEN_POS);
}

/**
  * @brief  Enable I2S main clock output.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_enable_mclock(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->I2SPR, SPI_I2SPR_MCKOE_MSK);
}

/**
  * @brief  Disable I2S main clock output.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_disable_mclock(SPI_I2S_TypeDef *I2Sx)
{
    CLEAR_BIT(I2Sx->I2SPR, SPI_I2SPR_MCKOE_MSK);
}

/**
  * @brief  Check if main clock output is enable.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enable_mclock(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->I2SPR, SPI_I2SPR_MCKOE_MSK) == SPI_I2SPR_MCKOE_MSK);
}

/**
  * @brief  Set I2S odd coefficient.
  * @param  I2Sx: I2S Instance.
  * @param  odd: Odd coefficient
  *           - 0: Frequency division = I2SDIV * 2
  *           - 1: Frequency division = (I2SDIV * 2) + 1
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_div_odd(SPI_I2S_TypeDef *I2Sx, uint32_t odd)
{
    MODIFY_REG(I2Sx->I2SPR, SPI_I2SPR_ODD_MSK, odd << SPI_I2SPR_ODD_POS);
}

/**
  * @brief  Get I2S odd coefficient.
  * @param  I2Sx: I2S Instance.
  * @retval Odd coefficient:
  *           - 0: Frequency division = I2SDIV * 2
  *           - 1: Frequency division = (I2SDIV * 2) + 1
  */
__STATIC_INLINE uint32_t md_i2s_get_div_odd(SPI_I2S_TypeDef *I2Sx)
{
    return READ_BITS(I2Sx->I2SPR, SPI_I2SPR_ODD_MSK, SPI_I2SPR_ODD_POS);
}

/**
  * @brief  Set I2S division
  * @param  I2Sx: I2S Instance.
  * @param  div: Frequency division.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_div(SPI_I2S_TypeDef *I2Sx, uint32_t div)
{
    MODIFY_REG(I2Sx->I2SPR, SPI_I2SPR_I2SDIV_MSK, div << SPI_I2SPR_I2SDIV_POSS);
}

/**
  * @brief  Get I2S division.
  * @param  I2Sx: I2S Instance.
  * @retval Frequency division.
  */
__STATIC_INLINE uint32_t md_i2s_get_div(SPI_I2S_TypeDef *I2Sx)
{
    return READ_BITS(I2Sx->I2SPR, SPI_I2SPR_I2SDIV_MSK, SPI_I2SPR_I2SDIV_POSS);
}
/**
  * @}
  */
/** @defgroup MD_I2S_Public_Functions_Group7 IER
  * @{
  */
/**
  * @brief  Enable I2S frame error interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_fre(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IER, SPI_IER_FRE_MSK);
}

/**
  * @brief  Enable I2S rx threshold interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_rxth(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IER, SPI_IER_RXTH_MSK);
}

/**
  * @brief  Enable I2S rx under flow interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_rxud(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IER, SPI_IER_RXUD_MSK);
}


/**
  * @brief  Enable I2S rx over flow interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_rxov(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IER, SPI_IER_RXOV_MSK);
}

/**
  * @brief  Enable I2S rx full interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_rxf(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IER, SPI_IER_RXF_MSK);
}

/**
  * @brief  Enable I2S tx threshold interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_txth(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IER, SPI_IER_TXTH_MSK);
}

/**
  * @brief  Enable I2S tx under flow interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_txud(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IER, SPI_IER_TXUD_MSK);
}

/**
  * @brief  Enable I2S tx over flow interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_txov(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IER, SPI_IER_TXOV_MSK);
}

/**
  * @brief  Enable I2S tx empty interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_txe(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IER, SPI_IER_TXE_MSK);
}
/**
  * @}
  */
/** @defgroup MD_I2S_Public_Functions_Group8 IDR
  * @{
  */
/**
  * @brief  Disable I2S frame error interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_fre(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IDR, SPI_IDR_FRE_MSK);
}

/**
  * @brief  Disable I2S rx threshold interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_rxth(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IDR, SPI_IDR_RXTH_MSK);
}

/**
  * @brief  Disable I2S rx under flow interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_rxud(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IDR, SPI_IDR_RXUD_MSK);
}

/**
  * @brief  Disable I2S rx over flow interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_rxov(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IDR, SPI_IDR_RXOV_MSK);
}

/**
  * @brief  Disable I2S rx full interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_rxf(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IDR, SPI_IDR_RXF_MSK);
}

/**
  * @brief  Disable I2S tx threshold interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_txth(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IDR, SPI_IDR_TXTH_MSK);
}

/**
  * @brief  Disable I2S tx under flow interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_txud(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IDR, SPI_IDR_TXUD_MSK);
}

/**
  * @brief  Disable I2S tx over flow interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_txov(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IDR, SPI_IDR_TXOV_MSK);
}

/**
  * @brief  Disable I2S tx empty interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_txe(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->IDR, SPI_IDR_TXE_MSK);
}
/**
  * @}
  */
/** @defgroup MD_I2S_Public_Functions_Group9 IVS
  * @{
  */
/**
  * @brief  Check if the frame error interrupt is enabled or disabled.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enable_it_fre(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IVS, SPI_IVS_FRE_MSK) == (SPI_IVS_FRE_MSK));
}

/**
  * @brief  Check if the rx threshold interrupt is enabled or disabled.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enable_it_rxth(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IVS, SPI_IVS_RXTH_MSK) == (SPI_IVS_RXTH_MSK));
}

/**
  * @brief  Check if the rx under flow interrupt is enabled or disabled.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enable_it_rxud(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IVS, SPI_IVS_RXUD_MSK) == (SPI_IVS_RXUD_MSK));
}

/**
  * @brief  Check if the rx over flow interrupt is enabled or disabled.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enable_it_rxov(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IVS, SPI_IVS_RXOV_MSK) == (SPI_IVS_RXOV_MSK));
}

/**
  * @brief  Check if the rx full interrupt is enabled or disabled.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enable_it_rxf(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IVS, SPI_IVS_RXF_MSK) == (SPI_IVS_RXF_MSK));
}

/**
  * @brief  Check if the tx threshold interrupt is enabled or disabled.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enable_it_txth(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IVS, SPI_IVS_TXTH_MSK) == (SPI_IVS_TXTH_MSK));
}

/**
  * @brief  Check if the tx under flow interrupt is enabled or disabled.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enable_it_txud(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IVS, SPI_IVS_TXUD_MSK) == (SPI_IVS_TXUD_MSK));
}

/**
  * @brief  Check if the tx over flow interrupt is enabled or disabled.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enable_it_txov(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IVS, SPI_IVS_TXOV_MSK) == (SPI_IVS_TXOV_MSK));
}

/**
  * @brief  Check if the tx empty interrupt is enabled or disabled.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enable_it_txe(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IVS, SPI_IVS_TXE_MSK) == (SPI_IVS_TXE_MSK));
}
/**
  * @}
  */
/** @defgroup MD_I2S_Public_Functions_Group10 RIF
  * @{
  */
/**
  * @brief  Get frame error interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_fre(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->RIF, SPI_RIF_FRE_MSK) == (SPI_RIF_FRE_MSK));
}

/**
  * @brief  Get rx threshold interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_rxth(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->RIF, SPI_RIF_RXTH_MSK) == (SPI_RIF_RXTH_MSK));
}

/**
  * @brief  Get rx under flow interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_rxud(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->RIF, SPI_RIF_RXUD_MSK) == (SPI_RIF_RXUD_MSK));
}

/**
  * @brief  Get rx over flow interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_rxov(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->RIF, SPI_RIF_RXOV_MSK) == (SPI_RIF_RXOV_MSK));
}

/**
  * @brief  Get rx full interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_rxf(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->RIF, SPI_RIF_RXF_MSK) == (SPI_RIF_RXF_MSK));
}

/**
  * @brief  Get tx threshold interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_txth(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->RIF, SPI_RIF_TXTH_MSK) == (SPI_RIF_TXTH_MSK));
}

/**
  * @brief  Get tx under flow interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_txud(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->RIF, SPI_RIF_TXUD_MSK) == (SPI_RIF_TXUD_MSK));
}

/**
  * @brief  Get tx over flow interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_txov(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->RIF, SPI_RIF_TXOV_MSK) == (SPI_RIF_TXOV_MSK));
}

/**
  * @brief  Get tx empty interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_txe(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->RIF, SPI_RIF_TXE_MSK) == (SPI_RIF_TXE_MSK));
}
/**
  * @}
  */
/** @defgroup MD_I2S_Public_Functions_Group11 IFM
  * @{
  */
/**
  * @brief  Mask frame error interrupt.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_mask_it_fre(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IFM, SPI_IFM_FRE_MSK) == SPI_IFM_FRE_MSK);
}

/**
  * @brief  Mask rx threshold interrupt.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_mask_it_rxth(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IFM, SPI_IFM_RXTH_MSK) == SPI_IFM_RXTH_MSK);
}

/**
  * @brief  Mask rx under flow interrupt.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_mask_it_rxud(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IFM, SPI_IFM_RXUD_MSK) == SPI_IFM_RXUD_MSK);
}

/**
  * @brief  Mask rx over flow interrupt.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_mask_it_rxov(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IFM, SPI_IFM_RXOV_MSK) == SPI_IFM_RXOV_MSK);
}

/**
  * @brief  Mask rx full interrupt.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_mask_it_rxf(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IFM, SPI_IFM_RXF_MSK) == SPI_IFM_RXF_MSK);
}

/**
  * @brief  Mask tx threshold interrupt.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_mask_it_txth(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IFM, SPI_IFM_TXTH_MSK) == SPI_IFM_TXTH_MSK);
}

/**
  * @brief  Mask tx under flow interrupt.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_mask_it_txud(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IFM, SPI_IFM_TXUD_MSK) == SPI_IFM_TXUD_MSK);
}

/**
  * @brief  Mask tx over flow interrupt.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_mask_it_txov(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IFM, SPI_IFM_TXOV_MSK) == SPI_IFM_TXOV_MSK);
}

/**
  * @brief  Mask tx empty interrupt.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_mask_it_txe(SPI_I2S_TypeDef *I2Sx)
{
    return (READ_BIT(I2Sx->IFM, SPI_IFM_TXE_MSK) == SPI_IFM_TXE_MSK);
}
/**
  * @}
  */
/** @defgroup MD_I2S_Public_Functions_Group12 ICR
  * @{
  */
/**
  * @brief  Clear frame error interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_flag_fre(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->ICR, SPI_ICR_FRE_MSK);
}

/**
  * @brief  Clear rx under flow interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_flag_rxth(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->ICR, SPI_ICR_RXTH_MSK);
}

/**
  * @brief  Clear rx under flow interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_flag_rxud(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->ICR, SPI_ICR_RXUD_MSK);
}

/**
  * @brief  Clear rx over flow interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_flag_rxov(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->ICR, SPI_ICR_RXOV_MSK);
}

/**
  * @brief  Clear rx full interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_flag_rxf(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->ICR, SPI_ICR_RXF_MSK);
}

/**
  * @brief  Clear tx under flow interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_flag_txth(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->ICR, SPI_ICR_TXTH_MSK);
}

/**
  * @brief  Clear tx under flow interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_flag_txud(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->ICR, SPI_ICR_TXUD_MSK);
}

/**
  * @brief  Clear tx over flow interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_flag_txov(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->ICR, SPI_ICR_TXOV_MSK);
}

/**
  * @brief  Clear tx empty interrupt flag.
  * @param  I2Sx I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_flag_txe(SPI_I2S_TypeDef *I2Sx)
{
    SET_BIT(I2Sx->ICR, SPI_ICR_TXE_MSK);
}
/**
  * @}
  */
/** @defgroup MD_I2S_Public_Functions_Group1 Initialization
  * @{
  */
extern void md_i2s_reset(SPI_I2S_TypeDef *I2Sx);
extern md_status_t md_i2s_init(SPI_I2S_TypeDef *I2Sx, md_i2s_init_t *init);
extern void md_i2s_struct_init(md_i2s_init_t *init);
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

#endif /* __MD_I2S_H__ */
