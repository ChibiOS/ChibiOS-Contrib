/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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
 * @file    common/I2C/hal_i2c_lld.c
 * @brief   SW I2C subsystem low level driver source.
 *
 * @addtogroup I2C
 * @{
 */

#include "hal.h"

#if HAL_USE_I2C || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/
#if (SW_I2C_USE_OPENDRAIN == TRUE) || defined(__DOXYGEN__)
#  define CHECK_ERROR(msg)                                                    \
    if ((msg) < (msg_t)0) {                                                   \
      palSetLine(i2cp->config->sda);                                          \
      palSetLine(i2cp->config->scl);                                          \
      return MSG_TIMEOUT;                                                     \
    }
#else
#  define CHECK_ERROR(msg)                                                    \
    if ((msg) < (msg_t)0) {                                                   \
      palSetLineMode(i2cp->config->scl, PAL_MODE_OUTPUT_PUSHPULL);            \
      palSetLineMode(i2cp->config->sda, PAL_MODE_OUTPUT_PUSHPULL);            \
      palSetLine(i2cp->config->sda);                                          \
      palSetLine(i2cp->config->scl);                                          \
      return MSG_TIMEOUT;                                                     \
    }
#endif

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief I2C1 driver identifier.*/
#if SW_I2C_USE_I2C1 || defined(__DOXYGEN__)
I2CDriver I2CD1;
#endif

/** @brief I2C2 driver identifier.*/
#if SW_I2C_USE_I2C2 || defined(__DOXYGEN__)
I2CDriver I2CD2;
#endif

/** @brief I2C3 driver identifier.*/
#if SW_I2C_USE_I2C3 || defined(__DOXYGEN__)
I2CDriver I2CD3;
#endif

/** @brief I2C4 driver identifier.*/
#if SW_I2C_USE_I2C4 || defined(__DOXYGEN__)
I2CDriver I2CD4;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static msg_t i2c_write_stop(I2CDriver *i2cp);

static inline void i2c_delay(I2CDriver *i2cp) {

#if SW_I2C_USE_OSAL_DELAY || defined(__DOXYGEN__)
  osalThreadSleepS(i2cp->config->ticks);
#else
  i2cp->config->delay();
#endif
}

static inline msg_t i2c_check_arbitration(I2CDriver *i2cp) {
#if (SW_I2C_USE_OPENDRAIN == FALSE)
  palSetLineMode(i2cp->config->sda, PAL_MODE_INPUT);
#endif
  i2c_delay(i2cp);
  if (palReadLine(i2cp->config->sda) == PAL_LOW) {
    i2cp->errors |= I2C_ARBITRATION_LOST;
    return MSG_RESET;
  }
#if (SW_I2C_USE_OPENDRAIN == FALSE)
  palSetLineMode(i2cp->config->sda, PAL_MODE_OUTPUT_PUSHPULL);
#endif
  return MSG_OK;
}

static inline msg_t i2c_check_timeout(I2CDriver *i2cp) {

  if ((i2cp->start != i2cp->end) &&
      (!osalTimeIsInRangeX(osalOsGetSystemTimeX(), i2cp->start, i2cp->end))) {
    i2c_write_stop(i2cp);
    return MSG_TIMEOUT;
  }

  return MSG_OK;
}

static msg_t i2c_wait_clock(I2CDriver *i2cp) {
#if (SW_I2C_USE_OPENDRAIN == FALSE)
  palSetLineMode(i2cp->config->scl, PAL_MODE_INPUT);
#endif
  i2c_delay(i2cp);

  while (palReadLine(i2cp->config->scl) == PAL_LOW) {
    if ((i2cp->start != i2cp->end) &&
        (!osalTimeIsInRangeX(osalOsGetSystemTimeX(), i2cp->start, i2cp->end))) {
      return MSG_TIMEOUT;
    }
    i2c_delay(i2cp);
  }
#if (SW_I2C_USE_OPENDRAIN == FALSE)
  palSetLineMode(i2cp->config->scl, PAL_MODE_OUTPUT_PUSHPULL);
#endif
  return MSG_OK;
}

static inline msg_t i2c_write_start(I2CDriver *i2cp) {

  /* Arbitration check.*/
  CHECK_ERROR(i2c_check_arbitration(i2cp));

  palClearLine(i2cp->config->sda);
  i2c_delay(i2cp);
  palClearLine(i2cp->config->scl);
  i2c_delay(i2cp);

  return MSG_OK;
}

static msg_t i2c_write_restart(I2CDriver *i2cp) {

  palSetLine(i2cp->config->sda);
  i2c_delay(i2cp);
  palSetLine(i2cp->config->scl);

  /* Clock stretching.*/
  CHECK_ERROR(i2c_wait_clock(i2cp));

  i2c_delay(i2cp);
  i2c_write_start(i2cp);

  return MSG_OK;
}

static msg_t i2c_write_stop(I2CDriver *i2cp) {

  palClearLine(i2cp->config->sda);
  i2c_delay(i2cp);
  palSetLine(i2cp->config->scl);

  /* Clock stretching.*/
  CHECK_ERROR(i2c_wait_clock(i2cp));

  i2c_delay(i2cp);
  palSetLine(i2cp->config->sda);
  i2c_delay(i2cp);

  /* Arbitration check.*/
  CHECK_ERROR(i2c_check_arbitration(i2cp));

  i2c_delay(i2cp);

  return MSG_OK;
}

static msg_t i2c_write_bit(I2CDriver *i2cp, unsigned bit) {

  palWriteLine(i2cp->config->sda, bit);

  i2c_delay(i2cp);
  palSetLine(i2cp->config->scl);
  i2c_delay(i2cp);

  /* Clock stretching.*/
  CHECK_ERROR(i2c_wait_clock(i2cp));

  /* Arbitration check.*/
  if (bit == PAL_HIGH) {
    CHECK_ERROR(i2c_check_arbitration(i2cp));
  }

  palClearLine(i2cp->config->scl);
  i2c_delay(i2cp);

  return MSG_OK;
}

static msg_t i2c_read_bit(I2CDriver *i2cp) {
  msg_t bit;
#if (SW_I2C_USE_OPENDRAIN == FALSE)
  palSetLineMode(i2cp->config->sda, PAL_MODE_INPUT);
#endif
  i2c_delay(i2cp);
  palSetLine(i2cp->config->scl);

  /* Clock stretching.*/
  CHECK_ERROR(i2c_wait_clock(i2cp));

  i2c_delay(i2cp);

  bit = palReadLine(i2cp->config->sda);
#if (SW_I2C_USE_OPENDRAIN == FALSE)
  palSetLineMode(i2cp->config->sda, PAL_MODE_OUTPUT_PUSHPULL);
#endif
  palClearLine(i2cp->config->scl);
  i2c_delay(i2cp);

  return bit;
}

static msg_t i2c_write_byte(I2CDriver *i2cp, uint8_t byte) {
  msg_t msg;

  CHECK_ERROR(i2c_check_timeout(i2cp));

#if (SW_I2C_USE_OPENDRAIN == TRUE) || defined(__DOXYGEN__)
  uint8_t mask;
  for (mask = 0x80U; mask > 0U; mask >>= 1U) {
    CHECK_ERROR(i2c_write_bit(i2cp, (byte & mask) != 0));
  }
#else
  for(uint8_t i = 0; i < 8; i++) {
    unsigned bit = ((0x80U >> i) & byte);
    CHECK_ERROR(i2c_write_bit(i2cp, bit));
  }
#endif
  msg = i2c_read_bit(i2cp);
  CHECK_ERROR(msg);

  /* Checking for NACK.*/
  if (msg == PAL_HIGH) {
    i2cp->errors |= I2C_ACK_FAILURE;
    return MSG_RESET;
  }

  return MSG_OK;
}

static msg_t i2c_read_byte(I2CDriver *i2cp, unsigned nack) {
  msg_t byte;
  unsigned i;

  CHECK_ERROR(i2c_check_timeout(i2cp));

  byte = 0U;
  for (i = 0; i < 8; i++) {
    msg_t msg = i2c_read_bit(i2cp);
    CHECK_ERROR(msg);
    byte = (byte << 1U) | msg;
  }

  CHECK_ERROR(i2c_write_bit(i2cp, nack));

  return byte;
}

static msg_t i2c_write_header(I2CDriver *i2cp, i2caddr_t addr, bool rw) {

  /* Check for 10 bits addressing.*/
  if (i2cp->config->addr10) {
    /* It is 10 bits.*/
    uint8_t b1, b2;

    b1 = 0xF0U | ((addr >> 8U) << 1U);
    b2 = (uint8_t)(addr & 255U);
    if (rw) {
      b1 |= 1U;
    }
    CHECK_ERROR(i2c_write_byte(i2cp, b1));
    CHECK_ERROR(i2c_write_byte(i2cp, b2));
  }
  else {
    /* It is 7 bits.*/
    if (rw) {
      /* Read.*/
      CHECK_ERROR(i2c_write_byte(i2cp, (addr << 1U) | 1U));
    }
    else {
      /* Write.*/
      CHECK_ERROR(i2c_write_byte(i2cp, (addr << 1U) | 0U));
    }
  }

  return MSG_OK;
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level I2C driver initialization.
 *
 * @notapi
 */
void i2c_lld_init(void) {

#if SW_I2C_USE_I2C1
  i2cObjectInit(&I2CD1);
#endif
#if SW_I2C_USE_I2C2
  i2cObjectInit(&I2CD2);
#endif
#if SW_I2C_USE_I2C3
  i2cObjectInit(&I2CD3);
#endif
#if SW_I2C_USE_I2C4
  i2cObjectInit(&I2CD4);
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

  /* Does nothing.*/
  (void)i2cp;
}

/**
 * @brief   Deactivates the I2C peripheral.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
void i2c_lld_stop(I2CDriver *i2cp) {

  /* Does nothing.*/
  (void)i2cp;
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

  /* Setting timeout fields.*/
  i2cp->start = osalOsGetSystemTimeX();
  i2cp->end = i2cp->start;
  if (timeout != TIME_INFINITE) {
    i2cp->end = osalTimeAddX(i2cp->start, timeout);
  }

  CHECK_ERROR(i2c_write_start(i2cp));

  /* Sending address and mode.*/
  CHECK_ERROR(i2c_write_header(i2cp, addr, true));

  do {
    /* Last byte sends a NACK.*/
    msg_t msg = i2c_read_byte(i2cp, rxbytes > 1U ? 0U : 1U);
    CHECK_ERROR(msg);
    *rxbuf++ = (uint8_t)msg;
  } while (--rxbytes);

  return i2c_write_stop(i2cp);
}

/**
 * @brief   Transmits data via the I2C bus as master.
 * @details Number of receiving bytes must be 0 or more than 1 on STM32F1x.
 *          This is hardware restriction.
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

  /* Setting timeout fields.*/
  i2cp->start = osalOsGetSystemTimeX();
  i2cp->end = i2cp->start;
  if (timeout != TIME_INFINITE) {
    i2cp->end = osalTimeAddX(i2cp->start, timeout);
  }

  /* Sending start condition.*/
  CHECK_ERROR(i2c_write_start(i2cp));

  /* Sending address and mode.*/
  CHECK_ERROR(i2c_write_header(i2cp, addr, false));

  do {
    CHECK_ERROR(i2c_write_byte(i2cp, *txbuf++));
  } while (--txbytes);

  /* Is there a read phase? */
  if (rxbytes > 0U) {

    /* Sending restart condition.*/
    CHECK_ERROR(i2c_write_restart(i2cp));
    /* Sending address and mode.*/
    CHECK_ERROR(i2c_write_header(i2cp, addr, true));

    do {
      /* Last byte sends a NACK.*/
      msg_t msg = i2c_read_byte(i2cp, rxbytes > 1U ? 0U : 1U);
      CHECK_ERROR(msg);
      *rxbuf++ = (uint8_t)msg;
    } while (--rxbytes);
  }

  return i2c_write_stop(i2cp);
}

#endif /* HAL_USE_I2C */

/** @} */
