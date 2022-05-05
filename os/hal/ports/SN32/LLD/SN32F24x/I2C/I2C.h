#ifndef __SN32F240_I2C_H
#define __SN32F240_I2C_H

/*_____ I N C L U D E S ____________________________________________________*/


/*_____ D E F I N I T I O N S ______________________________________________*/
/*
Base Address: 0x4001 8000 (I2C0)
							0x4005 A000 (I2C1)
*/	

/* I2C n Control register <I2Cn_CTRL> (0x00) */
																				//[1:1]Assert NACK (HIGH level to SDA) flag
#define	I2C_NACK_NOFUNCTION 				0		//No function
#define	I2C_NACK 										1		//An NACK will be returned during the acknowledge clock pulse on SCLn
#define mskI2C_NACK_NOFUNCTION			(I2C_NACK_NOFUNCTION<<1)
#define	mskI2C_NACK									(I2C_NACK<<1)

																				//[2:2]Assert ACK (Low level to SDA) flag
#define	I2C_ACK_NOFUNCTION 					0		//No function
#define	I2C_ACK  										1		//An ACK will be returned during the acknowledge clock pulse on SCLn
#define mskI2C_ACK_NOFUNCTION				(I2C_ACK_NOFUNCTION<<2)
#define	mskI2C_ACK									(I2C_ACK<<2)

																				//[4:4]STOP flag
#define	I2C_STO_IDLE								0		//Stop condition idle
#define	I2C_STO_STOP								1		//Transmit a STOP condition in master mode, or recover from an error condition in slave mode.
#define mskI2C_STO_IDLE							(I2C_STO_IDLE<<4)
#define	mskI2C_STO_STOP							(I2C_STO_STOP<<4)

																		//[5:5]START bit
#define	I2C_STA_IDLE								0		//No START condition or Repeated START condition will be generated
#define	I2C_STA_START								1		//transmit a START or a Repeated START condition
#define mskI2C_STA_IDLE							(I2C_STA_IDLE<<5)
#define	mskI2C_STA_START						(I2C_STA_START<<5)

#define	I2C_I2CEN_DIS								0		//[8:8]I2C Interface enable bit
#define	I2C_I2CEN_EN								1
#define mskI2C_I2CEN_DIS						(I2C_I2CEN_DIS<<8)
#define	mskI2C_I2CEN_EN							(I2C_I2CEN_EN<<8)


/* I2C n Status register <I2Cn_STAT> (0x04) */
																							//[0:0]RX done status
#define	I2C_RX_DN_NO_HANDSHAKE 						0		//No RX with ACK/NACK transfer
#define	I2C_RX_DN_HANDSHAKE 							1		//8-bit RX with ACK/NACK transfer is done
#define mskI2C_RX_DN_NO_HANDSHAKE					(I2C_RX_DN_NO_HANDSHAKE<<0)
#define	mskI2C_RX_DN_HANDSHAKE						(I2C_RX_DN_HANDSHAKE<<0)

																							//[1:1]ACK done status
#define	I2C_ACK_STAT_NO_RECEIVED_ACK 			0		//Not received an ACK
#define	I2C_ACK_STAT_RECEIVED_ACK 				1		//Received an ACK
#define mskI2C_ACK_STAT_NO_RECEIVED_ACK		(I2C_ACK_STAT_NO_RECEIVED_ACK<<1)
#define	mskI2C_ACK_STAT_RECEIVED_ACK			(I2C_ACK_STAT_RECEIVED_ACK<<1)


																							//[2:2]NACK done status
#define	I2C_NACK_STAT_NO_RECEIVED_NACK		0		//Not received a NACK
#define	I2C_NACK_STAT_RECEIVED_NACK 			1		//Received a NACK
#define mskI2C_NACK_STAT_NO_RECEIVED_NACK		(I2C_NACK_STAT_NO_RECEIVED_NACK<<2)
#define	mskI2C_NACK_STAT_RECEIVED_NACK			(I2C_NACK_STAT_RECEIVED_NACK<<2)

																							//[3:3]Stop done status
#define	I2C_STOP_DN_NO_STOP								0		//No STOP bit
#define	I2C_STOP_DN_STOP	  							1		//MASTER mode, a STOP condition was issued
																							//SLAVE mode, a STOP condition was received
#define mskI2C_STOP_DN_NO_STOP						(I2C_STOP_DN_NO_STOP<<3)
#define	mskI2C_STOP_DN_STOP								(I2C_STOP_DN_STOP<<3)

																							//[4:4]Start done status
#define	I2C_START_DN_NO_START							0		//No START bit
#define	I2C_START_DN_START								1		//MASTER mode, a START bit was issued
																							//SLAVE mode, a START bit was received
#define mskI2C_START_DN_NO_START					(I2C_START_DN_NO_START<<4)
#define	mskI2C_START_DN_START							(I2C_START_DN_START<<4)


#define	I2C_MST_SLAVE											0		//[5:5]Master/Slave status
#define	I2C_MST_MASTER										1
#define mskI2C_MST_SLAVE									(I2C_MST_SLAVE<<5)
#define	mskI2C_MST_MASTER									(I2C_MST_MASTER<<5)

#define	mskI2C_STA_STA_STO								((I2C_START_DN_START<<4)|(I2C_STOP_DN_STOP<<3))
#define	mskI2C_STA_MASTER_STA_STO					((I2C_MST_MASTER<<5)|(I2C_START_DN_START<<4)|(I2C_STOP_DN_STOP<<3))


																							//[6:6]Slave address check
#define	I2C_SLV_RX_NO_MATCH_ADDR					0		//No matched slave address
#define	I2C_SLV_RX_MATCH_ADDR							1		//Slave address hit, and is called for RX in slave mode
#define mskI2C_SLV_RX_NO_MATCH_ADDR				(I2C_SLV_RX_NO_MATCH_ADDR<<6)
#define	mskI2C_SLV_RX_MATCH_ADDR					(I2C_SLV_RX_MATCH_ADDR<<6)

																							//[7:7]Slave address check
#define	I2C_SLV_TX_NO_MATCH_ADDR					0		//No matched slave address
#define	I2C_SLV_TX_MATCH_ADDR							1		//Slave address hit, and is called for TX in slave mode.
#define mskI2C_SLV_TX_NO_MATCH_ADDR				(I2C_SLV_TX_NO_MATCH_ADDR<<7)
#define	mskI2C_SLV_TX_MATCH_ADDR					(I2C_SLV_TX_MATCH_ADDR<<7)

																							//[8:8]Lost arbitration
#define	I2C_LOST_ARB_NO_LOST							0		//Not lost arbitration
#define	I2C_LOST_ARB_LOST_ARBITRATION			1		//Lost arbitration
#define mskI2C_LOST_ARB_NO_LOST						(I2C_LOST_ARB_NO_LOST<<8)
#define	mskI2C_LOST_ARB_LOST_ARBITRATION	(I2C_LOST_ARB_LOST_ARBITRATION<<8)

																							//[9:9]Time-out status
#define	I2C_TIMEOUT_NO_TIMEOUT						0		//No Timeout
#define	I2C_TIMEOUT_TIMEOUT								1		//Timeout
#define mskI2C_TIMEOUT_TIMEOUT						(I2C_TIMEOUT_TIMEOUT<<9)
#define	mskI2C_TIMEOUT_NO_TIMEOUT					(I2C_TIMEOUT_NO_TIMEOUT<<9)

																							//[15:15]I2C Interrupt flag
#define	I2C_I2CIF_STAUS_NO_CHANGE					0		//I2C status doesn’t change
#define	I2C_I2CIF_INTERRUPT								1		//Read, I2C status changes
																							//Write, Clear this flag
#define mskI2C_I2CIF_STAUS_NO_CHANGE			(I2C_I2CIF_STAUS_NO_CHANGE<<15)
#define	mskI2C_I2CIF_INTERRUPT						(I2C_I2CIF_INTERRUPT<<15)


/* I2C n TX Data register <I2Cn_TXDATA> (0x08) */


/* I2C n RX Data register <I2Cn_RXDATA> (0x0C) */


/* I2C n Slave Address 0 register <I2Cn_SLVADDR0> (0x10) */
																								//[9:0]The I2C slave address
#define	I2C_ADDR_SLAVE_ADDR0							0x07	//ADD[9:0] is valid when ADD_MODE = 1
																								//ADD[7:1] is valid when ADD_MODE = 0

																								//[30:30]General call address enable bit
#define	I2C_GCEN_DIS											0			//Disable
#define	I2C_GCEN_EN												1			//Enable general call address (0x0)
#define mskI2C_GCEN_DIS										(I2C_GCEN_DIS<<30)
#define	mskI2C_GCEN_EN										(I2C_GCEN_EN<<30)

																								//[31:31]Slave address mode
#define	I2C_ADD_MODE_7BIT									0			//7-bit address mode
#define	I2C_ADD_MODE_10BIT								1			//10-bit address mode
#define mskI2C_ADD_MODE_7BIT							(I2C_ADD_MODE_7BIT<<31)
#define	mskI2C_ADD_MODE_10BIT							(I2C_ADD_MODE_10BIT<<31)


/* I2C n Slave Address 1~3 register <I2Cn_SLVADDR1~3> (0x14/0x18/0x1C) */
																								//The I2C slave address 1~3
																								//ADD[9:0] is valid when ADD_MODE = 1
																								//ADD[7:1] is valid when ADD_MODE = 0																						
#define	I2C_ADDR_SLAVE_ADDR1							0x0A	//The I2C slave address 1
#define	I2C_ADDR_SLAVE_ADDR2							0			//The I2C slave address 2
#define	I2C_ADDR_SLAVE_ADDR3							0			//The I2C slave address 3

#define	I2C_SLAVE0												0			//Slave Number 0
#define	I2C_SLAVE1												1			//Slave Number 1
#define	I2C_SLAVE2												2			//Slave Number 2
#define	I2C_SLAVE3												3			//Slave Number 3

/* I2C n SCL High Time register <(I2Cn_SCLHT> (0x20) */
#define	I2C0_SCLHT												14		//[7:0], Count for SCL High Period time
#define	I2C1_SCLHT												4			//SCL High Period Time = (SCLH+1) * I2C0_PCLK cycle


/* I2C n SCL Low Time register <(I2Cn_SCLLT> (0x24) */
#define	I2C0_SCLLT												14		//[7:0], Count for SCL Low Period time
#define	I2C1_SCLLT												4			//SCL Loq Period Time = (SCLH+1) * I2C0_PCLK cycle


/* I2C n Timeout Control register <I2Cn_TOCTRL> (0x2C) */
#define	I2C_TO_DIS												0			//[15:0], Count for checking Timeout
#define	I2C_TO_PERIOD_TIME								0			//N: Timeout period time = N*I2Cn_PCLK cycle


/* I2C n Monitor Mode Control register <I2Cn_MMCTRL> (0x30) */
#define	I2C_MMEN_MONITOR_DIS							0			//[0:0]Monitor mode enable bit
#define	I2C_MMEN_MONITOR_EN								1
#define	mskI2C_MMEN_MONITOR_DIS						(I2C_MMEN_MONITOR_DIS<<0)		//Monitor mode enable bit
#define	mskI2C_MMEN_MONITOR_EN						(I2C_MMEN_MONITOR_EN<<0)

																								//[1:1]SCL output enable bit
#define	I2C_SCLOEN_DIS										0			//SCL output will be forced high
#define	I2C_SCLOEN_EN											1			//I2C holds the clock line low until it has had time to respond to an I2C interrupt
#define	mskI2C_SCLOEN_DIS									(I2C_SCLOEN_DIS<<1)	//SCL output enable bit
#define	mskI2C_SCLOEN_EN									(I2C_SCLOEN_EN<<1)

																									//[2:2]Match address selection
#define	I2C_MATCH_ALL_ADDR0_3							0			//Interrupt will only be generated when the address matches
#define	I2C_MATCH_ALL_ANY_ADDR						1			//In monitor mode, an interrupt will be generated on ANY address received
#define	mskI2C_MATCH_ALL_ADDR0_3					(I2C_MATCH_ALL_ADDR0_3<<2)
#define	mskI2C_MATCH_ALL_ANY_ADDR					(I2C_MATCH_ALL_ANY_ADDR<<2)


#define I2C_ERROR													0x00001

/*_____ M A C R O S ________________________________________________________*/


/*_____ D E C L A R A T I O N S ____________________________________________*/

//------------------I2C-------------------------
//Address
extern uint16_t hwI2C_Device_Addr_I2C0;
extern uint16_t hwI2C_Device_Addr_I2C1;

//Check Flag
extern uint32_t wI2C_TimeoutFlag;
extern uint32_t wI2C_ArbitrationFlag;

//Error Flag
extern uint32_t wI2C_RegisterCheckError;
extern uint32_t wI2C_TotalError;

//------------------Master Tx-------------------------
//TX FIFO
extern uint8_t 	bI2C_MasTxData[10];

//Control Flag
extern uint8_t 	bI2C_MasTxPointer;
extern uint32_t wI2C_MasTxCtr; 

//------------------Master Rx-------------------------
//RX FIFO
extern uint8_t		bI2C_MasRxData[10];

//Rx Control Flag
extern uint8_t	bI2C_MasRxPointer;
extern uint32_t wI2C_ReturnNackFlag;
extern uint32_t wI2C_RxControlFlag;

//------------------Slave Rx-------------------------
//RX FIFO
extern uint8_t bI2C_SlaRxData[10];
//Rx Control Flag
extern uint8_t bI2C_SlaRxPointer;
//extern volatile uint8_t bEndSRxFlagI2C;

//------------------Slave Tx-------------------------
//TX FIFO
extern uint8_t bI2C_SlaTxData[10];
//Tx Control Flag
extern uint8_t bI2C_SlaTxPointer;
//extern volatile uint8_t bEndSTxFlagI2C;

void I2C0_Init(void);
void I2C1_Init(void);
void I2C0_Timeout_Ctrl(uint32_t wI2CTo);
void I2C1_Timeout_Ctrl(uint32_t wI2CTo);
void I2C0_Monitor_Mode_Ctrl(uint32_t wI2CmatchAll, uint32_t wI2Cscloen, uint32_t wI2Cmmen);
void I2C1_Monitor_Mode_Ctrl(uint32_t wI2CmatchAll, uint32_t wI2Cscloen, uint32_t wI2Cmmen);
void Set_I2C0_Address(uint8_t bI2CaddMode, uint8_t bSlaveNo, uint32_t bSlaveAddr, uint8_t bGCEnable);
void Set_I2C1_Address(uint8_t bI2CaddMode, uint8_t bSlaveNo, uint32_t bSlaveAddr, uint8_t bGCEnable);

extern void I2C0_Enable(void);
extern void I2C0_Disable(void);
extern void I2C1_Enable(void);
extern void I2C1_Disable(void);

void I2C0_Master_Tx(volatile uint8_t *bDataFIFO, volatile uint8_t *bPointerFIFO, volatile uint8_t *bCommStop, volatile uint8_t bSlaveAddress, volatile uint32_t wTxNum, volatile uint32_t wRepeatTX, volatile uint32_t wReTxNum);
void I2C0_Master_Rx(volatile uint8_t *bDataFIFO, volatile uint8_t *bPointerFIFO, volatile uint8_t *bCommStop, volatile uint8_t bSlaveAddress, volatile uint32_t wRxNum, volatile uint32_t wRepeatRX, volatile uint32_t wReRxNum);
void I2C1_Master_Tx(volatile uint8_t *bDataFIFO, volatile uint8_t *bPointerFIFO, volatile uint8_t *bCommStop, volatile uint8_t bSlaveAddress, volatile uint32_t wTxNum, volatile uint32_t wRepeatTX, volatile uint32_t wReTxNum);
void I2C1_Master_Rx(volatile uint8_t *bDataFIFO, volatile uint8_t *bPointerFIFO, volatile uint8_t *bCommStop, volatile uint8_t bSlaveAddress, volatile uint32_t wRxNum, volatile uint32_t wRepeatRX, volatile uint32_t wReRxNum);



void I2C1_Slave_Rx(volatile uint8_t *bDataFIFO, volatile uint8_t *bPointerFIFO, volatile uint8_t *bCommStop, volatile uint32_t wNumForNack);
void I2C1_Slave_Tx(volatile uint8_t *bDataFIFO, volatile uint8_t *bPointerFIFO, volatile uint8_t *bCommStop);

void I2C1_Mointer_Mode(volatile uint8_t *bDataFIFO, volatile uint8_t *bPointerFIFO, volatile uint8_t *bCommStop);

void I2C0_Slave_Rx(volatile uint8_t *bDataFIFO, volatile uint8_t *bPointerFIFO, volatile uint8_t *bCommStop, volatile uint32_t wNumForNack);
void I2C0_Slave_Tx(volatile uint8_t *bDataFIFO, volatile uint8_t *bPointerFIFO, volatile uint8_t *bCommStop);

void I2C0_Mointer_Mode(volatile uint8_t *bDataFIFO, volatile uint8_t *bPointerFIFO, volatile uint8_t *bCommStop);


#endif	/*__SN32F240_I2C_H*/
