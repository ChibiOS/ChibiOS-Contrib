/*
    Copyright (C) 2024 Dimitris Mantzouranis

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
 * @file    UART/hal_serial_lld.h
 * @brief   SN32 low level serial driver header.
 *
 * @addtogroup SERIAL
 * @{
 */

#ifndef HAL_SERIAL_LLD_H
#define HAL_SERIAL_LLD_H

#if HAL_USE_SERIAL || defined(__DOXYGEN__)

#include "sn32_uart.h"

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
 * @brief   UART0 driver enable switch.
 * @details If set to @p TRUE the support for UART0 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SN32_SERIAL_USE_UART0) || defined(__DOXYGEN__)
#define SN32_SERIAL_USE_UART0                  FALSE
#endif

/**
 * @brief   UART1 driver enable switch.
 * @details If set to @p TRUE the support for UART1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SN32_SERIAL_USE_UART1) || defined(__DOXYGEN__)
#define SN32_SERIAL_USE_UART1                  FALSE
#endif

/**
 * @brief   UART2 driver enable switch.
 * @details If set to @p TRUE the support for UART2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SN32_SERIAL_USE_UART2) || defined(__DOXYGEN__)
#define SN32_SERIAL_USE_UART2                  FALSE
#endif

/**
 * @brief   UART0 interrupt priority level setting.
 */
#if !defined(SN32_SERIAL_UART0_PRIORITY) || defined(__DOXYGEN__)
#define SN32_SERIAL_UART0_PRIORITY             3
#endif

/**
 * @brief   UART1 interrupt priority level setting.
 */
#if !defined(SN32_SERIAL_UART1_PRIORITY) || defined(__DOXYGEN__)
#define SN32_SERIAL_UART1_PRIORITY             3
#endif

/**
 * @brief   UART2 interrupt priority level setting.
 */
#if !defined(SN32_SERIAL_UART2_PRIORITY) || defined(__DOXYGEN__)
#define SN32_SERIAL_UART2_PRIORITY             3
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if SN32_SERIAL_USE_UART0 && !SN32_HAS_UART0
#error "UART0 not present in the selected device"
#endif

#if SN32_SERIAL_USE_UART1 && !SN32_HAS_UART1
#error "UART1 not present in the selected device"
#endif

#if SN32_SERIAL_USE_UART2 && !SN32_HAS_UART2
#error "UART2 not present in the selected device"
#endif

#if !SN32_SERIAL_USE_UART0 && !SN32_SERIAL_USE_UART1 &&                     \
    !SN32_SERIAL_USE_UART2
#error "SERIAL driver activated but no UART/UART peripheral assigned"
#endif

#if SN32_SERIAL_USE_UART0 &&                                                \
    !OSAL_IRQ_IS_VALID_PRIORITY(SN32_SERIAL_UART0_PRIORITY)
#error "Invalid IRQ priority assigned to UART0"
#endif

#if SN32_SERIAL_USE_UART1 &&                                                \
    !OSAL_IRQ_IS_VALID_PRIORITY(SN32_SERIAL_UART1_PRIORITY)
#error "Invalid IRQ priority assigned to UART1"
#endif

#if SN32_SERIAL_USE_UART2 &&                                                \
    !OSAL_IRQ_IS_VALID_PRIORITY(SN32_SERIAL_UART2_PRIORITY)
#error "Invalid IRQ priority assigned to UART2"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

#if SN32_HAS_UART0
#define SN32_UART0_BASE  SN_UART0_BASE
#define SN32_UART0       ((sn32_uart_t *)SN_UART0_BASE)
#endif

#if SN32_HAS_UART1
#define SN32_UART1_BASE  SN_UART1_BASE
#define SN32_UART1       ((sn32_uart_t *)SN_UART1_BASE)
#endif

#if SN32_HAS_UART2
#define SN32_UART2_BASE  SN_UART2_BASE
#define SN32_UART2       ((sn32_uart_t *)SN_UART2_BASE)
#endif

/**
 * @brief   SN32 Serial Driver configuration structure.
 * @details An instance of this structure must be passed to @p sdStart()
 *          in order to configure and start a serial driver operations.
 * @note    This structure content is architecture dependent, each driver
 *          implementation defines its own version and the custom static
 *          initializers.
 */
typedef struct {
  /**
   * @brief This member configures the UART communication baud rate.
   */
  uint32_t                  speed;
  /**
   * @brief Specifies the number of data bits transmitted or received in a frame.
   *        This parameter can be a value of @ref UART_Word_Length
   */
  uint8_t                   UART_WordLength;
  /**
  * @brief Specifies the number of stop bits transmitted.
  *        This parameter can be a value of @ref UART_Stop_Bits
  */
  uint8_t                   UART_StopBits;
  /**
   * @brief Specifies the parity mode.
   *        This parameter can be a value of @ref UART_Parity
   */
  uint8_t                   UART_Parity;
  /**
   * @brief Controls the operation of the UART RX and TX FIFOs.
   */
  uint32_t                  UART_FIFOControl;
  /**
  * @brief Specifies the auto flow control mode and configures functionality.
  */
  uint32_t                  UART_AutoBaudControl;
  /**
  * @brief Specifies the oversampling rate.
  *        This parameter can be a value of @ref UART_Oversample
  */
  uint16_t                   UART_Oversampling;
  /**
  * @brief Enables half-duplex mode.
  */
  uint8_t                   UART_HalfDuplexMode;
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
  /* Pointer to the UART registers block.*/                                 \
  sn32_uart_t              *uart;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if SN32_SERIAL_USE_UART0 && !defined(__DOXYGEN__)
extern SerialDriver SD0;
#endif
#if SN32_SERIAL_USE_UART1 && !defined(__DOXYGEN__)
extern SerialDriver SD1;
#endif
#if SN32_SERIAL_USE_UART2 && !defined(__DOXYGEN__)
extern SerialDriver SD2;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void sd_lld_init(void);
  void sd_lld_start(SerialDriver *sdp, const SerialConfig *config);
  void sd_lld_stop(SerialDriver *sdp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_SERIAL */

#endif /* HAL_SERIAL_LLD_H */

/** @} */
