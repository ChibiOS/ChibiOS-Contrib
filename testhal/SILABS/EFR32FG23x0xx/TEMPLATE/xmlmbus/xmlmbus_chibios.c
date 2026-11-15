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

#include <xmlmbus_interface_ioctl.h>
#include <xmlmbus_chibios.h>

static inline int calc_min_wait_time(int timeout_msec, int baudrate) {

  const int msec_per_byte = (1000 * (1 + 8 + 1 + 1) + (baudrate - 1)) / baudrate;

  return ((msec_per_byte < timeout_msec) ? msec_per_byte : timeout_msec);
}

int xmlmbus_interface_open(struct xmlmbus_interface *iface, int flags) {

  return (iface->open(iface, flags));
}

int xmlmbus_interface_close(struct xmlmbus_interface *iface) {

  return (iface->close(iface));
}

int xmlmbus_interface_read(struct xmlmbus_interface *iface, void *buf, unsigned long buflen, int flags, int timeout_msec) {

  uint8_t rx_data[16];
  const int wait_time_msec = calc_min_wait_time(timeout_msec, iface->sio_config->baud);

  xmlmbus_reset_state_machine(&iface->state_machine_data);

  (void)iface->ioctl(iface, XMLMBUS_INTERFACE_IOCTL_RESET_INTERFACE_ERRORS);

  systime_t start = chVTGetSystemTime();
  systime_t end = chTimeAddX(start, TIME_MS2I(timeout_msec));

  do {
    const int read_bytes = iface->read(iface, rx_data, sizeof(rx_data), flags, wait_time_msec);

    for (int i = 0; i < read_bytes; i++) {
      const int rx_complete = xmlmbus_process_state_machine(&iface->state_machine_data, rx_data[i]);
      if (rx_complete != 0) {
        if (iface->state_machine_data.datalen <= buflen) {
          memcpy(buf, iface->state_machine_data.data, iface->state_machine_data.datalen);
          /* Return the length of received packet. */
          return (iface->state_machine_data.datalen);
        }
        else {
          /* Provided buffer was too small. */
          return (-1);
        }
      }
    }
  }
  while (chVTIsSystemTimeWithin(start, end));

  /* No packet received. */
  return 0;
}

int xmlmbus_interface_write(struct xmlmbus_interface *iface, const void *_buf, unsigned long buflen, int flags, int timeout_msec) {

  int total_written = 0;
  const uint8_t *buf = _buf;
  const int wait_time_msec = calc_min_wait_time(timeout_msec, iface->sio_config->baud);

  (void)iface->ioctl(iface, XMLMBUS_INTERFACE_IOCTL_RESET_INTERFACE_ERRORS);

  systime_t start = chVTGetSystemTime();
  systime_t end = chTimeAddX(start, TIME_MS2I(timeout_msec));

  while (buflen > 0) {
    int written_bytes = iface->write(iface, buf, buflen, flags, wait_time_msec);
    if (written_bytes >= 0) {
      total_written += written_bytes;
      buf += written_bytes;
      buflen -= written_bytes;
    }

    if (!chVTIsSystemTimeWithin(start, end))
      break;
  }

  return total_written;
}

int xmlmbus_interface_create_packet(struct xmlmbus_interface *iface, void *dst, unsigned long *_dstlen, const void *src, unsigned long srclen) {

  unsigned long dstlen;

  int rc = iface->ioctl(iface, XMLMBUS_INTERFACE_IOCTL_CREATE_PACKET, dst, &dstlen, src, srclen);

  *_dstlen = dstlen;

  return rc;
}

int xmlmbus_interface_isopen(struct xmlmbus_interface *iface) {

  return (iface->isopen(iface));
}

