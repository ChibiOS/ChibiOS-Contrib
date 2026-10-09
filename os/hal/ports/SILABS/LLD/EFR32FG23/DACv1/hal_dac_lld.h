/*
    ChibiOS - Copyright (C) 2024 Xael South

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
 * @file    hal_dac_lld.h
 * @brief   EFR32 DAC subsystem low level driver header.
 *
 * @addtogroup DAC
 * @{
 */

#ifndef HAL_DAC_LLD_H
#define HAL_DAC_LLD_H

#if (HAL_USE_DAC == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#define DAC_LLD_ENHANCED_API

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   Enables the DAC dual mode.
 * @note    In dual mode DAC second channels cannot be accessed individually.
 */
#if !defined(EFR32_DAC_DUAL_MODE) || defined(__DOXYGEN__)
#define EFR32_DAC_DUAL_MODE                 FALSE
#endif

/**
 * @brief   DAC1 CH1 driver enable switch.
 * @details If set to @p TRUE the support for DAC1 channel 1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(EFR32_DAC_USE_DAC1_CH1) || defined(__DOXYGEN__)
#define EFR32_DAC_USE_DAC1_CH1              FALSE
#endif

/**
 * @brief   DAC1 CH2 driver enable switch.
 * @details If set to @p TRUE the support for DAC1 channel 2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(EFR32_DAC_USE_DAC1_CH2) || defined(__DOXYGEN__)
#define EFR32_DAC_USE_DAC1_CH2              FALSE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if EFR32_DAC_USE_DAC1_CH1 && !EFR32_HAS_DAC1_CH1
#error "DAC1 CH1 not present in the selected device"
#endif

#if EFR32_DAC_USE_DAC1_CH2 && !EFR32_HAS_DAC1_CH2
#error "DAC1 CH2 not present in the selected device"
#endif

#if !defined(EFR32_DMA_REQUIRED)
#define EFR32_DMA_REQUIRED
#endif

/**
 * @brief   Maximum number of DAC channels per unit.
 */
#if EFR32_DAC_DUAL_MODE == TRUE
#define DAC_MAX_CHANNELS                    2
#else
#define DAC_MAX_CHANNELS                    1
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a DAC channel index.
 */
typedef uint32_t dacchannel_t;

/**
 * @brief   Type representing a DAC sample.
 */
typedef uint16_t dacsample_t;

/**
 * @brief   Possible DAC failure causes.
 * @note    Error codes are architecture dependent and should not relied
 *          upon.
 */
typedef enum {
  DAC_ERR_DMAFAILURE = 0,                   /**< DMA operations failure.    */
  DAC_ERR_UNDERFLOW = 1                     /**< DAC overflow condition.    */
} dacerror_t;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Low level fields of the DAC driver structure.
 */
#define dac_lld_driver_fields                                               \
  /* Dummy field, it is not needed.*/                                       \
  uint32_t                  dummy

/**
 * @brief   Low level fields of the DAC configuration structure.
 */
#define dac_lld_config_fields                                               \
  /* Dummy configuration, it is not needed.*/                               \
  uint32_t                  dummy

/**
 * @brief   Low level fields of the DAC group configuration structure.
 */
#define dac_lld_conversion_group_fields                                     \
  /* Dummy configuration, it is not needed.*/                               \
  uint32_t                  dummy

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if EFR32_DAC_USE_DAC1_CH1 && !defined(__DOXYGEN__)
extern DACDriver DACD1;
#endif

#if EFR32_DAC_USE_DAC1_CH2 && !EFR32_DAC_DUAL_MODE && !defined(__DOXYGEN__)
extern DACDriver DACD2;
#endif


#ifdef __cplusplus
extern "C" {
#endif
  void  dac_lld_init(void);
  msg_t dac_lld_start(DACDriver *dacp);
  void  dac_lld_stop(DACDriver *dacp);
  msg_t dac_lld_put_channel(DACDriver *dacp,
                           dacchannel_t channel,
                           dacsample_t sample);
  msg_t dac_lld_start_conversion(DACDriver *dacp);
  void  dac_lld_stop_conversion(DACDriver *dacp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_DAC == TRUE */

#endif /* HAL_DAC_LLD_H */

/** @} */
