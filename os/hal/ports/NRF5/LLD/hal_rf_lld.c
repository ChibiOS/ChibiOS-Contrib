/*
    ChibiOS - Copyright (C) 2016..2016 Stephane D'Alu

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
 * @file    RF/hal_rf_lld.c
 * @brief   RF subsystem low level driver source.
 *
 * @addtogroup RF
 * @{
 */

#include <string.h>

#include "hal.h"

#if HAL_USE_RF || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define RF_RADIO_MAXLEN             RF_PACKET_MAXLEN
#define RF_RADIO_LEN                8
#define RF_RADIO_S0                 0
#define RF_RADIO_S1                 0
#define RF_RADIO_STATLEN            0
#define RF_RADIO_BALEN              4
#define RF_RADIO_ENDIAN             RADIO_PCNF1_ENDIAN_Little
#define RF_RADIO_WHITENING          RADIO_PCNF1_WHITEEN_Enabled
#define RF_RADIO_CRC_CNF            2U
#define RF_RADIO_CRC_POLY           0x11021
#define RF_RADIO_CRC_INIT           0xF0F0F0
#define RF_RADIO_PREFIX0            0xE7E7E7E7


/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

#if NRF5_RF_USE_RADIO0 && !defined(__DOXYGEN__)
/** @brief RFD1 driver identifier.*/
RFDriver RFD1;
#endif


/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/
static inline
void _set_address(RFDriver *rfp, rf_addr_t addr) {
  rfp->radio->BASE0 &= ~(0xffff);
  rfp->radio->BASE0 |= addr;
}

static void serve_interrupt(RFDriver *rfp) {
  NRF_RADIO_Type *radio = rfp->radio;

  if (radio->EVENTS_READY == 1) {
    radio->EVENTS_READY = 0;
  }
  if (radio->EVENTS_ADDRESS == 1) {
    radio->EVENTS_ADDRESS = 0;
  }
  if (radio->EVENTS_PAYLOAD == 1) {
    radio->EVENTS_PAYLOAD = 0;
  }
  if (radio->EVENTS_DISABLED == 1) {
    radio->EVENTS_DISABLED = 0;
  }

  if (radio->EVENTS_END == 1) {
    radio->EVENTS_END = 0;
      
    rfp->error = RF_ERROR_NONE;
    if (radio->CRCSTATUS != 1) {
      rfp->error = RF_ERROR_CRC;
    }
    
    _rf_isr_code(rfp);
  }
}


/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if NRF5_RF_USE_RADIO0 && !defined(__DOXYGEN__)
OSAL_IRQ_HANDLER(Vector44) {
  OSAL_IRQ_PROLOGUE();
  serve_interrupt(&RFD1);
  OSAL_IRQ_EPILOGUE();
}
#endif


/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

void rf_lld_init(void) {
  rfObjectInit(&RFD1);
  RFD1.thread = NULL;
  RFD1.radio = NRF_RADIO;
}

void rf_lld_stop_receive(RFDriver *rfp) {
  NRF_RADIO_Type *radio = rfp->radio;

  /* Ensure radio is in disabled state */
  radio->EVENTS_DISABLED = 0;
  radio->TASKS_DISABLE = 1;
  while (radio->EVENTS_DISABLED == 0) { /* busy-waiting */ }
}


void rf_lld_stop(RFDriver *rfp) {
  NRF_CLOCK->TASKS_HFCLKSTOP = 1;
  rfp->radio->POWER = 0;
}

void rf_lld_start(RFDriver *rfp) {
  const RFConfig       *cfg   = rfp->config;
        NRF_RADIO_Type *radio = rfp->radio;
  
  osalDbgAssert((cfg->frequency >= 2400) &&
		(cfg->frequency <= 2500),
		"invalid frequency value (2400MHz..2500MHz)");

  osalDbgAssert((cfg->bitrate == RF_BITRATE_250K) ||
		(cfg->bitrate == RF_BITRATE_1M  ) ||
		(cfg->bitrate == RF_BITRATE_2M  ),
		"invalid bitrate value");

  /* Enable the high frequency clock (HFCLK) */
  NRF_CLOCK->TASKS_HFCLKSTART = 1;

  /* Power on the RFs radio */
  radio->POWER = 1;

  /* Specify operating mode */
  radio->MODE = cfg->bitrate;

  /* Set radio frequency */
  radio->FREQUENCY = cfg->frequency - 2400;

  /* Set transmission power (rounded to the nearest allowed value) */
  int8_t power = cfg->power;
  if      (power >   2) { power =   4; }
  else if (power >  -2) { power =   0; }
  else if (power >  -6) { power =  -4; }
  else if (power > -10) { power =  -8; }
  else if (power > -14) { power = -12; }
  else if (power > -18) { power = -16; }
  else if (power > -25) { power = -20; }
  else                  { power = -30; }
  radio->TXPOWER = power;

  /* Set addresses */
  radio->PREFIX0 = RF_RADIO_PREFIX0;
  radio->BASE0 = (cfg->pan_id << 16);
  radio->BASE1 = (cfg->pan_id << 16) | RF_BCAST_ADDR;

  /* Set logical addresses */
  radio->TXADDRESS   = 0X00UL;    /* transmit from address 0 */
  radio->RXADDRESSES = 0X03UL;    /* listen to addresses 0 and 1 */

  /* Configure radio */
  radio->PCNF0 = (RF_RADIO_S1          << RADIO_PCNF0_S1LEN_Pos  ) |
                 (RF_RADIO_S0          << RADIO_PCNF0_S0LEN_Pos  ) |
                 (RF_RADIO_LEN         << RADIO_PCNF0_LFLEN_Pos  ) ;
  radio->PCNF1 = (RF_RADIO_WHITENING   << RADIO_PCNF1_WHITEEN_Pos) |
                 (RF_RADIO_ENDIAN      << RADIO_PCNF1_ENDIAN_Pos ) |
                 (RF_RADIO_BALEN       << RADIO_PCNF1_BALEN_Pos  ) |
                 (RF_RADIO_STATLEN     << RADIO_PCNF1_STATLEN_Pos) |
                 (RF_RADIO_MAXLEN      << RADIO_PCNF1_MAXLEN_Pos ) ;

  /* CRC computation */
  radio->CRCCNF  = RF_RADIO_CRC_CNF;
  radio->CRCPOLY = RF_RADIO_CRC_POLY;
  radio->CRCINIT = RF_RADIO_CRC_INIT;

  /* Enable shortcuts */
  radio->SHORTS = RADIO_SHORTS_READY_START_Msk |
                  RADIO_SHORTS_END_DISABLE_Msk ;

  /* Ensure radio is in disabled state */
  radio->EVENTS_DISABLED = 0;
  radio->TASKS_DISABLE = 1;
  while (radio->EVENTS_DISABLED == 0) { /* busy-waiting */ }
  
  /* Clear events */
  radio->EVENTS_END = 0;
  radio->EVENTS_DISABLED = 0;
  
  /* Enable interrupt */
  radio->INTENSET = RADIO_INTENSET_ADDRESS_Msk  |
                    RADIO_INTENSET_PAYLOAD_Msk  |
                    RADIO_INTENSET_DISABLED_Msk |
                    RADIO_INTENSET_READY_Msk    |
                    RADIO_INTENSET_END_Msk      ;
  nvicEnableVector(RADIO_IRQn, NRF5_RF_RADIO0_IRQ_PRIORITY);
}

void rf_lld_receive(RFDriver *rfp, size_t n, uint8_t *rxbuf) {
  const RFConfig       *cfg   = rfp->config;
        NRF_RADIO_Type *radio = rfp->radio;

  /* Set pointer to receive buffer */
  radio->PACKETPTR = (uint32_t)&rfp->packet;
  /* Set address (used as reception when RX) */
  _set_address(rfp, cfg->src_addr);
  /* Start receiving */
  radio->TASKS_RXEN = 1;
}

void rf_lld_received(RFDriver *rfp, size_t *np, uint8_t *rxbuf) {
  size_t sz = *np;
  *np = rfp->packet.hdr.length;
  if (sz > *np)
    sz = *np;
  memcpy(rxbuf, &rfp->packet.payload, sz);
}

void rf_lld_send(RFDriver *rfp,
		 rf_addr_t addr, size_t n, const uint8_t *txbuf) {
  const RFConfig       *cfg   = rfp->config;
        NRF_RADIO_Type *radio = rfp->radio;

  rfp->packet.hdr.length = n;
  memcpy(rfp->packet.payload, txbuf, n);

  /* Set packet pointer to TX buffer and write destination address */
  radio->PACKETPTR = (uint32_t)&rfp->packet;
  /* Set address (used as destination when TX) */
  _set_address(rfp, addr);

  /* Start transmission */
  radio->TASKS_TXEN = 1;
}

#endif /* HAL_USE_RF */

/** @} */
