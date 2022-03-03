/****************************************************************************
 ****************************************************************************
****************************************************************************/
#ifndef __USBHW_H__
#define __USBHW_H__

/* USB Interrupt Enable Bit Definitions <USB_INTEN> */
#define mskEP1_NAK_EN               (0x1<<0)
#define mskEP2_NAK_EN               (0x1<<1)
#define mskEP3_NAK_EN               (0x1<<2)
#define mskEP4_NAK_EN               (0x1<<3)
#define mskEP5_NAK_EN               (0x1<<4)
#define mskEP6_NAK_EN               (0x1<<5)
#define mskEPnACK_EN                (0x1<<6)

#define mskBUSWK_IE                 (0x1<<28)
#define mskUSB_IE                   (0x1<<29)
#define mskUSB_SOF_IE               (0x1<<30)
#define mskBUS_IE                   (0x1U<<31)

/* USB Interrupt Event Status Bit Definitions <USB_INSTS/USB_INSTSC> */
#define mskEP1_NAK                  (0x1<<0)
#define mskEP2_NAK                  (0x1<<1)
#define mskEP3_NAK                  (0x1<<2)
#define mskEP4_NAK                  (0x1<<3)
#define mskEP5_NAK                  (0x1<<4)
#define mskEP6_NAK                  (0x1<<5)

#define mskEP1_ACK                  (0x1<<8)
#define mskEP2_ACK                  (0x1<<9)
#define mskEP3_ACK                  (0x1<<10)
#define mskEP4_ACK                  (0x1<<11)
#define mskEP5_ACK                  (0x1<<12)
#define mskEP6_ACK                  (0x1<<13)


#define mskERR_TIMEOUT              (0x1<<17)
#define mskERR_SETUP                (0x1<<18)
#define mskEP0_OUT_STALL            (0x1<<19)
#define mskEP0_IN_STALL             (0x1<<20)
#define mskEP0_OUT                  (0x1<<21)
#define mskEP0_IN                   (0x1<<22)
#define mskEP0_SETUP                (0x1<<23)
#define mskEP0_PRESETUP             (0x1<<24)
#define mskBUS_WAKEUP               (0x1<<25)
#define mskUSB_SOF                  (0x1<<26)
#define mskBUS_RESUME               (0x1<<29)
#define mskBUS_SUSPEND              (0x1<<30)
#define mskBUS_RESET                (0x1U<<31)

/* USB Device Address Bit Definitions <USB_ADDR> */
#define mskUADDR                    (0x7F<<0)

/* USB Configuration Bit Definitions <USB_CFG> */
#define mskEP1_DIR                  (0x1<<0)
#define mskEP2_DIR                  (0x1<<1)
#define mskEP3_DIR                  (0x1<<2)
#define mskEP4_DIR                  (0x1<<3)
#define mskEP5_DIR                  (0x1<<4)
#define mskEP6_DIR                  (0x1<<5)

#define mskDIS_PDEN                 (0x1<<26)
#define mskESD_EN                   (0x1<<27)
#define mskSIE_EN                   (0x1<<28)
#define mskDPPU_EN                  (0x1<<29)
#define mskPHY_EN                   (0x1<<30)
#define mskVREG33_EN                (0x1U<<31)

/* USB Signal Control Bit Definitions <USB_SGCTL> */
#define mskBUS_DRVEN                (0x1<<2)
#define mskBUS_DPDN_STATE           (0x3<<0)
#define mskBUS_J_STATE              (0x2<<0)        // D+ = 1, D- = 0
#define mskBUS_K_STATE              (0x1<<0)        // D+ = 0, D- = 1
#define mskBUS_SE0_STATE            (0x0<<0)        // D+ = 0, D- = 0
#define mskBUS_SE1_STATE            (0x3<<0)        // D+ = 1, D- = 1
#define mskBUS_IDLE_STATE           mskBUS_J_STATE

/* USB Configuration Bit Definitions <USB_EPnCTL> */
#define mskEPn_CNT                  (0x1FF<<0)
#define mskEP0_OUT_STALL_EN         (0x1<<27)
#define mskEP0_IN_STALL_EN          (0x1<<28)
#define mskEPn_ENDP_STATE           (0x3<<29)
#define mskEPn_ENDP_STATE_ACK       (0x1<<29)
#define mskEPn_ENDP_STATE_NAK       (0x0<<29)
#define mskEPn_ENDP_STATE_STALL     (0x3<<29)
#define mskEPn_ENDP_EN              (0x1U<<31)

/* USB Endpoint Data Toggle Bit Definitions <USB_EPTOGGLE> */
#define mskEP1_CLEAR_DATA0          (0x1<<0)
#define mskEP2_CLEAR_DATA0          (0x1<<1)
#define mskEP3_CLEAR_DATA0          (0x1<<2)
#define mskEP4_CLEAR_DATA0          (0x1<<3)

/* USB Endpoint n Buffer Offset Bit Definitions <USB_EPnBUFOS> */
#define mskEPn_OFFSET               (0x1FF<<0)

/* USB Frame Number Bit Definitions <USB_FRMNO> */
#define mskFRAME_NO                 (0x7FF<<0)

/* Rx & Tx Packet Length Definitions */
#define PKT_LNGTH_MASK              0x000003FF

/* nUsb_Status Register Definitions */
#define mskBUSRESET                 (0x1<<0)
#define mskBUSSUSPEND               (0x1<<1)
#define mskBUSRESUME                (0x1<<2)
#define mskREMOTEWAKEUP             (0x1<<3)
#define mskSETCONFIGURATION0CMD     (0x1<<4)
#define mskSETADDRESS               (0x1<<5)
#define mskSETADDRESSCMD            (0x1<<6)
#define mskREMOTE_WAKEUP            (0x1<<7)
#define mskDEV_FEATURE_CMD          (0x1<<8)
#define mskSET_REPORT_FLAG          (0x1<<9)
#define mskPROTOCOL_GET_REPORT      (0x1<<10)
#define mskPROTOCOL_SET_IDLE        (0x1<<11)
#define mskPROTOCOL_ARRIVAL         (0x1<<12)
#define mskSET_REPORT_DONE          (0x1<<13)
#define mskNOT_8BYTE_ENDDING        (0x1<<14)
#define mskSETUP_OUT                (0x1<<15)
#define mskSETUP_IN                 (0x1<<16)
#define mskINITREPEAT               (0x1<<17)
#define mskREMOTE_WAKEUP_ACT        (0x1<<18)

/***************************************/

#endif  /* __USBHW_H__ */
