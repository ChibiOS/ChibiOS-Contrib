/*
    ChibiOS - Copyright (C) 2024 Xael South

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
 * @file    hal_sio_lld.h
 * @brief   PLATFORM SIO subsystem low level driver header.
 *
 * @addtogroup SIO
 * @{
 */

#ifndef HAL_SIO_LLD_H
#define HAL_SIO_LLD_H

#if (HAL_USE_SIO == TRUE) || defined(__DOXYGEN__)

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
 * @brief   SIO driver enable switch.
 * @details If set to @p TRUE the support for SIO1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(EFR32_SIO_USE_EUSART1) || defined(__DOXYGEN__)
#define EFR32_SIO_USE_EUSART1             FALSE
#endif

/**
 * @brief   SIO driver enable switch.
 * @details If set to @p TRUE the support for SIO2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(EFR32_SIO_USE_EUSART2) || defined(__DOXYGEN__)
#define EFR32_SIO_USE_EUSART2             FALSE
#endif

/**
 * @brief   SIO driver enable switch.
 * @details If set to @p TRUE the support for SIO3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(EFR32_SIO_USE_EUSART3) || defined(__DOXYGEN__)
#define EFR32_SIO_USE_EUSART3             FALSE
#endif
/** @} */

/**
 * @brief   SIO driver enable switch.
 * @details If set to @p TRUE the support for SIO4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(EFR32_SIO_USE_USART1) || defined(__DOXYGEN__)
#define EFR32_SIO_USE_USART1              FALSE
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if EFR32_SIO_USE_EUSART1 && !EFR32_HAS_EUSART1
#error "EUSART1 not present in the selected device"
#endif

#if EFR32_SIO_USE_EUSART2 && !EFR32_HAS_EUSART2
#error "EUSART2 not present in the selected device"
#endif

#if EFR32_SIO_USE_EUSART3 && !EFR32_HAS_EUSART3
#error "EUSART3 not present in the selected device"
#endif

#if EFR32_SIO_USE_USART1 && !EFR32_HAS_USART1
#error "USART1 not present in the selected device"
#endif


/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Low level fields of the SIO driver structure.
 */
#define sio_lld_driver_fields                                               \
  /* Pointer to the EUSARTx or USARTx registers block.*/                    \
  void *usart;                                                              \
/* Clock frequency for the associated USART/UART.*/                         \
  uint32_t clock

/**
 * @brief   Low level fields of the SIO configuration structure.
 */
#define sio_lld_config_fields                                               \
  /* Desired baud rate.*/                                                   \
  uint32_t baud;                                                            \
  uint32_t cfg0;                                                            \
  uint32_t framecfg

/**
 * @brief   Determines the state of the RX FIFO.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The RX FIFO state.
 * @retval false        if RX FIFO is not empty
 * @retval true         if RX FIFO is empty
 *
 * @notapi
 */
#define sio_lld_is_rx_empty(siop) _sio_lld_is_rx_empty(siop)

/**
 * @brief   Determines the activity state of the receiver.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The RX activity state.
 * @retval false        if RX is in active state.
 * @retval true         if RX is in idle state.
 *
 * @notapi
 */
#define sio_lld_is_rx_idle(siop) _sio_lld_is_rx_idle(siop)

/**
 * @brief   Determines if RX has pending error events to be read and cleared.
 * @note    Only error and protocol errors are handled, data events are not
 *          considered.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The RX error events.
 * @retval false        if RX has no pending events
 * @retval true         if RX has pending events
 *
 * @notapi
 */
#define sio_lld_has_rx_errors(siop) _sio_lld_has_rx_errors(siop)

/**
 * @brief   Determines the state of the TX FIFO.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The TX FIFO state.
 * @retval false        if TX FIFO is not full
 * @retval true         if TX FIFO is full
 *
 * @notapi
 */
#define sio_lld_is_tx_full(siop) _sio_lld_is_tx_full(siop)

/**
 * @brief   Determines the transmission state.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The TX FIFO state.
 * @retval false        if transmission is idle
 * @retval true         if transmission is ongoing
 *
 * @notapi
 */
#define sio_lld_is_tx_ongoing(siop) _sio_lld_is_tx_ongoing(siop)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (EFR32_SIO_USE_EUSART1 == TRUE) && !defined(__DOXYGEN__)
extern SIODriver SIOD1;
#endif

#if (EFR32_SIO_USE_EUSART2 == TRUE) && !defined(__DOXYGEN__)
extern SIODriver SIOD2;
#endif

#if (EFR32_SIO_USE_EUSART3 == TRUE) && !defined(__DOXYGEN__)
extern SIODriver SIOD3;
#endif

#if (EFR32_SIO_USE_USART1 == TRUE) && !defined(__DOXYGEN__)
extern SIODriver SIOD4;
#endif

#ifdef __cplusplus
extern "C"
{
#endif
void sio_lld_init(void);
msg_t  sio_lld_start(SIODriver* siop);
void sio_lld_stop(SIODriver* siop);
void sio_lld_update_enable_flags(SIODriver* siop);
sioevents_t sio_lld_get_and_clear_errors(SIODriver* siop);
sioevents_t sio_lld_get_and_clear_events(SIODriver* siop);
sioevents_t sio_lld_get_events(SIODriver* siop);
size_t sio_lld_read(SIODriver* siop, uint8_t* buffer, size_t n);
size_t sio_lld_write(SIODriver* siop, const uint8_t* buffer, size_t n);
msg_t sio_lld_get(SIODriver* siop);
void sio_lld_put(SIODriver* siop, uint_fast16_t data);
msg_t sio_lld_control(SIODriver* siop, unsigned int operation, void* arg);
void sio_lld_serve_interrupt(SIODriver* siop);

bool _sio_lld_is_rx_empty(SIODriver* siop);
bool _sio_lld_is_rx_idle(SIODriver* siop);
bool _sio_lld_has_rx_errors(SIODriver* siop);
bool _sio_lld_is_tx_full(SIODriver* siop);
bool _sio_lld_is_tx_ongoing(SIODriver* siop);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_SIO == TRUE */

#endif /* HAL_SIO_LLD_H */

/** @} */