/*
    ChibiOS/RT - Copyright (C) 2006-2015 Giovanni Di Sirio

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
/*
   Rewritten by Emil Fresk (1/5 - 2014) for extended input capture
   functionality. And fix for spurious callbacks in the interrupt handler.
*/
/*
   Improved by Uladzimir Pylinsky aka barthess (1/3 - 2015) for support of
   32-bit timers and timers with single capture/compare channels.
*/

#ifndef _CRC_H_
#define _CRC_H_

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
 * @brief   CRC1 software driver enable switch.
 * @details If set to @p TRUE the support for CRC1 is included.
 * @note    The default is @p TRUE
 */
#if !defined(CRCSW_USE_CRC1) || defined(__DOXYGEN__)
#define CRCSW_USE_CRC1                  FALSE
#endif

/**
 * @brief   Enables the @p crcAcquireBus() and @p crcReleaseBus() APIs.
 * @note    Disabling this option saves both code and data space.
 */
#if !defined(CRC_USE_MUTUAL_EXCLUSION) || defined(__DOXYGEN__)
#define CRC_USE_MUTUAL_EXCLUSION        TRUE
#endif

/**
 * @brief Enables software CRC32
 */
#if !defined(CRCSW_CRC32) || defined(__DOXYGEN__)
#define CRCSW_CRC32                     FALSE
#endif

/**
 * @brief Enables software CRC16
 */
#if !defined(CRCSW_CRC16) || defined(__DOXYGEN__)
#define CRCSW_CRC16                     FALSE
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if CRCSW_USE_CRC1
#if (CRCSW_CRC32 == FALSE) && (CRCSW_CRC16 == FALSE)
#error "At least one of CRCSW_CRC32 or CRCSw_CRC16 must be defined"
#endif
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Driver state machine possible states.
 */
typedef enum {
  CRC_UNINIT,                /* Not initialized.                           */
  CRC_STOP,                  /* Stopped.                                   */
  CRC_READY,                 /* Ready.                                     */
  CRC_WAITING,               /* Waiting for first edge.                    */
  CRC_ACTIVE,                /* Active cycle phase.                        */
  CRC_IDLE                   /* Idle cycle phase.                          */
} crcstate_t;

#if CRCSW_USE_CRC1 && !defined(__DOXYGEN__)
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
   * @brief The crc lookup table to use when calculating CRC.
   */
  const uint32_t           *table;
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
   * @brief Current value of calculated CRC.
   */
  uint32_t                  crc;
};

#else 
#include "crc_lld.h"
#endif /* CRCSW_USE_CRC1 */


/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

#if CRCSW_CRC32
#define CRCSW_CRC32_CONFIG (&crcsw_crc32_config)
#endif

#if CRCSW_CRC16
#define CRCSW_CRC16_CONFIG (&crcsw_crc16_config)
#endif

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if CRCSW_USE_CRC1 && !defined(__DOXYGEN__)
extern CRCDriver CRCD1;
#endif

#if CRCSW_CRC32
extern const CRCConfig crcsw_crc32_config;
#endif

#if CRCSW_CRC16
extern const CRCConfig crcsw_crc16_config;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void crcInit(void);
  void crcObjectInit(CRCDriver *crcp);
  void crcStart(CRCDriver *crcp, const CRCConfig *config);
  void crcStop(CRCDriver *crcp);
  void crcReset(CRCDriver *crcp);
  uint32_t crcCalcByte(CRCDriver *crcp, uint8_t data);
  uint32_t crcCalcHalfWord(CRCDriver *crcp, uint16_t data);
  uint32_t crcCalcWord(CRCDriver *crcp, uint32_t data);
  uint32_t crcCalc(CRCDriver *crcp, uint8_t *data, uint32_t size);
#if CRC_USE_MUTUAL_EXCLUSION
  void crcAcquireUnit(CRCDriver *crcp);
  void crcReleaseUnit(CRCDriver *crcp);
#endif
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_CRC */

#endif /* _CRC_H_ */

/** @} */
