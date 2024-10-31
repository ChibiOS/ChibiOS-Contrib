#pragma once

#include <stdint.h>
#include <stddef.h>

#include <xmlmbus_buffer.h>

enum xmlmbus_server_error {
  XMLMBUS_SERVER_OK = 0, /* Must have the same value as XMLMBUS_OK. */

  XMLMBUS_SERVER_NOT_FOR_ME = 0x1000, /* Must be "above" all other XMLLMBUS_ERROR_x. */

  XMLMBUS_SERVER_UNIMPLEMENTED_SINGLE_CHARACTER_FRAME_HANDLER = 0x1010,
  XMLMBUS_SERVER_UNIMPLEMENTED_SHORT_FRAME_HANDLER,
  XMLMBUS_SERVER_UNIMPLEMENTED_LONG_FRAME_HANDLER,
  XMLMBUS_SERVER_ERROR_IN_SHORT_FRAME_HANDLER,
  XMLMBUS_SERVER_ERROR_IN_LONG_FRAME_HANDLER,
};

struct xmlmbus_server_ctx; /* Forward declaration. */

typedef int (*ci_cmd_func)(struct xmlmbus_server_ctx *ctx, const uint8_t **in, size_t inlen, void *arg);

typedef int (*ctrl_cmd_func)(struct xmlmbus_server_ctx *ctx, void *arg);

typedef int (*single_character_handler_func)(struct xmlmbus_server_ctx* ctx);

struct ctrl_cmd
{
    uint8_t cfield;
    ctrl_cmd_func func;
    void *func_arg;
};

struct ci_cmd
{
    uint8_t cfield;
    uint8_t ci;
    ci_cmd_func func;
    void *func_arg;
};

struct xmlmbus_server_ctx
{
    struct xmlmbus_buffer buffer;

    uint8_t address;

    const struct ctrl_cmd *ctrl_cmd_table;
    size_t ctrl_cmd_table_size;

    const struct ci_cmd* ci_cmd_table;
    size_t ci_cmd_table_size;

    single_character_handler_func single_character_handler;
};

#ifdef __cplusplus
extern "C" {
#endif

uint8_t* xmlmbus_server_get_response_buffer(struct xmlmbus_server_ctx *ctx);

size_t xmlmbus_server_get_response_buffer_size(const struct xmlmbus_server_ctx *ctx);

size_t xmlmbus_server_get_response_buffer_used(const struct xmlmbus_server_ctx *ctx);

int xmlmbus_server_process_client_request(struct xmlmbus_server_ctx *ctx, const uint8_t *in, size_t inlen);

#ifdef __cplusplus
}
#endif

