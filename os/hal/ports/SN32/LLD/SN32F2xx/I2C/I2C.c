/******************** (C) COPYRIGHT 2017 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2017/07
* AUTHOR:				SA1
* IC:						SN32F240B
* DESCRIPTION:	I2C0 related functions.
*____________________________________________________________________________
* REVISION	Date				User		Description
* 1.0				2017/07/07	SA1			First release
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
#include <SN32F200_Def.h>
#include "I2C.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/
uint8_t bI2C_RxFIFO[I2C_RX_FIFO_LENGTH];
uint8_t bI2C_TxFIFO[I2C_TX_FIFO_LENGTH] = {0};
uint8_t bI2C_RxFIFO_cnts, bI2C_Rx_cnts;
uint8_t bI2C_TxFIFO_cnts, bI2C_Tx_cnts;
uint8_t *bTX_ptr;
uint8_t	EEPROM_ADR_H, EEPROM_ADR_L;
uint8_t	EEPROM_WR;				// 0 : write
													// 1 : read
uint8_t Busy = 1, Error = 0;
uint8_t Read_Down = 0;
uint8_t Send_Address;
uint8_t temp = 0;
volatile uint8_t Timeout = 0;


/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ F U N C T I O N S __________________________________________________*/
/*****************************************************************************
* Function		: I2C_Init
* Description	: Initialization of I2C
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void I2C_Init (void)
{
	SN_SYS1->AHBCLKEN_b.I2C0CLKEN = 1;					//Enables HCLK for I2C0
	
	//I2C speed
	SN_I2C0->SCLHT = I2C0_SCLHT;
	SN_I2C0->SCLLT = I2C0_SCLLT;
	
	SN_I2C0->CTRL_b.I2CEN = 1;									//Enable I2C
	
	//===NVIC===	
	NVIC_ClearPendingIRQ(I2C0_IRQn);	
	NVIC_EnableIRQ(I2C0_IRQn);
}
/*****************************************************************************
* Function		: I2C_Start
* Description	: transmit a START bit
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void I2C_Start(void)
{
		SN_I2C0->CTRL_b.STA = 1;
}
/*****************************************************************************
* Function		: I2C_Stop
* Description	: transmit a STOP condition in master mode
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void I2C_Stop(void)
{
		SN_I2C0->CTRL_b.STO = 1;
}
/*****************************************************************************
* Function		: I2C_Read
* Description	: read N Byte data from EEPROM
* Input			: eeprom_adr - data word address
*						: read_num - byte length
* Output		: None
* Return		: OK or Fail  
* Note			: None
*****************************************************************************/
uint8_t I2C_Read(uint16_t eeprom_adr, uint8_t read_num)
{	
	bI2C_Rx_cnts = 0;
		
	EEPROM_ADR_H =  eeprom_adr >> 8;				//data word address low byte
	EEPROM_ADR_L =  eeprom_adr & 0x00ff;		//data word address high byte
	
	bI2C_RxFIFO_cnts = read_num;						//byte length 					

	Busy = 1;
		
	EEPROM_WR = 0;													//write
	
	I2C_Start();														//I2C start

	SysTick->CTRL = 0x7;										//Enable SysTick timer and interrupt	
	
	Send_Address = 1;												//data word address setting flag 
	
	while(Busy == 1 && Timeout == 0);
	
	SysTick->CTRL = 0x0;										//Disable SysTick timer and interrupt	
	
	if(Error == 1 || Timeout == 1) return FALSE;
		
	#if (EEPROM_less_than_32K == 0)	
		
		SN_I2C0->TXDATA = EEPROM_ADR_H;				//data word address high byte

		SysTick->CTRL = 0x7;									//Enable SysTick timer and interrupt	
	
		Busy = 1;
		
		while(Busy == 1 && Timeout == 0);
		
		SysTick->CTRL = 0x0;									//Disable SysTick timer and interrupt	

		if(Error == 1 || Timeout == 1) return FALSE;

	#endif
	
	SN_I2C0->TXDATA = EEPROM_ADR_L;					//data word address low byte
	
	SysTick->CTRL = 0x7;										//Enable SysTick timer and interrupt	
			
	Busy = 1;
	
	while(Busy == 1 && Timeout == 0);
		
	SysTick->CTRL = 0x0;										//Disable SysTick timer and interrupt	
	
	if(Error == 1 || Timeout == 1) return FALSE;	

	Read_Down = 0;													  
	
	Send_Address = 0;
			
	EEPROM_WR = 1;													//read		
	
	I2C_Start();														//I2C start
	
	SysTick->CTRL = 0x7;										//Enable SysTick timer and interrupt	
	
	while(Read_Down == 0 && Timeout == 0);

	SysTick->CTRL = 0x0;										//Disable SysTick timer and interrupt	
	
	Read_Down = 0;	
	
	if(Error == 1 || Timeout == 1) return FALSE;
	
	return TRUE;
}
/*****************************************************************************
* Function		: I2C_Write
* Description	: write N Byte data to EEPROM
* Input			: eeprom_adr - data word address
*						: write_num - byte length
* Output		: None
* Return		: OK or Fail  
* Note			: None
*****************************************************************************/
uint8_t I2C_Write(uint16_t eeprom_adr, uint8_t write_num)
{
	Timeout = 0;
	
	bI2C_Tx_cnts = 0;
	
	bTX_ptr = &bI2C_TxFIFO[0];							//write data buffer	
	
	EEPROM_ADR_H =  eeprom_adr >> 8;				//data word address high byte
	
	EEPROM_ADR_L =  eeprom_adr & 0x00ff;		//data word address low byte
	
	bI2C_TxFIFO_cnts = write_num;						//byte length	
		
	Busy = 1;
	
	EEPROM_WR = 0;													//write
	
	SysTick->CTRL = 0x7;										//Enable SysTick timer and interrupt
	
	I2C_Start();														//I2C start	

	Send_Address = 1;												//data word address setting flag 
	
	while(Busy == 1 && Timeout == 0);
		
	SysTick->CTRL = 0x0;										//Disable SysTick timer and interrupt
	
	if(Error == 1 || Timeout == 1) return FALSE;						

	#if (EEPROM_less_than_32K == 0)

		SN_I2C0->TXDATA = EEPROM_ADR_H;					//data word address high byte
		
		SysTick->CTRL = 0x7;										//Enable SysTick timer and interrupt	
		
		Busy = 1;

		while(Busy == 1 && Timeout == 0);
			
		SysTick->CTRL = 0x0;										//Disable SysTick timer and interrupt
		
		if(Error == 1 || Timeout == 1) return FALSE;			

	#endif
	
	SN_I2C0->TXDATA = EEPROM_ADR_L;					//data word address low byte
	
	SysTick->CTRL = 0x7;										//Enable SysTick timer and interrupt

	Busy = 1;	

	while(Busy == 1 && Timeout == 0);

	if(Error == 1 || Timeout == 1 ) return FALSE;
	
	SysTick->CTRL = 0x0;										//Disable SysTick timer and interrupt	
	
	Send_Address = 0;
	
	SN_I2C0->TXDATA = *bTX_ptr++;						//write data
	
	SysTick->CTRL = 0x7;										//Enable SysTick timer and interrupt
	
	Busy = 1;	

	while(Busy == 1 && Timeout == 0);
	
	if(Error == 1 || Timeout == 1) return FALSE;
	
	SysTick->CTRL = 0x0;									//Disable SysTick timer and interrupt	
	
	Busy = 1;	
	
	I2C_Stop();
	
	SysTick->CTRL = 0x7;										//Enable SysTick timer and interrupt
	
	while(Busy == 1 && Timeout == 0);
	
	if(Error == 1 || Timeout == 1) return FALSE;
	
	SysTick->CTRL = 0x0;										//Disable SysTick timer and interrupt		
	
	return TRUE;
}

/*****************************************************************************
* Function		: I2C_IRQHandler
* Description	: I2C interrupt service routine
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
__irq void I2C0_IRQHandler(void)
{		
	if(((SN_I2C0->STAT) & (mskI2C_LOST_ARB_LOST_ARBITRATION)) == Lost_Arbitration)
	{
		SN_I2C0->STAT_b.I2CIF = 1;		
		SN_I2C0->CTRL_b.I2CEN = 0;			//Disable I2C				
		SN_I2C0->CTRL_b.I2CEN = 1;			//Enable I2C		
		I2C_Start();										//Re-start				
	}
	
	/* Stop Done */
	else if(((SN_I2C0->STAT) & (mskI2C_STA_MASTER_STA_STO)) == STOP_DONE)
	{	
		Busy = 0;	
		SN_I2C0->STAT_b.I2CIF = 1;			
		if(EEPROM_WR == 1)
			Read_Down = 1;
	}	
	else
	{	
		SN_I2C0->STAT_b.I2CIF = 1;	

		switch (SN_I2C0->STAT)
		{			
			case	(Lost_Arbitration | mskI2C_MST_MASTER):
				I2C_Start();	
			break;
			
			/* RX with ACK/NACK transfer is down */	
			case	(RX_DONE | mskI2C_MST_MASTER):
				bI2C_RxFIFO[bI2C_Rx_cnts++] = SN_I2C0->RXDATA;					
				if(bI2C_Rx_cnts < (bI2C_RxFIFO_cnts - 1))
					SN_I2C0->CTRL_b.ACK	=	1;
				else if(bI2C_Rx_cnts == (bI2C_RxFIFO_cnts - 1))
					SN_I2C0->CTRL_b.NACK = 1;						
				else if(bI2C_Rx_cnts == bI2C_RxFIFO_cnts)
					I2C_Stop(); 
				Busy = 0;				
			break;
				
			/* SLA+W or Data has been transmitted and ACK has been received */
			case	(ACK_DONE | mskI2C_MST_MASTER):			
				if(EEPROM_WR == 1)
				{
					Busy = 0;					
					if(bI2C_RxFIFO_cnts == 1)
						SN_I2C0->CTRL_b.NACK = 1;	
					else
						SN_I2C0->CTRL_b.ACK = 1;
				}			
				if(EEPROM_WR == 0)
				{
					if(Send_Address == 0) 
					{
						bI2C_Tx_cnts++;						
						if(bI2C_Tx_cnts <  bI2C_TxFIFO_cnts)
							SN_I2C0->TXDATA = *bTX_ptr++;
						else if(bI2C_Tx_cnts == bI2C_TxFIFO_cnts)
							Busy = 0;					
					}
					else
						Busy = 0;
				}				
			break;
			
			/* SLA+W or Data has been transmitted and NACK has been received */	
			case	(NACK_DONE | mskI2C_MST_MASTER):				
				SN_I2C0->CTRL_b.STO = 1;			
				Error  = 1;			
			break;
			
			/* START has been transmitted and prepare SLA+W/SLA+R */	
			case	(START_DONE | mskI2C_MST_MASTER):			
				#if (EEPROM_less_than_32K == 1)				
					SN_I2C0->TXDATA = Device_ADDRESS | (EEPROM_ADR_H << 1) | EEPROM_WR;					
				#else			
					SN_I2C0->TXDATA = Device_ADDRESS | EEPROM_WR;					
				#endif			
			break;				
			
			default:
				SN_I2C0->CTRL_b.I2CEN = 0;
				SN_I2C0->CTRL_b.I2CEN = 1;
				SN_I2C0->CTRL_b.STA = 1;			
			break;
		}
	}	
}	

