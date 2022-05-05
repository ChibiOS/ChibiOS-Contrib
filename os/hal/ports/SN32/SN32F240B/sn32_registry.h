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
 * @file    SN32F240B/sn32_registry.h
 * @brief   SN32F24xB capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef SN32_REGISTRY_H
#define SN32_REGISTRY_H

/* Common identifier of all SN32F2xx devices.*/
#if !defined(SN32F2xx) || defined(__DOXYGEN__)
#define SN32F2xx
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    SN32F24xB capabilities
 * @{
 */

/* Common identifier of all SN32F24xB devices.*/
#if !defined(SN32F240B) || defined(__DOXYGEN__)
#define SN32F240B
#endif

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
 * UART units.
 */
#define SN32_UART0_HANDLER        Vector70
#define SN32_UART1_HANDLER        Vector74
#define SN32_UART2_HANDLER        Vector78

#define SN32_UART0_NUMBER         UART0_IRQn
#define SN32_UART1_NUMBER         UART1_IRQn
#define SN32_UART2_NUMBER         UART2_IRQn

/*
 * CT16 units.
 */
#define SN32_CT16B0_HANDLER       Vector7C
#define SN32_CT16B1_HANDLER       Vector80

#define SN32_CT16B0_NUMBER        CT16B0_IRQn
#define SN32_CT16B1_NUMBER        CT16B1_IRQn

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
