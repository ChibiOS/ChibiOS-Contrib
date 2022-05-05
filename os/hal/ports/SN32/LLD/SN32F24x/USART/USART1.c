/******************** (C) COPYRIGHT 2015 SONiX *******************************
* COMPANY:	SONiX
* DATE:			2015/05
* AUTHOR:		SA1
* IC:				SN32F240/230/220 
* DESCRIPTION:	USART1 related functions.
*____________________________________________________________________________
*	REVISION	Date				User	Description
*	1.0				2013/12/17	SA1		First release
*	1.1				2014/01/20	SA1		1. Modify USART0_SendByte sub function
*	1.2				2014/02/27	SA1		1. Fix typing errors.
*	1.22			2014/05/23	SA1		1. Fix USART1_Init for BR=115200
*	2.0				2015/05/29	SA1		1. Fix USART1_Init for BR=115200 & 57600 @ PCLK=12MHz
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
#include "USART.h"
#include "..\..\Utility\Utility.h"


/*_____ D E C L A R A T I O N S ____________________________________________*/
volatile uint8_t bUSART1_RecvNew;
uint32_t GulNum1;
uint8_t  bUSART1_RecvFIFO[16];


/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ F U N C T I O N S __________________________________________________*/

/*****************************************************************************
* Function		: UART1_IRQHandler
* Description	: USART1 interrupt service routine
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
__irq void USART1_IRQHandler (void)
{
	uint32_t II_Buf, LS_Buf;
	volatile uint32_t Null_Buf;

	II_Buf = SN_USART1->II;
	while ((II_Buf & mskUSART_II_STATUS) == USART_II_STATUS)		//check interrupt status, the INT can be determined by USARTn_II[3:1]
	{
		switch ((II_Buf>>1) & mskUSART_INTID_STATUS)
		{
			case USART_RLS:		//Receive Line Status
				LS_Buf = SN_USART1->LS;
				if((LS_Buf & mskUSART_LS_OE) ==  USART_LS_OE) 	//Overrun Error
				{ }
				if((LS_Buf & mskUSART_LS_RXFE) == USART_LS_RXFE)//RX FIFO Error
				{
					if((LS_Buf & mskUSART_LS_PE) == USART_LS_PE)//Parity Error
						Null_Buf = SN_USART1->RB;	//Clear interrupt
					if((LS_Buf & mskUSART_LS_FE) == USART_LS_FE)	//Framing Error
						Null_Buf = SN_USART1->RB;	//Clear interrupt
					if((LS_Buf & mskUSART_LS_BI) == USART_LS_BI)	//Break Interrupt
						Null_Buf = SN_USART1->RB;	//Clear interrupt
				}
				break;

      case USART_RDA:		//Receive Data Available
      case USART_CTI:		//Character Time-out Indicator
				LS_Buf = SN_USART1->LS;
        bUSART1_RecvNew = 1;                                        
				if((LS_Buf & mskUSART_LS_RDR) == USART_LS_RDR)//Receiver Data Ready
				{
					bUSART1_RecvFIFO[GulNum1] = SN_USART1->RB;
					GulNum1++;
				}
				if(GulNum1 == 16)
					GulNum1 = 0;
        break;
            
			case USART_THRE:		//THRE interrupt
				LS_Buf = SN_USART1->LS;
				if((LS_Buf & mskUSART_LS_THRE) == USART_LS_THRE)//THRE empty
				{	//SN_USART1->TH = Null_Buf; 	//Clear interrupt
				}
				break;

			case USART_TEMT:		//TEMT interrupt
				LS_Buf = SN_USART1->LS;
				if((LS_Buf & mskUSART_LS_TEMT) == USART_LS_TEMT)
				{	//SN_USART1->TH = Null_Buf; 	//Clear interrupt
				}
				break;
			
			default:
         break;
    } //end switch ((II_Buf>>1) & mskUSART_INTID_STATUS)

		II_Buf = SN_USART1->II;
  }	//end  while ((II_Buf&0x01) == mskUSART_II_STATUS)

	if ((II_Buf & mskUSART_II_ABEOIF) ==  USART_II_ABEOIF) //Auto Baud interrupt
		SN_USART1->ABCTRL |= USART_ABEO_EN;
	else if((II_Buf & mskUSART_II_ABTOIF) ==  USART_II_ABTOIF) //Auto Baud time-out interrupt
		SN_USART1->ABCTRL |= USART_ABTO_EN;

	if((II_Buf & mskUSART_II_TXERRIF) ==  USART_II_TXERRIF)//TXERR interrupt
	{
		LS_Buf = SN_USART1->LS;
		if ((LS_Buf & mskUSART_LS_TXERR) == USART_LS_THERR)//TX Error
			SN_USART1->FIFOCTRL|= USART_TXFIFO_RESET;			//TX FIFO Reset
	}
}


/*****************************************************************************
* Function		: USART1_Init
* Description	: Initialization of USART1
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USART1_Init (void)
{
	SN_SYS1->AHBCLKEN |= USART1_CLK_EN;			//Enables clock for USART0
	
	SN_SYS1->APBCP1 |= USART1_PLKSEL_DIV1;		//USART0 PCLK = HCLK/1 = 12MHz
	//SN_SYS1->APBCP1 |= USART1_PLKSEL_DIV2;	//USART0 PCLK = HCLK/2 = 6MHz
	//SN_SYS1->APBCP1 |= USART1_PLKSEL_DIV4;	//USART0 PCLK = HCLK/4 = 3MHz
	//SN_SYS1->APBCP1 |= USART1_PLKSEL_DIV8;	//USART0 PCLK = HCLK/8 = 1.5MHz
	//SN_SYS1->APBCP1 |= USART1_PLKSEL_DIV16;	//USART0 PCLK = HCLK/16= 0.75MHz
	
	//===Line Control===
	//setting character Word length(5/6/7/8 bit)
	SN_USART1->LC = (USART_CHARACTER_LEN8BIT		//8bit character length.
								|	USART_STOPBIT_1BIT					//stop bit of 1 bit
								|	USART_PARITY_BIT_DISEN			//parity bit is disable
								|	USART_PARITY_SELECTODD			//parity bit is odd
								|	USART_BREAK_DISEN		//Break Transmission control disable
								|	USART_DIVISOR_EN);		//Divisor Latch Access enable
			
	//===Baud Rate Calculation===
	//USART PCLK = 12MHz, Baud rate = 115200
	SN_USART1->FD = (USART_OVER_SAMPLE_16|USART_MULVAL_7|USART_DIVADDVAL_5);
  SN_USART1->DLM  = 0;
  SN_USART1->DLL  = 4;
	/*
	//USART PCLK = 12MHz, Baud rate = 57600
	SN_USART1->FD = (OVER_SAMPLE_16|USART_MULVAL_7|USART_DIVADDVAL_5);
  SN_USART1->DLM  = 0;
  SN_USART1->DLL  = 8;
	*/
	SN_USART1->LC &= ~(USART_DIVISOR_EN);		//Disable divisor latch
	
	//===Auto Baud Rate===
	//USART0_Autobaudrate_Init();		//Auto buad rate initial

	//===FIFO Control===
	SN_USART1->FIFOCTRL  =(USART_FIFO_ENABLE					//Enable USART FIFOs
											|	USART_RXFIFO_RESET				//RX FIFO Reset
											|	USART_TXFIFO_RESET				//TX FIFO Reset
											|	USART_RXTRIGGER_LEVEL1);		//RX Trigger Level(1/4/8/14 characters)

	//===Scratch Pad===
	//SN_USART1->SP = 0;												//A readable, writable byte

	//===Oversampling===
	//SN_USART1->FD |= USART_OVER_SAMPLE_8;		//OVER8(Oversampling Value), 1:Oversampling by 8. 0:Oversampling by 16

	//===Half-duplex===
	//SN_USART1->HDEN = 1;											//Half-duplex mode enable

	//===Interrupt Enable===
	USART1_InterruptEnable();

	//===USART Control===
	SN_USART1->CTRL =(USART_EN										//Enable USART0
									| USART_MODE_UART 						//USART Mode = USAT
									|	USART_RX_EN									//Enable RX
									| USART_TX_EN);								//Enable TX
	//===NVIC===
	NVIC_EnableIRQ(USART1_IRQn);			//Enable USART1 INT

}

/*****************************************************************************
* Function		: USART1_SendByte
* Description	: USART1 Send data
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void	USART1_SendByte(void)
{
	uint32_t	i;
	for (i=0; i<8; i++)
	{
		SN_USART1->TH= ('a'+i);
		while ((SN_USART1->LS & 0x40) == 0);
	}
}

/*****************************************************************************
* Function		: USART1_AutoBaudrateInit
* Description	: Initialization of USART1 Auto baud rate.
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USART1_AutoBaudrateInit(void)
{
	SN_USART1->ABCTRL =(USART_ABTO_EN										//Clear Auto Baud Time-out interrupt
										| USART_ABEO_EN										//Clear Auto Baud interrupt
										| USART_ABCCTRL_RESTART						//Restart in case of time-out
										| USART_ABCCTRL_MODE1							//Auto Baud mode, 0:mode 0, 1:mode 1
										|	USART_ABCCTRL_START);						//Auto Baud start, 0:stop(not running), 1:start(running)
}

/*****************************************************************************
* Function		: USART1_Enable
* Description	: Enable USART1
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USART1_Enable(void)
{
	//Enable HCLK for USART1
	SN_SYS1->AHBCLKEN |= USART1_CLK_EN;			//Enables clock for USART0
	SN_USART1->CTRL_b.USARTEN = USART_CTRL_EN;			//USART enable bit
	__USART1_RXFIFO_RESET;
	__USART1_TXFIFO_RESET;
}

/*****************************************************************************
* Function		: USART1_Disable
* Description	: Disable USART1
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USART1_Disable(void)
{
	SN_USART1->CTRL_b.USARTEN = USART_CTRL_DIS;			//USART disable
	//Disable HCLK for USART1
	SN_SYS1->AHBCLKEN &= ~(USART1_CLK_EN);			//Disable clock for USART0
}

/*****************************************************************************
* Function		: USART1_InterruptEnable
* Description	: Interrupt Enable 
* Input			: wTxhfie- TX half empty interrupt enable.  0: Disable, 1: Enable.
							wRxhfie- RX half empty interrupt enable.  0: Disable, 1: Enable.
							wRxtoie- RX Time-out interrupt enable.    0: Disable, 1: Enable.
							wRxovfie- RXOverflow interrupt enable. 	0: Disable, 1: Enable.
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USART1_InterruptEnable(void)
{
	SN_USART1->IE =(USART_RDAIE_EN		//Enables the Receive Data Available(RDA) interrupt	
								|	USART_THREIE_EN		//Enable THRE interrupt					
								|	USART_RLSIE_EN		//Enable Receive Line Status(RLS) interrupt									
								|	USART_TEMTIE_EN		//Enable TEMT interrupt
								|	USART_ABEOIE_EN		//Enable Auto Baud interrupt
								|	USART_ABTOIE_EN		//Enable Auto Baud time-out interrupt
								|	USART_TXERRIE_EN);//Enable TXERR interrupt									
}

