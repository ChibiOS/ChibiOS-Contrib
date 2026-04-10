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

#include <avs_commons_init.h>

#include <avsystem/commons/avs_defs.h>
#include <avsystem/commons/avs_init_once.h>

#include <stdatomic.h>
#include <stdbool.h>

AVS_STATIC_ASSERT(sizeof(avs_init_once_handle_t) >= sizeof(atomic_int),
                  avs_init_once_handle_too_small);
AVS_STATIC_ASSERT(AVS_ALIGNOF(avs_init_once_handle_t)
                  >= AVS_ALIGNOF(atomic_int),
                  avs_init_once_alignment_incompatible);

enum init_state { INIT_NOT_STARTED, INIT_IN_PROGRESS, INIT_DONE };

int avs_init_once(volatile avs_init_once_handle_t *handle,
                  avs_init_once_func_t *func,
                  void *func_arg) {
  volatile atomic_int *state = (volatile atomic_int *) handle;

  int expected;

  do {
    expected = INIT_NOT_STARTED;
    /*
     * `*_weak` version may fail spuriously (return false when
     * *state == expected); this does not matter to us, because we check
     * it in a loop anyway, and according to cppreference it may have
     * better performance than `*_strong` variant on some platforms.
     */
  } while (!atomic_compare_exchange_weak(state, &expected, INIT_IN_PROGRESS)
           && expected != INIT_DONE);

  int result = 0;

  if (expected != INIT_DONE) {
    result = func(func_arg);

    if (result) {
      atomic_store(state, INIT_NOT_STARTED);
    } else {
      atomic_store(state, INIT_DONE);
    }
  }

  return result;
}
