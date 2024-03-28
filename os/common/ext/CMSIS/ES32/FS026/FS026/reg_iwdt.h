/**********************************************************************************
 *
 * @file    reg_iwdt.h
 * @brief   IWDT Head File
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

#ifndef __IWDT_H__
#define __IWDT_H__


/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/

/*  Support for anonymous structures and unions.  */
////#pragma anon_unions

/****************** Bit definition for IWDT_BKKR register ************************/

# define  IWDT_BKKR_KEY_POSS 0U
# define  IWDT_BKKR_KEY_POSE 15U
# define  IWDT_BKKR_KEY_MSK  BITS(IWDT_BKKR_KEY_POSS, IWDT_BKKR_KEY_POSE)
# define  IWDT_BKKR_KEY      IWDT_BKKR_KEY_MSK

/****************** Bit definition for IWDT_BKPR register ************************/

# define  IWDT_BKPR_PR_POSS 0U
# define  IWDT_BKPR_PR_POSE 2U
# define  IWDT_BKPR_PR_MSK  BITS(IWDT_BKPR_PR_POSS, IWDT_BKPR_PR_POSE)
# define  IWDT_BKPR_PR      IWDT_BKPR_PR_MSK

/****************** Bit definition for IWDT_BKRLR register ************************/

# define  IWDT_BKRLR_RL_POSS 0U
# define  IWDT_BKRLR_RL_POSE 11U
# define  IWDT_BKRLR_RL_MSK  BITS(IWDT_BKRLR_RL_POSS, IWDT_BKRLR_RL_POSE)
# define  IWDT_BKRLR_RL      IWDT_BKRLR_RL_MSK

/****************** Bit definition for IWDT_BKFR register ************************/

# define  IWDT_BKFR_BUSY_POS 15U
# define  IWDT_BKFR_BUSY_MSK BIT(IWDT_BKFR_BUSY_POS)
# define  IWDT_BKFR_BUSY     IWDT_BKFR_BUSY_MSK

/****************** Bit definition for IWDT_BKWINR register ************************/

# define  IWDT_BKWINR_WIN_POSS 0U
# define  IWDT_BKWINR_WIN_POSE 11U
# define  IWDT_BKWINR_WIN_MSK  BITS(IWDT_BKWINR_WIN_POSS, IWDT_BKWINR_WIN_POSE)
# define  IWDT_BKWINR_WIN      IWDT_BKWINR_WIN_MSK

/****************** Bit definition for IWDT_BKSR register ************************/

# define  IWDT_BKSR_CNT_POSS 0U
# define  IWDT_BKSR_CNT_POSE 11U
# define  IWDT_BKSR_CNT_MSK  BITS(IWDT_BKSR_CNT_POSS, IWDT_BKSR_CNT_POSE)
# define  IWDT_BKSR_CNT      IWDT_BKSR_CNT_MSK

typedef struct
{
    __IO uint32_t RESERVED0[32];            // 0x000-0x07c
    __O  uint32_t BKKR;                     // 0x080
    __IO uint32_t BKPR;                     // 0x084
    __IO uint32_t BKRLR;                    // 0x088
    __I  uint32_t BKFR;                     // 0x08c
    __IO uint32_t BKWINR;                   // 0x090
    __I  uint32_t BKSR;                     // 0x094
} IWDT_TypeDef;


#endif
