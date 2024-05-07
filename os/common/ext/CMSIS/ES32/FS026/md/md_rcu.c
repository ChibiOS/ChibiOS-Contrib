/**********************************************************************************
 *
 * @file    md_rcu.c
 * @brief   md_rcu C file
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov   2021   Ginger          the first version
 *          24 Mar   2022   AE Team         Modify MD Driver
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
#include "system_fs026.h"
#include "md_rcu.h"
#include "md_fc.h"
#include "md_tick.h"
/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup RCU RCU
  * @brief RCU micro driver
  * @{
  */

/* Private types --------------------------------------------------------------*/
/* Private variables ----------------------------------------------------------*/
static uint32_t  TICKms;
static uint32_t  TICK100us;
static uint32_t  TICK10us;
/* Private constants ----------------------------------------------------------*/
/* Private macros -------------------------------------------------------------*/
#define TICK_CLOCKSOURCE 4000000

/** @defgroup MD_RCU_Private_Macros RCU Private Macros
  * @{
  */

/**
  * @} MD_RCU_Private_Macros
  */

/* Private function prototypes ------------------------------------------------*/

/* Public functions -----------------------------------------------------------*/
/** @addtogroup MD_RCU_Public_Functions RCU Public Functions
  * @{
  */
void  md_tick_init_rcu(void)
{
    TICKms = TICK_CLOCKSOURCE / 1000;
    TICK100us = TICK_CLOCKSOURCE / 10000;
    TICK10us = TICK_CLOCKSOURCE / 100000;

    md_tick_set_rvr_reload(TICK, ((1 << 24) - 1));            /*  Maximun ReLoad  */
    md_tick_set_cvr_current(TICK, 0);                         /*  Reset CVR  */
    md_tick_set_csr_clksrc(TICK, MD_SYSTICK_CLKSRC_HCLK);     /*  MCU Clock  */
    md_tick_enable_csr_enable(TICK);                          /*  Counter Enable  */
}

void  md_tick_waitms_rcu(uint8_t Unit, uint16_t msCnt)
{
    uint32_t  mstime;

    mstime = (1 << 24) - (Unit * TICKms);

    while (msCnt--)
    {
        md_tick_set_cvr_current(TICK, ((1 << 24) - 1)); /*  Reset CVR  */

        while (md_tick_get_cvr_current(TICK) > mstime);
    }
}

void  md_tick_wait100us_rcu(uint16_t Unit, uint16_t usCnt)
{
    uint32_t  ustime;

    ustime = (1 << 24) - (Unit * TICK100us);

    while (usCnt--)
    {
        md_tick_set_cvr_current(TICK, ((1 << 24) - 1)); /*  Reset CVR  */

        while (md_tick_get_cvr_current(TICK) > ustime);
    }
}

void  md_tick_wait10us_rcu(uint16_t Unit, uint16_t usCnt)
{
    uint32_t  ustime;

    ustime = (1 << 24) - (Unit * TICK10us);

    while (usCnt--)
    {
        md_tick_set_cvr_current(TICK, ((1 << 24) - 1)); /*  Reset CVR  */

        while (md_tick_get_cvr_current(TICK) > ustime);
    }
}

void md_rcu_check_hosc_ready(void)
{
    md_tick_init_rcu();

    md_tick_waitms_rcu(1, 1);

    while (md_rcu_is_active_flag_hosc_ready(RCU) == MD_RCU_HOSCRDY_NOT_READY)
    {
        md_rcu_disable_hosc(RCU);

        md_tick_waitms_rcu(1, 1);

        md_rcu_enable_hosc(RCU);

        md_tick_waitms_rcu(1, 1);

    }
}

/**
  * @} MD_RCU_Check_Hosc_Ready
  */

/** @addtogroup MD_RCU_Init
  * @{
  */
void md_rcu_sys_init(RCU_TypeDef *rcu, md_rcu_init_typedef *RCU_InitStruct)
{
    uint32_t    PLL0_Frequency;
    uint32_t    PLL0_Ref_Frequency;
    uint32_t    Current_Frequency;
    double      fration;

    md_fc_set_read_latency(FC, MD_FC_WAIT_MORE_THAN_72Mhz);

    if (RCU_InitStruct->HS_Clock & RCU_CON_PLL0ON)
        md_rcu_enable_pll0(rcu);

    if (RCU_InitStruct->HS_Clock & RCU_CON_HRC48ON)
        md_rcu_enable_hrc48(rcu);

    if (RCU_InitStruct->HS_Clock & RCU_CON_HOSCON)
        md_rcu_enable_hosc(rcu);

    if (RCU_InitStruct->HS_Clock & RCU_CON_HRCON)
        md_rcu_enable_hrc(rcu);

    if (RCU_InitStruct->LS_Clock & RCU_LCON_LOSCON)
        md_rcu_enable_losc(rcu);

    if (RCU_InitStruct->LS_Clock & RCU_LCON_LRCON)
        md_rcu_enable_lrc(rcu);

    //make sure HOSC CLK Ready
    if ((RCU_InitStruct->HS_Clock & RCU_CON_HOSCON))
        md_rcu_check_hosc_ready();

    while (
        ((RCU->CON  & RCU_CON_PLL0ON) && (md_rcu_is_active_flag_pll0_ready(rcu)  == MD_RCU_PLL0RDY_NOT_READY))
        || ((RCU->CON  & RCU_CON_HRC48ON) && (md_rcu_is_active_flag_hrc48_ready(rcu) == MD_RCU_HRC48RDY_NOT_READY))
        || ((RCU->CON  & RCU_CON_HOSCON) && (md_rcu_is_active_flag_hosc_ready(rcu)  == MD_RCU_HOSCRDY_NOT_READY))
        || ((RCU->CON  & RCU_CON_HRCON) && (md_rcu_is_active_flag_hrc_ready(rcu)   == MD_RCU_HRCRDY_NOT_READY))
        || ((RCU->LCON & RCU_LCON_LRCON) && (md_rcu_is_active_flag_lrc_ready(rcu)   == MD_RCU_LRCRDY_NOT_READY))
        || ((RCU->LCON & RCU_LCON_LOSCON) && (md_rcu_is_active_flag_losc_ready(rcu)  == MD_RCU_LOSCRDY_NOT_READY))
    );

    md_rcu_set_mco_div(rcu, RCU_InitStruct->Mpre);
    md_rcu_set_mco_source(rcu, RCU_InitStruct->Msw);
    
    switch ((RCU_InitStruct->PllSrc))
    {
        case MD_RCU_PLLSRC_HRC :
            PLL0_Ref_Frequency = (uint32_t)(__HRC);
            break;

        case MD_RCU_PLLSRC_HOSC :
            PLL0_Ref_Frequency = (uint32_t)(__HOSC);
            break;

        case MD_RCU_PLLSRC_HRC48 :
            PLL0_Ref_Frequency = (uint32_t)(__HRC48);
            break;

        default :
            PLL0_Ref_Frequency = (uint32_t)(__HRC);
            break;
    }

    PLL0_Ref_Frequency /= (md_rcu_get_pll_prediv(rcu) + 1);
    fration = (double)md_rcu_get_pll0_fn(rcu) + ((double)md_rcu_get_pll0_fk(rcu) / (1 << 19));
    PLL0_Frequency = (uint32_t)(PLL0_Ref_Frequency * fration / (1 << (md_rcu_get_pll0_fm(rcu) + 3)));

    /*
    Determine whether it is a PLL that needs to be switched. 
    If it is a PLL, it is a frequency increase buffering process. 
    Otherwise, if it is not a PLL, it is a frequency decrease buffering process.
    */
    if(RCU_InitStruct->Sw==MD_RCU_SW_SYSCLK_PLL0)
    {
        /*
        PLL frequency rise buffer processing, the trigger environment is when it is necessary to 
        switch to the PLL frequency greater than or equal to 48M, if the current or set HCLK prescaler is 1, 
        the HCLK prescaler will be set to 2 first and then the system frequency will be switched. 
        After the switch is completed Will wait for 10us before resetting the HCLK prescaler.
        */
        if((PLL0_Frequency>=48000000) && 
           ((md_rcu_get_hclk_div(RCU)==MD_RCU_HPRE_SYSCLK_DIV_1)||
            (RCU_InitStruct->Hpre==MD_RCU_HPRE_SYSCLK_DIV_1)))
        {
            SystemFrequency_AHBClk = PLL0_Frequency>>1;
            md_tick_init(MD_SYSTICK_CLKSRC_HCLK);
            md_rcu_set_hclk_div(rcu,MD_RCU_HPRE_SYSCLK_DIV_2);
            md_rcu_set_system_clock_source(rcu, RCU_InitStruct->Sw);
            md_tick_wait10us(1,1);
        }
    }
    else
    {
        /*
        PLL frequency reduction buffer processing, the triggering environment is when it is not 
        necessary to switch the PLL frequency and the current system frequency is higher than 48M, 
        the HCLK prescaler will first be set to 2 to reduce the HCLK speed, and then the system frequency 
        will be switched to a low frequency after the reduction is completed. Finally reset the 
        HCLK prescaler.
        */
        Current_Frequency = md_rcu_get_current_system_frequency(RCU)*1000000;
        if(Current_Frequency>=48000000)
        {
            SystemFrequency_AHBClk = Current_Frequency>>1;
            md_tick_init(MD_SYSTICK_CLKSRC_HCLK);
            md_rcu_set_hclk_div(rcu,MD_RCU_HPRE_SYSCLK_DIV_2);
            md_tick_wait10us(1,1);
        }
    }
    
    md_rcu_set_system_clock_source(rcu, RCU_InitStruct->Sw);
    
    md_rcu_set_hclk_div(rcu, RCU_InitStruct->Hpre);
    
    md_rcu_set_pclk_div(rcu, RCU_InitStruct->Ppre);
    
    switch (md_rcu_get_current_system_clock(rcu)) /* System clock switch(SYSCLK) */
    {

        case MD_RCU_SWS_SYSCLK_HRC: /*================= HRC selected as system clock*/
            SystemCoreClock = (uint32_t)(__HRC);
            break;

        case MD_RCU_SWS_SYSCLK_HOSC: /*================= HOSC selected as system clock*/
            SystemCoreClock = (uint32_t)(__HOSC);
            break;

        case MD_RCU_SWS_SYSCLK_PLL0: /*================= PLL selected as system clock*/
            SystemCoreClock = PLL0_Frequency;
            break;

        case MD_RCU_SWS_SYSCLK_HRC48: /*================= HRC48 selected as system clock*/
            SystemCoreClock = (uint32_t)(__HRC48);
            break;

        default:
            SystemCoreClock = (uint32_t)(__HRC);
            break;
    }

    /* Core Frequency */
    SystemFrequency_SysClk = SystemCoreClock;

    /* AHB Frequency */
    if ((md_rcu_get_hclk_div(rcu) >= 12))
        SystemFrequency_AHBClk = SystemCoreClock >> ((md_rcu_get_hclk_div(rcu) & 0x07) + 2);
    else if ((md_rcu_get_hclk_div(rcu)) >= 8)
        SystemFrequency_AHBClk = SystemCoreClock >> ((md_rcu_get_hclk_div(rcu) & 0x07) + 1);
    else
        SystemFrequency_AHBClk = SystemCoreClock;

    /* APB Frequency */
    if (md_rcu_get_pclk_div(rcu))
        SystemFrequency_APBClk = SystemFrequency_AHBClk >> ((md_rcu_get_pclk_div(rcu) & 0x03) + 1);
    else
        SystemFrequency_APBClk = SystemFrequency_AHBClk;

    if (RCU_InitStruct->HS_Clock & RCU_CON_CSSON)
        md_rcu_enable_hosc_css(rcu);
    else
        md_rcu_disable_hosc_css(rcu);

    md_rcu_set_current_system_frequency(RCU, (SystemFrequency_SysClk / 1000000));

    if (SystemFrequency_AHBClk / 1000000 > 72)
        md_fc_set_read_latency(FC, MD_FC_WAIT_MORE_THAN_72Mhz);
    else if (SystemFrequency_AHBClk / 1000000 > 48)
        md_fc_set_read_latency(FC, MD_FC_WAIT_BETWEEN_48MHz_AND_72Mhz);
    else if (SystemFrequency_AHBClk / 1000000 > 24)
        md_fc_set_read_latency(FC, MD_FC_WAIT_BETWEEN_24MHz_AND_48Mhz);
    else
        md_fc_set_read_latency(FC, MD_FC_WAIT_LESS_THAN_24MHz);

    if (!(RCU_InitStruct->HS_Clock & RCU_CON_PLL0ON))
        md_rcu_disable_pll0(rcu);

    if (!(RCU_InitStruct->HS_Clock & RCU_CON_HRC48ON))
        md_rcu_disable_hrc48(rcu);

    if (!(RCU_InitStruct->HS_Clock & RCU_CON_HOSCON))
        md_rcu_disable_hosc(rcu);

    if (!(RCU_InitStruct->HS_Clock & RCU_CON_HRCON))
        md_rcu_disable_hrc(rcu);

    if (!(RCU_InitStruct->LS_Clock & RCU_LCON_LOSCON))
        md_rcu_disable_losc(rcu);

    if (!(RCU_InitStruct->LS_Clock & RCU_LCON_LRCON))
        md_rcu_disable_lrc(rcu);

    md_tick_init(MD_SYSTICK_CLKSRC_HCLK);
}

/**
  * @} MD_RCU_Init
  */

/** @addtogroup MD_RCU_Pll0_Init
  * @{
  */
void md_rcu_pll0_init(RCU_TypeDef *rcu, md_rcu_init_typedef *RCU_InitStruct)
{
    uint32_t    fpllin;
    uint32_t    fvco;

    md_rcu_disable_pll0(rcu);

    while (md_rcu_is_active_flag_pll0_ready(rcu) == MD_RCU_PLL0RDY_READY);

    md_rcu_set_pll_source(rcu, RCU_InitStruct->PllSrc);

    switch ((RCU_InitStruct->PllSrc))
    {
        case MD_RCU_PLLSRC_HRC :
            fpllin = (uint32_t)(__HRC);
            break;

        case MD_RCU_PLLSRC_HOSC :
            fpllin = (uint32_t)(__HOSC);
            break;

        case MD_RCU_PLLSRC_HRC48 :
            fpllin = (uint32_t)(__HRC48);
            break;

        default :
            fpllin = (uint32_t)(__HRC);
            break;
    }

    md_rcu_set_pll_prediv(rcu, ((fpllin / __PLL0_CLKREF) - 1));

    if (RCU_InitStruct->Pllclk <= 72000000 && RCU_InitStruct->Pllclk >= 4000000)
    {
        if ((RCU_InitStruct->Pllclk / 1000000) >= 32)
            md_rcu_set_pll0_fm(rcu, MD_RCU_FM_PLL0_DIV_8);
        else if ((RCU_InitStruct->Pllclk / 1000000) >= 16)
            md_rcu_set_pll0_fm(rcu, MD_RCU_FM_PLL0_DIV_16);
        else if ((RCU_InitStruct->Pllclk / 1000000) >= 8)
            md_rcu_set_pll0_fm(rcu, MD_RCU_FM_PLL0_DIV_32);
        else
            md_rcu_set_pll0_fm(rcu, MD_RCU_FM_PLL0_DIV_64);

        fvco = RCU_InitStruct->Pllclk * (1 << (md_rcu_get_pll0_fm(rcu) + 3));

        md_rcu_set_pll0_fn(rcu, fvco / __PLL0_CLKREF);

        md_rcu_set_pll0_fk(rcu, (((long long)(fvco) << 19) / __PLL0_CLKREF) & 0x7FFFF);

        md_rcu_enable_pll0(rcu);

        while (md_rcu_is_active_flag_pll0_ready(rcu) == 0);
    }
}

/**
  * @} MD_RCU_Pll0_Init
  */

/** @addtogroup MD_RCU HRC/HRC48 Trim
  * @{
  */

void md_rcu_hrc_software_trim(RCU_TypeDef *rcu, uint8_t trim_value)
{
    md_rcu_set_hrctrim_source(rcu, MD_RCU_HRCSEL_HRCTRIM);
    md_rcu_set_hrctrim(rcu, trim_value);
}

void md_rcu_hrc_disable_software_trim(RCU_TypeDef *rcu)
{
    md_rcu_set_hrctrim_source(rcu, MD_RCU_HRCSEL_OPTIONBYTE);
}

void md_rcu_hrc48_software_trim(RCU_TypeDef *rcu, uint16_t trim_value)
{
    md_rcu_set_hrc48trim_source(rcu, MD_RCU_HRC48SEL_HRC48TRIM);
    md_rcu_set_hrc48trim(rcu, trim_value);
    md_rcu_trigger_hrc48trim_update(rcu);
}

void md_rcu_hrc48_disable_software_trim(RCU_TypeDef *rcu)
{
    md_rcu_set_hrc48trim_source(rcu, MD_RCU_HRC48SEL_OPTIONBYTE);
}

uint16_t md_rcu_get_hrc_option_trim_value(RCU_TypeDef *rcu)
{
    md_rcu_set_hrctrim_source(rcu, MD_RCU_HRCSEL_OPTIONBYTE);
    return md_rcu_get_hrctrim(rcu);
}

uint16_t md_rcu_get_hrc48_option_trim_value(RCU_TypeDef *rcu)
{
    md_rcu_set_hrc48trim_source(rcu, MD_RCU_HRC48SEL_OPTIONBYTE);
    return md_rcu_get_hrc48trim(rcu);
}
/**
  * @}
  */

/**
  * @} MD_RCU_Public_Functions
  */

/**
  * @} RCU
  */

/**
  * @} Micro_Driver
  */

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
