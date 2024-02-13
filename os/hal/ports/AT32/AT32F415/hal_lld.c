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
 * @file    AT32F415/hal_lld.c
 * @brief   AT32F415 HAL subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   CMSIS system core clock variable.
 * @note    It is declared in system_at32f415.h.
 */
uint32_t SystemCoreClock = AT32_HCLK;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Initializes the battery powered domain.
 * @note    WARNING! Changing clock source impossible without resetting
 *          of the whole BPR domain.
 */
static void hal_lld_battery_powered_domain_init(void) {

  /* Battery powered domain access enabled and left open. */
  PWC->CTRL |= PWC_CTRL_BPWEN;

  /* Reset BPR domain if different clock source selected. */
  if ((CRM->BPDC & AT32_ERTCSEL_MASK) != AT32_ERTCSEL) {
    /* Battery powered domain reset. */
    CRM->BPDC = CRM_BPDC_BPDRST;
    CRM->BPDC = 0;
  }

#if AT32_LEXT_ENABLED
#if defined(AT32_LEXT_BYPASS)
  /* LEXT Bypass. */
  CRM->BPDC |= CRM_BPDC_LEXTEN | CRM_BPDC_LEXTBYPS;
#else
  /* No LEXT Bypass. */
  CRM->BPDC |= CRM_BPDC_LEXTEN;
#endif
  while ((CRM->BPDC & CRM_BPDC_LEXTSTBL) == 0)
    ;                                       /* Waits until LEXT is stable.   */
#endif

#if HAL_USE_RTC
  /* If the battery powered domain hasn't been initialized yet then proceed
     with initialization. */
  if ((CRM->BPDC & CRM_BPDC_ERTCEN) == 0) {
    /* Selects clock source. */
    CRM->BPDC |= AT32_ERTCSEL;

    /* ERTC clock enabled. */
    CRM->BPDC |= CRM_BPDC_ERTCEN;
  }
#endif /* HAL_USE_RTC */
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(AT32_DMA_REQUIRED) || defined(__DOXYGEN__)
#if defined(AT32_DMA2_CH4_5_HANDLER) || defined(__DOXYGEN__)
/**
 * @brief   DMA2 streams 4 and 5 shared ISR.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_DMA2_CH4_5_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  /* Check on channel 4 of DMA2. */
  dmaServeInterrupt(AT32_DMA2_STREAM4);

  /* Check on channel 5 of DMA2. */
  dmaServeInterrupt(AT32_DMA2_STREAM5);

  OSAL_IRQ_EPILOGUE();
}
#endif /* defined(AT32_DMA2_CH4_5_HANDLER) */

#if defined(AT32_DMA2_CH6_7_HANDLER) || defined(__DOXYGEN__)
/**
 * @brief   DMA2 streams 6 and 7 shared ISR.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_DMA2_CH6_7_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  /* Check on channel 6 of DMA2.*/
  dmaServeInterrupt(AT32_DMA2_STREAM6);

  /* Check on channel 7 of DMA2.*/
  dmaServeInterrupt(AT32_DMA2_STREAM7);

  OSAL_IRQ_EPILOGUE();
}
#endif /* defined(AT32_DMA2_CH6_7_HANDLER) */
#endif /* defined(AT32_DMA_REQUIRED) */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void) {

  /* Reset of all peripherals. */
  crmResetAPB1(0xFFFFFFFF);
  crmResetAPB2(0xFFFFFFFF);

  /* PWC clocks enabled. */
  crmEnablePWCInterface(true);

  /* Initializes the backup domain. */
  hal_lld_battery_powered_domain_init();

  /* DMA subsystems initialization. */
#if defined(AT32_DMA_REQUIRED)
  dmaInit();
#endif

  /* IRQ subsystem initialization. */
  irqInit();

  /* Power voltage monitoring enable. */
#if AT32_PVM_ENABLE
  PWC->CTRL |= PWC_CTRL_PVMEN | (AT32_PVMSEL & AT32_PVMSEL_MASK);
#endif /* AT32_PVM_ENABLE */
}

/**
 * @brief   AT32 clocks and PLL initialization.
 * @note    All the involved constants come from the file @p board.h.
 * @note    This function should be invoked just after the system reset.
 *
 * @special
 */

/*
 * Clocks initialization for all series.
 */
void at32_clock_init(void) {

#if !AT32_NO_INIT
  /* HICK setup, it enforces the reset situation in order to handle possible
     problems with JTAG probes and re-initializations. */
  CRM->CTRL |= CRM_CTRL_HICKEN;             /* Make sure HICK is ON.          */
  while (!(CRM->CTRL & CRM_CTRL_HICKSTBL))
    ;                                       /* Wait until HICK is stable.     */

  /* HICK is selected as new source without touching the other fields in
     CFGR. Clearing the register has to be postponed after HICK is the
     new source. */
  CRM->CFG &= ~CRM_CFG_SCLKSEL;             /* Reset SCLKSEL, selecting HICK. */
  while ((CRM->CFG & CRM_CFG_SCLKSTS) != CRM_CFG_SCLKSTS_HICK)
    ;                                       /* Waits until HICK is selected.  */

  /* Registers finally cleared to reset values. */
  CRM->CTRL &= ~(0x010D0000U);              /* CTRL reset value.             */
  CRM->CFG = 0x00000000;                    /* CFG reset value.              */
  CRM->PLL = 0x00001F10U;                   /* PLL reset value.              */
  CRM->MISC1 = 0x00100000;                  /* MISC1 reset value.            */
  CRM->MISC2 = 0x0000000D;                  /* MISC2 reset value.            */
  CRM->CLKINT = 0x009F0000;                 /* CLKINT reset value.           */

  /* Flash setup and final clock selection. */
  FLASH->PSR = AT32_FLASHBITS;       /* Flash wait states depending on clock. */
  while ((FLASH->PSR & FLASH_PSR_WTCYC_Msk) !=
         (AT32_FLASHBITS & FLASH_PSR_WTCYC_Msk)) {
  }

#if AT32_HEXT_ENABLED
#if defined(AT32_HEXT_BYPASS)
  /* HEXT Bypass. */
  CRM->CTRL |= CRM_CTRL_HEXTEN | CRM_CTRL_HEXTBYPS;
#endif
  /* HEXT activation. */
  CRM->CTRL |= CRM_CTRL_HEXTEN;
  while (!(CRM->CTRL & CRM_CTRL_HEXTSTBL))
    ;                                       /* Waits until HEXT is stable.    */
#endif

#if AT32_LICK_ENABLED
  /* LICK activation. */
  CRM->CTRLSTS |= CRM_CTRLSTS_LICKEN;
  while ((CRM->CTRLSTS & CRM_CTRLSTS_LICKSTBL) == 0)
    ;                                       /* Waits until LICK is stable.    */
#endif

#if AT32_ACTIVATE_PLL
  /* PLL activation. */
#if (AT32_PLLCFGEN == AT32_PLLCFGEN_SOLID)
  /* Solid PLL config. */
  CRM->CFG |= AT32_PLLMULT | AT32_PLLHEXTDIV | AT32_PLLRCS;
#ifdef AT32_PLLCLKREF
  CRM->PLL |= AT32_PLLCLKREF;
#endif
#else
  /* Flexible PLL config. */
  CRM->CFG |= AT32_PLLHEXTDIV | AT32_PLLRCS;
  CRM->PLL  = AT32_PLL_FR | AT32_PLL_MS | AT32_PLL_NS | AT32_PLLCFGEN;
#endif

  CRM->CTRL |= CRM_CTRL_PLLEN;
  while (!(CRM->CTRL & CRM_CTRL_PLLSTBL))
    ;                                       /* Waits until PLL is stable.     */
#endif

  /* Clock settings.*/
#if AT32_HAS_OTG1
  CRM->CFG   |= (AT32_CLKOUT_SEL & AT32_CLKOUT_SEL_CFG_MSK) | AT32_USBDIV  | AT32_ADCDIV |
                AT32_APB2DIV                                | AT32_APB1DIV | AT32_AHBDIV;
#else
  CRM->CFG   |= (AT32_CLKOUT_SEL & AT32_CLKOUT_SEL_CFG_MSK) |                AT32_ADCDIV |
                AT32_APB2DIV                                | AT32_APB1DIV | AT32_AHBDIV;
#endif
  CRM->MISC1 |= (AT32_CLKOUT_SEL & AT32_CLKOUT_SEL_MISC_MSK) >> 11;

  /* PLL Auto Step activation. */
  CRM->MISC2 |= CRM_MISC2_AUTO_STEP_EN;

  /* Switching to the configured clock source if it is different from HICK. */
#if (AT32_SCLKSEL != AT32_SCLKSEL_HICK)
  /* Switches clock source. */
  CRM->CFG |= AT32_SCLKSEL;
  while ((CRM->CFG & CRM_CFG_SCLKSTS) != (AT32_SCLKSEL << 2))
    ;                                       /* Waits selection complete.      */
#endif

  /* PLL Auto Step inactivation. */
  CRM->MISC2 &= ~CRM_MISC2_AUTO_STEP_EN;

#if !AT32_HICK_ENABLED
  CRM->CTRL &= ~CRM_CTRL_HICKEN;
#endif
#endif /* !AT32_NO_INIT */
}
/** @} */
