/*
    W5500 for ChibiOS/RT - Copyright (C) 2023 Xael South

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

#include "ch.h"
#include "hal.h"

#include "hal_mac_lld.h"
#include "w5500_lld.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define W5500_MSB(n)               (((n) >> 8) & 0xFF)
#define W5500_LSB(n)               (((n) >> 0) & 0xFF)

#define W5500_RWB_READ             (0x00 << 2) //< Read Access Mode Bit
#define W5500_RWB_WRITE            (0x01 << 2) //< Write Access Mode Bit

#define W5500P_BSB_COMMON          (block_select_t)(0x00 << 3)  //< Select Common Register
#define W5500P_BSB_SOCKET          (block_select_t)(0x01 << 3)  //< Select Socket 0 Register
#define W5500P_BSB_TX_BUF          (block_select_t)(0x02 << 3)  //< Select TX buffer
#define W5500P_BSB_RX_BUF          (block_select_t)(0x03 << 3)  //< Select RX buffer

#define W5500_IO_COMMON_BASE       0x0000

#define W5500_IO_MR                (io_address_t)(W5500_IO_COMMON_BASE + 0x0000)
#define W5500_MR_RST                        (1 << 7)

#define W5500_IO_SNCR              (io_address_t)(W5500_IO_COMMON_BASE + 0x0001)

#define W5500_IO_SHAR              (io_address_t)(W5500_IO_COMMON_BASE + 0x0009)

#define W5500_IO_SIMR              (io_address_t)(W5500_IO_COMMON_BASE + 0x0018)
#define W5500_SIMR_S0_INT                   (1 << 0)

#define W5500_IO_PHYCFGR           (io_address_t)(W5500_IO_COMMON_BASE + 0x002E)
#define W5500_PHYCFGR_RST                   (1 << 7)
#define W5500_PHYCFGR_OPMD                  (1 << 6)
#define W5500_PHYCFGR_OPMDC_AUTONEGOTIATION (1 << 5)
#define W5500_PHYCFGR_OPMDC_SPEED_100       (1 << 4)
#define W5500_PHYCFGR_OPMDC_FULL_DUPLEX     (1 << 3)
#define W5500_PHYCFGR_PWR_DOWN              ((1 << 5) | (1 << 4) | (0 << 3))
#define W5500_PHYCFGR_STATUS_DPX_FULL       (1 << 2)
#define W5500_PHYCFGR_STATUS_SPD_100        (1 << 1)
#define W5500_PHYCFGR_STATUS_LNK_UP         (1 << 0)

#define W5500_IO_VERSIONR          (io_address_t)(W5500_IO_COMMON_BASE + 0x0039)


#define W5500_IO_SOCKET_BASE      0x0000
#define W5500_IO_SN_MR            (io_address_t)(W5500_IO_SOCKET_BASE + 0x0000)
#define W5500_SN_MR_PROTO_MASK      0x0F
#define W5500_SN_MR_PROTO_TCP       (1 << 0)
#define W5500_SN_MR_PROTO_UDP       (1 << 1)
#define W5500_SN_MR_PROTO_MACRAW    (1 << 2)

#define W5500_IO_SN_CR            (io_address_t)(W5500_IO_SOCKET_BASE + 0x0001)
#define W5500_SN_CR_OPEN            (0x01)
#define W5500_SN_CR_CLOSE           (0x10)
#define W5500_SN_CR_SEND            (0x20)
#define W5500_SN_CR_RECV            (0x40)

#define W5500_IO_SN_IR            (io_address_t)(W5500_IO_SOCKET_BASE + 0x0002)
#define W5500_SN_IR_CON             (1 << 0)
#define W5500_SN_IR_DISCON          (1 << 1)
#define W5500_SN_IR_RECV            (1 << 2)
#define W5500_SN_IR_TIMEOUT         (1 << 3)
#define W5500_SN_IR_SEND_OK         (1 << 4)
#define W5500_SN_IR_CLEAR_ALL       (W5500_SN_IR_CON | W5500_SN_IR_DISCON | W5500_SN_IR_RECV | \
                                    W5500_SN_IR_TIMEOUT | W5500_SN_IR_SEND_OK)

#define W5500_IO_SN_SR            (io_address_t)(W5500_IO_SOCKET_BASE + 0x0003)
#define W5500_SN_SR_SOCK_CLOSED     (0x00)
#define W5500_SN_SR_SOCK_MACRAW     (0x42)

#define W5500_IO_SN_RXBUF_SIZE    (io_address_t)(W5500_IO_SOCKET_BASE + 0x001E)
#define W5500_IO_SN_TXBUF_SIZE    (io_address_t)(W5500_IO_SOCKET_BASE + 0x001F)
#define W5500_IO_SN_TX_FSR        (io_address_t)(W5500_IO_SOCKET_BASE + 0x0020)
#define W5500_IO_SN_TX_WR         (io_address_t)(W5500_IO_SOCKET_BASE + 0x0024)
#define W5500_IO_SN_RX_RSR        (io_address_t)(W5500_IO_SOCKET_BASE + 0x0026)
#define W5500_IO_SN_RX_RD         (io_address_t)(W5500_IO_SOCKET_BASE + 0x0028)

#define W5500_IO_SN_IMR           (io_address_t)(W5500_IO_SOCKET_BASE + 0x002C)
#define W5500_SN_IMR_CON            (1 << 0)
#define W5500_SN_IMR_DISCON         (1 << 1)
#define W5500_SN_IMR_RECV           (1 << 2)
#define W5500_SN_IMR_TIMEOUT        (1 << 3)
#define W5500_SN_IMR_SEND_OK        (1 << 4)


/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

typedef uint16_t io_address_t;
typedef uint8_t block_select_t;

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

static uint8_t w5500_read8(SPIDriver *spi, io_address_t address, block_select_t block);
static void w5500_write8(SPIDriver *spi, io_address_t address, block_select_t block, uint8_t val);

#if ETH_USE_CALLBACKS == TRUE
/**
 * @brief   Interrupt handler.
 *
 * @isr
 */
static void w5500_lld_isr(void *arg) {

  chSysLockFromISR();
  MACDriver *macp = arg;
  macp->irq_unhandled = true;
  chEvtBroadcastFlagsI(macGetEventSource(macp), MAC_FLAGS_RX);
  chSysUnlockFromISR();
}
#endif


static void w5500_lld_enable_isr(MACDriver *macp) {
#if ETH_USE_CALLBACKS == TRUE
  chSysLock();

  SPIDriver *spi = macp->spi_config->driver;

  palSetLineCallback(macp->spi_config->irq_line, w5500_lld_isr, macp);
  palEnableLineEvent(macp->spi_config->irq_line, PAL_EVENT_MODE_FALLING_EDGE);

  /* Unmask RECV interrupt. */
  w5500_write8(spi, W5500_IO_SN_IMR, W5500P_BSB_SOCKET, W5500_SN_IMR_RECV);

  /* Clear all pending interrupts. */
  w5500_write8(spi, W5500_IO_SN_IR, W5500P_BSB_SOCKET, W5500_SN_IR_CLEAR_ALL);

  /* Enable RECV interrupt. */
  w5500_write8(spi, W5500_IO_SIMR, W5500P_BSB_COMMON, W5500_SIMR_S0_INT);

  chSysUnlock();
#else
  (void)macp;
#endif
}


static void w5500_lld_disable_isr(MACDriver *macp) {
#if ETH_USE_CALLBACKS == TRUE
  chSysLock();

  SPIDriver *spi = macp->spi_config->driver;

  /* Mask interrupts. */
  w5500_write8(spi, W5500_IO_SN_IMR, W5500P_BSB_SOCKET, 0);

  /* Clear all pending interrupts. */
  w5500_write8(spi, W5500_IO_SN_IR, W5500P_BSB_SOCKET, W5500_SN_IR_CLEAR_ALL);

  /* Disable interrupts. */
  w5500_write8(spi, W5500_IO_SIMR, W5500P_BSB_COMMON, 0);

  palDisableLineEvent(macp->spi_config->irq_line);
  palSetLineCallback(macp->spi_config->irq_line, NULL, NULL);

  chSysUnlock();
#else
  (void)macp;
#endif
}

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void w5500_read(SPIDriver *spi, io_address_t address, block_select_t block, size_t buflen,
                       void *buf) {

  const uint8_t cmd[3] = {
    W5500_MSB(address),
    W5500_LSB(address),
    block | W5500_RWB_READ
  };

#if ETH_USE_MUTUAL_EXCLUSION == TRUE
  spiAcquireBus(spi);
#endif

  spiSelect(spi);
  spiSend(spi, sizeof(cmd), cmd);
  spiReceive(spi, buflen, buf);
  spiUnselect(spi);

#if ETH_USE_MUTUAL_EXCLUSION == TRUE
  spiReleaseBus(spi);
#endif
}


static void w5500_write(SPIDriver *spi, io_address_t address, block_select_t block, size_t buflen,
                        const void *buf) {

  const uint8_t cmd[3] = {
    W5500_MSB(address),
    W5500_LSB(address),
    block | W5500_RWB_WRITE
  };

#if ETH_USE_MUTUAL_EXCLUSION == TRUE
  spiAcquireBus(spi);
#endif

  spiSelect(spi);
  spiSend(spi, sizeof(cmd), cmd);

  if (buf && buflen > 0) {
    spiSend(spi, buflen, buf);
  }

  spiUnselect(spi);

#if ETH_USE_MUTUAL_EXCLUSION == TRUE
  spiReleaseBus(spi);
#endif
}


uint8_t w5500_read8(SPIDriver *spi, io_address_t address, block_select_t block) {
  uint8_t ret;

  w5500_read(spi, address, block, sizeof(ret), &ret);
  return ret;
}


static uint16_t w5500_read16(SPIDriver *spi, io_address_t address, block_select_t block) {
  uint16_t prev, last;

  last = ((uint16_t)w5500_read8(spi, address + 0, block) << 8) |
         ((uint16_t)w5500_read8(spi, address + 1, block) << 0);

  do {
    prev = last;
    last = ((uint16_t)w5500_read8(spi, address + 0, block) << 8) |
           ((uint16_t)w5500_read8(spi, address + 1, block) << 0);
  } while (prev != last);

  return last;
}


void w5500_write8(SPIDriver *spi, io_address_t address, block_select_t block, uint8_t val) {
  w5500_write(spi, address, block, sizeof(val), &val);
}


static void w5500_write16(SPIDriver *spi, io_address_t address, block_select_t block,
                          uint16_t val) {
  w5500_write8(spi, address + 0, block, W5500_MSB(val));
  w5500_write8(spi, address + 1, block, W5500_LSB(val));
}


static void w5500_lld_hw_reset(const ETHSPIConfig *spicfg) {
  palClearLine(spicfg->reset_line);
  chThdSleepMilliseconds(spicfg->reset_trc_delay_ms);

  palSetLine(spicfg->reset_line);
  chThdSleepMilliseconds(spicfg->reset_tpl_delay_ms);
}


#if 0
static void w5500_lld_sw_reset(SPIDriver *spi) {
  w5500_write8(spi, W5500_IO_MR, W5500P_BSB_COMMON, W5500_MR_RST);
}


static uint8_t w5500_lld_get_version(SPIDriver *spi) {
  return w5500_read8(spi, W5500_IO_VERSIONR, W5500P_BSB_COMMON);
}


static bool w5500_lld_probe(MACDriver *macp) {

  uint8_t chip_version;
  SPIDriver *spi = macp->spi_config->driver;

  chip_version = w5500_lld_get_version(spi);

  if (chip_version == W5500_CHIP_ID)
    return true;

  return false;
}


static void w5500_lld_get_phy_mode(MACDriver *macp, ETHPhyConfig *chipcfg) {
  SPIDriver *spi = macp->spi_config->driver;

  uint8_t phycfg = w5500_read8(spi, W5500_IO_PHYCFGR, W5500P_BSB_COMMON);

  if (phycfg & W5500_PHYCFGR_OPMD) {
    chipcfg->conf_by = ETH_PHY_CONF_BY_SW;
  } else {
    chipcfg->conf_by = ETH_PHY_CONF_BY_HW;
  }

  if (phycfg & W5500_PHYCFGR_OPMDC_FULL_DUPLEX) {
    chipcfg->duplex = ETH_PHY_DUPLEX_FULL;
  } else {
    chipcfg->duplex = ETH_PHY_DUPLEX_HALF;
  }

  if (phycfg & W5500_PHYCFGR_OPMDC_SPEED_100) {
    chipcfg->speed = ETH_PHY_SPEED_100;
  } else {
    chipcfg->speed = ETH_PHY_SPEED_10;
  }

  if (phycfg & W5500_PHYCFGR_OPMDC_AUTONEGOTIATION) {
    chipcfg->mode = ETH_PHY_MODE_AUTO;
  } else {
    chipcfg->mode = ETH_PHY_MODE_MANUAL;
  }
}
#endif


static void w5500_lld_clear_pending_irqs(SPIDriver *spi) {

  w5500_write8(spi, W5500_IO_SN_IR, W5500P_BSB_SOCKET, W5500_SN_IR_CLEAR_ALL);
}


static void w5500_lld_set_mac_address(SPIDriver *spi, const uint8_t mac[6] ) {

  w5500_write(spi, W5500_IO_SHAR, W5500P_BSB_COMMON, 6, mac);
}


static void w5500_lld_pwr_down(SPIDriver *spi) {
  uint8_t phycfg;

  phycfg = w5500_read8(spi, W5500_IO_PHYCFGR, W5500P_BSB_COMMON);
  phycfg |= W5500_PHYCFGR_PWR_DOWN;
  w5500_write8(spi, W5500_IO_PHYCFGR, W5500P_BSB_COMMON, phycfg);
}


static void w5500_lld_set_tx_buffer_size(SPIDriver *spi, size_t buf_size_kb) {
  w5500_write8(spi, W5500_IO_SN_TXBUF_SIZE, W5500P_BSB_SOCKET, buf_size_kb);
}


static void w5500_lld_set_rx_buffer_size(SPIDriver *spi, size_t buf_size_kb) {

  w5500_write8(spi, W5500_IO_SN_RXBUF_SIZE, W5500P_BSB_SOCKET, buf_size_kb);
}


static void w5500_lld_set_socket_mode_raw(SPIDriver *spi) {
  uint8_t tmp = w5500_read8(spi, W5500_IO_SN_MR, W5500P_BSB_SOCKET);

  tmp &= ~W5500_SN_MR_PROTO_MASK;
  tmp |= W5500_SN_MR_PROTO_MACRAW;
  w5500_write8(spi, W5500_IO_SN_MR, W5500P_BSB_SOCKET, W5500_SN_MR_PROTO_MACRAW);
}


static void w5500_lld_open_socket(SPIDriver *spi) {

  w5500_write8(spi, W5500_IO_SN_CR, W5500P_BSB_SOCKET, W5500_SN_CR_OPEN);
}


static void w5500_lld_close_socket(SPIDriver *spi) {

  w5500_write8(spi, W5500_IO_SN_CR, W5500P_BSB_SOCKET, W5500_SN_CR_CLOSE);
}


static void w5500_lld_set_phy_mode(MACDriver *macp, const ETHPhyConfig *chipcfg) {
  SPIDriver *spi = macp->spi_config->driver;

  uint8_t phycfg = w5500_read8(spi, W5500_IO_PHYCFGR, W5500P_BSB_COMMON);

  if (chipcfg == NULL)
    chipcfg = macp->phy_config;

  if (chipcfg->conf_by == ETH_PHY_CONF_BY_SW) {
    phycfg |= W5500_PHYCFGR_OPMD;
  } else {
    phycfg &= ~W5500_PHYCFGR_OPMD;
  }

  if (chipcfg->duplex == ETH_PHY_DUPLEX_FULL) {
    phycfg |= W5500_PHYCFGR_OPMDC_FULL_DUPLEX;
  } else {
    phycfg &= ~W5500_PHYCFGR_OPMDC_FULL_DUPLEX;
  }

  if (chipcfg->speed == ETH_PHY_SPEED_100) {
    phycfg |= W5500_PHYCFGR_OPMDC_SPEED_100;
  } else {
    phycfg &= ~W5500_PHYCFGR_OPMDC_SPEED_100;
  }

  if (chipcfg->mode == ETH_PHY_MODE_AUTO) {
    phycfg |= W5500_PHYCFGR_OPMDC_AUTONEGOTIATION;
  } else {
    phycfg &= ~W5500_PHYCFGR_OPMDC_AUTONEGOTIATION;
  }

  /* Reset PHY by setting the RST bit to '0' after the user configures this bit as '1'. */
  phycfg &= ~W5500_PHYCFGR_RST;
  w5500_write8(spi, W5500_IO_PHYCFGR, W5500P_BSB_COMMON, phycfg);
  /* And enable again. */
  phycfg |= W5500_PHYCFGR_RST;
  w5500_write8(spi, W5500_IO_PHYCFGR, W5500P_BSB_COMMON, phycfg);
}


static void w5500_lld_init(void) {

}


static void w5500_lld_start(MACDriver *macp) {
  SPIDriver *spi = macp->spi_config->driver;

  w5500_lld_hw_reset(macp->spi_config);

  w5500_lld_set_phy_mode(macp, NULL);

  w5500_lld_set_mac_address(spi, macp->config->mac_address);

  w5500_lld_set_tx_buffer_size(spi, 16);

  w5500_lld_set_rx_buffer_size(spi, 16);

  w5500_lld_set_socket_mode_raw(spi);

  w5500_lld_open_socket(spi);

  w5500_lld_enable_isr(macp);
}


static bool w5500_lld_poll_link_status(MACDriver *macp) {
  SPIDriver *spi = macp->spi_config->driver;

  uint8_t phycfg = w5500_read8(spi, W5500_IO_PHYCFGR, W5500P_BSB_COMMON);

  if (phycfg & W5500_PHYCFGR_STATUS_LNK_UP)
    return true;

  return false;
}


static void w5500_lld_stop(MACDriver *macp) {
  SPIDriver *spi = macp->spi_config->driver;

  w5500_lld_disable_isr(macp);

  w5500_lld_close_socket(spi);

  w5500_lld_pwr_down(spi);
}


static size_t w5500_lld_get_free_bytes(SPIDriver *spi) {

  if (W5500_SN_SR_SOCK_MACRAW != w5500_read8(spi, W5500_IO_SN_SR, W5500P_BSB_SOCKET))
    return 0;

  return w5500_read16(spi, W5500_IO_SN_TX_FSR, W5500P_BSB_SOCKET);
}


static uint16_t w5500_lld_get_tx_ptr(SPIDriver *spi) {
  return w5500_read16(spi, W5500_IO_SN_TX_WR, W5500P_BSB_SOCKET);
}


static size_t w5500_lld_write_transmit(SPIDriver *spi, const void *txbuf, size_t n) {

  uint16_t ptr = w5500_lld_get_tx_ptr(spi);
  w5500_write(spi, ptr, W5500P_BSB_TX_BUF, n, txbuf);
  ptr = (size_t)ptr + n;
  w5500_write16(spi, W5500_IO_SN_TX_WR, W5500P_BSB_SOCKET, ptr);
  w5500_write8(spi, W5500_IO_SN_CR, W5500P_BSB_SOCKET, W5500_SN_CR_SEND);

  while (true) {
    uint8_t status = w5500_read8(spi, W5500_IO_SN_IR, W5500P_BSB_SOCKET);

    if (status & W5500_SN_IR_TIMEOUT) {
      w5500_write8(spi, W5500_IO_SN_IR, W5500P_BSB_SOCKET, W5500_SN_IR_TIMEOUT);
      return 0;
    }

    if (status & W5500_SN_IR_SEND_OK) {
      w5500_write8(spi, W5500_IO_SN_IR, W5500P_BSB_SOCKET, W5500_SN_IR_SEND_OK);
      break;
    }
  }

  return n;
}


static size_t w5500_lld_get_bytes_received(SPIDriver *spi) {
  return w5500_read16(spi, W5500_IO_SN_RX_RSR, W5500P_BSB_SOCKET);
}


static uint16_t w5500_lld_get_rx_ptr(SPIDriver *spi) {
  return w5500_read16(spi, W5500_IO_SN_RX_RD, W5500P_BSB_SOCKET);
}


static size_t w5500_lld_read_receive(SPIDriver *spi, void *rxbuf, size_t n) {

  uint16_t ptr = w5500_lld_get_rx_ptr(spi);

  /* First two bytes contain the length of data that is following.
   * The length itself is not really useful, so skip it. */
#define W5500_RX_FRAME_HEADER_SIZE 2
  ptr += W5500_RX_FRAME_HEADER_SIZE;
  n -= W5500_RX_FRAME_HEADER_SIZE;

  w5500_read(spi, ptr, W5500P_BSB_RX_BUF, n, rxbuf);
  ptr = (size_t)ptr + n;
  w5500_write16(spi, W5500_IO_SN_RX_RD, W5500P_BSB_SOCKET, ptr);
  w5500_write8(spi, W5500_IO_SN_CR, W5500P_BSB_SOCKET, W5500_SN_CR_RECV);

  return n;
}

static uint16_t w5500_lld_get_rx_frame_length(SPIDriver *spi) {

  if (W5500_SN_SR_SOCK_MACRAW != w5500_read8(spi, W5500_IO_SN_SR, W5500P_BSB_SOCKET))
    return 0;

  uint16_t bytes_received = w5500_lld_get_bytes_received(spi);

  if (bytes_received < W5500_RX_FRAME_HEADER_SIZE) {
    /* Return 0 so that the caller know he must wait for accumulating of more data. */
    return 0;
  }

#define MAX_ETH_FRAME_SIZE 1518

  if (bytes_received > (MAX_ETH_FRAME_SIZE + W5500_RX_FRAME_HEADER_SIZE)) {
    /* Skip all rx data. */
    uint16_t ptr = w5500_lld_get_rx_ptr(spi);
    ptr = (size_t)ptr + bytes_received;
    w5500_write16(spi, W5500_IO_SN_RX_RD, W5500P_BSB_SOCKET, ptr);
    w5500_write8(spi, W5500_IO_SN_CR, W5500P_BSB_SOCKET, W5500_SN_CR_RECV);
    return 0;
  }

#undef W5500_RX_FRAME_HEADER_SIZE
#undef MAX_ETH_FRAME_SIZE

  return bytes_received;
}


/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level MAC initialization.
 *
 * @notapi
 */
void mac_lld_init(void) {

#if PLATFORM_MAC_USE_MAC1 == TRUE
  macObjectInit(&ETHD1);
#endif
  w5500_lld_init();
}

/**
 * @brief   Configures and activates the MAC peripheral.
 *
 * @param[in] macp      pointer to the @p MACDriver object
 *
 * @notapi
 */
void mac_lld_start(MACDriver *macp) {

  if (macp->state == MAC_STOP) {
    spiStart(macp->spi_config->driver, macp->spi_config->config);
    w5500_lld_start(macp);
  }
}

/**
 * @brief   Deactivates the MAC peripheral.
 *
 * @param[in] macp      pointer to the @p MACDriver object
 *
 * @notapi
 */
void mac_lld_stop(MACDriver *macp) {

  if (macp->state != MAC_STOP) {
    w5500_lld_stop(macp);
    spiStop(macp->spi_config->driver);
  }
}

/**
 * @brief   Returns a transmission descriptor.
 * @details One of the available transmission descriptors is locked and
 *          returned.
 *
 * @param[in] macp      pointer to the @p MACDriver object
 * @param[out] tdp      pointer to a @p MACTransmitDescriptor structure
 * @return              The operation status.
 * @retval RDY_OK       the descriptor has been obtained.
 * @retval RDY_TIMEOUT  descriptor not available.
 *
 * @notapi
 */
msg_t mac_lld_get_transmit_descriptor(MACDriver *macp,
                                      MACTransmitDescriptor *tdp) {

  SPIDriver *spi = macp->spi_config->driver;

  size_t bytes_free = w5500_lld_get_free_bytes(spi);

  if (bytes_free == 0)
    return MSG_TIMEOUT;

  tdp->offset = w5500_lld_get_tx_ptr(spi);
  tdp->size = bytes_free;
  tdp->spi_config = macp->spi_config;

  return MSG_OK;
}

/**
 * @brief   Releases a transmit descriptor and starts the transmission of the
 *          enqueued data as a single frame.
 *
 * @param[in] tdp       the pointer to the @p MACTransmitDescriptor structure
 *
 * @notapi
 */
void mac_lld_release_transmit_descriptor(MACTransmitDescriptor *tdp) {

  SPIDriver *spi = tdp->spi_config->driver;

  tdp->offset = 0;
  tdp->size = 0;
  tdp->spi_config = NULL;

  w5500_write8(spi, W5500_IO_SN_CR, W5500P_BSB_SOCKET, W5500_SN_CR_SEND);

  while (true) {
    uint8_t event_mask = 0;
    uint8_t status = w5500_read8(spi, W5500_IO_SN_IR, W5500P_BSB_SOCKET);

    if (status & W5500_SN_IR_TIMEOUT) {
      event_mask |= W5500_SN_IR_TIMEOUT;
    }

    if (status & W5500_SN_IR_SEND_OK) {
      event_mask |= W5500_SN_IR_SEND_OK;
    }

    if (event_mask) {
      w5500_write8(spi, W5500_IO_SN_IR, W5500P_BSB_SOCKET, event_mask);
      break;
    }
  }
}

/**
 * @brief   Returns a receive descriptor.
 *
 * @param[in] macp      pointer to the @p MACDriver object
 * @param[out] rdp      pointer to a @p MACReceiveDescriptor structure
 * @return              The operation status.
 * @retval RDY_OK       the descriptor has been obtained.
 * @retval RDY_TIMEOUT  descriptor not available.
 *
 * @notapi
 */
msg_t mac_lld_get_receive_descriptor(MACDriver *macp,
                                     MACReceiveDescriptor *rdp) {

  SPIDriver *spi = macp->spi_config->driver;

  if (macp->irq_unhandled) {
    macp->irq_unhandled = false;
    w5500_lld_clear_pending_irqs(spi);
  }

  size_t eth_frame_length = w5500_lld_get_rx_frame_length(spi);

  if (eth_frame_length == 0)
    return MSG_TIMEOUT;

  rdp->offset = w5500_lld_get_rx_ptr(spi);
  rdp->size = eth_frame_length;
  rdp->spi_config = macp->spi_config;

  return MSG_OK;
}

/**
 * @brief   Releases a receive descriptor.
 * @details The descriptor and its buffer are made available for more incoming
 *          frames.
 *
 * @param[in] rdp       the pointer to the @p MACReceiveDescriptor structure
 *
 * @notapi
 */
void mac_lld_release_receive_descriptor(MACReceiveDescriptor *rdp) {

  rdp->offset = 0;
  rdp->size = 0;
  rdp->spi_config = NULL;
}

/**
 * @brief   Updates and returns the link status.
 *
 * @param[in] macp      pointer to the @p MACDriver object
 * @return              The link status.
 * @retval TRUE         if the link is active.
 * @retval FALSE        if the link is down.
 *
 * @notapi
 */
bool mac_lld_poll_link_status(MACDriver *macp) {

  return w5500_lld_poll_link_status(macp);
}

/**
 * @brief   Writes to a transmit descriptor's stream.
 *
 * @param[in] tdp       pointer to a @p MACTransmitDescriptor structure
 * @param[in] buf       pointer to the buffer containing the data to be
 *                      written
 * @param[in] size      number of bytes to be written
 * @return              The number of bytes written into the descriptor's
 *                      stream, this value can be less than the amount
 *                      specified in the parameter @p size if the maximum
 *                      frame size is reached.
 *
 * @notapi
 */
size_t mac_lld_write_transmit_descriptor(MACTransmitDescriptor *tdp,
                                         uint8_t *buf,
                                         size_t size) {

  SPIDriver *spi = tdp->spi_config->driver;
  uint16_t ptr;

  if (size > tdp->size) size = tdp->size;

  ptr = tdp->offset;
  w5500_write(spi, ptr, W5500P_BSB_TX_BUF, size, buf);

  ptr = (size_t)ptr + size;
  w5500_write16(spi, W5500_IO_SN_TX_WR, W5500P_BSB_SOCKET, ptr);

  tdp->offset = ptr;
  tdp->size = tdp->size - size;

  return size;
}

/**
 * @brief   Reads from a receive descriptor's stream.
 *
 * @param[in] rdp       pointer to a @p MACReceiveDescriptor structure
 * @param[in] buf       pointer to the buffer that will receive the read data
 * @param[in] size      number of bytes to be read
 * @return              The number of bytes read from the descriptor's
 *                      stream, this value can be less than the amount
 *                      specified in the parameter @p size if there are
 *                      no more bytes to read.
 *
 * @notapi
 */
size_t mac_lld_read_receive_descriptor(MACReceiveDescriptor *rdp,
                                       uint8_t *buf,
                                       size_t size) {

  SPIDriver *spi = rdp->spi_config->driver;
  size_t n = w5500_lld_read_receive(spi, buf, size);

  rdp->offset = w5500_lld_get_rx_ptr(spi);
  rdp->size = w5500_lld_get_rx_frame_length(spi);

  return n;
}
