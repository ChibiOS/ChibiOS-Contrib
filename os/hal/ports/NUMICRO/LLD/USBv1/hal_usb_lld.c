/*
    ChibiOS - Copyright (C) 2017 Frank Zschockelt
	ChibiOS - Copyright (C) 2019 /u/KeepItUnder

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
 * @brief   NUC123 USB subsystem low level driver source.
 *
 * @addtogroup USB
 * @{
 */

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
#if (NUC123_USB_USE_USB1 == TRUE) || defined(__DOXYGEN__)
USBDriver USBD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

uint8_t * const usbd_sram = (uint8_t*)(USBD_BASE + 0x100);

/**
 * @brief   EP0 state.
 */
  /**
   * @brief   IN EP0 state.
   */
  USBInEndpointState ep0_in;
  /**
   * @brief   OUT EP0 state.
   */
  USBOutEndpointState ep0_out;

static uint8_t ep0setup_buffer[8];

/**
 * @brief   EP0 initialization structure.
 */
static const USBEndpointConfig ep0config = {
  USB_EP_MODE_TYPE_CTRL,
  _usb_ep0setup,
  _usb_ep0in,
  _usb_ep0out,
  0x40,
  0x40,
  &ep0_in,
  &ep0_out,
  1,
  ep0setup_buffer
};

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/
void _toggle_dsq(int ep, uint8_t *dsq)
{
  if (*dsq) {
    USBD->EP[ep].CFG &= ~USBD_CFG_DSQ_SYNC_Msk;
  }
  else {
    USBD->EP[ep].CFG |= USBD_CFG_DSQ_SYNC_Msk;
  }
  *dsq = !*dsq;
}

/*===========================================================================*/
/* Driver interrupt handlers and threads.                                    */
/*===========================================================================*/

static void serve_endpoint_irq(USBDriver *usbp,
                               uint32_t endpoint_mask,
                               uint32_t epstatus)
{
  for (int hwEp = 0; hwEp < USB_MAX_ENDPOINTS; hwEp++) {
    if (endpoint_mask  & (1 << hwEp)) {
      uint32_t bus_status = ((epstatus >> (hwEp*(USBD_EPSTS_EPSTS1_Pos - USBD_EPSTS_EPSTS0_Pos))) & USBD_EPSTS_EPSTS0_Msk) >> USBD_EPSTS_EPSTS0_Pos;
      usbep_t ep = (USBD->EP[hwEp].CFG & USBD_CFG_EP_NUM_Msk) >> USBD_CFG_EP_NUM_Pos;

      switch (bus_status) {
      case 0: /* In ACK */
        {
          USBInEndpointState *iesp = usbp->epc[ep]->in_state;
          iesp->txcnt += USBD->EP[hwEp].MXPLD;
          if (iesp->txcnt >= iesp->txsize) {
            _usb_isr_invoke_in_cb(usbp, ep);
          }
          else {
            uint32_t txcnt;
            if ((iesp->txcnt + usbp->epc[ep]->in_maxsize) > iesp->txsize) {
              txcnt = iesp->txsize - iesp->txcnt;
            }
            else {
              txcnt = usbp->epc[ep]->in_maxsize;
            }
            for (uint32_t n = 0; n < txcnt; n++) {
              usbd_sram[(USBD->EP[hwEp].BUFSEG) + n] = iesp->txbuf[iesp->txcnt + n];
            }
            _toggle_dsq(hwEp, &(iesp->dsq));
            USBD->EP[hwEp].MXPLD = txcnt;
          }
        }
        break;
      case 0x1: /* In NAK */
        break;
      case 0x2: /* Out Packet Data 0 ACK */
      case 0x6: /* Out Packet Data 1 ACK */
        {
          USBOutEndpointState *oesp = usbp->epc[ep]->out_state;
          for (uint32_t n = 0; n < USBD->EP[hwEp].MXPLD; n++) {
            oesp->rxbuf[oesp->rxcnt] = usbd_sram[USBD->EP[hwEp].BUFSEG + n];
            oesp->rxcnt++;
          }
          if (oesp->rxcnt == oesp->rxsize) {
            _usb_isr_invoke_out_cb(usbp, ep);
          }
          else {
            _toggle_dsq(hwEp, &(oesp->dsq));
            if ((oesp->rxcnt + usbp->epc[ep]->out_maxsize) > oesp->rxsize) {
              USBD->EP[hwEp].MXPLD = oesp->rxsize - oesp->rxcnt;
            }
            else {
              USBD->EP[hwEp].MXPLD = usbp->epc[ep]->out_maxsize;
            }
          }
        }
        break;
      case 0x3: /* Setup ACK */
        break;
      case 0x7: /* Isochronous transfer end */
      default:
          osalDbgAssert(FALSE, "not supported");
      }
    }
  }
}

static void serve_usb_irq(USBDriver *usbp) {
  uint32_t intsts = USBD->INTSTS;
  uint32_t epsts = USBD->EPSTS;

  if (intsts & USBD_INTSTS_FLDET_STS_Msk) {
    USBD->INTSTS |= USBD_INTSTS_FLDET_STS_Msk;
    if (USBD->FLDET) {
      usbConnectBus(usbp);
    }
    else {
      usbDisconnectBus(usbp);
    }
  }

  if (intsts & USBD_INTSTS_BUS_STS_Msk) {
    uint32_t bus_attr = USBD->ATTR;
    USBD->INTSTS |= USBD_INTSTS_BUS_STS_Msk;
    if (bus_attr & USBD_ATTR_USBRST_Msk) {
      _usb_reset(usbp);
    }
    if (bus_attr & USBD_ATTR_SUSPEND_Msk) {
      if (usbp->state == USB_ACTIVE) {
        _usb_suspend(usbp);
      }
    }
    if (bus_attr & USBD_ATTR_RESUME_Msk) {
      usbConnectBus(usbp);
      (usbp)->receiving = 0;
      (usbp)->transmitting = 0;
      _usb_wakeup(usbp);
    }
  }

  if (intsts & USBD_INTSTS_USB_STS_Msk) {
    /* check endpoints first */
    serve_endpoint_irq(usbp, (intsts & USBD_INTSTS_EPEVT_Msk) >> USBD_INTSTS_EPEVT_Pos, epsts);
    USBD->INTSTS = intsts & USBD_INTSTS_EPEVT_Msk;
    /* then handle setup packets */
    if (intsts & USBD_INTSTS_SETUP_Msk) {
      USBD->INTSTS |= USBD_INTSTS_SETUP_Msk;
      USBInEndpointState *iesp = usbp->epc[0]->in_state;
      iesp->dsq = 0;
      _usb_isr_invoke_setup_cb(usbp, 0);
    }
  }
  if (intsts & USBD_INTSTS_WAKEUP_STS_Msk) {
    USBD->INTSTS |= USBD_INTSTS_WAKEUP_STS_Msk;
    USBD->ATTR |= USBD_ATTR_PHY_EN_Msk;
  }
}

OSAL_IRQ_HANDLER(NUC123_USB1_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  serve_usb_irq(&USBD1);
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

#if NUC123_USB_USE_USB1 == TRUE
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
#if NUC123_USB_USE_USB1 == TRUE
    if (&USBD1 == usbp) {
      uint16_t delay;
      /* Enable USB Clock */
      UNLOCKREG();
      CLK->APBCLK |= CLK_APBCLK_USBD_EN_Msk;

      /* Reset USB */
      SYS->IPRSTC2 |= SYS_IPRSTC2_USBD_RST_Msk;
      for (delay=0x100; delay > 0; delay--);
      SYS->IPRSTC2 &= ~SYS_IPRSTC2_USBD_RST_Msk;
      LOCKREG();

      usbConnectBus(usbp);
      USBD->ATTR = (USBD_ATTR_BYTEM_Msk | USBD_ATTR_PWRDN_Msk |
                    USBD_ATTR_DPPU_EN_Msk |USBD_ATTR_USB_EN_Msk |
                    USBD_ATTR_PHY_EN_Msk);


      USBD->DRVSE0 = 1u;
      for (delay=0x100; delay > 0; delay--);
      USBD->DRVSE0 = 0u;

      USBD->INTSTS = USBD->INTSTS;

      nvicEnableVector(NUC123_USB1_NUMBER, NUC123_USB_USB1_IRQ_PRIORITY);

      USBD->INTEN = (USBD_INTEN_WAKEUP_EN_Msk |
                     USBD_INTEN_WAKEUP_IE_Msk |
                     USBD_INTEN_FLDET_IE_Msk |
                     USBD_INTEN_USB_IE_Msk |
                     USBD_INTEN_BUS_IE_Msk);
    }
#endif
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
  if (usbp->state == USB_READY) {
    /* Resets the peripheral.*/
    /* Disables the peripheral.*/
#if NUC123_USB_USE_USB1 == TRUE
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
  /* NUC123 has 512b SRAM for EP-buffers; the first 8b are reserved for setup packets */
  usbp->bufnext = 8;
  usbp->epnext = 0;

  usb_lld_init_endpoint(usbp, 0);
  usbConnectBus(usbp);
  USBD->FADDR = 0;
}

/**
 * @brief   Sets the USB address.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_set_address(USBDriver *usbp) {
  USBD->FADDR = usbp->address;
}

uint32_t usb_alloc_buf(USBDriver *usbp, size_t size) {
  uint32_t buf;
  buf = usbp->bufnext;
  usbp->bufnext += size;
  osalDbgAssert(usbp->bufnext <= 512, "usb buffer space full");
  return buf;
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
  uint8_t hwep;


  if (epcp->in_state != NULL) {
    hwep = usbp->epnext;
    usbp->epnext += 1;
    osalDbgAssert(usbp->epnext <= USB_MAX_ENDPOINTS, "No endpoints left");

    USBD->EP[hwep].BUFSEG = usb_alloc_buf(usbp, epcp->in_maxsize);
    if (epcp->ep_mode == USB_EP_MODE_TYPE_CTRL)
      /* 2 == in */
      USBD->EP[hwep].CFG = (ep << USBD_CFG_EP_NUM_Pos) | (2 << USBD_CFG_STATE_Pos) |  USBD_CFG_CSTALL_Msk;
    else
      USBD->EP[hwep].CFG = (ep << USBD_CFG_EP_NUM_Pos) | (2 << USBD_CFG_STATE_Pos);
    epcp->in_state->hwEp = hwep;
  }

  if (epcp->out_state != NULL) {
    hwep = usbp->epnext;
    usbp->epnext += 1;
    osalDbgAssert(usbp->epnext <= USB_MAX_ENDPOINTS, "No endpoints left");

    USBD->EP[hwep].BUFSEG = usb_alloc_buf(usbp, epcp->out_maxsize);
    if (epcp->ep_mode == USB_EP_MODE_TYPE_CTRL)
      /* 1 == Out */
      USBD->EP[hwep].CFG = (ep << USBD_CFG_EP_NUM_Pos) | (1 << USBD_CFG_STATE_Pos) | USBD_CFG_CSTALL_Msk;
    else
      USBD->EP[hwep].CFG = (ep << USBD_CFG_EP_NUM_Pos) | (1 << USBD_CFG_STATE_Pos);
    epcp->out_state->hwEp = hwep;
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
  (void)usbp;

  for (int i = 0; i < USB_MAX_ENDPOINTS; i++) {
    USBD->EP[i].CFGP |= USBD_CFGP_CLRRDY_Msk;
    USBD->EP[i].CFG &= ~USBD_CFG_STATE_Msk;
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
  (void)ep;

  return EP_STATUS_DISABLED;
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
  return EP_STATUS_DISABLED;
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
  (void)usbp;
  (void)ep;
  int i;
  for (i = 0; i < 8; i++) {
    *buf = usbd_sram[i];
    //*buf = ep0setup_buffer[i];
    ep0setup_buffer[i] = usbd_sram[i];
    buf += 1;
  }
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
  uint32_t rxcnt;
  USBOutEndpointState *oesp = usbp->epc[ep]->out_state;
  if (oesp->rxsize > usbp->epc[ep]->out_maxsize) {
    rxcnt = usbp->epc[ep]->out_maxsize;
  }
  else {
    rxcnt = oesp->rxsize;
  }
  _toggle_dsq(oesp->hwEp, &(oesp->dsq));
  USBD->EP[oesp->hwEp].MXPLD = rxcnt;
}

/**
 * @brief   Starts a transmit operation on an IN endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_start_in(USBDriver *usbp, usbep_t ep) {
  uint32_t i, txcnt;
  USBInEndpointState *iesp = usbp->epc[ep]->in_state;
  if (iesp->txsize > usbp->epc[ep]->in_maxsize) {
    txcnt = usbp->epc[ep]->in_maxsize;
  }
  else {
    txcnt = iesp->txsize;
  }
  for (i = 0; i < txcnt; i++) {
    usbd_sram[(USBD->EP[iesp->hwEp].BUFSEG) + i] = iesp->txbuf[i];
  }
  _toggle_dsq(iesp->hwEp, &(iesp->dsq));
  USBD->EP[iesp->hwEp].MXPLD = txcnt;
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
  USBOutEndpointState *oesp = usbp->epc[ep]->out_state;
  USBD->EP[oesp->hwEp].CFGP |= (USBD_CFGP_SSTALL_Msk | USBD_CFGP_CLRRDY_Msk);
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
  USBInEndpointState *iesp = usbp->epc[ep]->in_state;
  USBD->EP[iesp->hwEp].CFGP |= (USBD_CFGP_SSTALL_Msk | USBD_CFGP_CLRRDY_Msk);
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
  USBOutEndpointState *oesp = usbp->epc[ep]->out_state;
  USBD->EP[oesp->hwEp].CFGP &= ~USBD_CFGP_SSTALL_Msk;
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
  USBInEndpointState *iesp = usbp->epc[ep]->in_state;
  USBD->EP[iesp->hwEp].CFGP &= ~USBD_CFGP_SSTALL_Msk;
}

#endif /* HAL_USE_USB == TRUE */

/** @} */
