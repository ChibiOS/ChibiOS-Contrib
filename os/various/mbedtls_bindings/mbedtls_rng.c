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

#include "ch.h"

#include "mbedtls/platform.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"

void mbedtls_ctr_drbg_free(mbedtls_ctr_drbg_context *ctx) {

  (void)ctx;
}

void mbedtls_ctr_drbg_init(mbedtls_ctr_drbg_context *ctx) {

  (void)ctx;
}

void mbedtls_entropy_init(mbedtls_entropy_context *ctx) {

  (void)ctx;
}

int mbedtls_entropy_func(void *data, unsigned char *output, size_t len) {

  return mbedtls_ctr_drbg_random(data, output, len);
}

int mbedtls_ctr_drbg_seed(mbedtls_ctr_drbg_context *ctx,
                          int (*f_entropy)(void *, unsigned char *, size_t),
                          void *p_entropy,
                          const unsigned char *custom,
                          size_t len) {

  (void)ctx;
  (void)f_entropy;
  (void)p_entropy;
  (void)custom;
  (void)len;

  return 0;
}

#if defined(HAL_USE_TRNG) && (HAL_USE_TRNG==TRUE) && \
    defined(STM32_TRNG_USE_RNG1) && (STM32_TRNG_USE_RNG1==TRUE)
#include "hwrng.inc"
#else
#include "swrng.inc"
#endif
