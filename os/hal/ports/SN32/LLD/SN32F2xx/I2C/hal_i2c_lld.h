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
 * @file    hal_i2c_lld.h
 * @brief   SN32 I2C subsystem low level driver header.
 *
 * @addtogroup I2C
 * @{
 */

#ifndef HAL_I2C_LLD_H
#define HAL_I2C_LLD_H

#if (HAL_USE_I2C == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/
#include "sn32_i2c.h"
/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    SN32 configuration options
 * @{
 */
/**
 * @brief   I2C0 driver enable switch.
 * @details If set to @p TRUE the support for I2C0 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SN32_I2C_USE_I2C0) || defined(__DOXYGEN__)
#define SN32_I2C_USE_I2C0                  FALSE
#endif

/**
 * @brief   I2C0 interrupt priority level setting.
 */
#if !defined(SN32_I2C_I2C0_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SN32_I2C_I2C0_IRQ_PRIORITY         3
#endif

/**
 * @brief   I2C timeout on busy condition in milliseconds.
 */
#if !defined(SN32_I2C_BUSY_TIMEOUT) || defined(__DOXYGEN__)
#define SN32_I2C_BUSY_TIMEOUT              50
#endif

/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

#if SN32_HAS_I2C0
#define SN32_I2C0_BASE  SN_I2C0_BASE
#define SN32_I2C0       ((sn32_i2c_t *)SN_I2C0_BASE)
#endif

/**
 * @brief   Type representing an I2C address.
 */
typedef uint16_t i2caddr_t;

/**
 * @brief   Type of I2C Driver condition flags.
 */
typedef uint32_t i2cflags_t;

/**
 * @brief   I2C driver configuration structure.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
struct hal_i2c_config {
  /* End of the mandatory fields.*/
  uint8_t                  high_time;
  uint8_t                  low_time;
  uint16_t                 timeout;
};

/**
 * @brief   Type of a structure representing an I2C configuration.
 */
typedef struct hal_i2c_config I2CConfig;

/**
 * @brief   Type of a structure representing an I2C driver.
 */
typedef struct hal_i2c_driver I2CDriver;

/**
 * @brief   Structure representing an I2C driver.
 */
struct hal_i2c_driver {
  /**
   * @brief   Driver state.
   */
  i2cstate_t                state;
  /**
   * @brief   Current configuration data.
   */
  const I2CConfig           *config;
  /**
   * @brief   Error flags.
   */
  i2cflags_t                errors;
#if (I2C_USE_MUTUAL_EXCLUSION == TRUE) || defined(__DOXYGEN__)
  mutex_t                   mutex;
#endif
#if defined(I2C_DRIVER_EXT_FIELDS)
  I2C_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/

  /* @brief Thread waiting for I/O completion. */
  thread_reference_t        thread;
  /* @brief     Current slave address without R/W bit. */
  i2caddr_t                 addr;

  sn32_i2c_t               *i2c;
  /* @brief Pointer to the buffer to put received data. */
  uint8_t                  *rx_buffer;
  /* @brief Number of bytes of data to receive. */
  size_t                   rx_len;
  /* @brief Pointer to the buffer with data to send. */
  const uint8_t            *tx_buffer;
  /* @brief Number of bytes of data to send. */
  size_t                   tx_len;
  /* @brief Current count of transmitted data. */
  size_t                   count;
};

/* For compatibility, some LLDs could not export this.*/
#if !defined(I2C_SUPPORTS_SLAVE_MODE)
#define I2C_SUPPORTS_SLAVE_MODE             TRUE
#endif

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Get errors from I2C driver.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
#define i2c_lld_get_errors(i2cp) ((i2cp)->errors)
/**
 * @brief   Get rx length from I2C driver.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
#define i2c_lld_get_rxbytes(i2cp) (i2cp)->rx_len
/**
 * @brief   Get tx length from I2C driver.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
#define i2c_lld_get_txbytes(i2cp) (i2cp)->tx_len

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (SN32_I2C_USE_I2C0 == TRUE) && !defined(__DOXYGEN__)
extern I2CDriver I2CD0;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void i2c_lld_init(void);
  void i2c_lld_start(I2CDriver *i2cp);
  void i2c_lld_stop(I2CDriver *i2cp);
  msg_t i2c_lld_master_transmit_timeout(I2CDriver *i2cp, i2caddr_t addr,
                                        const uint8_t *txbuf, size_t txbytes,
                                        uint8_t *rxbuf, size_t rxbytes,
                                        sysinterval_t timeout);
  msg_t i2c_lld_master_receive_timeout(I2CDriver *i2cp, i2caddr_t addr,
                                       uint8_t *rxbuf, size_t rxbytes,
                                       sysinterval_t timeout);
#if (I2C_SUPPORTS_SLAVE_MODE == TRUE) || defined(__DOXYGEN__)
  msg_t i2c_lld_match_address(I2CDriver *i2cp, i2caddr_t addr);
  msg_t i2c_lld_slave_receive_timeout(I2CDriver *i2cp,
                             uint8_t *rxbuf,
                             size_t rxbytes,
                             sysinterval_t timeout);
  msg_t i2c_lld_slave_transmit_timeout(I2CDriver *i2cp,
                               const uint8_t *txbuf,
                               size_t txbytes,
                               sysinterval_t timeout);
#endif /* I2C_SUPPORTS_SLAVE_MODE == TRUE */
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_I2C == TRUE */

#endif /* HAL_I2C_LLD_H */

/** @} */