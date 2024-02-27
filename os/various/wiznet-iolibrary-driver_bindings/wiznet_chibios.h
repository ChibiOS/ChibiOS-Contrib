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
 * @file    wiznet_chibios.h
 * @brief   WIZNET Driver macros and structures.
 * @addtogroup WIZNET
 * @{
 */

#ifndef HAL_WIZNET_H
#define HAL_WIZNET_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

enum {
  WIZCHIP_INVALID_SOCKET = -1,
  WIZCHIP_MAC_SOCKET = 0,
  WIZCHIP_RAW_SOCKET,
  WIZCHIP_UDP_SOCKET,
  WIZCHIP_TCP_SOCKET,
  WIZCHIP_DHCP_SOCKET,
  WIZCHIP_DNS_SOCKET,
  WIZCHIP_NTP_SOCKET,
};

typedef enum {
  DHCP_QUERY_SUCCESS = 0,
  DHCP_QUERY_ERROR,
  DHCP_QUERY_TIMEOUT
} dhcp_query_result_t;

typedef enum {
  DNS_QUERY_SUCCESS = 0,
  DNS_QUERY_ERROR,
  DNS_QUERY_TIMEOUT
} dns_query_result_t;

typedef enum {

  WIZCHIP_NET_ADDRESS_STATIC = 0,
  WIZCHIP_NET_ADDRESS_DHCP,
} ip_mode_t;

#define WIZCHIP_DOMAIN_UNIX              0
#define WIZCHIP_DOMAIN_LOCAL             1
#define WIZCHIP_DOMAIN_INET              2

#define WIZCHIP_TYPE_MAC                 0
#define WIZCHIP_TYPE_RAW                 1
#define WIZCHIP_TYPE_DGRAM               2
#define WIZCHIP_TYPE_STREAM              3

#define WIZCHIP_FLAG_MSG_DONTWAIT    (1<<0)
#define WIZCHIP_FLAG_MSG_WAIT        (1<<1)

#define WIZCHIP_SOL_SOCKET               0

#define WIZCHIP_SO_RCVTIMEO              0

enum {
  WIZCHIP_SOCKETS_ERR_OK = 0,
  WIZCHIP_SOCKETS_ERR_DESCRIPTOR,
  WIZCHIP_SOCKETS_ERR_PARAMETER,
  WIZCHIP_SOCKETS_ERR_WOULDBLOCK,
  WIZCHIP_SOCKETS_ERR_NOMEMORY,
  WIZCHIP_SOCKETS_ERR_CLOSING,
  WIZCHIP_SOCKETS_ERR_LOCKED,
  WIZCHIP_SOCKETS_ERR_TIMEOUT,
  WIZCHIP_SOCKETS_ERR_INPROGRESS,
  WIZCHIP_SOCKETS_ERR_NONAME,
  WIZCHIP_SOCKETS_ERR_NONETWORK,
  WIZCHIP_SOCKETS_ERR_UNSUPPORTED,
  WIZCHIP_SOCKETS_ERR_STATE,
  WIZCHIP_SOCKETS_ERR_GENERAL
};

#define WIZCHIP_ANY_PORT       (uint16_t)0

#define ETH_PHY_CONF_BY_HW (eth_phy_conf_t)0
#define ETH_PHY_CONF_BY_SW (eth_phy_conf_t)1

#define ETH_PHY_MODE_MANUAL (eth_phy_mode_t)0
#define ETH_PHY_MODE_AUTO   (eth_phy_mode_t)1

#define ETH_PHY_SPEED_10  (eth_phy_speed_t)0
#define ETH_PHY_SPEED_100 (eth_phy_speed_t)1

#define ETH_PHY_DUPLEX_HALF (eth_phy_duplex_t)0
#define ETH_PHY_DUPLEX_FULL (eth_phy_duplex_t)1

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

#ifndef _WIZCHIP_
#define _WIZCHIP_ W5500 /* Define _WIZCHIP_ as one of W5100, W5100S, W5200, W5300, W5500 (default). */
#endif

#ifndef ETH_FRAME_BUFFER_SIZE
#define ETH_FRAME_BUFFER_SIZE 2048u
#endif

#ifndef WIZCHIP_MAX_SOCKET_TX_DATA_SIZE_KB
#define WIZCHIP_MAX_SOCKET_TX_DATA_SIZE_KB 2u
#endif

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
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#define WIZCHIP_MAX_SOCKET_TX_DATA_SIZE (WIZCHIP_MAX_SOCKET_TX_DATA_SIZE_KB*1024u)

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

typedef struct {
  uint8_t ip[4];
} IP_Address_t;

typedef struct {
  uint8_t sn[4];
} IP_Subnet_t;

typedef int32_t eth_link_state_t;

typedef int32_t eth_phy_conf_t;

typedef int32_t eth_phy_mode_t;

typedef int32_t eth_phy_speed_t;

typedef int32_t eth_phy_duplex_t;


typedef struct {
  SPIDriver *driver;

  const SPIConfig *config;

  ioline_t reset_line;

  uint16_t reset_trc_delay_ms;

  uint16_t reset_tpl_delay_ms;

#if ETH_USE_CALLBACKS == TRUE
  ioline_t irq_line;
#endif
} WIZCHIP_ETHSPIConfig;

typedef struct {
  eth_phy_conf_t    conf_by;

  eth_phy_mode_t    mode;

  eth_phy_speed_t   speed;

  eth_phy_duplex_t  duplex;

} WIZCHIP_ETHPhyConfig;

typedef struct {
  IP_Address_t ip;

  IP_Subnet_t sn;

  IP_Address_t gw;

  IP_Address_t dns;

  ip_mode_t mode;

} WIZCHIP_NetworkConfig;

typedef struct {
  const uint8_t *mac_address;
} WIZCHIP_MACConfig;

typedef struct {
  const WIZCHIP_MACConfig *config;

  const WIZCHIP_ETHSPIConfig *spi_config;

  const WIZCHIP_ETHPhyConfig *phy_config;

  WIZCHIP_NetworkConfig *net_config;

  uint8_t eth_frame_buffer[ETH_FRAME_BUFFER_SIZE];
} WIZCHIP_MACDriver;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

extern WIZCHIP_MACDriver WIZCHIP0;

#ifdef __cplusplus
extern "C"
{
#endif
void wizchipInit(void);

msg_t wizchipStart(WIZCHIP_MACDriver *wizp, const WIZCHIP_MACConfig *configp);

void wizchipStop(WIZCHIP_MACDriver *wizp);

msg_t wizchipReset(WIZCHIP_MACDriver *wizp);

bool wizchipPhyLinkIsUp(WIZCHIP_MACDriver *wizp);

char *wizchipGetId(WIZCHIP_MACDriver *wizp, char chipid[6] );

msg_t wizchipSetIPMode(WIZCHIP_MACDriver *wizp, ip_mode_t ip_mode);

ip_mode_t wizchipGetIPMode(WIZCHIP_MACDriver *wizp);

dhcp_query_result_t
wizchipRefreshDHCPLease(WIZCHIP_MACDriver *wizp, uint32_t waittime_sec,
                        uint32_t *dhcp_lease_time);

dns_query_result_t
wizchipDNSQuery(WIZCHIP_MACDriver *wizp, uint32_t waittime_sec,
                const char *host, IP_Address_t *ip_from_dns);

int wizchipSocket(int domain, int socket_type, int protocol);

int wizchipClose(int sock);

int wizchipShutdown(int sock);

int wizchipConnect(int sock, IP_Address_t *addr, uint16_t port);

int wizchipDisconnect(int sock);

int wizchipSend(int sock, const void *buf, size_t len, int flag);

int wizchipRecv(int sock, void *buf, size_t len, int flag);

int wizchipSendTo(int sock, const void *buf, size_t len, int flag,
                  IP_Address_t *dest_addr, uint16_t dest_port);

int wizchipRecvFrom(int sock, void *buf, size_t len, int flag,
                    IP_Address_t *dest_addr, uint16_t dest_port);

int wizchipSetSockopt(int sock, int level, int optname,
                      const void *optval, size_t optlen);

int wizchipGetSockopt(int sock, int level, int optname,
                      const void *optval, size_t optlen);

#ifdef __cplusplus
}
#endif

#endif /* HAL_WIZNET_H */

/** @} */
