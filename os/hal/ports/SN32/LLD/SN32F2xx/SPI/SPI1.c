/******************** (C) COPYRIGHT 2014 SONiX *******************************
* COMPANY:            SONiX
* DATE:                    2014/05
* AUTHOR:                SA1
* IC:                SN32F240/230/220
* DESCRIPTION:    SPI1 related functions.
*____________________________________________________________________________
* REVISION    Date                User        Description
* 1.0                2013/12/17    SA1            1. First release
*    1.1                2014/05/23    SA1            1. Add __SSP1_DATA_FETCH_HIGH_SPEED macro
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
#include "SPI.h"


/*_____ D E C L A R A T I O N S ____________________________________________*/


/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ F U N C T I O N S __________________________________________________*/

/*****************************************************************************
* Function        : SPI1_Init
* Description    : Initialization of SPI1 init
* Input            : None
* Output        : None
* Return        : None
* Note            : None
*****************************************************************************/
void SPI1_Init() {
    sys1EnableSPI1();
    SN_SPI1->CTRL0_b.DL             = SPI_DL_8;

#ifdef SN32_SPI_SLAVE_MODE
    SN_SPI1->CTRL0_b.MS             = SPI_MS_SLAVE_MODE;
    SN_SPI1->CTRL0_b.SDODIS         = SPI_SDODIS_EN;
#else
    SN_SPI1->CTRL0_b.MS             = SPI_MS_MASTER_MODE;
#endif

    SN_SPI1->CTRL0_b.LOOPBACK       = SPI_LOOPBACK_DIS;

#ifdef SN32_SPI_RXFIFO_THRESHOLD
    SN_SPI1->CTRL0_b.RXFIFOTH       = SN32_SPI_TXFIFO_THRESHOLD;
#endif

#ifdef SN32_SPI_TXFIFO_THRESHOLD
    SN_SPI1->CTRL0_b.TXFIFOTH       = SN32_SPI_TXFIFO_THRESHOLD;
#endif

#ifdef SN32_SPI_CLKDIV
    SN_SPI1->CLKDIV_b.DIV           = SN32_SPI_CLKDIV;
#else
    SN_SPI1->CLKDIV_b.DIV           = (SPI_DIV / 2) - 1;
#endif

    SN_SPI1->CTRL1_b.CPHA           = SPI_CPHA_FALLING_EDGE;
    SN_SPI1->CTRL1_b.CPOL           = SPI_CPOL_SCK_IDLE_LOW;
    SN_SPI1->CTRL1_b.MLSB           = SPI_MLSB_MSB;

#ifdef SN32_SPI_AUTOSEL
    SN_SPI1->CTRL0_b.SELDIS         = SN32_SPI_AUTOSEL;
#endif

    __SPI1_FIFO_RESET;

    uint32_t spiClock = (SN32_HCLK / ((2 * SN_SPI1->CLKDIV_b.DIV) + 2));
    if (spiClock > 6000000) {
        __SPI1_DATA_FETCH_HIGH_SPEED;
    }

    NVIC_DisableIRQ(SN32_SPI1_NUMBER);
}

/*****************************************************************************
* Function        : SPI1_Enable
* Description    : SPI1 enable setting
* Input            : None
* Output        : None
* Return        : None
* Note            : None
*****************************************************************************/
void SPI1_Enable() {
    sys1EnableSPI1();

    SN_SPI1->CTRL0_b.SPIEN = SPI_SPIEN_EN;

    __SPI1_FIFO_RESET;
}

/*****************************************************************************
* Function        : SPI1_Disable
* Description    : SPI1 disable setting
* Input            : None
* Output        : None
* Return        : None
* Note            : None
*****************************************************************************/
void SPI1_Disable() {
    SN_SPI1->CTRL0_b.SPIEN = SPI_SPIEN_DIS;

    //Disable HCLK for SSP1
    sys1DisableSPI1();
}

void SPI1_Write1(uint8_t data) {
    while (SN_SPI1->STAT_b.TX_FULL);
    SN_SPI1->DATA = data;
}

void SPI1_Write(uint8_t *data, uint8_t len) {
    for (uint8_t i = 0; i < len; i++) {
        SPI1_Write1(data[i]);
    }
}

void SPI1_Write_End() {
    while (!SN_SPI1->STAT_b.TX_EMPTY);
}
