/*
    Copyright (C) 2025 Dimitris Mantzouranis

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
 * @file    ADC/hal_adc_lld.h
 * @brief   SN32 ADC subsystem low level driver header.
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
 * @name    ADC ADM register configuration helpers
 * @{
 */
//ADC Enable bit
#define ADC_ADENB_DIS           0x0
#define ADC_ADENB_EN            0x1

//ADC start control bit
#define ADC_ADS_STOP            0x0
#define ADC_ADS_START           0x1

//ADC End Of Conversion bit
#define ADC_EOC_BUSY            0x0
#define ADC_EOC_RESET           0x1

//ADC global channel select bit
#define ADC_GCHS_DIS            0x0
#define ADC_GCHS_EN             0x1

//ADC high reference voltage source select bit
#define ADC_AVREFHSEL_INTERNAL  0x0
#define ADC_AVREFHSEL_EXTERNAL  0x1
/** @} */

/**
 * @name    ADC Internal reference voltage level selection helpers
 * @{
 */
#define ADC_ADM_VREF_2_0V             0U // Internal 2.0V as ADC internal reference high voltage
#define ADC_ADM_VREF_3_0V             1U // Internal 3.0V as ADC internal reference high voltage
#define ADC_ADM_VREF_4_5V             2U // Internal 4.5V as ADC internal reference high voltage
#define ADC_ADM_VREF_VDD_2_0V_AIN     4U // VDD as ADC internal reference high voltage, Internal 2.0V as AIN
#define ADC_ADM_VREF_VDD_3_0V_AIN     5U // VDD as ADC internal reference high voltage, Internal 3.0V as AIN
#define ADC_ADM_VREF_VDD_4_5V_AIN     6U // VDD as ADC internal reference high voltage, Internal 4.5V as AIN
#define ADC_ADM_VREF_VDD              7U // VDD as ADC internal reference high voltage

/** @} */

/**
 * @name    ADC Interrupt register configuration helpers
 * @{
 */
// ADC Interrupt Enable register (ADC_IE)
#define ADC_IE_AIN(n)                   (1U << (n))
//ADC Raw Interrupt Status register(ADC_RIS)
#define mskADC_IF_AIN(n)                (1U << (n))

/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   ADC driver enable switch.
 * @details If set to @p TRUE the support for ADC is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SN32_ADC_USE_ADC1) || defined(__DOXYGEN__)
#define SN32_ADC_USE_ADC1                  FALSE
#endif

/**
 * @brief   ADC interrupt priority level setting.
 */
#if !defined(SN32_ADC_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SN32_ADC_IRQ_PRIORITY             3
#endif

/*
 * @brief   ADC prescaler setting.
 */
#if !defined(SN32_ADC_PRESCALER_VALUE) || defined(__DOXYGEN__)
#define SN32_ADC_PRESCALER_VALUE           1
#endif

/**
 * @brief   ADC wake-up procedure duration.
 */
#if !defined(SN32_USB_HOST_WAKEUP_DURATION) || defined(__DOXYGEN__)
#define SN32_ADC_WAKEUP_DURATION        100
#endif

/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Registry checks.*/
#if !defined(SN32_HAS_ADC)
#error "SN32_HAS_ADC not defined in registry"
#endif

#if !defined(SN32_ADC_HANDLER)
#error "SN32_ADC_HANDLER not defined in registry"
#endif

#if !defined(SN32_ADC_NUMBER)
#error "SN32_ADC_NUMBER not defined in registry"
#endif

/* ADC IRQ priority tests.*/
#if !OSAL_IRQ_IS_VALID_PRIORITY(SN32_ADC_ADC_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to ADC"
#endif

/* ADC clock source checks.*/
#if SN32_ADC_PRESCALER_VALUE == 1
#define SN32_ADC_PRESC                     0U
#elif SN32_ADC_PRESCALER_VALUE == 2
#define SN32_ADC_PRESC                     1U
#elif SN32_ADC_PRESCALER_VALUE == 4
#define SN32_ADC_PRESC                     2U
#elif SN32_ADC_PRESCALER_VALUE == 8
#define SN32_ADC_PRESC                     3U
#elif SN32_ADC_PRESCALER_VALUE == 16
#define SN32_ADC_PRESC                     5U
#elif SN32_ADC_PRESCALER_VALUE == 32
#define SN32_ADC_PRESC                     6U
#else
#error "Invalid value assigned to SN32_ADC_PRESCALER_VALUE"
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
 */
#define adc_lld_driver_fields                                               \
  /* Pointer to the ADCx registers block.*/                                 \
  SN_ADC_Type               *adc;                                           \
  /* @brief Number of samples expected. */                                  \
  size_t                    number_of_samples;                              \
  /* @brief Current position in the buffer. */                              \
  size_t                    current_index;                                  \
  /* @brief Current channel index into group channel_mask. */               \
  size_t                    current_channel

/**
 * @brief   Low level fields of the ADC configuration structure.
 */
#define adc_lld_config_fields                                               \
  /* Dummy configuration, it is not needed.*/                               \
  uint32_t                  dummy

/**
 * @brief   Low level fields of the ADC configuration structure.
 */
#define adc_lld_configuration_group_fields                                  \
  /* ADC VHS register initialization data.*/                                \
  uint32_t                  vhs;                                            \
  /* ADC ADLEN register initialization data.*/                              \
  uint32_t                  adlen;                                          \
  /* ADC AVREFHSEL register initialization data.*/                          \
  uint32_t                  avrefhsel;                                      \
  /* ADC CHS    register initialization data.                               \
     NOTE: The number of bits at logic level one in this register must      \
           be equal to the number in the @p num_channels field.*/           \
  uint32_t                  chs

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if SN32_ADC_USE_ADC1 && !defined(__DOXYGEN__)
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
  void adcSN32EnableAVREFHSEL(ADCDriver *adcp);
  void adcSN32DisableAVREFHSEL(ADCDriver *adcp);
  void adcSN32EnableGCHS(SN_ADC_Type *adc);
  void adcSN32DisableGCHS(SN_ADC_Type *adc);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_ADC */

#endif /* HAL_ADC_LLD_H */

/** @} */
