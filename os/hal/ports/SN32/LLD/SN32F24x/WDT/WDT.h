#ifndef __SN32F240_WDT_H
#define __SN32F240_WDT_H

/*_____ I N C L U D E S ____________________________________________________*/
#include <SN32F240.h>

/*_____ D E F I N I T I O N S ______________________________________________*/
#define RESET										0										//WDT as Reset mode
#define INTERRUPT								1										//WDT as Interrupt mode
#define	WDT_MODE								INTERRUPT			
																										//RESET_MODE : WDT as Reset mode

//Watchdog register key
#define mskWDT_WDKEY		 				(0x5AFA<<16)

//Watchdog interrupt flag
#define mskWDT_WDTINT						(1<<2)

//Watchdog interrupt enable
#define WDT_WDTIE_DISABLE				0
#define WDT_WDTIE_ENABLE				1
#define mskWDT_WDTIE_DISABLE		(WDT_WDTIE_DISABLE<<1)
#define mskWDT_WDTIE_ENABLE			(WDT_WDTIE_ENABLE<<1)

//Watchdog enable
#define mskWDT_WDTEN_DISABLE		0		
#define mskWDT_WDTEN_ENABLE			1		

//Watchdog Clock source
#define WDT_CLKSEL_IHRC					0
#define WDT_CLKSEL_HCLK					1
#define WDT_CLKSEL_ILRC					2
#define WDT_CLKSEL_ELS					3

//Watchdog Feed value
#define mskWDT_FV		 						0x55AA

/*_____ M A C R O S ________________________________________________________*/
//Watchdog Feed Value
#define	__WDT_FEED_VALUE				(SN_WDT->FEED = (mskWDT_WDKEY | mskWDT_FV))	

//WDT Enable/Disable
#define	__WDT_ENABLE						(SN_WDT->CFG |= (mskWDT_WDKEY | mskWDT_WDTEN_ENABLE))
#define	__WDT_DISABLE						(SN_WDT->CFG = (mskWDT_WDKEY | (SN_WDT->CFG & ~mskWDT_WDTEN_ENABLE))) 
																 
//WDT INT status register clear
#define __WDT_CLRINSTS		      (SN_WDT->CFG = (mskWDT_WDKEY | (SN_WDT->CFG & ~mskWDT_WDTINT)))   

/*_____ D E C L A R A T I O N S ____________________________________________*/
void WDT_Init(void);
void WDT_ReloadValue(uint32_t time);
void WDT_SelectClockSource(uint32_t src);
void WDT_NvicEnable(void);
void WDT_NvicDisable(void);
#endif	/*__SN32F240_WDT_H*/
