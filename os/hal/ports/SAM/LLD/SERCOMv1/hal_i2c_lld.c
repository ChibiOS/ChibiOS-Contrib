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
 * @file    hal_i2c_lld.c
 * @brief   PLATFORM I2C subsystem low level driver source.
 *
 * @addtogroup I2C
 * @{
 */

#include "hal.h"
#include "sercom_clk.h"
#if (HAL_USE_I2C == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/
#define i2c_lld_get_rxbytes(i2cp) (i2cp)->rxbytes
#define i2c_lld_get_txbytes(i2cp) (i2cp)->txbytes

#define SERCOM_I2C_CTRLA_FORBIDDEN (SERCOM_I2CM_CTRLA_MODE_Msk |   \
                                    SERCOM_I2CM_CTRLA_ENABLE_Msk | \
                                    SERCOM_I2CM_CTRLA_SWRST_Msk |  \
                                    SERCOM_I2CM_CTRLA_SPEED_Msk)
/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   I2C1 driver identifier.
 */
#if (SAM_I2C_USE_SERCOM0 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD1;
#endif

/**
 * @brief   I2C2 driver identifier.
 */
#if (SAM_I2C_USE_SERCOM1 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD2;
#endif

/**
 * @brief   I2C3 driver identifier.
 */
#if (SAM_I2C_USE_SERCOM2 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD3;
#endif

/**
 * @brief   I2C4 driver identifier.
 */
#if (SAM_I2C_USE_SERCOM3 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD4;
#endif

/**
 * @brief   I2C5 driver identifier.
 */
#if (SAM_I2C_USE_SERCOM4 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD5;
#endif

/**
 * @brief   I2C6 driver identifier.
 */
#if (SAM_I2C_USE_SERCOM5 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD6;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/
static inline void sam_i2c_busy_wait(I2CDriver *i2cp)
{
  while ((i2cp->i2c->SERCOM_SYNCBUSY) != 0U)
    ;
}

static bool sam_i2c_cal_baud(uint32_t srcClkFreq, uint32_t i2cClkSpeed, uint32_t *baudVal)
{
  osalDbgAssert(i2cClkSpeed <= 400000, "This Clock is currently not supported");
  uint32_t baudValue = 0U;
  float fSrcClkFreq = (float)srcClkFreq;
  float fI2cClkSpeed = (float)i2cClkSpeed;
  float fBaudValue = 0.0f;

  /* Reference clock frequency must be atleast two times the baud rate */
  if (srcClkFreq < (2U * i2cClkSpeed))
  {
    return false;
  }

  if (i2cClkSpeed <= 1000000U)
  {
    /* Standard, FM and FM+ baud calculation */
    fBaudValue = (fSrcClkFreq / fI2cClkSpeed) - ((fSrcClkFreq * (100.0f / 1000000000.0f)) + 10.0f);
    baudValue = (uint32_t)fBaudValue;
  }
  else
  {
    return false;
  }
  if (i2cClkSpeed <= 400000U)
  {
    /* For I2C clock speed upto 400 kHz, the value of BAUD<7:0> determines both SCL_L and SCL_H with SCL_L = SCL_H */
    if (baudValue > (0xFFU * 2U))
    {
      /* Set baud rate to the minimum possible value */
      baudValue = 0xFFU;
    }
    else if (baudValue <= 1U)
    {
      /* Baud value cannot be 0. Set baud rate to maximum possible value */
      baudValue = 1U;
    }
    else
    {
      baudValue /= 2U;
    }
  }
  else
  {
    /* To maintain the ratio of SCL_L:SCL_H to 2:1, the max value of BAUD_LOW<15:8>:BAUD<7:0> can be 0xFF:0x7F. Hence BAUD_LOW + BAUD can not exceed 255+127 = 382 */
    if (baudValue >= 382U)
    {
      /* Set baud rate to the minimum possible value while maintaining SCL_L:SCL_H to 2:1 */
      baudValue = (0xFFUL << 8U) | (0x7FU);
    }
    else if (baudValue <= 3U)
    {
      /* Baud value cannot be 0. Set baud rate to maximum possible value while maintaining SCL_L:SCL_H to 2:1 */
      baudValue = (2UL << 8U) | 1U;
    }
    else
    {
      /* For Fm+ mode, I2C SCL_L:SCL_H to 2:1 */
      baudValue = ((((baudValue * 2U) / 3U) << 8U) | (baudValue / 3U));
    }
  }
  *baudVal = baudValue;
  return true;
}

static void i2c_lld_abort_operation(I2CDriver *i2cp)
{
  /* Disable the I2C module */
  i2cp->i2c->SERCOM_CTRLA &= ~SERCOM_I2CM_CTRLA_ENABLE_Msk;
  sam_i2c_busy_wait(i2cp);
  /* Re-enable the I2C module */
  i2cp->i2c->SERCOM_CTRLA |= SERCOM_I2CM_CTRLA_ENABLE_Msk;
  sam_i2c_busy_wait(i2cp);
  /* Since the I2C module was disabled, re-initialize the bus state to IDLE */
  i2cp->i2c->SERCOM_STATUS = (uint16_t)SERCOM_I2CM_STATUS_BUSSTATE(0x01UL);
  sam_i2c_busy_wait(i2cp);
}

static void i2c_lld_set_address(I2CDriver *i2cp, i2caddr_t addr, bool dir)
{
  i2cp->addr = addr;
  uint32_t temp = ((uint32_t)(i2cp->addr << 1U) | (dir ? 1U : 0U));
  i2cp->i2c->SERCOM_ADDR = temp;
  /* Wait for synchronization */
  sam_i2c_busy_wait(i2cp);
}
/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

static void i2c_lld_serve_interrupt(I2CDriver *i2cp)
{
  sercom_i2cm_registers_t *dp = i2cp->i2c;
  uint8_t isr = dp->SERCOM_STATUS;
  bool isFinished = false;
  if (i2cp->i2c->SERCOM_INTENSET != 0U)
  {
    /* Checks if the arbitration lost in multi-master scenario */
    if ((isr & SERCOM_I2CM_STATUS_ARBLOST_Msk) == SERCOM_I2CM_STATUS_ARBLOST_Msk)
    {
      /* Set Error status */
      i2cp->errors |= I2C_ARBITRATION_LOST;
    }
    /* Check for Bus Error during transmission */
    else if ((isr & SERCOM_I2CM_STATUS_BUSERR_Msk) == SERCOM_I2CM_STATUS_BUSERR_Msk)
    {
      /* Set Error status */
      i2cp->errors |= I2C_BUS_ERROR;
    }
    /* Checks slave acknowledge for address or data */
    else if ((isr & SERCOM_I2CM_STATUS_RXNACK_Msk) == SERCOM_I2CM_STATUS_RXNACK_Msk)
    {
      i2cp->errors |= I2C_ACK_FAILURE;
    }
    if (i2cp->errors)
    {
      dp->SERCOM_CTRLB |= SERCOM_I2CM_CTRLB_CMD(3UL);
      sam_i2c_busy_wait(i2cp);
      dp->SERCOM_INTENCLR = SERCOM_I2CM_INTENCLR_Msk;
      _i2c_wakeup_error_isr(i2cp);
    }
    else
    {
      if (i2cp->state == I2C_ACTIVE_TX && (dp->SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_MB_Msk))
      {
        if (i2cp->txbytes == 0 && i2cp->rxbytes != 0)
        {
          i2c_lld_set_address(i2cp, i2cp->addr, true);
          i2cp->state = I2C_ACTIVE_RX;
        }
        else if (i2cp->txbytes == 0)
        {
          dp->SERCOM_CTRLB |= SERCOM_I2CM_CTRLB_CMD(3UL);
          sam_i2c_busy_wait(i2cp);
          isFinished = true;
        }
        else {        
          dp->SERCOM_INTFLAG |= SERCOM_I2CM_INTFLAG_MB_Msk;
          uint8_t data = (uint8_t)*i2cp->txptr;
          i2cp->txptr++;
          i2cp->txbytes--;
          dp->SERCOM_DATA = data;
          sam_i2c_busy_wait(i2cp);
        }

      }
      else if (i2cp->state == I2C_ACTIVE_RX && (dp->SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_SB_Msk))
      {
        if (i2cp->rxbytes == 1)
        {
          dp->SERCOM_CTRLB |= SERCOM_I2CM_CTRLB_ACKACT_Msk | SERCOM_I2CM_CTRLB_CMD(3UL);
          sam_i2c_busy_wait(i2cp);
          isFinished = true;
        }
        *i2cp->rxptr = dp->SERCOM_DATA;
        i2cp->rxptr++;
        i2cp->rxbytes--;
        dp->SERCOM_INTFLAG |= SERCOM_I2CM_INTFLAG_SB_Msk;
        sam_i2c_busy_wait(i2cp);
      }
      if (isFinished)
      {
        dp->SERCOM_INTFLAG = (uint8_t)SERCOM_I2CM_INTFLAG_Msk;
        dp->SERCOM_INTENCLR = SERCOM_I2CM_INTENCLR_Msk;
        while ((dp->SERCOM_STATUS & SERCOM_I2CM_STATUS_BUSSTATE_Msk) != SERCOM_I2CM_STATUS_BUSSTATE(0x01U))
          ;
        _i2c_wakeup_isr(i2cp);
      }
    }
  }
}

#if SAM_I2C_USE_SERCOM0 == TRUE
OSAL_IRQ_HANDLER(SERCOM0_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD1);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM1 == TRUE
OSAL_IRQ_HANDLER(SERCOM1_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD2);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM2 == TRUE
OSAL_IRQ_HANDLER(SERCOM2_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD3);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM3 == TRUE
OSAL_IRQ_HANDLER(SERCOM3_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD4);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM4 == TRUE
OSAL_IRQ_HANDLER(SERCOM4_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD5);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM5 == TRUE
OSAL_IRQ_HANDLER(SERCOM5_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD6);
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
void i2c_lld_init(void)
{

#if SAM_I2C_USE_SERCOM0 == TRUE
  i2cObjectInit(&I2CD1);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM0_Msk;
  I2CD1.i2c = &SERCOM0_REGS->I2CM;
  I2CD1.clock = SAM_SERCOM0_GCLK_SRC_FREQ;
#endif
#if SAM_I2C_USE_SERCOM1 == TRUE
  i2cObjectInit(&I2CD2);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM1_Msk;
  I2CD2.i2c = &SERCOM1_REGS->I2CM;
  I2CD2.clock = SAM_SERCOM1_GCLK_SRC_FREQ;
#endif
#if SAM_I2C_USE_SERCOM2 == TRUE
  i2cObjectInit(&I2CD3);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM2_Msk;
  I2CD3.i2c = &SERCOM2_REGS->I2CM;
  I2CD3.clock = SAM_SERCOM2_GCLK_SRC_FREQ;
#endif
#if SAM_I2C_USE_SERCOM3 == TRUE
  i2cObjectInit(&I2CD4);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM3_Msk;
  I2CD4.i2c = &SERCOM3_REGS->I2CM;
  I2CD4.clock = SAM_SERCOM3_GCLK_SRC_FREQ;
#endif
#if SAM_I2C_USE_SERCOM4 == TRUE
  i2cObjectInit(&I2CD5);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM4_Msk;
  I2CD5.i2c = &SERCOM4_REGS->I2CM;
  I2CD5.clock = SAM_SERCOM4_GCLK_SRC_FREQ;
#endif
#if SAM_I2C_USE_SERCOM5 == TRUE
  i2cObjectInit(&I2CD6);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM5_Msk;
  I2CD6.i2c = &SERCOM5_REGS->I2CM;
  I2CD6.clock = SAM_SERCOM5_GCLK_SRC_FREQ;
#endif
}

/**
 * @brief   Configures and activates the I2C peripheral.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
void i2c_lld_start(I2CDriver *i2cp)
{

  if (i2cp->state == I2C_STOP)
  {
    sercom_i2cm_registers_t *dp = i2cp->i2c;
    /* Enables the peripheral.*/
#if SAM_I2C_USE_SERCOM0 == TRUE
    if (&I2CD1 == i2cp)
    {
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM0_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM0_CORE_Val, 1);
      nvicEnableVector(SERCOM0_IRQn, SAM_SERCOM0_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM1 == TRUE
    if (&I2CD2 == i2cp)
    {
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM1_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM1_CORE_Val, 1);
      nvicEnableVector(SERCOM1_IRQn, SAM_SERCOM1_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM2 == TRUE
    if (&I2CD3 == i2cp)
    {
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM2_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM2_CORE_Val, 1);
      nvicEnableVector(SERCOM2_IRQn, SAM_SERCOM1_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM3 == TRUE
    if (&I2CD4 == i2cp)
    {
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM3_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM3_CORE_Val, 1);
      nvicEnableVector(SERCOM3_IRQn, SAM_SERCOM3_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM4 == TRUE
    if (&I2CD5 == i2cp)
    {
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM4_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM4_CORE_Val, 1);
      nvicEnableVector(SERCOM4_IRQn, SAM_SERCOM4_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM5 == TRUE
    if (&I2CD6 == i2cp)
    {
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM5_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM5_CORE_Val, 1);
      nvicEnableVector(SERCOM5_IRQn, SAM_SERCOM5_IRQ_PRIORITY);
    }
#endif
    // Resetting sercom module
    i2cp->i2c->SERCOM_CTRLA = SERCOM_I2CM_CTRLA_SWRST_Msk;

    /* Wait for synchronization */
    sam_i2c_busy_wait(i2cp);

    /* Enable smart mode */
    dp->SERCOM_CTRLB = SERCOM_I2CM_CTRLB_SMEN_Msk;
    uint32_t baud_val = 0;
    osalDbgAssert(sam_i2c_cal_baud(i2cp->clock, i2cp->config->i2cSpeed, &baud_val), "unable to calculate baud");
    dp->SERCOM_BAUD = baud_val;
    dp->SERCOM_CTRLA = SERCOM_I2CM_CTRLA_MODE_I2C_MASTER | (i2cp->config->ctrla & ~SERCOM_I2C_CTRLA_FORBIDDEN) | SERCOM_I2CM_CTRLA_ENABLE_Msk;
    sam_i2c_busy_wait(i2cp);
    i2cp->i2c->SERCOM_STATUS = (uint16_t)SERCOM_I2CM_STATUS_BUSSTATE(0x01UL);
    sam_i2c_busy_wait(i2cp);
  }
}

/**
 * @brief   Deactivates the I2C peripheral.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
void i2c_lld_stop(I2CDriver *i2cp)
{
  if (i2cp->state != I2C_STOP)
  {
    i2c_lld_abort_operation(i2cp);
    /* Disables the peripheral.*/
#if SAM_I2C_USE_SERCOM1 == TRUE
    if (&I2CD2 == i2cp)
    {
      nvicDisableVector(SERCOM1_IRQn);
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
                                     sysinterval_t timeout)
{
  msg_t msg;
  sercom_i2cm_registers_t *dp = i2cp->i2c;
  systime_t start, end;
  osalSysUnlock();
  i2cp->rxptr = rxbuf;
  i2cp->rxbytes = rxbytes;
  start = osalOsGetSystemTimeX();
  end = osalTimeAddX(start, OSAL_MS2I(SAM_I2C_BUSY_TIMEOUT));
  /* Waits until BUSY flag is reset or, alternatively, for a timeout
      condition.*/
  while (true)
  {
    osalSysLock();

    /* If the bus is not busy then the operation can continue, note, the
       loop is exited in the locked state.*/
    if (((dp->SERCOM_STATUS & SERCOM_I2CM_STATUS_BUSSTATE_Msk) == SERCOM_I2CM_STATUS_BUSSTATE(0x01U)))
      break;

    /* If the system time went outside the allowed window then a timeout
       condition is returned.*/
    if (!osalTimeIsInRangeX(osalOsGetSystemTimeX(), start, end))
    {
      return MSG_TIMEOUT;
    }
    osalSysUnlock();
  }
  dp->SERCOM_INTFLAG = (uint8_t)SERCOM_I2CM_INTFLAG_Msk;
  dp->SERCOM_INTENSET = (uint8_t)SERCOM_I2CM_INTENSET_Msk;
  dp->SERCOM_CTRLB &= ~SERCOM_I2CM_CTRLB_ACKACT_Msk;
  sam_i2c_busy_wait(i2cp);
  i2c_lld_set_address(i2cp, addr, true);
  msg = osalThreadSuspendTimeoutS(&i2cp->thread, timeout);
  if (msg == MSG_TIMEOUT)
  {
    dp->SERCOM_CTRLB |= SERCOM_I2CM_CTRLB_CMD(3UL);
    sam_i2c_busy_wait(i2cp);
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
                                      sysinterval_t timeout)
{
  msg_t msg;
  sercom_i2cm_registers_t *dp = i2cp->i2c;
  systime_t start, end;
  osalSysUnlock();
  i2cp->txbytes = txbytes;
  i2cp->txptr = txbuf;
  i2cp->rxptr = rxbuf;
  i2cp->rxbytes = rxbytes;
  start = osalOsGetSystemTimeX();
  end = osalTimeAddX(start, OSAL_MS2I(SAM_I2C_BUSY_TIMEOUT));
  /* Waits until BUSY flag is reset or, alternatively, for a timeout
      condition.*/
  while (true)
  {
    osalSysLock();

    /* If the bus is not busy then the operation can continue, note, the
       loop is exited in the locked state.*/
    if (((dp->SERCOM_STATUS & SERCOM_I2CM_STATUS_BUSSTATE_Msk) == SERCOM_I2CM_STATUS_BUSSTATE(0x01U)))
      break;

    /* If the system time went outside the allowed window then a timeout
       condition is returned.*/
    if (!osalTimeIsInRangeX(osalOsGetSystemTimeX(), start, end))
    {
      return MSG_TIMEOUT;
    }
    osalSysUnlock();
  }
  dp->SERCOM_INTFLAG = (uint8_t)SERCOM_I2CM_INTFLAG_Msk;
  dp->SERCOM_INTENSET = (uint8_t)SERCOM_I2CM_INTENSET_Msk;
  dp->SERCOM_CTRLB &= ~SERCOM_I2CM_CTRLB_ACKACT_Msk;
  sam_i2c_busy_wait(i2cp);
  i2c_lld_set_address(i2cp, addr, false);
  msg = osalThreadSuspendTimeoutS(&i2cp->thread, timeout);
  if (msg == MSG_TIMEOUT)
  {
    dp->SERCOM_CTRLB |= SERCOM_I2CM_CTRLB_CMD(3UL);
    sam_i2c_busy_wait(i2cp);
  }
  return msg;
}

#endif /* HAL_USE_I2C == TRUE */

/** @} */
