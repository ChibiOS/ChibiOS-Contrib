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

#include <xmlmbus_server.h>
#include <xmlmbus_mbus_proprietary_structs.h>

uint8_t* xmlmbus_server_get_response_buffer(struct xmlmbus_server_ctx *ctx) {

  return (ctx->buffer.data);
}

uint32_t xmlmbus_server_get_response_buffer_size(const struct xmlmbus_server_ctx *ctx) {

  return (sizeof(ctx->buffer.data));
}

uint32_t xmlmbus_server_get_response_buffer_used(const struct xmlmbus_server_ctx *ctx) {

  return (ctx->buffer.length);
}

static int xmlmbus_server_process_short_frame(struct xmlmbus_server_ctx *ctx, uint8_t cfield) {

  if (ctx->ctrl_cmd_table == NULL || ctx->ctrl_cmd_table_size == 0u)
    return XMLMBUS_SERVER_UNIMPLEMENTED_SHORT_FRAME_HANDLER;

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

static int xmlmbus_server_process_long_frame(struct xmlmbus_server_ctx *ctx, uint8_t cfield,
                                             const uint8_t *in, const size_t inlen) {

  if (ctx->ci_cmd_table == NULL || ctx->ci_cmd_table_size == 0u)
    return XMLMBUS_SERVER_UNIMPLEMENTED_LONG_FRAME_HANDLER;

  int rc = XMLMBUS_SERVER_UNIMPLEMENTED_LONG_FRAME_HANDLER;

  const uint8_t ci = in[0];

  for (size_t i = 0; i < ctx->ci_cmd_table_size; i++) {
    const struct ci_cmd *cmd = &ctx->ci_cmd_table[i];

    if (cfield == cmd->cfield && ci == cmd->ci) {
      if (cmd->func != NULL) {
        if (0 == cmd->func(ctx, cmd->func_arg, in, inlen)) {
          rc = XMLMBUS_SERVER_OK;
        }
        else {
          rc = XMLMBUS_SERVER_ERROR_IN_LONG_FRAME_HANDLER;
        }

        /* Don't process any further here, because the long frame is over. */
        break;
      }
    }
  }

  return rc;
}

int xmlmbus_server_process_client_request(struct xmlmbus_server_ctx *ctx, const uint8_t *in, uint32_t inlen) {

  int rc;
  unsigned cfield, address, length;

  if (ctx == NULL || in == NULL || inlen == 0u)
    return XMLMBUS_SERVER_ERROR;

  ctx->buffer.length = 0;

  switch (inlen) {
  case MBUS_FRAME_SIZE_SINGLE_CHARACTER:
    if (ctx->single_character_handler != NULL)
      rc = ctx->single_character_handler(ctx);
    else
      rc = XMLMBUS_SERVER_UNIMPLEMENTED_SINGLE_CHARACTER_FRAME_HANDLER;
    break;

  case MBUS_FRAME_SIZE_SHORT:
    cfield = in[1];
    address = in[2];
    //length = MBUS_FRAME_SIZE_DATA_SHORT;

    if ((cfield & MBUS_CFIELD_REQUEST) == 0)
      return XMLMBUS_SERVER_ERROR_WRONG_DIRECTION_IN_CFIELD;

    if (address == MBUS_ADDRESS_BROADCAST_ALL_REPLY || address == ctx->address)
      rc = xmlmbus_server_process_short_frame(ctx, cfield);
    else
      rc = XMLMBUS_SERVER_NOT_FOR_ME;
    break;

  default:
    cfield = in[4];
    address = in[5];
    length = in[1];

    if ((cfield & MBUS_CFIELD_REQUEST) == 0)
      return XMLMBUS_SERVER_ERROR_WRONG_DIRECTION_IN_CFIELD;

    if (address == MBUS_ADDRESS_BROADCAST_ALL_REPLY || address == ctx->address)
      rc = xmlmbus_server_process_long_frame(ctx, cfield, &in[6], &in[4 + length] - &in[6]);
    else
      rc = XMLMBUS_SERVER_NOT_FOR_ME;
    break;
  }

  if (rc == XMLMBUS_SERVER_OK) {
    ctx->access_number++;
  }

  return rc;
}

/* Must return XMLMBUS_SERVER_OK if no error. */
int xmlmbus_server_write_response_data(struct xmlmbus_server_ctx *ctx, struct xmlmbus_dib_with_data *data) {

  int rc;

  const uint8_t dif_length = xmlmbus_get_dif_from_size(data->blobsize);

  if (0 != (rc = xmlmbus_buffer_write_u8(&ctx->buffer, dif_length)))
    return XMLMBUS_SERVER_ERROR_NO_MEMORY;

  if (0 != (rc = xmlmbus_buffer_write_u8(&ctx->buffer, VIF_MANUFACTURER_SPECIFIC)))
    return XMLMBUS_SERVER_ERROR_NO_MEMORY;

  data->vife_layer.vif.msb = 1u; /* Bit E is set in the request. */
  if (0 != (rc = xmlmbus_buffer_write_u8(&ctx->buffer, data->vife_layer.value)))
    return XMLMBUS_SERVER_ERROR_NO_MEMORY;

  data->vife_request.vif.msb = 1u; /* Bit E is set in the request. */
  if (0 != (rc = xmlmbus_buffer_write_u8(&ctx->buffer, data->vife_request.value)))
    return XMLMBUS_SERVER_ERROR_NO_MEMORY;

  data->vife_function.vif.msb = 1u; /* Bit E is set in the request. */
  if (0 != (rc = xmlmbus_buffer_write_u8(&ctx->buffer, data->vife_function.value)))
    return XMLMBUS_SERVER_ERROR_NO_MEMORY;

  data->vife_response.vif.msb = 0u; /* Bit E is unset in the request. */
  if (0 != (rc = xmlmbus_buffer_write_u8(&ctx->buffer, data->vife_response.value)))
    return XMLMBUS_SERVER_ERROR_NO_MEMORY;

  if (dif_length == DIF_DATA_LENGTH_IS_LVAR) {
    if (0 != (rc = xmlmbus_buffer_write_u8(&ctx->buffer, data->blobsize)))
      return XMLMBUS_SERVER_ERROR_NO_MEMORY;
  }

  if (data->blobsize > 0) {
    if (0 != (rc = xmlmbus_buffer_write_blob(&ctx->buffer, data->blob, data->blobsize)))
      return XMLMBUS_SERVER_ERROR_NO_MEMORY;
  }

  return XMLMBUS_SERVER_OK;
}

/* Must return XMLMBUS_SERVER_OK if no error. */
int xmlmbus_server_write_fixed_header(struct xmlmbus_server_ctx *ctx) {

  if (0 != xmlmbus_buffer_write_cfield(&ctx->buffer, RSP_UD))
    return XMLMBUS_SERVER_ERROR_NO_MEMORY;

  if (0 != xmlmbus_buffer_write_afield(&ctx->buffer, ctx->address))
    return XMLMBUS_SERVER_ERROR_NO_MEMORY;

  if (0 != xmlmbus_buffer_write_cifield(&ctx->buffer, MBUS_CI_VARIABLE_DATA_RESPOND))
    return XMLMBUS_SERVER_ERROR_NO_MEMORY;

  struct mbus_fixed_data_header header = {
    .ident_no = ctx->ident_no,
    .manufacturer = ctx->manufacturer,
    .version = ctx->version,
    .medium = ctx->medium,

    .access_number = ctx->access_number,
    .status = ctx->status,
    .signature = 0x0000,
  };

  if (0 != xmlmbus_buffer_write_blob(&ctx->buffer, &header, sizeof(header)))
    return XMLMBUS_SERVER_ERROR_NO_MEMORY;

  return XMLMBUS_SERVER_OK;
}

int xmlmbus_server_write_mdh(struct xmlmbus_server_ctx *ctx, uint8_t mdh) {

  if (0 != xmlmbus_buffer_write_u8(&ctx->buffer, mdh))
    return XMLMBUS_SERVER_ERROR_NO_MEMORY;

  return XMLMBUS_SERVER_OK;
}

int xmlmbus_server_check_authcode(struct xmlmbus_server_ctx *ctx, const uint8_t auth_code[8]) {

  int rc = XMLMBUS_SERVER_OK;

  /* Compare byte for byte without using time-optimized memcmp() trying to prevent timing attack. */
  for (size_t i = 0; i < sizeof(ctx->auth_code_layer_1); ++i) {
    if (ctx->auth_code_layer_1[i] != auth_code[i]) {
      rc = XMLMBUS_SERVER_ERROR_WRONG_AUTHCODE;
    }
  }

  return rc;
}

void xmlmbus_server_set_auth_code(struct xmlmbus_server_ctx *ctx, const uint8_t auth_code[8]) {

  memcpy(ctx->auth_code_layer_1, auth_code, sizeof(ctx->auth_code_layer_1));
}

void xmlmbus_server_set_ctrl_cmd_table(struct xmlmbus_server_ctx *ctx, const struct ctrl_cmd *ctrl_cmd_table, uint32_t ctrl_cmd_table_size) {

  ctx->ctrl_cmd_table = ctrl_cmd_table;
  ctx->ctrl_cmd_table_size = ctrl_cmd_table_size;
}

void xmlmbus_server_set_ci_cmd_table(struct xmlmbus_server_ctx *ctx, const struct ci_cmd *ci_cmd_table, uint32_t ci_cmd_table_size) {

  ctx->ci_cmd_table = ci_cmd_table;
  ctx->ci_cmd_table_size = ci_cmd_table_size;
}

void xmlmbus_server_set_appl_cmd_table(struct xmlmbus_server_ctx *ctx, const struct appl_cmd *appl_cmd_table, uint32_t appl_cmd_table_size) {

  ctx->appl_cmd_table = appl_cmd_table;
  ctx->appl_cmd_table_size = appl_cmd_table_size;
}

void xmlmbus_server_set_address(struct xmlmbus_server_ctx *ctx, uint8_t address) {

  ctx->address = address;
}

void xmlmbus_server_set_identification(struct xmlmbus_server_ctx *ctx, uint32_t ident_no, uint16_t manufacturer, uint8_t version, uint8_t medium) {

  ctx->ident_no = ident_no;
  ctx->manufacturer = manufacturer;
  ctx->version = version;
  ctx->medium = medium;
}

void xmlmbus_server_set_single_character_handler(struct xmlmbus_server_ctx *ctx, single_character_handler_func single_character_handler) {

  ctx->single_character_handler = single_character_handler;
}

struct xmlmbus_server_ctx* xmlmbus_server_static_alloc(void) {

  static struct xmlmbus_server_ctx ctx = {
    .dynamically_allocated = false,
  };

  return (&ctx);
}

#if XMLMBUS_SERVER_HAS_MALLOC
#include <xmlmbus_memory_management.h>

struct xmlmbus_server_ctx* xmlmbus_server_alloc(void) {

  struct xmlmbus_server_ctx *ctx = xmlmbus_zalloc(sizeof(struct xmlmbus_server_ctx));
  if (ctx == NULL)
    return NULL;

  ctx->dynamically_allocated = true;

  return ctx;
}

void xmlmbus_server_destroy(struct xmlmbus_server_ctx *ctx) {

  if (ctx == NULL)
    return;

  if (ctx->dynamically_allocated)
    xmlmbus_free(ctx);
}
#endif

static int snd_ud_handle_layer_function(struct xmlmbus_server_ctx *ctx, struct xmlmbus_dib_with_data *data) {

  const uint8_t *in = data->blob;
  size_t inlen = data->blobsize;

  uint8_t out[256];
  uint32_t outlen = sizeof(out);

  data->vife_response.value = VIFE_RESPONSE_TYPE_CMD_UNIMPLEMENTED;
  data->blob = NULL;
  data->blobsize = 0;

  for (size_t i = 0; i < ctx->appl_cmd_table_size; ++i) {

    const struct appl_cmd *cmd = &ctx->appl_cmd_table[i];
    if (cmd->layer == data->vife_layer.value &&
        cmd->request == data->vife_request.value &&
        cmd->function == data->vife_function.value) {
      if (cmd->func != NULL) {

        int rc;

        if (ctx->authorized)
          rc = cmd->func(ctx, cmd->func_arg, in, inlen, out, &outlen);
        else
          rc = XMLMBUS_SERVER_ERROR_WRONG_AUTHCODE;

        if (XMLMBUS_SERVER_OK == rc) {
          if (outlen > 0) {
            data->vife_response.value = VIFE_RESPONSE_TYPE_CMD_EXEC_RESULT;
            data->blob = out;
            data->blobsize = outlen;
          }
          else {
            data->vife_response.value = VIFE_RESPONSE_TYPE_CMD_EXEC_SUCCESS;
          }
        }
        else if (XMLMBUS_SERVER_ERROR_WRONG_AUTHCODE == rc) {
          data->vife_response.value = VIFE_RESPONSE_TYPE_CMD_UNAUTHORIZED;
        }
        else if (XMLMBUS_SERVER_ERROR_WRONG_HANDLER_PARAMETER == rc) {
          data->vife_response.value = VIFE_RESPONSE_TYPE_CMD_HAS_WRONG_PARAMETER;
        }
        else if (XMLMBUS_SERVER_ERROR_BUSY == rc) {
          data->vife_response.value = VIFE_RESPONSE_TYPE_DEVICE_IS_BUSY;
          data->blob = out;
          data->blobsize = outlen;
        }
        else {
          data->vife_response.value = VIFE_RESPONSE_TYPE_CMD_EXEC_ERROR;
          data->blob = NULL;
          data->blobsize = 0;
        }

        break;
      }
    }
  }

  int rc = xmlmbus_server_write_response_data(ctx, data);
  if (rc != XMLMBUS_SERVER_OK)
    return rc;

  return XMLMBUS_SERVER_OK;
}

int xmlmbus_server_snd_ud_handler(struct xmlmbus_server_ctx *ctx, void *arg, const uint8_t *in, uint32_t inlen) {

  (void)arg;
  int rc;

  const uint8_t * const begin = in;

  /* CI field must be MBUS_CI_DATA_SEND. */
  uint8_t ci = *in++;
  if ((ci & MBUS_CI_DATA_SEND) != MBUS_CI_DATA_SEND)
    return XMLMBUS_SERVER_ERROR_WRONG_CI;

  /* There is the authorization layer in front of data. */
  uint8_t dif = *in++;
  if (dif != DIF_BINARY_DATA_LENGTH_IS_8)
    return XMLMBUS_SERVER_ERROR_WRONG_DIF;

  uint8_t vif = *in++;
  if (vif != VIF_MANUFACTURER_SPECIFIC)
    return XMLMBUS_SERVER_ERROR_WRONG_VIF;

  uint8_t vife = *in++;
  if (vife != VIFE_LAYER_AUTHORIZATION)
    return XMLMBUS_SERVER_ERROR_WRONG_VIF;

  /* Finally check the authorization code. */
  const Authcode_t *auth = (const Authcode_t*)in;
  if (XMLMBUS_SERVER_OK == xmlmbus_server_check_authcode(ctx, auth->code))
    ctx->authorized = true;
  else
    ctx->authorized = false;

  in += sizeof(*auth);

  /* Fixed header has always to be send. All following data
     is up to functions implemented by the user. */
  if (XMLMBUS_SERVER_OK != (rc = xmlmbus_server_write_fixed_header(ctx)))
    return rc;

  #if 0
  /* ... and don't forget the Manufacturer Defined Header. */
  if (XMLMBUS_SERVER_OK != (rc = xmlmbus_server_write_mdh(ctx, DIF_MANUFACTURER_SPECIAL_FUNCTION)))
    return rc;
  #endif

  /* DRH consists of DIB and VIB and in our implementation it's always 5 bytes long. */
  const unsigned DRH_length_in_request = 5u;
  while (in + DRH_length_in_request < begin + inlen) {
    dif = *in++;

    vif = *in++;
    if (vif != VIF_MANUFACTURER_SPECIFIC)
      return XMLMBUS_SERVER_ERROR_WRONG_VIF;

    struct xmlmbus_dib_with_data data;
    data.vife_layer.value = *in++ & VIFE_LAYER_MASK;
    data.vife_request.value = *in++ & VIFE_REQUEST_MASK;
    data.vife_function.value = *in++ & VIFE_FUNCTION_MASK;
    data.blobsize = (dif == DIF_DATA_LENGTH_IS_LVAR) ? *in++ : xmlmbus_get_size_from_dif(dif);
    data.blob = in;

    if (data.blobsize == DIF_DATA_LENGTH_IS_INVALID ||
        data.blobsize > (size_t)inlen + (in - begin))
      return XMLMBUS_SERVER_ERROR_WRONG_DATA_LENGTH;

    in += data.blobsize;

    if (XMLMBUS_SERVER_OK != (rc = snd_ud_handle_layer_function(ctx, &data)))
      return rc;
  }

  /* The end of the data stream must have been reached. */
  if (in != begin + inlen)
    return XMLMBUS_SERVER_ERROR_WRONG_DATA_LENGTH;

  return XMLMBUS_SERVER_OK;
}

