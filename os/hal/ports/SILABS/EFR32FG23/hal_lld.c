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
 * @file    hal_lld.c
 * @brief   PLATFORM HAL subsystem low level driver source.
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
 * @note    It is declared in system_efr32fg23.h.
 */
uint32_t SystemCoreClock = EFR32_HCLK;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

__STATIC_INLINE void efr32_calibrate_lfxo(void) {

  uint32_t gain_cal_value, captune_cal_value;
  uint32_t gain, captune;

  efr32_get_lfxo_calibration_values(&gain_cal_value, &captune_cal_value);

  gain = (LFXO->CAL & _LFXO_CAL_GAIN_MASK) >> _LFXO_CAL_GAIN_SHIFT;
  if (gain != gain_cal_value) {
    while ((LFXO->SYNCBUSY & _LFXO_SYNCBUSY_CAL_MASK) == LFXO_SYNCBUSY_CAL);
    LFXO->CAL = (LFXO->CAL & ~_LFXO_CAL_GAIN_MASK) |
                ((gain_cal_value & _LFXO_CAL_GAIN_MASK) << _LFXO_CAL_GAIN_SHIFT);
    while ((LFXO->SYNCBUSY & _LFXO_SYNCBUSY_CAL_MASK) != 0U);
  }

  while (true)
  {
    captune = (LFXO->CAL & _LFXO_CAL_CAPTUNE_MASK) >> _LFXO_CAL_CAPTUNE_SHIFT;

    if (captune > captune_cal_value) {
      --captune;
    }
    else if (captune < captune_cal_value) {
      ++captune;
    }
    else {
      break;
    }

    while ((LFXO->SYNCBUSY & _LFXO_SYNCBUSY_CAL_MASK) == LFXO_SYNCBUSY_CAL);
    LFXO->CAL = (LFXO->CAL & ~_LFXO_CAL_CAPTUNE_MASK) |
                ((captune & _LFXO_CAL_CAPTUNE_MASK) << _LFXO_CAL_CAPTUNE_SHIFT);
    while ((LFXO->SYNCBUSY & _LFXO_SYNCBUSY_CAL_MASK) == LFXO_SYNCBUSY_CAL);
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   EFR32FG23 chip and errata initialization.
 * @note    All the involved constants come from the file @p board.h.
 * @note    This function should be invoked just after the system reset.
 *
 * @special
 */

void efr32_chip_init(void) {

}

__STATIC_INLINE void efr32_enable_clock_sources(void) {

#if defined(EFR32_CMU_SYSCLKCTRL)
  CMU->SYSCLKCTRL = (CMU->SYSCLKCTRL & ~_CMU_SYSCLKCTRL_MASK) | EFR32_CMU_SYSCLKCTRL;
  //CMU->SYSCLKCTRL = (CMU->SYSCLKCTRL & ~_CMU_SYSCLKCTRL_HCLKPRESC_MASK) | EFR32_HPRE;
  //CMU->SYSCLKCTRL = (CMU->SYSCLKCTRL & ~_CMU_SYSCLKCTRL_CLKSEL_MASK) | EFR32_SYSCLKSEL;
#endif

#if EFR32_LFXO_ENABLED
  CMU->CLKEN0_SET = CMU_CLKEN0_LFXO;
  LFXO->CTRL_SET = LFXO_CTRL_FORCEEN;
  while ((LFXO->STATUS & (_LFXO_STATUS_RDY_MASK | _LFXO_STATUS_ENS_MASK)) !=
         (LFXO_STATUS_RDY | LFXO_STATUS_ENS));
  efr32_calibrate_lfxo();
#else
  CMU->CLKEN0_CLR = CMU_CLKEN0_LFXO;
#endif

#if EFR32_HFXO_ENABLED
  CMU->CLKEN0_SET = CMU_CLKEN0_HFXO0;
  HFXO0->CTRL |= HFXO_CTRL_FORCEEN;
#else
  CMU->CLKEN0_CLR = CMU_CLKEN0_HFXO0;
#endif

#if EFR32_LFRCO_ENABLED
  CMU->CLKEN0_SET = CMU_CLKEN0_LFRCO;
#else
  CMU->CLKEN0_CLR = CMU_CLKEN0_LFRCO;
#endif

#if EFR32_ULFRCO_ENABLED
  CMU->CLKEN0_SET = CMU_CLKEN0_ULFRCO;
#else
  CMU->CLKEN0_CLR = CMU_CLKEN0_ULFRCO;
#endif

#if EFR32_HFRCOEM23_ENABLED
  CMU->CLKEN0_SET = CMU_CLKEN0_HFRCOEM23;
  HFRCOEM23->CTRL_SET = HFRCO_CTRL_FORCEEN;
  while ((HFRCOEM23->STATUS & _HFRCO_STATUS_RDY_MASK) != HFRCO_STATUS_RDY);
#else
  CMU->CLKEN0_CLR = CMU_CLKEN0_HFRCOEM23;
#endif

#if EFR32_FSRCO_ENABLED
  CMU->CLKEN0_SET = CMU_CLKEN0_FSRCO;
#else
  CMU->CLKEN0_CLR = CMU_CLKEN0_FSRCO;
#endif

}

__STATIC_INLINE void efr32_enable_em01grpaclk(void) {

#if EFR32_EM01GRPACLKSEL != EFR32_EM01GRPACLKSEL_NOCLOCK
#if EFR32_FSRCO_ENABLED && (EFR32_EM01GRPACLKSEL == EFR32_EM01GRPACLKSEL_FSRCO)
  CMU->EM01GRPACLKCTRL = (CMU->EM01GRPACLKCTRL & ~_CMU_EM01GRPACLKCTRL_CLKSEL_MASK) |
                         CMU_EM01GRPACLKCTRL_CLKSEL_FSRCO;
#elif EFR32_HFRCODPLL_ENABLED && (EFR32_EM01GRPACLKSEL == EFR32_EM01GRPACLKSEL_HFRCODPLL)
  CMU->EM01GRPACLKCTRL = (CMU->EM01GRPACLKCTRL & ~_CMU_EM01GRPACLKCTRL_CLKSEL_MASK) |
                         CMU_EM01GRPACLKCTRL_CLKSEL_HFRCODPLL;
#elif EFR32_HFXO_ENABLED && (EFR32_EM01GRPACLKSEL == EFR32_EM01GRPACLKSEL_HFXO)
  CMU->EM01GRPACLKCTRL = (CMU->EM01GRPACLKCTRL & ~_CMU_EM01GRPACLKCTRL_CLKSEL_MASK) |
                         CMU_EM01GRPACLKCTRL_CLKSEL_HFXO;
#else
#error "No clock source selected for EFR32_EM01GRPACLK"
#endif
#else
#warning "EFR32_EM01GRPACLK can't be disabled"
#endif
}

__STATIC_INLINE void efr32_enable_em01grpcclk(void) {

#if EFR32_EM01GRPCCLKSEL != EFR32_EM01GRPCCLKSEL_NOCLOCK
#if EFR32_FSRCO_ENABLED && (EFR32_EM01GRPCCLKSEL == EFR32_EM01GRPCCLKSEL_FSRCO)
  CMU->EM01GRPCCLKCTRL = (CMU->EM01GRPCCLKCTRL & ~_CMU_EM01GRPCCLKCTRL_CLKSEL_MASK) |
                         CMU_EM01GRPCCLKCTRL_CLKSEL_FSRCO;
#elif EFR32_HFRCODPLL_ENABLED && (EFR32_EM01GRPCCLKSEL == EFR32_EM01GRPCCLKSEL_HFRCODPLL)
  CMU->EM01GRPCCLKCTRL = (CMU->EM01GRPCCLKCTRL & ~_CMU_EM01GRPCCLKCTRL_CLKSEL_MASK) |
                         CMU_EM01GRPCCLKCTRL_CLKSEL_HFRCODPLL;
#elif EFR32_HFXO_ENABLED && (EFR32_EM01GRPCCLKSEL == EFR32_EM01GRPCCLKSEL_HFXO)
  CMU->EM01GRPCCLKCTRL = (CMU->EM01GRPCCLKCTRL & ~_CMU_EM01GRPCCLKCTRL_CLKSEL_MASK) |
                         CMU_EM01GRPCCLKCTRL_CLKSEL_HFXO;
#else
#error "No clock source selected for EFR32_EM01GRPCCLK"
#endif
#else
#warning "EFR32_EM01GRPCCLK can't be disabled"
#endif
}

__STATIC_INLINE void efr32_enable_em23grpaclk(void) {

#if EFR32_EM23GRPACLKSEL != EFR32_EM23GRPACLKSEL_NOCLOCK
#if EFR32_LFXO_ENABLED && (EFR32_EM23GRPACLKSEL == EFR32_EM23GRPACLKSEL_LFXO)
  CMU->EM23GRPACLKCTRL = (CMU->EM23GRPACLKCTRL & ~_CMU_EM23GRPACLKCTRL_CLKSEL_MASK) |
                         CMU_EM23GRPACLKCTRL_CLKSEL_LFXO;

#elif EFR32_LFRCO_ENABLED && (EFR32_EM23GRPACLKSEL == EFR32_EM23GRPACLKSEL_LFRCO)
  CMU->EM23GRPACLKCTRL = (CMU->EM23GRPACLKCTRL & ~_CMU_EM23GRPACLKCTRL_CLKSEL_MASK) |
                         CMU_EM23GRPACLKCTRL_CLKSEL_LFRCO;

#elif EFR32_ULFRCO_ENABLED && (EFR32_EM23GRPACLKSEL == EFR32_EM23GRPACLKSEL_ULFRCO)
  CMU->EM23GRPACLKCTRL = (CMU->EM23GRPACLKCTRL & ~_CMU_EM23GRPACLKCTRL_CLKSEL_MASK) |
                         CMU_EM23GRPACLKCTRL_CLKSEL_ULFRCO;
#else
#error "No clock source selected for EFR32_EM23GRPACLK"
#endif
#else
#warning "EFR32_EM23GRPACLK can't be disabled"
#endif
}

__STATIC_INLINE void efr32_enable_eusartclk(void) {

#if EFR32_EUSART1SEL != EFR32_EUSART1SEL_NOCLOCK
#if EFR32_LFRCO_ENABLED && EFR32_EUSART1SEL == EFR32_EUSART1SEL_LFRCO
  CMU->EUSART0CLKCTRL = (CMU->EUSART0CLKCTRL & ~_CMU_EUSART0CLKCTRL_CLKSEL_MASK)\
    | _CMU_EUSART0CLKCTRL_CLKSEL_LFRCO;
#elif EFR32_LFXO_ENABLED && EFR32_EUSART1SEL == EFR32_EUSART1SEL_LFXO
  CMU->EUSART0CLKCTRL = (CMU->EUSART0CLKCTRL & ~_CMU_EUSART0CLKCTRL_CLKSEL_MASK)\
    | _CMU_EUSART0CLKCTRL_CLKSEL_LFXO;
#elif EFR32_HFRCOEM23_ENABLED && EFR32_EUSART1SEL == EFR32_EUSART1SEL_HFRCOEM23
  CMU->EUSART0CLKCTRL = (CMU->EUSART0CLKCTRL & ~_CMU_EUSART0CLKCTRL_CLKSEL_MASK)\
    | CMU_EUSART0CLKCTRL_CLKSEL_HFRCOEM23;
#elif EFR32_HFRCODPLL_ENABLED && EFR32_EUSART1SEL == EFR32_EUSART1SEL_EM01GRPCCLK
  CMU->EUSART0CLKCTRL = (CMU->EUSART0CLKCTRL & ~_CMU_EUSART0CLKCTRL_CLKSEL_MASK)\
    | CMU_EUSART0CLKCTRL_CLKSEL_EM01GRPCCLK;
#else
#error "No clock source selected for EFR32_EUSART1SEL"
#endif
#else
  CMU->EUSART0CLKCTRL = (CMU->EUSART0CLKCTRL & ~_CMU_EUSART0CLKCTRL_CLKSEL_MASK)\
    | CMU_EUSART0CLKCTRL_CLKSEL_DISABLED;
#endif

#if EFR32_EUSART23SEL != EFR32_EUSART23SEL_NOCLOCK
#if EFR32_HFRCOEM23_ENABLED && EFR32_EUSART23SEL == EFR32_EUSART23SEL_HFRCOEM23
  CMU->EM01GRPCCLKCTRL = (CMU->EM01GRPCCLKCTRL & ~_CMU_EM01GRPCCLKCTRL_CLKSEL_MASK)\
    | _CMU_EM01GRPCCLKCTRL_CLKSEL_HFRCOEM23;
#elif EFR32_HFRCODPLL_ENABLED && EFR32_EUSART23SEL == EFR32_EUSART23SEL_HFRCODPLL
  CMU->EM01GRPCCLKCTRL = (CMU->EM01GRPCCLKCTRL & ~_CMU_EM01GRPCCLKCTRL_CLKSEL_MASK)\
    | _CMU_EM01GRPCCLKCTRL_CLKSEL_HFRCODPLL;
#elif EFR32_FSRCO_ENABLED && EFR32_EUSART23SEL == EFR32_EUSART23SEL_FSRCO
  CMU->EM01GRPCCLKCTRL = (CMU->EM01GRPCCLKCTRL & ~_CMU_EM01GRPCCLKCTRL_CLKSEL_MASK)\
    | _CMU_EM01GRPCCLKCTRL_CLKSEL_FSRCO;
#elif EFR32_HFXO_ENABLED && EFR32_EUSART23SEL == EFR32_EUSART23SEL_HFXO
  CMU->EM01GRPCCLKCTRL = (CMU->EM01GRPCCLKCTRL & ~_CMU_EM01GRPCCLKCTRL_CLKSEL_MASK)\
    | _CMU_EM01GRPCCLKCTRL_CLKSEL_HFXO;
#else
#error "No clock source selected for EFR32_EUSART23SEL"
#endif
#else
  CMU->EM01GRPCCLKCTRL = (CMU->EM01GRPCCLKCTRL & ~_CMU_EM01GRPCCLKCTRL_CLKSEL_MASK)\
    | CMU_EM01GRPCCLKCTRL_CLKSEL_DEFAULT;
#endif
}

void efr32_get_lfxo_calibration_values(uint32_t *gain, uint32_t *captune)
{
  osalDbgAssert(gain != NULL, "gain must be not NULL");
  osalDbgAssert(captune != NULL, "captune must be not NULL");

  *gain = LFXO_RTC_GAIN_DEFAULT_VALUE;
  *captune = LFXO_RTC_CAPTUNE_DEFAULT_VALUE;
}

/**
 * @brief   EFR32FG23 clocks initialization.
 * @note    All the involved constants come from the file @p board.h.
 * @note    This function should be invoked just after the system reset.
 *
 * @special
 */
void efr32_clock_init(void) {

  efr32_enable_clock_sources();
  efr32_enable_em01grpaclk();
  efr32_enable_em01grpcclk();
  efr32_enable_em23grpaclk();
  efr32_enable_eusartclk();
}

/**
 * @brief efr32_escape_hatch()
 * When developing or debugging code that enters EM2 or
 * lower, it's a good idea to have an "escape hatch" type
 * mechanism, e.g. a way to pause the device so that a debugger can
 * connect in order to erase flash, among other things.
 *
 * Before proceeding with this example, make sure ESCAPE_HATCH_PAD is not
 * grounded. If the ESCAPE_HATCH_PIN pin is low, execute the breakpoint instruction
 * to stop the processor in EM0 and allow a debug connection to be made.
 */
void efr32_escape_hatch(void) {

#if defined(ESCAPE_HATCH_ENABLE) && (ESCAPE_HATCH_ENABLE == TRUE)
  const uint32_t port = ESCAPE_HATCH_PORT;
  const uint32_t pin  = ESCAPE_HATCH_PIN;
  const bool gpio_clk_was_enabled = (CMU->CLKEN0 & CMU_CLKEN0_GPIO) != 0U;
  unsigned int pin_state;

  CMU->CLKEN0_SET = CMU_CLKEN0_GPIO;

  GPIO->P_SET[port].DOUT = 1UL << pin;
  if (pin < 8) {
    GPIO->P[port].MODEL = (GPIO->P[port].MODEL & ~(0xFu << (pin * 4))) |
                          (GPIO_P_MODEL_MODE0_INPUTPULLFILTER << (pin * 4));
  } else {
    GPIO->P[port].MODEH = (GPIO->P[port].MODEH & ~(0xFu << (pin * 4))) |
                          (GPIO_P_MODEL_MODE0_INPUTPULLFILTER << (pin * 4));
  }

  pin_state = (GPIO->P[port].DIN >> pin) & 1;

  if (pin_state == 0) { /* Pi asserted, so break into debugger. */
    __BKPT(0);
  } else { /* Pin not asserted, so disable input. */
    if (pin < 8) {
      GPIO->P[port].MODEL = (GPIO->P[port].MODEL & ~(0xFu << (pin * 4))) |
                            (GPIO_P_MODEL_MODE0_DISABLED << (pin * 4));
    } else {
      GPIO->P[port].MODEH = (GPIO->P[port].MODEH & ~(0xFu << (pin * 4))) |
                            (GPIO_P_MODEL_MODE0_DISABLED << (pin * 4));
    }

    if (!gpio_clk_was_enabled) {
      CMU->CLKEN0_CLR = CMU_CLKEN0_GPIO;
    }
  }
#endif
}


/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void) {

  /* NVIC initialization.*/
  nvicInit();
}

/** @} */