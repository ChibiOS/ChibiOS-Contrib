/******************** (C) COPYRIGHT 2015 SONiX *******************************
* COMPANY:	SONiX
* DATE:			2015/05
* AUTHOR:		SA1
* IC:				SN32F240/230/220 
* DESCRIPTION:	USART0 related functions.
*____________________________________________________________________________
*	REVISION	Date				User	Description
*	1.0				2013/12/17	SA1		First release
*	1.1				2014/01/20	SA1		1. Modify USART0_SendByte sub function
*	1.2				2014/02/27	SA1		1. Fix typing errors.
*	1.22			2014/05/23	SA1		1. Fix USART0_Init for BR=115200
*	2.0				2015/05/29	SA1		1. Fix USART0_Init for BR=115200 & 57600 @ PCLK=12MHz
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
volatile uint8_t bUSART0_RecvNew;
uint32_t   GulNum;
uint8_t 	 bUSART0_RecvFIFO[16];


/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ F U N C T I O N S __________________________________________________*/

/*****************************************************************************
* Function		: UART0_IRQHandler
* Description	: USART0 interrupt service routine
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
__irq void USART0_IRQHandler (void)
{
	uint32_t II_Buf, LS_Buf, MS_Buf;
	volatile uint32_t Null_Buf;

	II_Buf = SN_USART0->II;
	while ((II_Buf & mskUSART_II_STATUS) == USART_II_STATUS)		//check interrupt status, the INT can be determined by USARTn_II[3:1]
	{
		switch ((II_Buf>>1) & mskUSART_INTID_STATUS)
		{
			case USART_RLS:		//Receive Line Status
				LS_Buf = SN_USART0->LS;
				if((LS_Buf & mskUSART_LS_OE) ==  USART_LS_OE) 	//Overrun Error
				{ }
				if((LS_Buf & mskUSART_LS_RXFE) == USART_LS_RXFE)//RX FIFO Error
				{
					if((LS_Buf & mskUSART_LS_PE) == USART_LS_PE)//Parity Error
						Null_Buf = SN_USART0->RB;	//Clear interrupt
					if((LS_Buf & mskUSART_LS_FE) == USART_LS_FE)	//Framing Error
						Null_Buf = SN_USART0->RB;	//Clear interrupt
					if((LS_Buf & mskUSART_LS_BI) == USART_LS_BI)	//Break Interrupt
						Null_Buf = SN_USART0->RB;	//Clear interrupt
				}
				break;

      case USART_RDA:		//Receive Data Available
      case USART_CTI:		//Character Time-out Indicator
				LS_Buf = SN_USART0->LS;
        bUSART0_RecvNew = 1;                                        
				if((LS_Buf & mskUSART_LS_RDR) == USART_LS_RDR)//Receiver Data Ready
				{
					bUSART0_RecvFIFO[GulNum] = SN_USART0->RB;
					GulNum++;
				}
				if(GulNum == 16)
					GulNum = 0;
        break;
            
			case USART_THRE:		//THRE interrupt
				LS_Buf = SN_USART0->LS;
				if((LS_Buf & mskUSART_LS_THRE) == USART_LS_THRE)//THRE empty
				{	//SN_USART0->TH = Null_Buf; 	//Clear interrupt
				}
				break;

			case USART_TEMT:		//TEMT interrupt
				LS_Buf = SN_USART0->LS;
				if((LS_Buf & mskUSART_LS_TEMT) == USART_LS_TEMT)
				{	//SN_USART0->TH = Null_Buf; 	//Clear interrupt
				}
				break;
			
			case USART_MODEM:		//Modem status
				MS_Buf = SN_USART0->MS;
				if((MS_Buf & mskUSART_MS_DCTS) == USART_MS_DCTS)//Delta CTS
				{
					if((MS_Buf & mskUSART_MS_CTS) == USART_MS_CTS)
					{	//Low to High transition
					}
					else
					{	//High to Low transition
					}
				}
				break;
			default:
         break;
    } //end switch ((II_Buf>>1) & mskUSART_INTID_STATUS)

		II_Buf = SN_USART0->II;
		//LS_Buf = SN_USART0->LS;
  }	//end  while ((II_Buf&0x01) == mskUSART_II_STATUS)

	if ((II_Buf & mskUSART_II_ABEOIF) ==  USART_II_ABEOIF) //Auto Baud interrupt
		SN_USART0->ABCTRL |= USART_ABEO_EN;
	else if((II_Buf & mskUSART_II_ABTOIF) ==  USART_II_ABTOIF) //Auto Baud time-out interrupt
		SN_USART0->ABCTRL |= USART_ABTO_EN;

	if((II_Buf & mskUSART_II_TXERRIF) ==  USART_II_TXERRIF)//TXERR interrupt
	{
		LS_Buf = SN_USART0->LS;
		if ((LS_Buf & mskUSART_LS_TXERR) == USART_LS_THERR)//TX Error
			SN_USART0->FIFOCTRL|= USART_TXFIFO_RESET;			//TX FIFO Reset
	}
}


/*****************************************************************************
* Function		: USART0_Init
* Description	: Initialization of USART0
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USART0_Init (void)
{
	SN_SYS1->AHBCLKEN |= USART0_CLK_EN;			//Enables clock for USART0
	
	SN_SYS1->APBCP1 |= USART0_PLKSEL_DIV1;		//USART0 PCLK = HCLK/1 = 12MHz
	//SN_SYS1->APBCP1 |= USART0_PLKSEL_DIV2;	//USART0 PCLK = HCLK/2 = 6MHz
	//SN_SYS1->APBCP1 |= USART0_PLKSEL_DIV4;	//USART0 PCLK = HCLK/4 = 3MHz
	//SN_SYS1->APBCP1 |= USART0_PLKSEL_DIV8;	//USART0 PCLK = HCLK/8 = 1.5MHz
	//SN_SYS1->APBCP1 |= USART0_PLKSEL_DIV16;	//USART0 PCLK = HCLK/16= 0.75MHz
	
    //===Line Control===
	//setting character Word length(5/6/7/8 bit)
	SN_USART0->LC = (USART_CHARACTER_LEN8BIT		//8bit character length.
								|	USART_STOPBIT_1BIT					//stop bit of 1 bit
								|	USART_PARITY_BIT_DISEN			//parity bit is disable
								|	USART_PARITY_SELECTODD			//parity bit is odd
								|	USART_BREAK_DISEN		//Break Transmission control disable
								|	USART_DIVISOR_EN);		//Divisor Latch Access enable

	//===Baud Rate Calculation===
	//USART PCLK = 12MHz, Baud rate = 115200
	SN_USART0->FD = (USART_OVER_SAMPLE_16|USART_MULVAL_7|USART_DIVADDVAL_5);
  SN_USART0->DLM  = 0;
  SN_USART0->DLL  = 4;
	/*
	//USART PCLK = 12MHz, Baud rate = 57600
	SN_USART0->FD = (OVER_SAMPLE_16|USART_MULVAL_7|USART_DIVADDVAL_5);
  SN_USART0->DLM  = 0;
  SN_USART0->DLL  = 8;
	*/
	SN_USART0->LC &= ~(USART_DIVISOR_EN);		//Disable divisor latch

	//===Auto Baud Rate===
	//USART0_Autobaudrate_Init();		//Auto buad rate initial

	//===FIFO Control===
	SN_USART0->FIFOCTRL =(USART_FIFO_ENABLE					//Enable USART FIFOs
											|	USART_RXFIFO_RESET				//RX FIFO Reset
											|	USART_TXFIFO_RESET				//TX FIFO Reset
											|	USART_RXTRIGGER_LEVEL1);		//RX Trigger Level(1/4/8/14 characters)

	//===Modem Control=== 
	//USART0_Modem_Init();			//Initialization of USART0 Modem.	

	//===Smart Card Control===
	//SN_USART0->SCICTRL_b.NACKDIS = 1;					//NACK response disable, T=0 only (0:NACK response is enabled, 1:NACK response is inhibited)
	//SN_USART0->SCICTRL_b.PROTSEL = 1;					//Protocol selection (0:T=0, 1:T=1)
	//SN_USART0->SCICTRL_b.SCLKEN = 1;					//SCLK out enable (0:Disable, 1:Enable)
	//SN_USART0->SCICTRL_b.TXRETRY = 0;					//T=0 only, the field controls the maximum number of retransmissions that the USART will attempt if the remote device signal NACK. 
	//SN_USART0->SCICTRL_b.XTRAGUARD = 0;				//T=0 only, this field indicates the Guard time value in terms of number of bit times
	//SN_USART0->SCICTRL_b.TC = 0;							//TC[7:0] (Count for SCLK clock cycle when SCLKEN=1. SCLK will toggle every (TC[7:0]+1)*USARTn_PCLK cycle)

	//===Synchronous Mode Control===
	//USART0_SyncMode_Init(); 									//USART0_SyncMode_Init

	//===RS485 Control===	
	//USART0_RS485_Init();											//USART0_RS485_Init

	//===Scratch Pad===
	//SN_USART0->SP = 0;												//A readable, writable byte

	//===Oversampling===
	//SN_USART0->FD |= USART_OVER_SAMPLE_8;		//OVER8(Oversampling Value), 1:Oversampling by 8. 0:Oversampling by 16

	//===Half-duplex===
	//SN_USART0->HDEN = 1;											//Half-duplex mode enable

 	//===Interrupt Enable===
	USART0_InterruptEnable();

	//===USART Control===
	SN_USART0->CTRL =(USART_EN										//Enable USART0
									| USART_MODE_UART 						//USART Mode = USAT
									|	USART_RX_EN									//Enable RX
									| USART_TX_EN);								//Enable TX
	//===NVIC===
	NVIC_EnableIRQ(USART0_IRQn);			//Enable USART0 INT

}

/*****************************************************************************
* Function		: USART0_SendByte
* Description	: USART0 Send data
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void	USART0_SendByte(void)
{
	uint32_t	i;
	for (i=0; i<8; i++)
	{
		SN_USART0->TH= ('a'+i);
		while ((SN_USART0->LS & 0x40) == 0);
	}
}

/*****************************************************************************
* Function		: USART0_AutoBaudrateInit
* Description	: Initialization of USART0 Auto baud rate.
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USART0_AutoBaudrateInit(void)
{
	SN_USART0->ABCTRL =(USART_ABTO_EN										//Clear Auto Baud Time-out interrupt
										| USART_ABEO_EN										//Clear Auto Baud interrupt
										| USART_ABCCTRL_RESTART						//Restart in case of time-out
										| USART_ABCCTRL_MODE1							//Auto Baud mode, 0:mode 0, 1:mode 1
										|	USART_ABCCTRL_START);						//Auto Baud start, 0:stop(not running), 1:start(running)
}

/*****************************************************************************
* Function		: USART0_Modem_Init
* Description	: Initialization of USART0 Modem.
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USART0_Modem_Init(void)
{
	SN_USART0->MC =(USART_MC_RTSCTRL						//Source for modem output pin RTS
								|	USART_MCCTS_EN							//CTS	enable 
								|	USART_MCRTS_EN);							//RTS	enable
}

/*****************************************************************************
* Function		: USART0_RS485_Init
* Description	: Initialization of USART0 RS-485.
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USART0_RS485_Init(void)
{
	SN_USART0->RS485CTRL=(USART_NMM_EN						//RS-485 Normal Multidrop Mode enable	
											| USART_485RX_EN					//RS-485 Receiver enable, NMMEN=1 only
											|	USART_AAD_EN						//Auto Address Detect enable
											| USART_ADC_EN						//Direction control enable
											| USART_OINV_SEL1);					//Polarity control
	SN_USART0->RS485ADRMATCH = RS485_ADDRESS;			//the address match value for RS-485mode
	SN_USART0->RS485DLYV = RS485_DELAY_TIME;			//The direction control (RTS or DTR) delay value,this time is in periods of the baud clock
}

/*****************************************************************************
* Function		: USART0_SyncMode_Init
* Description	: Initialization of USART0 Synchronous Mode.
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USART0_SyncMode_Init(void)
{
	SN_USART0->SYNCCTRL=(USART_SCLK_HIGH						//SCLK idle	high
										 |USART_POLAR_FALLING);			//sample on Falling edge			
}

/*****************************************************************************
* Function		: USART0_Smartcard_Init
* Description	: Initialization of USART0 Smart Card.
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USART0_Smartcard_Init(void)
{
}

/*****************************************************************************
* Function		: USART0_Enable
* Description	: Enable USART0
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USART0_Enable(void)
{
	//Enable HCLK for USART0
	SN_SYS1->AHBCLKEN |= USART0_CLK_EN;			//Enables clock for USART0
	SN_USART0->CTRL_b.USARTEN = USART_CTRL_EN;			//USART enable bit
	__USART0_RXFIFO_RESET;
	__USART0_TXFIFO_RESET;
}

/*****************************************************************************
* Function		: USART0_Disable
* Description	: Disable USART0
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USART0_Disable(void)
{
	SN_USART0->CTRL_b.USARTEN = USART_CTRL_DIS;			//USART disable
	//Disable HCLK for USART0
	SN_SYS1->AHBCLKEN &= ~(USART0_CLK_EN);			//Disable clock for USART0
}

/*****************************************************************************
* Function		: USART0_InterruptEnable
* Description	: Interrupt Enable 
* Input			: wTxhfie- TX half empty interrupt enable.  0: Disable, 1: Enable.
							wRxhfie- RX half empty interrupt enable.  0: Disable, 1: Enable.
							wRxtoie- RX Time-out interrupt enable.    0: Disable, 1: Enable.
							wRxovfie- RXOverflow interrupt enable. 	0: Disable, 1: Enable.
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USART0_InterruptEnable(void)
{
	SN_USART0->IE =(USART_RDAIE_EN		//Enables the Receive Data Available(RDA) interrupt	
								|	USART_THREIE_EN		//Enable THRE interrupt					
								|	USART_RLSIE_EN		//Enable Receive Line Status(RLS) interrupt									
								|	USART_TEMTIE_EN		//Enable TEMT interrupt
								|	USART_ABEOIE_EN		//Enable Auto Baud interrupt
								|	USART_ABTOIE_EN		//Enable Auto Baud time-out interrupt
								|	USART_TXERRIE_EN);//Enable TXERR interrupt									
}

