/*----------------------------------------------------------------------------
 *      U S B  -  K e r n e l
 *----------------------------------------------------------------------------
 * Name:    usbuser.c
 * Purpose: USB Custom User Module
 * Version: V1.01
 * Date:		2017/07
 *------------------------------------------------------------------------------*/
#include	<SN32F240B.h>
// #include	"..\type.h"
// #include	"..\Utility\Utility.h"
#include  <string.h>

#include	"usbhw.h"
#include	"usbuser.h"
#include	"usbram.h"
#include	"usbdesc.h"
#include	"hid.h"
#include	"hidram.h"


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
* Function		: USB_EP0SetupEvent
* Description	: 1. Clear SETUP Interrupt event status.
*								2. Save SETUP CMD to parameter.
*								3. Determine SETUP is Standard or HID request.
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EP0SetupEvent (void)
{
	volatile uint32_t	USB_SRAM_EP0_W0, USB_SRAM_EP0_W1;
	uint32_t	wCmd;

	//** Clear ENDP0_SETUP & ENDP0_PRESETUP = 0
	__USB_CLRINSTS((mskEP0_SETUP|mskEP0_PRESETUP|mskEP0_OUT_STALL|mskEP0_IN_STALL));
	//** keep EP0	NAK
	USB_EPnNak(USB_EP0);

	if (!(SN_USB->INSTS & mskERR_SETUP))
	{
		sUSB_EumeData.wUSB_Status &= ~(mskSETUP_IN | mskSETUP_OUT);	//** Clear Setup_IN & Setup_OUT = 0
		/*save SETUP cmd data*/
		fnUSBINT_ReadFIFO(0x00);
		USB_SRAM_EP0_W0 = wUSBINT_ReadDataBuf;
		fnUSBINT_ReadFIFO(0x04);
		USB_SRAM_EP0_W1 = wUSBINT_ReadDataBuf;

		//** save EP0 SETUP DATA to sUSB_EumeData
		sUSB_EumeData.bUSB_bmRequestType     = (USB_SRAM_EP0_W0& 0x000000FF);
		sUSB_EumeData.bUSB_bRequest			 = (USB_SRAM_EP0_W0& 0x0000FF00)>>8;
		sUSB_EumeData.bUSB_wValueL			 = (USB_SRAM_EP0_W0& 0x00FF0000)>>16;
		sUSB_EumeData.bUSB_wValueH			 = (USB_SRAM_EP0_W0& 0xFF000000)>>24;
		sUSB_EumeData.bUSB_wIndexL 			 = (USB_SRAM_EP0_W1& 0x000000FF);
		sUSB_EumeData.bUSB_wIndexH			 = (USB_SRAM_EP0_W1& 0x0000FF00)>>8;
		sUSB_EumeData.bUSB_wLength			 = (USB_SRAM_EP0_W1& 0xFFFF0000)>>16;

		//** Check the CMD request type
		wCmd = (sUSB_EumeData.bUSB_bmRequestType) & REQUEST_TYPE_MASK;
		if (wCmd == REQUEST_STANDARD)
		{
			USB_StandardRequest();
			return;
		}
		else if ( wCmd == REQUEST_CLASS)
		{
			USB_HIDRequest();
			return;
		}
	}
	else
	__USB_CLRINSTS(mskERR_SETUP);						    //** Clear ERR_SETUP
	USB_EPnStall(USB_EP0);									//** EP0 SETUP token Wrong or SETUP Cmd Wrong
}


/*****************************************************************************
* Function		: USB_EP0InEvent
* Description	: 1. check set reprot feature cmd.
*								2. check set address cmd.
*								3. return IN token data.
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EP0InEvent(void)
{
	uint32_t		i;
	__USB_CLRINSTS(mskEP0_IN);								//** Clear ENDP0_IN = 0
	if(sHID_Data.wHID_SetReportFeature == mskSET_REPROTFEATURE_ARRIVAL)
	{
		//** The IN token of set report feature command END.
		sHID_Data.wHID_SetReportFeature = 0x00;
		if( (sHID_Data.wHID_Setreportfeature[0] == RETURN_KERNEL_0) &&(sHID_Data.wHID_Setreportfeature[1] == RETURN_KERNEL_1))
		{
				//** check ISP password
				//** Clear USB FIFO
				for(i=0; i<64 ; i++)
				{
					fnUSBINT_WriteFIFO(i<<2 , 0);
				}
				// Goto_Bootloader();						//** go to bootloader
		}
		sHID_Data.wHID_SetReportFeature = mskSET_REPROTFEATURE_DONE;
	}

	if (sUSB_EumeData.wUSB_Status & mskSETADDRESSCMD)
	{
		//** The IN token of set address command END.
		sUSB_EumeData.wUSB_Status &= ~mskSETADDRESSCMD;		//** Clear SetAddressCmd = 0
		__USB_SETADDRESS(sUSB_EumeData.bUSB_DeviceAddr);
		USB_EPnStall(USB_EP0);
		sUSB_EumeData.wUSB_Status &= ~mskSETUP_IN;				//** Clear Setup_IN = 0
		return;
	}
	else
	{
		//** The IN toekn of device return IN toekn data
		if ((sUSB_EumeData.bUSB_wLength != 0) && ((sUSB_EumeData.wUSB_Status & mskSETUP_IN) == 0))// Check Setup_IN == 0
		{
			USB_TableTransmit();
			sUSB_EumeData.wUSB_Status &= ~mskSETUP_IN;				//** Clear Setup_IN = 0
			return;
		}
	}
	USB_EPnStall(USB_EP0);									//** EP0 STALL
}


/*****************************************************************************
* Function		: USB_EP0OutEvent
* Description	: 1. set report Feature data.
*								2. set report Output cmd data.
*								3. OUT toekn return ACK or STALL
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EP0OutEvent(void)
{
	uint32_t i;

	__USB_CLRINSTS(mskEP0_OUT);								//** Clear ENDP0_OUT = 0

	if(sHID_Data.wHID_SetReportFeature == mskSET_REPORTFEATURE_FLAG)	//** Check Set_report_feature == 1
	{
		//** Read only the first 8 byte data to check whether matach RETURN_KERNEL pattern
		for(i=0; i<16 ; i++)
		{
			fnUSBINT_ReadFIFO(i<<2);
			sHID_Data.wHID_Setreportfeature[i] = wUSBINT_ReadDataBuf;
		}
		sHID_Data.wHID_SetReportFeature = mskSET_REPROTFEATURE_ARRIVAL;

	}
	else if (sHID_Data.wHID_Status & mskSET_REPORT_FLAG)	//** Check Set_report_flag == 1
	{
		sHID_Data.wHID_Status &= ~mskSET_REPORT_FLAG;		//** Clear Set_report_flag = 0
		fnUSBINT_ReadFIFO(0x00);
		sHID_Data.wHID_SetRptByte[0] = wUSBINT_ReadDataBuf; //** save data
		sHID_Data.wHID_Status |= mskSET_REPORT_DONE;		//** Ser Set_report_done = 1
	}
	if (!(sUSB_EumeData.wUSB_Status & mskSETUP_OUT))	//** Check Setup_OUT == 0
		USB_EPnAck(USB_EP0,0);								//** EP0 ACK 0 byte
	else
	{
		if (!(SN_USB->INSTS & mskEP0_PRESETUP))
			__USB_EP0OUTSTALL_EN;		//** OUT token return STALL
	}
	sUSB_EumeData.wUSB_Status &= ~mskSETUP_OUT;				//** Clear Setup_OUT = 0
}


/*****************************************************************************
* Function		: USB_StandardRequest
* Description	: sUSB_EumeData.bUSB_bRequest of SETUP request type.
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_StandardRequest(void)
{
	switch(sUSB_EumeData.bUSB_bRequest)
	{
		case	USB_GET_STATUS:						//** 0
		{
			USB_GetStatusEvent();
			break;
		}
		case	USB_CLEAR_FEATURE:				//** 1
		{
			USB_ClearFeatureEvent();
			break;
		}
		case	USB_SET_FEATURE:					//** 3
		{
			USB_SetFeatureEvent();
			break;
		}
		case	USB_SET_ADDRESS:					//** 5
		{
			USB_SetAddressEvent();
			break;
		}
		case	USB_GET_DESCRIPTOR:				//** 6
		{
			USB_GetDescriptorEvent();
			break;
		}
		case	USB_SET_DESCRIPTOR:				//** 7
		{
			USB_SetDescriptorEvent();
			break;
		}
		case	USB_GET_CONFIGURATION:		//** 8
		{
			USB_GetConfigurationEvent();
			break;
		}
		case	USB_SET_CONFIGURATION:		//** 9
		{
			USB_SetConfigurationEvent();
			break;
		}
		case	USB_GET_INTERFACE:				//** 10
		{
			USB_GetInterfaceEvent();
			break;
		}
		case	USB_SET_INTERFACE:				//** 11
		{
			USB_SetInterfaceEvent();
			break;
		}
		default:												//** others
		{
			USB_EPnStall(USB_EP0);
			break;
		}
	}
}


/*****************************************************************************
* Function		: USB_GetStatusEvent
* Description	: return Remote_Wakeup and EPn Halt status.
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_GetStatusEvent(void)
{
	uint32_t	wCmdtype = sUSB_EumeData.bUSB_bmRequestType & USB_ENDPOINT_NUM;
	uint32_t	wEPNum, i;

	if ((sUSB_EumeData.bUSB_bmRequestType & REQUEST_DIR_MASK) != REQUEST_DEVICE_TO_HOST)
		USB_EPnStall(0);											//** EP0 STALL

	if (wCmdtype == REQUEST_TO_DEVICE)			//** Device
	{
		if (sUSB_EumeData.wUSB_Status & mskREMOTE_WAKEUP)				//** Remote Wakeup enable
			fnUSBINT_WriteFIFO(0x00, USB_GETSTATUS_REMOTE_WAKEUP );
		else {                                                          //** Remote Wakeup disable
			fnUSBINT_WriteFIFO(0x00, 0);
			sUSB_EumeData.wUSB_Status |= mskSETUP_OUT;						//** Set Setup_OUT = 1
			USB_EPnAck(USB_EP0,2);							//** EP0 ACK 2 byte
		    return;
        }
	}
	else if (wCmdtype == REQUEST_TO_INTERFACE)	//** Interface
	{
		if ((sUSB_EumeData.wUSB_SetConfiguration == USB_CONFIG_VALUE) && (sUSB_EumeData.bUSB_wIndexH == 0))
		{
			#if (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE1)
				if (sUSB_EumeData.bUSB_wIndexL <= USB_INTERFACE_3)
			#elif (USB_LIBRARY_TYPE == USB_MOUSE_TYPE)
				if (sUSB_EumeData.bUSB_wIndexL <= USB_INTERFACE_1)
			#elif (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE2)
				if (sUSB_EumeData.bUSB_wIndexL <= USB_INTERFACE_2)
			#endif
				{
					fnUSBINT_WriteFIFO(0x00, 0);
					sUSB_EumeData.wUSB_Status |= mskSETUP_OUT;			//** Set Setup_OUT = 1
					USB_EPnAck(USB_EP0,2);						//** EP0 ACK 2 byte
					return;
				}
		}
	}
	else if (wCmdtype == REQUEST_TO_ENDPOINT)	//** Endpoint
	{
			wEPNum = sUSB_EumeData.bUSB_wIndexL & USB_ENDPOINT_NUM;
		#if (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE1)
			if (wEPNum <= USB_EP4)
		#elif (USB_LIBRARY_TYPE == USB_MOUSE_TYPE)
			if ((wEPNum == USB_EP1)||(wEPNum == USB_EP4))
		#elif (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE2)
			if ((wEPNum <= USB_EP2)||(wEPNum == USB_EP4))
		#endif
			{
				i = *(&wUSB_EndpHalt[0] + wEPNum);
				fnUSBINT_WriteFIFO(0x00, i);

				sUSB_EumeData.wUSB_Status |= mskSETUP_OUT;		//** Setup_OUT = 1
				USB_EPnAck(USB_EP0,2);					//** EP0 ACK 2 byte
				return;
			}
	}
}


/*****************************************************************************
* Function		: USB_ClearFeatureEvent
* Description	: disable Remote_Wakeup and EPn Halt=1.
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	USB_ClearFeatureEvent(void)
{
	uint32_t	wCmdtype = sUSB_EumeData.bUSB_bmRequestType & USB_ENDPOINT_NUM;
	uint32_t	wEPNum;

	if ((sUSB_EumeData.bUSB_bmRequestType & REQUEST_DIR_MASK) != REQUEST_HOST_TO_DEVICE)
		USB_EPnStall(USB_EP0);									//** EP0 STALL

	if (wCmdtype == REQUEST_TO_DEVICE)				//** Device
	{
		if (sUSB_EumeData.bUSB_wValueL == USB_FEATURE_REMOTE_WAKEUP)
		{
			sUSB_EumeData.wUSB_Status &= ~mskREMOTE_WAKEUP;			//** Clear Remote_Wakeup = 0
			//** Set Dev_Feature_Cmd & Setup_IN = 1
			sUSB_EumeData.wUSB_Status |= (mskDEV_FEATURE_CMD | mskSETUP_IN);
			USB_EPnAck(USB_EP0,0);				//** EP0 ACK 0 byte
			return;
		}
	}
	else if (wCmdtype == REQUEST_TO_ENDPOINT)	//** Endpoint
	{
		if (sUSB_EumeData.bUSB_wValueL == USB_FEATURE_ENDPOINT_STALL)
		{
			wEPNum = sUSB_EumeData.bUSB_wIndexL & USB_ENDPOINT_NUM;
			if (wEPNum == USB_EP0)
			{
				if (sUSB_EumeData.wUSB_Status & mskSETADDRESS)		//** Check SetAddress
				{
					wUSB_EndpHalt[0] = USB_EPn_NON_HALT;
					sUSB_EumeData.wUSB_Status |= mskSETUP_IN;				//** Set Setup_IN = 1
					USB_EPnAck(USB_EP0,0);						//** EP0 ACK 0 byte
					return;
				}
			}
			#if (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE1)
				else if (wEPNum <= USB_EP4)
			#elif (USB_LIBRARY_TYPE == USB_MOUSE_TYPE)
				else if ((wEPNum == USB_EP1)||(wEPNum == USB_EP4))
			#elif (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE2)
				else if ((wEPNum <= USB_EP2)||(wEPNum == USB_EP4))
			#endif
				{
				if (sUSB_EumeData.wUSB_SetConfiguration == USB_CONFIG_VALUE)
				{
					*(&wUSB_EndpHalt[0] + wEPNum) = USB_EPn_NON_HALT;

					sUSB_EumeData.wUSB_Status |= mskSETUP_IN;			//** Set Setup_IN = 1
					USB_EPnAck(USB_EP0,0);					//** EP0 ACK 0 byte
					return;
				}
			}
		}
	}
}


/*****************************************************************************
* Function		: USB_SetFeatureEvent
* Description	: Enable Remote_Wakeup and EPn Halt=1.
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	USB_SetFeatureEvent(void)
{
	uint32_t	wCmdtype = sUSB_EumeData.bUSB_bmRequestType & USB_ENDPOINT_NUM;
	uint32_t	wEPNum;

	if ((sUSB_EumeData.bUSB_bmRequestType & REQUEST_DIR_MASK) != REQUEST_HOST_TO_DEVICE)
		USB_EPnStall(USB_EP0);								//** EP0 STALL


	if (wCmdtype == REQUEST_TO_DEVICE)			//** Device
	{
		if (sUSB_EumeData.bUSB_wValueL == USB_FEATURE_REMOTE_WAKEUP)
		{
			//** Set Remote_Wakeup & Dev_Feature_Cmd & Setup_IN = 1
			sUSB_EumeData.wUSB_Status |= (mskREMOTE_WAKEUP | mskDEV_FEATURE_CMD | mskSETUP_IN);
			USB_EPnAck(USB_EP0,0);							//** EP0 ACK 0 byte
			return;
		}
	}
	else if (wCmdtype == REQUEST_TO_ENDPOINT)	//** Endpoint
	{
		if (sUSB_EumeData.bUSB_wValueL == USB_FEATURE_ENDPOINT_STALL)
		{
			wEPNum = sUSB_EumeData.bUSB_wIndexL & USB_ENDPOINT_NUM;
		#if (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE1)
			if ((wEPNum >= USB_EP1) && (wEPNum <= USB_EP4))
		#elif (USB_LIBRARY_TYPE == USB_MOUSE_TYPE)
			if ((wEPNum == USB_EP1)||(wEPNum == USB_EP4))
		#elif (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE2)
			if (((wEPNum >= USB_EP1) && (wEPNum <= USB_EP2))||(wEPNum == USB_EP4))
		#endif
			{
				if (sUSB_EumeData.wUSB_SetConfiguration == USB_CONFIG_VALUE)
				{
					*(&wUSB_EndpHalt[0] + wEPNum) = USB_EPn_HALT;
					USB_EPnStall(wEPNum);
					sUSB_EumeData.wUSB_Status |= mskSETUP_IN;			//** Set Setup_IN = 1
					USB_EPnAck(USB_EP0,0);					//** EP0 ACK 0 byte
					return;
				}
			}
		}
	}
	else
	{
		USB_EPnStall(USB_EP0);								//** EP0 STALL
	}
}


/*****************************************************************************
* Function		: USB_SetAddressEvent
* Description	: Set device address.
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	USB_SetAddressEvent(void)
{
	sUSB_EumeData.wUSB_Status &= ~mskSETADDRESS;						// Clear SetAddress = 0
	sUSB_EumeData.wUSB_Status |= mskSETADDRESSCMD;					// Set SetAddressCmd = 1
	if (sUSB_EumeData.bUSB_wValueL != 0)
		sUSB_EumeData.wUSB_Status |= mskSETADDRESS;						// Set SetAddress = 1

	sUSB_EumeData.bUSB_DeviceAddr = sUSB_EumeData.bUSB_wValueL;
	sUSB_EumeData.wUSB_Status |= mskSETUP_IN;								// Set Setup_IN = 1
	USB_EPnAck(USB_EP0,0);										// EP0 ACK 0 byte
}


/*****************************************************************************
* Function		: USB_GetDescriptorEvent
* Description	: Get descriptor length & index
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	USB_GetDescriptorEvent(void)
{
		// uint32_t 	unsupport, i;
        uint32_t 	unsupport;
		unsupport = GET_DESCRIPTOR_STALL;

		// for(i=0; i<USB_GETDESCRIPTOR_MAX; i++)
		// {
		// 	if( (sUSB_EumeData.bUSB_wValueH == DesInfo[i].wValue_H) && (sUSB_EumeData.bUSB_wIndexL == DesInfo[i].wIndex_L) &&
		// 		(sUSB_EumeData.bUSB_wValueL == DesInfo[i].wValue_L) )
		// 	{
		// 		// wUSB_TableLength = DesInfo[i].wTable_length;
		// 		// pUSB_TableIndex  = DesInfo[i].pTable_Index;
		// 		unsupport = GET_DESCRIPTOR_ACK;
		// 		break;
		// 	}
		// }
		if(unsupport == GET_DESCRIPTOR_STALL)
		{
			USB_EPnStall(USB_EP0);						// EP0 STALL
			return;
		}
		sUSB_EumeData.wUSB_Status |= mskSETUP_OUT;				// Set Setup_OUT = 1
		USB_TableTransmit();
}


/*****************************************************************************
* Function		: USB_SetDescriptorEvent
* Description	: Set descriptor STALL
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	USB_SetDescriptorEvent(void)
{
	USB_EPnStall(USB_EP0);							// EP0 STALL
}


/*****************************************************************************
* Function		: USB_GetConfigurationEvent
* Description	: None
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	USB_GetConfigurationEvent(void)
{
	uint32_t	i;
	fnUSBINT_WriteFIFO(0x00, sUSB_EumeData.wUSB_SetConfiguration);

	if (sUSB_EumeData.wUSB_SetConfiguration == USB_CONFIG_VALUE)
	{
	#if (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE1)
		for (i=USB_EP1; i<=USB_EP3; i++)
	#elif (USB_LIBRARY_TYPE == USB_MOUSE_TYPE)
		for (i=USB_EP1; i<=USB_EP1; i++)
	#elif (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE2)
		for (i=USB_EP1; i<=USB_EP2; i++)
	#endif
		{
			USB_EPnNak(i);							// Enable EP1~EP4
		}
		USB_EPnNak(USB_EP4);
	}
	wUSB_TableLength = 0;
	// Set Not_8byte_endding & Setup_OUT =1
	sUSB_EumeData.wUSB_Status |= (mskNOT_8BYTE_ENDDING | mskSETUP_OUT);
	USB_EPnAck(USB_EP0,1);							// EP0 ACK 1 byte
}


/*****************************************************************************
* Function		: USB_SetConfigurationEvent
* Description	: SetConfiguration Halt =0, IN token = NAK, OUT token =ACK
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	USB_SetConfigurationEvent(void)
{
	uint32_t	i;
	volatile uint8_t	*pUsbRam;
	pUsbRam = &wUSB_EndpHalt[0];

	if (sUSB_EumeData.wUSB_Status & mskSETADDRESS)
	{
		if (sUSB_EumeData.bUSB_wValueL == 0)
		{
			sUSB_EumeData.wUSB_SetConfiguration = 0;
			sUSB_EumeData.wUSB_Status |= mskSETCONFIGURATION0CMD;	// Set SetConfiguration0Cmd = 1
			for (i=USB_EP1; i<=USB_EP4; i++)
			{
				*(pUsbRam+i) = USB_EPn_HALT;			// wUsb_EndpHalt0n = 1
				USB_EPnDisable(i);			// Disable EP1~EP4
			}
			sUSB_EumeData.wUSB_Status |= mskSETUP_IN;			// Set Setup_IN = 1
			USB_EPnAck(USB_EP0,0);					// EP0 ACK 0 byte
			return;
		}
		else if (sUSB_EumeData.bUSB_wValueL == USB_CONFIG_VALUE)
		{
			sUSB_EumeData.wUSB_SetConfiguration = USB_CONFIG_VALUE;
			sUSB_EumeData.wUSB_Status &= ~mskSETCONFIGURATION0CMD;	// Clear SetConfiguration0Cmd = 0
		#if (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE1)
			for (i=USB_EP0; i<=USB_EP3; i++)
		#elif (USB_LIBRARY_TYPE == USB_MOUSE_TYPE)
			for (i=USB_EP0; i<=USB_EP1; i++)
		#elif (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE2)
			for (i=USB_EP0; i<=USB_EP2; i++)
		#endif
			{
				*(pUsbRam+i) = USB_EPn_NON_HALT;		// wUsb_EndpHaltn = 0
				if (i > USB_EP0)
				{
					USB_EPnNak(i);					// Enable EP1~EP4
					if ( (SN_USB->CFG>>(i-1)) & mskEP1_DIR) //if EP1~EP4 is OUT direction
						USB_EPnAck(i, 0);			// set EP1~EP4 ACK
				}
			}
			sUSB_EumeData.wUSB_Status |= mskSETUP_IN;			// Set Setup_IN = 1
			USB_EPnAck(USB_EP0,0);					// EP0 ACK 0 byte
			return;
		}
	}
	USB_EPnStall(USB_EP0);							// EP0 STALL
}


/*****************************************************************************
* Function		: USB_GetInterfaceEvent
* Description	: return AlternateSet status
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	USB_GetInterfaceEvent(void)
{
	uint32_t	i;

	if (sUSB_EumeData.wUSB_SetConfiguration == USB_CONFIG_VALUE)
	{
		if (sUSB_EumeData.bUSB_bmRequestType == (REQUEST_DEVICE_TO_HOST|REQUEST_TO_INTERFACE))
		{
		#if (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE1)
			if (sUSB_EumeData.bUSB_wIndexL <= USB_INTERFACE_3)
		#elif (USB_LIBRARY_TYPE == USB_MOUSE_TYPE)
			if (sUSB_EumeData.bUSB_wIndexL <= USB_INTERFACE_1)
		#elif (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE2)
			if (sUSB_EumeData.bUSB_wIndexL <= USB_INTERFACE_2)
		#endif
			{
				i = *(&wUSB_IfAlternateSet[0]+sUSB_EumeData.bUSB_wIndexL);
				fnUSBINT_WriteFIFO(0x00, i);

				sUSB_EumeData.wUSB_Status |= mskSETUP_OUT;	// Set Setup_OUT = 1
				USB_EPnAck(USB_EP0,1);				// EP0 ACK 1 byte
				return;
			}
		}
	}
	USB_EPnStall(USB_EP0);							// EP0 STALL
}


/*****************************************************************************
* Function		: USB_SetInterfaceEvent
* Description	: Set AlternateSet status
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void	USB_SetInterfaceEvent(void)
{
	uint32_t	i;
	volatile 	uint8_t		*pUsbRam;

	if (sUSB_EumeData.wUSB_SetConfiguration == USB_CONFIG_VALUE)
	{
		pUsbRam = &wUSB_EndpHalt[0];
		for (i=USB_EP0; i<=USB_EP4; i++)
		{
			*(pUsbRam+i) = USB_EPn_NON_HALT;	// wUsb_EndpHalt0~wUsb_EndpHalt4 = 0
		}
	#if (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE1)
		if (sUSB_EumeData.bUSB_wIndexL <= USB_INTERFACE_3)
	#elif (USB_LIBRARY_TYPE == USB_MOUSE_TYPE)
		if (sUSB_EumeData.bUSB_wIndexL <= USB_INTERFACE_1)
	#elif (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE2)
		if (sUSB_EumeData.bUSB_wIndexL <= USB_INTERFACE_2)
	#endif
		{
			if (sUSB_EumeData.bUSB_wValueL == 0)
			{
				*(&wUSB_IfAlternateSet[0] + sUSB_EumeData.bUSB_wIndexL) = 0;
				USB_ClrEPnToggle(sUSB_EumeData.bUSB_wIndexL);	// EPn Data toggle = DATA0
				sUSB_EumeData.wUSB_Status |= mskSETUP_IN;			// Set Setup_IN = 1
				USB_EPnAck(USB_EP0,0);					// EP0 ACK 0 byte
				return;
			}
		}
	}
	USB_EPnStall(USB_EP0);							// EP0 STALL
}


/*****************************************************************************
* Function		: USB_TableTransmit
* Description	: set USB data to EP0 RAM
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_TableTransmit(void)
{
	uint8_t	i;
	uint32_t	wUSB_TableTemp;
	const uint8_t	*pUsbIndex = pUSB_TableIndex ;

	if (sUSB_EumeData.bUSB_wLength < wUSB_TableLength)
		wUSB_TableLength = sUSB_EumeData.bUSB_wLength;

	if (wUSB_TableLength == 0)
	{
		USB_EPnAck(USB_EP0,0);						//** EP0 ACK 0 byte
		if (wUSB_PreTableLength == USB_EP0_PACKET_SIZE)
		{
			wUSB_PreTableLength = 0;				//** Previous IN Token data length = USB_EP0_PACKET_SIZE
																			//** Next IN Token ACK 0 byte
		}
		else
		{
			__USB_EP0INSTALL_EN;						//** Before IN Token data length = 1 ~ (USB_EP0_PACKET_SIZE-1)
																			//** Next IN Token response STALL for CH8
		}
	}
	else
	{
		for (i=0; i<(USB_EP0_PACKET_SIZE>>2); i++)
		{
			wUSB_TableTemp = USB_Comb_Bytetoword((*pUsbIndex),*(pUsbIndex+1),*(pUsbIndex+2),*(pUsbIndex+3));
			fnUSBINT_WriteFIFO((i<<2),wUSB_TableTemp);
			pUsbIndex += 4;
		}
		wUSB_PreTableLength = wUSB_TableLength;				//** Temp IN Token data length
		if (wUSB_TableLength >= USB_EP0_PACKET_SIZE)
		{
			USB_EPnAck(USB_EP0,USB_EP0_PACKET_SIZE);		//** EP0 ACK USB_SETUP_PACKET_SIZE byte
			pUSB_TableIndex += USB_EP0_PACKET_SIZE;
			wUSB_TableLength -= USB_EP0_PACKET_SIZE;
		}
		else
		{
			USB_EPnAck(USB_EP0,wUSB_TableLength);
			wUSB_TableLength = 0;
		}
	}
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


/*****************************************************************************
* Function		: USB_Comb_Bytetoword
* Description	: Byte array memory copy to Word array
* Input				: None
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
uint32_t	USB_Comb_Bytetoword	(uint8_t	data0, uint8_t	data1, uint8_t	data2, uint8_t	data3)
{
	uint32_t	data;
	data = ((((uint32_t)data3<<24)&((uint32_t)0xFF<<24)) | ((data2<<16)&(0xFF<<16)) | ((data1<<8)&(0xFF<<8)) | (data0&0xFF));
	return (data);
}

