/*
    ChibiOS - Copyright (C) 2006..2020 Giovanni Di Sirio

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

#include <string.h>
#include "hal.h"

#if (HAL_USE_USB == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   USB1 driver identifier.
 */
#if (SN32_USB_USE_USB1 == TRUE) || defined(__DOXYGEN__)
USBDriver USBD1;
#endif /* SN32_USB_USE_USB1 == TRUE */

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

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
 * @brief   Buffer for the EP0 setup packets.
 */
static uint8_t ep0setup_buffer[8];

/**
 * @brief   EP0 initialization structure.
 */
static const USBEndpointConfig ep0config = {
  .ep_mode          = USB_EP_MODE_TYPE_CTRL,
  .setup_cb         = _usb_ep0setup,
  .in_cb            = _usb_ep0in,
  .out_cb           = _usb_ep0out,
  .in_maxsize       = 0x40,
  .out_maxsize      = 0x40,
  .in_state         = &ep0_state.in,
  .out_state        = &ep0_state.out,
  .ep_buffers       = 1,
  .setup_buf        = ep0setup_buffer
};

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Resets the packet memory allocator.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 */
static void usb_pm_reset(USBDriver *usbp) {

  /* The first 64 bytes are reserved for the descriptors table. The effective
     available RAM for endpoint buffers is just 192/448 bytes.*/
  usbp->pmnext = 64;
}

/**
 * @brief   Sets the packet memory allocator.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] size      size of the packet buffer to allocate
 * @return              The packet buffer address.
 */
static uint32_t usb_pm_alloc(USBDriver *usbp, size_t size) {
  uint32_t next;

  next = usbp->pmnext;
  usbp->pmnext += (size + 1) & ~1;
  osalDbgAssert(usbp->pmnext <= SN32_USB_PMA_SIZE, "PMA overflow");
  return next;
}

static void sn32_usb_read_fifo(usbep_t ep, uint8_t *buf, size_t sz, bool intr) {
    size_t ep_offset;
    if (ep == 0) {
        ep_offset = 0;
    }
    else {
        ep_offset = SN32_USB->EPBUFOS[ep-1];
    }
    size_t off;
    size_t chunk;
    uint32_t data;

    off = 0;
    while (off != sz) {
        chunk = 4;
        if (off + chunk > sz)
            chunk = sz - off;

        if(intr) {
            SN32_USB->RWADDR = off + ep_offset;
            SN32_USB->RWSTATUS = 0x02;
            while (SN32_USB->RWSTATUS & 0x02);
            data = SN32_USB->RWDATA;
        }
        else {
            SN32_USB->RWADDR2 = off + ep_offset;
            SN32_USB->RWSTATUS2 = 0x02;
            while (SN32_USB->RWSTATUS2 & 0x02);
            data = SN32_USB->RWDATA2;
        }

        //dest, src, size
        memcpy(buf, &data, chunk);

        off += chunk;
        buf += chunk;
    }
}

static void sn32_usb_write_fifo(usbep_t ep, const uint8_t *buf, size_t sz, bool intr) {
    size_t ep_offset;
    if (ep == 0) {
        ep_offset = 0;
    }
    else {
        ep_offset = SN32_USB->EPBUFOS[ep-1];
    }
    size_t off;
    size_t chunk;
    uint32_t data;

    off = 0;

    while (off != sz) {
        chunk = 4;
        if (off + chunk > sz)
            chunk = sz - off;

        //dest, src, size
        memcpy(&data, buf, chunk);

        if(intr) {
            SN32_USB->RWADDR = off + ep_offset;
            SN32_USB->RWDATA = data;
            SN32_USB->RWSTATUS = 0x01;
            while (SN32_USB->RWSTATUS & 0x01);
        }
        else {
            SN32_USB->RWADDR2 = off + ep_offset;
            SN32_USB->RWDATA2 = data;
            SN32_USB->RWSTATUS2 = 0x01;
            while (SN32_USB->RWSTATUS2 & 0x01);
        }

        off += chunk;
        buf += chunk;
    }
}

/**
 * @brief   USB shared ISR.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
static void usb_lld_serve_interrupt(USBDriver *usbp) {
    uint32_t iwIntFlag;

    /* Get Interrupt Status and clear immediately. */
    iwIntFlag = SN32_USB->INSTS;
    /* Keep only PRESETUP & ERR_SETUP flags. */
    SN32_USB->INSTSC = ~(mskEP0_PRESETUP | mskERR_SETUP);

    if (iwIntFlag == 0) {
        //@20160902 add for EMC protection
        SN32_USB->CFG |= (mskESD_EN|mskPHY_EN);
        return;
    }

    /////////////////////////////////////////////////////////////////
    /* Device Status Interrupt (BusReset, Suspend, Resume, Wakeup) */
    /////////////////////////////////////////////////////////////////
    if (iwIntFlag & (mskBUS_RESET | mskBUS_SUSPEND | mskBUS_RESUME | mskBUS_WAKEUP)) {
        if (iwIntFlag & mskBUS_RESET) {
            /* BusReset */
            SN32_USB->CFG |= (mskESD_EN|mskPHY_EN);
            SN32_USB->INSTSC = (mskBUS_RESET);
            _usb_reset(usbp);
        }
        else if (iwIntFlag & mskBUS_SUSPEND) {
            /* Suspend */
            SN32_USB->CFG &= ~(mskESD_EN|mskPHY_EN);
            _usb_suspend(usbp);
            SN32_USB->INSTSC = (mskBUS_SUSPEND);
        }
        else if(iwIntFlag & mskBUS_RESUME) {
            /* Resume */
            SN32_USB->CFG |= (mskESD_EN|mskPHY_EN);
            SN32_USB->INSTSC = (mskBUS_RESUME);
        }
        else if(iwIntFlag & mskBUS_WAKEUP) {
            /* Wakeup */
            SN32_USB->CFG |= (mskESD_EN|mskPHY_EN);
            SN32_USB->INSTSC = (mskBUS_WAKEUP);
            _usb_wakeup(usbp);
        }
    }
    /////////////////////////////////////////////////
    /* Device Status Interrupt (SETUP, IN, OUT)    */
    /////////////////////////////////////////////////
    else if (iwIntFlag & mskERR_SETUP) {
        SN32_USB->INSTSC = (mskERR_SETUP);
        usb_lld_stall_in(usbp, 0);
    }
    else if (iwIntFlag & (mskEP0_SETUP|mskEP0_IN|mskEP0_OUT|mskEP0_IN_STALL|mskEP0_OUT_STALL)) {

        if (iwIntFlag & mskEP0_SETUP) {
            /* SETUP */
            /* Clear receiving in the chibios state machine */
            (usbp)->receiving &= ~1;
            SN32_USB->INSTSC = (mskEP0_PRESETUP);
            /* Call SETUP function (ChibiOS core), which prepares
             * for send or receive and releases the buffer
             */
            _usb_isr_invoke_setup_cb(usbp, 0);
            SN32_USB->INSTSC = (mskEP0_SETUP);
        }
        else if (iwIntFlag & mskEP0_IN) {
            usb_serve_endpoints(usbp, 0, true);

            SN32_USB->INSTSC = (mskEP0_IN);
        }
        else if (iwIntFlag & mskEP0_OUT) {
            usb_serve_endpoints(usbp, 0, false);
            SN32_USB->INSTSC = (mskEP0_OUT);
        }
        else if (iwIntFlag & (mskEP0_IN_STALL)) {
            /* EP0_IN_STALL */
            usb_lld_stall_in(usbp, 0);
            SN32_USB->INSTSC = (mskEP0_IN_STALL);
        }
        else if (iwIntFlag & (mskEP0_OUT_STALL))
        {
            /* EP0_OUT_STALL */
            usb_lld_stall_out(usbp, 0);
            SN32_USB->INSTSC = (mskEP0_OUT_STALL);
        }
    }

    /////////////////////////////////////////////////
    /* Device Status Interrupt (SOF)               */
    /////////////////////////////////////////////////
    if ((iwIntFlag & mskUSB_SOF) && (SN32_USB->INTEN & mskUSB_SOF_IE)) {
        /* SOF */
        _usb_isr_invoke_sof_cb(usbp);
        SN32_USB->INSTSC = (mskUSB_SOF);
    }
    /////////////////////////////////////////////////
    /* Device Status Interrupt (EPnACK)            */
    /////////////////////////////////////////////////
    if (iwIntFlag & (mskEP6_ACK|mskEP5_ACK|mskEP4_ACK|mskEP3_ACK|mskEP2_ACK|mskEP1_ACK)) {
        // Determine the interrupting endpoint, direction, and clear the interrupt flag
        for(usbep_t ep = 1; ep <= USB_MAX_ENDPOINTS; ep++) {
            if (iwIntFlag & mskEPn_ACK(ep)){
                usb_serve_endpoints(usbp, ep, (SN32_USB->CFG & mskEPn_DIR(ep)) == 0);
                SN32_USB->INSTSC = (mskEPn_ACK(ep));
            }
        }
    }
    if (iwIntFlag & (mskEP6_NAK|mskEP5_NAK|mskEP4_NAK|mskEP3_NAK|mskEP2_NAK|mskEP1_NAK)) {
        SN32_USB->INSTSC = (mskEP6_NAK|mskEP5_NAK|mskEP4_NAK|mskEP3_NAK|mskEP2_NAK|mskEP1_NAK);

    }

}

void usb_serve_endpoints(USBDriver* usbp, usbep_t ep, bool in) {
    size_t n;

    if(ep > USB_MAX_ENDPOINTS) return;

    n = SN32_USB->EPCTL[ep] & mskEPn_CNT;

    // Get the endpoint config and state
    const USBEndpointConfig *epcp = usbp->epc[ep];

    // Process based on endpoint direction
    if(in) {
        /* IN endpoint, transmission.*/
        USBInEndpointState *isp = epcp->in_state;
        
        if (isp->txcnt >= isp->txsize) {
          /* Transfer completed, invokes the callback.*/
          _usb_isr_invoke_in_cb(usbp, ep);
          return;
        }

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
            osalSysLockFromISR();
            sn32_usb_write_fifo(ep, isp->txbuf, n, true);
            osalSysUnlockFromISR();

            EPCTL_SET_STAT_ACK(ep, n);
        }
        else {
            /* Transfer complete, invokes the callback.*/
            //EPCTL_SET_STAT_NAK(ep); //useless mcu resets it anyways
            _usb_isr_invoke_in_cb(usbp, ep);
        }
    }
    else {
        /* OUT endpoint, receive.*/
        USBOutEndpointState *osp = epcp->out_state;
        
        if (n) {
            /* Reads the packet into the defined buffer.*/
            osalSysLockFromISR();
            sn32_usb_read_fifo(ep, osp->rxbuf, n, true);
            osalSysUnlockFromISR();
            osp->rxbuf += n;

            /* Transaction data updated.*/
            osp->rxcnt  += n;
            osp->rxsize -= n;
            osp->rxpkts -= 1;

            /* The transaction is completed if the specified number of packets
               has been received or the current packet is a short packet.*/
            if ((n < epcp->out_maxsize) || (epcp->out_state->rxpkts == 0))
            {
                /* Transfer complete, invokes the callback.*/
                //EPCTL_SET_STAT_NAK(0); //useless mcu resets it anyways
                _usb_isr_invoke_out_cb(usbp, ep);
            }
            else {
                /* Transfer not complete, there are more packets to receive.*/
                EPCTL_SET_STAT_ACK(ep, 0);
            }
        }
    }
  
}

/*===========================================================================*/
/* Driver interrupt handlers and threads.                                    */
/*===========================================================================*/
#if (SN32_USB_USE_USB1 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   SN32 USB Interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SN32_USB_HANDLER) {

    OSAL_IRQ_PROLOGUE();
    usb_lld_serve_interrupt(&USBD1);
    OSAL_IRQ_EPILOGUE();
}
#endif /* SN32_USB_USE_USB1 == TRUE */
/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level USB driver initialization.
 *
 * @notapi
 */
void usb_lld_init(void) {
#if SN32_USB_USE_USB1 == TRUE
    /* Driver initialization.*/
    usbObjectInit(&USBD1);
#endif /* SN32_USB_USE_USB1 == TRUE */
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
    /* Clock activation.*/
#if SN32_USB_USE_USB1
    if (&USBD1 == usbp) {
      /* USB clock enabled.*/
      sys1EnableUSB();
      /* Powers up the transceiver while holding the USB in reset state.*/
      SN32_USB->SGCTL = (mskBUS_DRVEN|mskBUS_J_STATE);
      SN32_USB->CFG = (mskVREG33_EN|mskPHY_EN|mskDPPU_EN|mskSIE_EN|mskESD_EN);
      /* Set up hardware configuration.*/
      SN32_USB->PHYPRM = 0x80000000;
      SN32_USB->PHYPRM2 = 0x00004004;
      /* Enable the USB Bus Interrupts.*/
      SN32_USB->INTEN = mskBUS_IE;

      nvicEnableVector(SN32_USB_NUMBER, SN32_USB_IRQ_PRIORITY);
      /* Releases the reset state.*/
      SN32_USB->SGCTL &= ~mskBUS_DRVEN;
    }
#endif /* SN32_USB_USE_USB1 == TRUE */
    /* Reset procedure enforced on driver start.*/
    usb_lld_reset(usbp);
  }
}

/**
 * @brief   Deactivates the USB peripheral.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_stop(USBDriver *usbp) {
  /* If in ready state then disables the USB clock.*/
  if (usbp->state != USB_STOP) {
#if SN32_USB_USE_USB1 == TRUE
    /* Disables the peripheral.*/
    if (&USBD1 == usbp) {
        nvicDisableVector(SN32_USB_NUMBER);
        sys1DisableUSB();
    }
#endif /* SN32_USB_USE_USB1 == TRUE */
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
    SN32_USB->INSTSC = (0xFFFFFFFF);

    /* Set the address to zero during enumeration.*/
    usbp->address = 0;
    SN32_USB->ADDR  = 0;

    /* Resets the packet memory allocator.*/
    usb_pm_reset(usbp);

    /* EP0 initialization.*/
    usbp->epc[0] = &ep0config;
    usb_lld_init_endpoint(usbp, 0);

    /* Enable other interrupts.*/
    SN32_USB->INTEN |= (mskUSB_IE|mskEPnACK_EN|mskBUSWK_IE|mskUSB_SOF_IE);
    //SN32_USB->INTEN |= (mskEP1_NAK_EN|mskEP2_NAK_EN|mskEP3_NAK_EN|mskEP4_NAK_EN);
#if (USB_ENDPOINTS_NUMBER > 4)
    //SN32_USB->INTEN |= (mskEP5_NAK_EN|mskEP6_NAK_EN);
#endif /* (USB_ENDPOINTS_NUMBER > 4) */

}

/**
 * @brief   Sets the USB address.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_set_address(USBDriver *usbp) {

    SN32_USB->ADDR = usbp->address & 0x7F;
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

    /* Make sure direction flags are not set.*/
    if(ep > 0 && ep <= USB_MAX_ENDPOINTS) {
        SN32_USB->CFG &= ~mskEPn_DIR(ep);
    }

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
        if(ep ==0) {
            usb_lld_stall_in(usbp, 0);
        }
        else if(ep <= USB_MAX_ENDPOINTS) {
            /* Set endpoint direction flag in USB configuration register.*/
            SN32_USB->CFG &= ~mskEPn_DIR(ep);
            /* Set endpoint PMA buffer offset in USB configuration register.*/
            uint32_t buff_addr = usb_pm_alloc(usbp, epcp->in_maxsize);
            USB_SET_BUFFER_OFST(ep,buff_addr);
        }
    }

    /* OUT endpoint? */
    if (epcp->out_state != NULL) {
        if(ep ==0) {
            usb_lld_stall_out(usbp, 0);
        }
        else if(ep <= USB_MAX_ENDPOINTS) {
            /* Set endpoint direction flag in USB configuration register.*/
            SN32_USB->CFG |= mskEPn_DIR(ep);
            /* Set endpoint PMA buffer offset in USB configuration register.*/
            uint32_t buff_addr = usb_pm_alloc(usbp, epcp->out_maxsize);
            USB_SET_BUFFER_OFST(ep,buff_addr);
        }
    }

    /* Enable endpoint. */
    if(ep <= USB_MAX_ENDPOINTS) {
        SN32_USB->EPCTL[ep] |= mskEPn_ENDP_EN;
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

    /* Resets the packet memory allocator.*/
    usb_pm_reset(usbp);

    /* Disabling all endpoints.*/
    for(usbep_t ep=1; ep <= USB_MAX_ENDPOINTS; ep++) {
        SN32_USB->EPCTL[ep] = 0;
        SN32_USB->CFG &= ~mskEPn_DIR(ep);
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
    (void)usbp;
    if (ep > USB_MAX_ENDPOINTS)
        return EP_STATUS_DISABLED;
    if ((SN32_USB->EPCTL[ep] & mskEPn_ENDP_EN) != mskEPn_ENDP_EN)
        return EP_STATUS_DISABLED;
    if ((SN32_USB->EPCTL[ep] & mskEPn_ENDP_STATE) == mskEPn_ENDP_STATE_STALL)
        return EP_STATUS_STALLED;
    return EP_STATUS_ACTIVE;
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
    (void)usbp;
    if (ep > USB_MAX_ENDPOINTS)
        return EP_STATUS_DISABLED;
    if ((SN32_USB->EPCTL[ep] & mskEPn_ENDP_EN) != mskEPn_ENDP_EN)
        return EP_STATUS_DISABLED;
    if ((SN32_USB->EPCTL[ep] & mskEPn_ENDP_STATE) == mskEPn_ENDP_STATE_STALL)
        return EP_STATUS_STALLED;
    return EP_STATUS_ACTIVE;
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
    osalSysLockFromISR();
    sn32_usb_read_fifo(ep, buf, 8, false);
    osalSysUnlockFromISR();
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
    EPCTL_SET_STAT_ACK(ep, 0);
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
    n = isp->txsize;

    if (n > (size_t)usbp->epc[ep]->in_maxsize)
        n = (size_t)usbp->epc[ep]->in_maxsize;

    isp->txlast = n;
    osalSysLockFromISR();
    sn32_usb_write_fifo(ep, isp->txbuf, n, false);
    osalSysUnlockFromISR();

    EPCTL_SET_STAT_ACK(ep, n);

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
    (void)usbp;
    if (ep == 0 ) {
        if (SN32_USB->INSTS & mskEP0_PRESETUP) {
            return;
        }
        if (SN32_USB->INSTS & mskEP0_OUT_STALL) {
            SN32_USB->EPCTL[ep] |= mskEP0_OUT_STALL_EN;
            return;
        }
    }
    EPCTL_SET_STAT_STALL(ep);
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
    (void)usbp;
    if (ep == 0 ) {
        if (SN32_USB->INSTS & mskEP0_PRESETUP) {
            return;
        }
        if (SN32_USB->INSTS & mskEP0_IN_STALL) {
            SN32_USB->EPCTL[ep] |= mskEP0_IN_STALL_EN;
            return;
        }
    }
    EPCTL_SET_STAT_STALL(ep);
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
    (void)usbp;
    /* Makes sure to not put to NAK an endpoint that is already
       transferring.*/
    if (!(SN32_USB->EPCTL[ep] & mskEPn_ENDP_STATE_NAK))
        EPCTL_SET_STAT_NAK(ep);
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
    (void)usbp;
    /* Makes sure to not put to NAK an endpoint that is already
       transferring.*/
    if (!(SN32_USB->EPCTL[ep] & mskEPn_ENDP_STATE_NAK))
        EPCTL_SET_STAT_NAK(ep);
}

#endif /* HAL_USE_USB == TRUE */

/** @} */
