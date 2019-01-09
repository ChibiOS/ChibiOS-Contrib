/*
    ChibiOS - Copyright (C) 2006..2019 Giovanni Di Sirio
              Copyright (C) 2019 Fabien Poussin (fabien.poussin (at) google's mail)

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
 * @file    STM32/hal_opamp_lld.c
 * @brief   STM32 Operational Amplifier subsystem low level driver header.
 *
 * @addtogroup OPAMP
 * @{
 */

#include "hal.h"

#if HAL_USE_OPAMP || defined(__DOXYGEN__)

#include "hal_opamp.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   OPAMPD1 driver identifier.
 * @note    The driver OPAMPD1 allocates the comparator OPAMP1 when enabled.
 */
#if STM32_OPAMP_USE_OPAMP1 || defined(__DOXYGEN__)
OPAMPDriver OPAMPD1;
#endif

/**
 * @brief   OPAMPD2 driver identifier.
 * @note    The driver OPAMPD2 allocates the comparator OPAMP2 when enabled.
 */
#if STM32_OPAMP_USE_OPAMP2 || defined(__DOXYGEN__)
OPAMPDriver OPAMPD2;
#endif

/**
 * @brief   OPAMPD3 driver identifier.
 * @note    The driver OPAMPD3 allocates the comparator OPAMP3 when enabled.
 */
#if STM32_OPAMP_USE_OPAMP3 || defined(__DOXYGEN__)
OPAMPDriver OPAMPD3;
#endif

/**
 * @brief   OPAMPD4 driver identifier.
 * @note    The driver OPAMPD4 allocates the comparator OPAMP4 when enabled.
 */
#if STM32_OPAMP_USE_OPAMP4 || defined(__DOXYGEN__)
OPAMPDriver OPAMPD4;
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
 * @brief   Low level OPAMP driver initialization.
 *
 * @notapi
 */
void opamp_lld_init(void) {

#if STM32_OPAMP_USE_OPAMP1
  /* Driver initialization.*/
  opampObjectInit(&OPAMPD1);
  OPAMPD1.reg = OPAMP;
  OPAMPD1.reg->CSR = 0;
#endif

#if STM32_OPAMP_USE_OPAMP2
  /* Driver initialization.*/
  opampObjectInit(&OPAMPD2);
  OPAMPD2.reg = OPAMP2;
  OPAMPD2.reg->CSR = 0;
#endif

#if STM32_OPAMP_USE_OPAMP3
  /* Driver initialization.*/
  opampObjectInit(&OPAMPD3);
  OPAMPD3.reg = OPAMP3;
  OPAMPD3.reg->CSR = 0;
#endif

#if STM32_OPAMP_USE_OPAMP4
  /* Driver initialization.*/
  opampObjectInit(&OPAMPD4);
  OPAMPD4.reg = OPAMP4;
  OPAMPD4.reg->CSR = 0;
#endif

}

/**
 * @brief   Configures and activates the OPAMP peripheral.
 *
 * @param[in] compp      pointer to the @p OPAMPDriver object
 *
 * @notapi
 */
void opamp_lld_start(OPAMPDriver *compp) {

  // Apply CSR Execpt the enable bit.
  compp->reg->CSR = compp->config->csr & ~OPAMP_CSR_OPAMPxEN;

}

/**
 * @brief   Deactivates the comp peripheral.
 *
 * @param[in] compp      pointer to the @p OPAMPDriver object
 *
 * @notapi
 */
void opamp_lld_stop(OPAMPDriver *compp) {

  if (compp->state == OPAMP_READY) {

    compp->reg->CSR = 0;
  }

}

/**
 * @brief   Enables the output.
 *
 * @param[in] compp      pointer to the @p OPAMPDriver object
 *
 * @notapi
 */
void opamp_lld_enable(OPAMPDriver *compp) {

   compp->reg->CSR |= OPAMP_CSR_OPAMPxEN; /* Enable */
}

/**
 * @brief   Disables the output.
 *
 * @param[in] compp      pointer to the @p OPAMPDriver object
 *
 * @notapi
 */
void opamp_lld_disable(OPAMPDriver *compp) {

  compp->reg->CSR &= ~OPAMP_CSR_OPAMPxEN; /* Disable */
}

#endif /* HAL_USE_OPAMP */

/** @} */
