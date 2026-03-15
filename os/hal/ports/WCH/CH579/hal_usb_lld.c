/**
 * @file    hal_usb_lld.c
 * @brief   CH579M USB Full-Speed device low level driver.
 *
 * @details This is a minimally-complete driver that lets ChibiOS USB HAL
 *          run and QMK boot.  The register-level USB sequences follow the
 *          WCH CH579EVT/EXAM/USB/Device/DevHID/ reference code and the
 *          CH579DS1 datasheet Chapter 17.
 *
 *          Endpoint mapping (confirmed from lsusb of stock firmware):
 *          EP0  →  8-byte control (bMaxPacketSize0 = 8)
 *          EP1  →  64-byte IN   (keyboard HID reports)
 *          EP2  →  4-byte IN    (consumer/encoder HID, optional)
 *
 *          Buffer layout (512-byte RAM at 0x40008800):
 *          0x00 – 0x07   EP0 shared buf  (8 bytes)
 *          0x40 – 0x7F   EP1 IN buf      (64 bytes)
 *          0x80 – 0x83   EP2 IN buf      (4 bytes)
 *
 * @addtogroup USB
 * @{
 */

#include "hal.h"
#include <string.h>

#if HAL_USE_USB || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   USB1 driver.
 */
USBDriver USBD1;

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/**
 * @brief   Endpoint buffer RAM (in normal SRAM 0x20000000+).
 *
 * @details WCH CH579 USB DMA engine accesses normal SRAM via R16_UEPn_DMA.
 *          R16_UEPn_DMA stores the lower 16 bits of the SRAM buffer address;
 *          the SIE reconstructs the full 32-bit address by prepending the SRAM
 *          base (0x20000000).  Buffers must therefore live in normal SRAM —
 *          NOT at 0x40008800 (USB peripheral register space) which the DMA
 *          engine cannot reach via the SRAM bus.
 *
 *          Buffer sizes match the hardware endpoint max-packet limits:
 *          EP0: 8 bytes (bMaxPacketSize0 = 8, confirmed from stock lsusb)
 *          EP1: 64 bytes IN (keyboard HID)
 *          EP2: 4 bytes IN  (consumer/encoder HID, optional)
 */
static uint8_t ep0_buf[8]      __attribute__((aligned(4)));
static uint8_t ep1_in_buf[64]  __attribute__((aligned(4)));
static uint8_t ep2_in_buf[32]  __attribute__((aligned(4)));

/**
 * @brief   EP0 TX data toggle tracker.
 *
 * @details The CH579 USB SIE does NOT auto-toggle EP0 — firmware must manage
 *          RB_UEP_T_TOG (bit6) in R8_UEP0_CTRL manually.
 *          USB spec: first IN after SETUP must be DATA1 (toggle=1).
 *          Reset to 1 at every SETUP so each new control transfer starts correctly.
 */
static uint8_t ep0_tx_tog;

/**
 * @brief   Static EP0 endpoint state (IN + OUT share the same 8-byte buffer).
 */
static struct {
  USBInEndpointState  in;
  USBOutEndpointState out;
} ep0_state;

/**
 * @brief   Static EP0 endpoint configuration.
 *
 * @details ChibiOS _usb_reset() clears epc[0] = NULL on every bus reset.
 *          QMK's event callback never re-initialises EP0 via usbInitEndpointI,
 *          so usb_lld_reset() must restore epc[0] from this static config —
 *          identical to the RP2040 LLD approach.
 */
static const USBEndpointConfig ep0config = {
  .ep_mode     = USB_EP_MODE_TYPE_CTRL,
  .setup_cb    = _usb_ep0setup,
  .in_cb       = _usb_ep0in,
  .out_cb      = _usb_ep0out,
  .in_maxsize  = USB_EP0_PACKET_SIZE,
  .out_maxsize = USB_EP0_PACKET_SIZE,
  .in_state    = &ep0_state.in,
  .out_state   = &ep0_state.out,
  .ep_bufoffset = 0,
};

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/**
 * @brief   USB interrupt handler.
 * @note    USB_IRQn = 6 → vector address 0x0058 → ChibiOS slot Vector58.
 *          Formula: hex(0x40 + IRQn×4) = hex(0x40+24) = 0x58.
 *          The handler MUST use this exact name or it lands in the default
 *          trap and locks up the CPU on the first USB event.
 */
OSAL_IRQ_HANDLER(Vector58) {
  OSAL_IRQ_PROLOGUE();

  uint8_t int_fg = R8_USB_INT_FG;

  if (int_fg & RB_UIF_TRANSFER) {
    uint8_t token  = R8_USB_INT_ST & MASK_UIS_TOKEN;
    uint8_t ep_num = R8_USB_INT_ST & MASK_UIS_ENDP;

    switch (token) {
    case UIS_TOKEN_SETUP:
      /* Copy SETUP packet from EP0 buffer into driver setup[8] array.
       * Reset ep0_tx_tog=1: first IN of each control transfer must be DATA1. */
      memcpy(USBD1.setup, ep0_buf, 8);
      ep0_tx_tog = 1;
      _usb_ep0setup(&USBD1, 0);
      break;
    case UIS_TOKEN_IN:
      if (ep_num == 0) {
        /* ChibiOS _usb_ep0in() must be called only when the ENTIRE EP0 IN
         * transfer is complete.  For multi-packet transfers (e.g. 18-byte
         * device descriptor over 8-byte EP0), advance txcnt and re-arm the
         * endpoint for the next chunk; only notify the framework when the last
         * byte has been acknowledged.
         *
         * We compute the bytes just ACKed from (txsize − txcnt) clamped to
         * the EP0 packet size rather than reading R8_UEP0_T_LEN.  This avoids
         * any ambiguity about whether the SIE clears or modifies that register
         * after the transaction completes. */
        const USBEndpointConfig *epc0 = USBD1.epc[0];
        if (epc0 != NULL && epc0->in_state != NULL) {
          USBInEndpointState *isp = epc0->in_state;
          size_t remaining = isp->txsize - isp->txcnt;
          if (remaining > USB_EP0_PACKET_SIZE)
            remaining = USB_EP0_PACKET_SIZE;
          isp->txcnt += remaining;
          if (isp->txcnt < isp->txsize) {
            /* More data remaining — usb_lld_start_in stages + arms next chunk. */
            usb_lld_start_in(&USBD1, 0);
            break; /* do NOT call _usb_ep0in yet */
          }
        }
        _usb_ep0in(&USBD1, 0);
      } else {
        _usb_isr_invoke_in_cb(&USBD1, ep_num);
      }
      break;
    case UIS_TOKEN_OUT:
      if (ep_num == 0) {
        _usb_ep0out(&USBD1, 0);
      } else {
        _usb_isr_invoke_out_cb(&USBD1, ep_num);
      }
      break;
    default:
      break;
    }
    R8_USB_INT_FG = RB_UIF_TRANSFER; /* W1C */
  }

  if (int_fg & RB_UIF_BUS_RST) {
    R8_USB_INT_FG = RB_UIF_BUS_RST; /* W1C before _usb_reset which re-enables */
    _usb_reset(&USBD1);
  }

  if (int_fg & RB_UIF_SUSPEND) {
    _usb_suspend(&USBD1);
    R8_USB_INT_FG = RB_UIF_SUSPEND; /* W1C */
  }

  OSAL_IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level USB driver global init.
 */
void usb_lld_init(void) { usbObjectInit(&USBD1); }

/**
 * @brief   Activates the USB peripheral, enabling D+ pull-up.
 */
void usb_lld_start(USBDriver *usbp) {
  if (usbp->state == USB_STOP) {
    /* Arm EP0 config now so SETUP packets are handled even if the host sends
     * one before we receive the first BUS_RST event.  usbStart() sets
     * epc[0]=NULL; usb_lld_reset() also restores it, but that fires only on
     * BUS_RST which may not arrive before the first SETUP on some hosts. */
    usbp->epc[0] = &ep0config;

    /* Reset SIE and clear all pending flags (reset value of R8_USB_CTRL is
     * already 0x06 = RESET_SIE|CLR_ALL, but be explicit on warm start). */
    R8_USB_CTRL = RB_UC_RESET_SIE | RB_UC_CLR_ALL;
    for (volatile int i = 0; i < 10; i++) { __NOP(); }
    R8_USB_CTRL = 0x00;

    /* Point SIE at endpoint buffers in normal SRAM.
     * R16_UEPn_DMA stores the lower 16 bits of the SRAM address; the DMA
     * engine prepends the SRAM base (0x20000000) internally.  Buffers must
     * be in 0x20000000–0x2000FFFF for the lower-16-bit truncation to work. */
    R16_UEP0_DMA = (uint16_t)(uint32_t)ep0_buf;
    R16_UEP1_DMA = (uint16_t)(uint32_t)ep1_in_buf;
    R16_UEP2_DMA = (uint16_t)(uint32_t)ep2_in_buf;

    /* Enable EP1 IN (keyboard reports) and EP2 IN (consumer reports).
     * R8_UEP4_1_MOD bit6 = RB_UEP1_TX_EN; R8_UEP2_3_MOD bit2 = RB_UEP2_TX_EN */
    R8_UEP4_1_MOD = RB_UEP1_TX_EN;
    R8_UEP2_3_MOD = RB_UEP2_TX_EN;

    /* Enable USB device mode + internal 1.5k D+ pull-up.
     * RB_UC_DEV_PU_EN (bit 5): device mode + internal D+ pull-up.
     * RB_UC_INT_BUSY:  SIE auto-NAKs all tokens while interrupt is pending.
     * RB_UC_DMA_EN:    Required for SIE to use R16_UEPn_DMA registers to
     *                  locate endpoint buffers in SRAM. Without this bit the
     *                  SIE ignores the DMA address registers entirely. */
    R8_USB_CTRL = RB_UC_DEV_PU_EN | RB_UC_INT_BUSY | RB_UC_DMA_EN;

    /* Enable USB analog pin I/O (PB10=UD-, PB11=UD+). */
    R16_PIN_ANALOG_IE |= RB_PIN_USB_IE;

    /* Enable physical port; disable internal D+/D- pull-downs. */
    R8_UDEV_CTRL = RB_UD_PD_DIS | RB_UD_PORT_EN;

    /* Enable transfer, bus-reset, and suspend interrupts */
    R8_USB_INT_EN = RB_UIF_TRANSFER | RB_UIF_BUS_RST | RB_UIF_SUSPEND;

    nvicEnableVector(USB_IRQn, CH579_USB_IRQ_PRIORITY);
  }
}

/**
 * @brief   Deactivates the USB peripheral.
 */
void usb_lld_stop(USBDriver *usbp) {
  if (usbp->state != USB_STOP) {
    nvicDisableVector(USB_IRQn);
    R8_UDEV_CTRL  = 0x00;
    R8_USB_CTRL   = 0x00;
    R8_USB_INT_EN = 0x00;
  }
}

/**
 * @brief   USB low-level reset — hardware only, called by ChibiOS _usb_reset().
 *
 * @details _usb_reset() (hal_usb.c) clears ChibiOS state and fires
 *          USB_EVENT_RESET, then calls usb_lld_reset() for the hardware
 *          portion.  This function must NOT call _usb_reset() — that would
 *          cause infinite recursion.
 */
void usb_lld_reset(USBDriver *usbp) {
  /* Restore EP0 config — _usb_reset() cleared epc[0]=NULL and QMK never
   * calls usbInitEndpointI for EP0, so we must re-arm it here. */
  usbp->epc[0] = &ep0config;

  R8_USB_DEV_AD = 0x00; /* address 0 */

  /* EP0: ACK OUT/SETUP, NAK IN.  Manage T_TOG manually. */
  ep0_tx_tog    = 1;    /* first IN of next control transfer must be DATA1 */
  R8_UEP0_T_LEN = 0;
  R8_UEP0_CTRL  = UEP_R_RES_ACK | UEP_T_RES_NAK;

  /* EP1/EP2: NAK IN, T_TOG=0.  AUTO_TOG enabled by usb_lld_init_endpoint(). */
  R8_UEP1_T_LEN = 0;
  R8_UEP1_CTRL  = UEP_T_RES_NAK;

  R8_UEP2_T_LEN = 0;
  R8_UEP2_CTRL  = UEP_T_RES_NAK;
}

/**
 * @brief   Sets the device USB address.
 */
void usb_lld_set_address(USBDriver *usbp) {
  R8_USB_DEV_AD = (uint8_t)usbp->address;
}

/**
 * @brief   Enables an endpoint.
 */
void usb_lld_init_endpoint(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  switch (ep) {
  case 0:
    ep0_tx_tog    = 1; /* first IN of next SETUP will be DATA1 */
    R8_UEP0_T_LEN = 0;
    R8_UEP0_CTRL  = UEP_R_RES_ACK | UEP_T_RES_NAK;
    break;
  case 1:
    /* AUTO_TOG (bit4): hardware flips T_TOG after each successful IN.
     * T_TOG starts at 0 → first report is DATA0, then DATA1, alternating. */
    R8_UEP1_T_LEN = 0;
    R8_UEP1_CTRL  = RB_UEP_AUTO_TOG | UEP_T_RES_NAK;
    R8_UEP4_1_MOD |= RB_UEP1_TX_EN;
    break;
  case 2:
    R8_UEP2_T_LEN = 0;
    R8_UEP2_CTRL  = RB_UEP_AUTO_TOG | UEP_T_RES_NAK;
    R8_UEP2_3_MOD |= RB_UEP2_TX_EN;
    break;
  default:
    break;
  }
}

/**
 * @brief   Disables all non-zero endpoints.
 */
void usb_lld_disable_endpoints(USBDriver *usbp) {
  (void)usbp;
  R8_UEP4_1_MOD &= ~RB_UEP1_TX_EN;
  R8_UEP2_3_MOD &= ~RB_UEP2_TX_EN;
  R8_UEP1_CTRL   = UEP_T_RES_NAK;
  R8_UEP2_CTRL   = UEP_T_RES_NAK;
}

/**
 * @brief   Returns the IN endpoint status.
 */
usbepstatus_t usb_lld_get_status_in(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  switch (ep) {
  case 1:
    return (R8_UEP1_CTRL & MASK_UEP_T_RES) == UEP_T_RES_STALL
               ? EP_STATUS_STALLED : EP_STATUS_ACTIVE;
  case 2:
    return (R8_UEP2_CTRL & MASK_UEP_T_RES) == UEP_T_RES_STALL
               ? EP_STATUS_STALLED : EP_STATUS_ACTIVE;
  default:
    return EP_STATUS_DISABLED;
  }
}

/**
 * @brief   Returns the OUT endpoint status.
 */
usbepstatus_t usb_lld_get_status_out(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  (void)ep;
  return EP_STATUS_DISABLED;
}

/**
 * @brief   Copies the received SETUP payload into buf.
 */
void usb_lld_read_setup(USBDriver *usbp, usbep_t ep, uint8_t *buf) {
  (void)ep;
  memcpy(buf, usbp->setup, 8);
}

/**
 * @brief   Prepares for a data receive on an OUT endpoint.
 */
void usb_lld_prepare_receive(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  if (ep == 0) {
    R8_UEP0_CTRL = (R8_UEP0_CTRL & ~MASK_UEP_R_RES) | UEP_R_RES_ACK;
  }
}

/**
 * @brief   Prepares an IN transfer (stages data into the endpoint buffer).
 */
void usb_lld_prepare_transmit(USBDriver *usbp, usbep_t ep) {
  USBInEndpointState *isp = usbp->epc[ep]->in_state;
  size_t n = isp->txsize - isp->txcnt;

  switch (ep) {
  case 0:
    if (n > USB_EP0_PACKET_SIZE) n = USB_EP0_PACKET_SIZE;
    if (n > 0) memcpy(ep0_buf, isp->txbuf + isp->txcnt, n);
    R8_UEP0_T_LEN = (uint8_t)n;
    break;
  case 1:
    if (n > 64) n = 64;
    memcpy(ep1_in_buf, isp->txbuf + isp->txcnt, n);
    R8_UEP1_T_LEN = (uint8_t)n;
    break;
  case 2:
    if (n > 32) n = 32;
    memcpy(ep2_in_buf, isp->txbuf + isp->txcnt, n);
    R8_UEP2_T_LEN = (uint8_t)n;
    break;
  default:
    break;
  }
}

/**
 * @brief   Starts an IN transfer: stages the next chunk then arms the endpoint.
 *
 * @details ChibiOS calls only usb_lld_start_in (never usb_lld_prepare_transmit)
 *          from usbStartTransmitI, so this function must both load the EP buffer
 *          and flip T_RES to ACK.
 *
 *          EP0: firmware manages T_TOG manually (bit6).  ep0_tx_tog tracks the
 *          next DATA PID.  Initialised to 1 (DATA1) at each SETUP so the first
 *          IN is always DATA1, then alternates each packet.
 *          EP1/2: AUTO_TOG (bit4) handles toggle automatically.
 */
void usb_lld_start_in(USBDriver *usbp, usbep_t ep) {
  /* Stage data into the EP buffer first. */
  usb_lld_prepare_transmit(usbp, ep);

  switch (ep) {
  case 0: {
    /* Set T_TOG from ep0_tx_tog, then pre-flip for next call. */
    uint8_t ctrl = R8_UEP0_CTRL & ~(MASK_UEP_T_RES | RB_UEP_T_TOG);
    ctrl |= UEP_T_RES_ACK;
    if (ep0_tx_tog) ctrl |= RB_UEP_T_TOG;
    ep0_tx_tog ^= 1u;
    R8_UEP0_CTRL = ctrl;
    break;
  }
  case 1:
    R8_UEP1_CTRL = (R8_UEP1_CTRL & ~MASK_UEP_T_RES) | UEP_T_RES_ACK;
    break;
  case 2:
    R8_UEP2_CTRL = (R8_UEP2_CTRL & ~MASK_UEP_T_RES) | UEP_T_RES_ACK;
    break;
  default:
    break;
  }
}

/**
 * @brief   Starts an OUT transfer (flip R_RES from NAK to ACK, set R_TOG for EP0).
 *
 * @details After every SETUP (DATA0), the next OUT token from the host uses
 *          DATA1 — either the STATUS OUT for D→H transfers, or the first data
 *          packet for H→D transfers.  Set RB_UEP_R_TOG (bit7) so the SIE
 *          accepts DATA1; if R_TOG doesn't match the host's PID, the SIE ACKs
 *          but RB_UIS_TOG_OK will be clear and firmware should discard the data.
 */
void usb_lld_start_out(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  if (ep == 0) {
    /* Clear both R_RES and T_RES fields plus R_TOG.
     * Setting T_RES=NAK here prevents a stale ACK from a previous IN
     * transaction triggering a spurious IN response during the OUT phase. */
    R8_UEP0_CTRL = (R8_UEP0_CTRL & ~(MASK_UEP_R_RES | MASK_UEP_T_RES | RB_UEP_R_TOG))
                   | UEP_R_RES_ACK | UEP_T_RES_NAK | RB_UEP_R_TOG;
  }
}

/**
 * @brief   Stalls an IN endpoint.
 */
void usb_lld_stall_in(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  switch (ep) {
  case 0:
    R8_UEP0_CTRL = (R8_UEP0_CTRL & ~MASK_UEP_T_RES) | UEP_T_RES_STALL;
    break;
  case 1:
    R8_UEP1_CTRL = (R8_UEP1_CTRL & ~MASK_UEP_T_RES) | UEP_T_RES_STALL;
    break;
  case 2:
    R8_UEP2_CTRL = (R8_UEP2_CTRL & ~MASK_UEP_T_RES) | UEP_T_RES_STALL;
    break;
  default:
    break;
  }
}

/**
 * @brief   Stalls an OUT endpoint.
 */
void usb_lld_stall_out(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  if (ep == 0) {
    R8_UEP0_CTRL = (R8_UEP0_CTRL & ~MASK_UEP_R_RES) | UEP_R_RES_STALL;
  }
}

/**
 * @brief   Clears an IN endpoint stall.
 *
 * @details On STALL clear, the data toggle must restart from DATA0 per USB spec.
 *          EP0: reset ep0_tx_tog; T_TOG cleared via full CTRL rewrite.
 *          EP1/2: force T_TOG=0 (bit6=0), keep AUTO_TOG (bit4=1).
 */
void usb_lld_clear_in(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  switch (ep) {
  case 0:
    ep0_tx_tog    = 1; /* next control transfer starts from DATA1 */
    R8_UEP0_CTRL  = UEP_R_RES_ACK | UEP_T_RES_NAK; /* T_TOG=0 */
    break;
  case 1:
    /* T_TOG=0 (bit6), AUTO_TOG on (bit4), T_RES=NAK */
    R8_UEP1_CTRL = RB_UEP_AUTO_TOG | UEP_T_RES_NAK;
    break;
  case 2:
    R8_UEP2_CTRL = RB_UEP_AUTO_TOG | UEP_T_RES_NAK;
    break;
  default:
    break;
  }
}

/**
 * @brief   Clears an OUT endpoint stall.
 */
void usb_lld_clear_out(USBDriver *usbp, usbep_t ep) {
  (void)usbp;
  if (ep == 0) {
    R8_UEP0_CTRL = (R8_UEP0_CTRL & ~MASK_UEP_R_RES) | UEP_R_RES_ACK;
  }
}

#endif /* HAL_USE_USB */

/** @} */
