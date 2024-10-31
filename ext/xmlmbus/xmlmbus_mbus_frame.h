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
  uint8_t crc;
  unsigned bytes_to_receive;
  unsigned datalen;

  union {
    unsigned info;

    struct {

      unsigned length_error: 1;
      unsigned start2_error: 1;
      unsigned crc_error: 1;
      unsigned stop_error: 1;
      unsigned rx_complete: 1;
    } status;
  };

  uint8_t data[MBUS_FRAME_SIZE_MAX];
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

int xmlmbus_mbus_frame_is_crc_error(const struct xmlmbus_mbus_frame_state_machine_data *mach);

int xmlmbus_mbus_frame_is_good(const struct xmlmbus_mbus_frame_state_machine_data *mach);

int xmlmbus_mbus_frame_is_rx_complete(const struct xmlmbus_mbus_frame_state_machine_data *mach);

uint8_t xmlmbus_crc_mbus(const uint8_t *buf, unsigned buflen);

const uint8_t* xmlmbus_mbus_frame_get_data(const struct xmlmbus_mbus_frame_state_machine_data *mach);

unsigned xmlmbus_mbus_frame_get_datalen(const struct xmlmbus_mbus_frame_state_machine_data *mach); 

#ifdef __cplusplus
}
#endif

