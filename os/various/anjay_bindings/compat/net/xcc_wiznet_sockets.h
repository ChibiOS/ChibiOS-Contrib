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

#ifndef XCC_WIZNET_SOCKETS_H
#define XCC_WIZNET_SOCKETS_H

#include <stddef.h>
#include <stdint.h>

#include <avsystem/commons/avs_socket.h>
#include <avsystem/commons/xcc_wiznet_posix_compat.h>

// Forward declarations of avs_net APIs that must be implemented
void _avs_net_cleanup_global_compat_state(void);

avs_error_t _avs_net_create_tcp_socket(avs_net_socket_t **socket,
                                       const void *socket_configuration);

avs_error_t _avs_net_create_udp_socket(avs_net_socket_t **socket,
                                       const void *socket_configuration);

int xcc_net_socket_poll_single(xcc_net_socket_impl_t *socket,
                               int64_t timeout_ms,
                               short events,
                               short *revents);

#endif /* XCC_WIZNET_SOCKETS_H */

