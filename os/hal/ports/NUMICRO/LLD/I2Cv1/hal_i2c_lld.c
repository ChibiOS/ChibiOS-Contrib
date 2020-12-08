/*
    ChibiOS - Copyright (C) 2019 Ein Terakawa
               Copyright (C) 2014-2015 Fabio Utzig

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
 * @file    NUMICRO/hal_i2c_lld.c
 * @brief   NUMICRO I2C subsystem low level driver source.
 *
 * @addtogroup I2C
 * @{
 */

// #include "osal.h"
// #include "hal.h"

// #define wait_ms(ms) chThdSleepMilliseconds(ms)
// #define wait_us(us) chThdSleepMicroseconds(us)

// void tfp_printf(char *fmt, ...);
// #define printf tfp_printf 

#include "hal_i2c_lld.h"
#include "wait.h"


#if HAL_USE_I2C || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

// #define I2C_SET_I2CON(i2c, i2conMsk) ((i2c)->I2CON = (((i2c)->I2CON & ~I2C_I2CON_STA_STO_SI_AA) | (i2conMsk)))
#if 0
#define I2C_I2CON_SI (I2C_I2CON_SI_Msk)
#define I2C_I2CON_SI_AA (I2C_I2CON_SI_Msk|I2C_I2CON_AA_Msk)
#define I2C_I2CON_STA_SI (I2C_I2CON_STA_Msk|I2C_I2CON_SI_Msk)
#define I2C_I2CON_STO_SI (I2C_I2CON_STO_Msk|I2C_I2CON_SI_Msk)
#define I2C_I2CON_STA_STO_SI_AA (I2C_I2CON_STA_Msk|I2C_I2CON_STO_Msk|I2C_I2CON_SI_Msk|I2C_I2CON_AA_Msk)
#endif

msg_t osalThreadSuspendTimeoutS(volatile msg_t *wait_object, systime_t timeout) {
    *wait_object = MSG_UNDEFINED;
    do { } while(*wait_object == MSG_UNDEFINED);
    return *wait_object;
}

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   I2C0 driver identifier.
 */
#if NUMICRO_I2C_USE_I2C0 || defined(__DOXYGEN__)
I2CDriver I2CD1;
#endif

/**
 * @brief   I2C1 driver identifier.
 */
#if NUMICRO_I2C_USE_I2C1 || defined(__DOXYGEN__)
I2CDriver I2CD2;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

void config_frequency(I2CDriver *i2cp) {

  uint8_t divisor;

  if (i2cp->config != NULL)
    divisor = (I2C_PCLK * 10 / (i2cp->config->clock * 4) + 5) / 10 - 1;
  else
    divisor = I2C_PCLK / 4 / 100000 - 1;

#if __NUC123__
  i2cp->i2c->I2CLK = divisor;
#endif
}

/**
 * @brief   Common IRQ handler.
 * @note    Tries hard to clear all the pending interrupt sources, we don't
 *          want to go through the whole ISR and have another interrupt soon
 *          after.
 *
 * @param[in] i2cp         pointer to an I2CDriver
 */
static void serve_interrupt(I2CDriver *i2cp) {

  I2C_TypeDef *i2c = i2cp->i2c;
  // intstate_t state = i2cp->intstate;

  if (I2C_GET_TIMEOUT_FLAG(i2c)) {
    i2cp->errors |= I2C_TIMEOUT;
    I2C_ClearTimeoutFlag(i2c);
    I2C_Trigger(i2c, /* Start */ 0, /* Stop */ 0, /* SI */ 1, /* Ack */ 0);
    return;
  }

  uint8_t status = (uint8_t)I2C_GET_STATUS(i2c);

  if (status == 0x08 || status == 0x10) {
    if (i2cp->intstate == STATE_STOP) {
      // i2c->I2CON = ((i2c->I2CON & ~I2C_I2CON_STA_STO_SI_AA) | I2C_I2CON_SI);
      I2C_DisableInt(i2c);
      return;
    }
    i2cp->is_master = 1;
  }

  /* check if we're master or slave */
  if (i2cp->is_master) {
    /* master */

    if (status == 0x38 || status == 0x68 || status == 0x78 || status == 0xB0) {
      /* check if we lost arbitration */
      i2cp->errors |= I2C_ARBITRATION_LOST;
      I2C_Trigger(i2c, /* Start */ 0, /* Stop */ 0, /* SI */ 1, /* Ack */ 0);
      /* TODO: may need to do more here, reset bus? */
      /* Perhaps clear MST? */
      i2cp->is_master = 0;
    }

    else if (status == 0x08 || status == 0x10) {
      uint8_t op = (i2cp->intstate == STATE_SEND) ? 0 : 1;
      I2C_SET_DATA(i2c, (i2cp->addr << 1) | op);
      // i2c->I2CON |= I2C_I2CON_SI;
      // I2C_SET_I2CON(i2c, I2C_I2CON_SI);
      I2C_Trigger(i2c, /* Start */ 0, /* Stop */ 0, /* SI */ 1, /* Ack */ 0);
    }
    else if (status == 0x18 || status == 0x28) {
      // ACK
	if (i2cp->txbuf != NULL && i2cp->txidx < i2cp->txbytes) {
            /* slave ACK'd and we want to send more */
          I2C_SET_DATA(i2c, i2cp->txbuf[i2cp->txidx++]);
	  // i2c->I2CON |= I2C_I2CON_SI;
	  // I2C_SET_I2CON(i2c, I2C_I2CON_SI);
          I2C_Trigger(i2c, /* Start */ 0, /* Stop */ 0, /* SI */ 1, /* Ack */ 0);
	} else {
	  /* slave ACK'd and we are done sending */
	  if (i2cp->rxbuf != NULL && i2cp->rxbytes != 0) {
	    i2cp->intstate = STATE_RECV;
	    // i2c->I2CON |= I2C_I2CON_STA_STO_SI;
            I2C_START(i2c); // should we use Repeat-START ?
	  } else {
	    i2cp->intstate = STATE_STOP;
	    // i2c->I2CON |= I2C_I2CON_STO_SI;
	    // I2C_SET_I2CON(i2c, I2C_I2CON_STO_SI);
            I2C_Trigger(i2c, /* Start */ 0, /* Stop */ 1, /* SI */ 1, /* Ack */ 0);
	    // I2C_SET_I2CON(i2c, I2C_I2CON_STA_SI); // go to Repeated-START state
_i2c_wakeup_isr(i2cp);
	    /* this wakes up the waiting thread at the end of ISR */
	  }
	}
    }
    else if (status == 0x20 || status == 0x30) {
      // NAK
      i2cp->errors |= I2C_ACK_FAILURE;
      i2cp->intstate = STATE_STOP;
      // I2C_SET_I2CON(i2c, I2C_I2CON_STO_SI); // go to Repeated-START state
      I2C_Trigger(i2c, /* Start */ 0, /* Stop */ 1, /* SI */ 1, /* Ack */ 0); // go to Repeated-START state
    }
    else if (status == 0x40) {
      // ACK to read request
#if 1
      if (i2cp->rxidx + 1 == i2cp->rxbytes) {
	// only one byte to receive
	// i2c->I2CON |= I2C_I2CON_SI;
	// I2C_SET_I2CON(i2c, I2C_I2CON_SI);
        I2C_Trigger(i2c, /* Start */ 0, /* Stop */ 0, /* SI */ 1, /* Ack */ 0);
      } else {
	// i2c->I2CON |= I2C_I2CON_SI_AA;
	// I2C_SET_I2CON(i2c, I2C_I2CON_SI_AA);
        I2C_Trigger(i2c, /* Start */ 0, /* Stop */ 0, /* SI */ 1, /* Ack */ 1);
      }
#endif
      // i2c->I2CON |= I2C_I2CON_SI_AA;
    }
    else if (status == 0x50 || status == 0x58) {
      // one byte done
      if (i2cp->rxbuf == NULL || i2cp->rxidx >= i2cp->rxbytes) {
	// this is unexpected.
	i2cp->errors |= I2C_OVERRUN; // is this the apropriate error code?
	i2cp->intstate = STATE_STOP;
        I2C_STOP(i2c);
      }
      else {
        i2cp->rxbuf[i2cp->rxidx++] = I2C_GET_DATA(i2c);
	if (i2cp->rxidx == i2cp->rxbytes) {
	  // last byte done
	  i2cp->intstate = STATE_STOP;
	  // I2C_SET_I2CON(i2c, I2C_I2CON_STO_SI);
          I2C_Trigger(i2c, /* Start */ 0, /* Stop */ 1, /* SI */ 1, /* Ack */ 0);
_i2c_wakeup_isr(i2cp);
	}
	else if (i2cp->rxidx + 1 == i2cp->rxbytes) {
	  // next byte is the last
	  // I2C_SET_I2CON(i2c, I2C_I2CON_SI);
          I2C_Trigger(i2c, /* Start */ 0, /* Stop */ 0, /* SI */ 1, /* Ack */ 0);
	} 
	else {
	  // I2C_SET_I2CON(i2c, I2C_I2CON_SI_AA);
          I2C_Trigger(i2c, /* Start */ 0, /* Stop */ 0, /* SI */ 1, /* Ack */ 1);
	}
      }
    }
    else if (status == 0x48) {
      // NAK to read request
      i2cp->errors |= I2C_ACK_FAILURE;
      i2cp->intstate = STATE_STOP;
      I2C_STOP(i2c);
    }
    else if (status == 0xF8) {
      /* CAUTION! I2CSTATUS == 0xF8 won't trigger interrupt! */
      // everything completed
      // i2cp->is_master = 0;
      // i2cp->intstate = STATE_STOP;
    }
    else {
      // need anything else?
    }
#if 0
    else if (i2c->S & I2Cx_S_TCF) {
      /* just completed byte transfer */
      if (i2c->C1 & I2Cx_C1_TX) {
        /* the byte was transmitted */

        if (state == STATE_SEND) {
          /* currently sending stuff */

          if (i2c->S & I2Cx_S_RXAK) {
            /* slave did not ACK */
            i2cp->errors |= I2C_ACK_FAILURE;
            /* the thread will be woken up at the end of ISR and release the bus */

          } else if (i2cp->txbuf != NULL && i2cp->txidx < i2cp->txbytes) {
            /* slave ACK'd and we want to send more */
            i2c->D = i2cp->txbuf[i2cp->txidx++];
          } else {
            /* slave ACK'd and we are done sending */
            i2cp->intstate = STATE_STOP;
            /* this wakes up the waiting thread at the end of ISR */
          }

        } else if (state == STATE_RECV) {
          /* should be receiving stuff, so we've just sent the address */

          if (i2c->S & I2Cx_S_RXAK) {
            /* slave did not ACK */
            i2cp->errors |= I2C_ACK_FAILURE;
            /* the thread will be woken up and release the bus */

          } else {
            /* slave ACK'd, we should be receiving next */
            i2c->C1 &= ~I2Cx_C1_TX;

            if (i2cp->rxbytes > 1) {
              /* multi-byte read, send ACK after next transfer */
              i2c->C1 &= ~I2Cx_C1_TXAK;
            } else {
              /* only 1 byte remaining, send NAK */
              i2c->C1 |= I2Cx_C1_TXAK;
            }

            (void) i2c->D; /* dummy read; triggers next receive */
          }

        } /* possibly check other states here - should not happen! */

      } else {
        /* the byte was received */

        if (state == STATE_RECV) {
          /* currently receiving stuff */
          /* the received byte is now in D */

          if (i2cp->rxbytes > 1) {
            /* expecting at least one byte after this one */
            if (i2cp->rxidx == (i2cp->rxbytes - 2)) {
              /* expecting exactly one byte after this one, NAK that one */
              i2c->C1 |= I2Cx_C1_TXAK;
            } else {
              /* expecting more than one after this one, respond with ACK */
              i2c->C1 &= ~I2Cx_C1_TXAK;
            }
          }

          if (i2cp->rxidx == i2cp->rxbytes - 1) {
            /* D is the last byte we're expecting */
            /* release bus: switch to RX mode, send STOP */
            /* need to do it now otherwise the I2C module will wait for another byte */
            // delayMicroseconds(1);
            i2c->C1 &= ~(I2Cx_C1_TX | I2Cx_C1_MST);
            i2cp->intstate = STATE_STOP;
            /* this wakes up the waiting thread at the end of ISR */
          }

          /* get the data from D; this triggers the next receive */
          i2cp->rxbuf[i2cp->rxidx++] = i2c->D;

          // if (i2cp->rxidx == i2cp->rxbytes) {
            /* done receiving */
          // }
        } /* possibly check other states here - should not happen! */
      }

    } /* possibly check other interrupt flags here */
#endif
  } else {
    /* slave */

    /* Not implemented yet */
  }

  /* Reset other interrupt sources */

  /* Reset interrupt flag */
  // i2c->S |= I2Cx_S_IICIF;

  if (i2cp->errors != I2C_NO_ERROR)
    _i2c_wakeup_error_isr(i2cp);
  else if (i2cp->intstate == STATE_STOP && i2cp->is_master == 0)
    _i2c_wakeup_isr(i2cp);
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if NUMICRO_I2C_USE_I2C0 || defined(__DOXYGEN__)

OSAL_IRQ_HANDLER(NUMICRO_I2C0_IRQ_VECTOR) {

  OSAL_IRQ_PROLOGUE();
  serve_interrupt(&I2CD1);
  OSAL_IRQ_EPILOGUE();
}

#endif

#if NUMICRO_I2C_USE_I2C1 || defined(__DOXYGEN__)

OSAL_IRQ_HANDLER(NUMICRO_I2C1_IRQ_VECTOR) {

  OSAL_IRQ_PROLOGUE();
  serve_interrupt(&I2CD2);
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

#if NUMICRO_I2C_USE_I2C0
  i2cObjectInit(&I2CD1);
  // I2CD1.thread = NULL;
  I2CD1.i2c = I2C0;
  I2CD1.is_master = 0;
#endif

#if NUMICRO_I2C_USE_I2C1
  i2cObjectInit(&I2CD2);
  // I2CD2.thread = NULL;
  I2CD2.i2c = I2C1;
  I2CD2.is_master = 0;
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

  /* TODO:
   *   The PORT must be enabled somewhere. The PIN multiplexer
   *   will map the I2C functionality to some PORT which must
   *   than be enabled. The easier way is enabling all PORTs at
   *   startup, which is currently being done in __early_init.
   */

#if NUMICRO_I2C_USE_I2C0
    if (&I2CD1 == i2cp) {
      // SIM->SCGC4 |= SIM_SCGC4_I2C0;
      CLK_EnableModuleClock(I2C0_MODULE);
      // CLK->APBCLK |= CLK_APBCLK_I2C0_EN_Msk;
      SYS_ResetModule(I2C0_RST);
      // SYS->IPRSTC2 |= SYS_IPRSTC2_I2C0_RST_Msk;
      // SYS->IPRSTC2 &= ~SYS_IPRSTC2_I2C0_RST_Msk;
      nvicEnableVector(I2C0_IRQn, NUMICRO_I2C_I2C0_PRIORITY);
    }
#endif

#if NUMICRO_I2C_USE_I2C1
    if (&I2CD2 == i2cp) {
      // SIM->SCGC4 |= SIM_SCGC4_I2C1;
      CLK_EnableModuleClock(I2C1_MODULE);
      // CLK->APBCLK |= CLK_APBCLK_I2C1_EN_Msk;
      SYS_ResetModule(I2C1_RST);
      // SYS->IPRSTC2 |= SYS_IPRSTC2_I2C1_RST_Msk;
      // SYS->IPRSTC2 &= ~SYS_IPRSTC2_I2C1_RST_Msk;
      nvicEnableVector(I2C1_IRQn, NUMICRO_I2C_I2C1_PRIORITY);
    }
#endif

#if 0
  config_frequency(i2cp);
  // i2cp->i2c->C1 = I2Cx_C1_IICEN | I2Cx_C1_IICIE; // reset I2C, enable interrupts
  // i2cp->i2c->S = I2Cx_S_IICIF | I2Cx_S_ARBL; // clear status flags just in case
  I2C_ClearTimeoutFlag(i2cp->i2c);
  // i2cp->i2c->I2CON = I2C_I2CON_SI_Msk;
  I2C_Trigger(i2cp->i2c, /* Start */ 0, /* Stop */ 0, /* SI */ 1, /* Ack */ 0);
  i2cp->i2c->I2CON = (I2C_I2CON_EI_Msk | I2C_I2CON_ENS1_Msk);
#endif
  uint32_t bus_clock = i2cp->config ? i2cp->config->clock : 100000;
  I2C_Open(i2cp->i2c, bus_clock);
  I2C_EnableInt(i2cp->i2c);
  i2cp->intstate = STATE_STOP; // internal state
  }
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

    // i2cp->i2c->C1 &= ~(I2Cx_C1_IICEN | I2Cx_C1_IICIE);
    // i2cp->i2c->I2CON &= ~(I2C_I2CON_EI_Msk | I2C_I2CON_ENS1_Msk);
    I2C_DisableInt(i2cp->i2c);
    I2C_Close(i2cp->i2c);

#if NUMICRO_I2C_USE_I2C0
    if (&I2CD1 == i2cp) {
      // SIM->SCGC4 &= ~SIM_SCGC4_I2C0;
      nvicDisableVector(I2C0_IRQn);
    }
#endif

#if NUMICRO_I2C_USE_I2C1
    if (&I2CD2 == i2cp) {
      // SIM->SCGC4 &= ~SIM_SCGC4_I2C1;
      nvicDisableVector(I2C1_IRQn);
    }
#endif

  }
}

static inline msg_t _i2c_txrx_timeout(I2CDriver *i2cp, i2caddr_t addr,
                                      const uint8_t *txbuf, size_t txbytes,
                                      uint8_t *rxbuf, size_t rxbytes,
                                      systime_t timeout) {

  msg_t msg;
  // systime_t start, end;

  // uint8_t op = (i2cp->intstate == STATE_SEND) ? 0 : 1;

  i2cp->errors = I2C_NO_ERROR;
  i2cp->addr = addr;

  i2cp->txbuf = txbuf;
  i2cp->txbytes = txbytes;
  i2cp->txidx = 0;

  i2cp->rxbuf = rxbuf;
  i2cp->rxbytes = rxbytes;
  i2cp->rxidx = 0;

  /* clear status flags */
  // i2cp->i2c->S = I2Cx_S_IICIF|I2Cx_S_ARBL;

  /* acquire the bus */
  /* check to see if we already have the bus */
  if(i2cp->is_master) {

    /* send repeated start */
    // i2cp->i2c->I2CON |= I2C_I2CON_STA_SI;
    I2C_START(i2cp->i2c);
    // i2cp->i2c->I2CON |= I2C_I2CON_STA_STO_SI;
    while((uint8_t)I2C_GET_STATUS(i2cp->i2c) == 0xF8);

  } else {
    /* unlock during the wait, so that tasks with
     * higher priority can get attention */
    // osalSysUnlock();

    /* wait until the bus is released */
    /* Calculating the time window for the timeout on the busy bus condition.*/
    // start = osalOsGetSystemTimeX();
    // end = start + OSAL_MS2ST(NUMICRO_I2C_BUSY_TIMEOUT);
    // i2cp->i2c->I2CTOC =  I2C_I2CTOC_ENTI_Msk | I2C_I2CTOC_DIV4_Msk | I2C_I2CTOC_TIF_Msk;
    // i2cp->i2c->I2CON |=  I2C_I2CON_STA_SI;
    uint8_t status = (uint8_t)(I2C_GET_STATUS(i2cp->i2c));
    if (status == 0x08 || status == 0x10) {
      i2cp->is_master = 1;
      // uint8_t op = (i2cp->intstate == STATE_SEND) ? 0 : 1;
      // i2cp->i2c->I2CDAT = (i2cp->addr << 1) | op;
      // i2c->I2CON |= I2C_I2CON_SI;
      // I2C_SET_I2CON(i2cp->i2c, I2C_I2CON_SI);
      I2C_EnableInt(i2cp->i2c);
    } else {
      // I2C_SET_I2CON(i2cp->i2c, I2C_I2CON_STA_SI);
      I2C_Trigger(i2cp->i2c, /* Start */ 1, /* Stop */ 0, /* SI */ 1, /* Ack */ 0);
    }
  }

  /* send slave address */
  // i2cp->i2c->I2CDAT = addr << 1 | op;

  /* wait for the ISR to signal that the transmission (or receive if no transmission) phase is complete */

  msg = osalThreadSuspendTimeoutS(&i2cp->thread, timeout);
  i2cp->is_master = 0;

  // i2cp->i2c->I2CTOC =  /* I2C_I2CTOC_ENTI_Msk | I2C_I2CTOC_DIV4_Msk | */ I2C_I2CTOC_TIF_Msk;
  I2C_ClearTimeoutFlag(i2cp->i2c);

  // osalSysUnlock();
  // wait_us(1);
  // osalSysLock();

  /* FIXME */
  //if (i2cp->i2c->S & I2Cx_S_RXAK)
  //  i2cp->errors |= I2C_ACK_FAILURE;

#if 0
  /* the transmitting (or receiving if no transmission) phase has finished,
   * do we expect to receive something? */
  if (msg == MSG_OK && rxbuf != NULL && rxbytes > 0 && i2cp->rxidx < rxbytes) {

    /* send repeated start */
    i2cp->i2c->C1 |= I2Cx_C1_RSTA;

    /* FIXME */
    // while (!(i2cp->i2c->S & I2Cx_S_BUSY));

    i2cp->intstate = STATE_RECV;
    i2cp->i2c->D = i2cp->addr << 1 | 1;

    msg = osalThreadSuspendTimeoutS(&i2cp->thread, timeout);
  }
#endif

  /* release bus - RX mode, send STOP */
  // other kinetis I2C drivers wait here for 1us. is this needed?
  // i2cp->i2c->C1 &= ~(I2Cx_C1_TX | I2Cx_C1_MST);
  /* FIXME */
  // while (i2cp->i2c->S & I2Cx_S_BUSY);

  return msg;
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
                                     systime_t timeout) {

  i2cp->intstate = STATE_RECV;
  return _i2c_txrx_timeout(i2cp, addr, NULL, 0, rxbuf, rxbytes, timeout);
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
                                      systime_t timeout) {

  i2cp->intstate = STATE_SEND;
  return _i2c_txrx_timeout(i2cp, addr, txbuf, txbytes, rxbuf, rxbytes, timeout);
}

#endif /* HAL_USE_I2C */

/** @} */
