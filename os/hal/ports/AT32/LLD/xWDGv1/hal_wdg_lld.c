/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian

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
 * @file    xWDGv1/hal_wdg_lld.c
 * @brief   WDT Driver subsystem low level driver source.
 *
 * @addtogroup WDG
 * @{
 */

#include "hal.h"

#if (HAL_USE_WDG == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define CMD_CMD_RELOAD                      0xAAAAU
#define CMD_CMD_ENABLE                      0xCCCCU
#define CMD_CMD_WRITE                       0x5555U
#define CMD_CMD_PROTECT                     0x0000U

#if !defined(WDT) && defined(WDT1)
#define WDT                                 WDT1
#endif

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

#if AT32_WDG_USE_WDT || defined(__DOXYGEN__)
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
 * @brief   Low level WDT driver initialization.
 *
 * @notapi
 */
void wdg_lld_init(void) {

#if AT32_WDG_USE_WDT
  WDGD1.state = WDG_STOP;
  WDGD1.wdt   = WDT;
#endif
}

/**
 * @brief   Configures and activates the WDT peripheral.
 *
 * @param[in] wdgp      pointer to the @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_start(WDGDriver *wdgp) {

  /* Enable WDT and unlock for write.*/
  wdgp->wdt->CMD = CMD_CMD_ENABLE;
  wdgp->wdt->CMD = CMD_CMD_WRITE;

  /* Write configuration.*/
  wdgp->wdt->DIV = wdgp->config->div;
  wdgp->wdt->RLD = wdgp->config->rld;

  /* Wait the registers to be updated.*/
  while (wdgp->wdt->STS != 0)
    ;

#if AT32_WDT_IS_WINDOWED
  /* This also triggers a refresh.*/
  wdgp->wdt->WIN = wdgp->config->win;
#else
  wdgp->wdt->CMD = CMD_CMD_RELOAD;
#endif
}

/**
 * @brief   Deactivates the WDT peripheral.
 *
 * @param[in] wdgp      pointer to the @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_stop(WDGDriver *wdgp) {

  osalDbgAssert(wdgp->state == WDG_STOP,
                "WDT cannot be stopped once activated");
}

/**
 * @brief   Reloads WDT's counter.
 *
 * @param[in] wdgp      pointer to the @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_reset(WDGDriver * wdgp) {

  wdgp->wdt->CMD = CMD_CMD_RELOAD;
}

#endif /* HAL_USE_WDG == TRUE */

/** @} */
