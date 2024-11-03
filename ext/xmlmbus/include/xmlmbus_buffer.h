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
