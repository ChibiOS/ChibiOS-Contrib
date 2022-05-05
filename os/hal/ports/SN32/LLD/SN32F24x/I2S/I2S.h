#ifndef __SN32F240_I2S_H
#define __SN32F240_I2S_H

/*_____ I N C L U D E S ____________________________________________________*/


/*_____ D E F I N I T I O N S ______________________________________________*/
/*							
Base Address: 0x4001 A000												
*/

/* I2S Control register <I2S_CTRL> (0x00) */
										
#define	I2S_START_DIS									0			//[0:0]Start Transmit/Receive bit
#define	I2S_START_EN									1
#define	mskI2S_START_DIS							(mskI2S_START_DIS<<0)
#define	mskI2S_START_EN								(mskI2S_START_EN<<0)

#define	I2S_MUTE_DIS									0			//[1:1]Mute enable bit
#define	I2S_MUTE_EN										1
#define	mskI2S_MUTE_DIS								(I2S_MUTE_DIS<<1)
#define	mskI2S_MUTE_EN								(I2S_MUTE_EN<<1)

#define	I2S_MONO_STERO								0			//[2:2]Mono/Stereo selection bit
#define	I2S_MONO_MONO									1
#define	mskI2S_MONO_STERO							(I2S_MONO_STERO<<2)
#define	mskI2S_MONO_MONO							(I2S_MONO_MONO<<2)

#define	I2S_MS_MASTER_MODE						0			//[3:3]Master/Slave selection bit
#define	I2S_MS_SLAVE_MODE							1
#define	mskI2S_MS_MASTER_MODE					(I2S_MS_MASTER_MODE<<3)
#define	mskI2S_MS_SLAVE_MODE					(I2S_MS_SLAVE_MODE<<3)	

																						//[5:4]I2S operation format
#define	I2S_FORMAT_STANDARD						0			//Standard I2S format
#define	I2S_FORMAT_LEFTJUST						1			//Left-justified format
#define	I2S_FORMAT_RIGHTJUST					2			//Right(MSB)-justified format
#define	mskI2S_FORMAT_STANDARD				(I2S_FORMAT_STANDARD<<4)
#define	mskI2S_FORMAT_LEFTJUST				(I2S_FORMAT_LEFTJUST<<4)	
#define	mskI2S_FORMAT_RIGHTJUST				(I2S_FORMAT_RIGHTJUST<<4)

#define	I2S_TXEN_DIS									0			//[6:6]Transmit enable bit
#define	I2S_TXEN_EN										1
#define	mskI2S_TXEN_DIS								(I2S_TXEN_DIS<<6)	
#define	mskI2S_TXEN_EN								(I2S_TXEN_EN<<6)

#define	I2S_RXEN_DIS									0			//[7:7]Receiver enable bit
#define	I2S_RXEN_EN										1
#define	mskI2S_RXEN_DIS								(I2S_RXEN_DIS<<7)	
#define	mskI2S_RXEN_EN								(I2S_RXEN_EN<<7)

#define	I2S_CLRTXFIFO_RESET_TXFIFO		1			//[8:8]Clear I2S TX FIFO
#define	I2S_CLRRXFIFO_RESET_RXFIFO		1			//[9:9]Clear I2S TX FIFO
																						
#define	I2S_DL_8BITS									0			//[11:10]I2S Data Length
#define	I2S_DL_16BITS									1
#define	I2S_DL_24BITS									2
#define	I2S_DL_32BITS									3

#define	I2S_TXFIFOTH_0								0			//[14:12]TX FIFO Threshold level[2:0]
#define	I2S_TXFIFOTH_1								1
#define	I2S_TXFIFOTH_2								2
#define	I2S_TXFIFOTH_3								3
#define	I2S_TXFIFOTH_4								4
#define	I2S_TXFIFOTH_5								5
#define	I2S_TXFIFOTH_6								6
#define	I2S_TXFIFOTH_7								7

#define	I2S_RXFIFOTH_0								0			//[18:16]RX FIFO Threshold level[2:0]
#define	I2S_RXFIFOTH_1								1
#define	I2S_RXFIFOTH_2								2
#define	I2S_RXFIFOTH_3								3
#define	I2S_RXFIFOTH_4								4
#define	I2S_RXFIFOTH_5								5
#define	I2S_RXFIFOTH_6								6
#define	I2S_RXFIFOTH_7								7

#define	I2S_CHLENGTH_8BITS						7			//[24:20]Bit number of single channel[4:0]
#define	I2S_CHLENGTH_9BITS						8		
#define	I2S_CHLENGTH_10BITS						9		
#define	I2S_CHLENGTH_11BITS						10		
#define	I2S_CHLENGTH_12BITS						11		
#define	I2S_CHLENGTH_13BITS						12		
#define	I2S_CHLENGTH_14BITS						13		
#define	I2S_CHLENGTH_15BITS						14		
#define	I2S_CHLENGTH_16BITS						15	
#define	I2S_CHLENGTH_17BITS						16		
#define	I2S_CHLENGTH_18BITS						17		
#define	I2S_CHLENGTH_19BITS						18		
#define	I2S_CHLENGTH_20BITS						19		
#define	I2S_CHLENGTH_21BITS						20		
#define	I2S_CHLENGTH_22BITS						21		
#define	I2S_CHLENGTH_23BITS						22		
#define	I2S_CHLENGTH_24BITS						23		
#define	I2S_CHLENGTH_25BITS						24		
#define	I2S_CHLENGTH_26BITS						25		
#define	I2S_CHLENGTH_27BITS						26		
#define	I2S_CHLENGTH_28BITS						27		
#define	I2S_CHLENGTH_29BITS						28		
#define	I2S_CHLENGTH_30BITS						29		
#define	I2S_CHLENGTH_31BITS						30		
#define	I2S_CHLENGTH_32BITS						31		

#define	I2S_I2SEN_DIS 								0			//[31:31]I2S enable bit
#define	I2S_I2SEN_EN									1
#define	mskI2S_I2SEN_DIS							(I2S_I2SEN_DIS<<31)	
#define	mskI2S_I2SEN_EN								(I2S_I2SEN_EN<<31)

/* I2S Clock register <I2S_CLK> (0x04) */
																					//[2:0]MCLK divider
#define	I2S_MCLKDIV_DIV0							0		//MCLK = MCLK source
#define	mskI2S_MCLKDIV_DIV0						(I2S_MCLKDIV_DIV0<<0)	
#define	I2S_MCLKDIV_DIV1							1		//MCLK = MCLK source / 2
#define	mskI2S_MCLKDIV_DIV1						(I2S_MCLKDIV_DIV1<<0)	
#define	I2S_MCLKDIV_DIV2							2		//MCLK = MCLK source / 4	
#define	mskI2S_MCLKDIV_DIV2						(I2S_MCLKDIV_DIV2<<0)	
#define	I2S_MCLKDIV_DIV3							3		//MCLK = MCLK source / 6
#define	mskI2S_MCLKDIV_DIV3						(I2S_MCLKDIV_DIV3<<0)	
#define	I2S_MCLKDIV_DIV4							4		//MCLK = MCLK source / 8
#define	mskI2S_MCLKDIV_DIV4						(I2S_MCLKDIV_DIV4<<0)	
#define	I2S_MCLKDIV_DIV5							5		//MCLK = MCLK source / 10
#define	mskI2S_MCLKDIV_DIV5						(I2S_MCLKDIV_DIV5<<0)	
#define	I2S_MCLKDIV_DIV6							6		//MCLK = MCLK source / 12
#define	mskI2S_MCLKDIV_DIV6						(I2S_MCLKDIV_DIV6<<0)	
#define	I2S_MCLKDIV_DIV7							7		//MCLK = MCLK source / 14
#define	mskI2S_MCLKDIV_DIV7						(I2S_MCLKDIV_DIV7<<0)	


#define	I2S_MCLKOEN_OUTPUT_DIS				0		//[3:3]MCLK output enable bit
#define	I2S_MCLKOEN_OUTPUT_EN					1
#define	mskI2S_MCLKOEN_OUTPUT_DIS			(I2S_MCLKOEN_OUTPUT_DIS<<3)	
#define	mskI2S_MCLKOEN_OUTPUT_EN			(I2S_MCLKOEN_OUTPUT_EN<<3)

																					//[4:4]MCLK source selection bit
#define	I2S_MCLKSEL_I2S_PCLK					0		//MCLK source of master is from I2S_PCLK
#define	I2S_MCLKSEL_GPIO							1		//MCLK source of master is from GPIO
#define	mskI2S_MCLKSEL_I2S_PCLK				(I2S_MCLKSEL_I2S_PCLK<<4)	
#define	mskI2S_MCLKSEL_GPIO						(I2S_MCLKSEL_GPIO<<4)

																					//[15:8]BCLK divider
#define	I2S_BCLKDIV_DIV								0		// MCLK/n, n = 2, 4, 6, 8, ...,512
#define	mskI2S_BCLKDIV_DIV						(I2S_BCLKDIV_DIV<<8)
																					//[16:16]I2S clock source selection
#define	I2S_CLKSEL_HCLK								0		//HCLK
#define	I2S_CLKSEL_EHS								1		//EHS
#define	mskI2S_CLKSEL_HCLK						(I2S_CLKSEL_HCLK<<16)	
#define	mskI2S_CLKSEL_EHS							(I2S_CLKSEL_EHS<<16)


/* I2S Status register <I2S_STATUS> (0x08) */
#define mskI2S_I2SINT									(0x1<<0)		//I2S interrupt flag
#define mskI2S_RIGHTCH								(0x1<<1)		//Current channel status
#define mskI2S_TXFIFOTHF							(0x1<<6)		//TX FIFO threshold flag
#define mskI2S_RXFIFOTHF							(0x1<<7)		//RX FIFO threshold flag
#define mskI2S_TXFIFOFULL							(0x1<<8)		//TX FIFO full flag
#define mskI2S_RXFIFOFULL							(0x1<<9)		//RX FIFO full flag	
#define mskI2S_TXFIFOEMPTY						(0x1<<10)		//TX FIFO empty flag
#define mskI2S_RXFIFOEMPTY						(0x1<<11)		//RX FIFO empty flag
#define mskI2S_TXFIFOLV								(0xf<<12)		//TX FIFO used level
#define mskI2S_RXFIFOLV								(0xf<<17)		//RX FIFO used level


/* I2S Interrupt Enable register <I2S_IE> (0x0C) */
#define	I2S_TXFIFOOVFIEN_DIS					0		//[4:4]TX FIFO overflow interrupt enable bit
#define	I2S_TXFIFOOVFIEN_EN						1
#define	mskI2S_TXFIFOOVFIEN_DIS				(I2S_TXFIFOOVFIEN_DIS<<4)	
#define	mskI2S_TXFIFOOVFIEN_EN				(I2S_TXFIFOOVFIEN_EN<<4)

#define	I2S_RXFIFOUDFIEN_DIS					0		//[5:5]RX FIFO underflow interrupt enable bit
#define	I2S_RXFIFOUDFIEN_EN						1
#define	mskI2S_RXFIFOUDFIEN_DIS				(I2S_RXFIFOUDFIEN_DIS<<5)	
#define	mskI2S_RXFIFOUDFIEN_EN				(I2S_RXFIFOUDFIEN_EN<<5)

#define	I2S_TXFIFOTHIEN_DIS						0		//[6:6]TX FIFO threshold interrupt enable bit
#define	I2S_TXFIFOTHIEN_EN						1
#define	mskI2S_TXFIFOTHIEN_DIS				(I2S_TXFIFOTHIEN_DIS<<6)	
#define	mskI2S_TXFIFOTHIEN_EN					(I2S_TXFIFOTHIEN_EN<<6)

#define	I2S_RXFIFOTHIEN_DIS						0		//[7:7]RX FIFO threshold interrupt enable bit
#define	I2S_RXFIFOTHIEN_EN						1
#define	mskI2S_RXFIFOTHIEN_DIS				(I2S_RXFIFOTHIEN_DIS<<7)	
#define	mskI2S_RXFIFOTHIEN_EN					(I2S_RXFIFOTHIEN_EN<<7)


/* I2S Raw Interrupt Status register <I2S_RIS> (0x10) */
/* I2S Interrupt Clear register <I2S_IC> (0x14) */
#define mskI2S_TXFIFOOVIF							(0x1<<4)		//TX FIFO overflow interrupt flag
#define mskI2S_TXFIFOOVIC							mskI2S_TXFIFOOVIF
#define mskI2S_RXFIFOUDIF							(0x1<<5)		//RX FIFO underflow interrupt flag
#define mskI2S_RXFIFOUDIC							mskI2S_RXFIFOUDIF
#define mskI2S_TXFIFOTHIF							(0x1<<6)		//TX FIFO threshold interrupt flag
#define mskI2S_TXFIFOTHIC							mskI2S_TXFIFOTHIF
#define mskI2S_RXFIFOTHIF							(0x1<<7)		//RX FIFO threshold interrupt flag
#define mskI2S_RXFIFOTHIC							mskI2S_RXFIFOTHIF


/*_____ M A C R O S ________________________________________________________*/
//I2S HCLK Enable/Disable
#define	__I2S_ENABLE_I2SHCLK					SN_SYS1->AHBCLKEN |= (1<<22)
#define	__I2S_DISABLE_I2SHCLK					SN_SYS1->AHBCLKEN &= ~(1<<22)

//Reset I2S FIFO
#define	__I2S_RESET_TXFIFO		(SN_I2S->CTRL_b.CLRTXFIFO = I2S_CLRTXFIFO_RESET_TXFIFO)
#define	__I2S_RESET_RXFIFO		(SN_I2S->CTRL_b.CLRRXFIFO = I2S_CLRRXFIFO_RESET_RXFIFO)

//I2S Start
#define	__I2S_START						(SN_I2S->CTRL_b.START = 1)

/*_____ D E C L A R A T I O N S ____________________________________________*/
void I2S_Master_Init(void);
void I2S_Slave_Init(void);
void I2S_Enable(void);
void I2S_Disable(void);
void I2S_Interrupt_Enable(void);

#endif	/*__SN32F240_I2S_H*/
