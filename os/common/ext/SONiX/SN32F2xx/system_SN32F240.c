/******************************************************************************
 * @file     system_SN32F240.c
 * @brief    CMSIS Cortex-M0 Device Peripheral Access Layer Source File
 *           for the SONIX SN32F240 Devices
 * @version  V1.1.1
 * @date     2015/08/21
 *
 * @note
 * Copyright (C) 2009-2013 ARM Limited. All rights reserved.
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
//<e> System Clock Configuration
//		<o1.0..2>  SYSCLKSEL (SYS0_CLKCFG)
//					<0=> IHRC
//					<1=> ILRC
//					<2=> EHS X'TAL
//					<3=> ELS X'TAL
//					<4=> PLL
//
//		<o2> EHS Source Frequency (MHz)
//			<10-25>
//
//	<h> PLL Control Register (SYS0_PLLCTRL)
//			<i> F_CLKOUT = F_VCO / P = (F_CLKIN / F * M) / P
//			<i>  10 MHz <= F_CLKIN <= 25 MHz
//			<i> 156 MHz <= (F_CLKIN / F * M) <= 320 MHz
//		<o3> MSEL
//					<3-31>
//		<o4> PSEL
//					<3=> P = 6
//					<4=> P = 8
//					<5=> P = 10
//					<6=> P = 12
//					<7=> P = 14
//		<o5> FSEL
//					<0=> F = 1
//					<1=> F = 2
//		<o6> PLL CLKIN Source selection
//					<0=> IHRC
//					<1=> EHS X'TAL
//		<o7> PLL Enable selection
//					<0=> Disable
//					<1=> Enable
//	</h>
//
//		<o8>   AHB Clock Prescaler Register  (SYS0_AHBCP)
//					<0=> SYSCLK/1
//					<1=> SYSCLK/2
//					<2=> SYSCLK/4
//					<3=> SYSCLK/8
//					<4=> SYSCLK/16
//					<5=> SYSCLK/32
//					<6=> SYSCLK/64
//					<7=> SYSCLK/128
//					<8=> SYSCLK/256
//					<9=> SYSCLK/512
//
//		<o9>   CLKOUT selection
//					<0=> Disable
//					<1=> ILRC
//					<2=> ELS X'TAL
//					<4=> HCLK
//					<5=> IHRC
//					<6=> EHS X'TAL
//					<7=> PLL
//</e>
*/

#ifndef SYS_CLOCK_SETUP
#define SYS_CLOCK_SETUP		1
#endif
#ifndef SYS0_CLKCFG_VAL
#define SYS0_CLKCFG_VAL		0
#endif
#ifndef EHS_FREQ
#define EHS_FREQ			10
#endif
#ifndef PLL_MSEL
#define PLL_MSEL			12
#endif
#ifndef PLL_PSEL
#define PLL_PSEL			3
#endif
#ifndef PLL_FSEL
#define PLL_FSEL			0
#endif
#ifndef PLL_CLKIN
#define PLL_CLKIN			1
#endif
#ifndef PLL_ENABLE
#define PLL_ENABLE			0
#endif
#ifndef AHB_PRESCALAR
#define AHB_PRESCALAR 		0x0
#endif
#ifndef CLKOUT_SEL_VAL
#define CLKOUT_SEL_VAL 		0x0
#endif

/*
//-------- <<< end of configuration section >>> ------------------------------
*/


/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/
#ifndef IHRC
#define IHRC            0
#endif
#ifndef ILRC
#define ILRC            1
#endif
#ifndef EHSXTAL
#define EHSXTAL     2
#endif
#ifndef ELSXTAL
#define ELSXTAL     3
#endif
#ifndef PLL
#define PLL             4
#endif

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define __IHRC_FREQ			(12000000UL)
#define __ILRC_FREQ			(32000UL)
#define __ELS_XTAL_FREQ		(32768UL)

#if (SYS_CLOCK_SETUP)
#define SYS0_PLLCTRL_VAL	(PLL_ENABLE<<15) | (PLL_CLKIN<<12) | (PLL_FSEL<<8) | (PLL_PSEL<<5) |  PLL_MSEL
#endif

/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock;	/*!< System Clock Frequency (Core Clock)*/


/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)            /* Get Core Clock Frequency      */
{
    uint32_t AHB_prescaler = 0;
    uint32_t F;

    switch (SN_SYS0->CLKCFG_b.SYSCLKST)
    {
        case 0:		//IHRC
            SystemCoreClock = __IHRC_FREQ;
            break;
        case 1:		//ILRC
            SystemCoreClock = __ILRC_FREQ;
            break;
        case 2:		//EHS X'TAL
#if (SYS_CLOCK_SETUP)
            SystemCoreClock = EHS_FREQ * 1000000;
#else
            //TODO: User had to assign EHS X'TAL frequency.
			SystemCoreClock = 10000000UL / AHB_prescaler;
#endif
            break;
        case 3:		//ELS X'TAL
            SystemCoreClock = __ELS_XTAL_FREQ;
            break;
        case 4: 	//PLL
#if (SYS_CLOCK_SETUP)
            if (PLL_FSEL == 0)
                F = 1;
            else
                F = 2;
            if (PLL_CLKIN == 0x0)	//IHRC as F_CLKIN
                SystemCoreClock = __IHRC_FREQ / F * PLL_MSEL / PLL_PSEL /2;
            else
                SystemCoreClock = EHS_FREQ * 1000000 / F * PLL_MSEL / PLL_PSEL /2;
#else
            //TODO: User had to assign PLL output frequency.
			SystemCoreClock = 50000000UL;
#endif
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
        case 8:	AHB_prescaler = 256;break;
        case 9:	AHB_prescaler = 512;break;
        default: break;
    }

    SystemCoreClock /= AHB_prescaler;

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

#if (SYS_CLOCK_SETUP)

#if SYS0_CLKCFG_VAL == IHRC			//IHRC

#endif

#if SYS0_CLKCFG_VAL == ILRC			//ILRC
    SN_SYS0->CLKCFG = 0x1;
    while ((SN_SYS0->CLKCFG & 0x70) != 0x10);
#endif

#if (SYS0_CLKCFG_VAL == EHSXTAL)	//EHS XTAL
    #if (EHS_FREQ > 12)
	SN_SYS0->ANBCTRL |= (1<<5);
	#else
	SN_SYS0->ANBCTRL &=~(1<<5);
	#endif
	SN_SYS0->ANBCTRL |= (1<<4);
	while ((SN_SYS0->CSST & 0x10) != 0x10);
	SN_SYS0->CLKCFG = 0x2;
    while ((SN_SYS0->CLKCFG & 0x70) != 0x20);
#endif

#if (SYS0_CLKCFG_VAL == ELSXTAL)	//ELS XTAL
    SN_SYS0->ANBCTRL |=0x04;
	while((SN_SYS0->CSST & 0x4) != 0x4);
	SN_SYS0->CLKCFG = 0x3;
    while ((SN_SYS0->CLKCFG & 0x70) != 0x30);
#endif

#if (SYS0_CLKCFG_VAL == PLL)		//PLL
    SN_SYS0->PLLCTRL = SYS0_PLLCTRL_VAL;
	if (PLL_CLKIN == 0x1)	//EHS XTAL as F_CLKIN
	{
		//Enable EHS
		#if (EHS_FREQ > 12)
		SN_SYS0->ANBCTRL |= (1<<5);
		#else
		SN_SYS0->ANBCTRL &=~(1<<5);
		#endif
		SN_SYS0->ANBCTRL |= (1<<4);
		while ((SN_SYS0->CSST & 0x10) != 0x10);
	}

	while ((SN_SYS0->CSST & 0x40) != 0x40);
    SN_SYS0->CLKCFG = 0x4;
    while ((SN_SYS0->CLKCFG & 0x70) != 0x40);
#endif

    SN_SYS0->AHBCP = AHB_PRESCALAR;

#if (CLKOUT_SEL_VAL > 0)			//CLKOUT
    SN_SYS1->AHBCLKEN_b.CLKOUTSEL = CLKOUT_SEL_VAL;
#endif
#endif //(SYS_CLOCK_SETUP)

}