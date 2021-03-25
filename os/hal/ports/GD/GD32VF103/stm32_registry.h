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
 * @file    STM32F1xx/gd32_registry.h
 * @brief   STM32F1xx capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef GD32_REGISTRY_H
#define GD32_REGISTRY_H

#if defined(STM32F100xB)
#define STM32F10X_MD_VL

#elif defined(STM32F100xE)
#define STM32F10X_HD_VL

#elif defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6)
#define STM32F10X_LD

#elif defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB)
#define STM32F10X_MD

#elif defined(STM32F101xE) || defined(STM32F103xE)
#define STM32F10X_HD

#elif defined(STM32F101xG) || defined(STM32F103xG)
#define STM32F10X_XL

#elif defined(STM32F105xC) || defined(STM32F107xC)
#define STM32F10X_CL

#else
#error "unsupported or unrecognized STM32F1xx member"
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

#if defined(STM32F10X_MD_VL) || defined(__DOXYGEN__)
/**
 * @name    STM32F100 MD capabilities
 * @{
 */
/* ADC attributes.*/
#define GD32_HAS_ADC1                      TRUE
#define GD32_HAS_ADC2                      FALSE
#define GD32_HAS_ADC3                      FALSE
#define GD32_HAS_ADC4                      FALSE

#define GD32_HAS_SDADC1                    FALSE
#define GD32_HAS_SDADC2                    FALSE
#define GD32_HAS_SDADC3                    FALSE

/* CAN attributes.*/
#define GD32_HAS_CAN1                      FALSE
#define GD32_HAS_CAN2                      FALSE
#define GD32_HAS_CAN3                      FALSE
#define GD32_CAN_MAX_FILTERS               0

/* DAC attributes.*/
#define GD32_HAS_DAC1_CH1                  TRUE
#define GD32_DAC_DAC1_CH1_DMA_STREAM       GD32_DMA_STREAM_ID(1, 3)

#define GD32_HAS_DAC1_CH2                  TRUE
#define GD32_DAC_DAC1_CH2_DMA_STREAM       GD32_DMA_STREAM_ID(1, 4)

#define GD32_HAS_DAC2_CH1                  FALSE
#define GD32_HAS_DAC2_CH2                  FALSE

/* DMA attributes.*/
#define GD32_ADVANCED_DMA                  FALSE
#define GD32_DMA_SUPPORTS_DMAMUX           FALSE
#define GD32_DMA_SUPPORTS_CSELR            FALSE

#define GD32_DMA0_NUM_CHANNELS             7
#define GD32_DMA0_CH0_HANDLER              Vector6C
#define GD32_DMA0_CH1_HANDLER              Vector70
#define GD32_DMA0_CH2_HANDLER              Vector74
#define GD32_DMA0_CH3_HANDLER              Vector78
#define GD32_DMA0_CH4_HANDLER              Vector7C
#define GD32_DMA0_CH5_HANDLER              Vector80
#define GD32_DMA0_CH6_HANDLER              Vector84
#define GD32_DMA0_CH0_NUMBER               11
#define GD32_DMA0_CH1_NUMBER               12
#define GD32_DMA0_CH2_NUMBER               13
#define GD32_DMA0_CH3_NUMBER               14
#define GD32_DMA0_CH4_NUMBER               15
#define GD32_DMA0_CH5_NUMBER               16
#define GD32_DMA0_CH6_NUMBER               17

#define GD32_DMA1_NUM_CHANNELS             0

/* ETH attributes.*/
#define GD32_HAS_ETH                       FALSE

/* EXTI attributes.*/
#define GD32_EXTI_NUM_LINES                19
#define GD32_EXTI_IMR_MASK                 0x00000000U

/* Flash attributes.*/
#define GD32_FLASH_NUMBER_OF_BANKS         1
#define GD32_FLASH_SECTOR_SIZE             1024U
#if !defined(GD32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define GD32_FLASH_SECTORS_PER_BANK        32 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define GD32_HAS_GPIOA                     TRUE
#define GD32_HAS_GPIOB                     TRUE
#define GD32_HAS_GPIOC                     TRUE
#define GD32_HAS_GPIOD                     TRUE
#define GD32_HAS_GPIOE                     TRUE
#define GD32_HAS_GPIOF                     FALSE
#define GD32_HAS_GPIOG                     FALSE
#define GD32_HAS_GPIOH                     FALSE
#define GD32_HAS_GPIOI                     FALSE
#define GD32_HAS_GPIOJ                     FALSE
#define GD32_HAS_GPIOK                     FALSE

/* I2C attributes.*/
#define GD32_HAS_I2C0                      TRUE
#define GD32_I2C_I2C0_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 7)
#define GD32_I2C_I2C0_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 6)

#define GD32_HAS_I2C1                      TRUE
#define GD32_I2C_I2C1_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 5)
#define GD32_I2C_I2C1_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 4)

#define GD32_HAS_I2C3                      FALSE
#define GD32_HAS_I2C4                      FALSE

/* QUADSPI attributes.*/
#define GD32_HAS_QUADSPI1                  FALSE

/* RTC attributes.*/
#define GD32_HAS_RTC                       TRUE
#define GD32_RTC_HAS_SUBSECONDS            TRUE
#define GD32_RTC_IS_CALENDAR               FALSE

/* SDIO attributes.*/
#define GD32_HAS_SDIO                      FALSE

/* SPI attributes.*/
#define GD32_HAS_SPI1                      TRUE
#define GD32_SPI1_SUPPORTS_I2S             FALSE
#define GD32_SPI_SPI1_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 2)
#define GD32_SPI_SPI1_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 3)

#define GD32_HAS_SPI2                      TRUE
#define GD32_SPI2_SUPPORTS_I2S             FALSE
#define GD32_SPI_SPI2_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 4)
#define GD32_SPI_SPI2_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 5)

#define GD32_HAS_SPI3                      FALSE
#define GD32_HAS_SPI4                      FALSE
#define GD32_HAS_SPI5                      FALSE
#define GD32_HAS_SPI6                      FALSE

/* TIM attributes.*/
#define GD32_TIM_MAX_CHANNELS              4

#define GD32_HAS_TIM1                      TRUE
#define GD32_TIM1_IS_32BITS                FALSE
#define GD32_TIM1_CHANNELS                 4

#define GD32_HAS_TIM2                      TRUE
#define GD32_TIM2_IS_32BITS                FALSE
#define GD32_TIM2_CHANNELS                 4

#define GD32_HAS_TIM3                      TRUE
#define GD32_TIM3_IS_32BITS                FALSE
#define GD32_TIM3_CHANNELS                 4

#define GD32_HAS_TIM4                      TRUE
#define GD32_TIM4_IS_32BITS                FALSE
#define GD32_TIM4_CHANNELS                 4

#define GD32_HAS_TIM6                      TRUE
#define GD32_TIM6_IS_32BITS                FALSE
#define GD32_TIM6_CHANNELS                 0

#define GD32_HAS_TIM7                      TRUE
#define GD32_TIM7_IS_32BITS                FALSE
#define GD32_TIM7_CHANNELS                 0

#define GD32_HAS_TIM15                     TRUE
#define GD32_TIM15_IS_32BITS               FALSE
#define GD32_TIM15_CHANNELS                2

#define GD32_HAS_TIM16                     TRUE
#define GD32_TIM16_IS_32BITS               FALSE
#define GD32_TIM16_CHANNELS                1

#define GD32_HAS_TIM17                     TRUE
#define GD32_TIM17_IS_32BITS               FALSE
#define GD32_TIM17_CHANNELS                1

#define GD32_HAS_TIM5                      FALSE
#define GD32_HAS_TIM8                      FALSE
#define GD32_HAS_TIM9                      FALSE
#define GD32_HAS_TIM10                     FALSE
#define GD32_HAS_TIM11                     FALSE
#define GD32_HAS_TIM12                     FALSE
#define GD32_HAS_TIM13                     FALSE
#define GD32_HAS_TIM14                     FALSE
#define GD32_HAS_TIM18                     FALSE
#define GD32_HAS_TIM19                     FALSE
#define GD32_HAS_TIM20                     FALSE
#define GD32_HAS_TIM21                     FALSE
#define GD32_HAS_TIM22                     FALSE

/* USART attributes.*/
#define GD32_HAS_USART0                    TRUE
#define GD32_UART_USART0_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 5)
#define GD32_UART_USART0_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 4)

#define GD32_HAS_USART1                    TRUE
#define GD32_UART_USART1_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 6)
#define GD32_UART_USART1_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 7)

#define GD32_HAS_USART2                    TRUE
#define GD32_UART_USART2_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 3)
#define GD32_UART_USART2_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 2)

#define GD32_HAS_UART4                     FALSE
#define GD32_HAS_UART5                     FALSE
#define GD32_HAS_USART6                    FALSE
#define GD32_HAS_UART7                     FALSE
#define GD32_HAS_UART8                     FALSE
#define GD32_HAS_LPUART1                   FALSE

/* USB attributes.*/
#define GD32_HAS_USB                       FALSE
#define GD32_HAS_USBFS                      FALSE
#define GD32_HAS_OTG2                      FALSE

/* IWDG attributes.*/
#define GD32_HAS_IWDG                      TRUE
#define GD32_IWDG_IS_WINDOWED              FALSE

/* LTDC attributes.*/
#define GD32_HAS_LTDC                      FALSE

/* DMA1D attributes.*/
#define GD32_HAS_DMA1D                     FALSE

/* FSMC attributes.*/
#define GD32_HAS_FSMC                      FALSE

/* CRC attributes.*/
#define GD32_HAS_CRC                       TRUE
#define GD32_CRC_PROGRAMMABLE              FALSE
/** @} */
#endif /* defined(STM32F10X_MD_VL) */

#if defined(STM32F10X_LD) || defined(__DOXYGEN__)
/**
 * @name    STM32F103 LD capabilities
 * @{
 */
/* ADC attributes.*/
#define GD32_HAS_ADC1                      TRUE
#define GD32_HAS_ADC2                      TRUE
#define GD32_HAS_ADC3                      FALSE
#define GD32_HAS_ADC4                      FALSE

#define GD32_HAS_SDADC1                    FALSE
#define GD32_HAS_SDADC2                    FALSE
#define GD32_HAS_SDADC3                    FALSE

/* CAN attributes.*/
#define GD32_HAS_CAN1                      TRUE
#define GD32_HAS_CAN2                      FALSE
#define GD32_HAS_CAN3                      FALSE
#define GD32_CAN_MAX_FILTERS               14

/* DAC attributes.*/
#define GD32_HAS_DAC1_CH1                  FALSE
#define GD32_HAS_DAC1_CH2                  FALSE
#define GD32_HAS_DAC2_CH1                  FALSE
#define GD32_HAS_DAC2_CH2                  FALSE

/* DMA attributes.*/
#define GD32_ADVANCED_DMA                  FALSE
#define GD32_DMA_SUPPORTS_DMAMUX           FALSE
#define GD32_DMA_SUPPORTS_CSELR            FALSE

#define GD32_DMA0_NUM_CHANNELS             7
#define GD32_DMA0_CH0_HANDLER              Vector6C
#define GD32_DMA0_CH1_HANDLER              Vector70
#define GD32_DMA0_CH2_HANDLER              Vector74
#define GD32_DMA0_CH3_HANDLER              Vector78
#define GD32_DMA0_CH4_HANDLER              Vector7C
#define GD32_DMA0_CH5_HANDLER              Vector80
#define GD32_DMA0_CH6_HANDLER              Vector84
#define GD32_DMA0_CH0_NUMBER               11
#define GD32_DMA0_CH1_NUMBER               12
#define GD32_DMA0_CH2_NUMBER               13
#define GD32_DMA0_CH3_NUMBER               14
#define GD32_DMA0_CH4_NUMBER               15
#define GD32_DMA0_CH5_NUMBER               16
#define GD32_DMA0_CH6_NUMBER               17

#define GD32_DMA1_NUM_CHANNELS             0

/* ETH attributes.*/
#define GD32_HAS_ETH                       FALSE

/* EXTI attributes.*/
#define GD32_EXTI_NUM_LINES                19
#define GD32_EXTI_IMR_MASK                 0x00000000U

/* Flash attributes.*/
#define GD32_FLASH_NUMBER_OF_BANKS         1
#define GD32_FLASH_SECTOR_SIZE             1024U
#if !defined(GD32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define GD32_FLASH_SECTORS_PER_BANK        32 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define GD32_HAS_GPIOA                     TRUE
#define GD32_HAS_GPIOB                     TRUE
#define GD32_HAS_GPIOC                     TRUE
#define GD32_HAS_GPIOD                     TRUE
#define GD32_HAS_GPIOE                     FALSE
#define GD32_HAS_GPIOF                     FALSE
#define GD32_HAS_GPIOG                     FALSE
#define GD32_HAS_GPIOH                     FALSE
#define GD32_HAS_GPIOI                     FALSE
#define GD32_HAS_GPIOJ                     FALSE
#define GD32_HAS_GPIOK                     FALSE

/* I2C attributes.*/
#define GD32_HAS_I2C0                      TRUE
#define GD32_I2C_I2C0_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 7)
#define GD32_I2C_I2C0_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 6)

#define GD32_HAS_I2C1                      FALSE
#define GD32_HAS_I2C3                      FALSE
#define GD32_HAS_I2C4                      FALSE

/* QUADSPI attributes.*/
#define GD32_HAS_QUADSPI1                  FALSE

/* RTC attributes.*/
#define GD32_HAS_RTC                       TRUE
#define GD32_RTC_HAS_SUBSECONDS            TRUE
#define GD32_RTC_IS_CALENDAR               FALSE

/* SDIO attributes.*/
#define GD32_HAS_SDIO                      FALSE

/* SPI attributes.*/
#define GD32_HAS_SPI1                      TRUE
#define GD32_SPI1_SUPPORTS_I2S             FALSE
#define GD32_SPI_SPI1_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 2)
#define GD32_SPI_SPI1_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 3)

#define GD32_HAS_SPI2                      FALSE
#define GD32_HAS_SPI3                      FALSE
#define GD32_HAS_SPI4                      FALSE
#define GD32_HAS_SPI5                      FALSE
#define GD32_HAS_SPI6                      FALSE

/* TIM attributes.*/
#define GD32_TIM_MAX_CHANNELS              4

#define GD32_HAS_TIM1                      TRUE
#define GD32_TIM1_IS_32BITS                FALSE
#define GD32_TIM1_CHANNELS                 4

#define GD32_HAS_TIM2                      TRUE
#define GD32_TIM2_IS_32BITS                FALSE
#define GD32_TIM2_CHANNELS                 4

#define GD32_HAS_TIM3                      TRUE
#define GD32_TIM3_IS_32BITS                FALSE
#define GD32_TIM3_CHANNELS                 4

#define GD32_HAS_TIM4                      FALSE
#define GD32_HAS_TIM5                      FALSE
#define GD32_HAS_TIM6                      FALSE
#define GD32_HAS_TIM7                      FALSE
#define GD32_HAS_TIM8                      FALSE
#define GD32_HAS_TIM9                      FALSE
#define GD32_HAS_TIM10                     FALSE
#define GD32_HAS_TIM11                     FALSE
#define GD32_HAS_TIM12                     FALSE
#define GD32_HAS_TIM13                     FALSE
#define GD32_HAS_TIM14                     FALSE
#define GD32_HAS_TIM15                     FALSE
#define GD32_HAS_TIM16                     FALSE
#define GD32_HAS_TIM17                     FALSE
#define GD32_HAS_TIM18                     FALSE
#define GD32_HAS_TIM19                     FALSE
#define GD32_HAS_TIM20                     FALSE
#define GD32_HAS_TIM21                     FALSE
#define GD32_HAS_TIM22                     FALSE

/* USART attributes.*/
#define GD32_HAS_USART0                    TRUE
#define GD32_UART_USART0_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 5)
#define GD32_UART_USART0_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 4)

#define GD32_HAS_USART1                    TRUE
#define GD32_UART_USART1_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 6)
#define GD32_UART_USART1_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 7)

#define GD32_HAS_USART2                    FALSE
#define GD32_HAS_UART4                     FALSE
#define GD32_HAS_UART5                     FALSE
#define GD32_HAS_USART6                    FALSE
#define GD32_HAS_UART7                     FALSE
#define GD32_HAS_UART8                     FALSE
#define GD32_HAS_LPUART1                   FALSE

/* USB attributes.*/
#define GD32_HAS_USB                       FALSE
#define GD32_HAS_USBFS                      FALSE
#define GD32_HAS_OTG2                      FALSE

/* IWDG attributes.*/
#define GD32_HAS_IWDG                      TRUE
#define GD32_IWDG_IS_WINDOWED              FALSE

/* LTDC attributes.*/
#define GD32_HAS_LTDC                      FALSE

/* DMA1D attributes.*/
#define GD32_HAS_DMA1D                     FALSE

/* FSMC attributes.*/
#define GD32_HAS_FSMC                      FALSE

/* CRC attributes.*/
#define GD32_HAS_CRC                       TRUE
#define GD32_CRC_PROGRAMMABLE              FALSE
/** @} */
#endif /* defined(STM32F10X_LD) */

#if defined(STM32F10X_MD) || defined(__DOXYGEN__)
/**
 * @name    STM32F103 MD capabilities
 * @{
 */
/* ADC attributes.*/
#define GD32_HAS_ADC1                      TRUE
#define GD32_HAS_ADC2                      TRUE
#define GD32_HAS_ADC3                      FALSE
#define GD32_HAS_ADC4                      FALSE

#define GD32_HAS_SDADC1                    FALSE
#define GD32_HAS_SDADC2                    FALSE
#define GD32_HAS_SDADC3                    FALSE

/* CAN attributes.*/
#define GD32_HAS_CAN1                      TRUE
#define GD32_HAS_CAN2                      FALSE
#define GD32_HAS_CAN3                      FALSE
#define GD32_CAN_MAX_FILTERS               14

/* DAC attributes.*/
#define GD32_HAS_DAC1_CH1                  FALSE
#define GD32_HAS_DAC1_CH2                  FALSE
#define GD32_HAS_DAC2_CH1                  FALSE
#define GD32_HAS_DAC2_CH2                  FALSE

/* DMA attributes.*/
#define GD32_ADVANCED_DMA                  FALSE
#define GD32_DMA_SUPPORTS_DMAMUX           FALSE
#define GD32_DMA_SUPPORTS_CSELR            FALSE

#define GD32_DMA0_NUM_CHANNELS             7
#define GD32_DMA0_CH0_HANDLER              Vector6C
#define GD32_DMA0_CH1_HANDLER              Vector70
#define GD32_DMA0_CH2_HANDLER              Vector74
#define GD32_DMA0_CH3_HANDLER              Vector78
#define GD32_DMA0_CH4_HANDLER              Vector7C
#define GD32_DMA0_CH5_HANDLER              Vector80
#define GD32_DMA0_CH6_HANDLER              Vector84
#define GD32_DMA0_CH0_NUMBER               11
#define GD32_DMA0_CH1_NUMBER               12
#define GD32_DMA0_CH2_NUMBER               13
#define GD32_DMA0_CH3_NUMBER               14
#define GD32_DMA0_CH4_NUMBER               15
#define GD32_DMA0_CH5_NUMBER               16
#define GD32_DMA0_CH6_NUMBER               17

#define GD32_DMA1_NUM_CHANNELS             0

/* ETH attributes.*/
#define GD32_HAS_ETH                       FALSE

/* EXTI attributes.*/
#define GD32_EXTI_NUM_LINES                19
#define GD32_EXTI_IMR_MASK                 0x00000000U

/* Flash attributes.*/
#define GD32_FLASH_NUMBER_OF_BANKS         1
#define GD32_FLASH_SECTOR_SIZE             1024U
#if !defined(GD32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define GD32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define GD32_HAS_GPIOA                     TRUE
#define GD32_HAS_GPIOB                     TRUE
#define GD32_HAS_GPIOC                     TRUE
#define GD32_HAS_GPIOD                     TRUE
#define GD32_HAS_GPIOE                     TRUE
#define GD32_HAS_GPIOF                     FALSE
#define GD32_HAS_GPIOG                     FALSE
#define GD32_HAS_GPIOH                     FALSE
#define GD32_HAS_GPIOI                     FALSE
#define GD32_HAS_GPIOJ                     FALSE
#define GD32_HAS_GPIOK                     FALSE

/* I2C attributes.*/
#define GD32_HAS_I2C0                      TRUE
#define GD32_I2C_I2C0_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 7)
#define GD32_I2C_I2C0_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 6)

#define GD32_HAS_I2C1                      TRUE
#define GD32_I2C_I2C1_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 5)
#define GD32_I2C_I2C1_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 4)

#define GD32_HAS_I2C3                      FALSE
#define GD32_HAS_I2C4                      FALSE

/* QUADSPI attributes.*/
#define GD32_HAS_QUADSPI1                  FALSE

/* RTC attributes.*/
#define GD32_HAS_RTC                       TRUE
#define GD32_RTC_HAS_SUBSECONDS            TRUE
#define GD32_RTC_IS_CALENDAR               FALSE

/* SDIO attributes.*/
#define GD32_HAS_SDIO                      FALSE

/* SPI attributes.*/
#define GD32_HAS_SPI1                      TRUE
#define GD32_SPI1_SUPPORTS_I2S             FALSE
#define GD32_SPI_SPI1_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 2)
#define GD32_SPI_SPI1_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 3)

#define GD32_HAS_SPI2                      TRUE
#define GD32_SPI2_SUPPORTS_I2S             FALSE
#define GD32_SPI_SPI2_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 4)
#define GD32_SPI_SPI2_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 5)

#define GD32_HAS_SPI3                      FALSE
#define GD32_HAS_SPI4                      FALSE
#define GD32_HAS_SPI5                      FALSE
#define GD32_HAS_SPI6                      FALSE

/* TIM attributes.*/
#define GD32_TIM_MAX_CHANNELS              4

#define GD32_HAS_TIM1                      TRUE
#define GD32_TIM1_IS_32BITS                FALSE
#define GD32_TIM1_CHANNELS                 4

#define GD32_HAS_TIM2                      TRUE
#define GD32_TIM2_IS_32BITS                FALSE
#define GD32_TIM2_CHANNELS                 4

#define GD32_HAS_TIM3                      TRUE
#define GD32_TIM3_IS_32BITS                FALSE
#define GD32_TIM3_CHANNELS                 4

#define GD32_HAS_TIM4                      TRUE
#define GD32_TIM4_IS_32BITS                FALSE
#define GD32_TIM4_CHANNELS                 4

#define GD32_HAS_TIM5                      FALSE
#define GD32_HAS_TIM6                      FALSE
#define GD32_HAS_TIM7                      FALSE
#define GD32_HAS_TIM8                      FALSE
#define GD32_HAS_TIM9                      FALSE
#define GD32_HAS_TIM10                     FALSE
#define GD32_HAS_TIM11                     FALSE
#define GD32_HAS_TIM12                     FALSE
#define GD32_HAS_TIM13                     FALSE
#define GD32_HAS_TIM14                     FALSE
#define GD32_HAS_TIM15                     FALSE
#define GD32_HAS_TIM16                     FALSE
#define GD32_HAS_TIM17                     FALSE
#define GD32_HAS_TIM18                     FALSE
#define GD32_HAS_TIM19                     FALSE
#define GD32_HAS_TIM20                     FALSE
#define GD32_HAS_TIM21                     FALSE
#define GD32_HAS_TIM22                     FALSE

/* USART attributes.*/
#define GD32_HAS_USART0                    TRUE
#define GD32_UART_USART0_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 5)
#define GD32_UART_USART0_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 4)

#define GD32_HAS_USART1                    TRUE
#define GD32_UART_USART1_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 6)
#define GD32_UART_USART1_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 7)

#define GD32_HAS_USART2                    TRUE
#define GD32_UART_USART2_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 3)
#define GD32_UART_USART2_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 2)

#define GD32_HAS_UART4                     FALSE
#define GD32_HAS_UART5                     FALSE
#define GD32_HAS_USART6                    FALSE
#define GD32_HAS_UART7                     FALSE
#define GD32_HAS_UART8                     FALSE
#define GD32_HAS_LPUART1                   FALSE

/* USB attributes.*/
#define GD32_HAS_USB                       TRUE
#define GD32_USB_ACCESS_SCHEME_2x16        FALSE
#define GD32_USB_PMA_SIZE                  512
#define GD32_USB_HAS_BCDR                  FALSE
#define GD32_HAS_USBFS                      FALSE
#define GD32_HAS_OTG2                      FALSE

/* IWDG attributes.*/
#define GD32_HAS_IWDG                      TRUE
#define GD32_IWDG_IS_WINDOWED              FALSE

/* LTDC attributes.*/
#define GD32_HAS_LTDC                      FALSE

/* DMA1D attributes.*/
#define GD32_HAS_DMA1D                     FALSE

/* FSMC attributes.*/
#define GD32_HAS_FSMC                      FALSE

/* CRC attributes.*/
#define GD32_HAS_CRC                       TRUE
#define GD32_CRC_PROGRAMMABLE              FALSE
/** @} */
#endif /* defined(STM32F10X_MD) */

#if defined(STM32F10X_HD) || defined(__DOXYGEN__)
/**
 * @name    STM32F103 HD capabilities
 * @{
 */
/* ADC attributes.*/
#define GD32_HAS_ADC1                      TRUE
#define GD32_HAS_ADC2                      TRUE
#define GD32_HAS_ADC3                      TRUE
#define GD32_HAS_ADC4                      FALSE

#define GD32_HAS_SDADC1                    FALSE
#define GD32_HAS_SDADC2                    FALSE
#define GD32_HAS_SDADC3                    FALSE

/* CAN attributes.*/
#define GD32_HAS_CAN1                      TRUE
#define GD32_HAS_CAN2                      FALSE
#define GD32_HAS_CAN3                      FALSE
#define GD32_CAN_MAX_FILTERS               14

/* DAC attributes.*/
#define GD32_HAS_DAC1_CH1                  TRUE
#define GD32_DAC_DAC1_CH1_DMA_STREAM       GD32_DMA_STREAM_ID(2, 3)

#define GD32_HAS_DAC1_CH2                  TRUE
#define GD32_DAC_DAC1_CH2_DMA_STREAM       GD32_DMA_STREAM_ID(2, 4)

#define GD32_HAS_DAC2_CH1                  FALSE
#define GD32_HAS_DAC2_CH2                  FALSE

/* DMA attributes.*/
#define GD32_ADVANCED_DMA                  FALSE
#define GD32_DMA_SUPPORTS_DMAMUX           FALSE
#define GD32_DMA_SUPPORTS_CSELR            FALSE

#define GD32_DMA0_NUM_CHANNELS             7
#define GD32_DMA0_CH0_HANDLER              Vector6C
#define GD32_DMA0_CH1_HANDLER              Vector70
#define GD32_DMA0_CH2_HANDLER              Vector74
#define GD32_DMA0_CH3_HANDLER              Vector78
#define GD32_DMA0_CH4_HANDLER              Vector7C
#define GD32_DMA0_CH5_HANDLER              Vector80
#define GD32_DMA0_CH6_HANDLER              Vector84
#define GD32_DMA0_CH0_NUMBER               11
#define GD32_DMA0_CH1_NUMBER               12
#define GD32_DMA0_CH2_NUMBER               13
#define GD32_DMA0_CH3_NUMBER               14
#define GD32_DMA0_CH4_NUMBER               15
#define GD32_DMA0_CH5_NUMBER               16
#define GD32_DMA0_CH6_NUMBER               17

#define GD32_DMA1_NUM_CHANNELS             5
#define GD32_DMA1_CH0_HANDLER              Vector120
#define GD32_DMA1_CH1_HANDLER              Vector124
#define GD32_DMA1_CH2_HANDLER              Vector128
#define GD32_DMA1_CH35_HANDLER             Vector12C
#define GD32_DMA1_CH0_NUMBER               56
#define GD32_DMA1_CH1_NUMBER               57
#define GD32_DMA1_CH2_NUMBER               58
#define GD32_DMA1_CH35_NUMBER              59

#define GD32_DMA1_CH3_NUMBER               GD32_DMA1_CH35_NUMBER
#define GD32_DMA1_CH4_NUMBER               GD32_DMA1_CH35_NUMBER
#define DMA1_CH3_CMASK                      0x00000C00U
#define DMA1_CH4_CMASK                      0x00000C00U

/* ETH attributes.*/
#define GD32_HAS_ETH                       FALSE

/* EXTI attributes.*/
#define GD32_EXTI_NUM_LINES                19
#define GD32_EXTI_IMR_MASK                 0x00000000U

/* Flash attributes.*/
#define GD32_FLASH_NUMBER_OF_BANKS         1
#define GD32_FLASH_SECTOR_SIZE             2048U
#if !defined(GD32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define GD32_FLASH_SECTORS_PER_BANK        256 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define GD32_HAS_GPIOA                     TRUE
#define GD32_HAS_GPIOB                     TRUE
#define GD32_HAS_GPIOC                     TRUE
#define GD32_HAS_GPIOD                     TRUE
#define GD32_HAS_GPIOE                     TRUE
#define GD32_HAS_GPIOF                     TRUE
#define GD32_HAS_GPIOG                     TRUE
#define GD32_HAS_GPIOH                     FALSE
#define GD32_HAS_GPIOI                     FALSE
#define GD32_HAS_GPIOJ                     FALSE
#define GD32_HAS_GPIOK                     FALSE

/* I2C attributes.*/
#define GD32_HAS_I2C0                      TRUE
#define GD32_I2C_I2C0_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 7)
#define GD32_I2C_I2C0_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 6)

#define GD32_HAS_I2C1                      TRUE
#define GD32_I2C_I2C1_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 5)
#define GD32_I2C_I2C1_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 4)

#define GD32_HAS_I2C3                      FALSE
#define GD32_HAS_I2C4                      FALSE

/* QUADSPI attributes.*/
#define GD32_HAS_QUADSPI1                  FALSE

/* RTC attributes.*/
#define GD32_HAS_RTC                       TRUE
#define GD32_RTC_HAS_SUBSECONDS            TRUE
#define GD32_RTC_IS_CALENDAR               FALSE

/* SDIO attributes.*/
#define GD32_HAS_SDIO                      TRUE
#define GD32_SDC_SDIO_DMA_STREAM           GD32_DMA_STREAM_ID(2, 4)

/* SPI attributes.*/
#define GD32_HAS_SPI1                      TRUE
#define GD32_SPI1_SUPPORTS_I2S             FALSE
#define GD32_SPI_SPI1_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 2)
#define GD32_SPI_SPI1_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 3)

#define GD32_HAS_SPI2                      TRUE
#define GD32_SPI2_SUPPORTS_I2S             TRUE
#define GD32_SPI2_I2S_FULLDUPLEX           FALSE
#define GD32_SPI_SPI2_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 4)
#define GD32_SPI_SPI2_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 5)

#define GD32_HAS_SPI3                      TRUE
#define GD32_SPI3_SUPPORTS_I2S             TRUE
#define GD32_SPI3_I2S_FULLDUPLEX           FALSE
#define GD32_SPI_SPI3_RX_DMA_STREAM        GD32_DMA_STREAM_ID(2, 1)
#define GD32_SPI_SPI3_TX_DMA_STREAM        GD32_DMA_STREAM_ID(2, 2)

#define GD32_HAS_SPI4                      FALSE
#define GD32_HAS_SPI5                      FALSE
#define GD32_HAS_SPI6                      FALSE

/* TIM attributes.*/
#define GD32_TIM_MAX_CHANNELS              4

#define GD32_HAS_TIM1                      TRUE
#define GD32_TIM1_IS_32BITS                FALSE
#define GD32_TIM1_CHANNELS                 4

#define GD32_HAS_TIM2                      TRUE
#define GD32_TIM2_IS_32BITS                FALSE
#define GD32_TIM2_CHANNELS                 4

#define GD32_HAS_TIM3                      TRUE
#define GD32_TIM3_IS_32BITS                FALSE
#define GD32_TIM3_CHANNELS                 4

#define GD32_HAS_TIM4                      TRUE
#define GD32_TIM4_IS_32BITS                FALSE
#define GD32_TIM4_CHANNELS                 4

#define GD32_HAS_TIM5                      TRUE
#define GD32_TIM5_IS_32BITS                FALSE
#define GD32_TIM5_CHANNELS                 4

#define GD32_HAS_TIM6                      TRUE
#define GD32_TIM6_IS_32BITS                FALSE
#define GD32_TIM6_CHANNELS                 0

#define GD32_HAS_TIM7                      TRUE
#define GD32_TIM7_IS_32BITS                FALSE
#define GD32_TIM7_CHANNELS                 0

#define GD32_HAS_TIM8                      TRUE
#define GD32_TIM8_IS_32BITS                FALSE
#define GD32_TIM8_CHANNELS                 4

#define GD32_HAS_TIM9                      FALSE
#define GD32_HAS_TIM10                     FALSE
#define GD32_HAS_TIM11                     FALSE
#define GD32_HAS_TIM12                     FALSE
#define GD32_HAS_TIM13                     FALSE
#define GD32_HAS_TIM14                     FALSE
#define GD32_HAS_TIM15                     FALSE
#define GD32_HAS_TIM16                     FALSE
#define GD32_HAS_TIM17                     FALSE
#define GD32_HAS_TIM18                     FALSE
#define GD32_HAS_TIM19                     FALSE
#define GD32_HAS_TIM20                     FALSE
#define GD32_HAS_TIM21                     FALSE
#define GD32_HAS_TIM22                     FALSE

/* USART attributes.*/
#define GD32_HAS_USART0                    TRUE
#define GD32_UART_USART0_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 5)
#define GD32_UART_USART0_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 4)

#define GD32_HAS_USART1                    TRUE
#define GD32_UART_USART1_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 6)
#define GD32_UART_USART1_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 7)

#define GD32_HAS_USART2                    TRUE
#define GD32_UART_USART2_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 3)
#define GD32_UART_USART2_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 2)

#define GD32_HAS_UART4                     TRUE
#define GD32_UART_UART4_RX_DMA_STREAM      GD32_DMA_STREAM_ID(2, 3)
#define GD32_UART_UART4_TX_DMA_STREAM      GD32_DMA_STREAM_ID(2, 5)

#define GD32_HAS_UART5                     FALSE
#define GD32_HAS_USART6                    FALSE
#define GD32_HAS_UART7                     FALSE
#define GD32_HAS_UART8                     FALSE
#define GD32_HAS_LPUART1                   FALSE

/* USB attributes.*/
#define GD32_HAS_USB                       TRUE
#define GD32_USB_ACCESS_SCHEME_2x16        FALSE
#define GD32_USB_PMA_SIZE                  512
#define GD32_USB_HAS_BCDR                  FALSE
#define GD32_HAS_USBFS                      FALSE
#define GD32_HAS_OTG2                      FALSE

/* IWDG attributes.*/
#define GD32_HAS_IWDG                      TRUE
#define GD32_IWDG_IS_WINDOWED              FALSE

/* LTDC attributes.*/
#define GD32_HAS_LTDC                      FALSE

/* DMA1D attributes.*/
#define GD32_HAS_DMA1D                     FALSE

/* FSMC attributes.*/
#define GD32_HAS_FSMC                      TRUE
#define GD32_FSMC_IS_FMC                   FALSE
#define GD32_FSMC_HANDLER                  Vector100
#define GD32_FSMC_NUMBER                   48

/* CRC attributes.*/
#define GD32_HAS_CRC                       TRUE
#define GD32_CRC_PROGRAMMABLE              FALSE
/** @} */
#endif /* defined(STM32F10X_HD) */

#if defined(STM32F10X_XL) || defined(__DOXYGEN__)
/**
 * @name    STM32F103 XL capabilities
 * @{
 */
/* ADC attributes.*/
#define GD32_HAS_ADC1                      TRUE
#define GD32_HAS_ADC2                      TRUE
#define GD32_HAS_ADC3                      TRUE
#define GD32_HAS_ADC4                      FALSE

#define GD32_HAS_SDADC1                    FALSE
#define GD32_HAS_SDADC2                    FALSE
#define GD32_HAS_SDADC3                    FALSE

/* CAN attributes.*/
#define GD32_HAS_CAN1                      TRUE
#define GD32_HAS_CAN2                      FALSE
#define GD32_HAS_CAN3                      FALSE
#define GD32_CAN_MAX_FILTERS               14

/* DAC attributes.*/
#define GD32_HAS_DAC1_CH1                  TRUE
#define GD32_DAC_DAC1_CH1_DMA_STREAM       GD32_DMA_STREAM_ID(2, 3)

#define GD32_HAS_DAC1_CH2                  TRUE
#define GD32_DAC_DAC1_CH2_DMA_STREAM       GD32_DMA_STREAM_ID(2, 4)

#define GD32_HAS_DAC2_CH1                  FALSE
#define GD32_HAS_DAC2_CH2                  FALSE

/* DMA attributes.*/
#define GD32_ADVANCED_DMA                  FALSE
#define GD32_DMA_SUPPORTS_DMAMUX           FALSE
#define GD32_DMA_SUPPORTS_CSELR            FALSE

#define GD32_DMA0_NUM_CHANNELS             7
#define GD32_DMA0_CH0_HANDLER              Vector6C
#define GD32_DMA0_CH1_HANDLER              Vector70
#define GD32_DMA0_CH2_HANDLER              Vector74
#define GD32_DMA0_CH3_HANDLER              Vector78
#define GD32_DMA0_CH4_HANDLER              Vector7C
#define GD32_DMA0_CH5_HANDLER              Vector80
#define GD32_DMA0_CH6_HANDLER              Vector84
#define GD32_DMA0_CH0_NUMBER               11
#define GD32_DMA0_CH1_NUMBER               12
#define GD32_DMA0_CH2_NUMBER               13
#define GD32_DMA0_CH3_NUMBER               14
#define GD32_DMA0_CH4_NUMBER               15
#define GD32_DMA0_CH5_NUMBER               16
#define GD32_DMA0_CH6_NUMBER               17

#define GD32_DMA1_NUM_CHANNELS             5
#define GD32_DMA1_CH0_HANDLER              Vector120
#define GD32_DMA1_CH1_HANDLER              Vector124
#define GD32_DMA1_CH2_HANDLER              Vector128
#define GD32_DMA1_CH3_HANDLER              Vector12C
#define GD32_DMA1_CH4_HANDLER              Vector130
#define GD32_DMA1_CH0_NUMBER               56
#define GD32_DMA1_CH1_NUMBER               57
#define GD32_DMA1_CH2_NUMBER               58
#define GD32_DMA1_CH3_NUMBER               59
#define GD32_DMA1_CH4_NUMBER               60

/* ETH attributes.*/
#define GD32_HAS_ETH                       FALSE

/* EXTI attributes.*/
#define GD32_EXTI_NUM_LINES                19
#define GD32_EXTI_IMR_MASK                 0x00000000U

/* Flash attributes.*/
#define GD32_FLASH_NUMBER_OF_BANKS         2
#define GD32_FLASH_SECTOR_SIZE             2048U
#if !defined(GD32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define GD32_FLASH_SECTORS_PER_BANK        256 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define GD32_HAS_GPIOA                     TRUE
#define GD32_HAS_GPIOB                     TRUE
#define GD32_HAS_GPIOC                     TRUE
#define GD32_HAS_GPIOD                     TRUE
#define GD32_HAS_GPIOE                     TRUE
#define GD32_HAS_GPIOF                     TRUE
#define GD32_HAS_GPIOG                     TRUE
#define GD32_HAS_GPIOH                     FALSE
#define GD32_HAS_GPIOI                     FALSE
#define GD32_HAS_GPIOJ                     FALSE
#define GD32_HAS_GPIOK                     FALSE

/* I2C attributes.*/
#define GD32_HAS_I2C0                      TRUE
#define GD32_I2C_I2C0_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 7)
#define GD32_I2C_I2C0_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 6)

#define GD32_HAS_I2C1                      TRUE
#define GD32_I2C_I2C1_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 5)
#define GD32_I2C_I2C1_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 4)

#define GD32_HAS_I2C3                      FALSE
#define GD32_HAS_I2C4                      FALSE

/* QUADSPI attributes.*/
#define GD32_HAS_QUADSPI1                  FALSE

/* RTC attributes.*/
#define GD32_HAS_RTC                       TRUE
#define GD32_RTC_HAS_SUBSECONDS            TRUE
#define GD32_RTC_IS_CALENDAR               FALSE

/* SDIO attributes.*/
#define GD32_HAS_SDIO                      TRUE
#define GD32_SDC_SDIO_DMA_STREAM           GD32_DMA_STREAM_ID(2, 4)

/* SPI attributes.*/
#define GD32_HAS_SPI1                      TRUE
#define GD32_SPI1_SUPPORTS_I2S             FALSE
#define GD32_SPI_SPI1_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 2)
#define GD32_SPI_SPI1_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 3)

#define GD32_HAS_SPI2                      TRUE
#define GD32_SPI2_SUPPORTS_I2S             TRUE
#define GD32_SPI2_I2S_FULLDUPLEX           FALSE
#define GD32_SPI_SPI2_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 4)
#define GD32_SPI_SPI2_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 5)

#define GD32_HAS_SPI3                      TRUE
#define GD32_SPI3_SUPPORTS_I2S             TRUE
#define GD32_SPI3_I2S_FULLDUPLEX           FALSE
#define GD32_SPI_SPI3_RX_DMA_STREAM        GD32_DMA_STREAM_ID(2, 1)
#define GD32_SPI_SPI3_TX_DMA_STREAM        GD32_DMA_STREAM_ID(2, 2)

#define GD32_HAS_SPI4                      FALSE
#define GD32_HAS_SPI5                      FALSE
#define GD32_HAS_SPI6                      FALSE

/* TIM attributes.*/
#define GD32_TIM_MAX_CHANNELS              4

#define GD32_HAS_TIM1                      TRUE
#define GD32_TIM1_IS_32BITS                FALSE
#define GD32_TIM1_CHANNELS                 4

#define GD32_HAS_TIM2                      TRUE
#define GD32_TIM2_IS_32BITS                FALSE
#define GD32_TIM2_CHANNELS                 4

#define GD32_HAS_TIM3                      TRUE
#define GD32_TIM3_IS_32BITS                FALSE
#define GD32_TIM3_CHANNELS                 4

#define GD32_HAS_TIM4                      TRUE
#define GD32_TIM4_IS_32BITS                FALSE
#define GD32_TIM4_CHANNELS                 4

#define GD32_HAS_TIM5                      TRUE
#define GD32_TIM5_IS_32BITS                FALSE
#define GD32_TIM5_CHANNELS                 4

#define GD32_HAS_TIM6                      TRUE
#define GD32_TIM6_IS_32BITS                FALSE
#define GD32_TIM6_CHANNELS                 0

#define GD32_HAS_TIM7                      TRUE
#define GD32_TIM7_IS_32BITS                FALSE
#define GD32_TIM7_CHANNELS                 0

#define GD32_HAS_TIM8                      TRUE
#define GD32_TIM8_IS_32BITS                FALSE
#define GD32_TIM8_CHANNELS                 4

#define GD32_HAS_TIM9                      TRUE
#define GD32_TIM9_IS_32BITS                FALSE
#define GD32_TIM9_CHANNELS                 2

#define GD32_HAS_TIM10                     TRUE
#define GD32_TIM10_IS_32BITS               FALSE
#define GD32_TIM10_CHANNELS                1

#define GD32_HAS_TIM11                     TRUE
#define GD32_TIM11_IS_32BITS               FALSE
#define GD32_TIM11_CHANNELS                1

#define GD32_HAS_TIM12                     TRUE
#define GD32_TIM12_IS_32BITS               FALSE
#define GD32_TIM12_CHANNELS                2

#define GD32_HAS_TIM13                     TRUE
#define GD32_TIM13_IS_32BITS               FALSE
#define GD32_TIM13_CHANNELS                1

#define GD32_HAS_TIM14                     TRUE
#define GD32_TIM14_IS_32BITS               FALSE
#define GD32_TIM14_CHANNELS                1

#define GD32_HAS_TIM15                     FALSE
#define GD32_HAS_TIM16                     FALSE
#define GD32_HAS_TIM17                     FALSE
#define GD32_HAS_TIM18                     FALSE
#define GD32_HAS_TIM19                     FALSE
#define GD32_HAS_TIM20                     FALSE
#define GD32_HAS_TIM21                     FALSE
#define GD32_HAS_TIM22                     FALSE

/* USART attributes.*/
#define GD32_HAS_USART0                    TRUE
#define GD32_UART_USART0_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 5)
#define GD32_UART_USART0_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 4)

#define GD32_HAS_USART1                    TRUE
#define GD32_UART_USART1_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 6)
#define GD32_UART_USART1_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 7)

#define GD32_HAS_USART2                    TRUE
#define GD32_UART_USART2_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 3)
#define GD32_UART_USART2_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 2)

#define GD32_HAS_UART4                     TRUE
#define GD32_UART_UART4_RX_DMA_STREAM      GD32_DMA_STREAM_ID(2, 3)
#define GD32_UART_UART4_TX_DMA_STREAM      GD32_DMA_STREAM_ID(2, 5)

#define GD32_HAS_UART5                     FALSE
#define GD32_HAS_USART6                    FALSE
#define GD32_HAS_UART7                     FALSE
#define GD32_HAS_UART8                     FALSE
#define GD32_HAS_LPUART1                   FALSE

/* USB attributes.*/
#define GD32_HAS_USB                       TRUE
#define GD32_USB_ACCESS_SCHEME_2x16        FALSE
#define GD32_USB_PMA_SIZE                  512
#define GD32_USB_HAS_BCDR                  FALSE
#define GD32_HAS_USBFS                      FALSE
#define GD32_HAS_OTG2                      FALSE

/* IWDG attributes.*/
#define GD32_HAS_IWDG                      TRUE
#define GD32_IWDG_IS_WINDOWED              FALSE

/* LTDC attributes.*/
#define GD32_HAS_LTDC                      FALSE

/* DMA1D attributes.*/
#define GD32_HAS_DMA1D                     FALSE

/* FSMC attributes.*/
#define GD32_HAS_FSMC                      TRUE
#define GD32_FSMC_IS_FMC                   FALSE
#define GD32_FSMC_HANDLER                  Vector100
#define GD32_FSMC_NUMBER                   48

/* CRC attributes.*/
#define GD32_HAS_CRC                       TRUE
#define GD32_CRC_PROGRAMMABLE              FALSE
/** @} */
#endif /* defined(STM32F10X_XL) */
#define STM32F10X_CL
#if defined(STM32F10X_CL) || defined(__DOXYGEN__)
/**
 * @name    STM32F105/F107 CL capabilities
 * @{
 */
/* ADC attributes.*/
#define GD32_HAS_ADC1                      TRUE
#define GD32_HAS_ADC2                      TRUE
#define GD32_HAS_ADC3                      FALSE
#define GD32_HAS_ADC4                      FALSE

#define GD32_HAS_SDADC1                    FALSE
#define GD32_HAS_SDADC2                    FALSE
#define GD32_HAS_SDADC3                    FALSE

/* CAN attributes.*/
#define GD32_HAS_CAN1                      TRUE
#define GD32_HAS_CAN2                      TRUE
#define GD32_HAS_CAN3                      FALSE
#define GD32_CAN_MAX_FILTERS               28

/* DAC attributes.*/
#define GD32_HAS_DAC1_CH1                  TRUE
#define GD32_DAC_DAC1_CH1_DMA_STREAM       GD32_DMA_STREAM_ID(2, 3)

#define GD32_HAS_DAC1_CH2                  TRUE
#define GD32_DAC_DAC1_CH2_DMA_STREAM       GD32_DMA_STREAM_ID(2, 4)

#define GD32_HAS_DAC2_CH1                  FALSE
#define GD32_HAS_DAC2_CH2                  FALSE

/* DMA attributes.*/
#define GD32_ADVANCED_DMA                  FALSE
#define GD32_DMA_SUPPORTS_DMAMUX           FALSE
#define GD32_DMA_SUPPORTS_CSELR            FALSE

#define GD32_DMA0_NUM_CHANNELS             7
#define GD32_DMA0_CH0_HANDLER              Vector6C
#define GD32_DMA0_CH1_HANDLER              Vector70
#define GD32_DMA0_CH2_HANDLER              Vector74
#define GD32_DMA0_CH3_HANDLER              Vector78
#define GD32_DMA0_CH4_HANDLER              Vector7C
#define GD32_DMA0_CH5_HANDLER              Vector80
#define GD32_DMA0_CH6_HANDLER              Vector84
#define GD32_DMA0_CH0_NUMBER               11
#define GD32_DMA0_CH1_NUMBER               12
#define GD32_DMA0_CH2_NUMBER               13
#define GD32_DMA0_CH3_NUMBER               14
#define GD32_DMA0_CH4_NUMBER               15
#define GD32_DMA0_CH5_NUMBER               16
#define GD32_DMA0_CH6_NUMBER               17

#define GD32_DMA1_NUM_CHANNELS             5
#define GD32_DMA1_CH0_HANDLER              Vector120
#define GD32_DMA1_CH1_HANDLER              Vector124
#define GD32_DMA1_CH2_HANDLER              Vector128
#define GD32_DMA1_CH3_HANDLER              Vector12C
#define GD32_DMA1_CH4_HANDLER              Vector130
#define GD32_DMA1_CH0_NUMBER               56
#define GD32_DMA1_CH1_NUMBER               57
#define GD32_DMA1_CH2_NUMBER               58
#define GD32_DMA1_CH3_NUMBER               59
#define GD32_DMA1_CH4_NUMBER               60

/* ETH attributes.*/
#define GD32_HAS_ETH                       TRUE
#define GD32_ETH_HANDLER                   Vector134
#define GD32_ETH_NUMBER                    61

/* EXTI attributes.*/
#define GD32_EXTI_NUM_LINES                20
#define GD32_EXTI_IMR_MASK                 0x00000000U

/* Flash attributes.*/
#define GD32_FLASH_NUMBER_OF_BANKS         1
#define GD32_FLASH_SECTOR_SIZE             2048U
#if !defined(GD32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define GD32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define GD32_HAS_GPIOA                     TRUE
#define GD32_HAS_GPIOB                     TRUE
#define GD32_HAS_GPIOC                     TRUE
#define GD32_HAS_GPIOD                     TRUE
#define GD32_HAS_GPIOE                     TRUE
#define GD32_HAS_GPIOF                     FALSE
#define GD32_HAS_GPIOG                     FALSE
#define GD32_HAS_GPIOH                     FALSE
#define GD32_HAS_GPIOI                     FALSE
#define GD32_HAS_GPIOJ                     FALSE
#define GD32_HAS_GPIOK                     FALSE

/* I2C attributes.*/
#define GD32_HAS_I2C0                      TRUE
#define GD32_I2C_I2C0_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 7)
#define GD32_I2C_I2C0_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 6)

#define GD32_HAS_I2C1                      TRUE
#define GD32_I2C_I2C1_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 5)
#define GD32_I2C_I2C1_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 4)

#define GD32_HAS_I2C3                      FALSE
#define GD32_HAS_I2C4                      FALSE

/* QUADSPI attributes.*/
#define GD32_HAS_QUADSPI1                  FALSE

/* RTC attributes.*/
#define GD32_HAS_RTC                       TRUE
#define GD32_RTC_HAS_SUBSECONDS            TRUE
#define GD32_RTC_IS_CALENDAR               FALSE

/* SDIO attributes.*/
#define GD32_HAS_SDIO                      FALSE

/* SPI attributes.*/
#define GD32_HAS_SPI1                      TRUE
#define GD32_SPI1_SUPPORTS_I2S             FALSE
#define GD32_SPI_SPI1_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 2)
#define GD32_SPI_SPI1_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 3)

#define GD32_HAS_SPI2                      TRUE
#define GD32_SPI2_SUPPORTS_I2S             TRUE
#define GD32_SPI2_I2S_FULLDUPLEX           FALSE
#define GD32_SPI_SPI2_RX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 4)
#define GD32_SPI_SPI2_TX_DMA_STREAM        GD32_DMA_STREAM_ID(1, 5)

#define GD32_HAS_SPI3                      TRUE
#define GD32_SPI3_SUPPORTS_I2S             TRUE
#define GD32_SPI3_I2S_FULLDUPLEX           FALSE
#define GD32_SPI_SPI3_RX_DMA_STREAM        GD32_DMA_STREAM_ID(2, 1)
#define GD32_SPI_SPI3_TX_DMA_STREAM        GD32_DMA_STREAM_ID(2, 2)

#define GD32_HAS_SPI4                      FALSE
#define GD32_HAS_SPI5                      FALSE
#define GD32_HAS_SPI6                      FALSE

/* TIM attributes.*/
#define GD32_TIM_MAX_CHANNELS              4

#define GD32_HAS_TIM1                      TRUE
#define GD32_TIM1_IS_32BITS                FALSE
#define GD32_TIM1_CHANNELS                 4

#define GD32_HAS_TIM2                      TRUE
#define GD32_TIM2_IS_32BITS                FALSE
#define GD32_TIM2_CHANNELS                 4

#define GD32_HAS_TIM3                      TRUE
#define GD32_TIM3_IS_32BITS                FALSE
#define GD32_TIM3_CHANNELS                 4

#define GD32_HAS_TIM4                      TRUE
#define GD32_TIM4_IS_32BITS                FALSE
#define GD32_TIM4_CHANNELS                 4

#define GD32_HAS_TIM5                      TRUE
#define GD32_TIM5_IS_32BITS                FALSE
#define GD32_TIM5_CHANNELS                 4

#define GD32_HAS_TIM6                      TRUE
#define GD32_TIM6_IS_32BITS                FALSE
#define GD32_TIM6_CHANNELS                 0

#define GD32_HAS_TIM7                      TRUE
#define GD32_TIM7_IS_32BITS                FALSE
#define GD32_TIM7_CHANNELS                 0

#define GD32_HAS_TIM8                      FALSE
#define GD32_HAS_TIM9                      FALSE
#define GD32_HAS_TIM10                     FALSE
#define GD32_HAS_TIM11                     FALSE
#define GD32_HAS_TIM12                     FALSE
#define GD32_HAS_TIM13                     FALSE
#define GD32_HAS_TIM14                     FALSE
#define GD32_HAS_TIM15                     FALSE
#define GD32_HAS_TIM16                     FALSE
#define GD32_HAS_TIM17                     FALSE
#define GD32_HAS_TIM18                     FALSE
#define GD32_HAS_TIM19                     FALSE
#define GD32_HAS_TIM20                     FALSE
#define GD32_HAS_TIM21                     FALSE
#define GD32_HAS_TIM22                     FALSE

/* USART attributes.*/
#define GD32_HAS_USART0                    TRUE
#define GD32_UART_USART0_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 5)
#define GD32_UART_USART0_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 4)

#define GD32_HAS_USART1                    TRUE
#define GD32_UART_USART1_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 6)
#define GD32_UART_USART1_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 7)

#define GD32_HAS_USART2                    TRUE
#define GD32_UART_USART2_RX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 3)
#define GD32_UART_USART2_TX_DMA_STREAM     GD32_DMA_STREAM_ID(1, 2)

#define GD32_HAS_UART4                     TRUE
#define GD32_UART_UART4_RX_DMA_STREAM      GD32_DMA_STREAM_ID(2, 3)
#define GD32_UART_UART4_TX_DMA_STREAM      GD32_DMA_STREAM_ID(2, 5)

#define GD32_HAS_UART5                     TRUE

#define GD32_HAS_USART6                    FALSE
#define GD32_HAS_UART7                     FALSE
#define GD32_HAS_UART8                     FALSE
#define GD32_HAS_LPUART1                   FALSE

/* USB attributes.*/
#define GD32_HAS_USBFS                      TRUE
#define GD32_USBFS_ENDPOINTS                3

#define GD32_HAS_OTG2                      FALSE
#define GD32_HAS_USB                       FALSE

/* IWDG attributes.*/
#define GD32_HAS_IWDG                      TRUE
#define GD32_IWDG_IS_WINDOWED              FALSE

/* LTDC attributes.*/
#define GD32_HAS_LTDC                      FALSE

/* DMA1D attributes.*/
#define GD32_HAS_DMA1D                     FALSE

/* FSMC attributes.*/
#define GD32_HAS_FSMC                      FALSE

/* CRC attributes.*/
#define GD32_HAS_CRC                       TRUE
#define GD32_CRC_PROGRAMMABLE              FALSE
/** @} */
#endif /* defined(STM32F10X_CL) */

#endif /* GD32_REGISTRY_H */

/** @} */
