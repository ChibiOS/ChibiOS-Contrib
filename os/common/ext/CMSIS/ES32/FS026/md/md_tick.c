/**********************************************************************************
 *
 * @file    md_tick.c
 * @brief   md_tick C file
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov  2021    Ginger          the first version
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

/* Includes -------------------------------------------------------------------*/
#include "md_rcu.h"
#include "md_tick.h"
#include "md_calc.h"
/** @addtogroup Micro_Driver
  * @{
  */

#if defined (TICK)

/** @addtogroup TICK TICK
  * @brief TICK micro driver
  * @{
  */

/* Private types --------------------------------------------------------------*/
/* Private constants ----------------------------------------------------------*/
/* Private macros -------------------------------------------------------------*/

/* Private function prototypes ------------------------------------------------*/

#define  CALCON  0

/* Private variables ----------------------------------------------------------*/
/** @defgroup MD_TICK_Private_Variables TICK Private Variables
  * @{
  */
static  uint32_t  TICKms;
static  uint32_t  TICK100us;
static  uint32_t  TICK10us;

/**
  * @} MD_TICK_Private_Variables
  */
/* Public functions -----------------------------------------------------------*/
/** @defgroup MD_TICK_Public_Functions TICK Public Functions
  * @{
  */

/**
  * @brief  Tick Initialization
  * @note   This function set the maximun load and enable TICK counter
  * @note   This function also calculate ms, 100us ans 10us counter
  * @param  clksrc
            @arg @ref MD_SYSTICK_CLKSRC_HCLK_DIV8
            @arg @ref MD_SYSTICK_CLKSRC_HCLK
  * @retval  None
  */
void  md_tick_init(uint8_t clksrc)
{
    uint32_t tick_source;

    if (clksrc)
        tick_source = SystemFrequency_AHBClk;
    else
        tick_source = SystemFrequency_AHBClk / 8;

#if  CALCON
    CALC->DIVDR = tick_source;
    CALC->DIVSR = 1000;
    TICKms = CALC->DIVQR;
    CALC->DIVSR = 10000;
    TICK100us = CALC->DIVQR;
    CALC->DIVSR = 100000;
    TICK10us = CALC->DIVQR;
#else
    TICKms = tick_source / 1000;
    TICK100us = tick_source / 10000;
    TICK10us = tick_source / 100000;
#endif

    md_tick_set_rvr_reload(TICK, ((1 << 24) - 1));  /*  Maximun ReLoad  */
    md_tick_set_cvr_current(TICK, 0);               /*  Reset CVR  */
    md_tick_set_csr_clksrc(TICK, clksrc);           /*  MCU Clock  */
    md_tick_enable_csr_enable(TICK);                /*  Counter Enable  */
}

/**
  * @brief   Retrive the TICK counter and converted to millisecond
  * @param   None
  * @retval  The ms value converted by TICK counter
  */
uint32_t  md_tick_get_mscnt(void)
{
#if  CALCON
    CALC->DIVDR = md_tick_get_cvr_current();
    CALC->DIVSR = TICKms;
    return (HDIV->DIVQR);
#else
    return (md_tick_get_cvr_current(TICK) / TICKms);
#endif
}

/**
  * @brief   Retrive the TICK counter and converted to 100 microseconds
  * @param   None
  * @retval  The 100 microseconds value converted by TICK counter
  */
uint32_t  md_tick_get_100uscnt(void)
{
#if  CALCON
    CALC->DIVDR = md_tick_get_cvr_current();
    CALC->DIVSR = TICK100us;
    return (HDIV->DIVQR);
#else
    return (md_tick_get_cvr_current(TICK) / TICK100us);
#endif
}

/**
  * @brief   Retrive the TICK counter and converted to 10 microseconds
  * @param   None
  * @retval  The 10 microseconds value converted by TICK counter
  */
uint32_t  md_tick_get_10uscnt(void)
{
#if  CALCON
    CALC->DIVDR = md_tick_get_cvr_current();
    CALC->DIVSR = TICK10us;
    return (HDIV->DIVQR);
#else
    return (md_tick_get_cvr_current(TICK) / TICK10us);
#endif
}

/**
  * @brief  Delay based on milliseconds
  * @param  Unit The number of ms in one delay period
  * @param  msCnt The counter of delay period
  * @note   user can use the function to set the delay time, Delay time = Unit*msCnt (ms)
  * @retVal None
  */
void  md_tick_waitms(uint8_t Unit, uint16_t msCnt)
{
    uint32_t  mstime;

    mstime = (1 << 24) - (Unit * TICKms);

    while (msCnt--)
    {
        md_tick_set_cvr_current(TICK, ((1 << 24) - 1)); /*  Reset CVR  */

        while (md_tick_get_cvr_current(TICK) > mstime);
    }
}

/**
  * @brief  Delay based on 100 microseconds
  * @param  Unit The number of 100 microseconds in one delay period
  * @param  msCnt The counter of delay period
  * @note   user can use the function to set the delay time, Delay time = Unit*usCnt (100us)
  * @etVal  None
  */
void  md_tick_wait100us(uint16_t Unit, uint16_t usCnt)
{
    uint32_t  ustime;

    ustime = (1 << 24) - (Unit * TICK100us);

    while (usCnt--)
    {
        md_tick_set_cvr_current(TICK, ((1 << 24) - 1)); /*  Reset CVR  */

        while (md_tick_get_cvr_current(TICK) > ustime);
    }
}

/**
  * @brief  Delay based on 10 microseconds
  * @param  Unit The number of 10 microseconds in one delay period
  * @param  msCnt The counter of delay period
  * @note   user can use the function to set the delay time, Delay time = Unit*usCnt (10us)
  * @etVal  None
  */
void  md_tick_wait10us(uint16_t Unit, uint16_t usCnt)
{
    uint32_t  ustime;

    ustime = (1 << 24) - (Unit * TICK10us);

    while (usCnt--)
    {
        md_tick_set_cvr_current(TICK, ((1 << 24) - 1)); /*  Reset CVR  */

        while (md_tick_get_cvr_current(TICK) > ustime);
    }
}


/**
  * @} MD_TICK_Public_Functions
  */

/**
  * @} TICK
  */
#endif

/**
  * @} Micro_Driver
  */

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
