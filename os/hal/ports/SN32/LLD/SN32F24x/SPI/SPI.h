#ifndef __SN32F240_SSP_H
#define __SN32F240_SSP_H


/*_____ I N C L U D E S ____________________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/
/*
Base Address: 0x4001 C000 (SSP0)
							0x4005 8000 (SSP1)
*/		

/* SSP n Control register 0 <SSPn_CTRL0> (0x00) */
#define	SSP_SSPEN_DIS 					0			//[0:0] SSP enable bit
#define	SSP_SSPEN_EN  					1
#define mskSSP_SSPEN_DIS				(SSP_SSPEN_DIS<<0)
#define	mskSSP_SSPEN_EN 				(SSP_SSPEN_EN<<0)

																			//[1:1] Loop back mode disable
#define	SSP_LOOPBACK_DIS				0			//Disable
#define	SSP_LOOPBACK_EN					1			//Data input from data output
#define mskSSP_LOOPBACK_DIS			(SSP_LOOPBACK_DIS<<1)
#define	mskSSP_LOOPBACK_EN 			(SSP_LOOPBACK_EN<<1)

																			//[2:2] Slave data output disable bit (ONLY used in slave mode)
#define	SSP_SDODIS_EN						0 		//Enable slave data output
#define	SSP_SDODIS_DIS					1 		//Disable slave data output. (MISO=0)
#define mskSSP_SDODIS_EN				(SSP_SDODIS_EN<<2)
#define	mskSSP_SDODIS_DIS 			(SSP_SDODIS_DIS<<2)

#define	SSP_MS_MASTER_MODE  		0			//[3:3] Master/Slave selection bit
#define	SSP_MS_SLAVE_MODE  			1			
#define mskSSP_MS_MASTER_MODE		(SSP_MS_MASTER_MODE<<3)
#define	mskSSP_MS_SLAVE_MODE 		(SSP_MS_SLAVE_MODE<<3)

#define	SSP_FORMAT_SPI_MODE  		0			//[4:4] Interface format
#define	SSP_FORMAT_SSP_MODE  		1			
#define mskSSP_FORMAT_SPI_MODE	(SSP_FORMAT_SPI_MODE<<4)
#define	mskSSP_FORMAT_SSP_MODE 	(SSP_FORMAT_SSP_MODE<<4)

																			//[7:6] SSP FSM and FIFO Reset bit
#define	SSP_FRESET_DO_NOTHING		0			//Do nothing																	
#define	SSP_FRESET_RESET_FIFO		3			//Reset finite state machine and FIFO
#define mskSSP_FRESET_DO_NOTHING	(SSP_FRESET_DO_NOTHING<<6)
#define	mskSSP_FRESET_RESET_FIFO 	(SSP_FRESET_RESET_FIFO<<6)

#define	SSP_DL_3 								2			//[11:8] Data Length = DL[3:0]+1
#define	SSP_DL_4 								3		
#define	SSP_DL_5 								4		
#define	SSP_DL_6 								5		
#define	SSP_DL_7 								6		
#define	SSP_DL_8 								7		
#define	SSP_DL_9 								8	
#define	SSP_DL_10 							9		
#define	SSP_DL_11								10	
#define	SSP_DL_12								11	
#define	SSP_DL_13 							12	
#define	SSP_DL_14 							13	
#define	SSP_DL_15 							14	
#define	SSP_DL_16 							15	

#define	SSP_TXFIFOTH_0					0		//[14:12]TX FIFO Threshold level
#define	SSP_TXFIFOTH_1					1		
#define	SSP_TXFIFOTH_2					2		
#define	SSP_TXFIFOTH_3					3		
#define	SSP_TXFIFOTH_4					4		
#define	SSP_TXFIFOTH_5					5		
#define	SSP_TXFIFOTH_6					6		
#define	SSP_TXFIFOTH_7					7		

#define	SSP_RXFIFOTH_0					0		//[17:15]RX FIFO Threshold level
#define	SSP_RXFIFOTH_1					1		
#define	SSP_RXFIFOTH_2					2		
#define	SSP_RXFIFOTH_3					3		
#define	SSP_RXFIFOTH_4					4		
#define	SSP_RXFIFOTH_5					5		
#define	SSP_RXFIFOTH_6					6		
#define	SSP_RXFIFOTH_7					7		

																		//[18:18]Auto-SEL disable bit. For SPI mode only.
#define	SSP_SELDIS_EN						0		//Enable Auto-SEL flow control
#define	SSP_SELDIS_DIS					1		//Disable Auto-SEL flow control
#define	mskSSP_SELDIS_EN 				(SSP_SELDIS_EN<<18)
#define	mskSSP_SELDIS_DIS 			(SSP_SELDIS_DIS<<18)


/* SSP n Control register 1 <SSPn_CTRL1> (0x04) */
																		//[0:0]MSB/LSB selection bit
#define	SSP_MLSB_MSB						0		//MSB transmit first
#define	SSP_MLSB_LSB						1		//LSB transmit first
#define	mskSSP_MLSB_MSB 				(SSP_MLSB_MSB<<0)
#define	mskSSP_MLSB_LSB 				(SSP_MLSB_LSB<<0)

																		//[1:1]Clock polarity selection bit
#define	SSP_CPOL_SCK_IDLE_LOW		0		//SCK idles at Low level
#define	SSP_CPOL_SCK_IDLE_HIGH	1		//SCK idles at High level
#define	mskSSP_CPOL_SCK_IDLE_LOW 	(SSP_CPOL_SCK_IDLE_LOW<<1)
#define	mskSSP_CPOL_SCK_IDLE_HIGH (SSP_CPOL_SCK_IDLE_HIGH<<1)

																		//[2:2]Clock phase for edge sampling
#define	SSP_CPHA_FALLING_EDGE		0		//Data changes at clock falling edge
#define	SSP_CPHA_RISING_EDGE		1		//Data changes at clock rising edge
#define	mskSSP_CPHA_FALLING_EDGE 	(SSP_CPHA_FALLING_EDGE<<2)
#define	mskSSP_CPHA_RISING_EDGE		(SSP_CPHA_RISING_EDGE<<2)


/* SSP n Clock Divider register <SSPn_CLKDIV> (0x08) */
																		//[7:0]SSPn clock divider
#define	SSP_DIV  								6		//MCLK/n, n = 2, 4, 6, 8, ...,512


/* SSP n Status register <SSPn_STAT> (0x0C) */
#define mskSSP_TX_EMPTY					(0x1<<0)		//TX FIFO empty flag
#define mskSSP_TX_FULL					(0x1<<1)		//TX FIFO full flag
#define mskSSP_RX_EMPTY					(0x1<<2)		//RX FIFO empty flag
#define mskSSP_RX_FULL					(0x1<<3)		//RX FIFO full flag
#define mskSSP_BUSY							(0x1<<4)		//Busy flag
#define mskSSP_TXFIFOTHF				(0x1<<5)		//TX FIFO threshold flag
#define mskSSP_RXFIFOTHF				(0x1<<6)		//RX FIFO threshold flag

	
/* SSP n Interrupt Enable register <SSPn_IE> (0x10) */
#define	SSP_RXOVFIE_DIS					0		//[0:0]RX Overflow interrupt enable
#define	SSP_RXOVFIE_EN					1
#define	mskSSP_RXOVFIE_DIS 			(SSP_RXOVFIE_DIS<<0)
#define	mskSSP_RXOVFIE_EN				(SSP_RXOVFIE_EN<<0)

#define	SSP_RXTOIE_DIS					0		//[1:1]RX time-out interrupt enable
#define	SSP_RXTOIE_EN						1
#define	mskSSP_RXTOIE_DIS 			(SSP_RXTOIE_DIS<<1)
#define	mskSSP_RXTOIE_EN				(SSP_RXTOIE_EN<<1)

#define	SSP_RXFIFOTHIE_DIS			0		//[2:2]RX FIFO threshold interrupt enable
#define	SSP_RXFIFOTHIE_EN				1
#define	mskSSP_RXFIFOTHIE_DIS 	(SSP_RXFIFOTHIE_DIS<<2)
#define	mskSSP_RXFIFOTHIE_EN		(SSP_RXFIFOTHIE_EN	<<2)

#define	SSP_TXFIFOTHIE_DIS			0		//[3:3]TX FIFO threshold interrupt enable
#define	SSP_TXFIFOTHIE_EN				1
#define	mskSSP_TXFIFOTHIE_DIS 	(SSP_TXFIFOTHIE_DIS<<3)
#define	mskSSP_TXFIFOTHIE_EN		(SSP_TXFIFOTHIE_EN<<3)


/* SSP n Raw Interrupt Status register <SSPn_RIS> (0x14) */
/* SSP n Interrupt Clear register <SSPn_IC> (0x18) */
#define mskSSP_RXOVFIF					(0x1<<0)	//[0:0]RX overflow interrupt flag
#define mskSSP_RXOVFIC					mskSSP_RXOVFIF

#define mskSSP_RXTOIF						(0x1<<1)	//[1:1]RX time-out interrupt flag
#define mskSSP_RXTOIC						mskSSP_RXTOIF

#define mskSSP_RXFIFOTHIF				(0x1<<2)	//[2:2]RX FIFO threshold interrupt flag
#define mskSSP_RXFIFOTHIC				mskSSP_RXFIFOTHIF

#define mskSSP_TXFIFOTHIF				(0x1<<3)	//[3:3]TX FIFO threshold interrupt flag
#define mskSSP_TXFIFOTHIC				mskSSP_TXFIFOTHIF


/*  SSP n Data Fetch register <SSPn_DF> (0x20) */
																		//[0:0]SSP data fetch control bit
#define	SSP_DF_DIS							0		//Disable
#define	SSP_DF_EN								1		//Enable when SCKn frequency > 6MHz
#define	mskSSP_DF_DIS						(SSP_DF_DIS<<0)
#define	mskSSP_SSP_DF_EN				(SSP_DF_EN<<0)


/*_____ M A C R O S ________________________________________________________*/
#define	__SPI0_FIFO_RESET		(SN_SSP0->CTRL0_b.FRESET = SSP_FRESET_RESET_FIFO)
#define	__SPI1_FIFO_RESET		(SN_SSP1->CTRL0_b.FRESET = SSP_FRESET_RESET_FIFO)
#define	__SPI0_CLR_SEL0			(SN_GPIO2->DATA_b.DATA15=0)
#define	__SPI0_SET_SEL0			(SN_GPIO2->DATA_b.DATA15=1)
#define	__SPI1_CLR_SEL1			(SN_GPIO2->DATA_b.DATA14=0)
#define	__SPI1_SET_SEL1			(SN_GPIO2->DATA_b.DATA14=1)
//SSP Data Fetch speed (High: SCK>6MHz)
#define	__SSP0_DATA_FETCH_HIGH_SPEED	(SN_SSP0->DF = SSP_DF_EN)		//*(volatile unsigned long *)(0x4001C020) = 1
#define	__SSP1_DATA_FETCH_HIGH_SPEED	(SN_SSP1->DF = SSP_DF_EN)		//*(volatile unsigned long *)(0x40058020) = 1


/*_____ D E C L A R A T I O N S ____________________________________________*/
extern void SPI0_Init(void);
extern void SPI0_Enable(void);
extern void SPI0_Disable(void);

extern void SPI1_Init(void);
extern void SPI1_Enable(void);
extern void SPI1_Disable(void);
#endif	/*__SN32F760_SSP_H*/

