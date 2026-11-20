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

#include <time.h>

#if !defined(MSVC_COMPILER)
#if defined(_MSC_VER) || defined(_MSC_FULL_VER)
#define MSVC_COMPILER 1
#else
#define MSVC_COMPILER 0
#define XMLMBUS_ATTRIBUTE_USED    __attribute__((used))
#define XMLMBUS_ATTRIBUTE_PACKED  __attribute__((packed))
#endif
#endif

#if !defined(WINDOWS_BUILD)
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64) || defined(__CYGWIN__)
#define WINDOWS_BUILD 1

#define msleep(msecs) Sleep(msecs)
#else
#define WINDOWS_BUILD 0

#include <unistd.h>

typedef int XMLMBUS_SOCKET;

#define XMLMBUS_INVALID_SOCKET  -1
#define XMLMBUS_SOCKET_ERROR   (-1)
#define XMLMBUS_SOCKET_EINPROGRESS  EINPROGRESS

#define xmlmbus_closesocket(fd)   close(fd)

#define msleep(msecs) usleep(msecs*1000)
#endif
#endif

