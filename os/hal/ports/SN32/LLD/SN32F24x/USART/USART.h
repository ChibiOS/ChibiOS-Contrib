#ifndef __SN32F240_USART_H
#define __SN32F240_USART_H


/*_____ I N C L U D E S ____________________________________________________*/
#include	<stdint.h>

/*_____ D E F I N I T I O N S ______________________________________________*/
/*
Base Address: 0x4001 6000 (USART0)
							0x4005 6000 (USART1)
*/		
#define	USART0_CLK_EN	(0x01<<16)
#define	USART1_CLK_EN	(0x01<<17)

#define	USART0_PLKSEL_DIV1	(0x00)
#define	USART0_PLKSEL_DIV2	(0x01)
#define	USART0_PLKSEL_DIV4	(0x02)
#define	USART0_PLKSEL_DIV8	(0x03)
#define	USART0_PLKSEL_DIV16	(0x04)

#define	USART1_PLKSEL_DIV1	(0x00<<4)
#define	USART1_PLKSEL_DIV2	(0x01<<4)
#define	USART1_PLKSEL_DIV4	(0x02<<4)
#define	USART1_PLKSEL_DIV8	(0x03<<4)
#define	USART1_PLKSEL_DIV16	(0x04<<4)
/**************Line Control Define******/
#define	USART_CHARACTER_LEN5BIT		(0x00)
#define	USART_CHARACTER_LEN6BIT		(0x01)
#define	USART_CHARACTER_LEN7BIT		(0x02)
#define	USART_CHARACTER_LEN8BIT		(0x03)
/***********************/
#define	USART_STOPBIT_1BIT				(0x0<<2)
#define	USART_STOPBIT_2BIT				(0x1<<2)
/***********************/
#define	USART_PARITY_BIT_DISEN		(0x0<<3)
#define	USART_PARITY_BIT_EN				(0x1<<3)
/***********************/
#define	USART_PARITY_SELECTODD		(0x00<<4)
#define	USART_PARITY_SELECTEVEN		(0x01<<4)
#define	USART_PARITY_SELECTFORC1	(0x02<<4)
#define	USART_PARITY_SELECTFORC0	(0x03<<4)
/***********************/
#define	USART_BREAK_DISEN					(0x0<<6)
#define	USART_BREAK_EN						(0x1<<6)
/***********************/
#define	USART_DIVISOR_DISEN				(0x0<<7)
#define	USART_DIVISOR_EN					(0x1<<7)

#define	USART_OVER_SAMPLE_16			(0x0<<8)
#define	USART_OVER_SAMPLE_8				(0x1<<8)
/***Baud rate pre-scaler multilier = MULVAL+1***/
#define	USART_MULVAL_0						(0x0000<<4)
#define	USART_MULVAL_1						(0x0001<<4)
#define	USART_MULVAL_2						(0x0002<<4)
#define	USART_MULVAL_3						(0x0003<<4)
#define	USART_MULVAL_4						(0x0004<<4)
#define	USART_MULVAL_5						(0x0005<<4)
#define	USART_MULVAL_6						(0x0006<<4)
#define	USART_MULVAL_7						(0x0007<<4)
#define	USART_MULVAL_8						(0x0008<<4)
#define	USART_MULVAL_9						(0x0009<<4)
#define	USART_MULVAL_10						(0x000A<<4)
#define	USART_MULVAL_11						(0x000B<<4)
#define	USART_MULVAL_12						(0x000C<<4)
#define	USART_MULVAL_13						(0x000D<<4)
#define	USART_MULVAL_14						(0x000E<<4)
#define	USART_MULVAL_15						(0x000F<<4)
/***Buad rate pre-scaler divisor value********/
#define	USART_DIVADDVAL_0					(0x000)
#define	USART_DIVADDVAL_1					(0x001)
#define	USART_DIVADDVAL_2					(0x002)
#define	USART_DIVADDVAL_3					(0x003)
#define	USART_DIVADDVAL_4					(0x004)
#define	USART_DIVADDVAL_5					(0x005)
#define	USART_DIVADDVAL_6					(0x006)
#define	USART_DIVADDVAL_7					(0x007)
#define	USART_DIVADDVAL_8					(0x008)
#define	USART_DIVADDVAL_9					(0x009)
#define	USART_DIVADDVAL_10				(0x00A)
#define	USART_DIVADDVAL_11				(0x00B)
#define	USART_DIVADDVAL_12				(0x00C)
#define	USART_DIVADDVAL_13				(0x00D)
#define	USART_DIVADDVAL_14				(0x00E)
#define	USART_DIVADDVAL_15				(0x00F)
/***USART divisor latch MSB reg[7:0]. determines the baud rate***/


/***USART divisor latch LSB reg[7:0]. determines the baud rate***/


#define	USART_FIFO_ENABLE					(0x01)
#define	USART_RXFIFO_RESET				(0x01<<1)
#define	USART_TXFIFO_RESET				(0x01<<2)

#define	USART_RXTRIGGER_LEVEL1		(0x00<<6)
#define	USART_RXTRIGGER_LEVEL4		(0x01<<6)
#define	USART_RXTRIGGER_LEVEL8		(0x02<<6)
#define	USART_RXTRIGGER_LEVEL14		(0x03<<6)

/***USART Interrupt Enable register***/
#define	USART_TXERRIE_EN					(0x01<<10)	//Tx error flag INT
#define	USART_ABTOIE_EN						(0x01<<9)		//auto-buad time out INT
#define	USART_ABEOIE_EN						(0x01<<8)		//End of auto-buad INT
#define	USART_TEMTIE_EN						(0x01<<4)		//Transmitter empty flag
#define	USART_MSIE_EN							(0x01<<3)		//Modem status INT
#define	USART_RLSIE_EN						(0x01<<2)		//Rx Receive line status(RLS) INT
#define	USART_THREIE_EN						(0x01<<1)		//Transmitter holding register empty flag INT
#define	USART_RDAIE_EN						(0x01)			//character receive(RDA) time-out INT

/*** USARTn_CTRL************/
#define	USART_EN									(0x01)			
#define	USART_MODE_UART						(0x00<<1)
#define	USART_MODE_MODEN					(0x01<<1)
#define	USART_MODE_SMARTCARD			(0x03<<1)
#define	USART_MODE_SYNCH					(0x04<<1)
#define	USART_MODE_RS485					(0x05<<1)
#define	USART_RX_EN								(0x01<<6)
#define	USART_TX_EN								(0x01<<7)
#define	USART_CTRL_EN							1
#define	USART_CTRL_DIS						0
#define	USART_FIFOCTRL_RESET			1

/*** USARTn_ABCCTRL************/
#define	USART_ABCCTRL_START				(0x01)			//START:1(Auto-baud is running), START:0(Auto-baud is not running)
#define	USART_ABCCTRL_MODE0				(0x00<<1)
#define	USART_ABCCTRL_MODE1				(0x01<<1)
#define	USART_ABCCTRL_RESTART			(0x01<<2)
#define	USART_ABEO_EN							(0x01<<8)
#define	USART_ABTO_EN							(0x01<<9)

/*** USARTn_MC(modem contro)************/
#define	USART_MC_RTSCTRL					(0x01<<1)			//Source for modem output pin RTS
#define	USART_MCCTS_EN						(0x01<<6)			//Auto-CTS	1:enable 0:disable
#define	USART_MCRTS_EN						(0x01<<7)			//Auto-RTS	1:enable 0:disable

/*** USARTn_RS485(modem contro)************/
#define	USART_NMM_EN							(0x01)				//Normal Multidrop Mode(NMM) 1:enable 0:disable
#define	USART_485RX_EN						(0x01<<1)			//RS-485 Receiver bit 1:enalbe 0:disable
#define	USART_AAD_EN							(0x01<<2)			//Auto address detect(AAD) bit 1:enable 0:disable
#define	USART_ADC_EN							(0x01<<4)			//Auto Direction control bit 1:enable 0:disable
#define	USART_OINV_SEL1						(0x01<<5)			
#define	USART_OINV_SEL0						(0x00<<5)			
#define	RS485_ADDRESS							40
#define	RS485_DELAY_TIME					40

/*** USARTn_Synchronous Mode(modem contro)************/
#define	USART_SCLK_LOW						(0x0<<1)			//SCLK idle low
#define	USART_SCLK_HIGH						(0x1<<1)			//SCLK idle	high
#define	USART_POLAR_RISING				(0x0<<2)			//sample on Rising edge
#define	USART_POLAR_FALLING				(0x1<<2)			//sample on Falling edge	

/*** Line status register************/
#define	USART_LS_RDR									(0x01)			//receiver data ready flag					
#define	USART_LS_OE										(0x01<<1)		//overrun error flag
#define	USART_LS_PE										(0x01<<2)		//parity error flag
#define	USART_LS_FE										(0x01<<3)		//framing error flag
#define	USART_LS_BI										(0x01<<4)		//break interrupt flag
#define	USART_LS_THRE									(0x01<<5)		//transmitter holding register empty flag
#define	USART_LS_TEMT									(0x01<<6)		//transmitter empty flag
#define	USART_LS_RXFE									(0x01<<7)		//error in RX FIFO flag
#define	USART_LS_THERR								(0x01<<8)		//TX error flag
#define	mskUSART_LS_RDR								(0x01)
#define	mskUSART_LS_OE								(0x01<<1)
#define	mskUSART_LS_PE								(0x01<<2)
#define	mskUSART_LS_FE								(0x01<<3)
#define	mskUSART_LS_BI								(0x01<<4)
#define	mskUSART_LS_THRE							(0x01<<5)
#define	mskUSART_LS_TEMT							(0x01<<6)
#define	mskUSART_LS_RXFE							(0x01<<7)
#define	mskUSART_LS_TXERR							(0x01<<8)

/*** Line status register************/
#define	USART_MS_DCTS									(0x01)
#define	USART_MS_CTS									(0x01<<4)
#define	mskUSART_MS_DCTS							(0x01)
#define	mskUSART_MS_CTS								(0x01<<4)

/*** Interrupt Identification register************/
#define	USART_RLS											3
#define	USART_RDA											2
#define	USART_CTI											6
#define	USART_THRE										1
#define	USART_MODEM										0
#define	USART_TEMT										7
#define	USART_II_STATUS								0						//the INTstatus can be determined by USARTn_II[3:1]
#define USART_II_ABEOIF								(0x01<<8)		//end of auto-baud interrupt flag
#define	USART_II_ABTOIF								(0x01<<9)		//auto-baud time-out interrupt flag
#define	USART_II_TXERRIF							(0x01<<10)	//TXERR interrupt flag
#define	mskUSART_INTID_STATUS					7						//interrupt corresponding to the USARTn RX FIFO
#define	mskUSART_II_STATUS						(0x01)
#define	mskUSART_II_ABEOIF						(0x01<<8)
#define	mskUSART_II_ABTOIF						(0x01<<9)
#define	mskUSART_II_TXERRIF						(0x01<<10)


/*_____ M A C R O S ________________________________________________________*/
#define	__USART0_RXFIFO_RESET		(SN_USART0->FIFOCTRL_b.RXFIFORST = USART_FIFOCTRL_RESET)
#define	__USART0_TXFIFO_RESET		(SN_USART0->FIFOCTRL_b.TXFIFORST = USART_FIFOCTRL_RESET)
#define	__USART1_RXFIFO_RESET		(SN_USART1->FIFOCTRL_b.RXFIFORST = USART_FIFOCTRL_RESET)
#define	__USART1_TXFIFO_RESET		(SN_USART1->FIFOCTRL_b.TXFIFORST = USART_FIFOCTRL_RESET)
			  
/*_____ D E C L A R A T I O N S ____________________________________________*/
extern uint32_t   GulNum;
extern uint8_t 	 	bUSART0_RecvFIFO[16];
extern uint32_t   GulNum1;
extern uint8_t 	 	bUSART1_RecvFIFO[16];
extern volatile uint8_t bUSART0_RecvNew;
extern volatile uint8_t bUSART1_RecvNew;


/*_____ D E C L A R A T I O N S ____________________________________________*/
extern void USART0_Init(void);
extern void	USART0_SendByte(void);
extern void USART0_Enable(void);
extern void USART0_Disable(void);
extern void USART0_InterruptEnable(void);
extern void USART0_AutoBaudrateInit(void);

extern void USART1_Init(void);
extern void	USART1_SendByte(void);
extern void USART1_Enable(void);
extern void USART1_Disable(void);
extern void USART1_InterruptEnable(void);
extern void USART1_AutoBaudrateInit(void);

extern void USART0_Modem_Init(void);
extern void USART0_RS485_Init(void);
extern void USART0_SyncMode_Init(void);


#endif	/*__SN32F240_USART_H*/

