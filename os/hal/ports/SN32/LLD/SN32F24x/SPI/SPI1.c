/******************** (C) COPYRIGHT 2014 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2014/05
* AUTHOR:				SA1
* IC:				SN32F240/230/220 
* DESCRIPTION:	SPI1 related functions.
*____________________________________________________________________________
* REVISION	Date				User		Description
* 1.0				2013/12/17	SA1			1. First release
*	1.1				2014/05/23	SA1			1. Add __SSP1_DATA_FETCH_HIGH_SPEED macro
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
* Function		: SPI1_Init
* Description	: Initialization of SPI1 init
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void SPI1_Init(void)
{
	//Enable HCLK for SSP1
	SN_SYS1->AHBCLKEN |= (0x1 << 13);								//Enable clock for SSP1.

	//SSP1 PCLK
	SN_SYS1->APBCP0 |= (0x00 << 24); 								//PCLK = HCLK/1
	//SN_SYS1->APBCP0 |= (0x01 << 24);							//PCLK = HCLK/2  
	//SN_SYS1->APBCP0 |= (0x02 << 24);							//PCLK = HCLK/4 
	//SN_SYS1->APBCP0 |= (0x03 << 24);							//PCLK = HCLK/8 
	//SN_SYS1->APBCP0 |= (0x04 << 24);							//PCLK = HCLK/16 

	//SSP1 setting
	SN_SSP1->CTRL0_b.DL = SSP_DL_8;									//3 ~ 16 Data length
	SN_SSP1->CTRL0_b.FORMAT = SSP_FORMAT_SPI_MODE;	//Interface format      
	SN_SSP1->CTRL0_b.MS = SSP_MS_MASTER_MODE;				//Master/Slave selection bit
	SN_SSP1->CTRL0_b.LOOPBACK = SSP_LOOPBACK_DIS; 	//Loop back mode
	SN_SSP1->CTRL0_b.SDODIS = SSP_SDODIS_EN; 				//Slave data output 
																									
	SN_SSP1->CLKDIV_b.DIV = (SSP_DIV/2) - 1;				//SSPn clock divider
	
	//SSP1 SPI mode
	SN_SSP1->CTRL1 = SSP_CPHA_FALLING_EDGE|					//Clock phase for edge sampling
									 SSP_CPOL_SCK_IDLE_LOW|					//Clock polarity selection bit
									 SSP_MLSB_MSB;									//MSB/LSB selection bit
									 
	//SSP1 SEL1 Setting
	SN_SSP1->CTRL0_b.SELDIS = SSP_SELDIS_DIS; 			//Auto-SEL disable bit
	SN_GPIO2->MODE_b.MODE14=1;											//SEL1(P2.14) is outout high
	__SPI1_SET_SEL1;

	//SSP1 Fifo reset
	__SPI1_FIFO_RESET;	

	//SSP1 interrupt enable
	NVIC_ClearPendingIRQ(SSP1_IRQn);	
	NVIC_EnableIRQ(SSP1_IRQn);
	//NVIC_SetPriority(SSP1_IRQn,0);
	
	//__SSP1_DATA_FETCH_HIGH_SPEED;									//Enable if Freq. of SCK > 6MHz

	//SSP1 enable	
	SN_SSP1->CTRL0_b.SSPEN  = SSP_SSPEN_EN;    			//SSP enable bit
}

/*****************************************************************************
* Function		: SPI1_Enable
* Description	: SPI1 enable setting
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void SPI1_Enable(void)
{
	//Enable HCLK for SSP1
	SN_SYS1->AHBCLKEN |= (0x1 << 13);								//Enable clock for SSP0.

	SN_SSP1->CTRL0_b.SSPEN  = SSP_SSPEN_EN;    			//SSP enable bit
	__SPI1_FIFO_RESET;
}

/*****************************************************************************
* Function		: SPI1_Disable
* Description	: SPI1 disable setting
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void SPI1_Disable(void)
{
	 SN_SSP1->CTRL0_b.SSPEN  = SSP_SSPEN_DIS;    		//SSP disable bit
		
	//Disable HCLK for SSP1
	SN_SYS1->AHBCLKEN &=~ (0x1 << 13);							//Disable clock for SSP0.
}

