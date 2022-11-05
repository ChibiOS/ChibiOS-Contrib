/*
    ChibiOS - Copyright (C) 2006..2020 Giovanni Di Sirio

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

#define SAM_OSC8M_ENABLED         FALSE
#define SAM_OSC32K_ENABLED        FALSE
#define SAM_XOSC_ENABLED          FALSE
#define SAM_XOSC32_ENABLED        TRUE
#define SAM_DFLL48_ENABLED        TRUE

#define SAM_CPUDIV                1
#define SAM_APBADIV               1
#define SAM_APBBDIV               1
#define SAM_APBCDIV               1
#define SAM_RTC_GCLK_SRC_ID       8
#define SAM_RTC_DIV               6

#define SAM_ADC_GCLK_SRC_ID       0
#define SAM_SERCOM0_GCLK_SRC_ID   0
#define SAM_SERCOM1_GCLK_SRC_ID   0
#define SAM_SERCOM2_GCLK_SRC_ID   0
#define SAM_SERCOM3_GCLK_SRC_ID   0
#define SAM_SERCOM4_GCLK_SRC_ID   0
#define SAM_SERCOM5_GCLK_SRC_ID   0
#define SAM_TCC0_TCC1_GCLK_SRC_ID 0
#define SAM_TCC2_TC3_GCLK_SRC_ID  0

/******************** GENCLK *******************/
#define SAM_GCLK0_SRC             GCLK_GENCTRL_SRC_DFLL48M
#define SAM_GCLK0_FREQ            48000000UL

#define SAM_GCLK1_SRC             GCLK_GENCTRL_SRC_XOSC32K
#define SAM_GCLK1_FREQ            32768UL
#define SAM_GCLK1_ENABLE          TRUE

#define SAM_GCLK2_SRC             GCLK_GENCTRL_SRC_DFLL48M
#define SAM_GCLK2_FREQ            1000000UL
#define SAM_GCLK2_ENABLE          FALSE

#define SAM_GCLK3_SRC             GCLK_GENCTRL_SRC_DFLL48M
#define SAM_GCLK3_FREQ            1000000UL
#define SAM_GCLK3_ENABLE          FALSE

#define SAM_GCLK4_SRC             GCLK_GENCTRL_SRC_DFLL48M
#define SAM_GCLK4_FREQ            1000000UL
#define SAM_GCLK4_ENABLE          FALSE

#define SAM_GCLK5_SRC             GCLK_GENCTRL_SRC_DFLL48M
#define SAM_GCLK5_FREQ            1000000UL
#define SAM_GCLK5_ENABLE          FALSE

#define SAM_GCLK6_SRC             GCLK_GENCTRL_SRC_DFLL48M
#define SAM_GCLK6_FREQ            1000000UL
#define SAM_GCLK6_ENABLE          FALSE

#define SAM_GCLK7_SRC             GCLK_GENCTRL_SRC_DFLL48M
#define SAM_GCLK7_FREQ            1000000UL
#define SAM_GCLK7_ENABLE          FALSE

#define SAM_GCLK8_SRC             GCLK_GENCTRL_SRC_DFLL48M
#define SAM_GCLK8_FREQ            640000UL
#define SAM_GCLK8_ENABLE          TRUE

/***********************************************/


#define SAM_DMAC_IRQ_PRIORITY     2
#define SAM_ADC_IRQ_PRIORITY      4
#define SAM_EIC_IRQ_PRIORITY      6
#define SAM_RTC_IRQ_PRIORITY      2
#define SAM_SERCOM0_IRQ_PRIORITY  3
#define SAM_SERCOM1_IRQ_PRIORITY  3
#define SAM_SERCOM2_IRQ_PRIORITY  3
#define SAM_SERCOM3_IRQ_PRIORITY  3
#define SAM_SERCOM4_IRQ_PRIORITY  3
#define SAM_SERCOM5_IRQ_PRIORITY  3
#define SAM_TCC0_IRQ_PRIORITY     2 
#define SAM_TC3_IRQ_PRIORITY      2

#define SAM_ADC_USE_ADC1          FALSE

#define SAM_SIO_USE_SERCOM0       FALSE
#define SAM_SPI_USE_SERCOM0       FALSE
#define SAM_I2C_USE_SERCOM0       FALSE

#define SAM_SIO_USE_SERCOM1       FALSE
#define SAM_SPI_USE_SERCOM1       FALSE
#define SAM_I2C_USE_SERCOM1       FALSE

#define SAM_SIO_USE_SERCOM2       TRUE
#define SAM_SPI_USE_SERCOM2       FALSE
#define SAM_I2C_USE_SERCOM2       FALSE

#define SAM_SIO_USE_SERCOM3       FALSE
#define SAM_SPI_USE_SERCOM3       FALSE
#define SAM_I2C_USE_SERCOM3       FALSE

#define SAM_SIO_USE_SERCOM4       FALSE
#define SAM_SPI_USE_SERCOM4       FALSE
#define SAM_I2C_USE_SERCOM4       FALSE

#define SAM_SIO_USE_SERCOM5       FALSE
#define SAM_SPI_USE_SERCOM5       FALSE
#define SAM_I2C_USE_SERCOM5       FALSE

#define SAM_EFL_USE_EFL1          TRUE

#endif /* MCUCONF_H */
