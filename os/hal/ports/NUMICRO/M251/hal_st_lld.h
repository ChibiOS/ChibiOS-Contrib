/*
    Copyright (C) 2019 /u/KeepItUnder
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

/**
 * @file    M251/hal_st_lld.h
 * @brief   M251/M252 ST subsystem low level driver header.
 *
 * @addtogroup ST
 * @{
 */

#ifndef HAL_ST_LLD_H
#define HAL_ST_LLD_H

/**
 * @name    M251 system timer configuration options
 * @{
 */

/**
 * @brief   SysTick interrupt priority.
 * @note    The default is 3.
 */
#if !defined(M251_ST_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define M251_ST_IRQ_PRIORITY                3
#endif

/**
 * @brief   SysTick input clock.
 * @note    The default is @p M251_HCLK.
 */
#if !defined(M251_ST_CLK) || defined(__DOXYGEN__)
#define M251_ST_CLK                         M251_HCLK
#endif
/** @} */

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
#error "M251 ST free-running mode is not supported yet"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(M251_ST_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to SysTick"
#endif

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC

#if M251_ST_CLK % OSAL_ST_FREQUENCY != 0
#error "OSAL_ST_FREQUENCY is not an integer divisor of M251_ST_CLK"
#endif

#if ((M251_ST_CLK / OSAL_ST_FREQUENCY) - 1U) > 0xFFFFFFU
#error "the selected ST frequency is not obtainable using SysTick"
#endif

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */

#ifdef __cplusplus
extern "C" {
#endif
  void st_lld_init(void);
#ifdef __cplusplus
}
#endif

#endif /* HAL_ST_LLD_H */

/** @} */
