/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    hal_usb_lld.c
 * @brief   PLATFORM USB subsystem low level driver source.
 *
 * @addtogroup USB
 * @{
 */

#include <SN32F240.h>
#include <string.h>
#include "hal.h"
#include "usbhw.h"

#if (HAL_USE_USB == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/
#define SN32_USB_IRQ_VECTOR    Vector44
#define SN32_USB_PMA_SIZE      256

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   USB1 driver identifier.
 */
#if (PLATFORM_USB_USE_USB1 == TRUE) || defined(__DOXYGEN__)
USBDriver USBD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

static int address;
static uint8_t nakcnt[USB_MAX_ENDPOINTS + 1] = {0, 0, 0, 0, 0, 0, 0};

/**
 * @brief   EP0 state.
 * @note    It is an union because IN and OUT endpoints are never used at the
 *          same time for EP0.
 */
static union {
  /**
   * @brief   IN EP0 state.
   */
  USBInEndpointState in;
  /**
   * @brief   OUT EP0 state.
   */
  USBOutEndpointState out;
} ep0_state;

/**
 * @brief   EP0 initialization structure.
 */
static const USBEndpointConfig ep0config = {
	USB_ENDPOINT_TYPE_CONTROL,
	_usb_ep0setup,
	_usb_ep0in,
	_usb_ep0out,
	0x40,
	0x40,
	&ep0_state.in,
	&ep0_state.out
};
void rgb_matrix_toggle(void);
void handleACK(USBDriver* usbp, usbep_t ep);
void handleNAK(USBDriver* usbp, usbep_t ep);
#if (USB_USE_WAIT == TRUE) || defined(__DOXYGEN__)
#define _usb_isr_invoke_tx_complete_cb(usbp, ep) {                          \
  (usbp)->transmitting &= ~(1 << (ep));                                     \
  osalSysLockFromISR();                                                     \
  osalThreadResumeI(&(usbp)->epc[ep]->in_state->thread, MSG_OK);            \
  osalSysUnlockFromISR();                                                   \
}
#else
#define _usb_isr_invoke_tx_complete_cb(usbp, ep) {                          \
  (usbp)->transmitting &= ~(1 << (ep));                                     \
}
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void sn32_usb_read_fifo(usbep_t ep, uint8_t *buf, size_t sz, bool intr) {
    uint32_t *pRAM = &USB_SRAM_EP0_W0;

    if (ep == 0) {
        memcpy(buf, pRAM, sz);
    } else {
        memcpy(buf, (void *)wUSB_EPnOffset[ep - 1], sz);
    }
}

static void sn32_usb_write_fifo(usbep_t ep, const uint8_t *buf, size_t sz, bool intr) {
    uint32_t *pRAM = &USB_SRAM_EP0_W0;

    if (ep == 0) {
        memcpy(pRAM, buf, sz);
    } else {
        memcpy((void *)wUSB_EPnOffset[ep - 1], buf, sz);
    }
}

void rgb_matrix_disable_noeeprom(void);
/**
 * @brief   USB shared ISR.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
static void usb_lld_serve_interrupt(USBDriver *usbp)
{
	uint32_t iwIntFlag;
    size_t n;

	//** Get Interrupt Status and clear immediately.
	iwIntFlag = SN_USB->INSTS;
    //Clear flags right away for interrupts that we dont handle, keep other untill fully handled
    SN_USB->INSTSC = 0x0007C0C0;

	if(iwIntFlag == 0)
	{
		//@20160902 add for EMC protection
		return;
	}

    if (iwIntFlag & mskBUS_WAKEUP)
    {									/* Wakeup */
        USB_WakeupEvent();
        _usb_wakeup(usbp);
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
			USB_ResetEvent();
            _usb_reset(usbp);
		}
		else if (iwIntFlag & mskBUS_SUSPEND)
		{
			/* Suspend */
			__USB_CLRINSTS(mskBUS_SUSPEND);
            _usb_suspend(usbp);
		}
		else if(iwIntFlag & mskBUS_RESUME)
		{
			/* Resume */
			__USB_CLRINSTS(mskBUS_RESUME);
            _usb_wakeup(usbp);
		}
	}
	/////////////////////////////////////////////////
	/* Device Status Interrupt (SETUP, IN, OUT) */
	/////////////////////////////////////////////////
	else if (iwIntFlag & (mskEP0_SETUP|mskEP0_IN|mskEP0_OUT|mskEP0_IN_STALL|mskEP0_OUT_STALL))
	{
        const USBEndpointConfig *epcp = usbp->epc[0];

		if (iwIntFlag & mskEP0_SETUP)
		{
			/* SETUP */
            //** keep EP0 NAK
            //USB_EPnNak(USB_EP0); //useless

			//not sure we need it here...
            //TODO: clean it up when packets are properly handled
            epcp->in_state->txcnt  = 0;
            epcp->in_state->txsize = 0;
            epcp->in_state->txlast = 0;
			epcp->out_state->rxcnt = 0;
            epcp->out_state->rxsize = 0;
            epcp->out_state->rxpkts = 0;

            _usb_isr_invoke_setup_cb(usbp, 0);
            __USB_CLRINSTS((mskEP0_SETUP|mskEP0_PRESETUP|mskEP0_OUT_STALL|mskEP0_IN_STALL));
		}
		else if (iwIntFlag & mskEP0_IN)
		{
            USBInEndpointState *isp = epcp->in_state;

			/* IN */

            // The address
            if (address) {
                SN_USB->ADDR = address;
                address = 0;
                USB_EPnStall(USB_EP0);
            }

//            USB_EPnAck(USB_EP0,0);

            isp->txcnt += isp->txlast;
            n = isp->txsize - isp->txcnt;
            if (n > 0) {
                /* Transfer not completed, there are more packets to send.*/
                if (n > epcp->in_maxsize)
                    n = epcp->in_maxsize;

                /* Writes the packet from the defined buffer.*/
                isp->txbuf += isp->txlast;
                isp->txlast = n;

                sn32_usb_write_fifo(0, isp->txbuf, n, true);

                USB_EPnAck(USB_EP0, n);
            }
            else
            {
                //USB_EPnNak(USB_EP0); //not needed

                _usb_isr_invoke_in_cb(usbp, 0);
            }
            __USB_CLRINSTS(mskEP0_IN);

        }
        else if (iwIntFlag & mskEP0_OUT)
        {
            USBOutEndpointState *osp = epcp->out_state;
            /* OUT */

			n = SN_USB->EP0CTL & mskEPn_CNT;
            if (n > epcp->out_maxsize)
                n = epcp->out_maxsize;

            //Just being paranoid here. keep here while debugging EP handling issue
            //TODO: clean it up when packets are properly handled
            if (epcp->out_state->rxsize >= n) {
                //we are ok to copy n bytes to buf
                sn32_usb_read_fifo(USB_EP0, osp->rxbuf, n, true);
                epcp->out_state->rxsize -= n;
            }
            else if (epcp->out_state->rxsize > 0) {
                //we dont have enough buffer to receive n bytes
                //copy only size availabe on buffer
                n = epcp->out_state->rxsize;
                sn32_usb_read_fifo(USB_EP0, osp->rxbuf, n, true);
                epcp->out_state->rxsize -= n;
            }
            else {
                //well buffer is 0 size. strange. do nothing.
                n = 0;
            }

            epcp->out_state->rxbuf += n;
            epcp->out_state->rxcnt += n;
            if (epcp->out_state->rxpkts > 0) {
                epcp->out_state->rxpkts -= 1;
            }

            if (n < epcp->out_maxsize || epcp->out_state->rxpkts == 0)
            {
                //done with transfer
                //USB_EPnNak(USB_EP0); //useless mcu resets it anyways
                _usb_isr_invoke_out_cb(usbp, 0);
            }
            else {
                //more to receive
                USB_EPnAck(USB_EP0, 0);
            }
            __USB_CLRINSTS(mskEP0_OUT);

        }
        else if (iwIntFlag & (mskEP0_IN_STALL|mskEP0_OUT_STALL))
        {
            /* EP0_IN_OUT_STALL */
            USB_EPnStall(USB_EP0);
            SN_USB->INSTSC = (mskEP0_IN_STALL|mskEP0_OUT_STALL);
		}
	}
	/////////////////////////////////////////////////
	/* Device Status Interrupt (EPnACK) 					 */
	/////////////////////////////////////////////////
	else if (iwIntFlag & (mskEP6_ACK|mskEP5_ACK|mskEP4_ACK|mskEP3_ACK|mskEP2_ACK|mskEP1_ACK))
	{
        // Determine the interrupting endpoint, direction, and clear the interrupt flag
        if(iwIntFlag & mskEP1_ACK)
        {
            handleACK(usbp, USB_EP1);
            __USB_CLRINSTS(mskEP1_ACK);
        }
        if(iwIntFlag & mskEP2_ACK)
        {
            handleACK(usbp, USB_EP2);
            __USB_CLRINSTS(mskEP2_ACK);
        }
        if(iwIntFlag & mskEP3_ACK)
        {
            handleACK(usbp, USB_EP3);
            __USB_CLRINSTS(mskEP3_ACK);
        }
        if(iwIntFlag & mskEP4_ACK)
        {
            handleACK(usbp, USB_EP4);
            __USB_CLRINSTS(mskEP4_ACK);
        }
        if(iwIntFlag & mskEP5_ACK)
        {
            handleACK(usbp, USB_EP5);
            __USB_CLRINSTS(mskEP5_ACK);
        }
        if(iwIntFlag & mskEP6_ACK)
        {
            handleACK(usbp, USB_EP6);
            __USB_CLRINSTS(mskEP6_ACK);
        }
    }
	else if (iwIntFlag & (mskEP6_NAK|mskEP5_NAK|mskEP4_NAK|mskEP3_NAK|mskEP2_NAK|mskEP1_NAK))
	{
        // Determine the interrupting endpoint, direction, and clear the interrupt flag
		if (iwIntFlag & mskEP1_NAK)
		{
            handleNAK(usbp, USB_EP1);
            __USB_CLRINSTS(mskEP1_NAK);
		}
		if (iwIntFlag & mskEP2_NAK)
		{
            handleNAK(usbp, USB_EP2);
            __USB_CLRINSTS(mskEP2_NAK);
		}
		if (iwIntFlag & mskEP3_NAK)
		{
            handleNAK(usbp, USB_EP3);
            __USB_CLRINSTS(mskEP3_NAK);
		}
		if (iwIntFlag & mskEP4_NAK)
		{
            handleNAK(usbp, USB_EP4);
            __USB_CLRINSTS(mskEP4_NAK);
		}
		if (iwIntFlag & mskEP5_NAK)
		{
            handleNAK(usbp, USB_EP5);
            __USB_CLRINSTS(mskEP5_NAK);
		}
		if (iwIntFlag & mskEP6_NAK)
		{
            handleNAK(usbp, USB_EP6);
            __USB_CLRINSTS(mskEP6_NAK);
		}
    }

    /////////////////////////////////////////////////
    /* Device Status Interrupt (SOF)               */
    /////////////////////////////////////////////////
    if ((iwIntFlag & mskUSB_SOF) && (SN_USB->INTEN & mskUSB_SOF_IE))
    {
        /* SOF */
        _usb_isr_invoke_sof_cb(usbp);
        __USB_CLRINSTS(mskUSB_SOF);
    }
}

void handleACK(USBDriver* usbp, usbep_t ep) {
    uint8_t out = 0;
    uint8_t cnt = 0;
    size_t n;

    if(ep == USB_EP1)
    {
        out = ( SN_USB->CFG & mskEP1_DIR ) == mskEP1_DIR;
        cnt = SN_USB->EP1CTL & mskEPn_CNT;
    }
    else if(ep == USB_EP2)
    {
        out = ( SN_USB->CFG & mskEP2_DIR ) == mskEP2_DIR;
        cnt = SN_USB->EP2CTL & mskEPn_CNT;
    }
    else if(ep == USB_EP3)
    {
        out = ( SN_USB->CFG & mskEP3_DIR ) == mskEP3_DIR;
        cnt = SN_USB->EP3CTL & mskEPn_CNT;
    }
    else if(ep == USB_EP4)
    {
        out = ( SN_USB->CFG & mskEP4_DIR ) == mskEP4_DIR;
        cnt = SN_USB->EP4CTL & mskEPn_CNT;
    }
	else if(ep == USB_EP5)
    {
        out = ( SN_USB->CFG & mskEP5_DIR ) == mskEP5_DIR;
        cnt = SN_USB->EP5CTL & mskEPn_CNT;
    }
    else if(ep == USB_EP6)
    {
        out = ( SN_USB->CFG & mskEP6_DIR ) == mskEP6_DIR;
        cnt = SN_USB->EP6CTL & mskEPn_CNT;
    }
    else {
        return;
    }
    nakcnt[ep] = 0;

    // Get the endpoint config and state
    const USBEndpointConfig *epcp = usbp->epc[ep];
    USBInEndpointState *isp = epcp->in_state;
    USBOutEndpointState *osp = epcp->out_state;

    // Process based on endpoint direction
    if(out)
    {
        // Read size of received data
        n = cnt;

        if (n > epcp->out_maxsize)
            n = epcp->out_maxsize;

        //state is NAK already
        //Just being paranoid here. keep here while debugging EP handling issue
        //TODO: clean it up when packets are properly handled
        if (epcp->out_state->rxsize >= n) {
            //we are ok to copy n bytes to buf
            sn32_usb_read_fifo(ep, osp->rxbuf, n, true);
            epcp->out_state->rxsize -= n;
        }
        else if (epcp->out_state->rxsize > 0) {
            //we dont have enough buffer to receive n bytes
            //copy only size availabe on buffer
            n = epcp->out_state->rxsize;
            sn32_usb_read_fifo(ep, osp->rxbuf, n, true);
            epcp->out_state->rxsize -= n;
        }
        else {
            //well buffer is 0 size. strange. do nothing.
            n = 0;
        }
        osp->rxbuf += n;

        epcp->out_state->rxcnt += n;
        if (epcp->out_state->rxpkts > 0) {
            epcp->out_state->rxpkts -= 1;
        }

        if (n < epcp->out_maxsize || epcp->out_state->rxpkts == 0)
        {
            _usb_isr_invoke_out_cb(usbp, ep);
        }
        else
        {
			//not done. keep on receiving
            USB_EPnAck(ep, 0);
        }
    }
    else
    {
        // Process transmit queue
        isp->txcnt += isp->txlast;
        n = isp->txsize - isp->txcnt;

        if (n > 0)
        {
            /* Transfer not completed, there are more packets to send.*/
            if (n > epcp->in_maxsize)
            {
                n = epcp->in_maxsize;
            }

            /* Writes the packet from the defined buffer.*/
            isp->txbuf += isp->txlast;
            isp->txlast = n;

            sn32_usb_write_fifo(ep, isp->txbuf, n, true);

            USB_EPnAck(ep, n);
        }
        else
        {
            //USB_EPnNak(ep); //not needed here it is autoreset to NAK already

            _usb_isr_invoke_in_cb(usbp, ep);
        }
    }
}

void handleNAK(USBDriver *usbp, usbep_t ep) {
    uint8_t out = 0;
    //handle it properly
    if (ep == USB_EP1) {
        out = ( SN_USB->CFG & mskEP1_DIR ) == mskEP1_DIR;
    }
    else if (ep == USB_EP2) {
        out = ( SN_USB->CFG & mskEP2_DIR ) == mskEP2_DIR;
    }
    else if (ep == USB_EP3) {
        out = ( SN_USB->CFG & mskEP3_DIR ) == mskEP3_DIR;
    }
    else if (ep == USB_EP4) {
        out = ( SN_USB->CFG & mskEP4_DIR ) == mskEP4_DIR;
    }
	else if (ep == USB_EP5) {
        out = ( SN_USB->CFG & mskEP5_DIR ) == mskEP5_DIR;
    }
	else if (ep == USB_EP6) {
        out = ( SN_USB->CFG & mskEP6_DIR ) == mskEP6_DIR;
    }
    else {
        return;
	}


    if(out)
	{
		// By acking next OUT token from host we are allowing reception
        // of the data from host
        USB_EPnAck(ep, 0);
    }
    else
    {
        // This is not a retransmission, retransmission is transparent and happens on phy layer
        // NAK happens when host polls IN EP and device has nothing to send
        // It has been observed that sometimes USB phy doesn't generate ACK (unknown why)
        // (count ACK interrupts didn't match count of usb_lld_start_in calls per EP)
        // However while USB transmitting and qmk thread wants to send another packet qmk goes to
        // infinite sleep, expecting that successfull USB transmission will wake it up
        // If USB transmission never completes (no ACK) then qmk never wakes up and keyboard locks up
        // To prevent this every NAK (1ms or 8ms depending on host poll interval) was calling
        // callbacks and wake up function to wake up qmk thread, however packet was not delivered to host
        // (for unknown reason) and thus we have seen:
        // 1) stuck keypresses when usb packets to press key delivered but key release packet lost
        // 2) untyped key when usb packet to press key was lost but key release packet delivered
        // Because callback was called every NAK some qmk features didnt work such as CONSOLE
        // since callback might release buffers and endup in deadlock via disabled interrupts
        // callback for keyboard is empty thus its repated calling is harmless
        #if defined(SN32_USB_ORIGINAL_NAK_HANDLING)
        _usb_isr_invoke_in_cb(usbp, ep);
        #else
        //To fake missing ACK we can send 0 sized packet
        //however (again for unknown reason) packets now being delivered to host as well!
        //- value 2 has been selected to allow at least 2 NAK delivery (2ms or 16ms depending on
        //host polling interval) between moment qmk called start_in and moment USB phy actually
        //started transmission
        //- value 10 was selected arbitrary.
        //- values 3-10 we are delivering 0 sized packet trying to get at least one ack
        if (nakcnt[ep] > 0) {
            //qmk called start_in
            if (nakcnt[ep] > 10) {
                //11-....
                //consider packet undeliverable but ack it to the qmk
                nakcnt[ep] = 0;
                _usb_isr_invoke_in_cb(usbp, ep);
            }
            else if (nakcnt[ep] > 2) {
                //3-10
                nakcnt[ep]++;
                USB_EPnAck(ep, 0);
            }
            else {
                //1-2
                //give it sometime to deliver the packet
                nakcnt[ep]++;
            }
        }
        #endif
	}
}

/*===========================================================================*/
/* Driver interrupt handlers and threads.                                    */
/*===========================================================================*/

/**
 * @brief   SN32 USB Interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SN32_USB_IRQ_VECTOR) {

  OSAL_IRQ_PROLOGUE();
  usb_lld_serve_interrupt(&USBD1);
  OSAL_IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level USB driver initialization.
 *
 * @notapi
 */
void usb_lld_init(void) {

	#if PLATFORM_USB_USE_USB1 == TRUE
	/* Driver initialization.*/
	usbObjectInit(&USBD1);
	#endif
}

/**
 * @brief   Configures and activates the USB peripheral.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_start(USBDriver *usbp) {

    if (usbp->state == USB_STOP) {
        /* Enables the peripheral.*/
        #if PLATFORM_USB_USE_USB1 == TRUE
        if (&USBD1 == usbp) {
            USB_Init();
            nvicEnableVector(USB_IRQn, 14);
        }
        #endif
    }
    /* Configures the peripheral.*/
}

/**
 * @brief   Deactivates the USB peripheral.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_stop(USBDriver *usbp) {
    if (usbp->state == USB_READY) {
        /* Resets the peripheral.*/

        /* Disables the peripheral.*/
        #if PLATFORM_USB_USE_USB1 == TRUE
        if (&USBD1 == usbp) {
        }
        #endif
	}
}

/**
 * @brief   USB low level reset routine.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_reset(USBDriver *usbp) {
    /* Post reset initialization.*/

    /* EP0 initialization.*/
    usbp->epc[0] = &ep0config;
    usb_lld_init_endpoint(usbp, 0);
}

/**
 * @brief   Sets the USB address.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_set_address(USBDriver *usbp) {
    // It seems the address must be set after an endpoint interrupt, so store it for now.
    // It will be written to SN_USB->ADDR in the EP0 IN interrupt
    address = usbp->address;
}

/**
 * @brief   Enables an endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_init_endpoint(USBDriver *usbp, usbep_t ep) {
    const USBEndpointConfig *epcp = usbp->epc[ep];

    /* Set the endpoint type. */
    switch (epcp->ep_mode & USB_EP_MODE_TYPE) {
        case USB_EP_MODE_TYPE_ISOC:
            break;
        case USB_EP_MODE_TYPE_BULK:
            break;
        case USB_EP_MODE_TYPE_INTR:
            break;
        default:
            break;
    }

    /* IN endpoint? */
    if (epcp->in_state != NULL) {
        // Set endpoint direction flag in USB configuration register
        switch (ep)
        {
        case 1:
            SN_USB->CFG &= ~mskEP1_DIR;
            break;
        case 2:
            SN_USB->CFG &= ~mskEP2_DIR;
            break;
        case 3:
            SN_USB->CFG &= ~mskEP3_DIR;
            break;
        case 4:
            SN_USB->CFG &= ~mskEP4_DIR;
            break;
        case 5:
            SN_USB->CFG &= ~mskEP5_DIR;
            break;
        case 6:
            SN_USB->CFG &= ~mskEP6_DIR;
            break;
        }
    }

    /* OUT endpoint? */
    if (epcp->out_state != NULL) {
        // Set endpoint direction flag in USB configuration register
        // Also enable ACK state
        switch (ep)
        {
        case 1:
            SN_USB->CFG |= mskEP1_DIR;
            break;
        case 2:
            SN_USB->CFG |= mskEP2_DIR;
            break;
        case 3:
            SN_USB->CFG |= mskEP3_DIR;
            break;
        case 4:
            SN_USB->CFG |= mskEP4_DIR;
            break;
        case 5:
            SN_USB->CFG |= mskEP5_DIR;
            break;
        case 6:
            SN_USB->CFG |= mskEP6_DIR;
            break;
        }
    }

    /* Enable endpoint. */
    switch(ep)
    {
        case 1:
            SN_USB->EP1CTL |= mskEPn_ENDP_EN;
            break;
        case 2:
            SN_USB->EP2CTL |= mskEPn_ENDP_EN;
            break;
        case 3:
            SN_USB->EP3CTL |= mskEPn_ENDP_EN;
            break;
        case 4:
            SN_USB->EP4CTL |= mskEPn_ENDP_EN;
            break;
        case 5:
            SN_USB->EP5CTL |= mskEPn_ENDP_EN;
            break;
        case 6:
            SN_USB->EP6CTL |= mskEPn_ENDP_EN;
            break;
    }
}

/**
 * @brief   Disables all the active endpoints except the endpoint zero.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_disable_endpoints(USBDriver *usbp) {
    unsigned i;

    /* Disabling all endpoints.*/
    for (i = 1; i <= USB_MAX_ENDPOINTS; i++) {
        USB_EPnDisable(i);
    }
}

/**
 * @brief   Returns the status of an OUT endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @return              The endpoint status.
 * @retval EP_STATUS_DISABLED The endpoint is not active.
 * @retval EP_STATUS_STALLED  The endpoint is stalled.
 * @retval EP_STATUS_ACTIVE   The endpoint is active.
 *
 * @notapi
 */
usbepstatus_t usb_lld_get_status_out(USBDriver *usbp, usbep_t ep) {
    if (ep > USB_MAX_ENDPOINTS)
        return EP_STATUS_DISABLED;
    if (!USB_EPnEnabled(ep))
        return EP_STATUS_DISABLED;
    if (USB_EPnStalled(ep))
        return EP_STATUS_STALLED;
    return EP_STATUS_ACTIVE;
/*
    if (SN_USB->INSTS & mskEP0_OUT) {
        return EP_STATUS_DISABLED;
    } else if (SN_USB->INSTS & mskEP0_OUT_STALL) {
        return EP_STATUS_STALLED;
    } else {
        return EP_STATUS_ACTIVE;
    }
*/
}

/**
 * @brief   Returns the status of an IN endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @return              The endpoint status.
 * @retval EP_STATUS_DISABLED The endpoint is not active.
 * @retval EP_STATUS_STALLED  The endpoint is stalled.
 * @retval EP_STATUS_ACTIVE   The endpoint is active.
 *
 * @notapi
 */
usbepstatus_t usb_lld_get_status_in(USBDriver *usbp, usbep_t ep) {
    if (ep > USB_MAX_ENDPOINTS)
        return EP_STATUS_DISABLED;
    if (!USB_EPnEnabled(ep))
        return EP_STATUS_DISABLED;
    if (USB_EPnStalled(ep))
        return EP_STATUS_STALLED;
    return EP_STATUS_ACTIVE;
/*
   if (SN_USB->INSTS & mskEP0_IN) {
       return EP_STATUS_DISABLED;
   } else if (SN_USB->INSTS & mskEP0_IN_STALL) {
       return EP_STATUS_STALLED;
   } else {
       return EP_STATUS_ACTIVE;
   }
*/
}

/**
 * @brief   Reads a setup packet from the dedicated packet buffer.
 * @details This function must be invoked in the context of the @p setup_cb
 *          callback in order to read the received setup packet.
 * @pre     In order to use this function the endpoint must have been
 *          initialized as a control endpoint.
 * @post    The endpoint is ready to accept another packet.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @param[out] buf      buffer where to copy the packet data
 *
 * @notapi
 */

void usb_lld_read_setup(USBDriver *usbp, usbep_t ep, uint8_t *buf) {

    sn32_usb_read_fifo(ep, buf, 8, false);
}

/**
 * @brief   Starts a receive operation on an OUT endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_start_out(USBDriver *usbp, usbep_t ep) {

    USBOutEndpointState *osp = usbp->epc[ep]->out_state;

    /* Transfer initialization.*/
    if (osp->rxsize == 0)         /* Special case for zero sized packets.*/
        osp->rxpkts = 1;
    else
        osp->rxpkts = (uint16_t)((osp->rxsize + usbp->epc[ep]->out_maxsize - 1) /
                                    usbp->epc[ep]->out_maxsize);
    osp->rxcnt = 0;//haven't received anything yet
    USB_EPnAck(ep, 0);
}

/**
 * @brief   Starts a transmit operation on an IN endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_start_in(USBDriver *usbp, usbep_t ep)
{
    size_t n;
    USBInEndpointState *isp = usbp->epc[ep]->in_state;

    /* Transfer initialization.*/
	//who handles 0 packet ack on setup?
    n = isp->txsize;

    if((n >= 0) || (ep == 0))
    {
    if (n > (size_t)usbp->epc[ep]->in_maxsize)
        n = (size_t)usbp->epc[ep]->in_maxsize;

    isp->txlast = n;

        sn32_usb_write_fifo(ep, isp->txbuf, n, false);

    nakcnt[ep] = 1;
    USB_EPnAck(ep, n);
    }
    else
    {
        _usb_isr_invoke_in_cb(usbp, ep);
    }

}

/**
 * @brief   Brings an OUT endpoint in the stalled state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_stall_out(USBDriver *usbp, usbep_t ep) {

	USB_EPnStall(ep);

}

/**
 * @brief   Brings an IN endpoint in the stalled state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_stall_in(USBDriver *usbp, usbep_t ep) {

   USB_EPnStall(ep);

}

/**
 * @brief   Brings an OUT endpoint in the active state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_clear_out(USBDriver *usbp, usbep_t ep) {
    if (ep > USB_MAX_ENDPOINTS)
        return;
    USB_EPnNak(ep);
    //__USB_CLRINSTS(mskEP0_OUT);
}

/**
 * @brief   Brings an IN endpoint in the active state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_clear_in(USBDriver *usbp, usbep_t ep) {
    if (ep > USB_MAX_ENDPOINTS)
        return;
    USB_EPnNak(ep);
    //__USB_CLRINSTS(mskEP0_IN);
}

#endif /* HAL_USE_USB == TRUE */

/** @} */