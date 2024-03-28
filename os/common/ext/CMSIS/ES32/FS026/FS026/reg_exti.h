/**********************************************************************************
 *
 * @file    reg_exti.h
 * @brief   EXTI Head File
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

#ifndef __EXTI_H__
#define __EXTI_H__


/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/

/*  Support for anonymous structures and unions.  */
////#pragma anon_unions

/****************** Bit definition for EXTI_IER register ************************/

# define    EXTI_IER_WAKEUP_POS 21U
# define    EXTI_IER_WAKEUP_MSK BIT(EXTI_IER_WAKEUP_POS)
# define    EXTI_IER_WAKEUP     EXTI_IER_WAKEUP_MSK

# define    EXTI_IER_LVD_POS 20U
# define    EXTI_IER_LVD_MSK BIT(EXTI_IER_LVD_POS)
# define    EXTI_IER_LVD     EXTI_IER_LVD_MSK

# define    EXTI_IER_CMP2_POS 17U
# define    EXTI_IER_CMP2_MSK BIT(EXTI_IER_CMP2_POS)
# define    EXTI_IER_CMP2     EXTI_IER_CMP2_MSK

# define    EXTI_IER_CMP1_POS 16U
# define    EXTI_IER_CMP1_MSK BIT(EXTI_IER_CMP1_POS)
# define    EXTI_IER_CMP1     EXTI_IER_CMP1_MSK

# define    EXTI_IER_GPIOy_POSS 0U
# define    EXTI_IER_GPIOy_POSE 15U
# define    EXTI_IER_GPIOy_MSK  BITS(EXTI_IER_GPIOy_POSS, EXTI_IER_GPIOy_POSE)
# define    EXTI_IER_GPIOy      EXTI_IER_GPIOy_MSK

/****************** Bit definition for EXTI_IDR register ************************/

# define    EXTI_IDR_WAKEUP_POS 21U
# define    EXTI_IDR_WAKEUP_MSK BIT(EXTI_IDR_WAKEUP_POS)
# define    EXTI_IDR_WAKEUP     EXTI_IDR_WAKEUP_MSK

# define    EXTI_IDR_LVD_POS 20U
# define    EXTI_IDR_LVD_MSK BIT(EXTI_IDR_LVD_POS)
# define    EXTI_IDR_LVD     EXTI_IDR_LVD_MSK

# define    EXTI_IDR_CMP2_POS 17U
# define    EXTI_IDR_CMP2_MSK BIT(EXTI_IDR_CMP2_POS)
# define    EXTI_IDR_CMP2     EXTI_IDR_CMP2_MSK

# define    EXTI_IDR_CMP1_POS 16U
# define    EXTI_IDR_CMP1_MSK BIT(EXTI_IDR_CMP1_POS)
# define    EXTI_IDR_CMP1     EXTI_IDR_CMP1_MSK

# define    EXTI_IDR_GPIOy_POSS 0U
# define    EXTI_IDR_GPIOy_POSE 15U
# define    EXTI_IDR_GPIOy_MSK  BITS(EXTI_IDR_GPIOy_POSS, EXTI_IDR_GPIOy_POSE)
# define    EXTI_IDR_GPIOy      EXTI_IDR_GPIOy_MSK

/****************** Bit definition for EXTI_IVS register ************************/

# define    EXTI_IVS_WAKEUP_POS 21U
# define    EXTI_IVS_WAKEUP_MSK BIT(EXTI_IVS_WAKEUP_POS)
# define    EXTI_IVS_WAKEUP     EXTI_IVS_WAKEUP_MSK

# define    EXTI_IVS_LVD_POS 20U
# define    EXTI_IVS_LVD_MSK BIT(EXTI_IVS_LVD_POS)
# define    EXTI_IVS_LVD     EXTI_IVS_LVD_MSK

# define    EXTI_IVS_CMP2_POS 17U
# define    EXTI_IVS_CMP2_MSK BIT(EXTI_IVS_CMP2_POS)
# define    EXTI_IVS_CMP2     EXTI_IVS_CMP2_MSK

# define    EXTI_IVS_CMP1_POS 16U
# define    EXTI_IVS_CMP1_MSK BIT(EXTI_IVS_CMP1_POS)
# define    EXTI_IVS_CMP1     EXTI_IVS_CMP1_MSK

# define    EXTI_IVS_GPIOy_POSS 0U
# define    EXTI_IVS_GPIOy_POSE 15U
# define    EXTI_IVS_GPIOy_MSK  BITS(EXTI_IVS_GPIOy_POSS, EXTI_IVS_GPIOy_POSE)
# define    EXTI_IVS_GPIOy      EXTI_IVS_GPIOy_MSK

/****************** Bit definition for EXTI_RIF register ************************/

# define    EXTI_RIF_WAKEUP_POS 21U
# define    EXTI_RIF_WAKEUP_MSK BIT(EXTI_RIF_WAKEUP_POS)
# define    EXTI_RIF_WAKEUP     EXTI_RIF_WAKEUP_MSK

# define    EXTI_RIF_LVD_POS 20U
# define    EXTI_RIF_LVD_MSK BIT(EXTI_RIF_LVD_POS)
# define    EXTI_RIF_LVD     EXTI_RIF_LVD_MSK

# define    EXTI_RIF_CMP2_POS 17U
# define    EXTI_RIF_CMP2_MSK BIT(EXTI_RIF_CMP2_POS)
# define    EXTI_RIF_CMP2     EXTI_RIF_CMP2_MSK

# define    EXTI_RIF_CMP1_POS 16U
# define    EXTI_RIF_CMP1_MSK BIT(EXTI_RIF_CMP1_POS)
# define    EXTI_RIF_CMP1     EXTI_RIF_CMP1_MSK

# define    EXTI_RIF_GPIOy_POSS 0U
# define    EXTI_RIF_GPIOy_POSE 15U
# define    EXTI_RIF_GPIOy_MSK  BITS(EXTI_RIF_GPIOy_POSS, EXTI_RIF_GPIOy_POSE)
# define    EXTI_RIF_GPIOy      EXTI_RIF_GPIOy_MSK

/****************** Bit definition for EXTI_IFM register ************************/

# define    EXTI_IFM_WAKEUP_POS 21U
# define    EXTI_IFM_WAKEUP_MSK BIT(EXTI_IFM_WAKEUP_POS)
# define    EXTI_IFM_WAKEUP     EXTI_IFM_WAKEUP_MSK

# define    EXTI_IFM_LVD_POS 20U
# define    EXTI_IFM_LVD_MSK BIT(EXTI_IFM_LVD_POS)
# define    EXTI_IFM_LVD     EXTI_IFM_LVD_MSK

# define    EXTI_IFM_CMP2_POS 17U
# define    EXTI_IFM_CMP2_MSK BIT(EXTI_IFM_CMP2_POS)
# define    EXTI_IFM_CMP2     EXTI_IFM_CMP2_MSK

# define    EXTI_IFM_CMP1_POS 16U
# define    EXTI_IFM_CMP1_MSK BIT(EXTI_IFM_CMP1_POS)
# define    EXTI_IFM_CMP1     EXTI_IFM_CMP1_MSK

# define    EXTI_IFM_GPIOy_POSS 0U
# define    EXTI_IFM_GPIOy_POSE 15U
# define    EXTI_IFM_GPIOy_MSK  BITS(EXTI_IFM_GPIOy_POSS, EXTI_IFM_GPIOy_POSE)
# define    EXTI_IFM_GPIOy      EXTI_IFM_GPIOy_MSK

/****************** Bit definition for EXTI_ICR register ************************/

# define    EXTI_ICR_WAKEUP_POS 21U
# define    EXTI_ICR_WAKEUP_MSK BIT(EXTI_ICR_WAKEUP_POS)
# define    EXTI_ICR_WAKEUP     EXTI_ICR_WAKEUP_MSK

# define    EXTI_ICR_LVD_POS 20U
# define    EXTI_ICR_LVD_MSK BIT(EXTI_ICR_LVD_POS)
# define    EXTI_ICR_LVD     EXTI_ICR_LVD_MSK

# define    EXTI_ICR_CMP2_POS 17U
# define    EXTI_ICR_CMP2_MSK BIT(EXTI_ICR_CMP2_POS)
# define    EXTI_ICR_CMP2     EXTI_ICR_CMP2_MSK

# define    EXTI_ICR_CMP1_POS 16U
# define    EXTI_ICR_CMP1_MSK BIT(EXTI_ICR_CMP1_POS)
# define    EXTI_ICR_CMP1     EXTI_ICR_CMP1_MSK

# define    EXTI_ICR_GPIOy_POSS 0U
# define    EXTI_ICR_GPIOy_POSE 15U
# define    EXTI_ICR_GPIOy_MSK  BITS(EXTI_ICR_GPIOy_POSS, EXTI_ICR_GPIOy_POSE)
# define    EXTI_ICR_GPIOy      EXTI_ICR_GPIOy_MSK

/****************** Bit definition for EXTI_RTS register ************************/

//# define  EXTI_RTS_RTSy_POSS 20U
//# define  EXTI_RTS_RTSy_POSE 21U
//# define  EXTI_RTS_RTSy_MSK  BITS(EXTI_RTS_RTSy_POSS, EXTI_RTS_RTSy_POSE)
//# define  EXTI_RTS_RTSy      EXTI_RTS_RTSy_MSK

# define    EXTI_RTS_RTSy_POSS  0U
# define    EXTI_RTS_RTSy_POSE  21U
# define    EXTI_RTS_RTSy_MSK   BITS(EXTI_RTS_RTSy_POSS, EXTI_RTS_RTSy_POSE)
# define    EXTI_RTS_RTSy       EXTI_RTS_RTSy_MSK

/****************** Bit definition for EXTI_FTS register ************************/

//# define  EXTI_FTS_FTSy_POSS 20U
//# define  EXTI_FTS_FTSy_POSE 21U
//# define  EXTI_FTS_FTSy_MSK  BITS(EXTI_FTS_FTSy_POSS, EXTI_FTS_FTSy_POSE)
//# define  EXTI_FTS_FTSy      EXTI_FTS_FTSy_MSK

# define    EXTI_FTS_FTSy_POSS 0U
# define    EXTI_FTS_FTSy_POSE 21U
# define    EXTI_FTS_FTSy_MSK  BITS(EXTI_FTS_FTSy_POSS, EXTI_FTS_FTSy_POSE)
# define    EXTI_FTS_FTSy      EXTI_FTS_FTSy_MSK

/****************** Bit definition for EXTI_SWI register ************************/

//# define  EXTI_SWI_SWIy_POSS 20U
//# define  EXTI_SWI_SWIy_POSE 21U
//# define  EXTI_SWI_SWIy_MSK  BITS(EXTI_SWI_SWIy_POSS, EXTI_SWI_SWIy_POSE)
//# define  EXTI_SWI_SWIy      EXTI_SWI_SWIy_MSK

# define    EXTI_SWI_SWIy_POSS 0U
# define    EXTI_SWI_SWIy_POSE 21U
# define    EXTI_SWI_SWIy_MSK  BITS(EXTI_SWI_SWIy_POSS, EXTI_SWI_SWIy_POSE)
# define    EXTI_SWI_SWIy      EXTI_SWI_SWIy_MSK

/****************** Bit definition for EXTI_ADTE1 register ************************/

# define    EXTI_ADTE1_ADTEy_POSS 0U
# define    EXTI_ADTE1_ADTEy_POSE 17U
# define    EXTI_ADTE1_ADTEy_MSK  BITS(EXTI_ADTE1_ADTEy_POSS, EXTI_ADTE1_ADTEy_POSE)
# define    EXTI_ADTE1_ADTEy      EXTI_ADTE1_ADTEy_MSK

/****************** Bit definition for EXTI_ADTE2 register ************************/

# define    EXTI_ADTE2_ADTEy_POSS 0U
# define    EXTI_ADTE2_ADTEy_POSE 17U
# define    EXTI_ADTE2_ADTEy_MSK  BITS(EXTI_ADTE2_ADTEy_POSS, EXTI_ADTE2_ADTEy_POSE)
# define    EXTI_ADTE2_ADTEy      EXTI_ADTE2_ADTEy_MSK

/****************** Bit definition for EXTI_DB register ************************/

//# define  EXTI_DB_DBENy_POSS 20U
//# define  EXTI_DB_DBENy_POSE 21U
//# define  EXTI_DB_DBENy_MSK  BITS(EXTI_DB_DBENy_POSS, EXTI_DB_DBENy_POSE)
//# define  EXTI_DB_DBENy      EXTI_DB_DBENy_MSK

# define    EXTI_DB_DBENy_POSS 0U
# define    EXTI_DB_DBENy_POSE 21U
# define    EXTI_DB_DBENy_MSK  BITS(EXTI_DB_DBENy_POSS, EXTI_DB_DBENy_POSE)
# define    EXTI_DB_DBENy      EXTI_DB_DBENy_MSK

/****************** Bit definition for EXTI_DBC register ************************/

# define    EXTI_DBC_DBPRE_POSS 8U
# define    EXTI_DBC_DBPRE_POSE 15U
# define    EXTI_DBC_DBPRE_MSK  BITS(EXTI_DBC_DBPRE_POSS, EXTI_DBC_DBPRE_POSE)
# define    EXTI_DBC_DBPRE      EXTI_DBC_DBPRE_MSK

# define    EXTI_DBC_DBCNT_POSS 0U
# define    EXTI_DBC_DBCNT_POSE 2U
# define    EXTI_DBC_DBCNT_MSK  BITS(EXTI_DBC_DBCNT_POSS, EXTI_DBC_DBCNT_POSE)
# define    EXTI_DBC_DBCNT      EXTI_DBC_DBCNT_MSK

/****************** Bit definition for EXTI_ICFG1 register ************************/

# define    EXTI_ICFG1_EXTIy_POSS 0U
# define    EXTI_ICFG1_EXTIy_POSE 31U
# define    EXTI_ICFG1_EXTIy_MSK  BITS(EXTI_ICFG1_EXTIy_POSS, EXTI_ICFG1_EXTIy_POSE)
# define    EXTI_ICFG1_EXTIy      EXTI_ICFG1_EXTIy_MSK

/****************** Bit definition for EXTI_ICFG2 register ************************/

# define    EXTI_ICFG2_EXTIy_POSS 0U
# define    EXTI_ICFG2_EXTIy_POSE 31U
# define    EXTI_ICFG2_EXTIy_MSK  BITS(EXTI_ICFG2_EXTIy_POSS, EXTI_ICFG2_EXTIy_POSE)
# define    EXTI_ICFG2_EXTIy      EXTI_ICFG2_EXTIy_MSK

typedef struct
{
    __O  uint32_t IER;                      // 0x000
    __O  uint32_t IDR;                      // 0x004
    __I  uint32_t IVS;                      // 0x008
    __I  uint32_t RIF;                      // 0x00c
    __I  uint32_t IFM;                      // 0x010
    __O  uint32_t ICR;                      // 0x014
    __IO uint32_t RTS;                      // 0x018
    __IO uint32_t FTS;                      // 0x01c
    __IO uint32_t SWI;                      // 0x020
    __IO uint32_t ADTE1;                    // 0x024
    __IO uint32_t ADTE2;                    // 0x028
    __IO uint32_t DB;                       // 0x02c
    __IO uint32_t DBC;                      // 0x030
    __IO uint32_t ICFG1;                    // 0x034
    __IO uint32_t ICFG2;                    // 0x038
} EXTI_TypeDef;


#endif
