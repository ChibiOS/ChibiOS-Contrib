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
 * @file    SK32F0xx/hal_wdg_lld.h
 * @brief   SK32F0xx WDG subsystem low level driver header.
 * @details The SK32F077 embeds both watchdog controllers of the family:
 *          - IWDG (independent watchdog, clocked by the LSI oscillator, no
 *            interrupt, once started it cannot be stopped),
 *          - WWDG (window watchdog, clocked by PCLK1, supports an early
 *            wakeup interrupt).
 *          Both are handled by this driver through two distinct driver
 *          objects: @p WDGD1 for the IWDG and @p WDGD2 for the WWDG.  The
 *          early wakeup interrupt of the WWDG is not used because the
 *          generic WDG driver has no callback mechanism.
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
 * @name    IWDG RLR register definitions
 * @{
 */
#define SK32_IWDG_RL_MASK                   (0x00000FFFU)
#define SK32_IWDG_RL(n)                     ((n) & SK32_IWDG_RL_MASK)
/** @} */

/**
 * @name    IWDG PR register definitions
 * @{
 */
#define SK32_IWDG_PR_MASK                   (7U)
#define SK32_IWDG_PR_DIV4                   0U
#define SK32_IWDG_PR_DIV8                   1U
#define SK32_IWDG_PR_DIV16                  2U
#define SK32_IWDG_PR_DIV32                  3U
#define SK32_IWDG_PR_DIV64                  4U
#define SK32_IWDG_PR_DIV128                 5U
#define SK32_IWDG_PR_DIV256                 6U
/** @} */

/**
 * @name    IWDG WINR register definitions
 * @{
 */
#define SK32_IWDG_WIN_MASK                  (0x00000FFFU)
#define SK32_IWDG_WIN(n)                    ((n) & SK32_IWDG_WIN_MASK)
#define SK32_IWDG_WIN_DISABLED              SK32_IWDG_WIN(0x00000FFFU)
/** @} */

/**
 * @name    WWDG CR register definitions
 * @{
 */
#define SK32_WWDG_T_MASK                    (0x7FU)
#define SK32_WWDG_T_WDGA                    (0x80U)
/** @} */

/**
 * @name    WWDG CFR register definitions
 * @{
 */
#define SK32_WWDG_W_MASK                    (0x7FU)
#define SK32_WWDG_WDGTB_MASK                (0x0180U)
#define SK32_WWDG_WDGTB_DIV1                (0U << 7)
#define SK32_WWDG_WDGTB_DIV2                (1U << 7)
#define SK32_WWDG_WDGTB_DIV4                (2U << 7)
#define SK32_WWDG_WDGTB_DIV8                (3U << 7)
#define SK32_WWDG_EWI                       (0x0200U)
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   IWDG driver enable switch.
 * @details If set to @p TRUE the support for the IWDG is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SK32_WDG_USE_IWDG) || defined(__DOXYGEN__)
#define SK32_WDG_USE_IWDG                   FALSE
#endif

/**
 * @brief   WWDG driver enable switch.
 * @details If set to @p TRUE the support for the WWDG is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SK32_WDG_USE_WWDG) || defined(__DOXYGEN__)
#define SK32_WDG_USE_WWDG                   FALSE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if SK32_WDG_USE_IWDG && !SK32_HAS_IWDG
#error "IWDG not present in the selected device"
#endif

#if SK32_WDG_USE_WWDG && !SK32_HAS_WWDG
#error "WWDG not present in the selected device"
#endif

#if !SK32_WDG_USE_IWDG && !SK32_WDG_USE_WWDG
#error "WDG driver activated but no watchdog peripheral assigned"
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
 * @note    The fields are grouped by watchdog controller, only the group of
 *          the controller the configuration is passed to (see @p WDGD1 and
 *          @p WDGD2) is meaningful.
 */
typedef struct {
  /* IWDG (WDGD1) settings.*/
  /**
   * @brief   Configuration of the IWDG_PR register, one of the
   *          @p SK32_IWDG_PR_DIVx values.
   */
  uint32_t    pr;
  /**
   * @brief   Configuration of the IWDG_RLR register, the reload value of
   *          the down counter (1..4095).
   */
  uint32_t    rlr;
  /**
   * @brief   Configuration of the IWDG_WINR register or
   *          @p SK32_IWDG_WIN_DISABLED to disable the window feature.
   */
  uint32_t    winr;
  /* WWDG (WDGD2) settings.*/
  /**
   * @brief   Configuration of the WWDG_CR T[6:0] counter field, the value
   *          must have bit 6 set (0x40..0x7F).
   */
  uint32_t    t;
  /**
   * @brief   Configuration of the WWDG_CFR W[6:0] window field.
   */
  uint32_t    w;
  /**
   * @brief   Configuration of the WWDG_CFR WDGTB[1:0] prescaler field, one
   *          of the @p SK32_WWDG_WDGTB_DIVx values.
   */
  uint32_t    wdgtb;
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
   * @brief   Pointer to the watchdog registers block.
   */
  union {
    IWDG_TypeDef            *iwdg;
    WWDG_TypeDef            *wwdg;
  } wdg;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if SK32_WDG_USE_IWDG && !defined(__DOXYGEN__)
extern WDGDriver WDGD1;
#endif
#if SK32_WDG_USE_WWDG && !defined(__DOXYGEN__)
extern WDGDriver WDGD2;
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
