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
 * @file    ADCv1/hal_adc_lld.h
 * @brief   ES32 ADC subsystem low level driver header.
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
  ADC_TypeDef               *adc;                                           \
  /* Pointer to associated DMA channel.*/                                   \
  const void  *dmastp;                                        \
  /* DMA mode bit mask.*/                                                   \
  uint32_t                  dmamode

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
  /* ADC CFGR1 register initialization data.                                \
     NOTE: The bits DMAEN and DMACFG are enforced internally                \
           to the driver, keep them to zero.                                \
     NOTE: The bits @p ADC_CFGR1_CONT or @p ADC_CFGR1_DISCEN must be        \
           specified in continuous more or if the buffer depth is           \
           greater than one.*/                                              \
  uint32_t                  cfgr1;                                          \
  /* ADC TR register initialization data.*/                                 \
  uint32_t                  tr;                                             \
  /* ADC SMPR register initialization data.*/                               \
  uint32_t                  smpr;                                           \
  /* ADC CHSELR register initialization data.                               \
     NOTE: The number of bits at logic level one in this register must      \
           be equal to the number in the @p num_channels field.*/           \
  uint32_t                  chselr


/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if ES32_ADC_USE_ADC1 && !defined(__DOXYGEN__)

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
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_ADC */

#endif /* HAL_ADC_LLD_H */

/** @} */
