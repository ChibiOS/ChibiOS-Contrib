/*
    ChibiOS - Copyright (C) 2023..2024 Zhaqian
    ChibiOS - Copyright (C) 2024 Maxjta

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
 * @file    AT32F405xx/at32_registry.h
 * @brief   AT32F405xx capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef AT32_REGISTRY_H
#define AT32_REGISTRY_H

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/
#if defined(AT32F402Kx) || defined(AT32F405Kx) || defined(__DOXYGEN__)
/**
 * @name    AT32F402_5Kx capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                       TRUE
#define AT32_HAS_ADC2                       FALSE
#define AT32_HAS_ADC3                       FALSE

/* CAN attributes.*/
#define AT32_HAS_CAN1                       TRUE
#define AT32_HAS_CAN2                       FALSE
#define AT32_CAN_MAX_FILTERS                14

/* DAC attributes.*/
#define AT32_HAS_DAC1_CH1                   FALSE
#define AT32_HAS_DAC1_CH2                   FALSE

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                   TRUE
#define AT32_DMA_SUPPORTS_DMAMUX            TRUE
#define AT32_DMA_SUPPORTS_CSELR             FALSE

#define AT32_DMA1_NUM_CHANNELS              7
#define AT32_DMA2_NUM_CHANNELS              7
 
/* ETH attributes.*/
#define AT32_HAS_ETH                        FALSE

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES                22
#define AT32_EXINT_INTEN_MASK               0x00000000U

/* Flash attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS          1
#if defined(AT32F402xB) || defined(AT32F405xB)
#define AT32_FLASH_SECTOR_SIZE              1024U
#elif defined(AT32F402xC) || defined(AT32F405xC)
#define AT32_FLASH_SECTOR_SIZE              2048U
#endif
#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK         128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                      TRUE
#define AT32_HAS_GPIOB                      TRUE
#define AT32_HAS_GPIOC                      FALSE
#define AT32_HAS_GPIOD                      FALSE
#define AT32_HAS_GPIOE                      FALSE
#define AT32_HAS_GPIOF                      TRUE
#define AT32_HAS_GPIOG                      FALSE
#define AT32_HAS_GPIOH                      FALSE
#define AT32_HAS_GPIOI                      FALSE
#define AT32_HAS_GPIOJ                      FALSE
#define AT32_HAS_GPIOK                      FALSE

#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN | \
                                            CRM_AHBEN1_GPIOBEN | \
                                            CRM_AHBEN1_GPIOFEN)

/* I2C attributes.*/
#define AT32_HAS_I2C1                       TRUE
#define AT32_HAS_I2C2                       TRUE
#define AT32_HAS_I2C3                       TRUE

/* RTC attributes.*/
#define AT32_HAS_ERTC                       TRUE
#define AT32_ERTC_HAS_SUBSECONDS            TRUE
#define AT32_ERTC_IS_CALENDAR               TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS      TRUE
#define AT32_ERTC_NUM_ALARMS                2
#define AT32_ERTC_STORAGE_SIZE              80

/* SDIO attributes.*/
#define AT32_HAS_SDIO                       FALSE

/* SPI attributes.*/
#define AT32_HAS_SPI1                       TRUE
#define AT32_SPI1_SUPPORTS_I2S              TRUE
#define AT32_SPI1_I2S_FULLDUPLEX            FALSE

#define AT32_HAS_SPI2                       FALSE

#define AT32_HAS_SPI3                       TRUE
#define AT32_SPI3_SUPPORTS_I2S              TRUE
#define AT32_SPI3_I2S_FULLDUPLEX            FALSE

/* TMR attributes.*/
#define AT32_TMR_MAX_CHANNELS               4

#define AT32_HAS_TMR1                       TRUE
#define AT32_TMR1_IS_32BITS                 FALSE
#define AT32_TMR1_CHANNELS                  4

#define AT32_HAS_TMR2                       TRUE
#define AT32_TMR2_IS_32BITS                 TRUE
#define AT32_TMR2_CHANNELS                  4

#define AT32_HAS_TMR3                       TRUE
#define AT32_TMR3_IS_32BITS                 FALSE
#define AT32_TMR3_CHANNELS                  4

#define AT32_HAS_TMR4                       TRUE
#define AT32_TMR4_IS_32BITS                 FALSE
#define AT32_TMR4_CHANNELS                  4

#define AT32_HAS_TMR5                       FALSE

#define AT32_HAS_TMR6                       TRUE
#define AT32_TMR6_IS_32BITS                 FALSE
#define AT32_TMR6_CHANNELS                  0

#define AT32_HAS_TMR7                       TRUE
#define AT32_TMR7_IS_32BITS                 FALSE
#define AT32_TMR7_CHANNELS                  0

#define AT32_HAS_TMR8                       FALSE

#define AT32_HAS_TMR9                       TRUE
#define AT32_TMR9_IS_32BITS                 FALSE
#define AT32_TMR9_CHANNELS                  2

#define AT32_HAS_TMR10                      TRUE
#define AT32_TMR10_IS_32BITS                FALSE
#define AT32_TMR10_CHANNELS                 1

#define AT32_HAS_TMR11                      TRUE
#define AT32_TMR11_IS_32BITS                FALSE
#define AT32_TMR11_CHANNELS                 1

#define AT32_HAS_TMR12                      FALSE

#define AT32_HAS_TMR13                      TRUE
#define AT32_TMR13_IS_32BITS                FALSE
#define AT32_TMR13_CHANNELS                 1

#define AT32_HAS_TMR14                      TRUE
#define AT32_TMR14_IS_32BITS                FALSE
#define AT32_TMR14_CHANNELS                 1

/* USART attributes.*/
#define AT32_HAS_USART1                     TRUE
#define AT32_HAS_USART2                     TRUE
#define AT32_HAS_USART3                     TRUE
#define AT32_HAS_UART4                      TRUE
#define AT32_HAS_UART5                      TRUE
#define AT32_HAS_USART6                     TRUE
#define AT32_HAS_UART7                      TRUE
#define AT32_HAS_UART8                      FALSE

/* USB attributes.*/
#define AT32_OTG_STEPPING                   2
#define AT32_HAS_OTG1                       TRUE
#define AT32_OTG1_ENDPOINTS                 8

#if defined(AT32F405xx)
#define AT32_HAS_OTG2                       TRUE
#define AT32_OTG2_ENDPOINTS                 8
#define AT32_OTG2_SUPPORTS_HS               TRUE
#else
#define AT32_HAS_OTG2                       FALSE
#endif

#define AT32_HAS_USB                        FALSE

/* IWDG attributes.*/
#define AT32_HAS_IWDG                       TRUE
#define AT32_IWDG_IS_WINDOWED               TRUE

/* FSMC attributes.*/
#define AT32_HAS_FSMC                       FALSE

/* CRC attributes.*/
#define AT32_HAS_CRC                        TRUE
#define AT32_CRC_PROGRAMMABLE               FALSE

#endif /* defined(AT32F402Kx) || defined(AT32F405Kx) */

#if defined(AT32F402Cx) || defined(AT32F405Cx)
/**
 * @name    AT32F402_5Cx capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                       TRUE
#define AT32_HAS_ADC2                       FALSE
#define AT32_HAS_ADC3                       FALSE

/* CAN attributes.*/
#define AT32_HAS_CAN1                       TRUE
#define AT32_HAS_CAN2                       FALSE
#define AT32_CAN_MAX_FILTERS                14

/* DAC attributes.*/
#define AT32_HAS_DAC1_CH1                   FALSE
#define AT32_HAS_DAC1_CH2                   FALSE

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                   TRUE
#define AT32_DMA_SUPPORTS_DMAMUX            TRUE
#define AT32_DMA_SUPPORTS_CSELR             FALSE

#define AT32_DMA1_NUM_CHANNELS              7
#define AT32_DMA2_NUM_CHANNELS              7

/* ETH attributes.*/
#define AT32_HAS_ETH                        FALSE

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES                22
#define AT32_EXINT_INTEN_MASK               0x00000000U

/* Flash attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS          1
#if defined(AT32F402xB) || defined(AT32F405xB)
#define AT32_FLASH_SECTOR_SIZE              1024U
#elif defined(AT32F402xC) || defined(AT32F405xC)
#define AT32_FLASH_SECTOR_SIZE              2048U
#endif
#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK         128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                      TRUE
#define AT32_HAS_GPIOB                      TRUE
#define AT32_HAS_GPIOC                      TRUE
#define AT32_HAS_GPIOD                      FALSE
#define AT32_HAS_GPIOE                      FALSE
#define AT32_HAS_GPIOF                      TRUE
#define AT32_HAS_GPIOG                      FALSE
#define AT32_HAS_GPIOH                      FALSE
#define AT32_HAS_GPIOI                      FALSE
#define AT32_HAS_GPIOJ                      FALSE
#define AT32_HAS_GPIOK                      FALSE

#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN | \
                                            CRM_AHBEN1_GPIOBEN | \
                                            CRM_AHBEN1_GPIOCEN | \
                                            CRM_AHBEN1_GPIOFEN)

/* I2C attributes.*/
#define AT32_HAS_I2C1                       TRUE
#define AT32_HAS_I2C2                       TRUE
#define AT32_HAS_I2C3                       TRUE

/* RTC attributes.*/
#define AT32_HAS_ERTC                       TRUE
#define AT32_ERTC_HAS_SUBSECONDS            TRUE
#define AT32_ERTC_IS_CALENDAR               TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS      TRUE
#define AT32_ERTC_NUM_ALARMS                2
#define AT32_ERTC_STORAGE_SIZE              80

/* SDIO attributes.*/
#define AT32_HAS_SDIO                       FALSE

/* SPI attributes.*/
#define AT32_HAS_SPI1                       TRUE
#define AT32_SPI1_SUPPORTS_I2S              TRUE
#define AT32_SPI1_I2S_FULLDUPLEX            FALSE

#define AT32_HAS_SPI2                       TRUE
#define AT32_SPI2_SUPPORTS_I2S              TRUE
#define AT32_SPI2_I2S_FULLDUPLEX            FALSE

#define AT32_HAS_SPI3                       TRUE
#define AT32_SPI3_SUPPORTS_I2S              TRUE
#define AT32_SPI3_I2S_FULLDUPLEX            FALSE

/* TMR attributes.*/
#define AT32_TMR_MAX_CHANNELS               4

#define AT32_HAS_TMR1                       TRUE
#define AT32_TMR1_IS_32BITS                 FALSE
#define AT32_TMR1_CHANNELS                  4

#define AT32_HAS_TMR2                       TRUE
#define AT32_TMR2_IS_32BITS                 TRUE
#define AT32_TMR2_CHANNELS                  4

#define AT32_HAS_TMR3                       TRUE
#define AT32_TMR3_IS_32BITS                 FALSE
#define AT32_TMR3_CHANNELS                  4

#define AT32_HAS_TMR4                       TRUE
#define AT32_TMR4_IS_32BITS                 FALSE
#define AT32_TMR4_CHANNELS                  4

#define AT32_HAS_TMR5                       FALSE

#define AT32_HAS_TMR6                       TRUE
#define AT32_TMR6_IS_32BITS                 FALSE
#define AT32_TMR6_CHANNELS                  0

#define AT32_HAS_TMR7                       TRUE
#define AT32_TMR7_IS_32BITS                 FALSE
#define AT32_TMR7_CHANNELS                  0

#define AT32_HAS_TMR8                       FALSE

#define AT32_HAS_TMR9                       TRUE
#define AT32_TMR9_IS_32BITS                 FALSE
#define AT32_TMR9_CHANNELS                  2

#define AT32_HAS_TMR10                      TRUE
#define AT32_TMR10_IS_32BITS                FALSE
#define AT32_TMR10_CHANNELS                 1

#define AT32_HAS_TMR11                      TRUE
#define AT32_TMR11_IS_32BITS                FALSE
#define AT32_TMR11_CHANNELS                 1

#define AT32_HAS_TMR12                      FALSE

#define AT32_HAS_TMR13                      TRUE
#define AT32_TMR13_IS_32BITS                FALSE
#define AT32_TMR13_CHANNELS                 1

#define AT32_HAS_TMR14                      TRUE
#define AT32_TMR14_IS_32BITS                FALSE
#define AT32_TMR14_CHANNELS                 1

/* USART attributes.*/
#define AT32_HAS_USART1                     TRUE
#define AT32_HAS_USART2                     TRUE
#define AT32_HAS_USART3                     TRUE
#define AT32_HAS_UART4                      TRUE
#define AT32_HAS_UART5                      TRUE
#define AT32_HAS_USART6                     TRUE
#define AT32_HAS_UART7                      TRUE
#define AT32_HAS_UART8                      FALSE

/* USB attributes.*/
#define AT32_OTG_STEPPING                   2
#define AT32_HAS_OTG1                       TRUE
#define AT32_OTG1_ENDPOINTS                 8

#if defined(AT32F405xx)
#define AT32_HAS_OTG2                       TRUE
#define AT32_OTG2_ENDPOINTS                 8
#else
#define AT32_HAS_OTG2                       FALSE
#endif

#define AT32_HAS_USB                        FALSE

/* IWDG attributes.*/
#define AT32_HAS_IWDG                       TRUE
#define AT32_IWDG_IS_WINDOWED               TRUE

/* FSMC attributes.*/
#define AT32_HAS_FSMC                       FALSE

/* CRC attributes.*/
#define AT32_HAS_CRC                        TRUE
#define AT32_CRC_PROGRAMMABLE               FALSE

#endif /* defined(AT32F402Cx) || defined(AT32F405Cx) */

#if defined(AT32F402Rx) || defined(AT32F405Rx)
/**
 * @name    AT32F402_405Rx capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                       TRUE
#define AT32_HAS_ADC2                       FALSE
#define AT32_HAS_ADC3                       FALSE

/* CAN attributes.*/
#define AT32_HAS_CAN1                       TRUE
#define AT32_HAS_CAN2                       FALSE
#define AT32_CAN_MAX_FILTERS                14

/* DAC attributes.*/
#define AT32_HAS_DAC1_CH1                   FALSE
#define AT32_HAS_DAC1_CH2                   FALSE

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                   TRUE
#define AT32_DMA_SUPPORTS_DMAMUX            TRUE
#define AT32_DMA_SUPPORTS_CSELR             FALSE

#define AT32_DMA1_NUM_CHANNELS              7
#define AT32_DMA2_NUM_CHANNELS              7

/* ETH attributes.*/
#define AT32_HAS_ETH                        FALSE

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES                22
#define AT32_EXINT_INTEN_MASK               0x00000000U

/* Flash attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS          1
#if defined(AT32F402xB) || defined(AT32F405xB)
#define AT32_FLASH_SECTOR_SIZE              1024U
#elif defined(AT32F402xC) || defined(AT32F405xC)
#define AT32_FLASH_SECTOR_SIZE              2048U
#endif
#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK         128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                      TRUE
#define AT32_HAS_GPIOB                      TRUE
#define AT32_HAS_GPIOC                      TRUE
#define AT32_HAS_GPIOD                      TRUE
#define AT32_HAS_GPIOE                      FALSE
#define AT32_HAS_GPIOF                      TRUE
#define AT32_HAS_GPIOG                      FALSE
#define AT32_HAS_GPIOH                      FALSE
#define AT32_HAS_GPIOI                      FALSE
#define AT32_HAS_GPIOJ                      FALSE
#define AT32_HAS_GPIOK                      FALSE

#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN | \
                                            CRM_AHBEN1_GPIOBEN | \
                                            CRM_AHBEN1_GPIOCEN | \
                                            CRM_AHBEN1_GPIODEN | \
                                            CRM_AHBEN1_GPIOFEN)

/* I2C attributes.*/
#define AT32_HAS_I2C1                       TRUE
#define AT32_HAS_I2C2                       TRUE
#define AT32_HAS_I2C3                       TRUE

/* RTC attributes.*/
#define AT32_HAS_ERTC                       TRUE
#define AT32_ERTC_HAS_SUBSECONDS            TRUE
#define AT32_ERTC_IS_CALENDAR               TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS      TRUE
#define AT32_ERTC_NUM_ALARMS                2
#define AT32_ERTC_STORAGE_SIZE              80

/* SDIO attributes.*/
#define AT32_HAS_SDIO                       FALSE

/* SPI attributes.*/
#define AT32_HAS_SPI1                       TRUE
#define AT32_SPI1_SUPPORTS_I2S              TRUE
#define AT32_SPI1_I2S_FULLDUPLEX            FALSE

#define AT32_HAS_SPI2                       TRUE
#define AT32_SPI2_SUPPORTS_I2S              TRUE
#define AT32_SPI2_I2S_FULLDUPLEX            FALSE

#define AT32_HAS_SPI3                       TRUE
#define AT32_SPI3_SUPPORTS_I2S              TRUE
#define AT32_SPI3_I2S_FULLDUPLEX            FALSE

/* TMR attributes.*/
#define AT32_TMR_MAX_CHANNELS               4

#define AT32_HAS_TMR1                       TRUE
#define AT32_TMR1_IS_32BITS                 FALSE
#define AT32_TMR1_CHANNELS                  4

#define AT32_HAS_TMR2                       TRUE
#define AT32_TMR2_IS_32BITS                 TRUE
#define AT32_TMR2_CHANNELS                  4

#define AT32_HAS_TMR3                       TRUE
#define AT32_TMR3_IS_32BITS                 FALSE
#define AT32_TMR3_CHANNELS                  4

#define AT32_HAS_TMR4                       TRUE
#define AT32_TMR4_IS_32BITS                 FALSE
#define AT32_TMR4_CHANNELS                  4

#define AT32_HAS_TMR5                       FALSE

#define AT32_HAS_TMR6                       TRUE
#define AT32_TMR6_IS_32BITS                 FALSE
#define AT32_TMR6_CHANNELS                  0

#define AT32_HAS_TMR7                       TRUE
#define AT32_TMR7_IS_32BITS                 FALSE
#define AT32_TMR7_CHANNELS                  0

#define AT32_HAS_TMR8                       FALSE

#define AT32_HAS_TMR9                       TRUE
#define AT32_TMR9_IS_32BITS                 FALSE
#define AT32_TMR9_CHANNELS                  2

#define AT32_HAS_TMR10                      TRUE
#define AT32_TMR10_IS_32BITS                FALSE
#define AT32_TMR10_CHANNELS                 1

#define AT32_HAS_TMR11                      TRUE
#define AT32_TMR11_IS_32BITS                FALSE
#define AT32_TMR11_CHANNELS                 1

#define AT32_HAS_TMR12                      FALSE

#define AT32_HAS_TMR13                      TRUE
#define AT32_TMR13_IS_32BITS                FALSE
#define AT32_TMR13_CHANNELS                 1

#define AT32_HAS_TMR14                      TRUE
#define AT32_TMR14_IS_32BITS                FALSE
#define AT32_TMR14_CHANNELS                 1

/* USART attributes.*/
#define AT32_HAS_USART1                     TRUE
#define AT32_HAS_USART2                     TRUE
#define AT32_HAS_USART3                     TRUE
#define AT32_HAS_UART4                      TRUE
#define AT32_HAS_UART5                      TRUE
#define AT32_HAS_USART6                     TRUE
#define AT32_HAS_UART7                      TRUE
#define AT32_HAS_UART8                      TRUE

/* USB attributes.*/
#define AT32_OTG_STEPPING                   2
#define AT32_HAS_OTG1                       TRUE
#define AT32_OTG1_ENDPOINTS                 8

#if defined(AT32F405xx)
#define AT32_HAS_OTG2                       TRUE
#define AT32_OTG2_ENDPOINTS                 8
#else
#define AT32_HAS_OTG2                       FALSE
#endif

#define AT32_HAS_USB                        FALSE

/* IWDG attributes.*/
#define AT32_HAS_IWDG                       TRUE
#define AT32_IWDG_IS_WINDOWED               TRUE

/* FSMC attributes.*/
#define AT32_HAS_FSMC                       FALSE

/* CRC attributes.*/
#define AT32_HAS_CRC                        TRUE
#define AT32_CRC_PROGRAMMABLE               FALSE

#endif /* defined(AT32F402Rx) || defined(AT32F405Rx) */

#endif /* AT32_REGISTRY_H */

/** @} */
