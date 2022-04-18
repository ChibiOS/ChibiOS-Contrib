/******************** (C) COPYRIGHT 2014 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2014/02
* AUTHOR:				SA1
* IC:						SN32F240/730/220
* DESCRIPTION:	I2S related functions.
*____________________________________________________________________________
* REVISION	Date				User		Description
* 1.0				2013/12/17	SA1			1. First release
*	2.0				2014/02/27	SA1			1. Update I2S functions.
*	3.2				2019/05/31	SA1			1. Fix I2S_Master_Init and I2S_Slave_Init.
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
#include "I2S.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/


/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ F U N C T I O N S __________________________________________________*/
/**************************************************************
* Function		: I2S_Master_INIT
* Description	: Set I2S as master
* Input			: None
* Output		: None
* Return		: None
* Note			: None
****************************************************************/
void I2S_Master_Init(void)
{
	__I2S_ENABLE_I2SHCLK;														//Enable HCLK for I2S

	SN_I2S->CTRL_b.I2SEN = I2S_I2SEN_EN;						//I2S enable bit
	SN_I2S->CTRL_b.CHLENGTH = I2S_CHLENGTH_32BITS;	//Single channel[4:0]
	SN_I2S->CTRL_b.RXFIFOTH = I2S_RXFIFOTH_2;				//RX FIFO Threshold level
	SN_I2S->CTRL_b.TXFIFOTH = I2S_TXFIFOTH_6;				//TX FIFO Threshold level

	SN_I2S->CTRL_b.DL = I2S_DL_24BITS;							//I2S Data Length
	__I2S_RESET_RXFIFO;															//Clear I2S RX FIFO
	__I2S_RESET_TXFIFO;															//Clear I2S TX FIFO
	SN_I2S->CTRL_b.RXEN = I2S_RXEN_EN;							//Receiver enable bit
	SN_I2S->CTRL_b.TXEN = I2S_TXEN_EN;							//Transmit enable bit

	SN_I2S->CTRL_b.FORMAT=I2S_FORMAT_STANDARD;			//I2S operation format
	SN_I2S->CTRL_b.MS=I2S_MS_MASTER_MODE;						//Master selection bit
	SN_I2S->CTRL_b.MONO=I2S_MONO_STERO;							//Stereo selection bit
	SN_I2S->CTRL_b.MUTE=I2S_MUTE_DIS;								//Mute enable bit

	//I2S clk
	SN_I2S->CLK = mskI2S_CLKSEL_HCLK|								//I2S clock source selection
								mskI2S_BCLKDIV_DIV|								//MCLK/n, n = 2, 4, 6, 8, ...,512
								mskI2S_MCLKSEL_I2S_PCLK|					//MCLK source of master is from I2S_PCLK
								mskI2S_MCLKOEN_OUTPUT_DIS|				//MCLK output enable bit
								mskI2S_MCLKDIV_DIV3;							//MCLK = MCLK source / 6
}

/**************************************************************
* Function		: I2S_Slave_Init
* Description	: Set I2S as slave
* Input			: None
* Output		: None
* Return		: None
* Note			: None
****************************************************************/
void I2S_Slave_Init(void)
{
	__I2S_ENABLE_I2SHCLK;														//Enable HCLK for I2S

	SN_I2S->CTRL_b.I2SEN = I2S_I2SEN_EN ;										//I2S enable bit
	SN_I2S->CTRL_b.CHLENGTH = I2S_CHLENGTH_32BITS;					//Single channel[4:0]
	SN_I2S->CTRL_b.RXFIFOTH = I2S_RXFIFOTH_2;								//RX FIFO Threshold level
	SN_I2S->CTRL_b.TXFIFOTH = I2S_TXFIFOTH_6;

	SN_I2S->CTRL_b.DL = I2S_DL_24BITS;											//I2S Data Length
	__I2S_RESET_RXFIFO;																			//Clear I2S RX FIFO
	__I2S_RESET_TXFIFO;																			//Clear I2S TX FIFO
	SN_I2S->CTRL_b.RXEN = I2S_RXEN_EN;											//Receiver enable bit
	SN_I2S->CTRL_b.TXEN = I2S_TXEN_EN;

	SN_I2S->CTRL_b.FORMAT=I2S_FORMAT_STANDARD;							//I2S operation format
	SN_I2S->CTRL_b.MS=I2S_MS_SLAVE_MODE;										//Master selection bit
	SN_I2S->CTRL_b.MONO=I2S_MONO_STERO;											//Stereo selection bit
	SN_I2S->CTRL_b.MUTE=I2S_MUTE_DIS;
}

/*****************************************************************************
* Function		: I2S_Enable
* Description	: I2S enable
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void I2S_Enable(void)
{
	__I2S_ENABLE_I2SHCLK;														//Enable HCLK for I2S

	SN_I2S->CTRL_b.I2SEN = I2S_I2SEN_EN ;						//I2S enable bit
	__I2S_RESET_TXFIFO;
	__I2S_RESET_RXFIFO;
}

/*****************************************************************************
* Function		: I2S_Disable
* Description	: I2S disable
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void I2S_Disable(void)
{
	 SN_I2S->CTRL_b.I2SEN   = I2S_I2SEN_DIS;    		//I2S disable bit

	__I2S_DISABLE_I2SHCLK;													//Disable HCLK for I2S
}

/**********************************
* Function		: I2S_Interrupt_Enable
* Description	: I2S interrupt enable
* Input			: None
* Output		: None
* Return		: None
* Note			: None
**********************************/
void I2S_Interrupt_Enable(void)
{
		SN_I2S->IC = mskI2S_RXFIFOTHIC|								//Clear RXFIFOTHIF bit
								 mskI2S_TXFIFOTHIC|								//Clear TXFIFOTHIF bit
								 mskI2S_RXFIFOUDIC|								//Clear RXFIFOOUDIF bit
								 mskI2S_TXFIFOOVIC;								//Clear TXFIFOOVIF bit

		SN_I2S->IE = mskI2S_TXFIFOOVFIEN_EN|					//TX FIFO overflow interrupt enable bit
								 mskI2S_RXFIFOUDFIEN_EN|					//RX FIFO underflow interrupt enable bit
								 mskI2S_TXFIFOTHIEN_EN|						//TX FIFO threshold interrupt enable bit
								 mskI2S_RXFIFOTHIEN_EN;						//RX FIFO threshold interrupt enable bit
}
