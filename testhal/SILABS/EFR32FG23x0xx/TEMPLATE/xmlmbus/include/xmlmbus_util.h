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

#include <stddef.h>
#include <time.h>

#if !defined(MAX)
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#endif

#if !defined(MIN)
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#endif

#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(arr) (sizeof((arr))/sizeof((arr)[0]))
#endif

#ifdef __cplusplus
extern "C" {
#endif

void timerspecsub(const struct timespec *a, const struct timespec *b, struct timespec *result);

long timespecsub_to_msec(const struct timespec *ts);

const char* xmlmbus_get_timestr(char *buf, size_t len);

unsigned short xmlmbus_get_manufacturer_integer(const char *src);

char* xmlmbus_get_manufacturer_string(char dest[4], unsigned short manufacturer);

#ifdef __cplusplus
}
#endif

