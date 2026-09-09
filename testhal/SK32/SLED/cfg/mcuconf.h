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
 * SERIAL driver system settings.
 * The SK32 native serial driver (SR/DR USART) is selected through the
 * SK32_SERIAL_USE_USARTx switches.  Not used by this test: HAL_USE_SERIAL
 * is disabled in halconf.h, the switches are kept at FALSE.
 */
#define SK32_SERIAL_USE_USART1              FALSE
#define SK32_SERIAL_USE_USART2              FALSE
#define SK32_SERIAL_USART1_PRIORITY         3
#define SK32_SERIAL_USART2_PRIORITY         3

/*
 * SPI driver system settings.
 * The SK32 native interrupt-driven SPI driver is selected through the
 * SK32_SPI_USE_SPIx switches.  Not used by this test: HAL_USE_SPI is
 * disabled in halconf.h, the switches are kept at FALSE.
 */
#define SK32_SPI_USE_SPI1                   FALSE
#define SK32_SPI_USE_SPI2                   FALSE
#define SK32_SPI_SPI1_PRIORITY              3
#define SK32_SPI_SPI2_PRIORITY              3

/*
 * SLED driver system settings.
 * The SK32 SLED driver (hal_sled_lld.c) is enabled through the HAL_USE_SLED
 * switch in halconf.h.  It allocates one DMA1 channel per compiled group
 * (channel 1 for the SLED1 registers, channel 2 for the SLED2 registers)
 * and routes each channel to its SLED request line through the SYSCFG CFGR3
 * remapping.  This test drives the PC0 pad = datasheet SLED1_CH0 output,
 * which is served by the SLED2 channel registers (DR[1]/DMAEN2/RSTSTR2);
 * the Makefile therefore adds -DSK32_SLED_USE_SLED2=TRUE.  The pad (PC0,
 * alternate function 14) is configured by main.c.
 */

/*
 * SK32 ST driver system settings.
 * The SK32 port uses its native SysTick-based ST driver which requires
 * periodic mode.
 */
#define SK32_ST_IRQ_PRIORITY                2

#endif /* MCUCONF_H */