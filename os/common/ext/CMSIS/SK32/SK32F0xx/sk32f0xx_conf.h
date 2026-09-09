/*
    ChibiOS - Copyright (C) 2026 QMK

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

/* ChibiOS does not build the 3Think SPL (sk32f0xx_*.c), it programs the
   peripheral registers directly.  sk32f0xx.h includes this file so we
   provide a minimal configuration matching the ChibiOS use model: the SPL
   peripheral headers are deliberately not included here. */

#ifndef __SK32F0XX_CONF_H
#define __SK32F0XX_CONF_H

#ifdef USE_FULL_ASSERT

#define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))

void assert_failed(uint8_t *file, uint32_t line);

#else

#define assert_param(expr) ((void)0)

#endif /* USE_FULL_ASSERT */

#endif /* __SK32F0XX_CONF_H */
