/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    Copyright (C) 2026 QMK

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
 * @file    SK32F0xx/hal_wdg_lld.c
 * @brief   SK32F0xx WDG subsystem low level driver source.
 *
 * @addtogroup WDG
 * @{
 */

#include "hal.h"

#if (HAL_USE_WDG == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/* IWDG key register values, same convention as the STM32 xWDGv1 LLD.*/
#define SK32_IWDG_KEY_RELOAD                0xAAAAU
#define SK32_IWDG_KEY_ENABLE                0xCCCCU
#define SK32_IWDG_KEY_WRITE                 0x5555U

/*
 * Bounded polling count used while waiting for the LSI oscillator to become
 * ready and for the IWDG registers to be updated, prevents a deadlock if the
 * oscillator is not populated.
 */
#define SK32_IWDG_TIMEOUT                   0x000FFFFFU

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

#if SK32_WDG_USE_IWDG || defined(__DOXYGEN__)
/**
 * @brief   IWDG driver identifier.
 * @note    The IWDG is clocked by the LSI oscillator and has no interrupt.
 */
WDGDriver WDGD1;
#endif

#if SK32_WDG_USE_WWDG || defined(__DOXYGEN__)
/**
 * @brief   WWDG driver identifier.
 * @note    The WWDG is clocked by PCLK1 and can generate an early wakeup
 *          interrupt (not used by this driver).
 */
WDGDriver WDGD2;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level WDG driver initialization.
 *
 * @notapi
 */
void wdg_lld_init(void) {

#if SK32_WDG_USE_IWDG
  WDGD1.state    = WDG_STOP;
  WDGD1.wdg.iwdg = IWDG;
#endif
#if SK32_WDG_USE_WWDG
  WDGD2.state    = WDG_STOP;
  WDGD2.wdg.wwdg = WWDG;
#endif
}

/**
 * @brief   Configures and activates the WDG peripheral.
 *
 * @param[in] wdgp      pointer to the @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_start(WDGDriver *wdgp) {

#if SK32_WDG_USE_IWDG
  if (wdgp == &WDGD1) {
    uint32_t n;

    /* The IWDG is clocked by the LSI oscillator, make sure it is running
       before enabling the watchdog.*/
    rccEnableLSI(true);
    for (n = 0U; ((RCC->CSR & RCC_CSR_LSIRDY) == 0U) &&
                 (n < SK32_IWDG_TIMEOUT); n++) {
    }

    /* Enable the IWDG and unlock the PR/RLR/WINR registers.*/
    wdgp->wdg.iwdg->KR = SK32_IWDG_KEY_ENABLE;
    wdgp->wdg.iwdg->KR = SK32_IWDG_KEY_WRITE;

    /* Write configuration.*/
    wdgp->wdg.iwdg->PR  = wdgp->config->pr & SK32_IWDG_PR_MASK;
    wdgp->wdg.iwdg->RLR = SK32_IWDG_RL(wdgp->config->rlr);

    /* Wait the registers to be updated.*/
    for (n = 0U; (wdgp->wdg.iwdg->SR != 0U) && (n < SK32_IWDG_TIMEOUT); n++) {
    }

    /* Programming the window value also reloads the counter, this replaces
       the final KR reload key of the non windowed controllers.*/
    wdgp->wdg.iwdg->WINR = SK32_IWDG_WIN(wdgp->config->winr);
  }
#endif

#if SK32_WDG_USE_WWDG
  if (wdgp == &WDGD2) {

    /* The WWDG is clocked by PCLK1.*/
    rccEnableWWDG(true);

    /* Window and prescaler configuration, the early wakeup interrupt is not
       used because the generic WDG driver has no callback mechanism.*/
    wdgp->wdg.wwdg->CFR = (wdgp->config->w & SK32_WWDG_W_MASK) |
                          (wdgp->config->wdgtb & SK32_WWDG_WDGTB_MASK);

    /* A possibly pending early wakeup flag is cleared.*/
    wdgp->wdg.wwdg->SR = 0U;

    /* Start the watchdog, loading T also triggers a first refresh.*/
    wdgp->wdg.wwdg->CR = (wdgp->config->t & SK32_WWDG_T_MASK) |
                         SK32_WWDG_T_WDGA;
  }
#endif
}

/**
 * @brief   Deactivates the WDG peripheral.
 * @note    A watchdog cannot be stopped once it has been activated, the
 *          assertion fires if this function is called on a started driver.
 *
 * @param[in] wdgp      pointer to the @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_stop(WDGDriver *wdgp) {

  osalDbgAssert(wdgp->state == WDG_STOP,
                "watchdog cannot be stopped once activated");
}

/**
 * @brief   Reloads WDG's counter.
 *
 * @param[in] wdgp      pointer to the @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_reset(WDGDriver *wdgp) {

#if SK32_WDG_USE_IWDG
  if (wdgp == &WDGD1) {
    wdgp->wdg.iwdg->KR = SK32_IWDG_KEY_RELOAD;
  }
#endif

#if SK32_WDG_USE_WWDG
  if (wdgp == &WDGD2) {
    wdgp->wdg.wwdg->CR = (wdgp->config->t & SK32_WWDG_T_MASK) |
                         SK32_WWDG_T_WDGA;
  }
#endif

  (void)wdgp;
}

#endif /* HAL_USE_WDG == TRUE */

/** @} */
