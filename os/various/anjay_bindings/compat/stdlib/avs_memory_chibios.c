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

#define AVS_UTILS_COMPAT_STDLIB_MEMORY_C
#include <avs_commons_init.h>

#if defined(AVS_COMMONS_WITH_AVS_UTILS) \
        && !defined(AVS_COMMONS_UTILS_WITH_STANDARD_ALLOCATOR)

#include <avsystem/commons/avs_memory.h>

#include <string.h>
#include <ch.h>

VISIBILITY_SOURCE_BEGIN

#ifndef AVS_HEAP_MAX_BUFFER_SIZE
#define AVS_HEAP_MAX_BUFFER_SIZE  16*1024u
#endif

static memory_heap_t avs_heap;
static uint8_t avs_heap_buf[AVS_HEAP_MAX_BUFFER_SIZE];

void avs_heap_init(void) {

  chHeapObjectInit(&avs_heap, avs_heap_buf, sizeof(avs_heap_buf));
}

size_t avs_heap_get_free(void) {
  size_t total_free;
  size_t largest;
  size_t fragments = chHeapStatus(&avs_heap, &total_free, &largest);

  (void)fragments;
  (void)largest;

  return total_free;
}

void *avs_malloc(size_t size) {

  return chHeapAlloc(&avs_heap, size);
}

void avs_free(void *ptr) {

  if (ptr == NULL)
    return;

  chHeapFree(ptr);
}

void *avs_calloc(size_t nmemb, size_t size) {

  void *ptr;

  const size_t total = nmemb * size;

  ptr = chHeapAlloc(&avs_heap, total);

  if (!ptr)
    return NULL;

  memset(ptr, 0, total);
  return ptr;
}

void *avs_realloc(void *ptr, size_t size) {

  void *p = avs_malloc(size);

  if (!p)
    return NULL;

  memcpy(p, ptr, size);
  chHeapFree(ptr);
  return p;
}

#endif // defined(AVS_COMMONS_WITH_AVS_UTILS) &&
// !defined(AVS_COMMONS_UTILS_WITH_STANDARD_ALLOCATOR)
