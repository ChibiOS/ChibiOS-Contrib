/*
    Copyright (C) 2014 Marco Veeneman

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
 * @file    Tiva/ext_lld.h
 * @brief   Tiva EXT subsystem low level driver header.
 *
 * @addtogroup EXT
 * @{
 */

#ifndef _EXT_LLD_H_
#define _EXT_LLD_H_

#if HAL_USE_EXT || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Number of EXT per port.
 */
#define EXT_MAX_CHANNELS    TIVA_GPIO_PINS

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   GPIOA interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOA_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOA_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIOB interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOB_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOB_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIOC interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOC_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOC_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIOD interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOD_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOD_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIOE interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOE_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOE_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIOF interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOF_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOF_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIOG interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOG_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOG_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIOH interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOH_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOH_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIOJ interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOJ_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOJ_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIOK interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOK_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOK_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIOL interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOL_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOL_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIOM interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOM_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOM_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPION interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPION_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPION_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIOP0 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOP0_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOP0_IRQ_PRIORITY        3
#endif

/**
 * @brief   GPIOP1 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOP1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOP1_IRQ_PRIORITY        3
#endif

/**
 * @brief   GPIOP2 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOP2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOP2_IRQ_PRIORITY        3
#endif

/**
 * @brief   GPIOP3 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOP3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOP3_IRQ_PRIORITY        3
#endif

/**
 * @brief   GPIOP4 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOP4_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOP4_IRQ_PRIORITY        3
#endif

/**
 * @brief   GPIOP5 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOP5_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOP5_IRQ_PRIORITY        3
#endif

/**
 * @brief   GPIOP6 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOP6_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOP6_IRQ_PRIORITY        3
#endif

/**
 * @brief   GPIOP7 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOP7_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOP7_IRQ_PRIORITY        3
#endif
/** @} */

/**
 * @brief   GPIOQ0 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOQ0_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOQ0_IRQ_PRIORITY        3
#endif

/**
 * @brief   GPIOQ1 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOQ1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOQ1_IRQ_PRIORITY        3
#endif

/**
 * @brief   GPIOQ2 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOQ2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOQ2_IRQ_PRIORITY        3
#endif

/**
 * @brief   GPIOQ3 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOQ3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOQ3_IRQ_PRIORITY        3
#endif

/**
 * @brief   GPIOQ4 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOQ4_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOQ4_IRQ_PRIORITY        3
#endif

/**
 * @brief   GPIOQ5 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOQ5_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOQ5_IRQ_PRIORITY        3
#endif

/**
 * @brief   GPIOQ6 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOQ6_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOQ6_IRQ_PRIORITY        3
#endif

/**
 * @brief   GPIOQ7 interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOQ7_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOQ7_IRQ_PRIORITY        3
#endif

/**
 * @brief   GPIOR interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOR_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOR_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIOS interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOS_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOS_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIOT interrupt priority level setting.
 */
#if !defined(TIVA_EXT_GPIOT_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_EXT_GPIOT_IRQ_PRIORITY         3
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   EXT channel identifier.
 */
typedef uint32_t expchannel_t;

/**
 * @brief   Type of an EXT generic notification callback.
 *
 * @param[in] extp      pointer to the @p EXPDriver object triggering the
 *                      callback
 */
typedef void (*extcallback_t)(EXTDriver *extp, expchannel_t channel);

/**
 * @brief   Channel configuration structure.
 */
typedef struct {
  /**
   * @brief Channel mode.
   */
  uint32_t              mode;
  /**
   * @brief Channel callback.
   */
  extcallback_t         cb;
} EXTChannelConfig;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /**
   * @brief Channel configurations.
   */
  EXTChannelConfig      channels[EXT_MAX_CHANNELS];
  /* End of the mandatory fields.*/
} EXTConfig;

/**
 * @brief   Structure representing an EXT driver.
 */
struct EXTDriver {
  /**
   * @brief Driver state.
   */
  extstate_t                state;
  /**
   * @brief Current configuration data.
   */
  const EXTConfig           *config;
  /* End of the mandatory fields.*/
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(__DOXYGEN__)
extern EXTDriver EXTD1;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void ext_lld_init(void);
  void ext_lld_start(EXTDriver *extp);
  void ext_lld_stop(EXTDriver *extp);
  void ext_lld_channel_enable(EXTDriver *extp, expchannel_t channel);
  void ext_lld_channel_disable(EXTDriver *extp, expchannel_t channel);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_EXT */

#endif /* _EXT_LLD_H_ */

/** @} */
