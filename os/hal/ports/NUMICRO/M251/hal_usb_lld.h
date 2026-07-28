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
 * @file    M251/hal_usb_lld.h
 * @brief   M252 USB subsystem low level driver header.
 *
 * @addtogroup USB
 * @{
 */

#ifndef HAL_USB_LLD_H
#define HAL_USB_LLD_H

#if (HAL_USE_USB == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Maximum logical endpoint address, excluding endpoint zero.
 * @note    USB device is a M252-only feature, not a plain M251 feature.
 *          M252SD2AE exposes 12 hardware endpoint slots. The initial driver
 *          maps them as OUT/IN pairs, giving EP0 plus logical EP1..EP5.
 */
#define USB_MAX_ENDPOINTS                  ((M251_USBD_ENDPOINTS / 2U) - 1U)

/**
 * @brief   Status stage handling method.
 */
#define USB_EP0_STATUS_STAGE               USB_EP0_STATUS_STAGE_SW

/**
 * @brief   The address can be changed immediately upon packet reception.
 */
#define USB_SET_ADDRESS_MODE               USB_LATE_SET_ADDRESS

/**
 * @brief   Method for set address acknowledge.
 */
#define USB_SET_ADDRESS_ACK_HANDLING       USB_SET_ADDRESS_ACK_SW

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    M251 USB configuration options
 * @{
 */

/**
 * @brief   USB driver enable switch.
 * @details If set to @p TRUE the support for USBD1 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(M251_USB_USE_USBD1) || defined(__DOXYGEN__)
#define M251_USB_USE_USBD1                 TRUE
#endif

/**
 * @brief   USB interrupt priority level setting.
 * @note    The default is 3.
 */
#if !defined(M251_USB_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define M251_USB_IRQ_PRIORITY              3
#endif

/**
 * @brief   Enables HIRC auto-trim from USB SOF.
 * @details The default is @p TRUE when HIRC is selected as the USB clock
 *          source, otherwise it is @p FALSE.
 */
#if !defined(M251_USB_USE_HIRC_TRIM) || defined(__DOXYGEN__)
#if M251_USB_SRC == M251_USBSRC_HIRC
#define M251_USB_USE_HIRC_TRIM              TRUE
#else
#define M251_USB_USE_HIRC_TRIM              FALSE
#endif
#endif

/**
 * @brief   Maximum HIRC trim adjustment from the factory value.
 * @note    The default is 10.
 */
#if !defined(M251_USB_HIRC_TRIM_BOUNDARY) || defined(__DOXYGEN__)
#define M251_USB_HIRC_TRIM_BOUNDARY         10U
#endif
/** @}*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !M251_DEVICE_IS_M252
#error "USB requested for a non-M252 device; plain M251 parts have no USBD"
#endif

#if !M251_HAS_USBD
#error "USB requested on a selected M252 device without USBD capability"
#endif

#if M251_USBD_ENDPOINTS != 12U
#error "Initial M252 USBD driver expects 12 hardware endpoint slots"
#endif

#if (M251_USBD_ENDPOINTS & 1U) != 0U
#error "Initial M252 USBD driver requires paired OUT/IN endpoint slots"
#endif

#if !M251_USB_USE_USBD1
#error "USB subsystem enabled, but no USBD driver configured"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(M251_USB_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to USBD"
#endif

#if (M251_USB_USE_HIRC_TRIM == TRUE) && \
    (M251_USB_SRC != M251_USBSRC_HIRC)
#error "USB HIRC auto-trim requires HIRC as the USBD clock source"
#endif

#if (M251_USB_USE_HIRC_TRIM == TRUE) && \
    ((M251_USB_HIRC_TRIM_BOUNDARY < 1U) || \
     (M251_USB_HIRC_TRIM_BOUNDARY > 31U))
#error "M251_USB_HIRC_TRIM_BOUNDARY must be in the range 1..31"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of an IN endpoint state structure.
 */
typedef struct {
  /** @brief Requested transmit transfer size.*/
  size_t txsize;
  /** @brief Transmitted bytes so far.*/
  size_t txcnt;
  /** @brief Pointer to the transmission linear buffer.*/
  const uint8_t *txbuf;
#if USB_USE_WAIT || defined(__DOXYGEN__)
  /** @brief Waiting thread.*/
  thread_reference_t thread;
#endif
} USBInEndpointState;

/**
 * @brief   Type of an OUT endpoint state structure.
 */
typedef struct {
  /** @brief Requested receive transfer size.*/
  size_t rxsize;
  /** @brief Received bytes so far.*/
  size_t rxcnt;
  /** @brief Pointer to the receive linear buffer.*/
  uint8_t *rxbuf;
#if USB_USE_WAIT || defined(__DOXYGEN__)
  /** @brief Waiting thread.*/
  thread_reference_t thread;
#endif
} USBOutEndpointState;

/**
 * @brief   Type of a USB endpoint configuration structure.
 * @note    Platform-specific restrictions may apply to endpoints.
 */
typedef struct {
  /** @brief Type and mode of the endpoint.*/
  uint32_t ep_mode;
  /**
   * @brief   Setup packet notification callback.
   * @note    This field is valid only for control endpoints.
   */
  usbepcallback_t setup_cb;
  /** @brief IN endpoint notification callback.*/
  usbepcallback_t in_cb;
  /** @brief OUT endpoint notification callback.*/
  usbepcallback_t out_cb;
  /** @brief IN endpoint maximum packet size.*/
  uint16_t in_maxsize;
  /** @brief OUT endpoint maximum packet size.*/
  uint16_t out_maxsize;
  /** @brief State associated with the IN endpoint.*/
  USBInEndpointState *in_state;
  /** @brief State associated with the OUT endpoint.*/
  USBOutEndpointState *out_state;
  /**
   * @brief   Number of endpoint buffers.
   * @note    Initialize this field to one for forward compatibility.
   */
  uint16_t ep_buffers;
  /**
   * @brief   Pointer to a setup packet buffer.
   * @note    Set this field to @p NULL for non-control endpoints.
   */
  uint8_t *setup_buf;
} USBEndpointConfig;

/**
 * @brief   Type of a USB driver configuration structure.
 */
typedef struct {
  /** @brief USB events callback.*/
  usbeventcb_t event_cb;
  /**
   * @brief   Device GET_DESCRIPTOR request callback.
   * @note    This callback is mandatory and cannot be @p NULL.
   */
  usbgetdescriptor_t get_descriptor_cb;
  /** @brief Standard and non-standard requests hook callback.*/
  usbreqhandler_t requests_hook_cb;
  /** @brief Start Of Frame callback.*/
  usbcallback_t sof_cb;
} USBConfig;

/**
 * @brief   Structure representing a USB driver.
 */
struct USBDriver {
  /** @brief Driver state.*/
  usbstate_t state;
  /** @brief Current configuration data.*/
  const USBConfig *config;
  /** @brief Bitmap of the transmitting IN endpoints.*/
  uint16_t transmitting;
  /** @brief Bitmap of the receiving OUT endpoints.*/
  uint16_t receiving;
  /** @brief Active endpoint configurations.*/
  const USBEndpointConfig *epc[USB_MAX_ENDPOINTS + 1U];
  /**
   * @brief   User parameters associated with IN endpoints.
   * @note    The base index is one; endpoint zero has no reserved element.
   */
  void *in_params[USB_MAX_ENDPOINTS];
  /**
   * @brief   User parameters associated with OUT endpoints.
   * @note    The base index is one; endpoint zero has no reserved element.
   */
  void *out_params[USB_MAX_ENDPOINTS];
  /** @brief Endpoint zero state.*/
  usbep0state_t ep0state;
  /** @brief Next position in the endpoint zero transfer buffer.*/
  uint8_t *ep0next;
  /** @brief Number of bytes remaining in the endpoint zero transfer.*/
  size_t ep0n;
  /** @brief Endpoint zero transaction completion callback.*/
  usbcallback_t ep0endcb;
  /** @brief Setup packet buffer.*/
  uint8_t setup[8];
  /** @brief Current USB device status.*/
  uint16_t status;
  /** @brief Assigned USB address.*/
  uint8_t address;
  /** @brief Current USB device configuration.*/
  uint8_t configuration;
  /** @brief Driver state saved on suspend.*/
  usbstate_t saved_state;
#if defined(USB_DRIVER_EXT_FIELDS)
  USB_DRIVER_EXT_FIELDS
#endif
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the current frame number.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @return              The current frame number.
 * @notapi
 */
#define usb_lld_get_frame_number(usbp)                                      \
  (USBD->FN & 0x7FFU)

/**
 * @brief   Returns the exact size of a receive transaction.
 * @details The received size can differ from the requested size because the
 *          last packet can be shorter than expected.
 * @pre     The OUT endpoint must be configured in transaction mode.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @return              Received data size.
 * @notapi
 */
#define usb_lld_get_transaction_size(usbp, ep)                              \
  ((usbp)->epc[ep]->out_state->rxcnt)

/**
 * @brief   Connects the USB device to the bus.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @api
 */
#define usb_lld_connect_bus(usbp)                                           \
  do {                                                                      \
    (void)(usbp);                                                           \
    USBD->SE0 = 0U;                                                         \
    USBD->ATTR |= USBD_ATTR_DPPUEN_Msk;                                     \
  } while (false)

/**
 * @brief   Disconnects the USB device from the bus.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @api
 */
#define usb_lld_disconnect_bus(usbp)                                        \
  do {                                                                      \
    (void)(usbp);                                                           \
    USBD->SE0 = USBD_SE0_SE0_Msk;                                           \
    USBD->ATTR &= ~USBD_ATTR_DPPUEN_Msk;                                    \
  } while (false)

/**
 * @brief   Starts the host remote wake-up procedure.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @notapi
 */
#define usb_lld_wakeup_host(usbp)                                           \
  do {                                                                      \
    USBD->ATTR |= USBD_ATTR_RWAKEUP_Msk;                                    \
    osalThreadSleepMilliseconds(10);                                        \
    USBD->ATTR &= ~USBD_ATTR_RWAKEUP_Msk;                                   \
    _usb_wakeup(usbp);                                                      \
  } while (false)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if M251_USB_USE_USBD1 && !defined(__DOXYGEN__)
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
  void usb_lld_start_out(USBDriver *usbp, usbep_t ep);
  void usb_lld_start_in(USBDriver *usbp, usbep_t ep);
  void usb_lld_stall_out(USBDriver *usbp, usbep_t ep);
  void usb_lld_stall_in(USBDriver *usbp, usbep_t ep);
  void usb_lld_clear_out(USBDriver *usbp, usbep_t ep);
  void usb_lld_clear_in(USBDriver *usbp, usbep_t ep);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_USB == TRUE */

#endif /* HAL_USB_LLD_H */

/** @}*/
