/*
    Copyright (C) 2024 Dimitris Mantzouranis

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
 * @file    SN32F290/sn32_registry.h
 * @brief   SN32F29x capabilities registry.
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
 * @name    SN32F29x capabilities
 * @{
 */

/* Common identifier of all SN32F24xB devices.*/
#if !defined(SN32F290) || defined(__DOXYGEN__)
#define SN32F290
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
#define SN32_HAS_USB              TRUE

#define USBD_INTSTS_EPEVT_Pos        USBD_INTSTS_EPEVT0_Pos
#define USBD_INTSTS_EPEVT_Msk        (0xFFul << USBD_INTSTS_EPEVT_Pos)

/*
 * LCD unit.
 */
#define SN32_LCD_HANDLER          Vector48
#define SN32_LCD_NUMBER           LCD_IRQn

/*
 * I2S units.
 */
#define SN32_I2S0_HANDLER          Vector4C
#define SN32_I2S1_HANDLER          Vector50

#define SN32_I2S0_NUMBER           I2S0_IRQn
#define SN32_I2S1_NUMBER           I2S1_IRQn

/*
 * CMP units.
 */
#define SN32_CMP0_HANDLER          VectorAC
#define SN32_CMP1_HANDLER          Vector88
#define SN32_CMP2_HANDLER          Vector70
#define SN32_CMP3_HANDLER          Vector54

#define SN32_CMP0_NUMBER           CMP0_IRQn
#define SN32_CMP1_NUMBER           CMP1_IRQn
#define SN32_CMP2_NUMBER           CMP2_IRQn
#define SN32_CMP3_NUMBER           CMP3_IRQn

/*
 * SPI units.
 */
#define SN32_SPI0_HANDLER          Vector58
#define SN32_SPI1_HANDLER          Vector5C

#define SN32_SPI0_NUMBER           SPI0_IRQn
#define SN32_SPI1_NUMBER           SPI1_IRQn

#define SN32_HAS_SPI0              TRUE
#define SN32_HAS_SPI1              TRUE

/*
 * UART units.
 */
#define SN32_UART0_HANDLER        Vector74
#define SN32_UART1_HANDLER        Vector78
#define SN32_UART2_HANDLER        Vector60
#define SN32_UART3_HANDLER        Vector64

#define SN32_UART0_NUMBER         UART0_IRQn
#define SN32_UART1_NUMBER         UART1_IRQn
#define SN32_UART2_NUMBER         UART2_IRQn
#define SN32_UART3_NUMBER         UART3_IRQn

#define SN32_HAS_UART0            TRUE
#define SN32_HAS_UART1            TRUE
#define SN32_HAS_UART2            TRUE
#define SN32_HAS_UART3            TRUE


/*
 * I2C units.
 */
#define SN32_I2C0_GLOBAL_HANDLER   Vector68
#define SN32_I2C1_GLOBAL_HANDLER   Vector6C

#define SN32_I2C0_GLOBAL_NUMBER    I2C0_IRQn
#define SN32_I2C1_GLOBAL_NUMBER    I2C0_IRQn

#define SN32_HAS_I2C0              TRUE
#define SN32_HAS_I2C1              TRUE

/*
 * CT16 units.
 */
#define SN32_CT16B0_HANDLER       Vector7C
#define SN32_CT16B1_HANDLER       Vector80
#define SN32_CT16B2_HANDLER       Vector84
#define SN32_CT16B3_HANDLER       Vector8C
#define SN32_CT16B4_HANDLER       Vector90
#define SN32_CT16B5_HANDLER       Vector94

#define SN32_CT16B0_NUMBER        CT16B0_IRQn
#define SN32_CT16B1_NUMBER        CT16B1_IRQn
#define SN32_CT16B2_NUMBER        CT16B2_IRQn
#define SN32_CT16B3_NUMBER        CT16B3_IRQn
#define SN32_CT16B4_NUMBER        CT16B4_IRQn
#define SN32_CT16B5_NUMBER        CT16B5_IRQn

#define SN32_HAS_CT16B0           TRUE
#define SN32_HAS_CT16B1           TRUE
#define SN32_HAS_CT16B2           TRUE
#define SN32_HAS_CT16B3           TRUE
#define SN32_HAS_CT16B4           TRUE
#define SN32_HAS_CT16B5           TRUE

/*
 * EBI unit.
 */
#define SN32_EBI_HANDLER          Vector98
#define SN32_EBI_NUMBER           EBI_IRQn

/*
 * RTC unit.
 */
#define SN32_RTC_HANDLER          Vector9C
#define SN32_RTC_NUMBER           RTC_IRQn
#define SN32_HAS_RTC              TRUE
/*
 * ADC unit.
 */
#define SN32_ADC_HANDLER          VectorA0
#define SN32_ADC_NUMBER           ADC_IRQn
#define SN32_HAS_ADC              TRUE

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

#define SN32_HAS_GPIOD            TRUE
#define SN32_HAS_GPIOC            TRUE
#define SN32_HAS_GPIOB            TRUE
#define SN32_HAS_GPIOA            TRUE

/*
 * FLASH units.
 */
#define SN32_JUMPLOADER_SIZE 0x200
#define SN32_FLASH_LINE_SIZE 8U
#define SN32_FLASH_NUMBER_OF_BANKS 1
#define SN32_FLASH_SECTORS_PER_BANK 256U
#define SN32_FLASH_SECTOR_SIZE 1024U
#define SN32_FLASH_BASE 0x00000000UL
#define FLASH_SIZE (SN32_FLASH_NUMBER_OF_BANKS * SN32_FLASH_SECTORS_PER_BANK * SN32_FLASH_SECTOR_SIZE)
/*===========================================================================*/
/* Common.                                                                   */
/*===========================================================================*/



/** @} */

#endif /* SN32_REGISTRY_H */

/** @} */
