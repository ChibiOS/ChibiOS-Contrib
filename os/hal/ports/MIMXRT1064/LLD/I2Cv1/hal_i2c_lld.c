/*
    ChibiOS - Copyright (C) 2014-2015 Fabio Utzig

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
 * @file    I2Cv1/hal_i2c_lld.c
 * @brief   LPI2C subsystem low level driver source.
 *
 * @addtogroup I2C
 * @{
 */

#include "osal.h"
#include "hal.h"

#include "fsl_lpi2c.h"

#if HAL_USE_I2C || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   I2C3 driver identifier.
 */
#if MIMXRT1064_I2C_USE_I2C3 || defined(__DOXYGEN__)
I2CDriver I2CD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
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

#if MIMXRT1064_I2C_USE_I2C3
  i2cObjectInit(&I2CD1);
  I2CD1.thread = NULL;
  I2CD1.i2c.lpi2c_p = LPI2C3;
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

#if MIMXRT1064_I2C_USE_I2C3
    if (&I2CD1 == i2cp) {
      lpi2c_master_config_t masterConfig = {0};

      IOMUXC->SW_MUX_CTL_PAD[kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_06] = IOMUXC_SW_MUX_CTL_PAD_SION(1) | PIN_MUX_ALTERNATIVE(1);
      IOMUXC->SW_MUX_CTL_PAD[kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_07] = IOMUXC_SW_MUX_CTL_PAD_SION(1) | PIN_MUX_ALTERNATIVE(1);

      IOMUXC->SW_PAD_CTL_PAD[kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_06] = IOMUXC_SW_PAD_CTL_PAD_ODE(1) | IOMUXC_SW_PAD_CTL_PAD_SPEED(1) | IOMUXC_SW_PAD_CTL_PAD_DSE(7);
      IOMUXC->SW_PAD_CTL_PAD[kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_07] = IOMUXC_SW_PAD_CTL_PAD_ODE(1) | IOMUXC_SW_PAD_CTL_PAD_SPEED(1) | IOMUXC_SW_PAD_CTL_PAD_DSE(7);

      IOMUXC->SELECT_INPUT[kIOMUXC_LPI2C3_SCL_SELECT_INPUT] = IOMUXC_SELECT_INPUT_DAISY(2);
      IOMUXC->SELECT_INPUT[kIOMUXC_LPI2C3_SDA_SELECT_INPUT] = IOMUXC_SELECT_INPUT_DAISY(2);


      /*
       * lpi2cConfig.debugEnable = false;
       * lpi2cConfig.ignoreAck = false;
       * lpi2cConfig.pinConfig = kLPI2C_2PinOpenDrain;
       * lpi2cConfig.baudRate_Hz = 100000U;
       * lpi2cConfig.busIdleTimeout_ns = 0;
       * lpi2cConfig.pinLowTimeout_ns = 0;
       * lpi2cConfig.sdaGlitchFilterWidth_ns = 0;
       * lpi2cConfig.sclGlitchFilterWidth_ns = 0;
       */
      LPI2C_MasterGetDefaultConfig(&masterConfig);
      //masterConfig.baudRate_Hz = 400000U;
      LPI2C_MasterInit(i2cp->i2c.lpi2c_p, &masterConfig, 60000000U);

    }
#endif

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

#if MIMXRT1064_I2C_USE_I2C3
    if (&I2CD1 == i2cp) {
      LPI2C_MasterDeinit(i2cp->i2c.lpi2c_p);
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
                                     systime_t timeout) {
  lpi2c_master_transfer_t xfer;
  status_t ret;

  xfer.flags          = kLPI2C_TransferDefaultFlag;
  xfer.slaveAddress   = addr;
  xfer.direction      = kLPI2C_Read;
  xfer.subaddress     = 0;
  xfer.subaddressSize = 0;
  xfer.data           = rxbuf;
  xfer.dataSize       = rxbytes;
  
  ret = LPI2C_MasterTransferBlocking(i2cp->i2c.lpi2c_p, &xfer);
  if (ret != kStatus_Success) {
    return MSG_RESET;
  }

  return MSG_OK;
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
  lpi2c_master_transfer_t xfer;
  status_t ret;

  xfer.flags          = kLPI2C_TransferDefaultFlag;
  xfer.slaveAddress   = addr;
  xfer.direction      = kLPI2C_Write;
  xfer.subaddress     = 0;
  xfer.subaddressSize = 0;
  xfer.data           = (void *)txbuf;
  xfer.dataSize       = txbytes;

  ret = LPI2C_MasterTransferBlocking(i2cp->i2c.lpi2c_p, &xfer);
  if (ret != kStatus_Success) {
    return MSG_RESET;
  }

  return MSG_OK;
}

#endif /* HAL_USE_I2C */

/** @} */
