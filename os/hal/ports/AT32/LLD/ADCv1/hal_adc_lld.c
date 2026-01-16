/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2026 HorrorTroll
    ChibiOS - Copyright (C) 2023..2026 Zhaqian

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
 * @file    ADCv1/hal_adc_lld.c
 * @brief   AT32 ADC subsystem low level driver source.
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

/** @brief ADC1 driver identifier.*/
#if AT32_ADC_USE_ADC1 || defined(__DOXYGEN__)
ADCDriver ADCD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   ADC DMA service routine.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 * @param[in] flags     pre-shifted content of the STS register
 */
static void adc_lld_serve_rx_interrupt(ADCDriver *adcp, uint32_t flags) {

  /* DMA errors handling.*/
  if ((flags & AT32_DMA_STS_DTERRF) != 0) {
    /* DMA, this could help only if the DMA tries to access an unmapped
       address space or violates alignment rules.*/
    _adc_isr_error_code(adcp, ADC_ERR_DMAFAILURE);
  }
  else {
    /* It is possible that the conversion group has already be reset by the
       ADC error handler, in this case this interrupt is spurious.*/
    if (adcp->grpp != NULL) {

      if ((flags & AT32_DMA_STS_FDTF) != 0) {
        /* Transfer complete processing.*/
        _adc_isr_full_code(adcp);
      }
      else if ((flags & AT32_DMA_STS_HDTF) != 0) {
        /* Half transfer processing.*/
        _adc_isr_half_code(adcp);
      }
    }
  }
}

/**
 * @brief   ADC IRQ service routine.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 * @param[in] sts       content of the STS register
 */
static void adc_lld_serve_interrupt(ADCDriver *adcp, uint32_t sts) {

  /* It could be a spurious interrupt caused by overflows after DMA disabling,
     just ignore it in this case.*/
  if (adcp->grpp != NULL) {
    adcerror_t emask = 0U;

    if (sts & ADC_STS_VMOR) {
      /* Analog voltage monitoring error.*/
      emask |= ADC_ERR_VM;
    }
    if (emask != 0U) {
      _adc_isr_error_code(adcp, emask);
    }
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if AT32_ADC_USE_ADC1 || defined(__DOXYGEN__)
/**
 * @brief   ADC1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_ADC1_HANDLER) {
  uint32_t sts;

  OSAL_IRQ_PROLOGUE();

#if AT32_ADC_USE_ADC1
  sts = ADC1->STS;
  ADC1->STS = 0;
#if defined(AT32_ADC_ADC1_IRQ_HOOK)
  AT32_ADC_ADC1_IRQ_HOOK
#endif
  adc_lld_serve_interrupt(&ADCD1, sts);
#endif /* AT32_ADC_USE_ADC1 */

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

#if AT32_ADC_USE_ADC1
  /* Driver initialization.*/
  adcObjectInit(&ADCD1);
  ADCD1.adc     = ADC1;
  ADCD1.dmastp  = NULL;
  ADCD1.dmamode = AT32_DMA_CCTRL_CHPL(AT32_ADC_ADC1_DMA_PRIORITY) |
                  AT32_DMA_CCTRL_DTD_P2M      |
                  AT32_DMA_CCTRL_MWIDTH_HWORD | AT32_DMA_CCTRL_PWIDTH_HWORD |
                  AT32_DMA_CCTRL_MINCM        | AT32_DMA_CCTRL_FDTIEN       |
                  AT32_DMA_CCTRL_DTERRIEN;

  /* Temporary activation.*/
  crmEnableADC1(true);
  ADC1->CTRL1 = 0;
  ADC1->CTRL2 = ADC_CTRL2_ADCEN;

  /* Reset calibration just to be safe.*/
  ADC1->CTRL2 = ADC_CTRL2_ADCEN | ADC_CTRL2_ADCALINIT;
  while ((ADC1->CTRL2 & ADC_CTRL2_ADCALINIT) != 0)
    ;

  /* Calibration.*/
  ADC1->CTRL2 = ADC_CTRL2_ADCEN | ADC_CTRL2_ADCAL;
  while ((ADC1->CTRL2 & ADC_CTRL2_ADCAL) != 0)
    ;

  /* Return the ADC in low power mode.*/
  ADC1->CTRL2 = 0;
  crmDisableADC1();
#endif

  /* The shared vector is initialized on driver initialization and never
     disabled because sharing.*/
  nvicEnableVector(AT32_ADC1_NUMBER, AT32_ADC_ADC1_IRQ_PRIORITY);
}

/**
 * @brief   Configures and activates the ADC peripheral.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_start(ADCDriver *adcp) {

  /* If in stopped state then enables the ADC and DMA clocks.*/
  if (adcp->state == ADC_STOP) {
#if AT32_ADC_USE_ADC1
    if (&ADCD1 == adcp) {
      adcp->dmastp = dmaStreamAllocI(AT32_ADC_ADC1_DMA_STREAM,
                                     AT32_ADC_ADC1_DMA_IRQ_PRIORITY,
                                     (at32_dmasts_t)adc_lld_serve_rx_interrupt,
                                     (void *)adcp);
      osalDbgAssert(adcp->dmastp != NULL, "unable to allocate stream");
      dmaStreamSetPeripheral(adcp->dmastp, &ADC1->ODT);
#if AT32_DMA_SUPPORTS_DMAMUX
      dmaSetRequestSource(adcp->dmastp, AT32_ADC_ADC1_DMAMUX_CHANNEL, AT32_DMAMUX_ADC1);
#endif
#if defined(crmResetADC1)
      crmResetADC1();
#endif
      crmEnableADC1(true);
    }
#endif /* AT32_ADC_USE_ADC1 */

    /* This is a common register but apparently it requires that at least one
       of the ADCs is clocked in order to allow writing, see bug 3575297.*/
    adcp->adc->CTRL2 = ADC_CTRL2_ITSRVEN;

    /* ADC initial setup, starting the analog part here in order to reduce
       the latency when starting a conversion.*/
    adcp->adc->CTRL1 = 0;
    adcp->adc->CTRL2 = 0;
    adcp->adc->CTRL2 = ADC_CTRL2_ADCEN;
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

  /* If in ready state then disables the ADC clock.*/
  if (adcp->state == ADC_READY) {

    dmaStreamFreeI(adcp->dmastp);
    adcp->dmastp = NULL;

    adcp->adc->CTRL1 = 0;
    adcp->adc->CTRL2 = 0;

#if AT32_ADC_USE_ADC1
    if (&ADCD1 == adcp)
      crmDisableADC1();
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
  uint32_t mode;
  uint32_t ctrl2;
  const ADCConversionGroup *grpp = adcp->grpp;

  /* DMA setup.*/
  mode = adcp->dmamode;
  if (grpp->circular) {
    mode |= AT32_DMA_CCTRL_LM;
    if (adcp->depth > 1) {
      /* If circular buffer depth > 1, then the half transfer interrupt
         is enabled in order to allow streaming processing.*/
      mode |= AT32_DMA_CCTRL_HDTIEN;
    }
    ctrl2 = 0U;
  }
  dmaStreamSetMemory0(adcp->dmastp, adcp->samples);
  dmaStreamSetTransactionSize(adcp->dmastp, (uint32_t)grpp->num_channels *
                                            (uint32_t)adcp->depth);
  dmaStreamSetMode(adcp->dmastp, mode);
  dmaStreamEnable(adcp->dmastp);

  /* ADC setup.*/
  adcp->adc->STS  = 0;
  adcp->adc->SPT1 = grpp->spt1;
  adcp->adc->SPT2 = grpp->spt2;
  adcp->adc->VMHB = grpp->vmhb;
  adcp->adc->VMLB = grpp->vmlb;
  adcp->adc->OSQ1 = grpp->osq1 | ADC_OSQ1_NUM_CH(grpp->num_channels);
  adcp->adc->OSQ2 = grpp->osq2;
  adcp->adc->OSQ3 = grpp->osq3;

  /* ADC configuration and start.*/
  adcp->adc->CTRL1 = grpp->ctrl1 | ADC_CTRL1_SQEN;

  /* Enforcing the mandatory bits in CTRL2.*/
  ctrl2 |= grpp->ctrl2 | ADC_CTRL2_OCDMAEN | ADC_CTRL2_ADCEN;

  if ((ctrl2 & (ADC_CTRL2_OCTEN | ADC_CTRL2_PCTEN)) == 0) {
    ctrl2 |= ADC_CTRL2_RPEN;
  }

  adcp->adc->CTRL2 = grpp->ctrl2 | ctrl2;

  /* ADC start by writing ADC_CTRL2_ADCEN a second time.*/
  adcp->adc->CTRL2 = ctrl2;
}

/**
 * @brief   Stops an ongoing conversion.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_stop_conversion(ADCDriver *adcp) {

  dmaStreamDisable(adcp->dmastp);
  adcp->adc->CTRL1 = 0U;
  if ((adcp->adc->CTRL2 & ADC_CTRL2_RPEN) != 0U) {
    adcp->adc->CTRL2 = 0U;
  }
  adcp->adc->CTRL2 = ADC_CTRL2_ADCEN;
}

/**
 * @brief   Enables the ITSRVEN bit.
 * @details The ITSRVEN bit is required in order to sample the internal
 *          temperature sensor and internal reference voltage.
 * @note    This is an AT32-only functionality.
 */
void adcAT32EnableITSRVEN(void) {

  ADC1->CTRL2 |= ADC_CTRL2_ITSRVEN;
}

/**
 * @brief   Disables the ITSRVEN bit.
 * @details The ITSRVEN bit is required in order to sample the internal
 *          temperature sensor and internal reference voltage.
 * @note    This is an AT32-only functionality.
 */
void adcAT32DisableITSRVEN(void) {

  ADC1->CTRL2 &= ~ADC_CTRL2_ITSRVEN;
}

#endif /* HAL_USE_ADC */

/** @} */
