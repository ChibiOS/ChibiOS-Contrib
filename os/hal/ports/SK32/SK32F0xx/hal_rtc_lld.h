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

/**
 * @file    SK32F0xx/hal_rtc_lld.h
 * @brief   SK32F077 RTC subsystem low level driver stub.
 * @details The SK32F077 does not integrate a real-time clock with the register
 *          set expected by the generic RTC driver.  This header only exists to
 *          satisfy the unconditional include in the generic hal_rtc.h so that
 *          this platform never needs to reference the shared STM32 RTCv2 LLD
 *          header tree.
 *
 * @addtogroup SK32F0xx_RTC
 * @{
 */

#ifndef HAL_RTC_LLD_H
#define HAL_RTC_LLD_H

#if HAL_USE_RTC || defined(__DOXYGEN__)

#endif /* HAL_USE_RTC */

#endif /* HAL_RTC_LLD_H */

/** @} */