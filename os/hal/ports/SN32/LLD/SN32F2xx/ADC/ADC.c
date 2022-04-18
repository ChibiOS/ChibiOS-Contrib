/******************** (C) COPYRIGHT 2017 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2017/07
* AUTHOR:				SA1
* IC:						SN32F240B
* DESCRIPTION:	ADC related functions.
*____________________________________________________________________________
* REVISION	Date				User		Description
* 1.0				2017/07/07	SA1			First release
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
#include <SN32F2xx.h>
#include <SN32F200_Def.h>
#include "ADC.h"	

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
	SN_SYS1->AHBCLKEN_b.ADCCLKEN = 1;										//Enables HCLK for ADC
	
	SN_ADC->ADM_b.ADENB = ADC_ADENB_EN;									//Enable ADC
	
	UT_DelayNx10us(10);																	//Delay 100us
	
	SN_ADC->ADM_b.AVREFHSEL = ADC_AVREFHSEL_INTERNAL;		//Set ADC high reference voltage source from internal reference
	
	SN_ADC->ADM_b.VHS = ADC_VHS_VDD;										//Set ADC high reference voltage source as VDD
	
	SN_ADC->ADM_b.GCHS = ADC_GCHS_EN;										//Enable ADC global channel	
	
	SN_ADC->ADM_b.ADLEN = ADC_ADLEN_12BIT;							//Set ADC resolution = 12-bit			

	SN_ADC->ADM_b.ADCKS = ADC_ADCKS_DIV1;							//ADC_CLK = ADC_PCLK/1
	//SN_ADC->ADM_b.ADCKS = ADC_ADCKS_DIV2;							//ADC_CLK = ADC_PCLK/2
	//SN_ADC->ADM_b.ADCKS = ADC_ADCKS_DIV4;							//ADC_CLK = ADC_PCLK/4
	//SN_ADC->ADM_b.ADCKS = ADC_ADCKS_DIV8;							//ADC_CLK = ADC_PCLK/8
	//SN_ADC->ADM_b.ADCKS = ADC_ADCKS_DIV16;							//ADC_CLK = ADC_PCLK/16
	//SN_ADC->ADM_b.ADCKS = ADC_ADCKS_DIV32;							//ADC_CLK = ADC_PCLK/32
	
	SN_ADC->ADM_b.CHS = ADC_CHS_AIN1;										//Set P2.1 as ADC input channel
	
	SN_ADC->IE |= ADC_IE_AIN1;													//Enable ADC channel P2.1 interrupt															
	
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
