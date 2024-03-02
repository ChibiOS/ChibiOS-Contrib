/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian

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

#if defined(AT32F415KB)
#define AT32F415K_MD

#elif defined(AT32F415KC)
#define AT32F415K_HD

#elif defined(AT32F415CB)
#define AT32F415C_MD

#elif defined(AT32F415CC)
#define AT32F415C_HD

#elif defined(AT32F415RB)
#define AT32F415R_MD

#elif defined(AT32F415RC)
#define AT32F415R_HD

#else
#error "unsupported or unrecognized AT32F415 member"
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

#if defined(AT32F415K_MD) || defined(__DOXYGEN__)
/**
 * @name    AT32F415K MD capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE

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
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE
#else
#define AT32_DMA_SUPPORTS_DMAMUX           FALSE
#endif

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               23
#define AT32_EXINT_INTEN_MASK              0x00000000U

/* FLASH attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS         1
#define AT32_FLASH_SECTOR_SIZE             1024U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOC                     FALSE
#define AT32_HAS_GPIOD                     TRUE
#define AT32_HAS_GPIOF                     FALSE

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

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* SDIO attributes.*/
#define AT32_HAS_SDIO1                     TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_SDC_SDIO1_DMA_STREAM          AT32_DMA_STREAM_ID(1, 5)
#define AT32_SDC_SDIO1_DMAMUX_CHANNEL      5
#else
#define AT32_SDC_SDIO1_DMA_STREAM          AT32_DMA_STREAM_ID(2, 4)
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

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_UART4_RX_DMAMUX_CHANNEL  1
#define AT32_UART_UART4_TX_DMAMUX_CHANNEL  2
#else
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 3)
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 5)
#endif

#define AT32_HAS_UART5                     FALSE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_UART5_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_UART5_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_UART5_RX_DMAMUX_CHANNEL  1
#define AT32_UART_UART5_TX_DMAMUX_CHANNEL  2
#endif

/* USB attributes.*/
#define AT32_OTG_STEPPING                  1
#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                3

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE
/** @} */
#endif /* defined(AT32F415K_MD) */

#if defined(AT32F415K_HD) || defined(__DOXYGEN__)
/**
 * @name    AT32F415K HD capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE

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
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE
#else
#define AT32_DMA_SUPPORTS_DMAMUX           FALSE
#endif

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               23
#define AT32_EXINT_INTEN_MASK              0x00000000U

/* FLASH attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS         1
#define AT32_FLASH_SECTOR_SIZE             2048U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOC                     FALSE
#define AT32_HAS_GPIOD                     TRUE
#define AT32_HAS_GPIOF                     FALSE

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

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* SDIO attributes.*/
#define AT32_HAS_SDIO1                     TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_SDC_SDIO1_DMA_STREAM          AT32_DMA_STREAM_ID(1, 5)
#define AT32_SDC_SDIO1_DMAMUX_CHANNEL      5
#else
#define AT32_SDC_SDIO1_DMA_STREAM          AT32_DMA_STREAM_ID(2, 4)
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

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_UART4_RX_DMAMUX_CHANNEL  1
#define AT32_UART_UART4_TX_DMAMUX_CHANNEL  2
#else
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 3)
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 5)
#endif

#define AT32_HAS_UART5                     FALSE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_UART5_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_UART5_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_UART5_RX_DMAMUX_CHANNEL  1
#define AT32_UART_UART5_TX_DMAMUX_CHANNEL  2
#endif

/* USB attributes.*/
#define AT32_OTG_STEPPING                  1
#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                3

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE
/** @} */
#endif /* defined(AT32F415K_HD) */

#if defined(AT32F415C_MD) || defined(__DOXYGEN__)
/**
 * @name    AT32F415C MD capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE

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
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE
#else
#define AT32_DMA_SUPPORTS_DMAMUX           FALSE
#endif

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               23
#define AT32_EXINT_INTEN_MASK              0x00000000U

/* FLASH attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS         1
#define AT32_FLASH_SECTOR_SIZE             1024U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOC                     TRUE
#define AT32_HAS_GPIOD                     TRUE
#define AT32_HAS_GPIOF                     TRUE

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

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* SDIO attributes.*/
#define AT32_HAS_SDIO1                     TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_SDC_SDIO1_DMA_STREAM          AT32_DMA_STREAM_ID(1, 5)
#define AT32_SDC_SDIO1_DMAMUX_CHANNEL      5
#else
#define AT32_SDC_SDIO1_DMA_STREAM          AT32_DMA_STREAM_ID(2, 4)
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

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_UART4_RX_DMAMUX_CHANNEL  1
#define AT32_UART_UART4_TX_DMAMUX_CHANNEL  2
#else
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 3)
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 5)
#endif

#define AT32_HAS_UART5                     FALSE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_UART5_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_UART5_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_UART5_RX_DMAMUX_CHANNEL  1
#define AT32_UART_UART5_TX_DMAMUX_CHANNEL  2
#endif

/* USB attributes.*/
#define AT32_OTG_STEPPING                  1
#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                3

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE
/** @} */
#endif /* defined(AT32F415C_MD) */

#if defined(AT32F415C_HD) || defined(__DOXYGEN__)
/**
 * @name    AT32F415C HD capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE

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
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE
#else
#define AT32_DMA_SUPPORTS_DMAMUX           FALSE
#endif

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               23
#define AT32_EXINT_INTEN_MASK              0x00000000U

/* FLASH attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS         1
#define AT32_FLASH_SECTOR_SIZE             2048U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOC                     TRUE
#define AT32_HAS_GPIOD                     TRUE
#define AT32_HAS_GPIOF                     TRUE

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

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* SDIO attributes.*/
#define AT32_HAS_SDIO1                     TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_SDC_SDIO1_DMA_STREAM          AT32_DMA_STREAM_ID(1, 5)
#define AT32_SDC_SDIO1_DMAMUX_CHANNEL      5
#else
#define AT32_SDC_SDIO1_DMA_STREAM          AT32_DMA_STREAM_ID(2, 4)
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

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_UART4_RX_DMAMUX_CHANNEL  1
#define AT32_UART_UART4_TX_DMAMUX_CHANNEL  2
#else
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 3)
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 5)
#endif

#define AT32_HAS_UART5                     FALSE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_UART_UART5_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 1)
#define AT32_UART_UART5_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 2)
#define AT32_UART_UART5_RX_DMAMUX_CHANNEL  1
#define AT32_UART_UART5_TX_DMAMUX_CHANNEL  2
#endif

/* USB attributes.*/
#define AT32_OTG_STEPPING                  1
#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                3

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE
/** @} */
#endif /* defined(AT32F415C_HD) */

#if defined(AT32F415R_MD) || defined(__DOXYGEN__)
/**
 * @name    AT32F415R MD capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE

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
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE
#else
#define AT32_DMA_SUPPORTS_DMAMUX           FALSE
#endif

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               23
#define AT32_EXINT_INTEN_MASK              0x00000000U

/* FLASH attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS         1
#define AT32_FLASH_SECTOR_SIZE             1024U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOC                     TRUE
#define AT32_HAS_GPIOD                     TRUE
#define AT32_HAS_GPIOF                     TRUE

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

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* SDIO attributes.*/
#define AT32_HAS_SDIO1                     TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_SDC_SDIO1_DMA_STREAM          AT32_DMA_STREAM_ID(1, 5)
#define AT32_SDC_SDIO1_DMAMUX_CHANNEL      5
#else
#define AT32_SDC_SDIO1_DMA_STREAM          AT32_DMA_STREAM_ID(2, 4)
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

/* USB attributes.*/
#define AT32_OTG_STEPPING                  1
#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                3

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE
/** @} */
#endif /* defined(AT32F415R_MD) */

#if defined(AT32F415R_HD) || defined(__DOXYGEN__)
/**
 * @name    AT32F415R HD capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE

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
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE
#else
#define AT32_DMA_SUPPORTS_DMAMUX           FALSE
#endif

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               23
#define AT32_EXINT_INTEN_MASK              0x00000000U

/* FLASH attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS         1
#define AT32_FLASH_SECTOR_SIZE             2048U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOC                     TRUE
#define AT32_HAS_GPIOD                     TRUE
#define AT32_HAS_GPIOF                     TRUE

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

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* SDIO attributes.*/
#define AT32_HAS_SDIO1                     TRUE

#if (AT32_DMA_USE_DMAMUX == TRUE) || defined(__DOXYGEN__)
#define AT32_SDC_SDIO1_DMA_STREAM          AT32_DMA_STREAM_ID(1, 5)
#define AT32_SDC_SDIO1_DMAMUX_CHANNEL      5
#else
#define AT32_SDC_SDIO1_DMA_STREAM          AT32_DMA_STREAM_ID(2, 4)
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

/* USB attributes.*/
#define AT32_OTG_STEPPING                  1
#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                3

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE
/** @} */
#endif /* defined(AT32F415R_HD) */

#endif /* AT32_REGISTRY_H */

/** @} */
