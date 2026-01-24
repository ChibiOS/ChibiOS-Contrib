/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2025 HorrorTroll
    ChibiOS - Copyright (C) 2023..2025 Zhaqian

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
 * @file    USARTv2/at32_usart.h
 * @brief   AT32 USART helpers header.
 *
 * @addtogroup AT32_
 * @{
 */

#ifndef AT32_USART_H
#define AT32_USART_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    CTRL1 register additional macros
 * @{
 */
#define USART_CTRL1_DATA7                   (USART_CTRL1_DBN1)
#define USART_CTRL1_DATA8                   (0U)
#define USART_CTRL1_DATA9                   (USART_CTRL1_DBN0)
/** @} */

/**
 * @name    CTRL2 register additional macros
 * @{
 */
#define USART_CTRL2_STOPBN1_BITS            (0U << 12)
#define USART_CTRL2_STOPBN0P5_BITS          (1U << 12)
#define USART_CTRL2_STOPBN2_BITS            (2U << 12)
#define USART_CTRL2_STOPBN1P5_BITS          (3U << 12)
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

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* AT32_USART_H */

/** @} */
