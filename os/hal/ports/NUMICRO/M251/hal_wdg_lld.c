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
 * @file    M251/hal_wdg_lld.c
 * @brief   M251/M252 Watchdog Driver low level source.
 *
 * @addtogroup WDG
 * @{
 */

#include "hal.h"

#if (HAL_USE_WDG == TRUE) || defined(__DOXYGEN__)

#define M251_WDG_RELOAD_KEY                0x00005AA5UL
#define M251_WDG_CLKSRC_LIRC               (3UL << CLK_CLKSEL1_WDTSEL_Pos)

/**
 * @brief   WDGD1 driver identifier.
 */
WDGDriver WDGD1;

static void wdg_lld_wait_sync(WDGDriver *wdgp) {
  uint32_t timeout = 0x100000U;

  while (((wdgp->wdt->CTL & WDT_CTL_SYNC_Msk) != 0U) && (timeout > 0U)) {
    timeout--;
  }
  if (timeout == 0U) {
    osalSysHalt("WDT synchronization timeout");
  }
}

/**
 * @brief   Low level watchdog driver initialization.
 *
 * @notapi
 */
void wdg_lld_init(void) {
  WDGD1.state = WDG_STOP;
  WDGD1.config = NULL;
  WDGD1.wdt = WDT;
}

/**
 * @brief   Configures and activates the watchdog.
 *
 * @param[in] wdgp      pointer to a @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_start(WDGDriver *wdgp) {
  uint32_t ctl;

  osalDbgAssert(wdgp->config->timeout <= M251_WDG_TIMEOUT_2POW20,
                "invalid WDT timeout");
  osalDbgAssert(wdgp->config->reset_delay <= M251_WDG_RESET_DELAY_3CLK,
                "invalid WDT reset delay");

  m251_lld_unlock();

  CLK->CLKSEL1 = (CLK->CLKSEL1 & ~CLK_CLKSEL1_WDTSEL_Msk) |
                 M251_WDG_CLKSRC_LIRC;
  CLK->APBCLK0 |= CLK_APBCLK0_WDTCKEN_Msk;

  wdgp->wdt->ALTCTL =
      (uint32_t)wdgp->config->reset_delay << WDT_ALTCTL_RSTDSEL_Pos;

  ctl = ((uint32_t)wdgp->config->timeout << WDT_CTL_TOUTSEL_Pos) |
        WDT_CTL_WDTEN_Msk;

  if (wdgp->config->reset_on_timeout) {
    ctl |= WDT_CTL_RSTEN_Msk;
  }

  if (wdgp->config->run_in_debug) {
    ctl |= WDT_CTL_ICEDEBUG_Msk;
  }

  wdgp->wdt->CTL = ctl;
  wdg_lld_wait_sync(wdgp);

  m251_lld_lock();
}

/**
 * @brief   Deactivates the watchdog.
 *
 * @param[in] wdgp      pointer to a @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_stop(WDGDriver *wdgp) {
  m251_lld_unlock();
  wdgp->wdt->CTL = 0U;
  wdg_lld_wait_sync(wdgp);
  CLK->APBCLK0 &= ~CLK_APBCLK0_WDTCKEN_Msk;
  m251_lld_lock();
}

/**
 * @brief   Reloads the watchdog counter.
 *
 * @param[in] wdgp      pointer to a @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_reset(WDGDriver *wdgp) {
  wdgp->wdt->RSTCNT = M251_WDG_RELOAD_KEY;
}

#endif /* HAL_USE_WDG == TRUE */

/** @} */
