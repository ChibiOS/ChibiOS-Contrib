/*
    Copyright (C) 2020 Alex Lewontin
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
 * @file    M251/hal_serial_lld.h
 * @brief   M251/M252 Serial subsystem low level driver header.
 *
 * @addtogroup SERIAL
 * @{
 */

#ifndef HAL_SERIAL_LLD_H
#define HAL_SERIAL_LLD_H

#if (HAL_USE_SERIAL == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    M251 serial configuration options
 * @{
 */

/**
 * @brief   UART0 driver enable switch.
 * @details If set to @p TRUE the support for UART0 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(M251_SERIAL_USE_UART0) || defined(__DOXYGEN__)
#define M251_SERIAL_USE_UART0              TRUE
#endif

/**
 * @brief   UART1 driver enable switch.
 * @details If set to @p TRUE the support for UART1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(M251_SERIAL_USE_UART1) || defined(__DOXYGEN__)
#define M251_SERIAL_USE_UART1              FALSE
#endif

/**
 * @brief   UART clock input.
 * @note    The initial M251 port only supports direct 48 MHz HIRC HCLK.
 * @note    The default is @p M251_HCLK.
 */
#if !defined(M251_SERIAL_CLK) || defined(__DOXYGEN__)
#define M251_SERIAL_CLK                    M251_HCLK
#endif

/**
 * @brief   UART0 interrupt priority level setting.
 * @note    The default is 3.
 */
#if !defined(M251_SERIAL_UART0_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define M251_SERIAL_UART0_IRQ_PRIORITY     3
#endif

/**
 * @brief   UART1 interrupt priority level setting.
 * @note    The default is 3.
 */
#if !defined(M251_SERIAL_UART1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define M251_SERIAL_UART1_IRQ_PRIORITY     3
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if M251_SERIAL_USE_UART0 && !M251_HAS_UART0
#error "UART0 not present in the selected device"
#endif

#if M251_SERIAL_USE_UART1 && !M251_HAS_UART1
#error "UART1 not present in the selected device"
#endif

#if !M251_SERIAL_USE_UART0 && !M251_SERIAL_USE_UART1
#error "SERIAL driver activated but no UART peripheral assigned"
#endif

#if M251_SERIAL_CLK != __HIRC
#error "Only 48 MHz HIRC UART clock is supported by the initial M251 serial driver"
#endif

#if M251_SERIAL_USE_UART0 &&                                                 \
    !OSAL_IRQ_IS_VALID_PRIORITY(M251_SERIAL_UART0_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to UART0"
#endif

#if M251_SERIAL_USE_UART1 &&                                                 \
    !OSAL_IRQ_IS_VALID_PRIORITY(M251_SERIAL_UART1_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to UART1"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   M251 Serial Driver configuration structure.
 */
typedef struct hal_serial_config {
  /**
   * @brief Bit rate.
   */
  uint32_t                  speed;
  /**
   * @brief Initialization value for the UART LINE register.
   */
  uint32_t                  line;
} SerialConfig;

/**
 * @brief   @p SerialDriver specific data.
 * @details This macro declares the mandatory queues, buffers and
 *          peripheral-specific state embedded in @p SerialDriver.
 */
#define _serial_driver_data                                                 \
  _base_asynchronous_channel_data                                           \
  sdstate_t                 state;                                          \
  input_queue_t             iqueue;                                         \
  output_queue_t            oqueue;                                         \
  uint8_t                   ib[SERIAL_BUFFERS_SIZE];                        \
  uint8_t                   ob[SERIAL_BUFFERS_SIZE];                        \
  UART_T                    *uart;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if M251_SERIAL_USE_UART0 && !defined(__DOXYGEN__)
extern SerialDriver SD0;
#endif

#if M251_SERIAL_USE_UART1 && !defined(__DOXYGEN__)
extern SerialDriver SD1;
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

#endif /* HAL_USE_SERIAL == TRUE */

#endif /* HAL_SERIAL_LLD_H */

/** @} */
