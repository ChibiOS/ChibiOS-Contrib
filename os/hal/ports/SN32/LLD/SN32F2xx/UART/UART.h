#ifndef __SN32F2XX_UART_H
#define __SN32F2XX_UART_H


/*_____ I N C L U D E S ____________________________________________________*/
#include	<stdint.h>

/*_____ D E F I N I T I O N S ______________________________________________*/
/*
Base Address: 0x4001 6000 (UART0)
							0x4001 4000 (UART1)
							0x4001 2000 (UART1)
*/		
#define	UART0_CLK_EN	(0x01<<16)
#define	UART1_CLK_EN	(0x01<<17)
#define	UART2_CLK_EN	(0x01<<18)

/**************Line Control Define******/
#define	UART_CHARACTER_LEN5BIT	(0x00)
#define	UART_CHARACTER_LEN6BIT	(0x01)
#define	UART_CHARACTER_LEN7BIT	(0x02)
#define	UART_CHARACTER_LEN8BIT	(0x03)
/***********************/
#define	UART_STOPBIT_1BIT				(0x0<<2)
#define	UART_STOPBIT_2BIT				(0x1<<2)
/***********************/
#define	UART_PARITY_BIT_DISEN		(0x0<<3)
#define	UART_PARITY_BIT_EN			(0x1<<3)
/***********************/
#define	UART_PARITY_SELECTODD		(0x00<<4)
#define	UART_PARITY_SELECTEVEN	(0x01<<4)
#define	UART_PARITY_SELECTFORC1	(0x02<<4)
#define	UART_PARITY_SELECTFORC0	(0x03<<4)
/***********************/
#define	UART_BREAK_DISEN				(0x0<<6)
#define	UART_BREAK_EN						(0x1<<6)
/***********************/
#define	UART_DIVISOR_DISEN			(0x0<<7)
#define	UART_DIVISOR_EN					(0x1<<7)

#define	UART_OVER_SAMPLE_16			(0x0<<8)
#define	UART_OVER_SAMPLE_8			(0x1<<8)
/***Baud rate pre-scaler multilier = MULVAL+1***/
#define	UART_MULVAL_0						(0x0000<<4)
#define	UART_MULVAL_1						(0x0001<<4)
#define	UART_MULVAL_2						(0x0002<<4)
#define	UART_MULVAL_3						(0x0003<<4)
#define	UART_MULVAL_4						(0x0004<<4)
#define	UART_MULVAL_5						(0x0005<<4)
#define	UART_MULVAL_6						(0x0006<<4)
#define	UART_MULVAL_7						(0x0007<<4)
#define	UART_MULVAL_8						(0x0008<<4)
#define	UART_MULVAL_9						(0x0009<<4)
#define	UART_MULVAL_10					(0x000A<<4)
#define	UART_MULVAL_11					(0x000B<<4)
#define	UART_MULVAL_12					(0x000C<<4)
#define	UART_MULVAL_13					(0x000D<<4)
#define	UART_MULVAL_14					(0x000E<<4)
#define	UART_MULVAL_15					(0x000F<<4)
/***Buad rate pre-scaler divisor value********/
#define	UART_DIVADDVAL_0				(0x000)
#define	UART_DIVADDVAL_1				(0x001)
#define	UART_DIVADDVAL_2				(0x002)
#define	UART_DIVADDVAL_3				(0x003)
#define	UART_DIVADDVAL_4				(0x004)
#define	UART_DIVADDVAL_5				(0x005)
#define	UART_DIVADDVAL_6				(0x006)
#define	UART_DIVADDVAL_7				(0x007)
#define	UART_DIVADDVAL_8				(0x008)
#define	UART_DIVADDVAL_9				(0x009)
#define	UART_DIVADDVAL_10				(0x00A)
#define	UART_DIVADDVAL_11				(0x00B)
#define	UART_DIVADDVAL_12				(0x00C)
#define	UART_DIVADDVAL_13				(0x00D)
#define	UART_DIVADDVAL_14				(0x00E)
#define	UART_DIVADDVAL_15				(0x00F)
/***UART divisor latch MSB reg[7:0]. determines the baud rate***/


/***UART divisor latch LSB reg[7:0]. determines the baud rate***/


#define	UART_FIFO_ENABLE				(0x01)
#define	UART_RXFIFO_RESET				(0x01<<1)
#define	UART_TXFIFO_RESET				(0x01<<2)

#define	UART_RXTRIGGER_LEVEL1		(0x00<<6)


/***UART Interrupt Enable register***/
#define	UART_ABTOIE_EN					(0x01<<9)		//auto-buad time out INT
#define	UART_ABEOIE_EN					(0x01<<8)		//End of auto-buad INT
#define	UART_TEMTIE_EN					(0x01<<4)		//Transmitter empty flag
#define	UART_RLSIE_EN						(0x01<<2)		//Rx Receive line status(RLS) INT
#define	UART_THREIE_EN					(0x01<<1)		//Transmitter holding register empty flag INT
#define	UART_RDAIE_EN						(0x01)			//character receive(RDA) time-out INT

/*** UARTn_CTRL************/
#define	UART_EN									(0x01)			
#define	UART_RX_EN							(0x01<<6)
#define	UART_TX_EN							(0x01<<7)
#define	UART_CTRL_EN						1
#define	UART_CTRL_DIS						0
#define	UART_FIFOCTRL_RESET			1

/*** UARTn_ABCCTRL************/
#define	UART_ABCCTRL_START			(0x01)			//START:1(Auto-baud is running), START:0(Auto-baud is not running)
#define	UART_ABCCTRL_MODE0			(0x00<<1)
#define	UART_ABCCTRL_MODE1			(0x01<<1)
#define	UART_ABCCTRL_RESTART		(0x01<<2)
#define	UART_ABEO_EN						(0x01<<8)
#define	UART_ABTO_EN						(0x01<<9)

/*** Line status register************/
#define	UART_LS_RDR							(0x01)			//receiver data ready flag					
#define	UART_LS_OE							(0x01<<1)		//overrun error flag
#define	UART_LS_PE							(0x01<<2)		//parity error flag
#define	UART_LS_FE							(0x01<<3)		//framing error flag
#define	UART_LS_BI							(0x01<<4)		//break interrupt flag
#define	UART_LS_THRE						(0x01<<5)		//transmitter holding register empty flag
#define	UART_LS_TEMT						(0x01<<6)		//transmitter empty flag
#define	UART_LS_RXFE						(0x01<<7)		//error in RX FIFO flag
#define	mskUART_LS_RDR					(0x01)
#define	mskUART_LS_OE						(0x01<<1)
#define	mskUART_LS_PE						(0x01<<2)
#define	mskUART_LS_FE						(0x01<<3)
#define	mskUART_LS_BI						(0x01<<4)
#define	mskUART_LS_THRE					(0x01<<5)
#define	mskUART_LS_TEMT					(0x01<<6)
#define	mskUART_LS_RXFE					(0x01<<7)

/*** Interrupt Identification register************/
#define	UART_RLS								3
#define	UART_RDA								2
#define	UART_THRE								1
#define	UART_TEMT								7
#define	UART_II_STATUS					0						//the INTstatus can be determined by UARTn_II[3:1]
#define UART_II_ABEOIF					(0x01<<8)		//end of auto-baud interrupt flag
#define	UART_II_ABTOIF					(0x01<<9)		//auto-baud time-out interrupt flag
#define	mskUART_INTID_STATUS		7						//interrupt corresponding to the UARTn RX FIFO
#define	mskUART_II_STATUS				(0x01)
#define	mskUART_II_ABEOIF				(0x01<<8)
#define	mskUART_II_ABTOIF				(0x01<<9)


/*_____ M A C R O S ________________________________________________________*/

			  
/*_____ D E C L A R A T I O N S ____________________________________________*/
extern uint32_t   GulNum;
extern uint8_t 	 	bUART0_RecvFIFO[];
extern uint32_t   GulNum1;
extern uint8_t 	 	bUART1_RecvFIFO[];
extern uint32_t   GulNum2;
extern uint8_t 	 	bUART2_RecvFIFO[];
extern volatile uint8_t bUART0_RecvNew;
extern volatile uint8_t bUART1_RecvNew;
extern volatile uint8_t bUART2_RecvNew;


/*_____ D E C L A R A T I O N S ____________________________________________*/
extern void UART0_Init(void);
extern void UART0_SendByte (uint8_t ucDat);
extern void UART0_Enable(void);
extern void UART0_Disable(void);
extern void UART0_InterruptEnable(void);
extern void UART0_AutoBaudrateInit(void);

extern void UART1_Init(void);
extern void UART1_SendByte (uint8_t ucDat);
extern void UART1_Enable(void);
extern void UART1_Disable(void);
extern void UART1_InterruptEnable(void);
extern void UART1_AutoBaudrateInit(void);

void UART2_Init(void);
void UART2_SendByte (uint8_t ucDat);
void UART2_Enable(void);
void UART2_Disable(void);
void UART2_InterruptEnable(void);
void UART2_AutoBaudrateInit(void);

#endif	/*__SN32F2XX_UART_H*/

