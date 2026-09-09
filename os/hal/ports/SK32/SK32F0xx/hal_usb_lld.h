/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    SK32F0xx USB LLD - 3Think SK32F077 (Mentor/MUSB musbfsfc class USB FS controller)

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
 * @file    SK32F0xx/hal_usb_lld.h
 * @brief   SK32 USB subsystem low level driver header.
 * @details The SK32F077 embeds a Mentor/MUSB (musbfsfc) full-speed USB device
 *          controller whose register map is completely different from the
 *          STM32F0 USB (PMA) peripheral, although the rest of the chip is
 *          STM32F072 register compatible. This driver is modeled on the
 *          3Think CherryUSB port (usb_dc_musbfsfc) shipped inside the
 *          "SK32F0xx_Firmware Package".
 *
 * @addtogroup USB
 * @{
 */

#ifndef HAL_USB_LLD_H
#define HAL_USB_LLD_H

#if HAL_USE_USB || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Maximum endpoint number supported by the controller.
 * @note    The musbfsfc core has 16 endpoint FIFOs but the INTR1/OUT1
 *          registers used by this driver cover endpoints 0..7. QMK class
 *          drivers only need a handful of endpoints.
 */
#define USB_MAX_ENDPOINTS                   8U

/**
 * @brief   Status stage handling method (software driven, same as the
 *          STM32 USBv1 LLD: the control-transfer status ZLP is exchanged
 *          through usbStartTransmitI()/usbStartReceiveI()).
 */
#define USB_EP0_STATUS_STAGE                USB_EP0_STATUS_STAGE_SW

/**
 * @brief   This device requires the address change after the status packet.
 * @note    The musbfsfc core latches FADDR only when the firmware writes it;
 *          a SET_ADDRESS control transfer is completed with the status ZLP
 *          still sent at address zero, so the address is programmed by
 *          usb_lld_set_address() which the high level layer invokes once the
 *          status stage has completed.
 */
#define USB_SET_ADDRESS_MODE                USB_LATE_SET_ADDRESS

/**
 * @brief   Method for set address acknowledge.
 */
#define USB_SET_ADDRESS_ACK_HANDLING        USB_SET_ADDRESS_ACK_SW

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   USB driver enable switch.
 * @details If set to @p TRUE the support for USB is included.
 * @note    The default is @p TRUE.
 */
#if !defined(SK32_USB_USE_USB1) || defined(__DOXYGEN__)
#define SK32_USB_USE_USB1                  TRUE
#endif

/**
 * @brief   Enables the USB device low power mode on suspend.
 */
#if !defined(SK32_USB_LOW_POWER_ON_SUSPEND) || defined(__DOXYGEN__)
#define SK32_USB_LOW_POWER_ON_SUSPEND      FALSE
#endif

/**
 * @brief   USB interrupt priority level setting.
 * @note    The SK32F077 has a single USB IRQ line (vector 31) shared by the
 *          "HP" and "LP" STM32F0 naming conventions.
 */
#if !defined(SK32_USB_USB1_HP_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SK32_USB_USB1_HP_IRQ_PRIORITY      3
#endif

/**
 * @brief   USB interrupt priority level setting.
 */
#if !defined(SK32_USB_USB1_LP_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SK32_USB_USB1_LP_IRQ_PRIORITY      3
#endif

/*===========================================================================*/
/* SK32 USB controller register definition.                                  */
/*===========================================================================*/

/**
 * @brief   SK32 musbfsfc USB controller base address.
 */
#define SK32_USB_BASE                       0x40005C00U

/**
 * @brief   Type of the SK32 musbfsfc USB register file.
 * @note    All registers are 8 bit wide and the endpoint status/control
 *          registers are selected through the INDEX register.
 */
typedef struct {
  volatile uint8_t  FADDR;      /**< @brief Function address.                */
  volatile uint8_t  POWER;      /**< @brief Power management.                */
  volatile uint8_t  INTRIN1;    /**< @brief EP0 + IN EP1..7 interrupts.      */
  volatile uint8_t  INTRIN2;    /**< @brief IN EP8..15 interrupts.           */
  volatile uint8_t  INTROUT1;   /**< @brief OUT EP1..7 interrupts.           */
  volatile uint8_t  INTROUT2;   /**< @brief OUT EP8..15 interrupts.          */
  volatile uint8_t  INTRUSB;    /**< @brief Common USB interrupts.           */
  volatile uint8_t  INTRIN1E;   /**< @brief INTRIN1 enable.                  */
  volatile uint8_t  INTRIN2E;   /**< @brief INTRIN2 enable.                  */
  volatile uint8_t  INTROUT1E;  /**< @brief INTROUT1 enable.                 */
  volatile uint8_t  INTROUT2E;  /**< @brief INTROUT2 enable.                 */
  volatile uint8_t  INTRUSBE;   /**< @brief INTRUSB enable.                  */
  volatile uint8_t  FRAME1;     /**< @brief Frame number bits 0..7.          */
  volatile uint8_t  FRAME2;     /**< @brief Frame number bits 8..10.         */
  volatile uint8_t  INDEX;      /**< @brief Endpoint index selection.        */
  volatile uint8_t  RESERVED0;
  volatile uint8_t  INMAXP;     /**< @brief IN endpoint max packet size.     */
  volatile uint8_t  CSR;        /**< @brief EP0 CSR / IN endpoint CSR1.      */
  volatile uint8_t  INCSR2;     /**< @brief IN endpoint CSR2.                */
  volatile uint8_t  OUTMAXP;    /**< @brief OUT endpoint max packet size.    */
  volatile uint8_t  OUTCSR1;    /**< @brief OUT endpoint CSR1.               */
  volatile uint8_t  OUTCSR2;    /**< @brief OUT endpoint CSR2.               */
  volatile uint8_t  COUNT;      /**< @brief Received bytes (low byte).       */
  volatile uint8_t  OUTCOUNT2;  /**< @brief Received bytes (high byte).      */
  volatile uint8_t  RESERVED1[8];
  volatile uint8_t  FIFO[16];   /**< @brief Endpoint FIFOs (8 bit).          */
  volatile uint8_t  RESERVED2[8];
  volatile uint8_t  PULL;       /**< @brief D+/D- pull-up control.           */
} SK32_USB_TypeDef;

/**
 * @brief   SK32 musbfsfc controller instance.
 * @note    Named SK32_USB on purpose: the STM32F072 CMSIS header (which this
 *          port reuses for the rest of the chip) already defines a different
 *          `USB` peripheral for the PMA-based ST USB IP.
 */
#define SK32_USB                ((SK32_USB_TypeDef *)SK32_USB_BASE)

/* FADDR register. */
#define SK32_FADDR_FUNC_ADDR    0x7FU        /**< Function address.          */
#define SK32_FADDR_UPDATE       0x80U        /**< Address update pending.    */

/* POWER register. */
#define SK32_POWER_ENSUS        0x01U        /**< Enable suspend mode.       */
#define SK32_POWER_SUSMOD       0x02U        /**< Suspend mode enable.       */
#define SK32_POWER_RESUME       0x04U        /**< Resume signaling.          */
#define SK32_POWER_RESET        0x08U        /**< Bus reset in progress.     */
#define SK32_POWER_ISOUP        0x80U        /**< Isochronous ups.           */

/* INTRUSB register. */
#define SK32_INTRUSB_SUS        0x01U        /**< Suspend interrupt.         */
#define SK32_INTRUSB_RESUME     0x02U        /**< Resume interrupt.          */
#define SK32_INTRUSB_RESET      0x04U        /**< Reset interrupt.           */
#define SK32_INTRUSB_SOF        0x08U        /**< SOF interrupt.             */

/* INTRUSBE register. */
#define SK32_INTRUSBE_SUS       0x01U
#define SK32_INTRUSBE_RESUME    0x02U
#define SK32_INTRUSBE_RESET     0x04U
#define SK32_INTRUSBE_SOF       0x08U

/* EP0 CSR (index 0) register. */
#define SK32_CSR0_OPKTRD        0x01U        /**< OUT/setup packet ready.    */
#define SK32_CSR0_IPKTRD        0x02U        /**< IN packet ready (TX).      */
#define SK32_CSR0_SENTST        0x04U        /**< STALL handshake sent.      */
#define SK32_CSR0_DATEND        0x08U        /**< End of data stage.         */
#define SK32_CSR0_SETUPEND      0x10U        /**< Setup ended before DATAEND.*/
#define SK32_CSR0_SENDST        0x20U        /**< Send STALL handshake.      */
#define SK32_CSR0_SEROPKTRD     0x40U        /**< Service RX packet ready.   */
#define SK32_CSR0_SERSETUPEND   0x80U        /**< Service SETUPEND.          */

/* IN CSR1 register (index != 0, aliased with the CSR register). */
#define SK32_INCSR1_IPKTRD      0x01U        /**< IN packet ready (TX).      */
#define SK32_INCSR1_FIFONE      0x02U        /**< TX FIFO not empty.         */
#define SK32_INCSR1_UNDERRUN    0x04U        /**< TX underrun.               */
#define SK32_INCSR1_FLFIFO      0x08U        /**< Flush TX FIFO.             */
#define SK32_INCSR1_SENDST      0x10U        /**< Send STALL handshake.      */
#define SK32_INCSR1_SENTST      0x20U        /**< STALL handshake sent.      */
#define SK32_INCSR1_CLRDT       0x40U        /**< Clear data toggle.         */

/* IN CSR2 register. */
#define SK32_INCSR2_FRCDT       0x08U        /**< Force data toggle.         */
#define SK32_INCSR2_DMAEN       0x10U        /**< DMA request enable.        */
#define SK32_INCSR2_MODE        0x20U        /**< Endpoint direction IN.     */
#define SK32_INCSR2_ISO         0x40U        /**< Isochronous endpoint.      */
#define SK32_INCSR2_AUTOSET     0x80U        /**< Auto set on FIFO write.    */

/* OUT CSR1 register. */
#define SK32_OUTCSR1_OPKTRD     0x01U        /**< OUT packet ready.          */
#define SK32_OUTCSR1_FIFOF      0x02U        /**< RX FIFO full.              */
#define SK32_OUTCSR1_OVERRUN    0x04U        /**< RX overrun.                */
#define SK32_OUTCSR1_DATERR     0x08U        /**< RX data error.             */
#define SK32_OUTCSR1_FLFIFO     0x10U        /**< Flush RX FIFO.             */
#define SK32_OUTCSR1_SENDST     0x20U        /**< Send STALL handshake.      */
#define SK32_OUTCSR1_SENTST     0x40U        /**< STALL handshake sent.      */
#define SK32_OUTCSR1_CLRDT      0x80U        /**< Clear data toggle.         */

/* OUT CSR2 register. */
#define SK32_OUTCSR2_DMAMODE    0x10U        /**< DMA burst mode.            */
#define SK32_OUTCSR2_DMAEN      0x20U        /**< DMA request enable.        */
#define SK32_OUTCSR2_ISO        0x40U        /**< Isochronous endpoint.      */
#define SK32_OUTCSR2_AUTOCLR    0x80U        /**< Auto clear on FIFO read.   */

/* PULL register. */
#define SK32_PULL_DP            0x01U        /**< D+ pull-up (full speed).   */
#define SK32_PULL_DM            0x02U        /**< D- pull-up (low speed).    */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !defined(SK32_USB_HANDLER) || !defined(SK32_USB_NUMBER)
#error "SK32_USB_HANDLER/NUMBER not defined in registry"
#endif

#if SK32_USB_USE_USB1 && !OSAL_IRQ_IS_VALID_PRIORITY(SK32_USB_USB1_LP_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to USB LP"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of an IN endpoint state structure.
 */
typedef struct {
  /**
   * @brief   Requested transmit transfer size.
   */
  size_t                        txsize;
  /**
   * @brief   Transmitted bytes so far.
   */
  size_t                        txcnt;
  /**
   * @brief   Pointer to the transmission linear buffer.
   */
  const uint8_t                 *txbuf;
#if (USB_USE_WAIT == TRUE) || defined(__DOXYGEN__)
  /**
   * @brief   Waiting thread.
   */
  thread_reference_t            thread;
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief   Size of the last transmitted packet.
   */
  size_t                        txlast;
} USBInEndpointState;

/**
 * @brief   Type of an OUT endpoint state structure.
 */
typedef struct {
  /**
   * @brief   Requested receive transfer size.
   */
  size_t                        rxsize;
  /**
   * @brief   Received bytes so far.
   */
  size_t                        rxcnt;
  /**
   * @brief   Pointer to the receive linear buffer.
   */
  uint8_t                       *rxbuf;
#if (USB_USE_WAIT == TRUE) || defined(__DOXYGEN__)
  /**
   * @brief   Waiting thread.
   */
  thread_reference_t            thread;
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief   Number of packets to receive.
   */
  uint16_t                      rxpkts;
} USBOutEndpointState;

/**
 * @brief   Type of an USB endpoint configuration structure.
 * @note    Platform specific restrictions may apply to endpoints.
 */
typedef struct {
  /**
   * @brief   Type and mode of the endpoint.
   */
  uint32_t                      ep_mode;
  /**
   * @brief   Setup packet notification callback.
   * @post    The application must immediately call @p usbReadPacket() in
   *          order to access the received packet.
   */
  usbepcallback_t               setup_cb;
  /**
   * @brief   IN endpoint notification callback.
   */
  usbepcallback_t               in_cb;
  /**
   * @brief   OUT endpoint notification callback.
   */
  usbepcallback_t               out_cb;
  /**
   * @brief   IN endpoint maximum packet size.
   */
  uint16_t                      in_maxsize;
  /**
   * @brief   OUT endpoint maximum packet size.
   */
  uint16_t                      out_maxsize;
  /**
   * @brief   @p USBEndpointState associated to the IN endpoint.
   */
  USBInEndpointState            *in_state;
  /**
   * @brief   @p USBEndpointState associated to the OUT endpoint.
   */
  USBOutEndpointState           *out_state;
  /* End of the mandatory fields.*/
  /**
   * @brief   Reserved field, not currently used.
   */
  uint16_t                      ep_buffers;
  /**
   * @brief   Pointer to a buffer for setup packets.
   */
  uint8_t                       *setup_buf;
} USBEndpointConfig;

/**
 * @brief   Type of an USB driver configuration structure.
 */
typedef struct {
  /**
   * @brief   USB events callback.
   */
  usbeventcb_t                  event_cb;
  /**
   * @brief   Device GET_DESCRIPTOR request callback.
   */
  usbgetdescriptor_t            get_descriptor_cb;
  /**
   * @brief   Requests hook callback.
   */
  usbreqhandler_t               requests_hook_cb;
  /**
   * @brief   Start Of Frame callback.
   */
  usbcallback_t                 sof_cb;
  /* End of the mandatory fields.*/
} USBConfig;

/**
 * @brief   Structure representing an USB driver.
 */
struct USBDriver {
  /**
   * @brief   Driver state.
   */
  usbstate_t                    state;
  /**
   * @brief   Current configuration data.
   */
  const USBConfig               *config;
  /**
   * @brief   Bit map of the transmitting IN endpoints.
   */
  uint16_t                      transmitting;
  /**
   * @brief   Bit map of the receiving OUT endpoints.
   */
  uint16_t                      receiving;
  /**
   * @brief   Active endpoints configurations.
   */
  const USBEndpointConfig       *epc[USB_MAX_ENDPOINTS + 1];
  /**
   * @brief   Fields available to user, it can be used to associate an
   *          application-defined handler to an IN endpoint.
   */
  void                          *in_params[USB_MAX_ENDPOINTS];
  /**
   * @brief   Fields available to user, it can be used to associate an
   *          application-defined handler to an OUT endpoint.
   */
  void                          *out_params[USB_MAX_ENDPOINTS];
  /**
   * @brief   Endpoint 0 state.
   */
  usbep0state_t                 ep0state;
  /**
   * @brief   Next position in the buffer to be transferred through endpoint 0.
   */
  uint8_t                       *ep0next;
  /**
   * @brief   Number of bytes yet to be transferred through endpoint 0.
   */
  size_t                        ep0n;
  /**
   * @brief   Endpoint 0 end transaction callback.
   */
  usbcallback_t                 ep0endcb;
  /**
   * @brief   Setup packet buffer.
   */
  uint8_t                       setup[8];
  /**
   * @brief   Current USB device status.
   */
  uint16_t                      status;
  /**
   * @brief   Assigned USB address.
   */
  uint8_t                       address;
  /**
   * @brief   Current USB device configuration.
   */
  uint8_t                       configuration;
  /**
   * @brief   State of the driver when a suspend happened.
   */
  usbstate_t                    saved_state;
#if defined(USB_DRIVER_EXT_FIELDS)
  USB_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the current frame number.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @return              The current frame number.
 *
 * @notapi
 */
#define usb_lld_get_frame_number(usbp)                                      \
  ((uint16_t)(((uint16_t)SK32_USB->FRAME1) |                                \
              ((uint16_t)(SK32_USB->FRAME2 & 0x07U) << 8U)))

/**
 * @brief   Returns the exact size of a receive transaction.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @return              Received data size.
 *
 * @notapi
 */
#define usb_lld_get_transaction_size(usbp, ep)                              \
  ((usbp)->epc[ep]->out_state->rxcnt)

/**
 * @brief   Connects the USB device by enabling the D+ pull-up.
 *
 * @notapi
 */
#if !defined(usb_lld_connect_bus)
#define usb_lld_connect_bus(usbp)                                           \
  ((void)(usbp), SK32_USB->PULL |= SK32_PULL_DP)
#endif

/**
 * @brief   Disconnect the USB device by disabling the D+ pull-up.
 *
 * @notapi
 */
#if !defined(usb_lld_disconnect_bus)
#define usb_lld_disconnect_bus(usbp)                                        \
  ((void)(usbp), SK32_USB->PULL = 0U)
#endif

/**
 * @brief   Start of host wake-up procedure (remote wakeup).
 * @details The resume signaling is generated by toggling the RESUME bit of
 *          the POWER register for about 10ms as done by the vendor driver.
 *
 * @notapi
 */
#define usb_lld_wakeup_host(usbp)                                           \
  do {                                                                      \
    (void)(usbp);                                                           \
    SK32_USB->POWER |= SK32_POWER_RESUME;                                   \
    osalThreadSleepMilliseconds(10);                                        \
    SK32_USB->POWER &= (uint8_t)~SK32_POWER_RESUME;                         \
  } while (false)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if SK32_USB_USE_USB1 && !defined(__DOXYGEN__)
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

#endif /* HAL_USE_USB */

#endif /* HAL_USB_LLD_H */

/** @} */
