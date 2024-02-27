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

#include <string.h>

#include "ch.h"
#include "hal.h"

#include "wiznet_chibios.h"
#include "wizchip_conf.h"

#include "socket.h"
#include "dhcp.h"
#include "dns.h"

static SPIDriver *spip;

static void wizchip_select(void) {

  spiSelect(spip);
}


static void wizchip_deselect(void) {

  spiUnselect(spip);
}


static uint8_t wizchip_read_byte(void) {

  uint8_t rb;

  spiReceive(spip, 1, &rb);
  return rb;
}


static void wizchip_write_byte(uint8_t wb) {

  spiSend(spip, 1, &wb);
}


static void wizchip_read_buffer(uint8_t *pBuf, uint16_t len) {

  spiReceive(spip, len, pBuf);
}


static void wizchip_write_buffer(uint8_t *pBuf, uint16_t len) {

  spiSend(spip, len, pBuf);
}


static inline void __wizchipHWReset(const WIZCHIP_ETHSPIConfig *config) {

  palClearLine(config->reset_line);
  chThdSleepMilliseconds(config->reset_trc_delay_ms);

  palSetLine(config->reset_line);
  chThdSleepMilliseconds(config->reset_tpl_delay_ms);
}


#define ETH_SOCKET_BUFFER_SIZE_INITIALIZER      WIZCHIP_MAX_SOCKET_TX_DATA_SIZE_KB, \
                                                WIZCHIP_MAX_SOCKET_TX_DATA_SIZE_KB, \
                                                WIZCHIP_MAX_SOCKET_TX_DATA_SIZE_KB, \
                                                WIZCHIP_MAX_SOCKET_TX_DATA_SIZE_KB, \
                                                WIZCHIP_MAX_SOCKET_TX_DATA_SIZE_KB, \
                                                WIZCHIP_MAX_SOCKET_TX_DATA_SIZE_KB, \
                                                WIZCHIP_MAX_SOCKET_TX_DATA_SIZE_KB, \
                                                WIZCHIP_MAX_SOCKET_TX_DATA_SIZE_KB

static inline int __wizchipInitSocketBufferSize(void) {

  uint8_t sock_buf_size[2] [_WIZCHIP_SOCK_NUM_] = {
    [0] = { ETH_SOCKET_BUFFER_SIZE_INITIALIZER },
    [1] = { ETH_SOCKET_BUFFER_SIZE_INITIALIZER },
  };

  return ctlwizchip(CW_INIT_WIZCHIP, sock_buf_size);
}


static inline int __wizchipConfigurePHY(const WIZCHIP_ETHPhyConfig *phy_config) {

  wiz_PhyConf phyconf;

  phyconf.by = (phy_config->conf_by == ETH_PHY_CONF_BY_HW) ? PHY_CONFBY_HW : PHY_CONFBY_SW;
  phyconf.mode = (phy_config->mode == ETH_PHY_MODE_MANUAL) ? PHY_MODE_MANUAL : PHY_MODE_AUTONEGO;
  phyconf.speed = (phy_config->speed == ETH_PHY_SPEED_10) ? PHY_SPEED_10 : PHY_SPEED_100;
  phyconf.duplex = (phy_config->duplex == ETH_PHY_DUPLEX_HALF) ? PHY_DUPLEX_HALF : PHY_DUPLEX_FULL;

  return ctlwizchip(CW_SET_PHYCONF, &phyconf);
}


void wizchipInit(void) {
}


/**
 * @brief Configures and activates the SPI peripheral.
 * @param[in] spip pointer to the @p WIZCHIPConfig
 *       object
 * @param[in] cfgp pointer to the @p WIZCHIPConfig
 *       object
 * @return The operation status.
 * @api
 */
msg_t wizchipStart(WIZCHIP_MACDriver *wizp, const WIZCHIP_MACConfig *configp) {

  msg_t msg;

  osalDbgCheck((wizp != NULL) && (configp != NULL));

  osalDbgCheck(wizp->spi_config != NULL);
  osalDbgCheck(wizp->phy_config != NULL);
  osalDbgCheck(wizp->net_config != NULL);
  osalDbgCheck(configp->mac_address != NULL);

  wizp->config = configp;

  spip = wizp->spi_config->driver;

  reg_wizchip_cs_cbfunc(wizchip_select, wizchip_deselect);
  reg_wizchip_spi_cbfunc(wizchip_read_byte, wizchip_write_byte);
  reg_wizchip_spiburst_cbfunc(wizchip_read_buffer, wizchip_write_buffer);

  msg = spiStart(wizp->spi_config->driver, wizp->spi_config->config);

  return msg;
}


void wizchipStop(WIZCHIP_MACDriver *wizp) {

  spiStop(wizp->spi_config->driver);

  reg_wizchip_cs_cbfunc(NULL, NULL);
  reg_wizchip_spi_cbfunc(NULL, NULL);
  reg_wizchip_spiburst_cbfunc(NULL, NULL);

  spip = NULL;
}


msg_t wizchipReset(WIZCHIP_MACDriver *wizp) {

  int rc;

  osalDbgCheck(wizp != NULL);
  osalDbgCheck(wizp->config != NULL);

  __wizchipHWReset(wizp->spi_config);

  rc = __wizchipInitSocketBufferSize();

  if (rc != 0)
    return HAL_RET_CONFIG_ERROR;

  rc = __wizchipConfigurePHY(wizp->phy_config);

  if (rc != 0)
    return HAL_RET_CONFIG_ERROR;

  return HAL_RET_SUCCESS;
}


bool wizchipPhyLinkIsUp(WIZCHIP_MACDriver *wizp) {

  int rc;
  int8_t phylink;

  (void)wizp;

  rc = ctlwizchip(CW_GET_PHYLINK, &phylink);

  if (rc != 0)
    return false;

  return (phylink == PHY_LINK_ON);
}


char *wizchipGetId(WIZCHIP_MACDriver *wizp, char chipid[6] ) {

  int rc;

  (void)wizp;

  rc = ctlwizchip(CW_GET_ID, chipid);

  if (rc != 0)
    strcpy(chipid, "?????");

  return chipid;
}


static msg_t wizchipSetIPModeStatic(WIZCHIP_MACDriver *wizp) {

  int rc;
  wiz_NetInfo netinfo;

  osalDbgCheck(wizp != NULL);
  osalDbgCheck(wizp->config->mac_address != NULL);
  osalDbgCheck(wizp->net_config != NULL);

  wizp->net_config->mode = WIZCHIP_NET_ADDRESS_STATIC;

  memcpy(netinfo.mac, wizp->config->mac_address, 6);
  memcpy(netinfo.ip, wizp->net_config->ip.ip, 4);
  memcpy(netinfo.sn, wizp->net_config->sn.sn, 4);
  memcpy(netinfo.gw, wizp->net_config->gw.ip, 4);
  memcpy(netinfo.dns, wizp->net_config->dns.ip, 4);
  netinfo.dhcp = NETINFO_STATIC;

  rc = ctlnetwork(CN_SET_NETINFO, &netinfo);

  if (rc != 0)
    return HAL_RET_CONFIG_ERROR;

  return HAL_RET_SUCCESS;
}


static msg_t wizchipSetIPModeDHCP(WIZCHIP_MACDriver *wizp) {

  int rc;
  wiz_NetInfo netinfo;

  osalDbgCheck(wizp != NULL);
  osalDbgCheck(wizp->config->mac_address != NULL);

  wizp->net_config->mode = WIZCHIP_NET_ADDRESS_DHCP;

  memcpy(netinfo.mac, wizp->config->mac_address, 6);
  memset(netinfo.ip, 0, 4);
  memset(netinfo.sn, 0, 4);
  memset(netinfo.gw, 0, 4);
  memset(netinfo.dns, 0, 4);
  netinfo.dhcp = NETINFO_DHCP;

  rc = ctlnetwork(CN_SET_NETINFO, &netinfo);

  if (rc != 0)
    return HAL_RET_CONFIG_ERROR;

  return HAL_RET_SUCCESS;
}


msg_t wizchipSetIPMode(WIZCHIP_MACDriver *wizp, ip_mode_t ip_mode) {

  osalDbgCheck(wizp != NULL);

  if (ip_mode == WIZCHIP_NET_ADDRESS_STATIC)
    return wizchipSetIPModeStatic(wizp);
  else if (ip_mode == WIZCHIP_NET_ADDRESS_DHCP)
    return wizchipSetIPModeDHCP(wizp);
  else
    osalDbgCheck(true);

  return HAL_RET_CONFIG_ERROR;
}


ip_mode_t wizchipGetIPMode(WIZCHIP_MACDriver *wizp) {

  osalDbgCheck(wizp != NULL);

  return wizp->net_config->mode;
}


dhcp_query_result_t wizchipRefreshDHCPLease(WIZCHIP_MACDriver *wizp, uint32_t waittime_sec,
                                            uint32_t *dhcp_lease_time) {

  dhcp_query_result_t res = DHCP_QUERY_TIMEOUT;

  osalDbgCheck(wizp != NULL);
  osalDbgCheck(waittime_sec > 0);

  DHCP_init(WIZCHIP_DHCP_SOCKET, wizp->eth_frame_buffer);

  const systime_t start = chVTGetSystemTime();
  const systime_t end = chTimeAddX(start, TIME_S2I(waittime_sec));

  while (chVTIsSystemTimeWithin(start, end)) {
    uint8_t dhcp_status = DHCP_run();

    if (dhcp_status == DHCP_IP_ASSIGN ||
        dhcp_status == DHCP_IP_CHANGED ||
        dhcp_status == DHCP_IP_LEASED) {

      getIPfromDHCP(wizp->net_config->ip.ip);
      getSNfromDHCP(wizp->net_config->sn.sn);
      getGWfromDHCP(wizp->net_config->gw.ip);
      getDNSfromDHCP(wizp->net_config->dns.ip);

      if (dhcp_lease_time != NULL)
        *dhcp_lease_time = getDHCPLeasetime();

      res = DHCP_QUERY_SUCCESS;
      break;
    }

    chThdSleepMilliseconds(1000);
    DHCP_time_handler(); /* 1 second tick. */
  }

  DHCP_stop();

  return res;
}


static inline int wizchipIsDomainName(const char *host, IP_Address_t *ip_from_dns) {

  const size_t host_size = strlen(host);
  int dot_count = 0;
  uint8_t *ip = ip_from_dns->ip;

  *ip = 0;

  for (size_t i = 0; i < host_size && dot_count < 4; ++i) {
    if ('0' <= host[i] && host[i] <= '9') {
      *ip *= 10;
      *ip += host[i] - '0';
    } else if (host[i] == '.') {
      ip++;
      *ip = 0;
      dot_count++;
    } else {
      memset(ip_from_dns, 0, sizeof(*ip_from_dns));
      return 1; /* host is a domain name. */
    }
  }

  return 0; /* host is an IP address, NOT a domain name. */
}


dns_query_result_t wizchipDNSQuery(WIZCHIP_MACDriver *wizp, uint32_t waittime_sec, const char *host,
                                   IP_Address_t *ip_from_dns) {

  dns_query_result_t res = DNS_QUERY_TIMEOUT;

  osalDbgCheck(wizp != NULL);
  osalDbgCheck(waittime_sec > 0);
  osalDbgCheck(host != NULL);
  osalDbgCheck(ip_from_dns != NULL);

  if (!wizchipIsDomainName(host, ip_from_dns))
    return DNS_QUERY_SUCCESS;

  DNS_init(WIZCHIP_DNS_SOCKET, wizp->eth_frame_buffer);

  const systime_t start = chVTGetSystemTime();
  const systime_t end = chTimeAddX(start, TIME_S2I(waittime_sec));

  while (chVTIsSystemTimeWithin(start, end)) {
    int8_t dns_status = DNS_run(wizp->net_config->dns.ip, (uint8_t *)host, ip_from_dns->ip);

    if (dns_status == 1) {
      res = DNS_QUERY_SUCCESS;
      break;
    }

    chThdSleepMilliseconds(1000);
    DNS_time_handler(); /* 1 second tick. */
  }

  return res;
}


int wizchipSocket(int domain, int socket_type, int protocol) {

  int sock;

  (void)domain;
  (void)protocol;

  switch (socket_type) {
  case WIZCHIP_TYPE_MAC:
    sock = socket(WIZCHIP_MAC_SOCKET, Sn_MR_MACRAW, WIZCHIP_ANY_PORT, 0);
    break;

  case WIZCHIP_TYPE_RAW:
    sock = socket(WIZCHIP_RAW_SOCKET, Sn_MR_UDP, WIZCHIP_ANY_PORT, 0);
    break;

  case WIZCHIP_TYPE_DGRAM:
    sock = socket(WIZCHIP_UDP_SOCKET, Sn_MR_UDP, WIZCHIP_ANY_PORT, 0);
    break;

  case WIZCHIP_TYPE_STREAM:
    sock = socket(WIZCHIP_TCP_SOCKET, Sn_MR_TCP, WIZCHIP_ANY_PORT, 0);
    break;

  default:
    sock = WIZCHIP_INVALID_SOCKET;
    break;
  }

  return sock;
}


int wizchipClose(int sock) {

  int err = close(sock);

  if (err != SOCK_OK)
    return -1;

  return 0;
}

int wizchipShutdown(int sock) {

  (void)sock;

  return 0;
}


int wizchipConnect(int sock, IP_Address_t *addr, uint16_t port) {

  int err = connect(sock, addr->ip, port);

  if (err != SOCK_OK)
    return -1;

  return 0;
}


int wizchipDisconnect(int sock) {

  int err = disconnect(sock);

  if (err != SOCK_OK)
    return -1;

  return 0;
}

int wizchipSend(int sock, const void *buf, size_t len, int flag) {

  (void)flag;

  int tx_bytes = send(sock, (void *)buf, len);

  return tx_bytes;
}

int wizchipRecv(int sock, void *buf, size_t len, int flag) {

  (void)flag;

  int rx_bytes = recv(sock, buf, len);

  return rx_bytes;
}


int wizchipSendTo(int sock, const void *buf, size_t len, int flag,
                  IP_Address_t *dest_addr, uint16_t dest_port) {

  (void)flag;

  int tx_bytes = sendto(sock, (void *)buf, len, dest_addr->ip, dest_port);

  return tx_bytes;
}


int wizchipRecvFrom(int sock, void *buf, size_t len, int flag,
                    IP_Address_t *dest_addr, uint16_t dest_port) {

  (void)flag;

  int rx_bytes = recvfrom(sock, buf, len, dest_addr->ip, &dest_port);

  return rx_bytes;
}

int wizchipSetSockopt(int sock, int level, int optname,
                      const void *optval, size_t optlen) {

  (void)sock;
  (void)level;
  (void)optname;
  (void)optval;
  (void)optlen;

  return 0;
}

int wizchipGetSockopt(int sock, int level, int optname,
                      const void *optval, size_t optlen) {

  (void)sock;
  (void)level;
  (void)optname;
  (void)optval;
  (void)optlen;

  return 0;
}
