/******************** (C) COPYRIGHT 2013 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2013/12
* AUTHOR:				SA1
* IC:						SN32F240/230/220
* DESCRIPTION:	CT32B2 related functions.
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
#include "CT32.h"
#include "CT32B2.h"


/*_____ D E C L A R A T I O N S ____________________________________________*/
volatile uint32_t	iwCT32B2_IrqEvent = 0x00; //The bitmask usage of iwCT32Bn_IrqEvent is the same with CT32Bn_RIS

void	CT32B2_Init (void);
void	CT32B2_NvicEnable (void);
void	CT32B2_NvicDisable (void);

/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ F U N C T I O N S __________________________________________________*/

/*****************************************************************************
* Function		: CT32B2_Init
* Description	: Initialization of CT32B2 timer
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void	CT32B2_Init (void)
{
	//Enable P_CLOCK for CT32B2.
	__CT32B2_ENABLE;					

	//CT32B2 PCLK prescalar setting
	SN_SYS1->APBCP0_b.CT32B2PRE = 0x00;							//PCLK = HCLK/1
	//SN_SYS1->APBCP0_b.CT32B2PRE = 0x01;						//PCLK = HCLK/2  
	//SN_SYS1->APBCP0_b.CT32B2PRE = 0x02;						//PCLK = HCLK/4 
	//SN_SYS1->APBCP0_b.CT32B2PRE = 0x03;						//PCLK = HCLK/8 
	//SN_SYS1->APBCP0_b.CT32B2PRE = 0x04;						//PCLK = HCLK/16 
}

/*****************************************************************************
* Function		: CT32B2_NvicEnable
* Description	: Enable CT32B2 timer interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void	CT32B2_NvicEnable (void)
{
	NVIC_ClearPendingIRQ(CT32B2_IRQn);
	NVIC_EnableIRQ(CT32B2_IRQn);
	//NVIC_SetPriority(CT32B2_IRQn,0);		//Set interrupt priority (default)
}

/*****************************************************************************
* Function		: CT32B2_NvicDisable
* Description	: Disable CT32B2 timer interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void	CT32B2_NvicDisable (void)
{
	NVIC_DisableIRQ(CT32B2_IRQn);
}


/*****************************************************************************
* Function		: TIMER32_0_IRQHandler
* Description	: ISR of CT32B2 interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void CT32B2_IRQHandler(void)
{
	uint32_t iwRisStatus;

	iwRisStatus = SN_CT32B2->RIS;	// Save the interrupt status.
	
	//Before checking the status, always re-check the interrupt enable register first.
	//In practice, user might use only one or two timer interrupt source. 
	//Ex: Enable only MR0IE and MR3IE ==> No check on MR1IE, MR2IE, and CAP0IE is necessary.
  //User can add the directive pair of "#if 0" and "#endif" pair 
	//to COMMENT the un-used parts to reduce ISR overheads and ROM usage.
	
	//Check the status in oder.
	//MR0
	if (SN_CT32B2->MCTRL_b.MR0IE)				//Check if MR0 IE enables?
	{
		if(iwRisStatus & mskCT32_MR0IF)				
		{
			iwCT32B2_IrqEvent |= mskCT32_MR0IF;				
			SN_CT32B2->IC = mskCT32_MR0IC;	//Clear MR0 match interrupt status
		}
	}
	//MR1
	if (SN_CT32B2->MCTRL_b.MR1IE)				//Check if MR1 IE enables?
	{
		if(iwRisStatus & mskCT32_MR1IF)		
		{
			iwCT32B2_IrqEvent |= mskCT32_MR1IF;			
			SN_CT32B2->IC = mskCT32_MR1IC;	//Clear MR1 match interrupt status
		}
	}
	//MR2
	if (SN_CT32B2->MCTRL_b.MR2IE)				//Check if MR2 IE enables?
	{
		if(iwRisStatus & mskCT32_MR2IF)		
		{
			iwCT32B2_IrqEvent |= mskCT32_MR2IF;		
			SN_CT32B2->IC = mskCT32_MR2IC;	//Clear MR2 match interrupt status
		}
	}
	//MR3
	if (SN_CT32B2->MCTRL_b.MR3IE)				//Check if MR3 IE enables?
	{	
		if(iwRisStatus & mskCT32_MR3IF)	
		{
			iwCT32B2_IrqEvent |= mskCT32_MR3IF;		
			SN_CT32B2->IC = mskCT32_MR3IC;	//Clear MR3 match interrupt status
		}
	}
	//CAP0
	if (SN_CT32B2->CAPCTRL_b.CAP0IE)		//Check if CAP0 IE enables?
	{
		if(iwRisStatus & mskCT32_CAP0IF)	//CAP0
		{
			iwCT32B2_IrqEvent |= mskCT32_CAP0IF;	
			SN_CT32B2->IC = mskCT32_CAP0IC;	//Clear CAP0 interrupt status
		}	
	}		
}



