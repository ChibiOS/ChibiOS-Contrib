/**********************************************************************************
 *
 * @file    reg_tick.h
 * @brief   TICK Head File
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

#ifndef __TICK_H__
#define __TICK_H__

/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/

/* ////#pragma anon_unions */

/****************** Bit definition for SYST_CSR register ************************/

#define SYST_CSR_ENABLE_POS  0U
#define SYST_CSR_ENABLE_MSK  BIT(SYST_CSR_ENABLE_POS)
#define SYST_CSR_ENABLE      SYST_CSR_ENABLE_MSK

#define SYST_CSR_TICKIE_POS 1U
#define SYST_CSR_TICKIE_MSK BIT(SYST_CSR_TICKIE_POS)
#define SYST_CSR_TICKIE     SYST_CSR_TICKIE_MSK

#define SYST_CSR_CLKSRC_POS 2U
#define SYST_CSR_CLKSRC_MSK BIT(SYST_CSR_CLKSRC_POS)
#define SYST_CSR_CLKSRC     SYST_CSR_CLKSRC_MSK

#define SYST_CSR_COUNT_POS 16U
#define SYST_CSR_COUNT_MSK BIT(SYST_CSR_COUNT_POS)
#define SYST_CSR_COUNT     SYST_CSR_COUNT_MSK

/****************** Bit definition for SYST_RVR register ************************/

#define SYST_RVR_RELOAD_POSS 0U
#define SYST_RVR_RELOAD_POSE 23U
#define SYST_RVR_RELOAD_MSK  BITS(SYST_RVR_RELOAD_POSS,SYST_RVR_RELOAD_POSE)
#define SYST_RVR_RELOAD      SYST_RVR_RELOAD_MSK

/****************** Bit definition for SYST_CVR register ************************/

#define SYST_CVR_CURRENT_POSS 0U
#define SYST_CVR_CURRENT_POSE 23U
#define SYST_CVR_CURRENT_MSK  BITS(SYST_CVR_CURRENT_POSS,SYST_CVR_CURRENT_POSE)
#define SYST_CVR_CURRENT      SYST_CVR_CURRENT_MSK

/*  TICK Register  */
#define  pTICK    TICK

/*  TICK CSR Register(TICK_CSR)  */
#define CSR_COUNTFLAG(x)  (x<<16)  /*  Indicates whether the counter has counted to 0 since the last read of this register
                    0 timer has not counted to 0
                    1 timer has counted to 0  */
#define CSR_CLKSOURCE(x)  (x<<2)  /*  Indicates the SysTick clock source:
                    0 SysTick uses the optional external reference clock
                    1 SysTick uses the processor clock  */
#define CSR_TICKINT(x)    (x<<1)  /*  Indicates whether counting to 0 causes the status of the SysTick exception to change to pending:
                    0 count to 0 does not affect the SysTick exception status
                    1 count to 0 changes the SysTick exception status to pending  */
#define CSR_ENABLE(x)    (x<<0)  /*  /Indicates the enabled status of the SysTick counter:
                    0 counter is disabled
                    1 counter is operating  */


/*  TICK RVR Register(TICK_RVR)  */
#define RVR_RELOAD(x)    (x<<0)  /*  The value to load into the SYST_CVR register when the counter reaches 0  */


/*  TICK CVR Register(TICK_CVR)  */
#define CVR_CURRENT(x)    (x<<0)  /*  Current counter value
                    This is the value of the counter at the time it is sampled  */

typedef struct
{
    __IO uint32_t   CSR;            /*  0x10, Control and Status  */
    __IO uint32_t   RVR;            /*  0x14, Reload Value  */
    __IO uint32_t   CVR;            /*  0x18, Current Value  */
} SYST_TypeDef;


#else
/* */
#endif
