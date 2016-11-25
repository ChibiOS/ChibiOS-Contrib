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
 * @file    hal_rf.c
 * @brief   RF Driver code.
 *
 * @addtogroup RF
 * @{
 */


#include "hal.h"

#if (HAL_USE_RF == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   RF Driver initialization.
 * @note    This function is implicitly invoked by @p halInit(), there is
 *          no need to explicitly initialize the driver.
 *
 * @init
 */
void rfInit(void) {
  rf_lld_init();
}


/**
 * @brief   Initializes the standard part of a @p RFDriver structure.
 *
 * @param[out] rfp     pointer to the @p RFDriver object
 *
 * @init
 */
void rfObjectInit(RFDriver *rfp) {

  rfp->state  = RF_STOP;
  rfp->config = NULL;

#if RF_USE_MUTUAL_EXCLUSION == TRUE
  osalMutexObjectInit(&rfp->mutex);
#endif

#if defined(RF_DRIVER_EXT_INIT_HOOK)
  RF_DRIVER_EXT_INIT_HOOK(rfp);
#endif
}


/**
 * @brief   Configures and activates the RF peripheral.
 *
 * @param[in] rfp       pointer to the @p RFDriver object
 * @param[in] config    pointer to the @p RFConfig object
 *
 * @api
 */
void rfStart(RFDriver *rfp, const RFConfig *config) {

  osalDbgCheck((rfp != NULL) && (config != NULL));
  osalDbgAssert((rfp->state == RF_STOP  ) ||
		(rfp->state == RF_READY ) ||
                (rfp->state == RF_LOCKED),
		"invalid state");

  osalSysLock();
  rfp->config = config;
  rf_lld_start(rfp);
  rfp->state = RF_READY;
  osalSysUnlock();
}


/**
 * @brief   Deactivates the RF peripheral.
 *
 * @param[in] rfp       pointer to the @p RFDriver object
 *
 * @api
 */
void rfStop(RFDriver *rfp) {

  osalDbgCheck(rfp != NULL);

  osalSysLock();
  rf_lld_stop(rfp);
  rfp->state = RF_STOP;
  osalSysUnlock();
}


/**
 * @brief   Sends data over the air.
 *
 * @param[in] rfp       pointer to the @p RFDriver object
 * @param[in] addr      destination address
 * @param[in] n         number of bytes to be transmitted
 * @param[in] txbuf     pointer to transmit buffer
 *
 * @api
 */
void rfStartSend(RFDriver *rfp, rf_addr_t addr, size_t n, const uint8_t *txbuf) {
  osalDbgCheck((rfp != NULL) && (txbuf != NULL));
    
  osalSysLock();
  osalDbgAssert(rfp->state == RF_READY, "not ready");
  rfStartSendI(rfp, addr, n, txbuf);
  osalSysUnlock();
}


/**
 * @brief   Receives data from the air.
 * @details This asynchronous function starts a receive operation.
 * @post    At the end of the operation the configured callback is invoked.
 *
 * @param[in]     rfp      pointer to the @p RFDriver object
 * @param[in,out] np       number of words to receive
 * @param[out]    rxbuf    the pointer to the receive buffer
 *
 * @api
 */
void rfStartReceive(RFDriver *rfp, size_t *np, void *rxbuf) {

  osalDbgCheck((rfp != NULL) && (rxbuf != NULL));

  osalSysLock();
  osalDbgAssert(rfp->state == RF_READY, "not ready");
  rfStartReceiveI(rfp, np, rxbuf);
  osalSysUnlock();
}


#if RF_USE_WAIT == TRUE
void rfSend(RFDriver *rfp, rf_addr_t addr, size_t n, const uint8_t *txbuf) {
  osalDbgCheck((rfp != NULL) && (txbuf != NULL));
    
  osalSysLock();
  osalDbgAssert(rfp->state == RF_READY, "not ready");
  osalDbgAssert(rfp->config->end_cb == NULL, "has callback");
  rfStartSendI(rfp, addr, n, txbuf);
  (void) osalThreadSuspendS(&rfp->thread);
  osalSysUnlock();
}

/**
 * @brief   Performs a receive operation on the air.
 * @note    This function implements a software timeout, it does not use
 *          any underlying HW timeout mechanism.
 *
 * @param[in] rfp     pointer to the @p RFDriver object
 * @param[in,out] np    number of data frames to receive, on exit the number
 *                      of frames actually received
 * @param[in] rxbuf     the pointer to the receive buffer
 * @param[in] timeout   operation timeout
 *
 * @return              The operation status.
 * @retval MSG_OK       if the operation completed successfully.
 * @retval MSG_TIMEOUT  if the operation timed out.
 * @retval MSG_RESET    in case of a receive error.
 *
 * @api
 */
msg_t rfReceiveTimeout(RFDriver *rfp, size_t *np, void *rxbuf, systime_t timeout) {

  msg_t msg;

  osalDbgCheck((rfp != NULL) && (rxbuf != NULL));

  osalSysLock();
  osalDbgAssert(rfp->state == RF_READY, "not ready");
  osalDbgAssert(rfp->config->end_cb == NULL, "has callback");

  rfStartReceiveI(rfp, np, rxbuf);
  msg = osalThreadSuspendTimeoutS(&rfp->thread, timeout);
  if (msg == MSG_OK) {
      if (rfp->error != RF_ERROR_NONE)
	  msg = MSG_RESET;
  } else {
      rfStopReceiveI(rfp);
  }
  rf_lld_received(rfp, np, rxbuf);
  osalSysUnlock();

  return msg;
}


#endif /* RF_USE_WAIT */

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

#if (RF_USE_MUTUAL_EXCLUSION == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   Gains exclusive access to the radio.
 * @details This function tries to gain ownership to the RF bus, if the bus
 *          is already being used then the invoking thread is queued.
 * @pre     In order to use this function the option @p RF_USE_MUTUAL_EXCLUSION
 *          must be enabled.
 *
 * @param[in] rfp      pointer to the @p RFDriver object
 *
 * @api
 */
void rfAcquireRadio(RFDriver *rfp) {
  osalDbgCheck(rfp != NULL);

  osalMutexLock(&rfp->mutex);
}

/**
 * @brief   Releases exclusive access to the radio.
 * @pre     In order to use this function the option @p RF_USE_MUTUAL_EXCLUSION
 *          must be enabled.
 *
 * @param[in] rfp      pointer to the @p RFDriver object
 *
 * @api
 */
void rfReleaseRadio(RFDriver *rfp) {
  osalDbgCheck(rfp != NULL);

  osalMutexUnlock(&rfp->mutex);
}
#endif /* RF_USE_MUTUAL_EXCLUSION == TRUE */


#endif /* HAL_USE_RF == TRUE */

/** @} */
