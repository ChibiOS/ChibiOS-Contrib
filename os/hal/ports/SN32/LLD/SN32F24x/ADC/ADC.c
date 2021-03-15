/******************** (C) COPYRIGHT 2013 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2013/12
* AUTHOR:				SA1
* IC:						SN32F240/230/220
* DESCRIPTION:	ADC related functions.
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
#include <SN32F200_Def.h>
#include "ADC.h"
#include "..\..\Utility\Utility.h"


/*_____ D E C L A R A T I O N S ____________________________________________*/
uint8_t	bADC_StartConv;

/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ F U N C T I O N S __________________________________________________*/

/*****************************************************************************
* Function		: ADC_Init
* Description	: Initialization of ADC
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void ADC_Init(void)
{
	SN_SYS1->AHBCLKEN |= (0x01 << 11);									//Enables HCLK for ADC
	
	//Set ADC PCLK
	SN_SYS1->APBCP0 |= (0x00 << 16);										//ADC PCLK = HCLK/1
	//SN_SYS1->APBCP0 |= (0x01 << 16);									//ADC PCLK = HCLK/2
	//SN_SYS1->APBCP0 |= (0x02 << 16);									//ADC PCLK = HCLK/4	
	//SN_SYS1->APBCP0 |= (0x03 << 16);									//ADC PCLK = HCLK/8	
	//SN_SYS1->APBCP0 |= (0x04 << 16);									//ADC PCLK = HCLK/16	
	
	SN_ADC->ADM_b.ADENB = ADC_ADENB_EN;									//Enable ADC
	
	UT_DelayNx10us(10);																	//Delay 100us
	
	SN_ADC->ADM_b.AVREFHSEL = ADC_AVREFHSEL_INTERNAL;		//Set ADC high reference voltage source from internal VDD
	
	SN_ADC->ADM_b.GCHS = ADC_GCHS_EN;										//Enable ADC global channel	
	
	SN_ADC->ADM_b.ADLEN = ADC_ADLEN_12BIT;							//Set ADC resolution = 12-bit			

	SN_ADC->ADM_b.ADCKS = ADC_ADCKS_DIV32;							//ADC_CLK = ADC_PCLK/32

	#if ADC_FUNCTION_TYPE == ADC_TYPE
	
	SN_ADC->ADM_b.CHS = ADC_CHS_AIN1;										//Set P2.1 as ADC input channel
	
	SN_ADC->IE |= ADC_IE_AIN1;													//Enable ADC channel P2.1 interrupt															
	
	#endif
		
	#if ADC_FUNCTION_TYPE == TS_TYPE
	
	SN_ADC->ADM_b.TSENB = ADC_TSENB_EN;									//Enable Temperature Sensor 
	SN_ADC->ADM_b.CHS = ADC_CHS_TS;											//Set P2.14 as Temperature Sensor channel
	SN_ADC->IE |= ADC_IE_TS;														//Enable Temperature Sensor interrupt		
	
	#endif
	
	ADC_NvicEnable();																		//Enable ADC NVIC interrupt
}

/*****************************************************************************
* Function		: ADC_Read
* Description	: Read ADC converted data
* Input			: None
* Output		: None
* Return		: Data in ADB register
* Note			: None
*****************************************************************************/
uint16_t ADC_Read(void)
{
	return	SN_ADC->ADB;
}

/*****************************************************************************
* Function		: ADC_IRQHandler
* Description	: ISR of ADC interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
__irq void ADC_IRQHandler(void)
{
	bADC_StartConv = 0;

	SN_ADC->RIS = 0x0;				//clear interrupt flag
}

/*****************************************************************************
* Function		: ADC_NvicEnable
* Description	: Enable ADC interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void ADC_NvicEnable(void)
{
	NVIC_ClearPendingIRQ(ADC_IRQn);
	NVIC_EnableIRQ(ADC_IRQn);
	NVIC_SetPriority(ADC_IRQn,0);			// Set interrupt priority (default)
}

/*****************************************************************************
* Function		: ADC_NvicDisable
* Description	: Disable ADC interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void ADC_NvicDisable(void)
{
	NVIC_DisableIRQ(ADC_IRQn);
}
