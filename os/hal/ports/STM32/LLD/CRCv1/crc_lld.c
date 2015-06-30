/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

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
 * @file    STM32/CRCv1/crc_lld.c
 * @brief   STM32 CRC subsystem low level driver source.
 *
 * @addtogroup CRC
 * @{
 */

#include "hal.h"

#if HAL_USE_CRC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   CRC default configuration.
 */
static const CRCConfig default_config = {
  .poly_size   = 32,
  .poly        = 0x04C11DB7,
  .initial_val = 0xFFFFFFFF,
  .final_val   = 0xFFFFFFFF,
  .cr          = CRC_CR_REV_IN_0 | CRC_CR_REV_OUT
};

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief CRC1 driver identifier.*/
#if STM32_CRC_USE_CRC1 || defined(__DOXYGEN__)
CRCDriver CRCD1;
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
 * @brief   Low level CRC driver initialization.
 *
 * @notapi
 */
void crc_lld_init(void) {
#if STM32_CRC_USE_CRC1
  crcObjectInit(&CRCD1);
  CRCD1.crc = CRC;
#endif
}

/**
 * @brief   Configures and activates the CRC peripheral.
 *
 * @param[in] crcp      pointer to the @p CRCDriver object
 *
 * @notapi
 */
void crc_lld_start(CRCDriver *crcp) {
  if (crcp->config == NULL)
    crcp->config = &default_config;

  rccEnableCRC(FALSE);

  crcp->crc->CR = crcp->config->cr;

  switch(crcp->config->poly_size) {
    case 32:
      break;
    case 16:
      crcp->crc->CR |= CRC_CR_POLYSIZE_0;
      break;
    case 8:
      crcp->crc->CR |= CRC_CR_POLYSIZE_1;
      break;
    case 7:
      crcp->crc->CR |= CRC_CR_POLYSIZE_1 | CRC_CR_POLYSIZE_0;
      break;
    default:
      osalDbgAssert(false, "STM32 Hardware doesn't support polynomial");
      break;
  };

  crcp->crc->INIT = crcp->config->initial_val;
  crcp->crc->POL = crcp->config->poly;

  crc_lld_reset(crcp);
}
  

/**
 * @brief   Deactivates the CRC peripheral.
 *
 * @param[in] crcp      pointer to the @p CRCDriver object
 *
 * @notapi
 */
void crc_lld_stop(CRCDriver *crcp) {
  (void)crcp;
  rccDisableCRC(FALSE);
}

/**
 * @brief   Resets current CRC calculation.
 *
 * @param[in] crcp      pointer to the @p CRCDriver object
 *
 * @notapi
 */
void crc_lld_reset(CRCDriver *crcp) {
  crcp->crc->CR |= CRC_CR_RESET;
}

/**
 * @brief   Returns calculated CRC from last reset
 *
 * @param[in] crcp      pointer to the @p CRCDriver object
 * @param[in] data      data to be added to crc
 *
 * @notapi
 */
uint32_t crc_lld_calc_byte(CRCDriver *crcp, uint8_t data) {
  __IO uint8_t *crc8 = (__IO uint8_t*)&(crcp->crc->DR);
  *crc8 = data;
  return crcp->crc->DR ^ crcp->config->final_val;
}

/*
 * @brief   Returns calculated CRC from last reset
 *
 * @param[in] crcp      pointer to the @p CRCDriver object
 * @param[in] data      data to be added to crc
 *
 * @notapi
 */
uint32_t crc_lld_calc_halfword(CRCDriver *crcp, uint16_t data) {
  __IO uint16_t *crc16 = (__IO uint16_t*)&(crcp->crc->DR);
  *crc16 = data;
  return crcp->crc->DR ^ crcp->config->final_val;
}

/*
 * @brief   Returns calculated CRC from last reset
 *
 * @param[in] crcp      pointer to the @p CRCDriver object
 * @param[in] data      data to be added to crc
 *
 * @notapi
 */
uint32_t crc_lld_calc_word(CRCDriver *crcp, uint32_t data) {
  crcp->crc->DR = data;
  return crcp->crc->DR ^ crcp->config->final_val;
}

/**
 * @brief   Returns calculated CRC from last reset
 *
 * @param[in] crcp      pointer to the @p CRCDriver object
 * @param[in] data      data to be added to crc
 * @param[in] size      size of data to be added to crc
 *
 * @notapi
 */
uint32_t crc_lld_calc(CRCDriver *crcp, uint8_t *data, uint32_t size) {
  uint32_t i;

  for (i = 0; i < size; i++)
    crc_lld_calc_byte(crcp, *(data+i));

  return crcp->crc->DR ^ crcp->config->final_val;
}

#endif /* HAL_USE_CRC */

/** @} */
