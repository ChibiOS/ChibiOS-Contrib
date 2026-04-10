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
#include <stdbool.h>

#include <xmlmbus_mbus_proprietary_structs.h>
#include <xmlmbus_buffer.h>

#ifndef XMLMBUS_SERVER_HAS_MALLOC
#define XMLMBUS_SERVER_HAS_MALLOC  1
#endif

enum xmlmbus_server_error {
  XMLMBUS_SERVER_OK = 0, /* Must have the same value as XMLMBUS_OK. */

  XMLMBUS_SERVER_ERROR = 0x1000, /* Must be "above" all other XMLLMBUS_ERROR_x. */
  XMLMBUS_SERVER_ERROR_NO_MEMORY,
  XMLMBUS_SERVER_ERROR_WRONG_DIRECTION_IN_CFIELD,
  XMLMBUS_SERVER_ERROR_WRONG_CI,
  XMLMBUS_SERVER_ERROR_WRONG_DIF,
  XMLMBUS_SERVER_ERROR_WRONG_VIF,
  XMLMBUS_SERVER_ERROR_WRONG_AUTHCODE,
  XMLMBUS_SERVER_ERROR_WRONG_DATA_LENGTH,
  XMLMBUS_SERVER_ERROR_UNIMPLEMENTED_HANDLER,
  XMLMBUS_SERVER_ERROR_WRONG_HANDLER_PARAMETER,
  XMLMBUS_SERVER_ERROR_BUSY,

  XMLMBUS_SERVER_NOT_FOR_ME = 0x1010,

  XMLMBUS_SERVER_UNIMPLEMENTED_SINGLE_CHARACTER_FRAME_HANDLER = 0x1020,
  XMLMBUS_SERVER_UNIMPLEMENTED_SHORT_FRAME_HANDLER,
  XMLMBUS_SERVER_UNIMPLEMENTED_LONG_FRAME_HANDLER,
  XMLMBUS_SERVER_ERROR_IN_SHORT_FRAME_HANDLER,
  XMLMBUS_SERVER_ERROR_IN_LONG_FRAME_HANDLER,

  XMLMBUS_SERVER_CANT_OPEN_INTERFACE = 0x1030,
};

struct xmlmbus_server_ctx; /* Forward declaration. */

typedef int (*appl_cmd_func)(struct xmlmbus_server_ctx *ctx, void *arg, const uint8_t *in, uint32_t inlen, void *out, uint32_t *outlen);

typedef int (*ci_cmd_func)(struct xmlmbus_server_ctx *ctx, void *arg, const uint8_t *in, uint32_t inlen);

typedef int (*ctrl_cmd_func)(struct xmlmbus_server_ctx *ctx, void *arg);

typedef int (*single_character_handler_func)(struct xmlmbus_server_ctx *ctx);

struct ctrl_cmd {
  uint8_t cfield;
  ctrl_cmd_func func;
  void *func_arg;
};

struct ci_cmd {
  uint8_t cfield;
  uint8_t ci;
  ci_cmd_func func;
  void *func_arg;
};

struct appl_cmd {
  uint8_t layer;
  uint8_t request;
  uint8_t function;
  appl_cmd_func func;
  void *func_arg;
};

struct xmlmbus_server_ctx {
  /* Internal variables, flags, etc. */
  struct xmlmbus_buffer buffer;

  uint8_t access_number;
  uint8_t status;

  bool authorized;

  bool dynamically_allocated;

  /* Settings. */
  uint8_t address;

  uint32_t ident_no;
  uint16_t manufacturer;
  uint8_t version;
  uint8_t medium;

  uint8_t auth_code_layer_1[8];

  const struct ctrl_cmd *ctrl_cmd_table;
  size_t ctrl_cmd_table_size;

  const struct ci_cmd *ci_cmd_table;
  size_t ci_cmd_table_size;

  const struct appl_cmd *appl_cmd_table;
  size_t appl_cmd_table_size;

  single_character_handler_func single_character_handler;
};

#ifdef __cplusplus
extern "C" {
#endif

#if XMLMBUS_SERVER_HAS_MALLOC
struct xmlmbus_server_ctx* xmlmbus_server_alloc(void);

void xmlmbus_server_destroy(struct xmlmbus_server_ctx *ctx);
#endif

struct xmlmbus_server_ctx* xmlmbus_server_static_alloc(void);

uint8_t* xmlmbus_server_get_response_buffer(struct xmlmbus_server_ctx *ctx);

uint32_t xmlmbus_server_get_response_buffer_size(const struct xmlmbus_server_ctx *ctx);

uint32_t xmlmbus_server_get_response_buffer_used(const struct xmlmbus_server_ctx *ctx);

int xmlmbus_server_process_client_request(struct xmlmbus_server_ctx *ctx, const uint8_t *in, uint32_t inlen);

int xmlmbus_server_write_response_data(struct xmlmbus_server_ctx *ctx, struct xmlmbus_dib_with_data *data);

int xmlmbus_server_write_fixed_header(struct xmlmbus_server_ctx *ctx);

int xmlmbus_server_write_mdh(struct xmlmbus_server_ctx *ctx, uint8_t mdh);

int xmlmbus_server_check_authcode(struct xmlmbus_server_ctx *ctx, const uint8_t auth_code[8]);

int xmlmbus_server_snd_ud_handler(struct xmlmbus_server_ctx *ctx, void *arg, const uint8_t *in, uint32_t inlen);

void xmlmbus_server_set_address(struct xmlmbus_server_ctx *ctx, uint8_t address);

void xmlmbus_server_set_identification(struct xmlmbus_server_ctx *ctx, uint32_t ident_no, uint16_t manufacturer, uint8_t version, uint8_t medium);

void xmlmbus_server_set_auth_code(struct xmlmbus_server_ctx *ctx, const uint8_t auth_code[8]);

void xmlmbus_server_set_ctrl_cmd_table(struct xmlmbus_server_ctx *ctx, const struct ctrl_cmd *ctrl_cmd_table, uint32_t ctrl_cmd_table_size);

void xmlmbus_server_set_ci_cmd_table(struct xmlmbus_server_ctx *ctx, const struct ci_cmd *ci_cmd_table, uint32_t ci_cmd_table_size);

void xmlmbus_server_set_appl_cmd_table(struct xmlmbus_server_ctx *ctx, const struct appl_cmd *appl_cmd_table, uint32_t appl_cmd_table_size);

void xmlmbus_server_set_single_character_handler(struct xmlmbus_server_ctx *ctx, single_character_handler_func single_character_handler);

#ifdef __cplusplus
}
#endif

