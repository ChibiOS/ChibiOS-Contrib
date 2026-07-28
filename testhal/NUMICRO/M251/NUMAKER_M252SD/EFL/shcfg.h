/*
    Copyright (C) 2021 Alex Lewontin
    Modifications copyright (C) 2026 Belonit

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

#ifndef SHCFG_H
#define SHCFG_H

#include "hal.h"
#include "hal_mfs.h"
#include "shell.h"

/**
 * @brief   Shell thread working area size.
 */
#define SHELL_WA_SIZE THD_WORKING_AREA_SIZE(768)

extern const ShellConfig shell_cfg;
extern MFSDriver mfsd;
extern mfs_nocache_buffer_t mfsbuf;
extern const MFSConfig mfsd_config;

#endif
