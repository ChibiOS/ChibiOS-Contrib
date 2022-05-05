/******************** (C) COPYRIGHT 2013 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2013/12
* AUTHOR:				SA1
* IC:				SN32F240/230/220 
* DESCRIPTION:	I2C0 related functions.
*____________________________________________________________________________
* REVISION	Date				User		Description
* 1.0				2013/12/17	SA1			1. First release
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
#include "I2C.h"
#include "..\..\Utility\Utility.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/
//------------------I2C-------------------------
//Address
uint16_t hwI2C_Device_Addr_I2C0 = 0x00;
uint16_t hwI2C_Device_Addr_I2C1 = 0x00;

//Check Flag
uint32_t wI2C_TimeoutFlag = 0;
uint32_t wI2C_ArbitrationFlag = 0;

//Error Flag
uint32_t wI2C_RegisterCheckError = 0;
uint32_t wI2C_TotalError = 0;

//------------------Master Tx-------------------------
//TX FIFO
uint8_t 	bI2C_MasTxData[10];

//Tx Control Flag
uint8_t 	bI2C_MasTxPointer=0;
uint32_t wI2C_MasTxCtr=0; 

//------------------Master Rx-------------------------
//RX FIFO
uint8_t	bI2C_MasRxData[10];
//Rx Control Flag
uint8_t 	bI2C_MasRxPointer=0;
uint32_t wI2C_ReturnNackFlag=0;
uint32_t wI2C_RxControlFlag=0;

//------------------Slave Rx-------------------------
//RX FIFO
uint8_t bI2C_SlaRxData[10];
//Rx Control Flag
uint8_t bI2C_SlaRxPointer=0;

//------------------Slave Tx-------------------------
//TX FIFO
uint8_t bI2C_SlaTxData[10];
//Tx Control Flag
uint8_t bI2C_SlaTxPointer=0;

//Mointer Mode
uint8_t bI2C0_MointerAddress = 0x00;

/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ F U N C T I O N S __________________________________________________*/

/*****************************************************************************
* Function		: I2C0_Init
* Description	: Set specified value to specified bits of assigned register
* Input			: wI2C0SCLH - SCL High Time
*				  		wI2C0SCLL - SCL Low Time 
*				  		wI2C0Mode - 0: Standard/Fast mode.1: Fast-mode Plus 
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void I2C0_Init(void)
{
	//I2C0 interrupt enable
	NVIC_ClearPendingIRQ(I2C0_IRQn);	
	NVIC_EnableIRQ(I2C0_IRQn);
	NVIC_SetPriority(I2C0_IRQn,0);

	//Enable HCLK for I2C0
	SN_SYS1->AHBCLKEN |= (0x1 << 21);								//Enable clock for I2C0

	//I2C speed
	SN_I2C0->SCLHT = I2C0_SCLHT;
	SN_I2C0->SCLLT = I2C0_SCLLT;
	
	//Mointer mode
	//SN_I2C0->MMCTRL = 0x00;
	SN_I2C0->MMCTRL = mskI2C_MATCH_ALL_ADDR0_3|
										mskI2C_SCLOEN_DIS|	
										mskI2C_MMEN_MONITOR_DIS;
	
	//I2C enable
	SN_I2C0->CTRL_b.I2CEN = I2C_I2CEN_EN;
}

/*****************************************************************************
* Function		: I2C0_Timeout_Ctrl
* Description	: Set specified value to specified bits of assigned register
* Input			: wI2CTo - TimeOut Value: wI2CTo * 32 * I2C_PCLK cycle
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void I2C0_Timeout_Ctrl(uint32_t wI2CTo) 
{
		SN_I2C0->TOCTRL = wI2CTo;
}

/*****************************************************************************
* Function		: I2C0_Monitor_Mode_Ctrl
* Description	: Set specified value to specified bits of assigned register
* Input			: wI2CmatchAll - 0: No use. 1: Interrupt will be generated on ANY address received.
*				  		wI2Cscloen - 0: No use. 1: Let I2C holds the clock line low to get data. 
*				  		wI2Cmmen - 0: No use. 1: Monitor mode enable bit. 
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void I2C0_Monitor_Mode_Ctrl(uint32_t wI2CmatchAll, uint32_t wI2Cscloen, uint32_t wI2Cmmen) 
{
		SN_I2C0->TOCTRL = (wI2CmatchAll << 2) | (wI2Cscloen << 1) | (wI2Cmmen << 0);  
}

/*****************************************************************************
* Function		: Set_I2C0_Address
* Description	: Set specified value to specified bits of assigned register
* Input			: bI2CaddMode - 7 bits address is 0, 10 bits address is 1 
*				  		bSlaveNo - Slave address number 0, 1, 2, 3
*				  		bSlaveAddr - Slave value
*				  		bGCEnable - Genral call enable is 1
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void Set_I2C0_Address(uint8_t bI2CaddMode, uint8_t bSlaveNo, uint32_t bSlaveAddr, uint8_t bGCEnable)
{
	volatile uint16_t hwAddressCom=0;  


	if(bI2CaddMode == 0)
	{	
		hwAddressCom = bSlaveAddr << 1;
	}
	else
	{
		hwAddressCom = bSlaveAddr;
	}

	if(bGCEnable == 1)
	{
		SN_I2C0->SLVADDR0_b.GCEN = I2C_GCEN_EN;
	}
	else
	{
		SN_I2C0->SLVADDR0_b.GCEN = I2C_GCEN_DIS;
	}

	if(bI2CaddMode == 1)
	{
		SN_I2C0->SLVADDR0_b.ADD_MODE = I2C_ADD_MODE_10BIT;
	}
	else
	{
		SN_I2C0->SLVADDR0_b.ADD_MODE = I2C_ADD_MODE_7BIT;
	}
			
				switch (bSlaveNo)
        {
        	case 0:
            SN_I2C0->SLVADDR0 = hwAddressCom;	
            break;
				
        	case 1:
            SN_I2C0->SLVADDR1 = hwAddressCom;	
            break;
				
            case 2:
            SN_I2C0->SLVADDR2 = hwAddressCom;	
            break;
				
            case 3:
            SN_I2C0->SLVADDR3 = hwAddressCom;	
            break;
              
            default:
            break;
        }
}

/*****************************************************************************
* Function		: I2C0_Enable
* Description	: I2C0 enable setting
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void I2C0_Enable(void)
{
	//Enable HCLK for I2C0
	SN_SYS1->AHBCLKEN |= (0x1 << 21);								//Enable clock for I2C0

	SN_I2C0->CTRL_b.I2CEN = I2C_I2CEN_EN;						//I2C enable
}

/*****************************************************************************
* Function		: I2C0_Disable
* Description	: I2C0 disable setting
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void I2C0_Disable(void)
{
	SN_I2C0->CTRL_b.I2CEN = I2C_I2CEN_DIS;					//I2C disable
	
	//Disable HCLK for I2C0
	SN_SYS1->AHBCLKEN &=~ (0x1 << 21);							//Disable clock for I2C0
}

/*****************************************************************************
* Function		: I2C0_Master_Tx
* Description	: Set specified value to specified bits of assigned register
* Input			: *bDataFIFO - Declare TX FIFO Register  
*				  		*bPointerFIFO - Declare TX FIFO Pointer Register
*				 		 	*bCommStop - Declare the Register when get the STOP information
*				  		bSlaveAddress - Set the Slave adress
*				  		wTxNum - Set the Number of sending Data
*				  		wRepeatTX - 0 : No use. 1: Next transfer with a Repated Start condition. 2: Work next transfer.  
*				 			wReTxNum - Send (wReTxNum + 1) Data when wRepeatTX is 1.
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void I2C0_Master_Tx(volatile uint8_t *bDataFIFO, volatile uint8_t *bPointerFIFO, volatile uint8_t *bCommStop, volatile uint8_t bSlaveAddress, volatile uint32_t wTxNum, volatile uint32_t wRepeatTX, volatile uint32_t wReTxNum)
{

		//wReTxNum = 0, Repeat once;	wReTxNum = 1, Repeat twice
		
    //if(((I2C_STAT) & (mskI2C_TIMEOUT_TIMEOUT)) != 0x00) 			//Timeout State
    if(SN_I2C0->STAT & mskI2C_TIMEOUT_TIMEOUT) 				//Timeout State		
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
	    wI2C_TimeoutFlag = 1;								
    }
    else if(SN_I2C0->STAT & mskI2C_LOST_ARB_LOST_ARBITRATION)	//ARB State	
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
			wI2C_ArbitrationFlag = 1;
    }
    else if(((SN_I2C0->STAT) & (mskI2C_STA_MASTER_STA_STO)) == (mskI2C_STOP_DN_STOP))	//Stop Down
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
	   	*bPointerFIFO = 0x00;
	   	wI2C_MasTxCtr = 0x00;
			*bCommStop = 1;
    }
    else if(((SN_I2C0->STAT) & (mskI2C_STA_MASTER_STA_STO)) == (mskI2C_STA_MASTER_STA_STO))	//Start and Stop Down
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
			SN_I2C0->TXDATA = (bSlaveAddress << 0x01);
    }
		else 
		{	
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag

			switch (SN_I2C0->STAT)
			{
				/* START has been transmitted and prepare SLA+W */	
      case (mskI2C_MST_MASTER|mskI2C_START_DN_START):
				SN_I2C0->TXDATA = (bSlaveAddress << 0x01);
			break;
			
				/* SLA+W or Data has been transmitted and ACK has been received */
			case (mskI2C_MST_MASTER|mskI2C_ACK_STAT_RECEIVED_ACK):
        if ((*bPointerFIFO < wTxNum)&&(wI2C_MasTxCtr == 0x00))
        {				
					SN_I2C0->TXDATA = *bDataFIFO;
					*bPointerFIFO = *bPointerFIFO + 1;	
        }
        else if ((*bPointerFIFO == wTxNum)&&(wI2C_MasTxCtr == 0x00))
       	{
  	     	if(wRepeatTX == 0)											//No Repeat
  	     	{
						SN_I2C0->CTRL |= mskI2C_STO_STOP;
  	    	}
					else if(wRepeatTX == 1)									//Repeat Start	
					{
						SN_I2C0->CTRL |= mskI2C_STA_START;	
						wI2C_MasTxCtr++;
					}
					else if(wRepeatTX == 2)									//Repeat Both
					{
						SN_I2C0->CTRL |= (mskI2C_STO_STOP|mskI2C_STA_START);
						wI2C_MasTxCtr++;
					}
					else 
					{
						wI2C_RegisterCheckError |= I2C_ERROR;
						wI2C_TotalError++;
					}
				}
				else if ((*bPointerFIFO < (wTxNum+1+wReTxNum))&&(wI2C_MasTxCtr == 0x01))
				{
					SN_I2C0->TXDATA = *bDataFIFO;
					*bPointerFIFO = *bPointerFIFO + 1;
				}
				else if ((*bPointerFIFO == (wTxNum+1+wReTxNum))&&(wI2C_MasTxCtr == 0x01))
				{
					SN_I2C0->CTRL |= mskI2C_STO_STOP;	
				}
				else 
				{
         	wI2C_RegisterCheckError |= I2C_ERROR;
					wI2C_TotalError++;
				}
			break;
			
			/* SLA+W or Data has been transmitted and NACK has been received */	
			case (mskI2C_MST_MASTER|mskI2C_NACK_STAT_RECEIVED_NACK):
				if ((*bPointerFIFO == wTxNum)&&(wI2C_MasTxCtr == 0x00))
      	{  
  	     	if(wRepeatTX == 0)											//No Repeat
  	     	{
						SN_I2C0->CTRL |= mskI2C_STO_STOP;		
  	     	}
					else if(wRepeatTX == 1)									//Repeat Start	
					{
						SN_I2C0->CTRL |= mskI2C_STA_START;	
						wI2C_MasTxCtr++;
					}
					else if(wRepeatTX == 2)									//Repeat Both
					{
						SN_I2C0->CTRL |= (mskI2C_STO_STOP|mskI2C_STA_START);
						wI2C_MasTxCtr++;
					}
					else 
					{
						wI2C_RegisterCheckError |= I2C_ERROR;
						wI2C_TotalError++;
					}  	
        }
				else if ((*bPointerFIFO == (wTxNum+1+wReTxNum))&&(wI2C_MasTxCtr == 0x01))
				{
					SN_I2C0->CTRL |= mskI2C_STO_STOP;		
				}
				else 
				{
          wI2C_RegisterCheckError |= I2C_ERROR;
					wI2C_TotalError++;
				}
      break;
				
      /*Error State Check*/
      default:
				wI2C_RegisterCheckError |= I2C_ERROR;
	   		wI2C_TotalError++;
      break;
		}
	}
}

/*****************************************************************************
* Function		: I2C0_Master_Rx
* Description	: Set specified value to specified bits of assigned register
* Input			: *bDataFIFO - Declare RX FIFO Register  
*				  		*bPointerFIFO - Declare RX FIFO Pointer Register
*				  		*bCommStop - Declare the Register when get the STOP information
*				  		bSlaveAddress - Set the Slave adress
*				  		wRxNum - Set the Number of getting Data
*				  		wRepeatRX - 0 : No use. 1: Next transfer with a Repated Start condition 2: Work next transfer.  
*				  		wReRxNum - Get (wReRxNum + 1) data when wRepeatRX is 1.
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void I2C0_Master_Rx(volatile uint8_t *bDataFIFO, volatile uint8_t *bPointerFIFO, volatile uint8_t *bCommStop, volatile uint8_t bSlaveAddress, volatile uint32_t wRxNum, volatile uint32_t wRepeatRX, volatile uint32_t wReRxNum)
{
		uint32_t wDeboundNum = 0; 

    //if(((I2C_STAT) & (mskI2C_TIMEOUT_TIMEOUT)) != 0x00) 			//Timeout State
    if(SN_I2C0->STAT & mskI2C_TIMEOUT_TIMEOUT) 				//Timeout State		
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
	    wI2C_TimeoutFlag = 1;
    }
    else if(SN_I2C0->STAT & mskI2C_LOST_ARB_LOST_ARBITRATION)	//ARB State	
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
			wI2C_ArbitrationFlag = 1;
    }
    else if(((SN_I2C0->STAT) & (mskI2C_STA_STA_STO)) == (mskI2C_STOP_DN_STOP))	//Stop Down
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
	   	*bPointerFIFO = 0x00;
	   	wI2C_MasTxCtr = 0x00;
			*bCommStop = 1;
			wI2C_RxControlFlag = 0x00;
			wI2C_ReturnNackFlag = 0x00;
    }
    else if(((SN_I2C0->STAT) & (mskI2C_STA_MASTER_STA_STO)) == (mskI2C_STA_MASTER_STA_STO))	//Start and Stop Down
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
			SN_I2C0->TXDATA = (bSlaveAddress << 0x01) | 0x01;
    }
		else
		{	
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag

			switch (SN_I2C0->STAT)
			{
				/* START has been transmitted and prepare to send address */	
				case (mskI2C_MST_MASTER|mskI2C_START_DN_START):
					SN_I2C0->TXDATA = (bSlaveAddress << 0x01) | 0x01;
				break;

				/* Received an ACK */	
				case (mskI2C_MST_MASTER|mskI2C_ACK_STAT_RECEIVED_ACK):
					if((wRxNum == 1) && (wI2C_ReturnNackFlag == 0))
					{
						SN_I2C0->CTRL |= mskI2C_NACK;					//NACK	
						wI2C_ReturnNackFlag++;
					}
					else if((wReRxNum == 0) && (wI2C_ReturnNackFlag == 1))
					{
						SN_I2C0->CTRL |= mskI2C_NACK;					//NACK	
						wI2C_ReturnNackFlag++;
					}
					else
					{
						SN_I2C0->CTRL |= mskI2C_ACK;					//ACK
					}
				break;

				/* RX with ACK/NACK transfer is down */	
				case (mskI2C_MST_MASTER|mskI2C_RX_DN_HANDSHAKE):
					*bDataFIFO = SN_I2C0->RXDATA; 
					*bPointerFIFO = *bPointerFIFO + 1;

					if(wI2C_ReturnNackFlag == 0x00)
					{
						wDeboundNum = wRxNum-1;
					}
					else if(wI2C_ReturnNackFlag == 0x01)
					{
						wDeboundNum = wRxNum+wReRxNum;
					}

					if(wI2C_ReturnNackFlag == 0x02)
					{
						SN_I2C0->CTRL |= mskI2C_STO_STOP;
					}
					else if((wI2C_ReturnNackFlag == 0x01) && (wI2C_RxControlFlag == 0x00))
					{
					 
						if(wRepeatRX == 0)										//No Repeat
						{
							SN_I2C0->CTRL |= mskI2C_STO_STOP;	
						}
						else if(wRepeatRX == 1)								//Repeat Start	
						{
							SN_I2C0->CTRL |= mskI2C_STA_START;	
						}
						else if(wRepeatRX == 2)								//Repeat Both
						{
							SN_I2C0->CTRL |= (mskI2C_STO_STOP|mskI2C_STA_START);
						}
						else 
						{
							wI2C_RegisterCheckError |= I2C_ERROR;
							wI2C_TotalError++;
						}
						wI2C_RxControlFlag = 1;		
					}
					else if((*bPointerFIFO < (wDeboundNum)))
					{
						//Return ACK
						SN_I2C0->CTRL |= mskI2C_ACK;					//ACK
					}
					else if((*bPointerFIFO >= (wDeboundNum)))
					{
						//Return NACK
						SN_I2C0->CTRL |= mskI2C_NACK;					//NACK
						wI2C_ReturnNackFlag++;
					}
					else
					{
						wI2C_RegisterCheckError |= I2C_ERROR;
						wI2C_TotalError++;
					}					
			break;

			/*Error State Check*/
      default:
				wI2C_RegisterCheckError |= I2C_ERROR;
	   		wI2C_TotalError++;
      break;
		}
	}   
}


/*****************************************************************************
* Function		: I2C0_Slave_Rx
* Description	: Set specified value to specified bits of assigned register
* Input			: *bDataFIFO - Declare RX FIFO Register  
*				  		*bPointerFIFO - Declare RX FIFO Pointer Register
*				  		*bCommStop - Declare the Register when get the STOP information
*				  		wNumForNack - Return NACK when getting the number of data is wNumForNack. 
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void I2C0_Slave_Rx(volatile uint8_t *bDataFIFO, volatile uint8_t *bPointerFIFO, volatile uint8_t *bCommStop, volatile uint32_t wNumForNack)
{

    if(SN_I2C0->STAT & mskI2C_TIMEOUT_TIMEOUT) 					//Timeout State		
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
	    wI2C_TimeoutFlag = 1;
    }
    else if(SN_I2C0->STAT & mskI2C_LOST_ARB_LOST_ARBITRATION)	//ARB State	
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
			wI2C_ArbitrationFlag = 1;
    }
    else if( SN_I2C0->STAT & mskI2C_STOP_DN_STOP)				//Stop Down
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
			*bCommStop = 0x01;
    }
	else
	{	
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag

		switch (SN_I2C0->STAT)
		{
			/* Slave addess hit for Rx */
			case mskI2C_SLV_RX_MATCH_ADDR:
				if(wNumForNack == 0)
				{
					SN_I2C0->CTRL |= mskI2C_ACK;;						//ACK
				}
				else if(wNumForNack == 1)
				{
					SN_I2C0->CTRL  |= mskI2C_NACK;					//NACK	
				}
				else
				{
					SN_I2C0->CTRL  |= mskI2C_ACK;						//ACK
				}	
			break;

			/* DATA has been received and ACK/NACK has been returned */	
      case mskI2C_RX_DN_HANDSHAKE:
				*bDataFIFO = SN_I2C0->RXDATA ;
				*bPointerFIFO = *bPointerFIFO + 1;

				if(wNumForNack == 0)
				{
					SN_I2C0->CTRL  |= mskI2C_ACK;						//ACK
				}
				else if(*bPointerFIFO == (wNumForNack-1))
				{
					SN_I2C0->CTRL  |= mskI2C_NACK;					//NACK	
				}
				else
				{
					SN_I2C0->CTRL  |= mskI2C_ACK;						//ACK
				}
			break;

			/*Error State Check*/
      default:
				wI2C_RegisterCheckError |= I2C_ERROR;
	   		wI2C_TotalError++;
     break;
		}
	}
}

/*****************************************************************************
* Function		: I2C0_Slave_Tx
* Description	: Set specified value to specified bits of assigned register
* Input			: *bDataFIFO - Declare TX FIFO Register  
*				  		*bPointerFIFO - Declare TX FIFO Pointer Register
*				  		*bCommStop - Declare the Register when get the STOP information
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void I2C0_Slave_Tx(volatile uint8_t *bDataFIFO, volatile uint8_t *bPointerFIFO, volatile uint8_t *bCommStop)
{
    if(SN_I2C0->STAT & mskI2C_TIMEOUT_TIMEOUT) 					//Timeout State		
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
	    wI2C_TimeoutFlag = 1;
    }
    else if(SN_I2C0->STAT & mskI2C_LOST_ARB_LOST_ARBITRATION)	//ARB State	
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
			wI2C_ArbitrationFlag = 1;
    }
    else if( SN_I2C0->STAT & mskI2C_STOP_DN_STOP)				//Stop Down
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
			*bCommStop = 0x01;
    }
	else
	{	
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag

		switch (SN_I2C0->STAT)
		{
			/* Slave addess hit for Tx */
      case mskI2C_SLV_TX_MATCH_ADDR:
				SN_I2C0->TXDATA  = *bDataFIFO;
				*bPointerFIFO = *bPointerFIFO + 1;	
			break;

			/* Received ACK */	
      case mskI2C_ACK_STAT_RECEIVED_ACK:
				SN_I2C0->TXDATA = *bDataFIFO;
				*bPointerFIFO = *bPointerFIFO + 1;
			break;

			/* Received NACK */	
      case mskI2C_NACK_STAT_RECEIVED_NACK:
				SN_I2C0->CTRL  |= mskI2C_ACK;							//For release SCL and SDA
			break;

			/*Error State Check*/
       default:
				wI2C_RegisterCheckError |= I2C_ERROR;
	   		wI2C_TotalError++;
       break;
		}
	}
}

/*****************************************************************************
* Function		: I2C0_Mointer_Mode
* Description	: Set specified value to specified bits of assigned register
* Input			: *bDataFIFO - Declare RX FIFO Register  
*				  		*bPointerFIFO - Declare RX FIFO Pointer Register
*				  		*bCommStop - Declare the Register when get the STOP information
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void I2C0_Mointer_Mode(volatile uint8_t *bDataFIFO, volatile uint8_t *bPointerFIFO, volatile uint8_t *bCommStop)
{
    if(SN_I2C0->STAT & mskI2C_TIMEOUT_TIMEOUT) 					//Timeout State		
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
	    wI2C_TimeoutFlag = 1;	
    }
    else if(SN_I2C0->STAT & mskI2C_LOST_ARB_LOST_ARBITRATION)	//ARB State	
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
			wI2C_ArbitrationFlag = 1;
    }
    else if( SN_I2C0->STAT & mskI2C_STOP_DN_STOP)				//Stop Down
    {
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag
			*bCommStop = 0x01;
    }
	else
	{	
	    SN_I2C0->STAT |= mskI2C_I2CIF_INTERRUPT;					//Clear I2C flag

		switch (SN_I2C0->STAT)
		{
			/* Slave addess hit for Rx */
      case mskI2C_SLV_RX_MATCH_ADDR:
				bI2C0_MointerAddress = SN_I2C0->RXDATA;
				bI2C0_MointerAddress = bI2C0_MointerAddress >> 1;
				SN_I2C0->CTRL  |= mskI2C_ACK;							//ACK

			break;

			/* Slave addess hit for Tx */
      case mskI2C_SLV_TX_MATCH_ADDR:
				bI2C0_MointerAddress = SN_I2C0->RXDATA;
				bI2C0_MointerAddress = bI2C0_MointerAddress >> 1;
				SN_I2C0->CTRL  |= mskI2C_ACK;							//ACK

			break;
			/* DATA has been received*/	
      case I2C_RX_DN_HANDSHAKE:
				*bDataFIFO = SN_I2C0->RXDATA;
				*bPointerFIFO = *bPointerFIFO + 1;
				SN_I2C0->CTRL  |= mskI2C_ACK;							//ACK

			break;

			/*Error State Check*/
      default:
				wI2C_RegisterCheckError |= I2C_ERROR;
	   		wI2C_TotalError++;
      break;
		}
	}
}
