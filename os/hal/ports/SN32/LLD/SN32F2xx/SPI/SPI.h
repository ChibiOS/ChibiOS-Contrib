#ifndef __SN32F2XX_SPI_H
#define __SN32F2XX_SPI_H
#include "hal.h"


/*_____ I N C L U D E S ____________________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/
/*
Base Address: 0x4001 C000 (SPI0)

*/

/* SPI n Control register 0 <SPIn_CTRL0> (0x00) */
#define SPI_SPIEN_DIS                 0            //[0:0] SPI enable bit
#define SPI_SPIEN_EN                  1
#define mskSPI_SPIEN_DIS              (SPI_SPIEN_DIS<<0)
#define mskSPI_SPIEN_EN               (SPI_SPIEN_EN<<0)

                                                                            //[1:1] Loop back mode disable
#define SPI_LOOPBACK_DIS              0            //Disable
#define SPI_LOOPBACK_EN               1            //Data input from data output
#define mskSPI_LOOPBACK_DIS           (SPI_LOOPBACK_DIS<<1)
#define mskSPI_LOOPBACK_EN            (SPI_LOOPBACK_EN<<1)

                                                                            //[2:2] Slave data output disable bit (ONLY used in slave mode)
#define SPI_SDODIS_EN                 0         //Enable slave data output
#define SPI_SDODIS_DIS                1         //Disable slave data output. (MISO=0)
#define mskSPI_SDODIS_EN              (SPI_SDODIS_EN<<2)
#define mskSPI_SDODIS_DIS             (SPI_SDODIS_DIS<<2)

#define SPI_MS_MASTER_MODE            0            //[3:3] Master/Slave selection bit
#define SPI_MS_SLAVE_MODE             1
#define mskSPI_MS_MASTER_MODE         (SPI_MS_MASTER_MODE<<3)
#define mskSPI_MS_SLAVE_MODE          (SPI_MS_SLAVE_MODE<<3)

                                                                            //[7:6] SPI FSM and FIFO Reset bit
#define SPI_FRESET_DO_NOTHING         0            //Do nothing
#define SPI_FRESET_RESET_FIFO         3            //Reset finite state machine and FIFO
#define mskSPI_FRESET_DO_NOTHING      (SPI_FRESET_DO_NOTHING<<6)
#define mskSPI_FRESET_RESET_FIFO      (SPI_FRESET_RESET_FIFO<<6)

#define SPI_DL_3                      2            //[11:8] Data Length = DL[3:0]+1
#define SPI_DL_4                      3
#define SPI_DL_5                      4
#define SPI_DL_6                      5
#define SPI_DL_7                      6
#define SPI_DL_8                      7
#define SPI_DL_9                      8
#define SPI_DL_10                     9
#define SPI_DL_11                     10
#define SPI_DL_12                     11
#define SPI_DL_13                     12
#define SPI_DL_14                     13
#define SPI_DL_15                     14
#define SPI_DL_16                     15

#define SPI_TXFIFOTH_0                0        //[14:12]TX FIFO Threshold level
#define SPI_TXFIFOTH_1                1
#define SPI_TXFIFOTH_2                2
#define SPI_TXFIFOTH_3                3
#define SPI_TXFIFOTH_4                4
#define SPI_TXFIFOTH_5                5
#define SPI_TXFIFOTH_6                6
#define SPI_TXFIFOTH_7                7

#define SPI_RXFIFOTH_0                0        //[17:15]RX FIFO Threshold level
#define SPI_RXFIFOTH_1                1
#define SPI_RXFIFOTH_2                2
#define SPI_RXFIFOTH_3                3
#define SPI_RXFIFOTH_4                4
#define SPI_RXFIFOTH_5                5
#define SPI_RXFIFOTH_6                6
#define SPI_RXFIFOTH_7                7

                                                                        //[18:18]Auto-SEL disable bit. For SPI mode only.
#define SPI_SELDIS_EN                 0        //Enable Auto-SEL flow control
#define SPI_SELDIS_DIS                1        //Disable Auto-SEL flow control
#define mskSPI_SELDIS_EN              (SPI_SELDIS_EN<<18)
#define mskSPI_SELDIS_DIS             (SPI_SELDIS_DIS<<18)


/* SPI n Control register 1 <SPIn_CTRL1> (0x04) */
                                                                        //[0:0]MSB/LSB selection bit
#define SPI_MLSB_MSB                  0        //MSB transmit first
#define SPI_MLSB_LSB                  1        //LSB transmit first
#define mskSPI_MLSB_MSB               (SPI_MLSB_MSB<<0)
#define mskSPI_MLSB_LSB               (SPI_MLSB_LSB<<0)

                                                                        //[1:1]Clock polarity selection bit
#define SPI_CPOL_SCK_IDLE_LOW         0        //SCK idles at Low level
#define SPI_CPOL_SCK_IDLE_HIGH        1        //SCK idles at High level
#define mskSPI_CPOL_SCK_IDLE_LOW      (SPI_CPOL_SCK_IDLE_LOW<<1)
#define mskSPI_CPOL_SCK_IDLE_HIGH     (SPI_CPOL_SCK_IDLE_HIGH<<1)

                                                                        //[2:2]Clock phase for edge sampling
#define SPI_CPHA_FALLING_EDGE         0        //Data changes at clock falling edge
#define SPI_CPHA_RISING_EDGE          1        //Data changes at clock rising edge
#define mskSPI_CPHA_FALLING_EDGE      (SPI_CPHA_FALLING_EDGE<<2)
#define mskSPI_CPHA_RISING_EDGE       (SPI_CPHA_RISING_EDGE<<2)


/* SPI n Clock Divider register <SPIn_CLKDIV> (0x08) */
                                                                        //[7:0]SPIn clock divider
#define SPI_DIV                       6        //MCLK/n,MCLK=system clk n = 2, 4, 6, 8, ...,512


/* SPI n Status register <SPIn_STAT> (0x0C) */
#define mskSPI_TX_EMPTY               (0x1<<0)        //TX FIFO empty flag
#define mskSPI_TX_FULL                (0x1<<1)        //TX FIFO full flag
#define mskSPI_RX_EMPTY               (0x1<<2)        //RX FIFO empty flag
#define mskSPI_RX_FULL                (0x1<<3)        //RX FIFO full flag
#define mskSPI_BUSY                   (0x1<<4)        //Busy flag
#define mskSPI_TXFIFOTHF              (0x1<<5)        //TX FIFO threshold flag
#define mskSPI_RXFIFOTHF              (0x1<<6)        //RX FIFO threshold flag


/* SPI n Interrupt Enable register <SPIn_IE> (0x10) */
#define SPI_RXOVFIE_DIS               0        //[0:0]RX Overflow interrupt enable
#define SPI_RXOVFIE_EN                1
#define mskSPI_RXOVFIE_DIS            (SPI_RXOVFIE_DIS<<0)
#define mskSPI_RXOVFIE_EN             (SPI_RXOVFIE_EN<<0)

#define SPI_RXTOIE_DIS                0        //[1:1]RX time-out interrupt enable
#define SPI_RXTOIE_EN                 1
#define mskSPI_RXTOIE_DIS             (SPI_RXTOIE_DIS<<1)
#define mskSPI_RXTOIE_EN              (SPI_RXTOIE_EN<<1)

#define SPI_RXFIFOTHIE_DIS            0        //[2:2]RX FIFO threshold interrupt enable
#define SPI_RXFIFOTHIE_EN             1
#define mskSPI_RXFIFOTHIE_DIS         (SPI_RXFIFOTHIE_DIS<<2)
#define mskSPI_RXFIFOTHIE_EN          (SPI_RXFIFOTHIE_EN    <<2)

#define SPI_TXFIFOTHIE_DIS            0        //[3:3]TX FIFO threshold interrupt enable
#define SPI_TXFIFOTHIE_EN             1
#define mskSPI_TXFIFOTHIE_DIS         (SPI_TXFIFOTHIE_DIS<<3)
#define mskSPI_TXFIFOTHIE_EN          (SPI_TXFIFOTHIE_EN<<3)


/* SPI n Raw Interrupt Status register <SPIn_RIS> (0x14) */
/* SPI n Interrupt Clear register <SPIn_IC> (0x18) */
#define mskSPI_RXOVFIF                (0x1<<0)    //[0:0]RX overflow interrupt flag
#define mskSPI_RXOVFIC                mskSPI_RXOVFIF

#define mskSPI_RXTOIF                 (0x1<<1)    //[1:1]RX time-out interrupt flag
#define mskSPI_RXTOIC                 mskSPI_RXTOIF

#define mskSPI_RXFIFOTHIF             (0x1<<2)    //[2:2]RX FIFO threshold interrupt flag
#define mskSPI_RXFIFOTHIC             mskSPI_RXFIFOTHIF

#define mskSPI_TXFIFOTHIF             (0x1<<3)    //[3:3]TX FIFO threshold interrupt flag
#define mskSPI_TXFIFOTHIC             mskSPI_TXFIFOTHIF


/*  SPI n Data Fetch register <SPIn_DF> (0x20) */
//[0:0]SPI data fetch control bit
#define SPI_DF_DIS                    0        //Disable
#define SPI_DF_EN                     1        //Enable when SCKn frequency > 6MHz
#define mskSPI_DF_DIS                 (SPI_DF_DIS<<0)
#define mskSPI_SPI_DF_EN              (SPI_DF_EN<<0)


/*_____ M A C R O S ________________________________________________________*/
#define __SPI0_FIFO_RESET             (SN_SPI0->CTRL0_b.FRESET = SPI_FRESET_RESET_FIFO)
#define __SPI1_FIFO_RESET             (SN_SPI1->CTRL0_b.FRESET = SPI_FRESET_RESET_FIFO)
#define __SPI0_CLR_SEL0               (SN_GPIO2->DATA_b.DATA9 = 0)
#define __SPI0_SET_SEL0               (SN_GPIO2->DATA_b.DATA9 = 1)
#define __SPI1_CLR_SEL0               (SN_GPIO2->DATA_b.DATA10 = 0)
#define __SPI1_SET_SEL0               (SN_GPIO2->DATA_b.DATA10 = 1)

//SPI Data Fetch speed (High: SCK>6MHz)
#if defined(SN32F260)
#define __SPI0_DATA_FETCH_HIGH_SPEED  (SN_SPI0->DF = SPI_DF_EN)
#define __SPI1_DATA_FETCH_HIGH_SPEED  (SN_SPI1->DF = SPI_DF_EN)
#else
#define __SPI0_DATA_FETCH_HIGH_SPEED  (SN_SPI0->DFDLY = SPI_DF_EN)
#define __SPI1_DATA_FETCH_HIGH_SPEED  (SN_SPI1->DFDLY = SPI_DF_EN)
#endif

/*_____ D E C L A R A T I O N S ____________________________________________*/
extern void SPI0_Init(void);
extern void SPI0_Enable(void);
extern void SPI0_Disable(void);
extern void SPI0_Write1(uint8_t data);
extern void SPI0_Write(uint8_t *data, uint8_t len);
extern void SPI0_Write_End(void);

extern void SPI1_Init(void);
extern void SPI1_Enable(void);
extern void SPI1_Disable(void);
extern void SPI1_Write1(uint8_t data);
extern void SPI1_Write(uint8_t *data, uint8_t len);
extern void SPI1_Write_End(void);
#endif    /*__SN32F2xx_SPI_H*/
