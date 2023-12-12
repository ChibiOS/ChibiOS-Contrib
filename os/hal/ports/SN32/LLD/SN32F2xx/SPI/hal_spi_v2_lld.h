/*
    ChibiOS - Copyright (C) 2023 1Conan

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
 * @file    hal_spi_v2_lld.h
 * @brief   SN32 SPI (v2) subsystem low level driver header.
 *
 * @addtogroup SPI_V2
 * @{
 */

#ifndef HAL_SPI_V2_LLD_H
#define HAL_SPI_V2_LLD_H

#if HAL_USE_SPI || defined(__DOXYGEN__)

#include "sn32_spi.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Circular mode support flag.
 */
#define SPI_SUPPORTS_CIRCULAR           FALSE

/**
 * @brief   Slave mode support flag.
 */
#define SPI_SUPPORTS_SLAVE_MODE         TRUE

/** @defgroup SPI_Exported_Constants
  * @{
  */

/** @defgroup SPI_SN32_CTRL0
  * @{
  */
#define SPI_DATA_LENGTH(x)              ((x - 1) << 8)
#define SPI_TXFIFO_LENGTH(x)            (x << 12)
#define SPI_RXFIFO_LENGTH(x)            (x << 15)
#define SPI_LOOPBACK_ENABLE             (1 << 1)
/**
  * @}
  */

/** @defgroup SPI_SN32_CTRL1
  * @{
  */
#define SPI_MLSB_MSB                    (0 << 0)
#define SPI_MLSB_LSB                    (1 << 0)
#define SPI_CPOL_LOW                    (0 << 1)
#define SPI_CPOL_HIGH                   (1 << 1)
#define SPI_CPHA_FALLING                (0 << 2)
#define SPI_CPHA_RISING                 (1 << 2)
/**
  * @}
  */

/**
  * @}
  */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    SN32 configuration options
 * @{
 */
/**
 * @brief   SPI0 driver enable switch.
 * @details If set to @p TRUE the support for SPI1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SN32_SPI_USE_SPI0) || defined(__DOXYGEN__)
#define SN32_SPI_USE_SPI0                  FALSE
#endif

/*
 * @brief   SPI1 driver enable switch.
 * @details If set to @p TRUE the support for SPI1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SN32_SPI_USE_SPI1) || defined(__DOXYGEN__)
#define SN32_SPI_USE_SPI1                  FALSE
#endif

/**
 * @brief   SPI0 interrupt priority level setting.
 */
#if !defined(SN32_SPI_SPI0_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SN32_SPI_SPI0_IRQ_PRIORITY         3
#endif

/**
 * @brief   SPI1 interrupt priority level setting.
 */
#if !defined(SN32_SPI_SPI1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SN32_SPI_SPI1_IRQ_PRIORITY         3
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if SN32_SPI_USE_SPI0 && !SN32_HAS_SPI0
#error "SPI0 not present in the selected device"
#endif

#if SN32_SPI_USE_SPI1 && !SN32_HAS_SPI1
#error "SPI1 not present in the selected device"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

#if SN32_HAS_SPI0
#define SN32_SPI0_BASE  SN_SPI0_BASE
#define SN32_SPI0       ((sn32_spi_t *)SN_SPI0_BASE)
#endif

#if SN32_HAS_SPI1
#define SN32_SPI1_BASE  SN_SPI1_BASE
#define SN32_SPI1       ((sn32_spi_t *)SN_SPI1_BASE)
#endif

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

#define SPI_FIFO_FRESET(spip) (spip->spi->CTRL0_b.FRESET = 0b11)

/**
 * @brief   Low level fields of the SPI driver structure.
 */
#define spi_lld_driver_fields                                               \
  sn32_spi_t                *spi;                                           \
  uint8_t                   *rxbuf;                                         \
  const uint8_t             *txbuf;                                         \
  uint32_t                  count;                                          \
  uint32_t                  idx;

/**
 * @brief   Low level fields of the SPI configuration structure.
 */
#define spi_lld_config_fields                                               \
  uint32_t                  ctrl0;                                          \
  uint32_t                  ctrl1;                                          \
  uint32_t                  clkdiv;


/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (SN32_SPI_USE_SPI0 == TRUE) && !defined(__DOXYGEN__)
extern SPIDriver SPID0;
#endif

#if (SN32_SPI_USE_SPI1 == TRUE) && !defined(__DOXYGEN__)
extern SPIDriver SPID1;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void spi_lld_init(void);
  msg_t spi_lld_start(SPIDriver *spip);
  void spi_lld_stop(SPIDriver *spip);
#if (SPI_SELECT_MODE == SPI_SELECT_MODE_LLD) || defined(__DOXYGEN__)
  void spi_lld_select(SPIDriver *spip);
  void spi_lld_unselect(SPIDriver *spip);
#endif
  msg_t spi_lld_ignore(SPIDriver *spip, size_t n);
  msg_t spi_lld_exchange(SPIDriver *spip, size_t n,
                         const void *txbuf, void *rxbuf);
  msg_t spi_lld_send(SPIDriver *spip, size_t n, const void *txbuf);
  msg_t spi_lld_receive(SPIDriver *spip, size_t n, void *rxbuf);
  msg_t spi_lld_stop_transfer(SPIDriver *spip, size_t *sizep);
  uint16_t spi_lld_polled_exchange(SPIDriver *spip, uint16_t frame);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_SPI */

#endif /* HAL_SPI_V2_LLD_H */

/** @} */
