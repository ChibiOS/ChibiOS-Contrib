/*
    Copyright (C) 2020 Alex Lewontin
    Copyright (C) 2021 Ein Terakawa
    Modifications copyright (C) 2026 Belonit

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
 * @file    M251/hal_usb_lld.c
 * @brief   M252 USB subsystem low level driver source.
 *
 * @addtogroup USB
 * @{
 */

#include "hal.h"

#if (HAL_USE_USB == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define M252_USBD_HW_ENDPOINTS            M251_USBD_ENDPOINTS
#define M252_USBD_SETUP_BLOCK_OFFSET      0U
#define M252_USBD_FIRST_BLOCK_OFFSET      1U

#define M252_USBD_CFG_OUT                 (1UL << USBD_CFG_STATE_Pos)
#define M252_USBD_CFG_IN                  (2UL << USBD_CFG_STATE_Pos)

#define M252_USBD_SRAM_BASE               ((volatile uint8_t *)(USBD_BASE + 0x100U))
#define M252_USBD_SRAM_BLOCKS             64U

#define M252_USBD_INT_ALL                 (USBD_INTSTS_BUSIF_Msk |         \
                                           USBD_INTSTS_USBIF_Msk |         \
                                           USBD_INTSTS_VBDETIF_Msk |       \
                                           USBD_INTSTS_NEVWKIF_Msk |       \
                                           USBD_INTSTS_SOFIF_Msk |         \
                                           USBD_INTSTS_SETUP_Msk)
#define M252_USBD_EP_INT_MASK             (((1UL << M252_USBD_HW_ENDPOINTS) - 1UL) << \
                                           USBD_INTSTS_EPEVT0_Pos)

#define HW_OUT_EPN(lepn)                  (2U * (lepn))
#define HW_IN_EPN(lepn)                   ((2U * (lepn)) + 1U)
#define LOGICAL_EPN(hwepn)                ((hwepn) / 2U)
#define HW_EP(hwepn)                      (&USBD->EP[hwepn])
#define HW_OUT_EP(lepn)                   HW_EP(HW_OUT_EPN(lepn))
#define HW_IN_EP(lepn)                    HW_EP(HW_IN_EPN(lepn))

#define BYTES_TO_NEXT_SRAM_BLOCK(bytes)   (((bytes) + 7U) >> 3U)

#if M251_USB_USE_HIRC_TRIM == TRUE
/* Factory HIRC trim value used by the Nuvoton crystal-less USB examples.*/
#define M252_HIRC_TRIM_INIT               \
  (*(volatile uint32_t *)(SYS_BASE + 0x118UL))
#define M252_HIRC_TRIM_ERROR_MASK         \
  (SYS_HIRCTRIMSTS_CLKERIF_Msk | SYS_HIRCTRIMSTS_TFAILIF_Msk)
#define M252_HIRC_TRIM_CONTROL            \
  (SYS_HIRCTRIMCTL_REFCKSEL_Msk | SYS_HIRCTRIMCTL_BOUNDEN_Msk | \
   (1UL << SYS_HIRCTRIMCTL_FREQSEL_Pos) | \
   ((uint32_t)M251_USB_HIRC_TRIM_BOUNDARY << \
    SYS_HIRCTRIMCTL_BOUNDARY_Pos))
#endif

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   USBD1 driver identifier.
 */
#if M251_USB_USE_USBD1 || defined(__DOXYGEN__)
USBDriver USBD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

static union {
  USBInEndpointState in;
  USBOutEndpointState out;
} ep0_state;

static uint8_t ep0setup_buffer[8];

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

static uint32_t sram_free_block_offset = M252_USBD_FIRST_BLOCK_OFFSET;

#if M251_USB_USE_HIRC_TRIM == TRUE
static uint32_t hirc_trim_initial;
#endif

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline size_t m252_min(size_t x, size_t y) {

  return x < y ? x : y;
}

static bool usb_lld_valid_out_ep(USBDriver *usbp, usbep_t ep) {

  return (ep <= USB_MAX_ENDPOINTS) &&
         (usbp->epc[ep] != NULL) &&
         (usbp->epc[ep]->out_state != NULL);
}

static bool usb_lld_valid_in_ep(USBDriver *usbp, usbep_t ep) {

  return (ep <= USB_MAX_ENDPOINTS) &&
         (usbp->epc[ep] != NULL) &&
         (usbp->epc[ep]->in_state != NULL);
}

static void usb_sram_copy_to(volatile uint8_t *dst,
                             const uint8_t *src,
                             size_t n) {

  while (n-- > 0U) {
    *dst++ = *src++;
  }
}

static void usb_sram_copy_from(uint8_t *dst,
                               const volatile uint8_t *src,
                               size_t n) {

  while (n-- > 0U) {
    *dst++ = *src++;
  }
}

static uint32_t usb_sram_alloc(size_t size) {
  uint32_t offset = sram_free_block_offset;
  uint32_t blocks;

  osalDbgAssert((size > 0U) && (size <= 64U),
                "invalid USB endpoint allocation");

  blocks = BYTES_TO_NEXT_SRAM_BLOCK((uint32_t)size);
  osalDbgAssert((sram_free_block_offset <= M252_USBD_SRAM_BLOCKS) &&
                (blocks <= (M252_USBD_SRAM_BLOCKS -
                            sram_free_block_offset)),
                "USB SRAM overflow");
  sram_free_block_offset += blocks;

  return offset << USBD_BUFSEG_BUFSEG_Pos;
}

#if M251_USB_USE_HIRC_TRIM == TRUE
static void usbd_hirc_trim_recover(void) {

  m251_lld_unlock();
  M252_HIRC_TRIM_INIT = hirc_trim_initial;
  SYS->HIRCTRIMCTL = 0U;
  SYS->HIRCTRIMSTS = M252_HIRC_TRIM_ERROR_MASK;
  m251_lld_lock();
}

static void usbd_hirc_trim_serve_sof(void) {

  if ((SYS->HIRCTRIMSTS & M252_HIRC_TRIM_ERROR_MASK) != 0U) {
    usbd_hirc_trim_recover();
    return;
  }

  if ((SYS->HIRCTRIMCTL & SYS_HIRCTRIMCTL_FREQSEL_Msk) !=
      (1UL << SYS_HIRCTRIMCTL_FREQSEL_Pos)) {
    m251_lld_unlock();
    SYS->HIRCTRIMCTL = M252_HIRC_TRIM_CONTROL;
    m251_lld_lock();
  }
}

static void usbd_hirc_trim_start(void) {

  hirc_trim_initial = M252_HIRC_TRIM_INIT;

  m251_lld_unlock();
  SYS->HIRCTRIMCTL = 0U;
  SYS->HIRCTRIMSTS = M252_HIRC_TRIM_ERROR_MASK;
  SYS->HIRCTRIMIEN |= SYS_HIRCTRIMIEN_CLKEIEN_Msk |
                     SYS_HIRCTRIMIEN_TFALIEN_Msk;
  m251_lld_lock();

  nvicClearPending(M251_IRCTRIM_NUMBER);
  nvicEnableVector(M251_IRCTRIM_NUMBER, M251_USB_IRQ_PRIORITY);
}

static void usbd_hirc_trim_stop(void) {

  nvicDisableVector(M251_IRCTRIM_NUMBER);
  nvicClearPending(M251_IRCTRIM_NUMBER);

  m251_lld_unlock();
  SYS->HIRCTRIMIEN &= ~(SYS_HIRCTRIMIEN_CLKEIEN_Msk |
                        SYS_HIRCTRIMIEN_TFALIEN_Msk);
  SYS->HIRCTRIMCTL = 0U;
  SYS->HIRCTRIMSTS = M252_HIRC_TRIM_ERROR_MASK;
  m251_lld_lock();
}
#endif

static void usbd_clock_enable(void) {

  SystemUnlockReg();

  CLK->CLKSEL0 = (CLK->CLKSEL0 & ~CLK_CLKSEL0_USBDSEL_Msk) |
                 M251_USB_SRC;
  CLK->CLKDIV0 = (CLK->CLKDIV0 & ~CLK_CLKDIV0_USBDIV_Msk) |
                 M251_CLKDIV0_USB(M251_USB_DIV);
  CLK->APBCLK0 |= CLK_APBCLK0_USBDCKEN_Msk;

  SYS->IPRST1 |= SYS_IPRST1_USBDRST_Msk;
  SYS->IPRST1 &= ~SYS_IPRST1_USBDRST_Msk;

  SystemLockReg();
}

static void usbd_clock_disable(void) {

  SystemUnlockReg();
  CLK->APBCLK0 &= ~CLK_APBCLK0_USBDCKEN_Msk;
  SystemLockReg();
}

static void usb_serve_out_endpoint(uint32_t epn) {
  USBDriver *const usbp = &USBD1;
  USBOutEndpointState *osp = usbp->epc[epn]->out_state;
  size_t rxsize_actual;

  rxsize_actual = m252_min((size_t)(HW_OUT_EP(epn)->MXPLD & USBD_MXPLD_MXPLD_Msk),
                           osp->rxsize - osp->rxcnt);

  if (rxsize_actual > 0U) {
    usb_sram_copy_from(osp->rxbuf + osp->rxcnt,
                       M252_USBD_SRAM_BASE + HW_OUT_EP(epn)->BUFSEG,
                       rxsize_actual);
    osp->rxcnt += rxsize_actual;
  }

  if ((rxsize_actual < usbp->epc[epn]->out_maxsize) ||
      (osp->rxcnt >= osp->rxsize)) {
    _usb_isr_invoke_out_cb(usbp, epn);
  }
  else {
    HW_OUT_EP(epn)->MXPLD = m252_min(usbp->epc[epn]->out_maxsize,
                                     osp->rxsize - osp->rxcnt);
  }
}

static void usb_serve_in_endpoint(uint32_t epn) {
  USBDriver *const usbp = &USBD1;
  USBInEndpointState *isp = usbp->epc[epn]->in_state;
  size_t txsize;

  isp->txcnt += HW_IN_EP(epn)->MXPLD & USBD_MXPLD_MXPLD_Msk;

  if (isp->txcnt >= isp->txsize) {
    _usb_isr_invoke_in_cb(usbp, epn);
  }
  else {
    txsize = m252_min(usbp->epc[epn]->in_maxsize,
                      isp->txsize - isp->txcnt);
    usb_sram_copy_to(M252_USBD_SRAM_BASE + HW_IN_EP(epn)->BUFSEG,
                     isp->txbuf + isp->txcnt,
                     txsize);
    HW_IN_EP(epn)->MXPLD = txsize;
  }
}

static void usb_serve_endpoint(uint32_t hwepn) {
  uint32_t epn = LOGICAL_EPN(hwepn);

  if ((epn > USB_MAX_ENDPOINTS) || (USBD1.epc[epn] == NULL)) {
    return;
  }

  if ((hwepn & 1U) == 0U) {
    if (USBD1.epc[epn]->out_state != NULL) {
      usb_serve_out_endpoint(epn);
    }
  }
  else {
    if (USBD1.epc[epn]->in_state != NULL) {
      usb_serve_in_endpoint(epn);
    }
  }
}

static void usb_lld_serve_interrupt(USBDriver *usbp) {
  uint32_t intsts = USBD->INTSTS;
  uint32_t bussts = USBD->ATTR;

  if ((intsts & USBD_INTSTS_VBDETIF_Msk) != 0U) {
    USBD->INTSTS = USBD_INTSTS_VBDETIF_Msk;

    if ((USBD->VBUSDET & USBD_VBUSDET_VBUSDET_Msk) != 0U) {
      USBD->ATTR |= USBD_ATTR_PWRDN_Msk | USBD_ATTR_PHYEN_Msk |
                    USBD_ATTR_USBEN_Msk | USBD_ATTR_BYTEM_Msk;
    }
    else {
      USBD->ATTR &= ~USBD_ATTR_USBEN_Msk;
    }
  }

  if ((intsts & USBD_INTSTS_NEVWKIF_Msk) != 0U) {
    USBD->INTSTS = USBD_INTSTS_NEVWKIF_Msk;
    _usb_wakeup(usbp);
  }

  if ((intsts & USBD_INTSTS_SOFIF_Msk) != 0U) {
    USBD->INTSTS = USBD_INTSTS_SOFIF_Msk;
#if M251_USB_USE_HIRC_TRIM == TRUE
    usbd_hirc_trim_serve_sof();
#endif
    _usb_isr_invoke_sof_cb(usbp);
  }

  if ((intsts & USBD_INTSTS_BUSIF_Msk) != 0U) {
    USBD->INTSTS = USBD_INTSTS_BUSIF_Msk;

    if ((bussts & USBD_ATTR_USBRST_Msk) != 0U) {
      USBD->ATTR |= USBD_ATTR_PWRDN_Msk | USBD_ATTR_PHYEN_Msk |
                    USBD_ATTR_USBEN_Msk;
      _usb_reset(usbp);
    }
    if ((bussts & USBD_ATTR_SUSPEND_Msk) != 0U) {
      USBD->ATTR &= ~USBD_ATTR_PHYEN_Msk;
      _usb_suspend(usbp);
    }
    if ((bussts & USBD_ATTR_RESUME_Msk) != 0U) {
      USBD->ATTR |= USBD_ATTR_PWRDN_Msk | USBD_ATTR_PHYEN_Msk |
                    USBD_ATTR_USBEN_Msk;
      _usb_wakeup(usbp);
    }
  }

  if ((intsts & USBD_INTSTS_USBIF_Msk) != 0U) {
    uint32_t epmask = intsts & M252_USBD_EP_INT_MASK;

    if ((intsts & USBD_INTSTS_SETUP_Msk) != 0U) {
      USBD->INTSTS = USBD_INTSTS_SETUP_Msk;
      HW_IN_EP(0)->CFGP |= USBD_CFGP_CLRRDY_Msk;
      HW_OUT_EP(0)->CFGP |= USBD_CFGP_CLRRDY_Msk;
      HW_IN_EP(0)->CFG |= USBD_CFG_DSQSYNC_Msk;
      _usb_isr_invoke_setup_cb(usbp, 0);
    }

    for (uint32_t hwepn = 0U; hwepn < M252_USBD_HW_ENDPOINTS; hwepn++) {
      uint32_t bit = 1UL << (USBD_INTSTS_EPEVT0_Pos + hwepn);

      if ((epmask & bit) != 0U) {
        USBD->INTSTS = bit;
        usb_serve_endpoint(hwepn);
      }
    }

  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if M251_USB_USE_USBD1 || defined(__DOXYGEN__)
/**
 * @brief   USB device interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_USBD_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  usb_lld_serve_interrupt(&USBD1);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if (M251_USB_USE_HIRC_TRIM == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   HIRC trim interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_IRCTRIM_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  if ((SYS->HIRCTRIMSTS & M252_HIRC_TRIM_ERROR_MASK) != 0U) {
    usbd_hirc_trim_recover();
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
void usb_lld_init(void) {

#if M251_USB_USE_USBD1
  usbObjectInit(&USBD1);
#endif
}

/**
 * @brief   Configures and activates the USB peripheral.
 *
 * @param[in] usbp      pointer to a @p USBDriver object
 *
 * @notapi
 */
void usb_lld_start(USBDriver *usbp) {
  if (usbp->state == USB_STOP) {
    usbd_clock_enable();
#if M251_USB_USE_HIRC_TRIM == TRUE
    usbd_hirc_trim_start();
#endif
  }

  USBD->ATTR = USBD_ATTR_PWRDN_Msk | USBD_ATTR_PHYEN_Msk |
               USBD_ATTR_USBEN_Msk | USBD_ATTR_BYTEM_Msk;
  USBD->STBUFSEG = M252_USBD_SETUP_BLOCK_OFFSET <<
                   USBD_STBUFSEG_STBUFSEG_Pos;
  USBD->SE0 = USBD_SE0_SE0_Msk;
  USBD->INTSTS = M252_USBD_INT_ALL | M252_USBD_EP_INT_MASK;
  USBD->INTEN = USBD_INTEN_BUSIEN_Msk | USBD_INTEN_USBIEN_Msk |
                USBD_INTEN_VBDETIEN_Msk | USBD_INTEN_NEVWKIEN_Msk |
                USBD_INTEN_WKEN_Msk;

#if M251_USB_USE_HIRC_TRIM == TRUE
  USBD->INTEN |= USBD_INTEN_SOFIEN_Msk;
#else
  if ((usbp->config != NULL) && (usbp->config->sof_cb != NULL)) {
    USBD->INTEN |= USBD_INTEN_SOFIEN_Msk;
  }
#endif

  nvicEnableVector(M251_USBD_NUMBER, M251_USB_IRQ_PRIORITY);

  usb_lld_reset(usbp);
}

/**
 * @brief   Deactivates the USB peripheral.
 *
 * @param[in] usbp      pointer to a @p USBDriver object
 *
 * @notapi
 */
void usb_lld_stop(USBDriver *usbp) {

  if (usbp->state != USB_STOP) {
    usbDisconnectBus(usbp);
    USBD->INTEN = 0U;
    USBD->ATTR = 0U;
    nvicDisableVector(M251_USBD_NUMBER);
#if M251_USB_USE_HIRC_TRIM == TRUE
    usbd_hirc_trim_stop();
#endif
    usbd_clock_disable();
  }
}

/**
 * @brief   Resets the USB peripheral.
 *
 * @param[in] usbp      pointer to a @p USBDriver object
 *
 * @notapi
 */
void usb_lld_reset(USBDriver *usbp) {

  for (uint32_t hwepn = 0U; hwepn < M252_USBD_HW_ENDPOINTS; hwepn++) {
    USBD->EP[hwepn].CFGP = USBD_CFGP_CLRRDY_Msk;
    USBD->EP[hwepn].CFG = 0U;
  }

  sram_free_block_offset = M252_USBD_FIRST_BLOCK_OFFSET;
  USBD->FADDR = 0U;
  usbp->epc[0] = &ep0config;
  usb_lld_init_endpoint(usbp, 0);
}

/**
 * @brief   Sets the USB address.
 *
 * @param[in] usbp      pointer to a @p USBDriver object
 *
 * @notapi
 */
void usb_lld_set_address(USBDriver *usbp) {

  USBD->FADDR = usbp->address & USBD_FADDR_FADDR_Msk;
}

/**
 * @brief   Enables an endpoint.
 *
 * @param[in] usbp      pointer to a @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_init_endpoint(USBDriver *usbp, usbep_t ep) {

  osalDbgAssert((ep <= USB_MAX_ENDPOINTS) && (usbp->epc[ep] != NULL),
                "invalid USB endpoint");
  osalDbgAssert(usbp->epc[ep]->ep_mode != USB_EP_MODE_TYPE_ISOC,
                "isochronous USB endpoint unsupported");

  if (usbp->epc[ep]->out_state != NULL) {
    uint32_t cfg = ((uint32_t)ep << USBD_CFG_EPNUM_Pos) & USBD_CFG_EPNUM_Msk;

    cfg |= M252_USBD_CFG_OUT;
    if (usbp->epc[ep]->ep_mode == USB_EP_MODE_TYPE_CTRL) {
      cfg |= USBD_CFG_CSTALL_Msk;
    }
    osalDbgAssert((HW_OUT_EP(ep)->CFG & USBD_CFG_STATE_Msk) == 0U,
                  "USB endpoint already allocated");
    HW_OUT_EP(ep)->CFGP = USBD_CFGP_CLRRDY_Msk;
    HW_OUT_EP(ep)->CFG = cfg;
    HW_OUT_EP(ep)->BUFSEG = usb_sram_alloc(usbp->epc[ep]->out_maxsize);
  }
  else {
    HW_OUT_EP(ep)->CFG = 0U;
  }

  if (usbp->epc[ep]->in_state != NULL) {
    uint32_t cfg = ((uint32_t)ep << USBD_CFG_EPNUM_Pos) & USBD_CFG_EPNUM_Msk;

    cfg |= M252_USBD_CFG_IN;
    if (usbp->epc[ep]->ep_mode == USB_EP_MODE_TYPE_CTRL) {
      cfg |= USBD_CFG_CSTALL_Msk;
    }
    osalDbgAssert((HW_IN_EP(ep)->CFG & USBD_CFG_STATE_Msk) == 0U,
                  "USB endpoint already allocated");
    HW_IN_EP(ep)->CFGP = USBD_CFGP_CLRRDY_Msk;
    HW_IN_EP(ep)->CFG = cfg;
    HW_IN_EP(ep)->BUFSEG = usb_sram_alloc(usbp->epc[ep]->in_maxsize);
  }
  else {
    HW_IN_EP(ep)->CFG = 0U;
  }
}

/**
 * @brief   Disables all active endpoints except endpoint zero.
 *
 * @param[in] usbp      pointer to a @p USBDriver object
 *
 * @notapi
 */
void usb_lld_disable_endpoints(USBDriver *usbp) {

  USBD->INTSTS = M252_USBD_EP_INT_MASK &
                 ~((1UL << (USBD_INTSTS_EPEVT0_Pos + HW_OUT_EPN(0))) |
                   (1UL << (USBD_INTSTS_EPEVT0_Pos + HW_IN_EPN(0))));

  for (uint32_t hwepn = 0U; hwepn < M252_USBD_HW_ENDPOINTS; hwepn++) {
    if (LOGICAL_EPN(hwepn) != 0U) {
      USBD->EP[hwepn].CFGP = USBD_CFGP_CLRRDY_Msk;
      USBD->EP[hwepn].CFG = 0U;
    }
  }

  sram_free_block_offset = M252_USBD_FIRST_BLOCK_OFFSET +
                           BYTES_TO_NEXT_SRAM_BLOCK(usbp->epc[0]->in_maxsize) +
                           BYTES_TO_NEXT_SRAM_BLOCK(usbp->epc[0]->out_maxsize);
}

/**
 * @brief   Returns the status of an OUT endpoint.
 *
 * @param[in] usbp      pointer to a @p USBDriver object
 * @param[in] ep        endpoint number
 * @return              The endpoint status.
 * @retval EP_STATUS_DISABLED The endpoint is not active.
 * @retval EP_STATUS_STALLED  The endpoint is stalled.
 * @retval EP_STATUS_ACTIVE   The endpoint is active.
 *
 * @notapi
 */
usbepstatus_t usb_lld_get_status_out(USBDriver *usbp, usbep_t ep) {

  if (!usb_lld_valid_out_ep(usbp, ep)) {
    return EP_STATUS_DISABLED;
  }

  if ((HW_OUT_EP(ep)->CFG & USBD_CFG_STATE_Msk) == 0U) {
    return EP_STATUS_DISABLED;
  }

  if ((HW_OUT_EP(ep)->CFGP & USBD_CFGP_SSTALL_Msk) != 0U) {
    return EP_STATUS_STALLED;
  }

  return EP_STATUS_ACTIVE;
}

/**
 * @brief   Returns the status of an IN endpoint.
 *
 * @param[in] usbp      pointer to a @p USBDriver object
 * @param[in] ep        endpoint number
 * @return              The endpoint status.
 * @retval EP_STATUS_DISABLED The endpoint is not active.
 * @retval EP_STATUS_STALLED  The endpoint is stalled.
 * @retval EP_STATUS_ACTIVE   The endpoint is active.
 *
 * @notapi
 */
usbepstatus_t usb_lld_get_status_in(USBDriver *usbp, usbep_t ep) {

  if (!usb_lld_valid_in_ep(usbp, ep)) {
    return EP_STATUS_DISABLED;
  }

  if ((HW_IN_EP(ep)->CFG & USBD_CFG_STATE_Msk) == 0U) {
    return EP_STATUS_DISABLED;
  }

  if ((HW_IN_EP(ep)->CFGP & USBD_CFGP_SSTALL_Msk) != 0U) {
    return EP_STATUS_STALLED;
  }

  return EP_STATUS_ACTIVE;
}

/**
 * @brief   Reads a setup packet from the dedicated packet buffer.
 *
 * @param[in] usbp      pointer to a @p USBDriver object
 * @param[in] ep        endpoint number
 * @param[out] buf      destination buffer
 *
 * @notapi
 */
void usb_lld_read_setup(USBDriver *usbp, usbep_t ep, uint8_t *buf) {

  (void)usbp;
  (void)ep;

  usb_sram_copy_from(buf, M252_USBD_SRAM_BASE, 8U);
}

/**
 * @brief   Starts a receive operation on an OUT endpoint.
 *
 * @param[in] usbp      pointer to a @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_start_out(USBDriver *usbp, usbep_t ep) {
  USBOutEndpointState *osp = usbp->epc[ep]->out_state;

  HW_OUT_EP(ep)->MXPLD = m252_min(osp->rxsize, usbp->epc[ep]->out_maxsize);
}

/**
 * @brief   Starts a transmit operation on an IN endpoint.
 *
 * @param[in] usbp      pointer to a @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_start_in(USBDriver *usbp, usbep_t ep) {
  USBInEndpointState *isp = usbp->epc[ep]->in_state;
  size_t txsize = m252_min(isp->txsize, usbp->epc[ep]->in_maxsize);

  if (txsize > 0U) {
    usb_sram_copy_to(M252_USBD_SRAM_BASE + HW_IN_EP(ep)->BUFSEG,
                     isp->txbuf,
                     txsize);
  }
  HW_IN_EP(ep)->MXPLD = txsize;
}

/**
 * @brief   Brings an OUT endpoint into the stalled state.
 *
 * @param[in] usbp      pointer to a @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_stall_out(USBDriver *usbp, usbep_t ep) {

  if (!usb_lld_valid_out_ep(usbp, ep)) {
    return;
  }

  HW_OUT_EP(ep)->CFGP |= USBD_CFGP_SSTALL_Msk | USBD_CFGP_CLRRDY_Msk;
}

/**
 * @brief   Brings an IN endpoint into the stalled state.
 *
 * @param[in] usbp      pointer to a @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_stall_in(USBDriver *usbp, usbep_t ep) {

  if (!usb_lld_valid_in_ep(usbp, ep)) {
    return;
  }

  HW_IN_EP(ep)->CFGP |= USBD_CFGP_SSTALL_Msk | USBD_CFGP_CLRRDY_Msk;
}

/**
 * @brief   Brings an OUT endpoint into the active state.
 *
 * @param[in] usbp      pointer to a @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_clear_out(USBDriver *usbp, usbep_t ep) {

  if (!usb_lld_valid_out_ep(usbp, ep)) {
    return;
  }

  HW_OUT_EP(ep)->CFGP &= ~USBD_CFGP_SSTALL_Msk;
  HW_OUT_EP(ep)->CFG &= ~USBD_CFG_DSQSYNC_Msk;
}

/**
 * @brief   Brings an IN endpoint into the active state.
 *
 * @param[in] usbp      pointer to a @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_clear_in(USBDriver *usbp, usbep_t ep) {

  if (!usb_lld_valid_in_ep(usbp, ep)) {
    return;
  }

  HW_IN_EP(ep)->CFGP &= ~USBD_CFGP_SSTALL_Msk;
  HW_IN_EP(ep)->CFG &= ~USBD_CFG_DSQSYNC_Msk;
}

#endif /* HAL_USE_USB == TRUE */

/** @} */
