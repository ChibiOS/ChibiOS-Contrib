/*
    Copyright (C) 2019 /u/KeepItUnder
    Copyright (C) 2020 Alex Lewontin
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
 * @file    M251/hal_lld.h
 * @brief   M251/M252 HAL subsystem low level driver header.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef HAL_LLD_H
#define HAL_LLD_H

#include "m251_cmsis.h"
#include "nvic.h"
#include "m251_registry.h"
#include "m251_isr.h"

/**
 * @brief   Platform identification string.
 */
#if defined(M251_DEVICE_NAME) || defined(__DOXYGEN__)
#define PLATFORM_NAME M251_DEVICE_NAME
#else
#error "M251/M252 device unsupported or not specified"
#endif

#if !defined(M251_MCUCONF)
#error "Using a wrong mcuconf.h file, M251_MCUCONF not defined"
#endif

/**
 * @brief   Disables the M251/M252 clock initialization.
 * @details If set to @p TRUE then the clock tree is assumed to have been
 *          initialized by the bootloader.
 * @note    The default is @p FALSE.
 */
#if !defined(M251_NO_INIT) || defined(__DOXYGEN__)
#define M251_NO_INIT FALSE
#endif

/*===========================================================================*/
/* Clock-source identifier constants (raw register encodings).               */
/*===========================================================================*/

/**
 * @name    PLL source selections
 * @{
 */
/** @brief HXT oscillator selected as PLL source.*/
#define M251_PLLSRC_HXT 0U
/** @brief HIRC oscillator selected as PLL source.*/
#define M251_PLLSRC_HIRC 1U
/** @brief MIRC oscillator selected as PLL source.*/
#define M251_PLLSRC_MIRC 3U
/** @}*/

/**
 * @name    HCLK source selections
 * @{
 */
/** @brief HXT oscillator selected as HCLK source.*/
#define M251_HCLKSRC_HXT (0UL << CLK_CLKSEL0_HCLKSEL_Pos)
/** @brief PLL output selected as HCLK source.*/
#define M251_HCLKSRC_PLL (2UL << CLK_CLKSEL0_HCLKSEL_Pos)
/** @brief LIRC oscillator selected as HCLK source.*/
#define M251_HCLKSRC_LIRC (3UL << CLK_CLKSEL0_HCLKSEL_Pos)
/** @brief MIRC oscillator selected as HCLK source.*/
#define M251_HCLKSRC_MIRC (5UL << CLK_CLKSEL0_HCLKSEL_Pos)
/** @brief HIRC oscillator selected as HCLK source.*/
#define M251_HCLKSRC_HIRC (7UL << CLK_CLKSEL0_HCLKSEL_Pos)
/** @}*/

/**
 * @name    USB source selections
 * @{
 */
/** @brief HIRC oscillator selected as USB source.*/
#define M251_USBSRC_HIRC (0UL << CLK_CLKSEL0_USBDSEL_Pos)
/** @brief PLL output selected as USB source.*/
#define M251_USBSRC_PLL (1UL << CLK_CLKSEL0_USBDSEL_Pos)
/** @}*/

/*===========================================================================*/
/* Clock-divider helper macros.                                              */
/*===========================================================================*/

/**
 * @brief   Builds the HCLK divider register field.
 *
 * @param[in] n         divider value
 * @return              Encoded CLKDIV0.HCLKDIV field.
 */
#define M251_CLKDIV0_HCLK(n) (((n) - 1UL) << CLK_CLKDIV0_HCLKDIV_Pos)

/**
 * @brief   Builds the USB divider register field.
 *
 * @param[in] n         divider value
 * @return              Encoded CLKDIV0.USBDIV field.
 */
#define M251_CLKDIV0_USB(n) (((n) - 1UL) << CLK_CLKDIV0_USBDIV_Pos)

/*===========================================================================*/
/* PLL register-value builder.                                               */
/*===========================================================================*/

/**
 * @brief   PLLCTL value generated from the configured PLL parameters.
 */
#define M251_PLLCTL_VAL                                   \
    (((uint32_t)(M251_PLL_NO) << CLK_PLLCTL_OUTDIV_Pos) | \
     ((uint32_t)(M251_PLL_NR) << CLK_PLLCTL_INDIV_Pos) |  \
     ((uint32_t)(M251_PLL_NF) << CLK_PLLCTL_FBDIV_Pos) |  \
     ((uint32_t)(M251_PLL_SRC) << CLK_PLLCTL_PLLSRC_Pos))

/*===========================================================================*/
/* Configurable clock-tree parameters (override in mcuconf.h).               */
/*===========================================================================*/

/**
 * @name    M251/M252 clock configuration options
 * @{
 */

/**
 * @brief   HXT oscillator enable switch.
 * @note    The default is @p FALSE.
 */
#if !defined(M251_HXT_ENABLED) || defined(__DOXYGEN__)
#define M251_HXT_ENABLED FALSE
#endif

/**
 * @brief   HXT frequency in Hz, zero if unavailable or unspecified.
 * @note    Required whenever HXT can be selected, including @p M251_NO_INIT
 *          configurations initialized by a bootloader.
 */
#if !defined(M251_HXT_CLK) || defined(__DOXYGEN__)
#define M251_HXT_CLK 0U
#endif

/**
 * @brief   PLL enable switch.
 * @note    The default is @p FALSE.
 */
#if !defined(M251_PLL_ENABLED) || defined(__DOXYGEN__)
#define M251_PLL_ENABLED FALSE
#endif

/**
 * @brief   PLL input clock source.
 * @note    The default is @p M251_PLLSRC_HXT.
 */
#if !defined(M251_PLL_SRC) || defined(__DOXYGEN__)
#define M251_PLL_SRC M251_PLLSRC_HXT
#endif

/**
 * @brief   PLL input divider.
 * @note    The default is 2.
 */
#if !defined(M251_PLL_NR) || defined(__DOXYGEN__)
#define M251_PLL_NR 2
#endif

/**
 * @brief   PLL feedback multiplier.
 * @note    The default is 16.
 */
#if !defined(M251_PLL_NF) || defined(__DOXYGEN__)
#define M251_PLL_NF 16
#endif

/**
 * @brief   PLL output divider register encoding.
 * @note    Values 0, 1 and 3 select divide-by-1, divide-by-2 and divide-by-4.
 * @note    The default is 1.
 */
#if !defined(M251_PLL_NO) || defined(__DOXYGEN__)
#define M251_PLL_NO 1
#endif

/**
 * @brief   HCLK clock source.
 * @note    The default is @p M251_HCLKSRC_HIRC.
 */
#if !defined(M251_HCLK_SRC) || defined(__DOXYGEN__)
#define M251_HCLK_SRC M251_HCLKSRC_HIRC
#endif

/**
 * @brief   HCLK divider.
 * @note    The default is 1.
 */
#if !defined(M251_HCLK_DIV) || defined(__DOXYGEN__)
#define M251_HCLK_DIV 1
#endif

/**
 * @brief   USB clock source.
 * @note    The default is @p M251_USBSRC_HIRC.
 */
#if !defined(M251_USB_SRC) || defined(__DOXYGEN__)
#define M251_USB_SRC M251_USBSRC_HIRC
#endif

/**
 * @brief   USB clock divider.
 * @note    The default is 1.
 */
#if !defined(M251_USB_DIV) || defined(__DOXYGEN__)
#define M251_USB_DIV 1
#endif

#if M251_PLL_SRC == M251_PLLSRC_HXT
#define M251_PLL_FIN M251_HXT_CLK
#elif M251_PLL_SRC == M251_PLLSRC_HIRC
#define M251_PLL_FIN (__HIRC / 4U)
#else
#define M251_PLL_FIN __MIRC
#endif

#if M251_PLL_NO == 0
#define M251_PLL_NO_VAL 1U
#elif M251_PLL_NO == 1
#define M251_PLL_NO_VAL 2U
#else
#define M251_PLL_NO_VAL 4U
#endif

#define M251_PLL_CLOCK \
    (M251_PLL_FIN / M251_PLL_NR * M251_PLL_NF / M251_PLL_NO_VAL)

/*===========================================================================*/
/* Compile-time HCLK frequency hint (must match the runtime configuration).*/
/*===========================================================================*/

/**
 * @brief   Compile-time HCLK frequency in Hz.
 * @details The default is calculated from the configured clock tree.
 */
#if !defined(M251_HCLK) || defined(__DOXYGEN__)
#if M251_HCLK_SRC == M251_HCLKSRC_HXT
#define M251_HCLK (M251_HXT_CLK / M251_HCLK_DIV)
#elif M251_HCLK_SRC == M251_HCLKSRC_PLL
#define M251_HCLK (M251_PLL_CLOCK / M251_HCLK_DIV)
#elif M251_HCLK_SRC == M251_HCLKSRC_LIRC
#define M251_HCLK (__LIRC / M251_HCLK_DIV)
#elif M251_HCLK_SRC == M251_HCLKSRC_MIRC
#define M251_HCLK (__MIRC / M251_HCLK_DIV)
#else
#define M251_HCLK (__HIRC / M251_HCLK_DIV)
#endif
#endif
/** @}*/

/**
 * @name    M251/M252 derived clock constants
 * @{
 */
/** @brief High-speed internal oscillator frequency.*/
#define M251_HSICLK __HIRC
/** @brief Low-speed internal oscillator frequency.*/
#define M251_LSICLK __LIRC
/** @brief Minimum supported HXT frequency.*/
#define M251_HXT_CLK_MIN 4000000UL
/** @brief Maximum supported HXT frequency.*/
#define M251_HXT_CLK_MAX 32000000UL
/** @brief Maximum supported HCLK frequency.*/
#define M251_HCLK_MAX 48000000UL
/** @}*/

#if M251_HXT_ENABLED == TRUE
#if (M251_HXT_CLK < M251_HXT_CLK_MIN) || \
    (M251_HXT_CLK > M251_HXT_CLK_MAX)
#error "M251_HXT_CLK must be in the range 4..32 MHz"
#endif

#if M251_HXT_CLK <= 4000000UL
#define M251_HXT_GAIN_VALUE 0U
#elif M251_HXT_CLK <= 8000000UL
#define M251_HXT_GAIN_VALUE 1U
#elif M251_HXT_CLK <= 12000000UL
#define M251_HXT_GAIN_VALUE 2U
#elif M251_HXT_CLK <= 16000000UL
#define M251_HXT_GAIN_VALUE 3U
#elif M251_HXT_CLK <= 24000000UL
#define M251_HXT_GAIN_VALUE 4U
#else
/* Datasheet table 8.4-4 characterizes a 32 MHz crystal at gain level 7.*/
#define M251_HXT_GAIN_VALUE 7U
#endif
#endif

#if (M251_HCLK_DIV < 1U) || (M251_HCLK_DIV > 16U)
#error "M251_HCLK_DIV must be in the range 1..16"
#endif

#if (M251_USB_DIV < 1U) || (M251_USB_DIV > 16U) || \
    ((M251_USB_DIV != 1U) && ((M251_USB_DIV & 1U) != 0U))
#error "M251_USB_DIV must be 1 or an even value in the range 2..16"
#endif

#if (M251_USB_SRC != M251_USBSRC_HIRC) && \
    (M251_USB_SRC != M251_USBSRC_PLL)
#error "Invalid M251_USB_SRC"
#endif

#if (M251_HCLK_SRC != M251_HCLKSRC_HXT) && \
    (M251_HCLK_SRC != M251_HCLKSRC_PLL) && \
    (M251_HCLK_SRC != M251_HCLKSRC_LIRC) && \
    (M251_HCLK_SRC != M251_HCLKSRC_MIRC) && \
    (M251_HCLK_SRC != M251_HCLKSRC_HIRC)
#error "Invalid M251_HCLK_SRC"
#endif

#if (M251_HCLK_SRC == M251_HCLKSRC_HXT) && \
    (M251_HXT_ENABLED == FALSE)
#error "HXT must be enabled when selected as HCLK source"
#endif

#if (M251_HCLK_SRC == M251_HCLKSRC_PLL) && (M251_PLL_ENABLED == FALSE)
#error "PLL must be enabled when selected as HCLK source"
#endif

#if (M251_PLL_ENABLED == TRUE) && (M251_PLL_SRC == M251_PLLSRC_HXT) && \
    (M251_HXT_ENABLED == FALSE)
#error "HXT must be enabled when selected as PLL source"
#endif

#if M251_PLL_ENABLED == TRUE
#if (M251_PLL_SRC != M251_PLLSRC_HXT) &&  \
    (M251_PLL_SRC != M251_PLLSRC_HIRC) && \
    (M251_PLL_SRC != M251_PLLSRC_MIRC)
#error "Invalid M251_PLL_SRC"
#endif
#if (M251_PLL_NR < 1U) || (M251_PLL_NR > 15U)
#error "M251_PLL_NR must be in the range 1..15"
#elif (M251_PLL_NF < 1U) || (M251_PLL_NF > 63U)
#error "M251_PLL_NF must be in the range 1..63"
#elif (M251_PLL_NO != 0U) && (M251_PLL_NO != 1U) && (M251_PLL_NO != 3U)
#error "M251_PLL_NO must be the raw divide-by-1, divide-by-2, or divide-by-4 code"
#elif ((M251_PLL_FIN / M251_PLL_NR) < 4000000U) || \
    ((M251_PLL_FIN / M251_PLL_NR) > 8000000U)
#error "PLL input after M251_PLL_NR must be in the range 4..8 MHz"
#elif ((M251_PLL_FIN / M251_PLL_NR * M251_PLL_NF) < 64000000U) || \
    ((M251_PLL_FIN / M251_PLL_NR * M251_PLL_NF) > 100000000U)
#error "PLL VCO frequency must be in the range 64..100 MHz"
#endif
#endif

#if (HAL_USE_USB == TRUE) && (M251_USB_SRC == M251_USBSRC_PLL) && \
    (M251_PLL_ENABLED == FALSE)
#error "PLL must be enabled when selected as USB clock source"
#endif

#if (HAL_USE_USB == TRUE) && (M251_USB_SRC == M251_USBSRC_HIRC) && \
    ((__HIRC / M251_USB_DIV) != 48000000U)
#error "USB clock must be exactly 48 MHz"
#endif

#if (HAL_USE_USB == TRUE) && (M251_USB_SRC == M251_USBSRC_PLL) && \
    ((M251_PLL_CLOCK / M251_USB_DIV) != 48000000U)
#error "USB clock must be exactly 48 MHz"
#endif

#if M251_HCLK > M251_HCLK_MAX
#error "M251_HCLK exceeds the device limit"
#endif

/**
 * @brief   Enables access to protected system registers.
 *
 * @notapi
 */
#define SystemUnlockReg() m251_lld_unlock()

/**
 * @brief   Disables access to protected system registers.
 *
 * @notapi
 */
#define SystemLockReg() m251_lld_lock()

/**
 * @brief   Size of the factory-programmed unique identifier in 32-bit words.
 */
#define M251_UNIQUE_ID_WORDS 3U

/**
 * @brief   Returns the frequency of a clock point in Hz.
 * @note    Clock points are not currently exposed by this port.
 *
 * @param[in] clkpt     clock point identifier
 * @return              Zero because the clock point is not available.
 * @notapi
 */
#define hal_lld_get_clock_point(clkpt) 0U

#ifdef __cplusplus
extern "C" {
#endif
  void m251_lld_unlock(void);
  void m251_lld_lock(void);
  bool m251_lld_read_unique_id(uint32_t uid[M251_UNIQUE_ID_WORDS]);
  void m251_lld_chip_reset(void) __attribute__((noreturn));
  void M251_clock_init(void);
  void hal_lld_init(void);
#ifdef __cplusplus
}
#endif

#endif /* HAL_LLD_H */

/** @}*/
