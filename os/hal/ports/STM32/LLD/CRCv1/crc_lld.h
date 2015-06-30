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
 * @file    STM32/CRCv1/crc_lld.h
 * @brief   STM32 CRC subsystem low level driver header.
 *
 * @addtogroup CRC
 * @{
 */

#ifndef _CRC_LLD_H_
#define _CRC_LLD_H_

#if HAL_USE_CRC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   CRC1 driver enable switch.
 * @details If set to @p TRUE the support for CRC1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_CRC_USE_CRC1) || defined(__DOXYGEN__)
#define STM32_CRC_USE_CRC1                  FALSE
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if defined(STM32_CRC_USE_CRC1) && CRCSW_USE_CRC1
#error "Software CRC and STM32 CRC1 block conflict"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

#if STM32_CRC_USE_CRC1 && !defined(__DOXYGEN__)
/**
 * @brief   Type of a structure representing an CRC driver.
 */
typedef struct CRCDriver CRCDriver;

/**
 * @brief   Driver configuration structure.
 */
typedef struct {

  /**
   * @brief The size of polynomial to be used for CRC.
   */
  uint32_t                 poly_size;
  /**
   * @brief The coefficients of the polynomial to be used for CRC.
   */
  uint32_t                 poly;
  /**
   * @brief The inital value
   */
  uint32_t                 initial_val;
  /**
   * @brief The final XOR value
   */
  uint32_t                 final_val;
  /* End of the mandatory fields.*/
  /**
   * @brief CRC CR register initialization data.
   */
  uint32_t                  cr;
} CRCConfig;


/**
 * @brief   Structure representing an CRC driver.
 */
struct CRCDriver {
  /**
   * @brief Driver state.
   */
  crcstate_t                state;
  /**
   * @brief Current configuration data.
   */
  const CRCConfig           *config;
#if CRC_USE_MUTUAL_EXCLUSION || defined(__DOXYGEN__)
  /**
   * @brief   Mutex protecting the peripheral.
   */
  mutex_t                   mutex;
#endif /* CRC_USE_MUTUAL_EXCLUSION */
  /* End of the mandatory fields.*/
  /**
   * @brief Pointer to the CRCx registers block.
   */
  CRC_TypeDef               *crc;
};

#endif

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if STM32_CRC_USE_CRC1 && !defined(__DOXYGEN__)
extern CRCDriver CRCD1;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void crc_lld_init(void);
  void crc_lld_start(CRCDriver *crcp);
  void crc_lld_stop(CRCDriver *crcp);
  void crc_lld_reset(CRCDriver *crcp);
  uint32_t crc_lld_calc_byte(CRCDriver *crcp, uint8_t data);
  uint32_t crc_lld_calc_halfword(CRCDriver *crcp, uint16_t data);
  uint32_t crc_lld_calc_word(CRCDriver *crcp, uint32_t data);
  uint32_t crc_lld_calc(CRCDriver *crcp, uint8_t *data, uint32_t size);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_CRC */

#endif /* _CRC_LLD_H_ */

/** @} */
