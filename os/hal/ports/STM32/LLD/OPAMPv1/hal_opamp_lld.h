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
 * @file    STM32/opamp_lld.h
 * @brief   STM32 Operational Amplifier subsystem low level driver header.
 *
 * @addtogroup OPAMP
 * @{
 */

#ifndef HAL_OPAMP_LLD_H_
#define HAL_OPAMP_LLD_H_

#include "hal.h"

#if HAL_USE_OPAMP || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/


#define STM32_OPAMP_InvertingInput_IO1          ((uint32_t)0x00000000) /*!< IO1 (PC5 for OPAMP1 and OPAMP2, PB10 for OPAMP3 and OPAMP4)
                                                                       connected to OPAMPx inverting input */
#define STM32_OPAMP_InvertingInput_IO2          OPAMP_CSR_VMSEL_0      /*!< IO2 (PA3 for OPAMP1, PA5 for OPAMP2, PB2 for OPAMP3, PD8 for OPAMP4)
                                                                       connected to OPAMPx inverting input */
#define STM32_OPAMP_InvertingInput_PGA          OPAMP_CSR_VMSEL_1      /*!< Resistor feedback output connected to OPAMPx inverting input (PGA mode) */
#define STM32_OPAMP_InvertingInput_Vout         OPAMP_CSR_VMSEL        /*!< Vout connected to OPAMPx inverting input (follower mode) */


#define STM32_OPAMP_NonInvertingInput_IO1       ((uint32_t)0x00000000) /*!< IO1 (PA7 for OPAMP1, PD14 for OPAMP2, PB13 for OPAMP3, PD11 for OPAMP4)
                                                                       connected to OPAMPx non inverting input */
#define STM32_OPAMP_NonInvertingInput_IO2       OPAMP_CSR_VPSEL_0      /*!< IO2 (PA5 for OPAMP1, PB14 for OPAMP2, PA5 for OPAMP3, PB11 for OPAMP4)
                                                                       connected to OPAMPx non inverting input */
#define STM32_OPAMP_NonInvertingInput_IO3       OPAMP_CSR_VPSEL_1      /*!< IO3 (PA3 for OPAMP1, PB0 for OPAMP2, PA1 for OPAMP3, PA4 for OPAMP4)
                                                                       connected to OPAMPx non inverting input */
#define STM32_OPAMP_NonInvertingInput_IO4       OPAMP_CSR_VPSEL        /*!< IO4 (PA1 for OPAMP1, PA7 for OPAMP2, PB0 for OPAMP3, PB13 for OPAMP4)
                                                                       connected to OPAMPx non inverting input */


#define STM32_OPAMP_PGAGain_2                   ((uint32_t)0x00000000)
#define STM32_OPAMP_PGAGain_4                   OPAMP_CSR_PGGAIN_0
#define STM32_OPAMP_PGAGain_8                   OPAMP_CSR_PGGAIN_1
#define STM32_OPAMP_PGAGain_16                  ((uint32_t)0x0000C000)

#define STM32_OPAMP_PGAConnect_No               ((uint32_t)0x00000000)
#define STM32_OPAMP_PGAConnect_IO1              OPAMP_CSR_PGGAIN_3
#define STM32_OPAMP_PGAConnect_IO2              ((uint32_t)0x00030000)

#define STM32_OPAMP_Input_Inverting             ((uint32_t)0x00000018) /*!< Inverting input */
#define STM32_OPAMP_Input_NonInverting          ((uint32_t)0x00000013) /*!< Non inverting input */

#define STM32_OPAMP_Vref_3VDDA                  ((uint32_t)0x00000000) /*!< OPMAP Vref = 3.3% VDDA */
#define STM32_OPAMP_Vref_10VDDA                 OPAMP_CSR_CALSEL_0     /*!< OPMAP Vref = 10% VDDA  */
#define STM32_OPAMP_Vref_50VDDA                 OPAMP_CSR_CALSEL_1     /*!< OPMAP Vref = 50% VDDA  */
#define STM32_OPAMP_Vref_90VDDA                 OPAMP_CSR_CALSEL       /*!< OPMAP Vref = 90% VDDA  */

#define STM32_OPAMP_Trimming_Factory            ((uint32_t)0x00000000) /*!< Factory trimming */
#define STM32_OPAMP_Trimming_User               OPAMP_CSR_USERTRIM     /*!< User trimming */

#define STM32_OPAMP_OutputLevel_High            OPAMP_CSR_OUTCAL
#define STM32_OPAMP_OutputLevel_Low             ((uint32_t)0x00000000)


#if defined(STM32F302xB) || defined(STM32F302xC) || defined(STM32F302xD) \
|| defined(STM32F302xE) || defined(STM32F302xc) || defined(STM32F302xe) \
|| defined(STM32L1XX) || defined(STM32L4XX) || defined(STM32H7XX)
#define STM32_HAS_OPAMP1 TRUE
#define STM32_HAS_OPAMP2 TRUE
#define STM32_HAS_OPAMP3 FALSE
#define STM32_HAS_OPAMP4 FALSE

#elif defined(STM32F303xB) || defined(STM32F303xC) || defined(STM32F303xE) \
|| defined(STM32F358xx) || defined(STM32F398xx)
#define STM32_HAS_OPAMP1 TRUE
#define STM32_HAS_OPAMP2 TRUE
#define STM32_HAS_OPAMP3 TRUE
#define STM32_HAS_OPAMP4 TRUE

#else
#define STM32_HAS_OPAMP1 FALSE
#define STM32_HAS_OPAMP2 FALSE
#define STM32_HAS_OPAMP3 FALSE
#define STM32_HAS_OPAMP4 FALSE

#endif


/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */

/**
 * @brief   OPAMPD1 driver enable switch.
 * @details If set to @p TRUE the support for OPAMPD1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_OPAMP_USE_OPAMP1) || defined(__DOXYGEN__)
#define STM32_OPAMP_USE_OPAMP1                  FALSE
#endif

/**
 * @brief   OPAMPD2 driver enable switch.
 * @details If set to @p TRUE the support for OPAMPD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_OPAMP_USE_OPAMP2) || defined(__DOXYGEN__)
#define STM32_OPAMP_USE_OPAMP2                  FALSE
#endif

/**
 * @brief   OPAMPD3 driver enable switch.
 * @details If set to @p TRUE the support for OPAMPD3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_OPAMP_USE_OPAMP3) || defined(__DOXYGEN__)
#define STM32_OPAMP_USE_OPAMP3                  FALSE
#endif

/**
 * @brief   OPAMPD4 driver enable switch.
 * @details If set to @p TRUE the support for OPAMPD4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_OPAMP_USE_OPAMP4) || defined(__DOXYGEN__)
#define STM32_OPAMP_USE_OPAMP4                  FALSE
#endif


/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/


#if STM32_OPAMP_USE_OPAMP1 && !STM32_HAS_OPAMP1
#error "OPAMP1 not present in the selected device"
#endif

#if STM32_OPAMP_USE_OPAMP2 && !STM32_HAS_OPAMP2
#error "OPAMP2 not present in the selected device"
#endif

#if STM32_OPAMP_USE_OPAMP3 && !STM32_HAS_OPAMP3
#error "OPAMP3 not present in the selected device"
#endif

#if STM32_OPAMP_USE_OPAMP4 && !STM32_HAS_OPAMP4
#error "OPAMP4 not present in the selected device"
#endif

#if !STM32_OPAMP_USE_OPAMP1 && !STM32_OPAMP_USE_OPAMP2 &&                         \
    !STM32_OPAMP_USE_OPAMP3 && !STM32_OPAMP_USE_OPAMP4
#error "OPAMP driver activated but no OPAMP peripheral assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /**
   * @brief OPAMP CSR register initialization data.
   * @note  The value of this field should normally be equal to zero.
   */
  uint32_t                  csr;
} OPAMPConfig;

/**
 * @brief   Structure representing an OPAMP driver.
 */
struct OPAMPDriver {
  /**
   * @brief Driver state.
   */
  opampstate_t                state;
  /**
   * @brief Current configuration data.
   */
  const OPAMPConfig           *config;
#if defined(OPAMP_DRIVER_EXT_FIELDS)
  OPAMP_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief Pointer to the OPAMPx registers block.
   */
  OPAMP_TypeDef               *reg;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if STM32_OPAMP_USE_OPAMP1 && !defined(__DOXYGEN__)
extern OPAMPDriver OPAMPD1;
#endif

#if STM32_OPAMP_USE_OPAMP2 && !defined(__DOXYGEN__)
extern OPAMPDriver OPAMPD2;
#endif

#if STM32_OPAMP_USE_OPAMP3 && !defined(__DOXYGEN__)
extern OPAMPDriver OPAMPD3;
#endif

#if STM32_OPAMP_USE_OPAMP4 && !defined(__DOXYGEN__)
extern OPAMPDriver OPAMPD4;
#endif


#ifdef __cplusplus
extern "C" {
#endif
  void opamp_lld_init(void);
  void opamp_lld_start(OPAMPDriver *compp);
  void opamp_lld_stop(OPAMPDriver *compp);
  void opamp_lld_enable(OPAMPDriver *compp);
  void opamp_lld_disable(OPAMPDriver *compp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_OPAMP */

#endif /* _opamp_lld_H_ */

/** @} */
