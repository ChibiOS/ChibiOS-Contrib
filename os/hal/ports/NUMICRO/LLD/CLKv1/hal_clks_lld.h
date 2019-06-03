/*
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
 * @file    hal_clks_lld.h
 * @brief   Clock/Timer subsystem low level header.
 *
 * @addtogroup CLKS
 * @{
 */

#ifndef HAL_CLKS_LLD_H
#define HAL_CLKS_LLD_H

// #if HAL_USE_CLKS || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#define FREQ_25MHZ         25000000
#define FREQ_50MHZ         50000000
#define FREQ_72MHZ         72000000
#define FREQ_100MHZ       100000000
#define FREQ_200MHZ       200000000

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL0                                                                                                */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKSEL0_HCLK_S_HXT          (0x0ul<<CLK_CLKSEL0_HCLK_S_Pos)   /*!< Set HCLK clock source as HXT */
#define CLK_CLKSEL0_HCLK_S_PLL_DIV2     (0x1ul<<CLK_CLKSEL0_HCLK_S_Pos)   /*!< Set HCLK clock source as PLL/2 */
#define CLK_CLKSEL0_HCLK_S_PLL          (0x2ul<<CLK_CLKSEL0_HCLK_S_Pos)   /*!< Set HCLK clock source as PLL */
#define CLK_CLKSEL0_HCLK_S_LIRC         (0x3ul<<CLK_CLKSEL0_HCLK_S_Pos)   /*!< Set HCLK clock source as LIRC */
#define CLK_CLKSEL0_HCLK_S_HIRC         (0x7ul<<CLK_CLKSEL0_HCLK_S_Pos)   /*!< Set HCLK clock source as HIRC */


/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL1                                                                                                */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKSEL1_TMR0_S_HXT          (0x0ul<<CLK_CLKSEL1_TMR0_S_Pos)   /*!< Set TMR0 clock source as HXT */
#define CLK_CLKSEL1_TMR0_S_HCLK         (0x2ul<<CLK_CLKSEL1_TMR0_S_Pos)   /*!< Set TMR0 clock source as HCLK */
#define CLK_CLKSEL1_TMR0_S_EXT_TRG      (0x3ul<<CLK_CLKSEL1_TMR0_S_Pos)   /*!< Set TMR0 clock source as external trigger */
#define CLK_CLKSEL1_TMR0_S_LIRC         (0x5ul<<CLK_CLKSEL1_TMR0_S_Pos)   /*!< Set TMR0 clock source as LIRC */
#define CLK_CLKSEL1_TMR0_S_HIRC         (0x7ul<<CLK_CLKSEL1_TMR0_S_Pos)   /*!< Set TMR0 clock source as HIRC */
#define CLK_CLKSEL1_TMR1_S_HXT          (0x0ul<<CLK_CLKSEL1_TMR1_S_Pos)   /*!< Set TMR1 clock source as HXT */
#define CLK_CLKSEL1_TMR1_S_HCLK         (0x2ul<<CLK_CLKSEL1_TMR1_S_Pos)   /*!< Set TMR1 clock source as HCLK */
#define CLK_CLKSEL1_TMR1_S_EXT_TRG      (0x3ul<<CLK_CLKSEL1_TMR1_S_Pos)   /*!< Set TMR1 clock source as external trigger */
#define CLK_CLKSEL1_TMR1_S_LIRC         (0x5ul<<CLK_CLKSEL1_TMR1_S_Pos)   /*!< Set TMR1 clock source as LIRC */
#define CLK_CLKSEL1_TMR1_S_HIRC         (0x7ul<<CLK_CLKSEL1_TMR1_S_Pos)   /*!< Set TMR1 clock source as HIRC*/
#define CLK_CLKSEL1_TMR2_S_HXT          (0x0ul<<CLK_CLKSEL1_TMR2_S_Pos)   /*!< Set TMR2 clock source as external X'tal */
#define CLK_CLKSEL1_TMR2_S_HCLK         (0x2ul<<CLK_CLKSEL1_TMR2_S_Pos)   /*!< Set TMR2 clock source as HCLK */
#define CLK_CLKSEL1_TMR2_S_EXT_TRG      (0x3ul<<CLK_CLKSEL1_TMR2_S_Pos)   /*!< Set TMR2 clock source as external trigger */
#define CLK_CLKSEL1_TMR2_S_LIRC         (0x5ul<<CLK_CLKSEL1_TMR2_S_Pos)   /*!< Set TMR2 clock source as LIRC */
#define CLK_CLKSEL1_TMR2_S_HIRC         (0x7ul<<CLK_CLKSEL1_TMR2_S_Pos)   /*!< Set TMR2 clock source as HIRC */
#define CLK_CLKSEL1_TMR3_S_HXT          (0x0ul<<CLK_CLKSEL1_TMR3_S_Pos)   /*!< Set TMR3 clock source as HXT */
#define CLK_CLKSEL1_TMR3_S_HCLK         (0x2ul<<CLK_CLKSEL1_TMR3_S_Pos)   /*!< Set TMR3 clock source as HCLK */
#define CLK_CLKSEL1_TMR3_S_EXT_TRG      (0x3ul<<CLK_CLKSEL1_TMR3_S_Pos)   /*!< Set TMR3 clock source as external trigger */
#define CLK_CLKSEL1_TMR3_S_LIRC         (0x5ul<<CLK_CLKSEL1_TMR3_S_Pos)   /*!< Set TMR3 clock source as LIRC */
#define CLK_CLKSEL1_TMR3_S_HIRC         (0x7ul<<CLK_CLKSEL1_TMR3_S_Pos)   /*!< Set TMR3 clock source as HIRC */
#define CLK_CLKSEL1_PWM01_S_HXT         (0x0ul<<CLK_CLKSEL1_PWM01_S_Pos)  /*!< Set PWM01 clock source as HXT */
#define CLK_CLKSEL1_PWM01_S_HCLK        (0x2ul<<CLK_CLKSEL1_PWM01_S_Pos)  /*!< Set PWM01 clock source as HCLK */
#define CLK_CLKSEL1_PWM01_S_HIRC        (0x3ul<<CLK_CLKSEL1_PWM01_S_Pos)  /*!< Set PWM01 clock source as HIRC */
#define CLK_CLKSEL1_PWM01_S_LIRC        (0x3ul<<CLK_CLKSEL1_PWM01_S_Pos)  /*!< Set PWM01 clock source as LIRC */
#define CLK_CLKSEL1_PWM23_S_HXT         (0x0ul<<CLK_CLKSEL1_PWM23_S_Pos)  /*!< Set PWM23 clock source as HXT */
#define CLK_CLKSEL1_PWM23_S_HCLK        (0x2ul<<CLK_CLKSEL1_PWM23_S_Pos)  /*!< Set PWM23 clock source as HCLK */
#define CLK_CLKSEL1_PWM23_S_HIRC        (0x3ul<<CLK_CLKSEL1_PWM23_S_Pos)  /*!< Set PWM23 clock source as HIRC */
#define CLK_CLKSEL1_PWM23_S_LIRC        (0x3ul<<CLK_CLKSEL1_PWM23_S_Pos)  /*!< Set PWM23 clock source as LIRC */


/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL2                                                                                                */
/*---------------------------------------------------------------------------------------------------------*/

#define CLK_CLKSEL2_PWM01_EXT_HXT       (0x0ul<<CLK_CLKSEL2_PWM01_S_Pos)  /*!< Set PWM01 clock source as HXT */
#define CLK_CLKSEL2_PWM01_EXT_HCLK      (0x0ul<<CLK_CLKSEL2_PWM01_S_Pos)  /*!< Set PWM01 clock source as HCLK */
#define CLK_CLKSEL2_PWM01_EXT_HIRC      (0x0ul<<CLK_CLKSEL2_PWM01_S_Pos)  /*!< Set PWM01 clock source as HIRC */
#define CLK_CLKSEL2_PWM01_EXT_LIRC      (0x1ul<<CLK_CLKSEL2_PWM01_S_Pos)  /*!< Set PWM01 clock source as LIRC */
#define CLK_CLKSEL2_PWM23_EXT_HXT       (0x0ul<<CLK_CLKSEL2_PWM23_S_Pos)  /*!< Set PWM23 clock source as HXT */
#define CLK_CLKSEL2_PWM23_EXT_HCLK      (0x0ul<<CLK_CLKSEL2_PWM23_S_Pos)  /*!< Set PWM23 clock source as HCLK */
#define CLK_CLKSEL2_PWM23_EXT_HIRC      (0x0ul<<CLK_CLKSEL2_PWM23_S_Pos)  /*!< Set PWM23 clock source as HIRC */
#define CLK_CLKSEL2_PWM23_EXT_LIRC      (0x1ul<<CLK_CLKSEL2_PWM23_S_Pos)  /*!< Set PWM23 clock source as LIRC */

#define CLK_CLKSEL2_FRQDIV_S_HXT        (0x0ul<<CLK_CLKSEL2_FRQDIV_S_Pos) /*!< Set FRQDIV clock source as HXT */
#define CLK_CLKSEL2_FRQDIV_S_HCLK       (0x2ul<<CLK_CLKSEL2_FRQDIV_S_Pos) /*!< Set FRQDIV clock source as HCLK */
#define CLK_CLKSEL2_FRQDIV_S_HIRC       (0x3ul<<CLK_CLKSEL2_FRQDIV_S_Pos) /*!< Set FRQDIV clock source as HIRC */


/*---------------------------------------------------------------------------------------------------------*/
/*  CLKDIV                                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/

#define CLK_CLKDIV_HCLK(x)  ((x)-1)                             /*!< HCLK clock divider (1~16) */
#define CLK_CLKDIV_USB(x)  (((x)-1) << CLK_CLKDIV_USB_N_Pos)    /*!< USB clock divider (1~16)  */


/*---------------------------------------------------------------------------------------------------------*/
/*  PLLCON                                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/

#define CLK_PLLCON_PLL_SRC_HXT   0x00000000ul    /*!< Set PLL clock source as HXT */
#define CLK_PLLCON_PLL_SRC_HIRC  0x00080000ul    /*!< Set PLL clock source as HIRC */


/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */

/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

// extern DACDriver DACD1;

#ifdef __cplusplus
extern "C" {
#endif
  // void CLK_SetHCLK(uint32_t u32ClkSrc, uint32_t u32ClkDiv);
  // void CLK_EnableModuleClock(uint32_t u32ModuleIdx);
  // void CLK_DisableModuleClock(uint32_t u32ModuleIdx);
  // uint32_t CLK_WaitClockReady(uint32_t u32ClkMask);
  // void CLK_EnableSysTick(uint32_t u32ClkSrc, uint32_t u32Count);
  // void CLK_DisableSysTick(void);

  
/**
  * @brief      Get PLL clock frequency
  * @param      None
  * @return     PLL frequency
  * @details    This function get PLL frequency. The frequency unit is Hz.
  */
  static inline uint32_t clks_lld_get_pll_clock_freq(void) {
    uint32_t PllReg;
    uint32_t pllFIN, pllNF, pllNR, pllNO;

    PllReg = CLK->PLLCON;

    if(PllReg & (CLK_PLLCON_PD_Msk | CLK_PLLCON_OE_Msk)) {
        PllClock = 0;           /* PLL is in power down mode or fix low */
    } else {

      if (PllReg & CLK_PLLCON_PLL_SRC_HIRC) {
          pllFIN = __HIRC;    /* Use HXT for PLL clock */
      } else {
          pllFIN = __HXT;     /* Use HXT for PLL clock */
      }

      if (PllReg & CLK_PLLCON_BP_Msk) {
          PllClock = pllFIN;
      } else {
        switch (((PllReg & CLK_PLLCON_OUT_DV_Msk) >> CLK_PLLCON_OUT_DV_Pos)) {
            case 0b00: // OUT_DIV == 00 : NO = 1
                pllNO = 1;
                break;
            case 0b11: // OUT_DIV == 11 : NO = 4
                pllNO = 4;
                break;
            default:   // OUT_DIV == 01 or 10 : NO = 2
                pllNO = 2;
                break;
        }

        pllNF = ((PllReg & CLK_PLLCON_FB_DV_Msk) >> CLK_PLLCON_FB_DV_Pos) + 2;
        pllNR = ((PllReg & CLK_PLLCON_IN_DV_Msk) >> CLK_PLLCON_IN_DV_Pos) + 2;

        /* shift to avoid overflow condition */
        PllClock = (((pllFIN >> 2) * pllNF) / (pllNR * pllNO) << 2);
      }
    }

    return PllClock;
  }

  uint32_t clks_lld_set_core_clock(uint32_t clkCore);
  void clks_lld_set_HCLK(uint32_t clkSource, uint32_t clkDivider);
  void clks_lld_set_module_clock(uint32_t module, uint32_t clkSource, uint32_t clkDivider);
  void clks_lld_enable_ck0(uint32_t clkSource, uint32_t clkDivider);
  void clks_lld_enable_module_clock(uint32_t moduleIdx);
  void clks_lld_disable_module_clock(uint32_t moduleIdx);
  uint32_t clks_lld_enable_pll(uint32_t pllSrc, uint32_t pllFreq);
  uint32_t clks_lld_wait_for_clock_ready(uint32_t clkMask);
  void clks_lld_enable_SysTick(uint32_t clkSource, uint32_t count);
  void clks_lld_disable_SysTick(void);

#ifdef __cplusplus
}
#endif

#endif /* HAL_CLK_LLD_H */

/** @} */
