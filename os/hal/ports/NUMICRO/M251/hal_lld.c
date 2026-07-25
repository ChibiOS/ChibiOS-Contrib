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
 * @file    M251/hal_lld.c
 * @brief   M251/M252 HAL subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "hal.h"

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

static bool clock_initialized = false;
static uint32_t protected_depth = 0U;
static bool protected_relock = false;

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   System core clock frequency.
 */
uint32_t SystemCoreClock = __HIRC;

/**
 * @brief   Number of system core clock cycles per microsecond.
 */
uint32_t CyclesPerUs = (__HIRC / 1000000UL);

/**
 * @brief   PLL output clock frequency.
 */
uint32_t PllClock = 0U;

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static bool wait_for_clock_ready(uint32_t mask) {
  uint32_t timeout = 0x100000U;

  while (timeout-- > 0U) {
    if ((CLK->STATUS & mask) == mask) {
      return true;
    }
  }

  return false;
}

static uint32_t _get_pll_freq(void) {
  uint32_t pllctl = CLK->PLLCTL;
  uint32_t nf = (pllctl & CLK_PLLCTL_FBDIV_Msk) >> CLK_PLLCTL_FBDIV_Pos;
  uint32_t nr = (pllctl & CLK_PLLCTL_INDIV_Msk) >> CLK_PLLCTL_INDIV_Pos;
  uint32_t no_code = (pllctl & CLK_PLLCTL_OUTDIV_Msk) >>
                     CLK_PLLCTL_OUTDIV_Pos;
  uint32_t no = (no_code == 0U) ? 1U : (no_code == 1U) ? 2U : 4U;
  uint32_t fin;

  if ((pllctl & (CLK_PLLCTL_PD_Msk | CLK_PLLCTL_OE_Msk)) != 0U) {
    return 0U;
  }

  switch ((pllctl & CLK_PLLCTL_PLLSRC_Msk) >> CLK_PLLCTL_PLLSRC_Pos) {
  case 0U:
    fin = M251_HXT_CLK;
    break;
  case 1U:
    fin = __HIRC / 4U;
    break;
  default:
    fin = __MIRC;
    break;
  }

  if ((pllctl & CLK_PLLCTL_BP_Msk) != 0U) {
    return fin;
  }

  if ((nf == 0U) || (nr == 0U)) {
    return 0U;
  }

  return fin / nr * nf / no;
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Unlocks the protected system registers.
 * @details Nested unlock requests are supported and the previous lock state
 *          is preserved.
 *
 * @notapi
 */
void m251_lld_unlock(void) {
  uint32_t primask = __get_PRIMASK();

  __disable_irq();

  if (protected_depth == 0U) {
    protected_relock = (SYS->REGLCTL & 1U) == 0U;

    if (protected_relock) {
      do {
        SYS->REGLCTL = 0x59UL;
        SYS->REGLCTL = 0x16UL;
        SYS->REGLCTL = 0x88UL;
      } while (SYS->REGLCTL == 0UL);
    }
  }

  protected_depth++;

  if (primask == 0U) {
    __enable_irq();
  }
}

/**
 * @brief   Completes a protected system register access.
 * @details The registers are locked again after the outermost matching call
 *          if they were locked before @p m251_lld_unlock().
 *
 * @notapi
 */
void m251_lld_lock(void) {
  uint32_t primask = __get_PRIMASK();

  __disable_irq();

  osalDbgAssert(protected_depth > 0U, "unbalanced protected-register lock");

  protected_depth--;

  if ((protected_depth == 0U) && protected_relock) {
    SYS->REGLCTL = 0UL;
    protected_relock = false;
  }

  if (primask == 0U) {
    __enable_irq();
  }
}

/**
 * @brief   Performs a full chip reset.
 *
 * @notapi
 */
void m251_lld_chip_reset(void) {

  m251_lld_unlock();
  SYS->IPRST0 |= SYS_IPRST0_CHIPRST_Msk;
  while (true) {
  }
}

/**
 * @brief   Updates the system clock variables from the hardware registers.
 *
 * @notapi
 */
void SystemCoreClockUpdate(void) {
  uint32_t div;

  PllClock = _get_pll_freq();

  switch (CLK->CLKSEL0 & CLK_CLKSEL0_HCLKSEL_Msk) {
  case 0U:
    SystemCoreClock = M251_HXT_CLK;
    break;
  case 2U:
    SystemCoreClock = PllClock;
    break;
  case 3U:
    SystemCoreClock = __LIRC;
    break;
  case 5U:
    SystemCoreClock = __MIRC;
    break;
  case 7U:
    SystemCoreClock = __HIRC;
    break;
  default:
    SystemCoreClock = M251_HCLK;
    break;
  }

  div = ((CLK->CLKDIV0 & CLK_CLKDIV0_HCLKDIV_Msk) >> CLK_CLKDIV0_HCLKDIV_Pos)
        + 1U;
  SystemCoreClock /= div;
  CyclesPerUs = SystemCoreClock / 1000000UL;
}

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void) {

  if (!clock_initialized) {
    M251_clock_init();
  }
}

/**
 * @brief   Initializes the M251/M252 clock tree.
 *
 * @init
 */
void M251_clock_init(void) {
  uint32_t clksel0;
  uint32_t clkdiv0;

  if (M251_NO_INIT == TRUE) {
    SystemCoreClockUpdate();
    clock_initialized = true;
    return;
  }

  m251_lld_unlock();

  /* Enable HIRC first, safe clock source during transitions.*/
  CLK->PWRCTL |= CLK_PWRCTL_HIRCEN_Msk;
  if (!wait_for_clock_ready(CLK_STATUS_HIRCSTB_Msk)) {
    osalSysHalt("HIRC clock not stable");
  }

  /* Match the BSP SystemInit setting before raising HCLK to 48 MHz.*/
  FMC->CYCCTL = (FMC->CYCCTL & ~FMC_CYCCTL_CYCLE_Msk)
                | (3UL << FMC_CYCCTL_CYCLE_Pos) | 0x100UL;

  /* Ensure we are running on HIRC while configuring other sources.*/
  CLK->CLKSEL0 = (CLK->CLKSEL0 & ~CLK_CLKSEL0_HCLKSEL_Msk) | M251_HCLKSRC_HIRC;

  /* Set HCLK divider (safe while on HIRC).*/
  clkdiv0 = CLK->CLKDIV0 & ~CLK_CLKDIV0_HCLKDIV_Msk;
  clkdiv0 |= M251_CLKDIV0_HCLK(M251_HCLK_DIV);
  CLK->CLKDIV0 = clkdiv0;

  /* Optionally enables HXT.*/
#if M251_HXT_ENABLED == TRUE
  CLK->PWRCTL = (CLK->PWRCTL & ~CLK_PWRCTL_HXTGAIN_Msk)
                | ((uint32_t)M251_HXT_GAIN_VALUE << CLK_PWRCTL_HXTGAIN_Pos)
                | CLK_PWRCTL_HXTEN_Msk;
  if (!wait_for_clock_ready(CLK_STATUS_HXTSTB_Msk)) {
    osalSysHalt("HXT clock not stable");
  }
#endif

  /* Optionally enables PLL.*/
#if M251_PLL_ENABLED == TRUE
  CLK->PLLCTL = M251_PLLCTL_VAL;
  CLK->PLLCTL &= ~CLK_PLLCTL_PD_Msk;
  if (!wait_for_clock_ready(CLK_STATUS_PLLSTB_Msk)) {
    osalSysHalt("PLL clock not stable");
  }
#endif

  /* Switch HCLK to the configured source.*/
  clksel0 = CLK->CLKSEL0 & ~CLK_CLKSEL0_HCLKSEL_Msk;
  clksel0 |= (uint32_t)M251_HCLK_SRC;
  CLK->CLKSEL0 = clksel0;

  /* Configure USB clock.*/
  clksel0 = CLK->CLKSEL0 & ~CLK_CLKSEL0_USBDSEL_Msk;
  clksel0 |= (uint32_t)M251_USB_SRC;
  CLK->CLKSEL0 = clksel0;

  clkdiv0 = CLK->CLKDIV0 & ~CLK_CLKDIV0_USBDIV_Msk;
  clkdiv0 |= M251_CLKDIV0_USB(M251_USB_DIV);
  CLK->CLKDIV0 = clkdiv0;

  SystemCoreClockUpdate();

  m251_lld_lock();
  clock_initialized = true;
}

/** @} */
