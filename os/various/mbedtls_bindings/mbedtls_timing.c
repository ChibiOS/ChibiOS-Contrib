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
 * mbedtls_timing_set_delay, mbedtls_timing_get_delay and
 * mbedtls_timing_get_timer implementations based on mbedtls/library/timing.c
 */

#include <string.h>

#include "mbedtls/timing.h"

#include "ch.h"


unsigned long mbedtls_timing_hardclock(void) {

  return (unsigned long)chTimeI2MS(chVTGetSystemTime());
}

/*
 * Set delays to watch
 */
void mbedtls_timing_set_delay(void *data, uint32_t int_ms, uint32_t fin_ms) {
  mbedtls_timing_delay_context *ctx = (mbedtls_timing_delay_context *)data;

  ctx->MBEDTLS_PRIVATE(int_ms) = int_ms;
  ctx->MBEDTLS_PRIVATE(fin_ms) = fin_ms;

  if (fin_ms != 0)
    (void)mbedtls_timing_get_timer(&ctx->MBEDTLS_PRIVATE(timer), 1);
}

/*
 * Get number of delays expired
 */
int mbedtls_timing_get_delay(void *data) {
  mbedtls_timing_delay_context *ctx = (mbedtls_timing_delay_context *)data;
  unsigned long elapsed_ms;

  if (ctx->MBEDTLS_PRIVATE(fin_ms) == 0)
    return -1;

  elapsed_ms = mbedtls_timing_get_timer(&ctx->MBEDTLS_PRIVATE(timer), 0);

  if (elapsed_ms >= ctx->MBEDTLS_PRIVATE(fin_ms))
    return 2;

  if (elapsed_ms >= ctx->MBEDTLS_PRIVATE(int_ms))
    return 1;

  return 0;
}

unsigned long mbedtls_timing_get_timer(struct mbedtls_timing_hr_time *val,
                                       int reset) {

#ifndef MIN
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#endif

  systime_t start = 0;

  memcpy(&start, val, MIN(sizeof(start), sizeof(*val)));

  const systime_t end = chVTGetSystemTime();

  if (reset) {
    memset(val, 0, sizeof(*val));
    memcpy(val, &end, MIN(sizeof(*val), sizeof(end)));
    return 0;
  }

  return (unsigned long)chTimeI2MS(chTimeDiffX(start, end));
}
