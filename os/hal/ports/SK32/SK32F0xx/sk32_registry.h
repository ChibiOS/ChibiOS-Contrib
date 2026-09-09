/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    Copyright (C) 2026 QMK

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
 * @file    sk32_registry.h
 * @brief   SK32F0xx capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef SK32_REGISTRY_H
#define SK32_REGISTRY_H

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @brief   Maximum system and core clock (SYSCLK) frequency.
 */
#define SK32_SYSCLK_MAX         72000000UL

/**
 * @brief   HSI (internal high speed oscillator) frequency.
 */
#define SK32_HSICLK             8000000UL

/**
 * @brief   PLL48 (internal oscillator used for the USB) frequency.
 * @note    Enabled through the RCC->CR2.PLL48ON bit, it is independent from
 *          the main PLL used for the system clock.
 */
#define SK32_PLL48CLK           48000000UL

/**
 * @name    GPIO attributes
 * @{
 */
/* The AHB clock/reset registers expose enable bits for ports A..F on the
   whole SK32F0xx family. The GPIOF port is present on the SK32F077 while the
   GPIOE port is present on the SK32F072.*/
#define SK32_NUM_GPIO           6
#define SK32_HAS_GPIOA          TRUE
#define SK32_HAS_GPIOB          TRUE
#define SK32_HAS_GPIOC          TRUE
#define SK32_HAS_GPIOD          TRUE
#if defined(SK32F077xB)
#define SK32_HAS_GPIOE          FALSE
#define SK32_HAS_GPIOF          TRUE
#else
#define SK32_HAS_GPIOE          TRUE
#define SK32_HAS_GPIOF          FALSE
#endif
/** @} */

/**
 * @name    Peripheral presence
 * @note    Whole-family peripherals (declared regardless of the variant):
 *          GPIO, USART1/2, SPI1, I2C1, ADC1, DMA1, USB (musbfsfc).
 * @note    On the SK32F077 variant the I2C2 and SPI2 units and the TIM1,
 *          TIM2 timers are not present (their interrupt slots are reserved
 *          in the vector table).
 * @{
 */
#define SK32_HAS_USART1         TRUE
#define SK32_HAS_USART2         TRUE
#define SK32_HAS_SPI1           TRUE
#define SK32_HAS_I2C1           TRUE
#define SK32_HAS_ADC1           TRUE
#define SK32_HAS_DMA1           TRUE
#define SK32_HAS_USB            TRUE
#define SK32_HAS_TIM16          TRUE
#define SK32_HAS_TIM17          TRUE

#if defined(SK32F077xB)
#define SK32_HAS_SPI2           FALSE
#define SK32_HAS_I2C2           FALSE
#define SK32_HAS_TIM1           FALSE
#define SK32_HAS_TIM2           FALSE
#define SK32_HAS_TIM3           TRUE
#else
#define SK32_HAS_SPI2           TRUE
#define SK32_HAS_I2C2           TRUE
#define SK32_HAS_TIM1           TRUE
#define SK32_HAS_TIM2           TRUE
#define SK32_HAS_TIM3           TRUE
#endif
/** @} */

/**
 * @name    Interrupt vectors.
 * @details A Cortex-M0 vector slot is identified by the byte offset (in hex)
 *          of its entry inside the vector table, IRQn maps to
 *          Vector(0x40 + 4 * IRQn).
 * @note    The IRQn values are the ones declared in the device CMSIS header
 *          (sk32f0xx.h, IRQn_Type).
 * @note    On the SK32F077 variant the slots 8 (TSC), 13-15 (TIM1, TIM2),
 *          24 (I2C2) and 26 (SPI2) are Reserved; they are still declared in
 *          the family-wide device header.
 * @{
 */
#define SK32_WWDG_NUMBER                0
#define SK32_PVD_VDDIO2_NUMBER          1
#define SK32_RTC_NUMBER                 2
#define SK32_FLASH_NUMBER               3
#define SK32_RCC_CRS_NUMBER             4
#define SK32_EXTI0_1_NUMBER             5
#define SK32_EXTI2_3_NUMBER             6
#define SK32_EXTI4_15_NUMBER            7
#define SK32_TSC_NUMBER                 8
#define SK32_DMA1_CH1_NUMBER            9
#define SK32_DMA1_CH23_NUMBER           10
#define SK32_DMA1_CH456_NUMBER          11
#define SK32_ADC_COMP_NUMBER            12
#define SK32_TIM1_BRK_UP_TRG_COM_NUMBER 13
#define SK32_TIM1_CC_NUMBER             14
#define SK32_TIM2_NUMBER                15
#define SK32_TIM3_NUMBER                16
#define SK32_TIM6_DAC_NUMBER            17
#define SK32_TIM16_NUMBER               21
#define SK32_TIM17_NUMBER               22
#define SK32_I2C1_NUMBER                23
#define SK32_I2C2_NUMBER                24
#define SK32_SPI1_NUMBER                25
#define SK32_SPI2_NUMBER                26
#define SK32_USART1_NUMBER              27
#define SK32_USART2_NUMBER              28
#define SK32_USB_NUMBER                 31

#if defined(SK32F077xB) || defined(__DOXYGEN__)
#define SK32_SLED_NUMBER                29
#define SK32_KBCU_NUMBER                30
#endif

#define SK32_WWDG_HANDLER               Vector40
#define SK32_PVD_VDDIO2_HANDLER         Vector44
#define SK32_RTC_HANDLER                Vector48
#define SK32_FLASH_HANDLER              Vector4C
#define SK32_RCC_CRS_HANDLER            Vector50
#define SK32_EXTI0_1_HANDLER            Vector54
#define SK32_EXTI2_3_HANDLER            Vector58
#define SK32_EXTI4_15_HANDLER           Vector5C
#define SK32_TSC_HANDLER                Vector60
#define SK32_DMA1_CH1_HANDLER           Vector64
#define SK32_DMA1_CH23_HANDLER          Vector68
#define SK32_DMA1_CH456_HANDLER         Vector6C
#define SK32_ADC_COMP_HANDLER           Vector70
#define SK32_TIM1_BRK_UP_TRG_COM_HANDLER Vector74
#define SK32_TIM1_CC_HANDLER            Vector78
#define SK32_TIM2_HANDLER               Vector7C
#define SK32_TIM3_HANDLER               Vector80
#define SK32_TIM6_DAC_HANDLER           Vector84
#define SK32_TIM16_HANDLER              Vector94
#define SK32_TIM17_HANDLER              Vector98
#define SK32_I2C1_HANDLER               Vector9C
#define SK32_I2C2_HANDLER               VectorA0
#define SK32_SPI1_HANDLER               VectorA4
#define SK32_SPI2_HANDLER               VectorA8
#define SK32_USART1_HANDLER             VectorAC
#define SK32_USART2_HANDLER             VectorB0
#define SK32_USB_HANDLER                VectorBC

#if defined(SK32F077xB) || defined(__DOXYGEN__)
#define SK32_SLED_HANDLER               VectorB4
#define SK32_KBCU_HANDLER               VectorB8
#endif
/** @} */

/*===========================================================================*/
/* DMA attributes.                                                            */
/*===========================================================================*/

/**
 * @name    DMA1 channels mapping
 * @details The DMA1 channels are aggregated on three NVIC vectors: channel 1
 *          owns a dedicated vector while channels 2-3 and channels 4-6 share
 *          one vector each.  Every channel is mapped on the vector of its
 *          group and a collision mask (CMASK) groups the channels that are
 *          served by the same ISR entry; the collision masks are used by the
 *          DMA driver to enable/disable a shared vector only on the first
 *          allocation and on the last release inside the group.
 * @{
 */
#define SK32_DMA1_NUM_CHANNELS          6
#define SK32_DMA2_NUM_CHANNELS          0

#define SK32_DMA1_CH2_NUMBER            SK32_DMA1_CH23_NUMBER
#define SK32_DMA1_CH3_NUMBER            SK32_DMA1_CH23_NUMBER
#define SK32_DMA1_CH4_NUMBER            SK32_DMA1_CH456_NUMBER
#define SK32_DMA1_CH5_NUMBER            SK32_DMA1_CH456_NUMBER
#define SK32_DMA1_CH6_NUMBER            SK32_DMA1_CH456_NUMBER

#define SK32_DMA1_CH1_CMASK             0x00000001U
#define SK32_DMA1_CH2_CMASK             0x00000006U
#define SK32_DMA1_CH3_CMASK             0x00000006U
#define SK32_DMA1_CH4_CMASK             0x00000078U
#define SK32_DMA1_CH5_CMASK             0x00000078U
#define SK32_DMA1_CH6_CMASK             0x00000078U
/** @} */

/*===========================================================================*/
/* Flash attributes.                                                         */
/*===========================================================================*/

/**
 * @brief   Flash wait states required above the HSI frequency.
 * @note    The vendor clock configuration applies 2 wait states at 72MHz
 *          (and keeps them at 48MHz as well).
 */
#define SK32_FLASH_WAIT_STATES          2

/**
 * @name    Embedded Flash geometry.
 * @details The SK32F077 internal flash is single-bank, 128 KByte, organised in
 *          2 KByte pages (unlike the STM32F072 1 KByte pages).  The write line
 *          is a half-word (2 bytes) exactly like the STM32F0 family.  These
 *          macros are consumed by the EFL low level driver (hal_efl_lld.c)
 *          which derives its sector/count/size and the programming alignment
 *          from them; they must not be redefined elsewhere.
 * @{
 */
#if !defined(STM32_FLASH_LINE_SIZE)
#define STM32_FLASH_LINE_SIZE           2
#endif
#if !defined(STM32_FLASH_SECTOR_SIZE)
#define STM32_FLASH_SECTOR_SIZE         2048U
#endif
#if !defined(STM32_FLASH_NUMBER_OF_BANKS)
#define STM32_FLASH_NUMBER_OF_BANKS     1
#endif
#if !defined(STM32_FLASH_SECTORS_PER_BANK)
#define STM32_FLASH_SECTORS_PER_BANK    64U
#endif
/** @} */

#endif /* SK32_REGISTRY_H */
