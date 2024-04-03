/**********************************************************************************
 *
 * @file    reg_spi.h
 * @brief   SPI Head File
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov 2021     Ginger          the first version
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

#ifndef __SPI_H__
#define __SPI_H__


/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/

/*  Support for anonymous structures and unions.  */
//#pragma anon_unions

/****************** Bit definition for SPI_CON1 register ************************/

# define  SPI_CON1_BIDEN_POS 15U
# define  SPI_CON1_BIDEN_MSK BIT(SPI_CON1_BIDEN_POS)
# define  SPI_CON1_BIDEN     SPI_CON1_BIDEN_MSK

# define  SPI_CON1_BIDOEN_POS 14U
# define  SPI_CON1_BIDOEN_MSK BIT(SPI_CON1_BIDOEN_POS)
# define  SPI_CON1_BIDOEN     SPI_CON1_BIDOEN_MSK

# define  SPI_CON1_CRCEN_POS 13U
# define  SPI_CON1_CRCEN_MSK BIT(SPI_CON1_CRCEN_POS)
# define  SPI_CON1_CRCEN     SPI_CON1_CRCEN_MSK

# define  SPI_CON1_NXTCRC_POS 12U
# define  SPI_CON1_NXTCRC_MSK BIT(SPI_CON1_NXTCRC_POS)
# define  SPI_CON1_NXTCRC     SPI_CON1_NXTCRC_MSK

# define  SPI_CON1_FLEN_POS 11U
# define  SPI_CON1_FLEN_MSK BIT(SPI_CON1_FLEN_POS)
# define  SPI_CON1_FLEN     SPI_CON1_FLEN_MSK

# define  SPI_CON1_RXO_POS 10U
# define  SPI_CON1_RXO_MSK BIT(SPI_CON1_RXO_POS)
# define  SPI_CON1_RXO     SPI_CON1_RXO_MSK

# define  SPI_CON1_SSEN_POS 9U
# define  SPI_CON1_SSEN_MSK BIT(SPI_CON1_SSEN_POS)
# define  SPI_CON1_SSEN     SPI_CON1_SSEN_MSK

# define  SPI_CON1_SSOUT_POS 8U
# define  SPI_CON1_SSOUT_MSK BIT(SPI_CON1_SSOUT_POS)
# define  SPI_CON1_SSOUT     SPI_CON1_SSOUT_MSK

# define  SPI_CON1_LSBFST_POS 7U
# define  SPI_CON1_LSBFST_MSK BIT(SPI_CON1_LSBFST_POS)
# define  SPI_CON1_LSBFST     SPI_CON1_LSBFST_MSK

# define  SPI_CON1_SPIEN_POS 6U
# define  SPI_CON1_SPIEN_MSK BIT(SPI_CON1_SPIEN_POS)
# define  SPI_CON1_SPIEN     SPI_CON1_SPIEN_MSK

# define  SPI_CON1_BAUD_POSS 3U
# define  SPI_CON1_BAUD_POSE 5U
# define  SPI_CON1_BAUD_MSK  BITS(SPI_CON1_BAUD_POSS, SPI_CON1_BAUD_POSE)
# define  SPI_CON1_BAUD      SPI_CON1_BAUD_MSK

# define  SPI_CON1_MSTREN_POS 2U
# define  SPI_CON1_MSTREN_MSK BIT(SPI_CON1_MSTREN_POS)
# define  SPI_CON1_MSTREN     SPI_CON1_MSTREN_MSK

# define  SPI_CON1_CPOL_POS 1U
# define  SPI_CON1_CPOL_MSK BIT(SPI_CON1_CPOL_POS)
# define  SPI_CON1_CPOL     SPI_CON1_CPOL_MSK

# define  SPI_CON1_CPHA_POS 0U
# define  SPI_CON1_CPHA_MSK BIT(SPI_CON1_CPHA_POS)
# define  SPI_CON1_CPHA     SPI_CON1_CPHA_MSK

/****************** Bit definition for SPI_CON2 register ************************/

# define  SPI_CON2_RXFTH_POSS 14U
# define  SPI_CON2_RXFTH_POSE 15U
# define  SPI_CON2_RXFTH_MSK  BITS(SPI_CON2_RXFTH_POSS, SPI_CON2_RXFTH_POSE)
# define  SPI_CON2_RXFTH      SPI_CON2_RXFTH_MSK

# define  SPI_CON2_TXFTH_POSS 12U
# define  SPI_CON2_TXFTH_POSE 13U
# define  SPI_CON2_TXFTH_MSK  BITS(SPI_CON2_TXFTH_POSS, SPI_CON2_TXFTH_POSE)
# define  SPI_CON2_TXFTH      SPI_CON2_TXFTH_MSK

# define  SPI_CON2_FRF_POS 4U
# define  SPI_CON2_FRF_MSK BIT(SPI_CON2_FRF_POS)
# define  SPI_CON2_FRF     SPI_CON2_FRF_MSK

# define  SPI_CON2_NSSP_POS 3U
# define  SPI_CON2_NSSP_MSK BIT(SPI_CON2_NSSP_POS)
# define  SPI_CON2_NSSP     SPI_CON2_NSSP_MSK

# define  SPI_CON2_NSSOE_POS 2U
# define  SPI_CON2_NSSOE_MSK BIT(SPI_CON2_NSSOE_POS)
# define  SPI_CON2_NSSOE     SPI_CON2_NSSOE_MSK

# define  SPI_CON2_TXDMA_POS 1U
# define  SPI_CON2_TXDMA_MSK BIT(SPI_CON2_TXDMA_POS)
# define  SPI_CON2_TXDMA     SPI_CON2_TXDMA_MSK

# define  SPI_CON2_RXDMA_POS 0U
# define  SPI_CON2_RXDMA_MSK BIT(SPI_CON2_RXDMA_POS)
# define  SPI_CON2_RXDMA     SPI_CON2_RXDMA_MSK

/****************** Bit definition for SPI_STAT register ************************/

# define  SPI_STAT_RXFLV_POSS 24U
# define  SPI_STAT_RXFLV_POSE 28U
# define  SPI_STAT_RXFLV_MSK  BITS(SPI_STAT_RXFLV_POSS, SPI_STAT_RXFLV_POSE)
# define  SPI_STAT_RXFLV      SPI_STAT_RXFLV_MSK

# define  SPI_STAT_TXFLV_POSS 16U
# define  SPI_STAT_TXFLV_POSE 20U
# define  SPI_STAT_TXFLV_MSK  BITS(SPI_STAT_TXFLV_POSS, SPI_STAT_TXFLV_POSE)
# define  SPI_STAT_TXFLV      SPI_STAT_TXFLV_MSK

# define  SPI_STAT_BUSY_POS 15U
# define  SPI_STAT_BUSY_MSK BIT(SPI_STAT_BUSY_POS)
# define  SPI_STAT_BUSY     SPI_STAT_BUSY_MSK

# define  SPI_STAT_CHSIDE_POS 14U
# define  SPI_STAT_CHSIDE_MSK BIT(SPI_STAT_CHSIDE_POS)
# define  SPI_STAT_CHSIDE     SPI_STAT_CHSIDE_MSK

# define  SPI_STAT_RXTH_POS 12U
# define  SPI_STAT_RXTH_MSK BIT(SPI_STAT_RXTH_POS)
# define  SPI_STAT_RXTH     SPI_STAT_RXTH_MSK

# define  SPI_STAT_RXUD_POS 11U
# define  SPI_STAT_RXUD_MSK BIT(SPI_STAT_RXUD_POS)
# define  SPI_STAT_RXUD     SPI_STAT_RXUD_MSK

# define  SPI_STAT_RXOV_POS 10U
# define  SPI_STAT_RXOV_MSK BIT(SPI_STAT_RXOV_POS)
# define  SPI_STAT_RXOV     SPI_STAT_RXOV_MSK

# define  SPI_STAT_RXF_POS 9U
# define  SPI_STAT_RXF_MSK BIT(SPI_STAT_RXF_POS)
# define  SPI_STAT_RXF     SPI_STAT_RXF_MSK

# define  SPI_STAT_RXNE_POS 8U
# define  SPI_STAT_RXNE_MSK BIT(SPI_STAT_RXNE_POS)
# define  SPI_STAT_RXNE     SPI_STAT_RXNE_MSK

# define  SPI_STAT_TXTH_POS 4U
# define  SPI_STAT_TXTH_MSK BIT(SPI_STAT_TXTH_POS)
# define  SPI_STAT_TXTH     SPI_STAT_TXTH_MSK

# define  SPI_STAT_TXUD_POS 3U
# define  SPI_STAT_TXUD_MSK BIT(SPI_STAT_TXUD_POS)
# define  SPI_STAT_TXUD     SPI_STAT_TXUD_MSK

# define  SPI_STAT_TXOV_POS 2U
# define  SPI_STAT_TXOV_MSK BIT(SPI_STAT_TXOV_POS)
# define  SPI_STAT_TXOV     SPI_STAT_TXOV_MSK

# define  SPI_STAT_TXF_POS 1U
# define  SPI_STAT_TXF_MSK BIT(SPI_STAT_TXF_POS)
# define  SPI_STAT_TXF     SPI_STAT_TXF_MSK

# define  SPI_STAT_TXE_POS 0U
# define  SPI_STAT_TXE_MSK BIT(SPI_STAT_TXE_POS)
# define  SPI_STAT_TXE     SPI_STAT_TXE_MSK

/****************** Bit definition for SPI_DATA register ************************/

# define  SPI_DATA_DATA_POSS 0U
# define  SPI_DATA_DATA_POSE 15U
# define  SPI_DATA_DATA_MSK  BITS(SPI_DATA_DATA_POSS, SPI_DATA_DATA_POSE)
# define  SPI_DATA_DATA      SPI_DATA_DATA_MSK

/****************** Bit definition for SPI_CRCPOLY register ************************/

# define  SPI_CRCPOLY_CRCPOLY_POSS 0U
# define  SPI_CRCPOLY_CRCPOLY_POSE 15U
# define  SPI_CRCPOLY_CRCPOLY_MSK  BITS(SPI_CRCPOLY_CRCPOLY_POSS, SPI_CRCPOLY_CRCPOLY_POSE)
# define  SPI_CRCPOLY_CRCPOLY      SPI_CRCPOLY_CRCPOLY_MSK

/****************** Bit definition for SPI_RXCRC register ************************/

# define  SPI_RXCRC_RXCRC_POSS 0U
# define  SPI_RXCRC_RXCRC_POSE 15U
# define  SPI_RXCRC_RXCRC_MSK  BITS(SPI_RXCRC_RXCRC_POSS, SPI_RXCRC_RXCRC_POSE)
# define  SPI_RXCRC_RXCRC      SPI_RXCRC_RXCRC_MSK

/****************** Bit definition for SPI_TXCRC register ************************/

# define  SPI_TXCRC_TXCRC_POSS 0U
# define  SPI_TXCRC_TXCRC_POSE 15U
# define  SPI_TXCRC_TXCRC_MSK  BITS(SPI_TXCRC_TXCRC_POSS, SPI_TXCRC_TXCRC_POSE)
# define  SPI_TXCRC_TXCRC      SPI_TXCRC_TXCRC_MSK

/****************** Bit definition for SPI_I2SCFG register ************************/

# define  SPI_I2SCFG_I2SMOD_POS 12U
# define  SPI_I2SCFG_I2SMOD_MSK BIT(SPI_I2SCFG_I2SMOD_POS)
# define  SPI_I2SCFG_I2SMOD     SPI_I2SCFG_I2SMOD_MSK

# define  SPI_I2SCFG_I2SE_POS 11U
# define  SPI_I2SCFG_I2SE_MSK BIT(SPI_I2SCFG_I2SE_POS)
# define  SPI_I2SCFG_I2SE     SPI_I2SCFG_I2SE_MSK

# define  SPI_I2SCFG_I2SCFG_POSS 8U
# define  SPI_I2SCFG_I2SCFG_POSE 10U
# define  SPI_I2SCFG_I2SCFG_MSK  BITS(SPI_I2SCFG_I2SCFG_POSS, SPI_I2SCFG_I2SCFG_POSE)
# define  SPI_I2SCFG_I2SCFG      SPI_I2SCFG_I2SCFG_MSK

# define  SPI_I2SCFG_PCMSYNC_POS 7U
# define  SPI_I2SCFG_PCMSYNC_MSK BIT(SPI_I2SCFG_PCMSYNC_POS)
# define  SPI_I2SCFG_PCMSYNC     SPI_I2SCFG_PCMSYNC_MSK

# define  SPI_I2SCFG_I2SSTD_POSS 4U
# define  SPI_I2SCFG_I2SSTD_POSE 5U
# define  SPI_I2SCFG_I2SSTD_MSK  BITS(SPI_I2SCFG_I2SSTD_POSS, SPI_I2SCFG_I2SSTD_POSE)
# define  SPI_I2SCFG_I2SSTD      SPI_I2SCFG_I2SSTD_MSK

# define  SPI_I2SCFG_CKPOL_POS 3U
# define  SPI_I2SCFG_CKPOL_MSK BIT(SPI_I2SCFG_CKPOL_POS)
# define  SPI_I2SCFG_CKPOL     SPI_I2SCFG_CKPOL_MSK

# define  SPI_I2SCFG_DATLEN_POSS 1U
# define  SPI_I2SCFG_DATLEN_POSE 2U
# define  SPI_I2SCFG_DATLEN_MSK  BITS(SPI_I2SCFG_DATLEN_POSS, SPI_I2SCFG_DATLEN_POSE)
# define  SPI_I2SCFG_DATLEN      SPI_I2SCFG_DATLEN_MSK

# define  SPI_I2SCFG_CHLEN_POS 0U
# define  SPI_I2SCFG_CHLEN_MSK BIT(SPI_I2SCFG_CHLEN_POS)
# define  SPI_I2SCFG_CHLEN     SPI_I2SCFG_CHLEN_MSK

/****************** Bit definition for SPI_I2SPR register ************************/

# define  SPI_I2SPR_EXTCKEN_POS 10U
# define  SPI_I2SPR_EXTCKEN_MSK BIT(SPI_I2SPR_EXTCKEN_POS)
# define  SPI_I2SPR_EXTCKEN     SPI_I2SPR_EXTCKEN_MSK

# define  SPI_I2SPR_MCKOE_POS 9U
# define  SPI_I2SPR_MCKOE_MSK BIT(SPI_I2SPR_MCKOE_POS)
# define  SPI_I2SPR_MCKOE     SPI_I2SPR_MCKOE_MSK

# define  SPI_I2SPR_ODD_POS 8U
# define  SPI_I2SPR_ODD_MSK BIT(SPI_I2SPR_ODD_POS)
# define  SPI_I2SPR_ODD     SPI_I2SPR_ODD_MSK

# define  SPI_I2SPR_I2SDIV_POSS 0U
# define  SPI_I2SPR_I2SDIV_POSE 7U
# define  SPI_I2SPR_I2SDIV_MSK  BITS(SPI_I2SPR_I2SDIV_POSS, SPI_I2SPR_I2SDIV_POSE)
# define  SPI_I2SPR_I2SDIV      SPI_I2SPR_I2SDIV_MSK

/****************** Bit definition for SPI_IER register ************************/

# define  SPI_IER_FRE_POS 18U
# define  SPI_IER_FRE_MSK BIT(SPI_IER_FRE_POS)
# define  SPI_IER_FRE     SPI_IER_FRE_MSK

# define  SPI_IER_MODF_POS 17U
# define  SPI_IER_MODF_MSK BIT(SPI_IER_MODF_POS)
# define  SPI_IER_MODF     SPI_IER_MODF_MSK

# define  SPI_IER_CRCERR_POS 16U
# define  SPI_IER_CRCERR_MSK BIT(SPI_IER_CRCERR_POS)
# define  SPI_IER_CRCERR     SPI_IER_CRCERR_MSK

# define  SPI_IER_RXTH_POS 12U
# define  SPI_IER_RXTH_MSK BIT(SPI_IER_RXTH_POS)
# define  SPI_IER_RXTH     SPI_IER_RXTH_MSK

# define  SPI_IER_RXUD_POS 11U
# define  SPI_IER_RXUD_MSK BIT(SPI_IER_RXUD_POS)
# define  SPI_IER_RXUD     SPI_IER_RXUD_MSK

# define  SPI_IER_RXOV_POS 10U
# define  SPI_IER_RXOV_MSK BIT(SPI_IER_RXOV_POS)
# define  SPI_IER_RXOV     SPI_IER_RXOV_MSK

# define  SPI_IER_RXF_POS 9U
# define  SPI_IER_RXF_MSK BIT(SPI_IER_RXF_POS)
# define  SPI_IER_RXF     SPI_IER_RXF_MSK

# define  SPI_IER_RXNE_POS 8U
# define  SPI_IER_RXNE_MSK BIT(SPI_IER_RXNE_POS)
# define  SPI_IER_RXNE     SPI_IER_RXNE_MSK

# define  SPI_IER_TXTH_POS 4U
# define  SPI_IER_TXTH_MSK BIT(SPI_IER_TXTH_POS)
# define  SPI_IER_TXTH     SPI_IER_TXTH_MSK

# define  SPI_IER_TXUD_POS 3U
# define  SPI_IER_TXUD_MSK BIT(SPI_IER_TXUD_POS)
# define  SPI_IER_TXUD     SPI_IER_TXUD_MSK

# define  SPI_IER_TXOV_POS 2U
# define  SPI_IER_TXOV_MSK BIT(SPI_IER_TXOV_POS)
# define  SPI_IER_TXOV     SPI_IER_TXOV_MSK

# define  SPI_IER_TXE_POS 0U
# define  SPI_IER_TXE_MSK BIT(SPI_IER_TXE_POS)
# define  SPI_IER_TXE     SPI_IER_TXE_MSK

/****************** Bit definition for SPI_IDR register ************************/

# define  SPI_IDR_FRE_POS 18U
# define  SPI_IDR_FRE_MSK BIT(SPI_IDR_FRE_POS)
# define  SPI_IDR_FRE     SPI_IDR_FRE_MSK

# define  SPI_IDR_MODF_POS 17U
# define  SPI_IDR_MODF_MSK BIT(SPI_IDR_MODF_POS)
# define  SPI_IDR_MODF     SPI_IDR_MODF_MSK

# define  SPI_IDR_CRCERR_POS 16U
# define  SPI_IDR_CRCERR_MSK BIT(SPI_IDR_CRCERR_POS)
# define  SPI_IDR_CRCERR     SPI_IDR_CRCERR_MSK

# define  SPI_IDR_RXTH_POS 12U
# define  SPI_IDR_RXTH_MSK BIT(SPI_IDR_RXTH_POS)
# define  SPI_IDR_RXTH     SPI_IDR_RXTH_MSK

# define  SPI_IDR_RXUD_POS 11U
# define  SPI_IDR_RXUD_MSK BIT(SPI_IDR_RXUD_POS)
# define  SPI_IDR_RXUD     SPI_IDR_RXUD_MSK

# define  SPI_IDR_RXOV_POS 10U
# define  SPI_IDR_RXOV_MSK BIT(SPI_IDR_RXOV_POS)
# define  SPI_IDR_RXOV     SPI_IDR_RXOV_MSK

# define  SPI_IDR_RXF_POS 9U
# define  SPI_IDR_RXF_MSK BIT(SPI_IDR_RXF_POS)
# define  SPI_IDR_RXF     SPI_IDR_RXF_MSK

# define  SPI_IDR_RXNE_POS 8U
# define  SPI_IDR_RXNE_MSK BIT(SPI_IDR_RXNE_POS)
# define  SPI_IDR_RXNE     SPI_IDR_RXNE_MSK

# define  SPI_IDR_TXTH_POS 4U
# define  SPI_IDR_TXTH_MSK BIT(SPI_IDR_TXTH_POS)
# define  SPI_IDR_TXTH     SPI_IDR_TXTH_MSK

# define  SPI_IDR_TXUD_POS 3U
# define  SPI_IDR_TXUD_MSK BIT(SPI_IDR_TXUD_POS)
# define  SPI_IDR_TXUD     SPI_IDR_TXUD_MSK

# define  SPI_IDR_TXOV_POS 2U
# define  SPI_IDR_TXOV_MSK BIT(SPI_IDR_TXOV_POS)
# define  SPI_IDR_TXOV     SPI_IDR_TXOV_MSK

# define  SPI_IDR_TXE_POS 0U
# define  SPI_IDR_TXE_MSK BIT(SPI_IDR_TXE_POS)
# define  SPI_IDR_TXE     SPI_IDR_TXE_MSK

/****************** Bit definition for SPI_IVS register ************************/

# define  SPI_IVS_FRE_POS 18U
# define  SPI_IVS_FRE_MSK BIT(SPI_IVS_FRE_POS)
# define  SPI_IVS_FRE     SPI_IVS_FRE_MSK

# define  SPI_IVS_MODF_POS 17U
# define  SPI_IVS_MODF_MSK BIT(SPI_IVS_MODF_POS)
# define  SPI_IVS_MODF     SPI_IVS_MODF_MSK

# define  SPI_IVS_CRCERR_POS 16U
# define  SPI_IVS_CRCERR_MSK BIT(SPI_IVS_CRCERR_POS)
# define  SPI_IVS_CRCERR     SPI_IVS_CRCERR_MSK

# define  SPI_IVS_RXTH_POS 12U
# define  SPI_IVS_RXTH_MSK BIT(SPI_IVS_RXTH_POS)
# define  SPI_IVS_RXTH     SPI_IVS_RXTH_MSK

# define  SPI_IVS_RXUD_POS 11U
# define  SPI_IVS_RXUD_MSK BIT(SPI_IVS_RXUD_POS)
# define  SPI_IVS_RXUD     SPI_IVS_RXUD_MSK

# define  SPI_IVS_RXOV_POS 10U
# define  SPI_IVS_RXOV_MSK BIT(SPI_IVS_RXOV_POS)
# define  SPI_IVS_RXOV     SPI_IVS_RXOV_MSK

# define  SPI_IVS_RXF_POS 9U
# define  SPI_IVS_RXF_MSK BIT(SPI_IVS_RXF_POS)
# define  SPI_IVS_RXF     SPI_IVS_RXF_MSK

# define  SPI_IVS_RXNE_POS 8U
# define  SPI_IVS_RXNE_MSK BIT(SPI_IVS_RXNE_POS)
# define  SPI_IVS_RXNE     SPI_IVS_RXNE_MSK

# define  SPI_IVS_TXTH_POS 4U
# define  SPI_IVS_TXTH_MSK BIT(SPI_IVS_TXTH_POS)
# define  SPI_IVS_TXTH     SPI_IVS_TXTH_MSK

# define  SPI_IVS_TXUD_POS 3U
# define  SPI_IVS_TXUD_MSK BIT(SPI_IVS_TXUD_POS)
# define  SPI_IVS_TXUD     SPI_IVS_TXUD_MSK

# define  SPI_IVS_TXOV_POS 2U
# define  SPI_IVS_TXOV_MSK BIT(SPI_IVS_TXOV_POS)
# define  SPI_IVS_TXOV     SPI_IVS_TXOV_MSK

# define  SPI_IVS_TXE_POS 0U
# define  SPI_IVS_TXE_MSK BIT(SPI_IVS_TXE_POS)
# define  SPI_IVS_TXE     SPI_IVS_TXE_MSK

/****************** Bit definition for SPI_RIF register ************************/

# define  SPI_RIF_FRE_POS 18U
# define  SPI_RIF_FRE_MSK BIT(SPI_RIF_FRE_POS)
# define  SPI_RIF_FRE     SPI_RIF_FRE_MSK

# define  SPI_RIF_MODF_POS 17U
# define  SPI_RIF_MODF_MSK BIT(SPI_RIF_MODF_POS)
# define  SPI_RIF_MODF     SPI_RIF_MODF_MSK

# define  SPI_RIF_CRCERR_POS 16U
# define  SPI_RIF_CRCERR_MSK BIT(SPI_RIF_CRCERR_POS)
# define  SPI_RIF_CRCERR     SPI_RIF_CRCERR_MSK

# define  SPI_RIF_RXTH_POS 12U
# define  SPI_RIF_RXTH_MSK BIT(SPI_RIF_RXTH_POS)
# define  SPI_RIF_RXTH     SPI_RIF_RXTH_MSK

# define  SPI_RIF_RXUD_POS 11U
# define  SPI_RIF_RXUD_MSK BIT(SPI_RIF_RXUD_POS)
# define  SPI_RIF_RXUD     SPI_RIF_RXUD_MSK

# define  SPI_RIF_RXOV_POS 10U
# define  SPI_RIF_RXOV_MSK BIT(SPI_RIF_RXOV_POS)
# define  SPI_RIF_RXOV     SPI_RIF_RXOV_MSK

# define  SPI_RIF_RXF_POS 9U
# define  SPI_RIF_RXF_MSK BIT(SPI_RIF_RXF_POS)
# define  SPI_RIF_RXF     SPI_RIF_RXF_MSK

# define  SPI_RIF_RXNE_POS 8U
# define  SPI_RIF_RXNE_MSK BIT(SPI_RIF_RXNE_POS)
# define  SPI_RIF_RXNE     SPI_RIF_RXNE_MSK

# define  SPI_RIF_TXTH_POS 4U
# define  SPI_RIF_TXTH_MSK BIT(SPI_RIF_TXTH_POS)
# define  SPI_RIF_TXTH     SPI_RIF_TXTH_MSK

# define  SPI_RIF_TXUD_POS 3U
# define  SPI_RIF_TXUD_MSK BIT(SPI_RIF_TXUD_POS)
# define  SPI_RIF_TXUD     SPI_RIF_TXUD_MSK

# define  SPI_RIF_TXOV_POS 2U
# define  SPI_RIF_TXOV_MSK BIT(SPI_RIF_TXOV_POS)
# define  SPI_RIF_TXOV     SPI_RIF_TXOV_MSK

# define  SPI_RIF_TXE_POS 0U
# define  SPI_RIF_TXE_MSK BIT(SPI_RIF_TXE_POS)
# define  SPI_RIF_TXE     SPI_RIF_TXE_MSK

/****************** Bit definition for SPI_IFM register ************************/

# define  SPI_IFM_FRE_POS 18U
# define  SPI_IFM_FRE_MSK BIT(SPI_IFM_FRE_POS)
# define  SPI_IFM_FRE     SPI_IFM_FRE_MSK

# define  SPI_IFM_MODF_POS 17U
# define  SPI_IFM_MODF_MSK BIT(SPI_IFM_MODF_POS)
# define  SPI_IFM_MODF     SPI_IFM_MODF_MSK

# define  SPI_IFM_CRCERR_POS 16U
# define  SPI_IFM_CRCERR_MSK BIT(SPI_IFM_CRCERR_POS)
# define  SPI_IFM_CRCERR     SPI_IFM_CRCERR_MSK

# define  SPI_IFM_RXTH_POS 12U
# define  SPI_IFM_RXTH_MSK BIT(SPI_IFM_RXTH_POS)
# define  SPI_IFM_RXTH     SPI_IFM_RXTH_MSK

# define  SPI_IFM_RXUD_POS 11U
# define  SPI_IFM_RXUD_MSK BIT(SPI_IFM_RXUD_POS)
# define  SPI_IFM_RXUD     SPI_IFM_RXUD_MSK

# define  SPI_IFM_RXOV_POS 10U
# define  SPI_IFM_RXOV_MSK BIT(SPI_IFM_RXOV_POS)
# define  SPI_IFM_RXOV     SPI_IFM_RXOV_MSK

# define  SPI_IFM_RXF_POS 9U
# define  SPI_IFM_RXF_MSK BIT(SPI_IFM_RXF_POS)
# define  SPI_IFM_RXF     SPI_IFM_RXF_MSK

# define  SPI_IFM_RXNE_POS 8U
# define  SPI_IFM_RXNE_MSK BIT(SPI_IFM_RXNE_POS)
# define  SPI_IFM_RXNE     SPI_IFM_RXNE_MSK

# define  SPI_IFM_TXTH_POS 4U
# define  SPI_IFM_TXTH_MSK BIT(SPI_IFM_TXTH_POS)
# define  SPI_IFM_TXTH     SPI_IFM_TXTH_MSK

# define  SPI_IFM_TXUD_POS 3U
# define  SPI_IFM_TXUD_MSK BIT(SPI_IFM_TXUD_POS)
# define  SPI_IFM_TXUD     SPI_IFM_TXUD_MSK

# define  SPI_IFM_TXOV_POS 2U
# define  SPI_IFM_TXOV_MSK BIT(SPI_IFM_TXOV_POS)
# define  SPI_IFM_TXOV     SPI_IFM_TXOV_MSK

# define  SPI_IFM_TXE_POS 0U
# define  SPI_IFM_TXE_MSK BIT(SPI_IFM_TXE_POS)
# define  SPI_IFM_TXE     SPI_IFM_TXE_MSK

/****************** Bit definition for SPI_ICR register ************************/

# define  SPI_ICR_FRE_POS 18U
# define  SPI_ICR_FRE_MSK BIT(SPI_ICR_FRE_POS)
# define  SPI_ICR_FRE     SPI_ICR_FRE_MSK

# define  SPI_ICR_MODF_POS 17U
# define  SPI_ICR_MODF_MSK BIT(SPI_ICR_MODF_POS)
# define  SPI_ICR_MODF     SPI_ICR_MODF_MSK

# define  SPI_ICR_CRCERR_POS 16U
# define  SPI_ICR_CRCERR_MSK BIT(SPI_ICR_CRCERR_POS)
# define  SPI_ICR_CRCERR     SPI_ICR_CRCERR_MSK

# define  SPI_ICR_RXTH_POS 12U
# define  SPI_ICR_RXTH_MSK BIT(SPI_ICR_RXTH_POS)
# define  SPI_ICR_RXTH     SPI_ICR_RXTH_MSK

# define  SPI_ICR_RXUD_POS 11U
# define  SPI_ICR_RXUD_MSK BIT(SPI_ICR_RXUD_POS)
# define  SPI_ICR_RXUD     SPI_ICR_RXUD_MSK

# define  SPI_ICR_RXOV_POS 10U
# define  SPI_ICR_RXOV_MSK BIT(SPI_ICR_RXOV_POS)
# define  SPI_ICR_RXOV     SPI_ICR_RXOV_MSK

# define  SPI_ICR_RXF_POS 9U
# define  SPI_ICR_RXF_MSK BIT(SPI_ICR_RXF_POS)
# define  SPI_ICR_RXF     SPI_ICR_RXF_MSK

# define  SPI_ICR_RXNE_POS 8U
# define  SPI_ICR_RXNE_MSK BIT(SPI_ICR_RXNE_POS)
# define  SPI_ICR_RXNE     SPI_ICR_RXNE_MSK

# define  SPI_ICR_TXTH_POS 4U
# define  SPI_ICR_TXTH_MSK BIT(SPI_ICR_TXTH_POS)
# define  SPI_ICR_TXTH     SPI_ICR_TXTH_MSK

# define  SPI_ICR_TXUD_POS 3U
# define  SPI_ICR_TXUD_MSK BIT(SPI_ICR_TXUD_POS)
# define  SPI_ICR_TXUD     SPI_ICR_TXUD_MSK

# define  SPI_ICR_TXOV_POS 2U
# define  SPI_ICR_TXOV_MSK BIT(SPI_ICR_TXOV_POS)
# define  SPI_ICR_TXOV     SPI_ICR_TXOV_MSK

# define  SPI_ICR_TXE_POS 0U
# define  SPI_ICR_TXE_MSK BIT(SPI_ICR_TXE_POS)
# define  SPI_ICR_TXE     SPI_ICR_TXE_MSK

typedef struct
{
    __IO uint32_t CON1;                     // 0x000
    __IO uint32_t CON2;                     // 0x004
    __I  uint32_t STAT;                     // 0x008
    __IO uint32_t DATA;                     // 0x00c
    __IO uint32_t CRCPOLY;                  // 0x010
    __I  uint32_t RXCRC;                    // 0x014
    __I  uint32_t TXCRC;                    // 0x018
    __IO uint32_t I2SCFG;                   // 0x01c
    __IO uint32_t I2SPR;                    // 0x020
    __O  uint32_t IER;                      // 0x024
    __O  uint32_t IDR;                      // 0x028
    __I  uint32_t IVS;                      // 0x02c
    __I  uint32_t RIF;                      // 0x030
    __I  uint32_t IFM;                      // 0x034
    __O  uint32_t ICR;                      // 0x038
} SPI_TypeDef, I2S_TypeDef;


#endif
