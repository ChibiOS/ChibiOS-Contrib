
/****************************************************************************************************//**
 * @file     SN32F260.h
 *
 * @brief    CMSIS Cortex-M0 Peripheral Access Layer Header File for
 *           SN32F260 from SONiX Technology Co., Ltd..
 *
 * @version  V1.1
 * @date     22. March 2017
 *
 * @note     Generated with SVDConv V2.87e 
 *           from CMSIS SVD File 'SN32F260.svd' Version 1.1,
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

/** @addtogroup SN32F260
  * @{
  */

#ifndef SN32F260_H
#define SN32F260_H

#ifdef __cplusplus
extern "C" {
#endif


/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum {
/* -------------------  Cortex-M0 Processor Exceptions Numbers  ------------------- */
  Reset_IRQn                    = -15,              /*!<   1  Reset Vector, invoked on Power up and warm reset                 */
  NonMaskableInt_IRQn           = -14,              /*!<   2  Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                = -13,              /*!<   3  Hard Fault, all classes of Fault                                 */
  SVCall_IRQn                   =  -5,              /*!<  11  System Service Call via SVC instruction                          */
  PendSV_IRQn                   =  -2,              /*!<  14  Pendable request for system service                              */
  SysTick_IRQn                  =  -1,              /*!<  15  System Tick Timer                                                */
/* ---------------------  SN32F260 Specific Interrupt Numbers  -------------------- */
  NDT_IRQn                      =   0,              /*!<   0  NDT                                                              */
  USB_IRQn                      =   1,              /*!<   1  USB                                                              */
  SPI0_IRQn                     =  13,              /*!<  13  SPI0                                                             */
  I2C0_IRQn                     =  15,              /*!<  15  I2C0                                                             */
  CT16B0_IRQn                   =  16,              /*!<  16  CT16B0                                                           */
  CT16B1_IRQn                   =  17,              /*!<  17  CT16B1                                                           */
  WDT_IRQn                      =  25,              /*!<  25  WDT                                                              */
  LVD_IRQn                      =  26,              /*!<  26  LVD                                                              */
  P3_IRQn                       =  28,              /*!<  28  P3                                                               */
  P2_IRQn                       =  29,              /*!<  29  P2                                                               */
  P1_IRQn                       =  30,              /*!<  30  P1                                                               */
  P0_IRQn                       =  31               /*!<  31  P0                                                               */
} IRQn_Type;


/** @addtogroup Configuration_of_CMSIS
  * @{
  */


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* ----------------Configuration of the Cortex-M0 Processor and Core Peripherals---------------- */
#define __CM0_REV                 0x0000            /*!< Cortex-M0 Core Revision                                               */
#define __MPU_PRESENT                  0            /*!< MPU present or not                                                    */
#define __NVIC_PRIO_BITS               2            /*!< Number of Bits used for Priority Levels                               */
#define __Vendor_SysTickConfig         0            /*!< Set to 1 if different SysTick Config is used                          */
/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm0.h"                               /*!< Cortex-M0 processor and core peripherals                              */
#include "system_SN32F260.h"                        /*!< SN32F260 System                                                       */


/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */


/** @addtogroup Device_Peripheral_Registers
  * @{
  */


/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif



/* ================================================================================ */
/* ================                     SN_SYS0                    ================ */
/* ================================================================================ */


/**
  * @brief System Control Registers (SN_SYS0)
  */

typedef struct {                                    /*!< SN_SYS0 Structure                                                     */
  
  union {
    __IO uint32_t  ANBCTRL;                         /*!< Offset:0x00 Analog Block Control Register                             */
    
    struct {
      __IO uint32_t  IHRCEN     :  1;               /*!< IHRC enable                                                           */
    } ANBCTRL_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED;
  
  union {
    __I  uint32_t  CSST;                            /*!< Offset:0x08 Clock Source Status Register                              */
    
    struct {
      __I  uint32_t  IHRCRDY    :  1;               /*!< IHRC ready flag                                                       */
    } CSST_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CLKCFG;                          /*!< Offset:0x0C System Clock Configuration Register                       */
    
    struct {
      __IO uint32_t  SYSCLKSEL  :  3;               /*!< System clock source selection                                         */
           uint32_t             :  1;
      __I  uint32_t  SYSCLKST   :  3;               /*!< System clock switch status                                            */
    } CLKCFG_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  AHBCP;                           /*!< Offset:0x10 AHB Clock Prescale Register                               */
    
    struct {
      __IO uint32_t  AHBPRE     :  3;               /*!< AHB clock source prescaler                                            */
    } AHBCP_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RSTST;                           /*!< Offset:0x14 System Reset Status Register                              */
    
    struct {
      __IO uint32_t  SWRSTF     :  1;               /*!< Software reset flag                                                   */
      __IO uint32_t  WDTRSTF    :  1;               /*!< WDT reset flag                                                        */
      __IO uint32_t  LVDRSTF    :  1;               /*!< LVD reset flag                                                        */
      __IO uint32_t  EXTRSTF    :  1;               /*!< External reset flag                                                   */
      __IO uint32_t  PORRSTF    :  1;               /*!< POR reset flag                                                        */
    } RSTST_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  LVDCTRL;                         /*!< Offset:0x18 LVD Control Register                                      */
    
    struct {
      __IO uint32_t  LVDRSTLVL  :  3;               /*!< LVD reset level                                                       */
           uint32_t             :  2;
      __IO uint32_t  LVDINTLVL  :  2;               /*!< LVD interrupt level                                                   */
           uint32_t             :  7;
      __IO uint32_t  LVDRSTEN   :  1;               /*!< LVD Reset enable                                                      */
      __IO uint32_t  LVDEN      :  1;               /*!< LVD enable                                                            */
    } LVDCTRL_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  EXRSTCTRL;                       /*!< Offset:0x1C External Reset Pin Control Register                       */
    
    struct {
      __IO uint32_t  RESETDIS   :  1;               /*!< External reset pin disable                                            */
    } EXRSTCTRL_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SWDCTRL;                         /*!< Offset:0x20 SWD Pin Control Register                                  */
    
    struct {
      __IO uint32_t  SWDDIS     :  1;               /*!< SWD pin disable                                                       */
    } SWDCTRL_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IVTM;                            /*!< Offset:0x24 Interrupt Vector Table Mapping Register                   */
    
    struct {
      __IO uint32_t  IVTM       :  2;               /*!< Interrupt table mapping selection                                     */
           uint32_t             : 14;
      __O  uint32_t  IVTMKEY    : 16;               /*!< IVTMKEY register key                                                  */
    } IVTM_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  NDTCTRL;                         /*!< Offset:0x28 Noise Detect Control Register                             */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  NDT5V_IE   :  1;               /*!< NDT for VDD interrupt enable bit                                      */
    } NDTCTRL_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  NDTSTS;                          /*!< Offset:0x2C Noise Detect Status Register                              */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  NDT5V_DET  :  1;               /*!< Power noise status of NDT5V IP                                        */
    } NDTSTS_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ANTIEFT;                         /*!< Offset:0x30 Anti-EFT Ability Control Register                         */
    
    struct {
      __IO uint32_t  AEFT       :  3;               /*!< Anti-EFT ability                                                      */
    } ANTIEFT_b;                                    /*!< BitSize                                                               */
  };
} SN_SYS0_Type;


/* ================================================================================ */
/* ================                     SN_SYS1                    ================ */
/* ================================================================================ */


/**
  * @brief System Control Registers (SN_SYS1)
  */

typedef struct {                                    /*!< SN_SYS1 Structure                                                     */
  
  union {
    __IO uint32_t  AHBCLKEN;                        /*!< Offset:0x00 AHB Clock Enable Register                                 */
    
    struct {
      __IO uint32_t  P0CLKEN    :  1;               /*!< Enable AHB clock for P0                                               */
      __IO uint32_t  P1CLKEN    :  1;               /*!< Enable AHB clock for P1                                               */
      __IO uint32_t  P2CLKEN    :  1;               /*!< Enable AHB clock for P2                                               */
      __IO uint32_t  P3CLKEN    :  1;               /*!< Enable AHB clock for P3                                               */
      __IO uint32_t  USBCLKEN   :  1;               /*!< Enable AHB clock for USB                                              */
           uint32_t             :  1;
      __IO uint32_t  CT16B0CLKEN:  1;               /*!< Enable AHB clock for CT16B0                                           */
      __IO uint32_t  CT16B1CLKEN:  1;               /*!< Enable AHB clock for CT16B1                                           */
           uint32_t             :  4;
      __IO uint32_t  SPI0CLKEN  :  1;               /*!< Enable AHB clock for SPI0                                             */
           uint32_t             :  8;
      __IO uint32_t  I2C0CLKEN  :  1;               /*!< Enable AHB clock for I2C0                                             */
           uint32_t             :  2;
      __IO uint32_t  WDTCLKEN   :  1;               /*!< Enable AHB clock for WDT                                              */
           uint32_t             :  3;
      __IO uint32_t  CLKOUTSEL  :  3;               /*!< Clock output source selection                                         */
    } AHBCLKEN_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  APBCP1;                          /*!< Offset:0x08 APB Clock Prescale Register 1                             */
    
    struct {
           uint32_t             : 16;
      __IO uint32_t  SYSTICKPRE :  2;               /*!< SysTick APB clock source prescaler                                    */
           uint32_t             :  2;
      __IO uint32_t  WDTPRE     :  3;               /*!< WDT APB clock source prescaler                                        */
           uint32_t             :  5;
      __IO uint32_t  CLKOUTPRE  :  3;               /*!< CLKOUT APB clock source prescaler                                     */
    } APBCP1_b;                                     /*!< BitSize                                                               */
  };
} SN_SYS1_Type;


/* ================================================================================ */
/* ================                     SN_USB                     ================ */
/* ================================================================================ */


/**
  * @brief Universal Serial Bus Full Speed Device Interface (USB) (SN_USB)
  */

typedef struct {                                    /*!< SN_USB Structure                                                      */
  
  union {
    __IO uint32_t  INTEN;                           /*!< Offset:0x00 USB Interrupt Enable Register                             */
    
    struct {
      __IO uint32_t  EP1_NAK_EN :  1;               /*!< EP1 NAK Interrupt Enable                                              */
      __IO uint32_t  EP2_NAK_EN :  1;               /*!< EP2 NAK Interrupt Enable                                              */
      __IO uint32_t  EP3_NAK_EN :  1;               /*!< EP3 NAK Interrupt Enable                                              */
      __IO uint32_t  EP4_NAK_EN :  1;               /*!< EP4 NAK Interrupt Enable                                              */
      __IO uint32_t  EPN_ACK_EN :  1;               /*!< Enable all of EP(1~4) ACK Interrupt                                   */
           uint32_t             : 23;
      __IO uint32_t  BUSWK_IE   :  1;               /*!< Bus Wake Up Interrupt Enable                                          */
      __IO uint32_t  USB_IE     :  1;               /*!< USB Event Interrupt Enable                                            */
      __IO uint32_t  USB_SOF_IE :  1;               /*!< USB SOF Interrupt Enable                                              */
      __IO uint32_t  BUS_IE     :  1;               /*!< Bus Event Interrupt Enable                                            */
    } INTEN_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  INSTS;                           /*!< Offset:0x04 USB Interrupt Event Status Register                       */
    
    struct {
      __I  uint32_t  EP1_NAK    :  1;               /*!< Endpoint 1 NAK transaction flag                                       */
      __I  uint32_t  EP2_NAK    :  1;               /*!< Endpoint 2 NAK transaction flag                                       */
      __I  uint32_t  EP3_NAK    :  1;               /*!< Endpoint 3 NAK transaction flag                                       */
      __I  uint32_t  EP4_NAK    :  1;               /*!< Endpoint 4 NAK transaction flag                                       */
           uint32_t             :  4;
      __I  uint32_t  EP1_ACK    :  1;               /*!< Endpoint 1 ACK transaction flag                                       */
      __I  uint32_t  EP2_ACK    :  1;               /*!< Endpoint 2 ACK transaction flag                                       */
      __I  uint32_t  EP3_ACK    :  1;               /*!< Endpoint 3 ACK transaction flag                                       */
      __I  uint32_t  EP4_ACK    :  1;               /*!< Endpoint 4 ACK transaction flag                                       */
           uint32_t             :  5;
      __I  uint32_t  ERR_TIMEOUT:  1;               /*!< Timeout Status                                                        */
      __I  uint32_t  ERR_SETUP  :  1;               /*!< Wrong Setup data received                                             */
      __I  uint32_t  EP0_OUT_STALL:  1;             /*!< EP0 OUT STALL transaction                                             */
      __I  uint32_t  EP0_IN_STALL:  1;              /*!< EP0 IN STALL Transaction is completed                                 */
      __I  uint32_t  EP0_OUT    :  1;               /*!< EP0 OUT ACK Transaction Flag                                          */
      __I  uint32_t  EP0_IN     :  1;               /*!< EP0 IN ACK Transaction Flag                                           */
      __I  uint32_t  EP0_SETUP  :  1;               /*!< EP0 Setup Transaction Flag                                            */
      __I  uint32_t  EP0_PRESETUP:  1;              /*!< EP0 Setup Token Packet Flag                                           */
           uint32_t             :  1;
      __I  uint32_t  USB_SOF    :  1;               /*!< USB SOF packet received flag                                          */
           uint32_t             :  2;
      __I  uint32_t  BUS_RESUME :  1;               /*!< USB Bus Resume signal flag                                            */
      __I  uint32_t  BUS_SUSPEND:  1;               /*!< USB Bus Suspend signal flag                                           */
      __I  uint32_t  BUS_RESET  :  1;               /*!< USB Bus Reset signal flag                                             */
    } INSTS_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  INSTSC;                          /*!< Offset:0x08 USB Interrupt Event Status Clear Register                 */
    
    struct {
      __O  uint32_t  EP1_NAKC   :  1;               /*!< EP1 NAK clear bit                                                     */
      __O  uint32_t  EP2_NAKC   :  1;               /*!< EP2 NAK clear bit                                                     */
      __O  uint32_t  EP3_NAKC   :  1;               /*!< EP3 NAK clear bit                                                     */
      __O  uint32_t  EP4_NAKC   :  1;               /*!< EP4 NAK clear bit                                                     */
           uint32_t             :  4;
      __O  uint32_t  EP1_ACKC   :  1;               /*!< EP1 ACK clear bit                                                     */
      __O  uint32_t  EP2_ACKC   :  1;               /*!< EP2 ACK clear bit                                                     */
      __O  uint32_t  EP3_ACKC   :  1;               /*!< EP3 ACK clear bit                                                     */
      __O  uint32_t  EP4_ACKC   :  1;               /*!< EP4 ACK clear bit                                                     */
           uint32_t             :  5;
      __O  uint32_t  ERR_TIMEOUTC:  1;              /*!< Timeout Error clear bit                                               */
      __O  uint32_t  ERR_SETUPC :  1;               /*!< Error Setup clear bit                                                 */
      __O  uint32_t  EP0_OUT_STALLC:  1;            /*!< EP0 OUT STALL clear bit                                               */
      __O  uint32_t  EP0_IN_STALLC:  1;             /*!< EP0 IN STALL clear bit                                                */
      __O  uint32_t  EP0_OUTC   :  1;               /*!< EP0 OUT clear bit                                                     */
      __O  uint32_t  EP0_INC    :  1;               /*!< EP0 IN clear bit                                                      */
      __O  uint32_t  EP0_SETUPC :  1;               /*!< EP0 SETUP clear bit                                                   */
      __O  uint32_t  EP0_PRESETUPC:  1;             /*!< EP0 PRESETUP clear bit                                                */
      __O  uint32_t  BUS_WAKEUPC:  1;               /*!< Bus Wakeup clear bit                                                  */
      __O  uint32_t  USB_SOFC   :  1;               /*!< USB SOF clear bit                                                     */
           uint32_t             :  2;
      __O  uint32_t  BUS_RESUMEC:  1;               /*!< USB Bus Resume clear bit                                              */
           uint32_t             :  1;
      __O  uint32_t  BUS_RESETC :  1;               /*!< USB Bus Reset clear bit                                               */
    } INSTSC_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR;                            /*!< Offset:0x0C USB Device Address Register                               */
    
    struct {
      __IO uint32_t  UADDR      :  7;               /*!< USB device's address                                                  */
    } ADDR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CFG;                             /*!< Offset:0x10 USB Configuration Register                                */
    
    struct {
      __IO uint32_t  EP1_DIR    :  1;               /*!< Endpoint 1 IN/OUT direction setting                                   */
      __IO uint32_t  EP2_DIR    :  1;               /*!< Endpoint 2 IN/OUT direction setting                                   */
      __IO uint32_t  EP3_DIR    :  1;               /*!< Endpoint 3 IN/OUT direction setting                                   */
      __IO uint32_t  EP4_DIR    :  1;               /*!< Endpoint 4 IN/OUT direction setting                                   */
           uint32_t             : 22;
      __IO uint32_t  DIS_PDEN   :  1;               /*!< Enable internal D+ and D- 175k pull-down resistor                     */
      __IO uint32_t  ESD_EN     :  1;               /*!< Enable USB anti-ESD protection                                        */
      __IO uint32_t  SIE_EN     :  1;               /*!< USB Serial Interface Engine Enable                                    */
      __IO uint32_t  DPPU_EN    :  1;               /*!< Enable internal D+ 1.5k pull-up resistor                              */
      __IO uint32_t  PHY_EN     :  1;               /*!< PHY Transceiver Function Enable                                       */
      __IO uint32_t  VREG33_EN  :  1;               /*!< Enable the internal VREG33 ouput                                      */
    } CFG_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SGCTL;                           /*!< Offset:0x14 USB Signal Control Register                               */
    
    struct {
      __IO uint32_t  BUS_DN     :  1;               /*!< USB D- state                                                          */
      __IO uint32_t  BUS_DP     :  1;               /*!< USB DP state                                                          */
      __IO uint32_t  BUS_DRVEN  :  1;               /*!< Enable to drive USB bus                                               */
    } SGCTL_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  EP0CTL;                          /*!< Offset:0x18 USB Endpoint 0 Control Register                           */
    
    struct {
      __IO uint32_t  ENDP_CNT   :  7;               /*!< Endpoint byte count                                                   */
           uint32_t             : 20;
      __IO uint32_t  OUT_STALL_EN:  1;              /*!< Enable EP0 OUT STALL handshake                                        */
      __IO uint32_t  IN_STALL_EN:  1;               /*!< Enable EP0 IN STALL handshake                                         */
      __IO uint32_t  ENDP_STATE :  2;               /*!< Endpoint Handshake State                                              */
      __IO uint32_t  ENDP_EN    :  1;               /*!< Enable Endpoint 0 Function                                            */
    } EP0CTL_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  EP1CTL;                          /*!< Offset:0x1C USB Endpoint 1 Control Register                           */
    
    struct {
      __IO uint32_t  ENDP_CNT   :  7;               /*!< Endpoint byte count                                                   */
           uint32_t             : 22;
      __IO uint32_t  ENDP_STATE :  2;               /*!< Endpoint Handshake State                                              */
      __IO uint32_t  ENDP_EN    :  1;               /*!< Endpoint 1 Function enable bit                                        */
    } EP1CTL_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  EP2CTL;                          /*!< Offset:0x20 USB Endpoint 2 Control Register                           */
    
    struct {
      __IO uint32_t  ENDP_CNT   :  7;               /*!< Endpoint byte count                                                   */
           uint32_t             : 22;
      __IO uint32_t  ENDP_STATE :  2;               /*!< Endpoint Handshake State                                              */
      __IO uint32_t  ENDP_EN    :  1;               /*!< Endpoint 2 Function enable bit                                        */
    } EP2CTL_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  EP3CTL;                          /*!< Offset:0x24 USB Endpoint 3 Control Register                           */
    
    struct {
      __IO uint32_t  ENDP_CNT   :  7;               /*!< Endpoint byte count                                                   */
           uint32_t             : 22;
      __IO uint32_t  ENDP_STATE :  2;               /*!< Endpoint Handshake State                                              */
      __IO uint32_t  ENDP_EN    :  1;               /*!< Endpoint 3 Function enable bit                                        */
    } EP3CTL_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  EP4CTL;                          /*!< Offset:0x28 USB Endpoint 4 Control Register                           */
    
    struct {
      __IO uint32_t  ENDP_CNT   :  7;               /*!< Endpoint byte count                                                   */
           uint32_t             : 22;
      __IO uint32_t  ENDP_STATE :  2;               /*!< Endpoint Handshake State                                              */
      __IO uint32_t  ENDP_EN    :  1;               /*!< Endpoint 4 Function enable bit                                        */
    } EP4CTL_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED[4];
  
  union {
    __IO uint32_t  EPTOGGLE;                        /*!< Offset:0x3C USB Endpoint Data Toggle Register                         */
    
    struct {
      __IO uint32_t  ENDP1_DATA01:  1;              /*!< Endpoint 1 data toggle bit                                            */
      __IO uint32_t  ENDP2_DATA01:  1;              /*!< Endpoint 2 data toggle bit                                            */
      __IO uint32_t  ENDP3_DATA01:  1;              /*!< Endpoint 3 data toggle bit                                            */
      __IO uint32_t  ENDP4_DATA01:  1;              /*!< Endpoint 4 data toggle bit                                            */
    } EPTOGGLE_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1[2];
  
  union {
    __IO uint32_t  EP1BUFOS;                        /*!< Offset:0x48 USB Endpoint 1 Buffer Offset Register                     */
    
    struct {
           uint32_t             :  2;
      __IO uint32_t  OFFSET     :  7;               /*!< The offset address for endpoint data buffer                           */
    } EP1BUFOS_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  EP2BUFOS;                        /*!< Offset:0x4C USB Endpoint 2 Buffer Offset Register                     */
    
    struct {
           uint32_t             :  2;
      __IO uint32_t  OFFSET     :  7;               /*!< The offset address for endpoint data buffer                           */
    } EP2BUFOS_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  EP3BUFOS;                        /*!< Offset:0x50 USB Endpoint 3 Buffer Offset Register                     */
    
    struct {
           uint32_t             :  2;
      __IO uint32_t  OFFSET     :  7;               /*!< The offset address for endpoint data buffer                           */
    } EP3BUFOS_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  EP4BUFOS;                        /*!< Offset:0x54 USB Endpoint 4 Buffer Offset Register                     */
    
    struct {
           uint32_t             :  2;
      __IO uint32_t  OFFSET     :  7;               /*!< The offset address for endpoint data buffer                           */
    } EP4BUFOS_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2[2];
  
  union {
    __I  uint32_t  FRMNO;                           /*!< Offset:0x60 USB Frame Number Register                                 */
    
    struct {
      __IO uint32_t  FRAME_NO   : 11;               /*!< The 11-bit frame number of the SOF packet                             */
    } FRMNO_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PHYPRM;                          /*!< Offset:0x64 USB PHY Parameter Register                                */
    
    struct {
      __IO uint32_t  PHY_PARAM  :  6;               /*!< USB PHY parameter                                                     */
    } PHYPRM_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED3;
  
  union {
    __IO uint32_t  PHYPRM2;                         /*!< Offset:0x6C USB PHY Parameter Register 2                              */
    
    struct {
      __IO uint32_t  PHY_PS     : 15;               /*!< USB PHY parameter 2                                                   */
    } PHYPRM2_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PS2CTL;                          /*!< Offset:0x70 PS/2 Control Register                                     */
    
    struct {
      __IO uint32_t  SCKM       :  1;               /*!< PS/2 SCK mode control bit                                             */
      __IO uint32_t  SDAM       :  1;               /*!< PS/2 SDA mode control bit                                             */
      __IO uint32_t  SCK        :  1;               /*!< PS/2 SCK data buffer                                                  */
      __IO uint32_t  SDA        :  1;               /*!< PS/2 SDA data buffer                                                  */
           uint32_t             : 27;
      __IO uint32_t  PS2ENB     :  1;               /*!< PS/2 internal 5kohm pull-up resistor control bit                      */
    } PS2CTL_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED4;
  
  union {
    __IO uint32_t  RWADDR;                          /*!< Offset:0x78 USB Read/Write Address Register                           */
    
    struct {
           uint32_t             :  2;
      __IO uint32_t  RWADDR     :  6;               /*!< USB FIFO address to be read or written from/to USB FIFO               */
    } RWADDR_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RWDATA;                          /*!< Offset:0x7C USB Read/Write Data Register                              */
    
    struct {
      __IO uint32_t  RWDATA     : 32;               /*!< Data to be read or written from/to USB FIFO                           */
    } RWDATA_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RWSTATUS;                        /*!< Offset:0x80 USB Read/Write Status Register                            */
    
    struct {
      __IO uint32_t  W_STATUS   :  1;               /*!< Write status of USB FIFO                                              */
      __IO uint32_t  R_STATUS   :  1;               /*!< WRead status of USB FIFO                                              */
    } RWSTATUS_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RWADDR2;                         /*!< Offset:0x84 USB Read/Write Address Register 2                         */
    
    struct {
           uint32_t             :  2;
      __IO uint32_t  RWADDR     :  6;               /*!< USB FIFO address to be read or written from/to USB FIFO               */
    } RWADDR2_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RWDATA2;                         /*!< Offset:0x88 USB Read/Write Data Register 2                            */
    
    struct {
      __IO uint32_t  RWDATA     : 32;               /*!< Data to be read or written from/to USB FIFO                           */
    } RWDATA2_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RWSTATUS2;                       /*!< Offset:0x8C USB Read/Write Status Register 2                          */
    
    struct {
      __IO uint32_t  W_STATUS   :  1;               /*!< Write status of USB FIFO                                              */
      __IO uint32_t  R_STATUS   :  1;               /*!< WRead status of USB FIFO                                              */
    } RWSTATUS2_b;                                  /*!< BitSize                                                               */
  };
} SN_USB_Type;


/* ================================================================================ */
/* ================                    SN_GPIO0                    ================ */
/* ================================================================================ */


/**
  * @brief General Purpose I/O (SN_GPIO0)
  */

typedef struct {                                    /*!< SN_GPIO0 Structure                                                    */
  
  union {
    __IO uint32_t  DATA;                            /*!< Offset:0x00 GPIO Port n Data Register                                 */
    
    struct {
      __IO uint32_t  DATA0      :  1;               /*!< Data of Pn.0                                                          */
      __IO uint32_t  DATA1      :  1;               /*!< Data of Pn.1                                                          */
      __IO uint32_t  DATA2      :  1;               /*!< Data of Pn.2                                                          */
      __IO uint32_t  DATA3      :  1;               /*!< Data of Pn.3                                                          */
      __IO uint32_t  DATA4      :  1;               /*!< Data of Pn.4                                                          */
      __IO uint32_t  DATA5      :  1;               /*!< Data of Pn.5                                                          */
      __IO uint32_t  DATA6      :  1;               /*!< Data of Pn.6                                                          */
      __IO uint32_t  DATA7      :  1;               /*!< Data of Pn.7                                                          */
      __IO uint32_t  DATA8      :  1;               /*!< Data of Pn.8                                                          */
      __IO uint32_t  DATA9      :  1;               /*!< Data of Pn.9                                                          */
      __IO uint32_t  DATA10     :  1;               /*!< Data of Pn.10                                                         */
      __IO uint32_t  DATA11     :  1;               /*!< Data of Pn.11                                                         */
      __IO uint32_t  DATA12     :  1;               /*!< Data of Pn.12                                                         */
      __IO uint32_t  DATA13     :  1;               /*!< Data of Pn.13                                                         */
      __IO uint32_t  DATA14     :  1;               /*!< Data of Pn.14                                                         */
      __IO uint32_t  DATA15     :  1;               /*!< Data of Pn.15                                                         */
    } DATA_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MODE;                            /*!< Offset:0x04 GPIO Port n Mode Register                                 */
    
    struct {
      __IO uint32_t  MODE0      :  1;               /*!< Mode of Pn.0                                                          */
      __IO uint32_t  MODE1      :  1;               /*!< Mode of Pn.1                                                          */
      __IO uint32_t  MODE2      :  1;               /*!< Mode of Pn.2                                                          */
      __IO uint32_t  MODE3      :  1;               /*!< Mode of Pn.3                                                          */
      __IO uint32_t  MODE4      :  1;               /*!< Mode of Pn.4                                                          */
      __IO uint32_t  MODE5      :  1;               /*!< Mode of Pn.5                                                          */
      __IO uint32_t  MODE6      :  1;               /*!< Mode of Pn.6                                                          */
      __IO uint32_t  MODE7      :  1;               /*!< Mode of Pn.7                                                          */
      __IO uint32_t  MODE8      :  1;               /*!< Mode of Pn.8                                                          */
      __IO uint32_t  MODE9      :  1;               /*!< Mode of Pn.9                                                          */
      __IO uint32_t  MODE10     :  1;               /*!< Mode of Pn.10                                                         */
      __IO uint32_t  MODE11     :  1;               /*!< Mode of Pn.11                                                         */
      __IO uint32_t  MODE12     :  1;               /*!< Mode of Pn.12                                                         */
      __IO uint32_t  MODE13     :  1;               /*!< Mode of Pn.13                                                         */
      __IO uint32_t  MODE14     :  1;               /*!< Mode of Pn.14                                                         */
      __IO uint32_t  MODE15     :  1;               /*!< Mode of Pn.15                                                         */
    } MODE_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CFG;                             /*!< Offset:0x08 GPIO Port n Configuration Register                        */
    
    struct {
      __IO uint32_t  CFG0       :  2;               /*!< Configuration of Pn.0                                                 */
      __IO uint32_t  CFG1       :  2;               /*!< Configuration of Pn.1                                                 */
      __IO uint32_t  CFG2       :  2;               /*!< Configuration of Pn.2                                                 */
      __IO uint32_t  CFG3       :  2;               /*!< Configuration of Pn.3                                                 */
      __IO uint32_t  CFG4       :  2;               /*!< Configuration of Pn.4                                                 */
      __IO uint32_t  CFG5       :  2;               /*!< Configuration of Pn.5                                                 */
      __IO uint32_t  CFG6       :  2;               /*!< Configuration of Pn.6                                                 */
      __IO uint32_t  CFG7       :  2;               /*!< Configuration of Pn.7                                                 */
      __IO uint32_t  CFG8       :  2;               /*!< Configuration of Pn.8                                                 */
      __IO uint32_t  CFG9       :  2;               /*!< Configuration of Pn.9                                                 */
      __IO uint32_t  CFG10      :  2;               /*!< Configuration of Pn.10                                                */
      __IO uint32_t  CFG11      :  2;               /*!< Configuration of Pn.11                                                */
      __IO uint32_t  CFG12      :  2;               /*!< Configuration of Pn.12                                                */
      __IO uint32_t  CFG13      :  2;               /*!< Configuration of Pn.13                                                */
      __IO uint32_t  CFG14      :  2;               /*!< Configuration of Pn.14                                                */
      __IO uint32_t  CFG15      :  2;               /*!< Configuration of Pn.15                                                */
    } CFG_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IS;                              /*!< Offset:0x0C GPIO Port n Interrupt Sense Register                      */
    
    struct {
      __IO uint32_t  IS0        :  1;               /*!< Interrupt on Pn.0 is event or edge sensitive                          */
      __IO uint32_t  IS1        :  1;               /*!< Interrupt on Pn.1 is event or edge sensitive                          */
      __IO uint32_t  IS2        :  1;               /*!< Interrupt on Pn.2 is event or edge sensitive                          */
      __IO uint32_t  IS3        :  1;               /*!< Interrupt on Pn.3 is event or edge sensitive                          */
      __IO uint32_t  IS4        :  1;               /*!< Interrupt on Pn.4 is event or edge sensitive                          */
      __IO uint32_t  IS5        :  1;               /*!< Interrupt on Pn.5 is event or edge sensitive                          */
      __IO uint32_t  IS6        :  1;               /*!< Interrupt on Pn.6 is event or edge sensitive                          */
      __IO uint32_t  IS7        :  1;               /*!< Interrupt on Pn.7 is event or edge sensitive                          */
      __IO uint32_t  IS8        :  1;               /*!< Interrupt on Pn.8 is event or edge sensitive                          */
      __IO uint32_t  IS9        :  1;               /*!< Interrupt on Pn.9 is event or edge sensitive                          */
      __IO uint32_t  IS10       :  1;               /*!< Interrupt on Pn.10 is event or edge sensitive                         */
      __IO uint32_t  IS11       :  1;               /*!< Interrupt on Pn.11 is event or edge sensitive                         */
      __IO uint32_t  IS12       :  1;               /*!< Interrupt on Pn.12 is event or edge sensitive                         */
      __IO uint32_t  IS13       :  1;               /*!< Interrupt on Pn.13 is event or edge sensitive                         */
      __IO uint32_t  IS14       :  1;               /*!< Interrupt on Pn.14 is event or edge sensitive                         */
      __IO uint32_t  IS15       :  1;               /*!< Interrupt on Pn.15 is event or edge sensitive                         */
    } IS_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IBS;                             /*!< Offset:0x10 GPIO Port n Interrupt Both-edge Sense Register            */
    
    struct {
      __IO uint32_t  IBS0       :  1;               /*!< Interrupt on Pn.0 is triggered ob both edges                          */
      __IO uint32_t  IBS1       :  1;               /*!< Interrupt on Pn.1 is triggered ob both edges                          */
      __IO uint32_t  IBS2       :  1;               /*!< Interrupt on Pn.2 is triggered ob both edges                          */
      __IO uint32_t  IBS3       :  1;               /*!< Interrupt on Pn.3 is triggered ob both edges                          */
      __IO uint32_t  IBS4       :  1;               /*!< Interrupt on Pn.4 is triggered ob both edges                          */
      __IO uint32_t  IBS5       :  1;               /*!< Interrupt on Pn.5 is triggered ob both edges                          */
      __IO uint32_t  IBS6       :  1;               /*!< Interrupt on Pn.6 is triggered ob both edges                          */
      __IO uint32_t  IBS7       :  1;               /*!< Interrupt on Pn.7 is triggered ob both edges                          */
      __IO uint32_t  IBS8       :  1;               /*!< Interrupt on Pn.8 is triggered ob both edges                          */
      __IO uint32_t  IBS9       :  1;               /*!< Interrupt on Pn.9 is triggered ob both edges                          */
      __IO uint32_t  IBS10      :  1;               /*!< Interrupt on Pn.10 is triggered ob both edges                         */
      __IO uint32_t  IBS11      :  1;               /*!< Interrupt on Pn.11 is triggered ob both edges                         */
      __IO uint32_t  IBS12      :  1;               /*!< Interrupt on Pn.12 is triggered ob both edges                         */
      __IO uint32_t  IBS13      :  1;               /*!< Interrupt on Pn.13 is triggered ob both edges                         */
      __IO uint32_t  IBS14      :  1;               /*!< Interrupt on Pn.14 is triggered ob both edges                         */
      __IO uint32_t  IBS15      :  1;               /*!< Interrupt on Pn.15 is triggered ob both edges                         */
    } IBS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IEV;                             /*!< Offset:0x14 GPIO Port n Interrupt Event Register                      */
    
    struct {
      __IO uint32_t  IEV0       :  1;               /*!< Interrupt trigged evnet on Pn.0                                       */
      __IO uint32_t  IEV1       :  1;               /*!< Interrupt trigged evnet on Pn.1                                       */
      __IO uint32_t  IEV2       :  1;               /*!< Interrupt trigged evnet on Pn.2                                       */
      __IO uint32_t  IEV3       :  1;               /*!< Interrupt trigged evnet on Pn.3                                       */
      __IO uint32_t  IEV4       :  1;               /*!< Interrupt trigged evnet on Pn.4                                       */
      __IO uint32_t  IEV5       :  1;               /*!< Interrupt trigged evnet on Pn.5                                       */
      __IO uint32_t  IEV6       :  1;               /*!< Interrupt trigged evnet on Pn.6                                       */
      __IO uint32_t  IEV7       :  1;               /*!< Interrupt trigged evnet on Pn.7                                       */
      __IO uint32_t  IEV8       :  1;               /*!< Interrupt trigged evnet on Pn.8                                       */
      __IO uint32_t  IEV9       :  1;               /*!< Interrupt trigged evnet on Pn.9                                       */
      __IO uint32_t  IEV10      :  1;               /*!< Interrupt trigged evnet on Pn.10                                      */
      __IO uint32_t  IEV11      :  1;               /*!< Interrupt trigged evnet on Pn.11                                      */
      __IO uint32_t  IEV12      :  1;               /*!< Interrupt trigged evnet on Pn.12                                      */
      __IO uint32_t  IEV13      :  1;               /*!< Interrupt trigged evnet on Pn.13                                      */
      __IO uint32_t  IEV14      :  1;               /*!< Interrupt trigged evnet on Pn.14                                      */
      __IO uint32_t  IEV15      :  1;               /*!< Interrupt trigged evnet on Pn.15                                      */
    } IEV_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IE;                              /*!< Offset:0x18 GPIO Port n Interrupt Enable Register                     */
    
    struct {
      __IO uint32_t  IE0        :  1;               /*!< Interrupt on Pn.0 enable                                              */
      __IO uint32_t  IE1        :  1;               /*!< Interrupt on Pn.1 enable                                              */
      __IO uint32_t  IE2        :  1;               /*!< Interrupt on Pn.2 enable                                              */
      __IO uint32_t  IE3        :  1;               /*!< Interrupt on Pn.3 enable                                              */
      __IO uint32_t  IE4        :  1;               /*!< Interrupt on Pn.4 enable                                              */
      __IO uint32_t  IE5        :  1;               /*!< Interrupt on Pn.5 enable                                              */
      __IO uint32_t  IE6        :  1;               /*!< Interrupt on Pn.6 enable                                              */
      __IO uint32_t  IE7        :  1;               /*!< Interrupt on Pn.7 enable                                              */
      __IO uint32_t  IE8        :  1;               /*!< Interrupt on Pn.8 enable                                              */
      __IO uint32_t  IE9        :  1;               /*!< Interrupt on Pn.9 enable                                              */
      __IO uint32_t  IE10       :  1;               /*!< Interrupt on Pn.10 enable                                             */
      __IO uint32_t  IE11       :  1;               /*!< Interrupt on Pn.11 enable                                             */
      __IO uint32_t  IE12       :  1;               /*!< Interrupt on Pn.12 enable                                             */
      __IO uint32_t  IE13       :  1;               /*!< Interrupt on Pn.13 enable                                             */
      __IO uint32_t  IE14       :  1;               /*!< Interrupt on Pn.14 enable                                             */
      __IO uint32_t  IE15       :  1;               /*!< Interrupt on Pn.15 enable                                             */
    } IE_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RIS;                             /*!< Offset:0x1C GPIO Port n Raw Interrupt Status Register                 */
    
    struct {
      __I  uint32_t  IF0        :  1;               /*!< Pn.0 raw interrupt flag                                               */
      __I  uint32_t  IF1        :  1;               /*!< Pn.1 raw interrupt flag                                               */
      __I  uint32_t  IF2        :  1;               /*!< Pn.2 raw interrupt flag                                               */
      __I  uint32_t  IF3        :  1;               /*!< Pn.3 raw interrupt flag                                               */
      __I  uint32_t  IF4        :  1;               /*!< Pn.4 raw interrupt flag                                               */
      __I  uint32_t  IF5        :  1;               /*!< Pn.5 raw interrupt flag                                               */
      __I  uint32_t  IF6        :  1;               /*!< Pn.6 raw interrupt flag                                               */
      __I  uint32_t  IF7        :  1;               /*!< Pn.7 raw interrupt flag                                               */
      __I  uint32_t  IF8        :  1;               /*!< Pn.8 raw interrupt flag                                               */
      __I  uint32_t  IF9        :  1;               /*!< Pn.9 raw interrupt flag                                               */
      __I  uint32_t  IF10       :  1;               /*!< Pn.10 raw interrupt flag                                              */
      __I  uint32_t  IF11       :  1;               /*!< Pn.11 raw interrupt flag                                              */
      __I  uint32_t  IF12       :  1;               /*!< Pn.12 raw interrupt flag                                              */
      __I  uint32_t  IF13       :  1;               /*!< Pn.13 raw interrupt flag                                              */
      __I  uint32_t  IF14       :  1;               /*!< Pn.14 raw interrupt flag                                              */
      __I  uint32_t  IF15       :  1;               /*!< Pn.15 raw interrupt flag                                              */
    } RIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  IC;                              /*!< Offset:0x20 GPIO Port n Interrupt Clear Register                      */
    
    struct {
      __O  uint32_t  IC0        :  1;               /*!< Pn.0 interrupt flag clear                                             */
      __O  uint32_t  IC1        :  1;               /*!< Pn.1 interrupt flag clear                                             */
      __O  uint32_t  IC2        :  1;               /*!< Pn.2 interrupt flag clear                                             */
      __O  uint32_t  IC3        :  1;               /*!< Pn.3 interrupt flag clear                                             */
      __O  uint32_t  IC4        :  1;               /*!< Pn.4 interrupt flag clear                                             */
      __O  uint32_t  IC5        :  1;               /*!< Pn.5 interrupt flag clear                                             */
      __O  uint32_t  IC6        :  1;               /*!< Pn.6 interrupt flag clear                                             */
      __O  uint32_t  IC7        :  1;               /*!< Pn.7 interrupt flag clear                                             */
      __O  uint32_t  IC8        :  1;               /*!< Pn.8 interrupt flag clear                                             */
      __O  uint32_t  IC9        :  1;               /*!< Pn.9 interrupt flag clear                                             */
      __O  uint32_t  IC10       :  1;               /*!< Pn.10 interrupt flag clear                                            */
      __O  uint32_t  IC11       :  1;               /*!< Pn.11 interrupt flag clear                                            */
      __O  uint32_t  IC12       :  1;               /*!< Pn.12 interrupt flag clear                                            */
      __O  uint32_t  IC13       :  1;               /*!< Pn.13 interrupt flag clear                                            */
      __O  uint32_t  IC14       :  1;               /*!< Pn.14 interrupt flag clear                                            */
      __O  uint32_t  IC15       :  1;               /*!< Pn.15 interrupt flag clear                                            */
    } IC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  BSET;                            /*!< Offset:0x24 GPIO Port n Bits Set Operation Register                   */
    
    struct {
      __O  uint32_t  BSET0      :  1;               /*!< Set Pn.0                                                              */
      __O  uint32_t  BSET1      :  1;               /*!< Set Pn.1                                                              */
      __O  uint32_t  BSET2      :  1;               /*!< Set Pn.2                                                              */
      __O  uint32_t  BSET3      :  1;               /*!< Set Pn.3                                                              */
      __O  uint32_t  BSET4      :  1;               /*!< Set Pn.4                                                              */
      __O  uint32_t  BSET5      :  1;               /*!< Set Pn.5                                                              */
      __O  uint32_t  BSET6      :  1;               /*!< Set Pn.6                                                              */
      __O  uint32_t  BSET7      :  1;               /*!< Set Pn.7                                                              */
      __O  uint32_t  BSET8      :  1;               /*!< Set Pn.8                                                              */
      __O  uint32_t  BSET9      :  1;               /*!< Set Pn.9                                                              */
      __O  uint32_t  BSET10     :  1;               /*!< Set Pn.10                                                             */
      __O  uint32_t  BSET11     :  1;               /*!< Set Pn.11                                                             */
      __O  uint32_t  BSET12     :  1;               /*!< Set Pn.12                                                             */
      __O  uint32_t  BSET13     :  1;               /*!< Set Pn.13                                                             */
      __O  uint32_t  BSET14     :  1;               /*!< Set Pn.14                                                             */
      __O  uint32_t  BSET15     :  1;               /*!< Set Pn.15                                                             */
    } BSET_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  BCLR;                            /*!< Offset:0x28 GPIO Port n Bits Clear Operation Register                 */
    
    struct {
      __O  uint32_t  BCLR0      :  1;               /*!< Clear Pn.0                                                            */
      __O  uint32_t  BCLR1      :  1;               /*!< Clear Pn.1                                                            */
      __O  uint32_t  BCLR2      :  1;               /*!< Clear Pn.2                                                            */
      __O  uint32_t  BCLR3      :  1;               /*!< Clear Pn.3                                                            */
      __O  uint32_t  BCLR4      :  1;               /*!< Clear Pn.4                                                            */
      __O  uint32_t  BCLR5      :  1;               /*!< Clear Pn.5                                                            */
      __O  uint32_t  BCLR6      :  1;               /*!< Clear Pn.6                                                            */
      __O  uint32_t  BCLR7      :  1;               /*!< Clear Pn.7                                                            */
      __O  uint32_t  BCLR8      :  1;               /*!< Clear Pn.8                                                            */
      __O  uint32_t  BCLR9      :  1;               /*!< Clear Pn.9                                                            */
      __O  uint32_t  BCLR10     :  1;               /*!< Clear Pn.10                                                           */
      __O  uint32_t  BCLR11     :  1;               /*!< Clear Pn.11                                                           */
      __O  uint32_t  BCLR12     :  1;               /*!< Clear Pn.12                                                           */
      __O  uint32_t  BCLR13     :  1;               /*!< Clear Pn.13                                                           */
      __O  uint32_t  BCLR14     :  1;               /*!< Clear Pn.14                                                           */
      __O  uint32_t  BCLR15     :  1;               /*!< Clear Pn.15                                                           */
    } BCLR_b;                                       /*!< BitSize                                                               */
  };
} SN_GPIO0_Type;


/* ================================================================================ */
/* ================                    SN_GPIO1                    ================ */
/* ================================================================================ */


/**
  * @brief General Purpose I/O (SN_GPIO1)
  */

typedef struct {                                    /*!< SN_GPIO1 Structure                                                    */
  
  union {
    __IO uint32_t  DATA;                            /*!< Offset:0x00 GPIO Port n Data Register                                 */
    
    struct {
      __IO uint32_t  DATA0      :  1;               /*!< Data of Pn.0                                                          */
      __IO uint32_t  DATA1      :  1;               /*!< Data of Pn.1                                                          */
      __IO uint32_t  DATA2      :  1;               /*!< Data of Pn.2                                                          */
      __IO uint32_t  DATA3      :  1;               /*!< Data of Pn.3                                                          */
      __IO uint32_t  DATA4      :  1;               /*!< Data of Pn.4                                                          */
      __IO uint32_t  DATA5      :  1;               /*!< Data of Pn.5                                                          */
    } DATA_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MODE;                            /*!< Offset:0x04 GPIO Port n Mode Register                                 */
    
    struct {
      __IO uint32_t  MODE0      :  1;               /*!< Mode of Pn.0                                                          */
      __IO uint32_t  MODE1      :  1;               /*!< Mode of Pn.1                                                          */
      __IO uint32_t  MODE2      :  1;               /*!< Mode of Pn.2                                                          */
      __IO uint32_t  MODE3      :  1;               /*!< Mode of Pn.3                                                          */
      __IO uint32_t  MODE4      :  1;               /*!< Mode of Pn.4                                                          */
      __IO uint32_t  MODE5      :  1;               /*!< Mode of Pn.5                                                          */
    } MODE_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CFG;                             /*!< Offset:0x08 GPIO Port n Configuration Register                        */
    
    struct {
      __IO uint32_t  CFG0       :  2;               /*!< Configuration of Pn.0                                                 */
      __IO uint32_t  CFG1       :  2;               /*!< Configuration of Pn.1                                                 */
      __IO uint32_t  CFG2       :  2;               /*!< Configuration of Pn.2                                                 */
      __IO uint32_t  CFG3       :  2;               /*!< Configuration of Pn.3                                                 */
      __IO uint32_t  CFG4       :  2;               /*!< Configuration of Pn.4                                                 */
      __IO uint32_t  CFG5       :  2;               /*!< Configuration of Pn.5                                                 */
    } CFG_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IS;                              /*!< Offset:0x0C GPIO Port n Interrupt Sense Register                      */
    
    struct {
      __IO uint32_t  IS0        :  1;               /*!< Interrupt on Pn.0 is event or edge sensitive                          */
      __IO uint32_t  IS1        :  1;               /*!< Interrupt on Pn.1 is event or edge sensitive                          */
      __IO uint32_t  IS2        :  1;               /*!< Interrupt on Pn.2 is event or edge sensitive                          */
      __IO uint32_t  IS3        :  1;               /*!< Interrupt on Pn.3 is event or edge sensitive                          */
      __IO uint32_t  IS4        :  1;               /*!< Interrupt on Pn.4 is event or edge sensitive                          */
      __IO uint32_t  IS5        :  1;               /*!< Interrupt on Pn.5 is event or edge sensitive                          */
    } IS_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IBS;                             /*!< Offset:0x10 GPIO Port n Interrupt Both-edge Sense Register            */
    
    struct {
      __IO uint32_t  IBS0       :  1;               /*!< Interrupt on Pn.0 is triggered ob both edges                          */
      __IO uint32_t  IBS1       :  1;               /*!< Interrupt on Pn.1 is triggered ob both edges                          */
      __IO uint32_t  IBS2       :  1;               /*!< Interrupt on Pn.2 is triggered ob both edges                          */
      __IO uint32_t  IBS3       :  1;               /*!< Interrupt on Pn.3 is triggered ob both edges                          */
      __IO uint32_t  IBS4       :  1;               /*!< Interrupt on Pn.4 is triggered ob both edges                          */
      __IO uint32_t  IBS5       :  1;               /*!< Interrupt on Pn.5 is triggered ob both edges                          */
    } IBS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IEV;                             /*!< Offset:0x14 GPIO Port n Interrupt Event Register                      */
    
    struct {
      __IO uint32_t  IEV0       :  1;               /*!< Interrupt trigged evnet on Pn.0                                       */
      __IO uint32_t  IEV1       :  1;               /*!< Interrupt trigged evnet on Pn.1                                       */
      __IO uint32_t  IEV2       :  1;               /*!< Interrupt trigged evnet on Pn.2                                       */
      __IO uint32_t  IEV3       :  1;               /*!< Interrupt trigged evnet on Pn.3                                       */
      __IO uint32_t  IEV4       :  1;               /*!< Interrupt trigged evnet on Pn.4                                       */
      __IO uint32_t  IEV5       :  1;               /*!< Interrupt trigged evnet on Pn.5                                       */
    } IEV_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IE;                              /*!< Offset:0x18 GPIO Port n Interrupt Enable Register                     */
    
    struct {
      __IO uint32_t  IE0        :  1;               /*!< Interrupt on Pn.0 enable                                              */
      __IO uint32_t  IE1        :  1;               /*!< Interrupt on Pn.1 enable                                              */
      __IO uint32_t  IE2        :  1;               /*!< Interrupt on Pn.2 enable                                              */
      __IO uint32_t  IE3        :  1;               /*!< Interrupt on Pn.3 enable                                              */
      __IO uint32_t  IE4        :  1;               /*!< Interrupt on Pn.4 enable                                              */
      __IO uint32_t  IE5        :  1;               /*!< Interrupt on Pn.5 enable                                              */
    } IE_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RIS;                             /*!< Offset:0x1C GPIO Port n Raw Interrupt Status Register                 */
    
    struct {
      __I  uint32_t  IF0        :  1;               /*!< Pn.0 raw interrupt flag                                               */
      __I  uint32_t  IF1        :  1;               /*!< Pn.1 raw interrupt flag                                               */
      __I  uint32_t  IF2        :  1;               /*!< Pn.2 raw interrupt flag                                               */
      __I  uint32_t  IF3        :  1;               /*!< Pn.3 raw interrupt flag                                               */
      __I  uint32_t  IF4        :  1;               /*!< Pn.4 raw interrupt flag                                               */
      __I  uint32_t  IF5        :  1;               /*!< Pn.5 raw interrupt flag                                               */
    } RIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  IC;                              /*!< Offset:0x20 GPIO Port n Interrupt Clear Register                      */
    
    struct {
      __O  uint32_t  IC0        :  1;               /*!< Pn.0 interrupt flag clear                                             */
      __O  uint32_t  IC1        :  1;               /*!< Pn.1 interrupt flag clear                                             */
      __O  uint32_t  IC2        :  1;               /*!< Pn.2 interrupt flag clear                                             */
      __O  uint32_t  IC3        :  1;               /*!< Pn.3 interrupt flag clear                                             */
      __O  uint32_t  IC4        :  1;               /*!< Pn.4 interrupt flag clear                                             */
      __O  uint32_t  IC5        :  1;               /*!< Pn.5 interrupt flag clear                                             */
    } IC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  BSET;                            /*!< Offset:0x24 GPIO Port n Bits Set Operation Register                   */
    
    struct {
      __O  uint32_t  BSET0      :  1;               /*!< Set Pn.0                                                              */
      __O  uint32_t  BSET1      :  1;               /*!< Set Pn.1                                                              */
      __O  uint32_t  BSET2      :  1;               /*!< Set Pn.2                                                              */
      __O  uint32_t  BSET3      :  1;               /*!< Set Pn.3                                                              */
      __O  uint32_t  BSET4      :  1;               /*!< Set Pn.4                                                              */
      __O  uint32_t  BSET5      :  1;               /*!< Set Pn.5                                                              */
    } BSET_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  BCLR;                            /*!< Offset:0x28 GPIO Port n Bits Clear Operation Register                 */
    
    struct {
      __O  uint32_t  BCLR0      :  1;               /*!< Clear Pn.0                                                            */
      __O  uint32_t  BCLR1      :  1;               /*!< Clear Pn.1                                                            */
      __O  uint32_t  BCLR2      :  1;               /*!< Clear Pn.2                                                            */
      __O  uint32_t  BCLR3      :  1;               /*!< Clear Pn.3                                                            */
      __O  uint32_t  BCLR4      :  1;               /*!< Clear Pn.4                                                            */
      __O  uint32_t  BCLR5      :  1;               /*!< Clear Pn.5                                                            */
    } BCLR_b;                                       /*!< BitSize                                                               */
  };
} SN_GPIO1_Type;


/* ================================================================================ */
/* ================                    SN_GPIO2                    ================ */
/* ================================================================================ */


/**
  * @brief General Purpose I/O (SN_GPIO2)
  */

typedef struct {                                    /*!< SN_GPIO2 Structure                                                    */
  
  union {
    __IO uint32_t  DATA;                            /*!< Offset:0x00 GPIO Port n Data Register                                 */
    
    struct {
      __IO uint32_t  DATA0      :  1;               /*!< Data of Pn.0                                                          */
      __IO uint32_t  DATA1      :  1;               /*!< Data of Pn.1                                                          */
      __IO uint32_t  DATA2      :  1;               /*!< Data of Pn.2                                                          */
      __IO uint32_t  DATA3      :  1;               /*!< Data of Pn.3                                                          */
      __IO uint32_t  DATA4      :  1;               /*!< Data of Pn.4                                                          */
      __IO uint32_t  DATA5      :  1;               /*!< Data of Pn.5                                                          */
      __IO uint32_t  DATA6      :  1;               /*!< Data of Pn.6                                                          */
      __IO uint32_t  DATA7      :  1;               /*!< Data of Pn.7                                                          */
      __IO uint32_t  DATA8      :  1;               /*!< Data of Pn.8                                                          */
      __IO uint32_t  DATA9      :  1;               /*!< Data of Pn.9                                                          */
      __IO uint32_t  DATA10     :  1;               /*!< Data of Pn.10                                                         */
    } DATA_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MODE;                            /*!< Offset:0x04 GPIO Port n Mode Register                                 */
    
    struct {
      __IO uint32_t  MODE0      :  1;               /*!< Mode of Pn.0                                                          */
      __IO uint32_t  MODE1      :  1;               /*!< Mode of Pn.1                                                          */
      __IO uint32_t  MODE2      :  1;               /*!< Mode of Pn.2                                                          */
      __IO uint32_t  MODE3      :  1;               /*!< Mode of Pn.3                                                          */
      __IO uint32_t  MODE4      :  1;               /*!< Mode of Pn.4                                                          */
      __IO uint32_t  MODE5      :  1;               /*!< Mode of Pn.5                                                          */
      __IO uint32_t  MODE6      :  1;               /*!< Mode of Pn.6                                                          */
      __IO uint32_t  MODE7      :  1;               /*!< Mode of Pn.7                                                          */
      __IO uint32_t  MODE8      :  1;               /*!< Mode of Pn.8                                                          */
      __IO uint32_t  MODE9      :  1;               /*!< Mode of Pn.9                                                          */
      __IO uint32_t  MODE10     :  1;               /*!< Mode of Pn.10                                                         */
    } MODE_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CFG;                             /*!< Offset:0x08 GPIO Port n Configuration Register                        */
    
    struct {
      __IO uint32_t  CFG0       :  2;               /*!< Configuration of Pn.0                                                 */
      __IO uint32_t  CFG1       :  2;               /*!< Configuration of Pn.1                                                 */
      __IO uint32_t  CFG2       :  2;               /*!< Configuration of Pn.2                                                 */
      __IO uint32_t  CFG3       :  2;               /*!< Configuration of Pn.3                                                 */
      __IO uint32_t  CFG4       :  2;               /*!< Configuration of Pn.4                                                 */
      __IO uint32_t  CFG5       :  2;               /*!< Configuration of Pn.5                                                 */
      __IO uint32_t  CFG6       :  2;               /*!< Configuration of Pn.6                                                 */
      __IO uint32_t  CFG7       :  2;               /*!< Configuration of Pn.7                                                 */
      __IO uint32_t  CFG8       :  2;               /*!< Configuration of Pn.8                                                 */
      __IO uint32_t  CFG9       :  2;               /*!< Configuration of Pn.9                                                 */
      __IO uint32_t  CFG10      :  2;               /*!< Configuration of Pn.10                                                */
    } CFG_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IS;                              /*!< Offset:0x0C GPIO Port n Interrupt Sense Register                      */
    
    struct {
      __IO uint32_t  IS0        :  1;               /*!< Interrupt on Pn.0 is event or edge sensitive                          */
      __IO uint32_t  IS1        :  1;               /*!< Interrupt on Pn.1 is event or edge sensitive                          */
      __IO uint32_t  IS2        :  1;               /*!< Interrupt on Pn.2 is event or edge sensitive                          */
      __IO uint32_t  IS3        :  1;               /*!< Interrupt on Pn.3 is event or edge sensitive                          */
      __IO uint32_t  IS4        :  1;               /*!< Interrupt on Pn.4 is event or edge sensitive                          */
      __IO uint32_t  IS5        :  1;               /*!< Interrupt on Pn.5 is event or edge sensitive                          */
      __IO uint32_t  IS6        :  1;               /*!< Interrupt on Pn.6 is event or edge sensitive                          */
      __IO uint32_t  IS7        :  1;               /*!< Interrupt on Pn.7 is event or edge sensitive                          */
      __IO uint32_t  IS8        :  1;               /*!< Interrupt on Pn.8 is event or edge sensitive                          */
      __IO uint32_t  IS9        :  1;               /*!< Interrupt on Pn.9 is event or edge sensitive                          */
      __IO uint32_t  IS10       :  1;               /*!< Interrupt on Pn.10 is event or edge sensitive                         */
    } IS_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IBS;                             /*!< Offset:0x10 GPIO Port n Interrupt Both-edge Sense Register            */
    
    struct {
      __IO uint32_t  IBS0       :  1;               /*!< Interrupt on Pn.0 is triggered ob both edges                          */
      __IO uint32_t  IBS1       :  1;               /*!< Interrupt on Pn.1 is triggered ob both edges                          */
      __IO uint32_t  IBS2       :  1;               /*!< Interrupt on Pn.2 is triggered ob both edges                          */
      __IO uint32_t  IBS3       :  1;               /*!< Interrupt on Pn.3 is triggered ob both edges                          */
      __IO uint32_t  IBS4       :  1;               /*!< Interrupt on Pn.4 is triggered ob both edges                          */
      __IO uint32_t  IBS5       :  1;               /*!< Interrupt on Pn.5 is triggered ob both edges                          */
      __IO uint32_t  IBS6       :  1;               /*!< Interrupt on Pn.6 is triggered ob both edges                          */
      __IO uint32_t  IBS7       :  1;               /*!< Interrupt on Pn.7 is triggered ob both edges                          */
      __IO uint32_t  IBS8       :  1;               /*!< Interrupt on Pn.8 is triggered ob both edges                          */
      __IO uint32_t  IBS9       :  1;               /*!< Interrupt on Pn.9 is triggered ob both edges                          */
      __IO uint32_t  IBS10      :  1;               /*!< Interrupt on Pn.10 is triggered ob both edges                         */
    } IBS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IEV;                             /*!< Offset:0x14 GPIO Port n Interrupt Event Register                      */
    
    struct {
      __IO uint32_t  IEV0       :  1;               /*!< Interrupt trigged evnet on Pn.0                                       */
      __IO uint32_t  IEV1       :  1;               /*!< Interrupt trigged evnet on Pn.1                                       */
      __IO uint32_t  IEV2       :  1;               /*!< Interrupt trigged evnet on Pn.2                                       */
      __IO uint32_t  IEV3       :  1;               /*!< Interrupt trigged evnet on Pn.3                                       */
      __IO uint32_t  IEV4       :  1;               /*!< Interrupt trigged evnet on Pn.4                                       */
      __IO uint32_t  IEV5       :  1;               /*!< Interrupt trigged evnet on Pn.5                                       */
      __IO uint32_t  IEV6       :  1;               /*!< Interrupt trigged evnet on Pn.6                                       */
      __IO uint32_t  IEV7       :  1;               /*!< Interrupt trigged evnet on Pn.7                                       */
      __IO uint32_t  IEV8       :  1;               /*!< Interrupt trigged evnet on Pn.8                                       */
      __IO uint32_t  IEV9       :  1;               /*!< Interrupt trigged evnet on Pn.9                                       */
      __IO uint32_t  IEV10      :  1;               /*!< Interrupt trigged evnet on Pn.10                                      */
    } IEV_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IE;                              /*!< Offset:0x18 GPIO Port n Interrupt Enable Register                     */
    
    struct {
      __IO uint32_t  IE0        :  1;               /*!< Interrupt on Pn.0 enable                                              */
      __IO uint32_t  IE1        :  1;               /*!< Interrupt on Pn.1 enable                                              */
      __IO uint32_t  IE2        :  1;               /*!< Interrupt on Pn.2 enable                                              */
      __IO uint32_t  IE3        :  1;               /*!< Interrupt on Pn.3 enable                                              */
      __IO uint32_t  IE4        :  1;               /*!< Interrupt on Pn.4 enable                                              */
      __IO uint32_t  IE5        :  1;               /*!< Interrupt on Pn.5 enable                                              */
      __IO uint32_t  IE6        :  1;               /*!< Interrupt on Pn.6 enable                                              */
      __IO uint32_t  IE7        :  1;               /*!< Interrupt on Pn.7 enable                                              */
      __IO uint32_t  IE8        :  1;               /*!< Interrupt on Pn.8 enable                                              */
      __IO uint32_t  IE9        :  1;               /*!< Interrupt on Pn.9 enable                                              */
      __IO uint32_t  IE10       :  1;               /*!< Interrupt on Pn.10 enable                                             */
    } IE_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RIS;                             /*!< Offset:0x1C GPIO Port n Raw Interrupt Status Register                 */
    
    struct {
      __I  uint32_t  IF0        :  1;               /*!< Pn.0 raw interrupt flag                                               */
      __I  uint32_t  IF1        :  1;               /*!< Pn.1 raw interrupt flag                                               */
      __I  uint32_t  IF2        :  1;               /*!< Pn.2 raw interrupt flag                                               */
      __I  uint32_t  IF3        :  1;               /*!< Pn.3 raw interrupt flag                                               */
      __I  uint32_t  IF4        :  1;               /*!< Pn.4 raw interrupt flag                                               */
      __I  uint32_t  IF5        :  1;               /*!< Pn.5 raw interrupt flag                                               */
      __I  uint32_t  IF6        :  1;               /*!< Pn.6 raw interrupt flag                                               */
      __I  uint32_t  IF7        :  1;               /*!< Pn.7 raw interrupt flag                                               */
      __I  uint32_t  IF8        :  1;               /*!< Pn.8 raw interrupt flag                                               */
      __I  uint32_t  IF9        :  1;               /*!< Pn.9 raw interrupt flag                                               */
      __I  uint32_t  IF10       :  1;               /*!< Pn.10 raw interrupt flag                                              */
    } RIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  IC;                              /*!< Offset:0x20 GPIO Port n Interrupt Clear Register                      */
    
    struct {
      __O  uint32_t  IC0        :  1;               /*!< Pn.0 interrupt flag clear                                             */
      __O  uint32_t  IC1        :  1;               /*!< Pn.1 interrupt flag clear                                             */
      __O  uint32_t  IC2        :  1;               /*!< Pn.2 interrupt flag clear                                             */
      __O  uint32_t  IC3        :  1;               /*!< Pn.3 interrupt flag clear                                             */
      __O  uint32_t  IC4        :  1;               /*!< Pn.4 interrupt flag clear                                             */
      __O  uint32_t  IC5        :  1;               /*!< Pn.5 interrupt flag clear                                             */
      __O  uint32_t  IC6        :  1;               /*!< Pn.6 interrupt flag clear                                             */
      __O  uint32_t  IC7        :  1;               /*!< Pn.7 interrupt flag clear                                             */
      __O  uint32_t  IC8        :  1;               /*!< Pn.8 interrupt flag clear                                             */
      __O  uint32_t  IC9        :  1;               /*!< Pn.9 interrupt flag clear                                             */
      __O  uint32_t  IC10       :  1;               /*!< Pn.10 interrupt flag clear                                            */
    } IC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  BSET;                            /*!< Offset:0x24 GPIO Port n Bits Set Operation Register                   */
    
    struct {
      __O  uint32_t  BSET0      :  1;               /*!< Set Pn.0                                                              */
      __O  uint32_t  BSET1      :  1;               /*!< Set Pn.1                                                              */
      __O  uint32_t  BSET2      :  1;               /*!< Set Pn.2                                                              */
      __O  uint32_t  BSET3      :  1;               /*!< Set Pn.3                                                              */
      __O  uint32_t  BSET4      :  1;               /*!< Set Pn.4                                                              */
      __O  uint32_t  BSET5      :  1;               /*!< Set Pn.5                                                              */
      __O  uint32_t  BSET6      :  1;               /*!< Set Pn.6                                                              */
      __O  uint32_t  BSET7      :  1;               /*!< Set Pn.7                                                              */
      __O  uint32_t  BSET8      :  1;               /*!< Set Pn.8                                                              */
      __O  uint32_t  BSET9      :  1;               /*!< Set Pn.9                                                              */
      __O  uint32_t  BSET10     :  1;               /*!< Set Pn.10                                                             */
    } BSET_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  BCLR;                            /*!< Offset:0x28 GPIO Port n Bits Clear Operation Register                 */
    
    struct {
      __O  uint32_t  BCLR0      :  1;               /*!< Clear Pn.0                                                            */
      __O  uint32_t  BCLR1      :  1;               /*!< Clear Pn.1                                                            */
      __O  uint32_t  BCLR2      :  1;               /*!< Clear Pn.2                                                            */
      __O  uint32_t  BCLR3      :  1;               /*!< Clear Pn.3                                                            */
      __O  uint32_t  BCLR4      :  1;               /*!< Clear Pn.4                                                            */
      __O  uint32_t  BCLR5      :  1;               /*!< Clear Pn.5                                                            */
      __O  uint32_t  BCLR6      :  1;               /*!< Clear Pn.6                                                            */
      __O  uint32_t  BCLR7      :  1;               /*!< Clear Pn.7                                                            */
      __O  uint32_t  BCLR8      :  1;               /*!< Clear Pn.8                                                            */
      __O  uint32_t  BCLR9      :  1;               /*!< Clear Pn.9                                                            */
      __O  uint32_t  BCLR10     :  1;               /*!< Clear Pn.10                                                           */
    } BCLR_b;                                       /*!< BitSize                                                               */
  };
} SN_GPIO2_Type;


/* ================================================================================ */
/* ================                    SN_GPIO3                    ================ */
/* ================================================================================ */


/**
  * @brief General Purpose I/O (SN_GPIO3)
  */

typedef struct {                                    /*!< SN_GPIO3 Structure                                                    */
  
  union {
    __IO uint32_t  DATA;                            /*!< Offset:0x00 GPIO Port n Data Register                                 */
    
    struct {
      __IO uint32_t  DATA0      :  1;               /*!< Data of Pn.0                                                          */
      __IO uint32_t  DATA1      :  1;               /*!< Data of Pn.1                                                          */
      __IO uint32_t  DATA2      :  1;               /*!< Data of Pn.2                                                          */
      __IO uint32_t  DATA3      :  1;               /*!< Data of Pn.3                                                          */
      __IO uint32_t  DATA4      :  1;               /*!< Data of Pn.4                                                          */
      __IO uint32_t  DATA5      :  1;               /*!< Data of Pn.5                                                          */
      __IO uint32_t  DATA6      :  1;               /*!< Data of Pn.6                                                          */
      __IO uint32_t  DATA7      :  1;               /*!< Data of Pn.7                                                          */
      __IO uint32_t  DATA8      :  1;               /*!< Data of Pn.8                                                          */
    } DATA_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MODE;                            /*!< Offset:0x04 GPIO Port n Mode Register                                 */
    
    struct {
      __IO uint32_t  MODE0      :  1;               /*!< Mode of Pn.0                                                          */
      __IO uint32_t  MODE1      :  1;               /*!< Mode of Pn.1                                                          */
      __IO uint32_t  MODE2      :  1;               /*!< Mode of Pn.2                                                          */
      __IO uint32_t  MODE3      :  1;               /*!< Mode of Pn.3                                                          */
      __IO uint32_t  MODE4      :  1;               /*!< Mode of Pn.4                                                          */
      __IO uint32_t  MODE5      :  1;               /*!< Mode of Pn.5                                                          */
      __IO uint32_t  MODE6      :  1;               /*!< Mode of Pn.6                                                          */
      __IO uint32_t  MODE7      :  1;               /*!< Mode of Pn.7                                                          */
      __IO uint32_t  MODE8      :  1;               /*!< Mode of Pn.8                                                          */
    } MODE_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CFG;                             /*!< Offset:0x08 GPIO Port n Configuration Register                        */
    
    struct {
      __IO uint32_t  CFG0       :  2;               /*!< Configuration of Pn.0                                                 */
      __IO uint32_t  CFG1       :  2;               /*!< Configuration of Pn.1                                                 */
      __IO uint32_t  CFG2       :  2;               /*!< Configuration of Pn.2                                                 */
      __IO uint32_t  CFG3       :  2;               /*!< Configuration of Pn.3                                                 */
      __IO uint32_t  CFG4       :  2;               /*!< Configuration of Pn.4                                                 */
      __IO uint32_t  CFG5       :  2;               /*!< Configuration of Pn.5                                                 */
      __IO uint32_t  CFG6       :  2;               /*!< Configuration of Pn.6                                                 */
      __IO uint32_t  CFG7       :  2;               /*!< Configuration of Pn.7                                                 */
      __IO uint32_t  CFG8       :  2;               /*!< Configuration of Pn.8                                                 */
    } CFG_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IS;                              /*!< Offset:0x0C GPIO Port n Interrupt Sense Register                      */
    
    struct {
      __IO uint32_t  IS0        :  1;               /*!< Interrupt on Pn.0 is event or edge sensitive                          */
      __IO uint32_t  IS1        :  1;               /*!< Interrupt on Pn.1 is event or edge sensitive                          */
      __IO uint32_t  IS2        :  1;               /*!< Interrupt on Pn.2 is event or edge sensitive                          */
      __IO uint32_t  IS3        :  1;               /*!< Interrupt on Pn.3 is event or edge sensitive                          */
      __IO uint32_t  IS4        :  1;               /*!< Interrupt on Pn.4 is event or edge sensitive                          */
      __IO uint32_t  IS5        :  1;               /*!< Interrupt on Pn.5 is event or edge sensitive                          */
      __IO uint32_t  IS6        :  1;               /*!< Interrupt on Pn.6 is event or edge sensitive                          */
      __IO uint32_t  IS7        :  1;               /*!< Interrupt on Pn.7 is event or edge sensitive                          */
      __IO uint32_t  IS8        :  1;               /*!< Interrupt on Pn.8 is event or edge sensitive                          */
    } IS_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IBS;                             /*!< Offset:0x10 GPIO Port n Interrupt Both-edge Sense Register            */
    
    struct {
      __IO uint32_t  IBS0       :  1;               /*!< Interrupt on Pn.0 is triggered ob both edges                          */
      __IO uint32_t  IBS1       :  1;               /*!< Interrupt on Pn.1 is triggered ob both edges                          */
      __IO uint32_t  IBS2       :  1;               /*!< Interrupt on Pn.2 is triggered ob both edges                          */
      __IO uint32_t  IBS3       :  1;               /*!< Interrupt on Pn.3 is triggered ob both edges                          */
      __IO uint32_t  IBS4       :  1;               /*!< Interrupt on Pn.4 is triggered ob both edges                          */
      __IO uint32_t  IBS5       :  1;               /*!< Interrupt on Pn.5 is triggered ob both edges                          */
      __IO uint32_t  IBS6       :  1;               /*!< Interrupt on Pn.6 is triggered ob both edges                          */
      __IO uint32_t  IBS7       :  1;               /*!< Interrupt on Pn.7 is triggered ob both edges                          */
      __IO uint32_t  IBS8       :  1;               /*!< Interrupt on Pn.8 is triggered ob both edges                          */
    } IBS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IEV;                             /*!< Offset:0x14 GPIO Port n Interrupt Event Register                      */
    
    struct {
      __IO uint32_t  IEV0       :  1;               /*!< Interrupt trigged evnet on Pn.0                                       */
      __IO uint32_t  IEV1       :  1;               /*!< Interrupt trigged evnet on Pn.1                                       */
      __IO uint32_t  IEV2       :  1;               /*!< Interrupt trigged evnet on Pn.2                                       */
      __IO uint32_t  IEV3       :  1;               /*!< Interrupt trigged evnet on Pn.3                                       */
      __IO uint32_t  IEV4       :  1;               /*!< Interrupt trigged evnet on Pn.4                                       */
      __IO uint32_t  IEV5       :  1;               /*!< Interrupt trigged evnet on Pn.5                                       */
      __IO uint32_t  IEV6       :  1;               /*!< Interrupt trigged evnet on Pn.6                                       */
      __IO uint32_t  IEV7       :  1;               /*!< Interrupt trigged evnet on Pn.7                                       */
      __IO uint32_t  IEV8       :  1;               /*!< Interrupt trigged evnet on Pn.8                                       */
    } IEV_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IE;                              /*!< Offset:0x18 GPIO Port n Interrupt Enable Register                     */
    
    struct {
      __IO uint32_t  IE0        :  1;               /*!< Interrupt on Pn.0 enable                                              */
      __IO uint32_t  IE1        :  1;               /*!< Interrupt on Pn.1 enable                                              */
      __IO uint32_t  IE2        :  1;               /*!< Interrupt on Pn.2 enable                                              */
      __IO uint32_t  IE3        :  1;               /*!< Interrupt on Pn.3 enable                                              */
      __IO uint32_t  IE4        :  1;               /*!< Interrupt on Pn.4 enable                                              */
      __IO uint32_t  IE5        :  1;               /*!< Interrupt on Pn.5 enable                                              */
      __IO uint32_t  IE6        :  1;               /*!< Interrupt on Pn.6 enable                                              */
      __IO uint32_t  IE7        :  1;               /*!< Interrupt on Pn.7 enable                                              */
      __IO uint32_t  IE8        :  1;               /*!< Interrupt on Pn.8 enable                                              */
    } IE_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RIS;                             /*!< Offset:0x1C GPIO Port n Raw Interrupt Status Register                 */
    
    struct {
      __I  uint32_t  IF0        :  1;               /*!< Pn.0 raw interrupt flag                                               */
      __I  uint32_t  IF1        :  1;               /*!< Pn.1 raw interrupt flag                                               */
      __I  uint32_t  IF2        :  1;               /*!< Pn.2 raw interrupt flag                                               */
      __I  uint32_t  IF3        :  1;               /*!< Pn.3 raw interrupt flag                                               */
      __I  uint32_t  IF4        :  1;               /*!< Pn.4 raw interrupt flag                                               */
      __I  uint32_t  IF5        :  1;               /*!< Pn.5 raw interrupt flag                                               */
      __I  uint32_t  IF6        :  1;               /*!< Pn.6 raw interrupt flag                                               */
      __I  uint32_t  IF7        :  1;               /*!< Pn.7 raw interrupt flag                                               */
      __I  uint32_t  IF8        :  1;               /*!< Pn.8 raw interrupt flag                                               */
    } RIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  IC;                              /*!< Offset:0x20 GPIO Port n Interrupt Clear Register                      */
    
    struct {
      __O  uint32_t  IC0        :  1;               /*!< Pn.0 interrupt flag clear                                             */
      __O  uint32_t  IC1        :  1;               /*!< Pn.1 interrupt flag clear                                             */
      __O  uint32_t  IC2        :  1;               /*!< Pn.2 interrupt flag clear                                             */
      __O  uint32_t  IC3        :  1;               /*!< Pn.3 interrupt flag clear                                             */
      __O  uint32_t  IC4        :  1;               /*!< Pn.4 interrupt flag clear                                             */
      __O  uint32_t  IC5        :  1;               /*!< Pn.5 interrupt flag clear                                             */
      __O  uint32_t  IC6        :  1;               /*!< Pn.6 interrupt flag clear                                             */
      __O  uint32_t  IC7        :  1;               /*!< Pn.7 interrupt flag clear                                             */
      __O  uint32_t  IC8        :  1;               /*!< Pn.8 interrupt flag clear                                             */
    } IC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  BSET;                            /*!< Offset:0x24 GPIO Port n Bits Set Operation Register                   */
    
    struct {
      __O  uint32_t  BSET0      :  1;               /*!< Set Pn.0                                                              */
      __O  uint32_t  BSET1      :  1;               /*!< Set Pn.1                                                              */
      __O  uint32_t  BSET2      :  1;               /*!< Set Pn.2                                                              */
      __O  uint32_t  BSET3      :  1;               /*!< Set Pn.3                                                              */
      __O  uint32_t  BSET4      :  1;               /*!< Set Pn.4                                                              */
      __O  uint32_t  BSET5      :  1;               /*!< Set Pn.5                                                              */
      __O  uint32_t  BSET6      :  1;               /*!< Set Pn.6                                                              */
      __O  uint32_t  BSET7      :  1;               /*!< Set Pn.7                                                              */
      __O  uint32_t  BSET8      :  1;               /*!< Set Pn.8                                                              */
    } BSET_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  BCLR;                            /*!< Offset:0x28 GPIO Port n Bits Clear Operation Register                 */
    
    struct {
      __O  uint32_t  BCLR0      :  1;               /*!< Clear Pn.0                                                            */
      __O  uint32_t  BCLR1      :  1;               /*!< Clear Pn.1                                                            */
      __O  uint32_t  BCLR2      :  1;               /*!< Clear Pn.2                                                            */
      __O  uint32_t  BCLR3      :  1;               /*!< Clear Pn.3                                                            */
      __O  uint32_t  BCLR4      :  1;               /*!< Clear Pn.4                                                            */
      __O  uint32_t  BCLR5      :  1;               /*!< Clear Pn.5                                                            */
      __O  uint32_t  BCLR6      :  1;               /*!< Clear Pn.6                                                            */
      __O  uint32_t  BCLR7      :  1;               /*!< Clear Pn.7                                                            */
      __O  uint32_t  BCLR8      :  1;               /*!< Clear Pn.8                                                            */
    } BCLR_b;                                       /*!< BitSize                                                               */
  };
} SN_GPIO3_Type;


/* ================================================================================ */
/* ================                     SN_WDT                     ================ */
/* ================================================================================ */


/**
  * @brief Watchdog Timer (SN_WDT)
  */

typedef struct {                                    /*!< SN_WDT Structure                                                      */
  
  union {
    __IO uint32_t  CFG;                             /*!< Offset:0x00 WDT Configuration Register                                */
    
    struct {
      __IO uint32_t  WDTEN      :  1;               /*!< WDT enable                                                            */
      __IO uint32_t  WDTIE      :  1;               /*!< WDT interrupt enable                                                  */
      __IO uint32_t  WDTINT     :  1;               /*!< WDT interrupt flag                                                    */
           uint32_t             : 13;
      __O  uint32_t  WDKEY      : 16;               /*!< WDT register key                                                      */
    } CFG_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CLKSOURCE;                       /*!< Offset:0x04 WDT Clock Source Register                                 */
    
    struct {
      __IO uint32_t  CLKSEL     :  2;               /*!< WDT clock source                                                      */
           uint32_t             : 14;
      __O  uint32_t  WDKEY      : 16;               /*!< WDT register key                                                      */
    } CLKSOURCE_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TC;                              /*!< Offset:0x08 WDT Timer Constant Register                               */
    
    struct {
      __IO uint32_t  TC         :  8;               /*!< Watchdog timer constant reload value                                  */
           uint32_t             :  8;
      __O  uint32_t  WDKEY      : 16;               /*!< WDT register key                                                      */
    } TC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  FEED;                            /*!< Offset:0x0C WDT Feed Register                                         */
    
    struct {
      __O  uint32_t  FV         : 16;               /*!< Watchdog feed value                                                   */
      __O  uint32_t  WDKEY      : 16;               /*!< WDT register key                                                      */
    } FEED_b;                                       /*!< BitSize                                                               */
  };
} SN_WDT_Type;


/* ================================================================================ */
/* ================                    SN_CT16B0                   ================ */
/* ================================================================================ */


/**
  * @brief 16-bit Timer 0 with Capture function (SN_CT16B0)
  */

typedef struct {                                    /*!< SN_CT16B0 Structure                                                   */
  
  union {
    __IO uint32_t  TMRCTRL;                         /*!< Offset:0x00 CT16Bn Timer Control Register                             */
    
    struct {
      __IO uint32_t  CEN        :  1;               /*!< Counter enable                                                        */
      __IO uint32_t  CRST       :  1;               /*!< Counter Reset                                                         */
    } TMRCTRL_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TC;                              /*!< Offset:0x04 CT16Bn Timer Counter Register                             */
    
    struct {
      __IO uint32_t  TC         : 16;               /*!< Timer Counter                                                         */
    } TC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PRE;                             /*!< Offset:0x08 CT16Bn Prescale Register                                  */
    
    struct {
      __IO uint32_t  PRE        :  8;               /*!< Prescaler                                                             */
    } PRE_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC;                              /*!< Offset:0x0C CT16Bn Prescale Counter Register                          */
    
    struct {
      __IO uint32_t  PC         :  8;               /*!< Prescaler Counter                                                     */
    } PC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CNTCTRL;                         /*!< Offset:0x10 CT16Bn Counter Control Register                           */
    
    struct {
      __IO uint32_t  CTM        :  2;               /*!< Counter/Timer Mode                                                    */
      __IO uint32_t  CIS        :  2;               /*!< Counter Input Select                                                  */
    } CNTCTRL_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MCTRL;                           /*!< Offset:0x14 CT16Bn Match Control Register                             */
    
    struct {
      __IO uint32_t  MR0IE      :  1;               /*!< Enable generating an interrupt when MR0 matches TC                    */
      __IO uint32_t  MR0RST     :  1;               /*!< Enable reset TC when MR0 matches TC                                   */
      __IO uint32_t  MR0STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR0 matches TC                  */
    } MCTRL_b;                                      /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED[2];
  __IO uint32_t  MR0;                               /*!< Offset:0x20 CT16Bn MR0 Register                                       */
  __I  uint32_t  RESERVED1[23];
  
  union {
    __IO uint32_t  CAPCTRL;                         /*!< Offset:0x80 CT16Bn Capture Control Register                           */
    
    struct {
      __IO uint32_t  CAP0RE     :  1;               /*!< Capture on CT16Bn_CAP0 rising edge                                    */
      __IO uint32_t  CAP0FE     :  1;               /*!< Capture on CT16Bn_CAP0 falling edge                                   */
      __IO uint32_t  CAP0IE     :  1;               /*!< Interrupt on CT16Bn_CAP0 event                                        */
      __IO uint32_t  CAP0EN     :  1;               /*!< CAP0 function enable                                                  */
    } CAPCTRL_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  CAP0;                            /*!< Offset:0x84 CT16Bn CAP0 Register                                      */
    
    struct {
      __I  uint32_t  CAP0       : 16;               /*!< Timer counter capture value                                           */
    } CAP0_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2[7];
  
  union {
    __I  uint32_t  RIS;                             /*!< Offset:0xA4 CT16Bn Raw Interrupt Status Register                      */
    
    struct {
      __I  uint32_t  MR0IF      :  1;               /*!< Match channel 0 interrupt flag                                        */
           uint32_t             : 23;
      __I  uint32_t  CAP0IF     :  1;               /*!< Capture channel 0 interrupt flag                                      */
    } RIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  IC;                              /*!< Offset:0xA8 CT16Bn Interrupt Clear Register                           */
    
    struct {
      __O  uint32_t  MR0IC      :  1;               /*!< MR0IF clear bit                                                       */
           uint32_t             : 23;
      __O  uint32_t  CAP0IC     :  1;               /*!< CAP0IF clear bit                                                      */
    } IC_b;                                         /*!< BitSize                                                               */
  };
} SN_CT16B0_Type;


/* ================================================================================ */
/* ================                    SN_CT16B1                   ================ */
/* ================================================================================ */


/**
  * @brief 16-bit Timer 1 with Capture function (SN_CT16B1)
  */

typedef struct {                                    /*!< SN_CT16B1 Structure                                                   */
  
  union {
    __IO uint32_t  TMRCTRL;                         /*!< Offset:0x00 CT16Bn Timer Control Register                             */
    
    struct {
      __IO uint32_t  CEN        :  1;               /*!< Counter enable                                                        */
      __IO uint32_t  CRST       :  1;               /*!< Counter Reset                                                         */
    } TMRCTRL_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TC;                              /*!< Offset:0x04 CT16Bn Timer Counter Register                             */
    
    struct {
      __IO uint32_t  TC         : 16;               /*!< Timer Counter                                                         */
    } TC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PRE;                             /*!< Offset:0x08 CT16Bn Prescale Register                                  */
    
    struct {
      __IO uint32_t  PRE        :  8;               /*!< Prescaler                                                             */
    } PRE_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PC;                              /*!< Offset:0x0C CT16Bn Prescale Counter Register                          */
    
    struct {
      __IO uint32_t  PC         :  8;               /*!< Prescaler Counter                                                     */
    } PC_b;                                         /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  MCTRL;                           /*!< Offset:0x14 CT16Bn Match Control Register                             */
    
    struct {
      __IO uint32_t  MR0IE      :  1;               /*!< Enable generating an interrupt when MR0 matches TC                    */
      __IO uint32_t  MR0RST     :  1;               /*!< Enable reset TC when MR0 matches TC                                   */
      __IO uint32_t  MR0STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR0 matches TC                  */
      __IO uint32_t  MR1IE      :  1;               /*!< Enable generating an interrupt when MR1 matches TC                    */
      __IO uint32_t  MR1RST     :  1;               /*!< Enable reset TC when MR1 matches TC                                   */
      __IO uint32_t  MR1STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR1 matches TC                  */
      __IO uint32_t  MR2IE      :  1;               /*!< Enable generating an interrupt when MR2 matches TC                    */
      __IO uint32_t  MR2RST     :  1;               /*!< Enable reset TC when MR2 matches TC                                   */
      __IO uint32_t  MR2STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR2 matches TC                  */
      __IO uint32_t  MR3IE      :  1;               /*!< Enable generating an interrupt when MR3 matches TC                    */
      __IO uint32_t  MR3RST     :  1;               /*!< Enable reset TC when MR3 matches TC                                   */
      __IO uint32_t  MR3STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR3 matches TC                  */
      __IO uint32_t  MR4IE      :  1;               /*!< Enable generating an interrupt when MR4 matches TC                    */
      __IO uint32_t  MR4RST     :  1;               /*!< Enable reset TC when MR4 matches TC                                   */
      __IO uint32_t  MR4STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR4 matches TC                  */
      __IO uint32_t  MR5IE      :  1;               /*!< Enable generating an interrupt when MR5 matches TC                    */
      __IO uint32_t  MR5RST     :  1;               /*!< Enable reset TC when MR5 matches TC                                   */
      __IO uint32_t  MR5STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR5 matches TC                  */
      __IO uint32_t  MR6IE      :  1;               /*!< Enable generating an interrupt when MR6 matches TC                    */
      __IO uint32_t  MR6RST     :  1;               /*!< Enable reset TC when MR6 matches TC                                   */
      __IO uint32_t  MR6STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR6 matches TC                  */
      __IO uint32_t  MR7IE      :  1;               /*!< Enable generating an interrupt when MR7 matches TC                    */
      __IO uint32_t  MR7RST     :  1;               /*!< Enable reset TC when MR7 matches TC                                   */
      __IO uint32_t  MR7STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR7 matches TC                  */
      __IO uint32_t  MR8IE      :  1;               /*!< Enable generating an interrupt when MR8 matches TC                    */
      __IO uint32_t  MR8RST     :  1;               /*!< Enable reset TC when MR8 matches TC                                   */
      __IO uint32_t  MR8STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR8 matches TC                  */
      __IO uint32_t  MR9IE      :  1;               /*!< Enable generating an interrupt based on CM[2:0] when MR9 matches
                                                         the value in the TC                                                   */
      __IO uint32_t  MR9RST     :  1;               /*!< Enable reset TC when MR9 matches TC                                   */
      __IO uint32_t  MR9STOP    :  1;               /*!< Stop TC and PC and clear CEN bit when MR9 matches TC                  */
    } MCTRL_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MCTRL2;                          /*!< Offset:0x18 CT16Bn Match Control Register                             */
    
    struct {
      __IO uint32_t  MR10IE     :  1;               /*!< Enable generating an interrupt when MR10 matches TC                   */
      __IO uint32_t  MR10RST    :  1;               /*!< Enable reset TC when MR10 matches TC                                  */
      __IO uint32_t  MR10STOP   :  1;               /*!< Stop TC and PC and clear CEN bit when MR10 matches TC                 */
      __IO uint32_t  MR11IE     :  1;               /*!< Enable generating an interrupt when MR11 matches TC                   */
      __IO uint32_t  MR11RST    :  1;               /*!< Enable reset TC when MR11 matches TC                                  */
      __IO uint32_t  MR11STOP   :  1;               /*!< Stop TC and PC and clear CEN bit when MR11 matches TC                 */
      __IO uint32_t  MR12IE     :  1;               /*!< Enable generating an interrupt when MR12 matches TC                   */
      __IO uint32_t  MR12RST    :  1;               /*!< Enable reset TC when MR12 matches TC                                  */
      __IO uint32_t  MR12STOP   :  1;               /*!< Stop TC and PC and clear CEN bit when MR12 matches TC                 */
      __IO uint32_t  MR13IE     :  1;               /*!< Enable generating an interrupt when MR13 matches TC                   */
      __IO uint32_t  MR13RST    :  1;               /*!< Enable reset TC when MR13 matches TC                                  */
      __IO uint32_t  MR13STOP   :  1;               /*!< Stop TC and PC and clear CEN bit when MR13 matches TC                 */
      __IO uint32_t  MR14IE     :  1;               /*!< Enable generating an interrupt when MR14 matches TC                   */
      __IO uint32_t  MR14RST    :  1;               /*!< Enable reset TC when MR14 matches TC                                  */
      __IO uint32_t  MR14STOP   :  1;               /*!< Stop TC and PC and clear CEN bit when MR14 matches TC                 */
      __IO uint32_t  MR15IE     :  1;               /*!< Enable generating an interrupt when MR15 matches TC                   */
      __IO uint32_t  MR15RST    :  1;               /*!< Enable reset TC when MR15 matches TC                                  */
      __IO uint32_t  MR15STOP   :  1;               /*!< Stop TC and PC and clear CEN bit when MR15 matches TC                 */
      __IO uint32_t  MR16IE     :  1;               /*!< Enable generating an interrupt when MR16 matches TC                   */
      __IO uint32_t  MR16RST    :  1;               /*!< Enable reset TC when MR16 matches TC                                  */
      __IO uint32_t  MR16STOP   :  1;               /*!< Stop TC and PC and clear CEN bit when MR16 matches TC                 */
      __IO uint32_t  MR17IE     :  1;               /*!< Enable generating an interrupt when MR17 matches TC                   */
      __IO uint32_t  MR17RST    :  1;               /*!< Enable reset TC when MR17 matches TC                                  */
      __IO uint32_t  MR17STOP   :  1;               /*!< Stop TC and PC and clear CEN bit when MR17 matches TC                 */
      __IO uint32_t  MR18IE     :  1;               /*!< Enable generating an interrupt when MR18 matches TC                   */
      __IO uint32_t  MR18RST    :  1;               /*!< Enable reset TC when MR18 matches TC                                  */
      __IO uint32_t  MR18STOP   :  1;               /*!< Stop TC and PC and clear CEN bit when MR18 matches TC                 */
      __IO uint32_t  MR19IE     :  1;               /*!< Enable generating an interrupt based on CM[2:0] when MR19 matches
                                                         the value in the TC                                                   */
      __IO uint32_t  MR19RST    :  1;               /*!< Enable reset TC when MR19 matches TC                                  */
      __IO uint32_t  MR19STOP   :  1;               /*!< Stop TC and PC and clear CEN bit when MR19 matches TC                 */
    } MCTRL2_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MCTRL3;                          /*!< Offset:0x1C CT16Bn Match Control Register                             */
    
    struct {
           uint32_t             :  3;
      __IO uint32_t  MR21IE     :  1;               /*!< Enable generating an interrupt when MR21 matches TC                   */
      __IO uint32_t  MR21RST    :  1;               /*!< Enable reset TC when MR21 matches TC                                  */
      __IO uint32_t  MR21STOP   :  1;               /*!< Stop TC and PC and clear CEN bit when MR21 matches TC                 */
      __IO uint32_t  MR22IE     :  1;               /*!< Enable generating an interrupt when MR22 matches TC                   */
      __IO uint32_t  MR22RST    :  1;               /*!< Enable reset TC when MR22 matches TC                                  */
      __IO uint32_t  MR22STOP   :  1;               /*!< Stop TC and PC and clear CEN bit when MR22 matches TC                 */
      __IO uint32_t  MR23IE     :  1;               /*!< Enable generating an interrupt when MR23 matches TC                   */
      __IO uint32_t  MR23RST    :  1;               /*!< Enable reset TC when MR23 matches TC                                  */
      __IO uint32_t  MR23STOP   :  1;               /*!< Stop TC and PC and clear CEN bit when MR23 matches TC                 */
    } MCTRL3_b;                                     /*!< BitSize                                                               */
  };
  __IO uint32_t  MR0;                               /*!< Offset:0x20 CT16Bn MR0 Register                                       */
  __IO uint32_t  MR1;                               /*!< Offset:0x24 CT16Bn MR1 Register                                       */
  __IO uint32_t  MR2;                               /*!< Offset:0x28 CT16Bn MR2 Register                                       */
  __IO uint32_t  MR3;                               /*!< Offset:0x2C CT16Bn MR3 Register                                       */
  __IO uint32_t  MR4;                               /*!< Offset:0x30 CT16Bn MR4 Register                                       */
  __IO uint32_t  MR5;                               /*!< Offset:0x34 CT16Bn MR5 Register                                       */
  __IO uint32_t  MR6;                               /*!< Offset:0x38 CT16Bn MR6 Register                                       */
  __IO uint32_t  MR7;                               /*!< Offset:0x3C CT16Bn MR7 Register                                       */
  __IO uint32_t  MR8;                               /*!< Offset:0x40 CT16Bn MR8 Register                                       */
  __IO uint32_t  MR9;                               /*!< Offset:0x44 CT16Bn MR9 Register                                       */
  __IO uint32_t  MR10;                              /*!< Offset:0x48 CT16Bn MR10 Register                                      */
  __IO uint32_t  MR11;                              /*!< Offset:0x4C CT16Bn MR11 Register                                      */
  __IO uint32_t  MR12;                              /*!< Offset:0x50 CT16Bn MR12 Register                                      */
  __IO uint32_t  MR13;                              /*!< Offset:0x54 CT16Bn MR13 Register                                      */
  __IO uint32_t  MR14;                              /*!< Offset:0x58 CT16Bn MR14 Register                                      */
  __IO uint32_t  MR15;                              /*!< Offset:0x5C CT16Bn MR15 Register                                      */
  __IO uint32_t  MR16;                              /*!< Offset:0x60 CT16Bn MR16 Register                                      */
  __IO uint32_t  MR17;                              /*!< Offset:0x64 CT16Bn MR17 Register                                      */
  __IO uint32_t  MR18;                              /*!< Offset:0x68 CT16Bn MR18 Register                                      */
  __IO uint32_t  MR19;                              /*!< Offset:0x6C CT16Bn MR19 Register                                      */
  __I  uint32_t  RESERVED1;
  __IO uint32_t  MR21;                              /*!< Offset:0x74 CT16Bn MR21 Register                                      */
  __IO uint32_t  MR22;                              /*!< Offset:0x78 CT16Bn MR22 Register                                      */
  __IO uint32_t  MR23;                              /*!< Offset:0x7C CT16Bn MR23 Register                                      */
  __I  uint32_t  RESERVED2[2];
  
  union {
    __IO uint32_t  EM;                              /*!< Offset:0x88 CT16Bn External Match Register                            */
    
    struct {
      __IO uint32_t  EM0        :  1;               /*!< When the TC matches MR0, this bit will act according to EMC0[1:0],
                                                         and also drive the state of CT16Bn_PWM0 output.                       */
      __IO uint32_t  EM1        :  1;               /*!< When the TC matches MR1, this bit will act according to EMC1[1:0],
                                                         and also drive the state of CT16Bn_PWM1 output.                       */
      __IO uint32_t  EM2        :  1;               /*!< When the TC matches MR2, this bit will act according to EMC2[1:0],
                                                         and also drive the state of CT16Bn_PWM2 output.                       */
      __IO uint32_t  EM3        :  1;               /*!< When the TC matches MR3, this bit will act according to EMC3[1:0],
                                                         and also drive the state of CT16Bn_PWM3 output.                       */
      __IO uint32_t  EM4        :  1;               /*!< When the TC matches MR4, this bit will act according to EMC4[1:0],
                                                         and also drive the state of CT16Bn_PWM0 output.                       */
      __IO uint32_t  EM5        :  1;               /*!< When the TC matches MR5, this bit will act according to EMC5[1:0],
                                                         and also drive the state of CT16Bn_PWM1 output.                       */
      __IO uint32_t  EM6        :  1;               /*!< When the TC matches MR6, this bit will act according to EMC6[1:0],
                                                         and also drive the state of CT16Bn_PWM2 output.                       */
      __IO uint32_t  EM7        :  1;               /*!< When the TC matches MR7, this bit will act according to EMC7[1:0],
                                                         and also drive the state of CT16Bn_PWM3 output.                       */
      __IO uint32_t  EM8        :  1;               /*!< When the TC matches MR8, this bit will act according to EMC8[1:0],
                                                         and also drive the state of CT16Bn_PWM0 output.                       */
      __IO uint32_t  EM9        :  1;               /*!< When the TC matches MR9, this bit will act according to EMC9[1:0],
                                                         and also drive the state of CT16Bn_PWM1 output.                       */
      __IO uint32_t  EM10       :  1;               /*!< When the TC matches MR10, this bit will act according to EMC10[1:0],
                                                         and also drive the state of CT16Bn_PWM2 output.                       */
      __IO uint32_t  EM11       :  1;               /*!< When the TC matches MR11, this bit will act according to EMC11[1:0],
                                                         and also drive the state of CT16Bn_PWM3 output.                       */
      __IO uint32_t  EM12       :  1;               /*!< When the TC matches MR12, this bit will act according to EMC12[1:0],
                                                         and also drive the state of CT16Bn_PWM0 output.                       */
      __IO uint32_t  EM13       :  1;               /*!< When the TC matches MR13, this bit will act according to EMC13[1:0],
                                                         and also drive the state of CT16Bn_PWM1 output.                       */
      __IO uint32_t  EM14       :  1;               /*!< When the TC matches MR14, this bit will act according to EMC14[1:0],
                                                         and also drive the state of CT16Bn_PWM2 output.                       */
      __IO uint32_t  EM15       :  1;               /*!< When the TC matches MR15, this bit will act according to EMC15[1:0],
                                                         and also drive the state of CT16Bn_PWM3 output.                       */
      __IO uint32_t  EM16       :  1;               /*!< When the TC matches MR16, this bit will act according to EMC16[1:0],
                                                         and also drive the state of CT16Bn_PWM0 output.                       */
      __IO uint32_t  EM17       :  1;               /*!< When the TC matches MR17, this bit will act according to EMC17[1:0],
                                                         and also drive the state of CT16Bn_PWM1 output.                       */
      __IO uint32_t  EM18       :  1;               /*!< When the TC matches MR18, this bit will act according to EMC18[1:0],
                                                         and also drive the state of CT16Bn_PWM2 output.                       */
      __IO uint32_t  EM19       :  1;               /*!< When the TC matches MR19, this bit will act according to EMC19[1:0],
                                                         and also drive the state of CT16Bn_PWM3 output.                       */
           uint32_t             :  1;
      __IO uint32_t  EM21       :  1;               /*!< When the TC matches MR21, this bit will act according to EMC21[1:0],
                                                         and also drive the state of CT16Bn_PWM1 output.                       */
      __IO uint32_t  EM22       :  1;               /*!< When the TC matches MR22, this bit will act according to EMC22[1:0],
                                                         and also drive the state of CT16Bn_PWM2 output.                       */
    } EM_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  EMC;                             /*!< Offset:0x8C CT16Bn External Match Control register                    */
    
    struct {
      __IO uint32_t  EMC0       :  2;               /*!< CT16Bn_PWM0 functionality                                             */
      __IO uint32_t  EMC1       :  2;               /*!< CT16Bn_PWM1 functionality                                             */
      __IO uint32_t  EMC2       :  2;               /*!< CT16Bn_PWM2 functionality                                             */
      __IO uint32_t  EMC3       :  2;               /*!< CT16Bn_PWM3 functionality                                             */
      __IO uint32_t  EMC4       :  2;               /*!< CT16Bn_PWM4 functionality                                             */
      __IO uint32_t  EMC5       :  2;               /*!< CT16Bn_PWM5 functionality                                             */
      __IO uint32_t  EMC6       :  2;               /*!< CT16Bn_PWM6 functionality                                             */
      __IO uint32_t  EMC7       :  2;               /*!< CT16Bn_PWM7 functionality                                             */
      __IO uint32_t  EMC8       :  2;               /*!< CT16Bn_PWM8 functionality                                             */
      __IO uint32_t  EMC9       :  2;               /*!< CT16Bn_PWM9 functionality                                             */
      __IO uint32_t  EMC10      :  2;               /*!< CT16Bn_PWM10 functionality                                            */
      __IO uint32_t  EMC11      :  2;               /*!< CT16Bn_PWM11 functionality                                            */
      __IO uint32_t  EMC12      :  2;               /*!< CT16Bn_PWM12 functionality                                            */
      __IO uint32_t  EMC13      :  2;               /*!< CT16Bn_PWM13 functionality                                            */
      __IO uint32_t  EMC14      :  2;               /*!< CT16Bn_PWM14 functionality                                            */
      __IO uint32_t  EMC15      :  2;               /*!< CT16Bn_PWM15 functionality                                            */
    } EMC_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  EMC2;                            /*!< Offset:0x90 CT16Bn External Match Control register 2                  */
    
    struct {
      __IO uint32_t  EMC16      :  2;               /*!< CT16Bn_PWM16 functionality                                            */
      __IO uint32_t  EMC17      :  2;               /*!< CT16Bn_PWM17 functionality                                            */
      __IO uint32_t  EMC18      :  2;               /*!< CT16Bn_PWM18 functionality                                            */
      __IO uint32_t  EMC19      :  2;               /*!< CT16Bn_PWM19 functionality                                            */
           uint32_t             :  2;
      __IO uint32_t  EMC21      :  2;               /*!< CT16Bn_PWM21 functionality                                            */
      __IO uint32_t  EMC22      :  2;               /*!< CT16Bn_PWM22 functionality                                            */
    } EMC2_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PWMCTRL;                         /*!< Offset:0x94 CT16Bn PWM Control Register                               */
    
    struct {
      __IO uint32_t  PWM0MODE   :  2;               /*!< PWM0 output mode                                                      */
      __IO uint32_t  PWM1MODE   :  2;               /*!< PWM1 output mode                                                      */
      __IO uint32_t  PWM2MODE   :  2;               /*!< PWM2 output mode                                                      */
      __IO uint32_t  PWM3MODE   :  2;               /*!< PWM3 output mode                                                      */
      __IO uint32_t  PWM4MODE   :  2;               /*!< PWM4 output mode                                                      */
      __IO uint32_t  PWM5MODE   :  2;               /*!< PWM5 output mode                                                      */
      __IO uint32_t  PWM6MODE   :  2;               /*!< PWM6 output mode                                                      */
      __IO uint32_t  PWM7MODE   :  2;               /*!< PWM7 output mode                                                      */
      __IO uint32_t  PWM8MODE   :  2;               /*!< PWM8 output mode                                                      */
      __IO uint32_t  PWM9MODE   :  2;               /*!< PWM9 output mode                                                      */
      __IO uint32_t  PWM10MODE  :  2;               /*!< PWM10 output mode                                                     */
      __IO uint32_t  PWM11MODE  :  2;               /*!< PWM11 output mode                                                     */
      __IO uint32_t  PWM12MODE  :  2;               /*!< PWM12 output mode                                                     */
      __IO uint32_t  PWM13MODE  :  2;               /*!< PWM13 output mode                                                     */
      __IO uint32_t  PWM14MODE  :  2;               /*!< PWM14 output mode                                                     */
      __IO uint32_t  PWM15MODE  :  2;               /*!< PWM15 output mode                                                     */
    } PWMCTRL_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PWMCTRL2;                        /*!< Offset:0x98 CT16Bn PWM Control Register 2                             */
    
    struct {
      __IO uint32_t  PWM16MODE  :  2;               /*!< PWM16 output mode                                                     */
      __IO uint32_t  PWM17MODE  :  2;               /*!< PWM17 output mode                                                     */
      __IO uint32_t  PWM18MODE  :  2;               /*!< PWM18 output mode                                                     */
      __IO uint32_t  PWM19MODE  :  2;               /*!< PWM19 output mode                                                     */
           uint32_t             :  2;
      __IO uint32_t  PWM21MODE  :  2;               /*!< PWM21 output mode                                                     */
      __IO uint32_t  PWM22MODE  :  2;               /*!< PWM22 output mode                                                     */
    } PWMCTRL2_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PWMENB;                          /*!< Offset:0x9C CT16Bn PWM Enable register                                */
    
    struct {
      __IO uint32_t  PWM0EN     :  1;               /*!< PWM0 enable                                                           */
      __IO uint32_t  PWM1EN     :  1;               /*!< PWM1 enable                                                           */
      __IO uint32_t  PWM2EN     :  1;               /*!< PWM2 enable                                                           */
      __IO uint32_t  PWM3EN     :  1;               /*!< PWM3 enable                                                           */
      __IO uint32_t  PWM4EN     :  1;               /*!< PWM4 enable                                                           */
      __IO uint32_t  PWM5EN     :  1;               /*!< PWM5 enable                                                           */
      __IO uint32_t  PWM6EN     :  1;               /*!< PWM6 enable                                                           */
      __IO uint32_t  PWM7EN     :  1;               /*!< PWM7 enable                                                           */
      __IO uint32_t  PWM8EN     :  1;               /*!< PWM8 enable                                                           */
      __IO uint32_t  PWM9EN     :  1;               /*!< PWM9 enable                                                           */
      __IO uint32_t  PWM10EN    :  1;               /*!< PWM10 enable                                                          */
      __IO uint32_t  PWM11EN    :  1;               /*!< PWM11 enable                                                          */
      __IO uint32_t  PWM12EN    :  1;               /*!< PWM12 enable                                                          */
      __IO uint32_t  PWM13EN    :  1;               /*!< PWM13 enable                                                          */
      __IO uint32_t  PWM14EN    :  1;               /*!< PWM14 enable                                                          */
      __IO uint32_t  PWM15EN    :  1;               /*!< PWM15 enable                                                          */
      __IO uint32_t  PWM16EN    :  1;               /*!< PWM16 enable                                                          */
      __IO uint32_t  PWM17EN    :  1;               /*!< PWM17 enable                                                          */
      __IO uint32_t  PWM18EN    :  1;               /*!< PWM18 enable                                                          */
      __IO uint32_t  PWM19EN    :  1;               /*!< PWM19 enable                                                          */
           uint32_t             :  1;
      __IO uint32_t  PWM21EN    :  1;               /*!< PWM21 enable                                                          */
      __IO uint32_t  PWM22EN    :  1;               /*!< PWM22 enable                                                          */
    } PWMENB_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PWMIOENB;                        /*!< Offset:0xA0 CT16Bn PWM IO Enable register                             */
    
    struct {
      __IO uint32_t  PWM0IOEN   :  1;               /*!< CT16Bn_PWM0/GPIO selection                                            */
      __IO uint32_t  PWM1IOEN   :  1;               /*!< CT16Bn_PWM1/GPIO selection                                            */
      __IO uint32_t  PWM2IOEN   :  1;               /*!< CT16Bn_PWM2/GPIO selection                                            */
      __IO uint32_t  PWM3IOEN   :  1;               /*!< CT16Bn_PWM3/GPIO selection                                            */
      __IO uint32_t  PWM4IOEN   :  1;               /*!< CT16Bn_PWM4/GPIO selection                                            */
      __IO uint32_t  PWM5IOEN   :  1;               /*!< CT16Bn_PWM5/GPIO selection                                            */
      __IO uint32_t  PWM6IOEN   :  1;               /*!< CT16Bn_PWM6/GPIO selection                                            */
      __IO uint32_t  PWM7IOEN   :  1;               /*!< CT16Bn_PWM7/GPIO selection                                            */
      __IO uint32_t  PWM8IOEN   :  1;               /*!< CT16Bn_PWM8/GPIO selection                                            */
      __IO uint32_t  PWM9IOEN   :  1;               /*!< CT16Bn_PWM9/GPIO selection                                            */
      __IO uint32_t  PWM10IOEN  :  1;               /*!< CT16Bn_PWM10/GPIO selection                                           */
      __IO uint32_t  PWM11IOEN  :  1;               /*!< CT16Bn_PWM11/GPIO selection                                           */
      __IO uint32_t  PWM12IOEN  :  1;               /*!< CT16Bn_PWM12/GPIO selection                                           */
      __IO uint32_t  PWM13IOEN  :  1;               /*!< CT16Bn_PWM13/GPIO selection                                           */
      __IO uint32_t  PWM14IOEN  :  1;               /*!< CT16Bn_PWM14/GPIO selection                                           */
      __IO uint32_t  PWM15IOEN  :  1;               /*!< CT16Bn_PWM15/GPIO selection                                           */
      __IO uint32_t  PWM16IOEN  :  1;               /*!< CT16Bn_PWM16/GPIO selection                                           */
      __IO uint32_t  PWM17IOEN  :  1;               /*!< CT16Bn_PWM17/GPIO selection                                           */
      __IO uint32_t  PWM18IOEN  :  1;               /*!< CT16Bn_PWM18/GPIO selection                                           */
      __IO uint32_t  PWM19IOEN  :  1;               /*!< CT16Bn_PWM19/GPIO selection                                           */
           uint32_t             :  1;
      __IO uint32_t  PWM21IOEN  :  1;               /*!< CT16Bn_PWM21/GPIO selection                                           */
      __IO uint32_t  PWM22IOEN  :  1;               /*!< CT16Bn_PWM22/GPIO selection                                           */
    } PWMIOENB_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RIS;                             /*!< Offset:0xA4 CT16Bn Raw Interrupt Status Register                      */
    
    struct {
      __I  uint32_t  MR0IF      :  1;               /*!< Match channel 0 interrupt flag                                        */
      __I  uint32_t  MR1IF      :  1;               /*!< Match channel 1 interrupt flag                                        */
      __I  uint32_t  MR2IF      :  1;               /*!< Match channel 2 interrupt flag                                        */
      __I  uint32_t  MR3IF      :  1;               /*!< Match channel 3 interrupt flag                                        */
      __I  uint32_t  MR4IF      :  1;               /*!< Match channel 4 interrupt flag                                        */
      __I  uint32_t  MR5IF      :  1;               /*!< Match channel 5 interrupt flag                                        */
      __I  uint32_t  MR6IF      :  1;               /*!< Match channel 6 interrupt flag                                        */
      __I  uint32_t  MR7IF      :  1;               /*!< Match channel 7 interrupt flag                                        */
      __I  uint32_t  MR8IF      :  1;               /*!< Match channel 8 interrupt flag                                        */
      __I  uint32_t  MR9IF      :  1;               /*!< Match channel 9 interrupt flag                                        */
      __I  uint32_t  MR10IF     :  1;               /*!< Match channel 10 interrupt flag                                       */
      __I  uint32_t  MR11IF     :  1;               /*!< Match channel 11 interrupt flag                                       */
      __I  uint32_t  MR12IF     :  1;               /*!< Match channel 12 interrupt flag                                       */
      __I  uint32_t  MR13IF     :  1;               /*!< Match channel 13 interrupt flag                                       */
      __I  uint32_t  MR14IF     :  1;               /*!< Match channel 14 interrupt flag                                       */
      __I  uint32_t  MR15IF     :  1;               /*!< Match channel 15 interrupt flag                                       */
      __I  uint32_t  MR16IF     :  1;               /*!< Match channel 16 interrupt flag                                       */
      __I  uint32_t  MR17IF     :  1;               /*!< Match channel 17 interrupt flag                                       */
      __I  uint32_t  MR18IF     :  1;               /*!< Match channel 18 interrupt flag                                       */
      __I  uint32_t  MR19IF     :  1;               /*!< Match channel 19 interrupt flag                                       */
           uint32_t             :  1;
      __I  uint32_t  MR21IF     :  1;               /*!< Match channel 21 interrupt flag                                       */
      __I  uint32_t  MR22IF     :  1;               /*!< Match channel 22 interrupt flag                                       */
      __I  uint32_t  MR23IF     :  1;               /*!< Match channel 23 interrupt flag                                       */
    } RIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  IC;                              /*!< Offset:0xA8 CT16Bn Interrupt Clear Register                           */
    
    struct {
      __O  uint32_t  MR0IC      :  1;               /*!< MR0IF clear bit                                                       */
      __O  uint32_t  MR1IC      :  1;               /*!< MR1IF clear bit                                                       */
      __O  uint32_t  MR2IC      :  1;               /*!< MR2IF clear bit                                                       */
      __O  uint32_t  MR3IC      :  1;               /*!< MR3IF clear bit                                                       */
      __O  uint32_t  MR4IC      :  1;               /*!< MR4IF clear bit                                                       */
      __O  uint32_t  MR5IC      :  1;               /*!< MR5IF clear bit                                                       */
      __O  uint32_t  MR6IC      :  1;               /*!< MR6IF clear bit                                                       */
      __O  uint32_t  MR7IC      :  1;               /*!< MR7IF clear bit                                                       */
      __O  uint32_t  MR8IC      :  1;               /*!< MR8IF clear bit                                                       */
      __O  uint32_t  MR9IC      :  1;               /*!< MR9IF clear bit                                                       */
      __O  uint32_t  MR10IC     :  1;               /*!< MR10IF clear bit                                                      */
      __O  uint32_t  MR11IC     :  1;               /*!< MR11IF clear bit                                                      */
      __O  uint32_t  MR12IC     :  1;               /*!< MR12IF clear bit                                                      */
      __O  uint32_t  MR13IC     :  1;               /*!< MR13IF clear bit                                                      */
      __O  uint32_t  MR14IC     :  1;               /*!< MR14IF clear bit                                                      */
      __O  uint32_t  MR15IC     :  1;               /*!< MR15IF clear bit                                                      */
      __O  uint32_t  MR16IC     :  1;               /*!< MR16IF clear bit                                                      */
      __O  uint32_t  MR17IC     :  1;               /*!< MR17IF clear bit                                                      */
      __O  uint32_t  MR18IC     :  1;               /*!< MR18IF clear bit                                                      */
      __O  uint32_t  MR19IC     :  1;               /*!< MR19IF clear bit                                                      */
           uint32_t             :  1;
      __O  uint32_t  MR21IC     :  1;               /*!< MR21IF clear bit                                                      */
      __O  uint32_t  MR22IC     :  1;               /*!< MR22IF clear bit                                                      */
      __O  uint32_t  MR23IC     :  1;               /*!< MR23IF clear bit                                                      */
    } IC_b;                                         /*!< BitSize                                                               */
  };
} SN_CT16B1_Type;


/* ================================================================================ */
/* ================                     SN_PMU                     ================ */
/* ================================================================================ */


/**
  * @brief Power Management Unit (SN_PMU)
  */

typedef struct {                                    /*!< SN_PMU Structure                                                      */
  __I  uint32_t  RESERVED[16];
  
  union {
    __IO uint32_t  CTRL;                            /*!< Offset:0x40 PMU Control Register                                      */
    
    struct {
      __IO uint32_t  MODE       :  3;               /*!< Low Power mode selection                                              */
    } CTRL_b;                                       /*!< BitSize                                                               */
  };
} SN_PMU_Type;


/* ================================================================================ */
/* ================                     SN_SPI0                    ================ */
/* ================================================================================ */


/**
  * @brief SPI0 (SN_SPI0)
  */

typedef struct {                                    /*!< SN_SPI0 Structure                                                     */
  
  union {
    __IO uint32_t  CTRL0;                           /*!< Offset:0x00 SPIn Control Register 0                                   */
    
    struct {
      __IO uint32_t  SSPEN      :  1;               /*!< SSP enable bit                                                        */
      __IO uint32_t  LOOPBACK   :  1;               /*!< Loopback mode enable                                                  */
      __IO uint32_t  SDODIS     :  1;               /*!< Slave data out disable                                                */
      __IO uint32_t  MS         :  1;               /*!< Master/Slave selection                                                */
      __IO uint32_t  FORMAT     :  1;               /*!< Interface format                                                      */
           uint32_t             :  1;
      __O  uint32_t  FRESET     :  2;               /*!< SPI FSM and FIFO Reset                                                */
      __IO uint32_t  DL         :  4;               /*!< Data length = DL[3:0]+1                                               */
      __IO uint32_t  TXFIFOTH   :  3;               /*!< TX FIFO Threshold level                                               */
      __IO uint32_t  RXFIFOTH   :  3;               /*!< RX FIFO Threshold level                                               */
      __IO uint32_t  SELDIS     :  1;               /*!< Auto-SEL disable bit. For SPI mode only                               */
    } CTRL0_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CTRL1;                           /*!< Offset:0x04 SPIn Control Register 1                                   */
    
    struct {
      __IO uint32_t  MLSB       :  1;               /*!< MSB/LSB seletion                                                      */
      __IO uint32_t  CPOL       :  1;               /*!< Clock priority selection                                              */
      __IO uint32_t  CPHA       :  1;               /*!< Clock phase of edge sampling                                          */
    } CTRL1_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CLKDIV;                          /*!< Offset:0x08 SPIn Clock Divider Register                               */
    
    struct {
      __IO uint32_t  DIV        :  8;               /*!< SPIn SCK=SPIn_PCLK/(2*DIV+2)                                          */
    } CLKDIV_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  STAT;                            /*!< Offset:0x0C SPIn Status Register                                      */
    
    struct {
      __I  uint32_t  TX_EMPTY   :  1;               /*!< TX FIFO empty flag                                                    */
      __I  uint32_t  TX_FULL    :  1;               /*!< TX FIFO full flag                                                     */
      __I  uint32_t  RX_EMPTY   :  1;               /*!< RX FIFO empty flag                                                    */
      __I  uint32_t  RX_FULL    :  1;               /*!< RX FIFO full flag                                                     */
      __I  uint32_t  BUSY       :  1;               /*!< Busy flag                                                             */
      __I  uint32_t  TXFIFOTHF  :  1;               /*!< TX FIFO threshold flag                                                */
      __I  uint32_t  RXFIFOTHF  :  1;               /*!< RX FIFO threshold flag                                                */
    } STAT_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IE;                              /*!< Offset:0x10 SPIn Interrupt Enable Register                            */
    
    struct {
      __IO uint32_t  RXOVFIE    :  1;               /*!< RX FIFO overflow interrupt enable                                     */
      __IO uint32_t  RXTOIE     :  1;               /*!< RX time-out interrupt enable                                          */
      __IO uint32_t  RXFIFOTHIE :  1;               /*!< RX FIFO threshold interrupt enable                                    */
      __IO uint32_t  TXFIFOTHIE :  1;               /*!< TX FIFO threshold interrupt enable                                    */
    } IE_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RIS;                             /*!< Offset:0x14 SPIn Raw Interrupt Status Register                        */
    
    struct {
      __I  uint32_t  RXOVFIF    :  1;               /*!< RX FIFO overflow interrupt flag                                       */
      __I  uint32_t  RXTOIF     :  1;               /*!< RX time-out interrupt flag                                            */
      __I  uint32_t  RXFIFOTHIF :  1;               /*!< RX FIFO threshold interrupt flag                                      */
      __I  uint32_t  TXFIFOTHIF :  1;               /*!< TX FIFO threshold interrupt flag                                      */
    } RIS_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  IC;                              /*!< Offset:0x18 SPIn Interrupt Clear Register                             */
    
    struct {
      __O  uint32_t  RXOVFIC    :  1;               /*!< RX FIFO overflow flag clear                                           */
      __O  uint32_t  RXTOIC     :  1;               /*!< RX time-out interrupt flag clear                                      */
      __O  uint32_t  RXFIFOTHIC :  1;               /*!< RX Interrupt flag Clear                                               */
      __O  uint32_t  TXFIFOTHIC :  1;               /*!< TX Interrupt flag Clear                                               */
    } IC_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA;                            /*!< Offset:0x1C SPIn Data Register                                        */
    
    struct {
      __IO uint32_t  Data       : 16;               /*!< Data                                                                  */
    } DATA_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DF;                              /*!< Offset:0x20 SPIn Data Fetch Register                                  */
    
    struct {
      __IO uint32_t  DF         :  1;               /*!< SPI data fetch delay enable                                           */
    } DF_b;                                         /*!< BitSize                                                               */
  };
} SN_SPI0_Type;


/* ================================================================================ */
/* ================                     SN_I2C0                    ================ */
/* ================================================================================ */


/**
  * @brief I2C0 (SN_I2C0)
  */

typedef struct {                                    /*!< SN_I2C0 Structure                                                     */
  
  union {
    __IO uint32_t  CTRL;                            /*!< Offset:0x00 I2Cn Control Register                                     */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  NACK       :  1;               /*!< NACK assert flag                                                      */
      __IO uint32_t  ACK        :  1;               /*!< ACK assert flag                                                       */
           uint32_t             :  1;
      __IO uint32_t  STO        :  1;               /*!< STOP assert flag                                                      */
      __IO uint32_t  STA        :  1;               /*!< START assert flag                                                     */
           uint32_t             :  1;
      __IO uint32_t  MODE       :  1;               /*!< I2C mode                                                              */
      __IO uint32_t  I2CEN      :  1;               /*!< I2Cn interface enable                                                 */
    } CTRL_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  STAT;                            /*!< Offset:0x04 I2Cn Status Register                                      */
    
    struct {
      __I  uint32_t  RX_DN      :  1;               /*!< RX done status                                                        */
      __I  uint32_t  ACK_STAT   :  1;               /*!< ACK done status                                                       */
      __I  uint32_t  NACK_STAT  :  1;               /*!< NACK done status                                                      */
      __I  uint32_t  STOP_DN    :  1;               /*!< STOP done status                                                      */
      __I  uint32_t  START_DN   :  1;               /*!< START done status                                                     */
      __I  uint32_t  MST        :  1;               /*!< I2C master/slave status                                               */
      __I  uint32_t  SLV_RX_HIT :  1;               /*!< Slave RX address hit flag                                             */
      __I  uint32_t  SLV_TX_HIT :  1;               /*!< Slave TX address hit flag                                             */
      __I  uint32_t  LOST_ARB   :  1;               /*!< Lost arbitration status                                               */
      __I  uint32_t  TIMEOUT    :  1;               /*!< Time-out status                                                       */
           uint32_t             :  5;
      __IO uint32_t  I2CIF      :  1;               /*!< I2C interrupt flag                                                    */
    } STAT_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TXDATA;                          /*!< Offset:0x08 I2Cn TX Data Register                                     */
    
    struct {
      __IO uint32_t  Data       :  8;               /*!< TX Data                                                               */
    } TXDATA_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RXDATA;                          /*!< Offset:0x0C I2Cn RX Data Register                                     */
    
    struct {
      __I  uint32_t  Data       :  8;               /*!< RX Data received when RX_DN=1                                         */
    } RXDATA_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SLVADDR0;                        /*!< Offset:0x10 I2Cn Slave Address 0 Register                             */
    
    struct {
      __IO uint32_t  ADDR       : 10;               /*!< I2Cn slave address 0                                                  */
           uint32_t             : 20;
      __IO uint32_t  GCEN       :  1;               /*!< General call address enable                                           */
      __IO uint32_t  ADD_MODE   :  1;               /*!< Slave address mode                                                    */
    } SLVADDR0_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SLVADDR1;                        /*!< Offset:0x14 I2Cn Slave Address 1 Register                             */
    
    struct {
      __IO uint32_t  ADDR       : 10;               /*!< I2Cn slave address 1                                                  */
    } SLVADDR1_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SLVADDR2;                        /*!< Offset:0x18 I2Cn Slave Address 2 Register                             */
    
    struct {
      __IO uint32_t  ADDR       : 10;               /*!< I2Cn slave address 2                                                  */
    } SLVADDR2_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SLVADDR3;                        /*!< Offset:0x1C I2Cn Slave Address 3 Register                             */
    
    struct {
      __IO uint32_t  ADDR       : 10;               /*!< I2Cn slave address 3                                                  */
    } SLVADDR3_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SCLHT;                           /*!< Offset:0x20 I2Cn SCL High Time Register                               */
    
    struct {
      __IO uint32_t  SCLH       :  8;               /*!< SCLn High period time=(SCLHT+1)*I2Cn_PCLK cycle                       */
    } SCLHT_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SCLLT;                           /*!< Offset:0x24 I2Cn SCL Low Time Register                                */
    
    struct {
      __IO uint32_t  SCLL       :  8;               /*!< SCLn Low period time=(SCLLT+1)*I2Cn_PCLK cycle                        */
    } SCLLT_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SCLCT;                           /*!< Offset:0x28 I2C SCL Check Time register                               */
    
    struct {
      __IO uint32_t  SCLCT      :  4;               /*!< Count for checking SCL arbitration in Master mode.                    */
    } SCLCT_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TOCTRL;                          /*!< Offset:0x2C I2Cn Timeout Control Register                             */
    
    struct {
      __IO uint32_t  TO         : 16;               /*!< Timeout period time = TO*I2Cn_PCLK cycle                              */
    } TOCTRL_b;                                     /*!< BitSize                                                               */
  };
} SN_I2C0_Type;


/* ================================================================================ */
/* ================                    SN_FLASH                    ================ */
/* ================================================================================ */


/**
  * @brief FLASH Memory Control Registers (SN_FLASH)
  */

typedef struct {                                    /*!< SN_FLASH Structure                                                    */
  
  union {
    __IO uint32_t  LPCTRL;                          /*!< Offset:0x00 Flash Low Power Control Register                          */
    
    struct {
      __IO uint32_t  LPMODE     :  4;               /*!< Flash Low Power mode selection bit                                    */
    } LPCTRL_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  STATUS;                          /*!< Offset:0x04 Flash Status Register                                     */
    
    struct {
      __I  uint32_t  BUSY       :  1;               /*!< Busy flag                                                             */
           uint32_t             :  1;
      __IO uint32_t  ERR        :  1;               /*!< Erase/Error flag                                                      */
    } STATUS_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CTRL;                            /*!< Offset:0x08 Flash Control Register                                    */
    
    struct {
      __IO uint32_t  PG         :  1;               /*!< Flash program mode chosen bit                                         */
      __IO uint32_t  PER        :  1;               /*!< Page erase mode chosen bit                                            */
      __IO uint32_t  MER        :  1;               /*!< Mass erase mode chosen bit                                            */
           uint32_t             :  3;
      __IO uint32_t  START      :  1;               /*!< Start erase/program operation                                         */
      __IO uint32_t  CHK        :  1;               /*!< Checksum calculation chosen                                           */
    } CTRL_b;                                       /*!< BitSize                                                               */
  };
  __IO uint32_t  DATA;                              /*!< Offset:0x0C Flash Data Register                                       */
  __IO uint32_t  ADDR;                              /*!< Offset:0x10 Flash Address Register                                    */
  
  union {
    __I  uint32_t  CHKSUM;                          /*!< Offset:0x14 Flash Checksum Register                                   */
    
    struct {
      __I  uint32_t  UserROM    : 16;               /*!< Checksum of User ROM                                                  */
      __I  uint32_t  BootROM    : 16;               /*!< Checksum of Boot ROM                                                  */
    } CHKSUM_b;                                     /*!< BitSize                                                               */
  };
} SN_FLASH_Type;


/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif




/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

#define SN_SYS0_BASE                    0x40060000UL
#define SN_SYS1_BASE                    0x4005E000UL
#define SN_USB_BASE                     0x4005C000UL
#define SN_GPIO0_BASE                   0x40044000UL
#define SN_GPIO1_BASE                   0x40046000UL
#define SN_GPIO2_BASE                   0x40048000UL
#define SN_GPIO3_BASE                   0x4004A000UL
#define SN_WDT_BASE                     0x40010000UL
#define SN_CT16B0_BASE                  0x40000000UL
#define SN_CT16B1_BASE                  0x40002000UL
#define SN_PMU_BASE                     0x40032000UL
#define SN_SPI0_BASE                    0x4001C000UL
#define SN_I2C0_BASE                    0x40018000UL
#define SN_FLASH_BASE                   0x40062000UL


/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define SN_SYS0                         ((SN_SYS0_Type            *) SN_SYS0_BASE)
#define SN_SYS1                         ((SN_SYS1_Type            *) SN_SYS1_BASE)
#define SN_USB                          ((SN_USB_Type             *) SN_USB_BASE)
#define SN_GPIO0                        ((SN_GPIO0_Type           *) SN_GPIO0_BASE)
#define SN_GPIO1                        ((SN_GPIO1_Type           *) SN_GPIO1_BASE)
#define SN_GPIO2                        ((SN_GPIO2_Type           *) SN_GPIO2_BASE)
#define SN_GPIO3                        ((SN_GPIO3_Type           *) SN_GPIO3_BASE)
#define SN_WDT                          ((SN_WDT_Type             *) SN_WDT_BASE)
#define SN_CT16B0                       ((SN_CT16B0_Type          *) SN_CT16B0_BASE)
#define SN_CT16B1                       ((SN_CT16B1_Type          *) SN_CT16B1_BASE)
#define SN_PMU                          ((SN_PMU_Type             *) SN_PMU_BASE)
#define SN_SPI0                         ((SN_SPI0_Type            *) SN_SPI0_BASE)
#define SN_I2C0                         ((SN_I2C0_Type            *) SN_I2C0_BASE)
#define SN_FLASH                        ((SN_FLASH_Type           *) SN_FLASH_BASE)


/** @} */ /* End of group Device_Peripheral_Registers */
/** @} */ /* End of group SN32F260 */
/** @} */ /* End of group SONiX Technology Co., Ltd. */

#ifdef __cplusplus
}
#endif


#endif  /* SN32F260_H */

