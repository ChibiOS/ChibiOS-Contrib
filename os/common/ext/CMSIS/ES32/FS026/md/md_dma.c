/**********************************************************************************
 *
 * @file    md_dma.c
 * @brief   md_dma C file
 *
 * @date    26 Apr 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          26 Apr 2022     AE Team         the first version
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
#include "md_syscfg.h"
#include "md_dma.h"
#include <stdio.h>
#include <stdint.h>
/* Private types --------------------------------------------------------------*/
/* Private variables ----------------------------------------------------------*/
/* Private constants ----------------------------------------------------------*/
/* Private macros -------------------------------------------------------------*/
/* Private function prototypes ------------------------------------------------*/
/* Public functions -----------------------------------------------------------*/




void md_dma_init(DMA_TypeDef *DMAx, md_dma_init_typedef DMAx_init)
{
    if (DMAx_init.type == MD_DMA_PRIMARY)
    {
        md_dma_enable_primary_mode(DMAx, DMAx_init.channal);
        md_dma_set_primary_channel_source_data_end_address(DMAx, DMAx_init.channal, DMAx_init.source_data_end_address);
        md_dma_set_primary_channel_destination_data_end_address(DMAx, DMAx_init.channal, DMAx_init.destination_data_end_address);
        md_dma_set_primary_channel_cycle_mode(DMAx, DMAx_init.channal, DMAx_init.cycle_mode);

        if ((DMAx_init.transfer_number - 1) > 0)
        {
            md_dma_set_primary_channel_transfer_number(DMAx, DMAx_init.channal, DMAx_init.transfer_number - 1);
        }
        else
        {
            md_dma_set_primary_channel_transfer_number(DMAx, DMAx_init.channal, 0);
        }

        md_dma_set_primary_channel_r_power(DMAx, DMAx_init.channal, DMAx_init.r_power);
        md_dma_set_primary_channel_source_address_size(DMAx, DMAx_init.channal, DMAx_init.source_address_size);
        md_dma_set_primary_channel_source_address_incremental(DMAx, DMAx_init.channal, DMAx_init.source_address_incremental);
        md_dma_set_primary_channel_destination_address_size(DMAx, DMAx_init.channal, DMAx_init.destination_address_size);
        md_dma_set_primary_channel_destination_address_incremental(DMAx, DMAx_init.channal, DMAx_init.destination_address_incremental);
    }
    else if (DMAx_init.type == MD_DMA_ALTERNATE)
    {
        md_dma_enable_alternate_mode(DMAx, DMAx_init.channal);
        md_dma_set_alternate_channel_source_data_end_address(DMAx, DMAx_init.channal, DMAx_init.source_data_end_address);
        md_dma_set_alternate_channel_destination_data_end_address(DMAx, DMAx_init.channal, DMAx_init.destination_data_end_address);
        md_dma_set_alternate_channel_cycle_mode(DMAx, DMAx_init.channal, DMAx_init.cycle_mode);

        if ((DMAx_init.transfer_number - 1) > 0)
        {
            md_dma_set_alternate_channel_transfer_number(DMAx, DMAx_init.channal, DMAx_init.transfer_number - 1);
        }
        else
        {
            md_dma_set_alternate_channel_transfer_number(DMAx, DMAx_init.channal, 0);
        }

        md_dma_set_alternate_channel_r_power(DMAx, DMAx_init.channal, DMAx_init.r_power);
        md_dma_set_alternate_channel_source_address_size(DMAx, DMAx_init.channal, DMAx_init.source_address_size);
        md_dma_set_alternate_channel_source_address_incremental(DMAx, DMAx_init.channal, DMAx_init.source_address_incremental);
        md_dma_set_alternate_channel_destination_address_size(DMAx, DMAx_init.channal, DMAx_init.destination_address_size);
        md_dma_set_alternate_channel_destination_address_incremental(DMAx, DMAx_init.channal, DMAx_init.destination_address_incremental);
    }


    if (DMAx_init.disable_auto_software_enable_channel == 0)
        md_dma_enable_channel(DMAx, DMAx_init.channal);
}

/**
  * @brief  md_dma_set_channel_data_start_address_and_length
  * @param  len:
            number of arrays
  * @param  size:
            MD_DMA_CHANNEL_SIZE_BYTE
            MD_DMA_CHANNEL_SIZE_HALF_WORD
            MD_DMA_CHANNEL_SIZE_WORD
  * @retval None
  */

uint32_t md_dma_set_channel_data_start_address_and_length(uint32_t addr, uint32_t len, uint32_t size)
{
    return (uint32_t)addr + ((len - 1) * (1 << size));
}

/**
  * @brief  md_dma_set_primary_channel_destination_data_start_address_and_length
  * @param  ch:
            MD_DMA_CHANNEL0
            MD_DMA_CHANNEL1
            MD_DMA_CHANNEL2
            MD_DMA_CHANNEL3
            MD_DMA_CHANNEL4
            MD_DMA_CHANNEL5
  * @param  len:
            number of arrays
  * @param  size:
            MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_BYTE
            MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_HALF_WORD
            MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_WORD
  * @retval None
  */

void md_dma_set_primary_channel_destination_data_start_address_and_length(DMA_TypeDef *DMAx, uint32_t ch, uint32_t addr, uint32_t len, uint32_t size)
{
    md_dma_set_primary_channel_destination_data_end_address(DMAx, ch, (uint32_t)addr + ((len - 1) * (1 << size)));
}


/**
  * @brief  md_dma_set_primary_channel_source_data_start_address_and_length
  * @param  ch:
            MD_DMA_CHANNEL0
            MD_DMA_CHANNEL1
            MD_DMA_CHANNEL2
            MD_DMA_CHANNEL3
            MD_DMA_CHANNEL4
            MD_DMA_CHANNEL5
  * @param  len:
            number of arrays
  * @param  size:
            MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_BYTE
            MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_HALF_WORD
            MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_WORD
  * @retval None
  */

void md_dma_set_primary_channel_source_data_start_address_and_length(DMA_TypeDef *DMAx, uint32_t ch, uint32_t addr, uint32_t len, uint32_t size)
{
    md_dma_set_primary_channel_source_data_end_address(DMAx, ch, (uint32_t)addr + ((len - 1) * (1 << size)));
}


