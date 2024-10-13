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
 * @file    hal_dac_lld.c
 * @brief   EFR32 DAC subsystem low level driver source.
 *
 * @addtogroup DAC
 * @{
 */

#include "hal.h"

#if (HAL_USE_DAC == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define EFF32_DAC1_CLK_EN_MASK      0x03
#define EFF32_DAC1_CLK_EN_SHIFT(ch) (1U << ((ch) + 0))

#define EFF32_DAC2_CLK_EN_MASK      0x0C
#define EFF32_DAC2_CLK_EN_SHIFT(ch) (1U << ((ch) + 2))

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief DAC1 CH1 driver identifier.*/
#if (EFR32_DAC_USE_DAC1_CH1 == TRUE) || defined(__DOXYGEN__)
DACDriver DACD1;
#endif

/** @brief DAC1 CH2 driver identifier.*/
#if (EFR32_DAC_USE_DAC1_CH2 == TRUE) || defined(__DOXYGEN__)
#if !EFR32_DAC_DUAL_MODE
DACDriver DACD2;
#else
#error "DAC1 CH2 not independently available in dual mode"
#endif
#endif

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*
 * @brief   Global DAC-related data structures.
 */
static struct
{
  /**
   * @brief   Mask of the allocated streams.
   */
  uint32_t          clk_en_mask;

} dac;

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level DAC driver initialization.
 *
 * @notapi
 */
void dac_lld_init(void)
{

#if EFR32_DAC_USE_DAC1_CH1 == TRUE
  dacObjectInit(&DACD1);
#endif

#if EFR32_DAC_USE_DAC1_CH2 == TRUE
  dacObjectInit(&DACD2);
#endif

  dac.clk_en_mask = 0U;
}

/**
 * @brief   Configures and activates the DAC peripheral.
 *
 * @param[in] dacp      pointer to the @p DACDriver object
 *
 * @notapi
 */
msg_t dac_lld_start(DACDriver *dacp)
{

  /* If the driver is in DAC_STOP state then a full initialization is
     required.*/
  if (dacp->state == DAC_STOP)
  {
    dacchannel_t channel = 0;

    /* Enable DAC clock. DMA channel allocation is deferred to conversion
       start and only allocated if a group conversion is used.*/

    if (false)
    {
    }

#if EFR32_DAC_USE_DAC1_CH1 == TRUE
    else if (&DACD1 == dacp)
    {
      /* Enable clock only if disabled. The clock can be shared with CH2. */
      if ((dac.clk_en_mask & EFF32_DAC1_CLK_EN_MASK) == 0U)
      {
        CMU->CLKEN1 = (CMU->CLKEN1 & ~_CMU_CLKEN1_VDAC0_MASK) |\
          CMU_CLKEN1_VDAC0;
      }

      dac.clk_en_mask |= EFF32_DAC1_CLK_EN_SHIFT(channel);
    }
#endif

#if EFR32_DAC_USE_DAC1_CH2 == TRUE
    else if (&DACD2 == dacp)
    {
      channel = 1;

      /* Enable clock only if disabled. The clock can be shared with CH1. */
      if ((dac.clk_en_mask & EFF32_DAC1_CLK_EN_MASK) == 0U)
      {
        CMU->CLKEN1 = (CMU->CLKEN1 & ~_CMU_CLKEN1_VDAC0_MASK) |\
          CMU_CLKEN1_VDAC0;
      }

      dac.clk_en_mask |= EFF32_DAC1_CLK_EN_SHIFT(channel);
    }
#endif
    else
    {
      osalDbgAssert(false, "unknown DAC instance");
      return HAL_RET_NO_RESOURCE;
    }
  }

  return HAL_RET_SUCCESS;
}

/**
 * @brief   Deactivates the DAC peripheral.
 *
 * @param[in] dacp      pointer to the @p DACDriver object
 *
 * @notapi
 */
void dac_lld_stop(DACDriver *dacp)
{

  /* If in ready state then disables the DAC clock.*/
  if (dacp->state == DAC_READY)
  {
    dacchannel_t channel = 0;

#if EFR32_DAC_USE_DAC1_CH1 == TRUE
    if (&DACD1 == dacp)
    {
      dac.clk_en_mask &= ~EFF32_DAC1_CLK_EN_SHIFT(channel);

      if ((dac.clk_en_mask & EFF32_DAC1_CLK_EN_MASK) == 0U)
      {
        CMU->CLKEN1 = (CMU->CLKEN1 & ~_CMU_CLKEN1_VDAC0_MASK) |\
          CMU_CLKEN1_VDAC0_DEFAULT;
      }

      return;
    }
#endif

#if EFR32_DAC_USE_DAC1_CH2 == TRUE
    if (&DACD2 == dacp)
    {
      channel = 1;

      dac.clk_en_mask &= ~EFF32_DAC1_CLK_EN_SHIFT(channel);

      if ((dac.clk_en_mask & EFF32_DAC1_CLK_EN_MASK) == 0U)
      {
        CMU->CLKEN1 = (CMU->CLKEN1 & ~_CMU_CLKEN1_VDAC0_MASK) |\
          CMU_CLKEN1_VDAC0_DEFAULT;
      }

      return;
    }
#endif
  }
}

/**
 * @brief   Outputs a value directly on a DAC channel.
 *
 * @param[in] dacp      pointer to the @p DACDriver object
 * @param[in] channel   DAC channel number
 * @param[in] sample    value to be output
 *
 * @api
 */
msg_t dac_lld_put_channel(DACDriver *dacp,
                          dacchannel_t channel,
                          dacsample_t sample)
{

  (void)dacp;
  (void)channel;
  (void)sample;

  return HAL_RET_SUCCESS;
}

/**
 * @brief   Starts a DAC conversion.
 * @details Starts an asynchronous conversion operation.
 * @note    In @p DAC_DHRM_8BIT_RIGHT mode the parameters passed to the
 *          callback are wrong because two samples are packed in a single
 *          dacsample_t element. This will not be corrected, do not rely
 *          on those parameters.
 * @note    In @p DAC_DHRM_8BIT_RIGHT_DUAL mode two samples are treated
 *          as a single 16 bits sample and packed into a single dacsample_t
 *          element. The num_channels must be set to one in the group
 *          conversion configuration structure.
 *
 * @param[in] dacp      pointer to the @p DACDriver object
 *
 * @notapi
 */
msg_t dac_lld_start_conversion(DACDriver *dacp)
{

  (void)dacp;

  osalDbgAssert(false, "not implemented");

  return HAL_RET_HW_FAILURE;
}

/**
 * @brief   Stops an ongoing conversion.
 * @details This function stops the currently ongoing conversion and returns
 *          the driver in the @p DAC_READY state. If there was no conversion
 *          being processed then the function does nothing.
 *
 * @param[in] dacp      pointer to the @p DACDriver object
 *
 * @iclass
 */
void dac_lld_stop_conversion(DACDriver *dacp)
{

  (void)dacp;

  osalDbgAssert(false, "not implemented");
}

#endif /* HAL_USE_DAC == TRUE */

/** @} */