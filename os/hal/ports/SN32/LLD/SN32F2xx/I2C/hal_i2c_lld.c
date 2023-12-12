/*
    Copyright (C) 2023 1Conan
    Copyright (C) 2023 Dimitris Mantzouranis

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
 * @file    hal_i2c_lld.c
 * @brief   SN32 I2C subsystem low level driver source.
 *
 * @addtogroup I2C
 * @{
 */

#include "hal.h"

#if (HAL_USE_I2C == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   I2C0 driver identifier.
 */
#if (SN32_I2C_USE_I2C0 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD0;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline void i2c_lld_configure(I2CDriver *i2cp) {
  i2cp->i2c->SCLHT = i2cp->config->high_time;
  i2cp->i2c->SCLLT = i2cp->config->low_time;
  i2cp->i2c->TOCTRL = i2cp->config->timeout;
  i2cp->i2c->CTRL_b.I2CEN = true;
}

static inline void i2c_lld_irq_handler(I2CDriver * i2cp) {
  chSysLockFromISR();
  i2cp -> i2c -> STAT_b.I2CIF = true;
  chSysUnlockFromISR();

  if (i2cp -> i2c -> STAT_b.LOST_ARB) {
    i2cp -> state = I2C_ARBITRATION_LOST;
    _i2c_wakeup_error_isr(i2cp);
    return;
  }
  if (i2cp -> i2c -> STAT_b.NACK_STAT) {
    i2cp -> i2c -> CTRL_b.ACK = true;
  } else {
    if (i2cp -> i2c -> STAT_b.RX_DN && i2cp -> rx_buffer && i2cp -> count < i2cp -> rx_len) {
      i2cp -> rx_buffer[i2cp -> count++] = i2cp -> i2c -> RXDATA;
      i2cp -> i2c -> CTRL_b.ACK = true;
      return;
    } else {
      if (i2cp -> i2c -> STAT_b.SLV_RX_HIT) {
        i2cp -> i2c -> CTRL_b.ACK = true;
        return;
      }
      if (i2cp -> i2c -> STAT_b.SLV_TX_HIT) {
        //silent return
        return;
      }
    }
    if (i2cp -> i2c -> STAT_b.ACK_STAT && i2cp -> tx_buffer && i2cp -> count < i2cp -> tx_len) {
       i2cp -> i2c -> TXDATA = i2cp -> tx_buffer[i2cp -> count++];
      return;
    }
  }

  if ((i2cp -> rx_buffer && !i2cp -> tx_buffer) || (!i2cp -> rx_buffer && i2cp -> tx_buffer)) {
    if ((i2cp -> count == i2cp -> rx_len) || (i2cp -> count == i2cp -> tx_len)) {
      i2cp -> i2c -> CTRL_b.STO = true;
      i2cp -> i2c -> CTRL_b.I2CEN = false;
      i2cp -> i2c -> CTRL_b.I2CEN = true;
      i2cp -> state = I2C_STOP;
      _i2c_wakeup_isr(i2cp);
      return;
    }
  }
}
/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if SN32_I2C_USE_I2C0
OSAL_IRQ_HANDLER(SN32_I2C0_GLOBAL_HANDLER) {
  OSAL_IRQ_PROLOGUE();

  i2c_lld_irq_handler(&I2CD0);

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level I2C driver initialization.
 *
 * @notapi
 */
void i2c_lld_init(void) {

#if SN32_I2C_USE_I2C0 == TRUE
  i2cObjectInit(&I2CD0);
  I2CD0.thread  = NULL;
  I2CD0.i2c = SN32_I2C0;
#endif
}

/**
 * @brief   Configures and activates the I2C peripheral.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
void i2c_lld_start(I2CDriver *i2cp) {

  if (i2cp->state == I2C_STOP) {
    /* Enables the peripheral.*/
#if SN32_I2C_USE_I2C0 == TRUE
    if (&I2CD0 == i2cp) {
      sys1EnableI2C0();
      nvicClearPending(SN32_I2C0_GLOBAL_NUMBER);
      nvicEnableVector(SN32_I2C0_GLOBAL_NUMBER, SN32_I2C_I2C0_IRQ_PRIORITY);
    }
#endif
  }

  i2c_lld_configure(i2cp);
}

/**
 * @brief   Deactivates the I2C peripheral.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
void i2c_lld_stop(I2CDriver *i2cp) {

  if (i2cp->state != I2C_STOP) {

    i2cp->i2c->CTRL_b.I2CEN = false;

    /* Disables the peripheral.*/
#if SN32_I2C_USE_I2C0 == TRUE
    if (&I2CD0 == i2cp) {
      sys1DisableI2C0();
      nvicDisableVector(SN32_I2C0_GLOBAL_NUMBER);
    }
#endif
  }
}

/**
 * @brief   Receives data via the I2C bus as master.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 * @param[in] addr      slave device address
 * @param[out] rxbuf    pointer to the receive buffer
 * @param[in] rxbytes   number of bytes to be received
 * @param[in] timeout   the number of ticks before the operation timeouts,
 *                      the following special values are allowed:
 *                      - @a TIME_INFINITE no timeout.
 *                      .
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    if one or more I2C errors occurred, the errors can
 *                      be retrieved using @p i2cGetErrors().
 * @retval MSG_TIMEOUT  if a timeout occurred before operation end. <b>After a
 *                      timeout the driver must be stopped and restarted
 *                      because the bus is in an uncertain state</b>.
 *
 * @notapi
 */
msg_t i2c_lld_master_receive_timeout(I2CDriver *i2cp, i2caddr_t addr,
                                     uint8_t *rxbuf, size_t rxbytes,
                                     sysinterval_t timeout) {

  systime_t start, end;

  /* Resetting error flags for this transfer.*/
  i2cp->errors = I2C_NO_ERROR;

  /* Initializes driver fields, LSB = 1 -> receive.*/
  i2cp->addr = (addr << 1) | 0x01;

  /* Releases the lock from high level driver.*/
  osalSysUnlock();

  /* Calculating the time window for the timeout on the busy bus condition.*/
  start = osalOsGetSystemTimeX();
  end = osalTimeAddX(start, OSAL_MS2I(SN32_I2C_BUSY_TIMEOUT));

  /* Waits for a timeout condition.*/
  while (true) {
    osalSysLock();

    /* If the system time went outside the allowed window then a timeout
       condition is returned.*/
    if (!osalTimeIsInRangeX(osalOsGetSystemTimeX(), start, end))
      return MSG_TIMEOUT;

    osalSysUnlock();
  }
  i2cp->rx_buffer = rxbuf;
  i2cp->rx_len = rxbytes;
  i2cp->count = 0;
  i2cp->i2c->CTRL_b.STA = true;
  i2cp->i2c->TXDATA = addr;

  /* Waits for the operation completion or a timeout.*/
  return osalThreadSuspendTimeoutS(&i2cp->thread, timeout);

}

/**
 * @brief   Transmits data via the I2C bus as master.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 * @param[in] addr      slave device address
 * @param[in] txbuf     pointer to the transmit buffer
 * @param[in] txbytes   number of bytes to be transmitted
 * @param[out] rxbuf    pointer to the receive buffer
 * @param[in] rxbytes   number of bytes to be received
 * @param[in] timeout   the number of ticks before the operation timeouts,
 *                      the following special values are allowed:
 *                      - @a TIME_INFINITE no timeout.
 *                      .
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    if one or more I2C errors occurred, the errors can
 *                      be retrieved using @p i2cGetErrors().
 * @retval MSG_TIMEOUT  if a timeout occurred before operation end. <b>After a
 *                      timeout the driver must be stopped and restarted
 *                      because the bus is in an uncertain state</b>.
 *
 * @notapi
 */
msg_t i2c_lld_master_transmit_timeout(I2CDriver *i2cp, i2caddr_t addr,
                                      const uint8_t *txbuf, size_t txbytes,
                                      uint8_t *rxbuf, size_t rxbytes,
                                      sysinterval_t timeout) {

  systime_t start, end;
  
  /* Resetting error flags for this transfer.*/
  i2cp->errors = I2C_NO_ERROR;

  /* Initializes driver fields, LSB = 0 -> transmit.*/
  i2cp->addr = (addr << 1);

  /* Releases the lock from high level driver.*/
  osalSysUnlock();

  /* Calculating the time window for the timeout on the busy bus condition.*/
  start = osalOsGetSystemTimeX();
  end = osalTimeAddX(start, OSAL_MS2I(SN32_I2C_BUSY_TIMEOUT));

  /* Waits for a timeout condition.*/
  while (true) {
    osalSysLock();

    /* If the system time went outside the allowed window then a timeout
       condition is returned.*/
    if (!osalTimeIsInRangeX(osalOsGetSystemTimeX(), start, end))
      return MSG_TIMEOUT;

    osalSysUnlock();
  }
  i2cp->tx_buffer = txbuf;
  i2cp->tx_len = txbytes;
  i2cp->count = 0;
  i2cp->i2c->CTRL_b.STA = true;
  i2cp->i2c->TXDATA = addr;

  /* Waits for the operation completion or a timeout.*/
  return osalThreadSuspendTimeoutS(&i2cp->thread, timeout);
}

#if (I2C_SUPPORTS_SLAVE_MODE == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   Listen I2C bus for address match.
 * @details Use 7 bit address (10 bit,dual and general call address dosn't implement yet) .
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 * @param[in] addr      slave device address
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    if one or more I2C errors occurred, the errors can
 *                      be retrieved using @p i2cGetErrors().
 *
 * @notapi
 */
msg_t i2c_lld_match_address(I2CDriver *i2cp, i2caddr_t addr) {

  uint16_t i2cadr = addr << 1;
  uint16_t ownAdr = i2cp->i2c->SLVADRR0 & (0x7f<<1);

  if (ownAdr == 0 || ownAdr == i2cadr)
    i2cp->i2c->SLVADRR0 = i2cadr;
  else
  /* cannot add this address to set of those matched */
    return MSG_RESET;

  return MSG_OK;

}

/**
 * @brief   Receive data via the I2C bus as slave and call handler.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 * @param[out] rxbuf    pointer to the receive buffer
 * @param[in] rxbytes   size of receive buffer
 * @param[in] timeout   the number of ticks before the operation timeouts,
 *                      the following special values are allowed:
 *                      - @a TIME_INFINITE no timeout.
 *                      .
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    if one or more I2C errors occurred, the errors can
 *                      be retrieved using @p i2cGetErrors().
 * @retval MSG_TIMEOUT  if a timeout occurred before operation end. <b>After a
 *                      timeout the driver must be stopped and restarted
 *                      because the bus is in an uncertain state</b>.
 *
 * @api
 */
msg_t i2c_lld_slave_receive_timeout(I2CDriver *i2cp,
                             uint8_t *rxbuf,
                             size_t rxbytes,
                             sysinterval_t timeout) {
  i2cp->rx_buffer = rxbuf;
  i2cp->rx_len = rxbytes;
  i2cp->count = 0;

  /* Waits for the operation completion or a timeout.*/
  return osalThreadSuspendTimeoutS(&i2cp->thread, timeout);
}

/**
 * @brief   Transmits data via the I2C bus as slave.
 * @details Call this function when Master request data (in request handler)
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 * @param[in] txbuf     pointer to the transmit buffer
 * @param[in] txbytes   number of bytes to be transmitted
 * @param[in] timeout   the number of ticks before the operation timeouts,
 *                      the following special values are allowed:
 *                      - @a TIME_INFINITE no timeout.
 *                      .
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    if one or more I2C errors occurred, the errors can
 *                      be retrieved using @p i2cGetErrors().
 * @retval MSG_TIMEOUT  if a timeout occurred before operation end. <b>After a
 *                      timeout the driver must be stopped and restarted
 *                      because the bus is in an uncertain state</b>.
 *
 * @api
 */
msg_t i2c_lld_slave_transmit_timeout(I2CDriver *i2cp,
                               const uint8_t *txbuf,
                               size_t txbytes,
                               sysinterval_t timeout) {
  i2cp->tx_buffer = txbuf;
  i2cp->tx_len = txbytes;
  i2cp->count = 0;

  /* Waits for the operation completion or a timeout.*/
  return osalThreadSuspendTimeoutS(&i2cp->thread, timeout);
}
#endif /* I2C_SUPPORTS_SLAVE_MODE == TRUE */
#endif /* HAL_USE_I2C == TRUE */

/** @} */


