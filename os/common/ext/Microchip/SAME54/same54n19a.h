/*
 * Header file for ATSAME54N19A
 *
 * Copyright (c) 2024 Microchip Technology Inc. and its subsidiaries.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/* File generated from device description file (ATDF) version 2023-03-17T09:50:05Z */
#ifndef _SAME54N19A_H_
#define _SAME54N19A_H_

/* Header version uses Semantic Versioning 2.0.0 (https://semver.org/) */
#define HEADER_FORMAT_VERSION "2.1.1"

#define HEADER_FORMAT_VERSION_MAJOR (2)
#define HEADER_FORMAT_VERSION_MINOR (1)
#define HEADER_FORMAT_VERSION_PATCH (1)

/* SAME54N19A definitions
  This file defines all structures and symbols for SAME54N19A:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
*/

#ifdef __cplusplus
 extern "C" {
#endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  include <stdint.h>
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !defined(SKIP_INTEGER_LITERALS)
#  if defined(_UINT8_) || defined(_UINT16_) || defined(_UINT32_)
#    error "Integer constant value macros already defined elsewhere"
#  endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Macros that deal with sizes of integer constants for C/C++ */
#  define _UINT8_(x)   ((uint8_t)(x))    /* C code: 8-bits unsigned integer constant value */
#  define _UINT16_(x)  ((uint16_t)(x))   /* C code: 16-bits unsigned integer constant value */
#  define _UINT32_(x)  ((uint32_t)(x))   /* C code: 32-bits unsigned integer constant value */

#else /* Assembler */

#  define _UINT8_(x) x    /* Assembler: 8-bits unsigned integer constant value */
#  define _UINT16_(x) x   /* Assembler: 16-bits unsigned integer constant value */
#  define _UINT32_(x) x   /* Assembler: 32-bits unsigned integer constant value */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* SKIP_INTEGER_LITERALS */

/* ************************************************************************** */
/* CMSIS DEFINITIONS FOR SAME54N19A                                         */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Interrupt Number Definition */
typedef enum IRQn
{
/******  CORTEX-M4 Processor Exceptions Numbers ******************************/
  Reset_IRQn                = -15, /* -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn       = -14, /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn            = -13, /* -13 Hard Fault, all classes of Fault    */
  MemoryManagement_IRQn     = -12, /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn             = -11, /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  UsageFault_IRQn           = -10, /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  SVCall_IRQn               =  -5, /* -5  System Service Call via SVC instruction */
  DebugMonitor_IRQn         =  -4, /* -4  Debug Monitor                       */
  PendSV_IRQn               =  -2, /* -2  Pendable request for system service */
  SysTick_IRQn              =  -1, /* -1  System Tick Timer                   */

/******  SAME54N19A specific Interrupt Numbers ***********************************/
  PM_IRQn                   =   0, /* 0   Power Manager (PM)                  */
  MCLK_IRQn                 =   1, /* 1   Main Clock (MCLK)                   */
  OSCCTRL_XOSC0_IRQn        =   2, /* 2   Oscillators Control (OSCCTRL)       */
  OSCCTRL_XOSC1_IRQn        =   3, /* 3   Oscillators Control (OSCCTRL)       */
  OSCCTRL_DFLL_IRQn         =   4, /* 4   Oscillators Control (OSCCTRL)       */
  OSCCTRL_DPLL0_IRQn        =   5, /* 5   Oscillators Control (OSCCTRL)       */
  OSCCTRL_DPLL1_IRQn        =   6, /* 6   Oscillators Control (OSCCTRL)       */
  OSC32KCTRL_IRQn           =   7, /* 7   32kHz Oscillators Control (OSC32KCTRL) */
  SUPC_OTHER_IRQn           =   8, /* 8   Supply Controller (SUPC)            */
  SUPC_BODDET_IRQn          =   9, /* 9   Supply Controller (SUPC)            */
  WDT_IRQn                  =  10, /* 10  Watchdog Timer (WDT)                */
  RTC_IRQn                  =  11, /* 11  Real-Time Counter (RTC)             */
  EIC_EXTINT_0_IRQn         =  12, /* 12  External Interrupt Controller (EIC) */
  EIC_EXTINT_1_IRQn         =  13, /* 13  External Interrupt Controller (EIC) */
  EIC_EXTINT_2_IRQn         =  14, /* 14  External Interrupt Controller (EIC) */
  EIC_EXTINT_3_IRQn         =  15, /* 15  External Interrupt Controller (EIC) */
  EIC_EXTINT_4_IRQn         =  16, /* 16  External Interrupt Controller (EIC) */
  EIC_EXTINT_5_IRQn         =  17, /* 17  External Interrupt Controller (EIC) */
  EIC_EXTINT_6_IRQn         =  18, /* 18  External Interrupt Controller (EIC) */
  EIC_EXTINT_7_IRQn         =  19, /* 19  External Interrupt Controller (EIC) */
  EIC_EXTINT_8_IRQn         =  20, /* 20  External Interrupt Controller (EIC) */
  EIC_EXTINT_9_IRQn         =  21, /* 21  External Interrupt Controller (EIC) */
  EIC_EXTINT_10_IRQn        =  22, /* 22  External Interrupt Controller (EIC) */
  EIC_EXTINT_11_IRQn        =  23, /* 23  External Interrupt Controller (EIC) */
  EIC_EXTINT_12_IRQn        =  24, /* 24  External Interrupt Controller (EIC) */
  EIC_EXTINT_13_IRQn        =  25, /* 25  External Interrupt Controller (EIC) */
  EIC_EXTINT_14_IRQn        =  26, /* 26  External Interrupt Controller (EIC) */
  EIC_EXTINT_15_IRQn        =  27, /* 27  External Interrupt Controller (EIC) */
  FREQM_IRQn                =  28, /* 28  Frequency Meter (FREQM)             */
  NVMCTRL_0_IRQn            =  29, /* 29  Non-Volatile Memory Controller (NVMCTRL) */
  NVMCTRL_1_IRQn            =  30, /* 30  Non-Volatile Memory Controller (NVMCTRL) */
  DMAC_0_IRQn               =  31, /* 31  Direct Memory Access Controller (DMAC) */
  DMAC_1_IRQn               =  32, /* 32  Direct Memory Access Controller (DMAC) */
  DMAC_2_IRQn               =  33, /* 33  Direct Memory Access Controller (DMAC) */
  DMAC_3_IRQn               =  34, /* 34  Direct Memory Access Controller (DMAC) */
  DMAC_OTHER_IRQn           =  35, /* 35  Direct Memory Access Controller (DMAC) */
  EVSYS_0_IRQn              =  36, /* 36  Event System Interface (EVSYS)      */
  EVSYS_1_IRQn              =  37, /* 37  Event System Interface (EVSYS)      */
  EVSYS_2_IRQn              =  38, /* 38  Event System Interface (EVSYS)      */
  EVSYS_3_IRQn              =  39, /* 39  Event System Interface (EVSYS)      */
  EVSYS_OTHER_IRQn          =  40, /* 40  Event System Interface (EVSYS)      */
  PAC_IRQn                  =  41, /* 41  Peripheral Access Controller (PAC)  */
  RAMECC_IRQn               =  45, /* 45  RAM ECC (RAMECC)                    */
  SERCOM0_0_IRQn            =  46, /* 46  Serial Communication Interface (SERCOM0) */
  SERCOM0_1_IRQn            =  47, /* 47  Serial Communication Interface (SERCOM0) */
  SERCOM0_2_IRQn            =  48, /* 48  Serial Communication Interface (SERCOM0) */
  SERCOM0_OTHER_IRQn        =  49, /* 49  Serial Communication Interface (SERCOM0) */
  SERCOM1_0_IRQn            =  50, /* 50  Serial Communication Interface (SERCOM1) */
  SERCOM1_1_IRQn            =  51, /* 51  Serial Communication Interface (SERCOM1) */
  SERCOM1_2_IRQn            =  52, /* 52  Serial Communication Interface (SERCOM1) */
  SERCOM1_OTHER_IRQn        =  53, /* 53  Serial Communication Interface (SERCOM1) */
  SERCOM2_0_IRQn            =  54, /* 54  Serial Communication Interface (SERCOM2) */
  SERCOM2_1_IRQn            =  55, /* 55  Serial Communication Interface (SERCOM2) */
  SERCOM2_2_IRQn            =  56, /* 56  Serial Communication Interface (SERCOM2) */
  SERCOM2_OTHER_IRQn        =  57, /* 57  Serial Communication Interface (SERCOM2) */
  SERCOM3_0_IRQn            =  58, /* 58  Serial Communication Interface (SERCOM3) */
  SERCOM3_1_IRQn            =  59, /* 59  Serial Communication Interface (SERCOM3) */
  SERCOM3_2_IRQn            =  60, /* 60  Serial Communication Interface (SERCOM3) */
  SERCOM3_OTHER_IRQn        =  61, /* 61  Serial Communication Interface (SERCOM3) */
  SERCOM4_0_IRQn            =  62, /* 62  Serial Communication Interface (SERCOM4) */
  SERCOM4_1_IRQn            =  63, /* 63  Serial Communication Interface (SERCOM4) */
  SERCOM4_2_IRQn            =  64, /* 64  Serial Communication Interface (SERCOM4) */
  SERCOM4_OTHER_IRQn        =  65, /* 65  Serial Communication Interface (SERCOM4) */
  SERCOM5_0_IRQn            =  66, /* 66  Serial Communication Interface (SERCOM5) */
  SERCOM5_1_IRQn            =  67, /* 67  Serial Communication Interface (SERCOM5) */
  SERCOM5_2_IRQn            =  68, /* 68  Serial Communication Interface (SERCOM5) */
  SERCOM5_OTHER_IRQn        =  69, /* 69  Serial Communication Interface (SERCOM5) */
  SERCOM6_0_IRQn            =  70, /* 70  Serial Communication Interface (SERCOM6) */
  SERCOM6_1_IRQn            =  71, /* 71  Serial Communication Interface (SERCOM6) */
  SERCOM6_2_IRQn            =  72, /* 72  Serial Communication Interface (SERCOM6) */
  SERCOM6_OTHER_IRQn        =  73, /* 73  Serial Communication Interface (SERCOM6) */
  SERCOM7_0_IRQn            =  74, /* 74  Serial Communication Interface (SERCOM7) */
  SERCOM7_1_IRQn            =  75, /* 75  Serial Communication Interface (SERCOM7) */
  SERCOM7_2_IRQn            =  76, /* 76  Serial Communication Interface (SERCOM7) */
  SERCOM7_OTHER_IRQn        =  77, /* 77  Serial Communication Interface (SERCOM7) */
  CAN0_IRQn                 =  78, /* 78  Control Area Network (CAN0)         */
  CAN1_IRQn                 =  79, /* 79  Control Area Network (CAN1)         */
  USB_OTHER_IRQn            =  80, /* 80  Universal Serial Bus (USB)          */
  USB_SOF_HSOF_IRQn         =  81, /* 81  Universal Serial Bus (USB)          */
  USB_TRCPT0_IRQn           =  82, /* 82  Universal Serial Bus (USB)          */
  USB_TRCPT1_IRQn           =  83, /* 83  Universal Serial Bus (USB)          */
  GMAC_IRQn                 =  84, /* 84  Ethernet MAC (GMAC)                 */
  TCC0_OTHER_IRQn           =  85, /* 85  Timer Counter Control (TCC0)        */
  TCC0_MC0_IRQn             =  86, /* 86  Timer Counter Control (TCC0)        */
  TCC0_MC1_IRQn             =  87, /* 87  Timer Counter Control (TCC0)        */
  TCC0_MC2_IRQn             =  88, /* 88  Timer Counter Control (TCC0)        */
  TCC0_MC3_IRQn             =  89, /* 89  Timer Counter Control (TCC0)        */
  TCC0_MC4_IRQn             =  90, /* 90  Timer Counter Control (TCC0)        */
  TCC0_MC5_IRQn             =  91, /* 91  Timer Counter Control (TCC0)        */
  TCC1_OTHER_IRQn           =  92, /* 92  Timer Counter Control (TCC1)        */
  TCC1_MC0_IRQn             =  93, /* 93  Timer Counter Control (TCC1)        */
  TCC1_MC1_IRQn             =  94, /* 94  Timer Counter Control (TCC1)        */
  TCC1_MC2_IRQn             =  95, /* 95  Timer Counter Control (TCC1)        */
  TCC1_MC3_IRQn             =  96, /* 96  Timer Counter Control (TCC1)        */
  TCC2_OTHER_IRQn           =  97, /* 97  Timer Counter Control (TCC2)        */
  TCC2_MC0_IRQn             =  98, /* 98  Timer Counter Control (TCC2)        */
  TCC2_MC1_IRQn             =  99, /* 99  Timer Counter Control (TCC2)        */
  TCC2_MC2_IRQn             = 100, /* 100 Timer Counter Control (TCC2)        */
  TCC3_OTHER_IRQn           = 101, /* 101 Timer Counter Control (TCC3)        */
  TCC3_MC0_IRQn             = 102, /* 102 Timer Counter Control (TCC3)        */
  TCC3_MC1_IRQn             = 103, /* 103 Timer Counter Control (TCC3)        */
  TCC4_OTHER_IRQn           = 104, /* 104 Timer Counter Control (TCC4)        */
  TCC4_MC0_IRQn             = 105, /* 105 Timer Counter Control (TCC4)        */
  TCC4_MC1_IRQn             = 106, /* 106 Timer Counter Control (TCC4)        */
  TC0_IRQn                  = 107, /* 107 Basic Timer Counter (TC0)           */
  TC1_IRQn                  = 108, /* 108 Basic Timer Counter (TC1)           */
  TC2_IRQn                  = 109, /* 109 Basic Timer Counter (TC2)           */
  TC3_IRQn                  = 110, /* 110 Basic Timer Counter (TC3)           */
  TC4_IRQn                  = 111, /* 111 Basic Timer Counter (TC4)           */
  TC5_IRQn                  = 112, /* 112 Basic Timer Counter (TC5)           */
  TC6_IRQn                  = 113, /* 113 Basic Timer Counter (TC6)           */
  TC7_IRQn                  = 114, /* 114 Basic Timer Counter (TC7)           */
  PDEC_OTHER_IRQn           = 115, /* 115 Quadrature Decodeur (PDEC)          */
  PDEC_MC0_IRQn             = 116, /* 116 Quadrature Decodeur (PDEC)          */
  PDEC_MC1_IRQn             = 117, /* 117 Quadrature Decodeur (PDEC)          */
  ADC0_OTHER_IRQn           = 118, /* 118 Analog Digital Converter (ADC0)     */
  ADC0_RESRDY_IRQn          = 119, /* 119 Analog Digital Converter (ADC0)     */
  ADC1_OTHER_IRQn           = 120, /* 120 Analog Digital Converter (ADC1)     */
  ADC1_RESRDY_IRQn          = 121, /* 121 Analog Digital Converter (ADC1)     */
  AC_IRQn                   = 122, /* 122 Analog Comparators (AC)             */
  DAC_OTHER_IRQn            = 123, /* 123 Digital-to-Analog Converter (DAC)   */
  DAC_EMPTY_0_IRQn          = 124, /* 124 Digital-to-Analog Converter (DAC)   */
  DAC_EMPTY_1_IRQn          = 125, /* 125 Digital-to-Analog Converter (DAC)   */
  DAC_RESRDY_0_IRQn         = 126, /* 126 Digital-to-Analog Converter (DAC)   */
  DAC_RESRDY_1_IRQn         = 127, /* 127 Digital-to-Analog Converter (DAC)   */
  I2S_IRQn                  = 128, /* 128 Inter-IC Sound Interface (I2S)      */
  PCC_IRQn                  = 129, /* 129 Parallel Capture Controller (PCC)   */
  AES_IRQn                  = 130, /* 130 Advanced Encryption Standard (AES)  */
  TRNG_IRQn                 = 131, /* 131 True Random Generator (TRNG)        */
  ICM_IRQn                  = 132, /* 132 Integrity Check Monitor (ICM)       */
  PUKCC_IRQn                = 133, /* 133 PUblic-Key Cryptography Controller (PUKCC) */
  QSPI_IRQn                 = 134, /* 134 Quad SPI interface (QSPI)           */
  SDHC0_IRQn                = 135, /* 135 SD/MMC Host Controller (SDHC0)      */
  SDHC1_IRQn                = 136, /* 136 SD/MMC Host Controller (SDHC1)      */

  PERIPH_MAX_IRQn           = 136  /* Max peripheral ID */
} IRQn_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct _DeviceVectors
{
  /* Stack pointer */
  void* pvStack;
  /* CORTEX-M4 handlers */
  void* pfnReset_Handler;                        /* -15 Reset Vector, invoked on Power up and warm reset */
  void* pfnNonMaskableInt_Handler;               /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  void* pfnHardFault_Handler;                    /* -13 Hard Fault, all classes of Fault */
  void* pfnMemoryManagement_Handler;             /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  void* pfnBusFault_Handler;                     /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  void* pfnUsageFault_Handler;                   /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  void* pvReservedC9;
  void* pvReservedC8;
  void* pvReservedC7;
  void* pvReservedC6;
  void* pfnSVCall_Handler;                       /*  -5 System Service Call via SVC instruction */
  void* pfnDebugMonitor_Handler;                 /*  -4 Debug Monitor */
  void* pvReservedC3;
  void* pfnPendSV_Handler;                       /*  -2 Pendable request for system service */
  void* pfnSysTick_Handler;                      /*  -1 System Tick Timer */

  /* Peripheral handlers */
  void* pfnPM_Handler;                           /*   0 Power Manager (PM) */
  void* pfnMCLK_Handler;                         /*   1 Main Clock (MCLK) */
  void* pfnOSCCTRL_XOSC0_Handler;                /*   2 Oscillators Control (OSCCTRL) */
  void* pfnOSCCTRL_XOSC1_Handler;                /*   3 Oscillators Control (OSCCTRL) */
  void* pfnOSCCTRL_DFLL_Handler;                 /*   4 Oscillators Control (OSCCTRL) */
  void* pfnOSCCTRL_DPLL0_Handler;                /*   5 Oscillators Control (OSCCTRL) */
  void* pfnOSCCTRL_DPLL1_Handler;                /*   6 Oscillators Control (OSCCTRL) */
  void* pfnOSC32KCTRL_Handler;                   /*   7 32kHz Oscillators Control (OSC32KCTRL) */
  void* pfnSUPC_OTHER_Handler;                   /*   8 Supply Controller (SUPC) */
  void* pfnSUPC_BODDET_Handler;                  /*   9 Supply Controller (SUPC) */
  void* pfnWDT_Handler;                          /*  10 Watchdog Timer (WDT) */
  void* pfnRTC_Handler;                          /*  11 Real-Time Counter (RTC) */
  void* pfnEIC_EXTINT_0_Handler;                 /*  12 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_1_Handler;                 /*  13 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_2_Handler;                 /*  14 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_3_Handler;                 /*  15 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_4_Handler;                 /*  16 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_5_Handler;                 /*  17 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_6_Handler;                 /*  18 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_7_Handler;                 /*  19 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_8_Handler;                 /*  20 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_9_Handler;                 /*  21 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_10_Handler;                /*  22 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_11_Handler;                /*  23 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_12_Handler;                /*  24 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_13_Handler;                /*  25 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_14_Handler;                /*  26 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_15_Handler;                /*  27 External Interrupt Controller (EIC) */
  void* pfnFREQM_Handler;                        /*  28 Frequency Meter (FREQM) */
  void* pfnNVMCTRL_0_Handler;                    /*  29 Non-Volatile Memory Controller (NVMCTRL) */
  void* pfnNVMCTRL_1_Handler;                    /*  30 Non-Volatile Memory Controller (NVMCTRL) */
  void* pfnDMAC_0_Handler;                       /*  31 Direct Memory Access Controller (DMAC) */
  void* pfnDMAC_1_Handler;                       /*  32 Direct Memory Access Controller (DMAC) */
  void* pfnDMAC_2_Handler;                       /*  33 Direct Memory Access Controller (DMAC) */
  void* pfnDMAC_3_Handler;                       /*  34 Direct Memory Access Controller (DMAC) */
  void* pfnDMAC_OTHER_Handler;                   /*  35 Direct Memory Access Controller (DMAC) */
  void* pfnEVSYS_0_Handler;                      /*  36 Event System Interface (EVSYS) */
  void* pfnEVSYS_1_Handler;                      /*  37 Event System Interface (EVSYS) */
  void* pfnEVSYS_2_Handler;                      /*  38 Event System Interface (EVSYS) */
  void* pfnEVSYS_3_Handler;                      /*  39 Event System Interface (EVSYS) */
  void* pfnEVSYS_OTHER_Handler;                  /*  40 Event System Interface (EVSYS) */
  void* pfnPAC_Handler;                          /*  41 Peripheral Access Controller (PAC) */
  void* pvReserved42;
  void* pvReserved43;
  void* pvReserved44;
  void* pfnRAMECC_Handler;                       /*  45 RAM ECC (RAMECC) */
  void* pfnSERCOM0_0_Handler;                    /*  46 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_1_Handler;                    /*  47 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_2_Handler;                    /*  48 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_OTHER_Handler;                /*  49 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM1_0_Handler;                    /*  50 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_1_Handler;                    /*  51 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_2_Handler;                    /*  52 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_OTHER_Handler;                /*  53 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM2_0_Handler;                    /*  54 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_1_Handler;                    /*  55 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_2_Handler;                    /*  56 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_OTHER_Handler;                /*  57 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM3_0_Handler;                    /*  58 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_1_Handler;                    /*  59 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_2_Handler;                    /*  60 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_OTHER_Handler;                /*  61 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM4_0_Handler;                    /*  62 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_1_Handler;                    /*  63 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_2_Handler;                    /*  64 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_OTHER_Handler;                /*  65 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM5_0_Handler;                    /*  66 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_1_Handler;                    /*  67 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_2_Handler;                    /*  68 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_OTHER_Handler;                /*  69 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM6_0_Handler;                    /*  70 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM6_1_Handler;                    /*  71 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM6_2_Handler;                    /*  72 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM6_OTHER_Handler;                /*  73 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM7_0_Handler;                    /*  74 Serial Communication Interface (SERCOM7) */
  void* pfnSERCOM7_1_Handler;                    /*  75 Serial Communication Interface (SERCOM7) */
  void* pfnSERCOM7_2_Handler;                    /*  76 Serial Communication Interface (SERCOM7) */
  void* pfnSERCOM7_OTHER_Handler;                /*  77 Serial Communication Interface (SERCOM7) */
  void* pfnCAN0_Handler;                         /*  78 Control Area Network (CAN0) */
  void* pfnCAN1_Handler;                         /*  79 Control Area Network (CAN1) */
  void* pfnUSB_OTHER_Handler;                    /*  80 Universal Serial Bus (USB) */
  void* pfnUSB_SOF_HSOF_Handler;                 /*  81 Universal Serial Bus (USB) */
  void* pfnUSB_TRCPT0_Handler;                   /*  82 Universal Serial Bus (USB) */
  void* pfnUSB_TRCPT1_Handler;                   /*  83 Universal Serial Bus (USB) */
  void* pfnGMAC_Handler;                         /*  84 Ethernet MAC (GMAC) */
  void* pfnTCC0_OTHER_Handler;                   /*  85 Timer Counter Control (TCC0) */
  void* pfnTCC0_MC0_Handler;                     /*  86 Timer Counter Control (TCC0) */
  void* pfnTCC0_MC1_Handler;                     /*  87 Timer Counter Control (TCC0) */
  void* pfnTCC0_MC2_Handler;                     /*  88 Timer Counter Control (TCC0) */
  void* pfnTCC0_MC3_Handler;                     /*  89 Timer Counter Control (TCC0) */
  void* pfnTCC0_MC4_Handler;                     /*  90 Timer Counter Control (TCC0) */
  void* pfnTCC0_MC5_Handler;                     /*  91 Timer Counter Control (TCC0) */
  void* pfnTCC1_OTHER_Handler;                   /*  92 Timer Counter Control (TCC1) */
  void* pfnTCC1_MC0_Handler;                     /*  93 Timer Counter Control (TCC1) */
  void* pfnTCC1_MC1_Handler;                     /*  94 Timer Counter Control (TCC1) */
  void* pfnTCC1_MC2_Handler;                     /*  95 Timer Counter Control (TCC1) */
  void* pfnTCC1_MC3_Handler;                     /*  96 Timer Counter Control (TCC1) */
  void* pfnTCC2_OTHER_Handler;                   /*  97 Timer Counter Control (TCC2) */
  void* pfnTCC2_MC0_Handler;                     /*  98 Timer Counter Control (TCC2) */
  void* pfnTCC2_MC1_Handler;                     /*  99 Timer Counter Control (TCC2) */
  void* pfnTCC2_MC2_Handler;                     /* 100 Timer Counter Control (TCC2) */
  void* pfnTCC3_OTHER_Handler;                   /* 101 Timer Counter Control (TCC3) */
  void* pfnTCC3_MC0_Handler;                     /* 102 Timer Counter Control (TCC3) */
  void* pfnTCC3_MC1_Handler;                     /* 103 Timer Counter Control (TCC3) */
  void* pfnTCC4_OTHER_Handler;                   /* 104 Timer Counter Control (TCC4) */
  void* pfnTCC4_MC0_Handler;                     /* 105 Timer Counter Control (TCC4) */
  void* pfnTCC4_MC1_Handler;                     /* 106 Timer Counter Control (TCC4) */
  void* pfnTC0_Handler;                          /* 107 Basic Timer Counter (TC0) */
  void* pfnTC1_Handler;                          /* 108 Basic Timer Counter (TC1) */
  void* pfnTC2_Handler;                          /* 109 Basic Timer Counter (TC2) */
  void* pfnTC3_Handler;                          /* 110 Basic Timer Counter (TC3) */
  void* pfnTC4_Handler;                          /* 111 Basic Timer Counter (TC4) */
  void* pfnTC5_Handler;                          /* 112 Basic Timer Counter (TC5) */
  void* pfnTC6_Handler;                          /* 113 Basic Timer Counter (TC6) */
  void* pfnTC7_Handler;                          /* 114 Basic Timer Counter (TC7) */
  void* pfnPDEC_OTHER_Handler;                   /* 115 Quadrature Decodeur (PDEC) */
  void* pfnPDEC_MC0_Handler;                     /* 116 Quadrature Decodeur (PDEC) */
  void* pfnPDEC_MC1_Handler;                     /* 117 Quadrature Decodeur (PDEC) */
  void* pfnADC0_OTHER_Handler;                   /* 118 Analog Digital Converter (ADC0) */
  void* pfnADC0_RESRDY_Handler;                  /* 119 Analog Digital Converter (ADC0) */
  void* pfnADC1_OTHER_Handler;                   /* 120 Analog Digital Converter (ADC1) */
  void* pfnADC1_RESRDY_Handler;                  /* 121 Analog Digital Converter (ADC1) */
  void* pfnAC_Handler;                           /* 122 Analog Comparators (AC) */
  void* pfnDAC_OTHER_Handler;                    /* 123 Digital-to-Analog Converter (DAC) */
  void* pfnDAC_EMPTY_0_Handler;                  /* 124 Digital-to-Analog Converter (DAC) */
  void* pfnDAC_EMPTY_1_Handler;                  /* 125 Digital-to-Analog Converter (DAC) */
  void* pfnDAC_RESRDY_0_Handler;                 /* 126 Digital-to-Analog Converter (DAC) */
  void* pfnDAC_RESRDY_1_Handler;                 /* 127 Digital-to-Analog Converter (DAC) */
  void* pfnI2S_Handler;                          /* 128 Inter-IC Sound Interface (I2S) */
  void* pfnPCC_Handler;                          /* 129 Parallel Capture Controller (PCC) */
  void* pfnAES_Handler;                          /* 130 Advanced Encryption Standard (AES) */
  void* pfnTRNG_Handler;                         /* 131 True Random Generator (TRNG) */
  void* pfnICM_Handler;                          /* 132 Integrity Check Monitor (ICM) */
  void* pfnPUKCC_Handler;                        /* 133 PUblic-Key Cryptography Controller (PUKCC) */
  void* pfnQSPI_Handler;                         /* 134 Quad SPI interface (QSPI) */
  void* pfnSDHC0_Handler;                        /* 135 SD/MMC Host Controller (SDHC0) */
  void* pfnSDHC1_Handler;                        /* 136 SD/MMC Host Controller (SDHC1) */
} DeviceVectors;

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if !defined DONT_USE_PREDEFINED_CORE_HANDLERS
/* CORTEX-M4 exception handlers */
void Reset_Handler                 ( void );
void NonMaskableInt_Handler        ( void );
void HardFault_Handler             ( void );
void MemoryManagement_Handler      ( void );
void BusFault_Handler              ( void );
void UsageFault_Handler            ( void );
void SVCall_Handler                ( void );
void DebugMonitor_Handler          ( void );
void PendSV_Handler                ( void );
void SysTick_Handler               ( void );
#endif /* DONT_USE_PREDEFINED_CORE_HANDLERS */

#if !defined DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS
/* Peripherals interrupt handlers */
void PM_Handler                    ( void );
void MCLK_Handler                  ( void );
void OSCCTRL_XOSC0_Handler         ( void );
void OSCCTRL_XOSC1_Handler         ( void );
void OSCCTRL_DFLL_Handler          ( void );
void OSCCTRL_DPLL0_Handler         ( void );
void OSCCTRL_DPLL1_Handler         ( void );
void OSC32KCTRL_Handler            ( void );
void SUPC_OTHER_Handler            ( void );
void SUPC_BODDET_Handler           ( void );
void WDT_Handler                   ( void );
void RTC_Handler                   ( void );
void EIC_EXTINT_0_Handler          ( void );
void EIC_EXTINT_1_Handler          ( void );
void EIC_EXTINT_2_Handler          ( void );
void EIC_EXTINT_3_Handler          ( void );
void EIC_EXTINT_4_Handler          ( void );
void EIC_EXTINT_5_Handler          ( void );
void EIC_EXTINT_6_Handler          ( void );
void EIC_EXTINT_7_Handler          ( void );
void EIC_EXTINT_8_Handler          ( void );
void EIC_EXTINT_9_Handler          ( void );
void EIC_EXTINT_10_Handler         ( void );
void EIC_EXTINT_11_Handler         ( void );
void EIC_EXTINT_12_Handler         ( void );
void EIC_EXTINT_13_Handler         ( void );
void EIC_EXTINT_14_Handler         ( void );
void EIC_EXTINT_15_Handler         ( void );
void FREQM_Handler                 ( void );
void NVMCTRL_0_Handler             ( void );
void NVMCTRL_1_Handler             ( void );
void DMAC_0_Handler                ( void );
void DMAC_1_Handler                ( void );
void DMAC_2_Handler                ( void );
void DMAC_3_Handler                ( void );
void DMAC_OTHER_Handler            ( void );
void EVSYS_0_Handler               ( void );
void EVSYS_1_Handler               ( void );
void EVSYS_2_Handler               ( void );
void EVSYS_3_Handler               ( void );
void EVSYS_OTHER_Handler           ( void );
void PAC_Handler                   ( void );
void RAMECC_Handler                ( void );
void SERCOM0_0_Handler             ( void );
void SERCOM0_1_Handler             ( void );
void SERCOM0_2_Handler             ( void );
void SERCOM0_OTHER_Handler         ( void );
void SERCOM1_0_Handler             ( void );
void SERCOM1_1_Handler             ( void );
void SERCOM1_2_Handler             ( void );
void SERCOM1_OTHER_Handler         ( void );
void SERCOM2_0_Handler             ( void );
void SERCOM2_1_Handler             ( void );
void SERCOM2_2_Handler             ( void );
void SERCOM2_OTHER_Handler         ( void );
void SERCOM3_0_Handler             ( void );
void SERCOM3_1_Handler             ( void );
void SERCOM3_2_Handler             ( void );
void SERCOM3_OTHER_Handler         ( void );
void SERCOM4_0_Handler             ( void );
void SERCOM4_1_Handler             ( void );
void SERCOM4_2_Handler             ( void );
void SERCOM4_OTHER_Handler         ( void );
void SERCOM5_0_Handler             ( void );
void SERCOM5_1_Handler             ( void );
void SERCOM5_2_Handler             ( void );
void SERCOM5_OTHER_Handler         ( void );
void SERCOM6_0_Handler             ( void );
void SERCOM6_1_Handler             ( void );
void SERCOM6_2_Handler             ( void );
void SERCOM6_OTHER_Handler         ( void );
void SERCOM7_0_Handler             ( void );
void SERCOM7_1_Handler             ( void );
void SERCOM7_2_Handler             ( void );
void SERCOM7_OTHER_Handler         ( void );
void CAN0_Handler                  ( void );
void CAN1_Handler                  ( void );
void USB_OTHER_Handler             ( void );
void USB_SOF_HSOF_Handler          ( void );
void USB_TRCPT0_Handler            ( void );
void USB_TRCPT1_Handler            ( void );
void GMAC_Handler                  ( void );
void TCC0_OTHER_Handler            ( void );
void TCC0_MC0_Handler              ( void );
void TCC0_MC1_Handler              ( void );
void TCC0_MC2_Handler              ( void );
void TCC0_MC3_Handler              ( void );
void TCC0_MC4_Handler              ( void );
void TCC0_MC5_Handler              ( void );
void TCC1_OTHER_Handler            ( void );
void TCC1_MC0_Handler              ( void );
void TCC1_MC1_Handler              ( void );
void TCC1_MC2_Handler              ( void );
void TCC1_MC3_Handler              ( void );
void TCC2_OTHER_Handler            ( void );
void TCC2_MC0_Handler              ( void );
void TCC2_MC1_Handler              ( void );
void TCC2_MC2_Handler              ( void );
void TCC3_OTHER_Handler            ( void );
void TCC3_MC0_Handler              ( void );
void TCC3_MC1_Handler              ( void );
void TCC4_OTHER_Handler            ( void );
void TCC4_MC0_Handler              ( void );
void TCC4_MC1_Handler              ( void );
void TC0_Handler                   ( void );
void TC1_Handler                   ( void );
void TC2_Handler                   ( void );
void TC3_Handler                   ( void );
void TC4_Handler                   ( void );
void TC5_Handler                   ( void );
void TC6_Handler                   ( void );
void TC7_Handler                   ( void );
void PDEC_OTHER_Handler            ( void );
void PDEC_MC0_Handler              ( void );
void PDEC_MC1_Handler              ( void );
void ADC0_OTHER_Handler            ( void );
void ADC0_RESRDY_Handler           ( void );
void ADC1_OTHER_Handler            ( void );
void ADC1_RESRDY_Handler           ( void );
void AC_Handler                    ( void );
void DAC_OTHER_Handler             ( void );
void DAC_EMPTY_0_Handler           ( void );
void DAC_EMPTY_1_Handler           ( void );
void DAC_RESRDY_0_Handler          ( void );
void DAC_RESRDY_1_Handler          ( void );
void I2S_Handler                   ( void );
void PCC_Handler                   ( void );
void AES_Handler                   ( void );
void TRNG_Handler                  ( void );
void ICM_Handler                   ( void );
void PUKCC_Handler                 ( void );
void QSPI_Handler                  ( void );
void SDHC0_Handler                 ( void );
void SDHC1_Handler                 ( void );
#endif /* DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* Configuration of the CORTEX-M4 Processor and Core Peripherals */
#define __CM4_REV                     0x0001 /* Cortex-M4 Core Revision                                                   */
#define __DEBUG_LVL                        3 /* Debug Level                                                               */
#define __FPU_PRESENT                      1 /* FPU present or not                                                        */
#define __MPU_PRESENT                      1 /* MPU present or not                                                        */
#define __NVIC_PRIO_BITS                   3 /* Number of Bits used for Priority Levels                                   */
#define __TRACE_LVL                        2 /* Trace Level                                                               */
#define __VTOR_PRESENT                     1 /* Vector Table Offset Register present or not                               */
#define __Vendor_SysTickConfig             0 /* Set to 1 if different SysTick Config is used                              */
#define __ARCH_ARM                         1
#define __ARCH_ARM_CORTEX_M                1

/* CMSIS includes */
#include "core_cm4.h"
#if defined USE_CMSIS_INIT
#include "system_same54.h"
#endif /* USE_CMSIS_INIT */

/* ************************************************************************** */
/*   SOFTWARE PERIPHERAL API DEFINITION FOR SAME54N19A                        */
/* ************************************************************************** */
#include "component/ac.h"
#include "component/adc.h"
#include "component/aes.h"
#include "component/can.h"
#include "component/ccl.h"
#include "component/cmcc.h"
#include "component/dac.h"
#include "component/dmac.h"
#include "component/dsu.h"
#include "component/eic.h"
#include "component/evsys.h"
#include "component/freqm.h"
#include "component/fuses.h"
#include "component/gclk.h"
#include "component/gmac.h"
#include "component/hmatrixb.h"
#include "component/i2s.h"
#include "component/icm.h"
#include "component/mclk.h"
#include "component/nvmctrl.h"
#include "component/osc32kctrl.h"
#include "component/oscctrl.h"
#include "component/pac.h"
#include "component/pcc.h"
#include "component/pdec.h"
#include "component/pm.h"
#include "component/port.h"
#include "component/pukcc.h"
#include "component/qspi.h"
#include "component/ramecc.h"
#include "component/rstc.h"
#include "component/rtc.h"
#include "component/sdhc.h"
#include "component/sercom.h"
#include "component/supc.h"
#include "component/tc.h"
#include "component/tcc.h"
#include "component/trng.h"
#include "component/usb.h"
#include "component/wdt.h"

/* ************************************************************************** */
/*   INSTANCE DEFINITIONS FOR SAME54N19A */
/* ************************************************************************** */
#include "instance/ac.h"
#include "instance/adc0.h"
#include "instance/adc1.h"
#include "instance/aes.h"
#include "instance/can0.h"
#include "instance/can1.h"
#include "instance/ccl.h"
#include "instance/cmcc.h"
#include "instance/dac.h"
#include "instance/dmac.h"
#include "instance/dsu.h"
#include "instance/eic.h"
#include "instance/evsys.h"
#include "instance/freqm.h"
#include "instance/fuses.h"
#include "instance/gclk.h"
#include "instance/gmac.h"
#include "instance/hmatrix.h"
#include "instance/i2s.h"
#include "instance/icm.h"
#include "instance/mclk.h"
#include "instance/nvmctrl.h"
#include "instance/osc32kctrl.h"
#include "instance/oscctrl.h"
#include "instance/pac.h"
#include "instance/pcc.h"
#include "instance/pdec.h"
#include "instance/pm.h"
#include "instance/port.h"
#include "instance/qspi.h"
#include "instance/ramecc.h"
#include "instance/rstc.h"
#include "instance/rtc.h"
#include "instance/sdhc0.h"
#include "instance/sdhc1.h"
#include "instance/sercom0.h"
#include "instance/sercom1.h"
#include "instance/sercom2.h"
#include "instance/sercom3.h"
#include "instance/sercom4.h"
#include "instance/sercom5.h"
#include "instance/sercom6.h"
#include "instance/sercom7.h"
#include "instance/supc.h"
#include "instance/tc0.h"
#include "instance/tc1.h"
#include "instance/tc2.h"
#include "instance/tc3.h"
#include "instance/tc4.h"
#include "instance/tc5.h"
#include "instance/tc6.h"
#include "instance/tc7.h"
#include "instance/tcc0.h"
#include "instance/tcc1.h"
#include "instance/tcc2.h"
#include "instance/tcc3.h"
#include "instance/tcc4.h"
#include "instance/trng.h"
#include "instance/usb.h"
#include "instance/wdt.h"

/* ************************************************************************** */
/*  PERIPHERAL ID DEFINITIONS FOR SAME54N19A                                  */
/* ************************************************************************** */
#define ID_PAC           (  0) /* Instance index for PAC (PAC) */
#define ID_PM            (  1) /* Instance index for PM (PM) */
#define ID_MCLK          (  2) /* Instance index for MCLK (MCLK) */
#define ID_RSTC          (  3) /* Instance index for RSTC (RSTC) */
#define ID_OSCCTRL       (  4) /* Instance index for OSCCTRL (OSCCTRL) */
#define ID_OSC32KCTRL    (  5) /* Instance index for OSC32KCTRL (OSC32KCTRL) */
#define ID_SUPC          (  6) /* Instance index for SUPC (SUPC) */
#define ID_GCLK          (  7) /* Instance index for GCLK (GCLK) */
#define ID_WDT           (  8) /* Instance index for WDT (WDT) */
#define ID_RTC           (  9) /* Instance index for RTC (RTC) */
#define ID_EIC           ( 10) /* Instance index for EIC (EIC) */
#define ID_FREQM         ( 11) /* Instance index for FREQM (FREQM) */
#define ID_SERCOM0       ( 12) /* Instance index for SERCOM0 (SERCOM0) */
#define ID_SERCOM1       ( 13) /* Instance index for SERCOM1 (SERCOM1) */
#define ID_TC0           ( 14) /* Instance index for TC0 (TC0) */
#define ID_TC1           ( 15) /* Instance index for TC1 (TC1) */
#define ID_USB           ( 32) /* Instance index for USB (USB) */
#define ID_DSU           ( 33) /* Instance index for DSU (DSU) */
#define ID_NVMCTRL       ( 34) /* Instance index for NVMCTRL (NVMCTRL) */
#define ID_CMCC          ( 35) /* Instance index for CMCC (CMCC) */
#define ID_PORT          ( 36) /* Instance index for PORT (PORT) */
#define ID_DMAC          ( 37) /* Instance index for DMAC (DMAC) */
#define ID_HMATRIX       ( 38) /* Instance index for HMATRIX (HMATRIX) */
#define ID_EVSYS         ( 39) /* Instance index for EVSYS (EVSYS) */
#define ID_SERCOM2       ( 41) /* Instance index for SERCOM2 (SERCOM2) */
#define ID_SERCOM3       ( 42) /* Instance index for SERCOM3 (SERCOM3) */
#define ID_TCC0          ( 43) /* Instance index for TCC0 (TCC0) */
#define ID_TCC1          ( 44) /* Instance index for TCC1 (TCC1) */
#define ID_TC2           ( 45) /* Instance index for TC2 (TC2) */
#define ID_TC3           ( 46) /* Instance index for TC3 (TC3) */
#define ID_RAMECC        ( 48) /* Instance index for RAMECC (RAMECC) */
#define ID_CAN0          ( 64) /* Instance index for CAN0 (CAN0) */
#define ID_CAN1          ( 65) /* Instance index for CAN1 (CAN1) */
#define ID_GMAC          ( 66) /* Instance index for GMAC (GMAC) */
#define ID_TCC2          ( 67) /* Instance index for TCC2 (TCC2) */
#define ID_TCC3          ( 68) /* Instance index for TCC3 (TCC3) */
#define ID_TC4           ( 69) /* Instance index for TC4 (TC4) */
#define ID_TC5           ( 70) /* Instance index for TC5 (TC5) */
#define ID_PDEC          ( 71) /* Instance index for PDEC (PDEC) */
#define ID_AC            ( 72) /* Instance index for AC (AC) */
#define ID_AES           ( 73) /* Instance index for AES (AES) */
#define ID_TRNG          ( 74) /* Instance index for TRNG (TRNG) */
#define ID_ICM           ( 75) /* Integrity Check Monitor (ICM) */
#define ID_PUKCC         ( 76) /* Instance index for PUKCC (PUKCC) */
#define ID_QSPI          ( 77) /* Instance index for QSPI (QSPI) */
#define ID_CCL           ( 78) /* Instance index for CCL (CCL) */
#define ID_SERCOM4       ( 96) /* Instance index for SERCOM4 (SERCOM4) */
#define ID_SERCOM5       ( 97) /* Instance index for SERCOM5 (SERCOM5) */
#define ID_SERCOM6       ( 98) /* Instance index for SERCOM6 (SERCOM6) */
#define ID_SERCOM7       ( 99) /* Instance index for SERCOM7 (SERCOM7) */
#define ID_TCC4          (100) /* Instance index for TCC4 (TCC4) */
#define ID_TC6           (101) /* Instance index for TC6 (TC6) */
#define ID_TC7           (102) /* Instance index for TC7 (TC7) */
#define ID_ADC0          (103) /* Instance index for ADC0 (ADC0) */
#define ID_ADC1          (104) /* Instance index for ADC1 (ADC1) */
#define ID_DAC           (105) /* Instance index for DAC (DAC) */
#define ID_I2S           (106) /* Instance index for I2S (I2S) */
#define ID_PCC           (107) /* Instance index for PCC (PCC) */

#define ID_PERIPH_MAX    (107) /* Number of peripheral IDs */

/* ************************************************************************** */
/*   REGISTER STRUCTURE ADDRESS DEFINITIONS FOR SAME54N19A                    */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#define AC_REGS                          ((ac_registers_t*)0x42002000)                 /* AC Registers Address         */
#define ADC0_REGS                        ((adc_registers_t*)0x43001c00)                /* ADC0 Registers Address       */
#define ADC1_REGS                        ((adc_registers_t*)0x43002000)                /* ADC1 Registers Address       */
#define AES_REGS                         ((aes_registers_t*)0x42002400)                /* AES Registers Address        */
#define CAN0_REGS                        ((can_registers_t*)0x42000000)                /* CAN0 Registers Address       */
#define CAN1_REGS                        ((can_registers_t*)0x42000400)                /* CAN1 Registers Address       */
#define CCL_REGS                         ((ccl_registers_t*)0x42003800)                /* CCL Registers Address        */
#define CMCC_REGS                        ((cmcc_registers_t*)0x41006000)               /* CMCC Registers Address       */
#define DAC_REGS                         ((dac_registers_t*)0x43002400)                /* DAC Registers Address        */
#define DMAC_REGS                        ((dmac_registers_t*)0x4100a000)               /* DMAC Registers Address       */
#define DSU_REGS                         ((dsu_registers_t*)0x41002000)                /* DSU Registers Address        */
#define EIC_REGS                         ((eic_registers_t*)0x40002800)                /* EIC Registers Address        */
#define EVSYS_REGS                       ((evsys_registers_t*)0x4100e000)              /* EVSYS Registers Address      */
#define FREQM_REGS                       ((freqm_registers_t*)0x40002c00)              /* FREQM Registers Address      */
#define GCLK_REGS                        ((gclk_registers_t*)0x40001c00)               /* GCLK Registers Address       */
#define GMAC_REGS                        ((gmac_registers_t*)0x42000800)               /* GMAC Registers Address       */
#define HMATRIX_REGS                     ((hmatrixb_registers_t*)0x4100c000)           /* HMATRIX Registers Address    */
#define ICM_REGS                         ((icm_registers_t*)0x42002c00)                /* ICM Registers Address        */
#define I2S_REGS                         ((i2s_registers_t*)0x43002800)                /* I2S Registers Address        */
#define MCLK_REGS                        ((mclk_registers_t*)0x40000800)               /* MCLK Registers Address       */
#define NVMCTRL_REGS                     ((nvmctrl_registers_t*)0x41004000)            /* NVMCTRL Registers Address    */
#define SW0_FUSES_REGS                   ((fuses_sw0_fuses_registers_t*)0x00800080)    /* FUSES Registers Address      */
#define TEMP_LOG_FUSES_REGS              ((fuses_temp_log_fuses_registers_t*)0x00800100) /* FUSES Registers Address      */
#define USER_FUSES_REGS                  ((fuses_user_fuses_registers_t*)0x00804000)   /* FUSES Registers Address      */
#define OSCCTRL_REGS                     ((oscctrl_registers_t*)0x40001000)            /* OSCCTRL Registers Address    */
#define OSC32KCTRL_REGS                  ((osc32kctrl_registers_t*)0x40001400)         /* OSC32KCTRL Registers Address */
#define PAC_REGS                         ((pac_registers_t*)0x40000000)                /* PAC Registers Address        */
#define PCC_REGS                         ((pcc_registers_t*)0x43002c00)                /* PCC Registers Address        */
#define PDEC_REGS                        ((pdec_registers_t*)0x42001c00)               /* PDEC Registers Address       */
#define PM_REGS                          ((pm_registers_t*)0x40000400)                 /* PM Registers Address         */
#define PORT_REGS                        ((port_registers_t*)0x41008000)               /* PORT Registers Address       */
#define QSPI_REGS                        ((qspi_registers_t*)0x42003400)               /* QSPI Registers Address       */
#define RAMECC_REGS                      ((ramecc_registers_t*)0x41020000)             /* RAMECC Registers Address     */
#define RSTC_REGS                        ((rstc_registers_t*)0x40000c00)               /* RSTC Registers Address       */
#define RTC_REGS                         ((rtc_registers_t*)0x40002400)                /* RTC Registers Address        */
#define SDHC0_REGS                       ((sdhc_registers_t*)0x45000000)               /* SDHC0 Registers Address      */
#define SDHC1_REGS                       ((sdhc_registers_t*)0x46000000)               /* SDHC1 Registers Address      */
#define SERCOM0_REGS                     ((sercom_registers_t*)0x40003000)             /* SERCOM0 Registers Address    */
#define SERCOM1_REGS                     ((sercom_registers_t*)0x40003400)             /* SERCOM1 Registers Address    */
#define SERCOM2_REGS                     ((sercom_registers_t*)0x41012000)             /* SERCOM2 Registers Address    */
#define SERCOM3_REGS                     ((sercom_registers_t*)0x41014000)             /* SERCOM3 Registers Address    */
#define SERCOM4_REGS                     ((sercom_registers_t*)0x43000000)             /* SERCOM4 Registers Address    */
#define SERCOM5_REGS                     ((sercom_registers_t*)0x43000400)             /* SERCOM5 Registers Address    */
#define SERCOM6_REGS                     ((sercom_registers_t*)0x43000800)             /* SERCOM6 Registers Address    */
#define SERCOM7_REGS                     ((sercom_registers_t*)0x43000c00)             /* SERCOM7 Registers Address    */
#define SUPC_REGS                        ((supc_registers_t*)0x40001800)               /* SUPC Registers Address       */
#define TC0_REGS                         ((tc_registers_t*)0x40003800)                 /* TC0 Registers Address        */
#define TC1_REGS                         ((tc_registers_t*)0x40003c00)                 /* TC1 Registers Address        */
#define TC2_REGS                         ((tc_registers_t*)0x4101a000)                 /* TC2 Registers Address        */
#define TC3_REGS                         ((tc_registers_t*)0x4101c000)                 /* TC3 Registers Address        */
#define TC4_REGS                         ((tc_registers_t*)0x42001400)                 /* TC4 Registers Address        */
#define TC5_REGS                         ((tc_registers_t*)0x42001800)                 /* TC5 Registers Address        */
#define TC6_REGS                         ((tc_registers_t*)0x43001400)                 /* TC6 Registers Address        */
#define TC7_REGS                         ((tc_registers_t*)0x43001800)                 /* TC7 Registers Address        */
#define TCC0_REGS                        ((tcc_registers_t*)0x41016000)                /* TCC0 Registers Address       */
#define TCC1_REGS                        ((tcc_registers_t*)0x41018000)                /* TCC1 Registers Address       */
#define TCC2_REGS                        ((tcc_registers_t*)0x42000c00)                /* TCC2 Registers Address       */
#define TCC3_REGS                        ((tcc_registers_t*)0x42001000)                /* TCC3 Registers Address       */
#define TCC4_REGS                        ((tcc_registers_t*)0x43001000)                /* TCC4 Registers Address       */
#define TRNG_REGS                        ((trng_registers_t*)0x42002800)               /* TRNG Registers Address       */
#define USB_REGS                         ((usb_registers_t*)0x41000000)                /* USB Registers Address        */
#define WDT_REGS                         ((wdt_registers_t*)0x40002000)                /* WDT Registers Address        */
#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR SAME54N19A                                  */
/* ************************************************************************** */
#define AC_BASE_ADDRESS                  _UINT32_(0x42002000)                          /* AC Base Address */
#define ADC0_BASE_ADDRESS                _UINT32_(0x43001c00)                          /* ADC0 Base Address */
#define ADC1_BASE_ADDRESS                _UINT32_(0x43002000)                          /* ADC1 Base Address */
#define AES_BASE_ADDRESS                 _UINT32_(0x42002400)                          /* AES Base Address */
#define CAN0_BASE_ADDRESS                _UINT32_(0x42000000)                          /* CAN0 Base Address */
#define CAN1_BASE_ADDRESS                _UINT32_(0x42000400)                          /* CAN1 Base Address */
#define CCL_BASE_ADDRESS                 _UINT32_(0x42003800)                          /* CCL Base Address */
#define CMCC_BASE_ADDRESS                _UINT32_(0x41006000)                          /* CMCC Base Address */
#define DAC_BASE_ADDRESS                 _UINT32_(0x43002400)                          /* DAC Base Address */
#define DMAC_BASE_ADDRESS                _UINT32_(0x4100a000)                          /* DMAC Base Address */
#define DSU_BASE_ADDRESS                 _UINT32_(0x41002000)                          /* DSU Base Address */
#define EIC_BASE_ADDRESS                 _UINT32_(0x40002800)                          /* EIC Base Address */
#define EVSYS_BASE_ADDRESS               _UINT32_(0x4100e000)                          /* EVSYS Base Address */
#define FREQM_BASE_ADDRESS               _UINT32_(0x40002c00)                          /* FREQM Base Address */
#define GCLK_BASE_ADDRESS                _UINT32_(0x40001c00)                          /* GCLK Base Address */
#define GMAC_BASE_ADDRESS                _UINT32_(0x42000800)                          /* GMAC Base Address */
#define HMATRIX_BASE_ADDRESS             _UINT32_(0x4100c000)                          /* HMATRIX Base Address */
#define ICM_BASE_ADDRESS                 _UINT32_(0x42002c00)                          /* ICM Base Address */
#define I2S_BASE_ADDRESS                 _UINT32_(0x43002800)                          /* I2S Base Address */
#define MCLK_BASE_ADDRESS                _UINT32_(0x40000800)                          /* MCLK Base Address */
#define NVMCTRL_BASE_ADDRESS             _UINT32_(0x41004000)                          /* NVMCTRL Base Address */
#define SW0_FUSES_BASE_ADDRESS           _UINT32_(0x00800080)                          /* FUSES Base Address */
#define TEMP_LOG_FUSES_BASE_ADDRESS      _UINT32_(0x00800100)                          /* FUSES Base Address */
#define USER_FUSES_BASE_ADDRESS          _UINT32_(0x00804000)                          /* FUSES Base Address */
#define OSCCTRL_BASE_ADDRESS             _UINT32_(0x40001000)                          /* OSCCTRL Base Address */
#define OSC32KCTRL_BASE_ADDRESS          _UINT32_(0x40001400)                          /* OSC32KCTRL Base Address */
#define PAC_BASE_ADDRESS                 _UINT32_(0x40000000)                          /* PAC Base Address */
#define PCC_BASE_ADDRESS                 _UINT32_(0x43002c00)                          /* PCC Base Address */
#define PDEC_BASE_ADDRESS                _UINT32_(0x42001c00)                          /* PDEC Base Address */
#define PM_BASE_ADDRESS                  _UINT32_(0x40000400)                          /* PM Base Address */
#define PORT_BASE_ADDRESS                _UINT32_(0x41008000)                          /* PORT Base Address */
#define QSPI_BASE_ADDRESS                _UINT32_(0x42003400)                          /* QSPI Base Address */
#define RAMECC_BASE_ADDRESS              _UINT32_(0x41020000)                          /* RAMECC Base Address */
#define RSTC_BASE_ADDRESS                _UINT32_(0x40000c00)                          /* RSTC Base Address */
#define RTC_BASE_ADDRESS                 _UINT32_(0x40002400)                          /* RTC Base Address */
#define SDHC0_BASE_ADDRESS               _UINT32_(0x45000000)                          /* SDHC0 Base Address */
#define SDHC1_BASE_ADDRESS               _UINT32_(0x46000000)                          /* SDHC1 Base Address */
#define SERCOM0_BASE_ADDRESS             _UINT32_(0x40003000)                          /* SERCOM0 Base Address */
#define SERCOM1_BASE_ADDRESS             _UINT32_(0x40003400)                          /* SERCOM1 Base Address */
#define SERCOM2_BASE_ADDRESS             _UINT32_(0x41012000)                          /* SERCOM2 Base Address */
#define SERCOM3_BASE_ADDRESS             _UINT32_(0x41014000)                          /* SERCOM3 Base Address */
#define SERCOM4_BASE_ADDRESS             _UINT32_(0x43000000)                          /* SERCOM4 Base Address */
#define SERCOM5_BASE_ADDRESS             _UINT32_(0x43000400)                          /* SERCOM5 Base Address */
#define SERCOM6_BASE_ADDRESS             _UINT32_(0x43000800)                          /* SERCOM6 Base Address */
#define SERCOM7_BASE_ADDRESS             _UINT32_(0x43000c00)                          /* SERCOM7 Base Address */
#define SUPC_BASE_ADDRESS                _UINT32_(0x40001800)                          /* SUPC Base Address */
#define TC0_BASE_ADDRESS                 _UINT32_(0x40003800)                          /* TC0 Base Address */
#define TC1_BASE_ADDRESS                 _UINT32_(0x40003c00)                          /* TC1 Base Address */
#define TC2_BASE_ADDRESS                 _UINT32_(0x4101a000)                          /* TC2 Base Address */
#define TC3_BASE_ADDRESS                 _UINT32_(0x4101c000)                          /* TC3 Base Address */
#define TC4_BASE_ADDRESS                 _UINT32_(0x42001400)                          /* TC4 Base Address */
#define TC5_BASE_ADDRESS                 _UINT32_(0x42001800)                          /* TC5 Base Address */
#define TC6_BASE_ADDRESS                 _UINT32_(0x43001400)                          /* TC6 Base Address */
#define TC7_BASE_ADDRESS                 _UINT32_(0x43001800)                          /* TC7 Base Address */
#define TCC0_BASE_ADDRESS                _UINT32_(0x41016000)                          /* TCC0 Base Address */
#define TCC1_BASE_ADDRESS                _UINT32_(0x41018000)                          /* TCC1 Base Address */
#define TCC2_BASE_ADDRESS                _UINT32_(0x42000c00)                          /* TCC2 Base Address */
#define TCC3_BASE_ADDRESS                _UINT32_(0x42001000)                          /* TCC3 Base Address */
#define TCC4_BASE_ADDRESS                _UINT32_(0x43001000)                          /* TCC4 Base Address */
#define TRNG_BASE_ADDRESS                _UINT32_(0x42002800)                          /* TRNG Base Address */
#define USB_BASE_ADDRESS                 _UINT32_(0x41000000)                          /* USB Base Address */
#define WDT_BASE_ADDRESS                 _UINT32_(0x40002000)                          /* WDT Base Address */

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR SAME54N19A                                           */
/* ************************************************************************** */
#include "pio/same54n19a.h"

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR SAME54N19A                                */
/* ************************************************************************** */
#define FLASH_SIZE                     _UINT32_(0x00080000)    /*  512kB Memory segment type: flash */
#define FLASH_PAGE_SIZE                _UINT32_(       512)
#define FLASH_NB_OF_PAGES              _UINT32_(      1024)

#define SW0_SIZE                       _UINT32_(0x00000010)    /*    0kB Memory segment type: fuses */
#define TEMP_LOG_SIZE                  _UINT32_(0x00000200)    /*    0kB Memory segment type: fuses */
#define TEMP_LOG_PAGE_SIZE             _UINT32_(       512)
#define TEMP_LOG_NB_OF_PAGES           _UINT32_(         1)

#define USER_PAGE_SIZE                 _UINT32_(0x00000200)    /*    0kB Memory segment type: user_page */
#define USER_PAGE_PAGE_SIZE            _UINT32_(       512)
#define USER_PAGE_NB_OF_PAGES          _UINT32_(         1)

#define CMCC_SIZE                      _UINT32_(0x01000000)    /* 16384kB Memory segment type: io */
#define CMCC_DATARAM_SIZE              _UINT32_(0x00001000)    /*    4kB Memory segment type: io */
#define CMCC_TAGRAM_SIZE               _UINT32_(0x00000400)    /*    1kB Memory segment type: io */
#define CMCC_VALIDRAM_SIZE             _UINT32_(0x00000040)    /*    0kB Memory segment type: io */
#define QSPI_SIZE                      _UINT32_(0x01000000)    /* 16384kB Memory segment type: other */
#define HSRAM_SIZE                     _UINT32_(0x00030000)    /*  192kB Memory segment type: ram */
#define HSRAM_ETB_SIZE                 _UINT32_(0x00008000)    /*   32kB Memory segment type: ram */
#define HSRAM_RET1_SIZE                _UINT32_(0x00008000)    /*   32kB Memory segment type: ram */
#define HPB0_SIZE                      _UINT32_(0x00004400)    /*   17kB Memory segment type: io */
#define HPB1_SIZE                      _UINT32_(0x00022000)    /*  136kB Memory segment type: io */
#define HPB2_SIZE                      _UINT32_(0x00003c00)    /*   15kB Memory segment type: io */
#define HPB3_SIZE                      _UINT32_(0x00003000)    /*   12kB Memory segment type: io */
#define SEEPROM_SIZE                   _UINT32_(0x00020000)    /*  128kB Memory segment type: io */
#define SDHC0_SIZE                     _UINT32_(0x00000c00)    /*    3kB Memory segment type: io */
#define SDHC1_SIZE                     _UINT32_(0x00000c00)    /*    3kB Memory segment type: io */
#define BKUPRAM_SIZE                   _UINT32_(0x00002000)    /*    8kB Memory segment type: ram */
#define PPB_SIZE                       _UINT32_(0x00100000)    /* 1024kB Memory segment type: io */
#define SCS_SIZE                       _UINT32_(0x00001000)    /*    4kB Memory segment type: io */

#define FLASH_ADDR                     _UINT32_(0x00000000)    /* FLASH base address (type: flash)*/
#define SW0_ADDR                       _UINT32_(0x00800080)    /* SW0 base address (type: fuses)*/
#define TEMP_LOG_ADDR                  _UINT32_(0x00800100)    /* TEMP_LOG base address (type: fuses)*/
#define USER_PAGE_ADDR                 _UINT32_(0x00804000)    /* USER_PAGE base address (type: user_page)*/
#define CMCC_ADDR                      _UINT32_(0x03000000)    /* CMCC base address (type: io)*/
#define CMCC_DATARAM_ADDR              _UINT32_(0x03000000)    /* CMCC_DATARAM base address (type: io)*/
#define CMCC_TAGRAM_ADDR               _UINT32_(0x03001000)    /* CMCC_TAGRAM base address (type: io)*/
#define CMCC_VALIDRAM_ADDR             _UINT32_(0x03002000)    /* CMCC_VALIDRAM base address (type: io)*/
#define QSPI_ADDR                      _UINT32_(0x04000000)    /* QSPI base address (type: other)*/
#define HSRAM_ADDR                     _UINT32_(0x20000000)    /* HSRAM base address (type: ram)*/
#define HSRAM_ETB_ADDR                 _UINT32_(0x20000000)    /* HSRAM_ETB base address (type: ram)*/
#define HSRAM_RET1_ADDR                _UINT32_(0x20000000)    /* HSRAM_RET1 base address (type: ram)*/
#define HPB0_ADDR                      _UINT32_(0x40000000)    /* HPB0 base address (type: io)*/
#define HPB1_ADDR                      _UINT32_(0x41000000)    /* HPB1 base address (type: io)*/
#define HPB2_ADDR                      _UINT32_(0x42000000)    /* HPB2 base address (type: io)*/
#define HPB3_ADDR                      _UINT32_(0x43000000)    /* HPB3 base address (type: io)*/
#define SEEPROM_ADDR                   _UINT32_(0x44000000)    /* SEEPROM base address (type: io)*/
#define SDHC0_ADDR                     _UINT32_(0x45000000)    /* SDHC0 base address (type: io)*/
#define SDHC1_ADDR                     _UINT32_(0x46000000)    /* SDHC1 base address (type: io)*/
#define BKUPRAM_ADDR                   _UINT32_(0x47000000)    /* BKUPRAM base address (type: ram)*/
#define PPB_ADDR                       _UINT32_(0xe0000000)    /* PPB base address (type: io)*/
#define SCS_ADDR                       _UINT32_(0xe000e000)    /* SCS base address (type: io)*/

/* ************************************************************************** */
/*   DEVICE SIGNATURES FOR SAME54N19A                                         */
/* ************************************************************************** */
#define CHIP_DSU_DID                   _UINT32_(0X61840303)

/* ************************************************************************** */
/*   ELECTRICAL DEFINITIONS FOR SAME54N19A                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/* Event Generator IDs for SAME54N19A */
/* ************************************************************************** */
#define EVENT_ID_GEN_OSCCTRL_XOSC_FAIL_0                  1 /* ID for OSCCTRL event generator XOSC_FAIL_0 */
#define EVENT_ID_GEN_OSCCTRL_XOSC_FAIL_1                  2 /* ID for OSCCTRL event generator XOSC_FAIL_1 */
#define EVENT_ID_GEN_OSC32KCTRL_XOSC32K_FAIL              3 /* ID for OSC32KCTRL event generator XOSC32K_FAIL */
#define EVENT_ID_GEN_RTC_PER_0                            4 /* ID for RTC event generator PER_0 */
#define EVENT_ID_GEN_RTC_PER_1                            5 /* ID for RTC event generator PER_1 */
#define EVENT_ID_GEN_RTC_PER_2                            6 /* ID for RTC event generator PER_2 */
#define EVENT_ID_GEN_RTC_PER_3                            7 /* ID for RTC event generator PER_3 */
#define EVENT_ID_GEN_RTC_PER_4                            8 /* ID for RTC event generator PER_4 */
#define EVENT_ID_GEN_RTC_PER_5                            9 /* ID for RTC event generator PER_5 */
#define EVENT_ID_GEN_RTC_PER_6                           10 /* ID for RTC event generator PER_6 */
#define EVENT_ID_GEN_RTC_PER_7                           11 /* ID for RTC event generator PER_7 */
#define EVENT_ID_GEN_RTC_CMP_0                           12 /* ID for RTC event generator CMP_0 */
#define EVENT_ID_GEN_RTC_CMP_1                           13 /* ID for RTC event generator CMP_1 */
#define EVENT_ID_GEN_RTC_CMP_2                           14 /* ID for RTC event generator CMP_2 */
#define EVENT_ID_GEN_RTC_CMP_3                           15 /* ID for RTC event generator CMP_3 */
#define EVENT_ID_GEN_RTC_TAMPER                          16 /* ID for RTC event generator TAMPER */
#define EVENT_ID_GEN_RTC_OVF                             17 /* ID for RTC event generator OVF */
#define EVENT_ID_GEN_EIC_EXTINT_0                        18 /* ID for EIC event generator EXTINT_0 */
#define EVENT_ID_GEN_EIC_EXTINT_1                        19 /* ID for EIC event generator EXTINT_1 */
#define EVENT_ID_GEN_EIC_EXTINT_2                        20 /* ID for EIC event generator EXTINT_2 */
#define EVENT_ID_GEN_EIC_EXTINT_3                        21 /* ID for EIC event generator EXTINT_3 */
#define EVENT_ID_GEN_EIC_EXTINT_4                        22 /* ID for EIC event generator EXTINT_4 */
#define EVENT_ID_GEN_EIC_EXTINT_5                        23 /* ID for EIC event generator EXTINT_5 */
#define EVENT_ID_GEN_EIC_EXTINT_6                        24 /* ID for EIC event generator EXTINT_6 */
#define EVENT_ID_GEN_EIC_EXTINT_7                        25 /* ID for EIC event generator EXTINT_7 */
#define EVENT_ID_GEN_EIC_EXTINT_8                        26 /* ID for EIC event generator EXTINT_8 */
#define EVENT_ID_GEN_EIC_EXTINT_9                        27 /* ID for EIC event generator EXTINT_9 */
#define EVENT_ID_GEN_EIC_EXTINT_10                       28 /* ID for EIC event generator EXTINT_10 */
#define EVENT_ID_GEN_EIC_EXTINT_11                       29 /* ID for EIC event generator EXTINT_11 */
#define EVENT_ID_GEN_EIC_EXTINT_12                       30 /* ID for EIC event generator EXTINT_12 */
#define EVENT_ID_GEN_EIC_EXTINT_13                       31 /* ID for EIC event generator EXTINT_13 */
#define EVENT_ID_GEN_EIC_EXTINT_14                       32 /* ID for EIC event generator EXTINT_14 */
#define EVENT_ID_GEN_EIC_EXTINT_15                       33 /* ID for EIC event generator EXTINT_15 */
#define EVENT_ID_GEN_DMAC_CH_0                           34 /* ID for DMAC event generator CH_0 */
#define EVENT_ID_GEN_DMAC_CH_1                           35 /* ID for DMAC event generator CH_1 */
#define EVENT_ID_GEN_DMAC_CH_2                           36 /* ID for DMAC event generator CH_2 */
#define EVENT_ID_GEN_DMAC_CH_3                           37 /* ID for DMAC event generator CH_3 */
#define EVENT_ID_GEN_PAC_ACCERR                          38 /* ID for PAC event generator ACCERR */
#define EVENT_ID_GEN_TCC0_OVF                            41 /* ID for TCC0 event generator OVF */
#define EVENT_ID_GEN_TCC0_TRG                            42 /* ID for TCC0 event generator TRG */
#define EVENT_ID_GEN_TCC0_CNT                            43 /* ID for TCC0 event generator CNT */
#define EVENT_ID_GEN_TCC0_MC_0                           44 /* ID for TCC0 event generator MC_0 */
#define EVENT_ID_GEN_TCC0_MC_1                           45 /* ID for TCC0 event generator MC_1 */
#define EVENT_ID_GEN_TCC0_MC_2                           46 /* ID for TCC0 event generator MC_2 */
#define EVENT_ID_GEN_TCC0_MC_3                           47 /* ID for TCC0 event generator MC_3 */
#define EVENT_ID_GEN_TCC0_MC_4                           48 /* ID for TCC0 event generator MC_4 */
#define EVENT_ID_GEN_TCC0_MC_5                           49 /* ID for TCC0 event generator MC_5 */
#define EVENT_ID_GEN_TCC1_OVF                            50 /* ID for TCC1 event generator OVF */
#define EVENT_ID_GEN_TCC1_TRG                            51 /* ID for TCC1 event generator TRG */
#define EVENT_ID_GEN_TCC1_CNT                            52 /* ID for TCC1 event generator CNT */
#define EVENT_ID_GEN_TCC1_MC_0                           53 /* ID for TCC1 event generator MC_0 */
#define EVENT_ID_GEN_TCC1_MC_1                           54 /* ID for TCC1 event generator MC_1 */
#define EVENT_ID_GEN_TCC1_MC_2                           55 /* ID for TCC1 event generator MC_2 */
#define EVENT_ID_GEN_TCC1_MC_3                           56 /* ID for TCC1 event generator MC_3 */
#define EVENT_ID_GEN_TCC2_OVF                            57 /* ID for TCC2 event generator OVF */
#define EVENT_ID_GEN_TCC2_TRG                            58 /* ID for TCC2 event generator TRG */
#define EVENT_ID_GEN_TCC2_CNT                            59 /* ID for TCC2 event generator CNT */
#define EVENT_ID_GEN_TCC2_MC_0                           60 /* ID for TCC2 event generator MC_0 */
#define EVENT_ID_GEN_TCC2_MC_1                           61 /* ID for TCC2 event generator MC_1 */
#define EVENT_ID_GEN_TCC2_MC_2                           62 /* ID for TCC2 event generator MC_2 */
#define EVENT_ID_GEN_TCC3_OVF                            63 /* ID for TCC3 event generator OVF */
#define EVENT_ID_GEN_TCC3_TRG                            64 /* ID for TCC3 event generator TRG */
#define EVENT_ID_GEN_TCC3_CNT                            65 /* ID for TCC3 event generator CNT */
#define EVENT_ID_GEN_TCC3_MC_0                           66 /* ID for TCC3 event generator MC_0 */
#define EVENT_ID_GEN_TCC3_MC_1                           67 /* ID for TCC3 event generator MC_1 */
#define EVENT_ID_GEN_TCC4_OVF                            68 /* ID for TCC4 event generator OVF */
#define EVENT_ID_GEN_TCC4_TRG                            69 /* ID for TCC4 event generator TRG */
#define EVENT_ID_GEN_TCC4_CNT                            70 /* ID for TCC4 event generator CNT */
#define EVENT_ID_GEN_TCC4_MC_0                           71 /* ID for TCC4 event generator MC_0 */
#define EVENT_ID_GEN_TCC4_MC_1                           72 /* ID for TCC4 event generator MC_1 */
#define EVENT_ID_GEN_TC0_OVF                             73 /* ID for TC0 event generator OVF */
#define EVENT_ID_GEN_TC0_MC_0                            74 /* ID for TC0 event generator MC_0 */
#define EVENT_ID_GEN_TC0_MC_1                            75 /* ID for TC0 event generator MC_1 */
#define EVENT_ID_GEN_TC1_OVF                             76 /* ID for TC1 event generator OVF */
#define EVENT_ID_GEN_TC1_MC_0                            77 /* ID for TC1 event generator MC_0 */
#define EVENT_ID_GEN_TC1_MC_1                            78 /* ID for TC1 event generator MC_1 */
#define EVENT_ID_GEN_TC2_OVF                             79 /* ID for TC2 event generator OVF */
#define EVENT_ID_GEN_TC2_MC_0                            80 /* ID for TC2 event generator MC_0 */
#define EVENT_ID_GEN_TC2_MC_1                            81 /* ID for TC2 event generator MC_1 */
#define EVENT_ID_GEN_TC3_OVF                             82 /* ID for TC3 event generator OVF */
#define EVENT_ID_GEN_TC3_MC_0                            83 /* ID for TC3 event generator MC_0 */
#define EVENT_ID_GEN_TC3_MC_1                            84 /* ID for TC3 event generator MC_1 */
#define EVENT_ID_GEN_TC4_OVF                             85 /* ID for TC4 event generator OVF */
#define EVENT_ID_GEN_TC4_MC_0                            86 /* ID for TC4 event generator MC_0 */
#define EVENT_ID_GEN_TC4_MC_1                            87 /* ID for TC4 event generator MC_1 */
#define EVENT_ID_GEN_TC5_OVF                             88 /* ID for TC5 event generator OVF */
#define EVENT_ID_GEN_TC5_MC_0                            89 /* ID for TC5 event generator MC_0 */
#define EVENT_ID_GEN_TC5_MC_1                            90 /* ID for TC5 event generator MC_1 */
#define EVENT_ID_GEN_TC6_OVF                             91 /* ID for TC6 event generator OVF */
#define EVENT_ID_GEN_TC6_MC_0                            92 /* ID for TC6 event generator MC_0 */
#define EVENT_ID_GEN_TC6_MC_1                            93 /* ID for TC6 event generator MC_1 */
#define EVENT_ID_GEN_TC7_OVF                             94 /* ID for TC7 event generator OVF */
#define EVENT_ID_GEN_TC7_MC_0                            95 /* ID for TC7 event generator MC_0 */
#define EVENT_ID_GEN_TC7_MC_1                            96 /* ID for TC7 event generator MC_1 */
#define EVENT_ID_GEN_PDEC_OVF                            97 /* ID for PDEC event generator OVF */
#define EVENT_ID_GEN_PDEC_ERR                            98 /* ID for PDEC event generator ERR */
#define EVENT_ID_GEN_PDEC_DIR                            99 /* ID for PDEC event generator DIR */
#define EVENT_ID_GEN_PDEC_VLC                           100 /* ID for PDEC event generator VLC */
#define EVENT_ID_GEN_PDEC_MC_0                          101 /* ID for PDEC event generator MC_0 */
#define EVENT_ID_GEN_PDEC_MC_1                          102 /* ID for PDEC event generator MC_1 */
#define EVENT_ID_GEN_ADC0_RESRDY                        103 /* ID for ADC0 event generator RESRDY */
#define EVENT_ID_GEN_ADC0_WINMON                        104 /* ID for ADC0 event generator WINMON */
#define EVENT_ID_GEN_ADC1_RESRDY                        105 /* ID for ADC1 event generator RESRDY */
#define EVENT_ID_GEN_ADC1_WINMON                        106 /* ID for ADC1 event generator WINMON */
#define EVENT_ID_GEN_AC_COMP_0                          107 /* ID for AC event generator COMP_0 */
#define EVENT_ID_GEN_AC_COMP_1                          108 /* ID for AC event generator COMP_1 */
#define EVENT_ID_GEN_AC_WIN_0                           109 /* ID for AC event generator WIN_0 */
#define EVENT_ID_GEN_DAC_EMPTY_0                        110 /* ID for DAC event generator EMPTY_0 */
#define EVENT_ID_GEN_DAC_EMPTY_1                        111 /* ID for DAC event generator EMPTY_1 */
#define EVENT_ID_GEN_DAC_RESRDY_0                       112 /* ID for DAC event generator RESRDY_0 */
#define EVENT_ID_GEN_DAC_RESRDY_1                       113 /* ID for DAC event generator RESRDY_1 */
#define EVENT_ID_GEN_GMAC_TSU_CMP                       114 /* ID for GMAC event generator TSU_CMP */
#define EVENT_ID_GEN_TRNG_READY                         115 /* ID for TRNG event generator READY */
#define EVENT_ID_GEN_CCL_LUTOUT_0                       116 /* ID for CCL event generator LUTOUT_0 */
#define EVENT_ID_GEN_CCL_LUTOUT_1                       117 /* ID for CCL event generator LUTOUT_1 */
#define EVENT_ID_GEN_CCL_LUTOUT_2                       118 /* ID for CCL event generator LUTOUT_2 */
#define EVENT_ID_GEN_CCL_LUTOUT_3                       119 /* ID for CCL event generator LUTOUT_3 */

/* ************************************************************************** */
/*  Event User IDs for SAME54N19A */
/* ************************************************************************** */
#define EVENT_ID_USER_RTC_TAMPER                          0 /* ID for RTC event user TAMPER */
#define EVENT_ID_USER_PORT_EV_0                           1 /* ID for PORT event user EV_0 */
#define EVENT_ID_USER_PORT_EV_1                           2 /* ID for PORT event user EV_1 */
#define EVENT_ID_USER_PORT_EV_2                           3 /* ID for PORT event user EV_2 */
#define EVENT_ID_USER_PORT_EV_3                           4 /* ID for PORT event user EV_3 */
#define EVENT_ID_USER_DMAC_CH_0                           5 /* ID for DMAC event user CH_0 */
#define EVENT_ID_USER_DMAC_CH_1                           6 /* ID for DMAC event user CH_1 */
#define EVENT_ID_USER_DMAC_CH_2                           7 /* ID for DMAC event user CH_2 */
#define EVENT_ID_USER_DMAC_CH_3                           8 /* ID for DMAC event user CH_3 */
#define EVENT_ID_USER_DMAC_CH_4                           9 /* ID for DMAC event user CH_4 */
#define EVENT_ID_USER_DMAC_CH_5                          10 /* ID for DMAC event user CH_5 */
#define EVENT_ID_USER_DMAC_CH_6                          11 /* ID for DMAC event user CH_6 */
#define EVENT_ID_USER_DMAC_CH_7                          12 /* ID for DMAC event user CH_7 */
#define EVENT_ID_USER_CM4_TRACE_START                    14 /* ID for CM4 event user TRACE_START */
#define EVENT_ID_USER_CM4_TRACE_STOP                     15 /* ID for CM4 event user TRACE_STOP */
#define EVENT_ID_USER_CM4_TRACE_TRIG                     16 /* ID for CM4 event user TRACE_TRIG */
#define EVENT_ID_USER_TCC0_EV_0                          17 /* ID for TCC0 event user EV_0 */
#define EVENT_ID_USER_TCC0_EV_1                          18 /* ID for TCC0 event user EV_1 */
#define EVENT_ID_USER_TCC0_MC_0                          19 /* ID for TCC0 event user MC_0 */
#define EVENT_ID_USER_TCC0_MC_1                          20 /* ID for TCC0 event user MC_1 */
#define EVENT_ID_USER_TCC0_MC_2                          21 /* ID for TCC0 event user MC_2 */
#define EVENT_ID_USER_TCC0_MC_3                          22 /* ID for TCC0 event user MC_3 */
#define EVENT_ID_USER_TCC0_MC_4                          23 /* ID for TCC0 event user MC_4 */
#define EVENT_ID_USER_TCC0_MC_5                          24 /* ID for TCC0 event user MC_5 */
#define EVENT_ID_USER_TCC1_EV_0                          25 /* ID for TCC1 event user EV_0 */
#define EVENT_ID_USER_TCC1_EV_1                          26 /* ID for TCC1 event user EV_1 */
#define EVENT_ID_USER_TCC1_MC_0                          27 /* ID for TCC1 event user MC_0 */
#define EVENT_ID_USER_TCC1_MC_1                          28 /* ID for TCC1 event user MC_1 */
#define EVENT_ID_USER_TCC1_MC_2                          29 /* ID for TCC1 event user MC_2 */
#define EVENT_ID_USER_TCC1_MC_3                          30 /* ID for TCC1 event user MC_3 */
#define EVENT_ID_USER_TCC2_EV_0                          31 /* ID for TCC2 event user EV_0 */
#define EVENT_ID_USER_TCC2_EV_1                          32 /* ID for TCC2 event user EV_1 */
#define EVENT_ID_USER_TCC2_MC_0                          33 /* ID for TCC2 event user MC_0 */
#define EVENT_ID_USER_TCC2_MC_1                          34 /* ID for TCC2 event user MC_1 */
#define EVENT_ID_USER_TCC2_MC_2                          35 /* ID for TCC2 event user MC_2 */
#define EVENT_ID_USER_TCC3_EV_0                          36 /* ID for TCC3 event user EV_0 */
#define EVENT_ID_USER_TCC3_EV_1                          37 /* ID for TCC3 event user EV_1 */
#define EVENT_ID_USER_TCC3_MC_0                          38 /* ID for TCC3 event user MC_0 */
#define EVENT_ID_USER_TCC3_MC_1                          39 /* ID for TCC3 event user MC_1 */
#define EVENT_ID_USER_TCC4_EV_0                          40 /* ID for TCC4 event user EV_0 */
#define EVENT_ID_USER_TCC4_EV_1                          41 /* ID for TCC4 event user EV_1 */
#define EVENT_ID_USER_TCC4_MC_0                          42 /* ID for TCC4 event user MC_0 */
#define EVENT_ID_USER_TCC4_MC_1                          43 /* ID for TCC4 event user MC_1 */
#define EVENT_ID_USER_TC0_EVU                            44 /* ID for TC0 event user EVU */
#define EVENT_ID_USER_TC1_EVU                            45 /* ID for TC1 event user EVU */
#define EVENT_ID_USER_TC2_EVU                            46 /* ID for TC2 event user EVU */
#define EVENT_ID_USER_TC3_EVU                            47 /* ID for TC3 event user EVU */
#define EVENT_ID_USER_TC4_EVU                            48 /* ID for TC4 event user EVU */
#define EVENT_ID_USER_TC5_EVU                            49 /* ID for TC5 event user EVU */
#define EVENT_ID_USER_TC6_EVU                            50 /* ID for TC6 event user EVU */
#define EVENT_ID_USER_TC7_EVU                            51 /* ID for TC7 event user EVU */
#define EVENT_ID_USER_PDEC_EVU_0                         52 /* ID for PDEC event user EVU_0 */
#define EVENT_ID_USER_PDEC_EVU_1                         53 /* ID for PDEC event user EVU_1 */
#define EVENT_ID_USER_PDEC_EVU_2                         54 /* ID for PDEC event user EVU_2 */
#define EVENT_ID_USER_ADC0_START                         55 /* ID for ADC0 event user START */
#define EVENT_ID_USER_ADC0_SYNC                          56 /* ID for ADC0 event user SYNC */
#define EVENT_ID_USER_ADC1_START                         57 /* ID for ADC1 event user START */
#define EVENT_ID_USER_ADC1_SYNC                          58 /* ID for ADC1 event user SYNC */
#define EVENT_ID_USER_AC_SOC_0                           59 /* ID for AC event user SOC_0 */
#define EVENT_ID_USER_AC_SOC_1                           60 /* ID for AC event user SOC_1 */
#define EVENT_ID_USER_DAC_START_0                        61 /* ID for DAC event user START_0 */
#define EVENT_ID_USER_DAC_START_1                        62 /* ID for DAC event user START_1 */
#define EVENT_ID_USER_CCL_LUTIN_0                        63 /* ID for CCL event user LUTIN_0 */
#define EVENT_ID_USER_CCL_LUTIN_1                        64 /* ID for CCL event user LUTIN_1 */
#define EVENT_ID_USER_CCL_LUTIN_2                        65 /* ID for CCL event user LUTIN_2 */
#define EVENT_ID_USER_CCL_LUTIN_3                        66 /* ID for CCL event user LUTIN_3 */

#ifdef __cplusplus
}
#endif

#endif /* _SAME54N19A_H_ */

