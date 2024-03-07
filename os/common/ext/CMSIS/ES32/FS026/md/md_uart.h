/**********************************************************************************
 *
 * @file    md_uart.h
 * @brief   header file of md_uart.c
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
#ifndef __MD_UART_H__
#define __MD_UART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include <stdbool.h>
#include "fs026.h"


/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_UART UART
  * @brief UART micro driver
  * @{
  */

/** @defgroup MD_UART_Pubulic_Types UART Pubulic Types
  * @{
  */

/**
  * @brief MD_UART_Public_Types UART Public Init Type
  */

typedef struct
{
    uint32_t BaudRate;                  /*!< This field defines expected Usart communication baud rate.*/

    uint32_t BitOrder;                  /*!< Specifies the MSB of data bits will be transmitted or received first.
                                           This parameter can be a value of @ref MD_UART_LCON_MSB_FIRST.*/

    uint32_t Parity;                    /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref MD_UART_LCON_PS_EVEN.*/

    uint32_t StopBits;                  /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref MD_UART_LCON_STOP_1.*/

    uint32_t DataWidth;                 /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref MD_UART_LCON_DLS_8.*/

} md_uart_init_typedef;

/**
  * @}
  */

/** @defgroup MD_UART_Public_Macros UART Public Macros
  * @{
  */

/**
  * @brief UART_BAUDRATE UART Baudrate Definitation
  */
#define  MD_UART_BAUDRATE_1200              (1200U)                            /* baud rate=1200   bps */
#define  MD_UART_BAUDRATE_2400              (2400U)                            /* baud rate=2400   bps */
#define  MD_UART_BAUDRATE_4800              (4800U)                            /* baud rate=4800   bps */
#define  MD_UART_BAUDRATE_9600              (9600U)                            /* baud rate=9600   bps */
#define  MD_UART_BAUDRATE_19200             (19200U)                           /* baud rate=19200  bps */
#define  MD_UART_BAUDRATE_38400             (38400U)                           /* baud rate=38400  bps */
#define  MD_UART_BAUDRATE_57600             (57600U)                           /* baud rate=57600  bps */
#define  MD_UART_BAUDRATE_115200            (115200U)                          /* baud rate=115200 bps */
#define  MD_UART_BAUDRATE_230400            (230400U)                          /* baud rate=230400 bps */
#define  MD_UART_BAUDRATE_460800            (460800U)                          /* baud rate=460800 bps */
#define  MD_UART_BAUDRATE_512000            (512000U)                          /* baud rate=512000 bps */
#define  MD_UART_BAUDRATE_921600            (921600U)                          /* baud rate=921600 bps */

/**
  * @brief UART_LCON UART_LCON Register
  */
#define MD_UART_LCON_MSB_FIRST              (1U)                               /** @brief data Most significant bit first */
#define MD_UART_LCON_LSB_FIRST              (0U)                               /** @brief data Least significant bit first */

#define MD_UART_LCON_PS_EVEN                (3U)                               /** @brief data Even parity bit selection */
#define MD_UART_LCON_PS_ODD                 (1U)                               /** @brief data Odd parity bit selection */
#define MD_UART_LCON_PS_NONE                (0U)                               /** @brief data No parity bit selection */

#define MD_UART_LCON_STOP_2                 (1U)                               /** @brief data 2(1.5) Stop bit */
#define MD_UART_LCON_STOP_1                 (0U)                               /** @brief data 2(1.5) Stop bit */
#define MD_UART_LCON_STOP_1P5               (1U)                               /** @brief data 2(1.5) Stop bit */
#define MD_UART_LCON_STOP_0P5               (0U)

#define MD_UART_LCON_DLS_8                  (0U)                               /** @brief data Date length 8  */
#define MD_UART_LCON_DLS_7                  (1U)                               /** @brief data Date length 7 */
#define MD_UART_LCON_DLS_6                  (2U)                               /** @brief data Date length 6  */
#define MD_UART_LCON_DLS_5                  (3U)                               /** @brief data Date length 5  */

/**
  * @brief UART_MCON UART_MCON Register
  */
#define MD_UART_MCON_TXFLOAT_HIGH           (0)   /** @brief When the transmitter is not transmitting, the TX pin outputs high level */
#define MD_UART_MCON_TXFLOAT_FLOATING       (1)   /** @brief When the transmitter is not transmitting, the TX pin is floating */

#define MD_UART_MCON_ABRMOD_0               (0U)    /** @brief data Receiver DMA disable */
#define MD_UART_MCON_ABRMOD_1               (1U)    /** @brief data Repeat auto-baud rate detection after timeout enable */
#define MD_UART_MCON_ABRMOD_2               (2U)    /** @brief data Repeat auto-baud rate detection after timeout disable */

#define MD_UART_MCON_RTSSET_HIGH            (0U)    /** @brief data RTSn set control bit RTSn level is 1 */
#define MD_UART_MCON_RTSSET_LOW             (1U)    /** @brief data RTSn set control bit RTSn level is 0 */

/**
  * @brief UART_RS485 UART_RS485 Register
  */
#define MD_UART_RS485_AADINV_LOW            (0U)  /** @brief data Low : Transfering data, High: Idle */
#define MD_UART_RS485_AADINV_HIGH           (1U)  /** @brief data High: Transfering data, Low : Idle */

/**
  * @brief UART_SCARD UART_SCARD Register
  */
#define MD_UART_SCARD_IRDA_AND_NORMAL_1_DIVIDE      (1U)  /** @brief 1 Divide, IRDA and NORMAL Mode*/
#define MD_UART_SCARD_IRDA_AND_NORMAL_2_DIVIDE      (2U)  /** @brief 2 Divide, IRDA and NORMAL Mode*/
#define MD_UART_SCARD_SMART_CARD_2_DIVIDE           (1U)  /** @brief 1 Divide, Smart Card Mode */
#define MD_UART_SCARD_SMART_CARD_4_DIVIDE           (2U)  /** @brief 4 Divide, Smart Card Mode */
#define MD_UART_SCARD_SMART_CARD_6_DIVIDE           (3U)  /** @brief 6 Divide, Smart Card Mode */

/**
  * @brief UART_LIN UART_LIN Register
  */
#define MD_UART_LIN_LINBDL_10         (0)   /** @brief 10-bit break character detection */
#define MD_UART_LIN_LINBDL_11         (1)   /** @brief 11-bit break character detection */

/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions UART Public Functions
  * @{
  */

/** @defgroup MD_UART_Public_Functions_Group2 RXDATA
  * @{
  */
/**
  * @brief  Read 8-Bits Receiver Buffer Register
  * @note   Contains the received data character.
  *         The RXBR register provides the parallel interface between the
  *         input shift register and the internal bus.
  *         When receiving with the parity enabled, the value read in the
  *         MSB bit is the received parity bit.
  * @param  UARTx UART Instance
  * @retval RxData Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint8_t md_uart_get_recv_data8(UART_TypeDef *UARTx)
{
    return (uint8_t)(READ_REG(UARTx->RXDATA));
}

/**
  * @brief  Read 9-Bits Receiver Buffer Register
  * @note   Contains the received data character.
  *         The RXBR register provides the parallel interface between the
  *         input shift register and the internal bus.
  *         When receiving with the parity enabled, the value read in the
  *         MSB bit is the received parity bit.
  * @param  UARTx UART Instance
  * @retval RxData Value between Min_Data=0x00 and Max_Data=0x1FF
  */
__STATIC_INLINE uint16_t md_uart_get_recv_data9(UART_TypeDef *UARTx)
{
    return (uint16_t)(READ_REG(UARTx->RXDATA));
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group3 TXDATA
  * @{
  */
/**
  * @brief  Write 9-Bits Transmit buffer register
  * @note   Contains the data character to be transmitted.
  *         The TXBR register provides the parallel interface between the
  *         internal bus and the output shift register.
  *         When transmitting with the parity enabled the value written in
  *         the MSB (bit 7 or bit 8 depending on the data length) has no
  *         effect because it is replaced by the parity.
  * @param  UARTx UART Instance
  * @param  TxData Value between Min_Data=0x00 and Max_Data=0x1FF
  * @retval None
  */
__STATIC_INLINE void md_uart_set_send_data9(UART_TypeDef *UARTx, uint16_t TxData)
{
    WRITE_REG(UARTx->TXDATA, TxData);
}

/**
  * @brief  Write 8-Bits Transmit buffer register
  * @note   Contains the data character to be transmitted.
  *         The TXBR register provides the parallel interface between the
  *         internal bus and the output shift register.
  *         When transmitting with the parity enabled the value written in
  *         the MSB (bit 7 or bit 8 depending on the data length) has no
  *         effect because it is replaced by the parity.
  * @param  UARTx UART Instance
  * @param  TxData Value between Min_Data=0x00 and Max_Data=0xFF
  * @retval None
  */
__STATIC_INLINE void md_uart_set_send_data8(UART_TypeDef *UARTx, uint8_t TxData)
{
    WRITE_REG(UARTx->TXDATA, TxData);
}

/**
  * @brief  Read 8-Bits Transmit buffer register
  * @note   Contains the data character to be transmitted.
  *         The TXBR register provides the parallel interface between the
  *         internal bus and the output shift register.
  *         When transmitting with the parity enabled the value written in
  *         the MSB (bit 7 or bit 8 depending on the data length) has no
  *         effect because it is replaced by the parity.
  * @param  UARTx UART Instance
  * @param  TxData Value between Min_Data=0x00 and Max_Data=0xFF
  * @retval None
  */
__STATIC_INLINE uint8_t md_uart_get_send_data8(UART_TypeDef *UARTx)
{
    return (uint8_t)(READ_REG(UARTx->TXDATA));
}

/**
  * @brief  Read 9-Bits Transmit buffer register
  * @note   Contains the data character to be transmitted.
  *         The TXBR register provides the parallel interface between the
  *         internal bus and the output shift register.
  *         When transmitting with the parity enabled the value written in
  *         the MSB (bit 7 or bit 8 depending on the data length) has no
  *         effect because it is replaced by the parity.
  * @param  UARTx UART Instance
  * @param  TxData Value between Min_Data=0x00 and Max_Data=0x1FF
  * @retval None
  */
__STATIC_INLINE uint16_t md_uart_get_send_data9(UART_TypeDef *UARTx)
{
    return (uint16_t)(READ_REG(UARTx->TXDATA));
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group4 BRR
  * @{
  */
/**
  * @brief  Set UARTx Baud rate register.
  * @note   This bits can only be written when the UART is disabled.
  *         (RXEN and TXEN=0 in the LCR register).
  * @param  UARTx UART Instance.
  * @param  UART buad rate value.
  * @retval None
  */
__STATIC_INLINE void md_uart_set_baudrate(UART_TypeDef *UARTx, uint32_t baudrate)
{
    WRITE_REG(UARTx->BRR, baudrate);
}

/**
  * @brief  Get UARTx baud rate.
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0).
  * @param  UARTx UART Instance.
  * @retval UARTx Baudrate.
  */
__STATIC_INLINE uint32_t md_uart_get_baudrate(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_REG(UARTx->BRR));
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group5 LCON
  * @{
  */
/**
  * @brief  Set UART_LCON Register
  * @param  rcu RCU Instance
  * @param  lcon
  */
__STATIC_INLINE void md_uart_set_lcon(UART_TypeDef *UARTx, uint32_t lcon)
{
    WRITE_REG(UARTx->LCON, lcon);
}

/**
  * @brief  Get UART_LCON Register
  * @param  rcu RCU Instance
  * @retval UARTx LCON.
  */
__STATIC_INLINE uint32_t md_uart_get_lcon(UART_TypeDef *UARTx)
{
    return (uint32_t)READ_REG(UARTx->LCON);
}

/**
  * @brief  UARTx Transmitter enable.
  * @note   This bit enables the transmitter. It is set and cleared by
  *         software.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_tx(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_TXEN);
}

/**
  * @brief  UARTx Transmitter disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_tx(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_TXEN);
}

/**
  * @brief  Check if UART Transmitter is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_tx(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_TXEN) == (UART_LCON_TXEN));
}

/**
  * @brief  UARTx Receiver enable
  * @note   This bit enables the receiver. It is set and cleared by software.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_rx(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_RXEN);
}

/**
  * @brief  UARTx Receiver Disable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_rx(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_RXEN);
}

/**
  * @brief  Check if UARTx Receiver is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_rx(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_RXEN) == (UART_LCON_RXEN));
}

/**
  * @brief  UARTx Debounce Enable.
  * @note   This bit enables the debounce. It is set and cleared by software.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_dbcen(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_DBCEN);
}

/**
  * @brief  UART Debounce Disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_dbcen(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_DBCEN);
}

/**
  * @brief  Check if UART Debounce is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_dbcen(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_DBCEN) == (UART_LCON_DBCEN));
}

/**
  * @brief  Enable UARTx Break control bit.
  * @note   This is used to cause a break condition to be transmitted to the
  *         receiving device. The serial data output (Tx) is forced to the
  *         Spacing State (logic 0).
  *         This bit can only be written when the UART is disabled.
  *         (RXENand TXEN=0).
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_break(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_BREAK);
}

/**
  * @brief  Disable UARTx Break control bit.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_break(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_BREAK);
}

/**
  * @brief  Check if UARTx Break control bit is enabled.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_break(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_BREAK) == (UART_LCON_BREAK));
}

/**
  * @brief  UARTx Swap TX/RX pins.
  * @note   This allows to work in the case of a cross-wired connection to another UART.
  *         This bit can only be written when the UART is disabled (RXEN and TXEN=0).
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_swap(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_SWAP);
}

/**
  * @brief  UARTx Swap TX/RX pins disabl.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_disable_swap(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_SWAP);
}

/**
  * @brief  Check if UART Swap TX/RX pins is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_swap(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_SWAP) == (UART_LCON_SWAP));
}

/**
  * @brief  UARTx TX pin active level inversion.
  * @note   This allows the use of an external inverter on the TX line.
  *         This bit can only be written when the UART is disabled (RXEN and TXEN=0).
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_txinv(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_TXINV);
}

/**
  * @brief  UARTx TX pin active level inversion disable.
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0).
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_txinv(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_TXINV);
}

/**
  * @brief  Check if UARTx TX pin active level is inverted.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_txinv(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_TXINV) == (UART_LCON_TXINV));
}

/**
  * @brief  UARTx RX pin active level inversion.
  * @note   This allows the use of an external inverter on the RX line.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_rxinv(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_RXINV);
}

/**
  * @brief  UARTx RX pin active level inversion disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_rxinv(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_RXINV);
}

/**
  * @brief  Check if UART RX pin active level is inverted.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_rxinv(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_RXINV) == (UART_LCON_RXINV));
}

/**
  * @brief  UARTx Binary data inversion.
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0).
  *         The parity bit is also inverted.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_datainv(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_DATAINV);
}

/**
  * @brief  UARTx Binary data inverted disable.
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0).
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_datainv(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_DATAINV);
}

/**
  * @brief  Check if UARTx Binary data is inverted.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_datainv(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_DATAINV) == (UART_LCON_DATAINV));
}

/**
  * @brief  Set UARTx Least significant bit first.
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0).
  * @param  UARTx UART Instance.
  * @retval None
  */
__STATIC_INLINE void md_uart_set_bitorder_lsb(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_MSB);
}

/**
  * @brief  Set UARTx Most significant bit first.
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0).
  * @param  UARTx UART Instance.
  * @retval None
  */
__STATIC_INLINE void md_uart_set_bitorder_msb(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_MSB);
}

/**
  * @brief  Get UARTx Most significant bit first bit.
  * @param  UARTx UART Instance
  */
__STATIC_INLINE uint32_t md_uart_get_bitorder(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LCON, UART_LCON_MSB) >> UART_LCON_MSB_POS);
}

/**
  * @brief  UARTx Parity bit selection
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @param  parity This parameter can be one of the following values:
  *         @arg @ref MD_UART_LCON_PS_EVEN
  *         @arg @ref MD_UART_LCON_PS_ODD
  *         @arg @ref MD_UART_LCON_PS_NONE
  * @retval None
  */
__STATIC_INLINE void md_uart_set_parity(UART_TypeDef *UARTx, uint32_t parity)
{
    MODIFY_REG(UARTx->LCON, UART_LCON_PS | UART_LCON_PE, parity << UART_LCON_PE_POS);
}

/**
  * @brief  Get UARTx Parity bit selection
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_UART_LCON_PS_EVEN
  *         @arg @ref MD_UART_LCON_PS_ODD
  *         @arg @ref MD_UART_LCON_PS_NONE
  */
__STATIC_INLINE uint32_t md_uart_get_parity(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LCON, UART_LCON_PS | UART_LCON_PE) >> UART_LCON_PE_POS);
}

/**
  * @brief  Set UARTx Stop bit.
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance.
  * @param  stop This parameter can be one of the following values:
  *         @arg @ref MD_UART_LCON_STOP_1 (Nomal mode)
  *         @arg @ref MD_UART_LCON_STOP_2 (Nomal mode)
  *         @arg @ref MD_UART_LCON_STOP_1P5 (Smart card mode)
  *         @arg @ref MD_UART_LCON_STOP_0P5 (Smart card mode)
  * @retval None
  */
__STATIC_INLINE void md_uart_set_stop(UART_TypeDef *UARTx, uint32_t stop)
{
    MODIFY_REG(UARTx->LCON, UART_LCON_STOP, stop << UART_LCON_STOP_POS);
}

/**
  * @brief  Get UARTx Stop bit.
  * @param  UARTx UART Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_UART_LCON_STOP_1 (Nomal mode)
  *         @arg @ref MD_UART_LCON_STOP_2 (Nomal mode)
  *         @arg @ref MD_UART_LCON_STOP_1P5 (Smart card mode)
  *         @arg @ref MD_UART_LCON_STOP_0P5 (Smart card mode)
  */
__STATIC_INLINE uint32_t md_uart_get_stop(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LCON, UART_LCON_STOP) >> UART_LCON_STOP_POS);
}

/**
  * @brief  UARTx Date length selection.
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0).
  * @param  UARTx UART Instance.
  * @param  width This parameter can be one of the following values:
  *         @arg @ref MD_UART_LCON_DLS_8
  *         @arg @ref MD_UART_LCON_DLS_7
  *         @arg @ref MD_UART_LCON_DLS_6
  *         @arg @ref MD_UART_LCON_DLS_5
  * @retval None
  */
__STATIC_INLINE void md_uart_set_datawidth(UART_TypeDef *UARTx, uint32_t width)
{
    MODIFY_REG(UARTx->LCON, UART_LCON_DLS, width << UART_LCON_DLS_POSS);
}

/**
  * @brief  Get UARTx data stop bit
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_UART_LCON_DLS_8
  *         @arg @ref MD_UART_LCON_DLS_7
  *         @arg @ref MD_UART_LCON_DLS_6
  *         @arg @ref MD_UART_LCON_DLS_5
  */
__STATIC_INLINE uint32_t md_uart_get_datawidth(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LCON, UART_LCON_DLS) >> UART_LCON_DLS_POSS);
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group6 MCON
  * @{
  */
/**
  * @brief  Set UART_MCON Register
  * @param  rcu RCU Instance
  * @param  mcon
  * @retval None
  */
__STATIC_INLINE void md_uart_set_mcon(UART_TypeDef *UARTx, uint32_t mcon)
{
    WRITE_REG(UARTx->MCON, mcon);
}

/**
  * @brief  Get UART_MCON Register
  * @param  rcu RCU Instance
  * @retval UART mode control
  */
__STATIC_INLINE uint32_t md_uart_get_mcon(UART_TypeDef *UARTx)
{
    return (uint32_t)READ_REG(UARTx->MCON);
}

/**
  * @brief  Set Transmitter waits for sending status selection
  * @param  UARTx UART Instance.
  * @param  txfloat
            @arg @ref MD_UART_MCON_TXFLOAT_HIGH
            @arg @ref MD_UART_MCON_TXFLOAT_FLOATING
  * @retval None
  */

__STATIC_INLINE void md_uart_set_tx_floating(UART_TypeDef *UARTx, uint32_t txfloat)
{
    MODIFY_REG(UARTx->MCON, UART_MCON_TXFLOAT, txfloat << UART_MCON_TXFLOAT_POS);
}

/**
  * @brief  Get Transmitter waits for sending status selection
  * @param  UARTx UART Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_UART_MCON_TXFLOAT_HIGH
            @arg @ref MD_UART_MCON_TXFLOAT_FLOATING
  */
__STATIC_INLINE uint32_t md_uart_get_tx_floating(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->MCON, UART_MCON_TXFLOAT >> UART_MCON_TXFLOAT_POS));
}

/**
  * @brief  UARTx Transmitter DMA enable.
  * @note   This bit is set and cleared by software. This bit enables the DMA transmitter.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_txdma(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_TXDMAEN);
}

/**
  * @brief  UARTx Transmitter DMA enable disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_txdma(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_TXDMAEN);
}

/**
  * @brief  Check if UARTx Transmitter DMA is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_txdma(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->MCON, UART_MCON_TXDMAEN) == (UART_MCON_TXDMAEN));
}

/**
  * @brief  UARTx Receiver DMA enable.
  * @note   This bit is set and cleared by software. This bit enables the DMA Receiver.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_rxdma(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_RXDMAEN);
}

/**
  * @brief  UARTx Receiver DMA disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_rxdma(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_RXDMAEN);
}

/**
  * @brief  Check if UARTx UARTx Receiver DMA is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_rxdma(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->MCON, UART_MCON_RXDMAEN) == (UART_MCON_RXDMAEN));
}

/**
  * @brief  UARTx Auto baud rate detection repeat enable.
  * @note   This bit is set to enable baud rate detection repeat one more time
  *         after the first failure of auto-baud rate detection.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_abrrept(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_ABRREPT);
}

/**
  * @brief  UARTx Auto baud rate detection repeat disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_abrrept(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_ABRREPT);
}

/**
  * @brief  Check if UARTx Auto baud rate detection repeat is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_abrrept(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->MCON, UART_MCON_ABRREPT) == (UART_MCON_ABRREPT));
}

/**
  * @brief  Set UARTx Auto baud rate mode.
  * @note   MD_UART_MCON_ABRMOD_0: Mode 0 detect falling edge to second falling edge (detect 2 Bps).
  *         MD_UART_MCON_ABRMOD_1: Mode 1 detect falling edge to first rising edge (detect 1 Bps).
  *         MD_UART_MCON_ABRMOD_2: Mode 2 detect falling edge to first rising edge (detect 2 Bps).
  * @param  UARTx UART Instance.
  * @param  mode This parameter can be one of the following values:
  *         @arg @ref MD_UART_MCON_ABRMOD_0
  *         @arg @ref MD_UART_MCON_ABRMOD_1
  *         @arg @ref MD_UART_MCON_ABRMOD_2
  * @retval None
  */
__STATIC_INLINE void md_uart_set_abrmod(UART_TypeDef *UARTx, uint32_t mode)
{
    MODIFY_REG(UARTx->MCON, UART_MCON_ABRMOD, mode << UART_MCON_ABRMOD_POSS);
}

/**
  * @brief  Get UARTx Auto baud rate mode.
  * @param  UARTx UART Instance.
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_UART_MCON_ABRMOD_0
  *         @arg @ref MD_UART_MCON_ABRMOD_1
  *         @arg @ref MD_UART_MCON_ABRMOD_2
  */
__STATIC_INLINE uint32_t md_uart_get_abrmod(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->MCON, UART_MCON_ABRMOD) >> UART_MCON_ABRMOD_POSS);
}

/**
  * @brief  UARTx Auto baud rate enable.
  * @note   This bit is set by software and cleared by hardware after the
  *         auto-baud rate finish.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_abr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_ABREN);
}

/**
  * @brief  UARTx Auto baud rate disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_abr(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_ABREN);
}

/**
  * @brief  Check if UARTx Auto baud rate is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_abr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->MCON, UART_MCON_ABREN) == (UART_MCON_ABREN));
}

/**
  * @brief  UARTx break request enable.
  * @note   This bit is set by software and automatically cleared by
  *         hardware in the next clock cycle.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_trigger_break_request(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_BKREQ);
}

/**
  * @brief  UARTx Half-duplex enable(Only UART).
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_half_duplex(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_HDEN);
}

/**
  * @brief  UARTx Half-duplex disable(Only UART).
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_half_duplex(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_HDEN);
}

/**
  * @brief  Check if UARTx Half-duplex is enabled.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_half_duplex(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->MCON, UART_MCON_HDEN) == (UART_MCON_HDEN));
}

/**
  * @brief  UARTx IrDA mode enable(Only UART).
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_irda(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_IREN);
}

/**
  * @brief  UARTx IrDA mode disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_irda(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_IREN);
}

/**
  * @brief  Check if UARTx IrDA mode is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_irda(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->MCON, UART_MCON_IREN) == (UART_MCON_IREN));
}

/**
  * @brief  UARTx Auto flow control enable.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_auto_flow(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_AFCEN);
}

/**
  * @brief  UARTx Auto flow control disable.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_auto_flow(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_AFCEN);
}

/**
  * @brief  Check if Auto flow control is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_auto_flow(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->MCON, UART_MCON_AFCEN) == (UART_MCON_AFCEN));
}

/**
  * @brief  Set UARTx RTSn set control bit.
  * @note   If Auto flow control disable, user can control RTSn output level by this bit.
  *         MD_UART_MCON_RTSSET_HIGH: RTSn level is 1
  *         MD_UART_MCON_RTSSET_LOW : RTSn level is 0
  * @param  UARTx UART Instance.
  * @param  This parameter can be one of the following values:
  *         @arg @ref MD_UART_MCON_RTSSET_HIGH
  *         @arg @ref MD_UART_MCON_RTSSET_LOW
  * @retval None
  */
__STATIC_INLINE void md_uart_set_rtsset(UART_TypeDef *UARTx, uint32_t level)
{
    MODIFY_REG(UARTx->MCON, UART_MCON_RTSSET, level >> UART_MCON_RTSSET_POS);
}

/**
  * @brief  Get UARTx RTSn set control bit.
  * @param  UARTx UART Instance.
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_UART_MCON_RTSSET_HIGH
  *         @arg @ref MD_UART_MCON_RTSSET_LOW
  */
__STATIC_INLINE uint32_t md_uart_get_rtsset(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->MCON, UART_MCON_RTSSET) >> UART_MCON_RTSSET_POS);
}

/**
  * @brief  UARTx LoopBack enable.
  * @note   This is used to put the UART into a diagnostic mode for test purpose.
  *         If operating in UART mode, data on the TXD line is held high,
  *         while serial data output is looped back to the RXD line, internally.
  *         In this mode, all the interrupts are fully functional.
  *         If operating in infrared mode, data on the TXD with IrDA line is held low,
  *         while serial data output is inverted and looped back to the RXD line.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_loopback(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_LPBKEN);
}

/**
  * @brief  UARTx LoopBack disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_loopback(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_LPBKEN);
}

/**
  * @brief  Check if UARTx LoopBack is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_loopback(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->MCON, UART_MCON_LPBKEN) == (UART_MCON_LPBKEN));
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group7 RS485
  * @{
  */
/**
  * @brief  Set UART_RS485 Register
  * @param  rcu RCU Instance
  * @param  rs485
  */
__STATIC_INLINE void md_uart_set_rs485(UART_TypeDef *UARTx, uint32_t rs485)
{
    WRITE_REG(UARTx->RS485, rs485);
}

/**
  * @brief  Get UART_RS485 Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE uint32_t md_uart_get_rs485(UART_TypeDef *UARTx)
{
    return (uint32_t)READ_REG(UARTx->RS485);
}

/**
  * @brief  Set UARTx Delay value.
  * @note   Contains a direction control RTSn Delay value. This register
  *         works in conjunction with an 8-bit counter in terms of number of
  *         DIVISOR bit duration.
  * @param  UARTx UART Instance.
  * @param  UARTx Delay value.
  * @retval None.
  */
__STATIC_INLINE void md_uart_set_rs485_dly(UART_TypeDef *UARTx, uint32_t delay)
{
    MODIFY_REG(UARTx->RS485, UART_RS485_DLY, delay << UART_RS485_DLY_POSS);
}

/**
  * @brief  Get UARTx Delay value.
  * @param  UARTx UART Instance.
  * @retval UARTx Delay value.
  */
__STATIC_INLINE uint32_t md_uart_get_rs485_dly(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->RS485, UART_RS485_DLY) >> UART_RS485_DLY_POSS);
}

/**
  * @brief  Set UARTx Address match value.
  * @param  UARTx UART Instance.
  * @param  UARTx Address match value.
  * @retval None
  */
__STATIC_INLINE void md_uart_set_rs485_addr(UART_TypeDef *UARTx, uint32_t address)
{
    MODIFY_REG(UARTx->RS485, UART_RS485_ADDR, address << UART_RS485_ADDR_POSS);
}

/**
  * @brief  Get UARTx Address match value.
  * @param  UARTx UART Instance.
  * @retval UARTx Address match value.
  */
__STATIC_INLINE uint32_t md_uart_get_rs485_addr(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->RS485, UART_RS485_ADDR) >> UART_RS485_ADDR_POSS);
}

/**
  * @brief  Set UARTx Automatic address detection invert.
  * @note   This bit retains the DE(RTSn) polarity direction control signal on pin.
  * @param  UARTx UART Instance.
  * @param  aadinv can be one of the following value:
  *         @arg @ref MD_UART_RS485_AADINV_LOW  (Low : Transfering data, High: Idle)
  *         @arg @ref MD_UART_RS485_AADINV_HIGH (High: Transfering data, Low : Idle)
  * @retval None
  */
__STATIC_INLINE void md_uart_set_rs485_auto_addr_invert(UART_TypeDef *UARTx, uint32_t aadinv)
{
    MODIFY_REG(UARTx->RS485, UART_RS485_AADINV, aadinv << UART_RS485_AADINV_POS);
}

/**
  * @brief  Get UARTx Automatic address detection invert.
  * @param  UARTx UART Instance.
  * @retval the retval can be one of the following value:
  *         @arg @ref MD_UART_RS485_AADINV_LOW  (Low : Transfering data, High: Idle)
  *         @arg @ref MD_UART_RS485_AADINV_HIGH (High: Transfering data, Low : Idle)
  */
__STATIC_INLINE uint32_t md_uart_get_rs485_auto_addr_invert(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->RS485, UART_RS485_AADINV) >> UART_RS485_AADINV_POS);
}

/**
  * @brief  UARTx Automatic address detection auto-control enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_auto_dir_mode(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->RS485, UART_RS485_AADACEN);
}

/**
  * @brief  UARTx Automatic address detection auto-control disable
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_auto_dir_mode(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->RS485, UART_RS485_AADACEN);
}

/**
  * @brief  Check if UARTx Automatic address detection auto-control is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_auto_dir_mode(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RS485, UART_RS485_AADACEN) == (UART_RS485_AADACEN));
}

/**
  * @brief  UARTx Automatic address detection normal mode enable.
  * @note   Note that it can be active with RS-485 AAD operation mode.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_autoaddr_normal_mode(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->RS485, UART_RS485_AADNEN);
}

/**
  * @brief  UARTx Automatic address detection normal mode disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_autoaddr_normal_mode(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->RS485, UART_RS485_AADNEN);
}

/**
  * @brief  Check if Automatic address detection normal mode is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_autoaddr_normal_mode(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RS485, UART_RS485_AADNEN) == (UART_RS485_AADNEN));
}

/**
  * @brief  UARTx Automatic address detection operation mode enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_aaden(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->RS485, UART_RS485_AADEN);
}

/**
  * @brief  UARTx Automatic address detection operation mode disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_aaden(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->RS485, UART_RS485_AADEN);
}

/**
  * @brief  Check if UARTx Automatic address detection operation mode is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_aaden(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RS485, UART_RS485_AADEN) == (UART_RS485_AADEN));
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group8 SCARD
  * @{
  */
/**
  * @brief  Set UART_SCARD Register
  * @param  rcu RCU Instance
  * @param  scard
  */
__STATIC_INLINE void md_uart_set_scard(UART_TypeDef *UARTx, uint32_t scard)
{
    WRITE_REG(UARTx->SCARD, scard);
}

/**
  * @brief  Get UART_SCARD Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE uint32_t md_uart_get_scard(UART_TypeDef *UARTx)
{
    return (uint32_t)READ_REG(UARTx->SCARD);
}

/**
  * @brief  Set UARTx Block Length (Only UART).
  * @note   This bit-field gives the Block length in Smartcard T=1
  *         Reception. Its value equals the number of information
  *         characters + the length of the Epilogue Field (1-LEC/2-CRC) - 1.
  *         This bit-field can be used also in other modes. In this case, the
  *         Block length counter is reset when RXEN=0 (receiver disabled).
  * @param  UARTx UART Instance.
  * @param  Block Length.
  * @retval None.
  */
__STATIC_INLINE void md_uart_set_rx_data_block_length(UART_TypeDef *UARTx, uint32_t blocklength)
{
    MODIFY_REG(UARTx->SCARD, UART_SCARD_BLEN, blocklength << UART_SCARD_BLEN_POSS);
}

/**
  * @brief  Get UARTx Block Length (Only UART).
  * @param  UARTx UART Instance.
  * @retval Block Length.
  */
__STATIC_INLINE uint32_t md_uart_get_rx_data_block_length(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCARD, UART_SCARD_BLEN) >> UART_SCARD_BLEN_POSS);
}

/**
  * @brief  Set UARTx Guard time value(Only UART).
  * @param  UARTx UART Instance.
  * @param  Guard time value.
  * @retval None.
  */
__STATIC_INLINE void md_uart_set_scard_guardtime(UART_TypeDef *UARTx, uint32_t guardtime)
{
    MODIFY_REG(UARTx->SCARD, UART_SCARD_GT, guardtime << UART_SCARD_GT_POSS);
}

/**
  * @brief  Get UARTx Guard time value(Only UART).
  * @param  UARTx UART Instance.
  * @retval Guard time value.
  */
__STATIC_INLINE uint32_t md_uart_get_scard_guardtime(UART_TypeDef *UARTx)
{
    return (uint32_t)((READ_BIT(UARTx->SCARD, UART_SCARD_GT)) >> UART_SCARD_GT_POSS);
}

/**
  * @brief  Set UARTx Prescaler value (Only UART).
  * @note   In IrDA Low-power and normal IrDA mode:
  *           Used for programming the prescaler for dividing the UART
  *           source clock to achieve the low-power frequency.
  *           The source clock is divided by the value given in the register (8
  *           significant bits)
  *         In Smartcard mode:
  *           Used for programming the prescaler for dividing the UART
  *           source clock to provide the Smartcard clock.
  *           The value given in the register (5 significant bits) is multiplied by
  *           2 to give the division factor of the source clock frequency.
  * @param  UARTx UART Instance.
  * @param  Prescaler value.
            @arg @ref MD_UART_SCARD_IRDA_AND_NORMAL_1_DIVIDE
            @arg @ref MD_UART_SCARD_IRDA_AND_NORMAL_2_DIVIDE
            @arg @ref MD_UART_SCARD_SMART_CARD_2_DIVIDE
            @arg @ref MD_UART_SCARD_SMART_CARD_4_DIVIDE
            @arg @ref MD_UART_SCARD_SMART_CARD_6_DIVIDE
  * @retval None
  */
__STATIC_INLINE void md_uart_set_scard_psc(UART_TypeDef *UARTx, uint32_t prescaler)
{
    MODIFY_REG(UARTx->SCARD, UART_SCARD_PSC, prescaler << UART_SCARD_PSC_POSS);
}

/**
  * @brief  Get UARTx Prescaler value (Only UART).
  * @param  UARTx UART Instance.
  * @retval The retval can be one of the following values:
            @arg @ref MD_UART_SCARD_IRDA_AND_NORMAL_1_DIVIDE
            @arg @ref MD_UART_SCARD_IRDA_AND_NORMAL_2_DIVIDE
            @arg @ref MD_UART_SCARD_SMART_CARD_2_DIVIDE
            @arg @ref MD_UART_SCARD_SMART_CARD_4_DIVIDE
            @arg @ref MD_UART_SCARD_SMART_CARD_6_DIVIDE
  */
__STATIC_INLINE uint32_t md_uart_get_scard_psc(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCARD, UART_SCARD_PSC) >> UART_SCARD_PSC_POSS);
}

/**
  * @brief  Set UARTx Smartcard auto-retry count (Only UART).
  * @note   This bit-field specifies the number of retries in transmit and
  *         receive, in Smartcard mode.
  *         In transmission mode, it specifies the number of automatic
  *         retransmission retries, before generating a transmission error
  *         (FE bit set).
  *         In reception mode, it specifies the number or erroneous
  *         reception trials, before generating a reception error (RXNE and
  *         PE bits set).
  * @param  UARTx UART Instance.
  * @param  smartcard auto-retry count Min_Value=0x00 Max_Value=0x07.
  * @retval None.
  */
__STATIC_INLINE void md_uart_set_scard_sccnt(UART_TypeDef *UARTx, uint32_t count)
{
    MODIFY_REG(UARTx->SCARD, UART_SCARD_SCCNT, count << UART_SCARD_SCCNT_POSS);
}

/**
  * @brief  Get UARTx Smartcard auto-retry count (Only UART).
  * @param  UARTx UART Instance.
  * @retval smartcard auto-retry count Min_Value=0x00 Max_Value=0x07
  */
__STATIC_INLINE uint32_t md_uart_get_scard_sccnt(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCARD, UART_SCARD_SCCNT) >> UART_SCARD_SCCNT_POSS);
}

/**
  * @brief  Smartcard clock enable(Only UART).
  * @note   This bit allows the user to enable the SCK pin.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_scard_sclken(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->SCARD, UART_SCARD_SCLKEN);
}

/**
  * @brief  Smartcard clock disable(Only UART).
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_scard_sclken(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->SCARD, UART_SCARD_SCLKEN);
}

/**
  * @brief  Check if Smartcard clock is enable.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_scard_sclken(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->SCARD, UART_SCARD_SCLKEN) == (UART_SCARD_SCLKEN));
}

/**
  * @brief  Smartcard NACK enable(Only UART).
  * @note   This bit allows the user to enable nack detection.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_scard_nack(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->SCARD, UART_SCARD_SCNACK);
}

/**
  * @brief  Smartcard NACK disable(Only UART).
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_scard_nack(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->SCARD, UART_SCARD_SCNACK);
}

/**
  * @brief  Check if Smartcard NACK is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_scard_nack(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->SCARD, UART_SCARD_SCNACK) == (UART_SCARD_SCNACK));
}

/**
  * @brief  Smartcard mode enable(Only UART).
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_scard_mode(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->SCARD, UART_SCARD_SCEN);
}

/**
  * @brief  Smartcard mode disable(Only UART).
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_scard_mode(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->SCARD, UART_SCARD_SCEN);
}

/**
  * @brief  Check if Smartcard mode is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_scard_mode(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->SCARD, UART_SCARD_SCEN) == (UART_SCARD_SCEN));
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group9 LIN
  * @{
  */
/**
  * @brief  Set UART_LIN Register
  * @param  rcu RCU Instance
  * @param  lin
  */
__STATIC_INLINE void md_uart_set_lin(UART_TypeDef *UARTx, uint32_t lin)
{
    WRITE_REG(UARTx->LIN, lin);
}

/**
  * @brief  Get UART_LIN Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE uint32_t md_uart_get_lin(UART_TypeDef *UARTx)
{
    return (uint32_t)READ_REG(UARTx->LIN);
}

/**
  * @brief  Enable LIN mode break request.
  * @note   This bit is set by software and automatically cleared by
  *         hardware in the next clock cycle.
  *         Writing 1 to this bit sets request to send a BREAK on the line, as
  *         soon as the transmit machine is available.
  *         It generates 13 bits rate low pulse in Lin mode.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_trigger_lin_break_request(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LIN, UART_LIN_LINBKREQ);
}

/**
  * @brief  UARTx LIN mode disconnection word length
  * @param  UARTx UART Instance.
  * @param  linbdl LIN mode disconnection word length
            @arg @ref MD_UART_LIN_LINBDL_10
            @arg @ref MD_UART_LIN_LINBDL_11
  * @retval None.
  */
__STATIC_INLINE void md_uart_set_lin_bk11(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LIN, UART_LIN_LINBDL);
}

__STATIC_INLINE void md_uart_set_lin_bk10(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LIN, UART_LIN_LINBDL);
}

/**
  * @brief  Get LIN mode disconnection word length
  * @param  UARTx UART Instance.
  * @retval The retval can be one of the following values:
            @arg @ref MD_UART_LIN_LINBDL_10
            @arg @ref MD_UART_LIN_LINBDL_11
  */
__STATIC_INLINE uint32_t md_uart_get_lin_break_length(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LIN, UART_LIN_LINBDL) >> UART_LIN_LINBDL_POS);
}

/**
  * @brief  UARTx LIN mode enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_lin_mode(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LIN, UART_LIN_LINEN);
}

/**
  * @brief  UART LIN mode disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_lin_mode(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LIN, UART_LIN_LINEN);
}

/**
  * @brief  Check if UARTx LIN mode is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_lin_mode(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LIN, UART_LIN_LINEN) == (UART_LIN_LINEN));
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group10 RTOR
  * @{
  */
/**
  * @brief  Set UART_RTOR Register
  * @param  rcu RCU Instance
  * @param  rtor
  */
__STATIC_INLINE void md_uart_set_rtor(UART_TypeDef *UARTx, uint32_t rtor)
{
    WRITE_REG(UARTx->RTOR, rtor);
}

/**
  * @brief  Get UART_RTOR Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE uint32_t md_uart_get_rtor(UART_TypeDef *UARTx)
{
    return (uint32_t)READ_REG(UARTx->RTOR);
}

/**
  * @brief  UARTx receive timeout enable.
  * @note   When this feature is enabled, the RTOIF flag in the UART_RIF
  *         register is set if the RX line is idle (no reception) for the duration
  *         programmed in the RTOR (receiver timeout register).
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_rtoen(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->RTOR, UART_RTOR_RTOEN);
}

/**
  * @brief  UARTx receive timeout disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_rtoen(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->RTOR, UART_RTOR_RTOEN);
}

/**
  * @brief  Check if UARTx receive timeout is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_rtoen(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RTOR, UART_RTOR_RTOEN) == (UART_RTOR_RTOEN));
}

/**
  * @brief  Set UARTx receiver timeout value.
  * @note   This bit-field gives the Receiver timeout value in terms of number of bit duration.
  *         In standard mode:
  *           the RTOF flag is set if, after the last received character,
  *           no new start bit is detected for more than the RTO value.
  *         In Smartcard mode:
  *           this value is used to implement the CWT and BWT. See Smartcard section for more details.
  *           In this case, the timeout measurement is done starting from the Stop Bit of the last
  *           received character.
  * @param  UARTx UART Instance.
  * @param  timeout UART timeout value.
  * @retval None.
  */
__STATIC_INLINE void md_uart_set_rec_timeout(UART_TypeDef *UARTx, uint32_t timeout)
{
    MODIFY_REG(UARTx->RTOR, UART_RTOR_RTO, timeout);
}

/**
  * @brief  Get UARTx receiver timeout value.
  * @param  UARTx UART Instance.
  * @retval UART timeout value.
  */
__STATIC_INLINE uint32_t md_uart_get_rec_timeout(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->RTOR, UART_RTOR_RTO));
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group11 STAT
  * @{
  */
/**
  * @brief  Get UART_STAT Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE uint32_t md_uart_get_stat(UART_TypeDef *UARTx)
{
    return READ_REG(UARTx->STAT);
}
/**
  * @brief  Check if Transmit FIFO overrun error.
  * @note   This bit is set and cleared by hardware Tx line start transmit
  *         data. An overrun error occurs when the FIFO is full and a new
  *         character write at the Transmit. The data in the FIFO is retained
  *         and the data in the TXBR register is lost.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_tfoerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_TFOERR) == (UART_STAT_TFOERR));
}

/**
  * @brief  Check if Transmit FIFO empty.
  * @note   This bit is set and cleared by hardware when the TX FIFO is no
  *         longer empty.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_tfempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_TFEMPTY) == (UART_STAT_TFEMPTY));
}

/**
  * @brief  Check if Transmit shift register busy.
  * @note   This bit is cleared by hardware.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_tsbusy(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_TSBUSY) == (UART_STAT_TSBUSY));
}

/**
  * @brief  Check if Receive FIFO underrun error.
  * @note   This bit is set and cleared by hardware when receive a new
  *         data. An underrun error occurs when the FIFO is empty at the
  *         receive. The data in the FIFO is read 0 in the RXBR register.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_rfuerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_RFUERR) == (UART_STAT_RFUERR));
}

/**
  * @brief  Check if Receive FIFO overrun error.
  * @note   This bit is set and cleared by hardware when read data in the
  *         RXBR register. An overrun error occurs when the FIFO is full
  *         and a new character arrives at the receiver. The data in the
  *         FIFO is retained and the data in the RXBR register is lost.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_rfoerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_RFOERR) == (UART_STAT_RFOERR));
}

/**
  * @brief  Check if Receive FIFO not empty.
  * @note   This bit is cleared when the RX FIFO is no longer not empty.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_rfnempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_RFNEMPTY) == (UART_STAT_RFNEMPTY));
}

/**
  * @brief  Check if Receive shiftregister busy.
  * @note   This bit is set and cleared by hardware.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_rsbusy(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_RSBUSY) == (UART_STAT_RSBUSY));
}

/**
  * @brief  Get UARTx Clear to send status.
  * @note   This bit is the complement of CTSn. When CTSn is asserted, it
  *         is an indication that the modem or data set is ready to exchange
  *         data with UART.
  * @param  ADCx ADC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_ctssta(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_CTSSTA) >> UART_STAT_CTSSTA_POS);
}

/**
  * @brief  Check if Break error.
  * @note   This bit is used to indicate the detection of a break sequence on
  *         the serial input data.
  *         This error is associated with the character at the top of the FIFO.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_bkerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_BKERR) == (UART_STAT_BKERR));
}

/**
  * @brief  Check if Framing Error.
  * @note   When the received characters stop bit is a logic 0(i.e. the
  *         receiver did not have a valid stop bit), a framing error occurs.
  *         This error is associated with the character at the top of the FIFO.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_ferr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_FERR) == (UART_STAT_FERR));
}

/**
  * @brief  Check if Parity Error.
  * @note   When the receive character does not have correct parity
  *         information and is suspect, a parity error occurs.
  *         This error is associated with the character at the top of the FIFO.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_perr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_PERR) == (UART_STAT_PERR));
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group12 IER
  * @{
  */
/**
  * @brief  Set UART_IER Register
  * @param  rcu RCU Instance
  * @param  ier
  */
__STATIC_INLINE void md_uart_set_ier(UART_TypeDef *UARTx, uint32_t ier)
{
    WRITE_REG(UARTx->IER, ier);
}

/**
  * @brief  Transmit FIFO overrun interrupt enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_tfoerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_TFOERR);
}

/**
  * @brief  Transmit FIFO empty interrupt enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_tfempty(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_TFEMPTY);
}

/**
  * @brief  Transmission byte complete enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_tbc(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_TBC);
}

/**
  * @brief  Receive FIFO underrun interrupt enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_rfuerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RFUERR);
}

/**
  * @brief  Receive FIFO overrun interrupt enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_rfoerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RFOERR);
}

/**
  * @brief  Receive FIFO not empty interrupt enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_rfnempty(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RFNEMPTY);
}

/**
  * @brief  Bit Noise detection enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_noise(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_NOISE);
}

/**
  * @brief  End of block interrupt enable(Only UART).
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_eob(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_EOB);
}

/**
  * @brief  LINBK: LIN break detection interrupt enable(Only UART).
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_linbk(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_LINBK);
}

/**
  * @brief  Address match interrupt enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_addrm(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_ADDRM);
}

/**
  * @brief  Receiver Timeout interrupt enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_rxto(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RXTO);
}

/**
  * @brief  Delta CTS status interrupt enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_dcts(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_DCTS);
}

/**
  * @brief  Auto-Baud rate detection Timeout interrupt enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_abto(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_ABTO);
}

/**
  * @brief  Auto-Baud rate detection End interrupt enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_abend(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_ABEND);
}

/**
  * @brief  Receiver byte error interrupt enable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_rxberr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RXBERR);
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group13 IDR
  * @{
  */
/**
  * @brief  Set UART_IDR Register
  * @param  rcu RCU Instance
  * @param  idr
  */
__STATIC_INLINE void md_uart_set_idr(UART_TypeDef *UARTx, uint32_t idr)
{
    WRITE_REG(UARTx->IDR, idr);
}
/**
  * @brief  Transmit FIFO overrun interrupt disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_tfoerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_TFOERR);
}

/**
  * @brief  Transmit FIFO empty interrupt disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_tfempty(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_TFEMPTY);
}

/**
  * @brief  Transmission byte complete interrupt disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_tbc(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_TBC);
}

/**
  * @brief  Receive FIFO underrun interrupt disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_rfuerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_RFUERR);
}

/**
  * @brief  Receive FIFO overrun interrupt disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_rfoerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_RFOERR);
}

/**
  * @brief  Receive FIFO not empty interrupt disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_rfnempty(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_RFNEMPTY);
}

/**
  * @brief  Bit Noise detection disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_noise(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_NOISE);
}

/**
  * @brief  End of block interrupt disable(Only UART).
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_eob(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_EOB);
}

/**
  * @brief  LIN break detection interrupt disable(Only UART).
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_linbk(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_LINBK);
}

/**
  * @brief  Address match interrupt disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_addrm(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_ADDRM);
}

/**
  * @brief  Receiver Timeout interrupt disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_rxto(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_RXTO);
}

/**
  * @brief  Delta CTS status interrupt disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_dcts(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_DCTS);
}

/**
  * @brief  Auto-Baud rate detection Timeout interrupt disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_abto(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_ABTO);
}

/**
  * @brief  Auto-Baud rate detection End interrupt disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_abend(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_ABEND);
}

/**
  * @brief  Receiver byte error interrupt disable.
  * @param  UARTx UART Instance.
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_rxberr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_RXBERR);
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group14 IVS
  * @{
  */
/**
  * @brief  Get UART_IVS Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE uint32_t md_uart_get_ivs(UART_TypeDef *UARTx)
{
    return (uint32_t)READ_REG(UARTx->IVS);
}
/**
  * @brief  Check if Tx FIFO overrun interrupt is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_it_tfoerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_TFOERR) == (UART_IVS_TFOERR));
}

/**
  * @brief  Check if Tx FIFO empty interrupt is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_it_tfempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_TFEMPTY) == (UART_IVS_TFEMPTY));
}

/**
  * @brief  Check if Tx complete interrupt is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_it_tbc(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_TBC) == (UART_IVS_TBC));
}

/**
  * @brief  Check if Rx FIFO underrun interrupt is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_it_rfuerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_RFUERR) == (UART_IVS_RFUERR));
}

/**
  * @brief  Check if Rx FIFO overrun interrupt is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_it_rfoerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_RFOERR) == (UART_IVS_RFOERR));
}

/**
  * @brief  Check if Rx FIFO not empty interrupt is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_it_rfnempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_RFNEMPTY) == (UART_IVS_RFNEMPTY));
}

/**
  * @brief  Check if noise detection interrupt is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_it_noise(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_NOISE) == (UART_IVS_NOISE));
}

/**
  * @brief  Check if end of block detection interrupt is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_it_eob(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_EOB) == (UART_IVS_EOB));
}

/**
  * @brief  Check if LIN break detection interrupt is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_it_linbk(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_LINBK) == (UART_IVS_LINBK));
}

/**
  * @brief  Check if address match interrupt is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_it_addrm(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_ADDRM) == (UART_IVS_ADDRM));
}

/**
  * @brief  Check if RX timeout interrupt is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_it_rxto(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_RXTO) == (UART_IVS_RXTO));
}

/**
  * @brief  Check if delta CTS status interrupt is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_it_dcts(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_DCTS) == (UART_IVS_DCTS));
}

/**
  * @brief  Check if auto-baud rate detection interrupt is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_it_abto(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_ABTO) == (UART_IVS_ABTO));
}

/**
  * @brief  Check if auto-baud rate detection end interrupt is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_it_abend(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_ABEND) == (UART_IVS_ABEND));
}

/**
  * @brief  Check if RX byte error interrupt is enabled.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_it_rxberr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_RXBERR) == (UART_IVS_RXBERR));
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group15 RIF
  * @{
  */
/**
  * @brief  Set UART_RIF Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE uint32_t md_uart_get_rif(UART_TypeDef *UARTx)
{
    return (uint32_t)READ_REG(UARTx->RIF);
}
/**
  * @brief  Get Transmit FIFO overrun interrupt flag.
  * @note   This bit is set by hardware when an overrun error occurs that
  *         the FIFO is full and a new character write at the Transmit.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_tfoerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_TFOERR) == (UART_RIF_TFOERR));
}

/**
  * @brief  Get Transmit FIFO empty interrupt flag.
  * @note   This bit is set by hardware when transmit FIFO is empty from
  *         have data to empty.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_tfempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_TFEMPTY) == (UART_RIF_TFEMPTY));
}

/**
  * @brief  Get Transmission byte complete interrupt flag.
  * @note   This bit is set by hardware when transmission byte complete.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_tbc(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_TBC) == (UART_RIF_TBC));
}

/**
  * @brief  Get Receive FIFO underrun interrupt flag
  * @note   This bit is set by hardware when an underrun error occurs that
  *         the FIFO is empty and a new character read at the Receive.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_rfuerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_RFUERR) == (UART_RIF_RFUERR));
}

/**
  * @brief  Get Receive FIFO overrun interrupt flag.
  * @note   This bit is set by hardware when an overrun error occurs that
  *         the FIFO is full and a new character arrive at the Receive.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_rfoerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_RFOERR) == (UART_RIF_RFOERR));
}

/**
  * @brief  Get Receive FIFO not empty interrupt flag.
  * @note   This bit is set by hardware when receive FIFO is full.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_rfnempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_RFNEMPTY) == (UART_RIF_RFNEMPTY));
}

/**
  * @brief  Get Bit Noise detection interrupt flag.
  * @note   This bit is set by hardware when START bit Noise is detected.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_noise(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_NOISE) == (UART_RIF_NOISE));
}

/**
  * @brief  Get End of block interrupt flag(Only UART).
  * @note   This bit is set by hardware when blcok length value equals the
  *         number of data byte.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_eob(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_EOB) == (UART_RIF_EOB));
}

/**
  * @brief  Get LIN break detection interrupt flag(Only UART).
  * @note   This bit is set by hardware when lin break is detected.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_linbk(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_LINBK) == (UART_RIF_LINBK));
}

/**
  * @brief  Get Address match interrupt flag.
  * @note   This bit is set by hardware when the data in the RXBR register
  *         defined by ADD[7:0] in the RS485 register is received.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_addrm(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_ADDRM) == (UART_RIF_ADDRM));
}

/**
  * @brief  Get Receiver Timeout interrupt flag.
  * @note   This bit is set by hardware when the timeout value,
  *         programmed in the RTOR register has lapsed, without any
  *         communication.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_rxto(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_RXTO) == (UART_RIF_RXTO));
}

/**
  * @brief  Get Delta CTS status interrupt flag.
  * @note   This bit is set by hardware when the CTS input toggles.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_dcts(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_DCTS) == (UART_RIF_DCTS));
}

/**
  * @brief  Get Auto-Baud rate detection timeout interrupt flag.
  * @note   This bit is set by hardware when the baud rate detection timeout.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_abto(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_ABTO) == (UART_RIF_ABTO));
}

/**
  * @brief  Get Auto-Baud rate detection end interrupt flag.
  * @note   This bit is set by hardware when the baud rate detection end.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_abend(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_ABEND) == (UART_RIF_ABEND));
}

/**
  * @brief  Get Receiver byte error flag.
  * @note   This bit is set by hardware when a parity error or frame error
  *         occurs in receiver.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_rxberr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_RXBERR) == (UART_RIF_RXBERR));
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group16 IFM
  * @{
  */
/**
  * @brief  Set UART_IFM Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE uint32_t md_uart_get_ifm(UART_TypeDef *UARTx)
{
    return (uint32_t)READ_REG(UARTx->IFM);
}
/**
  * @brief  Get Transmit FIFO overrun interrupt flag masked.
  * @note   This bit is set by hardware when an overrun error occurs that
  *         the FIFO is full and a new character write at the Transmit.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_masked_it_tfoerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_TFOERR) == (UART_IFM_TFOERR));
}

/**
  * @brief  Get Transmit FIFO empty interrupt flag masked.
  * @note   This bit is set by hardware when transmit FIFO is empty from
  *         have data to empty.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_masked_it_tfempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_TFEMPTY) == (UART_IFM_TFEMPTY));
}

/**
  * @brief  Get Transmission byte complete interrupt flag masked.
  * @note   This bit is set by hardware when transmission byte complete.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_masked_it_tbc(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_TBC) == (UART_IFM_TBC));
}

/**
  * @brief  Get Receive FIFO underrun interrupt flag masked.
  * @note   This bit is set by hardware when an underrun error occurs that
  *         the FIFO is empty and a new character read at the Receive.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_masked_it_rfuerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_RFUERR) == (UART_IFM_RFUERR));
}

/**
  * @brief  Get Receive FIFO overrun interrupt flag masked.
  * @note   This bit is set by hardware when an overrun error occurs that
  *         the FIFO is full and a new character arrive at the Receive.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_masked_it_rfoerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_RFOERR) == (UART_IFM_RFOERR));
}

/**
  * @brief  Get Receive FIFO not empty interrupt flag masked.
  * @note   This bit is set by hardware when receive FIFO is full.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_masked_it_rfnempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_RFNEMPTY) == (UART_IFM_RFNEMPTY));
}

/**
  * @brief  Get Bit Noise detection interrupt flag masked.
  * @note   This bit is set by hardware when START bit Noise is detected.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_masked_it_noise(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_NOISE) == (UART_IFM_NOISE));
}

/**
  * @brief  Get End of block interrupt flag masked(Only UART).
  * @note   This bit is set by hardware when block length value equals the
  *         number of data byte.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_masked_it_eob(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_EOB) == (UART_IFM_EOB));
}

/**
  * @brief  Get LIN break detection interrupt flag masked(Only UART).
  * @note   This bit is set by hardware when lin break is detected.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_masked_it_linbk(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_LINBK) == (UART_IFM_LINBK));
}

/**
  * @brief  Get Address match interrupt flag masked.
  * @note   This bit is set by hardware when the data in the RXBR register
  *         defined by ADD[7:0] in the RS485 register is received.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_masked_it_addrm(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_ADDRM) == (UART_IFM_ADDRM));
}

/**
  * @brief  Get Receiver Timeout interrupt flag masked.
  * @note   This bit is set by hardware when the timeout value,
  *         programmed in the RTOR register has lapsed, without any
  *         communication.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_masked_it_rxto(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_RXTO) == (UART_IFM_RXTO));
}

/**
  * @brief  Get Delta CTS status interrupt flag masked.
  * @note   This bit is set by hardware when the CTS input toggles.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_masked_it_dcts(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_DCTS) == (UART_IFM_DCTS));
}

/**
  * @brief  Get Auto-Baud rate detection timeout interrupt flag masked.
  * @note   This bit is set by hardware when the baud rate detection timeout.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_masked_it_abto(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_ABTO) == (UART_IFM_ABTO));
}

/**
  * @brief  Get Auto-Baud rate detection end interrupt flag masked.
  * @note   This bit is set by hardware when the baud rate detection end.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_masked_it_abend(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_ABEND) == (UART_IFM_ABEND));
}

/**
  * @brief  Get Receiver byte error interrupt flag masked.
  * @note   This bit is set by hardware when a parity error, frame error or
  *         break error occurs in receiver.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_masked_it_rxberr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_RXBERR) == (UART_IFM_RXBERR));
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group17 ICR
  * @{
  */
/**
  * @brief  Set UART_ICR Register
  * @param  rcu RCU Instance
  * @param  icr
  */
__STATIC_INLINE void md_uart_set_icr(UART_TypeDef *UARTx, uint32_t icr)
{
    WRITE_REG(UARTx->ICR, icr);
}
/**
  * @brief  Transmit FIFO overrun interrupt flag clear.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_clear_it_tfoerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_TFOERR);
}

/**
  * @brief  Transmit FIFO empty interrupt flag clear.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_clear_it_tfempty(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_TFEMPTY);
}

/**
  * @brief  Transmission byte complete interrupt flag clear.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_clear_it_tbc(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_TBC);
}

/**
  * @brief  Receive FIFO underrun interrupt flag clear.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_clear_it_rfuerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_RFUERR);
}

/**
  * @brief  Receive FIFO overrun interrupt flag clear.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_clear_it_rfoerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_RFOERR);
}

/**
  * @brief  Receive FIFO not empty interrupt flag clear.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_clear_it_rfnempty(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_RFNEMPTY);
}

/**
  * @brief  Bit Noise detection interrupt flag clear.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_clear_it_noise(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_NOISE);
}

/**
  * @brief  End of block interrupt flag clear(Only UART).
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_clear_it_eob(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_EOB);
}

/**
  * @brief  LIN break detection interrupt flag clear(Only UART).
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_clear_it_linbk(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_LINBK);
}

/**
  * @brief  Address match interrupt flag clear.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_clear_it_addrm(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_ADDRM);
}

/**
  * @brief  Receiver Timeout interrupt flag clear.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_clear_it_rxto(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_RXTO);
}

/**
  * @brief  Delta CTS status interrupt flag clear.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_clear_it_dcts(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_DCTS);
}

/**
  * @brief  Auto-Baud rate detection timeout interrupt flag clear.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_clear_it_abto(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_ABTO);
}

/**
  * @brief  Auto-Baud rate detection end interrupt flag clear.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_clear_it_abend(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_ABEND);
}

/**
  * @brief  Receiver byte error interrupt flag clear.
  * @param  UARTx UART Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_uart_clear_it_rxberr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_RXBERR);
}
/**
  * @}
  */

/** @defgroup MD_UART_Public_Functions_Group1 Initialization
  * @{
  */
/* Public functions -----------------------------------------------------------*/
void md_uart_setting_baudrate(UART_TypeDef *UARTx, uint32_t baudrate);
void md_uart_init(UART_TypeDef *UARTx, md_uart_init_typedef *UART_InitStruct);
void md_uart_send(UART_TypeDef *UARTx, uint8_t ch);
void md_uart_send_string(UART_TypeDef *UARTx, uint8_t *data, uint32_t len);
void md_uart_receive_string(UART_TypeDef *UARTx, uint8_t *data, uint32_t len);
uint8_t md_uart_receive(UART_TypeDef *UARTx);
uint32_t md_uart_getting_baudrate(UART_TypeDef *UARTx);
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
