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
 * @file    xWDGv1/hal_wdg_lld.h
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

/**
 * @name    RLD register definitions
 * @{
 */
#define AT32_WDT_RLD_MASK                   (0x00000FFF << 0)
#define AT32_WDT_RLD(n)                     ((n) << 0)
/** @} */

/**
 * @name    DIV register definitions
 * @{
 */
#define AT32_WDT_DIV_MASK                   (7 << 0)
#define AT32_WDT_DIV_4                      0U
#define AT32_WDT_DIV_8                      1U
#define AT32_WDT_DIV_16                     2U
#define AT32_WDT_DIV_32                     3U
#define AT32_WDT_DIV_64                     4U
#define AT32_WDT_DIV_128                    5U
#define AT32_WDT_DIV_256                    6U
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   WDG driver enable switch.
 * @details If set to @p TRUE the support for WDG is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_WDG_USE_WDT) || defined(__DOXYGEN__)
#define AT32_WDG_USE_WDT                    FALSE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if AT32_WDG_USE_WDT && !AT32_HAS_WDT
#error "WDG not present in the selected device"
#endif

#if !AT32_WDG_USE_WDT
#error "WDG driver activated but no xWDG peripheral assigned"
#endif

#if !defined(AT32_LICK_ENABLED)
#error "AT32_LICK_ENABLED not defined"
#endif

#if (AT32_WDG_USE_WDT == TRUE) && (AT32_LICK_ENABLED == FALSE)
#error "WDG requires LICK clock"
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
   * @brief   Configuration of the WDT_DIV register.
   * @details See the AT32 reference manual for details.
   */
  uint32_t    div;
  /**
   * @brief   Configuration of the WDT_RLD register.
   * @details See the AT32 reference manual for details.
   */
  uint32_t    rld;
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
   * @brief   Pointer to the WDG registers block.
   */
  WDT_TypeDef               *wdg;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if AT32_WDG_USE_WDT && !defined(__DOXYGEN__)
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
