/*
    ChibiOS/HAL - Copyright (C) 2024 Xael South

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
 * @file    hal_buram_lld.h
 * @brief   BURAM Driver subsystem low level driver header.
 *
 * @addtogroup BURAM
 * @{
 */

#ifndef HAL_BURAM_LLD_H_
#define HAL_BURAM_LLD_H_


/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#define BURAM1_ADDRESS          (BURAM_BASE + 0UL)
#define BURAM1_SIZE             32U

#define BURAM2_ADDRESS          (BURAM1_ADDRESS + BURAM1_SIZE)
#define BURAM2_SIZE             32U

#define BURAM3_ADDRESS          (BURAM2_ADDRESS + BURAM2_SIZE)
#define BURAM3_SIZE             32U

#define BURAM4_ADDRESS          (BURAM3_ADDRESS + BURAM3_SIZE)
#define BURAM4_SIZE             32U

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if BURAM1_SIZE % 32U != 0U
#error "BURAM1_SIZE has to be a multiple of 32!"
#endif

#if BURAM2_SIZE % 32U != 0U
#error "BURAM2_SIZE has to be a multiple of 32!"
#endif

#if BURAM3_SIZE % 32U != 0U
#error "BURAM3_SIZE has to be a multiple of 32!"
#endif

#if BURAM4_SIZE % 32U != 0U
#error "BURAM4_SIZE has to be a multiple of 32!"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/
/**
 * @brief   Type of a structure representing a BURAM driver.
 */
typedef struct BURAMDriver BURAMDriver;

/**
 * @brief   Type of a structure representing a BURAM driver configuration.
 */
typedef struct BURAMConfig BURAMConfig;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/
#if BURAM_USE_BURAM1 && !defined(__DOXYGEN__)
extern BURAMDriver BURAMD1;
#endif

#if BURAM_USE_BURAM2 && !defined(__DOXYGEN__)
extern BURAMDriver BURAMD2;
#endif

#if BURAM_USE_BURAM3 && !defined(__DOXYGEN__)
extern BURAMDriver BURAMD3;
#endif

#if BURAM_USE_BURAM4 && !defined(__DOXYGEN__)
extern BURAMDriver BURAMD4;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void buram_lld_start(BURAMDriver *sramp, const BURAMConfig *cfgp);
  void buram_lld_stop(BURAMDriver *sramp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_BURAM_LLD_H_ */

/** @} */
