/**********************************************************************************
 *
 * @file    md_uart.c
 * @brief   md_uart C file
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov   2021    Ginger         the first version
 *          27 Apr   2022    AE Team        add function
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

/* Includes -------------------------------------------------------------------*/
#include "system_fs026.h"
#include "md_uart.h"
#include <stdlib.h>

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup UART UART
  * @brief UART micro driver
  * @{
  */

/* Private types --------------------------------------------------------------*/
/* Private variables ----------------------------------------------------------*/
/* Private constants ----------------------------------------------------------*/
/* Private macros -------------------------------------------------------------*/
/* Private function prototypes ------------------------------------------------*/

/* Public functions -----------------------------------------------------------*/

/** @defgroup UART_PUB_FUNC UART Public Functions
  * @brief UART Public Functions
  * @{
  */
/**
  * @brief  Set UARTx baudrate.
  * @param  UARTx UART Instance.
  * @param  Baudrate
  * @retval None.
  */
void md_uart_setting_baudrate(UART_TypeDef *UARTx, uint32_t baudrate)
{
    uint32_t brr;
    brr = ((SystemFrequency_APBClk + (baudrate >> 1)) / baudrate);
    md_uart_set_baudrate(UARTx, brr);
}

/**
  * @brief  UART Initialization
  * @param  UART Init Structure
  * @retval None
  */
void md_uart_init(UART_TypeDef *UARTx, md_uart_init_typedef *UART_InitStruct)
{
    /* Check the UART_InitStruct */
    assert_param((UART_InitStruct != NULL));

    md_uart_disable_tx(UARTx);
    md_uart_disable_rx(UARTx);
    md_uart_setting_baudrate(UARTx, UART_InitStruct->BaudRate);

    if (UART_InitStruct->BitOrder == MD_UART_LCON_MSB_FIRST)
        md_uart_set_bitorder_msb(UARTx);
    else
        md_uart_set_bitorder_lsb(UARTx);

    md_uart_set_stop(UARTx, UART_InitStruct->StopBits);
    md_uart_set_datawidth(UARTx, UART_InitStruct->DataWidth);
    md_uart_set_parity(UARTx, UART_InitStruct->Parity);

    md_uart_enable_tx(UARTx);
    md_uart_enable_rx(UARTx);
}

/**
  * @brief  UARTx send character
  * @param  UART_TypeDef *UARTx.
  * @param  Character
  * @retval None
  */
void md_uart_send(UART_TypeDef *UARTx, uint8_t data)
{
    while (!md_uart_is_active_flag_tfempty(UARTx)); // Tx FIFO empty

    md_uart_set_send_data8(UARTx, data);                    // Sent byte
}



/**
  * @brief  UARTx send string
  * @param  UART_TypeDef *UARTx.
  * @param  Character address
  * @param  data length
  * @retval None
  */
void md_uart_send_string(UART_TypeDef *UARTx, uint8_t *data, uint32_t len)
{
    int i = 0;

    for (i = 0; * (data + i) != '\0' && i < len; i++)
    {
        while (!md_uart_is_active_flag_tfempty(UARTx)); // Tx FIFO empty

        md_uart_set_send_data8(UARTx, *(data + i)); // Sent byte
    }
}


/**
  * @brief  UARTx receive character.
  * @param  UART_TypeDef *UARTx.
  * @retval unsigned char.
  */
uint8_t md_uart_receive(UART_TypeDef *UARTx)
{
    while (!md_uart_is_active_flag_rfnempty(UARTx));           // Rx FIFO not empty

    return (md_uart_get_recv_data8(UARTx));
}

/**
  * @brief  UARTx receive string.
  * @param  UART_TypeDef *UARTx.
  * @param  Character address
  * @param  data length
  * @retval unsigned char.
  */
void md_uart_receive_string(UART_TypeDef *UARTx, uint8_t *data, uint32_t len)
{
    int i = 0;

    for (i = 0; i < len; i++)
    {
        while (!md_uart_is_active_flag_rfnempty(UARTx));           // Rx FIFO not empty

        *(data + i) = (md_uart_get_recv_data8(UARTx));
    }
}



/**
  * @brief  Get UARTx baudrate.
  * @param  UART_TypeDef *UARTx.
  * @retval Baudrate.
  */
uint32_t md_uart_getting_baudrate(UART_TypeDef *UARTx)
{
    uint32_t brr, baudrate;

    brr = md_uart_get_baudrate(UARTx);
    baudrate = SystemFrequency_APBClk / brr;
    return baudrate;
}


/**
  * @} UART_PUB_FUNC UART Public Functions
  */

/**
  * @} UART
  */

/**
  * @} Micro_Driver
  */

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
