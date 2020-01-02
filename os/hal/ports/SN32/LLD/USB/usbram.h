/*----------------------------------------------------------------------------
 *      U S B  -  K e r n e l
 *----------------------------------------------------------------------------
 * Name:    usbuser.h
 * Purpose: USB Custom User Definitions
 * Version: V1.20
 *----------------------------------------------------------------------------*/

#ifndef __USBRAM_H__
#define __USBRAM_H__



typedef struct
{
	uint8_t	bUSB_bmRequestType;
	uint8_t	bUSB_bRequest;
	uint8_t	bUSB_wValueL;
	uint8_t	bUSB_wValueH;
	uint8_t	bUSB_wIndexL;
	uint8_t	bUSB_wIndexH;
	uint16_t	bUSB_wLength;
	volatile	uint32_t wUSB_SetConfiguration;
	uint8_t		bUSB_DeviceAddr;
	volatile	uint32_t	wUSB_Status;
}SUSB_EUME_DATA;

extern  SUSB_EUME_DATA	sUSB_EumeData;
//extern S_USB_SETUP_DATA	S_USB_EP0setupdata;

//USB FIFO Read/Write Data buffer
extern	volatile uint32_t	wUSBINT_ReadDataBuf;
extern	volatile uint32_t	wUSBINT_WriteDataBuf;
//USB Main Loop FIFO Read/Write Data buffer
extern	volatile uint32_t	wUSBMAIN_ReadDataBuf;
extern	volatile uint32_t	wUSBMAIN_WriteDataBuf;


/*_____ D E C L A R A T I O N S ____________________________________________*/

extern	volatile uint32_t	wUSB_EPnOffset[];
extern	volatile uint32_t	wUSB_EPnPacketsize[];
extern	volatile uint8_t		wUSB_EndpHalt[];

extern	const	uint8_t	*pUSB_TableIndex;
extern	volatile uint32_t	wUSB_TableLength;
extern	volatile uint8_t	wUSB_IfAlternateSet[];
extern	uint8_t		bNDT_Flag;
extern	uint16_t	dbNDT_Cnt;
extern	uint32_t	wUSB_PreTableLength;

extern	uint16_t	mode;
extern	uint32_t	cnt;
extern	uint32_t	wUSB_MouseData;


#endif  /* __USBRAM_H__ */
