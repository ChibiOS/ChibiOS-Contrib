/*----------------------------------------------------------------------------
 *      U S B  -  K e r n e l
 *----------------------------------------------------------------------------
 * Name:    usbhw.c
 * Purpose: USB Custom User Module
 * Version: V1.01
 * Date:	2017/07
 *------------------------------------------------------------------------------*/
#include <SN32F240.h>
#include "SN32F200_Def.h"

#include "usbhw.h"
#include "usbsystem.h"

volatile uint32_t wUSB_EPnOffset[7];
volatile uint32_t wUSB_EPnMaxPacketsize[7];

/*****************************************************************************
* Function		: USB_Init
* Description	: 1. setting IDLE_TIME, REPORT_PROTOCOL, S_USB_EP0setupdata.wUSB_Status
*				  2. set EP1~EP6 FIFO RAM address.
*				  3. save EP1~EP6 FIFO RAM point address.
*				  4. save EP1~EP6 Package Size.
*				  5. Enable USB function and setting EP1~EP6 Direction.
*				  6. NEVER REMOVE !! USB D+/D- Dischage
*				  7. Enable USB PHY and USB interrupt.
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USB_Init	(void)
{
    volatile uint32_t	*pRam;
    uint32_t 	wTmp, i;

    /* Initialize clock and Enable USB PHY. */
    USB_SystemInit(); 		   // enable System,PLL,EHS XTAL by user setting
    SN_SYS1->AHBCLKEN |= 0x02; // Enable USBCLKEN
    __USB_PHY_ENABLE; 		   // enable ESD_EN & PHY_EN

    /* Initialize USB EP1~EP6 RAM address base on 64-bytes. */
    USB_EPnBufferOffset(1,EP1_BUFFER_OFFSET_VALUE);
    USB_EPnBufferOffset(2,EP2_BUFFER_OFFSET_VALUE);
    USB_EPnBufferOffset(3,EP3_BUFFER_OFFSET_VALUE);
    USB_EPnBufferOffset(4,EP4_BUFFER_OFFSET_VALUE);
    USB_EPnBufferOffset(5,EP5_BUFFER_OFFSET_VALUE);
    USB_EPnBufferOffset(6,EP6_BUFFER_OFFSET_VALUE);

    /* Initialize EP1~EP6 RAM point address to array(wUSB_EPnOffset).*/
    pRam = &wUSB_EPnOffset[0];
    *(pRam+0) = (uint32_t)(&USB_SRAM_EP0_W0) + EP1_BUFFER_OFFSET_VALUE;
    *(pRam+1) = (uint32_t)(&USB_SRAM_EP0_W0) + EP2_BUFFER_OFFSET_VALUE;
    *(pRam+2) = (uint32_t)(&USB_SRAM_EP0_W0) + EP3_BUFFER_OFFSET_VALUE;
    *(pRam+3) = (uint32_t)(&USB_SRAM_EP0_W0) + EP4_BUFFER_OFFSET_VALUE;
    *(pRam+4) = (uint32_t)(&USB_SRAM_EP0_W0) + EP5_BUFFER_OFFSET_VALUE;
    *(pRam+5) = (uint32_t)(&USB_SRAM_EP0_W0) + EP6_BUFFER_OFFSET_VALUE;

    /* Initialize EP0~EP6 package size to array(wUSB_EPnPacketsize).*/
    pRam = &wUSB_EPnMaxPacketsize[0];
    *(pRam+0) = USB_EP0_PACKET_SIZE;
    *(pRam+1) = USB_EP1_PACKET_SIZE;
    *(pRam+2) = USB_EP2_PACKET_SIZE;
    *(pRam+3) = USB_EP3_PACKET_SIZE;
    *(pRam+4) = USB_EP4_PACKET_SIZE;
    *(pRam+5) = USB_EP5_PACKET_SIZE;
    *(pRam+6) = USB_EP6_PACKET_SIZE;

    /* Enable the USB Interrupt */
    SN_USB->INTEN = (mskBUS_IE|mskUSB_IE|mskUSB_BUSWK_IE);
	SN_USB->INTEN |= mskEP1_NAK_EN;
	SN_USB->INTEN |= mskEP2_NAK_EN;
	SN_USB->INTEN |= mskEP3_NAK_EN;
	SN_USB->INTEN |= mskEP4_NAK_EN;
	SN_USB->INTEN |= mskEP5_NAK_EN;
	SN_USB->INTEN |= mskEP6_NAK_EN;
	SN_USB->INTEN |= mskUSB_SOF_IE;

	NVIC_ClearPendingIRQ(USB_IRQn);
	NVIC_EnableIRQ(USB_IRQn);
	
    /* BUS_DRVEN = 0, BUS_DP = 1, BUS_DN = 0 */
    SN_USB->SGCTL = mskBUS_J_STATE;
    /* VREG33_EN = 1, PHY_EN = 1, DPPU_EN = 1, SIE_EN = 1, USBRAM_EN = 1, FLTDET_PUEN = 1 */
    wTmp = (mskVREG33_EN|mskPHY_EN|mskDPPU_EN|mskSIE_EN|mskESD_EN|mskUSBRAM_EN|mskVREG33DIS_EN|mskFLTDET_PUEN_DISABLE);

    //!!NEVER REMOVE!!!
    SN_USB->CFG = wTmp;
    for (i = 0; i < DISCHARE_DELAY; i++);
    SN_USB->CFG = (wTmp&(~mskVREG33DIS_EN))|mskDPPU_EN;
    //!!NEVER REMOVE!!!

    SN_USB->PHYPRM = (0x01U<<31);
    return;
}

/*****************************************************************************
* Function		: USB_ClrEPnToggle
* Description	: USB Clear EP1~EP6 toggle bit to DATA0
*				  write 1: toggle bit Auto.
*				  write 0: clear EPn toggle bit to DATA0
* Input			: hwEPNum ->EP1~EP6
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USB_ClrEPnToggle (uint32_t hwEPNum)
{
	SN_USB->EPTOGGLE &= ~(0x1<<hwEPNum);
}

/*****************************************************************************
* Function		: USB_EPnDisable
* Description	: Disable EP1~EP6
* Input			: wEPNum
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USB_EPnDisable (uint32_t wEPNum)
{
    volatile uint32_t *pEPn_ptr;
    if(wEPNum > USB_EP6)
        return;
    pEPn_ptr = &SN_USB->EP0CTL + wEPNum;
    *pEPn_ptr = 0; //** SET DISABLE. No handshake IN/OUT token.
}

/*****************************************************************************
* Function		: USB_EPnNak
* Description	: SET EP1~EP6 is NAK.
*				  For IN will handshake NAK to IN token.
*				  For OUT will handshake NAK to OUT token.
* Input			: wEPNum
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USB_EPnNak (uint32_t wEPNum)
{
    volatile uint32_t *pEPn_ptr;
    if(wEPNum > USB_EP6)
        return;
    pEPn_ptr = &SN_USB->EP0CTL + wEPNum;
    *pEPn_ptr = mskEPn_ENDP_EN;	//** SET NAK
}

/*****************************************************************************
* Function		: USB_EPnAck
* Description	: SET EP1~EP6 is ACK.
*				  For IN will handshake bBytent to IN token.
*				  For OUT will handshake ACK to OUT token.
* Input			: wEPNum:EP1~EP6.
*				  bBytecnt: Byte Number of Handshake.
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USB_EPnAck (uint32_t wEPNum, uint8_t bBytecnt)
{
    volatile uint32_t *pEPn_ptr;
    if (wEPNum > USB_EP6)
        return;
    pEPn_ptr = &SN_USB->EP0CTL + wEPNum;
    *pEPn_ptr = (mskEPn_ENDP_EN|mskEPn_ENDP_STATE_ACK|bBytecnt);
}

/*****************************************************************************
* Function		: USB_EPnAck
* Description	: SET EP1~EP6 is STALL. For IN will handshake STALL to IN token.
*				  For OUT will handshake STALL to OUT token.
* Input			: wEPNum:EP1~EP6.
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void USB_EPnStall (uint32_t	wEPNum)
{
    volatile uint32_t *pEPn_ptr;
    if(wEPNum > USB_EP6) //wEPNum != EP0~EP6
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
* Function      : USB_EPnEnabled
* Description   : check if EP0~EP4 enabled or not
* Input    : wEPNum:EP0~EP4.
* Output   : None
* Return   : true - enabled/false - disabled
* Note     : None
*****************************************************************************/
_Bool USB_EPnEnabled(uint32_t wEPNum)
{
    volatile uint32_t *pEPn_ptr;
    if(wEPNum > USB_EP6) //** wEPNum != EP0~EP6
        return 0;
    pEPn_ptr = &SN_USB->EP0CTL + wEPNum;
    return (((*pEPn_ptr) & mskEPn_ENDP_EN) == mskEPn_ENDP_EN);
}

/*****************************************************************************
* Function      : USB_EPnStalled
* Description   : GET EP0~EP4 state.
* Input    : wEPNum:EP0~EP4.
* Output   : None
* Return   : mskEPn_ENDP_STATE
* Note     : None
*****************************************************************************/
_Bool USB_EPnStalled(uint32_t wEPNum)
{
    volatile uint32_t *pEPn_ptr;
    if(wEPNum > USB_EP6) //** wEPNum != EP0~EP6
        return 0;
    pEPn_ptr = &SN_USB->EP0CTL + wEPNum;
    return (((*pEPn_ptr) & mskEPn_ENDP_STATE) == mskEPn_ENDP_STATE_STALL);
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
	__USB_JSTATE_DRIVER; //** J state ;Full speed D+ = 1, D- = 0
	USB_DelayJstate();
	__USB_KSTATE_DRIVER; //** K state ;Full speed D+ = 0, D- = 1
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
void USB_DelayJstate()
{
    uint32_t i;
    for (i = 0; i < 300; i++)
        ;  // delay 180us
}

/*****************************************************************************
 * Function		: USB_DelayKstate
 * Description	: For K state delay. about 14 ~ 14.5ms
 * Input				: None
 * Output			: None
 * Return			: None
 * Note				: None
 *****************************************************************************/
void USB_DelayKstate()
{
    uint32_t i;
    for (i = 0; i < K_STATE_DELAY; i++)
        ;  // require delay 1ms ~ 15ms
}

/*****************************************************************************
* Function		: USB_EPnBufferOffset
* Description	: SET EP1~EP6 RAM point address
* Input				: wEPNum: EP1~EP6
*								wAddr of device address
* Output			: None
* Return			: None
* Note				: None
*****************************************************************************/
void USB_EPnBufferOffset(uint32_t wEPNum, uint32_t wAddr)
{
    volatile uint32_t *pEPn_ptr;
    if ((wEPNum > USB_EP0) && (wEPNum <= USB_EP6))	//wEPNum = EP1 ~ EP6
    {
        pEPn_ptr = &SN_USB->EP1BUFOS; 				// Assign point to EP1 RAM address
        *(pEPn_ptr+wEPNum-1) = wAddr;				// SET point to EPn RAM address
    }
}

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
    __USB_CLRINSTS(0xFFFFFFFF);	// Clear all USB Event status
    __USB_SETADDRESS(0);		// Set USB address = 0
    USB_EPnStall(USB_EP0);		// Set EP0 enable & INOUTSTALL

    for (wLoop=USB_EP1; wLoop<=USB_EP6; wLoop++)
        USB_EPnDisable(wLoop);	// Set EP1~EP6 disable & NAK
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
  USB_SystemInit();					// enable System,PLL,EHS XTAL by user setting
	__USB_PHY_ENABLE;				//** enable ESD_EN & PHY_EN
	__USB_CLRINSTS(mskBUS_WAKEUP);	//** Clear BUS_WAKEUP
}