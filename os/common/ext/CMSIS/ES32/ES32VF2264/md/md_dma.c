/**********************************************************************************
 *
 * @file    md_dma.c
 * @brief   DMA module driver.
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

/* Includes ------------------------------------------------------------------ */
#include "md_dma.h"

/* Private Macros ------------------------------------------------------------ */
#define IS_PERH_ADDR(x) (((uint32_t)(x))>=0x40000000)
/* Private Variables --------------------------------------------------------- */
/* Public Variables ---------------------------------------------------------- */
/* Private Constants --------------------------------------------------------- */
/* Private function prototypes ----------------------------------------------- */

/* Private Function ---------------------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */

/** @addtogroup MD_DMA
  * @{
  */

/** @addtogroup MD_DMA_Public_Functions
  * @{
  */
/** @addtogroup MD_DMA_Public_Functions_Group1
  * @{
  */
/**
  * @brief  Reset the DMA register
  * @param  DMAx: Pointer to DMA peripheral
  * @retval None
  */
void md_dma_reset(void)
{
    uint32_t i;

    WRITE_REG(DMA->IDR, 0x3FFF);
    WRITE_REG(DMA->ICR, 0x3FFF);

    for (i = 0; i < DMA_CHANNELS; ++i)
    {
        md_dma_disable_channel(i);
        WRITE_REG(DMA->CHANNEL[i].CON, 0x0);
        WRITE_REG(DMA->CHANNEL[i].SAR, 0x0);
        WRITE_REG(DMA->CHANNEL[i].DAR, 0x0);
        WRITE_REG(DMA->CHANNEL[i].NDT, 0x0);
        WRITE_REG(DMA_MUX->CH_SELCON[i], 0x0);
    }

    return;
}

/**
  * @brief  DMA init
  * @param  ch: DMA channel
  * @param  config: DMA config
  * @retval None
  */
void md_dma_init(uint32_t ch, md_dma_config_t *config)
{
    md_dma_set_source_addr(ch, config->src);
    md_dma_set_source_width(ch, config->src_data_width);
    md_dma_set_source_inc(ch, config->src_inc);
    md_dma_set_dest_addr(ch, config->dst);
    md_dma_set_dest_width(ch, config->dst_data_width);
    md_dma_set_dest_inc(ch, config->dst_inc);
    md_dma_set_circle_mode(ch, config->circle_mode);
    md_dma_set_mem_to_mem(ch, config->mem_to_mem);
    md_dma_set_priority(ch, config->priority);
    md_dma_set_r_power(ch, config->R_power);
    md_dma_set_transfer_size(ch, config->size);
    md_dma_set_channel_msel(ch, config->msel);
    md_dma_set_channel_msigsel(ch, config->msigsel);
	
	if (IS_PERH_ADDR(config->dst)&&!IS_PERH_ADDR(config->src))
	{
		md_dma_set_data_dir(ch, ENABLE);
	}
    else
    {
        md_dma_set_data_dir(ch, DISABLE);
    }
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
