/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    Copyright (C) 2026 QMK

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
 * @file    SK32F0xx/hal_adc_lld.h
 * @brief   SK32F0xx ADC subsystem low level driver header.
 * @details The SK32F0xx embeds a single ADC1 unit with the classic STM32F0
 *          register set (ISR/IER/CR/CFGR1/CFGR2/SMPR/TR/CHSELR/DR plus the
 *          shared ADC_Common_TypeDef CCR register and the VREFSR register).
 *          Unlike the shared STM32 ADCv1 LLD this driver does not use a DMA
 *          stream: every EOC event is serviced in the ADC interrupt handler
 *          and the converted sample is read from the DR register, so no
 *          STM32 DMA support is required.  This driver is written directly
 *          against the vendor CMSIS header (@p sk32f0xx.h).
 *
 * @addtogroup ADC
 * @{
 */

#ifndef HAL_ADC_LLD_H
#define HAL_ADC_LLD_H

#if HAL_USE_ADC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Possible ADC errors mask bits
 * @{
 */
#define ADC_ERR_DMAFAILURE      1U  /**< DMA operations failure.            */
#define ADC_ERR_OVERFLOW        2U  /**< ADC overflow condition.            */
#define ADC_ERR_AWD1            4U  /**< Watchdog triggered.                */
/** @} */

/**
 * @name    Sampling rates
 * @note    On the SK32F0xx a single SMPR register field (SMP[2:0]) applies
 *          to every enabled channel, unlike the per-channel SMPRx registers
 *          of the bigger STM32 families.
 * @{
 */
#define ADC_SMPR_SMP_1P5        0U  /**< @brief 14 cycles conversion time.  */
#define ADC_SMPR_SMP_7P5        1U  /**< @brief 21 cycles conversion time.  */
#define ADC_SMPR_SMP_13P5       2U  /**< @brief 28 cycles conversion time.  */
#define ADC_SMPR_SMP_28P5       3U  /**< @brief 41 cycles conversion time.  */
#define ADC_SMPR_SMP_41P5       4U  /**< @brief 54 cycles conversion time.  */
#define ADC_SMPR_SMP_55P5       5U  /**< @brief 68 cycles conversion time.  */
#define ADC_SMPR_SMP_71P5       6U  /**< @brief 84 cycles conversion time.  */
#define ADC_SMPR_SMP_239P5      7U  /**< @brief 252 cycles conversion time. */
/** @} */

/**
 * @name    CFGR1 register configuration helpers
 * @note    The vendor CMSIS header only spells the raw RES_0/RES_1 bits,
 *          the resolution level helpers used in the conversion groups are
 *          defined here.
 * @{
 */
#define ADC_CFGR1_RES_12BIT             (0U << 3U)
#define ADC_CFGR1_RES_10BIT             (1U << 3U)
#define ADC_CFGR1_RES_8BIT              (2U << 3U)
#define ADC_CFGR1_RES_6BIT              (3U << 3U)

#define ADC_CFGR1_EXTSEL_MASK           (15U << 6U)
#define ADC_CFGR1_EXTSEL_SRC(n)         ((n) << 6U)

#define ADC_CFGR1_EXTEN_MASK            (3U << 10U)
#define ADC_CFGR1_EXTEN_DISABLED        (0U << 10U)
#define ADC_CFGR1_EXTEN_RISING          (1U << 10U)
#define ADC_CFGR1_EXTEN_FALLING         (2U << 10U)
#define ADC_CFGR1_EXTEN_BOTH            (3U << 10U)
/** @} */

/**
 * @name    CFGR2 register configuration helpers
 * @note    The SK32F0xx has no ADC prescaler in the CCR register: the ADC
 *          kernel clock is derived from the APB (PCLK) clock through the
 *          CFGR2 CKMODE[1:0] bits (the CMSIS comments name the single bits
 *          "PCLK div2" for bit 30 and "PCLK div4" for bit 31).
 * @{
 */
#define ADC_CFGR2_CKMODE_MASK           (3U << 30U)
#define ADC_CFGR2_CKMODE_ADCCLK         (0U << 30U)
#define ADC_CFGR2_CKMODE_PCLK_DIV2      (1U << 30U)
#define ADC_CFGR2_CKMODE_PCLK_DIV4      (2U << 30U)
/** @} */

/**
 * @name    Threshold register initializer
 * @{
 */
#define ADC_TR(low, high)               (((uint32_t)(high) << 16U) |        \
                                         (uint32_t)(low))
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   ADC1 driver enable switch.
 * @details If set to @p TRUE the support for ADC1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SK32_ADC_USE_ADC1) || defined(__DOXYGEN__)
#define SK32_ADC_USE_ADC1                   FALSE
#endif

/**
 * @brief   ADC1 CFGR2 initialization.
 * @note    The ADC kernel clock is the APB clock divided as specified by
 *          the CKMODE bits.  The default (PCLK/4 -> 18 MHz with the 72 MHz
 *          PCLK used by this platform) keeps the ADC inside its maximum
 *          conversion clock; it can be overridden in mcuconf.h.
 */
#if !defined(SK32_ADC_ADC1_CFGR2) || defined(__DOXYGEN__)
#define SK32_ADC_ADC1_CFGR2                 ADC_CFGR2_CKMODE_PCLK_DIV4
#endif

/**
 * @brief   ADC1 interrupt priority level setting.
 * @note    ARMv6-M (Cortex-M0) implements only 2 priority bits, the valid
 *          priority range is 0 (highest) .. 3 (lowest).
 */
#if !defined(SK32_ADC_ADC1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SK32_ADC_ADC1_IRQ_PRIORITY          2
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !defined(SK32_HAS_ADC1)
#define SK32_HAS_ADC1                       FALSE
#endif

#if SK32_ADC_USE_ADC1 && !SK32_HAS_ADC1
#error "ADC1 not present in the selected device"
#endif

#if !SK32_ADC_USE_ADC1
#error "ADC driver activated but no ADC peripheral assigned"
#endif

/* ADC1 IRQ priority tests.*/
#if SK32_ADC_USE_ADC1 && !defined(SK32_ADC1_SUPPRESS_ISR) &&                 \
    !OSAL_IRQ_IS_VALID_PRIORITY(SK32_ADC_ADC1_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to ADC1"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   ADC sample data type.
 */
typedef uint16_t adcsample_t;

/**
 * @brief   Channels number in a conversion group.
 */
typedef uint16_t adc_channels_num_t;

/**
 * @brief   Type of an ADC error mask.
 */
typedef uint32_t adcerror_t;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Low level fields of the ADC driver structure.
 * @note    The two @p isr_* fields implement the software sample counter
 *          used by the interrupt driven (DMA-less) conversion path.
 */
#define adc_lld_driver_fields                                               \
  /* Pointer to the ADCx registers block.*/                                 \
  ADC_TypeDef               *adc;                                           \
  /* Samples collected so far in the current conversion.*/                  \
  uint32_t                  isr_count;                                      \
  /* Total samples to collect (num_channels * depth).*/                     \
  uint32_t                  isr_total;

/**
 * @brief   Low level fields of the ADC driver configuration structure.
 */
#define adc_lld_config_fields                                               \
  /* Dummy configuration, it is not needed.*/                               \
  uint32_t                  dummy;

/**
 * @brief   Low level fields of the ADC conversion group configuration
 *          structure.
 */
#define adc_lld_configuration_group_fields                                  \
  /* ADC CFGR1 register initialization data.                                \
     NOTE: The bits @p ADC_CFGR1_CONT or @p ADC_CFGR1_DISCEN must be        \
           specified in continuous mode or if the buffer depth is           \
           greater than one.*/                                              \
  uint32_t                  cfgr1;                                          \
  /* ADC TR register initialization data.*/                                 \
  uint32_t                  tr;                                             \
  /* ADC SMPR register initialization data.*/                               \
  uint32_t                  smpr;                                           \
  /* ADC CHSELR register initialization data.                               \
     NOTE: The number of bits at logic level one in this register must      \
           be equal to the number in the @p num_channels field.*/           \
  uint32_t                  chselr;

/**
 * @brief   Changes the value of the ADC CCR register.
 * @details Use this function in order to enable or disable the internal
 *          analog sources (VREFINT, temperature sensor).  See the
 *          documentation in the device reference manual.
 */
#define adcSK32SetCCR(ccr) (ADC->CCR = (ccr))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if SK32_ADC_USE_ADC1 && !defined(__DOXYGEN__)
extern ADCDriver ADCD1;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void adc_lld_init(void);
  void adc_lld_start(ADCDriver *adcp);
  void adc_lld_stop(ADCDriver *adcp);
  void adc_lld_start_conversion(ADCDriver *adcp);
  void adc_lld_stop_conversion(ADCDriver *adcp);
  void adc_lld_serve_interrupt(ADCDriver *adcp);
  void adcSK32EnableVREF(ADCDriver *adcp);
  void adcSK32DisableVREF(ADCDriver *adcp);
  void adcSK32EnableTS(ADCDriver *adcp);
  void adcSK32DisableTS(ADCDriver *adcp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_ADC */

#endif /* HAL_ADC_LLD_H */

/** @} */
