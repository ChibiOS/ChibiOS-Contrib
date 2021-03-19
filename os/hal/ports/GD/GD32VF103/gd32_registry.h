/*
    ChibiOS - Copyright (C) 2021 Stefan Kerkmann

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
 * @file    GD32VF103/gd32_registry.h
 * @brief   GD32VF103xx capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef GD32_REGISTRY_H
#define GD32_REGISTRY_H

#if defined(GD32VF103TB) || defined(GD32VF103T8)

#define GD32_HAS_TIM_1234                   TRUE
#define GD32_HAS_USART_01                   TRUE
#define GD32_HAS_I2C_0                      TRUE
#define GD32_HAS_SPI_0                      TRUE
#define GD32_HAS_GPIO_AB                    TRUE

#elif defined(GD32VF103T6) || defined(GD32VF103T4)

#define GD32_HAS_TIM_12                     TRUE
#define GD32_HAS_USART_01                   TRUE
#define GD32_HAS_I2C_0                      TRUE
#define GD32_HAS_SPI_0                      TRUE
#define GD32_HAS_GPIO_AB                    TRUE

#elif defined(GD32VF103CB) || defined(GD32VF103C8)

#define GD32_HAS_TIM_1234                   TRUE
#define GD32_HAS_USART_012                  TRUE
#define GD32_HAS_I2C_01                     TRUE
#define GD32_HAS_SPI_012                    TRUE
#define GD32_HAS_GPIO_AB                    TRUE

#elif defined(GD32VF103C6) || defined(GD32VF103C4)

#define GD32_HAS_TIM_12                     TRUE
#define GD32_HAS_USART_01                   TRUE
#define GD32_HAS_I2C_0                      TRUE
#define GD32_HAS_SPI_0                      TRUE
#define GD32_HAS_GPIO_AB                    TRUE

#elif defined(GD32VF103RB) || defined(GD32VF103R8)

#define GD32_HAS_TIM_1234                   TRUE
#define GD32_HAS_USART_01234                TRUE
#define GD32_HAS_I2C_01                     TRUE
#define GD32_HAS_SPI_012                    TRUE
#define GD32_HAS_GPIO_ABCD                  TRUE

#elif defined(GD32VF103R6) || defined(GD32VF103R4)

#define GD32_HAS_TIM_12                     TRUE
#define GD32_HAS_USART_01                   TRUE
#define GD32_HAS_I2C_0                      TRUE
#define GD32_HAS_SPI_0                      TRUE
#define GD32_HAS_GPIO_ABCD                  TRUE

#elif defined(GD32VF103VB) || defined(GD32VF103V8)

#define GD32_HAS_TIM_1234                   TRUE
#define GD32_HAS_USART_01234                TRUE
#define GD32_HAS_I2C_01                     TRUE
#define GD32_HAS_SPI_012                    TRUE
#define GD32_HAS_GPIO_ABCDE                 TRUE
#define GD32_HAS_EXMC                       TRUE

#else

#error "unsupported or unrecognized GD32VF103 member"

#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

#if defined(GD32VF103) || defined(__DOXYGEN__)
/**
 * @name    GD32VF103 family capabilities
 * @{
 */
/* ADC attributes.*/
#define STM32_HAS_ADC1                      TRUE
#define STM32_HAS_ADC2                      TRUE

/* CAN attributes.*/
#define STM32_HAS_CAN1                      TRUE
#define STM32_HAS_CAN2                      TRUE
#define STM32_CAN_MAX_FILTERS               28

/* DAC attributes.*/
#define STM32_HAS_DAC1_CH1                  TRUE
#define STM32_DAC_DAC1_CH1_DMA_STREAM       STM32_DMA_STREAM_ID(1, 3)

#define STM32_HAS_DAC1_CH2                  TRUE
#define STM32_DAC_DAC1_CH2_DMA_STREAM       STM32_DMA_STREAM_ID(1, 4)

/* DMA attributes.*/
#define STM32_ADVANCED_DMA                  FALSE
#define STM32_DMA_SUPPORTS_DMAMUX           FALSE
#define STM32_DMA_SUPPORTS_CSELR            FALSE

#define STM32_DMA1_NUM_CHANNELS             7
#define GD32_DMA1_CH1_HANDLER               vector30
#define GD32_DMA1_CH2_HANDLER               vector31
#define GD32_DMA1_CH3_HANDLER               vector32
#define GD32_DMA1_CH4_HANDLER               vector33
#define GD32_DMA1_CH5_HANDLER               vector34
#define GD32_DMA1_CH6_HANDLER               vector35
#define GD32_DMA1_CH7_HANDLER               vector36
#define GD32_DMA1_CH1_NUMBER                30
#define GD32_DMA1_CH2_NUMBER                31
#define GD32_DMA1_CH3_NUMBER                32
#define GD32_DMA1_CH4_NUMBER                33
#define GD32_DMA1_CH5_NUMBER                34
#define GD32_DMA1_CH6_NUMBER                35
#define GD32_DMA1_CH7_NUMBER                36

#define STM32_DMA2_NUM_CHANNELS             5
#define STM32_DMA2_CH1_HANDLER              vector75
#define STM32_DMA2_CH2_HANDLER              vector76
#define STM32_DMA2_CH3_HANDLER              vector77
#define STM32_DMA2_CH4_HANDLER              vector78
#define STM32_DMA2_CH5_HANDLER              vector79
#define GD32_DMA2_CH1_NUMBER                75
#define GD32_DMA2_CH2_NUMBER                76
#define GD32_DMA2_CH3_NUMBER                77
#define GD32_DMA2_CH4_NUMBER                78
#define GD32_DMA2_CH5_NUMBER                79

/* EXTI attributes.*/
#define STM32_EXTI_NUM_LINES                19
#define STM32_EXTI_IMR_MASK                 0x00000000U

/* Flash attributes.*/
#define GD32_FLASH_NUMBER_OF_BANKS         1
#define STM32_FLASH_SECTOR_SIZE             1024U
#if !defined(STM32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define STM32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#if GD32_HAS_GPIO_AB || GD32_HAS_GPIO_ABCD || GD32_HAS_GPIO_ABCDE
    #define STM32_HAS_GPIOA                     TRUE
    #define STM32_HAS_GPIOB                     TRUE
#else
    #define STM32_HAS_GPIOA                     FALSE
    #define STM32_HAS_GPIOB                     FALSE
#endif

#if GD32_HAS_GPIO_ABCD || GD32_HAS_GPIO_ABCDE
    #define STM32_HAS_GPIOC                     TRUE
    #define STM32_HAS_GPIOD                     TRUE
#else
    #define STM32_HAS_GPIOC                     FALSE
    #define STM32_HAS_GPIOD                     FALSE
#endif

#if GD32_HAS_GPIO_ABCDE
    #define STM32_HAS_GPIOE                     TRUE
#else
    #define STM32_HAS_GPIOE                     FALSE
#endif

/* I2C attributes.*/
#if GD32_HAS_I2C_0 || GD32_HAS_I2C_01
    #define STM32_HAS_I2C1                      TRUE
    #define STM32_I2C_I2C1_RX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 7)
    #define STM32_I2C_I2C1_TX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 6)
#else
    #define STM32_HAS_I2C1                      FALSE
#endif

#if GD32_HAS_I2C_01
    #define STM32_HAS_I2C2                      TRUE
    #define STM32_I2C_I2C2_RX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 5)
    #define STM32_I2C_I2C2_TX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 4)
#else
    #define STM32_HAS_I2C2                      FALSE
#endif

/* RTC attributes.*/
#define STM32_HAS_RTC                       TRUE
#define STM32_RTC_HAS_SUBSECONDS            TRUE
#define STM32_RTC_IS_CALENDAR               FALSE

/* SPI attributes.*/
#if GD32_HAS_SPI_0 || GD32_HAS_SPI_012
    #define STM32_HAS_SPI1                      TRUE
    #define STM32_SPI1_SUPPORTS_I2S             FALSE
    #define STM32_SPI_SPI1_RX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 2)
    #define STM32_SPI_SPI1_TX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 3)
#else
    #define STM32_HAS_SPI1                      FALSE
#endif

#if GD32_HAS_SPI_012
    #define STM32_HAS_SPI2                      TRUE
    #define STM32_SPI2_SUPPORTS_I2S             TRUE
    #define STM32_SPI2_I2S_FULLDUPLEX           FALSE
    #define STM32_SPI_SPI2_RX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 4)
    #define STM32_SPI_SPI2_TX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 5)
    
    #define STM32_HAS_SPI3                      TRUE
    #define STM32_SPI3_SUPPORTS_I2S             TRUE
    #define STM32_SPI3_I2S_FULLDUPLEX           FALSE
    #define STM32_SPI_SPI3_RX_DMA_STREAM        STM32_DMA_STREAM_ID(2, 1)
    #define STM32_SPI_SPI3_TX_DMA_STREAM        STM32_DMA_STREAM_ID(2, 2)
#else
    #define STM32_HAS_SPI2                      FALSE
    #define STM32_HAS_SPI3                      FALSE
#endif

/* TIM attributes.*/
#define STM32_TIM_MAX_CHANNELS              4

#define STM32_HAS_TIM1                      TRUE
#define STM32_TIM1_IS_32BITS                FALSE
#define STM32_TIM1_CHANNELS                 4

#if GD32_HAS_TIM_12 || GD32_HAS_TIM_1234
    #define STM32_HAS_TIM2                      TRUE
    #define STM32_TIM2_IS_32BITS                FALSE
    #define STM32_TIM2_CHANNELS                 4

    #define STM32_HAS_TIM3                      TRUE
    #define STM32_TIM3_IS_32BITS                FALSE
    #define STM32_TIM3_CHANNELS                 4
#else
    #define STM32_HAS_TIM2                      FALSE
    #define STM32_HAS_TIM3                      FALSE
#endif

#if GD32_HAS_TIM_1234
    #define STM32_HAS_TIM4                      TRUE
    #define STM32_TIM4_IS_32BITS                FALSE
    #define STM32_TIM4_CHANNELS                 4

    #define STM32_HAS_TIM5                      TRUE
    #define STM32_TIM5_IS_32BITS                FALSE
    #define STM32_TIM5_CHANNELS                 4
#else
    #define STM32_HAS_TIM4                      FALSE
    #define STM32_HAS_TIM5                      FALSE
#endif

#define STM32_HAS_TIM6                      TRUE
#define STM32_TIM6_IS_32BITS                FALSE
#define STM32_TIM6_CHANNELS                 0

#define STM32_HAS_TIM7                      TRUE
#define STM32_TIM7_IS_32BITS                FALSE
#define STM32_TIM7_CHANNELS                 0

/* USART attributes.*/
#if GD32_HAS_USART_01 || GD32_HAS_USART_012 || GD32_HAS_USART_01234
    #define STM32_HAS_USART1                    TRUE
    #define STM32_UART_USART1_RX_DMA_STREAM     STM32_DMA_STREAM_ID(1, 5)
    #define STM32_UART_USART1_TX_DMA_STREAM     STM32_DMA_STREAM_ID(1, 4)

    #define STM32_HAS_USART2                    TRUE
    #define STM32_UART_USART2_RX_DMA_STREAM     STM32_DMA_STREAM_ID(1, 6)
    #define STM32_UART_USART2_TX_DMA_STREAM     STM32_DMA_STREAM_ID(1, 7)
#else
    #define STM32_HAS_USART1                    FALSE
    #define STM32_HAS_USART2                    FALSE
#endif

#if GD32_HAS_USART_012 || GD32_HAS_USART_01234
    #define STM32_HAS_USART3                    TRUE
    #define STM32_UART_USART3_RX_DMA_STREAM     STM32_DMA_STREAM_ID(1, 3)
    #define STM32_UART_USART3_TX_DMA_STREAM     STM32_DMA_STREAM_ID(1, 2)
#else
    #define STM32_HAS_USART3                    FALSE
#endif

#if GD32_HAS_USART_01234
    #define STM32_HAS_UART4                     TRUE
    #define STM32_UART_UART4_RX_DMA_STREAM      STM32_DMA_STREAM_ID(2, 3)
    #define STM32_UART_UART4_TX_DMA_STREAM      STM32_DMA_STREAM_ID(2, 5)
    #define STM32_HAS_UART5                     TRUE
#else
    #define STM32_HAS_UART4                     FALSE
    #define STM32_HAS_UART5                     FALSE
#endif

/* USB attributes.*/
#define STM32_OTG_STEPPING                  1
#define STM32_HAS_OTG1                      TRUE
#define STM32_OTG1_ENDPOINTS                3

#define STM32_HAS_USB                       TRUE

/* IWDG attributes.*/
#define STM32_HAS_IWDG                      TRUE
#define STM32_IWDG_IS_WINDOWED              FALSE

/* FSMC attributes.*/
#if GD32_HAS_EXMC
    #define STM32_HAS_FSMC                      TRUE
#else
    #define STM32_HAS_FSMC                      FALSE
#endif

/* CRC attributes.*/
#define STM32_HAS_CRC                       TRUE
#define STM32_CRC_PROGRAMMABLE              FALSE

#endif

/** @} */

#endif /* GD32_REGISTRY_H */

/** @} */
