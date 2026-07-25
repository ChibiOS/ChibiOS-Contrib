/*
    Copyright (C) 2019 /u/KeepItUnder
    Modifications copyright (C) 2026 Belonit

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
 * @file    M251/m251_registry.h
 * @brief   M251/M252 capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef M251_REGISTRY_H
#define M251_REGISTRY_H

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    M251/M252 capabilities
 * @{
 */

#if defined(M252SD2AE) || defined(__DOXYGEN__)

#define M251_DEVICE_NAME                    "Nuvoton M252SD2AE"
#define M251_DEVICE_IS_M251                 FALSE
#define M251_DEVICE_IS_M252                 TRUE
#define M251_DEVICE_HAS_USBD                TRUE

#define M251_HAS_GPIOA                      TRUE
#define M251_HAS_GPIOB                      TRUE
#define M251_HAS_GPIOC                      TRUE
#define M251_HAS_GPIOD                      TRUE
#define M251_HAS_GPIOE                      TRUE
#define M251_HAS_GPIOF                      TRUE

#define M251_HAS_TIM0                       TRUE
#define M251_HAS_TIM1                       TRUE
#define M251_HAS_TIM2                       TRUE
#define M251_HAS_TIM3                       TRUE

#define M251_HAS_UART0                      TRUE
#define M251_HAS_UART1                      TRUE
#define M251_HAS_UART2                      TRUE
#define M251_HAS_UART3                      FALSE

#define M251_HAS_I2C0                       TRUE
#define M251_HAS_I2C1                       TRUE

#define M251_HAS_SPI0                       TRUE
#define M251_HAS_SPI1                       TRUE

#define M251_HAS_WDT                        TRUE

#define M251_HAS_USBD                       M251_DEVICE_HAS_USBD
#define M251_USBD_ENDPOINTS                 12U

#define M251_HAS_PWM0                       TRUE
#define M251_HAS_PWM1                       TRUE
#define M251_HAS_BPWM0                      TRUE
#define M251_HAS_BPWM1                      TRUE

#define M251_FLASH_SIZE                     0x10000UL
#define M251_SRAM_SIZE                      0x3000UL
#define M251_LDROM_SIZE                     0x1000UL

#if M251_DEVICE_IS_M251 && M251_DEVICE_IS_M252
#error "Invalid M251 registry: device cannot be both M251 and M252"
#endif

#if !M251_DEVICE_IS_M251 && !M251_DEVICE_IS_M252
#error "Invalid M251 registry: device family not classified"
#endif

#if M251_DEVICE_IS_M251 && M251_DEVICE_HAS_USBD
#error "Invalid M251 registry: plain M251 parts have no USBD"
#endif

#if M251_DEVICE_HAS_USBD && !M251_DEVICE_IS_M252
#error "Invalid M251 registry: USBD is supported only for M252 parts"
#endif

#else
#error "Unsupported M251/M252 device"
#endif
/** @} */

#endif /* M251_REGISTRY_H */

/** @} */
