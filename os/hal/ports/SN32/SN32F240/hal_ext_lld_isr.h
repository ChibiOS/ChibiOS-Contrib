/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

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
 * @file    SN32F0xx/hal_ext_lld_isr.h
 * @brief   SN32F0xx EXT subsystem low level driver ISR header.
 *
 * @addtogroup EXT
 * @{
 */

#ifndef HAL_EXT_LLD_ISR_H
#define HAL_EXT_LLD_ISR_H

#if HAL_USE_EXT || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    ISR names and numbers remapping
 * @{
 */

/*
 * GPIO units.
 */

#define SN32_GPIOAB_HANDLER        Vector50
#define SN32_GPIOCDF_HANDLER       Vector54

#define SN32_GPIOAB_NUMBER         GPAB_IRQn
#define SN32_GPIOCDF_NUMBER        GPCDF_IRQn

/*
 * Special ST unit
 */
#define SN32_ST_HANDLER            Vector3C
#define SN32_ST_NUMBER             SysTick_IRQn

/*
 * DMA units.
 */
#define SN32_PDMA_HANDLER          VectorA8
#define SN32_PDMA_NUMBER           PDMA_IRQn

/*
 * ADC units.
 */
#define SN32_ADC_HANDLER          VectorB0
#define SN32_ADC_NUMBER           ADC_IRQn

/*
 * PWM units.
 */
#define SN32_PWMA_HANDLER         Vector58
#define SN32_PWMA_NUMBER          PWMA_IRQn

/*
 * SPI units.
 */
#define SN32_SPI0_HANDLER          Vector78
#define SN32_SPI1_HANDLER          Vector7C
#define SN32_SPI2_HANDLER          Vector80

#define SN32_SPI0_NUMBER           SPI0_IRQn
#define SN32_SPI1_NUMBER           SPI1_IRQn
#define SN32_SPI2_NUMBER           SPI2_IRQn

/*
 * I2S units.
 */
#define SN32_I2C1_HANDLER         VectorB8
#define SN32_I2C1_NUMBER          I2S_IRQn

/*
 * I2C units.
 */
#define SN32_I2C1_GLOBAL_HANDLER   Vector88
#define SN32_I2C1_GLOBAL_NUMBER    I2C0_IRQn

#define SN32_I2C2_GLOBAL_HANDLER   Vector8C
#define SN32_I2C2_GLOBAL_NUMBER    I2C1_IRQn

/*
 * TIM units.
 */
#define SN32_TIM1_HANDLER          Vector60
#define SN32_TIM2_HANDLER          Vector64
#define SN32_TIM3_HANDLER          Vector68
#define SN32_TIM4_HANDLER          Vector6C

#define SN32_TIM1_NUMBER           TMR0_IRQn
#define SN32_TIM2_NUMBER           TMR1_IRQn
#define SN32_TIM3_NUMBER           TMR2_IRQn
#define SN32_TIM4_NUMBER           TMR3_IRQn

/*
 * USART units.
 */
#define SN32_USART1_HANDLER        Vector70
#define SN32_USART2_HANDLER        Vector74

#define SN32_USART1_NUMBER         UART0_IRQn
#define SN32_USART2_NUMBER         UART1_IRQn

/*
 * USB units.
 */
#define SN32_USB1_HANDLER          Vector9C
#define SN32_USB1_NUMBER           USBD_IRQn

#define USBD_INTSTS_EPEVT_Pos        USBD_INTSTS_EPEVT0_Pos
#define USBD_INTSTS_EPEVT_Msk        (0xFFul << USBD_INTSTS_EPEVT_Pos)

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

#ifdef __cplusplus
extern "C" {
#endif
  void ext_lld_exti_irq_enable(void);
  void ext_lld_exti_irq_disable(void);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_EXT */

#endif /* HAL_EXT_LLD_ISR_H */

/** @} */
