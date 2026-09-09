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
 * @file    SK32F0xx/hal_spi_lld.h
 * @brief   SK32F0xx low level SPI driver header.
 * @details The SK32F0xx SPI is a legacy CR1/CR2/SR/DR unit (SPIv1 class, the
 *          same register set used by the STM32F1 family, no FIFO).  This
 *          driver is interrupt-driven (RXNE/TXE/ERRIE) and is written
 *          directly against the vendor CMSIS header (@p sk32f0xx.h), no
 *          STM32 port code and no DMA are involved.
 *
 * @addtogroup SPI
 * @{
 */

#ifndef HAL_SPI_LLD_H
#define HAL_SPI_LLD_H

#if HAL_USE_SPI || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Circular mode support flag.
 */
#define SPI_SUPPORTS_CIRCULAR           FALSE

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   SPI1 driver enable switch.
 * @details If set to @p TRUE the support for SPI1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SK32_SPI_USE_SPI1) || defined(__DOXYGEN__)
#define SK32_SPI_USE_SPI1                   FALSE
#endif

/**
 * @brief   SPI2 driver enable switch.
 * @details If set to @p TRUE the support for SPI2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SK32_SPI_USE_SPI2) || defined(__DOXYGEN__)
#define SK32_SPI_USE_SPI2                   FALSE
#endif

/**
 * @brief   SPI1 interrupt priority level setting.
 * @note    ARMv6-M (Cortex-M0) implements only 2 priority bits, the valid
 *          priority range is 0 (highest) .. 3 (lowest).
 */
#if !defined(SK32_SPI_SPI1_PRIORITY) || defined(__DOXYGEN__)
#define SK32_SPI_SPI1_PRIORITY              3
#endif

/**
 * @brief   SPI2 interrupt priority level setting.
 */
#if !defined(SK32_SPI_SPI2_PRIORITY) || defined(__DOXYGEN__)
#define SK32_SPI_SPI2_PRIORITY              3
#endif

/**
 * @brief   SPI error hook.
 * @details This hook is invoked from the ISR context when an overrun or a
 *          mode fault aborts an ongoing transfer.
 */
#if !defined(SK32_SPI_ERROR_HOOK) || defined(__DOXYGEN__)
#define SK32_SPI_ERROR_HOOK(spip)           osalSysHalt("SPI failure")
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if SK32_SPI_USE_SPI1 && !SK32_HAS_SPI1
#error "SPI1 not present in the selected device"
#endif

#if SK32_SPI_USE_SPI2 && !SK32_HAS_SPI2
#error "SPI2 not present in the selected device"
#endif

#if !SK32_SPI_USE_SPI1 && !SK32_SPI_USE_SPI2
#error "SPI driver activated but no SPI peripheral assigned"
#endif

#if SK32_SPI_USE_SPI1 &&                                                    \
    !OSAL_IRQ_IS_VALID_PRIORITY(SK32_SPI_SPI1_PRIORITY)
#error "Invalid IRQ priority assigned to SPI1"
#endif

#if SK32_SPI_USE_SPI2 &&                                                    \
    !OSAL_IRQ_IS_VALID_PRIORITY(SK32_SPI_SPI2_PRIORITY)
#error "Invalid IRQ priority assigned to SPI2"
#endif

/* Checks on allocation of SPI units.*/
#if SK32_SPI_USE_SPI1
#if defined(SK32_SPI1_IS_USED)
#error "SPID1 requires SPI1 but it is already used"
#else
#define SK32_SPI1_IS_USED
#endif
#endif

#if SK32_SPI_USE_SPI2
#if defined(SK32_SPI2_IS_USED)
#error "SPID2 requires SPI2 but it is already used"
#else
#define SK32_SPI2_IS_USED
#endif
#endif

#if SPI_SELECT_MODE == SPI_SELECT_MODE_LLD
#error "SPI_SELECT_MODE_LLD not supported by this driver"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @name    CR1 helpers
 * @{
 */
/**
 * @brief   Data frame format bit.
 * @details The vendor CMSIS header names the CR1 bit 11 "CRCL" (the STM32F0
 *          SPI convention) but the vendor StdPeriph driver uses it as the
 *          8/16 bit data frame format selector (@p SPI_DataSize_16b is
 *          defined to 0x0800, the STM32F1 @p DFF convention).  It is
 *          aliased here with the name used by the ChibiOS SPIv1 drivers.
 */
#if !defined(SPI_CR1_DFF) || defined(__DOXYGEN__)
#define SPI_CR1_DFF                         ((uint16_t)0x0800)
#endif

/**
 * @brief   Baud rate selection: PCLK2 divided by 2.
 */
#define SK32_SPI_BR_PCLK_DIV2               (0U << 3)
/**
 * @brief   Baud rate selection: PCLK2 divided by 4.
 */
#define SK32_SPI_BR_PCLK_DIV4               (1U << 3)
/**
 * @brief   Baud rate selection: PCLK2 divided by 8.
 */
#define SK32_SPI_BR_PCLK_DIV8               (2U << 3)
/**
 * @brief   Baud rate selection: PCLK2 divided by 16.
 */
#define SK32_SPI_BR_PCLK_DIV16              (3U << 3)
/**
 * @brief   Baud rate selection: PCLK2 divided by 32.
 */
#define SK32_SPI_BR_PCLK_DIV32              (4U << 3)
/**
 * @brief   Baud rate selection: PCLK2 divided by 64.
 */
#define SK32_SPI_BR_PCLK_DIV64              (5U << 3)
/**
 * @brief   Baud rate selection: PCLK2 divided by 128.
 */
#define SK32_SPI_BR_PCLK_DIV128             (6U << 3)
/**
 * @brief   Baud rate selection: PCLK2 divided by 256.
 */
#define SK32_SPI_BR_PCLK_DIV256             (7U << 3)
/** @} */

/**
 * @brief   Low level fields of the SPI driver structure.
 * @note    The transfer state is owned by the driver ISR, @p txidx counts
 *          the frames written to the data register while @p rxidx counts
 *          the frames read back; the transfer is complete when the last
 *          frame has been received.
 */
#define spi_lld_driver_fields                                               \
  /* Pointer to the SPIx registers block.*/                                 \
  SPI_TypeDef               *spi;                                           \
  /* Pointer to the transmit buffer or NULL.*/                              \
  const void                *txbuf;                                         \
  /* Pointer to the receive buffer or NULL.*/                               \
  void                      *rxbuf;                                         \
  /* Number of frames written to the data register.*/                       \
  size_t                    txidx;                                          \
  /* Number of frames read from the data register.*/                        \
  size_t                    rxidx;                                          \
  /* Total number of frames of the current transfer.*/                      \
  size_t                    count;

/**
 * @brief   Low level fields of the SPI configuration structure.
 * @details The CR1 content is applied to the peripheral with the master
 *          mode and the software slave management bits forced on.  The
 *          CR2 interrupt enable bits (RXNEIE, TXEIE, ERRIE) and the DMA
 *          request bits are owned by this driver and masked out of the
 *          configured value.
 */
#define spi_lld_config_fields                                               \
  /* SPI CR1 register initialization data.*/                                \
  uint16_t                  cr1;                                            \
  /* SPI CR2 register initialization data.*/                                \
  uint16_t                  cr2;

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if SK32_SPI_USE_SPI1 && !defined(__DOXYGEN__)
extern SPIDriver SPID1;
#endif
#if SK32_SPI_USE_SPI2 && !defined(__DOXYGEN__)
extern SPIDriver SPID2;
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

#endif /* HAL_USE_SPI */

#endif /* HAL_SPI_LLD_H */

/** @} */
