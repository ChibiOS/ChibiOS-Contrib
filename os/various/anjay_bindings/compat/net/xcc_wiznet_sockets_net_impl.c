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

/*
 The code below is initially based on
 Anjay-freertos-client-23.09/Application/Src/compat/net/xcc_com_sockets_net_impl.c.
 with following copyright information:

/*
 * Copyright 2020-2023 AVSystem <avsystem@avsystem.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#include <assert.h>
#include <inttypes.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <avsystem/commons/avs_log.h>
#include <avsystem/commons/avs_memory.h>
#include <avsystem/commons/avs_socket.h>
#include <avsystem/commons/avs_socket_v_table.h>
#include <avsystem/commons/avs_time.h>
#include <avsystem/commons/avs_utils.h>
#include <avsystem/commons/xcc_wiznet_posix_compat.h>

#include "ch.h"
#include "hal.h"

#include "xcc_wiznet_sockets.h"
#include "wiznet_chibios.h"

#define REMOTE_HOST_BUF_SIZE sizeof("255.255.255.255")
#define REMOTE_PORT_BUF_SIZE AVS_UINT_STR_BUF_SIZE(uint16_t)

struct xcc_net_socket_impl {
  const avs_net_socket_v_table_t *operations;
  xcc_net_socket_impl_t *self;
  int address_family;
  int forced_mtu;
  int socktype;
  int32_t fd;
  char remote_host_str[REMOTE_HOST_BUF_SIZE];
  char remote_port_str[REMOTE_PORT_BUF_SIZE];
  IP_Address_t remote_host;
  uint16_t remote_port;
  avs_time_duration_t recv_timeout;
  uint64_t bytes_sent;
  uint64_t bytes_received;
};

static struct xcc_net_socket_impl wiznet_sock;

avs_error_t _avs_net_initialize_global_compat_state(void) {

  return AVS_OK;
}

void _avs_net_cleanup_global_compat_state(void) { }

static avs_errno_t wizchip_sockets_err_to_avs_errno(int err) {

  switch (err) {
  case WIZCHIP_SOCKETS_ERR_OK:
    return AVS_NO_ERROR;

  case WIZCHIP_SOCKETS_ERR_DESCRIPTOR:
    return AVS_EIO;

  case WIZCHIP_SOCKETS_ERR_PARAMETER:
    return AVS_EINVAL;

  case WIZCHIP_SOCKETS_ERR_WOULDBLOCK:
    return AVS_EAGAIN;

  case WIZCHIP_SOCKETS_ERR_NOMEMORY:
    return AVS_ENOMEM;

  case WIZCHIP_SOCKETS_ERR_CLOSING:
    return AVS_ENOTCONN;

  case WIZCHIP_SOCKETS_ERR_LOCKED:
    return AVS_EADDRINUSE;

  case WIZCHIP_SOCKETS_ERR_TIMEOUT:
    return AVS_ETIMEDOUT;

  case WIZCHIP_SOCKETS_ERR_INPROGRESS:
    return AVS_EINPROGRESS;

  case WIZCHIP_SOCKETS_ERR_NONAME:
    return AVS_EHOSTUNREACH;

  case WIZCHIP_SOCKETS_ERR_NONETWORK:
    return AVS_EHOSTUNREACH;

  case WIZCHIP_SOCKETS_ERR_UNSUPPORTED:
    return AVS_ENOTSUP;

  case WIZCHIP_SOCKETS_ERR_STATE:
    return AVS_EINVAL;

  default:
    return AVS_UNKNOWN_ERROR;
  }
}

static avs_error_t wizchip_sockets_err_to_avs_error(int err) {

  return avs_errno(wizchip_sockets_err_to_avs_errno(err));
}

static int prepare_stringified_host_port(xcc_net_socket_impl_t *sock,
    IP_Address_t *addr,
    uint16_t port) {

  if (snprintf(sock->remote_host_str, sizeof(sock->remote_host_str), "%u.%u.%u.%u",
               (unsigned int)addr->ip[0], (unsigned int)addr->ip[1],
               (unsigned int)addr->ip[2], (unsigned int)addr->ip[3]) < 0
      || snprintf(sock->remote_port_str, sizeof(sock->remote_port_str),
                  "%" PRIu16, port)
      < 0) {
    return -1;
  }

  return 0;
}

#define GETHOSTBYNAME_RETRIES 20

static avs_error_t
net_connect(avs_net_socket_t *sock_, const char *host, const char *port) {

  xcc_net_socket_impl_t *sock = (xcc_net_socket_impl_t *)sock_;
  dns_query_result_t dns_res;

  assert(sock->fd < 0);

  if (sscanf(port, "%" PRIu16, &sock->remote_port) != 1) {
    return avs_errno(AVS_EINVAL);
  }

  for (int i = GETHOSTBYNAME_RETRIES; i > 0; i--) {
    dns_res = wizchipDNSQuery(&WIZCHIP0, 15, host, &sock->remote_host);

    if (dns_res == DNS_QUERY_SUCCESS)
      break;

    //LOG(WARNING, "Failed to resolve hostname. Result: %d Retries left: %d", (int) res, i);
  }

  if (dns_res != DNS_QUERY_SUCCESS) {
    return avs_errno(AVS_ECONNREFUSED);
  }

  if (prepare_stringified_host_port(sock, &sock->remote_host, sock->remote_port)) {
    return avs_errno(AVS_UNKNOWN_ERROR);
  }

  int res;

  res = wizchipSocket(sock->address_family, sock->socktype, 0);

  if (res < 0) {
    return wizchip_sockets_err_to_avs_error(res);
  }

  sock->fd = res;

  res = wizchipConnect(sock->fd, &sock->remote_host, sock->remote_port);

  if (sock->socktype != WIZCHIP_TYPE_DGRAM && res < 0) {
    return wizchip_sockets_err_to_avs_error(res);
  }

  return AVS_OK;
}

static avs_error_t
net_send(avs_net_socket_t *sock_, const void *buffer, size_t buffer_length) {

  xcc_net_socket_impl_t *sock = (xcc_net_socket_impl_t *)sock_;
  int res;

  if (sock->socktype == WIZCHIP_TYPE_DGRAM) {
    res = wizchipSendTo(sock->fd, buffer, buffer_length, 0, &sock->remote_host, sock->remote_port);
  } else {
    res = wizchipSend(sock->fd, buffer, buffer_length, 0);
  }

  if (res < 0 || res != (int)buffer_length) {
    return avs_errno(AVS_EIO);
  }

  sock->bytes_sent += res;

  return AVS_OK;
}

avs_error_t net_send_to(avs_net_socket_t *sock_, const void *buffer, size_t buffer_length,
                        const char *host, const char *port) {

  xcc_net_socket_impl_t *sock = (xcc_net_socket_impl_t *)sock_;
  IP_Address_t remote_host;
  uint16_t remote_port;
  dns_query_result_t dns_res;

  if (sscanf(port, "%" PRIu16, &remote_port) != 1) {
    return avs_errno(AVS_EINVAL);
  }

  for (int i = GETHOSTBYNAME_RETRIES; i > 0; i--) {
    dns_res = wizchipDNSQuery(&WIZCHIP0, 15, host, &remote_host);

    if (dns_res == DNS_QUERY_SUCCESS)
      break;

    //LOG(WARNING, "Failed to resolve hostname. Result: %d Retries left: %d", (int) res, i);
  }

  if (dns_res != DNS_QUERY_SUCCESS) {
    return avs_errno(AVS_ECONNREFUSED);
  }

  int res;

  res = wizchipSendTo(sock->fd, buffer, buffer_length, 0, &remote_host, remote_port);

  if (res < 0 || res != (int)buffer_length) {
    return avs_errno(AVS_EIO);
  }

  sock->bytes_sent += res;

  return AVS_OK;
}

static int32_t recv_with_timeout(xcc_net_socket_impl_t *sock,
                                 void *buffer,
                                 int32_t buffer_length,
                                 int64_t timeout) {

  uint32_t timeout_opt;
  int32_t res;

  if (timeout == 0) {
    if (sock->socktype == WIZCHIP_TYPE_DGRAM) {
      res = wizchipRecvFrom(sock->fd, buffer, buffer_length, WIZCHIP_FLAG_MSG_DONTWAIT,
                            &sock->remote_host, sock->remote_port);
    } else {
      res = wizchipRecv(sock->fd, buffer, buffer_length, WIZCHIP_FLAG_MSG_DONTWAIT);
    }

    if (res == WIZCHIP_SOCKETS_ERR_GENERAL) {
      // behavior unique to WIZCHIP_MSG_DONTWAIT
      res = AVS_ETIMEDOUT;
    }

    return res;
  }

  if (timeout < 0) {
    timeout_opt = TIME_INFINITE;
  } else {
    timeout_opt = (uint32_t)timeout;

    if (timeout_opt != timeout) {
      // accidentally truncated
      return WIZCHIP_SOCKETS_ERR_GENERAL;
    }
  }

  res = wizchipSetSockopt(sock->fd, WIZCHIP_SOL_SOCKET, WIZCHIP_SO_RCVTIMEO,
                          &timeout_opt, sizeof(timeout_opt));

  if (res) {
    return res;
  }

  if (sock->socktype == WIZCHIP_TYPE_DGRAM) {
    res = wizchipRecvFrom(sock->fd, buffer, buffer_length, WIZCHIP_FLAG_MSG_WAIT,
                          &sock->remote_host, sock->remote_port);
  } else {
    res = wizchipRecv(sock->fd, buffer, buffer_length, WIZCHIP_FLAG_MSG_WAIT);
  }

  return res;
}

static avs_error_t net_receive(avs_net_socket_t *sock_, size_t *out_bytes_received,
                               void *buffer, size_t buffer_length) {

  xcc_net_socket_impl_t *sock = (xcc_net_socket_impl_t *)sock_;

  // assume we don't need support for zero-length datagrams
  if (buffer_length == 0) {
    *out_bytes_received = 0;
    return AVS_OK;
  }

  int64_t timeout_ms;

  if (avs_time_duration_to_scalar(&timeout_ms, AVS_TIME_MS,
                                  sock->recv_timeout)) {
    // treat AVS_TIME_DURATION_INVALID as infinite timeout
    timeout_ms = -1;
  } else if (timeout_ms < 0) {
    timeout_ms = 0;
  }

  int32_t res;

  res = recv_with_timeout(sock, buffer, buffer_length, timeout_ms);

  if (res < 0) {
    return wizchip_sockets_err_to_avs_error(res);
  }

  *out_bytes_received = res;
  sock->bytes_received += res;

  return AVS_OK;
}

static avs_error_t net_receive_from(avs_net_socket_t *sock_, size_t *out_bytes_received,
                                    void *buffer, size_t buffer_length,
                                    char *host, size_t host_size, char *port, size_t port_size) {

  xcc_net_socket_impl_t *sock = (xcc_net_socket_impl_t *)sock_;
  IP_Address_t remote_host;
  uint16_t remote_port;
  dns_query_result_t dns_res;

  (void)host_size;
  (void)port_size;

  // assume we don't need support for zero-length datagrams
  if (buffer_length == 0) {
    *out_bytes_received = 0;
    return AVS_OK;
  }

  if (sscanf(port, "%" PRIu16, &remote_port) != 1) {
    return avs_errno(AVS_EINVAL);
  }

  for (int i = GETHOSTBYNAME_RETRIES; i > 0; i--) {
    dns_res = wizchipDNSQuery(&WIZCHIP0, 15, host, &remote_host);

    if (dns_res == DNS_QUERY_SUCCESS)
      break;

    //LOG(WARNING, "Failed to resolve hostname. Result: %d Retries left: %d", (int) res, i);
  }

  if (dns_res != DNS_QUERY_SUCCESS) {
    return avs_errno(AVS_ECONNREFUSED);
  }

  int res;

  res = wizchipRecvFrom(sock->fd, buffer, buffer_length, 0, &remote_host, remote_port);

  if (res < 0) {
    return wizchip_sockets_err_to_avs_error(res);
  }

  *out_bytes_received = res;
  sock->bytes_received += res;

  return AVS_OK;
}

static avs_error_t net_bind(avs_net_socket_t *sock_, const char *address, const char *port) {

  (void)sock_;
  (void)address;
  (void)port;

  /** TODO: Implement net_bind. */
  return AVS_OK;
}

static avs_error_t net_accept(avs_net_socket_t *server_socket, avs_net_socket_t *new_socket) {

  (void)server_socket;
  (void)new_socket;

  /** TODO: Implement net_accept. */
  return AVS_OK;
}

static avs_error_t net_close(avs_net_socket_t *sock_) {

  xcc_net_socket_impl_t *sock = (xcc_net_socket_impl_t *)sock_;
  avs_error_t err = AVS_OK;

  if (sock->fd >= 0) {
    err = wizchip_sockets_err_to_avs_error(wizchipClose(sock->fd));
    sock->fd = -1;
  }

  return err;
}

static avs_error_t net_shutdown(avs_net_socket_t *sock_) {

  xcc_net_socket_impl_t *sock = (xcc_net_socket_impl_t *)sock_;
  avs_error_t err = AVS_OK;

  if (sock->fd >= 0) {
    err = wizchip_sockets_err_to_avs_error(wizchipShutdown(sock->fd));
  }

  return err;
}

static avs_error_t net_cleanup(avs_net_socket_t **sock_ptr) {

  avs_error_t err = AVS_OK;

  if (sock_ptr && *sock_ptr) {
    err = net_close(*sock_ptr);
    *sock_ptr = NULL;
    memset(&wiznet_sock, 0, sizeof(wiznet_sock));
  }

  return err;
}

static const void *net_system_socket(avs_net_socket_t *sock_) {

  xcc_net_socket_impl_t *sock = (xcc_net_socket_impl_t *)sock_;

  return sock->fd < 0 ? NULL : &sock->self;
}

static avs_error_t net_remote_host(avs_net_socket_t *sock_,
                                   char *out_buffer,
                                   size_t out_buffer_size) {

  xcc_net_socket_impl_t *sock = (xcc_net_socket_impl_t *)sock_;

  if (out_buffer_size < strlen(sock->remote_host_str) + 1) {
    return avs_errno(AVS_UNKNOWN_ERROR);
  }

  strcpy(out_buffer, sock->remote_host_str);

  return AVS_OK;
}

static avs_error_t net_remote_hostname(avs_net_socket_t *sock_,
                                       char *out_buffer, size_t out_buffer_size) {

  xcc_net_socket_impl_t *sock = (xcc_net_socket_impl_t *)sock_;

  if (out_buffer_size < strlen(sock->remote_host_str) + 1) {
    return avs_errno(AVS_UNKNOWN_ERROR);
  }

  strcpy(out_buffer, sock->remote_host_str);

  return AVS_OK;
}

static avs_error_t net_remote_port(avs_net_socket_t *sock_,
                                   char *out_buffer,
                                   size_t out_buffer_size) {

  xcc_net_socket_impl_t *sock = (xcc_net_socket_impl_t *)sock_;

  if (out_buffer_size < strlen(sock->remote_port_str) + 1) {
    return avs_errno(AVS_UNKNOWN_ERROR);
  }

  strcpy(out_buffer, sock->remote_port_str);

  return AVS_OK;
}

static avs_error_t net_get_opt(avs_net_socket_t *sock_,
                               avs_net_socket_opt_key_t option_key,
                               avs_net_socket_opt_value_t *out_option_value) {

  xcc_net_socket_impl_t *sock = (xcc_net_socket_impl_t *)sock_;

  switch (option_key) {
  case AVS_NET_SOCKET_OPT_RECV_TIMEOUT:
    out_option_value->recv_timeout = sock->recv_timeout;
    return AVS_OK;

  case AVS_NET_SOCKET_OPT_STATE:
    out_option_value->state = sock->fd < 0 ? AVS_NET_SOCKET_STATE_CLOSED
                              : AVS_NET_SOCKET_STATE_CONNECTED;
    return AVS_OK;

  case AVS_NET_SOCKET_OPT_MTU:
    out_option_value->mtu = sock->forced_mtu;
    return AVS_OK;

  case AVS_NET_SOCKET_OPT_INNER_MTU:
    // this option only controls send and sendto calls, so use only max TX size
    out_option_value->mtu = WIZCHIP_MAX_SOCKET_TX_DATA_SIZE;
    return AVS_OK;

  case AVS_NET_SOCKET_HAS_BUFFERED_DATA:
    out_option_value->flag = false;
    return AVS_OK;

  case AVS_NET_SOCKET_OPT_BYTES_SENT:
    out_option_value->bytes_sent = sock->bytes_sent;
    return AVS_OK;

  case AVS_NET_SOCKET_OPT_BYTES_RECEIVED:
    out_option_value->bytes_received = sock->bytes_received;
    return AVS_OK;

  default:
    return avs_errno(AVS_ENOTSUP);
  }
}

static avs_error_t net_set_opt(avs_net_socket_t *sock_,
                               avs_net_socket_opt_key_t option_key,
                               avs_net_socket_opt_value_t option_value) {

  xcc_net_socket_impl_t *sock = (xcc_net_socket_impl_t *)sock_;

  switch (option_key) {
  case AVS_NET_SOCKET_OPT_RECV_TIMEOUT:
    sock->recv_timeout = option_value.recv_timeout;
    return AVS_OK;

  case AVS_NET_SOCKET_OPT_MTU:
    sock->forced_mtu = option_value.mtu;
    return AVS_OK;

  default:
    return avs_errno(AVS_ENOTSUP);
  }
}

static const avs_net_socket_v_table_t NET_SOCKET_VTABLE = {
  .connect = net_connect,
  .decorate = NULL,
  .send = net_send,
  .send_to = net_send_to,
  .receive = net_receive,
  .receive_from = net_receive_from,
  .bind = net_bind,
  .accept = net_accept,
  .close = net_close,
  .shutdown = net_shutdown,
  .cleanup = net_cleanup,
  .get_system_socket = net_system_socket,
  .get_interface_name = NULL,
  .get_remote_host = net_remote_host,
  .get_remote_hostname = net_remote_hostname,
  .get_remote_port = net_remote_port,
  .get_local_host = NULL,
  .get_local_port = NULL,
  .get_opt = net_get_opt,
  .set_opt = net_set_opt
};

static avs_error_t
net_create_socket(avs_net_socket_t **socket_ptr,
                  const avs_net_socket_configuration_t *configuration,
                  int32_t socktype) {

  assert(socket_ptr);
  assert(!*socket_ptr);
  (void)configuration;

  xcc_net_socket_impl_t *socket = (xcc_net_socket_impl_t *)memset(&wiznet_sock, 0,
                                  sizeof(wiznet_sock));

  if (!socket) {
    return avs_errno(AVS_ENOMEM);
  }

  socket->operations = &NET_SOCKET_VTABLE;
  socket->self = socket;
  socket->address_family = configuration->address_family;
  socket->forced_mtu = configuration->forced_mtu;
  socket->socktype = socktype;
  socket->fd = -1;
  socket->recv_timeout = avs_time_duration_from_scalar(30, AVS_TIME_S);
  *socket_ptr = (avs_net_socket_t *)socket;
  return AVS_OK;
}

avs_error_t _avs_net_create_udp_socket(avs_net_socket_t **socket_ptr,
                                       const void *configuration) {

  return net_create_socket(
           socket_ptr, (const avs_net_socket_configuration_t *)configuration,
           WIZCHIP_TYPE_DGRAM);
}

avs_error_t _avs_net_create_tcp_socket(avs_net_socket_t **socket_ptr,
                                       const void *configuration) {

  return net_create_socket(
           socket_ptr, (const avs_net_socket_configuration_t *)configuration,
           WIZCHIP_TYPE_STREAM);
}
