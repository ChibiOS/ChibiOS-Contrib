/*
    ChibiOS - Copyright (C) 2023 Xael South

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
 * @file    SPI_MACv1/hal_mac_lld.h
 * @brief   SPI low level MAC driver header.
 *
 * @addtogroup MAC
 * @{
 */

#ifndef HAL_MAC_LLD_H
#define HAL_MAC_LLD_H

#if HAL_USE_MAC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   This implementation supports the zero-copy mode API.
 */
#define MAC_SUPPORTS_ZERO_COPY      FALSE

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    PLATFORM configuration options
 * @{
 */
/**
 * @brief   MAC driver enable switch.
 * @details If set to @p TRUE the support for MAC1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(PLATFORM_MAC_USE_MAC1) || defined(__DOXYGEN__)
  #define PLATFORM_MAC_USE_MAC1               TRUE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if HAL_USE_SPI == FALSE
  #error "ETH driver requires HAL_USE_SPI"
#endif

#if SPI_USE_WAIT == FALSE
  #error "ETH driver requires SPI_USE_WAIT"
#endif

#define ETH_USE_MUTUAL_EXCLUSION SPI_USE_MUTUAL_EXCLUSION

#if HAL_USE_PAL == FALSE
  #error "ETH driver requires HAL_USE_PAL"
#endif

#define ETH_USE_CALLBACKS        PAL_USE_CALLBACKS

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

#define ETH_PHY_CONF_BY_HW      (eth_phy_conf_t)0
#define ETH_PHY_CONF_BY_SW      (eth_phy_conf_t)1

#define ETH_PHY_DUPLEX_HALF     (eth_phy_duplex_t)0
#define ETH_PHY_DUPLEX_FULL     (eth_phy_duplex_t)1

#define ETH_PHY_MODE_MANUAL     (eth_phy_mode_t)0
#define ETH_PHY_MODE_AUTO       (eth_phy_mode_t)1

#define ETH_PHY_SPEED_10        (eth_phy_speed_t)0
#define ETH_PHY_SPEED_100       (eth_phy_speed_t)1
#define ETH_PHY_SPEED_1000      (eth_phy_speed_t)2

#define ETH_PHY_LINK_DOWN       (eth_phy_link_state_t)0
#define ETH_PHY_LINK_UP         (eth_phy_link_state_t)1
#define ETH_PHY_LINK_UNKNOWN    (eth_phy_link_state_t)-1

typedef int32_t eth_phy_conf_t;

typedef int32_t eth_phy_duplex_t;

typedef int32_t eth_phy_mode_t;

typedef int32_t eth_phy_speed_t;

typedef int32_t eth_phy_link_state_t;

typedef struct {
  void *driver; /* SPIDriver */

  const void *config; /* SPIConfig */

  uint16_t reset_trc_delay_ms;

  uint16_t reset_tpl_delay_ms;

  ioline_t reset_line;

#if ETH_USE_CALLBACKS == TRUE
  ioline_t irq_line;
#endif
} ETHSPIConfig;

typedef struct {
  eth_phy_conf_t    conf_by;

  eth_phy_mode_t    mode;

  eth_phy_speed_t   speed;

  eth_phy_duplex_t  duplex;
} ETHPhyConfig;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Low level fields of the MAC driver structure.
 */
#define mac_lld_driver_fields                                               \
  const ETHSPIConfig            *spi_config;                                \
  const ETHPhyConfig            *phy_config;                                \
  bool irq_unhandled

/**
 * @brief   Low level fields of the MAC configuration structure.
 */
#define mac_lld_config_fields                                               \
  /* MAC address.*/                                                         \
  const uint8_t                 *mac_address

/**
 * @brief   Low level fields of the MAC transmit descriptor structure.
 */
#define mac_lld_transmit_descriptor_fields                                  \
  MACDriver                     *macp

/**
 * @brief   Low level fields of the MAC receive descriptor structure.
 */
#define mac_lld_receive_descriptor_fields                                  \
  MACDriver                     *macp

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (PLATFORM_MAC_USE_MAC1 == TRUE) && !defined(__DOXYGEN__)
extern MACDriver ETHD1;
#endif

#ifdef __cplusplus
extern "C" {
#endif
void mac_lld_init(void);
void mac_lld_start(MACDriver *macp);
void mac_lld_stop(MACDriver *macp);
msg_t mac_lld_get_transmit_descriptor(MACDriver *macp,
                                      MACTransmitDescriptor *tdp);
void mac_lld_release_transmit_descriptor(MACTransmitDescriptor *tdp);
msg_t mac_lld_get_receive_descriptor(MACDriver *macp,
                                     MACReceiveDescriptor *rdp);
void mac_lld_release_receive_descriptor(MACReceiveDescriptor *rdp);
bool mac_lld_poll_link_status(MACDriver *macp);
size_t mac_lld_write_transmit_descriptor(MACTransmitDescriptor *tdp,
                                         uint8_t *buf,
                                         size_t size);
size_t mac_lld_read_receive_descriptor(MACReceiveDescriptor *rdp,
                                       uint8_t *buf,
                                       size_t size);
#if MAC_USE_ZERO_COPY == TRUE
uint8_t *mac_lld_get_next_transmit_buffer(MACTransmitDescriptor *tdp,
                                          size_t size,
                                          size_t *sizep);
const uint8_t *mac_lld_get_next_receive_buffer(MACReceiveDescriptor *rdp,
                                               size_t *sizep);
#endif
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_MAC */

#endif /* HAL_MAC_LLD_H */

/** @} */
