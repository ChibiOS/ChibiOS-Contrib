/******************** (C) COPYRIGHT 2013 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2013/12
* AUTHOR:				SA1
* IC:						SN32F240/230/220
* DESCRIPTION:	LCD related functions.
*____________________________________________________________________________
* REVISION	Date				User		Description
* 1.0				2013/12/17	SA1			1. First release
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
#include "LCD.h"
#include "..\..\System\SYS_con_drive.h"


/*_____ D E C L A R A T I O N S ____________________________________________*/


/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ F U N C T I O N S __________________________________________________*/
#if LCD_TYPE == LCD_R_TYPE
/***********************************************************************************
* Function		: LCD_RtypeInit
* Description	: Initialization of R-type LCD driver
* Input			: None
* Output		: None
* Return		: None
* Note			: User shall follow the notice in 16.6 R-TYPE LCD APPLICATION CIRCUIT
*							to take care of the circuit.
***********************************************************************************/
void LCD_RtypeInit(void)
{
	__LCD_ENABLE_LCDHCLK;										//Enable HCLK for LCD

	//<-------------------- TODO: User modify on demand BEGIN -------------------->
	//Setup LCD Driving ability, Clock rate, Duty, Bias, Type
	SN_LCD->CTRL = (mskLCD_DRIVEP_LOW|mskLCD_RATE_DIV64|mskLCD_ONE_FOURTH_DUTY|mskLCD_ONE_THIRD_BIAS|mskLCD_R_TYPE);

	LCD_SelectClockSource(LCD_CLOCK_ILRC);	//Setup LCD Clock source

	//Setup ITB bit, R-type resistance
	SN_LCD->CTRL1 = (0|mskLCD_REF_400K);		//Only value 0 is allowed for ITB bit

	__LCD_SEGMENT_GROUP1_ENABLE;						//Enable SEG12~23 (P0.10~P0.15, P1.0~P1.5) as LCD pins
	__LCD_SEGMENT_GROUP2_ENABLE;						//Enable SEG24~31 (P0.0~P0.7) as LCD pins
	//<-------------------- TODO: User modify on demand END -------------------->

	__LCD_ENABLE;														//Enable LCD
}
#endif
#if LCD_TYPE == LCD_1C_TYPE
/***********************************************************************************
* Function		: LCD_1CtypeInit
* Description	: Initialization of 1C-type LCD driver
* Input			: None
* Output		: None
* Return		: None
* Note			: User shall follow the notice in 16.7 C-TYPE LCD APPLICATION CIRCUIT
*							to take care of the circuit.
***********************************************************************************/
void LCD_1CtypeInit(void)
{
	__LCD_ENABLE_LCDHCLK;										//Enable HCLK for LCD

	//<-------------------- TODO: User modify on demand BEGIN -------------------->
	//Setup LCD Driving ability, Clock rate, Duty, Bias, Type
	SN_LCD->CTRL = (mskLCD_DRIVEP_LOW|mskLCD_RATE_DIV64|mskLCD_ONE_FOURTH_DUTY|
									mskLCD_ONE_THIRD_BIAS|mskLCD_1C_TYPE);

	LCD_SelectClockSource(LCD_CLOCK_ILRC);	//Setup LCD Clock source
	
	//Setup IT1 bits, IT2 bits, VCP
	SN_LCD->CCTRL1 = (0x44020000|mskLCD_1C_VCP_3P3V);

	__LCD_SEGMENT_GROUP1_ENABLE;						//Enable SEG12~23 (P0.10~P0.15, P1.0~P1.5) as LCD pins
	__LCD_SEGMENT_GROUP2_ENABLE;						//Enable SEG24~31 (P0.0~P0.7) as LCD pins
	//<-------------------- TODO: User modify on demand END -------------------->
	
	SN_LCD->CCTRL2 = 4;											//Only value 0x4 is allowed
	__LCD_ENABLE;														//Enable LCD
}
#endif
#if LCD_TYPE == LCD_4C_TYPE
/***********************************************************************************
* Function		: LCD_4CtypeInit
* Description	: Initialization of 4C-type LCD driver
* Input			: None
* Output		: None
* Return		: None
* Note			: User shall follow the notice in 16.7 C-TYPE LCD APPLICATION CIRCUIT
*							to take care of the circuit.
***********************************************************************************/
void LCD_4CtypeInit(void)
{
	__LCD_ENABLE_LCDHCLK;										//Enable HCLK for LCD

	//<-------------------- TODO: User modify on demand BEGIN -------------------->
	//Setup LCD Driving ability, Clock rate, Duty, Bias, Type
	SN_LCD->CTRL = (mskLCD_DRIVEP_LOW|mskLCD_RATE_DIV64|mskLCD_ONE_FOURTH_DUTY|
									mskLCD_ONE_THIRD_BIAS|mskLCD_4C_TYPE);
	
	LCD_SelectClockSource(LCD_CLOCK_ILRC);	//Setup LCD Clock source

	//Setup IT1 bits, IT2 bits, VCP
	SN_LCD->CCTRL1 = (0x44020000|mskLCD_4C_VCP_3P0V);

	__LCD_SEGMENT_GROUP1_ENABLE;			//Enable SEG12~23 (P0.10~P0.15, P1.0~P1.5) as LCD pins
	__LCD_SEGMENT_GROUP2_ENABLE;			//Enable SEG24~31 (P0.0~P0.7) as LCD pins
	//<-------------------- TODO: User modify on demand END -------------------->
	
	SN_LCD->CCTRL2 = 4;								//Only value 0x4 is allowed
	__LCD_ENABLE;											//Enable LCD
}
#endif

/***********************************************************************************
* Function		: LCD_SelectClockSource
*	Description	: Select LCD clcok source
* Input			: LCD clock source - LCD_CLOCK_ILRC or LCD_CLOCK_ELS
* Output		: None
* Return		: None
* Note			: None
***********************************************************************************/
void LCD_SelectClockSource(uint32_t src)
{
	if (src == LCD_CLOCK_ELS)
		SYS0_EnableELSXtal();
	
	SN_LCD->CTRL_b.LCDCLK = src;
}


/***********************************************************************************
* Function		: LCD_FrameInterruptEnable
* Description	: LCD Frame interrupt enable function
* Input			: CEN - Enable/Disable counter (ENABLE or DISABLE)
*							FCT - Frame counter threshold value
*							IE - LCD interrupt Enable/Disable (ENABLE or DISABLE)
* Output		: None
* Return		: None
* Note			: 0 < FCT < 32
***********************************************************************************/
void LCD_SetFrameCounterInterrupt(uint32_t CEN, uint32_t FCT, uint32_t IE)
{
	if (IE == ENABLE)
	{
		NVIC_ClearPendingIRQ(LCD_IRQn);
		NVIC_EnableIRQ(LCD_IRQn);
	}
	
	SN_LCD->FCC = (CEN | (FCT<<1) | (IE<<7));
}


/*****************************************************************************
* Function		: LCD_IRQHandler
* Description	: ISR of LCD frame interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
__irq	void LCD_IRQHandler(void)
{
	SN_LCD->RIS = 0;				//Write 0 to clear LCD interurpt flag
}
