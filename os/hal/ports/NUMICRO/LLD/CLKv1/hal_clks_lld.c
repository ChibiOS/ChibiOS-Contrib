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
 * @file    CLKv1/hal_clks_lld.c
 * @brief   CLK subsystem low level driver code.
 *
 * @addtogroup CLKS
 * @{
 */

#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/**
 * WDT_ModuleNum
 * ADC_ModuleNum
 * SPI0_ModuleNum
 * SPI1_ModuleNum
 * SPI2_ModuleNum
 * TMR0_ModuleNum
 * TMR1_ModuleNum
 * TMR2_ModuleNum
 * TMR3_ModuleNum
 * UART0_ModuleNum
 * UART1_ModuleNum
 * PWM01_ModuleNum
 * PWM23_ModuleNum
 * I2S_ModuleNum
 * FDIV_ModuleNum
 * WWDT_ModuleNum
 * USBD_ModuleNum
 * I2C0_ModuleNum
 * I2C1_ModuleNum
 * PS2_ModuleNum
 * PDMA_ModuleNum
 * ISP_ModuleNum
 * 
 */

bool clks_module_hxt_source[22] =    { 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
bool clks_module_hirc_source[22] =   { 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
bool clks_module_lirc_source[22] =   { 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 };
bool clks_module_hclk_source[22] =   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };
bool clks_module_pll_source[22] =    { 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 };
bool clks_module_ext_source[22] =    { 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
bool clks_module_divider[22] =       { 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 };
uint32_t clks_module_enable[22] =    { CLK_APBCLK_WDT_EN_Msk,
                                       CLK_APBCLK_ADC_EN_Msk,
                                       CLK_APBCLK_SPI0_EN_Msk,
                                       CLK_APBCLK_SPI1_EN_Msk,
                                       CLK_APBCLK_SPI2_EN_Msk,
                                       CLK_APBCLK_TMR0_EN_Msk,
                                       CLK_APBCLK_TMR1_EN_Msk,
                                       CLK_APBCLK_TMR2_EN_Msk,
                                       CLK_APBCLK_TMR3_EN_Msk,
                                       CLK_APBCLK_UART0_EN_Msk,
                                       CLK_APBCLK_UART1_EN_Msk,
                                       CLK_APBCLK_PWM01_EN_Msk,
                                       CLK_APBCLK_PWM23_EN_Msk,
                                       CLK_APBCLK_I2S_EN_Msk,
                                       CLK_APBCLK_FDIV_EN_Msk,
                                       0,
                                       CLK_APBCLK_USBD_EN_Msk,
                                       CLK_APBCLK_I2C0_EN_Msk,
                                       CLK_APBCLK_I2C1_EN_Msk,
                                       CLK_APBCLK_PS2_EN_Msk,
                                       CLK_AHBCLK_PDMA_EN_Msk,
                                       CLK_AHBCLK_ISP_EN_Msk };
uint32_t clks_module_sel1_mask[22] = { CLK_CLKSEL1_WDT_S_Msk,
                                       CLK_CLKSEL1_ADC_S_Msk,
                                       CLK_CLKSEL1_SPI0_S_Msk,
                                       CLK_CLKSEL1_SPI1_S_Msk,
                                       CLK_CLKSEL1_SPI2_S_Msk,
                                       CLK_CLKSEL1_TMR0_S_Msk,
                                       CLK_CLKSEL1_TMR1_S_Msk,
                                       CLK_CLKSEL1_TMR2_S_Msk,
                                       CLK_CLKSEL1_TMR3_S_Msk,
                                       CLK_CLKSEL1_UART_S_Msk,
                                       CLK_CLKSEL1_UART_S_Msk,
                                       CLK_CLKSEL1_PWM01_S_Msk,
                                       CLK_CLKSEL1_PWM23_S_Msk,
                                       0, 0, 0, 0, 0, 0, 0, 0, 0 };

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
 * @brief   Low level CLK driver initialization.
 *
 * @notapi
 */

/** @brief Set Core Clock
 * 
 * @description Set the core system clock some reference speed (Hz).
 *              This should be between 25MHz and 72MHz for the NUC123SD4AN0.
 * 
 *              Use either the HXT (exact) or HIRC (nearest using 22.1184MHz)
 *              as the clock source.
 * 
 */
uint32_t clks_lld_set_core_clock(uint32_t clkCore)
{
    uint32_t stableHIRC;

    /* Read HIRC clock source stable flag */
    stableHIRC = CLK->CLKSTATUS & CLK_CLKSTATUS_OSC22M_STB_Msk;

    /* Setup __HIRC */
    CLK->PWRCON |= CLK_PWRCON_OSC22M_EN_Msk;

    clks_lld_wait_for_clock_ready(CLK_CLKSTATUS_OSC22M_STB_Msk);

    /* Use __HIRC as HCLK temporarily */
    CLK->CLKSEL0 |= CLK_CLKSEL0_HCLK_S_Msk;
    CLK->CLKDIV &= (~CLK_CLKDIV_HCLK_N_Msk);

    /* Is HXT stable ? */
    if(CLK->CLKSTATUS & CLK_CLKSTATUS_XTL12M_STB_Msk) {
        /* Use __HXT as PLL source */
        clkCore = clks_lld_enable_pll(CLK_PLLCON_PLL_SRC_HXT, (clkCore << 1));
    } else {
        /* Use __HIRC as PLL source */
        clkCore = clks_lld_enable_pll(CLK_PLLCON_PLL_SRC_HIRC, (clkCore << 1));

        /* Read HIRC clock source stable flag again (since we're using it now) */
        stableHIRC = CLK->CLKSTATUS & CLK_CLKSTATUS_OSC22M_STB_Msk;
    }
    
    /* Set HCLK clock source to PLL */
    clks_lld_set_HCLK(CLK_CLKSEL0_HCLK_S_PLL, CLK_CLKDIV_HCLK(2));

    /* Disable HIRC if HIRC was disabled before we started */
    if (stableHIRC == 0) {
        CLK->PWRCON &= ~CLK_PWRCON_OSC22M_EN_Msk;
    }

    /* Return actual HCLK frequency is PLL frequency divide 2 */
    return (clkCore >> 1);
}


/** @brief Set system HCLK
 * 
 * @description Setup HCLK source and divider
 * 
 * Always switch to a known stable clock source before changing a
 * system clock, to avoid issues related to the original clock's
 * speed/settings.
 * 
 */
void clks_lld_set_HCLK(uint32_t clkSource, uint32_t clkDivider)
{
    uint32_t stableHIRC;

    /* Read HIRC clock source stable flag */    
    stableHIRC = CLK->CLKSTATUS & CLK_CLKSTATUS_OSC22M_STB_Msk;

    /* Setup __HIRC */
    CLK->PWRCON |= CLK_CLKSTATUS_OSC22M_STB_Msk;

    clks_lld_wait_for_clock_ready(CLK_CLKSTATUS_OSC22M_STB_Msk);

    /* Use __HIRC as HCLK, temporarily */
    CLK->CLKSEL0 = (CLK->CLKSEL0 & (~CLK_CLKSEL0_HCLK_S_Msk)) | CLK_CLKSEL0_HCLK_S_HIRC;

    /* Set new clock divider */
    CLK->CLKDIV = (CLK->CLKDIV & (~CLK_CLKDIV_HCLK_N_Msk)) | clkDivider;

    /* Switch HCLK to new HCLK source */
    CLK->CLKSEL0 = (CLK->CLKSEL0 & (~CLK_CLKSEL0_HCLK_S_Msk)) | clkSource;

    /* Update System Core Clock */
    SystemCoreClockUpdate();

    /* Disable HIRC if HIRC was disabled before we started */
    if (stableHIRC == 0) {
        CLK->PWRCON &= ~CLK_CLKSTATUS_OSC22M_STB_Msk;
    }
}


void clks_lld_set_module_clock(uint32_t module, uint32_t clkSource, uint32_t clkDivider)
{
    /* Set clock source */
    CLK->CLKSEL1 = (CLK->CLKSEL1 & (~(clks_module_sel1_mask[module]))) | clkSource;

    /* Set secondary clock source bit for PWM01/PWM23 */
    if (module == PWM01_ModuleNum) {
        CLK->CLKSEL2 = (CLK->CLKSEL2 & (~CLK_CLKSEL2_PWM01_S_Msk)) | (clkSource & CLK_CLKSEL2_PWM01_S_Msk);
    } else if (module == PWM23_ModuleNum) {
        CLK->CLKSEL2 = (CLK->CLKSEL2 & (~CLK_CLKSEL2_PWM23_S_Msk)) | (clkSource & CLK_CLKSEL2_PWM23_S_Msk);
    }

    /* Set clock divider */
    if (clks_module_divider[module]) {
        switch (module) {
            case ADC_ModuleNum:
                CLK->CLKDIV = (CLK->CLKDIV & ~CLK_CLKDIV_ADC_N_Msk) | clkDivider;
                break;
            case UART0_ModuleNum:
            case UART1_ModuleNum:
                CLK->CLKDIV = (CLK->CLKDIV & ~CLK_CLKDIV_UART_N_Msk) | clkDivider;
                break;
            case USBD_ModuleNum:
                CLK->CLKDIV = (CLK->CLKDIV & ~CLK_CLKDIV_USB_N_Msk) | clkDivider;
                break;
            default:
                break;
        }
    }
}


void clks_lld_enable_ck0(uint32_t clkSource, uint32_t clkDivider)
{
    CLK->FRQDIV = (CLK_FRQDIV_DIVIDER_EN_Msk | clkDivider) ;

    clks_lld_enable_module_clock(FDIV_ModuleNum);

    clks_lld_set_module_clock(FDIV_ModuleNum, clkSource, 0);
}


/**
  * @brief      Enable module clock
  * 
  * @description   Module clock enables are all in either AHBCLK or APBCLK
  *                Register masks are stored in a table to save knowing bit width
  * 
  */
void clks_lld_enable_module_clock(uint32_t clkModule) {
    switch (clkModule) {
        case PDMA_ModuleNum:
        case ISP_ModuleNum:
            /* AHB Clocks */
            CLK->AHBCLK |= clks_module_enable[clkModule];
            break;
        case WWDT_ModuleNum:
            /* No Module Clock */
            break;
        default:
            /* APB Clocks */
            CLK->APBCLK |= clks_module_enable[clkModule];
            break;
    }
}


/**
  * @brief         Disable module clock
  * 
  * @description   Module clock enables are all in either AHBCLK or APBCLK
  *                Register masks are stored in a table to save knowing bit width
  * 
  */
void clks_lld_disable_module_clock(uint32_t clkModule) {
    switch (clkModule) {
        case PDMA_ModuleNum:
        case ISP_ModuleNum:
            /* AHB Clocks */
            CLK->AHBCLK &= ~clks_module_enable[clkModule];
            break;
        case WWDT_ModuleNum:
            /* No Module Clock */
            break;
        default:
            /* APB Clocks */
            CLK->APBCLK &= ~clks_module_enable[clkModule];
            break;
    }
}


uint32_t clks_lld_enable_pll(uint32_t pllSrc, uint32_t pllFreq)
{
    /* Disable PLL first to avoid unstable when setting PLL. */
    CLK->PLLCON = CLK_PLLCON_PD_Msk;

    /* Check and setup correct clock source */
    switch (pllSrc) {
        case CLK_PLLCON_PLL_SRC_HXT:
            /* Use HXT clock */
            CLK->PWRCON |= CLK_PWRCON_XTL12M_EN_Msk;

            /* Wait for stable HXT */
            clks_lld_wait_for_clock_ready(CLK_CLKSTATUS_XTL12M_STB_Msk);


            break;
        case CLK_PLLCON_PLL_SRC_HIRC:
            /* Use HIRC clock */
            CLK->PWRCON |= CLK_PWRCON_OSC22M_EN_Msk;

            /* Wait for stable HIRC */
            clks_lld_wait_for_clock_ready(CLK_CLKSTATUS_OSC22M_STB_Msk);

            break;
    }

    /**
     * Calculate best PLL variables from requested frequency
     * 
     * See NUC123 Technical Reference Manual 5.4.8 PLL Control Register Description, page 124
     * 
     *                NF     1
     * FOUT = FIN  x  --  x  --
     *                NR     NO
     * 
     */

    uint32_t NO = 0;
    uint32_t NR = 0;
    uint32_t clkCalc = 0;

    /* Set "NO" for requested frequency */
    /* We're using "NO" first to set the PLLCON - so make it "NO" - 1; */
    if (pllFreq >= FREQ_25MHZ && pllFreq <= FREQ_50MHZ) {
        /* Low frequency - use full variable headroom */
        pllFreq <<= 2;
        NO = 3;
    } else if (pllFreq > FREQ_50MHZ && pllFreq <= FREQ_100MHZ) {
        /* Medium frequency - use full variable headroom */
        pllFreq <<= 1;
        NO = 1;
    } else if (pllFreq > FREQ_100MHZ && pllFreq <= FREQ_200MHZ) {
        /* High frequency - full variable headroom already used */
        NO = 0;
    } else {
        /* Frequency out of range - use default PLL settings
         *
         * See NUC123 Technical Reference Manual PLL COntrol Register Description, page 124
         * The default value: 0xC22E
         *   FIN = 12 MHz
         *   NR = (1+2) = 3
         *   NF = (46+2) = 48
         *   NO = 4
         *   FOUT = 12/4 x 48 x 1/3 = 48 MHz
         */
        if (pllSrc == CLK_PLLCON_PLL_SRC_HXT) {
            CLK->PLLCON = 0xC22E;
        } else {
            CLK->PLLCON = 0xD66F;
        }

        /* Wait for stable PLL clock */
        clks_lld_wait_for_clock_ready(CLK_CLKSTATUS_PLL_STB_Msk);

        return clks_lld_get_pll_clock_freq();
    }

    /* Setup "NR" and clkCalc */
    switch (pllSrc) {
        case CLK_PLLCON_PLL_SRC_HXT:
            NR = 2;
            clkCalc = __HXT;
            break;
        case CLK_PLLCON_PLL_SRC_HIRC:
            NR = 4;
            clkCalc = __HIRC;
            break;
    }

    /**
     * Loop to calculate best/lowest NR (between 0 or 2 and 31) and best/lowest NF (between 0 and 511)
     * 
     * Best results are off-by-2 until final equation calculation (to allow use in PLLCON)
     * 
     */
    uint32_t bestNR = 0;
    uint32_t bestNF = 0;
    uint32_t minLimit = -1;

    while (NR <= 33) {
        uint32_t tmpCalc1 = clkCalc / NR;

        if (tmpCalc1 > 1600000 && tmpCalc1 < 16000000) {
            uint32_t NF = 2;

            while (NF <= 513) {
                uint32_t tmpCalc2 = tmpCalc1 * NF;

                if (tmpCalc2 >= 100000000 && tmpCalc2 <= 200000000) {
                    uint32_t tmpCalc3;

                    if (tmpCalc2 > pllFreq) {
                        tmpCalc3 = tmpCalc2 - pllFreq;
                    } else {
                        tmpCalc3 = pllFreq - tmpCalc2;
                    }

                    if (tmpCalc3 < minLimit) {
                        minLimit = tmpCalc3;
                        bestNF = NF;
                        bestNR = NR;

                        /* Stop NF calc loop when minLimit tends back to 0 */
                        if(minLimit == 0)
                            break;
                    }
                }

                NF++;
            }
        }

        NR++;
    }

    /* Enable and apply new PLL setting. */
    CLK->PLLCON = pllSrc | (NO << 14) | ((bestNR - 2) << 9) | (bestNF - 2);

    /* Wait for stable PLL clock */
    clks_lld_wait_for_clock_ready(CLK_CLKSTATUS_PLL_STB_Msk);

    /* Return equation result */
    return (clkCalc / ((NO + 1) * bestNR) * bestNF);
}


/**
  * @brief         Wait for stable clock
  * 
  * @description   Always wait around 300ms for clock to be stable
  * 
  */
uint32_t clks_lld_wait_for_clock_ready(uint32_t clkMask)
{
    int32_t timeout = 2180000;

    while (timeout-- > 0) {
        if ((CLK->CLKSTATUS & clkMask) == clkMask) {
            return 1;
        }
    }

    return 0;
}


void clks_lld_enable_SysTick(uint32_t clkSrc, uint32_t count) {

    // Disable the counter
    clks_lld_disable_SysTick();

    // Clear current values/flags
    SysTick->VAL = 0;

    // Set SysTick Clock Source
    switch (clkSrc) {
      case CLK_CLKSEL0_STCLK_S_HCLK:
        SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
        break;
      default:
        CLK->CLKSEL0 = (CLK->CLKSEL0 & ~CLK_CLKSEL0_STCLK_S_Msk) | clkSrc; 
        // CLK->CLKSEL0 |= SysTick_CTRL_CLKSOURCE_Msk;
        break;
    }

    // Set reload value
    SysTick->LOAD = count;

    // Enable Interrupt and Counter
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
}


void clks_lld_disable_SysTick(void) {
    /* Disable System Tick counter */
	SysTick->CTRL = 0;
}

/** @} */
