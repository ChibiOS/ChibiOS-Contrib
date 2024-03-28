/**********************************************************************************
 *
 * @file    reg_wwdt.h
 * @brief   WWDT Head File
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

#ifndef __WWDT_H__
#define __WWDT_H__


/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/

/*  Support for anonymous structures and unions.  */
////#pragma anon_unions

/****************** Bit definition for WWDT_CON register ************************/

# define  WWDT_CON_WDGA_POS 7U
# define  WWDT_CON_WDGA_MSK BIT(WWDT_CON_WDGA_POS)
# define  WWDT_CON_WDGA     WWDT_CON_WDGA_MSK

# define  WWDT_CON_T_POSS 0U
# define  WWDT_CON_T_POSE 6U
# define  WWDT_CON_T_MSK  BITS(WWDT_CON_T_POSS, WWDT_CON_T_POSE)
# define  WWDT_CON_T      WWDT_CON_T_MSK

/****************** Bit definition for WWDT_CFG register ************************/

# define  WWDT_CFG_WDGTB_POSS 7U
# define  WWDT_CFG_WDGTB_POSE 8U
# define  WWDT_CFG_WDGTB_MSK  BITS(WWDT_CFG_WDGTB_POSS, WWDT_CFG_WDGTB_POSE)
# define  WWDT_CFG_WDGTB      WWDT_CFG_WDGTB_MSK

# define  WWDT_CFG_W_POSS 0U
# define  WWDT_CFG_W_POSE 6U
# define  WWDT_CFG_W_MSK  BITS(WWDT_CFG_W_POSS, WWDT_CFG_W_POSE)
# define  WWDT_CFG_W      WWDT_CFG_W_MSK

/****************** Bit definition for WWDT_IER register ************************/

# define  WWDT_IER_EWI_POS 0U
# define  WWDT_IER_EWI_MSK BIT(WWDT_IER_EWI_POS)
# define  WWDT_IER_EWI      WWDT_IER_EWI_MSK

/****************** Bit definition for WWDT_IDR register ************************/

# define  WWDT_IDR_EWI_POS 0U
# define  WWDT_IDR_EWI_MSK BIT(WWDT_IDR_EWI_POS)
# define  WWDT_IDR_EWI      WWDT_IDR_EWI_MSK

/****************** Bit definition for WWDT_IVS register ************************/

# define  WWDT_IVS_EWI_POS 0U
# define  WWDT_IVS_EWI_MSK BIT(WWDT_IVS_EWI_POS)
# define  WWDT_IVS_EWI      WWDT_IVS_EWI_MSK

/****************** Bit definition for WWDT_RIF register ************************/

# define  WWDT_RIF_EWI_POS 0U
# define  WWDT_RIF_EWI_MSK BIT(WWDT_RIF_EWI_POS)
# define  WWDT_RIF_EWI      WWDT_RIF_EWI_MSK

/****************** Bit definition for WWDT_IFM register ************************/

# define  WWDT_IFM_EWI_POS 0U
# define  WWDT_IFM_EWI_MSK BIT(WWDT_IFM_EWI_POS)
# define  WWDT_IFM_EWI      WWDT_IFM_EWI_MSK

/****************** Bit definition for WWDT_ICR register ************************/

# define  WWDT_ICR_EWI_POS 0U
# define  WWDT_ICR_EWI_MSK BIT(WWDT_ICR_EWI_POS)
# define  WWDT_ICR_EWI      WWDT_ICR_EWI_MSK

typedef struct
{
    __IO uint32_t CON;                      // 0x000
    __IO uint32_t CFG;                      // 0x004
    __O  uint32_t IER;                      // 0x008
    __O  uint32_t IDR;                      // 0x00c
    __I  uint32_t IVS;                      // 0x010
    __I  uint32_t RIF;                      // 0x014
    __I  uint32_t IFM;                      // 0x018
    __O  uint32_t ICR;                      // 0x01c
} WWDT_TypeDef;


#endif
