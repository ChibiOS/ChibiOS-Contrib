/*
    ChibiOS - Copyright (C) 2016..2016 Stephane D'Alu

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
 * @file    hal_rf.h
 * @brief   RF Driver macros and structures.
 *
 * @addtogroup RF
 * @{
 */

#ifndef HAL_RF_H
#define HAL_RF_H

#if (HAL_USE_RF == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/


/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    RF configuration options
 * @{
 */
/**
 * @brief   Enables synchronous APIs.
 * @note    Disabling this option saves both code and data space.
 */
#if !defined(RF_USE_WAIT) || defined(__DOXYGEN__)
#define RF_USE_WAIT TRUE
#endif

/**
 * @brief   Enables the @p rfAcquireBus() and @p rfReleaseBus() APIs.
 * @note    Disabling this option saves both code and data space.
 */
#if !defined(RF_USE_MUTUAL_EXCLUSION)
#define RF_USE_MUTUAL_EXCLUSION TRUE
#endif

/**
 * @brief   Define the maximum payload
 */
#if !defined(RF_PAYLOAD_MAXLEN)
#define RF_PAYLOAD_MAXLEN     127
#endif
/** @} */


/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/


/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Driver state machine possible states.
 */
typedef enum {
  RF_UNINIT    = 0,              /**< Not initialized.                   */
  RF_STOP      = 1,              /**< Stopped.                           */
  RF_READY     = 2,              /**< Ready.                             */
  RF_ACTIVE_TX = 3,              /**< Transmitting.                      */
  RF_ACTIVE_RX = 4,              /**< Receiving.                         */
  RF_COMPLETE  = 5,              /**< Asynchronous operation complete.   */
  RF_LOCKED    = 6               /**< Bus or driver locked.              */
} rfstate_t;


#include "hal_rf_lld.h"


/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @name    Macro Functions
 * @{
 */
/**
 * @brief   Sends data over the air.
 * @details This asynchronous function starts a transmit operation.
 * @post    At the end of the operation the configured callback is invoked.
 *
 * @param[in] rfp       pointer to the @p RFDriver object
 * @param[in] addr      destination address
 * @param[in] n         number of words to send
 * @param[in] txbuf     the pointer to the transmit buffer
 *
 * @iclass
 */
#define rfStartSendI(rfp, addr, n, txbuf) {				\
  (rfp)->state = RF_ACTIVE_TX;						\
  rf_lld_send(rfp, addr, n, txbuf);					\
}

/**
 * @brief   Receives data from the RF bus.
 * @details This asynchronous function starts a receive operation.
 * @pre     A slave must have been selected using @p rfSelect() or
 *          @p rfSelectI().
 * @post    At the end of the operation the configured callback is invoked.
 * @note    The buffers are organized as uint8_t arrays for data sizes below
 *          or equal to 8 bits else it is organized as uint16_t arrays.
 *
 * @param[in]     rfp       pointer to the @p RFDriver object
 * @param[in,out] np        number of words to receive
 * @param[out]    rxbuf     the pointer to the receive buffer
 *
 * @iclass
 */
#define rfStartReceiveI(rfp, np, rxbuf) {				\
  (rfp)->state = RF_ACTIVE_RX; 						\
  rf_lld_receive(rfp, np, rxbuf);					\
}

/**
 * @brief   Stops any ongoing receive operation.
 * @note    Stopping a receive operation also suppresses the receive callbacks.
 * @note    This function has to be invoked from a lock zone.
 *
 * @param[in] rfp      pointer to the @p RFDriver object
 *
 * @iclass
 */
#define rfStopReceiveI(rfp) { 						\
  rf_lld_stop_receive(rfp);						\
  rfp->state = RF_READY;						\
}

/**
 * @brief   Performs a receive operation on the air.
 * @note    This function implements a software timeout, it does not use
 *          any underlying HW timeout mechanism.
 *
 * @param[in] rfp       pointer to the @p RFDriver object
 * @param[in,out] np    number of byte in the frame received
 *                      of frames actually received
 * @param[in] rxbuf     the pointer to the receive buffer
 *
 * @return              The operation status.
 * @retval MSG_OK       if the operation completed successfully.
 * @retval MSG_RESET    in case of a receive error.
 *
 * @api
 */
#define rfReceive(rfp, np, rxbuf) 					\
  rfReceiveTimeout(rfp, np, rxbuf, TIME_INFINITE)
/** @} */


/**
 * @name    Low level driver helper macros
 * @{
 */
#if (RF_USE_WAIT == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   Wakes up the waiting thread.
 *
 * @param[in] rfp      pointer to the @p RFDriver object
 *
 * @notapi
 */
#define _rf_wakeup_isr(rfp) {                                               \
  osalSysLockFromISR();                                                     \
  osalThreadResumeI(&(rfp)->thread, MSG_OK);                                \
  osalSysUnlockFromISR();                                                   \
}
#else /* !RF_USE_WAIT */
#define _rf_wakeup_isr(rfp)
#endif /* !RF_USE_WAIT */

/**
 * @brief   Common ISR code.
 * @details This code handles the portable part of the ISR code:
 *          - Callback invocation.
 *          - Waiting thread wakeup, if any.
 *          - Driver state transitions.
 *          .
 * @note    This macro is meant to be used in the low level drivers
 *          implementation only.
 *
 * @param[in] rfp      pointer to the @p RFDriver object
 *
 * @notapi
 */
#define _rf_isr_code(rfp) {                                                 \
  if ((rfp)->config->end_cb) {                                              \
    (rfp)->state = RF_COMPLETE;                                             \
    (rfp)->config->end_cb(rfp);                                             \
    if ((rfp)->state == RF_COMPLETE)                                        \
      (rfp)->state = RF_READY;                                              \
  }                                                                         \
  else                                                                      \
    (rfp)->state = RF_READY;                                                \
  _rf_wakeup_isr(rfp);                                                      \
}
/** @} */


/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void rfInit(void);
  void rfObjectInit(RFDriver *rfp);
  void rfStart(RFDriver *rfp, const RFConfig *config);
  void rfStop(RFDriver *rfp);
  void rfStartSend(RFDriver *rfp, uint16_t addr, 
		    size_t n, const uint8_t *txbuf);
  void rfStartReceive(RFDriver *rfp, size_t *np, void *rxbuf);
   
#if RF_USE_WAIT == TRUE
  void rfSend(RFDriver *rfp, rf_addr_t addr, size_t n, const uint8_t *txbuf);
  msg_t rfReceiveTimeout(RFDriver *rfp, size_t *np,
			  void *rxbuf, systime_t timeout);
#endif

#if RF_USE_MUTUAL_EXCLUSION == TRUE
  void rfAcquireRadio(RFDriver *rfp);
  void rfReleaseRadio(RFDriver *rfp);
#endif

#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_RF == TRUE */

#endif /* HAL_RF_H */

/** @} */
