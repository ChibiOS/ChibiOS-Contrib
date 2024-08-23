/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2024 Maxjta

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
 * @file    GPIOv2/at32_gpio.h
 * @brief   AT32 GPIO units common header.
 * @note    This file requires definitions from the AT32 header file.
 *
 * @addtogroup AT32_GPIOv2
 * @{
 */

#ifndef AT32_GPIO_H
#define AT32_GPIO_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/* Discarded definitions from the AT headers, the PAL driver uses its own
   definitions in order to have an unified handling for all devices.
   Unfortunately the AT headers have no uniform definitions for the same
   objects across the various sub-families.*/
#undef GPIOA
#undef GPIOB
#undef GPIOC
#undef GPIOD
#undef GPIOE
#undef GPIOF
#undef GPIOG
#undef GPIOH
#undef GPIOI
#undef GPIOJ
#undef GPIOK

/**
 * @name    GPIO ports definitions
 * @{
 */
#define GPIOA                           ((at32_gpio_t *)GPIOA_BASE)
#define GPIOB                           ((at32_gpio_t *)GPIOB_BASE)
#define GPIOC                           ((at32_gpio_t *)GPIOC_BASE)
#define GPIOD                           ((at32_gpio_t *)GPIOD_BASE)
#define GPIOE                           ((at32_gpio_t *)GPIOE_BASE)
#define GPIOF                           ((at32_gpio_t *)GPIOF_BASE)
#if AT32_HAS_GPIOG
#define GPIOG                           ((at32_gpio_t *)GPIOG_BASE)
#endif
#if AT32_HAS_GPIOH
#define GPIOH                           ((at32_gpio_t *)GPIOH_BASE)
#endif
#if AT32_HAS_GPIOI
#define GPIOI                           ((at32_gpio_t *)GPIOI_BASE)
#endif
#if AT32_HAS_GPIOJ
#define GPIOJ                           ((at32_gpio_t *)GPIOJ_BASE)
#endif
#if AT32_HAS_GPIOK
#define GPIOK                           ((at32_gpio_t *)GPIOK_BASE)
#endif
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   AT32 GPIO registers block.
 */
typedef struct {

  volatile uint32_t CFGR;
  volatile uint32_t OMODE;
  volatile uint32_t ODRVR;
  volatile uint32_t PULL;
  volatile uint32_t IDT;
  volatile uint32_t ODT;
  volatile union {
    uint32_t        W;
    struct {
      uint16_t      set;
      uint16_t      clear;
    } H;
  } SCR;
  volatile uint32_t WPR;
  volatile uint32_t MUXL;
  volatile uint32_t MUXH;
  volatile uint32_t CLR;
  volatile uint32_t TOGR;
  volatile uint32_t resvd30[3];
  volatile uint32_t HDRV;
} at32_gpio_t;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#endif /* AT32_GPIO_H */

/** @} */
