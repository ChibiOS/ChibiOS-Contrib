/*
    ChibiOS - Copyright (C) 2023 Xael South

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

#include "ch.h"
#include "hal.h"
#include "cmsis_os.h"

#include <avsystem/commons/avs_socket.h>
#include <avsystem/coap/coap.h>
#include <avsystem/coap/ctx.h>
#include <avsystem/coap/code.h>
#include <avsystem/coap/option.h>
#include <avsystem/coap/token.h>
#include <avsystem/coap/streaming.h>
#include <avsystem/coap/udp.h>
#include <avsystem/coap/tcp.h>
#include <avsystem/coap/writer.h>

#include <avsystem/commons/avs_crypto_pki.h>
#include <avsystem/commons/avs_crypto_psk.h>

#include <avs_memory_chibios.h>
#include "avs_test_task.h"

#define CUSTOM_CONTENT_TYPE       72

static const char *dst_ip_addr;
static const char *dst_port_coap_udp;
static const char *dst_coap_udp_ssl;
static const char *dst_coap_tcp;
static const char *dst_coap_tcp_ssl;

static const char *psk_identity;
static const uint8_t *psk_key;
static size_t psk_key_size;


#if defined(AVS_COMMONS_WITH_AVS_STREAM) && defined(WITH_AVS_COAP_STREAMING_API)

static int avs_buffer_writer(struct avs_stream_struct *out_stream, void *arg) {
  avs_payload_buffer_t *buf = arg;

  avs_error_t err = avs_stream_write(out_stream, buf->buffer, buf->length);

  if (avs_is_err(err))
    return -1;

  return 0;
}

static void anjay_streaming_test(void) {
  avs_error_t err;

  avs_sched_t *sched = avs_sched_new(NULL, NULL);

  if (!sched) {
    goto err;
  }

  avs_shared_buffer_t *in_buffer = avs_shared_buffer_new(2 * 1024);

  if (!in_buffer) {
    goto err;
  }

  avs_shared_buffer_t *out_buffer = avs_shared_buffer_new(2 * 1024);

  if (!out_buffer) {
    goto err;
  }

  avs_coap_udp_response_cache_t *cache = avs_coap_udp_response_cache_create(2 * 1024);

  if (!cache) {
    goto err;
  }

  avs_crypto_prng_ctx_t *prng = avs_crypto_prng_new(NULL, NULL);

  if (!prng) {
    goto err;
  }

  const avs_coap_udp_tx_params_t tx_params = {
    .ack_timeout = AVS_NET_SOCKET_DEFAULT_RECV_TIMEOUT,
    .ack_random_factor = 1.0,
    .max_retransmit = 2,
    .nstart = 1,
  };
  avs_coap_ctx_t *udp_ctx = avs_coap_udp_ctx_create(sched, &tx_params, in_buffer, out_buffer, cache,
                            prng);

  if (!udp_ctx) {
    goto err;
  }

  const avs_net_socket_configuration_t sock_cfg = {
    .reuse_addr = 0,
    .address_family = AVS_NET_AF_INET4,
    .forced_mtu = 512,
    .preferred_family = AVS_NET_AF_INET4
  };

  avs_net_socket_t *sock = NULL;

  err = avs_net_udp_socket_create(&sock, &sock_cfg);

  if (avs_is_err(err)) {
    goto err;
  }

  err = avs_net_socket_connect(sock, dst_ip_addr, dst_port_coap_udp);

  if (avs_is_err(err)) {
    goto err;
  }

  err = avs_coap_ctx_set_socket(udp_ctx, sock);

  if (avs_is_err(err)) {
    goto err;
  }

  uint8_t __payload[] = { 0x00, 0x01, 0x02, 0x03 };
  avs_payload_buffer_t payload = { .buffer = __payload, .length = sizeof(__payload), };

  avs_coap_request_header_t request = { .code = AVS_COAP_CODE_POST,
                                        .options = avs_coap_options_create_empty(NULL, 0),
                                      };

  err = avs_coap_options_dynamic_init(&request.options);
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_HOST, "localhost");
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_PATH, "res_lvl_1");
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_PATH, "res_lvl_2");
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_PATH, "res_lvl_2a");
  err = avs_coap_options_set_content_format(&request.options, CUSTOM_CONTENT_TYPE);
  //err = avs_coap_options_set_content_format(&request.options, AVS_COAP_FORMAT_CBOR);
  err = avs_coap_options_add_uint(&request.options, AVS_COAP_OPTION_SIZE1, &payload.length,
                                  sizeof(payload.length));

  avs_coap_response_header_t response;
  avs_stream_t *out_response_stream = NULL;

  err = avs_coap_streaming_send_request(udp_ctx, &request, &avs_buffer_writer, &payload, &response,
                                        &out_response_stream);

  if (!avs_is_err(err)) {
    goto err;
  }

  uint8_t buf[128];
  size_t bytes_read;

  if (out_response_stream) {
    for (bool finished = false; !finished;) {
      //avs_coap_streaming_handle_incoming_packet(avs_coap_ctx_t *coap_ctx, avs_coap_streaming_request_handler_t *handle_request, void *handler_arg);
      err = avs_stream_read(out_response_stream, &bytes_read, &finished, buf, sizeof(buf));

      if (!avs_is_err(err)) {
        break;
      }
    }
  }

  err = avs_net_socket_shutdown(sock);

  if (avs_is_err(err)) {
    goto err;
  }

  err = avs_net_socket_close(sock);

  if (avs_is_err(err)) {
    goto err;
  }

err:
  avs_coap_options_cleanup(&request.options);
  avs_net_socket_cleanup(&sock);
  avs_coap_ctx_cleanup(&udp_ctx);
  avs_coap_udp_response_cache_release(&cache);
  avs_free(out_buffer);
  avs_free(in_buffer);
  avs_crypto_prng_free(&prng);
  avs_sched_cleanup(&sched);
}
#endif

static int avs_payload_writer(size_t payload_offset,
                              void *payload_buf,
                              size_t payload_buf_size,
                              size_t *out_payload_chunk_size,
                              void *arg) {
  (void)payload_offset;

  avs_payload_buffer_t *buf = arg;

  size_t payload_bytes = AVS_MIN(buf->length, payload_buf_size);

  memcpy(payload_buf, buf->buffer, payload_bytes);


  *out_payload_chunk_size = payload_bytes;

  return 0;
}

static void avs_payload_reader(avs_coap_ctx_t *ctx,
                               avs_coap_exchange_id_t exchange_id,
                               avs_coap_client_request_state_t result,
                               const avs_coap_client_async_response_t *response,
                               avs_error_t err,
                               void *finished_) {
  (void)ctx;
  (void)exchange_id;
  (void)result;
  (void)response;
  (void)err;

  *(bool *)finished_ = true;
}

static int avs_request_handler(avs_coap_server_ctx_t *ctx, const avs_coap_request_header_t *request,
                               void *arg) {

  (void)ctx;
  (void)request;
  (void)arg;

  return 0;
}

static void anjay_async_test(void) {
  avs_error_t err;

  avs_sched_t *sched = avs_sched_new(NULL, NULL);

  if (!sched) {
    goto err;
  }

  avs_crypto_prng_ctx_t *prng = avs_crypto_prng_new(NULL, NULL);

  if (!prng) {
    goto err;
  }

  avs_shared_buffer_t *in_buffer = avs_shared_buffer_new(2 * 1024);

  if (!in_buffer) {
    goto err;
  }

  avs_shared_buffer_t *out_buffer = avs_shared_buffer_new(2 * 1024);

  if (!out_buffer) {
    goto err;
  }

  avs_coap_udp_response_cache_t *cache = avs_coap_udp_response_cache_create(2 * 1024);

  if (!cache) {
    goto err;
  }

  const avs_coap_udp_tx_params_t tx_params = {
    .ack_timeout = AVS_NET_SOCKET_DEFAULT_RECV_TIMEOUT,
    .ack_random_factor = 1.0,
    .max_retransmit = 2,
    .nstart = 1,
  };

  avs_coap_ctx_t *udp_ctx = avs_coap_udp_ctx_create(sched, &tx_params, in_buffer, out_buffer, cache,
                            prng);

  if (!udp_ctx) {
    goto err;
  }

  const avs_net_socket_configuration_t sock_cfg = {
    .reuse_addr = 0,
    .address_family = AVS_NET_AF_INET4,
    .forced_mtu = 512,
    .preferred_family = AVS_NET_AF_INET4
  };

  avs_net_socket_t *sock = NULL;

  err = avs_net_udp_socket_create(&sock, &sock_cfg);

  if (avs_is_err(err)) {
    goto err;
  }

  err = avs_net_socket_connect(sock, dst_ip_addr, dst_port_coap_udp);

  if (avs_is_err(err)) {
    goto err;
  }

  err = avs_coap_ctx_set_socket(udp_ctx, sock);

  if (avs_is_err(err)) {
    goto err;
  }

  uint8_t __payload[] = { 0x00, 0x01, 0x02, 0x03 };
  avs_payload_buffer_t payload = { .buffer = __payload, .length = sizeof(__payload), };

  avs_coap_request_header_t request = { .code = AVS_COAP_CODE_POST,
                                        .options = avs_coap_options_create_empty(NULL, 0),
                                      };

  err = avs_coap_options_dynamic_init(&request.options);
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_HOST, "localhost");
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_PATH, "res_lvl_1");
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_PATH, "res_lvl_2");
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_PATH, "res_lvl_2a");
  err = avs_coap_options_set_content_format(&request.options, CUSTOM_CONTENT_TYPE);
  //err = avs_coap_options_set_content_format(&request.options, AVS_COAP_FORMAT_CBOR);
  err = avs_coap_options_add_uint(&request.options, AVS_COAP_OPTION_SIZE1, &payload.length,
                                  sizeof(payload.length));

  avs_coap_exchange_id_t id;
  bool finished = false;

  err = avs_coap_client_send_async_request(udp_ctx, &id, &request,
        &avs_payload_writer, &payload, &avs_payload_reader, &finished);

  if (avs_is_err(err)) {
    goto err;
  }

  uint8_t __read_payload[64];
  avs_payload_buffer_t read_payload = { .buffer = __read_payload, .length = sizeof(__read_payload), };

  if (!avs_coap_exchange_id_valid(id)) {
    goto err;
  }

  for (int i = 0; i < 50 && !finished; ++i) {
    avs_sched_run(sched);

    osDelay(100);

    err = avs_coap_async_handle_incoming_packet(udp_ctx, &avs_request_handler, &read_payload);

    if (avs_is_err(err)) {
      goto err;
    }
  }

  err = avs_net_socket_shutdown(sock);

  if (avs_is_err(err)) {
    goto err;
  }

  err = avs_net_socket_close(sock);

  if (avs_is_err(err)) {
    goto err;
  }

err:
  avs_coap_options_cleanup(&request.options);
  avs_net_socket_cleanup(&sock);
  avs_coap_ctx_cleanup(&udp_ctx);
  avs_coap_udp_response_cache_release(&cache);
  avs_free(out_buffer);
  avs_free(in_buffer);
  avs_crypto_prng_free(&prng);
  avs_sched_cleanup(&sched);
}

#if defined(WITH_AVS_COAP_TCP)
static void anjay_async_tcp_test(void) {
  avs_error_t err;

  avs_sched_t *sched = avs_sched_new(NULL, NULL);

  if (!sched) {
    goto err;
  }

  avs_crypto_prng_ctx_t *prng = avs_crypto_prng_new(NULL, NULL);

  if (!prng) {
    goto err;
  }

  avs_shared_buffer_t *in_buffer = avs_shared_buffer_new(2 * 1024);

  if (!in_buffer) {
    goto err;
  }

  avs_shared_buffer_t *out_buffer = avs_shared_buffer_new(2 * 1024);

  if (!out_buffer) {
    goto err;
  }

  avs_time_duration_t request_timeout = { }; // = AVS_NET_SOCKET_DEFAULT_RECV_TIMEOUT;
  avs_coap_ctx_t *tcp_ctx = avs_coap_tcp_ctx_create(sched, in_buffer, out_buffer, 10, request_timeout,
                            prng);

  if (!tcp_ctx) {
    goto err;
  }

  const avs_net_socket_configuration_t sock_cfg = {
    .reuse_addr = 0,
    .address_family = AVS_NET_AF_INET4,
    .forced_mtu = 512,
    .preferred_family = AVS_NET_AF_INET4
  };

  avs_net_socket_t *sock = NULL;

  err = avs_net_tcp_socket_create(&sock, &sock_cfg);

  if (avs_is_err(err)) {
    goto err;
  }

  err = avs_net_socket_connect(sock, dst_ip_addr, dst_coap_tcp);

  if (avs_is_err(err)) {
    goto err;
  }

  err = avs_coap_ctx_set_socket(tcp_ctx, sock);

  if (avs_is_err(err)) {
    goto err;
  }

  uint8_t __payload[] = { 0x00, 0x01, 0x02, 0x03 };
  avs_payload_buffer_t payload = { .buffer = __payload, .length = sizeof(__payload), };

  avs_coap_request_header_t request = { .code = AVS_COAP_CODE_POST,
                                        .options = avs_coap_options_create_empty(NULL, 0),
                                      };

  err = avs_coap_options_dynamic_init(&request.options);
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_HOST, "localhost");
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_PATH, "res_lvl_1");
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_PATH, "res_lvl_2");
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_PATH, "res_lvl_2a");
  err = avs_coap_options_set_content_format(&request.options, CUSTOM_CONTENT_TYPE);
  //err = avs_coap_options_set_content_format(&request.options, AVS_COAP_FORMAT_CBOR);
  err = avs_coap_options_add_uint(&request.options, AVS_COAP_OPTION_SIZE1, &payload.length,
                                  sizeof(payload.length));

  avs_coap_exchange_id_t id;
  bool finished = false;

  err = avs_coap_client_send_async_request(tcp_ctx, &id, &request,
        &avs_payload_writer, &payload, &avs_payload_reader, &finished);

  if (avs_is_err(err)) {
    goto err;
  }

  uint8_t __read_payload[64];
  avs_payload_buffer_t read_payload = { .buffer = __read_payload, .length = sizeof(__read_payload), };

  if (!avs_coap_exchange_id_valid(id)) {
    goto err;
  }

  for (int i = 0; i < 50 && !finished; ++i) {
    avs_sched_run(sched);

    osDelay(100);

    err = avs_coap_async_handle_incoming_packet(tcp_ctx, &avs_request_handler, &read_payload);

    if (avs_is_err(err)) {
      goto err;
    }
  }

  err = avs_net_socket_shutdown(sock);

  if (avs_is_err(err)) {
    goto err;
  }

  err = avs_net_socket_close(sock);

  if (avs_is_err(err)) {
    goto err;
  }

err:
  avs_coap_options_cleanup(&request.options);
  avs_net_socket_cleanup(&sock);
  avs_coap_ctx_cleanup(&tcp_ctx);
  avs_free(out_buffer);
  avs_free(in_buffer);
  avs_crypto_prng_free(&prng);
  avs_sched_cleanup(&sched);
}
#endif

static void ssl_psk_anjay_async_test(void) {
  avs_error_t err;

  avs_sched_t *sched = avs_sched_new(NULL, NULL);

  if (!sched) {
    goto err;
  }

  avs_crypto_prng_ctx_t *prng = avs_crypto_prng_new(NULL, NULL);

  if (!prng) {
    goto err;
  }

  avs_shared_buffer_t *in_buffer = avs_shared_buffer_new(2 * 1024);

  if (!in_buffer) {
    goto err;
  }

  avs_shared_buffer_t *out_buffer = avs_shared_buffer_new(2 * 1024);

  if (!out_buffer) {
    goto err;
  }

  avs_coap_udp_response_cache_t *cache = avs_coap_udp_response_cache_create(2 * 1024);

  if (!cache) {
    goto err;
  }

  const avs_coap_udp_tx_params_t tx_params = {
    .ack_timeout = AVS_NET_SOCKET_DEFAULT_RECV_TIMEOUT,
    .ack_random_factor = 1.0,
    .max_retransmit = 2,
    .nstart = 1,
  };
  avs_coap_ctx_t *udp_ctx = avs_coap_udp_ctx_create(sched, &tx_params, in_buffer, out_buffer, cache,
                            prng);

  if (!udp_ctx) {
    goto err;
  }

  avs_net_ssl_configuration_t config = {
    .version = AVS_NET_SSL_VERSION_DEFAULT,
    .security = avs_net_security_info_from_psk((avs_net_psk_info_t) {
      .key = avs_crypto_psk_key_info_from_buffer(psk_key, psk_key_size),
      .identity = avs_crypto_psk_identity_info_from_buffer(psk_identity, strlen(psk_identity)),
    }),
    .ciphersuites = {
      //.ids = default_ciphersuites,
      //.num_ids = default_ciphersuites_num
    },
    .prng_ctx = prng,

    .backend_configuration.reuse_addr = 0,
    .backend_configuration.address_family = AVS_NET_AF_INET4,
    .backend_configuration.forced_mtu = 512,
    .backend_configuration.preferred_family = AVS_NET_AF_INET4
  };

  avs_net_socket_t *sock = NULL;

  err = avs_net_dtls_socket_create(&sock, &config);

  if (avs_is_err(err)) {
    goto err;
  }

  err = avs_net_socket_connect(sock, dst_ip_addr, dst_coap_udp_ssl);

  if (avs_is_err(err)) {
    goto err;
  }

  err = avs_coap_ctx_set_socket(udp_ctx, sock);

  if (avs_is_err(err)) {
    goto err;
  }

  uint8_t __payload[] = { 0x00, 0x01, 0x02, 0x03 };
  avs_payload_buffer_t payload = { .buffer = __payload, .length = sizeof(__payload), };

  avs_coap_request_header_t request = { .code = AVS_COAP_CODE_POST,
                                        .options = avs_coap_options_create_empty(NULL, 0),
                                      };

  err = avs_coap_options_dynamic_init(&request.options);
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_HOST, "localhost");
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_PATH, "res_lvl_1");
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_PATH, "res_lvl_2");
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_PATH, "res_lvl_2a");
  err = avs_coap_options_set_content_format(&request.options, CUSTOM_CONTENT_TYPE);
  //err = avs_coap_options_set_content_format(&request.options, AVS_COAP_FORMAT_CBOR);
  err = avs_coap_options_add_uint(&request.options, AVS_COAP_OPTION_SIZE1, &payload.length,
                                  sizeof(payload.length));

  avs_coap_exchange_id_t id;
  bool finished = false;

  err = avs_coap_client_send_async_request(udp_ctx, &id, &request,
        &avs_payload_writer, &payload, &avs_payload_reader, &finished);

  if (avs_is_err(err)) {
    goto err;
  }

  uint8_t __read_payload[64];
  avs_payload_buffer_t read_payload = { .buffer = __read_payload, .length = sizeof(__read_payload), };

  if (!avs_coap_exchange_id_valid(id)) {
    goto err;
  }

  for (int i = 0; i < 50 && !finished; ++i) {
    avs_sched_run(sched);

    osDelay(100);

    err = avs_coap_async_handle_incoming_packet(udp_ctx, &avs_request_handler, &read_payload);

    if (avs_is_err(err)) {
      goto err;
    }
  }

  err = avs_net_socket_shutdown(sock);

  if (avs_is_err(err)) {
    goto err;
  }

  err = avs_net_socket_close(sock);

  if (avs_is_err(err)) {
    goto err;
  }

err:
  //avs_coap_options_cleanup(&request.options);
  avs_net_socket_cleanup(&sock);
  avs_coap_ctx_cleanup(&udp_ctx);
  avs_coap_udp_response_cache_release(&cache);
  avs_free(out_buffer);
  avs_free(in_buffer);
  avs_crypto_prng_free(&prng);
  avs_sched_cleanup(&sched);
}

static const char *ca_cert = R"()";
static const char *client_cert = R"()";
static const char *client_key = R"()";

static void ssl_x509_anjay_async_test(void) {
  avs_error_t err;

  avs_sched_t *sched = avs_sched_new(NULL, NULL);

  if (!sched) {
    goto err;
  }

  avs_crypto_prng_ctx_t *prng = avs_crypto_prng_new(NULL, NULL);

  if (!prng) {
    goto err;
  }

  avs_shared_buffer_t *in_buffer = avs_shared_buffer_new(2 * 1024);

  if (!in_buffer) {
    goto err;
  }

  avs_shared_buffer_t *out_buffer = avs_shared_buffer_new(2 * 1024);

  if (!out_buffer) {
    goto err;
  }

  avs_coap_udp_response_cache_t *cache = avs_coap_udp_response_cache_create(2 * 1024);

  if (!cache) {
    goto err;
  }

  const avs_coap_udp_tx_params_t tx_params = {
    .ack_timeout = AVS_NET_SOCKET_DEFAULT_RECV_TIMEOUT,
    .ack_random_factor = 1.0,
    .max_retransmit = 2,
    .nstart = 1,
  };
  avs_coap_ctx_t *udp_ctx = avs_coap_udp_ctx_create(sched, &tx_params, in_buffer, out_buffer, cache,
                            prng);

  if (!udp_ctx) {
    goto err;
  }

  const avs_net_ssl_configuration_t config = {
    .version = AVS_NET_SSL_VERSION_DEFAULT,
    .security = avs_net_security_info_from_certificates((avs_net_certificate_info_t) {
      .server_cert_validation = true,
      .trusted_certs = avs_crypto_certificate_chain_info_from_buffer(ca_cert, strlen(ca_cert)),
      .client_cert = avs_crypto_certificate_chain_info_from_buffer(client_cert, strlen(client_cert)),
      .client_key = avs_crypto_private_key_info_from_buffer(client_key, strlen(client_key), NULL)
    }),
    .ciphersuites = {
      //.ids = default_ciphersuites,
      //.num_ids = default_ciphersuites_num
    },
    .prng_ctx = prng,

    .backend_configuration.reuse_addr = 0,
    .backend_configuration.address_family = AVS_NET_AF_INET4,
    .backend_configuration.forced_mtu = 512,
    .backend_configuration.preferred_family = AVS_NET_AF_INET4
  };

  avs_net_socket_t *sock = NULL;

  err = avs_net_dtls_socket_create(&sock, &config);

  if (avs_is_err(err)) {
    goto err;
  }

  err = avs_net_socket_connect(sock, dst_ip_addr, dst_coap_udp_ssl);

  if (avs_is_err(err)) {
    goto err;
  }

  err = avs_coap_ctx_set_socket(udp_ctx, sock);

  if (avs_is_err(err)) {
    goto err;
  }

  uint8_t __payload[] = { 0x00, 0x01, 0x02, 0x03 };
  avs_payload_buffer_t payload = { .buffer = __payload, .length = sizeof(__payload), };

  avs_coap_request_header_t request = { .code = AVS_COAP_CODE_POST,
                                        .options = avs_coap_options_create_empty(NULL, 0),
                                      };

  err = avs_coap_options_dynamic_init(&request.options);
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_HOST, "localhost");
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_PATH, "res_lvl_1");
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_PATH, "res_lvl_2");
  err = avs_coap_options_add_string(&request.options, AVS_COAP_OPTION_URI_PATH, "res_lvl_2a");
  err = avs_coap_options_set_content_format(&request.options, CUSTOM_CONTENT_TYPE);
  //err = avs_coap_options_set_content_format(&request.options, AVS_COAP_FORMAT_CBOR);
  err = avs_coap_options_add_uint(&request.options, AVS_COAP_OPTION_SIZE1, &payload.length,
                                  sizeof(payload.length));

  avs_coap_exchange_id_t id;
  bool finished = false;

  err = avs_coap_client_send_async_request(udp_ctx, &id, &request,
        &avs_payload_writer, &payload, &avs_payload_reader, &finished);

  if (avs_is_err(err)) {
    goto err;
  }

  uint8_t __read_payload[64];
  avs_payload_buffer_t read_payload = { .buffer = __read_payload, .length = sizeof(__read_payload), };

  if (!avs_coap_exchange_id_valid(id)) {
    goto err;
  }

  for (int i = 0; i < 50 && !finished; ++i) {
    avs_sched_run(sched);

    osDelay(100);

    err = avs_coap_async_handle_incoming_packet(udp_ctx, &avs_request_handler, &read_payload);

    if (avs_is_err(err)) {
      goto err;
    }
  }

  err = avs_net_socket_shutdown(sock);

  if (avs_is_err(err)) {
    goto err;
  }

  err = avs_net_socket_close(sock);

  if (avs_is_err(err)) {
    goto err;
  }

err:
  //avs_coap_options_cleanup(&request.options);
  avs_net_socket_cleanup(&sock);
  avs_coap_ctx_cleanup(&udp_ctx);
  avs_coap_udp_response_cache_release(&cache);
  avs_free(out_buffer);
  avs_free(in_buffer);
  avs_crypto_prng_free(&prng);
  avs_sched_cleanup(&sched);
}

static void avsTestTask(const void *arg) {
  (void)arg;

  avs_heap_init();

  //anjay_async_tcp_test();
  //anjay_streaming_test();
  //anjay_async_test();
  //ssl_psk_anjay_async_test();
  //ssl_x509_anjay_async_test();

  while (true) {
    osDelay(1000);
    ssl_psk_anjay_async_test();
    avs_heap_get_free();

    osDelay(1000);
    anjay_async_test();
    avs_heap_get_free();
  }
}

void avsTestInit(const avs_test_opts_t *avs_test_opts) {
  static osThreadDef(avsTestTask, osPriorityNormal, 4u * 1024u, "avs_test_task");

  dst_ip_addr = avs_test_opts->dst_ip_addr;
  dst_port_coap_udp = avs_test_opts->dst_port_coap_udp;
  dst_coap_udp_ssl = avs_test_opts->dst_coap_udp_ssl;
  dst_coap_tcp = avs_test_opts->dst_coap_tcp;
  dst_coap_tcp_ssl = avs_test_opts->dst_coap_tcp_ssl;

  psk_identity = avs_test_opts->psk_identity;
  psk_key = avs_test_opts->psk_key;
  psk_key_size = avs_test_opts->psk_key_size;

  osThreadCreate(osThread(avsTestTask), NULL);
}
