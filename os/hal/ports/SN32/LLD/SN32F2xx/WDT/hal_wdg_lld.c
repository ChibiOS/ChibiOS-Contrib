/*
    ChibiOS - Copyright (C) 2006..2020 Giovanni Di Sirio

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

#if SN32_WDG_USE_WDT || defined(__DOXYGEN__)
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
void wdg_lld_init(void) {

#if SN32_WDG_USE_WDT
  WDGD1.state = WDG_STOP;
  WDGD1.wdg   = SN_WDT;
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
  uint32_t  wRegBuf;
  /* Enable WDT and unlock for write.*/
  sys1EnableWDT();
  wRegBuf = mskWDT_WDTIE_DISABLE;        //WDT as reset mode
  wRegBuf = wRegBuf & (~mskWDT_WDTINT);  //Clear WDT interrupt flag
  wRegBuf = wRegBuf | mskWDT_WDKEY;
  wdgp->wdg->CFG   = wRegBuf;

  /* Write configuration.*/
  sys1SelectWDTPRE(wdgp->config->pr);
  wdgp->wdg->TC  = (wdgp->config->tc | mskWDT_WDKEY);
  wdg_lld_reset(&WDGD1);

  /* Start .*/
  wdgp->wdg->CFG   = (mskWDT_WDKEY | mskWDT_WDTEN_ENABLE);
}

/**
 * @brief   Deactivates the WDG peripheral.
 *
 * @param[in] wdgp      pointer to the @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_stop(WDGDriver *wdgp) {
  if (wdgp->state == WDG_READY) {
  wdgp->wdg->CFG   = (mskWDT_WDKEY | (wdgp->wdg->CFG & ~mskWDT_WDTEN_ENABLE));
  sys1DisableWDT();
  }
}

/**
 * @brief   Reloads WDG's counter.
 *
 * @param[in] wdgp      pointer to the @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_reset(WDGDriver * wdgp) {
  wdgp->wdg->FEED = (mskWDT_WDKEY | mskWDT_FV);
}

#endif /* HAL_USE_WDG == TRUE */

/** @} */
