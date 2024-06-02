/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio
              Copyright (C) 2020 Yaotian Feng

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    hal_lld.c
 * @brief   PLATFORM HAL subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */


#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
  * @brief update the value of SystemCoreClock after changing the system clock.
  */
unsigned int SystemCoreClock;
unsigned int SystemFrequency_SysClk;
unsigned int SystemFrequency_AHBClk;
unsigned int SystemFrequency_APBClk;
unsigned int HRC48Frequency;
unsigned int PLL0Frequency;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/
#if ES32_NO_INIT
__attribute__((weak)) void hal_lld_init(void)
{
    
}
#else
void HardFault_Handler(void)
{
    while(1);
}

const md_rcu_init_typedef rcu_initStruct =    /**< RCU init structure */
{
    MD_RCU_MPRE_MCO_DIV1,
    MD_RCU_MSW_MCO_DISABLE,
    ES32_PLL_SOURSE_SELECT,
    ES32_PLL_CLK_FREQ,
    ES32_BUS_DIV_PPRE,
    ES32_BUS_DIV_HPRE,
    ES32_SYSCLK_SOURSE_SELECT,
#if ES32_PLL_CLK_EN
#if ES32_HOSC_CLK_EN
    (RCU_CON_HRCON | RCU_CON_HRC48ON_MSK | RCU_CON_PLL0ON | RCU_CON_HOSCON),
#else
    (RCU_CON_HRCON | RCU_CON_HRC48ON_MSK | RCU_CON_PLL0ON),
#endif
#else
#if ES32_HOSC_CLK_EN
    (RCU_CON_HRCON | RCU_CON_HRC48ON_MSK | RCU_CON_HOSCON),
#else
    (RCU_CON_HRCON | RCU_CON_HRC48ON_MSK),
#endif
#endif
};

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void)
{
    __disable_irq();
#if ES32_PLL_CLK_EN
    md_rcu_pll0_init(RCU, (md_rcu_init_typedef*)(&rcu_initStruct));
#endif
    md_rcu_sys_init(RCU, (md_rcu_init_typedef*)(&rcu_initStruct));
    md_rcu_enable_gpioa(RCU);
    md_rcu_enable_gpiob(RCU);
    md_rcu_enable_gpioc(RCU);
    md_rcu_enable_gpiod(RCU);
    md_rcu_enable_usb(RCU);
#if ES32_USE_USB_SOF_TRIM_HRC48
    /*Using USB_SOF to calibrate the internal clock*/
    md_rcu_enable_csu(RCU);
    CSU->CON |= CSU_CON_AUTOEN_MSK;
    CSU->CON |= CSU_CON_CNTEN_MSK;
#endif
    __enable_irq();
}
#endif

/** @} */
