/**********************************************************************************
 *
 * @file    reg_calc.h
 * @brief   CALC Head File
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

#ifndef __CALC_H__
#define __CALC_H__


/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/

/*  Support for anonymous structures and unions.  */
////#pragma anon_unions

/****************** Bit definition for CALC_DIVDR register ************************/

#define  CALC_DIVDR_DIVD_POSS  0U
#define  CALC_DIVDR_DIVD_POSE  31U
#define  CALC_DIVDR_DIVD_MSK   BITS(CALC_DIVDR_DIVD_POSS,CALC_DIVDR_DIVD_POSE)
#define  CALC_DIVDR_DIVD       CALC_DIVDR_DIVD_MSK

/****************** Bit definition for CALC_DIVSR register ************************/

#define  CALC_DIVSR_DIVS_POSS  0U
#define  CALC_DIVSR_DIVS_POSE  31U
#define  CALC_DIVSR_DIVS_MSK   BITS(CALC_DIVSR_DIVS_POSS,CALC_DIVSR_DIVS_POSE)
#define  CALC_DIVSR_DIVS       CALC_DIVSR_DIVS_MSK

/****************** Bit definition for CALC_DIVQR register ************************/

#define  CALC_DIVQR_DIVQ_POSS  0U
#define  CALC_DIVQR_DIVQ_POSE  31U
#define  CALC_DIVQR_DIVQ_MSK   BITS(CALC_DIVQR_DIVQ_POSS,CALC_DIVQR_DIVQ_POSE)
#define  CALC_DIVQR_DIVQ       CALC_DIVQR_DIVQ_MSK

/****************** Bit definition for CALC_DIVRR register ************************/

#define  CALC_DIVRR_DIVR_POSS  0U
#define  CALC_DIVRR_DIVR_POSE  31U
#define  CALC_DIVRR_DIVR_MSK   BITS(CALC_DIVRR_DIVR_POSS,CALC_DIVRR_DIVR_POSE)
#define  CALC_DIVRR_DIVR       CALC_DIVRR_DIVR_MSK

/****************** Bit definition for CALC_DIVCON register ************************/

#define  CALC_DIVCON_TRM_POS  1U
#define  CALC_DIVCON_TRM_MSK  BIT(CALC_DIVCON_TRM_POS)
#define  CALC_DIVCON_TRM      CALC_DIVCON_TRM_MSK

#define  CALC_DIVCON_SIGN_POS  0U
#define  CALC_DIVCON_SIGN_MSK  BIT(CALC_DIVCON_SIGN_POS)
#define  CALC_DIVCON_SIGN      CALC_DIVCON_SIGN_MSK

/****************** Bit definition for CALC_RDCND register ************************/

#define  CALC_RDCND_RADICAND_POSS  0U
#define  CALC_RDCND_RADICAND_POSE  31U
#define  CALC_RDCND_RADICAND_MSK   BITS(CALC_RDCND_RADICAND_POSS,CALC_RDCND_RADICAND_POSE)
#define  CALC_RDCND_RADICAND       CALC_RDCND_RADICAND_MSK

/****************** Bit definition for CALC_SQRTRES register ************************/

#define  CALC_SQRTRES_RESULT_POSS  0U
#define  CALC_SQRTRES_RESULT_POSE  15U
#define  CALC_SQRTRES_RESULT_MSK   BITS(CALC_SQRTRES_RESULT_POSS,CALC_SQRTRES_RESULT_POSE)
#define  CALC_SQRTRES_RESULT       CALC_SQRTRES_RESULT_MSK

/****************** Bit definition for CALC_STAT register ************************/

#define  CALC_STAT_DZ_POS  1U
#define  CALC_STAT_DZ_MSK  BIT(CALC_STAT_DZ_POS)
#define  CALC_STAT_DZ      CALC_STAT_DZ_MSK

#define  CALC_STAT_BUSY_POS  0U
#define  CALC_STAT_BUSY_MSK  BIT(CALC_STAT_BUSY_POS)
#define  CALC_STAT_BUSY      CALC_STAT_BUSY_MSK

typedef struct
{
    __IO uint32_t DIVDR;
    __IO uint32_t DIVSR;
    __I  uint32_t DIVQR;
    __I  uint32_t DIVRR;
    __IO uint32_t DIVCON;
    __IO uint32_t RDCND;
    __I  uint32_t SQRTRES;
    __IO uint32_t RESERVED0;
    __I  uint32_t STAT;
} CALC_TypeDef;

#endif
