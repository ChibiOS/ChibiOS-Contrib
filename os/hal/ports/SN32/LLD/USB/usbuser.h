/*----------------------------------------------------------------------------
 *      U S B  -  K e r n e l
 *----------------------------------------------------------------------------
 * Name:    usbuser.h
 * Purpose: USB Custom User Definitions
 * Version: V1.20
 *-----------------------------------------------------------------------------*/

#ifndef	__USBUSER_H__
#define	__USBUSER_H__

/* USB Endpoint Address */
#define USB_EP0																0x0
#define USB_EP1																0x1
#define USB_EP2																0x2
#define USB_EP3																0x3
#define USB_EP4																0x4

/* USB Interface Address */
#define USB_INTERFACE_0												0x0
#define USB_INTERFACE_1												0x1
#define USB_INTERFACE_2												0x2
#define USB_INTERFACE_3												0x3
#define USB_INTERFACE_4												0x4
#define USB_INTERFACE_5												0x5

/* USB Standard Device Requests */
#define	USB_GET_STATUS					0
#define	USB_CLEAR_FEATURE				1
#define	USB_SET_FEATURE					3
#define	USB_SET_ADDRESS					5
#define	USB_GET_DESCRIPTOR			6
#define	USB_SET_DESCRIPTOR			7
#define	USB_GET_CONFIGURATION		8
#define	USB_SET_CONFIGURATION		9
#define	USB_GET_INTERFACE				10
#define	USB_SET_INTERFACE				11
#define	USB_SYNCH_FRAME					12

/* bmRequestType.Dir */
#define REQUEST_HOST_TO_DEVICE		(0<<7)
#define REQUEST_DEVICE_TO_HOST		(1<<7)
#define REQUEST_DIR_MASK					(1<<7)

/* bmRequestType.Type */
#define REQUEST_STANDARD					(0<<5)
#define REQUEST_CLASS							(1<<5)
#define REQUEST_VENDOR						(2<<5)
#define REQUEST_RESERVED					(3<<5)
#define REQUEST_TYPE_MASK					(3<<5)

/* bmRequestType.Recipient */
#define REQUEST_TO_DEVICE					0
#define REQUEST_TO_INTERFACE			1
#define REQUEST_TO_ENDPOINT				2
#define REQUEST_TO_OTHER					3
#define REQUEST_MASK							3

/* USB Standard Request Codes */
#define USB_REQUEST_GET_STATUS										0
#define USB_REQUEST_CLEAR_FEATURE									1
#define USB_REQUEST_SET_FEATURE										3
#define USB_REQUEST_SET_ADDRESS										5
#define USB_REQUEST_GET_DESCRIPTOR								6
#define USB_REQUEST_SET_DESCRIPTOR								7
#define USB_REQUEST_GET_CONFIGURATION							8
#define USB_REQUEST_SET_CONFIGURATION							9
#define USB_REQUEST_GET_INTERFACE									10
#define USB_REQUEST_SET_INTERFACE									11
#define USB_REQUEST_SYNC_FRAME										12

/* USB GET_STATUS Bit Values */
#define USB_GETSTATUS_SELF_POWERED								0x01
#define USB_GETSTATUS_REMOTE_WAKEUP								0x02
#define USB_GETSTATUS_ENDPOINT_STALL							0x01

/* USB Standard Feature selectors */
#define USB_FEATURE_ENDPOINT_STALL								0
#define USB_FEATURE_REMOTE_WAKEUP									1

/* USB Descriptor Types */
#define USB_DEVICE_DESCRIPTOR_TYPE								1
#define USB_CONFIGURATION_DESCRIPTOR_TYPE					2
#define USB_STRING_DESCRIPTOR_TYPE								3
#define USB_INTERFACE_DESCRIPTOR_TYPE							4
#define USB_ENDPOINT_DESCRIPTOR_TYPE							5
#define USB_DEVICE_QUALIFIER_DESCRIPTOR_TYPE			6
#define USB_OTHER_SPEED_CONFIG_DESCRIPTOR_TYPE		7
#define USB_INTERFACE_POWER_DESCRIPTOR_TYPE				8
#define USB_OTG_DESCRIPTOR_TYPE										9
#define USB_DEBUG_DESCRIPTOR_TYPE									10
#define USB_INTERFACE_ASSOCIATION_DESCRIPTOR_TYPE	11
/* Wireless USB extension Descriptor Type. */
#define USB_SECURITY_TYPE													12
#define USB_KEY_TYPE															13
#define USB_ENCRIPTION_TYPE												14
#define USB_BOS_TYPE															15
#define USB_DEVICE_CAPABILITY_TYPE								16
#define USB_WIRELESS_ENDPOINT_COMPANION_TYPE			17



extern	void	USB_StandardRequest(void);
extern	void	USB_HIDRequest(void);
extern	void	USB_TableTransmit(void);
extern	void	USB_StandardVar_Init(void);

extern	void	USB_GetStatusEvent(void);
extern	void	USB_ClearFeatureEvent(void);
extern	void	USB_SetFeatureEvent(void);
extern	void	USB_SetAddressEvent(void);
extern	void	USB_GetDescriptorEvent(void);
extern	void	USB_SetDescriptorEvent(void);
extern	void	USB_GetConfigurationEvent(void);
extern	void	USB_SetConfigurationEvent(void);
extern	void	USB_GetInterfaceEvent(void);
extern	void	USB_SetInterfaceEvent(void);
extern	void	USB_SynchFrameEvent(void);

extern	void USB_EP0InEvent(void);
extern	void USB_EP0OutEvent(void);

extern uint32_t	USB_Comb_Bytetoword	(uint8_t	data0, uint8_t	data1, uint8_t	data2, uint8_t	data3);



#endif  /* __USBUSER_H__ */
