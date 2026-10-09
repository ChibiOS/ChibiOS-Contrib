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
#include <stddef.h>

#include <xmlmbus_mbus_common.h>

struct xmlmbus_buffer {

  uint8_t data[MBUS_FRAME_SIZE_MAX];
  size_t length; /** Number of bytes used in data. */
};

#ifdef __cplusplus
extern "C"
{
#endif

int xmlmbus_buffer_write_u8(struct xmlmbus_buffer*, uint8_t);

int xmlmbus_buffer_write_u16(struct xmlmbus_buffer*, uint16_t);

int xmlmbus_buffer_write_u24(struct xmlmbus_buffer *buffer, uint32_t);

int xmlmbus_buffer_write_u32(struct xmlmbus_buffer*, uint32_t);

int xmlmbus_buffer_write_u64(struct xmlmbus_buffer*, uint64_t);

int xmlmbus_buffer_write_blob(struct xmlmbus_buffer*, const void*, size_t);

int xmlmbus_buffer_write_cfield(struct xmlmbus_buffer*, uint8_t);

int xmlmbus_buffer_write_afield(struct xmlmbus_buffer*, uint8_t);

int xmlmbus_buffer_write_cifield(struct xmlmbus_buffer*, uint8_t);

#ifdef __cplusplus
}
#endif
