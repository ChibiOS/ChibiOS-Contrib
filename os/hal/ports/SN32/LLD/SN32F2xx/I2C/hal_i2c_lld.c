/*
    Copyright (C) 2023 1Conan
    Copyright (C) 2024 Dimitris Mantzouranis

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

/**
 * @brief   I2C1 driver identifier.
 */
#if (SN32_I2C_USE_I2C1 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD1;
#endif


/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/
#define I2C_CLK                          SN32_HCLK
/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline void i2c_lld_configure(I2CDriver *i2cp) {
  I2C_TypeDef *dp = i2cp->i2c;

  i2copmode_t opmode = i2cp->config->op_mode;

  switch (opmode) {
    case OPMODE_I2C:
      break;
    case OPMODE_SMBUS_DEVICE:
      osalDbgAssert(false, "SMBUS_DEVICE mode is not supported");
      break;
    case OPMODE_SMBUS_HOST:
      osalDbgAssert(false, "SMBUS_HOST mode is not supported");
      break;
  }

  float tclk, tval;
  int32_t clock_speed = i2cp->config->clock_speed;

  osalDbgCheck((i2cp != NULL) &&
               (clock_speed > 0) &&
               (clock_speed <= 400000));

  tclk = (float)1000000 / (clock_speed << 1);
  tval = (float)I2C_CLK / 1000000 * tclk;

  dp->SCLHT = (uint32_t)(tval -1);
  dp->SCLLT = (uint32_t)(tval -1);
  if(i2cp->config->timeout > 0) {
  // Convert timeout in milliseconds to system ticks
  sysinterval_t timeout_ticks = TIME_MS2I(i2cp->config->timeout);
  uint32_t timeout_cycles = (uint32_t)(timeout_ticks * 32 * I2C_CLK / CH_CFG_ST_FREQUENCY);

  osalDbgCheck(timeout_cycles <= 0xFFFF);
  dp->TOCTRL = (uint16_t)timeout_cycles;
  }
}

static inline void i2c_lld_handle_error(I2CDriver *i2cp, uint32_t error_flag) {
  i2cp->errors |= error_flag;
  _i2c_wakeup_error_isr(i2cp);
  i2cp->i2c->STAT_b.I2CIF = true;
}

static inline void i2c_lld_handle_success(I2CDriver *i2cp) {
  _i2c_wakeup_isr(i2cp);
  i2cp->i2c->STAT_b.I2CIF = true;
}

static inline void i2c_lld_irq_handler(I2CDriver * i2cp) {
  I2C_TypeDef *dp = i2cp->i2c;
  uint32_t status = dp->STAT;
  bool master = (status & mskI2C_MASTER_STATUS);

  if (status & mskI2C_I2C_TIMEOUT) {
    i2c_lld_handle_error(i2cp, I2C_TIMEOUT);
    return;
  }
  if (status & mskI2C_LOST_ARB) {
    i2c_lld_handle_error(i2cp, I2C_ARBITRATION_LOST);
    return;
  }
  if (status & mskI2C_STOP_DONE) {
    // stop received
    i2c_lld_handle_success(i2cp);
    return;
  }
  if (master && (status & mskI2C_START_DONE)) {
    // set slave address.
    dp->TXDATA = i2cp->addr;
    dp->STAT_b.I2CIF |= true;
    return;
  }
  // TX
  if (i2cp->state == I2C_ACTIVE_TX) {
    if (status & (mskI2C_ACK_DONE | mskI2C_SLAVE_TX_MATCH)) {
      if (i2cp->tx_buffer && i2cp->count < i2cp->tx_len) {
        dp->TXDATA = i2cp->tx_buffer[i2cp->count++];
        dp->STAT_b.I2CIF |= true;
      }

      else if (i2cp->count == i2cp->tx_len) {
        // All data sent — end transaction
        dp->CTRL_b.STO = true;
        i2c_lld_handle_success(i2cp);
      }

    } else if (status & mskI2C_NACK_DONE) {
      if (!master) {
        // Slave was NACKed — treat as completed
        dp->CTRL_b.ACK = true;
        i2c_lld_handle_success(i2cp);
      } else if (i2cp->count == i2cp->tx_len) {
        dp->CTRL_b.STO = true;
        i2c_lld_handle_success(i2cp);
      } else {
        dp->CTRL_b.STO = true;
        i2c_lld_handle_error(i2cp, I2C_ACK_FAILURE);
      }

    } else {
      dp->CTRL_b.STO = true;
      i2c_lld_handle_error(i2cp, I2C_BUS_ERROR);
    }
  }
  // RX
  else if (i2cp->state == I2C_ACTIVE_RX) {
    if ((status & mskI2C_ACK_DONE) || (status & mskI2C_SLAVE_RX_MATCH)) {
      // ACK to continue reception
      if (i2cp->count < i2cp->rx_len) {
        dp->CTRL_b.ACK = true;
      } else {
        i2c_lld_handle_error(i2cp, I2C_OVERRUN);
        return;
      }
      dp->STAT_b.I2CIF = true;
      return;
    }

    if (status & mskI2C_RX_DONE) {
      if (!i2cp->rx_buffer || i2cp->count >= i2cp->rx_len) {
        // Buffer full or invalid
        i2c_lld_handle_error(i2cp, I2C_OVERRUN);
        return;
      }

      // Receive byte
      i2cp->rx_buffer[i2cp->count++] = dp->RXDATA;

      if (i2cp->count == i2cp->rx_len) {
        if (master) dp->CTRL_b.STO = true;
        i2c_lld_handle_success(i2cp);
      } else dp->STAT_b.I2CIF = true;
    } else {
      dp->CTRL_b.STO = true;
      i2c_lld_handle_error(i2cp, I2C_BUS_ERROR);
    }
  }
  // UNINIT, STOP, READY, LOCKED
  else {
    dp->CTRL_b.STO = true;
    i2c_lld_handle_error(i2cp, I2C_BUS_ERROR);
  }
}
/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if SN32_I2C_USE_I2C0 || defined(__DOXYGEN__)
OSAL_IRQ_HANDLER(SN32_I2C0_GLOBAL_HANDLER) {
  OSAL_IRQ_PROLOGUE();

  i2c_lld_irq_handler(&I2CD0);

  OSAL_IRQ_EPILOGUE();
}
#endif /* SN32_I2C_USE_I2C0 */

#if SN32_I2C_USE_I2C1 || defined(__DOXYGEN__)
OSAL_IRQ_HANDLER(SN32_I2C1_GLOBAL_HANDLER) {
  OSAL_IRQ_PROLOGUE();

  i2c_lld_irq_handler(&I2CD1);

  OSAL_IRQ_EPILOGUE();
}
#endif /* SN32_I2C_USE_I2C1 */

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
  I2CD0.rx_buffer = NULL;
  I2CD0.tx_buffer = NULL;
  I2CD0.rx_len = 0;
  I2CD0.tx_len = 0;
#endif /* SN32_I2C_USE_I2C0 */

#if SN32_I2C_USE_I2C1 == TRUE
  i2cObjectInit(&I2CD1);
  I2CD1.thread  = NULL;
  I2CD1.i2c = SN32_I2C1;
  I2CD1.rx_buffer = NULL;
  I2CD1.tx_buffer = NULL;
  I2CD1.rx_len = 0;
  I2CD1.tx_len = 0;
#endif /* SN32_I2C_USE_I2C1 */
}

/**
 * @brief   Configures and activates the I2C peripheral.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
void i2c_lld_start(I2CDriver *i2cp) {
  I2C_TypeDef *dp = i2cp->i2c;

  if (i2cp->state == I2C_STOP) {
    /* Enables the peripheral.*/
#if SN32_I2C_USE_I2C0 == TRUE
    if (&I2CD0 == i2cp) {
      sys1EnableI2C0();
      nvicClearPending(SN32_I2C0_GLOBAL_NUMBER);
      nvicEnableVector(SN32_I2C0_GLOBAL_NUMBER, SN32_I2C_I2C0_IRQ_PRIORITY);
    }
#endif /* SN32_I2C_USE_I2C0 */

#if SN32_I2C_USE_I2C1 == TRUE
    if (&I2CD1 == i2cp) {
      sys1EnableI2C1();
      nvicClearPending(SN32_I2C1_GLOBAL_NUMBER);
      nvicEnableVector(SN32_I2C1_GLOBAL_NUMBER, SN32_I2C_I2C1_IRQ_PRIORITY);
    }
#endif /* SN32_I2C_USE_I2C1 */
  }

  i2c_lld_configure(i2cp);
  dp->CTRL_b.I2CEN = true;
}

/**
 * @brief   Deactivates the I2C peripheral.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
void i2c_lld_stop(I2CDriver *i2cp) {
  I2C_TypeDef *dp = i2cp->i2c;

  if (i2cp->state != I2C_STOP) {

    dp->CTRL_b.I2CEN = false;
    i2cp->rx_buffer = NULL;
    i2cp->tx_buffer = NULL;
    i2cp->rx_len = 0;
    i2cp->tx_len = 0;

    /* Disables the peripheral.*/
#if SN32_I2C_USE_I2C0 == TRUE
    if (&I2CD0 == i2cp) {
      sys1DisableI2C0();
      nvicDisableVector(SN32_I2C0_GLOBAL_NUMBER);
    }
#endif /* SN32_I2C_USE_I2C0 */

#if SN32_I2C_USE_I2C1 == TRUE
    if (&I2CD1 == i2cp) {
      sys1DisableI2C1();
      nvicDisableVector(SN32_I2C1_GLOBAL_NUMBER);
    }
#endif /* SN32_I2C_USE_I2C1 */
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
  I2C_TypeDef *dp = i2cp->i2c;
  msg_t msg;

  /* Resetting error flags for this transfer.*/
  i2cp->errors = I2C_NO_ERROR;

  /* Initializes driver fields, LSB = 1 -> receive.*/
  i2cp->addr = (addr << 1) | 0x01;

  /* Get the buffer from the peripheral */
  rxbuf = i2cp->rx_buffer;
  rxbytes = i2cp->rx_len;
  i2cp->count = 0;

  /* Starts the operation.*/
  dp->CTRL_b.STA = true;

  /* Waits for the operation completion or a timeout.*/
  msg = osalThreadSuspendTimeoutS(&i2cp->thread, timeout);
  if (msg != MSG_OK) {
    i2cp->rx_buffer = NULL;
    i2cp->rx_len = 0;
  }

  return msg;
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
  I2C_TypeDef *dp = i2cp->i2c;
  msg_t msg;

  /* Resetting error flags for this transfer.*/
  i2cp->errors = I2C_NO_ERROR;

  /* Initializes driver fields, LSB = 0 -> transmit.*/
  i2cp->addr = (addr << 1);

  /* Pass the buffer to the peripheral */
  i2cp->tx_buffer = txbuf;
  i2cp->tx_len = txbytes;
  i2cp->count = 0;

  /* Starts the operation.*/
  dp->CTRL_b.STA = true;

  /* Waits for the operation completion or a timeout.*/
  msg = osalThreadSuspendTimeoutS(&i2cp->thread, timeout);

  if (msg != MSG_OK) {
    i2cp->tx_buffer = NULL;
    i2cp->tx_len = 0;
  }

  return msg;
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

  I2C_TypeDef *dp = i2cp->i2c;
  uint16_t i2cadr = addr << 1;
  uint16_t ownAdr = dp->SLVADDR0 & (0x7f<<1);

  if (ownAdr == 0 || ownAdr == i2cadr)
    dp->SLVADDR0 = i2cadr;
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
  I2C_TypeDef *dp = i2cp->i2c;
  msg_t msg;

  /* Resetting error flags for this transfer.*/
  i2cp->errors = I2C_NO_ERROR;

  /* Get the buffer from the peripheral */
  rxbuf = i2cp->rx_buffer;
  rxbytes = i2cp->rx_len;
  i2cp->count = 0;

  /* Starts the operation.*/
  dp->CTRL_b.STA = true;

  /* Waits for the operation completion or a timeout.*/
  msg = osalThreadSuspendTimeoutS(&i2cp->thread, timeout);
  if (msg != MSG_OK) {
    i2cp->rx_buffer = NULL;
    i2cp->rx_len = 0;
  }

  return msg;
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
  I2C_TypeDef *dp = i2cp->i2c;
  msg_t msg;

  /* Resetting error flags for this transfer.*/
  i2cp->errors = I2C_NO_ERROR;

  /* Pass the buffer to the peripheral */
  i2cp->tx_buffer = txbuf;
  i2cp->tx_len = txbytes;
  i2cp->count = 0;

  /* Starts the operation.*/
  dp->CTRL_b.STA = true;

  /* Waits for the operation completion or a timeout.*/
  msg = osalThreadSuspendTimeoutS(&i2cp->thread, timeout);

  if (msg != MSG_OK) {
    i2cp->tx_buffer = NULL;
    i2cp->tx_len = 0;
  }

  return msg;
}
#endif /* I2C_SUPPORTS_SLAVE_MODE == TRUE */
#endif /* HAL_USE_I2C == TRUE */

/** @} */


