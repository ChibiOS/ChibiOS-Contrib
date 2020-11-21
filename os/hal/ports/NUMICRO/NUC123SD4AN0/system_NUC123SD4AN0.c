/**************************************************************************//**
 * @file     system_NUC123SD4AN0.c
 * @brief    CMSIS Cortex-M0 Device Peripheral Access Layer Source File for
 *           Device NUC123SD4AN0
 * @version  V5.00
 * @date     13. May 2019
 ******************************************************************************/
/*
 * Copyright (c) 2019 /u/KeepItUnder. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdint.h>
#include "NUC123SD4AN0.h"


/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
/* ToDo: add here your necessary defines for device initialization
         following is an example for different system frequencies */
// #define XTAL            (12000000U)       /* Oscillator frequency             */

// #define SYSTEM_CLOCK    (5 * XTAL)


/*----------------------------------------------------------------------------
  System Core Clock Variable
 *----------------------------------------------------------------------------*/
/* ToDo: initialize SystemCoreClock with the system core clock frequency value
         achieved after system intitialization.
         This means system core clock frequency after call to SystemInit() */
// uint32_t SystemCoreClock = SYSTEM_CLOCK;          /* System Clock Frequency (Core Clock)*/
// uint32_t CyclesPerUs = (SYSTEM_CLOCK / 1000000);    /* Cycles per micro second */
// uint32_t PllClock = SYSTEM_CLOCK;                 /*!< PLL Clock Frequency */
uint32_t SystemCoreClock = __HSI;          /* System Clock Frequency (Core Clock)*/
uint32_t CyclesPerUs = (__HSI / 1000000);    /* Cycles per micro second */
uint32_t PllClock = __HSI;                 /*!< PLL Clock Frequency */


/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/

void SystemCoreClockUpdate (void)            /* Get Core Clock Frequency      */
{
/* ToDo: add code to calculate the system frequency based upon the current
         register settings.
         This function can be used to retrieve the system core clock frequeny
         after user changed register sittings. */
  // SystemCoreClock = SYSTEM_CLOCK;

    uint32_t clkFreq;
    uint32_t PllReg;

    uint32_t pllFIN, pllNF, pllNR, pllNO;

    /* Update PLL Clock */
    // PllClock = clks_lld_get_pll_clock_freq();
    PllReg = CLK->PLLCON;

    if(PllReg & (CLK_PLLCON_PD_Msk | CLK_PLLCON_OE_Msk)) {
        PllClock = 0;         /* PLL is off. */
    } else {

      if (PllReg & 0x00080000ul) {
          pllFIN = __HIRC;    /* Use HXT for PLL clock */
      } else {
          pllFIN = __HXT;     /* Use HXT for PLL clock */
      }

      if (PllReg & CLK_PLLCON_BP_Msk) {
          PllClock = pllFIN;
      } else {
        switch (((PllReg & CLK_PLLCON_OUT_DV_Msk) >> CLK_PLLCON_OUT_DV_Pos)) {
            case 0b00: /* OUT_DIV == 00 : NO = 1 */
                pllNO = 1;
                break;
            case 0b11: /* OUT_DIV == 11 : NO = 4 */
                pllNO = 4;
                break;
            default:   /* OUT_DIV == 01 or 10 : NO = 2 */
                pllNO = 2;
                break;
        }

        pllNF = ((PllReg & CLK_PLLCON_FB_DV_Msk) >> CLK_PLLCON_FB_DV_Pos) + 2;
        pllNR = ((PllReg & CLK_PLLCON_IN_DV_Msk) >> CLK_PLLCON_IN_DV_Pos) + 2;

        /* Shift right to avoid overflow condition */
        PllClock = (((pllFIN >> 2) * pllNF) / (pllNR * pllNO) << 2);
      }
    }

    /* Pick Clock Source */
    switch (CLK->CLKSEL0 & CLK_CLKSEL0_HCLK_S_Msk) {
      case 0: // External HF Xtal
        clkFreq = __HXT;
        break;
      case 1: // PLL clock / 2
        clkFreq = PllClock >> 1;
        break;
      case 3: // Internal 10kHz
        clkFreq = __LIRC;
        break;
      case 2: // PLL clock
        clkFreq = PllClock;
        break;
      case 7: // Internal 22.184MHz
        clkFreq = __HIRC;
        break;
      default:
        clkFreq = NULL;
        break;
    }

    SystemCoreClock = clkFreq / ((CLK->CLKDIV & CLK_CLKDIV_HCLK_N_Msk) + 1);
    // CyclesPerUs = (SystemCoreClock + 500000) / 1000000;
    CyclesPerUs = SystemCoreClock / 1000000;
}


void SystemInit (void)
{
/* ToDo: add code to initialize the system
         do not use global variables because this function is called before
         reaching pre-main. RW section maybe overwritten afterwards. */
  // SystemCoreClock = SYSTEM_CLOCK;
}


void SystemUnlockReg(void)
{
    while(SYS->REGWRPROT != SYS_REGWRPROT_REGPROTDIS_Msk)
    {
        SYS->REGWRPROT = 0x59ul;
        SYS->REGWRPROT = 0x16ul;
        SYS->REGWRPROT = 0x88ul;
    }
}
