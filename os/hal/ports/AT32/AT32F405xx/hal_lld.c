/*
    ChibiOS - Copyright (C) 2023..2024 Zhaqian
    ChibiOS - Copyright (C) 2024 Maxjta

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
 * @file    AT32F405xx/hal_lld.c
 * @brief   AT32F405xx HAL subsystem low level driver source.
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
 * @note    It is declared in system_at32f405xx.h.
 */
uint32_t SystemCoreClock = AT32_HCLK;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Initializes the backup domain.
 * @note    WARNING! Changing clock source impossible without resetting
 *          of the whole BKP domain.
 */
static void hal_lld_backup_domain_init(void) {

  /* Backup domain access enabled and left open.*/
  PWC->CTRL |= PWC_CTRL_BPWEN;
  
  /* Reset BKP domain if different clock source selected.*/
  if ((CRM->BPDC & AT32_ERTCSEL_MASK) != AT32_ERTCSEL) {
    /* Backup domain reset.*/
    CRM->BPDC = CRM_BPDC_BPDRST;
    CRM->BPDC = 0;
  }

  /* If enabled then the LEXT is started.*/
#if AT32_LEXT_ENABLED
#if defined(AT32_LEXT_BYPASS)
  /* LEXT Bypass.*/
  CRM->BPDC |= CRM_BPDC_LEXTEN | CRM_BPDC_LEXTBYPS;
#else
  /* No LEXT Bypass.*/
  CRM->BPDC |= CRM_BPDC_LEXTEN;
#endif
  while ((CRM->BPDC & CRM_BPDC_LEXTSTBL) == 0);  /* Waits until LEXT is stable.   */
#endif /* AT32_LEXT_ENABLED */

#if AT32_ERTCSEL != AT32_ERTCSEL_NOCLOCK
  /* If the backup domain hasn't been initialized yet then proceed with
     initialization.*/
  if ((CRM->BPDC & CRM_BPDC_ERTCEN) == 0) {
    /* Selects clock source.*/
    CRM->BPDC |= AT32_ERTCSEL;

    /* ERTC clock enabled.*/
    CRM->BPDC |= CRM_BPDC_ERTCEN;
  }
#endif /* AT32_ERTCSEL != AT32_ERTCSEL_NOCLOCK */
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

  /* Initializes the backup domain.*/
  hal_lld_backup_domain_init();

  /* DMA subsystems initialization.*/
#if defined(AT32_DMA_REQUIRED)
  dmaInit();
#endif

  /* IRQ subsystem initialization.*/
  irqInit();

  /* Programmable voltage detector enable.*/
#if AT32_PVM_ENABLE
  PWC->CTRL |= PWC_CTRL_PVMEN | (AT32_PVM & AT32_PVMSEL_MASK);
#endif /* AT32_PVM_ENABLE */
}

/*
 * hick divider selection for all sub-families.
 */
static void at32_hick_divider_select(uint32_t div)
{
  volatile uint32_t misc1 = CRM->MISC1;
  volatile uint32_t misc2 = CRM->MISC2;

  CRM->MISC2 &= ~AT32_HICK_TO_SCLK_DIV_MASK;
  CRM->MISC2 |= AT32_HICK_TO_SCLK_DIV_DIV16;
  /* delay */
  {
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
  }

  CRM->MISC1 = (AT32_HICK_TO_SCLK_HICKOUT | div);
  CRM->MISC1 &= ~AT32_HICK_TO_SCLK_MASK;
  CRM->MISC1 |= (misc1 & AT32_HICK_TO_SCLK_MASK);
  
  CRM->MISC2 &= ~AT32_HICK_TO_SCLK_DIV_MASK;
  CRM->MISC2 |= (misc2 & AT32_HICK_TO_SCLK_DIV_MASK);
}

/* 
 * hick as system clock frequency selection for all sub-families.
 */
static void at32_hick_frequency_select(uint32_t value)
{
  volatile uint32_t misc1 = CRM->MISC1;
  volatile uint32_t misc2 = CRM->MISC2;

  CRM->MISC2 &= ~AT32_HICK_TO_SCLK_DIV_MASK;
  CRM->MISC2 |= AT32_HICK_TO_SCLK_DIV_DIV16;
  /* delay */
  {
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
    __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
  }
  
  CRM->MISC1 = (AT32_HICK_TO_SCLK_HICKOUT | (misc1 & AT32_HICKDIV_MASK));
  CRM->MISC1 &= ~AT32_HICK_TO_SCLK_MASK;
  CRM->MISC1 |= value;

  CRM->MISC2 &= ~AT32_HICK_TO_SCLK_DIV_MASK;
  CRM->MISC2 |= (misc2 & AT32_HICK_TO_SCLK_DIV_MASK);
}

/*
 * Clocks deinitialization for all sub-families.
 */
void at32_clock_reset(void)
{
  /* reset cfg register, include sclk switch, ahbdiv, apb1div, apb2div, adcdiv, clkout bits */
  CRM->CFG = (0x40000000U);

  /* reset hexten, hextbyps, cfden and pllen bits */
  CRM->CTRL &= ~(0x010D0000U);

  /* reset pllms pllns pllfr pllrcs bits */
  CRM->PLLCFG = 0x000007C1U;

  /* reset clkout_sel, clkoutdiv, pllclk_to_adc, hick_to_usb */
  CRM->MISC1 &= 0x00005000U;
  CRM->MISC1 |= 0x000F0000U;
  
  /* disable all interrupts enable and clear pending bits  */
  CRM->CLKINT = 0x009F0000;
}

/*
 * Clocks initialization for all sub-families.
 */
void at32_clock_init(void) {
#if !AT32_NO_INIT
  /* HICK setup, it enforces the reset situation in order to handle possible
     problems with JTAG probes and re-initializations.*/

  /* clock reset. */
  at32_clock_reset();

  CRM->MISC2 |= CRM_MISC2_AUTO_STEP_EN;

  CRM->CTRL |= CRM_CTRL_HICKEN;                                 /* Make sure HICK is ON.        */
  while((CRM->CTRL & CRM_CTRL_HICKSTBL) == 0);                  /* Wait until HICK is stable.   */

  CRM->CTRL &= CRM_CTRL_HICKTRIM | CRM_CTRL_HICKEN;             /* CTRL Reset value.            */

  at32_hick_divider_select(AT32_HICKDIV);
  at32_hick_frequency_select(AT32_HICK_TO_SCLK);
  CRM->MISC2 |= AT32_HICK_TO_SCLK_DIV;
  CRM->CFG  |= CRM_CFG_SCLK_HICK;                               /* CFG reset value.             */
  while ((CRM->CFG & CRM_CFG_SCLKSTS) != CRM_CFG_SCLKSTS_HICK); /* Waits until HICK is selected.*/

  CRM->MISC2 &= ~CRM_MISC2_AUTO_STEP_EN;

  /* Flash setup and final clock selection.*/
  FLASH->PSR = AT32_FLASHBITS;
  CRM->APB1EN |= CRM_APB1EN_PWCEN;

  /* PWR initialization.*/
  PWC->LDOOV = AT32_LDOOVSEL;

#if AT32_HEXT_ENABLED
  /* HEXT activation.*/
#if defined(AT32_HEXT_BYPASS)
  /* HEXT Bypass.*/
  CRM->CTRL |= CRM_CTRL_HEXTEN | CRM_CTRL_HEXTBYPS;
#else
  /* No HEXT Bypass.*/
  CRM->CTRL |= CRM_CTRL_HEXTEN;
#endif
  while (!(CRM->CTRL & CRM_CTRL_HEXTSTBL));           /* Waits until HEXT is stable.   */
#endif

#if AT32_LICK_ENABLED
  /* LICK activation.*/
  CRM->CTRLSTS |= CRM_CTRLSTS_LICKEN;
  while ((CRM->CTRLSTS & CRM_CTRLSTS_LICKSTBL) == 0); /* Waits until LICK is stable.   */
#endif

#if AT32_ACTIVATE_PLL
  /* PLL activation.*/
#if AT32_PLLRCS == AT32_PLLRCS_HICK
  at32_hick_divider_select(AT32_HICKDIV_DIV1);
#endif
  CRM->PLLCFG = AT32_PLL_MS | AT32_PLL_NS | AT32_PLL_FP | AT32_PLL_FU |
                AT32_PLLRCS;
  CRM->CTRL |= CRM_CTRL_PLLEN;
  while (!(CRM->CTRL & CRM_CTRL_PLLSTBL));       /* Waits until PLL is stable.   */
#if AT32_PLLU_ENABLED
  CRM->PLLCFG |= CRM_PLLCFG_PLLUEN;
  while (!(CRM->CTRL & CRM_CTRL_PLLUSTBL));      /* Waits until PLLU is stable.   */
#endif
#endif

  /* Clock settings.*/
  CRM->CFG   |= (AT32_CLKOUT_SEL & AT32_CLKOUT_SEL_CFG_MASK) | AT32_APB2DIV     | 
                 AT32_APB1DIV | AT32_AHBDIV | AT32_ETRCDIV   | AT32_I2SF5CLKSEL |
                 AT32_CLKOUTDIV1;
  CRM->MISC1 |= (AT32_CLKOUT_SEL & AT32_CLKOUT_SEL_MISC1_MASK) | AT32_CLKOUTDIV2;

  /* PLL Auto Step activation.*/
  CRM->MISC2 |= CRM_MISC2_AUTO_STEP_EN;
  
  /* Switching to the configured clock source if it is different from HICK.*/
#if AT32_SCLKSEL != AT32_SCLKSEL_HICK
#if AT32_SCLKSEL == AT32_SCLKSEL_HEXT
  CRM->MISC2 |= AT32_HEXT_TO_SCLK_DIV;
#endif
  /* Switches clock source.*/
  CRM->CFG |= AT32_SCLKSEL;
  while ((CRM->CFG & CRM_CFG_SCLKSTS) != (AT32_SCLKSEL << 2)); /* Waits selection complete.    */
#endif

  /* PLL Auto Step inactivation.*/
  CRM->MISC2 &= ~CRM_MISC2_AUTO_STEP_EN;
  
#if !AT32_HICK_ENABLED
  CRM->CTRL &= ~CRM_CTRL_HICKEN;
#endif

#if AT32_PLLU_USB48_SEL == AT32_PLLU_USB48_SEL_HICK
  at32_hick_divider_select(AT32_HICKDIV_DIV1);
  at32_hick_frequency_select(AT32_HICK_TO_SCLK_HICKOUT);
#endif
  CRM->MISC2 &= ~AT32_PLLU_USB48_SEL_MASK;
  CRM->MISC2 |= AT32_PLLU_USB48_SEL;

#if AT32_SYSTICK_CLKSRC == AT32_SYSTICK_CLKSRC_HCLKDIV1
  SysTick->CTRL |= AT32_SYSTICK_CLKSRC_HCLKDIV1;
#else
  SysTick->CTRL &= ~AT32_SYSTICK_CLKSRC_HCLKDIV1;
#endif 

#endif /* !AT32_NO_INIT */

  /* SYSCFG clock enabled here because it is a multi-functional unit shared
     among multiple drivers.*/
  CRM->APB2EN |= CRM_APB2EN_SCFGEN;
  CRM->APB2LPEN |= CRM_APB2LPEN_SCFGLPEN;
}

/** @} */
