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
#if !defined(SAM_SIO_USE_SERCOM0) || defined(__DOXYGEN__)
#define SAM_SIO_USE_SERCOM0             FALSE
#endif

/**
 * @brief   SIO driver enable switch.
 * @details If set to @p TRUE the support for SIO2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_SIO_USE_SERCOM1) || defined(__DOXYGEN__)
#define SAM_SIO_USE_SERCOM1             FALSE
#endif

/**
 * @brief   SIO driver enable switch.
 * @details If set to @p TRUE the support for SIO3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_SIO_USE_SERCOM2) || defined(__DOXYGEN__)
#define SAM_SIO_USE_SERCOM2             FALSE
#endif

/**
 * @brief   SIO driver enable switch.
 * @details If set to @p TRUE the support for SIO4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_SIO_USE_SERCOM3) || defined(__DOXYGEN__)
#define SAM_SIO_USE_SERCOM3             FALSE
#endif

/**
 * @brief   SIO driver enable switch.
 * @details If set to @p TRUE the support for SIO5 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_SIO_USE_SERCOM4) || defined(__DOXYGEN__)
#define SAM_SIO_USE_SERCOM4             FALSE
#endif

/**
 * @brief   SIO driver enable switch.
 * @details If set to @p TRUE the support for SIO6 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_SIO_USE_SERCOM5) || defined(__DOXYGEN__)
#define SAM_SIO_USE_SERCOM5             FALSE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/
#if SAM_SIO_USE_SERCOM0 == TRUE
#if SAM_SPI_USE_SERCOM0 == TRUE || SAM_I2C_USE_SERCOM0 == TRUE
#error "SERCOM0: Can only configured as one function only"
#endif
#endif

#if SAM_SIO_USE_SERCOM1 == TRUE
#if SAM_SPI_USE_SERCOM1 == TRUE || SAM_I2C_USE_SERCOM1 == TRUE
#error "SERCOM1: Can only configured as one function only"
#endif
#endif

#if SAM_SIO_USE_SERCOM2 == TRUE
#if SAM_SPI_USE_SERCOM2 == TRUE || SAM_I2C_USE_SERCOM2 == TRUE
#error "SERCOM2: Can only configured as one function only"
#endif
#endif

#if SAM_SIO_USE_SERCOM3 == TRUE
#if SAM_SPI_USE_SERCOM3 == TRUE || SAM_I2C_USE_SERCOM3 == TRUE
#error "SERCOM3: Can only configured as one function only"
#endif
#endif

#if SAM_SIO_USE_SERCOM4 == TRUE
#if SAM_SPI_USE_SERCOM4 == TRUE || SAM_I2C_USE_SERCOM4 == TRUE
#error "SERCOM4: Can only configured as one function only"
#endif
#endif

#if SAM_SIO_USE_SERCOM5 == TRUE
#if SAM_SPI_USE_SERCOM5 == TRUE || SAM_I2C_USE_SERCOM5 == TRUE
#error "SERCOM5: Can only configured as one function only"
#endif
#endif
/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a SIO events mask.
 */
typedef uint32_t sio_events_mask_t;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Low level fields of the SIO driver structure.
 */
#define sio_lld_driver_fields                                               \
  sercom_usart_int_registers_t   *usart;                                    \
  uint32_t                       clock;                                     

/**
 * @brief   Low level fields of the SIO configuration structure.
 */
#define sio_lld_config_fields                                               \
  uint32_t                  baud;                                           \
  uint32_t                  ctrla;                                          \
  uint32_t                  ctrlb;                                          \
  uint8_t                   txpo;                                           \
  uint8_t                   rxpo;


#define SERCOM_CTRLA_DEFAULT (SERCOM_USART_INT_CTRLA_MODE_USART_INT_CLK | \
                              SERCOM_USART_INT_CTRLA_DORD_Msk | \
                              SERCOM_USART_INT_CTRLA_IBON_Msk)

#define SERCOM_CTRLB_DEFAULT (0)

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
#define sio_lld_is_rx_empty(siop) !((siop->usart->SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_RXC_Msk) == \
                                    SERCOM_USART_INT_INTFLAG_RXC_Msk)

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
#define sio_lld_is_tx_full(siop) !((siop->usart->SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_DRE_Msk) == \
                                    SERCOM_USART_INT_INTFLAG_DRE_Msk)

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
#define sio_lld_is_tx_ongoing(siop) !((siop->usart->SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_TXC_Msk) == \
                                    SERCOM_USART_INT_INTFLAG_TXC_Msk)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (SAM_SIO_USE_SERCOM0 == TRUE) && !defined(__DOXYGEN__)
extern SIODriver SIOD1;
#endif

#if (SAM_SIO_USE_SERCOM1 == TRUE) && !defined(__DOXYGEN__)
extern SIODriver SIOD2;
#endif

#if (SAM_SIO_USE_SERCOM2 == TRUE) && !defined(__DOXYGEN__)
extern SIODriver SIOD3;
#endif

#if (SAM_SIO_USE_SERCOM3 == TRUE) && !defined(__DOXYGEN__)
extern SIODriver SIOD4;
#endif

#if (SAM_SIO_USE_SERCOM4 == TRUE) && !defined(__DOXYGEN__)
extern SIODriver SIOD5;
#endif

#if (SAM_SIO_USE_SERCOM5 == TRUE) && !defined(__DOXYGEN__)
extern SIODriver SIOD6;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void sio_lld_init(void);
  msg_t  sio_lld_start(SIODriver *siop);
  void sio_lld_stop(SIODriver *siop);
  void sio_lld_start_operation(SIODriver *siop);
  void sio_lld_stop_operation(SIODriver *siop);
  sio_events_mask_t sio_lld_get_and_clear_events(SIODriver *siop);
  size_t sio_lld_read(SIODriver *siop, uint8_t *buffer, size_t n);
  size_t sio_lld_write(SIODriver *siop, const uint8_t *buffer, size_t n);
  msg_t sio_lld_get(SIODriver *siop);
  void sio_lld_put(SIODriver *siop, uint_fast16_t data);
  msg_t sio_lld_control(SIODriver *siop, unsigned int operation, void *arg);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_SIO == TRUE */

#endif /* HAL_SIO_LLD_H */

/** @} */
