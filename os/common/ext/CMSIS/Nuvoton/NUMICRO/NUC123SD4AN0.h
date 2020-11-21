/**************************************************************************//**
 * @file     NUC123SD4AN0.h
 * @brief    CMSIS Cortex-M0 Core Peripheral Access Layer Header File for
 *           Device NUC123SD4AN0
 * @version  V5.00
 * @date     13. May 2019
 ******************************************************************************/
/*
 * Copyright (c) 2019 /u/KeepItUnder. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NUC123SD4AN0_H      /* ToDo: replace '<Device>' with your device name */
#define NUC123SD4AN0_H

#ifdef __cplusplus
extern "C" {
#endif

/* ToDo: replace '<Vendor>' with vendor name; add your doxyGen comment   */
/** @addtogroup NUVOTON
  * @{
  */


/* ToDo: replace '<Device>' with device name; add your doxyGen comment   */
/** @addtogroup NUC123SD4AN0
  * @{
  */


/** @addtogroup Configuration_of_CMSIS
  * @{
  */



/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum IRQn {
/* =======================================  ARM Cortex-M0 Specific Interrupt Numbers  ======================================== */

/* ToDo: use this Cortex interrupt numbers if your device is a Cortex-M0 / Cortex-M0+ device */
  Reset_IRQn                = -15,              /*!< -15  Reset Vector, invoked on Power up and warm reset                     */
  NonMaskableInt_IRQn       = -14,              /*!< -14  Non maskable Interrupt, cannot be stopped or preempted               */
  HardFault_IRQn            = -13,              /*!< -13  Hard Fault, all classes of Fault                                     */
  SVCall_IRQn               =  -5,              /*!< -5 System Service Call via SVC instruction                                */
  PendSV_IRQn               =  -2,              /*!< -2 Pendable request for system service                                    */
  SysTick_IRQn              =  -1,              /*!< -1 System Tick Timer                                                      */

/* ===========================================  <Device> Specific Interrupt Numbers  ========================================= */
/* ToDo: add here your device specific external interrupt numbers
         according the interrupt handlers defined in startup_Device.s
         eg.: Interrupt for Timer#1       TIM1_IRQHandler   ->   TIM1_IRQn */
/**
 * IRQ numbers
 * 
 * See NUC123 Technical Reference Manual 5.2.3, page 32-33
 */
    BOD_OUT_IRQn            = 0,                // Brown-out low voltage detected interrupt
    WDT_IRQn                = 1,                // Watchdog/Window Watchdog Timer interrupt
    EINT0_IRQn              = 2,                // External signal interrupt from PB.14 pin
    EINT1_IRQn              = 3,                // External signal interrupt from PB.15 or PD.11 pin
    GPAB_IRQn               = 4,                // External signal interrupt from PA[15:0]/PB[13:0]
    GPCDF_IRQn              = 5,                // External interrupt from PC[15:0]/PD[15:0]/PF[3:0]
    PWMA_IRQn               = 6,                // PWM0, PWM1, PWM2 and PWM3 interrupt
    // IRQn                    = 7,                // Reserved
    TMR0_IRQn               = 8,                // Timer 0 interrupt
    TMR1_IRQn               = 9,                // Timer 1 interrupt
    TMR2_IRQn               = 10,               // Timer 2 interrupt
    TMR3_IRQn               = 11,               // Timer 3 interrupt
    UART0_IRQn              = 12,               // UART0 interrupt
    UART1_IRQn              = 13,               // UART1 interrupt
    SPI0_IRQn               = 14,               // SPI0 interrupt
    SPI1_IRQn               = 15,               // SPI1 interrupt
    SPI2_IRQn               = 16,               // SPI2 interrupt
    // IRQn                    = 17,               // Reserved
    I2C0_IRQn               = 18,               // I2C0 interrupt
    I2C1_IRQn               = 19,               // I2C1 interrupt
    // IRQn                    = 20,               // Reserved
    // IRQn                    = 21,               // Reserved
    // IRQn                    = 22,               // Reserved
    USBD_IRQn               = 23,               // USB 2.0 FS Device interrupt
    PS2_IRQn                = 24,               // PS/2 interrupt
    // IRQn                    = 25,               // Reserved
    PDMA_IRQn               = 26,               // PDMA interrupt
    I2S_IRQn                = 27,               // I2S interrupt
    PWRWU_IRQn              = 28,               // Clock controller interrupt for chip wake-up from Power-down state
    ADC_IRQn                = 29,               // ADC Interrupt
    // IRQn                    = 30,               // Reserved
    // IRQn                    = 31,               // Reserved
} IRQn_Type;



/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

/* ===========================  Configuration of the Arm Cortex-M4 Processor and Core Peripherals  =========================== */
/* ToDo: set the defines according your Device */
/* ToDo: define the correct core revision
         __CM0_REV if your device is a Cortex-M0 device
         __CM3_REV if your device is a Cortex-M3 device
         __CM4_REV if your device is a Cortex-M4 device
         __CM7_REV if your device is a Cortex-M7 device */
#define __CM0_REV                 0x0201    /*!< Core Revision r2p1 */

/* ToDo: define the correct core features for the <Device> */
#define __MPU_PRESENT             1         /*!< Set to 1 if MPU is present */
#define __VTOR_PRESENT            0         /*!< Set to 1 if VTOR is present */
#define __NVIC_PRIO_BITS          2         /*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             0         /*!< Set to 1 if FPU is present */
#define __FPU_DP                  0         /*!< Set to 1 if FPU is double precision FPU (default is single precision FPU) */
#define __ICACHE_PRESENT          0         /*!< Set to 1 if I-Cache is present */
#define __DCACHE_PRESENT          0         /*!< Set to 1 if D-Cache is present */
#define __DTCM_PRESENT            0         /*!< Set to 1 if DTCM is present */


/** @} */ /* End of group Configuration_of_CMSIS */


/* ToDo: include the correct core_cm#.h file
         core_cm0.h if your device is a CORTEX-M0 device
         core_cm3.h if your device is a CORTEX-M3 device
         core_cm4.h if your device is a CORTEX-M4 device
         core_cm7.h if your device is a CORTEX-M4 device */
#include <core_cm0.h>                           /*!< Arm Cortex-M# processor and core peripherals */
/* ToDo: include your system_<Device>.h file
         replace '<Device>' with your device name */
#include "system_NUC123SD4AN0.h"                    /*!< <Device> System */


/* ========================================  Start of section using anonymous unions  ======================================== */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */


/** @addtogroup NUC123SD4AN0_Peripherals
  * @{
  */

/* ToDo: add here your device specific peripheral access structure typedefs
         following is an example for a timer */

/* =========================================================================================================================== */
/* ================                                            TMR                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Timer (TMR)
  */

// typedef struct
// {                                               /*!< (@ 0x40000000) TIM Structure                                              */
//   __IOM uint32_t   TimerLoad;                   /*!< (@ 0x00000004) Timer Load                                                 */
//   __IM  uint32_t   TimerValue;                  /*!< (@ 0x00000008) Timer Counter Current Value                                */
//   __IOM uint32_t   TimerControl;                /*!< (@ 0x0000000C) Timer Control                                              */
//   __OM  uint32_t   TimerIntClr;                 /*!< (@ 0x00000010) Timer Interrupt Clear                                      */
//   __IM  uint32_t   TimerRIS;                    /*!< (@ 0x00000014) Timer Raw Interrupt Status                                 */
//   __IM  uint32_t   TimerMIS;                    /*!< (@ 0x00000018) Timer Masked Interrupt Status                              */
//   __IM  uint32_t   RESERVED[1];
//   __IOM uint32_t   TimerBGLoad;                 /*!< (@ 0x00000020) Background Load Register                                   */
// } <DeviceAbbreviation>_TMR_TypeDef;


/* =========================================================================================================================== */
/* ================                                    Clock Controller                                       ================ */
/* =========================================================================================================================== */


/**
  * @brief Clock Controller (CLK)
  * 
  * @description See NUC123 Technical Reference Manual 5.4.7 Register Map, page 106
  * 
  * CLK_BA = 0x5000_0200
  * 
  * Struct rearranged from table to track actual locations (without having to specify offsets)
  */
typedef struct {

    __IO uint32_t PWRCON;        // CLK_BA+0x00    System Power-down Control Register
    __IO uint32_t AHBCLK;        // CLK_BA+0x04    AHB Devices Clock Enable Control Register
    __IO uint32_t APBCLK;        // CLK_BA+0x08    APB Devices Clock Enable Control Register
    __IO uint32_t CLKSTATUS;     // CLK_BA+0x0C    Clock status monitor Register
    __IO uint32_t CLKSEL0;       // CLK_BA+0x10    Clock Source Select Control Register 0
    __IO uint32_t CLKSEL1;       // CLK_BA+0x14    Clock Source Select Control Register 1
    __IO uint32_t CLKDIV;        // CLK_BA+0x18    Clock Divider Number Register
    __IO uint32_t CLKSEL2;       // CLK_BA+0x1C    Clock Source Select Control Register 2
    __IO uint32_t PLLCON;        // CLK_BA+0x20    PLL Control Register
    __IO uint32_t FRQDIV;        // CLK_BA+0x24    Frequency Divider Control Register
    __I  uint32_t RESERVED0;     // CLK_BA+0x28    Missing from table    
    __IO uint32_t APBDIV;        // CLK_BA+0x2C    APB Divider Control Register

} CLK_T;

/**
  * @brief Clock Controller (CLK) - Register PWRCON
  * 
  * @description Power-down Control Register (PWRCON) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.4.8 Register Description, page 107-109
  * 
  * PWRCON = CLK_BA+0x00
  * 
  * 
  * XTL12M_EN [0]
  * External 4~24 MHz High Speed Crystal Enable (Write-protection Bit)
  * 
  * The bit default value is set by flash controller user configuration register config0
  * [26:24]. When the default clock source is from external 4~24 MHz high speed crystal,
  * this bit is set to 1 automatically
  * 
  * 1 = External 4~24 MHz high speed crystal Enabled
  * 0 = External 4~24 MHz high speed crystal Disabled
  * 
  * 
  * OSC22M_EN [2]
  * Internal 22.1184 MHz High Speed Oscillator Enable (Write-protection Bit)
  * 
  * 1 = Internal 22.1184 MHz high speed oscillator Enabled.
  * 0 = Internal 22.1184 MHz high speed oscillator Disabled.
  * 
  * 
  * OSC10K_EN [3]
  * Internal 10 kHz Low Speed Oscillator Enable (Write-protection Bit)
  * 
  * 1 = Internal 10 kHz low speed oscillator Enabled.
  * 0 = Internal 10 kHz low speed oscillator Disabled.
  * 
  * 
  * PD_WU_DLY [4]
  * Enable the Wake-up Delay Counter (Write-protection Bit)
  * 
  * When the chip wakes up from Power-down mode, the clock control will delay certain
  * clock cycles to wait system clock stable.
  * The delayed clock cycle is 4096 clock cycles when chip work at external 4~24 MHz
  * high speed crystal, and 256 clock cycles when chip work at internal 22.1184 MHz high
  * speed oscillator.
  * 
  * 1 = Clock cycles delay Enabled.
  * 0 = Clock cycles delay Disabled.
  * 
  * 
  * PD_WU_INT_EN [5]
  * Power-down Mode Wake-up Interrupt Enable (Write-protection Bit)
  * 
  * 0 = Disabled.
  * 1 = Enabled.
  * 
  * The interrupt will only occur when both PD_WU_STS and PD_WU_INT_EN are high.
  * 
  * 
  * PD_WU_STS [6]
  * Power-down Mode Wake-up Interrupt Status
  * 
  * Set by the "Power-down wake-up event", which indicates that resume from Power-down
  * mode has occured.
  * 
  * The flag is set if the GPIO, USB, UART, WDT, CAN, ACMP or BOD wake-up occurred.
  * 
  * Write 1 to clear the bit to zero.
  * 
  * Note: This bit works only when PD_WU_INT_EN (PWRCON[5]) set to 1.
  * 
  * 
  * PWE_DOWN_EN [7]
  * System Power-down Enable Bit (Write-protection Bit)
  * 
  * When this bit is set to 1, the chip Power-down mode is enabled and chip Power-down
  * behavior will depend on the PD_WAIT_CPU bit.
  * (a) If the PD_WAIT_CPU is 0, the chip enters Power-down mode immediately after the
  *     PWR_DOWN_EN bit set.
  * (b) If the PD_WAIT_CPU is 1, the chip keeps active till the CPU sleep mode is also
  *     active and then the chip enters Power-down mode
  * 
  * When the chip wakes up from Power-down mode, this bit is auto cleared. User needs to
  * set this bit again for next Power-down.
  * 
  * In Power-down mode, external 4~24 MHz high speed crystal and the internal 22.1184MHz
  * high speed oscillator will be disabled in this mode, but the internal 10 kHz low
  * speed oscillator is not controlled by Power-down mode.
  * 
  * In Power-down mode, the PLL and system clock are disabled, and ignored the clock
  * source selection. The clocks of peripheral are not controlled by Power-down mode, if
  * the peripheral clock source is from the internal 10 kHz low speed oscillator.
  * 
  * 1 = Chip entering the Power-down mode instantly or wait CPU sleep command - WFI
  * 0 = Chip operating normally or chip in Idle mode because of WFI command.
  * 
  * 
  * PD_WAIT_CPU [8]
  * Power-down Entry Conditions Control (Write-protection Bit)
  * 
  * 1 = Chip entering Power-down mode when the both PD_WAIT_CPU and
  *     PWR_DOWN_EN bits are set to 1 and CPU run WFI instruction.
  * 0 = Chip entering Power-down mode when the PWR_DOWN_EN bit is set to 1
  * 
  * 
  * See NUC123 Technical Reference Manual, page 109, for Power-Down Mode Control Table
  * which contains operating modes for Power-Down.
  * 
  */

#define CLK_PWRCON_XTL12M_EN_Pos                          0
#define CLK_PWRCON_XTL12M_EN_Msk                          (0x01ul << CLK_PWRCON_XTL12M_EN_Pos)
// Bit 1 is Reserved
#define CLK_PWRCON_OSC22M_EN_Pos                          2
#define CLK_PWRCON_OSC22M_EN_Msk                          (0x01ul << CLK_PWRCON_OSC22M_EN_Pos)
#define CLK_PWRCON_OSC10K_EN_Pos                          3
#define CLK_PWRCON_OSC10K_EN_Msk                          (0x01ul << CLK_PWRCON_OSC10K_EN_Pos)
#define CLK_PWRCON_PD_WU_DLY_Pos                          4
#define CLK_PWRCON_PD_WU_DLY_Msk                          (0x01ul << CLK_PWRCON_PD_WU_DLY_Pos)
#define CLK_PWRCON_PD_WU_INT_EN_Pos                       5
#define CLK_PWRCON_PD_WU_INT_EN_Msk                       (0x01ul << CLK_PWRCON_PD_WU_INT_EN_Pos)
#define CLK_PWRCON_PD_WU_STS_Pos                          6
#define CLK_PWRCON_PD_WU_STS_Msk                          (0x01ul << CLK_PWRCON_PD_WU_STS_Pos)
#define CLK_PWRCON_PWR_DOWN_EN_Pos                        7
#define CLK_PWRCON_PWR_DOWN_EN_Msk                        (0x01ul << CLK_PWRCON_PWR_DOWN_EN_Pos)
#define CLK_PWRCON_PD_WAIT_CPU_Pos                        8
#define CLK_PWRCON_PD_WAIT_CPU_Msk                        (0x01ul << CLK_PWRCON_PD_WAIT_CPU_Pos)
// Bits 9-31 are Reserved


/**
  * @brief Clock Controller (CLK) - Register AHBCLK
  * 
  * @description AHB Devices Clock Enable Control Register (AHBCLK) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.4.8 Register Description, page 110
  * 
  * AHBCLK = CLK_BA+0x04
  * 
  * 
  * PDMA_EN [1]
  * PDMA Controller Clock Enable Control
  * 
  * 1 = PDMA engine clock Enabled.
  * 0 = PDMA engine clock Disabled.
  * 
  * 
  * ISP_EN [2]
  * Flash ISP Controller Clock Enable Control
  * 
  * 1 = Flash ISP engine clock Enabled.
  * 0 = Flash ISP engine clock Disabled.
  * 
  */

// Bit 0 is Reserved.
#define CLK_AHBCLK_PDMA_EN_Pos                            1
#define CLK_AHBCLK_PDMA_EN_Msk                            (0x01ul << CLK_AHBCLK_PDMA_EN_Pos)
#define CLK_AHBCLK_ISP_EN_Pos                             2
#define CLK_AHBCLK_ISP_EN_Msk                             (0x01ul << CLK_AHBCLK_ISP_EN_Pos)
//Bits 3-31 are Reserved.

/**
  * @brief Clock Controller (CLK) - Register APBCLK
  * 
  * @description APB Devices Clock Enable Control Register (APBCLK) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.4.8 Register Description, page 111-113
  * 
  * APBCLK = CLK_BA+0x08
  * 
  * 
  * WDT_EN [0]
  * Watchdog Timer Clock Enable (Write-protection Bit)
  * 
  * 1 = Watchdog Timer Clock Enabled.
  * 0 = Watchdog Timer Clock Disabled.
  * 
  * This bit is the protected bit, which means programming it needs to write "59h", "16h",
  * "88h" to address 0x5000_0100 to disable register protection.
  * 
  * Refer to the register REGWRPROT at address GCR_BA+0x100.
  * 
  * 
  * TMR0_EN [2]
  * Timer0 Clock Enable
  * 
  * 1 = Timer0 clock Enabled.
  * 0 = Timer0 clock Disabled.
  * 
  * 
  * TMR1_EN [3]
  * Timer1 Clock Enable
  * 
  * 1 = Timer1 clock Enabled.
  * 0 = Timer1 clock Disabled.
  * 
  * 
  * TMR2_EN [4]
  * Timer2 Clock Enable
  * 
  * 1 = Timer2 clock Enabled.
  * 0 = Timer2 clock Disabled.
  * 
  * 
  * TMR3_EN [5]
  * Timer3 Clock Enable
  * 
  * 1 = Timer3 clock Enabled.
  * 0 = Timer3 clock Disabled.
  * 
  * 
  * FDIV_EN [6]
  * Frequency Divider Output Clock Enable
  * 
  * 1 = FDIV clock Enabled.
  * 0 = FDIV clock Disabled.
  * 
  * 
  * I2C0_EN [8]
  * I2C0 Clock Enable
  * 
  * 1 = I2C0 clock Enabled.
  * 0 = I2C0 clock Disabled.
  * 
  * 
  * I2C1_EN [9]
  * I2C1 Clock Enable
  * 
  * 1 = I2C1 clock Enabled.
  * 0 = I2C1 clock Disabled.
  * 
  * 
  * SPI0_EN [12]
  * SPI0 Clock Enable
  * 
  * 1 = SPI0 clock Enabled.
  * 0 = SPI0 clock Disabled.
  * 
  * 
  * SPI1_EN [13]
  * SPI1 Clock Enable
  * 
  * 1 = SPI1 clock Enabled.
  * 0 = SPI1 clock Disabled.
  * 
  * 
  * SPI2_EN [14]
  * SPI2 Clock Enable
  * 
  * 1 = SPI2 clock Enabled.
  * 0 = SPI2 clock Disabled.
  * 
  * 
  * UART0_EN [16]
  * UART0 Clock Enable
  * 
  * 1 = UART0 clock Enabled.
  * 0 = UART0 clock Disabled.
  * 
  * 
  * UART1_EN [16]
  * UART1 Clock Enable
  * 
  * 1 = UART1 clock Enabled.
  * 0 = UART1 clock Disabled.
  * 
  * 
  * PWM01_EN [20]
  * PWM_01 Clock Enable
  * 
  * 1 = PWM01 clock Enabled.
  * 0 = PWM01 clock Disabled.
  * 
  * 
  * PWM23_EN [21]
  * PWM_23 Clock Enable
  * 
  * 1 = PWM23 clock Enabled.
  * 0 = PWM23 clock Disabled.
  * 
  * 
  * USBD_EN [27]
  * USB 2.0 FS Device Controller Clock Enable
  * 
  * 1 = USB clock Enabled.
  * 0 = USB clock Disabled.
  * 
  * 
  * ADC_EN [28]
  * Analog-Digital-Converter (ADC) Clock Enable
  * 
  * 1 = ADC clock Enabled.
  * 0 = ADC clock Disabled.
  * 
  * 
  * I2S_EN [29]
  * I2S Clock Enable
  * 
  * 1 = I2S Clock Enabled.
  * 0 = I2S Clock Disabled.
  * 
  * 
  * PS2_EN [31]
  * PS/2 Clock Enable
  * 
  * 1 = PS/2 clock Enabled.
  * 0 = PS/2 clock Disabled.
  * 
  */

#define CLK_APBCLK_WDT_EN_Pos                             0
#define CLK_APBCLK_WDT_EN_Msk                             (0x01ul << CLK_APBCLK_WDT_EN_Pos)
// Bit 1 is Reserved.
#define CLK_APBCLK_TMR0_EN_Pos                            2
#define CLK_APBCLK_TMR0_EN_Msk                            (0x01ul << CLK_APBCLK_TMR0_EN_Pos)
#define CLK_APBCLK_TMR1_EN_Pos                            3
#define CLK_APBCLK_TMR1_EN_Msk                            (0x01ul << CLK_APBCLK_TMR1_EN_Pos)
#define CLK_APBCLK_TMR2_EN_Pos                            4
#define CLK_APBCLK_TMR2_EN_Msk                            (0x01ul << CLK_APBCLK_TMR2_EN_Pos)
#define CLK_APBCLK_TMR3_EN_Pos                            5
#define CLK_APBCLK_TMR3_EN_Msk                            (0x01ul << CLK_APBCLK_TMR3_EN_Pos)
#define CLK_APBCLK_FDIV_EN_Pos                            6
#define CLK_APBCLK_FDIV_EN_Msk                            (0x01ul << CLK_APBCLK_FDIV_EN_Pos)
// Bit 7 is Reserved.
#define CLK_APBCLK_I2C0_EN_Pos                            8
#define CLK_APBCLK_I2C0_EN_Msk                            (0x01ul << CLK_APBCLK_I2C0_EN_Pos)
#define CLK_APBCLK_I2C1_EN_Pos                            9
#define CLK_APBCLK_I2C1_EN_Msk                            (0x01ul << CLK_APBCLK_I2C1_EN_Pos)
// Bits 10-11 are Reserved.
#define CLK_APBCLK_SPI0_EN_Pos                            12
#define CLK_APBCLK_SPI0_EN_Msk                            (0x01ul << CLK_APBCLK_SPI0_EN_Pos)
#define CLK_APBCLK_SPI1_EN_Pos                            13
#define CLK_APBCLK_SPI1_EN_Msk                            (0x01ul << CLK_APBCLK_SPI1_EN_Pos)
#define CLK_APBCLK_SPI2_EN_Pos                            14
#define CLK_APBCLK_SPI2_EN_Msk                            (0x01ul << CLK_APBCLK_SPI2_EN_Pos)
// Bit 15 is Reserved.
#define CLK_APBCLK_UART0_EN_Pos                           16
#define CLK_APBCLK_UART0_EN_Msk                           (0x01ul << CLK_APBCLK_UART0_EN_Pos)
#define CLK_APBCLK_UART1_EN_Pos                           17
#define CLK_APBCLK_UART1_EN_Msk                           (0x01ul << CLK_APBCLK_UART1_EN_Pos)
// Bits 18-19 are Reserved.
#define CLK_APBCLK_PWM01_EN_Pos                           20
#define CLK_APBCLK_PWM01_EN_Msk                           (0x01ul << CLK_APBCLK_PWM01_EN_Pos)
#define CLK_APBCLK_PWM23_EN_Pos                           21
#define CLK_APBCLK_PWM23_EN_Msk                           (0x01ul << CLK_APBCLK_PWM23_EN_Pos)
// Bits 22-26 are Reserved.
#define CLK_APBCLK_USBD_EN_Pos                            27
#define CLK_APBCLK_USBD_EN_Msk                            (0x01ul << CLK_APBCLK_USBD_EN_Pos)
#define CLK_APBCLK_ADC_EN_Pos                             28
#define CLK_APBCLK_ADC_EN_Msk                             (0x01ul << CLK_APBCLK_ADC_EN_Pos)
#define CLK_APBCLK_I2S_EN_Pos                             29
#define CLK_APBCLK_I2S_EN_Msk                             (0x01ul << CLK_APBCLK_I2S_EN_Pos)
// Bit 30 is Reserved.
#define CLK_APBCLK_PS2_EN_Pos                             31
#define CLK_APBCLK_PS2_EN_Msk                             (0x01ul << CLK_APBCLK_PS2_EN_Pos)


/**
  * @brief Clock Controller (CLK) - Register CLKSTATUS
  * 
  * @description Clock Status Register (CLKSTATUS) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.4.8 Register Description, page 114-115
  * 
  * CLKSTATUS = CLK_BA+0x0C
  * 
  * 
  * XTL12M_STB [0]
  * External 4~24 MHz High Speed Crystal Clock Source Stable Flag
  * 
  * 1 = External 4~24 MHz high speed crystal clock is stable.
  * 0 = External 4~24 MHz high speed crystal clock is not stable or disabled.
  * 
  * This is read only bit.
  * 
  * 
  * PLL_STB [2]
  * Internal PLL Clock Source Stable Flag
  * 
  * 1 = Internal PLL clock is stable.
  * 0 = Internal PLL clock is not stable or disabled.
  * 
  * This is read only bit.
  * 
  * 
  * OSC10K_STB [3]
  * Internal 10 kHz Low Speed Oscillator Clock Source Stable Flag
  * 
  * 1 = Internal 10 kHz low speed oscillator clock is stable.
  * 0 = Internal 10 kHz low speed oscillator clock is not stable or disabled.
  * 
  * This is read only bit.
  * 
  * 
  * OSC22M_STB [4]
  * Internal 22.1184 MHz High Speed Oscillator Clock Source Stable Flag
  * 
  * 1 = Internal 22.1184 MHz high speed oscillator clock is stable.
  * 0 = Internal 22.1184 MHz high speed oscillator clock is not stable or disabled.
  * 
  * This is read only bit
  * 
  * 
  * CLK_SW_FAIL [7]
  * Clock Switching Fail Flag (Write-protection Bit)
  * 
  * 1 = Clock switching failed.
  * 0 = Clock switching success.
  * 
  * This bit is updated when software switches system clock source. If switch target clock
  * is stable, this bit will be set to 0.
  * If switch target clock is not stable, this bit will be set to 1.
  * 
  * Write 1 to clear the bit to zero.
  * 
  */

#define CLK_CLKSTATUS_XTL12M_STB_Pos                      0
#define CLK_CLKSTATUS_XTL12M_STB_Msk                      (0x01ul << CLK_CLKSTATUS_XTL12M_STB_Pos)
// Bit 1 is Reserved.
#define CLK_CLKSTATUS_PLL_STB_Pos                         2
#define CLK_CLKSTATUS_PLL_STB_Msk                         (0x01ul << CLK_CLKSTATUS_PLL_STB_Pos)
#define CLK_CLKSTATUS_OSC10K_STB_Pos                      3
#define CLK_CLKSTATUS_OSC10K_STB_Msk                      (0x01ul << CLK_CLKSTATUS_OSC10K_STB_Pos)
#define CLK_CLKSTATUS_OSC22M_STB_Pos                      4
#define CLK_CLKSTATUS_OSC22M_STB_Msk                      (0x01ul << CLK_CLKSTATUS_OSC22M_STB_Pos)
// Bits 5-6 are Reserved.
#define CLK_CLKSTATUS_CLK_SW_FAIL_Pos                     7
#define CLK_CLKSTATUS_CLK_SW_FAIL_Msk                     (0x01ul << CLK_CLKSTATUS_CLK_SW_FAIL_Pos)
// Bits 8-31 are Reserved.


/**
  * @brief Clock Controller (CLK) - Register CLKSEL0
  * 
  * @description Clock Source Select Control Register 0 (CLKSEL0) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.4.8 Register Description, page 116
  * 
  * CLKSEL0 = CLK_BA+0x10
  * 
  * 
  * HCLK_S [0:2]
  * HCLK Clock Source Selection (Write-protection Bits)
  * 
  * 000 = Clock source from external 4~24 MHz high speed crystal clock
  * 001 = Clock source from PLL clock/2
  * 010 = Clock source from PLL clock
  * 011 = Clock source from internal 10 kHz low speed oscillator clock
  * 111 = Clock source from internal 22.1184 MHz high speed oscillator clock
  * 
  * Note 1 Before clock switching, the related clock sources (both pre-select and new-select)
  *        must be turn on.
  * Note 2 The 3-bit default value is reloaded from the value of CFOSC (Config0[26:24]) in
  *        user configuration register of Flash controller by any reset. Therefore the default
  *        value is either 000b or 111b.
  * 
  * 
  * STCLK_S [3:5]
  * Cortex_M0 SysTick Clock Source Selection (Write-protection Bits)
  * 
  * If SYST_CSR[2]= 0, SysTick uses clock source listed below.
  * 000 = Clock source from external 4~24 MHz high speed crystal clock
  * 010 = Clock source from external 4~24 MHz high speed crystal clock/2
  * 011 = Clock source from HCLK/2
  * 111 = Clock source from internal 22.1184 MHz high speed oscillator clock/2
  * 
  * 
  * All these bits are protected bit, It means programming this bit needs to write
  * "59h", "16h", "88h" to address 0x5000_0100 to disable register protection.
  * 
  * Refer to the register REGWRPROT at address GCR_BA+0x100.
  * 
  */

/* CLK CLKSEL0 Bit Field Definitions */
#define CLK_CLKSEL0_HCLK_S_Pos                            0
#define CLK_CLKSEL0_HCLK_S_Msk                            (0b0111ul << CLK_CLKSEL0_HCLK_S_Pos)
#define CLK_CLKSEL0_STCLK_S_Pos                           3
#define CLK_CLKSEL0_STCLK_S_Msk                           (0b0111ul << CLK_CLKSEL0_STCLK_S_Pos)
// Bits 4-31 are Reserved.


/**
  * @brief Clock Controller (CLK) - Register CLKSEL1
  * 
  * @description Clock Source Select Control Register 1 (CLKSEL1) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.4.8 Register Description, page 117-119
  * 
  * CLKSEL1 = CLK_BA+0x14
  * 
  * 
  * WDT_S [0:1]
  * Watchdog Timer Clock Source Selection (Write-protection Bits)
  * 
  * 10 = Clock source from HCLK/2048 clock.
  * 11 = Clock source from internal 10 kHz low speed oscillator clock.
  * 
  * These bits are protected bits and programming this needs to write "59h", "16h", "88h" to
  * address 0x5000_0100 to disable register protection.
  * Refer to the register REGWRPROT at address GCR_BA+0x100.
  * 
  * 
  * ADC_S [2:3]
  * ADC Clock Source Selection
  * 
  * 00 = Clock source from external 4~24 MHz high speed crystal clock
  * 01 = Clock source from PLL clock
  * 10 = Clock source from HCLK
  * 11 = Clock source from internal 22.1184 MHz high speed oscillator clock
  * 
  * 
  * SPI0_S [4]
  * SPI0 Clock Source Selection
  * 
  * 1 = Clock source from HCLK.
  * 0 = Clock source from PLL clock.
  * 
  * 
  * SPI1_S [5]
  * SPI1 Clock Source Selection
  * 
  * 1 = Clock source from HCLK.
  * 0 = Clock source from PLL clock.
  * 
  * 
  * SPI2_S [6]
  * SPI2 Clock Source Selection
  * 
  * 1 = Clock source from HCLK.
  * 0 = Clock source from PLL clock.
  * 
  * 
  * TMR0_S [8:10]
  * TIMER0 Clock Source Selection
  * 
  * 000 = Clock source from external 4~24 MHz high speed crystal clock.
  * 010 = Clock source from HCLK.
  * 011 = Clock source from external clock source TM0.
  * 100 = Clock source from internal 10 kHz low speed oscillator clock.
  * 111 = Clock source from internal 22.1184 MHz high speed oscillator clock.
  * 
  * 
  * TMR1_S [12:14]
  * TIMER1 Clock Source Selection
  * 
  * 000 = Clock source from external 4~24 MHz high speed crystal clock.
  * 010 = Clock source from HCLK.
  * 011 = Clock source from external clock source TM1.
  * 100 = Clock source from internal 10 kHz low speed oscillator clock.
  * 111 = Clock source from internal 22.1184 MHz high speed oscillator clock.
  * 
  * 
  * TMR2_S [16:18]
  * TIMER2 Clock Source Selection
  * 
  * 000 = Clock source from external 4~24 MHz high speed crystal clock.
  * 010 = Clock source from HCLK.
  * 011 = Clock source from external clock source TM2.
  * 100 = Clock source from internal 10 kHz low speed oscillator clock.
  * 111 = Clock source from internal 22.1184 MHz high speed oscillator clock.
  * 
  * 
  * TMR3_S [20:22]
  * TIMER3 Clock Source Selection
  * 
  * 000 = Clock source from external 4~24 MHz high speed crystal clock.
  * 010 = Clock source from HCLK.
  * 011 = Clock source from external clock source TM3.
  * 100 = Clock source from internal 10 kHz low speed oscillator clock.
  * 111 = Clock source from internal 22.1184 MHz high speed oscillator clock.
  * 
  * 
  * UART_S [24:25]
  * UART Clock Source Selection
  * 
  * 00 = Clock source from external 4~24 MHz high speed crystal clock.
  * 01 = Clock source from PLL clock.
  * 11 = Clock source from internal 22.1184 MHz high speed oscillator clock.
  * 
  * 
  * PWM01_S [28:29]
  * PWM0 and PWM1 Clock Source Select Bit [1:0]
  * 
  * PWM0 and PWM1 use the same Engine clock source, and both of them use the same
  * prescaler
  * 
  * The Engine clock source of PWM0 and PWM1 is defined by PWM01_S[0:2] and this
  * field is combined by CLKSEL2[8] and CLKSEL1[29:28].
  * 
  * 000 = Clock source from external 4~24 MHz high speed crystal clock.
  * 010 = Clock source from HCLK.
  * 011 = Clock source from internal 22.1184 MHz high speed oscillator clock.
  * 111 = Clock source from internal 10 kHz low speed oscillator clock.
  * 
  * 
  * PWM23_S [30:31]
  * PWM2 and PWM3 Clock Source Select Bit [1:0]
  * 
  * PWM2 and PWM3 use the same Engine clock source, and both of them use the same
  * prescaler
  * 
  * The Engine clock source of PWM2 and PWM3 is defined by PWM23_S[0:2] and this
  * field is combined by CLKSEL2[9] and CLKSEL1[30:31].
  * 
  * 000 = Clock source from external 4~24 MHz high speed crystal clock.
  * 010 = Clock source from HCLK.
  * 011 = Clock source from internal 22.1184 MHz high speed oscillator clock.
  * 111 = Clock source from internal 10 kHz low speed oscillator clock.
  * 
  * 
  * NOTE: Before clock switching, the related clock sources (pre-select and new-select)
  * must be turned on.
  * 
  */

#define CLK_CLKSEL1_WDT_S_Pos                             0
#define CLK_CLKSEL1_WDT_S_Msk                             (0b011ul << CLK_CLKSEL1_WDT_S_Pos)
#define CLK_CLKSEL1_ADC_S_Pos                             2
#define CLK_CLKSEL1_ADC_S_Msk                             (0b011ul << CLK_CLKSEL1_ADC_S_Pos)
#define CLK_CLKSEL1_SPI0_S_Pos                            4
#define CLK_CLKSEL1_SPI0_S_Msk                            (0b01ul << CLK_CLKSEL1_SPI0_S_Pos)
#define CLK_CLKSEL1_SPI1_S_Pos                            5
#define CLK_CLKSEL1_SPI1_S_Msk                            (0b01ul << CLK_CLKSEL1_SPI1_S_Pos)
#define CLK_CLKSEL1_SPI2_S_Pos                            6
#define CLK_CLKSEL1_SPI2_S_Msk                            (0b01ul << CLK_CLKSEL1_SPI2_S_Pos)
// Bit 7 is Reserved.
#define CLK_CLKSEL1_TMR0_S_Pos                            8
#define CLK_CLKSEL1_TMR0_S_Msk                            (0b0111ul << CLK_CLKSEL1_TMR0_S_Pos)
// Bit 11 is Reserved.
#define CLK_CLKSEL1_TMR1_S_Pos                            12
#define CLK_CLKSEL1_TMR1_S_Msk                            (0b0111ul << CLK_CLKSEL1_TMR1_S_Pos)
// Bit 15 is Reserved.
#define CLK_CLKSEL1_TMR2_S_Pos                            16
#define CLK_CLKSEL1_TMR2_S_Msk                            (0b0111ul << CLK_CLKSEL1_TMR2_S_Pos)
// Bit 19 is Reserved.
#define CLK_CLKSEL1_TMR3_S_Pos                            20
#define CLK_CLKSEL1_TMR3_S_Msk                            (0b0111ul << CLK_CLKSEL1_TMR3_S_Pos)
// Bit 23 is Reserved.
#define CLK_CLKSEL1_UART_S_Pos                            24
#define CLK_CLKSEL1_UART_S_Msk                            (0b011ul << CLK_CLKSEL1_UART_S_Pos)
// Bits 26-27 are Reserved.
#define CLK_CLKSEL1_PWM01_S_Pos                           28
#define CLK_CLKSEL1_PWM01_S_Msk                           (0b011ul << CLK_CLKSEL1_PWM01_S_Pos)
#define CLK_CLKSEL1_PWM23_S_Pos                           30
#define CLK_CLKSEL1_PWM23_S_Msk                           (0b011ul << CLK_CLKSEL1_PWM23_S_Pos)


/**
  * @brief Clock Controller (CLK) - Register CLKSEL2
  * 
  * @description Clock Source Select Control Register 2 (CLKSEL2) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.4.8 Register Description, page 120-121
  * 
  * CLKSEL2 = CLK_BA+0x1C
  * 
  * 
  * I2S_S [0:1]
  * I2S Clock Source Selection
  * 
  * 00 = Clock source from external 4~24 MHz high speed crystal clock.
  * 01 = Clock source from HCLK.
  * 10 = Clock source from PLL clock.
  * 11 = Clock source from internal 22.1184 MHz high speed oscillator clock.
  * 
  * 
  * FRQDIV_S [2:3]
  * Clock Divider Clock Source Selection
  * 
  * 00 = Clock source from external 4~24 MHz high speed crystal clock.
  * 01 = Clock source from HCLK.
  * 10 = Reserved.
  * 11 = Clock source from internal 22.1184 MHz high speed oscillator clock.
  * 
  * 
  * PWM01_S [2]
  * PWM0 and PWM1 Clock Source Select Bit [2]
  * 
  * PWM0 and PWM1 use the same Engine clock source, and both of them use the same
  * prescaler.
  * 
  * The Engine clock source of PWM0 and PWM1 is defined by PWM01_S[2:0] and this
  * field is combined by CLKSEL2[8] and CLKSEL1[29:28].
  * 
  * 000 = Clock source from external 4~24 MHz high speed crystal clock.
  * 010 = Clock source from HCLK.
  * 011 = Clock source from internal 22.1184 MHz high speed oscillator clock.
  * 111 = Clock source from internal 10 kHz low speed oscillator clock.
  * 
  * 
  * PWM23_S [9]
  * PWM2 and PWM3 Clock Source Select Bit [2]
  * 
  * PWM2 and PWM3 use the same Engine clock source, and both of them use the same
  * prescaler.
  * 
  * The Engine clock source of PWM2 and PWM3 is defined by PWM23_S[2:0] and this
  * field is combined by CLKSEL2[9] and CLKSEL1[31:30].
  * 
  * 000 = Clock source from external 4~24 MHz high speed crystal clock.
  * 010 = Clock source from HCLK.
  * 011 = Clock source from internal 22.1184 MHz high speed oscillator clock.
  * 111 = Clock source from internal 10 kHz low speed oscillator clock.
  * 
  * 
  * WWDT_S [16:17]
  * Windowed-Watchdog Timer Clock Source Selection (Write-protection Bits)
  * 
  * 10 = Clock source from HCLK/2048 clock.
  * 11 = Clock source from internal 10 kHz low speed oscillator clock.
  * 
  * 
  * NOTE: Before clock switching, the related clock sources (pre-select and new-select)
  * must be turned on.
  * 
  */

#define CLK_CLKSEL2_I2S_S_Pos                             0
#define CLK_CLKSEL2_I2S_S_Msk                             (0b011ul << CLK_CLKSEL2_I2S_S_Pos)
#define CLK_CLKSEL2_FRQDIV_S_Pos                          2
#define CLK_CLKSEL2_FRQDIV_S_Msk                          (0b011ul << CLK_CLKSEL2_FRQDIV_S_Pos)
// Bits 4-7 are Reserved.
#define CLK_CLKSEL2_PWM01_S_Pos                           8
#define CLK_CLKSEL2_PWM01_S_Msk                           (0b01ul << CLK_CLKSEL2_PWM01_S_Pos)
#define CLK_CLKSEL2_PWM23_S_Pos                           9
#define CLK_CLKSEL2_PWM23_S_Msk                           (0b01ul << CLK_CLKSEL2_PWM23_S_Pos)
// Bits 10-15 are Reserved.
#define CLK_CLKSEL2_WWDT_S_Pos                            16
#define CLK_CLKSEL2_WWDT_S_Msk                            (0b011ul << CLK_CLKSEL2_WWDT_S_Pos)
// Bits 18-31 are Reserved.


/**
  * @brief Clock Controller (CLK) - Register CLKDIV
  * 
  * @description Clock Divider Register (CLKDIV) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.4.8 Register Description, page 122
  * 
  * CLKDIV = CLK_BA+0x18
  * 
  * 
  * HCLK_N [0:3]
  * HCLK Clock Divide Number from HCLK Clock Source
  * 
  * HCLK clock frequency = (HCLK clock source frequency) / (HCLK_N + 1)
  * 
  * 
  * USB_N [4:7]
  * USB Clock Divide Number from PLL Clock
  * 
  * USB clock frequency = (PLL frequency ) / (USB_N + 1)
  * 
  * 
  * UART_N [8:11]
  * UART Clock Divide Number from UART Clock Source
  * 
  * UART clock frequency = (UART clock source frequency ) / (UART_N + 1)
  * 
  * 
  * ADC_N [16:23]
  * ADC Clock Divide Number from ADC Clock Source
  * 
  * ADC clock frequency = (ADC clock source frequency ) / (ADC_N + 1)
  * 
  */

#define CLK_CLKDIV_HCLK_N_Pos                             0
#define CLK_CLKDIV_HCLK_N_Msk                             (0x0Ful << CLK_CLKDIV_HCLK_N_Pos)
#define CLK_CLKDIV_USB_N_Pos                              4
#define CLK_CLKDIV_USB_N_Msk                              (0x0Ful << CLK_CLKDIV_USB_N_Pos)
#define CLK_CLKDIV_UART_N_Pos                             8
#define CLK_CLKDIV_UART_N_Msk                             (0x0Ful << CLK_CLKDIV_UART_N_Pos)
// Bits 12-15 are Reserved.
#define CLK_CLKDIV_ADC_N_Pos                              16
#define CLK_CLKDIV_ADC_N_Msk                              (0xFFul << CLK_CLKDIV_ADC_N_Pos)
// Bits 24-31 are Reserved.


/**
  * @brief Clock Controller (CLK) - Register PLLCON
  * 
  * @description PLL Control Register (PLLCON) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.4.8 Register Description, page 123-124
  * 
  * PLLCON = CLK_BA+0x18
  * 
  * 
  * FB_DV [0:8]
  * PLL Feedback Divider Control Pins
  * 
  * See formulas on NUC123 Technical Reference Manual, page 124
  * 
  * 
  * IN_DV [9:13]
  * PLL Input Divider Control Pins
  * 
  * See formulas on NUC123 Technical Reference Manual, page 124
  * 
  * 
  * OUT_DV [14:15]
  * PLL Output Divider Control Pins
  * 
  * See formulas on NUC123 Technical Reference Manual, page 124
  * 
  * OUT_DV = "00" : NO = 1
  * OUT_DV = "01" : NO = 2
  * OUT_DV = "10" : NO = 2
  * OUT_DV = "11" : NO = 4
  * 
  * 
  * PD [16]
  * Power-down Mode
  * 
  * If the PWR_DOWN_EN bit set to 1 in PWRCON register, the PLL will also enter
  * Power-down mode.
  * 
  * 0 = PLL is in Normal mode.
  * 1 = PLL is in Power-down mode (default).
  * 
  * 
  * BP [17]
  * PLL Bypass Control
  * 
  * 0 = PLL is in Normal mode (default).
  * 1 = PLL clock output is the same as clock input (XTALin).
  * 
  * 
  * OE [18]
  * PLL OE (FOUT Enable) Pin Control
  * 
  * 0 = PLL FOUT Enabled.
  * 1 = PLL FOUT is fixed low.
  * 
  * 
  * PLL_SRC [19]
  * PLL Source Clock Selection
  * 
  * 1 = PLL source clock from internal 22.1184 MHz high speed oscillator.
  * 0 = PLL source clock from external 4~24 MHz high speed crystal.
  * 
  */

#define CLK_PLLCON_FB_DV_Pos                              0
#define CLK_PLLCON_FB_DV_Msk                              (0x1FFul << CLK_PLLCON_FB_DV_Pos)
#define CLK_PLLCON_IN_DV_Pos                              9
#define CLK_PLLCON_IN_DV_Msk                              (0x01Ful << CLK_PLLCON_IN_DV_Pos)
#define CLK_PLLCON_OUT_DV_Pos                             14
#define CLK_PLLCON_OUT_DV_Msk                             (0x03ul << CLK_PLLCON_OUT_DV_Pos)
#define CLK_PLLCON_PD_Pos                                 16
#define CLK_PLLCON_PD_Msk                                 (0x01ul << CLK_PLLCON_PD_Pos)
#define CLK_PLLCON_BP_Pos                                 17
#define CLK_PLLCON_BP_Msk                                 (0x01ul << CLK_PLLCON_BP_Pos)
#define CLK_PLLCON_OE_Pos                                 18
#define CLK_PLLCON_OE_Msk                                 (0x01ul << CLK_PLLCON_OE_Pos)
#define CLK_PLLCON_PLL_SRC_Pos                            19
#define CLK_PLLCON_PLL_SRC_Msk                            (0x01ul << CLK_PLLCON_PLL_SRC_Pos)
// Bits 20-31 are Reserved.


/**
  * @brief Clock Controller (CLK) - Register FRQDIV
  * 
  * @description Frequency Divider Control Register (FRQDIV) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.4.8 Register Description, page 125
  * 
  * FRQDIV = CLK_BA+0x24
  * 
  * 
  * FSEL [0:3]
  * Divider Output Frequency Select Bits
  * 
  * The formula of output frequency is:
  * 
  * Fout = Fin / 2 (N+1)
  * Fin is the input clock frequency.
  * Fout is the frequency of divider output clock.
  * N is the 4-bit value of FSEL[3:0].
  * 
  * 
  * DIVIDER_EN [4]
  * Frequency Divider Enable Bit
  * 
  * 0 = Frequency Divider Disabled.
  * 1 = Frequency Divider Enabled.
  * 
  */

#define CLK_FRQDIV_FSEL_Pos                               0
#define CLK_FRQDIV_FSEL_Msk                               (0x0Ful << CLK_FRQDIV_FSEL_Pos)
#define CLK_FRQDIV_DIVIDER_EN_Pos                         4
#define CLK_FRQDIV_DIVIDER_EN_Msk                         (0x01ul << CLK_FRQDIV_DIVIDER_EN_Pos)
// Bits 5-31 are Reserved.


/**
  * @brief Clock Controller (CLK) - Register APBDIV
  * 
  * @description APB Divider Control Register (APBDIV) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.4.8 Register Description, page 125
  * 
  * APBDIV = CLK_BA+0x24
  * 
  * 
  * APBDIV [0]
  * APB Divider Enable Bit
  * 
  * 0: PCLK = HCLK
  * 1: PCLK = HCLK / 2
  * 
  */

#define CLK_APBDIV_APBDIV_Pos                             0
#define CLK_APBDIV_APBDIV_Msk                             (0x01ul << CLK_APBDIV_APBDIV_Pos)
// Bits 1-31 are Reserved.



/* =========================================================================================================================== */
/* ================                                    System Manager Control                                 ================ */
/* =========================================================================================================================== */

/**
  * @brief System Manager Control (GCR)
  * 
  * @description See NUC123 Technical Reference Manual 5.3.4 System Manager Control Registers, page 57
  * 
  * GCR_BA = 0x5000_0000
  * 
  * Struct has large sections of reserved space (RESERVED<x>) for other NUC123 Family silicon
  * 
  */

typedef struct {

    __I  uint32_t PDID;          // GCR_BA+0x00                   Part Device Identification Number Register
    __IO uint32_t RSTSRC;        // GCR_BA+0x04                   System Reset Source Register
    __IO uint32_t IPRSTC1;       // GCR_BA+0x08                   Peripheral Reset Control Register 1
    __IO uint32_t IPRSTC2;       // GCR_BA+0x0C                   Peripheral Reset Control Register 2
    __I  uint32_t RESERVED0[2];
    __IO uint32_t BODCR;         // GCR_BA+0x18                   Brown-out Detector Control Register
    __I  uint32_t RESERVED1[2];
    __IO uint32_t PORCR;         // GCR_BA+0x24                   Power-on-Reset Controller Register
    __I  uint32_t RESERVED2[2];
    __IO uint32_t GPA_MFP;       // GCR_BA+0x30                   GPIOA Multiple Function and Input Type Control Register
    __IO uint32_t GPB_MFP;       // GCR_BA+0x34                   GPIOB Multiple Function and Input Type Control Register
    __IO uint32_t GPC_MFP;       // GCR_BA+0x38                   GPIOC Multiple Function and Input Type Control Register
    __IO uint32_t GPD_MFP;       // GCR_BA+0x3C                   GPIOD Multiple Function and Input Type Control Register
    __I  uint32_t RESERVED3;
    __IO uint32_t GPF_MFP;       // GCR_BA+0x44                   GPIOF Multiple Function and Input Type Control Register
    __I  uint32_t RESERVED4[2];
    __IO uint32_t ALT_MFP;       // GCR_BA+0x50                   Alternative Multiple Function Pin Control Register
    __IO uint32_t ALT_MFP1;      // GCR_BA+0x54                   Alternative Multiple Function Pin Control Register 1
    __I  uint32_t RESERVED5[26];
    __IO uint32_t GPA_IOCR;      // GCR_BA+0xC0                   GPIOA IO Control Register
    __IO uint32_t GPB_IOCR;      // GCR_BA+0xC4                   GPIOB IO Control Register
    __I  uint32_t RESERVED6;
    __IO uint32_t GPD_IOCR;      // GCR_BA+0xCC                   GPIOD IO Control Register
    __I  uint32_t RESERVED7[12];
    __IO uint32_t REGWRPROT;     // GCR_BA+0x100                  Register Write Protect Register

} GCR_T;


/**
  * @brief System Manager Controller (SYS) - Register PDID
  * 
  * @description Part Device ID Code Register (PDID) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 58
  * 
  * Part Device Identification Number
  * This register reflects the device part number code. S/W can read this register to identify
  * which device is used.
  * 
  * PART NUMBER   |  PACKAGE  |  FLASH  |  SRAM  |     PDID
  * ==============|===========|=========|========|=============
  * NUC123ZD4AN0  |  QFN-33   |   68    |   20   |  0x0001_2355
  * NUC123ZC2AN1  |  QFN-33   |   36    |   12   |  0x0001_2345
  * NUC123LD4AN0  |  LQFP-48  |   68    |   20   |  0x0001_2335
  * NUC123LC2AN1  |  LQFP-48  |   36    |   12   |  0x0001_2325
  * NUC123SD4AN0  |  LQFP-64  |   68    |   20   |  0x0001_2315
  * NUC123SC2AN1  |  LQFP-64  |   36    |   12   |  0x0001_2305
  * 
  */

#define SYS_PDID_PN_Pos                                   0
#define SYS_PDID_PN_Msk                                   (0xFFFFFFFFFFFFFFFFul << SYS_PDID_PN_Pos)


/**
  * @brief System Manager Controller (SYS) - Register RSTSRC
  * 
  * @description System Reset Source Register (RSTSRC) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 59-60
  * 
  * 
  * RSTS_POR [0]
  * The RSTS_POR flag is set by the "reset signal" from the Power-On Reset (POR)
  * controller or bit CHIP_RST (IPRSTC1[0]) to indicate the previous reset source.
  * 
  * 1 = Power-On Reset (POR) or CHIP_RST had issued the reset signal to reset the
  *     system.
  * 0 = No reset from POR or CHIP_RST
  * 
  * RSTS_RESET [1]
  * The RSTS_RESET flag is set by the "reset signal" from the /RESET pin to indicate the
  * previous reset source.
  * 
  * 1 = Pin /RESET had issued the reset signal to reset the system.
  * 0 = No reset from /RESET pin
  * 
  * RSTS_WDT [2]
  * The RSTS_WDT flag is set by the "reset signal" from the watchdog timer to indicate the
  * previous reset source.
  * 
  * 1 = Watchdog timer had issued the reset signal to reset the system.
  * 0 = No reset from watchdog timer
  * 
  * RSTS_LVR [3]
  * The RSTS_LVR flag is set by the "reset signal" from the Low-Voltage-Reset controller
  * to indicate the previous reset source.
  * 
  * 1 = LVR controller had issued the reset signal to reset the system.
  * 0 = No reset from LVR
  * 
  * RSTS_BOD [4]
  * The RSTS_BOD flag is set by the "reset signal" from the Brown-out-Detector to
  * indicate the previous reset source.
  * 
  * 1 = BOD had issued the reset signal to reset the system
  * 0 = No reset from BOD
  * 
  * RSTS_SYS [5]
  * The RSTS_SYS flag is set by the "reset signal" from the Cortex_M0 kernel to indicate
  * the previous reset source.
  * 
  * 1 = Cortex_M0 had issued the reset signal to reset the system by software writing 1 to
  *     bit SYSRESETREQ(AIRCR[2], Application Interrupt and Reset Control Register,
  *     address = 0xE000ED0C) in system control registers of Cortex_M0 kernel.
  * 0 = No reset from Cortex_M0
  * 
  * RSTS_CPU [7]
  * The RSTS_CPU flag is set by hardware if software writes CPU_RST (IPRSTC1[1]) 1 to
  * reset Cortex-M0 CPU kernel and Flash memory controller (FMC).
  * 
  * 1 = Cortex-M0 CPU kernel and FMC are reset by software setting CPU_RST to 1.
  * 0 = No reset from CPU
  * 
  * 
  * Software can write 1 to any bit to clear to zero.
  * 
  */

#define SYS_RSTSRC_RSTS_POR_Pos                           0
#define SYS_RSTSRC_RSTS_POR_Msk                           (0x01ul << SYS_RSTSRC_RSTS_POR_Pos)
#define SYS_RSTSRC_RSTS_RESET_Pos                         1
#define SYS_RSTSRC_RSTS_RESET_Msk                         (0x01ul << SYS_RSTSRC_RSTS_RESET_Pos)
#define SYS_RSTSRC_RSTS_WDT_Pos                           2
#define SYS_RSTSRC_RSTS_WDT_Msk                           (0x01ul << SYS_RSTSRC_RSTS_WDT_Pos)
#define SYS_RSTSRC_RSTS_LVR_Pos                           3
#define SYS_RSTSRC_RSTS_LVR_Msk                           (0x01ul << SYS_RSTSRC_RSTS_LVR_Pos)
#define SYS_RSTSRC_RSTS_BOD_Pos                           4
#define SYS_RSTSRC_RSTS_BOD_Msk                           (0x01ul << SYS_RSTSRC_RSTS_BOD_Pos)
#define SYS_RSTSRC_RSTS_SYS_Pos                           5
#define SYS_RSTSRC_RSTS_SYS_Msk                           (0x01ul << SYS_RSTSRC_RSTS_SYS_Pos)
// Bit 6 is Reserved.
#define SYS_RSTSRC_RSTS_CPU_Pos                           7
#define SYS_RSTSRC_RSTS_CPU_Msk                           (0x01ul << SYS_RSTSRC_RSTS_CPU_Pos)
// Bits 8-31 are Reserved.


/**
  * @brief System Manager Controller (SYS) - Register IPRSTC1
  * 
  * @description Peripheral Reset Control Register1 (IPRSTC1) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 61-62
  * 
  * 
  * These bits are protected bits, which means programming them requires writing to "59h", "16h",
  * and "88h" to address 0x5000_0100 to disable register protection.
  * 
  * Refer to the register REGWRPROT at address GCR_BA+0x100 (See below)
  * 
  * 
  * CHIP One-shot Reset (Write-protection Bit)
  * Setting this bit will reset the whole chip, including CPU kernel and all peripherals, and
  * this bit will automatically return to 0 after the 2 clock cycles.
  * 
  * The CHIP_RST is same as the POR reset, all the chip controllers is reset and the chip
  * setting from flash are also reload.
  * 
  * 1 = CHIP one-shot reset.
  * 0 = CHIP normal operation.
  * 
  * 
  * CPU kernel one-shot reset (Write-protection Bit)
  * Setting this bit will only reset the CPU kernel and Flash Memory Controller(FMC), and
  * this bit will automatically return to 0 after the 2 clock cycles
  * 
  * 1 = CPU one-shot reset.
  * 0 = CPU normal operation.
  * 
  * 
  * PDMA Controller Reset (Write-protection Bit)
  * Setting this bit to 1 will generate a reset signal to the PDMA. User need to set this bit to
  * 0 to release from reset state.
  * 
  * 1 = PDMA controller reset.
  * 0 = PDMA controller normal operation.
  *
  */

#define SYS_IPRSTC1_CHIP_RST_Pos                          0
#define SYS_IPRSTC1_CHIP_RST_Msk                          (0x01ul << SYS_IPRSTC1_CHIP_RST_Pos)
#define SYS_IPRSTC1_CPU_RST_Pos                           1
#define SYS_IPRSTC1_CPU_RST_Msk                           (0x01ul << SYS_IPRSTC1_CPU_RST_Pos)
#define SYS_IPRSTC1_PDMA_RST_Pos                          2
#define SYS_IPRSTC1_PDMA_RST_Msk                          (0x01ul << SYS_IPRSTC1_PDMA_RST_Pos)
// Bits 3-31 are Reserved.


/**
  * @brief System Manager Controller (SYS) - Register IPRSTC2
  * 
  * @description Peripheral Reset Control Register2 (IPRSTC2) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 63-65
  * 
  * 
  * GPIO controller Reset
  * 1 = GPIO controller reset
  * 0 = GPIO controller normal operation
  * 
  * Timer0 controller Reset
  * 1 = Timer0 controller reset
  * 0 = Timer0 controller normal operation
  * 
  * Timer1 controller Reset
  * 1 = Timer1 controller reset
  * 0 = Timer1 controller normal operation
  * 
  * Timer2 controller Reset
  * 1 = Timer2 controller reset
  * 0 = Timer2 controller normal operation
  * 
  * Timer3 controller Reset
  * 1 = Timer3 controller reset
  * 0 = Timer3 controller normal operation
  * 
  * I2C0 controller Reset
  * 1 = I2C0 controller reset
  * 0 = I2C0 controller normal operation
  * 
  * I2C1 controller Reset
  * 1 = I2C1 controller reset
  * 0 = I2C1 controller normal operation
  * 
  * SPI0 controller Reset
  * 1 = SPI0 controller reset
  * 0 = SPI0 controller normal operation
  * 
  * SPI1 controller Reset
  * 1 = SPI1 controller reset
  * 0 = SPI1 controller normal operation
  * 
  * SPI2 controller Reset
  * 1 = SPI2 controller reset
  * 0 = SPI2 controller normal operation
  * 
  * UART0 controller Reset
  * 1 = UART0 controller reset
  * 0 = UART0 controller normal operation
  * 
  * UART1 controller Reset
  * 1 = UART1 controller reset
  * 0 = UART1 controller normal operation
  * 
  * USB Device controller Reset
  * 1 = USB Device controller reset
  * 0 = USB Device controller normal operation
  * 
  * ADC controller Reset
  * 1 = ADC controller reset
  * 0 = ADC controller normal operation
  * 
  * I2S controller Reset
  * 1 = I2S controller reset
  * 0 = I2S controller normal operation
  * 
  */

// Bit 0 is Reserved.
#define SYS_IPRSTC2_GPIO_RST_Pos                          1
#define SYS_IPRSTC2_GPIO_RST_Msk                          (0x01ul << SYS_IPRSTC2_GPIO_RST_Pos)
#define SYS_IPRSTC2_TMR0_RST_Pos                          2
#define SYS_IPRSTC2_TMR0_RST_Msk                          (0x01ul << SYS_IPRSTC2_TMR0_RST_Pos)
#define SYS_IPRSTC2_TMR1_RST_Pos                          3
#define SYS_IPRSTC2_TMR1_RST_Msk                          (0x01ul << SYS_IPRSTC2_TMR1_RST_Pos)
#define SYS_IPRSTC2_TMR2_RST_Pos                          4
#define SYS_IPRSTC2_TMR2_RST_Msk                          (0x01ul << SYS_IPRSTC2_TMR2_RST_Pos)
#define SYS_IPRSTC2_TMR3_RST_Pos                          5
#define SYS_IPRSTC2_TMR3_RST_Msk                          (0x01ul << SYS_IPRSTC2_TMR3_RST_Pos)
// Bits 6-7 are Reserved.
#define SYS_IPRSTC2_I2C0_RST_Pos                          8
#define SYS_IPRSTC2_I2C0_RST_Msk                          (0x01ul << SYS_IPRSTC2_I2C0_RST_Pos)
#define SYS_IPRSTC2_I2C1_RST_Pos                          9
#define SYS_IPRSTC2_I2C1_RST_Msk                          (0x01ul << SYS_IPRSTC2_I2C1_RST_Pos)
// Bits 10-11 are Reserved.
#define SYS_IPRSTC2_SPI0_RST_Pos                          12
#define SYS_IPRSTC2_SPI0_RST_Msk                          (0x01ul << SYS_IPRSTC2_SPI0_RST_Pos)
#define SYS_IPRSTC2_SPI1_RST_Pos                          13
#define SYS_IPRSTC2_SPI1_RST_Msk                          (0x01ul << SYS_IPRSTC2_SPI1_RST_Pos)
#define SYS_IPRSTC2_SPI2_RST_Pos                          14
#define SYS_IPRSTC2_SPI2_RST_Msk                          (0x01ul << SYS_IPRSTC2_SPI2_RST_Pos)
// Bit 15 is Reserved.
#define SYS_IPRSTC2_UART0_RST_Pos                         16
#define SYS_IPRSTC2_UART0_RST_Msk                         (0x01ul << SYS_IPRSTC2_UART0_RST_Pos)
#define SYS_IPRSTC2_UART1_RST_Pos                         17
#define SYS_IPRSTC2_UART1_RST_Msk                         (0x01ul << SYS_IPRSTC2_UART1_RST_Pos)
// Bits 18-19 are Reserved.
#define SYS_IPRSTC2_PWM03_RST_Pos                         20
#define SYS_IPRSTC2_PWM03_RST_Msk                         (0x01ul << SYS_IPRSTC2_PWM03_RST_Pos)
// Bits 21-22 are Reserved.
#define SYS_IPRSTC2_PS2_RST_Pos                           23
#define SYS_IPRSTC2_PS2_RST_Msk                           (0x01ul << SYS_IPRSTC2_PS2_RST_Pos)
// Bits 24-26 are Reserved.
#define SYS_IPRSTC2_USBD_RST_Pos                          27
#define SYS_IPRSTC2_USBD_RST_Msk                          (0x01ul << SYS_IPRSTC2_USBD_RST_Pos)
#define SYS_IPRSTC2_ADC_RST_Pos                           28
#define SYS_IPRSTC2_ADC_RST_Msk                           (0x01ul << SYS_IPRSTC2_ADC_RST_Pos)
#define SYS_IPRSTC2_I2S_RST_Pos                           29
#define SYS_IPRSTC2_I2S_RST_Msk                           (0x01ul << SYS_IPRSTC2_I2S_RST_Pos)
// Bits 30-31 are Reserved.


/**
  * @brief System Manager Controller (SYS) - Register BODCR
  * 
  * @description Peripheral Brown-out Detector Control Register (BODCR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 66-68
  * 
  * Part of the BODCR control registers bits are initiated by the flash configuration and part of the
  * bits are write-protected. Programming write-protected bits needs to write "59h", "16h", "88h" to
  * address 0x5000_0100 to disable register protection.
  * Refer to the register REGWRPROT at address GCR_BA+0x100.
  * 
  * BODCR = GCR_BA+0x18
  * 
  * 
  * BOD_EN [0]
  * Brown-out Detector Enable (Write-protection Bit)
  * 
  * The default value is set by flash controller user configuration register config0 bit[23].
  * 
  * 1 = Brown-out Detector function Enabled.
  * 0 = Brown-out Detector function Disabled.
  * 
  * This bit is a protected bit.
  * 
  * 
  * BOD_VL [1:2]
  * Brown-out Detector Threshold Voltage Selection (Write-protection Bits)
  * 
  * The default value is set by flash controller user configuration register config0 bit[22:21]
  * 
  * BOV_VL[1]  | BOV_VL[0]  |  Brown-out Voltage
  * ===========|============|=====================
  *     1      |     1      |      4.5 V
  *     1      |     0      |      3.8 V
  *     0      |     1      |      2.7 V
  *     0      |     0      |      2.2 V
  * 
  * 
  * BOD_RSTEN [3]
  * Brown-out Reset Enable (Write-protection Bit)
  * 
  * 1 = Brown-out "RESET" function Enabled.
  *     While the Brown-out Detector function is enabled (BOD_EN high) and BOD reset
  *     function is enabled (BOD_RSTEN high), BOD will assert a signal to reset chip when
  *     the detected voltage is lower than the threshold (BOD_OUT high).
  * 0 = Brown-out "INTERRUPT" function Enabled.
  *     While the BOD function is enabled (BOD_EN high) and BOD interrupt function is
  *     enabled (BOD_RSTEN low), BOD will assert an interrupt if BOD_OUT is high. BOD
  *     interrupt will keep till to the BOD_EN set to 0. BOD interrupt can be blocked by
  *     disabling the NVIC BOD interrupt or disabling BOD function (set BOD_EN low).
  * 
  * The default value is set by flash controller user configuration register config0 bit[20].
  * 
  * 
  * BOD_INTF [4]
  * Brown-out Detector Interrupt Flag
  * 
  * 1 = When Brown-out Detector detects the VDD is dropped down through the voltage of
  *     BOD_VL setting or the VDD is raised up through the voltage of BOD_VL setting, this
  *     bit is set to 1 and the Brown-out interrupt is requested if Brown-out interrupt is enabled.
  * 0 = Brown-out Detector does not detect any voltage draft at VDD down through or up
  *     through the voltage of BOD_VL setting.
  * 
  * Software can write 1 to clear this bit to zero.
  * 
  * 
  * BOD_LPM [5]
  * Brown-out Detector Low power Mode (Write-protection Bit)
  * 
  * 1 = BOD low power mode Enabled.
  * 0 = BOD operated in Normal mode (Default).
  * 
  * The BOD consumes about 100 uA in Normal mode, the low power mode can reduce
  * the current to about 1/10 but will slow the BOD response.
  * 
  * 
  * BOD_OUT [6]
  * Brown-out Detector Output Status
  * 
  * 1 = Brown-out Detector output status is 1, which means the detected voltage is lower
  *     than BOD_VL setting. If the BOD_EN is 0, BOD function disabled , this bit always
  *     responds to 0
  * 0 = Brown-out Detector output status is 0, which means the detected voltage is higher
  *     than BOD_VL setting or BOD_EN is 0.
  * 
  * 
  * LVR_EN [7]
  * Low Voltage Reset Enable (Write-protection Bit)
  * 
  * The LVR function reset the chip when the input power voltage is lower than LVR circuit
  * setting. LVR function is enabled by default.
  * 
  * 1 = Low Voltage Reset function Enabled– After enabling the bit, the LVR function will
  *     be active with 100uS delay for LVR output stable (Default).
  * 0 = Low Voltage Reset function Disabled.
  * 
  * 
  */

#define SYS_BODCR_BOD_EN_Pos                              0
#define SYS_BODCR_BOD_EN_Msk                              (0x01ul << SYS_BODCR_BOD_EN_Pos)
#define SYS_BODCR_BOD_VL_Pos                              1
#define SYS_BODCR_BOD_VL_Msk                              (0x03ul << SYS_BODCR_BOD_VL_Pos)
#define SYS_BODCR_BOD_RSTEN_Pos                           3
#define SYS_BODCR_BOD_RSTEN_Msk                           (0x01ul << SYS_BODCR_BOD_RSTEN_Pos)
#define SYS_BODCR_BOD_INTF_Pos                            4
#define SYS_BODCR_BOD_INTF_Msk                            (0x01ul << SYS_BODCR_BOD_INTF_Pos)
#define SYS_BODCR_BOD_LPM_Pos                             5
#define SYS_BODCR_BOD_LPM_Msk                             (0x01ul << SYS_BODCR_BOD_LPM_Pos)
#define SYS_BODCR_BOD_OUT_Pos                             6
#define SYS_BODCR_BOD_OUT_Msk                             (0x01ul << SYS_BODCR_BOD_OUT_Pos)
#define SYS_BODCR_LVR_EN_Pos                              7
#define SYS_BODCR_LVR_EN_Msk                              (0x01ul << SYS_BODCR_LVR_EN_Pos)
// Bits 8-31 are Reserved.


/**
  * @brief System Manager Controller (SYS) - Register PORCR
  * 
  * @description Peripheral Power-On-Reset Control Register (PORCR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 69
  * 
  * PORCR = GCR_BA+0x24
  * 
  * POR_DIS_CODE [0:15]
  * This register is used for the Power-On-Reset enable control (Write-protection Bits)
  * 
  * When powered on, the POR circuit generates a reset signal to reset the whole chip
  * function, but noise on the power may cause the POR active again. User can disable
  * internal POR circuit to avoid unpredictable noise to cause chip reset by writing 0x5AA5
  * to this field.
  * 
  * The POR function will become active again when this field is set to another value or
  * chip is reset by other reset source, including:
  * /RESET, Watchdog, LVR reset, BOD reset, ICE reset command and the software-chip
  * reset function
  * 
  * This bit is a protected bit, which means programming it needs to write "59h", "16h",
  * "88h" to address 0x5000_0100 to disable register protection.
  * 
  * Refer to the register REGWRPROT at address GCR_BA+0x100.
  * 
  */

#define SYS_PORCR_POR_DIS_CODE_Pos                        0
#define SYS_PORCR_POR_DIS_CODE_Msk                        (0xFFFFul << SYS_PORCR_POR_DIS_CODE_Pos)
// Bits 16-31 are Reserved.


/**
  * @brief System Manager Controller (SYS) - Register GPA_MFP
  * 
  * @description Peripheral Multi Function Pin GPIOA Control Register (GPA_MFP) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 70-71
  * 
  * GPA_MFP GCR_BA+0x30
  * 
  */

#define SYS_GPA_MFP_GPA_MFP_Pos                           0
#define SYS_GPA_MFP_GPA_MFP_Msk                           (0xFFFFul << SYS_GPA_MFP_GPA_MFP_Pos)
#define SYS_GPA_MFP_GPA_TYPE_Pos                          16
#define SYS_GPA_MFP_GPA_TYPE_Msk                          (0xFFFFul << SYS_GPA_MFP_GPA_TYPE_Pos)

// Available Alternate Function Pins
#define GPA_MFP10                                         10
#define GPA_MFP11                                         11
#define GPA_MFP12                                         12
#define GPA_MFP13                                         13
#define GPA_MFP14                                         14
#define GPA_MFP15                                         15


/**
  * @brief System Manager Controller (SYS) - Register GPB_MFP
  * 
  * @description Peripheral Multi Function Pin GPIOB Control Register (GPB_MFP) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 72-75
  * 
  * GPB_MFP GCR_BA+0x34
  * 
  */

#define SYS_GPB_MFP_GPB_MFP_Pos                           0
#define SYS_GPB_MFP_GPB_MFP_Msk                           (0xFFFFul << SYS_GPB_MFP_GPB_MFP_Pos)
#define SYS_GPB_MFP_GPB_TYPE_Pos                          16
#define SYS_GPB_MFP_GPB_TYPE_Msk                          (0xFFFFul << SYS_GPB_MFP_GPB_TYPE_Pos)

// Available Alternate Function Pins
#define GPB_MFP0                                          0
#define GPB_MFP1                                          1
#define GPB_MFP2                                          2
#define GPB_MFP3                                          3
#define GPB_MFP4                                          4
#define GPB_MFP5                                          5
#define GPB_MFP6                                          6
#define GPB_MFP7                                          7
#define GPB_MFP8                                          8
#define GPB_MFP9                                          9
#define GPB_MFP10                                         10
#define GPB_MFP12                                         12
#define GPB_MFP13                                         13
#define GPB_MFP14                                         14
#define GPB_MFP15                                         15


/**
  * @brief System Manager Controller (SYS) - Register GPC_MFP
  * 
  * @description Peripheral Multi Function Pin GPIOC Control Register (GPC_MFP) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 76-78
  * 
  * GPC_MFP GCR_BA+0x38
  * 
  */

#define SYS_GPC_MFP_GPC_MFP_Pos                           0
#define SYS_GPC_MFP_GPC_MFP_Msk                           (0xFFFFul << SYS_GPC_MFP_GPC_MFP_Pos)
#define SYS_GPC_MFP_GPC_TYPE_Pos                          16
#define SYS_GPC_MFP_GPC_TYPE_Msk                          (0xFFFFul << SYS_GPC_MFP_GPC_TYPE_Pos)

// Available Alternate Function Pins
#define GPC_MFP0                                          0
#define GPC_MFP1                                          1
#define GPC_MFP2                                          2
#define GPC_MFP3                                          3
#define GPC_MFP4                                          4
#define GPC_MFP5                                          5
#define GPC_MFP8                                          8
#define GPC_MFP9                                          9
#define GPC_MFP10                                         10
#define GPC_MFP11                                         11
#define GPC_MFP12                                         12
#define GPC_MFP13                                         13


/**
  * @brief System Manager Controller (SYS) - Register GPD_MFP
  * 
  * @description Peripheral Multi Function Pin GPIOD Control Register (GPD_MFP) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 79-81
  * 
  * GPD_MFP GCR_BA+0x3C
  * 
  */

#define SYS_GPD_MFP_GPD_MFP_Pos                           0
#define SYS_GPD_MFP_GPD_MFP_Msk                           (0xFFFFul << SYS_GPD_MFP_GPD_MFP_Pos)
#define SYS_GPD_MFP_GPD_TYPE_Pos                          16
#define SYS_GPD_MFP_GPD_TYPE_Msk                          (0xFFFFul << SYS_GPD_MFP_GPD_TYPE_Pos)

// Available Alternate Function Pins
#define GPD_MFP0                                          0
#define GPD_MFP1                                          1
#define GPD_MFP2                                          2
#define GPD_MFP3                                          3
#define GPD_MFP4                                          4
#define GPD_MFP5                                          5
#define GPD_MFP8                                          8
#define GPD_MFP9                                          9
#define GPD_MFP10                                         10
#define GPD_MFP11                                         11


/**
  * @brief System Manager Controller (SYS) - Register GPF_MFP
  * 
  * @description Peripheral Multi Function Pin GPIOF Control Register (GPF_MFP) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 82-83
  * 
  * GPF_MFP GCR_BA+0x44
  * 
  */

#define SYS_GPF_MFP_GPF_MFP0_Pos                          0
#define SYS_GPF_MFP_GPF_MFP0_Msk                          (0x01ul << SYS_GPF_MFP_GPF_MFP0_Pos)
#define SYS_GPF_MFP_GPF_MFP1_Pos                          1
#define SYS_GPF_MFP_GPF_MFP1_Msk                          (0x01ul << SYS_GPF_MFP_GPF_MFP1_Pos)
#define SYS_GPF_MFP_GPF_MFP2_Pos                          2
#define SYS_GPF_MFP_GPF_MFP2_Msk                          (0x01ul << SYS_GPF_MFP_GPF_MFP2_Pos)
#define SYS_GPF_MFP_GPF_MFP3_Pos                          3
#define SYS_GPF_MFP_GPF_MFP3_Msk                          (0x01ul << SYS_GPF_MFP_GPF_MFP3_Pos)
// Bits 4 to 15 are Reserved.
#define SYS_GPF_MFP_GPF_TYPE_Pos                          16
#define SYS_GPF_MFP_GPF_TYPE_Msk                          (0xFul << SYS_GPF_MFP_GPF_TYPE_Pos)
// Bits 20 to 31 are Reserved.

// Available Alternate Function Pins
#define GPF_MFP0                                          0
#define GPF_MFP1                                          1
#define GPF_MFP2                                          2
#define GPF_MFP3                                          3


/**
  * @brief System Manager Controller (SYS) - Register ALT_MFP
  * 
  * @description Peripheral Alternate Multi Function Pin Control Register (ALT_MFP) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 84-89
  * 
  * ALT_MFP GCR_BA+0x50
  * 
  */

#define SYS_ALT_MFP_PB10_MFP1_Pos                         0
#define SYS_ALT_MFP_PB10_MFP1_Msk                         (0x01ul << SYS_ALT_MFP_PB10_MFP1_Pos)
#define SYS_ALT_MFP_PB9_MFP1_Pos                          1
#define SYS_ALT_MFP_PB9_MFP1_Msk                          (0x01ul << SYS_ALT_MFP_PB9_MFP1_Pos)
// Bits 2-4 are Reserved.
#define SYS_ALT_MFP_PC0_MFP1_Pos                          5
#define SYS_ALT_MFP_PC0_MFP1_Msk                          (0x01ul << SYS_ALT_MFP_PC0_MFP1_Pos)
#define SYS_ALT_MFP_PC1_MFP1_Pos                          6
#define SYS_ALT_MFP_PC1_MFP1_Msk                          (0x01ul << SYS_ALT_MFP_PC1_MFP1_Pos)
#define SYS_ALT_MFP_PC2_MFP1_Pos                          7
#define SYS_ALT_MFP_PC2_MFP1_Msk                          (0x01ul << SYS_ALT_MFP_PC2_MFP1_Pos)
#define SYS_ALT_MFP_PC3_MFP1_Pos                          8
#define SYS_ALT_MFP_PC3_MFP1_Msk                          (0x01ul << SYS_ALT_MFP_PC3_MFP1_Pos)
#define SYS_ALT_MFP_PA15_MFP1_Pos                         9
#define SYS_ALT_MFP_PA15_MFP1_Msk                         (0x01ul << SYS_ALT_MFP_PA15_MFP1_Pos)
#define SYS_ALT_MFP_PB12_MFP1_Pos                         10
#define SYS_ALT_MFP_PB12_MFP1_Msk                         (0x01ul << SYS_ALT_MFP_PB12_MFP1_Pos)
#define SYS_ALT_MFP_PA11_MFP1_Pos                         11
#define SYS_ALT_MFP_PA11_MFP1_Msk                         (0x01ul << SYS_ALT_MFP_PA11_MFP1_Pos)
#define SYS_ALT_MFP_PA10_MFP1_Pos                         12
#define SYS_ALT_MFP_PA10_MFP1_Msk                         (0x01ul << SYS_ALT_MFP_PA10_MFP1_Pos)
// Bits 13-14 are Reserved.
#define SYS_ALT_MFP_PB4_MFP1_Pos                          15
#define SYS_ALT_MFP_PB4_MFP1_Msk                          (0x01ul << SYS_ALT_MFP_PB4_MFP1_Pos)
#define SYS_ALT_MFP_PB7_MFP1_Pos                          16
#define SYS_ALT_MFP_PB7_MFP1_Msk                          (0x01ul << SYS_ALT_MFP_PB7_MFP1_Pos)
#define SYS_ALT_MFP_PB6_MFP1_Pos                          17
#define SYS_ALT_MFP_PB6_MFP1_Msk                          (0x01ul << SYS_ALT_MFP_PB6_MFP1_Pos)
#define SYS_ALT_MFP_PB5_MFP1_Pos                          18
#define SYS_ALT_MFP_PB5_MFP1_Msk                          (0x01ul << SYS_ALT_MFP_PB5_MFP1_Pos)
// Bit 19 is Reserved.
#define SYS_ALT_MFP_PC12_MFP1_Pos                         20
#define SYS_ALT_MFP_PC12_MFP1_Msk                         (0x01ul << SYS_ALT_MFP_PC12_MFP1_Pos)
#define SYS_ALT_MFP_PC13_MFP1_Pos                         21
#define SYS_ALT_MFP_PC13_MFP1_Msk                         (0x01ul << SYS_ALT_MFP_PC13_MFP1_Pos)
// Bits 22-23 are Reserved.
#define SYS_ALT_MFP_PB15_MFP1_Pos                         24
#define SYS_ALT_MFP_PB15_MFP1_Msk                         (0x01ul << SYS_ALT_MFP_PB15_MFP1_Pos)
// Bit 25 is Reserved.
#define SYS_ALT_MFP_PB2_MFP1_Pos                          26
#define SYS_ALT_MFP_PB2_MFP1_Msk                          (0x01ul << SYS_ALT_MFP_PB2_MFP1_Pos)
#define SYS_ALT_MFP_PB3_MFP1_Pos                          27
#define SYS_ALT_MFP_PB3_MFP1_Msk                          (0x01ul << SYS_ALT_MFP_PB3_MFP1_Pos)
// Bit 28 is Reserved.
#define SYS_ALT_MFP_PC4_MFP1_Pos                          29
#define SYS_ALT_MFP_PC4_MFP1_Msk                          (0x01ul << SYS_ALT_MFP_PC4_MFP1_Pos)
#define SYS_ALT_MFP_PC5_MFP1_Pos                          30
#define SYS_ALT_MFP_PC5_MFP1_Msk                          (0x01ul << SYS_ALT_MFP_PC5_MFP1_Pos)
// Bit 31 is Reserved.


/**
  * @brief System Manager Controller (SYS) - Register ALT_MFP1
  * 
  * @description Peripheral Alternate Multi Function Pin Control Register1 (ALT_MFP) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 90-92
  * 
  * ALT_MFP1 GCR_BA+0x54
  * 
  */

// Bits 0-15 are Reserved.
#define SYS_ALT_MFP1_PD0_MFP1_Pos                         16
#define SYS_ALT_MFP1_PD0_MFP1_Msk                         (0x01ul << SYS_ALT_MFP1_PD0_MFP1_Pos)
#define SYS_ALT_MFP1_PD1_MFP1_Pos                         17
#define SYS_ALT_MFP1_PD1_MFP1_Msk                         (0x01ul << SYS_ALT_MFP1_PD1_MFP1_Pos)
#define SYS_ALT_MFP1_PD2_MFP1_Pos                         18
#define SYS_ALT_MFP1_PD2_MFP1_Msk                         (0x01ul << SYS_ALT_MFP1_PD2_MFP1_Pos)
#define SYS_ALT_MFP1_PD3_MFP1_Pos                         19
#define SYS_ALT_MFP1_PD3_MFP1_Msk                         (0x01ul << SYS_ALT_MFP1_PD3_MFP1_Pos)
#define SYS_ALT_MFP1_PD4_MFP1_Pos                         20
#define SYS_ALT_MFP1_PD4_MFP1_Msk                         (0x01ul << SYS_ALT_MFP1_PD4_MFP1_Pos)
#define SYS_ALT_MFP1_PD5_MFP1_Pos                         21
#define SYS_ALT_MFP1_PD5_MFP1_Msk                         (0x01ul << SYS_ALT_MFP1_PD5_MFP1_Pos)
// Bit 22 is Reserved.
#define SYS_ALT_MFP1_PC8_MFP1_Pos                         23
#define SYS_ALT_MFP1_PC8_MFP1_Msk                         (0x01ul << SYS_ALT_MFP1_PC8_MFP1_Pos)
#define SYS_ALT_MFP1_PF2_MFP1_Pos                         24
#define SYS_ALT_MFP1_PF2_MFP1_Msk                         (0x03ul << SYS_ALT_MFP1_PF2_MFP1_Pos)
// Bit 25 is Reserved.
#define SYS_ALT_MFP1_PF3_MFP1_Pos                         26
#define SYS_ALT_MFP1_PF3_MFP1_Msk                         (0x03ul << SYS_ALT_MFP1_PF3_MFP1_Pos)
// Bits 27-31 are Reserved.


/**
  * @brief System Manager Controller (SYS) - Register DFP_CSR
  * 
  * @description Peripheral Dynamic Function Pin Conflict Status Register (DFP_CSR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 93-94
  * 
  * DFP_CSR GCR_BA+0xA0
  * 
  * 
  * DFP0_CST [0]
  * Conflict Status of PD.9
  * 
  * 1 = PD.9 is conflicted.
  * 0 = PD.9 worked normally.
  * 
  * DFP1_CST [1]
  * Conflict Status of PD.10
  * 
  * 1 = PD.10 is conflicted.
  * 0 = PD.10 worked normally.
  * 
  * DFP2_CST [2]
  * Conflict Status of PD.11
  * 
  * 1 = PD.11 is conflicted.
  * 0 = PD.11 worked normally.
  * 
  * DFP3_CST [3]
  * Conflict Status of PB.4
  * 
  * 1 = PB.4 is conflicted.
  * 0 = PB.4 worked normally.
  * 
  * DFP4_CST [4]
  * Conflict Status of PB.5
  * 
  * 1 = PB.5 is conflicted.
  * 0 = PB.5 worked normally.
  * 
  * DFP5_CST [5]
  * Conflict Status of PB.6
  * 
  * 1 = PB.6 is conflicted.
  * 0 = PB.6 worked normally.
  * 
  * DFP6_CST [6]
  * Conflict Status of PB.7
  * 
  * 1 = PB.7 is conflicted.
  * 0 = PB.7 worked normally.
  * 
  */

#define SYS_DFP_CSR_DFP0_CST_Pos                          0
#define SYS_DFP_CSR_DFP0_CST_Msk                          (0x01ul << SYS_DFP_CSR_DFP0_CST_Pos)
#define SYS_DFP_CSR_DFP1_CST_Pos                          1
#define SYS_DFP_CSR_DFP1_CST_Msk                          (0x01ul << SYS_DFP_CSR_DFP1_CST_Pos)
#define SYS_DFP_CSR_DFP2_CST_Pos                          2
#define SYS_DFP_CSR_DFP2_CST_Msk                          (0x01ul << SYS_DFP_CSR_DFP2_CST_Pos)
#define SYS_DFP_CSR_DFP3_CST_Pos                          3
#define SYS_DFP_CSR_DFP3_CST_Msk                          (0x01ul << SYS_DFP_CSR_DFP3_CST_Pos)
#define SYS_DFP_CSR_DFP4_CST_Pos                          4
#define SYS_DFP_CSR_DFP4_CST_Msk                          (0x01ul << SYS_DFP_CSR_DFP4_CST_Pos)
#define SYS_DFP_CSR_DFP5_CST_Pos                          5
#define SYS_DFP_CSR_DFP5_CST_Msk                          (0x01ul << SYS_DFP_CSR_DFP5_CST_Pos)
#define SYS_DFP_CSR_DFP6_CST_Pos                          6
#define SYS_DFP_CSR_DFP6_CST_Msk                          (0x01ul << SYS_DFP_CSR_DFP6_CST_Pos)
// Bits 7-31 are Reserved.


/**
  * @brief System Manager Controller (SYS) - Register GPA_IOCR
  * 
  * @description Peripheral GPIOA IO Control Register (GPA_IOCR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 95
  * 
  * GPA_IOCR GCR_BA+0xC0
  * 
  * 
  * GPA10_DS [10]
  * PA.10 Pin Driving Strength Selection
  * 
  * 1 = PA.10 strong driving strength mode Enabled.
  * 0 = PA.10 strong driving strength mode Disabled.
  * 
  * GPA11_DS [11]
  * PA.11 Pin Driving Strength Selection
  * 
  * 1 = PA.11 strong driving strength mode Enabled.
  * 0 = PA.11 strong driving strength mode Disabled.
  * 
  */

// Bits 0-9 are Reserved.
#define SYS_GPA_IOCR_GPA10_DS_Pos                         10
#define SYS_GPA_IOCR_GPA10_DS_Msk                         (0x01ul << SYS_GPA_IOCR_GPA10_DS_Pos)
#define SYS_GPA_IOCR_GPA11_DS_Pos                         11
#define SYS_GPA_IOCR_GPA11_DS_Msk                         (0x01ul << SYS_GPA_IOCR_GPA11_DS_Pos)
// Bits 12-31 are Reserved.


/**
  * @brief System Manager Controller (SYS) - Register GPB_IOCR
  * 
  * @description Peripheral GPIOB IO Control Register (GPB_IOCR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 96-97
  * 
  * GPB_IOCR GCR_BA+0xC4
  * 
  * 
  * GPB4_DS [4]
  * PB.4 Pin Driving Strength Selection
  * 
  * 1 = PB.4 strong driving strength mode Enabled.
  * 0 = PB.4 strong driving strength mode Disabled.
  * 
  * GPB5_DS [5]
  * PB.5 Pin Driving Strength Selection
  * 
  * 1 = PB.5 strong driving strength mode Enabled.
  * 0 = PB.5 strong driving strength mode Disabled.
  * 
  * GPB6_DS [6]
  * PB.6 Pin Driving Strength Selection
  * 
  * 1 = PB.6 strong driving strength mode Enabled.
  * 0 = PB.6 strong driving strength mode Disabled.
  * 
  * GPB7_DS [7]
  * PB.7 Pin Driving Strength Selection
  * 
  * 1 = PB.7 strong driving strength mode Enabled.
  * 0 = PB.7 strong driving strength mode Disabled.
  * 
  * GPB8_DS [8]
  * PB.8 Pin Driving Strength Selection
  * 
  * 1 = PB.8 strong driving strength mode Enabled.
  * 0 = PB.8 strong driving strength mode Disabled.
  * 
  * GPB12_DS [12]
  * PB.12 Pin Driving Strength Selection
  * 
  * 1 = PB.12 strong driving strength mode Enabled.
  * 0 = PB.12 strong driving strength mode Disabled.
  * 
  * GPB13_DS [13]
  * PB.13 Pin Driving Strength Selection
  * 
  * 1 = PB.13 strong driving strength mode Enabled.
  * 0 = PB.13 strong driving strength mode Disabled.
  * 
  * GPB14_DS [14]
  * PB.14 Pin Driving Strength Selection
  * 
  * 1 = PB.14 strong driving strength mode Enabled.
  * 0 = PB.14 strong driving strength mode Disabled.
  * 
  */

// Bits 0-3 are Reserved.
#define SYS_GPB_IOCR_GPB4_DS_Pos                          4
#define SYS_GPB_IOCR_GPB4_DS_Msk                          (0x01ul << SYS_GPB_IOCR_GPB4_DS_Pos)
#define SYS_GPB_IOCR_GPB5_DS_Pos                          5
#define SYS_GPB_IOCR_GPB5_DS_Msk                          (0x01ul << SYS_GPB_IOCR_GPB5_DS_Pos)
#define SYS_GPB_IOCR_GPB6_DS_Pos                          6
#define SYS_GPB_IOCR_GPB6_DS_Msk                          (0x01ul << SYS_GPB_IOCR_GPB6_DS_Pos)
#define SYS_GPB_IOCR_GPB7_DS_Pos                          7
#define SYS_GPB_IOCR_GPB7_DS_Msk                          (0x01ul << SYS_GPB_IOCR_GPB7_DS_Pos)
#define SYS_GPB_IOCR_GPB8_DS_Pos                          8
#define SYS_GPB_IOCR_GPB8_DS_Msk                          (0x01ul << SYS_GPB_IOCR_GPB8_DS_Pos)
// Bits 9-11 are Reserved.
#define SYS_GPB_IOCR_GPB12_DS_Pos                         12
#define SYS_GPB_IOCR_GPB12_DS_Msk                         (0x01ul << SYS_GPB_IOCR_GPB12_DS_Pos)
#define SYS_GPB_IOCR_GPB13_DS_Pos                         13
#define SYS_GPB_IOCR_GPB13_DS_Msk                         (0x01ul << SYS_GPB_IOCR_GPB13_DS_Pos)
#define SYS_GPB_IOCR_GPB14_DS_Pos                         14
#define SYS_GPB_IOCR_GPB14_DS_Msk                         (0x01ul << SYS_GPB_IOCR_GPB14_DS_Pos)
// Bits 15-31 are Reserved.


/**
  * @brief System Manager Controller (SYS) - Register GPD_IOCR
  * 
  * @description Peripheral GPIOD IO Control Register (GPD_IOCR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 98
  * 
  * GPD_IOCR GCR_BA+0xCC
  * 
  * 
  * GPD8_DS [8]
  * PD.8 Pin Driving Strength Selection
  * 
  * 1 = PD.8 strong driving strength mode Enabled.
  * 0 = PD.8 strong driving strength mode Disabled.
  * 
  * GPD9_DS [9]
  * PD.9 Pin Driving Strength Selection
  * 
  * 1 = PD.9 strong driving strength mode Enabled.
  * 0 = PD.9 strong driving strength mode Disabled.
  * 
  * GPD10_DS [10]
  * PD.10 Pin Driving Strength Selection
  * 
  * 1 = PD.10 strong driving strength mode Enabled.
  * 0 = PD.10 strong driving strength mode Disabled.
  * 
  * GPD11_DS [11]
  * PD.11 Pin Driving Strength Selection
  * 
  * 1 = PD.11 strong driving strength mode Enabled.
  * 0 = PD.11 strong driving strength mode Disabled.
  * 
  */

// Bits 0-7 are Reserved.
#define SYS_GPD_IOCR_GPD8_DS_Pos                          8
#define SYS_GPD_IOCR_GPD8_DS_Msk                          (0x01ul << SYS_GPD_IOCR_GPD8_DS_Pos)
#define SYS_GPD_IOCR_GPD9_DS_Pos                          9
#define SYS_GPD_IOCR_GPD9_DS_Msk                          (0x01ul << SYS_GPD_IOCR_GPD9_DS_Pos)
#define SYS_GPD_IOCR_GPD10_DS_Pos                         10
#define SYS_GPD_IOCR_GPD10_DS_Msk                         (0x01ul << SYS_GPD_IOCR_GPD10_DS_Pos)
#define SYS_GPD_IOCR_GPD11_DS_Pos                         11
#define SYS_GPD_IOCR_GPD11_DS_Msk                         (0x01ul << SYS_GPD_IOCR_GPD11_DS_Pos)
// Bits 12-31 are Reserved.


/**
  * @brief System Manager Controller (SYS) - Register REGWRPROT
  * 
  * @description Register Write-Protection Control Register (REGWRPROT) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.3.4 Register Description, page 99
  * 
  * REGWRPROT GCR_BA+0x100
  * 
  * Some of the system control registers need to be protected to avoid inadvertent write and disturb
  * the chip operation. These system control registers are protected after the power-on reset till user
  * to disable register protection. For user to program these protected registers, a register protection
  * disable sequence needs to be followed by a special programming. The register protection disable
  * sequence is writing the data "59h", "16h" "88h" to the register REGWRPROT address at
  * 0x5000_0100 continuously. Any different data value, different sequence or any other write to
  * other address during these three data writing will abort the whole sequence.
  * 
  * After the protection is disabled, user can check the protection disable bit at address 0x5000_0100
  * bit0, 1 is protection disable, and 0 is protection enable. Then user can update the target protected
  * register value and then write any data to the address "0x5000_0100" to enable register protection.
  * 
  * This register is write for disable/enable register protection and read for the REGPROTDIS status
  * 
  * 
  * REGPROTDIS [0]
  * Register Write-Protection Disable index (Read Only)
  * 
  * 1 = Write-protection Disabled for writing protected registers.
  * 0 = Write-protection Enabled for writing protected registers. Any write to the protected
  *     register is ignored.
  * 
  * The Protected registers are:
  *     IPRSTC1: address 0x5000_0008
  *     BODCR: address 0x5000_0018
  *     PORCR: address 0x5000_0024
  *     PWRCON: address 0x5000_0200 (bit[6] is not protected for power wake-up interrupt clear)
  *     APBCLK bit[0]: address 0x5000_0208 (bit[0] is watchdog clock enabled)
  *     CLKSEL0: address 0x5000_0210 (for HCLK and CPU STCLK clock source select)
  *     CLKSEL1 bit[1:0]: address 0x5000_0214 (for watchdog clock source select)
  *     ISPCON: address 0x5000_C000 (Flash ISP Control register)
  *     WTCR: address 0x4000_4000
  *     FATCON: address 0x5000_C018
  * 
  * 
  * REGWRPROT [0:7]
  * Register Write-Protection Code (Write Only)
  * 
  * Some registers have write-protection function. Writing these registers has to disable
  * the protected function by writing the sequence value "59h", "16h", "88h" to this field.
  * After this sequence is completed, the REGPROTDIS bit will be set to 1 and write-
  * protection registers can be normal write.
  * 
  */

#define SYS_REGWRPROT_REGPROTDIS_Pos                      0
#define SYS_REGWRPROT_REGPROTDIS_Msk                      (0x01ul << SYS_REGWRPROT_REGPROTDIS_Pos)
#define SYS_REGWRPROT_REGWRPROT_Pos                       0
#define SYS_REGWRPROT_REGWRPROT_Msk                       (0xFFul << SYS_REGWRPROT_REGWRPROT_Pos)
// Bits 8-31 are Reserved.


/* =========================================================================================================================== */
/* ================                                     USBD Controller                                       ================ */
/* =========================================================================================================================== */


/**
  * @brief USBD Controller (USBD)
  * 
  * @description See NUC123 Technical Reference Manual 5.6.5 Register Map, page 158-160
  * 
  * USB_BA = 0x4006_0000
  * 
  * 
  * There are large swathes of registers included in the NUC123 Technical Reference Manual
  * that are NOT NEEDED by this implementation - so are not included in this header. They
  * are marked in this struct as RESERVED sections - to allow for future updates as needed.
  * 
  * The main USBD_T struct contains a set of EndPoint structs (USBD_EP_T) - maximum of 8
  * for the NUC123SD4AN0 MCU.
  * 
  * USBD EndPoint Registers [EndPoint 0~7]
  * 
  * EP0 Registers = USB_BA+0x500
  * EP1 Registers = USB_BA+0x510
  * EP2 Registers = USB_BA+0x520
  * EP3 Registers = USB_BA+0x530
  * EP4 Registers = USB_BA+0x540
  * EP5 Registers = USB_BA+0x550
  * EP6 Registers = USB_BA+0x560
  * EP7 Registers = USB_BA+0x570
  * 
  * 
  * SRAM = USB_BA+0x100 -> USB_BA+0x2FF [512 Bytes]
  * 
  * The SRAM is used for the endpoints buffers for all 8 endpoints.
  * 
  * Refer to section 5.4.4.7 for the endpoint SRAM structure and its description.
  * 
  */

typedef struct {

    __IO uint32_t BUFSEG;                  // Endpoint 0~7 Buffer Segmentation Register
    __IO uint32_t MXPLD;                   // Endpoint 0~7 Maximal Payload Register
    __IO uint32_t CFG;                     // Endpoint 0~7 Configuration Register
    __IO uint32_t CFGP;                    // Endpoint 0~7 Set Stall and Clear In/Out Ready Control Register

} USBD_EP_T;

typedef struct {

    __IO uint32_t INTEN;                   // USB_BA + 0x00  USB Interrupt Enable Register
    __IO uint32_t INTSTS;                  // USB_BA + 0x04  USB Interrupt Event Status Register
    __IO uint32_t FADDR;                   // USB_BA + 0x08  USB Device Function Address Register
    __I  uint32_t EPSTS;                   // USB_BA + 0x0C  USB Endpoint Status Register
    __IO uint32_t ATTR;                    // USB_BA + 0x10  USB Bus Status and Attribution Register
    __I  uint32_t FLDET;                   // USB_BA + 0x14  USB Floating Detection Register
    __IO uint32_t STBUFSEG;                // USB_BA + 0x18  Setup Token Buffer Segmentation Register
    __I  uint32_t RESERVED0[29]; 
    __IO uint32_t DRVSE0;                  // USB_BA + 0x90  USB Drive SE0 Control Register
    __I  uint32_t RESERVED2[283];
        USBD_EP_T EP[8];                   // USB_BA + 0x500 Endpoint 0~7 Control Registers

} USBD_T;


/**
  * @brief USB Device Controller (USBD) - Register USBD_INTEN
  * 
  * @description USB Interrupt Enable Register (USBD_INTEN) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.6.6 Register Description, page 161-162
  * 
  * USBD_INTEN = USB_BA+0x000
  * 
  * 
  * BUS_IE [0]
  * Bus Event Interrupt Enable
  * 
  * 1 = BUS event interrupt Enabled.
  * 0 = BUS event interrupt Disabled.
  * 
  * 
  * USB_IE [1]
  * USB Event Interrupt Enable
  * 
  * 1 = USB event interrupt Enabled.
  * 0 = USB event interrupt Disabled.
  * 
  * 
  * FLDET_IE [2]
  * Floating Detected Interrupt Enable
  * 
  * 1 = Floating detect Interrupt Enabled.
  * 0 = Floating detect Interrupt Disabled.
  * 
  * 
  * WAKEUP_IE [3]
  * USB Wake-up Interrupt Enable
  * 
  * 1 = Wake-up Interrupt Enabled.
  * 0 = Wake-up Interrupt Disabled.
  * 
  * 
  * WAKEUP_EN [8]
  * Wake-up Function Enable
  * 
  * 1 = USB wake-up function Enabled.
  * 0 = USB wake-up function Disabled.
  * 
  * 
  * INNAK_EN [15]
  * Active NAK Function and its Status in IN Token
  * 
  * 1 = NAK status is updated into the endpoint status register, USB_EPSTS, when it is
  *     set to 1 and there is NAK response in IN token. It also enables the interrupt event
  *     when the device responds NAK after receiving IN token
  * 0 = NAK status wasn‟t updated into the endpoint status register when it was set to 0.
  *     It also disables the interrupt event when device responds NAK after receiving IN
  *     token
  * 
  * 
  */

#define USBD_INTEN_BUS_IE_Pos                             0
#define USBD_INTEN_BUS_IE_Msk                             (0x01ul << USBD_INTEN_BUS_IE_Pos)
#define USBD_INTEN_USB_IE_Pos                             1
#define USBD_INTEN_USB_IE_Msk                             (0x01ul << USBD_INTEN_USB_IE_Pos)
#define USBD_INTEN_FLDET_IE_Pos                           2
#define USBD_INTEN_FLDET_IE_Msk                           (0x01ul << USBD_INTEN_FLDET_IE_Pos)
#define USBD_INTEN_WAKEUP_IE_Pos                          3
#define USBD_INTEN_WAKEUP_IE_Msk                          (0x01ul << USBD_INTEN_WAKEUP_IE_Pos)
// Bits 4-7 are Reserved.
#define USBD_INTEN_WAKEUP_EN_Pos                          8
#define USBD_INTEN_WAKEUP_EN_Msk                          (0x01ul << USBD_INTEN_WAKEUP_EN_Pos)
// Bits 9-14 are Reserved.
#define USBD_INTEN_INNAK_EN_Pos                           15
#define USBD_INTEN_INNAK_EN_Msk                           (0x01ul << USBD_INTEN_INNAK_EN_Pos)
// Bits 16-31 are Reserved.


/**
  * @brief USB Device Controller (USBD) - Register USBD_INTSTS
  * 
  * @description USB Interrupt Event Status Register (USBD_INTSTS) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.6.6 Register Description, page 163-165
  * 
  * USBD_INTSTS = USB_BA+0x004
  * 
  * 
  * BUS_STS [0]
  * BUS Interrupt Status
  * 
  * The BUS event means that there is one of the suspense or the resume function in the bus.
  * 
  * 1 = Bus event occurred.
  *     Check USBD_ATTR[3:0] to know which kind of bus event has occurred.
  *     Clear event by writing 1 to USBD_INTSTS[0].
  * 0 = No BUS event occurred.
  * 
  * 
  * USB_STS [1]
  * USB event Interrupt Status
  * 
  * The USB event includes the Setup Token, IN Token, OUT ACK, ISO IN, or ISO OUT
  * events in the bus.
  * 
  * 1 = USB event occurred
  *     Check EPSTS0~7[2:0] to know which kind of USB event has occured.
  *     Clear event by writing 1 to USBD_INTSTS[1] or EPSTS0~7 and SETUP (USBD_INTSTS[31])
  * 0 = No USB event occurred.
  * 
  * 
  * FLDET_STS [2]
  * Floating Detected Interrupt Status
  * 
  * 1 = There is attached/detached event in the USB bus.
  *     Cleared by writing 1 to USBD_INTSTS[2].
  * 0 = There is not attached/detached event in the USB.
  * 
  * 
  * WAKEUP_STS [3]
  * Wake-up Interrupt Status
  * 
  * 1 = Wake-up event occurred, cleared by writing 1 to USBD_INTSTS[3]
  * 0 = No Wake-up event occurred.
  * 
  * 
  * EPEVT0 [16]
  * Endpoint 0's USB Event Status
  * 
  * 1 = USB event occurred on Endpoint 0, check USBD_EPSTS[10:8] to know which kind
  *     of USB event has occurred.
  *     Cleared by writing 1 to USBD_INTSTS[16] or USBD_INTSTS[1]
  * 0 = No event occurred on Endpoint 0.
  * 
  * 
  * EPEVT1 [17]
  * Endpoint 1's USB Event Status
  * 
  * 1 = USB event occurred on Endpoint 1, check USBD_EPSTS[13:11] to know which kind
  *     of USB event has occurred.
  *     Cleared by writing 1 to USBD_INTSTS[17] or USBD_INTSTS[1]
  * 0 = No event occurred on Endpoint 1.
  * 
  * 
  * EPEVT2 [18]
  * Endpoint 2's USB Event Status
  * 
  * 1 = USB event occurred on Endpoint 2, check USBD_EPSTS[14:16] to know which kind
  *     of USB event has occurred.
  *     Cleared by writing 1 to USBD_INTSTS[18] or USBD_INTSTS[1]
  * 0 = No event occurred on Endpoint 2.
  * 
  * 
  * EPEVT3 [19]
  * Endpoint 3's USB Event Status
  * 
  * 1 = USB event occurred on Endpoint 3, check USBD_EPSTS[17:19] to know which kind
  *     of USB event has occurred.
  *     Cleared by writing 1 to USBD_INTSTS[19] or USBD_INTSTS[1]
  * 0 = No event occurred on Endpoint 3.
  * 
  * 
  * EPEVT4 [20]
  * Endpoint 4's USB Event Status
  * 
  * 1 = USB event occurred on Endpoint 4, check USBD_EPSTS[20:22] to know which kind
  *     of USB event has occurred.
  *     Cleared by writing 1 to USBD_INTSTS[20] or USBD_INTSTS[1]
  * 0 = No event occurred on Endpoint 4.
  * 
  * 
  * EPEVT5 [21]
  * Endpoint 5's USB Event Status
  * 
  * 1 = USB event occurred on Endpoint 5, check USBD_EPSTS[23:25] to know which kind
  *     of USB event has occurred.
  *     Cleared by writing 1 to USBD_INTSTS[21] or USBD_INTSTS[1]
  * 0 = No event occurred on Endpoint 5.
  * 
  * 
  * EPEVT6 [22]
  * Endpoint 6's USB Event Status
  * 
  * 1 = USB event occurred on Endpoint 6, check USBD_EPSTS[26:28] to know which kind
  *     of USB event has occurred.
  *     Cleared by writing 1 to USBD_INTSTS[22] or USBD_INTSTS[1]
  * 0 = No event occurred on Endpoint 6.
  * 
  * 
  * EPEVT7 [23]
  * Endpoint 7's USB Event Status
  * 
  * 1 = USB event occurred on Endpoint 7, check USBD_EPSTS[29:31] to know which kind
  *     of USB event has occurred.
  *     Cleared by writing 1 to USBD_INTSTS[23] or USBD_INTSTS[1]
  * 0 = No event occurred on Endpoint 7.
  * 
  * 
  * SETUP [31]
  * Setup Event Status
  * 
  * 1 = Setup event occurred. Cleared by writing 1 to USBD_INTSTS[31].
  * 0 = No Setup event.
  * 
  */

#define USBD_INTSTS_BUS_STS_Pos                           0
#define USBD_INTSTS_BUS_STS_Msk                           (0x01ul << USBD_INTSTS_BUS_STS_Pos)
#define USBD_INTSTS_USB_STS_Pos                           1
#define USBD_INTSTS_USB_STS_Msk                           (0x01ul << USBD_INTSTS_USB_STS_Pos)
#define USBD_INTSTS_FLDET_STS_Pos                         2
#define USBD_INTSTS_FLDET_STS_Msk                         (0x01ul << USBD_INTSTS_FLDET_STS_Pos)
#define USBD_INTSTS_WAKEUP_STS_Pos                        3
#define USBD_INTSTS_WAKEUP_STS_Msk                        (0x01ul << USBD_INTSTS_WAKEUP_STS_Pos)
// Bits 4-15 are Reserved.
#define USBD_INTSTS_EPEVT0_Pos                            16
#define USBD_INTSTS_EPEVT0_Msk                            (0x1ul << USBD_INTSTS_EPEVT0_Pos)
#define USBD_INTSTS_EPEVT1_Pos                            17
#define USBD_INTSTS_EPEVT1_Msk                            (0x1ul << USBD_INTSTS_EPEVT1_Pos)
#define USBD_INTSTS_EPEVT2_Pos                            18
#define USBD_INTSTS_EPEVT2_Msk                            (0x1ul << USBD_INTSTS_EPEVT2_Pos)
#define USBD_INTSTS_EPEVT3_Pos                            19
#define USBD_INTSTS_EPEVT3_Msk                            (0x1ul << USBD_INTSTS_EPEVT3_Pos)
#define USBD_INTSTS_EPEVT4_Pos                            20
#define USBD_INTSTS_EPEVT4_Msk                            (0x1ul << USBD_INTSTS_EPEVT4_Pos)
#define USBD_INTSTS_EPEVT5_Pos                            21
#define USBD_INTSTS_EPEVT5_Msk                            (0x1ul << USBD_INTSTS_EPEVT5_Pos)
#define USBD_INTSTS_EPEVT6_Pos                            22
#define USBD_INTSTS_EPEVT6_Msk                            (0x1ul << USBD_INTSTS_EPEVT6_Pos)
#define USBD_INTSTS_EPEVT7_Pos                            23
#define USBD_INTSTS_EPEVT7_Msk                            (0x1ul << USBD_INTSTS_EPEVT7_Pos)
// Bits 24-30 are Reserved.
#define USBD_INTSTS_SETUP_Pos                             31
#define USBD_INTSTS_SETUP_Msk                             (0x01ul << USBD_INTSTS_SETUP_Pos)


/**
  * @brief USB Device Controller (USBD) - Register USBD_FADDR
  * 
  * @description USB Interrupt Event Status Register (USBD_FADDR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.6.6 Register Description, page 166
  * 
  * USBD_FADDR = USB_BA+0x008
  * 
  * 
  * FADDR [0:6]
  * USB Device Function Address
  * 
  * A seven-bit value used as the address of the device on the USB BUS
  * 
  */

#define USBD_FADDR_FADDR_Pos                              0
#define USBD_FADDR_FADDR_Msk                              (0x07Ful << USBD_FADDR_FADDR_Pos)
// Bits 7-31 are Reserved.


/**
  * @brief USB Device Controller (USBD) - Register USBD_EPSTS
  * 
  * @description USB Endpoint Status Register (USBD_EPSTS) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.6.6 Register Description, page 167-169
  * 
  * USBD_EPSTS = USB_BA+0x00C
  * 
  * 
  * OVERRUN [7]
  * Overrun
  * 
  * Indicates that the received data is larger than the maximum payload number.
  * 
  * 1 = Out data is more than the Max Payload in MXPLD register or the Setup data is
  *     more than 8 bytes.
  * 0 = No overrun.
  * 
  * 
  * EPSTS0~7 [8:10]/[11:13]/[14:16]/[17:19]/[20:22]/[23:25]/[26:28]/[29:31]
  * Endpoint 0~7 Bus Status
  * 
  * These bits are used to indicate the current status of this endpoint.
  * 
  * 000 = In ACK
  * 001 = In NAK
  * 010 = Out Packet Data0 ACK
  * 110 = Out Packet Data1 ACK
  * 011 = Setup ACK
  * 111 = Isochronous transfer end
  * 
  */

// Bits 0-6 are Reserved.
#define USBD_EPSTS_OVERRUN_Pos                            7
#define USBD_EPSTS_OVERRUN_Msk                            (0b01ul << USBD_EPSTS_OVERRUN_Pos)
#define USBD_EPSTS_EPSTS0_Pos                             8
#define USBD_EPSTS_EPSTS0_Msk                             (0b0111ul << USBD_EPSTS_EPSTS0_Pos)
#define USBD_EPSTS_EPSTS1_Pos                             11
#define USBD_EPSTS_EPSTS1_Msk                             (0b0111ul << USBD_EPSTS_EPSTS1_Pos)
#define USBD_EPSTS_EPSTS2_Pos                             14
#define USBD_EPSTS_EPSTS2_Msk                             (0b0111ul << USBD_EPSTS_EPSTS2_Pos)
#define USBD_EPSTS_EPSTS3_Pos                             17
#define USBD_EPSTS_EPSTS3_Msk                             (0b0111ul << USBD_EPSTS_EPSTS3_Pos)
#define USBD_EPSTS_EPSTS4_Pos                             20
#define USBD_EPSTS_EPSTS4_Msk                             (0b0111ul << USBD_EPSTS_EPSTS4_Pos)
#define USBD_EPSTS_EPSTS5_Pos                             23
#define USBD_EPSTS_EPSTS5_Msk                             (0b0111ul << USBD_EPSTS_EPSTS5_Pos)
#define USBD_EPSTS_EPSTS6_Pos                             26
#define USBD_EPSTS_EPSTS6_Msk                             (0b0111ul << USBD_EPSTS_EPSTS6_Pos)
#define USBD_EPSTS_EPSTS7_Pos                             29
#define USBD_EPSTS_EPSTS7_Msk                             (0b0111ul << USBD_EPSTS_EPSTS7_Pos)


/**
  * @brief USB Device Controller (USBD) - Register USBD_ATTR
  * 
  * @description USB Bus Status and Attribution Register (USBD_ATTR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.6.6 Register Description, page 170-171
  * 
  * USBD_ATTR = USB_BA+0x010
  * 
  * 
  * USBRST [0]
  * USB Reset Status (Read Only)
  * 
  * 1 = Bus reset when SE0 (single-ended 0) more than 2.5 us.
  * 0 = No bus reset.
  * 
  * 
  * SUSPEND [1]
  * Suspend Status (Read Only)
  * 
  * 1 = Bus idle more than 3ms, either cable is unplugged or host is sleeping
  * 0 = No bus suspend.
  * 
  * 
  * RESUME [2]
  * Resume Status (Read Only)
  * 
  * 1 = Resume from suspend.
  * 0 = No bus resume.
  * 
  * 
  * TIME-OUT [3]
  * Time Out Status (Read Only)
  * 
  * 1 = No Bus response for more than 18 bits/units time.
  * 0 = No time-out.
  * 
  * 
  * PHY_EN [4]
  * PHY Transceiver Function Enable
  * 
  * 1 = PHY transceiver function Enabled.
  * 0 = PHY transceiver function Disabled.
  * 
  * 
  * RWAKEUP [5]
  * Remote Wake-up
  * 
  * 1 = Force USB bus to K (USB_DP low, USB_DM: high) state, used for remote wake-up.
  * 0 = Release the USB bus from K state.
  * 
  * 
  * USB_EN [7]
  * USB Controller Enable
  * 
  * 1 = USB Controller Enabled.
  * 0 = USB Controller Disabled.
  * 
  * 
  * DPPU_EN [8]
  * Pull-up resistor on USB_DP enable
  * 
  * 1 = Pull-up resistor in USB_DP bus Enabled.
  * 0 = Pull-up resistor in USB_DP bus Disabled.
  * 
  * 
  * PWRDN [9]
  * Power-down PHY Transceiver, Low Active
  * 
  * 1 = Power-up related circuit of PHY transceiver.
  * 0 = Power-down related circuit of PHY transceiver.
  * 
  * 
  * BYTEM [10]
  * CPU access USB SRAM Size Mode Selection
  * 
  * 1 = Byte Mode: The size of the transfer from CPU to USB SRAM must be Byte-wide.
  * 0 = Word Mode: The size of the transfer from CPU to USB SRAM must be Word-wide.
  * 
  */

#define USBD_ATTR_USBRST_Pos                              0
#define USBD_ATTR_USBRST_Msk                              (0x01ul << USBD_ATTR_USBRST_Pos)
#define USBD_ATTR_SUSPEND_Pos                             1
#define USBD_ATTR_SUSPEND_Msk                             (0x01ul << USBD_ATTR_SUSPEND_Pos)
#define USBD_ATTR_RESUME_Pos                              2
#define USBD_ATTR_RESUME_Msk                              (0x01ul << USBD_ATTR_RESUME_Pos)
#define USBD_ATTR_TIMEOUT_Pos                             3
#define USBD_ATTR_TIMEOUT_Msk                             (0x01ul << USBD_ATTR_TIMEOUT_Pos)
#define USBD_ATTR_PHY_EN_Pos                              4
#define USBD_ATTR_PHY_EN_Msk                              (0x01ul << USBD_ATTR_PHY_EN_Pos)
#define USBD_ATTR_RWAKEUP_Pos                             5
#define USBD_ATTR_RWAKEUP_Msk                             (0x01ul << USBD_ATTR_RWAKEUP_Pos)
// Bit 6 is Reserved.
#define USBD_ATTR_USB_EN_Pos                              7
#define USBD_ATTR_USB_EN_Msk                              (0x01ul << USBD_ATTR_USB_EN_Pos)
#define USBD_ATTR_DPPU_EN_Pos                             8
#define USBD_ATTR_DPPU_EN_Msk                             (0x01ul << USBD_ATTR_DPPU_EN_Pos)
#define USBD_ATTR_PWRDN_Pos                               9
#define USBD_ATTR_PWRDN_Msk                               (0x01ul << USBD_ATTR_PWRDN_Pos)
#define USBD_ATTR_BYTEM_Pos                               10
#define USBD_ATTR_BYTEM_Msk                               (0x01ul << USBD_ATTR_BYTEM_Pos)
// Bits 11-31 are Reserved.


/**
  * @brief USB Device Controller (USBD) - Register USBD_FLDET
  * 
  * @description USB Device Floating Detection Register (USBD_FLDET) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.6.6 Register Description, page 172
  * 
  * USBD_FLDET = USB_BA+0x014
  * 
  * 
  * FLDET [0]
  * Device Floating Detected
  * 
  * 1 = Controller is attached to the BUS.
  * 0 = Controller isn't attached to the USB host.
  * 
  */

#define USBD_FLDET_FLDET_Pos                              0
#define USBD_FLDET_FLDET_Msk                              (0x01ul << USBD_FLDET_FLDET_Pos)
// Bits 1-31 are Reserved.


/**
  * @brief USB Device Controller (USBD) - Register USBD_BUFSEG
  * 
  * @description Setup Token Buffer Segmentation Register (USBD_BUFSEG) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.6.6 Register Description, page 173
  * 
  * USBD_BUFSEG = USB_BA+0x018
  * 
  * 
  * BUFSEG [3:8]
  * Used to indicate the offset address for the Setup token with the USB SRAM
  * starting address.
  * 
  * The effective starting address is:
  *     USBD_SRAM address + { BUFSEG[8:3], 3‟b000}
  * Where the USBD_SRAM address = USB_BA+0x100h.
  * 
  * Note: This is ONLY used for Setup token.
  * 
  */

// Bits 0-2 are Reserved.
#define USBD_STBUFSEG_STBUFSEG_Pos                        3
#define USBD_STBUFSEG_STBUFSEG_Msk                        (0x03Ful << USBD_STBUFSEG_STBUFSEG_Pos)
// Bits 9-31 are Reserved.


/**
  * @brief USB Device Controller (USBD) - Register USBD_BUFSEG0~7
  * 
  * @description Buffer Segmentation Register (USBD_BUFSEG0~7) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.6.6 Register Description, page 174-175
  * 
  * USBD_BUFSEG0 = USB_BA+0x500
  * USBD_BUFSEG1 = USB_BA+0x510
  * USBD_BUFSEG2 = USB_BA+0x520
  * USBD_BUFSEG3 = USB_BA+0x530
  * USBD_BUFSEG4 = USB_BA+0x540
  * USBD_BUFSEG5 = USB_BA+0x550
  * USBD_BUFSEG6 = USB_BA+0x560
  * USBD_BUFSEG7 = USB_BA+0x570
  * 
  * 
  * BUFSEG [3:8]
  * Used to indicate the offset address for each endpoint with the USB SRAM
  * starting address.
  * 
  * The effective starting address is:
  *     USBD_SRAM address + { BUFSEG[8:3], 3‟b000}
  * Where the USBD_SRAM address = USB_BA+0x100h.
  * 
  */

// Bits 0-2 are Reserved.
#define USBD_BUFSEG_BUFSEG_Pos                            3
#define USBD_BUFSEG_BUFSEG_Msk                            (0x03Ful << USBD_BUFSEG_BUFSEG_Pos)
// Bits 9-31 are Reserved.


/**
  * @brief USB Device Controller (USBD) - Register USBD_MXPLD0~7
  * 
  * @description Maximal Payload Register (USBD_MXPLD0~7) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.6.6 Register Description, page 176-177
  * 
  * USBD_MXPLD0 = USB_BA+0x504
  * USBD_MXPLD1 = USB_BA+0x514
  * USBD_MXPLD2 = USB_BA+0x524
  * USBD_MXPLD3 = USB_BA+0x534
  * USBD_MXPLD4 = USB_BA+0x544
  * USBD_MXPLD5 = USB_BA+0x554
  * USBD_MXPLD6 = USB_BA+0x564
  * USBD_MXPLD7 = USB_BA+0x574
  * 
  * MXPLD [0:8]
  * Maximal Payload
  * 
  * It is used to define the data length which is transmitted to host (IN token) or the actual
  * data length which is received from the host (OUT token). It is also used to indicate
  * that the endpoint is ready to be transmitted in IN token or received in OUT token.
  * 
  * (1) When the register is written by CPU,
  *     For IN token, the value of MXPLD is used to define the data length to be transmitted
  *     and indicate the data buffer is ready.
  *     For OUT token, it means that the controller is ready to receive data from the host and
  *     the value of MXPLD is the maximal data length comes from host.
  * (2) When the register is read by CPU,
  *     For IN token, the value of MXPLD indicates the data length be transmitted to host
  *     For OUT token, the value of MXPLD indicates the actual data length receiving from host.
  * 
  * Note: Once MXPLD is written, the data packets will be transmitted/received
  * immediately after IN/OUT token arrived.
  * 
  */

#define USBD_MXPLD_MXPLD_Pos                              0
#define USBD_MXPLD_MXPLD_Msk                              (0x1FFul << USBD_MXPLD_MXPLD_Pos)
// Bits 9-31 are Reserved.


/**
  * @brief USB Device Controller (USBD) - Register USBD_CFG0~7
  * 
  * @description Endpoint Configuration Register (USBD_CFG0~7) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.6.6 Register Description, page 178-179
  * 
  * USBD_CFG0 = USB_BA+0x508
  * USBD_CFG1 = USB_BA+0x518
  * USBD_CFG2 = USB_BA+0x528
  * USBD_CFG3 = USB_BA+0x538
  * USBD_CFG4 = USB_BA+0x548
  * USBD_CFG5 = USB_BA+0x558
  * USBD_CFG6 = USB_BA+0x568
  * USBD_CFG7 = USB_BA+0x578
  * 
  * 
  * EP_NUM [0:3]
  * Endpoint Number
  * 
  * These bits are used to define the endpoint number of the current endpoint.
  * 
  * 
  * ISOCH [4]
  * Isochronous Endpoint
  * 
  * This bit is used to set the endpoint as Isochronous endpoint - no handshake.
  * 
  * 1 = Isochronous endpoint
  * 0 = No Isochronous endpoint
  * 
  * 
  * STATE [5:6]
  * Endpoint STATE
  * 
  * 00 = Endpoint Disabled
  * 01 = Out endpoint
  * 10 = IN endpoint
  * 11 = Undefined
  * 
  * 
  * DSQ_SYNC [7]
  * Data Sequence Synchronization
  * 
  * 1 = DATA1 PID
  * 0 = DATA0 PID
  * 
  * It is used to specify the DATA0 or DATA1 PID in the following IN token transaction.
  * H/W will toggle automatically in IN token - based on this bit.
  * 
  * 
  * CSTALL [9]
  * Clear STALL Response
  * 
  * 1 = Clear the device to respond STALL handshake in the setup stage.
  * 0 = Device Disabled to clear the STALL handshake in the setup stage.
  * 
  */

#define USBD_CFG_EP_NUM_Pos                               0
#define USBD_CFG_EP_NUM_Msk                               (0xFul << USBD_CFG_EP_NUM_Pos)
#define USBD_CFG_ISOCH_Pos                                4
#define USBD_CFG_ISOCH_Msk                                (0x01ul << USBD_CFG_ISOCH_Pos)
#define USBD_CFG_STATE_Pos                                5
#define USBD_CFG_STATE_Msk                                (0x03ul << USBD_CFG_STATE_Pos)
#define USBD_CFG_DSQ_SYNC_Pos                             7
#define USBD_CFG_DSQ_SYNC_Msk                             (0x01ul << USBD_CFG_DSQ_SYNC_Pos)
// Bit 8 is Reserved.
#define USBD_CFG_CSTALL_Pos                               9
#define USBD_CFG_CSTALL_Msk                               (0x01ul << USBD_CFG_CSTALL_Pos)
// Bits 10-31 are Reserved.


/**
  * @brief USB Device Controller (USBD) - Register USBD_CFGP0~7
  * 
  * @description Extra Configuration Register (USBD_CFGP0~7) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.6.6 Register Description, page 180-181
  * 
  * USBD_CFGP0 = USB_BA+0x50C
  * USBD_CFGP1 = USB_BA+0x51C
  * USBD_CFGP2 = USB_BA+0x52C
  * USBD_CFGP3 = USB_BA+0x53C
  * USBD_CFGP4 = USB_BA+0x54C
  * USBD_CFGP5 = USB_BA+0x55C
  * USBD_CFGP6 = USB_BA+0x56C
  * USBD_CFGP7 = USB_BA+0x57C
  * 
  * 
  * CLRRDY [0]
  * Clear Ready
  * 
  * When the MXPLD register is set by user, it means that the endpoint is ready to
  * transmit or receive data. If the user wants to turn off this transaction before the
  * transaction start, user can set this bit to 1 to turn it off, which is then automatically
  * cleared to 0.
  * 
  * For IN token, writing 1 is used to clear the IN token - ready to transmit data to USB.
  * For OUT token, writing 1 is used to clear the OUT token - ready to receive data from USB.
  * 
  * This bit is written 1 only and is always 0 when it is read back.
  * 
  * 
  * SSTALL [1]
  * Set STALL
  * 
  * 1 = Set the device to respond STALL automatically.
  * 0 = Device Disabled from responding to STALL.
  * 
  */

#define USBD_CFGP_CLRRDY_Pos                              0
#define USBD_CFGP_CLRRDY_Msk                              (0x01ul << USBD_CFGP_CLRRDY_Pos)
#define USBD_CFGP_SSTALL_Pos                              1
#define USBD_CFGP_SSTALL_Msk                              (0x01ul << USBD_CFGP_SSTALL_Pos)
// Bits 2-31 are Reserved.


/**
  * @brief USB Device Controller (USBD) - Register USBD_DRVSE0
  * 
  * @description USB Drive SE0 Register (USBD_DRVSE0) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.6.6 Register Description, page 182
  * 
  * USBD_DRVSE0 = USB_BA+0x090
  * 
  * 
  * DRVSE0 [0]
  * Drive Single Ended Zero in USB Bus
  * 
  * The Single Ended Zero (SE0) is when both lines (USB_DP and USB_DM) are being
  * pulled low.
  * 
  * 1 = Force USB PHY transceiver to drive SE0
  * 0 = None
  * 
  * 
  */

#define USBD_DRVSE0_DRVSE0_Pos                            0
#define USBD_DRVSE0_DRVSE0_Msk                            (0x01ul << USBD_DRVSE0_DRVSE0_Pos)
// Bits 1-31 are Reserved.


/**
  * @brief USB Device Controller (USBD) - Register USBD_PDMA
  * 
  * @description USB PDMA Controller Register (USBD_PDMA) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.6.6 Register Description, page 183
  * 
  * USBD_PDMA = USB_BA+0x0A4
  * 
  * 
  * PDMA_RW [0]
  * PDMA Read/Write
  * 
  * 1 = The PDMA will read data from USB buffer to memory
  * 0 = The PDMA will read data from memory to USB buffer
  * 
  * 
  * PDMA_EN [1]
  * PDMA Function Enable
  * 
  * 1 = The PDMA function in USB is active
  * 0 = The PDMA function is not active
  * 
  * This bit will be automatically cleared after the PDMA transfer completes.
  * 
  */


#define USBD_PDMA_PDMA_RW_Pos                             0
#define USBD_PDMA_PDMA_RW_Msk                             (0x01ul << USBD_PDMA_PDMA_RW_Pos)
#define USBD_PDMA_PDMA_EN_Pos                             1
#define USBD_PDMA_PDMA_EN_Msk                             (0x01ul << USBD_PDMA_PDMA_EN_Pos)
// Bits 2-31 are Reserved.



/* =========================================================================================================================== */
/* ================                                     GPIO Controller                                       ================ */
/* =========================================================================================================================== */


/**
  * @brief GPIO Controller (GPIO)
  * 
  * @description See NUC123 Technical Reference Manual 5.7.4 Register Map, page 187-190
  * 
  * GP_BA = 0x5000_4000
  * 
  * Struct rearranged from table to track actual locations (without having to specify offsets)
  * 
  * GPIO_T Struct is per-GPIO port, with offsets of:
  * 
  * GPIOA = GP_BA+0x000
  * GPIOB = GP_BA+0x040
  * GPIOC = GP_BA+0x080
  * GPIOD = GP_BA+0x0C0
  * GPIOF = GP_BA+0x140
  * 
  * DBNCECON = GP_BA+0x180
  * 
  * Note: DBNCECON in separate struct due to unary nature of register, compared to multiple nature of GPIO_T-based GPIO ports
  * 
  * There are separate DOUTs for each GPIO Port Pin (A10-A15, B0-B15, C0-C5:C8-C13, D0-D5:D8-D11, F0-F3) but these are NOT
  * NOT represented here as defines, other than the GPIO_PIN_DATA_BASE defining their start location.
  */
typedef struct {

    __IO uint32_t PMD;           // GP_BA + GPIO<x> + 0x00        GPIO Port [A/B/C/D/F] Pin I/O Mode Control
    __IO uint32_t OFFD;          // GP_BA + GPIO<x> + 0x04        GPIO Port [A/B/C/D/F] Pin Digital Input Path Disable Control
    __IO uint32_t DOUT;          // GP_BA + GPIO<x> + 0x08        GPIO Port [A/B/C/D/F] Data Output Value
    __IO uint32_t DMASK;         // GP_BA + GPIO<x> + 0x0C        GPIO Port [A/B/C/D/F] Data Output Write Mask
    __I  uint32_t PIN;           // GP_BA + GPIO<x> + 0x10        GPIO Port [A/B/C/D/F] Pin Value
    __IO uint32_t DBEN;          // GP_BA + GPIO<x> + 0x14        GPIO Port [A/B/C/D/F] De-bounce Enable
    __IO uint32_t IMD;           // GP_BA + GPIO<x> + 0x18        GPIO Port [A/B/C/D/F] Interrupt Mode Control
    __IO uint32_t IEN;           // GP_BA + GPIO<x> + 0x1C        GPIO Port [A/B/C/D/F] Interrupt Enable
    __IO uint32_t ISRC;          // GP_BA + GPIO<x> + 0x20        GPIO Port [A/B/C/D/F] Interrupt Source Flag

} GPIO_T;


typedef struct {

    __IO uint32_t DBNCECON;      // GP_BA + 0x180                 External Interrupt De-bounce Control

} GPIO_DBNCECON_T;

/**
  * @brief GPIO Controller (GPIO) - Register PMD
  * 
  * @description GPIO Port [A/B/C/D/F] I/O Mode Control (PMD) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.7.5 Register Description, page 191
  * 
  * 
  * GPIOx I/O Pin[n] Mode Control
  * 
  * 00 = GPIO port [n] pin is in INPUT mode
  * 01 = GPIO port [n] pin is in OUTPUT mode
  * 10 = GPIO port [n] pin is in Open-Drain mode
  * 11 = GPIO port [n] pin is in Quasi-bidirectional mode
  * 
  * GPIOA: valid n are 15~10. Others are reserved.
  * GPIOB: valid n are 15~12, 10~0. Others are reserved.
  * GPIOC: valid n are 13~8, 5~0. Others are reserved.
  * GPIOD: valid n are 11~8, 5~0. Others are reserved.
  * GPIOF: valid n are 3~0. Others are reserved.
  * 
  */

#define GPIO_PMD_PMD0_Pos                                 0
#define GPIO_PMD_PMD0_Msk                                 (0b011ul << GPIO_PMD_PMD0_Pos)
#define GPIO_PMD_PMD1_Pos                                 2
#define GPIO_PMD_PMD1_Msk                                 (0b011ul << GPIO_PMD_PMD1_Pos)
#define GPIO_PMD_PMD2_Pos                                 4
#define GPIO_PMD_PMD2_Msk                                 (0b011ul << GPIO_PMD_PMD2_Pos)
#define GPIO_PMD_PMD3_Pos                                 6
#define GPIO_PMD_PMD3_Msk                                 (0b011ul << GPIO_PMD_PMD3_Pos)
#define GPIO_PMD_PMD4_Pos                                 8
#define GPIO_PMD_PMD4_Msk                                 (0b011ul << GPIO_PMD_PMD4_Pos)
#define GPIO_PMD_PMD5_Pos                                 10
#define GPIO_PMD_PMD5_Msk                                 (0b011ul << GPIO_PMD_PMD5_Pos)
#define GPIO_PMD_PMD6_Pos                                 12
#define GPIO_PMD_PMD6_Msk                                 (0b011ul << GPIO_PMD_PMD6_Pos)
#define GPIO_PMD_PMD7_Pos                                 14
#define GPIO_PMD_PMD7_Msk                                 (0b011ul << GPIO_PMD_PMD7_Pos)
#define GPIO_PMD_PMD8_Pos                                 16
#define GPIO_PMD_PMD8_Msk                                 (0b011ul << GPIO_PMD_PMD8_Pos)
#define GPIO_PMD_PMD9_Pos                                 18
#define GPIO_PMD_PMD9_Msk                                 (0b011ul << GPIO_PMD_PMD9_Pos)
#define GPIO_PMD_PMD10_Pos                                20
#define GPIO_PMD_PMD10_Msk                                (0b011ul << GPIO_PMD_PMD10_Pos)
#define GPIO_PMD_PMD11_Pos                                22
#define GPIO_PMD_PMD11_Msk                                (0b011ul << GPIO_PMD_PMD11_Pos)
#define GPIO_PMD_PMD12_Pos                                24
#define GPIO_PMD_PMD12_Msk                                (0b011ul << GPIO_PMD_PMD12_Pos)
#define GPIO_PMD_PMD13_Pos                                26
#define GPIO_PMD_PMD13_Msk                                (0b011ul << GPIO_PMD_PMD13_Pos)
#define GPIO_PMD_PMD14_Pos                                28
#define GPIO_PMD_PMD14_Msk                                (0b011ul << GPIO_PMD_PMD14_Pos)
#define GPIO_PMD_PMD15_Pos                                30
#define GPIO_PMD_PMD15_Msk                                (0b011ul << GPIO_PMD_PMD15_Pos)

/**
  * @brief GPIO Controller (GPIO) - Register OFFD
  * 
  * @description GPIO Port [A/B/C/D/F] OFF Digital Input Path Enable (OFFD) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.7.5 Register Description, page 192
  * 
  * GPIOx I/O Pin[n] OFF Digital Input Path Enable
  * 
  * Each of these bits is used to control if the input path of corresponding GPIO pin is
  * disabled. If input is analog signal, user can OFF digital input path to avoid creepage
  * 
  * 1 = IO digital input path Disabled (digital input tied to low).
  * 0 = IO digital input path Enabled.
  * 
  * GPIOA: valid n are 15~10. Others are reserved.
  * GPIOB: valid n are 15~12, 10~0. Others are reserved.
  * GPIOC: valid n are 13~8, 5~0. Others are reserved.
  * GPIOD: valid n are 11~8, 5~0. Others are reserved.
  * GPIOF: valid n are 3~0. Others are reserved.
  * 
  */

// Bits 0-15 are Reserved
// Bits 16-31
#define GPIO_OFFD_OFFD_Pos                                16
#define GPIO_OFFD_OFFD_Msk                                (0xFFFFul << GPIO_OFFD_OFFD_Pos)

/**
  * @brief GPIO Controller (GPIO) - Register DOUT
  * 
  * @description GPIO Port [A/B/C/D/F] Output Value (DOUT) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.7.5 Register Description, page 193
  * 
  * GPIOx Pin[n] Output Value
  * 
  * Each of these bits control the status of a GPIO pin when the GPIO pin is configures
  * as output, open-drain and quasi-mode.
  * 
  * 1 = GPIO port [A/B/C/DF] Pin[n] will drive High if the GPIO pin is configures as output,
  *     open-drain and quasi-mode.
  * 0 = GPIO port [A/B/C/D/ F] Pin[n] will drive Low if the GPIO pin is configures as
  *     output, open-drain and quasi-mode.
  * 
  * GPIOA: valid n are 15~10. Others are reserved.
  * GPIOB: valid n are 15~12, 10~0. Others are reserved.
  * GPIOC: valid n are 13~8, 5~0. Others are reserved.
  * GPIOD: valid n are 11~8, 5~0. Others are reserved.
  * GPIOF: valid n are 3~0. Others are reserved.
  * 
  */

// Bits 0-15
#define GPIO_DOUT_DOUT_Pos                                0
#define GPIO_DOUT_DOUT_Msk                                (0xFFFFul << GPIO_DOUT_DOUT_Pos)
// Bits 16-31 are Reserved


/**
  * @brief GPIO Controller (GPIO) - Register DMASK
  * 
  * @description GPIO Port [A/B/C/D/F] Data Output Write Mask (DMASK) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.7.5 Register Description, page 194
  * 
  * GPIO Port [A/B/C/D/F] Data Output Write Mask
  * 
  * These bits are used to protect the corresponding register of GPIOx_DOUT bit[n].
  * When set the DMASK bit[n] to 1, the corresponding GPIOx_DOUT[n] bit is protected.
  * The write signal is masked, write data to the protect bit is ignored
  * 
  * 1 = The corresponding GPIOx_DOUT[n] bit is protected
  * 0 = The corresponding GPIOx_DOUT[n] bit can be updated
  * 
  * IMPORTANT
  * =========
  * This function only protect corresponding GPIOx_DOUT[n] bit, and WILL NOT
  * protect corresponding bit control registers (GPIOAx_DOUT, GPIOBx_DOUT,
  * GPIOCx_DOUT, GPIODx_DOUT and GPIOFx_DOUT) found later in the memory map.
  * 
  * GPIOA: valid n are 15~10. Others are reserved.
  * GPIOB: valid n are 15~12, 10~0. Others are reserved.
  * GPIOC: valid n are 13~8, 5~0. Others are reserved.
  * GPIOD: valid n are 11~8, 5~0. Others are reserved.
  * GPIOF: valid n are 3~0. Others are reserved.
  * 
  */

// Bits 0-15
#define GPIO_DMASK_DMASK_Pos                              0
#define GPIO_DMASK_DMASK_Msk                              (0xFFFFul << GPIO_DMASK_DMASK_Pos)
// Bits 16-31 are Reserved.

/**
  * @brief GPIO Controller (GPIO) - Register PIN
  * 
  * @description GPIO Port [A/B/C/D/F] Pin Value (PIN) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.7.5 Register Description, page 195
  * 
  * GPIO Port [A/B/C/D/F] Pin Values
  * 
  * Each bit of the register reflects the actual status of the respective GPIO pin If bit is 1,
  * it indicates the corresponding pin status is high, else the pin status is low
  * 
  * GPIOA: valid n are 15~10. Others are reserved.
  * GPIOB: valid n are 15~12, 10~0. Others are reserved.
  * GPIOC: valid n are 13~8, 5~0. Others are reserved.
  * GPIOD: valid n are 11~8, 5~0. Others are reserved.
  * GPIOF: valid n are 3~0. Others are reserved.
  * 
  */

// Bits 0-15
#define GPIO_PIN_PIN_Pos                                  0
#define GPIO_PIN_PIN_Msk                                  (0xFFFFul << GPIO_PIN_PIN_Pos)
// Bits 16-31 are Reserved.

/**
  * @brief GPIO Controller (GPIO) - Register DBEN
  * 
  * @description GPIO Port [A/B/C/D/F] De-bounce Enable (DBEN) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.7.5 Register Description, page 196
  * 
  * GPIO Port [A/B/C/D/F] Input Signal De-bounce Enable
  * 
  * DBEN[n] is used to enable the de-bounce function for each corresponding bit.
  * If the input signal pulse width can't be sampled by continuous two de-bounce
  * sample cycle The input signal transition is seen as the signal bounce and
  * will not trigger the interrupt.
  * 
  * The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample
  * cycle is controlled by DBNCECON[3:0]
  * 
  * The DBEN[n] is used for "edge-trigger" interrupt only, and ignored for "level trigger"
  * interrupt
  * 
  * 1 = The bit[n] de-bounce function is enabled
  * 0 = The bit[n] de-bounce function is disabled
  * 
  * The de-bounce function is ONLY valid for edge triggered interrupt. If the interrupt mode
  * is level triggered, the de-bounce enable bit is ignored.
  * 
  * GPIOA: valid n are 15~10. Others are reserved.
  * GPIOB: valid n are 15~12, 10~0. Others are reserved.
  * GPIOC: valid n are 13~8, 5~0. Others are reserved.
  * GPIOD: valid n are 11~8, 5~0. Others are reserved.
  * GPIOF: valid n are 3~0. Others are reserved.
  * 
  */

// Bits 0-15
#define GPIO_DBEN_DBEN_Pos                                0
#define GPIO_DBEN_DBEN_Msk                                (0xFFFFul << GPIO_DBEN_DBEN_Pos)
// Bits 16-31 are Reserved.

/**
  * @brief GPIO Controller (GPIO) - Register IMD
  * 
  * @description GPIO Port [A/B/C/D/F] Interrupt Mode Control (IMD) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.7.5 Register Description, page 197
  * 
  * GPIO Port [A/B/C/D/F] Edge or Level Detection Interrupt Control
  * 
  * IMD[n] is used to choose between a level trigger or an edge trigger intterupt.
  * 
  * If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce.
  * If the interrupt is by level trigger, the input source is sampled during one HCLK clock
  * and then generates the interrupt.
  * 
  * 1 = Level trigger interrupt.
  * 0 = Edge trigger interrupt.
  * 
  * If pin is set as a level trigger interrupt, only one level can be set on the registers
  * GPIOx_IEN. If both levels are set to trigger an interrupt, the setting is ignored and no
  * interrupt will occur.
  * 
  * The de-bounce function is ONLY valid for edge triggered interrupt. If the interrupt mode
  * is level triggered, the de-bounce enable bit is ignored.
  * 
  * GPIOA: Valid n are 15~10. Others are reserved.
  * GPIOB: Valid n are 15~12, 10~0. Others are reserved.
  * GPIOC: Valid n are 13~8, 5~0. Others are reserved.
  * GPIOD: Valid n are 11~8, 5~0. Others are reserved.
  * GPIOF: valid n are 3~0. Others are reserved.
  * 
  */

// Bits 0-15
#define GPIO_IMD_IMD_Pos                                  0
#define GPIO_IMD_IMD_Msk                                  (0xFFFFul << GPIO_IMD_IMD_Pos)
// Bits 16-31 are Reserved.

/**
  * @brief GPIO Controller (GPIO) - Register IEN
  * 
  * @description GPIO Port [A/B/C/D/F] Interrupt Enable Control (IEN) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.7.5 Register Description, page 199-200
  *
  * IR_EN[n]
  * ========
  * GPIO Port [A/B/C/D/F] Interrupt Enable by Input Rising Edge or Input Level High
  * 
  * IR_EN[n] is used to enable the interrupt for each of the corresponding input
  * GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function
  * 
  * When the IR_EN[n] bit is set to 1:
  * 
  * If the interrupt is level triggered, the input PIN[n] state at level "high" will generate the
  * interrupt.
  * If the interrupt is edge triggered, the input PIN[n] state changes from "low-to-high" will
  * generate the interrupt.
  * 
  * 1 = PIN[n] level-high or low-to-high interrupt Enabled.
  * 0 = PIN[n] level-high or low-to-high interrupt Disabled.
  * 
  * 
  * IF_EN[n]
  * ========
  * GPIO Port [A/B/C/D/F] Interrupt Enable by Input Falling Edge or Input Level Low
  * 
  * IF_EN[n] is used to enable the interrupt for each of the corresponding input
  * GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function
  * 
  * When set the IF_EN[n] bit to 1:
  * 
  * If the interrupt is level triggered, the input PIN[n] state at level "low" will generate the
  * interrupt.
  * If the interrupt is edge triggered, the input PIN[n] state changes from "high-to-low" will
  * generate the interrupt.
  * 
  * 1 = PIN[n] state low-level or high-to-low change interrupt Enabled.
  * 0 = PIN[n] state low-level or high-to-low change interrupt Disabled.
  * 
  * 
  * GPIOA: Valid n are 15~10. Others are reserved.
  * GPIOB: Valid n are 15~12, 10~0. Others are reserved.
  * GPIOC: Valid n are 13~8, 5~0. Others are reserved.
  * GPIOD: Valid n are 11~8, 5~0. Others are reserved.
  * GPIOF: Valid n are 3~0. Others are reserved.
  * 
  */

// IF_EN[n]
// Bits 0-15
#define GPIO_IEN_IF_EN_Pos                                0
#define GPIO_IEN_IF_EN_Msk                                (0xFFFFul << GPIO_IEN_IF_EN_Pos)
// IR_EN[n]
// Bits 16-31
#define GPIO_IEN_IR_EN_Pos                                16
#define GPIO_IEN_IR_EN_Msk                                (0xFFFFul << GPIO_IEN_IR_EN_Pos)

/**
  * @brief GPIO Controller (GPIO) - Register ISRC
  * 
  * @description GPIO Port [A/B/C/D/F] Interrupt Trigger Source (ISRC) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.7.5 Register Description, page 201
  * 
  * GPIO Port [A/B/C/D/F] Interrupt Trigger Source Indicator
  * 
  * On Read:
  * 1 = Indicates GPIOx[n] generate an interrupt.
  * 0 = No interrupt at GPIOx[n].
  * 
  * On Write :
  * 1= Clear the corresponding pending interrupt.
  * 0= No action.
  * 
  * GPIOA: Valid n are 15~10. Others are reserved.
  * GPIOB: Valid n are 15~12, 10~0. Others are reserved.
  * GPIOC: Valid n are 13~8, 5~0. Others are reserved.
  * GPIOD: Valid n are 11~8, 5~0. Others are reserved.
  * GPIOF: Valid n are 3~0. Others are reserved.
  * 
  */
// Bits 0-15
#define GPIO_ISRC_ISRC_Pos                                0
#define GPIO_ISRC_ISRC_Msk                                (0xFFFFul << GPIO_ISRC_ISRC_Pos)
// Bits 16-31 are Reserved.

/**
  * @brief GPIO Controller (GPIO) - Register DBNCECON
  * 
  * @description GPIO Port [A/B/C/D/F] Interrupt De-bounce Cycle Control (DBNCECON) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.7.5 Register Description, page 202-203
  * 
  * DBNCECON = GP_BA+0x180
  * 
  * 
  * ICLK_ON
  * =======
  * 
  * Interrupt clock On mode
  * Setting this bit to 0 will disable the interrupt generate circuit clock if the pin[n] interrupt
  * is disabled
  * 
  * 1 = Interrupt generated circuit clock always Enabled.
  * 0 = Clock Disabled if the GPIOA/B/C/D/F[n] interrupt is disabled.
  * 
  * DBCLKSRC
  * ========
  * De-bounce counter clock source select
  * 
  * 1 = De-bounce counter clock source is the internal 10 kHz low speed oscillator.
  * 0 = De-bounce counter clock source is the HCLK.
  * 
  * DBCLKSEL
  * ========
  * De-bounce sampling cycle selection
  * 
  * 0 Sample interrupt input once per 1 clocks
  * 1 Sample interrupt input once per 2 clocks
  * 2 Sample interrupt input once per 4 clocks
  * 3 Sample interrupt input once per 8 clocks
  * 4 Sample interrupt input once per 16 clocks
  * 5 Sample interrupt input once per 32 clocks
  * 6 Sample interrupt input once per 64 clocks
  * 7 Sample interrupt input once per 128 clocks
  * 8 Sample interrupt input once per 256 clocks
  * 9 Sample interrupt input once per 2*256 clocks
  * 10 Sample interrupt input once per 4*256clocks
  * 11 Sample interrupt input once per 8*256 clocks
  * 12 Sample interrupt input once per 16*256 clocks
  * 13 Sample interrupt input once per 32*256 clocks
  * 14 Sample interrupt input once per 64*256 clocks
  * 15 Sample interrupt input once per 128*256 clocks
  * 
  */

// DBCLKSEL [0:3]
#define GPIO_DBNCECON_DBCLKSEL_Pos                        0
#define GPIO_DBNCECON_DBCLKSEL_Msk                        (0x0Ful << GPIO_DBNCECON_DBCLKSEL_Pos)
// DBCLKSRC [4]
#define GPIO_DBNCECON_DBCLKSRC_Pos                        4
#define GPIO_DBNCECON_DBCLKSRC_Msk                        (0x01ul << GPIO_DBNCECON_DBCLKSRC_Pos)
// ICLK_ON [5]
#define GPIO_DBNCECON_ICLK_ON_Pos                         5
#define GPIO_DBNCECON_ICLK_ON_Msk                         (0x01ul << GPIO_DBNCECON_ICLK_ON_Pos)
// Bits 6-31 are Reserved.


/* =========================================================================================================================== */
/* ================                                      PWM Controller                                       ================ */
/* =========================================================================================================================== */

/**
  * @brief PWM Controller (PWM)
  * 
  * @description See NUC123 Technical Reference Manual 5.9.5 Register Map, page 243-244
  * 
  * PWMA_BA = 0x4004_0000 (PWM group A)
  * 
  * Struct has several reserved sections for future expansion (the memory-mapped peripherals have these gaps)
  * 
  * PWM_T Struct is for PWM Group A on the NUC123SD4AN0 - other NUMICRO family processors have more than one group.
  * 
  */

typedef struct {

    __IO uint32_t PPR;           // PWMA_BA + 0x00                        PWM Group A Prescaler Register
    __IO uint32_t CSR;           // PWMA_BA + 0x04                        PWM Group A Clock Source Divider Select Register
    __IO uint32_t PCR;           // PWMA_BA + 0x08                        PWM Group A Control Register
    __IO uint32_t CNR0;          // PWMA_BA + 0x0C                        PWM Group A Counter Register 0
    __IO uint32_t CMR0;          // PWMA_BA + 0x10                        PWM Group A Comparator Register 0
    __I  uint32_t PDR0;          // PWMA_BA + 0x14                        PWM Group A Data Register 0
    __IO uint32_t CNR1;          // PWMA_BA + 0x18                        PWM Group A Counter Register 1
    __IO uint32_t CMR1;          // PWMA_BA + 0x1C                        PWM Group A Comparator Register 1
    __I  uint32_t PDR1;          // PWMA_BA + 0x20                        PWM Group A Data Register 1
    __IO uint32_t CNR2;          // PWMA_BA + 0x24                        PWM Group A Counter Register 2
    __IO uint32_t CMR2;          // PWMA_BA + 0x28                        PWM Group A Comparator Register 2
    __I  uint32_t PDR2;          // PWMA_BA + 0x2C                        PWM Group A Data Register 2
    __IO uint32_t CNR3;          // PWMA_BA + 0x30                        PWM Group A Counter Register 3
    __IO uint32_t CMR3;          // PWMA_BA + 0x34                        PWM Group A Comparator Register 3
    __I  uint32_t PDR3;          // PWMA_BA + 0x38                        PWM Group A Data Register 3
    __I  uint32_t RESERVED0[1]; 
    __IO uint32_t PIER;          // PWMA_BA + 0x40                        PWM Group A Interrupt Enable Register
    __IO uint32_t PIIR;          // PWMA_BA + 0x44                        PWM Group A Interrupt Indication Register
    __I  uint32_t RESERVED1[2];  
    __IO uint32_t CCR0;          // PWMA_BA + 0x50                        PWM Group A Capture Control Register 0
    __IO uint32_t CCR2;          // PWMA_BA + 0x54                        PWM Group A Capture Control Register 2
    __IO uint32_t CRLR0;         // PWMA_BA + 0x58                        PWM Group A Capture Rising Latch Register (Channel 0)
    __IO uint32_t CFLR0;         // PWMA_BA + 0x5C                        PWM Group A Capture Falling Latch Register (Channel 0)
    __IO uint32_t CRLR1;         // PWMA_BA + 0x60                        PWM Group A Capture Rising Latch Register (Channel 1)
    __IO uint32_t CFLR1;         // PWMA_BA + 0x64                        PWM Group A Capture Falling Latch Register (Channel 1)
    __IO uint32_t CRLR2;         // PWMA_BA + 0x68                        PWM Group A Capture Rising Latch Register (Channel 2)
    __IO uint32_t CFLR2;         // PWMA_BA + 0x6C                        PWM Group A Capture Falling Latch Register (Channel 2)
    __IO uint32_t CRLR3;         // PWMA_BA + 0x70                        PWM Group A Capture Rising Latch Register (Channel 3)
    __IO uint32_t CFLR3;         // PWMA_BA + 0x74                        PWM Group A Capture Falling Latch Register (Channel 3)
    __IO uint32_t CAPENR;        // PWMA_BA + 0x78                        PWM Group A Capture Input 0~3 Enable Register
    __IO uint32_t POE;           // PWMA_BA + 0x7C                        PWM Group A Output Enable for Channel 0~3
    __IO uint32_t TCON;          // PWMA_BA + 0x80                        PWM Group A Trigger Control for Channel 0~3
    __IO uint32_t TSTATUS;       // PWMA_BA + 0x84                        PWM Group A Trigger Status Register
    __IO uint32_t SYNCBUSY0;     // PWMA_BA + 0x88                        PWM Group A [PWM0] Synchronous Busy Status Register
    __IO uint32_t SYNCBUSY1;     // PWMA_BA + 0x8C                        PWM Group A [PWM1] Synchronous Busy Status Register
    __IO uint32_t SYNCBUSY2;     // PWMA_BA + 0x90                        PWM Group A [PWM2] Synchronous Busy Status Register
    __IO uint32_t SYNCBUSY3;     // PWMA_BA + 0x94                        PWM Group A [PWM3] Synchronous Busy Status Register
    __I  uint32_t RESERVE2[10]; 
    __IO uint32_t CAPPDMACTL;    // PWMA_BA + 0xC0                        PWM Group A Trigger Status Register
    __IO uint32_t CAP0PDMA;      // PWMA_BA + 0xC4                        PWM Group A PDMA channel 0 DATA Register
    __IO uint32_t CAP1PDMA;      // PWMA_BA + 0xC8                        PWM Group A PDMA channel 1 DATA Register
    __IO uint32_t CAP2PDMA;      // PWMA_BA + 0xCC                        PWM Group A PDMA channel 2 DATA Register
    __IO uint32_t CAP3PDMA;      // PWMA_BA + 0xD0                        PWM Group A PDMA channel 3 DATA Register

} PWM_T;


/**
  * @brief PWM Controller (PWM) - Register PPR
  * 
  * @description PWM Group A Prescalar Register (PPR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 245
  * 
  * PPR = PWMA_BA+0x00
  * 
  * 
  * CP01 [0:7]
  * Clock Prescaler 0 (PWM-timer 0 / 1 for Group A)
  * 
  * Clock input is divided by (CP01 + 1) before it is fed to the corresponding PWM-timer.
  * If CP01 = 0, the clock prescaler 0 output clock will be stopped. Thus the corresponding
  * PWM timer will also be stopped.
  * 
  * 
  * CP23 [8:15]
  * Clock Prescaler 2 (PWM Timer2 / 3 for Group A)
  * 
  * Clock input is divided by (CP23 + 1) before it is fed to the corresponding PWM-timer.
  * If CP23 = 0, the clock prescaler 2 output clock will be stopped. Thus the corresponding
  * PWM timer will also be stopped.
  * 
  * 
  * DZI01 [16:23]
  * Dead-zone Interval for Pair of Channel 0 and Channel 1 (PWM0 and PWM1 Pair
  * for PWM Group A). These 8 bits determine dead-zone length.
  * 
  * 
  * DZI23 [24:31]
  * Dead-zone Interval for Pair of Channel 2 and Channel 3 (PWM2 and PWM3 Pair
  * for PWM Group A). These 8 bits determine dead-zone length.
  * 
  * For both DZI01 and DZI23:
  * The unit time of dead-zone length is received from corresponding CSR bits.
  * 
  */

/* PWM PPR Bit Field Definitions */

#define PWM_PPR_CP01_Pos                                  0
#define PWM_PPR_CP01_Msk                                  (0xFFul << PWM_PPR_CP01_Pos)
#define PWM_PPR_CP23_Pos                                  8
#define PWM_PPR_CP23_Msk                                  (0xFFul << PWM_PPR_CP23_Pos)
#define PWM_PPR_DZI01_Pos                                 16
#define PWM_PPR_DZI01_Msk                                 (0xFFul << PWM_PPR_DZI01_Pos)
#define PWM_PPR_DZI23_Pos                                 24
#define PWM_PPR_DZI23_Msk                                 (0xFFul << PWM_PPR_DZI23_Pos)


/**
  * @brief PWM Controller (PWM) - Register CSR
  * 
  * @description PWM Group A Clock Selection Register (CSR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 246-247
  * 
  * CSR = PWMA_BA+0x04
  * 
  * 
  * CSR0 [0:2]
  * PWM Timer 0 Clock Source Selection (PWM Timer 0 for Group A and PWM Timer
  * 4 for Group B)
  * 
  * Select clock input for PWM timer.
  * 
  * CSRn [High->Low]  |  Input Clock Divided by
  * ==================|=========================
  *       100         |            1
  *       000         |            2
  *       001         |            4
  *       010         |            8
  *       011         |           16
  * 
  * 
  * CSR1 [0:2]
  * PWM Timer 0 Clock Source Selection (PWM Timer 1 for Group A)
  * 
  * Select clock input for PWM timer.
  * 
  * CSR1 [High->Low]  |  Input Clock Divided by
  * ==================|=========================
  *       100         |            1
  *       000         |            2
  *       001         |            4
  *       010         |            8
  *       011         |           16
  * 
  * 
  * CSR2 [0:2]
  * PWM Timer 2 Clock Source Selection (PWM Timer 2 for Group A)
  * 
  * Select clock input for PWM timer.
  * 
  * CSR2 [High->Low]  |  Input Clock Divided by
  * ==================|=========================
  *       100         |            1
  *       000         |            2
  *       001         |            4
  *       010         |            8
  *       011         |           16
  * 
  * 
  * CSR3 [12:14]
  * PWM Timer 0 Clock Source Selection (PWM Timer 0 for Group A)
  * 
  * Select clock input for PWM timer.
  * 
  * CSR3 [High->Low]  |  Input Clock Divided by
  * ==================|=========================
  *       100         |            1
  *       000         |            2
  *       001         |            4
  *       010         |            8
  *       011         |           16
  * 
  */

#define PWM_CSR_CSR0_Pos                                  0
#define PWM_CSR_CSR0_Msk                                  (0b0111ul << PWM_CSR_CSR0_Pos)
// Bit 3 is Reserved.
#define PWM_CSR_CSR1_Pos                                  4
#define PWM_CSR_CSR1_Msk                                  (0b0111ul << PWM_CSR_CSR1_Pos)
// Bit 7 is Reserved.
#define PWM_CSR_CSR2_Pos                                  8
#define PWM_CSR_CSR2_Msk                                  (0b0111ul << PWM_CSR_CSR2_Pos)
// Bit 11 is Reserved.
#define PWM_CSR_CSR3_Pos                                  12
#define PWM_CSR_CSR3_Msk                                  (0b0111ul << PWM_CSR_CSR3_Pos)
// Bits 15-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register PCR
  * 
  * @description PWM Group A Control Register (PCR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 248-250
  * 
  * PCR = PWMA_BA+0x08
  * 
  * 
  * CH0EN [0]
  * PWM-Timer 0 Enable (PWM timer 0 for group A)
  * 
  * 1 = Corresponding PWM-Timer Start Run Enabled.
  * 0 = Corresponding PWM-Timer Running Stopped.
  * 
  * 
  * CH0PINV [1]
  * PWM-Timer 0 Output Polar Inverse Enable (PWM Timer 0 for Group A)
  * 
  * 1 = PWM0 output polar inverse Enabled.
  * 0 = PWM0 output polar inverse Disabled.
  * 
  * 
  * CH0INV [2]
  * PWM-Timer 0 Output Inverter Enable (PWM Timer 0 for Group A)
  * 
  * 1 = Inverter Enabled.
  * 0 = Inverter Disabled.
  * 
  * 
  * CH0MOD [3]
  * PWM-Timer 0 Auto-reload/One-Shot Mode (PWM Timer 0 for Group A)
  * 
  * 1 = Auto-reload mode.
  * 0 = One-shot mode.
  * 
  * Note: If there is a transition at this bit, it will cause CNR0 and CMR0 be clear.
  * 
  * 
  * DZEN01 [4]
  * Dead-Zone 0 Generator Enable (PWM0 and PWM1 Pair for PWM Group A )
  * 
  * 1 = Enabled.
  * 0 = Disabled.
  * 
  * Note: When dead-zone generator is enabled, the pair of PWM0 and PWM1 becomes a
  * complementary pair for PWM group A.
  * 
  * 
  * DZEN23 [5]
  * Dead-Zone 2 Generator Enable (PWM2 and PWM3 Pair for PWM Group A)
  * 
  * 1 = Enabled.
  * 0 = Disabled.
  * 
  * Note: When dead-zone generator is enabled, the pair of PWM2 and PWM3 becomes a
  * complementary pair for PWM group A.
  * 
  * 
  * CH1EN [8]
  * PWM-Timer 1 Enable (PWM timer 1 for group A)
  * 
  * 1 = Corresponding PWM-Timer Start Run Enabled.
  * 0 = Corresponding PWM-Timer Running Stopped.
  * 
  * 
  * CH1PINV [9]
  * PWM-Timer 1 Output Polar Inverse Enable (PWM Timer 1 for Group A)
  * 
  * 1 = PWM1 output polar inverse Enabled.
  * 0 = PWM1 output polar inverse Disabled.
  * 
  * 
  * CH1INV [10]
  * PWM-Timer 1 Output Inverter Enable (PWM Timer 1 for Group A)
  * 
  * 1 = Inverter Enabled.
  * 0 = Inverter Disabled.
  * 
  * 
  * CH1MOD [11]
  * PWM-Timer 1 Auto-reload/One-Shot Mode (PWM Timer 1 for Group A)
  * 
  * 1 = Auto-reload mode.
  * 0 = One-shot mode.
  * 
  * Note: If there is a transition at this bit, it will cause CNR1 and CMR1 be clear.
  * 
  * 
  * CH2EN [16]
  * PWM-Timer 2 Enable (PWM timer 2 for group A)
  * 
  * 1 = Corresponding PWM-Timer Start Run Enabled.
  * 0 = Corresponding PWM-Timer Running Stopped.
  * 
  * 
  * CH2PINV [17]
  * PWM-Timer 2 Output Polar Inverse Enable (PWM Timer 2 for Group A)
  * 
  * 1 = PWM2 output polar inverse Enabled.
  * 0 = PWM2 output polar inverse Disabled.
  * 
  * 
  * CH2INV [18]
  * PWM-Timer 2 Output Inverter Enable (PWM Timer 2 for Group A)
  * 
  * 1 = Inverter Enabled.
  * 0 = Inverter Disabled.
  * 
  * 
  * CH2MOD [19]
  * PWM-Timer 2 Auto-reload/One-Shot Mode (PWM Timer 2 for Group A)
  * 
  * 1 = Auto-reload mode.
  * 0 = One-shot mode.
  * 
  * Note: If there is a transition at this bit, it will cause CNR2 and CMR2 be clear.
  * 
  * 
  * CH3EN [24]
  * PWM-Timer 3 Enable (PWM timer 3 for group A)
  * 
  * 1 = Corresponding PWM-Timer Start Run Enabled.
  * 0 = Corresponding PWM-Timer Running Stopped.
  * 
  * 
  * CH3PINV [25]
  * PWM-Timer 3 Output Polar Inverse Enable (PWM Timer 3 for Group A)
  * 
  * 1 = PWM3 output polar inverse Enabled.
  * 0 = PWM3 output polar inverse Disabled.
  * 
  * 
  * CH3INV [26]
  * PWM-Timer 3 Output Inverter Enable (PWM Timer 3 for Group A)
  * 
  * 1 = Inverter Enabled.
  * 0 = Inverter Disabled.
  * 
  * 
  * CH3MOD [27]
  * PWM-Timer 3 Auto-reload/One-Shot Mode (PWM Timer 3 for Group A)
  * 
  * 1 = Auto-reload mode.
  * 0 = One-shot mode.
  * 
  * Note: If there is a transition at this bit, it will cause CNR3 and CMR3 be clear.
  * 
  * 
  * PWMTYPE01 [30]
  * PWM01 Aligned Type Selection Bit (PWM0 and PWM1 Pair for PWM Group A)
  * 
  * 0 = Edge-aligned type.
  * 1 = Center-aligned type.
  * 
  * 
  * PWMTYPE23 [31]
  * PWM23 Aligned Type Selection Bit (PWM2 and PWM3 Pair for PWM Group A)
  * 
  * 0 = Edge-aligned type.
  * 1 = Center-aligned type.
  * 
  */

#define PWM_PCR_CH0EN_Pos                                 0
#define PWM_PCR_CH0EN_Msk                                 (0x01ul << PWM_PCR_CH0EN_Pos)
#define PWM_PCR_CH0PINV_Pos                               1
#define PWM_PCR_CH0PINV_Msk                               (0x01ul << PWM_PCR_CH0PINV_Pos)
#define PWM_PCR_CH0INV_Pos                                2
#define PWM_PCR_CH0INV_Msk                                (0x01ul << PWM_PCR_CH0INV_Pos)
#define PWM_PCR_CH0MOD_Pos                                3
#define PWM_PCR_CH0MOD_Msk                                (0x01ul << PWM_PCR_CH0MOD_Pos)
#define PWM_PCR_DZEN01_Pos                                4
#define PWM_PCR_DZEN01_Msk                                (0x01ul << PWM_PCR_DZEN01_Pos)
#define PWM_PCR_DZEN23_Pos                                5
#define PWM_PCR_DZEN23_Msk                                (0x01ul << PWM_PCR_DZEN23_Pos)
// Bits 6-7 are Reserved.
#define PWM_PCR_CH1EN_Pos                                 8
#define PWM_PCR_CH1EN_Msk                                 (0x01ul << PWM_PCR_CH1EN_Pos)
#define PWM_PCR_CH1PINV_Pos                               9
#define PWM_PCR_CH1PINV_Msk                               (0x01ul << PWM_PCR_CH1PINV_Pos)
#define PWM_PCR_CH1INV_Pos                                10
#define PWM_PCR_CH1INV_Msk                                (0x01ul << PWM_PCR_CH1INV_Pos)
#define PWM_PCR_CH1MOD_Pos                                11
#define PWM_PCR_CH1MOD_Msk                                (0x01ul << PWM_PCR_CH1MOD_Pos)
// Bits 12-15 are Reserved.
#define PWM_PCR_CH2EN_Pos                                 16
#define PWM_PCR_CH2EN_Msk                                 (0x01ul << PWM_PCR_CH2EN_Pos)
#define PWM_PCR_CH2PINV_Pos                               17
#define PWM_PCR_CH2PINV_Msk                               (0x01ul << PWM_PCR_CH2PINV_Pos)
#define PWM_PCR_CH2INV_Pos                                18
#define PWM_PCR_CH2INV_Msk                                (0x01ul << PWM_PCR_CH2INV_Pos)
#define PWM_PCR_CH2MOD_Pos                                19
#define PWM_PCR_CH2MOD_Msk                                (0x01ul << PWM_PCR_CH2MOD_Pos)
// Bits 20-23 are Reserved.
#define PWM_PCR_CH3EN_Pos                                 24
#define PWM_PCR_CH3EN_Msk                                 (0x01ul << PWM_PCR_CH3EN_Pos)
#define PWM_PCR_CH3PINV_Pos                               25
#define PWM_PCR_CH3PINV_Msk                               (0x01ul << PWM_PCR_CH3PINV_Pos)
#define PWM_PCR_CH3INV_Pos                                26
#define PWM_PCR_CH3INV_Msk                                (0x01ul << PWM_PCR_CH3INV_Pos)
#define PWM_PCR_CH3MOD_Pos                                27
#define PWM_PCR_CH3MOD_Msk                                (0x01ul << PWM_PCR_CH3MOD_Pos)
// Bits 28-29 are Reserved.
#define PWM_PCR_PWM01TYPE_Pos                             30
#define PWM_PCR_PWM01TYPE_Msk                             (0x01ul << PWM_PCR_PWM01TYPE_Pos)
#define PWM_PCR_PWM23TYPE_Pos                             31
#define PWM_PCR_PWM23TYPE_Msk                             (0x01ul << PWM_PCR_PWM23TYPE_Pos)


/**
  * @brief PWM Controller (PWM) - Register CNR [0/1/2/3]
  * 
  * @description PWM Group A Counter Register (CNR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 251-252
  * 
  * CNR0 = PWMA_BA+0x0C
  * CNR1 = PWMA_BA+0x18
  * CNR2 = PWMA_BA+0x24
  * CNR3 = PWMA_BA+0x30
  * 
  * 
  * PWM Timer Loaded Value
  * CNR determines the PWM period.
  * 
  * PWM frequency = PWMxy_CLK/[(prescale+1)*(clock divider)*(CNR+1)]
  * where xy could be 01, 23, depending on the selected PWM channel.
  * 
  * For Edge-aligned mode:
  *  - Duty ratio = (CMR+1)/(CNR+1).
  *  - CMR >= CNR: PWM output is always high.
  *  - CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit.
  *  - CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit
  * 
  * For Center-aligned mode:
  *  - Duty ratio = [(2 x CMR) + 1]/[2 x (CNR+1)].
  *  - CMR > CNR: PWM output is always high.
  *  - CMR <= CNR: PWM low width = 2 x (CNR-CMR) + 1 unit; PWM high width = (2 x CMR) + 1 unit.
  *  - CMR = 0: PWM low width = 2 x CNR + 1 unit; PWM high width = 1 unit
  * 
  * (1 Unit = one PWM clock cycle)
  * 
  * 
  * Note: Any write to CNR will take effect in the next PWM cycle.
  * Note: When CNR value is set to 0, PWM output is always high.
  * 
  * Note: When PWM operating at center-aligned type, CNR value should be set between
  * 0x0000 to 0xFFFE. If CNR equal to 0xFFFF, the PWM will work unpredictable.
  * 
  * Note: This one define should be used with the correct CNRn memory map offset from above.
  * 
  */

#define PWM_CNR_CNR_Pos                                   0
#define PWM_CNR_CNR_Msk                                   (0xFFFFul << PWM_CNR_CNR_Pos)
// Bits 16-31 are Reserved.

/**
  * @brief PWM Controller (PWM) - Register CMR [0/1/2/3]
  * 
  * @description PWM Group A Comparator Register (CMR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 253
  * 
  * CMR0 = PWMA_BA+0x10
  * CMR1 = PWMA_BA+0x1C
  * CMR2 = PWMA_BA+0x28
  * CMR3 = PWMA_BA+0x34
  * 
  * 
  * PWM Comparator Register
  * CMR determines the PWM duty.
  * 
  * PWM frequency = PWMxy_CLK/[(prescale+1)*(clock divider)*(CNR+1)]; where xy
  * could be 01, 23, 45 or 67, depending on the selected PWM channel.
  * 
  * For Edge-aligned mode:
  *  - Duty ratio = (CMR+1)/(CNR+1).
  *  - CMR >= CNR: PWM output is always high.
  *  - CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit.
  *  - CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit
  * 
  * For Center-aligned mode:
  *  - Duty ratio = [(2 x CMR) + 1]/[2 x (CNR+1)].
  *  - CMR > CNR: PWM output is always high.
  *  - CMR <= CNR: PWM low width = 2 x (CNR-CMR) + 1 unit; PWM high width = (2 x CMR) + 1 unit.
  *  - CMR = 0: PWM low width = 2 x CNR + 1 unit; PWM high width = 1 unit
  * 
  * (1 Unit = one PWM clock cycle)
  * 
  * Note: Any write to CMR will take effect in the next PWM cycle.
  * 
  * Note: This one define should be used with the correct CMRn memory map offset from above.
  * 
  */

#define PWM_CMR_CMR_Pos                                   0
#define PWM_CMR_CMR_Msk                                   (0xFFFFul << PWM_CMR_CMR_Pos)
// Bits 16-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register PDR [0/1/2/3]
  * 
  * @description PWM Group A Data Register (PDR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 254
  * 
  * PDR0 = PWMA_BA+0x14
  * PDR1 = PWMA_BA+0x20
  * PDR2 = PWMA_BA+0x2C
  * PDR3 = PWMA_BA+0x38
  * 
  * 
  * PWM Data Register
  * Software can monitor PDR to know the current value of the 16-bit down counter.
  * 
  * Note: This one define should be used with the correct PDRn memory map offset from above.
  * 
  */

#define PWM_PDR_PDR_Pos                                   0
#define PWM_PDR_PDR_Msk                                   (0xFFFFul << PWM_PDR_PDR_Pos)
// Bits 16-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register PIER
  * 
  * @description PWM Group A Interrupt Enable Register (PIER) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 255-256
  * 
  * PIER = PWMA_BA+0x40
  * 
  * 
  * PWMIE0 [0]
  * PWM Channel 0 Interrupt Enable
  * 
  * 1 = Enabled.
  * 0 = Disabled.
  * 
  * 
  * PWMIE1 [1]
  * PWM Channel 1 Interrupt Enable
  * 
  * 1 = Enabled.
  * 0 = Disabled.
  * 
  * 
  * PWMIE2 [2]
  * PWM Channel 2 Interrupt Enable
  * 
  * 1 = Enabled.
  * 0 = Disabled.
  * 
  * 
  * PWMIE3 [3]
  * PWM Channel 3 Interrupt Enable
  * 
  * 1 = Enabled.
  * 0 = Disabled.
  * 
  * 
  * PWMDIE0 [8]
  * PWM Channel 0 Duty Interrupt Enable
  * 
  * 1 = Enabled.
  * 0 = Disabled.
  * 
  * 
  * PWMDIE1 [9]
  * PWM Channel 1 Duty Interrupt Enable
  * 
  * 1 = Enabled.
  * 0 = Disabled.
  * 
  * 
  * PWMDIE2 [10]
  * PWM Channel 2 Duty Interrupt Enable
  * 
  * 1 = Enabled.
  * 0 = Disabled.
  * 
  * 
  * PWMDIE3 [11]
  * PWM Channel 3 Duty Interrupt Enable
  * 
  * 1 = Enabled.
  * 0 = Disabled.
  * 
  * 
  * INTTYPE01 [16]
  * PWM01 Interrupt Type Selection Bit (PWM0 and PWM1 Pair for PWM Group A)
  * 
  * 1 = PWMIFn will be set if PWM counter matches CNRn register.
  * 0 = PWMIFn will be set if PWM counter underflow.
  * 
  * Note: This bit is effective when PWM in central align mode only.
  * 
  * 
  * INTTYPE23 [17]
  * PWM12 Interrupt Type Selection Bit (PWM2 and PWM3 Pair for PWM Group A)
  * 
  * 1 = PWMIFn will be set if PWM counter matches CNRn register.
  * 0 = PWMIFn will be set if PWM counter underflow.
  * 
  * Note: This bit is effective when PWM in central align mode only.
  * 
  */

#define PWM_PIER_PWMIE0_Pos                               0
#define PWM_PIER_PWMIE0_Msk                               (0x01ul << PWM_PIER_PWMIE0_Pos)
#define PWM_PIER_PWMIE1_Pos                               1
#define PWM_PIER_PWMIE1_Msk                               (0x01ul << PWM_PIER_PWMIE1_Pos)
#define PWM_PIER_PWMIE2_Pos                               2
#define PWM_PIER_PWMIE2_Msk                               (0x01ul << PWM_PIER_PWMIE2_Pos)
#define PWM_PIER_PWMIE3_Pos                               3
#define PWM_PIER_PWMIE3_Msk                               (0x01ul << PWM_PIER_PWMIE3_Pos)
// Bits 4-7 are Reserved.
#define PWM_PIER_PWMDIE0_Pos                              8
#define PWM_PIER_PWMDIE0_Msk                              (0x01ul << PWM_PIER_PWMDIE0_Pos)
#define PWM_PIER_PWMDIE1_Pos                              9
#define PWM_PIER_PWMDIE1_Msk                              (0x01ul << PWM_PIER_PWMDIE1_Pos)
#define PWM_PIER_PWMDIE2_Pos                              10
#define PWM_PIER_PWMDIE2_Msk                              (0x01ul << PWM_PIER_PWMDIE2_Pos)
#define PWM_PIER_PWMDIE3_Pos                              11
#define PWM_PIER_PWMDIE3_Msk                              (0x01ul << PWM_PIER_PWMDIE3_Pos)
// Bits 12-15 are Reserved.
#define PWM_PIER_INT01TYPE_Pos                            16
#define PWM_PIER_INT01TYPE_Msk                            (0x01ul << PWM_PIER_INT01TYPE_Pos)
#define PWM_PIER_INT23TYPE_Pos                            17
#define PWM_PIER_INT23TYPE_Msk                            (0x01ul << PWM_PIER_INT23TYPE_Pos)
// Bits 18-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register PIIR
  * 
  * @description PWM Group A Interrupt Indication Register (PIIR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 257-258
  * 
  * PIIR = PWMA_BA+0x44
  * 
  * 
  * PWMIF0 [0]
  * PWM channel 0 Interrupt Status
  * 
  * This bit is set by hardware when PWM0 counter reaches the requirement of interrupt
  * (depending on INTTYPE01 bit of PIER register) if PWM0 interrupt enable bit (PWMIE0)
  * is 1, software can write 1 to clear this bit to zero.
  * 
  * 
  * PWMIF1 [1]
  * PWM channel 1 Interrupt Status
  * 
  * This bit is set by hardware when PWM1 counter reaches the requirement of interrupt
  * (depending on INTTYPE01 bit of PIER register) if PWM1 interrupt enable bit (PWMIE1)
  * is 1, software can write 1 to clear this bit to zero.
  * 
  * 
  * PWMIF2 [2]
  * PWM channel 2 Interrupt Status
  * 
  * This bit is set by hardware when PWM2 counter reaches the requirement of interrupt
  * (depending on INTTYPE23 bit of PIER register) if PWM2 interrupt enable bit (PWMIE2)
  * is 1, software can write 1 to clear this bit to zero.
  * 
  * 
  * PWMIF3 [3]
  * PWM channel 3 Interrupt Status
  * 
  * This bit is set by hardware when PWM3 counter reaches the requirement of interrupt
  * (depending on INTTYPE23 bit of PIER register) if PWM3 interrupt enable bit (PWMIE3)
  * is 1, software can write 1 to clear this bit to zero.
  * 
  * 
  * PWMDIF0 [8]
  * PWM channel 0 Duty Interrupt Flag
  * 
  * Flag is set by hardware when channel 0 PWM counter down-count and reaches CMR0.
  * Software can clear this bit by writing a 1.
  * 
  * Note: If CMR is equal to CNR, this flag will not function.
  * 
  * 
  * PWMDIF1 [9]
  * PWM channel 1 Duty Interrupt Flag
  * 
  * Flag is set by hardware when channel 1 PWM counter down-count and reaches CMR1.
  * Software can clear this bit by writing a 1.
  * 
  * Note: If CMR is equal to CNR, this flag will not function.
  * 
  * 
  * PWMDIF2 [10]
  * PWM channel 2 Duty Interrupt Flag
  * 
  * Flag is set by hardware when channel 2 PWM counter down-count and reaches CMR2.
  * Software can clear this bit by writing a 1.
  * 
  * Note: If CMR is equal to CNR, this flag will not function.
  * 
  * 
  * PWMDIF3 [11]
  * PWM channel 3 Duty Interrupt Flag
  * 
  * Flag is set by hardware when channel 3 PWM counter down-count and reaches CMR3.
  * Software can clear this bit by writing a 1.
  * 
  * Note: If CMR is equal to CNR, this flag will not function.
  * 
  */

#define PWM_PIIR_PWMIF0_Pos                               0
#define PWM_PIIR_PWMIF0_Msk                               (0x01ul << PWM_PIIR_PWMIF0_Pos)
#define PWM_PIIR_PWMIF1_Pos                               1
#define PWM_PIIR_PWMIF1_Msk                               (0x01ul << PWM_PIIR_PWMIF1_Pos)
#define PWM_PIIR_PWMIF2_Pos                               2
#define PWM_PIIR_PWMIF2_Msk                               (0x01ul << PWM_PIIR_PWMIF2_Pos)
#define PWM_PIIR_PWMIF3_Pos                               3
#define PWM_PIIR_PWMIF3_Msk                               (0x01ul << PWM_PIIR_PWMIF3_Pos)
// Bits 4-7 are Reserved.
#define PWM_PIIR_PWMDIF0_Pos                              8
#define PWM_PIIR_PWMDIF0_Msk                              (0x01ul << PWM_PIIR_PWMDIF0_Pos)
#define PWM_PIIR_PWMDIF1_Pos                              9
#define PWM_PIIR_PWMDIF1_Msk                              (0x01ul << PWM_PIIR_PWMDIF1_Pos)
#define PWM_PIIR_PWMDIF2_Pos                              10
#define PWM_PIIR_PWMDIF2_Msk                              (0x01ul << PWM_PIIR_PWMDIF2_Pos)
#define PWM_PIIR_PWMDIF3_Pos                              11
#define PWM_PIIR_PWMDIF3_Msk                              (0x01ul << PWM_PIIR_PWMDIF3_Pos)
// Bits 12-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register CCR0
  * 
  * @description PWM Group A Capture Control Register (CCR0) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 259-261
  * 
  * CCR0 = PWMA_BA+0x50
  * 
  * 
  * INV0 [0]
  * Channel 0 Inverter Enable
  * 
  * 1 = Inverter Enabled. Reverse the input signal from GPIO before fed to Capture timer
  * 0 = Inverter Disabled
  * 
  * 
  * CRL_IE0 [1]
  * Channel 0 Rising Latch Interrupt Enable
  * 
  * 1 = Rising latch interrupt Enabled.
  * 0 = Rising latch interrupt Disabled.
  * 
  * When Enabled, if capture detects PWM group channel 0 has rising transition, capture
  * issues an Interrupt.
  * 
  * 
  * CFL_IE0 [2]
  * Channel 0 Falling Latch Interrupt Enable
  * 
  * 1 = Falling latch interrupt Enabled.
  * 0 = Falling latch interrupt Disabled.
  * 
  * When Enabled, if capture detects PWM group channel 0 has falling transition, capture
  * issues an Interrupt.
  * 
  * 
  * CAPCH0EN [3]
  * Channel 0 Capture Function Enable
  * 
  * 1 = Capture function on PWM group channel 0 Enabled.
  * 0 = Capture function on PWM group channel 0 Disabled.
  * 
  * When Enabled, Capture latched the PWM-counter value and saved to CRLR (Rising
  * latch) and CFLR (Falling latch).
  * When Disabled, capture does not update CRLR and CFLR, and disable PWM group
  * channel 0 Interrupt.
  * 
  * 
  * CAPIF0 [4]
  * Channel 0 Capture Interrupt Indication Flag
  * 
  * If PWM group channel 0 rising latch interrupt is enabled (CRL_IE0=1), a rising
  * transition occurs at PWM group channel 0 will result in CAPIF0 to high.
  * A falling transition will cause CAPIF0 to be set high if PWM group channel 0 falling latch
  * interrupt is enabled (CFL_IE0=1).
  * 
  * Write 1 to clear this bit.
  * 
  * 
  * CRLRI0 [6]
  * CRLR0 Latched Indicator Bit
  * 
  * When PWM group input channel 0 has a rising transition, CRLR0 was latched with the
  * value of PWM down-counter and this bit is set by hardware.
  * Software can write 0 to clear this bit if BCn bit is 0, and can write 1 to clear this
  * bit if BCn bit is 1.
  * 
  * 
  * CFLRI0 [7]
  * CFLR0 Latched Indicator Bit
  * 
  * When PWM group input channel 0 has a falling transition, CFLR0 was latched with the
  * value of PWM down-counter and this bit is set by hardware.
  * Software can write 0 to clear this bit if BCn bit is 0, and can write 1 to clear this
  * bit if BCn bit is 1.
  * 
  * 
  * INV1 [16]
  * Channel 1 Inverter Enable
  * 
  * 1 = Inverter Enabled. Reverse the input signal from GPIO before fed to Capture timer
  * 0 = Inverter Disabled
  * 
  * 
  * CRL_IE1 [17]
  * Channel 1 Rising Latch Interrupt Enable
  * 
  * 1 = Rising latch interrupt Enabled.
  * 0 = Rising latch interrupt Disabled.
  * 
  * When Enabled, if capture detects PWM group channel 1 has rising transition, capture
  * issues an Interrupt.
  * 
  * 
  * CFL_IE1 [18]
  * Channel 1 Falling Latch Interrupt Enable
  * 
  * 1 = Falling latch interrupt Enabled.
  * 0 = Falling latch interrupt Disabled.
  * 
  * When Enabled, if capture detects PWM group channel 1 has falling transition, capture
  * issues an Interrupt.
  * 
  * 
  * CAPCH1EN [19]
  * Channel 1 Capture Function Enable
  * 
  * 1 = Capture function on PWM group channel 1 Enabled.
  * 0 = Capture function on PWM group channel 1 Disabled.
  * 
  * When Enabled, Capture latched the PWM-counter value and saved to CRLR (Rising
  * latch) and CFLR (Falling latch).
  * When Disabled, capture does not update CRLR and CFLR, and disable PWM group
  * channel 1 Interrupt.
  * 
  * 
  * CAPIF1 [20]
  * Channel 1 Capture Interrupt Indication Flag
  * 
  * If PWM group channel 1 rising latch interrupt is enabled (CRL_IE1=1), a rising
  * transition occurs at PWM group channel 1 will result in CAPIF1 to high.
  * A falling transition will cause CAPIF1 to be set high if PWM group channel 1 falling latch
  * interrupt is enabled (CFL_IE1=1).
  * 
  * Write 1 to clear this bit.
  * 
  * 
  * CRLRI1 [22]
  * CRLR1 Latched Indicator Bit
  * 
  * When PWM group input channel 1 has a rising transition, CRLR1 was latched with the
  * value of PWM down-counter and this bit is set by hardware.
  * Software can write 0 to clear this bit if BCn bit is 0, and can write 1 to clear this
  * bit if BCn bit is 1.
  * 
  * 
  * CFLRI1 [23]
  * CFLR1 Latched Indicator Bit
  * 
  * When PWM group input channel 1 has a falling transition, CFLR1 was latched with the
  * value of PWM down-counter and this bit is set by hardware.
  * Software can write 0 to clear this bit if BCn bit is 0, and can write 1 to clear this
  * bit if BCn bit is 1.
  * 
  */

#define PWM_CCR0_INV0_Pos                                 0
#define PWM_CCR0_INV0_Msk                                 (0x01ul << PWM_CCR0_INV0_Pos)
#define PWM_CCR0_CRL_IE0_Pos                              1
#define PWM_CCR0_CRL_IE0_Msk                              (0x01ul << PWM_CCR0_CRL_IE0_Pos)
#define PWM_CCR0_CFL_IE0_Pos                              2
#define PWM_CCR0_CFL_IE0_Msk                              (0x01ul << PWM_CCR0_CFL_IE0_Pos)
#define PWM_CCR0_CAPCH0EN_Pos                             3
#define PWM_CCR0_CAPCH0EN_Msk                             (0x01ul << PWM_CCR0_CAPCH0EN_Pos)
#define PWM_CCR0_CAPIF0_Pos                               4
#define PWM_CCR0_CAPIF0_Msk                               (0x01ul << PWM_CCR0_CAPIF0_Pos)
// Bit 5 is Reserved.
#define PWM_CCR0_CRLRI0_Pos                               6
#define PWM_CCR0_CRLRI0_Msk                               (0x01ul << PWM_CCR0_CRLRI0_Pos)
#define PWM_CCR0_CFLRI0_Pos                               7
#define PWM_CCR0_CFLRI0_Msk                               (0x01ul << PWM_CCR0_CFLRI0_Pos)
// Bits 8-15 are Reserved.
#define PWM_CCR0_INV1_Pos                                 16
#define PWM_CCR0_INV1_Msk                                 (0x01ul << PWM_CCR0_INV1_Pos)
#define PWM_CCR0_CRL_IE1_Pos                              17
#define PWM_CCR0_CRL_IE1_Msk                              (0x01ul << PWM_CCR0_CRL_IE1_Pos)
#define PWM_CCR0_CFL_IE1_Pos                              18
#define PWM_CCR0_CFL_IE1_Msk                              (0x01ul << PWM_CCR0_CFL_IE1_Pos)
#define PWM_CCR0_CAPCH1EN_Pos                             19
#define PWM_CCR0_CAPCH1EN_Msk                             (0x01ul << PWM_CCR0_CAPCH1EN_Pos)
#define PWM_CCR0_CAPIF1_Pos                               20
#define PWM_CCR0_CAPIF1_Msk                               (0x01ul << PWM_CCR0_CAPIF1_Pos)
// Bit 21 is Reserved.
#define PWM_CCR0_CRLRI1_Pos                               22
#define PWM_CCR0_CRLRI1_Msk                               (0x01ul << PWM_CCR0_CRLRI1_Pos)
#define PWM_CCR0_CFLRI1_Pos                               23
#define PWM_CCR0_CFLRI1_Msk                               (0x01ul << PWM_CCR0_CFLRI1_Pos)
// Bits 24-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register CCR2
  * 
  * @description PWM Group A Capture Control Register (CCR2) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 262-264
  * 
  * CCR2 = PWMA_BA+0x54
  * 
  * 
  * INV2 [0]
  * Channel 2 Inverter Enable
  * 
  * 1 = Inverter Enabled. Reverse the input signal from GPIO before fed to Capture timer
  * 0 = Inverter Disabled
  * 
  * 
  * CRL_IE2 [1]
  * Channel 2 Rising Latch Interrupt Enable
  * 
  * 1 = Rising latch interrupt Enabled.
  * 0 = Rising latch interrupt Disabled.
  * 
  * When Enabled, if capture detects PWM group channel 2 has rising transition, capture
  * issues an Interrupt.
  * 
  * 
  * CFL_IE2 [2]
  * Channel 2 Falling Latch Interrupt Enable
  * 
  * 1 = Falling latch interrupt Enabled.
  * 0 = Falling latch interrupt Disabled.
  * 
  * When Enabled, if capture detects PWM group channel 2 has falling transition, capture
  * issues an Interrupt.
  * 
  * 
  * CAPCH2EN [3]
  * Channel 2 Capture Function Enable
  * 
  * 1 = Capture function on PWM group channel 2 Enabled.
  * 0 = Capture function on PWM group channel 2 Disabled.
  * 
  * When Enabled, Capture latched the PWM-counter value and saved to CRLR (Rising
  * latch) and CFLR (Falling latch).
  * When Disabled, capture does not update CRLR and CFLR, and disable PWM group
  * channel 2 Interrupt.
  * 
  * 
  * CAPIF2 [4]
  * Channel 2 Capture Interrupt Indication Flag
  * 
  * If PWM group channel 2 rising latch interrupt is enabled (CRL_IE2=1), a rising
  * transition occurs at PWM group channel 2 will result in CAPIF2 to high.
  * A falling transition will cause CAPIF2 to be set high if PWM group channel 2 falling latch
  * interrupt is enabled (CFL_IE2=1).
  * 
  * Write 1 to clear this bit.
  * 
  * 
  * CRLRI2 [6]
  * CRLR2 Latched Indicator Bit
  * 
  * When PWM group input channel 2 has a rising transition, CRLR2 was latched with the
  * value of PWM down-counter and this bit is set by hardware.
  * Software can write 0 to clear this bit if BCn bit is 0, and can write 1 to clear this
  * bit if BCn bit is 1.
  * 
  * 
  * CFLRI2 [7]
  * CFLR2 Latched Indicator Bit
  * 
  * When PWM group input channel 2 has a falling transition, CFLR2 was latched with the
  * value of PWM down-counter and this bit is set by hardware.
  * Software can write 0 to clear this bit if BCn bit is 0, and can write 1 to clear this
  * bit if BCn bit is 1.
  * 
  * 
  * INV3 [16]
  * Channel 3 Inverter Enable
  * 
  * 1 = Inverter Enabled. Reverse the input signal from GPIO before fed to Capture timer
  * 0 = Inverter Disabled
  * 
  * 
  * CRL_IE3 [17]
  * Channel 3 Rising Latch Interrupt Enable
  * 
  * 1 = Rising latch interrupt Enabled.
  * 0 = Rising latch interrupt Disabled.
  * 
  * When Enabled, if capture detects PWM group channel 3 has rising transition, capture
  * issues an Interrupt.
  * 
  * 
  * CFL_IE3 [18]
  * Channel 3 Falling Latch Interrupt Enable
  * 
  * 1 = Falling latch interrupt Enabled.
  * 0 = Falling latch interrupt Disabled.
  * 
  * When Enabled, if capture detects PWM group channel 3 has falling transition, capture
  * issues an Interrupt.
  * 
  * 
  * CAPCH3EN [19]
  * Channel 3 Capture Function Enable
  * 
  * 1 = Capture function on PWM group channel 3 Enabled.
  * 0 = Capture function on PWM group channel 3 Disabled.
  * 
  * When Enabled, Capture latched the PWM-counter value and saved to CRLR (Rising
  * latch) and CFLR (Falling latch).
  * When Disabled, capture does not update CRLR and CFLR, and disable PWM group
  * channel 3 Interrupt.
  * 
  * 
  * CAPIF3 [20]
  * Channel 3 Capture Interrupt Indication Flag
  * 
  * If PWM group channel 3 rising latch interrupt is enabled (CRL_IE3=1), a rising
  * transition occurs at PWM group channel 3 will result in CAPIF3 to high.
  * A falling transition will cause CAPIF3 to be set high if PWM group channel 3 falling latch
  * interrupt is enabled (CFL_IE3=1).
  * 
  * Write 1 to clear this bit.
  * 
  * 
  * CRLRI3 [22]
  * CRLR3 Latched Indicator Bit
  * 
  * When PWM group input channel 3 has a rising transition, CRLR3 was latched with the
  * value of PWM down-counter and this bit is set by hardware.
  * Software can write 0 to clear this bit if BCn bit is 0, and can write 1 to clear this
  * bit if BCn bit is 1.
  * 
  * 
  * CFLRI3 [23]
  * CFLR3 Latched Indicator Bit
  * 
  * When PWM group input channel 3 has a falling transition, CFLR3 was latched with the
  * value of PWM down-counter and this bit is set by hardware.
  * Software can write 0 to clear this bit if BCn bit is 0, and can write 1 to clear this
  * bit if BCn bit is 1.
  * 
  */

#define PWM_CCR2_INV2_Pos                                 0
#define PWM_CCR2_INV2_Msk                                 (0x01ul << PWM_CCR2_INV2_Pos)
#define PWM_CCR2_CRL_IE2_Pos                              1
#define PWM_CCR2_CRL_IE2_Msk                              (0x01ul << PWM_CCR2_CRL_IE2_Pos)
#define PWM_CCR2_CFL_IE2_Pos                              2
#define PWM_CCR2_CFL_IE2_Msk                              (0x01ul << PWM_CCR2_CFL_IE2_Pos)
#define PWM_CCR2_CAPCH2EN_Pos                             3
#define PWM_CCR2_CAPCH2EN_Msk                             (0x01ul << PWM_CCR2_CAPCH2EN_Pos)
#define PWM_CCR2_CAPIF2_Pos                               4
#define PWM_CCR2_CAPIF2_Msk                               (0x01ul << PWM_CCR2_CAPIF2_Pos)
// Bit 5 is Reserved.
#define PWM_CCR2_CRLRI2_Pos                               6
#define PWM_CCR2_CRLRI2_Msk                               (0x01ul << PWM_CCR2_CRLRI2_Pos)
#define PWM_CCR2_CFLRI2_Pos                               7
#define PWM_CCR2_CFLRI2_Msk                               (0x01ul << PWM_CCR2_CFLRI2_Pos)
// Bits 8-15 are Reserved.
#define PWM_CCR2_INV3_Pos                                 16
#define PWM_CCR2_INV3_Msk                                 (0x01ul << PWM_CCR2_INV3_Pos)
#define PWM_CCR2_CRL_IE3_Pos                              17
#define PWM_CCR2_CRL_IE3_Msk                              (0x01ul << PWM_CCR2_CRL_IE3_Pos)
#define PWM_CCR2_CFL_IE3_Pos                              18
#define PWM_CCR2_CFL_IE3_Msk                              (0x01ul << PWM_CCR2_CFL_IE3_Pos)
#define PWM_CCR2_CAPCH3EN_Pos                             19
#define PWM_CCR2_CAPCH3EN_Msk                             (0x01ul << PWM_CCR2_CAPCH3EN_Pos)
#define PWM_CCR2_CAPIF3_Pos                               20
#define PWM_CCR2_CAPIF3_Msk                               (0x01ul << PWM_CCR2_CAPIF3_Pos)
// Bit 21 is Reserved.
#define PWM_CCR2_CRLRI3_Pos                               22
#define PWM_CCR2_CRLRI3_Msk                               (0x01ul << PWM_CCR2_CRLRI3_Pos)
#define PWM_CCR2_CFLRI3_Pos                               23
#define PWM_CCR2_CFLRI3_Msk                               (0x01ul << PWM_CCR2_CFLRI3_Pos)
// Bits 24-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register CRLR [0/1/2/3]
  * 
  * @description PWM Group A Capture Rising Latch Register (CRLR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 265
  * 
  * CRLR0 = PWMA_BA+0x58
  * CRLR1 = PWMA_BA+0x60
  * CRLR2 = PWMA_BA+0x68
  * CRLR3 = PWMA_BA+0x70
  * 
  * 
  * Capture Rising Latch Register
  * Latch the PWM counter when Channel 0/1/2/3 has a Rising transition.
  * 
  * Note: This one define should be used with the correct CRLRn memory map offset from above.
  * 
  */

#define PWM_CRLR_CRLR_Pos                                 0
#define PWM_CRLR_CRLR_Msk                                 (0xFFFFul << PWM_CRLR_CRLR_Pos)
// Bits 16-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register CFLR [0/1/2/3]
  * 
  * @description PWM Group A Capture Falling Latch Register (CFLR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 266
  * 
  * CFLR0 = PWMA_BA+0x5C
  * CFLR1 = PWMA_BA+0x64
  * CFLR2 = PWMA_BA+0x6C
  * CFLR3 = PWMA_BA+0x74
  * 
  * 
  * Capture Falling Latch Register
  * Latch the PWM counter when Channel 0/1/2/3 has a Falling transition.
  * 
  * Note: This one define should be used with the correct CFLRn memory map offset from above.
  * 
  */

#define PWM_CFLR_CFLR_Pos                                 0
#define PWM_CFLR_CFLR_Msk                                 (0xFFFFul << PWM_CFLR_CFLR_Pos)
// Bits 16-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register CAPENR
  * 
  * @description PWM Group A Capture Input Enable Register (CAPENR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 267
  * 
  * CAPENR = PWMA_BA+0x78
  * 
  * 
  * Capture Input Enable Register
  * 
  * There are four capture inputs from pad. Bit0~Bit3 are used to control each input enable
  * or disable.
  * 
  * 0 = Disabled (PWMx multi-function pin input does not affect input capture function.)
  * 1 = Enabled (PWMx multi-function pin input will affect its input capture function.)
  * 
  * Bit 3210 for PWM group A
  * Bit xxx1 -> Capture channel 0 is from pin PA.12
  * Bit xx1x -> Capture channel 1 is from pin PA.13
  * Bit x1xx -> Capture channel 2 is from pin PA.14
  * Bit 1xxx -> Capture channel 3 is from pin PA.15
  * 
  */

#define PWM_CAPENR_CAPENR_Pos                             0
#define PWM_CAPENR_CAPENR_Msk                             (0x0Ful << PWM_CAPENR_CAPENR_Pos)
// Bits 4-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register POE
  * 
  * @description PWM Group A Output Enable Register (POE) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 268
  * 
  * POE = PWMA_BA+0x7C
  * 
  * 
  * PWM0 [0]
  * Channel 0 Output Enable Register
  * 
  * 1 = PWM channel 0 output to pin Enabled.
  * 0 = PWM channel 0 output to pin Disabled.
  * 
  * 
  * PWM1 [1]
  * Channel 1 Output Enable Register
  * 
  * 1 = PWM channel 1 output to pin Enabled.
  * 0 = PWM channel 1 output to pin Disabled.
  * 
  * 
  * PWM2 [2]
  * Channel 2 Output Enable Register
  * 
  * 1 = PWM channel 2 output to pin Enabled.
  * 0 = PWM channel 2 output to pin Disabled.
  * 
  * 
  * PWM3 [3]
  * Channel 3 Output Enable Register
  * 
  * 1 = PWM channel 3 output to pin Enabled.
  * 0 = PWM channel 3 output to pin Disabled.
  * 
  * Note: The corresponding GPIO pin must also be switched to PWM function for
  * each needed PWM channel.
  * 
  */

#define PWM_POE_PWM0_Pos                                  0
#define PWM_POE_PWM0_Msk                                  (0x01ul << PWM_POE_PWM0_Pos)
#define PWM_POE_PWM1_Pos                                  1
#define PWM_POE_PWM1_Msk                                  (0x01ul << PWM_POE_PWM1_Pos)
#define PWM_POE_PWM2_Pos                                  2
#define PWM_POE_PWM2_Msk                                  (0x01ul << PWM_POE_PWM2_Pos)
#define PWM_POE_PWM3_Pos                                  3
#define PWM_POE_PWM3_Msk                                  (0x01ul << PWM_POE_PWM3_Pos)
// Bits 4-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register TCON
  * 
  * @description PWM Group A Trigger Control Register (TCON) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 269-270
  * 
  * TCON = PWMA_BA+0x80
  * 
  * 
  * PWM0TEN [0]
  * Channel 0 Center-Aligned Trigger Enable Register
  * 
  * 1 = PWM channel 0 trigger ADC function Enabled.
  * 0 = PWM channel 0 trigger ADC function Disabled.
  * 
  * PWM can trigger ADC to start conversion when PWM counter counts up to CNR
  * if this bit is set to 1.
  * 
  * 
  * PWM1TEN [1]
  * Channel 1 Center-Aligned Trigger Enable Register
  * 
  * 1 = PWM channel 1 trigger ADC function Enabled.
  * 0 = PWM channel 1 trigger ADC function Disabled.
  * 
  * PWM can trigger ADC to start conversion when PWM counter counts up to CNR
  * if this bit is set to 1.
  * 
  * 
  * PWM2TEN [2]
  * Channel 2 Center-Aligned Trigger Enable Register
  * 
  * 1 = PWM channel 2 trigger ADC function Enabled.
  * 0 = PWM channel 2 trigger ADC function Disabled.
  * 
  * PWM can trigger ADC to start conversion when PWM counter counts up to CNR
  * if this bit is set to 1.
  * 
  * 
  * PWM3TEN [3]
  * Channel 3 Center-Aligned Trigger Enable Register
  * 
  * 1 = PWM channel 3 trigger ADC function Enabled.
  * 0 = PWM channel 3 trigger ADC function Disabled.
  * 
  * PWM can trigger ADC to start conversion when PWM counter counts up to CNR
  * if this bit is set to 1.
  * 
  * 
  * Note: These functions are only supported when the relevant PWM is operating in
  * Center-aligned mode.
  * 
  */

#define PWM_TCON_PWM0TEN_Pos                              0
#define PWM_TCON_PWM0TEN_Msk                              (0x01ul << PWM_TCON_PWM0TEN_Pos)
#define PWM_TCON_PWM1TEN_Pos                              1
#define PWM_TCON_PWM1TEN_Msk                              (0x01ul << PWM_TCON_PWM1TEN_Pos)
#define PWM_TCON_PWM2TEN_Pos                              2
#define PWM_TCON_PWM2TEN_Msk                              (0x01ul << PWM_TCON_PWM2TEN_Pos)
#define PWM_TCON_PWM3TEN_Pos                              3
#define PWM_TCON_PWM3TEN_Msk                              (0x01ul << PWM_TCON_PWM3TEN_Pos)
// Bits 4-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register TSTATUS
  * 
  * @description PWM Group A Trigger Status Register (TSTATUS) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 271
  * 
  * TSTATUS = PWMA_BA+0x84
  * 
  * 
  * PWM0TF [0]
  * Channel 0 Center-aligned Trigger Flag
  * 
  * For Center-aligned operating mode, this bit is set to 1 by hardware when PWM
  * counter up count to CNR if PWM0TEN bit is set to 1. After this bit is set to 1, ADC
  * will start conversion if ADC triggered source is selected by PWM.
  * 
  * 
  * PWM1TF [1]
  * Channel 1 Center-aligned Trigger Flag
  * 
  * For Center-aligned operating mode, this bit is set to 1 by hardware when PWM
  * counter up count to CNR if PWM1TEN bit is set to 1. After this bit is set to 1, ADC
  * will start conversion if ADC triggered source is selected by PWM.
  * 
  * 
  * PWM2TF [2]
  * Channel 2 Center-aligned Trigger Flag
  * 
  * For Center-aligned operating mode, this bit is set to 1 by hardware when PWM
  * counter up count to CNR if PWM2TEN bit is set to 1. After this bit is set to 1, ADC
  * will start conversion if ADC triggered source is selected by PWM.
  * 
  * 
  * PWM3TF [3]
  * Channel 3 Center-aligned Trigger Flag
  * 
  * For Center-aligned operating mode, this bit is set to 1 by hardware when PWM
  * counter up count to CNR if PWM3TEN bit is set to 1. After this bit is set to 1, ADC
  * will start conversion if ADC triggered source is selected by PWM.
  * 
  * 
  * Software can write 1 to each of these bits to clear.
  * 
  */

#define PWM_TSTATUS_PWM0TF_Pos                            0
#define PWM_TSTATUS_PWM0TF_Msk                            (0x01ul << PWM_TSTATUS_PWM0TF_Pos)
#define PWM_TSTATUS_PWM1TF_Pos                            1
#define PWM_TSTATUS_PWM1TF_Msk                            (0x01ul << PWM_TSTATUS_PWM1TF_Pos)
#define PWM_TSTATUS_PWM2TF_Pos                            2
#define PWM_TSTATUS_PWM2TF_Msk                            (0x01ul << PWM_TSTATUS_PWM2TF_Pos)
#define PWM_TSTATUS_PWM3TF_Pos                            3
#define PWM_TSTATUS_PWM3TF_Msk                            (0x01ul << PWM_TSTATUS_PWM3TF_Pos)
// Bits 4-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register SYNCBUSY0
  * 
  * @description PWM Group A PWM0 Sync Busy Status Register (SYNCBUSY0) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 272
  * 
  * SYNCBUSY0 = PWMA_BA+0x88
  * 
  * 
  * PWM Synchronous Busy
  * 
  * When software writes CNR0/CMR0/PPR or switch PWM0 operation mode
  * (PCR[3]), PWM will have a busy time to update these values completely because
  * PWM clock may be different from system clock domain. Software needs to check
  * this busy status before writes CNR0/CMR0/PPR or switch PWM0 operation mode
  * (PCR[3]) to make sure previous setting has been update completely.
  * 
  * This bit will be set when software write CNR0/CMR0/PPR or switch PWM0
  * operation mode (PCR[3]) and will be cleared by hardware automatically when
  * PWM update these value completely.
  * 
  */

#define PWM_SYNCBUSY0_S_BUSY_Pos                          0
#define PWM_SYNCBUSY0_S_BUSY_Msk                          (0x01ul << PWM_SYNCBUSY0_S_BUSY_Pos)


/**
  * @brief PWM Controller (PWM) - Register SYNCBUSY1
  * 
  * @description PWM Group A PWM1 Sync Busy Status Register (SYNCBUSY1) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 273
  * 
  * SYNCBUSY1 = PWMA_BA+0x8C
  * 
  * 
  * PWM Synchronous Busy
  * 
  * When software writes CNR1/CMR1/PPR or switch PWM1 operation mode
  * (PCR[11]), PWM will have a busy time to update these values completely because
  * PWM clock may be different from system clock domain. Software needs to check
  * this busy status before writes CNR1/CMR1/PPR or switch PWM1 operation mode
  * (PCR[11]) to make sure previous setting has been update completely.
  * 
  * This bit will be set when software write CNR1/CMR1/PPR or switch PWM1
  * operation mode (PCR[11]) and will be cleared by hardware automatically when
  * PWM update these value completely.
  * 
  */

#define PWM_SYNCBUSY1_S_BUSY_Pos                          0
#define PWM_SYNCBUSY1_S_BUSY_Msk                          (0x01ul << PWM_SYNCBUSY1_S_BUSY_Pos)


/**
  * @brief PWM Controller (PWM) - Register SYNCBUSY2
  * 
  * @description PWM Group A PWM2 Sync Busy Status Register (SYNCBUSY2) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 274
  * 
  * SYNCBUSY2 = PWMA_BA+0x90
  * 
  * 
  * PWM Synchronous Busy
  * 
  * When software writes CNR2/CMR2/PPR or switch PWM2 operation mode
  * (PCR[19]), PWM will have a busy time to update these values completely because
  * PWM clock may be different from system clock domain. Software needs to check
  * this busy status before writes CNR2/CMR2/PPR or switch PWM2 operation mode
  * (PCR[19]) to make sure previous setting has been update completely.
  * 
  * This bit will be set when software write CNR2/CMR2/PPR or switch PWM2
  * operation mode (PCR[19]) and will be cleared by hardware automatically when
  * PWM update these value completely.
  * 
  */

#define PWM_SYNCBUSY2_S_BUSY_Pos                          0
#define PWM_SYNCBUSY2_S_BUSY_Msk                          (0x01ul << PWM_SYNCBUSY2_S_BUSY_Pos)


/**
  * @brief PWM Controller (PWM) - Register SYNCBUSY3
  * 
  * @description PWM Group A PWM3 Sync Busy Status Register (SYNCBUSY3) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 275
  * 
  * SYNCBUSY3 = PWMA_BA+0x94
  * 
  * 
  * PWM Synchronous Busy
  * 
  * When software writes CNR3/CMR3/PPR or switch PWM3 operation mode
  * (PCR[27]), PWM will have a busy time to update these values completely because
  * PWM clock may be different from system clock domain. Software needs to check
  * this busy status before writes CNR3/CMR3/PPR or switch PWM3 operation mode
  * (PCR[27]) to make sure previous setting has been update completely.
  * 
  * This bit will be set when software write CNR3/CMR3PPR or switch PWM3
  * operation mode (PCR[27]) and will be cleared by hardware automatically when
  * PWM update these value completely.
  * 
  */

#define PWM_SYNCBUSY3_S_BUSY_Pos                          0
#define PWM_SYNCBUSY3_S_BUSY_Msk                          (0x01ul << PWM_SYNCBUSY3_S_BUSY_Pos)


/**
  * @brief PWM Controller (PWM) - Register CAPPDMACTL
  * 
  * @description PWM Group A PDMA Control Register (CAPPDMACTL) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 276-277
  * 
  * CAPPDMACTL = PWMA_BA+0xC0
  * 
  * 
  * CAP0PDMAEN [0]
  * Channel 0 PDMA Enable
  * 
  * 1 = Channel 0 PDMA function Enabled for the channel 0 captured data and
  *     transfer to memory.
  * 0 = Channel 0 PDMA function Disabled.
  * 
  * 
  * CAP0PDMAMOD [1:2]
  * Select CRLR0 or CFLR0 to Transfer PDMA
  * 
  * 00 = Reserved
  * 01 = CFLR0
  * 10 = CRLR0
  * 11 = Both CRLR0 and CFLR0
  * 
  * 
  * CAP0RFORDER [3]
  * Set this bit to determine whether the CRLR0 or CFLR0 is the first captured
  * data transferred to memory through PDMA when CAP0PDMAMOD =11
  * 
  * 1 = CRLR0 is the first captured data to memory.
  * 0 = CFLR0 is the first captured data to memory.
  * 
  * 
  * CAP1PDMAEN [8]
  * Channel 1 PDMA Enable
  * 
  * 1 = Channel 1 PDMA function Enabled for the channel 1 captured data and
  *     transfer to memory.
  * 0 = Channel 1 PDMA function Disabled.
  * 
  * 
  * CAP1PDMAMOD [9:10]
  * Select CRLR1 or CFLR1 to Transfer PDMA
  * 
  * 00 = Reserved
  * 01 = CFLR1
  * 10 = CRLR1
  * 11 = Both CRLR1 and CFLR1
  * 
  * 
  * CAP1RFORDER [11]
  * Set this bit to determine whether the CRLR1 or CFLR1 is the first captured
  * data transferred to memory through PDMA when CAP1PDMAMOD =11
  * 
  * 1 = CRLR1 is the first captured data to memory.
  * 0 = CFLR1 is the first captured data to memory.
  * 
  * 
  * CAP2PDMAEN [16]
  * Channel 2 PDMA Enable
  * 
  * 1 = Channel 2 PDMA function Enabled for the channel 2 captured data and
  *     transfer to memory.
  * 0 = Channel 2 PDMA function Disabled.
  * 
  * 
  * CAP2PDMAMOD [17:18]
  * Select CRLR2 or CFLR2 to Transfer PDMA
  * 
  * 00 = Reserved
  * 01 = CFLR2
  * 10 = CRLR2
  * 11 = Both CRLR2 and CFLR2
  * 
  * 
  * CAP2RFORDER [19]
  * Set this bit to determine whether the CRLR2 or CFLR2 is the first captured
  * data transferred to memory through PDMA when CAP2PDMAMOD =11
  * 
  * 1 = CRLR2 is the first captured data to memory.
  * 0 = CFLR2 is the first captured data to memory.
  * 
  * 
  * CAP3PDMAEN [24]
  * Channel 3 PDMA Enable
  * 
  * 1 = Channel 3 PDMA function Enabled for the channel 3 captured data and
  *     transfer to memory.
  * 0 = Channel 3 PDMA function Disabled.
  * 
  * 
  * CAP3PDMAMOD [25:26]
  * Select CRLR3 or CFLR3 to Transfer PDMA
  * 
  * 00 = Reserved
  * 01 = CFLR3
  * 10 = CRLR3
  * 11 = Both CRLR3 and CFLR3
  * 
  * 
  * CAP3RFORDER [3]
  * Set this bit to determine whether the CRLR3 or CFLR3 is the first captured
  * data transferred to memory through PDMA when CAP3PDMAMOD =11
  * 
  * 1 = CRLR3 is the first captured data to memory.
  * 0 = CFLR3 is the first captured data to memory.
  * 
  */

/* PWM CAPPDMACTL Bit Field Definitions */
#define PWM_CAPPDMACTL_CAP0PDMAEN_Pos                     0
#define PWM_CAPPDMACTL_CAP0PDMAEN_Msk                     (0x01ul << PWM_CAPPDMACTL_CAP0PDMAEN_Pos)
#define PWM_CAPPDMACTL_CAP0PDMAMOD_Pos                    1
#define PWM_CAPPDMACTL_CAP0PDMAMOD_Msk                    (0x03ul << PWM_CAPPDMACTL_CAP0PDMAMOD_Pos)
#define PWM_CAPPDMACTL_CAP0RFORDER_Pos                    3
#define PWM_CAPPDMACTL_CAP0RFORDER_Msk                    (0x01ul << PWM_CAPPDMACTL_CAP0RFORDER_Pos)
// Bits 4-7 are Reserved.
#define PWM_CAPPDMACTL_CAP1PDMAEN_Pos                     8
#define PWM_CAPPDMACTL_CAP1PDMAEN_Msk                     (0x01ul << PWM_CAPPDMACTL_CAP1PDMAEN_Pos)
#define PWM_CAPPDMACTL_CAP1PDMAMOD_Pos                    9
#define PWM_CAPPDMACTL_CAP1PDMAMOD_Msk                    (0x03ul << PWM_CAPPDMACTL_CAP1PDMAMOD_Pos)
#define PWM_CAPPDMACTL_CAP1RFORDER_Pos                    11
#define PWM_CAPPDMACTL_CAP1RFORDER_Msk                    (0x01ul << PWM_CAPPDMACTL_CAP1RFORDER_Pos)
// Bits 12-15 are Reserved.
#define PWM_CAPPDMACTL_CAP2PDMAEN_Pos                     16
#define PWM_CAPPDMACTL_CAP2PDMAEN_Msk                     (0x01ul << PWM_CAPPDMACTL_CAP2PDMAEN_Pos)
#define PWM_CAPPDMACTL_CAP2PDMAMOD_Pos                    17
#define PWM_CAPPDMACTL_CAP2PDMAMOD_Msk                    (0x03ul << PWM_CAPPDMACTL_CAP2PDMAMOD_Pos)
#define PWM_CAPPDMACTL_CAP2RFORDER_Pos                    19
#define PWM_CAPPDMACTL_CAP2RFORDER_Msk                    (0x01ul << PWM_CAPPDMACTL_CAP2RFORDER_Pos)
// Bits 20-23 are Reserved.
#define PWM_CAPPDMACTL_CAP3PDMAEN_Pos                     24
#define PWM_CAPPDMACTL_CAP3PDMAEN_Msk                     (0x01ul << PWM_CAPPDMACTL_CAP3PDMAEN_Pos)
#define PWM_CAPPDMACTL_CAP3PDMAMOD_Pos                    25
#define PWM_CAPPDMACTL_CAP3PDMAMOD_Msk                    (0x03ul << PWM_CAPPDMACTL_CAP3PDMAMOD_Pos)
#define PWM_CAPPDMACTL_CAP3RFORDER_Pos                    27
#define PWM_CAPPDMACTL_CAP3RFORDER_Msk                    (0x01ul << PWM_CAPPDMACTL_CAP3RFORDER_Pos)
// Bits 28-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register CAP0PDMA
  * 
  * @description PWM Group A PDMA Data Register0 (CAP0PDMA) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 278
  * 
  * CAP0PDMA = PWMA_BA+0xC4
  * 
  * 
  * CAP0RFPDMA
  * PDMA data register for channel 0
  * This is the capture value (CFLR0/CRLR0) for channel 0
  * 
  */

#define PWM_CAP0PDMA_CAP0RFPDMA_Pos                       0
#define PWM_CAP0PDMA_CAP0RFPDMA_Msk                       (0xFFFFul << PWM_CAP0PDMA_CAP0RFPDMA_Pos)
// Bits 16-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register CAP1PDMA
  * 
  * @description PWM Group A PDMA Data Register1 (CAP1PDMA) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 279
  * 
  * CAP1PDMA = PWMA_BA+0xC8
  * 
  * 
  * CAP1RFPDMA
  * PDMA data register for channel 1
  * This is the capture value (CFLR1/CRLR1) for channel 1
  * 
  */

#define PWM_CAP1PDMA_CAP1RFPDMA_Pos                       0
#define PWM_CAP1PDMA_CAP1RFPDMA_Msk                       (0xFFFFul << PWM_CAP1PDMA_CAP1RFPDMA_Pos)
// Bits 16-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register CAP2PDMA
  * 
  * @description PWM Group A PDMA Data Register2 (CAP2PDMA) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 280
  * 
  * CAP2PDMA = PWMA_BA+0xCC
  * 
  * 
  * CAP2RFPDMA
  * PDMA data register for channel 2
  * This is the capture value (CFLR2/CRLR2) for channel 2
  * 
  */

#define PWM_CAP2PDMA_CAP2RFPDMA_Pos                       0
#define PWM_CAP2PDMA_CAP2RFPDMA_Msk                       (0xFFFFul << PWM_CAP2PDMA_CAP2RFPDMA_Pos)
// Bits 16-31 are Reserved.


/**
  * @brief PWM Controller (PWM) - Register CAP3PDMA
  * 
  * @description PWM Group A PDMA Data Register3 (CAP3PDMA) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.9.6 Register Description, page 281
  * 
  * CAP3PDMA = PWMA_BA+0xD0
  * 
  * 
  * CAP3RFPDMA
  * PDMA data register for channel 3
  * This is the capture value (CFLR3/CRLR3) for channel 3
  * 
  */

#define PWM_CAP3PDMA_CAP3RFPDMA_Pos                       0
#define PWM_CAP3PDMA_CAP3RFPDMA_Msk                       (0xFFFFul << PWM_CAP3PDMA_CAP3RFPDMA_Pos)
// Bits 16-31 are Reserved.


/* PWM-Timer Start Procedure
The following procedure is recommended for starting a PWM drive:
1. Set clock selector (CSR)
2. Set prescaler (PPR)
3. Set inverter on/off, dead-zone generator on/off, auto-reload/one-shot mode and stop
PWM-timer (PCR)
4. Set comparator register (CMR) for setting PWM duty.
5. Set PWM down-counter register (CNR) for setting PWM period.
6. Set interrupt enable register (PIER)
7. Set the corresponding GPIO pins as PWM function (enable POE and disable CAPENR)
for the corresponding PWM channel.
8. Enable PWM timer start running (set CHxEN = 1 in PCR)
 */



/* =========================================================================================================================== */
/* ================                                    TIMER Controller                                       ================ */
/* =========================================================================================================================== */


/**
  * @brief TIMER Controller (TIMER)
  * 
  * @description See NUC123 Technical Reference Manual 5.11.5 Register Map, page 325-326
  * 
  * TMR_BA01 = 0x4001_0000
  * TMR_BA23 = 0x4011_0000
  * 
  * Struct rearranged from table to track actual locations (without having to specify offsets)
  * 
  * TIMER_T Struct is per-TMR pair (TMR01, TMR23).
  * 
  */

typedef struct {

    __IO uint32_t TCSR;          // TMR_BAxx + 0x00                       Timer Control and Status Register
    __IO uint32_t TCMPR;         // TMR_BAxx + 0x04                       Timer Compare Register
    __IO uint32_t TISR;          // TMR_BAxx + 0x08                       Timer Interrupt Status Register
    __I  uint32_t TDR;           // TMR_BAxx + 0x0C                       Timer Data Register
    __I  uint32_t TCAP;          // TMR_BAxx + 0x10                       Timer Capture Data Register
    __IO uint32_t TEXCON;        // TMR_BAxx + 0x14                       Timer External Control Register
    __IO uint32_t TEXISR;        // TMR_BAxx + 0x18                       Timer External Interrupt Status Register

} TIMER_T;


/**
  * @brief TIMER Controller (TIMER) - Register TCSR
  * 
  * @description TIMER [0/1/2/3] Timer Control and Status Register (TCSR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.11.6 Register Description, page 327-329
  * 
  * TCSR0 = TMR_BA01+0x00
  * TCSR1 = TMR_BA01+0x20
  * TCSR2 = TMR_BA23+0x00
  * TCSR3 = TMR_BA23+0x20
  * 
  * 
  * PRESCALE [0:7]
  * Pre-scale Counter
  * 
  * Clock input is divided by PRESCALE+1 before it is fed to the counter.
  * If PRESCALE = 0, there is no scaling.
  * 
  * 
  * TDR_EN [16]
  * Data Load Enable
  * 
  * When TDR_EN is set, TDR (Timer Data Register) will be updated continuously with the
  * 24-bit up-timer value as the timer is counting.
  * 
  * 1 = Timer Data Register update Enabled.
  * 0 = Timer Data Register update Disabled.
  * 
  * 
  * WAKEN [23]
  * Wake-up Enable
  * 
  * When WAKE_EN is set and the TIF is set, the timer controller will generator a wake-up
  * trigger event to CPU.
  * 
  * 0 = Wake-up trigger event Disabled.
  * 1 = Wake-up trigger event Enabled.
  * 
  * 
  * CTB [24]
  * Counter Mode Enable Bit
  * 
  * This bit is the counter mode enable bit. When Timer is used as an event counter, this
  * bit should be set to 1 and Timer will work as an event counter. The counter detect
  * phase can be selected as rising/falling edge of external pin by TX_PHASE field.
  * 
  * 1 = Counter mode Enabled.
  * 0 = Counter mode Disabled.
  * 
  * 
  * CACT [25]
  * Timer Active Status Bit (Read only)
  * 
  * This bit indicates the up-timer status.
  * 
  * 0 = Timer is not active
  * 1 = Timer is active
  * 
  * 
  * CRST [26]
  * Timer Reset Bit
  * 
  * Set this bit will reset the 24-bit up-timer, 8-bit pre-scale counter and also force CEN
  * to 0.
  * 
  * 0 = No effect
  * 1 = Reset Timer's 8-bit pre-scale counter, internal 24-bit up-timer and CEN bit
  * 
  * 
  * MODE [27:28]
  * Timer Operating Mode
  * 
  * 00 = The timer is operating at the one-shot mode. The associated
  *      interrupt signal is generated once (if IE is enabled) and CEN is
  *      automatically cleared by hardware.
  * 01 = The timer is operating at the periodic mode. The associated
  *      interrupt signal is generated periodically (if IE is enabled).
  * 10 = The timer is operating at the toggle mode. The interrupt signal is
  *      generated periodically (if IE is enabled). And the associated
  *      signal (tout) is changing back and forth with 50% duty cycle.
  * 11 = The timer is operating at continuous counting mode. The
  *      associated interrupt signal is generated when TDR = TCMPR (if
  *      IE is enabled). However, the 24-bit up-timer counts continuously.
  * 
  * 
  * IE [29]
  * Interrupt Enable Bit
  * 
  * 1 = Timer Interrupt Enabled
  * 0 = Timer Interrupt Disabled
  * 
  * If timer interrupt is enabled, the timer asserts its interrupt signal when the associated
  * up-timer value is equal to TCMPR.
  * 
  * 
  * CEN [30]
  * Timer Enable Bit
  * 
  * 1 = Starts counting
  * 0 = Stops/Suspends counting
  * 
  * Note1: If CEN is in stop and then CEN is set to 1, the 24-bit up-timer will keep
  * counting up from the last stop counting value.
  * Note2: This bit is auto-cleared by hardware in one-shot mode (MODE [27:28] = 00)
  * when the associated timer interrupt is generated (IE [29] = 1).
  * 
  * 
  * DBGACK_TMR [31]
  * ICE Debug mode Acknowledge Disable (Write-protection Bit)
  * 
  * 0 = ICE debug mode acknowledgement effects TIMER counting.
  *     TIMER counter will be held while ICE debug mode acknowledged.
  * 1 = ICE debug mode acknowledgement disabled.
  *     TIMER counter will keep going regardless of ICE debug mode acknowledgement.
  * 
  */

#define TIMER_TCSR_PRESCALE_Pos                           0
#define TIMER_TCSR_PRESCALE_Msk                           (0xFFul << TIMER_TCSR_PRESCALE_Pos)
// Bits 8-15 are Reserved.
#define TIMER_TCSR_TDR_EN_Pos                             16
#define TIMER_TCSR_TDR_EN_Msk                             (0x01ul << TIMER_TCSR_TDR_EN_Pos)
// Bits 17-22 are Reserved.
#define TIMER_TCSR_WAKE_EN_Pos                            23
#define TIMER_TCSR_WAKE_EN_Msk                            (0x01ul << TIMER_TCSR_WAKE_EN_Pos)
#define TIMER_TCSR_CTB_Pos                                24
#define TIMER_TCSR_CTB_Msk                                (0x01ul << TIMER_TCSR_CTB_Pos)
#define TIMER_TCSR_CACT_Pos                               25
#define TIMER_TCSR_CACT_Msk                               (0x01ul << TIMER_TCSR_CACT_Pos)
#define TIMER_TCSR_CRST_Pos                               26
#define TIMER_TCSR_CRST_Msk                               (0x01ul << TIMER_TCSR_CRST_Pos)
#define TIMER_TCSR_MODE_Pos                               27
#define TIMER_TCSR_MODE_Msk                               (0x03ul << TIMER_TCSR_MODE_Pos)
#define TIMER_TCSR_IE_Pos                                 29
#define TIMER_TCSR_IE_Msk                                 (0x01ul << TIMER_TCSR_IE_Pos)
#define TIMER_TCSR_CEN_Pos                                30
#define TIMER_TCSR_CEN_Msk                                (0x01ul << TIMER_TCSR_CEN_Pos)
#define TIMER_TCSR_DBGACK_TMR_Pos                         31
#define TIMER_TCSR_DBGACK_TMR_Msk                         (0x01ul << TIMER_TCSR_DBGACK_TMR_Pos)


/**
  * @brief TIMER Controller (TIMER) - Register TCMP
  * 
  * @description TIMER [0/1/2/3] Timer Compare Register (TCMP) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.11.6 Register Description, page 330
  * 
  * TCMPR0 = TMR_BA01+0x04
  * TCMPR1 = TMR_BA01+0x24
  * TCMPR2 = TMR_BA23+0x04
  * TCMPR3 = TMR_BA23+0x24
  * 
  * 
  * TCMP [0:23]
  * Timer Compared Value
  * 
  * TCMP is a 24-bit compared register. When the internal 24-bit up-timer counts and its
  * value is equal to TCMP value, a Timer Interrupt is requested if the timer interrupt is
  * enabled with TCSR.IE[29]=1. The TCMP value defines the timer counting cycle time.
  * Time out period = (Period of timer clock input) * (8-bit PRESCALE + 1) * (24-bit TCMP)
  * 
  * Note1: Never write 0x0 or 0x1 in TCMP, or the core will run into unknown state.
  * Note2: When timer is operating in continuous counting mode, the 24-bit up-timer will
  * count continuously if software writes a new value into TCMP. If timer is operating in
  * other modes, the 24-bit up-timer will restart counting and will use the newest TCMP value
  * to be the compared value if the software has written a new value into TCMP.
  * 
  */

#define TIMER_TCMP_TCMP_Pos                               0
#define TIMER_TCMP_TCMP_Msk                               (0xFFFFFFul << TIMER_TCMP_TCMP_Pos)
// Bits 24-31 are Reserved.


/**
  * @brief TIMER Controller (TIMER) - Register TISR
  * 
  * @description TIMER [0/1/2/3] Timer Interrupt Status Register (TISR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.11.6 Register Description, page 331
  * 
  * TISR0 = TMR_BA01+0x08
  * TISR1 = TMR_BA01+0x28
  * TISR2 = TMR_BA23+0x08
  * TISR3 = TMR_BA23+0x28
  * 
  * 
  * TIF [0]
  * Timer Interrupt Flag
  * 
  * This bit indicates the interrupt status of timer.
  * The TIF bit is set by hardware when the up counting value of internal 24-bit up-timer
  * matches the timer compared value (TCMP). It is cleared by writing 1 to this bit.
  * 
  * 
  * TWF [1]
  * Timer Wakeup Flag
  * 
  * If timer causes CPU wakes up from power-down mode, this bit will be set to high.
  * It must be cleared by software with a write 1 to this bit.
  * 
  * 0 = Timer does not cause CPU wakeup.
  * 1 = CPU wakes up from sleep or power-down mode by timer time-out.
  * 
  * 
  */

#define TIMER_TISR_TIF_Pos                                0
#define TIMER_TISR_TIF_Msk                                (0x01ul << TIMER_TISR_TIF_Pos)
#define TIMER_TISR_TWF_Pos                                1
#define TIMER_TISR_TWF_Msk                                (0x01ul << TIMER_TISR_TWF_Pos)
// Bits 2-31 are Reserved.


/**
  * @brief TIMER Controller (TIMER) - Register TDR
  * 
  * @description TIMER [0/1/2/3] Timer Data Register (TDR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.11.6 Register Description, page 332
  * 
  * TDR0 = TMR_BA01+0x0C
  * TDR1 = TMR_BA01+0x2C
  * TDR2 = TMR_BA23+0x0C
  * TDR3 = TMR_BA23+0x2C
  * 
  * 
  * TDR [0:23]
  * Timer Data Register
  * 
  * 1. CTB (TCSR[24] ) = 0:
  *    TDR is 24- bits up timer value.
  *    User can read TDR for getting current 24- bits up timer value if
  *    TCSR[24] = is set to 0
  * 2. CTB (TCSR[24] ) = 1:
  *    TDR is 24- bits up event counter value.
  *    User can read TDR for getting current 24- bits up event counter value
  *    if TCSR[24] is 1
  * 
  */

#define TIMER_TDR_TDR_Pos                                 0
#define TIMER_TDR_TDR_Msk                                 (0xFFFFFFul << TIMER_TDR_TDR_Pos)
// Bits 24-31 are Reserved.


/**
  * @brief TIMER Controller (TIMER) - Register TCAP
  * 
  * @description TIMER [0/1/2/3] Timer Capture Data Register (TCAP) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.11.6 Register Description, page 333
  * 
  * TCAP0 = TMR_BA01+0x10
  * TCAP1 = TMR_BA01+0x30
  * TCAP2 = TMR_BA23+0x10
  * TCAP3 = TMR_BA23+0x30
  * 
  * 
  * TCAP [0:23]
  * Timer Capture Data Register
  * 
  * When TEXEN (TEXCON[3]) is set, RSTCAPn(TTXCON[4]) is 0, and the transition
  * on the TEX pins associated TEX_EDGE(TEXCON[2:1]) setting has occurred -
  * the internal 24-bit up-timer value will be loaded into TCAP.
  * 
  * User can read this register for the counter value.
  * 
  */

#define TIMER_TCAP_TCAP_Pos                               0
#define TIMER_TCAP_TCAP_Msk                               (0xFFFFFFul << TIMER_TCAP_TCAP_Pos)
// Bits 24-31 are Reserved.


/**
  * @brief TIMER Controller (TIMER) - Register TEXCON
  * 
  * @description TIMER [0/1/2/3] Timer External Control Register (TEXCON) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.11.6 Register Description, page 334-335
  * 
  * TEXCON0 = TMR_BA01+0x14
  * TEXCON1 = TMR_BA01+0x34
  * TEXCON2 = TMR_BA23+0x14
  * TEXCON3 = TMR_BA23+0x34
  * 
  * 
  * TX_PHASE [0]
  * Timer External Count Phase
  * 
  * This bit indicates the external count pin phase.
  * 
  * 1 = A rising edge of external count pin will be counted.
  * 0 = A falling edge of external count pin will be counted.
  * 
  * 
  * TEX_EDGE [1:2]
  * Timer External Pin Edge Detect
  * 
  * 00 = 1 to 0 transition on TEX will be detected.
  * 01 = 0 to 1 transition on TEX will be detected.
  * 10 = Either 1 to 0 or 0 to 1 transition on TEX will be detected.
  * 11 = Reserved.
  * 
  * 
  * TEXEN [3]
  * Timer External Pin Enable
  * 
  * This bit enables the reset/capture function on the TEX pin.
  * 
  * 1 = Transition detected on the TEX pin will result in capture or reset of timer counter.
  * 0 = TEX pin will be ignored.
  * 
  * 
  * RSTCAPn [4]
  * Timer External Reset Counter/Capture Mode Selection
  * 
  * 1 = TEX transition is used as the timer counter reset function.
  * 0 = TEX transition is used as the timer capture function.
  * 
  * 
  * TEXIEN [5]
  * Timer External Interrupt Enable Bit
  * 
  * 1 = Timer external interrupt Enabled.
  * 0 = Timer external interrupt Disabled.
  * 
  * If timer external interrupt is enabled, the timer asserts its external interrupt signal
  * which issent to NVIC to inform CPU when the transition on the TEX pins associated with
  * TEX_EDGE(TEXCON[2:1]) setting has happened.
  * 
  * For example, while TEXIEN = 1, TEXEN = 1, and TEX_EDGE = 00, a 1 to 0 transition
  * on the TEX pin will cause the TEXIF(TEXISR[0]) interrupt flag to be set, then the
  * interrupt signal is generated and sent to NVIC to inform MCU.
  * 
  * 
  * TEXDB [6]
  * Timer External Capture Pin De-bounce Enable Bit
  * 
  * 1 = De-bounce Enabled.
  * 0 = De-bounce Disabled.
  * 
  * If this bit is enabled, the edge of T0EX~T3EX pin is detected with de-bounce circuit.
  * 
  * 
  * TCDB [7]
  * Timer Counter Pin De-bounce Enable Bit
  * 
  * 1 = De-bounce Enabled.
  * 0 = De-bounce Disabled.
  * 
  * If this bit is enabled, the edge of TM0~TM3 pin is detected with de-bounce circuit.
  * 
  */

#define TIMER_TEXCON_TX_PHASE_Pos                         0
#define TIMER_TEXCON_TX_PHASE_Msk                         (0x01ul << TIMER_TEXCON_TX_PHASE_Pos)
#define TIMER_TEXCON_TEX_EDGE_Pos                         1
#define TIMER_TEXCON_TEX_EDGE_Msk                         (0x03ul << TIMER_TEXCON_TEX_EDGE_Pos)
#define TIMER_TEXCON_TEXEN_Pos                            3
#define TIMER_TEXCON_TEXEN_Msk                            (0x01ul << TIMER_TEXCON_TEXEN_Pos)
#define TIMER_TEXCON_RSTCAPSEL_Pos                        4
#define TIMER_TEXCON_RSTCAPSEL_Msk                        (0x01ul << TIMER_TEXCON_RSTCAPSEL_Pos)
#define TIMER_TEXCON_TEXIEN_Pos                           5
#define TIMER_TEXCON_TEXIEN_Msk                           (0x01ul << TIMER_TEXCON_TEXIEN_Pos)
#define TIMER_TEXCON_TEXDB_Pos                            6
#define TIMER_TEXCON_TEXDB_Msk                            (0x01ul << TIMER_TEXCON_TEXDB_Pos)
#define TIMER_TEXCON_TCDB_Pos                             7
#define TIMER_TEXCON_TCDB_Msk                             (0x01ul << TIMER_TEXCON_TCDB_Pos)
// Bits 8-31 are Reserved.


/**
  * @brief TIMER Controller (TIMER) - Register TEXISR
  * 
  * @description TIMER [0/1/2/3] Timer External Interrupt Status Register (TEXISR) bit defines
  * 
  * See NUC123 Technical Reference Manual 5.11.6 Register Description, page 336
  * 
  * TEXISR0 = TMR_BA01+0x18
  * TEXISR1 = TMR_BA01+0x38
  * TEXISR2 = TMR_BA23+0x18
  * TEXISR3 = TMR_BA23+0x38
  * 
  * 
  * TEXIF [0]
  * Timer External Interrupt Flag
  * 
  * This bit indicates the external interrupt status of Timer.
  * This bit is set by hardware when TEXEN (TEXCON[3]) is to 1, and the transition on
  * the TEX pins associated with TEX_EDGE (TEXCON[2:1]) setting has occurred.
  * 
  * It is cleared by writing 1 to this bit.
  * 
  * For example, while TEXEN = 1, and TEX_EDGE = 00, a 1 to 0 transition on the TEX
  * pin causes the TEXIF bit to be set.
  * 
  */

#define TIMER_TEXISR_TEXIF_Pos                            0
#define TIMER_TEXISR_TEXIF_Msk                            (0x01ul << TIMER_TEXISR_TEXIF_Pos)
// Bits 1-31 are Reserved.


/*@}*/ /* end of group NUC123SD4AN0_Peripherals */

/* =========================================  End of section using anonymous unions  ========================================= */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */


/* ToDo: add here your device peripherals base addresses
         following is an example for timer */
/** @addtogroup Device_Peripheral_peripheralAddr
  * @{
  * 
  * See NUC123 Technical Reference Manual 5.1.2 System Memory Map, pages 29-30
  * 
  */

/* Peripheral and SRAM base address */
// #define <DeviceAbbreviation>_FLASH_BASE       (0x00000000UL)                              /*!< (FLASH     ) Base Address */
// #define <DeviceAbbreviation>_SRAM_BASE        (0x20000000UL)                              /*!< (SRAM      ) Base Address */
// #define <DeviceAbbreviation>_PERIPH_BASE      (0x40000000UL)                              /*!< (Peripheral) Base Address */
#define FLASH_BASE          (0x00000000ul)
#define SRAM_BASE           (0x20000000ul)
#define AHB_BASE            (0x50000000ul)
#define APB1_BASE           (0x40000000ul)
#define APB2_BASE           (0x40100000ul)

/* Peripheral memory map */
// #define <DeviceAbbreviation>TIM0_BASE         (<DeviceAbbreviation>_PERIPH_BASE)          /*!< (Timer0    ) Base Address */
// #define <DeviceAbbreviation>TIM1_BASE         (<DeviceAbbreviation>_PERIPH_BASE + 0x0800) /*!< (Timer1    ) Base Address */
// #define <DeviceAbbreviation>TIM2_BASE         (<DeviceAbbreviation>_PERIPH_BASE + 0x1000) /*!< (Timer2    ) Base Address */
#define GCR_BASE             (AHB_BASE+0x00000)                           // System Global Controller Base Address
#define CLK_BASE             (AHB_BASE+0x00200)                           // System Clock Controller Base Address
#define INT_BASE             (AHB_BASE+0x00300)                           // Interrupt Source Controller Base Address

#define GPIO_BASE            (AHB_BASE+0x4000)                            // GPIO Base Address
#define PA_BASE              (GPIO_BASE+0x0000)                           // GPIO PORTA Base Address
#define PB_BASE              (GPIO_BASE+0x0040)                           // GPIO PORTB Base Address
#define PC_BASE              (GPIO_BASE+0x0080)                           // GPIO PORTC Base Address
#define PD_BASE              (GPIO_BASE+0x00C0)                           // GPIO PORTD Base Address
#define PF_BASE              (GPIO_BASE+0x0140)                           // GPIO PORTF Base Address
#define DBNCECON_BASE        (GPIO_BASE+0x0180)                           // GPIO De-bounce Cycle Control Base Address
#define GPIO_PIN_DATA_BASE   (GPIO_BASE+0x0200)                           // GPIO Pin Data Input/Output Control Base Address

// #define WDT_BASE             (APB1_BASE+0x4000)                           // Watchdog Timer Base Address
// #define WWDT_BASE            (APB1_BASE+0x4100)                           // Window Watchdog Timer Base Address

#define TIMER0_BASE          (APB1_BASE+0x10000)                          // Timer0 Base Address
#define TIMER1_BASE          (APB1_BASE+0x10020)                          // Timer1 Base Address
#define TIMER2_BASE          (APB2_BASE+0x10000)                          // Timer2 Base Address
#define TIMER3_BASE          (APB2_BASE+0x10020)                          // Timer3 Base Address

#define SPI0_BASE            (APB1_BASE+0x30000)                          // SPI0 Base Address
#define SPI1_BASE            (APB1_BASE+0x34000)                          // SPI1 Base Address
#define SPI2_BASE            (APB2_BASE+0x30000)                          // SPI2 Base Address

#define PWMA_BASE            (APB1_BASE+0x40000)                          // PWMA Base Address                                */

// #define UART0_BASE           (APB1_BASE+0x50000)                          // UART0 Base Address
// #define UART1_BASE           (APB2_BASE+0x50000)                          // UART1 Base Address

#define USBD_BASE            (APB1_BASE+0x60000)                          // USBD Base Address

/** @} */ /* End of group Device_Peripheral_peripheralAddr */


/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */


/* ToDo: add here your device peripherals pointer definitions
         following is an example for timer */
/** @addtogroup Device_Peripheral_declaration
  * @{
  */

// #define <DeviceAbbreviation>_TIM0        ((<DeviceAbbreviation>_TMR_TypeDef *) <DeviceAbbreviation>TIM0_BASE)
// #define <DeviceAbbreviation>_TIM1        ((<DeviceAbbreviation>_TMR_TypeDef *) <DeviceAbbreviation>TIM0_BASE)
// #define <DeviceAbbreviation>_TIM2        ((<DeviceAbbreviation>_TMR_TypeDef *) <DeviceAbbreviation>TIM0_BASE)


#define SYS                  ((GCR_T *) GCR_BASE)
#define CLK                  ((CLK_T *) CLK_BASE)
#define SYSINT               ((GCR_INT_T *) INT_BASE)

#define PA                   ((GPIO_T *) PA_BASE)
#define PB                   ((GPIO_T *) PB_BASE)
#define PC                   ((GPIO_T *) PC_BASE)
#define PD                   ((GPIO_T *) PD_BASE)
#define PF                   ((GPIO_T *) PF_BASE)
#define GPIO_DBNCE           ((GPIO_DBNCECON_T *) DBNCECON_BASE)

// #define WDT                  ((WDT_T *) WDT_BASE)
// #define WWDT                 ((WWDT_T *) WWDT_BASE)

#define TIMER0               ((TIMER_T *) TIMER0_BASE)
#define TIMER1               ((TIMER_T *) TIMER1_BASE)
#define TIMER2               ((TIMER_T *) TIMER2_BASE)
#define TIMER3               ((TIMER_T *) TIMER3_BASE)

#define PWMA                 ((PWM_T *) PWMA_BASE)

#define SPI0                 ((SPI_T *) SPI0_BASE)
#define SPI1                 ((SPI_T *) SPI1_BASE)
#define SPI2                 ((SPI_T *) SPI2_BASE)

// #define UART0                ((UART_T *) UART0_BASE)
// #define UART1                ((UART_T *) UART1_BASE)

#define USBD                 ((USBD_T *) USBD_BASE)

/*
  * |Module index        |Clock source                          |Divider                 |
  * | :----------------  | :------------------------------------| :--------------------- |
  * |\ref WDT_MODULE     |\ref CLK_CLKSEL1_WDT_S_LIRC           | x                      |
  * |\ref WDT_MODULE     |\ref CLK_CLKSEL1_WDT_S_HCLK_DIV2048   | x                      |
  * |\ref ADC_MODULE     |\ref CLK_CLKSEL1_ADC_S_HXT            |\ref CLK_CLKDIV_ADC(x)  |
  * |\ref ADC_MODULE     |\ref CLK_CLKSEL1_ADC_S_PLL            |\ref CLK_CLKDIV_ADC(x)  |
  * |\ref ADC_MODULE     |\ref CLK_CLKSEL1_ADC_S_HCLK           |\ref CLK_CLKDIV_ADC(x)  |
  * |\ref ADC_MODULE     |\ref CLK_CLKSEL1_ADC_S_HIRC           |\ref CLK_CLKDIV_ADC(x)  |
  * |\ref SPI0_MODULE    |\ref CLK_CLKSEL1_SPI0_S_HCLK          | x                      |
  * |\ref SPI0_MODULE    |\ref CLK_CLKSEL1_SPI0_S_PLL           | x                      |
  * |\ref SPI1_MODULE    |\ref CLK_CLKSEL1_SPI1_S_HCLK          | x                      |
  * |\ref SPI1_MODULE    |\ref CLK_CLKSEL1_SPI1_S_PLL           | x                      |
  * |\ref SPI2_MODULE    |\ref CLK_CLKSEL1_SPI2_S_HCLK          | x                      |
  * |\ref SPI2_MODULE    |\ref CLK_CLKSEL1_SPI2_S_PLL           | x                      |
  * |\ref TMR0_MODULE    |\ref CLK_CLKSEL1_TMR0_S_HXT           | x                      |
  * |\ref TMR0_MODULE    |\ref CLK_CLKSEL1_TMR0_S_HCLK          | x                      |
  * |\ref TMR0_MODULE    |\ref CLK_CLKSEL1_TMR0_S_EXT_TRG       | x                      |
  * |\ref TMR0_MODULE    |\ref CLK_CLKSEL1_TMR0_S_LIRC          | x                      |
  * |\ref TMR0_MODULE    |\ref CLK_CLKSEL1_TMR0_S_HIRC          | x                      |
  * |\ref TMR1_MODULE    |\ref CLK_CLKSEL1_TMR1_S_HXT           | x                      |
  * |\ref TMR1_MODULE    |\ref CLK_CLKSEL1_TMR1_S_HCLK          | x                      |
  * |\ref TMR1_MODULE    |\ref CLK_CLKSEL1_TMR1_S_EXT_TRG       | x                      |
  * |\ref TMR1_MODULE    |\ref CLK_CLKSEL1_TMR1_S_LIRC          | x                      |
  * |\ref TMR1_MODULE    |\ref CLK_CLKSEL1_TMR1_S_HIRC          | x                      |
  * |\ref TMR2_MODULE    |\ref CLK_CLKSEL1_TMR2_S_HXT           | x                      |
  * |\ref TMR2_MODULE    |\ref CLK_CLKSEL1_TMR2_S_HCLK          | x                      |
  * |\ref TMR2_MODULE    |\ref CLK_CLKSEL1_TMR2_S_EXT_TRG       | x                      |
  * |\ref TMR2_MODULE    |\ref CLK_CLKSEL1_TMR2_S_LIRC          | x                      |
  * |\ref TMR2_MODULE    |\ref CLK_CLKSEL1_TMR2_S_HIRC          | x                      |
  * |\ref TMR3_MODULE    |\ref CLK_CLKSEL1_TMR3_S_HXT           | x                      |
  * |\ref TMR3_MODULE    |\ref CLK_CLKSEL1_TMR3_S_HCLK          | x                      |
  * |\ref TMR3_MODULE    |\ref CLK_CLKSEL1_TMR3_S_EXT_TRG       | x                      |
  * |\ref TMR3_MODULE    |\ref CLK_CLKSEL1_TMR3_S_LIRC          | x                      |
  * |\ref TMR3_MODULE    |\ref CLK_CLKSEL1_TMR3_S_HIRC          | x                      |
  * |\ref UART0_MODULE   |\ref CLK_CLKSEL1_UART_S_HXT           |\ref CLK_CLKDIV_UART(x) |
  * |\ref UART0_MODULE   |\ref CLK_CLKSEL1_UART_S_PLL           |\ref CLK_CLKDIV_UART(x) |
  * |\ref UART0_MODULE   |\ref CLK_CLKSEL1_UART_S_HIRC          |\ref CLK_CLKDIV_UART(x) |
  * |\ref UART1_MODULE   |\ref CLK_CLKSEL1_UART_S_HXT           |\ref CLK_CLKDIV_UART(x) |
  * |\ref UART1_MODULE   |\ref CLK_CLKSEL1_UART_S_PLL           |\ref CLK_CLKDIV_UART(x) |
  * |\ref UART1_MODULE   |\ref CLK_CLKSEL1_UART_S_HIRC          |\ref CLK_CLKDIV_UART(x) |
  * |\ref PWM01_MODULE   |\ref CLK_CLKSEL12_PWM01_S_HXT         | x                      |
  * |\ref PWM01_MODULE   |\ref CLK_CLKSEL12_PWM01_S_HCLK        | x                      |
  * |\ref PWM01_MODULE   |\ref CLK_CLKSEL12_PWM01_S_HIRC        | x                      |
  * |\ref PWM01_MODULE   |\ref CLK_CLKSEL12_PWM01_S_LIRC        | x                      |
  * |\ref PWM23_MODULE   |\ref CLK_CLKSEL12_PWM23_S_HXT         | x                      |
  * |\ref PWM23_MODULE   |\ref CLK_CLKSEL12_PWM23_S_HCLK        | x                      |
  * |\ref PWM23_MODULE   |\ref CLK_CLKSEL12_PWM23_S_HIRC        | x                      |
  * |\ref PWM23_MODULE   |\ref CLK_CLKSEL12_PWM23_S_LIRC        | x                      |
  * |\ref I2S_MODULE     |\ref CLK_CLKSEL2_I2S_S_HXT            | x                      |
  * |\ref I2S_MODULE     |\ref CLK_CLKSEL2_I2S_S_PLL            | x                      |
  * |\ref I2S_MODULE     |\ref CLK_CLKSEL2_I2S_S_HCLK           | x                      |
  * |\ref I2S_MODULE     |\ref CLK_CLKSEL2_I2S_S_HIRC           | x                      |
  * |\ref FDIV_MODULE    |\ref CLK_CLKSEL2_FRQDIV_S_HXT         | x                      |
  * |\ref FDIV_MODULE    |\ref CLK_CLKSEL2_FRQDIV_S_HCLK        | x                      |
  * |\ref FDIV_MODULE    |\ref CLK_CLKSEL2_FRQDIV_S_HIRC        | x                      |
  * |\ref WWDT_MODULE    |\ref CLK_CLKSEL2_WWDT_S_HCLK_DIV2048  | x                      |
  * |\ref WWDT_MODULE    |\ref CLK_CLKSEL2_WWDT_S_LIRC          | x                      |
  * |\ref USBD_MODULE    | x                                    |\ref CLK_CLKDIV_USB(x)  |
*/
typedef enum ModuleNum {

  WDT_ModuleNum = 0,
  ADC_ModuleNum = 1,
  SPI0_ModuleNum,
  SPI1_ModuleNum,
  SPI2_ModuleNum,
  TMR0_ModuleNum,
  TMR1_ModuleNum,
  TMR2_ModuleNum,
  TMR3_ModuleNum,
  UART0_ModuleNum,
  UART1_ModuleNum,
  PWM01_ModuleNum,
  PWM23_ModuleNum,
  I2S_ModuleNum,
  FDIV_ModuleNum,
  WWDT_ModuleNum,
  USBD_ModuleNum,
  I2C0_ModuleNum,
  I2C1_ModuleNum,
  PS2_ModuleNum,
  PDMA_ModuleNum,
  ISP_ModuleNum

} ModuleNum_Type;


/* =========================================================================================================================== */
/* ================                             Peripheral Register Operations                                ================ */
/* =========================================================================================================================== */

#ifndef NULL
#define NULL        0
#endif

#define UNLOCKREG()        do{*((__IO uint32_t *)(GCR_BASE + 0x100)) = 0x59;*((__IO uint32_t *)(GCR_BASE + 0x100)) = 0x16;*((__IO uint32_t *)(GCR_BASE + 0x100)) = 0x88;}while(*((__IO uint32_t *)(GCR_BASE + 0x100))==0)
#define LOCKREG()          *((__IO uint32_t *)(GCR_BASE + 0x100)) = 0x00

#define REGCOPY(dest, src)  *((uint32_t *)&(dest)) = *((uint32_t *)&(src))
#define CLEAR(dest)         *((uint32_t *)&(dest)) = 0

#define MEM32(addr) (*((volatile unsigned long *) (addr)))


/* =========================================================================================================================== */
/* ================                                  Peripheral includes                                      ================ */
/* =========================================================================================================================== */



/** @} */ /* End of group NUC123SD4AN0 */

/** @} */ /* End of group NUVOTON */

#ifdef __cplusplus
}
#endif



#endif  /* NUC123SD4AN0_H */