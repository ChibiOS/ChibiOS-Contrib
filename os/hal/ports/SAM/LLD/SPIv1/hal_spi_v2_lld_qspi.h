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

#ifndef HAL_SPI_V2_LLD_QSPI_H
#define HAL_SPI_V2_LLD_QSPI_H

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

#if !defined(SAM_QSPI1_DMATX_CHANNEL)
#define SAM_QSPI1_DMATX_CHANNEL SAM_DMAC_NUM_MAX
#endif

#if !defined(SAM_QSPI1_DMARX_CHANNEL)
#define SAM_QSPI1_DMARX_CHANNEL SAM_DMAC_NUM_MAX
#endif

#if !defined(SAM_QSPI1_DMA_PRIO)
#define SAM_QSPI1_DMA_PRIO 1
#endif
/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    PLATFORM configuration options
 * @{
 */

/**
 * @brief   QSPI1 SPI Mode driver enable switch.
 * @details If set to @p TRUE the support for SPI1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SAM_SPI_USE_QSPI1) || defined(__DOXYGEN__)
#define SAM_SPI_USE_QSPI1 FALSE
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

#if SAM_SPI_USE_QSPI1 == TRUE
#if SAM_WSPI_USE_QSPI1 == TRUE
#error "QSPI1: Can only configured as one function only"
#endif
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/
typedef struct {
    /* CTRLB register */
    uint32_t ctrlb;
    /* Desired frequency, it will calculate the baud based on the input clock */   
    uint32_t freq; 
    /* DELAY before SCK, check the calculation on DLYBS on QSPI Driver */
    uint8_t dlybs; 
    /* CPOL register, check the description in BAUD Register */
    bool cpol; 
    /* CPHA register */
    bool cpha; 
} qspi_spi_config_t;
/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/
/**
* @brief   SPI9 driver identifier.
*/
#if (SAM_SPI_USE_QSPI1 == TRUE) || defined(__DOXYGEN__)
extern SPIDriver SPID9;
#endif

#ifdef __cplusplus
extern "C" {
#endif
void qspi_spi_lld_init();
msg_t qspi_spi_lld_start(SPIDriver* spip);
void qspi_spi_lld_stop(SPIDriver* spip);
#if (SPI_SELECT_MODE == SPI_SELECT_MODE_LLD) || defined(__DOXYGEN__)
void qspi_spi_lld_select(SPIDriver* spip);
void qspi_spi_lld_unselect(SPIDriver* spip);
#endif
msg_t qspi_spi_lld_ignore(SPIDriver* spip, size_t n);
msg_t qspi_spi_lld_exchange(SPIDriver* spip, size_t n, const void* txbuf,
                       void* rxbuf);
msg_t qspi_spi_lld_send(SPIDriver* spip, size_t n, const void* txbuf);
msg_t qspi_spi_lld_receive(SPIDriver* spip, size_t n, void* rxbuf);
msg_t qspi_spi_lld_stop_transfer(SPIDriver* spip, size_t* sizep);
uint16_t qspi_spi_lld_polled_exchange(SPIDriver* spip, uint16_t frame);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_SPI */

#endif /* HAL_SPI_V2_LLD_H */

/** @} */
