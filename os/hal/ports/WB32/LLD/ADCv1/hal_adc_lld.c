/*
    Copyright (C) 2022 Westberry Technology (ChangZhou) Corp., Ltd

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
 * @brief   WB32 ADC subsystem low level driver source.
 *
 * @addtogroup ADC
 * @{
 */

#include "hal.h"

#if HAL_USE_ADC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define SARENR_SAREN_BB     BIT_BAND_ADDR(&ANCTL->SARENR, 0)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief ADC driver identifier.*/
#if WB32_ADC_USE_ADC1 || defined(__DOXYGEN__)
ADCDriver ADCD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Shared ADC DMA ISR service routine.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 * @param[in] flags     pre-shifted content of the ISR register
 */
static void adc_lld_serve_rx_interrupt(ADCDriver *adcp, uint32_t flags) {

  /* DMA errors handling.*/
  if ((flags & WB32_DMAC_IT_STATE_ERR) != 0) {
    /* DMA, this could help only if the DMA tries to access an unmapped
       address space or violates alignment rules.*/
    _adc_isr_error_code(adcp, ADC_ERR_DMAFAILURE);
  }
  else {
    if ((flags & WB32_DMAC_IT_STATE_TFR) != 0) {
      /* Transfer complete processing.*/
      _adc_isr_full_code(adcp);
    }
    /* Because WB32 DMAC hasn't half transfer interrupt,
       so it use transfer complete interrupt. */
    else if ((flags & WB32_DMAC_IT_STATE_BLOCK) != 0) {
      /* Half transfer processing.*/
      _adc_isr_half_code(adcp);
    }
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level ADC driver initialization.
 *
 * @notapi
 */
void adc_lld_init(void) {
  uint32_t tmpreg1 = 0;

#if WB32_ADC_USE_ADC1
  /* Driver initialization.*/
  adcObjectInit(&ADCD1);
  ADCD1.adc     = ADC;
  ADCD1.dmastp  = NULL;
  ADCD1.dmamode = WB32_DMA_CHCFG_HWHIF(WB32_DMAC_HWHIF_ADC_Regular) | \
                  WB32_DMA_CHCFG_PL(WB32_ADC_ADC1_DMA_PRIORITY) | \
                  WB32_DMA_CHCFG_PSIZE_HWORD | \
                  WB32_DMA_CHCFG_MSIZE_HWORD | \
                  WB32_DMA_CHCFG_DIR_P2M | \
                  WB32_DMA_CHCFG_MINC | \
                  WB32_DMA_CHCFG_TCIE | \
                  WB32_DMAC_INTERRUPT_EN;

  /* Temporary activation.*/
  rccEnableADC();
  
  PWR->ANAKEY1 = 0x03;
  PWR->ANAKEY2 = 0x0C;

  *(__IO uint32_t*) SARENR_SAREN_BB = (uint32_t)ENABLE;
  
  PWR->ANAKEY1 = 0x00;
  PWR->ANAKEY2 = 0x00;

  tmpreg1 = (uint8_t)(((WB32_PCLK1 / 6000000) >> 1) - 1);
  ADC->CR3 = ((tmpreg1 << 8) | ADC_CR3_12BIT);
  
  ADC->CR1 = 0;
  ADC->CR2 = ADC_CR2_ADON;
  
  /* Calibration.*/
  ADC->CR2 = ADC_CR2_ADON | ADC_CR2_CAL;
  while ((ADC->CR2 & ADC_CR2_CAL) != 0)
    ;

  /* Reset calibration just to be safe.*/
  ADC->CR2 = ADC_CR2_ADON | ADC_CR2_RSTCAL;
  while ((ADC->CR2 & ADC_CR2_RSTCAL) != 0)
    ;

  /* Return the ADC in low power mode.*/
  ADC->CR2 = 0;
  rccDisableADC();
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

  /* If in stopped state then enables the ADC clocks.*/
  if (adcp->state == ADC_STOP) {
#if WB32_ADC_USE_ADC1
    if (&ADCD1 == adcp) {
      adcp->dmastp = dmaStreamAllocI(WB32_ADC_ADC1_DMA_STREAM,
                                     WB32_ADC_ADC1_IRQ_PRIORITY,
                                     (wb32_dmaisr_t)adc_lld_serve_rx_interrupt,
                                     (void *)adcp);
      osalDbgAssert(adcp->dmastp != NULL, "unable to allocate stream");
      dmaStreamSetSource(adcp->dmastp, &ADC->DR);
      dmaStreamEnableInterrupt(adcp->dmastp, WB32_DMAC_IT_TFR);

      PWR->ANAKEY1 = 0x03;
      PWR->ANAKEY2 = 0x0C;
      *(__IO uint32_t*) SARENR_SAREN_BB = (uint32_t)ENABLE;
      PWR->ANAKEY1 = 0x00;
      PWR->ANAKEY2 = 0x00;

      rccEnableADC();
    }
#endif /* WB32_ADC_USE_ADC1 */

    /* ADC setup, the calibration procedure has already been performed
       during initialization.*/
    adcp->adc->CR1 = 0;
    adcp->adc->CR2 = 0;
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
#if WB32_ADC_USE_ADC1
    if (&ADCD1 == adcp) {
      ADC->CR1 = 0;
      ADC->CR2 = 0;

      dmaStreamFreeI(adcp->dmastp);
      adcp->dmastp = NULL;

      rccDisableADC();

      PWR->ANAKEY1 = 0x03;
      PWR->ANAKEY2 = 0x0C;
      *(__IO uint32_t*) SARENR_SAREN_BB = (uint32_t)DISABLE;
      PWR->ANAKEY1 = 0x00;
      PWR->ANAKEY2 = 0x00;
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
  uint32_t cr2, mode;
  uint32_t tmpreg1                  = 0;
  const    ADCConversionGroup *grpp = adcp->grpp;

  /* DMA setup.*/
  mode = adcp->dmamode;
  if (grpp->circular) {
    mode |= WB32_DMA_CHCFG_CIRC;
    if (adcp->depth > 1) {
      /* If circular buffer depth > 1, then the half transfer interrupt
         is enabled in order to allow streaming processing.*/
      mode |= WB32_DMA_CHCFG_HTIE;
    }
  }
  dmaStreamSetDestination(adcp->dmastp, adcp->samples);
  dmaStreamSetTransactionSize(adcp->dmastp, (uint32_t)grpp->num_channels *
                                            (uint32_t)adcp->depth);
  dmaStreamSetMode(adcp->dmastp, mode);
  dmaStreamEnable(adcp->dmastp);

  /* ADC setup.*/
  adcp->adc->CR1   = grpp->cr1 | ADC_CR1_SCAN;
  cr2 = grpp->cr2 | ADC_CR2_DMA | ADC_CR2_ADON;
  if ((cr2 & (ADC_CR2_EXTTRIG | ADC_CR2_JEXTTRIG)) == 0)
    cr2 |= ADC_CR2_CONT;
  tmpreg1          = (uint8_t)(((WB32_PCLK1 / 6000000) >> 1) - 1);
  adcp->adc->CR2   = grpp->cr2 | cr2;
  adcp->adc->SMPR1 = grpp->smpr1;
  adcp->adc->SMPR2 = grpp->smpr2;
  adcp->adc->SQR1  = grpp->sqr1;
  adcp->adc->SQR2  = grpp->sqr2;
  adcp->adc->SQR3  = grpp->sqr3;
  adcp->adc->CR3   = ((tmpreg1 << 8) | ADC_CR3_12BIT);

  /* ADC start by writing ADC_CR2_ADON a second time.*/
  adcp->adc->CR2   = cr2;
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
  rccResetADC();
}

#endif /* HAL_USE_ADC */

/** @} */
