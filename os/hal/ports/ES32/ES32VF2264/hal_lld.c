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

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void)
{
    csi_vic_set_prio(MACHINE_MODE_SOFT_IRQn, 0);
    csi_vic_enable_sirq(MACHINE_MODE_SOFT_IRQn);
    CLIC->CLICINT[MACHINE_MODE_SOFT_IRQn].ATTR |= (3);
	
    md_cmu_pll_config(MD_CMU_PLL_INPUT_HRC4M, MD_CMU_PLL_OUTPUT_72M);
    md_cmu_clock_config(MD_CMU_CLOCK_PLL, 72000000);

    MD_SYSCFG_UNLOCK();
    md_cmu_enable_perh_all();
    md_cmu_enable_usbck48();/*USB 48M使能*/
    md_csu_enable_auto();
    md_csu_enable_cnt();
    MD_SYSCFG_LOCK();
	
    md_rmu_reset_periperal(MD_RMU_PERH_USB);
    md_init_1ms_tick();
    __enable_irq();
}
#endif

/** @} */
