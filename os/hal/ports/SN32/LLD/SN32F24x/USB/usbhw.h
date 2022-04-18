/****************************************************************************
 ****************************************************************************
****************************************************************************/
#ifndef __USBHW_H__
#define __USBHW_H__

//** USB Remote Wakeup I/O Define
//** USB Remote Wakeup I/O Port Define, Default P1.5
#define	REMOTE_WAKEUP_IO_P0			DISABLE
#define	REMOTE_WAKEUP_IO_P1			ENABLE
#define	REMOTE_WAKEUP_IO_P2			DISABLE
#define	REMOTE_WAKEUP_IO_P3			DISABLE

//** USB Remote Wakeup I/O Bit Define
#define	REMOTE_WAKEUP_IO_P0_BIT		0x0000
#define	REMOTE_WAKEUP_IO_P1_BIT		0x0020
#define	REMOTE_WAKEUP_IO_P2_BIT		0x0000
#define	REMOTE_WAKEUP_IO_P3_BIT		0x0000

//** USB EPn NAK interrupt
#define	EP1_NAK_IE					DISABLE
#define	EP2_NAK_IE					DISABLE
#define	EP3_NAK_IE					DISABLE
#define	EP4_NAK_IE					DISABLE

//** USB SOF interrupt
#define	SOF_IE						DISABLE

/* AHB Clock Enable register <SYS1_AHBCLKEN> */
#define	mskP0CLK_EN					(0x1<<0)
#define	mskP1CLK_EN					(0x1<<1)
#define	mskP2CLK_EN					(0x1<<2)
#define	mskP3CLK_EN					(0x1<<3)
#define	mskUSBCLK_EN				(0x1<<4)
#define	mskCT16B0CLK_EN				(0x1<<6)
#define	mskCT16B1CLK_EN				(0x1<<7)
#define	mskADCCLK_EN				(0x1<<11)
#define	mskSPI0CLK_EN				(0x1<<12)
#define	mskUART0CLK_EN				(0x1<<16)
#define	mskUART1CLK_EN				(0x1<<17)
#define	mskUART2CLK_EN				(0x1<<18)
#define	mskI2C0CLK_EN				(0x1<<21)
#define	mskWDTCLK_EN				(0x1<<24)

/* USB Interrupt Enable Bit Definitions <USB_INTEN> */
#define mskEP1_NAK_EN				(0x1<<0)
#define mskEP2_NAK_EN				(0x1<<1)
#define	mskEP3_NAK_EN				(0x1<<2)
#define mskEP4_NAK_EN				(0x1<<3)
#define mskEP5_NAK_EN				(0x1<<4)
#define	mskEP6_NAK_EN				(0x1<<5)
#define mskUSB_BUSWK_IE             (0x1<<28)
#define mskUSB_IE					(0x1<<29)
#define mskUSB_SOF_IE				(0x1<<30)
#define	mskBUS_IE					(0x1U<<31)

/* USB Interrupt Event Status Bit Definitions <USB_INSTS/USB_INSTSC> */
#define mskEP1_NAK					(0x1<<0)
#define mskEP2_NAK					(0x1<<1)
#define mskEP3_NAK					(0x1<<2)
#define mskEP4_NAK					(0x1<<3)
#define mskEP5_NAK					(0x1<<4)
#define mskEP6_NAK					(0x1<<5)
#define mskEP1_ACK					(0x1<<8)
#define mskEP2_ACK					(0x1<<9)
#define mskEP3_ACK					(0x1<<10)
#define mskEP4_ACK					(0x1<<11)
#define mskEP5_ACK					(0x1<<12)
#define mskEP6_ACK					(0x1<<13)
#define mskERR_TIMEOUT			    (0x1<<17)
#define mskERR_SETUP				(0x1<<18)
#define mskEP0_OUT_STALL		    (0x1<<19)
#define mskEP0_IN_STALL			    (0x1<<20)
#define	mskEP0_OUT					(0x1<<21)
#define mskEP0_IN					(0x1<<22)
#define mskEP0_SETUP				(0x1<<23)
#define mskEP0_PRESETUP			    (0x1<<24)
#define mskBUS_WAKEUP				(0x1<<25)
#define	mskUSB_SOF					(0x1<<26)
#define mskBUS_RESUME				(0x1<<29)
#define mskBUS_SUSPEND			    (0x1<<30)
#define	mskBUS_RESET				(0x1U<<31)

/* USB Device Address Bit Definitions <USB_ADDR> */
#define mskUADDR					(0x7F<<0)

/* USB Configuration Bit Definitions <USB_CFG> */
#define mskEP1_DIR					(0x1<<0)
#define mskEP2_DIR					(0x1<<1)
#define mskEP3_DIR					(0x1<<2)
#define mskEP4_DIR					(0x1<<3)
#define mskEP5_DIR					(0x1<<4)
#define mskEP6_DIR					(0x1<<5)
#define mskEP2_ISO					(0x1<<9)
#define mskEP3_ISO					(0x1<<10)
#define mskEP4_ISO					(0x1<<11)
#define mskEP5_ISO					(0x1<<12)
#define mskEP6_ISO					(0x1<<13)
#define mskVREG33DIS_EN			    (0x1<<31)
#define	mskUSBRAM_EN				(0x1<<25)
#define mskFLTDET_PUEN_DISABLE	    (0x1<<26) // FixMe ? // #define mskDIS_PDEN					(0x1<<26)
#define mskESD_EN					(0x1<<27)
#define	mskSIE_EN					(0x1<<28)
#define mskDPPU_EN				 	(0x1<<29)
#define mskPHY_EN					(0x1<<30)
#define	mskVREG33_EN				(0x1U<<31)

/* USB Signal Control Bit Definitions <USB_SGCTL> */
#define mskBUS_DRVEN				(0x1<<2)
#define mskBUS_DPDN_STATE			(0x3<<0)
#define mskBUS_J_STATE				(0x2<<0)		// D+ = 1, D- = 0
#define mskBUS_K_STATE				(0x1<<0)		// D+ = 0, D- = 1
#define mskBUS_SE0_STATE			(0x0<<0)		// D+ = 0, D- = 0
#define mskBUS_SE1_STATE			(0x3<<0)		// D+ = 1, D- = 1
#define mskBUS_IDLE_STATE			mskBUS_J_STATE

/* USB Configuration Bit Definitions <USB_EPnCTL> */
#define mskEPn_CNT					(0x1FF<<0)
#define mskEP0_OUT_STALL_EN			(0x1<<27)
#define mskEP0_IN_STALL_EN			(0x1<<28)
#define mskEPn_ENDP_STATE			(0x3<<29)
#define mskEPn_ENDP_STATE_ACK		(0x1<<29)
#define mskEPn_ENDP_STATE_NAK		(0x0<<29)
#define mskEPn_ENDP_STATE_STALL		(0x3<<29)
#define mskEPn_ENDP_EN				(0x1U<<31)

/* USB Endpoint Data Toggle Bit Definitions <USB_EPTOGGLE> */
#define mskEP1_CLEAR_DATA0			(0x1<<0)
#define mskEP2_CLEAR_DATA0			(0x1<<1)
#define mskEP3_CLEAR_DATA0			(0x1<<2)
#define mskEP4_CLEAR_DATA0			(0x1<<3)
#define mskEP5_CLEAR_DATA0			(0x1<<4)
#define mskEP6_CLEAR_DATA0			(0x1<<5)

/* USB Endpoint n Buffer Offset Bit Definitions <USB_EPnBUFOS> */
#define mskEPn_OFFSET				(0x1FF<<0)

/* USB Frame Number Bit Definitions <USB_FRMNO> */
#define mskFRAME_NO					(0x7FF<<0)

/* Rx & Tx Packet Length Definitions */
#define PKT_LNGTH_MASK				0x000003FF

/* nUsb_Status Register Definitions */
#define	mskBUSRESET					(0x1<<0)
#define	mskBUSSUSPEND				(0x1<<1)
#define	mskBUSRESUME				(0x1<<2)
#define	mskREMOTEWAKEUP				(0x1<<3)
#define	mskSETCONFIGURATION0CMD		(0x1<<4)
#define	mskSETADDRESS				(0x1<<5)
#define	mskSETADDRESSCMD			(0x1<<6)
#define	mskREMOTE_WAKEUP			(0x1<<7)
#define	mskDEV_FEATURE_CMD			(0x1<<8)
#define	mskSET_REPORT_FLAG			(0x1<<9)
#define	mskPROTOCOL_GET_REPORT		(0x1<<10)
#define	mskPROTOCOL_SET_IDLE		(0x1<<11)
#define	mskPROTOCOL_ARRIVAL			(0x1<<12)
#define	mskSET_REPORT_DONE			(0x1<<13)
#define	mskNOT_8BYTE_ENDDING		(0x1<<14)
#define	mskSETUP_OUT				(0x1<<15)
#define	mskSETUP_IN					(0x1<<16)
#define	mskINITREPEAT				(0x1<<17)
#define	mskREMOTE_WAKEUP_ACT		(0x1<<18)

//ISP KERNEL MODE
#define	RETURN_KERNEL_0 0x5AA555AA
#define	RETURN_KERNEL_1 0xCC3300FF
/*********Marco function***************/

//USB device address set
#define __USB_SETADDRESS(addr)		(SN_USB->ADDR = addr)
//USB INT status register clear
#define	__USB_CLRINSTS(Clrflag)		(SN_USB->INSTSC = Clrflag)
//USB EP0_IN token set STALL
#define	__USB_EP0INSTALL_EN			(SN_USB->EP0CTL |= mskEP0_IN_STALL_EN)
//USB EP0_OUT token set STALL
#define	__USB_EP0OUTSTALL_EN		(SN_USB->EP0CTL |= mskEP0_OUT_STALL_EN)
//USB bus driver J state
#define	__USB_JSTATE_DRIVER			(SN_USB->SGCTL = (mskBUS_DRVEN|mskBUS_J_STATE))
//USB bus driver K state
#define	__USB_KSTATE_DRIVER			(SN_USB->SGCTL = (mskBUS_DRVEN|mskBUS_K_STATE))
//USB PHY set enable
#define	__USB_PHY_ENABLE			(SN_USB->CFG |= (mskESD_EN|mskPHY_EN))
//USB PHY set Disable
#define	__USB_PHY_DISABLE			(SN_USB->CFG &= ~(mskESD_EN|mskPHY_EN))

/***************************************/

/* USB SRAM */
#define USB_SRAM_EP0_W0 *((uint32_t *)&SN_USB->SRAM+0)		// EP0 SRAM	Byte 0~3
#define USB_SRAM_EP0_W1 *((uint32_t *)&SN_USB->SRAM+1)		// EP0 SRAM	Byte 4~7
#define USB_SRAM_EP0_W2 *((uint32_t *)&SN_USB->SRAM+2)		// EP0 SRAM	Byte 8~11
#define USB_SRAM_EP0_W3 *((uint32_t *)&SN_USB->SRAM+3)		// EP0 SRAM	Byte 12~15
#define USB_SRAM_EP0_W4 *((uint32_t *)&SN_USB->SRAM+4)		// EP0 SRAM	Byte 16~19
#define USB_SRAM_EP0_W5 *((uint32_t *)&SN_USB->SRAM+5)		// EP0 SRAM	Byte 20~23
#define USB_SRAM_EP0_W6 *((uint32_t *)&SN_USB->SRAM+6)		// EP0 SRAM	Byte 24~27
#define USB_SRAM_EP0_W7 *((uint32_t *)&SN_USB->SRAM+7)		// EP0 SRAM	Byte 28~31
#define USB_SRAM_EP0_W8 *((uint32_t *)&SN_USB->SRAM+8)		// EP0 SRAM	Byte 32~35
#define USB_SRAM_EP0_W9 *((uint32_t *)&SN_USB->SRAM+9)		// EP0 SRAM	Byte 36~39
#define USB_SRAM_EP0_W10 *((uint32_t *)&SN_USB->SRAM+10)	// EP0 SRAM	Byte 40~43
#define USB_SRAM_EP0_W11 *((uint32_t *)&SN_USB->SRAM+11)	// EP0 SRAM	Byte 44~47
#define USB_SRAM_EP0_W12 *((uint32_t *)&SN_USB->SRAM+12)	// EP0 SRAM	Byte 48~51
#define USB_SRAM_EP0_W13 *((uint32_t *)&SN_USB->SRAM+13)	// EP0 SRAM	Byte 52~55
#define USB_SRAM_EP0_W14 *((uint32_t *)&SN_USB->SRAM+14)	// EP0 SRAM	Byte 56~59
#define USB_SRAM_EP0_W15 *((uint32_t *)&SN_USB->SRAM+15)	// EP0 SRAM	Byte 60~63

/* TODO: orgaize better since this is MCU dependent:
 * 240b has 1+4 EPs/256 Bytes USB SRAM
 * 240 has  1+6 EPs/512 Bytes USB SRAM
 * 260 has  1+4 EPs/256 Bytes USB SRAM
 * */
// USB EPn Buffer Offset Register
#define EP1_BUFFER_OFFSET_VALUE                 0x40
#define EP2_BUFFER_OFFSET_VALUE                 0x80
#define EP3_BUFFER_OFFSET_VALUE                 0xC0
#define EP4_BUFFER_OFFSET_VALUE                 0x100
#define	EP5_BUFFER_OFFSET_VALUE					0x140
#define	EP6_BUFFER_OFFSET_VALUE					0x180

/* USB Endpoint Max Packet Size */
#define USB_EP0_PACKET_SIZE                     64  // only 8, 64
#define USB_EP1_PACKET_SIZE                     0x40
#define USB_EP2_PACKET_SIZE                     0x40
#define USB_EP3_PACKET_SIZE                     0x20
#define USB_EP4_PACKET_SIZE                     0x20
#define USB_EP5_PACKET_SIZE                     0x20
#define USB_EP6_PACKET_SIZE                     0x20

/* USB Endpoint Direction */
#define USB_DIRECTION_OUT                       0
#define USB_DIRECTION_IN                        1

/* USB Endpoint Address */
#define USB_EP0                                 0x0
#define USB_EP1                                 0x1
#define USB_EP2                                 0x2
#define USB_EP3                                 0x3
#define USB_EP4                                 0x4
#define USB_EP5                                 0x5
#define USB_EP6                                 0x6

extern volatile uint32_t wUSB_EPnOffset[];
extern volatile uint32_t wUSB_EPnMaxPacketSize[];

/* USB Hardware Functions */
extern void USB_Init(void);
extern void	USB_ClrEPnToggle(uint32_t wEPNum);
extern void USB_EPnDisable(uint32_t	wEPNum);
extern void USB_EPnNak(uint32_t	wEPNum);
extern void	USB_EPnAck(uint32_t	wEPNum, uint8_t	bBytecnt);
extern void	USB_EPnStall(uint32_t wEPNum);
extern _Bool USB_EPnEnabled(uint32_t wEPNum);
extern _Bool USB_EPnStalled(uint32_t wEPNum);

extern void USB_RemoteWakeUp(void);
extern void USB_DelayJstate(void);
extern void USB_DelayKstate(void);
extern void USB_EPnBufferOffset(uint32_t wEPNum, uint32_t wAddr);

/* USB IRQ Functions*/
extern void USB_ResetEvent(void);
extern void USB_WakeupEvent(void);

#endif  /* __USBHW_H__ */