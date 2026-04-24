/**********************************************************************************
 *
 * @file    md_usart.h
 * @brief   Header file of USART module driver.
 *
 * @date    12 July 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          12 July 2022    Lisq            the first version
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


#ifndef __MD_UART_H__
#define __MD_UART_H__

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
/** @defgroup MD_UART UART
  * @brief UART micro driver
  * @{
  */
/**
  * @defgroup MD_UART_Public_Macros UART Public Macros
  * @{
  */

/* Exported Types ------------------------------------------------------------ */

/**
  * @brief  UART mode
  */
typedef enum
{
    MD_UART_MODE       = 0x0U,  /**< UART */
    MD_UART_MODE_IRDA  = 0x1U,  /**< IrDA */
    MD_UART_MODE_LIN   = 0x2U,  /**< LIN */
    MD_UART_MODE_RS485 = 0x3U,  /**< RS485 */
    MD_UART_MODE_HDSEL = 0x4U,  /**< Single-wire half-duplex */
    MD_UART_MODE_SCARD = 0x5U,  /**< Smart card */
} md_uart_mode_t;

/**
  * @brief  UART word length
  */
typedef enum
{
    MD_UART_WORD_LENGTH_5B = 0x3U,  /**< 5-bits */
    MD_UART_WORD_LENGTH_6B = 0x2U,  /**< 6-bits */
    MD_UART_WORD_LENGTH_7B = 0x1U,  /**< 7-bits */
    MD_UART_WORD_LENGTH_8B = 0x0U,  /**< 8-bits */
} md_uart_word_length_t;

/**
  * @brief  UART stop bits
  */
typedef enum
{
    MD_UART_STOP_BITS_1   = 0x0U,   /**< 1-bits */
    MD_UART_STOP_BITS_2   = 0x4U,   /**< 2-bits */
    MD_UART_STOP_BITS_0_5 = 0x0U,   /**< 0.5-bits, using smartcard mode */
    MD_UART_STOP_BITS_1_5 = 0x4U,   /**< 1.5-bits, using smartcard mode */
} md_uart_stop_bits_t;

/**
  * @brief  UART parity
  */
typedef enum
{
    MD_UART_PARITY_NONE  = 0x0U,    /**< Not parity */
    MD_UART_PARITY_ODD   = 0x8U,    /**< Odd parity */
    MD_UART_PARITY_EVEN  = 0x18U,   /**< Even parity */
} md_uart_parity_t;

/**
  * @brief  UART hardware flow control
  */
typedef enum
{
    MD_UART_FLOW_CTL_DISABLE = 0x0U,    /**< Auto-flow-control disable */
    MD_UART_FLOW_CTL_ENABLE  = 0x4U,    /**< Auto-flow-control enable */
} md_uart_flow_ctl_t;

/**
  * @brief Smart_card clock division
  */
typedef enum
{
    MD_SCARD_CLOCK_DIV1 = 0x0U, /**< No prescaler is used */
    MD_SCARD_CLOCK_DIV2 = 0x1U, /** Clock is divided by 2 */
    MD_SCARD_CLOCK_DIV4 = 0x2U, /** Clock is divided by 4 */
    MD_SCARD_CLOCK_DIV6 = 0x3U, /** Clock is divided by 6 */
} md_scard_clk_div_t;

/**
  * @brief Smart_card Rx/Tx handle retry time
  */
typedef enum
{
    MD_SCARD_RETRY_CNT0 = 0x0U, /**< retry time 0 */
    MD_SCARD_RETRY_CNT1 = 0x1U, /**< retry time 1 */
    MD_SCARD_RETRY_CNT2 = 0x2U, /**< retry time 2 */
    MD_SCARD_RETRY_CNT3 = 0x3U, /**< retry time 3 */
    MD_SCARD_RETRY_CNT4 = 0x4U, /**< retry time 4 */
    MD_SCARD_RETRY_CNT5 = 0x5U, /**< retry time 5 */
    MD_SCARD_RETRY_CNT6 = 0x6U, /**< retry time 6 */
    MD_SCARD_RETRY_CNT7 = 0x7U, /**< retry time 7 */
} md_scard_retry_t;

/**
  * @brief LIN detection break length
  */
typedef enum
{
    MD_LIN_BREAK_LEN_10B = 0x0U,    /**< 10-bit break */
    MD_LIN_BREAK_LEN_11B = 0x1U,    /**< 11-bit break */
} md_uart_lin_break_len_t;

/**
  * @brief UART TXFIFO size
  */
typedef enum
{
    MD_UART_TXFIFO_EMPTY = 0x0U,    /**< Empty */
    MD_UART_TXFIFO_2BYTE = 0x1U,    /**< 2-Bytes */
    MD_UART_TXFIFO_4BYTE = 0x2U,    /**< 4-Bytes */
    MD_UART_TXFIFO_8BYTE = 0x3U,    /**< 8-Bytes */
} md_uart_txfifo_t;

/**
  * @brief UART RXFIFO size
  */
typedef enum
{
    MD_UART_RXFIFO_1BYTE  = 0x0U,   /**< 1-Byte */
    MD_UART_RXFIFO_4BYTE  = 0x1U,   /**< 4-Bytes */
    MD_UART_RXFIFO_8BYTE  = 0x2U,   /**< 8-Bytes */
    MD_UART_RXFIFO_14BYTE = 0x3U,   /**< 14-Bytes */
} md_uart_rxfifo_t;

/**
  * @brief UART auto-baud mode
  */
typedef enum
{
    MD_UART_ABRMOD_1_TO_0 = 0x0U,   /**< Detect bit0:1, bit1:0 */
    MD_UART_ABRMOD_1      = 0x1U,   /**< Detect bit0:1 */
    MD_UART_ABRMOD_0_TO_1 = 0x2U,   /**< Detect bit0:0, bit1:1 */
} md_uart_auto_baud_mode_t;

/**
  * @brief UART DMA Requests
  */
typedef enum
{
    MD_UART_DMA_REQ_TX = 0x0U,  /**< TX dma */
    MD_UART_DMA_REQ_RX = 0x1U,  /**< RX dma */
} md_uart_dma_req_t;

/**
  * @brief UART status types
  */
typedef enum
{
    MD_UART_STATUS_PERR    = (1U << 0), /**< Parity error */
    MD_UART_STATUS_FERR    = (1U << 1), /**< Framing error */
    MD_UART_STATUS_BKERR   = (1U << 2), /**< Break error */
    MD_UART_STATUS_CTSSTA  = (1U << 3), /**< Clear to send status */
    MD_UART_STATUS_RSBUSY  = (1U << 8), /**< Receive shif register busy */
    MD_UART_STATUS_RFTH    = (1U << 9), /**< Receive FIFO trigger threshold */
    MD_UART_STATUS_RFEMPTY = (1U << 10),    /**< Receive FIFO empty */
    MD_UART_STATUS_RFFULL  = (1U << 11),    /**< Receive FIFO full */
    MD_UART_STATUS_RFOERR  = (1U << 12),    /**< Reveive FIFO overrun error */
    MD_UART_STATUS_RFUERR  = (1U << 13),    /**< Receive FIFO underrun error */
    MD_UART_STATUS_TSBUSY  = (1U << 14),    /**< Transmit shit register busy */
    MD_UART_STATUS_TFTH    = (1U << 15),    /**< Transmit FIFO trigger threshold */
    MD_UART_STATUS_TFEMPTY = (1U << 16),    /**< Transmit FIFO empty */
    MD_UART_STATUS_TFFULL  = (1U << 17),    /**< Transmit FIFO full */
    MD_UART_STATUS_TFOERR  = (1U << 18),    /**< Transmit FIFO overrun error */
} md_uart_status_t;

/**
  * @brief UART interrupt types
  */
typedef enum
{
    MD_UART_IT_RXBERR  = (1U << 0),     /**< Receiver byte error */
    MD_UART_IT_ABEND   = (1U << 1),     /**< Auto-Baud rate detection end */
    MD_UART_IT_ABTO    = (1U << 2),     /**< Auto-Baud rate detection timeout */
    MD_UART_IT_DCTS    = (1U << 3),     /**< Delta CTS status */
    MD_UART_IT_RXTO    = (1U << 4),     /**< Receiver timeout */
    MD_UART_IT_ADDRM   = (1U << 5),     /**< Addredd match */
    MD_UART_IT_LINBK   = (1U << 6),     /**< Lin break detection */
    MD_UART_IT_EOB     = (1U << 7),     /**< End of block */
    MD_UART_IT_NOISE   = (1U << 8),     /**< Start bit noise detection */
    MD_UART_IT_RFTH    = (1U << 9),     /**< Receive FIFO trigger threshold */
    MD_UART_IT_RFFULL  = (1U << 11),    /**< Receive FIFO full */
    MD_UART_IT_RFOERR  = (1U << 12),    /**< Receive FIFO overrun */
    MD_UART_IT_RFUERR  = (1U << 13),    /**< Reveive FIFO underrun */
    MD_UART_IT_TSEMPTY = (1U << 14),    /**< Transmit shift register empty */
    MD_UART_IT_TFTH    = (1U << 15),    /**< Transmit FIFO trigger threshold */
    MD_UART_IT_TFEMPTY = (1U << 16),    /**< Transmit FIFO empty */
    MD_UART_IT_TFOVER  = (1U << 18),    /**< Transmit FIFO overrun */
} md_uart_it_t;

/**
  * @brief UART flags types
  */
typedef enum
{
    MD_UART_IF_RXBERR  = (1U << 0),     /**< Receiver byte error */
    MD_UART_IF_ABEND   = (1U << 1),     /**< Auto-Baud rate detection end */
    MD_UART_IF_ABTO    = (1U << 2),     /**< Auto-Baud rate detection timeout */
    MD_UART_IF_DCTS    = (1U << 3),     /**< Delta CTS status */
    MD_UART_IF_RXTO    = (1U << 4),     /**< Receiver timeout */
    MD_UART_IF_ADDRM   = (1U << 5),     /**< Addredd match */
    MD_UART_IF_LINBK   = (1U << 6),     /**< Lin break detection */
    MD_UART_IF_EOB     = (1U << 7),     /**< End of block */
    MD_UART_IF_NOISE   = (1U << 8),     /**< Start bit noise detection */
    MD_UART_IF_RFTH    = (1U << 9),     /**< Receive FIFO trigger threshold */
    MD_UART_IF_RFFULL  = (1U << 11),    /**< Receive FIFO full */
    MD_UART_IF_RFOERR  = (1U << 12),    /**< Receive FIFO overrun */
    MD_UART_IF_RFUERR  = (1U << 13),    /**< Reveive FIFO underrun */
    MD_UART_IF_TBC     = (1U << 14),    /**< Transmit shift register empty */
    MD_UART_IF_TFTH    = (1U << 15),    /**< Transmit FIFO trigger threshold */
    MD_UART_IF_TFEMPTY = (1U << 16),    /**< Transmit FIFO empty */
    MD_UART_IF_TFOVER  = (1U << 18),    /**< Transmit FIFO overrun */
} md_uart_flag_t;
/**
  * @}
  */
/**
  * @defgroup MD_UART_Public_Types UART Public Types
  * @{
  */
/**
  * @brief UART init structure definition
  */
typedef struct
{
    uint32_t baud;              /**< Specifies the uart communication baud rate */
    md_uart_word_length_t word_length;  /**< Specifies the number of data bits transmitted or received in a frame */
    md_uart_stop_bits_t stop_bits;      /**< Specifies the number of stop bits transmitted */
    md_uart_parity_t parity;        /**< Specifies the parity mode */
    md_uart_flow_ctl_t fctl;        /**< Specifies wether the hardware flow control mode is enabled or disabled */
    md_uart_mode_t mode;            /**< Specifies the uart mode */
} md_uart_init_t;
/**
  * @}
  */

/* Exported Functions -------------------------------------------------------- */

/** @defgroup MD_UART_Public_Functions UART Public Functions
  * @{
  */
/** @defgroup MD_UART_Public_Functions_Group2 RXBUF
  * @{
  */
/**
  * @brief  Read 8-Bits in the data register
  * @param  UARTx UART Instance
  * @retval Data Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint8_t md_uart_recv_data8(UART_TypeDef *UARTx)
{
    return (uint8_t)(READ_REG(UARTx->RXBUF));
}

/**
  * @brief  Read 9-Bits in the data register
  * @param  UARTx UART Instance
  * @retval Data Value between Min_Data=0x00 and Max_Data=0x1FF
  */
__STATIC_INLINE uint16_t md_uart_recv_data9(UART_TypeDef *UARTx)
{
    return (uint16_t)(READ_REG(UARTx->RXBUF));
}
/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group3 TXBUF
  * @{
  */
/**
  * @brief  Write data in the data register
  * @param  UARTx UART Instance
  * @param  data Value between Min_Data=0x00 and Max_Data=0x1FF
  * @retval None
  */
__STATIC_INLINE void md_uart_set_send_data9(UART_TypeDef *UARTx, uint16_t data)
{
	WRITE_REG(UARTx->TXBUF, data);
}

/**
  * @brief  Write data in the data register
  * @param  UARTx UART Instance
  * @param  data Value between Min_Data=0x00 and Max_Data=0xFF
  * @retval None
  */
__STATIC_INLINE void md_uart_set_send_data8(UART_TypeDef *UARTx, uint8_t data)
{
    WRITE_REG(UARTx->TXBUF, data);
}

/**
  * @brief  Read 8-Bits in the tx data register
  * @param  UARTx UART Instance
  * @retval Data Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint8_t md_uart_get_send_data8(UART_TypeDef *UARTx)
{
    return (uint8_t)(READ_REG(UARTx->TXBUF));
}

/**
  * @brief  Read 9-Bits in the tx data register
  * @param  UARTx UART Instance
  * @retval Data Value between Min_Data=0x00 and Max_Data=0x1FF
  */
__STATIC_INLINE uint16_t md_uart_get_send_data9(UART_TypeDef *UARTx)
{
    return (uint16_t)(READ_REG(UARTx->TXBUF));
}
/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group4 BRR
  * @{
  */
/**
  * @brief  Set UART baud rate
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @param  buadrate UART buad rate value
  * @retval None
  */
__STATIC_INLINE void md_uart_set_baudrate(UART_TypeDef *UARTx, uint32_t buadrate)
{
    WRITE_REG(UARTx->BRR, buadrate);
}

/**
  * @brief  Get UART baud rate
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval buadrate UART buad rate value
  */
__STATIC_INLINE uint32_t md_uart_get_baudrate(UART_TypeDef *UARTx)
{
    return (READ_REG(UARTx->BRR));
}
/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group5 LCON
  * @{
  */
/**
  * @brief  UART Tx Enable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_tx(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_TXEN_MSK);
}

/**
  * @brief  UART Tx Disable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_tx(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_TXEN_MSK);
}

/**
  * @brief  Indicate if UART Tx is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_tx(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_TXEN_MSK) == (UART_LCON_TXEN_MSK));
}

/**
  * @brief  UART Rx Enable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_rx(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_RXEN_MSK);
}

/**
  * @brief  UART Rx Disable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_rx(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_RXEN_MSK);
}

/**
  * @brief  Indicate if UART Rx is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_rx(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_RXEN_MSK) == (UART_LCON_RXEN_MSK));
}

/**
  * @brief  UART Rx filter Enable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_dbcen(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_DBCEN_MSK);
}

/**
  * @brief  UART Rx filter Disable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_dbcen(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_DBCEN_MSK);
}

/**
  * @brief  Indicate if UART Rx filter is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_dbcen(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_DBCEN_MSK) == (UART_LCON_DBCEN_MSK));
}

/**
  * @brief  UART Break Enable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_break(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_BREAK_MSK);
}

/**
  * @brief  UART Break Disable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_break(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_BREAK_MSK);
}

/**
  * @brief  Indicate if UART break is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_break(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_BREAK_MSK) == (UART_LCON_BREAK_MSK));
}

/**
  * @brief  Enable UART swap TX/RX pins
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_swap(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_SWAP_MSK);
}

/**
  * @brief  Disable UART swap TX/RX pins
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_swap(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_SWAP_MSK);
}

/**
  * @brief  Indicate if UART TX/RX pins is swaped
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_swap(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_SWAP_MSK) == (UART_LCON_SWAP_MSK));
}

/**
  * @brief  Enable UART TX pin active level inversion
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_txinv(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_TXINV_MSK);
}

/**
  * @brief  Disable UART TX pin active level inversion
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_txinv(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_TXINV_MSK);
}

/**
  * @brief  Indicate if UART TX pin active level is invered
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_txinv(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LCON, UART_LCON_TXINV_MSK) == (UART_LCON_TXINV_MSK));
}

/**
  * @brief  Enable UART RX pin active level inversion
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_rxinv(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_RXINV_MSK);
}

/**
  * @brief  Disable UART RX pin active level inversion
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_rxinv(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_RXINV_MSK);
}

/**
  * @brief  Indicate if UART RX pin active level is invered
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_rxinv(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LCON, UART_LCON_RXINV_MSK) == (UART_LCON_RXINV_MSK));
}

/**
  * @brief  Enable UART Binary data inversion
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_datainv(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_DATAINV_MSK);
}

/**
  * @brief  Disable UART Binary data inversion
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_datainv(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_DATAINV_MSK);
}

/**
  * @brief  Indicate if UART Binary data is invered
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_datainv(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LCON, UART_LCON_DATAINV_MSK) == (UART_LCON_DATAINV_MSK));
}

/**
  * @brief  Set UART Binary data bit order LSB first
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_set_bitorder_lsb(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LCON, UART_LCON_MSB_MSK);
}

/**
  * @brief  Set UART Binary data bit order MSB first
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_set_bitorder_msb(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LCON, UART_LCON_MSB_MSK);
}

/**
  * @brief  Get UART Binary data bit order
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval The retval:
  *         - 0: LSB first
  *         - 0: MSB first
  */
__STATIC_INLINE uint32_t md_uart_get_bitorder(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_MSB_MSK) == (UART_LCON_MSB_MSK));
}

/**
  * @brief  Set UART data parity
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @param  parity This parameter can be one of the following values:
  *         @arg @ref MD_UART_PARITY_NONE
  *         @arg @ref MD_UART_PARITY_ODD
  *         @arg @ref MD_UART_PARITY_EVEN
  * @retval None
  */
__STATIC_INLINE void md_uart_set_parity(UART_TypeDef *UARTx, uint32_t parity)
{
    MODIFY_REG(UARTx->LCON, UART_LCON_PE_MSK | UART_LCON_PS_MSK, parity);
}

/**
  * @brief  Get UART data parity
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_UART_PARITY_NONE
  *         @arg @ref MD_UART_PARITY_ODD
  *         @arg @ref MD_UART_PARITY_EVEN
  */
__STATIC_INLINE uint32_t md_uart_get_parity(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_PE_MSK | UART_LCON_PS_MSK));
}

/**
  * @brief  Set UART data stop bit
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @param  stop This parameter can be one of the following values:
  *         @arg @ref MD_UART_STOP_BITS_1
  *         @arg @ref MD_UART_STOP_BITS_2
  * @retval None
  */
__STATIC_INLINE void md_uart_set_stop(UART_TypeDef *UARTx, uint32_t stop)
{
    MODIFY_REG(UARTx->LCON, UART_LCON_STOP_MSK, stop);
}

/**
  * @brief  Get UART data stop bit
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_UART_STOP_BITS_1
  *         @arg @ref MD_UART_STOP_BITS_2
  */
__STATIC_INLINE uint32_t md_uart_get_stop(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_STOP_MSK));
}


/**
  * @brief  Set UART data width
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @param  width This parameter can be one of the following values:
  *         @arg @ref MD_UART_WORD_LENGTH_5B
  *         @arg @ref MD_UART_WORD_LENGTH_6B
  *         @arg @ref MD_UART_WORD_LENGTH_7B
  *         @arg @ref MD_UART_WORD_LENGTH_8B
  * @retval None
  */
__STATIC_INLINE void md_uart_set_datawidth(UART_TypeDef *UARTx, uint32_t width)
{
    MODIFY_REG(UARTx->LCON, UART_LCON_DLS_MSK, width);
}

/**
  * @brief  Get UART data width
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_UART_WORD_LENGTH_5B
  *         @arg @ref MD_UART_WORD_LENGTH_6B
  *         @arg @ref MD_UART_WORD_LENGTH_7B
  *         @arg @ref MD_UART_WORD_LENGTH_8B
  */
__STATIC_INLINE uint32_t md_uart_get_datawidth(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->LCON, UART_LCON_DLS_MSK));
}
/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group6 MCON
  * @{
  */

/**
  * @brief  Enable TXFLOAT
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_txfloat(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_TXFLOAT_MSK);
}

/**
  * @brief  Disable TXFLOAT
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_txfloat(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_TXFLOAT_MSK);
}

/**
  * @brief  Check if TXFLOAT is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_txfloat(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->MCON, UART_MCON_TXFLOAT_MSK) == (UART_MCON_TXFLOAT_MSK));
}

/**
  * @brief  Enable TXDMA request
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_txdma(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_TXDMAEN_MSK);
}

/**
  * @brief  Disable TXDMA request
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_txdma(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_TXDMAEN_MSK);
}

/**
  * @brief  Check if TXDMA request is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_txdma(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->MCON, UART_MCON_TXDMAEN_MSK) == (UART_MCON_TXDMAEN_MSK));
}

/**
  * @brief  Enable RXDMA request
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_rxdma(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_RXDMAEN_MSK);
}

/**
  * @brief  Disable RXDMA request
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_rxdma(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_RXDMAEN_MSK);
}

/**
  * @brief  Check if RXDMA request is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_rxdma(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->MCON, UART_MCON_RXDMAEN_MSK) == (UART_MCON_RXDMAEN_MSK));
}

/**
  * @brief  UART auto baud rate detection repeat Enable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_abrrept(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_ABRREPT_MSK);
}

/**
  * @brief  UART auto baud rate detection repeat Disable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_abrrept(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_ABRREPT_MSK);
}

/**
  * @brief  Indicate if UART auto baud rate detection repeat is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_abrrept(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->MCON, UART_MCON_ABRREPT_MSK) == (UART_MCON_ABRREPT_MSK));
}

/**
  * @brief  Set UART auto baud-rate mode
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @param  mode This parameter can be one of the following values:
  *         - 0: MODE0
  *         - 1: MODE1
  *         - 2: MODE2
  * @retval None
  */
__STATIC_INLINE void md_uart_set_abrmod(UART_TypeDef *UARTx, uint32_t mode)
{
    MODIFY_REG(UARTx->MCON, UART_MCON_ABRMOD_MSK, mode << UART_MCON_ABRMOD_POSS);
}

/**
  * @brief  Get UART auto baud-rate mode
  * @note   This bit can only be written when UART is disabled(TXEN and RXEN=0)
  * @param  UARTx UART Instance
  * @retval The retval can be one of the following values:
  *         - 0: MODE0
  *         - 1: MODE1
  *         - 2: MODE2
  */
__STATIC_INLINE uint32_t md_uart_get_abrmod(UART_TypeDef *UARTx)
{
    return READ_BITS(UARTx->MCON, UART_MCON_ABRMOD_MSK, UART_MCON_ABRMOD_POSS);
}

/**
  * @brief  Enable auto-baud
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_abr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_ABREN_MSK);
}

/**
  * @brief  Disable auto-baud
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_abr(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_ABREN_MSK);
}

/**
  * @brief  Indicate if auto-baud  is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_abr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->MCON, UART_MCON_ABREN_MSK) == (UART_MCON_ABREN_MSK));
}

/**
  * @brief  Send UART LIN mode break request
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_trigger_break_request(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_BKREQ_MSK);
}

/**
  * @brief  UART half-duplex Enable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_half_duplex(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_HDEN_MSK);
}

/**
  * @brief  UART half-duplex Disable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_half_duplex(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_HDEN_MSK);
}

/**
  * @brief  Indicate if UART half-duplex is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_half_duplex(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->MCON, UART_MCON_HDEN_MSK) == (UART_MCON_HDEN_MSK));
}

/**
  * @brief  UART Irda Enable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_irda(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_IREN_MSK);
}

/**
  * @brief  UART Irda Disable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_irda(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_IREN_MSK);
}

/**
  * @brief  Indicate if UART Irda is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_irda(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->MCON, UART_MCON_IREN_MSK) == (UART_MCON_IREN_MSK));
}

/**
  * @brief  UART auto flow control Enable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_auto_flow(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_AFCEN_MSK);
}

/**
  * @brief  UART auto flow control Disable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_auto_flow(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_AFCEN_MSK);
}

/**
  * @brief  Indicate if UART auto flow control is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_auto_flow(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->MCON, UART_MCON_AFCEN_MSK) == (UART_MCON_AFCEN_MSK));
}

/**
  * @brief  Set UART RTSn pin level
  * @note   This bit is set and cleared by software when auto flow disabled
  * @param  UARTx UART Instance
  * @param  level This parameter can be one of the following values:
  *         - 1: Low level
  *         - 0: High level
  * @retval None
  */
__STATIC_INLINE void md_uart_set_rtsset(UART_TypeDef *UARTx, uint32_t level)
{
    MODIFY_REG(UARTx->MCON, UART_MCON_RTSSET_MSK, level << UART_MCON_RTSSET_POS);
}

/**
  * @brief  Get UART RTSn pin level
  * @param  UARTx UART Instance
  * @retval The retval can be one of the following values:
  *         - 0: Low level
  *         - 1: High level
  */
__STATIC_INLINE uint32_t md_uart_get_rtsset(UART_TypeDef *UARTx)
{
    return READ_BITS(UARTx->MCON, UART_MCON_RTSSET_MSK, UART_MCON_RTSSET_POS);
}

/**
  * @brief  UART loopback mode Enable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_loopback(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->MCON, UART_MCON_LPBKEN_MSK);
}

/**
  * @brief  UART loopback mode Disable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_loopback(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->MCON, UART_MCON_LPBKEN_MSK);
}

/**
  * @brief  Indicate if UART loopback mode is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_loopback(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->MCON, UART_MCON_LPBKEN_MSK) == (UART_MCON_LPBKEN_MSK));
}
/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group7 RS485
  * @{
  */
/**
  * @brief  Set UART direction control RTSn delay value
  * @param  UARTx UART Instance
  * @param  delay UART direction control RTSn delay value
  * @retval None
  */
__STATIC_INLINE void md_uart_set_rs485_dly(UART_TypeDef *UARTx, uint32_t delay)
{
    MODIFY_REG(UARTx->RS485, UART_RS485_DLY_MSK, delay << UART_RS485_DLY_POSS);
}

/**
  * @brief  Get UART direction control RTSn delay value
  * @param  UARTx UART Instance
  * @retval UART delay value
  */
__STATIC_INLINE uint32_t md_uart_get_rs485_dly(UART_TypeDef *UARTx)
{
    return READ_BITS(UARTx->RS485, UART_RS485_DLY_MSK, UART_RS485_DLY_POSS);
}

/**
  * @brief  Set UART RS485 address value
  * @param  UARTx UART Instance
  * @param  address UART match address value
  * @retval None
  */
__STATIC_INLINE void md_uart_set_rs485_addr(UART_TypeDef *UARTx, uint32_t address)
{
    MODIFY_REG(UARTx->RS485, UART_RS485_ADDR_MSK, address << UART_RS485_ADDR_POSS);
}

/**
  * @brief  Get UART RS485 address value
  * @param  UARTx UART Instance
  * @retval UART match address value
  */
__STATIC_INLINE uint32_t md_uart_get_rs485_addr(UART_TypeDef *UARTx)
{
    return (READ_BITS(UARTx->RS485, UART_RS485_ADDR_MSK, UART_RS485_ADDR_POSS));
}

/**
  * @brief  Set UART RS485 automatic address detection invertion
  * @param  UARTx UART Instance
  * @param  aadinv can be one of the following value:
  *         - 0: Low
  *         - 0: High
  * @retval None
  */
__STATIC_INLINE void md_uart_set_rs485_auto_addr_invert(UART_TypeDef *UARTx, uint32_t aadinv)
{
    MODIFY_REG(UARTx->RS485, UART_RS485_AADINV_MSK, aadinv << UART_RS485_AADINV_POS);
}

/**
  * @brief  Get UART RS485 automatic address detection invertion
  * @param  UARTx UART Instance
  * @retval The status.
  */
__STATIC_INLINE uint32_t md_uart_get_rs485_auto_addr_invert(UART_TypeDef *UARTx)
{
    return READ_BITS(UARTx->RS485, UART_RS485_AADINV_MSK, UART_RS485_AADINV_POS);
}

/**
  * @brief  UART auto direction mode Enable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_auto_dir_mode(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->RS485, UART_RS485_AADACEN_MSK);
}

/**
  * @brief  UART auto direction mode Disable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_auto_dir_mode(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->RS485, UART_RS485_AADACEN_MSK);
}

/**
  * @brief  Indicate if auto direction mode is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_auto_dir_mode(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->RS485, UART_RS485_AADACEN_MSK) == (UART_RS485_AADACEN_MSK));
}

/**
  * @brief  UART auto address detection normal mode Enable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_autoaddr_normal_mode(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->RS485, UART_RS485_AADNEN_MSK);
}

/**
  * @brief  UART auto address detection normal mode Disable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_autoaddr_normal_mode(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->RS485, UART_RS485_AADNEN_MSK);
}

/**
  * @brief  Indicate if auto address detection normal mode is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_autoaddr_normal_mode(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->RS485, UART_RS485_AADNEN_MSK) == (UART_RS485_AADNEN_MSK));
}

/**
  * @brief  UART auto bit_addr detect Enable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_aaden(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->RS485, UART_RS485_AADEN_MSK);
}

/**
  * @brief  UART auto bit_addr detect Disable
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_aaden(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->RS485, UART_RS485_AADEN_MSK);
}

/**
  * @brief  Indicate if auto bit_addr detect is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_aaden(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->RS485, UART_RS485_AADEN_MSK) == (UART_RS485_AADEN_MSK));
}
/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group8 SCARD
  * @{
  */
/**
  * @brief  Set UART receive data block length.
  * @param  UARTx UART Instance
  * @param  len length of data block
  * @retval None
  */
__STATIC_INLINE void md_uart_set_rx_data_block_length(UART_TypeDef *UARTx, uint32_t len)
{
    MODIFY_REG(UARTx->SCARD, UART_SCARD_BLEN_MSK, len << UART_SCARD_BLEN_POSS);
}

/**
  * @brief  Get UART receive data block length.
  * @param  UARTx UART Instance
  * @retval length of receive data block
  */
__STATIC_INLINE uint32_t md_uart_get_rx_data_block_length(UART_TypeDef *UARTx)
{
    return READ_BITS(UARTx->SCARD, UART_SCARD_BLEN_MSK, UART_SCARD_BLEN_POSS);
}

/**
  * @brief  Set UART Smartcard protect time.
  * @param  UARTx UART Instance
  * @param  tim time of Smartcard protect time.
  * @retval None
  */
__STATIC_INLINE void md_uart_set_scard_gt(UART_TypeDef *UARTx, uint32_t tim)
{
    MODIFY_REG(UARTx->SCARD, UART_SCARD_GT_MSK, tim << UART_SCARD_GT_POSS);
}

/**
  * @brief  Get UART Smartcard protect time.
  * @param  UARTx UART Instance
  * @retval Smartcard protect time
  */
__STATIC_INLINE uint32_t md_uart_get_scard_gt(UART_TypeDef *UARTx)
{
    return READ_BITS(UARTx->SCARD, UART_SCARD_GT_MSK, UART_SCARD_GT_POSS);
}

/**
  * @brief  Set UART Smartcard prescaler clock.
  * @param  UARTx UART Instance
  * @param  pre prescaler clock value.
  * @retval None
  */
__STATIC_INLINE void md_uart_set_scard_psc(UART_TypeDef *UARTx, uint32_t pre)
{
    MODIFY_REG(UARTx->SCARD, UART_SCARD_PSC_MSK, pre << UART_SCARD_PSC_POSS);
}

/**
  * @brief  Get UART Smartcard protect time.
  * @param  UARTx UART Instance
  * @retval Smartcard protect time
  */
__STATIC_INLINE uint32_t md_uart_get_scard_sccnt(UART_TypeDef *UARTx)
{
    return READ_BITS(UARTx->SCARD, UART_SCARD_PSC_MSK, UART_SCARD_PSC_POSS);
}

/**
  * @brief  Set UART Smartcard repetition transmit frequency.
  * @param  UARTx UART Instance
  * @param  num repetition frequency.
  * @retval None
  */
__STATIC_INLINE void md_uart_set_scard_sccnt(UART_TypeDef *UARTx, uint32_t num)
{
    MODIFY_REG(UARTx->SCARD, UART_SCARD_SCCNT_MSK, num << UART_SCARD_SCCNT_POSS);
}

/**
  * @brief  Get UART Smartcard repetition transmit frequency.
  * @param  UARTx UART Instance
  * @retval Smartcard repetition transmit frequency.
  */
__STATIC_INLINE uint32_t md_uart_get_scard_psc(UART_TypeDef *UARTx)
{
    return READ_BITS(UARTx->SCARD, UART_SCARD_SCCNT_MSK, UART_SCARD_SCCNT_POSS);
}

/**
  * @brief  Enable UART Smartcard clock.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_scard_sclken(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->SCARD, UART_SCARD_SCLKEN_MSK);
}

/**
  * @brief  Disable UART Smartcard clock.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_scard_sclken(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->SCARD, UART_SCARD_SCLKEN_MSK);
}

/**
  * @brief  Indicate if Smartcard clock is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_scard_sclken(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCARD, UART_SCARD_SCLKEN_MSK) == (UART_SCARD_SCLKEN_MSK));
}

/**
  * @brief  Enable UART Smartcard nack.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_scard_nack(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->SCARD, UART_SCARD_SCNACK_MSK);
}

/**
  * @brief  Disable UART Smartcard nack.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_scard_nack(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->SCARD, UART_SCARD_SCNACK_MSK);
}

/**
  * @brief  Indicate if Smartcard nack is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_scard_nack(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCARD, UART_SCARD_SCNACK_MSK) == (UART_SCARD_SCNACK_MSK));
}

/**
  * @brief  Enable UART Smartcard mode.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_scard_mode(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->SCARD, UART_SCARD_SCEN_MSK);
}

/**
  * @brief  Disable UART Smartcard mode.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_scard_mode(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->SCARD, UART_SCARD_SCEN_MSK);
}

/**
  * @brief  Indicate if Smartcard mode is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_scard_mode(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCARD, UART_SCARD_SCEN_MSK) == (UART_SCARD_SCEN_MSK));
}
/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group9 LIN
  * @{
  */
/**
  * @brief  Enable UART LIN break request.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_lin_bkreq(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LIN, UART_LIN_LINBKREQ_MSK);
}

/**
  * @brief  Disable UART LIN break request.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_lin_bkreq(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LIN, UART_LIN_LINBKREQ_MSK);
}

/**
  * @brief  Set UART LIN break 11 bit length.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_set_lin_bk11(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LIN, UART_LIN_LINBDL_MSK);
}

/**
  * @brief  Set UART LIN break 10 bit length.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_set_lin_bk10(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LIN, UART_LIN_LINBDL_MSK);
}

/**
  * @brief  Indicate the length of LIN break
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  *     - 0: 10bit
  *     - 1: 11bit
  */
__STATIC_INLINE uint32_t md_uart_get_lin_break_length(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LIN, UART_LIN_LINBDL_MSK));
}

/**
  * @brief  Enable UART LIN mode.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_lin_mode(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->LIN, UART_LIN_LINEN_MSK);
}

/**
  * @brief  Disable UART LIN mode.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_lin_mode(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->LIN, UART_LIN_LINEN_MSK);
}

/**
  * @brief  Indicate if UART LIN mode is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_lin_mode(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LIN, UART_LIN_LINEN_MSK) == (UART_LIN_LINEN_MSK));
}
/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group10 RTOR
  * @{
  */
/**
  * @brief  Enable UART rx timeout.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_enable_rtoen(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->RTOR, UART_RTOR_RTOEN_MSK);
}

/**
  * @brief  Disable UART rx timeout.
  * @param  UARTx UART Instance
  * @retval None
  */
__STATIC_INLINE void md_uart_disable_rtoen(UART_TypeDef *UARTx)
{
    CLEAR_BIT(UARTx->RTOR, UART_RTOR_RTOEN_MSK);
}

/**
  * @brief  Indicate if rx timeout is enabled
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enabled_rtoen(UART_TypeDef *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->RTOR, UART_RTOR_RTOEN_MSK) == (UART_RTOR_RTOEN_MSK));
}

/**
  * @brief  Set UART receiver timeout value and enable receiver timeout
  * @param  UARTx UART Instance
  * @param  timeout UART timeout value
  * @retval None
  */
__STATIC_INLINE void md_uart_set_rec_timeout(UART_TypeDef *UARTx, uint32_t timeout)
{
    MODIFY_REG(UARTx->RTOR, UART_RTOR_RTO_MSK, timeout);
}

/**
  * @brief  Get UART receiver timeout value
  * @param  UARTx UART Instance
  * @retval UART timeout value
  */
__STATIC_INLINE uint32_t md_uart_get_rec_timeout(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RTOR, UART_RTOR_RTO_MSK));
}

/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group12 STAT
  * @{
  */
/**
  * @brief  Get UART Tx FIFO overflow state
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_tfoerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_TFOERR_MSK) == (UART_STAT_TFOERR_MSK));
}

/**
  * @brief  Get UART Tx FIFO empty state
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_tfempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_TFEMPTY_MSK) == (UART_STAT_TFEMPTY_MSK));
}

/**
  * @brief  Get UART Tx shifting register busy state
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_tsbusy(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_TSBUSY_MSK) == (UART_STAT_TSBUSY_MSK));
}

/**
  * @brief  Get UART Rx underflow error state
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_rfuerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_RFUERR_MSK) == (UART_STAT_RFUERR_MSK));
}

/**
  * @brief  Get UART Rx overflow error state
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_rfoerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_RFOERR_MSK) == (UART_STAT_RFOERR_MSK));
}

/**
  * @brief  Get UART Rx fifo not empty state
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_rfnempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_RFNEMPTY_MSK) == (UART_STAT_RFNEMPTY_MSK));
}

/**
  * @brief  Get UART Rx shifting register busy state
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_rsbusy(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_RSBUSY_MSK) == (UART_STAT_RSBUSY_MSK));
}

/**
  * @brief  Get UART CTSn state
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_ctssta(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_CTSSTA_MSK) == (UART_STAT_CTSSTA_MSK));
}

/**
  * @brief  Get UART break error state
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_bkerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_BKERR_MSK) == (UART_STAT_BKERR_MSK));
}

/**
  * @brief  Get UART frame error state
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_ferr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_FERR_MSK) == (UART_STAT_FERR_MSK));
}

/**
  * @brief  Get UART verify error state
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_perr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->STAT, UART_STAT_PERR_MSK) == (UART_STAT_PERR_MSK));
}
/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group13 IER
  * @{
  */
/**
  * @brief  Enable UART tx fifo overflow interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_tfoerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_TFOERR_MSK);
}

/**
  * @brief  Enable UART tx fifo empty interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_tfempty(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_TFEMPTY_MSK);
}

/**
  * @brief  Enable UART tx fifo transmit complete interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_tbc(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_TBC_MSK);
}

/**
  * @brief  Enable UART rx fifo underflow interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_rfuerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RFUERR_MSK);
}

/**
  * @brief  Enable UART rx fifo overflow interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_rfoerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RFOERR_MSK);
}

/**
  * @brief  Enable UART rx not empty interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_rfnempty(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RFNEMPTY_MSK);
}

/**
  * @brief  Enable UART noise interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_noise(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_NOISE_MSK);
}

/**
  * @brief  Enable UART block end interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_eob(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_EOB_MSK);
}

/**
  * @brief  Enable UART link break interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_linbk(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_LINBK_MSK);
}

/**
  * @brief  Enable UART address match interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_addrm(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_ADDRM_MSK);
}

/**
  * @brief  Enable UART receive timeout interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_rxto(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RXTO_MSK);
}

/**
  * @brief  Enable UART CTSn change interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_dcts(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_DCTS_MSK);
}

/**
  * @brief  Enable UART auto-baud detection timeout interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_abto(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_ABTO_MSK);
}

/**
  * @brief  Enable UART auto-baud detection end interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_abend(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_ABEND_MSK);
}

/**
  * @brief  Enable UART rx format error interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_enable_it_rxberr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RXBERR_MSK);
}
/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group14 IDR
  * @{
  */
/**
  * @brief  Disable UART tx fifo overflow interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_tfover(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_TFOVER_MSK);
}

/**
  * @brief  Disable UART tx fifo empty interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_tfempty(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_TFEMPTY_MSK);
}

/**
  * @brief  Disable UART tx fifo transmit complete interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_tbc(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_TBC_MSK);
}

/**
  * @brief  Disable UART rx fifo underflow interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_rfuerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_RFUERR_MSK);
}

/**
  * @brief  Disable UART rx fifo overflow interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_rfoerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_RFOERR_MSK);
}

/**
  * @brief  Disable UART rx not empty interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_rfnempty(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_RFNEMPTY_MSK);
}

/**
  * @brief  Disable UART rx fifo noise interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_noise(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_NOISE_MSK);
}

/**
  * @brief  Disable UART block end interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_eob(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_EOB_MSK);
}

/**
  * @brief  Disable UART link break interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_linbk(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_LINBK_MSK);
}

/**
  * @brief  Disable UART address match interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_addrm(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_ADDRM_MSK);
}

/**
  * @brief  Disable UART receive timeout interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_rxto(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_RXTO_MSK);
}

/**
  * @brief  Disable UART CTSn change interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_dcts(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_DCTS_MSK);
}

/**
  * @brief  Disable UART auto-baud detection timeout interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_abto(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_ABTO_MSK);
}

/**
  * @brief  Disable UART auto-baud detection end interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_abend(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_ABEND_MSK);
}

/**
  * @brief  Disable UART rx format error interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_disable_it_rxberr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->IDR, UART_IDR_RXBERR_MSK);
}
/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group15 IVS
  * @{
  */
/**
  * @brief  Check if is enable tx fifo overflow interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enable_it_tfover(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_TFOVER_MSK) == (UART_IVS_TFOVER_MSK));
}

/**
  * @brief  Check if is enable tx fifo empty interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enable_it_tfempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_TFEMPTY_MSK) == (UART_IVS_TFEMPTY_MSK));
}

/**
  * @brief  Check if is enable tx fifo transmit complete interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enable_it_tbc(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_TBC_MSK) == (UART_IVS_TBC_MSK));
}

/**
  * @brief  Check if is enable rx fifo underflow interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enable_it_rfuerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_RFUERR_MSK) == (UART_IVS_RFUERR_MSK));
}

/**
  * @brief  Check if is enable rx fifo overflow interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enable_it_rfoerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_RFOERR_MSK) == (UART_IVS_RFOERR_MSK));
}

/**
  * @brief  Check if is enable rx not empty interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enable_it_rfnempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_RFNEMPTY_MSK) == (UART_IVS_RFNEMPTY_MSK));
}

/**
  * @brief  Check if is enable rx noise threshold interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enable_it_noise(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_NOISE_MSK) == (UART_IVS_NOISE_MSK));
}

/**
  * @brief  Check if is enable block end interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enable_it_eob(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_EOB_MSK) == (UART_IVS_EOB_MSK));
}

/**
  * @brief  Check if is enable link break interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enable_it_linbk(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_LINBK_MSK) == (UART_IVS_LINBK_MSK));
}

/**
  * @brief  Check if is enable address match interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enable_it_addrm(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_ADDRM_MSK) == (UART_IVS_ADDRM_MSK));
}

/**
  * @brief  Check if is enable receive timeout interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enable_it_rxto(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_RXTO_MSK) == (UART_IVS_RXTO_MSK));
}

/**
  * @brief  Check if is enable CTSn change interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enable_it_dcts(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_DCTS_MSK) == (UART_IVS_DCTS_MSK));
}

/**
  * @brief  Check if is enable auto-baud detection timeout interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enable_it_abto(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_ABTO_MSK) == (UART_IVS_ABTO_MSK));
}

/**
  * @brief  Check if is enable auto-baud detection end interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enable_it_abend(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_ABEND_MSK) == (UART_IVS_ABEND_MSK));
}

/**
  * @brief  Check if is enable rx format error interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_enable_it_rxberr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IVS, UART_IVS_RXBERR_MSK) == (UART_IVS_RXBERR_MSK));
}
/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group16 RIF
  * @{
  */
/**
  * @brief  Check if is active tx fifo overflow interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_tfover(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_TFOVER_MSK) == (UART_RIF_TFOVER_MSK));
}

/**
  * @brief  Check if is active tx fifo empty interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_tfempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_TFEMPTY_MSK) == (UART_RIF_TFEMPTY_MSK));
}

/**
  * @brief  Check if is active tx fifo transmit complete interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_tbc(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_TBC_MSK) == (UART_RIF_TBC_MSK));
}

/**
  * @brief  Check if is active rx fifo underflow interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_rfuerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_RFUERR_MSK) == (UART_RIF_RFUERR_MSK));
}

/**
  * @brief  Check if is active rx fifo overflow interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_rfoerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_RFOERR_MSK) == (UART_RIF_RFOERR_MSK));
}

/**
  * @brief  Check if is active rx not empty interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_it_rfnempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_RFNEMPTY_MSK) == (UART_RIF_RFNEMPTY_MSK));
}

/**
  * @brief  Check if is active rx noise threshold interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_noise(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_NOISE_MSK) == (UART_RIF_NOISE_MSK));
}

/**
  * @brief  Check if is active block end interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_eob(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_EOB_MSK) == (UART_RIF_EOB_MSK));
}

/**
  * @brief  Check if is active link break interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_linbk(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_LINBK_MSK) == (UART_RIF_LINBK_MSK));
}

/**
  * @brief  Check if is active address match interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_addrm(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_ADDRM_MSK) == (UART_RIF_ADDRM_MSK));
}

/**
  * @brief  Check if is active receive timeout interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_rxto(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_RXTO_MSK) == (UART_RIF_RXTO_MSK));
}

/**
  * @brief  Check if is active CTSn change interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_dcts(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_DCTS_MSK) == (UART_RIF_DCTS_MSK));
}

/**
  * @brief  Check if is active auto-baud detection timeout interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_abto(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_ABTO_MSK) == (UART_RIF_ABTO_MSK));
}

/**
  * @brief  Check if is active auto-baud detection end interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_abend(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_ABEND_MSK) == (UART_RIF_ABEND_MSK));
}

/**
  * @brief  Check if is active rx format error interrupt.
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_uart_is_active_flag_rxberr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->RIF, UART_RIF_RXBERR_MSK) == (UART_RIF_RXBERR_MSK));
}
/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group17 IFM
  * @{
  */
/**
  * @brief  Mask tx fifo overflow interrupt.
  * @param  UARTx UART Instance
  * @retval Interrupt Mask.
  */
__STATIC_INLINE uint32_t md_uart_mask_it_tfover(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_TFOVER_MSK) == UART_IFM_TFOVER_MSK);
}

/**
  * @brief  Mask tx fifo empty interrupt.
  * @param  UARTx UART Instance
  * @retval Interrupt Mask.
  */
__STATIC_INLINE uint32_t md_uart_mask_it_tfempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_TFEMPTY_MSK) == UART_IFM_TFEMPTY_MSK);
}

/**
  * @brief  Mask tx fifo transmit complete interrupt.
  * @param  UARTx UART Instance
  * @retval Interrupt Mask.
  */
__STATIC_INLINE uint32_t md_uart_mask_it_tbc(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_TBC_MSK) == UART_IFM_TBC_MSK);
}

/**
  * @brief  Mask rx fifo underflow interrupt.
  * @param  UARTx UART Instance
  * @retval Interrupt Mask.
  */
__STATIC_INLINE uint32_t md_uart_mask_it_rfuerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_RFUERR_MSK) == UART_IFM_RFUERR_MSK);
}

/**
  * @brief  Mask rx fifo overflow interrupt.
  * @param  UARTx UART Instance
  * @retval Interrupt Mask.
  */
__STATIC_INLINE uint32_t md_uart_mask_it_rfoerr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_RFOERR_MSK) == UART_IFM_RFOERR_MSK);
}

/**
  * @brief  Mask rx not empty interrupt.
  * @param  UARTx UART Instance
  * @retval Interrupt Mask.
  */
__STATIC_INLINE uint32_t md_uart_mask_it_rfnempty(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_RFNEMPTY_MSK) == UART_IFM_RFNEMPTY_MSK);
}

/**
  * @brief  Mask rx fifo noise interrupt.
  * @param  UARTx UART Instance
  * @retval Interrupt Mask.
  */
__STATIC_INLINE uint32_t md_uart_mask_it_noise(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_NOISE_MSK) == UART_IFM_NOISE_MSK);
}

/**
  * @brief  Mask block end interrupt.
  * @param  UARTx UART Instance
  * @retval Interrupt Mask.
  */
__STATIC_INLINE uint32_t md_uart_mask_it_eob(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_EOB_MSK) == UART_IFM_EOB_MSK);
}

/**
  * @brief  Mask link break interrupt.
  * @param  UARTx UART Instance
  * @retval Interrupt Mask.
  */
__STATIC_INLINE uint32_t md_uart_mask_it_linbk(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_LINBK_MSK) == UART_IFM_LINBK_MSK);
}

/**
  * @brief  Mask address match interrupt.
  * @param  UARTx UART Instance
  * @retval Interrupt Mask.
  */
__STATIC_INLINE uint32_t md_uart_mask_it_addrm(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_ADDRM_MSK) == UART_IFM_ADDRM_MSK);
}

/**
  * @brief  Mask receive timeout interrupt.
  * @param  UARTx UART Instance
  * @retval Interrupt Mask.
  */
__STATIC_INLINE uint32_t md_uart_mask_it_rxto(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_RXTO_MSK) == UART_IFM_RXTO_MSK);
}

/**
  * @brief  Mask CTSn change interrupt.
  * @param  UARTx UART Instance
  * @retval Interrupt Mask.
  */
__STATIC_INLINE uint32_t md_uart_mask_it_dcts(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_DCTS_MSK) == UART_IFM_DCTS_MSK);
}

/**
  * @brief  Mask auto-baud detection timeout interrupt.
  * @param  UARTx UART Instance
  * @retval Interrupt Mask.
  */
__STATIC_INLINE uint32_t md_uart_mask_it_abto(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_ABTO_MSK) == UART_IFM_ABTO_MSK);
}

/**
  * @brief  Mask auto-baud detection end interrupt.
  * @param  UARTx UART Instance
  * @retval Interrupt Mask.
  */
__STATIC_INLINE uint32_t md_uart_mask_it_abend(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_ABEND_MSK) == UART_IFM_ABEND_MSK);
}

/**
  * @brief  Read Mask rx format error interrupt.
  * @param  UARTx UART Instance
  * @retval Interrupt Mask.
  */
__STATIC_INLINE uint32_t md_uart_mask_it_rxberr(UART_TypeDef *UARTx)
{
    return (READ_BIT(UARTx->IFM, UART_IFM_RXBERR_MSK) == UART_IFM_RXBERR_MSK);
}
/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group18 ICR
  * @{
  */
/**
  * @brief  Clear tx fifo overflow interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_clear_it_tfover(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_TFOVER_MSK);
}

/**
  * @brief  Clear tx fifo empty interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_clear_it_tfempty(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_TFEMPTY_MSK);
}

/**
  * @brief  Clear tx fifo transmit complete interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_clear_it_tbc(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_TBC_MSK);
}

/**
  * @brief  Clear rx fifo underflow interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_clear_flag_rfuerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_RFUERC_W1_MSK);
}

/**
  * @brief  Clear rx fifo overflow interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_clear_flag_rfoerr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_RFOERC_W1_MSK);
}

/**
  * @brief  Clear rx not empty interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_clear_flag_rfnempty(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_RFNEMPTY_MSK);
}

/**
  * @brief  Clear rx fifo noise interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_clear_flag_noise(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_NOISE_MSK);
}

/**
  * @brief  Clear block end interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_clear_flag_eob(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_EOB_MSK);
}

/**
  * @brief  Clear LIN break interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_clear_flag_linbk(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_LINBK_MSK);
}

/**
  * @brief  Clear address match interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_clear_flag_addrm(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_ADDRM_MSK);
}

/**
  * @brief  Clear receive timeout interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_clear_flag_rxto(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_RXTO_MSK);
}

/**
  * @brief  Clear CTSn change interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_clear_flag_dcts(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_DCTS_MSK);
}

/**
  * @brief  Clear auto-baud detection timeout interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_clear_flag_abto(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_ABTO_MSK);
}

/**
  * @brief  Clear auto-baud detection end interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_clear_it_abend(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_ABEND_MSK);
}

/**
  * @brief  Clear rx format error interrupt.
  * @param  UARTx UART Instance
  * @retval None.
  */
__STATIC_INLINE void md_uart_clear_flag_rxberr(UART_TypeDef *UARTx)
{
    SET_BIT(UARTx->ICR, UART_ICR_RXBERR_MSK);
}
/**
  * @}
  */
/** @defgroup MD_UART_Public_Functions_Group1 Initialization
  * @{
  */
extern void md_uart_reset(UART_TypeDef *UARTx);
extern void md_uart_init(UART_TypeDef *UARTx, md_uart_init_t *init);
extern void md_uart_init_struct(md_uart_init_t *init);
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
#endif /* __MD_UART_H__ */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
