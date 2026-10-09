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

#include <avsystem/commons/avs_condvar.h>
#include <avsystem/commons/avs_defs.h>
#include <avsystem/commons/avs_memory.h>

#include "avs_cmsis_os_structs.h"

#include <stdatomic.h>

// Code partially inspired by:
// https://github.com/yaahallo/nachos/blob/master/threads/Condition.java
// The Nachos project is the code examples for the Operating Systems course on
// the University of California, see:
// https://eng.ucmerced.edu/crf/engineering/cse-150-operating-systems/
// Copyright (c) 1992-2001 The Regents of the University of California.
// All rights reserved. Used under BSD license
// (https://github.com/yaahallo/nachos/blob/master/README)

int avs_condvar_create(avs_condvar_t **out_condvar) {
  AVS_ASSERT(!*out_condvar,
             "possible attempt to reinitialize a condition variable");

  *out_condvar = (avs_condvar_t *) avs_calloc(1, sizeof(avs_condvar_t));

  if (!*out_condvar) {
    return -1;
  }

  if (_avs_mutex_init(&(*out_condvar)->waiters_mutex)) {
    avs_free(*out_condvar);
    *out_condvar = NULL;
    return -1;
  }

  return 0;
}

int avs_condvar_notify_all(avs_condvar_t *condvar) {
  avs_mutex_lock(&condvar->waiters_mutex);
  condvar_waiter_node_t *waiter = condvar->first_waiter;

  while (waiter) {
    // wake up the waiter
    atomic_flag_clear(&waiter->waiting);

    waiter = waiter->next;
  }

  avs_mutex_unlock(&condvar->waiters_mutex);
  return 0;
}

static void insert_new_waiter(avs_condvar_t *condvar,
                              condvar_waiter_node_t *waiter) {
  avs_mutex_lock(&condvar->waiters_mutex);

  // Initialize the waiting flag to true
  atomic_flag_clear(&waiter->waiting);
  bool value = atomic_flag_test_and_set(&waiter->waiting);
  assert(!value);
  (void) value;

  // Insert waiter as the first element on the list
  waiter->next = condvar->first_waiter;
  condvar->first_waiter = waiter;

  avs_mutex_unlock(&condvar->waiters_mutex);
}

static void remove_waiter(avs_condvar_t *condvar,
                          condvar_waiter_node_t *waiter) {
  avs_mutex_lock(&condvar->waiters_mutex);

  condvar_waiter_node_t **waiter_node_ptr = &condvar->first_waiter;

  while (*waiter_node_ptr && *waiter_node_ptr != waiter) {
    waiter_node_ptr = &(*waiter_node_ptr)->next;
  }

  AVS_ASSERT(*waiter_node_ptr == waiter,
             "waiter node inexplicably disappeared from condition variable");

  if (*waiter_node_ptr == waiter) {
    // detach it
    *waiter_node_ptr = (*waiter_node_ptr)->next;
  }

  avs_mutex_unlock(&condvar->waiters_mutex);
}

int avs_condvar_wait(avs_condvar_t *condvar,
                     avs_mutex_t *mutex,
                     avs_time_monotonic_t deadline) {
  // Precondition: mutex is locked by the current thread
  // although we can't check if it's the current thread that locked it :(

  bool use_deadline = avs_time_monotonic_valid(deadline);
  bool flag_value;
  condvar_waiter_node_t waiter;
  insert_new_waiter(condvar, &waiter);

  avs_mutex_unlock(mutex);

  do {
    flag_value = atomic_flag_test_and_set(&waiter.waiting);
  } while (flag_value
           && (!use_deadline
               || avs_time_monotonic_before(avs_time_monotonic_now(),
                   deadline)));

  avs_mutex_lock(mutex);

  remove_waiter(condvar, &waiter);

  // flag_value == 0 -> it means it was cleared, so we've been woken up
  // flag_value == 1 -> it mean we haven't, so timeout occurred
  return flag_value ? AVS_CONDVAR_TIMEOUT : 0;
}

void avs_condvar_cleanup(avs_condvar_t **condvar) {
  if (!*condvar) {
    return;
  }

  AVS_ASSERT(!(*condvar)->first_waiter,
             "attempted to cleanup a condition variable some thread is "
             "waiting on");

  _avs_mutex_destroy(&(*condvar)->waiters_mutex);
  avs_free(*condvar);
  *condvar = NULL;
}
