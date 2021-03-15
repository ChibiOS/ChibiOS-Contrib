/*----------------------------------------------------------------------------
 *      U S B  -  K e r n e l
 *----------------------------------------------------------------------------
 * Name:    usbsystem.h
 * Purpose: USB Custom User Definitions
 * Version: V1.20
 *----------------------------------------------------------------------------*/

#ifndef	__USBSYSTEM_H__
#define	__USBSYSTEM_H__
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


/*
//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
*/

/*--------------------- Clock Configuration ----------------------------------
//
//<e> System Clock Configuration
//		<o1.0..2>  SYSCLKSEL (SYS0_CLKCFG)
//					<0=> ILRC
//					<1=> IHRC
//					<2=> EHS X'TAL
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
//					<24=> MSEL = 24
//					<18=>	MSEL = 18
//					<12=> MSEL = 12	
//		<o4> PSEL
//					<3=> P = 6
//					<4=> P = 8
//		<o5> FSEL
//					<0=> F = 1
//					<1=> F = 2
//		<o6> PLL CLKIN Source selection
//					<0=> IHRC
//					<1=> EHS X'TAL
//		<o7> PLL Enable selection
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

#define USB_SYS_CLOCK_SETUP		1
#define USB_SYS0_CLKCFG_VAL		USB_PLL
#define USB_EHS_FREQ			12
#define USB_PLL_MSEL			18
#define USB_PLL_PSEL			3
#define USB_PLL_FSEL			0
#define USB_PLL_CLKIN			0
#define USB_PLL_ENABLE			1
#define USB_AHB_PRESCALAR 		0x0
#define USB_CLKOUT_SEL_VAL 		0x0

/*
//-------- <<< end of configuration section >>> ------------------------------
*/
/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/
#define	USB_IHRC		0
#define	USB_ILRC		1
#define USB_EHSXTAL		2
#define USB_ELSXTAL		3
#define USB_PLL			4

#define	USB_IHRC_EN						1
#define	USB_SYS0_PLLCTRL_EN		0x8000
#define	USB_PSEL_6  (0x03<<5)
#define	USB_PSEL_8	(0x04<<5)
#define	USB_MSEL_24	24
#define	USB_MSEL_18	18
#define	USB_MSEL_12	12	
#define	USB_PLL_CLKSOURCE_IHRC	(USB_PSEL_6|USB_MSEL_24)
#define	USB_PLL_CLKSOURCE_12MHz	(USB_PSEL_6|USB_MSEL_24)
#define	USB_PLL_CLKSOURCE_16MHz	(USB_PSEL_6|USB_MSEL_18)
#define	USB_PLL_CLKSOURCE_24MHz	(USB_PSEL_6|USB_MSEL_12)

#define	USB_PLL_DLEYA_TIME	100000
#define	USB_PLL_10US_TIME		76

#if (USB_SYS0_CLKCFG_VAL == USB_PLL)	
	#define	K_STATE_DELAY  USB_PLL_DLEYA_TIME*(USB_AHB_PRESCALAR+1)
	#define	DISCHARE_DELAY K_STATE_DELAY
	#define	UTILITY_10US_DELAY		USB_PLL_10US_TIME*(USB_AHB_PRESCALAR+1)
#endif	//end USB_SYS0_CLKCFG_VAL == PLL

#if (USB_SYS0_CLKCFG_VAL == USB_IHRC)	
#define	K_STATE_DELAY  (USB_PLL_DLEYA_TIME/4)*(USB_AHB_PRESCALAR+1)
#define	DISCHARE_DELAY K_STATE_DELAY
	#define	UTILITY_10US_DELAY		(USB_PLL_10US_TIME/4)*(USB_AHB_PRESCALAR+1)		
#endif	//end USB_SYS0_CLKCFG_VAL == USB_IHRC

#if (USB_SYS0_CLKCFG_VAL == USB_EHSXTAL)	
#if (USB_EHS_FREQ == 12)
	#define	K_STATE_DELAY  (USB_PLL_DLEYA_TIME/4)*(USB_AHB_PRESCALAR+1)
	#define	DISCHARE_DELAY K_STATE_DELAY
	#define	UTILITY_10US_DELAY		(USB_PLL_10US_TIME/4)*(USB_AHB_PRESCALAR+1)			
#elif (USB_EHS_FREQ == 16)
	#define	K_STATE_DELAY  (USB_PLL_DLEYA_TIME/3)*(USB_AHB_PRESCALAR+1)
	#define	DISCHARE_DELAY K_STATE_DELAY
	#define	UTILITY_10US_DELAY		(USB_PLL_10US_TIME/3)*(USB_AHB_PRESCALAR+1)	
#elif (USB_EHS_FREQ == 24)
	#define	K_STATE_DELAY  (USB_PLL_DLEYA_TIME/2)*(USB_AHB_PRESCALAR+1)
	#define	DISCHARE_DELAY K_STATE_DELAY
	#define	UTILITY_10US_DELAY		(USB_PLL_10US_TIME/2)*(USB_AHB_PRESCALAR+1)	
#endif	//end USB_EHS_FREQ
#endif  //end USB_SYS0_CLKCFG_VAL == USB_EHSTAL

extern void USB_SystemInit (void);
#endif		/* __USBSYSTEM_H__ */