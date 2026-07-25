/*
    Copyright (C) 2019 /u/KeepItUnder
    Modifications copyright (C) 2026 Belonit

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
 * @file    M251/m251_isr.h
 * @brief   ISR remapper driver header.
 *
 * @addtogroup M251_ISR
 * @{
 */

#ifndef M251_ISR_H
#define M251_ISR_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    ISR names and numbers remapping
 * @{
 */

/*
 * System handlers.
 */
#define M251_ST_HANDLER                     SysTick_Handler
#define M251_ST_NUMBER                      SysTick_IRQn

/*
 * Brown-out, clock, RTC, watchdog and wakeup units.
 */
#define M251_BOD_HANDLER                    Vector40
#define M251_IRCTRIM_HANDLER                Vector44
#define M251_PWRWU_HANDLER                  Vector48
#define M251_CLKFAIL_HANDLER                Vector50
#define M251_RTC_HANDLER                    Vector58
#define M251_TAMPER_HANDLER                 Vector5C
#define M251_WDT_HANDLER                    Vector60
#define M251_WWDT_HANDLER                   Vector64

#define M251_BOD_NUMBER                     BOD_IRQn
#define M251_IRCTRIM_NUMBER                 IRCTRIM_IRQn
#define M251_PWRWU_NUMBER                   PWRWU_IRQn
#define M251_CLKFAIL_NUMBER                 CLKFAIL_IRQn
#define M251_RTC_NUMBER                     RTC_IRQn
#define M251_TAMPER_NUMBER                  TAMPER_IRQn
#define M251_WDT_NUMBER                     WDT_IRQn
#define M251_WWDT_NUMBER                    WWDT_IRQn

/*
 * External interrupt units.
 */
#define M251_EINT0_HANDLER                  Vector68
#define M251_EINT1_HANDLER                  Vector6C
#define M251_EINT2_HANDLER                  Vector70
#define M251_EINT3_HANDLER                  Vector74
#define M251_EINT4_HANDLER                  Vector78
#define M251_EINT5_HANDLER                  Vector7C

#define M251_EINT0_NUMBER                   EINT0_IRQn
#define M251_EINT1_NUMBER                   EINT1_IRQn
#define M251_EINT2_NUMBER                   EINT2_IRQn
#define M251_EINT3_NUMBER                   EINT3_IRQn
#define M251_EINT4_NUMBER                   EINT4_IRQn
#define M251_EINT5_NUMBER                   EINT5_IRQn

/*
 * GPIO units.
 */
#define M251_GPA_HANDLER                    Vector80
#define M251_GPB_HANDLER                    Vector84
#define M251_GPC_HANDLER                    Vector88
#define M251_GPD_HANDLER                    Vector8C
#define M251_GPE_HANDLER                    Vector90
#define M251_GPF_HANDLER                    Vector94

#define M251_GPA_NUMBER                     GPA_IRQn
#define M251_GPB_NUMBER                     GPB_IRQn
#define M251_GPC_NUMBER                     GPC_IRQn
#define M251_GPD_NUMBER                     GPD_IRQn
#define M251_GPE_NUMBER                     GPE_IRQn
#define M251_GPF_NUMBER                     GPF_IRQn

/*
 * QSPI/SPI/USCI units.
 */
#define M251_QSPI0_HANDLER                  Vector98
#define M251_SPI0_HANDLER                   Vector9C
#define M251_USCI0_HANDLER                  Vector108
#define M251_SPI1_HANDLER                   Vector10C
#define M251_USCI1_HANDLER                  Vector110
#define M251_USCI2_HANDLER                  Vector130

#define M251_QSPI0_NUMBER                   QSPI0_IRQn
#define M251_SPI0_NUMBER                    SPI0_IRQn
#define M251_USCI0_NUMBER                   USCI0_IRQn
#define M251_SPI1_NUMBER                    SPI1_IRQn
#define M251_USCI1_NUMBER                   USCI1_IRQn
#define M251_USCI2_NUMBER                   USCI2_IRQn

/*
 * PWM/BPWM units.
 */
#define M251_BRAKE0_HANDLER                 VectorA0
#define M251_PWM0_P0_HANDLER                VectorA4
#define M251_PWM0_P1_HANDLER                VectorA8
#define M251_PWM0_P2_HANDLER                VectorAC
#define M251_BRAKE1_HANDLER                 VectorB0
#define M251_PWM1_P0_HANDLER                VectorB4
#define M251_PWM1_P1_HANDLER                VectorB8
#define M251_PWM1_P2_HANDLER                VectorBC
#define M251_BPWM0_HANDLER                  VectorF4
#define M251_BPWM1_HANDLER                  Vector118

#define M251_BRAKE0_NUMBER                  BRAKE0_IRQn
#define M251_PWM0_P0_NUMBER                 PWM0_P0_IRQn
#define M251_PWM0_P1_NUMBER                 PWM0_P1_IRQn
#define M251_PWM0_P2_NUMBER                 PWM0_P2_IRQn
#define M251_BRAKE1_NUMBER                  BRAKE1_IRQn
#define M251_PWM1_P0_NUMBER                 PWM1_P0_IRQn
#define M251_PWM1_P1_NUMBER                 PWM1_P1_IRQn
#define M251_PWM1_P2_NUMBER                 PWM1_P2_IRQn
#define M251_BPWM0_NUMBER                   BPWM0_IRQn
#define M251_BPWM1_NUMBER                   BPWM1_IRQn

/*
 * Timer units.
 */
#define M251_TMR0_HANDLER                   VectorC0
#define M251_TMR1_HANDLER                   VectorC4
#define M251_TMR2_HANDLER                   VectorC8
#define M251_TMR3_HANDLER                   VectorCC

#define M251_TMR0_NUMBER                    TMR0_IRQn
#define M251_TMR1_NUMBER                    TMR1_IRQn
#define M251_TMR2_NUMBER                    TMR2_IRQn
#define M251_TMR3_NUMBER                    TMR3_IRQn

/*
 * UART and I2C units.
 */
#define M251_UART0_HANDLER                  VectorD0
#define M251_UART1_HANDLER                  VectorD4
#define M251_I2C0_HANDLER                   VectorD8
#define M251_I2C1_HANDLER                   VectorDC
#define M251_UART2_HANDLER                  Vector100
#define M251_UART3_HANDLER                  Vector104

#define M251_UART0_NUMBER                   UART0_IRQn
#define M251_UART1_NUMBER                   UART1_IRQn
#define M251_I2C0_NUMBER                    I2C0_IRQn
#define M251_I2C1_NUMBER                    I2C1_IRQn
#define M251_UART2_NUMBER                   UART2_IRQn
#define M251_UART3_NUMBER                   UART3_IRQn

/*
 * PDMA, analog, crypto, smart card, PSIO, LCD, OPA and touch key units.
 */
#define M251_PDMA_HANDLER                   VectorE0
#define M251_DAC_HANDLER                    VectorE4
#define M251_EADC_INT0_HANDLER              VectorE8
#define M251_EADC_INT1_HANDLER              VectorEC
#define M251_ACMP01_HANDLER                 VectorF0
#define M251_EADC_INT2_HANDLER              VectorF8
#define M251_EADC_INT3_HANDLER              VectorFC
#define M251_PSIO_HANDLER                   Vector11C
#define M251_CRPT_HANDLER                   Vector124
#define M251_SC0_HANDLER                    Vector128
#define M251_LCD_HANDLER                    Vector134
#define M251_OPA_HANDLER                    Vector138
#define M251_TK_HANDLER                     Vector13C

#define M251_PDMA_NUMBER                    PDMA_IRQn
#define M251_DAC_NUMBER                     DAC_IRQn
#define M251_EADC_INT0_NUMBER               EADC_INT0_IRQn
#define M251_EADC_INT1_NUMBER               EADC_INT1_IRQn
#define M251_ACMP01_NUMBER                  ACMP01_IRQn
#define M251_EADC_INT2_NUMBER               EADC_INT2_IRQn
#define M251_EADC_INT3_NUMBER               EADC_INT3_IRQn
#define M251_PSIO_NUMBER                    PSIO_IRQn
#define M251_CRPT_NUMBER                    CRPT_IRQn
#define M251_SC0_NUMBER                     SC0_IRQn
#define M251_LCD_NUMBER                     LCD_IRQn
#define M251_OPA_NUMBER                     OPA_IRQn
#define M251_TK_NUMBER                      TK_IRQn

/*
 * USB device unit.
 */
#define M251_USBD_HANDLER                   Vector114
#define M251_USBD_NUMBER                    USBD_IRQn
/** @} */

#endif /* M251_ISR_H */

/** @} */
