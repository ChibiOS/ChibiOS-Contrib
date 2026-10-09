/*
    Copyright 2024 Xael South

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

#pragma once

#include <stdint.h>

#include <xmlmbus_mbus_common.h>

typedef enum {

  XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_START_1 = 0,
  XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_LENGTH_1,
  XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_LENGTH_2,
  XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_START_2,
  XMLMBUS_MBUS_RX_FRAME_STATE_RX_DATA,
  XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_CRC,
  XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_STOP
} xmlmbus_mbus_rx_frame_state_t;

struct xmlmbus_mbus_frame_state_machine_data {
  int state;
  uint8_t length_1;
  uint8_t length_2;
  uint8_t checksum;
  unsigned bytes_to_receive;
  unsigned datalen;

  union {
    unsigned info;

    struct {

      unsigned length_error: 1;
      unsigned start2_error: 1;
      unsigned checksum_error: 1;
      unsigned stop_error: 1;
      unsigned rx_complete: 1;
    } status;
  };

  uint8_t data[MBUS_FRAME_SIZE_MAX];
};

struct mbus_single_frame {
  uint8_t start;
};

struct mbus_short_frame {
  uint8_t start;
  uint8_t c;
  uint8_t a;
  uint8_t checksum;
  uint8_t stop;
};

struct mbus_control_frame {
  uint8_t start;
  uint8_t length_1;
  uint8_t length_2;
  uint8_t start_2;
  uint8_t c;
  uint8_t a;
  uint8_t ci;
  uint8_t checksum;
  uint8_t stop;
};

struct mbus_long_frame_header {
  uint8_t start;
  uint8_t length_1;
  uint8_t length_2;
  uint8_t start_2;
  uint8_t c;
  uint8_t a;
  uint8_t ci;
};

#ifdef __cplusplus
extern "C"
{
#endif

void xmlmbus_reset_state_machine(struct xmlmbus_mbus_frame_state_machine_data *mach);

int xmlmbus_process_state_machine(struct xmlmbus_mbus_frame_state_machine_data *mach, uint8_t b);

void xmlmbus_mbus_frame_clear_error_mask(struct xmlmbus_mbus_frame_state_machine_data *mach);

int xmlmbus_mbus_frame_is_length_error(const struct xmlmbus_mbus_frame_state_machine_data *mach);

int xmlmbus_mbus_frame_is_start2_error(const struct xmlmbus_mbus_frame_state_machine_data *mach);

int xmlmbus_mbus_frame_is_stop_error(const struct xmlmbus_mbus_frame_state_machine_data *mach);

int xmlmbus_mbus_frame_is_checksum_error(const struct xmlmbus_mbus_frame_state_machine_data *mach);

int xmlmbus_mbus_frame_is_good(const struct xmlmbus_mbus_frame_state_machine_data *mach);

int xmlmbus_mbus_frame_is_rx_complete(const struct xmlmbus_mbus_frame_state_machine_data *mach);

uint8_t xmlmbus_mbus_checksum(const uint8_t *buf, unsigned buflen);

const uint8_t* xmlmbus_mbus_frame_get_data(const struct xmlmbus_mbus_frame_state_machine_data *mach);

unsigned xmlmbus_mbus_frame_get_datalen(const struct xmlmbus_mbus_frame_state_machine_data *mach); 

#ifdef __cplusplus
}
#endif

