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

#ifndef AVS_TEST_TASK_H
#define AVS_TEST_TASK_H

typedef struct {
  const char *dst_ip_addr;
  const char *dst_port_coap_udp;
  const char *dst_coap_udp_ssl;
  const char *dst_coap_tcp;
  const char *dst_coap_tcp_ssl;

  const char *psk_identity;
  const uint8_t *psk_key;
  size_t psk_key_size;
} avs_test_opts_t;

typedef struct {
  uint8_t *buffer;
  size_t length;
} avs_payload_buffer_t;

void avsTestInit(const avs_test_opts_t *avs_test_opts);

#endif /* AVS_TEST_TASK_H */
