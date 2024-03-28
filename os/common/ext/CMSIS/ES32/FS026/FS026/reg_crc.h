/**********************************************************************************
 *
 * @file    reg_crc.h
 * @brief   CRC Head File
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

#ifndef __CRC_H__
#define __CRC_H__


/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/

/*  Support for anonymous structures and unions.  */
////#pragma anon_unions

/****************** Bit definition for CRC_INIT register ************************/

#define  CRC_INIT_INIT_POSS     0U
#define  CRC_INIT_INIT_POSE     31U
#define  CRC_INIT_INIT_MSK      BITS(CRC_INIT_INIT_POSS,CRC_INIT_INIT_POSE)
#define  CRC_INIT_INIT          CRC_INIT_INIT_MSK

/****************** Bit definition for CRC_POLY register ************************/

#define  CRC_POLY_POLY_POSS     0U
#define  CRC_POLY_POLY_POSE     31U
#define  CRC_POLY_POLY_MSK      BITS(CRC_POLY_POLY_POSS,CRC_POLY_POLY_POSE)
#define  CRC_POLY_POLY          CRC_POLY_POLY_MSK

/****************** Bit definition for CRC_DATA register ************************/

#define  CRC_DATA_DATA_POSS     0U
#define  CRC_DATA_DATA_POSE     31U
#define  CRC_DATA_DATA_MSK      BITS(CRC_DATA_DATA_POSS,CRC_DATA_DATA_POSE)
#define  CRC_DATA_DATA          CRC_DATA_DATA_MSK

/****************** Bit definition for CRC_COMP register ************************/

#define  CRC_COMP_COMP_POSS     0U
#define  CRC_COMP_COMP_POSE     31U
#define  CRC_COMP_COMP_MSK      BITS(CRC_COMP_COMP_POSS,CRC_COMP_COMP_POSE)
#define  CRC_COMP_COMP          CRC_COMP_COMP_MSK

/****************** Bit definition for CRC_REMA register ************************/

#define  CRC_REMA_REMA_POSS     0U
#define  CRC_REMA_REMA_POSE     31U
#define  CRC_REMA_REMA_MSK      BITS(CRC_REMA_REMA_POSS,CRC_REMA_REMA_POSE)
#define  CRC_REMA_REMA          CRC_REMA_REMA_MSK

/****************** Bit definition for CRC_CON register ************************/

#define  CRC_CON_DMA_POS    16U
#define  CRC_CON_DMA_MSK    BIT(CRC_CON_DMA_POS)
#define  CRC_CON_DMA        CRC_CON_DMA_MSK

#define  CRC_CON_MSB_POS    12U
#define  CRC_CON_MSB_MSK    BIT(CRC_CON_MSB_POS)
#define  CRC_CON_MSB        CRC_CON_MSB_MSK

#define  CRC_CON_REOUT_POS  10U
#define  CRC_CON_REOUT_MSK  BIT(CRC_CON_REOUT_POS)
#define  CRC_CON_REOUT      CRC_CON_REOUT_MSK

#define  CRC_CON_REIN_POS   8U
#define  CRC_CON_REIN_MSK   BIT(CRC_CON_REIN_POS)
#define  CRC_CON_REIN       CRC_CON_REIN_MSK

#define  CRC_CON_SIZE_POSS  4U
#define  CRC_CON_SIZE_POSE  5U
#define  CRC_CON_SIZE_MSK   BITS(CRC_CON_SIZE_POSS,CRC_CON_SIZE_POSE)
#define  CRC_CON_SIZE       CRC_CON_SIZE_MSK

#define  CRC_CON_MODE_POSS  2U
#define  CRC_CON_MODE_POSE  3U
#define  CRC_CON_MODE_MSK   BITS(CRC_CON_MODE_POSS,CRC_CON_MODE_POSE)
#define  CRC_CON_MODE       CRC_CON_MODE_MSK

#define  CRC_CON_RESET_POS  0U
#define  CRC_CON_RESET_MSK  BIT(CRC_CON_RESET_POS)
#define  CRC_CON_RESET      CRC_CON_RESET_MSK

/****************** Bit definition for CRC_DOUT register ************************/

#define  CRC_DOUT_DOUT_POSS     0U
#define  CRC_DOUT_DOUT_POSE     31U
#define  CRC_DOUT_DOUT_MSK      BITS(CRC_DOUT_DOUT_POSS,CRC_DOUT_DOUT_POSE)
#define  CRC_DOUT_DOUT          CRC_DOUT_DOUT_MSK

/****************** Bit definition for CRC_DOUT_XOR register ************************/

#define  CRC_DOUT_XOR_DOUT_XOR_POSS     0U
#define  CRC_DOUT_XOR_DOUT_XOR_POSE     31U
#define  CRC_DOUT_XOR_DOUT_XOR_MSK      BITS(CRC_DOUT_XOR_DOUT_XOR_POSS,CRC_DOUT_XOR_DOUT_XOR_POSE)
#define  CRC_DOUT_XOR_DOUT_XOR          CRC_DOUT_XOR_DOUT_XOR_MSK

/****************** Bit definition for CRC_STAT register ************************/

#define  CRC_STAT_FAIL_POS      8U
#define  CRC_STAT_FAIL_MSK      BIT(CRC_STAT_FAIL_POS)
#define  CRC_STAT_FAIL          CRC_STAT_FAIL_MSK

#define  CRC_STAT_EMPTY_POS     2U
#define  CRC_STAT_EMPTY_MSK     BIT(CRC_STAT_EMPTY_POS)
#define  CRC_STAT_EMPTY         CRC_STAT_EMPTY_MSK

#define  CRC_STAT_BUSY_POS      1U
#define  CRC_STAT_BUSY_MSK      BIT(CRC_STAT_BUSY_POS)
#define  CRC_STAT_BUSY          CRC_STAT_BUSY_MSK

#define  CRC_STAT_DONE_POS      0U
#define  CRC_STAT_DONE_MSK      BIT(CRC_STAT_DONE_POS)
#define  CRC_STAT_DONE          CRC_STAT_DONE_MSK

typedef struct
{
    __IO uint32_t   INIT;       /* 0x000 CRC_INIT       CRC Iintial Value Register  */
    __IO uint32_t   POLY;       /* 0x004 CRC_POLY       CRC Polynomial Register     */
    __IO uint32_t   DATA;       /* 0x008 CRC_DATA       CRC Input Data Register     */
    __IO uint32_t   COMP;       /* 0x00C CRC_COMP       CRC Compare Data Register   */
    __IO uint32_t   REMA;       /* 0x010 CRC_REMA       CRC Remainder Register      */
    __IO uint32_t   CON;        /* 0x014 CRC_CTRL       CRC Control Register        */
    __I  uint32_t   DOUT;       /* 0x018 CRC_DOUT       CRC Output Data Register    */
    __I  uint32_t   DOUT_XOR;   /* 0x01C CRC_DOUT_XOR   CRC Output Data Register    */
    __I  uint32_t   STAT;       /* 0x020 CRC_STA        CRC Status Register         */
} CRC_TypeDef;





#endif
