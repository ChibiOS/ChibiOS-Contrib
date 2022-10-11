/*
  Copyright (C) 2020 Alex Lewontin
  Copyright (C) 2019 /u/KeepItUnder

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
 * @file    NUC126/hal_lld.h
 * @brief   NUC126 HAL subsystem low level driver header.
 * @pre     This module requires the following macros to be defined in the
 *          @p board.h file:
 *          - NUC126_HSECLK.
 *          - NUC126_HSE_BYPASS (optionally).
 *          .
 *
 * @addtogroup HAL
 * @{
 */

#ifndef HAL_LLD_H
#define HAL_LLD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Platform identification macros
 * @{
 */
#if defined(NUC126VG4AE) || defined(__DOXYGEN__)
#define PLATFORM_NAME           "NUC126VG4AE NUC126 Cortex M0 USB Micro"
#define NUC126xx4AE
#define NUC126_FLASH_SIZE 0x40000
#elif defined(NUC126SG4AE)
#define PLATFORM_NAME           "NUC126SG4AE NUC126 Cortex M0 USB Micro"
#define NUC126xx4AE
#define NUC126_FLASH_SIZE 0x40000
#elif defined(NUC126LG4AE)
#define PLATFORM_NAME           "NUC126LG4AE NUC126 Cortex M0 USB Micro"
#define NUC126xx4AE
#define NUC126_FLASH_SIZE 0x40000
#elif defined(NUC126SE4AE)
#define PLATFORM_NAME           "NUC126SE4AE NUC126 Cortex M0 USB Micro"
#define NUC126xx4AE
#define NUC126_FLASH_SIZE 0x20000
#elif defined(NUC126LE4AE)
#define PLATFORM_NAME           "NUC126LE4AE NUC126 Cortex M0 USB Micro"
#define NUC126xx4AE
#define NUC126_FLASH_SIZE 0x20000
#elif defined(NUC126NE4AE)
#define PLATFORM_NAME           "NUC126NE4AE NUC126 Cortex M0 USB Micro"
#define NUC126xx4AE
#define NUC126_FLASH_SIZE 0x20000
#else
#error "NUC126 device unsupported or not specified"
#endif

/** @} */

/**
 * @name    Absolute Maximum Ratings
 * @{
 */

/**
 * @brief   Maximum HSE clock frequency.
 */
#define NUC126_HSECLK_MAX        24000000

/**
 * @brief   Minimum HSE clock frequency.
 */
#define NUC126_HSECLK_MIN        4000000

/**
 * @brief   Minimum PLL frequency.
 */
#define NUC126_PLLCLK_MIN 25000000UL

/**
 * @brief   Maximum PLL frequency.
 */
#define NUC126_PLLCLK_MAX 144000000UL

/**
 * @brief   Minimum HCLK divider value.
 */
#define NUC126_HCLKDIV_MIN 1

/**
 * @brief   Maximum HCLK divider value.
 */
#define NUC126_HCLKDIV_MAX 16
/** @} */

/**
 * @name    Internal clock sources
 * @{
 */
#define NUC126_HSICLK            __HIRC       /**< High speed internal clock. */
#define NUC126_HSI48CLK          __HIRC48     /**< High speed internal clock. */
#define NUC126_LSICLK            __LIRC       /**< Low speed internal clock.  */
/** @} */

/**
 * @name    HCLKSEL bit definitions
 * @{
 */
#define NUC126_HCLKSRC_HSE     (0 << CLK_CLKSEL0_HCLKSEL_Pos) /**< HCLK source is HSE.      */
#define NUC126_HCLKSRC_LSE     (1 << CLK_CLKSEL0_HCLKSEL_Pos) /**< HCLK source is LSE.      */
#define NUC126_HCLKSRC_PLL     (2 << CLK_CLKSEL0_HCLKSEL_Pos) /**< HCLK source is PLL.      */
#define NUC126_HCLKSRC_LSI     (3 << CLK_CLKSEL0_HCLKSEL_Pos) /**< HCLK source is LSI.      */
#define NUC126_HCLKSRC_HSI48   (4 << CLK_CLKSEL0_HCLKSEL_Pos) /**< HCLK source is HSI48.    */
#define NUC126_HCLKSRC_HSI     (7 << CLK_CLKSEL0_HCLKSEL_Pos) /**< HCLK source is HSI.      */
/** @} */

/**
 * @name    PLLSRC bit definitions
 * @{
 */
#define NUC126_PLLSRC_HSE      (0 << CLK_PLLCTL_PLLSRC_Pos) /**< PLL source is HSE.      */
#define NUC126_PLLSRC_HSI      (1 << CLK_PLLCTL_PLLSRC_Pos) /**< PLL source is HSI.      */
/** @} */

/**
 * @name    User config bit definitions
 * @{
 */
#define NUC126_CONFIG0_DFEN_Pos 0
#define NUC126_CONFIG0_DFEN_Msk (1 << NUC126_CONFIG0_DFEN_Pos)

#define NUC126_CONFIG0_LOCK_Pos 1
#define NUC126_CONFIG0_LOCK_Msk (1 << NUC126_CONFIG0_LOCK_Pos)

#define NUC126_CONFIG0_CFGXT1_Pos 27
#define NUC126_CONFIG0_CFGXT1_Msk (1 << NUC126_CONFIG0_CFGXT1_Pos)

/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    NUMICRO configuration options
 * @{
 */

/**
 * @brief   Disables the PWR/RCC initialization in the HAL.
 */
#if !defined(NUC126_NO_INIT) || defined(__DOXYGEN__)
#define NUC126_NO_INIT                       FALSE
#endif

/**
 * @brief   Enables or disables the HSI clock source.
 */
#if !defined(NUC126_HSI_ENABLED) || defined(__DOXYGEN__)
#define NUC126_HSI_ENABLED                   TRUE
#endif

/**
 * @brief   Enables or disables the LSI clock source.
 */
#if !defined(NUC126_LSI_ENABLED) || defined(__DOXYGEN__)
#define NUC126_LSI_ENABLED                   FALSE
#endif

/**
 * @brief   Enables or disables the HSI48 clock source.
 */
#if !defined(NUC126_HSI48_ENABLED) || defined(__DOXYGEN__)
#define NUC126_HSI48_ENABLED                 FALSE
#endif

/**
 * @brief   Enables or disables the HSE clock source.
 */
#if !defined(NUC126_HSE_ENABLED) || defined(__DOXYGEN__)
#define NUC126_HSE_ENABLED                   TRUE
#endif

/**
 * @brief   Enables or disables the LSE clock source.
 */
#if !defined(NUC126_LSE_ENABLED) || defined(__DOXYGEN__)
#define NUC126_LSE_ENABLED                   TRUE
#endif

/**
 * @brief   Enables or disables PLL
 */
#if !defined(NUC126_PLL_ENABLED) || defined(__DOXYGEN__)
#define NUC126_PLL_ENABLED TRUE
#endif

/**
 * @brief   Core clock speed.
 */
#if !defined(NUC126_HCLK) || defined(__DOXYGEN__)
#if NUC126_PLL_ENABLED
#define NUC126_HCLK 72000000UL
#else
#define NUC126_HCLK __HIRC
#endif
#endif

/**
 * @brief   Enables the use of the CONFIG0/1 registers
 */
#if !defined(NUC126_CONFIG_ENABLED) || defined(__DOXYGEN__)
#define NUC126_CONFIG_ENABLED FALSE
#endif

#if (NUC126_CONFIG_ENABLED == TRUE)
/**
 * @brief   Enables or disables data flash
 * @warning If data this is set to @p TRUE, the data flash
 *          is subtracted from the APROM. The linker script is not aware
 *          of this, so therefore it is the responsiblity of the user to ensure
 *          that the combination of the data flash & the text section still fit
 *          into ROM.

 * @note    The default is @p TRUE.
 */
#if !defined(NUC126_CONFIG_DATAFLASH_ENABLED) || defined(__DOXYGEN__)
#define NUC126_CONFIG_DATAFLASH_ENABLED TRUE
#endif

/**
 * @brief   Sets the data flash size. This is ignored if data flash is disabled.
 */
#if !defined(NUC126_CONFIG_DATAFLASH_SIZE) || defined(__DOXYGEN__)
#define NUC126_CONFIG_DATAFLASH_SIZE 4096
#endif

#endif /* NUC126_CONFIG_ENABLED == TRUE */

/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*
 * Configuration-related checks.
 */
#if !defined(NUC126_MCUCONF)
#error "Using a wrong mcuconf.h file, NUC126_MCUCONF not defined"
#endif

/*
 * HSE checks.
 */
#if NUC126_HSE_ENABLED

#if !defined(NUC126_HSECLK)
#error "HSE frequency not defined"
#elif (NUC126_HSECLK < NUC126_HSECLK_MIN) || (NUC126_HSECLK > NUC126_HSECLK_MAX)
#error "NUC126_HSECLK outside acceptable range (NUC126_HSECLK_MIN...NUC126_HSECLK_MAX)"
#endif
#define NUC126_CONFIG0_HSE_PINS 0
#else
#define NUC126_CONFIG0_HSE_PINS NUC126_CONFIG0_CFGXT1_Msk
#endif

#define NUC126_PLLCLK (NUC126_HCLK * 2)

/*
* Persistant configuration settings.
*/

#if (NUC126_CONFIG_ENABLED == TRUE)

#if (NUC126_CONFIG_DATAFLASH_ENABLED == TRUE)
/* DFEN = 0 */
#define NUC126_CONFIG0_DATAFLASH NUC126_CONFIG0_DFEN_Msk
#define NUC126_DFBADDR ((NUC126_FLASH_SIZE - NUC126_CONFIG_DATAFLASH_SIZE) & ~(0x7FFUL))
#else  /* NUC126_CONFIG_DATAFLASH_ENABLED == FALSE */
#undef NUC126_CONFIG_DATAFLASH_SIZE
#define NUC126_CONFIG_DATAFLASH_SIZE 0
/* DFEN = 1 */
#define NUC126_CONFIG0_DATAFLASH 0
#define NUC126_DFBADDR 0xFFFFF800UL
#endif /* NUC126_CONFIG_DATAFLASH_ENABLED == TRUE/FALSE */

#define NUC126_CONFIG0                                                      \
  0xFFFFFFFFUL & (~NUC126_CONFIG0_DATAFLASH) & (~NUC126_CONFIG0_HSE_PINS)
#define NUC126_CONFIG1 NUC126_DFBADDR

#else /* NUC126_CONFIG_ENABLED == FALSE */

#if defined(NUC126_CONFIG_DATAFLASH_ENABLED)
#error                                                                      \
    "Defining NUC126_CONFIG_DATAFLASH_ENABLED requires NUC126_CONFIG_ENABLED to be TRUE"
#endif

#if defined(NUC126_CONFIG_DATAFLASH_SIZE)
#error                                                                      \
    "Defining NUC126_CONFIG_DATAFLASH_SIZE requires NUC126_CONFIG_ENABLED to be TRUE"
#endif

#endif /* NUC126_CONFIG_ENABLED == TRUE/FALSE */

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/* Alias for compatibility */
#define SystemUnlockReg() UNLOCKREG()

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Various helpers */
#include "NUC126.h"
#include "nuc126_isr.h"
#include "nuc126_registry.h"
#include "nvic.h"

#ifdef __cplusplus
extern "C" {
#endif
  void hal_lld_init(void);
  void NUC126_clock_init(void);
#ifdef __cplusplus
}
#endif

#endif /* _HAL_LLD_H_ */

/** @} */
