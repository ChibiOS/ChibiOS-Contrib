#ifndef __SN32F2XX_I2C_H
#define __SN32F2XX_I2C_H

/*_____ I N C L U D E S ____________________________________________________*/
#include <stdint.h>

/*_____ D E F I N I T I O N S ______________________________________________*/
#define EEPROM_less_than_32K	1								// 1: for EEPROM size less than 32K bits (4096x8)
																							// 0: for EEPROM size more than or equal to 32K bits (4096x8)

#define Device_ADDRESS 0xA0
#define	Lost_Arbitration			0x100
#define SLAVE_ADDRESS_HIT_TX	0x80
#define SLAVE_ADDRESS_HIT_RX	0x40
#define START_DONE						0x10
#define STOP_DONE							0x08
#define	NACK_DONE							0x04
#define ACK_DONE							0x02
#define RX_DONE								0x01

/* I2C n SCL High Time register <(I2Cn_SCLHT> (0x20) */
#define	I2C0_SCLHT												14		//[7:0], Count for SCL High Period time
																								//SCL High Period Time = (SCLH+1) * I2C0_PCLK cycle
#define	I2C0_SCLLT												14		//[7:0], Count for SCL Low Period time
																								//SCL Loq Period Time = (SCLL+1) * I2C0_PCLK cycle


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


//Recv FIFO
#define I2C_RX_FIFO_LENGTH		32

//TX FIFO
#define I2C_TX_FIFO_LENGTH		32

/*_____ M A C R O S ________________________________________________________*/


/*_____ D E C L A R A T I O N S ____________________________________________*/

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
uint8_t I2C_Read(uint16_t eeprom_adr, uint8_t read_num);
uint8_t I2C_Write(uint16_t eeprom_adr, uint8_t write_num);
#endif	/*__SN32F2XX_I2C_H*/
