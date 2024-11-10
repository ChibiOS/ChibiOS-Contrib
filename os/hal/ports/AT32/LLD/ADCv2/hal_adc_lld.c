/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 Maxjta

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
 * @file    ADCv2/hal_adc_lld.c
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

#define ADC1_DMA_CHANNEL                                                    \
  AT32_DMA_GETCHANNEL(AT32_ADC_ADC1_DMA_STREAM, AT32_ADC1_DMA_CHN)

#define ADC2_DMA_CHANNEL                                                    \
  AT32_DMA_GETCHANNEL(AT32_ADC_ADC2_DMA_STREAM, AT32_ADC2_DMA_CHN)

#define ADC3_DMA_CHANNEL                                                    \
  AT32_DMA_GETCHANNEL(AT32_ADC_ADC3_DMA_STREAM, AT32_ADC3_DMA_CHN)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief ADC1 driver identifier.*/
#if AT32_ADC_USE_ADC1 || defined(__DOXYGEN__)
ADCDriver ADCD1;
#endif

/** @brief ADC2 driver identifier.*/
#if AT32_ADC_USE_ADC2 || defined(__DOXYGEN__)
ADCDriver ADCD2;
#endif

/** @brief ADC3 driver identifier.*/
#if AT32_ADC_USE_ADC3 || defined(__DOXYGEN__)
ADCDriver ADCD3;
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
 * @param[in] flags     pre-shifted content of the ISR register
 */
static void adc_lld_serve_rx_interrupt(ADCDriver *adcp, uint32_t flags) {

  /* DMA errors handling.*/
  if ((flags & (AT32_DMA_STS_DTERRF | AT32_DMA_STS_DMERRF)) != 0) {
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

    /* Note, an overflow may occur after the conversion ended before the driver
       is able to stop the ADC, this is why the state is checked too.*/
    if ((sts & ADC_STS_OCCS) && (adcp->state == ADC_ACTIVE)) {
      /* ADC overflow condition, this could happen only if the DMA is unable
         to read data fast enough.*/
      emask |= ADC_ERR_OVERFLOW;
    }
    if (sts & ADC_STS_VMOR) {
      /* Analog watchdog 1 error.*/
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

#if AT32_ADC_USE_ADC1 || AT32_ADC_USE_ADC2 || AT32_ADC_USE_ADC3 ||       \
    defined(__DOXYGEN__)
/**
 * @brief   ADC interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_ADC_HANDLER) {
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

#if AT32_ADC_USE_ADC2
  sts = ADC2->STS;
  ADC2->STS = 0;
#if defined(AT32_ADC_ADC2_IRQ_HOOK)
  AT32_ADC_ADC2_IRQ_HOOK
#endif
  adc_lld_serve_interrupt(&ADCD2, sts);
#endif /* AT32_ADC_USE_ADC2 */

#if AT32_ADC_USE_ADC3
  sts = ADC3->STS;
  ADC3->STS = 0;
#if defined(AT32_ADC_ADC3_IRQ_HOOK)
  AT32_ADC_ADC3_IRQ_HOOK
#endif
  adc_lld_serve_interrupt(&ADCD3, sts);
#endif /* AT32_ADC_USE_ADC3 */

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
  ADCD1.dmamode = AT32_DMA_CTRL_CHSEL(ADC1_DMA_CHANNEL) |
                  AT32_DMA_CTRL_CHPL(AT32_ADC_ADC1_DMA_PRIORITY) |
                  AT32_DMA_CTRL_DTD_P2M      |
                  AT32_DMA_CTRL_MWIDTH_HWORD | AT32_DMA_CTRL_PWIDTH_HWORD |
                  AT32_DMA_CTRL_MINCM        | AT32_DMA_CTRL_FDTIEN       |
                  AT32_DMA_CTRL_DMERRIEN     | AT32_DMA_CTRL_DTERRIEN;
  crmEnableADC1(true);
  ADC1->CTRL1 = 0;
  ADC1->CTRL2 = ADC_CTRL2_ADCEN;

  /* Reset calibration just to be safe.*/
  ADC1->CTRL2 = ADC_CTRL2_ADCEN | ADC_CTRL2_ADCALINIT;
  while ((ADC1->CTRL2 & ADC_CTRL2_ADCALINIT) != 0);

  /* Calibration.*/
  ADC1->CTRL2 = ADC_CTRL2_ADCEN | ADC_CTRL2_ADCAL;
  while ((ADC1->CTRL2 & ADC_CTRL2_ADCAL) != 0);

  /* Return the ADC in low power mode.*/
  ADC1->CTRL2 = 0;
  crmDisableADC1();
#endif

#if AT32_ADC_USE_ADC2
  /* Driver initialization.*/
  adcObjectInit(&ADCD2);
  ADCD2.adc     = ADC2;
  ADCD2.dmastp  = NULL;
  ADCD2.dmamode = AT32_DMA_CTRL_CHSEL(ADC2_DMA_CHANNEL) |
                  AT32_DMA_CTRL_CHPL(AT32_ADC_ADC2_DMA_PRIORITY) |
                  AT32_DMA_CTRL_DTD_P2M      |
                  AT32_DMA_CTRL_MWIDTH_HWORD | AT32_DMA_CTRL_PWIDTH_HWORD |
                  AT32_DMA_CTRL_MINCM        | AT32_DMA_CTRL_FDTIEN       |
                  AT32_DMA_CTRL_DMERRIEN     | AT32_DMA_CTRL_DTERRIEN;
  crmEnableADC2(true);
  ADC2->CTRL1 = 0;
  ADC2->CTRL2 = ADC_CTRL2_ADCEN;

  /* Reset calibration just to be safe.*/
  ADC2->CTRL2 = ADC_CTRL2_ADCEN | ADC_CTRL2_ADCALINIT;
  while ((ADC2->CTRL2 & ADC_CTRL2_ADCALINIT) != 0);

  /* Calibration.*/
  ADC2->CTRL2 = ADC_CTRL2_ADCEN | ADC_CTRL2_ADCAL;
  while ((ADC2->CTRL2 & ADC_CTRL2_ADCAL) != 0);

  /* Return the ADC in low power mode.*/
  ADC2->CTRL2 = 0;
  crmDisableADC2();
#endif

#if AT32_ADC_USE_ADC3
  /* Driver initialization.*/
  adcObjectInit(&ADCD3);
  ADCD3.adc     = ADC3;
  ADCD3.dmastp  = NULL;
  ADCD3.dmamode = AT32_DMA_CTRL_CHSEL(ADC3_DMA_CHANNEL) |
                  AT32_DMA_CTRL_CHPL(AT32_ADC_ADC3_DMA_PRIORITY) |
                  AT32_DMA_CTRL_DTD_P2M      |
                  AT32_DMA_CTRL_MWIDTH_HWORD | AT32_DMA_CTRL_PWIDTH_HWORD |
                  AT32_DMA_CTRL_MINCM        | AT32_DMA_CTRL_FDTIEN       |
                  AT32_DMA_CTRL_DMERRIEN     | AT32_DMA_CTRL_DTERRIEN;
  crmEnableADC3(true);
  ADC3->CTRL1 = 0;
  ADC3->CTRL2 = ADC_CTRL2_ADCEN;

  /* Reset calibration just to be safe.*/
  ADC3->CTRL2 = ADC_CTRL2_ADCEN | ADC_CTRL2_ADCALINIT;
  while ((ADC3->CTRL2 & ADC_CTRL2_ADCALINIT) != 0);

  /* Calibration.*/
  ADC3->CTRL2 = ADC_CTRL2_ADCEN | ADC_CTRL2_ADCAL;
  while ((ADC3->CTRL2 & ADC_CTRL2_ADCAL) != 0);

  /* Return the ADC in low power mode.*/
  ADC3->CTRL2 = 0;
  crmDisableADC3();
#endif

  /* The shared vector is initialized on driver initialization and never
     disabled because sharing.*/
  nvicEnableVector(AT32_ADC_NUMBER, AT32_ADC_IRQ_PRIORITY);
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
#if AT32_USE_DMA_V1 && AT32_DMA_USE_DMAMUX
      dmaSetRequestSource(adcp->dmastp, AT32_ADC_ADC1_DMAMUX_CHANNEL, AT32_DMAMUX_ADC1);
#elif AT32_USE_DMA_V2 || AT32_USE_DMA_V3
      dmaSetRequestSource(adcp->dmastp, AT32_DMAMUX_ADC1);
#endif
      crmEnableADC1(true);
    }
#endif /* AT32_ADC_USE_ADC1 */

#if AT32_ADC_USE_ADC2
    if (&ADCD2 == adcp) {
      adcp->dmastp = dmaStreamAllocI(AT32_ADC_ADC2_DMA_STREAM,
                                     AT32_ADC_ADC2_DMA_IRQ_PRIORITY,
                                     (at32_dmasts_t)adc_lld_serve_rx_interrupt,
                                     (void *)adcp);
      osalDbgAssert(adcp->dmastp != NULL, "unable to allocate stream");
      dmaStreamSetPeripheral(adcp->dmastp, &ADC2->ODT);
#if AT32_USE_DMA_V1 && AT32_DMA_USE_DMAMUX
      dmaSetRequestSource(adcp->dmastp, AT32_ADC_ADC2_DMAMUX_CHANNEL, AT32_DMAMUX_ADC2);
#elif AT32_USE_DMA_V2 || AT32_USE_DMA_V3
      dmaSetRequestSource(adcp->dmastp, AT32_DMAMUX_ADC2);
#endif
      crmEnableADC2(true);
    }
#endif /* AT32_ADC_USE_ADC2 */

#if AT32_ADC_USE_ADC3
    if (&ADCD3 == adcp) {
      adcp->dmastp = dmaStreamAllocI(AT32_ADC_ADC3_DMA_STREAM,
                                     AT32_ADC_ADC3_DMA_IRQ_PRIORITY,
                                     (at32_dmasts_t)adc_lld_serve_rx_interrupt,
                                     (void *)adcp);
      osalDbgAssert(adcp->dmastp != NULL, "unable to allocate stream");
      dmaStreamSetPeripheral(adcp->dmastp, &ADC3->ODT);
#if AT32_USE_DMA_V1 && AT32_DMA_USE_DMAMUX
      dmaSetRequestSource(adcp->dmastp, AT32_ADC_ADC3_DMAMUX_CHANNEL, AT32_DMAMUX_ADC3);
#elif AT32_USE_DMA_V2 || AT32_USE_DMA_V3
      dmaSetRequestSource(adcp->dmastp, AT32_DMAMUX_ADC3);
#endif
      crmEnableADC3(true);
    }
#endif /* AT32_ADC_USE_ADC3 */

    /* This is a common register but apparently it requires that at least one
       of the ADCs is clocked in order to allow writing, see bug 3575297.*/
#if defined(AT32F435_437xx)
    ADCCOM->CCTRL = (ADCCOM->CCTRL & (ADC_CCTRL_ITSRVEN | ADC_CCTRL_VBATEN)) |
                    ((AT32_ADC_ADCDIV - 2) << 16);
#elif defined(AT32F423xx)
    ADCCOM->CCTRL = (ADCCOM->CCTRL & ADC_CCTRL_ITSRVEN) |
                    ((AT32_ADC_ADCDIV - 2) << 16);
#else
    adcp->adc->CTRL2 = ADC_CTRL2_ITSRVEN;
    ADCCOM->CCTRL = ((AT32_ADC_ADCDIV - 2) << 16);
#endif
    
    /* ADC initial setup, starting the analog part here in order to reduce
       the latency when starting a conversion.*/
    adcp->adc->CTRL1 = 0;
#if defined(AT32F435_437xx) || defined(AT32F423xx)
    adcp->adc->CTRL2 = 0;
#endif
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

#if AT32_ADC_USE_ADC2
    if (&ADCD2 == adcp)
      crmDisableADC2();
#endif

#if AT32_ADC_USE_ADC3
    if (&ADCD3 == adcp)
      crmDisableADC3();
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
    mode |= AT32_DMA_CTRL_LM;
    if (adcp->depth > 1) {
      /* If circular buffer depth > 1, then the half transfer interrupt
         is enabled in order to allow streaming processing.*/
      mode |= AT32_DMA_CTRL_HDTIEN;
    }
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
#if AT32_ADC_MAX_CHANNELS >= 20
  adcp->adc->SPT3 = grpp->spt3;
  adcp->adc->OSQ4 = grpp->osq4;
  adcp->adc->OSQ4 = grpp->osq5;
  adcp->adc->OSQ4 = grpp->osq6;
#endif

  /* ADC configuration and start.*/
#if defined(AT32F435_437xx) || defined(AT32F423xx)
  adcp->adc->CTRL1 = grpp->ctrl1 | ADC_CTRL1_OCCOIE | ADC_CTRL1_SQEN;
  ctrl2 = grpp->ctrl2 | ADC_CTRL2_OCDMAEN | ADC_CTRL2_OCDRCEN | ADC_CTRL2_ADCEN;
#else
  adcp->adc->CTRL1 = grpp->ctrl1 | ADC_CTRL1_OCCOIE | ADC_CTRL1_SQEN;
  ctrl2 = grpp->ctrl2 | ADC_CTRL2_OCDMAEN | ADC_CTRL2_ADCEN;
#endif

  /* The start method is different dependign if HW or SW triggered, the
     start is performed using the method specified in the CTRL2 configuration.*/
  if ((ctrl2 & ADC_CTRL2_OCSWTRG) != 0) {
    /* Initializing CTRL2 while keeping ADC_CTRL2_OCSWTRG at zero.*/
    adcp->adc->CTRL2 = (ctrl2 | ADC_CTRL2_RPEN) & ~ADC_CTRL2_OCSWTRG;

    /* Finally enabling ADC_CTRL2_OCSWTRG.*/
    adcp->adc->CTRL2 = (ctrl2 | ADC_CTRL2_RPEN);
  }
  else
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
  adcp->adc->CTRL1 = 0;
  /* Because ticket #822, preserving injected conversions.*/
  adcp->adc->CTRL2 &= ~(ADC_CTRL2_OCSWTRG);
  adcp->adc->CTRL2 = ADC_CTRL2_ADCEN;
}

/**
 * @brief   Enables the TSVREFE bit.
 * @details The TSVREFE bit is required in order to sample the internal
 *          temperature sensor and internal reference voltage.
 * @note    This is an AT32-only functionality.
 */
void adcAT32EnableITSRVEN(void) {

#if defined(AT32F435_437xx) || defined(AT32F423xx)
  ADCCOM->CCTRL |= ADC_CCTRL_ITSRVEN;
#else
  ADC1->CTRL2 |= ADC_CTRL2_ITSRVEN;
#endif
}

/**
 * @brief   Disables the TSVREFE bit.
 * @details The TSVREFE bit is required in order to sample the internal
 *          temperature sensor and internal reference voltage.
 * @note    This is an AT32-only functionality.
 */
void adcAT32DisableITSRVEN(void) {

#if defined(AT32F435_437xx) || defined(AT32F423xx)
  ADCCOM->CCTRL &= ~ADC_CCTRL_ITSRVEN;
#else
  ADC1->CTRL2 &= ~ADC_CTRL2_ITSRVEN;
#endif
}

/**
 * @brief   Enables the VBATE bit.
 * @details The VBATE bit is required in order to sample the VBAT channel.
 * @note    This is an AT32-only functionality.
 * @note    This function is meant to be called after @p adcStart().
 */
void adcAT32EnableVBATEN(void) {

#if defined(AT32F435_437xx)
  ADCCOM->CCTRL |= ADC_CCTRL_VBATEN;
#endif
}

/**
 * @brief   Disables the VBATE bit.
 * @details The VBATE bit is required in order to sample the VBAT channel.
 * @note    This is an AT32-only functionality.
 * @note    This function is meant to be called after @p adcStart().
 */
void adcAT32DisableVBATEN(void) {

#if defined(AT32F435_437xx)
  ADCCOM->CCTRL &= ~ADC_CCTRL_VBATEN;
#endif
}

#endif /* HAL_USE_ADC */

/** @} */
