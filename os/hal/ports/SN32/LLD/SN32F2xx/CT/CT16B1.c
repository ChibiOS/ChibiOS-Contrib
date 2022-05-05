/******************** (C) COPYRIGHT 2013 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2013/12
* AUTHOR:				SA1
* IC:						SN32F240/230/220
* DESCRIPTION:	CT16B1 related functions.
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
volatile uint32_t iwCT16B1_IrqEvent = 0x00; //The bitmask usage of iwCT16Bn_IrqEvent is the same with CT16Bn_RIS

void	CT16B1_Init (void);
void	CT16B1_NvicEnable (void);
void	CT16B1_NvicDisable (void);

/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ F U N C T I O N S __________________________________________________*/
/*****************************************************************************
* Function		: CT16B1_Init
* Description	: Initialization of CT16B1 timer
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void	CT16B1_Init (void)
{
	//Enable P_CLOCK for CT16B1.
	sys1EnableCT16B1();

	//CT16B1 PCLK prescalar setting
	//SN_SYS1->APBCP1_b.CT16B1PRE = 0x00;							//PCLK = HCLK/1
	//SN_SYS1->APBCP1_b.CT16B1PRE = 0x01;						//PCLK = HCLK/2
	//SN_SYS1->APBCP1_b.CT16B1PRE = 0x02;						//PCLK = HCLK/4
	//SN_SYS1->APBCP1_b.CT16B1PRE = 0x03;						//PCLK = HCLK/8
	//SN_SYS1->APBCP1_b.CT16B1PRE = 0x04;						//PCLK = HCLK/16
}

/*****************************************************************************
* Function		: CT16B1_ResetTimer
* Description	: Reset of CT16B1 timer
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void CT16B1_ResetTimer (void)
{
	//Set CT16B1 as the up-counting mode.
	SN_CT16B1->TMRCTRL = (mskCT16_CRST);

    // Wait until timer reset done.
    while (SN_CT16B1->TMRCTRL & mskCT16_CRST);
}

/*****************************************************************************
* Function		: CT16B1_NvicEnable
* Description	: Enable CT16B1 timer interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void	CT16B1_NvicEnable (void)
{
	NVIC_ClearPendingIRQ(CT16B1_IRQn);
	NVIC_EnableIRQ(CT16B1_IRQn);
	//NVIC_SetPriority(CT16B1_IRQn,0);			// Set interrupt priority (default)
}

/*****************************************************************************
* Function		: CT16B1_NvicDisable
* Description	: Enable CT16B1 timer interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void	CT16B1_NvicDisable (void)
{
	NVIC_DisableIRQ(CT16B1_IRQn);
}

/*****************************************************************************
* Function		: CT16B1_IRQHandler
* Description	: ISR of CT16B1 interrupt
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void	CT16B1_IRQHandler(void)
{
	uint32_t iwRisStatus;

	iwRisStatus = SN_CT16B1->RIS;	//Save the interrupt status.

	//Before checking the status, always re-check the interrupt enable register first.
	//In practice, user might use only one or two timer interrupt source.
	//Ex: Enable only MR0IE and MR3IE ==> No check on MR1IE, MR2IE, and CAP0IE is necessary.
  //User can add the directive pair of "#if 0" and "#endif" pair
	//to COMMENT the un-used parts to reduce ISR overheads and ROM usage.

	//Check the status in oder.
	//MR0
	if (SN_CT16B1->MCTRL_b.MR0IE)				//Check if MR0 IE enables?
	{
		if(iwRisStatus & mskCT16_MR0IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR0IF;
			SN_CT16B1->IC = mskCT16_MR0IC;	//Clear MR0 match interrupt status
		}
	}
	//MR1
	if (SN_CT16B1->MCTRL_b.MR1IE)				//Check if MR1 IE enables?
	{
		if(iwRisStatus & mskCT16_MR1IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR1IF;
			SN_CT16B1->IC = mskCT16_MR1IC;	//Clear MR1 match interrupt status
		}
	}
	//MR2
	if (SN_CT16B1->MCTRL_b.MR2IE)				//Check if MR2 IE enables?
	{
		if(iwRisStatus & mskCT16_MR2IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR2IF;
			SN_CT16B1->IC = mskCT16_MR2IC;	//Clear MR2 match interrupt status
		}
	}
	//MR3
	if (SN_CT16B1->MCTRL_b.MR3IE)				//Check if MR3 IE enables?
	{
		if(iwRisStatus & mskCT16_MR3IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR3IF;
			SN_CT16B1->IC = mskCT16_MR3IC;	//Clear MR3 match interrupt status
		}
	}
	//MR4
	if (SN_CT16B1->MCTRL_b.MR4IE)				//Check if MR4 IE enables?
	{
		if(iwRisStatus & mskCT16_MR4IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR4IF;
			SN_CT16B1->IC = mskCT16_MR4IC;	//Clear MR4 match interrupt status
		}
	}
	//MR5
	if (SN_CT16B1->MCTRL_b.MR5IE)				//Check if MR5 IE enables?
	{
		if(iwRisStatus & mskCT16_MR5IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR5IF;
			SN_CT16B1->IC = mskCT16_MR5IC;	//Clear MR5 match interrupt status
		}
	}
	//MR6
	if (SN_CT16B1->MCTRL_b.MR6IE)				//Check if MR6 IE enables?
	{
		if(iwRisStatus & mskCT16_MR6IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR6IF;
			SN_CT16B1->IC = mskCT16_MR6IC;	//Clear MR6 match interrupt status
		}
	}
	//MR7
	if (SN_CT16B1->MCTRL_b.MR7IE)				//Check if MR7 IE enables?
	{
		if(iwRisStatus & mskCT16_MR7IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR7IF;
			SN_CT16B1->IC = mskCT16_MR7IC;	//Clear MR7 match interrupt status
		}
	}
	//MR8
	if (SN_CT16B1->MCTRL_b.MR8IE)				//Check if MR8 IE enables?
	{
		if(iwRisStatus & mskCT16_MR8IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR8IF;
			SN_CT16B1->IC = mskCT16_MR8IC;	//Clear MR8 match interrupt status
		}
	}
	//MR9
	if (SN_CT16B1->MCTRL_b.MR9IE)				//Check if MR9 IE enables?
	{
		if(iwRisStatus & mskCT16_MR9IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR9IF;
			SN_CT16B1->IC = mskCT16_MR9IC;	//Clear MR9 match interrupt status
		}
	}
	//MR10
	if (SN_CT16B1->MCTRL2_b.MR10IE)				//Check if MR10 IE enables?
	{
		if(iwRisStatus & mskCT16_MR10IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR10IF;
			SN_CT16B1->IC = mskCT16_MR10IC;	//Clear MR10 match interrupt status
		}
	}
	//MR11
	if (SN_CT16B1->MCTRL2_b.MR11IE)				//Check if MR11 IE enables?
	{
		if(iwRisStatus & mskCT16_MR11IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR11IF;
			SN_CT16B1->IC = mskCT16_MR11IC;	//Clear MR11 match interrupt status
		}
	}
	//MR12
	if (SN_CT16B1->MCTRL2_b.MR12IE)				//Check if MR12 IE enables?
	{
		if(iwRisStatus & mskCT16_MR12IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR12IF;
			SN_CT16B1->IC = mskCT16_MR12IC;	//Clear MR12 match interrupt status
		}
	}
	//MR13
	if (SN_CT16B1->MCTRL2_b.MR13IE)				//Check if MR13 IE enables?
	{
		if(iwRisStatus & mskCT16_MR13IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR13IF;
			SN_CT16B1->IC = mskCT16_MR13IC;	//Clear MR13 match interrupt status
		}
	}
	//MR14
	if (SN_CT16B1->MCTRL2_b.MR14IE)				//Check if MR14 IE enables?
	{
		if(iwRisStatus & mskCT16_MR14IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR14IF;
			SN_CT16B1->IC = mskCT16_MR14IC;	//Clear MR14 match interrupt status
		}
	}
	//MR15
	if (SN_CT16B1->MCTRL2_b.MR15IE)				//Check if MR15 IE enables?
	{
		if(iwRisStatus & mskCT16_MR15IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR15IF;
			SN_CT16B1->IC = mskCT16_MR15IC;	//Clear MR15 match interrupt status
		}
	}
	//MR16
	if (SN_CT16B1->MCTRL2_b.MR16IE)				//Check if MR16 IE enables?
	{
		if(iwRisStatus & mskCT16_MR16IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR16IF;
			SN_CT16B1->IC = mskCT16_MR16IC;	//Clear MR16 match interrupt status
		}
	}
	//MR17
	if (SN_CT16B1->MCTRL2_b.MR17IE)				//Check if MR17 IE enables?
	{
		if(iwRisStatus & mskCT16_MR17IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR17IF;
			SN_CT16B1->IC = mskCT16_MR17IC;	//Clear MR17 match interrupt status
		}
	}
	//MR18
	if (SN_CT16B1->MCTRL2_b.MR18IE)				//Check if MR18 IE enables?
	{
		if(iwRisStatus & mskCT16_MR18IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR18IF;
			SN_CT16B1->IC = mskCT16_MR18IC;	//Clear MR18 match interrupt status
		}
	}
	//MR19
	if (SN_CT16B1->MCTRL2_b.MR19IE)				//Check if MR19 IE enables?
	{
		if(iwRisStatus & mskCT16_MR19IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR19IF;
			SN_CT16B1->IC = mskCT16_MR19IC;	//Clear MR19 match interrupt status
		}
	}
	//MR20
	if (SN_CT16B1->MCTRL3_b.MR20IE)				//Check if MR20 IE enables?
	{
		if(iwRisStatus & mskCT16_MR20IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR20IF;
			SN_CT16B1->IC = mskCT16_MR20IC;	//Clear MR20 match interrupt status
		}
	}
	//MR21
	if (SN_CT16B1->MCTRL3_b.MR21IE)				//Check if MR21 IE enables?
	{
		if(iwRisStatus & mskCT16_MR21IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR21IF;
			SN_CT16B1->IC = mskCT16_MR21IC;	//Clear MR21 match interrupt status
		}
	}
	//MR22
	if (SN_CT16B1->MCTRL3_b.MR22IE)				//Check if MR22 IE enables?
	{
		if(iwRisStatus & mskCT16_MR22IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR22IF;
			SN_CT16B1->IC = mskCT16_MR22IC;	//Clear MR22 match interrupt status
		}
	}
	//MR23
	if (SN_CT16B1->MCTRL3_b.MR23IE)				//Check if MR23 IE enables?
	{
		if(iwRisStatus & mskCT16_MR23IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR23IF;
			SN_CT16B1->IC = mskCT16_MR23IC;	//Clear MR23 match interrupt status
		}
	}
#if SN32_CT16B1_CHANNELS > 23
	//MR24
	if (SN_CT16B1->MCTRL3_b.MR24IE)				//Check if MR24 IE enables?
	{
		if(iwRisStatus & mskCT16_MR24IF)
		{
			iwCT16B1_IrqEvent |= mskCT16_MR24IF;
			SN_CT16B1->IC = mskCT16_MR24IC;	//Clear MR24 match interrupt status
		}
	}
#endif
}



