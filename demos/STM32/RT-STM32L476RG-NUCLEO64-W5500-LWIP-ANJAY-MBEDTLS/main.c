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

#include "hal.h"
#include "cmsis_os.h"
#include "avs_test_task.h"
#include "lwipthread.h"


/*
 * 1) The MAC address usually comes from factory settings which are stored somewhere in ROM.
 * 2) The MAC address can be generated by https://gist.githubusercontent.com/pklaus/9638536/raw/2fe075503fda54fc00f5b6d2a4398a7208e085f4/randmac.py
 */
static uint8_t mac_address[6] = { 0x7e, 0x2f, 0xa2, 0xc0, 0xd0, 0xf8 };

static const SPIConfig spi_config = {
  .circular = false,
  .slave = false,
  .ssport = PAL_PORT(LINE_W5500_NSS),
  .sspad = PAL_PAD(LINE_W5500_NSS),
  /* W5500 supports SPI mode 0 and 3. Here we go with mode 3. */
  .cr1 = SPI_CR1_MSTR |                       /* Master Configuration */
  SPI_CR1_CPHA |                              /* The second clock transition is the first data capture edge */
  SPI_CR1_CPOL |                              /* Clock Polarity to 1 when idle */
  SPI_CR1_BR_0 | SPI_CR1_BR_1 | SPI_CR1_BR_2, /* Baud Rate is fPCLK /256 */
  .cr2 = SPI_CR2_DS_0 | SPI_CR2_DS_1 | SPI_CR2_DS_2  /* Data size is 8-bit */
};

static const ETHSPIConfig eth_config = {
  .driver = &SPID1,
  .config = &spi_config,

  .reset_line = LINE_W5500_RST,
  .reset_trc_delay_ms = 100,
  .reset_tpl_delay_ms = 300,

#if ETH_USE_CALLBACKS == TRUE
  .irq_line = LINE_W5500_INT,
#endif
};

static const ETHPhyConfig phy_config = {
  .conf_by = ETH_PHY_CONF_BY_SW,
  .mode = ETH_PHY_MODE_AUTO,
  .speed = ETH_PHY_SPEED_100,
  .duplex = ETH_PHY_DUPLEX_FULL
};

MACDriver ETHD1 = {
  .spi_config = &eth_config,
  .phy_config = &phy_config,
};

static const lwipthread_opts_t lwip_opts = {
  .macaddress = mac_address,
  .addrMode = NET_ADDRESS_DHCP,
};

static const uint8_t PSK_KEY[] = { 5, 4, 3, 2, 1 };

static const avs_test_opts_t avs_test_opts = {
  .dst_ip_addr = "192.168.2.136",
  .dst_port_coap_udp = "5683",
  .dst_coap_udp_ssl = "5684",
  .dst_coap_tcp = "6683",
  .dst_coap_tcp_ssl = "6684",

  .psk_identity = "12345",
  .psk_key = PSK_KEY,
  .psk_key_size = sizeof(PSK_KEY),
};

int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   */
  halInit();

  /* The kernel is initialized but not started yet, this means that
     main() is executing with absolute priority but interrupts are
     already enabled.*/
  osKernelInitialize();

  /* Kernel started, the main() thread has priority osPriorityNormal by default.*/
  osKernelStart();

  trngStart(&TRNGD1, NULL);

  lwipInit(&lwip_opts);

  avsTestInit(&avs_test_opts);

  /*
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  while (true) {
    osDelay(osWaitForever);
  }

  return 0;
}
