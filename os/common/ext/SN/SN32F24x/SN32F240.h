
/****************************************************************************************************/
/**
* @file     SN32F240.h
*
* @brief    CMSIS Cortex-M0 Peripheral Access Layer Header File for
*           SN32F240 from SONiX Technology Co., Ltd..
*
* @version  V2.0
* @date     19. March 2019
*
* @note     Generated with SVDConv V2.87e
*           from CMSIS SVD File 'SN32F240.svd' Version 2.0,
*
* @par      ARM Limited (ARM) is supplying this software for use with Cortex-M
*           processor based microcontroller, but can be equally used for other
*           suitable processor architectures. This file can be freely distributed.
*           Modifications to this file shall be clearly marked.
*
*           THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED
*           OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
*           MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
*           ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
*           CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
*
*******************************************************************************************************/

/** @addtogroup SONiX Technology Co., Ltd.
 * @{
 */

/** @addtogroup SN32F240
 * @{
 */

#ifndef SN32F240_H
#define SN32F240_H

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum {
    /* -------------------  Cortex-M0 Processor Exceptions Numbers  ------------------- */
    Reset_IRQn          = -15, /*!<   1  Reset Vector, invoked on Power up and warm reset                 */
    NonMaskableInt_IRQn = -14, /*!<   2  Non maskable Interrupt, cannot be stopped or preempted           */
    HardFault_IRQn      = -13, /*!<   3  Hard Fault, all classes of Fault                                 */
    SVCall_IRQn         = -5,  /*!<  11  System Service Call via SVC instruction                          */
    PendSV_IRQn         = -2,  /*!<  14  Pendable request for system service                              */
    SysTick_IRQn        = -1,  /*!<  15  System Tick Timer                                                */
                               /* ---------------------  SN32F240 Specific Interrupt Numbers  -------------------- */
    NDT_IRQn    = 0,           /*!<   0  NDT                                                              */
    USB_IRQn    = 1,           /*!<   1  USB                                                              */
    LCD_IRQn    = 2,           /*!<   2  LCD                                                              */
    I2S_IRQn    = 3,           /*!<   3  I2S                                                              */
    SSP0_IRQn   = 6,           /*!<   6  SSP0                                                             */
    SSP1_IRQn   = 7,           /*!<   7  SSP1                                                             */
    I2C0_IRQn   = 10,          /*!<  10  I2C0                                                             */
    I2C1_IRQn   = 11,          /*!<  11  I2C1                                                             */
    USART0_IRQn = 13,          /*!<  13  USART0                                                           */
    USART1_IRQn = 14,          /*!<  14  USART1                                                           */
    CT16B0_IRQn = 15,          /*!<  15  CT16B0                                                           */
    CT16B1_IRQn = 16,          /*!<  16  CT16B1                                                           */
    CT16B2_IRQn = 17,          /*!<  17  CT16B2                                                           */
    CT32B0_IRQn = 19,          /*!<  19  CT32B0                                                           */
    CT32B1_IRQn = 20,          /*!<  20  CT32B1                                                           */
    CT32B2_IRQn = 21,          /*!<  21  CT32B2                                                           */
    RTC_IRQn    = 23,          /*!<  23  RTC                                                              */
    ADC_IRQn    = 24,          /*!<  24  ADC                                                              */
    WDT_IRQn    = 25,          /*!<  25  WDT                                                              */
    LVD_IRQn    = 26,          /*!<  26  LVD                                                              */
    P3_IRQn     = 28,          /*!<  28  P3                                                               */
    P2_IRQn     = 29,          /*!<  29  P2                                                               */
    P1_IRQn     = 30,          /*!<  30  P1                                                               */
    P0_IRQn     = 31           /*!<  31  P0                                                               */
} IRQn_Type;

/** @addtogroup Configuration_of_CMSIS
 * @{
 */

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* ----------------Configuration of the Cortex-M0 Processor and Core Peripherals---------------- */
#define __CM0_REV 0x0000 /*!< Cortex-M0 Core Revision                                               */
#define __MPU_PRESENT 0 /*!< MPU present or not                                                    */
#define __NVIC_PRIO_BITS 2 /*!< Number of Bits used for Priority Levels                               */
#define __Vendor_SysTickConfig 0 /*!< Set to 1 if different SysTick Config is used                          */
/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm0.h" /*!< Cortex-M0 processor and core peripherals                              */
#include "system_SN32F200.h" /*!< SN32F240 System                                                       */

/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */

/** @addtogroup Device_Peripheral_Registers
 * @{
 */

/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
#    pragma push
#    pragma anon_unions
#elif defined(__ICCARM__)
#    pragma language = extended
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
#    pragma warning 586
#else
#    warning Not supported compiler type
#endif

/* ================================================================================ */
/* ================                     SN_SYS0                    ================ */
/* ================================================================================ */

/**
 * @brief System Control Registers (SN_SYS0)
 */

typedef struct { /*!< SN_SYS0 Structure                                                     */

    union {
        __IO uint32_t ANBCTRL; /*!< Offset:0x00 Analog Block Control Register                             */

        struct {
            __IO uint32_t IHRCEN : 1; /*!< IHRC enable                                                           */
            uint32_t : 1;
            __IO uint32_t ELSEN : 1; /*!< ELS XTAL enable                                                       */
            uint32_t : 1;
            __IO uint32_t EHSEN : 1;   /*!< EHS XTAL enable                                                       */
            __IO uint32_t EHSFREQ : 1; /*!< EHS XTAL frequency range                                              */
        } ANBCTRL_b;                   /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t PLLCTRL; /*!< Offset:0x04 PLL Control Register                                      */

        struct {
            __IO uint32_t MSEL : 5; /*!< M: 3~31                                                               */
            __IO uint32_t PSEL : 3; /*!< P=PSEL*2                                                              */
            __IO uint32_t FSEL : 1; /*!< F=POWER(2, FSEL)                                                      */
            uint32_t : 3;
            __IO uint32_t PLLCLKSEL : 2; /*!< PLL clock source                                                      */
            uint32_t : 1;
            __IO uint32_t PLLEN : 1; /*!< PLL enable                                                            */
        } PLLCTRL_b;                 /*!< BitSize                                                               */
    };

    union {
        __I uint32_t CSST; /*!< Offset:0x08 Clock Source Status Register                              */

        struct {
            __I uint32_t IHRCRDY : 1; /*!< IHRC ready flag                                                       */
            uint32_t : 1;
            __I uint32_t ELSRDY : 1; /*!< ELS XTAL ready flag                                                   */
            uint32_t : 1;
            __I uint32_t EHSRDY : 1; /*!< EHS XTAL ready flag                                                   */
            uint32_t : 1;
            __I uint32_t PLLRDY : 1; /*!< PLL ready flag                                                        */
        } CSST_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CLKCFG; /*!< Offset:0x0C System Clock Configuration Register                       */

        struct {
            __IO uint32_t SYSCLKSEL : 3; /*!< System clock source selection                                         */
            uint32_t : 1;
            __I uint32_t SYSCLKST : 3; /*!< System clock switch status                                            */
        } CLKCFG_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t AHBCP; /*!< Offset:0x10 AHB Clock Prescale Register                               */

        struct {
            __IO uint32_t AHBPRE : 4; /*!< AHB clock source prescaler                                            */
        } AHBCP_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t RSTST; /*!< Offset:0x14 System Reset Status Register                              */

        struct {
            __IO uint32_t SWRSTF : 1;  /*!< Software reset flag                                                   */
            __IO uint32_t WDTRSTF : 1; /*!< WDT reset flag                                                        */
            __IO uint32_t LVDRSTF : 1; /*!< LVD reset flag                                                        */
            __IO uint32_t EXTRSTF : 1; /*!< External reset flag                                                   */
            __IO uint32_t PORRSTF : 1; /*!< POR reset flag                                                        */
        } RSTST_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t LVDCTRL; /*!< Offset:0x18 LVD Control Register                                      */

        struct {
            __IO uint32_t LVDRSTLVL : 3; /*!< LVD reset level                                                       */
            uint32_t : 1;
            __IO uint32_t LVDINTLVL : 3; /*!< LVD interrupt level                                                   */
            uint32_t : 7;
            __IO uint32_t LVDRSTEN : 1; /*!< LVD Reset enable                                                      */
            __IO uint32_t LVDEN : 1;    /*!< LVD enable                                                            */
        } LVDCTRL_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t EXRSTCTRL; /*!< Offset:0x1C External Reset Pin Control Register                       */

        struct {
            __IO uint32_t RESETDIS : 1; /*!< External reset pin disable                                            */
        } EXRSTCTRL_b;                  /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t SWDCTRL; /*!< Offset:0x20 SWD Pin Control Register                                  */

        struct {
            __IO uint32_t SWDDIS : 1; /*!< SWD pin disable                                                       */
        } SWDCTRL_b;                  /*!< BitSize                                                               */
    };
    __I uint32_t RESERVED;

    union {
        __IO uint32_t NDTCTRL; /*!< Offset:0x28 Noise Detect Control Register                             */

        struct {
            __IO uint32_t NDT1_IE : 1; /*!< NDT for Vcore interrupt enable bit                                    */
            __IO uint32_t NDT2_IE : 1; /*!< NDT for VDD interrupt enable bit                                      */
        } NDTCTRL_b;                   /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t NDTSTS; /*!< Offset:0x2C Noise Detect Status Register                              */

        struct {
            __IO uint32_t NDT1_DET : 1; /*!< Power noise status of NDT1                                            */
            __IO uint32_t NDT2_DET : 1; /*!< Power noise status of NDT2                                            */
        } NDTSTS_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t ANTIEFT; /*!< Offset:0x30 Anti-EFT Ability Control Register                         */

        struct {
            __IO uint32_t AEFT : 3; /*!< Anti-EFT ability                                                      */
        } ANTIEFT_b;                /*!< BitSize                                                               */
    };
} SN_SYS0_Type;

/* ================================================================================ */
/* ================                     SN_SYS1                    ================ */
/* ================================================================================ */

/**
 * @brief System Control Registers (SN_SYS1)
 */

typedef struct { /*!< SN_SYS1 Structure                                                     */

    union {
        __IO uint32_t AHBCLKEN; /*!< Offset:0x00 AHB Clock Enable Register                                 */

        struct {
            __IO uint32_t GPIOCLKEN : 1; /*!< Enable AHB clock for GPIO                                             */
            __IO uint32_t USBCLKEN : 1;  /*!< Enable AHB clock for USB                                              */
            __IO uint32_t LCDCLKEN : 1;  /*!< Enable AHB clock for LCD                                              */
            uint32_t : 2;
            __IO uint32_t CT16B0CLKEN : 1; /*!< Enable AHB clock for CT16B0                                           */
            __IO uint32_t CT16B1CLKEN : 1; /*!< Enable AHB clock for CT16B1                                           */
            __IO uint32_t CT16B2CLKEN : 1; /*!< Enable AHB clock for CT16B2                                           */
            __IO uint32_t CT32B0CLKEN : 1; /*!< Enable AHB clock for CT32B0                                           */
            __IO uint32_t CT32B1CLKEN : 1; /*!< Enable AHB clock for CT32B1                                           */
            __IO uint32_t CT32B2CLKEN : 1; /*!< Enable AHB clock for CT32B2                                           */
            __IO uint32_t ADCCLKEN : 1;    /*!< Enable AHB clock for ADC                                              */
            __IO uint32_t SSP0CLKEN : 1;   /*!< Enable AHB clock for SSP0                                             */
            __IO uint32_t SSP1CLKEN : 1;   /*!< Enable AHB clock for SSP1                                             */
            uint32_t : 2;
            __IO uint32_t USART0CLKEN : 1; /*!< Enable AHB clock for USART0                                           */
            __IO uint32_t USART1CLKEN : 1; /*!< Enable AHB clock for USART1                                           */
            uint32_t : 2;
            __IO uint32_t I2C1CLKEN : 1; /*!< Enable AHB clock for I2C1                                             */
            __IO uint32_t I2C0CLKEN : 1; /*!< Enable AHB clock for I2C0                                             */
            __IO uint32_t I2SCLKEN : 1;  /*!< Enable AHB clock for I2S                                              */
            __IO uint32_t RTCCLKEN : 1;  /*!< Enable AHB clock for RTC                                              */
            __IO uint32_t WDTCLKEN : 1;  /*!< Enable AHB clock for WDT                                              */
            uint32_t : 3;
            __IO uint32_t CLKOUTSEL : 3; /*!< Clock output source selection                                         */
        } AHBCLKEN_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t APBCP0; /*!< Offset:0x04 APB Clock Prescale Register 0                             */

        struct {
            __IO uint32_t CT16B0PRE : 3; /*!< CT16B0 APB clock source prescaler                                     */
            uint32_t : 1;
            __IO uint32_t CT16B1PRE : 3; /*!< CT16B1 APB clock source prescaler                                     */
            uint32_t : 1;
            __IO uint32_t CT32B0PRE : 3; /*!< CT32B0 APB clock source prescaler                                     */
            uint32_t : 1;
            __IO uint32_t CT32B1PRE : 3; /*!< CT32B1 APB clock source prescaler                                     */
            uint32_t : 1;
            __IO uint32_t ADCPRE : 3; /*!< ADC APB clock source prescaler                                        */
            uint32_t : 1;
            __IO uint32_t SSP0PRE : 3; /*!< SSP0 APB clock source prescaler                                       */
            uint32_t : 1;
            __IO uint32_t SSP1PRE : 3; /*!< SSP1 APB clock source prescaler                                       */
            uint32_t : 1;
            __IO uint32_t CT32B2PRE : 3; /*!< CT32B2 APB clock source prescaler                                     */
        } APBCP0_b;                      /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t APBCP1; /*!< Offset:0x08 APB Clock Prescale Register 1                             */

        struct {
            __IO uint32_t USART0PRE : 3; /*!< USART0 APB clock source prescaler                                     */
            uint32_t : 1;
            __IO uint32_t USART1PRE : 3; /*!< USART1 APB clock source prescaler                                     */
            uint32_t : 1;
            __IO uint32_t I2C0PRE : 3; /*!< I2C0 APB clock source prescaler                                       */
            uint32_t : 1;
            __IO uint32_t I2SPRE : 3; /*!< I2S APB clock source prescaler                                        */
            uint32_t : 1;
            __IO uint32_t SYSTICKPRE : 2; /*!< SysTick APB clock source prescaler                                    */
            uint32_t : 2;
            __IO uint32_t WDTPRE : 3; /*!< WDT APB clock source prescaler                                        */
            uint32_t : 1;
            __IO uint32_t I2C1PRE : 3; /*!< I2C1 APB clock source prescaler                                       */
            uint32_t : 1;
            __IO uint32_t CT16B2PRE : 3; /*!< CT16B2 APB clock source prescaler                                     */
        } APBCP1_b;                      /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t APBCP2; /*!< Offset:0x0C APB Clock Prescale Register 2                             */

        struct {
            __IO uint32_t CLKOUTPRE : 4; /*!< CLKOUT APB clock source prescaler                                     */
        } APBCP2_b;                      /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t PRST; /*!< Offset:0x10 Peripheral Reset Register                                 */

        struct {
            __IO uint32_t GPIO0RST : 1; /*!< GPIO0 Reset                                                           */
            __IO uint32_t GPIO1RST : 1; /*!< GPIO1 Reset                                                           */
            __IO uint32_t GPIO2RST : 1; /*!< GPIO2 Reset                                                           */
            __IO uint32_t GPIO3RST : 1; /*!< GPIO3 Reset                                                           */
            uint32_t : 1;
            __IO uint32_t CT16B0RST : 1; /*!< CT16B0 Reset                                                          */
            __IO uint32_t CT16B1RST : 1; /*!< CT16B1 Reset                                                          */
            __IO uint32_t CT16B2RST : 1; /*!< CT16B2 Reset                                                          */
            __IO uint32_t CT32B0RST : 1; /*!< CT32B0 Reset                                                          */
            __IO uint32_t CT32B1RST : 1; /*!< CT32B1 Reset                                                          */
            __IO uint32_t CT32B2RST : 1; /*!< CT32B2 Reset                                                          */
            __IO uint32_t ADCRST : 1;    /*!< ADC Reset                                                             */
            __IO uint32_t SSP0RST : 1;   /*!< SSP0 Reset                                                            */
            __IO uint32_t SSP1RST : 1;   /*!< SSP1 Reset                                                            */
            uint32_t : 1;
            __IO uint32_t LCDRST : 1;    /*!< LCD Reset                                                             */
            __IO uint32_t USART0RST : 1; /*!< USART0 Reset                                                          */
            __IO uint32_t USART1RST : 1; /*!< USART1 Reset                                                          */
            uint32_t : 2;
            __IO uint32_t I2C1RST : 1; /*!< I2C1 Reset                                                            */
            __IO uint32_t I2C0RST : 1; /*!< I2C0 Reset                                                            */
            __IO uint32_t I2SRST : 1;  /*!< I2S Reset                                                             */
            __IO uint32_t RTCRST : 1;  /*!< RTC Reset                                                             */
            __IO uint32_t WDTRST : 1;  /*!< WDT Reset                                                             */
            __IO uint32_t USBRST : 1;  /*!< USB Reset                                                             */
        } PRST_b;                      /*!< BitSize                                                               */
    };
    __I uint32_t  RESERVED[3];
    __IO uint32_t DIVIDEND;  /*!< Offset:0x20 Divider Dividend Register                                 */
    __IO uint32_t DIVISOR;   /*!< Offset:0x24 Divider Dividend Register                                 */
    __I uint32_t  QUOTIENT;  /*!< Offset:0x28 Divider Quotient Register                                 */
    __I uint32_t  REMAINDER; /*!< Offset:0x2C Divider Remainder Register                                */

    union {
        __IO uint32_t DIVCTRL; /*!< Offset:0x30 Divider Control Register                                  */

        struct {
            __IO uint32_t DIVS : 1; /*!< Divider start control bit                                             */
        } DIVCTRL_b;                /*!< BitSize                                                               */
    };
} SN_SYS1_Type;

/* ================================================================================ */
/* ================                    SN_GPIO0                    ================ */
/* ================================================================================ */

/**
 * @brief General Purpose I/O (SN_GPIO0)
 */

typedef struct { /*!< SN_GPIO0 Structure                                                    */

    union {
        __IO uint32_t DATA; /*!< Offset:0x00 GPIO Port n Data Register                                 */

        struct {
            __IO uint32_t DATA0 : 1;  /*!< Data of Pn.0                                                          */
            __IO uint32_t DATA1 : 1;  /*!< Data of Pn.1                                                          */
            __IO uint32_t DATA2 : 1;  /*!< Data of Pn.2                                                          */
            __IO uint32_t DATA3 : 1;  /*!< Data of Pn.3                                                          */
            __IO uint32_t DATA4 : 1;  /*!< Data of Pn.4                                                          */
            __IO uint32_t DATA5 : 1;  /*!< Data of Pn.5                                                          */
            __IO uint32_t DATA6 : 1;  /*!< Data of Pn.6                                                          */
            __IO uint32_t DATA7 : 1;  /*!< Data of Pn.7                                                          */
            __IO uint32_t DATA8 : 1;  /*!< Data of Pn.8                                                          */
            __IO uint32_t DATA9 : 1;  /*!< Data of Pn.9                                                          */
            __IO uint32_t DATA10 : 1; /*!< Data of Pn.10                                                         */
            __IO uint32_t DATA11 : 1; /*!< Data of Pn.11                                                         */
            __IO uint32_t DATA12 : 1; /*!< Data of Pn.12                                                         */
            __IO uint32_t DATA13 : 1; /*!< Data of Pn.13                                                         */
            __IO uint32_t DATA14 : 1; /*!< Data of Pn.14                                                         */
            __IO uint32_t DATA15 : 1; /*!< Data of Pn.15                                                         */
        } DATA_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t MODE; /*!< Offset:0x04 GPIO Port n Mode Register                                 */

        struct {
            __IO uint32_t MODE0 : 1;     /*!< Mode of Pn.0                                                          */
            __IO uint32_t MODE1 : 1;     /*!< Mode of Pn.1                                                          */
            __IO uint32_t MODE2 : 1;     /*!< Mode of Pn.2                                                          */
            __IO uint32_t MODE3 : 1;     /*!< Mode of Pn.3                                                          */
            __IO uint32_t MODE4 : 1;     /*!< Mode of Pn.4                                                          */
            __IO uint32_t MODE5 : 1;     /*!< Mode of Pn.5                                                          */
            __IO uint32_t MODE6 : 1;     /*!< Mode of Pn.6                                                          */
            __IO uint32_t MODE7 : 1;     /*!< Mode of Pn.7                                                          */
            __IO uint32_t MODE8 : 1;     /*!< Mode of Pn.8                                                          */
            __IO uint32_t MODE9 : 1;     /*!< Mode of Pn.9                                                          */
            __IO uint32_t MODE10 : 1;    /*!< Mode of Pn.10                                                         */
            __IO uint32_t MODE11 : 1;    /*!< Mode of Pn.11                                                         */
            __IO uint32_t MODE12 : 1;    /*!< Mode of Pn.12                                                         */
            __IO uint32_t MODE13 : 1;    /*!< Mode of Pn.13                                                         */
            __IO uint32_t MODE14 : 1;    /*!< Mode of Pn.14                                                         */
            __IO uint32_t MODE15 : 1;    /*!< Mode of Pn.15                                                         */
            __IO uint32_t CURRENT0 : 1;  /*!< Driving/Sinking current of Pn.0                                       */
            __IO uint32_t CURRENT1 : 1;  /*!< Driving/Sinking current of Pn.1                                       */
            __IO uint32_t CURRENT2 : 1;  /*!< Driving/Sinking current of Pn.2                                       */
            __IO uint32_t CURRENT3 : 1;  /*!< Driving/Sinking current of Pn.3                                       */
            __IO uint32_t CURRENT4 : 1;  /*!< Driving/Sinking current of Pn.4                                       */
            __IO uint32_t CURRENT5 : 1;  /*!< Driving/Sinking current of Pn.5                                       */
            __IO uint32_t CURRENT6 : 1;  /*!< Driving/Sinking current of Pn.6                                       */
            __IO uint32_t CURRENT7 : 1;  /*!< Driving/Sinking current of Pn.7                                       */
            __IO uint32_t CURRENT8 : 1;  /*!< Driving/Sinking current of Pn.8                                       */
            __IO uint32_t CURRENT9 : 1;  /*!< Driving/Sinking current of Pn.9                                       */
            __IO uint32_t CURRENT10 : 1; /*!< Driving/Sinking current of Pn.10                                      */
            __IO uint32_t CURRENT11 : 1; /*!< Driving/Sinking current of Pn.11                                      */
            __IO uint32_t CURRENT12 : 1; /*!< Driving/Sinking current of Pn.12                                      */
            __IO uint32_t CURRENT13 : 1; /*!< Driving/Sinking current of Pn.13                                      */
            __IO uint32_t CURRENT14 : 1; /*!< Driving/Sinking current of Pn.14                                      */
            __IO uint32_t CURRENT15 : 1; /*!< Driving/Sinking current of Pn.15                                      */
        } MODE_b;                        /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CFG; /*!< Offset:0x08 GPIO Port n Configuration Register                        */

        struct {
            __IO uint32_t CFG0 : 2;  /*!< Configuration of Pn.0                                                 */
            __IO uint32_t CFG1 : 2;  /*!< Configuration of Pn.1                                                 */
            __IO uint32_t CFG2 : 2;  /*!< Configuration of Pn.2                                                 */
            __IO uint32_t CFG3 : 2;  /*!< Configuration of Pn.3                                                 */
            __IO uint32_t CFG4 : 2;  /*!< Configuration of Pn.4                                                 */
            __IO uint32_t CFG5 : 2;  /*!< Configuration of Pn.5                                                 */
            __IO uint32_t CFG6 : 2;  /*!< Configuration of Pn.6                                                 */
            __IO uint32_t CFG7 : 2;  /*!< Configuration of Pn.7                                                 */
            __IO uint32_t CFG8 : 2;  /*!< Configuration of Pn.8                                                 */
            __IO uint32_t CFG9 : 2;  /*!< Configuration of Pn.9                                                 */
            __IO uint32_t CFG10 : 2; /*!< Configuration of Pn.10                                                */
            __IO uint32_t CFG11 : 2; /*!< Configuration of Pn.11                                                */
            __IO uint32_t CFG12 : 2; /*!< Configuration of Pn.12                                                */
            __IO uint32_t CFG13 : 2; /*!< Configuration of Pn.13                                                */
            __IO uint32_t CFG14 : 2; /*!< Configuration of Pn.14                                                */
            __IO uint32_t CFG15 : 2; /*!< Configuration of Pn.15                                                */
        } CFG_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t IS; /*!< Offset:0x0C GPIO Port n Interrupt Sense Register                      */

        struct {
            __IO uint32_t IS0 : 1;  /*!< Interrupt on Pn.0 is event or edge sensitive                          */
            __IO uint32_t IS1 : 1;  /*!< Interrupt on Pn.1 is event or edge sensitive                          */
            __IO uint32_t IS2 : 1;  /*!< Interrupt on Pn.2 is event or edge sensitive                          */
            __IO uint32_t IS3 : 1;  /*!< Interrupt on Pn.3 is event or edge sensitive                          */
            __IO uint32_t IS4 : 1;  /*!< Interrupt on Pn.4 is event or edge sensitive                          */
            __IO uint32_t IS5 : 1;  /*!< Interrupt on Pn.5 is event or edge sensitive                          */
            __IO uint32_t IS6 : 1;  /*!< Interrupt on Pn.6 is event or edge sensitive                          */
            __IO uint32_t IS7 : 1;  /*!< Interrupt on Pn.7 is event or edge sensitive                          */
            __IO uint32_t IS8 : 1;  /*!< Interrupt on Pn.8 is event or edge sensitive                          */
            __IO uint32_t IS9 : 1;  /*!< Interrupt on Pn.9 is event or edge sensitive                          */
            __IO uint32_t IS10 : 1; /*!< Interrupt on Pn.10 is event or edge sensitive                         */
            __IO uint32_t IS11 : 1; /*!< Interrupt on Pn.11 is event or edge sensitive                         */
            __IO uint32_t IS12 : 1; /*!< Interrupt on Pn.12 is event or edge sensitive                         */
            __IO uint32_t IS13 : 1; /*!< Interrupt on Pn.13 is event or edge sensitive                         */
            __IO uint32_t IS14 : 1; /*!< Interrupt on Pn.14 is event or edge sensitive                         */
            __IO uint32_t IS15 : 1; /*!< Interrupt on Pn.15 is event or edge sensitive                         */
        } IS_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t IBS; /*!< Offset:0x10 GPIO Port n Interrupt Both-edge Sense Register            */

        struct {
            __IO uint32_t IBS0 : 1;  /*!< Interrupt on Pn.0 is triggered ob both edges                          */
            __IO uint32_t IBS1 : 1;  /*!< Interrupt on Pn.1 is triggered ob both edges                          */
            __IO uint32_t IBS2 : 1;  /*!< Interrupt on Pn.2 is triggered ob both edges                          */
            __IO uint32_t IBS3 : 1;  /*!< Interrupt on Pn.3 is triggered ob both edges                          */
            __IO uint32_t IBS4 : 1;  /*!< Interrupt on Pn.4 is triggered ob both edges                          */
            __IO uint32_t IBS5 : 1;  /*!< Interrupt on Pn.5 is triggered ob both edges                          */
            __IO uint32_t IBS6 : 1;  /*!< Interrupt on Pn.6 is triggered ob both edges                          */
            __IO uint32_t IBS7 : 1;  /*!< Interrupt on Pn.7 is triggered ob both edges                          */
            __IO uint32_t IBS8 : 1;  /*!< Interrupt on Pn.8 is triggered ob both edges                          */
            __IO uint32_t IBS9 : 1;  /*!< Interrupt on Pn.9 is triggered ob both edges                          */
            __IO uint32_t IBS10 : 1; /*!< Interrupt on Pn.10 is triggered ob both edges                         */
            __IO uint32_t IBS11 : 1; /*!< Interrupt on Pn.11 is triggered ob both edges                         */
            __IO uint32_t IBS12 : 1; /*!< Interrupt on Pn.12 is triggered ob both edges                         */
            __IO uint32_t IBS13 : 1; /*!< Interrupt on Pn.13 is triggered ob both edges                         */
            __IO uint32_t IBS14 : 1; /*!< Interrupt on Pn.14 is triggered ob both edges                         */
            __IO uint32_t IBS15 : 1; /*!< Interrupt on Pn.15 is triggered ob both edges                         */
        } IBS_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t IEV; /*!< Offset:0x14 GPIO Port n Interrupt Event Register                      */

        struct {
            __IO uint32_t IEV0 : 1;  /*!< Interrupt trigged evnet on Pn.0                                       */
            __IO uint32_t IEV1 : 1;  /*!< Interrupt trigged evnet on Pn.1                                       */
            __IO uint32_t IEV2 : 1;  /*!< Interrupt trigged evnet on Pn.2                                       */
            __IO uint32_t IEV3 : 1;  /*!< Interrupt trigged evnet on Pn.3                                       */
            __IO uint32_t IEV4 : 1;  /*!< Interrupt trigged evnet on Pn.4                                       */
            __IO uint32_t IEV5 : 1;  /*!< Interrupt trigged evnet on Pn.5                                       */
            __IO uint32_t IEV6 : 1;  /*!< Interrupt trigged evnet on Pn.6                                       */
            __IO uint32_t IEV7 : 1;  /*!< Interrupt trigged evnet on Pn.7                                       */
            __IO uint32_t IEV8 : 1;  /*!< Interrupt trigged evnet on Pn.8                                       */
            __IO uint32_t IEV9 : 1;  /*!< Interrupt trigged evnet on Pn.9                                       */
            __IO uint32_t IEV10 : 1; /*!< Interrupt trigged evnet on Pn.10                                      */
            __IO uint32_t IEV11 : 1; /*!< Interrupt trigged evnet on Pn.11                                      */
            __IO uint32_t IEV12 : 1; /*!< Interrupt trigged evnet on Pn.12                                      */
            __IO uint32_t IEV13 : 1; /*!< Interrupt trigged evnet on Pn.13                                      */
            __IO uint32_t IEV14 : 1; /*!< Interrupt trigged evnet on Pn.14                                      */
            __IO uint32_t IEV15 : 1; /*!< Interrupt trigged evnet on Pn.15                                      */
        } IEV_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t IE; /*!< Offset:0x18 GPIO Port n Interrupt Enable Register                     */

        struct {
            __IO uint32_t IE0 : 1;  /*!< Interrupt on Pn.0 enable                                              */
            __IO uint32_t IE1 : 1;  /*!< Interrupt on Pn.1 enable                                              */
            __IO uint32_t IE2 : 1;  /*!< Interrupt on Pn.2 enable                                              */
            __IO uint32_t IE3 : 1;  /*!< Interrupt on Pn.3 enable                                              */
            __IO uint32_t IE4 : 1;  /*!< Interrupt on Pn.4 enable                                              */
            __IO uint32_t IE5 : 1;  /*!< Interrupt on Pn.5 enable                                              */
            __IO uint32_t IE6 : 1;  /*!< Interrupt on Pn.6 enable                                              */
            __IO uint32_t IE7 : 1;  /*!< Interrupt on Pn.7 enable                                              */
            __IO uint32_t IE8 : 1;  /*!< Interrupt on Pn.8 enable                                              */
            __IO uint32_t IE9 : 1;  /*!< Interrupt on Pn.9 enable                                              */
            __IO uint32_t IE10 : 1; /*!< Interrupt on Pn.10 enable                                             */
            __IO uint32_t IE11 : 1; /*!< Interrupt on Pn.11 enable                                             */
            __IO uint32_t IE12 : 1; /*!< Interrupt on Pn.11 enable                                             */
            __IO uint32_t IE13 : 1; /*!< Interrupt on Pn.13 enable                                             */
            __IO uint32_t IE14 : 1; /*!< Interrupt on Pn.14 enable                                             */
            __IO uint32_t IE15 : 1; /*!< Interrupt on Pn.15 enable                                             */
        } IE_b;                     /*!< BitSize                                                               */
    };

    union {
        __I uint32_t RIS; /*!< Offset:0x1C GPIO Port n Raw Interrupt Status Register                 */

        struct {
            __I uint32_t IF0 : 1;  /*!< Pn.0 raw interrupt flag                                               */
            __I uint32_t IF1 : 1;  /*!< Pn.1 raw interrupt flag                                               */
            __I uint32_t IF2 : 1;  /*!< Pn.2 raw interrupt flag                                               */
            __I uint32_t IF3 : 1;  /*!< Pn.3 raw interrupt flag                                               */
            __I uint32_t IF4 : 1;  /*!< Pn.4 raw interrupt flag                                               */
            __I uint32_t IF5 : 1;  /*!< Pn.5 raw interrupt flag                                               */
            __I uint32_t IF6 : 1;  /*!< Pn.6 raw interrupt flag                                               */
            __I uint32_t IF7 : 1;  /*!< Pn.7 raw interrupt flag                                               */
            __I uint32_t IF8 : 1;  /*!< Pn.8 raw interrupt flag                                               */
            __I uint32_t IF9 : 1;  /*!< Pn.9 raw interrupt flag                                               */
            __I uint32_t IF10 : 1; /*!< Pn.10 raw interrupt flag                                              */
            __I uint32_t IF11 : 1; /*!< Pn.11 raw interrupt flag                                              */
            __I uint32_t IF12 : 1; /*!< Pn.12 raw interrupt flag                                              */
            __I uint32_t IF13 : 1; /*!< Pn.13 raw interrupt flag                                              */
            __I uint32_t IF14 : 1; /*!< Pn.14 raw interrupt flag                                              */
            __I uint32_t IF15 : 1; /*!< Pn.15 raw interrupt flag                                              */
        } RIS_b;                   /*!< BitSize                                                               */
    };

    union {
        __O uint32_t IC; /*!< Offset:0x20 GPIO Port n Interrupt Clear Register                      */

        struct {
            __O uint32_t IC0 : 1;  /*!< Pn.0 interrupt flag clear                                             */
            __O uint32_t IC1 : 1;  /*!< Pn.1 interrupt flag clear                                             */
            __O uint32_t IC2 : 1;  /*!< Pn.2 interrupt flag clear                                             */
            __O uint32_t IC3 : 1;  /*!< Pn.3 interrupt flag clear                                             */
            __O uint32_t IC4 : 1;  /*!< Pn.4 interrupt flag clear                                             */
            __O uint32_t IC5 : 1;  /*!< Pn.5 interrupt flag clear                                             */
            __O uint32_t IC6 : 1;  /*!< Pn.6 interrupt flag clear                                             */
            __O uint32_t IC7 : 1;  /*!< Pn.7 interrupt flag clear                                             */
            __O uint32_t IC8 : 1;  /*!< Pn.8 interrupt flag clear                                             */
            __O uint32_t IC9 : 1;  /*!< Pn.9 interrupt flag clear                                             */
            __O uint32_t IC10 : 1; /*!< Pn.10 interrupt flag clear                                            */
            __O uint32_t IC11 : 1; /*!< Pn.11 interrupt flag clear                                            */
            __O uint32_t IC12 : 1; /*!< Pn.12 interrupt flag clear                                            */
            __O uint32_t IC13 : 1; /*!< Pn.13 interrupt flag clear                                            */
            __O uint32_t IC14 : 1; /*!< Pn.14 interrupt flag clear                                            */
            __O uint32_t IC15 : 1; /*!< Pn.15 interrupt flag clear                                            */
        } IC_b;                    /*!< BitSize                                                               */
    };

    union {
        __O uint32_t BSET; /*!< Offset:0x24 GPIO Port n Bits Set Operation Register                   */

        struct {
            __O uint32_t BSET0 : 1;  /*!< Set Pn.0                                                              */
            __O uint32_t BSET1 : 1;  /*!< Set Pn.1                                                              */
            __O uint32_t BSET2 : 1;  /*!< Set Pn.2                                                              */
            __O uint32_t BSET3 : 1;  /*!< Set Pn.3                                                              */
            __O uint32_t BSET4 : 1;  /*!< Set Pn.4                                                              */
            __O uint32_t BSET5 : 1;  /*!< Set Pn.5                                                              */
            __O uint32_t BSET6 : 1;  /*!< Set Pn.6                                                              */
            __O uint32_t BSET7 : 1;  /*!< Set Pn.7                                                              */
            __O uint32_t BSET8 : 1;  /*!< Set Pn.8                                                              */
            __O uint32_t BSET9 : 1;  /*!< Set Pn.9                                                              */
            __O uint32_t BSET10 : 1; /*!< Set Pn.10                                                             */
            __O uint32_t BSET11 : 1; /*!< Set Pn.11                                                             */
            __O uint32_t BSET12 : 1; /*!< Set Pn.12                                                             */
            __O uint32_t BSET13 : 1; /*!< Set Pn.13                                                             */
            __O uint32_t BSET14 : 1; /*!< Set Pn.14                                                             */
            __O uint32_t BSET15 : 1; /*!< Set Pn.15                                                             */
        } BSET_b;                    /*!< BitSize                                                               */
    };

    union {
        __O uint32_t BCLR; /*!< Offset:0x28 GPIO Port n Bits Clear Operation Register                 */

        struct {
            __O uint32_t BCLR0 : 1;  /*!< Clear Pn.0                                                            */
            __O uint32_t BCLR1 : 1;  /*!< Clear Pn.1                                                            */
            __O uint32_t BCLR2 : 1;  /*!< Clear Pn.2                                                            */
            __O uint32_t BCLR3 : 1;  /*!< Clear Pn.3                                                            */
            __O uint32_t BCLR4 : 1;  /*!< Clear Pn.4                                                            */
            __O uint32_t BCLR5 : 1;  /*!< Clear Pn.5                                                            */
            __O uint32_t BCLR6 : 1;  /*!< Clear Pn.6                                                            */
            __O uint32_t BCLR7 : 1;  /*!< Clear Pn.7                                                            */
            __O uint32_t BCLR8 : 1;  /*!< Clear Pn.8                                                            */
            __O uint32_t BCLR9 : 1;  /*!< Clear Pn.9                                                            */
            __O uint32_t BCLR10 : 1; /*!< Clear Pn.10                                                           */
            __O uint32_t BCLR11 : 1; /*!< Clear Pn.11                                                           */
            __O uint32_t BCLR12 : 1; /*!< Clear Pn.12                                                           */
            __O uint32_t BCLR13 : 1; /*!< Clear Pn.13                                                           */
            __O uint32_t BCLR14 : 1; /*!< Clear Pn.14                                                           */
            __O uint32_t BCLR15 : 1; /*!< Clear Pn.15                                                           */
        } BCLR_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t ODCTRL; /*!< Offset:0x2C GPIO Port n Open-drain Control Register                   */

        struct {
            __IO uint32_t OC0 : 1;  /*!< Pn.0 open-drain control                                               */
            __IO uint32_t OC1 : 1;  /*!< Pn.1 open-drain control                                               */
            __IO uint32_t OC2 : 1;  /*!< Pn.2 open-drain control                                               */
            __IO uint32_t OC3 : 1;  /*!< Pn.3 open-drain control                                               */
            __IO uint32_t OC4 : 1;  /*!< Pn.4 open-drain control                                               */
            __IO uint32_t OC5 : 1;  /*!< Pn.5 open-drain control                                               */
            __IO uint32_t OC6 : 1;  /*!< Pn.6 open-drain control                                               */
            __IO uint32_t OC7 : 1;  /*!< Pn.7 open-drain control                                               */
            __IO uint32_t OC8 : 1;  /*!< Pn.8 open-drain control                                               */
            __IO uint32_t OC9 : 1;  /*!< Pn.9 open-drain control                                               */
            __IO uint32_t OC10 : 1; /*!< Pn.10 open-drain control                                              */
            __IO uint32_t OC11 : 1; /*!< Pn.11 open-drain control                                              */
            __IO uint32_t OC12 : 1; /*!< Pn.12 open-drain control                                              */
            __IO uint32_t OC13 : 1; /*!< Pn.13 open-drain control                                              */
            __IO uint32_t OC14 : 1; /*!< Pn.14 open-drain control                                              */
            __IO uint32_t OC15 : 1; /*!< Pn.15 open-drain control                                              */
        } ODCTRL_b;                 /*!< BitSize                                                               */
    };
} SN_GPIO0_Type;

/* ================================================================================ */
/* ================                    SN_GPIO2                    ================ */
/* ================================================================================ */

/**
 * @brief General Purpose I/O (SN_GPIO2)
 */

typedef struct { /*!< SN_GPIO2 Structure                                                    */

    union {
        __IO uint32_t DATA; /*!< Offset:0x00 GPIO Port n Data Register                                 */

        struct {
            __IO uint32_t DATA0 : 1;  /*!< Data of Pn.0                                                          */
            __IO uint32_t DATA1 : 1;  /*!< Data of Pn.1                                                          */
            __IO uint32_t DATA2 : 1;  /*!< Data of Pn.2                                                          */
            __IO uint32_t DATA3 : 1;  /*!< Data of Pn.3                                                          */
            __IO uint32_t DATA4 : 1;  /*!< Data of Pn.4                                                          */
            __IO uint32_t DATA5 : 1;  /*!< Data of Pn.5                                                          */
            __IO uint32_t DATA6 : 1;  /*!< Data of Pn.6                                                          */
            __IO uint32_t DATA7 : 1;  /*!< Data of Pn.7                                                          */
            __IO uint32_t DATA8 : 1;  /*!< Data of Pn.8                                                          */
            __IO uint32_t DATA9 : 1;  /*!< Data of Pn.9                                                          */
            __IO uint32_t DATA10 : 1; /*!< Data of Pn.10                                                         */
            __IO uint32_t DATA11 : 1; /*!< Data of Pn.11                                                         */
            __IO uint32_t DATA12 : 1; /*!< Data of Pn.12                                                         */
            __IO uint32_t DATA13 : 1; /*!< Data of Pn.13                                                         */
            __IO uint32_t DATA14 : 1; /*!< Data of Pn.14                                                         */
            __IO uint32_t DATA15 : 1; /*!< Data of Pn.15                                                         */
        } DATA_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t MODE; /*!< Offset:0x04 GPIO Port n Mode Register                                 */

        struct {
            __IO uint32_t MODE0 : 1;     /*!< Mode of Pn.0                                                          */
            __IO uint32_t MODE1 : 1;     /*!< Mode of Pn.1                                                          */
            __IO uint32_t MODE2 : 1;     /*!< Mode of Pn.2                                                          */
            __IO uint32_t MODE3 : 1;     /*!< Mode of Pn.3                                                          */
            __IO uint32_t MODE4 : 1;     /*!< Mode of Pn.4                                                          */
            __IO uint32_t MODE5 : 1;     /*!< Mode of Pn.5                                                          */
            __IO uint32_t MODE6 : 1;     /*!< Mode of Pn.6                                                          */
            __IO uint32_t MODE7 : 1;     /*!< Mode of Pn.7                                                          */
            __IO uint32_t MODE8 : 1;     /*!< Mode of Pn.8                                                          */
            __IO uint32_t MODE9 : 1;     /*!< Mode of Pn.9                                                          */
            __IO uint32_t MODE10 : 1;    /*!< Mode of Pn.10                                                         */
            __IO uint32_t MODE11 : 1;    /*!< Mode of Pn.11                                                         */
            __IO uint32_t MODE12 : 1;    /*!< Mode of Pn.12                                                         */
            __IO uint32_t MODE13 : 1;    /*!< Mode of Pn.13                                                         */
            __IO uint32_t MODE14 : 1;    /*!< Mode of Pn.14                                                         */
            __IO uint32_t MODE15 : 1;    /*!< Mode of Pn.15                                                         */
            __IO uint32_t CURRENT0 : 1;  /*!< Driving/Sinking current of Pn.0                                       */
            __IO uint32_t CURRENT1 : 1;  /*!< Driving/Sinking current of Pn.1                                       */
            __IO uint32_t CURRENT2 : 1;  /*!< Driving/Sinking current of Pn.2                                       */
            __IO uint32_t CURRENT3 : 1;  /*!< Driving/Sinking current of Pn.3                                       */
            __IO uint32_t CURRENT4 : 1;  /*!< Driving/Sinking current of Pn.4                                       */
            __IO uint32_t CURRENT5 : 1;  /*!< Driving/Sinking current of Pn.5                                       */
            __IO uint32_t CURRENT6 : 1;  /*!< Driving/Sinking current of Pn.6                                       */
            __IO uint32_t CURRENT7 : 1;  /*!< Driving/Sinking current of Pn.7                                       */
            __IO uint32_t CURRENT8 : 1;  /*!< Driving/Sinking current of Pn.8                                       */
            __IO uint32_t CURRENT9 : 1;  /*!< Driving/Sinking current of Pn.9                                       */
            __IO uint32_t CURRENT10 : 1; /*!< Driving/Sinking current of Pn.10                                      */
            __IO uint32_t CURRENT11 : 1; /*!< Driving/Sinking current of Pn.11                                      */
            __IO uint32_t CURRENT12 : 1; /*!< Driving/Sinking current of Pn.12                                      */
            __IO uint32_t CURRENT13 : 1; /*!< Driving/Sinking current of Pn.13                                      */
            __IO uint32_t CURRENT14 : 1; /*!< Driving/Sinking current of Pn.14                                      */
            __IO uint32_t CURRENT15 : 1; /*!< Driving/Sinking current of Pn.15                                      */
        } MODE_b;                        /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CFG; /*!< Offset:0x08 GPIO Port n Configuration Register                        */

        struct {
            __IO uint32_t CFG0 : 2;  /*!< Configuration of Pn.0                                                 */
            __IO uint32_t CFG1 : 2;  /*!< Configuration of Pn.1                                                 */
            __IO uint32_t CFG2 : 2;  /*!< Configuration of Pn.2                                                 */
            __IO uint32_t CFG3 : 2;  /*!< Configuration of Pn.3                                                 */
            __IO uint32_t CFG4 : 2;  /*!< Configuration of Pn.4                                                 */
            __IO uint32_t CFG5 : 2;  /*!< Configuration of Pn.5                                                 */
            __IO uint32_t CFG6 : 2;  /*!< Configuration of Pn.6                                                 */
            __IO uint32_t CFG7 : 2;  /*!< Configuration of Pn.7                                                 */
            __IO uint32_t CFG8 : 2;  /*!< Configuration of Pn.8                                                 */
            __IO uint32_t CFG9 : 2;  /*!< Configuration of Pn.9                                                 */
            __IO uint32_t CFG10 : 2; /*!< Configuration of Pn.10                                                */
            __IO uint32_t CFG11 : 2; /*!< Configuration of Pn.11                                                */
            __IO uint32_t CFG12 : 2; /*!< Configuration of Pn.12                                                */
            __IO uint32_t CFG13 : 2; /*!< Configuration of Pn.13                                                */
            __IO uint32_t CFG14 : 2; /*!< Configuration of Pn.14                                                */
            __IO uint32_t CFG15 : 2; /*!< Configuration of Pn.15                                                */
        } CFG_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t IS; /*!< Offset:0x0C GPIO Port n Interrupt Sense Register                      */

        struct {
            __IO uint32_t IS0 : 1;  /*!< Interrupt on Pn.0 is event or edge sensitive                          */
            __IO uint32_t IS1 : 1;  /*!< Interrupt on Pn.1 is event or edge sensitive                          */
            __IO uint32_t IS2 : 1;  /*!< Interrupt on Pn.2 is event or edge sensitive                          */
            __IO uint32_t IS3 : 1;  /*!< Interrupt on Pn.3 is event or edge sensitive                          */
            __IO uint32_t IS4 : 1;  /*!< Interrupt on Pn.4 is event or edge sensitive                          */
            __IO uint32_t IS5 : 1;  /*!< Interrupt on Pn.5 is event or edge sensitive                          */
            __IO uint32_t IS6 : 1;  /*!< Interrupt on Pn.6 is event or edge sensitive                          */
            __IO uint32_t IS7 : 1;  /*!< Interrupt on Pn.7 is event or edge sensitive                          */
            __IO uint32_t IS8 : 1;  /*!< Interrupt on Pn.8 is event or edge sensitive                          */
            __IO uint32_t IS9 : 1;  /*!< Interrupt on Pn.9 is event or edge sensitive                          */
            __IO uint32_t IS10 : 1; /*!< Interrupt on Pn.10 is event or edge sensitive                         */
            __IO uint32_t IS11 : 1; /*!< Interrupt on Pn.11 is event or edge sensitive                         */
            __IO uint32_t IS12 : 1; /*!< Interrupt on Pn.12 is event or edge sensitive                         */
            __IO uint32_t IS13 : 1; /*!< Interrupt on Pn.13 is event or edge sensitive                         */
            __IO uint32_t IS14 : 1; /*!< Interrupt on Pn.14 is event or edge sensitive                         */
            __IO uint32_t IS15 : 1; /*!< Interrupt on Pn.15 is event or edge sensitive                         */
        } IS_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t IBS; /*!< Offset:0x10 GPIO Port n Interrupt Both-edge Sense Register            */

        struct {
            __IO uint32_t IBS0 : 1;  /*!< Interrupt on Pn.0 is triggered ob both edges                          */
            __IO uint32_t IBS1 : 1;  /*!< Interrupt on Pn.1 is triggered ob both edges                          */
            __IO uint32_t IBS2 : 1;  /*!< Interrupt on Pn.2 is triggered ob both edges                          */
            __IO uint32_t IBS3 : 1;  /*!< Interrupt on Pn.3 is triggered ob both edges                          */
            __IO uint32_t IBS4 : 1;  /*!< Interrupt on Pn.4 is triggered ob both edges                          */
            __IO uint32_t IBS5 : 1;  /*!< Interrupt on Pn.5 is triggered ob both edges                          */
            __IO uint32_t IBS6 : 1;  /*!< Interrupt on Pn.6 is triggered ob both edges                          */
            __IO uint32_t IBS7 : 1;  /*!< Interrupt on Pn.7 is triggered ob both edges                          */
            __IO uint32_t IBS8 : 1;  /*!< Interrupt on Pn.8 is triggered ob both edges                          */
            __IO uint32_t IBS9 : 1;  /*!< Interrupt on Pn.9 is triggered ob both edges                          */
            __IO uint32_t IBS10 : 1; /*!< Interrupt on Pn.10 is triggered ob both edges                         */
            __IO uint32_t IBS11 : 1; /*!< Interrupt on Pn.11 is triggered ob both edges                         */
            __IO uint32_t IBS12 : 1; /*!< Interrupt on Pn.12 is triggered ob both edges                         */
            __IO uint32_t IBS13 : 1; /*!< Interrupt on Pn.13 is triggered ob both edges                         */
            __IO uint32_t IBS14 : 1; /*!< Interrupt on Pn.14 is triggered ob both edges                         */
            __IO uint32_t IBS15 : 1; /*!< Interrupt on Pn.15 is triggered ob both edges                         */
        } IBS_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t IEV; /*!< Offset:0x14 GPIO Port n Interrupt Event Register                      */

        struct {
            __IO uint32_t IEV0 : 1;  /*!< Interrupt trigged evnet on Pn.0                                       */
            __IO uint32_t IEV1 : 1;  /*!< Interrupt trigged evnet on Pn.1                                       */
            __IO uint32_t IEV2 : 1;  /*!< Interrupt trigged evnet on Pn.2                                       */
            __IO uint32_t IEV3 : 1;  /*!< Interrupt trigged evnet on Pn.3                                       */
            __IO uint32_t IEV4 : 1;  /*!< Interrupt trigged evnet on Pn.4                                       */
            __IO uint32_t IEV5 : 1;  /*!< Interrupt trigged evnet on Pn.5                                       */
            __IO uint32_t IEV6 : 1;  /*!< Interrupt trigged evnet on Pn.6                                       */
            __IO uint32_t IEV7 : 1;  /*!< Interrupt trigged evnet on Pn.7                                       */
            __IO uint32_t IEV8 : 1;  /*!< Interrupt trigged evnet on Pn.8                                       */
            __IO uint32_t IEV9 : 1;  /*!< Interrupt trigged evnet on Pn.9                                       */
            __IO uint32_t IEV10 : 1; /*!< Interrupt trigged evnet on Pn.10                                      */
            __IO uint32_t IEV11 : 1; /*!< Interrupt trigged evnet on Pn.11                                      */
            __IO uint32_t IEV12 : 1; /*!< Interrupt trigged evnet on Pn.12                                      */
            __IO uint32_t IEV13 : 1; /*!< Interrupt trigged evnet on Pn.13                                      */
            __IO uint32_t IEV14 : 1; /*!< Interrupt trigged evnet on Pn.14                                      */
            __IO uint32_t IEV15 : 1; /*!< Interrupt trigged evnet on Pn.15                                      */
        } IEV_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t IE; /*!< Offset:0x18 GPIO Port n Interrupt Enable Register                     */

        struct {
            __IO uint32_t IE0 : 1;  /*!< Interrupt on Pn.0 enable                                              */
            __IO uint32_t IE1 : 1;  /*!< Interrupt on Pn.1 enable                                              */
            __IO uint32_t IE2 : 1;  /*!< Interrupt on Pn.2 enable                                              */
            __IO uint32_t IE3 : 1;  /*!< Interrupt on Pn.3 enable                                              */
            __IO uint32_t IE4 : 1;  /*!< Interrupt on Pn.4 enable                                              */
            __IO uint32_t IE5 : 1;  /*!< Interrupt on Pn.5 enable                                              */
            __IO uint32_t IE6 : 1;  /*!< Interrupt on Pn.6 enable                                              */
            __IO uint32_t IE7 : 1;  /*!< Interrupt on Pn.7 enable                                              */
            __IO uint32_t IE8 : 1;  /*!< Interrupt on Pn.8 enable                                              */
            __IO uint32_t IE9 : 1;  /*!< Interrupt on Pn.9 enable                                              */
            __IO uint32_t IE10 : 1; /*!< Interrupt on Pn.10 enable                                             */
            __IO uint32_t IE11 : 1; /*!< Interrupt on Pn.11 enable                                             */
            __IO uint32_t IE12 : 1; /*!< Interrupt on Pn.11 enable                                             */
            __IO uint32_t IE13 : 1; /*!< Interrupt on Pn.13 enable                                             */
            __IO uint32_t IE14 : 1; /*!< Interrupt on Pn.14 enable                                             */
            __IO uint32_t IE15 : 1; /*!< Interrupt on Pn.15 enable                                             */
        } IE_b;                     /*!< BitSize                                                               */
    };

    union {
        __I uint32_t RIS; /*!< Offset:0x1C GPIO Port n Raw Interrupt Status Register                 */

        struct {
            __I uint32_t IF0 : 1;  /*!< Pn.0 raw interrupt flag                                               */
            __I uint32_t IF1 : 1;  /*!< Pn.1 raw interrupt flag                                               */
            __I uint32_t IF2 : 1;  /*!< Pn.2 raw interrupt flag                                               */
            __I uint32_t IF3 : 1;  /*!< Pn.3 raw interrupt flag                                               */
            __I uint32_t IF4 : 1;  /*!< Pn.4 raw interrupt flag                                               */
            __I uint32_t IF5 : 1;  /*!< Pn.5 raw interrupt flag                                               */
            __I uint32_t IF6 : 1;  /*!< Pn.6 raw interrupt flag                                               */
            __I uint32_t IF7 : 1;  /*!< Pn.7 raw interrupt flag                                               */
            __I uint32_t IF8 : 1;  /*!< Pn.8 raw interrupt flag                                               */
            __I uint32_t IF9 : 1;  /*!< Pn.9 raw interrupt flag                                               */
            __I uint32_t IF10 : 1; /*!< Pn.10 raw interrupt flag                                              */
            __I uint32_t IF11 : 1; /*!< Pn.11 raw interrupt flag                                              */
            __I uint32_t IF12 : 1; /*!< Pn.12 raw interrupt flag                                              */
            __I uint32_t IF13 : 1; /*!< Pn.13 raw interrupt flag                                              */
            __I uint32_t IF14 : 1; /*!< Pn.14 raw interrupt flag                                              */
            __I uint32_t IF15 : 1; /*!< Pn.15 raw interrupt flag                                              */
        } RIS_b;                   /*!< BitSize                                                               */
    };

    union {
        __O uint32_t IC; /*!< Offset:0x20 GPIO Port n Interrupt Clear Register                      */

        struct {
            __O uint32_t IC0 : 1;  /*!< Pn.0 interrupt flag clear                                             */
            __O uint32_t IC1 : 1;  /*!< Pn.1 interrupt flag clear                                             */
            __O uint32_t IC2 : 1;  /*!< Pn.2 interrupt flag clear                                             */
            __O uint32_t IC3 : 1;  /*!< Pn.3 interrupt flag clear                                             */
            __O uint32_t IC4 : 1;  /*!< Pn.4 interrupt flag clear                                             */
            __O uint32_t IC5 : 1;  /*!< Pn.5 interrupt flag clear                                             */
            __O uint32_t IC6 : 1;  /*!< Pn.6 interrupt flag clear                                             */
            __O uint32_t IC7 : 1;  /*!< Pn.7 interrupt flag clear                                             */
            __O uint32_t IC8 : 1;  /*!< Pn.8 interrupt flag clear                                             */
            __O uint32_t IC9 : 1;  /*!< Pn.9 interrupt flag clear                                             */
            __O uint32_t IC10 : 1; /*!< Pn.10 interrupt flag clear                                            */
            __O uint32_t IC11 : 1; /*!< Pn.11 interrupt flag clear                                            */
            __O uint32_t IC12 : 1; /*!< Pn.12 interrupt flag clear                                            */
            __O uint32_t IC13 : 1; /*!< Pn.13 interrupt flag clear                                            */
            __O uint32_t IC14 : 1; /*!< Pn.14 interrupt flag clear                                            */
            __O uint32_t IC15 : 1; /*!< Pn.15 interrupt flag clear                                            */
        } IC_b;                    /*!< BitSize                                                               */
    };

    union {
        __O uint32_t BSET; /*!< Offset:0x24 GPIO Port n Bits Set Operation Register                   */

        struct {
            __O uint32_t BSET0 : 1;  /*!< Set Pn.0                                                              */
            __O uint32_t BSET1 : 1;  /*!< Set Pn.1                                                              */
            __O uint32_t BSET2 : 1;  /*!< Set Pn.2                                                              */
            __O uint32_t BSET3 : 1;  /*!< Set Pn.3                                                              */
            __O uint32_t BSET4 : 1;  /*!< Set Pn.4                                                              */
            __O uint32_t BSET5 : 1;  /*!< Set Pn.5                                                              */
            __O uint32_t BSET6 : 1;  /*!< Set Pn.6                                                              */
            __O uint32_t BSET7 : 1;  /*!< Set Pn.7                                                              */
            __O uint32_t BSET8 : 1;  /*!< Set Pn.8                                                              */
            __O uint32_t BSET9 : 1;  /*!< Set Pn.9                                                              */
            __O uint32_t BSET10 : 1; /*!< Set Pn.10                                                             */
            __O uint32_t BSET11 : 1; /*!< Set Pn.11                                                             */
            __O uint32_t BSET12 : 1; /*!< Set Pn.12                                                             */
            __O uint32_t BSET13 : 1; /*!< Set Pn.13                                                             */
            __O uint32_t BSET14 : 1; /*!< Set Pn.14                                                             */
            __O uint32_t BSET15 : 1; /*!< Set Pn.15                                                             */
        } BSET_b;                    /*!< BitSize                                                               */
    };

    union {
        __O uint32_t BCLR; /*!< Offset:0x28 GPIO Port n Bits Clear Operation Register                 */

        struct {
            __O uint32_t BCLR0 : 1;  /*!< Clear Pn.0                                                            */
            __O uint32_t BCLR1 : 1;  /*!< Clear Pn.1                                                            */
            __O uint32_t BCLR2 : 1;  /*!< Clear Pn.2                                                            */
            __O uint32_t BCLR3 : 1;  /*!< Clear Pn.3                                                            */
            __O uint32_t BCLR4 : 1;  /*!< Clear Pn.4                                                            */
            __O uint32_t BCLR5 : 1;  /*!< Clear Pn.5                                                            */
            __O uint32_t BCLR6 : 1;  /*!< Clear Pn.6                                                            */
            __O uint32_t BCLR7 : 1;  /*!< Clear Pn.7                                                            */
            __O uint32_t BCLR8 : 1;  /*!< Clear Pn.8                                                            */
            __O uint32_t BCLR9 : 1;  /*!< Clear Pn.9                                                            */
            __O uint32_t BCLR10 : 1; /*!< Clear Pn.10                                                           */
            __O uint32_t BCLR11 : 1; /*!< Clear Pn.11                                                           */
            __O uint32_t BCLR12 : 1; /*!< Clear Pn.12                                                           */
            __O uint32_t BCLR13 : 1; /*!< Clear Pn.13                                                           */
            __O uint32_t BCLR14 : 1; /*!< Clear Pn.14                                                           */
            __O uint32_t BCLR15 : 1; /*!< Clear Pn.15                                                           */
        } BCLR_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t ODCTRL; /*!< Offset:0x2C GPIO Port n Open-drain Control Register                   */

        struct {
            __IO uint32_t OC0 : 1;  /*!< Pn.0 open-drain control                                               */
            __IO uint32_t OC1 : 1;  /*!< Pn.1 open-drain control                                               */
            __IO uint32_t OC2 : 1;  /*!< Pn.2 open-drain control                                               */
            __IO uint32_t OC3 : 1;  /*!< Pn.3 open-drain control                                               */
            __IO uint32_t OC4 : 1;  /*!< Pn.4 open-drain control                                               */
            __IO uint32_t OC5 : 1;  /*!< Pn.5 open-drain control                                               */
            __IO uint32_t OC6 : 1;  /*!< Pn.6 open-drain control                                               */
            __IO uint32_t OC7 : 1;  /*!< Pn.7 open-drain control                                               */
            __IO uint32_t OC8 : 1;  /*!< Pn.8 open-drain control                                               */
            __IO uint32_t OC9 : 1;  /*!< Pn.9 open-drain control                                               */
            __IO uint32_t OC10 : 1; /*!< Pn.10 open-drain control                                              */
            __IO uint32_t OC11 : 1; /*!< Pn.11 open-drain control                                              */
            __IO uint32_t OC12 : 1; /*!< Pn.12 open-drain control                                              */
            __IO uint32_t OC13 : 1; /*!< Pn.13 open-drain control                                              */
            __IO uint32_t OC14 : 1; /*!< Pn.14 open-drain control                                              */
            __IO uint32_t OC15 : 1; /*!< Pn.15 open-drain control                                              */
        } ODCTRL_b;                 /*!< BitSize                                                               */
    };
} SN_GPIO2_Type;

/* ================================================================================ */
/* ================                     SN_ADC                     ================ */
/* ================================================================================ */

/**
 * @brief ADC (SN_ADC)
 */

typedef struct { /*!< SN_ADC Structure                                                      */

    union {
        __IO uint32_t ADM; /*!< Offset:0x00 ADC Management Register                                   */

        struct {
            __IO uint32_t CHS : 4;       /*!< ADC input channel                                                     */
            __IO uint32_t GCHS : 1;      /*!< ADC global channel enable                                             */
            __IO uint32_t EOC : 1;       /*!< ADC status                                                            */
            __IO uint32_t ADS : 1;       /*!< ADC start control                                                     */
            __IO uint32_t ADLEN : 1;     /*!< ADC resolution                                                        */
            __IO uint32_t ADCKS : 3;     /*!< ADC clock source divider                                              */
            __IO uint32_t ADENB : 1;     /*!< ADC enable                                                            */
            __IO uint32_t AVREFHSEL : 1; /*!< ADC high reference voltage source                                     */
            uint32_t : 4;
            __IO uint32_t TSENB : 1; /*!< Temperature sensor enable bit                                         */
        } ADM_b;                     /*!< BitSize                                                               */
    };
    __I uint32_t ADB; /*!< Offset:0x04 ADC Data Register                                         */

    union {
        __I uint32_t P2CON; /*!< Offset:0x08 ADC Port 2 Control Register                               */

        struct {
            __I uint32_t P2CON0 : 1;  /*!< P2.0 Control                                                          */
            __I uint32_t P2CON1 : 1;  /*!< P2.1 Control                                                          */
            __I uint32_t P2CON2 : 1;  /*!< P2.2 Control                                                          */
            __I uint32_t P2CON3 : 1;  /*!< P2.3 Control                                                          */
            __I uint32_t P2CON4 : 1;  /*!< P2.4 Control                                                          */
            __I uint32_t P2CON5 : 1;  /*!< P2.5 Control                                                          */
            __I uint32_t P2CON6 : 1;  /*!< P2.6 Control                                                          */
            __I uint32_t P2CON7 : 1;  /*!< P2.7 Control                                                          */
            __I uint32_t P2CON8 : 1;  /*!< P2.8 Control                                                          */
            __I uint32_t P2CON9 : 1;  /*!< P2.9 Control                                                          */
            __I uint32_t P2CON10 : 1; /*!< P2.10 Control                                                         */
            __I uint32_t P2CON11 : 1; /*!< P2.11 Control                                                         */
            __I uint32_t P2CON12 : 1; /*!< P2.12 Control                                                         */
            __I uint32_t P2CON13 : 1; /*!< P2.13 Control                                                         */
            __I uint32_t P2CON14 : 1; /*!< P2.14 Control                                                         */
            __I uint32_t P2CON15 : 1; /*!< P2.15 Control                                                         */
        } P2CON_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t IE; /*!< Offset:0x0C ADC Interrupt Enable Register                             */

        struct {
            __IO uint32_t IE0 : 1;  /*!< AIN0 interrupt enable                                                 */
            __IO uint32_t IE1 : 1;  /*!< AIN1 interrupt enable                                                 */
            __IO uint32_t IE2 : 1;  /*!< AIN2 interrupt enable                                                 */
            __IO uint32_t IE3 : 1;  /*!< AIN3 interrupt enable                                                 */
            __IO uint32_t IE4 : 1;  /*!< AIN4 interrupt enable                                                 */
            __IO uint32_t IE5 : 1;  /*!< AIN5 interrupt enable                                                 */
            __IO uint32_t IE6 : 1;  /*!< AIN6 interrupt enable                                                 */
            __IO uint32_t IE7 : 1;  /*!< AIN7 interrupt enable                                                 */
            __IO uint32_t IE8 : 1;  /*!< AIN8 interrupt enable                                                 */
            __IO uint32_t IE9 : 1;  /*!< AIN9 interrupt enable                                                 */
            __IO uint32_t IE10 : 1; /*!< AIN10 interrupt enable                                                */
            __IO uint32_t IE11 : 1; /*!< AIN11 interrupt enable                                                */
            __IO uint32_t IE12 : 1; /*!< AIN12 interrupt enable                                                */
            __IO uint32_t IE13 : 1; /*!< AIN13 interrupt enable                                                */
            __IO uint32_t IE14 : 1; /*!< AIN14 interrupt enable                                                */
        } IE_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t RIS; /*!< Offset:0x10 ADC Raw Interrupt Status Register                         */

        struct {
            __IO uint32_t IF0 : 1;  /*!< AIN0 interrupt flag                                                   */
            __IO uint32_t IF1 : 1;  /*!< AIN1 interrupt flag                                                   */
            __IO uint32_t IF2 : 1;  /*!< AIN2 interrupt flag                                                   */
            __IO uint32_t IF3 : 1;  /*!< AIN0 interrupt flag                                                   */
            __IO uint32_t IF4 : 1;  /*!< AIN4 interrupt flag                                                   */
            __IO uint32_t IF5 : 1;  /*!< AIN5 interrupt flag                                                   */
            __IO uint32_t IF6 : 1;  /*!< AIN6 interrupt flag                                                   */
            __IO uint32_t IF7 : 1;  /*!< AIN7 interrupt flag                                                   */
            __IO uint32_t IF8 : 1;  /*!< AIN8 interrupt flag                                                   */
            __IO uint32_t IF9 : 1;  /*!< AIN9 interrupt flag                                                   */
            __IO uint32_t IF10 : 1; /*!< AIN10 interrupt flag                                                  */
            __IO uint32_t IF11 : 1; /*!< AIN11 interrupt flag                                                  */
            __IO uint32_t IF12 : 1; /*!< AIN12 interrupt flag                                                  */
            __IO uint32_t IF13 : 1; /*!< AIN13 interrupt flag                                                  */
            __IO uint32_t IF14 : 1; /*!< AIN14 interrupt flag                                                  */
        } RIS_b;                    /*!< BitSize                                                               */
    };
} SN_ADC_Type;

/* ================================================================================ */
/* ================                     SN_WDT                     ================ */
/* ================================================================================ */

/**
 * @brief Watchdog Timer (SN_WDT)
 */

typedef struct { /*!< SN_WDT Structure                                                      */

    union {
        __IO uint32_t CFG; /*!< Offset:0x00 WDT Configuration Register                                */

        struct {
            __IO uint32_t WDTEN : 1;  /*!< WDT enable                                                            */
            __IO uint32_t WDTIE : 1;  /*!< WDT interrupt enable                                                  */
            __IO uint32_t WDTINT : 1; /*!< WDT interrupt flag                                                    */
            uint32_t : 13;
            __O uint32_t WDKEY : 16; /*!< WDT register key                                                      */
        } CFG_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CLKSOURCE; /*!< Offset:0x04 WDT Clock Source Register                                 */

        struct {
            __IO uint32_t CLKSEL : 2; /*!< WDT clock source                                                      */
            uint32_t : 14;
            __O uint32_t WDKEY : 16; /*!< WDT register key                                                      */
        } CLKSOURCE_b;               /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t TC; /*!< Offset:0x08 WDT Timer Constant Register                               */

        struct {
            __IO uint32_t TC : 8; /*!< Watchdog timer constant reload value                                  */
            uint32_t : 8;
            __O uint32_t WDKEY : 16; /*!< WDT register key                                                      */
        } TC_b;                      /*!< BitSize                                                               */
    };

    union {
        __O uint32_t FEED; /*!< Offset:0x0C WDT Feed Register                                         */

        struct {
            __O uint32_t FV : 16;    /*!< Watchdog feed value                                                   */
            __O uint32_t WDKEY : 16; /*!< WDT register key                                                      */
        } FEED_b;                    /*!< BitSize                                                               */
    };
} SN_WDT_Type;

/* ================================================================================ */
/* ================                     SN_RTC                     ================ */
/* ================================================================================ */

/**
 * @brief Real-time Clock (SN_RTC)
 */

typedef struct { /*!< SN_RTC Structure                                                      */

    union {
        __IO uint32_t CTRL; /*!< Offset:0x00 RTC Control Register                                      */

        struct {
            __IO uint32_t RTCEN : 1; /*!< RTC enable                                                            */
        } CTRL_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CLKS; /*!< Offset:0x04 RTC Clock Source Register                                 */

        struct {
            __IO uint32_t CLKSEL : 2; /*!< RTC clock source                                                      */
        } CLKS_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t IE; /*!< Offset:0x08 RTC Interrupt Enable Register                             */

        struct {
            __IO uint32_t SECIE : 1; /*!< Second interrupt enable                                               */
            __IO uint32_t ALMIE : 1; /*!< Alarm interrupt enable                                                */
            __IO uint32_t OVFIE : 1; /*!< Overflow interrupt enable                                             */
        } IE_b;                      /*!< BitSize                                                               */
    };

    union {
        __I uint32_t RIS; /*!< Offset:0x0C RTC Raw Interrupt Status Register                         */

        struct {
            __I uint32_t SECIF : 1; /*!< Second interrupt flag                                                 */
            __I uint32_t ALMIF : 1; /*!< Alarm interrupt flag                                                  */
            __I uint32_t OVFIF : 1; /*!< Overflow interrupt flag                                               */
        } RIS_b;                    /*!< BitSize                                                               */
    };

    union {
        __O uint32_t IC; /*!< Offset:0x10 RTC Interrupt Clear Register                              */

        struct {
            __O uint32_t SECIC : 1; /*!< Second interrupt flag clear                                           */
            __O uint32_t ALMIC : 1; /*!< Alarm interrupt flag clear                                            */
            __O uint32_t OVFIC : 1; /*!< Overflow interrupt flag clear                                         */
        } IC_b;                     /*!< BitSize                                                               */
    };
    __IO uint32_t SECCNTV; /*!< Offset:0x14 RTC Second Counter Reload Value Register                  */
    __I uint32_t  SECCNT;  /*!< Offset:0x18 RTC Second Counter Register                               */
    __IO uint32_t ALMCNTV; /*!< Offset:0x1C RTC Alarm Counter Reload Value Register                   */
    __I uint32_t  ALMCNT;  /*!< Offset:0x20 RTC Alarm Counter Register                                */
} SN_RTC_Type;

/* ================================================================================ */
/* ================                    SN_CT16B0                   ================ */
/* ================================================================================ */

/**
 * @brief 16-bit Timer 0 with Capture function (SN_CT16B0)
 */

typedef struct { /*!< SN_CT16B0 Structure                                                   */

    union {
        __IO uint32_t TMRCTRL; /*!< Offset:0x00 CT16Bn Timer Control Register                             */

        struct {
            __IO uint32_t CEN : 1;  /*!< Counter enable                                                        */
            __IO uint32_t CRST : 1; /*!< Counter Reset                                                         */
            uint32_t : 2;
            __IO uint32_t CM : 3; /*!< Counting Mode                                                         */
        } TMRCTRL_b;              /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t TC; /*!< Offset:0x04 CT16Bn Timer Counter Register                             */

        struct {
            __IO uint32_t TC : 16; /*!< Timer Counter                                                         */
        } TC_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t PRE; /*!< Offset:0x08 CT16Bn Prescale Register                                  */

        struct {
            __IO uint32_t PRE : 16; /*!< Prescaler                                                             */
        } PRE_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t PC; /*!< Offset:0x0C CT16Bn Prescale Counter Register                          */

        struct {
            __IO uint32_t PC : 16; /*!< Prescaler Counter                                                     */
        } PC_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CNTCTRL; /*!< Offset:0x10 CT16Bn Counter Control Register                           */

        struct {
            __IO uint32_t CTM : 2; /*!< Counter/Timer Mode                                                    */
            __IO uint32_t CIS : 2; /*!< Counter Input Select                                                  */
        } CNTCTRL_b;               /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t MCTRL; /*!< Offset:0x14 CT16Bn Match Control Register                             */

        struct {
            __IO uint32_t MR0IE : 1;   /*!< Enable generating an interrupt when MR0 matches TC                    */
            __IO uint32_t MR0RST : 1;  /*!< Enable reset TC when MR0 matches TC                                   */
            __IO uint32_t MR0STOP : 1; /*!< Stop TC and PC and clear CEN bit when MR0 matches TC                  */
            __IO uint32_t MR1IE : 1;   /*!< Enable generating an interrupt when MR1 matches TC                    */
            __IO uint32_t MR1RST : 1;  /*!< Enable reset TC when MR1 matches TC                                   */
            __IO uint32_t MR1STOP : 1; /*!< Stop TC and PC and clear CEN bit when MR1 matches TC                  */
            __IO uint32_t MR2IE : 1;   /*!< Enable generating an interrupt when MR2 matches TC                    */
            __IO uint32_t MR2RST : 1;  /*!< Enable reset TC when MR2 matches TC                                   */
            __IO uint32_t MR2STOP : 1; /*!< Stop TC and PC and clear CEN bit when MR2 matches TC                  */
            __IO uint32_t MR3IE : 1;   /*!< Enable generating an interrupt when MR3 matches TC                    */
            __IO uint32_t MR3RST : 1;  /*!< Enable reset TC when MR3 matches TC                                   */
            __IO uint32_t MR3STOP : 1; /*!< Stop TC and PC and clear CEN bit when MR3 matches TC                  */
        } MCTRL_b;                     /*!< BitSize                                                               */
    };
    __IO uint32_t MR0; /*!< Offset:0x18 CT16Bn MR0 Register                                       */
    __IO uint32_t MR1; /*!< Offset:0x1C CT16Bn MR1 Register                                       */
    __IO uint32_t MR2; /*!< Offset:0x20 CT16Bn MR2 Register                                       */
    __IO uint32_t MR3; /*!< Offset:0x24 CT16Bn MR3 Register                                       */

    union {
        __IO uint32_t CAPCTRL; /*!< Offset:0x28 CT16Bn Capture Control Register                           */

        struct {
            __IO uint32_t CAP0RE : 1; /*!< Capture on CT16Bn_CAP0 rising edge                                    */
            __IO uint32_t CAP0FE : 1; /*!< Capture on CT16Bn_CAP0 falling edge                                   */
            __IO uint32_t CAP0IE : 1; /*!< Interrupt on CT16Bn_CAP0 event                                        */
            __IO uint32_t CAP0EN : 1; /*!< CAP0 function enable                                                  */
        } CAPCTRL_b;                  /*!< BitSize                                                               */
    };

    union {
        __I uint32_t CAP0; /*!< Offset:0x2C CT16Bn CAP0 Register                                      */

        struct {
            __I uint32_t CAP0 : 16; /*!< Timer counter capture value                                           */
        } CAP0_b;                   /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t EM; /*!< Offset:0x30 CT16Bn External Match Register                            */

        struct {
            __IO uint32_t EM0 : 1; /*!< When the TC matches MR0, this bit will act according to EMC0[1:0],
                                  and also drive the state of CT16Bn_PWM0 output.                       */
            __IO uint32_t EM1 : 1; /*!< When the TC matches MR1, this bit will act according to EMC1[1:0],
                                  and also drive the state of CT16Bn_PWM1 output.                       */
            __IO uint32_t EM2 : 1; /*!< When the TC matches MR2, this bit will act according to EMC2[1:0],
                                  and also drive the state of CT16Bn_PWM2 output.                       */
            uint32_t : 1;
            __IO uint32_t EMC0 : 2; /*!< CT16Bn_PWM0 functionality                                             */
            __IO uint32_t EMC1 : 2; /*!< CT16Bn_PWM1 functionality                                             */
            __IO uint32_t EMC2 : 2; /*!< CT16Bn_PWM2 functionality                                             */
        } EM_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t PWMCTRL; /*!< Offset:0x34 CT16Bn PWM Control Register                               */

        struct {
            __IO uint32_t PWM0EN : 1; /*!< PWM0 enable                                                           */
            __IO uint32_t PWM1EN : 1; /*!< PWM1 enable                                                           */
            __IO uint32_t PWM2EN : 1; /*!< PWM2 enable                                                           */
            uint32_t : 1;
            __IO uint32_t PWM0M0DE : 2; /*!< PWM0 output mode                                                      */
            __IO uint32_t PWM1M0DE : 2; /*!< PWM1 output mode                                                      */
            __IO uint32_t PWM2M0DE : 2; /*!< PWM2 output mode                                                      */
            uint32_t : 10;
            __IO uint32_t PWM0IOEN : 1; /*!< CT16Bn_PWM0/GPIO selection                                            */
            __IO uint32_t PWM1IOEN : 1; /*!< CT16Bn_PWM1/GPIO selection                                            */
            __IO uint32_t PWM2IOEN : 1; /*!< CT16Bn_PWM2/GPIO selection                                            */
        } PWMCTRL_b;                    /*!< BitSize                                                               */
    };

    union {
        __I uint32_t RIS; /*!< Offset:0x38 CT16Bn Raw Interrupt Status Register                      */

        struct {
            __I uint32_t MR0IF : 1;  /*!< Match channel 0 interrupt flag                                        */
            __I uint32_t MR1IF : 1;  /*!< Match channel 1 interrupt flag                                        */
            __I uint32_t MR2IF : 1;  /*!< Match channel 2 interrupt flag                                        */
            __I uint32_t MR3IF : 1;  /*!< Match channel 3 interrupt flag                                        */
            __I uint32_t CAP0IF : 1; /*!< Capture channel 0 interrupt flag                                      */
        } RIS_b;                     /*!< BitSize                                                               */
    };

    union {
        __O uint32_t IC; /*!< Offset:0x3C CT16Bn Interrupt Clear Register                           */

        struct {
            __O uint32_t MR0IC : 1;  /*!< MR0IF clear bit                                                       */
            __O uint32_t MR1IC : 1;  /*!< MR1IF clear bit                                                       */
            __O uint32_t MR2IC : 1;  /*!< MR2IF clear bit                                                       */
            __O uint32_t MR3IC : 1;  /*!< MR3IF clear bit                                                       */
            __O uint32_t CAP0IC : 1; /*!< CAP0IF clear bit                                                      */
        } IC_b;                      /*!< BitSize                                                               */
    };
} SN_CT16B0_Type;

/* ================================================================================ */
/* ================                    SN_CT32B0                   ================ */
/* ================================================================================ */

/**
 * @brief 32-bit Timer 0 with Capture function (SN_CT32B0)
 */

typedef struct { /*!< SN_CT32B0 Structure                                                   */

    union {
        __IO uint32_t TMRCTRL; /*!< Offset:0x00 CT32Bn Timer Control Register                             */

        struct {
            __IO uint32_t CEN : 1;  /*!< Counter Enable                                                        */
            __IO uint32_t CRST : 1; /*!< Counter Reset                                                         */
            uint32_t : 2;
            __IO uint32_t CM : 3; /*!< Counting Mode                                                         */
        } TMRCTRL_b;              /*!< BitSize                                                               */
    };
    __IO uint32_t TC;  /*!< Offset:0x04 CT32Bn Timer Counter Register                             */
    __IO uint32_t PRE; /*!< Offset:0x08 CT32Bn Prescale Register                                  */
    __IO uint32_t PC;  /*!< Offset:0x0C CT32Bn Prescale Counter Register                          */

    union {
        __IO uint32_t CNTCTRL; /*!< Offset:0x10 CT32Bn Counter Control Register                           */

        struct {
            __IO uint32_t CTM : 2; /*!< Counter/Timer Mode                                                    */
            __IO uint32_t CIS : 2; /*!< Counter Input Select                                                  */
        } CNTCTRL_b;               /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t MCTRL; /*!< Offset:0x14 CT32Bn Match Control Register                             */

        struct {
            __IO uint32_t MR0IE : 1;   /*!< Enable generating an interrupt when MR0 matches TC                    */
            __IO uint32_t MR0RST : 1;  /*!< Enable reset TC when MR0 matches TC                                   */
            __IO uint32_t MR0STOP : 1; /*!< Stop TC and PC and clear CEN bit when MR0 matches TC                  */
            __IO uint32_t MR1IE : 1;   /*!< Enable generating an interrupt when MR1 matches TC                    */
            __IO uint32_t MR1RST : 1;  /*!< Enable reset TC when MR1 matches TC                                   */
            __IO uint32_t MR1STOP : 1; /*!< Stop TC and PC and clear CEN bit when MR1 matches TC                  */
            __IO uint32_t MR2IE : 1;   /*!< Enable generating an interrupt when MR2 matches TC                    */
            __IO uint32_t MR2RST : 1;  /*!< Enable reset TC when MR2 matches TC                                   */
            __IO uint32_t MR2STOP : 1; /*!< Stop TC and PC and clear CEN bit when MR2 matches TC                  */
            __IO uint32_t MR3IE : 1;   /*!< Enable generating an interrupt when MR3 matches TC                    */
            __IO uint32_t MR3RST : 1;  /*!< Enable reset TC when MR3 matches TC                                   */
            __IO uint32_t MR3STOP : 1; /*!< Stop TC and PC and clear CEN bit when MR3 matches TC                  */
        } MCTRL_b;                     /*!< BitSize                                                               */
    };
    __IO uint32_t MR0; /*!< Offset:0x18 CT32Bn MR0 Register                                       */
    __IO uint32_t MR1; /*!< Offset:0x1C CT32Bn MR1 Register                                       */
    __IO uint32_t MR2; /*!< Offset:0x20 CT32Bn MR2 Register                                       */
    __IO uint32_t MR3; /*!< Offset:0x24 CT32Bn MR3 Register                                       */

    union {
        __IO uint32_t CAPCTRL; /*!< Offset:0x28 CT32Bn Capture Control Register                           */

        struct {
            __IO uint32_t CAP0RE : 1; /*!< Capture on CT32Bn_CAP0 rising edge                                    */
            __IO uint32_t CAP0FE : 1; /*!< Capture on CT32Bn_CAP0 falling edge                                   */
            __IO uint32_t CAP0IE : 1; /*!< Interrupt on CT32Bn_CAP0 event                                        */
            __IO uint32_t CAP0EN : 1; /*!< CAP0 function enable                                                  */
        } CAPCTRL_b;                  /*!< BitSize                                                               */
    };
    __I uint32_t CAP0; /*!< Offset:0x2C CT32Bn CAP0 Register                                      */

    union {
        __IO uint32_t EM; /*!< Offset:0x30 CT32Bn External Match Register                            */

        struct {
            __IO uint32_t EM0 : 1;  /*!< When the TC matches MR0, this bit will act according to EMC0[1:0],
                                   and also drive the state of CT32Bn_PWM0 output.                       */
            __IO uint32_t EM1 : 1;  /*!< When the TC matches MR1, this bit will act according to EMC1[1:0],
                                   and also drive the state of CT32Bn_PWM1 output.                       */
            __IO uint32_t EM2 : 1;  /*!< When the TC matches MR2, this bit will act according to EMC2[1:0],
                                   and also drive the state of CT32Bn_PWM2 output.                       */
            __IO uint32_t EM3 : 1;  /*!< When the TC matches MR3, this bit will act according to EMC3[1:0],
                                   and also drive the state of CT32Bn_PWM3 output.                       */
            __IO uint32_t EMC0 : 2; /*!< CT32Bn_PWM0 functionality                                             */
            __IO uint32_t EMC1 : 2; /*!< CT32Bn_PWM1 functionality                                             */
            __IO uint32_t EMC2 : 2; /*!< CT32Bn_PWM2 functionality                                             */
            __IO uint32_t EMC3 : 2; /*!< CT32Bn_PWM3 functionality                                             */
        } EM_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t PWMCTRL; /*!< Offset:0x34 CT32Bn PWM Control Register                               */

        struct {
            __IO uint32_t PWM0EN : 1;   /*!< PWM0 enable                                                           */
            __IO uint32_t PWM1EN : 1;   /*!< PWM1 enable                                                           */
            __IO uint32_t PWM2EN : 1;   /*!< PWM2 enable                                                           */
            __IO uint32_t PWM3EN : 1;   /*!< PWM3 enable                                                           */
            __IO uint32_t PWM0M0DE : 2; /*!< PWM0 output mode                                                      */
            __IO uint32_t PWM1M0DE : 2; /*!< PWM1 output mode                                                      */
            __IO uint32_t PWM2M0DE : 2; /*!< PWM2 output mode                                                      */
            __IO uint32_t PWM3M0DE : 2; /*!< PWM3 output mode                                                      */
            uint32_t : 8;
            __IO uint32_t PWM0IOEN : 1; /*!< CT32Bn_PWM0/GPIO selection                                            */
            __IO uint32_t PWM1IOEN : 1; /*!< CT16Bn_PWM1/GPIO selection                                            */
            __IO uint32_t PWM2IOEN : 1; /*!< CT32Bn_PWM2/GPIO selection                                            */
            __IO uint32_t PWM3IOEN : 1; /*!< CT32Bn_PWM3/GPIO selection                                            */
        } PWMCTRL_b;                    /*!< BitSize                                                               */
    };

    union {
        __I uint32_t RIS; /*!< Offset:0x38 CT32Bn Raw Interrupt Status Register                      */

        struct {
            __I uint32_t MR0IF : 1;  /*!< Match channel 0 interrupt flag                                        */
            __I uint32_t MR1IF : 1;  /*!< Match channel 1 interrupt flag                                        */
            __I uint32_t MR2IF : 1;  /*!< Match channel 2 interrupt flag                                        */
            __I uint32_t MR3IF : 1;  /*!< Match channel 3 interrupt flag                                        */
            __I uint32_t CAP0IF : 1; /*!< Capture channel 0 interrupt flag                                      */
        } RIS_b;                     /*!< BitSize                                                               */
    };

    union {
        __O uint32_t IC; /*!< Offset:0x3C CT32Bn Interrupt Clear Register                           */

        struct {
            __O uint32_t MR0IC : 1;  /*!< MR0IF clear bit                                                       */
            __O uint32_t MR1IC : 1;  /*!< MR1IF clear bit                                                       */
            __O uint32_t MR2IC : 1;  /*!< MR2IF clear bit                                                       */
            __O uint32_t MR3IC : 1;  /*!< MR3IF clear bit                                                       */
            __O uint32_t CAP0IC : 1; /*!< CAP0IF clear bit                                                      */
        } IC_b;                      /*!< BitSize                                                               */
    };
} SN_CT32B0_Type;

/* ================================================================================ */
/* ================                     SN_PMU                     ================ */
/* ================================================================================ */

/**
 * @brief Power Management Unit (SN_PMU)
 */

typedef struct { /*!< SN_PMU Structure                                                      */

    union {
        __IO uint32_t BKP0; /*!< Offset:0x00 PMU Backup Register 0                                     */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP0_b;                         /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t BKP1; /*!< Offset:0x04 PMU Backup Register 1                                     */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP1_b;                         /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t BKP2; /*!< Offset:0x08 PMU Backup Register 2                                     */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP2_b;                         /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t BKP3; /*!< Offset:0x0C PMU Backup Register 3                                     */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP3_b;                         /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t BKP4; /*!< Offset:0x10 PMU Backup Register 4                                     */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP4_b;                         /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t BKP5; /*!< Offset:0x14 PMU Backup Register 5                                     */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP5_b;                         /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t BKP6; /*!< Offset:0x18 PMU Backup Register 6                                     */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP6_b;                         /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t BKP7; /*!< Offset:0x1C PMU Backup Register 7                                     */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP7_b;                         /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t BKP8; /*!< Offset:0x20 PMU Backup Register 8                                     */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP8_b;                         /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t BKP9; /*!< Offset:0x24 PMU Backup Register 9                                     */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP9_b;                         /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t BKP10; /*!< Offset:0x28 PMU Backup Register 10                                    */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP10_b;                        /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t BKP11; /*!< Offset:0x2C PMU Backup Register 11                                    */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP11_b;                        /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t BKP12; /*!< Offset:0x30 PMU Backup Register 12                                    */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP12_b;                        /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t BKP13; /*!< Offset:0x34 PMU Backup Register 13                                    */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP13_b;                        /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t BKP14; /*!< Offset:0x38 PMU Backup Register 14                                    */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP14_b;                        /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t BKP15; /*!< Offset:0x3C PMU Backup Register 15                                    */

        struct {
            __IO uint32_t BACKUPDATA : 8; /*!< Data retained                                                         */
        } BKP15_b;                        /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CTRL; /*!< Offset:0x40 PMU Control Register                                      */

        struct {
            __IO uint32_t MODE : 3; /*!< Low Power mode selection                                              */
        } CTRL_b;                   /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t LATCHCTRL1; /*!< Offset:0x44 PMU Latch Control Register 1                              */

        struct {
            __IO uint32_t LATCHEN : 1; /*!< Latch enable bit                                                      */
            uint32_t : 15;
            __O uint32_t LATCHKEY : 16; /*!< Latch register key                                                    */
        } LATCHCTRL1_b;                 /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t LATCHCTRL2; /*!< Offset:0x48 PMU Latch Control Register 2                              */

        struct {
            __IO uint32_t LATCHDIS : 1; /*!< Latch disable bit                                                     */
            uint32_t : 15;
            __O uint32_t LATCHKEY : 16; /*!< Latch register key                                                    */
        } LATCHCTRL2_b;                 /*!< BitSize                                                               */
    };

    union {
        __I uint32_t LATCHST; /*!< Offset:0x4C PMU Latch Status Register                                 */

        struct {
            __I uint32_t LATCHST : 1; /*!< Latch status                                                          */
        } LATCHST_b;                  /*!< BitSize                                                               */
    };
} SN_PMU_Type;

/* ================================================================================ */
/* ================                     SN_SSP0                    ================ */
/* ================================================================================ */

/**
 * @brief SSP0 (SN_SSP0)
 */

typedef struct { /*!< SN_SSP0 Structure                                                     */

    union {
        __IO uint32_t CTRL0; /*!< Offset:0x00 SSPn Control Register 0                                   */

        struct {
            __IO uint32_t SSPEN : 1;    /*!< SSP enable                                                            */
            __IO uint32_t LOOPBACK : 1; /*!< Loopback mode enable                                                  */
            __IO uint32_t SDODIS : 1;   /*!< Slave data out disable                                                */
            __IO uint32_t MS : 1;       /*!< Master/Slave selection                                                */
            __IO uint32_t FORMAT : 1;   /*!< Interface format                                                      */
            uint32_t : 1;
            __O uint32_t  FRESET : 2;   /*!< SSP FSM and FIFO Reset                                                */
            __IO uint32_t DL : 4;       /*!< Data length = DL[3:0]+1                                               */
            __IO uint32_t TXFIFOTH : 3; /*!< TX FIFO Threshold level                                               */
            __IO uint32_t RXFIFOTH : 3; /*!< RX FIFO Threshold level                                               */
            __IO uint32_t SELDIS : 1;   /*!< Auto-SEL disable bit                                                  */
        } CTRL0_b;                      /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CTRL1; /*!< Offset:0x04 SSPn Control Register 1                                   */

        struct {
            __IO uint32_t MLSB : 1; /*!< MSB/LSB seletion                                                      */
            __IO uint32_t CPOL : 1; /*!< Clock priority selection                                              */
            __IO uint32_t CPHA : 1; /*!< Clock phase of edge sampling                                          */
        } CTRL1_b;                  /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CLKDIV; /*!< Offset:0x08 SSPn Clock Divider Register                               */

        struct {
            __IO uint32_t DIV : 8; /*!< SSPn SCK=SSPn_PCLK/(2*DIV+2)                                          */
        } CLKDIV_b;                /*!< BitSize                                                               */
    };

    union {
        __I uint32_t STAT; /*!< Offset:0x0C SSPn Status Register                                      */

        struct {
            __I uint32_t TX_EMPTY : 1;  /*!< TX FIFO empty flag                                                    */
            __I uint32_t TX_FULL : 1;   /*!< TX FIFO full flag                                                     */
            __I uint32_t RX_EMPTY : 1;  /*!< RX FIFO empty flag                                                    */
            __I uint32_t RX_FULL : 1;   /*!< RX FIFO full flag                                                     */
            __I uint32_t BUSY : 1;      /*!< Busy flag                                                             */
            __I uint32_t TXFIFOTHF : 1; /*!< TX FIFO threshold flag                                                */
            __I uint32_t RXFIFOTHF : 1; /*!< RX FIFO threshold flag                                                */
        } STAT_b;                       /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t IE; /*!< Offset:0x10 SSPn Interrupt Enable Register                            */

        struct {
            __IO uint32_t RXOVFIE : 1;    /*!< RX FIFO overflow interrupt enable                                     */
            __IO uint32_t RXTOIE : 1;     /*!< RX time-out interrupt enable                                          */
            __IO uint32_t RXFIFOTHIE : 1; /*!< RX FIFO threshold interrupt enable                                    */
            __IO uint32_t TXFIFOTHIE : 1; /*!< TX FIFO threshold interrupt enable                                    */
        } IE_b;                           /*!< BitSize                                                               */
    };

    union {
        __I uint32_t RIS; /*!< Offset:0x14 SSPn Raw Interrupt Status Register                        */

        struct {
            __I uint32_t RXOVFIF : 1;    /*!< RX FIFO overflow interrupt flag                                       */
            __I uint32_t RXTOIF : 1;     /*!< RX time-out interrupt flag                                            */
            __I uint32_t RXFIFOTHIF : 1; /*!< RX FIFO threshold interrupt flag                                      */
            __I uint32_t TXFIFOTHIF : 1; /*!< TX FIFO threshold interrupt flag                                      */
        } RIS_b;                         /*!< BitSize                                                               */
    };

    union {
        __O uint32_t IC; /*!< Offset:0x18 SSPn Interrupt Clear Register                             */

        struct {
            __O uint32_t RXOVFIC : 1;    /*!< RX FIFO overflow flag clear                                           */
            __O uint32_t RXTOIC : 1;     /*!< RX time-out interrupt flag clear                                      */
            __O uint32_t RXFIFOTHIC : 1; /*!< RX Interrupt flag Clear                                               */
            __O uint32_t TXFIFOTHIC : 1; /*!< TX Interrupt flag Clear                                               */
        } IC_b;                          /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t DATA; /*!< Offset:0x1C SSPn Data Register                                        */

        struct {
            __IO uint32_t Data : 16; /*!< Data                                                                  */
        } DATA_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t DF; /*!< Offset:0x20 SSPn Data Fetch Register                                  */

        struct {
            __IO uint32_t DF : 1; /*!< SSP data fetch control bit                                            */
        } DF_b;                   /*!< BitSize                                                               */
    };
} SN_SSP0_Type;

/* ================================================================================ */
/* ================                     SN_I2C0                    ================ */
/* ================================================================================ */

/**
 * @brief I2C0 (SN_I2C0)
 */

typedef struct { /*!< SN_I2C0 Structure                                                     */

    union {
        __IO uint32_t CTRL; /*!< Offset:0x00 I2Cn Control Register                                     */

        struct {
            uint32_t : 1;
            __IO uint32_t NACK : 1; /*!< NACK assert flag                                                      */
            __IO uint32_t ACK : 1;  /*!< ACK assert flag                                                       */
            uint32_t : 1;
            __IO uint32_t STO : 1; /*!< STOP assert flag                                                      */
            __IO uint32_t STA : 1; /*!< START assert flag                                                     */
            uint32_t : 1;
            __IO uint32_t I2CMODE : 1; /*!< I2C mode                                                              */
            __IO uint32_t I2CEN : 1;   /*!< I2Cn interface enable                                                 */
        } CTRL_b;                      /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t STAT; /*!< Offset:0x04 I2Cn Status Register                                      */

        struct {
            __I uint32_t RX_DN : 1;      /*!< RX done status                                                        */
            __I uint32_t ACK_STAT : 1;   /*!< ACK done status                                                       */
            __I uint32_t NACK_STAT : 1;  /*!< NACK done status                                                      */
            __I uint32_t STOP_DN : 1;    /*!< STOP done status                                                      */
            __I uint32_t START_DN : 1;   /*!< START done status                                                     */
            __I uint32_t MST : 1;        /*!< I2C master/slave status                                               */
            __I uint32_t SLV_RX_HIT : 1; /*!< Slave RX address hit flag                                             */
            __I uint32_t SLV_TX_HIT : 1; /*!< Slave TX address hit flag                                             */
            __I uint32_t LOST_ARB : 1;   /*!< Lost arbitration status                                               */
            __I uint32_t TIMEOUT : 1;    /*!< Time-out status                                                       */
            uint32_t : 5;
            __IO uint32_t I2CIF : 1; /*!< I2C interrupt flag                                                    */
        } STAT_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t TXDATA; /*!< Offset:0x08 I2Cn TX Data Register                                     */

        struct {
            __IO uint32_t Data : 8; /*!< TX Data                                                               */
        } TXDATA_b;                 /*!< BitSize                                                               */
    };

    union {
        __I uint32_t RXDATA; /*!< Offset:0x0C I2Cn RX Data Register                                     */

        struct {
            __I uint32_t Data : 8; /*!< RX Data received when RX_DN=1                                         */
        } RXDATA_b;                /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t SLVADDR0; /*!< Offset:0x10 I2Cn Slave Address 0 Register                             */

        struct {
            __IO uint32_t ADDR : 10; /*!< I2Cn slave address 0                                                  */
            uint32_t : 20;
            __IO uint32_t GCEN : 1;     /*!< General call address enable                                           */
            __IO uint32_t ADD_MODE : 1; /*!< Slave address mode                                                    */
        } SLVADDR0_b;                   /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t SLVADDR1; /*!< Offset:0x14 I2Cn Slave Address 1 Register                             */

        struct {
            __IO uint32_t ADDR : 10; /*!< I2Cn slave address 1                                                  */
        } SLVADDR1_b;                /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t SLVADDR2; /*!< Offset:0x18 I2Cn Slave Address 2 Register                             */

        struct {
            __IO uint32_t ADDR : 10; /*!< I2Cn slave address 2                                                  */
        } SLVADDR2_b;                /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t SLVADDR3; /*!< Offset:0x1C I2Cn Slave Address 3 Register                             */

        struct {
            __IO uint32_t ADDR : 10; /*!< I2Cn slave address 3                                                  */
        } SLVADDR3_b;                /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t SCLHT; /*!< Offset:0x20 I2Cn SCL High Time Register                               */

        struct {
            __IO uint32_t SCLH : 8; /*!< SCLn High period time=(SCLHT+1)*I2Cn_PCLK cycle                       */
        } SCLHT_b;                  /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t SCLLT; /*!< Offset:0x24 I2Cn SCL Low Time Register                                */

        struct {
            __IO uint32_t SCLL : 8; /*!< SCLn Low period time=(SCLLT+1)*I2Cn_PCLK cycle                        */
        } SCLLT_b;                  /*!< BitSize                                                               */
    };
    __I uint32_t RESERVED;

    union {
        __IO uint32_t TOCTRL; /*!< Offset:0x2C I2Cn Timeout Control Register                             */

        struct {
            __IO uint32_t TO : 16; /*!< Timeout period time = TO*32*I2Cn_PCLK cycle                           */
        } TOCTRL_b;                /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t MMCTRL; /*!< Offset:0x30 I2Cn Monitor Mode Control Register                        */

        struct {
            __IO uint32_t MMEN : 1;      /*!< Monitor mode enable                                                   */
            __IO uint32_t SCLOEN : 1;    /*!< SCLn output enable                                                    */
            __IO uint32_t MATCH_ALL : 1; /*!< Match address selection                                               */
        } MMCTRL_b;                      /*!< BitSize                                                               */
    };
} SN_I2C0_Type;

/* ================================================================================ */
/* ================                    SN_USART0                   ================ */
/* ================================================================================ */

/**
 * @brief USART0 (SN_USART0)
 */

typedef struct { /*!< SN_USART0 Structure                                                   */

    union {
        union {
            __IO uint32_t DLL; /*!< Offset:0x00 USARTn Divisor Latch LSB Register                         */

            struct {
                __IO uint32_t DLL : 8; /*!< DLL and DLM register determines the baud rate of USARTn               */
            } DLL_b;                   /*!< BitSize                                                               */
        };

        union {
            __IO uint32_t TH; /*!< Offset:0x00 USARTn Transmit Holding Register                          */

            struct {
                __O uint32_t TH : 8; /*!< The oldest byte to be transmitted in USART TX FIFO when transmitter
                                  is available                                                          */
            } TH_b;                  /*!< BitSize                                                               */
        };

        union {
            __I uint32_t RB; /*!< Offset:0x00 USARTn Receiver Buffer Register                           */

            struct {
                __I uint32_t RB : 8; /*!< The oldest received byte in USART RX FIFO                             */
            } RB_b;                  /*!< BitSize                                                               */
        };
    };

    union {
        union {
            __IO uint32_t IE; /*!< Offset:0x04 USARTn Interrupt Enable Register                          */

            struct {
                __IO uint32_t RDAIE : 1;  /*!< RDA interrupt enable                                                  */
                __IO uint32_t THREIE : 1; /*!< THRE interrupt enable                                                 */
                __IO uint32_t RLSIE : 1;  /*!< RLS interrupt enable                                                  */
                __IO uint32_t MSIE : 1;   /*!< MS interrupt enable                                                   */
                __IO uint32_t TEMTIE : 1; /*!< TEMT interrupt enable                                                 */
                uint32_t : 3;
                __IO uint32_t ABEOIE : 1;  /*!< ABE0 interrupt enable                                                 */
                __IO uint32_t ABTOIE : 1;  /*!< ABT0 interrupt enable                                                 */
                __IO uint32_t TXERRIE : 1; /*!< TXERR interrupt enable                                                */
            } IE_b;                        /*!< BitSize                                                               */
        };

        union {
            __IO uint32_t DLM; /*!< Offset:0x04 USARTn Divisor Latch MSB Register                         */

            struct {
                __IO uint32_t DLM : 8; /*!< DLL and DLM register determines the baud rate of USARTn               */
            } DLM_b;                   /*!< BitSize                                                               */
        };
    };

    union {
        union {
            __O uint32_t FIFOCTRL; /*!< Offset:0x08 USARTn FIFO Control Register                              */

            struct {
                __O uint32_t FIFOEN : 1;    /*!< FIFO enable                                                           */
                __O uint32_t RXFIFORST : 1; /*!< RX FIFO reset                                                         */
                __O uint32_t TXFIFORST : 1; /*!< TX FIFO reset                                                         */
                uint32_t : 3;
                __O uint32_t RXTL : 2; /*!< RX trigger level                                                      */
            } FIFOCTRL_b;              /*!< BitSize                                                               */
        };

        union {
            __I uint32_t II; /*!< Offset:0x08 USARTn Interrupt Identification Register                  */

            struct {
                __I uint32_t INTSTATUS : 1; /*!< Interrupt status                                                      */
                __I uint32_t INTID : 3;     /*!< Interrupt ID of RX FIFO                                               */
                uint32_t : 2;
                __I uint32_t FIFOEN : 2;  /*!< Equal to FIFOEN bits in USARTn_FIFOCTRL register                      */
                __I uint32_t ABEOIF : 1;  /*!< ABEO interrupt flag                                                   */
                __I uint32_t ABTOIF : 1;  /*!< ABTO interrupt flag                                                   */
                __I uint32_t TXERRIF : 1; /*!< TXERR interrupt flag                                                  */
            } II_b;                       /*!< BitSize                                                               */
        };
    };

    union {
        __IO uint32_t LC; /*!< Offset:0x0C USARTn Line Control Register                              */

        struct {
            __IO uint32_t WLS : 2;  /*!< Word length selection                                                 */
            __IO uint32_t SBS : 1;  /*!< Stop bit selection                                                    */
            __IO uint32_t PE : 1;   /*!< Parity enable                                                         */
            __IO uint32_t PS : 2;   /*!< Parity selection                                                      */
            __IO uint32_t BC : 1;   /*!< Break control                                                         */
            __IO uint32_t DLAB : 1; /*!< Divisor Latch access                                                  */
        } LC_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t MC; /*!< Offset:0x10 USARTn Modem Control Register                             */

        struct {
            uint32_t : 1;
            __IO uint32_t RTSCTRL : 1; /*!< Source from modem output (RTS) pin                                    */
            uint32_t : 4;
            __IO uint32_t RTSEN : 1; /*!< RTS enable                                                            */
            __IO uint32_t CTSEN : 1; /*!< CTS enable                                                            */
        } MC_b;                      /*!< BitSize                                                               */
    };

    union {
        __I uint32_t LS; /*!< Offset:0x14 USARTn Line Status Register                               */

        struct {
            __I uint32_t RDR : 1;   /*!< Receiver data ready flag                                              */
            __I uint32_t OE : 1;    /*!< Overrun error flag                                                    */
            __I uint32_t PE : 1;    /*!< Parity error flag                                                     */
            __I uint32_t FE : 1;    /*!< Framing error flag                                                    */
            __I uint32_t BI : 1;    /*!< Break interrupt flag                                                  */
            __I uint32_t THRE : 1;  /*!< THR empty flag                                                        */
            __I uint32_t TEMT : 1;  /*!< Transmitter empty flag                                                */
            __I uint32_t RXFE : 1;  /*!< Receiver FIFO error flag                                              */
            __I uint32_t TXERR : 1; /*!< TX error flag                                                         */
        } LS_b;                     /*!< BitSize                                                               */
    };

    union {
        __I uint32_t MS; /*!< Offset:0x18 USARTn Modem Status Register                              */

        struct {
            __I uint32_t DCTS : 1; /*!< Delta CTS                                                             */
            uint32_t : 3;
            __I uint32_t CTS : 1; /*!< Complement of CTS pin input signal                                    */
        } MS_b;                   /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t SP; /*!< Offset:0x1C USARTn Scratch Pad Register                               */

        struct {
            __IO uint32_t PAD : 8; /*!< Pad informaton                                                        */
        } SP_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t ABCTRL; /*!< Offset:0x20 USARTn Auto-baud Control Register                         */

        struct {
            __IO uint32_t START : 1;       /*!< Auto-baud run bit                                                     */
            __IO uint32_t MODE : 1;        /*!< Auto-baud mode selection                                              */
            __IO uint32_t AUTORESTART : 1; /*!< Restart mode selection                                                */
            uint32_t : 5;
            __O uint32_t ABEOIFC : 1; /*!< Clear ABEOIF flag                                                     */
            __O uint32_t ABTOIFC : 1; /*!< Clear ABTOIF flag                                                     */
        } ABCTRL_b;                   /*!< BitSize                                                               */
    };
    __I uint32_t RESERVED;

    union {
        __IO uint32_t FD; /*!< Offset:0x28 USARTn Fractional Divider Register                        */

        struct {
            __IO uint32_t DIVADDVAL : 4; /*!< Baud rate generation prescaler divisor value                          */
            __IO uint32_t MULVAL : 4;    /*!< Baud rate generation prescaler multiplier value                       */
            __IO uint32_t OVER8 : 1;     /*!< Oversampling value                                                    */
        } FD_b;                          /*!< BitSize                                                               */
    };
    __I uint32_t RESERVED1;

    union {
        __IO uint32_t CTRL; /*!< Offset:0x30 USARTn Control Register                                   */

        struct {
            __IO uint32_t USARTEN : 1; /*!< USART enable                                                          */
            __IO uint32_t MODE : 3;    /*!< USART mode                                                            */
            uint32_t : 2;
            __IO uint32_t RXEN : 1; /*!< RX enable                                                             */
            __IO uint32_t TXEN : 1; /*!< TX enable                                                             */
        } CTRL_b;                   /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t HDEN; /*!< Offset:0x34 USARTn Control Register                                   */

        struct {
            __IO uint32_t HDEN : 1; /*!< Half-duplex mode enable                                               */
        } HDEN_b;                   /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t SCICTRL; /*!< Offset:0x38 USARTn Smartcard Interface Control Register               */

        struct {
            uint32_t : 1;
            __IO uint32_t NACKDIS : 1; /*!< NACK response disable                                                 */
            __IO uint32_t PROTSEL : 1; /*!< ISO7816-3 protocol selection                                          */
            __IO uint32_t SCLKEN : 1;  /*!< SCLK enable                                                           */
            uint32_t : 1;
            __IO uint32_t TXRETRY : 3;   /*!< Maximal number of retransmissions that USART will attempt             */
            __IO uint32_t XTRAGUARD : 8; /*!< Extra guard time                                                      */
            __IO uint32_t TC : 8;        /*!< Count for SCLK clock cycle                                            */
        } SCICTRL_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t RS485CTRL; /*!< Offset:0x3C USARTn RS485 Control Register                             */

        struct {
            __IO uint32_t NMMEN : 1; /*!< RS-485 normal multidrop mode enable                                   */
            __IO uint32_t RXEN : 1;  /*!< RS-485 receiver enable                                                */
            __IO uint32_t AADEN : 1; /*!< Auto address detect enable                                            */
            uint32_t : 1;
            __IO uint32_t ADCEN : 1; /*!< Auto direction control enable                                         */
            __IO uint32_t OINV : 1;  /*!< Polarity control                                                      */
        } RS485CTRL_b;               /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t RS485ADRMATCH; /*!< Offset:0x40 USARTn RS485 Address Match Register                       */

        struct {
            __IO uint32_t MATCH : 8; /*!< RS-485 address value to be matched                                    */
        } RS485ADRMATCH_b;           /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t RS485DLYV; /*!< Offset:0x44 USARTn RS485 Delay Value Register                         */

        struct {
            __IO uint32_t DLY : 8; /*!< RTS delay value                                                       */
        } RS485DLYV_b;             /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t SYNCCTRL; /*!< Offset:0x48 USARTn Synchronous Mode Control Register                  */

        struct {
            uint32_t : 1;
            __IO uint32_t CPOL : 1; /*!< Clock polarity selection                                              */
            __IO uint32_t CPHA : 1; /*!< Clock phase for edge sampling                                         */
        } SYNCCTRL_b;               /*!< BitSize                                                               */
    };
} SN_USART0_Type;

/* ================================================================================ */
/* ================                     SN_I2S                     ================ */
/* ================================================================================ */

/**
 * @brief I2S (SN_I2S)
 */

typedef struct { /*!< SN_I2S Structure                                                      */

    union {
        __IO uint32_t CTRL; /*!< Offset:0x00 I2S Control Register                                      */

        struct {
            __IO uint32_t START : 1;     /*!< Start Transmit/Receive                                                */
            __IO uint32_t MUTE : 1;      /*!< Mute enable                                                           */
            __IO uint32_t MONO : 1;      /*!< Mono/stereo selection                                                 */
            __IO uint32_t MS : 1;        /*!< Master/Slave selection bit                                            */
            __IO uint32_t FORMAT : 2;    /*!< I2S operation format                                                  */
            __IO uint32_t TXEN : 1;      /*!< Transmit enable bit                                                   */
            __IO uint32_t RXEN : 1;      /*!< Receiver enable bit                                                   */
            __O uint32_t  CLRTXFIFO : 1; /*!< Clear I2S TX FIFO                                                     */
            __O uint32_t  CLRRXFIFO : 1; /*!< Clear I2S RX FIFO                                                     */
            __IO uint32_t DL : 2;        /*!< Data length                                                           */
            __IO uint32_t TXFIFOTH : 3;  /*!< TX FIFO threshold level                                               */
            uint32_t : 1;
            __IO uint32_t RXFIFOTH : 3; /*!< RX FIFO threshold level                                               */
            uint32_t : 1;
            __IO uint32_t CHLENGTH : 5; /*!< Bit number of single channel                                          */
            uint32_t : 6;
            __IO uint32_t I2SEN : 1; /*!< I2S enable                                                            */
        } CTRL_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CLK; /*!< Offset:0x04 I2S Clock Register                                        */

        struct {
            __IO uint32_t MCLKDIV : 3; /*!< MCLK divider                                                          */
            __IO uint32_t MCLKOEN : 1; /*!< MLCK output enable                                                    */
            __IO uint32_t MCLKSEL : 1; /*!< MLCK source selection                                                 */
            uint32_t : 3;
            __IO uint32_t BCLKDIV : 8; /*!< BCLK divider                                                          */
            __IO uint32_t CLKSEL : 1;  /*!< I2S clock source                                                      */
        } CLK_b;                       /*!< BitSize                                                               */
    };

    union {
        __I uint32_t STATUS; /*!< Offset:0x08 I2S Status Register                                       */

        struct {
            __I uint32_t I2SINT : 1;  /*!< I2S interrupt flag                                                    */
            __I uint32_t RIGHTCH : 1; /*!< Current channel status                                                */
            uint32_t : 4;
            __I uint32_t TXFIFOTHF : 1;   /*!< TX FIFO threshold flag                                                */
            __I uint32_t RXFIFOTHF : 1;   /*!< RX FIFO threshold flag                                                */
            __I uint32_t TXFIFOFULL : 1;  /*!< TX FIFO full flag                                                     */
            __I uint32_t RXFIFOFULL : 1;  /*!< RX FIFO full flag                                                     */
            __I uint32_t TXFIFOEMPTY : 1; /*!< TX FIFO empty flag                                                    */
            __I uint32_t RXFIFOEMPTY : 1; /*!< RX FIFO empty flag                                                    */
            __I uint32_t TXFIFOLV : 4;    /*!< TX FIFO used level                                                    */
            uint32_t : 1;
            __I uint32_t RXFIFOLV : 4; /*!< RX FIFO used level                                                    */
        } STATUS_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t IE; /*!< Offset:0x0C I2S Interrupt Enable Register                             */

        struct {
            uint32_t : 4;
            __IO uint32_t TXFIFOOVFIEN : 1; /*!< TX FIFO overflow interrupt enable                                     */
            __IO uint32_t RXFIFOUDFIEN : 1; /*!< RX FIFO underflow interrupt enable                                    */
            __IO uint32_t TXFIFOTHIEN : 1;  /*!< TX FIFO threshold interrupt enable                                    */
            __IO uint32_t RXFIFOTHIEN : 1;  /*!< RX FIFO threshold interrupt enable                                    */
        } IE_b;                             /*!< BitSize                                                               */
    };

    union {
        __I uint32_t RIS; /*!< Offset:0x10 I2S Raw Interrupt Status Register                         */

        struct {
            uint32_t : 4;
            __I uint32_t TXFIFOOVIF : 1; /*!< TX FIFO overflow interrupt flag                                       */
            __I uint32_t RXFIFOUDIF : 1; /*!< RX FIFO underflow interrupt flag                                      */
            __I uint32_t TXFIFOTHIF : 1; /*!< TX FIFO threshold interrupt flag                                      */
            __I uint32_t RXFIFOTHIF : 1; /*!< RX FIFO threshold interrupt flag                                      */
        } RIS_b;                         /*!< BitSize                                                               */
    };

    union {
        __O uint32_t IC; /*!< Offset:0x14 I2S Interrupt Clear Register                              */

        struct {
            uint32_t : 4;
            __O uint32_t TXFIFOOVIC : 1; /*!< TX FIFO overflow interrupt clear                                      */
            __O uint32_t RXFIFOUDIC : 1; /*!< RX FIFO underflow interrupt clear                                     */
            __O uint32_t TXFIFOTHIC : 1; /*!< TX FIFO threshold interrupt clear                                     */
            __O uint32_t RXFIFOTHIC : 1; /*!< RX FIFO threshold interrupt clear                                     */
        } IC_b;                          /*!< BitSize                                                               */
    };
    __I uint32_t RXFIFO; /*!< Offset:0x18 I2S RX FIFO Register                                      */
    __O uint32_t TXFIFO; /*!< Offset:0x1C I2S TX FIFO Register                                      */
} SN_I2S_Type;

/* ================================================================================ */
/* ================                    SN_FLASH                    ================ */
/* ================================================================================ */

/**
 * @brief FLASH Memory Control Registers (SN_FLASH)
 */

typedef struct { /*!< SN_FLASH Structure                                                    */

    union {
        __IO uint32_t LPCTRL; /*!< Offset:0x00 Flash Low Power Control Register                          */

        struct {
            __IO uint32_t LPMODE : 2; /*!< Flash Low Power mode enable bit                                       */
        } LPCTRL_b;                   /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t STATUS; /*!< Offset:0x04 Flash Status Register                                     */

        struct {
            __I uint32_t BUSY : 1; /*!< Busy flag                                                             */
            uint32_t : 1;
            __IO uint32_t PGERR : 1; /*!< Programming error flag                                                */
        } STATUS_b;                  /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CTRL; /*!< Offset:0x08 Flash Control Register                                    */

        struct {
            __IO uint32_t PG : 1;  /*!< Flash program enable bit                                              */
            __IO uint32_t PER : 1; /*!< Page erase enable bit                                                 */
            uint32_t : 4;
            __IO uint32_t STARTE : 1; /*!< Start erase enable bit                                                */
            __IO uint32_t CHK : 1;    /*!< Checksum calculation choosen                                          */
        } CTRL_b;                     /*!< BitSize                                                               */
    };
    __IO uint32_t DATA;   /*!< Offset:0x0C Flash Data Register                                       */
    __IO uint32_t ADDR;   /*!< Offset:0x10 Flash Address Register                                    */
    __I uint32_t  CHKSUM; /*!< Offset:0x14 Flash Checksum Register                                   */
} SN_FLASH_Type;

/* ================================================================================ */
/* ================                     SN_PFPA                    ================ */
/* ================================================================================ */

/**
 * @brief Peripheral Function Pin Assignment (SN_PFPA)
 */

typedef struct { /*!< SN_PFPA Structure                                                     */

    union {
        __IO uint32_t UART; /*!< Offset:0x00 PFPA for UART Register                                    */

        struct {
            __IO uint32_t UTXD0 : 4; /*!< UTXD0 assigned pin                                                    */
            __IO uint32_t URXD0 : 4; /*!< URXD0 assigned pin                                                    */
            __IO uint32_t UTXD1 : 4; /*!< UTXD1 assigned pin                                                    */
            __IO uint32_t URXD1 : 4; /*!< URXD1 assigned pin                                                    */
        } UART_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t I2C; /*!< Offset:0x04 PFPA for I2C Register                                     */

        struct {
            __IO uint32_t SDA0 : 4; /*!< SDA0 assigned pin                                                     */
            __IO uint32_t SCL0 : 4; /*!< SCL0 assigned pin                                                     */
            __IO uint32_t SDA1 : 4; /*!< SDA1 assigned pin                                                     */
            __IO uint32_t SCL1 : 4; /*!< SCL1 assigned pin                                                     */
        } I2C_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t SSP; /*!< Offset:0x08 PFPA for SSP Register                                     */

        struct {
            __IO uint32_t MISO0 : 4; /*!< MISO0 assigned pin                                                    */
            __IO uint32_t MOSI0 : 4; /*!< MOSI0 assigned pin                                                    */
            __IO uint32_t SCK0 : 4;  /*!< SCK0 assigned pin                                                     */
            __IO uint32_t SEL0 : 4;  /*!< SEL0 assigned pin                                                     */
            __IO uint32_t MISO1 : 4; /*!< MISO1 assigned pin                                                    */
            __IO uint32_t MOSI1 : 4; /*!< MOSI1 assigned pin                                                    */
            __IO uint32_t SCK1 : 4;  /*!< SCK1 assigned pin                                                     */
            __IO uint32_t SEL1 : 4;  /*!< SEL1 assigned pin                                                     */
        } SSP_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t I2S; /*!< Offset:0x0C PFPA for I2S Register                                     */

        struct {
            __IO uint32_t MCLK : 4; /*!< I2SMCLK assigned pin                                                  */
            __IO uint32_t BCLK : 4; /*!< I2SBCLK assigned pin                                                  */
            __IO uint32_t WS : 4;   /*!< I2SWS assigned pin                                                    */
            __IO uint32_t DOUT : 4; /*!< I2SDOUT assigned pin                                                  */
            __IO uint32_t DIN : 4;  /*!< I2SDIN assigned pin                                                   */
        } I2S_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CT16B0; /*!< Offset:0x10 PFPA for CT16B0 Register                                  */

        struct {
            __IO uint32_t CAP0 : 4; /*!< CT16B0_CAP0 assigned pin                                              */
            __IO uint32_t PWM0 : 4; /*!< CT16B0_PWM0 assigned pin                                              */
            __IO uint32_t PWM1 : 4; /*!< CT16B0_PWM1 assigned pin                                              */
            __IO uint32_t PWM2 : 4; /*!< CT16B0_PWM2 assigned pin                                              */
        } CT16B0_b;                 /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CT16B1; /*!< Offset:0x14 PFPA for CT16B1 Register                                  */

        struct {
            __IO uint32_t CAP0 : 4; /*!< CT16B1_CAP0 assigned pin                                              */
            __IO uint32_t PWM0 : 4; /*!< CT16B1_PWM0 assigned pin                                              */
            __IO uint32_t PWM1 : 4; /*!< CT16B1_PWM1 assigned pin                                              */
            __IO uint32_t PWM2 : 4; /*!< CT16B1_PWM2 assigned pin                                              */
        } CT16B1_b;                 /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CT16B2; /*!< Offset:0x18 PFPA for CT16B2 Register                                  */

        struct {
            __IO uint32_t CAP0 : 4; /*!< CT16B2_CAP0 assigned pin                                              */
            __IO uint32_t PWM0 : 4; /*!< CT16B2_PWM0 assigned pin                                              */
            __IO uint32_t PWM1 : 4; /*!< CT16B2_PWM1 assigned pin                                              */
            __IO uint32_t PWM2 : 4; /*!< CT16B2_PWM2 assigned pin                                              */
        } CT16B2_b;                 /*!< BitSize                                                               */
    };
    __I uint32_t RESERVED;

    union {
        __IO uint32_t CT32B0; /*!< Offset:0x20 PFPA for CT32B0 Register                                  */

        struct {
            __IO uint32_t CAP0 : 4; /*!< CT32B0_CAP0 assigned pin                                              */
            __IO uint32_t PWM0 : 4; /*!< CT32B0_PWM0 assigned pin                                              */
            __IO uint32_t PWM1 : 4; /*!< CT32B0_PWM1 assigned pin                                              */
            __IO uint32_t PWM2 : 4; /*!< CT32B0_PWM2 assigned pin                                              */
            __IO uint32_t PWM3 : 4; /*!< CT32B0_PWM3 assigned pin                                              */
        } CT32B0_b;                 /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CT32B1; /*!< Offset:0x24 PFPA for CT32B1 Register                                  */

        struct {
            __IO uint32_t CAP0 : 4; /*!< CT32B1_CAP0 assigned pin                                              */
            __IO uint32_t PWM0 : 4; /*!< CT32B1_PWM0 assigned pin                                              */
            __IO uint32_t PWM1 : 4; /*!< CT32B1_PWM1 assigned pin                                              */
            __IO uint32_t PWM2 : 4; /*!< CT32B1_PWM2 assigned pin                                              */
            __IO uint32_t PWM3 : 4; /*!< CT32B1_PWM3 assigned pin                                              */
        } CT32B1_b;                 /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CT32B2; /*!< Offset:0x28 PFPA for CT32B2 Register                                  */

        struct {
            __IO uint32_t CAP0 : 4; /*!< CT32B2_CAP0 assigned pin                                              */
            __IO uint32_t PWM0 : 4; /*!< CT32B2_PWM0 assigned pin                                              */
            __IO uint32_t PWM1 : 4; /*!< CT32B2_PWM1 assigned pin                                              */
            __IO uint32_t PWM2 : 4; /*!< CT32B2_PWM2 assigned pin                                              */
            __IO uint32_t PWM3 : 4; /*!< CT32B2_PWM3 assigned pin                                              */
        } CT32B2_b;                 /*!< BitSize                                                               */
    };
} SN_PFPA_Type;

/* ================================================================================ */
/* ================                     SN_USB                     ================ */
/* ================================================================================ */

/**
 * @brief Universal Serial Bus Full Speed Device Interface (USB) (SN_USB)
 */

typedef struct { /*!< SN_USB Structure                                                      */

    union {
        __IO uint32_t INTEN; /*!< Offset:0x00 USB Interrupt Enable Register                             */

        struct {
            __IO uint32_t EP1_NAK_EN : 1; /*!< EP1 NAK Interrupt Enable                                              */
            __IO uint32_t EP2_NAK_EN : 1; /*!< EP2 NAK Interrupt Enable                                              */
            __IO uint32_t EP3_NAK_EN : 1; /*!< EP3 NAK Interrupt Enable                                              */
            __IO uint32_t EP4_NAK_EN : 1; /*!< EP4 NAK Interrupt Enable                                              */
            __IO uint32_t EP5_NAK_EN : 1; /*!< EP5 NAK Interrupt Enable                                              */
            __IO uint32_t EP6_NAK_EN : 1; /*!< EP6 NAK Interrupt Enable                                              */
            uint32_t : 23;
            __IO uint32_t USB_IE : 1;     /*!< USB Event Interrupt Enable                                            */
            __IO uint32_t USB_SOF_IE : 1; /*!< USB SOF Interrupt Enable                                              */
            __IO uint32_t BUS_IE : 1;     /*!< Bus Event Interrupt Enable                                            */
        } INTEN_b;                        /*!< BitSize                                                               */
    };

    union {
        __I uint32_t INSTS; /*!< Offset:0x04 USB Interrupt Event Status Register                       */

        struct {
            __I uint32_t EP1_NAK : 1; /*!< Endpoint 1 NAK transaction flag                                       */
            __I uint32_t EP2_NAK : 1; /*!< Endpoint 2 NAK transaction flag                                       */
            __I uint32_t EP3_NAK : 1; /*!< Endpoint 3 NAK transaction flag                                       */
            __I uint32_t EP4_NAK : 1; /*!< Endpoint 4 NAK transaction flag                                       */
            __I uint32_t EP5_NAK : 1; /*!< Endpoint 5 NAK transaction flag                                       */
            __I uint32_t EP6_NAK : 1; /*!< Endpoint 6 NAK transaction flag                                       */
            uint32_t : 2;
            __I uint32_t EP1_ACK : 1; /*!< Endpoint 1 ACK transaction flag                                       */
            __I uint32_t EP2_ACK : 1; /*!< Endpoint 2 ACK transaction flag                                       */
            __I uint32_t EP3_ACK : 1; /*!< Endpoint 3 ACK transaction flag                                       */
            __I uint32_t EP4_ACK : 1; /*!< Endpoint 4 ACK transaction flag                                       */
            __I uint32_t EP5_ACK : 1; /*!< Endpoint 5 ACK transaction flag                                       */
            __I uint32_t EP6_ACK : 1; /*!< Endpoint 6 ACK transaction flag                                       */
            uint32_t : 3;
            __I uint32_t ERR_TIMEOUT : 1;   /*!< Timeout Status                                                        */
            __I uint32_t ERR_SETUP : 1;     /*!< Wrong Setup data received                                             */
            __I uint32_t EP0_OUT_STALL : 1; /*!< EP0 OUT STALL transaction                                             */
            __I uint32_t EP0_IN_STALL : 1;  /*!< EP0 IN STALL Transaction is completed                                 */
            __I uint32_t EP0_OUT : 1;       /*!< EP0 OUT ACK Transaction Flag                                          */
            __I uint32_t EP0_IN : 1;        /*!< EP0 IN ACK Transaction Flag                                           */
            __I uint32_t EP0_SETUP : 1;     /*!< EP0 Setup Transaction Flag                                            */
            __I uint32_t EP0_PRESETUP : 1;  /*!< EP0 Setup Token Packet Flag                                           */
            __I uint32_t BUS_WAKEUP : 1;    /*!< Bus Wakeup Flag                                                       */
            __I uint32_t USB_SOF : 1;       /*!< USB SOF packet received flag                                          */
            uint32_t : 2;
            __I uint32_t BUS_RESUME : 1;  /*!< USB Bus Resume signal flag                                            */
            __I uint32_t BUS_SUSPEND : 1; /*!< USB Bus Suspend signal flag                                           */
            __I uint32_t BUS_RESET : 1;   /*!< USB Bus Reset signal flag                                             */
        } INSTS_b;                        /*!< BitSize                                                               */
    };

    union {
        __O uint32_t INSTSC; /*!< Offset:0x08 USB Interrupt Event Status Clear Register                 */

        struct {
            __O uint32_t EP1_NAKC : 1; /*!< EP1 NAK clear bit                                                     */
            __O uint32_t EP2_NAKC : 1; /*!< EP2 NAK clear bit                                                     */
            __O uint32_t EP3_NAKC : 1; /*!< EP3 NAK clear bit                                                     */
            __O uint32_t EP4_NAKC : 1; /*!< EP4 NAK clear bit                                                     */
            __O uint32_t EP5_NAKC : 1; /*!< EP5 NAK clear bit                                                     */
            __O uint32_t EP6_NAKC : 1; /*!< EP6 NAK clear bit                                                     */
            uint32_t : 2;
            __O uint32_t EP1_ACKC : 1; /*!< EP1 ACK clear bit                                                     */
            __O uint32_t EP2_ACKC : 1; /*!< EP2 ACK clear bit                                                     */
            __O uint32_t EP3_ACKC : 1; /*!< EP3 ACK clear bit                                                     */
            __O uint32_t EP4_ACKC : 1; /*!< EP4 ACK clear bit                                                     */
            __O uint32_t EP5_ACKC : 1; /*!< EP5 ACK clear bit                                                     */
            __O uint32_t EP6_ACKC : 1; /*!< EP6 ACK clear bit                                                     */
            uint32_t : 3;
            __O uint32_t ERR_TIMEOUTC : 1;   /*!< Timeout Error clear bit                                               */
            __O uint32_t ERR_SETUPC : 1;     /*!< Error Setup clear bit                                                 */
            __O uint32_t EP0_OUT_STALLC : 1; /*!< EP0 OUT STALL clear bit                                               */
            __O uint32_t EP0_IN_STALLC : 1;  /*!< EP0 IN STALL clear bit                                                */
            __O uint32_t EP0_OUTC : 1;       /*!< EP0 OUT clear bit                                                     */
            __O uint32_t EP0_INC : 1;        /*!< EP0 IN clear bit                                                      */
            __O uint32_t EP0_SETUPC : 1;     /*!< EP0 SETUP clear bit                                                   */
            __O uint32_t EP0_PRESETUPC : 1;  /*!< EP0 PRESETUP clear bit                                                */
            __O uint32_t BUS_WAKEUPC : 1;    /*!< Bus Wakeup clear bit                                                  */
            __O uint32_t USB_SOFC : 1;       /*!< USB SOF clear bit                                                     */
            uint32_t : 2;
            __O uint32_t BUS_RESUMEC : 1; /*!< USB Bus Resume clear bit                                              */
            uint32_t : 1;
            __O uint32_t BUS_RESETC : 1; /*!< USB Bus Reset clear bit                                               */
        } INSTSC_b;                      /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t ADDR; /*!< Offset:0x0C USB Device Address Register                               */

        struct {
            __IO uint32_t UADDR : 7; /*!< USB device's address                                                  */
        } ADDR_b;                    /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CFG; /*!< Offset:0x10 USB Configuration Register                                */

        struct {
            __IO uint32_t EP1_DIR : 1; /*!< Endpoint 1 IN/OUT direction setting                                   */
            __IO uint32_t EP2_DIR : 1; /*!< Endpoint 2 IN/OUT direction setting                                   */
            __IO uint32_t EP3_DIR : 1; /*!< Endpoint 3 IN/OUT direction setting                                   */
            __IO uint32_t EP4_DIR : 1; /*!< Endpoint 4 IN/OUT direction setting                                   */
            __IO uint32_t EP5_DIR : 1; /*!< Endpoint 5 IN/OUT direction setting                                   */
            __IO uint32_t EP6_DIR : 1; /*!< Endpoint 6 IN/OUT direction setting                                   */
            uint32_t : 2;
            __IO uint32_t EP1_ISO : 1; /*!< Endpoint 1 ISO mode setting                                           */
            __IO uint32_t EP2_ISO : 1; /*!< Endpoint 2 ISO mode setting                                           */
            __IO uint32_t EP3_ISO : 1; /*!< Endpoint 3 ISO mode setting                                           */
            __IO uint32_t EP4_ISO : 1; /*!< Endpoint 4 ISO mode setting                                           */
            __IO uint32_t EP5_ISO : 1; /*!< Endpoint 5 ISO mode setting                                           */
            __IO uint32_t EP6_ISO : 1; /*!< Endpoint 6 ISO mode setting                                           */
            uint32_t : 10;
            __IO uint32_t VREG33DIS_EN : 1; /*!< Enable 400ohm discharge path of VREG33 to GND                         */
            __IO uint32_t USBRAM_EN : 1;    /*!< Enable USB 512-byte RAM function                                      */
            __IO uint32_t FLTDET_PUEN : 1;  /*!< Enable internal D+ and D- weak pull-up resistor                       */
            __IO uint32_t EMC_EN : 1;       /*!< Enable USB EMC protection                                             */
            __IO uint32_t SIE_EN : 1;       /*!< USB Serial Interface Engine Enable                                    */
            __IO uint32_t DPPU_EN : 1;      /*!< Enable internal D+ 1.5k pull-up resistor                              */
            __IO uint32_t PHY_EN : 1;       /*!< PHY Transceiver Function Enable                                       */
            __IO uint32_t VREG33_EN : 1;    /*!< Enable the internal VREG33 ouput                                      */
        } CFG_b;                            /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t SGCTL; /*!< Offset:0x14 USB Signal Control Register                               */

        struct {
            __IO uint32_t BUS_DN : 1;    /*!< USB D- state                                                          */
            __IO uint32_t BUS_DP : 1;    /*!< USB DP state                                                          */
            __IO uint32_t BUS_DRVEN : 1; /*!< Enable to drive USB bus                                               */
        } SGCTL_b;                       /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t EP0CTL; /*!< Offset:0x18 USB Endpoint 0 Control Register                           */

        struct {
            __IO uint32_t ENDP_CNT : 7; /*!< Endpoint byte count                                                   */
            uint32_t : 20;
            __IO uint32_t OUT_STALL_EN : 1; /*!< Enable EP0 OUT STALL handshake                                        */
            __IO uint32_t IN_STALL_EN : 1;  /*!< Enable EP0 IN STALL handshake                                         */
            __IO uint32_t ENDP_STATE : 2;   /*!< Endpoint Handshake State                                              */
            __IO uint32_t ENDP_EN : 1;      /*!< Enable Endpoint 0 Function                                            */
        } EP0CTL_b;                         /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t EP1CTL; /*!< Offset:0x1C USB Endpoint 1 Control Register                           */

        struct {
            __IO uint32_t ENDP_CNT : 9; /*!< Endpoint byte count                                                   */
            uint32_t : 20;
            __IO uint32_t ENDP_STATE : 2; /*!< Endpoint Handshake State                                              */
            __IO uint32_t ENDP_EN : 1;    /*!< Endpoint 1 Function enable bit                                        */
        } EP1CTL_b;                       /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t EP2CTL; /*!< Offset:0x20 USB Endpoint 2 Control Register                           */

        struct {
            __IO uint32_t ENDP_CNT : 9; /*!< Endpoint byte count                                                   */
            uint32_t : 20;
            __IO uint32_t ENDP_STATE : 2; /*!< Endpoint Handshake State                                              */
            __IO uint32_t ENDP_EN : 1;    /*!< Endpoint 2 Function enable bit                                        */
        } EP2CTL_b;                       /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t EP3CTL; /*!< Offset:0x24 USB Endpoint 3 Control Register                           */

        struct {
            __IO uint32_t ENDP_CNT : 9; /*!< Endpoint byte count                                                   */
            uint32_t : 20;
            __IO uint32_t ENDP_STATE : 2; /*!< Endpoint Handshake State                                              */
            __IO uint32_t ENDP_EN : 1;    /*!< Endpoint 3 Function enable bit                                        */
        } EP3CTL_b;                       /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t EP4CTL; /*!< Offset:0x28 USB Endpoint 4 Control Register                           */

        struct {
            __IO uint32_t ENDP_CNT : 9; /*!< Endpoint byte count                                                   */
            uint32_t : 20;
            __IO uint32_t ENDP_STATE : 2; /*!< Endpoint Handshake State                                              */
            __IO uint32_t ENDP_EN : 1;    /*!< Endpoint 4 Function enable bit                                        */
        } EP4CTL_b;                       /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t EP5CTL; /*!< Offset:0x2C USB Endpoint 5 Control Register                           */

        struct {
            __IO uint32_t ENDP_CNT : 9; /*!< Endpoint byte count                                                   */
            uint32_t : 20;
            __IO uint32_t ENDP_STATE : 2; /*!< Endpoint Handshake State                                              */
            __IO uint32_t ENDP_EN : 1;    /*!< Endpoint 5 Function enable bit                                        */
        } EP5CTL_b;                       /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t EP6CTL; /*!< Offset:0x30 USB Endpoint 6 Control Register                           */

        struct {
            __IO uint32_t ENDP_CNT : 9; /*!< Endpoint byte count                                                   */
            uint32_t : 20;
            __IO uint32_t ENDP_STATE : 2; /*!< Endpoint Handshake State                                              */
            __IO uint32_t ENDP_EN : 1;    /*!< Endpoint 6 Function enable bit                                        */
        } EP6CTL_b;                       /*!< BitSize                                                               */
    };
    __I uint32_t RESERVED[2];

    union {
        __IO uint32_t EPTOGGLE; /*!< Offset:0x3C USB Endpoint Data Toggle Register                         */

        struct {
            __IO uint32_t ENDP1_DATA01 : 1; /*!< Endpoint 1 data toggle bit                                            */
            __IO uint32_t ENDP2_DATA01 : 1; /*!< Endpoint 2 data toggle bit                                            */
            __IO uint32_t ENDP3_DATA01 : 1; /*!< Endpoint 3 data toggle bit                                            */
            __IO uint32_t ENDP4_DATA01 : 1; /*!< Endpoint 4 data toggle bit                                            */
            __IO uint32_t ENDP5_DATA01 : 1; /*!< Endpoint 5 data toggle bit                                            */
            __IO uint32_t ENDP6_DATA01 : 1; /*!< Endpoint 6 data toggle bit                                            */
        } EPTOGGLE_b;                       /*!< BitSize                                                               */
    };
    __I uint32_t RESERVED1[2];

    union {
        __IO uint32_t EP1BUFOS; /*!< Offset:0x48 USB Endpoint 1 Buffer Offset Register                     */

        struct {
            uint32_t : 2;
            __IO uint32_t OFFSET : 7; /*!< The offset address for endpoint data buffer                           */
        } EP1BUFOS_b;                 /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t EP2BUFOS; /*!< Offset:0x4C USB Endpoint 2 Buffer Offset Register                     */

        struct {
            uint32_t : 2;
            __IO uint32_t OFFSET : 7; /*!< The offset address for endpoint data buffer                           */
        } EP2BUFOS_b;                 /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t EP3BUFOS; /*!< Offset:0x50 USB Endpoint 3 Buffer Offset Register                     */

        struct {
            uint32_t : 2;
            __IO uint32_t OFFSET : 7; /*!< The offset address for endpoint data buffer                           */
        } EP3BUFOS_b;                 /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t EP4BUFOS; /*!< Offset:0x54 USB Endpoint 4 Buffer Offset Register                     */

        struct {
            uint32_t : 2;
            __IO uint32_t OFFSET : 7; /*!< The offset address for endpoint data buffer                           */
        } EP4BUFOS_b;                 /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t EP5BUFOS; /*!< Offset:0x58 USB Endpoint 5 Buffer Offset Register                     */

        struct {
            uint32_t : 2;
            __IO uint32_t OFFSET : 7; /*!< The offset address for endpoint data buffer                           */
        } EP5BUFOS_b;                 /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t EP6BUFOS; /*!< Offset:0x5C USB Endpoint 6 Buffer Offset Register                     */

        struct {
            uint32_t : 2;
            __IO uint32_t OFFSET : 7; /*!< The offset address for endpoint data buffer                           */
        } EP6BUFOS_b;                 /*!< BitSize                                                               */
    };

    union {
        __I uint32_t FRMNO; /*!< Offset:0x60 USB Frame Number Register                                 */

        struct {
            __IO uint32_t FRAME_NO : 11; /*!< The 11-bit frame number of the SOF packet                             */
        } FRMNO_b;                       /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t PHYPRM; /*!< Offset:0x64 USB PHY Parameter Register                                */

        struct {
            uint32_t : 26;
            __IO uint32_t PHY_PARAM : 6; /*!< The USB PHY parameter value                                           */
        } PHYPRM_b;                      /*!< BitSize                                                               */
    };
    __I uint32_t  RESERVED2[38];
    __IO uint32_t SRAM; /*!< Offset:0x100 USB SRAM starting address                                */
} SN_USB_Type;

/* ================================================================================ */
/* ================                     SN_LCD                     ================ */
/* ================================================================================ */

/**
 * @brief 4 x 32 LCD Driver (SN_LCD)
 */

typedef struct { /*!< SN_LCD Structure                                                      */

    union {
        __IO uint32_t CTRL; /*!< Offset:0x00 LCD Control register                                      */

        struct {
            __IO uint32_t LCDENB : 1;  /*!< LCD driver enable bit                                                 */
            __IO uint32_t ITB : 1;     /*!< Internal testing bit                                                  */
            __IO uint32_t LCDTYPE : 2; /*!< LCD type control bit                                                  */
            __IO uint32_t BIAS : 1;    /*!< LCD bias selection                                                    */
            __IO uint32_t SEGSEL1 : 1; /*!< SEG12~23 enable bit                                                   */
            __IO uint32_t SEGSEL2 : 1; /*!< SEG24~31 enable bit                                                   */
            uint32_t : 1;
            __IO uint32_t DUTY : 2;    /*!< Duty selection                                                        */
            __IO uint32_t LCDCLK : 1;  /*!< LCD clock source selection                                            */
            __IO uint32_t LCDRATE : 1; /*!< LCD clock rate                                                        */
            uint32_t : 16;
            __IO uint32_t DRIVEP : 2; /*!< LCD panel driving ability                                             */
        } CTRL_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CTRL1; /*!< Offset:0x04 LCD Control register 1                                    */

        struct {
            __IO uint32_t LCDBNK : 1; /*!< LCD blank control bit                                                 */
            __IO uint32_t REF : 2;    /*!< Resistance selection for LCD Bias Voltage-division                    */
            uint32_t : 25;
            __IO uint32_t ITB : 1; /*!< Internal testing bit                                                  */
        } CTRL1_b;                 /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CCTRL1; /*!< Offset:0x08 LCD C-Type Control register 1                             */

        struct {
            __IO uint32_t VCP : 4; /*!< C-Type VLCD output voltage                                            */
            uint32_t : 22;
            __IO uint32_t IT2 : 2; /*!< Internal testing bits                                                 */
            __IO uint32_t IT1 : 2; /*!< Internal testing bits                                                 */
        } CCTRL1_b;                /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t CCTRL2; /*!< Offset:0x0C LCD C-Type Control register 2                             */

        struct {
            uint32_t : 1;
            __IO uint32_t IT : 3; /*!< Internal testing bits                                                 */
        } CCTRL2_b;               /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t FCC; /*!< Offset:0x10 LCD Frame Counter Control register                        */

        struct {
            __IO uint32_t FCENB : 1; /*!< LCD frame counter enable bit                                          */
            __IO uint32_t FCT : 6;   /*!< LCD frame counter threshold value                                     */
            __IO uint32_t FCIE : 1;  /*!< LCD frame interrupt enable bit                                        */
        } FCC_b;                     /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t RIS; /*!< Offset:0x14 LCD Raw Interrupt Status register                         */

        struct {
            __IO uint32_t FCIF : 1; /*!< LCD frame interrupt flag                                              */
        } RIS_b;                    /*!< BitSize                                                               */
    };
    __I uint32_t RESERVED[2];

    union {
        __IO uint32_t SEGM0; /*!< Offset:0x20 LCD SEG Memory register 0                                 */

        struct {
            __IO uint32_t SEG0 : 4; /*!< SEG0 data for COM0~COM3                                               */
            __IO uint32_t SEG1 : 4; /*!< SEG1 data for COM0~COM3                                               */
            __IO uint32_t SEG2 : 4; /*!< SEG2 data for COM0~COM3                                               */
            __IO uint32_t SEG3 : 4; /*!< SEG3 data for COM0~COM3                                               */
            __IO uint32_t SEG4 : 4; /*!< SEG4 data for COM0~COM3                                               */
            __IO uint32_t SEG5 : 4; /*!< SEG5 data for COM0~COM3                                               */
            __IO uint32_t SEG6 : 4; /*!< SEG6 data for COM0~COM3                                               */
            __IO uint32_t SEG7 : 4; /*!< SEG7 data for COM0~COM3                                               */
        } SEGM0_b;                  /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t SEGM1; /*!< Offset:0x24 LCD SEG Memory register 1                                 */

        struct {
            __IO uint32_t SEG8 : 4;  /*!< SEG8 data for COM0~COM3                                               */
            __IO uint32_t SEG9 : 4;  /*!< SEG9 data for COM0~COM3                                               */
            __IO uint32_t SEG10 : 4; /*!< SEG10 data for COM0~COM3                                              */
            __IO uint32_t SEG11 : 4; /*!< SEG11 data for COM0~COM3                                              */
            __IO uint32_t SEG12 : 4; /*!< SEG12 data for COM0~COM3                                              */
            __IO uint32_t SEG13 : 4; /*!< SEG13 data for COM0~COM3                                              */
            __IO uint32_t SEG14 : 4; /*!< SEG14 data for COM0~COM3                                              */
            __IO uint32_t SEG15 : 4; /*!< SEG15 data for COM0~COM3                                              */
        } SEGM1_b;                   /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t SEGM2; /*!< Offset:0x28 LCD SEG Memory register 2                                 */

        struct {
            __IO uint32_t SEG16 : 4; /*!< SEG16 data for COM0~COM3                                              */
            __IO uint32_t SEG17 : 4; /*!< SEG17 data for COM0~COM3                                              */
            __IO uint32_t SEG18 : 4; /*!< SEG18 data for COM0~COM3                                              */
            __IO uint32_t SEG19 : 4; /*!< SEG19 data for COM0~COM3                                              */
            __IO uint32_t SEG20 : 4; /*!< SEG20 data for COM0~COM3                                              */
            __IO uint32_t SEG21 : 4; /*!< SEG21 data for COM0~COM3                                              */
            __IO uint32_t SEG22 : 4; /*!< SEG22 data for COM0~COM3                                              */
            __IO uint32_t SEG23 : 4; /*!< SEG23 data for COM0~COM3                                              */
        } SEGM2_b;                   /*!< BitSize                                                               */
    };

    union {
        __IO uint32_t SEGM3; /*!< Offset:0x2C LCD SEG Memory register 3                                 */

        struct {
            __IO uint32_t SEG24 : 4; /*!< SEG24 data for COM0~COM3                                              */
            __IO uint32_t SEG25 : 4; /*!< SEG25 data for COM0~COM3                                              */
            __IO uint32_t SEG26 : 4; /*!< SEG26 data for COM0~COM3                                              */
            __IO uint32_t SEG27 : 4; /*!< SEG27 data for COM0~COM3                                              */
            __IO uint32_t SEG28 : 4; /*!< SEG28 data for COM0~COM3                                              */
            __IO uint32_t SEG29 : 4; /*!< SEG29 data for COM0~COM3                                              */
            __IO uint32_t SEG30 : 4; /*!< SEG30 data for COM0~COM3                                              */
            __IO uint32_t SEG31 : 4; /*!< SEG31 data for COM0~COM3                                              */
        } SEGM3_b;                   /*!< BitSize                                                               */
    };
} SN_LCD_Type;

/* ================================================================================ */
/* ================                      SN_UC                     ================ */
/* ================================================================================ */

/**
 * @brief UC Registers (SN_UC)
 */

typedef struct {         /*!< SN_UC Structure                                                       */
    __I uint32_t L4BYTE; /*!< Offset:0x00 UC Low 4 Byte Register                                    */
    __I uint32_t H4BYTE; /*!< Offset:0x04 UC High 4 Byte Register                                   */
} SN_UC_Type;

/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
#    pragma pop
#elif defined(__ICCARM__)
/* leave anonymous unions enabled */
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
#    pragma warning restore
#else
#    warning Not supported compiler type
#endif

/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

#define SN_SYS0_BASE 0x40060000UL
#define SN_SYS1_BASE 0x4005E000UL
#define SN_GPIO0_BASE 0x40044000UL
#define SN_GPIO1_BASE 0x40046000UL
#define SN_GPIO3_BASE 0x4004A000UL
#define SN_GPIO2_BASE 0x40048000UL
#define SN_ADC_BASE 0x40026000UL
#define SN_WDT_BASE 0x40010000UL
#define SN_RTC_BASE 0x40012000UL
#define SN_CT16B0_BASE 0x40000000UL
#define SN_CT16B1_BASE 0x40002000UL
#define SN_CT16B2_BASE 0x40004000UL
#define SN_CT32B0_BASE 0x40006000UL
#define SN_CT32B1_BASE 0x40008000UL
#define SN_CT32B2_BASE 0x4000A000UL
#define SN_PMU_BASE 0x40032000UL
#define SN_SSP0_BASE 0x4001C000UL
#define SN_SSP1_BASE 0x40058000UL
#define SN_I2C0_BASE 0x40018000UL
#define SN_I2C1_BASE 0x4005A000UL
#define SN_USART0_BASE 0x40016000UL
#define SN_USART1_BASE 0x40056000UL
#define SN_I2S_BASE 0x4001A000UL
#define SN_FLASH_BASE 0x40062000UL
#define SN_PFPA_BASE 0x40042000UL
#define SN_USB_BASE 0x4005C000UL
#define SN_LCD_BASE 0x40034000UL
#define SN_UC_BASE 0x1FFF2C08UL

/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define SN_SYS0 ((SN_SYS0_Type *)SN_SYS0_BASE)
#define SN_SYS1 ((SN_SYS1_Type *)SN_SYS1_BASE)
#define SN_GPIO0 ((SN_GPIO0_Type *)SN_GPIO0_BASE)
#define SN_GPIO1 ((SN_GPIO0_Type *)SN_GPIO1_BASE)
#define SN_GPIO3 ((SN_GPIO0_Type *)SN_GPIO3_BASE)
#define SN_GPIO2 ((SN_GPIO2_Type *)SN_GPIO2_BASE)
#define SN_ADC ((SN_ADC_Type *)SN_ADC_BASE)
#define SN_WDT ((SN_WDT_Type *)SN_WDT_BASE)
#define SN_RTC ((SN_RTC_Type *)SN_RTC_BASE)
#define SN_CT16B0 ((SN_CT16B0_Type *)SN_CT16B0_BASE)
#define SN_CT16B1 ((SN_CT16B0_Type *)SN_CT16B1_BASE)
#define SN_CT16B2 ((SN_CT16B0_Type *)SN_CT16B2_BASE)
#define SN_CT32B0 ((SN_CT32B0_Type *)SN_CT32B0_BASE)
#define SN_CT32B1 ((SN_CT32B0_Type *)SN_CT32B1_BASE)
#define SN_CT32B2 ((SN_CT32B0_Type *)SN_CT32B2_BASE)
#define SN_PMU ((SN_PMU_Type *)SN_PMU_BASE)
#define SN_SSP0 ((SN_SSP0_Type *)SN_SSP0_BASE)
#define SN_SSP1 ((SN_SSP0_Type *)SN_SSP1_BASE)
#define SN_I2C0 ((SN_I2C0_Type *)SN_I2C0_BASE)
#define SN_I2C1 ((SN_I2C0_Type *)SN_I2C1_BASE)
#define SN_USART0 ((SN_USART0_Type *)SN_USART0_BASE)
#define SN_USART1 ((SN_USART0_Type *)SN_USART1_BASE)
#define SN_I2S ((SN_I2S_Type *)SN_I2S_BASE)
#define SN_FLASH ((SN_FLASH_Type *)SN_FLASH_BASE)
#define SN_PFPA ((SN_PFPA_Type *)SN_PFPA_BASE)
#define SN_USB ((SN_USB_Type *)SN_USB_BASE)
#define SN_LCD ((SN_LCD_Type *)SN_LCD_BASE)
#define SN_UC ((SN_UC_Type *)SN_UC_BASE)

/** @} */ /* End of group Device_Peripheral_Registers */
/** @} */ /* End of group SN32F240 */
/** @} */ /* End of group SONiX Technology Co., Ltd. */

#ifdef __cplusplus
}
#endif

#endif /* SN32F240_H */