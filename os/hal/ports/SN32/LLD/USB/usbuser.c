/*----------------------------------------------------------------------------
 *      U S B  -  K e r n e l
 *----------------------------------------------------------------------------
 * Name:    usbuser.c
 * Purpose: USB Custom User Module
 * Version: V1.01
 * Date:		2017/07
 *------------------------------------------------------------------------------*/
#include	<SN32F240B.h>
#include    <string.h>

#include	"usbhw.h"
#include	"usbuser.h"
#include	"usbram.h"
#include	"usbdesc.h"


/*****************************************************************************
* Function		: Goto_Bootloader
* Description	: ISP use for user code jump to Bootloader
* Input				: None
* Output			: None
* Return			: None
* Note				: NEVER REMOVE!!!!!
*****************************************************************************/
// __asm void Goto_Bootloader(void)
// {
// 		LDR			r0,=0x40060024 		//**�IMap to BL
//      STR			r1,[r0]
// 		LDR         r0, =0x1FFF0301		//** bootloader address = 0x1FFF0300,	under Thumb mode usage LSB=1
// 		BX          r0
// }


/*****************************************************************************
* Function		: USB_ResetEvent
* Description	: recevice USB bus reset to Initial parameter
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_ResetEvent (void)
{
	uint32_t	wLoop;
	__USB_CLRINSTS(0xFFFFFFFF);		//** Clear all USB Event status

	sUSB_EumeData.wUSB_Status = mskBUSRESET;	//** Set BusReset = 1
	sUSB_EumeData.wUSB_SetConfiguration = 0;	//** Clear Set Configuration
	__USB_SETADDRESS(0);					//** Set USB address = 0
	USB_EPnStall(USB_EP0);				//** Set EP0 enable & INOUTSTALL

	for (wLoop=USB_EP1; wLoop<=USB_EP4; wLoop++)
		USB_EPnDisable(wLoop);			//** Set EP1~EP4 disable & NAK
}


/*****************************************************************************
* Function		: USB_SuspendEvent
* Description	: SET USB_Status = SUSPEND
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_SuspendEvent (void)
{
	sUSB_EumeData.wUSB_Status |= mskBUSSUSPEND;	//** Set BusSuspend = 1
}


/*****************************************************************************
* Function		: USB_ResumeEvent
* Description	: SET USB_Status = BUSRESUME
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_ResumeEvent (void)
{
	sUSB_EumeData.wUSB_Status |= mskBUSRESUME;	//** sUSB_EumeData.wUSB_Status record  Bus resume status
	__USB_CLRINSTS(mskBUS_RESUME);							//** Clear BUS_RESUME
}


/*****************************************************************************
* Function		: USB_WakeupEvent
* Description	: Enable USB CLK and PHY
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_WakeupEvent	(void)
{
	__USB_PHY_ENABLE;												//** enable ESD_EN & PHY_EN
	__USB_CLRINSTS(mskBUS_WAKEUP);					//** Clear BUS_WAKEUP
}


/*****************************************************************************
* Function		: USB_SOFEvent
* Description	: Clear SOF Interrupt Event Status
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_SOFEvent (void)
{
	__USB_CLRINSTS(mskUSB_SOF);							//** Clear USB_SOF
}


/*****************************************************************************
* Function		: USB_StandardVar_Init
* Description	: USB Standard Variable initialtion
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_StandardVar_Init(void)
{
	uint32_t	i;

	for(i=0; i<5; i++)
	{
		wUSB_EndpHalt[i]=0;
	}
	for(i=0; i<4; i++)
	{
		wUSB_IfAlternateSet[i]=0;
	}
	sUSB_EumeData.bUSB_bmRequestType = 0;
	sUSB_EumeData.bUSB_bRequest=0;
	sUSB_EumeData.bUSB_wValueL=0;
	sUSB_EumeData.bUSB_wValueH=0;
	sUSB_EumeData.bUSB_wIndexL=0;
	sUSB_EumeData.bUSB_wIndexH=0;
	sUSB_EumeData.bUSB_wLength=0;
	sUSB_EumeData.wUSB_SetConfiguration = 0;
	sUSB_EumeData.bUSB_DeviceAddr=0;
	sUSB_EumeData.wUSB_Status |= mskINITREPEAT;
}

