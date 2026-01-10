/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2026 HorrorTroll
    ChibiOS - Copyright (C) 2023..2026 Zhaqian
    ChibiOS - Copyright (C) 2024..2026 Maxjta

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
 * @file    AT32F402_405/hal_lld.c
 * @brief   AT32F402_405 HAL subsystem low level driver source.
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
 * @note    It is declared in system_at32f402_405.h.
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

  /* Battery powered domain access enabled and left open.*/
  PWC->CTRL |= PWC_CTRL_BPWEN;

  /* Reset BPR domain if different clock source selected.*/
  if ((CRM->BPDC & AT32_ERTCSEL_MASK) != AT32_ERTCSEL) {
    /* Battery powered domain reset.*/
    CRM->BPDC = CRM_BPDC_BPDRST;

    /* Errata 1.2.1: Read/write ERTC occupies APB1 for 15 ERTC clock cycles
       (one more clock cycle at the end for stable).*/
    {
      __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
      __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    }

    CRM->BPDC = 0;
  }

#if AT32_LEXT_ENABLED
#if defined(AT32_LEXT_BYPASS)
  /* LEXT Bypass.*/
  CRM->BPDC |= CRM_BPDC_LEXTEN | CRM_BPDC_LEXTBYPS;
#else
  /* No LEXT Bypass.*/
  CRM->BPDC |= CRM_BPDC_LEXTEN;
#endif
  while ((CRM->BPDC & CRM_BPDC_LEXTSTBL) == 0)
    ;                                       /* Waits until LEXT is stable.   */
#endif

#if HAL_USE_RTC
  /* If the battery powered domain hasn't been initialized yet then proceed
     with initialization.*/
  if ((CRM->BPDC & CRM_BPDC_ERTCEN) == 0) {
    /* Selects clock source.*/
    CRM->BPDC |= AT32_ERTCSEL;

    /* ERTC clock enabled.*/
    CRM->BPDC |= CRM_BPDC_ERTCEN;
  }
#endif /* HAL_USE_RTC */
}

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

  /* Reset of all peripherals. AHB3 is not reseted because it could have
     been initialized in the board initialization file (board.c).
     Note, GPIOs are not reset because initialized before this point in
     board files.*/
  crmResetAHB1(~AT32_GPIO_EN_MASK);
  crmResetAHB2(~0);
  crmResetAPB1(~CRM_APB1RST_PWCRST);
  crmResetAPB2(~0);

  /* Initializes the battery powered domain.*/
  hal_lld_battery_powered_domain_init();

  /* DMA subsystems initialization.*/
#if defined(AT32_DMA_REQUIRED)
  dmaInit();
#endif

  /* IRQ subsystem initialization.*/
  irqInit();

  /* Power voltage monitoring enable.*/
#if AT32_PVM_ENABLE
  PWC->CTRL |= PWC_CTRL_PVMEN | (AT32_PVMSEL & AT32_PVMSEL_MASK);
#endif /* AT32_PVM_ENABLE */
}

/*
 * HICK divider selection for all series.
 */
static void at32_hick_divider(uint32_t div)
{
  volatile uint32_t misc1 = CRM->MISC1;
  volatile uint32_t misc2 = CRM->MISC2;

  CRM->MISC2 &= ~AT32_HICK_TO_SCLK_DIV_MASK;
  CRM->MISC2 |= AT32_HICK_TO_SCLK_DIV_DIV16;

  /* Delay.*/
  {
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
  }

  CRM->MISC1 = (AT32_HICK_TO_SCLK_48M | div);
  CRM->MISC1 &= ~AT32_HICK_TO_SCLK_MASK;
  CRM->MISC1 |= (misc1 & AT32_HICK_TO_SCLK_MASK);

  CRM->MISC2 &= ~AT32_HICK_TO_SCLK_DIV_MASK;
  CRM->MISC2 |= (misc2 & AT32_HICK_TO_SCLK_DIV_MASK);
}

/*
 * HICK to SCLK selection for all series.
 */
static void at32_hick_to_sclk(uint32_t value)
{
  volatile uint32_t misc1 = CRM->MISC1;
  volatile uint32_t misc2 = CRM->MISC2;

  CRM->MISC2 &= ~AT32_HICK_TO_SCLK_DIV_MASK;
  CRM->MISC2 |= AT32_HICK_TO_SCLK_DIV_DIV16;

  /* Delay.*/
  {
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
  }

  CRM->MISC1 = (AT32_HICK_TO_SCLK_48M | (misc1 & AT32_HICKDIV_MASK));
  CRM->MISC1 &= ~AT32_HICK_TO_SCLK_MASK;
  CRM->MISC1 |= value;

  CRM->MISC2 &= ~AT32_HICK_TO_SCLK_DIV_MASK;
  CRM->MISC2 |= (misc2 & AT32_HICK_TO_SCLK_DIV_MASK);
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
  /* PWC activation.*/
  CRM->APB1EN |= CRM_APB1EN_PWCEN;

  /* PWC initialization.*/
  PWC->LDOOV = AT32_LDOOVSEL;

  /* HICK setup, it enforces the reset situation in order to handle possible
     problems with JTAG probes and re-initializations.*/
  CRM->CTRL |= CRM_CTRL_HICKEN;             /* Make sure HICK is ON.          */
  while (!(CRM->CTRL & CRM_CTRL_HICKSTBL))
    ;                                       /* Wait until HICK is stable.     */
  at32_hick_divider(AT32_HICKDIV);          /* HICK divider.                  */
  at32_hick_to_sclk(AT32_HICK_TO_SCLK);     /* HICK sending to SCLK.          */
  CRM->MISC2 |= AT32_HICK_TO_SCLK_DIV;      /* Divider when sending to SCLK.  */

  /* HICK is selected as new source without touching the other fields in
     CFGR. Clearing the register has to be postponed after HICK is the
     new source.*/
  CRM->CFG &= ~CRM_CFG_SCLKSEL;             /* Reset SCLKSEL, selecting HICK. */
  while ((CRM->CFG & CRM_CFG_SCLKSTS) != CRM_CFG_SCLKSTS_HICK)
    ;                                       /* Waits until HICK is selected.  */

  /* Registers finally cleared to reset values.*/
  CRM->CTRL &= ~(0x010D0000);               /* CTRL reset value.              */
  CRM->CFG = (0x40000000);                  /* CFG reset value.               */
  CRM->PLLCFG = 0x000007C1;                 /* PLLCFG reset value.            */
  CRM->MISC1 &= 0x00005000;                 /* MISC1 reset value.             */
  CRM->MISC1 |= 0x000F0000;
  CRM->CLKINT = 0x009F0000;                 /* CLKINT reset value.            */

  /* Flash setup and final clock selection.*/
  FLASH->PSR = AT32_FLASHBITS;        /* Flash wait states depending on clock.*/
  while ((FLASH->PSR & FLASH_PSR_WTCYC_Msk) !=
         (AT32_FLASHBITS & FLASH_PSR_WTCYC_Msk)) {
  }

#if AT32_HEXT_ENABLED
#if defined(AT32_HEXT_BYPASS)
  /* HEXT Bypass.*/
  CRM->CTRL |= CRM_CTRL_HEXTEN | CRM_CTRL_HEXTBYPS;
#endif
  /* HEXT activation.*/
  CRM->CTRL |= CRM_CTRL_HEXTEN;
  while (!(CRM->CTRL & CRM_CTRL_HEXTSTBL))
    ;                                       /* Waits until HEXT is stable.    */
#endif

#if AT32_LICK_ENABLED
  /* LICK activation.*/
  CRM->CTRLSTS |= CRM_CTRLSTS_LICKEN;
  while ((CRM->CTRLSTS & CRM_CTRLSTS_LICKSTBL) == 0)
    ;                                       /* Waits until LICK is stable.    */
#endif

#if AT32_ACTIVATE_PLL
  /* PLL activation.*/
#if AT32_PLLRCS == AT32_PLLRCS_HICK
  at32_hick_divider(AT32_HICKDIV_DIV1);
#endif
  CRM->PLLCFG = AT32_PLL_MS | AT32_PLL_NS | AT32_PLL_FP | AT32_PLL_FU |
                AT32_PLLRCS;
  CRM->CTRL |= CRM_CTRL_PLLEN;
  while (!(CRM->CTRL & CRM_CTRL_PLLSTBL))
    ;                                       /* Waits until PLL is stable.     */
#if AT32_PLLU_ENABLED
  CRM->PLLCFG |= CRM_PLLCFG_PLLU_EN;
  while (!(CRM->CTRL & CRM_CTRL_PLLUSTBL))
    ;                                       /* Waits until PLLU is stable.    */
#endif
#endif

  /* Clock settings.*/
  CRM->CFG   |= (AT32_CLKOUT_SEL & AT32_CLKOUT_SEL_CFG_MASK) | AT32_APB2DIV     |
                 AT32_APB1DIV                                | AT32_AHBDIV      |
                 AT32_ERTCDIV                                | AT32_I2SF5CLKSEL |
                 AT32_CLKOUTDIV1;
  CRM->MISC1 |= (AT32_CLKOUT_SEL & AT32_CLKOUT_SEL_MISC1_MASK) | AT32_CLKOUTDIV2;

  /* PLL auto step activation.*/
  CRM->MISC2 |= CRM_MISC2_AUTO_STEP_EN;

  /* Switching to the configured clock source if it is different from HICK.*/
#if AT32_SCLKSEL != AT32_SCLKSEL_HICK
#if AT32_SCLKSEL == AT32_SCLKSEL_HEXT
  CRM->MISC2 |= AT32_HEXT_TO_SCLK_DIV;
#endif
  /* Switches clock source.*/
  CRM->CFG |= AT32_SCLKSEL;
  while ((CRM->CFG & CRM_CFG_SCLKSTS) != (AT32_SCLKSEL << 2))
    ;                                       /* Waits selection complete.      */
#endif

  /* PLL auto step inactivation.*/
  CRM->MISC2 &= ~CRM_MISC2_AUTO_STEP_EN;

#if !AT32_HICK_ENABLED
  CRM->CTRL &= ~CRM_CTRL_HICKEN;
#endif

#if AT32_PLLU_USB48_SEL == AT32_PLLU_USB48_SEL_HICK
  at32_hick_divider(AT32_HICKDIV_DIV1);
  at32_hick_to_sclk(AT32_HICK_TO_SCLK_48M);
#endif
  CRM->MISC2 &= ~AT32_PLLU_USB48_SEL_MASK;
  CRM->MISC2 |= AT32_PLLU_USB48_SEL;

#endif /* !AT32_NO_INIT */

  /* SYSCFG clock enabled here because it is a multi-functional unit shared
     among multiple drivers.*/
  crmEnableAPB2(CRM_APB2EN_SCFGEN, true);
}

#if HAL_USE_USB
/*
 * Reduce power consumption initialize for all series using OTGFS.
 */
void at32_reduce_power_consumption(void) {
  volatile uint32_t delay = 0x34BC0;

  if (CRM->CTRL & CRM_CTRL_HEXTSTBL) {
    CRM->OTGHS = 0x00;
  } else if (CRM->CTRL & CRM_CTRL_PLLSTBL) {
    CRM->PLLCFG |= CRM_PLLCFG_PLLU_EN;
    while ((!(CRM->CTRL & CRM_CTRL_PLLSTBL)) || (!(CRM->CTRL & CRM_CTRL_PLLUSTBL)))
      ;
    CRM->OTGHS = 0x10;
  } else {
    /* PLL or HEXT need to be enable.*/
    return;
  }

  CRM->AHBEN1 |= CRM_AHBEN1_OTGHSEN;
  OTG_HS->GCCFG = GCCFG_PWRDOWN | GCCFG_VBUSIG;
  OTG_HS->GUSBCFG |= GUSBCFG_FDEVMODE;
  OTG_HS->DCTL &= ~DCTL_SFTDISCON;

  while (delay --) {
    if (OTG_HS->DSTS & DSTS_SUSPSTS) {
      break;
    }
  }

  OTG_HS->GCCFG |= GCCFG_WAIT_CLK_RCV;
  OTG_HS->PCGCCTL |= PCGCCTL_STOPPCLK;
  OTG_HS->GCCFG &= ~GCCFG_PWRDOWN;

  return;
}
#endif /* HAL_USE_USB */
/** @} */
