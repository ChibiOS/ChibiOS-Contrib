/*
    Copyright (C) 2026 Belonit

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

/**
 * @file    M251/m251_cmsis.h
 * @brief   ChibiOS wrapper for the Nuvoton M251/M252 CMSIS header.
 *
 * @addtogroup ARMCMx_M251
 * @{
 */

#ifndef M251_CMSIS_H
#define M251_CMSIS_H

#if !defined(__ARMCC_VERSION)
#define M251_CMSIS_UNDEF_ARMCC_VERSION
#define __ARMCC_VERSION 0
#endif

#if defined(TRUE)
#undef TRUE
#endif

#if defined(FALSE)
#undef FALSE
#endif

#include "M251/M251.h"

#if defined(TRUE)
#undef TRUE
#endif
#define TRUE 1

#if defined(FALSE)
#undef FALSE
#endif
#define FALSE 0

#if defined(M251_CMSIS_UNDEF_ARMCC_VERSION)
#undef __ARMCC_VERSION
#undef M251_CMSIS_UNDEF_ARMCC_VERSION
#endif

#endif /* M251_CMSIS_H */

/** @} */
