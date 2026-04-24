/**********************************************************************************
 *
 * @file    md_spi.h
 * @brief   Header file of SPI module driver.
 *
 * @date    28 Dec. 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          28 Dec. 2022    Lisq            the first version
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

#ifndef __MD_SPI_H__
#define __MD_SPI_H__

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

/** @defgroup MD_SPI SPI
  * @brief SPI micro driver
  * @{
  */

/* Exported Types ------------------------------------------------------------ */

/** @defgroup MD_SPI_Public_Types SPI Public Types
  * @{
  */
/**
  * @brief clock phase
  */
typedef enum
{
    MD_SPI_CPHA_FIRST  = 0U,    /**< Transiting data in the first edge */
    MD_SPI_CPHA_SECOND = 1U,    /**< Transiting data in the seconde edge */
} md_spi_cpha_t;

/**
  * @brief clock polarity
  */
typedef enum
{
    MD_SPI_CPOL_LOW  = 0U,  /**< Polarity hold low when spi-bus is idle */
    MD_SPI_CPOL_HIGH = 1U,  /**< Polarity hold high when spi-bus is idle */
} md_spi_cpol_t;

/**
  * @brief master selection
  */
typedef enum
{
    MD_SPI_MODE_SLAVER = 0U,    /**< Slave mode */
    MD_SPI_MODE_MASTER = 1U,    /**< Master mode */
} md_spi_mode_t;

/**
  * @brief baud rate control
  */
typedef enum
{
    MD_SPI_BAUD_2   = 0U,   /**< fpclk/2 */
    MD_SPI_BAUD_4   = 1U,   /**< fpclk/4 */
    MD_SPI_BAUD_8   = 2U,   /**< fpclk/8 */
    MD_SPI_BAUD_16  = 3U,   /**< fpclk/16 */
    MD_SPI_BAUD_32  = 4U,   /**< fpclk/32 */
    MD_SPI_BAUD_64  = 5U,   /**< fpclk/64 */
    MD_SPI_BAUD_128 = 6U,   /**< fpclk/128 */
    MD_SPI_BAUD_256 = 7U,   /**< fpclk/256 */
} md_md_spi_baud_t;

/**
  * @brief frame format
  */
typedef enum
{
    MD_SPI_FIRSTBIT_MSB = 0U,   /**< MSB transmitted first */
    MD_SPI_FIRSTBIT_LSB = 1U,   /**< LSB transmitted first */
} md_spi_firstbit_t;

/**
  * @brief data frame format
  */
typedef enum
{
    MD_SPI_DATA_SIZE_8  = 0U,   /**< 8-bit data frame format is selected for transmission/reception */
    MD_SPI_DATA_SIZE_16 = 1U,   /**< 16-bit data frame format is selected for transmission/reception */
} md_spi_datasize_t;

/**
  * @brief SPI direction definition
  */
typedef enum
{
    MD_SPI_DIRECTION_2LINES        = 0U,    /**< 2 lines */
    MD_SPI_DIRECTION_2LINES_RXONLY = 1U,    /**< 2 lines only rx */
    MD_SPI_DIRECTION_1LINE         = 2U,    /**< 1 line */
    MD_SPI_DIRECTION_1LINE_RX      = 3U,    /**< 1 line only rx */
} md_spi_direction_t;

/**
  * @brief SPI crc length definition
  */
typedef enum
{
    MD_SPI_FRAME_MOTOROLA = 0U, /**< SPI motorola mode */
    MD_SPI_FRAME_TI       = 1U, /**< SPI TI mode */
} md_spi_frame_t;

/**
  * @brief SPI init structure definition
  */
typedef struct
{
    SPI_I2S_TypeDef *SPIx;      /**< SPI peripheral */
    md_spi_mode_t mode;     /**< SPI mode */
    md_spi_direction_t dir;     /**< SPI direction */
    md_spi_datasize_t data_size;    /**< SPI data size */
    md_md_spi_baud_t baud;      /**< SPI baudrate prescaler */
    md_spi_cpha_t phase;        /**< SPI clock phase */
    md_spi_cpol_t polarity;     /**< SPI clock polarity */
    md_spi_firstbit_t first_bit;    /**< SPI first bit */
    type_func_t ss_en;      /**< SPI ssm enable or disable */
    type_func_t crc_calc;       /**< SPI crc calculation */
    md_spi_frame_t frame;              /**< SPI frame format */
    uint16_t crc_poly;      /**< SPI crc polynomial */
} md_spi_init_t;
/**
  * @}
  */

/* Exported Functions -------------------------------------------------------- */

/** @defgroup MD_SPI_Public_Functions SPI Public Functions
  * @{
  */
/** @defgroup MD_SPI_Public_Functions_Group2 CON1
  * @{
  */
/**
  * @brief  Set spi duplex line simplex direction commumication.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_duplex_line_simplex(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_BIDEN_MSK);
}

/**
  * @brief  Set spi simplex line duplex direction commumication.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_simplex_line_duplex(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_BIDEN_MSK);
}

/**
  * @brief  Check if spi is Enable duplex line simplex direction commumication.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t md_spi_is_enable_duplex_line_simplex(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_BIDEN_MSK) != SPI_CON1_BIDEN_MSK);
}

/**
  * @brief  Check if spi is Enable simplex line duplex direction commumication
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t md_spi_is_enable_simplex_line_duplex(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_BIDEN_MSK) == SPI_CON1_BIDEN_MSK);
}

/**
  * @brief  Enable spi duplex line mode data transmit.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_simplex_line_tx(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_BIDOEN_MSK);
}

/**
  * @brief  Enable spi duplex line mode data receive.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_simplex_line_rx(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_BIDOEN_MSK);
}

/**
  * @brief  Check if spi is enable duplex line mode data transmit.
  * @param  SPIx: SPI Instance.
  * @retval State:
  *           - 1: transmit
  *           - 0: receive
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_simplex_line_tx(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_BIDOEN_MSK) == SPI_CON1_BIDOEN_MSK);
}

/**
  * @brief  Enable spi crc by hardware.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_crc_hardware(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_CRCEN_MSK);
}

/**
  * @brief  Disable spi crc by hardware.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_crc_hardware(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_CRCEN_MSK);
}

/**
  * @brief  Check if spi is enable crc by hardware.
  * @param  SPIx: SPI Instance.
  * @retval State for 1 or 0.
  */
__STATIC_INLINE uint32_t md_spi_is_enable_crc_hardware(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_CRCEN_MSK) == SPI_CON1_CRCEN_MSK);
}

/**
  * @brief  Enable spi next time transmit is crc.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_next_crc_transmit(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_NXTCRC_MSK);
}

/**
  * @brief  Disable spi next time transmit is crc.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_next_crc_transmit(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_NXTCRC_MSK);
}

/**
  * @brief  Check if spi is enable next time transmit is crc.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_next_crc_transmit(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_NXTCRC_MSK) == SPI_CON1_NXTCRC_MSK);
}

/**
  * @brief  Enable spi 16 bytes commumication data .
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_16_byte_commumication(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_FLEN_MSK);
}

/**
  * @brief  Enable spi 8 bytes commumication data .
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_8_byte_commumication(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_FLEN_MSK);
}

/**
  * @brief  Check if spi is enable 16 bytes commumication data.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_16_byte_commumication(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_FLEN_MSK) == SPI_CON1_FLEN_MSK);
}

/**
  * @brief  Check if spi is enable 8 bytes commumication data.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_8_byte_commumication(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_FLEN_MSK) != SPI_CON1_FLEN_MSK);
}

/**
  * @brief  Enable spi only receive mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_recv_only(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_RXO_MSK);
}

/**
  * @brief  Disable spi only receive mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_disable_recv_only(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_RXO_MSK);
}

/**
  * @brief  Check if spi is enable only receive mode.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint8_t md_spi_is_enable_recv_only(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_RXO_MSK) == SPI_CON1_RXO_MSK);
}

/**
  * @brief  Enable spi control slave device by software.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_control_slave(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_SSEN_MSK);
}

/**
  * @brief  Disable spi control slave device by software.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_disable_control_slave(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_SSEN_MSK);
}

/**
  * @brief  Check if spi is enable control slave device by software.
  * @param  SPIx: SPI Instance.
  * @retval State for bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_control_slave(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_SSEN_MSK) == SPI_CON1_SSEN_MSK);
}

/**
  * @brief  Enable spi chip select output high.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_ss_output_high(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_SSOUT_MSK);
}

/**
  * @brief  Enable spi chip select output low.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_ss_output_low(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_SSOUT_MSK);
}

/**
  * @brief  Check if spi is enable chip select output high.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_ss_output_high(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_SSOUT_MSK) == SPI_CON1_SSOUT_MSK);
}

/**
  * @brief  Enable spi data first transmit MSB.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_first_transmit_msb(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_LSBFST_MSK);
}

/**
  * @brief  Enable spi data first transmit LSB.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_first_transmit_lsb(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_LSBFST_MSK);
}

/**
  * @brief  Check if spi is enable data first transmit MSB.
  * @param  SPIx: SPI Instance.
  * @retval State:
  *           - 1: LSB first
  *           - 0: MSB first
  */
__STATIC_INLINE uint32_t md_spi_is_enable_first_transmit_msb(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_LSBFST_MSK) != SPI_CON1_LSBFST_MSK);
}

/**
  * @brief  Enable SPI module.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_SPIEN_MSK);
}

/**
  * @brief  Disable SPI module.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_disable(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_SPIEN_MSK);
}

/**
  * @brief  Check if is enable spi.
  * @param  SPIx: SPI Instance.
  * @retval State for bit (1 or 0)
  */
__STATIC_INLINE uint32_t md_spi_is_enable(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_SPIEN_MSK) == SPI_CON1_SPIEN_MSK);
}

/**
  * @brief  Set spi commumication baudrate.
  * @param  SPIx: SPI Instance.
  * @param  baud: specific commumication rate @see md_spi_baud_t.
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_commumication_baud(SPI_I2S_TypeDef *SPIx, md_md_spi_baud_t baud)
{
    MODIFY_REG(SPIx->CON1, SPI_CON1_BAUD_MSK, baud << SPI_CON1_BAUD_POSS);
}

/**
  * @brief  Get spi commumication baudrate.
  * @param  SPIx: SPI Instance.
  * @retval specific commumication rate @see md_spi_baud_t.
  */
__STATIC_INLINE uint32_t md_spi_get_commumication_baud(SPI_I2S_TypeDef *SPIx)
{
    return READ_BITS(SPIx->CON1, SPI_CON1_BAUD_MSK, SPI_CON1_BAUD_POSS);
}

/**
  * @brief  Enable spi master mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_master_mode(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_MSTREN_MSK);
}

/**
  * @brief  Enable spi slave mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_slave_mode(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_MSTREN_MSK);
}
/**
  * @brief  Check if spi is enable master mode.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_master_mode(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_MSTREN_MSK) == SPI_CON1_MSTREN_MSK);
}

/**
  * @brief  Enable spi sck bus keep high polarity in idle mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_sck_high_idle(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_CPOL_MSK);
}

/**
  * @brief  Enable spi sck bus keep low polarity in idle mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_sck_low_idle(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_CPOL_MSK);
}

/**
  * @brief  Check if spi is enable sck keep high in idle.
  * @param  SPIx: SPI Instance.
  * @retval State:
  *           - 1: SCK high in idle
  *           - 0: SCK low in idle
  */
__STATIC_INLINE uint32_t md_spi_is_enable_sck_high_idle(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_CPOL_MSK) == SPI_CON1_CPOL_MSK);
}

/**
  * @brief  Enable spi sample data in seconde time edge.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_sample_sec_edge(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_CPHA_MSK);
}

/**
  * @param  SPIx: SPI Instance.
  * @brief  Enable spi sample data in first time edge.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_sample_first_edge(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_CPHA_MSK);
}

/**
  * @brief  Check is spi is enable sample data in seconde time edge.
  * @param  SPIx: SPI Instance.
  * @retval State:
  *           - 1: Sample in second edge
  *           - 0: Sample in first edge
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_sample_sec_edge(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_CPHA_MSK) == SPI_CON1_CPHA_MSK);
}
/**
  * @}
  */
/** @defgroup MD_SPI_Public_Functions_Group3 CON2
  * @{
  */
/**
  * @brief  Set spi receive fifo threshold.
  * @param  SPIx: SPI Instance.
  * @param  rxth: rx fifo threshold(1, 4, 8, 11)
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_rxfifo_threshold(SPI_I2S_TypeDef *SPIx, uint8_t rxth)
{
    MODIFY_REG(SPIx->CON2, SPI_CON2_RXFTH_MSK, (rxth << SPI_CON2_RXFTH_POSS));
}

/**
  * @brief  Get spi receive fifo threshold.
  * @param  SPIx: SPI Instance.
  * @retval Rx fifo threshold.
  */
__STATIC_INLINE uint8_t md_spi_get_rxfifo_threshold(SPI_I2S_TypeDef *SPIx)
{
    return READ_BITS(SPIx->CON2, SPI_CON2_RXFTH_MSK, SPI_CON2_RXFTH_POSS);
}

/**
  * @brief  Set spi transmit fifo threshold.
  * @param  SPIx: SPI Instance.
  * @param  rxth: rx fifo threshold(1, 4, 8, 11)
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_txfifo_threshold(SPI_I2S_TypeDef *SPIx, uint8_t rxth)
{
    MODIFY_REG(SPIx->CON2, SPI_CON2_TXFTH_MSK, (rxth << SPI_CON2_TXFTH_POSS));
}

/**
  * @brief  Get spi transmit fifo threshold.
  * @param  SPIx: SPI Instance.
  * @retval TX fifo threshold.
  */
__STATIC_INLINE uint8_t md_spi_get_txfifo_threshold(SPI_I2S_TypeDef *SPIx)
{
    return READ_BITS(SPIx->CON2, SPI_CON2_TXFTH_MSK, SPI_CON2_TXFTH_POSS);
}

/**
  * @brief  Set MOTO TI mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_moto_mode(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON2, SPI_CON2_FRF_MSK);
}

/**
  * @brief  Set MOTO SPI mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_ti_mode(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON2, SPI_CON2_FRF_MSK);
}

/**
  * @brief  Get spi mode.
  * @param  SPIx: SPI Instance.
  * @retval SPI mode(0: MOTO 1: TI).
  */
__STATIC_INLINE uint8_t md_spi_get_mode(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON2, SPI_CON2_FRF_MSK) == SPI_CON2_FRF_MSK);
}

/**
  * @brief  Produce spi clock(master mode).
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_nss_pulse(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON2, SPI_CON2_NSSP_MSK);
}

/**
  * @brief  Stop spi clock(master mode).
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_disable_nss_pulse(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON2, SPI_CON2_NSSP_MSK);
}

/**
  * @brief  Get spi clock(master mode).
  * @param  SPIx: SPI Instance.
  * @retval SPI mode(0: CLK Disable 1: CLK Enable).
  */
__STATIC_INLINE uint8_t md_spi_is_enabled_nss_pulse(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON2, SPI_CON2_NSSP_MSK) == SPI_CON2_NSSP_MSK);
}

/**
  * @brief  Enable nss output clock function.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_nss_output(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON2, SPI_CON2_NSSOE_MSK);
}

/**
  * @brief  Disable nss output clock function.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_disable_nss_output(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON2, SPI_CON2_NSSOE_MSK);
}

/**
  * @brief  Get nss output clock function..
  * @param  SPIx: SPI Instance.
  * @retval nss mode(0: Output Disable 1: Output Enable).
  */
__STATIC_INLINE uint8_t md_spi_is_enabled_nss_output(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON2, SPI_CON2_NSSOE_MSK) == SPI_CON2_NSSOE_MSK);
}

/**
  * @brief  Enable spi tx_dma function.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_txdma(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON2, SPI_CON2_TXDMA_MSK);
}

/**
  * @brief  Disable spi error interrupt.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_disable_txdma(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON2, SPI_CON2_TXDMA_MSK);
}

/**
  * @brief  Check if spi is enable txdma.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_txdma(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON2, SPI_CON2_TXDMA_MSK) == SPI_CON2_TXDMA_MSK);
}

/**
  * @brief  Enable spi rx_dma function.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_rxdma(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON2, SPI_CON2_RXDMA_MSK);
}

/**
  * @brief  Disable spi rx_dma function.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_disable_rxdma(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON2, SPI_CON2_RXDMA_MSK);
}

/**
  * @brief  Check if spi is enable rxdma.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_rxdma(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON2, SPI_CON2_RXDMA_MSK) == SPI_CON2_RXDMA_MSK);
}
/**
  * @}
  */
/** @defgroup MD_SPI_Public_Functions_Group4 STAT
  * @{
  */
/**
  * @brief  Get spi rxfifo value.
  * @param  SPIx: SPI Instance.
  * @retval rxfifo threshold.
  */
__STATIC_INLINE uint32_t md_spi_get_rxfifo_value(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BITS(SPIx->STAT, SPI_STAT_RXFLV_MSK, SPI_STAT_RXFLV_POSS));
}

/**
  * @brief  Get spi txfifo value.
  * @param  SPIx: SPI Instance.
  * @retval txfifo threshold.
  */
__STATIC_INLINE uint32_t md_spi_get_txfifo_value(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BITS(SPIx->STAT, SPI_STAT_TXFLV_MSK, SPI_STAT_TXFLV_POSS));
}

/**
  * @brief  Get spi busy flag.
  * @param  SPIx: SPI Instance.
  * @retval State for bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_busy(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_BUSY_MSK) == SPI_STAT_BUSY_MSK);
}

/**
  * @brief  Get spi rx threshold flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_rxth(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_RXTH_MSK) == SPI_STAT_RXTH_MSK);
}

/**
  * @brief  Get spi rx under flow flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_get_flag_rxud(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_RXUD_MSK) == SPI_STAT_RXUD_MSK);
}

/**
  * @brief  Get spi rx over flow flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_get_flag_rxov(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_RXOV_MSK) == SPI_STAT_RXOV_MSK);
}

/**
  * @brief  Get spi rx buffer full flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_rxf(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_RXF_MSK) == SPI_STAT_RXF_MSK);
}

/**
  * @brief  Get spi rx buffer not empty flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_rxne(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_RXNE_MSK) == SPI_STAT_RXNE_MSK);
}

/**
  * @brief  Get spi tx threshold flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_txth(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_TXTH_MSK) == SPI_STAT_TXTH_MSK);
}

/**
  * @brief  Get spi tx under flow flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_get_flag_txud(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_TXUD_MSK) == SPI_STAT_TXUD_MSK);
}

/**
  * @brief  Get spi tx over flow flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_get_flag_txov(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_TXOV_MSK) == SPI_STAT_TXOV_MSK);
}

/**
  * @brief  Get spi tx buffer full flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_txf(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_TXF_MSK) == SPI_STAT_TXF_MSK);
}

/**
  * @brief  Get spi tx buffer empty flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_txe(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_TXE_MSK) == SPI_STAT_TXE_MSK);
}
/**
  * @}
  */
/** @defgroup MD_SPI_Public_Functions_Group5 DATA
  * @{
  */
/**
  * @brief  Set spi data register value.
  * @param  SPIx: SPI Instance.
  * @param  data: tx data.
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_data_reg(SPI_I2S_TypeDef *SPIx, uint32_t data)
{
    WRITE_REG(SPIx->DATA, data);
}

/**
  * @brief  Get spi data register value.
  * @param  SPIx: SPI Instance.
  * @retval data: value for data register.
  */
__STATIC_INLINE uint32_t md_spi_get_data_reg_value(SPI_I2S_TypeDef *SPIx)
{
    return READ_REG(SPIx->DATA);
}
/**
  * @}
  */
/** @defgroup MD_SPI_Public_Functions_Group6 CRCPOLY
  * @{
  */
/**
  * @brief  Set spi crc register value.
  * @param  SPIx: SPI Instance.
  * @param  data: crc data.
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_crc_reg_value(SPI_I2S_TypeDef *SPIx, uint32_t data)
{
    WRITE_REG(SPIx->CRCPOLY, data);
}

/**
  * @brief  Get spi crc register value.
  * @param  SPIx: SPI Instance.
  * @retval data: value for crc register.
  */
__STATIC_INLINE uint32_t md_spi_get_crc_reg_value(SPI_I2S_TypeDef *SPIx)
{
    return READ_REG(SPIx->CRCPOLY);
}
/**
  * @}
  */
/** @defgroup MD_SPI_Public_Functions_Group7 RXCRC
  * @{
  */
/**
  * @brief  Get spi receive data crc value.
  * @param  SPIx: SPI Instance.
  * @retval data: value for receive crc.
  */
__STATIC_INLINE uint32_t md_spi_get_rx_data_crc(SPI_I2S_TypeDef *SPIx)
{
    return READ_REG(SPIx->RXCRC);
}
/**
  * @}
  */
/** @defgroup MD_SPI_Public_Functions_Group8 TXCRC
  * @{
  */
/**
  * @brief  Get spi transmit data crc value.
  * @param  SPIx: SPI Instance.
  * @retval data: value for transmit crc.
  */
__STATIC_INLINE uint32_t md_spi_get_tx_data_crc(SPI_I2S_TypeDef *SPIx)
{
    return READ_REG(SPIx->TXCRC);
}
/**
  * @}
  */
/** @defgroup MD_SPI_Public_Functions_Group9 I2SCFG
  * @{
  */
/**
  * @brief  Set spi mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_chose_spi(SPI_I2S_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->I2SCFG, SPI_I2SCFG_I2SMOD_MSK);
}

/**
  * @brief  Check is set spi mode.
  * @param  SPIx: SPI Instance.
  * @retval State:
  *           - 1: SPI mode
  *           - 0: I2S mode
  */
__STATIC_INLINE uint32_t md_spi_is_set_spi_mode(SPI_I2S_TypeDef *SPIx)
{
    return !(READ_BIT(SPIx->I2SCFG, SPI_I2SCFG_I2SMOD_MSK) == SPI_I2SCFG_I2SMOD_MSK);
}
/**
  * @}
  */
/** @defgroup MD_SPI_Public_Functions_Group10 IER
  * @{
  */
/**
  * @brief  Enable spi frame error interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_fre(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_FRE_MSK);
}

/**
  * @brief  Enable spi mode fail interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_modf(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_MODF_MSK);
}

/**
  * @brief  Enable spi crc error interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_crcerr(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_CRCERR_MSK);
}

/**
  * @brief  Enable spi rx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_rxth(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_RXTH_MSK);
}

/**
  * @brief  Enable spi rx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_rxud(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_RXUD_MSK);
}


/**
  * @brief  Enable spi rx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_rxov(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_RXOV_MSK);
}

/**
  * @brief  Enable spi rx full interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_rxf(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_RXF_MSK);
}

/**
  * @brief  Enable spi rx not empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_rxne(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_RXNE_MSK);
}

/**
  * @brief  Enable spi tx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_txth(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_TXTH_MSK);
}

/**
  * @brief  Enable spi tx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_txud(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_TXUD_MSK);
}

/**
  * @brief  Enable spi tx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_txov(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_TXOV_MSK);
}

/**
  * @brief  Enable spi tx empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_txe(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_TXE_MSK);
}
/**
  * @}
  */
/** @defgroup MD_SPI_Public_Functions_Group11 IDR
  * @{
  */
/**
  * @brief  Disable spi frame error interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_fre(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_FRE_MSK);
}

/**
  * @brief  Disable spi mode fail interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_modf(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_MODF_MSK);
}

/**
  * @brief  Disable spi crc error interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_crcerr(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_CRCERR_MSK);
}

/**
  * @brief  Disable spi rx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_rxth(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_RXTH_MSK);
}

/**
  * @brief  Disable spi rx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_rxud(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_RXUD_MSK);
}

/**
  * @brief  Disable spi rx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_rxov(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_RXOV_MSK);
}

/**
  * @brief  Disable spi rx full interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_rxf(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_RXF_MSK);
}

/**
  * @brief  Disable spi rx not empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_rxne(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_RXNE_MSK);
}

/**
  * @brief  Disable spi tx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_txth(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_TXTH_MSK);
}

/**
  * @brief  Disable spi tx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_txud(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_TXUD_MSK);
}

/**
  * @brief  Disable spi tx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_txov(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_TXOV_MSK);
}

/**
  * @brief  Disable spi tx empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_txe(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_TXE_MSK);
}
/**
  * @}
  */
/** @defgroup MD_SPI_Public_Functions_Group12 IVS
  * @{
  */
/**
  * @brief  Check if the frame error interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_it_fre(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_FRE_MSK) == (SPI_IVS_FRE_MSK));
}

/**
  * @brief  Check if the mode fail interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_it_modf(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_MODF_MSK) == (SPI_IVS_MODF_MSK));
}

/**
  * @brief  Check if the crc error interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_it_crcerr(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_CRCERR_MSK) == (SPI_IVS_CRCERR_MSK));
}

/**
  * @brief  Check if the rx threshold interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_it_rxth(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_RXTH_MSK) == (SPI_IVS_RXTH_MSK));
}

/**
  * @brief  Check if the rx under flow interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_it_rxud(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_RXUD_MSK) == (SPI_IVS_RXUD_MSK));
}

/**
  * @brief  Check if the rx over flow interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_it_rxov(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_RXOV_MSK) == (SPI_IVS_RXOV_MSK));
}

/**
  * @brief  Check if the rx full interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_it_rxf(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_RXF_MSK) == (SPI_IVS_RXF_MSK));
}

/**
  * @brief  Check if the rx not empty interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_it_rxne(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_RXNE_MSK) == (SPI_IVS_RXNE_MSK));
}

/**
  * @brief  Check if the tx threshold interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_it_txth(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_TXTH_MSK) == (SPI_IVS_TXTH_MSK));
}

/**
  * @brief  Check if the tx under flow interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_it_txud(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_TXUD_MSK) == (SPI_IVS_TXUD_MSK));
}

/**
  * @brief  Check if the tx over flow interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_it_txov(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_TXOV_MSK) == (SPI_IVS_TXOV_MSK));
}

/**
  * @brief  Check if the tx empty interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enable_it_txe(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_TXE_MSK) == (SPI_IVS_TXE_MSK));
}
/**
  * @}
  */
/** @defgroup MD_SPI_Public_Functions_Group13 RIF
  * @{
  */
/**
  * @brief  Get frame error interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_fre(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_FRE_MSK) == (SPI_RIF_FRE_MSK));
}

/**
  * @brief  Get mode fail interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_modf(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_MODF_MSK) == (SPI_RIF_MODF_MSK));
}

/**
  * @brief  Get crc error interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_crcerr(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_CRCERR_MSK) == (SPI_RIF_CRCERR_MSK));
}

/**
  * @brief  Get rx threshold interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_rxth(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_RXTH_MSK) == (SPI_RIF_RXTH_MSK));
}

/**
  * @brief  Get rx under flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_rxud(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_RXUD_MSK) == (SPI_RIF_RXUD_MSK));
}

/**
  * @brief  Get rx over flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_rxov(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_RXOV_MSK) == (SPI_RIF_RXOV_MSK));
}

/**
  * @brief  Get rx full interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_rxf(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_RXF_MSK) == (SPI_RIF_RXF_MSK));
}

/**
  * @brief  Get rx not empty interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_rxne(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_RXNE_MSK) == (SPI_RIF_RXNE_MSK));
}

/**
  * @brief  Get tx threshold interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_txth(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_TXTH_MSK) == (SPI_RIF_TXTH_MSK));
}

/**
  * @brief  Get tx under flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_txud(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_TXUD_MSK) == (SPI_RIF_TXUD_MSK));
}

/**
  * @brief  Get tx over flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_txov(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_TXOV_MSK) == (SPI_RIF_TXOV_MSK));
}

/**
  * @brief  Get tx empty interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_txe(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_TXE_MSK) == (SPI_RIF_TXE_MSK));
}
/**
  * @}
  */
/** @defgroup MD_SPI_Public_Functions_Group14 IFM
  * @{
  */
/**
  * @brief  Mask frame error interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_mask_it_fre(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_FRE_MSK) == SPI_IFM_FRE_MSK);
}

/**
  * @brief  Mask mode fail interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_mask_it_modf(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_MODF_MSK) == SPI_IFM_MODF_MSK);
}

/**
  * @brief  Mask crc error interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_mask_it_crcerr(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_CRCERR_MSK) == SPI_IFM_CRCERR_MSK);
}

/**
  * @brief  Mask rx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_mask_it_rxth(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_RXTH_MSK) == SPI_IFM_RXTH_MSK);
}

/**
  * @brief  Mask rx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_mask_it_rxud(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_RXUD_MSK) == SPI_IFM_RXUD_MSK);
}

/**
  * @brief  Mask rx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_mask_it_rxov(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_RXOV_MSK) == SPI_IFM_RXOV_MSK);
}

/**
  * @brief  Mask rx full interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_mask_it_rxf(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_RXF_MSK) == SPI_IFM_RXF_MSK);
}

/**
  * @brief  Mask rx not empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_mask_it_rxne(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_RXNE_MSK) == SPI_IFM_RXNE_MSK);
}

/**
  * @brief  Mask tx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_mask_it_txth(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_TXTH_MSK) == SPI_IFM_TXTH_MSK);
}

/**
  * @brief  Mask tx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_mask_it_txud(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_TXUD_MSK) == SPI_IFM_TXUD_MSK);
}

/**
  * @brief  Mask tx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_mask_it_txov(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_TXOV_MSK) == SPI_IFM_TXOV_MSK);
}

/**
  * @brief  Mask tx empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_mask_it_txe(SPI_I2S_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_TXE_MSK) == SPI_IFM_TXE_MSK);
}
/**
  * @}
  */
/** @defgroup MD_SPI_Public_Functions_Group15 ICR
  * @{
  */
/**
  * @brief  Clear frame error interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_flag_fre(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_FRE_MSK);
}

/**
  * @brief  Clear mode fail interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_flag_modf(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_MODF_MSK);
}

/**
  * @brief  Clear crc error interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_flag_crcerr(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_CRCERR_MSK);
}

/**
  * @brief  Clear rx under flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_flag_rxth(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_RXTH_MSK);
}

/**
  * @brief  Clear rx under flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_flag_rxud(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_RXUD_MSK);
}

/**
  * @brief  Clear rx over flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_flag_rxov(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_RXOV_MSK);
}

/**
  * @brief  Clear rx full interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_flag_rxf(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_RXF_MSK);
}

/**
  * @brief  Clear rx not empty interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_flag_rxne(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_RXNE_MSK);
}

/**
  * @brief  Clear tx under flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_flag_txth(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_TXTH_MSK);
}

/**
  * @brief  Clear tx under flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_flag_txud(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_TXUD_MSK);
}

/**
  * @brief  Clear tx over flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_flag_txov(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_TXOV_MSK);
}

/**
  * @brief  Clear tx empty interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_flag_txe(SPI_I2S_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_TXE_MSK);
}
/**
  * @}
  */

/** @defgroup MD_SPI_Public_Functions_Group1 Initialization
  * @{
  */
extern void md_spi_reset(SPI_I2S_TypeDef *SPIx);
extern md_status_t md_spi_init(md_spi_init_t *init);
extern void md_spi_struct_init(md_spi_init_t *init);
extern int32_t md_spi_send_byte_fast(md_spi_init_t *hperh, uint8_t data);
extern uint8_t md_spi_recv_byte_fast(md_spi_init_t *hperh, int *status);
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
#endif /* __MD_SPI_H__ */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
