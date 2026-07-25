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
 * @file    M251/hal_wdg_lld.h
 * @brief   M251/M252 Watchdog Driver low level header.
 *
 * @addtogroup WDG
 * @{
 */

#ifndef HAL_WDG_LLD_H
#define HAL_WDG_LLD_H

#if (HAL_USE_WDG == TRUE) || defined(__DOXYGEN__)

#include "m251_registry.h"

#if (M251_HAS_WDT == FALSE)
#error "WDT not present in the selected device"
#endif

/**
 * @name    Watchdog timeout selections
 * @{
 */
/** @brief Watchdog timeout of 2^4 WDT clocks.*/
#define M251_WDG_TIMEOUT_2POW4             0U
/** @brief Watchdog timeout of 2^6 WDT clocks.*/
#define M251_WDG_TIMEOUT_2POW6             1U
/** @brief Watchdog timeout of 2^8 WDT clocks.*/
#define M251_WDG_TIMEOUT_2POW8             2U
/** @brief Watchdog timeout of 2^10 WDT clocks.*/
#define M251_WDG_TIMEOUT_2POW10            3U
/** @brief Watchdog timeout of 2^12 WDT clocks.*/
#define M251_WDG_TIMEOUT_2POW12            4U
/** @brief Watchdog timeout of 2^14 WDT clocks.*/
#define M251_WDG_TIMEOUT_2POW14            5U
/** @brief Watchdog timeout of 2^16 WDT clocks.*/
#define M251_WDG_TIMEOUT_2POW16            6U
/** @brief Watchdog timeout of 2^18 WDT clocks.*/
#define M251_WDG_TIMEOUT_2POW18            7U
/** @brief Watchdog timeout of 2^20 WDT clocks.*/
#define M251_WDG_TIMEOUT_2POW20            8U
/** @}*/

/**
 * @name    Watchdog reset delay selections
 * @{
 */
/** @brief Reset delay of 1026 WDT clocks.*/
#define M251_WDG_RESET_DELAY_1026CLK       0U
/** @brief Reset delay of 130 WDT clocks.*/
#define M251_WDG_RESET_DELAY_130CLK        1U
/** @brief Reset delay of 18 WDT clocks.*/
#define M251_WDG_RESET_DELAY_18CLK         2U
/** @brief Reset delay of 3 WDT clocks.*/
#define M251_WDG_RESET_DELAY_3CLK          3U
/** @}*/

/**
 * @brief   Type of a structure representing a watchdog driver.
 */
typedef struct WDGDriver WDGDriver;

/**
 * @brief   Watchdog driver configuration structure.
 */
typedef struct {
  /** @brief Watchdog timeout selection.*/
  uint8_t timeout;
  /** @brief Reset delay selection.*/
  uint8_t reset_delay;
  /** @brief Enables a system reset when the watchdog expires.*/
  bool    reset_on_timeout;
  /** @brief Keeps the watchdog running while the core is halted by a debugger.*/
  bool    run_in_debug;
} WDGConfig;

/**
 * @brief   Structure representing a watchdog driver.
 */
struct WDGDriver {
  /** @brief Driver state.*/
  wdgstate_t      state;
  /** @brief Current configuration data.*/
  const WDGConfig *config;
  /** @brief Pointer to the associated watchdog registers.*/
  WDT_T           *wdt;
};

extern WDGDriver WDGD1;

#ifdef __cplusplus
extern "C" {
#endif
  void wdg_lld_init(void);
  void wdg_lld_start(WDGDriver *wdgp);
  void wdg_lld_stop(WDGDriver *wdgp);
  void wdg_lld_reset(WDGDriver *wdgp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_WDG == TRUE */

#endif /* HAL_WDG_LLD_H */

/** @}*/
