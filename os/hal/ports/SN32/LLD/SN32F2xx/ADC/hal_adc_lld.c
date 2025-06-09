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
 * @file    ADC/hal_adc_lld.c
 * @brief   SN32 ADC subsystem low level driver source.
 *
 * @addtogroup ADC
 * @{
 */

#include "hal.h"

#if HAL_USE_ADC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief ADC driver identifier.*/
#if SN32_ADC_USE_ADC1 || defined(__DOXYGEN__)
ADCDriver ADCD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/
#define ADC_CHANNEL_MASK 0x0F
/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Stops an ongoing conversion, if any.
 *
 * @param[in] adc       pointer to the ADC registers block
 */
static void adc_lld_stop_adc(SN_ADC_Type *adc) {

  if (adc->ADM_b.EOC == ADC_EOC_BUSY) {
    adc->ADM_b.EOC = ADC_EOC_RESET;
    adc->IE = 0;
  }
  adcSN32DisableGCHS(adc);
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if SN32_ADC_USE_ADC1 || defined(__DOXYGEN__)
#if !defined(SN32_ADC_HANDLER)
#error "SN32_ADC_HANDLER not defined"
#endif
/**
 * @brief   ADC interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SN32_ADC_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  adc_lld_serve_interrupt(&ADCD1);

#if defined(SN32_ADC_ADC1_IRQ_HOOK)
  SN32_ADC_ADC1_IRQ_HOOK
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level ADC driver initialization.
 *
 * @notapi
 */
void adc_lld_init(void) {

#if SN32_ADC_USE_ADC1
  /* Driver initialization.*/
  adcObjectInit(&ADCD1);
  ADCD1.adc     = SN_ADC;
  /* The vector is initialized on driver initialization and never
     disabled.*/
  nvicEnableVector(SN32_ADC_NUMBER, SN32_ADC_IRQ_PRIORITY);
#endif
}

/**
 * @brief   Configures and activates the ADC peripheral.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_start(ADCDriver *adcp) {

  /* If in stopped state then enables the ADC peripheral and clock.*/
  if (adcp->state == ADC_STOP) {
#if SN32_ADC_USE_ADC1
    if (&ADCD1 == adcp) {
      sys1EnableADC();
      adcp->adc->ADM_b.ADENB = ADC_ADENB_EN;
      osalThreadSleepMicroseconds(SN32_ADC_WAKEUP_DURATION);
      /* Clock settings.*/
      adcp->adc->ADM_b.ADCKS = SN32_ADC_PRESC;
    }
#endif /* SN32_ADC_USE_ADC1 */
  }
}

/**
 * @brief   Deactivates the ADC peripheral.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_stop(ADCDriver *adcp) {

  /* If in ready state then disables the ADC peripheral and clock.*/
  if (adcp->state == ADC_READY) {

    /* Disabling the ADC.*/
    adc_lld_stop_adc(adcp->adc);
    adcp->adc->ADM_b.ADENB = ADC_ADENB_DIS;
    while ((adcp->adc->ADM_b.ADENB & ADC_ADENB_EN) != 0U) {
    /* Waiting for ADC to be disabled.*/
    }

#if SN32_ADC_USE_ADC1
    if (&ADCD1 == adcp) {
      sys1DisableADC();
    }
#endif
  }
}

/**
 * @brief   Starts an ADC conversion.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_start_conversion(ADCDriver *adcp) {
  const ADCConversionGroup *grpp = adcp->grpp;

  /* Apply ADC configuration.*/
  if(grpp->avrefhsel) adcSN32EnableAVREFHSEL(adcp);
  adcp->adc->ADM_b.VHS  = grpp->vhs;
  adcSN32EnableGCHS(adcp->adc);
  adcp->adc->ADM_b.ADLEN  = grpp->adlen;

  adcp->number_of_samples = adcp->depth * grpp->num_channels;
  adcp->current_index = 0;

  /* Skip to the next channel */
  adcp->current_channel = 0;
  while (((1 << adcp->current_channel) & grpp->chs) == 0) {
    adcp->current_channel = (adcp->current_channel + 1) & ADC_CHANNEL_MASK;
  }

  /* Select ADC channel. */
  adcp->adc->ADM_b.CHS = adcp->current_channel;

  /* Enable ADC interrupt. */
  adcp->adc->RIS = 0U;
  adcp->adc->IE = ADC_IE_AIN(adcp->current_channel);

  /* ADC conversion start.*/
  adcp->adc->ADM_b.ADS |= ADC_ADS_START;
}

/**
 * @brief   Stops an ongoing conversion.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_stop_conversion(ADCDriver *adcp) {

  adc_lld_stop_adc(adcp->adc);
}

/**
 * @brief   ISR code.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_serve_interrupt(ADCDriver *adcp) {

  /* Disable Interrupt, Disable Channel */
  adcp->adc->IE = 0U;
  adcp->adc->ADM_b.CHS = 0U;
  adcp->adc->RIS = 0U;

  /* Read the sample into the buffer */
  adcp->samples[adcp->current_index++] = adcp->adc->ADB;

  bool more = true;
  /*  At the end of the buffer then we may be finished */
  if (adcp->current_index == adcp->number_of_samples) {
    /* We are never finished in circular mode */
    more = adcp->grpp->circular;

    _adc_isr_full_code(adcp);

    adcp->current_index = 0;

  }

  if (more) {

    /* Signal half completion in circular mode. */
    if (adcp->grpp->circular &&
        (adcp->current_index == (adcp->number_of_samples / 2))) {

        _adc_isr_half_code(adcp);
    }

    /* Skip to the next channel */
    do {
      adcp->current_channel = (adcp->current_channel + 1) & ADC_CHANNEL_MASK;
    } while (((1 << adcp->current_channel) & adcp->grpp->chs) == 0);

    /* Enable Interrupt, Select the Channel */
    adcp->adc->ADM_b.CHS = adcp->current_channel;
    adcp->adc->IE = ADC_IE_AIN(adcp->current_channel);
    /* Sample the next channel */
    adcp->adc->ADM_b.ADS |= ADC_ADS_START;
  }
}

/**
 * @brief   Enables the AVREFHSEL bit.
 * @details The AVREFHSEL bit is required in order to sample the VREF channel.
 * @note    This is an SN32-only functionality.
 * @note    This function is meant to be called after @p adcStart().
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adcSN32EnableAVREFHSEL(ADCDriver *adcp) {
  adcp->adc->ADM_b.AVREFHSEL |= ADC_AVREFHSEL_EXTERNAL;
}

/**
 * @brief   Disables the AVREFHSEL bit.
 * @details The AVREFHSEL bit is required in order to sample the VREF channel.
 * @note    This is an SN32-only functionality.
 * @note    This function is meant to be called after @p adcStart().
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adcSN32DisableAVREFHSEL(ADCDriver *adcp) {
  adcp->adc->ADM_b.AVREFHSEL &= ~ADC_AVREFHSEL_EXTERNAL;
}

/**
 * @brief   Enables the GCHS bit.
 * @details The GCHS bit is required in order to sample the AIN channels.
 * @note    This is an SN32-only functionality.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adcSN32EnableGCHS(SN_ADC_Type *adc) {
  adc->ADM_b.GCHS |= ADC_GCHS_EN;
}

/**
 * @brief   Disables the GCHS bit.
 * @details The GCHS bit is required in order to sample the AIN channels.
 * @note    This is an SN32-only functionality.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adcSN32DisableGCHS(SN_ADC_Type *adc) {
  adc->ADM_b.GCHS &= ~ADC_GCHS_EN;
}

#endif /* HAL_USE_ADC */

/** @} */
