/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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
 * @file    CT/sn32_ct.h
 * @brief   SN32 CT units common header.
 * @note    This file requires definitions from the SN32 header file.
 *
 * @{
 */

#ifndef SN32_CT_H
#define SN32_CT_H

#include <SN32F2xx.h>
#include "CT16.h"
#include "CT16B0.h"
#include "CT16B1.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    CT units references
 * @{
 */
#define SN32_CT16B0       ((sn32_ct_t *)SN_CT16B0_BASE)
#define SN32_CT16B1       ((sn32_ct_t *)SN_CT16B1_BASE)
#if defined(SN32F240B)
#define SN32_CT16B1_CHANNELS        24
#elif defined(SN32F260)
#define SN32_CT16B1_CHANNELS        23
#else
#error "CT not supported in the selected device"
#endif
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

/**
 * @brief   SN32 CT registers block.
 * @note    This is the most general known form, not all timers have
 *          necessarily all registers and bits.
 */
typedef struct {                                   /*!< (@ 0x40002000) SN_CT16Bn Structure                                        */
    volatile uint32_t TMRCTRL;                     /*!< (@ 0x00000000) Offset:0x00 CT16Bn Timer Control Register                  */
    volatile uint32_t TC;                          /*!< (@ 0x00000004) Offset:0x04 CT16Bn Timer Counter Register                  */
    volatile uint32_t PRE;                         /*!< (@ 0x00000008) Offset:0x08 CT16Bn Prescale Register                       */
    volatile uint32_t PC;                          /*!< (@ 0x0000000C) Offset:0x0C CT16Bn Prescale Counter Register               */
    volatile uint32_t CNTCTRL;                     /*!< (@ 0x00000010) Offset:0x10 CT16Bn Counter Control Register                */
    volatile uint32_t MCTRL;                       /*!< (@ 0x00000014) Offset:0x14 CT16Bn Match Control Register                  */
    volatile uint32_t MCTRL2;                      /*!< (@ 0x00000018) Offset:0x18 CT16Bn Match Control Register 2                */
    volatile uint32_t MCTRL3;                      /*!< (@ 0x0000001C) Offset:0x1C CT16Bn Match Control Register 3                */
    volatile uint32_t MR0;                         /*!< (@ 0x00000020) Offset:0x20 CT16Bn MR0 Register                            */
    volatile uint32_t MR1;                         /*!< (@ 0x00000024) Offset:0x24 CT16Bn MR1 Register                            */
    volatile uint32_t MR2;                         /*!< (@ 0x00000028) Offset:0x28 CT16Bn MR2 Register                            */
    volatile uint32_t MR3;                         /*!< (@ 0x0000002C) Offset:0x2C CT16Bn MR3 Register                            */
    volatile uint32_t MR4;                         /*!< (@ 0x00000030) Offset:0x30 CT16Bn MR4 Register                            */
    volatile uint32_t MR5;                         /*!< (@ 0x00000034) Offset:0x34 CT16Bn MR5 Register                            */
    volatile uint32_t MR6;                         /*!< (@ 0x00000038) Offset:0x38 CT16Bn MR6 Register                            */
    volatile uint32_t MR7;                         /*!< (@ 0x0000003C) Offset:0x3C CT16Bn MR7 Register                            */
    volatile uint32_t MR8;                         /*!< (@ 0x00000040) Offset:0x40 CT16Bn MR8 Register                            */
    volatile uint32_t MR9;                         /*!< (@ 0x00000044) Offset:0x44 CT16Bn MR9 Register                            */
    volatile uint32_t MR10;                        /*!< (@ 0x00000048) Offset:0x48 CT16Bn MR10 Register                           */
    volatile uint32_t MR11;                        /*!< (@ 0x0000004C) Offset:0x4C CT16Bn MR11 Register                           */
    volatile uint32_t MR12;                        /*!< (@ 0x00000050) Offset:0x50 CT16Bn MR12 Register                           */
    volatile uint32_t MR13;                        /*!< (@ 0x00000054) Offset:0x54 CT16Bn MR13 Register                           */
    volatile uint32_t MR14;                        /*!< (@ 0x00000058) Offset:0x58 CT16Bn MR14 Register                           */
    volatile uint32_t MR15;                        /*!< (@ 0x0000005C) Offset:0x5C CT16Bn MR15 Register                           */
    volatile uint32_t MR16;                        /*!< (@ 0x00000060) Offset:0x60 CT16Bn MR16 Register                           */
    volatile uint32_t MR17;                        /*!< (@ 0x00000064) Offset:0x64 CT16Bn MR17 Register                           */
    volatile uint32_t MR18;                        /*!< (@ 0x00000068) Offset:0x68 CT16Bn MR18 Register                           */
    volatile uint32_t MR19;                        /*!< (@ 0x0000006C) Offset:0x6C CT16Bn MR19 Register                           */
    volatile uint32_t MR20;                        /*!< (@ 0x00000070) Offset:0x70 CT16Bn MR20 Register                           */
    volatile uint32_t MR21;                        /*!< (@ 0x00000074) Offset:0x74 CT16Bn MR21 Register                           */
    volatile uint32_t MR22;                        /*!< (@ 0x00000078) Offset:0x78 CT16Bn MR22 Register                           */
    volatile uint32_t MR23;                        /*!< (@ 0x0000007C) Offset:0x7C CT16Bn MR23 Register                           */
    volatile uint32_t MR24;                        /*!< (@ 0x00000080) Offset:0x80 CT16Bn MR24 Register                           */
    volatile uint32_t CAP0;                        /*!< (@ 0x00000084) Offset:0x84 CT16Bn CAP0 Register                           */
    volatile uint32_t EM;                          /*!< (@ 0x00000088) Offset:0x88 CT16Bn External Match Register                 */
    volatile uint32_t EMC;                         /*!< (@ 0x0000008C) Offset:0x8C CT16Bn External Match Control register         */
    volatile uint32_t EMC2;                        /*!< (@ 0x00000090) Offset:0x90 CT16Bn External Match Control register 2       */
    volatile uint32_t PWMCTRL;                     /*!< (@ 0x00000094) Offset:0x94 CT16Bn PWM Control Register                    */
    volatile uint32_t PWMCTRL2;                    /*!< (@ 0x00000098) Offset:0x98 CT16Bn PWM Control Register 2                  */
    volatile uint32_t PWMENB;                      /*!< (@ 0x0000009C) Offset:0x9C CT16Bn PWM Enable register                     */
    volatile uint32_t PWMIOENB;                    /*!< (@ 0x000000A0) Offset:0xA0 CT16Bn PWM IO Enable register                  */
    volatile uint32_t RIS;                         /*!< (@ 0x000000A4) Offset:0xA4 CT16Bn Raw Interrupt Status Register           */
    volatile uint32_t IC;                          /*!< (@ 0x000000A8) Offset:0xA8 CT16Bn Interrupt Clear Register                */
} sn32_ct_t;                                       /*!< Size = 172 (0xac)                                                         */

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#endif /* SN32_CT_H */

/** @} */
