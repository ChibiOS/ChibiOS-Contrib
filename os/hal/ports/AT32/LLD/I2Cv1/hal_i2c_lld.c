/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian

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

/*
   Concepts and parts of this file have been contributed by Uladzimir Pylinsky
   aka barthess.
 */

/**
 * @file    I2Cv1/hal_i2c_lld.c
 * @brief   AT32 I2C subsystem low level driver source.
 *
 * @addtogroup I2C
 * @{
 */

#include "hal.h"

#if HAL_USE_I2C || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#define I2C_EV5_MASTER_MODE_SELECT                                            \
  ((uint32_t)(((I2C_STS2_TRMODE | I2C_STS2_BUSYF) << 16) | I2C_STS1_STARTF))

#define I2C_EV5_MASTER_MODE_SELECT_NO_BUSY                                    \
  ((uint32_t)((I2C_STS2_TRMODE << 16) | I2C_STS1_STARTF))

#define I2C_EV6_MASTER_TRA_MODE_SELECTED                                      \
  ((uint32_t)(((I2C_STS2_TRMODE | I2C_STS2_BUSYF | I2C_STS2_DIRF) << 16) |    \
              I2C_STS1_ADDR7F | I2C_STS1_TDBE))

#define I2C_EV6_MASTER_REC_MODE_SELECTED                                      \
  ((uint32_t)(((I2C_STS2_TRMODE | I2C_STS2_BUSYF) << 16) | I2C_STS1_ADDR7F))

#define I2C_EV8_2_MASTER_BYTE_TRANSMITTED                                     \
  ((uint32_t)(((I2C_STS2_TRMODE | I2C_STS2_BUSYF | I2C_STS2_DIRF) << 16) |    \
              I2C_STS1_TDC | I2C_STS1_TDBE))

#define I2C_EV9_MASTER_ADD10                                                  \
  ((uint32_t)(((I2C_STS2_TRMODE | I2C_STS2_BUSYF) << 16) | I2C_STS1_ADDRHF))

#define I2C_EV5_MASTER_MODE_INVALID                                           \
  ((uint32_t)(((I2C_STS2_TRMODE | I2C_STS2_BUSYF) << 16) | (I2C_STS1_STARTF | \
              I2C_STS1_STOPF)))

#define I2C_EV_MASK 0x00FF00FF

#define I2C_ERROR_MASK                                                        \
  ((uint16_t)(I2C_STS1_BUSERR | I2C_STS1_ARLOST | I2C_STS1_ACKFAIL |          \
              I2C_STS1_OUF | I2C_STS1_PECERR | I2C_STS1_TMOUT |               \
              I2C_STS1_ALERTF))
 
/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief I2C1 driver identifier.*/
#if AT32_I2C_USE_I2C1 || defined(__DOXYGEN__)
I2CDriver I2CD1;
#endif

/** @brief I2C2 driver identifier.*/
#if AT32_I2C_USE_I2C2 || defined(__DOXYGEN__)
I2CDriver I2CD2;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Aborts an I2C transaction.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
static void i2c_lld_abort_operation(I2CDriver *i2cp) {
  I2C_TypeDef *dp = i2cp->i2c;

  /* Stops the I2C peripheral.*/
  dp->CTRL1 = I2C_CTRL1_RESET;
  dp->CTRL1 = 0;
  dp->CTRL2 = 0;
  dp->STS1  = 0;

  /* Stops the associated DMA streams.*/
  dmaStreamDisable(i2cp->dmatx);
  dmaStreamDisable(i2cp->dmarx);
}

/**
 * @brief   Set clock speed.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
static void i2c_lld_set_clock(I2CDriver *i2cp) {
  I2C_TypeDef *dp = i2cp->i2c;
  uint16_t regCLKCTRL, clock_div;
  int32_t clock_speed = i2cp->config->clock_speed;
  i2cdutycycle_t duty = i2cp->config->duty_cycle;

  osalDbgCheck((i2cp != NULL) &&
               (clock_speed > 0) &&
               (clock_speed <= 400000));

  /* CTRL2 Configuration.*/
  dp->CTRL2 &= (uint16_t)~I2C_CTRL2_CLKFREQ;
  dp->CTRL2 |= (uint16_t)I2C_CLK_FREQ;

  /* CLKCTRL Configuration.*/
  regCLKCTRL = 0;
  clock_div = I2C_CLKCTRL_SPEED;

  if (clock_speed <= 100000) {
    /* Configure clock_div in standard mode.*/
    osalDbgAssert(duty == STD_DUTY_CYCLE, "invalid standard mode duty cycle");

    /* Standard mode clock_div calculate: Tlow/Thigh = 1/1.*/
    osalDbgAssert((AT32_PCLK1 % (clock_speed * 2)) == 0,
                  "PCLK1 must be divisible without remainder");
    clock_div = (uint16_t)(AT32_PCLK1 / (clock_speed * 2));

    osalDbgAssert(clock_div >= 0x04,
                  "clock divider less then 0x04 not allowed");
    regCLKCTRL |= (clock_div & I2C_CLKCTRL_SPEED);

    /* Sets the Maximum Rise Time for standard mode.*/
    dp->TMRISE = I2C_CLK_FREQ + 1;
  }
  else if (clock_speed <= 400000) {
    /* Configure clock_div in fast mode.*/
    osalDbgAssert((duty == FAST_DUTY_CYCLE_2) ||
                  (duty == FAST_DUTY_CYCLE_16_9),
                  "invalid fast mode duty cycle");

    if (duty == FAST_DUTY_CYCLE_2) {
      /* Fast mode clock_div calculate: Tlow/Thigh = 2/1.*/
      osalDbgAssert((AT32_PCLK1 % (clock_speed * 3)) == 0,
                    "PCLK1 must be divided without remainder");
      clock_div = (uint16_t)(AT32_PCLK1 / (clock_speed * 3));
    }
    else if (duty == FAST_DUTY_CYCLE_16_9) {
      /* Fast mode clock_div calculate: Tlow/Thigh = 16/9.*/
      osalDbgAssert((AT32_PCLK1 % (clock_speed * 25)) == 0,
                    "PCLK1 must be divided without remainder");
      clock_div = (uint16_t)(AT32_PCLK1 / (clock_speed * 25));
      regCLKCTRL |= I2C_CLKCTRL_DUTYMODE;
    }

    osalDbgAssert(clock_div >= 0x01,
                  "clock divider less then 0x04 not allowed");
    regCLKCTRL |= (I2C_CLKCTRL_SPEEDMODE | (clock_div & I2C_CLKCTRL_SPEED));

    /* Sets the Maximum Rise Time for fast mode.*/
    dp->TMRISE = (I2C_CLK_FREQ * 300 / 1000) + 1;
  }

  osalDbgAssert((clock_div <= I2C_CLKCTRL_SPEED), "the selected clock is too low");

  dp->CLKCTRL = regCLKCTRL;
}

/**
 * @brief   Set operation mode of I2C hardware.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
static void i2c_lld_set_opmode(I2CDriver *i2cp) {
  I2C_TypeDef *dp = i2cp->i2c;
  i2copmode_t opmode = i2cp->config->op_mode;
  uint16_t regCTRL1;

  regCTRL1 = dp->CTRL1;
  switch (opmode) {
  case OPMODE_I2C:
    regCTRL1 &= (uint16_t)~(I2C_CTRL1_PERMODE|I2C_CTRL1_SMBMODE);
    break;
  case OPMODE_SMBUS_DEVICE:
    regCTRL1 |= I2C_CTRL1_PERMODE;
    regCTRL1 &= (uint16_t)~(I2C_CTRL1_SMBMODE);
    break;
  case OPMODE_SMBUS_HOST:
    regCTRL1 |= (I2C_CTRL1_PERMODE|I2C_CTRL1_SMBMODE);
    break;
  }
  dp->CTRL1 = regCTRL1;
}

/**
 * @brief   I2C shared ISR code.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
static void i2c_lld_serve_event_interrupt(I2CDriver *i2cp) {
  I2C_TypeDef *dp = i2cp->i2c;
  uint32_t regSTS2 = dp->STS2;
  uint32_t event = dp->STS1;

  /* Interrupts are disabled just before dmaStreamEnable() because there
     is no need of interrupts until next transaction begin. All the work is
     done by the DMA.*/
  switch (I2C_EV_MASK & (event | (regSTS2 << 16))) {
  case I2C_EV5_MASTER_MODE_SELECT:
  case I2C_EV5_MASTER_MODE_SELECT_NO_BUSY:
    if ((i2cp->addr >> 8) > 0) {
      /* 10-bit address: 1 1 1 1 0 X X R/W */
      dp->DT = 0xF0 | (0x6 & (i2cp->addr >> 8)) | (0x1 & i2cp->addr);
    } else {
      dp->DT = i2cp->addr;
    }
    break;
  case I2C_EV9_MASTER_ADD10:
    /* Set second addr byte (10-bit addressing)*/
    dp->DT = (0xFF & (i2cp->addr >> 1));
    break;
  case I2C_EV6_MASTER_REC_MODE_SELECTED:
    dp->CTRL2 &= ~I2C_CTRL2_EVTIEN;
    dmaStreamEnable(i2cp->dmarx);
    dp->CTRL2 |= I2C_CTRL2_DMAEND;           /* Needed in receiver mode. */
    if (dmaStreamGetTransactionSize(i2cp->dmarx) < 2)
      dp->CTRL1 &= ~I2C_CTRL1_ACKEN;
    break;
  case I2C_EV6_MASTER_TRA_MODE_SELECTED:
    dp->CTRL2 &= ~I2C_CTRL2_EVTIEN;
    dmaStreamEnable(i2cp->dmatx);
    break;
  case I2C_EV8_2_MASTER_BYTE_TRANSMITTED:
    /* Catches TDC event after the end of transmission.*/
    (void)dp->DT; /* Clear TDC.*/
    if (dmaStreamGetTransactionSize(i2cp->dmarx) > 0) {
      /* Starts "read after write" operation, LSB = 1 -> receive.*/
      i2cp->addr |= 0x01;
      dp->CTRL1 |= I2C_CTRL1_GENSTART | I2C_CTRL1_ACKEN;
      return;
    }
    dp->CTRL2 &= ~I2C_CTRL2_EVTIEN;
    dp->CTRL1 |= I2C_CTRL1_GENSTOP;
    _i2c_wakeup_isr(i2cp);
    break;
  case I2C_EV5_MASTER_MODE_INVALID:
    i2c_lld_abort_operation(i2cp);
    dp->CTRL2 &= ~I2C_CTRL2_EVTIEN;
    break;
  default:
    break;
  }
  /* Clear ADDR7F flag. */
  if (event & (I2C_STS1_ADDR7F | I2C_STS1_ADDRHF))
    (void)dp->STS2;
}

/**
 * @brief   DMA RX end IRQ handler.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 * @param[in] flags     pre-shifted content of the ISR register
 *
 * @notapi
 */
static void i2c_lld_serve_rx_end_irq(I2CDriver *i2cp, uint32_t flags) {
  I2C_TypeDef *dp = i2cp->i2c;

  /* DMA errors handling.*/
#if defined(AT32_I2C_DMA_ERROR_HOOK)
  if ((flags & AT32_DMA_STS_DTERRF) != 0) {
    AT32_I2C_DMA_ERROR_HOOK(i2cp);
  }
#else
  (void)flags;
#endif

  dmaStreamDisable(i2cp->dmarx);

  dp->CTRL2 &= ~I2C_CTRL2_DMAEND;
  dp->CTRL1 &= ~I2C_CTRL1_ACKEN;
  dp->CTRL1 |= I2C_CTRL1_GENSTOP;
  _i2c_wakeup_isr(i2cp);
}

/**
 * @brief    DMA TX end IRQ handler.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
static void i2c_lld_serve_tx_end_irq(I2CDriver *i2cp, uint32_t flags) {
  I2C_TypeDef *dp = i2cp->i2c;

  /* DMA errors handling.*/
#if defined(AT32_I2C_DMA_ERROR_HOOK)
  if ((flags & AT32_DMA_STS_DTERRF) != 0) {
    AT32_I2C_DMA_ERROR_HOOK(i2cp);
  }
#else
  (void)flags;
#endif

  dmaStreamDisable(i2cp->dmatx);
  /* Enables interrupts to catch BTF event meaning transmission part complete.
     Interrupt handler will decide to generate GENSTOP or to begin receiving
     part of R/W transaction itself.*/
  dp->CTRL2 |= I2C_CTRL2_EVTIEN;
}

/**
 * @brief   I2C error handler.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 * @param[in] sts       content of the STS1 register to be decoded
 *
 * @notapi
 */
static void i2c_lld_serve_error_interrupt(I2CDriver *i2cp, uint16_t sts) {

  /* Clears interrupt flags just to be safe.*/
  dmaStreamDisable(i2cp->dmatx);
  dmaStreamDisable(i2cp->dmarx);

  i2cp->errors = I2C_NO_ERROR;

  if (sts & I2C_STS1_BUSERR) {                      /* Bus error.           */
    i2cp->errors |= I2C_BUS_ERROR;
  }

  if (sts & I2C_STS1_ARLOST)                        /* Arbitration lost.    */
    i2cp->errors |= I2C_ARBITRATION_LOST;

  if (sts & I2C_STS1_ACKFAIL) {                     /* Acknowledge failure. */
    i2cp->i2c->CTRL2 &= ~I2C_CTRL2_EVTIEN;
    i2cp->i2c->CTRL1 |= I2C_CTRL1_GENSTOP;          /* Generate stop.       */
    i2cp->errors |= I2C_ACK_FAILURE;
  }

  if (sts & I2C_STS1_OUF)                           /* Overload.            */
    i2cp->errors |= I2C_OVERRUN;

  if (sts & I2C_STS1_TMOUT)                         /* SMBus timeout.       */
    i2cp->errors |= I2C_TIMEOUT;

  if (sts & I2C_STS1_PECERR)                        /* PEC receive error.   */
    i2cp->errors |= I2C_PEC_ERROR;

  if (sts & I2C_STS1_ALERTF)                        /* SMBus alert.         */
    i2cp->errors |= I2C_SMB_ALERT;

  /* If some error has been identified then sends wakes the waiting thread.*/
  if (i2cp->errors != I2C_NO_ERROR)
    _i2c_wakeup_error_isr(i2cp);
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if AT32_I2C_USE_I2C1 || defined(__DOXYGEN__)
/**
 * @brief   I2C1 event interrupt handler.
 *
 * @notapi
 */
OSAL_IRQ_HANDLER(AT32_I2C1_EVENT_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  i2c_lld_serve_event_interrupt(&I2CD1);

  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   I2C1 error interrupt handler.
 */
OSAL_IRQ_HANDLER(AT32_I2C1_ERROR_HANDLER) {
  uint16_t sts = I2CD1.i2c->STS1;

  OSAL_IRQ_PROLOGUE();

  I2CD1.i2c->STS1 = ~(sts & I2C_ERROR_MASK);
  i2c_lld_serve_error_interrupt(&I2CD1, sts);

  OSAL_IRQ_EPILOGUE();
}
#endif /* AT32_I2C_USE_I2C1 */

#if AT32_I2C_USE_I2C2 || defined(__DOXYGEN__)
/**
 * @brief   I2C2 event interrupt handler.
 *
 * @notapi
 */
OSAL_IRQ_HANDLER(AT32_I2C2_EVENT_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  i2c_lld_serve_event_interrupt(&I2CD2);

  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   I2C2 error interrupt handler.
 *
 * @notapi
 */
OSAL_IRQ_HANDLER(AT32_I2C2_ERROR_HANDLER) {
  uint16_t sts = I2CD2.i2c->STS1;

  OSAL_IRQ_PROLOGUE();

  I2CD2.i2c->STS1 = ~(sts & I2C_ERROR_MASK);
  i2c_lld_serve_error_interrupt(&I2CD2, sts);

  OSAL_IRQ_EPILOGUE();
}
#endif /* AT32_I2C_USE_I2C2 */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level I2C driver initialization.
 *
 * @notapi
 */
void i2c_lld_init(void) {

#if AT32_I2C_USE_I2C1
  i2cObjectInit(&I2CD1);
  I2CD1.thread = NULL;
  I2CD1.i2c    = I2C1;
  I2CD1.dmarx  = NULL;
  I2CD1.dmatx  = NULL;
#endif /* AT32_I2C_USE_I2C1 */

#if AT32_I2C_USE_I2C2
  i2cObjectInit(&I2CD2);
  I2CD2.thread = NULL;
  I2CD2.i2c    = I2C2;
  I2CD2.dmarx  = NULL;
  I2CD2.dmatx  = NULL;
#endif /* AT32_I2C_USE_I2C2 */
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

  /* If in stopped state then enables the I2C and DMA clocks.*/
  if (i2cp->state == I2C_STOP) {

    i2cp->txdmamode = AT32_DMA_CCTRL_PWIDTH_BYTE | AT32_DMA_CCTRL_MWIDTH_BYTE |
                      AT32_DMA_CCTRL_MINCM       | AT32_DMA_CCTRL_DTERRIEN    |
                      AT32_DMA_CCTRL_FDTIEN      | AT32_DMA_CCTRL_DTD_M2P;
    i2cp->rxdmamode = AT32_DMA_CCTRL_PWIDTH_BYTE | AT32_DMA_CCTRL_MWIDTH_BYTE |
                      AT32_DMA_CCTRL_MINCM       | AT32_DMA_CCTRL_DTERRIEN    |
                      AT32_DMA_CCTRL_FDTIEN      | AT32_DMA_CCTRL_DTD_P2M;

#if AT32_I2C_USE_I2C1
    if (&I2CD1 == i2cp) {
      crmResetI2C1();

      i2cp->dmarx = dmaStreamAllocI(AT32_I2C_I2C1_RX_DMA_STREAM,
                                    AT32_I2C_I2C1_IRQ_PRIORITY,
                                    (at32_dmasts_t)i2c_lld_serve_rx_end_irq,
                                    (void *)i2cp);
      osalDbgAssert(i2cp->dmarx != NULL, "unable to allocate stream");
      i2cp->dmatx = dmaStreamAllocI(AT32_I2C_I2C1_TX_DMA_STREAM,
                                    AT32_I2C_I2C1_IRQ_PRIORITY,
                                    (at32_dmasts_t)i2c_lld_serve_tx_end_irq,
                                    (void *)i2cp);
      osalDbgAssert(i2cp->dmatx != NULL, "unable to allocate stream");

#if AT32_DMA_SUPPORTS_DMAMUX
      dmaSetRequestSource(i2cp->dmarx, AT32_I2C_I2C1_RX_DMAMUX_CHANNEL, AT32_DMAMUX_I2C1_RX);
      dmaSetRequestSource(i2cp->dmatx, AT32_I2C_I2C1_TX_DMAMUX_CHANNEL, AT32_DMAMUX_I2C1_TX);
#endif

      crmEnableI2C1(true);
      nvicEnableVector(I2C1_EVT_IRQn, AT32_I2C_I2C1_IRQ_PRIORITY);
      nvicEnableVector(I2C1_ERR_IRQn, AT32_I2C_I2C1_IRQ_PRIORITY);

      i2cp->rxdmamode |= AT32_DMA_CCTRL_CHPL(AT32_I2C_I2C1_DMA_PRIORITY);
      i2cp->txdmamode |= AT32_DMA_CCTRL_CHPL(AT32_I2C_I2C1_DMA_PRIORITY);
    }
#endif /* AT32_I2C_USE_I2C1 */

#if AT32_I2C_USE_I2C2
    if (&I2CD2 == i2cp) {
      crmResetI2C2();

      i2cp->dmarx = dmaStreamAllocI(AT32_I2C_I2C2_RX_DMA_STREAM,
                                    AT32_I2C_I2C2_IRQ_PRIORITY,
                                    (at32_dmasts_t)i2c_lld_serve_rx_end_irq,
                                    (void *)i2cp);
      osalDbgAssert(i2cp->dmarx != NULL, "unable to allocate stream");
      i2cp->dmatx = dmaStreamAllocI(AT32_I2C_I2C2_TX_DMA_STREAM,
                                    AT32_I2C_I2C2_IRQ_PRIORITY,
                                    (at32_dmasts_t)i2c_lld_serve_tx_end_irq,
                                    (void *)i2cp);
      osalDbgAssert(i2cp->dmatx != NULL, "unable to allocate stream");

#if AT32_DMA_SUPPORTS_DMAMUX
      dmaSetRequestSource(i2cp->dmarx, AT32_I2C_I2C2_RX_DMAMUX_CHANNEL, AT32_DMAMUX_I2C2_RX);
      dmaSetRequestSource(i2cp->dmatx, AT32_I2C_I2C2_TX_DMAMUX_CHANNEL, AT32_DMAMUX_I2C2_TX);
#endif

      crmEnableI2C2(true);
      nvicEnableVector(I2C2_EVT_IRQn, AT32_I2C_I2C2_IRQ_PRIORITY);
      nvicEnableVector(I2C2_ERR_IRQn, AT32_I2C_I2C2_IRQ_PRIORITY);

      i2cp->rxdmamode |= AT32_DMA_CCTRL_CHPL(AT32_I2C_I2C2_DMA_PRIORITY);
      i2cp->txdmamode |= AT32_DMA_CCTRL_CHPL(AT32_I2C_I2C2_DMA_PRIORITY);
    }
#endif /* AT32_I2C_USE_I2C2 */
  }

  /* I2C registers pointed by the DMA.*/
  dmaStreamSetPeripheral(i2cp->dmarx, &dp->DT);
  dmaStreamSetPeripheral(i2cp->dmatx, &dp->DT);

  /* Reset i2c peripheral.*/
  dp->CTRL1 = I2C_CTRL1_RESET;
  dp->CTRL1 = 0;
  dp->CTRL2 = I2C_CTRL2_ERRIEN | I2C_CTRL2_DMAEN;

  /* Setup I2C parameters.*/
  i2c_lld_set_clock(i2cp);
  i2c_lld_set_opmode(i2cp);

  /* Ready to go.*/
  dp->CTRL1 |= I2C_CTRL1_I2CEN;
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

    /* I2C disable.*/
    i2c_lld_abort_operation(i2cp);
    dmaStreamFreeI(i2cp->dmatx);
    dmaStreamFreeI(i2cp->dmarx);
    i2cp->dmatx = NULL;
    i2cp->dmarx = NULL;

#if AT32_I2C_USE_I2C1
    if (&I2CD1 == i2cp) {
      nvicDisableVector(I2C1_EVT_IRQn);
      nvicDisableVector(I2C1_ERR_IRQn);
      crmDisableI2C1();
    }
#endif

#if AT32_I2C_USE_I2C2
    if (&I2CD2 == i2cp) {
      nvicDisableVector(I2C2_EVT_IRQn);
      nvicDisableVector(I2C2_ERR_IRQn);
      crmDisableI2C2();
    }
#endif
  }
}

/**
 * @brief   Receives data via the I2C bus as master.
 * @details Number of receiving bytes must be more than 1. This is hardware
 *          restriction.
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
  systime_t start, end;
  msg_t msg;

  osalDbgCheck(rxbytes > 1);

  /* Resetting error flags for this transfer.*/
  i2cp->errors = I2C_NO_ERROR;

  /* Initializes driver fields, LSB = 1 -> receive.*/
  i2cp->addr = (addr << 1) | 0x01;

  /* Releases the lock from high level driver.*/
  osalSysUnlock();

  /* RX DMA setup.*/
  dmaStreamSetMode(i2cp->dmarx, i2cp->rxdmamode);
  dmaStreamSetMemory0(i2cp->dmarx, rxbuf);
  dmaStreamSetTransactionSize(i2cp->dmarx, rxbytes);

  /* Calculating the time window for the timeout on the busy bus condition.*/
  start = osalOsGetSystemTimeX();
  end = osalTimeAddX(start, OSAL_MS2I(AT32_I2C_BUSY_TIMEOUT));

  /* Waits until BUSY flag is reset or, alternatively, for a timeout
     condition.*/
  while (true) {
    osalSysLock();

    /* If the bus is not busy then the operation can continue, note, the
       loop is exited in the locked state.*/
    if (!(dp->STS2 & I2C_STS2_BUSYF) && !(dp->CTRL1 & I2C_CTRL1_GENSTOP))
      break;

    /* If the system time went outside the allowed window then a timeout
       condition is returned.*/
    if (!osalTimeIsInRangeX(osalOsGetSystemTimeX(), start, end)) {
      dmaStreamDisable(i2cp->dmarx);
      return MSG_TIMEOUT;
    }

    osalSysUnlock();
  }

  /* Starts the operation.*/
  dp->CTRL2 |= I2C_CTRL2_EVTIEN;
  dp->CTRL1 |= I2C_CTRL1_GENSTART | I2C_CTRL1_ACKEN;

  /* Waits for the operation completion or a timeout.*/
  msg = osalThreadSuspendTimeoutS(&i2cp->thread, timeout);
  if (msg != MSG_OK) {
    dmaStreamDisable(i2cp->dmarx);
  }

  return msg;
}

/**
 * @brief   Transmits data via the I2C bus as master.
 * @details Number of receiving bytes must be 0 or more than 1.
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
  I2C_TypeDef *dp = i2cp->i2c;
  systime_t start, end;
  msg_t msg;

  osalDbgCheck((rxbytes == 0) || ((rxbytes > 1) && (rxbuf != NULL)));

  /* Resetting error flags for this transfer.*/
  i2cp->errors = I2C_NO_ERROR;

  /* Initializes driver fields, LSB = 0 -> transmit.*/
  i2cp->addr = (addr << 1);

  /* Releases the lock from high level driver.*/
  osalSysUnlock();

  /* TX DMA setup.*/
  dmaStreamSetMode(i2cp->dmatx, i2cp->txdmamode);
  dmaStreamSetMemory0(i2cp->dmatx, txbuf);
  dmaStreamSetTransactionSize(i2cp->dmatx, txbytes);

  /* RX DMA setup.*/
  dmaStreamSetMode(i2cp->dmarx, i2cp->rxdmamode);
  dmaStreamSetMemory0(i2cp->dmarx, rxbuf);
  dmaStreamSetTransactionSize(i2cp->dmarx, rxbytes);

  /* Calculating the time window for the timeout on the busy bus condition.*/
  start = osalOsGetSystemTimeX();
  end = osalTimeAddX(start, OSAL_MS2I(AT32_I2C_BUSY_TIMEOUT));

  /* Waits until BUSY flag is reset or, alternatively, for a timeout
     condition.*/
  while (true) {
    osalSysLock();

    /* If the bus is not busy then the operation can continue, note, the
       loop is exited in the locked state.*/
    if (!(dp->STS2 & I2C_STS2_BUSYF) && !(dp->CTRL1 & I2C_CTRL1_GENSTOP))
      break;

    /* If the system time went outside the allowed window then a timeout
       condition is returned.*/
    if (!osalTimeIsInRangeX(osalOsGetSystemTimeX(), start, end)) {
      dmaStreamDisable(i2cp->dmatx);
      dmaStreamDisable(i2cp->dmarx);
      return MSG_TIMEOUT;
    }

    osalSysUnlock();
  }

  /* Starts the operation.*/
  dp->CTRL2 |= I2C_CTRL2_EVTIEN;
  dp->CTRL1 |= I2C_CTRL1_GENSTART;

  /* Waits for the operation completion or a timeout.*/
  msg = osalThreadSuspendTimeoutS(&i2cp->thread, timeout);
  if (msg != MSG_OK) {
    dmaStreamDisable(i2cp->dmatx);
    dmaStreamDisable(i2cp->dmarx);
  }

  return msg;
}

#endif /* HAL_USE_I2C */

/** @} */
