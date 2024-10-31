#include <xmlmbus_buffer.h>

static inline int _xmlmbus_buffer_write_u8(struct xmlmbus_buffer *buffer, uint8_t src) {

  if (buffer->length >= sizeof(buffer->data))
    return (-1);
  buffer->data[buffer->length++] = src;
  return 0;
}

int xmlmbus_buffer_write_u8(struct xmlmbus_buffer *buffer, uint8_t src) {

  return (_xmlmbus_buffer_write_u8(buffer, src));
}

int xmlmbus_buffer_write_u16(struct xmlmbus_buffer *buffer, uint16_t src) {

  int rc = 0;
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src));
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src >> 8));
  return rc;
}

int xmlmbus_buffer_write_u24(struct xmlmbus_buffer *buffer, uint32_t src) {

  int rc = 0;
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src));
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src >> 8));
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src >> 16));
  return rc;
}

int xmlmbus_buffer_write_u32(struct xmlmbus_buffer *buffer, uint32_t src) {

  int rc = 0;
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src));
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src >> 8));
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src >> 16));
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src >> 24));
  return rc;
}

int xmlmbus_buffer_write_u64(struct xmlmbus_buffer *buffer, uint64_t src) {

  int rc = 0;
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src));
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src >> 8));
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src >> 16));
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src >> 24));
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src >> 32));
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src >> 40));
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src >> 48));
  if (rc == 0)
    rc = _xmlmbus_buffer_write_u8(buffer, (uint8_t)(src >> 56));
  return rc;
}

int xmlmbus_buffer_write_blob(struct xmlmbus_buffer *buffer, const void *_src, size_t src_size) {

  int rc = 0;
  const uint8_t *src = _src;

  while (rc == 0 && src_size--)
    rc = _xmlmbus_buffer_write_u8(buffer, *src++);

  return rc;
}

int xmlmbus_buffer_write_cfield(struct xmlmbus_buffer *packet, uint8_t src) {

  return (_xmlmbus_buffer_write_u8(packet, src));
}

int xmlmbus_buffer_write_afield(struct xmlmbus_buffer *packet, uint8_t src) {

  return (_xmlmbus_buffer_write_u8(packet, src));
}

