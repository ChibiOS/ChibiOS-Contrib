/*
    ChibiOS - Copyright (C) 2006..2017 Giovanni Di Sirio
              Copyright (C) 2017 Fabien Poussin (fabien.poussin (at) google's mail)

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
 * @file    STM32/hal_comp_lld.c
 * @brief   STM32 Comp subsystem low level driver header.
 *
 * @addtogroup COMP
 * @{
 */

#include "hal.h"

#if HAL_USE_COMP || defined(__DOXYGEN__)

#include "hal_comp.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   COMPD1 driver identifier.
 * @note    The driver COMPD1 allocates the comparator COMP1 when enabled.
 */
#if STM32_COMP_USE_COMP1 || defined(__DOXYGEN__)
COMPDriver COMPD1;
#endif

/**
 * @brief   COMPD2 driver identifier.
 * @note    The driver COMPD2 allocates the comparator COMP2 when enabled.
 */
#if STM32_COMP_USE_COMP2 || defined(__DOXYGEN__)
COMPDriver COMPD2;
#endif

/**
 * @brief   COMPD3 driver identifier.
 * @note    The driver COMPD3 allocates the comparator COMP3 when enabled.
 */
#if STM32_COMP_USE_COMP3 || defined(__DOXYGEN__)
COMPDriver COMPD3;
#endif

/**
 * @brief   COMPD4 driver identifier.
 * @note    The driver COMPD4 allocates the comparator COMP4 when enabled.
 */
#if STM32_COMP_USE_COMP4 || defined(__DOXYGEN__)
COMPDriver COMPD4;
#endif

/**
 * @brief   COMPD5 driver identifier.
 * @note    The driver COMPD5 allocates the comparator COMP5 when enabled.
 */
#if STM32_COMP_USE_COMP5 || defined(__DOXYGEN__)
COMPDriver COMPD5;
#endif

/**
 * @brief   COMPD6 driver identifier.
 * @note    The driver COMPD6 allocates the comparator COMP6 when enabled.
 */
#if STM32_COMP_USE_COMP6 || defined(__DOXYGEN__)
COMPDriver COMPD6;
#endif

/**
 * @brief   COMPD7 driver identifier.
 * @note    The driver COMPD7 allocates the comparator COMP7 when enabled.
 */
#if STM32_COMP_USE_COMP7 || defined(__DOXYGEN__)
COMPDriver COMPD7;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

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
 * @brief   Low level COMP driver initialization.
 *
 * @notapi
 */
void comp_lld_init(void) {

#if STM32_COMP_USE_COMP1
  /* Driver initialization.*/
  compObjectInit(&COMPD1);
  COMPD1.comp = COMP;
#endif

#if STM32_COMP_USE_COMP2
  /* Driver initialization.*/
  compObjectInit(&COMPD2);
  COMPD2.comp = COMP2;
#endif

#if STM32_COMP_USE_COMP3
  /* Driver initialization.*/
  compObjectInit(&COMPD3);
  COMPD3.comp = COMP3;
#endif

#if STM32_COMP_USE_COMP4
  /* Driver initialization.*/
  compObjectInit(&COMPD4);
  COMPD4.comp = COMP4;
#endif

#if STM32_COMP_USE_COMP5
  /* Driver initialization.*/
  compObjectInit(&COMPD5);
  COMPD8.comp = COMP5;
#endif

#if STM32_COMP_USE_COMP6
  /* Driver initialization.*/
  compObjectInit(&COMPD6);
  COMPD6.comp = COMP6;
#endif

#if STM32_COMP_USE_COMP7
  /* Driver initialization.*/
  compObjectInit(&COMPD7);
  COMPD7.comp = COMP7;
#endif

}
#if STM32_COMP_USE_INTERRUPTS
static void comp_lld_cb(EXTDriver *extp, expchannel_t channel) {

  (void) extp;
  switch (channel) {

#if STM32_COMP_USE_COMP1
    case 21:
      COMPD1.config->cb(&COMPD1);
#endif
#if STM32_COMP_USE_COMP2
    case 22:
      COMPD2.config->cb(&COMPD2);
#endif
#if STM32_COMP_USE_COMP3
    case 29:
      COMPD3.config->cb(&COMPD3);
#endif
#if STM32_COMP_USE_COMP4
    case 30:
      COMPD4.config->cb(&COMPD4);
#endif
#if STM32_COMP_USE_COMP5
    case 31:
      COMPD5.config->cb(&COMPD5);
#endif
#if STM32_COMP_USE_COMP6
    case 32:
      COMPD6.config->cb(&COMPD6);
#endif
#if STM32_COMP_USE_COMP7
    case 33:
      COMPD7.config->cb(&COMPD7);
#endif
    default:
      return;
    }

}
#endif

/**
 * @brief   Configures and activates the COMP peripheral.
 *
 * @param[in] compp      pointer to the @p COMPDriver object
 *
 * @notapi
 */
void comp_lld_start(COMPDriver *compp) {

  // Apply CSR Execpt the enable bit.
  compp->comp->CSR = compp->config->csr & ~COMP_CSR_COMPxEN;

  // Inverted output
  if (compp->config->mode == COMP_OUTPUT_INVERTED)
    compp->comp->CSR |= COMP_CSR_COMPxPOL;

  EXTChannelConfig chn_cfg = {EXT_CH_MODE_BOTH_EDGES, comp_lld_cb};
  EXTConfig *cfg = (EXTConfig*)EXTD1.config;


#if STM32_COMP_USE_COMP1 && STM32_COMP_USE_INTERRUPTS
    if (&COMPD1 == compp) {
      cfg->channels[21] = chn_cfg;
      ext_lld_channel_enable(&EXTD1, 21);
    }
#endif
#if STM32_COMP_USE_COMP2 && STM32_COMP_USE_INTERRUPTS
    if (&COMPD2 == compp) {
      cfg->channels[22] = chn_cfg;
      ext_lld_channel_enable(&EXTD1, 22);
    }
#endif
#if STM32_COMP_USE_COMP3 && STM32_COMP_USE_INTERRUPTS
    if (&COMPD3 == compp) {
      cfg->channels[29] = chn_cfg;
      ext_lld_channel_enable(&EXTD1, 29);
    }
#endif
#if STM32_COMP_USE_COMP4 && STM32_COMP_USE_INTERRUPTS
    if (&COMPD4 == compp) {
      cfg->channels[30] = chn_cfg;
      ext_lld_channel_enable(&EXTD1, 30);
    }
#endif
#if STM32_COMP_USE_COMP5 && STM32_COMP_USE_INTERRUPTS
    if (&COMPD5 == compp) {
      cfg->channels[31] = chn_cfg;
      ext_lld_channel_enable(&EXTD1, 31);
    }
#endif
#if STM32_COMP_USE_COMP6 && STM32_COMP_USE_INTERRUPTS
    if (&COMPD6 == compp) {
      cfg->channels[32] = chn_cfg;
      ext_lld_channel_enable(&EXTD1, 32);
    }
#endif
#if STM32_COMP_USE_COMP7 && STM32_COMP_USE_INTERRUPTS
    if (&COMPD7 == compp) {
      cfg->channels[33] = chn_cfg;
      ext_lld_channel_enable(&EXTD1, 33);
    }
#endif

}

/**
 * @brief   Deactivates the comp peripheral.
 *
 * @param[in] compp      pointer to the @p COMPDriver object
 *
 * @notapi
 */
void comp_lld_stop(COMPDriver *compp) {

  if (compp->state == COMP_READY) {


#if STM32_COMP_USE_COMP1 && STM32_COMP_USE_INTERRUPTS
    if (&COMPD1 == compp) {
      ext_lld_channel_disable(&EXTD1, 21);
    }
#endif
#if STM32_COMP_USE_COMP2 && STM32_COMP_USE_INTERRUPTS
    if (&COMPD2 == compp) {
      ext_lld_channel_disable(&EXTD1, 22);
    }
#endif
#if STM32_COMP_USE_COMP3 && STM32_COMP_USE_INTERRUPTS
    if (&COMPD3 == compp) {
      ext_lld_channel_disable(&EXTD1, 29);
    }
#endif
#if STM32_COMP_USE_COMP4 && STM32_COMP_USE_INTERRUPTS
    if (&COMPD4 == compp) {
      ext_lld_channel_disable(&EXTD1, 30);
    }
#endif
#if STM32_COMP_USE_COMP5 && STM32_COMP_USE_INTERRUPTS
    if (&COMPD5 == compp) {
      ext_lld_channel_disable(&EXTD1, 31);
    }
#endif
#if STM32_COMP_USE_COMP6 && STM32_COMP_USE_INTERRUPTS
    if (&COMPD6 == compp) {
      ext_lld_channel_disable(&EXTD1, 32);
    }
#endif
#if STM32_COMP_USE_COMP7 && STM32_COMP_USE_INTERRUPTS
    if (&COMPD7 == compp) {
      ext_lld_channel_disable(&EXTD1, 33);
    }
#endif
  }
}

/**
 * @brief   Enables the output.
 *
 * @param[in] compp      pointer to the @p COMPDriver object
 *
 * @notapi
 */
void comp_lld_enable(COMPDriver *compp) {

   compp->comp->CSR |= COMP_CSR_COMPxEN; /* Enable */

}

/**
 * @brief   Disables the output.
 *
 * @param[in] compp      pointer to the @p COMPDriver object
 *
 * @notapi
 */
void comp_lld_disable(COMPDriver *compp) {

  compp->comp->CSR &= ~COMP_CSR_COMPxEN; /* Disable */

}

#endif /* HAL_USE_COMP */

/** @} */
