/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio
              Copyright (C) 2020 Yaotian Feng

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
 * @file    ES32_registry.h
 * @brief   capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef ES32_REGISTRY_H
#define ES32_REGISTRY_H

/**
 * @brief   Sub-family identifier.
 */

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @brief   Maximum system and core clock (f_SYS) frequency.
 */
#define ES32_SYSCLK_MAX         72000000L

/**
 * @brief   Maximum bus clock (f_BUS) frequency.
 */
#define ES32_BUSCLK_MAX         72000000L

/**
 * @brief   Maximum flash clock (f_FLASH) frequency.
 */
#define ES32_FLASHCLK_MAX       72000000L

/**
 * @name    attributes
 * @{
 */

/* GPIO attributes.*/
#define ES32_NUM_GPIO             5

#define ES32_GPIO_INDEX_BITS        13
#define ES32_CCR_PAEN               CKCU_AHBCCR_PAEN

/* EXTI attributes */
#define ES32_HAS_EXTI               TRUE
#define ES32_NUM_EXTI               16
#define ES32_EVWUP_IRQ_VECTOR       Vector58
#define ES32_EXTI0_IRQ_VECTOR       Vector60
#define ES32_EXTI1_IRQ_VECTOR       Vector64
#define ES32_EXTI2_IRQ_VECTOR       Vector68
#define ES32_EXTI3_IRQ_VECTOR       Vector6C
#define ES32_EXTI4_IRQ_VECTOR       Vector70
#define ES32_EXTI5_IRQ_VECTOR       Vector74
#define ES32_EXTI6_IRQ_VECTOR       Vector78
#define ES32_EXTI7_IRQ_VECTOR       Vector7C
#define ES32_EXTI8_IRQ_VECTOR       Vector80
#define ES32_EXTI9_IRQ_VECTOR       Vector84
#define ES32_EXTI10_IRQ_VECTOR      Vector88
#define ES32_EXTI11_IRQ_VECTOR      Vector8C
#define ES32_EXTI12_IRQ_VECTOR      Vector90
#define ES32_EXTI13_IRQ_VECTOR      Vector94
#define ES32_EXTI14_IRQ_VECTOR      Vector98
#define ES32_EXTI15_IRQ_VECTOR      Vector9C

/* I2C attributes.*/
#define ES32_HAS_I2C0               TRUE
#define ES32_I2C0_IRQ_VECTOR        VectorEC
#define ES32_HAS_I2C1               TRUE
#define ES32_I2C1_IRQ_VECTOR        VectorF0

/* SPI attributes.*/
#define ES32_HAS_SPI0               TRUE
#define ES32_SPI0_IRQ_VECTOR        VectorF4
#define ES32_HAS_SPI1               TRUE
#define ES32_SPI1_IRQ_VECTOR        VectorF8

/* UART attributes.*/
#define ES32_HAS_USART0             TRUE
#define ES32_USART0_IRQ_VECTOR      VectorFC
#define ES32_HAS_USART1             TRUE
#define ES32_USART1_IRQ_VECTOR      Vector100
#define ES32_HAS_UART0              TRUE
#define ES32_UART0_IRQ_VECTOR       Vector104
#define ES32_HAS_UART1              TRUE
#define ES32_UART1_IRQ_VECTOR       Vector108

/* USB attributes.*/
#define ES32_HAS_USB                TRUE
#define ES32_USB_IRQ_VECTOR         Vector114
#define ES32_USB0_IS_USBOTG         FALSE
#define ES32_HAS_USB_CLOCK_RECOVERY FALSE

/* BFTM attributes. */
#define ES32_BFTM0_IRQ_VECTOR       VectorE4
#define ES32_BFTM1_IRQ_VECTOR       VectorE8

/** @} */

#endif /* ES32_REGISTRY_H */

/** @} */
