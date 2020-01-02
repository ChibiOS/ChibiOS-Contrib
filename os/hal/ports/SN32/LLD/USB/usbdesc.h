/*----------------------------------------------------------------------------
 *      U S B  -  K e r n e l
 *----------------------------------------------------------------------------
 * Name:    usbdesc.h
 * Purpose: USB Descriptors Definitions
 * Version: V1.20
 *----------------------------------------------------------------------------*/

#ifndef __USBDESC_H__
#define __USBDESC_H__


/*****************************************************************************
* Description	: USB_LIBRARY_TYPE SELECTION
*****************************************************************************/
#define USB_KB_MOUSE_TYPE1				1	// KB+Mouse(EP1 Standard + EP2 Mouse + EP3 hot key)
#define USB_MOUSE_TYPE						2	// Mouse(EP1)
#define USB_KB_MOUSE_TYPE2				3	// KB+Mouse(EP1 Standard + EP2 Mouse/Consumer page)
#define USB_LIBRARY_TYPE				USB_KB_MOUSE_TYPE2

/*****************************************************************************
* Description	: USB_VID
*****************************************************************************/
#define	USB_VID	0x0C45

/*****************************************************************************
* Description	: USB_PID
*****************************************************************************/
#if (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE1)
	#define	USB_PID	0x7043
#elif (USB_LIBRARY_TYPE == USB_MOUSE_TYPE)
	#define	USB_PID	0x7041
#elif (USB_LIBRARY_TYPE == USB_KB_MOUSE_TYPE2)
	#define	USB_PID	0x7044
#endif

/*****************************************************************************
* Description	: USB_REV
*****************************************************************************/
#define	USB_REV	0x0104

/*****************************************************************************
* Description	: USB EPn Buffer Offset Register
*****************************************************************************/
#define	EP1_BUFFER_OFFSET_VALUE	0x40
#define	EP2_BUFFER_OFFSET_VALUE	0x80
#define	EP3_BUFFER_OFFSET_VALUE	0xC0
#define	EP4_BUFFER_OFFSET_VALUE	0xE0


/*****************************************************************************
* Description	: USB EPn Settings
*****************************************************************************/
#define USB_EP0_PACKET_SIZE 			64					// only 8, 64
#define USB_ENDPOINT_NUM					0x7F
#define	USB_SETREPORT_SIZE				USB_SETUP_PACKET_SIZE/4

/* USB Endpoint Max Packet Size */
#define USB_EP1_PACKET_SIZE										0x40
#define USB_EP2_PACKET_SIZE										0x08
#define USB_EP3_PACKET_SIZE										0x08
#define USB_EP4_PACKET_SIZE										0x08

/* EP1~EP4 Direction define */
#define USB_EP1_DIRECTION					1					// IN = 1; OUT = 0
#define USB_EP2_DIRECTION					1					// IN = 1; OUT = 0
#define USB_EP3_DIRECTION					1					// IN = 1; OUT = 0
#define USB_EP4_DIRECTION					0					// IN = 1; OUT = 0

/* USB Endpoint Direction */
#define USB_DIRECTION_OUT											0
#define USB_DIRECTION_IN											1

/* EP1~EP6 Transfer mode define */
#define USB_INTERRUPT_MODE				0					// INTERRUPT Transfer
#define USB_BULK_MODE							1					// BULK Transfer
#define USB_ISOCHRONOUS_MODE			2					// ISOCHRONOUS Transfer

/* USB Protocol Value */
#define USB_BOOT_PROTOCOL											0
#define USB_REPORT_PROTOCOL										1

#define USB_IDLE_TIME_INITIAL									0x7D	// 125*4 = 500ms

/* USB Endpoint Halt Value */
#define USB_EPn_NON_HALT											0x0
#define USB_EPn_HALT													0x1

#define	LANG_ID_H															0x09
#define	LANG_ID_L															0X04



#define USB_WBVAL(x) ((x) & 0xFF),(((x) >> 8) & 0xFF)

#define USB_DEVICE_DESC_SIZE				0x12//(sizeof(USB_DEVICE_DESCRIPTOR))
#define USB_CONFIGUARTION_DESC_SIZE	0x09//(sizeof(USB_CONFIGURATION_DESCRIPTOR))
#define USB_INTERFACE_DESC_SIZE			0x09//(sizeof(USB_INTERFACE_DESCRIPTOR))
#define USB_ENDPOINT_DESC_SIZE			0x07//(sizeof(USB_ENDPOINT_DESCRIPTOR))
#define USB_HID_DESC_SIZE						0x09//(sizeof(HID_DESCRIPTOR))

/* USB Device Classes */
#define USB_DEVICE_CLASS_RESERVED							0x00
#define USB_DEVICE_CLASS_AUDIO								0x01
#define USB_DEVICE_CLASS_COMMUNICATIONS				0x02
#define USB_DEVICE_CLASS_HUMAN_INTERFACE			0x03
#define USB_DEVICE_CLASS_MONITOR							0x04
#define USB_DEVICE_CLASS_PHYSICAL_INTERFACE		0x05
#define USB_DEVICE_CLASS_POWER								0x06
#define USB_DEVICE_CLASS_PRINTER							0x07
#define USB_DEVICE_CLASS_STORAGE							0x08
#define USB_DEVICE_CLASS_HUB									0x09
#define USB_DEVICE_CLASS_MISCELLANEOUS				0xEF
#define USB_DEVICE_CLASS_VENDOR_SPECIFIC			0xFF

/* USB Device String Index */
#define USB_DEVICE_STRING_RESERVED						0x00
#define USB_DEVICE_STRING_MANUFACTURER				0x01
#define USB_DEVICE_STRING_PRODUCT							0x02
#define USB_DEVICE_STRING_SERIALNUMBER				0x03

/* bmAttributes in Configuration Descriptor */
#define USB_CONFIG_VALUE											0x01

/* bmAttributes in Configuration Descriptor */
#define USB_CONFIG_POWERED_MASK								0x40
#define USB_CONFIG_BUS_POWERED								0x80
#define USB_CONFIG_SELF_POWERED								0xC0
#define	USB_CONFIG_REMOTE_WAKEUP							0x20

/* bMaxPower in Configuration Descriptor */
#define USB_CONFIG_POWER_MA(mA)								((mA)/2)

/* bmAttributes in Endpoint Descriptor */
#define USB_ENDPOINT_TYPE_MASK								0x03
#define USB_ENDPOINT_TYPE_CONTROL							0x00
#define USB_ENDPOINT_TYPE_ISOCHRONOUS					0x01
#define USB_ENDPOINT_TYPE_BULK								0x02
#define USB_ENDPOINT_TYPE_INTERRUPT						0x03
#define USB_ENDPOINT_SYNC_MASK								0x0C
#define USB_ENDPOINT_SYNC_NO_SYNCHRONIZATION	0x00
#define USB_ENDPOINT_SYNC_ASYNCHRONOUS				0x04
#define USB_ENDPOINT_SYNC_ADAPTIVE						0x08
#define USB_ENDPOINT_SYNC_SYNCHRONOUS					0x0C
#define USB_ENDPOINT_USAGE_MASK								0x30
#define USB_ENDPOINT_USAGE_DATA								0x00
#define USB_ENDPOINT_USAGE_FEEDBACK						0x10
#define USB_ENDPOINT_USAGE_IMPLICIT_FEEDBACK	0x20
#define USB_ENDPOINT_USAGE_RESERVED						0x30

/* bEndpointAddress in Endpoint Descriptor */
#define USB_ENDPOINT_DIRECTION_MASK						0x80
// #define USB_ENDPOINT_OUT(addr)								((addr) | 0x00)
// #define USB_ENDPOINT_IN(addr)									((addr) | 0x80)

/* USB String Descriptor Types */
#define USB_STRING_LANGUAGE										0x00
#define USB_STRING_MANUFACTURER								0x01
#define USB_STRING_PRODUCT										0x02
#define USB_STRING_SERIALNUMBER								0x03
#define USB_STRING_CONFIGURATION							0x04
#define USB_STRING_INTERFACE									0x05




#define ENDPOINT_DESCRIPTOR_INDEX (USB_ConfigDescriptor+USB_CONFIGUARTION_DESC_SIZE+USB_INTERFACE_DESC_SIZE+USB_HID_DESC_SIZE)

#define HID_DESCRIPTOR_INDEX0	(USB_ConfigDescriptor+USB_CONFIGUARTION_DESC_SIZE+USB_INTERFACE_DESC_SIZE+((USB_HID_DESC_SIZE + USB_ENDPOINT_DESC_SIZE+USB_INTERFACE_DESC_SIZE)*(0x00)))
#define HID_DESCRIPTOR_INDEX1	(USB_ConfigDescriptor+USB_CONFIGUARTION_DESC_SIZE+USB_INTERFACE_DESC_SIZE+((USB_HID_DESC_SIZE + USB_ENDPOINT_DESC_SIZE+USB_INTERFACE_DESC_SIZE)*(0x01)))
#define HID_DESCRIPTOR_INDEX2	(USB_ConfigDescriptor+USB_CONFIGUARTION_DESC_SIZE+USB_INTERFACE_DESC_SIZE+((USB_HID_DESC_SIZE + USB_ENDPOINT_DESC_SIZE+USB_INTERFACE_DESC_SIZE)*(0x02)))
#define HID_DESCRIPTOR_INDEX3	(USB_ConfigDescriptor+USB_CONFIGUARTION_DESC_SIZE+USB_INTERFACE_DESC_SIZE+((USB_HID_DESC_SIZE + USB_ENDPOINT_DESC_SIZE+USB_INTERFACE_DESC_SIZE)*(0x03)))

typedef struct STRUCT_DESCRIPTOR_INFO{
	uint8_t	wValue_H;
	uint8_t	wIndex_L;
	uint8_t	wValue_L;
	uint16_t	wTable_length;
	const	uint8_t	*pTable_Index;
}STRUCT_DESCRIPTOR_INFO_A;
extern const	STRUCT_DESCRIPTOR_INFO_A DesInfo[];

#define USB_GETDESCRIPTOR_MAX 18		//by DesInfo size
#define USB_DES_STRING_MAX 		3		//by DesInfo size
#define GET_DESCRIPTOR_ACK 	 	1
#define GET_DESCRIPTOR_STALL 	0


//extern struct STRUCT_DESCRIPTOR_INFO;
extern const uint8_t USB_DeviceDescriptor[];
extern const uint8_t USB_ConfigDescriptor[];
extern const uint8_t USB_LanguageStringDescriptor[];
extern const uint8_t USB_ManufacturerStringDescriptor[];
extern const uint8_t USB_ProductStringDescriptor[];
extern const uint8_t USB_SerialNumberStringDescriptor[];
extern const uint8_t	HID_ReportDescriptor[];
extern const uint8_t	HID_ReportDescriptor2[];
extern const uint8_t	HID_ReportDescriptor3[];
extern const uint16_t	HID_ReportDescSize;
extern const uint16_t	HID_ReportDescSize2;
extern const uint16_t	HID_ReportDescSize3;
extern const uint16_t USB_LangStrDescSize;
extern const uint16_t USB_ManufStrDescSize;
extern const uint16_t USB_ProdStrDescSize;
extern const uint16_t USB_SerNumStrDescSize;

extern const uint16_t nUsb_TotalLength;
extern const uint8_t nUsb_NumInterfaces;

#endif  /* __USBDESC_H__ */
