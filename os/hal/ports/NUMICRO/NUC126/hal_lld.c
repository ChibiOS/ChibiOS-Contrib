/*
  Copyright (C) 2020 Alex Lewontin
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
 * @file    hal_lld.c
 * @brief   NUC126 HAL subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/
#define FREQ_25MHZ  25000000
#define FREQ_50MHZ  50000000
#define FREQ_72MHZ  72000000
#define FREQ_100MHZ 100000000
#define FREQ_200MHZ 200000000

#define CLK_CLKDIV0_HCLK(x)     (((x)-1) << CLK_CLKDIV0_HCLKDIV_Pos) /*!< CLKDIV0 Setting for HCLK clock divider. It could be 1~16 */

//  PLLCTL constant definitions. PLL = FIN * NF / NR / NO

#define CLK_PLLCTL_NF(x)        ((x)-2)         /*!< x must be constant and 2 <= x <= 513. 200MHz < FIN*NF/NR < 500MHz. (FIN*NF/NR > 250MHz is preferred.) */
#define CLK_PLLCTL_NR(x)        (((x)-2)<<9)    /*!< x must be constant and 2 <= x <= 33.  1.6MHz < FIN/NR < 16MHz */
#define CLK_PLLCTL_NO(x)        ((x-1)<<14)        /*!< x must be either 1, 2 or 4. */

#define CLK_PLLCTL(src, nr, nf, no)     \
        (src | CLK_PLLCTL_NR(nr) |      \
         CLK_PLLCTL_NF(nf) | CLK_PLLCTL_NO(no))

#define CLK_PLLCTL_72MHz_HXT    CLK_PLLCTL(NUC126_PLLSRC_HSE, 4, 48, 2) /*!< Predefined PLLCTL setting for 72MHz PLL output with HXT(12MHz X'tal) */
#define CLK_PLLCTL_144MHz_HXT    CLK_PLLCTL(NUC126_PLLSRC_HSE, 4, 48, 1) /*!< Predefined PLLCTL setting for 144MHz PLL output with HXT(12MHz X'tal) */
#define CLK_PLLCTL_72MHz_HIRC    CLK_PLLCTL(NUC126_PLLSRC_HSE, 8, 52, 2) /*!< Predefined PLLCTL setting for 71.8848MHz PLL output with HIRC(22.1184MHz IRC) */

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

_Bool clock_initialized = FALSE;

uint32_t SystemCoreClock  = __HSI;              /*!< System Clock Frequency (Core Clock) */
uint32_t CyclesPerUs      = (__HSI / 1000000);  /*!< Cycles per micro second             */
#if NUC126_PLL_ENABLED
uint32_t PllClock         = __HSI;              /*!< PLL Output Clock Frequency          */
#endif
const uint32_t gau32ClkSrcTbl[] = {__HXT, __LXT, __HSI, __LIRC, __HIRC48, 0UL, 0UL, __HIRC};

#if (NUC126_CONFIG_ENABLED == TRUE)

static volatile const uint32_t config0 __attribute__((used, unused, section(".nuc126_config0"))) = NUC126_CONFIG0;
static volatile const uint32_t config1 __attribute__((used, unused, section(".nuc126_config1"))) = NUC126_CONFIG1;

#endif

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
  * @brief      Enable clock source
  * @param[in]  u32ClkMask is clock source mask. Including :
  *             - \ref CLK_PWRCTL_HXTEN_Msk
  *             - \ref CLK_PWRCTL_LXTEN_Msk
  *             - \ref CLK_PWRCTL_HIRCEN_Msk
  *             - \ref CLK_PWRCTL_LIRCEN_Msk
  *             - \ref CLK_PWRCTL_HIRC48EN_Msk
  * @return     None
  * @details    This function enable clock source. \n
  *             The register write-protection function should be disabled before using this function.
  */
static void CLK_EnableXtalRC(uint32_t u32ClkMask)
{
    CLK->PWRCTL |= u32ClkMask;
}

/**
  * @brief      This function check selected clock source status
  * @param[in]  u32ClkMask is selected clock source. Including :
  *             - \ref CLK_STATUS_HXTSTB_Msk
  *             - \ref CLK_STATUS_LXTSTB_Msk
  *             - \ref CLK_STATUS_HIRCSTB_Msk
  *             - \ref CLK_STATUS_LIRCSTB_Msk
  *             - \ref CLK_STATUS_PLLSTB_Msk
  *             - \ref CLK_STATUS_HIRC48STB_Msk
  * @retval     0  clock is not stable
  * @retval     1  clock is stable
  * @details    To wait for clock ready by specified clock source stable flag or timeout (>500ms)
  */
static uint32_t CLK_WaitClockReady(uint32_t u32ClkMask)
{
    uint32_t u32TimeOutCnt = SystemCoreClock>>1; /* 500ms time-out */
    uint32_t u32Ret = 1U;

    while((CLK->STATUS & u32ClkMask) != u32ClkMask)
    {
        if(--u32TimeOutCnt == 0)
        {
            u32Ret = 0U;
            break;
        }
    }

    return u32Ret;
}

/**
  * @brief      Set HCLK clock source and HCLK clock divider
  * @param[in]  u32ClkSrc is HCLK clock source. Including :
  *             - \ref NUC126_HCLKSRC_HSE
  *             - \ref NUC126_HCLKSRC_LSE
  *             - \ref NUC126_HCLKSRC_PLL
  *             - \ref NUC126_HCLKSRC_LSI
  *             - \ref NUC126_HCLKSRC_HSI48
  *             - \ref NUC126_HCLKSRC_HSI
  * @param[in]  u32ClkDiv is HCLK clock divider. Including :
  *             - \ref CLK_CLKDIV0_HCLK(x)
  * @return     None
  * @details    This function set HCLK clock source and HCLK clock divider.
  *             The register write-protection function should be disabled before using this function.
  */
static void CLK_SetHCLK(uint32_t u32ClkSrc, uint32_t u32ClkDiv)
{
    uint32_t u32HIRCSTB;

    /* Read HIRC clock source stable flag */
    u32HIRCSTB = CLK->STATUS & CLK_STATUS_HIRCSTB_Msk;

    /* Switch to HIRC for Safe. Avoid HCLK too high when applying new divider. */
    CLK->PWRCTL |= CLK_PWRCTL_HIRCEN_Msk;
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);
    CLK->CLKSEL0 = (CLK->CLKSEL0 & (~CLK_CLKSEL0_HCLKSEL_Msk)) | NUC126_HCLKSRC_HSI;

    /* Apply new Divider */
    CLK->CLKDIV0 = (CLK->CLKDIV0 & (~CLK_CLKDIV0_HCLKDIV_Msk)) | u32ClkDiv;

    /* Switch HCLK to new HCLK source */
    CLK->CLKSEL0 = (CLK->CLKSEL0 & (~CLK_CLKSEL0_HCLKSEL_Msk)) | u32ClkSrc;

    /* Update System Core Clock */
    SystemCoreClockUpdate();

    /* Disable HIRC if HIRC is disabled before switching HCLK source */
    if(u32HIRCSTB == 0)
        CLK->PWRCTL &= ~CLK_PWRCTL_HIRCEN_Msk;
}

#if NUC126_PLL_ENABLED
/**
  * @brief      Get PLL clock frequency
  * @param      None
  * @return     PLL frequency
  * @details    This function get PLL frequency. The frequency unit is Hz.
  */
static inline uint32_t CLK_GetPLLClockFreq(void)
{
  uint32_t PllReg;
  uint32_t pllFIN, pllNF, pllNR, pllNO;

  PllReg = CLK->PLLCTL;

  if (PllReg & (CLK_PLLCTL_PD_Msk | CLK_PLLCTL_OE_Msk)) {
    PllClock = 0; /* PLL is in power down mode or fix low */
  } else {

    if (PllReg & NUC126_PLLSRC_HSI) {
      pllFIN = __HIRC; /* Use HXT for PLL clock */
    } else {
      pllFIN = NUC126_HSECLK; /* Use HXT for PLL clock */
    }

    if (PllReg & CLK_PLLCTL_BP_Msk) {
      PllClock = pllFIN;
    } else {
      switch (((PllReg & CLK_PLLCTL_OUTDIV_Msk) >> CLK_PLLCTL_OUTDIV_Pos)) {
      case 0: /* OUT_DIV == 00 : NO = 1 */
        pllNO = 1;
        break;
      case 3: /* OUT_DIV == 11 : NO = 4 */
        pllNO = 4;
        break;
      default: /* OUT_DIV == 01 or 10 : NO = 2 */
        pllNO = 2;
        break;
      }

      pllNF = ((PllReg & CLK_PLLCTL_FBDIV_Msk) >> CLK_PLLCTL_FBDIV_Pos) + 2;
      pllNR = ((PllReg & CLK_PLLCTL_INDIV_Msk) >> CLK_PLLCTL_INDIV_Pos) + 2;

      /* Shift to avoid overflow condition */
      PllClock = (((pllFIN >> 2) * pllNF) / (pllNR * pllNO) << 2);
    }
  }

  return PllClock;
}

/**
  * @brief      Set PLL frequency
  * @param[in]  pllSrc is PLL clock source. Including :
  *             - \ref NUC126_PLLSRC_HSE
  *             - \ref NUC126_PLLSRC_HSI
  * @param[in]  pllFreq is PLL frequency. The range of pllFreq is 25 MHz ~ 200 MHz.
  * @return     PLL frequency
  * @details    This function is used to configure PLLCTL register to set specified PLL frequency. \n
  *             The register write-protection function should be disabled before using this function.
  */
uint32_t CLK_EnablePLL(uint32_t pllSrc, uint32_t pllFreq)
{
    /* Disable PLL first to avoid unstable when setting PLL */
    CLK->PLLCTL |= CLK_PLLCTL_PD_Msk;

    /* Check and setup correct clock source */
    switch (pllSrc) {
    case NUC126_PLLSRC_HSE:
        /* Enable HXT clock */
        CLK->PWRCTL |= CLK_PWRCTL_HXTEN_Msk;

        /* Wait for HXT clock ready */
        CLK_WaitClockReady(CLK_STATUS_HXTSTB_Msk);

        break;
    case NUC126_PLLSRC_HSI:
        /* Enable HIRC clock */
        CLK->PWRCTL |= CLK_PWRCTL_HIRCEN_Msk;

        /* Wait for HIRC clock ready */
        CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);

        break;
    }

  /**
     * Calculate best PLL variables from requested frequency
     *
     * See NUC126 Technical Reference Manual, PLL Control Register Description
     *
     *                NF     1
     * FOUT = FIN  x  --  x  --
     *                NR     NO
     *
     */

  uint32_t NO      = 0;
  uint32_t NR      = 0;
  uint32_t clkCalc = 0;

  /* Set "NO" for requested frequency */
  if (pllFreq >= FREQ_25MHZ && pllFreq <= FREQ_50MHZ) {
    /* Low frequency - use full variable headroom */
    pllFreq <<= 2;
    NO = 4;
  } else if (pllFreq > FREQ_50MHZ && pllFreq <= FREQ_100MHZ) {
    /* Medium frequency - use full variable headroom */
    pllFreq <<= 1;
    NO = 2;
  } else if (pllFreq > FREQ_100MHZ && pllFreq <= FREQ_200MHZ) {
    /* High frequency - full variable headroom already used */
    NO = 1;
  } else {
    /* Frequency out of range - use default PLL settings */
    /* Apply default PLL setting and return */
    if(pllSrc == NUC126_PLLSRC_HSE)
        CLK->PLLCTL = CLK_PLLCTL_72MHz_HXT; /* 72MHz */
    else
        CLK->PLLCTL = CLK_PLLCTL_72MHz_HIRC; /* 71.8848MHz */

    /* Wait for PLL clock stable */
    CLK_WaitClockReady(CLK_STATUS_PLLSTB_Msk);

    return CLK_GetPLLClockFreq();
  }

  /* Setup "NR" and clkCalc */
  switch (pllSrc) {
  case NUC126_PLLSRC_HSE:
    NR      = 2;
    clkCalc = NUC126_HSECLK;
    break;
  case NUC126_PLLSRC_HSI:
    NR      = 4;
    clkCalc = __HIRC;
    break;
  }

  /**
     * Loop to calculate best/lowest NR (between 0 or 2 and 31) and best/lowest NF (between 0 and 511)
     *
     * Best results are off-by-2 until final equation calculation (to allow use in PLLCTL)
     *
     */
  uint32_t bestNR   = 0;
  uint32_t bestNF   = 0;
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
            bestNF   = NF;
            bestNR   = NR;

            /* Stop NF calc loop when minLimit tends back to 0 */
            if (minLimit == 0)
              break;
          }
        }

        NF++;
      }
    }

    NR++;
  }

  /* Enable and apply new PLL setting. */
  CLK->PLLCTL = CLK_PLLCTL(pllSrc, NO, bestNR, bestNF);

  /* Wait for PLL clock stable */
  CLK_WaitClockReady(CLK_STATUS_PLLSTB_Msk);

  /* Return equation result */
  return (clkCalc / (NO * bestNR) * bestNF);
}

/**
  * @brief      Set HCLK frequency
  * @param[in]  u32Hclk is HCLK frequency. The range of u32Hclk is 25 MHz ~ 72 MHz.
  * @return     HCLK frequency
  * @details    This function is used to set HCLK frequency. The frequency unit is Hz. \n
  *             It would configure PLL frequency to 50MHz ~ 144MHz,
  *             set HCLK clock divider as 2 and switch HCLK clock source to PLL. \n
  *             The register write-protection function should be disabled before using this function.
  */
uint32_t CLK_SetCoreClock(uint32_t u32Hclk)
{
    uint32_t u32HIRCSTB;

    /* Read HIRC clock source stable flag */
    u32HIRCSTB = CLK->STATUS & CLK_STATUS_HIRCSTB_Msk;

    /* The range of u32Hclk is 25 MHz ~ 72 MHz */
    if(u32Hclk > FREQ_72MHZ) {
        u32Hclk = FREQ_72MHZ;
    }
    if(u32Hclk < FREQ_25MHZ) {
        u32Hclk = FREQ_25MHZ;
    }

    /* Setup __HIRC */
    CLK->PWRCTL |= CLK_PWRCTL_HIRCEN_Msk;

    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);

    /* Use __HIRC as HCLK temporarily */
    CLK->CLKSEL0 |= CLK_CLKSEL0_HCLKSEL_Msk;
    CLK->CLKDIV0 &= (~CLK_CLKDIV0_HCLKDIV_Msk);

    /* Is HXT stable ? */
    if(CLK->STATUS & CLK_STATUS_HXTSTB_Msk) {
        /* Use NUC126_HSECLK as PLL source */
        u32Hclk = CLK_EnablePLL(NUC126_PLLSRC_HSE, (2 * u32Hclk));
    } else {
        /* Use __HIRC as PLL source */
        u32Hclk = CLK_EnablePLL(NUC126_PLLSRC_HSI, (2 * u32Hclk));

        /* Read HIRC clock source stable flag again (since we're using it now) */
        u32HIRCSTB = CLK->STATUS & CLK_STATUS_HIRCSTB_Msk;
    }

    /* Set HCLK clock source to PLL */
    CLK_SetHCLK(NUC126_HCLKSRC_PLL, CLK_CLKDIV0_HCLK(1));

    /* Disable HIRC if HIRC was disabled before we started */
    if(u32HIRCSTB == 0) {
        CLK->PWRCTL &= ~CLK_PWRCTL_HIRCEN_Msk;
    }

    /* Return actual HCLK frequency is PLL frequency divide 2 */
    return u32Hclk >> 1;
}
#endif // NUC126_PLL_ENABLED

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

void SystemCoreClockUpdate(void)
{
    uint32_t u32Freq, u32ClkSrc;
    uint32_t u32HclkDiv;

    u32ClkSrc = CLK->CLKSEL0 & CLK_CLKSEL0_HCLKSEL_Msk;

#if NUC126_PLL_ENABLED
    /* Update PLL Clock */
    PllClock = CLK_GetPLLClockFreq();
#endif

    if(u32ClkSrc != NUC126_HCLKSRC_PLL)
    {
        /* Use the clock sources directly */
        u32Freq = gau32ClkSrcTbl[u32ClkSrc];
    }
    else
    {
#if NUC126_PLL_ENABLED
        /* Use PLL clock */
        u32Freq = PllClock;
#else
        // Uh oh...
	      u32Freq = 0;
#endif
    }

    u32HclkDiv = (CLK->CLKDIV0 & CLK_CLKDIV0_HCLKDIV_Msk) + 1;

    /* Update System Core Clock */
    SystemCoreClock = u32Freq / u32HclkDiv;

    CyclesPerUs = (SystemCoreClock + 500000) / 1000000;
}

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void)
{
  if (!clock_initialized) {
    NUC126_clock_init();
  }
}

void NUC126_clock_init(void)
{
  clock_initialized = TRUE;
  UNLOCKREG();

  /* Always initialize HSI and go from there, things can change later */

  /* Enable HSI */
  CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);
  CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);

  /* Switch HCLK clock source to HSI */
  CLK_SetHCLK(NUC126_HCLKSRC_HSI, CLK_CLKDIV0_HCLK(1));

#if NUC126_HSI48_ENABLED
  CLK_EnableXtalRC(CLK_PWRCTL_HIRC48EN_Msk);
  CLK_WaitClockReady(CLK_STATUS_HIRC48STB_Msk);
#endif

#if NUC126_HSE_ENABLED
  /* 
   * Set PF[3:4] to output HSE
   * Note: This is already set by CONFIG0[27] if NUC126_CONFIG_ENABLED is set
   */
  SYS->GPF_MFPL |= (SYS_GPF_MFPL_PF4MFP_Msk | SYS_GPF_MFPL_PF3MFP_Msk);

  CLK_EnableXtalRC(CLK_PWRCTL_HXTEN_Msk);
  CLK_WaitClockReady(CLK_STATUS_HXTSTB_Msk);
#endif /* NUC126_HSE_ENABLED */

#if NUC126_LSE_ENABLED
  CLK_EnableXtalRC(CLK_PWRCTL_LXTEN_Msk);
  CLK_WaitClockReady(CLK_STATUS_LXTSTB_Msk);
#endif /* NUC126_LSE_ENABLED */

#if NUC126_LSI_ENABLED
  CLK_EnableXtalRC(CLK_PWRCTL_LIRCEN_Msk);
  CLK_WaitClockReady(CLK_STATUS_LIRCSTB_Msk);
#endif /* NUC126_LSI_ENABLED */

#if NUC126_PLL_ENABLED
  CLK_SetCoreClock(NUC126_HCLK);
#endif /* NUC126_PLL_ENABLED */

  LOCKREG();
}

/** @} */
