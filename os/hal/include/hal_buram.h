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
 * @file    hal_buram.h
 * @brief   BURAM Driver subsystem low level driver header.
 *
 * @addtogroup BURAM
 * @{
 */

#ifndef HAL_BURAM_H_
#define HAL_BURAM_H_

#if (HAL_USE_BURAM == TRUE) || defined(__DOXYGEN__)

#include "bitmap.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

#include "hal_buram_lld.h"

/**
 * @brief   Driver state machine possible states.
 */
typedef enum {
  BURAM_UNINIT = 0,                   /**< Not initialized.                */
  BURAM_STOP = 1,                     /**< Stopped.                        */
  BURAM_READY = 2,                    /**< Ready.                          */
} buramstate_t;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
struct BURAMConfig {

  #if defined(buram_lld_config_ext_fields)
  buram_lld_config_ext_fields
  #endif
};

/**
 * @brief   Structure representing an BURAM driver.
 */
struct BURAMDriver {
  /**
   * @brief   Driver state.
   */
  buramstate_t               state;

  /**
   * @brief   Backup RAM start address.
   */
  uintptr_t                  start;

  /**
   * @brief   Backup RAM end address.
   */
  uintptr_t                  end;

  /**
   * @brief   Map of allocated backup RAM.
   */
  bitmap_t                   buram_map;

  #if defined(buram_lld_driver_fields)
  buram_lld_driver_fields
  #endif
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void buramInit(void);
  void buramObjectInit(BURAMDriver *sdramp);
  void buramStart(BURAMDriver *buramp, const BURAMConfig *cfgp);
  void buramStop(BURAMDriver *buramp);
  volatile void* buramAllocateAtI(BURAMDriver* buramp, uintptr_t address, size_t size);
  volatile void* buramAllocateAt(BURAMDriver *buramp, uintptr_t address, size_t size);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_BURAM */

#endif /* HAL_BURAM_H_ */

/** @} */
