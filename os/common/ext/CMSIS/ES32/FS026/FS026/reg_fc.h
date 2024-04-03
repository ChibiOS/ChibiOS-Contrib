/**********************************************************************************
 *
 * @file    reg_fc.h
 * @brief   FC Head File
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

#ifndef __FC_H__
#define __FC_H__


/******************************************************************************/
/*                              设备特殊寄存器结构定义                        */
/******************************************************************************/

/*   允许匿名结构和匿名联合    */
/* ////#pragma anon_unions */

/****************** Bit definition for FC_CMD register ************************/

#define  FC_CMD_CMD_POSS  0U
#define  FC_CMD_CMD_POSE  7U
#define  FC_CMD_CMD_MSK   BITS(FC_CMD_CMD_POSS,FC_CMD_CMD_POSE)
#define  FC_CMD_CMD       FC_CMD_CMD_MSK

/****************** Bit definition for FC_PA register ************************/

#define  FC_PA_PCNT_POSS  25U
#define  FC_PA_PCNT_POSE  31U
#define  FC_PA_PCNT_MSK   BITS(FC_PA_PCNT_POSS,FC_PA_PCNT_POSE)
#define  FC_PA_PCNT       FC_PA_PCNT_MSK

#define  FC_PA_IFREN_POS  24U
#define  FC_PA_IFREN_MSK  BIT(FC_PA_IFREN_POS)
#define  FC_PA_IFREN      FC_PA_IFREN_MSK

#define  FC_PA_PA_POSS  0U
#define  FC_PA_PA_POSE  23U
#define  FC_PA_PA_MSK  BITS(FC_PA_PA_POSS,FC_PA_PA_POSE)
#define  FC_PA_PA      FC_PA_PA_MSK

/****************** Bit definition for FC_PLD register ************************/

#define  FC_PLD_PLD_POSS  0U
#define  FC_PLD_PLD_POSE  31U
#define  FC_PLD_PLD_MSK   BITS(FC_PLD_PLD_POSS,FC_PLD_PLD_POSE)
#define  FC_PLD_PLD       FC_PLD_PLD_MSK

/****************** Bit definition for FC_CTL register ************************/

#define  FC_CTL_FCSLEEP_POS  10U
#define  FC_CTL_FCSLEEP_MSK  BIT(FC_CTL_FCSLEEP_POS)
#define  FC_CTL_FCSLEEP      FC_CTL_FCSLEEP_MSK

#define  FC_CTL_PFEN_POS  8U
#define  FC_CTL_PFEN_MSK  BIT(FC_CTL_PFEN_POS)
#define  FC_CTL_PFEN      FC_CTL_PFEN_MSK

#define  FC_CTL_OPRLD_POSS  4U
#define  FC_CTL_OPRLD_POSE  7U
#define  FC_CTL_OPRLD_MSK   BITS(FC_CTL_OPRLD_POSS, FC_CTL_OPRLD_POSE)
#define  FC_CTL_OPRLD       FC_CTL_OPRLD_MSK

#define  FC_CTL_WAIT_POSS  0U
#define  FC_CTL_WAIT_POSE  1U
#define  FC_CTL_WAIT_MSK   BITS(FC_CTL_WAIT_POSS, FC_CTL_WAIT_POSE)
#define  FC_CTL_WAIT       FC_CTL_WAIT_MSK

/****************** Bit definition for FC_STA register ************************/

#define  FC_STA_OPRLDLOOP_POSS  8U
#define  FC_STA_OPRLDLOOP_POSE  11U
#define  FC_STA_OPRLDLOOP_MSK   BITS(FC_STA_OPRLDLOOP_POSS, FC_STA_OPRLDLOOP_POSE)
#define  FC_STA_OPRLDLOOP       FC_STA_OPRLDLOOP_MSK

#define  FC_STA_PRTAREARD_POS  7U
#define  FC_STA_PRTAREARD_MSK  BIT(FC_STA_PRTAREARD_POS)
#define  FC_STA_PRTAREARD      FC_STA_PRTAREARD_MSK

#define  FC_STA_PRTAREAWR_POS  6U
#define  FC_STA_PRTAREAWR_MSK  BIT(FC_STA_PRTAREAWR_POS)
#define  FC_STA_PRTAREAWR      FC_STA_PRTAREAWR_MSK

#define  FC_STA_CMDULK_POS  5U
#define  FC_STA_CMDULK_MSK  BIT(FC_STA_CMDULK_POS)
#define  FC_STA_CMDULK      FC_STA_CMDULK_MSK

#define  FC_STA_FCBUSY_POS  4U
#define  FC_STA_FCBUSY_MSK  BIT(FC_STA_FCBUSY_POS)
#define  FC_STA_FCBUSY      FC_STA_FCBUSY_MSK

#define  FC_STA_WPDIS_POS  3U
#define  FC_STA_WPDIS_MSK  BIT(FC_STA_WPDIS_POS)
#define  FC_STA_WPDIS      FC_STA_WPDIS_MSK

#define  FC_STA_RPLV_POSS  1U
#define  FC_STA_RPLV_POSE  2U
#define  FC_STA_RPLV_MSK   BITS(FC_STA_RPLV_POSS, FC_STA_RPLV_POSE)
#define  FC_STA_RPLV       FC_STA_RPLV_MSK

#define  FC_STA_UCRPDIS_POS  0U
#define  FC_STA_UCRPDIS_MSK  BIT(FC_STA_UCRPDIS_POS)
#define  FC_STA_UCRPDIS      FC_STA_UCRPDIS_MSK

/****************** Bit definition for FC_UPL register ************************/

#define  FC_UPL_UPL_POSS  0U
#define  FC_UPL_UPL_POSE  31U
#define  FC_UPL_UPL_MSK   BITS(FC_UPL_UPL_POSS,FC_UPL_UPL_POSE)
#define  FC_UPL_UPL       FC_UPL_UPL_MSK

/****************** Bit definition for FC_UPH register ************************/

#define  FC_UPH_UPH_POSS  0U
#define  FC_UPH_UPH_POSE  31U
#define  FC_UPH_UPH_MSK   BITS(FC_UPH_UPH_POSS,FC_UPH_UPH_POSE)
#define  FC_UPH_UPH       FC_UPH_UPH_MSK

/****************** Bit definition for FC_UL register ************************/

#define  FC_UL_UL_POSS  0U
#define  FC_UL_UL_POSE  31U
#define  FC_UL_UL_MSK   BITS(FC_UL_UL_POSS,FC_UL_UL_POSE)
#define  FC_UL_UL       FC_UL_UL_MSK

/****************** Bit definition for FC_UCRPL register ************************/

#define  FC_UCRPL_UCRPL_POSS  0U
#define  FC_UCRPL_UCRPL_POSE  31U
#define  FC_UCRPL_UCRPL_MSK   BITS(FC_UCRPL_UCRPL_POSS,FC_UCRPL_UCRPL_POSE)
#define  FC_UCRPL_UCRPL       FC_UCRPL_UCRPL_MSK

/****************** Bit definition for FC_UCRPH register ************************/

#define  FC_UCRPH_UCRPH_POSS  0U
#define  FC_UCRPH_UCRPH_POSE  31U
#define  FC_UCRPH_UCRPH_MSK   BITS(FC_UCRPH_UCRPH_POSS,FC_UCRPH_UCRPH_POSE)
#define  FC_UCRPH_UCRPH       FC_UCRPH_UCRPH_MSK

/****************** Bit definition for FC_RP register ************************/

#define  FC_RP_RP_POSS  0U
#define  FC_RP_RP_POSE  31U
#define  FC_RP_RP_MSK   BITS(FC_RP_RP_POSS,FC_RP_RP_POSE)
#define  FC_RP_RP       FC_RP_RP_MSK

/****************** Bit definition for FC_WPL register ************************/

#define  FC_WPL_WPL_POSS  0U
#define  FC_WPL_WPL_POSE  31U
#define  FC_WPL_WPL_MSK   BITS(FC_WPL_WPL_POSS,FC_WPL_WPL_POSE)
#define  FC_WPL_WPL       FC_WPL_WPL_MSK

/****************** Bit definition for FC_WPH register ************************/

#define  FC_WPH_WPH_POSS  0U
#define  FC_WPH_WPH_POSE  31U
#define  FC_WPH_WPH_MSK   BITS(FC_WPH_WPH_POSS,FC_WPH_WPH_POSE)
#define  FC_WPH_WPH       FC_WPH_WPH_MSK

/****************** Bit definition for FC_REMAP register ************************/

#define  FC_REMAP_BOOTBYP_POSS  16U
#define  FC_REMAP_BOOTBYP_POSE  23U
#define  FC_REMAP_BOOTBYP_MSK   BITS(FC_REMAP_BOOTBYP_POSS,FC_REMAP_BOOTBYP_POSE)
#define  FC_REMAP_BOOTBYP       FC_REMAP_BOOTBYP_MSK

#define  FC_REMAP_SELECT_POSS  8U
#define  FC_REMAP_SELECT_POSE  15U
#define  FC_REMAP_SELECT_MSK   BITS(FC_REMAP_SELECT_POSS,FC_REMAP_SELECT_POSE)
#define  FC_REMAP_SELECT       FC_REMAP_SELECT_MSK

#define  FC_REMAP_SEFBASE_POSS  0U
#define  FC_REMAP_SEFBASE_POSE  7U
#define  FC_REMAP_SEFBASE_MSK   BITS(FC_REMAP_SEFBASE_POSS,FC_REMAP_SEFBASE_POSE)
#define  FC_REMAP_SEFBASE       FC_REMAP_SEFBASE_MSK

typedef struct
{
    __IO uint32_t CMD;
    __IO uint32_t PA;
    __IO uint32_t PLD;
    uint32_t RESERVED0 ;
    __IO uint32_t CTL;
    __IO uint32_t STAT;
    uint32_t RESERVED1[2] ;
    __IO uint32_t UPL;
    __IO uint32_t UPH;
    __IO uint32_t UL;
    uint32_t RESERVED2[5] ;
    __I uint32_t UCRPL;
    __I uint32_t UCRPH;
    __I uint32_t RP;
    __I uint32_t WPL;
    __I uint32_t WPH;
    __I uint32_t REMAP;
} FC_TypeDef;





#endif
