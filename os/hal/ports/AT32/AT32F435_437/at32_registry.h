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
 * @file    AT32F435_437/at32_registry.h
 * @brief   AT32F435_437 capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef AT32_REGISTRY_H
#define AT32_REGISTRY_H

/* define with package */
#if defined(AT32F435CC) || defined(AT32F435CG) ||                           \
    defined(AT32F435CM)
#define AT32F435_437Cx

#elif defined(AT32F435RC) || defined(AT32F435RG) ||                          \
      defined(AT32F435RM) || defined(AT32F437RC) ||                          \
      defined(AT32F437RG) || defined(AT32F437RM)
#define AT32F435_437Rx

#elif defined(AT32F435VC) || defined(AT32F435VG) ||                          \
      defined(AT32F435VM) || defined(AT32F437VC) ||                          \
      defined(AT32F437VG) || defined(AT32F437VM)
#define AT32F435_437Vx

#elif defined(AT32F435ZC) || defined(AT32F435ZG) ||                          \
      defined(AT32F435ZM) || defined(AT32F437ZC) ||                          \
      defined(AT32F437ZG) || defined(AT32F437ZM)
#define AT32F435_437Zx

#else
#error "unsupported or unrecognized AT32F435 or AT32F437 member"
#endif

/* define with memory */
#if defined(AT32F435CC) || defined(AT32F435RC) ||                           \
    defined(AT32F435VC) || defined(AT32F435ZC) ||                           \
    defined(AT32F437RC) || defined(AT32F437VC) ||                           \
    defined(AT32F437ZC)
#define AT32F435_437xC

#elif defined(AT32F435CG) || defined(AT32F435RG) ||                          \
      defined(AT32F435VG) || defined(AT32F435ZG) ||                          \
      defined(AT32F437RG) || defined(AT32F437VG) ||                          \
      defined(AT32F437ZG)
#define AT32F435_437xG

#elif defined(AT32F435CM) || defined(AT32F435RM) ||                          \
      defined(AT32F435VM) || defined(AT32F435ZM) ||                          \
      defined(AT32F437RM) || defined(AT32F437VM) ||                          \
      defined(AT32F437ZM)
#define AT32F435_437xM

#else
#error "unsupported or unrecognized AT32F435 or AT32F437 member"
#endif

/* Flash attributes.*/
#if defined(AT32F435_437xG) || defined(AT32F435_437xM)
#define AT32_FLASH_NUMBER_OF_BANKS          2
#else
#define AT32_FLASH_NUMBER_OF_BANKS          1
#endif

#if defined(AT32F435_437xM)
#define AT32_FLASH_SECTOR_SIZE              4096U
#else
#define AT32_FLASH_SECTOR_SIZE              2048U
#endif

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#if defined(AT32F435_437xM)
#define AT32_FLASH_SECTORS_PER_BANK         512 /* Maximum, can be redefined.*/
#elif defined(AT32F435_437xG)
#define AT32_FLASH_SECTORS_PER_BANK         256 /* Maximum, can be redefined.*/
#else 
#define AT32_FLASH_SECTORS_PER_BANK         128 /* Maximum, can be redefined.*/
#endif
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    AT32F435_437 capabilities
 * @{
 */

/* DEBUG helpers.*/
#define AT32_DEBUG_TMR1_STOP()             DEBUG->APB2_PAUSE |= DEBUG_APB2_PAUSE_TMR1_PAUSE
#define AT32_DEBUG_TMR2_STOP()             DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR2_PAUSE
#define AT32_DEBUG_TMR3_STOP()             DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR3_PAUSE
#define AT32_DEBUG_TMR4_STOP()             DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR4_PAUSE
#define AT32_DEBUG_TMR5_STOP()             DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR5_PAUSE
#define AT32_DEBUG_TMR6_STOP()             DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR6_PAUSE
#define AT32_DEBUG_TMR7_STOP()             DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR7_PAUSE
#define AT32_DEBUG_TMR8_STOP()             DEBUG->APB2_PAUSE |= DEBUG_APB2_PAUSE_TMR8_PAUSE
#define AT32_DEBUG_TMR9_STOP()             DEBUG->APB2_PAUSE |= DEBUG_APB2_PAUSE_TMR9_PAUSE
#define AT32_DEBUG_TMR10_STOP()            DEBUG->APB2_PAUSE |= DEBUG_APB2_PAUSE_TMR10_PAUSE
#define AT32_DEBUG_TMR11_STOP()            DEBUG->APB2_PAUSE |= DEBUG_APB2_PAUSE_TMR11_PAUSE
#define AT32_DEBUG_TMR12_STOP()            DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR12_PAUSE
#define AT32_DEBUG_TMR13_STOP()            DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR13_PAUSE
#define AT32_DEBUG_TMR14_STOP()            DEBUG->APB1_PAUSE |= DEBUG_APB1_PAUSE_TMR14_PAUSE
#define AT32_DEBUG_TMR20_STOP()            DEBUG->APB2_PAUSE |= DEBUG_APB2_PAUSE_TMR20_PAUSE

#if defined(AT32F435_437Cx) || defined(__DOXYGEN__)
/**
 * @name    AT32F435Cx capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                       TRUE
#define AT32_HAS_ADC2                       TRUE
#define AT32_HAS_ADC3                       TRUE
#define AT32_ADC_SUPPORTS_PRESCALER         TRUE
#define AT32_ADC_SUPPORTS_OVERSAMPLING      TRUE

/* CAN attributes.*/
#define AT32_HAS_CAN1                       TRUE
#define AT32_HAS_CAN2                       TRUE
#define AT32_CAN_MAX_FILTERS                14

/* DAC attributes.*/
#define AT32_HAS_DAC1_CH1                   TRUE
#define AT32_HAS_DAC1_CH2                   TRUE

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                   TRUE
#define AT32_DMA_SUPPORTS_DMAMUX            TRUE
#define AT32_DMA_SUPPORTS_CSELR             FALSE

#define AT32_DMA1_NUM_CHANNELS              7
#define AT32_DMA2_NUM_CHANNELS              7

/* EDMA attributes.*/
#define AT32_EDMA_SUPPORTS_EDMAMUX          TRUE
#define AT32_HAS_EDMA1                      TRUE
#define AT32_HAS_EDMA2                      FALSE

/* ETH attributes.*/
#define AT32_HAS_ETH                        FALSE

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES                23
#define AT32_EXINT_INTEN_MASK               0x00000000U

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                      TRUE
#define AT32_HAS_GPIOB                      TRUE
#define AT32_HAS_GPIOC                      TRUE
#define AT32_HAS_GPIOD                      FALSE
#define AT32_HAS_GPIOE                      FALSE
#define AT32_HAS_GPIOF                      FALSE
#define AT32_HAS_GPIOG                      FALSE
#define AT32_HAS_GPIOH                      TRUE
#define AT32_HAS_GPIOI                      FALSE
#define AT32_HAS_GPIOJ                      FALSE
#define AT32_HAS_GPIOK                      FALSE

#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN | \
                                            CRM_AHBEN1_GPIOBEN | \
                                            CRM_AHBEN1_GPIOCEN | \
                                            CRM_AHBEN1_GPIOHEN)

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
#define AT32_HAS_SDIO1                      TRUE
#define AT32_HAS_SDIO2                      FALSE
#define AT32_HAS_SDIO                       TRUE

/* SPI attributes.*/
#define AT32_HAS_SPI1                       TRUE
#define AT32_SPI1_SUPPORTS_I2S              TRUE
#define AT32_SPI1_I2S_FULLDUPLEX            FALSE

#define AT32_HAS_SPI2                       TRUE
#define AT32_SPI2_SUPPORTS_I2S              TRUE
#define AT32_SPI2_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI3                       TRUE
#define AT32_SPI3_SUPPORTS_I2S              TRUE
#define AT32_SPI3_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI4                       TRUE
#define AT32_SPI4_SUPPORTS_I2S              TRUE
#define AT32_SPI4_I2S_FULLDUPLEX            FALSE

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                   TRUE
#define AT32_HAS_QUADSPI2                   TRUE

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

#define AT32_HAS_TMR5                       TRUE
#define AT32_TMR5_IS_32BITS                 TRUE
#define AT32_TMR5_CHANNELS                  4

#define AT32_HAS_TMR6                       TRUE
#define AT32_TMR6_IS_32BITS                 FALSE
#define AT32_TMR6_CHANNELS                  0

#define AT32_HAS_TMR7                       TRUE
#define AT32_TMR7_IS_32BITS                 FALSE
#define AT32_TMR7_CHANNELS                  0

#define AT32_HAS_TMR8                       TRUE
#define AT32_TMR8_IS_32BITS                 FALSE
#define AT32_TMR8_CHANNELS                  4

#define AT32_HAS_TMR9                       TRUE
#define AT32_TMR9_IS_32BITS                 FALSE
#define AT32_TMR9_CHANNELS                  2

#define AT32_HAS_TMR10                      TRUE
#define AT32_TMR10_IS_32BITS                FALSE
#define AT32_TMR10_CHANNELS                 1

#define AT32_HAS_TMR11                      TRUE
#define AT32_TMR11_IS_32BITS                FALSE
#define AT32_TMR11_CHANNELS                 1

#define AT32_HAS_TMR12                      TRUE
#define AT32_TMR12_IS_32BITS                FALSE
#define AT32_TMR12_CHANNELS                 2

#define AT32_HAS_TMR13                      TRUE
#define AT32_TMR13_IS_32BITS                FALSE
#define AT32_TMR13_CHANNELS                 1

#define AT32_HAS_TMR14                      TRUE
#define AT32_TMR14_IS_32BITS                FALSE
#define AT32_TMR14_CHANNELS                 1

#define AT32_HAS_TMR20                      TRUE
#define AT32_TMR20_IS_32BITS                FALSE
#define AT32_TMR20_CHANNELS                 4

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
#define AT32_OTG1_ENDPOINTS                 7

#define AT32_HAS_OTG2                       TRUE
#define AT32_OTG2_ENDPOINTS                 7
#define AT32_OTG2_SUPPORTS_HS               FALSE

#define AT32_HAS_USB                        FALSE

/* IWDG attributes.*/
#define AT32_HAS_IWDG                       TRUE
#define AT32_IWDG_IS_WINDOWED               TRUE

/* FSMC attributes.*/
#define AT32_HAS_FSMC                       FALSE

/* CRC attributes.*/
#define AT32_HAS_CRC                        TRUE
#define AT32_CRC_PROGRAMMABLE               FALSE

#endif /* defined(AT32F435_437Cx) */

#if defined(AT32F435_437Rx) || defined(__DOXYGEN__)
/**
 * @name    AT32F435Rx AT32F437Rx capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                       TRUE
#define AT32_HAS_ADC2                       TRUE
#define AT32_HAS_ADC3                       TRUE
#define AT32_ADC_SUPPORTS_PRESCALER         TRUE
#define AT32_ADC_SUPPORTS_OVERSAMPLING      TRUE

/* CAN attributes.*/
#define AT32_HAS_CAN1                       TRUE
#define AT32_HAS_CAN2                       TRUE
#define AT32_CAN_MAX_FILTERS                14

/* DAC attributes.*/
#define AT32_HAS_DAC1_CH1                   TRUE
#define AT32_HAS_DAC1_CH2                   TRUE

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                   TRUE
#define AT32_DMA_SUPPORTS_DMAMUX            TRUE
#define AT32_DMA_SUPPORTS_CSELR             FALSE

#define AT32_DMA1_NUM_CHANNELS              7
#define AT32_DMA2_NUM_CHANNELS              7

/* EDMA attributes.*/
#define AT32_EDMA_SUPPORTS_EDMAMUX          TRUE
#define AT32_HAS_EDMA1                      TRUE
#define AT32_HAS_EDMA2                      FALSE

/* ETH attributes.*/
#if defined(AT32F437xx)
#define AT32_HAS_ETH                        TRUE
#else
#define AT32_HAS_ETH                        FALSE
#endif

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES                23
#define AT32_EXINT_INTEN_MASK               0x00000000U

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                      TRUE
#define AT32_HAS_GPIOB                      TRUE
#define AT32_HAS_GPIOC                      TRUE
#define AT32_HAS_GPIOD                      TRUE
#define AT32_HAS_GPIOE                      FALSE
#define AT32_HAS_GPIOF                      FALSE
#define AT32_HAS_GPIOG                      FALSE
#define AT32_HAS_GPIOH                      TRUE
#define AT32_HAS_GPIOI                      FALSE
#define AT32_HAS_GPIOJ                      FALSE
#define AT32_HAS_GPIOK                      FALSE

#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN | \
                                            CRM_AHBEN1_GPIOBEN | \
                                            CRM_AHBEN1_GPIOCEN | \
                                            CRM_AHBEN1_GPIODEN | \
                                            CRM_AHBEN1_GPIOHEN)

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
#define AT32_HAS_SDIO1                      TRUE
#define AT32_HAS_SDIO2                      TRUE
#define AT32_HAS_SDIO                       TRUE

/* SPI attributes.*/
#define AT32_HAS_SPI1                       TRUE
#define AT32_SPI1_SUPPORTS_I2S              TRUE
#define AT32_SPI1_I2S_FULLDUPLEX            FALSE

#define AT32_HAS_SPI2                       TRUE
#define AT32_SPI2_SUPPORTS_I2S              TRUE
#define AT32_SPI2_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI3                       TRUE
#define AT32_SPI3_SUPPORTS_I2S              TRUE
#define AT32_SPI3_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI4                       TRUE
#define AT32_SPI4_SUPPORTS_I2S              TRUE
#define AT32_SPI4_I2S_FULLDUPLEX            FALSE

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                   TRUE
#define AT32_HAS_QUADSPI2                   TRUE

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

#define AT32_HAS_TMR5                       TRUE
#define AT32_TMR5_IS_32BITS                 TRUE
#define AT32_TMR5_CHANNELS                  4

#define AT32_HAS_TMR6                       TRUE
#define AT32_TMR6_IS_32BITS                 FALSE
#define AT32_TMR6_CHANNELS                  0

#define AT32_HAS_TMR7                       TRUE
#define AT32_TMR7_IS_32BITS                 FALSE
#define AT32_TMR7_CHANNELS                  0

#define AT32_HAS_TMR8                       TRUE
#define AT32_TMR8_IS_32BITS                 FALSE
#define AT32_TMR8_CHANNELS                  4

#define AT32_HAS_TMR9                       TRUE
#define AT32_TMR9_IS_32BITS                 FALSE
#define AT32_TMR9_CHANNELS                  2

#define AT32_HAS_TMR10                      TRUE
#define AT32_TMR10_IS_32BITS                FALSE
#define AT32_TMR10_CHANNELS                 1

#define AT32_HAS_TMR11                      TRUE
#define AT32_TMR11_IS_32BITS                FALSE
#define AT32_TMR11_CHANNELS                 1

#define AT32_HAS_TMR12                      TRUE
#define AT32_TMR12_IS_32BITS                FALSE
#define AT32_TMR12_CHANNELS                 2

#define AT32_HAS_TMR13                      TRUE
#define AT32_TMR13_IS_32BITS                FALSE
#define AT32_TMR13_CHANNELS                 1

#define AT32_HAS_TMR14                      TRUE
#define AT32_TMR14_IS_32BITS                FALSE
#define AT32_TMR14_CHANNELS                 1

#define AT32_HAS_TMR20                      TRUE
#define AT32_TMR20_IS_32BITS                FALSE
#define AT32_TMR20_CHANNELS                 4

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
#define AT32_OTG1_ENDPOINTS                 7

#define AT32_HAS_OTG2                       TRUE
#define AT32_OTG2_ENDPOINTS                 7
#define AT32_OTG2_SUPPORTS_HS               FALSE

#define AT32_HAS_USB                        FALSE

/* IWDG attributes.*/
#define AT32_HAS_IWDG                       TRUE
#define AT32_IWDG_IS_WINDOWED               TRUE

/* FSMC attributes.*/
#define AT32_HAS_FSMC                       TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                        TRUE
#define AT32_CRC_PROGRAMMABLE               FALSE

#endif /* defined(AT32F435_437Rx) */

#if defined(AT32F435_437Vx) || defined(__DOXYGEN__)
/**
 * @name    AT32F435Vx AT32F437Vx capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                       TRUE
#define AT32_HAS_ADC2                       TRUE
#define AT32_HAS_ADC3                       TRUE
#define AT32_ADC_SUPPORTS_PRESCALER         TRUE
#define AT32_ADC_SUPPORTS_OVERSAMPLING      TRUE

/* CAN attributes.*/
#define AT32_HAS_CAN1                       TRUE
#define AT32_HAS_CAN2                       TRUE
#define AT32_CAN_MAX_FILTERS                14

/* DAC attributes.*/
#define AT32_HAS_DAC1_CH1                   TRUE
#define AT32_HAS_DAC1_CH2                   TRUE

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                   TRUE
#define AT32_DMA_SUPPORTS_DMAMUX            TRUE
#define AT32_DMA_SUPPORTS_CSELR             FALSE

#define AT32_DMA1_NUM_CHANNELS              7
#define AT32_DMA2_NUM_CHANNELS              7

/* EDMA attributes.*/
#define AT32_EDMA_SUPPORTS_EDMAMUX          TRUE
#define AT32_HAS_EDMA1                      TRUE
#define AT32_HAS_EDMA2                      FALSE

/* ETH attributes.*/
#if defined(AT32F437xx)
#define AT32_HAS_ETH                        TRUE
#else
#define AT32_HAS_ETH                        FALSE
#endif

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES                23
#define AT32_EXINT_INTEN_MASK               0x00000000U

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                      TRUE
#define AT32_HAS_GPIOB                      TRUE
#define AT32_HAS_GPIOC                      TRUE
#define AT32_HAS_GPIOD                      TRUE
#define AT32_HAS_GPIOE                      TRUE
#define AT32_HAS_GPIOF                      FALSE
#define AT32_HAS_GPIOG                      FALSE
#define AT32_HAS_GPIOH                      TRUE
#define AT32_HAS_GPIOI                      FALSE
#define AT32_HAS_GPIOJ                      FALSE
#define AT32_HAS_GPIOK                      FALSE

#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN | \
                                            CRM_AHBEN1_GPIOBEN | \
                                            CRM_AHBEN1_GPIOCEN | \
                                            CRM_AHBEN1_GPIODEN | \
                                            CRM_AHBEN1_GPIOEEN | \
                                            CRM_AHBEN1_GPIOHEN)

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
#define AT32_HAS_SDIO1                      TRUE
#define AT32_HAS_SDIO2                      TRUE
#define AT32_HAS_SDIO                       TRUE

/* SPI attributes.*/
#define AT32_HAS_SPI1                       TRUE
#define AT32_SPI1_SUPPORTS_I2S              TRUE
#define AT32_SPI1_I2S_FULLDUPLEX            FALSE

#define AT32_HAS_SPI2                       TRUE
#define AT32_SPI2_SUPPORTS_I2S              TRUE
#define AT32_SPI2_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI3                       TRUE
#define AT32_SPI3_SUPPORTS_I2S              TRUE
#define AT32_SPI3_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI4                       TRUE
#define AT32_SPI4_SUPPORTS_I2S              TRUE
#define AT32_SPI4_I2S_FULLDUPLEX            FALSE

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                   TRUE
#define AT32_HAS_QUADSPI2                   TRUE

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

#define AT32_HAS_TMR5                       TRUE
#define AT32_TMR5_IS_32BITS                 TRUE
#define AT32_TMR5_CHANNELS                  4

#define AT32_HAS_TMR6                       TRUE
#define AT32_TMR6_IS_32BITS                 FALSE
#define AT32_TMR6_CHANNELS                  0

#define AT32_HAS_TMR7                       TRUE
#define AT32_TMR7_IS_32BITS                 FALSE
#define AT32_TMR7_CHANNELS                  0

#define AT32_HAS_TMR8                       TRUE
#define AT32_TMR8_IS_32BITS                 FALSE
#define AT32_TMR8_CHANNELS                  4

#define AT32_HAS_TMR9                       TRUE
#define AT32_TMR9_IS_32BITS                 FALSE
#define AT32_TMR9_CHANNELS                  2

#define AT32_HAS_TMR10                      TRUE
#define AT32_TMR10_IS_32BITS                FALSE
#define AT32_TMR10_CHANNELS                 1

#define AT32_HAS_TMR11                      TRUE
#define AT32_TMR11_IS_32BITS                FALSE
#define AT32_TMR11_CHANNELS                 1

#define AT32_HAS_TMR12                      TRUE
#define AT32_TMR12_IS_32BITS                FALSE
#define AT32_TMR12_CHANNELS                 2

#define AT32_HAS_TMR13                      TRUE
#define AT32_TMR13_IS_32BITS                FALSE
#define AT32_TMR13_CHANNELS                 1

#define AT32_HAS_TMR14                      TRUE
#define AT32_TMR14_IS_32BITS                FALSE
#define AT32_TMR14_CHANNELS                 1

#define AT32_HAS_TMR20                      TRUE
#define AT32_TMR20_IS_32BITS                FALSE
#define AT32_TMR20_CHANNELS                 4

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
#define AT32_OTG1_ENDPOINTS                 7

#define AT32_HAS_OTG2                       TRUE
#define AT32_OTG2_ENDPOINTS                 7
#define AT32_OTG2_SUPPORTS_HS               FALSE

#define AT32_HAS_USB                        FALSE

/* IWDG attributes.*/
#define AT32_HAS_IWDG                       TRUE
#define AT32_IWDG_IS_WINDOWED               TRUE

/* FSMC attributes.*/
#define AT32_HAS_FSMC                       TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                        TRUE
#define AT32_CRC_PROGRAMMABLE               FALSE

#endif /* defined(AT32F435_437Vx) */

#if defined(AT32F435_437Zx) || defined(__DOXYGEN__)
/**
 * @name    AT32F435Zx AT32F437Zx capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                       TRUE
#define AT32_HAS_ADC2                       TRUE
#define AT32_HAS_ADC3                       TRUE
#define AT32_ADC_SUPPORTS_PRESCALER         TRUE
#define AT32_ADC_SUPPORTS_OVERSAMPLING      TRUE

/* CAN attributes.*/
#define AT32_HAS_CAN1                       TRUE
#define AT32_HAS_CAN2                       TRUE
#define AT32_CAN_MAX_FILTERS                14

/* DAC attributes.*/
#define AT32_HAS_DAC1_CH1                   TRUE
#define AT32_HAS_DAC1_CH2                   TRUE

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                   TRUE
#define AT32_DMA_SUPPORTS_DMAMUX            TRUE
#define AT32_DMA_SUPPORTS_CSELR             FALSE

#define AT32_DMA1_NUM_CHANNELS              7
#define AT32_DMA2_NUM_CHANNELS              7

/* EDMA attributes.*/
#define AT32_EDMA_SUPPORTS_EDMAMUX          TRUE
#define AT32_HAS_EDMA1                      TRUE
#define AT32_HAS_EDMA2                      FALSE

/* ETH attributes.*/
#if defined(AT32F437xx)
#define AT32_HAS_ETH                        TRUE
#else
#define AT32_HAS_ETH                        FALSE
#endif

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES                23
#define AT32_EXINT_INTEN_MASK               0x00000000U

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                      TRUE
#define AT32_HAS_GPIOB                      TRUE
#define AT32_HAS_GPIOC                      TRUE
#define AT32_HAS_GPIOD                      TRUE
#define AT32_HAS_GPIOE                      TRUE
#define AT32_HAS_GPIOF                      TRUE
#define AT32_HAS_GPIOG                      TRUE
#define AT32_HAS_GPIOH                      TRUE
#define AT32_HAS_GPIOI                      FALSE
#define AT32_HAS_GPIOJ                      FALSE
#define AT32_HAS_GPIOK                      FALSE

#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN | \
                                            CRM_AHBEN1_GPIOBEN | \
                                            CRM_AHBEN1_GPIOCEN | \
                                            CRM_AHBEN1_GPIODEN | \
                                            CRM_AHBEN1_GPIOEEN | \
                                            CRM_AHBEN1_GPIOFEN | \
                                            CRM_AHBEN1_GPIOGEN | \
                                            CRM_AHBEN1_GPIOHEN)

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
#define AT32_HAS_SDIO1                      TRUE
#define AT32_HAS_SDIO2                      TRUE
#define AT32_HAS_SDIO                       TRUE

/* SPI attributes.*/
#define AT32_HAS_SPI1                       TRUE
#define AT32_SPI1_SUPPORTS_I2S              TRUE
#define AT32_SPI1_I2S_FULLDUPLEX            FALSE

#define AT32_HAS_SPI2                       TRUE
#define AT32_SPI2_SUPPORTS_I2S              TRUE
#define AT32_SPI2_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI3                       TRUE
#define AT32_SPI3_SUPPORTS_I2S              TRUE
#define AT32_SPI3_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI4                       TRUE
#define AT32_SPI4_SUPPORTS_I2S              TRUE
#define AT32_SPI4_I2S_FULLDUPLEX            FALSE

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                   TRUE
#define AT32_HAS_QUADSPI2                   TRUE

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

#define AT32_HAS_TMR5                       TRUE
#define AT32_TMR5_IS_32BITS                 TRUE
#define AT32_TMR5_CHANNELS                  4

#define AT32_HAS_TMR6                       TRUE
#define AT32_TMR6_IS_32BITS                 FALSE
#define AT32_TMR6_CHANNELS                  0

#define AT32_HAS_TMR7                       TRUE
#define AT32_TMR7_IS_32BITS                 FALSE
#define AT32_TMR7_CHANNELS                  0

#define AT32_HAS_TMR8                       TRUE
#define AT32_TMR8_IS_32BITS                 FALSE
#define AT32_TMR8_CHANNELS                  4

#define AT32_HAS_TMR9                       TRUE
#define AT32_TMR9_IS_32BITS                 FALSE
#define AT32_TMR9_CHANNELS                  2

#define AT32_HAS_TMR10                      TRUE
#define AT32_TMR10_IS_32BITS                FALSE
#define AT32_TMR10_CHANNELS                 1

#define AT32_HAS_TMR11                      TRUE
#define AT32_TMR11_IS_32BITS                FALSE
#define AT32_TMR11_CHANNELS                 1

#define AT32_HAS_TMR12                      TRUE
#define AT32_TMR12_IS_32BITS                FALSE
#define AT32_TMR12_CHANNELS                 2

#define AT32_HAS_TMR13                      TRUE
#define AT32_TMR13_IS_32BITS                FALSE
#define AT32_TMR13_CHANNELS                 1

#define AT32_HAS_TMR14                      TRUE
#define AT32_TMR14_IS_32BITS                FALSE
#define AT32_TMR14_CHANNELS                 1

#define AT32_HAS_TMR20                      TRUE
#define AT32_TMR20_IS_32BITS                FALSE
#define AT32_TMR20_CHANNELS                 4

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
#define AT32_OTG1_ENDPOINTS                 7

#define AT32_HAS_OTG2                       TRUE
#define AT32_OTG2_ENDPOINTS                 7
#define AT32_OTG2_SUPPORTS_HS               FALSE

#define AT32_HAS_USB                        FALSE

/* IWDG attributes.*/
#define AT32_HAS_IWDG                       TRUE
#define AT32_IWDG_IS_WINDOWED               TRUE

/* FSMC attributes.*/
#define AT32_HAS_FSMC                       TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                        TRUE
#define AT32_CRC_PROGRAMMABLE               FALSE

#endif /* defined(AT32F435_437Zx) */

#endif /* AT32_REGISTRY_H */

/** @} */
