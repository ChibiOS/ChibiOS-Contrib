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
 * @file    SK32F0xx/hal_lld.c
 * @brief   SK32F0xx HAL subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/* GPIO enable bits are located in bits 17..22 of the AHB clock/reset
   registers (the vendor device header contains wrong values for the GPIOD,
   GPIOE, GPIOF reset macros, the enable macros are correct and are used
   here).*/
#define SK32_GPIO_CLK_MASK      (RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN |   \
                                 RCC_AHBENR_GPIOCEN | RCC_AHBENR_GPIODEN |   \
                                 RCC_AHBENR_GPIOEEN | RCC_AHBENR_GPIOFEN)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   CMSIS system core clock variable.
 */
uint32_t SystemCoreClock = SK32_HCLK;

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
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void) {

  /* Reset of all the peripherals. GPIOs are not reset because the board
     early initialization code may have already configured them. SYSCFG
     is not reset either: Cortex-M0 has no VTOR, so when the application
     is launched behind the sk32duino bootloader its exception vectors are
     fetched from the SRAM copy selected by SYSCFG CFGR1 MEM_MODE = 0b11.
     Resetting SYSCFG here would silently clear that remap and the first
     interrupt (the SysTick started by chSysInit()) would vector into the
     bootloader handlers again. The device header spells this bit
     RCC_APB2ENR_SYSCFGRST although it lives in the APB2RSTR register.*/
  RCC->AHBRSTR = (uint32_t)~SK32_GPIO_CLK_MASK;
  RCC->AHBRSTR = (uint32_t)0;
  RCC->APB2RSTR = (uint32_t)~RCC_APB2ENR_SYSCFGRST;
  RCC->APB2RSTR = (uint32_t)0;
  RCC->APB1RSTR = (uint32_t)0xFFFFFFFF;
  RCC->APB1RSTR = (uint32_t)0;

  /* DMA subsystem initialization.*/
#if defined(SK32_DMA_REQUIRED)
  dmaInit();
#endif
}

/**
 * @brief   SK32F0xx clocks and PLL initialization.
 * @note    All the involved constants come from the file @p mcuconf.h.
 * @note    This function should be invoked just after the system reset from
 *          the board early initialization code (__early_init).
 *
 * @special
 */
void sk32_clock_init(void) {

#if !SK32_NO_INIT
  /* HSI setup, it enforces the reset situation in order to handle possible
     problems with JTAG probes and re-initializations.*/
  RCC->CR |= RCC_CR_HSION;                  /* Make sure HSI is ON.          */
  while ((RCC->CR & RCC_CR_HSIRDY) == 0)
    ;                                       /* Wait until HSI is stable.     */

  /* HSI is selected as new source without touching the other fields in
     CFGR. Clearing the register has to be postponed after HSI is the
     new source.*/
  RCC->CFGR &= ~RCC_CFGR_SW;                /* Reset SW, selecting HSI.      */
  while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI)
    ;                                       /* Wait until HSI is selected.   */

  /* Registers finally cleared to reset values.*/
  RCC->CR &= RCC_CR_HSITRIM | RCC_CR_HSION; /* CR reset value.               */
  RCC->CFGR = 0;                            /* CFGR reset value.             */
  RCC->CFGR2 = 0;                           /* CFGR2 reset value.            */
  RCC->CFGR3 = 0;                           /* CFGR3 reset value.            */
  RCC->CR2 = 0;                             /* CR2 reset value.              */

#if SK32_ACTIVATE_PLL
  /* PLL configuration, the clock source is the HSI divided by PREDIV1,
     the multiplication factor is SK32_PLLMUL_VALUE. The AHB/APB prescalers
     are left at their DIV1 reset value.*/
  RCC->CFGR2 = SK32_PREDIV1;                /* PREDIV1 value.                */
  RCC->CFGR = SK32_PLLSRC_HSI_PREDIV | SK32_PLLMUL;

  /* PLL activation.*/
  RCC->CR |= RCC_CR_PLLON;
  while ((RCC->CR & RCC_CR_PLLRDY) == 0)
    ;                                       /* Wait until PLL is stable.     */
#endif /* SK32_ACTIVATE_PLL */

  /* Flash setup and final clock selection. 2 wait states are required at
     72MHz (the vendor keeps 2 wait states also at 48MHz).*/
  FLASH->ACR = SK32_FLASHBITS;

  /* Switching to the configured clock source if it is different from HSI.*/
#if (SK32_SW != SK32_SW_HSI)
  RCC->CFGR |= SK32_SW;
  while ((RCC->CFGR & RCC_CFGR_SWS) != (SK32_SW << 2))
    ;                                       /* Wait selection complete.      */
#endif /* (SK32_SW != SK32_SW_HSI) */

  /* SystemCoreClock is updated with the real HCLK frequency. It runs before
     the initialization of the .data segment, the same value is assigned by
     the variable initializer.*/
  SystemCoreClock = SK32_HCLK;
#endif /* !SK32_NO_INIT */
}

/** @} */
