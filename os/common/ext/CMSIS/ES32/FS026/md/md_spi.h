/**********************************************************************************
 *
 * @file    md_spi.h
 * @brief   header file of md_spi.c
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov 2021     Ginger          the first version
 *          30 Dec 2021     Ginger          Modify the function name
 *          25 Mar 2022     AE Team         Modify MD Driver
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
#ifndef __MD_SPI_H__
#define __MD_SPI_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_SPI SPI
  * @brief SPI micro driver
  * @{
  */

/** @defgroup MD_SPI_Pubulic_Types SPI Pubulic Types
  * @{
  */

/**
  * @brief   SPI Init structure.
  */
typedef struct
{
    uint32_t Mode;                    /*!< Specifies the SPI mode (Master/Slave).
                                         This parameter can be a value of @ref MD_SPI_PC_MODE.

                                         This feature can be modified afterwards using unitary function @ref md_spi_enable_master_mode() and @ref md_spi_enable_slave_mode().*/

    uint32_t ClockPhase;              /*!< Specifies the clock active edge for the bit capture.
                                         This parameter can be a value of @ref MD_SPI_PC_PHASE.

                                         This feature can be modified afterwards using unitary function @ref md_spi_enable_sample_first_edge() and @ref md_spi_enable_sample_sec_edge().*/

    uint32_t ClockPolarity;           /*!< Specifies the serial clock steady state.
                                         This parameter can be a value of @ref MD_SPI_PC_POLARITY.

                                         This feature can be modified afterwards using unitary function @ref md_spi_enable_sck_low_idle() and @ref md_spi_enable_sck_high_idle().*/

    uint32_t BaudRate;                /*!< Specifies the BaudRate prescaler value which will be used to configure the transmit and receive SCK clock.
                                         This parameter can be a value of @ref MD_SPI_PC_BAUDRATEPRESCALER.
                                         @note The communication clock is derived from the master clock. The slave clock does not need to be set.

                                         This feature can be modified afterwards using unitary function @ref md_spi_set_commumication_baud().*/

    uint32_t BitOrder;                /*!< Specifies whether data transfers start from MSB or LSB bit.
                                         This parameter can be a value of @ref MD_SPI_PC_BIT_ORDER.

                                         This feature can be modified afterwards using unitary function @ref md_spi_enable_first_transmit_lsb() and @ref md_spi_enable_first_transmit_msb().*/

    uint32_t TransferDirection;       /*!< Specifies the SPI unidirectional or bidirectional data mode.
                                         This parameter can be a value of @ref MD_SPI_PC_TRANSFER_DIRECTION.

                                         This feature can be modified afterwards using unitary function @ref md_spi_set_simplex_line_duplex() and @ref md_spi_set_duplex_line_simplex().*/

    uint32_t DataWidth;               /*!< Specifies the SPI data width.
                                         This parameter can be a value of @ref MD_SPI_PC_FRAME_FORMAT.

                                         This feature can be modified afterwards using unitary function @ref md_spi_set_con1_dlen().*/

    uint32_t NSS;                     /*!< Specifies whether the NSS signal is managed by hardware (NSS pin) or by software using the SSI bit.
                                         This parameter can be a value of @ref MD_SPI_PC_NSS_MODE.

                                         This feature can be modified afterwards using unitary function @ref md_spi_enable_ss_output_high() and @ref md_spi_enable_ss_output_low().*/

    uint32_t CRCCalculation;          /*!< Specifies if the CRC calculation is enabled or not.
                                         This parameter can be a value of @ref MD_SPI_EC_CRC_CALCULATION.

                                         This feature can be modified afterwards using unitary functions @ref md_spi_enable_con1_crcen() and @ref md_spi_disable_con1_crcen().*/

    uint32_t CRCPoly;                 /*!< Specifies the polynomial used for the CRC calculation.
                                         This parameter must be a number between Min_Data = 0x00 and Max_Data = 0xFFFF.

                                         This feature can be modified afterwards using unitary function.*/

} md_spi_inittypedef, md_i2s_inittypedef;

typedef struct md_spi_handle_s
{
    SPI_TypeDef *SPI;
    md_spi_inittypedef init;
    uint8_t tx_size;
    uint8_t rx_size;
    uint8_t tx_count;
    uint8_t rx_count;
    uint8_t *tx_buf;
    uint8_t *rx_buf;
    uint32_t ifm_buf;
} md_spi_handle_t;
/**
  * @}
  */

/** @defgroup MD_SPI_Public_Macros SPI Public Macros
  * @{
  */

/**
  * @brief SPI Operation Mode
  */
#define MD_SPI_MODE_SLAVE                       (0U)        /*!< Slave configuration   */
#define MD_SPI_MODE_MASTER                      (1U)        /*!< Master configuration  */

/**
  * @brief SPI Serial Protocol
  */
#define MD_SPI_PROTOCOL_MOTOROLA                (0U)        /*!< Motorola mode. Used as default value */
#define MD_SPI_PROTOCOL_TI                      (1U)        /*!< TI mode                              */

/**
  * @brief SPI Clock Phase
  */
#define MD_SPI_PHASE_1EDGE                      (0U)        /*!< First clock transition is the first data capture edge  */
#define MD_SPI_PHASE_2EDGE                      (1U)        /*!< Second clock transition is the first data capture edge */

/**
  * @brief SPI Clock Polarity
  */
#define MD_SPI_POLARITY_LOW                     (0U)        /*!< Clock to 0 when idle */
#define MD_SPI_POLARITY_HIGH                    (1U)        /*!< Clock to 1 when idle */

/**
  * @brief SPI Baud Rate Prescaler
  */
#define MD_SPI_BAUDRATEPRESCALER_DIV2           (0U)        /*!< BaudRate control equal to fPCLK/2   */
#define MD_SPI_BAUDRATEPRESCALER_DIV4           (1U)        /*!< BaudRate control equal to fPCLK/4   */
#define MD_SPI_BAUDRATEPRESCALER_DIV8           (2U)        /*!< BaudRate control equal to fPCLK/8   */
#define MD_SPI_BAUDRATEPRESCALER_DIV16          (3U)        /*!< BaudRate control equal to fPCLK/16   */
#define MD_SPI_BAUDRATEPRESCALER_DIV32          (4U)        /*!< BaudRate control equal to fPCLK/32  */
#define MD_SPI_BAUDRATEPRESCALER_DIV64          (5U)        /*!< BaudRate control equal to fPCLK/64  */
#define MD_SPI_BAUDRATEPRESCALER_DIV128         (6U)        /*!< BaudRate control equal to fPCLK/128 */
#define MD_SPI_BAUDRATEPRESCALER_DIV256         (7U)        /*!< BaudRate control equal to fPCLK/256 */

/**
  * @brief SPI Transmission Bit Order
  */
#define MD_SPI_LSB_FIRST                        (1U)        /*!< Data is transmitted/received with the LSB first */
#define MD_SPI_MSB_FIRST                        (0U)        /*!< Data is transmitted/received with the MSB first */

/**
  * @brief SPI Software control chip select output
  */
#define MD_SPI_NSS_0                            (0U)        /*!< NSS pin input is 0 */
#define MD_SPI_NSS_1                            (1U)        /*!< NSS pin input is 1 */

/**
  * @brief SPI Software control chip select output
  */
#define MD_SPI_TX_RX                            (0U)        /*!< Full duplex (transmit and receive) */
#define MD_SPI_RX_ONLY                          (1U)        /*!< Turn off output (receive mode only) */

/**
  * @brief SPI Transfer Mode
  */
#define MD_SPI_FRAME_FORMAT_8BIT                (0U)        /*!< 8 bits data format */
#define MD_SPI_FRAME_FORMAT_16BIT               (1U)        /*!< 16 bits data format    */

/**
  * @brief SPI transmission CRC Mode
  */
#define MD_SPI_CRC_NOT                          (0U)        /*!< Do not transmit CRC at the end of data transmission */
#define MD_SPI_CRC_TRANSMIT                     (1U)        /*!< CRC is transmitted at the end of data transmission    */

/**
  * @brief SPI Transfer Direction
  */
#define MD_SPI_FULL_DUPLEX                      (0U)        /*!< Full-Duplex mode. Rx and Tx transfer on 2 lines */
#define MD_SPI_HALF_DUPLEX                      (1U)        /*!< Half-Duplex Rx mode. Rx transfer on 1 line      */

/**
  * @brief SPI RX FIFO Threshold
  */
#define MD_SPI_RX_FIFO_1_CHARACTER_IN_THE_FIFO  (0U)        /*!< RXTHIE event is generated if FIFO level is greater than or equel to 1 character */
#define MD_SPI_RX_FIFO_QUARTER_FULL             (1U)        /*!< RXTHIE event is generated if FIFO level is greater than or equel to FIFO quarter full */
#define MD_SPI_RX_FIFO_HALF_FULL                (2U)        /*!< RXTHIE event is generated if FIFO level is greater than or equel to FIFO half full  */
#define MD_SPI_RX_FIFO_2_LESS_THAN_FULL         (3U)        /*!< RXTHIE event is generated if FIFO level is greater than or equel to FIFO 2 less than full  */

/**
  * @brief SPI TX FIFO Threshold
  */
#define MD_SPI_TX_FIFO_EMPTY                    (0U)        /*!< TXTHIE event is generated if FIFO level is equel to FIFO empty */
#define MD_SPI_TX_FIFO_2_CHARACTERS_IN_THE_FIFO (1U)        /*!< TXTHIE event is generated if FIFO level is below than or equel to 2 characters in the FIFO */
#define MD_SPI_TX_FIFO_QUARTER_FULL             (2U)        /*!< TXTHIE event is generated if FIFO level is below than or equel to FIFO quarter full */
#define MD_SPI_TX_FIFO_HALF_FULL                (3U)        /*!< TXTHIE event is generated if FIFO level is below than or equel to FIFO half full */

/**
  * @brief SPI Slave Select Pin Mode
  */
#define MD_SPI_NSS_SOFT                         (1U)        /*!< NSS managed internally  */
#define MD_SPI_NSS_HARD                         (0U)        /*!< NSS pin is controled by hardware */

/**
  * @brief SPI CRC Calculation
  */
#define MD_SPI_CRCCALCULATION_DISABLE           (0U)        /*!< CRC calculation disabled */
#define MD_SPI_CRCCALCULATION_ENABLE            (1U)        /*!< CRC calculation enabled  */

/**
  * @}
  */

/** @defgroup MD_SPI_Public_Functions SPI Public Functions
  * @{
  */

/** @defgroup MD_SPI_Public_Functions_Group2 CON1
  * @{
  */
/**
  * @brief  Set SPI control register (SPIx_CON1)
  * @param  SPIx SPI Instance
  * @param  value The value write in SPIx_CON1
  * @retval None
  */
__STATIC_INLINE void md_spi_set_con1(SPI_TypeDef *SPIx, uint32_t value)
{
    WRITE_REG(SPIx->CON1, value);
}

/**
  * @brief  Get SPI control register (SPIx_CON1)
  * @param  SPIx SPI Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_spi_get_con1(SPI_TypeDef *SPIx)
{
    return (uint32_t)(READ_REG(SPIx->CON1));
}

/**
  * @brief  Set spi duplex line simplex direction commumication.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_duplex_line_simplex(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_BIDEN);
}

/**
  * @brief  Set spi simplex line duplex direction commumication.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_simplex_line_duplex(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_BIDEN);
}

/**
  * @brief  Check if spi is Enabled duplex line simplex direction commumication.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_duplex_line_simplex(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_BIDEN) != SPI_CON1_BIDEN);
}

/**
  * @brief  Check if spi is Enabled simplex line duplex direction commumication
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_simplex_line_duplex(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_BIDEN) == SPI_CON1_BIDEN);
}

/**
  * @brief  Enable spi duplex line mode data transmit.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_simplex_line_tx(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_BIDOEN);
}

/**
  * @brief  Enable spi duplex line mode data receive.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_simplex_line_rx(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_BIDOEN);
}

/**
  * @brief  Check if spi is Enabled duplex line mode data transmit
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_simplex_line_tx(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_BIDOEN) == SPI_CON1_BIDOEN);
}

/**
  * @brief  Check if spi is Enabled duplex line mode data receive
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_simplex_line_rx(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_BIDOEN) != SPI_CON1_BIDOEN);
}

/**
  * @brief  Enable spi crc by hardware.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_crc_hardware(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_CRCEN);
}

/**
  * @brief  Disable spi crc by hardware.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_crc_hardware(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_CRCEN);
}

/**
  * @brief  Check if spi is enabled crc by hardware.
  * @param  SPIx: SPI Instance.
  * @retval State for 1 or 0.
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_crc_hardware(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_CRCEN) == SPI_CON1_CRCEN);
}

/**
  * @brief  Enable spi next time transmit is crc.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_next_crc_transmit(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_NXTCRC);
}

/**
  * @brief  Disable spi next time transmit is crc.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_next_crc_transmit(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_NXTCRC);
}

/**
  * @brief  Check if spi is enable next time transmit is crc.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_next_crc_transmit(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_NXTCRC) == SPI_CON1_NXTCRC);
}

/**
  * @brief  Enable spi 16 bytes commumication data .
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_16_byte_commumication(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_FLEN);
}

/**
  * @brief  Enable spi 8 bytes commumication data .
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_8_byte_commumication(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_FLEN);
}

/**
  * @brief  Check if spi is enabled 16 bytes commumication data.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_16_byte_commumication(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_FLEN) == SPI_CON1_FLEN);
}

/**
  * @brief  Check if spi is enabled 8 bytes commumication data.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_8_byte_commumication(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_FLEN) != SPI_CON1_FLEN);
}

/**
  * @brief  Enable spi only receive mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_recv_only(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_RXO);
}

/**
  * @brief  Disable spi only receive mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_disable_recv_only(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_RXO);
}

/**
  * @brief  Check if spi is enabled only receive mode.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint8_t md_spi_is_enabled_recv_only(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_RXO) == SPI_CON1_RXO);
}

/**
  * @brief  Enable spi control slave device by software.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_control_slave(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_SSEN);
}

/**
  * @brief  Disable spi control slave device by software.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_disable_control_slave(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_SSEN);
}

/**
  * @brief  Check if spi is enabled control slave device by software.
  * @param  SPIx: SPI Instance.
  * @retval State for bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_control_slave(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_SSEN) == SPI_CON1_SSEN);
}

/**
  * @brief  Enable spi chip select output high.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_ss_output_high(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_SSOUT);
}

/**
  * @brief  Enable spi chip select output low.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_ss_output_low(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_SSOUT);
}

/**
  * @brief  Check if spi is enabled chip select output high.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_ss_output_high(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_SSOUT) == SPI_CON1_SSOUT);
}

/**
  * @brief  Check if spi is enabled chip select output low.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_ss_output_low(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_SSOUT) != SPI_CON1_SSOUT);
}

/**
  * @brief  Enable spi data first transmit MSB.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_first_transmit_msb(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_LSBFST);
}

/**
  * @brief  Enable spi data first transmit LSB.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_first_transmit_lsb(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_LSBFST);
}

/**
  * @brief  Check if spi is enabled data first transmit LSB.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_first_transmit_lsb(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_LSBFST) == SPI_CON1_LSBFST);
}

/**
  * @brief  Check if spi is enabled data first transmit MSB.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_first_transmit_msb(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_LSBFST) != SPI_CON1_LSBFST);
}

/**
  * @brief  Enable SPI module.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_SPIEN);
}

/**
  * @brief  Disable SPI module.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_disable(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_SPIEN);
}

/**
  * @brief  Check if is enabled spi.
  * @param  SPIx: SPI Instance.
  * @retval State for bit (1 or 0)
  */
__STATIC_INLINE uint32_t md_spi_is_enabled(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_SPIEN) == SPI_CON1_SPIEN);
}

/**
  * @brief  Set spi commumication baudrate.
  * @param  SPIx: SPI Instance.
  * @param  BaudRate This parameter can be one of the following values:
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV2
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV4
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV8
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV16
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV32
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV64
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV128
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV256
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_commumication_baud(SPI_TypeDef *SPIx, uint8_t BaudRate)
{
    MODIFY_REG(SPIx->CON1, SPI_CON1_BAUD, BaudRate << SPI_CON1_BAUD_POSS);
}

/**
  * @brief  Get spi commumication baudrate.
  * @param  SPIx: SPI Instance.
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV2
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV4
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV8
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV16
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV32
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV64
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV128
  *         @arg @ref MD_SPI_BAUDRATEPRESCALER_DIV256
  */
__STATIC_INLINE uint32_t md_spi_get_commumication_baud(SPI_TypeDef *SPIx)
{
    return (uint32_t)(READ_BIT(SPIx->CON1, SPI_CON1_BAUD) >> SPI_CON1_BAUD_POSS);
}

/**
  * @brief  Enable spi master mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_master_mode(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_MSTREN);
}

/**
  * @brief  Enable spi slave mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_slave_mode(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_MSTREN);
}
/**
  * @brief  Check if spi is enabled master mode.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_master_mode(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_MSTREN) == SPI_CON1_MSTREN);
}

/**
  * @brief  Enable spi sck bus keep high polarity in idle mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_sck_high_idle(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_CPOL);
}

/**
  * @brief  Enable spi sck bus keep low polarity in idle mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_sck_low_idle(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_CPOL);
}

/**
  * @brief  Check if spi is enabled sck keep high in idle.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_sck_high_idle(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_CPOL) == SPI_CON1_CPOL);
}

/**
  * @brief  Check if spi is enabled sck keep low in idle.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_sck_low_idle(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_CPOL) != SPI_CON1_CPOL);
}

/**
  * @brief  Enable spi sample data in seconde time edge.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_sample_sec_edge(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON1, SPI_CON1_CPHA);
}

/**
  * @param  SPIx: SPI Instance.
  * @brief  Enable spi sample data in first time edge.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_sample_first_edge(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON1, SPI_CON1_CPHA);
}

/**
  * @brief  Check is spi is enabled sample data in seconde time edge.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (0 or 1).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_sample_sec_edge(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_CPHA) == SPI_CON1_CPHA);
}

/**
  * @brief  Check is spi is enabled sample data in first time edge.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (0 or 1).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_sample_first_edge(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON1, SPI_CON1_CPHA) != SPI_CON1_CPHA);
}
/**
  * @}
  */

/** @defgroup MD_SPI_Public_Functions_Group3 CON2
  * @{
  */
/**
  * @brief  Set SPI control register 2 (SPIx_CON2)
  * @param  SPIx SPI Instance
  * @param  value The value write in SPIx_CON2
  * @retval None
  */
__STATIC_INLINE void md_spi_set_con2(SPI_TypeDef *SPIx, uint32_t value)
{
    WRITE_REG(SPIx->CON2, value);
}

/**
  * @brief  Get SPI control register 2(SPIx_CON2)
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_spi_get_con2(SPI_TypeDef *SPIx)
{
    return (uint32_t)(READ_REG(SPIx->CON2));
}

/**
  * @brief  Set spi receive fifo threshold.
  * @param  SPIx: SPI Instance.
  * @param  Threshold This parameter can be one of the following values:
  *         @arg @ref MD_SPI_RX_FIFO_1_CHARACTER_IN_THE_FIFO
  *         @arg @ref MD_SPI_RX_FIFO_QUARTER_FULL
  *         @arg @ref MD_SPI_RX_FIFO_HALF_FULL
  *         @arg @ref MD_SPI_RX_FIFO_2_LESS_THAN_FULL
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_rxfifo_threshold(SPI_TypeDef *SPIx, uint8_t Threshold)
{
    MODIFY_REG(SPIx->CON2, SPI_CON2_RXFTH, Threshold << SPI_CON2_RXFTH_POSS);
}

/**
  * @brief  Get spi receive fifo threshold.
  * @param  SPIx: SPI Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref MD_SPI_RX_FIFO_1_CHARACTER_IN_THE_FIFO
  *         @arg @ref MD_SPI_RX_FIFO_QUARTER_FULL
  *         @arg @ref MD_SPI_RX_FIFO_HALF_FULL
  *         @arg @ref MD_SPI_RX_FIFO_2_LESS_THAN_FULL
  */
__STATIC_INLINE uint8_t md_spi_get_rxfifo_threshold(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON2, SPI_CON2_RXFTH) >> SPI_CON2_RXFTH_POSS);
}

/**
  * @brief  Set spi transmit fifo threshold.
  * @param  SPIx: SPI Instance.
  * @param  Threshold This parameter can be one of the following values:
  *         @arg @ref MD_SPI_TX_FIFO_EMPTY
  *         @arg @ref MD_SPI_TX_FIFO_2_CHARACTERS_IN_THE_FIFO
  *         @arg @ref MD_SPI_TX_FIFO_QUARTER_FULL
  *         @arg @ref MD_SPI_TX_FIFO_HALF_FULL
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_txfifo_threshold(SPI_TypeDef *SPIx, uint8_t Threshold)
{
    MODIFY_REG(SPIx->CON2, SPI_CON2_TXFTH, Threshold << SPI_CON2_TXFTH_POSS);
}

/**
  * @brief  Get spi transmit fifo threshold.
  * @param  SPIx: SPI Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref MD_SPI_TX_FIFO_EMPTY
  *         @arg @ref MD_SPI_TX_FIFO_2_CHARACTERS_IN_THE_FIFO
  *         @arg @ref MD_SPI_TX_FIFO_QUARTER_FULL
  *         @arg @ref MD_SPI_TX_FIFO_HALF_FULL
  */
__STATIC_INLINE uint8_t md_spi_get_txfifo_threshold(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON2, SPI_CON2_TXFTH) >> SPI_CON2_TXFTH_POSS);
}

/**
  * @brief  Set MOTO SPI mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_moto_mode(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON2, SPI_CON2_FRF);
}

/**
  * @brief  Set TI SPI mode.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_ti_mode(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON2, SPI_CON2_FRF);
}

/**
  * @brief  Get spi mode.
  * @param  SPIx: SPI Instance.
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_SPI_PROTOCOL_MOTOROLA
  *         @arg @ref MD_SPI_PROTOCOL_TI
  */
__STATIC_INLINE uint8_t md_spi_get_mode(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON2, SPI_CON2_FRF) >> SPI_CON2_FRF_POS);
}

/**
  * @brief  Produce spi NSS pulse management(master mode).
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_nss_pulse(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON2, SPI_CON2_NSSP);
}

/**
  * @brief  Stop spi NSS pulse management(master mode).
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_disable_nss_pulse(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON2, SPI_CON2_NSSP);
}

/**
  * @brief  Check if spi is enabled NSS pulse management(master mode).
  * @param  SPIx: SPI Instance.
  * @retval SPI mode(0: CLK Disable 1: CLK Enable).
  */
__STATIC_INLINE uint8_t md_spi_is_enabled_nss_pulse(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON2, SPI_CON2_NSSP) == SPI_CON2_NSSP);
}

/**
  * @brief  Enable nss output function.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_nss_output(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON2, SPI_CON2_NSSOE);
}

/**
  * @brief  Disable nss output function.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_disable_nss_output(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON2, SPI_CON2_NSSOE);
}

/**
  * @brief  Check if spi is enabled nss output function.
  * @param  SPIx: SPI Instance.
  * @retval nss mode(0: Output Disable 1: Output Enable).
  */
__STATIC_INLINE uint8_t md_spi_is_enabled_nss_output(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON2, SPI_CON2_NSSOE) == SPI_CON2_NSSOE);
}

/**
  * @brief  Enable spi tx_dma function.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_txdma(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON2, SPI_CON2_TXDMA);
}

/**
  * @brief  Disable spi tx_dma function.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_disable_txdma(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON2, SPI_CON2_TXDMA);
}

/**
  * @brief  Check if spi is enabled txdma.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_txdma(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON2, SPI_CON2_TXDMA) == SPI_CON2_TXDMA);
}

/**
  * @brief  Enable spi rx_dma function.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_enable_rxdma(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->CON2, SPI_CON2_RXDMA);
}

/**
  * @brief  Disable spi rx_dma function.
  * @param  SPIx: SPI Instance.
  * @retval None.
  */
__STATIC_INLINE void md_spi_disable_rxdma(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->CON2, SPI_CON2_RXDMA);
}

/**
  * @brief  Check if spi is enabled rxdma.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_rxdma(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->CON2, SPI_CON2_RXDMA) == SPI_CON2_RXDMA);
}
/**
  * @}
  */

/** @defgroup MD_SPI_Public_Functions_Group4 STAT
  * @{
  */
/**
  * @brief  Get SPI status register(SPIx_STAT)
  * @param  SPIx SPI Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_spi_get_stat(SPI_TypeDef *SPIx)
{
    return (uint32_t)(READ_REG(SPIx->STAT));
}

/**
  * @brief  Get spi rxfifo value.
  * @param  SPIx: SPI Instance.
  * @retval rxfifo threshold.
  */
__STATIC_INLINE uint32_t md_spi_get_rxfifo_value(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_RXFLV) >> SPI_STAT_RXFLV_POSS);
}

/**
  * @brief  Get spi txfifo value.
  * @param  SPIx: SPI Instance.
  * @retval txfifo threshold.
  */
__STATIC_INLINE uint32_t md_spi_get_txfifo_value(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_TXFLV) >> SPI_STAT_TXFLV_POSS);
}

/**
  * @brief  Get spi busy flag.
  * @param  SPIx: SPI Instance.
  * @retval State for bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_busy(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_BUSY) == SPI_STAT_BUSY);
}

/**
  * @brief  Get spi rx threshold flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_rxth(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_RXTH) == SPI_STAT_RXTH);
}

/**
  * @brief  Get spi rx under flow flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_rxud(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_RXUD) == SPI_STAT_RXUD);
}

/**
  * @brief  Get spi rx over flow flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_rxov(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_RXOV) == SPI_STAT_RXOV);
}

/**
  * @brief  Get spi rx buffer full flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_rxf(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_RXF) == SPI_STAT_RXF);
}

/**
  * @brief  Get spi rx buffer not empty flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_rxne(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_RXNE) == SPI_STAT_RXNE);
}

/**
  * @brief  Get spi tx threshold flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_txth(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_TXTH) == SPI_STAT_TXTH);
}

/**
  * @brief  Get spi tx under flow flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_txud(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_TXUD) == SPI_STAT_TXUD);
}

/**
  * @brief  Get spi tx over flow flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_txov(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_TXOV) == SPI_STAT_TXOV);
}

/**
  * @brief  Get spi tx buffer full flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_txf(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_TXF) == SPI_STAT_TXF);
}

/**
  * @brief  Get spi tx buffer empty flag.
  * @param  SPIx: SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_flag_txe(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_TXE) == SPI_STAT_TXE);
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
__STATIC_INLINE void md_spi_set_data_reg(SPI_TypeDef *SPIx, uint32_t Data)
{
    WRITE_REG(SPIx->DATA, Data);
}

/**
  * @brief  Get spi data register value.
  * @param  SPIx: SPI Instance.
  * @retval data: value for data register.
  */
__STATIC_INLINE uint32_t md_spi_get_data_reg(SPI_TypeDef *SPIx)
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
  * @note   When CRC calculation is enabled, the RxCRC[15:0] bits contain the computed CRC value of the subsequently \n
            received bytes. This register is reset when the CRCEN bit in SPIx_CR1 register is written to 1. The CRC is \n
            calculated serially using the polynomial  programmed in the SPIx_CRCPLOY register. Only the 8 LSB bits are \n
            considered when the CRC frame format is set to be 8-bit length (CRCL bit in the SPIx_CON1 is cleared). CRC \n
            calculation is done based on any CRC8 standard. The entire 16-bits of this register are considered when a \n
            16-bit CRC frame format is selected (CRCL bit in the SPIx_CR1 register is set). CRC calculation is done based \n
            on any CRC16 standard.
            Note: A read to this register when the BSY Flag is set could return an incorrect value. These bits are not \n
            used in I2S mode.
  * @param  SPIx: SPI Instance.
  * @param  data: crc data.
  * @retval None.
  */
__STATIC_INLINE void md_spi_set_crc_polynomial(SPI_TypeDef *SPIx, uint32_t data)
{
    WRITE_REG(SPIx->CRCPOLY, data);
}

/**
  * @brief  Get spi crc register value.
  * @param  SPIx: SPI Instance.
  * @retval data: value for crc register.
  */
__STATIC_INLINE uint32_t md_spi_get_crc_polynomial(SPI_TypeDef *SPIx)
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
  * @note   When CRC calculation is enabled, the RxCRC[7:0] bits contain the computed CRC value of the subsequently \n
            transmitted bytes. This register is reset when the CRCEN bit of SPIx_CON1 is written to 1. The CRC is calculated \n
            serially using the polynomial programmed in the SPIx_CRCPLOY register. Only the 8 LSB bits are considered \n
            when the CRC frame format is set to be 8-bit length (FLEN bit in the SPIx_CON1 is cleared). CRC calculation is \n
            done based on any CRC8 standard. The entire 16-bits of this register are considered when a 16-bit CRC frame \n
            format is selected (CRCL bit in the SPIx_CR1 register is set). CRC calculation is done based on any CRC16 standard. \n
            Note: A read to this register when the BSY flag is set could return an incorrect value. These bits are not used \n
            in I2S mode.
  * @param  SPIx: SPI Instance.
  * @retval data: value for receive crc.
  */
__STATIC_INLINE uint32_t md_spi_get_rx_data_crc(SPI_TypeDef *SPIx)
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
  * @note   When CRC calculation is enabled, the TxCRC[7:0] bits contain the computed CRC value of the subsequently \n
            transmitted bytes. This register is reset when the CRCEN bit of SPIx_CON1 is written to 1. The CRC is calculated \n
            serially using the polynomial programmed in the SPIx_CRCPLOY register. Only the 8 LSB bits are considered \n
            when the CRC frame format is set to be 8-bit length (FLEN bit in the SPIx_CR1 is cleared). CRC calculation is \n
            done based on any CRC8 standard. The entire 16-bits of this register are considered when a 16-bit CRC frame \n
            format is selected (CRCL bit in the SPIx_CR1 register is set). CRC calculation is done based on any CRC16 standard. \n
            Note: A read to this register when the BSY flag is set could return an incorrect value. These bits are not used \n
            in I2S mode.
  * @param  SPIx: SPI Instance.
  * @retval data: value for transmit crc.
  */
__STATIC_INLINE uint32_t md_spi_get_tx_data_crc(SPI_TypeDef *SPIx)
{
    return READ_REG(SPIx->TXCRC);
}
/**
  * @}
  */

/** @defgroup MD_SPI_Public_Functions_Group9 IER
  * @{
  */
/**
  * @brief  Set SPI Interrupt enable Register
  * @param  SPIx SPI Instance
  * @param  ier
  * @retval None
  */
__STATIC_INLINE void md_spi_set_ier(SPI_TypeDef *SPIx, uint32_t ier)
{
    WRITE_REG(SPIx->IER, ier);
}

/**
  * @brief  Enable spi frame error interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_fre(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_FRE);
}

/**
  * @brief  Enable spi mode fail interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_modf(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_MODF);
}

/**
  * @brief  Enable spi crc error interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_crcerr(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_CRCERR);
}

/**
  * @brief  Enable spi rx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_rxth(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_RXTH);
}

/**
  * @brief  Enable spi rx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_rxud(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_RXUD);
}

/**
  * @brief  Enable spi rx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_rxov(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_RXOV);
}

/**
  * @brief  Enable spi rx full interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_rxf(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_RXF);
}

/**
  * @brief  Enable spi rx not empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_rxne(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_RXNE);
}

/**
  * @brief  Enable spi tx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_txth(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_TXTH);
}

/**
  * @brief  Enable spi tx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_txud(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_TXUD);
}

/**
  * @brief  Enable spi tx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_txov(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_TXOV);
}

/**
  * @brief  Enable spi tx empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_enable_it_txe(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IER, SPI_IER_TXE);
}
/**
  * @}
  */

/** @defgroup MD_SPI_Public_Functions_Group10 IDR
  * @{
  */
/**
  * @brief  Set SPI interrupt disable Register
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void md_spi_set_idr(SPI_TypeDef *SPIx, uint32_t idr)
{
    WRITE_REG(SPIx->IDR, idr);
}

/**
  * @brief  Disable spi frame error interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_fre(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_FRE);
}

/**
  * @brief  Disable spi mode fail interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_modf(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_MODF);
}

/**
  * @brief  Disable spi crc error interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_crcerr(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_CRCERR);
}

/**
  * @brief  Disable spi rx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_rxth(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_RXTH);
}

/**
  * @brief  Disable spi rx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_rxud(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_RXUD);
}

/**
  * @brief  Disable spi rx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_rxov(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_RXOV);
}

/**
  * @brief  Disable spi rx full interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_rxf(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_RXF);
}

/**
  * @brief  Disable spi rx not empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_rxne(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_RXNE);
}

/**
  * @brief  Disable spi tx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_txth(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_TXTH);
}

/**
  * @brief  Disable spi tx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_txud(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_TXUD);
}

/**
  * @brief  Disable spi tx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_txov(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_TXOV);
}

/**
  * @brief  Disable spi tx empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_spi_disable_it_txe(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->IDR, SPI_IDR_TXE);
}
/**
  * @}
  */

/** @defgroup MD_SPI_Public_Functions_Group11 IVS
  * @{
  */
/**
  * @brief  Get SPI_IVS Register
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_spi_get_ivs(SPI_TypeDef *SPIx)
{
    return (uint32_t)(READ_REG(SPIx->IVS));
}

/**
  * @brief  Check if the frame error interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_it_fre(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_FRE) == (SPI_IVS_FRE));
}

/**
  * @brief  Check if the mode fail interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_it_modf(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_MODF) == (SPI_IVS_MODF));
}

/**
  * @brief  Check if the crc error interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_it_crcerr(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_CRCERR) == (SPI_IVS_CRCERR));
}

/**
  * @brief  Check if the rx threshold interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_it_rxth(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_RXTH) == (SPI_IVS_RXTH));
}

/**
  * @brief  Check if the rx under flow interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_it_rxud(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_RXUD) == (SPI_IVS_RXUD));
}

/**
  * @brief  Check if the rx over flow interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_it_rxov(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_RXOV) == (SPI_IVS_RXOV));
}

/**
  * @brief  Check if the rx full interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_it_rxf(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_RXF) == (SPI_IVS_RXF));
}

/**
  * @brief  Check if the rx not empty interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_it_rxne(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_RXNE) == (SPI_IVS_RXNE));
}

/**
  * @brief  Check if the tx threshold interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_it_txth(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_TXTH) == (SPI_IVS_TXTH));
}

/**
  * @brief  Check if the tx under flow interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_it_txud(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_TXUD) == (SPI_IVS_TXUD));
}

/**
  * @brief  Check if the tx over flow interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_it_txov(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_TXOV) == (SPI_IVS_TXOV));
}

/**
  * @brief  Check if the tx empty interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_enabled_it_txe(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IVS, SPI_IVS_TXE) == (SPI_IVS_TXE));
}
/**
  * @}
  */

/** @defgroup MD_SPI_Public_Functions_Group12 RIF
  * @{
  */
/**
  * @brief  Get SPI_RIF Register
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_spi_get_rif(SPI_TypeDef *SPIx)
{
    return (uint32_t)(READ_REG(SPIx->RIF));
}

/**
  * @brief  Get frame error interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_fre(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_FRE) == (SPI_RIF_FRE));
}

/**
  * @brief  Get mode fail interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_modf(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_MODF) == (SPI_RIF_MODF));
}

/**
  * @brief  Get crc error interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_crcerr(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_CRCERR) == (SPI_RIF_CRCERR));
}

/**
  * @brief  Get rx threshold interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_rxth(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_RXTH) == (SPI_RIF_RXTH));
}

/**
  * @brief  Get rx under flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_rxud(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_RXUD) == (SPI_RIF_RXUD));
}

/**
  * @brief  Get rx over flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_rxov(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_RXOV) == (SPI_RIF_RXOV));
}

/**
  * @brief  Get rx full interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_rxf(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_RXF) == (SPI_RIF_RXF));
}

/**
  * @brief  Get rx not empty interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_rxne(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_RXNE) == (SPI_RIF_RXNE));
}

/**
  * @brief  Get tx threshold interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_txth(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_TXTH) == (SPI_RIF_TXTH));
}

/**
  * @brief  Get tx under flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_txud(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_TXUD) == (SPI_RIF_TXUD));
}

/**
  * @brief  Get tx over flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_txov(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_TXOV) == (SPI_RIF_TXOV));
}

/**
  * @brief  Get tx empty interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_active_it_txe(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->RIF, SPI_RIF_TXE) == (SPI_RIF_TXE));
}
/**
  * @}
  */

/** @defgroup MD_SPI_Public_Functions_Group13 IFM
  * @{
  */
/**
  * @brief  Get SPI_IFM Register
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_spi_get_ifm(SPI_TypeDef *SPIx)
{
    return (uint32_t)(READ_REG(SPIx->IFM));
}

/**
  * @brief  Mask frame error interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_masked_it_fre(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_FRE) == SPI_IFM_FRE);
}

/**
  * @brief  Mask mode fail interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_masked_it_modf(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_MODF) == SPI_IFM_MODF);
}

/**
  * @brief  Mask crc error interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_masked_it_crcerr(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_CRCERR) == SPI_IFM_CRCERR);
}

/**
  * @brief  Mask rx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_masked_it_rxth(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_RXTH) == SPI_IFM_RXTH);
}

/**
  * @brief  Mask rx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_masked_it_rxud(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_RXUD) == SPI_IFM_RXUD);
}

/**
  * @brief  Mask rx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_masked_it_rxov(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_RXOV) == SPI_IFM_RXOV);
}

/**
  * @brief  Mask rx full interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_masked_it_rxf(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_RXF) == SPI_IFM_RXF);
}

/**
  * @brief  Mask rx not empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_masked_it_rxne(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_RXNE) == SPI_IFM_RXNE);
}

/**
  * @brief  Mask tx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_masked_it_txth(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_TXTH) == SPI_IFM_TXTH);
}

/**
  * @brief  Mask tx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_masked_it_txud(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_TXUD) == SPI_IFM_TXUD);
}

/**
  * @brief  Mask tx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_masked_it_txov(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_TXOV) == SPI_IFM_TXOV);
}

/**
  * @brief  Mask tx empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_spi_is_masked_it_txe(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->IFM, SPI_IFM_TXE) == SPI_IFM_TXE);
}
/**
  * @}
  */

/** @defgroup MD_SPI_Public_Functions_Group14 ICR
  * @{
  */
/**
  * @brief  Set SPI_ICR Register
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void md_spi_set_icr(SPI_TypeDef *SPIx, uint32_t icr)
{
    WRITE_REG(SPIx->ICR, icr);
}

/**
  * @brief  Clear frame error interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_it_fre(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_FRE);
}

/**
  * @brief  Clear mode fail interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_it_modf(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_MODF);
}

/**
  * @brief  Clear crc error interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_it_crcerr(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_CRCERR);
}

/**
  * @brief  Clear rx threshold interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_it_rxth(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_RXTH);
}

/**
  * @brief  Clear rx under flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_it_rxud(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_RXUD);
}

/**
  * @brief  Clear rx over flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_it_rxov(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_RXOV);
}

/**
  * @brief  Clear rx full interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_it_rxf(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_RXF);
}

/**
  * @brief  Clear rx not empty interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_it_rxne(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_RXNE);
}

/**
  * @brief  Clear tx threshold interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_it_txth(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_TXTH);
}

/**
  * @brief  Clear tx under flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_it_txud(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_TXUD);
}

/**
  * @brief  Clear tx over flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_it_txov(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_TXOV);
}

/**
  * @brief  Clear tx empty interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_spi_clear_it_txe(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->ICR, SPI_ICR_TXE);
}
/**
  * @}
  */

/** @defgroup MD_SPI_Public_Functions_Group11 Initialization
  * @{
  */
ErrorStatus md_spi_init(SPI_TypeDef *SPIx, md_spi_inittypedef *SPI_InitStruct);
ErrorStatus md_spi_deinit(SPI_TypeDef *SPIx);
void md_spi_struct_init(md_spi_inittypedef *SPI_InitStruct);
uint8_t md_spi_recv_byte(SPI_TypeDef *SPIx);
void md_spi_send_byte(SPI_TypeDef *SPIx, uint8_t data);
uint16_t md_spi_recv_halfword(SPI_TypeDef *SPIx);
void md_spi_send_halfword(SPI_TypeDef *SPIx, uint16_t data);
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup MD_I2S_Public_Macros I2S Public Macros
  * @{
  */

/**
  * @brief I2S Channel length
  */
#define MD_I2S_CHANNEL_LENGTH_16BIT             (0U)        /*!< 16 bits wide */
#define MD_I2S_CHANNEL_LENGTH_32BIT             (1U)        /*!< 32 bits wide */

/**
  * @brief I2S Clock polarity
  */
#define MD_I2S_POLARITY_LOW                     (0U)        /*!< Clock to 0 when idle */
#define MD_I2S_POLARITY_HIGH                    (1U)        /*!< Clock to 1 when idle */

/**
  * @brief I2S Data Length
  */
#define MD_I2S_DATA_LENGTH_16BIT                (0U)        /*!< I2S data length to be transferred 16-bit data length */
#define MD_I2S_DATA_LENGTH_24BIT                (1U)        /*!< I2S data length to be transferred  24-bit data length  */
#define MD_I2S_DATA_LENGTH_32BIT                (2U)        /*!< I2S data length to be transferred  32-bit data length  */
#define MD_I2S_DATA_LENGTH_NOT_ALLOWED          (3U)        /*!< I2S data length to be transferred  Not allowed  */

/**
  * @brief I2S standard selection
  */
#define MD_I2S_PHILIPS_STANDARD                 (0U)        /*!< I2S standard selection philips  */
#define MD_I2S_MSB_STANDARD                     (1U)        /*!< I2S standard selection MSB  */
#define MD_I2S_LSB_STANDARD                     (2U)        /*!< I2S standard selection LSB  */
#define MD_I2S_PCM_STANDARD                     (3U)        /*!< I2S standard selection PCM  */

/**
  * @brief I2S Frame Synchronization
  */
#define MD_I2S_FRAME_SYN_SHORT                  (0U)        /*!< Short frame synchronization */
#define MD_I2S_FRAME_SYN_LONG                   (1U)        /*!< Long frame synchronization */

/**
  * @brief I2S Mode Selection
  */
#define MD_I2S_MODE_SPI                         (0U)        /*!< SPI mode is selection */
#define MD_I2S_MODE_I2S                         (1U)        /*!< I2S mode is seleciton */

/**
  * @brief I2S Configuration Mode
  */
#define MD_I2S_SLAVE_FULL_DUPLEX                (0U)        /*!< I2S configuartion mode slave duplex  */
#define MD_I2S_SLAVE_TX                         (1U)        /*!< I2S configuartion mode slave transmit  */
#define MD_I2S_SLAVE_RX                         (2U)        /*!< I2S configuartion mode slave receive  */
#define MD_I2S_MASTER_FULL_DUPLEX               (4U)        /*!< I2S configuartion mode master duplex  */
#define MD_I2S_MASTER_TX                        (5U)        /*!< I2S configuartion mode master transmit  */
#define MD_I2S_MASTER_RX                        (6U)        /*!< I2S configuartion mode master receive  */

/**
  * @brief I2S Extern Clock
  */
#define MD_I2S_EVEN                             (0U)        /*!< Real divider value is = (I2SDIV * 2) */
#define MD_I2S_ODD                              (1U)        /*!< Real divider value is = (I2SDIV * 2)+1 */

/**
  * @brief I2S Extern Clock
  */
#define MD_I2S_APB_CLOCK                        (0U)        /*!< APB clock is selection */
#define MD_I2S_EXTERNAL_CLOCK                   (1U)        /*!< External clock is seleciton */

/**
  * @}
  */

/** @defgroup MD_I2S_Public_Functions I2S Public Functions
  * @{
  */

/** @defgroup MD_I2S_Public_Functions_Group2 I2SCFG
  * @{
  */
/**
  * @brief  Set SPI I2S configuration register(SPIx_I2SCFG)
  * @param  SPIx SPI Instance
  * @param  value The value write in SPIx_I2SCFG
  * @retval None
  */
__STATIC_INLINE void md_spi_set_i2scfg(SPI_TypeDef *SPIx, uint32_t value)
{
    WRITE_REG(SPIx->I2SCFG, value);
}

/**
  * @brief  Get SPI I2S configuration register (SPIx_I2SCFG)
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_spi_get_i2scfg(SPI_TypeDef *SPIx)
{
    return (uint32_t)(READ_REG(SPIx->I2SCFG));
}

/**
  * @brief  Enable I2S module.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_enable(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->I2SCFG, SPI_I2SCFG_I2SMOD | SPI_I2SCFG_I2SE);
}

/**
  * @brief  Disable I2S module.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_disable(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->I2SCFG, SPI_I2SCFG_I2SE);
    CLEAR_BIT(SPIx->I2SCFG, SPI_I2SCFG_I2SMOD);
}

/**
  * @brief  Check if I2S is enabled.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enabled(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->I2SCFG, SPI_I2SCFG_I2SE) == SPI_I2SCFG_I2SE);
}

/**
  * @brief  Set TX/RX mode.
  * @param  I2Sx: I2S Instance.
  * @param  value This bit can be set to:
  *         @arg @ref MD_I2S_SLAVE_FULL_DUPLEX
  *         @arg @ref MD_I2S_SLAVE_TX
  *         @arg @ref MD_I2S_SLAVE_RX
  *         @arg @ref MD_I2S_MASTER_FULL_DUPLEX
  *         @arg @ref MD_I2S_MASTER_TX
  *         @arg @ref MD_I2S_MASTER_RX
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_mode(SPI_TypeDef *SPIx, uint8_t mode)
{
    MODIFY_REG(SPIx->I2SCFG, SPI_I2SCFG_I2SCFG, mode << SPI_I2SCFG_I2SCFG_POSS);
}

/**
  * @brief  Get TX/RX mode.
  * @param  I2Sx: I2S Instance.
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_I2S_SLAVE_FULL_DUPLEX
  *         @arg @ref MD_I2S_SLAVE_TX
  *         @arg @ref MD_I2S_SLAVE_RX
  *         @arg @ref MD_I2S_MASTER_FULL_DUPLEX
  *         @arg @ref MD_I2S_MASTER_TX
  *         @arg @ref MD_I2S_MASTER_RX
  */
__STATIC_INLINE uint32_t md_i2s_get_mode(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->I2SCFG, SPI_I2SCFG_I2SCFG) >> SPI_I2SCFG_I2SCFG_POSS);
}

/**
  * @brief  Set PCM short frame.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_short_frame(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->I2SCFG, SPI_I2SCFG_PCMSYNC);
}

/**
  * @brief  Set PCM long frame.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_long_frame(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->I2SCFG, SPI_I2SCFG_PCMSYNC);
}

/**
  * @brief  Get PCM frame mode.
  * @param  I2Sx: I2S Instance.
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_I2S_FRAME_SYN_SHORT
  *         @arg @ref MD_I2S_FRAME_SYN_LONG
  */
__STATIC_INLINE uint32_t md_i2s_get_frame_mode(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->I2SCFG, SPI_I2SCFG_PCMSYNC) >> SPI_I2SCFG_PCMSYNC_POS);
}

/**
  * @brief  Set I2S standard.
  * @param  I2Sx: I2S Instance.
  * @param  value This bit can be set to:
  *         @arg @ref MD_I2S_PHILIPS_STANDARD
  *         @arg @ref MD_I2S_MSB_STANDARD
  *         @arg @ref MD_I2S_LSB_STANDARD
  *         @arg @ref MD_I2S_PCM_STANDARD
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_standard(SPI_TypeDef *SPIx, uint8_t value)
{
    MODIFY_REG(SPIx->I2SCFG, SPI_I2SCFG_I2SSTD, value << SPI_I2SCFG_I2SSTD_POSS);
}

/**
  * @brief  Get I2S standard.
  * @param  I2Sx: I2S Instance.
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_I2S_PHILIPS_STANDARD
  *         @arg @ref MD_I2S_MSB_STANDARD
  *         @arg @ref MD_I2S_LSB_STANDARD
  *         @arg @ref MD_I2S_PCM_STANDARD
  */
__STATIC_INLINE uint32_t md_i2s_get_standard(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->I2SCFG, SPI_I2SCFG_I2SSTD) >> SPI_I2SCFG_I2SSTD_POSS);
}

/**
  * @brief  Set I2S clock polarity.
  * @param  I2Sx: I2S Instance.
  * @param  value This bit can be set to:
  *         @arg @ref MD_I2S_POLARITY_LOW
  *         @arg @ref MD_I2S_POLARITY_HIGH
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_inactive_polarity(SPI_TypeDef *SPIx, uint8_t pol)
{
    MODIFY_REG(SPIx->I2SCFG, SPI_I2SCFG_CKPOL, pol << SPI_I2SCFG_CKPOL_POS);
}

/**
  * @brief  Get I2S clock polarity.
  * @param  I2Sx: I2S Instance.
  * @retval I2S polarity:
  *           - 0: low
  *           - 1: high
  */
__STATIC_INLINE uint32_t md_i2s_get_inactive_polarity(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->I2SCFG, SPI_I2SCFG_CKPOL) >> SPI_I2SCFG_CKPOL_POS);
}

/**
  * @brief  Set I2S data length.
  * @param  I2Sx: I2S Instance.
  * @param  value This bit can be set to:
  *         @arg @ref MD_I2S_DATA_LENGTH_16BIT
  *         @arg @ref MD_I2S_DATA_LENGTH_24BIT
  *         @arg @ref MD_I2S_DATA_LENGTH_32BIT
  *         @arg @ref MD_I2S_DATA_LENGTH_NOT_ALLOWED
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_data_length(SPI_TypeDef *SPIx, uint8_t length)
{
    MODIFY_REG(SPIx->I2SCFG, SPI_I2SCFG_DATLEN, length << SPI_I2SCFG_DATLEN_POSS);
}

/**
  * @brief  Get I2S data length.
  * @param  I2Sx: I2S Instance.
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_I2S_DATA_LENGTH_16BIT
  *         @arg @ref MD_I2S_DATA_LENGTH_24BIT
  *         @arg @ref MD_I2S_DATA_LENGTH_32BIT
  *         @arg @ref MD_I2S_DATA_LENGTH_NOT_ALLOWED
  */
__STATIC_INLINE uint32_t md_i2s_get_data_length(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->I2SCFG, SPI_I2SCFG_DATLEN) >> SPI_I2SCFG_DATLEN_POSS);
}

/**
  * @brief  Set I2S channel length.
  * @param  I2Sx: I2S Instance.
  * @param  value This bit can be set to:
  *         @arg @ref MD_I2S_CHANNEL_LENGTH_16BIT
  *         @arg @ref MD_I2S_CHANNEL_LENGTH_32BIT
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_channel_length(SPI_TypeDef *SPIx, uint8_t length)
{
    MODIFY_REG(SPIx->I2SCFG, SPI_I2SCFG_CHLEN, length << SPI_I2SCFG_CHLEN_POS);
}

/**
  * @brief  Get I2S channel length.
  * @param  I2Sx: I2S Instance.
  * @retval Return:
  *         @arg @ref MD_I2S_CHANNEL_LENGTH_16BIT
  *         @arg @ref MD_I2S_CHANNEL_LENGTH_32BIT
  */
__STATIC_INLINE uint32_t md_i2s_get_channel_length(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->I2SCFG, SPI_I2SCFG_CHLEN) >> SPI_I2SCFG_CHLEN_POS);
}
/**
  * @}
  */

/** @defgroup MD_I2S_Public_Functions_Group3 I2SPR
  * @{
  */
/**
  * @brief  Set SPI I2S configuration register(SPIx_I2SPR)
  * @param  SPIx SPI Instance
  * @param  value The value write in SPIx_I2SPR
  * @retval None
  */
__STATIC_INLINE void md_spi_set_i2spr(SPI_TypeDef *SPIx, uint32_t value)
{
    WRITE_REG(SPIx->I2SPR, value);
}

/**
  * @brief  Get SPI I2S configuration register (SPIx_I2SPR)
  * @param  SPIx SPI Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_spi_get_i2spr(SPI_TypeDef *SPIx)
{
    return (uint32_t)(READ_REG(SPIx->I2SPR));
}

/**
  * @brief  Set I2S clock source.
  * @param  I2Sx: I2S Instance.
  * @param  value This bit can be set to:
  *         @arg MD_I2S_APB_CLOCK
  *         @arg MD_I2S_EXTERNAL_CLOCK
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_clock_cource(SPI_TypeDef *SPIx, uint8_t clk)
{
    MODIFY_REG(SPIx->I2SPR, SPI_I2SPR_EXTCKEN, clk << SPI_I2SPR_EXTCKEN_POS);
}

/**
  * @brief  Get I2S clock source.
  * @param  I2Sx: I2S Instance.
  * @retval The retval can be one of the following values:
  *         @arg MD_I2S_APB_CLOCK
  *         @arg MD_I2S_EXTERNAL_CLOCK
  */
__STATIC_INLINE uint32_t md_i2s_get_clock_cource(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->I2SPR, SPI_I2SPR_EXTCKEN) >> SPI_I2SPR_EXTCKEN_POS);
}

/**
  * @brief  Enable I2S main clock output.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_enable_mclock(SPI_TypeDef *SPIx)
{
    SET_BIT(SPIx->I2SPR, SPI_I2SPR_MCKOE);
}

/**
  * @brief  Disable I2S main clock output.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_disable_mclock(SPI_TypeDef *SPIx)
{
    CLEAR_BIT(SPIx->I2SPR, SPI_I2SPR_MCKOE);
}

/**
  * @brief  Check if main clock output is enabled.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enabled_mclock(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->I2SPR, SPI_I2SPR_MCKOE) == SPI_I2SPR_MCKOE);
}

/**
  * @brief  Set I2S odd coefficient.
  * @param  I2Sx: I2S Instance.
  * @param  odd: Odd coefficient
  *           - 0: Frequency division = I2SDIV * 2
  *           - 1: Frequency division = (I2SDIV * 2) + 1
  * @param  value This bit can be set to:
  *         @arg MD_I2S_EVEN
  *         @arg MD_I2S_ODD
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_div_odd(SPI_TypeDef *SPIx, uint8_t odd)
{
    MODIFY_REG(SPIx->I2SPR, SPI_I2SPR_ODD, odd << SPI_I2SPR_ODD_POS);
}

/**
  * @brief  Get I2S odd coefficient.
  * @param  I2Sx: I2S Instance.
  * @retval Odd coefficient:
  *           - 0: Frequency division = I2SDIV * 2
  *           - 1: Frequency division = (I2SDIV * 2) + 1
  * @retval The retval can be one of the following values:
  *         @arg MD_I2S_EVEN
  *         @arg MD_I2S_ODD
  */
__STATIC_INLINE uint32_t md_i2s_get_div_odd(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->I2SPR, SPI_I2SPR_ODD) >> SPI_I2SPR_ODD_POS);
}

/**
  * @brief  Set I2S division
  * @param  I2Sx: I2S Instance.
  * @param  div: Frequency division.
  * @param  div This bit can be set to:
  *         @arg Max:255
  *         @arg Min:1
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_div(SPI_TypeDef *SPIx, uint8_t div)
{
    MODIFY_REG(SPIx->I2SPR, SPI_I2SPR_I2SDIV, div << SPI_I2SPR_I2SDIV_POSS);
}

/**
  * @brief  Get I2S division.
  * @param  I2Sx: I2S Instance.
  * @retval Frequency division.
  * @retval Return follow :
  *         @arg Max:255
  *         @arg Min:1
  */
__STATIC_INLINE uint32_t md_i2s_get_div(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->I2SPR, SPI_I2SPR_I2SDIV) >> SPI_I2SPR_I2SDIV_POSS);
}
/**
  * @}
  */

/** @defgroup MD_I2S_Public_Functions_Group4 I2S
  * @{
  */
/**
  * @brief  Set I2S control register 2 (SPIx_CON2)
  * @param  I2Sx: I2S Instance
  * @param  value The value write in SPIx_CON2
  * @retval None
  */
__STATIC_INLINE void md_i2s_set_con2(SPI_TypeDef *SPIx, uint32_t value)
{
    md_spi_set_con2(SPIx, value);
}

/**
  * @brief  Get I2S control register 2(SPIx_CON2)
  * @param  I2Sx: I2S Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_i2s_get_con2(SPI_TypeDef *SPIx)
{
    return md_spi_get_con2(SPIx);
}

/**
  * @brief  Set I2S receive fifo threshold.
  * @param  I2Sx: I2S Instance.
  * @param  Threshold This parameter can be one of the following values:
  *         @arg @ref MD_SPI_RX_FIFO_1_CHARACTER_IN_THE_FIFO
  *         @arg @ref MD_SPI_RX_FIFO_QUARTER_FULL
  *         @arg @ref MD_SPI_RX_FIFO_HALF_FULL
  *         @arg @ref MD_SPI_RX_FIFO_2_LESS_THAN_FULL
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_rxfifo_threshold(SPI_TypeDef *SPIx, uint8_t Threshold)
{
    md_spi_set_rxfifo_threshold(SPIx, Threshold);
}

/**
  * @brief  Get I2S receive fifo threshold.
  * @param  I2Sx: I2S Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref MD_SPI_RX_FIFO_1_CHARACTER_IN_THE_FIFO
  *         @arg @ref MD_SPI_RX_FIFO_QUARTER_FULL
  *         @arg @ref MD_SPI_RX_FIFO_HALF_FULL
  *         @arg @ref MD_SPI_RX_FIFO_2_LESS_THAN_FULL
  */
__STATIC_INLINE uint8_t md_i2s_get_rxfifo_threshold(SPI_TypeDef *SPIx)
{
    return md_spi_get_rxfifo_threshold(SPIx);
}

/**
  * @brief  Set I2S transmit fifo threshold.
  * @param  I2Sx: I2S Instance.
  * @param  Threshold This parameter can be one of the following values:
  *         @arg @ref MD_SPI_TX_FIFO_EMPTY
  *         @arg @ref MD_SPI_TX_FIFO_2_CHARACTERS_IN_THE_FIFO
  *         @arg @ref MD_SPI_TX_FIFO_QUARTER_FULL
  *         @arg @ref MD_SPI_TX_FIFO_HALF_FULL
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_txfifo_threshold(SPI_TypeDef *SPIx, uint8_t Threshold)
{
    md_spi_set_txfifo_threshold(SPIx, Threshold);
}

/**
  * @brief  Get I2S transmit fifo threshold.
  * @param  I2Sx: SPI Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref MD_SPI_TX_FIFO_EMPTY
  *         @arg @ref MD_SPI_TX_FIFO_2_CHARACTERS_IN_THE_FIFO
  *         @arg @ref MD_SPI_TX_FIFO_QUARTER_FULL
  *         @arg @ref MD_SPI_TX_FIFO_HALF_FULL
  */
__STATIC_INLINE uint8_t md_i2s_get_txfifo_threshold(SPI_TypeDef *SPIx)
{
    return md_spi_get_txfifo_threshold(SPIx);
}

/**
  * @brief  Enable I2S tx_dma function.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_enable_txdma(SPI_TypeDef *SPIx)
{
    md_spi_enable_txdma(SPIx);
}

/**
  * @brief  Disable I2S tx_dma function.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_disable_txdma(SPI_TypeDef *SPIx)
{
    md_spi_disable_txdma(SPIx);
}

/**
  * @brief  Check if I2S is enabled txdma.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enabled_txdma(SPI_TypeDef *SPIx)
{
    return md_spi_is_enabled_txdma(SPIx);
}

/**
  * @brief  Enable I2S rx_dma function.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_enable_rxdma(SPI_TypeDef *SPIx)
{
    md_spi_enable_rxdma(SPIx);
}

/**
  * @brief  Disable I2S rx_dma function.
  * @param  I2Sx: I2S Instance.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_disable_rxdma(SPI_TypeDef *SPIx)
{
    md_spi_disable_rxdma(SPIx);
}

/**
  * @brief  Check if I2S is enabled rxdma.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enabled_rxdma(SPI_TypeDef *SPIx)
{
    return md_spi_is_enabled_rxdma(SPIx);
}

/**
  * @brief  Get I2S status register(SPIx_STAT)
  * @param  I2Sx: I2S Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_i2s_get_stat(SPI_TypeDef *SPIx)
{
    return md_spi_get_stat(SPIx);
}

/**
  * @brief  Get I2S rxfifo value.
  * @param  I2Sx: I2S Instance.
  * @retval rxfifo threshold.
  */
__STATIC_INLINE uint32_t md_i2s_get_rxfifo_value(SPI_TypeDef *SPIx)
{
    return md_spi_get_rxfifo_value(SPIx);
}

/**
  * @brief  Get I2S txfifo value.
  * @param  I2Sx: I2S Instance.
  * @retval txfifo threshold.
  */
__STATIC_INLINE uint32_t  md_i2s_get_txfifo_value(SPI_TypeDef *SPIx)
{
    return md_spi_get_txfifo_value(SPIx);
}

/**
  * @brief  Get I2S busy flag.
  * @param  I2Sx: I2S Instance.
  * @retval State I2S bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_busy(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_flag_busy(SPIx);
}

/**
  * @brief  Get I2S channel side flag.
  * @param  I2Sx: I2S Instance.
  * @retval channel flag (0: left or 1: right).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_chside(SPI_TypeDef *SPIx)
{
    return (READ_BIT(SPIx->STAT, SPI_STAT_CHSIDE) == SPI_STAT_CHSIDE);;
}

/**
  * @brief  Get I2S rx threshold flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_rxth(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_flag_rxth(SPIx);
}

/**
  * @brief  Get I2S rx under flow flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_rxud(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_flag_rxud(SPIx);
}

/**
  * @brief  Get I2S rx over flow flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_rxov(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_flag_rxov(SPIx);
}

/**
  * @brief  Get I2S rx buffer full flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_rxf(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_flag_rxf(SPIx);
}

/**
  * @brief  Get I2S rx buffer not empty flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_rxne(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_flag_rxne(SPIx);
}

/**
  * @brief  Get I2S tx threshold flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_txth(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_flag_txth(SPIx);
}

/**
  * @brief  Get I2S tx under flow flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_txud(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_flag_txud(SPIx);
}

/**
  * @brief  Get I2S tx over flow flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_txov(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_flag_txov(SPIx);
}

/**
  * @brief  Get I2S tx buffer full flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_txf(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_flag_txf(SPIx);
}

/**
  * @brief  Get I2S tx buffer empty flag.
  * @param  I2Sx: I2S Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_flag_txe(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_flag_txe(SPIx);
}

/**
  * @brief  Set I2S data register value.
  * @param  I2Sx: I2S Instance.
  * @param  data: tx data.
  * @retval None.
  */
__STATIC_INLINE void md_i2s_set_data_reg(SPI_TypeDef *SPIx, uint32_t data)
{
    md_spi_set_data_reg(SPIx, data);
}

/**
  * @brief  Get I2S data register value.
  * @param  I2Sx: I2S Instance.
  * @retval data: value for data register.
  */
__STATIC_INLINE uint32_t md_i2s_get_data_reg(SPI_TypeDef *SPIx)
{
    return md_spi_get_data_reg(SPIx);
}

/**
  * @brief  Set I2S Interrupt enable Register
  * @param  SPIx SPI Instance
  * @param  ier
  * @retval None
  */
__STATIC_INLINE void md_i2s_set_ier(SPI_TypeDef *SPIx, uint32_t ier)
{
    md_spi_set_ier(SPIx, ier);
}

/**
  * @brief  Enable I2S frame error interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_fre(SPI_TypeDef *SPIx)
{
    md_spi_enable_it_fre(SPIx);
}

/**
  * @brief  Enable I2S rx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_rxth(SPI_TypeDef *SPIx)
{
    md_spi_enable_it_rxth(SPIx);
}

/**
  * @brief  Enable I2S rx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_rxud(SPI_TypeDef *SPIx)
{
    md_spi_enable_it_rxud(SPIx);
}

/**
  * @brief  Enable I2S rx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_rxov(SPI_TypeDef *SPIx)
{
    md_spi_enable_it_rxov(SPIx);
}

/**
  * @brief  Enable I2S rx full interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_rxf(SPI_TypeDef *SPIx)
{
    md_spi_enable_it_rxf(SPIx);
}

/**
  * @brief  Enable I2S rx not empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_rxne(SPI_TypeDef *SPIx)
{
    md_spi_enable_it_rxne(SPIx);
}

/**
  * @brief  Enable I2S tx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_txth(SPI_TypeDef *SPIx)
{
    md_spi_enable_it_txth(SPIx);
}

/**
  * @brief  Enable I2S tx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_txud(SPI_TypeDef *SPIx)
{
    md_spi_enable_it_txud(SPIx);
}

/**
  * @brief  Enable I2S tx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_txov(SPI_TypeDef *SPIx)
{
    md_spi_enable_it_txov(SPIx);
}

/**
  * @brief  Enable I2S tx empty interrupt.
  * @param  I2Sx I2S Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_enable_it_txe(SPI_TypeDef *SPIx)
{
    md_spi_enable_it_txe(SPIx);
}

/**
  * @brief  Set I2S interrupt disable Register
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void md_i2s_set_idr(SPI_TypeDef *SPIx, uint32_t idr)
{
    md_spi_set_idr(SPIx, idr);
}

/**
  * @brief  Disable I2S frame error interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_fre(SPI_TypeDef *SPIx)
{
    md_spi_disable_it_fre(SPIx);
}

/**
  * @brief  Disable I2S rx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_rxth(SPI_TypeDef *SPIx)
{
    md_spi_disable_it_rxth(SPIx);
}

/**
  * @brief  Disable I2S rx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_rxud(SPI_TypeDef *SPIx)
{
    md_spi_disable_it_rxud(SPIx);
}

/**
  * @brief  Disable I2S rx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_rxov(SPI_TypeDef *SPIx)
{
    md_spi_disable_it_rxov(SPIx);
}

/**
  * @brief  Disable I2S rx full interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_rxf(SPI_TypeDef *SPIx)
{
    md_spi_disable_it_rxf(SPIx);
}

/**
  * @brief  Disable I2S rx not empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_rxne(SPI_TypeDef *SPIx)
{
    md_spi_disable_it_rxne(SPIx);
}

/**
  * @brief  Disable I2S tx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_txth(SPI_TypeDef *SPIx)
{
    md_spi_disable_it_txth(SPIx);
}

/**
  * @brief  Disable I2S tx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_txud(SPI_TypeDef *SPIx)
{
    md_spi_disable_it_txud(SPIx);
}

/**
  * @brief  Disable I2S tx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_txov(SPI_TypeDef *SPIx)
{
    md_spi_disable_it_txov(SPIx);
}

/**
  * @brief  Disable I2S tx empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2s_disable_it_txe(SPI_TypeDef *SPIx)
{
    md_spi_disable_it_txe(SPIx);
}

/**
  * @brief  Get I2S_IVS Register
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_i2s_get_ivs(SPI_TypeDef *SPIx)
{
    return md_spi_get_ivs(SPIx);
}

/**
  * @brief  Check if the frame error interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enabled_it_fre(SPI_TypeDef *SPIx)
{
    return md_spi_is_enabled_it_fre(SPIx);
}

/**
  * @brief  Check if the rx threshold interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enabled_it_rxth(SPI_TypeDef *SPIx)
{
    return md_spi_is_enabled_it_rxth(SPIx);
}

/**
  * @brief  Check if the rx under flow interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enabled_it_rxud(SPI_TypeDef *SPIx)
{
    return md_spi_is_enabled_it_rxud(SPIx);
}

/**
  * @brief  Check if the rx over flow interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enabled_it_rxov(SPI_TypeDef *SPIx)
{
    return md_spi_is_enabled_it_rxov(SPIx);
}

/**
  * @brief  Check if the rx full interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enabled_it_rxf(SPI_TypeDef *SPIx)
{
    return md_spi_is_enabled_it_rxf(SPIx);
}

/**
  * @brief  Check if the rx not empty interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enabled_it_rxne(SPI_TypeDef *SPIx)
{
    return md_spi_is_enabled_it_rxne(SPIx);
}

/**
  * @brief  Check if the tx threshold interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enabled_it_txth(SPI_TypeDef *SPIx)
{
    return md_spi_is_enabled_it_txth(SPIx);
}

/**
  * @brief  Check if the tx under flow interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enabled_it_txud(SPI_TypeDef *SPIx)
{
    return md_spi_is_enabled_it_txud(SPIx);
}

/**
  * @brief  Check if the tx over flow interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enabled_it_txov(SPI_TypeDef *SPIx)
{
    return md_spi_is_enabled_it_txov(SPIx);
}

/**
  * @brief  Check if the tx empty interrupt is enabled or disabled.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_enabled_it_txe(SPI_TypeDef *SPIx)
{
    return md_spi_is_enabled_it_txe(SPIx);
}

/**
  * @brief  Get I2S_RIF Register
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_i2s_get_rif(SPI_TypeDef *SPIx)
{
    return md_spi_get_rif(SPIx);
}

/**
  * @brief  Get frame error interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_fre(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_it_fre(SPIx);
}

/**
  * @brief  Get rx threshold interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_rxth(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_it_rxth(SPIx);
}

/**
  * @brief  Get rx under flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_rxud(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_it_rxud(SPIx);
}

/**
  * @brief  Get rx over flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_rxov(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_it_rxov(SPIx);
}

/**
  * @brief  Get rx full interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_rxf(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_it_rxf(SPIx);
}

/**
  * @brief  Get rx not empty interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_rxne(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_it_rxne(SPIx);
}

/**
  * @brief  Get tx threshold interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_txth(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_it_txth(SPIx);
}

/**
  * @brief  Get tx under flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_txud(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_it_txud(SPIx);
}

/**
  * @brief  Get tx over flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_txov(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_it_txov(SPIx);
}

/**
  * @brief  Get tx empty interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_active_it_txe(SPI_TypeDef *SPIx)
{
    return md_spi_is_active_it_txe(SPIx);
}

/**
  * @brief  Get I2S_IFM Register
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_i2s_get_ifm(SPI_TypeDef *SPIx)
{
    return md_spi_get_ifm(SPIx);
}

/**
  * @brief  Mask frame error interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_masked_it_fre(SPI_TypeDef *SPIx)
{
    return md_spi_is_masked_it_fre(SPIx);
}

/**
  * @brief  Mask rx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_masked_it_rxth(SPI_TypeDef *SPIx)
{
    return md_spi_is_masked_it_rxth(SPIx);
}

/**
  * @brief  Mask rx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_masked_it_rxud(SPI_TypeDef *SPIx)
{
    return md_spi_is_masked_it_rxud(SPIx);
}

/**
  * @brief  Mask rx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_masked_it_rxov(SPI_TypeDef *SPIx)
{
    return md_spi_is_masked_it_rxov(SPIx);
}

/**
  * @brief  Mask rx full interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_masked_it_rxf(SPI_TypeDef *SPIx)
{
    return md_spi_is_masked_it_rxf(SPIx);
}

/**
  * @brief  Mask rx not empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_masked_it_rxne(SPI_TypeDef *SPIx)
{
    return md_spi_is_masked_it_rxne(SPIx);
}

/**
  * @brief  Mask tx threshold interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_masked_it_txth(SPI_TypeDef *SPIx)
{
    return md_spi_is_masked_it_txth(SPIx);
}

/**
  * @brief  Mask tx under flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_masked_it_txud(SPI_TypeDef *SPIx)
{
    return md_spi_is_masked_it_txud(SPIx);
}

/**
  * @brief  Mask tx over flow interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_masked_it_txov(SPI_TypeDef *SPIx)
{
    return md_spi_is_masked_it_txov(SPIx);
}

/**
  * @brief  Mask tx empty interrupt.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2s_is_masked_it_txe(SPI_TypeDef *SPIx)
{
    return md_spi_is_masked_it_txe(SPIx);
}

/**
  * @brief  Set I2S_ICR Register
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void md_i2s_set_icr(SPI_TypeDef *SPIx, uint32_t icr)
{
    md_spi_set_icr(SPIx, icr);
}

/**
  * @brief  Clear frame error interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_it_fre(SPI_TypeDef *SPIx)
{
    md_spi_clear_it_fre(SPIx);
}

/**
  * @brief  Clear rx threshold interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_it_rxth(SPI_TypeDef *SPIx)
{
    md_spi_clear_it_rxth(SPIx);
}

/**
  * @brief  Clear rx under flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_it_rxud(SPI_TypeDef *SPIx)
{
    md_spi_clear_it_rxud(SPIx);
}

/**
  * @brief  Clear rx over flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_it_rxov(SPI_TypeDef *SPIx)
{
    md_spi_clear_it_rxov(SPIx);
}

/**
  * @brief  Clear rx full interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_it_rxf(SPI_TypeDef *SPIx)
{
    md_spi_clear_it_rxf(SPIx);
}

/**
  * @brief  Clear rx not empty interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_it_rxne(SPI_TypeDef *SPIx)
{
    md_spi_clear_it_rxne(SPIx);
}

/**
  * @brief  Clear tx threshold interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_it_txth(SPI_TypeDef *SPIx)
{
    md_spi_clear_it_txth(SPIx);
}

/**
  * @brief  Clear tx under flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_it_txud(SPI_TypeDef *SPIx)
{
    md_spi_clear_it_txud(SPIx);
}

/**
  * @brief  Clear tx over flow interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_it_txov(SPI_TypeDef *SPIx)
{
    md_spi_clear_it_txov(SPIx);
}

/**
  * @brief  Clear tx empty interrupt flag.
  * @param  SPIx SPI Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_i2s_clear_it_txe(SPI_TypeDef *SPIx)
{
    md_spi_clear_it_txe(SPIx);
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
