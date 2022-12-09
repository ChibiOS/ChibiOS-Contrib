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
 * @file    hal_i2c_lld.h
 * @brief   PLATFORM I2C subsystem low level driver header.
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

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    PLATFORM configuration options
 * @{
 */
/**
 * @brief   I2C1 driver enable switch.
 * @details If set to @p TRUE the support for I2C1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_I2C_USE_SERCOM0) || defined(__DOXYGEN__)
#define SAM_I2C_USE_SERCOM0 FALSE
#endif

/**
 * @brief   I2C2 driver enable switch.
 * @details If set to @p TRUE the support for I2C2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_I2C_USE_SERCOM1) || defined(__DOXYGEN__)
#define SAM_I2C_USE_SERCOM1 FALSE
#endif

/**
 * @brief   I2C3 driver enable switch.
 * @details If set to @p TRUE the support for I2C3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_I2C_USE_SERCOM2) || defined(__DOXYGEN__)
#define SAM_I2C_USE_SERCOM2 FALSE
#endif

/**
 * @brief   I2C4 driver enable switch.
 * @details If set to @p TRUE the support for I2C4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_I2C_USE_SERCOM3) || defined(__DOXYGEN__)
#define SAM_I2C_USE_SERCOM3 FALSE
#endif

/**
 * @brief   I2C5 driver enable switch.
 * @details If set to @p TRUE the support for I2C5 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_I2C_USE_SERCOM4) || defined(__DOXYGEN__)
#define SAM_I2C_USE_SERCOM4 FALSE
#endif

/**
 * @brief   I2C6 driver enable switch.
 * @details If set to @p TRUE the support for I2C6 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_I2C_USE_SERCOM5) || defined(__DOXYGEN__)
#define SAM_I2C_USE_SERCOM5 FALSE
#endif

/**
 * @brief   I2C timeout on busy condition in milliseconds.
 */
#if !defined(SAM_I2C_BUSY_TIMEOUT) || defined(__DOXYGEN__)
#define SAM_I2C_BUSY_TIMEOUT 50
#endif

/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if SAM_I2C_USE_SERCOM0 == TRUE
#if SAM_SIO_USE_SERCOM0 == TRUE || SAM_SPI_USE_SERCOM0 == TRUE
#error "SERCOM0: Can only configured as one function only"
#endif
#endif

#if SAM_I2C_USE_SERCOM1 == TRUE
#if SAM_SIO_USE_SERCOM1 == TRUE || SAM_SPI_USE_SERCOM1 == TRUE
#error "SERCOM1: Can only configured as one function only"
#endif
#endif

#if SAM_I2C_USE_SERCOM2 == TRUE
#if SAM_SIO_USE_SERCOM2 == TRUE || SAM_SPI_USE_SERCOM2 == TRUE
#error "SERCOM2: Can only configured as one function only"
#endif
#endif

#if SAM_I2C_USE_SERCOM3 == TRUE
#if SAM_SIO_USE_SERCOM3 == TRUE || SAM_SPI_USE_SERCOM3 == TRUE
#error "SERCOM3: Can only configured as one function only"
#endif
#endif

#if SAM_I2C_USE_SERCOM4 == TRUE
#if SAM_SIO_USE_SERCOM4 == TRUE || SAM_SPI_USE_SERCOM4 == TRUE
#error "SERCOM4: Can only configured as one function only"
#endif
#endif

#if SAM_I2C_USE_SERCOM5 == TRUE
#if SAM_SIO_USE_SERCOM5 == TRUE || SAM_SPI_USE_SERCOM5 == TRUE
#error "SERCOM5: Can only configured as one function only"
#endif
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

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
struct hal_i2c_config
{
  /* End of the mandatory fields.*/
  uint32_t i2cSpeed;
  uint32_t ctrla;
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
struct hal_i2c_driver
{
  /**
   * @brief   Driver state.
   */
  i2cstate_t state;
  /**
   * @brief   Current configuration data.
   */
  const I2CConfig *config;
  /**
   * @brief   Error flags.
   */
  i2cflags_t errors;
#if (I2C_USE_MUTUAL_EXCLUSION == TRUE) || defined(__DOXYGEN__)
  mutex_t mutex;
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief   Thread waiting for I/O completion.
   */
  thread_reference_t thread;
#if defined(I2C_DRIVER_EXT_FIELDS)
  I2C_DRIVER_EXT_FIELDS
#endif
  uint32_t clock;
  /**
   * @brief     Pointer to the next TX buffer location.
   */
  const uint8_t *txptr;
  /**
   * @brief     Number of bytes in TX phase.
   */
  size_t txbytes;
  /**
   * @brief     Pointer to the next RX buffer location.
   */
  uint8_t *rxptr;
  /**
   * @brief     Number of bytes in RX phase.
   */
  size_t rxbytes;
  sercom_i2cm_registers_t *i2c;
  i2caddr_t addr;
  /* End of the mandatory fields.*/
};

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

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (SAM_I2C_USE_SERCOM0 == TRUE) && !defined(__DOXYGEN__)
extern I2CDriver I2CD1;
#endif

#if (SAM_I2C_USE_SERCOM1 == TRUE) && !defined(__DOXYGEN__)
extern I2CDriver I2CD2;
#endif

#if (SAM_I2C_USE_SERCOM2 == TRUE) && !defined(__DOXYGEN__)
extern I2CDriver I2CD3;
#endif

#if (SAM_I2C_USE_SERCOM3 == TRUE) && !defined(__DOXYGEN__)
extern I2CDriver I2CD4;
#endif

#if (SAM_I2C_USE_SERCOM4 == TRUE) && !defined(__DOXYGEN__)
extern I2CDriver I2CD5;
#endif

#if (SAM_I2C_USE_SERCOM5 == TRUE) && !defined(__DOXYGEN__)
extern I2CDriver I2CD6;
#endif

#ifdef __cplusplus
extern "C"
{
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
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_I2C == TRUE */

#endif /* HAL_I2C_LLD_H */

/** @} */
