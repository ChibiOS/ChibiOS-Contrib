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
 * @file    SK32F0xx/hal_serial_lld.h
 * @brief   SK32F0xx low level serial driver header.
 * @details The SK32F0xx USART is a legacy SR/DR style unit (USARTv1 class,
 *          the same register set used by the STM32F1 family).  This driver
 *          is written directly against the vendor CMSIS header
 *          (@p sk32f0xx.h), no STM32 port code is involved.
 *
 * @addtogroup SERIAL
 * @{
 */

#ifndef HAL_SERIAL_LLD_H
#define HAL_SERIAL_LLD_H

#if HAL_USE_SERIAL || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   USART1 driver enable switch.
 * @details If set to @p TRUE the support for USART1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SK32_SERIAL_USE_USART1) || defined(__DOXYGEN__)
#define SK32_SERIAL_USE_USART1              FALSE
#endif

/**
 * @brief   USART2 driver enable switch.
 * @details If set to @p TRUE the support for USART2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SK32_SERIAL_USE_USART2) || defined(__DOXYGEN__)
#define SK32_SERIAL_USE_USART2              FALSE
#endif

/**
 * @brief   USART1 interrupt priority level setting.
 * @note    ARMv6-M (Cortex-M0) implements only 2 priority bits, the valid
 *          priority range is 0 (highest) .. 3 (lowest).
 */
#if !defined(SK32_SERIAL_USART1_PRIORITY) || defined(__DOXYGEN__)
#define SK32_SERIAL_USART1_PRIORITY         3
#endif

/**
 * @brief   USART2 interrupt priority level setting.
 */
#if !defined(SK32_SERIAL_USART2_PRIORITY) || defined(__DOXYGEN__)
#define SK32_SERIAL_USART2_PRIORITY         3
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if SK32_SERIAL_USE_USART1 && !SK32_HAS_USART1
#error "USART1 not present in the selected device"
#endif

#if SK32_SERIAL_USE_USART2 && !SK32_HAS_USART2
#error "USART2 not present in the selected device"
#endif

#if !SK32_SERIAL_USE_USART1 && !SK32_SERIAL_USE_USART2
#error "SERIAL driver activated but no USART peripheral assigned"
#endif

#if SK32_SERIAL_USE_USART1 &&                                              \
    !OSAL_IRQ_IS_VALID_PRIORITY(SK32_SERIAL_USART1_PRIORITY)
#error "Invalid IRQ priority assigned to USART1"
#endif

#if SK32_SERIAL_USE_USART2 &&                                              \
    !OSAL_IRQ_IS_VALID_PRIORITY(SK32_SERIAL_USART2_PRIORITY)
#error "Invalid IRQ priority assigned to USART2"
#endif

/* Checks on allocation of USART units.*/
#if SK32_SERIAL_USE_USART1
#if defined(SK32_USART1_IS_USED)
#error "SD1 requires USART1 but it is already used"
#else
#define SK32_USART1_IS_USED
#endif
#endif

#if SK32_SERIAL_USE_USART2
#if defined(SK32_USART2_IS_USED)
#error "SD2 requires USART2 but it is already used"
#else
#define SK32_USART2_IS_USED
#endif
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   SK32 Serial Driver configuration structure.
 * @details An instance of this structure must be passed to @p sdStart()
 *          in order to configure and start a serial driver operations.
 * @note    This structure content is architecture dependent, each driver
 *          implementation defines its own version and the custom static
 *          initializers.
 */
typedef struct hal_serial_config {
  /**
   * @brief Bit rate.
   */
  uint32_t                  speed;
  /* End of the mandatory fields.*/
  /**
   * @brief Initialization value for the CR1 register.
   */
  uint16_t                  cr1;
  /**
   * @brief Initialization value for the CR2 register.
   */
  uint16_t                  cr2;
  /**
   * @brief Initialization value for the CR3 register.
   */
  uint16_t                  cr3;
} SerialConfig;

/**
 * @brief   @p SerialDriver specific data.
 */
#define _serial_driver_data                                                 \
  _base_asynchronous_channel_data                                           \
  /* Driver state.*/                                                        \
  sdstate_t                 state;                                          \
  /* Input queue.*/                                                         \
  input_queue_t             iqueue;                                         \
  /* Output queue.*/                                                        \
  output_queue_t            oqueue;                                         \
  /* Input circular buffer.*/                                               \
  uint8_t                   ib[SERIAL_BUFFERS_SIZE];                        \
  /* Output circular buffer.*/                                              \
  uint8_t                   ob[SERIAL_BUFFERS_SIZE];                        \
  /* End of the mandatory fields.*/                                         \
  /* Pointer to the USART registers block.*/                                \
  USART_TypeDef             *usart;                                         \
  /* Clock frequency for the associated USART.*/                            \
  uint32_t                  clock;                                          \
  /* Mask to be applied on received frames.*/                               \
  uint8_t                   rxmask;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*
 * Stop bit encoding is not present in the vendor device header under this
 * symbolic form, it is defined here (USARTv1 convention).
 */
#ifndef USART_CR2_STOP1_BITS
#define USART_CR2_STOP1_BITS    (0 << 12)   /**< @brief CR2 1 stop bit value.*/
#endif
#ifndef USART_CR2_STOP0P5_BITS
#define USART_CR2_STOP0P5_BITS  (1 << 12)   /**< @brief CR2 0.5 stop bit value.*/
#endif
#ifndef USART_CR2_STOP2_BITS
#define USART_CR2_STOP2_BITS    (2 << 12)   /**< @brief CR2 2 stop bit value.*/
#endif
#ifndef USART_CR2_STOP1P5_BITS
#define USART_CR2_STOP1P5_BITS  (3 << 12)   /**< @brief CR2 1.5 stop bit value.*/
#endif

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if SK32_SERIAL_USE_USART1 && !defined(__DOXYGEN__)
extern SerialDriver SD1;
#endif
#if SK32_SERIAL_USE_USART2 && !defined(__DOXYGEN__)
extern SerialDriver SD2;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void sd_lld_init(void);
  void sd_lld_start(SerialDriver *sdp, const SerialConfig *config);
  void sd_lld_stop(SerialDriver *sdp);
  void sd_lld_serve_interrupt(SerialDriver *sdp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_SERIAL */

#endif /* HAL_SERIAL_LLD_H */

/** @} */
