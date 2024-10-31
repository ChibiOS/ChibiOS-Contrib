#include <xmlmbus_server.h>

uint8_t* xmlmbus_server_get_response_buffer(struct xmlmbus_server_ctx *ctx) {

  return (ctx->buffer.data);
}

size_t xmlmbus_server_get_response_buffer_size(const struct xmlmbus_server_ctx *ctx) {

  return (sizeof(ctx->buffer.data));
}

size_t xmlmbus_server_get_response_buffer_used(const struct xmlmbus_server_ctx *ctx) {

  return (ctx->buffer.length);
}

static int xmlmbus_process_control_frame(struct xmlmbus_server_ctx *ctx, uint8_t cfield) {

  if (ctx->ctrl_cmd_table == NULL ||
      ctx->ctrl_cmd_table_size == 0) {

    return XMLMBUS_SERVER_UNIMPLEMENTED_SHORT_FRAME_HANDLER;
  }


  int rc = XMLMBUS_SERVER_UNIMPLEMENTED_SHORT_FRAME_HANDLER;

  for (size_t i = 0; i < ctx->ctrl_cmd_table_size; i++) {
    const struct ctrl_cmd *cmd = &ctx->ctrl_cmd_table[i];

    if (cfield == cmd->cfield) {
      if (cmd->func != NULL) {
        if (0 == cmd->func(ctx, cmd->func_arg)) {
          rc = XMLMBUS_SERVER_OK;
        }
        else {
          rc = XMLMBUS_SERVER_ERROR_IN_SHORT_FRAME_HANDLER;
        }

        /* Don't process any further here, because the control frame is over. */
        break;
      }
    }
  }

  return rc;
}

static int xmlmbus_process_long_frame(struct xmlmbus_server_ctx *ctx, uint8_t cfield,
                                      const uint8_t *next_ci, const uint8_t * const last_ci) {

  if (ctx->ci_cmd_table == NULL ||
      ctx->ci_cmd_table_size == 0) {

    return XMLMBUS_SERVER_UNIMPLEMENTED_LONG_FRAME_HANDLER;
  }

  int rc = XMLMBUS_SERVER_OK;

  while (rc == XMLMBUS_SERVER_OK && next_ci < last_ci) {
    rc = XMLMBUS_SERVER_UNIMPLEMENTED_LONG_FRAME_HANDLER;

    for (size_t i = 0; i < ctx->ci_cmd_table_size; i++) {
      const struct ci_cmd *cmd = &ctx->ci_cmd_table[i];

      if (cfield == cmd->cfield && *next_ci == cmd->ci) {
        if (cmd->func != NULL) {
          if (0 == cmd->func(ctx, &next_ci, last_ci - next_ci, cmd->func_arg)) {
            rc = XMLMBUS_SERVER_OK;
          }
          else {
            rc = XMLMBUS_SERVER_ERROR_IN_LONG_FRAME_HANDLER;
          }

          break;
        }
      }
    }
  }

  return rc;
}

int xmlmbus_server_process_client_request(struct xmlmbus_server_ctx *ctx, const uint8_t *in, size_t inlen) {

  int rc;
  unsigned cfield, address, length;

  if (ctx == NULL || in == NULL || inlen == 0)
    return XMLMBUS_SERVER_OK;

  ctx->buffer.length = 0;

  switch (inlen) {
  case MBUS_FRAME_SIZE_SINGLE_CHARACTER:
    if (ctx->single_character_handler == NULL)
      rc = XMLMBUS_SERVER_UNIMPLEMENTED_SINGLE_CHARACTER_FRAME_HANDLER;
    else
      rc = ctx->single_character_handler(ctx);
    break;

  case MBUS_FRAME_SIZE_SHORT:
    cfield = in[1];
    address = in[2];
    //length = MBUS_FRAME_SIZE_DATA_SHORT;

    if (address != ctx->address)
      return XMLMBUS_SERVER_NOT_FOR_ME;

    rc = xmlmbus_process_control_frame(ctx, cfield);
    break;

  default:
    cfield = in[4];
    address = in[5];
    length = in[1];

    if (address != ctx->address)
      return XMLMBUS_SERVER_NOT_FOR_ME;

    rc = xmlmbus_process_long_frame(ctx, cfield, &in[6], &in[4 + length]);
    break;
  }

  return rc;
}

