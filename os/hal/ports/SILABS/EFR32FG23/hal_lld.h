/*
    ChibiOS - Copyright (C) 2023 Xael South

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
 * @file    hal_lld.h
 * @brief   PLATFORM HAL subsystem low level driver header.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef _HAL_LLD_H_
#define _HAL_LLD_H_

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#include "efr32_registry.h"

/**
 * @name    Platform identification macros
 * @{
 */
#define PLATFORM_NAME           "EFR32FG23"
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*
 * Configuration-related checks.
 */
#if defined(EFR32FG23X) && !defined(EFR32FG23X_MCUCONF)
#error "Using a wrong mcuconf.h file, EFR32FG23X_MCUCONF not defined"
#endif

#if !defined(HFRCODPLL_MAX_FREQ)
#define HFRCODPLL_MAX_FREQ               80000000UL
#endif

#define EFR32_LFXOCLK                    EFR32_LFXO_FREQ
#define EFR32_HFXOCLK                    EFR32_HFXO_FREQ
#define EFR32_CLKIN0CLK                  EFR32_CLKIN0_FREQ
#define EFR32_FSRCOCLK                   20000000UL
#define EFR32_LFRCOCLK                   32768UL
#define EFR32_ULFRCOCLK                  1000UL
#define EFR32_HFRCODPLLCLK               19000000UL

/**
 * @name    CMU_SYSCLKCTRL register bits definitions
 * @{
 */
#define EFR32_SYSCLKSEL_FSRCO            (1U << 0)   /**< SYSCLK source is FSRCO.       */
#define EFR32_SYSCLKSEL_HFRCODPLL        (2U << 0)   /**< SYSCLK source is HFRCODPLL    */
#define EFR32_SYSCLKSEL_HFXO             (3U << 0)   /**< SYSCLK source is HFCO.        */
#define EFR32_SYSCLKSEL_CLKIN0           (4U << 0)   /**< SYSCLK source is CLKIN0.      */

#define EFR32_PPRE_DIV1                  (0U << 10)  /**< PCLK is HCLK divided by 1     */
#define EFR32_PPRE_DIV2                  (1U << 10)  /**< PCLK is HCLK divided by 2     */

#define EFR32_HPRE_DIV1                  (0U  << 12)  /**< HCLK is SYSCLK divided by 1  */
#define EFR32_HPRE_DIV2                  (1U  << 12)  /**< HCLK is SYSCLK divided by 2  */
#define EFR32_HPRE_DIV4                  (3U  << 12)  /**< HCLK is SYSCLK divided by 4  */
#define EFR32_HPRE_DIV8                  (7U  << 12)  /**< HCLK is SYSCLK divided by 8  */
#define EFR32_HPRE_DIV16                 (15U << 12)  /**< HCLK is SYSCLK divided by 16 */

#define EFR32_RHPRE_DIV1                 (0U << 16)   /**< Radio HCLK is HCLK divided by 1 */
#define EFR32_RHPRE_DIV2                 (1U << 16)   /**< Radio HCLK is HCLK divided by 2 */

/**
 * @brief   System clock source.
 */
#if (EFR32_SYSCLKSEL == EFR32_SYSCLKSEL_FSRCO) || defined(__DOXYGEN__)
#define EFR32_SYSCLK                EFR32_FSRCOCLK
#elif (EFR32_SYSCLKSEL == EFR32_SYSCLKSEL_HFRCODPLL)
#define EFR32_SYSCLK                EFR32_HFRCODPLLCLK
#elif (EFR32_SYSCLKSEL == EFR32_SYSCLKSEL_HFXO)
#define EFR32_SYSCLK                EFR32_HFXOCLK
#elif (EFR32_SYSCLKSEL == EFR32_SYSCLKSEL_CLKIN0)
#define EFR32_SYSCLK                EFR32_CLKIN0CLK
#else
#error "invalid EFR32_SYSCLKSEL value specified"
#endif

/**
 * @brief   HCLK frequency.
 */
#if (EFR32_HPRE == EFR32_HPRE_DIV1) || defined(__DOXYGEN__)
#define EFR32_HCLK                 (EFR32_SYSCLK / 1)
#elif EFR32_HPRE == EFR32_HPRE_DIV2
#define EFR32_HCLK                  (EFR32_SYSCLK / 2)
#elif EFR32_HPRE == EFR32_HPRE_DIV4
#define EFR32_HCLK                 (EFR32_SYSCLK / 4)
#elif EFR32_HPRE == EFR32_HPRE_DIV8
#define EFR32_HCLK                 (EFR32_SYSCLK / 8)
#elif EFR32_HPRE == EFR32_HPRE_DIV16
#define EFR32_HCLK                 (EFR32_SYSCLK / 16)
#else
#error "invalid EFR32_HPRE value specified"
#endif

/**
 * @brief   PCLK frequency.
 */
#if (EFR32_PPRE == EFR32_PPRE_DIV1) || defined(__DOXYGEN__)
#define EFR32_PCLK                 (EFR32_HCLK / 1)
#elif EFR32_PPRE == EFR32_PPRE_DIV2
#define EFR32_PCLK                  (EFR32_HCLK / 2)
#else
#error "invalid EFR32_PPRE value specified"
#endif

/**
 * @brief   RHCLK frequency.
 */
#if (EFR32_RHPRE == EFR32_RHPRE_DIV1) || defined(__DOXYGEN__)
#define EFR32_RHCLK                (EFR32_SYSCLK / 1)
#elif EFR32_RHPRE == EFR32_RHPRE_DIV2
#define EFR32_RHCLK                (EFR32_SYSCLK / 2)
#else
#error "invalid EFR32_RHPRE value specified"
#endif

#if EFR32_HFXO_ENABLED
#else
#if EFR32_SYSCLKSEL == EFR32_SYSCLKSEL_HFXO
#error "HFXO is not enabled, required by EFR32_SYSCLKSEL"
#endif
#endif

#if EFR32_FSRCO_ENABLED
#else
#if EFR32_SYSCLKSEL == EFR32_SYSCLKSEL_FSRCO
#error "FSRCO is not enabled, required by EFR32_SYSCLKSEL"
#endif
#endif

#if EFR32_CLKIN0CLK == 0U
#else
#if EFR32_SYSCLKSEL == EFR32_SYSCLKSEL_CLKIN0
#error "CLKIN0 is not enabled, required by EFR32_SYSCLKSEL"
#endif
#endif

#define EFR32_EM01GRPACLKSEL_NOCLOCK     (1u << 0)
#define EFR32_EM01GRPACLKSEL_HFRCODPLL   (1u << 1)
#define EFR32_EM01GRPACLKSEL_HFXO        (1u << 2)
#define EFR32_EM01GRPACLKSEL_FSRCO       (1u << 3)
#define EFR32_EM01GRPACLKSEL_HFRCOEM23   (1u << 4)
#define EFR32_EM01GRPACLKSEL_HFRCODPLLRT (1u << 5)
#define EFR32_EM01GRPACLKSEL_HFXORT      (1u << 6)

#define EFR32_EM01GRPCCLKSEL_NOCLOCK     (1u << 0)
#define EFR32_EM01GRPCCLKSEL_HFRCODPLL   (1u << 1)
#define EFR32_EM01GRPCCLKSEL_HFXO        (1u << 2)
#define EFR32_EM01GRPCCLKSEL_FSRCO       (1u << 3)
#define EFR32_EM01GRPCCLKSEL_HFRCOEM23   (1u << 4)
#define EFR32_EM01GRPCCLKSEL_HFRCODPLLRT (1u << 5)
#define EFR32_EM01GRPCCLKSEL_HFXORT      (1u << 6)

#define EFR32_EM23GRPACLKSEL_NOCLOCK     (1u << 0)
#define EFR32_EM23GRPACLKSEL_LFXO        (1u << 1)
#define EFR32_EM23GRPACLKSEL_LFRCO       (1u << 2)
#define EFR32_EM23GRPACLKSEL_ULFRCO      (1u << 3)

#define EFR32_EM4GRPACLKSEL_NOCLOCK      (1u << 0)
#define EFR32_EM4GRPACLKSEL_LFXO         (1u << 1)
#define EFR32_EM4GRPACLKSEL_LFRCO        (1u << 2)
#define EFR32_EM4GRPACLKSEL_ULFRCO       (1u << 3)
                                        
#define EFR32_EUSART1SEL_NOCLOCK         (0u << 0)
#define EFR32_EUSART1SEL_EM01GRPCCLK     (1u << 1)
#define EFR32_EUSART1SEL_HFRCOEM23       (1u << 2)
#define EFR32_EUSART1SEL_LFRCO           (1u << 3)
#define EFR32_EUSART1SEL_LFXO            (1u << 4)

#define EFR32_EUSART23SEL_NOCLOCK        (0u << 0)
#define EFR32_EUSART23SEL_HFRCODPLL      (1u << 0)
#define EFR32_EUSART23SEL_HFRCOEM23      (1u << 1)
#define EFR32_EUSART23SEL_HFXO           (1u << 2)
#define EFR32_EUSART23SEL_HFRCODPLLRT    (1u << 3)
#define EFR32_EUSART23SEL_HFXORT         (1u << 4)
#define EFR32_EUSART23SEL_FSRCO          (1u << 5)


#if EFR32_EM01GRPACLKSEL == EFR32_EM01GRPACLKSEL_HFRCODPLL
#define EFR32_EM01GRPACLK               EFR32_HCLK
#elif EFR32_EM01GRPACLKSEL == EFR32_EM01GRPACLKSEL_HFXO
#define EFR32_EM01GRPACLK               EFR32_HFXOCLK
#elif EFR32_EM01GRPACLKSEL == EFR32_EM01GRPACLKSEL_FSRCO
#define EFR32_EM01GRPACLK               EFR32_FSRCOCLK
#elif EFR32_EM01GRPACLKSEL == EFR32_EM01GRPACLKSEL_HFRCOEM23
#error "EFR32_EM01GRPACLKSEL_HFRCOEM23 is not implemented"
#elif EFR32_EM01GRPACLKSEL == EFR32_EM01GRPACLKSEL_HFRCODPLLRT
#error "EFR32_EM01GRPACLKSEL_HFRCODPLLRT is not implemented"
#elif EFR32_EM01GRPACLKSEL == EFR32_EM01GRPACLKSEL_HFXORT
#error "EFR32_EM01GRPACLKSEL_HFXORT is not implemented"
#endif


#if EFR32_EM01GRPCCLKSEL == EFR32_EM01GRPCCLKSEL_HFRCODPLL
#define EFR32_EM01GRPCCLK               EFR32_HCLK
#elif EFR32_EM01GRPCCLKSEL == EFR32_EM01GRPCCLKSEL_HFXO
#define EFR32_EM01GRPCCLK               EFR32_HFXOCLK
#elif EFR32_EM01GRPCCLKSEL == EFR32_EM01GRPCCLKSEL_FSRCO
#define EFR32_EM01GRPCCLK               EFR32_FSRCOCLK
#elif EFR32_EM01GRPCCLKSEL == EFR32_EM01GRPCCLKSEL_HFRCOEM23
#error "EFR32_EM01GRPCCLKSEL_HFRCOEM23 is not implemented"
#elif EFR32_EM01GRPCCLKSEL == EFR32_EM01GRPCCLKSEL_HFRCODPLLRT
#error "EFR32_EM01GRPCCLKSEL_HFRCODPLLRT is not implemented"
#elif EFR32_EM01GRPCCLKSEL == EFR32_EM01GRPCCLKSEL_HFXORT
#error "EFR32_EM01GRPCCLKSEL_HFXORT is not implemented"
#endif


#if EFR32_EM23GRPACLKSEL == EFR32_EM23GRPACLKSEL_LFXO
#define EFR32_EM23GRPACLK               EFR32_LFXOCLK
#elif EFR32_EM23GRPACLKSEL == EFR32_EM23GRPACLKSEL_LFRCO
#define EFR32_EM23GRPACLK               EFR32_LFRCOCLK
#elif EFR32_EM23GRPACLKSEL == EFR32_EM23GRPACLKSEL_ULFRCO
#define EFR32_EM23GRPACLK               EFR32_ULFRCOCLK
#endif


#if EFR32_EM4GRPACLKSEL == EFR32_EM4GRPACLKSEL_LFXO
#define EFR32_EM4GRPACLK                EFR32_LFXOCLK
#elif EFR32_EM4GRPACLKSEL == EFR32_EM4GRPACLKSEL_LFRCO
#define EFR32_EM4GRPACLK                EFR32_LFRCOCLK
#elif EFR32_EM4GRPACLKSEL == EFR32_EM4GRPACLKSEL_ULFRCO
#define EFR32_EM4GRPACLK                EFR32_ULFRCOCLK
#endif


#define EFR32_LETIM1CLK                 EFR32_EM23GRPACLK


#if EFR32_EUSART1SEL == EFR32_EUSART1SEL_EM01GRPCCLK
#define EFR32_EUSART1CLK                EFR32_EM01GRPCCLK
#elif EFR32_EUSART1SEL == EFR32_EUSART1SEL_HFRCOEM23
#error "EFR32_EUSART1SEL_HFRCOEM23 is not implemented"
#elif EFR32_EUSART1SEL == EFR32_EUSART1SEL_LFRCO
#define EFR32_EUSART1CLK                EFR32_LFRCOCLK
#elif EFR32_EUSART1SEL == EFR32_EUSART1SEL_LFXO
#define EFR32_EUSART1CLK                EFR32_LFXOCLK
#endif

#define EFR32_EUSART23CLK               EFR32_EM01GRPCCLK

#define EFR32_USART1CLK                 EFR32_PCLK


/* Vector8C = Vector(40 + 4*LETIMER0_IRQn) */
#define EFR32_LETIM1_HANDLER            Vector8C
#define EFR32_LETIM1_NUMBER             LETIMER0_IRQn

/* Vector120 = Vector(40 + 4*PCNT0_IRQn) */
#define EFR32_PCNT0_HANDLER				Vector120
#define EFR32_PCNT0_NUMBER				PCNT0_IRQn

/* VectorA8 = Vector(40 + 4*GPIO_ODD_IRQn) */
#define EFR32_GPIO_ODD_HANDLER 			VectorA8
#define EFR32_GPIO_ODD_NUMBER			GPIO_ODD_IRQn

/* VectorAC = Vector(40 + 4*GPIO_EVEN_IRQn) */
#define EFR32_GPIO_EVEN_HANDLER 		VectorAC
#define EFR32_GPIO_EVEN_NUMBER			GPIO_EVEN_IRQn

/* Vector64 = Vector(40 + 4*USART0_RX_IRQn) */
#define EFR32_USART1_RX_HANDLER 		Vector64
#define EFR32_USART1_RX_NUMBER			USART0_RX_IRQn

/* Vector68 = Vector(40 + 4USART0_TX_IRQn) */
#define EFR32_USART1_TX_HANDLER 		Vector68
#define EFR32_USART1_TX_NUMBER			USART0_TX_IRQn

/* Vector6C = Vector(40 + 4*EUSART0_RX_IRQn) */
#define EFR32_EUSART1_RX_HANDLER 		Vector6C
#define EFR32_EUSART1_RX_NUMBER			EUSART0_RX_IRQn

/* Vector70 = Vector(40 + 4*EUSART0_TX_IRQn) */
#define EFR32_EUSART1_TX_HANDLER 		Vector70
#define EFR32_EUSART1_TX_NUMBER			EUSART0_TX_IRQn

/* Vector74 = Vector(40 + 4*EUSART1_RX_IRQn) */
#define EFR32_EUSART2_RX_HANDLER 		Vector74
#define EFR32_EUSART2_RX_NUMBER			EUSART1_RX_IRQn

/* Vector78 = Vector(40 + 4*EUSART1_TX_IRQn) */
#define EFR32_EUSART2_TX_HANDLER 		Vector78
#define EFR32_EUSART2_TX_NUMBER			EUSART1_TX_IRQn

/* Vector7C = Vector(40 + 4*EUSART2_RX_IRQn) */
#define EFR32_EUSART3_RX_HANDLER 		Vector7C
#define EFR32_EUSART3_RX_NUMBER			EUSART2_RX_IRQn

/* Vector80 = Vector(40 + 4*EUSART2_TX_IRQn) */
#define EFR32_EUSART3_TX_HANDLER 		Vector80
#define EFR32_EUSART3_TX_NUMBER			EUSART2_TX_IRQn

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Various helpers.*/
#include "nvic.h"

#ifdef __cplusplus
extern "C" {
#endif
  void efr32_chip_init(void);
  void efr32_clock_init(void);
  void efr32_escape_hatch(void);
  void hal_lld_init(void);
#ifdef __cplusplus
}
#endif

#endif /* _HAL_LLD_H_ */

/** @} */
