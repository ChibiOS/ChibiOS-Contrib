/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.

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

#ifndef MCUCONF_H
#define MCUCONF_H

/*
 * SK32F0xx drivers configuration.
 * The following settings override the default settings present in
 * the various device driver implementation headers.
 * Note that the settings for each driver only have effect if the whole
 * driver is enabled in halconf.h.
 *
 * The SK32F0xx family is register-compatible with STM32F072 except for
 * the USB IP.  The SK32 port provides native drivers for the core platform
 * (clocks, SysTick-based ST, ISR aggregation, GPIO/PAL, USB) and reuses the
 * shared ChibiOS STM32 low level drivers (TIMv1, USARTv2, ADCv1, SPIv2,
 * I2Cv2, ...) for the remaining peripherals.  This mcuconf.h must therefore
 * satisfy two naming schemes:
 *   - SK32F0xx_MCUCONF + the SK32_* clock/ST settings (used by the SK32 HAL
 *     low level drivers), and
 *   - STM32F0xx_MCUCONF + the STM32_* settings consumed by the shared
 *     ChibiOS STM32 low level drivers.
 *
 * IRQ priorities:
 * 3...0       Lowest...Highest.
 *
 * DMA priorities:
 * 0...3        Lowest...Highest.
 */

#define STM32F0xx_MCUCONF
#define SK32F0xx_MCUCONF

/*
 * SK32 HAL system clock settings.
 * SK32_* defaults (72MHz system clock from the 8MHz HSI through the main
 * PLL, HSI/PREDIV1(=1) * PLLMUL(=9)) are applied by hal_lld.h when not
 * defined here; they are repeated below for clarity.
 */
#define SK32_SW                            SK32_SW_PLL
#define SK32_PREDIV_VALUE                  1
#define SK32_PLLMUL_VALUE                  9
#define SK32_HPRE                          SK32_HPRE_DIV1
#define SK32_PPRE                          SK32_PPRE_DIV1

/*
 * STM32 HAL driver system settings (shared LLD requirements).
 */
#define STM32_NO_INIT                       FALSE
#define STM32_PVD_ENABLE                    FALSE
#define STM32_PLS                           STM32_PLS_LEV0
#define STM32_HSI_ENABLED                   TRUE
#define STM32_HSI14_ENABLED                 TRUE
#define STM32_HSI48_ENABLED                 FALSE
#define STM32_LSI_ENABLED                   TRUE
#define STM32_HSE_ENABLED                   FALSE
#define STM32_LSE_ENABLED                   FALSE
#define STM32_SW                            STM32_SW_PLL
#define STM32_PLLSRC                        STM32_PLLSRC_HSI_DIV2
#define STM32_PREDIV_VALUE                  1
#define STM32_PLLMUL_VALUE                  12
#define STM32_HPRE                          STM32_HPRE_DIV1
#define STM32_PPRE                          STM32_PPRE_DIV1
#define STM32_MCOSEL                        STM32_MCOSEL_NOCLOCK
#define STM32_MCOPRE                        STM32_MCOPRE_DIV1
#define STM32_PLLNODIV                      STM32_PLLNODIV_DIV2
#define STM32_USBSW                         STM32_USBSW_HSI48
#define STM32_CECSW                         STM32_CECSW_HSI
#define STM32_I2C1SW                        STM32_I2C1SW_HSI
#define STM32_USART1SW                      STM32_USART1SW_PCLK
#define STM32_RTCSEL                        STM32_RTCSEL_LSI

/*
 * IRQ system settings.
 * The EXTI line IRQ priorities are configured through the native
 * SK32_IRQ_EXTI*_PRIORITY defaults in sk32_isr.h (priority 3), the shared
 * STM32 EXTIv1/GPIOv2 layers are not used by this port.
 */
#define STM32_IRQ_USART1_PRIORITY           3
#define STM32_IRQ_USART2_PRIORITY           3
#define STM32_IRQ_USART3_8_PRIORITY         3

/*
 * ADC driver system settings.
 */
#define STM32_ADC_USE_ADC1                  FALSE
#define STM32_ADC_ADC1_CFGR2                ADC_CFGR2_CKMODE_ADCCLK
#define STM32_ADC_ADC1_DMA_PRIORITY         2
#define STM32_ADC_ADC1_DMA_IRQ_PRIORITY     2
#define STM32_ADC_ADC1_DMA_STREAM           STM32_DMA_STREAM_ID(1, 1)

/*
 * CAN driver system settings.
 */
#define STM32_CAN_USE_CAN1                  FALSE
#define STM32_CAN_CAN1_IRQ_PRIORITY         3

/*
 * DAC driver system settings.
 */
#define STM32_DAC_DUAL_MODE                 FALSE
#define STM32_DAC_USE_DAC1_CH1              FALSE
#define STM32_DAC_USE_DAC1_CH2              FALSE
#define STM32_DAC_DAC1_CH1_IRQ_PRIORITY     2
#define STM32_DAC_DAC1_CH2_IRQ_PRIORITY     2
#define STM32_DAC_DAC1_CH1_DMA_PRIORITY     2
#define STM32_DAC_DAC1_CH2_DMA_PRIORITY     2
#define STM32_DAC_DAC1_CH1_DMA_STREAM       STM32_DMA_STREAM_ID(1, 3)
#define STM32_DAC_DAC1_CH2_DMA_STREAM       STM32_DMA_STREAM_ID(1, 4)

/*
 * GPT driver system settings.
 */
#define STM32_GPT_USE_TIM1                  FALSE
#define STM32_GPT_USE_TIM2                  FALSE
#define STM32_GPT_USE_TIM3                  FALSE
#define STM32_GPT_USE_TIM6                  FALSE
#define STM32_GPT_USE_TIM14                 FALSE
#define STM32_GPT_TIM1_IRQ_PRIORITY         2
#define STM32_GPT_TIM2_IRQ_PRIORITY         2
#define STM32_GPT_TIM3_IRQ_PRIORITY         2
#define STM32_GPT_TIM6_IRQ_PRIORITY         2
#define STM32_GPT_TIM14_IRQ_PRIORITY        2

/*
 * I2C driver system settings.
 */
#define STM32_I2C_USE_I2C1                  FALSE
#define STM32_I2C_USE_I2C2                  FALSE
#define STM32_I2C_BUSY_TIMEOUT              50
#define STM32_I2C_I2C1_IRQ_PRIORITY         3
#define STM32_I2C_I2C2_IRQ_PRIORITY         3
#define STM32_I2C_USE_DMA                   TRUE
#define STM32_I2C_I2C1_DMA_PRIORITY         1
#define STM32_I2C_I2C2_DMA_PRIORITY         1
#define STM32_I2C_I2C1_RX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 3)
#define STM32_I2C_I2C1_TX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 2)
#define STM32_I2C_I2C2_RX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 5)
#define STM32_I2C_I2C2_TX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 4)
#define STM32_I2C_DMA_ERROR_HOOK(i2cp)      osalSysHalt("DMA failure")

/*
 * I2S driver system settings.
 */
#define STM32_I2S_USE_SPI1                  FALSE
#define STM32_I2S_USE_SPI2                  FALSE
#define STM32_I2S_SPI1_MODE                 (STM32_I2S_MODE_MASTER |        \
                                             STM32_I2S_MODE_RX)
#define STM32_I2S_SPI2_MODE                 (STM32_I2S_MODE_MASTER |        \
                                             STM32_I2S_MODE_RX)
#define STM32_I2S_SPI1_IRQ_PRIORITY         2
#define STM32_I2S_SPI2_IRQ_PRIORITY         2
#define STM32_I2S_SPI1_DMA_PRIORITY         1
#define STM32_I2S_SPI2_DMA_PRIORITY         1
#define STM32_I2S_SPI1_RX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 2)
#define STM32_I2S_SPI1_TX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 3)
#define STM32_I2S_SPI2_RX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 4)
#define STM32_I2S_SPI2_TX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 5)
#define STM32_I2S_DMA_ERROR_HOOK(i2sp)      osalSysHalt("DMA failure")

/*
 * ICU driver system settings.
 */
#define STM32_ICU_USE_TIM1                  FALSE
#define STM32_ICU_USE_TIM2                  FALSE
#define STM32_ICU_USE_TIM3                  FALSE
#define STM32_ICU_TIM1_IRQ_PRIORITY         3
#define STM32_ICU_TIM2_IRQ_PRIORITY         3
#define STM32_ICU_TIM3_IRQ_PRIORITY         3

/*
 * PWM driver system settings.
 */
#define STM32_PWM_USE_ADVANCED              FALSE
#define STM32_PWM_USE_TIM1                  FALSE
#define STM32_PWM_USE_TIM2                  FALSE
#define STM32_PWM_USE_TIM3                  FALSE
#define STM32_PWM_TIM1_IRQ_PRIORITY         3
#define STM32_PWM_TIM2_IRQ_PRIORITY         3
#define STM32_PWM_TIM3_IRQ_PRIORITY         3

/*
 * SERIAL driver system settings.
 * The SK32 native serial driver (SR/DR USART) is selected through the
 * SK32_SERIAL_USE_USARTx switches, USART2 is mapped on PA2/PA3 (alternate 1)
 * as documented in board.h.
 */
#define SK32_SERIAL_USE_USART1              FALSE
#define SK32_SERIAL_USE_USART2              TRUE
#define SK32_SERIAL_USART1_PRIORITY         3
#define SK32_SERIAL_USART2_PRIORITY         3

/*
 * SPI driver system settings.
 */
#define STM32_SPI_USE_SPI1                  FALSE
#define STM32_SPI_USE_SPI2                  FALSE
#define STM32_SPI_SPI1_DMA_PRIORITY         1
#define STM32_SPI_SPI2_DMA_PRIORITY         1
#define STM32_SPI_SPI1_IRQ_PRIORITY         2
#define STM32_SPI_SPI2_IRQ_PRIORITY         2
#define STM32_SPI_SPI1_RX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 2)
#define STM32_SPI_SPI1_TX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 3)
#define STM32_SPI_SPI2_RX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 4)
#define STM32_SPI_SPI2_TX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 5)
#define STM32_SPI_DMA_ERROR_HOOK(spip)      osalSysHalt("DMA failure")

/*
 * ST driver system settings.
 */
#define STM32_ST_IRQ_PRIORITY               2
#define STM32_ST_USE_TIMER                  2

/*
 * SK32 ST driver system settings.
 * The SK32 port uses its native SysTick-based ST driver which requires
 * periodic mode, the STM32_ST_* settings above are only kept for the shared
 * STM32 low level drivers.
 */
#define SK32_ST_IRQ_PRIORITY                2

/*
 * UART driver system settings.
 */
#define STM32_UART_USE_USART1               FALSE
#define STM32_UART_USE_USART2               FALSE
#define STM32_UART_USE_USART3               FALSE
#define STM32_UART_USE_UART4                FALSE
#define STM32_UART_USART1_DMA_PRIORITY      0
#define STM32_UART_USART2_DMA_PRIORITY      0
#define STM32_UART_USART3_DMA_PRIORITY      0
#define STM32_UART_UART4_DMA_PRIORITY       0
#define STM32_UART_USART1_RX_DMA_STREAM     STM32_DMA_STREAM_ID(1, 3)
#define STM32_UART_USART1_TX_DMA_STREAM     STM32_DMA_STREAM_ID(1, 2)
#define STM32_UART_USART2_RX_DMA_STREAM     STM32_DMA_STREAM_ID(1, 5)
#define STM32_UART_USART2_TX_DMA_STREAM     STM32_DMA_STREAM_ID(1, 4)
#define STM32_UART_USART3_RX_DMA_STREAM     STM32_DMA_STREAM_ID(1, 3)
#define STM32_UART_USART3_TX_DMA_STREAM     STM32_DMA_STREAM_ID(1, 2)
#define STM32_UART_UART4_RX_DMA_STREAM      STM32_DMA_STREAM_ID(1, 6)
#define STM32_UART_UART4_TX_DMA_STREAM      STM32_DMA_STREAM_ID(1, 7)
#define STM32_UART_DMA_ERROR_HOOK(uartp)    osalSysHalt("DMA failure")

/*
 * USB driver system settings.
 * The SK32 musbfsfc USB LLD (not the STM32 USBv1 LLD) is used by this port.
 */
#define STM32_USB_USE_USB1                  TRUE
#define STM32_USB_LOW_POWER_ON_SUSPEND      FALSE
#define STM32_USB_USB1_LP_IRQ_PRIORITY      3

/*
 * WDG driver system settings.
 */
#define STM32_WDG_USE_IWDG                  FALSE

#endif /* MCUCONF_H */
