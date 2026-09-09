/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    Copyright (C) 2026 QMK

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
 * @file    SK32F0xx/hal_i2c_lld.c
 * @brief   SK32F0xx low level I2C driver code.
 * @details The SK32F0xx I2C is a legacy CR1/CR2/SR1/SR2/DR/CCR unit (the
 *          register set of the STM32F1 I2C minus the TRISE register) served
 *          by a single interrupt vector.  Transfers are driven byte by byte
 *          by the event (SB/ADDR/BTF) and buffer (TXE/RXNE) interrupts, the
 *          STM32 EV/ER IRQ split and the DMA are not used.
 *
 *          The I2C1 input clock is not software selectable (the SK32 CFGR3
 *          has no I2C1SW bits) and is analyzed as the 8MHz HSI; the CCR/FREQ
 *          programming is based on this frequency and must be verified on
 *          the actual silicon.
 *
 * @addtogroup I2C
 * @{
 */

#include "hal.h"

#if HAL_USE_I2C || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   Interrupt enable bits of CR2, owned by this driver.
 */
#define SK32_I2C_CR2_IE_MASK    ((uint16_t)(I2C_CR2_ITERREN |               \
                                            I2C_CR2_ITEVTEN |               \
                                            I2C_CR2_ITBUFEN))

/**
 * @brief   Error condition flags of SR1 monitored by this driver.
 */
#define SK32_I2C_SR1_ERRORS     ((uint16_t)(I2C_SR1_BERR |                  \
                                            I2C_SR1_ARLO |                  \
                                            I2C_SR1_AF   |                  \
                                            I2C_SR1_OVR))

/**
 * @brief   I2C peripheral input clock (analyzed as the 8MHz HSI).
 */
#define SK32_I2C_CLK            ((uint32_t)SK32_HSICLK)

/**
 * @brief   I2C peripheral clock expressed in MHz (CR2 FREQ field).
 */
#define SK32_I2C_FREQ           ((uint16_t)(SK32_HSICLK / 1000000U))

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief I2C1 driver identifier.*/
#if SK32_I2C_USE_I2C1 || defined(__DOXYGEN__)
I2CDriver I2CD1;
#endif

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Resets the I2C peripheral to its disabled state.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
static void i2c_lld_abort_operation(I2CDriver *i2cp) {
  I2C_TypeDef *dp = i2cp->i2c;

  /* Stops the I2C peripheral and clears all the flags.*/
  dp->CR1 = I2C_CR1_SWRST;
  dp->CR1 = 0U;
  dp->CR2 = 0U;
  dp->SR1 = 0U;
}

/**
 * @brief   Programs the CCR register and the CR2 FREQ field.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
static void i2c_lld_set_clock(I2CDriver *i2cp) {
  I2C_TypeDef *dp = i2cp->i2c;
  uint32_t clock_speed = i2cp->config->clock_speed;
  i2cdutycycle_t duty = i2cp->config->duty_cycle;
  uint32_t ccr;

  osalDbgCheck((i2cp != NULL) &&
               (clock_speed > 0U) &&
               (clock_speed <= 400000U));

  /* CR2 FREQ[5:0] = peripheral input clock in MHz.*/
  dp->CR2 &= (uint16_t)~I2C_CR2_FREQ;
  dp->CR2 |= SK32_I2C_FREQ;

  /* CCR programming, standard mode uses a 1/1 duty cycle while the fast
     mode uses the 2/1 or the 16/9 duty cycle selected in the config.*/
  if (clock_speed <= 100000U) {
    osalDbgAssert(duty == STD_DUTY_CYCLE, "invalid standard mode duty cycle");

    /* Standard mode CCR: Tlow/Thigh = 1/1.*/
    ccr = SK32_I2C_CLK / (clock_speed * 2U);
    osalDbgAssert(ccr >= 0x04U,
                  "clock divider less than 0x04 not allowed");
    dp->CCR = (uint16_t)ccr;
  }
  else {
    osalDbgAssert((duty == FAST_DUTY_CYCLE_2) ||
                  (duty == FAST_DUTY_CYCLE_16_9),
                  "invalid fast mode duty cycle");

    if (duty == FAST_DUTY_CYCLE_16_9) {
      /* Fast mode CCR with a 16/9 duty cycle.*/
      ccr = SK32_I2C_CLK / (clock_speed * 25U);
    }
    else {
      /* Fast mode CCR with a 2/1 duty cycle.*/
      ccr = SK32_I2C_CLK / (clock_speed * 3U);
    }

    osalDbgAssert(ccr >= 0x01U, "clock divider less than 0x01 not allowed");
    osalDbgAssert(ccr <= (uint32_t)I2C_CCR_CCR, "the selected clock is too low");

    if (duty == FAST_DUTY_CYCLE_16_9) {
      dp->CCR = (uint16_t)(I2C_CCR_FS | I2C_CCR_DUTY | (ccr & I2C_CCR_CCR));
    }
    else {
      dp->CCR = (uint16_t)(I2C_CCR_FS | (ccr & I2C_CCR_CCR));
    }
  }
}

/**
 * @brief   Programs the operation mode bits of CR1.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
static void i2c_lld_set_opmode(I2CDriver *i2cp) {
  I2C_TypeDef *dp = i2cp->i2c;
  uint16_t regCR1 = dp->CR1;

  switch (i2cp->config->op_mode) {
  case OPMODE_SMBUS_DEVICE:
    regCR1 |= I2C_CR1_SMBUS;
    regCR1 &= (uint16_t)~I2C_CR1_SMBTYPE;
    break;
  case OPMODE_SMBUS_HOST:
    regCR1 |= (uint16_t)(I2C_CR1_SMBUS | I2C_CR1_SMBTYPE);
    break;
  case OPMODE_I2C:
  default:
    regCR1 &= (uint16_t)~(I2C_CR1_SMBUS | I2C_CR1_SMBTYPE);
    break;
  }
  dp->CR1 = regCR1;
}

/**
 * @brief   Common error interrupt handling.
 * @note    Called with the transfer context active, the @p errors mask is
 *          filled and the waiting thread is resumed with @p MSG_RESET.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 * @param[in] sr1       content of the SR1 register (with the error bits)
 *
 * @notapi
 */
static void i2c_lld_serve_error_interrupt(I2CDriver *i2cp, uint16_t sr1) {
  I2C_TypeDef *dp = i2cp->i2c;

  i2cp->errors = I2C_NO_ERROR;

  if ((sr1 & I2C_SR1_BERR) != 0U) {
    i2cp->errors |= I2C_BUS_ERROR;
  }
  if ((sr1 & I2C_SR1_ARLO) != 0U) {
    i2cp->errors |= I2C_ARBITRATION_LOST;
  }
  if ((sr1 & I2C_SR1_AF) != 0U) {
    i2cp->errors |= I2C_ACK_FAILURE;
  }
  if ((sr1 & I2C_SR1_OVR) != 0U) {
    i2cp->errors |= I2C_OVERRUN;
  }

  /* Disables the interrupt sources, the transfer is over.*/
  dp->CR2 &= (uint16_t)~SK32_I2C_CR2_IE_MASK;

  /* An acknowledge failure leaves the lines in an undefined state while the
     master still owns the bus, a STOP releases them.  In case of a bus
     error or of an arbitration loss the bus is (or becomes) owned by some
     other master, generating a STOP would disturb it, so nothing is done.*/
  if ((sr1 & (I2C_SR1_AF | I2C_SR1_BERR)) != 0U) {
    dp->CR1 |= I2C_CR1_STOP;
  }

  /* Clears the error flags, they are cleared by writing zeros to them.*/
  dp->SR1 = (uint16_t)0U;

  SK32_I2C_ERROR_HOOK(i2cp);
  _i2c_wakeup_error_isr(i2cp);
}

/**
 * @brief   Common I2C interrupt handler.
 * @note    One event is served per invocation; the peripheral keeps the
 *          interrupt line asserted while a served condition (or a new one)
 *          remains pending, so the leftover flags generate a new interrupt
 *          as soon as this handler returns.  Reading SR1 followed by the
 *          appropriate register access is what clears each flag.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
static void i2c_lld_serve_interrupt(I2CDriver *i2cp) {
  I2C_TypeDef *dp = i2cp->i2c;
  uint16_t sr1 = dp->SR1;
  uint16_t sr2;

  /* Error conditions detection, the transfer is aborted.*/
  if ((sr1 & SK32_I2C_SR1_ERRORS) != 0U) {
    i2c_lld_serve_error_interrupt(i2cp, sr1);
    return;
  }

  /* EV5, start condition generated.  The address byte (with the R/W bit)
     is written to the data register, this also clears the SB flag.*/
  if ((sr1 & I2C_SR1_SB) != 0U) {
    dp->DR = i2cp->addr;
    return;
  }

  /* EV6, address sent.  Reading SR2 clears the ADDR flag.*/
  if ((sr1 & I2C_SR1_ADDR) != 0U) {
    sr2 = dp->SR2;

    if ((sr2 & I2C_SR2_TRA) != 0U) {
      /* Master transmitter: the first data byte is written here, right
         after the ADDR flag has been cleared.  A data byte written while
         the ADDR flag is still pending is ignored by the peripheral, so
         the first byte is never written on the TXE event.*/
      if ((i2cp->txbytes > 0U) && (i2cp->txidx < i2cp->txbytes)) {
        dp->DR = i2cp->txbuf[i2cp->txidx];
        i2cp->txidx++;
      }
    }
    else {
      /* Master receiver: the single data byte of a 1 byte read must be
         NACKed and followed by a STOP, both are programmed here.*/
      if (i2cp->rxbytes == 1U) {
        dp->CR1 &= (uint16_t)~I2C_CR1_ACK;
        dp->CR1 |= I2C_CR1_STOP;
      }
    }
    return;
  }

  /* EV7, data received.*/
  if (((sr1 & I2C_SR1_RXNE) != 0U) && (i2cp->rxphase != 0U)) {
    uint8_t b = (uint8_t)dp->DR;

    if (i2cp->rxidx < i2cp->rxbytes) {
      i2cp->rxbuf[i2cp->rxidx] = b;
    }
    i2cp->rxidx++;

    if (i2cp->rxidx >= i2cp->rxbytes) {
      /* Last data byte received, the STOP has already been programmed
         before its arrival (see below).*/
      dp->CR2 &= (uint16_t)~SK32_I2C_CR2_IE_MASK;
      _i2c_wakeup_isr(i2cp);
    }
    else if (i2cp->rxidx == (i2cp->rxbytes - 1U)) {
      /* The byte just read is the second to last: the last one must be
         NACKed and followed by a STOP.  The peripheral stretches SCL when
         it cannot proceed, so the programming below is in time for the
         9th clock of the next byte.*/
      dp->CR1 &= (uint16_t)~I2C_CR1_ACK;
      dp->CR1 |= I2C_CR1_STOP;
    }
    return;
  }

  /* EV8, data to be transmitted.*/
  if (((sr1 & I2C_SR1_TXE) != 0U) && (i2cp->rxphase == 0U) &&
      (i2cp->txidx < i2cp->txbytes)) {
    dp->DR = i2cp->txbuf[i2cp->txidx];
    i2cp->txidx++;
    return;
  }

  /* EV8_2, byte transfer finished (BTF).  In master transmitter mode it
     means that the last queued byte has been shifted out.*/
  if ((sr1 & I2C_SR1_BTF) != 0U) {
    if (i2cp->rxphase == 0U) {
      if (i2cp->txidx < i2cp->txbytes) {
        /* The peripheral is stretching the clock waiting for the next byte
           (the software did not keep the data register filled).*/
        dp->DR = i2cp->txbuf[i2cp->txidx];
        i2cp->txidx++;
        return;
      }

      if (i2cp->rxbytes > 0U) {
        /* Combined write-then-read transfer: a repeated START is generated
           and the address is sent again with the R/W bit set.*/
        i2cp->rxphase = true;
        i2cp->addr = (i2caddr_t)(i2cp->addr | 1U);
        dp->CR1 |= (uint16_t)(I2C_CR1_ACK | I2C_CR1_START);
        return;
      }

      /* Pure transmit: end of operation, a STOP is generated.*/
      dp->CR1 |= I2C_CR1_STOP;
      dp->CR2 &= (uint16_t)~SK32_I2C_CR2_IE_MASK;
      _i2c_wakeup_isr(i2cp);
    }
    return;
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if SK32_I2C_USE_I2C1 || defined(__DOXYGEN__)
#if !defined(SK32_I2C1_SUPPRESS_ISR)
#if !defined(SK32_I2C1_HANDLER)
#error "SK32_I2C1_HANDLER not defined"
#endif
/**
 * @brief   I2C1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SK32_I2C1_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  i2c_lld_serve_interrupt(&I2CD1);

  OSAL_IRQ_EPILOGUE();
}
#endif
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

#if SK32_I2C_USE_I2C1
  i2cObjectInit(&I2CD1);
  I2CD1.i2c = I2C1;
  I2CD1.thread = NULL;
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
  I2C_TypeDef *dp = i2cp->i2c;

  /* If in stopped state then enables the I2C clock and the interrupt
     vector.*/
  if (i2cp->state == I2C_STOP) {
#if SK32_I2C_USE_I2C1
    if (&I2CD1 == i2cp) {
      rccResetI2C1();
      rccEnableI2C1(true);
      nvicEnableVector(SK32_I2C1_NUMBER, SK32_I2C_I2C1_PRIORITY);
    }
#endif
  }

  /* Reset the peripheral to a known state.*/
  i2c_lld_abort_operation(i2cp);

  /* Setup the peripheral parameters and enable it, ACK is on by default
     so that multi-byte receptions are acknowledged until the last byte.*/
  i2c_lld_set_clock(i2cp);
  i2c_lld_set_opmode(i2cp);
  dp->CR1 = (uint16_t)(I2C_CR1_PE | I2C_CR1_ACK);
}

/**
 * @brief   Deactivates the I2C peripheral.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
void i2c_lld_stop(I2CDriver *i2cp) {

  /* If not in stopped state then disables the I2C clock.*/
  if (i2cp->state != I2C_STOP) {
    i2c_lld_abort_operation(i2cp);

#if SK32_I2C_USE_I2C1
    if (&I2CD1 == i2cp) {
      nvicDisableVector(SK32_I2C1_NUMBER);
      rccDisableI2C1();
    }
#endif
  }
}

/**
 * @brief   Receives data via the I2C bus as master.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 * @param[in] addr      slave device address (7 bits, no R/W bit)
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
 * @retval MSG_TIMEOUT  if a timeout occurred before operation end.  After a
 *                      timeout the driver must be stopped and restarted
 *                      because the bus is in an uncertain state.
 *
 * @notapi
 */
msg_t i2c_lld_master_receive_timeout(I2CDriver *i2cp, i2caddr_t addr,
                                     uint8_t *rxbuf, size_t rxbytes,
                                     sysinterval_t timeout) {
  I2C_TypeDef *dp = i2cp->i2c;
  systime_t start, end;
  msg_t msg;

  osalDbgCheck((i2cp != NULL) && (rxbuf != NULL) && (rxbytes > 0U));

  /* Initializes the driver fields, the LSB of the address selects the read
     direction.*/
  i2cp->errors = I2C_NO_ERROR;
  i2cp->addr = (i2caddr_t)((addr << 1) | 1U);
  i2cp->txbuf = NULL;
  i2cp->txbytes = 0U;
  i2cp->txidx = 0U;
  i2cp->rxbuf = rxbuf;
  i2cp->rxbytes = rxbytes;
  i2cp->rxidx = 0U;
  i2cp->rxphase = true;

  /* Releases the lock from the high level driver.*/
  osalSysUnlock();

  /* Calculating the time window for the timeout on the busy bus
     condition.*/
  start = osalOsGetSystemTimeX();
  end = osalTimeAddX(start, OSAL_MS2I(SK32_I2C_BUSY_TIMEOUT));

  /* Waits until the BUSY flag is reset and no STOP is pending or,
     alternatively, for a timeout condition.*/
  while (true) {
    osalSysLock();

    /* If the bus is not busy then the operation can continue, note, the
       loop is exited in the locked state.*/
    if (((dp->SR2 & I2C_SR2_BUSY) == 0U) && ((dp->CR1 & I2C_CR1_STOP) == 0U)) {
      break;
    }

    /* If the system time went outside the allowed window then a timeout
       condition is returned.*/
    if (!osalTimeIsInRangeX(osalOsGetSystemTimeX(), start, end)) {
      return MSG_TIMEOUT;
    }

    osalSysUnlock();
  }

  /* Starts the operation.*/
  dp->CR2 |= SK32_I2C_CR2_IE_MASK;
  dp->CR1 |= (uint16_t)(I2C_CR1_ACK | I2C_CR1_START);

  /* Waits for the operation completion or a timeout.*/
  msg = osalThreadSuspendTimeoutS(&i2cp->thread, timeout);

  /* In case of a software timeout the interrupt sources are disabled and a
     STOP is sent as an extreme attempt to release the bus.*/
  if (msg == MSG_TIMEOUT) {
    dp->CR2 &= (uint16_t)~SK32_I2C_CR2_IE_MASK;
    dp->CR1 |= I2C_CR1_STOP;
  }

  return msg;
}

/**
 * @brief   Transmits data via the I2C bus as master.
 * @details This function is also used for the "read-through-write" paradigm:
 *          if @p rxbytes is not zero a repeated START is generated after the
 *          last transmitted byte and @p rxbytes bytes are received from the
 *          same slave.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 * @param[in] addr      slave device address (7 bits, no R/W bit)
 * @param[in] txbuf     pointer to the transmit buffer
 * @param[in] txbytes   number of bytes to be transmitted
 * @param[out] rxbuf    pointer to the receive buffer
 * @param[in] rxbytes   number of bytes to be received, set it to 0 if you
 *                      want a transmit only operation
 * @param[in] timeout   the number of ticks before the operation timeouts,
 *                      the following special values are allowed:
 *                      - @a TIME_INFINITE no timeout.
 *                      .
 * @return              The operation status.
 * @retval MSG_OK       if the function succeeded.
 * @retval MSG_RESET    if one or more I2C errors occurred, the errors can
 *                      be retrieved using @p i2cGetErrors().
 * @retval MSG_TIMEOUT  if a timeout occurred before operation end.  After a
 *                      timeout the driver must be stopped and restarted
 *                      because the bus is in an uncertain state.
 *
 * @notapi
 */
msg_t i2c_lld_master_transmit_timeout(I2CDriver *i2cp, i2caddr_t addr,
                                      const uint8_t *txbuf, size_t txbytes,
                                      uint8_t *rxbuf, size_t rxbytes,
                                      sysinterval_t timeout) {
  I2C_TypeDef *dp = i2cp->i2c;
  systime_t start, end;
  msg_t msg;

  osalDbgCheck((i2cp != NULL) && (txbuf != NULL) && (txbytes > 0U) &&
               ((rxbytes == 0U) || ((rxbuf != NULL) && (rxbytes > 0U))));

  /* Initializes the driver fields, the LSB of the address selects the write
     direction, it is flipped by the interrupt handler before the repeated
     START of a combined transfer.*/
  i2cp->errors = I2C_NO_ERROR;
  i2cp->addr = (i2caddr_t)(addr << 1);
  i2cp->txbuf = txbuf;
  i2cp->txbytes = txbytes;
  i2cp->txidx = 0U;
  i2cp->rxbuf = rxbuf;
  i2cp->rxbytes = rxbytes;
  i2cp->rxidx = 0U;
  i2cp->rxphase = false;

  /* Releases the lock from the high level driver.*/
  osalSysUnlock();

  /* Calculating the time window for the timeout on the busy bus
     condition.*/
  start = osalOsGetSystemTimeX();
  end = osalTimeAddX(start, OSAL_MS2I(SK32_I2C_BUSY_TIMEOUT));

  /* Waits until the BUSY flag is reset and no STOP is pending or,
     alternatively, for a timeout condition.*/
  while (true) {
    osalSysLock();

    /* If the bus is not busy then the operation can continue, note, the
       loop is exited in the locked state.*/
    if (((dp->SR2 & I2C_SR2_BUSY) == 0U) && ((dp->CR1 & I2C_CR1_STOP) == 0U)) {
      break;
    }

    /* If the system time went outside the allowed window then a timeout
       condition is returned.*/
    if (!osalTimeIsInRangeX(osalOsGetSystemTimeX(), start, end)) {
      return MSG_TIMEOUT;
    }

    osalSysUnlock();
  }

  /* Starts the operation.*/
  dp->CR2 |= SK32_I2C_CR2_IE_MASK;
  dp->CR1 |= (uint16_t)(I2C_CR1_ACK | I2C_CR1_START);

  /* Waits for the operation completion or a timeout.*/
  msg = osalThreadSuspendTimeoutS(&i2cp->thread, timeout);

  /* In case of a software timeout the interrupt sources are disabled and a
     STOP is sent as an extreme attempt to release the bus.*/
  if (msg == MSG_TIMEOUT) {
    dp->CR2 &= (uint16_t)~SK32_I2C_CR2_IE_MASK;
    dp->CR1 |= I2C_CR1_STOP;
  }

  return msg;
}

#endif /* HAL_USE_I2C */

/** @} */
