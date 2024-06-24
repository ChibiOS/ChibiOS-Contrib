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
 * @file    sam_clk.h
 * @brief   Helper file to configure SAME54
 *
 * @addtogroup HAL
 * @{
 */

#ifndef SAM_CLK_H_
#define SAM_CLK_H_

#if !defined(SAM_XOSC0_FREQ) && SAM_XOSC0_ENABLED == TRUE
#error "XOSC0 input freq is not defined"
#elif SAM_XOSC0_ENABLED == FALSE
#undef SAM_XOSC0_FREQ
#define SAM_XOSC0_FREQ 0
#endif

#if !defined(SAM_XOSC1_FREQ) && SAM_XOSC1_ENABLED == TRUE
#error "XOSC1 input freq is not defined"
#elif SAM_XOSC1_ENABLED == FALSE
#undef SAM_XOSC1_FREQ
#define SAM_XOSC1_FREQ 0
#endif

#if SAM_XOSC32K_ENABLED == FALSE
#undef SAM_XOSC32K_FREQ
#define SAM_XOSC32K_FREQ 0
#endif

// FDPLL0 Configuration
#if SAM_FDPLL0_ENABLED == TRUE

#ifndef SAM_FDPLL0_INPUT_SRC
#error "no input source for FDPLL0"
#endif

#if SAM_FDPLL0_INPUT_SRC == SAM_DPLL_INPUT_SRC_GCLK
#error "TODO this configuration is currently not supported"
#elif SAM_FDPLL0_INPUT_SRC == SAM_DPLL_INPUT_SRC_XOSC32
#define SAM_FDPLL0_INPUT_FREQ SAM_XOSC32K_FREQ
#elif SAM_FDPLL0_INPUT_SRC == SAM_DPLL_INPUT_SRC_XOSC0
#define SAM_FDPLL0_INPUT_FREQ SAM_XOSC0_FREQ
#elif SAM_FDPLL0_INPUT_SRC == SAM_DPLL_INPUT_SRC_XOSC1
#define SAM_FDPLL0_INPUT_FREQ SAM_XOSC1_FREQ
#endif

#if SAM_FDPLL0_INPUT_FREQ == 0
#error input freq for FDPLL0 is 0
#endif

#define SAM_FDPLL0_OUTPUT_FREQ                           \
  (SAM_FDPLL0_INPUT_FREQ / (2 * (SAM_FDPLL0_DIV + 1))) * \
      (SAM_FDPLL0_LDR + 1 + SAM_FDPLL0_LDFRAC / 32)
#endif

// FDPLL1 Configuration
#if SAM_FDPLL1_ENABLED == TRUE

#ifndef SAM_FDPLL1_INPUT_SRC
#error "no input source for FDPLL1"
#endif

#if SAM_FDPLL1_INPUT_SRC == SAM_DPLL_INPUT_SRC_GCLK
#error "TODO this configuration is currently not supported"
#elif SAM_FDPLL1_INPUT_SRC == SAM_DPLL_INPUT_SRC_XOSC32
#define SAM_FDPLL1_INPUT_FREQ SAM_XOSC32K_FREQ
#elif SAM_FDPLL1_INPUT_SRC == SAM_DPLL_INPUT_SRC_XOSC0
#define SAM_FDPLL1_INPUT_FREQ SAM_XOSC0_FREQ
#elif SAM_FDPLL1_INPUT_SRC == SAM_DPLL_INPUT_SRC_XOSC1
#define SAM_FDPLL1_INPUT_FREQ SAM_XOSC1_FREQ
#endif

#if SAM_FDPLL1_INPUT_FREQ == 0
#error input freq for FDPLL0 is 0
#endif

#define SAM_FDPLL1_OUTPUT_FREQ                           \
  (SAM_FDPLL1_INPUT_FREQ / (2 * (SAM_FDPLL1_DIV + 1))) * \
      (SAM_FDPLL1_LDR + 1 + (SAM_FDPLL1_LDFRAC / 32))

#if (SAM_FDPLL1_OUTPUT_FREQ < 96000000ul) || \
    (SAM_FDPLL1_OUTPUT_FREQ > 200000000ul)
#error FDLL out of range
#endif

#endif

// GCLK0
#if SAM_GCLK0_SRC == GCLK_GENCTRL_SRC_XOSC0
#define SAM_GCLK0_SRC_FREQ SAM_XOSC0_FREQ
#elif SAM_GCLK0_SRC == GCLK_GENCTRL_SRC_XOSC1
#define SAM_GCLK0_SRC_FREQ SAM_XOSC1_FREQ
#elif SAM_GCLK0_SRC == GCLK_GENCTRL_SRC_DPLL0
#define SAM_GCLK0_SRC_FREQ SAM_FDPLL0_OUTPUT_FREQ
#elif SAM_GCLK0_SRC == GCLK_GENCTRL_SRC_DPLL1
#define SAM_GCLK0_SRC_FREQ SAM_FDPLL1_OUTPUT_FREQ
#else
#error not supported configuration
#endif

// GCLK1
#if SAM_GCLK1_ENABLE == TRUE
#if SAM_GCLK1_SRC == GCLK_GENCTRL_SRC_XOSC0
#define SAM_GCLK1_SRC_FREQ SAM_XOSC0_FREQ
#elif SAM_GCLK1_SRC == GCLK_GENCTRL_SRC_XOSC1
#define SAM_GCLK1_SRC_FREQ SAM_XOSC1_FREQ
#elif SAM_GCLK1_SRC == GCLK_GENCTRL_SRC_DPLL0
#define SAM_GCLK1_SRC_FREQ SAM_FDPLL0_OUTPUT_FREQ
#elif SAM_GCLK1_SRC == GCLK_GENCTRL_SRC_DPLL1
#define SAM_GCLK1_SRC_FREQ SAM_FDPLL1_OUTPUT_FREQ
#else
#error not supported configuration
#endif
#else
#define SAM_GCLK1_SRC_FREQ 0
#endif

// GCLK2
#if SAM_GCLK2_ENABLE == TRUE
#if SAM_GCLK2_SRC == GCLK_GENCTRL_SRC_XOSC0
#define SAM_GCLK2_SRC_FREQ SAM_XOSC0_FREQ
#elif SAM_GCLK2_SRC == GCLK_GENCTRL_SRC_XOSC1
#define SAM_GCLK2_SRC_FREQ SAM_XOSC1_FREQ
#elif SAM_GCLK2_SRC == GCLK_GENCTRL_SRC_DPLL0
#define SAM_GCLK2_SRC_FREQ SAM_FDPLL0_OUTPUT_FREQ
#elif SAM_GCLK2_SRC == GCLK_GENCTRL_SRC_DPLL1
#define SAM_GCLK2_SRC_FREQ SAM_FDPLL1_OUTPUT_FREQ
#else
#error not supported configuration
#endif
#else
#define SAM_GCLK2_SRC_FREQ 0
#endif

// GCLK3
#if SAM_GCLK3_ENABLE == TRUE
#if SAM_GCLK3_SRC == GCLK_GENCTRL_SRC_XOSC0
#define SAM_GCLK3_SRC_FREQ SAM_XOSC0_FREQ
#elif SAM_GCLK3_SRC == GCLK_GENCTRL_SRC_XOSC1
#define SAM_GCLK3_SRC_FREQ SAM_XOSC1_FREQ
#elif SAM_GCLK3_SRC == GCLK_GENCTRL_SRC_DPLL0
#define SAM_GCLK3_SRC_FREQ SAM_FDPLL0_OUTPUT_FREQ
#elif SAM_GCLK3_SRC == GCLK_GENCTRL_SRC_DPLL1
#define SAM_GCLK3_SRC_FREQ SAM_FDPLL1_OUTPUT_FREQ
#else
#error not supported configuration
#endif
#else
#define SAM_GCLK3_SRC_FREQ 0
#endif

// GCLK4
#if SAM_GCLK4_ENABLE == TRUE
#if SAM_GCLK4_SRC == GCLK_GENCTRL_SRC_XOSC0
#define SAM_GCLK4_SRC_FREQ SAM_XOSC0_FREQ
#elif SAM_GCLK4_SRC == GCLK_GENCTRL_SRC_XOSC1
#define SAM_GCLK4_SRC_FREQ SAM_XOSC1_FREQ
#elif SAM_GCLK4_SRC == GCLK_GENCTRL_SRC_DPLL0
#define SAM_GCLK4_SRC_FREQ SAM_FDPLL0_OUTPUT_FREQ
#elif SAM_GCLK4_SRC == GCLK_GENCTRL_SRC_DPLL1
#define SAM_GCLK4_SRC_FREQ SAM_FDPLL1_OUTPUT_FREQ
#else
#error not supported configuration
#endif
#else
#define SAM_GCLK4_SRC_FREQ 0
#endif

// GCLK5
#if SAM_GCLK5_ENABLE == TRUE
#if SAM_GCLK5_SRC == GCLK_GENCTRL_SRC_XOSC0
#define SAM_GCLK5_SRC_FREQ SAM_XOSC0_FREQ
#elif SAM_GCLK5_SRC == GCLK_GENCTRL_SRC_XOSC1
#define SAM_GCLK5_SRC_FREQ SAM_XOSC1_FREQ
#elif SAM_GCLK5_SRC == GCLK_GENCTRL_SRC_DPLL0
#define SAM_GCLK5_SRC_FREQ SAM_FDPLL0_OUTPUT_FREQ
#elif SAM_GCLK5_SRC == GCLK_GENCTRL_SRC_DPLL1
#define SAM_GCLK5_SRC_FREQ SAM_FDPLL1_OUTPUT_FREQ
#else
#error not supported configuration
#endif
#else
#define SAM_GCLK5_SRC_FREQ 0
#endif

// GCLK6
#if SAM_GCLK6_ENABLE == TRUE
#if SAM_GCLK6_SRC == GCLK_GENCTRL_SRC_XOSC0
#define SAM_GCLK6_SRC_FREQ SAM_XOSC0_FREQ
#elif SAM_GCLK6_SRC == GCLK_GENCTRL_SRC_XOSC1
#define SAM_GCLK6_SRC_FREQ SAM_XOSC1_FREQ
#elif SAM_GCLK6_SRC == GCLK_GENCTRL_SRC_DPLL0
#define SAM_GCLK6_SRC_FREQ SAM_FDPLL0_OUTPUT_FREQ
#elif SAM_GCLK6_SRC == GCLK_GENCTRL_SRC_DPLL1
#define SAM_GCLK6_SRC_FREQ SAM_FDPLL1_OUTPUT_FREQ
#else
#error not supported configuration
#endif
#else
#define SAM_GCLK6_SRC_FREQ 0
#endif

// GCLK7
#if SAM_GCLK7_ENABLE == TRUE
#if SAM_GCLK7_SRC == GCLK_GENCTRL_SRC_XOSC0
#define SAM_GCLK7_SRC_FREQ SAM_XOSC0_FREQ
#elif SAM_GCLK7_SRC == GCLK_GENCTRL_SRC_XOSC1
#define SAM_GCLK7_SRC_FREQ SAM_XOSC1_FREQ
#elif SAM_GCLK7_SRC == GCLK_GENCTRL_SRC_DPLL0
#define SAM_GCLK7_SRC_FREQ SAM_FDPLL0_OUTPUT_FREQ
#elif SAM_GCLK7_SRC == GCLK_GENCTRL_SRC_DPLL1
#define SAM_GCLK7_SRC_FREQ SAM_FDPLL1_OUTPUT_FREQ
#else
#error not supported configuration
#endif
#else
#define SAM_GCLK7_SRC_FREQ 0
#endif

// GCLK8
#if SAM_GCLK8_ENABLE == TRUE
#if SAM_GCLK8_SRC == GCLK_GENCTRL_SRC_XOSC0
#define SAM_GCLK8_SRC_FREQ SAM_XOSC0_FREQ
#elif SAM_GCLK8_SRC == GCLK_GENCTRL_SRC_XOSC1
#define SAM_GCLK8_SRC_FREQ SAM_XOSC1_FREQ
#elif SAM_GCLK8_SRC == GCLK_GENCTRL_SRC_DPLL0
#define SAM_GCLK8_SRC_FREQ SAM_FDPLL0_OUTPUT_FREQ
#elif SAM_GCLK8_SRC == GCLK_GENCTRL_SRC_DPLL1
#define SAM_GCLK8_SRC_FREQ SAM_FDPLL1_OUTPUT_FREQ
#else
#error not supported configuration
#endif
#else
#define SAM_GCLK8_SRC_FREQ 0
#endif

// GCLK9
#if SAM_GCLK9_ENABLE == TRUE
#if SAM_GCLK9_SRC == GCLK_GENCTRL_SRC_XOSC0
#define SAM_GCLK9_SRC_FREQ SAM_XOSC0_FREQ
#elif SAM_GCLK9_SRC == GCLK_GENCTRL_SRC_XOSC1
#define SAM_GCLK9_SRC_FREQ SAM_XOSC1_FREQ
#elif SAM_GCLK9_SRC == GCLK_GENCTRL_SRC_DPLL0
#define SAM_GCLK9_SRC_FREQ SAM_FDPLL0_OUTPUT_FREQ
#elif SAM_GCLK9_SRC == GCLK_GENCTRL_SRC_DPLL1
#define SAM_GCLK9_SRC_FREQ SAM_FDPLL1_OUTPUT_FREQ
#else
#error not supported configuration
#endif
#else
#define SAM_GCLK9_SRC_FREQ 0
#endif

// GCLK10
#if SAM_GCLK10_ENABLE == TRUE
#if SAM_GCLK10_SRC == GCLK_GENCTRL_SRC_XOSC0
#define SAM_GCLK10_SRC_FREQ SAM_XOSC0_FREQ
#elif SAM_GCLK10_SRC == GCLK_GENCTRL_SRC_XOSC1
#define SAM_GCLK10_SRC_FREQ SAM_XOSC1_FREQ
#elif SAM_GCLK10_SRC == GCLK_GENCTRL_SRC_DPLL0
#define SAM_GCLK10_SRC_FREQ SAM_FDPLL0_OUTPUT_FREQ
#elif SAM_GCLK10_SRC == GCLK_GENCTRL_SRC_DPLL1
#define SAM_GCLK8_SRC_FREQ SAM_FDPLL1_OUTPUT_FREQ
#else
#error not supported configuration
#endif
#else
#define SAM_GCLK10_SRC_FREQ 0
#endif

// GCLK11
#if SAM_GCLK11_ENABLE == TRUE
#if SAM_GCLK11_SRC == GCLK_GENCTRL_SRC_XOSC0
#define SAM_GCLK11_SRC_FREQ SAM_XOSC0_FREQ
#elif SAM_GCLK11_SRC == GCLK_GENCTRL_SRC_XOSC1
#define SAM_GCLK11_SRC_FREQ SAM_XOSC1_FREQ
#elif SAM_GCLK11_SRC == GCLK_GENCTRL_SRC_DPLL0
#define SAM_GCLK11_SRC_FREQ SAM_FDPLL0_OUTPUT_FREQ
#elif SAM_GCLK11_SRC == GCLK_GENCTRL_SRC_DPLL1
#define SAM_GCLK11_SRC_FREQ SAM_FDPLL1_OUTPUT_FREQ
#else
#error not supported configuration
#endif
#else
#define SAM_GCLK11_SRC_FREQ 0
#endif

#if (SAM_CPUDIV % 2 != 0) && SAM_CPUDIV > 1
#error invalid SAM_CPUDIV
#endif

#define SAM_CPU_FREQ SAM_GCLK0_FREQ / (SAM_CPUDIV)
#if SAM_CPU_FREQ > 120000000UL
#error CPU Frequency is over 120MHz
#endif

#define SAM_HS_FREQ SAM_GCLK0_FREQ

#if SAM_CPU_FREQ > 1000000UL
#define SAM_NVM_DELAY 3
#else
#define SAM_NVM_DELAY 0
#endif

#ifdef __cplusplus
extern "C" {
#endif
static inline uint32_t get_cpu_freq(void) {
  return SAM_CPU_FREQ;
}

void sam_gclk_init(uint32_t id, uint32_t sysctrl_src, uint16_t gendiv,
                   bool enable);
void sam_gclk_mux(uint32_t id, uint32_t dest, bool enable);
#ifdef __cplusplus
}
#endif

#endif