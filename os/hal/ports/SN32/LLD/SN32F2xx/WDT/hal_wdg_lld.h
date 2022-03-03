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
 * @file    WDT/hal_wdg_lld.h
 * @brief   WDG Driver subsystem low level driver header.
 *
 * @addtogroup WDG
 * @{
 */

#ifndef HAL_WDG_LLD_H
#define HAL_WDG_LLD_H

#if (HAL_USE_WDG == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

//Watchdog register key
#define mskWDT_WDKEY                        (0x5AFA<<16)

//Watchdog interrupt flag
#define mskWDT_WDTINT                       (1<<2)

//Watchdog interrupt enable
#define WDT_WDTIE_DISABLE                   0
#define WDT_WDTIE_ENABLE                    1
#define mskWDT_WDTIE_DISABLE                (WDT_WDTIE_DISABLE<<1)
#define mskWDT_WDTIE_ENABLE                 (WDT_WDTIE_ENABLE<<1)

//Watchdog enable
#define mskWDT_WDTEN_DISABLE                0   
#define mskWDT_WDTEN_ENABLE                 1   

//Watchdog Feed value
#define mskWDT_FV                           0x55AA
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   WDT driver enable switch.
 * @details If set to @p TRUE the support for WDT is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SN32_WDG_USE_WDT) || defined(__DOXYGEN__)
#define SN32_WDG_USE_WDT                  FALSE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !SN32_WDG_USE_WDT
#error "WDG driver activated but no WDT peripheral assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a structure representing an WDG driver.
 */
typedef struct WDGDriver WDGDriver;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /**
   * @brief   Configuration of the WDT preloader.
   * @details See the SN32 reference manual for details.
   */
  uint32_t    pr;
  /**
   * @brief   Configuration of the WDT_TC register.
   * @details See the SN32 reference manual for details.
   */
  uint32_t    tc;
} WDGConfig;

/**
 * @brief   Structure representing an WDG driver.
 */
struct WDGDriver {
  /**
   * @brief   Driver state.
   */
  wdgstate_t                state;
  /**
   * @brief   Current configuration data.
   */
  const WDGConfig           *config;
  /* End of the mandatory fields.*/
  /**
   * @brief   Pointer to the WDT registers block.
   */
  SN_WDT_Type              *wdg;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if SN32_WDG_USE_WDT && !defined(__DOXYGEN__)
extern WDGDriver WDGD1;
#endif

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

/** @} */
