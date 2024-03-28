/**********************************************************************************
 *
 * @file    md_spi.c
 * @brief   md_spi C file
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov  2021    Ginger          the first version
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

/* Includes -------------------------------------------------------------------*/
#include "md_spi.h"
#include "md_rcu.h"
#include <stdio.h>
#include "stdint.h"
/** @addtogroup Micro_Driver
  * @{
  */

/* Private types --------------------------------------------------------------*/
/* Private variables ----------------------------------------------------------*/
/* Private constants ----------------------------------------------------------*/
/* Private macros -------------------------------------------------------------*/

/**
  * @brief  Initialize the SPI registers according to the specified parameters in SPI_initStruct.
  * @note   The parameters in md_spi_init should be expected values. Otherwise, ERROR result will be returned.
  * @param  SPI_InitStruct pointer to a @ref SPI_initStruct structure
  * @retval None
  */
void md_spi_struct_init(md_spi_inittypedef *SPI_InitStruct)
{
    SPI_InitStruct->Mode               = MD_SPI_MODE_MASTER;
    SPI_InitStruct->ClockPhase         = MD_SPI_PHASE_1EDGE;
    SPI_InitStruct->ClockPolarity      = MD_SPI_POLARITY_LOW;
    SPI_InitStruct->BaudRate           = MD_SPI_BAUDRATEPRESCALER_DIV16;
    SPI_InitStruct->BitOrder           = MD_SPI_MSB_FIRST;
    SPI_InitStruct->TransferDirection  = MD_SPI_FULL_DUPLEX;
    SPI_InitStruct->DataWidth          = MD_SPI_FRAME_FORMAT_8BIT;
    SPI_InitStruct->CRCCalculation     = MD_SPI_CRCCALCULATION_DISABLE;
    SPI_InitStruct->CRCPoly            = 0x7;
    SPI_InitStruct->NSS                = MD_SPI_NSS_HARD;
}

/**
  * @brief  Initialize the SPI registers according to the specified parameters in SPI_initStruct.
  * @note   The parameters in md_spi_init should be expected values. Otherwise, ERROR result will be returned.
  * @param  SPIx SPI Instance
  * @param  SPI_InitStruct pointer to a @ref SPI_InitStruct structure
  * @retval An ErrorStatus enumeration value. (Return always SUCCESS)
  */
ErrorStatus md_spi_init(SPI_TypeDef *SPIx, md_spi_inittypedef *SPI_InitStruct)
{
    ErrorStatus status = ERROR;

    md_spi_disable(SPIx);

    if (SPI_InitStruct->Mode == MD_SPI_MODE_MASTER)
        md_spi_enable_master_mode(SPIx);
    else
        md_spi_enable_slave_mode(SPIx);

    if (SPI_InitStruct->ClockPhase == MD_SPI_PHASE_1EDGE)
        md_spi_enable_sample_first_edge(SPIx);
    else
        md_spi_enable_sample_sec_edge(SPIx);

    if (SPI_InitStruct->ClockPolarity == MD_SPI_POLARITY_LOW)
        md_spi_enable_sck_low_idle(SPIx);
    else
        md_spi_enable_sck_high_idle(SPIx);

    md_spi_set_commumication_baud(SPIx, SPI_InitStruct->BaudRate);

    if (SPI_InitStruct->BitOrder == MD_SPI_LSB_FIRST)
        md_spi_enable_first_transmit_lsb(SPIx);
    else
        md_spi_enable_first_transmit_msb(SPIx);

    if (SPI_InitStruct->TransferDirection == MD_SPI_HALF_DUPLEX)
        md_spi_set_simplex_line_duplex(SPIx);
    else
        md_spi_set_duplex_line_simplex(SPIx);

    if (SPI_InitStruct->DataWidth == MD_SPI_FRAME_FORMAT_16BIT)
        md_spi_enable_16_byte_commumication(SPIx);
    else
        md_spi_enable_8_byte_commumication(SPIx);



    if (SPI_InitStruct->NSS == MD_SPI_NSS_SOFT)
    {
        md_spi_enable_control_slave(SPIx);
        md_spi_enable_ss_output_high(SPIx);
    }
    else
        md_spi_disable_control_slave(SPIx);

    md_spi_enable_nss_output(SPIx);

    md_spi_enable(SPIx);

    status = SUCCESS;

    return status;
}


/**
  * @brief  De-Initialize the SPI registers to their default reset values.
  * @param  SPIx SPI Instance
  * @retval An ErrorStatus enumeration value. (Return always SUCCESS)
  */
ErrorStatus md_spi_deinit(SPI_TypeDef *SPIx)
{
    ErrorStatus status = ERROR;

    /* Check the parameters */
    md_spi_disable(SPIx);

    if (SPIx == SPI1)
    {
        /* Force reset of SPI clock */
        md_rcu_enable_spi1_reset(RCU);

        /* Release reset of SPI clock */
        md_rcu_disable_spi1_reset(RCU);
    }

    if (SPIx == SPI2)
    {
        /* Force reset of SPI clock */
        md_rcu_enable_spi2_reset(RCU);

        /* Release reset of SPI clock */
        md_rcu_disable_spi2_reset(RCU);
    }

    if (SPIx == SPI3)
    {
        /* Force reset of SPI clock */
        md_rcu_enable_spi3_reset(RCU);

        /* Release reset of SPI clock */
        md_rcu_disable_spi2_reset(RCU);
    }

    status = SUCCESS;

    return status;
}

/**
  * @brief  use to receive single one byte data.
  * @note   SPI Slave receive data
  * @param  SPIx SPI Instance
  * @retval Data.
  */
uint8_t md_spi_recv_byte(SPI_TypeDef *SPIx)
{
    while (!md_spi_is_active_flag_rxne(SPIx));

    return (md_spi_get_data_reg(SPIx));
}

/**
  * @brief  use to send single one byte data.
  * @note   SPI send data
  * @param  SPIx SPI Instance
  * @param  data SPI send one byte data.
  */
void md_spi_send_byte(SPI_TypeDef *SPIx, uint8_t data)
{
    md_spi_set_data_reg(SPIx, data);

    while (!(md_spi_is_active_flag_txe(SPIx)));
}

/**
  * @brief  use to receive single one halfword data.
  * @note   SPI Slave receive data
  * @param  SPIx SPI Instance
  * @retval Data.
  */
uint16_t md_spi_recv_halfword(SPI_TypeDef *SPIx)
{
    while (!md_spi_is_active_flag_rxne(SPIx));

    return (md_spi_get_data_reg(SPIx));
}

/**
  * @brief  use to send single one halfword data.
  * @note   SPI send data
  * @param  SPIx SPI Instance
  * @param  data SPI send one halfword data.
  */
void md_spi_send_halfword(SPI_TypeDef *SPIx, uint16_t data)
{
    md_spi_set_data_reg(SPIx, data);

    while (!(md_spi_is_active_flag_txe(SPIx)));
}

/**
  * @} Micro_Driver
  */
