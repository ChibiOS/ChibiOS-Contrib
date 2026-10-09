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

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#include <xmlmbus_util.h>

inline void timerspecsub(const struct timespec *a, const struct timespec *b, struct timespec *result) {

  result->tv_sec  = a->tv_sec  - b->tv_sec;

  result->tv_nsec = a->tv_nsec - b->tv_nsec;

  if (result->tv_nsec < 0) {
    --result->tv_sec;
    result->tv_nsec += 1000000000L;
  }
}

inline long timespecsub_to_msec(const struct timespec *ts) {

  return ((long)(ts->tv_sec * 1000L + ts->tv_nsec / 1000000L));
}

const char* xmlmbus_get_timestr(char *buf, size_t len) {

  struct timeval timeval;
  struct tm timeinfo;
  time_t seconds;
  long milliseconds;
  size_t n;

  if (buf) {
    if (0 != gettimeofday(&timeval, NULL))
      return NULL;
    seconds = timeval.tv_sec;
    milliseconds = timeval.tv_usec / 1000;
    if (!localtime_r(&seconds, &timeinfo))
      return NULL;

    n = strftime(buf, len, "%Y-%m-%dT%H:%M:%S", &timeinfo);
    if (n <= 0)
      return NULL;
    n = snprintf(buf + n, len - n, ".%03ldZ", milliseconds);
    if (n <= 0)
      return NULL;
  }

  return buf;
}

inline unsigned short xmlmbus_get_manufacturer_integer(const char *src) {

  unsigned short manufacturer;

  if (!src)
    return 0;
  if (strlen(src) != 3)
    return 0;

  manufacturer = (((int)src[0] - 64) << 10) | (((int)src[1] - 64) << 5) | (((int)src[2] - 64));

  return manufacturer;
}

inline char* xmlmbus_get_manufacturer_string(char dest[4], unsigned short manufacturer) {

  dest[0] = 64 + ((manufacturer >> 10) & 0x1f);
  dest[1] = 64 + ((manufacturer >> 5) & 0x1f);
  dest[2] = 64 + ((manufacturer >> 0) & 0x1f);
  dest[3] = '\0';

  return dest;
}

