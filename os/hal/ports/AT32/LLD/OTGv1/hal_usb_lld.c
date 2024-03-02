/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian

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
 * @file    OTGv1/hal_usb_lld.c
 * @brief   AT32 USB subsystem low level driver source.
 *
 * @addtogroup USB
 * @{
 */

#include <string.h>

#include "hal.h"

#if HAL_USE_USB || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define USBTRDTIM_VALUE_FS      5
#define USBTRDTIM_VALUE_HS      9

#define EP0_MAX_INSIZE          64
#define EP0_MAX_OUTSIZE         64

#if AT32_OTG_STEPPING == 1
#if defined(BOARD_OTG_VBUSIG)
#define GCCFG_INIT_VALUE        (GCCFG_VBUSIG | GCCFG_PWRDOWN)
#else
#define GCCFG_INIT_VALUE        (GCCFG_AVALIDSESEN | GCCFG_BVALIDSESEN |    \
                                 GCCFG_PWRDOWN)
#endif

#elif AT32_OTG_STEPPING == 2
#if defined(BOARD_OTG_VBUSIG_LPM)
#define GCCFG_INIT_VALUE        (GCCFG_VBUSIG | GCCFG_LP_MODE |             \
                                 GCCFG_PWRDOWN)
#elif defined(BOARD_OTG_VBUSIG)
#define GCCFG_INIT_VALUE        (GCCFG_VBUSIG | GCCFG_PWRDOWN)
#elif defined(BOARD_OTG_LPM)
#define GCCFG_INIT_VALUE        (GCCFG_LP_MODE | GCCFG_PWRDOWN)
#else
#define GCCFG_INIT_VALUE        GCCFG_PWRDOWN
#endif

#endif

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief OTG_FS driver identifier.*/
#if AT32_USB_USE_OTG1 || defined(__DOXYGEN__)
USBDriver USBD1;
#endif

/** @brief OTG_HS driver identifier.*/
#if AT32_USB_USE_OTG2 || defined(__DOXYGEN__)
USBDriver USBD2;
#endif

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
  USB_EP_MODE_TYPE_CTRL,
  _usb_ep0setup,
  _usb_ep0in,
  _usb_ep0out,
  0x40,
  0x40,
  &ep0_state.in,
  &ep0_state.out,
  1,
  ep0setup_buffer
};

#if AT32_USB_USE_OTG1
static const at32_otg_params_t fsparams = {
  AT32_USB_OTG1_RX_FIFO_SIZE / 4,
  AT32_OTG1_FIFO_MEM_SIZE,
  AT32_OTG1_ENDPOINTS
};
#endif

#if AT32_USB_USE_OTG2
static const at32_otg_params_t hsparams = {
  AT32_USB_OTG2_RX_FIFO_SIZE / 4,
  AT32_OTG2_FIFO_MEM_SIZE,
  AT32_OTG2_ENDPOINTS
};
#endif

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void otg_core_reset(USBDriver *usbp) {
  at32_otg_t *otgp = usbp->otg;

  /* Wait AHB idle condition.*/
  while ((otgp->GRSTCTL & GRSTCTL_AHBIDLE) == 0)
    ;

  /* Core reset and delay of at least 3 PHY cycles.*/
  otgp->GRSTCTL = GRSTCTL_CSFTRST;
  osalSysPolledDelayX(12);
  while ((otgp->GRSTCTL & GRSTCTL_CSFTRST) != 0)
    ;

  osalSysPolledDelayX(18);

  /* Wait AHB idle condition again.*/
  while ((otgp->GRSTCTL & GRSTCTL_AHBIDLE) == 0)
    ;
}

static void otg_disable_ep(USBDriver *usbp) {
  at32_otg_t *otgp = usbp->otg;
  unsigned i;

  for (i = 0; i <= usbp->otgparams->num_endpoints; i++) {

    if ((otgp->ie[i].DIEPCTL & DIEPCTL_EPTENA) != 0U) {
      otgp->ie[i].DIEPCTL |= DIEPCTL_EPTDIS;
    }

    if ((otgp->oe[i].DOEPCTL & DIEPCTL_EPTENA) != 0U) {
      otgp->oe[i].DOEPCTL |= DIEPCTL_EPTDIS;
    }

    otgp->ie[i].DIEPINT = 0xFFFFFFFF;
    otgp->oe[i].DOEPINT = 0xFFFFFFFF;
  }
  otgp->DAINTMSK = DAINTMSK_OUTEPTMSK(0) | DAINTMSK_INEPTMSK(0);
}

static void otg_rxfifo_flush(USBDriver *usbp) {
  at32_otg_t *otgp = usbp->otg;

  otgp->GRSTCTL = GRSTCTL_RXFFLSH;
  while ((otgp->GRSTCTL & GRSTCTL_RXFFLSH) != 0)
    ;
  /* Wait for 3 PHY Clocks.*/
  osalSysPolledDelayX(18);
}

static void otg_txfifo_flush(USBDriver *usbp, uint32_t fifo) {
  at32_otg_t *otgp = usbp->otg;

  otgp->GRSTCTL = GRSTCTL_TXFNUM(fifo) | GRSTCTL_TXFFLSH;
  while ((otgp->GRSTCTL & GRSTCTL_TXFFLSH) != 0)
    ;
  /* Wait for 3 PHY Clocks.*/
  osalSysPolledDelayX(18);
}

/**
 * @brief   Resets the FIFO RAM memory allocator.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
static void otg_ram_reset(USBDriver *usbp) {

  usbp->pmnext = usbp->otgparams->rx_fifo_size;
}

/**
 * @brief   Allocates a block from the FIFO RAM memory.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] size      size of the packet buffer to allocate in words
 *
 * @notapi
 */
static uint32_t otg_ram_alloc(USBDriver *usbp, size_t size) {
  uint32_t next;

  next = usbp->pmnext;
  usbp->pmnext += size;
  osalDbgAssert(usbp->pmnext <= usbp->otgparams->otg_ram_size,
                "OTG FIFO memory overflow");
  return next;
}

/**
 * @brief   Writes to a TX FIFO.
 *
 * @param[in] fifop     pointer to the FIFO register
 * @param[in] buf       buffer where to copy the endpoint data
 * @param[in] n         maximum number of bytes to copy
 *
 * @notapi
 */
static void otg_fifo_write_from_buffer(volatile uint32_t *fifop,
                                       const uint8_t *buf,
                                       size_t n) {

  osalDbgAssert(n > 0, "is zero");

  while (true) {
    *fifop = *((uint32_t *)buf);
    if (n <= 4) {
      break;
    }
    n -= 4;
    buf += 4;
  }
}

/**
 * @brief   Reads a packet from the RXFIFO.
 *
 * @param[in] fifop     pointer to the FIFO register
 * @param[out] buf      buffer where to copy the endpoint data
 * @param[in] n         number of bytes to pull from the FIFO
 * @param[in] max       number of bytes to copy into the buffer
 *
 * @notapi
 */
static void otg_fifo_read_to_buffer(volatile uint32_t *fifop,
                                    uint8_t *buf,
                                    size_t n,
                                    size_t max) {
  uint32_t w = 0;
  size_t i = 0;

  while (i < n) {
    if ((i & 3) == 0) {
      w = *fifop;
    }
    if (i < max) {
      *buf++ = (uint8_t)w;
      w >>= 8;
    }
    i++;
  }
}

/**
 * @brief   Incoming packets handler.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
static void otg_rxfifo_handler(USBDriver *usbp) {
  uint32_t sts, cnt, ep;

  /* Popping the event word out of the RX FIFO.*/
  sts = usbp->otg->GRXSTSP;

  /* Event details.*/
  cnt = (sts & GRXSTSP_BCNT_MASK) >> GRXSTSP_BCNT_OFF;
  ep  = (sts & GRXSTSP_EPTNUM_MASK) >> GRXSTSP_EPTNUM_OFF;

  switch (sts & GRXSTSP_PKTSTS_MASK) {
  case GRXSTSP_SETUP_DATA:
    otg_fifo_read_to_buffer(usbp->otg->FIFO[0], usbp->epc[ep]->setup_buf,
                            cnt, 8);
    break;
  case GRXSTSP_SETUP_COMP:
    break;
  case GRXSTSP_OUT_DATA:
    otg_fifo_read_to_buffer(usbp->otg->FIFO[0],
                            usbp->epc[ep]->out_state->rxbuf,
                            cnt,
                            usbp->epc[ep]->out_state->rxsize -
                            usbp->epc[ep]->out_state->rxcnt);
    usbp->epc[ep]->out_state->rxbuf += cnt;
    usbp->epc[ep]->out_state->rxcnt += cnt;
    break;
  case GRXSTSP_OUT_COMP:
    break;
  case GRXSTSP_OUT_GLOBAL_NAK:
    break;
  default:
    break;
  }
}

/**
 * @brief   Outgoing packets handler.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
static bool otg_txfifo_handler(USBDriver *usbp, usbep_t ep) {

  /* The TXFIFO is filled until there is space and data to be transmitted.*/
  while (true) {
    uint32_t n;

    /* Transaction end condition.*/
    if (usbp->epc[ep]->in_state->txcnt >= usbp->epc[ep]->in_state->txsize) {
#if 1
      usbp->otg->DIEPEMPMSK &= ~DIEPEMPMSK_INEPTXFEMSK(ep);
#endif
      return true;
    }

    /* Number of bytes remaining in current transaction.*/
    n = usbp->epc[ep]->in_state->txsize - usbp->epc[ep]->in_state->txcnt;
    if (n > usbp->epc[ep]->in_maxsize)
      n = usbp->epc[ep]->in_maxsize;

    /* Checks if in the TXFIFO there is enough space to accommodate the
       next packet.*/
    if (((usbp->otg->ie[ep].DTXFSTS & DTXFSTS_INEPTXFSAV_MASK) * 4) < n)
      return false;

#if AT32_USB_OTGFIFO_FILL_BASEPRI
    __set_BASEPRI(CORTEX_PRIO_MASK(AT32_USB_OTGFIFO_FILL_BASEPRI));
#endif
    otg_fifo_write_from_buffer(usbp->otg->FIFO[ep],
                               usbp->epc[ep]->in_state->txbuf,
                               n);
    usbp->epc[ep]->in_state->txbuf += n;
    usbp->epc[ep]->in_state->txcnt += n;
#if AT32_USB_OTGFIFO_FILL_BASEPRI
  __set_BASEPRI(0);
#endif
  }
}

/**
 * @brief   Generic endpoint IN handler.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
static void otg_epin_handler(USBDriver *usbp, usbep_t ep) {
  at32_otg_t *otgp = usbp->otg;
  uint32_t epint = otgp->ie[ep].DIEPINT;

  otgp->ie[ep].DIEPINT = epint;

  if (epint & DIEPINT_TIMEOUT) {
    /* Timeouts not handled yet, not sure how to handle.*/
  }
  if ((epint & DIEPINT_XFERC) && (otgp->DIEPMSK & DIEPMSK_XFERCMSK)) {
    /* Transmit transfer complete.*/
    USBInEndpointState *isp = usbp->epc[ep]->in_state;

    if (isp->txsize < isp->totsize) {
      /* In case the transaction covered only part of the total transfer
         then another transaction is immediately started in order to
         cover the remaining.*/
      isp->txsize = isp->totsize - isp->txsize;
      isp->txcnt  = 0;
      osalSysLockFromISR();
      usb_lld_start_in(usbp, ep);
      osalSysUnlockFromISR();
    }
    else {
      /* End on IN transfer.*/
      _usb_isr_invoke_in_cb(usbp, ep);
    }
  }
  if ((epint & DIEPINT_TXFEMP) &&
      (otgp->DIEPEMPMSK & DIEPEMPMSK_INEPTXFEMSK(ep))) {
    /* TX FIFO empty or emptying.*/
    otg_txfifo_handler(usbp, ep);
  }
}

/**
 * @brief   Generic endpoint OUT handler.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
static void otg_epout_handler(USBDriver *usbp, usbep_t ep) {
  at32_otg_t *otgp = usbp->otg;
  uint32_t epint = otgp->oe[ep].DOEPINT;

  /* Resets all EP IRQ sources.*/
  otgp->oe[ep].DOEPINT = epint;

  if ((epint & DOEPINT_SETUP) && (otgp->DOEPMSK & DOEPMSK_SETUPMSK)) {
    /* Setup packets handling, setup packets are handled using a
       specific callback.*/
    _usb_isr_invoke_setup_cb(usbp, ep);
  }

  if ((epint & DOEPINT_XFERC) && (otgp->DOEPMSK & DOEPMSK_XFERCMSK)) {
    USBOutEndpointState *osp;

    /* OUT state structure pointer for this endpoint.*/
    osp = usbp->epc[ep]->out_state;

    /* EP0 requires special handling.*/
    if (ep == 0) {

#if defined(AT32_OTG_SEQUENCE_WORKAROUND)
      /* If an OUT transaction end interrupt is processed while the state
         machine is not in an OUT state then it is ignored, this is caused
         on some devices (L4) apparently injecting spurious data complete
         words in the RX FIFO.*/
      if ((usbp->ep0state & USB_OUT_STATE) == 0)
        return;
#endif

      /* In case the transaction covered only part of the total transfer
         then another transaction is immediately started in order to
         cover the remaining.*/
      if (((osp->rxcnt % usbp->epc[ep]->out_maxsize) == 0) &&
          (osp->rxsize < osp->totsize)) {
        osp->rxsize = osp->totsize - osp->rxsize;
        osp->rxcnt  = 0;
        osalSysLockFromISR();
        usb_lld_start_out(usbp, ep);
        osalSysUnlockFromISR();
        return;
      }
    }

    /* End on OUT transfer.*/
    _usb_isr_invoke_out_cb(usbp, ep);
  }
}

/**
 * @brief   Isochronous IN transfer failed handler.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
static void otg_isoc_in_failed_handler(USBDriver *usbp) {
  usbep_t ep;
  at32_otg_t *otgp = usbp->otg;

  for (ep = 0; ep <= usbp->otgparams->num_endpoints; ep++) {
    if (((otgp->ie[ep].DIEPCTL & DIEPCTL_EPTYPE_MASK) == DIEPCTL_EPTYPE_ISO) &&
        ((otgp->ie[ep].DIEPCTL & DIEPCTL_EPTENA) != 0)) {
      /* Endpoint enabled -> ISOC IN transfer failed.*/
      /* Disable endpoint.*/
      otgp->ie[ep].DIEPCTL |= (DIEPCTL_EPTDIS | DIEPCTL_SNAK);
      while (otgp->ie[ep].DIEPCTL & DIEPCTL_EPTENA)
        ;

      /* Flush FIFO.*/
      otg_txfifo_flush(usbp, ep);

      /* Prepare data for next frame.*/
      _usb_isr_invoke_in_cb(usbp, ep);
    }
  }
}

/**
 * @brief   Isochronous OUT transfer failed handler.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
static void otg_isoc_out_failed_handler(USBDriver *usbp) {
  usbep_t ep;
  at32_otg_t *otgp = usbp->otg;

  for (ep = 0; ep <= usbp->otgparams->num_endpoints; ep++) {
    if (((otgp->oe[ep].DOEPCTL & DOEPCTL_EPTYPE_MASK) == DOEPCTL_EPTYPE_ISO) &&
        ((otgp->oe[ep].DOEPCTL & DOEPCTL_EPTENA) != 0)) {
#if 0
      /* Endpoint enabled -> ISOC OUT transfer failed.*/
      /* Disable endpoint.*/
      /* CHTODO:: Core stucks here */
      otgp->oe[ep].DOEPCTL |= (DOEPCTL_EPTDIS | DOEPCTL_SNAK);
      while (otgp->oe[ep].DOEPCTL & DOEPCTL_EPTENA)
        ;
#endif
      /* Prepare transfer for next frame.*/
      _usb_isr_invoke_out_cb(usbp, ep);
    }
  }
}

/**
 * @brief   OTG shared ISR.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
static void usb_lld_serve_interrupt(USBDriver *usbp) {
  at32_otg_t *otgp = usbp->otg;
  uint32_t sts, src;

  sts  = otgp->GINTSTS;
  sts &= otgp->GINTMSK;
  otgp->GINTSTS = sts;

  /* Reset interrupt handling.*/
  if (sts & GINTSTS_USBRST) {
    /* Default reset action.*/
    _usb_reset(usbp);

    /* Preventing execution of more handlers, the core has been reset.*/
    return;
  }

  /* Wake-up handling.*/
  if (sts & GINTSTS_WKUPINT) {
    /* If clocks are gated off, turn them back on (may be the case if
       coming out of suspend mode).*/
    if (otgp->PCGCCTL & PCGCCTL_STOPPCLK) {
      /* Set to zero to un-gate the USB core clocks.*/
      otgp->PCGCCTL &= ~PCGCCTL_STOPPCLK;
    }

    /* Clear the Remote Wake-up Signaling.*/
    otgp->DCTL &= ~DCTL_RWKUPSIG;

    _usb_wakeup(usbp);
  }

  /* Suspend handling.*/
  if (sts & GINTSTS_USBSUSP) {
    /* Stopping all ongoing transfers.*/
    otg_disable_ep(usbp);

    /* Default suspend action.*/
    _usb_suspend(usbp);
  }

  /* Enumeration done.*/
  if (sts & GINTSTS_ENUMDONE) {
    /* Full or High speed timing selection.*/
    if ((otgp->DSTS & DSTS_ENUMSPD_MASK) == DSTS_ENUMSPD_HS_480) {
      otgp->GUSBCFG = (otgp->GUSBCFG & ~(GUSBCFG_USBTRDTIM_MASK)) |
                      GUSBCFG_USBTRDTIM(USBTRDTIM_VALUE_HS);
    }
    else {
      otgp->GUSBCFG = (otgp->GUSBCFG & ~(GUSBCFG_USBTRDTIM_MASK)) |
                      GUSBCFG_USBTRDTIM(USBTRDTIM_VALUE_FS);
    }
  }

  /* SOF interrupt handling.*/
  if (sts & GINTSTS_SOF) {
    /* SOF interrupt was used to detect resume of the USB bus after issuing a
       remote wake up of the host, therefore we disable it again.*/
    if (usbp->config->sof_cb == NULL) {
      otgp->GINTMSK &= ~GINTMSK_SOFMSK;
    }
    if (usbp->state == USB_SUSPENDED) {
      /* If clocks are gated off, turn them back on (may be the case if
         coming out of suspend mode).*/
      if (otgp->PCGCCTL & PCGCCTL_STOPPCLK) {
        /* Set to zero to un-gate the USB core clocks.*/
        otgp->PCGCCTL &= ~PCGCCTL_STOPPCLK;
      }
      _usb_wakeup(usbp);
    }

    _usb_isr_invoke_sof_cb(usbp);
  }

  /* Isochronous IN failed handling */
  if (sts & GINTSTS_INCOMPISOIN) {
    otg_isoc_in_failed_handler(usbp);
  }

  /* Isochronous OUT failed handling */
  if (sts & GINTSTS_INCOMPISOOUT) {
    otg_isoc_out_failed_handler(usbp);
  }

  /* Performing the whole FIFO emptying in the ISR, it is advised to keep
     this IRQ at a very low priority level.*/
  if ((sts & GINTSTS_RXFLVL) != 0U) {
    otg_rxfifo_handler(usbp);
  }

  /* IN/OUT endpoints event handling.*/
  src = otgp->DAINT;
  if (sts & GINTSTS_OEPTINT) {
    if (src & (1 << 16))
      otg_epout_handler(usbp, 0);
    if (src & (1 << 17))
      otg_epout_handler(usbp, 1);
    if (src & (1 << 18))
      otg_epout_handler(usbp, 2);
    if (src & (1 << 19))
      otg_epout_handler(usbp, 3);
#if USB_MAX_ENDPOINTS >= 4
    if (src & (1 << 20))
      otg_epout_handler(usbp, 4);
#endif
#if USB_MAX_ENDPOINTS >= 5
    if (src & (1 << 21))
      otg_epout_handler(usbp, 5);
#endif
#if USB_MAX_ENDPOINTS >= 6
    if (src & (1 << 22))
      otg_epout_handler(usbp, 6);
#endif
#if USB_MAX_ENDPOINTS >= 7
    if (src & (1 << 23))
      otg_epout_handler(usbp, 7);
#endif
#if USB_MAX_ENDPOINTS >= 8
    if (src & (1 << 24))
      otg_epout_handler(usbp, 8);
#endif
  }
  if (sts & GINTSTS_IEPTINT) {
    if (src & (1 << 0))
      otg_epin_handler(usbp, 0);
    if (src & (1 << 1))
      otg_epin_handler(usbp, 1);
    if (src & (1 << 2))
      otg_epin_handler(usbp, 2);
    if (src & (1 << 3))
      otg_epin_handler(usbp, 3);
#if USB_MAX_ENDPOINTS >= 4
    if (src & (1 << 4))
      otg_epin_handler(usbp, 4);
#endif
#if USB_MAX_ENDPOINTS >= 5
    if (src & (1 << 5))
      otg_epin_handler(usbp, 5);
#endif
#if USB_MAX_ENDPOINTS >= 6
    if (src & (1 << 6))
      otg_epin_handler(usbp, 6);
#endif
#if USB_MAX_ENDPOINTS >= 7
    if (src & (1 << 7))
      otg_epin_handler(usbp, 7);
#endif
#if USB_MAX_ENDPOINTS >= 8
    if (src & (1 << 8))
      otg_epin_handler(usbp, 8);
#endif
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if AT32_USB_USE_OTG1 || defined(__DOXYGEN__)
/**
 * @brief   OTG1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_OTG1_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  usb_lld_serve_interrupt(&USBD1);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if AT32_USB_USE_OTG2 || defined(__DOXYGEN__)
/**
 * @brief   OTG2 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_OTG2_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  usb_lld_serve_interrupt(&USBD2);

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level USB driver initialization.
 *
 * @notapi
 */
void usb_lld_init(void) {

  /* Driver initialization.*/
#if AT32_USB_USE_OTG1
  usbObjectInit(&USBD1);
  USBD1.otg       = OTG_FS;
  USBD1.otgparams = &fsparams;

#endif

#if AT32_USB_USE_OTG2
  usbObjectInit(&USBD2);
  USBD2.otg       = OTG_HS;
  USBD2.otgparams = &hsparams;
#endif
}

/**
 * @brief   Configures and activates the USB peripheral.
 * @note    Starting the OTG cell can be a slow operation carried out with
 *          interrupts disabled, perform it before starting time-critical
 *          operations.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_start(USBDriver *usbp) {
  at32_otg_t *otgp = usbp->otg;

  if (usbp->state == USB_STOP) {
    /* Clock activation.*/

#if AT32_USB_USE_OTG1
    if (&USBD1 == usbp) {
      /* OTG FS clock enable and reset.*/
      crmEnableOTG_FS(true);
      crmResetOTG_FS();

      /* Enables IRQ vector.*/
      nvicEnableVector(AT32_OTG1_NUMBER, AT32_USB_OTG1_IRQ_PRIORITY);

      /* - Forced device mode.
         - USB turn-around time = USBTRDTIM_VALUE_FS.
         - Full Speed 1.1 PHY.*/
      otgp->GUSBCFG = GUSBCFG_FDEVMODE | GUSBCFG_USBTRDTIM(USBTRDTIM_VALUE_FS) |
                      GUSBCFG_PHYSEL;

      /* 48MHz 1.1 PHY.*/
      otgp->DCFG = 0x02200000 | DCFG_DEVSPD_FS11;
    }
#endif

#if AT32_USB_USE_OTG2
    if (&USBD2 == usbp) {
      /* OTG HS clock enable and reset.*/
      crmEnableOTG_HS(true);
      crmResetOTG_HS();

      /* ULPI clock is managed depending on the presence of an external
         PHY.*/
#if defined(BOARD_OTG2_USES_ULPI)
      crmEnableOTG_HSULPI(true);
#else
      /* Workaround for the problem described here:
         http://forum.chibios.org/phpbb/viewtopic.php?f=16&t=1798.*/
      crmDisableOTG_HSULPI();
#endif

      /* Enables IRQ vector.*/
      nvicEnableVector(AT32_OTG2_NUMBER, AT32_USB_OTG2_IRQ_PRIORITY);

      /* - Forced device mode.
         - USB turn-around time = USBTRDTIM_VALUE_HS or USBTRDTIM_VALUE_FS.*/
#if defined(BOARD_OTG2_USES_ULPI)
      /* High speed ULPI PHY.*/
      otgp->GUSBCFG = GUSBCFG_FDEVMODE | GUSBCFG_USBTRDTIM(USBTRDTIM_VALUE_HS);
#else
      otgp->GUSBCFG = GUSBCFG_FDEVMODE | GUSBCFG_USBTRDTIM(USBTRDTIM_VALUE_FS) |
                      GUSBCFG_PHYSEL;
#endif

#if defined(BOARD_OTG2_USES_ULPI)
#if AT32_USE_USB_OTG2_HS
      /* USB 2.0 High Speed PHY in HS mode.*/
      otgp->DCFG = 0x02200000 | DCFG_DEVSPD_HS;
#else
      /* USB 2.0 High Speed PHY in FS mode.*/
      otgp->DCFG = 0x02200000 | DCFG_DEVSPD_HS_FS;
#endif
#else
      /* 48MHz 1.1 PHY.*/
      otgp->DCFG = 0x02200000 | DCFG_DEVSPD_FS11;
#endif
    }
#endif

    /* PHY enabled.*/
    otgp->PCGCCTL = 0;

#if defined(BOARD_OTG2_USES_ULPI)
#if AT32_USB_USE_OTG1
    if (&USBD1 == usbp) {
      otgp->GCCFG = GCCFG_INIT_VALUE;
    }
#endif

#if AT32_USB_USE_OTG2
    if (&USBD2 == usbp) {
      otgp->GCCFG = 0;
    }
#endif
#else
    otgp->GCCFG = GCCFG_INIT_VALUE;
#endif

    /* Soft core reset.*/
    otg_core_reset(usbp);

    /* Interrupts on TXFIFOs half empty.*/
    otgp->GAHBCFG = 0;

    /* Endpoints re-initialization.*/
    otg_disable_ep(usbp);

    /* Clear all pending Device Interrupts, only the USB Reset interrupt
       is required initially.*/
    otgp->DIEPMSK  = 0;
    otgp->DOEPMSK  = 0;
    otgp->DAINTMSK = 0;
    if (usbp->config->sof_cb == NULL)
      otgp->GINTMSK  = GINTMSK_ENUMDONEMSK | GINTMSK_USBRSTMSK | GINTMSK_USBSUSPMSK |
                       GINTMSK_ERLYSUSPMSK | GINTMSK_WKUPINTMSK |
                       GINTMSK_INCOMISOINMSK | GINTMSK_INCOMPISOOUTMSK;
    else
      otgp->GINTMSK  = GINTMSK_ENUMDONEMSK | GINTMSK_USBRSTMSK | GINTMSK_USBSUSPMSK |
                       GINTMSK_ERLYSUSPMSK | GINTMSK_WKUPINTMSK |
                       GINTMSK_INCOMISOINMSK | GINTMSK_INCOMPISOOUTMSK |
                       GINTMSK_SOFMSK;

    /* Clears all pending IRQs, if any. */
    otgp->GINTSTS  = 0xFFFFFFFF;

    /* Global interrupts enable.*/
    otgp->GAHBCFG |= GAHBCFG_GLBINTMSK;
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
  at32_otg_t *otgp = usbp->otg;

  /* If in ready state then disables the USB clock.*/
  if (usbp->state != USB_STOP) {

    /* Disabling all endpoints in case the driver has been stopped while
       active.*/
    otg_disable_ep(usbp);

    otgp->DAINTMSK   = 0;
    otgp->GAHBCFG    = 0;
    otgp->GCCFG      = 0;

#if AT32_USB_USE_OTG1
    if (&USBD1 == usbp) {
      nvicDisableVector(AT32_OTG1_NUMBER);
      crmDisableOTG_FS();
    }
#endif

#if AT32_USB_USE_OTG2
    if (&USBD2 == usbp) {
      nvicDisableVector(AT32_OTG2_NUMBER);
      crmDisableOTG_HS();
#if defined(BOARD_OTG2_USES_ULPI)
      crmDisableOTG_HSULPI();
#endif
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
  unsigned i;
  at32_otg_t *otgp = usbp->otg;

  /* Flush the Tx FIFO.*/
  otg_txfifo_flush(usbp, 0);

  /* Endpoint interrupts all disabled and cleared.*/
  otgp->DIEPEMPMSK = 0;
  otgp->DAINTMSK   = DAINTMSK_OUTEPTMSK(0) | DAINTMSK_INEPTMSK(0);

  /* All endpoints in NAK mode, interrupts cleared.*/
  for (i = 0; i <= usbp->otgparams->num_endpoints; i++) {
    otgp->ie[i].DIEPCTL = DIEPCTL_SNAK;
    otgp->oe[i].DOEPCTL = DOEPCTL_SNAK;
    otgp->ie[i].DIEPINT = 0xFFFFFFFF;
    otgp->oe[i].DOEPINT = 0xFFFFFFFF;
  }

  /* Resets the FIFO memory allocator.*/
  otg_ram_reset(usbp);

  /* Receive FIFO size initialization, the address is always zero.*/
  otgp->GRXFSIZ = usbp->otgparams->rx_fifo_size;
  otg_rxfifo_flush(usbp);

  /* Resets the device address to zero.*/
  otgp->DCFG = (otgp->DCFG & ~DCFG_DEVADDR_MASK) | DCFG_DEVADDR(0);

  /* Enables also EP-related interrupt sources.*/
  otgp->GINTMSK  |= GINTMSK_RXFLVLMSK  | GINTMSK_OEPTINTMSK | GINTMSK_IEPTINTMSK;
  otgp->DIEPMSK   = DIEPMSK_TIMEOUTMSK | DIEPMSK_XFERCMSK;
  otgp->DOEPMSK   = DOEPMSK_SETUPMSK   | DOEPMSK_XFERCMSK;

  /* EP0 initialization, it is a special case.*/
  usbp->epc[0] = &ep0config;
  otgp->oe[0].DOEPTSIZ = DOEPTSIZ_SETUPCNT(3);
  otgp->oe[0].DOEPCTL = DOEPCTL_SETD0PID | DOEPCTL_USBACEPT | DOEPCTL_EPTYPE_CTRL |
                        DOEPCTL_MPS(ep0config.out_maxsize);
  otgp->ie[0].DIEPTSIZ = 0;
  otgp->ie[0].DIEPCTL = DIEPCTL_SETD0PID | DIEPCTL_USBACEPT | DIEPCTL_EPTYPE_CTRL |
                        DIEPCTL_TXFNUM(0) | DIEPCTL_MPS(ep0config.in_maxsize);
  otgp->DIEPTXF0 = DIEPTXF_INEPTXFDEP(ep0config.in_maxsize / 4) |
                   DIEPTXF_INEPTXFSTADDR(otg_ram_alloc(usbp,
                                                  ep0config.in_maxsize / 4));
}

/**
 * @brief   Sets the USB address.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_set_address(USBDriver *usbp) {
  at32_otg_t *otgp = usbp->otg;

  otgp->DCFG = (otgp->DCFG & ~DCFG_DEVADDR_MASK) | DCFG_DEVADDR(usbp->address);
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
  uint32_t ctl, fsize;
  at32_otg_t *otgp = usbp->otg;

  /* IN and OUT common parameters.*/
  switch (usbp->epc[ep]->ep_mode & USB_EP_MODE_TYPE) {
  case USB_EP_MODE_TYPE_CTRL:
    ctl = DIEPCTL_SETD0PID | DIEPCTL_USBACEPT | DIEPCTL_EPTYPE_CTRL;
    break;
  case USB_EP_MODE_TYPE_ISOC:
    ctl = DIEPCTL_SETD0PID | DIEPCTL_USBACEPT | DIEPCTL_EPTYPE_ISO;
    break;
  case USB_EP_MODE_TYPE_BULK:
    ctl = DIEPCTL_SETD0PID | DIEPCTL_USBACEPT | DIEPCTL_EPTYPE_BULK;
    break;
  case USB_EP_MODE_TYPE_INTR:
    ctl = DIEPCTL_SETD0PID | DIEPCTL_USBACEPT | DIEPCTL_EPTYPE_INTR;
    break;
  default:
    return;
  }

  /* OUT endpoint activation or deactivation.*/
  otgp->oe[ep].DOEPTSIZ = 0;
  if (usbp->epc[ep]->out_state != NULL) {
    otgp->oe[ep].DOEPCTL = ctl | DOEPCTL_MPS(usbp->epc[ep]->out_maxsize);
    otgp->DAINTMSK |= DAINTMSK_OUTEPTMSK(ep);
  }
  else {
    otgp->oe[ep].DOEPCTL &= ~DOEPCTL_USBACEPT;
    otgp->DAINTMSK &= ~DAINTMSK_OUTEPTMSK(ep);
  }

  /* IN endpoint activation or deactivation.*/
  otgp->ie[ep].DIEPTSIZ = 0;
  if (usbp->epc[ep]->in_state != NULL) {
    /* FIFO allocation for the IN endpoint.*/
    fsize = usbp->epc[ep]->in_maxsize / 4;
    if (usbp->epc[ep]->in_multiplier > 1)
      fsize *= usbp->epc[ep]->in_multiplier;
    otgp->DIEPTXF[ep - 1] = DIEPTXF_INEPTXFDEP(fsize) |
                            DIEPTXF_INEPTXFSTADDR(otg_ram_alloc(usbp, fsize));
    otg_txfifo_flush(usbp, ep);

    otgp->ie[ep].DIEPCTL = ctl |
                           DIEPCTL_TXFNUM(ep) |
                           DIEPCTL_MPS(usbp->epc[ep]->in_maxsize);
    otgp->DAINTMSK |= DAINTMSK_INEPTMSK(ep);
  }
  else {
    otgp->DIEPTXF[ep - 1] = 0x02000400; /* Reset value.*/
    otg_txfifo_flush(usbp, ep);
    otgp->ie[ep].DIEPCTL &= ~DIEPCTL_USBACEPT;
    otgp->DAINTMSK &= ~DAINTMSK_INEPTMSK(ep);
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

  /* Resets the FIFO memory allocator.*/
  otg_ram_reset(usbp);

  /* Disabling all endpoints.*/
  otg_disable_ep(usbp);
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
  uint32_t ctl;

  (void)usbp;

  ctl = usbp->otg->oe[ep].DOEPCTL;
  if (!(ctl & DOEPCTL_USBACEPT))
    return EP_STATUS_DISABLED;
  if (ctl & DOEPCTL_STALL)
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
  uint32_t ctl;

  (void)usbp;

  ctl = usbp->otg->ie[ep].DIEPCTL;
  if (!(ctl & DIEPCTL_USBACEPT))
    return EP_STATUS_DISABLED;
  if (ctl & DIEPCTL_STALL)
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

  memcpy(buf, usbp->epc[ep]->setup_buf, 8);
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
  uint32_t pcnt, rxsize;
  USBOutEndpointState *osp = usbp->epc[ep]->out_state;

  /* Transfer initialization.*/
  osp->totsize = osp->rxsize;
  if ((ep == 0) && (osp->rxsize > EP0_MAX_OUTSIZE))
      osp->rxsize = EP0_MAX_OUTSIZE;

  /* Transaction size is rounded to a multiple of packet size because the
     following requirement in the RM:
     "For OUT transfers, the transfer size field in the endpoint's transfer
     size register must be a multiple of the maximum packet size of the
     endpoint, adjusted to the Word boundary".*/
  pcnt   = (osp->rxsize + usbp->epc[ep]->out_maxsize - 1U) /
           usbp->epc[ep]->out_maxsize;
  rxsize = (pcnt * usbp->epc[ep]->out_maxsize + 3U) & 0xFFFFFFFCU;

  /* Setting up transaction parameters in DOEPTSIZ.*/
  usbp->otg->oe[ep].DOEPTSIZ = DOEPTSIZ_SETUPCNT(3) | DOEPTSIZ_PKTCNT(pcnt) |
                               DOEPTSIZ_XFERSIZE(rxsize);

  /* Special case of isochronous endpoint.*/
  if ((usbp->epc[ep]->ep_mode & USB_EP_MODE_TYPE) == USB_EP_MODE_TYPE_ISOC) {
    /* Odd/even bit toggling for isochronous endpoint.*/
    if (usbp->otg->DSTS & DSTS_SOFFN_ODD)
      usbp->otg->oe[ep].DOEPCTL |= DOEPCTL_SETEVENFR;
    else
      usbp->otg->oe[ep].DOEPCTL |= DOEPCTL_SETODDFR;
  }

  /* Starting operation.*/
  usbp->otg->oe[ep].DOEPCTL |= DOEPCTL_EPTENA | DOEPCTL_CNAK;
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
  USBInEndpointState *isp = usbp->epc[ep]->in_state;

  /* Transfer initialization.*/
  isp->totsize = isp->txsize;
  if (isp->txsize == 0) {
    /* Special case, sending zero size packet.*/
    usbp->otg->ie[ep].DIEPTSIZ = DIEPTSIZ_PKTCNT(1) | DIEPTSIZ_XFERSIZE(0);
  }
  else {
    if ((ep == 0) && (isp->txsize > EP0_MAX_INSIZE))
      isp->txsize = EP0_MAX_INSIZE;

    /* Normal case.*/
    uint32_t pcnt = (isp->txsize + usbp->epc[ep]->in_maxsize - 1) /
                    usbp->epc[ep]->in_maxsize;
    /* CHTODO: Support more than one packet per frame for isochronous transfers.*/
    usbp->otg->ie[ep].DIEPTSIZ = DIEPTSIZ_MC(1) | DIEPTSIZ_PKTCNT(pcnt) |
                                 DIEPTSIZ_XFERSIZE(isp->txsize);
  }

  /* Special case of isochronous endpoint.*/
  if ((usbp->epc[ep]->ep_mode & USB_EP_MODE_TYPE) == USB_EP_MODE_TYPE_ISOC) {
    /* Odd/even bit toggling.*/
    if (usbp->otg->DSTS & DSTS_SOFFN_ODD)
      usbp->otg->ie[ep].DIEPCTL |= DIEPCTL_SETEVENFR;
    else
      usbp->otg->ie[ep].DIEPCTL |= DIEPCTL_SETODDFR;
  }

  /* Starting operation.*/
  usbp->otg->ie[ep].DIEPCTL |= DIEPCTL_EPTENA | DIEPCTL_CNAK;
  usbp->otg->DIEPEMPMSK |= DIEPEMPMSK_INEPTXFEMSK(ep);
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

  usbp->otg->oe[ep].DOEPCTL |= DOEPCTL_STALL;
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

  usbp->otg->ie[ep].DIEPCTL |= DIEPCTL_STALL;
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

  usbp->otg->oe[ep].DOEPCTL &= ~DOEPCTL_STALL;
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

  usbp->otg->ie[ep].DIEPCTL &= ~DIEPCTL_STALL;
}

#endif /* HAL_USE_USB */

/** @} */
