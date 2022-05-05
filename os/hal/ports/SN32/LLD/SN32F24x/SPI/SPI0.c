/******************** (C) COPYRIGHT 2014 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2014/05
* AUTHOR:				SA1
* IC:				SN32F240/230/220 
* DESCRIPTION:	SPI0 related functions.
*____________________________________________________________________________
*	REVISION	Date				User		Description
*	1.0				2013/12/17	SA1			1. First release
*	1.1				2014/05/23	SA1			1. Add __SSP0_DATA_FETCH_HIGH_SPEED macro
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
#include "SPI.h"
#include "..\..\Utility\Utility.h"


/*_____ D E C L A R A T I O N S ____________________________________________*/


/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ F U N C T I O N S __________________________________________________*/

/*****************************************************************************
* Function		: SPI0_Init
* Description	: Initialization of SPI0 init
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void SPI0_Init(void)
{
	//Enable HCLK for SSP0
	SN_SYS1->AHBCLKEN |= (0x1 << 12);								//Enable clock for SSP0.

	//SSP0 PCLK
	SN_SYS1->APBCP0 |= (0x00 << 20); 								//PCLK = HCLK/1
	//SN_SYS1->APBCP0 |= (0x01 << 20);							//PCLK = HCLK/2  
	//SN_SYS1->APBCP0 |= (0x02 << 20);							//PCLK = HCLK/4 
	//SN_SYS1->APBCP0 |= (0x03 << 20);							//PCLK = HCLK/8 
	//SN_SYS1->APBCP0 |= (0x04 << 20);							//PCLK = HCLK/16 

	//SSP0 setting
	SN_SSP0->CTRL0_b.DL = SSP_DL_8;									//3 ~ 16 Data length
	SN_SSP0->CTRL0_b.FORMAT = SSP_FORMAT_SPI_MODE;	//Interface format      
	SN_SSP0->CTRL0_b.MS = SSP_MS_MASTER_MODE;				//Master/Slave selection bit
	SN_SSP0->CTRL0_b.LOOPBACK = SSP_LOOPBACK_DIS; 	//Loop back mode
	SN_SSP0->CTRL0_b.SDODIS = SSP_SDODIS_EN; 				//Slave data output 
																									//(ONLY used in slave mode)
																									
	SN_SSP0->CLKDIV_b.DIV = (SSP_DIV/2) - 1;				//SSPn clock divider

	//SSP0 SPI mode
	SN_SSP0->CTRL1 = SSP_CPHA_FALLING_EDGE|					//Clock phase for edge sampling
									 SSP_CPOL_SCK_IDLE_LOW|					//Clock polarity selection bit
									 SSP_MLSB_MSB;									//MSB/LSB selection bit

	//SSP0 SEL0 setting
	SN_SSP0->CTRL0_b.SELDIS = SSP_SELDIS_DIS; 			//Auto-SEL disable bit
	SN_GPIO2->MODE_b.MODE15=1;											//SEL(P2.15) is outout high
	__SPI0_SET_SEL0;

	//SSP0 Fifo reset
	__SPI0_FIFO_RESET;
	
	//SSP0 interrupt enable
	NVIC_ClearPendingIRQ(SSP0_IRQn);
	NVIC_EnableIRQ(SSP0_IRQn);
	//NVIC_SetPriority(SSP0_IRQn,0);
	
	//__SSP0_DATA_FETCH_HIGH_SPEED;									//Enable if Freq. of SCK > 6MHz

	//SSP0 enable	
	SN_SSP0->CTRL0_b.SSPEN  = SSP_SSPEN_EN;    			//SSP enable bit	
}

/*****************************************************************************
* Function		: SPI0_Enable
* Description	: SPI0 enable setting
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void SPI0_Enable(void)
{
	//Enable HCLK for SSP0
	SN_SYS1->AHBCLKEN |= (0x1 << 12);								//Enable clock for SSP0.

  SN_SSP0->CTRL0_b.SSPEN  = SSP_SSPEN_EN;    			//SSP enable bit
	__SPI0_FIFO_RESET;
}

/*****************************************************************************
* Function		: SPI0_Disable
* Description	: SPI0 disable setting
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void SPI0_Disable(void)
{
  SN_SSP0->CTRL0_b.SSPEN  = SSP_SSPEN_DIS;    		//SSP disable bit

	//Disable HCLK for SSP0
	SN_SYS1->AHBCLKEN &=~ (0x1 << 12);							//Disable clock for SSP0.
}

