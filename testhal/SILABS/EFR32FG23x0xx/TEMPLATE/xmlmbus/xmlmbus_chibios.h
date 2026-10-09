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

#include "hal.h"
#include <xmlmbus_mbus_frame.h>

struct xmlmbus_interface {
  SIODriver *siop;

  struct xmlmbus_mbus_frame_state_machine_data state_machine_data;

  int (*open)(struct xmlmbus_interface *iface, int flags);

  int (*close)(struct xmlmbus_interface *iface);

  int (*read)(struct xmlmbus_interface *iface, void *buf, unsigned long len, int flags, int timeout_msec);

  int (*write)(struct xmlmbus_interface *iface, const void *buf, unsigned long len, int flags, int timeout_msec);
};

int xmlmbus_interface_open(struct xmlmbus_interface *iface, int flags);

int xmlmbus_interface_close(struct xmlmbus_interface *iface);

int xmlmbus_interface_read(struct xmlmbus_interface *iface, void *buf, unsigned long buflen, int flags, int timeout_msec);

int xmlmbus_interface_write(struct xmlmbus_interface *iface, const void *buf, unsigned long buflen, int flags, int timeout_msec);

int xmlmbus_interface_create_packet(struct xmlmbus_interface *iface, void *dst, unsigned long *_dstlen, const void *src, unsigned long srclen);

