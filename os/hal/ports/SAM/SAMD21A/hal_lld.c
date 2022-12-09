/*
		ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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
#include "sam_clk.h"
/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

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
static void sam_clock_init(void);

static void sam_xosc32_init(void);
static void sam_xosc_init(void);
static void sam_osc8m_init(void);
static void sam_osc32k_init(void);
static void sam_dfll48m_init(void);
static void sam_osculp32k_init(void);

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void)
{
	sam_clock_init();
#if defined(SAM_DMAC_REQUIRED)
	dmacInit();
#endif
}

static void sam_clock_init(void)
{
	NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_RWS(SAM_NVM_DELAY);
	sam_xosc32_init();
	sam_xosc_init();
	sam_gclk_init(1, SAM_GCLK1_SRC, SAM_GCLK1_GENDIV, SAM_GCLK1_ENABLE);
	/* Init dfll48m when gclk1 is configured */
	sam_dfll48m_init();
	sam_gclk_init(2, SAM_GCLK2_SRC, SAM_GCLK2_GENDIV, SAM_GCLK2_ENABLE);
	sam_gclk_init(3, SAM_GCLK3_SRC, SAM_GCLK3_GENDIV, SAM_GCLK3_ENABLE);
	sam_gclk_init(4, SAM_GCLK4_SRC, SAM_GCLK4_GENDIV, SAM_GCLK4_ENABLE);
	sam_gclk_init(5, SAM_GCLK5_SRC, SAM_GCLK5_GENDIV, SAM_GCLK5_ENABLE);
	sam_gclk_init(6, SAM_GCLK6_SRC, SAM_GCLK6_GENDIV, SAM_GCLK6_ENABLE);
	sam_gclk_init(7, SAM_GCLK7_SRC, SAM_GCLK7_GENDIV, SAM_GCLK7_ENABLE);
	sam_gclk_init(8, SAM_GCLK8_SRC, SAM_GCLK8_GENDIV, SAM_GCLK8_ENABLE);
	sam_gclk_init(0, SAM_GCLK0_SRC, SAM_GCLK0_GENDIV, TRUE);
	sam_osc8m_init();
	sam_osc32k_init();
	sam_osculp32k_init();
	PM_REGS->PM_CPUSEL = PM_CPUSEL_CPUDIV(SAM_CPUDIV);
	PM_REGS->PM_APBASEL = PM_APBASEL_APBADIV(SAM_APBADIV);
	PM_REGS->PM_APBBSEL = PM_APBBSEL_APBBDIV(SAM_APBBDIV);
	PM_REGS->PM_APBCSEL = PM_APBCSEL_APBCDIV(SAM_APBCDIV);
}

static void sam_xosc32_init(void)
{
#if SAM_XOSC32_ENABLED == 1
	SYSCTRL_REGS->SYSCTRL_XOSC32K = SYSCTRL_XOSC32K_STARTUP(5) | SYSCTRL_XOSC32K_EN32K_Msk | SYSCTRL_XOSC32K_XTALEN_Msk;
	SYSCTRL_REGS->SYSCTRL_XOSC32K |= SYSCTRL_XOSC32K_ENABLE_Msk;
	while ((SYSCTRL_REGS->SYSCTRL_PCLKSR & SYSCTRL_PCLKSR_XOSC32KRDY_Msk) != SYSCTRL_PCLKSR_XOSC32KRDY_Msk)
		;
	GCLK_REGS->GCLK_GENCTRL = GCLK_GENCTRL_ID(1) | GCLK_GENCTRL_SRC_XOSC32K | GCLK_GENCTRL_IDC(1) | GCLK_GENCTRL_GENEN_Msk;
	while ((GCLK_REGS->GCLK_STATUS & GCLK_STATUS_SYNCBUSY_Msk) == GCLK_STATUS_SYNCBUSY_Msk)
		;
#else
	SYSCTRL_REGS->SYSCTRL_XOSC32K = 0;
#endif
}

static void sam_xosc_init(void)
{
#if SAM_XOSC_ENABLED == 1
	SYSCTRL_REGS->SYSCTRL_XOSC = SYSCTRL_XOSC_STARTUP(5) | SYSCTRL_XOSC_XTALEN_Msk | SYSCTRL_XOSC_AMPGC_Msk;
	SYSCTRL_REGS->SYSCTRL_XOSC |= SYSCTRL_XOSC_ENABLE_Msk;
	while ((SYSCTRL_REGS->SYSCTRL_PCLKSR & SYSCTRL_PCLKSR_XOSCRDY_Msk) != SYSCTRL_PCLKSR_XOSCRDY_Msk)
		;
	GCLK_REGS->GCLK_GENCTRL = GCLK_GENCTRL_ID(1) | GCLK_GENCTRL_SRC_XOSC | GCLK_GENCTRL_IDC(1) | GCLK_GENCTRL_GENEN_Msk;
	while ((GCLK_REGS->GCLK_STATUS & GCLK_STATUS_SYNCBUSY_Msk) == GCLK_STATUS_SYNCBUSY_Msk)
		;
#else
	SYSCTRL_REGS->SYSCTRL_XOSC = 0;
#endif
}

static void sam_osc8m_init(void)
{
#if SAM_OSC8M_ENABLED == 1
// SYSCTRL_REGS->SYSCTRL_OSC8M = 0;
// TODO: Init osc8m properly
#else
	SYSCTRL_REGS->SYSCTRL_OSC8M = 0;
#endif
}

static void sam_osc32k_init(void)
{
#if SAM_OSC32K_ENABLED == 1
// SYSCTRL_REGS->SYSCTRL_OSC32K = 0;
// TODO: Init osc32k properly
#else
	SYSCTRL_REGS->SYSCTRL_OSCULP32K = 0;
#endif
}

static void sam_osculp32k_init(void)
{
	SYSCTRL_REGS->SYSCTRL_OSCULP32K = 0;
}

static void sam_dfll48m_init()
{
#if SAM_DFLL48_ENABLED == 1
	/****************** DFLL Initialization  *********************************/
	SYSCTRL_REGS->SYSCTRL_DFLLCTRL &= ~SYSCTRL_DFLLCTRL_ONDEMAND_Msk;

	while ((SYSCTRL_REGS->SYSCTRL_PCLKSR & SYSCTRL_PCLKSR_DFLLRDY_Msk) != SYSCTRL_PCLKSR_DFLLRDY_Msk)
		;

	/*Load Calibration Value*/
	uint8_t calibCoarse = (uint8_t)(((*(uint32_t *)0x806024) >> 26) & 0x3f);
	calibCoarse = (((calibCoarse) == 0x3F) ? 0x1F : (calibCoarse));
	uint16_t calibFine = (uint16_t)(((*(uint32_t *)0x806028)) & 0x3ff);

	SYSCTRL_REGS->SYSCTRL_DFLLVAL = SYSCTRL_DFLLVAL_COARSE(calibCoarse) | SYSCTRL_DFLLVAL_FINE(calibFine);
	GCLK_REGS->GCLK_CLKCTRL = GCLK_CLKCTRL_GEN_GCLK1 | GCLK_CLKCTRL_CLKEN_Msk | GCLK_CLKCTRL_ID_DFLL48;
	while ((SYSCTRL_REGS->SYSCTRL_PCLKSR & SYSCTRL_PCLKSR_DFLLRDY_Msk) != SYSCTRL_PCLKSR_DFLLRDY_Msk)
		;

	SYSCTRL_REGS->SYSCTRL_DFLLMUL = SYSCTRL_DFLLMUL_MUL(1464) | SYSCTRL_DFLLMUL_FSTEP(511) | SYSCTRL_DFLLMUL_CSTEP(31);

	while ((SYSCTRL_REGS->SYSCTRL_PCLKSR & SYSCTRL_PCLKSR_DFLLRDY_Msk) != SYSCTRL_PCLKSR_DFLLRDY_Msk)
		;

	/* Configure DFLL    */
	SYSCTRL_REGS->SYSCTRL_DFLLCTRL = SYSCTRL_DFLLCTRL_ENABLE_Msk | SYSCTRL_DFLLCTRL_MODE_Msk | SYSCTRL_DFLLCTRL_WAITLOCK(1);

	while ((SYSCTRL_REGS->SYSCTRL_PCLKSR & SYSCTRL_PCLKSR_DFLLLCKF_Msk) != SYSCTRL_PCLKSR_DFLLLCKF_Msk)
		;
#else
	SYSCTRL_REGS->SYSCTRL_DFLLCTRL = 0;
#endif
}

/** @} */
