/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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
#include "sam_clk.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

#if defined(HAL_LLD_USE_CLOCK_MANAGEMENT) && !defined(__DOXYGEN__)
/**
 * @brief   Post-reset configuration, must be implemented.
 */
const halclkcfg_t hal_clkcfg_reset = {.dummy = 0U};

/**
 * @brief   Configuration from mcuconf.h, must be implemented.
 */
const halclkcfg_t hal_clkcfg_default = {.dummy = 0U};
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

typedef enum ctrlb_refclk_t {
  SAM_CTRLB_REFCLK_GCLK = 0,
  SAM_CTRLB_REFCLK_XOSC32,
  SAM_CTRLB_REFCLK_XOSC0,
  SAM_CTRLB_REFCLK_XOSC1,
} ctrlb_refclk_t;

typedef struct {
  ctrlb_refclk_t refclk;
  uint8_t div;
  bool en;
} ctrlb_reg_t;

typedef struct ratio_reg_t {
  uint32_t ldfrac;
  uint32_t ldr;
} ratio_reg_t;

typedef struct gclk_cfg {
  uint32_t src;
  uint32_t gendiv;
  uint8_t en;
} gclk_cfg_t;

const static gclk_cfg_t gclk_cfg_arr[12] = {
    {SAM_GCLK0_SRC, SAM_GCLK0_SRC_FREQ / SAM_GCLK0_FREQ, TRUE},
    {SAM_GCLK1_SRC, SAM_GCLK1_SRC_FREQ / SAM_GCLK1_FREQ, SAM_GCLK1_ENABLE},
    {SAM_GCLK2_SRC, SAM_GCLK2_SRC_FREQ / SAM_GCLK2_FREQ, SAM_GCLK2_ENABLE},
    {SAM_GCLK3_SRC, SAM_GCLK3_SRC_FREQ / SAM_GCLK3_FREQ, SAM_GCLK3_ENABLE},
    {SAM_GCLK4_SRC, SAM_GCLK4_SRC_FREQ / SAM_GCLK4_FREQ, SAM_GCLK4_ENABLE},
    {SAM_GCLK5_SRC, SAM_GCLK5_SRC_FREQ / SAM_GCLK5_FREQ, SAM_GCLK5_ENABLE},
    {SAM_GCLK6_SRC, SAM_GCLK6_SRC_FREQ / SAM_GCLK6_FREQ, SAM_GCLK6_ENABLE},
    {SAM_GCLK7_SRC, SAM_GCLK7_SRC_FREQ / SAM_GCLK7_FREQ, SAM_GCLK7_ENABLE},
    {SAM_GCLK8_SRC, SAM_GCLK8_SRC_FREQ / SAM_GCLK8_FREQ, SAM_GCLK8_ENABLE},
    {SAM_GCLK9_SRC, SAM_GCLK9_SRC_FREQ / SAM_GCLK9_FREQ, SAM_GCLK9_ENABLE},
    {SAM_GCLK10_SRC, SAM_GCLK10_SRC_FREQ / SAM_GCLK10_FREQ, SAM_GCLK10_ENABLE},
    {SAM_GCLK11_SRC, SAM_GCLK11_SRC_FREQ / SAM_GCLK11_FREQ, SAM_GCLK11_ENABLE},
};

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief Get the imult iptat values based on XOSC frequency (reference table 28-7)
 * 
 * @param osc_freq Input oscillator frequency
 * @param imult
 * @param iptat 
 */
static inline void get_imult_iptat(uint32_t osc_freq, uint8_t* imult,
                                   uint8_t* iptat) {
  if (osc_freq == 8000000ul) {
    *imult = 3;
    *iptat = 2;
  } else if (osc_freq > 8000000ul && osc_freq <= 16000000ul) {
    *imult = 4;
    *iptat = 3;
  } else if (osc_freq > 16000000ul && osc_freq <= 24000000ul) {
    *imult = 5;
    *iptat = 3;
  } else if (osc_freq > 24000000ul && osc_freq <= 48000000ul) {
    *imult = 6;
    *iptat = 3;
  }
}

/**
 * @brief Configure XOSCCTRL 
 * 
 * @param id id of the oscillator 
 * @param input_freq crystal frequency
 * @param enable enable this or not
 */
static void sam_xosc_init(const uint32_t id, const uint32_t input_freq,
                          bool enable) {
  osalDbgAssert(id < 2, "Invalid ID");
  uint8_t imult = 0, iptat = 0;
  get_imult_iptat(input_freq, &imult, &iptat);
  /* Configure External Oscillator */
  uint32_t en_mask =
      OSCCTRL_XOSCCTRL_XTALEN_Msk | OSCCTRL_XOSCCTRL_ENABLE(enable);
  if (!enable) {
    en_mask = 0;
  }
  OSCCTRL_REGS->OSCCTRL_XOSCCTRL[id] = OSCCTRL_XOSCCTRL_STARTUP(0U) |
                                       OSCCTRL_XOSCCTRL_IMULT(imult) |
                                       OSCCTRL_XOSCCTRL_IPTAT(iptat) | en_mask;
  if (enable) {
    while ((OSCCTRL_REGS->OSCCTRL_STATUS & (1 << id)) != (1 << id)) {
      /* Waiting for the XOSC Ready state */
    }
  }
}

/**
 * @brief Configure FDPLL 
 * 
 * @param id FDPLL no
 * @param ctrlb ctrlb values
 * @param ratio ratio values
 */
static void sam_fdpll_init(const uint32_t id, const ctrlb_reg_t* ctrlb,
                           const ratio_reg_t* ratio) {
  osalDbgAssert(((id < 2) && (ctrlb != NULL) && (ratio != NULL)),
                "invalid parameters");
  if (!ctrlb->en) {
    OSCCTRL_REGS->DPLL[id].OSCCTRL_DPLLCTRLA &= ~OSCCTRL_DPLLCTRLA_ENABLE_Msk;
    return;
  }
  /* Configure DPLL    */
  OSCCTRL_REGS->DPLL[id].OSCCTRL_DPLLCTRLB =
      OSCCTRL_DPLLCTRLB_FILTER(0U) | OSCCTRL_DPLLCTRLB_LTIME(0x0U) |
      OSCCTRL_DPLLCTRLB_REFCLK(ctrlb->refclk) |
      OSCCTRL_DPLLCTRLB_DIV(ctrlb->div);

  OSCCTRL_REGS->DPLL[id].OSCCTRL_DPLLRATIO =
      OSCCTRL_DPLLRATIO_LDRFRAC(ratio->ldfrac) |
      OSCCTRL_DPLLRATIO_LDR(ratio->ldr);

  while ((OSCCTRL_REGS->DPLL[id].OSCCTRL_DPLLSYNCBUSY &
          OSCCTRL_DPLLSYNCBUSY_DPLLRATIO_Msk) ==
         OSCCTRL_DPLLSYNCBUSY_DPLLRATIO_Msk) {
    /* Waiting for the synchronization */
  }

  /* Enable DPLL */
  OSCCTRL_REGS->DPLL[id].OSCCTRL_DPLLCTRLA = OSCCTRL_DPLLCTRLA_ENABLE_Msk;

  while ((OSCCTRL_REGS->DPLL[id].OSCCTRL_DPLLSYNCBUSY &
          OSCCTRL_DPLLSYNCBUSY_ENABLE_Msk) == OSCCTRL_DPLLSYNCBUSY_ENABLE_Msk) {
    /* Waiting for the DPLL enable synchronization */
  }

  while ((OSCCTRL_REGS->DPLL[id].OSCCTRL_DPLLSTATUS &
          (OSCCTRL_DPLLSTATUS_LOCK_Msk | OSCCTRL_DPLLSTATUS_CLKRDY_Msk)) !=
         (OSCCTRL_DPLLSTATUS_LOCK_Msk | OSCCTRL_DPLLSTATUS_CLKRDY_Msk)) {
    /* Waiting for the Ready state */
  }
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
  sam_xosc_init(0, SAM_XOSC0_FREQ, SAM_XOSC0_ENABLED);
  sam_xosc_init(1, SAM_XOSC1_FREQ, SAM_XOSC1_ENABLED);

  sam_gclk_init(1, gclk_cfg_arr[1].src, gclk_cfg_arr[1].gendiv,
                gclk_cfg_arr[1].en);

  /* Initialize FDPLL0 */
#if SAM_FDPLL0_ENABLED == TRUE
  ctrlb_reg_t ctrl = {
      SAM_FDPLL0_INPUT_SRC,
      SAM_FDPLL0_DIV,
      SAM_FDPLL0_ENABLED,
  };
  ratio_reg_t ratio_reg = {SAM_FDPLL0_LDFRAC, SAM_FDPLL0_LDR};
#else
  ctrlb_reg_t ctrl = {
      0,
      0,
      SAM_FDPLL0_ENABLED,
  };
  ratio_reg_t ratio_reg = {0, SAM_FDPLL0_LDR};
#endif

  sam_fdpll_init(0, &ctrl, &ratio_reg);

  /* Initialize FDPLL 1 */
#if SAM_FDPLL1_ENABLED == TRUE
  ctrl = (ctrlb_reg_t){
      SAM_FDPLL1_INPUT_SRC,
      SAM_FDPLL1_DIV,
      SAM_FDPLL1_ENABLED,
  };
  ratio_reg = (ratio_reg_t){SAM_FDPLL1_LDFRAC, SAM_FDPLL1_LDR};
#else
  ctrl = (ctrlb_reg_t){
      0,
      0,
      SAM_FDPLL1_ENABLED,
  };
  ratio_reg = (ratio_reg_t){0, 0};
#endif
  sam_fdpll_init(1, &ctrl, &ratio_reg);
  for (int i = 2; i < 11; i++) {
    sam_gclk_init(i, gclk_cfg_arr[i].src, gclk_cfg_arr[i].gendiv,
                  gclk_cfg_arr[i].en);
  }
  sam_gclk_init(0, gclk_cfg_arr[0].src, gclk_cfg_arr[0].gendiv,
                gclk_cfg_arr[0].en);

  MCLK_REGS->MCLK_CPUDIV = MCLK_CPUDIV_DIV(SAM_CPUDIV);

  while ((MCLK_REGS->MCLK_INTFLAG & MCLK_INTFLAG_CKRDY_Msk) !=
         MCLK_INTFLAG_CKRDY_Msk) {
    /* Wait for the Main Clock to be Ready */
  }
#if defined(SAM_DMAC_REQUIRED)
  dmacInit();
#endif
}

#if defined(HAL_LLD_USE_CLOCK_MANAGEMENT) || defined(__DOXYGEN__)
/**
 * @brief   Switches to a different clock configuration
 *
 * @param[in] ccp       pointer to clock a @p halclkcfg_t structure
 * @return              The clock switch result.
 * @retval false        if the clock switch succeeded
 * @retval true         if the clock switch failed
 *
 * @notapi
 */
bool hal_lld_clock_switch_mode(const halclkcfg_t* ccp) {

  (void)ccp;

  return false;
}

/**
 * @brief   Returns the frequency of a clock point in Hz.
 *
 * @param[in] clkpt     clock point to be returned
 * @return              The clock point frequency in Hz or zero if the
 *                      frequency is unknown.
 *
 * @notapi
 */
halfreq_t hal_lld_get_clock_point(halclkpt_t clkpt) {

  (void)clkpt;

  return 0U;
}
#endif /* defined(HAL_LLD_USE_CLOCK_MANAGEMENT) */

/** @} */
