/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2026 HorrorTroll
    ChibiOS - Copyright (C) 2023..2026 Zhaqian

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
 * @file    AT32F415/at32_registry.h
 * @brief   AT32F415 capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef AT32_REGISTRY_H
#define AT32_REGISTRY_H

/* Define by package size */
#if defined(AT32F415KB) || defined(AT32F415KC)
#define AT32F415Kx

#elif defined(AT32F415CB) || defined(AT32F415CC)
#define AT32F415Cx

#elif defined(AT32F415RB) ||  defined(AT32F415RC)
#define AT32F415Rx

#else
#error "unsupported or unrecognized AT32F415 package size"
#endif

/* Define by flash size */
#if defined(AT32F415KB) || defined(AT32F415CB) || defined(AT32F415RB)
#define AT32F415xB

#elif defined(AT32F415KC) || defined(AT32F415CC) || defined(AT32F415RC)
#define AT32F415xC

#else
#error "unsupported or unrecognized AT32F415 flash size"
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    AT32F415 capabilities
 * @{
 */

/* DEBUG helpers.*/
#define AT32_DEBUG_TMR1_STOP()             DEBUG->CTRL |= DEBUG_CTRL_TMR1_PAUSE
#define AT32_DEBUG_TMR2_STOP()             DEBUG->CTRL |= DEBUG_CTRL_TMR2_PAUSE
#define AT32_DEBUG_TMR3_STOP()             DEBUG->CTRL |= DEBUG_CTRL_TMR3_PAUSE
#define AT32_DEBUG_TMR4_STOP()             DEBUG->CTRL |= DEBUG_CTRL_TMR4_PAUSE
#define AT32_DEBUG_TMR5_STOP()             DEBUG->CTRL |= DEBUG_CTRL_TMR5_PAUSE
#define AT32_DEBUG_TMR9_STOP()             DEBUG->CTRL |= DEBUG_CTRL_TMR9_PAUSE
#define AT32_DEBUG_TMR10_STOP()            DEBUG->CTRL |= DEBUG_CTRL_TMR10_PAUSE
#define AT32_DEBUG_TMR11_STOP()            DEBUG->CTRL |= DEBUG_CTRL_TMR11_PAUSE

/*===========================================================================*/
/* Common.                                                                   */
/*===========================================================================*/

/* FLASH attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS         1

#if defined(AT32F415xB) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTOR_SIZE             1024U
#elif defined(AT32F415xC)
#define AT32_FLASH_SECTOR_SIZE             2048U
#endif

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/*===========================================================================*/
/* AT32F415KB, AT32F415KC.                                                   */
/*===========================================================================*/

#if defined(AT32F415Kx) || defined(__DOXYGEN__)

/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE
#define AT32_ADC_SUPPORTS_PRESCALER        FALSE
#define AT32_ADC_SUPPORTS_OVERSAMPLING     FALSE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_ADC_ADC1_DMA_STREAM           AT32_DMA_STREAM_ID(1, 2)
#define AT32_ADC_ADC1_DMAMUX_CHANNEL       2
#else
#define AT32_ADC_ADC1_DMA_STREAM           AT32_DMA_STREAM_ID(1, 1)
#endif

/* CAN attributes.*/
#define AT32_HAS_CAN1                      TRUE
#define AT32_CAN_MAX_FILTERS               14

/* DMA attributes.*/
#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_ADVANCED_DMA                  TRUE
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE
#else
#define AT32_ADVANCED_DMA                  FALSE
#define AT32_DMA_SUPPORTS_DMAMUX           FALSE
#endif

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               23
#define AT32_EXINT_INTEN_MASK              0x00000000U

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOD                     TRUE

#if !defined(AT32_HAS_GPIOC) || defined(__DOXYGEN__)
#define AT32_HAS_GPIOC                     FALSE
#elif !defined(AT32_HAS_GPIOF)
#define AT32_HAS_GPIOF                     FALSE
#endif
#define AT32_HAS_GPIOE                     FALSE
#define AT32_HAS_GPIOG                     FALSE
#define AT32_HAS_GPIOH                     FALSE

/* I2C attributes.*/
#define AT32_HAS_I2C1                      TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 3)
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 4)
#define AT32_I2C_I2C1_RX_DMAMUX_CHANNEL    3
#define AT32_I2C_I2C1_TX_DMAMUX_CHANNEL    4
#else
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 7)
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 6)
#endif

#define AT32_HAS_I2C2                      TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 3)
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 4)
#define AT32_I2C_I2C2_RX_DMAMUX_CHANNEL    3
#define AT32_I2C_I2C2_TX_DMAMUX_CHANNEL    4
#else
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 5)
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 4)
#endif

#define AT32_HAS_I2C3                      FALSE

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                  FALSE

/* SDIO attributes.*/
#define AT32_HAS_SDIO                      TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_SDC_SDIO_DMA_STREAM           AT32_DMA_STREAM_ID(1, 5)
#define AT32_SDC_SDIO_DMAMUX_CHANNEL       5
#else
#define AT32_SDC_SDIO_DMA_STREAM           AT32_DMA_STREAM_ID(2, 4)
#endif

/* SPI attributes.*/
#define AT32_HAS_SPI1                      TRUE
#define AT32_SPI1_SUPPORTS_I2S             TRUE
#define AT32_SPI1_I2S_FULLDUPLEX           FALSE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 6)
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 7)
#define AT32_SPI_SPI1_RX_DMAMUX_CHANNEL    6
#define AT32_SPI_SPI1_TX_DMAMUX_CHANNEL    7
#else
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 2)
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 3)
#endif

#define AT32_HAS_SPI2                      TRUE
#define AT32_SPI2_SUPPORTS_I2S             TRUE
#define AT32_SPI2_I2S_FULLDUPLEX           FALSE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_SPI_SPI2_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 6)
#define AT32_SPI_SPI2_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 7)
#define AT32_SPI_SPI2_RX_DMAMUX_CHANNEL    6
#define AT32_SPI_SPI2_TX_DMAMUX_CHANNEL    7
#else
#define AT32_SPI_SPI2_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 4)
#define AT32_SPI_SPI2_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 5)
#endif

#define AT32_HAS_SPI3                      FALSE

/* TMR attributes.*/
#define AT32_TMR_MAX_CHANNELS              4

#define AT32_HAS_TMR1                      TRUE
#define AT32_TMR1_IS_32BITS                FALSE
#define AT32_TMR1_CHANNELS                 4

#define AT32_HAS_TMR2                      TRUE
#define AT32_TMR2_IS_32BITS                TRUE
#define AT32_TMR2_CHANNELS                 4

#define AT32_HAS_TMR3                      TRUE
#define AT32_TMR3_IS_32BITS                FALSE
#define AT32_TMR3_CHANNELS                 4

#define AT32_HAS_TMR4                      TRUE
#define AT32_TMR4_IS_32BITS                FALSE
#define AT32_TMR4_CHANNELS                 4

#define AT32_HAS_TMR5                      TRUE
#define AT32_TMR5_IS_32BITS                TRUE
#define AT32_TMR5_CHANNELS                 4

#define AT32_HAS_TMR9                      TRUE
#define AT32_TMR9_IS_32BITS                FALSE
#define AT32_TMR9_CHANNELS                 2

#define AT32_HAS_TMR10                     TRUE
#define AT32_TMR10_IS_32BITS               FALSE
#define AT32_TMR10_CHANNELS                1

#define AT32_HAS_TMR11                     TRUE
#define AT32_TMR11_IS_32BITS               FALSE
#define AT32_TMR11_CHANNELS                1

#define AT32_HAS_TMR6                      FALSE
#define AT32_HAS_TMR7                      FALSE
#define AT32_HAS_TMR13                     FALSE
#define AT32_HAS_TMR14                     FALSE

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_USART1_RX_DMAMUX_CHANNEL 1
#define AT32_UART_USART1_TX_DMAMUX_CHANNEL 2
#else
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 5)
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 4)
#endif

#define AT32_HAS_USART2                    TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_USART2_RX_DMAMUX_CHANNEL 1
#define AT32_UART_USART2_TX_DMAMUX_CHANNEL 2
#else
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 6)
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 7)
#endif

#define AT32_HAS_USART3                    FALSE
#define AT32_HAS_UART4                     FALSE
#define AT32_HAS_UART5                     FALSE
#define AT32_HAS_USART6                    FALSE
#define AT32_HAS_UART7                     FALSE
#define AT32_HAS_UART8                     FALSE

/* USB attributes.*/
#define AT32_OTG_STEPPING                  1

#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                3

#define AT32_HAS_OTG2                      FALSE

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE
#define AT32_WDT_IS_WINDOWED               FALSE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE

/* STM32 compatibility define. */
#if AT32_CRC_USE_CRC1 == TRUE 
#define STM32_CRC_USE_CRC1                 TRUE
#else
#define STM32_CRC_USE_CRC1                 FALSE
#endif

#endif /* defined(AT32F415K) */

/*===========================================================================*/
/* AT32F415CB, AT32F415CC.                                                   */
/*===========================================================================*/

#if defined(AT32F415Cx) || defined(__DOXYGEN__)

/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE
#define AT32_ADC_SUPPORTS_PRESCALER        FALSE
#define AT32_ADC_SUPPORTS_OVERSAMPLING     FALSE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_ADC_ADC1_DMA_STREAM           AT32_DMA_STREAM_ID(1, 2)
#define AT32_ADC_ADC1_DMAMUX_CHANNEL       2
#else
#define AT32_ADC_ADC1_DMA_STREAM           AT32_DMA_STREAM_ID(1, 1)
#endif

/* CAN attributes.*/
#define AT32_HAS_CAN1                      TRUE
#define AT32_CAN_MAX_FILTERS               14

/* DMA attributes.*/
#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_ADVANCED_DMA                  TRUE
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE
#else
#define AT32_ADVANCED_DMA                  FALSE
#define AT32_DMA_SUPPORTS_DMAMUX           FALSE
#endif

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               23
#define AT32_EXINT_INTEN_MASK              0x00000000U

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOC                     TRUE
#define AT32_HAS_GPIOD                     TRUE
#define AT32_HAS_GPIOF                     TRUE

#define AT32_HAS_GPIOE                     FALSE
#define AT32_HAS_GPIOG                     FALSE
#define AT32_HAS_GPIOH                     FALSE

/* I2C attributes.*/
#define AT32_HAS_I2C1                      TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 3)
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 4)
#define AT32_I2C_I2C1_RX_DMAMUX_CHANNEL    3
#define AT32_I2C_I2C1_TX_DMAMUX_CHANNEL    4
#else
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 7)
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 6)
#endif

#define AT32_HAS_I2C2                      TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 3)
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 4)
#define AT32_I2C_I2C2_RX_DMAMUX_CHANNEL    3
#define AT32_I2C_I2C2_TX_DMAMUX_CHANNEL    4
#else
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 5)
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 4)
#endif

#define AT32_HAS_I2C3                      FALSE

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                  FALSE

/* SDIO attributes.*/
#define AT32_HAS_SDIO                      TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_SDC_SDIO_DMA_STREAM           AT32_DMA_STREAM_ID(1, 5)
#define AT32_SDC_SDIO_DMAMUX_CHANNEL       5
#else
#define AT32_SDC_SDIO_DMA_STREAM           AT32_DMA_STREAM_ID(2, 4)
#endif

/* SPI attributes.*/
#define AT32_HAS_SPI1                      TRUE
#define AT32_SPI1_SUPPORTS_I2S             TRUE
#define AT32_SPI1_I2S_FULLDUPLEX           FALSE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 6)
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 7)
#define AT32_SPI_SPI1_RX_DMAMUX_CHANNEL    6
#define AT32_SPI_SPI1_TX_DMAMUX_CHANNEL    7
#else
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 2)
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 3)
#endif

#define AT32_HAS_SPI2                      TRUE
#define AT32_SPI2_SUPPORTS_I2S             TRUE
#define AT32_SPI2_I2S_FULLDUPLEX           FALSE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_SPI_SPI2_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 6)
#define AT32_SPI_SPI2_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 7)
#define AT32_SPI_SPI2_RX_DMAMUX_CHANNEL    6
#define AT32_SPI_SPI2_TX_DMAMUX_CHANNEL    7
#else
#define AT32_SPI_SPI2_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 4)
#define AT32_SPI_SPI2_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 5)
#endif

#define AT32_HAS_SPI3                      FALSE

/* TMR attributes.*/
#define AT32_TMR_MAX_CHANNELS              4

#define AT32_HAS_TMR1                      TRUE
#define AT32_TMR1_IS_32BITS                FALSE
#define AT32_TMR1_CHANNELS                 4

#define AT32_HAS_TMR2                      TRUE
#define AT32_TMR2_IS_32BITS                TRUE
#define AT32_TMR2_CHANNELS                 4

#define AT32_HAS_TMR3                      TRUE
#define AT32_TMR3_IS_32BITS                FALSE
#define AT32_TMR3_CHANNELS                 4

#define AT32_HAS_TMR4                      TRUE
#define AT32_TMR4_IS_32BITS                FALSE
#define AT32_TMR4_CHANNELS                 4

#define AT32_HAS_TMR5                      TRUE
#define AT32_TMR5_IS_32BITS                TRUE
#define AT32_TMR5_CHANNELS                 4

#define AT32_HAS_TMR9                      TRUE
#define AT32_TMR9_IS_32BITS                FALSE
#define AT32_TMR9_CHANNELS                 2

#define AT32_HAS_TMR10                     TRUE
#define AT32_TMR10_IS_32BITS               FALSE
#define AT32_TMR10_CHANNELS                1

#define AT32_HAS_TMR11                     TRUE
#define AT32_TMR11_IS_32BITS               FALSE
#define AT32_TMR11_CHANNELS                1

#define AT32_HAS_TMR6                      FALSE
#define AT32_HAS_TMR7                      FALSE
#define AT32_HAS_TMR13                     FALSE
#define AT32_HAS_TMR14                     FALSE

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_USART1_RX_DMAMUX_CHANNEL 1
#define AT32_UART_USART1_TX_DMAMUX_CHANNEL 2
#else
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 5)
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 4)
#endif

#define AT32_HAS_USART2                    TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_USART2_RX_DMAMUX_CHANNEL 1
#define AT32_UART_USART2_TX_DMAMUX_CHANNEL 2
#else
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 6)
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 7)
#endif

#define AT32_HAS_USART3                    TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_USART3_RX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_USART3_TX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_USART3_RX_DMAMUX_CHANNEL 1
#define AT32_UART_USART3_TX_DMAMUX_CHANNEL 2
#else
#define AT32_UART_USART3_RX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 3)
#define AT32_UART_USART3_TX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 2)
#endif

#define AT32_HAS_UART4                     FALSE
#define AT32_HAS_UART5                     FALSE
#define AT32_HAS_USART6                    FALSE
#define AT32_HAS_UART7                     FALSE
#define AT32_HAS_UART8                     FALSE

/* USB attributes.*/
#define AT32_OTG_STEPPING                  1

#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                3

#define AT32_HAS_OTG2                      FALSE

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE
#define AT32_WDT_IS_WINDOWED               FALSE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE

/* STM32 compatibility define. */
#if AT32_CRC_USE_CRC1 == TRUE 
#define STM32_CRC_USE_CRC1                 TRUE
#else
#define STM32_CRC_USE_CRC1                 FALSE
#endif

#endif /* defined(AT32F415C) */

/*===========================================================================*/
/* AT32F415RB, AT32F415RC.                                                   */
/*===========================================================================*/

#if defined(AT32F415Rx) || defined(__DOXYGEN__)

/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE
#define AT32_ADC_SUPPORTS_PRESCALER        FALSE
#define AT32_ADC_SUPPORTS_OVERSAMPLING     FALSE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_ADC_ADC1_DMA_STREAM           AT32_DMA_STREAM_ID(1, 2)
#define AT32_ADC_ADC1_DMAMUX_CHANNEL       2
#else
#define AT32_ADC_ADC1_DMA_STREAM           AT32_DMA_STREAM_ID(1, 1)
#endif

/* CAN attributes.*/
#define AT32_HAS_CAN1                      TRUE
#define AT32_CAN_MAX_FILTERS               14

/* DMA attributes.*/
#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_ADVANCED_DMA                  TRUE
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE
#else
#define AT32_ADVANCED_DMA                  FALSE
#define AT32_DMA_SUPPORTS_DMAMUX           FALSE
#endif

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               23
#define AT32_EXINT_INTEN_MASK              0x00000000U

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOC                     TRUE
#define AT32_HAS_GPIOD                     TRUE
#define AT32_HAS_GPIOF                     TRUE

#define AT32_HAS_GPIOE                     FALSE
#define AT32_HAS_GPIOG                     FALSE
#define AT32_HAS_GPIOH                     FALSE

/* I2C attributes.*/
#define AT32_HAS_I2C1                      TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 3)
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 4)
#define AT32_I2C_I2C1_RX_DMAMUX_CHANNEL    3
#define AT32_I2C_I2C1_TX_DMAMUX_CHANNEL    4
#else
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 7)
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 6)
#endif

#define AT32_HAS_I2C2                      TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 3)
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 4)
#define AT32_I2C_I2C2_RX_DMAMUX_CHANNEL    3
#define AT32_I2C_I2C2_TX_DMAMUX_CHANNEL    4
#else
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 5)
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 4)
#endif

#define AT32_HAS_I2C3                      FALSE

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                  FALSE

/* SDIO attributes.*/
#define AT32_HAS_SDIO                      TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_SDC_SDIO_DMA_STREAM           AT32_DMA_STREAM_ID(1, 5)
#define AT32_SDC_SDIO_DMAMUX_CHANNEL       5
#else
#define AT32_SDC_SDIO_DMA_STREAM           AT32_DMA_STREAM_ID(2, 4)
#endif

/* SPI attributes.*/
#define AT32_HAS_SPI1                      TRUE
#define AT32_SPI1_SUPPORTS_I2S             TRUE
#define AT32_SPI1_I2S_FULLDUPLEX           FALSE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 6)
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 7)
#define AT32_SPI_SPI1_RX_DMAMUX_CHANNEL    6
#define AT32_SPI_SPI1_TX_DMAMUX_CHANNEL    7
#else
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 2)
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 3)
#endif

#define AT32_HAS_SPI2                      TRUE
#define AT32_SPI2_SUPPORTS_I2S             TRUE
#define AT32_SPI2_I2S_FULLDUPLEX           FALSE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_SPI_SPI2_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 6)
#define AT32_SPI_SPI2_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 7)
#define AT32_SPI_SPI2_RX_DMAMUX_CHANNEL    6
#define AT32_SPI_SPI2_TX_DMAMUX_CHANNEL    7
#else
#define AT32_SPI_SPI2_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 4)
#define AT32_SPI_SPI2_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 5)
#endif

#define AT32_HAS_SPI3                      FALSE

/* TMR attributes.*/
#define AT32_TMR_MAX_CHANNELS              4

#define AT32_HAS_TMR1                      TRUE
#define AT32_TMR1_IS_32BITS                FALSE
#define AT32_TMR1_CHANNELS                 4

#define AT32_HAS_TMR2                      TRUE
#define AT32_TMR2_IS_32BITS                TRUE
#define AT32_TMR2_CHANNELS                 4

#define AT32_HAS_TMR3                      TRUE
#define AT32_TMR3_IS_32BITS                FALSE
#define AT32_TMR3_CHANNELS                 4

#define AT32_HAS_TMR4                      TRUE
#define AT32_TMR4_IS_32BITS                FALSE
#define AT32_TMR4_CHANNELS                 4

#define AT32_HAS_TMR5                      TRUE
#define AT32_TMR5_IS_32BITS                TRUE
#define AT32_TMR5_CHANNELS                 4

#define AT32_HAS_TMR9                      TRUE
#define AT32_TMR9_IS_32BITS                FALSE
#define AT32_TMR9_CHANNELS                 2

#define AT32_HAS_TMR10                     TRUE
#define AT32_TMR10_IS_32BITS               FALSE
#define AT32_TMR10_CHANNELS                1

#define AT32_HAS_TMR11                     TRUE
#define AT32_TMR11_IS_32BITS               FALSE
#define AT32_TMR11_CHANNELS                1

#define AT32_HAS_TMR6                      FALSE
#define AT32_HAS_TMR7                      FALSE
#define AT32_HAS_TMR13                     FALSE
#define AT32_HAS_TMR14                     FALSE

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_USART1_RX_DMAMUX_CHANNEL 1
#define AT32_UART_USART1_TX_DMAMUX_CHANNEL 2
#else
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 5)
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 4)
#endif

#define AT32_HAS_USART2                    TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_USART2_RX_DMAMUX_CHANNEL 1
#define AT32_UART_USART2_TX_DMAMUX_CHANNEL 2
#else
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 6)
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 7)
#endif

#define AT32_HAS_USART3                    TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_USART3_RX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_USART3_TX_DMA_STREAM     AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_USART3_RX_DMAMUX_CHANNEL 1
#define AT32_UART_USART3_TX_DMAMUX_CHANNEL 2
#else
#define AT32_UART_USART3_RX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 3)
#define AT32_UART_USART3_TX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 2)
#endif

#define AT32_HAS_UART4                     TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_UART4_RX_DMAMUX_CHANNEL  1
#define AT32_UART_UART4_TX_DMAMUX_CHANNEL  2
#else
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 3)
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 5)
#endif

#define AT32_HAS_UART5                     TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_UART5_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_UART5_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_UART5_RX_DMAMUX_CHANNEL  1
#define AT32_UART_UART5_TX_DMAMUX_CHANNEL  2
#endif

#define AT32_HAS_USART6                    FALSE
#define AT32_HAS_UART7                     FALSE
#define AT32_HAS_UART8                     FALSE

/* USB attributes.*/
#define AT32_OTG_STEPPING                  1

#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                3

#define AT32_HAS_OTG2                      FALSE

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE
#define AT32_WDT_IS_WINDOWED               FALSE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE

/* STM32 compatibility define. */
#if AT32_CRC_USE_CRC1 == TRUE 
#define STM32_CRC_USE_CRC1                 TRUE
#else
#define STM32_CRC_USE_CRC1                 FALSE
#endif

#endif /* defined(AT32F415R) */

#endif /* AT32_REGISTRY_H */

/** @} */
