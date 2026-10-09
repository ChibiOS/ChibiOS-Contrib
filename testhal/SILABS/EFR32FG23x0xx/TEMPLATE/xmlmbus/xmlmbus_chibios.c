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

#include <string.h>

#include <xmlmbus_util.h>
#include <xmlmbus_chibios.h>

int xmlmbus_interface_open(struct xmlmbus_interface *iface, int flags) {

  return (iface->open(iface, flags));
}

int xmlmbus_interface_close(struct xmlmbus_interface *iface) {

  return (iface->close(iface));
}

int xmlmbus_interface_read(struct xmlmbus_interface *iface, void *buf, unsigned long buflen, int flags, int timeout_msec) {

  int received_packet_size = 0;
  int read_bytes;
  uint8_t rx_data[512];
  int rx_complete = 0;

  xmlmbus_reset_state_machine(&iface->state_machine_data);

  systime_t start = chVTGetSystemTime();
  systime_t end = chTimeAddX(start, TIME_MS2I(timeout_msec));

  while (0 == rx_complete && xmlmbus_mbus_frame_is_good(&iface->state_machine_data)) {
    read_bytes = iface->read(iface, rx_data, sizeof(rx_data), flags, MIN(timeout_msec, 10));

    for (int i = 0;
         i < read_bytes && 0 == rx_complete && xmlmbus_mbus_frame_is_good(&iface->state_machine_data);
         i++) {
      rx_complete = xmlmbus_process_state_machine(&iface->state_machine_data, rx_data[i]);
      if (rx_complete != 0) {
        if (iface->state_machine_data.datalen <= buflen) {
          received_packet_size = iface->state_machine_data.datalen;
          memcpy(buf, iface->state_machine_data.data, iface->state_machine_data.datalen);
        }

        break;
      }
    }

    if (!chVTIsSystemTimeWithin(start, end))
      break;
  }

  return received_packet_size;
}

int xmlmbus_interface_write(struct xmlmbus_interface *iface, const void *_buf, unsigned long buflen, int flags, int timeout_msec) {

  int total = 0;
  const uint8_t *buf = _buf;

  systime_t start = chVTGetSystemTime();
  systime_t end = chTimeAddX(start, TIME_MS2I(timeout_msec));

  while (buflen > 0) {
    int written_bytes = iface->write(iface, buf, buflen, flags, MIN(timeout_msec, 10));
    if (written_bytes >= 0) {
      total += written_bytes;
      buf += written_bytes;
      buflen -= written_bytes;
    }

    if (!chVTIsSystemTimeWithin(start, end))
      break;
  }

  return total;
}

static int create_mbus_packet(uint8_t *dst, const uint8_t *src, size_t srclen) {

  uint8_t * const begin = dst;
  uint8_t crc = 0;

  if (srclen > MBUS_FRAME_SIZE_DATA_MAX)
    return (-1);

  if (srclen < MBUS_FRAME_SIZE_DATA_SHORT)
    return (-1);

  if (srclen == MBUS_FRAME_SIZE_DATA_SHORT) {
    *dst++ = MBUS_FRAME_SHORT_START;
  }
  else {
    *dst++ = MBUS_FRAME_LONG_START;
    *dst++ = srclen;
    *dst++ = srclen;
    *dst++ = MBUS_FRAME_LONG_START;
  }

  while (srclen--) {
    crc += *src;
    *dst++ = *src++;
  }

  *dst++ = crc;
  *dst++ = MBUS_FRAME_STOP;

  return ((int)(dst - begin));
}

int xmlmbus_interface_create_packet(struct xmlmbus_interface *iface, void *dst, unsigned long *dstlen, const void *src, unsigned long srclen) {

  (void)iface;
  int rc;

  if (srclen > 1) {
    *dstlen = create_mbus_packet(dst, src, srclen);
    rc = 0;
  }
  else if (srclen == 1) {
    ((uint8_t*)dst)[0] = MBUS_FRAME_SINGLE_START;
    *dstlen = MBUS_FRAME_SIZE_SINGLE_CHARACTER;
    rc = 0;
  }
  else {
    rc = -1;
  }

  return rc;
}

