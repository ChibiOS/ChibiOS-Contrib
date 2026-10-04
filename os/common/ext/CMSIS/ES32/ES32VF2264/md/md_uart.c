/**********************************************************************************
 *
 * @file    md_uart.c
 * @brief   UART module driver.
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

/* Includes ------------------------------------------------------------------ */
#include "md_uart.h"
#include "md_cmu.h"

/* Private Macros ------------------------------------------------------------ */
/* Private Variables --------------------------------------------------------- */
/* Public Variables ---------------------------------------------------------- */
/* Private Constants --------------------------------------------------------- */
/* Private function prototypes ----------------------------------------------- */

/* Private Function ---------------------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */

/** @addtogroup MD_UART
  * @{
  */
/** @addtogroup MD_UART_Public_Functions
  * @{
  */
/** @addtogroup MD_UART_Public_Functions_Group1
  * @{
  */
/**
  * @brief  Reset UART peripheral
  * @param  UARTx: UART peripheral
  * @retval None
  */
void md_uart_reset(UART_TypeDef *UARTx)
{
    WRITE_REG(UARTx->BRR, 0x0);
    WRITE_REG(UARTx->LCON, 0x0);
    WRITE_REG(UARTx->MCON, 0x0);
    WRITE_REG(UARTx->RS485, 0x0);
    WRITE_REG(UARTx->SCARD, 0x0);
    WRITE_REG(UARTx->LIN, 0x0);
    WRITE_REG(UARTx->RTOR, 0x0);
    WRITE_REG(UARTx->IDR, 0xFFF);
}

/**
  * @brief  Initializes the UARTx according to the specified
  *         parameters in the uart_init_t.
  * @param  UARTx: UART peripheral
  * @param  init: Pointer to a md_uart_init_t structure that contains
  *         the configuration information for the specified UART module.
  * @retval None
  */
void md_uart_init(UART_TypeDef *UARTx, md_uart_init_t *init)
{
    uint32_t brr = 0U;
    brr = md_cmu_get_pclk_clock();
    brr = (brr + (init->baud >> 1)) / init->baud;

    md_uart_reset(UARTx);

    md_uart_set_datawidth(UARTx, init->word_length);
    md_uart_set_stop(UARTx, init->stop_bits);

    md_uart_set_parity(UARTx, init->parity);

    if (init->fctl)
    {
        md_uart_enable_auto_flow(UARTx);
    }
    else
    {
        md_uart_disable_auto_flow(UARTx);
    }

    md_uart_set_baudrate(UARTx, brr);

    if (init->mode == MD_UART_MODE_LIN)
        md_uart_enable_lin_mode(UARTx);
    else if (init->mode == MD_UART_MODE_IRDA)
        md_uart_enable_irda(UARTx);
    else if (init->mode == MD_UART_MODE_RS485)
        md_uart_enable_aaden(UARTx);
    else if (init->mode == MD_UART_MODE_HDSEL)
        md_uart_enable_half_duplex(UARTx);
    else
        ;   /* do nothing */

    md_uart_enable_tx(UARTx);
    md_uart_enable_rx(UARTx);

    return;
}

/**
  * @brief  Initialize the UARTx peripheral using the default parameters.
  * @param  init: Pointer to a md_uart_init_t structure
  * @retval None
  */
void md_uart_init_struct(md_uart_init_t *init)
{
    init->baud        = 115200;
    init->word_length = MD_UART_WORD_LENGTH_8B;
    init->stop_bits   = MD_UART_STOP_BITS_1;
    init->parity      = MD_UART_PARITY_NONE;
    init->fctl        = MD_UART_FLOW_CTL_DISABLE;
    init->mode        = MD_UART_MODE;

    return;
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
  * @}
  */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
