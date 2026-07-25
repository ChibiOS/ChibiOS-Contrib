/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.

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

#ifndef SHELLCONF_H
#define SHELLCONF_H

#define SHELL_MAX_LINE_LENGTH               64
#define SHELL_MAX_ARGUMENTS                 4
#define SHELL_USE_HISTORY                   FALSE
#define SHELL_USE_COMPLETION                FALSE
#define SHELL_USE_ESC_SEQ                   TRUE
#define SHELL_PROMPT_STR                    "ch> "
#define SHELL_NEWLINE_STR                   "\r\n"

#define SHELL_CMD_EXIT_ENABLED              TRUE
#define SHELL_CMD_INFO_ENABLED              FALSE
#define SHELL_CMD_ECHO_ENABLED              FALSE
#define SHELL_CMD_SYSTIME_ENABLED           FALSE
#define SHELL_CMD_MEM_ENABLED               FALSE
#define SHELL_CMD_THREADS_ENABLED           FALSE
#define SHELL_CMD_TEST_ENABLED              FALSE

#endif
