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
 * @file    hal_adc_lld.c
 * @brief   PLATFORM ADC subsystem low level driver source.
 *
 * @addtogroup ADC
 * @{
 */

#include "hal.h"

#if (HAL_USE_ADC == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/
#define ADC_LINEARITY0_POS (27U)
#define ADC_LINEARITY0_Msk ((0x1FUL << ADC_LINEARITY0_POS))

#define ADC_LINEARITY1_POS (0U)
#define ADC_LINEARITY1_Msk ((0x7U << ADC_LINEARITY1_POS))

#define ADC_BIASCAL_POS (3U)
#define ADC_BIASCAL_Msk ((0x7U << ADC_BIASCAL_POS))
/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   ADC1 driver identifier.
 */
#if (SAM_ADC_USE_ADC1 == TRUE) || defined(__DOXYGEN__)
ADCDriver ADCD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Stops an ongoing conversion, if any.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 */
static void adc_lld_stop_adc(ADCDriver *adcp)
{

  if (adcp->adc->ADC_CTRLA & ADC_CTRLA_ENABLE_Msk)
  {
    adcp->adc->ADC_CTRLA &= ~ADC_CTRLA_ENABLE_Msk;
    while (adcp->adc->ADC_CTRLA & ADC_CTRLA_ENABLE_Msk)
      ;
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

static void adc_lld_serve_interrupt(ADCDriver *adcp, uint32_t isr)
{
  if (adcp->grpp != NULL)
  {
    adcerror_t emask = 0U;
    if ((isr & ADC_INTFLAG_RESRDY_Msk) && (adcp->state == ADC_ACTIVE))
    {
      volatile uint16_t value = adcp->adc->ADC_RESULT;
      if (adcp->curr_size == adcp->depth * adcp->grpp->num_channels)
      {
        _adc_isr_full_code(adcp);
      }

      else
      {
        if (adcp->curr_pin == adcp->grpp->num_channels)
        {
          adcp->curr_pin = 0;
        }
        adcp->samples[adcp->curr_size] = value;
        adcp->curr_size += 1;
        ADCD1.adc->ADC_INTENSET = ADC_INTENSET_OVERRUN_Msk | ADC_INTENSET_RESRDY_Msk;
        uint8_t curr_pin = adcp->grpp->seq[adcp->curr_pin];
        adcp->adc->ADC_INPUTCTRL = (adcp->grpp->inputctrl & ~(ADC_INPUTCTRL_MUXPOS_Msk | ADC_INPUTCTRL_INPUTSCAN_Msk)) | ADC_INPUTCTRL_MUXPOS(curr_pin);
        while ((adcp->adc->ADC_STATUS & ADC_STATUS_SYNCBUSY_Msk) != 0U)
          ;
        adcp->curr_pin += 1;
        adcp->adc->ADC_SWTRIG = ADC_SWTRIG_START_Msk;
        while ((adcp->adc->ADC_STATUS & ADC_STATUS_SYNCBUSY_Msk) != 0U)
          ;
      }
    }
    /* Note, an overflow may occur after the conversion ended before the driver
       is able to stop the ADC, this is why the state is checked too.*/
    if ((isr & ADC_INTFLAG_OVERRUN_Msk) && (adcp->state == ADC_ACTIVE))
    {
      /* ADC overflow condition, this could happen only if the DMA is unable
         to read data fast enough.*/
      emask |= ADC_ERR_OVERFLOW;
    }
    if (emask != 0U)
    {
      _adc_isr_error_code(adcp, emask);
    }
  }
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level ADC driver initialization.
 *
 * @notapi
 */
void adc_lld_init(void)
{

#if SAM_ADC_USE_ADC1 == TRUE
  /* Driver initialization.*/
  adcObjectInit(&ADCD1);
  ADCD1.adc = ADC_REGS;
  sam_gclk_mux(0, GCLK_CLKCTRL_ID_EVSYS_0_Val, 1);
#endif
}

/**
 * @brief   Configures and activates the ADC peripheral.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_start(ADCDriver *adcp)
{

  if (adcp->state == ADC_STOP)
  {
    /* Enables the peripheral.*/
#if SAM_ADC_USE_ADC1 == TRUE
    if (&ADCD1 == adcp)
    {
      PM_REGS->PM_APBCMASK |= PM_APBCMASK_ADC_Msk | PM_APBCMASK_EVSYS_Msk;
      sam_gclk_mux(SAM_ADC_GCLK_SRC_ID, GCLK_CLKCTRL_ID_ADC_Val, 1);
      // Reset ADC
      adcp->adc->ADC_CTRLA = ADC_CTRLA_SWRST_Msk;
      while ((adcp->adc->ADC_STATUS & ADC_STATUS_SYNCBUSY_Msk) != 0U)
        ;
      uint32_t adc_linearity0 = (((*(uint32_t *)OTP4_ADDR) & ADC_LINEARITY0_Msk) >> ADC_LINEARITY0_POS);
      uint32_t adc_linearity1 = (((*(uint32_t *)(OTP4_ADDR + 4U)) & ADC_LINEARITY1_Msk) >> ADC_LINEARITY1_POS);
      adcp->adc->ADC_CALIB = (uint16_t)((ADC_CALIB_LINEARITY_CAL(adc_linearity0 |
                                                                 (adc_linearity1 << 5U))) |
                                        ADC_CALIB_BIAS_CAL((((*(uint32_t *)(OTP4_ADDR + 4U)) & ADC_BIASCAL_Msk) >> ADC_BIASCAL_POS)));
      while ((adcp->adc->ADC_STATUS & ADC_STATUS_SYNCBUSY_Msk) != 0U)
        ;
      adcp->adc->ADC_INTFLAG = (uint8_t)ADC_INTFLAG_Msk;
      adcp->adc->ADC_CTRLA |= (uint8_t)ADC_CTRLA_ENABLE_Msk;
      while ((adcp->adc->ADC_STATUS & ADC_STATUS_SYNCBUSY_Msk) != 0U)
        ;
      nvicEnableVector(ADC_IRQn, SAM_ADC_IRQ_PRIORITY);
    }
#endif
  }
  /* Configures the peripheral.*/
}

/**
 * @brief   Deactivates the ADC peripheral.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_stop(ADCDriver *adcp)
{

  if (adcp->state == ADC_READY)
  {
    /* Resets the peripheral.*/
    adcp->adc->ADC_CTRLA = ADC_CTRLA_SWRST_Msk;
    /* Disables the peripheral.*/
#if SAM_ADC_USE_ADC1 == TRUE
    if (&ADCD1 == adcp)
    {
      sam_gclk_mux(SAM_ADC_GCLK_SRC_ID, GCLK_CLKCTRL_ID_ADC_Val, 0);
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
void adc_lld_start_conversion(ADCDriver *adcp)
{
  adcp->curr_pin = 0;
  adcp->curr_size = 0;
  adcp->adc->ADC_AVGCTRL = adcp->grpp->avgctrl;
  adcp->adc->ADC_INPUTCTRL = (adcp->grpp->inputctrl & ~(ADC_INPUTCTRL_MUXPOS_Msk | ADC_INPUTCTRL_INPUTSCAN_Msk)) | ADC_INPUTCTRL_MUXPOS(adcp->grpp->seq[adcp->curr_pin]);
  while ((adcp->adc->ADC_STATUS & ADC_STATUS_SYNCBUSY_Msk) != 0U)
    ;
  adcp->curr_pin += 1;
  adcp->adc->ADC_REFCTRL = adcp->grpp->refctrl;
  adcp->adc->ADC_CTRLB = adcp->grpp->ctrlb;
  while ((adcp->adc->ADC_STATUS & ADC_STATUS_SYNCBUSY_Msk) != 0U)
    ;
  adcp->adc->ADC_INTENSET = (uint8_t)ADC_INTENSET_OVERRUN_Msk | ADC_INTENSET_RESRDY_Msk;
  adcp->adc->ADC_SWTRIG = (uint8_t)ADC_SWTRIG_START_Msk;
  while ((adcp->adc->ADC_STATUS & ADC_STATUS_SYNCBUSY_Msk) != 0U)
    ;
}

/**
 * @brief   Stops an ongoing conversion.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_stop_conversion(ADCDriver *adcp)
{
  // dmacChnlDisable(adcp->dmacId);
  adcp->adc->ADC_SWTRIG = ADC_SWTRIG_FLUSH_Msk;
}

OSAL_IRQ_HANDLER(ADC_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  uint8_t intflag = ADCD1.adc->ADC_INTFLAG;
  ADCD1.adc->ADC_INTFLAG = ADC_INTFLAG_Msk;
  ADCD1.adc->ADC_INTENCLR = ADC_INTENCLR_OVERRUN_Msk | ADC_INTENCLR_RESRDY_Msk;
  adc_lld_serve_interrupt(&ADCD1, intflag);
  OSAL_IRQ_EPILOGUE();
}
#endif /* HAL_USE_ADC == TRUE */

/** @} */
