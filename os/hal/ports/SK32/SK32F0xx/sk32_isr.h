/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    Copyright (C) 2026 QMK

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
 * @file    SK32F0xx/sk32_isr.h
 * @brief   SK32F0xx ISR handler header.
 * @details The peripheral specific interrupt handlers of this port are
 *          implemented inside the low level drivers that own the unit
 *          (USART handlers live in the serial driver, the USB handler in
 *          the USB driver and so on), only the EXTI handlers shared by the
 *          PAL subsystem are aggregated in the file @p sk32_isr.c.
 *
 * @addtogroup SK32F0xx_ISR
 * @{
 */

#ifndef SK32_ISR_H
#define SK32_ISR_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   EXTI0..1 interrupt priority level setting.
 */
#if !defined(SK32_IRQ_EXTI0_1_PRIORITY) || defined(__DOXYGEN__)
#define SK32_IRQ_EXTI0_1_PRIORITY           3
#endif

/**
 * @brief   EXTI2..3 interrupt priority level setting.
 */
#if !defined(SK32_IRQ_EXTI2_3_PRIORITY) || defined(__DOXYGEN__)
#define SK32_IRQ_EXTI2_3_PRIORITY           3
#endif

/**
 * @brief   EXTI4..15 interrupt priority level setting.
 */
#if !defined(SK32_IRQ_EXTI4_15_PRIORITY) || defined(__DOXYGEN__)
#define SK32_IRQ_EXTI4_15_PRIORITY          3
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* IRQ priority checks.*/
#if !OSAL_IRQ_IS_VALID_PRIORITY(SK32_IRQ_EXTI0_1_PRIORITY)
#error "Invalid IRQ priority assigned to SK32_IRQ_EXTI0_1_PRIORITY"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(SK32_IRQ_EXTI2_3_PRIORITY)
#error "Invalid IRQ priority assigned to SK32_IRQ_EXTI2_3_PRIORITY"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(SK32_IRQ_EXTI4_15_PRIORITY)
#error "Invalid IRQ priority assigned to SK32_IRQ_EXTI4_15_PRIORITY"
#endif

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
  void irqInit(void);
  void irqDeinit(void);
#ifdef __cplusplus
}
#endif

#endif /* SK32_ISR_H */

/** @} */
