/**********************************************************************************
 *
 * @file    reg_aes.h
 * @brief   AES Head File
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

#ifndef __AES_H__
#define __AES_H__


/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/

/*  Support for anonymous structures and unions.  */
////#pragma anon_unions

/****************** Bit definition for AES_CON register ************************/

#define  AES_CON_READY_POS      22U
#define  AES_CON_READY_MSK      BIT(AES_CON_READY_POS)
#define  AES_CON_READY          AES_CON_READY_MSK

#define  AES_CON_OT_DMA_ST_POS  21U
#define  AES_CON_OT_DMA_ST_MSK  BIT(AES_CON_OT_DMA_ST_POS)
#define  AES_CON_OT_DMA_ST      AES_CON_OT_DMA_ST_MSK

#define  AES_CON_IT_DMA_ST_POS  20U
#define  AES_CON_IT_DMA_ST_MSK  BIT(AES_CON_IT_DMA_ST_POS)
#define  AES_CON_IT_DMA_ST      AES_CON_IT_DMA_ST_MSK

#define  AES_CON_OT_DEPTH_POSS  18U
#define  AES_CON_OT_DEPTH_POSE  19U
#define  AES_CON_OT_DEPTH_MSK   BITS(AES_CON_OT_DEPTH_POSS,AES_CON_OT_DEPTH_POSE)
#define  AES_CON_OT_DEPTH       AES_CON_OT_DEPTH_MSK

#define  AES_CON_IT_DEPTH_POSS  16U
#define  AES_CON_IT_DEPTH_POSE  17U
#define  AES_CON_IT_DEPTH_MSK   BITS(AES_CON_IT_DEPTH_POSS,AES_CON_IT_DEPTH_POSE)
#define  AES_CON_IT_DEPTH       AES_CON_IT_DEPTH_MSK

#define  AES_CON_RE_INIT_POS    8U
#define  AES_CON_RE_INIT_MSK    BIT(AES_CON_RE_INIT_POS)
#define  AES_CON_RE_INIT        AES_CON_RE_INIT_MSK

#define  AES_CON_DMA_EN_POSS    6U
#define  AES_CON_DMA_EN_POSE    7U
#define  AES_CON_DMA_EN_MSK     BITS(AES_CON_DMA_EN_POSS,AES_CON_DMA_EN_POSE)
#define  AES_CON_DMA_EN         AES_CON_DMA_EN_MSK

#define  AES_CON_BL_POSS        3U
#define  AES_CON_BL_POSE        5U
#define  AES_CON_BL_MSK         BITS(AES_CON_BL_POSS,AES_CON_BL_POSE)
#define  AES_CON_BL             AES_CON_BL_MSK

#define  AES_CON_REV_POS        2U
#define  AES_CON_REV_MSK        BIT(AES_CON_REV_POS)
#define  AES_CON_REV            AES_CON_REV_MSK

#define  AES_CON_MODE_POS       1U
#define  AES_CON_MODE_MSK       BIT(AES_CON_MODE_POS)
#define  AES_CON_MODE           AES_CON_MODE_MSK

#define  AES_CON_START_POS      0U
#define  AES_CON_START_MSK      BIT(AES_CON_START_POS)
#define  AES_CON_START          AES_CON_START_MSK

/****************** Bit definition for AES_IER register ************************/

#define  AES_IER_DEC_POS  1U
#define  AES_IER_DEC_MSK  BIT(AES_IER_DEC_POS)
#define  AES_IER_DEC      AES_IER_DEC_MSK

#define  AES_IER_ENC_POS  0U
#define  AES_IER_ENC_MSK  BIT(AES_IER_ENC_POS)
#define  AES_IER_ENC      AES_IER_ENC_MSK

/****************** Bit definition for AES_IDR register ************************/

#define  AES_IDR_DEC_POS  1U
#define  AES_IDR_DEC_MSK  BIT(AES_IDR_DEC_POS)
#define  AES_IDR_DEC      AES_IDR_DEC_MSK

#define  AES_IDR_ENC_POS  0U
#define  AES_IDR_ENC_MSK  BIT(AES_IDR_ENC_POS)
#define  AES_IDR_ENC      AES_IDR_ENC_MSK

/****************** Bit definition for AES_IVS register ************************/

#define  AES_IVS_DEC_POS  1U
#define  AES_IVS_DEC_MSK  BIT(AES_IVS_DEC_POS)
#define  AES_IVS_DEC      AES_IVS_DEC_MSK

#define  AES_IVS_ENC_POS  0U
#define  AES_IVS_ENC_MSK  BIT(AES_IVS_ENC_POS)
#define  AES_IVS_ENC      AES_IVS_ENC_MSK

/****************** Bit definition for AES_RIF register ************************/

#define  AES_RIF_DEC_POS  1U
#define  AES_RIF_DEC_MSK  BIT(AES_RIF_DEC_POS)
#define  AES_RIF_DEC      AES_RIF_DEC_MSK

#define  AES_RIF_ENC_POS  0U
#define  AES_RIF_ENC_MSK  BIT(AES_RIF_ENC_POS)
#define  AES_RIF_ENC      AES_RIF_ENC_MSK

/****************** Bit definition for AES_IFM register ************************/

#define  AES_IFM_DEC_POS  1U
#define  AES_IFM_DEC_MSK  BIT(AES_IFM_DEC_POS)
#define  AES_IFM_DEC      AES_IFM_DEC_MSK

#define  AES_IFM_ENC_POS  0U
#define  AES_IFM_ENC_MSK  BIT(AES_IFM_ENC_POS)
#define  AES_IFM_ENC      AES_IFM_ENC_MSK

/****************** Bit definition for AES_ICR register ************************/

#define  AES_ICR_DEC_POS  1U
#define  AES_ICR_DEC_MSK  BIT(AES_ICR_DEC_POS)
#define  AES_ICR_DEC      AES_ICR_DEC_MSK

#define  AES_ICR_ENC_POS  0U
#define  AES_ICR_ENC_MSK  BIT(AES_ICR_ENC_POS)
#define  AES_ICR_ENC      AES_ICR_ENC_MSK

/****************** Bit definition for AES_DIO register ************************/

#define  AES_DIO_DIO_POSS   0U
#define  AES_DIO_DIO_POSE   31U
#define  AES_DIO_DIO_MSK    BITS(AES_DIO_DIO_POSS,AES_DIO_DIO_POSE)
#define  AES_DIO_DIO        AES_DIO_DIO_MSK

/****************** Bit definition for AES_KEY0 register ************************/

#define  AES_KEY0_KEY0_POSS     0U
#define  AES_KEY0_KEY0_POSE     31U
#define  AES_KEY0_KEY0_MSK      BITS(AES_KEY0_KEY0_POSS,AES_KEY0_KEY0_POSE)
#define  AES_KEY0_KEY0          AES_KEY0_KEY0_MSK

/****************** Bit definition for AES_KEY1 register ************************/

#define  AES_KEY1_KEY1_POSS     0U
#define  AES_KEY1_KEY1_POSE     31U
#define  AES_KEY1_KEY1_MSK      BITS(AES_KEY1_KEY1_POSS,AES_KEY1_KEY1_POSE)
#define  AES_KEY1_KEY1          AES_KEY1_KEY1_MSK

/****************** Bit definition for AES_KEY2 register ************************/

#define  AES_KEY2_KEY2_POSS     0U
#define  AES_KEY2_KEY2_POSE     31U
#define  AES_KEY2_KEY2_MSK      BITS(AES_KEY2_KEY2_POSS,AES_KEY2_KEY2_POSE)
#define  AES_KEY2_KEY2          AES_KEY2_KEY2_MSK

/****************** Bit definition for AES_KEY3 register ************************/

#define  AES_KEY3_KEY3_POSS     0U
#define  AES_KEY3_KEY3_POSE     31U
#define  AES_KEY3_KEY3_MSK      BITS(AES_KEY3_KEY3_POSS,AES_KEY3_KEY3_POSE)
#define  AES_KEY3_KEY3          AES_KEY3_KEY3_MSK

/****************** Bit definition for AES_IV0 register ************************/

#define  AES_IV0_IV0_POSS   0U
#define  AES_IV0_IV0_POSE   31U
#define  AES_IV0_IV0_MSK    BITS(AES_IV0_IV0_POSS,AES_IV0_IV0_POSE)
#define  AES_IV0_IV0        AES_IV0_IV0_MSK

/****************** Bit definition for AES_IV1 register ************************/

#define  AES_IV1_IV1_POSS   0U
#define  AES_IV1_IV1_POSE   31U
#define  AES_IV1_IV1_MSK    BITS(AES_IV1_IV1_POSS,AES_IV1_IV1_POSE)
#define  AES_IV1_IV1        AES_IV1_IV1_MSK

/****************** Bit definition for AES_IV2 register ************************/

#define  AES_IV2_IV2_POSS   0U
#define  AES_IV2_IV2_POSE   31U
#define  AES_IV2_IV2_MSK    BITS(AES_IV2_IV2_POSS,AES_IV2_IV2_POSE)
#define  AES_IV2_IV2        AES_IV2_IV2_MSK

/****************** Bit definition for AES_IV3 register ************************/

#define  AES_IV3_IV3_POSS   0U
#define  AES_IV3_IV3_POSE   31U
#define  AES_IV3_IV3_MSK    BITS(AES_IV3_IV3_POSS,AES_IV3_IV3_POSE)
#define  AES_IV3_IV3        AES_IV3_IV3_MSK

typedef struct
{
    __IO uint32_t      CON ;  /* 0x000 AES_CON    AES Control Register                      */
    __O  uint32_t      IER;   /* 0x004 AES_IER    AES Interrupt Enable Register             */
    __O  uint32_t      IDR;   /* 0x008 AES_IDR    AES Interrupt Disable Register            */
    __I  uint32_t      IVS;   /* 0x00C AES_IVS    AES Interrupt Valid Status Register       */
    __I  uint32_t      RIF;   /* 0x010 AES_RIF    AES Raw Interrupt Flag Status Register    */
    __I  uint32_t      IFM;   /* 0x014 AES_IFM    AES Interrupt Flag Masked Register        */
    __O  uint32_t      ICR;   /* 0x018 AES_ICR    AES Interrupt Clear Register              */
    __IO uint32_t      DIO;   /* 0x01C AES_DIO    AES 128-bit Input/Output Data Register    */
    __IO uint32_t      KEY0;  /* 0x020 AES_KEY0   AES 128-bit Keyword Register 0            */
    __IO uint32_t      KEY1;  /* 0x024 AES_KEY1   AES 128-bit Keyword Register 1            */
    __IO uint32_t      KEY2;  /* 0x028 AES_KEY2   AES 128-bit Keyword Register 2            */
    __IO uint32_t      KEY3;  /* 0x02C AES_KEY3   AES 128-bit Keyword Register 3            */
    uint32_t RESERVED0[4] ;
    __IO uint32_t      IV0;   /* 0x040 AES_IV0    AES 128-bit Initial Vector Register 0     */
    __IO uint32_t      IV1;   /* 0x044 AES_IV1    AES 128-bit Initial Vector Register 1     */
    __IO uint32_t      IV2;   /* 0x048 AES_IV2    AES 128-bit Initial Vector Register 2     */
    __IO uint32_t      IV3;   /* 0x04C AES_IV3    AES 128-bit Initial Vector Register 3     */
} AES_TypeDef;

#endif
