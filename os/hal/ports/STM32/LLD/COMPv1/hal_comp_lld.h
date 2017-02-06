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
 * @file    STM32/comp_lld.h
 * @brief   STM32 Comparator subsystem low level driver header.
 *
 * @addtogroup COMP
 * @{
 */

#ifndef HAL_COMP_LLD_H_
#define HAL_COMP_LLD_H_

#include "hal.h"

#if HAL_USE_COMP || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#if defined(STM32F303x8)

#define STM32_HAS_COMP1 FALSE
#define STM32_HAS_COMP2 TRUE
#define STM32_HAS_COMP3 FALSE
#define STM32_HAS_COMP4 TRUE
#define STM32_HAS_COMP5 FALSE
#define STM32_HAS_COMP6 FALSE
#define STM32_HAS_COMP7 FALSE

#endif

#if defined(STM32F303xC)

#define STM32_HAS_COMP1 TRUE
#define STM32_HAS_COMP2 TRUE
#define STM32_HAS_COMP3 TRUE
#define STM32_HAS_COMP4 TRUE
#define STM32_HAS_COMP5 TRUE
#define STM32_HAS_COMP6 TRUE
#define STM32_HAS_COMP7 TRUE

#endif

#if defined(STM32F303xE)

#define STM32_HAS_COMP1 TRUE
#define STM32_HAS_COMP2 TRUE
#define STM32_HAS_COMP3 TRUE
#define STM32_HAS_COMP4 TRUE
#define STM32_HAS_COMP5 TRUE
#define STM32_HAS_COMP6 TRUE
#define STM32_HAS_COMP7 TRUE

#endif

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */

/**
 * @brief   COMP INTERRUPTS.
 * @details If set to @p TRUE the support for COMPD1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_COMP_USE_INTERRUPTS) || defined(__DOXYGEN__)
#define STM32_COMP_USE_INTERRUPTS             FALSE
#endif

/**
 * @brief   COMPD1 driver enable switch.
 * @details If set to @p TRUE the support for COMPD1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_COMP_USE_COMP1) || defined(__DOXYGEN__)
#define STM32_COMP_USE_COMP1                  FALSE
#endif

/**
 * @brief   COMPD2 driver enable switch.
 * @details If set to @p TRUE the support for COMPD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_COMP_USE_COMP2) || defined(__DOXYGEN__)
#define STM32_COMP_USE_COMP2                  FALSE
#endif

/**
 * @brief   COMPD3 driver enable switch.
 * @details If set to @p TRUE the support for COMPD3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_COMP_USE_COMP3) || defined(__DOXYGEN__)
#define STM32_COMP_USE_COMP3                  FALSE
#endif

/**
 * @brief   COMPD4 driver enable switch.
 * @details If set to @p TRUE the support for COMPD4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_COMP_USE_COMP4) || defined(__DOXYGEN__)
#define STM32_COMP_USE_COMP4                  FALSE
#endif

/**
 * @brief   COMPD5 driver enable switch.
 * @details If set to @p TRUE the support for COMPD4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_COMP_USE_COMP5) || defined(__DOXYGEN__)
#define STM32_COMP_USE_COMP5                  FALSE
#endif

/**
 * @brief   COMPD6 driver enable switch.
 * @details If set to @p TRUE the support for COMPD4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_COMP_USE_COMP6) || defined(__DOXYGEN__)
#define STM32_COMP_USE_COMP6                  FALSE
#endif

/**
 * @brief   COMPD7 driver enable switch.
 * @details If set to @p TRUE the support for COMPD4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_COMP_USE_COMP7) || defined(__DOXYGEN__)
#define STM32_COMP_USE_COMP7                  FALSE
#endif

/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if STM32_COMP_USE_INTERRUPTS && !HAL_USE_EXT
#error "COMP needs HAL_USE_EXT to use interrupts"
#endif

#if STM32_COMP_USE_INTERRUPTS
#include "hal_ext_lld.h"
#endif

#if STM32_COMP_USE_COMP1 && !STM32_HAS_COMP1
#error "COMP1 not present in the selected device"
#endif

#if STM32_COMP_USE_COMP2 && !STM32_HAS_COMP2
#error "COMP2 not present in the selected device"
#endif

#if STM32_COMP_USE_COMP3 && !STM32_HAS_COMP3
#error "COMP3 not present in the selected device"
#endif

#if STM32_COMP_USE_COMP4 && !STM32_HAS_COMP4
#error "COMP4 not present in the selected device"
#endif

#if STM32_COMP_USE_COMP5 && !STM32_HAS_COMP5
#error "COMP5 not present in the selected device"
#endif

#if STM32_COMP_USE_COMP6 && !STM32_HAS_COMP6
#error "COMP6 not present in the selected device"
#endif

#if STM32_COMP_USE_COMP7 && !STM32_HAS_COMP7
#error "COMP7 not present in the selected device"
#endif

#if !STM32_COMP_USE_COMP1 && !STM32_COMP_USE_COMP2 &&                         \
    !STM32_COMP_USE_COMP3 && !STM32_COMP_USE_COMP4 &&                         \
    !STM32_COMP_USE_COMP6 && !STM32_COMP_USE_COMP6 &&                         \
    !STM32_COMP_USE_COMP7
#error "COMP driver activated but no COMP peripheral assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   COMP output mode.
 */
typedef enum {
  COMP_OUTPUT_NORMAL = 0,
  COMP_OUTPUT_INVERTED = 1
} comp_output_mode_t;


/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /**
   * @brief   Ouput mode.
   */
  comp_output_mode_t           mode;

  /**
   * @brief   Callback.
   */
  compcallback_t             cb;

  /* End of the mandatory fields.*/

  /**
   * @brief COMP CSR register initialization data.
   * @note  The value of this field should normally be equal to zero.
   */
  uint32_t                  csr;
} COMPConfig;

/**
 * @brief   Structure representing an TIMCAP driver.
 */
struct COMPDriver {
  /**
   * @brief Driver state.
   */
  compstate_t                state;
  /**
   * @brief Current configuration data.
   */
  const COMPConfig           *config;
#if defined(COMP_DRIVER_EXT_FIELDS)
  COMP_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief Pointer to the COMPx registers block.
   */
  COMP_TypeDef               *comp;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if STM32_COMP_USE_COMP1 && !defined(__DOXYGEN__)
extern COMPDriver COMPD1;
#endif

#if STM32_COMP_USE_COMP2 && !defined(__DOXYGEN__)
extern COMPDriver COMPD2;
#endif

#if STM32_COMP_USE_COMP3 && !defined(__DOXYGEN__)
extern COMPDriver COMPD3;
#endif

#if STM32_COMP_USE_COMP4 && !defined(__DOXYGEN__)
extern COMPDriver COMPD4;
#endif

#if STM32_COMP_USE_COMP5 && !defined(__DOXYGEN__)
extern COMPDriver COMPD5;
#endif

#if STM32_COMP_USE_COMP6 && !defined(__DOXYGEN__)
extern COMPDriver COMPD6;
#endif

#if STM32_COMP_USE_COMP7 && !defined(__DOXYGEN__)
extern COMPDriver COMPD7;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void comp_lld_init(void);
  void comp_lld_start(COMPDriver *timcapp);
  void comp_lld_stop(COMPDriver *timcapp);
  void comp_lld_enable(COMPDriver *timcapp);
  void comp_lld_disable(COMPDriver *timcapp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_COMP */

#endif /* _comp_lld_H_ */

/** @} */
