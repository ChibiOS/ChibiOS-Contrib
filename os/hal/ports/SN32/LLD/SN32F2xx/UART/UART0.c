/******************** (C) COPYRIGHT 2017 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2017/07
* AUTHOR:				SA1
* IC:						SN32F240B
* DESCRIPTION:	UART0 related functions.
*____________________________________________________________________________
*	REVISION	Date				User	Description
*	1.0				2017/07/07	SA1		First release
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
#include "UART.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/
volatile uint8_t bUART0_RecvNew;
uint32_t   GulNum;
uint8_t 	 bUART0_RecvFIFO[56];


/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ F U N C T I O N S __________________________________________________*/

/*****************************************************************************
* Function		: UART0_IRQHandler
* Description	: UART0 interrupt service routine
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
__irq void UART0_IRQHandler (void)
{
	uint32_t II_Buf, LS_Buf;
	volatile uint32_t Null_Buf;

	II_Buf = SN_UART0->II;
	while ((II_Buf & mskUART_II_STATUS) == UART_II_STATUS)		//check interrupt status, the INT can be determined by USARTn_II[3:1]
	{
		switch ((II_Buf>>1) & mskUART_INTID_STATUS)
		{
			case UART_RLS:		//Receive Line Status
				LS_Buf = SN_UART0->LS;
				if((LS_Buf & mskUART_LS_OE) ==  UART_LS_OE) 	//Overrun Error
				{ }
				if((LS_Buf & mskUART_LS_RXFE) == UART_LS_RXFE)//RX FIFO Error
				{
					if((LS_Buf & mskUART_LS_PE) == UART_LS_PE)//Parity Error
						Null_Buf = SN_UART0->RB;	//Clear interrupt
					if((LS_Buf & mskUART_LS_FE) == UART_LS_FE)	//Framing Error
						Null_Buf = SN_UART0->RB;	//Clear interrupt
					if((LS_Buf & mskUART_LS_BI) == UART_LS_BI)	//Break Interrupt
						Null_Buf = SN_UART0->RB;	//Clear interrupt
				}
				break;

      case UART_RDA:		//Receive Data Available
				LS_Buf = SN_UART0->LS;
        bUART0_RecvNew = 1;                                        
				if((LS_Buf & mskUART_LS_RDR) == UART_LS_RDR)//Receiver Data Ready
				{
					bUART0_RecvFIFO[GulNum] = SN_UART0->RB;
					GulNum++;
				}
				if(GulNum == 56)
					GulNum = 0;
        break;
            
			case UART_THRE:		//THRE interrupt
				LS_Buf = SN_UART0->LS;
				if((LS_Buf & mskUART_LS_THRE) == UART_LS_THRE)//THRE empty
				{	//SN_UART0->TH = Null_Buf; 	//Clear interrupt
				}
				break;

			case UART_TEMT:		//TEMT interrupt
				LS_Buf = SN_UART0->LS;
				if((LS_Buf & mskUART_LS_TEMT) == UART_LS_TEMT)
				{	//SN_UART0->TH = Null_Buf; 	//Clear interrupt
				}
				break;

			default:
         break;
    } //end switch ((II_Buf>>1) & mskUART_INTID_STATUS)

		II_Buf = SN_UART0->II;
  }	//end  while ((II_Buf&0x01) == mskUART_II_STATUS)

	if ((II_Buf & mskUART_II_ABEOIF) ==  UART_II_ABEOIF) //Auto Baud interrupt
		SN_UART0->ABCTRL |= UART_ABEO_EN;
	else if((II_Buf & mskUART_II_ABTOIF) ==  UART_II_ABTOIF) //Auto Baud time-out interrupt
		SN_UART0->ABCTRL |= UART_ABTO_EN;
}


/*****************************************************************************
* Function		: UART0_Init
* Description	: Initialization of UART0
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void UART0_Init (void)
{
	SN_SYS1->AHBCLKEN |= UART0_CLK_EN;				//Enables clock for UART0
	
  //===Line Control===
	//setting character Word length(5/6/7/8 bit)
	SN_UART0->LC = (UART_CHARACTER_LEN8BIT		//8bit character length.
								|	UART_STOPBIT_1BIT					//stop bit of 1 bit
								|	UART_PARITY_BIT_DISEN			//parity bit is disable
								|	UART_PARITY_SELECTODD			//parity bit is odd
								|	UART_BREAK_DISEN		//Break Transmission control disable
								|	UART_DIVISOR_EN);		//Divisor Latch Access enable

	//===Baud Rate Calculation===
	//UART PCLK = 12MHz, Baud rate = 115200
	SN_UART0->FD = (UART_OVER_SAMPLE_16|UART_MULVAL_7|UART_DIVADDVAL_5);
  SN_UART0->DLM  = 0;
  SN_UART0->DLL  = 4;
	/*
	//UART PCLK = 12MHz, Baud rate = 57600
	SN_UART0->FD = (OVER_SAMPLE_16|UART_MULVAL_7|UART_DIVADDVAL_5);
  SN_UART0->DLM  = 0;
  SN_UART0->DLL  = 8;
	*/
	SN_UART0->LC &= ~(UART_DIVISOR_EN);		//Disable divisor latch

	//===Auto Baud Rate===
	//UART0_Autobaudrate_Init();		//Auto buad rate initial

	//===FIFO Control===
	SN_UART0->FIFOCTRL =(UART_FIFO_ENABLE					//Enable USART FIFOs
											|	UART_RXFIFO_RESET				//RX FIFO Reset
											|	UART_TXFIFO_RESET				//TX FIFO Reset
											|	UART_RXTRIGGER_LEVEL1);		//RX Trigger Level(1 characters)

	//===Oversampling===
	//SN_UART0->FD |= UART_OVER_SAMPLE_8;		//OVER8(Oversampling Value), 1:Oversampling by 8. 0:Oversampling by 16

	//===Half-duplex===
	//SN_UART0->HDEN = 1;											//Half-duplex mode enable

 	//===Interrupt Enable===
	UART0_InterruptEnable();

	//===UART Control===
	SN_UART0->CTRL =(UART_EN										//Enable USART0
									|	UART_RX_EN									//Enable RX
									| UART_TX_EN);								//Enable TX
	//===NVIC===
	NVIC_EnableIRQ(UART0_IRQn);			//Enable USART0 INT

}

/*****************************************************************************
* Function		: UART0_SendByte
* Description	: MCU sends Byte through UTXD0
* Input			: ucDat - data to be sent
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void UART0_SendByte (uint8_t ucDat)
{
	SN_UART0->TH = ucDat; 
	while ((SN_UART0->LS & 0x40) == 0);
}

/*****************************************************************************
* Function		: UART0_AutoBaudrateInit
* Description	: Initialization of UART0 Auto baud rate.
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void UART0_AutoBaudrateInit(void)
{
	SN_UART0->ABCTRL =(UART_ABTO_EN										//Clear Auto Baud Time-out interrupt
										| UART_ABEO_EN										//Clear Auto Baud interrupt
										| UART_ABCCTRL_RESTART						//Restart in case of time-out
										| UART_ABCCTRL_MODE1							//Auto Baud mode, 0:mode 0, 1:mode 1
										|	UART_ABCCTRL_START);						//Auto Baud start, 0:stop(not running), 1:start(running)
}

/*****************************************************************************
* Function		: UART0_Enable
* Description	: Enable UART0
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void UART0_Enable(void)
{
	//Enable HCLK for UART0
	SN_SYS1->AHBCLKEN |= UART0_CLK_EN;				//Enables clock for UART0
	SN_UART0->CTRL_b.UARTEN = UART_CTRL_EN;		//UART enable bit
}

/*****************************************************************************
* Function		: UART0_Disable
* Description	: Disable UART0
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void UART0_Disable(void)
{
	SN_UART0->CTRL_b.UARTEN = UART_CTRL_DIS;			//UART disable
	//Disable HCLK for UART0
	SN_SYS1->AHBCLKEN &= ~(UART0_CLK_EN);					//Disable clock for UART0
}

/*****************************************************************************
* Function		: UART0_InterruptEnable
* Description	: Interrupt Enable 
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void UART0_InterruptEnable(void)
{
	SN_UART0->IE =(UART_RDAIE_EN		//Enables the Receive Data Available(RDA) interrupt	
								|	UART_THREIE_EN		//Enable THRE interrupt					
								|	UART_RLSIE_EN		//Enable Receive Line Status(RLS) interrupt									
								|	UART_TEMTIE_EN		//Enable TEMT interrupt
								|	UART_ABEOIE_EN		//Enable Auto Baud interrupt
								|	UART_ABTOIE_EN);		//Enable Auto Baud time-out interrupt
}

