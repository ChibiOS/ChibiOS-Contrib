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

#ifndef AVS_COMMONS_EXTERNAL_LOG_LEVELS_H
#define AVS_COMMONS_EXTERNAL_LOG_LEVELS_H

// global log level value
#define AVS_LOG_LEVEL_DEFAULT INFO

#ifdef __GNUC__

// HACK: Replace path to whole file with just the filename to save up on flash
// usage.
// Older versions of STM32CubeIDE (e.g. 1.7.0) provide __FILENAME__ definition.
// It was later replaced by __FILE_NAME__ which appeared in upstream gcc for
// compability with clang.
//
// Both definitions are not standard.

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbuiltin-macro-redefined"

#if defined(__FILE_NAME__)
#undef __FILE__
#define __FILE__ __FILE_NAME__
#elif defined(__FILENAME__)
#undef __FILE__
#define __FILE__ __FILENAME__
#else
#pragma GCC warning \
        "Both __FILE_NAME__ and __FILENAME__ macros are not available. Logs will include full file paths, which may affect the size of the application binary depending on where the project is located."
#endif // defined(__FILE_NAME__)

#pragma GCC diagnostic pop

#endif // __GNUC__

#endif
