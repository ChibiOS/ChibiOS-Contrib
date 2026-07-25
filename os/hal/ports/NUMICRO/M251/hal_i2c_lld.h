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
 * @file    M251/hal_i2c_lld.h
 * @brief   M251/M252 I2C subsystem low level driver header.
 *
 * @addtogroup I2C
 * @{
 */

#ifndef HAL_I2C_LLD_H
#define HAL_I2C_LLD_H

#if (HAL_USE_I2C == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    M251 I2C configuration options
 * @{
 */

/**
 * @brief   I2C0 driver enable switch.
 * @details If set to @p TRUE the support for I2C0 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(M251_I2C_USE_I2C0) || defined(__DOXYGEN__)
#define M251_I2C_USE_I2C0                   FALSE
#endif

/**
 * @brief   I2C1 driver enable switch.
 * @details If set to @p TRUE the support for I2C1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(M251_I2C_USE_I2C1) || defined(__DOXYGEN__)
#define M251_I2C_USE_I2C1                   FALSE
#endif

/**
 * @brief   Hardware bus timeout enable switch.
 * @details If set to @p TRUE, the 14-bit hardware counter uses @p PCLK divided
 *          by four and aborts an I2C state that makes no progress for
 *          65536/PCLK seconds, about 1.37 milliseconds at 48 MHz.
 * @note    The default is @p TRUE.
 * @note    Set to @p FALSE for slaves requiring longer clock stretching and
 *          use a finite timeout in the ChibiOS I2C API.
 */
#if !defined(M251_I2C_USE_HW_TIMEOUT) || defined(__DOXYGEN__)
#define M251_I2C_USE_HW_TIMEOUT              TRUE
#endif

/**
 * @brief   I2C0 interrupt priority.
 * @note    The default is 2.
 */
#if !defined(M251_I2C_I2C0_PRIORITY) || defined(__DOXYGEN__)
#define M251_I2C_I2C0_PRIORITY              2
#endif

/**
 * @brief   I2C1 interrupt priority.
 * @note    The default is 2.
 */
#if !defined(M251_I2C_I2C1_PRIORITY) || defined(__DOXYGEN__)
#define M251_I2C_I2C1_PRIORITY              2
#endif
/** @}*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if M251_I2C_USE_I2C0 && !M251_HAS_I2C0
#error "I2C0 not present in the selected device"
#endif

#if M251_I2C_USE_I2C1 && !M251_HAS_I2C1
#error "I2C1 not present in the selected device"
#endif

#if !(M251_I2C_USE_I2C0 || M251_I2C_USE_I2C1)
#error "I2C driver activated but no I2C peripheral assigned"
#endif

#if (M251_I2C_USE_HW_TIMEOUT != TRUE) &&                                    \
    (M251_I2C_USE_HW_TIMEOUT != FALSE)
#error "Invalid M251_I2C_USE_HW_TIMEOUT value"
#endif

#if M251_I2C_USE_I2C0 &&                                                    \
    !OSAL_IRQ_IS_VALID_PRIORITY(M251_I2C_I2C0_PRIORITY)
#error "Invalid IRQ priority assigned to I2C0"
#endif

#if M251_I2C_USE_I2C1 &&                                                    \
    !OSAL_IRQ_IS_VALID_PRIORITY(M251_I2C_I2C1_PRIORITY)
#error "Invalid IRQ priority assigned to I2C1"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type representing an I2C address.
 */
typedef uint8_t i2caddr_t;

/**
 * @brief   Type representing I2C error flags.
 */
typedef uint32_t i2cflags_t;

/**
 * @brief   Type representing the low-level interrupt state.
 */
typedef uint8_t intstate_t;

/**
 * @brief   Driver configuration structure.
 */
typedef struct I2CConfig {
  /**
   * @brief   I2C bus clock in Hz.
   */
  uint32_t              clock;
} I2CConfig;

/**
 * @brief   Type of a structure representing an I2C driver.
 */
typedef struct I2CDriver I2CDriver;

/**
 * @brief   Low-level I2C register type.
 */
typedef I2C_T I2C_TypeDef;

/**
 * @brief   Structure representing an I2C driver.
 */
struct I2CDriver {
  /** @brief Driver state.*/
  i2cstate_t                state;
  /** @brief Current configuration data.*/
  const I2CConfig           *config;
  /** @brief Latched error flags.*/
  i2cflags_t                errors;
#if I2C_USE_MUTUAL_EXCLUSION || defined(__DOXYGEN__)
  /** @brief Bus access mutex.*/
  mutex_t                   mutex;
#endif
  /** @brief Thread waiting for the current transfer.*/
  thread_reference_t        thread;
  /** @brief Current slave address.*/
  i2caddr_t                 addr;
  /** @brief Pointer to the transmit buffer.*/
  const uint8_t             *txbuf;
  /** @brief Requested transmit size.*/
  size_t                    txbytes;
  /** @brief Number of bytes transmitted so far.*/
  size_t                    txidx;
  /** @brief Pointer to the receive buffer.*/
  uint8_t                   *rxbuf;
  /** @brief Requested receive size.*/
  size_t                    rxbytes;
  /** @brief Number of bytes received so far.*/
  size_t                    rxidx;
  /** @brief Current low-level transfer state.*/
  intstate_t                intstate;
  /** @brief Pointer to the associated I2C registers.*/
  I2C_TypeDef               *i2c;
  /** @brief Master mode state.*/
  uint8_t                   is_master;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the errors from the previous operation.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 * @return              The error flags.
 * @notapi
 */
#define i2c_lld_get_errors(i2cp)           ((i2cp)->errors)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if M251_I2C_USE_I2C0 || defined(__DOXYGEN__)
extern I2CDriver I2CD0;
#endif

#if M251_I2C_USE_I2C1 || defined(__DOXYGEN__)
extern I2CDriver I2CD1;
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
                                        systime_t timeout);
  msg_t i2c_lld_master_receive_timeout(I2CDriver *i2cp, i2caddr_t addr,
                                       uint8_t *rxbuf, size_t rxbytes,
                                       systime_t timeout);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_I2C */

#endif /* HAL_I2C_LLD_H */

/** @}*/
