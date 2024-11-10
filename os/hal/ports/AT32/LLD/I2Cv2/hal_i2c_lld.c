/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 Maxjta

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
 * @file    I2Cv2/hal_i2c_lld.c
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

#if AT32_I2C_USE_DMA == TRUE
#define DMAMODE_COMMON                                                      \
  (AT32_DMA_CTRL_PWIDTH_BYTE | AT32_DMA_CTRL_MWIDTH_BYTE |                  \
   AT32_DMA_CTRL_MINCM       | AT32_DMA_CTRL_DMERRIEN    |                  \
   AT32_DMA_CTRL_DTERRIEN    | AT32_DMA_CTRL_FDTIEN)

#define I2C1_RX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_I2C_I2C1_RX_DMA_STREAM,                          \
                       AT32_I2C1_RX_DMA_CHN)

#define I2C1_TX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_I2C_I2C1_TX_DMA_STREAM,                          \
                       AT32_I2C1_TX_DMA_CHN)

#define I2C2_RX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_I2C_I2C2_RX_DMA_STREAM,                          \
                       AT32_I2C2_RX_DMA_CHN)

#define I2C2_TX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_I2C_I2C2_TX_DMA_STREAM,                          \
                       AT32_I2C2_TX_DMA_CHN)

#define I2C3_RX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_I2C_I2C3_RX_DMA_STREAM,                          \
                       AT32_I2C3_RX_DMA_CHN)

#define I2C3_TX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_I2C_I2C3_TX_DMA_STREAM,                          \
                       AT32_I2C3_TX_DMA_CHN)

#define I2C4_RX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_I2C_I2C4_RX_DMA_STREAM,                          \
                       AT32_I2C4_RX_DMA_CHN)

#define I2C4_TX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_I2C_I2C4_TX_DMA_STREAM,                          \
                       AT32_I2C4_TX_DMA_CHN)
#endif /* AT32_I2C_USE_DMA == TRUE */

#if AT32_I2C_USE_DMA == TRUE
#define i2c_lld_get_rxbytes(i2cp) dmaStreamGetTransactionSize((i2cp)->dmarx)
#define i2c_lld_get_txbytes(i2cp) dmaStreamGetTransactionSize((i2cp)->dmatx)
#else
#define i2c_lld_get_rxbytes(i2cp) (i2cp)->rxbytes
#define i2c_lld_get_txbytes(i2cp) (i2cp)->txbytes
#endif

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#define I2C_ERROR_MASK                                                          \
  ((uint32_t)(I2C_STS_BUSERR | I2C_STS_ARLOST | I2C_STS_OUF | I2C_STS_PECERR |  \
              I2C_STS_TMOUT  | I2C_STS_ALERTF))

#define I2C_INT_MASK                                                            \
  ((uint32_t)(I2C_STS_TCRLD | I2C_STS_TDC  | I2C_STS_STOPF | I2C_STS_ACKFAILF | \
              I2C_STS_ADDRF | I2C_STS_RDBF | I2C_STS_TDIS))

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

/** @brief I2C3 driver identifier.*/
#if AT32_I2C_USE_I2C3 || defined(__DOXYGEN__)
I2CDriver I2CD3;
#endif

/** @brief I2C4 driver identifier.*/
#if AT32_I2C_USE_I2C4 || defined(__DOXYGEN__)
I2CDriver I2CD4;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Slave address setup.
 * @note    The RW bit is set to zero internally.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 * @param[in] addr      slave device address
 *
 * @notapi
 */
static void i2c_lld_set_address(I2CDriver *i2cp, i2caddr_t addr) {
  I2C_TypeDef *dp = i2cp->i2c;

  /* Address alignment depends on the addressing mode selected.*/
  if ((i2cp->config->ctrl2 & I2C_CTRL2_ADDR10) == 0U)
    dp->CTRL2 = (uint32_t)addr << 1U;
  else
    dp->CTRL2 = (uint32_t)addr;
}

/**
 * @brief   I2C RX transfer setup.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
static void i2c_lld_setup_rx_transfer(I2CDriver *i2cp) {
  I2C_TypeDef *dp = i2cp->i2c;
  uint32_t rlden;
  size_t n;

  /* The unit can transfer 255 bytes maximum in a single operation.*/
  n = i2c_lld_get_rxbytes(i2cp);
  if (n > 255U) {
    n = 255U;
    rlden = I2C_CTRL2_RLDEN;
  }
  else {
    rlden = 0U;
  }

  /* Configures the CTRL2 registers with both the calculated and static
     settings.*/
  dp->CTRL2 = (dp->CTRL2 & ~(I2C_CTRL2_CNT_MASK | I2C_CTRL2_RLDEN)) | i2cp->config->ctrl2 |
               I2C_CTRL2_DIR | (n << 16U) | rlden;
}

/**
 * @brief   I2C TX transfer setup.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
static void i2c_lld_setup_tx_transfer(I2CDriver *i2cp) {
  I2C_TypeDef *dp = i2cp->i2c;
  uint32_t rlden;
  size_t n;

  /* The unit can transfer 255 bytes maximum in a single operation.*/
  n = i2c_lld_get_txbytes(i2cp);
  if (n > 255U) {
    n = 255U;
    rlden = I2C_CTRL2_RLDEN;
  } else {
    rlden = 0U;
  }

  /* Configures the CTRL2 registers with both the calculated and static
     settings.*/
  dp->CTRL2 = (dp->CTRL2 & ~(I2C_CTRL2_CNT_MASK | I2C_CTRL2_RLDEN)) | i2cp->config->ctrl2 |
               (n << 16U) | rlden;
}

/**
 * @brief   Aborts an I2C transaction.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
static void i2c_lld_abort_operation(I2CDriver *i2cp) {
  I2C_TypeDef *dp = i2cp->i2c;

  if (dp->CTRL1 & I2C_CTRL1_I2CEN) {
    /* Stops the I2C peripheral.*/
    dp->CTRL1 &= ~I2C_CTRL1_I2CEN;
    while (dp->CTRL1 & I2C_CTRL1_I2CEN)
      dp->CTRL1 &= ~I2C_CTRL1_I2CEN;
    dp->CTRL1 |= I2C_CTRL1_I2CEN;
  }

#if AT32_I2C_USE_DMA == TRUE
  /* Stops the associated DMA streams.*/
  dmaStreamDisable(i2cp->dmatx);
  dmaStreamDisable(i2cp->dmarx);
#else
  dp->CTRL1 &= ~(I2C_CTRL1_TDIEN | I2C_CTRL1_RDIEN);
#endif
}

/**
 * @brief   I2C shared ISR code.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 * @param[in] sts       content of the STS register to be decoded
 *
 * @notapi
 */
static void i2c_lld_serve_interrupt(I2CDriver *i2cp, uint32_t sts) {
  I2C_TypeDef *dp = i2cp->i2c;

  /* Special case of a received NACK, the transfer is aborted.*/
  if ((sts & I2C_STS_ACKFAILF) != 0U) {
#if AT32_I2C_USE_DMA == TRUE
    /* Stops the associated DMA streams.*/
    dmaStreamDisable(i2cp->dmatx);
    dmaStreamDisable(i2cp->dmarx);
#endif

    /* Error flag.*/
    i2cp->errors |= I2C_ACK_FAILURE;

    /* Transaction finished sending the STOP.*/
    dp->CTRL2 |= I2C_CTRL2_GENSTOP;

    /* Make sure no more interrupts.*/
    dp->CTRL1 &= ~(I2C_CTRL1_TDCIEN | I2C_CTRL1_TDIEN | I2C_CTRL1_RDIEN);

    /* Errors are signaled to the upper layer.*/
    _i2c_wakeup_error_isr(i2cp);

    return;
  }

#if AT32_I2C_USE_DMA == FALSE
  /* Handling of data transfer if the DMA mode is disabled.*/
  {
    uint32_t ctrl1 = dp->CTRL1;

    if (i2cp->state == I2C_ACTIVE_TX) {
      /* Transmission phase.*/
      if (((ctrl1 & I2C_CTRL1_TDIEN) != 0U) && ((sts & I2C_STS_TDIS) != 0U)) {
        dp->TXDT = (uint32_t)*i2cp->txptr;
        i2cp->txptr++;
        i2cp->txbytes--;
        if (i2cp->txbytes == 0U) {
          dp->CTRL1 &= ~I2C_CTRL1_TDIEN;
        }
      }
    }
    else {
      /* Receive phase.*/
      if (((ctrl1 & I2C_CTRL1_RDIEN) != 0U) && ((sts & I2C_STS_RDBF) != 0U)) {
        *i2cp->rxptr = (uint8_t)dp->RXDT;
        i2cp->rxptr++;
        i2cp->rxbytes--;
        if (i2cp->rxbytes == 0U) {
          dp->CTRL1 &= ~I2C_CTRL1_RDIEN;
        }
      }
    }
  }
#endif

  /* Partial transfer handling, restarting the transfer and returning.*/
  if ((sts & I2C_STS_TCRLD) != 0U) {
    if (i2cp->state == I2C_ACTIVE_TX) {
      i2c_lld_setup_tx_transfer(i2cp);
    }
    else {
      i2c_lld_setup_rx_transfer(i2cp);
    }
    return;
  }

  /* The following condition is true if a transfer phase has been completed.*/
  if ((sts & I2C_STS_TDC) != 0U) {
    if (i2cp->state == I2C_ACTIVE_TX) {
      /* End of the transmit phase.*/

#if AT32_I2C_USE_DMA == TRUE
      /* Disabling TX DMA channel.*/
      dmaStreamDisable(i2cp->dmatx);
#endif

      /* Starting receive phase if necessary.*/
      if (i2c_lld_get_rxbytes(i2cp) > 0U) {
        /* Setting up the peripheral.*/
        i2c_lld_setup_rx_transfer(i2cp);

#if AT32_I2C_USE_DMA == TRUE
        /* Enabling RX DMA.*/
        dmaStreamEnable(i2cp->dmarx);
#else
        /* RX interrupt enabled.*/
        dp->CTRL1 |= I2C_CTRL1_RDIEN;
#endif

        /* Starts the read operation.*/
        dp->CTRL2 |= I2C_CTRL2_GENSTART;

        /* State change.*/
        i2cp->state = I2C_ACTIVE_RX;

        /* Note, returning because the transaction is not over yet.*/
        return;
      }
    }
    else {
      /* End of the receive phase.*/
#if AT32_I2C_USE_DMA == TRUE
      /* Disabling RX DMA channel.*/
      dmaStreamDisable(i2cp->dmarx);
#endif
    }

    /* Transaction finished sending the STOP.*/
    dp->CTRL2 |= I2C_CTRL2_GENSTOP;

    /* Make sure no more 'Transfer Complete' interrupts.*/
    dp->CTRL1 &= ~I2C_CTRL1_TDCIEN;

    /* Normal transaction end.*/
    _i2c_wakeup_isr(i2cp);
  }
}

/**
 * @brief   I2C error handler.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 * @param[in] sts       content of the STS register to be decoded
 *
 * @notapi
 */
static void i2c_lld_serve_error_interrupt(I2CDriver *i2cp, uint32_t sts) {

#if AT32_I2C_USE_DMA == TRUE
  /* Clears DMA interrupt flags just to be safe.*/
  dmaStreamDisable(i2cp->dmatx);
  dmaStreamDisable(i2cp->dmarx);
#else
  /* Disabling RX and TX interrupts.*/
  i2cp->i2c->CTRL1 &= ~(I2C_CTRL1_TDIEN | I2C_CTRL1_RDIEN);
#endif

  if (sts & I2C_STS_BUSERR)
    i2cp->errors |= I2C_BUS_ERROR;

  if (sts & I2C_STS_ARLOST)
    i2cp->errors |= I2C_ARBITRATION_LOST;

  if (sts & I2C_STS_OUF)
    i2cp->errors |= I2C_OVERRUN;

  if (sts & I2C_STS_TMOUT)
    i2cp->errors |= I2C_TIMEOUT;

  /* If some error has been identified then sends wakes the waiting thread.*/
  if (i2cp->errors != I2C_NO_ERROR)
    _i2c_wakeup_error_isr(i2cp);
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if AT32_I2C_USE_I2C1 || defined(__DOXYGEN__)
#if defined(AT32_I2C1_GLOBAL_HANDLER) || defined(__DOXYGEN__)
/**
 * @brief   I2C1 event interrupt handler.
 *
 * @notapi
 */
OSAL_IRQ_HANDLER(AT32_I2C1_GLOBAL_HANDLER) {
  uint32_t sts = I2CD1.i2c->STS;

  OSAL_IRQ_PROLOGUE();

  /* Clearing IRQ bits.*/
  I2CD1.i2c->CLR = sts;

  if (sts & I2C_ERROR_MASK)
    i2c_lld_serve_error_interrupt(&I2CD1, sts);
  else if (sts & I2C_INT_MASK)
    i2c_lld_serve_interrupt(&I2CD1, sts);

  OSAL_IRQ_EPILOGUE();
}

#elif defined(AT32_I2C1_EVENT_HANDLER) && defined(AT32_I2C1_ERROR_HANDLER)
OSAL_IRQ_HANDLER(AT32_I2C1_EVENT_HANDLER) {
  uint32_t sts = I2CD1.i2c->STS;

  OSAL_IRQ_PROLOGUE();

  /* Clearing IRQ bits.*/
  I2CD1.i2c->CLR = sts & I2C_INT_MASK;

  i2c_lld_serve_interrupt(&I2CD1, sts);

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(AT32_I2C1_ERROR_HANDLER) {
  uint32_t sts = I2CD1.i2c->STS;

  OSAL_IRQ_PROLOGUE();

  /* Clearing IRQ bits.*/
  I2CD1.i2c->CLR = sts & I2C_ERROR_MASK;

  i2c_lld_serve_error_interrupt(&I2CD1, sts);

  OSAL_IRQ_EPILOGUE();
}

#else
#error "I2C1 interrupt handlers not defined"
#endif
#endif /* AT32_I2C_USE_I2C1 */

#if AT32_I2C_USE_I2C2 || defined(__DOXYGEN__)
#if defined(AT32_I2C2_GLOBAL_HANDLER) || defined(__DOXYGEN__)
/**
 * @brief   I2C2 event interrupt handler.
 *
 * @notapi
 */
OSAL_IRQ_HANDLER(AT32_I2C2_GLOBAL_HANDLER) {
  uint32_t sts = I2CD2.i2c->STS;

  OSAL_IRQ_PROLOGUE();

  /* Clearing IRQ bits.*/
  I2CD2.i2c->CLR = sts;

  if (sts & I2C_ERROR_MASK)
    i2c_lld_serve_error_interrupt(&I2CD2, sts);
  else if (sts & I2C_INT_MASK)
    i2c_lld_serve_interrupt(&I2CD2, sts);

  OSAL_IRQ_EPILOGUE();
}

#elif defined(AT32_I2C2_EVENT_HANDLER) && defined(AT32_I2C2_ERROR_HANDLER)
OSAL_IRQ_HANDLER(AT32_I2C2_EVENT_HANDLER) {
  uint32_t sts = I2CD2.i2c->STS;

  OSAL_IRQ_PROLOGUE();

  /* Clearing IRQ bits.*/
  I2CD2.i2c->CLR = sts & I2C_INT_MASK;

  i2c_lld_serve_interrupt(&I2CD2, sts);

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(AT32_I2C2_ERROR_HANDLER) {
  uint32_t sts = I2CD2.i2c->STS;

  OSAL_IRQ_PROLOGUE();

  /* Clearing IRQ bits.*/
  I2CD2.i2c->CLR = sts & I2C_ERROR_MASK;

  i2c_lld_serve_error_interrupt(&I2CD2, sts);

  OSAL_IRQ_EPILOGUE();
}

#else
#error "I2C2 interrupt handlers not defined"
#endif
#endif /* AT32_I2C_USE_I2C2 */

#if AT32_I2C_USE_I2C3 || defined(__DOXYGEN__)
#if defined(AT32_I2C3_GLOBAL_HANDLER) || defined(__DOXYGEN__)
/**
 * @brief   I2C3 event interrupt handler.
 *
 * @notapi
 */
OSAL_IRQ_HANDLER(AT32_I2C3_GLOBAL_HANDLER) {
  uint32_t sts = I2CD3.i2c->STS;

  OSAL_IRQ_PROLOGUE();

  /* Clearing IRQ bits.*/
  I2CD3.i2c->CLR = sts;

  if (sts & I2C_ERROR_MASK)
    i2c_lld_serve_error_interrupt(&I2CD3, sts);
  else if (sts & I2C_INT_MASK)
    i2c_lld_serve_interrupt(&I2CD3, sts);

  OSAL_IRQ_EPILOGUE();
}

#elif defined(AT32_I2C3_EVENT_HANDLER) && defined(AT32_I2C3_ERROR_HANDLER)
OSAL_IRQ_HANDLER(AT32_I2C3_EVENT_HANDLER) {
  uint32_t sts = I2CD3.i2c->STS;

  OSAL_IRQ_PROLOGUE();

  /* Clearing IRQ bits.*/
  I2CD3.i2c->CLR = sts & I2C_INT_MASK;

  i2c_lld_serve_interrupt(&I2CD3, sts);

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(AT32_I2C3_ERROR_HANDLER) {
  uint32_t sts = I2CD3.i2c->STS;

  OSAL_IRQ_PROLOGUE();

  /* Clearing IRQ bits.*/
  I2CD3.i2c->CLR = sts & I2C_ERROR_MASK;

  i2c_lld_serve_error_interrupt(&I2CD3, sts);

  OSAL_IRQ_EPILOGUE();
}

#else
#error "I2C3 interrupt handlers not defined"
#endif
#endif /* AT32_I2C_USE_I2C3 */

#if AT32_I2C_USE_I2C4 || defined(__DOXYGEN__)
#if defined(AT32_I2C4_GLOBAL_HANDLER) || defined(__DOXYGEN__)
/**
 * @brief   I2C4 event interrupt handler.
 *
 * @notapi
 */
OSAL_IRQ_HANDLER(AT32_I2C4_GLOBAL_HANDLER) {
  uint32_t sts = I2CD4.i2c->STS;

  OSAL_IRQ_PROLOGUE();

  /* Clearing IRQ bits.*/
  I2CD4.i2c->CLR = sts;

  if (sts & I2C_ERROR_MASK)
    i2c_lld_serve_error_interrupt(&I2CD4, sts);
  else if (sts & I2C_INT_MASK)
    i2c_lld_serve_interrupt(&I2CD4, sts);

  OSAL_IRQ_EPILOGUE();
}

#elif defined(AT32_I2C4_EVENT_HANDLER) && defined(AT32_I2C4_ERROR_HANDLER)
OSAL_IRQ_HANDLER(AT32_I2C4_EVENT_HANDLER) {
  uint32_t sts = I2CD4.i2c->STS;

  OSAL_IRQ_PROLOGUE();

  /* Clearing IRQ bits.*/
  I2CD4.i2c->CLR = sts & I2C_INT_MASK;

  i2c_lld_serve_interrupt(&I2CD4, sts);

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(AT32_I2C4_ERROR_HANDLER) {
  uint32_t sts = I2CD4.i2c->STS;

  OSAL_IRQ_PROLOGUE();

  /* Clearing IRQ bits.*/
  I2CD4.i2c->CLR = sts & I2C_ERROR_MASK;

  i2c_lld_serve_error_interrupt(&I2CD4, sts);

  OSAL_IRQ_EPILOGUE();
}

#else
#error "I2C4 interrupt handlers not defined"
#endif
#endif /* AT32_I2C_USE_I2C4 */

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
#if AT32_I2C_USE_DMA == TRUE
  I2CD1.dmarx  = NULL;
  I2CD1.dmatx  = NULL;
#endif
#endif /* AT32_I2C_USE_I2C1 */

#if AT32_I2C_USE_I2C2
  i2cObjectInit(&I2CD2);
  I2CD2.thread = NULL;
  I2CD2.i2c    = I2C2;
#if AT32_I2C_USE_DMA == TRUE
  I2CD2.dmarx  = NULL;
  I2CD2.dmatx  = NULL;
#endif
#endif /* AT32_I2C_USE_I2C2 */

#if AT32_I2C_USE_I2C3
  i2cObjectInit(&I2CD3);
  I2CD3.thread = NULL;
  I2CD3.i2c    = I2C3;
#if AT32_I2C_USE_DMA == TRUE
  I2CD3.dmarx  = NULL;
  I2CD3.dmatx  = NULL;
#endif
#endif /* AT32_I2C_USE_I2C3 */

#if AT32_I2C_USE_I2C4
  i2cObjectInit(&I2CD4);
  I2CD4.thread = NULL;
  I2CD4.i2c    = I2C4;
#if AT32_I2C_USE_DMA == TRUE
  I2CD4.dmarx  = NULL;
  I2CD4.dmatx  = NULL;
#endif
#endif /* AT32_I2C_USE_I2C4 */
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

  /* Make sure I2C peripheral is disabled */
  dp->CTRL1 &= ~I2C_CTRL1_I2CEN;

  /* If in stopped state then enables the I2C and DMA clocks.*/
  if (i2cp->state == I2C_STOP) {

#if AT32_I2C_USE_DMA == TRUE
    /* Common DMA modes.*/
    i2cp->txdmamode = DMAMODE_COMMON | AT32_DMA_CTRL_DTD_M2P;
    i2cp->rxdmamode = DMAMODE_COMMON | AT32_DMA_CTRL_DTD_P2M;
#endif

#if AT32_I2C_USE_I2C1
    if (&I2CD1 == i2cp) {

      crmResetI2C1();
      crmEnableI2C1(true);
#if AT32_I2C_USE_DMA == TRUE
      {
        i2cp->dmarx = dmaStreamAllocI(AT32_I2C_I2C1_RX_DMA_STREAM,
                                      AT32_I2C_I2C1_IRQ_PRIORITY,
                                      NULL,
                                      (void *)i2cp);
        osalDbgAssert(i2cp->dmarx != NULL, "unable to allocate stream");
        i2cp->dmatx = dmaStreamAllocI(AT32_I2C_I2C1_TX_DMA_STREAM,
                                      AT32_I2C_I2C1_IRQ_PRIORITY,
                                      NULL,
                                      (void *)i2cp);
        osalDbgAssert(i2cp->dmatx != NULL, "unable to allocate stream");

        i2cp->rxdmamode |= AT32_DMA_CTRL_CHSEL(I2C1_RX_DMA_CHANNEL) |
                           AT32_DMA_CTRL_CHPL(AT32_I2C_I2C1_DMA_PRIORITY);
        i2cp->txdmamode |= AT32_DMA_CTRL_CHSEL(I2C1_TX_DMA_CHANNEL) |
                           AT32_DMA_CTRL_CHPL(AT32_I2C_I2C1_DMA_PRIORITY);
#if AT32_DMA_SUPPORTS_DMAMUX
#if AT32_USE_DMA_V1 && AT32_DMA_USE_DMAMUX
        dmaSetRequestSource(i2cp->dmarx, AT32_I2C_I2C1_RX_DMAMUX_CHANNEL, AT32_DMAMUX_I2C1_RX);
        dmaSetRequestSource(i2cp->dmatx, AT32_I2C_I2C1_TX_DMAMUX_CHANNEL, AT32_DMAMUX_I2C1_TX);
#elif AT32_USE_DMA_V2 || AT32_USE_DMA_V3
        dmaSetRequestSource(i2cp->dmarx, AT32_DMAMUX_I2C1_RX);
        dmaSetRequestSource(i2cp->dmatx, AT32_DMAMUX_I2C1_TX);
#endif
#endif
      }
#endif /* AT32_I2C_USE_DMA == TRUE */

#if defined(AT32_I2C1_GLOBAL_NUMBER) || defined(__DOXYGEN__)
      nvicEnableVector(AT32_I2C1_GLOBAL_NUMBER, AT32_I2C_I2C1_IRQ_PRIORITY);
#elif defined(AT32_I2C1_EVENT_NUMBER) && defined(AT32_I2C1_ERROR_NUMBER)
      nvicEnableVector(AT32_I2C1_EVENT_NUMBER, AT32_I2C_I2C1_IRQ_PRIORITY);
      nvicEnableVector(AT32_I2C1_ERROR_NUMBER, AT32_I2C_I2C1_IRQ_PRIORITY);
#else
#error "I2C1 interrupt numbers not defined"
#endif
    }
#endif /* AT32_I2C_USE_I2C1 */

#if AT32_I2C_USE_I2C2
    if (&I2CD2 == i2cp) {

      crmResetI2C2();
      crmEnableI2C2(true);
#if AT32_I2C_USE_DMA == TRUE
      {
        i2cp->dmarx = dmaStreamAllocI(AT32_I2C_I2C2_RX_DMA_STREAM,
                                      AT32_I2C_I2C2_IRQ_PRIORITY,
                                      NULL,
                                      (void *)i2cp);
        osalDbgAssert(i2cp->dmarx != NULL, "unable to allocate stream");
        i2cp->dmatx = dmaStreamAllocI(AT32_I2C_I2C2_TX_DMA_STREAM,
                                      AT32_I2C_I2C2_IRQ_PRIORITY,
                                      NULL,
                                      (void *)i2cp);
        osalDbgAssert(i2cp->dmatx != NULL, "unable to allocate stream");

        i2cp->rxdmamode |= AT32_DMA_CTRL_CHSEL(I2C2_RX_DMA_CHANNEL) |
                           AT32_DMA_CTRL_CHPL(AT32_I2C_I2C2_DMA_PRIORITY);
        i2cp->txdmamode |= AT32_DMA_CTRL_CHSEL(I2C2_TX_DMA_CHANNEL) |
                           AT32_DMA_CTRL_CHPL(AT32_I2C_I2C2_DMA_PRIORITY);
#if AT32_DMA_SUPPORTS_DMAMUX
#if AT32_USE_DMA_V1 && AT32_DMA_USE_DMAMUX
        dmaSetRequestSource(i2cp->dmarx, AT32_I2C_I2C2_RX_DMAMUX_CHANNEL, AT32_DMAMUX_I2C2_RX);
        dmaSetRequestSource(i2cp->dmatx, AT32_I2C_I2C2_TX_DMAMUX_CHANNEL, AT32_DMAMUX_I2C2_TX);
#elif AT32_USE_DMA_V2 || AT32_USE_DMA_V3
        dmaSetRequestSource(i2cp->dmarx, AT32_DMAMUX_I2C2_RX);
        dmaSetRequestSource(i2cp->dmatx, AT32_DMAMUX_I2C2_TX);
#endif
#endif
      }
#endif /* AT32_I2C_USE_DMA == TRUE */

#if defined(AT32_I2C2_GLOBAL_NUMBER) || defined(__DOXYGEN__)
      nvicEnableVector(AT32_I2C2_GLOBAL_NUMBER, AT32_I2C_I2C2_IRQ_PRIORITY);
#elif defined(AT32_I2C2_EVENT_NUMBER) && defined(AT32_I2C2_ERROR_NUMBER)
      nvicEnableVector(AT32_I2C2_EVENT_NUMBER, AT32_I2C_I2C2_IRQ_PRIORITY);
      nvicEnableVector(AT32_I2C2_ERROR_NUMBER, AT32_I2C_I2C2_IRQ_PRIORITY);
#else
#error "I2C2 interrupt numbers not defined"
#endif
    }
#endif /* AT32_I2C_USE_I2C2 */

#if AT32_I2C_USE_I2C3
    if (&I2CD3 == i2cp) {

      crmResetI2C3();
      crmEnableI2C3(true);
#if AT32_I2C_USE_DMA == TRUE
      {
        i2cp->dmarx = dmaStreamAllocI(AT32_I2C_I2C3_RX_DMA_STREAM,
                                      AT32_I2C_I2C3_IRQ_PRIORITY,
                                      NULL,
                                      (void *)i2cp);
        osalDbgAssert(i2cp->dmarx != NULL, "unable to allocate stream");
        i2cp->dmatx = dmaStreamAllocI(AT32_I2C_I2C3_TX_DMA_STREAM,
                                      AT32_I2C_I2C3_IRQ_PRIORITY,
                                      NULL,
                                      (void *)i2cp);
        osalDbgAssert(i2cp->dmatx != NULL, "unable to allocate stream");

        i2cp->rxdmamode |= AT32_DMA_CTRL_CHSEL(I2C3_RX_DMA_CHANNEL) |
                           AT32_DMA_CTRL_CHPL(AT32_I2C_I2C3_DMA_PRIORITY);
        i2cp->txdmamode |= AT32_DMA_CTRL_CHSEL(I2C3_TX_DMA_CHANNEL) |
                           AT32_DMA_CTRL_CHPL(AT32_I2C_I2C3_DMA_PRIORITY);
#if AT32_DMA_SUPPORTS_DMAMUX
#if AT32_USE_DMA_V1 && AT32_DMA_USE_DMAMUX
        dmaSetRequestSource(i2cp->dmarx, AT32_I2C_I2C3_RX_DMAMUX_CHANNEL, AT32_DMAMUX_I2C3_RX);
        dmaSetRequestSource(i2cp->dmatx, AT32_I2C_I2C3_TX_DMAMUX_CHANNEL, AT32_DMAMUX_I2C3_TX);
#elif AT32_USE_DMA_V2 || AT32_USE_DMA_V3
        dmaSetRequestSource(i2cp->dmarx, AT32_DMAMUX_I2C3_RX);
        dmaSetRequestSource(i2cp->dmatx, AT32_DMAMUX_I2C3_TX);
#endif
#endif
      }
#endif /* AT32_I2C_USE_DMA == TRUE */

#if defined(AT32_I2C3_GLOBAL_NUMBER) || defined(__DOXYGEN__)
      nvicEnableVector(AT32_I2C3_GLOBAL_NUMBER, AT32_I2C_I2C3_IRQ_PRIORITY);
#elif defined(AT32_I2C3_EVENT_NUMBER) && defined(AT32_I2C3_ERROR_NUMBER)
      nvicEnableVector(AT32_I2C3_EVENT_NUMBER, AT32_I2C_I2C3_IRQ_PRIORITY);
      nvicEnableVector(AT32_I2C3_ERROR_NUMBER, AT32_I2C_I2C3_IRQ_PRIORITY);
#else
#error "I2C3 interrupt numbers not defined"
#endif
    }
#endif /* AT32_I2C_USE_I2C3 */

#if AT32_I2C_USE_I2C4
    if (&I2CD4 == i2cp) {

      crmResetI2C4();
      crmEnableI2C4(true);
#if AT32_I2C_USE_DMA == TRUE
      {
        i2cp->dmarx = dmaStreamAllocI(AT32_I2C_I2C4_RX_DMA_STREAM,
                                      AT32_I2C_I2C4_IRQ_PRIORITY,
                                      NULL,
                                      (void *)i2cp);
        osalDbgAssert(i2cp->dmarx != NULL, "unable to allocate stream");
        i2cp->dmatx = dmaStreamAllocI(AT32_I2C_I2C4_TX_DMA_STREAM,
                                      AT32_I2C_I2C4_IRQ_PRIORITY,
                                      NULL,
                                      (void *)i2cp);
        osalDbgAssert(i2cp->dmatx != NULL, "unable to allocate stream");

        i2cp->rxdmamode |= AT32_DMA_CTRL_CHSEL(I2C4_RX_DMA_CHANNEL) |
                           AT32_DMA_CTRL_CHPL(AT32_I2C_I2C4_DMA_PRIORITY);
        i2cp->txdmamode |= AT32_DMA_CTRL_CHSEL(I2C4_TX_DMA_CHANNEL) |
                           AT32_DMA_CTRL_CHPL(AT32_I2C_I2C4_DMA_PRIORITY);
#if AT32_DMA_SUPPORTS_DMAMUX
#if AT32_USE_DMA_V1 && AT32_DMA_USE_DMAMUX
        dmaSetRequestSource(i2cp->dmarx, AT32_I2C_I2C4_RX_DMAMUX_CHANNEL, AT32_DMAMUX_I2C4_RX);
        dmaSetRequestSource(i2cp->dmatx, AT32_I2C_I2C4_TX_DMAMUX_CHANNEL, AT32_DMAMUX_I2C4_TX);
#elif AT32_USE_DMA_V2 || AT32_USE_DMA_V3
        dmaSetRequestSource(i2cp->dmarx, AT32_DMAMUX_I2C4_RX);
        dmaSetRequestSource(i2cp->dmatx, AT32_DMAMUX_I2C4_TX);
#endif
#endif
      }
#endif /* AT32_I2C_USE_DMA == TRUE */

#if defined(AT32_I2C4_GLOBAL_NUMBER) || defined(__DOXYGEN__)
      nvicEnableVector(AT32_I2C4_GLOBAL_NUMBER, AT32_I2C_I2C4_IRQ_PRIORITY);
#elif defined(AT32_I2C4_EVENT_NUMBER) && defined(AT32_I2C4_ERROR_NUMBER)
      nvicEnableVector(AT32_I2C4_EVENT_NUMBER, AT32_I2C_I2C4_IRQ_PRIORITY);
      nvicEnableVector(AT32_I2C4_ERROR_NUMBER, AT32_I2C_I2C4_IRQ_PRIORITY);
#else
#error "I2C4 interrupt numbers not defined"
#endif
    }
#endif /* AT32_I2C_USE_I2C4 */
  }

#if AT32_I2C_USE_DMA == TRUE
  /* I2C registers pointed by the DMA.*/
  dmaStreamSetPeripheral(i2cp->dmarx, &dp->RXDT);
  dmaStreamSetPeripheral(i2cp->dmatx, &dp->TXDT);
#endif

  /* Reset i2c peripheral, the TCIE bit will be handled separately.*/
  dp->CTRL1 = i2cp->config->ctrl1 |
#if AT32_I2C_USE_DMA == TRUE
              I2C_CTRL1_DMATEN | I2C_CTRL1_DMAREN | /* Enable only if using DMA */
#endif
              I2C_CTRL1_ERRIEN | I2C_CTRL1_ACKFAILIEN;

  /* Setup I2C parameters.*/
  dp->CLKCTRL = i2cp->config->clkctrl;

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
#if AT32_I2C_USE_DMA == TRUE
    dmaStreamFreeI(i2cp->dmatx);
    dmaStreamFreeI(i2cp->dmarx);
    i2cp->dmatx = NULL;
    i2cp->dmarx = NULL;
#endif

#if AT32_I2C_USE_I2C1
    if (&I2CD1 == i2cp) {
#if defined(AT32_I2C1_GLOBAL_NUMBER) || defined(__DOXYGEN__)
      nvicDisableVector(AT32_I2C1_GLOBAL_NUMBER);
#elif defined(AT32_I2C1_EVENT_NUMBER) && defined(AT32_I2C1_ERROR_NUMBER)
      nvicDisableVector(AT32_I2C1_EVENT_NUMBER);
      nvicDisableVector(AT32_I2C1_ERROR_NUMBER);
#else
#error "I2C1 interrupt numbers not defined"
#endif

      crmDisableI2C1();
    }
#endif

#if AT32_I2C_USE_I2C2
    if (&I2CD2 == i2cp) {
#if defined(AT32_I2C2_GLOBAL_NUMBER) || defined(__DOXYGEN__)
      nvicDisableVector(AT32_I2C2_GLOBAL_NUMBER);
#elif defined(AT32_I2C2_EVENT_NUMBER) && defined(AT32_I2C2_ERROR_NUMBER)
      nvicDisableVector(AT32_I2C2_EVENT_NUMBER);
      nvicDisableVector(AT32_I2C2_ERROR_NUMBER);
#else
#error "I2C2 interrupt numbers not defined"
#endif

      crmDisableI2C2();
    }
#endif

#if AT32_I2C_USE_I2C3
    if (&I2CD3 == i2cp) {
#if defined(AT32_I2C3_GLOBAL_NUMBER) || defined(__DOXYGEN__)
      nvicDisableVector(AT32_I2C3_GLOBAL_NUMBER);
#elif defined(AT32_I2C3_EVENT_NUMBER) && defined(AT32_I2C3_ERROR_NUMBER)
      nvicDisableVector(AT32_I2C3_EVENT_NUMBER);
      nvicDisableVector(AT32_I2C3_ERROR_NUMBER);
#else
#error "I2C3 interrupt numbers not defined"
#endif

      crmDisableI2C3();
    }
#endif

#if AT32_I2C_USE_I2C4
    if (&I2CD4 == i2cp) {
#if defined(AT32_I2C4_GLOBAL_NUMBER) || defined(__DOXYGEN__)
      nvicDisableVector(AT32_I2C4_GLOBAL_NUMBER);
#elif defined(AT32_I2C4_EVENT_NUMBER) && defined(AT32_I2C4_ERROR_NUMBER)
      nvicDisableVector(AT32_I2C4_EVENT_NUMBER);
      nvicDisableVector(AT32_I2C4_ERROR_NUMBER);
#else
#error "I2C4 interrupt numbers not defined"
#endif

      crmDisableI2C4();
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
  msg_t msg;
  I2C_TypeDef *dp = i2cp->i2c;
  systime_t start, end;

  /* Resetting error flags for this transfer.*/
  i2cp->errors = I2C_NO_ERROR;

  /* Releases the lock from high level driver.*/
  osalSysUnlock();

#if AT32_I2C_USE_DMA == TRUE
  /* RX DMA setup.*/
  dmaStreamSetMode(i2cp->dmarx, i2cp->rxdmamode);
  dmaStreamSetMemory0(i2cp->dmarx, rxbuf);
  dmaStreamSetTransactionSize(i2cp->dmarx, rxbytes);
#else
  i2cp->rxptr   = rxbuf;
  i2cp->rxbytes = rxbytes;
#endif

  /* Calculating the time window for the timeout on the busy bus condition.*/
  start = osalOsGetSystemTimeX();
  end = osalTimeAddX(start, OSAL_MS2I(AT32_I2C_BUSY_TIMEOUT));

  /* Waits until BUSY flag is reset or, alternatively, for a timeout
     condition.*/
  while (true) {
    osalSysLock();

    /* If the bus is not busy then the operation can continue, note, the
       loop is exited in the locked state.*/
    if ((dp->STS & I2C_STS_BUSYF) == 0)
      break;

    /* If the system time went outside the allowed window then a timeout
       condition is returned.*/
    if (!osalTimeIsInRangeX(osalOsGetSystemTimeX(), start, end)) {
      return MSG_TIMEOUT;
    }

    osalSysUnlock();
  }

  /* Setting up the slave address.*/
  i2c_lld_set_address(i2cp, addr);

  /* Setting up the peripheral.*/
  i2c_lld_setup_rx_transfer(i2cp);

#if AT32_I2C_USE_DMA == TRUE
  /* Enabling RX DMA.*/
  dmaStreamEnable(i2cp->dmarx);

  /* Transfer complete interrupt enabled.*/
  dp->CTRL1 |= I2C_CTRL1_TDCIEN;
#else

  /* Transfer complete and RX interrupts enabled.*/
  dp->CTRL1 |= I2C_CTRL1_TDCIEN | I2C_CTRL1_RDIEN;
#endif

  /* Starts the operation.*/
  dp->CTRL2 |= I2C_CTRL2_GENSTART;

  /* Waits for the operation completion or a timeout.*/
  msg = osalThreadSuspendTimeoutS(&i2cp->thread, timeout);

  /* In case of a software timeout a STOP is sent as an extreme attempt
     to release the bus and DMA is forcibly disabled.*/
  if (msg == MSG_TIMEOUT) {
    dp->CTRL2 |= I2C_CTRL2_GENSTOP;
#if AT32_I2C_USE_DMA == TRUE
    dmaStreamDisable(i2cp->dmarx);
#endif
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
  msg_t msg;
  I2C_TypeDef *dp = i2cp->i2c;
  systime_t start, end;

  /* Resetting error flags for this transfer.*/
  i2cp->errors = I2C_NO_ERROR;

  /* Releases the lock from high level driver.*/
  osalSysUnlock();

#if AT32_I2C_USE_DMA == TRUE
  /* TX DMA setup.*/
  dmaStreamSetMode(i2cp->dmatx, i2cp->txdmamode);
  dmaStreamSetMemory0(i2cp->dmatx, txbuf);
  dmaStreamSetTransactionSize(i2cp->dmatx, txbytes);

  /* RX DMA setup, note, rxbytes can be zero but we write the value anyway.*/
  dmaStreamSetMode(i2cp->dmarx, i2cp->rxdmamode);
  dmaStreamSetMemory0(i2cp->dmarx, rxbuf);
  dmaStreamSetTransactionSize(i2cp->dmarx, rxbytes);
#else
  i2cp->txptr   = txbuf;
  i2cp->txbytes = txbytes;
  i2cp->rxptr   = rxbuf;
  i2cp->rxbytes = rxbytes;
#endif

  /* Calculating the time window for the timeout on the busy bus condition.*/
  start = osalOsGetSystemTimeX();
  end = osalTimeAddX(start, OSAL_MS2I(AT32_I2C_BUSY_TIMEOUT));

  /* Waits until BUSY flag is reset or, alternatively, for a timeout
     condition.*/
  while (true) {
    osalSysLock();

    /* If the bus is not busy then the operation can continue, note, the
       loop is exited in the locked state.*/
    if ((dp->STS & I2C_STS_BUSYF) == 0)
      break;

    /* If the system time went outside the allowed window then a timeout
       condition is returned.*/
    if (!osalTimeIsInRangeX(osalOsGetSystemTimeX(), start, end)) {
      return MSG_TIMEOUT;
    }

    osalSysUnlock();
  }

  /* Setting up the slave address.*/
  i2c_lld_set_address(i2cp, addr);

  /* Preparing the transfer.*/
  i2c_lld_setup_tx_transfer(i2cp);

#if AT32_I2C_USE_DMA == TRUE
  /* Enabling TX DMA.*/
  dmaStreamEnable(i2cp->dmatx);

  /* Transfer complete interrupt enabled.*/
  dp->CTRL1 |= I2C_CTRL1_TDCIEN;
#else
  /* Transfer complete and TX interrupts enabled.*/
  dp->CTRL1 |= I2C_CTRL1_TDCIEN | I2C_CTRL1_TDIEN;
#endif

  /* Starts the operation.*/
  dp->CTRL2 |= I2C_CTRL2_GENSTART;

  /* Waits for the operation completion or a timeout.*/
  msg = osalThreadSuspendTimeoutS(&i2cp->thread, timeout);

  /* In case of a software timeout a STOP is sent as an extreme attempt
     to release the bus and DMA is forcibly disabled.*/
  if (msg == MSG_TIMEOUT) {
    dp->CTRL2 |= I2C_CTRL2_GENSTOP;
#if AT32_I2C_USE_DMA == TRUE
    dmaStreamDisable(i2cp->dmarx);
    dmaStreamDisable(i2cp->dmatx);
#endif
  }

  return msg;
}

#endif /* HAL_USE_I2C */

/** @} */
