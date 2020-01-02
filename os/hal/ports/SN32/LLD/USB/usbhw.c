/*----------------------------------------------------------------------------
 *      U S B  -  K e r n e l
 *----------------------------------------------------------------------------
 * Name:    usbhw.c
 * Purpose: USB Custom User Module
 * Version: V1.01
 * Date:		2017/07
 *------------------------------------------------------------------------------*/
#include	<SN32F240B.h>
#include	"SN32F200_Def.h"
// #include	"..\type.h"
// #include	"..\Utility\Utility.h"

#include	"usbram.h"
#include	"usbhw.h"
#include	"usbuser.h"
#include	"usbdesc.h"

/*****************************************************************************
* Description	:Setting USB for different Power domain
*****************************************************************************/
#define System_Power_Supply 			System_Work_at_5_0V					// only 3.3V, 5V
	#define System_Work_at_3_3V				0
	#define	System_Work_at_5_0V				1


/*****************************************************************************
* Function		: USB_Init
* Description	: 1. setting IDLE_TIME, REPORT_PROTOCOL, S_USB_EP0setupdata.wUSB_Status
*								2. set EP1~EP6 FIFO RAM address.
*								3. save	EP1~EP6 FIFO RAM point address.
*								4. save EP1~EP6 Package Size.
*								5. Enable USB function and setting EP1~EP6 Direction.
*								6. NEVER REMOVE !! USB D+/D- Dischage
*								7. Enable USB PHY and USB interrupt.
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_Init	(void)
{
	volatile uint32_t	*pRam;
	uint32_t 	wTmp;
	USB_StandardVar_Init();
	//USB_HidVar_Init();

	/* Initialize clock and Enable USB PHY. */
	SystemInit();
	SystemCoreClockUpdate();
	SN_SYS1->AHBCLKEN |= mskUSBCLK_EN;		// Enable USBCLKEN

	/* Initialize USB EP1~EP4 RAM Start address base on 64-bytes. */
	USB_EPnBufferOffset(1,EP1_BUFFER_OFFSET_VALUE);
	USB_EPnBufferOffset(2,EP2_BUFFER_OFFSET_VALUE);
	USB_EPnBufferOffset(3,EP3_BUFFER_OFFSET_VALUE);
	USB_EPnBufferOffset(4,EP4_BUFFER_OFFSET_VALUE);

	/* Copy EP1~EP4 RAM Start address to array(wUSB_EPnOffset).*/
	pRam = &wUSB_EPnOffset[0];
	*(pRam+0) =  EP1_BUFFER_OFFSET_VALUE;
	*(pRam+1) =  EP2_BUFFER_OFFSET_VALUE;
	*(pRam+2) =  EP3_BUFFER_OFFSET_VALUE;
	*(pRam+3) =  EP4_BUFFER_OFFSET_VALUE;

	/* Initialize EP0~EP4 package size to array(wUSB_EPnPacketsize).*/
	pRam = &wUSB_EPnPacketsize[0];
	*(pRam+0) = USB_EP0_PACKET_SIZE;
	*(pRam+1) = USB_EP1_PACKET_SIZE;
	*(pRam+2) = USB_EP2_PACKET_SIZE;
	*(pRam+3) = USB_EP3_PACKET_SIZE;
	*(pRam+4) = USB_EP4_PACKET_SIZE;

	/* Enable the USB Interrupt */
	SN_USB->INTEN = (mskBUS_IE|mskUSB_IE|mskEPnACK_EN|mskBUSWK_IE);
	SN_USB->INTEN |= mskEP1_NAK_EN;
	SN_USB->INTEN |= mskEP2_NAK_EN;
	SN_USB->INTEN |= mskEP3_NAK_EN;
	SN_USB->INTEN |= mskEP4_NAK_EN;
	SN_USB->INTEN |= mskUSB_SOF_IE;

	NVIC_ClearPendingIRQ(USB_IRQn);
	NVIC_EnableIRQ(USB_IRQn);

	/* BUS_DRVEN = 0, BUS_DP = 1, BUS_DN = 0 */
	SN_USB->SGCTL = mskBUS_J_STATE;

	#if (System_Power_Supply == System_Work_at_5_0V)
			//----------------------------------//
			//Setting USB for System work at 5V	//
			//----------------------------------//
			//VREG33_EN = 1, PHY_EN = 1, DPPU_EN = 1, SIE_EN = 1, ESD_EN = 1
			wTmp = (mskVREG33_EN|mskPHY_EN|mskDPPU_EN|mskSIE_EN|mskESD_EN);

	#elif (System_Power_Supply == System_Work_at_3_3V)
			//------------------------------------//
			//Setting USB for System work at 3.3V	//
			//------------------------------------//
			//VREG33_EN = 0, PHY_EN = 1, DPPU_EN = 1, SIE_EN = 1, ESD_EN = 1
			wTmp = (mskVREG33_DIS|mskPHY_EN|mskDPPU_EN|mskSIE_EN|mskESD_EN);
	#endif

	//** Delay for the connection between Device and Host
	// UT_MAIN_DelayNms(50);
    // chThdSleepMilliseconds(50);
	//** Setting USB Configuration Register
 	SN_USB->CFG = wTmp;

	SN_USB->PHYPRM = 0x80000000;			// PHY parameter
	SN_USB->PHYPRM2 = 0x00004004;			// PHY parameter 2
}


/*****************************************************************************
* Function		: P0_IRQHandler
* Description	: P0_IRQHandler
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
#if (REMOTE_WAKEUP_IO_P0)
void P0_IRQHandler (void)
{
	NVIC_ClearPendingIRQ(P0_IRQn);
	SN_GPIO0->IC = REMOTE_WAKEUP_IO_P0_BIT;	//** Clear wakeup I/O interrupt
	sUSB_EumeData.wUSB_Status |= mskREMOTE_WAKEUP_ACT;
	NVIC_DisableIRQ(P0_IRQn);
}
#endif


/*****************************************************************************
* Function		: P1_IRQHandler
* Description	: P1_IRQHandler
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
#if (REMOTE_WAKEUP_IO_P1)
void P1_IRQHandler (void)
{
	NVIC_ClearPendingIRQ(P1_IRQn);
	SN_GPIO1->IC = REMOTE_WAKEUP_IO_P1_BIT;	//** Clear wakeup I/O interrupt
	sUSB_EumeData.wUSB_Status |= mskREMOTE_WAKEUP_ACT;
	NVIC_DisableIRQ(P1_IRQn);
}
#endif


/*****************************************************************************
* Function		: P2_IRQHandler
* Description	: P2_IRQHandler
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
#if (REMOTE_WAKEUP_IO_P2)
void P2_IRQHandler (void)
{
	NVIC_ClearPendingIRQ(P2_IRQn);
	SN_GPIO2->IC = REMOTE_WAKEUP_IO_P2_BIT;	//** Clear wakeup I/O interrupt
	sUSB_EumeData.wUSB_Status |= mskREMOTE_WAKEUP_ACT;
	NVIC_DisableIRQ(P2_IRQn);
}
#endif


/*****************************************************************************
* Function		: P3_IRQHandler
* Description	: P3_IRQHandler
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
#if (REMOTE_WAKEUP_IO_P3)
void P3_IRQHandler (void)
{
	NVIC_ClearPendingIRQ(P3_IRQn);
	SN_GPIO3->IC = REMOTE_WAKEUP_IO_P3_BIT;	//** Clear wakeup I/O interrupt
	sUSB_EumeData.wUSB_Status |= mskREMOTE_WAKEUP_ACT;
	NVIC_DisableIRQ(P3_IRQn);
}
#endif


/*****************************************************************************
* Function		: Remote_Wakeup_Setting
* Description	: Setting Remote Wakeup IO
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void Remote_Wakeup_Setting (void)
{
	#if	(REMOTE_WAKEUP_IO_P0 == ENABLE)
	SN_GPIO0->CFG = 0;  //** P0 Input mode Pull up
	SN_GPIO0->MODE &= (~REMOTE_WAKEUP_IO_P0_BIT);
	UT_MAIN_DelayNx10us(10);
	//** set Wakeup I/O	edge falling trigger
	SN_GPIO0->IS = 0x00;
	SN_GPIO0->IEV = REMOTE_WAKEUP_IO_P0_BIT;
	SN_GPIO0->IC =0xFFFFFFFF;
	//** Enable wakeup I/O interrupt
	SN_GPIO0->IE = REMOTE_WAKEUP_IO_P0_BIT;
	NVIC_ClearPendingIRQ(P0_IRQn);
	NVIC_EnableIRQ(P0_IRQn);
	#endif

	#if	(REMOTE_WAKEUP_IO_P1 == ENABLE)
	SN_GPIO1->CFG = 0;  //** P1 Input mode Pull up
	SN_GPIO1->MODE &= (~REMOTE_WAKEUP_IO_P1_BIT);
	// UT_MAIN_DelayNx10us(10);
    // chThdSleepMilliseconds(10);
	//** set Wakeup I/O	edge falling trigger
	SN_GPIO1->IS = 0x00;
	SN_GPIO1->IEV = REMOTE_WAKEUP_IO_P1_BIT;
	SN_GPIO1->IC =0xFFFFFFFF;
	//** Enable wakeup I/O interrupt
	SN_GPIO1->IE = REMOTE_WAKEUP_IO_P1_BIT;
	NVIC_ClearPendingIRQ(P1_IRQn);
	NVIC_EnableIRQ(P1_IRQn);
	#endif

	#if	(REMOTE_WAKEUP_IO_P2 == ENABLE)
	SN_GPIO2->CFG = 0;  //** P2 Input mode Pull up
	SN_GPIO2->MODE &= (~REMOTE_WAKEUP_IO_P2_BIT);
	UT_MAIN_DelayNx10us(10);
	//** set Wakeup I/O	edge falling trigger
	SN_GPIO2->IS = 0x00;
	SN_GPIO2->IEV = REMOTE_WAKEUP_IO_P2_BIT;
	SN_GPIO2->IC =0xFFFFFFFF;
	//** Enable wakeup I/O interrupt
	SN_GPIO2->IE = REMOTE_WAKEUP_IO_P2_BIT;
	NVIC_ClearPendingIRQ(P2_IRQn);
	NVIC_EnableIRQ(P2_IRQn);
	#endif

	#if	(REMOTE_WAKEUP_IO_P3 == ENABLE)
	SN_GPIO3->CFG = 0;  //** P3 Input mode Pull up
	SN_GPIO3->MODE &= (~REMOTE_WAKEUP_IO_P3_BIT);
	UT_MAIN_DelayNx10us(10);
	//** set Wakeup I/O	edge falling trigger
	SN_GPIO3->IS = 0x00;
	SN_GPIO3->IEV = REMOTE_WAKEUP_IO_P3_BIT;
	SN_GPIO3->IC =0xFFFFFFFF;
	//** Enable wakeup I/O interrupt
	SN_GPIO3->IE = REMOTE_WAKEUP_IO_P3_BIT;
	NVIC_ClearPendingIRQ(P3_IRQn);
	NVIC_EnableIRQ(P3_IRQn);
	#endif
}


/*****************************************************************************
* Function		: USB_IRQHandler
* Description	: USB Interrupt USB_BUS, USB SOF, USB_IE
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USB_IRQHandler (void)
{
	uint32_t iwIntFlag;

	//** Get Interrupt Status and clear immediately.
	iwIntFlag = SN_USB->INSTS;
	SN_USB->INSTSC = 0xFEFBFFFF;	//** Don't clear PRESETUP & ERR_SETUP flag

	if(iwIntFlag == 0)
	{
		//@20160902 add for EMC protection
		USB_ReturntoNormal();
		return;
	}

	/////////////////////////////////////////////////
	/* Device Status Interrupt (BusReset, Suspend) */
	/////////////////////////////////////////////////
	if (iwIntFlag & (mskBUS_RESET | mskBUS_SUSPEND | mskBUS_RESUME))
	{
		if (iwIntFlag & mskBUS_RESET)
		{
			/* BusReset */
			USB_ReturntoNormal();
			USB_ResetEvent();
		}
		else if (iwIntFlag & mskBUS_SUSPEND)
		{
			/* Suspend */
			USB_SuspendEvent();
		}
		else if(iwIntFlag & mskBUS_RESUME)
		{
			/* Resume */
			USB_ReturntoNormal();
			USB_ResumeEvent();
		}
	}
	/////////////////////////////////////////////////
	/* Device Status Interrupt (SETUP, IN, OUT) 	 */
	/////////////////////////////////////////////////
	else if (iwIntFlag & (mskEP0_SETUP|mskEP0_IN|mskEP0_OUT|mskEP0_IN_STALL|mskEP0_OUT_STALL))
	{
		if (iwIntFlag & mskEP0_SETUP)
		{
			/* SETUP */
			USB_EP0SetupEvent();
		}
		else if (iwIntFlag & mskEP0_IN)
		{
			/* IN */
			USB_EP0InEvent();
		}
		else if (iwIntFlag & mskEP0_OUT)
		{
			/* OUT */
			USB_EP0OutEvent();
		}
		else if (iwIntFlag & (mskEP0_IN_STALL|mskEP0_OUT_STALL))
		{
			/* EP0_IN_OUT_STALL */
			SN_USB->INSTSC = (mskEP0_IN_STALL|mskEP0_OUT_STALL);
			USB_EPnStall(USB_EP0);
		}
	}
	/////////////////////////////////////////////////
	/* Device Status Interrupt (EPnACK) 					 */
	/////////////////////////////////////////////////
	else if (iwIntFlag & (mskEP4_ACK|mskEP3_ACK|mskEP2_ACK|mskEP1_ACK))
	{
		if (iwIntFlag & mskEP1_ACK)
		{
			/* EP1 ACK */
			USB_EP1AckEvent();
		}
		if (iwIntFlag & mskEP2_ACK)
		{
			/* EP2 ACK */
			USB_EP2AckEvent();
		}
		if (iwIntFlag & mskEP3_ACK)
		{
			/* EP3 ACK */
			USB_EP3AckEvent();
		}
		if (iwIntFlag & mskEP4_ACK)
		{
			/* EP4 ACK */
			USB_EP4AckEvent();
		}
	}

	/////////////////////////////////////////////////
	/* Device Status Interrupt (EPnNAK) 					 */
	/////////////////////////////////////////////////
	else if (iwIntFlag & (mskEP4_NAK|mskEP3_NAK|mskEP2_NAK|mskEP1_NAK))
	{
		if (iwIntFlag & mskEP1_NAK)
		{
			/* EP1 NAK */
			USB_EP1NakEvent();
		}
		if (iwIntFlag & mskEP2_NAK)
		{
			/* EP2 NAK */
			USB_EP2NakEvent();
		}
		if (iwIntFlag & mskEP3_NAK)
		{
			/* EP3 NAK */
			USB_EP3NakEvent();
		}
		if (iwIntFlag & mskEP4_NAK)
		{
			/* EP4 NAK */
			USB_EP4NakEvent();
		}
	}

	/////////////////////////////////////////////////
	/* Device Status Interrupt (SOF) 							 */
	/////////////////////////////////////////////////
	if ((iwIntFlag & mskUSB_SOF) && (SN_USB->INTEN & mskUSB_SOF_IE))
	{
		/* SOF */
		USB_SOFEvent();
	}
}


// /*****************************************************************************
// * Function		: USB_Suspend
// * Description	: USB Suspend state SYS_CLK is runing slow mode.
// * Input				: None
// * Output			: None
// * Return			: None
// * Note				: None
// *****************************************************************************/
// void USB_Suspend (void)
// {
// 	uint32_t	i;

// 	#define SuspendMode Sleep
// 	#define Slow	1
// 	#define Sleep	2

// 	#if (SuspendMode == Slow)
// 		#if (REMOTE_WAKEUP_IO_P0 == ENABLE)
// 		uint32_t	wWakeupStatus0;
// 		#endif
// 		#if (REMOTE_WAKEUP_IO_P1 == ENABLE)
// 		uint32_t	wWakeupStatus1;
// 		#endif
// 		#if (REMOTE_WAKEUP_IO_P2 == ENABLE)
// 		uint32_t	wWakeupStatus2;
// 		#endif
// 		#if (REMOTE_WAKEUP_IO_P3 == ENABLE)
// 		uint32_t	wWakeupStatus3;
// 		#endif
// 	#endif

// 	//** Clear BusSuspend
// 	sUSB_EumeData.wUSB_Status &= ~mskBUSSUSPEND;

// 	if(bNDT_Flag == 1)				// Check NDT status
// 	{
// 		return;
// 	}

// 	for(i=0; i < 620000; i++ )
// 	{
// 		SN_WDT->FEED = 0x5AFA55AA;
// 		if(!(SN_USB->INSTS & mskBUS_SUSPEND))				// double check Suspend flag
// 		{
// 			return;
// 		}
// 	}

// 	//** double check Suspend flag for EMC protect
// 	if(!(SN_USB->INSTS & mskBUS_SUSPEND))
// 	{
// 		return;
// 	}

// 	//** Disable ESD_EN & PHY_EN
// 	__USB_PHY_DISABLE;

// 	//** If system support remote wakeup, setting Remote wakeup GPIOs
// 	if (sUSB_EumeData.wUSB_Status & mskREMOTE_WAKEUP)
// 	{
// 		//** Sleep mode setting
// 		#if (SuspendMode == Sleep)
// 		Remote_Wakeup_Setting();
// 		//** Slow mode setting
// 		#elif (SuspendMode == Slow)
// 			#if (REMOTE_WAKEUP_IO_P0 == ENABLE)
// 			SN_GPIO0->CFG = 0;  	//** P0 Input mode Pull up
// 			SN_GPIO0->MODE &= (~REMOTE_WAKEUP_IO_P0_BIT);
// 			UT_MAIN_DelayNx10us(10);
// 			wWakeupStatus0 = SN_GPIO0->DATA & REMOTE_WAKEUP_IO_P0_BIT;	//** Record P0 wakeup pin
// 			#endif
// 			#if (REMOTE_WAKEUP_IO_P1 == ENABLE)
// 			SN_GPIO1->CFG = 0;  	//** P1 Input mode Pull up
// 			SN_GPIO1->MODE &= (~REMOTE_WAKEUP_IO_P1_BIT);
// 			UT_MAIN_DelayNx10us(10);
// 			wWakeupStatus1 = SN_GPIO1->DATA & REMOTE_WAKEUP_IO_P1_BIT;	//** Record P1 wakeup pin
// 			#endif
// 			#if (REMOTE_WAKEUP_IO_P2 == ENABLE)
// 			SN_GPIO2->CFG = 0;  	//** P2 Input mode Pull up
// 			SN_GPIO2->MODE &= (~REMOTE_WAKEUP_IO_P2_BIT);
// 			UT_MAIN_DelayNx10us(10);
// 			wWakeupStatus2 = SN_GPIO2->DATA & REMOTE_WAKEUP_IO_P2_BIT;	//** Record P2 wakeup pin
// 			#endif
// 			#if (REMOTE_WAKEUP_IO_P3 == ENABLE)
// 			SN_GPIO3->CFG = 0;  	//** P3 Input mode Pull up
// 			SN_GPIO3->MODE &= (~REMOTE_WAKEUP_IO_P3_BIT);
// 			UT_MAIN_DelayNx10us(10);
// 			wWakeupStatus3 = SN_GPIO3->DATA & REMOTE_WAKEUP_IO_P3_BIT;	//** Record P3 wakeup pin
// 			#endif
// 		#endif
// 	}

// 	//** Delay for waitting IO stable, then go into sleep mode
// 	// UT_MAIN_DelayNx10us(10);
//     // chThdSleepMilliseconds(10);

// 	//** System switch into Slow mode(ILRC)
// 	USB_SwitchtoSlow();

// 	// double check Suspend flag for EMC protect
// 	if(!(SN_USB->INSTS & mskBUS_SUSPEND))
// 	{
// 		USB_ReturntoNormal();
// 		return;
// 	}

// 	#if (SuspendMode == Sleep)
// 	//** Into Sleep mode, for saving power consumption in suspend (<500uA)
// 	SN_PMU->CTRL = 0x04;
// 	__WFI();

// 	//** system wakeup from sleep mode, system clock(ILRC) switch into IHRC
// 	USB_ReturntoNormal();
// 	if ((sUSB_EumeData.wUSB_Status & (mskREMOTE_WAKEUP | mskREMOTE_WAKEUP_ACT)) == (mskREMOTE_WAKEUP | mskREMOTE_WAKEUP_ACT) )
// 	{
// 		sUSB_EumeData.wUSB_Status &= ~mskREMOTE_WAKEUP_ACT;
// 		if (sUSB_EumeData.wUSB_SetConfiguration == USB_CONFIG_VALUE)
// 		{
// 			USB_RemoteWakeUp();
// 			return;
// 		}
// 	}
// 	#elif (SuspendMode == Slow)
// 	//** ILRC mode
// 	while (SN_USB->INSTS & mskBUS_SUSPEND)
// 	{
// 		if (sUSB_EumeData.wUSB_Status & mskREMOTE_WAKEUP)
// 		{
// 			#if (REMOTE_WAKEUP_IO_P0 == ENABLE)
// 			if ((SN_GPIO0->DATA & REMOTE_WAKEUP_IO_P0_BIT) != wWakeupStatus0)
// 			{
// 				if (sUSB_EumeData.wUSB_SetConfiguration == USB_CONFIG_VALUE)
// 				{
// 					USB_ReturntoNormal();
// 					USB_RemoteWakeUp();
// 					return;
// 				}
// 			}
// 			#endif
// 			#if (REMOTE_WAKEUP_IO_P1 == ENABLE)
// 			if ((SN_GPIO1->DATA & REMOTE_WAKEUP_IO_P1_BIT) != wWakeupStatus1)
// 			{
// 				if (sUSB_EumeData.wUSB_SetConfiguration == USB_CONFIG_VALUE)
// 				{
// 					USB_ReturntoNormal();
// 					USB_RemoteWakeUp();
// 					return;
// 				}
// 			}
// 			#endif
// 			#if (REMOTE_WAKEUP_IO_P2 == ENABLE)
// 			if ((SN_GPIO2->DATA & REMOTE_WAKEUP_IO_P2_BIT) != wWakeupStatus2)
// 			{
// 				if (sUSB_EumeData.wUSB_SetConfiguration == USB_CONFIG_VALUE)
// 				{
// 					USB_ReturntoNormal();
// 					USB_RemoteWakeUp();
// 					return;
// 				}
// 			}
// 			#endif
// 			#if (REMOTE_WAKEUP_IO_P3 == ENABLE)
// 			if ((SN_GPIO3->DATA & REMOTE_WAKEUP_IO_P3_BIT) != wWakeupStatus3)
// 			{
// 				if (sUSB_EumeData.wUSB_SetConfiguration == USB_CONFIG_VALUE)
// 				{
// 					USB_ReturntoNormal();
// 					USB_RemoteWakeUp();
// 					return;
// 				}
// 			}
// 			#endif
// 		}
// 	}
// 	#endif
// 	USB_ReturntoNormal();
// }


/*****************************************************************************
* Function		: USB_EP1AckEvent
* Description	: USB Clear EP1 ACK interrupt status
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EP1AckEvent (void)
{
	__USB_CLRINSTS(mskEP1_ACK);
}


/*****************************************************************************
* Function		: USB_EP2AckEvent
* Description	: USB Clear EP2 ACK interrupt status
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EP2AckEvent (void)
{
	__USB_CLRINSTS(mskEP2_ACK);
}


/*****************************************************************************
* Function		: USB_EP3AckEvent
* Description	: USB Clear EP3 ACK interrupt status
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EP3AckEvent (void)
{
	__USB_CLRINSTS(mskEP3_ACK);
}


/*****************************************************************************
* Function		: USB_EP4AckEvent
* Description	: USB Clear EP4 ACK interrupt status
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EP4AckEvent (void)
{
	__USB_CLRINSTS(mskEP4_ACK);
}


/*****************************************************************************
* Function		: USB_EP1NakEvent
* Description	: USB Clear EP1 NAK interrupt status
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EP1NakEvent (void)
{
	__USB_CLRINSTS(mskEP1_NAK);
}


/*****************************************************************************
* Function		: USB_EP2NakEvent
* Description	: USB Clear EP2 NAK interrupt status
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EP2NakEvent (void)
{
	__USB_CLRINSTS(mskEP2_NAK);
}


/*****************************************************************************
* Function		: USB_EP3NakEvent
* Description	: USB Clear EP3 NAK interrupt status
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EP3NakEvent (void)
{
	__USB_CLRINSTS(mskEP3_NAK);
}


/*****************************************************************************
* Function		: USB_EP4NakEvent
* Description	: USB Clear EP4 NAK interrupt status
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EP4NakEvent (void)
{
	__USB_CLRINSTS(mskEP4_NAK);
}


/*****************************************************************************
* Function		: USB_ClrEPnToggle
* Description	: USB Clear EP1~EP6 toggle bit to DATA0
								write 1: toggle bit Auto. write0:clear EPn toggle bit to DATA0
* Input				: hwEPNum ->EP1~EP6
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_ClrEPnToggle	(uint32_t	hwEPNum)
{
	SN_USB->EPTOGGLE &= ~(0x1<<hwEPNum);
}


/*****************************************************************************
* Function		: USB_EPnDisable
* Description	: Disable EP1~EP4
* Input				: wEPNum
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EPnDisable (uint32_t	wEPNum)
{
	volatile uint32_t	*pEPn_ptr;
	if(wEPNum > USB_EP4)
		return;
	pEPn_ptr = &SN_USB->EP0CTL + wEPNum;
	*pEPn_ptr = 0;								//** SET DISABLE. No handshake IN/OUT token.
}


/*****************************************************************************
* Function		: USB_EPnNak
* Description	: SET EP1~EP4 is NAK. For IN will handshake NAK to IN token.
*																		For OUT will handshake NAK to OUT token.
* Input				: wEPNum
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EPnNak (uint32_t	wEPNum)
{
	volatile	uint32_t	*pEPn_ptr;
	if(wEPNum > USB_EP4)
		return;
	pEPn_ptr = &SN_USB->EP0CTL + wEPNum;
	*pEPn_ptr = mskEPn_ENDP_EN;			//** SET NAK
}


/*****************************************************************************
* Function		: USB_EPnAck
* Description	: SET EP1~EP4 is ACK. For IN will handshake bBytent to IN token.
*																		For OUT will handshake ACK to OUT token.
* Input				: wEPNum:EP1~EP4.
*								bBytecnt: Byte Number of Handshake.
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EPnAck (uint32_t	wEPNum, uint8_t	bBytecnt)
{
	volatile	uint32_t	*pEPn_ptr;
	if (wEPNum > USB_EP4)
		return;
	pEPn_ptr = &SN_USB->EP0CTL + wEPNum;
	*pEPn_ptr = (mskEPn_ENDP_EN|mskEPn_ENDP_STATE_ACK|bBytecnt);
}


/*****************************************************************************
* Function		: USB_EPnAck
* Description	: SET EP1~EP4 is STALL. For IN will handshake STALL to IN token.
*																			For OUT will handshake STALL to OUT token.
* Input				: wEPNum:EP1~EP4.
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EPnStall (uint32_t	wEPNum)
{
	volatile uint32_t	*pEPn_ptr;
	if(wEPNum > USB_EP4)				//** wEPNum != EP0~EP4
		return;
	pEPn_ptr = &SN_USB->EP0CTL + wEPNum;
	if (wEPNum == USB_EP0)
	{
			if(SN_USB->INSTS & mskEP0_PRESETUP)
				return;
	}
	*pEPn_ptr = (mskEPn_ENDP_EN|mskEPn_ENDP_STATE_STALL);
}


/*****************************************************************************
* Function		: USB_RemoteWakeUp
* Description	: USB Remote wakeup: USB D+/D- siganl is J-K state.
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_RemoteWakeUp()
{
	__USB_JSTATE_DRIVER;			//** J state ;Full speed D+ = 1, D- = 0
	USB_DelayJstate();
	__USB_KSTATE_DRIVER;			//** K state ;Full speed D+ = 0, D- = 1
	USB_DelayKstate();
	SN_USB->SGCTL &= ~mskBUS_DRVEN;
}


/*****************************************************************************
* Function		: USB_DelayJstate
* Description	: For J state delay. about 180us
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	USB_DelayJstate()
{
	uint32_t	i = 1500>>SN_SYS0->AHBCP;
	while(i--);
}


/*****************************************************************************
* Function		: USB_DelayKstate
* Description	: For K state delay. about 9~10ms
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	USB_DelayKstate()
{
	uint32_t	i = 80000>>SN_SYS0->AHBCP;		//** 10ms @ 12~48MHz
	while(i--);															//** require delay 1ms ~ 15ms
}


/*****************************************************************************
* Function		: USB_EPnBufferOffset
* Description	: SET EP1~EP4 RAM point address
* Input				: wEPNum: EP1~EP4
*								wAddr of device address
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	USB_EPnBufferOffset(uint32_t	wEPNum, uint32_t	wAddr)
{
	volatile	uint32_t	*pEPn_ptr;
	if ((wEPNum > USB_EP0) && (wEPNum <= USB_EP4))	//** wEPNum = EP1 ~ EP4
	{
		pEPn_ptr = &SN_USB->EP1BUFOS; 		//** Assign point to EP1 RAM address
		*(pEPn_ptr+wEPNum-1) = wAddr;			//** SET point to EPn RAM address
	}
}


/*****************************************************************************
* Function		: USB_EPnReadByteData
* Description	: EP1~EP4 Read RAM data by Bytes
* Input				: wEPNum: EP1~EP4
*								wByteIndex: Read Bytes count 0~63
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
uint32_t	USB_EPnReadByteData(uint32_t	wEPNum, uint32_t	wByteIndex)
{
	uint32_t	i, wVal;
	if (wByteIndex < 64)				//** 0~63 Byte index
	{
		i = wUSB_EPnOffset[wEPNum-1] + (wByteIndex>>2);
		fnUSBMAIN_ReadFIFO(i);
		wVal = ((wUSBMAIN_ReadDataBuf)>>((wByteIndex&0x3)<<3))&0xFF;
		return(wVal);
	}
	return 0;
}


/*****************************************************************************
* Function		: USB_EPnReadWordData
* Description	: EP1~EP4 Read RAM data by Words
* Input				: wEPNum: EP1~EP4
*								wWordIndex: Read Words count 0~15
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
uint32_t	USB_EPnReadWordData(uint32_t	wEPNum, uint32_t	wWordIndex)
{
	uint32_t	i, wVal;
	if (wWordIndex < 16)				//** 0~15 Word index
	{
		i = wUSB_EPnOffset[wEPNum-1] + (wWordIndex<<2);
		fnUSBMAIN_ReadFIFO(i);
		wVal = wUSBMAIN_ReadDataBuf;
		return (wVal);
	}
	return 0;
}


/*****************************************************************************
* Function		: USB_EPnWriteByteData
* Description	: EP1~EP4 Write RAM data by Bytes
* Input				: wEPNum: EP1~EP4
*								wByteindex: Write Bytes count 0~63
*								wBytedata:  Write Data by Bytes
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	USB_EPnWriteByteData(uint32_t	wEPNum, uint32_t wByteIndex, uint32_t	wBytedata)
{
	uint32_t	i, wVal;
	if (wByteIndex < 64)				//** 0~63 Byte index
	{
		i = wUSB_EPnOffset[wEPNum-1] + (wByteIndex>>2);
		//** Read from USB FIFO
		fnUSBMAIN_ReadFIFO(i);
		//** copy FIFO word data
		wVal = wUSBMAIN_ReadDataBuf;
		//** clear the byte data and rewrite
		wVal &= ~(0xFF<<((wByteIndex&0x3)<<3));			//** (wByteindex%4)*8
		wVal |= (wBytedata<<((wByteIndex&0x3)<<3));
		//** write new data into USB FIFO
		fnUSBMAIN_WriteFIFO(i, wVal);
	}
}


/*****************************************************************************
* Function		: USB_EPnWriteWordData
* Description	: EP1~EP4 Write RAM data by Words
* Input				: wEPNum: EP1~EP4
*								wByteindex: Write Words count 0~15
*								wBytedata:  Write Data by Words
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	USB_EPnWriteWordData(uint32_t	wEPNum, uint32_t	wWordIndex, uint32_t	wWorddata)
{
	uint32_t	i;
	if (wWordIndex < 16)				//** 0~15 Word index
	{
		i = wUSB_EPnOffset[wEPNum-1] + (wWordIndex<<2);
		fnUSBMAIN_WriteFIFO(i, wWorddata);
	}
}


/*****************************************************************************
* Function		: fnUSBINT_ReadFIFO
* Description	:
* Input				: FIFO_Address
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	fnUSBINT_ReadFIFO(uint32_t FIFO_Address)
{
		SN_USB->RWADDR = FIFO_Address;
		SN_USB->RWSTATUS = 0x02;
		while (SN_USB->RWSTATUS &0x02);
		wUSBINT_ReadDataBuf = SN_USB->RWDATA;
}


/*****************************************************************************
* Function		: fnUSBINT_WriteFIFO
* Description	:
* Input				: FIFO_Address,  FIFO_WriteData
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	fnUSBINT_WriteFIFO(uint32_t FIFO_Address, uint32_t FIFO_WriteData)
{
		SN_USB->RWADDR = FIFO_Address;
		SN_USB->RWDATA = FIFO_WriteData;
		SN_USB->RWSTATUS = 0x01;
		while (SN_USB->RWSTATUS &0x01);
}


/*****************************************************************************
* Function		: fnUSBMAIN_ReadFIFO
* Description	:
* Input				: FIFO_Address2
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	fnUSBMAIN_ReadFIFO(uint32_t FIFO_Address2)
{
		SN_USB->RWADDR2 = FIFO_Address2;
		SN_USB->RWSTATUS2 = 0x02;
		while (SN_USB->RWSTATUS2 &0x02);
		wUSBMAIN_ReadDataBuf = SN_USB->RWDATA2;
}


/*****************************************************************************
* Function		: fnUSBMAIN_WriteFIFO
* Description	:
* Input				: FIFO_Address2,  FIFO_WriteData2
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	fnUSBMAIN_WriteFIFO(uint32_t FIFO_Address2, uint32_t FIFO_WriteData2)
{
		SN_USB->RWADDR2 = FIFO_Address2;
		SN_USB->RWDATA2 = FIFO_WriteData2;
		SN_USB->RWSTATUS2 = 0x01;
 		while (SN_USB->RWSTATUS2 &0x01);
}


/*****************************************************************************
* Function		: USB_ReturntoNormal
* Description	: Enable USB IHRC and switch system into IHRC
*								Enable PHY/ESD protect
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_ReturntoNormal	(void)
{
	if(((SN_FLASH->LPCTRL)&0xF)!=0x05)				// avoid MCU run 48MHz call this function occur HF
		SystemInit();
	SystemCoreClockUpdate();
	USB_WakeupEvent();
}


// /*****************************************************************************
// * Function		: USB_SwitchtoSlow
// * Description	: System switch into ILRC, and wait for stable
// * Input				: None
// * Output			: None
// * Return			: None
// * Note				: None
// *****************************************************************************/
// void USB_SwitchtoSlow	(void)
// {
// 	SN_USB->INTEN = 0;

// 	//** switch ILRC
// 	SN_SYS0->CLKCFG = 0x01;
// 	//** check ILRC status
// 	while((SN_SYS0->CLKCFG & 0x10) != 0x10);
// 	//** switch SYSCLK / 4		DO NOT set SYSCLK / 1 or SYSCLK / 2!!!!
// 	SN_SYS0->AHBCP = 2;
// 	#if (SuspendMode == Slow)
// 	//** Setting Flash mode to slow mode
// 	SN_FLASH->LPCTRL = 0x5AFA0002;
// 	#endif
// 	//** disable IHRC
// 	SN_SYS0->ANBCTRL = 0;

// 	SN_USB->INTEN = (mskBUS_IE|mskUSB_IE|mskEPnACK_EN|mskBUSWK_IE);
// 	#if	(EP1_NAK_IE == ENABLE)
// 	SN_USB->INTEN |= mskEP1_NAK_EN;
// 	#endif
// 	#if	(EP2_NAK_IE == ENABLE)
// 	SN_USB->INTEN |= mskEP2_NAK_EN;
// 	#endif
// 	#if	(EP3_NAK_IE == ENABLE)
// 	SN_USB->INTEN |= mskEP3_NAK_EN;
// 	#endif
// 	#if	(EP4_NAK_IE == ENABLE)
// 	SN_USB->INTEN |= mskEP4_NAK_EN;
// 	#endif
// 	#if	(SOF_IE == ENABLE)
// 	SN_USB->INTEN |= mskUSB_SOF_IE;
// 	#endif
// }

