/*
    Copyright (C) 2019 Ein Terakawa
    Copyright (C) 2014-2015 Fabio Utzig
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
 * @file    M251/hal_i2c_lld.c
 * @brief   M251/M252 I2C subsystem low level driver source.
 *
 * @addtogroup I2C
 * @{
 */

#include "hal.h"

#if (HAL_USE_I2C == TRUE) || defined(__DOXYGEN__)

#include "m251_isr.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define I2C_CTL0_STA I2C_CTL0_STA_Msk
#define I2C_CTL0_STO I2C_CTL0_STO_Msk
#define I2C_CTL0_SI  I2C_CTL0_SI_Msk
#define I2C_CTL0_AA  I2C_CTL0_AA_Msk
#define I2C_CTL0_CONTROL_MASK                                                  \
  (I2C_CTL0_STA | I2C_CTL0_STO | I2C_CTL0_SI | I2C_CTL0_AA)

#define I2C_GET_STATUS(i2c)  ((i2c)->STATUS0)
#define I2C_SET_DATA(i2c, d) ((i2c)->DAT = (d))
#define I2C_GET_DATA(i2c)    ((i2c)->DAT)

#define I2C_GET_TIMEOUT_FLAG(i2c)                                              \
  (((i2c)->TOCTL & I2C_TOCTL_TOIF_Msk) ? 1U : 0U)

/*===========================================================================*/
/* Driver local state definitions.                                           */
/*===========================================================================*/

#define I2C_STATE_STOP 0U
#define I2C_STATE_SEND 1U
#define I2C_STATE_RECV 2U

#define I2C_STOP_TIMEOUT 0x10000U

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   I2CD0 driver identifier.
 */
#if M251_I2C_USE_I2C0 || defined(__DOXYGEN__)
I2CDriver I2CD0;
#endif

/**
 * @brief   I2CD1 driver identifier.
 */
#if M251_I2C_USE_I2C1 || defined(__DOXYGEN__)
I2CDriver I2CD1;
#endif

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void i2c_write_control(I2C_TypeDef *i2c, uint32_t control) {
  uint32_t ctl0 = i2c->CTL0 & ~I2C_CTL0_CONTROL_MASK;

  /* SI is W1C, it must never be copied back from the register read.*/
  i2c->CTL0 = ctl0 | (control & I2C_CTL0_CONTROL_MASK);
}

static void i2c_enable_controller(I2C_TypeDef *i2c) {

  /* This helper is only called immediately after a peripheral reset.*/
  i2c->CTL0 = I2C_CTL0_I2CEN_Msk | I2C_CTL0_INTEN_Msk;
}

static void i2c_disable_controller(I2C_TypeDef *i2c) {

  /* A direct write cannot accidentally acknowledge a live W1C SI flag.*/
  i2c->CTL0 = 0U;
}

static void i2c_clear_pending(I2CDriver *i2cp) {

#if M251_I2C_USE_I2C0
  if (i2cp == &I2CD0) {
    nvicClearPending(M251_I2C0_NUMBER);
  }
#endif
#if M251_I2C_USE_I2C1
  if (i2cp == &I2CD1) {
    nvicClearPending(M251_I2C1_NUMBER);
  }
#endif
}

static void i2c_enable_vector(I2CDriver *i2cp) {

#if M251_I2C_USE_I2C0
  if (i2cp == &I2CD0) {
    nvicEnableVector(M251_I2C0_NUMBER, M251_I2C_I2C0_PRIORITY);
  }
#endif
#if M251_I2C_USE_I2C1
  if (i2cp == &I2CD1) {
    nvicEnableVector(M251_I2C1_NUMBER, M251_I2C_I2C1_PRIORITY);
  }
#endif
}

static void i2c_disable_vector(I2CDriver *i2cp) {

  /*
    Do not use nvicDisableVector() here. This helper is also called from the
    I2C ISR, while nvicDisableVector() clears the vector priority on Cortex-M23.
    Changing the priority of the active IRQ to zero before an OSAL wakeup
    violates the kernel-aware interrupt contract and triggers a debug halt.
  */
#if M251_I2C_USE_I2C0
  if (i2cp == &I2CD0) {
    NVIC_DisableIRQ((IRQn_Type)M251_I2C0_NUMBER);
    NVIC_ClearPendingIRQ((IRQn_Type)M251_I2C0_NUMBER);
  }
#endif
#if M251_I2C_USE_I2C1
  if (i2cp == &I2CD1) {
    NVIC_DisableIRQ((IRQn_Type)M251_I2C1_NUMBER);
    NVIC_ClearPendingIRQ((IRQn_Type)M251_I2C1_NUMBER);
  }
#endif
}

static void i2c_quiesce_controller(I2CDriver *i2cp, i2cflags_t errors) {

  i2cp->errors |= errors;
  i2cp->intstate = (intstate_t)I2C_STATE_STOP;
  i2cp->is_master = 0U;
  i2c_disable_vector(i2cp);

  /* Disable the counter and clear its W1C flag before removing INTEN.*/
  i2cp->i2c->TOCTL = I2C_TOCTL_TOIF_Msk;
  i2c_disable_controller(i2cp->i2c);

  /* Clear anything re-pended before the peripheral source was disabled.*/
  i2c_clear_pending(i2cp);
}

static void i2c_config_frequency(I2CDriver *i2cp) {
  uint32_t code;
  uint32_t pclk;
  uint32_t divisor;
  uint32_t target = 100000U;

  if (i2cp->config != NULL)
    target = i2cp->config->clock;

  if (i2cp->i2c == I2C1) {
    code = (CLK->PCLKDIV & CLK_PCLKDIV_APB1DIV_Msk) >> CLK_PCLKDIV_APB1DIV_Pos;
  }
  else {
    code = (CLK->PCLKDIV & CLK_PCLKDIV_APB0DIV_Msk) >> CLK_PCLKDIV_APB0DIV_Pos;
  }

  osalDbgAssert(code <= 5U, "invalid APB clock divider");
  pclk = SystemCoreClock >> code;

  /* CLKDIV values below four are reserved by the M251 hardware.*/
  osalDbgAssert((target > 0U) && (target <= (pclk / 20U)), "invalid I2C clock");
  divisor =
      (uint32_t)((((uint64_t)pclk * 10U) / ((uint64_t)target * 4U) + 5U) / 10U
                 - 1U);
  osalDbgAssert(
      (divisor >= 4U)
          && (divisor <= (I2C_CLKDIV_DIVIDER_Msk >> I2C_CLKDIV_DIVIDER_Pos)),
      "I2C clock divider out of range");

  i2cp->i2c->CLKDIV = (i2cp->i2c->CLKDIV & ~I2C_CLKDIV_DIVIDER_Msk)
                      | (divisor << I2C_CLKDIV_DIVIDER_Pos);
}

static void i2c_reset_timeout(I2CDriver *i2cp) {
  /*
    Keep the hardware counter disabled between transfers and clear a stale
    W1C flag. It is enabled only around an active master transaction below.
  */
  i2cp->i2c->TOCTL = I2C_TOCTL_TOIF_Msk;
}

static void i2c_start_timeout(I2CDriver *i2cp) {
  /*
    Always clear a flag left by the preceding transaction. When enabled, the
    14-bit PCLK/4 counter is an independent escape from a stalled bus.
  */
#if M251_I2C_USE_HW_TIMEOUT
  i2cp->i2c->TOCTL =
      I2C_TOCTL_TOIF_Msk | I2C_TOCTL_TOCDIV4_Msk | I2C_TOCTL_TOCEN_Msk;
#else
  i2cp->i2c->TOCTL = I2C_TOCTL_TOIF_Msk;
#endif
}

static void i2c_stop_transaction(I2CDriver *i2cp) {

  i2c_disable_vector(i2cp);
  i2cp->intstate = (intstate_t)I2C_STATE_STOP;
  i2cp->is_master = 0U;
  i2c_write_control(i2cp->i2c, I2C_CTL0_STO | I2C_CTL0_SI);
}

static void i2c_stop_error(I2CDriver *i2cp, i2cflags_t errors) {

  i2cp->errors |= errors;
  i2c_stop_transaction(i2cp);
}

static void i2c_reset_peripheral(I2CDriver *i2cp) {

  m251_lld_unlock();
#if M251_I2C_USE_I2C0
  if (i2cp == &I2CD0) {
    SYS->IPRST1 |= SYS_IPRST1_I2C0RST_Msk;
    SYS->IPRST1 &= ~SYS_IPRST1_I2C0RST_Msk;
  }
#endif
#if M251_I2C_USE_I2C1
  if (i2cp == &I2CD1) {
    SYS->IPRST1 |= SYS_IPRST1_I2C1RST_Msk;
    SYS->IPRST1 &= ~SYS_IPRST1_I2C1RST_Msk;
  }
#endif
  m251_lld_lock();
}

static void i2c_lld_enable(I2CDriver *i2cp) {

  m251_lld_unlock();
#if M251_I2C_USE_I2C0
  if (i2cp == &I2CD0) {
    CLK->APBCLK0 |= CLK_APBCLK0_I2C0CKEN_Msk;
  }
#endif
#if M251_I2C_USE_I2C1
  if (i2cp == &I2CD1) {
    CLK->APBCLK0 |= CLK_APBCLK0_I2C1CKEN_Msk;
  }
#endif
  m251_lld_lock();
  i2c_reset_peripheral(i2cp);
}

static void i2c_lld_disable(I2CDriver *i2cp) {

  i2c_disable_vector(i2cp);

  m251_lld_unlock();
#if M251_I2C_USE_I2C0
  if (i2cp == &I2CD0) {
    CLK->APBCLK0 &= ~CLK_APBCLK0_I2C0CKEN_Msk;
  }
#endif
#if M251_I2C_USE_I2C1
  if (i2cp == &I2CD1) {
    CLK->APBCLK0 &= ~CLK_APBCLK0_I2C1CKEN_Msk;
  }
#endif
  m251_lld_lock();
}

static void i2c_reset_transaction(I2CDriver *i2cp) {

  i2c_disable_controller(i2cp->i2c);
  i2c_reset_peripheral(i2cp);
  i2c_config_frequency(i2cp);
  i2c_reset_timeout(i2cp);
  i2cp->intstate = (intstate_t)I2C_STATE_STOP;
  i2cp->is_master = 0U;
  i2c_enable_controller(i2cp->i2c);
}

static void i2c_abort_transaction(I2CDriver *i2cp) {
  uint32_t timeout = I2C_STOP_TIMEOUT;

  i2c_stop_transaction(i2cp);
  while (((i2cp->i2c->CTL0 & I2C_CTL0_STO_Msk) != 0U) && (timeout-- > 0U)) {
  }

  i2c_reset_transaction(i2cp);
}

static void i2c_recover_transaction(I2CDriver *i2cp) {

  i2c_disable_vector(i2cp);
  i2c_reset_transaction(i2cp);
}

static bool i2c_wait_stop(I2CDriver *i2cp) {
  uint32_t timeout = I2C_STOP_TIMEOUT;

  while (((i2cp->i2c->CTL0 & I2C_CTL0_STO_Msk) != 0U) && (timeout-- > 0U)) {
  }

  return (i2cp->i2c->CTL0 & I2C_CTL0_STO_Msk) == 0U;
}

static void serve_interrupt(I2CDriver *i2cp) {
  I2C_TypeDef *i2c = i2cp->i2c;
  uint8_t status;

  if (I2C_GET_TIMEOUT_FLAG(i2c)) {
    bool active = i2cp->intstate != I2C_STATE_STOP;

    i2c_quiesce_controller(i2cp, I2C_TIMEOUT);
    if (active) {
      _i2c_wakeup_error_isr(i2cp);
    }
    return;
  }

  /*
    An IRQ without SI or TOIF is unexpected. Fail closed in case it came from
    another peripheral source rather than merely a stale NVIC pending bit.
  */
  if ((i2c->CTL0 & I2C_CTL0_SI) == 0U) {
    bool active = i2cp->intstate != I2C_STATE_STOP;

    i2c_quiesce_controller(i2cp, I2C_BUS_ERROR);
    if (active) {
      _i2c_wakeup_error_isr(i2cp);
    }
    return;
  }

  status = (uint8_t)I2C_GET_STATUS(i2c);

  /*
    An interrupt while the software state is idle has no thread to wake. Shut
    the controller down so a noisy or wedged bus cannot continuously reassert
    SI and starve the kernel. The next public transfer detects the disabled
    controller, resets it, and returns MSG_RESET so its caller can retry.
  */
  if (i2cp->intstate == I2C_STATE_STOP) {
    if (status == 0x38U || status == 0x68U || status == 0x78U
        || status == 0xB0U) {
      i2c_quiesce_controller(i2cp, I2C_ARBITRATION_LOST);
    }
    else {
      i2c_quiesce_controller(i2cp, I2C_BUS_ERROR);
    }
    return;
  }

  if (status == 0x08U || status == 0x10U) {
    i2cp->is_master = 1U;
  }
  else if (status == 0x00U) {
    i2c_quiesce_controller(i2cp, I2C_BUS_ERROR);
    _i2c_wakeup_error_isr(i2cp);
    return;
  }
  else if (status == 0x38U || status == 0x68U || status == 0x78U
           || status == 0xB0U) {
    i2c_quiesce_controller(i2cp, I2C_ARBITRATION_LOST);
    _i2c_wakeup_error_isr(i2cp);
    return;
  }
  else if (i2cp->is_master == 0U) {
    i2c_quiesce_controller(i2cp, I2C_BUS_ERROR);
    _i2c_wakeup_error_isr(i2cp);
    return;
  }

  switch (status) {
  case 0x08U:
  case 0x10U: {
    uint8_t op = (i2cp->intstate == I2C_STATE_SEND) ? 0U : 1U;

    I2C_SET_DATA(i2c, (i2cp->addr << 1) | op);
    i2c_write_control(i2c, I2C_CTL0_SI);
    return;
  }
  case 0x18U:
  case 0x28U:
    if (i2cp->txbuf != NULL && i2cp->txidx < i2cp->txbytes) {
      I2C_SET_DATA(i2c, i2cp->txbuf[i2cp->txidx++]);
      i2c_write_control(i2c, I2C_CTL0_SI);
    }
    else if (i2cp->rxbuf != NULL && i2cp->rxbytes != 0U) {
      i2cp->intstate = (intstate_t)I2C_STATE_RECV;
      i2c_write_control(i2c, I2C_CTL0_STA | I2C_CTL0_SI);
    }
    else {
      i2c_stop_transaction(i2cp);
      _i2c_wakeup_isr(i2cp);
    }
    return;
  case 0x20U:
  case 0x30U:
  case 0x48U:
    i2c_stop_error(i2cp, I2C_ACK_FAILURE);
    _i2c_wakeup_error_isr(i2cp);
    return;
  case 0x40U:
    if (i2cp->rxidx + 1U == i2cp->rxbytes) {
      i2c_write_control(i2c, I2C_CTL0_SI);
    }
    else {
      i2c_write_control(i2c, I2C_CTL0_SI | I2C_CTL0_AA);
    }
    return;
  case 0x50U:
    if (i2cp->rxbuf == NULL || i2cp->rxidx >= i2cp->rxbytes) {
      i2c_stop_error(i2cp, I2C_OVERRUN);
      _i2c_wakeup_error_isr(i2cp);
      return;
    }

    i2cp->rxbuf[i2cp->rxidx++] = (uint8_t)I2C_GET_DATA(i2c);
    if (i2cp->rxidx >= i2cp->rxbytes) {
      i2c_stop_error(i2cp, I2C_OVERRUN);
      _i2c_wakeup_error_isr(i2cp);
    }
    else if (i2cp->rxidx + 1U == i2cp->rxbytes) {
      i2c_write_control(i2c, I2C_CTL0_SI);
    }
    else {
      i2c_write_control(i2c, I2C_CTL0_SI | I2C_CTL0_AA);
    }
    return;
  case 0x58U:
    if (i2cp->rxbuf == NULL || i2cp->rxidx >= i2cp->rxbytes) {
      i2c_stop_error(i2cp, I2C_OVERRUN);
      _i2c_wakeup_error_isr(i2cp);
      return;
    }

    i2cp->rxbuf[i2cp->rxidx++] = (uint8_t)I2C_GET_DATA(i2c);
    if (i2cp->rxidx == i2cp->rxbytes) {
      i2c_stop_transaction(i2cp);
      _i2c_wakeup_isr(i2cp);
    }
    else {
      i2c_stop_error(i2cp, I2C_OVERRUN);
      _i2c_wakeup_error_isr(i2cp);
    }
    return;
  default:
    i2c_quiesce_controller(i2cp, I2C_BUS_ERROR);
    _i2c_wakeup_error_isr(i2cp);
    return;
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if M251_I2C_USE_I2C0 || defined(__DOXYGEN__)
/**
 * @brief   I2C0 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_I2C0_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  serve_interrupt(&I2CD0);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if M251_I2C_USE_I2C1 || defined(__DOXYGEN__)
/**
 * @brief   I2C1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_I2C1_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  serve_interrupt(&I2CD1);
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

#if M251_I2C_USE_I2C0
  i2cObjectInit(&I2CD0);
  I2CD0.thread = NULL;
  I2CD0.i2c = I2C0;
  I2CD0.is_master = 0U;
#endif

#if M251_I2C_USE_I2C1
  i2cObjectInit(&I2CD1);
  I2CD1.thread = NULL;
  I2CD1.i2c = I2C1;
  I2CD1.is_master = 0U;
#endif
}

/**
 * @brief   Configures and activates the I2C peripheral.
 *
 * @param[in] i2cp      pointer to an @p I2CDriver object
 *
 * @notapi
 */
void i2c_lld_start(I2CDriver *i2cp) {

  i2c_disable_vector(i2cp);

  if (i2cp->state == I2C_STOP) {
    i2c_lld_enable(i2cp);
  }
  else {
    i2c_disable_controller(i2cp->i2c);
    i2c_reset_peripheral(i2cp);
  }

  i2c_config_frequency(i2cp);
  i2c_reset_timeout(i2cp);
  i2cp->intstate = (intstate_t)I2C_STATE_STOP;
  i2cp->is_master = 0U;
  i2c_enable_controller(i2cp->i2c);
}

/**
 * @brief   Deactivates the I2C peripheral.
 *
 * @param[in] i2cp      pointer to an @p I2CDriver object
 *
 * @notapi
 */
void i2c_lld_stop(I2CDriver *i2cp) {

  if (i2cp->state != I2C_STOP) {
    i2c_disable_controller(i2cp->i2c);
    i2c_reset_peripheral(i2cp);
    i2c_lld_disable(i2cp);
    i2cp->intstate = (intstate_t)I2C_STATE_STOP;
    i2cp->is_master = 0U;
  }
}

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static msg_t _i2c_txrx_timeout(I2CDriver *i2cp, i2caddr_t addr,
                               const uint8_t *txbuf, size_t txbytes,
                               uint8_t *rxbuf, size_t rxbytes,
                               systime_t timeout) {

  msg_t msg;

  i2cp->errors = I2C_NO_ERROR;
  if (addr > 0x7FU) {
    i2cp->errors = I2C_BUS_ERROR;
    i2cp->intstate = (intstate_t)I2C_STATE_STOP;
    i2cp->is_master = 0U;
    return MSG_RESET;
  }
  i2cp->addr = addr;

  i2cp->txbuf = txbuf;
  i2cp->txbytes = txbytes;
  i2cp->txidx = 0U;

  i2cp->rxbuf = rxbuf;
  i2cp->rxbytes = rxbytes;
  i2cp->rxidx = 0U;

  /*
    A public transfer always starts from an idle controller. Combined
    transmit/receive uses a repeated START internally in the ISR.
  */
  if (i2cp->is_master != 0U || (i2cp->i2c->CTL0 & I2C_CTL0_CONTROL_MASK) != 0U
      || (i2cp->i2c->CTL0 & (I2C_CTL0_I2CEN_Msk | I2C_CTL0_INTEN_Msk))
             != (I2C_CTL0_I2CEN_Msk | I2C_CTL0_INTEN_Msk)) {
    i2cp->errors |= I2C_BUS_ERROR;
    i2c_recover_transaction(i2cp);
    return MSG_RESET;
  }

  i2c_start_timeout(i2cp);
  i2c_enable_vector(i2cp);
  i2c_write_control(i2cp->i2c, I2C_CTL0_STA);

  msg = osalThreadSuspendTimeoutS(&i2cp->thread, timeout);
  if (msg == MSG_TIMEOUT) {
    i2cp->errors |= I2C_TIMEOUT;
    i2c_reset_timeout(i2cp);
    i2c_abort_transaction(i2cp);
    return msg;
  }

  /*
    The final data-state ISR wakes the thread when it requests STOP, before
    the controller has finished placing it on the bus. Starting another
    transfer while STO is still set can leave the M251 I2C state machine
    stalled. Nuvoton's polling and EEPROM implementations also wait for this
    bit to clear before returning or issuing the next START.
  */
  if (!i2c_wait_stop(i2cp)) {
    i2cp->errors |= I2C_TIMEOUT;
    i2c_reset_timeout(i2cp);
    i2c_abort_transaction(i2cp);
    return MSG_TIMEOUT;
  }

  i2cp->is_master = 0U;
  i2cp->intstate = (intstate_t)I2C_STATE_STOP;
  i2c_reset_timeout(i2cp);

  if (i2cp->errors != I2C_NO_ERROR) {
    if (i2cp->errors != I2C_ACK_FAILURE) {
      /* Recover from faults that can leave the controller state uncertain.*/
      i2c_recover_transaction(i2cp);
    }
    return MSG_RESET;
  }

  return MSG_OK;
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Receives data from an I2C slave.
 *
 * @param[in] i2cp      pointer to an @p I2CDriver object
 * @param[in] addr      slave address without R/W bit
 * @param[out] rxbuf    pointer to the receive buffer
 * @param[in] rxbytes   number of bytes to receive
 * @param[in] timeout   operation timeout
 * @return              The operation status.
 * @retval MSG_OK       if the operation completed successfully.
 * @retval MSG_RESET    if an I2C error occurred.
 * @retval MSG_TIMEOUT  if the operation timed out.
 *
 * @notapi
 */
msg_t i2c_lld_master_receive_timeout(I2CDriver *i2cp, i2caddr_t addr,
                                     uint8_t *rxbuf, size_t rxbytes,
                                     systime_t timeout) {

  i2cp->intstate = (intstate_t)I2C_STATE_RECV;
  return _i2c_txrx_timeout(i2cp, addr, NULL, 0U, rxbuf, rxbytes, timeout);
}

/**
 * @brief   Transmits data to an I2C slave, optionally receiving a response.
 *
 * @param[in] i2cp      pointer to an @p I2CDriver object
 * @param[in] addr      slave address without R/W bit
 * @param[in] txbuf     pointer to the transmit buffer
 * @param[in] txbytes   number of bytes to transmit
 * @param[out] rxbuf    pointer to the receive buffer or @p NULL
 * @param[in] rxbytes   number of bytes to receive
 * @param[in] timeout   operation timeout
 * @return              The operation status.
 * @retval MSG_OK       if the operation completed successfully.
 * @retval MSG_RESET    if an I2C error occurred.
 * @retval MSG_TIMEOUT  if the operation timed out.
 *
 * @notapi
 */
msg_t i2c_lld_master_transmit_timeout(I2CDriver *i2cp, i2caddr_t addr,
                                      const uint8_t *txbuf, size_t txbytes,
                                      uint8_t *rxbuf, size_t rxbytes,
                                      systime_t timeout) {

  i2cp->intstate = (intstate_t)I2C_STATE_SEND;
  return _i2c_txrx_timeout(i2cp, addr, txbuf, txbytes, rxbuf, rxbytes, timeout);
}

#endif /* HAL_USE_I2C */

/** @} */
