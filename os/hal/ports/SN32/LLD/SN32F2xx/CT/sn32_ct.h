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
 * @file    CT/sn32_ct.h
 * @brief   SN32 CT units common header.
 * @note    This file requires definitions from the SN32 header file.
 *
 * @{
 */

#ifndef SN32_CT_H
#define SN32_CT_H

#include <SN32F2xx.h>

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    CT units references
 * @{
 */
#if !defined(SN32_HAS_CT16B0)
#   define SN32_HAS_CT16B0                      FALSE
#endif
#if !defined(SN32_HAS_CT16B1)
#   define SN32_HAS_CT16B1                      FALSE
#endif
#if !defined(SN32_HAS_CT16B2)
#   define SN32_HAS_CT16B2                      FALSE
#endif
#if !defined(SN32_HAS_CT16B3)
#   define SN32_HAS_CT16B3                      FALSE
#endif
#if !defined(SN32_HAS_CT16B4)
#   define SN32_HAS_CT16B4                      FALSE
#endif
#if !defined(SN32_HAS_CT16B5)
#   define SN32_HAS_CT16B5                      FALSE
#endif

#if defined(SN32F240)
#   define SN32_CT16_PRE_LIMIT         UINT16_MAX
#   define SN32_CT16_TC_LIMIT          UINT16_MAX
#   define SN32_CT32_PRE_LIMIT         UINT32_MAX
#   define SN32_CT32_TC_LIMIT          UINT32_MAX
#   define SN32_CT16B0_CHANNELS        4
#   define SN32_CT16B1_CHANNELS        4
#   define SN32_CT16B2_CHANNELS        4
#   define SN32_CT32B0_CHANNELS        4
#   define SN32_CT32B1_CHANNELS        4
#   define SN32_CT32B2_CHANNELS        4
#   define SN32_CT32_MAX_CHANNELS      4
#   define SN32_CT16B0_MAX_CHANNELS    4
#   define SN32_CT16B1_MAX_CHANNELS    4
#   define SN32_CT16B2_MAX_CHANNELS    4
#   define SN32_CT16B0                 ((sn32_ct16b0_240_t *)SN_CT16B0_BASE)
#   define SN32_CT16B1                 ((sn32_ct16b0_240_t *)SN_CT16B1_BASE)
#   define SN32_CT16B2                 ((sn32_ct16b0_240_t *)SN_CT16B2_BASE)
#   define SN32_CT32B0                 ((sn32_ct32_t *)SN_CT32B0_BASE)
#   define SN32_CT32B1                 ((sn32_ct32_t *)SN_CT32B1_BASE)
#   define SN32_CT32B2                 ((sn32_ct32_t *)SN_CT32B2_BASE)
#elif (defined(SN32F240B)|| defined(SN32F240C))
#   define SN32_CT16_PRE_LIMIT         UINT8_MAX
#   define SN32_CT16_TC_LIMIT          UINT16_MAX
#   define SN32_CT16B0_CHANNELS        1
#   define SN32_CT16B1_CHANNELS        25
#   define SN32_CT16B0_MAX_CHANNELS    24
#   define SN32_CT16B1_MAX_CHANNELS    25
#   define SN32_CT16B0                 ((sn32_ct16b0_240b_t *)SN_CT16B0_BASE)
#   define SN32_CT16B1                 ((sn32_ct16b1_240b_t *)SN_CT16B1_BASE)
#elif defined(SN32F260)
#   define SN32_CT16_PRE_LIMIT         UINT8_MAX
#   define SN32_CT16_TC_LIMIT          UINT16_MAX
#   define SN32_CT16B0_CHANNELS        1
#   define SN32_CT16B1_CHANNELS        24
#   define SN32_CT16B0_MAX_CHANNELS    24
#   define SN32_CT16B1_MAX_CHANNELS    25
#   define SN32_CT16B0                 ((sn32_ct16b0_240b_t *)SN_CT16B0_BASE)
#   define SN32_CT16B1                 ((sn32_ct16b1_240b_t *)SN_CT16B1_BASE)
#elif (defined(SN32F280) || defined(SN32F290))
#   define SN32_CT16_PRE_LIMIT         UINT16_MAX
#   define SN32_CT16_TC_LIMIT          UINT16_MAX
#   define SN32_CT16B0_CHANNELS        5
#   define SN32_CT16B1_CHANNELS        13
#   define SN32_CT16B2_CHANNELS        5
#   define SN32_CT16B3_CHANNELS        5
#   define SN32_CT16B4_CHANNELS        5
#   define SN32_CT16B5_CHANNELS        5
#   define SN32_CT16B0_PWMN_CHANNELS   4
#   define SN32_CT16B3_PWMN_CHANNELS   2
#   define SN32_CT16B4_PWMN_CHANNELS   2
#   define SN32_CT16B0_MAX_CHANNELS    25
#   define SN32_CT16B1_MAX_CHANNELS    25
#   define SN32_CT16B2_MAX_CHANNELS    25
#   define SN32_CT16B3_MAX_CHANNELS    25
#   define SN32_CT16B4_MAX_CHANNELS    25
#   define SN32_CT16B5_MAX_CHANNELS    25
#   define SN32_CT16B0                 ((sn32_ct16b0_290_t *)SN_CT16B0_BASE)
#   define SN32_CT16B1                 ((sn32_ct16b1_290_t *)SN_CT16B1_BASE)
#   define SN32_CT16B2                 ((sn32_ct16b0_240b_t *)SN_CT16B2_BASE)
#   define SN32_CT16B3                 ((sn32_ct16b3_290_t *)SN_CT16B3_BASE)
#   define SN32_CT16B4                 ((sn32_ct16b3_290_t *)SN_CT16B4_BASE)
#   define SN32_CT16B5                 ((sn32_ct16b5_290_t *)SN_CT16B5_BASE)
#else
#   error "CT not supported in the selected device"
#endif

/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   SN32 CT registers block.
 * @note    This is the most general known form, not all timers have
 *          necessarily all registers and bits.
 */
// Configuration registers block
typedef struct {
    volatile uint32_t TMRCTRL;
    volatile uint32_t TC;
    volatile uint32_t PRE;
    volatile uint32_t PC;
    volatile uint32_t CNTCTRL;
} sn32_ct_config_t;

// Match control block
typedef struct {
    volatile uint32_t MCTRL;
#if !defined(SN32F240)
    volatile uint32_t MCTRL2;
    volatile uint32_t MCTRL3;
#endif
} sn32_ct_match_t;

// Capture control block
typedef struct {
    volatile uint32_t CAPCTRL;
    volatile uint32_t CAP0;
} sn32_ct_capture_t;

// External match control block
typedef struct {
    volatile uint32_t EM;
#if !defined(SN32F240)
    volatile uint32_t EMC;
    volatile uint32_t EMC2;
#endif
} sn32_ct_em_t;

// PWM control block
typedef struct {
    volatile uint32_t PWMCTRL;
#if !defined(SN32F240)
    volatile uint32_t PWMCTRL2;
    volatile uint32_t PWMENB;
    volatile uint32_t PWMIOENB;
#endif
} sn32_ct_pwm_t;

// IRQ control block
typedef struct {
    volatile uint32_t RIS;
    volatile uint32_t IC;
} sn32_ct_irq_t;

#if defined(SN32F240)
typedef struct {
    sn32_ct_config_t config;  // Configuration registers
    sn32_ct_match_t match;    // Match control registers
    volatile uint32_t MR[SN32_CT16B0_CHANNELS];
    sn32_ct_capture_t cap;    // Capture registers
    sn32_ct_em_t em;          // External match control
    sn32_ct_pwm_t pwm;        // PWM control registers
    sn32_ct_irq_t irq;        // IRQ control registers
} sn32_ct16b0_240_t;
typedef struct {
    sn32_ct_config_t config;  // Configuration registers
    sn32_ct_match_t match;    // Match control registers
    volatile uint32_t MR[SN32_CT32_MAX_CHANNELS];
    sn32_ct_capture_t cap;    // Capture registers
    sn32_ct_em_t em;          // External match control
    sn32_ct_pwm_t pwm;        // PWM control registers
    sn32_ct_irq_t irq;        // IRQ control registers
} sn32_ct32_t;
#endif
#if (defined(SN32F240B) || defined(SN32F240C) || defined(SN32F260) || defined(SN32F280) || defined(SN32F290))
typedef struct {
    sn32_ct_config_t config;  // Configuration registers
    sn32_ct_match_t match;    // Match control registers
    volatile uint32_t MR[SN32_CT16B0_CHANNELS];
#if (SN32_CT16B0_CHANNELS != SN32_CT16B0_MAX_CHANNELS)
    volatile const uint32_t RESERVED[SN32_CT16B0_MAX_CHANNELS - SN32_CT16B0_CHANNELS];
#endif
    sn32_ct_capture_t cap;    // Capture registers
    sn32_ct_em_t em;          // External match control
    sn32_ct_pwm_t pwm;        // PWM control registers
    sn32_ct_irq_t irq;        // IRQ control registers
} sn32_ct16b0_240b_t;
#endif
#if (defined(SN32F280) || defined(SN32F290))
typedef struct {
    sn32_ct_config_t config;  // Configuration registers
    sn32_ct_match_t match;    // Match control registers
    volatile uint32_t MR[SN32_CT16B0_CHANNELS];
#if (SN32_CT16B0_CHANNELS != SN32_CT16B0_MAX_CHANNELS)
    volatile const uint32_t RESERVED[SN32_CT16B0_MAX_CHANNELS - SN32_CT16B0_CHANNELS];
#endif
    sn32_ct_capture_t cap;    // Capture registers
    sn32_ct_em_t em;          // External match control
    sn32_ct_pwm_t pwm;        // PWM control registers
    sn32_ct_irq_t irq;        // IRQ control registers
    volatile uint32_t PWMmNIOCTRL;
    volatile uint32_t PWMnNDB[SN32_CT16B0_PWMN_CHANNELS];
} sn32_ct16b0_290_t;
#endif
#if (defined(SN32F240B) || defined(SN32F240C) || defined(SN32F260))
typedef struct {
    sn32_ct_config_t config;  // Configuration registers
    sn32_ct_match_t match;    // Match control registers
    volatile uint32_t MR[SN32_CT16B1_CHANNELS];
#if (SN32_CT16B1_CHANNELS != SN32_CT16B1_MAX_CHANNELS)
    volatile const uint32_t RESERVED[SN32_CT16B1_MAX_CHANNELS - SN32_CT16B1_CHANNELS];
#endif
    volatile const uint32_t RESERVED1;
    sn32_ct_em_t em;          // External match control
    sn32_ct_pwm_t pwm;        // PWM control registers
    sn32_ct_irq_t irq;        // IRQ control registers
} sn32_ct16b1_240b_t;
#endif
#if (defined(SN32F280) || defined(SN32F290))
typedef struct {
    sn32_ct_config_t config;  // Configuration registers
    sn32_ct_match_t match;    // Match control registers
    volatile uint32_t MR[SN32_CT16B1_CHANNELS];
#if (SN32_CT16B1_CHANNELS != SN32_CT16B1_MAX_CHANNELS)
    volatile const uint32_t RESERVED[SN32_CT16B1_MAX_CHANNELS - SN32_CT16B1_CHANNELS];
#endif
    sn32_ct_capture_t cap;    // Capture registers
    sn32_ct_em_t em;          // External match control
    sn32_ct_pwm_t pwm;        // PWM control registers
    sn32_ct_irq_t irq;        // IRQ control registers
} sn32_ct16b1_290_t;

typedef struct {
    sn32_ct_config_t config;  // Configuration registers
    sn32_ct_match_t match;    // Match control registers
    volatile uint32_t MR[SN32_CT16B0_CHANNELS];
#if (SN32_CT16B3_CHANNELS != SN32_CT16B3_MAX_CHANNELS)
    volatile const uint32_t RESERVED[SN32_CT16B3_MAX_CHANNELS - SN32_CT16B3_CHANNELS];
#endif
    sn32_ct_capture_t cap;    // Capture registers
    sn32_ct_em_t em;          // External match control
    sn32_ct_pwm_t pwm;        // PWM control registers
    sn32_ct_irq_t irq;        // IRQ control registers
    volatile uint32_t PWMmNIOCTRL;
    volatile uint32_t PWMnNDB[SN32_CT16B3_PWMN_CHANNELS];
} sn32_ct16b3_290_t;

typedef struct {
    sn32_ct_config_t config;  // Configuration registers
    sn32_ct_match_t match;    // Match control registers
    volatile uint32_t MR[SN32_CT16B5_CHANNELS];
#if (SN32_CT16B5_CHANNELS != SN32_CT16B5_MAX_CHANNELS)
    volatile const uint32_t RESERVED[SN32_CT16B5_MAX_CHANNELS - SN32_CT16B5_CHANNELS];
#endif
    sn32_ct_capture_t cap;    // Capture registers
    sn32_ct_em_t em;          // External match control
    sn32_ct_pwm_t pwm;        // PWM control registers
    sn32_ct_irq_t irq;        // IRQ control registers
} sn32_ct16b5_290_t;
#endif
/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/
/* CT16Bn Timer Control register <CT16Bn_TMRCTRL> (0x00) */
#define CT16_CEN_DIS                   0 //[0:0] CT16Bn enable bit
#define CT16_CEN_EN                    1
#define mskCT16_CEN_DIS                (CT16_CEN_DIS<<0)
#define mskCT16_CEN_EN                 (CT16_CEN_EN<<0)

#define CT16_CRST                      1 //[1:1] CT16Bn counter reset bit
#define mskCT16_CRST                   (CT16_CRST<<1)

#define CT16_CLKSEL_HCLK               0 //[2:2] CT16Bn PCLK source
#define CT16_CLKSEL_PLL_VCO            1
#define CT16_CLKSEL_ILRC               2
#define mskCT16_CLKSEL_HCLK            (CT16_CLKSEL_HCLK << 2)
#define mskCT16_CLKSEL_PLL_VCO         (CT16_CLKSEL_PLL_VCO << 2)
#define mskCT16_CLKSEL_ILRC            (CT16_CLKSEL_ILRC << 2)

#define CT16_PWM_KEY                   (0x5A << 24)
#define CT16_PWM_UNLOCK(value)         ((CT16_PWM_KEY) | ((value) & 0x00FFFFFF))

//[6:4] CT16Bn counting mode selection
#define CT16_CM_EDGE_UP                0 // Edge-aligned Up-counting mode
#define CT16_CM_EDGE_DOWN              1 // Edge-aligned Down-counting mode
#define CT16_CM_CENTER_UP              2 // Center-aligned mode 1. Match interrupt is set during up-counting period
#define CT16_CM_CENTER_DOWN            4 // Center-aligned mode 2. Match interrupt is set during down-counting period
#define CT16_CM_CENTER_BOTH            6 // Center-aligned mode 3. Match interrupt is set during both up and down period.
#define mskCT16_CM_EDGE_UP             (CT16_CM_EDGE_UP<<4)
#define mskCT16_CM_EDGE_DOWN           (CT16_CM_EDGE_DOWN<<4)
#define mskCT16_CM_CENTER_UP           (CT16_CM_CENTER_UP<<4)
#define mskCT16_CM_CENTER_DOWN         (CT16_CM_CENTER_DOWN<<4)
#define mskCT16_CM_CENTER_BOTH         (CT16_CM_CENTER_BOTH<<4)

/* CT16Bn Count Control register <CT16Bn_CNTCTRL> (0x10) */
//[1:0] Count/Timer Mode selection.
#define CT16_CTM_TIMER                 0 // Timer mode: Every rising PCLK edge.
#define CT16_CTM_CNTER_RISING          1 // Counter mode: TC increments on rising edge of CAP input.
#define CT16_CTM_CNTER_FALLING         2 // Counter mode: TC increments on falling edge of CAP input.
#define CT16_CTM_CNTER_BOTH            3 // Counter mode: TC increments on both edge of CAP input.
#define mskCT16_CTM_TIMER              (CT16_CTM_TIMER<<0)
#define mskCT16_CTM_CNTER_RISING       (CT16_CTM_CNTER_RISING<<0)
#define mskCT16_CTM_CNTER_FALLING      (CT16_CTM_CNTER_FALLING<<0)
#define mskCT16_CTM_CNTER_BOTH         (CT16_CTM_CNTER_BOTH<<0)

#define CT16_CIS                       0 //[3:2] Count Input Select
#define mskCT16_CIS                    (CT16_CIS<<2)

/* CT16Bn Match Control register <CT16Bn_MCTRL> (0x14) */
#define CT16_MRnIE_EN                  1 // Enable MRn match interrupt
#define CT16_MRnIE_DIS                 0
#define mskCT16_MRnIE_EN(n)            (CT16_MRnIE_EN<<((n % 10) *3))
#define mskCT16_MRnIE_DIS(n)           (CT16_MRnIE_DIS<<((n % 10) *3))

#define CT16_MRnRST_EN                 1 // Enable reset TC when MRn matches TC.
#define CT16_MRnRST_DIS                0
#define mskCT16_MRnRST_EN(n)           (CT16_MRnRST_EN<<(((n % 10) *3) +1))
#define mskCT16_MRnRST_DIS(n)          (CT16_MRnRST_DIS<<(((n % 10) *3) +1))

#define CT16_MRnSTOP_EN                1 // Enable stop TC and clear CEN when MRn matches TC.
#define CT16_MRnSTOP_DIS               0
#define mskCT16_MRnSTOP_EN(n)          (CT16_MRnSTOP_EN<<(((n % 10) *3) +2))
#define mskCT16_MRnSTOP_DIS(n)         (CT16_MRnSTOP_DIS<<(((n % 10) *3) +2))

/* CT16Bn Capture Control register <CT16Bn_CAPCTRL> (0x80) */
#define CT16_CAP0RE_EN                 1 //[0:0] Enable CAP0 capture on rising edge.
#define CT16_CAP0RE_DIS                0
#define mskCT16_CAP0RE_EN              (CT16_CAP0RE_EN<<0)
#define mskCT16_CAP0RE_DIS             (CT16_CAP0RE_DIS<<0)

#define CT16_CAP0FE_EN                 1 //[1:1] Enable CAP0 capture on fallng edge.
#define CT16_CAP0FE_DIS                0
#define mskCT16_CAP0FE_EN              (CT16_CAP0FE_EN<<1)
#define mskCT16_CAP0FE_DIS             (CT16_CAP0FE_DIS<<1)

#define CT16_CAP0IE_EN                 1 //[2:2] Enable CAP0 interrupt.
#define CT16_CAP0IE_DIS                0
#define mskCT16_CAP0IE_EN              (CT16_CAP0IE_EN<<2)
#define mskCT16_CAP0IE_DIS             (CT16_CAP0IE_DIS<<2)

#define CT16_CAP0EN_EN                 1 //[3:3] Enable CAP0 function.
#define CT16_CAP0EN_DIS                0
#define mskCT16_CAP0EN_EN              (CT16_CAP0EN_EN<<3)
#define mskCT16_CAP0EN_DIS             (CT16_CAP0EN_DIS<<3)

/* CT16Bn External Match register <CT16Bn_EM> (0x88) */
#define CT16_EMn                       1 // CT16Bn PWMn drive state
#define mskCT16_EM(n)                  (CT16_EMn<<n)
/* CT16Bn PWM Control register <CT16Bn_PWMCTRL> (0x94) */
#define CT16_PWMnMODE_1                0 // PWM mode 1.
#define CT16_PWMnMODE_2                1 // PWM mode 2.
#define CT16_PWMnMODE_FORCE_0          2 // Force 0.
#define CT16_PWMnMODE_FORCE_1          3 // Force 1.
#define mskCT16_PWMnMODE_1(n)          (CT16_PWMnMODE_1<<((n % 16) *2))
#define mskCT16_PWMnMODE_2(n)          (CT16_PWMnMODE_2<<((n % 16) *2))
#define mskCT16_PWMnMODE_FORCE_0(n)    (CT16_PWMnMODE_FORCE_0<<((n % 16) *2))
#define mskCT16_PWMnMODE_FORCE_1(n)    (CT16_PWMnMODE_FORCE_1<<((n % 16) *2))
/* CT16Bn PWM Enable register <CT16Bn_PWMENB> (0x9C) */
#define CT16_PWMnEN_EN                 1 // CT16Bn PWMn is enabled for PWM mode.
#define CT16_PWMnEN_EMn                0 // CT16Bn PWMn is controlled by EMn.
#define mskCT16_PWMnEN_EN(n)           (CT16_PWMnEN_EN<<n)
#define mskCT16_PWMnEN_EM0(n)          (CT16_PWMnEN_EM0<<n)
/* CT16Bn PWM IO Enable register <CT16Bn_PWMIOENB> (0xA0) */
#define CT16_PWMnIOEN_EN               1 // PWMn pin acts as match output.
#define CT16_PWMnIOEN_DIS              0 // PWMn pin acts as GPIO.
#define mskCT16_PWMnIOEN_EN(n)         (CT16_PWMnIOEN_EN<<n)
#define mskCT16_PWMnIOEN_DIS(n)        (CT16_PWMnIOEN_DIS<<n)
/* CT16Bn External Match Control register <CT16Bn_EMC> (0x8C) */
#define CT16_EMCn_DO_NOTHING           0   //Do nothing.
#define CT16_EMCn_LOW                  1   //CT16Bn PWM0 pin is low.
#define CT16_EMCn_HIGH                 2   //CT16Bn PWM0 pin is high.
#define CT16_EMCn_TOGGLE               3   //Toggle CT16Bn PWM0 pin.
#define mskCT16_EMCn_DO_NOTHING(n)     (CT16_EMCn_LOW<<((n % 16) *2))
#define mskCT16_EMCn_LOW(n)            (CT16_EMCn_LOW<<((n % 16) *2))
#define mskCT16_EMCn_HIGH(n)           (CT16_EMCn_HIGH<<((n % 16) *2))
#define mskCT16_EMCn_TOGGLE(n)         (CT16_EMCn_TOGGLE<<((n % 16) *2))
/* CT16Bn Timer Raw Interrupt Status register <CT16Bn_RIS> (0xA4) */
/* CT16Bn Timer Interrupt Clear register <CT16Bn_IC> (0xA8) */
/* The bitmask usage of iwCT16Bn_IrqEvent is the same with CT16Bn_RIS*/
#define mskCT16_MRnIF(n)               (0x1<<n) // Interrupt flag for match channel n
#define mskCT16_MRnIC(n)               mskCT16_MRnIF(n)
#define mskCT_IC_Clear(n)              ((1U << (n)) - 1)

#define SN32_CT_ResetTimer(timer)                            \
  do {                                                       \
      timer->config.TMRCTRL = (mskCT16_CRST);                \
      while (timer->config.TMRCTRL & mskCT16_CRST);          \
  } while (0)

#if defined(SN32_HAS_CT16B0)
#   define CT16B0_ResetTimer()     SN32_CT_ResetTimer(SN32_CT16B0)
#endif
#if defined(SN32_HAS_CT16B1)
#   define CT16B1_ResetTimer()     SN32_CT_ResetTimer(SN32_CT16B1)
#endif
#if defined(SN32_HAS_CT16B2)
#   define CT16B2_ResetTimer()     SN32_CT_ResetTimer(SN32_CT16B2)
#endif
#if defined(SN32_HAS_CT16B3)
#   define CT16B3_ResetTimer()     SN32_CT_ResetTimer(SN32_CT16B3)
#endif
#if defined(SN32_HAS_CT16B4)
#   define CT16B4_ResetTimer()     SN32_CT_ResetTimer(SN32_CT16B4)
#endif
#if defined(SN32_HAS_CT16B5)
#   define CT16B5_ResetTimer()     SN32_CT_ResetTimer(SN32_CT16B5)
#endif

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#endif /* SN32_CT_H */

/** @} */
