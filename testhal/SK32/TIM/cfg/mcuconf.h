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
 * The SK32F0xx family is register-compatible with STM32F072 except for the
 * USB IP, but the SK32 port provides native drivers for the entire core
 * platform and for every peripheral, so no shared STM32 low level driver
 * (TIMv1, USARTv2, ADCv1, SPIv2, I2Cv2, ..., nor the CANv1/DACv1/DMAv1/
 * RTCv2/xWDGv1 stubs) is linked in.  This mcuconf.h only needs to satisfy
 * the single SK32 naming scheme:
 *   - SK32F0xx_MCUCONF + the SK32_* clock/ST/peripheral settings consumed by
 *     the native SK32 HAL low level drivers.
 *
 * IRQ priorities:
 * 3...0       Lowest...Highest.
 *
 * DMA priorities:
 * 0...3        Lowest...Highest.
 */

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
 * GPT driver system settings.
 * The SK32 native GPT driver (TIM3 on the APB1 bus, TIM16/TIM17 on the APB2
 * bus) is selected through the SK32_GPT_USE_TIMx switches.  All three timers
 * are used by the TIM testhal to verify interrupt driven counting.
 */
#define SK32_GPT_USE_TIM3                   TRUE
#define SK32_GPT_USE_TIM16                  TRUE
#define SK32_GPT_USE_TIM17                  TRUE
#define SK32_GPT_TIM3_IRQ_PRIORITY          3
#define SK32_GPT_TIM16_IRQ_PRIORITY         3
#define SK32_GPT_TIM17_IRQ_PRIORITY         3

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
 * The SK32 native interrupt-driven SPI driver is selected through the
 * SK32_SPI_USE_SPIx switches.
 *
 * SPI1 self-loopback test:
 *  - SPI1 master on PA7 (SPI1_MOSI, alternate 12) and PA6 (SPI1_MISO,
 *    alternate 12), the two pads are shorted on the board.
 */
#define SK32_SPI_USE_SPI1                   TRUE
#define SK32_SPI_USE_SPI2                   FALSE
#define SK32_SPI_SPI1_PRIORITY              3
#define SK32_SPI_SPI2_PRIORITY              3

/*
 * SK32 ST driver system settings.
 * The SK32 port uses its native SysTick-based ST driver which requires
 * periodic mode.
 */
#define SK32_ST_IRQ_PRIORITY                2

#endif /* MCUCONF_H */