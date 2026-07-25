/*
    Copyright (C) 2026 Belonit

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
 * @file    M251/hal_spi_lld.h
 * @brief   M251/M252 SPI subsystem low level driver header.
 *
 * @addtogroup SPI
 * @{
 */

#ifndef HAL_SPI_LLD_H
#define HAL_SPI_LLD_H

#if (HAL_USE_SPI == TRUE) || defined(__DOXYGEN__)

#include "m251_registry.h"

/**
 * @brief   Circular transfers capability.
 */
#define SPI_SUPPORTS_CIRCULAR              FALSE

/**
 * @brief   Slave mode capability.
 */
#define SPI_SUPPORTS_SLAVE_MODE            FALSE

/**
 * @name    M251 SPI modes
 * @{
 */
/** @brief SPI mode 0, CPOL=0 and CPHA=0.*/
#define M251_SPI_MODE_0                     SPI_CTL_TXNEG_Msk
/** @brief SPI mode 1, CPOL=0 and CPHA=1.*/
#define M251_SPI_MODE_1                     SPI_CTL_RXNEG_Msk
/** @brief SPI mode 2, CPOL=1 and CPHA=0.*/
#define M251_SPI_MODE_2                     (SPI_CTL_CLKPOL_Msk | SPI_CTL_RXNEG_Msk)
/** @brief SPI mode 3, CPOL=1 and CPHA=1.*/
#define M251_SPI_MODE_3                     (SPI_CTL_CLKPOL_Msk | SPI_CTL_TXNEG_Msk)
/** @}*/

/**
 * @name    M251 SPI configuration options
 * @{
 */

/**
 * @brief   SPID0 driver enable switch.
 * @details If set to @p TRUE the support for SPI0 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(M251_SPI_USE_SPI0) || defined(__DOXYGEN__)
#define M251_SPI_USE_SPI0                   FALSE
#endif

/**
 * @brief   SPID1 driver enable switch.
 * @details If set to @p TRUE the support for SPI1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(M251_SPI_USE_SPI1) || defined(__DOXYGEN__)
#define M251_SPI_USE_SPI1                   FALSE
#endif

/**
 * @brief   SPI0 interrupt priority.
 * @note    The default is 2.
 */
#if !defined(M251_SPI_SPI0_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define M251_SPI_SPI0_IRQ_PRIORITY          2
#endif

/**
 * @brief   SPI1 interrupt priority.
 * @note    The default is 2.
 */
#if !defined(M251_SPI_SPI1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define M251_SPI_SPI1_IRQ_PRIORITY          2
#endif
/** @}*/

#if M251_SPI_USE_SPI0 && !M251_HAS_SPI0
#error "SPI0 not present in the selected device"
#endif

#if M251_SPI_USE_SPI1 && !M251_HAS_SPI1
#error "SPI1 not present in the selected device"
#endif

#if !(M251_SPI_USE_SPI0 || M251_SPI_USE_SPI1)
#error "SPI driver activated but no SPI peripheral assigned"
#endif

#if M251_SPI_USE_SPI0 &&                                                  \
    !OSAL_IRQ_IS_VALID_PRIORITY(M251_SPI_SPI0_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to SPI0"
#endif

#if M251_SPI_USE_SPI1 &&                                                  \
    !OSAL_IRQ_IS_VALID_PRIORITY(M251_SPI_SPI1_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to SPI1"
#endif

/**
 * @brief   Low level fields of the SPI configuration structure.
 */
#define spi_lld_config_fields                                             \
  uint32_t                  frequency;                                    \
  uint32_t                  mode;

/**
 * @brief   Low level fields of the SPI driver structure.
 */
#define spi_lld_driver_fields                                             \
  SPI_T                     *spi;                                         \
  const uint8_t             *txptr;                                       \
  uint8_t                   *rxptr;                                       \
  size_t                    txcnt;                                        \
  size_t                    rxcnt;                                        \
  bool                      overrun;

/**
 * @brief   Returns the receive overrun status.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @return              @p true if an overrun occurred.
 * @notapi
 */
#define spi_lld_get_overrun(spip)          ((spip)->overrun)

#if M251_SPI_USE_SPI0 || defined(__DOXYGEN__)
extern SPIDriver SPID0;
#endif

#if M251_SPI_USE_SPI1 || defined(__DOXYGEN__)
extern SPIDriver SPID1;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void spi_lld_init(void);
  void spi_lld_start(SPIDriver *spip);
  void spi_lld_stop(SPIDriver *spip);
  void spi_lld_ignore(SPIDriver *spip, size_t n);
  void spi_lld_exchange(SPIDriver *spip, size_t n,
                        const void *txbuf, void *rxbuf);
  void spi_lld_send(SPIDriver *spip, size_t n, const void *txbuf);
  void spi_lld_receive(SPIDriver *spip, size_t n, void *rxbuf);
  uint16_t spi_lld_polled_exchange(SPIDriver *spip, uint16_t frame);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_SPI == TRUE */

#endif /* HAL_SPI_LLD_H */

/** @}*/
