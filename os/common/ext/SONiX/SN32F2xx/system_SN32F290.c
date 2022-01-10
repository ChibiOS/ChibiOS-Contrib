/******************************************************************************
 * @file     system_SN32F290.c
 * @brief    CMSIS Cortex-M0 Device Peripheral Access Layer Source File
 *           for the SONIX SN32F790 Devices
 * @version  V0.0.5
 * @date     2018/06/14
 *
 * @note
 * Copyright (C) 2016-2017 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/


#include <stdint.h>
#include <system_SN32F2xx.h>
#include <mcuconf.h>


/*
//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
*/

/*--------------------- Clock Configuration ----------------------------------
//
//		<o0.0..2>  SYSCLKSEL (SYS0_CLKCFG)
//					<0=> IHRC
//					<1=> ILRC
//					<2=> EHS X'TAL
//					<3=> ELS X'TAL
//					<4=> PLL
//	
//		<o1> EHS Source Frequency (MHz)
//			<10-25>
//
//<e2> PLL ENABLE
//	<h> PLL Control Register (SYS0_PLLCTRL)
//			<i> F_CLKOUT = F_VCO / P = (F_CLKIN * M) / P
//			<i> 10 MHz <= F_CLKIN <= 25 MHz
//			<i> 96 MHz <= (F_CLKIN * M) <= 144 MHz
//		<o3> MSEL
//					<0=> M = 4
//					<1=> M = 6
//					<2=> M = 8
//					<3=> M = 10
//					<4=> M = 12
//		<o4> PSEL
//					<0=> P = 2
//					<1=> P = 4
//		<o5> PLL CLKIN Source selection
//					<0=> IHRC
//					<1=> EHS X'TAL
//	</h>
//</e>
//		<o6>  AHB Clock Prescaler Register  (SYS0_AHBCP)
//					<0=> SYSCLK/1
//					<1=> SYSCLK/2
//					<2=> SYSCLK/4
//					<3=> SYSCLK/8
//					<4=> SYSCLK/16
//					<5=> SYSCLK/32
//					<6=> SYSCLK/64
//					<7=> SYSCLK/128
//		<o7>  SYSCLK prescaler Register  (SYS0_AHBCP)
//					<0=> SYSCLK/1
//					<1=> SYSCLK/1.5
//		<o8>  CLKOUT selection
//					<0=> Disable
//					<1=> ILRC
//					<2=> ELS X'TAL
//					<4=> HCLK
//					<5=> IHRC
//					<6=> EHS X'TAL
//					<7=> PLL
//		<o9> CLKOUT Prescaler Register  (SYS1_APBCP1)
//					<0=> CLKOUT selection/1
//					<1=> CLKOUT selection/2
//					<2=> CLKOUT selection/4
//					<3=> CLKOUT selection/8
//					<4=> CLKOUT selection/16
//					<5=> CLKOUT selection/32
//					<6=> CLKOUT selection/64
//					<7=> CLKOUT selection/128
*/

#ifndef SYS0_CLKCFG_VAL
#define SYS0_CLKCFG_VAL		0
#endif
#ifndef EHS_FREQ
#define EHS_FREQ					16
#endif
#ifndef PLL_ENABLE
#define PLL_ENABLE				0
#endif
#ifndef PLL_MSEL
#define PLL_MSEL					1
#endif
#ifndef PLL_PSEL
#define PLL_PSEL					0
#endif
#ifndef PLL_CLKIN
#define PLL_CLKIN					0
#endif
#ifndef AHB_PRESCALAR
#define AHB_PRESCALAR 		0x0
#endif
#ifndef AHB_1P5PRESCALAR
#define AHB_1P5PRESCALAR 	0x0
#endif
#ifndef CLKOUT_SEL_VAL
#define CLKOUT_SEL_VAL 		0x0
#endif
#ifndef CLKOUT_PRESCALAR
#define CLKOUT_PRESCALAR 	0x0
#endif

/*
//-------- <<< end of configuration section >>> ------------------------------
*/


/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/
#ifndef IHRC
#define	IHRC			0
#endif
#ifndef ILRC
#define	ILRC			1
#endif
#ifndef EHSXTAL
#define EHSXTAL		2
#endif
#ifndef ELSXTAL
#define ELSXTAL		3
#endif
#ifndef PLL
#define PLL				4
#endif

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define __IHRC_FREQ			(12000000UL)
#define __ILRC_FREQ			(32000UL)
#define __ELS_XTAL_FREQ	(32768UL)

#define SYS0_PLLCTRL_VAL	(PLL_ENABLE<<15) | (PLL_CLKIN<<12) | (PLL_PSEL<<5) |  PLL_MSEL


/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock;	/*!< System Clock Frequency (Core Clock)*/


/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)            /* Get Core Clock Frequency      */
{
	uint32_t AHB_prescaler;

	switch (SN_SYS0->CLKCFG_b.SYSCLKST)
	{
		case 0:		//IHRC
			SystemCoreClock = __IHRC_FREQ;
			break;
		case 1:		//ILRC
			SystemCoreClock = __ILRC_FREQ;
			break;
		case 2:		//EHS X'TAL
			SystemCoreClock = EHS_FREQ * 1000000;
			break;
		case 3:		//ELS X'TAL
			SystemCoreClock = __ELS_XTAL_FREQ;
			break;	
		case 4: 	//PLL
			if (PLL_CLKIN == 0x0)	//IHRC as F_CLKIN
				SystemCoreClock = __IHRC_FREQ * (PLL_MSEL+2) / (PLL_PSEL+1);
			else
				SystemCoreClock = EHS_FREQ * 1000000 * (PLL_MSEL+2) / (PLL_PSEL+1);
			break;
		default:
			break;
	}

	switch (SN_SYS0->AHBCP)
	{
		case 0:	AHB_prescaler = 1;	break;
		case 1:	AHB_prescaler = 2;	break;
		case 2:	AHB_prescaler = 4;	break;
		case 3:	AHB_prescaler = 8;	break;
		case 4:	AHB_prescaler = 16;	break;
		case 5:	AHB_prescaler = 32;	break;
		case 6:	AHB_prescaler = 64;	break;
		case 7:	AHB_prescaler = 128;break;
		default: break;	
	}

	SystemCoreClock /= AHB_prescaler;
	
	if (SN_SYS0->AHBCP_b.DIV1P5 == 1)
		SystemCoreClock = SystemCoreClock*2/3;

	//;;;;;;;;; Need for SN32F780 Begin	;;;;;;;;;
	if (SystemCoreClock > 48000000)
		SN_FLASH->LPCTRL = 0x5AFA0031;
	else if (SystemCoreClock > 24000000)
		SN_FLASH->LPCTRL = 0x5AFA0011;
	else
		SN_FLASH->LPCTRL = 0x5AFA0000;
	//;;;;;;;;; Need for SN32F780 End	;;;;;;;;;

	return;
}

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */
void SystemInit (void)
{
	#if SYS0_CLKCFG_VAL == IHRC			//IHRC
	SN_SYS0->CLKCFG = 0x0;
	while ((SN_SYS0->CLKCFG & 0x70) != 0x0);
	#endif

	#if SYS0_CLKCFG_VAL == ILRC			//ILRC
	SN_SYS0->CLKCFG = 0x1;
	while ((SN_SYS0->CLKCFG & 0x70) != 0x10);
	#endif

	#if (SYS0_CLKCFG_VAL == EHSXTAL)	//EHS XTAL
	#if (EHS_FREQ > 12)
	SN_SYS0->ANBCTRL_b.EHSFREQ = 1;
	SN_FLASH->LPCTRL = 0x5AFA0011;
	#else
	SN_SYS0->ANBCTRL_b.EHSFREQ = 0;
	#endif
	SN_SYS0->ANBCTRL_b.EHSEN = 1;
	while ((SN_SYS0->CSST & 0x10) != 0x10);
	SN_SYS0->CLKCFG = 0x2;
	while ((SN_SYS0->CLKCFG & 0x70) != 0x20);
	#endif

	#if (SYS0_CLKCFG_VAL == ELSXTAL)	//ELS XTAL
	SN_SYS0->ANBCTRL_b.ELSEN = 1;
	while((SN_SYS0->CSST & 0x4) != 0x4);
	SN_SYS0->CLKCFG = 0x3;
	while ((SN_SYS0->CLKCFG & 0x70) != 0x30);
	#endif

	#if (PLL_ENABLE == 1)
	SN_SYS0->PLLCTRL = SYS0_PLLCTRL_VAL;
	if (PLL_CLKIN == 0x1)	//EHS XTAL as F_CLKIN
	{
		//Enable EHS
		#if (EHS_FREQ > 12)
		SN_SYS0->ANBCTRL_b.EHSFREQ = 1;
		#else
		SN_SYS0->ANBCTRL_b.EHSFREQ = 0;
		#endif
		SN_SYS0->ANBCTRL_b.EHSEN = 1;
		while ((SN_SYS0->CSST & 0x10) != 0x10);
	}
	while ((SN_SYS0->CSST & 0x40) != 0x40);
	#if (SYS0_CLKCFG_VAL == PLL)		//PLL
	SN_FLASH->LPCTRL = 0x5AFA0031;
	SN_SYS0->CLKCFG = 0x4;
	while ((SN_SYS0->CLKCFG & 0x70) != 0x40);
	#endif
	#endif

	SN_SYS0->AHBCP = AHB_PRESCALAR;
	SN_SYS0->AHBCP_b.DIV1P5 = AHB_1P5PRESCALAR;

	#if (CLKOUT_SEL_VAL > 0)			//CLKOUT
	SN_SYS1->AHBCLKEN_b.CLKOUTSEL = CLKOUT_SEL_VAL;
	SN_SYS1->APBCP1_b.CLKOUTPRE = CLKOUT_PRESCALAR;
	#endif
}
