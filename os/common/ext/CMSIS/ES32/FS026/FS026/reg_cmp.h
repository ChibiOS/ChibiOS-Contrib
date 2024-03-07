/**********************************************************************************
 *
 * @file    reg_cmp.h
 * @brief   CMP Head File
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

#ifndef __CMP_H__
#define __CMP_H__


/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/

/*  Support for anonymous structures and unions.  */
////#pragma anon_unions

/****************** Bit definition for CMP_CFG1 register ************************/

# define  CMP_CFG1_LOCK_POS 31U
# define  CMP_CFG1_LOCK_MSK BIT(CMP_CFG1_LOCK_POS)
# define  CMP_CFG1_LOCK     CMP_CFG1_LOCK_MSK

# define  CMP_CFG1_VALUE_POS 30U
# define  CMP_CFG1_VALUE_MSK BIT(CMP_CFG1_VALUE_POS)
# define  CMP_CFG1_VALUE     CMP_CFG1_VALUE_MSK

# define  CMP_CFG1_BLANKSEL_POSS 20U
# define  CMP_CFG1_BLANKSEL_POSE 24U
# define  CMP_CFG1_BLANKSEL_MSK  BITS(CMP_CFG1_BLANKSEL_POSS, CMP_CFG1_BLANKSEL_POSE)
# define  CMP_CFG1_BLANKSEL      CMP_CFG1_BLANKSEL_MSK

# define  CMP_CFG1_FILT_POS 18U
# define  CMP_CFG1_FILT_MSK BIT(CMP_CFG1_FILT_POS)
# define  CMP_CFG1_FILT     CMP_CFG1_FILT_MSK

# define  CMP_CFG1_HYST_POS 16U
# define  CMP_CFG1_HYST_MSK BIT(CMP_CFG1_HYST_POS)
# define  CMP_CFG1_HYST     CMP_CFG1_HYST_MSK

# define  CMP_CFG1_POLARITY_POS 15U
# define  CMP_CFG1_POLARITY_MSK BIT(CMP_CFG1_POLARITY_POS)
# define  CMP_CFG1_POLARITY     CMP_CFG1_POLARITY_MSK

# define  CMP_CFG1_OUTSEL_POSS 12U
# define  CMP_CFG1_OUTSEL_POSE 14U
# define  CMP_CFG1_OUTSEL_MSK  BITS(CMP_CFG1_OUTSEL_POSS, CMP_CFG1_OUTSEL_POSE)
# define  CMP_CFG1_OUTSEL      CMP_CFG1_OUTSEL_MSK

# define  CMP_CFG1_INNSEL_POSS 4U
# define  CMP_CFG1_INNSEL_POSE 6U
# define  CMP_CFG1_INNSEL_MSK  BITS(CMP_CFG1_INNSEL_POSS, CMP_CFG1_INNSEL_POSE)
# define  CMP_CFG1_INNSEL      CMP_CFG1_INNSEL_MSK

# define  CMP_CFG1_EN_POS 0U
# define  CMP_CFG1_EN_MSK BIT(CMP_CFG1_EN_POS)
# define  CMP_CFG1_EN     CMP_CFG1_EN_MSK

/****************** Bit definition for CMP_CFG2 register ************************/

# define  CMP_CFG2_LOCK_POS 31U
# define  CMP_CFG2_LOCK_MSK BIT(CMP_CFG2_LOCK_POS)
# define  CMP_CFG2_LOCK     CMP_CFG2_LOCK_MSK

# define  CMP_CFG2_VALUE_POS 30U
# define  CMP_CFG2_VALUE_MSK BIT(CMP_CFG2_VALUE_POS)
# define  CMP_CFG2_VALUE     CMP_CFG2_VALUE_MSK

# define  CMP_CFG2_BLANKSEL_POSS 20U
# define  CMP_CFG2_BLANKSEL_POSE 24U
# define  CMP_CFG2_BLANKSEL_MSK  BITS(CMP_CFG2_BLANKSEL_POSS, CMP_CFG2_BLANKSEL_POSE)
# define  CMP_CFG2_BLANKSEL      CMP_CFG2_BLANKSEL_MSK

# define  CMP_CFG2_FILT_POS 18U
# define  CMP_CFG2_FILT_MSK BIT(CMP_CFG2_FILT_POS)
# define  CMP_CFG2_FILT     CMP_CFG2_FILT_MSK

# define  CMP_CFG2_HYST_POS 16U
# define  CMP_CFG2_HYST_MSK BIT(CMP_CFG2_HYST_POS)
# define  CMP_CFG2_HYST     CMP_CFG2_HYST_MSK

# define  CMP_CFG2_POLARITY_POS 15U
# define  CMP_CFG2_POLARITY_MSK BIT(CMP_CFG2_POLARITY_POS)
# define  CMP_CFG2_POLARITY     CMP_CFG2_POLARITY_MSK

# define  CMP_CFG2_OUTSEL_POSS 12U
# define  CMP_CFG2_OUTSEL_POSE 14U
# define  CMP_CFG2_OUTSEL_MSK  BITS(CMP_CFG2_OUTSEL_POSS, CMP_CFG2_OUTSEL_POSE)
# define  CMP_CFG2_OUTSEL      CMP_CFG2_OUTSEL_MSK

# define  CMP_CFG2_WINOUT_POS 9U
# define  CMP_CFG2_WINOUT_MSK BIT(CMP_CFG2_WINOUT_POS)
# define  CMP_CFG2_WINOUT     CMP_CFG2_WINOUT_MSK

# define  CMP_CFG2_WINMODE_POS 8U
# define  CMP_CFG2_WINMODE_MSK BIT(CMP_CFG2_WINMODE_POS)
# define  CMP_CFG2_WINMODE     CMP_CFG2_WINMODE_MSK

# define  CMP_CFG2_INNSEL_POSS 4U
# define  CMP_CFG2_INNSEL_POSE 6U
# define  CMP_CFG2_INNSEL_MSK  BITS(CMP_CFG2_INNSEL_POSS, CMP_CFG2_INNSEL_POSE)
# define  CMP_CFG2_INNSEL      CMP_CFG2_INNSEL_MSK

# define  CMP_CFG2_EN_POS 0U
# define  CMP_CFG2_EN_MSK BIT(CMP_CFG2_EN_POS)
# define  CMP_CFG2_EN     CMP_CFG2_EN_MSK

/****************** Bit definition for CMP_TRIM1 register ************************/

# define  CMP_TRIM1_TRIM_SEL_POS 31U
# define  CMP_TRIM1_TRIM_SEL_MSK BIT(CMP_TRIM1_TRIM_SEL_POS)
# define  CMP_TRIM1_TRIM_SEL     CMP_TRIM1_TRIM_SEL_MSK

# define  CMP_TRIM1_CAL_STAT_POS 30U
# define  CMP_TRIM1_CAL_STAT_MSK BIT(CMP_TRIM1_CAL_STAT_POS)
# define  CMP_TRIM1_CAL_STAT     CMP_TRIM1_CAL_STAT_MSK

# define  CMP_TRIM1_INSW_STAT_POS 29U
# define  CMP_TRIM1_INSW_STAT_MSK BIT(CMP_TRIM1_INSW_STAT_POS)
# define  CMP_TRIM1_INSW_STAT     CMP_TRIM1_INSW_STAT_MSK

# define  CMP_TRIM1_CAL_EN_POSS 8U
# define  CMP_TRIM1_CAL_EN_POSE 15U
# define  CMP_TRIM1_CAL_EN_MSK  BITS(CMP_TRIM1_CAL_EN_POSS, CMP_TRIM1_CAL_EN_POSE)
# define  CMP_TRIM1_CAL_EN      CMP_TRIM1_CAL_EN_MSK

# define  CMP_TRIM1_INSW_EN_POSS 0U
# define  CMP_TRIM1_INSW_EN_POSE 7U
# define  CMP_TRIM1_INSW_EN_MSK  BITS(CMP_TRIM1_INSW_EN_POSS, CMP_TRIM1_INSW_EN_POSE)
# define  CMP_TRIM1_INSW_EN      CMP_TRIM1_INSW_EN_MSK

/****************** Bit definition for CMP_TRIM2 register ************************/

# define  CMP_TRIM2_OPT_TRIM2_POSS 24U
# define  CMP_TRIM2_OPT_TRIM2_POSE 31U
# define  CMP_TRIM2_OPT_TRIM2_MSK  BITS(CMP_TRIM2_OPT_TRIM2_POSS, CMP_TRIM2_OPT_TRIM2_POSE)
# define  CMP_TRIM2_OPT_TRIM2      CMP_TRIM2_OPT_TRIM2_MSK

# define  CMP_TRIM2_REG_TRIM2_POSS 16U
# define  CMP_TRIM2_REG_TRIM2_POSE 23U
# define  CMP_TRIM2_REG_TRIM2_MSK  BITS(CMP_TRIM2_REG_TRIM2_POSS, CMP_TRIM2_REG_TRIM2_POSE)
# define  CMP_TRIM2_REG_TRIM2      CMP_TRIM2_REG_TRIM2_MSK

# define  CMP_TRIM2_OPT_TRIM1_POSS 8U
# define  CMP_TRIM2_OPT_TRIM1_POSE 15U
# define  CMP_TRIM2_OPT_TRIM1_MSK  BITS(CMP_TRIM2_OPT_TRIM1_POSS, CMP_TRIM2_OPT_TRIM1_POSE)
# define  CMP_TRIM2_OPT_TRIM1      CMP_TRIM2_OPT_TRIM1_MSK

# define  CMP_TRIM2_REG_TRIM1_POSS 0U
# define  CMP_TRIM2_REG_TRIM1_POSE 7U
# define  CMP_TRIM2_REG_TRIM1_MSK  BITS(CMP_TRIM2_REG_TRIM1_POSS, CMP_TRIM2_REG_TRIM1_POSE)
# define  CMP_TRIM2_REG_TRIM1      CMP_TRIM2_REG_TRIM1_MSK

typedef struct
{
    __IO uint32_t CFG1;                     // 0x000
    __IO uint32_t CFG2;                     // 0x004
    __IO uint32_t TRIM1;                    // 0x008
    __IO uint32_t TRIM2;                    // 0x00c
} CMP_TypeDef;


#endif
