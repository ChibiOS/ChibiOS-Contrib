/*
    Copyright (C) 2022 Hansem Ro <hansemro@outlook.com>

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
 * @file    WDT/hal_wdg_lld.c
 * @brief   WDG Driver subsystem low level driver source.
 *
 * @addtogroup WDG
 * @{
 */

#include "hal.h"

#if (HAL_USE_WDG == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

#if ES32_WDG_USE_WDT || defined(__DOXYGEN__)
    WDGDriver WDGD1;
#endif

/*===========================================================================*/
/* Driver local variables.                                                   */
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
void wdg_lld_init(void)
{
#if ES32_WDG_USE_WDT
    WDGD1.state = WDG_STOP;
    WDGD1.wdg   = WDT;
#endif
}

/**
 * @brief   Configures and activates the WDG peripheral.
 *
 * @param[in] wdgp      pointer to the @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_start(WDGDriver *wdgp)
{
    if (~(wdgp->wdg->CSR & WDT_CSR_WDTLOCK))
    {
        /* Enable WDT clock and disable write protect lock.*/
        CKCU->APBCCR1 |= CKCU_APBCCR1_WDTREN;
        wdgp->wdg->PR = WDT_DISABLE_PROTECT_KEY;

        /* Write configuration.*/
        wdgp->wdg->MR0 = wdgp->config->mr0 & ~WDT_MR0_WDTEN;
        wdgp->wdg->MR1 = wdgp->config->mr1;
#if ES32_WDG_USE_LSE == TRUE
        wdgp->wdg->CSR = WDT_CSR_WDTSRC_LSE;
#else
        wdgp->wdg->CSR = WDT_CSR_WDTSRC_LSI;
#endif
        CKCU->MCUDBGCR &= ~CKCU_MCUDBGCR_DBWDT;
        CKCU->MCUDBGCR |= wdgp->config->dbwdt;

        /* Start.*/
        wdgp->wdg->MR0 |= WDT_MR0_WDTEN;

        /* Enable write protect lock.*/
        wdgp->wdg->PR = 0;
    }
}

/**
 * @brief   Deactivates the WDG peripheral.
 *
 * @param[in] wdgp      pointer to the @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_stop(WDGDriver *wdgp)
{
    if (wdgp->state == WDG_READY)
    {
        /* Disable write protect lock and stop WDT.*/
        wdgp->wdg->PR = WDT_DISABLE_PROTECT_KEY;
        wdgp->wdg->MR0 &= ~WDT_MR0_WDTEN;
        /* Enable write protect lock.*/
        wdgp->wdg->PR = 0;
    }
}

/**
 * @brief   Reloads WDG's counter.
 *
 * @param[in] wdgp      pointer to the @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_reset(WDGDriver *wdgp)
{
    wdgp->wdg->CR = (WDT_RELOAD_KEY | WDT_CR_WDTRS);
}

#endif /* HAL_USE_WDG == TRUE */

/** @} */
