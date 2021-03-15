/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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
 * @file    sn32_registry.h
 * @brief   SN32F24xx capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef SN32_REGISTRY_H
#define SN32_REGISTRY_H

#if !defined(SN32F24xx) || defined(__DOXYGEN__)
#define SN32F24xx
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    SN32F24xx capabilities
 * @{
 */

/*
 * ST unit
 */
#define SN32_ST_HANDLER           Vector3C
#define SN32_ST_NUMBER            SysTick_IRQn

/*
 * NDT unit.
 */
#define SN32_NDT_HANDLER          Vector40
#define SN32_NDT_NUMBER           NDT_IRQn

/*
 * USB unit.
 */
#define SN32_USB_HANDLER          Vector44
#define SN32_USB_NUMBER           USB_IRQn

#define USBD_INTSTS_EPEVT_Pos        USBD_INTSTS_EPEVT0_Pos
#define USBD_INTSTS_EPEVT_Msk        (0xFFul << USBD_INTSTS_EPEVT_Pos)

/*
 * SPI unit.
 */
#define SN32_SPI0_HANDLER          Vector58
#define SN32_SPI0_NUMBER           SPI0_IRQn

/*
 * I2C unit.
 */
#define SN32_I2C0_GLOBAL_HANDLER   Vector68
#define SN32_I2C0_GLOBAL_NUMBER    I2C0_IRQn

/*
 * USART units.
 */
#define SN32_USART0_HANDLER        Vector70
#define SN32_USART1_HANDLER        Vector74
#define SN32_USART2_HANDLER        Vector78

#define SN32_USART0_NUMBER         UART0_IRQn
#define SN32_USART1_NUMBER         UART1_IRQn
#define SN32_USART2_NUMBER         UART2_IRQn

/*
 * CT16 units.
 */
#define SN32_CT16B0_HANDLER       Vector7C
#define SN32_CT16B1_HANDLER       Vector80
#define SN32_CT16B2_HANDLER		  Vector84

#define SN32_CT16B0_NUMBER        CT16B0_IRQn
#define SN32_CT16B1_NUMBER        CT16B1_IRQn
#define SN32_CT16B2_NUMBER        CT16B2_IRQn

/*
 * CT32 units.
 */
#define SN32_CT32B0_HANDLER		  Vector8C
#define SN32_CT32B1_HANDLER 	  Vector90
#define SN32_CT32B2_HANDLER 	  Vector94

#define SN32_CT32B0_NUMBER        CT32B0_IRQn
#define SN32_CT32B1_NUMBER        CT32B1_IRQn
#define SN32_CT32B2_NUMBER        CT32B2_IRQn

/*
 * ADC unit.
 */
#define SN32_ADC_HANDLER          VectorA0
#define SN32_ADC_NUMBER           ADC_IRQn

/*
 * WDT unit.
 */
#define SN32_WDT_HANDLER          VectorA4
#define SN32_WDT_NUMBER           WDT_IRQn

/*
 * LVD unit.
 */
#define SN32_LVD_HANDLER          VectorA8
#define SN32_LVD_NUMBER           LVD_IRQn

/*
 * GPIO units.
 */
#define SN32_GPIOD_HANDLER        VectorB0
#define SN32_GPIOC_HANDLER        VectorB4
#define SN32_GPIOB_HANDLER        VectorB8
#define SN32_GPIOA_HANDLER        VectorBC

#define SN32_GPIOD_NUMBER         P3_IRQn
#define SN32_GPIOC_NUMBER         P2_IRQn
#define SN32_GPIOB_NUMBER         P1_IRQn
#define SN32_GPIOA_NUMBER         P0_IRQn
/*===========================================================================*/
/* Common.                                                                   */
/*===========================================================================*/



/** @} */

#endif /* SN32_REGISTRY_H */

/** @} */
