/**********************************************************************************
 *
 * @file    md_spi.c
 * @brief   SPI module driver.
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

/* Includes ------------------------------------------------------------------ */
#include "md_spi.h"

/* Private Macros ------------------------------------------------------------ */
/* Private Variables --------------------------------------------------------- */
/* Public Variables ---------------------------------------------------------- */
/* Private Constants --------------------------------------------------------- */
/* Private function prototypes ----------------------------------------------- */

/* Private Function ---------------------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */

/** @addtogroup MD_SPI
  * @{
  */

/** @addtogroup MD_SPI_Public_Functions
  * @{
  */
/** @addtogroup MD_SPI_Public_Functions_Group1
  * @{
  */
/**
  * @brief  Reset the SPI specificed.
  * @param  SPIx: SPI Instance.
  * @retval None
  */
void md_spi_reset(SPI_I2S_TypeDef *SPIx)
{
    SPIx->CON1    = 0x0;
    SPIx->CON2    = 0x0;
    SPIx->CRCPOLY = 0x00000007;

    return;
}

/**
  * @brief  Initialize the SPI registers according to the specified parameters in init.
  * @note   As some bits in SPI configuration registers can only be written when the SPI is disabled (SPI_CON1_SPIEN bit =0),
  *         SPI IP should be in disabled state prior calling this function. Otherwise, ERROR result will be returned.
  * @param  init pointer to a @ref md_spi_init_t structure
  * @retval An ErrorStatus enumeration value.
  */
md_status_t md_spi_init(md_spi_init_t *init)
{
    uint32_t tmp = 0U;

    md_spi_reset(init->SPIx);
    tmp = init->SPIx->CON1;

    if ((init->mode) == MD_SPI_MODE_MASTER)
        tmp |= 1 << SPI_CON1_SSOUT_POS;

    tmp |= ((init->phase << SPI_CON1_CPHA_POS) | (init->polarity << SPI_CON1_CPOL_POS) |
            (init->baud << SPI_CON1_BAUD_POSS) | (init->data_size << SPI_CON1_FLEN_POS) |
            (init->mode << SPI_CON1_MSTREN_POS) | (init->ss_en << SPI_CON1_SSEN_POS) |
            (init->first_bit << SPI_CON1_LSBFST_POS));

    init->SPIx->CON1 = tmp;

    MODIFY_REG(init->SPIx->CON2, SPI_CON2_FRF_MSK, init->frame << SPI_CON2_FRF_POS);

    if (init->dir == MD_SPI_DIRECTION_2LINES)
    {
        md_spi_set_duplex_line_simplex(init->SPIx);
        md_spi_disable_recv_only(init->SPIx);
    }
    else if (init->dir == MD_SPI_DIRECTION_2LINES_RXONLY)
    {
        md_spi_set_duplex_line_simplex(init->SPIx);
        md_spi_enable_recv_only(init->SPIx);
    }
    else if (init->dir == MD_SPI_DIRECTION_1LINE_RX)
    {
        md_spi_set_simplex_line_duplex(init->SPIx);
        md_spi_enable_simplex_line_rx(init->SPIx);
    }
    else
    {
        md_spi_set_simplex_line_duplex(init->SPIx);
        md_spi_enable_simplex_line_tx(init->SPIx);
    }

    /* configure CRC */
    init->SPIx->CON1   |= (init->crc_calc << SPI_CON1_CRCEN_POS);
    init->SPIx->CRCPOLY = init->crc_poly;

    if (init->dir == MD_SPI_DIRECTION_2LINES)
        md_spi_enable(init->SPIx);

    return MD_OK;
}

/**
  * @brief  Set each @ref md_spi_init_t field to default value.
  * @param  init pointer to a @ref md_spi_init_t structure
  * whose fields will be set to default values.
  * @retval None
  */
void md_spi_struct_init(md_spi_init_t *init)
{
    init->SPIx      = SPI1;
    init->mode      = MD_SPI_MODE_MASTER;
    init->dir       = MD_SPI_DIRECTION_2LINES;
    init->data_size = MD_SPI_DATA_SIZE_8;
    init->baud      = MD_SPI_BAUD_64;
    init->phase     = MD_SPI_CPHA_FIRST;
    init->polarity  = MD_SPI_CPOL_HIGH;
    init->first_bit = MD_SPI_FIRSTBIT_MSB;
    init->ss_en     = DISABLE;
    init->crc_calc  = DISABLE;
    init->crc_poly  = 0;
}

/**
  * @brief  transmit one byte fast in blocking mode.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  data: Data to be sent
  * @retval status:
  *           -  0 Success
  *           - -1 Failed
  */
int32_t md_spi_send_byte_fast(md_spi_init_t *hperh, uint8_t data)
{
    uint16_t cnt = 5000U, temp;

    hperh->SPIx->DATA = data;

    while (((hperh->SPIx->STAT & SPI_STAT_TXE_MSK) == 0) && (--cnt));

    cnt = 5000;

    while (((hperh->SPIx->STAT & SPI_STAT_RXNE_MSK) != SPI_STAT_RXNE_MSK) && (--cnt));

    temp = hperh->SPIx->DATA;
    UNUSED(temp);

    return cnt == 0 ? -1 : 0;
}

/**
  * @brief  Receive one byte fast in blocking mode.
  * @param  hperh Pointer to a spi_handle_t structure.
  * @param status:
  *           -  0 Success
  *           - -1 Failed
  * @retval Data.
  */
uint8_t md_spi_recv_byte_fast(md_spi_init_t *hperh, int *status)
{
    uint16_t cnt = 4000U;

    if (hperh->mode == MD_SPI_MODE_MASTER)
    {
        hperh->SPIx->DATA = 0xFF;

        while (((hperh->SPIx->STAT & SPI_STAT_TXE_MSK) == 0) && (--cnt));
    }

    cnt = 4000;

    while (((hperh->SPIx->STAT & SPI_STAT_RXNE_MSK) != SPI_STAT_RXNE_MSK) && (--cnt));

    *status = cnt == 0 ? -1 : 0;

    return (uint8_t)hperh->SPIx->DATA;
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
