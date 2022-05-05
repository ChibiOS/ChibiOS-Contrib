/******************** (C) COPYRIGHT 2013 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2013/12
* AUTHOR:				SA1
* IC:						SN32F240/230/220
* DESCRIPTION:	RTC related functions.
*____________________________________________________________________________
* REVISION	Date				User		Description
* 1.0				2013/12/17	SA1			First release
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
#include "RTC.h"
#include "..\..\System\SYS_con_drive.h"


/*_____ D E C L A R A T I O N S ____________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/

/*_____ M A C R O S ________________________________________________________*/

/*_____ F U N C T I O N S __________________________________________________*/

/*****************************************************************************
* Function		: RTC_IRQHandler
* Description	: None
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
__irq void RTC_IRQHandler(void)
{	
	if(SN_RTC->RIS & mskRTC_SECIF)
	{		
		SN_GPIO0->DATA_b.DATA0 = ~SN_GPIO0->DATA_b.DATA0;

		SN_RTC->IC = mskRTC_SECIC;						//Clear Second interrupt status
	}

	if(SN_RTC->RIS & mskRTC_ALMIF)
	{
		
		SN_GPIO0->DATA_b.DATA1 = ~SN_GPIO0->DATA_b.DATA1;

		SN_RTC->IC = mskRTC_ALMIC;						//Clear Alarm interrupt status
	}

	if(SN_RTC->RIS & mskRTC_OVFIF)
	{
		SN_GPIO0->DATA_b.DATA2 = ~SN_GPIO0->DATA_b.DATA2;
		
		SN_RTC->IC = mskRTC_OVFIC;						//Clear Overflow interrupt status
	}	
}


/*****************************************************************************
* Function		: RTC_Initial
* Description	: RTC initial set
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void RTC_Init(void)
{	
	__RTC_ENABLE_RTCHCLK;													//Enable HCLK for RTC			
	
	#if	RTC_MODE == SECOND												//Second will occur every 1 second
	RTC_SelectClockSource(RTC_CLKSEL_ELS);				//Clock Source select
	SN_RTC->IE = mskRTC_SECIE_ENABLE;							//Enable Second Interrupt
	__RTC_SECCNTV(32767);													//Second counter reload value
																								
	#endif

	#if	RTC_MODE == ALARM													//Alarm will occur after 10 seconds								
	RTC_SelectClockSource(RTC_CLKSEL_ELS);				//Clock Source select
	SN_RTC->IE = mskRTC_ALMIE_ENABLE;							//Enable Alarm Interrupt
	__RTC_SECCNTV(32767);													//Second counter reload value
	__RTC_ALMCNTV(9);															//Alarm counter reload value 
	#endif	
									
	#if	RTC_MODE == OVERFLOW											//Overflow will occur in 54975.58139 seconds(15.271 hours)	
	RTC_SelectClockSource(RTC_CLKSEL_EHS);				//Clock Source select
	SN_RTC->IE = 
	(mskRTC_OVFIE_ENABLE | mskRTC_ALMIE_ENABLE);	//Enable Overflow Interrupt
	__RTC_SECCNTV(1);															//Second counter reload value & Second will occur in 12.8u second	
	__RTC_ALMCNTV(75000000);											//Alarm counter reload value & Alarm will occur in 960 seconds(16 minutes)																							
	#endif		
	
	//Enable RTC NVIC interrupt
	RTC_NvicEnable();
	
	__RTC_ENABLE;																	//Enable RTC
}
/***********************************************************************************
* Function		: RTC_SelectClockSource
*	Description	: Select RTC clcok source
* Input			: RTC clock source - 
							RTC_CLKSEL_ILRC or RTC_CLKSEL_ELS or RTC_CLKSEL_EHS
* Output		: None
* Return		: None
* Note			: None
***********************************************************************************/
void RTC_SelectClockSource(uint32_t src)
{
	if (src == RTC_CLKSEL_ELS)
		SYS0_EnableELSXtal();	
	else	if (src == RTC_CLKSEL_EHS)
		SYS0_EnableEHSXtal(SYS0_EHS_FREQ_DRIVE_HIGH);
			
	SN_RTC->CLKS = src;																	//clock source select
}
/*****************************************************************************
* Function		: RTC_NvicEnable
* Description	: Enable RTC interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void RTC_NvicEnable(void)
{
	NVIC_ClearPendingIRQ(RTC_IRQn);
	NVIC_EnableIRQ(RTC_IRQn);
	NVIC_SetPriority(RTC_IRQn,0);			// Set interrupt priority (default)
}

/*****************************************************************************
* Function		: RTC_NvicDisable
* Description	: Disable RTC interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void RTC_NvicDisable(void)
{
	NVIC_DisableIRQ(RTC_IRQn);
}


