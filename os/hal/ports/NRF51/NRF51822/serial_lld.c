/*
    Copyright (C) 2015 Fabio Utzig

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
 * @file    serial_lld.c
 * @brief   NRF51822 serial subsystem low level driver source.
 *
 * @addtogroup SERIAL
 * @{
 */

#include "hal.h"

#if (HAL_USE_SERIAL == TRUE) || defined(__DOXYGEN__)

#include "nrf51.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief USART1 serial driver identifier.*/
#if (NRF51_SERIAL_USE_UART0 == TRUE) || defined(__DOXYGEN__)
SerialDriver SD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/**
 * @brief   Driver default configuration.
 */
static const SerialConfig default_config = {
  38400
};

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Driver output notification.
 */
#if NRF51_SERIAL_USE_UART0 || defined(__DOXYGEN__)
static void notify1(io_queue_t *qp)
{
  (void)qp;

  //if (NRF_UART0->EVENTS_TXDRDY) {
    msg_t b = oqGetI(&SD1.oqueue);
    if (b < Q_OK) {
      chnAddFlagsI(&SD1, CHN_OUTPUT_EMPTY);
      return;
    }
    NRF_UART0->TXD = b;
    //NRF_UART0->INTENCLR = 0x80; // clear TX interrupt
  //}
}
#endif


/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if NRF51_SERIAL_USE_UART0 || defined(__DOXYGEN__)
OSAL_IRQ_HANDLER(Vector48) {

  OSAL_IRQ_PROLOGUE();

  if (NRF_UART0->EVENTS_RXDRDY) {
    osalSysLockFromISR();
    if (iqIsEmptyI(&SD1.iqueue))
      chnAddFlagsI(&SD1, CHN_INPUT_AVAILABLE);
    if (iqPutI(&SD1.iqueue, NRF_UART0->RXD) < Q_OK)
      chnAddFlagsI(&SD1, SD_OVERRUN_ERROR);
    //NRF_UART0->INTENCLR = 4;
    osalSysUnlockFromISR();
  }

  if (NRF_UART0->EVENTS_TXDRDY) {
    msg_t b;

    osalSysLockFromISR();
    b = oqGetI(&SD1.oqueue);
    osalSysUnlockFromISR();

    if (b < Q_OK) {
      osalSysLockFromISR();
      chnAddFlagsI(&SD1, CHN_OUTPUT_EMPTY);
      osalSysUnlockFromISR();
      NRF_UART0->INTENCLR = 0x80; // clear TX interrupt
    } else {
       NRF_UART0->TXD = b;
    }
  }

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level serial driver initialization.
 *
 * @notapi
 */
void sd_lld_init(void) {

#if NRF51_SERIAL_USE_UART0 == TRUE
  sdObjectInit(&SD1, NULL, notify1);
#endif
}

/**
 * @brief   Low level serial driver configuration and (re)start.
 *
 * @param[in] sdp       pointer to a @p SerialDriver object
 * @param[in] config    the architecture-dependent serial driver configuration.
 *                      If this parameter is set to @p NULL then a default
 *                      configuration is used.
 *
 * @notapi
 */
void sd_lld_start(SerialDriver *sdp, const SerialConfig *config) {

  if (config == NULL) {
    config = &default_config;
  }

  if (sdp->state == SD_STOP) {

#if NRF51_SERIAL_USE_UART0 == TRUE
    if (sdp == &SD1) {
      /* FIXME: some board specific, some hardcodeds! */

      /* Configure PINs */
      NRF_UART0->PSELRTS = ~0;
      NRF_UART0->PSELCTS = ~0;

      NRF_GPIO->PIN_CNF[9] = 1;
      NRF_UART0->PSELTXD = 9;
      NRF_UART0->PSELRXD = 11;

      /* 38400!!! */
      NRF_UART0->BAUDRATE = 0x009D5000;

      /* Enable interrupts for RX, TX and ERROR */
      NRF_UART0->INTENSET = 0x284;

      nvicEnableVector(UART0_IRQn, 12);

      NRF_UART0->ENABLE = 4;
      NRF_UART0->TASKS_STARTRX = 1;
      NRF_UART0->TASKS_STARTTX = 1;
    }
#endif

  }
}

/**
 * @brief   Low level serial driver stop.
 * @details De-initializes the USART, stops the associated clock, resets the
 *          interrupt vector.
 *
 * @param[in] sdp       pointer to a @p SerialDriver object
 *
 * @notapi
 */
void sd_lld_stop(SerialDriver *sdp) {

  if (sdp->state == SD_READY) {

#if NRF51_SERIAL_USE_UART0 == TRUE
    if (&SD1 == sdp) {
      nvicDisableVector(UART0_IRQn);
    }
#endif

  }
}

#endif /* HAL_USE_SERIAL == TRUE */

/** @} */
