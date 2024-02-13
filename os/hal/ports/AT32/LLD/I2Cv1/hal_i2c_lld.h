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
 * @file    I2Cv1/hal_i2c_lld.h
 * @brief   AT32 I2C subsystem low level driver header.
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
 * @brief   Peripheral clock frequency.
 */
#define I2C_CLK_FREQ  ((AT32_PCLK1) / 1000000)

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
#if !defined(AT32_I2C_USE_I2C1) || defined(__DOXYGEN__)
#define AT32_I2C_USE_I2C1                   FALSE
#endif

/**
 * @brief   I2C2 driver enable switch.
 * @details If set to @p TRUE the support for I2C2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_I2C_USE_I2C2) || defined(__DOXYGEN__)
#define AT32_I2C_USE_I2C2                   FALSE
#endif

/**
 * @brief   I2C timeout on busy condition in milliseconds.
 */
#if !defined(AT32_I2C_BUSY_TIMEOUT) || defined(__DOXYGEN__)
#define AT32_I2C_BUSY_TIMEOUT               50
#endif

/**
 * @brief   I2C1 interrupt priority level setting.
 */
#if !defined(AT32_I2C_I2C1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_I2C_I2C1_IRQ_PRIORITY          10
#endif

/**
 * @brief   I2C2 interrupt priority level setting.
 */
#if !defined(AT32_I2C_I2C2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_I2C_I2C2_IRQ_PRIORITY          10
#endif

/**
* @brief   I2C1 DMA priority (0..3|lowest..highest).
* @note    The priority level is used for both the TX and RX DMA streams but
*          because of the streams ordering the RX stream has always priority
*          over the TX stream.
*/
#if !defined(AT32_I2C_I2C1_DMA_PRIORITY) || defined(__DOXYGEN__)
#define AT32_I2C_I2C1_DMA_PRIORITY          1
#endif

/**
* @brief   I2C2 DMA priority (0..3|lowest..highest).
* @note    The priority level is used for both the TX and RX DMA streams but
*          because of the streams ordering the RX stream has always priority
*          over the TX stream.
*/
#if !defined(AT32_I2C_I2C2_DMA_PRIORITY) || defined(__DOXYGEN__)
#define AT32_I2C_I2C2_DMA_PRIORITY          1
#endif

/**
 * @brief   I2C DMA error hook.
 * @note    The default action for DMA errors is a system halt because DMA
 *          error can only happen because programming errors.
 */
#if !defined(AT32_I2C_DMA_ERROR_HOOK) || defined(__DOXYGEN__)
#define AT32_I2C_DMA_ERROR_HOOK(i2cp)       osalSysHalt("DMA failure")
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/** @brief  error checks */
#if AT32_I2C_USE_I2C1 && !AT32_HAS_I2C1
#error "I2C1 not present in the selected device"
#endif

#if AT32_I2C_USE_I2C2 && !AT32_HAS_I2C2
#error "I2C2 not present in the selected device"
#endif

#if !AT32_I2C_USE_I2C1 && !AT32_I2C_USE_I2C2
#error "I2C driver activated but no I2C peripheral assigned"
#endif

#if AT32_I2C_USE_I2C1 &&                                                    \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_I2C_I2C1_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to I2C1"
#endif

#if AT32_I2C_USE_I2C2 &&                                                    \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_I2C_I2C2_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to I2C2"
#endif

#if AT32_I2C_USE_I2C1 &&                                                    \
    !AT32_DMA_IS_VALID_PRIORITY(AT32_I2C_I2C1_DMA_PRIORITY)
#error "Invalid DMA priority assigned to I2C1"
#endif

#if AT32_I2C_USE_I2C2 &&                                                    \
    !AT32_DMA_IS_VALID_PRIORITY(AT32_I2C_I2C2_DMA_PRIORITY)
#error "Invalid DMA priority assigned to I2C2"
#endif

#if !defined(AT32_DMA_REQUIRED)
#define AT32_DMA_REQUIRED
#endif

/* Check clock range. */
#if !(I2C_CLK_FREQ >= 2) && (I2C_CLK_FREQ <= 72)
#error "I2C peripheral clock frequency out of range."
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
   * @brief     Current slave address without R/W bit.
   */
  i2caddr_t                 addr;
  /**
   * @brief RX DMA mode bit mask.
   */
  uint32_t                  rxdmamode;
  /**
   * @brief TX DMA mode bit mask.
   */
  uint32_t                  txdmamode;
  /**
   * @brief     Receive DMA channel.
   */
  const at32_dma_stream_t   *dmarx;
  /**
   * @brief     Transmit DMA channel.
   */
  const at32_dma_stream_t   *dmatx;
  /**
   * @brief     Pointer to the I2Cx registers block.
   */
  I2C_TypeDef               *i2c;
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
#if AT32_I2C_USE_I2C1
extern I2CDriver I2CD1;
#endif

#if AT32_I2C_USE_I2C2
extern I2CDriver I2CD2;
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

#endif /* HAL_USE_I2C  */

#endif /* HAL_I2C_LLD_H */

/** @} */
