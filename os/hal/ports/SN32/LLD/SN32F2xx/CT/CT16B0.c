/******************** (C) COPYRIGHT 2013 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2013/12
* AUTHOR:				SA1
* IC:						SN32F240/230/220
* DESCRIPTION:	CT16B0 related functions.
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
#include "sn32_ct.h"


/*_____ D E C L A R A T I O N S ____________________________________________*/
volatile uint32_t iwCT16B0_IrqEvent = 0x00; //The bitmask usage of iwCT16Bn_IrqEvent is the same with CT16Bn_RIS

void	CT16B0_Init (void);
void	CT16B0_NvicEnable (void);
void	CT16B0_NvicDisable (void);

/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ F U N C T I O N S __________________________________________________*/
/*****************************************************************************
* Function		: CT16B0_Init
* Description	: Initialization of CT16B0 timer
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void CT16B0_Init (void)
{
	//Enable P_CLOCK for CT16B0.
	sys1EnableCT16B0();

	//CT16B0 PCLK prescalar setting
	// SN_SYS1->APBCP1_b.CT16B0PRE = 0x00;							//PCLK = HCLK/1
	//SN_SYS1->APBCP0_b.CT16B0PRE = 0x01;						//PCLK = HCLK/2
	//SN_SYS1->APBCP0_b.CT16B0PRE = 0x02;						//PCLK = HCLK/4
	//SN_SYS1->APBCP0_b.CT16B0PRE = 0x03;						//PCLK = HCLK/8
	//SN_SYS1->APBCP0_b.CT16B0PRE = 0x04;						//PCLK = HCLK/16
}
/*****************************************************************************
* Function		: CT16B0_ResetTimer
* Description	: Reset of CT16B0 timer
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void CT16B0_ResetTimer (void)
{
	//Set CT16B0 as the up-counting mode.
	SN_CT16B0->TMRCTRL = (mskCT16_CRST);

    // Wait until timer reset done.
    while (SN_CT16B0->TMRCTRL & mskCT16_CRST);
}
/*****************************************************************************
* Function		: CT16B0_NvicEnable
* Description	: Enable CT16B0 timer interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void CT16B0_NvicEnable (void)
{
	NVIC_ClearPendingIRQ(CT16B0_IRQn);
	NVIC_EnableIRQ(CT16B0_IRQn);
	//NVIC_SetPriority(CT16B0_IRQn,0);		// Set interrupt priority (default)
}

/*****************************************************************************
* Function		: CT16B0_NvicEnable
* Description	: Disable CT16B0 timer interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void CT16B0_NvicDisable (void)
{
	NVIC_DisableIRQ(CT16B0_IRQn);
}



/*****************************************************************************
* Function		: CT16B0_IRQHandler
* Description	: ISR of CT16B0 interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void CT16B0_IRQHandler(void)
{
	uint32_t iwRisStatus;

	iwRisStatus = SN_CT16B0->RIS;	//Save the interrupt status.

	//Before checking the status, always re-check the interrupt enable register first.
	//In practice, user might use only one or two timer interrupt source.
	//Ex: Enable only MR0IE and MR3IE ==> No check on MR1IE, MR2IE, and CAP0IE is necessary.
  //User can add the directive pair of "#if 0" and "#endif" pair
	//to COMMENT the un-used parts to reduce ISR overheads and ROM usage.

	//Check the status in oder.
	//MR0
	if (SN_CT16B0->MCTRL_b.MR0IE)				//Check if MR0 IE enables?
	{
		if(iwRisStatus & mskCT16_MR0IF)
		{
			iwCT16B0_IrqEvent |= mskCT16_MR0IF;
			SN_CT16B0->IC = mskCT16_MR0IC;	//Clear MR0 match interrupt status
		}
	}
	//CAP0
	if (SN_CT16B0->CAPCTRL_b.CAP0IE)		//Check if CAP0 IE enables?
	{
		if(iwRisStatus & mskCT16_CAP0IF)	//CAP0
		{
			iwCT16B0_IrqEvent |= mskCT16_CAP0IF;
			SN_CT16B0->IC = mskCT16_CAP0IC;	//Clear CAP0 interrupt status
		}
	}
}



