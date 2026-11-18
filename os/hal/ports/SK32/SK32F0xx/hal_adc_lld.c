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
 * @file    SK32F0xx/hal_adc_lld.c
 * @brief   SK32F0xx ADC subsystem low level driver source.
 *
 * @addtogroup ADC
 * @{
 */

#include "hal.h"

#if HAL_USE_ADC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   Write-one-to-clear of the whole ADC ISR register.
 */
#define adc_lld_clear_isr(adcp) ((adcp)->adc->ISR = (adcp)->adc->ISR)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   ADC1 driver identifier.
 * @note    The ADC1 interrupt vector is shared with the two comparators
 *          (COMP1/COMP2), the comparators are not used by this driver.
 */
#if SK32_ADC_USE_ADC1 || defined(__DOXYGEN__)
ADCDriver ADCD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Stops an ongoing conversion, if any, and disables the ADC.
 * @details This driver samples the data register in the interrupt handler,
 *          there is no DMA channel to stop: the conversion is aborted by
 *          writing ADSTP and the ADC is then fully disabled with ADDIS.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
static void adc_lld_stop_adc(ADCDriver *adcp) {

  /* Disabling all the ADC interrupts first so no new event can be raised
     while the peripheral is being stopped.*/
  adcp->adc->IER = 0U;

  /* Aborting a possible ongoing conversion. ADSTP is only accepted when a
     conversion is in progress (ADSTART set) and is cleared by the hardware
     when the conversion is effectively stopped.*/
  if ((adcp->adc->CR & ADC_CR_ADSTART) != 0U) {
    adcp->adc->CR |= ADC_CR_ADSTP;
    while ((adcp->adc->CR & ADC_CR_ADSTP) != 0U)
      ;
  }

  /* Disabling the ADC.*/
  adcp->adc->CR |= ADC_CR_ADDIS;
  while ((adcp->adc->CR & ADC_CR_ADEN) != 0U) {
    /* Waiting for ADC to be disabled.*/
  }

  adc_lld_clear_isr(adcp);
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if SK32_ADC_USE_ADC1 || defined(__DOXYGEN__)
#if !defined(SK32_ADC1_SUPPRESS_ISR)
#if !defined(SK32_ADC_COMP_HANDLER)
#error "SK32_ADC_COMP_HANDLER not defined"
#endif
/**
 * @brief   ADC interrupt handler.
 * @note    The vector is shared with the comparators, only the ADC interrupt
 *          and status register is serviced here.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SK32_ADC_COMP_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  adc_lld_serve_interrupt(&ADCD1);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(SK32_ADC1_SUPPRESS_ISR) */
#endif /* SK32_ADC_USE_ADC1 */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level ADC driver initialization.
 *
 * @notapi
 */
void adc_lld_init(void) {

#if SK32_ADC_USE_ADC1
  /* Driver initialization.*/
  adcObjectInit(&ADCD1);
  ADCD1.adc       = ADC1;
  ADCD1.isr_count = 0U;
  ADCD1.isr_total = 0U;

  /* The vector is initialized on driver initialization and never
     disabled.  A Cortex-M0 device has no way to read back the priority of
     an enabled vector, so this must be the only place setting it.*/
  nvicEnableVector(SK32_ADC_COMP_NUMBER, SK32_ADC_ADC1_IRQ_PRIORITY);
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

  /* If in stopped state then enables the ADC and configures its clock.*/
  if (adcp->state == ADC_STOP) {
    rccResetADC1();
    rccEnableADC1(true);

    /* The SK32F0xx has no ADC prescaler bits in the CCR register (only the
       VREFINT/temperature sensor enables), the ADC kernel clock is selected
       by the CFGR2 CKMODE bits.  The internal source enables in CCR are
       managed by the application through adcSK32SetCCR()/adcSK32EnableVREF()
       and friends, so they are left untouched here.*/
    adcp->adc->CFGR2 = SK32_ADC_ADC1_CFGR2;
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
    adc_lld_stop_adc(adcp);
    rccDisableADC1();
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
  uint32_t ier;
  const ADCConversionGroup *grpp = adcp->grpp;

  /* Write back ISR bits to clear the register.*/
  adc_lld_clear_isr(adcp);

  /* Apply the ADC configuration.  CFGR1 must be written while the ADC is
     disabled: modifying the RES bits with ADEN set would be ignored (see
     the device errata).*/
  adcp->adc->CFGR1  = grpp->cfgr1;
  adcp->adc->CHSELR = grpp->chselr;
  adcp->adc->SMPR   = grpp->smpr;

  /* Enable the ADC interrupts.  EOCIE is always required because every
     sample is read from the DR register in the interrupt handler.  The
     overrun and watchdog interrupts (and the TR register) are only enabled
     when an error callback is provided.*/
  ier = ADC_IER_EOCIE;
  if (grpp->error_cb != NULL) {
    adcp->adc->TR = grpp->tr;
    ier |= ADC_IER_OVRIE | ADC_IER_AWDIE;
  }
  adcp->adc->IER = ier;

  /* Sample counter initialization.*/
  adcp->isr_count = 0U;
  adcp->isr_total = (uint32_t)grpp->num_channels * (uint32_t)adcp->depth;

  /* Enable the ADC and wait for it to become ready.*/
  adcp->adc->CR |= ADC_CR_ADEN;
  while ((adcp->adc->ISR & ADC_ISR_ADRDY) == 0U) {
    /* Waiting for the ADC to be ready.*/
  }

  /* ADC conversion start.*/
  adcp->adc->CR |= ADC_CR_ADSTART;
}

/**
 * @brief   Stops an ongoing conversion.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_stop_conversion(ADCDriver *adcp) {

  adc_lld_stop_adc(adcp);
}

/**
 * @brief   ISR code.
 * @details On each EOC event the converted sample is read from the DR
 *          register into the samples buffer; when the whole buffer has been
 *          filled the standard full-buffer ISR code is invoked.  The
 *          hardware end of sequence flag is not used: with N channels in
 *          the group and a buffer depth D the driver counts exactly
 *          N * D end-of-conversion events.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_serve_interrupt(ADCDriver *adcp) {
  uint32_t isr;

  isr = adcp->adc->ISR;
  adc_lld_clear_isr(adcp);

  /* It could be a spurious interrupt caused by events raised after the
     conversion was stopped, just ignore it in this case.*/
  if (adcp->grpp == NULL) {
    return;
  }

  if ((isr & (ADC_ISR_OVR | ADC_ISR_AWD)) != 0U) {
    /* Overflow or analog watchdog condition.*/
    adcerror_t emask = 0U;

    if ((isr & ADC_ISR_OVR) != 0U) {
      /* ADC overflow condition, this could happen only if the interrupt
         handler is unable to read the DR register fast enough.*/
      emask |= ADC_ERR_OVERFLOW;
    }
    if ((isr & ADC_ISR_AWD) != 0U) {
      /* Analog watchdog error.*/
      emask |= ADC_ERR_AWD1;
    }
    _adc_isr_error_code(adcp, emask);
    return;
  }

  if ((isr & ADC_ISR_EOC) != 0U) {
    /* Store the sample and advance the counter.  Extra samples (possible
       only in circular mode right after a buffer wrap) are discarded.*/
    if (adcp->isr_count < adcp->isr_total) {
      adcp->samples[adcp->isr_count] = (adcsample_t)(adcp->adc->DR & 0xFFFFU);
    }
    else {
      (void)(adcp->adc->DR & 0xFFFFU);
    }
    adcp->isr_count++;

    if (adcp->isr_count >= adcp->isr_total) {
      /* The whole buffer has been filled.  In circular mode the counter is
         reset before the full-buffer code so the next buffer cycle keeps
         overwriting the samples buffer from the start.*/
      adcp->isr_count = 0U;
      _adc_isr_full_code(adcp);
    }
  }
}

/**
 * @brief   Enables the VREFEN bit.
 * @details The VREFEN bit is required in order to sample the VREFINT
 *          internal reference voltage (channel 17).
 * @note    This is a SK32-only functionality.
 * @note    This function is meant to be called after @p adcStart().
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adcSK32EnableVREF(ADCDriver *adcp) {

  (void)adcp;

  ADC->CCR |= ADC_CCR_VREFEN;
}

/**
 * @brief   Disables the VREFEN bit.
 * @note    This is a SK32-only functionality.
 * @note    This function is meant to be called after @p adcStart().
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adcSK32DisableVREF(ADCDriver *adcp) {

  (void)adcp;

  ADC->CCR &= ~ADC_CCR_VREFEN;
}

/**
 * @brief   Enables the TSEN bit.
 * @details The TSEN bit is required in order to sample the internal
 *          temperature sensor (channel 16).
 * @note    This is a SK32-only functionality.
 * @note    This function is meant to be called after @p adcStart().
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adcSK32EnableTS(ADCDriver *adcp) {

  (void)adcp;

  ADC->CCR |= ADC_CCR_TSEN;
}

/**
 * @brief   Disables the TSEN bit.
 * @note    This is a SK32-only functionality.
 * @note    This function is meant to be called after @p adcStart().
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adcSK32DisableTS(ADCDriver *adcp) {

  (void)adcp;

  ADC->CCR &= ~ADC_CCR_TSEN;
}

#endif /* HAL_USE_ADC */

/** @} */
