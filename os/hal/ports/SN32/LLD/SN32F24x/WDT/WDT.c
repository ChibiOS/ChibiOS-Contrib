/******************** (C) COPYRIGHT 2014 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2014/01
* AUTHOR:				SA1
* IC:						SN32F240/230/220
* DESCRIPTION:	WDT related functions.
*____________________________________________________________________________
* REVISION	Date				User		Description
* 1.0				2013/12/17	SA1			First release
* 1.1				2014/01/20	SA1			1. Modify WDT_ReloadValue function
*
*____________________________________________________________________________
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS TIME TO MARKET.
* SONiX SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL 
* DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH SOFTWARE
* AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN 
* IN CONNECTION WITH THEIR PRODUCTS.
*****************************************************************************/

/*_____ I N C L U D E S ____________________________________________________*/
#include <SN32F240.h>
#include <SN32F200_Def.h>
#include "WDT.h"
#include "..\..\System\SYS_con_drive.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/


/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/



/*_____ F U N C T I O N S __________________________________________________*/
/*****************************************************************************
* Function		: WDT_IRQHandler
* Description	: ISR of WDT interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
__irq void WDT_IRQHandler(void)
{
	SN_GPIO2->DATA_b.DATA0 = ~SN_GPIO2->DATA_b.DATA0;		//P2.0 toggle
	
	__WDT_FEED_VALUE;
	
	__WDT_CLRINSTS;																			//Clear WDT interrupt flag
}

/*****************************************************************************
* Function		: WDT_Init
* Description	: WDT initial
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void WDT_Init(void)
{
	uint32_t	wRegBuf;
	
	WDT_SelectClockSource(WDT_CLKSEL_ILRC);						//clock source select

	#if WDT_MODE == INTERRUPT
	wRegBuf = mskWDT_WDTIE_ENABLE;										//WDT as interrupt mode	
	#endif
	
	#if WDT_MODE == RESET
	wRegBuf = mskWDT_WDTIE_DISABLE;										//WDT as reset mode	
	#endif
	
	wRegBuf = wRegBuf & (~mskWDT_WDTINT);							//Clear WDT interrupt flag
	
	wRegBuf = wRegBuf | mskWDT_WDKEY;

	SN_WDT->CFG = wRegBuf;
	
	WDT_ReloadValue(61);															//Set overflow time = 250ms
	
	WDT_NvicEnable();																	//Enable WDT NVIC interrupt

	__WDT_ENABLE;																			//Enable WDT
}

/*****************************************************************************
* Function		: WDT_ReloadValue
* Description	: set WDT reload value 
* Input			:	time -  
							0~255: overflow time set
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void WDT_ReloadValue(uint32_t time)
{
	uint32_t	wRegBuf;

	wRegBuf = time | mskWDT_WDKEY;
	
	SN_WDT->TC = wRegBuf;
	
	__WDT_FEED_VALUE;	
}

/***********************************************************************************
* Function		: WDT_SelectClockSource
*	Description	: Select WDT clcok source
* Input			: WDT clock source - 
							WDT_CLKSEL_IHRC or WDT_CLKSEL_HCLK or WDT_CLKSEL_ILRC or WDT_CLKSEL_ELS
* Output		: None
* Return		: None
* Note			: None
***********************************************************************************/
void WDT_SelectClockSource(uint32_t src)
{
	if (src == WDT_CLKSEL_IHRC)
		SYS0_EnableIHRC();	
	else	if (src == WDT_CLKSEL_ELS)
		SYS0_EnableELSXtal();
			
	SN_WDT->CLKSOURCE = mskWDT_WDKEY | src;					//clock source select
}

/*****************************************************************************
* Function		: WDT_NvicEnable
* Description	: Enable WDT interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void WDT_NvicEnable(void)
{
	NVIC_ClearPendingIRQ(WDT_IRQn);
	NVIC_EnableIRQ(WDT_IRQn);
	NVIC_SetPriority(WDT_IRQn, 0);			// Set interrupt priority (default)
}

/*****************************************************************************
* Function		: WDT_NvicDisable
* Description	: Disable WDT interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void WDT_NvicDisable(void)
{
	NVIC_DisableIRQ(WDT_IRQn);
}
