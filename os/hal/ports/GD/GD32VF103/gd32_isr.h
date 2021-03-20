/*
    ChibiOS - Copyright (C) 2021 Stefan Kerkmann 

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
 * @file    GD32VF103/gd32_isr.h
 * @brief   GD32VF103 ISR handler header.
 *
 * @addtogroup GD32VF103_ISR
 * @{
 */

#ifndef GD32_ISR_H
#define GD32_ISR_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    ISR names and numbers remapping
 * @{
 */
/*
 * CAN units.
 */
#define GD32_CAN0_TX_HANDLER       vector38
#define GD32_CAN0_RX0_HANDLER      vector39
#define GD32_CAN0_RX1_HANDLER      vector40
#define GD32_CAN0_EWMC_HANDLER     vector41
#define GD32_CAN1_TX_HANDLER       vector82
#define GD32_CAN1_RX0_HANDLER      vector83
#define GD32_CAN1_RX1_HANDLER      vector84
#define GD32_CAN1_EWMC_HANDLER     vector85

#define GD32_CAN0_TX_NUMBER        38
#define GD32_CAN0_RX0_NUMBER       39
#define GD32_CAN0_RX1_NUMBER       40
#define GD32_CAN0_EWMC_NUMBER      41
#define GD32_CAN1_TX_NUMBER        82
#define GD32_CAN1_RX0_NUMBER       83
#define GD32_CAN1_RX1_NUMBER       84
#define GD32_CAN1_EWMC_NUMBER      85

/*
 * I2C units.
 */
#define GD32_I2C1_EVENT_HANDLER    vector50
#define GD32_I2C1_ERROR_HANDLER    vector51
#define GD32_I2C1_EVENT_NUMBER     50
#define GD32_I2C1_ERROR_NUMBER     51

#define GD32_I2C2_EVENT_HANDLER    vector52
#define GD32_I2C2_ERROR_HANDLER    vector53
#define GD32_I2C2_EVENT_NUMBER     52
#define GD32_I2C2_ERROR_NUMBER     53

/*
 * TIM units.
 */
#define GD32_TIM1_UP_HANDLER       vector44
#define GD32_TIM1_CC_HANDLER       vector46
#define GD32_TIM2_HANDLER          vector47
#define GD32_TIM3_HANDLER          vector48
#define GD32_TIM4_HANDLER          vector49
#define GD32_TIM5_HANDLER          vector69
#define GD32_TIM6_HANDLER          vector73
#define GD32_TIM7_HANDLER          vector74

#define GD32_TIM1_UP_NUMBER        44
#define GD32_TIM1_CC_NUMBER        46
#define GD32_TIM2_NUMBER           47
#define GD32_TIM3_NUMBER           48
#define GD32_TIM4_NUMBER           49
#define GD32_TIM5_NUMBER           69
#define GD32_TIM6_NUMBER           73
#define GD32_TIM7_NUMBER           74

/*
 * USART units.
 */
#define GD32_USART1_HANDLER        vector56
#define GD32_USART2_HANDLER        vector57
#define GD32_USART3_HANDLER        vector58
#define GD32_UART4_HANDLER         vector71
#define GD32_UART5_HANDLER         vector72

#define GD32_USART1_NUMBER         56
#define GD32_USART2_NUMBER         57
#define GD32_USART3_NUMBER         58
#define GD32_UART4_NUMBER          71
#define GD32_UART5_NUMBER          72

/*
 * OTG units.
 */
#define GD32_OTG1_HANDLER          vector86
#define GD32_OTG1_NUMBER           86

/*
 * RTC unit
 */
#define GD32_RTC1_HANDLER          vector22
#define GD32_RTC1_NUMBER           22
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   EXTI0 interrupt priority level setting.
 */
#if !defined(GD32_IRQ_EXTI0_PRIORITY) || defined(__DOXYGEN__)
#define GD32_IRQ_EXTI0_PRIORITY            6
#endif

/**
 * @brief   EXTI1 interrupt priority level setting.
 */
#if !defined(GD32_IRQ_EXTI1_PRIORITY) || defined(__DOXYGEN__)
#define GD32_IRQ_EXTI1_PRIORITY            6
#endif

/**
 * @brief   EXTI2 interrupt priority level setting.
 */
#if !defined(GD32_IRQ_EXTI2_PRIORITY) || defined(__DOXYGEN__)
#define GD32_IRQ_EXTI2_PRIORITY            6
#endif

/**
 * @brief   EXTI3 interrupt priority level setting.
 */
#if !defined(GD32_IRQ_EXTI3_PRIORITY) || defined(__DOXYGEN__)
#define GD32_IRQ_EXTI3_PRIORITY            6
#endif

/**
 * @brief   EXTI4 interrupt priority level setting.
 */
#if !defined(GD32_IRQ_EXTI4_PRIORITY) || defined(__DOXYGEN__)
#define GD32_IRQ_EXTI4_PRIORITY            6
#endif

/**
 * @brief   EXTI9..5 interrupt priority level setting.
 */
#if !defined(GD32_IRQ_EXTI5_9_PRIORITY) || defined(__DOXYGEN__)
#define GD32_IRQ_EXTI5_9_PRIORITY          6
#endif

/**
 * @brief   EXTI15..10 interrupt priority level setting.
 */
#if !defined(GD32_IRQ_EXTI10_15_PRIORITY) || defined(__DOXYGEN__)
#define GD32_IRQ_EXTI10_15_PRIORITY        6
#endif

/**
 * @brief   EXTI16 interrupt priority level setting.
 */
#if !defined(GD32_IRQ_EXTI16_PRIORITY) || defined(__DOXYGEN__)
#define GD32_IRQ_EXTI16_PRIORITY           6
#endif

/**
 * @brief   EXTI17 interrupt priority level setting.
 */
#if !defined(GD32_IRQ_EXTI17_PRIORITY) || defined(__DOXYGEN__)
#define GD32_IRQ_EXTI17_PRIORITY           6
#endif

/**
 * @brief   EXTI18 interrupt priority level setting.
 */
#if !defined(GD32_IRQ_EXTI18_PRIORITY) || defined(__DOXYGEN__)
#define GD32_IRQ_EXTI18_PRIORITY           6
#endif

/**
 * @brief   EXTI19 interrupt priority level setting.
 */
#if !defined(GD32_IRQ_EXTI19_PRIORITY) || defined(__DOXYGEN__)
#define GD32_IRQ_EXTI19_PRIORITY           6
#endif
/** @} */

#define __ECLIC_PRESENT 1

#include "nmsis_core.h"

#define ECLIC_TRIGGER_DEFAULT             ECLIC_POSTIVE_EDGE_TRIGGER
#define ECLIC_DMA_TRIGGER                 ECLIC_TRIGGER_DEFAULT

#define GD32_CAN_CAN1_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_CAN_CAN2_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_CAN_CAN3_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM10_IRQ_TRIGGER       ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM11_IRQ_TRIGGER       ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM12_IRQ_TRIGGER       ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM13_IRQ_TRIGGER       ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM14_IRQ_TRIGGER       ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM1_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM21_IRQ_TRIGGER       ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM22_IRQ_TRIGGER       ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM2_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM3_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM4_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM5_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM6_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM7_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM8_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_GPT_TIM9_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_I2C_I2C1_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_I2C_I2C2_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_I2C_I2C3_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_ICU_TIM1_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_ICU_TIM2_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_ICU_TIM3_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_ICU_TIM4_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_ICU_TIM5_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_ICU_TIM8_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_EXTI0_TRIGGER           ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_EXTI10_15_TRIGGER       ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_EXTI1_TRIGGER           ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_EXTI2_TRIGGER           ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_EXTI3_TRIGGER           ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_EXTI4_TRIGGER           ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_EXTI5_9_TRIGGER         ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM14_TRIGGER           ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM15_TRIGGER           ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM16_TRIGGER           ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM17_TRIGGER           ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM1_CC_TRIGGER         ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM1_UP_TRIGGER         ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM20_CC_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM20_UP_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM21_TRIGGER           ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM22_TRIGGER           ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM2_TRIGGER            ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM3_TRIGGER            ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM4_TRIGGER            ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM5_TRIGGER            ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM6_TRIGGER            ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM7_TRIGGER            ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM8_CC_TRIGGER         ECLIC_TRIGGER_DEFAULT
#define GD32_IRQ_TIM8_UP_TRIGGER         ECLIC_TRIGGER_DEFAULT
#define GD32_PWM_TIM1_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_PWM_TIM2_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_PWM_TIM3_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_PWM_TIM4_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_PWM_TIM5_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_PWM_TIM8_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_RTC_IRQ_TRIGGER             ECLIC_TRIGGER_DEFAULT
#define GD32_SDC_SDIO_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_SERIAL_UART4_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_SERIAL_UART5_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_SERIAL_UART7_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_SERIAL_UART8_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_SERIAL_USART1_TRIGGER       ECLIC_TRIGGER_DEFAULT
#define GD32_SERIAL_USART2_TRIGGER       ECLIC_TRIGGER_DEFAULT
#define GD32_SERIAL_USART3_TRIGGER       ECLIC_TRIGGER_DEFAULT
#define GD32_SERIAL_USART6_TRIGGER       ECLIC_TRIGGER_DEFAULT
#define GD32_ST_IRQ_TRIGGER              ECLIC_TRIGGER_DEFAULT
#define GD32_UART_UART4_IRQ_TRIGGER      ECLIC_TRIGGER_DEFAULT
#define GD32_UART_UART5_IRQ_TRIGGER      ECLIC_TRIGGER_DEFAULT
#define GD32_UART_UART7_IRQ_TRIGGER      ECLIC_TRIGGER_DEFAULT
#define GD32_UART_UART8_IRQ_TRIGGER      ECLIC_TRIGGER_DEFAULT
#define GD32_UART_USART1_IRQ_TRIGGER     ECLIC_TRIGGER_DEFAULT
#define GD32_UART_USART2_IRQ_TRIGGER     ECLIC_TRIGGER_DEFAULT
#define GD32_UART_USART3_IRQ_TRIGGER     ECLIC_TRIGGER_DEFAULT
#define GD32_UART_USART6_IRQ_TRIGGER     ECLIC_TRIGGER_DEFAULT
#define GD32_USB_OTG1_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT
#define GD32_USB_OTG2_IRQ_TRIGGER        ECLIC_TRIGGER_DEFAULT

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
  void irqInit(void);
  void irqDeinit(void);
#ifdef __cplusplus
}
#endif

#endif /* GD32_ISR_H */

/** @} */
