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
 * @file    hal_spi_v2_lld.h
 * @brief   PLATFORM SPI (v2) subsystem low level driver header.
 *
 * @addtogroup SPI_V2
 * @{
 */

#ifndef HAL_SPI_V2_LLD_H
#define HAL_SPI_V2_LLD_H

#if HAL_USE_SPI || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Circular mode support flag.
 */
#define SPI_SUPPORTS_CIRCULAR FALSE

/**
 * @brief   Slave mode support flag.
 */
#define SPI_SUPPORTS_SLAVE_MODE TRUE

#if !defined(SAM_SPI0_DMATX_CHANNEL)
#define SAM_SPI0_DMATX_CHANNEL SAM_DMAC_NUM_MAX
#endif

#if !defined(SAM_SPI0_DMARX_CHANNEL)
#define SAM_SPI0_DMARX_CHANNEL SAM_DMAC_NUM_MAX
#endif

#if !defined(SAM_SPI0_DMA_PRIO)
#define SAM_SPI0_DMA_PRIO 1
#endif

#if !defined(SAM_SPI1_DMATX_CHANNEL)
#define SAM_SPI1_DMATX_CHANNEL SAM_DMAC_NUM_MAX
#endif

#if !defined(SAM_SPI1_DMARX_CHANNEL)
#define SAM_SPI1_DMARX_CHANNEL SAM_DMAC_NUM_MAX
#endif

#if !defined(SAM_SPI1_DMA_PRIO)
#define SAM_SPI1_DMA_PRIO 1
#endif

#if !defined(SAM_SPI2_DMATX_CHANNEL)
#define SAM_SPI2_DMATX_CHANNEL SAM_DMAC_NUM_MAX
#endif

#if !defined(SAM_SPI2_DMARX_CHANNEL)
#define SAM_SPI2_DMARX_CHANNEL SAM_DMAC_NUM_MAX
#endif

#if !defined(SAM_SPI2_DMA_PRIO)
#define SAM_SPI2_DMA_PRIO 1
#endif

#if !defined(SAM_SPI3_DMATX_CHANNEL)
#define SAM_SPI3_DMATX_CHANNEL SAM_DMAC_NUM_MAX
#endif

#if !defined(SAM_SPI3_DMARX_CHANNEL)
#define SAM_SPI3_DMARX_CHANNEL SAM_DMAC_NUM_MAX
#endif

#if !defined(SAM_SPI3_DMA_PRIO)
#define SAM_SPI3_DMA_PRIO 1
#endif

#if !defined(SAM_SPI4_DMATX_CHANNEL)
#define SAM_SPI4_DMATX_CHANNEL SAM_DMAC_NUM_MAX
#endif

#if !defined(SAM_SPI4_DMARX_CHANNEL)
#define SAM_SPI4_DMARX_CHANNEL SAM_DMAC_NUM_MAX
#endif

#if !defined(SAM_SPI4_DMA_PRIO)
#define SAM_SPI4_DMA_PRIO 1
#endif

#if !defined(SAM_SPI5_DMATX_CHANNEL)
#define SAM_SPI5_DMATX_CHANNEL SAM_DMAC_NUM_MAX
#endif

#if !defined(SAM_SPI5_DMARX_CHANNEL)
#define SAM_SPI5_DMARX_CHANNEL SAM_DMAC_NUM_MAX
#endif

#if !defined(SAM_SPI5_DMA_PRIO)
#define SAM_SPI5_DMA_PRIO 1
#endif
/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    PLATFORM configuration options
 * @{
 */

/**
 * @brief   SPI1 driver enable switch.
 * @details If set to @p TRUE the support for SPI1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_SPI_USE_SERCOM0) || defined(__DOXYGEN__)
#define SAM_SPI_USE_SERCOM0 FALSE
#endif

/**
 * @brief   SPI2 driver enable switch.
 * @details If set to @p TRUE the support for SPI2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_SPI_USE_SERCOM1) || defined(__DOXYGEN__)
#define SAM_SPI_USE_SERCOM1 FALSE
#endif

/**
 * @brief   SPI3 driver enable switch.
 * @details If set to @p TRUE the support for SPI3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_SPI_USE_SERCOM2) || defined(__DOXYGEN__)
#define SAM_SPI_USE_SERCOM2 FALSE
#endif

/**
 * @brief   SPI4 driver enable switch.
 * @details If set to @p TRUE the support for SPI4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_SPI_USE_SERCOM3) || defined(__DOXYGEN__)
#define SAM_SPI_USE_SERCOM3 FALSE
#endif

/**
 * @brief   SPI5 driver enable switch.
 * @details If set to @p TRUE the support for SPI5 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_SPI_USE_SERCOM4) || defined(__DOXYGEN__)
#define SAM_SPI_USE_SERCOM4 FALSE
#endif

/**
 * @brief   SPI6 driver enable switch.
 * @details If set to @p TRUE the support for SPI6 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_SPI_USE_SERCOM5) || defined(__DOXYGEN__)
#define SAM_SPI_USE_SERCOM5 FALSE
#endif

/**
 * @brief SPI Driver requires DMAC to be enabled
 *
 */
#if !defined(SAM_DMAC_REQUIRED)
#define SAM_DMAC_REQUIRED
#endif

/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if SAM_SPI_USE_SERCOM0 == TRUE
#if SAM_SIO_USE_SERCOM0 == TRUE || SAM_I2C_USE_SERCOM0 == TRUE
#error "SERCOM0: Can only configured as one function only"
#endif
#endif

#if SAM_SPI_USE_SERCOM1 == TRUE
#if SAM_SIO_USE_SERCOM1 == TRUE || SAM_I2C_USE_SERCOM1 == TRUE
#error "SERCOM1: Can only configured as one function only"
#endif
#endif

#if SAM_SPI_USE_SERCOM2 == TRUE
#if SAM_SIO_USE_SERCOM2 == TRUE || SAM_I2C_USE_SERCOM2 == TRUE
#error "SERCOM2: Can only configured as one function only"
#endif
#endif

#if SAM_SPI_USE_SERCOM3 == TRUE
#if SAM_SIO_USE_SERCOM3 == TRUE || SAM_I2C_USE_SERCOM3 == TRUE
#error "SERCOM3: Can only configured as one function only"
#endif
#endif

#if SAM_SPI_USE_SERCOM4 == TRUE
#if SAM_SIO_USE_SERCOM4 == TRUE || SAM_I2C_USE_SERCOM4 == TRUE
#error "SERCOM4: Can only configured as one function only"
#endif
#endif

#if SAM_SPI_USE_SERCOM5 == TRUE
#if SAM_SIO_USE_SERCOM5 == TRUE || SAM_I2C_USE_SERCOM5 == TRUE
#error "SERCOM5: Can only configured as one function only"
#endif
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Low level fields of the SPI driver structure.
 */
#define spi_lld_driver_fields   \
  sercom_spim_registers_t *spi; \
  uint32_t clock;               \
  uint8_t dmaTxId;              \
  uint8_t dmaRxId;              \
  uint32_t rxsink;              \
  uint32_t txsource;

/**
 * @brief   Low level fields of the SPI configuration structure.
 */
#define spi_lld_config_fields \
  uint32_t ctrla;             \
  uint32_t ctrlb;             \
  uint32_t freq;

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/**
 * @brief   SPI1 driver identifier.
 */
#if (SAM_SPI_USE_SERCOM0 == TRUE) || defined(__DOXYGEN__)
extern SPIDriver SPID1;
#endif

/**
 * @brief   SPI2 driver identifier.
 */
#if (SAM_SPI_USE_SERCOM1 == TRUE) || defined(__DOXYGEN__)
extern SPIDriver SPID2;
#endif

/**
 * @brief   SPI3 driver identifier.
 */
#if (SAM_SPI_USE_SERCOM2 == TRUE) || defined(__DOXYGEN__)
extern SPIDriver SPID3;
#endif

/**
 * @brief   SPI4 driver identifier.
 */
#if (SAM_SPI_USE_SERCOM3 == TRUE) || defined(__DOXYGEN__)
extern SPIDriver SPID4;
#endif

/**
 * @brief   SPI5 driver identifier.
 */
#if (SAM_SPI_USE_SERCOM4 == TRUE) || defined(__DOXYGEN__)
extern SPIDriver SPID5;
#endif

/**
 * @brief   SPI6 driver identifier.
 */
#if (SAM_SPI_USE_SERCOM5 == TRUE) || defined(__DOXYGEN__)
extern SPIDriver SPID6;
#endif

#ifdef __cplusplus
extern "C"
{
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
