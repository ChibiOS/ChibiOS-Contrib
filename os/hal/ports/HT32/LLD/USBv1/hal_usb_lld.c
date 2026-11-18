/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio
              Copyright (C) 2020 Yaotian Feng

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
 * @brief   HT32 USB subsystem low level driver source.
 *
 * @addtogroup USB
 * @{
 */

#include "hal.h"

#if (HAL_USE_USB == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define roundup2(x, m) (((x) + (m) - 1) & ~((m) - 1))

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   USB1 driver identifier.
 */
#if HT32_USB_USE_USB0 || defined(__DOXYGEN__)
USBDriver USBD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/**
 * @brief   EP0 state.
 * @note    IN completion and OUT status can be pending together.
 */
static struct {
    /**
   * @brief   IN EP0 state.
   */
    USBInEndpointState in;
    /**
   * @brief   OUT EP0 state.
   */
    USBOutEndpointState out;
} ep0_state;

/* Snapshot SETUP before acknowledging it, so callbacks never read stale SRAM
   after a following SETUP has arrived. */
static uint8_t ep0_setup[8];

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
    ep0_setup
};

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static uint32_t usb_get_int_flags(void){
    return USB->IER & USB->ISR;
}

static void usb_clear_int_flags(uint32_t flags){
    /* Holtek USBD_ClearINT: interrupt status is acknowledged with ones. */
    HT32_USB_WRITE_ISR(flags);
}

static uint32_t usb_get_ep_int_flags(int ep){
    return USB->EP[ep].IER & USB->EP[ep].ISR;
}

static void usb_clear_ep_int_flags(int ep, uint32_t flags){
    // flags are cleared by writing 1
    HT32_USB_WRITE_EP_ISR(ep, flags);
}

/* A newer control transaction or bus reset must not be armed by an older
   completion callback while this interrupt is being handled. */
static bool usb_transfer_superseded(usbep_t ep) {
    return (USB->ISR & USBISR_URSTIF) ||
           ((ep == 0) && (USB->EP[0].ISR &
            (USBEPnISR_SDRXIF | USBEPnISR_SDERIF)));
}

static size_t usb_epmem_alloc(USBDriver *usbp, size_t size) {
    const size_t epmo = usbp->epmem_next;

    usbp->epmem_next = roundup2(epmo + size, 4);
    osalDbgAssert(usbp->epmem_next <= 0x400, "EPSRAM exhausted");
    return epmo;
}

static void usb_packet_transmit(USBDriver *usbp, usbep_t ep, size_t n)
{
    if (usb_transfer_superseded(ep))
        return;
    const USBEndpointConfig * const epc = usbp->epc[ep];
    USBInEndpointState * const isp = epc->in_state;

    if (n > (size_t)epc->in_maxsize)
        n = (size_t)epc->in_maxsize;

    if ((USB->EP[ep].TCR & USBEPnTCR_TCNT) == 0) {
        const uint32_t cfgr = USB->EP[ep].CFGR;
        volatile uint32_t * const EPSRAM = (void *)(USB_SRAM_BASE + (cfgr & 0x3ff));
        for (size_t i = 0; i < n; i += 4) {
            uint32_t word = 0;
            if (i + 0 < n)
                word |= (uint32_t)isp->txbuf[i+0]<<0;
            if (i + 1 < n)
                word |= (uint32_t)isp->txbuf[i+1]<<8;
            if (i + 2 < n)
                word |= (uint32_t)isp->txbuf[i+2]<<16;
            if (i + 3 < n)
                word |= (uint32_t)isp->txbuf[i+3]<<24;
            EPSRAM[i/4] = word;
        }

        USB->EP[ep].TCR = n;
        isp->txlastpktlen = n;
        HT32_USB_WRITE_EP_CSR(ep, USB->EP[ep].CSR & USBEPnCSR_NAKTX);
    }
}

static size_t usb_packet_receive(USBDriver *usbp, usbep_t ep) {
    const USBEndpointConfig *epcp = usbp->epc[ep];
    USBOutEndpointState *osp = epcp->out_state;
    const size_t n = (USB->EP[ep].TCR >> ((ep == 0) ? 16 : 0)) &
                     USBEPnTCR_TCNT;
    size_t copied = n < osp->rxsize ? n : osp->rxsize;
    if (copied > epcp->out_maxsize)
        copied = epcp->out_maxsize;
    if (osp->rxbuf == NULL)
        copied = 0;
    const uint32_t cfgr = USB->EP[ep].CFGR;
    volatile uint32_t *const EPSRAM = (void *)(USB_SRAM_BASE +
        (cfgr & USBEPnCFGR_EPBUFA) +
        ((ep == 0) ? ((cfgr & USBEPnCFGR_EPLEN) >> 10) : 0));

    for (size_t i = 0; i < copied; i += 4) {
        const uint32_t word = EPSRAM[i/4];
        if (i + 0 < copied)
            osp->rxbuf[i + 0] = word >> 0;
        if (i + 1 < copied)
            osp->rxbuf[i + 1] = word >> 8;
        if (i + 2 < copied)
            osp->rxbuf[i + 2] = word >> 16;
        if (i + 3 < copied)
            osp->rxbuf[i + 3] = word >> 24;
    }

    if (copied != 0)
        osp->rxbuf += copied;
    osp->rxcnt += n;
    osp->rxsize -= copied;
    if (osp->rxpkts != 0)
        osp->rxpkts--;
    return n;
}

/*===========================================================================*/
/* Driver interrupt handlers and threads.                                    */
/*===========================================================================*/

#if (HT32_USB_USE_USB0 == TRUE) || defined(__DOXYGEN__)

/**
 * @brief USB interrupt handler.
 * @isr
 */
OSAL_IRQ_HANDLER(HT32_USB_IRQ_VECTOR) {
    OSAL_IRQ_PROLOGUE();
    USBDriver *usbp = &USBD1;
    const uint32_t isr = usb_get_int_flags();

    /* A bus reset invalidates every endpoint event in this snapshot. */
    if (isr & USBISR_URSTIF) {
        usb_clear_int_flags(USBISR_URSTIF);
        _usb_reset(usbp);
        OSAL_IRQ_EPILOGUE();
        return;
    }

    if (isr & USBISR_SOFIF) {
        usb_clear_int_flags(USBISR_SOFIF);
        _usb_isr_invoke_sof_cb(usbp);
    }
    if (isr & USBISR_SUSPIF) {
        usb_clear_int_flags(USBISR_SUSPIF);
        _usb_suspend(usbp);
    }
    if (isr & USBISR_RSMIF) {
        usb_clear_int_flags(USBISR_RSMIF);
        _usb_wakeup(usbp);
    }

    for (usbep_t ep = 0; ep <= USB_MAX_ENDPOINTS; ++ep) {
        const uint32_t mask = USBISR_EP0IF << ep;
        if (USB->ISR & USBISR_URSTIF)
            break;
        if ((isr & mask) == 0)
            continue;
        uint32_t episr = usb_get_ep_int_flags(ep);

        /* Acknowledge the old summary before callbacks can rearm hardware.
           Endpoint flags are acknowledged individually, before rearming. */
        usb_clear_int_flags(mask);
        const USBEndpointConfig *epcp = usbp->epc[ep];
        if ((epcp == NULL) ||
            ((USB->EP[ep].CFGR & USBEPnCFGR_EPEN) == 0)) {
            usb_clear_ep_int_flags(ep, episr);
            continue;
        }

        if ((ep == 0) &&
            (episr & (USBEPnISR_SDRXIF | USBEPnISR_SDERIF))) {
            /* SETUP supersedes both directions of the previous transfer.
               Do not clear DATA toggles: hardware selects DATA1 on SETUP. */
            const uint32_t csr = USB->EP[0].CSR;
            HT32_USB_WRITE_EP_CSR(0,
                csr & (USBEPnCSR_STLTX | USBEPnCSR_STLRX));
            USB->EP[0].TCR = 0;
            usbp->transmitting &= ~1U;
            usbp->receiving &= ~1U;
            usbp->ep0endcb = NULL;
            if ((episr & USBEPnISR_SDERIF) == 0) {
                volatile uint32_t *const sram = (void *)USB_SRAM_BASE;
                for (size_t i = 0; i < 8; i += 4) {
                    const uint32_t word = sram[i / 4];
                    for (size_t j = 0; j < 4; ++j)
                        ep0_setup[i + j] = word >> (j * 8);
                }
            }
            usb_clear_ep_int_flags(0, USB->EP[0].ISR);
            if (episr & USBEPnISR_SDERIF) {
                usbp->ep0state = USB_EP0_ERROR;
                usb_lld_stall_in(usbp, 0);
                usb_lld_stall_out(usbp, 0);
            } else {
                _usb_isr_invoke_setup_cb(usbp, 0);
            }
            continue;
        }

        /* EP0's final IN and OUT status can be co-pending. IN must advance
           the control state machine before the OUT status is delivered. */
        if (episr & USBEPnISR_IDTXIF) {
            usb_clear_ep_int_flags(ep, USBEPnISR_IDTXIF);
            if (usb_transfer_superseded(ep))
                break;
            if ((epcp->in_state != NULL) &&
                (usbp->transmitting & (1U << ep))) {
                USBInEndpointState *isp = epcp->in_state;
                const size_t n = isp->txlastpktlen;
                isp->txcnt += n;
                if (isp->txcnt < isp->txsize) {
                    isp->txbuf += n;
                    osalSysLockFromISR();
                    usb_packet_transmit(usbp, ep, isp->txsize - isp->txcnt);
                    osalSysUnlockFromISR();
                } else {
                    if (!usb_transfer_superseded(ep)) {
                        _usb_isr_invoke_in_cb(usbp, ep);
                    }
                }
            }
        }

        /* An IN callback may have reconfigured/disabled the endpoints or
           a new SETUP/reset may have arrived while it ran. */
        epcp = usbp->epc[ep];
        if (usb_transfer_superseded(ep))
            break;
        if (episr & USBEPnISR_ODRXIF) {
            usb_clear_ep_int_flags(ep, USBEPnISR_ODRXIF);
            if ((epcp != NULL) && (epcp->out_state != NULL) &&
                (USB->EP[ep].CFGR & USBEPnCFGR_EPEN) &&
                (usbp->receiving & (1U << ep))) {
                USBOutEndpointState *osp = epcp->out_state;
                const size_t n = usb_packet_receive(usbp, ep);
                if ((n != epcp->out_maxsize) || (osp->rxpkts == 0) ||
                    (osp->rxsize == 0)) {
                    _usb_isr_invoke_out_cb(usbp, ep);
                } else {
                    HT32_USB_WRITE_EP_CSR(ep,
                        USB->EP[ep].CSR & USBEPnCSR_NAKRX);
                }
            }
        }
    }

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
void usb_lld_init(void){
#if HT32_USB_USE_USB0 == TRUE
    /* Driver initialization.*/
    usbObjectInit(&USBD1);

    // USB prescaler
    CKCU->GCFGR = (CKCU->GCFGR & ~CKCU_GCFGR_USBPRE_MASK) | ((HT32_USB_PRESCALER - 1) << 22);
    // enable USB clock
    CKCU->AHBCCR |= CKCU_AHBCCR_USBEN;
#endif // HT32_USB_USE_USB1
}

/**
 * @brief   Configures and activates the USB peripheral.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_start(USBDriver *usbp){
    if (usbp->state == USB_STOP) {
        /* Enables the peripheral.*/
#if HT32_USB_USE_USB0 == TRUE
        if (&USBD1 == usbp) {
            // enable USB IRQ
            nvicEnableVector(USB_IRQn, HT32_USB_USB0_IRQ_PRIORITY);
            /* USBD_PowerUp */
            USB->CSR = USBCSR_DPWKEN | USBCSR_DPPUEN | USBCSR_LPMODE | USBCSR_PDWN;
            // enable usb interrupts
            HT32_USB_WRITE_ISR(~0U);
            USB->CSR &= ~USBCSR_DPWKEN;
            USB->IER = USBIER_UGIE | USBIER_SOFIE |
                USBIER_URSTIE | USBIER_RSMIE | USBIER_SUSPIE |
                USBIER_EP0IE;
        }
#endif // HT32_USB_USE_USB1
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

    if (usbp->state != USB_STOP) {
        /* Resets the peripheral.*/

        /* Disables the peripheral.*/
#if HT32_USB_USE_USB0 == TRUE
        if (&USBD1 == usbp) {
            nvicDisableVector(USB_IRQn);
            USB->IER = 0;
            USB->CSR &= ~USBCSR_DPPUEN;
            /* Resets the peripheral.*/
            RSTCU->AHBPRSTR = RSTCU_AHBPRSTR_USBRST;
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
    /* Match Holtek's DeInit/PowerOn reset, preserving attachment. Bit 12
       is the power-on control used by USBD_PowerOn in the vendor driver. */
    const uint32_t pullup = USB->CSR & USBCSR_DPPUEN;
    USB->IER = 0;
    RSTCU->AHBPRSTR = RSTCU_AHBPRSTR_USBRST;
    USB->CSR = (1U << 12) | pullup;
    USB->DEVAR = 0;
    for (usbep_t ep = 0; ep <= USB_MAX_ENDPOINTS; ++ep) {
        USB->EP[ep].IER = 0;
        USB->EP[ep].CFGR = 0;
        USB->EP[ep].TCR = 0;
        HT32_USB_WRITE_EP_CSR(ep, USB->EP[ep].CSR &
            (USBEPnCSR_DTGTX | USBEPnCSR_DTGRX | USBEPnCSR_NAKRX |
             USBEPnCSR_STLTX | USBEPnCSR_STLRX));
        HT32_USB_WRITE_EP_ISR(ep, ~0U);
    }
    HT32_USB_WRITE_ISR(~0U);
    usbp->ep0endcb = NULL;

    /* Post reset initialization.*/
    usbp->epmem_next = 8;

    /* EP0 initialization.*/
    usbp->epc[0] = &ep0config;
    usb_lld_init_endpoint(usbp, 0);

    USB->IER = USBIER_UGIE | USBIER_SOFIE |
        USBIER_URSTIE | USBIER_RSMIE | USBIER_SUSPIE |
        USBIER_EP0IE;
}

/**
 * @brief   Sets the USB address.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_set_address(USBDriver *usbp) {
    USB->CSR |= USBCSR_ADRSET;
    USB->DEVAR = usbp->address & 0x7f;
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
    if(ep > USB_MAX_ENDPOINTS)
        return;

    const USBEndpointConfig *epcp = usbp->epc[ep];
    USB->EP[ep].IER = 0;
    USB->EP[ep].CFGR = 0;
    USB->IER &= ~(USBIER_EP0IE << ep);
    HT32_USB_WRITE_EP_ISR(ep, ~0U);
    usb_clear_int_flags(USBISR_EP0IF << ep);
    if (epcp == NULL)
        return;
    const bool has_in = epcp->in_state != NULL;
    const bool has_out = epcp->out_state != NULL;
    if ((has_in != (epcp->in_maxsize != 0)) ||
        (has_out != (epcp->out_maxsize != 0)) ||
        (!has_in && !has_out) ||
        (roundup2((size_t)epcp->in_maxsize, 4U) > (USBEPnCFGR_EPLEN >> 10)) ||
        (roundup2((size_t)epcp->out_maxsize, 4U) > (USBEPnCFGR_EPLEN >> 10)))
        return;
    if (ep == 0) {
        if (!has_in || !has_out ||
            (epcp->in_maxsize != epcp->out_maxsize) ||
            ((epcp->ep_mode & USB_EP_MODE_TYPE) != USB_EP_MODE_TYPE_CTRL))
            return;
    } else if ((has_in && has_out) ||
               ((epcp->ep_mode & USB_EP_MODE_TYPE) == USB_EP_MODE_TYPE_CTRL)) {
        /* Non-control hardware endpoints have one direction and one buffer. */
        return;
    }
    const size_t allocation = roundup2(epcp->in_maxsize, 4) +
                              roundup2(epcp->out_maxsize, 4);
    if (usbp->epmem_next + allocation > 0x400)
        return;
    uint32_t cfgr = USBEPnCFGR_EPEN | ((uint32_t)ep << 24);
    size_t epmo;

    switch(epcp->ep_mode & USB_EP_MODE_TYPE){
        case USB_EP_MODE_TYPE_CTRL:
            break;
        case USB_EP_MODE_TYPE_ISOC:
            cfgr |= USBEPnCFGR_EPTYPE;
            break;
        case USB_EP_MODE_TYPE_BULK:
            break;
        case USB_EP_MODE_TYPE_INTR:
            break;
        default:
            return;
    }

    if (epcp->in_state != NULL) {
        epmo = usb_epmem_alloc(usbp, epcp->in_maxsize);
        cfgr |= epmo << 0;
        cfgr |= roundup2(epcp->in_maxsize, 4) << 10;
        cfgr |= USBEPnCFGR_EPDIR;
    }

    if (epcp->out_state != NULL) {
        epmo = usb_epmem_alloc(usbp, epcp->out_maxsize);
        if (ep > 0) {
            cfgr |= epmo << 0;
            cfgr |= roundup2(epcp->out_maxsize, 4) << 10;
        }
    }

    USB->EP[ep].TCR = 0;
    /* Vendor EPTReset clears asserted toggles/NAKRX; halt bits also use
       write-one-toggle. Never attempt to set NAK bits in software. */
    HT32_USB_WRITE_EP_CSR(ep, USB->EP[ep].CSR &
        (USBEPnCSR_DTGTX | USBEPnCSR_DTGRX | USBEPnCSR_NAKRX |
         USBEPnCSR_STLTX | USBEPnCSR_STLRX));
    USB->EP[ep].CFGR = cfgr;
    USB->EP[ep].IER = (ep == 0) ?
      (USBEPnIER_SDRXIE | USBEPnIER_SDERIE |
       USBEPnIER_IDTXIE | USBEPnIER_ODRXIE) :
      (has_in ? USBEPnIER_IDTXIE : USBEPnIER_ODRXIE);
    USB->IER |= (USBIER_EP0IE << ep);
}

/**
 * @brief   Disables all the active endpoints except the endpoint zero.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_disable_endpoints(USBDriver *usbp) {
    for (usbep_t ep = 1; ep <= USB_MAX_ENDPOINTS; ++ep) {
        USB->EP[ep].CFGR = 0;
        USB->EP[ep].IER = 0;
        USB->EP[ep].TCR = 0;
        HT32_USB_WRITE_EP_CSR(ep, USB->EP[ep].CSR &
            (USBEPnCSR_DTGTX | USBEPnCSR_DTGRX | USBEPnCSR_NAKRX |
             USBEPnCSR_STLTX | USBEPnCSR_STLRX));
        HT32_USB_WRITE_EP_ISR(ep, ~0U);
        USB->IER &= ~(USBIER_EP0IE << ep);
        usb_clear_int_flags(USBISR_EP0IF << ep);
    }

    const uint32_t cfgr = USB->EP[0].CFGR;
    usbp->epmem_next = (cfgr & USBEPnCFGR_EPBUFA) +
                      2 * ((cfgr & USBEPnCFGR_EPLEN) >> 10);
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
usbepstatus_t usb_lld_get_status_out(USBDriver *usbp, usbep_t ep)
{
    if ((ep > USB_MAX_ENDPOINTS) || (usbp->epc[ep] == NULL) ||
        (usbp->epc[ep]->out_state == NULL))
        return EP_STATUS_DISABLED;

    if ((USB->EP[ep].CFGR & USBEPnCFGR_EPEN) == 0)
        return EP_STATUS_DISABLED;
    if ((ep != 0) && (USB->EP[ep].CFGR & USBEPnCFGR_EPDIR))
        return EP_STATUS_DISABLED;
    if ((USB->EP[ep].CSR & USBEPnCSR_STLRX) != 0)
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

  if ((ep > USB_MAX_ENDPOINTS) || (usbp->epc[ep] == NULL) ||
      (usbp->epc[ep]->in_state == NULL))
    return EP_STATUS_DISABLED;

  if ((USB->EP[ep].CFGR & USBEPnCFGR_EPEN) == 0)
    return EP_STATUS_DISABLED;
  if ((ep != 0) && ((USB->EP[ep].CFGR & USBEPnCFGR_EPDIR) == 0))
    return EP_STATUS_DISABLED;
  if ((USB->EP[ep].CSR & USBEPnCSR_STLTX) != 0)
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
    for (size_t i = 0; i < sizeof ep0_setup; ++i)
        buf[i] = ep0_setup[i];
    (void)usbp;
    (void)ep;
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
    if ((usb_lld_get_status_out(usbp, ep) == EP_STATUS_DISABLED) ||
        usb_transfer_superseded(ep))
        return;
    USBOutEndpointState * const osp = usbp->epc[ep]->out_state;

    if (osp->rxsize == 0)
        osp->rxpkts = 1;
    else
        osp->rxpkts = (osp->rxsize + usbp->epc[ep]->out_maxsize - 1) /
            usbp->epc[ep]->out_maxsize;
    HT32_USB_WRITE_EP_CSR(ep, USB->EP[ep].CSR & USBEPnCSR_NAKRX);
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
  if ((usb_lld_get_status_in(usbp, ep) == EP_STATUS_DISABLED) ||
      usb_transfer_superseded(ep))
    return;
  USBInEndpointState * const isp = usbp->epc[ep]->in_state;

  isp->txlastpktlen = 0;
  usb_packet_transmit(usbp, ep, isp->txsize);
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

  if (usb_lld_get_status_out(usbp, ep) == EP_STATUS_DISABLED)
    return;

  HT32_USB_WRITE_EP_CSR(ep, (~USB->EP[ep].CSR) & USBEPnCSR_STLRX);
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

  if (usb_lld_get_status_in(usbp, ep) == EP_STATUS_DISABLED)
    return;

  HT32_USB_WRITE_EP_CSR(ep, (~USB->EP[ep].CSR) & USBEPnCSR_STLTX);
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

  if (usb_lld_get_status_out(usbp, ep) == EP_STATUS_DISABLED)
    return;

  HT32_USB_WRITE_EP_CSR(ep, USB->EP[ep].CSR &
                       (USBEPnCSR_STLRX | USBEPnCSR_DTGRX));
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

  if (usb_lld_get_status_in(usbp, ep) == EP_STATUS_DISABLED)
    return;

  HT32_USB_WRITE_EP_CSR(ep, USB->EP[ep].CSR &
                       (USBEPnCSR_STLTX | USBEPnCSR_DTGTX));
}

#endif /* HAL_USE_USB == TRUE */

/** @} */
