#include <xmlmbus_mbus_frame.h>

static uint8_t _xmlmbus_mbus_checksum(const uint8_t *buf, unsigned buflen) {

  uint8_t checksum = 0;

  while (buflen--) {
    checksum += *buf++;
  }

  return checksum;
}

static void _xmlmbus_clear_error_mask(struct xmlmbus_mbus_frame_state_machine_data *mach) {

  mach->info = 0;
}

static void _xmlmbus_reset_state_machine(struct xmlmbus_mbus_frame_state_machine_data *mach) {

  mach->state = XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_START_1;
  mach->length_1 = 0u;
  mach->length_2 = 0u;
  mach->checksum = 0u;

  mach->bytes_to_receive = 0u;
  mach->datalen = 0u;

  _xmlmbus_clear_error_mask(mach);
}

static int _xmlmbus_is_length_error(const struct xmlmbus_mbus_frame_state_machine_data *mach) {

  return (mach->status.length_error);
}

static int _xmlmbus_is_start2_error(const struct xmlmbus_mbus_frame_state_machine_data *mach) {

  return (mach->status.start2_error);
}

static int _xmlmbus_is_checksum_error(const struct xmlmbus_mbus_frame_state_machine_data *mach) {

  return (mach->status.checksum_error);
}

static int _xmlmbus_is_stop_error(const struct xmlmbus_mbus_frame_state_machine_data *mach) {

  return (mach->status.stop_error);
}

void xmlmbus_reset_state_machine(struct xmlmbus_mbus_frame_state_machine_data *mach) {

  _xmlmbus_reset_state_machine(mach);
}

int xmlmbus_process_state_machine(struct xmlmbus_mbus_frame_state_machine_data *mach, uint8_t b) {

  if (mach->status.rx_complete != 0)
    _xmlmbus_reset_state_machine(mach);

  switch (mach->state) {
  case XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_START_1:
    mach->bytes_to_receive = 0u;
    mach->datalen = 0u;
    mach->data[mach->datalen++] = b;

    if (MBUS_FRAME_SINGLE_START == b) {
      mach->bytes_to_receive = 0u;
      mach->status.rx_complete = 1u;
      mach->state = XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_START_1;
    }
    else if (MBUS_FRAME_SHORT_START == b) {
      /* One byte is already received. */
      mach->bytes_to_receive = MBUS_FRAME_SIZE_SHORT - 1u;
      mach->status.rx_complete = 0u;
      mach->state = XMLMBUS_MBUS_RX_FRAME_STATE_RX_DATA;
    }
    else if (MBUS_FRAME_LONG_START == b) {
      /* One byte is already received. */
      mach->bytes_to_receive = MBUS_FRAME_SIZE_MAX - 1u;
      mach->status.rx_complete = 0u;
      mach->state = XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_LENGTH_1;
    }
    break;

  case XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_LENGTH_1:
    mach->bytes_to_receive--;
    mach->data[mach->datalen++] = b;

    mach->length_1 = b;

    mach->state = XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_LENGTH_2;
    break;

  case XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_LENGTH_2:
    mach->bytes_to_receive--;
    mach->data[mach->datalen++] = b;

    mach->length_2 = b;

    if (mach->length_1 == mach->length_2) {
      mach->status.length_error = 0;
      mach->state = XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_START_2;
    }
    else {
      mach->status.length_error = 1;
      mach->state = XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_START_1;
    }
    break;

  case XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_START_2:
    mach->bytes_to_receive--;
    mach->data[mach->datalen++] = b;

    if (MBUS_FRAME_LONG_START == b) {
      /* There are C, A, CI, data, CRC and STOP bytes to receive. */
      mach->bytes_to_receive = mach->length_1 + 2u;
      mach->status.start2_error = 0;
      mach->state = XMLMBUS_MBUS_RX_FRAME_STATE_RX_DATA;
    }
    else {
      mach->status.start2_error = 1;
      mach->state = XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_START_1;
    }
    break;

  case XMLMBUS_MBUS_RX_FRAME_STATE_RX_DATA:
    mach->bytes_to_receive--;
    mach->data[mach->datalen++] = b;

    if (mach->bytes_to_receive == 2u) {
      /* There are CRC and STOP bytes to receive. */
      mach->state = XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_CRC;
    }
    break;

  case XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_CRC:
    mach->bytes_to_receive--;
    mach->data[mach->datalen++] = b;

    /* We will go until the end of the current frame. */
    mach->state = XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_STOP;

    if (MBUS_FRAME_SHORT_START == mach->data[0]) {
      uint8_t checksum = _xmlmbus_mbus_checksum(&mach->data[1], mach->datalen - 1u - 1u);
      mach->status.checksum_error = (checksum == b) ? 0 : 1;
    }
    else if (MBUS_FRAME_LONG_START == mach->data[0]) {
      uint8_t checksum = _xmlmbus_mbus_checksum(&mach->data[4], mach->datalen - 4u - 1u);
      mach->status.checksum_error = (checksum == b) ? 0 : 1;
    }
    else {
      /* Unknown frame? */
      _xmlmbus_reset_state_machine(mach);
    }
    break;

  case XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_STOP:
    mach->bytes_to_receive--;
    mach->data[mach->datalen++] = b;

    /* Frame is definetely complete. */
    mach->status.rx_complete = 1u;

    /* And also stopped? */
    mach->status.stop_error = (MBUS_FRAME_STOP == b) ? 0 : 1;

    if (mach->bytes_to_receive == 0) {
      mach->state = XMLMBUS_MBUS_RX_FRAME_STATE_WAIT_START_1;
    }
    else {
      /* Still bytes to receive? */
      _xmlmbus_reset_state_machine(mach);
    }
    break;
  }

  return (mach->status.rx_complete);
}

void xmlmbus_mbus_frame_clear_error_mask(struct xmlmbus_mbus_frame_state_machine_data *mach) {

  _xmlmbus_clear_error_mask(mach);
}

int xmlmbus_mbus_frame_is_length_error(const struct xmlmbus_mbus_frame_state_machine_data *mach) {

  return (_xmlmbus_is_length_error(mach));
}

int xmlmbus_mbus_frame_is_start2_error(const struct xmlmbus_mbus_frame_state_machine_data *mach) {

  return (_xmlmbus_is_start2_error(mach));
}

int xmlmbus_mbus_frame_is_checksum_error(const struct xmlmbus_mbus_frame_state_machine_data *mach) {

  return (_xmlmbus_is_checksum_error(mach));
}

int xmlmbus_mbus_frame_is_stop_error(const struct xmlmbus_mbus_frame_state_machine_data *mach) {

  return (_xmlmbus_is_stop_error(mach));
}

int xmlmbus_mbus_frame_is_good(const struct xmlmbus_mbus_frame_state_machine_data *mach) {

  unsigned error_mask = 0;

  error_mask |= _xmlmbus_is_length_error(mach) <<  0;
  error_mask |= _xmlmbus_is_start2_error(mach) <<  1;
  error_mask |= _xmlmbus_is_checksum_error(mach) <<  2;
  error_mask |= _xmlmbus_is_stop_error(mach) <<  3;

  return ((error_mask == 0) ? 1 : 0);
}

int xmlmbus_mbus_frame_is_rx_complete(const struct xmlmbus_mbus_frame_state_machine_data *mach) {

  return (mach->status.rx_complete);
}

uint8_t xmlmbus_mbus_checksum(const uint8_t *buf, unsigned buflen) {

  return (_xmlmbus_mbus_checksum(buf, buflen));
}

const uint8_t* xmlmbus_mbus_frame_get_data(const struct xmlmbus_mbus_frame_state_machine_data *mach) {

  return (mach->data);
}

unsigned xmlmbus_mbus_frame_get_datalen(const struct xmlmbus_mbus_frame_state_machine_data *mach) {

  return (mach->datalen);
}

