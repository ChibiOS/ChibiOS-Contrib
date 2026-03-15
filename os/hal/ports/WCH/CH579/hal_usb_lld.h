/**
 * @file    hal_usb_lld.h
 * @brief   CH579M USB Full-Speed device low level driver header.
 *
 * @details The CH579M USB controller has:
 *   - EP0: 8-byte control endpoint (bMaxPacketSize0 = 8, confirmed from lsusb)
 *   - EP1: 64-byte IN (keyboard HID reports)
 *   - EP2: 4-byte IN  (consumer/media HID, for encoder keys)
 *   - Endpoint buffer RAM at 0x40008800 (512 bytes shared)
 *
 * @addtogroup USB
 * @{
 */

#ifndef HAL_USB_LLD_H
#define HAL_USB_LLD_H

#include "CH579.h"

#if HAL_USE_USB || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Maximum number of endpoints.
 * @details EP0 + EP1 + EP2 = 3 in practice; reserve 8 for the ChibiOS API.
 */
#define USB_MAX_ENDPOINTS 7

/**
 * @brief   EP0 packet size (hardware fixed at 8 bytes on CH579M).
 */
#define USB_EP0_PACKET_SIZE 8

/**
 * @brief   Address is applied AFTER the STATUS IN for SET_ADDRESS is ACKed.
 *
 * @details R8_USB_DEV_AD takes effect immediately when written.  Using EARLY
 *          mode would cause the SIE to change its address before sending the
 *          STATUS IN, so the host's IN token (to the old address) would be
 *          ignored → "Device not responding to setup address".  Use LATE mode
 *          so the address is updated via the ep0endcb callback only after the
 *          STATUS IN is successfully ACKed.
 */
#define USB_SET_ADDRESS_MODE USB_LATE_SET_ADDRESS

/**
 * @brief   Status stage handled entirely in software by usbStartTransmitI /
 *          usbStartReceiveI (USB_EP0_STATUS_STAGE_SW = 0 is the default when
 *          this macro is left undefined, but we make it explicit here).
 */
#define USB_EP0_STATUS_STAGE USB_EP0_STATUS_STAGE_SW

#define USB_SUPPORTS_HSIC FALSE

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   USB1 driver enable switch.
 */
#if !defined(CH579_USB_USE_USB1) || defined(__DOXYGEN__)
#define CH579_USB_USE_USB1 TRUE
#endif

/**
 * @brief   USB interrupt priority.
 */
#if !defined(CH579_USB_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define CH579_USB_IRQ_PRIORITY 5
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !CH579_USB_USE_USB1
#error "CH579M has only one USB peripheral"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of an IN endpoint state structure.
 */
typedef struct {
  /**
   * @brief   Pointer to the next buffer to be transmitted.
   */
  const uint8_t *txbuf;
  /**
   * @brief   Transmit transfer size.
   */
  size_t txsize;
  /**
   * @brief   Transmitted bytes so far.
   */
  size_t txcnt;
#if (USB_USE_WAIT == TRUE) || defined(__DOXYGEN__)
  /**
   * @brief   Waiting thread.
   */
  thread_reference_t thread;
#endif
  /* End of the mandatory fields.*/
} USBInEndpointState;

/**
 * @brief   Type of an OUT endpoint state structure.
 */
typedef struct {
  /**
   * @brief   Receive buffer pointer.
   */
  uint8_t *rxbuf;
  /**
   * @brief   Receive transfer size.
   */
  size_t rxsize;
  /**
   * @brief   Received bytes so far.
   */
  size_t rxcnt;
#if (USB_USE_WAIT == TRUE) || defined(__DOXYGEN__)
  /**
   * @brief   Waiting thread.
   */
  thread_reference_t thread;
#endif
  /* End of the mandatory fields.*/
} USBOutEndpointState;

/**
 * @brief   Type of an USB endpoint configuration structure.
 */
typedef struct {
  /**
   * @brief   Type and mode of the endpoint.
   */
  uint32_t ep_mode;
  /**
   * @brief   Setup packet callback (EP0 only).
   */
  usbepcallback_t setup_cb;
  /**
   * @brief   IN endpoint notification callback.
   */
  usbepcallback_t in_cb;
  /**
   * @brief   OUT endpoint notification callback.
   */
  usbepcallback_t out_cb;
  /**
   * @brief   IN endpoint maximum packet size.
   */
  uint16_t in_maxsize;
  /**
   * @brief   OUT endpoint maximum packet size.
   */
  uint16_t out_maxsize;
  /**
   * @brief   IN endpoint state.
   */
  USBInEndpointState *in_state;
  /**
   * @brief   OUT endpoint state.
   */
  USBOutEndpointState *out_state;
  /* End of the mandatory fields. */
  /**
   * @brief   EP buffer offset in endpoint RAM (relative to USB_BUF_BASE).
   */
  uint16_t ep_bufoffset;
} USBEndpointConfig;

/**
 * @brief   USB driver specific endpoint fields initializer.
 */
#define usb_lld_endpoint_fields 0

/**
 * @brief   Type of an USB driver configuration structure.
 */
typedef struct {
  /**
   * @brief   USB events callback. Receives USB_EVENT_* events.
   */
  usbeventcb_t event_cb;
  /**
   * @brief   Device GET_DESCRIPTOR request callback.
   */
  usbgetdescriptor_t get_descriptor_cb;
  /**
   * @brief   Requests hook callback.
   */
  usbreqhandler_t requests_hook_cb;
  /**
   * @brief   Start Of Frame callback.
   */
  usbcallback_t sof_cb;
} USBConfig;

/**
 * @brief   Structure representing an USB driver.
 */
struct USBDriver {
  /**
   * @brief   Driver state.
   */
  usbstate_t state;
  /**
   * @brief   Current configuration data.
   */
  const USBConfig *config;
  /**
   * @brief   Bit map of the transmitting IN endpoints.
   */
  uint16_t transmitting;
  /**
   * @brief   Bit map of the receiving OUT endpoints.
   */
  uint16_t receiving;
  /**
   * @brief   Pointer to the next address in the packet memory.
   */
  uint8_t *pmnext;
  /**
   * @brief   Endpoint 0 state.
   */
  usbep0state_t ep0state;
  /**
   * @brief   Next position in the buffer for endpoint 0.
   */
  uint8_t *ep0next;
  /**
   * @brief   Number of bytes yet to be transferred on endpoint 0.
   */
  size_t ep0n;
  /**
   * @brief   Endpoint 0 end callback.
   */
  usbcallback_t ep0endcb;
  /**
   * @brief   Next position in the buffer of the next packets.
   */
  uint8_t setup[8];
  /**
   * @brief   Current USB device status.
   */
  uint16_t status;
  /**
   * @brief   Assigned USB address.
   */
  uint8_t address;
  /**
   * @brief   Current USB device configuration.
   */
  uint8_t configuration;
  /**
   * @brief   State of the driver when a suspend happened.
   */
  usbstate_t saved_state;
  /**
   * @brief   Active IN endpoint descriptors.
   */
  const USBEndpointConfig *epc[USB_MAX_ENDPOINTS + 1];
  /**
   * @brief   Fields available to user, not used by the driver.
   */
  void *in_params[USB_MAX_ENDPOINTS];
  void *out_params[USB_MAX_ENDPOINTS];
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the current frame number.
 */
#define usb_lld_get_frame_number(usbp) (0)

/**
 * @brief   Returns the exact size of a receive transaction.
 */
#define usb_lld_get_transaction_size(usbp, ep)                                 \
  ((usbp)->epc[ep]->out_state->rxcnt)

/**
 * @brief   Connects the USB device.
 */
#ifndef usb_lld_connect_bus
#define usb_lld_connect_bus(usbp)
#endif

/**
 * @brief   Disconnect the USB device.
 */
#ifndef usb_lld_disconnect_bus
#define usb_lld_disconnect_bus(usbp)
#endif

/**
 * @brief   Wake up the host.
 */
#ifndef usb_lld_wakeup_host
#define usb_lld_wakeup_host(usbp)                                              \
  do {                                                                         \
  } while (false)
#endif

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if CH579_USB_USE_USB1 && !defined(__DOXYGEN__)
extern USBDriver USBD1;
#endif

#ifdef __cplusplus
extern "C" {
#endif
void usb_lld_init(void);
void usb_lld_start(USBDriver *usbp);
void usb_lld_stop(USBDriver *usbp);
void usb_lld_reset(USBDriver *usbp);
void usb_lld_set_address(USBDriver *usbp);
void usb_lld_init_endpoint(USBDriver *usbp, usbep_t ep);
void usb_lld_disable_endpoints(USBDriver *usbp);
usbepstatus_t usb_lld_get_status_in(USBDriver *usbp, usbep_t ep);
usbepstatus_t usb_lld_get_status_out(USBDriver *usbp, usbep_t ep);
void usb_lld_read_setup(USBDriver *usbp, usbep_t ep, uint8_t *buf);
void usb_lld_prepare_receive(USBDriver *usbp, usbep_t ep);
void usb_lld_prepare_transmit(USBDriver *usbp, usbep_t ep);
void usb_lld_start_in(USBDriver *usbp, usbep_t ep);
void usb_lld_start_out(USBDriver *usbp, usbep_t ep);
void usb_lld_stall_in(USBDriver *usbp, usbep_t ep);
void usb_lld_stall_out(USBDriver *usbp, usbep_t ep);
void usb_lld_clear_in(USBDriver *usbp, usbep_t ep);
void usb_lld_clear_out(USBDriver *usbp, usbep_t ep);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_USB */

#endif /* HAL_USB_LLD_H */

/** @} */
