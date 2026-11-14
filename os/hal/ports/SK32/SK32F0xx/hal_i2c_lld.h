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
 * @file    SK32F0xx/hal_i2c_lld.h
 * @brief   SK32F0xx low level I2C driver header.
 * @details The SK32F0xx I2C is a legacy CR1/CR2/SR1/SR2/DR/CCR unit (the
 *          register set used by the STM32F1 family with the rise-time
 *          register removed) and is served by a single interrupt vector
 *          (no EV/ER IRQ split).  This driver is interrupt-driven, is
 *          written directly against the vendor CMSIS header (@p
 *          sk32f0xx.h) and does not use DMA.
 * @note    Only the master mode is supported, the I2C_ENABLE_SLAVE_MODE
 *          switch must stay at its default @p FALSE value.
 *
 * @addtogroup I2C
 * @{
 */

#ifndef HAL_I2C_LLD_H
#define HAL_I2C_LLD_H

#if HAL_USE_I2C || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   This I2C LLD does not support the slave mode.
 */
#define I2C_SUPPORTS_SLAVE_MODE             FALSE

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   I2C1 driver enable switch.
 * @details If set to @p TRUE the support for I2C1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SK32_I2C_USE_I2C1) || defined(__DOXYGEN__)
#define SK32_I2C_USE_I2C1                   FALSE
#endif

/**
 * @brief   I2C1 interrupt priority level setting.
 * @note    ARMv6-M (Cortex-M0) implements only 2 priority bits, the valid
 *          priority range is 0 (highest) .. 3 (lowest).
 */
#if !defined(SK32_I2C_I2C1_PRIORITY) || defined(__DOXYGEN__)
#define SK32_I2C_I2C1_PRIORITY              3
#endif

/**
 * @brief   I2C timeout on busy condition in milliseconds.
 */
#if !defined(SK32_I2C_BUSY_TIMEOUT) || defined(__DOXYGEN__)
#define SK32_I2C_BUSY_TIMEOUT               50
#endif

/**
 * @brief   I2C error hook.
 * @details This hook is invoked from the ISR context when a bus condition
 *          (NACK, bus error, arbitration loss, overrun) aborts an ongoing
 *          transfer.
 */
#if !defined(SK32_I2C_ERROR_HOOK) || defined(__DOXYGEN__)
#define SK32_I2C_ERROR_HOOK(i2cp)           osalSysHalt("I2C failure")
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if SK32_I2C_USE_I2C1 && !SK32_HAS_I2C1
#error "I2C1 not present in the selected device"
#endif

#if !SK32_I2C_USE_I2C1
#error "I2C driver activated but no I2C peripheral assigned"
#endif

#if SK32_I2C_USE_I2C1 &&                                                    \
    !OSAL_IRQ_IS_VALID_PRIORITY(SK32_I2C_I2C1_PRIORITY)
#error "Invalid IRQ priority assigned to I2C1"
#endif

/* Checks on allocation of I2C units.*/
#if SK32_I2C_USE_I2C1
#if defined(SK32_I2C1_IS_USED)
#error "I2CD1 requires I2C1 but it is already used"
#else
#define SK32_I2C1_IS_USED
#endif
#endif

#if I2C_ENABLE_SLAVE_MODE
#error "I2C slave mode not supported by this driver"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type representing an I2C address.
 */
typedef uint16_t i2caddr_t;

/**
 * @brief   Type of I2C driver condition flags.
 */
typedef uint32_t i2cflags_t;

/**
 * @brief   Supported modes for the I2C bus.
 */
typedef enum {
  OPMODE_I2C = 1,
  OPMODE_SMBUS_DEVICE = 2,
  OPMODE_SMBUS_HOST = 3,
} i2copmode_t;

/**
 * @brief   Supported duty cycle modes for the I2C bus.
 */
typedef enum {
  STD_DUTY_CYCLE = 1,
  FAST_DUTY_CYCLE_2 = 2,
  FAST_DUTY_CYCLE_16_9 = 3,
} i2cdutycycle_t;

/**
 * @brief   I2C driver configuration structure.
 */
struct hal_i2c_config {
  /* End of the mandatory fields.*/
  i2copmode_t     op_mode;       /**< @brief Specifies the I2C mode.        */
  uint32_t        clock_speed;   /**< @brief Specifies the clock frequency.
                                      @note Must be set to a value lower
                                      than 400kHz.                          */
  i2cdutycycle_t  duty_cycle;    /**< @brief Specifies the I2C fast mode
                                      duty cycle.                           */
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
#if I2C_USE_MUTUAL_EXCLUSION || defined(__DOXYGEN__)
  /**
   * @brief   Mutex protecting the bus.
   */
  mutex_t                   mutex;
#endif /* I2C_USE_MUTUAL_EXCLUSION */
#if defined(I2C_DRIVER_EXT_FIELDS)
  I2C_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief   Thread waiting for I/O completion.
   */
  thread_reference_t        thread;
  /**
   * @brief   Pointer to the I2Cx registers block.
   */
  I2C_TypeDef               *i2c;
  /**
   * @brief   Address byte (slave address shifted left plus the R/W bit).
   */
  i2caddr_t                 addr;
  /**
   * @brief   Pointer to the transmit buffer.
   */
  const uint8_t             *txbuf;
  /**
   * @brief   Number of data bytes to be transmitted.
   */
  size_t                    txbytes;
  /**
   * @brief   Number of data bytes written to the data register.
   */
  size_t                    txidx;
  /**
   * @brief   Pointer to the receive buffer.
   */
  uint8_t                   *rxbuf;
  /**
   * @brief   Number of data bytes to be received.
   */
  size_t                    rxbytes;
  /**
   * @brief   Number of data bytes read from the data register.
   */
  size_t                    rxidx;
  /**
   * @brief   Read phase flag, set when the read (repeated start) phase of
   *          a combined transfer is in progress.
   */
  bool                      rxphase;
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

#if !defined(__DOXYGEN__)
#if SK32_I2C_USE_I2C1
extern I2CDriver I2CD1;
#endif
#endif /* !defined(__DOXYGEN__) */

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
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_I2C */

#endif /* HAL_I2C_LLD_H */

/** @} */
