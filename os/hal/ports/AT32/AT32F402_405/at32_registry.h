/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2026 HorrorTroll
    ChibiOS - Copyright (C) 2023..2026 Zhaqian
    ChibiOS - Copyright (C) 2024..2026 Maxjta

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
 * @file    AT32F402_405/at32_registry.h
 * @brief   AT32F402_405 capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef AT32_REGISTRY_H
#define AT32_REGISTRY_H

/* Define by package size */
#if defined(AT32F402KB) || defined(AT32F402KC) ||                          \
    defined(AT32F405KB) || defined(AT32F405KC)
#define AT32F402_405Kx

#elif defined(AT32F402CB) || defined(AT32F402CC) ||                        \
      defined(AT32F405CB) || defined(AT32F405CC)
#define AT32F402_405Cx

#elif defined(AT32F402RB) || defined(AT32F402RC) ||                        \
      defined(AT32F405RB) || defined(AT32F405RC)
#define AT32F402_405Rx

#else
#error "unsupported or unrecognized AT32F402 or AT32F405 package size"
#endif

/* Define by flash size */
#if defined(AT32F402KB) || defined(AT32F402CB) || defined(AT32F402RB) ||   \
    defined(AT32F405KB) || defined(AT32F405CB) || defined(AT32F405RB)
#define AT32F402_405xB

#elif defined(AT32F402KC) || defined(AT32F402CC) || defined(AT32F402RC) || \
      defined(AT32F405KC) || defined(AT32F405CC) || defined(AT32F405RC)
#define AT32F402_405xC

#else
#error "unsupported or unrecognized AT32F402 or AT32F405 flash size"
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    AT32F402_405 capabilities
 * @{
 */

/* DEBUG helpers.*/
#define AT32_DEBUG_TMR1_STOP()             DEBUG->APB2_PAUSE |= DEBUG_APB2_PAUSE_TMR1_PAUSE
#define AT32_DEBUG_TMR2_STOP()             DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR2_PAUSE
#define AT32_DEBUG_TMR3_STOP()             DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR3_PAUSE
#define AT32_DEBUG_TMR4_STOP()             DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR4_PAUSE
#define AT32_DEBUG_TMR6_STOP()             DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR6_PAUSE
#define AT32_DEBUG_TMR7_STOP()             DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR7_PAUSE
#define AT32_DEBUG_TMR9_STOP()             DEBUG->APB2_PAUSE |= DEBUG_APB2_PAUSE_TMR9_PAUSE
#define AT32_DEBUG_TMR10_STOP()            DEBUG->APB2_PAUSE |= DEBUG_APB2_PAUSE_TMR10_PAUSE
#define AT32_DEBUG_TMR11_STOP()            DEBUG->APB2_PAUSE |= DEBUG_APB2_PAUSE_TMR11_PAUSE
#define AT32_DEBUG_TMR13_STOP()            DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR13_PAUSE
#define AT32_DEBUG_TMR14_STOP()            DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR14_PAUSE

/*===========================================================================*/
/* Common.                                                                   */
/*===========================================================================*/

/* FLASH attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS         1

#if defined(AT32F402_405xB) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTOR_SIZE             1024U
#elif defined(AT32F402_405xC)
#define AT32_FLASH_SECTOR_SIZE             2048U
#endif

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#if defined(AT32_HAS_GPIOD)
#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN |           \
                                            CRM_AHBEN1_GPIOBEN |           \
                                            CRM_AHBEN1_GPIOCEN |           \
                                            CRM_AHBEN1_GPIODEN |           \
                                            CRM_AHBEN1_GPIOFEN)
#elif defined(AT32_HAS_GPIOC)
#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN |           \
                                            CRM_AHBEN1_GPIOBEN |           \
                                            CRM_AHBEN1_GPIOCEN |           \
                                            CRM_AHBEN1_GPIOFEN)
#else
#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN |           \
                                            CRM_AHBEN1_GPIOBEN |           \
                                            CRM_AHBEN1_GPIOFEN)
#endif

/*===========================================================================*/
/* AT32F402KB, AT32F402KC, AT32F405KB, AT32F405KC.                           */
/*===========================================================================*/

#if defined(AT32F402_405Kx) || defined(__DOXYGEN__)

/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE
#define AT32_ADC_SUPPORTS_PRESCALER        TRUE
#define AT32_ADC_SUPPORTS_OVERSAMPLING     TRUE
#define AT32_ADC_ADC1_DMA_STREAM           AT32_DMA_STREAM_ID_ANY

/* CAN attributes.*/
#define AT32_HAS_CAN1                      TRUE
#define AT32_CAN_MAX_FILTERS               14

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                  TRUE
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#if defined(AT32F402KB) || defined(AT32F402KC) || defined(__DOXYGEN__)
#define AT32_EXINT_NUM_LINES               21
#elif defined(AT32F405KB) || defined(AT32F405KC)
#define AT32_EXINT_NUM_LINES               22
#endif

#define AT32_EXINT_INTEN_MASK              0x00000000U

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOF                     TRUE

#if !defined(AT32_HAS_GPIOC) || defined(__DOXYGEN__)
#define AT32_HAS_GPIOC                     FALSE
#elif !defined(AT32_HAS_GPIOD)
#define AT32_HAS_GPIOD                     FALSE
#endif
#define AT32_HAS_GPIOE                     FALSE
#define AT32_HAS_GPIOG                     FALSE
#define AT32_HAS_GPIOH                     FALSE

/* I2C attributes.*/
#define AT32_HAS_I2C1                      TRUE
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C2                      TRUE
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C3                      TRUE
#define AT32_I2C_I2C3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                  TRUE
#define AT32_WSPI_QUADSPI1_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

/* SDIO attributes.*/
#define AT32_HAS_SDIO                      FALSE

/* SPI attributes.*/
#define AT32_HAS_SPI1                      TRUE
#define AT32_SPI1_SUPPORTS_I2S             TRUE
#define AT32_SPI1_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI3                      TRUE
#define AT32_SPI3_SUPPORTS_I2S             TRUE
#define AT32_SPI3_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI2                      FALSE

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

#define AT32_HAS_TMR6                      TRUE
#define AT32_TMR6_IS_32BITS                FALSE
#define AT32_TMR6_CHANNELS                 0

#define AT32_HAS_TMR7                      TRUE
#define AT32_TMR7_IS_32BITS                FALSE
#define AT32_TMR7_CHANNELS                 0

#define AT32_HAS_TMR9                      TRUE
#define AT32_TMR9_IS_32BITS                FALSE
#define AT32_TMR9_CHANNELS                 2

#define AT32_HAS_TMR10                     TRUE
#define AT32_TMR10_IS_32BITS               FALSE
#define AT32_TMR10_CHANNELS                1

#define AT32_HAS_TMR11                     TRUE
#define AT32_TMR11_IS_32BITS               FALSE
#define AT32_TMR11_CHANNELS                1

#define AT32_HAS_TMR13                     TRUE
#define AT32_TMR13_IS_32BITS               FALSE
#define AT32_TMR13_CHANNELS                1

#define AT32_HAS_TMR14                     TRUE
#define AT32_TMR14_IS_32BITS               FALSE
#define AT32_TMR14_CHANNELS                1

#define AT32_HAS_TMR5                      FALSE

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART2                    TRUE
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART3                    TRUE
#define AT32_UART_USART3_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART3_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART4                     TRUE
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART5                     TRUE
#define AT32_UART_UART5_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART5_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART6                    TRUE
#define AT32_UART_USART6_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART6_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART7                     TRUE
#define AT32_UART_UART7_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART7_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART8                     FALSE

/* USB attributes.*/
#define AT32_OTG_STEPPING                  2

#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                7

#if defined(AT32F402KB) || defined(AT32F402KC) || defined(__DOXYGEN__)
#define AT32_HAS_OTG2                      FALSE
#elif defined(AT32F405KB) || defined(AT32F405KC)
#define AT32_HAS_OTG2                      TRUE
#define AT32_OTG2_ENDPOINTS                7
#endif

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE
#define AT32_WDT_IS_WINDOWED               TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE

/* STM32 compatibility define. */
#if AT32_CRC_USE_CRC1 == TRUE 
#define STM32_CRC_USE_CRC1                 TRUE
#else
#define STM32_CRC_USE_CRC1                 FALSE
#endif

#endif /* defined(AT32F402_405K) */

/*===========================================================================*/
/* AT32F402CB, AT32F402CC, AT32F405CB, AT32F405CC.                           */
/*===========================================================================*/

#if defined(AT32F402_405Cx) || defined(__DOXYGEN__)

/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE
#define AT32_ADC_SUPPORTS_PRESCALER        TRUE
#define AT32_ADC_SUPPORTS_OVERSAMPLING     TRUE
#define AT32_ADC_ADC1_DMA_STREAM           AT32_DMA_STREAM_ID_ANY

/* CAN attributes.*/
#define AT32_HAS_CAN1                      TRUE
#define AT32_CAN_MAX_FILTERS               14

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                  TRUE
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#if defined(AT32F402CB) || defined(AT32F402CC) || defined(__DOXYGEN__)
#define AT32_EXINT_NUM_LINES               21
#elif defined(AT32F405CB) || defined(AT32F405CC)
#define AT32_EXINT_NUM_LINES               22
#endif

#define AT32_EXINT_INTEN_MASK              0x00000000U

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOC                     TRUE
#define AT32_HAS_GPIOF                     TRUE

#if !defined(AT32_HAS_GPIOD) || defined(__DOXYGEN__)
#define AT32_HAS_GPIOD                     FALSE
#endif
#define AT32_HAS_GPIOE                     FALSE
#define AT32_HAS_GPIOG                     FALSE
#define AT32_HAS_GPIOH                     FALSE

/* I2C attributes.*/
#define AT32_HAS_I2C1                      TRUE
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C2                      TRUE
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C3                      TRUE
#define AT32_I2C_I2C3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                  TRUE
#define AT32_WSPI_QUADSPI1_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

/* SDIO attributes.*/
#define AT32_HAS_SDIO                      FALSE

/* SPI attributes.*/
#define AT32_HAS_SPI1                      TRUE
#define AT32_SPI1_SUPPORTS_I2S             TRUE
#define AT32_SPI1_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI2                      TRUE
#define AT32_SPI2_SUPPORTS_I2S             TRUE
#define AT32_SPI2_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI2_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI2_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI3                      TRUE
#define AT32_SPI3_SUPPORTS_I2S             TRUE
#define AT32_SPI3_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

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

#define AT32_HAS_TMR6                      TRUE
#define AT32_TMR6_IS_32BITS                FALSE
#define AT32_TMR6_CHANNELS                 0

#define AT32_HAS_TMR7                      TRUE
#define AT32_TMR7_IS_32BITS                FALSE
#define AT32_TMR7_CHANNELS                 0

#define AT32_HAS_TMR9                      TRUE
#define AT32_TMR9_IS_32BITS                FALSE
#define AT32_TMR9_CHANNELS                 2

#define AT32_HAS_TMR10                     TRUE
#define AT32_TMR10_IS_32BITS               FALSE
#define AT32_TMR10_CHANNELS                1

#define AT32_HAS_TMR11                     TRUE
#define AT32_TMR11_IS_32BITS               FALSE
#define AT32_TMR11_CHANNELS                1

#define AT32_HAS_TMR13                     TRUE
#define AT32_TMR13_IS_32BITS               FALSE
#define AT32_TMR13_CHANNELS                1

#define AT32_HAS_TMR14                     TRUE
#define AT32_TMR14_IS_32BITS               FALSE
#define AT32_TMR14_CHANNELS                1

#define AT32_HAS_TMR5                      FALSE

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART2                    TRUE
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART3                    TRUE
#define AT32_UART_USART3_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART3_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART4                     TRUE
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART5                     TRUE
#define AT32_UART_UART5_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART5_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART6                    TRUE
#define AT32_UART_USART6_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART6_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART7                     TRUE
#define AT32_UART_UART7_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART7_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART8                     FALSE

/* USB attributes.*/
#define AT32_OTG_STEPPING                  2

#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                7

#if defined(AT32F402CB) || defined(AT32F402CC) || defined(__DOXYGEN__)
#define AT32_HAS_OTG2                      FALSE
#elif defined(AT32F405CB) || defined(AT32F405CC)
#define AT32_HAS_OTG2                      TRUE
#define AT32_OTG2_ENDPOINTS                7
#endif

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE
#define AT32_WDT_IS_WINDOWED               TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE

/* STM32 compatibility define. */
#if AT32_CRC_USE_CRC1 == TRUE 
#define STM32_CRC_USE_CRC1                 TRUE
#else
#define STM32_CRC_USE_CRC1                 FALSE
#endif

#endif /* defined(AT32F402_405C) */

/*===========================================================================*/
/* AT32F402RB, AT32F402RC, AT32F405RB, AT32F405RC.                           */
/*===========================================================================*/

#if defined(AT32F402_405Rx) || defined(__DOXYGEN__)

/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE
#define AT32_ADC_SUPPORTS_PRESCALER        TRUE
#define AT32_ADC_SUPPORTS_OVERSAMPLING     TRUE
#define AT32_ADC_ADC1_DMA_STREAM           AT32_DMA_STREAM_ID_ANY

/* CAN attributes.*/
#define AT32_HAS_CAN1                      TRUE
#define AT32_CAN_MAX_FILTERS               14

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                  TRUE
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#if defined(AT32F402RB) || defined(AT32F402RC) || defined(__DOXYGEN__)
#define AT32_EXINT_NUM_LINES               21
#elif defined(AT32F405RB) || defined(AT32F405RC)
#define AT32_EXINT_NUM_LINES               22
#endif

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
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C2                      TRUE
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C3                      TRUE
#define AT32_I2C_I2C3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                  TRUE
#define AT32_WSPI_QUADSPI1_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

/* SDIO attributes.*/
#define AT32_HAS_SDIO                      FALSE

/* SPI attributes.*/
#define AT32_HAS_SPI1                      TRUE
#define AT32_SPI1_SUPPORTS_I2S             TRUE
#define AT32_SPI1_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI2                      TRUE
#define AT32_SPI2_SUPPORTS_I2S             TRUE
#define AT32_SPI2_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI2_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI2_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI3                      TRUE
#define AT32_SPI3_SUPPORTS_I2S             TRUE
#define AT32_SPI3_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

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

#define AT32_HAS_TMR6                      TRUE
#define AT32_TMR6_IS_32BITS                FALSE
#define AT32_TMR6_CHANNELS                 0

#define AT32_HAS_TMR7                      TRUE
#define AT32_TMR7_IS_32BITS                FALSE
#define AT32_TMR7_CHANNELS                 0

#define AT32_HAS_TMR9                      TRUE
#define AT32_TMR9_IS_32BITS                FALSE
#define AT32_TMR9_CHANNELS                 2

#define AT32_HAS_TMR10                     TRUE
#define AT32_TMR10_IS_32BITS               FALSE
#define AT32_TMR10_CHANNELS                1

#define AT32_HAS_TMR11                     TRUE
#define AT32_TMR11_IS_32BITS               FALSE
#define AT32_TMR11_CHANNELS                1

#define AT32_HAS_TMR13                     TRUE
#define AT32_TMR13_IS_32BITS               FALSE
#define AT32_TMR13_CHANNELS                1

#define AT32_HAS_TMR14                     TRUE
#define AT32_TMR14_IS_32BITS               FALSE
#define AT32_TMR14_CHANNELS                1

#define AT32_HAS_TMR5                      FALSE

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART2                    TRUE
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART3                    TRUE
#define AT32_UART_USART3_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART3_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART4                     TRUE
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART5                     TRUE
#define AT32_UART_UART5_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART5_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART6                    TRUE
#define AT32_UART_USART6_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART6_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART7                     TRUE
#define AT32_UART_UART7_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART7_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART8                     TRUE
#define AT32_UART_UART8_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART8_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

/* USB attributes.*/
#define AT32_OTG_STEPPING                  2

#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                7

#if defined(AT32F402RB) || defined(AT32F402RC) || defined(__DOXYGEN__)
#define AT32_HAS_OTG2                      FALSE
#elif defined(AT32F405RB) || defined(AT32F405RC)
#define AT32_HAS_OTG2                      TRUE
#define AT32_OTG2_ENDPOINTS                7
#endif

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE
#define AT32_WDT_IS_WINDOWED               TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE

/* STM32 compatibility define. */
#if AT32_CRC_USE_CRC1 == TRUE 
#define STM32_CRC_USE_CRC1                 TRUE
#else
#define STM32_CRC_USE_CRC1                 FALSE
#endif

#endif /* defined(AT32F402_405R) */

#endif /* AT32_REGISTRY_H */

/** @} */
