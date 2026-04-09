/*
    Copyright (C) 2019 /u/KeepItUnder

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
 * @file    NUC126/nuc126_isr.h
 * @brief   ISR remapper driver header.
 *
 * @addtogroup NUC126_ISR
 * @{
 */

#ifndef NUC126_ISR_H
#define NUC126_ISR_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    ISR names and numbers remapping
 * @{
 */

// TODO Add other units as necessary

/*
 * GPIO units.
 */
#define NUC126_GPIOAB_HANDLER        Vector50
#define NUC126_GPIOCDEF_HANDLER      Vector54

#define NUC126_GPIOAB_NUMBER         GPAB_IRQn
#define NUC126_GPIOCDEF_NUMBER       GPCDEF_IRQn

/*
 * Special ST unit
 */
#define NUC126_ST_HANDLER            Vector3C
#define NUC126_ST_NUMBER             SysTick_IRQn

/*
 * DMA units.
 */
#define NUC126_PDMA_HANDLER          VectorA8
#define NUC126_PDMA_NUMBER           PDMA_IRQn

/*
 * ADC units.
 */
#define NUC126_ADC_HANDLER          VectorB4
#define NUC126_ADC_NUMBER           ADC_IRQn

/*
 * PWM units.
 */
#define NUC126_PWM0_HANDLER         Vector58
#define NUC126_PWM1_HANDLER         Vector5C

#define NUC126_PWM0_NUMBER          PWM0_IRQn
#define NUC126_PWM1_NUMBER          PWM1_IRQn

/*
 * SPI units.
 */
#define NUC126_SPI0_HANDLER          Vector78
#define NUC126_SPI1_HANDLER          Vector7C

#define NUC126_SPI0_NUMBER           SPI0_IRQn
#define NUC126_SPI1_NUMBER           SPI1_IRQn

/*
 * I2C units.
 */
#define NUC126_I2C0_HANDLER   Vector88
#define NUC126_I2C0_NUMBER    I2C0_IRQn

#define NUC126_I2C1_HANDLER   Vector8C
#define NUC126_I2C1_NUMBER    I2C1_IRQn

/*
 * TIM units.
 */
#define NUC126_TIM1_HANDLER          Vector60
#define NUC126_TIM2_HANDLER          Vector64
#define NUC126_TIM3_HANDLER          Vector68
#define NUC126_TIM4_HANDLER          Vector6C

#define NUC126_TIM1_NUMBER           TMR0_IRQn
#define NUC126_TIM2_NUMBER           TMR1_IRQn
#define NUC126_TIM3_NUMBER           TMR2_IRQn
#define NUC126_TIM4_NUMBER           TMR3_IRQn

/*
 * UART units.
 */
#define NUC126_UART02_HANDLER        Vector70
#define NUC126_UART1_HANDLER         Vector74

#define NUC126_UART02_NUMBER         UART02_IRQn
#define NUC126_UART1_NUMBER          UART1_IRQn

/*
 * USB units.
 */
#define NUC126_USB1_HANDLER          Vector9C
#define NUC126_USB1_NUMBER           USBD_IRQn

#define USBD_INTSTS_EPEVT_Pos        USBD_INTSTS_EPEVT0_Pos
#define USBD_INTSTS_EPEVT_Msk        (0xFFul << USBD_INTSTS_EPEVT_Pos)
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#endif /* NUC126_ISR_H */

/** @} */

