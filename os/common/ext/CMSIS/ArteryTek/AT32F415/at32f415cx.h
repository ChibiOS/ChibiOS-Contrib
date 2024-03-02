/**
  ******************************************************************************
  * @file    at32f415cx.h
  * @author  Artery Technology & HorrorTroll & Zhaqian
  * @version v2.1.1
  * @date    26-October-2023
  * @brief   AT32F415Cx header file.
  *
  ******************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup at32f415cx
  * @{
  */

#ifndef __AT32F415Cx_H
#define __AT32F415Cx_H

#ifdef __cplusplus
 extern "C" {
#endif

/**
  * @brief CMSIS Device version number V2.1.1
  */
#define __AT32F415_LIBRARY_VERSION_MAJOR   (0x02) /*!< [31:24] major version */
#define __AT32F415_LIBRARY_VERSION_MIDDLE  (0x01) /*!< [23:16] middle version */
#define __AT32F415_LIBRARY_VERSION_MINOR   (0x01) /*!< [15:8]  minor version */
#define __AT32F415_LIBRARY_VERSION_RC      (0x00) /*!< [7:0]   release candidate */
#define __AT32F415_LIBRARY_VERSION         ((__AT32F415_LIBRARY_VERSION_MAJOR  << 24)\
                                           |(__AT32F415_LIBRARY_VERSION_MIDDLE << 16)\
                                           |(__AT32F415_LIBRARY_VERSION_MINOR  << 8 )\
                                           |(__AT32F415_LIBRARY_VERSION_RC))

/**
  * @}
  */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
  * @brief Configuration of the Cortex-M4 Processor and Core Peripherals
 */
#define __CM4_REV                  0x0001U  /*!< Core Revision r0p1                           */
#define __MPU_PRESENT              1U       /*!< AT32 devices provide an MPU                  */
#define __NVIC_PRIO_BITS           4U       /*!< AT32 uses 4 Bits for the Priority Levels     */
#define __Vendor_SysTickConfig     0U       /*!< Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT              0U       /*!< AT32 devices provide an FPU                  */

/**
  * @}
  */

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

/**
 * @brief AT32F415Cx Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */

 /*!< Interrupt Number Definition */
typedef enum
{
/******  Cortex-M4 Processor Exceptions Numbers ***************************************************/
  Reset_IRQn                  = -15,    /*!< 1 Reset Vector Interrupt                             */
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                             */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M4 Hard Fault Interrupt                     */
  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt              */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt                      */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt                    */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                       */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                 */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                       */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                   */

/******  AT32 specific Interrupt Numbers **********************************************************/
  WWDT_IRQn                   = 0,      /*!< Window WatchDog Timer Interrupt                      */
  PVM_IRQn                    = 1,      /*!< PVM Interrupt linked to EXINT16                      */
  TAMPER_IRQn                 = 2,      /*!< Tamper Interrupt linked to EXINT21                   */
  ERTC_IRQn                   = 3,      /*!< ERTC Interrupt linked to EXINT22                     */
  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                               */
  CRM_IRQn                    = 5,      /*!< CRM global Interrupt                                 */
  EXINT0_IRQn                 = 6,      /*!< EXINT Line 0 Interrupt                               */
  EXINT1_IRQn                 = 7,      /*!< EXINT Line 1 Interrupt                               */
  EXINT2_IRQn                 = 8,      /*!< EXINT Line 2 Interrupt                               */
  EXINT3_IRQn                 = 9,      /*!< EXINT Line 3 Interrupt                               */
  EXINT4_IRQn                 = 10,     /*!< EXINT Line 4 Interrupt                               */
  DMA1_Channel1_IRQn          = 11,     /*!< DMA1 Channel 1 global Interrupt                      */
  DMA1_Channel2_IRQn          = 12,     /*!< DMA1 Channel 2 global Interrupt                      */
  DMA1_Channel3_IRQn          = 13,     /*!< DMA1 Channel 3 global Interrupt                      */
  DMA1_Channel4_IRQn          = 14,     /*!< DMA1 Channel 4 global Interrupt                      */
  DMA1_Channel5_IRQn          = 15,     /*!< DMA1 Channel 5 global Interrupt                      */
  DMA1_Channel6_IRQn          = 16,     /*!< DMA1 Channel 6 global Interrupt                      */
  DMA1_Channel7_IRQn          = 17,     /*!< DMA1 Channel 7 global Interrupt                      */
  ADC1_IRQn                   = 18,     /*!< ADC1 global Interrupt                                */
  CAN1_TX_IRQn                = 19,     /*!< CAN1 TX Interrupt                                    */
  CAN1_RX0_IRQn               = 20,     /*!< CAN1 RX0 Interrupt                                   */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
  CAN1_SE_IRQn                = 22,     /*!< CAN1 SE Interrupt                                    */
  EXINT9_5_IRQn               = 23,     /*!< EXINT Line[9:5] Interrupts                           */
  TMR1_BRK_TMR9_IRQn          = 24,     /*!< TMR1 Break Interrupt and TMR9 global Interrupt       */
  TMR1_OVF_TMR10_IRQn         = 25,     /*!< TMR1 Overflow Interrupt and TMR10 global Interrupt   */
  TMR1_TRG_HALL_TMR11_IRQn    = 26,     /*!< TMR1 Trigger and Hall Interrupt and TMR11 global IRQ */
  TMR1_CH_IRQn                = 27,     /*!< TMR1 Channel Interrupt                               */
  TMR2_GLOBAL_IRQn            = 28,     /*!< TMR2 global Interrupt                                */
  TMR3_GLOBAL_IRQn            = 29,     /*!< TMR3 global Interrupt                                */
  TMR4_GLOBAL_IRQn            = 30,     /*!< TMR4 global Interrupt                                */
  I2C1_EVT_IRQn               = 31,     /*!< I2C1 Event Interrupt                                 */
  I2C1_ERR_IRQn               = 32,     /*!< I2C1 Error Interrupt                                 */
  I2C2_EVT_IRQn               = 33,     /*!< I2C2 Event Interrupt                                 */
  I2C2_ERR_IRQn               = 34,     /*!< I2C2 Error Interrupt                                 */
  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                              */
  EXINT15_10_IRQn             = 40,     /*!< EXINT Line[15:10] Interrupts                         */
  ERTCAlarm_IRQn              = 41,     /*!< ERTC Alarm Interrupt linked to EXINT17               */
  OTGFS_WKUP_IRQn             = 42,     /*!< OTGFS Wake Up Interrupt linked to EXINT18            */
  SDIO_IRQn                   = 49,     /*!< SDIO global Interrupt                                */
  TMR5_GLOBAL_IRQn            = 50,     /*!< TMR5 global Interrupt                                */
  DMA2_Channel1_IRQn          = 56,     /*!< DMA2 Channel 1 global Interrupt                      */
  DMA2_Channel2_IRQn          = 57,     /*!< DMA2 Channel 2 global Interrupt                      */
  DMA2_Channel3_IRQn          = 58,     /*!< DMA2 Channel 3 global Interrupt                      */
  DMA2_Channel4_5_IRQn        = 59,     /*!< DMA2 Channel 4 and Channel 5 global Interrupt        */
  OTGFS_IRQn                  = 67,     /*!< OTGFS global Interrupt                               */
  CMP1_IRQn                   = 70,     /*!< CMP1 Interrupt linked to EXINT19                     */
  CMP2_IRQn                   = 71,     /*!< CMP2 Interrupt linked to EXINT20                     */
  DMA2_Channel6_7_IRQn        = 75,     /*!< DMA2 Channel 6 and Channel 7 global Interrupt        */
} IRQn_Type;

/**
  * @}
  */

#include "core_cm4.h"
#include "system_at32f415.h"
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */

/**
  * @brief Analog to Digital Converter
  */

typedef struct
{
  __IO uint32_t STS;             /*!< ADC status register,                         Address offset: 0x00 */
  __IO uint32_t CTRL1;           /*!< ADC control register 1,                      Address offset: 0x04 */
  __IO uint32_t CTRL2;           /*!< ADC control register 2,                      Address offset: 0x08 */
  __IO uint32_t SPT1;            /*!< ADC sampling time register 1,                Address offset: 0x0C */
  __IO uint32_t SPT2;            /*!< ADC sampling time register 2,                Address offset: 0x10 */
  __IO uint32_t PCDTO1;          /*!< ADC preempted channel data offset reg 1,     Address offset: 0x14 */
  __IO uint32_t PCDTO2;          /*!< ADC preempted channel data offset reg 2,     Address offset: 0x18 */
  __IO uint32_t PCDTO3;          /*!< ADC preempted channel data offset reg 3      Address offset: 0x1C */
  __IO uint32_t PCDTO4;          /*!< ADC preempted channel data offset reg 4      Address offset: 0x20 */
  __IO uint32_t VMHB;            /*!< ADC voltage monitor high threshold register, Address offset: 0x24 */
  __IO uint32_t VMLB;            /*!< ADC voltage monitor low threshold register,  Address offset: 0x28 */
  __IO uint32_t OSQ1;            /*!< ADC ordinary sequence register 1,            Address offset: 0x2C */
  __IO uint32_t OSQ2;            /*!< ADC ordinary sequence register 2,            Address offset: 0x30 */
  __IO uint32_t OSQ3;            /*!< ADC ordinary sequence register 3,            Address offset: 0x34 */
  __IO uint32_t PSQ;             /*!< ADC preempted sequence register,             Address offset: 0x38 */
  __IO uint32_t PDT1;            /*!< ADC preempted data register 1,               Address offset: 0x3C */
  __IO uint32_t PDT2;            /*!< ADC preempted data register 2,               Address offset: 0x40 */
  __IO uint32_t PDT3;            /*!< ADC preempted data register 3,               Address offset: 0x44 */
  __IO uint32_t PDT4;            /*!< ADC preempted data register 4,               Address offset: 0x48 */
  __IO uint32_t ODT;             /*!< ADC ordinary data register,                  Address offset: 0x4C */
} ADC_TypeDef;

/**
  * @brief Controller Area Network TX Mailbox Registers
  */

typedef struct
{
  __IO uint32_t TMI;
  __IO uint32_t TMC;
  __IO uint32_t TMDTL;
  __IO uint32_t TMDTH;
} CAN_TxMailBox_TypeDef;

/**
  * @brief Controller Area Network FIFO Mailbox Registers
  */

typedef struct
{
  __IO uint32_t RFI;
  __IO uint32_t RFC;
  __IO uint32_t RFDTL;
  __IO uint32_t RFDTH;
} CAN_FIFOMailBox_TypeDef;

/**
  * @brief Controller Area Network Filter Registers
  */

typedef struct
{
  __IO uint32_t FFB1;
  __IO uint32_t FFB2;
} CAN_FilterRegister_TypeDef;

/**
  * @brief Controller Area Network
  */

typedef struct
{
  __IO uint32_t MCTRL;                               /*!< CAN master control register,                 Address offset: 0x000         */
  __IO uint32_t MSTS;                                /*!< CAN master status register,                  Address offset: 0x004         */
  __IO uint32_t TSTS;                                /*!< CAN transmit status register,                Address offset: 0x008         */
  __IO uint32_t RF0;                                 /*!< CAN receive FIFO 0 register,                 Address offset: 0x00C         */
  __IO uint32_t RF1;                                 /*!< CAN receive FIFO 1 register,                 Address offset: 0x010         */
  __IO uint32_t INTEN;                               /*!< CAN interrupt enable register,               Address offset: 0x014         */
  __IO uint32_t ESTS;                                /*!< CAN error status register,                   Address offset: 0x018         */
  __IO uint32_t BTMG;                                /*!< CAN bit timing register,                     Address offset: 0x01C         */
  uint32_t      RESERVED0[88];                       /*!< Reserved,                                    Address offset: 0x020 ~ 0x17F */
  CAN_TxMailBox_TypeDef sTxMailBox[3];               /*!< CAN TX Mailbox registers,                    Address offset: 0x180 ~ 0x1AC */
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];           /*!< CAN FIFO Mailbox registers,                  Address offset: 0x1B0 ~ 0x1CC */
  uint32_t      RESERVED1[12];                       /*!< Reserved,                                    Address offset: 0x1D0 ~ 0x1FF */
  __IO uint32_t FCTRL;                               /*!< CAN filter control register,                 Address offset: 0x200         */
  __IO uint32_t FMCFG;                               /*!< CAN filter mode configuration register,      Address offset: 0x204         */
  uint32_t      RESERVED2;                           /*!< Reserved,                                    Address offset: 0x208         */
  __IO uint32_t FBWCFG;                              /*!< CAN filter bit width configuration register, Address offset: 0x20C         */
  uint32_t      RESERVED3;                           /*!< Reserved,                                    Address offset: 0x210         */
  __IO uint32_t FRF;                                 /*!< CAN filter FIFO association register,        Address offset: 0x214         */
  uint32_t      RESERVED4;                           /*!< Reserved,                                    Address offset: 0x218         */
  __IO uint32_t FACFG;                               /*!< CAN filter activation control register,      Address offset: 0x21C         */
  uint32_t      RESERVED5[8];                        /*!< Reserved,                                    Address offset: 0x220 ~ 0x23F */
  CAN_FilterRegister_TypeDef sFilterRegister[14];    /*!< CAN filter registers,                        Address offset: 0x240 ~ 0x2AC */
} CAN_TypeDef;

/**
  * @brief Comparator
  */

typedef struct
{
  __IO uint32_t CTRLSTS1;    /*!< CMP control and status register 1,           Address offset: 0x00 */
  __IO uint32_t CTRLSTS2;    /*!< CMP control and status register 2,           Address offset: 0x04 */
} CMP_TypeDef;

/**
  * @brief CRC calculation unit
  */

typedef struct
{
  __IO uint32_t DT;          /*!< CRC Data register,                           Address offset: 0x00 */
  __IO uint32_t CDT;         /*!< CRC Common data register,                    Address offset: 0x04 */
  __IO uint32_t CTRL;        /*!< CRC Control register,                        Address offset: 0x08 */
  uint32_t      RESERVED;    /*!< Reserved,                                    Address offset: 0x0C */
  __IO uint32_t IDT;         /*!< CRC Initialization register,                 Address offset: 0x10 */
} CRC_TypeDef;

/**
  * @brief Clock and Reset Manage
  */

typedef struct
{
  __IO uint32_t CTRL;            /*!< CRM Clock control register,                  Address offset: 0x00        */
  __IO uint32_t CFG;             /*!< CRM Clock configuration register,            Address offset: 0x04        */
  __IO uint32_t CLKINT;          /*!< CRM Clock interrupt register,                Address offset: 0x08        */
  __IO uint32_t APB2RST;         /*!< CRM APB2 peripheral reset register,          Address offset: 0x0C        */
  __IO uint32_t APB1RST;         /*!< CRM APB1 peripheral reset register,          Address offset: 0x10        */
  __IO uint32_t AHBEN;           /*!< CRM APB peripheral clock enable register,    Address offset: 0x14        */
  __IO uint32_t APB2EN;          /*!< CRM APB2 peripheral clock enable register,   Address offset: 0x18        */
  __IO uint32_t APB1EN;          /*!< CRM APB1 peripheral clock enable register,   Address offset: 0x1C        */
  __IO uint32_t BPDC;            /*!< CRM Battery powered domain control register, Address offset: 0x20        */
  __IO uint32_t CTRLSTS;         /*!< CRM Control/status register,                 Address offset: 0x24        */
  __IO uint32_t AHBRST;          /*!< CRM APB peripheral reset register,           Address offset: 0x28        */
  __IO uint32_t PLL;             /*!< CRM PLL configuration register,              Address offset: 0x2C        */
  __IO uint32_t MISC1;           /*!< CRM Additional register 1,                   Address offset: 0x30        */
  uint32_t      RESERVED0[4];    /*!< Reserved,                                    Address offset: 0x34 ~ 0x40 */
  __IO uint32_t OTG_EXTCTRL;     /*!< CRM OTG_FS extended control register,        Address offset: 0x44        */
  uint32_t      RESERVED1[3];    /*!< Reserved,                                    Address offset: 0x48 - 0x50 */
  __IO uint32_t MISC2;           /*!< CRM Additional register 2,                   Address offset: 0x54        */
} CRM_TypeDef;

/**
  * @brief Debug MCU
  */

typedef struct
{
  __IO uint32_t IDCODE;    /*!< DEBUG device ID,                             Address offset: 0xE004_2000 */
  __IO uint32_t CTRL;      /*!< DEBUG control register,                      Address offset: 0xE004_2004 */
} DEBUG_TypeDef;

/**
  * @brief DMA Controller
  */

typedef struct
{
  __IO uint32_t CCTRL;           /*!< DMA channel x configuration register,        Address offset: 0x08 + 20 * (x - 1) x = 1 ... 7 */
  __IO uint32_t CDTCNT;          /*!< DMA channel x number of data register,       Address offset: 0x0C + 20 * (x - 1) x = 1 ... 7 */
  __IO uint32_t CPADDR;          /*!< DMA channel x peripheral address register,   Address offset: 0x10 + 20 * (x - 1) x = 1 ... 7 */
  __IO uint32_t CMADDR;          /*!< DMA channel x memory address register,       Address offset: 0x14 + 20 * (x - 1) x = 1 ... 7 */
} DMA_Channel_TypeDef;

typedef struct
{
  __IO uint32_t STS;             /*!< DMA interrupt status register,               Address offset: 0x00        */
  __IO uint32_t CLR;             /*!< DMA interrupt flag clear register,           Address offset: 0x04        */
  uint32_t      RESERVED[38];    /*!< Reserved,                                    Address offset: 0x08 ~ 0x9C */
  __IO uint32_t SRC_SEL0;        /*!< DMA Channel source register 0,               Address offset: 0xA0        */
  __IO uint32_t SRC_SEL1;        /*!< DMA Channel source register 1,               Address offset: 0xA4        */
} DMA_TypeDef;

/**
  * @brief Enhanced Real-Time Clock
  */

typedef struct
{
  __IO uint32_t TIME;        /*!< ERTC time register,                          Address offset: 0x00 */
  __IO uint32_t DATE;        /*!< ERTC date register,                          Address offset: 0x04 */
  __IO uint32_t CTRL;        /*!< ERTC control register,                       Address offset: 0x08 */
  __IO uint32_t STS;         /*!< ERTC initialization and status register,     Address offset: 0x0C */
  __IO uint32_t DIV;         /*!< ERTC divider register,                       Address offset: 0x10 */
  __IO uint32_t WAT;         /*!< ERTC wakeup timer register,                  Address offset: 0x14 */
  __IO uint32_t CCAL;        /*!< ERTC coarse calibration register,            Address offset: 0x18 */
  __IO uint32_t ALA;         /*!< ERTC alarm clock A register,                 Address offset: 0x1C */
  __IO uint32_t ALB;         /*!< ERTC alarm clock B register,                 Address offset: 0x20 */
  __IO uint32_t WP;          /*!< ERTC write protection register,              Address offset: 0x24 */
  __IO uint32_t SBS;         /*!< ERTC subsecond register,                     Address offset: 0x28 */
  __IO uint32_t TADJ;        /*!< ERTC time adjustment register,               Address offset: 0x2C */
  __IO uint32_t TSTM;        /*!< ERTC time stamp time register,               Address offset: 0x30 */
  __IO uint32_t TSDT;        /*!< ERTC time stamp date register,               Address offset: 0x34 */
  __IO uint32_t TSSBS;       /*!< ERTC time stamp subsecond register,          Address offset: 0x38 */
  __IO uint32_t SCAL;        /*!< ERTC smooth calibration register,            Address offset: 0x3C */
  __IO uint32_t TAMP;        /*!< ERTC tamper configuration register,          Address offset: 0x40 */
  __IO uint32_t ALASBS;      /*!< ERTC alarm clock A subsecond register,       Address offset: 0x44 */
  __IO uint32_t ALBSBS;      /*!< ERTC alarm clock B subsecond register,       Address offset: 0x48 */
  uint32_t      RESERVED;    /*!< Reserved,                                    Address offset: 0x4C */
  __IO uint32_t BPR1;        /*!< ERTC battery powered domain data register 1, Address offset: 0x50 */
  __IO uint32_t BPR2;        /*!< ERTC battery powered domain data register 2, Address offset: 0x54 */
  __IO uint32_t BPR3;        /*!< ERTC battery powered domain data register 3, Address offset: 0x58 */
  __IO uint32_t BPR4;        /*!< ERTC battery powered domain data register 4, Address offset: 0x5C */
  __IO uint32_t BPR5;        /*!< ERTC battery powered domain data register 5, Address offset: 0x60 */
  __IO uint32_t BPR6;        /*!< ERTC battery powered domain data register 6, Address offset: 0x64 */
  __IO uint32_t BPR7;        /*!< ERTC battery powered domain data register 7, Address offset: 0x68 */
  __IO uint32_t BPR8;        /*!< ERTC battery powered domain data register 8, Address offset: 0x6C */
  __IO uint32_t BPR9;        /*!< ERTC battery powered domain data register 9, Address offset: 0x70 */
  __IO uint32_t BPR10;       /*!< ERTC BAT powered domain data register 10,    Address offset: 0x74 */
  __IO uint32_t BPR11;       /*!< ERTC BAT powered domain data register 11,    Address offset: 0x78 */
  __IO uint32_t BPR12;       /*!< ERTC BAT powered domain data register 12,    Address offset: 0x7C */
  __IO uint32_t BPR13;       /*!< ERTC BAT powered domain data register 13,    Address offset: 0x80 */
  __IO uint32_t BPR14;       /*!< ERTC BAT powered domain data register 14,    Address offset: 0x84 */
  __IO uint32_t BPR15;       /*!< ERTC BAT powered domain data register 15,    Address offset: 0x88 */
  __IO uint32_t BPR16;       /*!< ERTC BAT powered domain data register 16,    Address offset: 0x8C */
  __IO uint32_t BPR17;       /*!< ERTC BAT powered domain data register 17,    Address offset: 0x90 */
  __IO uint32_t BPR18;       /*!< ERTC BAT powered domain data register 18,    Address offset: 0x94 */
  __IO uint32_t BPR19;       /*!< ERTC BAT powered domain data register 19,    Address offset: 0x98 */
  __IO uint32_t BPR20;       /*!< ERTC BAT powered domain data register 20,    Address offset: 0x9C */
} ERTC_TypeDef;

/**
  * @brief External Interrupt/Event Controller
  */

typedef struct
{
  __IO uint32_t INTEN;      /*!< EXINT Interrupt enable register,             Address offset: 0x00 */
  __IO uint32_t EVTEN;      /*!< EXINT Event enable register,                 Address offset: 0x04 */
  __IO uint32_t POLCFG1;    /*!< EXINT Polarity configuration register 1,     Address offset: 0x08 */
  __IO uint32_t POLCFG2;    /*!< EXINT Polarity configuration register 2,     Address offset: 0x0C */
  __IO uint32_t SWTRG;      /*!< EXINT Software trigger register,             Address offset: 0x10 */
  __IO uint32_t INTSTS;     /*!< EXINT Interrupt status register,             Address offset: 0x14 */
} EXINT_TypeDef;

/**
  * @brief Flash Memory Registers
  */

typedef struct
{
  __IO uint32_t PSR;               /*!< FLASH performance select register,           Address offset: 0x00         */
  __IO uint32_t UNLOCK;            /*!< FLASH unlock register 1,                     Address offset: 0x04         */
  __IO uint32_t USD_UNLOCK;        /*!< FLASH user system data unlock register,      Address offset: 0x08         */
  __IO uint32_t STS;               /*!< FLASH status register,                       Address offset: 0x0C         */
  __IO uint32_t CTRL;              /*!< FLASH control register,                      Address offset: 0x10         */
  __IO uint32_t ADDR;              /*!< FLASH address register,                      Address offset: 0x14         */
  uint32_t      RESERVED0;         /*!< Reserved,                                    Address offset: 0x18         */
  __IO uint32_t USD;               /*!< FLASH user system data register,             Address offset: 0x1C         */
  __IO uint32_t EPPS;              /*!< FLASH erase/program protection status reg,   Address offset: 0x20         */
  uint32_t      RESERVED1[20];     /*!< Reserved,                                    Address offset: 0x24 ~ 0x70  */
  __IO uint32_t SLIB_STS0;         /*!< FLASH security library status register 0,    Address offset: 0x74         */
  __IO uint32_t SLIB_STS1;         /*!< FLASH security library status register 1,    Address offset: 0x78         */
  __IO uint32_t SLIB_PWD_CLR;      /*!< FLASH security library password clear reg,   Address offset: 0x7C         */
  __IO uint32_t SLIB_MISC_STS;     /*!< FLASH security library additional stat reg,  Address offset: 0x80         */
  __IO uint32_t CRC_ADDR;          /*!< FLASH CRC address register,                  Address offset: 0x84         */
  __IO uint32_t CRC_CTRL;          /*!< FLASH CRC control register,                  Address offset: 0x88         */
  __IO uint32_t CRC_CHKR;          /*!< FLASH CRC check result register,             Address offset: 0x8C         */
  uint32_t      RESERVED2[52];     /*!< Reserved,                                    Address offset: 0x90 ~ 0x15C */
  __IO uint32_t SLIB_SET_PWD;      /*!< FLASH security library password setting reg, Address offset: 0x160        */
  __IO uint32_t SLIB_SET_RANGE;    /*!< FLASH security library address setting reg,  Address offset: 0x164        */
  __IO uint32_t EM_SLIB_SET;       /*!< FLASH extension mem security lib set reg,    Address offset: 0x168        */
  __IO uint32_t BTM_MODE_SET;      /*!< FLASH boot mode setting register,            Address offset: 0x16C        */
  __IO uint32_t SLIB_UNLOCK;       /*!< FLASH security library unlock register,      Address offset: 0x170        */
} FLASH_TypeDef;

/**
  * @brief User System Data Registers
  */

typedef struct
{
  __IO uint16_t FAP;                 /*!< USD memory access protection,                Address offset: 0x1FFF_F800               */
  __IO uint16_t SSB;                 /*!< USD System configuration byte,               Address offset: 0x1FFF_F802               */
  __IO uint16_t DATA0;               /*!< USD User data 0,                             Address offset: 0x1FFF_F804               */
  __IO uint16_t DATA1;               /*!< USD User data 1,                             Address offset: 0x1FFF_F806               */
  __IO uint16_t EPP0;                /*!< USD erase/write protection byte 0,           Address offset: 0x1FFF_F808               */
  __IO uint16_t EPP1;                /*!< USD erase/write protection byte 1,           Address offset: 0x1FFF_F80A               */
  __IO uint16_t EPP2;                /*!< USD erase/write protection byte 2,           Address offset: 0x1FFF_F80C               */
  __IO uint16_t EPP3;                /*!< USD erase/write protection byte 3,           Address offset: 0x1FFF_F80E               */
  __IO uint16_t DATA[504];           /*!< USD User data 2 ~ 505,                       Address offset: 0x1FFF_F810 ~ 0x1FFF_FBFC */
} USD_TypeDef;

/**
  * @brief General Purpose I/O
  */

typedef struct
{
  __IO uint32_t CFGLR;          /*!< GPIO configuration register low,             Address offset: 0x00 */
  __IO uint32_t CFGHR;          /*!< GPIO configuration register high,            Address offset: 0x04 */
  __IO uint32_t IDT;            /*!< GPIO input data register,                    Address offset: 0x08 */
  __IO uint32_t ODT;            /*!< GPIO output data register,                   Address offset: 0x0C */
  __IO uint32_t SCR;            /*!< GPIO set/clear register,                     Address offset: 0x10 */
  __IO uint32_t CLR;            /*!< GPIO clear register,                         Address offset: 0x14 */
  __IO uint32_t WPR;            /*!< GPIO write protection register,              Address offset: 0x18 */
} GPIO_TypeDef;

/**
  * @brief Multiplex Function I/O
  */

typedef struct
{
  __IO uint32_t EVTOUT;      /*!< IOMUX Event output control register,         Address offset: 0x00 */
  __IO uint32_t REMAP;       /*!< IOMUX remap register 1,                      Address offset: 0x04 */
  __IO uint32_t EXINTC[4];   /*!< IOMUX external interrupt config register,    Address offset: 0x08 ~ 0x14 */
  uint32_t      RESERVED;    /*!< Reserved,                                    Address offset: 0x18 */
  __IO uint32_t REMAP2;      /*!< IOMUX remap register 2,                      Address offset: 0x1C */
  __IO uint32_t REMAP3;      /*!< IOMUX remap register 3,                      Address offset: 0x20 */
  __IO uint32_t REMAP4;      /*!< IOMUX remap register 4,                      Address offset: 0x24 */
  __IO uint32_t REMAP5;      /*!< IOMUX remap register 5,                      Address offset: 0x28 */
  __IO uint32_t REMAP6;      /*!< IOMUX remap register 6,                      Address offset: 0x2C */
  __IO uint32_t REMAP7;      /*!< IOMUX remap register 7,                      Address offset: 0x30 */
  __IO uint32_t REMAP8;      /*!< IOMUX remap register 8,                      Address offset: 0x34 */
} IOMUX_TypeDef;

/**
  * @brief Inter Integrated Circuit Interface
  */

typedef struct
{
  __IO uint32_t CTRL1;      /*!< I2C Control register 1,                      Address offset: 0x00 */
  __IO uint32_t CTRL2;      /*!< I2C Control register 2,                      Address offset: 0x04 */
  __IO uint32_t OADDR1;     /*!< I2C Own address register 1,                  Address offset: 0x08 */
  __IO uint32_t OADDR2;     /*!< I2C Own address register 2,                  Address offset: 0x0C */
  __IO uint32_t DT;         /*!< I2C Data register,                           Address offset: 0x10 */
  __IO uint32_t STS1;       /*!< I2C Status register 1,                       Address offset: 0x14 */
  __IO uint32_t STS2;       /*!< I2C Status register 2,                       Address offset: 0x18 */
  __IO uint32_t CLKCTRL;    /*!< I2C Clock control register,                  Address offset: 0x1C */
  __IO uint32_t TMRISE;     /*!< I2C timer rise time register,                Address offset: 0x20 */
} I2C_TypeDef;

/**
  * @brief Power Control
  */

typedef struct
{
  __IO uint32_t CTRL;       /*!< PWC Power control register,                  Address offset: 0x00 */
  __IO uint32_t CTRLSTS;    /*!< PWC Power control/status register,           Address offset: 0x04 */
} PWC_TypeDef;

/**
  * @brief SD Host Interface
  */

typedef struct
{
  __IO uint32_t PWRCTRL;          /*!< SDIO power control register,                 Address offset: 0x00        */
  __IO uint32_t CLKCTRL;          /*!< SDIO clock control register,                 Address offset: 0x04        */
  __IO uint32_t ARG;              /*!< SDIO argument register,                      Address offset: 0x08        */
  __IO uint32_t CMD;              /*!< SDIO command register,                       Address offset: 0x0C        */
  __I  uint32_t RSPCMD;           /*!< SDIO command response register,              Address offset: 0x10        */
  __I  uint32_t RSP1;             /*!< SDIO response register 1,                    Address offset: 0x14        */
  __I  uint32_t RSP2;             /*!< SDIO response register 2,                    Address offset: 0x18        */
  __I  uint32_t RSP3;             /*!< SDIO response register 3,                    Address offset: 0x1C        */
  __I  uint32_t RSP4;             /*!< SDIO response register 4,                    Address offset: 0x20        */
  __IO uint32_t DTTMR;            /*!< SDIO data timer register,                    Address offset: 0x24        */
  __IO uint32_t DTLEN;            /*!< SDIO data length register,                   Address offset: 0x28        */
  __IO uint32_t DTCTRL;           /*!< SDIO data control register,                  Address offset: 0x2C        */
  __I  uint32_t DTCNTR;           /*!< SDIO data counter register,                  Address offset: 0x30        */
  __I  uint32_t STS;              /*!< SDIO status register,                        Address offset: 0x34        */
  __IO uint32_t INTCLR;           /*!< SDIO clear interrupt register,               Address offset: 0x38        */
  __IO uint32_t INTEN;            /*!< SDIO interrupt mask register,                Address offset: 0x3C        */
  uint32_t      RESERVED0[2];     /*!< Reserved,                                    Address offset: 0x40 ~ 0x44 */
  __I  uint32_t BUFCNTR;          /*!< SDIO BUF counter register,                   Address offset: 0x48        */
  uint32_t      RESERVED1[13];    /*!< Reserved,                                    Address offset: 0x4C ~ 0x7C */
  __IO uint32_t BUF;              /*!< SDIO data BUF register,                      Address offset: 0x80        */
} SDIO_TypeDef;

/**
  * @brief Serial Peripheral Interface
  */

typedef struct
{
  __IO uint32_t CTRL1;      /*!< SPI control register 1,                      Address offset: 0x00 */
  __IO uint32_t CTRL2;      /*!< SPI control register 2,                      Address offset: 0x04 */
  __IO uint32_t STS;        /*!< SPI status register,                         Address offset: 0x08 */
  __IO uint32_t DT;         /*!< SPI data register,                           Address offset: 0x0C */
  __IO uint32_t CPOLY;      /*!< SPI CRC register,                            Address offset: 0x10 */
  __IO uint32_t RCRC;       /*!< SPI RX CRC register,                         Address offset: 0x14 */
  __IO uint32_t TCRC;       /*!< SPI TX CRC register,                         Address offset: 0x18 */
  __IO uint32_t I2SCTRL;    /*!< SPI_I2S register,                            Address offset: 0x1C */
  __IO uint32_t I2SCLKP;    /*!< SPI_I2S prescaler register,                  Address offset: 0x20 */
} SPI_TypeDef;

/**
  * @brief TMR Timers
  */

typedef struct
{
  __IO uint32_t CTRL1;      /*!< TMR control register 1,                      Address offset: 0x00 */
  __IO uint32_t CTRL2;      /*!< TMR control register 2,                      Address offset: 0x04 */
  __IO uint32_t STCTRL;     /*!< TMR slave timer control register,            Address offset: 0x08 */
  __IO uint32_t IDEN;       /*!< TMR DMA/interrupt enable register,           Address offset: 0x0C */
  __IO uint32_t ISTS;       /*!< TMR interrupt status register,               Address offset: 0x10 */
  __IO uint32_t SWEVT;      /*!< TMR software event register,                 Address offset: 0x14 */
  __IO uint32_t CM1;        /*!< TMR channel mode register 1,                 Address offset: 0x18 */
  __IO uint32_t CM2;        /*!< TMR channel mode register 2,                 Address offset: 0x1C */
  __IO uint32_t CCTRL;      /*!< TMR Channel control register,                Address offset: 0x20 */
  __IO uint32_t CVAL;       /*!< TMR counter value,                           Address offset: 0x24 */
  __IO uint32_t DIV;        /*!< TMR division value,                          Address offset: 0x28 */
  __IO uint32_t PR;         /*!< TMR period register,                         Address offset: 0x2C */
  __IO uint32_t RPR;        /*!< TMR repetition period register,              Address offset: 0x30 */
  __IO uint32_t C1DT;       /*!< TMR channel 1 data register,                 Address offset: 0x34 */
  __IO uint32_t C2DT;       /*!< TMR channel 2 data register,                 Address offset: 0x38 */
  __IO uint32_t C3DT;       /*!< TMR channel 3 data register,                 Address offset: 0x3C */
  __IO uint32_t C4DT;       /*!< TMR channel 4 data register,                 Address offset: 0x40 */
  __IO uint32_t BRK;        /*!< TMR break register,                          Address offset: 0x44 */
  __IO uint32_t DMACTRL;    /*!< TMR DMA control register,                    Address offset: 0x48 */
  __IO uint32_t DMADT;      /*!< TMR DMA data register,                       Address offset: 0x4C */
} TMR_TypeDef;

/**
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */

typedef struct
{
  __IO uint32_t STS;      /*!< USART status register,                       Address offset: 0x00 */
  __IO uint32_t DT;       /*!< USART data register,                         Address offset: 0x04 */
  __IO uint32_t BAUDR;    /*!< USART baud rate register,                    Address offset: 0x08 */
  __IO uint32_t CTRL1;    /*!< USART control register 1,                    Address offset: 0x0C */
  __IO uint32_t CTRL2;    /*!< USART control register 2,                    Address offset: 0x10 */
  __IO uint32_t CTRL3;    /*!< USART control register 3,                    Address offset: 0x14 */
  __IO uint32_t GDIV;     /*!< USART guard time and divider register,       Address offset: 0x18 */
} USART_TypeDef;

/**
  * @brief WATCHDOG Timer
  */

typedef struct
{
  __IO uint32_t CMD;    /*!< WDT Command register,                        Address offset: 0x00 */
  __IO uint32_t DIV;    /*!< WDT Divider register,                        Address offset: 0x04 */
  __IO uint32_t RLD;    /*!< WDT Reload register,                         Address offset: 0x08 */
  __IO uint32_t STS;    /*!< WDT Status register,                         Address offset: 0x0C */
} WDT_TypeDef;

/**
  * @brief Window WATCHDOG Timer
  */

typedef struct
{
  __IO uint32_t CTRL;    /*!< WWDT Control register,                       Address offset: 0x00 */
  __IO uint32_t CFG;     /*!< WWDT Configuration register,                 Address offset: 0x04 */
  __IO uint32_t STS;     /*!< WWDT Status register,                        Address offset: 0x08 */
} WWDT_TypeDef;

/**
  * @}
  */

/** @addtogroup Peripheral_memory_map
  * @{
  */

#define FLASH_BASE                   0x08000000U                     /*!< FLASH base address in the alias region         */
#define FLASH_BANK1_END              0x0803FFFFU                     /*!< FLASH end address of bank 1                    */
#define SRAM_BASE                    0x20000000U                     /*!< SRAM base address in the alias region          */
#define PERIPH_BASE                  0x40000000U                     /*!< Peripheral base address in the alias region    */

#define SRAM_BB_BASE                 0x22000000U                     /*!< SRAM base address in the bit-band region       */
#define PERIPH_BB_BASE               0x42000000U                     /*!< Peripheral base address in the bit-band region */

/*!< Peripheral memory map */
#define APB1PERIPH_BASE              PERIPH_BASE                     /*!< APB1 base address                              */
#define APB2PERIPH_BASE              (PERIPH_BASE + 0x00010000U)     /*!< APB2 base address                              */
#define AHBPERIPH_BASE               (PERIPH_BASE + 0x00020000U)     /*!< AHB base address                               */

#define TMR2_BASE                    (APB1PERIPH_BASE + 0x00000000U) /*!< TMR2 base address                              */
#define TMR3_BASE                    (APB1PERIPH_BASE + 0x00000400U) /*!< TMR3 base address                              */
#define TMR4_BASE                    (APB1PERIPH_BASE + 0x00000800U) /*!< TMR4 base address                              */
#define TMR5_BASE                    (APB1PERIPH_BASE + 0x00000C00U) /*!< TMR5 base address                              */
#define CMP_BASE                     (APB1PERIPH_BASE + 0x00002400U) /*!< CMP base address                               */
#define ERTC_BASE                    (APB1PERIPH_BASE + 0x00002800U) /*!< ERTC base address                              */
#define WWDT_BASE                    (APB1PERIPH_BASE + 0x00002C00U) /*!< WWDT base address                              */
#define WDT_BASE                     (APB1PERIPH_BASE + 0x00003000U) /*!< WDT base address                               */
#define SPI2_BASE                    (APB1PERIPH_BASE + 0x00003800U) /*!< SPI2 base address                              */
#define USART2_BASE                  (APB1PERIPH_BASE + 0x00004400U) /*!< USART2 base address                            */
#define USART3_BASE                  (APB1PERIPH_BASE + 0x00004800U) /*!< USART3 base address                            */
#define I2C1_BASE                    (APB1PERIPH_BASE + 0x00005400U) /*!< I2C1 base address                              */
#define I2C2_BASE                    (APB1PERIPH_BASE + 0x00005800U) /*!< I2C2 base address                              */
#define CAN1_BASE                    (APB1PERIPH_BASE + 0x00006400U) /*!< CAN1 base address                              */
#define PWC_BASE                     (APB1PERIPH_BASE + 0x00007000U) /*!< PWC base address                               */
#define IOMUX_BASE                   (APB2PERIPH_BASE + 0x00000000U) /*!< IOMUX base address                             */
#define EXINT_BASE                   (APB2PERIPH_BASE + 0x00000400U) /*!< EXINT base address                             */
#define GPIOA_BASE                   (APB2PERIPH_BASE + 0x00000800U) /*!< GPIOA base address                             */
#define GPIOB_BASE                   (APB2PERIPH_BASE + 0x00000C00U) /*!< GPIOB base address                             */
#define GPIOC_BASE                   (APB2PERIPH_BASE + 0x00001000U) /*!< GPIOC base address                             */
#define GPIOD_BASE                   (APB2PERIPH_BASE + 0x00001400U) /*!< GPIOD base address                             */
#define GPIOF_BASE                   (APB2PERIPH_BASE + 0x00001C00U) /*!< GPIOF base address                             */
#define ADC1_BASE                    (APB2PERIPH_BASE + 0x00002400U) /*!< ADC1 base address                              */
#define TMR1_BASE                    (APB2PERIPH_BASE + 0x00002C00U) /*!< TMR1 base address                              */
#define SPI1_BASE                    (APB2PERIPH_BASE + 0x00003000U) /*!< SPI1 base address                              */
#define USART1_BASE                  (APB2PERIPH_BASE + 0x00003800U) /*!< USART1 base address                            */
#define TMR9_BASE                    (APB2PERIPH_BASE + 0x00004C00U) /*!< TMR9 base address                              */
#define TMR10_BASE                   (APB2PERIPH_BASE + 0x00005000U) /*!< TMR10 base address                             */
#define TMR11_BASE                   (APB2PERIPH_BASE + 0x00005400U) /*!< TMR11 base address                             */

#define SDIO_BASE                    (PERIPH_BASE + 0x00018000U)     /*!< SDIO base address                              */

#define DMA1_BASE                    (AHBPERIPH_BASE + 0x00000000U)  /*!< DMA1 base address                              */
#define DMA1_Channel1_BASE           (AHBPERIPH_BASE + 0x00000008U)  /*!< DMA1 Channel 1 base address                    */
#define DMA1_Channel2_BASE           (AHBPERIPH_BASE + 0x0000001CU)  /*!< DMA1 Channel 2 base address                    */
#define DMA1_Channel3_BASE           (AHBPERIPH_BASE + 0x00000030U)  /*!< DMA1 Channel 3 base address                    */
#define DMA1_Channel4_BASE           (AHBPERIPH_BASE + 0x00000044U)  /*!< DMA1 Channel 4 base address                    */
#define DMA1_Channel5_BASE           (AHBPERIPH_BASE + 0x00000058U)  /*!< DMA1 Channel 5 base address                    */
#define DMA1_Channel6_BASE           (AHBPERIPH_BASE + 0x0000006CU)  /*!< DMA1 Channel 6 base address                    */
#define DMA1_Channel7_BASE           (AHBPERIPH_BASE + 0x00000080U)  /*!< DMA1 Channel 7 base address                    */
#define DMA2_BASE                    (AHBPERIPH_BASE + 0x00000400U)  /*!< DMA2 base address                              */
#define DMA2_Channel1_BASE           (AHBPERIPH_BASE + 0x00000408U)  /*!< DMA2 Channel 1 base address                    */
#define DMA2_Channel2_BASE           (AHBPERIPH_BASE + 0x0000041CU)  /*!< DMA2 Channel 2 base address                    */
#define DMA2_Channel3_BASE           (AHBPERIPH_BASE + 0x00000430U)  /*!< DMA2 Channel 3 base address                    */
#define DMA2_Channel4_BASE           (AHBPERIPH_BASE + 0x00000444U)  /*!< DMA2 Channel 4 base address                    */
#define DMA2_Channel5_BASE           (AHBPERIPH_BASE + 0x00000458U)  /*!< DMA2 Channel 5 base address                    */
#define DMA2_Channel6_BASE           (AHBPERIPH_BASE + 0x0000046CU)  /*!< DMA2 Channel 6 base address                    */
#define DMA2_Channel7_BASE           (AHBPERIPH_BASE + 0x00000480U)  /*!< DMA2 Channel 7 base address                    */
#define CRM_BASE                     (AHBPERIPH_BASE + 0x00001000U)  /*!< CRM base address                               */
#define CRC_BASE                     (AHBPERIPH_BASE + 0x00003000U)  /*!< CRC base address                               */

#define FLASH_R_BASE                 (AHBPERIPH_BASE + 0x00002000U)  /*!< FLASH registers base address                   */
#define FLASHSIZE_BASE               0x1FFFF7E0U                     /*!< FLASH Size register base address               */
#define UID_BASE                     0x1FFFF7E8U                     /*!< Unique device ID register base address         */
#define USD_BASE                     0x1FFFF800U                     /*!< FLASH User System Data base address            */

#define DEBUG_BASE                   0xE0042000U                     /*!< Debug MCU registers base address               */

/* USB OTG device FS */
#define USB_OTG_FS_PERIPH_BASE       0x50000000U                     /*!< USB OTG Peripheral Registers base address      */

#define USB_OTG_GLOBAL_BASE          0x00000000U                     /*!< USB OTG Global Registers base address          */
#define USB_OTG_DEVICE_BASE          0x00000800U                     /*!< USB OTG Device ModeRegisters base address      */
#define USB_OTG_IN_ENDPOINT_BASE     0x00000900U                     /*!< USB OTG IN Endpoint Registers base address     */
#define USB_OTG_OUT_ENDPOINT_BASE    0x00000B00U                     /*!< USB OTG OUT Endpoint Registers base address    */
#define USB_OTG_EP_REG_SIZE          0x00000020U                     /*!< USB OTG All Endpoint Registers size address    */
#define USB_OTG_HOST_BASE            0x00000400U                     /*!< USB OTG Host Mode Registers base address       */
#define USB_OTG_HOST_PORT_BASE       0x00000440U                     /*!< USB OTG Host Port Registers base address       */
#define USB_OTG_HOST_CHANNEL_BASE    0x00000500U                     /*!< USB OTG Host Channel Registers base address    */
#define USB_OTG_HOST_CHANNEL_SIZE    0x00000020U                     /*!< USB OTG Host Channel Registers size address    */
#define USB_OTG_DEP3RMPEN_BASE       0x00000D0CU                     /*!< USB OTG DEP3RMPEN Registers base address       */
#define USB_OTG_PCGCCTL_BASE         0x00000E00U                     /*!< USB OTG Power and Ctrl Registers base address  */
#define USB_OTG_USBDIVRST_BASE       0x00000E10U                     /*!< USB OTG USBDIVRST Registers base address       */
#define USB_OTG_FIFO_BASE            0x00001000U                     /*!< USB OTG FIFO Registers base address            */
#define USB_OTG_FIFO_SIZE            0x00001000U                     /*!< USB OTG FIFO Registers size address            */

/**
  * @}
  */

/** @addtogroup Peripheral_declaration
  * @{
  */

#define ADC1                ((ADC_TypeDef *)ADC1_BASE)
#define CAN1                ((CAN_TypeDef *)CAN1_BASE)
#define CMP                 ((CMP_TypeDef *)CMP_BASE)
#define CRC                 ((CRC_TypeDef *)CRC_BASE)
#define CRM                 ((CRM_TypeDef *)CRM_BASE)
#define DEBUG               ((DEBUG_TypeDef *)DEBUG_BASE)
#define DMA1                ((DMA_TypeDef *)DMA1_BASE)
#define DMA1_Channel1       ((DMA_Channel_TypeDef *)DMA1_Channel1_BASE)
#define DMA1_Channel2       ((DMA_Channel_TypeDef *)DMA1_Channel2_BASE)
#define DMA1_Channel3       ((DMA_Channel_TypeDef *)DMA1_Channel3_BASE)
#define DMA1_Channel4       ((DMA_Channel_TypeDef *)DMA1_Channel4_BASE)
#define DMA1_Channel5       ((DMA_Channel_TypeDef *)DMA1_Channel5_BASE)
#define DMA1_Channel6       ((DMA_Channel_TypeDef *)DMA1_Channel6_BASE)
#define DMA1_Channel7       ((DMA_Channel_TypeDef *)DMA1_Channel7_BASE)
#define DMA2                ((DMA_TypeDef *)DMA2_BASE)
#define DMA2_Channel1       ((DMA_Channel_TypeDef *)DMA2_Channel1_BASE)
#define DMA2_Channel2       ((DMA_Channel_TypeDef *)DMA2_Channel2_BASE)
#define DMA2_Channel3       ((DMA_Channel_TypeDef *)DMA2_Channel3_BASE)
#define DMA2_Channel4       ((DMA_Channel_TypeDef *)DMA2_Channel4_BASE)
#define DMA2_Channel5       ((DMA_Channel_TypeDef *)DMA2_Channel5_BASE)
#define DMA2_Channel6       ((DMA_Channel_TypeDef *)DMA2_Channel6_BASE)
#define DMA2_Channel7       ((DMA_Channel_TypeDef *)DMA2_Channel7_BASE)
#define ERTC                ((ERTC_TypeDef *)ERTC_BASE)
#define EXINT               ((EXINT_TypeDef *)EXINT_BASE)
#define FLASH               ((FLASH_TypeDef *)FLASH_R_BASE)
#define USD                 ((USD_TypeDef *)USD_BASE)
#define GPIOA               ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOF               ((GPIO_TypeDef *)GPIOF_BASE)
#define IOMUX               ((IOMUX_TypeDef *)IOMUX_BASE)
#define I2C1                ((I2C_TypeDef *)I2C1_BASE)
#define I2C2                ((I2C_TypeDef *)I2C2_BASE)
#define PWC                 ((PWC_TypeDef *)PWC_BASE)
#define SDIO                ((SDIO_TypeDef *)SDIO_BASE)
#define SPI1                ((SPI_TypeDef *)SPI1_BASE)
#define SPI2                ((SPI_TypeDef *)SPI2_BASE)
#define TMR1                ((TMR_TypeDef *)TMR1_BASE)
#define TMR2                ((TMR_TypeDef *)TMR2_BASE)
#define TMR3                ((TMR_TypeDef *)TMR3_BASE)
#define TMR4                ((TMR_TypeDef *)TMR4_BASE)
#define TMR5                ((TMR_TypeDef *)TMR5_BASE)
#define TMR9                ((TMR_TypeDef *)TMR9_BASE)
#define TMR10               ((TMR_TypeDef *)TMR10_BASE)
#define TMR11               ((TMR_TypeDef *)TMR11_BASE)
#define USART1              ((USART_TypeDef *)USART1_BASE)
#define USART2              ((USART_TypeDef *)USART2_BASE)
#define USART3              ((USART_TypeDef *)USART3_BASE)
#define WDT                 ((WDT_TypeDef *)WDT_BASE)
#define WWDT                ((WWDT_TypeDef *)WWDT_BASE)

/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */

  /** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */

/******************************************************************************/
/*                    Peripheral registers bits definition                    */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                             Power Control (PWC)                            */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for PWC_CTRL register  *******************/
#define PWC_CTRL_VRSEL_Pos                  (0U)
#define PWC_CTRL_VRSEL_Msk                  (0x1U << PWC_CTRL_VRSEL_Pos)            /*!< 0x00000001 */
#define PWC_CTRL_VRSEL                      PWC_CTRL_VRSEL_Msk                      /*!< LDO state select in deep sleep mode */
#define PWC_CTRL_LPSEL_Pos                  (1U)
#define PWC_CTRL_LPSEL_Msk                  (0x1U << PWC_CTRL_LPSEL_Pos)            /*!< 0x00000002 */
#define PWC_CTRL_LPSEL                      PWC_CTRL_LPSEL_Msk                      /*!< Low power mode select in deep sleep */
#define PWC_CTRL_CLSWEF_Pos                 (2U)
#define PWC_CTRL_CLSWEF_Msk                 (0x1U << PWC_CTRL_CLSWEF_Pos)           /*!< 0x00000004 */
#define PWC_CTRL_CLSWEF                     PWC_CTRL_CLSWEF_Msk                     /*!< Clear SWEF flag */
#define PWC_CTRL_CLSEF_Pos                  (3U)
#define PWC_CTRL_CLSEF_Msk                  (0x1U << PWC_CTRL_CLSEF_Pos)            /*!< 0x00000008 */
#define PWC_CTRL_CLSEF                      PWC_CTRL_CLSEF_Msk                      /*!< Clear SEF flag */
#define PWC_CTRL_PVMEN_Pos                  (4U)
#define PWC_CTRL_PVMEN_Msk                  (0x1U << PWC_CTRL_PVMEN_Pos)            /*!< 0x00000010 */
#define PWC_CTRL_PVMEN                      PWC_CTRL_PVMEN_Msk                      /*!< Power voltage monitoring enable */

/*!< PVM level configuration */
#define PWC_CTRL_PVMSEL_Pos                 (5U)
#define PWC_CTRL_PVMSEL_Msk                 (0x7U << PWC_CTRL_PVMSEL_Pos)           /*!< 0x000000E0 */
#define PWC_CTRL_PVMSEL                     PWC_CTRL_PVMSEL_Msk                     /*!< PVMSEL[2:0] bits (Power voltage monitoring boundary select) */
#define PWC_CTRL_PVMSEL_0                   (0x1U << PWC_CTRL_PVMSEL_Pos)           /*!< 0x00000020 */
#define PWC_CTRL_PVMSEL_1                   (0x2U << PWC_CTRL_PVMSEL_Pos)           /*!< 0x00000040 */
#define PWC_CTRL_PVMSEL_2                   (0x4U << PWC_CTRL_PVMSEL_Pos)           /*!< 0x00000080 */

#define PWC_CTRL_PVMSEL_LEV1                0x00000020U                             /*!< PVM level 2.3V */
#define PWC_CTRL_PVMSEL_LEV2                0x00000040U                             /*!< PVM level 2.4V */
#define PWC_CTRL_PVMSEL_LEV3                0x00000060U                             /*!< PVM level 2.5V */
#define PWC_CTRL_PVMSEL_LEV4                0x00000080U                             /*!< PVM level 2.6V */
#define PWC_CTRL_PVMSEL_LEV5                0x000000A0U                             /*!< PVM level 2.7V */
#define PWC_CTRL_PVMSEL_LEV6                0x000000C0U                             /*!< PVM level 2.8V */
#define PWC_CTRL_PVMSEL_LEV7                0x000000E0U                             /*!< PVM level 2.9V */

/* Legacy defines */
#define PWC_CTRL_PVMSEL_2V3                 PWC_CTRL_PVMSEL_LEV1
#define PWC_CTRL_PVMSEL_2V4                 PWC_CTRL_PVMSEL_LEV2
#define PWC_CTRL_PVMSEL_2V5                 PWC_CTRL_PVMSEL_LEV3
#define PWC_CTRL_PVMSEL_2V6                 PWC_CTRL_PVMSEL_LEV4
#define PWC_CTRL_PVMSEL_2V7                 PWC_CTRL_PVMSEL_LEV5
#define PWC_CTRL_PVMSEL_2V8                 PWC_CTRL_PVMSEL_LEV6
#define PWC_CTRL_PVMSEL_2V9                 PWC_CTRL_PVMSEL_LEV7

#define PWC_CTRL_BPWEN_Pos                  (8U)
#define PWC_CTRL_BPWEN_Msk                  (0x1U << PWC_CTRL_BPWEN_Pos)            /*!< 0x00000100 */
#define PWC_CTRL_BPWEN                      PWC_CTRL_BPWEN_Msk                      /*!< Battery powered domain write enable */

/*****************  Bit definition for PWC_CTRLSTS register  ******************/
#define PWC_CTRLSTS_SWEF_Pos                (0U)
#define PWC_CTRLSTS_SWEF_Msk                (0x1U << PWC_CTRLSTS_SWEF_Pos)          /*!< 0x00000001 */
#define PWC_CTRLSTS_SWEF                    PWC_CTRLSTS_SWEF_Msk                    /*!< Standby wake-up event flag */
#define PWC_CTRLSTS_SEF_Pos                 (1U)
#define PWC_CTRLSTS_SEF_Msk                 (0x1U << PWC_CTRLSTS_SEF_Pos)           /*!< 0x00000002 */
#define PWC_CTRLSTS_SEF                     PWC_CTRLSTS_SEF_Msk                     /*!< Standby mode entry flag */
#define PWC_CTRLSTS_PVMOF_Pos               (2U)
#define PWC_CTRLSTS_PVMOF_Msk               (0x1U << PWC_CTRLSTS_PVMOF_Pos)         /*!< 0x00000004 */
#define PWC_CTRLSTS_PVMOF                   PWC_CTRLSTS_PVMOF_Msk                   /*!< Power voltage monitoring output flag */
#define PWC_CTRLSTS_SWPEN_Pos               (8U)
#define PWC_CTRLSTS_SWPEN_Msk               (0x1U << PWC_CTRLSTS_SWPEN_Pos)         /*!< 0x00000100 */
#define PWC_CTRLSTS_SWPEN                   PWC_CTRLSTS_SWPEN_Msk                   /*!< Standby wake-up pin enable */

/******************************************************************************/
/*                                                                            */
/*                        Clock and reset manage (CRM)                        */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for CRM_CTRL register  *******************/
#define CRM_CTRL_HICKEN_Pos                 (0U)
#define CRM_CTRL_HICKEN_Msk                 (0x1U << CRM_CTRL_HICKEN_Pos)           /*!< 0x00000001 */
#define CRM_CTRL_HICKEN                     CRM_CTRL_HICKEN_Msk                     /*!< High speed internal clock enable */
#define CRM_CTRL_HICKSTBL_Pos               (1U)
#define CRM_CTRL_HICKSTBL_Msk               (0x1U << CRM_CTRL_HICKSTBL_Pos)         /*!< 0x00000002 */
#define CRM_CTRL_HICKSTBL                   CRM_CTRL_HICKSTBL_Msk                   /*!< High speed internal clock stable */
#define CRM_CTRL_HICKTRIM_Pos               (2U)
#define CRM_CTRL_HICKTRIM_Msk               (0x3FU << CRM_CTRL_HICKTRIM_Pos)        /*!< 0x000000FC */
#define CRM_CTRL_HICKTRIM                   CRM_CTRL_HICKTRIM_Msk                   /*!< High speed internal clock trimming */
#define CRM_CTRL_HICKCAL_Pos                (8U)
#define CRM_CTRL_HICKCAL_Msk                (0xFFU << CRM_CTRL_HICKCAL_Pos)         /*!< 0x0000FF00 */
#define CRM_CTRL_HICKCAL                    CRM_CTRL_HICKCAL_Msk                    /*!< High speed internal clock calibration */
#define CRM_CTRL_HEXTEN_Pos                 (16U)
#define CRM_CTRL_HEXTEN_Msk                 (0x1U << CRM_CTRL_HEXTEN_Pos)           /*!< 0x00010000 */
#define CRM_CTRL_HEXTEN                     CRM_CTRL_HEXTEN_Msk                     /*!< High speed external crystal enable */
#define CRM_CTRL_HEXTSTBL_Pos               (17U)
#define CRM_CTRL_HEXTSTBL_Msk               (0x1U << CRM_CTRL_HEXTSTBL_Pos)         /*!< 0x00020000 */
#define CRM_CTRL_HEXTSTBL                   CRM_CTRL_HEXTSTBL_Msk                   /*!< High speed external crystal stable */
#define CRM_CTRL_HEXTBYPS_Pos               (18U)
#define CRM_CTRL_HEXTBYPS_Msk               (0x1U << CRM_CTRL_HEXTBYPS_Pos)         /*!< 0x00040000 */
#define CRM_CTRL_HEXTBYPS                   CRM_CTRL_HEXTBYPS_Msk                   /*!< High speed external crystal bypass */
#define CRM_CTRL_CFDEN_Pos                  (19U)
#define CRM_CTRL_CFDEN_Msk                  (0x1U << CRM_CTRL_CFDEN_Pos)            /*!< 0x00080000 */
#define CRM_CTRL_CFDEN                      CRM_CTRL_CFDEN_Msk                      /*!< Clock failure detector enable */
#define CRM_CTRL_PLLEN_Pos                  (24U)
#define CRM_CTRL_PLLEN_Msk                  (0x1U << CRM_CTRL_PLLEN_Pos)            /*!< 0x01000000 */
#define CRM_CTRL_PLLEN                      CRM_CTRL_PLLEN_Msk                      /*!< PLL enable */
#define CRM_CTRL_PLLSTBL_Pos                (25U)
#define CRM_CTRL_PLLSTBL_Msk                (0x1U << CRM_CTRL_PLLSTBL_Pos)          /*!< 0x02000000 */
#define CRM_CTRL_PLLSTBL                    CRM_CTRL_PLLSTBL_Msk                    /*!< PLL clock stable */

/*******************  Bit definition for CRM_CFG register  ********************/
/*!< SCLKSEL configuration */
#define CRM_CFG_SCLKSEL_Pos                 (0U)
#define CRM_CFG_SCLKSEL_Msk                 (0x3U << CRM_CFG_SCLKSEL_Pos)           /*!< 0x00000003 */
#define CRM_CFG_SCLKSEL                     CRM_CFG_SCLKSEL_Msk                     /*!< SCLKSEL[1:0] bits (System clock select) */
#define CRM_CFG_SCLKSEL_0                   (0x1U << CRM_CFG_SCLKSEL_Pos)           /*!< 0x00000001 */
#define CRM_CFG_SCLKSEL_1                   (0x2U << CRM_CFG_SCLKSEL_Pos)           /*!< 0x00000002 */

#define CRM_CFG_SCLKSEL_HICK                0x00000000U                             /*!< HICK */
#define CRM_CFG_SCLKSEL_HEXT                0x00000001U                             /*!< HEXT */
#define CRM_CFG_SCLKSEL_PLL                 0x00000002U                             /*!< PLL */

/*!< SCLKSTS configuration */
#define CRM_CFG_SCLKSTS_Pos                 (2U)
#define CRM_CFG_SCLKSTS_Msk                 (0x3U << CRM_CFG_SCLKSTS_Pos)           /*!< 0x0000000C */
#define CRM_CFG_SCLKSTS                     CRM_CFG_SCLKSTS_Msk                     /*!< SCLKSTS[1:0] bits (System clock select status) */
#define CRM_CFG_SCLKSTS_0                   (0x1U << CRM_CFG_SCLKSTS_Pos)           /*!< 0x00000004 */
#define CRM_CFG_SCLKSTS_1                   (0x2U << CRM_CFG_SCLKSTS_Pos)           /*!< 0x00000008 */

#define CRM_CFG_SCLKSTS_HICK                0x00000000U                             /*!< HICK */
#define CRM_CFG_SCLKSTS_HEXT                0x00000004U                             /*!< HEXT */
#define CRM_CFG_SCLKSTS_PLL                 0x00000008U                             /*!< PLL */

/*!< AHBDIV configuration */
#define CRM_CFG_AHBDIV_Pos                  (4U)
#define CRM_CFG_AHBDIV_Msk                  (0xFU << CRM_CFG_AHBDIV_Pos)            /*!< 0x000000F0 */
#define CRM_CFG_AHBDIV                      CRM_CFG_AHBDIV_Msk                      /*!< AHBDIV[3:0] bits (AHB division) */
#define CRM_CFG_AHBDIV_0                    (0x1U << CRM_CFG_AHBDIV_Pos)            /*!< 0x00000010 */
#define CRM_CFG_AHBDIV_1                    (0x2U << CRM_CFG_AHBDIV_Pos)            /*!< 0x00000020 */
#define CRM_CFG_AHBDIV_2                    (0x4U << CRM_CFG_AHBDIV_Pos)            /*!< 0x00000040 */
#define CRM_CFG_AHBDIV_3                    (0x8U << CRM_CFG_AHBDIV_Pos)            /*!< 0x00000080 */

#define CRM_CFG_AHBDIV_DIV1                 0x00000000U                             /*!< SCLK is not divided */
#define CRM_CFG_AHBDIV_DIV2                 0x00000080U                             /*!< SCLK is divided by 2 */
#define CRM_CFG_AHBDIV_DIV4                 0x00000090U                             /*!< SCLK is divided by 4 */
#define CRM_CFG_AHBDIV_DIV8                 0x000000A0U                             /*!< SCLK is divided by 8 */
#define CRM_CFG_AHBDIV_DIV16                0x000000B0U                             /*!< SCLK is divided by 16 */
#define CRM_CFG_AHBDIV_DIV64                0x000000C0U                             /*!< SCLK is divided by 64 */
#define CRM_CFG_AHBDIV_DIV128               0x000000D0U                             /*!< SCLK is divided by 128 */
#define CRM_CFG_AHBDIV_DIV256               0x000000E0U                             /*!< SCLK is divided by 256 */
#define CRM_CFG_AHBDIV_DIV512               0x000000F0U                             /*!< SCLK is divided by 512 */

/*!< APB1DIV configuration */
#define CRM_CFG_APB1DIV_Pos                 (8U)
#define CRM_CFG_APB1DIV_Msk                 (0x7U << CRM_CFG_APB1DIV_Pos)           /*!< 0x00000700 */
#define CRM_CFG_APB1DIV                     CRM_CFG_APB1DIV_Msk                     /*!< APB1DIV[2:0] bits (APB1 division) */
#define CRM_CFG_APB1DIV_0                   (0x1U << CRM_CFG_APB1DIV_Pos)           /*!< 0x00000100 */
#define CRM_CFG_APB1DIV_1                   (0x2U << CRM_CFG_APB1DIV_Pos)           /*!< 0x00000200 */
#define CRM_CFG_APB1DIV_2                   (0x4U << CRM_CFG_APB1DIV_Pos)           /*!< 0x00000400 */

#define CRM_CFG_APB1DIV_DIV1                0x00000000U                             /*!< HCLK is not divided */
#define CRM_CFG_APB1DIV_DIV2                0x00000400U                             /*!< HCLK is divided by 2 */
#define CRM_CFG_APB1DIV_DIV4                0x00000500U                             /*!< HCLK is divided by 4 */
#define CRM_CFG_APB1DIV_DIV8                0x00000600U                             /*!< HCLK is divided by 8 */
#define CRM_CFG_APB1DIV_DIV16               0x00000700U                             /*!< HCLK is divided by 16 */

/*!< APB2DIV configuration */
#define CRM_CFG_APB2DIV_Pos                 (11U)
#define CRM_CFG_APB2DIV_Msk                 (0x7U << CRM_CFG_APB2DIV_Pos)           /*!< 0x00003800 */
#define CRM_CFG_APB2DIV                     CRM_CFG_APB2DIV_Msk                     /*!< APB2DIV[2:0] bits (APB2 division) */
#define CRM_CFG_APB2DIV_0                   (0x1U << CRM_CFG_APB2DIV_Pos)           /*!< 0x00000800 */
#define CRM_CFG_APB2DIV_1                   (0x2U << CRM_CFG_APB2DIV_Pos)           /*!< 0x00001000 */
#define CRM_CFG_APB2DIV_2                   (0x4U << CRM_CFG_APB2DIV_Pos)           /*!< 0x00002000 */

#define CRM_CFG_APB2DIV_DIV1                0x00000000U                             /*!< HCLK is not divided */
#define CRM_CFG_APB2DIV_DIV2                0x00002000U                             /*!< HCLK is divided by 2 */
#define CRM_CFG_APB2DIV_DIV4                0x00002800U                             /*!< HCLK is divided by 4 */
#define CRM_CFG_APB2DIV_DIV8                0x00003000U                             /*!< HCLK is divided by 8 */
#define CRM_CFG_APB2DIV_DIV16               0x00003800U                             /*!< HCLK is divided by 16 */

/*!< ADCDIV configuration */
#define CRM_CFG_ADCDIV_Msk                  ((0x3U << 14) | (0x1U << 28))           /*!< 0x0100C000 */
#define CRM_CFG_ADCDIV                      CRM_CFG_ADCDIV_Msk                      /*!< ADCDIV[2:0] bits (ADC division) */
#define CRM_CFG_ADCDIV_0                    (0x1U << 14)                            /*!< 0x00004000 */
#define CRM_CFG_ADCDIV_1                    (0x2U << 14)                            /*!< 0x00008000 */
#define CRM_CFG_ADCDIV_2                    (0x1U << 28)                            /*!< 0x10000000 */

#define CRM_CFG_ADCDIV_DIV2                 0x00000000U                             /*!< PCLK/2 */
#define CRM_CFG_ADCDIV_DIV4                 0x00004000U                             /*!< PCLK/4 */
#define CRM_CFG_ADCDIV_DIV6                 0x00008000U                             /*!< PCLK/6 */
#define CRM_CFG_ADCDIV_DIV8                 0x0000C000U                             /*!< PCLK/8 */
#define CRM_CFG_ADCDIV_DIV12                0x10004000U                             /*!< PCLK2/12 */
#define CRM_CFG_ADCDIV_DIV16                0x1000C000U                             /*!< PCLK2/16 */

#define CRM_CFG_PLLRCS_Pos                  (16U)
#define CRM_CFG_PLLRCS_Msk                  (0x1U << CRM_CFG_PLLRCS_Pos)            /*!< 0x00010000 */
#define CRM_CFG_PLLRCS                      CRM_CFG_PLLRCS_Msk                      /*!< PLL entry clock select */

#define CRM_CFG_PLLHEXTDIV_Pos              (17U)
#define CRM_CFG_PLLHEXTDIV_Msk              (0x1U << CRM_CFG_PLLHEXTDIV_Pos)        /*!< 0x00020000 */
#define CRM_CFG_PLLHEXTDIV                  CRM_CFG_PLLHEXTDIV_Msk                  /*!< HEXT division selection for PLL entry clock */

/*!< PLLMULT configuration */
#define CRM_CFG_PLLMULT_Msk                 ((0xFU << 18) | (0x3U << 29))           /*!< 0x603C0000 */
#define CRM_CFG_PLLMULT                     CRM_CFG_PLLMULT_Msk                     /*!< PLLMULT[5:0] bits (PLL multiplication factor) */
#define CRM_CFG_PLLMULT_0                   (0x1U << 18)                            /*!< 0x00040000 */
#define CRM_CFG_PLLMULT_1                   (0x2U << 18)                            /*!< 0x00080000 */
#define CRM_CFG_PLLMULT_2                   (0x4U << 18)                            /*!< 0x00100000 */
#define CRM_CFG_PLLMULT_3                   (0x8U << 18)                            /*!< 0x00200000 */
#define CRM_CFG_PLLMULT_4                   (0x1U << 29)                            /*!< 0x20000000 */
#define CRM_CFG_PLLMULT_5                   (0x2U << 29)                            /*!< 0x40000000 */

#define CRM_CFG_PLLMULT_MULT2               0x00000000U                             /*!< PLL input clock * 2 */
#define CRM_CFG_PLLMULT_MULT3_Pos           (18U)
#define CRM_CFG_PLLMULT_MULT3_Msk           (0x1U << CRM_CFG_PLLMULT_MULT3_Pos)     /*!< 0x00040000 */
#define CRM_CFG_PLLMULT_MULT3               CRM_CFG_PLLMULT_MULT3_Msk               /*!< PLL input clock * 3 */
#define CRM_CFG_PLLMULT_MULT4_Pos           (19U)
#define CRM_CFG_PLLMULT_MULT4_Msk           (0x1U << CRM_CFG_PLLMULT_MULT4_Pos)     /*!< 0x00080000 */
#define CRM_CFG_PLLMULT_MULT4               CRM_CFG_PLLMULT_MULT4_Msk               /*!< PLL input clock * 4 */
#define CRM_CFG_PLLMULT_MULT5_Pos           (18U)
#define CRM_CFG_PLLMULT_MULT5_Msk           (0x3U << CRM_CFG_PLLMULT_MULT5_Pos)     /*!< 0x000C0000 */
#define CRM_CFG_PLLMULT_MULT5               CRM_CFG_PLLMULT_MULT5_Msk               /*!< PLL input clock * 5 */
#define CRM_CFG_PLLMULT_MULT6_Pos           (20U)
#define CRM_CFG_PLLMULT_MULT6_Msk           (0x1U << CRM_CFG_PLLMULT_MULT6_Pos)     /*!< 0x00100000 */
#define CRM_CFG_PLLMULT_MULT6               CRM_CFG_PLLMULT_MULT6_Msk               /*!< PLL input clock * 6 */
#define CRM_CFG_PLLMULT_MULT7_Pos           (18U)
#define CRM_CFG_PLLMULT_MULT7_Msk           (0x5U << CRM_CFG_PLLMULT_MULT7_Pos)     /*!< 0x00140000 */
#define CRM_CFG_PLLMULT_MULT7               CRM_CFG_PLLMULT_MULT7_Msk               /*!< PLL input clock * 7 */
#define CRM_CFG_PLLMULT_MULT8_Pos           (19U)
#define CRM_CFG_PLLMULT_MULT8_Msk           (0x3U << CRM_CFG_PLLMULT_MULT8_Pos)     /*!< 0x00180000 */
#define CRM_CFG_PLLMULT_MULT8               CRM_CFG_PLLMULT_MULT8_Msk               /*!< PLL input clock * 8 */
#define CRM_CFG_PLLMULT_MULT9_Pos           (18U)
#define CRM_CFG_PLLMULT_MULT9_Msk           (0x7U << CRM_CFG_PLLMULT_MULT9_Pos)     /*!< 0x001C0000 */
#define CRM_CFG_PLLMULT_MULT9               CRM_CFG_PLLMULT_MULT9_Msk               /*!< PLL input clock * 9 */
#define CRM_CFG_PLLMULT_MULT10_Pos          (21U)
#define CRM_CFG_PLLMULT_MULT10_Msk          (0x1U << CRM_CFG_PLLMULT_MULT10_Pos)    /*!< 0x00200000 */
#define CRM_CFG_PLLMULT_MULT10              CRM_CFG_PLLMULT_MULT10_Msk              /*!< PLL input clock * 10 */
#define CRM_CFG_PLLMULT_MULT11_Pos          (18U)
#define CRM_CFG_PLLMULT_MULT11_Msk          (0x9U << CRM_CFG_PLLMULT_MULT11_Pos)    /*!< 0x00240000 */
#define CRM_CFG_PLLMULT_MULT11              CRM_CFG_PLLMULT_MULT11_Msk              /*!< PLL input clock * 11 */
#define CRM_CFG_PLLMULT_MULT12_Pos          (19U)
#define CRM_CFG_PLLMULT_MULT12_Msk          (0x5U << CRM_CFG_PLLMULT_MULT12_Pos)    /*!< 0x00280000 */
#define CRM_CFG_PLLMULT_MULT12              CRM_CFG_PLLMULT_MULT12_Msk              /*!< PLL input clock * 12 */
#define CRM_CFG_PLLMULT_MULT13_Pos          (18U)
#define CRM_CFG_PLLMULT_MULT13_Msk          (0xBU << CRM_CFG_PLLMULT_MULT13_Pos)    /*!< 0x002C0000 */
#define CRM_CFG_PLLMULT_MULT13              CRM_CFG_PLLMULT_MULT13_Msk              /*!< PLL input clock * 13 */
#define CRM_CFG_PLLMULT_MULT14_Pos          (20U)
#define CRM_CFG_PLLMULT_MULT14_Msk          (0x3U << CRM_CFG_PLLMULT_MULT14_Pos)    /*!< 0x00300000 */
#define CRM_CFG_PLLMULT_MULT14              CRM_CFG_PLLMULT_MULT14_Msk              /*!< PLL input clock * 14 */
#define CRM_CFG_PLLMULT_MULT15_Pos          (18U)
#define CRM_CFG_PLLMULT_MULT15_Msk          (0xDU << CRM_CFG_PLLMULT_MULT15_Pos)    /*!< 0x00340000 */
#define CRM_CFG_PLLMULT_MULT15              CRM_CFG_PLLMULT_MULT15_Msk              /*!< PLL input clock * 15 */
#define CRM_CFG_PLLMULT_MULT16_Pos          (19U)
#define CRM_CFG_PLLMULT_MULT16_Msk          (0x7U << CRM_CFG_PLLMULT_MULT16_Pos)    /*!< 0x00380000 */
#define CRM_CFG_PLLMULT_MULT16              CRM_CFG_PLLMULT_MULT16_Msk              /*!< PLL input clock * 16 */
#define CRM_CFG_PLLMULT_MULT17              0x20000000U                             /*!< PLL input clock * 17 */
#define CRM_CFG_PLLMULT_MULT18              0x20040000U                             /*!< PLL input clock * 18 */
#define CRM_CFG_PLLMULT_MULT19              0x20080000U                             /*!< PLL input clock * 19 */
#define CRM_CFG_PLLMULT_MULT20              0x200C0000U                             /*!< PLL input clock * 20 */
#define CRM_CFG_PLLMULT_MULT21              0x20100000U                             /*!< PLL input clock * 21 */
#define CRM_CFG_PLLMULT_MULT22              0x20140000U                             /*!< PLL input clock * 22 */
#define CRM_CFG_PLLMULT_MULT23              0x20180000U                             /*!< PLL input clock * 23 */
#define CRM_CFG_PLLMULT_MULT24              0x201C0000U                             /*!< PLL input clock * 24 */
#define CRM_CFG_PLLMULT_MULT25              0x20200000U                             /*!< PLL input clock * 25 */
#define CRM_CFG_PLLMULT_MULT26              0x20240000U                             /*!< PLL input clock * 26 */
#define CRM_CFG_PLLMULT_MULT27              0x20280000U                             /*!< PLL input clock * 27 */
#define CRM_CFG_PLLMULT_MULT28              0x202C0000U                             /*!< PLL input clock * 28 */
#define CRM_CFG_PLLMULT_MULT29              0x20300000U                             /*!< PLL input clock * 29 */
#define CRM_CFG_PLLMULT_MULT30              0x20340000U                             /*!< PLL input clock * 30 */
#define CRM_CFG_PLLMULT_MULT31              0x20380000U                             /*!< PLL input clock * 31 */
#define CRM_CFG_PLLMULT_MULT32              0x203C0000U                             /*!< PLL input clock * 32 */
#define CRM_CFG_PLLMULT_MULT33              0x40000000U                             /*!< PLL input clock * 33 */
#define CRM_CFG_PLLMULT_MULT34              0x40040000U                             /*!< PLL input clock * 34 */
#define CRM_CFG_PLLMULT_MULT35              0x40080000U                             /*!< PLL input clock * 35 */
#define CRM_CFG_PLLMULT_MULT36              0x400C0000U                             /*!< PLL input clock * 36 */
#define CRM_CFG_PLLMULT_MULT37              0x40100000U                             /*!< PLL input clock * 37 */
#define CRM_CFG_PLLMULT_MULT38              0x40140000U                             /*!< PLL input clock * 38 */
#define CRM_CFG_PLLMULT_MULT39              0x40180000U                             /*!< PLL input clock * 39 */
#define CRM_CFG_PLLMULT_MULT40              0x401C0000U                             /*!< PLL input clock * 40 */
#define CRM_CFG_PLLMULT_MULT41              0x40200000U                             /*!< PLL input clock * 41 */
#define CRM_CFG_PLLMULT_MULT42              0x40240000U                             /*!< PLL input clock * 42 */
#define CRM_CFG_PLLMULT_MULT43              0x40280000U                             /*!< PLL input clock * 43 */
#define CRM_CFG_PLLMULT_MULT44              0x402C0000U                             /*!< PLL input clock * 44 */
#define CRM_CFG_PLLMULT_MULT45              0x40300000U                             /*!< PLL input clock * 45 */
#define CRM_CFG_PLLMULT_MULT46              0x40340000U                             /*!< PLL input clock * 46 */
#define CRM_CFG_PLLMULT_MULT47              0x40380000U                             /*!< PLL input clock * 47 */
#define CRM_CFG_PLLMULT_MULT48              0x403C0000U                             /*!< PLL input clock * 48 */
#define CRM_CFG_PLLMULT_MULT49              0x60000000U                             /*!< PLL input clock * 49 */
#define CRM_CFG_PLLMULT_MULT50              0x60040000U                             /*!< PLL input clock * 50 */
#define CRM_CFG_PLLMULT_MULT51              0x60080000U                             /*!< PLL input clock * 51 */
#define CRM_CFG_PLLMULT_MULT52              0x600C0000U                             /*!< PLL input clock * 52 */
#define CRM_CFG_PLLMULT_MULT53              0x60100000U                             /*!< PLL input clock * 53 */
#define CRM_CFG_PLLMULT_MULT54              0x60140000U                             /*!< PLL input clock * 54 */
#define CRM_CFG_PLLMULT_MULT55              0x60180000U                             /*!< PLL input clock * 55 */
#define CRM_CFG_PLLMULT_MULT56              0x601C0000U                             /*!< PLL input clock * 56 */
#define CRM_CFG_PLLMULT_MULT57              0x60200000U                             /*!< PLL input clock * 57 */
#define CRM_CFG_PLLMULT_MULT58              0x60240000U                             /*!< PLL input clock * 58 */
#define CRM_CFG_PLLMULT_MULT59              0x60280000U                             /*!< PLL input clock * 59 */
#define CRM_CFG_PLLMULT_MULT60              0x602C0000U                             /*!< PLL input clock * 60 */
#define CRM_CFG_PLLMULT_MULT61              0x60300000U                             /*!< PLL input clock * 61 */
#define CRM_CFG_PLLMULT_MULT62              0x60340000U                             /*!< PLL input clock * 62 */
#define CRM_CFG_PLLMULT_MULT63              0x60380000U                             /*!< PLL input clock * 63 */
#define CRM_CFG_PLLMULT_MULT64              0x603C0000U                             /*!< PLL input clock * 64 */

/*!< USBDIV configuration */
#define CRM_CFG_USBDIV_Msk                  ((0x3U << 22) | (0x1U << 27))           /*!< 0x08C00000 */
#define CRM_CFG_USBDIV                      CRM_CFG_USBDIV_Msk                      /*!< USBDIV[2:0] bits (USB division factor) */
#define CRM_CFG_USBDIV_0                    (0x1U << 22)                            /*!< 0x00400000 */
#define CRM_CFG_USBDIV_1                    (0x2U << 22)                            /*!< 0x00800000 */
#define CRM_CFG_USBDIV_2                    (0x1U << 27)                            /*!< 0x08000000 */

#define CRM_CFG_USBDIV_DIV1_5               0x00000000U                             /*!< PLL/1.5 */
#define CRM_CFG_USBDIV_DIV1                 0x00400000U                             /*!< PLL/1 */
#define CRM_CFG_USBDIV_DIV2_5               0x00800000U                             /*!< PLL/2.5 */
#define CRM_CFG_USBDIV_DIV2                 0x00C00000U                             /*!< PLL/2 */
#define CRM_CFG_USBDIV_DIV3_5               0x08000000U                             /*!< PLL/3.5 */
#define CRM_CFG_USBDIV_DIV3                 0x08400000U                             /*!< PLL/3 */
#define CRM_CFG_USBDIV_DIV4                 0x08800000U                             /*!< PLL/4 */

/*!< CLKOUT_SEL configuration */
#define CRM_CFG_CLKOUT_SEL_Msk              ((CRM_MISC1_CLKOUT_SEL) | (0x7U << 24)) /*!< 0x07010000 */
#define CRM_CFG_CLKOUT_SEL                  CRM_CFG_CLKOUT_SEL_Msk                  /*!< CLKOUT_SEL[3:0] bits (Clock output selection) */
#define CRM_CFG_CLKOUT_SEL_0                (0x1U << 24)                            /*!< 0x01000000 */
#define CRM_CFG_CLKOUT_SEL_1                (0x2U << 24)                            /*!< 0x02000000 */
#define CRM_CFG_CLKOUT_SEL_2                (0x4U << 24)                            /*!< 0x04000000 */
#define CRM_CFG_CLKOUT_SEL_3                CRM_MISC1_CLKOUT_SEL                    /*!< 0x00010000 */

#define CRM_CFG_CLKOUT_SEL_NOCLOCK          0x00000000U                             /*!< Not clock output */
#define CRM_CFG_CLKOUT_SEL_LICK             0x02000000U                             /*!< LICK */
#define CRM_CFG_CLKOUT_SEL_LEXT             0x03000000U                             /*!< LEXT */
#define CRM_CFG_CLKOUT_SEL_SCLK             0x04000000U                             /*!< SCLK */
#define CRM_CFG_CLKOUT_SEL_HICK             0x05000000U                             /*!< HICK */
#define CRM_CFG_CLKOUT_SEL_HEXT             0x06000000U                             /*!< HEXT */
#define CRM_CFG_CLKOUT_SEL_PLL_DIV2         0x07000000U                             /*!< PLL/2 */
#define CRM_MISC1_CLKOUT_SEL_PLL_DIV4       0x04010000U                             /*!< PLL/4 */
#define CRM_MISC1_CLKOUT_SEL_USB            0x05010000U                             /*!< USB */
#define CRM_MISC1_CLKOUT_SEL_ADC            0x06010000U                             /*!< ADC */

/* Reference defines */
#define CRM_CFG_CLKSEL                      CRM_CFG_CLKOUT_SEL
#define CRM_CFG_CLKSEL_0                    CRM_CFG_CLKOUT_SEL_0
#define CRM_CFG_CLKSEL_1                    CRM_CFG_CLKOUT_SEL_1
#define CRM_CFG_CLKSEL_2                    CRM_CFG_CLKOUT_SEL_2
#define CRM_CFG_CLKSEL_NOCLOCK              CRM_CFG_CLKOUT_SEL_NOCLOCK
#define CRM_CFG_CLKSEL_LICK                 CRM_CFG_CLKOUT_SEL_LICK
#define CRM_CFG_CLKSEL_LEXT                 CRM_CFG_CLKOUT_SEL_LEXT
#define CRM_CFG_CLKSEL_SCLK                 CRM_CFG_CLKOUT_SEL_SCLK
#define CRM_CFG_CLKSEL_HICK                 CRM_CFG_CLKOUT_SEL_HICK
#define CRM_CFG_CLKSEL_HEXT                 CRM_CFG_CLKOUT_SEL_HEXT
#define CRM_CFG_CLKSEL_PLL_DIV2             CRM_CFG_CLKOUT_SEL_PLL_DIV2
#define CRM_MISC1_CLKSEL_PLL_DIV4           CRM_MISC1_CLKOUT_SEL_PLL_DIV4
#define CRM_MISC1_CLKSEL_USB                CRM_MISC1_CLKOUT_SEL_USB
#define CRM_MISC1_CLKSEL_ADC                CRM_MISC1_CLKOUT_SEL_ADC

/*!<***************  Bit definition for CRM_CLKINT register  ******************/
#define CRM_CLKINT_LICKSTBLF_Pos            (0U)
#define CRM_CLKINT_LICKSTBLF_Msk            (0x1U << CRM_CLKINT_LICKSTBLF_Pos)      /*!< 0x00000001 */
#define CRM_CLKINT_LICKSTBLF                CRM_CLKINT_LICKSTBLF_Msk                /*!< LICK stable interrupt flag */
#define CRM_CLKINT_LEXTSTBLF_Pos            (1U)
#define CRM_CLKINT_LEXTSTBLF_Msk            (0x1U << CRM_CLKINT_LEXTSTBLF_Pos)      /*!< 0x00000002 */
#define CRM_CLKINT_LEXTSTBLF                CRM_CLKINT_LEXTSTBLF_Msk                /*!< LEXT stable flag */
#define CRM_CLKINT_HICKSTBLF_Pos            (2U)
#define CRM_CLKINT_HICKSTBLF_Msk            (0x1U << CRM_CLKINT_HICKSTBLF_Pos)      /*!< 0x00000004 */
#define CRM_CLKINT_HICKSTBLF                CRM_CLKINT_HICKSTBLF_Msk                /*!< HICK stable flag */
#define CRM_CLKINT_HEXTSTBLF_Pos            (3U)
#define CRM_CLKINT_HEXTSTBLF_Msk            (0x1U << CRM_CLKINT_HEXTSTBLF_Pos)      /*!< 0x00000008 */
#define CRM_CLKINT_HEXTSTBLF                CRM_CLKINT_HEXTSTBLF_Msk                /*!< HEXT stable flag */
#define CRM_CLKINT_PLLSTBLF_Pos             (4U)
#define CRM_CLKINT_PLLSTBLF_Msk             (0x1U << CRM_CLKINT_PLLSTBLF_Pos)       /*!< 0x00000010 */
#define CRM_CLKINT_PLLSTBLF                 CRM_CLKINT_PLLSTBLF_Msk                 /*!< PLL stable flag */
#define CRM_CLKINT_CFDF_Pos                 (7U)
#define CRM_CLKINT_CFDF_Msk                 (0x1U << CRM_CLKINT_CFDF_Pos)           /*!< 0x00000080 */
#define CRM_CLKINT_CFDF                     CRM_CLKINT_CFDF_Msk                     /*!< Clock Failure Detection flag */
#define CRM_CLKINT_LICKSTBLIEN_Pos          (8U)
#define CRM_CLKINT_LICKSTBLIEN_Msk          (0x1U << CRM_CLKINT_LICKSTBLIEN_Pos)    /*!< 0x00000100 */
#define CRM_CLKINT_LICKSTBLIEN              CRM_CLKINT_LICKSTBLIEN_Msk              /*!< LICK stable interrupt enable */
#define CRM_CLKINT_LEXTSTBLIEN_Pos          (9U)
#define CRM_CLKINT_LEXTSTBLIEN_Msk          (0x1U << CRM_CLKINT_LEXTSTBLIEN_Pos)    /*!< 0x00000200 */
#define CRM_CLKINT_LEXTSTBLIEN              CRM_CLKINT_LEXTSTBLIEN_Msk              /*!< LEXT stable interrupt enable */
#define CRM_CLKINT_HICKSTBLIEN_Pos          (10U)
#define CRM_CLKINT_HICKSTBLIEN_Msk          (0x1U << CRM_CLKINT_HICKSTBLIEN_Pos)    /*!< 0x00000400 */
#define CRM_CLKINT_HICKSTBLIEN              CRM_CLKINT_HICKSTBLIEN_Msk              /*!< HICK stable interrupt enable */
#define CRM_CLKINT_HEXTSTBLIEN_Pos          (11U)
#define CRM_CLKINT_HEXTSTBLIEN_Msk          (0x1U << CRM_CLKINT_HEXTSTBLIEN_Pos)    /*!< 0x00000800 */
#define CRM_CLKINT_HEXTSTBLIEN              CRM_CLKINT_HEXTSTBLIEN_Msk              /*!< HEXT stable interrupt enable */
#define CRM_CLKINT_PLLSTBLIEN_Pos           (12U)
#define CRM_CLKINT_PLLSTBLIEN_Msk           (0x1U << CRM_CLKINT_PLLSTBLIEN_Pos)     /*!< 0x00001000 */
#define CRM_CLKINT_PLLSTBLIEN               CRM_CLKINT_PLLSTBLIEN_Msk               /*!< PLL stable interrupt enable */
#define CRM_CLKINT_LICKSTBLFC_Pos           (16U)
#define CRM_CLKINT_LICKSTBLFC_Msk           (0x1U << CRM_CLKINT_LICKSTBLFC_Pos)     /*!< 0x00010000 */
#define CRM_CLKINT_LICKSTBLFC               CRM_CLKINT_LICKSTBLFC_Msk               /*!< LICK stable flag clear */
#define CRM_CLKINT_LEXTSTBLFC_Pos           (17U)
#define CRM_CLKINT_LEXTSTBLFC_Msk           (0x1U << CRM_CLKINT_LEXTSTBLFC_Pos)     /*!< 0x00020000 */
#define CRM_CLKINT_LEXTSTBLFC               CRM_CLKINT_LEXTSTBLFC_Msk               /*!< LEXT stable flag clear */
#define CRM_CLKINT_HICKSTBLFC_Pos           (18U)
#define CRM_CLKINT_HICKSTBLFC_Msk           (0x1U << CRM_CLKINT_HICKSTBLFC_Pos)     /*!< 0x00040000 */
#define CRM_CLKINT_HICKSTBLFC               CRM_CLKINT_HICKSTBLFC_Msk               /*!< HICK stable flag clear */
#define CRM_CLKINT_HEXTSTBLFC_Pos           (19U)
#define CRM_CLKINT_HEXTSTBLFC_Msk           (0x1U << CRM_CLKINT_HEXTSTBLFC_Pos)     /*!< 0x00080000 */
#define CRM_CLKINT_HEXTSTBLFC               CRM_CLKINT_HEXTSTBLFC_Msk               /*!< HEXT stable flag clear */
#define CRM_CLKINT_PLLSTBLFC_Pos            (20U)
#define CRM_CLKINT_PLLSTBLFC_Msk            (0x1U << CRM_CLKINT_PLLSTBLFC_Pos)      /*!< 0x00100000 */
#define CRM_CLKINT_PLLSTBLFC                CRM_CLKINT_PLLSTBLFC_Msk                /*!< PLL stable flag clear */
#define CRM_CLKINT_CFDFC_Pos                (23U)
#define CRM_CLKINT_CFDFC_Msk                (0x1U << CRM_CLKINT_CFDFC_Pos)          /*!< 0x00800000 */
#define CRM_CLKINT_CFDFC                    CRM_CLKINT_CFDFC_Msk                    /*!< Clock failure detection flag clear */

/*****************  Bit definition for CRM_APB2RST register  ******************/
#define CRM_APB2RST_IOMUXRST_Pos            (0U)
#define CRM_APB2RST_IOMUXRST_Msk            (0x1U << CRM_APB2RST_IOMUXRST_Pos)      /*!< 0x00000001 */
#define CRM_APB2RST_IOMUXRST                CRM_APB2RST_IOMUXRST_Msk                /*!< IOMUX reset */
#define CRM_APB2RST_EXINTRST_Pos            (1U)
#define CRM_APB2RST_EXINTRST_Msk            (0x1U << CRM_APB2RST_EXINTRST_Pos)      /*!< 0x00000002 */
#define CRM_APB2RST_EXINTRST                CRM_APB2RST_EXINTRST_Msk                /*!< EXINT reset */
#define CRM_APB2RST_GPIOARST_Pos            (2U)
#define CRM_APB2RST_GPIOARST_Msk            (0x1U << CRM_APB2RST_GPIOARST_Pos)      /*!< 0x00000004 */
#define CRM_APB2RST_GPIOARST                CRM_APB2RST_GPIOARST_Msk                /*!< GPIOA reset */
#define CRM_APB2RST_GPIOBRST_Pos            (3U)
#define CRM_APB2RST_GPIOBRST_Msk            (0x1U << CRM_APB2RST_GPIOBRST_Pos)      /*!< 0x00000008 */
#define CRM_APB2RST_GPIOBRST                CRM_APB2RST_GPIOBRST_Msk                /*!< GPIOB reset */
#define CRM_APB2RST_GPIOCRST_Pos            (4U)
#define CRM_APB2RST_GPIOCRST_Msk            (0x1U << CRM_APB2RST_GPIOCRST_Pos)      /*!< 0x00000010 */
#define CRM_APB2RST_GPIOCRST                CRM_APB2RST_GPIOCRST_Msk                /*!< GPIOC reset */
#define CRM_APB2RST_GPIODRST_Pos            (5U)
#define CRM_APB2RST_GPIODRST_Msk            (0x1U << CRM_APB2RST_GPIODRST_Pos)      /*!< 0x00000020 */
#define CRM_APB2RST_GPIODRST                CRM_APB2RST_GPIODRST_Msk                /*!< GPIOD reset */
#define CRM_APB2RST_GPIOFRST_Pos            (7U)
#define CRM_APB2RST_GPIOFRST_Msk            (0x1U << CRM_APB2RST_GPIOFRST_Pos)      /*!< 0x00000080 */
#define CRM_APB2RST_GPIOFRST                CRM_APB2RST_GPIOFRST_Msk                /*!< GPIOF reset */
#define CRM_APB2RST_ADC1RST_Pos             (9U)
#define CRM_APB2RST_ADC1RST_Msk             (0x1U << CRM_APB2RST_ADC1RST_Pos)       /*!< 0x00000200 */
#define CRM_APB2RST_ADC1RST                 CRM_APB2RST_ADC1RST_Msk                 /*!< ADC1 reset */
#define CRM_APB2RST_TMR1RST_Pos             (11U)
#define CRM_APB2RST_TMR1RST_Msk             (0x1U << CRM_APB2RST_TMR1RST_Pos)       /*!< 0x00000800 */
#define CRM_APB2RST_TMR1RST                 CRM_APB2RST_TMR1RST_Msk                 /*!< TMR1 reset */
#define CRM_APB2RST_SPI1RST_Pos             (12U)
#define CRM_APB2RST_SPI1RST_Msk             (0x1U << CRM_APB2RST_SPI1RST_Pos)       /*!< 0x00001000 */
#define CRM_APB2RST_SPI1RST                 CRM_APB2RST_SPI1RST_Msk                 /*!< SPI1 reset */
#define CRM_APB2RST_USART1RST_Pos           (14U)
#define CRM_APB2RST_USART1RST_Msk           (0x1U << CRM_APB2RST_USART1RST_Pos)     /*!< 0x00004000 */
#define CRM_APB2RST_USART1RST               CRM_APB2RST_USART1RST_Msk               /*!< USART1 reset */
#define CRM_APB2RST_TMR9RST_Pos             (19U)
#define CRM_APB2RST_TMR9RST_Msk             (0x1U << CRM_APB2RST_TMR9RST_Pos)       /*!< 0x00080000 */
#define CRM_APB2RST_TMR9RST                 CRM_APB2RST_TMR9RST_Msk                 /*!< TMR9 reset */
#define CRM_APB2RST_TMR10RST_Pos            (20U)
#define CRM_APB2RST_TMR10RST_Msk            (0x1U << CRM_APB2RST_TMR10RST_Pos)      /*!< 0x00100000 */
#define CRM_APB2RST_TMR10RST                CRM_APB2RST_TMR10RST_Msk                /*!< TMR10 reset */
#define CRM_APB2RST_TMR11RST_Pos            (21U)
#define CRM_APB2RST_TMR11RST_Msk            (0x1U << CRM_APB2RST_TMR11RST_Pos)      /*!< 0x00200000 */
#define CRM_APB2RST_TMR11RST                CRM_APB2RST_TMR11RST_Msk                /*!< TMR11 reset */

/*****************  Bit definition for CRM_APB1RST register  ******************/
#define CRM_APB1RST_TMR2RST_Pos             (0U)
#define CRM_APB1RST_TMR2RST_Msk             (0x1U << CRM_APB1RST_TMR2RST_Pos)       /*!< 0x00000001 */
#define CRM_APB1RST_TMR2RST                 CRM_APB1RST_TMR2RST_Msk                 /*!< TMR2 reset */
#define CRM_APB1RST_TMR3RST_Pos             (1U)
#define CRM_APB1RST_TMR3RST_Msk             (0x1U << CRM_APB1RST_TMR3RST_Pos)       /*!< 0x00000002 */
#define CRM_APB1RST_TMR3RST                 CRM_APB1RST_TMR3RST_Msk                 /*!< TMR3 reset */
#define CRM_APB1RST_TMR4RST_Pos             (2U)
#define CRM_APB1RST_TMR4RST_Msk             (0x1U << CRM_APB1RST_TMR4RST_Pos)       /*!< 0x00000004 */
#define CRM_APB1RST_TMR4RST                 CRM_APB1RST_TMR4RST_Msk                 /*!< TMR4 reset */
#define CRM_APB1RST_TMR5RST_Pos             (3U)
#define CRM_APB1RST_TMR5RST_Msk             (0x1U << CRM_APB1RST_TMR5RST_Pos)       /*!< 0x00000008 */
#define CRM_APB1RST_TMR5RST                 CRM_APB1RST_TMR5RST_Msk                 /*!< TMR5 reset */
#define CRM_APB1RST_CMPRST_Pos              (9U)
#define CRM_APB1RST_CMPRST_Msk              (0x1U << CRM_APB1RST_CMPRST_Pos)        /*!< 0x00000200 */
#define CRM_APB1RST_CMPRST                  CRM_APB1RST_CMPRST_Msk                  /*!< CMP reset */
#define CRM_APB1RST_WWDTRST_Pos             (11U)
#define CRM_APB1RST_WWDTRST_Msk             (0x1U << CRM_APB1RST_WWDTRST_Pos)       /*!< 0x00000800 */
#define CRM_APB1RST_WWDTRST                 CRM_APB1RST_WWDTRST_Msk                 /*!< WWDT reset */
#define CRM_APB1RST_SPI2RST_Pos             (14U)
#define CRM_APB1RST_SPI2RST_Msk             (0x1U << CRM_APB1RST_SPI2RST_Pos)       /*!< 0x00004000 */
#define CRM_APB1RST_SPI2RST                 CRM_APB1RST_SPI2RST_Msk                 /*!< SPI2 reset */
#define CRM_APB1RST_USART2RST_Pos           (17U)
#define CRM_APB1RST_USART2RST_Msk           (0x1U << CRM_APB1RST_USART2RST_Pos)     /*!< 0x00020000 */
#define CRM_APB1RST_USART2RST               CRM_APB1RST_USART2RST_Msk               /*!< USART2 reset */
#define CRM_APB1RST_USART3RST_Pos           (18U)
#define CRM_APB1RST_USART3RST_Msk           (0x1U << CRM_APB1RST_USART3RST_Pos)     /*!< 0x00040000 */
#define CRM_APB1RST_USART3RST               CRM_APB1RST_USART3RST_Msk               /*!< USART3 reset */
#define CRM_APB1RST_I2C1RST_Pos             (21U)
#define CRM_APB1RST_I2C1RST_Msk             (0x1U << CRM_APB1RST_I2C1RST_Pos)       /*!< 0x00200000 */
#define CRM_APB1RST_I2C1RST                 CRM_APB1RST_I2C1RST_Msk                 /*!< I2C1 reset */
#define CRM_APB1RST_I2C2RST_Pos             (22U)
#define CRM_APB1RST_I2C2RST_Msk             (0x1U << CRM_APB1RST_I2C2RST_Pos)       /*!< 0x00400000 */
#define CRM_APB1RST_I2C2RST                 CRM_APB1RST_I2C2RST_Msk                 /*!< I2C2 reset */
#define CRM_APB1RST_CAN1RST_Pos             (25U)
#define CRM_APB1RST_CAN1RST_Msk             (0x1U << CRM_APB1RST_CAN1RST_Pos)       /*!< 0x02000000 */
#define CRM_APB1RST_CAN1RST                 CRM_APB1RST_CAN1RST_Msk                 /*!< CAN1 reset */
#define CRM_APB1RST_PWCRST_Pos              (28U)
#define CRM_APB1RST_PWCRST_Msk              (0x1U << CRM_APB1RST_PWCRST_Pos)        /*!< 0x10000000 */
#define CRM_APB1RST_PWCRST                  CRM_APB1RST_PWCRST_Msk                  /*!< PWC reset */

/******************  Bit definition for CRM_AHBEN register  *******************/
#define CRM_AHBEN_DMA1EN_Pos                (0U)
#define CRM_AHBEN_DMA1EN_Msk                (0x1U << CRM_AHBEN_DMA1EN_Pos)          /*!< 0x00000001 */
#define CRM_AHBEN_DMA1EN                    CRM_AHBEN_DMA1EN_Msk                    /*!< DMA1 clock enable */
#define CRM_AHBEN_DMA2EN_Pos                (1U)
#define CRM_AHBEN_DMA2EN_Msk                (0x1U << CRM_AHBEN_DMA2EN_Pos)          /*!< 0x00000002 */
#define CRM_AHBEN_DMA2EN                    CRM_AHBEN_DMA2EN_Msk                    /*!< DMA2 clock enable */
#define CRM_AHBEN_SRAMEN_Pos                (2U)
#define CRM_AHBEN_SRAMEN_Msk                (0x1U << CRM_AHBEN_SRAMEN_Pos)          /*!< 0x00000004 */
#define CRM_AHBEN_SRAMEN                    CRM_AHBEN_SRAMEN_Msk                    /*!< SRAM clock enable */
#define CRM_AHBEN_FLASHEN_Pos               (4U)
#define CRM_AHBEN_FLASHEN_Msk               (0x1U << CRM_AHBEN_FLASHEN_Pos)         /*!< 0x00000010 */
#define CRM_AHBEN_FLASHEN                   CRM_AHBEN_FLASHEN_Msk                   /*!< Flash clock enable */
#define CRM_AHBEN_CRCEN_Pos                 (6U)
#define CRM_AHBEN_CRCEN_Msk                 (0x1U << CRM_AHBEN_CRCEN_Pos)           /*!< 0x00000040 */
#define CRM_AHBEN_CRCEN                     CRM_AHBEN_CRCEN_Msk                     /*!< CRC clock enable */
#define CRM_AHBEN_SDIOEN_Pos                (10U)
#define CRM_AHBEN_SDIOEN_Msk                (0x1U << CRM_AHBEN_SDIOEN_Pos)          /*!< 0x00000400 */
#define CRM_AHBEN_SDIOEN                    CRM_AHBEN_SDIOEN_Msk                    /*!< SDIO clock enable */
#define CRM_AHBEN_OTGFSEN_Pos               (12U)
#define CRM_AHBEN_OTGFSEN_Msk               (0x1U << CRM_AHBEN_OTGFSEN_Pos)         /*!< 0x00001000 */
#define CRM_AHBEN_OTGFSEN                   CRM_AHBEN_OTGFSEN_Msk                   /*!< OTGFS clock enable */

/******************  Bit definition for CRM_APB2EN register  ******************/
#define CRM_APB2EN_IOMUXEN_Pos              (0U)
#define CRM_APB2EN_IOMUXEN_Msk              (0x1U << CRM_APB2EN_IOMUXEN_Pos)        /*!< 0x00000001 */
#define CRM_APB2EN_IOMUXEN                  CRM_APB2EN_IOMUXEN_Msk                  /*!< IOMUX clock enable */
#define CRM_APB2EN_GPIOAEN_Pos              (2U)
#define CRM_APB2EN_GPIOAEN_Msk              (0x1U << CRM_APB2EN_GPIOAEN_Pos)        /*!< 0x00000004 */
#define CRM_APB2EN_GPIOAEN                  CRM_APB2EN_GPIOAEN_Msk                  /*!< GPIOA clock enable */
#define CRM_APB2EN_GPIOBEN_Pos              (3U)
#define CRM_APB2EN_GPIOBEN_Msk              (0x1U << CRM_APB2EN_GPIOBEN_Pos)        /*!< 0x00000008 */
#define CRM_APB2EN_GPIOBEN                  CRM_APB2EN_GPIOBEN_Msk                  /*!< GPIOB clock enable */
#define CRM_APB2EN_GPIOCEN_Pos              (4U)
#define CRM_APB2EN_GPIOCEN_Msk              (0x1U << CRM_APB2EN_GPIOCEN_Pos)        /*!< 0x00000010 */
#define CRM_APB2EN_GPIOCEN                  CRM_APB2EN_GPIOCEN_Msk                  /*!< GPIOC clock enable */
#define CRM_APB2EN_GPIODEN_Pos              (5U)
#define CRM_APB2EN_GPIODEN_Msk              (0x1U << CRM_APB2EN_GPIODEN_Pos)        /*!< 0x00000020 */
#define CRM_APB2EN_GPIODEN                  CRM_APB2EN_GPIODEN_Msk                  /*!< GPIOD clock enable */
#define CRM_APB2EN_GPIOFEN_Pos              (7U)
#define CRM_APB2EN_GPIOFEN_Msk              (0x1U << CRM_APB2EN_GPIOFEN_Pos)        /*!< 0x00000080 */
#define CRM_APB2EN_GPIOFEN                  CRM_APB2EN_GPIOFEN_Msk                  /*!< GPIOF clock enable */
#define CRM_APB2EN_ADC1EN_Pos               (9U)
#define CRM_APB2EN_ADC1EN_Msk               (0x1U << CRM_APB2EN_ADC1EN_Pos)         /*!< 0x00000200 */
#define CRM_APB2EN_ADC1EN                   CRM_APB2EN_ADC1EN_Msk                   /*!< ADC1 clock enable */
#define CRM_APB2EN_TMR1EN_Pos               (11U)
#define CRM_APB2EN_TMR1EN_Msk               (0x1U << CRM_APB2EN_TMR1EN_Pos)         /*!< 0x00000800 */
#define CRM_APB2EN_TMR1EN                   CRM_APB2EN_TMR1EN_Msk                   /*!< TMR1 clock enable */
#define CRM_APB2EN_SPI1EN_Pos               (12U)
#define CRM_APB2EN_SPI1EN_Msk               (0x1U << CRM_APB2EN_SPI1EN_Pos)         /*!< 0x00001000 */
#define CRM_APB2EN_SPI1EN                   CRM_APB2EN_SPI1EN_Msk                   /*!< SPI1 clock enable */
#define CRM_APB2EN_USART1EN_Pos             (14U)
#define CRM_APB2EN_USART1EN_Msk             (0x1U << CRM_APB2EN_USART1EN_Pos)       /*!< 0x00004000 */
#define CRM_APB2EN_USART1EN                 CRM_APB2EN_USART1EN_Msk                 /*!< USART1 clock enable */
#define CRM_APB2EN_TMR9EN_Pos               (19U)
#define CRM_APB2EN_TMR9EN_Msk               (0x1U << CRM_APB2EN_TMR9EN_Pos)         /*!< 0x00080000 */
#define CRM_APB2EN_TMR9EN                   CRM_APB2EN_TMR9EN_Msk                   /*!< TMR9 clock enable */
#define CRM_APB2EN_TMR10EN_Pos              (20U)
#define CRM_APB2EN_TMR10EN_Msk              (0x1U << CRM_APB2EN_TMR10EN_Pos)        /*!< 0x00100000 */
#define CRM_APB2EN_TMR10EN                  CRM_APB2EN_TMR10EN_Msk                  /*!< TMR10 clock enable */
#define CRM_APB2EN_TMR11EN_Pos              (21U)
#define CRM_APB2EN_TMR11EN_Msk              (0x1U << CRM_APB2EN_TMR11EN_Pos)        /*!< 0x00200000 */
#define CRM_APB2EN_TMR11EN                  CRM_APB2EN_TMR11EN_Msk                  /*!< TMR11 clock enable */

/******************  Bit definition for CRM_APB1EN register  ******************/
#define CRM_APB1EN_TMR2EN_Pos               (0U)
#define CRM_APB1EN_TMR2EN_Msk               (0x1U << CRM_APB1EN_TMR2EN_Pos)         /*!< 0x00000001 */
#define CRM_APB1EN_TMR2EN                   CRM_APB1EN_TMR2EN_Msk                   /*!< TMR2 clock enable */
#define CRM_APB1EN_TMR3EN_Pos               (1U)
#define CRM_APB1EN_TMR3EN_Msk               (0x1U << CRM_APB1EN_TMR3EN_Pos)         /*!< 0x00000002 */
#define CRM_APB1EN_TMR3EN                   CRM_APB1EN_TMR3EN_Msk                   /*!< TMR3 clock enable */
#define CRM_APB1EN_TMR4EN_Pos               (2U)
#define CRM_APB1EN_TMR4EN_Msk               (0x1U << CRM_APB1EN_TMR4EN_Pos)         /*!< 0x00000004 */
#define CRM_APB1EN_TMR4EN                   CRM_APB1EN_TMR4EN_Msk                   /*!< TMR4 clock enable */
#define CRM_APB1EN_TMR5EN_Pos               (3U)
#define CRM_APB1EN_TMR5EN_Msk               (0x1U << CRM_APB1EN_TMR5EN_Pos)         /*!< 0x00000008 */
#define CRM_APB1EN_TMR5EN                   CRM_APB1EN_TMR5EN_Msk                   /*!< TMR5 clock enable */
#define CRM_APB1EN_CMPEN_Pos                (9U)
#define CRM_APB1EN_CMPEN_Msk                (0x1U << CRM_APB1EN_CMPEN_Pos)          /*!< 0x00000200 */
#define CRM_APB1EN_CMPEN                    CRM_APB1EN_CMPEN_Msk                    /*!< CMP clock enable */
#define CRM_APB1EN_WWDTEN_Pos               (11U)
#define CRM_APB1EN_WWDTEN_Msk               (0x1U << CRM_APB1EN_WWDTEN_Pos)         /*!< 0x00000800 */
#define CRM_APB1EN_WWDTEN                   CRM_APB1EN_WWDTEN_Msk                   /*!< WWDT clock enable */
#define CRM_APB1EN_SPI2EN_Pos               (14U)
#define CRM_APB1EN_SPI2EN_Msk               (0x1U << CRM_APB1EN_SPI2EN_Pos)         /*!< 0x00004000 */
#define CRM_APB1EN_SPI2EN                   CRM_APB1EN_SPI2EN_Msk                   /*!< SPI2 clock enable */
#define CRM_APB1EN_USART2EN_Pos             (17U)
#define CRM_APB1EN_USART2EN_Msk             (0x1U << CRM_APB1EN_USART2EN_Pos)       /*!< 0x00020000 */
#define CRM_APB1EN_USART2EN                 CRM_APB1EN_USART2EN_Msk                 /*!< USART2 clock enable */
#define CRM_APB1EN_USART3EN_Pos             (18U)
#define CRM_APB1EN_USART3EN_Msk             (0x1U << CRM_APB1EN_USART3EN_Pos)       /*!< 0x00040000 */
#define CRM_APB1EN_USART3EN                 CRM_APB1EN_USART3EN_Msk                 /*!< USART3 clock enable */
#define CRM_APB1EN_I2C1EN_Pos               (21U)
#define CRM_APB1EN_I2C1EN_Msk               (0x1U << CRM_APB1EN_I2C1EN_Pos)         /*!< 0x00200000 */
#define CRM_APB1EN_I2C1EN                   CRM_APB1EN_I2C1EN_Msk                   /*!< I2C1 clock enable */
#define CRM_APB1EN_I2C2EN_Pos               (22U)
#define CRM_APB1EN_I2C2EN_Msk               (0x1U << CRM_APB1EN_I2C2EN_Pos)         /*!< 0x00400000 */
#define CRM_APB1EN_I2C2EN                   CRM_APB1EN_I2C2EN_Msk                   /*!< I2C2 clock enable */
#define CRM_APB1EN_CAN1EN_Pos               (25U)
#define CRM_APB1EN_CAN1EN_Msk               (0x1U << CRM_APB1EN_CAN1EN_Pos)         /*!< 0x02000000 */
#define CRM_APB1EN_CAN1EN                   CRM_APB1EN_CAN1EN_Msk                   /*!< CAN1 clock enable */
#define CRM_APB1EN_PWCEN_Pos                (28U)
#define CRM_APB1EN_PWCEN_Msk                (0x1U << CRM_APB1EN_PWCEN_Pos)          /*!< 0x10000000 */
#define CRM_APB1EN_PWCEN                    CRM_APB1EN_PWCEN_Msk                    /*!< Power control clock enable */

/*******************  Bit definition for CRM_BPDC register  *******************/
#define CRM_BPDC_LEXTEN_Pos                 (0U)
#define CRM_BPDC_LEXTEN_Msk                 (0x1U << CRM_BPDC_LEXTEN_Pos)           /*!< 0x00000001 */
#define CRM_BPDC_LEXTEN                     CRM_BPDC_LEXTEN_Msk                     /*!< External low-speed oscillator enable */
#define CRM_BPDC_LEXTSTBL_Pos               (1U)
#define CRM_BPDC_LEXTSTBL_Msk               (0x1U << CRM_BPDC_LEXTSTBL_Pos)         /*!< 0x00000002 */
#define CRM_BPDC_LEXTSTBL                   CRM_BPDC_LEXTSTBL_Msk                   /*!< Low speed external oscillator stable */
#define CRM_BPDC_LEXTBYPS_Pos               (2U)
#define CRM_BPDC_LEXTBYPS_Msk               (0x1U << CRM_BPDC_LEXTBYPS_Pos)         /*!< 0x00000004 */
#define CRM_BPDC_LEXTBYPS                   CRM_BPDC_LEXTBYPS_Msk                   /*!< Low speed external crystal bypass */

/*!< ERTCSEL congiguration */
#define CRM_BPDC_ERTCSEL_Pos                (8U)
#define CRM_BPDC_ERTCSEL_Msk                (0x3U << CRM_BPDC_ERTCSEL_Pos)          /*!< 0x00000300 */
#define CRM_BPDC_ERTCSEL                    CRM_BPDC_ERTCSEL_Msk                    /*!< ERTCSEL[1:0] bits (ERTC clock selection) */
#define CRM_BPDC_ERTCSEL_0                  (0x1U << CRM_BPDC_ERTCSEL_Pos)          /*!< 0x00000100 */
#define CRM_BPDC_ERTCSEL_1                  (0x2U << CRM_BPDC_ERTCSEL_Pos)          /*!< 0x00000200 */

#define CRM_BPDC_ERTCSEL_NOCLOCK            0x00000000U                             /*!< No clock */
#define CRM_BPDC_ERTCSEL_LEXT               0x00000100U                             /*!< LEXT */
#define CRM_BPDC_ERTCSEL_LICK               0x00000200U                             /*!< LICK */
#define CRM_BPDC_ERTCSEL_HEXT               0x00000300U                             /*!< HEXT/128 */

#define CRM_BPDC_ERTCEN_Pos                 (15U)
#define CRM_BPDC_ERTCEN_Msk                 (0x1U << CRM_BPDC_ERTCEN_Pos)           /*!< 0x00008000 */
#define CRM_BPDC_ERTCEN                     CRM_BPDC_ERTCEN_Msk                     /*!< ERTC clock enable */
#define CRM_BPDC_BPDRST_Pos                 (16U)
#define CRM_BPDC_BPDRST_Msk                 (0x1U << CRM_BPDC_BPDRST_Pos)           /*!< 0x00010000 */
#define CRM_BPDC_BPDRST                     CRM_BPDC_BPDRST_Msk                     /*!< Battery powered domain software reset */

/*****************  Bit definition for CRM_CTRLSTS register  ******************/
#define CRM_CTRLSTS_LICKEN_Pos              (0U)
#define CRM_CTRLSTS_LICKEN_Msk              (0x1U << CRM_CTRLSTS_LICKEN_Pos)        /*!< 0x00000001 */
#define CRM_CTRLSTS_LICKEN                  CRM_CTRLSTS_LICKEN_Msk                  /*!< LICK enable */
#define CRM_CTRLSTS_LICKSTBL_Pos            (1U)
#define CRM_CTRLSTS_LICKSTBL_Msk            (0x1U << CRM_CTRLSTS_LICKSTBL_Pos)      /*!< 0x00000002 */
#define CRM_CTRLSTS_LICKSTBL                CRM_CTRLSTS_LICKSTBL_Msk                /*!< LICK stable */
#define CRM_CTRLSTS_RSTFC_Pos               (24U)
#define CRM_CTRLSTS_RSTFC_Msk               (0x1U << CRM_CTRLSTS_RSTFC_Pos)         /*!< 0x01000000 */
#define CRM_CTRLSTS_RSTFC                   CRM_CTRLSTS_RSTFC_Msk                   /*!< Reset flag clear */
#define CRM_CTRLSTS_NRSTF_Pos               (26U)
#define CRM_CTRLSTS_NRSTF_Msk               (0x1U << CRM_CTRLSTS_NRSTF_Pos)         /*!< 0x04000000 */
#define CRM_CTRLSTS_NRSTF                   CRM_CTRLSTS_NRSTF_Msk                   /*!< NRST pin reset flag */
#define CRM_CTRLSTS_PORRSTF_Pos             (27U)
#define CRM_CTRLSTS_PORRSTF_Msk             (0x1U << CRM_CTRLSTS_PORRSTF_Pos)       /*!< 0x08000000 */
#define CRM_CTRLSTS_PORRSTF                 CRM_CTRLSTS_PORRSTF_Msk                 /*!< POR/LVR reset flag */
#define CRM_CTRLSTS_SWRSTF_Pos              (28U)
#define CRM_CTRLSTS_SWRSTF_Msk              (0x1U << CRM_CTRLSTS_SWRSTF_Pos)        /*!< 0x10000000 */
#define CRM_CTRLSTS_SWRSTF                  CRM_CTRLSTS_SWRSTF_Msk                  /*!< Software reset flag */
#define CRM_CTRLSTS_WDTRSTF_Pos             (29U)
#define CRM_CTRLSTS_WDTRSTF_Msk             (0x1U << CRM_CTRLSTS_WDTRSTF_Pos)       /*!< 0x20000000 */
#define CRM_CTRLSTS_WDTRSTF                 CRM_CTRLSTS_WDTRSTF_Msk                 /*!< Watchdog timer reset flag */
#define CRM_CTRLSTS_WWDTRSTF_Pos            (30U)
#define CRM_CTRLSTS_WWDTRSTF_Msk            (0x1U << CRM_CTRLSTS_WWDTRSTF_Pos)      /*!< 0x40000000 */
#define CRM_CTRLSTS_WWDTRSTF                CRM_CTRLSTS_WWDTRSTF_Msk                /*!< Window watchdog timer reset flag */
#define CRM_CTRLSTS_LPRSTF_Pos              (31U)
#define CRM_CTRLSTS_LPRSTF_Msk              (0x1U << CRM_CTRLSTS_LPRSTF_Pos)        /*!< 0x80000000 */
#define CRM_CTRLSTS_LPRSTF                  CRM_CTRLSTS_LPRSTF_Msk                  /*!< Low-power reset flag */

/******************  Bit definition for CRM_AHBRST register  ******************/
#define CRM_AHBRST_OTGFSRST_Pos             (12U)
#define CRM_AHBRST_OTGFSRST_Msk             (0x1U << CRM_AHBRST_OTGFSRST_Pos)       /*!< 0x00001000 */
#define CRM_AHBRST_OTGFSRST                 CRM_AHBRST_OTGFSRST_Msk                 /*!< OTGFS reset */

/*******************  Bit definition for CRM_PLL register  ********************/
/*!< PLL_FR congiguration */
#define CRM_PLL_PLL_FR_Pos                  (0U)
#define CRM_PLL_PLL_FR_Msk                  (0x7U << CRM_PLL_PLL_FR_Pos)            /*!< 0x00000007 */
#define CRM_PLL_PLL_FR                      CRM_PLL_PLL_FR_Msk                      /*!< PLL_FR[2:0] bits (PLL post-division factor) */
#define CRM_PLL_PLL_FR_0                    (0x1U << CRM_PLL_PLL_FR_Pos)            /*!< 0x00000001 */
#define CRM_PLL_PLL_FR_1                    (0x2U << CRM_PLL_PLL_FR_Pos)            /*!< 0x00000002 */
#define CRM_PLL_PLL_FR_2                    (0x4U << CRM_PLL_PLL_FR_Pos)            /*!< 0x00000004 */

/*!< PLL_MS congiguration */
#define CRM_PLL_PLL_MS_Pos                  (4U)
#define CRM_PLL_PLL_MS_Msk                  (0xFU << CRM_PLL_PLL_MS_Pos)            /*!< 0x000000F0 */
#define CRM_PLL_PLL_MS                      CRM_PLL_PLL_MS_Msk                      /*!< PLL_MS[3:0] bits (PLL pre-division) */
#define CRM_PLL_PLL_MS_0                    (0x1U << CRM_PLL_PLL_MS_Pos)            /*!< 0x00000010 */
#define CRM_PLL_PLL_MS_1                    (0x2U << CRM_PLL_PLL_MS_Pos)            /*!< 0x00000020 */
#define CRM_PLL_PLL_MS_2                    (0x4U << CRM_PLL_PLL_MS_Pos)            /*!< 0x00000040 */
#define CRM_PLL_PLL_MS_3                    (0x8U << CRM_PLL_PLL_MS_Pos)            /*!< 0x00000080 */

/*!< PLL_NS congiguration */
#define CRM_PLL_PLL_NS_Pos                  (8U)
#define CRM_PLL_PLL_NS_Msk                  (0x1FFU << CRM_PLL_PLL_NS_Pos)          /*!< 0x0001FF00 */
#define CRM_PLL_PLL_NS                      CRM_PLL_PLL_NS_Msk                      /*!< PLL_NS[8:0] bits (PLL multiplication factor) */
#define CRM_PLL_PLL_NS_0                    (0x001U << CRM_PLL_PLL_NS_Pos)          /*!< 0x00000100 */
#define CRM_PLL_PLL_NS_1                    (0x002U << CRM_PLL_PLL_NS_Pos)          /*!< 0x00000200 */
#define CRM_PLL_PLL_NS_2                    (0x004U << CRM_PLL_PLL_NS_Pos)          /*!< 0x00000400 */
#define CRM_PLL_PLL_NS_3                    (0x008U << CRM_PLL_PLL_NS_Pos)          /*!< 0x00000800 */
#define CRM_PLL_PLL_NS_4                    (0x010U << CRM_PLL_PLL_NS_Pos)          /*!< 0x00001000 */
#define CRM_PLL_PLL_NS_5                    (0x020U << CRM_PLL_PLL_NS_Pos)          /*!< 0x00002000 */
#define CRM_PLL_PLL_NS_6                    (0x040U << CRM_PLL_PLL_NS_Pos)          /*!< 0x00004000 */
#define CRM_PLL_PLL_NS_7                    (0x080U << CRM_PLL_PLL_NS_Pos)          /*!< 0x00008000 */
#define CRM_PLL_PLL_NS_8                    (0x100U << CRM_PLL_PLL_NS_Pos)          /*!< 0x00010000 */

/*!< PLL_FREF congiguration */
#define CRM_PLL_PLL_FREF_Pos                (24U)
#define CRM_PLL_PLL_FREF_Msk                (0x7U << CRM_PLL_PLL_FREF_Pos)          /*!< 0x07000000 */
#define CRM_PLL_PLL_FREF                    CRM_PLL_PLL_FREF_Msk                    /*!< PLL_FREF[2:0] bits (PLL input clock selection) */
#define CRM_PLL_PLL_FREF_0                  (0x1U << CRM_PLL_PLL_FREF_Pos)          /*!< 0x01000000 */
#define CRM_PLL_PLL_FREF_1                  (0x2U << CRM_PLL_PLL_FREF_Pos)          /*!< 0x02000000 */
#define CRM_PLL_PLL_FREF_2                  (0x4U << CRM_PLL_PLL_FREF_Pos)          /*!< 0x04000000 */

#define CRM_PLL_PLL_FREF_4M                 0x00000000U                             /*!< 3.9 ~ 5 MHz */
#define CRM_PLL_PLL_FREF_6M                 0x01000000U                             /*!< 5.2 ~ 6.25 MHz */
#define CRM_PLL_PLL_FREF_8M                 0x02000000U                             /*!< 7.8125 ~ 8.33 MHz */
#define CRM_PLL_PLL_FREF_12M                0x03000000U                             /*!< 8.33 ~ 12.5 MHz */
#define CRM_PLL_PLL_FREF_16M                0x04000000U                             /*!< 15.625 ~ 20.83 MHz */
#define CRM_PLL_PLL_FREF_25M                0x05000000U                             /*!< 20.83 ~ 31.255 MHz */

#define CRM_PLL_PLLCFGEN_Pos                (31U)
#define CRM_PLL_PLLCFGEN_Msk                (0x1U << CRM_PLL_PLLCFGEN_Pos)          /*!< 0x80000000 */
#define CRM_PLL_PLLCFGEN                    CRM_PLL_PLLCFGEN_Msk                    /*!< PLL configuration enable */

/******************  Bit definition for CRM_MISC1 register  *******************/
#define CRM_MISC1_HICKCAL_KEY_Pos           (0U)
#define CRM_MISC1_HICKCAL_KEY_Msk           (0xFFU << CRM_MISC1_HICKCAL_KEY_Pos)    /*!< 0x000000FF */
#define CRM_MISC1_HICKCAL_KEY               CRM_MISC1_HICKCAL_KEY_Msk               /*!< HICK calibration key */
#define CRM_MISC1_CLKOUT_SEL_Pos            (16U)
#define CRM_MISC1_CLKOUT_SEL_Msk            (0x1U << CRN_MISC1_CLKOUT_SEL_Pos)      /*!< 0x00010000 */
#define CRM_MISC1_CLKOUT_SEL                CRM_MISC1_CLKOUT_SEL_Msk                /*!< Clock output selection */
#define CRM_MISC1_CLKFMC_SRC_Pos            (20U)
#define CRM_MISC1_CLKFMC_SRC_Msk            (0x1U << CRM_MISC1_CLKFMC_SRC_Pos)      /*!< 0x00100000 */
#define CRM_MISC1_CLKFMC_SRC                CRM_MISC1_CLKFMC_SRC_Msk                /*!< FMC clock source */
#define CRM_MISC1_HICKDIV_Pos               (25U)
#define CRM_MISC1_HICKDIV_Msk               (0x1U << CRM_MISC1_HICKDIV_Pos)         /*!< 0x02000000 */
#define CRM_MISC1_HICKDIV                   CRM_MISC1_HICKDIV_Msk                   /*!< HICK 6 divider selection */

/*!< CLKOUTDIV congiguration */
#define CRM_MISC1_CLKOUTDIV_Pos             (28U)
#define CRM_MISC1_CLKOUTDIV_Msk             (0xFU << CRM_MISC1_CLKOUTDIV_Pos)       /*!< 0xF0000000 */
#define CRM_MISC1_CLKOUTDIV                 CRM_MISC1_CLKOUTDIV_Msk                 /*!< CLKOUTDIV[3:0] bits (Clock output division */
#define CRM_MISC1_CLKOUTDIV_0               (0x1U << CRM_MISC1_CLKOUTDIV_Pos)       /*!< 0x10000000 */
#define CRM_MISC1_CLKOUTDIV_1               (0x2U << CRM_MISC1_CLKOUTDIV_Pos)       /*!< 0x20000000 */
#define CRM_MISC1_CLKOUTDIV_2               (0x4U << CRM_MISC1_CLKOUTDIV_Pos)       /*!< 0x40000000 */
#define CRM_MISC1_CLKOUTDIV_3               (0x8U << CRM_MISC1_CLKOUTDIV_Pos)       /*!< 0x80000000 */

#define CRM_MISC1_CLKOUTDIV_DIV1            0x00000000U                             /*!< No clock output */
#define CRM_MISC1_CLKOUTDIV_DIV2            0x80000000U                             /*!< Clock output divided by 2 */
#define CRM_MISC1_CLKOUTDIV_DIV4            0x90000000U                             /*!< Clock output divided by 4 */
#define CRM_MISC1_CLKOUTDIV_DIV8            0xA0000000U                             /*!< Clock output divided by 8 */
#define CRM_MISC1_CLKOUTDIV_DIV16           0xB0000000U                             /*!< Clock output divided by 16 */
#define CRM_MISC1_CLKOUTDIV_DIV64           0xC0000000U                             /*!< Clock output divided by 64 */
#define CRM_MISC1_CLKOUTDIV_DIV128          0xD0000000U                             /*!< Clock output divided by 128 */
#define CRM_MISC1_CLKOUTDIV_DIV256          0xE0000000U                             /*!< Clock output divided by 256 */
#define CRM_MISC1_CLKOUTDIV_DIV512          0xF0000000U                             /*!< Clock output divided by 512 */

/***************  Bit definition for CRM_OTG_EXTCTRL register  ****************/
#define CRM_OTG_EXTCTRL_USBDIV_RST_Pos      (30U)                                   /*!< 0x40000000 */
#define CRM_OTG_EXTCTRL_USBDIV_RST_Msk      (0x1U << CRM_OTG_EXTCTRL_USBDIV_RST_Pos)
#define CRM_OTG_EXTCTRL_USBDIV_RST          CRM_OTG_EXTCTRL_USBDIV_RST_Msk          /*!< USB divider reset */
#define CRM_OTG_EXTCTRL_EP3_RMPEN_Pos       (31U)
#define CRM_OTG_EXTCTRL_EP3_RMPEN_Msk       (0x1U << CRM_OTG_EXTCTRL_EP3_RMPEN_Pos) /*!< 0x80000000 */
#define CRM_OTG_EXTCTRL_EP3_RMPEN           CRM_OTG_EXTCTRL_EP3_RMPEN_Msk           /*!< Endpoint 3 remap enable */

/******************  Bit definition for CRM_MISC2 register  *******************/
/*!< AUTO_STEP_EN congiguration */
#define CRM_MISC2_AUTO_STEP_EN_Pos          (4U)
#define CRM_MISC2_AUTO_STEP_EN_Msk          (0x3U << CRM_MISC2_AUTO_STEP_EN_Pos)    /*!< 0x00000030 */
#define CRM_MISC2_AUTO_STEP_EN              CRM_MISC2_AUTO_STEP_EN_Msk              /*!< AUTO_STEP_EN[1:0] Auto step-by-step SCLK switch enable */
#define CRM_MISC2_AUTO_STEP_EN_0            (0x1U << CRM_MISC2_AUTO_STEP_EN_Pos)    /*!< 0x00000010 */
#define CRM_MISC2_AUTO_STEP_EN_1            (0x2U << CRM_MISC2_AUTO_STEP_EN_Pos)    /*!< 0x00000020 */

#define CRM_MISC2_HICK_TO_SCLK_Pos          (9U)
#define CRM_MISC2_HICK_TO_SCLK_Msk          (0x1U << CRM_MISC2_HICK_TO_SCLK_Pos)    /*!< 0x00000200 */
#define CRM_MISC2_HICK_TO_SCLK              CRM_MISC2_HICK_TO_SCLK_Msk              /*!< HICK as system clock frequency select */

/******************************************************************************/
/*                                                                            */
/*                Flash and User System Data Registers (FLASH)                */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for FLASH_PSR register  ******************/
/*!< WTCYC congiguration */
#define FLASH_PSR_WTCYC_Pos                 (0U)
#define FLASH_PSR_WTCYC_Msk                 (0x7U << FLASH_PSR_WTCYC_Pos)           /*!< 0x00000007 */
#define FLASH_PSR_WTCYC                     FLASH_PSR_WTCYC_Msk                     /*!< WTCYC[2:0] Wait states */
#define FLASH_PSR_WTCYC_0                   (0x1U << FLASH_PSR_WTCYC_Pos)           /*!< 0x00000001 */
#define FLASH_PSR_WTCYC_1                   (0x2U << FLASH_PSR_WTCYC_Pos)           /*!< 0x00000002 */
#define FLASH_PSR_WTCYC_2                   (0x4U << FLASH_PSR_WTCYC_Pos)           /*!< 0x00000004 */

#define FLASH_PSR_HFCYC_EN_Pos              (3U)
#define FLASH_PSR_HFCYC_EN_Msk              (0x1U << FLASH_PSR_HFCYC_EN_Pos)        /*!< 0x00000008 */
#define FLASH_PSR_HFCYC_EN                  FLASH_PSR_HFCYC_EN_Msk                  /*!< Half cycle acceleration access enable */
#define FLASH_PSR_PFT_EN_Pos                (4U)
#define FLASH_PSR_PFT_EN_Msk                (0x1U << FLASH_PSR_PFT_EN_Pos)          /*!< 0x00000010 */
#define FLASH_PSR_PFT_EN                    FLASH_PSR_PFT_EN_Msk                    /*!< Prefetch enable */
#define FLASH_PSR_PFT_ENF_Pos               (5U)
#define FLASH_PSR_PFT_ENF_Msk               (0x1U << FLASH_PSR_PFT_ENF_Pos)         /*!< 0x00000020 */
#define FLASH_PSR_PFT_ENF                   FLASH_PSR_PFT_ENF_Msk                   /*!< Prefetch enable flag */

/*****************  Bit definition for FLASH_UNLOCK register  *****************/
#define FLASH_UNLOCK_UKVAL_Pos              (0U)
#define FLASH_UNLOCK_UKVAL_Msk              (0xFFFFFFFFU << FLASH_UNLOCK_UKVAL_Pos) /*!< 0xFFFFFFFF */
#define FLASH_UNLOCK_UKVAL                  FLASH_UNLOCK_UKVAL_Msk                  /*!< Unlock key value */

#define FAP_KEY_Pos                         (0U)
#define FAP_KEY_Msk                         (0xA5U << FAP_KEY_Pos)                  /*!< 0x000000A5 */
#define FAP_KEY                             FAP_KEY_Msk                             /*!< Flash access protection key */
#define FLASH_KEY1_Pos                      (0U)
#define FLASH_KEY1_Msk                      (0x45670123U << FLASH_KEY1_Pos)         /*!< 0x45670123 */
#define FLASH_KEY1                          FLASH_KEY1_Msk                          /*!< Flash key 1 */
#define FLASH_KEY2_Pos                      (0U)
#define FLASH_KEY2_Msk                      (0xCDEF89ABU << FLASH_KEY2_Pos)         /*!< 0xCDEF89AB */
#define FLASH_KEY2                          FLASH_KEY2_Msk                          /*!< Flash key 2 */

/***************  Bit definition for FLASH_USD_UNLOCK register  ***************/
#define FLASH_USD_UNLOCK_USD_UKVAL_Pos      (0U)                                    /*!< 0xFFFFFFFF */
#define FLASH_USD_UNLOCK_USD_UKVAL_Msk      (0xFFFFFFFFU << FLASH_USD_UNLOCK_USD_UKVAL_Pos)
#define FLASH_USD_UNLOCK_USD_UKVAL          FLASH_USD_UNLOCK_USD_UKVAL_Msk          /*!< User system data unlock key value */

#define FLASH_USDKEY1                       FLASH_KEY1                              /*!< User system data key 1 */
#define FLASH_USDKEY2                       FLASH_KEY2                              /*!< User system data key 2 */

/******************  Bit definition for FLASH_STS register  *******************/
#define FLASH_STS_OBF_Pos                   (0U)
#define FLASH_STS_OBF_Msk                   (0x1U << FLASH_STS_OBF_Pos)             /*!< 0x00000001 */
#define FLASH_STS_OBF                       FLASH_STS_OBF_Msk                       /*!< Operation done flag */
#define FLASH_STS_PRGMERR_Pos               (2U)
#define FLASH_STS_PRGMERR_Msk               (0x1U << FLASH_STS_PRGMERR_Pos)         /*!< 0x00000004 */
#define FLASH_STS_PRGMERR                   FLASH_STS_PRGMERR_Msk                   /*!< Programming error */
#define FLASH_STS_EPPERR_Pos                (4U)
#define FLASH_STS_EPPERR_Msk                (0x1U << FLASH_STS_EPPERR_Pos)          /*!< 0x00000010 */
#define FLASH_STS_EPPERR                    FLASH_STS_EPPERR_Msk                    /*!< Erase/program protection error */
#define FLASH_STS_ODF_Pos                   (5U)
#define FLASH_STS_ODF_Msk                   (0x1U << FLASH_STS_ODF_Pos)             /*!< 0x00000020 */
#define FLASH_STS_ODF                       FLASH_STS_ODF_Msk                       /*!< Operation done flag */

/******************  Bit definition for FLASH_CTRL register  ******************/
#define FLASH_CTRL_FPRGM_Pos                (0U)
#define FLASH_CTRL_FPRGM_Msk                (0x1U << FLASH_CTRL_FPRGM_Pos)          /*!< 0x00000001 */
#define FLASH_CTRL_FPRGM                    FLASH_CTRL_FPRGM_Msk                    /*!< Flash program */
#define FLASH_CTRL_SECERS_Pos               (1U)
#define FLASH_CTRL_SECERS_Msk               (0x1U << FLASH_CTRL_SECERS_Pos)         /*!< 0x00000002 */
#define FLASH_CTRL_SECERS                   FLASH_CTRL_SECERS_Msk                   /*!< Page erase */
#define FLASH_CTRL_BANKERS_Pos              (2U)
#define FLASH_CTRL_BANKERS_Msk              (0x1U << FLASH_CTRL_BANKERS_Pos)        /*!< 0x00000004 */
#define FLASH_CTRL_BANKERS                  FLASH_CTRL_BANKERS_Msk                  /*!< Bank erase */
#define FLASH_CTRL_USDPRGM_Pos              (4U)
#define FLASH_CTRL_USDPRGM_Msk              (0x1U << FLASH_CTRL_USDPRGM_Pos)        /*!< 0x00000010 */
#define FLASH_CTRL_USDPRGM                  FLASH_CTRL_USDPRGM_Msk                  /*!< User system data program */
#define FLASH_CTRL_USDERS_Pos               (5U)
#define FLASH_CTRL_USDERS_Msk               (0x1U << FLASH_CTRL_USDERS_Pos)         /*!< 0x00000020 */
#define FLASH_CTRL_USDERS                   FLASH_CTRL_USDERS_Msk                   /*!< User system data erase */
#define FLASH_CTRL_ERSTR_Pos                (6U)
#define FLASH_CTRL_ERSTR_Msk                (0x1U << FLASH_CTRL_ERSTR_Pos)          /*!< 0x00000040 */
#define FLASH_CTRL_ERSTR                    FLASH_CTRL_ERSTR_Msk                    /*!< Erase start */
#define FLASH_CTRL_OPLK_Pos                 (7U)
#define FLASH_CTRL_OPLK_Msk                 (0x1U << FLASH_CTRL_OPLK_Pos)           /*!< 0x00000080 */
#define FLASH_CTRL_OPLK                     FLASH_CTRL_OPLK_Msk                     /*!< Operation lock */
#define FLASH_CTRL_USDULKS_Pos              (9U)
#define FLASH_CTRL_USDULKS_Msk              (0x1U << FLASH_CTRL_USDULKS_Pos)        /*!< 0x00000200 */
#define FLASH_CTRL_USDULKS                  FLASH_CTRL_USDULKS_Msk                  /*!< User system data unlock success */
#define FLASH_CTRL_ERRIE_Pos                (10U)
#define FLASH_CTRL_ERRIE_Msk                (0x1U << FLASH_CTRL_ERRIE_Pos)          /*!< 0x00000400 */
#define FLASH_CTRL_ERRIE                    FLASH_CTRL_ERRIE_Msk                    /*!< Error interrupt enable */
#define FLASH_CTRL_ODFIE_Pos                (12U)
#define FLASH_CTRL_ODFIE_Msk                (0x1U << FLASH_CTRL_ODFIE_Pos)          /*!< 0x00001000 */
#define FLASH_CTRL_ODFIE                    FLASH_CTRL_ODFIE_Msk                    /*!< Operation done flag interrupt enable */
#define FLASH_CTRL_FAP_HL_DIS_Pos           (16U)
#define FLASH_CTRL_FAP_HL_DIS_Msk           (0x1U << FLASH_CTRL_FAP_HL_DIS_Pos)     /*!< 0x00010000 */
#define FLASH_CTRL_FAP_HL_DIS               FLASH_CTRL_FAP_HL_DIS_Msk               /*!< High level Flash access protection disable */

/******************  Bit definition for FLASH_ADDR register  ******************/
#define FLASH_ADDR_FA_Pos                   (0U)
#define FLASH_ADDR_FA_Msk                   (0xFFFFFFFFU << FLASH_ADDR_FA_Pos)      /*!< 0xFFFFFFFF */
#define FLASH_ADDR_FA                       FLASH_ADDR_FA_Msk                       /*!< Flash address */

/******************  Bit definition for FLASH_USD register  *******************/
#define FLASH_USD_USDERR_Pos                (0U)
#define FLASH_USD_USDERR_Msk                (0x1U << FLASH_USD_USDERR_Pos)          /*!< 0x00000001 */
#define FLASH_USD_USDERR                    FLASH_USD_USDERR_Msk                    /*!< User system data error */
#define FLASH_USD_FAP_Pos                   (1U)
#define FLASH_USD_FAP_Msk                   (0x1U << FLASH_USD_FAP_Pos)             /*!< 0x00000002 */
#define FLASH_USD_FAP                       FLASH_USD_FAP_Msk                       /*!< Flash access protection */

/*!< SSB congiguration */
#define FLASH_USD_WDT_ATO_EN_Pos            (2U)
#define FLASH_USD_WDT_ATO_EN_Msk            (0x1U << FLASH_USD_WDT_ATO_EN_Pos)      /*!< 0x00000004 */
#define FLASH_USD_WDT_ATO_EN                FLASH_USD_WDT_ATO_EN_Msk                /*!< nWDT_ATO_EN */
#define FLASH_USD_DEPSLP_RST_Pos            (3U)
#define FLASH_USD_DEPSLP_RST_Msk            (0x1U << FLASH_USD_DEPSLP_RST_Pos)      /*!< 0x00000008 */
#define FLASH_USD_DEPSLP_RST                FLASH_USD_DEPSLP_RST_Msk                /*!< nDEPSLP_RST */
#define FLASH_USD_STDBY_RST_Pos             (4U)
#define FLASH_USD_STDBY_RST_Msk             (0x1U << FLASH_USD_STDBY_RST_Pos)       /*!< 0x00000010 */
#define FLASH_USD_STDBY_RST                 FLASH_USD_STDBY_RST_Msk                 /*!< nSTDBY_RST */
#define FLASH_USD_SSB_Pos                   (2U)
#define FLASH_USD_SSB_Msk                   (0x7U << FLASH_USD_SSB_Pos)             /*!< 0x0000001C */
#define FLASH_USD_SSB                       FLASH_USD_SSB_Msk                       /*!< System setting byte */

#define FLASH_USD_USER_D0_Pos               (10U)
#define FLASH_USD_USER_D0_Msk               (0xFFU << FLASH_USD_USER_D0_Pos)        /*!< 0x0003FC00 */
#define FLASH_USD_USER_D0                   FLASH_USD_USER_D0_Msk                   /*!< User data 0 */
#define FLASH_USD_USER_D1_Pos               (18U)
#define FLASH_USD_USER_D1_Msk               (0xFFU << FLASH_USD_USER_D1_Pos)        /*!< 0x03FC0000 */
#define FLASH_USD_USER_D1                   FLASH_USD_USER_D1_Msk                   /*!< User data 1 */
#define FLASH_USD_FAP_HL_Pos                (26U)
#define FLASH_USD_FAP_HL_Msk                (0x1U << FLASH_USD_FAP_HL_Pos)          /*!< 0x04000000 */
#define FLASH_USD_FAP_HL                    FLASH_USD_FAP_HL_Msk                    /*!< Flash access protection high level */

/******************  Bit definition for FLASH_EPPS register  ******************/
#define FLASH_EPPS_EPPS_Pos                 (0U)
#define FLASH_EPPS_EPPS_Msk                 (0xFFFFFFFFU << FLASH_EPPS_EPPS_Pos)    /*!< 0xFFFFFFFF */
#define FLASH_EPPS_EPPS                     FLASH_EPPS_EPPS_Msk                     /*!< Erase/Program protection status */

/*******************  Bit definition for SLIB_STS0 register *******************/
#define SLIB_STS0_BTM_AP_ENF_Pos            (0U)
#define SLIB_STS0_BTM_AP_ENF_Msk            (0x1U << SLIB_STS0_BTM_AP_ENF_Pos)      /*!< 0x00000001 */
#define SLIB_STS0_BTM_AP_ENF                SLIB_STS0_BTM_AP_ENF_Msk                /*!< Boot memory store application code enabled flag */
#define SLIB_STS0_EM_SLIB_ENF_Pos           (2U)
#define SLIB_STS0_EM_SLIB_ENF_Msk           (0x1U << SLIB_STS0_EM_SLIB_ENF_Pos)     /*!< 0x00000004 */
#define SLIB_STS0_EM_SLIB_ENF               SLIB_STS0_EM_SLIB_ENF_Msk               /*!< Extension memory sLib enable flag */
#define SLIB_STS0_SLIB_ENF_Pos              (3U)
#define SLIB_STS0_SLIB_ENF_Msk              (0x1U << SLIB_STS0_SLIB_ENF_Pos)        /*!< 0x00000008 */
#define SLIB_STS0_SLIB_ENF                  SLIB_STS0_SLIB_ENF_Msk                  /*!< Security library enable flag */
#define SLIB_STS0_EM_SLIB_DAT_SS_Pos        (16U)
#define SLIB_STS0_EM_SLIB_DAT_SS_Msk        (0xFFU << SLIB_STS0_EM_SLIB_DAT_SS_Pos) /*!< 0x00FF0000 */
#define SLIB_STS0_EM_SLIB_DAT_SS            SLIB_STS0_EM_SLIB_DAT_SS_Msk            /*!< Extension memory sLib data start page */

/*******************  Bit definition for SLIB_STS1 register *******************/
#define SLIB_STS1_SLIB_SS_Pos               (0U)
#define SLIB_STS1_SLIB_SS_Msk               (0x7FFU << SLIB_STS1_SLIB_SS_Pos)       /*!< 0x000007FF */
#define SLIB_STS1_SLIB_SS                   SLIB_STS1_SLIB_SS_Msk                   /*!< Security library start page */
#define SLIB_STS1_SLIB_DAT_SS_Pos           (11U)
#define SLIB_STS1_SLIB_DAT_SS_Msk           (0x3FF8U << SLIB_STS1_SLIB_DAT_SS_Pos)  /*!< 0x003FF800 */
#define SLIB_STS1_SLIB_DAT_SS               SLIB_STS1_SLIB_DAT_SS_Msk               /*!< Security library data start page */
#define SLIB_STS1_SLIB_ES_Pos               (22U)
#define SLIB_STS1_SLIB_ES_Msk               (0xFFCU << SLIB_STS1_SLIB_ES_Pos)       /*!< 0xFFC00000 */
#define SLIB_STS1_SLIB_ES                   SLIB_STS1_SLIB_ES_Msk                   /*!< Security library end page */

/*****************  Bit definition for SLIB_PWD_CLR register ******************/
#define SLIB_PWD_CLR_SLIB_PCLR_VAL_Pos      (0U)                                    /*!< 0xFFFFFFFF */
#define SLIB_PWD_CLR_SLIB_PCLR_VAL_Msk      (0xFFFFFFFFU << SLIB_PWD_CLR_SLIB_PCLR_VAL_Pos)
#define SLIB_PWD_CLR_SLIB_PCLR_VAL          SLIB_PWD_CLR_SLIB_PCLR_VAL_Msk          /*!< Security library password clear value */

/*****************  Bit definition for SLIB_MISC_STS register *****************/
#define SLIB_MISC_STS_SLIB_PWD_ERR_Pos      (0U)                                    /*!< 0x00000001 */
#define SLIB_MISC_STS_SLIB_PWD_ERR_Msk      (0x1U << SLIB_MISC_STS_SLIB_PWD_ERR_Pos)
#define SLIB_MISC_STS_SLIB_PWD_ERR          SLIB_MISC_STS_SLIB_PWD_ERR_Msk          /*!< Security library password error */
#define SLIB_MISC_STS_SLIB_PWD_OK_Pos       (1U)
#define SLIB_MISC_STS_SLIB_PWD_OK_Msk       (0x1U << SLIB_MISC_STS_SLIB_PWD_OK_Pos) /*!< 0x00000002 */
#define SLIB_MISC_STS_SLIB_PWD_OK           SLIB_MISC_STS_SLIB_PWD_OK_Msk           /*!< Security library password ok */
#define SLIB_MISC_STS_SLIB_ULKF_Pos         (2U)
#define SLIB_MISC_STS_SLIB_ULKF_Msk         (0x1U << SLIB_MISC_STS_SLIB_ULKF_Pos)   /*!< 0x00000004 */
#define SLIB_MISC_STS_SLIB_ULKF             SLIB_MISC_STS_SLIB_ULKF_Msk             /*!< Security library unlock flag */

/*****************  Bit definition for FLASH_CRC_ARR register *****************/
#define FLASH_CRC_ARR_CRC_ADDR_Pos          (0U)                                    /*!< 0xFFFFFFFF */
#define FLASH_CRC_ARR_CRC_ADDR_Msk          (0xFFFFFFFFU << FLASH_CRC_ARR_CRC_ADDR_Pos)
#define FLASH_CRC_ARR_CRC_ADDR              FLASH_CRC_ARR_CRC_ADDR_Msk              /*!< CRC address */

/****************  Bit definition for FLASH_CRC_CTRL register *****************/
#define FLASH_CRC_CTRL_CRC_SN_Pos           (0U)
#define FLASH_CRC_CTRL_CRC_SN_Msk           (0xFFFFU << FLASH_CRC_CTRL_CRC_SN_Pos)  /*!< 0x0000FFFF */
#define FLASH_CRC_CTRL_CRC_SN               FLASH_CRC_CTRL_CRC_SN_Msk               /*!< CRC page number */
#define FLASH_CRC_CTRL_CRC_STRT_Pos         (16U)
#define FLASH_CRC_CTRL_CRC_STRT_Msk         (0x1U << FLASH_CRC_CTRL_CRC_STRT_Pos)   /*!< 0x00010000 */
#define FLASH_CRC_CTRL_CRC_STRT             FLASH_CRC_CTRL_CRC_STRT_Msk             /*!< CRC start */

/****************  Bit definition for FLASH_CRC_CHKR register *****************/
#define FLASH_CRC_CHKR_CRC_CHKR_Pos         (0U)                                    /*!< 0xFFFFFFFF */
#define FLASH_CRC_CHKR_CRC_CHKR_Msk         (0xFFFFFFFFU << FLASH_CRC_CHKR_CRC_CHKR_Pos)
#define FLASH_CRC_CHKR_CRC_CHKR             FLASH_CRC_CHKR_CRC_CHKR_Msk             /*!< CRC check result */

/*****************  Bit definition for SLIB_SET_PWD register ******************/
#define SLIB_SET_PWD_SLIB_PSET_VAL_Pos      (0U)                                    /*!< 0xFFFFFFFF */
#define SLIB_SET_PWD_SLIB_PSET_VAL_Msk      (0xFFFFFFFFU << SLIB_SET_PWD_SLIB_PSET_VAL_Pos)
#define SLIB_SET_PWD_SLIB_PSET_VAL          SLIB_SET_PWD_SLIB_PSET_VAL_Msk          /*!< sLib password setting value */

/****************  Bit definition for SLIB_SET_RANGE register *****************/
#define SLIB_SET_RANGE_SLIB_SS_SET_Pos      (0U)                                    /*!< 0x000007FF */
#define SLIB_SET_RANGE_SLIB_SS_SET_Msk      (0x7FFU << SLIB_SET_RANGE_SLIB_SS_SET_Pos)
#define SLIB_SET_RANGE_SLIB_SS_SET          SLIB_SET_RANGE_SLIB_SS_SET_Msk          /*!< Security library start page setting */
#define SLIB_SET_RANGE_SLIB_ISS_SET_Pos     (11U)                                   /*!< 0x003FF800 */
#define SLIB_SET_RANGE_SLIB_ISS_SET_Msk     (0x3FF8U << SLIB_SET_RANGE_SLIB_ISS_SET_Pos)
#define SLIB_SET_RANGE_SLIB_ISS_SET         SLIB_SET_RANGE_SLIB_ISS_SET_Msk         /*!< Security library instruction start page setting */
#define SLIB_SET_RANGE_SLIB_ES_SET_Pos      (22U)                                   /*!< 0xFFC00000 */
#define SLIB_SET_RANGE_SLIB_ES_SET_Msk      (0xFFCU << SLIB_SET_RANGE_SLIB_ES_SET_Pos)
#define SLIB_SET_RANGE_SLIB_ES_SET          SLIB_SET_RANGE_SLIB_ES_SET_Msk          /*!< Security library end page setting */

/******************  Bit definition for EM_SLIB_SET register ******************/
#define EM_SLIB_SET_EM_SLIB_SET_Pos         (0U)                                    /*!< 0x0000FFFF */
#define EM_SLIB_SET_EM_SLIB_SET_Msk         (0xFFFFU << EM_SLIB_SET_EM_SLIB_SET_Pos)
#define EM_SLIB_SET_EM_SLIB_SET             EM_SLIB_SET_EM_SLIB_SET_Msk             /*!< Extension memory sLib setting */
#define EM_SLIB_SET_EM_SLIB_ISS_SET_Pos     (16U)                                   /*!< 0x00FF0000 */
#define EM_SLIB_SET_EM_SLIB_ISS_SET_Msk     (0xFFU << EM_SLIB_SET_EM_SLIB_ISS_SET_Pos)
#define EM_SLIB_SET_EM_SLIB_ISS_SET         EM_SLIB_SET_EM_SLIB_ISS_SET_Msk         /*!< Extension memory sLib instruction start page */

/*****************  Bit definition for BTM_MODE_SET register ******************/
#define BTM_MODE_SET_BTM_MODE_SET_Pos       (0U)                                    /*!< 0x000000FF */
#define BTM_MODE_SET_BTM_MODE_SET_Msk       (0xFFU << BTM_MODE_SET_BTM_MODE_SET_Pos)
#define BTM_MODE_SET_BTM_MODE_SET           BTM_MODE_SET_BTM_MODE_SET_Msk           /*!< Boot memory mode setting */

/*****************  Bit definition for SLIB_UNLOCK register ******************/
#define SLIB_UNLOCK_SLIB_UKVAL_Pos          (0U)                                    /*!< 0xFFFFFFFF */
#define SLIB_UNLOCK_SLIB_UKVAL_Msk          (0xFFFFFFFFU << SLIB_UNLOCK_SLIB_UKVAL_Pos)
#define SLIB_UNLOCK_SLIB_UKVAL              SLIB_UNLOCK_SLIB_UKVAL_Msk              /*!< Security library unlock key value */

#define SLIB_KEY_Pos                        (0U)                               
#define SLIB_KEY_Msk                        (0xA35F6D24U << SLIB_KEY_Pos)           /*!< 0xA35F6D24 */
#define SLIB_KEY                            SLIB_KEY_Msk  

/*----------------------------------------------------------------------------*/

/******************  Bit definition for FLASH_FAP register  *******************/
#define FLASH_FAP_FAP_Pos                   (0U)
#define FLASH_FAP_FAP_Msk                   (0xFFU << FLASH_FAP_FAP_Pos)            /*!< 0x000000FF */
#define FLASH_FAP_FAP                       FLASH_FAP_FAP_Msk                       /*!< Flash memory access protection */
#define FLASH_FAP_nFAP_Pos                  (8U)
#define FLASH_FAP_nFAP_Msk                  (0xFFU << FLASH_FAP_nFAP_Pos)           /*!< 0x0000FF00 */
#define FLASH_FAP_nFAP                      FLASH_FAP_nFAP_Msk                      /*!< Inverse code of flash memory access protection */

/******************  Bit definition for FLASH_SSB register  *******************/
#define FLASH_SSB_SSB_Pos                   (16U)
#define FLASH_SSB_SSB_Msk                   (0xFFU << FLASH_SSB_SSB_Pos)            /*!< 0x00FF0000 */
#define FLASH_SSB_SSB                       FLASH_SSB_SSB_Msk                       /*!< System configuration byte */
#define FLASH_SSB_nSSB_Pos                  (24U)
#define FLASH_SSB_nSSB_Msk                  (0xFFU << FLASH_SSB_nSSB_Pos)           /*!< 0xFF000000 */
#define FLASH_SSB_nSSB                      FLASH_SSB_nSSB_Msk                      /*!< Inverse code of system configuration byte */

/******************  Bit definition for FLASH_DATA0 register  *****************/
#define FLASH_DATA0_DATA0_Pos               (0U)
#define FLASH_DATA0_DATA0_Msk               (0xFFU << FLASH_DATA0_DATA0_Pos)        /*!< 0x000000FF */
#define FLASH_DATA0_DATA0                   FLASH_DATA0_DATA0_Msk                   /*!< User data 0 */
#define FLASH_DATA0_nDATA0_Pos              (8U)
#define FLASH_DATA0_nDATA0_Msk              (0xFFU << FLASH_DATA0_nDATA0_Pos)       /*!< 0x0000FF00 */
#define FLASH_DATA0_nDATA0                  FLASH_DATA0_nDATA0_Msk                  /*!< Inverse code of user data 0 */

/******************  Bit definition for FLASH_DATA1 register  *****************/
#define FLASH_DATA1_DATA1_Pos               (16U)
#define FLASH_DATA1_DATA1_Msk               (0xFFU << FLASH_DATA1_DATA1_Pos)        /*!< 0x00FF0000 */
#define FLASH_DATA1_DATA1                   FLASH_DATA1_DATA1_Msk                   /*!< User data 1 */
#define FLASH_DATA1_nDATA1_Pos              (24U)
#define FLASH_DATA1_nDATA1_Msk              (0xFFU << FLASH_DATA1_nDATA1_Pos)       /*!< 0xFF000000 */
#define FLASH_DATA1_nDATA1                  FLASH_DATA1_nDATA1_Msk                  /*!< Inverse code of user data 1 */

/******************  Bit definition for FLASH_EPP0 register  ******************/
#define FLASH_EPP0_EPP0_Pos                 (0U)
#define FLASH_EPP0_EPP0_Msk                 (0xFFU << FLASH_EPP0_EPP0_Pos)          /*!< 0x000000FF */
#define FLASH_EPP0_EPP0                     FLASH_EPP0_EPP0_Msk                     /*!< Flash erase/write protection byte 0 */
#define FLASH_EPP0_nEPP0_Pos                (8U)
#define FLASH_EPP0_nEPP0_Msk                (0xFFU << FLASH_EPP0_nEPP0_Pos)         /*!< 0x0000FF00 */
#define FLASH_EPP0_nEPP0                    FLASH_EPP0_nEPP0_Msk                    /*!< Inverse code of flash erase/write protection byte 0 */

/******************  Bit definition for FLASH_EPP1 register  ******************/
#define FLASH_EPP1_EPP1_Pos                 (16U)
#define FLASH_EPP1_EPP1_Msk                 (0xFFU << FLASH_EPP1_EPP1_Pos)          /*!< 0x00FF0000 */
#define FLASH_EPP1_EPP1                     FLASH_EPP1_EPP1_Msk                     /*!< Flash erase/write protection byte 1 */
#define FLASH_EPP1_nEPP1_Pos                (24U)
#define FLASH_EPP1_nEPP1_Msk                (0xFFU << FLASH_EPP1_nEPP1_Pos)         /*!< 0xFF000000 */
#define FLASH_EPP1_nEPP1                    FLASH_EPP1_nEPP1_Msk                    /*!< Inverse code of flash erase/write protection byte 1 */

/******************  Bit definition for FLASH_EPP2 register  ******************/
#define FLASH_EPP2_EPP2_Pos                 (0U)
#define FLASH_EPP2_EPP2_Msk                 (0xFFU << FLASH_EPP2_EPP2_Pos)          /*!< 0x000000FF */
#define FLASH_EPP2_EPP2                     FLASH_EPP2_EPP2_Msk                     /*!< Flash erase/write protection byte 2 */
#define FLASH_EPP2_nEPP2_Pos                (8U)
#define FLASH_EPP2_nEPP2_Msk                (0xFFU << FLASH_EPP2_nEPP2_Pos)         /*!< 0x0000FF00 */
#define FLASH_EPP2_nEPP2                    FLASH_EPP2_nEPP2_Msk                    /*!< Inverse code of flash erase/write protection byte 2 */

/******************  Bit definition for FLASH_EPP3 register  ******************/
#define FLASH_EPP3_EPP3_Pos                 (16U)
#define FLASH_EPP3_EPP3_Msk                 (0xFFU << FLASH_EPP3_EPP3_Pos)          /*!< 0x00FF0000 */
#define FLASH_EPP3_EPP3                     FLASH_EPP3_EPP3_Msk                     /*!< Flash erase/write protection byte 3 */
#define FLASH_EPP3_nEPP3_Pos                (24U)
#define FLASH_EPP3_nEPP3_Msk                (0xFFU << FLASH_EPP3_nEPP3_Pos)         /*!< 0xFF000000 */
#define FLASH_EPP3_nEPP3                    FLASH_EPP3_nEPP3_Msk                    /*!< Inverse code of flash erase/write protection byte 3 */

/*****************  Bit definition for FLASH_EOPB0 register  ******************/
#define FLASH_EOPB0_EOPB0_Pos               (0U)
#define FLASH_EOPB0_EOPB0_Msk               (0xFFU << FLASH_EOPB0_EOPB0_Pos)        /*!< 0x000000FF */
#define FLASH_EOPB0_EOPB0                   FLASH_EOPB0_EOPB0_Msk                   /*!< Extended system options */
#define FLASH_EOPB0_nEOPB0_Pos              (8U)
#define FLASH_EOPB0_nEOPB0_Msk              (0xFFU << FLASH_EOPB0_nEOPB0_Pos)       /*!< 0x0000FF00 */
#define FLASH_EOPB0_nEOPB0                  FLASH_EOPB0_nEOPB0_Msk                  /*!< Inverse code of extended system options */

/******************  Bit definition for FLASH_DATA2 register  *****************/
#define FLASH_DATA2_DATA2_Pos               (0U)
#define FLASH_DATA2_DATA2_Msk               (0xFFU << FLASH_DATA2_DATA2_Pos)        /*!< 0x000000FF */
#define FLASH_DATA2_DATA2                   FLASH_DATA2_DATA2_Msk                   /*!< User data 2 */
#define FLASH_DATA2_nDATA2_Pos              (8U)
#define FLASH_DATA2_nDATA2_Msk              (0xFFU << FLASH_DATA2_nDATA2_Pos)       /*!< 0x0000FF00 */
#define FLASH_DATA2_nDATA2                  FLASH_DATA2_nDATA2_Msk                  /*!< Inverse code of user data 2 */

/******************  Bit definition for FLASH_DATA3 register  *****************/
#define FLASH_DATA3_DATA3_Pos               (16U)
#define FLASH_DATA3_DATA3_Msk               (0xFFU << FLASH_DATA3_DATA3_Pos)        /*!< 0x00FF0000 */
#define FLASH_DATA3_DATA3                   FLASH_DATA3_DATA3_Msk                   /*!< User data 3 */
#define FLASH_DATA3_nDATA3_Pos              (24U)
#define FLASH_DATA3_nDATA3_Msk              (0xFFU << FLASH_DATA3_nDATA3_Pos)       /*!< 0xFF000000 */
#define FLASH_DATA3_nDATA3                  FLASH_DATA3_nDATA3_Msk                  /*!< Inverse code of user data 3 */

/******************  Bit definition for FLASH_DATA4 register  *****************/
#define FLASH_DATA4_DATA4_Pos               (0U)
#define FLASH_DATA4_DATA4_Msk               (0xFFU << FLASH_DATA4_DATA4_Pos)        /*!< 0x000000FF */
#define FLASH_DATA4_DATA4                   FLASH_DATA4_DATA4_Msk                   /*!< User data 4 */
#define FLASH_DATA4_nDATA4_Pos              (8U)
#define FLASH_DATA4_nDATA4_Msk              (0xFFU << FLASH_DATA4_nDATA4_Pos)       /*!< 0x0000FF00 */
#define FLASH_DATA4_nDATA4                  FLASH_DATA4_nDATA4_Msk                  /*!< Inverse code of user data 4 */

/******************  Bit definition for FLASH_DATA5 register  *****************/
#define FLASH_DATA5_DATA5_Pos               (16U)
#define FLASH_DATA5_DATA5_Msk               (0xFFU << FLASH_DATA5_DATA5_Pos)        /*!< 0x00FF0000 */
#define FLASH_DATA5_DATA5                   FLASH_DATA5_DATA5_Msk                   /*!< User data 5 */
#define FLASH_DATA5_nDATA5_Pos              (24U)
#define FLASH_DATA5_nDATA5_Msk              (0xFFU << FLASH_DATA5_nDATA5_Pos)       /*!< 0xFF000000 */
#define FLASH_DATA5_nDATA5                  FLASH_DATA5_nDATA5_Msk                  /*!< Inverse code of user data 5 */

/******************  Bit definition for FLASH_DATA6 register  *****************/
#define FLASH_DATA6_DATA6_Pos               (0U)
#define FLASH_DATA6_DATA6_Msk               (0xFFU << FLASH_DATA6_DATA6_Pos)        /*!< 0x000000FF */
#define FLASH_DATA6_DATA6                   FLASH_DATA6_DATA6_Msk                   /*!< User data 6 */
#define FLASH_DATA6_nDATA6_Pos              (8U)
#define FLASH_DATA6_nDATA6_Msk              (0xFFU << FLASH_DATA6_nDATA6_Pos)       /*!< 0x0000FF00 */
#define FLASH_DATA6_nDATA6                  FLASH_DATA6_nDATA6_Msk                  /*!< Inverse code of user data 6 */

/******************  Bit definition for FLASH_DATA7 register  *****************/
#define FLASH_DATA7_DATA7_Pos               (16U)
#define FLASH_DATA7_DATA7_Msk               (0xFFU << FLASH_DATA7_DATA7_Pos)        /*!< 0x00FF0000 */
#define FLASH_DATA7_DATA7                   FLASH_DATA7_DATA7_Msk                   /*!< User data 7 */
#define FLASH_DATA7_nDATA7_Pos              (24U)
#define FLASH_DATA7_nDATA7_Msk              (0xFFU << FLASH_DATA7_nDATA7_Pos)       /*!< 0xFF000000 */
#define FLASH_DATA7_nDATA7                  FLASH_DATA7_nDATA7_Msk                  /*!< Inverse code of user data 7 */

/*!< Noted: The FLASH_DATA go up to 505, it too long for added in here */

/******************************************************************************/
/*                                                                            */
/*                        General-purpose I/Os (GPIO)                         */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for GPIO_CFGLR register  ******************/
#define GPIO_CFGLR_IOMC_Pos                 (0U)
#define GPIO_CFGLR_IOMC_Msk                 (0x33333333U << GPIO_CFGLR_IOMC_Pos)    /*!< 0x33333333 */
#define GPIO_CFGLR_IOMC                     GPIO_CFGLR_IOMC_Msk                     /*!< GPIO x mode configuration */

#define GPIO_CFGLR_IOMC0_Pos                (0U)
#define GPIO_CFGLR_IOMC0_Msk                (0x3U << GPIO_CFGLR_IOMC0_Pos)          /*!< 0x00000003 */
#define GPIO_CFGLR_IOMC0                    GPIO_CFGLR_IOMC0_Msk                    /*!< IOMC0[1:0] bits (GPIO x mode configuration, pin 0) */
#define GPIO_CFGLR_IOMC0_0                  (0x1U << GPIO_CFGLR_IOMC0_Pos)          /*!< 0x00000001 */
#define GPIO_CFGLR_IOMC0_1                  (0x2U << GPIO_CFGLR_IOMC0_Pos)          /*!< 0x00000002 */

#define GPIO_CFGLR_IOMC1_Pos                (4U)
#define GPIO_CFGLR_IOMC1_Msk                (0x3U << GPIO_CFGLR_IOMC1_Pos)          /*!< 0x00000030 */
#define GPIO_CFGLR_IOMC1                    GPIO_CFGLR_IOMC1_Msk                    /*!< IOMC1[1:0] bits (GPIO x mode configuration, pin 1) */
#define GPIO_CFGLR_IOMC1_0                  (0x1U << GPIO_CFGLR_IOMC1_Pos)          /*!< 0x00000010 */
#define GPIO_CFGLR_IOMC1_1                  (0x2U << GPIO_CFGLR_IOMC1_Pos)          /*!< 0x00000020 */

#define GPIO_CFGLR_IOMC2_Pos                (8U)
#define GPIO_CFGLR_IOMC2_Msk                (0x3U << GPIO_CFGLR_IOMC2_Pos)          /*!< 0x00000300 */
#define GPIO_CFGLR_IOMC2                    GPIO_CFGLR_IOMC2_Msk                    /*!< IOMC2[1:0] bits (GPIO x mode configuration, pin 2) */
#define GPIO_CFGLR_IOMC2_0                  (0x1U << GPIO_CFGLR_IOMC2_Pos)          /*!< 0x00000100 */
#define GPIO_CFGLR_IOMC2_1                  (0x2U << GPIO_CFGLR_IOMC2_Pos)          /*!< 0x00000200 */

#define GPIO_CFGLR_IOMC3_Pos                (12U)
#define GPIO_CFGLR_IOMC3_Msk                (0x3U << GPIO_CFGLR_IOMC3_Pos)          /*!< 0x00003000 */
#define GPIO_CFGLR_IOMC3                    GPIO_CFGLR_IOMC3_Msk                    /*!< IOMC3[1:0] bits (GPIO x mode configuration, pin 3) */
#define GPIO_CFGLR_IOMC3_0                  (0x1U << GPIO_CFGLR_IOMC3_Pos)          /*!< 0x00001000 */
#define GPIO_CFGLR_IOMC3_1                  (0x2U << GPIO_CFGLR_IOMC3_Pos)          /*!< 0x00002000 */

#define GPIO_CFGLR_IOMC4_Pos                (16U)
#define GPIO_CFGLR_IOMC4_Msk                (0x3U << GPIO_CFGLR_IOMC4_Pos)          /*!< 0x00030000 */
#define GPIO_CFGLR_IOMC4                    GPIO_CFGLR_IOMC4_Msk                    /*!< IOMC4[1:0] bits (GPIO x mode configuration, pin 4) */
#define GPIO_CFGLR_IOMC4_0                  (0x1U << GPIO_CFGLR_IOMC4_Pos)          /*!< 0x00010000 */
#define GPIO_CFGLR_IOMC4_1                  (0x2U << GPIO_CFGLR_IOMC4_Pos)          /*!< 0x00020000 */

#define GPIO_CFGLR_IOMC5_Pos                (20U)
#define GPIO_CFGLR_IOMC5_Msk                (0x3U << GPIO_CFGLR_IOMC5_Pos)          /*!< 0x00300000 */
#define GPIO_CFGLR_IOMC5                    GPIO_CFGLR_IOMC5_Msk                    /*!< IOMC5[1:0] bits (GPIO x mode configuration, pin 5) */
#define GPIO_CFGLR_IOMC5_0                  (0x1U << GPIO_CFGLR_IOMC5_Pos)          /*!< 0x00100000 */
#define GPIO_CFGLR_IOMC5_1                  (0x2U << GPIO_CFGLR_IOMC5_Pos)          /*!< 0x00200000 */

#define GPIO_CFGLR_IOMC6_Pos                (24U)
#define GPIO_CFGLR_IOMC6_Msk                (0x3U << GPIO_CFGLR_IOMC6_Pos)          /*!< 0x03000000 */
#define GPIO_CFGLR_IOMC6                    GPIO_CFGLR_IOMC6_Msk                    /*!< IOMC6[1:0] bits (GPIO x mode configuration, pin 6) */
#define GPIO_CFGLR_IOMC6_0                  (0x1U << GPIO_CFGLR_IOMC6_Pos)          /*!< 0x01000000 */
#define GPIO_CFGLR_IOMC6_1                  (0x2U << GPIO_CFGLR_IOMC6_Pos)          /*!< 0x02000000 */

#define GPIO_CFGLR_IOMC7_Pos                (28U)
#define GPIO_CFGLR_IOMC7_Msk                (0x3U << GPIO_CFGLR_IOMC7_Pos)          /*!< 0x30000000 */
#define GPIO_CFGLR_IOMC7                    GPIO_CFGLR_IOMC7_Msk                    /*!< IOMC7[1:0] bits (GPIO x mode configuration, pin 7) */
#define GPIO_CFGLR_IOMC7_0                  (0x1U << GPIO_CFGLR_IOMC7_Pos)          /*!< 0x10000000 */
#define GPIO_CFGLR_IOMC7_1                  (0x2U << GPIO_CFGLR_IOMC7_Pos)          /*!< 0x20000000 */

#define GPIO_CFGLR_IOFC_Pos                 (2U)
#define GPIO_CFGLR_IOFC_Msk                 (0x33333333U << GPIO_CFGLR_IOFC_Pos)    /*!< 0xCCCCCCCC */
#define GPIO_CFGLR_IOFC                     GPIO_CFGLR_IOFC_Msk                     /*!< GPIO x function configuration */

#define GPIO_CFGLR_IOFC0_Pos                (2U)
#define GPIO_CFGLR_IOFC0_Msk                (0x3U << GPIO_CFGLR_IOFC0_Pos)          /*!< 0x0000000C */
#define GPIO_CFGLR_IOFC0                    GPIO_CFGLR_IOFC0_Msk                    /*!< IOFC0[1:0] bits (GPIO x function configuration, pin 0) */
#define GPIO_CFGLR_IOFC0_0                  (0x1U << GPIO_CFGLR_IOFC0_Pos)          /*!< 0x00000004 */
#define GPIO_CFGLR_IOFC0_1                  (0x2U << GPIO_CFGLR_IOFC0_Pos)          /*!< 0x00000008 */

#define GPIO_CFGLR_IOFC1_Pos                (6U)
#define GPIO_CFGLR_IOFC1_Msk                (0x3U << GPIO_CFGLR_IOFC1_Pos)          /*!< 0x000000C0 */
#define GPIO_CFGLR_IOFC1                    GPIO_CFGLR_IOFC1_Msk                    /*!< IOFC1[1:0] bits (GPIO x function configuration, pin 1) */
#define GPIO_CFGLR_IOFC1_0                  (0x1U << GPIO_CFGLR_IOFC1_Pos)          /*!< 0x00000040 */
#define GPIO_CFGLR_IOFC1_1                  (0x2U << GPIO_CFGLR_IOFC1_Pos)          /*!< 0x00000080 */

#define GPIO_CFGLR_IOFC2_Pos                (10U)
#define GPIO_CFGLR_IOFC2_Msk                (0x3U << GPIO_CFGLR_IOFC2_Pos)          /*!< 0x00000C00 */
#define GPIO_CFGLR_IOFC2                    GPIO_CFGLR_IOFC2_Msk                    /*!< IOFC2[1:0] bits (GPIO x function configuration, pin 2) */
#define GPIO_CFGLR_IOFC2_0                  (0x1U << GPIO_CFGLR_IOFC2_Pos)          /*!< 0x00000400 */
#define GPIO_CFGLR_IOFC2_1                  (0x2U << GPIO_CFGLR_IOFC2_Pos)          /*!< 0x00000800 */

#define GPIO_CFGLR_IOFC3_Pos                (14U)
#define GPIO_CFGLR_IOFC3_Msk                (0x3U << GPIO_CFGLR_IOFC3_Pos)          /*!< 0x0000C000 */
#define GPIO_CFGLR_IOFC3                    GPIO_CFGLR_IOFC3_Msk                    /*!< IOFC3[1:0] bits (GPIO x function configuration, pin 3) */
#define GPIO_CFGLR_IOFC3_0                  (0x1U << GPIO_CFGLR_IOFC3_Pos)          /*!< 0x00004000 */
#define GPIO_CFGLR_IOFC3_1                  (0x2U << GPIO_CFGLR_IOFC3_Pos)          /*!< 0x00008000 */

#define GPIO_CFGLR_IOFC4_Pos                (18U)
#define GPIO_CFGLR_IOFC4_Msk                (0x3U << GPIO_CFGLR_IOFC4_Pos)          /*!< 0x000C0000 */
#define GPIO_CFGLR_IOFC4                    GPIO_CFGLR_IOFC4_Msk                    /*!< IOFC4[1:0] bits (GPIO x function configuration, pin 4) */
#define GPIO_CFGLR_IOFC4_0                  (0x1U << GPIO_CFGLR_IOFC4_Pos)          /*!< 0x00040000 */
#define GPIO_CFGLR_IOFC4_1                  (0x2U << GPIO_CFGLR_IOFC4_Pos)          /*!< 0x00080000 */

#define GPIO_CFGLR_IOFC5_Pos                (22U)
#define GPIO_CFGLR_IOFC5_Msk                (0x3U << GPIO_CFGLR_IOFC5_Pos)          /*!< 0x00C00000 */
#define GPIO_CFGLR_IOFC5                    GPIO_CFGLR_IOFC5_Msk                    /*!< IOFC5[1:0] bits (GPIO x function configuration, pin 5) */
#define GPIO_CFGLR_IOFC5_0                  (0x1U << GPIO_CFGLR_IOFC5_Pos)          /*!< 0x00400000 */
#define GPIO_CFGLR_IOFC5_1                  (0x2U << GPIO_CFGLR_IOFC5_Pos)          /*!< 0x00800000 */

#define GPIO_CFGLR_IOFC6_Pos                (26U)
#define GPIO_CFGLR_IOFC6_Msk                (0x3U << GPIO_CFGLR_IOFC6_Pos)          /*!< 0x0C000000 */
#define GPIO_CFGLR_IOFC6                    GPIO_CFGLR_IOFC6_Msk                    /*!< IOFC6[1:0] bits (GPIO x function configuration, pin 6) */
#define GPIO_CFGLR_IOFC6_0                  (0x1U << GPIO_CFGLR_IOFC6_Pos)          /*!< 0x04000000 */
#define GPIO_CFGLR_IOFC6_1                  (0x2U << GPIO_CFGLR_IOFC6_Pos)          /*!< 0x08000000 */

#define GPIO_CFGLR_IOFC7_Pos                (30U)
#define GPIO_CFGLR_IOFC7_Msk                (0x3U << GPIO_CFGLR_IOFC7_Pos)          /*!< 0xC0000000 */
#define GPIO_CFGLR_IOFC7                    GPIO_CFGLR_IOFC7_Msk                    /*!< IOFC7[1:0] bits (GPIO x function configuration, pin 7) */
#define GPIO_CFGLR_IOFC7_0                  (0x1U << GPIO_CFGLR_IOFC7_Pos)          /*!< 0x40000000 */
#define GPIO_CFGLR_IOFC7_1                  (0x2U << GPIO_CFGLR_IOFC7_Pos)          /*!< 0x80000000 */

/******************  Bit definition for GPIO_CFGHR register  ******************/
#define GPIO_CFGHR_IOMC_Pos                 (0U)
#define GPIO_CFGHR_IOMC_Msk                 (0x33333333U << GPIO_CFGHR_IOMC_Pos)    /*!< 0x33333333 */
#define GPIO_CFGHR_IOMC                     GPIO_CFGHR_IOMC_Msk                     /*!< GPIO x mode configuration */

#define GPIO_CFGHR_IOMC8_Pos                (0U)
#define GPIO_CFGHR_IOMC8_Msk                (0x3U << GPIO_CFGHR_IOMC8_Pos)          /*!< 0x00000003 */
#define GPIO_CFGHR_IOMC8                    GPIO_CFGHR_IOMC8_Msk                    /*!< IOMC8[1:0] bits (GPIO x mode configuration, pin 8) */
#define GPIO_CFGHR_IOMC8_0                  (0x1U << GPIO_CFGHR_IOMC8_Pos)          /*!< 0x00000001 */
#define GPIO_CFGHR_IOMC8_1                  (0x2U << GPIO_CFGHR_IOMC8_Pos)          /*!< 0x00000002 */

#define GPIO_CFGHR_IOMC9_Pos                (4U)
#define GPIO_CFGHR_IOMC9_Msk                (0x3U << GPIO_CFGHR_IOMC9_Pos)          /*!< 0x00000030 */
#define GPIO_CFGHR_IOMC9                    GPIO_CFGHR_IOMC9_Msk                    /*!< IOMC9[1:0] bits (GPIO x mode configuration, pin 9) */
#define GPIO_CFGHR_IOMC9_0                  (0x1U << GPIO_CFGHR_IOMC9_Pos)          /*!< 0x00000010 */
#define GPIO_CFGHR_IOMC9_1                  (0x2U << GPIO_CFGHR_IOMC9_Pos)          /*!< 0x00000020 */

#define GPIO_CFGHR_IOMC10_Pos               (8U)
#define GPIO_CFGHR_IOMC10_Msk               (0x3U << GPIO_CFGHR_IOMC10_Pos)         /*!< 0x00000300 */
#define GPIO_CFGHR_IOMC10                   GPIO_CFGHR_IOMC10_Msk                   /*!< IOMC10[1:0] bits (GPIO x mode configuration, pin 10) */
#define GPIO_CFGHR_IOMC10_0                 (0x1U << GPIO_CFGHR_IOMC10_Pos)         /*!< 0x00000100 */
#define GPIO_CFGHR_IOMC10_1                 (0x2U << GPIO_CFGHR_IOMC10_Pos)         /*!< 0x00000200 */

#define GPIO_CFGHR_IOMC11_Pos               (12U)
#define GPIO_CFGHR_IOMC11_Msk               (0x3U << GPIO_CFGHR_IOMC11_Pos)         /*!< 0x00003000 */
#define GPIO_CFGHR_IOMC11                   GPIO_CFGHR_IOMC11_Msk                   /*!< IOMC11[1:0] bits (GPIO x mode configuration, pin 11) */
#define GPIO_CFGHR_IOMC11_0                 (0x1U << GPIO_CFGHR_IOMC11_Pos)         /*!< 0x00001000 */
#define GPIO_CFGHR_IOMC11_1                 (0x2U << GPIO_CFGHR_IOMC11_Pos)         /*!< 0x00002000 */

#define GPIO_CFGHR_IOMC12_Pos               (16U)
#define GPIO_CFGHR_IOMC12_Msk               (0x3U << GPIO_CFGHR_IOMC12_Pos)         /*!< 0x00030000 */
#define GPIO_CFGHR_IOMC12                   GPIO_CFGHR_IOMC12_Msk                   /*!< IOMC12[1:0] bits (GPIO x mode configuration, pin 12) */
#define GPIO_CFGHR_IOMC12_0                 (0x1U << GPIO_CFGHR_IOMC12_Pos)         /*!< 0x00010000 */
#define GPIO_CFGHR_IOMC12_1                 (0x2U << GPIO_CFGHR_IOMC12_Pos)         /*!< 0x00020000 */

#define GPIO_CFGHR_IOMC13_Pos               (20U)
#define GPIO_CFGHR_IOMC13_Msk               (0x3U << GPIO_CFGHR_IOMC13_Pos)         /*!< 0x00300000 */
#define GPIO_CFGHR_IOMC13                   GPIO_CFGHR_IOMC13_Msk                   /*!< IOMC13[1:0] bits (GPIO x mode configuration, pin 13) */
#define GPIO_CFGHR_IOMC13_0                 (0x1U << GPIO_CFGHR_IOMC13_Pos)         /*!< 0x00100000 */
#define GPIO_CFGHR_IOMC13_1                 (0x2U << GPIO_CFGHR_IOMC13_Pos)         /*!< 0x00200000 */

#define GPIO_CFGHR_IOMC14_Pos               (24U)
#define GPIO_CFGHR_IOMC14_Msk               (0x3U << GPIO_CFGHR_IOMC14_Pos)         /*!< 0x03000000 */
#define GPIO_CFGHR_IOMC14                   GPIO_CFGHR_IOMC14_Msk                   /*!< IOMC14[1:0] bits (GPIO x mode configuration, pin 14) */
#define GPIO_CFGHR_IOMC14_0                 (0x1U << GPIO_CFGHR_IOMC14_Pos)         /*!< 0x01000000 */
#define GPIO_CFGHR_IOMC14_1                 (0x2U << GPIO_CFGHR_IOMC14_Pos)         /*!< 0x02000000 */

#define GPIO_CFGHR_IOMC15_Pos               (28U)
#define GPIO_CFGHR_IOMC15_Msk               (0x3U << GPIO_CFGHR_IOMC15_Pos)         /*!< 0x30000000 */
#define GPIO_CFGHR_IOMC15                   GPIO_CFGHR_IOMC15_Msk                   /*!< IOMC15[1:0] bits (GPIO x mode configuration, pin 15) */
#define GPIO_CFGHR_IOMC15_0                 (0x1U << GPIO_CFGHR_IOMC15_Pos)         /*!< 0x10000000 */
#define GPIO_CFGHR_IOMC15_1                 (0x2U << GPIO_CFGHR_IOMC15_Pos)         /*!< 0x20000000 */

#define GPIO_CFGHR_IOFC_Pos                 (2U)
#define GPIO_CFGHR_IOFC_Msk                 (0x33333333U << GPIO_CFGHR_IOFC_Pos)    /*!< 0xCCCCCCCC */
#define GPIO_CFGHR_IOFC                     GPIO_CFGHR_IOFC_Msk                     /*!< GPIO x function configuration */

#define GPIO_CFGHR_IOFC8_Pos                (2U)
#define GPIO_CFGHR_IOFC8_Msk                (0x3U << GPIO_CFGHR_IOFC8_Pos)          /*!< 0x0000000C */
#define GPIO_CFGHR_IOFC8                    GPIO_CFGHR_IOFC8_Msk                    /*!< IOFC8[1:0] bits (GPIO x function configuration, pin 8) */
#define GPIO_CFGHR_IOFC8_0                  (0x1U << GPIO_CFGHR_IOFC8_Pos)          /*!< 0x00000004 */
#define GPIO_CFGHR_IOFC8_1                  (0x2U << GPIO_CFGHR_IOFC8_Pos)          /*!< 0x00000008 */

#define GPIO_CFGHR_IOFC9_Pos                (6U)
#define GPIO_CFGHR_IOFC9_Msk                (0x3U << GPIO_CFGHR_IOFC9_Pos)          /*!< 0x000000C0 */
#define GPIO_CFGHR_IOFC9                    GPIO_CFGHR_IOFC9_Msk                    /*!< IOFC9[1:0] bits (GPIO x function configuration, pin 9) */
#define GPIO_CFGHR_IOFC9_0                  (0x1U << GPIO_CFGHR_IOFC9_Pos)          /*!< 0x00000040 */
#define GPIO_CFGHR_IOFC9_1                  (0x2U << GPIO_CFGHR_IOFC9_Pos)          /*!< 0x00000080 */

#define GPIO_CFGHR_IOFC10_Pos               (10U)
#define GPIO_CFGHR_IOFC10_Msk               (0x3U << GPIO_CFGHR_IOFC10_Pos)         /*!< 0x00000C00 */
#define GPIO_CFGHR_IOFC10                   GPIO_CFGHR_IOFC10_Msk                   /*!< IOFC10[1:0] bits (GPIO x function configuration, pin 10) */
#define GPIO_CFGHR_IOFC10_0                 (0x1U << GPIO_CFGHR_IOFC10_Pos)         /*!< 0x00000400 */
#define GPIO_CFGHR_IOFC10_1                 (0x2U << GPIO_CFGHR_IOFC10_Pos)         /*!< 0x00000800 */

#define GPIO_CFGHR_IOFC11_Pos               (14U)
#define GPIO_CFGHR_IOFC11_Msk               (0x3U << GPIO_CFGHR_IOFC11_Pos)         /*!< 0x0000C000 */
#define GPIO_CFGHR_IOFC11                   GPIO_CFGHR_IOFC11_Msk                   /*!< IOFC11[1:0] bits (GPIO x function configuration, pin 11) */
#define GPIO_CFGHR_IOFC11_0                 (0x1U << GPIO_CFGHR_IOFC11_Pos)         /*!< 0x00004000 */
#define GPIO_CFGHR_IOFC11_1                 (0x2U << GPIO_CFGHR_IOFC11_Pos)         /*!< 0x00008000 */

#define GPIO_CFGHR_IOFC12_Pos               (18U)
#define GPIO_CFGHR_IOFC12_Msk               (0x3U << GPIO_CFGHR_IOFC12_Pos)         /*!< 0x000C0000 */
#define GPIO_CFGHR_IOFC12                   GPIO_CFGHR_IOFC12_Msk                   /*!< IOFC12[1:0] bits (GPIO x function configuration, pin 12) */
#define GPIO_CFGHR_IOFC12_0                 (0x1U << GPIO_CFGHR_IOFC12_Pos)         /*!< 0x00040000 */
#define GPIO_CFGHR_IOFC12_1                 (0x2U << GPIO_CFGHR_IOFC12_Pos)         /*!< 0x00080000 */

#define GPIO_CFGHR_IOFC13_Pos               (22U)
#define GPIO_CFGHR_IOFC13_Msk               (0x3U << GPIO_CFGHR_IOFC13_Pos)         /*!< 0x00C00000 */
#define GPIO_CFGHR_IOFC13                   GPIO_CFGHR_IOFC13_Msk                   /*!< IOFC13[1:0] bits (GPIO x function configuration, pin 13) */
#define GPIO_CFGHR_IOFC13_0                 (0x1U << GPIO_CFGHR_IOFC13_Pos)         /*!< 0x00400000 */
#define GPIO_CFGHR_IOFC13_1                 (0x2U << GPIO_CFGHR_IOFC13_Pos)         /*!< 0x00800000 */

#define GPIO_CFGHR_IOFC14_Pos               (26U)
#define GPIO_CFGHR_IOFC14_Msk               (0x3U << GPIO_CFGHR_IOFC14_Pos)         /*!< 0x0C000000 */
#define GPIO_CFGHR_IOFC14                   GPIO_CFGHR_IOFC14_Msk                   /*!< IOFC14[1:0] bits (GPIO x function configuration, pin 14) */
#define GPIO_CFGHR_IOFC14_0                 (0x1U << GPIO_CFGHR_IOFC14_Pos)         /*!< 0x04000000 */
#define GPIO_CFGHR_IOFC14_1                 (0x2U << GPIO_CFGHR_IOFC14_Pos)         /*!< 0x08000000 */

#define GPIO_CFGHR_IOFC15_Pos               (30U)
#define GPIO_CFGHR_IOFC15_Msk               (0x3U << GPIO_CFGHR_IOFC15_Pos)         /*!< 0xC0000000 */
#define GPIO_CFGHR_IOFC15                   GPIO_CFGHR_IOFC15_Msk                   /*!< IOFC15[1:0] bits (GPIO x function configuration, pin 15) */
#define GPIO_CFGHR_IOFC15_0                 (0x1U << GPIO_CFGHR_IOFC15_Pos)         /*!< 0x40000000 */
#define GPIO_CFGHR_IOFC15_1                 (0x2U << GPIO_CFGHR_IOFC15_Pos)         /*!< 0x80000000 */

/*!<****************  Bit definition for GPIO_IDT register  *******************/
#define GPIO_IDT_IDT0_Pos                   (0U)
#define GPIO_IDT_IDT0_Msk                   (0x1U << GPIO_IDT_IDT0_Pos)             /*!< 0x00000001 */
#define GPIO_IDT_IDT0                       GPIO_IDT_IDT0_Msk                       /*!< GPIO x input data, bit 0 */
#define GPIO_IDT_IDT1_Pos                   (1U)
#define GPIO_IDT_IDT1_Msk                   (0x1U << GPIO_IDT_IDT1_Pos)             /*!< 0x00000002 */
#define GPIO_IDT_IDT1                       GPIO_IDT_IDT1_Msk                       /*!< GPIO x input data, bit 1 */
#define GPIO_IDT_IDT2_Pos                   (2U)
#define GPIO_IDT_IDT2_Msk                   (0x1U << GPIO_IDT_IDT2_Pos)             /*!< 0x00000004 */
#define GPIO_IDT_IDT2                       GPIO_IDT_IDT2_Msk                       /*!< GPIO x input data, bit 2 */
#define GPIO_IDT_IDT3_Pos                   (3U)
#define GPIO_IDT_IDT3_Msk                   (0x1U << GPIO_IDT_IDT3_Pos)             /*!< 0x00000008 */
#define GPIO_IDT_IDT3                       GPIO_IDT_IDT3_Msk                       /*!< GPIO x input data, bit 3 */
#define GPIO_IDT_IDT4_Pos                   (4U)
#define GPIO_IDT_IDT4_Msk                   (0x1U << GPIO_IDT_IDT4_Pos)             /*!< 0x00000010 */
#define GPIO_IDT_IDT4                       GPIO_IDT_IDT4_Msk                       /*!< GPIO x input data, bit 4 */
#define GPIO_IDT_IDT5_Pos                   (5U)
#define GPIO_IDT_IDT5_Msk                   (0x1U << GPIO_IDT_IDT5_Pos)             /*!< 0x00000020 */
#define GPIO_IDT_IDT5                       GPIO_IDT_IDT5_Msk                       /*!< GPIO x input data, bit 5 */
#define GPIO_IDT_IDT6_Pos                   (6U)
#define GPIO_IDT_IDT6_Msk                   (0x1U << GPIO_IDT_IDT6_Pos)             /*!< 0x00000040 */
#define GPIO_IDT_IDT6                       GPIO_IDT_IDT6_Msk                       /*!< GPIO x input data, bit 6 */
#define GPIO_IDT_IDT7_Pos                   (7U)
#define GPIO_IDT_IDT7_Msk                   (0x1U << GPIO_IDT_IDT7_Pos)             /*!< 0x00000080 */
#define GPIO_IDT_IDT7                       GPIO_IDT_IDT7_Msk                       /*!< GPIO x input data, bit 7 */
#define GPIO_IDT_IDT8_Pos                   (8U)
#define GPIO_IDT_IDT8_Msk                   (0x1U << GPIO_IDT_IDT8_Pos)             /*!< 0x00000100 */
#define GPIO_IDT_IDT8                       GPIO_IDT_IDT8_Msk                       /*!< GPIO x input data, bit 8 */
#define GPIO_IDT_IDT9_Pos                   (9U)
#define GPIO_IDT_IDT9_Msk                   (0x1U << GPIO_IDT_IDT9_Pos)             /*!< 0x00000200 */
#define GPIO_IDT_IDT9                       GPIO_IDT_IDT9_Msk                       /*!< GPIO x input data, bit 9 */
#define GPIO_IDT_IDT10_Pos                  (10U)
#define GPIO_IDT_IDT10_Msk                  (0x1U << GPIO_IDT_IDT10_Pos)            /*!< 0x00000400 */
#define GPIO_IDT_IDT10                      GPIO_IDT_IDT10_Msk                      /*!< GPIO x input data, bit 10 */
#define GPIO_IDT_IDT11_Pos                  (11U)
#define GPIO_IDT_IDT11_Msk                  (0x1U << GPIO_IDT_IDT11_Pos)            /*!< 0x00000800 */
#define GPIO_IDT_IDT11                      GPIO_IDT_IDT11_Msk                      /*!< GPIO x input data, bit 11 */
#define GPIO_IDT_IDT12_Pos                  (12U)
#define GPIO_IDT_IDT12_Msk                  (0x1U << GPIO_IDT_IDT12_Pos)            /*!< 0x00001000 */
#define GPIO_IDT_IDT12                      GPIO_IDT_IDT12_Msk                      /*!< GPIO x input data, bit 12 */
#define GPIO_IDT_IDT13_Pos                  (13U)
#define GPIO_IDT_IDT13_Msk                  (0x1U << GPIO_IDT_IDT13_Pos)            /*!< 0x00002000 */
#define GPIO_IDT_IDT13                      GPIO_IDT_IDT13_Msk                      /*!< GPIO x input data, bit 13 */
#define GPIO_IDT_IDT14_Pos                  (14U)
#define GPIO_IDT_IDT14_Msk                  (0x1U << GPIO_IDT_IDT14_Pos)            /*!< 0x00004000 */
#define GPIO_IDT_IDT14                      GPIO_IDT_IDT14_Msk                      /*!< GPIO x input data, bit 14 */
#define GPIO_IDT_IDT15_Pos                  (15U)
#define GPIO_IDT_IDT15_Msk                  (0x1U << GPIO_IDT_IDT15_Pos)            /*!< 0x00008000 */
#define GPIO_IDT_IDT15                      GPIO_IDT_IDT15_Msk                      /*!< GPIO x input data, bit 15 */

/*******************  Bit definition for GPIO_ODT register  *******************/
#define GPIO_ODT_ODT0_Pos                   (0U)
#define GPIO_ODT_ODT0_Msk                   (0x1U << GPIO_ODT_ODT0_Pos)             /*!< 0x00000001 */
#define GPIO_ODT_ODT0                       GPIO_ODT_ODT0_Msk                       /*!< GPIO x output data, bit 0 */
#define GPIO_ODT_ODT1_Pos                   (1U)
#define GPIO_ODT_ODT1_Msk                   (0x1U << GPIO_ODT_ODT1_Pos)             /*!< 0x00000002 */
#define GPIO_ODT_ODT1                       GPIO_ODT_ODT1_Msk                       /*!< GPIO x output data, bit 1 */
#define GPIO_ODT_ODT2_Pos                   (2U)
#define GPIO_ODT_ODT2_Msk                   (0x1U << GPIO_ODT_ODT2_Pos)             /*!< 0x00000004 */
#define GPIO_ODT_ODT2                       GPIO_ODT_ODT2_Msk                       /*!< GPIO x output data, bit 2 */
#define GPIO_ODT_ODT3_Pos                   (3U)
#define GPIO_ODT_ODT3_Msk                   (0x1U << GPIO_ODT_ODT3_Pos)             /*!< 0x00000008 */
#define GPIO_ODT_ODT3                       GPIO_ODT_ODT3_Msk                       /*!< GPIO x output data, bit 3 */
#define GPIO_ODT_ODT4_Pos                   (4U)
#define GPIO_ODT_ODT4_Msk                   (0x1U << GPIO_ODT_ODT4_Pos)             /*!< 0x00000010 */
#define GPIO_ODT_ODT4                       GPIO_ODT_ODT4_Msk                       /*!< GPIO x output data, bit 4 */
#define GPIO_ODT_ODT5_Pos                   (5U)
#define GPIO_ODT_ODT5_Msk                   (0x1U << GPIO_ODT_ODT5_Pos)             /*!< 0x00000020 */
#define GPIO_ODT_ODT5                       GPIO_ODT_ODT5_Msk                       /*!< GPIO x output data, bit 5 */
#define GPIO_ODT_ODT6_Pos                   (6U)
#define GPIO_ODT_ODT6_Msk                   (0x1U << GPIO_ODT_ODT6_Pos)             /*!< 0x00000040 */
#define GPIO_ODT_ODT6                       GPIO_ODT_ODT6_Msk                       /*!< GPIO x output data, bit 6 */
#define GPIO_ODT_ODT7_Pos                   (7U)
#define GPIO_ODT_ODT7_Msk                   (0x1U << GPIO_ODT_ODT7_Pos)             /*!< 0x00000080 */
#define GPIO_ODT_ODT7                       GPIO_ODT_ODT7_Msk                       /*!< GPIO x output data, bit 7 */
#define GPIO_ODT_ODT8_Pos                   (8U)
#define GPIO_ODT_ODT8_Msk                   (0x1U << GPIO_ODT_ODT8_Pos)             /*!< 0x00000100 */
#define GPIO_ODT_ODT8                       GPIO_ODT_ODT8_Msk                       /*!< GPIO x output data, bit 8 */
#define GPIO_ODT_ODT9_Pos                   (9U)
#define GPIO_ODT_ODT9_Msk                   (0x1U << GPIO_ODT_ODT9_Pos)             /*!< 0x00000200 */
#define GPIO_ODT_ODT9                       GPIO_ODT_ODT9_Msk                       /*!< GPIO x output data, bit 9 */
#define GPIO_ODT_ODT10_Pos                  (10U)
#define GPIO_ODT_ODT10_Msk                  (0x1U << GPIO_ODT_ODT10_Pos)            /*!< 0x00000400 */
#define GPIO_ODT_ODT10                      GPIO_ODT_ODT10_Msk                      /*!< GPIO x output data, bit 10 */
#define GPIO_ODT_ODT11_Pos                  (11U)
#define GPIO_ODT_ODT11_Msk                  (0x1U << GPIO_ODT_ODT11_Pos)            /*!< 0x00000800 */
#define GPIO_ODT_ODT11                      GPIO_ODT_ODT11_Msk                      /*!< GPIO x output data, bit 11 */
#define GPIO_ODT_ODT12_Pos                  (12U)
#define GPIO_ODT_ODT12_Msk                  (0x1U << GPIO_ODT_ODT12_Pos)            /*!< 0x00001000 */
#define GPIO_ODT_ODT12                      GPIO_ODT_ODT12_Msk                      /*!< GPIO x output data, bit 12 */
#define GPIO_ODT_ODT13_Pos                  (13U)
#define GPIO_ODT_ODT13_Msk                  (0x1U << GPIO_ODT_ODT13_Pos)            /*!< 0x00002000 */
#define GPIO_ODT_ODT13                      GPIO_ODT_ODT13_Msk                      /*!< GPIO x output data, bit 13 */
#define GPIO_ODT_ODT14_Pos                  (14U)
#define GPIO_ODT_ODT14_Msk                  (0x1U << GPIO_ODT_ODT14_Pos)            /*!< 0x00004000 */
#define GPIO_ODT_ODT14                      GPIO_ODT_ODT14_Msk                      /*!< GPIO x output data, bit 14 */
#define GPIO_ODT_ODT15_Pos                  (15U)
#define GPIO_ODT_ODT15_Msk                  (0x1U << GPIO_ODT_ODT15_Pos)            /*!< 0x00008000 */
#define GPIO_ODT_ODT15                      GPIO_ODT_ODT15_Msk                      /*!< GPIO x output data, bit 15 */

/*******************  Bit definition for GPIO_SCR register  *******************/
#define GPIO_SCR_IOSB0_Pos                  (0U)
#define GPIO_SCR_IOSB0_Msk                  (0x1U << GPIO_SCR_IOSB0_Pos)            /*!< 0x00000001 */
#define GPIO_SCR_IOSB0                      GPIO_SCR_IOSB0_Msk                      /*!< GPIO x set bit 0 */
#define GPIO_SCR_IOSB1_Pos                  (1U)
#define GPIO_SCR_IOSB1_Msk                  (0x1U << GPIO_SCR_IOSB1_Pos)            /*!< 0x00000002 */
#define GPIO_SCR_IOSB1                      GPIO_SCR_IOSB1_Msk                      /*!< GPIO x set bit 1 */
#define GPIO_SCR_IOSB2_Pos                  (2U)
#define GPIO_SCR_IOSB2_Msk                  (0x1U << GPIO_SCR_IOSB2_Pos)            /*!< 0x00000004 */
#define GPIO_SCR_IOSB2                      GPIO_SCR_IOSB2_Msk                      /*!< GPIO x set bit 2 */
#define GPIO_SCR_IOSB3_Pos                  (3U)
#define GPIO_SCR_IOSB3_Msk                  (0x1U << GPIO_SCR_IOSB3_Pos)            /*!< 0x00000008 */
#define GPIO_SCR_IOSB3                      GPIO_SCR_IOSB3_Msk                      /*!< GPIO x set bit 3 */
#define GPIO_SCR_IOSB4_Pos                  (4U)
#define GPIO_SCR_IOSB4_Msk                  (0x1U << GPIO_SCR_IOSB4_Pos)            /*!< 0x00000010 */
#define GPIO_SCR_IOSB4                      GPIO_SCR_IOSB4_Msk                      /*!< GPIO x set bit 4 */
#define GPIO_SCR_IOSB5_Pos                  (5U)
#define GPIO_SCR_IOSB5_Msk                  (0x1U << GPIO_SCR_IOSB5_Pos)            /*!< 0x00000020 */
#define GPIO_SCR_IOSB5                      GPIO_SCR_IOSB5_Msk                      /*!< GPIO x set bit 5 */
#define GPIO_SCR_IOSB6_Pos                  (6U)
#define GPIO_SCR_IOSB6_Msk                  (0x1U << GPIO_SCR_IOSB6_Pos)            /*!< 0x00000040 */
#define GPIO_SCR_IOSB6                      GPIO_SCR_IOSB6_Msk                      /*!< GPIO x set bit 6 */
#define GPIO_SCR_IOSB7_Pos                  (7U)
#define GPIO_SCR_IOSB7_Msk                  (0x1U << GPIO_SCR_IOSB7_Pos)            /*!< 0x00000080 */
#define GPIO_SCR_IOSB7                      GPIO_SCR_IOSB7_Msk                      /*!< GPIO x set bit 7 */
#define GPIO_SCR_IOSB8_Pos                  (8U)
#define GPIO_SCR_IOSB8_Msk                  (0x1U << GPIO_SCR_IOSB8_Pos)            /*!< 0x00000100 */
#define GPIO_SCR_IOSB8                      GPIO_SCR_IOSB8_Msk                      /*!< GPIO x set bit 8 */
#define GPIO_SCR_IOSB9_Pos                  (9U)
#define GPIO_SCR_IOSB9_Msk                  (0x1U << GPIO_SCR_IOSB9_Pos)            /*!< 0x00000200 */
#define GPIO_SCR_IOSB9                      GPIO_SCR_IOSB9_Msk                      /*!< GPIO x set bit 9 */
#define GPIO_SCR_IOSB10_Pos                 (10U)
#define GPIO_SCR_IOSB10_Msk                 (0x1U << GPIO_SCR_IOSB10_Pos)           /*!< 0x00000400 */
#define GPIO_SCR_IOSB10                     GPIO_SCR_IOSB10_Msk                     /*!< GPIO x set bit 10 */
#define GPIO_SCR_IOSB11_Pos                 (11U)
#define GPIO_SCR_IOSB11_Msk                 (0x1U << GPIO_SCR_IOSB11_Pos)           /*!< 0x00000800 */
#define GPIO_SCR_IOSB11                     GPIO_SCR_IOSB11_Msk                     /*!< GPIO x set bit 11 */
#define GPIO_SCR_IOSB12_Pos                 (12U)
#define GPIO_SCR_IOSB12_Msk                 (0x1U << GPIO_SCR_IOSB12_Pos)           /*!< 0x00001000 */
#define GPIO_SCR_IOSB12                     GPIO_SCR_IOSB12_Msk                     /*!< GPIO x set bit 12 */
#define GPIO_SCR_IOSB13_Pos                 (13U)
#define GPIO_SCR_IOSB13_Msk                 (0x1U << GPIO_SCR_IOSB13_Pos)           /*!< 0x00002000 */
#define GPIO_SCR_IOSB13                     GPIO_SCR_IOSB13_Msk                     /*!< GPIO x set bit 13 */
#define GPIO_SCR_IOSB14_Pos                 (14U)
#define GPIO_SCR_IOSB14_Msk                 (0x1U << GPIO_SCR_IOSB14_Pos)           /*!< 0x00004000 */
#define GPIO_SCR_IOSB14                     GPIO_SCR_IOSB14_Msk                     /*!< GPIO x set bit 14 */
#define GPIO_SCR_IOSB15_Pos                 (15U)
#define GPIO_SCR_IOSB15_Msk                 (0x1U << GPIO_SCR_IOSB15_Pos)           /*!< 0x00008000 */
#define GPIO_SCR_IOSB15                     GPIO_SCR_IOSB15_Msk                     /*!< GPIO x set bit 15 */
#define GPIO_SCR_IOCB0_Pos                  (16U)
#define GPIO_SCR_IOCB0_Msk                  (0x1U << GPIO_SCR_IOCB0_Pos)            /*!< 0x00010000 */
#define GPIO_SCR_IOCB0                      GPIO_SCR_IOCB0_Msk                      /*!< GPIO x clear bit 0 */
#define GPIO_SCR_IOCB1_Pos                  (17U)
#define GPIO_SCR_IOCB1_Msk                  (0x1U << GPIO_SCR_IOCB1_Pos)            /*!< 0x00020000 */
#define GPIO_SCR_IOCB1                      GPIO_SCR_IOCB1_Msk                      /*!< GPIO x clear bit 1 */
#define GPIO_SCR_IOCB2_Pos                  (18U)
#define GPIO_SCR_IOCB2_Msk                  (0x1U << GPIO_SCR_IOCB2_Pos)            /*!< 0x00040000 */
#define GPIO_SCR_IOCB2                      GPIO_SCR_IOCB2_Msk                      /*!< GPIO x clear bit 2 */
#define GPIO_SCR_IOCB3_Pos                  (19U)
#define GPIO_SCR_IOCB3_Msk                  (0x1U << GPIO_SCR_IOCB3_Pos)            /*!< 0x00080000 */
#define GPIO_SCR_IOCB3                      GPIO_SCR_IOCB3_Msk                      /*!< GPIO x clear bit 3 */
#define GPIO_SCR_IOCB4_Pos                  (20U)
#define GPIO_SCR_IOCB4_Msk                  (0x1U << GPIO_SCR_IOCB4_Pos)            /*!< 0x00100000 */
#define GPIO_SCR_IOCB4                      GPIO_SCR_IOCB4_Msk                      /*!< GPIO x clear bit 4 */
#define GPIO_SCR_IOCB5_Pos                  (21U)
#define GPIO_SCR_IOCB5_Msk                  (0x1U << GPIO_SCR_IOCB5_Pos)            /*!< 0x00200000 */
#define GPIO_SCR_IOCB5                      GPIO_SCR_IOCB5_Msk                      /*!< GPIO x clear bit 5 */
#define GPIO_SCR_IOCB6_Pos                  (22U)
#define GPIO_SCR_IOCB6_Msk                  (0x1U << GPIO_SCR_IOCB6_Pos)            /*!< 0x00400000 */
#define GPIO_SCR_IOCB6                      GPIO_SCR_IOCB6_Msk                      /*!< GPIO x clear bit 6 */
#define GPIO_SCR_IOCB7_Pos                  (23U)
#define GPIO_SCR_IOCB7_Msk                  (0x1U << GPIO_SCR_IOCB7_Pos)            /*!< 0x00800000 */
#define GPIO_SCR_IOCB7                      GPIO_SCR_IOCB7_Msk                      /*!< GPIO x clear bit 7 */
#define GPIO_SCR_IOCB8_Pos                  (24U)
#define GPIO_SCR_IOCB8_Msk                  (0x1U << GPIO_SCR_IOCB8_Pos)            /*!< 0x01000000 */
#define GPIO_SCR_IOCB8                      GPIO_SCR_IOCB8_Msk                      /*!< GPIO x clear bit 8 */
#define GPIO_SCR_IOCB9_Pos                  (25U)
#define GPIO_SCR_IOCB9_Msk                  (0x1U << GPIO_SCR_IOCB9_Pos)            /*!< 0x02000000 */
#define GPIO_SCR_IOCB9                      GPIO_SCR_IOCB9_Msk                      /*!< GPIO x clear bit 9 */
#define GPIO_SCR_IOCB10_Pos                 (26U)
#define GPIO_SCR_IOCB10_Msk                 (0x1U << GPIO_SCR_IOCB10_Pos)           /*!< 0x04000000 */
#define GPIO_SCR_IOCB10                     GPIO_SCR_IOCB10_Msk                     /*!< GPIO x clear bit 10 */
#define GPIO_SCR_IOCB11_Pos                 (27U)
#define GPIO_SCR_IOCB11_Msk                 (0x1U << GPIO_SCR_IOCB11_Pos)           /*!< 0x08000000 */
#define GPIO_SCR_IOCB11                     GPIO_SCR_IOCB11_Msk                     /*!< GPIO x clear bit 11 */
#define GPIO_SCR_IOCB12_Pos                 (28U)
#define GPIO_SCR_IOCB12_Msk                 (0x1U << GPIO_SCR_IOCB12_Pos)           /*!< 0x10000000 */
#define GPIO_SCR_IOCB12                     GPIO_SCR_IOCB12_Msk                     /*!< GPIO x clear bit 12 */
#define GPIO_SCR_IOCB13_Pos                 (29U)
#define GPIO_SCR_IOCB13_Msk                 (0x1U << GPIO_SCR_IOCB13_Pos)           /*!< 0x20000000 */
#define GPIO_SCR_IOCB13                     GPIO_SCR_IOCB13_Msk                     /*!< GPIO x clear bit 13 */
#define GPIO_SCR_IOCB14_Pos                 (30U)
#define GPIO_SCR_IOCB14_Msk                 (0x1U << GPIO_SCR_IOCB14_Pos)           /*!< 0x40000000 */
#define GPIO_SCR_IOCB14                     GPIO_SCR_IOCB14_Msk                     /*!< GPIO x clear bit 14 */
#define GPIO_SCR_IOCB15_Pos                 (31U)
#define GPIO_SCR_IOCB15_Msk                 (0x1U << GPIO_SCR_IOCB15_Pos)           /*!< 0x80000000 */
#define GPIO_SCR_IOCB15                     GPIO_SCR_IOCB15_Msk                     /*!< GPIO x clear bit 15 */

/*******************  Bit definition for GPIO_CLR register  *******************/
#define GPIO_CLR_IOCB0_Pos                  (0U)
#define GPIO_CLR_IOCB0_Msk                  (0x1U << GPIO_CLR_IOCB0_Pos)            /*!< 0x00000001 */
#define GPIO_CLR_IOCB0                      GPIO_CLR_IOCB0_Msk                      /*!< GPIO x clear bit 0 */
#define GPIO_CLR_IOCB1_Pos                  (1U)
#define GPIO_CLR_IOCB1_Msk                  (0x1U << GPIO_CLR_IOCB1_Pos)            /*!< 0x00000002 */
#define GPIO_CLR_IOCB1                      GPIO_CLR_IOCB1_Msk                      /*!< GPIO x clear bit 1 */
#define GPIO_CLR_IOCB2_Pos                  (2U)
#define GPIO_CLR_IOCB2_Msk                  (0x1U << GPIO_CLR_IOCB2_Pos)            /*!< 0x00000004 */
#define GPIO_CLR_IOCB2                      GPIO_CLR_IOCB2_Msk                      /*!< GPIO x clear bit 2 */
#define GPIO_CLR_IOCB3_Pos                  (3U)
#define GPIO_CLR_IOCB3_Msk                  (0x1U << GPIO_CLR_IOCB3_Pos)            /*!< 0x00000008 */
#define GPIO_CLR_IOCB3                      GPIO_CLR_IOCB3_Msk                      /*!< GPIO x clear bit 3 */
#define GPIO_CLR_IOCB4_Pos                  (4U)
#define GPIO_CLR_IOCB4_Msk                  (0x1U << GPIO_CLR_IOCB4_Pos)            /*!< 0x00000010 */
#define GPIO_CLR_IOCB4                      GPIO_CLR_IOCB4_Msk                      /*!< GPIO x clear bit 4 */
#define GPIO_CLR_IOCB5_Pos                  (5U)
#define GPIO_CLR_IOCB5_Msk                  (0x1U << GPIO_CLR_IOCB5_Pos)            /*!< 0x00000020 */
#define GPIO_CLR_IOCB5                      GPIO_CLR_IOCB5_Msk                      /*!< GPIO x clear bit 5 */
#define GPIO_CLR_IOCB6_Pos                  (6U)
#define GPIO_CLR_IOCB6_Msk                  (0x1U << GPIO_CLR_IOCB6_Pos)            /*!< 0x00000040 */
#define GPIO_CLR_IOCB6                      GPIO_CLR_IOCB6_Msk                      /*!< GPIO x clear bit 6 */
#define GPIO_CLR_IOCB7_Pos                  (7U)
#define GPIO_CLR_IOCB7_Msk                  (0x1U << GPIO_CLR_IOCB7_Pos)            /*!< 0x00000080 */
#define GPIO_CLR_IOCB7                      GPIO_CLR_IOCB7_Msk                      /*!< GPIO x clear bit 7 */
#define GPIO_CLR_IOCB8_Pos                  (8U)
#define GPIO_CLR_IOCB8_Msk                  (0x1U << GPIO_CLR_IOCB8_Pos)            /*!< 0x00000100 */
#define GPIO_CLR_IOCB8                      GPIO_CLR_IOCB8_Msk                      /*!< GPIO x clear bit 8 */
#define GPIO_CLR_IOCB9_Pos                  (9U)
#define GPIO_CLR_IOCB9_Msk                  (0x1U << GPIO_CLR_IOCB9_Pos)            /*!< 0x00000200 */
#define GPIO_CLR_IOCB9                      GPIO_CLR_IOCB9_Msk                      /*!< GPIO x clear bit 9 */
#define GPIO_CLR_IOCB10_Pos                 (10U)
#define GPIO_CLR_IOCB10_Msk                 (0x1U << GPIO_CLR_IOCB10_Pos)           /*!< 0x00000400 */
#define GPIO_CLR_IOCB10                     GPIO_CLR_IOCB10_Msk                     /*!< GPIO x clear bit 10 */
#define GPIO_CLR_IOCB11_Pos                 (11U)
#define GPIO_CLR_IOCB11_Msk                 (0x1U << GPIO_CLR_IOCB11_Pos)           /*!< 0x00000800 */
#define GPIO_CLR_IOCB11                     GPIO_CLR_IOCB11_Msk                     /*!< GPIO x clear bit 11 */
#define GPIO_CLR_IOCB12_Pos                 (12U)
#define GPIO_CLR_IOCB12_Msk                 (0x1U << GPIO_CLR_IOCB12_Pos)           /*!< 0x00001000 */
#define GPIO_CLR_IOCB12                     GPIO_CLR_IOCB12_Msk                     /*!< GPIO x clear bit 12 */
#define GPIO_CLR_IOCB13_Pos                 (13U)
#define GPIO_CLR_IOCB13_Msk                 (0x1U << GPIO_CLR_IOCB13_Pos)           /*!< 0x00002000 */
#define GPIO_CLR_IOCB13                     GPIO_CLR_IOCB13_Msk                     /*!< GPIO x clear bit 13 */
#define GPIO_CLR_IOCB14_Pos                 (14U)
#define GPIO_CLR_IOCB14_Msk                 (0x1U << GPIO_CLR_IOCB14_Pos)           /*!< 0x00004000 */
#define GPIO_CLR_IOCB14                     GPIO_CLR_IOCB14_Msk                     /*!< GPIO x clear bit 14 */
#define GPIO_CLR_IOCB15_Pos                 (15U)
#define GPIO_CLR_IOCB15_Msk                 (0x1U << GPIO_CLR_IOCB15_Pos)           /*!< 0x00008000 */
#define GPIO_CLR_IOCB15                     GPIO_CLR_IOCB15_Msk                     /*!< GPIO x clear bit 15 */

/*******************  Bit definition for GPIO_WPR register  *******************/
#define GPIO_WPR_WPEN0_Pos                  (0U)
#define GPIO_WPR_WPEN0_Msk                  (0x1U << GPIO_WPR_WPEN0_Pos)            /*!< 0x00000001 */
#define GPIO_WPR_WPEN0                      GPIO_WPR_WPEN0_Msk                      /*!< Write protect enable bit 0 */
#define GPIO_WPR_WPEN1_Pos                  (1U)
#define GPIO_WPR_WPEN1_Msk                  (0x1U << GPIO_WPR_WPEN1_Pos)            /*!< 0x00000002 */
#define GPIO_WPR_WPEN1                      GPIO_WPR_WPEN1_Msk                      /*!< Write protect enable bit 1 */
#define GPIO_WPR_WPEN2_Pos                  (2U)
#define GPIO_WPR_WPEN2_Msk                  (0x1U << GPIO_WPR_WPEN2_Pos)            /*!< 0x00000004 */
#define GPIO_WPR_WPEN2                      GPIO_WPR_WPEN2_Msk                      /*!< Write protect enable bit 2 */
#define GPIO_WPR_WPEN3_Pos                  (3U)
#define GPIO_WPR_WPEN3_Msk                  (0x1U << GPIO_WPR_WPEN3_Pos)            /*!< 0x00000008 */
#define GPIO_WPR_WPEN3                      GPIO_WPR_WPEN3_Msk                      /*!< Write protect enable bit 3 */
#define GPIO_WPR_WPEN4_Pos                  (4U)
#define GPIO_WPR_WPEN4_Msk                  (0x1U << GPIO_WPR_WPEN4_Pos)            /*!< 0x00000010 */
#define GPIO_WPR_WPEN4                      GPIO_WPR_WPEN4_Msk                      /*!< Write protect enable bit 4 */
#define GPIO_WPR_WPEN5_Pos                  (5U)
#define GPIO_WPR_WPEN5_Msk                  (0x1U << GPIO_WPR_WPEN5_Pos)            /*!< 0x00000020 */
#define GPIO_WPR_WPEN5                      GPIO_WPR_WPEN5_Msk                      /*!< Write protect enable bit 5 */
#define GPIO_WPR_WPEN6_Pos                  (6U)
#define GPIO_WPR_WPEN6_Msk                  (0x1U << GPIO_WPR_WPEN6_Pos)            /*!< 0x00000040 */
#define GPIO_WPR_WPEN6                      GPIO_WPR_WPEN6_Msk                      /*!< Write protect enable bit 6 */
#define GPIO_WPR_WPEN7_Pos                  (7U)
#define GPIO_WPR_WPEN7_Msk                  (0x1U << GPIO_WPR_WPEN7_Pos)            /*!< 0x00000080 */
#define GPIO_WPR_WPEN7                      GPIO_WPR_WPEN7_Msk                      /*!< Write protect enable bit 7 */
#define GPIO_WPR_WPEN8_Pos                  (8U)
#define GPIO_WPR_WPEN8_Msk                  (0x1U << GPIO_WPR_WPEN8_Pos)            /*!< 0x00000100 */
#define GPIO_WPR_WPEN8                      GPIO_WPR_WPEN8_Msk                      /*!< Write protect enable bit 8 */
#define GPIO_WPR_WPEN9_Pos                  (9U)
#define GPIO_WPR_WPEN9_Msk                  (0x1U << GPIO_WPR_WPEN9_Pos)            /*!< 0x00000200 */
#define GPIO_WPR_WPEN9                      GPIO_WPR_WPEN9_Msk                      /*!< Write protect enable bit 9 */
#define GPIO_WPR_WPEN10_Pos                 (10U)
#define GPIO_WPR_WPEN10_Msk                 (0x1U << GPIO_WPR_WPEN10_Pos)           /*!< 0x00000400 */
#define GPIO_WPR_WPEN10                     GPIO_WPR_WPEN10_Msk                     /*!< Write protect enable bit 10 */
#define GPIO_WPR_WPEN11_Pos                 (11U)
#define GPIO_WPR_WPEN11_Msk                 (0x1U << GPIO_WPR_WPEN11_Pos)           /*!< 0x00000800 */
#define GPIO_WPR_WPEN11                     GPIO_WPR_WPEN11_Msk                     /*!< Write protect enable bit 11 */
#define GPIO_WPR_WPEN12_Pos                 (12U)
#define GPIO_WPR_WPEN12_Msk                 (0x1U << GPIO_WPR_WPEN12_Pos)           /*!< 0x00001000 */
#define GPIO_WPR_WPEN12                     GPIO_WPR_WPEN12_Msk                     /*!< Write protect enable bit 12 */
#define GPIO_WPR_WPEN13_Pos                 (13U)
#define GPIO_WPR_WPEN13_Msk                 (0x1U << GPIO_WPR_WPEN13_Pos)           /*!< 0x00002000 */
#define GPIO_WPR_WPEN13                     GPIO_WPR_WPEN13_Msk                     /*!< Write protect enable bit 13 */
#define GPIO_WPR_WPEN14_Pos                 (14U)
#define GPIO_WPR_WPEN14_Msk                 (0x1U << GPIO_WPR_WPEN14_Pos)           /*!< 0x00004000 */
#define GPIO_WPR_WPEN14                     GPIO_WPR_WPEN14_Msk                     /*!< Write protect enable bit 14 */
#define GPIO_WPR_WPEN15_Pos                 (15U)
#define GPIO_WPR_WPEN15_Msk                 (0x1U << GPIO_WPR_WPEN15_Pos)           /*!< 0x00008000 */
#define GPIO_WPR_WPEN15                     GPIO_WPR_WPEN15_Msk                     /*!< Write protect enable bit 15 */
#define GPIO_WPR_WPSEQ_Pos                  (16U)
#define GPIO_WPR_WPSEQ_Msk                  (0x1U << GPIO_WPR_WPSEQ_Pos)            /*!< 0x00010000 */
#define GPIO_WPR_WPSEQ                      GPIO_WPR_WPSEQ_Msk                      /*!< Write protect sequence */

/******************************************************************************/
/*                                                                            */
/*                      Multiplex function I/Os (IOMUX)                       */
/*                                                                            */
/******************************************************************************/

/*****************  Bit definition for IOMUX_EVTOUT register  *****************/
/*!< SELPIN configuration */
#define IOMUX_EVTOUT_SELPIN_Pos             (0U)
#define IOMUX_EVTOUT_SELPIN_Msk             (0xFU << IOMUX_EVTOUT_SELPIN_Pos)       /*!< 0x0000000F */
#define IOMUX_EVTOUT_SELPIN                 IOMUX_EVTOUT_SELPIN_Msk                 /*!< SELPIN[3:0] bits (Selection IO pin) */
#define IOMUX_EVTOUT_SELPIN_0               (0x1U << IOMUX_EVTOUT_SELPIN_Pos)       /*!< 0x00000001 */
#define IOMUX_EVTOUT_SELPIN_1               (0x2U << IOMUX_EVTOUT_SELPIN_Pos)       /*!< 0x00000002 */
#define IOMUX_EVTOUT_SELPIN_2               (0x4U << IOMUX_EVTOUT_SELPIN_Pos)       /*!< 0x00000004 */
#define IOMUX_EVTOUT_SELPIN_3               (0x8U << IOMUX_EVTOUT_SELPIN_Pos)       /*!< 0x00000008 */

#define IOMUX_EVTOUT_SELPIN_PIN0            0x00000000U                             /*!< Pin 0 */
#define IOMUX_EVTOUT_SELPIN_PIN1_Pos        (0U)
#define IOMUX_EVTOUT_SELPIN_PIN1_Msk        (0x1U << IOMUX_EVTOUT_SELPIN_PIN1_Pos)  /*!< 0x00000001 */
#define IOMUX_EVTOUT_SELPIN_PIN1            IOMUX_EVTOUT_SELPIN_PIN1_Msk            /*!< Pin 1 */
#define IOMUX_EVTOUT_SELPIN_PIN2_Pos        (1U)
#define IOMUX_EVTOUT_SELPIN_PIN2_Msk        (0x1U << IOMUX_EVTOUT_SELPIN_PIN2_Pos)  /*!< 0x00000002 */
#define IOMUX_EVTOUT_SELPIN_PIN2            IOMUX_EVTOUT_SELPIN_PIN2_Msk            /*!< Pin 2 */
#define IOMUX_EVTOUT_SELPIN_PIN3_Pos        (0U)
#define IOMUX_EVTOUT_SELPIN_PIN3_Msk        (0x3U << IOMUX_EVTOUT_SELPIN_PIN3_Pos)  /*!< 0x00000003 */
#define IOMUX_EVTOUT_SELPIN_PIN3            IOMUX_EVTOUT_SELPIN_PIN3_Msk            /*!< Pin 3 */
#define IOMUX_EVTOUT_SELPIN_PIN4_Pos        (2U)
#define IOMUX_EVTOUT_SELPIN_PIN4_Msk        (0x1U << IOMUX_EVTOUT_SELPIN_PIN4_Pos)  /*!< 0x00000004 */
#define IOMUX_EVTOUT_SELPIN_PIN4            IOMUX_EVTOUT_SELPIN_PIN4_Msk            /*!< Pin 4 */
#define IOMUX_EVTOUT_SELPIN_PIN5_Pos        (0U)
#define IOMUX_EVTOUT_SELPIN_PIN5_Msk        (0x5U << IOMUX_EVTOUT_SELPIN_PIN5_Pos)  /*!< 0x00000005 */
#define IOMUX_EVTOUT_SELPIN_PIN5            IOMUX_EVTOUT_SELPIN_PIN5_Msk            /*!< Pin 5 */
#define IOMUX_EVTOUT_SELPIN_PIN6_Pos        (1U)
#define IOMUX_EVTOUT_SELPIN_PIN6_Msk        (0x3U << IOMUX_EVTOUT_SELPIN_PIN6_Pos)  /*!< 0x00000006 */
#define IOMUX_EVTOUT_SELPIN_PIN6            IOMUX_EVTOUT_SELPIN_PIN6_Msk            /*!< Pin 6 */
#define IOMUX_EVTOUT_SELPIN_PIN7_Pos        (0U)
#define IOMUX_EVTOUT_SELPIN_PIN7_Msk        (0x7U << IOMUX_EVTOUT_SELPIN_PIN7_Pos)  /*!< 0x00000007 */
#define IOMUX_EVTOUT_SELPIN_PIN7            IOMUX_EVTOUT_SELPIN_PIN7_Msk            /*!< Pin 7 */
#define IOMUX_EVTOUT_SELPIN_PIN8_Pos        (3U)
#define IOMUX_EVTOUT_SELPIN_PIN8_Msk        (0x1U << IOMUX_EVTOUT_SELPIN_PIN8_Pos)  /*!< 0x00000008 */
#define IOMUX_EVTOUT_SELPIN_PIN8            IOMUX_EVTOUT_SELPIN_PIN8_Msk            /*!< Pin 8 */
#define IOMUX_EVTOUT_SELPIN_PIN9_Pos        (0U)
#define IOMUX_EVTOUT_SELPIN_PIN9_Msk        (0x9U << IOMUX_EVTOUT_SELPIN_PIN9_Pos)  /*!< 0x00000009 */
#define IOMUX_EVTOUT_SELPIN_PIN9            IOMUX_EVTOUT_SELPIN_PIN9_Msk            /*!< Pin 9 */
#define IOMUX_EVTOUT_SELPIN_PIN10_Pos       (1U)
#define IOMUX_EVTOUT_SELPIN_PIN10_Msk       (0x5U << IOMUX_EVTOUT_SELPIN_PIN10_Pos) /*!< 0x0000000A */
#define IOMUX_EVTOUT_SELPIN_PIN10           IOMUX_EVTOUT_SELPIN_PIN10_Msk           /*!< Pin 10 */
#define IOMUX_EVTOUT_SELPIN_PIN11_Pos       (0U)
#define IOMUX_EVTOUT_SELPIN_PIN11_Msk       (0xBU << IOMUX_EVTOUT_SELPIN_PIN11_Pos) /*!< 0x0000000B */
#define IOMUX_EVTOUT_SELPIN_PIN11           IOMUX_EVTOUT_SELPIN_PIN11_Msk           /*!< Pin 11 */
#define IOMUX_EVTOUT_SELPIN_PIN12_Pos       (2U)
#define IOMUX_EVTOUT_SELPIN_PIN12_Msk       (0x3U << IOMUX_EVTOUT_SELPIN_PIN12_Pos) /*!< 0x0000000C */
#define IOMUX_EVTOUT_SELPIN_PIN12           IOMUX_EVTOUT_SELPIN_PIN12_Msk           /*!< Pin 12 */
#define IOMUX_EVTOUT_SELPIN_PIN13_Pos       (0U)
#define IOMUX_EVTOUT_SELPIN_PIN13_Msk       (0xDU << IOMUX_EVTOUT_SELPIN_PIN13_Pos) /*!< 0x0000000D */
#define IOMUX_EVTOUT_SELPIN_PIN13           IOMUX_EVTOUT_SELPIN_PIN13_Msk           /*!< Pin 13 */
#define IOMUX_EVTOUT_SELPIN_PIN14_Pos       (1U)
#define IOMUX_EVTOUT_SELPIN_PIN14_Msk       (0x7U << IOMUX_EVTOUT_SELPIN_PIN14_Pos) /*!< 0x0000000E */
#define IOMUX_EVTOUT_SELPIN_PIN14           IOMUX_EVTOUT_SELPIN_PIN14_Msk           /*!< Pin 14 */
#define IOMUX_EVTOUT_SELPIN_PIN15_Pos       (0U)
#define IOMUX_EVTOUT_SELPIN_PIN15_Msk       (0xFU << IOMUX_EVTOUT_SELPIN_PIN15_Pos) /*!< 0x0000000F */
#define IOMUX_EVTOUT_SELPIN_PIN15           IOMUX_EVTOUT_SELPIN_PIN15_Msk           /*!< Pin 15 */

/*!< SELPORT configuration */
#define IOMUX_EVTOUT_SELPORT_Pos            (4U)
#define IOMUX_EVTOUT_SELPORT_Msk            (0x7U << IOMUX_EVTOUT_SELPORT_Pos)      /*!< 0x00000070 */
#define IOMUX_EVTOUT_SELPORT                IOMUX_EVTOUT_SELPORT_Msk                /*!< SELPORT[2:0] bits (Selection IO port) */
#define IOMUX_EVTOUT_SELPORT_0              (0x1U << IOMUX_EVTOUT_SELPORT_Pos)      /*!< 0x00000010 */
#define IOMUX_EVTOUT_SELPORT_1              (0x2U << IOMUX_EVTOUT_SELPORT_Pos)      /*!< 0x00000020 */
#define IOMUX_EVTOUT_SELPORT_2              (0x4U << IOMUX_EVTOUT_SELPORT_Pos)      /*!< 0x00000040 */

#define IOMUX_EVTOUT_SELPORT_GPIOA          0x00000000                              /*!< GPIOA */
#define IOMUX_EVTOUT_SELPORT_GPIOB_Pos      (4U)                                    /*!< 0x00000010 */
#define IOMUX_EVTOUT_SELPORT_GPIOB_Msk      (0x1U << IOMUX_EVTOUT_SELPORT_GPIOB_Pos)
#define IOMUX_EVTOUT_SELPORT_GPIOB          IOMUX_EVTOUT_SELPORT_GPIOB_Msk          /*!< GPIOB */
#define IOMUX_EVTOUT_SELPORT_GPIOC_Pos      (5U)                                    /*!< 0x00000020 */
#define IOMUX_EVTOUT_SELPORT_GPIOC_Msk      (0x1U << IOMUX_EVTOUT_SELPORT_GPIOC_Pos)
#define IOMUX_EVTOUT_SELPORT_GPIOC          IOMUX_EVTOUT_SELPORT_GPIOC_Msk          /*!< GPIOC */
#define IOMUX_EVTOUT_SELPORT_GPIOD_Pos      (4U)                                    /*!< 0x00000030 */
#define IOMUX_EVTOUT_SELPORT_GPIOD_Msk      (0x3U << IOMUX_EVTOUT_SELPORT_GPIOD_Pos)
#define IOMUX_EVTOUT_SELPORT_GPIOD          IOMUX_EVTOUT_SELPORT_GPIOD_Msk          /*!< GPIOD */
#define IOMUX_EVTOUT_SELPORT_GPIOF_Pos      (4U)                                    /*!< 0x00000050 */
#define IOMUX_EVTOUT_SELPORT_GPIOF_Msk      (0x5U << IOMUX_EVTOUT_SELPORT_GPIOF_Pos)
#define IOMUX_EVTOUT_SELPORT_GPIOF          IOMUX_EVTOUT_SELPORT_GPIOF_Msk          /*!< GPIOF */

#define IOMUX_EVTOUT_EVOEN_Pos              (7U)
#define IOMUX_EVTOUT_EVOEN_Msk              (0x1U << IOMUX_EVTOUT_EVOEN_Pos)        /*!< 0x00000080 */
#define IOMUX_EVTOUT_EVOEN                  IOMUX_EVTOUT_EVOEN_Msk                  /*!< Event output enable */

/*****************  Bit definition for IOMUX_REMAP register  ******************/
/*!< SPI1_MUX configuration */
#define IOMUX_REMAP_SPI1_MUX_Pos            (0U)
#define IOMUX_REMAP_SPI1_MUX_Msk            (0x1U << IOMUX_REMAP_SPI1_MUX_Pos)      /*!< 0x00000001 */
#define IOMUX_REMAP_SPI1_MUX                IOMUX_REMAP_SPI1_MUX_Msk                /*!< SPI1 IO multiplexing */
#define IOMUX_REMAP_I2C1_MUX_Pos            (1U)
#define IOMUX_REMAP_I2C1_MUX_Msk            (0x1U << IOMUX_REMAP_I2C1_MUX_Pos)      /*!< 0x00000002 */
#define IOMUX_REMAP_I2C1_MUX                IOMUX_REMAP_I2C1_MUX_Msk                /*!< I2C1 IO multiplexing */
#define IOMUX_REMAP_USART1_MUX_Pos          (2U)
#define IOMUX_REMAP_USART1_MUX_Msk          (0x1U << IOMUX_REMAP_USART1_MUX_Pos)    /*!< 0x00000004 */
#define IOMUX_REMAP_USART1_MUX              IOMUX_REMAP_USART1_MUX_Msk              /*!< USART1 IO multiplexing */

/*!< USART3_MUX configuration */
#define IOMUX_REMAP_USART3_MUX_Pos          (4U)
#define IOMUX_REMAP_USART3_MUX_Msk          (0x3U << IOMUX_REMAP_USART3_MUX_Pos)    /*!< 0x00000030 */
#define IOMUX_REMAP_USART3_MUX              IOMUX_REMAP_USART3_MUX_Msk              /*!< USART3_MUX[1:0] bits (USART3 IO multiplexing) */
#define IOMUX_REMAP_USART3_MUX_0            (0x1U << IOMUX_REMAP_USART3_MUX_Pos)    /*!< 0x00000010 */
#define IOMUX_REMAP_USART3_MUX_1            (0x2U << IOMUX_REMAP_USART3_MUX_Pos)    /*!< 0x00000020 */

#define IOMUX_REMAP_USART3_MUX_MUX0         0x00000000U                             /*!< TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14 */
#define IOMUX_REMAP_USART3_MUX_MUX1_Pos     (4U)                                    /*!< 0x00000010 */
#define IOMUX_REMAP_USART3_MUX_MUX1_Msk     (0x1U << IOMUX_REMAP_USART3_MUX_MUX1_Pos)
#define IOMUX_REMAP_USART3_MUX_MUX1         IOMUX_REMAP_USART3_MUX_MUX1_Msk         /*!< TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14 */
#define IOMUX_REMAP_USART3_MUX_MUX2_Pos     (5U)                                    /*!< 0x00000020 */
#define IOMUX_REMAP_USART3_MUX_MUX2_Msk     (0x1U << IOMUX_REMAP_USART3_MUX_MUX2_Pos)
#define IOMUX_REMAP_USART3_MUX_MUX2         IOMUX_REMAP_USART3_MUX_MUX2_Msk         /*!< TX/PA7, RX/PA6, CK/PA5, CTS/PB1, RTS/PB0 */

/*!< TMR1_MUX configuration */
#define IOMUX_REMAP_TMR1_MUX_Pos            (6U)
#define IOMUX_REMAP_TMR1_MUX_Msk            (0x3U << IOMUX_REMAP_TMR1_MUX_Pos)      /*!< 0x000000C0 */
#define IOMUX_REMAP_TMR1_MUX                IOMUX_REMAP_TMR1_MUX_Msk                /*!< TMR1_MUX[1:0] bits (TMR1 IO multiplexing) */
#define IOMUX_REMAP_TMR1_MUX_0              (0x1U << IOMUX_REMAP_TMR1_MUX_Pos)      /*!< 0x00000040 */
#define IOMUX_REMAP_TMR1_MUX_1              (0x2U << IOMUX_REMAP_TMR1_MUX_Pos       /*!< 0x00000080 */

#define IOMUX_REMAP_TMR1_MUX_MUX0           0x00000000U                             /*!< EXT/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BRK/PB12, CH1C/PB13, CH2C/PB14, CH3C/PB15 */
#define IOMUX_REMAP_TMR1_MUX_MUX1_Pos       (6U)
#define IOMUX_REMAP_TMR1_MUX_MUX1_Msk       (0x1U << IOMUX_REMAP_TMR1_MUX_MUX1_Pos) /*!< 0x00000040 */
#define IOMUX_REMAP_TMR1_MUX_MUX1           IOMUX_REMAP_TMR1_MUX_MUX1_Msk           /*!< EXT/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BRK/PA6, CH1C/PA7, CH2C/PB0, CH3C/PB1 */

/*!< TMR2_MUX configuration */
#define IOMUX_REMAP_TMR2_MUX_Pos            (8U)
#define IOMUX_REMAP_TMR2_MUX_Msk            (0x3U << IOMUX_REMAP_TMR2_MUX_Pos)      /*!< 0x00000300 */
#define IOMUX_REMAP_TMR2_MUX                IOMUX_REMAP_TMR2_MUX_Msk                /*!< TMR2_MUX[1:0] bits (TMR2 IO multiplexing) */
#define IOMUX_REMAP_TMR2_MUX_0              (0x1U << IOMUX_REMAP_TMR2_MUX_Pos)      /*!< 0x00000100 */
#define IOMUX_REMAP_TMR2_MUX_1              (0x2U << IOMUX_REMAP_TMR2_MUX_Pos)      /*!< 0x00000200 */

#define IOMUX_REMAP_TMR2_MUX_MUX0           0x00000000U                             /*!< CH1/EXT/PA0, CH2/PA1, CH3/PA2, CH4/PA3 */
#define IOMUX_REMAP_TMR2_MUX_MUX1_Pos       (8U)
#define IOMUX_REMAP_TMR2_MUX_MUX1_Msk       (0x1U << IOMUX_REMAP_TMR2_MUX_MUX1_Pos) /*!< 0x00000100 */
#define IOMUX_REMAP_TMR2_MUX_MUX1           IOMUX_REMAP_TMR2_MUX_MUX1_Msk           /*!< CH1/EXT/PA15, CH2/PB3, CH3/PA2, CH4/PA3 */
#define IOMUX_REMAP_TMR2_MUX_MUX2_Pos       (9U)
#define IOMUX_REMAP_TMR2_MUX_MUX2_Msk       (0x1U << IOMUX_REMAP_TMR2_MUX_MUX2_Pos) /*!< 0x00000200 */
#define IOMUX_REMAP_TMR2_MUX_MUX2           IOMUX_REMAP_TMR2_MUX_MUX2_Msk           /*!< CH1/EXT/PA0, CH2/PA1, CH3/PB10, CH4/PB11 */
#define IOMUX_REMAP_TMR2_MUX_MUX3_Pos       (8U)
#define IOMUX_REMAP_TMR2_MUX_MUX3_Msk       (0x3U << IOMUX_REMAP_TMR2_MUX_MUX3_Pos) /*!< 0x00000300 */
#define IOMUX_REMAP_TMR2_MUX_MUX3           IOMUX_REMAP_TMR2_MUX_MUX3_Msk           /*!< CH1/EXT/PA15, CH2/PB3, CH3/PB10, CH4/PB11 */

/*!< TMR3_MUX configuration */
#define IOMUX_REMAP_TMR3_MUX_Pos            (10U)
#define IOMUX_REMAP_TMR3_MUX_Msk            (0x3U << IOMUX_REMAP_TMR3_MUX_Pos)      /*!< 0x00000C00 */
#define IOMUX_REMAP_TMR3_MUX                IOMUX_REMAP_TMR3_MUX_Msk                /*!< TMR3_MUX[1:0] bits (TMR3 IO multiplexing) */
#define IOMUX_REMAP_TMR3_MUX_0              (0x1U << IOMUX_REMAP_TMR3_MUX_Pos)      /*!< 0x00000400 */
#define IOMUX_REMAP_TMR3_MUX_1              (0x2U << IOMUX_REMAP_TMR3_MUX_Pos)      /*!< 0x00000800 */

#define IOMUX_REMAP_TMR3_MUX_MUX0           0x00000000U                             /*!< CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1 */
#define IOMUX_REMAP_TMR3_MUX_MUX2_Pos       (11U)
#define IOMUX_REMAP_TMR3_MUX_MUX2_Msk       (0x1U << IOMUX_REMAP_TMR3_MUX_MUX2_Pos) /*!< 0x00000800 */
#define IOMUX_REMAP_TMR3_MUX_MUX2           IOMUX_REMAP_TMR3_MUX_MUX2_Msk           /*!< CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1 */
#define IOMUX_REMAP_TMR3_MUX_MUX3_Pos       (10U)
#define IOMUX_REMAP_TMR3_MUX_MUX3_Msk       (0x3U << IOMUX_REMAP_TMR3_MUX_MUX3_Pos) /*!< 0x00000C00 */
#define IOMUX_REMAP_TMR3_MUX_MUX3           IOMUX_REMAP_TMR3_MUX_MUX3_Msk           /*!< CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9 */

/*!< CAN1_MUX configuration */
#define IOMUX_REMAP_CAN1_MUX_Pos            (13U)
#define IOMUX_REMAP_CAN1_MUX_Msk            (0x3U << IOMUX_REMAP_CAN1_MUX_Pos)      /*!< 0x00006000 */
#define IOMUX_REMAP_CAN1_MUX                IOMUX_REMAP_CAN1_MUX_Msk                /*!< CAN1_MUX[1:0] bits (CAN1 IO multiplexing) */
#define IOMUX_REMAP_CAN1_MUX_0              (0x1U << IOMUX_REMAP_CAN1_MUX_Pos)      /*!< 0x00002000 */
#define IOMUX_REMAP_CAN1_MUX_1              (0x2U << IOMUX_REMAP_CAN1_MUX_Pos)      /*!< 0x00004000 */

#define IOMUX_REMAP_CAN1_MUX_MUX0           0x00000000U                             /*!< RX/PA11, TX/PA12 */
#define IOMUX_REMAP_CAN1_MUX_MUX2_Pos       (14U)
#define IOMUX_REMAP_CAN1_MUX_MUX2_Msk       (0x1U << IOMUX_REMAP_CAN1_MUX_MUX2_Pos) /*!< 0x00004000 */
#define IOMUX_REMAP_CAN1_MUX_MUX2           IOMUX_REMAP_CAN1_MUX_MUX2_Msk           /*!< RX/PB8, TX/PB9 */

#define IOMUX_REMAP_PD01_MUX_Pos            (15U)
#define IOMUX_REMAP_PD01_MUX_Msk            (0x1U << IOMUX_REMAP_PD01_MUX_Pos)      /*!< 0x00008000 */
#define IOMUX_REMAP_PD01_MUX                IOMUX_REMAP_PD01_MUX_Msk                /*!< PD0/PD1 mapped on HEXT_IN/HEXT_OUT */
#define IOMUX_REMAP_TMR5CH4_MUX_Pos         (16U)
#define IOMUX_REMAP_TMR5CH4_MUX_Msk         (0x1U << IOMUX_REMAP_TMR5CH4_MUX_Pos)   /*!< 0x00010000 */
#define IOMUX_REMAP_TMR5CH4_MUX             IOMUX_REMAP_TMR5CH4_MUX_Msk             /*!< TMR5 channel 4 multiplexing */
#define IOMUX_REMAP_ADC1_ETP_MUX_Pos        (17U)
#define IOMUX_REMAP_ADC1_ETP_MUX_Msk        (0x1U << IOMUX_REMAP_ADC1_ETP_MUX_Pos)  /*!< 0x00020000 */
#define IOMUX_REMAP_ADC1_ETP_MUX            IOMUX_REMAP_ADC1_ETP_MUX_Msk            /*!< ADC1 external trigger preempted conversion multiplexing */
#define IOMUX_REMAP_ADC1_ETO_MUX_Pos        (18U)
#define IOMUX_REMAP_ADC1_ETO_MUX_Msk        (0x1U << IOMUX_REMAP_ADC1_ETO_MUX_Pos)  /*!< 0x00040000 */
#define IOMUX_REMAP_ADC1_ETO_MUX            IOMUX_REMAP_ADC1_ETO_MUX_Msk            /*!< ADC1 external trigger regular conversion mutiplexing */

/*!< SWJTAG_MUX configuration */
#define IOMUX_REMAP_SWJTAG_MUX_Pos          (24U)
#define IOMUX_REMAP_SWJTAG_MUX_Msk          (0x7U << IOMUX_REMAP_SWJTAG_MUX_Pos)    /*!< 0x07000000 */
#define IOMUX_REMAP_SWJTAG_MUX              IOMUX_REMAP_SWJTAG_MUX_Msk              /*!< SWJTAG_MUX[2:0] bits (SWD JTAG mutiplexing) */
#define IOMUX_REMAP_SWJTAG_MUX_0            (0x1U << IOMUX_REMAP_SWJTAG_MUX_Pos)    /*!< 0x01000000 */
#define IOMUX_REMAP_SWJTAG_MUX_1            (0x2U << IOMUX_REMAP_SWJTAG_MUX_Pos)    /*!< 0x02000000 */
#define IOMUX_REMAP_SWJTAG_MUX_2            (0x4U << IOMUX_REMAP_SWJTAG_MUX_Pos)    /*!< 0x04000000 */

#define IOMUX_REMAP_SWJTAG_MUX_RESET        0x00000000U                             /*!< Supports SWD and JTAG. All SWJTAG pins cannot be used as GPIOs */
#define IOMUX_REMAP_SWJTAG_MUX_NONJTRST_Pos (24U)                                   /*!< 0x01000000 */
#define IOMUX_REMAP_SWJTAG_MUX_NONJTRST_Msk (0x1U << IOMUX_REMAP_SWJTAG_MUX_NONJTRST_Pos)
#define IOMUX_REMAP_SWJTAG_MUX_NONJTRST     IOMUX_REMAP_SWJTAG_MUX_NONJTRST_Msk     /*!< Supports SWD and JTAG. NJTRST is disabled. PB4 can be used as GPIO */
#define IOMUX_REMAP_SWJTAG_MUX_JTAGDIS_Pos  (25U)                                   /*!< 0x02000000 */
#define IOMUX_REMAP_SWJTAG_MUX_JTAGDIS_Msk  (0x1U << IOMUX_REMAP_SWJTAG_MUX_JTAGDIS_Pos)
#define IOMUX_REMAP_SWJTAG_MUX_JTAGDIS      IOMUX_REMAP_SWJTAG_MUX_JTAGDIS_Msk      /*!< Supports SWD but JTAG is disabled. PA15/PB3/PB4 can be used as GPIOs */
#define IOMUX_REMAP_SWJTAG_MUX_DISABLE_Pos  (26U)                                   /*!< 0x04000000 */
#define IOMUX_REMAP_SWJTAG_MUX_DISABLE_Msk  (0x1U << IOMUX_REMAP_SWJTAG_MUX_DISABLE_Pos)
#define IOMUX_REMAP_SWJTAG_MUX_DISABLE      IOMUX_REMAP_SWJTAG_MUX_DISABLE_Msk      /*!< SWD and JTAG are disabled. All SWJTAG pins can be used as GPIOs */

/****************  Bit definition for IOMUX_EXINTC1 register  *****************/
/*!< EXINT0 configuration */
#define IOMUX_EXINTC1_EXINT0_Pos            (0U)
#define IOMUX_EXINTC1_EXINT0_Msk            (0xFU << IOMUX_EXINTC1_EXINT0_Pos)      /*!< 0x0000000F */
#define IOMUX_EXINTC1_EXINT0                IOMUX_EXINTC1_EXINT0_Msk                /*!< EXINT0[3:0] bits (EXINT0 input source configuration) */

#define IOMUX_EXINTC1_EXINT0_GPA            0x00000000U                             /*!< GPIOA pin 0 */
#define IOMUX_EXINTC1_EXINT0_GPB_Pos        (0U)
#define IOMUX_EXINTC1_EXINT0_GPB_Msk        (0x1U << IOMUX_EXINTC1_EXINT0_GPB_Pos)  /*!< 0x00000001 */
#define IOMUX_EXINTC1_EXINT0_GPB            IOMUX_EXINTC1_EXINT0_GPB_Msk            /*!< GPIOB pin 0 */
#define IOMUX_EXINTC1_EXINT0_GPC_Pos        (1U)
#define IOMUX_EXINTC1_EXINT0_GPC_Msk        (0x1U << IOMUX_EXINTC1_EXINT0_GPC_Pos)  /*!< 0x00000002 */
#define IOMUX_EXINTC1_EXINT0_GPC            IOMUX_EXINTC1_EXINT0_GPC_Msk            /*!< GPIOC pin 0 */
#define IOMUX_EXINTC1_EXINT0_GPD_Pos        (0U)
#define IOMUX_EXINTC1_EXINT0_GPD_Msk        (0x3U << IOMUX_EXINTC1_EXINT0_GPD_Pos)  /*!< 0x00000003 */
#define IOMUX_EXINTC1_EXINT0_GPD            IOMUX_EXINTC1_EXINT0_GPD_Msk            /*!< GPIOD pin 0 */
#define IOMUX_EXINTC1_EXINT0_GPF_Pos        (2U)
#define IOMUX_EXINTC1_EXINT0_GPF_Msk        (0x1U << IOMUX_EXINTC1_EXINT0_GPF_Pos)  /*!< 0x00000004 */
#define IOMUX_EXINTC1_EXINT0_GPF            IOMUX_EXINTC1_EXINT0_GPF_Msk            /*!< GPIOF pin 0 */

/*!< EXINT1 configuration */
#define IOMUX_EXINTC1_EXINT1_Pos            (4U)
#define IOMUX_EXINTC1_EXINT1_Msk            (0xFU << IOMUX_EXINTC1_EXINT1_Pos)      /*!< 0x000000F0 */
#define IOMUX_EXINTC1_EXINT1                IOMUX_EXINTC1_EXINT1_Msk                /*!< EXINT1[3:0] bits (EXINT1 input source configuration) */

#define IOMUX_EXINTC1_EXINT1_GPA            0x00000000U                             /*!< GPIOA pin 1 */
#define IOMUX_EXINTC1_EXINT1_GPB_Pos        (4U)
#define IOMUX_EXINTC1_EXINT1_GPB_Msk        (0x1U << IOMUX_EXINTC1_EXINT1_GPB_Pos)  /*!< 0x00000010 */
#define IOMUX_EXINTC1_EXINT1_GPB            IOMUX_EXINTC1_EXINT1_GPB_Msk            /*!< GPIOB pin 1 */
#define IOMUX_EXINTC1_EXINT1_GPC_Pos        (5U)
#define IOMUX_EXINTC1_EXINT1_GPC_Msk        (0x1U << IOMUX_EXINTC1_EXINT1_GPC_Pos)  /*!< 0x00000020 */
#define IOMUX_EXINTC1_EXINT1_GPC            IOMUX_EXINTC1_EXINT1_GPC_Msk            /*!< GPIOC pin 1 */
#define IOMUX_EXINTC1_EXINT1_GPD_Pos        (4U)
#define IOMUX_EXINTC1_EXINT1_GPD_Msk        (0x3U << IOMUX_EXINTC1_EXINT1_GPD_Pos)  /*!< 0x00000030 */
#define IOMUX_EXINTC1_EXINT1_GPD            IOMUX_EXINTC1_EXINT1_GPD_Msk            /*!< GPIOD pin 1 */
#define IOMUX_EXINTC1_EXINT1_GPF_Pos        (6U)
#define IOMUX_EXINTC1_EXINT1_GPF_Msk        (0x1U << IOMUX_EXINTC1_EXINT1_GPF_Pos)  /*!< 0x00000040 */
#define IOMUX_EXINTC1_EXINT1_GPF            IOMUX_EXINTC1_EXINT1_GPF_Msk            /*!< GPIOF pin 1 */

/*!< EXINT2 configuration */
#define IOMUX_EXINTC1_EXINT2_Pos            (8U)
#define IOMUX_EXINTC1_EXINT2_Msk            (0xFU << IOMUX_EXINTC1_EXINT2_Pos)      /*!< 0x00000F00 */
#define IOMUX_EXINTC1_EXINT2                IOMUX_EXINTC1_EXINT2_Msk                /*!< EXINT2[3:0] bits (EXINT2 input source configuration) */

#define IOMUX_EXINTC1_EXINT2_GPA            0x00000000U                             /*!< GPIOA pin 2 */
#define IOMUX_EXINTC1_EXINT2_GPB_Pos        (8U)
#define IOMUX_EXINTC1_EXINT2_GPB_Msk        (0x1U << IOMUX_EXINTC1_EXINT2_GPB_Pos)  /*!< 0x00000100 */
#define IOMUX_EXINTC1_EXINT2_GPB            IOMUX_EXINTC1_EXINT2_GPB_Msk            /*!< GPIOB pin 2 */
#define IOMUX_EXINTC1_EXINT2_GPC_Pos        (9U)
#define IOMUX_EXINTC1_EXINT2_GPC_Msk        (0x1U << IOMUX_EXINTC1_EXINT2_GPC_Pos)  /*!< 0x00000200 */
#define IOMUX_EXINTC1_EXINT2_GPC            IOMUX_EXINTC1_EXINT2_GPC_Msk            /*!< GPIOC pin 2 */
#define IOMUX_EXINTC1_EXINT2_GPD_Pos        (8U)
#define IOMUX_EXINTC1_EXINT2_GPD_Msk        (0x3U << IOMUX_EXINTC1_EXINT2_GPD_Pos)  /*!< 0x00000300 */
#define IOMUX_EXINTC1_EXINT2_GPD            IOMUX_EXINTC1_EXINT2_GPD_Msk            /*!< GPIOD pin 2 */
#define IOMUX_EXINTC1_EXINT2_GPF_Pos        (10U)
#define IOMUX_EXINTC1_EXINT2_GPF_Msk        (0x1U << IOMUX_EXINTC1_EXINT2_GPF_Pos)  /*!< 0x00000400 */
#define IOMUX_EXINTC1_EXINT2_GPF            IOMUX_EXINTC1_EXINT2_GPF_Msk            /*!< GPIOF pin 2 */

/*!< EXINT3 configuration */
#define IOMUX_EXINTC1_EXINT3_Pos            (12U)
#define IOMUX_EXINTC1_EXINT3_Msk            (0xFU << IOMUX_EXINTC1_EXINT3_Pos)      /*!< 0x0000F000 */
#define IOMUX_EXINTC1_EXINT3                IOMUX_EXINTC1_EXINT3_Msk                /*!< EXINT3[3:0] bits (EXINT3 input source configuration) */

#define IOMUX_EXINTC1_EXINT3_GPA            0x00000000U                             /*!< GPIOA pin 3 */
#define IOMUX_EXINTC1_EXINT3_GPB_Pos        (12U)
#define IOMUX_EXINTC1_EXINT3_GPB_Msk        (0x1U << IOMUX_EXINTC1_EXINT3_GPB_Pos)  /*!< 0x00001000 */
#define IOMUX_EXINTC1_EXINT3_GPB            IOMUX_EXINTC1_EXINT3_GPB_Msk            /*!< GPIOB pin 3 */
#define IOMUX_EXINTC1_EXINT3_GPC_Pos        (13U)
#define IOMUX_EXINTC1_EXINT3_GPC_Msk        (0x1U << IOMUX_EXINTC1_EXINT3_GPC_Pos)  /*!< 0x00002000 */
#define IOMUX_EXINTC1_EXINT3_GPC            IOMUX_EXINTC1_EXINT3_GPC_Msk            /*!< GPIOC pin 3 */
#define IOMUX_EXINTC1_EXINT3_GPD_Pos        (12U)
#define IOMUX_EXINTC1_EXINT3_GPD_Msk        (0x3U << IOMUX_EXINTC1_EXINT3_GPD_Pos)  /*!< 0x00003000 */
#define IOMUX_EXINTC1_EXINT3_GPD            IOMUX_EXINTC1_EXINT3_GPD_Msk            /*!< GPIOD pin 3 */
#define IOMUX_EXINTC1_EXINT3_GPF_Pos        (14U)
#define IOMUX_EXINTC1_EXINT3_GPF_Msk        (0x1U << IOMUX_EXINTC1_EXINT3_GPF_Pos)  /*!< 0x00004000 */
#define IOMUX_EXINTC1_EXINT3_GPF            IOMUX_EXINTC1_EXINT3_GPF_Msk            /*!< GPIOF pin 3 */

/****************  Bit definition for IOMUX_EXINTC2 register  *****************/
/*!< EXINT4 configuration */
#define IOMUX_EXINTC2_EXINT4_Pos            (0U)
#define IOMUX_EXINTC2_EXINT4_Msk            (0xFU << IOMUX_EXINTC2_EXINT4_Pos)      /*!< 0x0000000F */
#define IOMUX_EXINTC2_EXINT4                IOMUX_EXINTC2_EXINT4_Msk                /*!< EXINT4[3:0] bits (EXINT4 input source configuration) */

#define IOMUX_EXINTC2_EXINT4_GPA            0x00000000U                             /*!< GPIOA pin 4 */
#define IOMUX_EXINTC2_EXINT4_GPB_Pos        (0U)
#define IOMUX_EXINTC2_EXINT4_GPB_Msk        (0x1U << IOMUX_EXINTC2_EXINT4_GPB_Pos)  /*!< 0x00000001 */
#define IOMUX_EXINTC2_EXINT4_GPB            IOMUX_EXINTC2_EXINT4_GPB_Msk            /*!< GPIOB pin 4 */
#define IOMUX_EXINTC2_EXINT4_GPC_Pos        (1U)
#define IOMUX_EXINTC2_EXINT4_GPC_Msk        (0x1U << IOMUX_EXINTC2_EXINT4_GPC_Pos)  /*!< 0x00000002 */
#define IOMUX_EXINTC2_EXINT4_GPC            IOMUX_EXINTC2_EXINT4_GPC_Msk            /*!< GPIOC pin 4 */
#define IOMUX_EXINTC2_EXINT4_GPD_Pos        (0U)
#define IOMUX_EXINTC2_EXINT4_GPD_Msk        (0x3U << IOMUX_EXINTC2_EXINT4_GPD_Pos)  /*!< 0x00000003 */
#define IOMUX_EXINTC2_EXINT4_GPD            IOMUX_EXINTC2_EXINT4_GPD_Msk            /*!< GPIOD pin 4 */
#define IOMUX_EXINTC2_EXINT4_GPF_Pos        (2U)
#define IOMUX_EXINTC2_EXINT4_GPF_Msk        (0x1U << IOMUX_EXINTC2_EXINT4_GPF_Pos)  /*!< 0x00000004 */
#define IOMUX_EXINTC2_EXINT4_GPF            IOMUX_EXINTC2_EXINT4_GPF_Msk            /*!< GPIOF pin 4 */

/* EXINT5 configuration */
#define IOMUX_EXINTC2_EXINT5_Pos            (4U)
#define IOMUX_EXINTC2_EXINT5_Msk            (0xFU << IOMUX_EXINTC2_EXINT5_Pos)      /*!< 0x000000F0 */
#define IOMUX_EXINTC2_EXINT5                IOMUX_EXINTC2_EXINT5_Msk                /*!< EXINT5[3:0] bits (EXINT5 input source configuration) */

#define IOMUX_EXINTC2_EXINT5_GPA            0x00000000U                             /*!< GPIOA pin 5 */
#define IOMUX_EXINTC2_EXINT5_GPB_Pos        (4U)
#define IOMUX_EXINTC2_EXINT5_GPB_Msk        (0x1U << IOMUX_EXINTC2_EXINT5_GPB_Pos)  /*!< 0x00000010 */
#define IOMUX_EXINTC2_EXINT5_GPB            IOMUX_EXINTC2_EXINT5_GPB_Msk            /*!< GPIOB pin 5 */
#define IOMUX_EXINTC2_EXINT5_GPC_Pos        (5U)
#define IOMUX_EXINTC2_EXINT5_GPC_Msk        (0x1U << IOMUX_EXINTC2_EXINT5_GPC_Pos)  /*!< 0x00000020 */
#define IOMUX_EXINTC2_EXINT5_GPC            IOMUX_EXINTC2_EXINT5_GPC_Msk            /*!< GPIOC pin 5 */
#define IOMUX_EXINTC2_EXINT5_GPD_Pos        (4U)
#define IOMUX_EXINTC2_EXINT5_GPD_Msk        (0x3U << IOMUX_EXINTC2_EXINT5_GPD_Pos)  /*!< 0x00000030 */
#define IOMUX_EXINTC2_EXINT5_GPD            IOMUX_EXINTC2_EXINT5_GPD_Msk            /*!< GPIOD pin 5 */
#define IOMUX_EXINTC2_EXINT5_GPF_Pos        (6U)
#define IOMUX_EXINTC2_EXINT5_GPF_Msk        (0x1U << IOMUX_EXINTC2_EXINT5_GPF_Pos)  /*!< 0x00000040 */
#define IOMUX_EXINTC2_EXINT5_GPF            IOMUX_EXINTC2_EXINT5_GPF_Msk            /*!< GPIOF pin 5 */

/*!< EXINT6 configuration */
#define IOMUX_EXINTC2_EXINT6_Pos            (8U)
#define IOMUX_EXINTC2_EXINT6_Msk            (0xFU << IOMUX_EXINTC2_EXINT6_Pos)      /*!< 0x00000F00 */
#define IOMUX_EXINTC2_EXINT6                IOMUX_EXINTC2_EXINT6_Msk                /*!< EXINT6[3:0] bits (EXINT6 input source configuration) */

#define IOMUX_EXINTC2_EXINT6_GPA            0x00000000U                             /*!< GPIOA pin 6 */
#define IOMUX_EXINTC2_EXINT6_GPB_Pos        (8U)
#define IOMUX_EXINTC2_EXINT6_GPB_Msk        (0x1U << IOMUX_EXINTC2_EXINT6_GPB_Pos)  /*!< 0x00000100 */
#define IOMUX_EXINTC2_EXINT6_GPB            IOMUX_EXINTC2_EXINT6_GPB_Msk            /*!< GPIOB pin 6 */
#define IOMUX_EXINTC2_EXINT6_GPC_Pos        (9U)
#define IOMUX_EXINTC2_EXINT6_GPC_Msk        (0x1U << IOMUX_EXINTC2_EXINT6_GPC_Pos)  /*!< 0x00000200 */
#define IOMUX_EXINTC2_EXINT6_GPC            IOMUX_EXINTC2_EXINT6_GPC_Msk            /*!< GPIOC pin 6 */
#define IOMUX_EXINTC2_EXINT6_GPD_Pos        (8U)
#define IOMUX_EXINTC2_EXINT6_GPD_Msk        (0x3U << IOMUX_EXINTC2_EXINT6_GPD_Pos)  /*!< 0x00000300 */
#define IOMUX_EXINTC2_EXINT6_GPD            IOMUX_EXINTC2_EXINT6_GPD_Msk            /*!< GPIOD pin 6 */
#define IOMUX_EXINTC2_EXINT6_GPF_Pos        (10U)
#define IOMUX_EXINTC2_EXINT6_GPF_Msk        (0x1U << IOMUX_EXINTC2_EXINT6_GPF_Pos)  /*!< 0x00000400 */
#define IOMUX_EXINTC2_EXINT6_GPF            IOMUX_EXINTC2_EXINT6_GPF_Msk            /*!< GPIOF pin 6 */

/*!< EXINT7 configuration */
#define IOMUX_EXINTC2_EXINT7_Pos            (12U)
#define IOMUX_EXINTC2_EXINT7_Msk            (0xFU << IOMUX_EXINTC2_EXINT7_Pos)      /*!< 0x0000F000 */
#define IOMUX_EXINTC2_EXINT7                IOMUX_EXINTC2_EXINT7_Msk                /*!< EXINT7[3:0] bits (EXINT7 input source configuration) */

#define IOMUX_EXINTC2_EXINT7_GPA            0x00000000U                             /*!< GPIOA pin 7 */
#define IOMUX_EXINTC2_EXINT7_GPB_Pos        (12U)
#define IOMUX_EXINTC2_EXINT7_GPB_Msk        (0x1U << IOMUX_EXINTC2_EXINT7_GPB_Pos)  /*!< 0x00001000 */
#define IOMUX_EXINTC2_EXINT7_GPB            IOMUX_EXINTC2_EXINT7_GPB_Msk            /*!< GPIOB pin 7 */
#define IOMUX_EXINTC2_EXINT7_GPC_Pos        (13U)
#define IOMUX_EXINTC2_EXINT7_GPC_Msk        (0x1U << IOMUX_EXINTC2_EXINT7_GPC_Pos)  /*!< 0x00002000 */
#define IOMUX_EXINTC2_EXINT7_GPC            IOMUX_EXINTC2_EXINT7_GPC_Msk            /*!< GPIOC pin 7 */
#define IOMUX_EXINTC2_EXINT7_GPD_Pos        (12U)
#define IOMUX_EXINTC2_EXINT7_GPD_Msk        (0x3U << IOMUX_EXINTC2_EXINT7_GPD_Pos)  /*!< 0x00003000 */
#define IOMUX_EXINTC2_EXINT7_GPD            IOMUX_EXINTC2_EXINT7_GPD_Msk            /*!< GPIOD pin 7 */
#define IOMUX_EXINTC2_EXINT7_GPF_Pos        (14U)
#define IOMUX_EXINTC2_EXINT7_GPF_Msk        (0x1U << IOMUX_EXINTC2_EXINT7_GPF_Pos)  /*!< 0x00004000 */
#define IOMUX_EXINTC2_EXINT7_GPF            IOMUX_EXINTC2_EXINT7_GPF_Msk            /*!< GPIOF pin 7 */

/****************  Bit definition for IOMUX_EXINTC3 register  *****************/
/*!< EXINT8 configuration */
#define IOMUX_EXINTC3_EXINT8_Pos            (0U)
#define IOMUX_EXINTC3_EXINT8_Msk            (0xFU << IOMUX_EXINTC3_EXINT8_Pos)      /*!< 0x0000000F */
#define IOMUX_EXINTC3_EXINT8                IOMUX_EXINTC3_EXINT8_Msk                /*!< EXINT8[3:0] bits (EXINT8 input source configuration) */

#define IOMUX_EXINTC3_EXINT8_GPA            0x00000000U                             /*!< GPIOA pin 8 */
#define IOMUX_EXINTC3_EXINT8_GPB_Pos        (0U)
#define IOMUX_EXINTC3_EXINT8_GPB_Msk        (0x1U << IOMUX_EXINTC3_EXINT8_GPB_Pos)  /*!< 0x00000001 */
#define IOMUX_EXINTC3_EXINT8_GPB            IOMUX_EXINTC3_EXINT8_GPB_Msk            /*!< GPIOB pin 8 */
#define IOMUX_EXINTC3_EXINT8_GPC_Pos        (1U)
#define IOMUX_EXINTC3_EXINT8_GPC_Msk        (0x1U << IOMUX_EXINTC3_EXINT8_GPC_Pos)  /*!< 0x00000002 */
#define IOMUX_EXINTC3_EXINT8_GPC            IOMUX_EXINTC3_EXINT8_GPC_Msk            /*!< GPIOC pin 8 */
#define IOMUX_EXINTC3_EXINT8_GPD_Pos        (0U)
#define IOMUX_EXINTC3_EXINT8_GPD_Msk        (0x3U << IOMUX_EXINTC3_EXINT8_GPD_Pos)  /*!< 0x00000003 */
#define IOMUX_EXINTC3_EXINT8_GPD            IOMUX_EXINTC3_EXINT8_GPD_Msk            /*!< GPIOD pin 8 */
#define IOMUX_EXINTC3_EXINT8_GPF_Pos        (2U)
#define IOMUX_EXINTC3_EXINT8_GPF_Msk        (0x1U << IOMUX_EXINTC3_EXINT8_GPF_Pos)  /*!< 0x00000004 */
#define IOMUX_EXINTC3_EXINT8_GPF            IOMUX_EXINTC3_EXINT8_GPF_Msk            /*!< GPIOF pin 8 */

/*!< EXINT9 configuration */
#define IOMUX_EXINTC3_EXINT9_Pos            (4U)
#define IOMUX_EXINTC3_EXINT9_Msk            (0xFU << IOMUX_EXINTC3_EXINT9_Pos)      /*!< 0x000000F0 */
#define IOMUX_EXINTC3_EXINT9                IOMUX_EXINTC3_EXINT9_Msk                /*!< EXINT9[3:0] bits (EXINT9 input source configuration) */

#define IOMUX_EXINTC3_EXINT9_GPA            0x00000000U                             /*!< GPIOA pin 9 */
#define IOMUX_EXINTC3_EXINT9_GPB_Pos        (4U)
#define IOMUX_EXINTC3_EXINT9_GPB_Msk        (0x1U << IOMUX_EXINTC3_EXINT9_GPB_Pos)  /*!< 0x00000010 */
#define IOMUX_EXINTC3_EXINT9_GPB            IOMUX_EXINTC3_EXINT9_GPB_Msk            /*!< GPIOB pin 9 */
#define IOMUX_EXINTC3_EXINT9_GPC_Pos        (5U)
#define IOMUX_EXINTC3_EXINT9_GPC_Msk        (0x1U << IOMUX_EXINTC3_EXINT9_GPC_Pos)  /*!< 0x00000020 */
#define IOMUX_EXINTC3_EXINT9_GPC            IOMUX_EXINTC3_EXINT9_GPC_Msk            /*!< GPIOC pin 9 */
#define IOMUX_EXINTC3_EXINT9_GPD_Pos        (4U)
#define IOMUX_EXINTC3_EXINT9_GPD_Msk        (0x3U << IOMUX_EXINTC3_EXINT9_GPD_Pos)  /*!< 0x00000030 */
#define IOMUX_EXINTC3_EXINT9_GPD            IOMUX_EXINTC3_EXINT9_GPD_Msk            /*!< GPIOD pin 9 */
#define IOMUX_EXINTC3_EXINT9_GPF_Pos        (6U)
#define IOMUX_EXINTC3_EXINT9_GPF_Msk        (0x1U << IOMUX_EXINTC3_EXINT9_GPF_Pos)  /*!< 0x00000040 */
#define IOMUX_EXINTC3_EXINT9_GPF            IOMUX_EXINTC3_EXINT9_GPF_Msk            /*!< GPIOF pin 9 */

/*!< EXINT10 configuration */
#define IOMUX_EXINTC3_EXINT10_Pos           (8U)
#define IOMUX_EXINTC3_EXINT10_Msk           (0xFU << IOMUX_EXINTC3_EXINT10_Pos)     /*!< 0x00000F00 */
#define IOMUX_EXINTC3_EXINT10               IOMUX_EXINTC3_EXINT10_Msk               /*!< EXINT10[3:0] bits (EXINT10 input source configuration) */

#define IOMUX_EXINTC3_EXINT10_GPA           0x00000000U                             /*!< GPIOA pin 10 */
#define IOMUX_EXINTC3_EXINT10_GPB_Pos       (8U)
#define IOMUX_EXINTC3_EXINT10_GPB_Msk       (0x1U << IOMUX_EXINTC3_EXINT10_GPB_Pos) /*!< 0x00000100 */
#define IOMUX_EXINTC3_EXINT10_GPB           IOMUX_EXINTC3_EXINT10_GPB_Msk           /*!< GPIOB pin 10 */
#define IOMUX_EXINTC3_EXINT10_GPC_Pos       (9U)
#define IOMUX_EXINTC3_EXINT10_GPC_Msk       (0x1U << IOMUX_EXINTC3_EXINT10_GPC_Pos) /*!< 0x00000200 */
#define IOMUX_EXINTC3_EXINT10_GPC           IOMUX_EXINTC3_EXINT10_GPC_Msk           /*!< GPIOC pin 10 */
#define IOMUX_EXINTC3_EXINT10_GPD_Pos       (8U)
#define IOMUX_EXINTC3_EXINT10_GPD_Msk       (0x3U << IOMUX_EXINTC3_EXINT10_GPD_Pos) /*!< 0x00000300 */
#define IOMUX_EXINTC3_EXINT10_GPD           IOMUX_EXINTC3_EXINT10_GPD_Msk           /*!< GPIOD pin 10 */
#define IOMUX_EXINTC3_EXINT10_GPF_Pos       (10U)
#define IOMUX_EXINTC3_EXINT10_GPF_Msk       (0x1U << IOMUX_EXINTC3_EXINT10_GPF_Pos) /*!< 0x00000400 */
#define IOMUX_EXINTC3_EXINT10_GPF           IOMUX_EXINTC3_EXINT10_GPF_Msk           /*!< GPIOF pin 10 */

/*!< EXINT11 configuration */
#define IOMUX_EXINTC3_EXINT11_Pos           (12U)
#define IOMUX_EXINTC3_EXINT11_Msk           (0xFU << IOMUX_EXINTC3_EXINT11_Pos)     /*!< 0x0000F000 */
#define IOMUX_EXINTC3_EXINT11               IOMUX_EXINTC3_EXINT11_Msk               /*!< EXINT11[3:0] bits (EXINT11 input source configuration) */

#define IOMUX_EXINTC3_EXINT11_GPA           0x00000000U                             /*!< GPIOA pin 11 */
#define IOMUX_EXINTC3_EXINT11_GPB_Pos       (12U)
#define IOMUX_EXINTC3_EXINT11_GPB_Msk       (0x1U << IOMUX_EXINTC3_EXINT11_GPB_Pos) /*!< 0x00001000 */
#define IOMUX_EXINTC3_EXINT11_GPB           IOMUX_EXINTC3_EXINT11_GPB_Msk           /*!< GPIOB pin 11 */
#define IOMUX_EXINTC3_EXINT11_GPC_Pos       (13U)
#define IOMUX_EXINTC3_EXINT11_GPC_Msk       (0x1U << IOMUX_EXINTC3_EXINT11_GPC_Pos) /*!< 0x00002000 */
#define IOMUX_EXINTC3_EXINT11_GPC           IOMUX_EXINTC3_EXINT11_GPC_Msk           /*!< GPIOC pin 11 */
#define IOMUX_EXINTC3_EXINT11_GPD_Pos       (12U)
#define IOMUX_EXINTC3_EXINT11_GPD_Msk       (0x3U << IOMUX_EXINTC3_EXINT11_GPD_Pos) /*!< 0x00003000 */
#define IOMUX_EXINTC3_EXINT11_GPD           IOMUX_EXINTC3_EXINT11_GPD_Msk           /*!< GPIOD pin 11 */
#define IOMUX_EXINTC3_EXINT11_GPF_Pos       (14U)
#define IOMUX_EXINTC3_EXINT11_GPF_Msk       (0x1U << IOMUX_EXINTC3_EXINT11_GPF_Pos) /*!< 0x00004000 */
#define IOMUX_EXINTC3_EXINT11_GPF           IOMUX_EXINTC3_EXINT11_GPF_Msk           /*!< GPIOF pin 11 */

/****************  Bit definition for IOMUX_EXINTC4 register  *****************/
/* EXINT12 configuration */
#define IOMUX_EXINTC4_EXINT12_Pos           (0U)
#define IOMUX_EXINTC4_EXINT12_Msk           (0xFU << IOMUX_EXINTC4_EXINT12_Pos)     /*!< 0x0000000F */
#define IOMUX_EXINTC4_EXINT12               IOMUX_EXINTC4_EXINT12_Msk               /*!< EXINT12[3:0] bits (EXINT12 input source configuration) */

#define IOMUX_EXINTC4_EXINT12_GPA           0x00000000U                             /*!< GPIOA pin 12 */
#define IOMUX_EXINTC4_EXINT12_GPB_Pos       (0U)
#define IOMUX_EXINTC4_EXINT12_GPB_Msk       (0x1U << IOMUX_EXINTC4_EXINT12_GPB_Pos) /*!< 0x00000001 */
#define IOMUX_EXINTC4_EXINT12_GPB           IOMUX_EXINTC4_EXINT12_GPB_Msk           /*!< GPIOB pin 12 */
#define IOMUX_EXINTC4_EXINT12_GPC_Pos       (1U)
#define IOMUX_EXINTC4_EXINT12_GPC_Msk       (0x1U << IOMUX_EXINTC4_EXINT12_GPC_Pos) /*!< 0x00000002 */
#define IOMUX_EXINTC4_EXINT12_GPC           IOMUX_EXINTC4_EXINT12_GPC_Msk           /*!< GPIOC pin 12 */
#define IOMUX_EXINTC4_EXINT12_GPD_Pos       (0U)
#define IOMUX_EXINTC4_EXINT12_GPD_Msk       (0x3U << IOMUX_EXINTC4_EXINT12_GPD_Pos) /*!< 0x00000003 */
#define IOMUX_EXINTC4_EXINT12_GPD           IOMUX_EXINTC4_EXINT12_GPD_Msk           /*!< GPIOD pin 12 */
#define IOMUX_EXINTC4_EXINT12_GPF_Pos       (2U)
#define IOMUX_EXINTC4_EXINT12_GPF_Msk       (0x1U << IOMUX_EXINTC4_EXINT12_GPF_Pos) /*!< 0x00000004 */
#define IOMUX_EXINTC4_EXINT12_GPF           IOMUX_EXINTC4_EXINT12_GPF_Msk           /*!< GPIOF pin 12 */

/* EXINT13 configuration */
#define IOMUX_EXINTC4_EXINT13_Pos           (4U)
#define IOMUX_EXINTC4_EXINT13_Msk           (0xFU << IOMUX_EXINTC4_EXINT13_Pos)     /*!< 0x000000F0 */
#define IOMUX_EXINTC4_EXINT13               IOMUX_EXINTC4_EXINT13_Msk               /*!< EXINT13[3:0] bits (EXINT13 input source configuration) */

#define IOMUX_EXINTC4_EXINT13_GPA           0x00000000U                             /*!< GPIOA pin 13 */
#define IOMUX_EXINTC4_EXINT13_GPB_Pos       (4U)
#define IOMUX_EXINTC4_EXINT13_GPB_Msk       (0x1U << IOMUX_EXINTC4_EXINT13_GPB_Pos) /*!< 0x00000010 */
#define IOMUX_EXINTC4_EXINT13_GPB           IOMUX_EXINTC4_EXINT13_GPB_Msk           /*!< GPIOB pin 13 */
#define IOMUX_EXINTC4_EXINT13_GPC_Pos       (5U)
#define IOMUX_EXINTC4_EXINT13_GPC_Msk       (0x1U << IOMUX_EXINTC4_EXINT13_GPC_Pos) /*!< 0x00000020 */
#define IOMUX_EXINTC4_EXINT13_GPC           IOMUX_EXINTC4_EXINT13_GPC_Msk           /*!< GPIOC pin 13 */
#define IOMUX_EXINTC4_EXINT13_GPD_Pos       (4U)
#define IOMUX_EXINTC4_EXINT13_GPD_Msk       (0x3U << IOMUX_EXINTC4_EXINT13_GPD_Pos) /*!< 0x00000030 */
#define IOMUX_EXINTC4_EXINT13_GPD           IOMUX_EXINTC4_EXINT13_GPD_Msk           /*!< GPIOD pin 13 */
#define IOMUX_EXINTC4_EXINT13_GPF_Pos       (6U)
#define IOMUX_EXINTC4_EXINT13_GPF_Msk       (0x1U << IOMUX_EXINTC4_EXINT13_GPF_Pos) /*!< 0x00000040 */
#define IOMUX_EXINTC4_EXINT13_GPF           IOMUX_EXINTC4_EXINT13_GPF_Msk           /*!< GPIOF pin 13 */

/*!< EXINT14 configuration */
#define IOMUX_EXINTC4_EXINT14_Pos           (8U)
#define IOMUX_EXINTC4_EXINT14_Msk           (0xFU << IOMUX_EXINTC4_EXINT14_Pos)     /*!< 0x00000F00 */
#define IOMUX_EXINTC4_EXINT14               IOMUX_EXINTC4_EXINT14_Msk               /*!< EXINT14[3:0] bits (EXINT14 input source configuration) */

#define IOMUX_EXINTC4_EXINT14_GPA           0x00000000U                             /*!< GPIOA pin 14 */
#define IOMUX_EXINTC4_EXINT14_GPB_Pos       (8U)
#define IOMUX_EXINTC4_EXINT14_GPB_Msk       (0x1U << IOMUX_EXINTC4_EXINT14_GPB_Pos) /*!< 0x00000100 */
#define IOMUX_EXINTC4_EXINT14_GPB           IOMUX_EXINTC4_EXINT14_GPB_Msk           /*!< GPIOB pin 14 */
#define IOMUX_EXINTC4_EXINT14_GPC_Pos       (9U)
#define IOMUX_EXINTC4_EXINT14_GPC_Msk       (0x1U << IOMUX_EXINTC4_EXINT14_GPC_Pos) /*!< 0x00000200 */
#define IOMUX_EXINTC4_EXINT14_GPC           IOMUX_EXINTC4_EXINT14_GPC_Msk           /*!< GPIOC pin 14 */
#define IOMUX_EXINTC4_EXINT14_GPD_Pos       (8U)
#define IOMUX_EXINTC4_EXINT14_GPD_Msk       (0x3U << IOMUX_EXINTC4_EXINT14_GPD_Pos) /*!< 0x00000300 */
#define IOMUX_EXINTC4_EXINT14_GPD           IOMUX_EXINTC4_EXINT14_GPD_Msk           /*!< GPIOD pin 14 */
#define IOMUX_EXINTC4_EXINT14_GPF_Pos       (10U)
#define IOMUX_EXINTC4_EXINT14_GPF_Msk       (0x1U << IOMUX_EXINTC4_EXINT14_GPF_Pos) /*!< 0x00000400 */
#define IOMUX_EXINTC4_EXINT14_GPF           IOMUX_EXINTC4_EXINT14_GPF_Msk           /*!< GPIOF pin 14 */

/*!< EXINT15 configuration */
#define IOMUX_EXINTC4_EXINT15_Pos           (12U)                             
#define IOMUX_EXINTC4_EXINT15_Msk           (0xFU << IOMUX_EXINTC4_EXINT15_Pos)     /*!< 0x0000F000 */
#define IOMUX_EXINTC4_EXINT15               IOMUX_EXINTC4_EXINT15_Msk               /*!< EXINT15[3:0] bits (EXINT15 input source configuration) */

#define IOMUX_EXINTC4_EXINT15_GPA           0x00000000U                             /*!< GPIOA pin 15 */
#define IOMUX_EXINTC4_EXINT15_GPB_Pos       (12U)
#define IOMUX_EXINTC4_EXINT15_GPB_Msk       (0x1U << IOMUX_EXINTC4_EXINT15_GPB_Pos) /*!< 0x00001000 */
#define IOMUX_EXINTC4_EXINT15_GPB           IOMUX_EXINTC4_EXINT15_GPB_Msk           /*!< GPIOB pin 15 */
#define IOMUX_EXINTC4_EXINT15_GPC_Pos       (13U)
#define IOMUX_EXINTC4_EXINT15_GPC_Msk       (0x1U << IOMUX_EXINTC4_EXINT15_GPC_Pos) /*!< 0x00002000 */
#define IOMUX_EXINTC4_EXINT15_GPC           IOMUX_EXINTC4_EXINT15_GPC_Msk           /*!< GPIOC pin 15 */
#define IOMUX_EXINTC4_EXINT15_GPD_Pos       (12U)
#define IOMUX_EXINTC4_EXINT15_GPD_Msk       (0x3U << IOMUX_EXINTC4_EXINT15_GPD_Pos) /*!< 0x00003000 */
#define IOMUX_EXINTC4_EXINT15_GPD           IOMUX_EXINTC4_EXINT15_GPD_Msk           /*!< GPIOD pin 15 */
#define IOMUX_EXINTC4_EXINT15_GPF_Pos       (14U)
#define IOMUX_EXINTC4_EXINT15_GPF_Msk       (0x1U << IOMUX_EXINTC4_EXINT15_GPF_Pos) /*!< 0x00004000 */
#define IOMUX_EXINTC4_EXINT15_GPF           IOMUX_EXINTC4_EXINT15_GPF_Msk           /*!< GPIOF pin 15 */

/*****************  Bit definition for IOMUX_REMAP2 register  *****************/
/*!< CMP_MUX configuration */
#define IOMUX_REMAP2_CMP_MUX_Pos            (26U)
#define IOMUX_REMAP2_CMP_MUX_Msk            (0x3U << IOMUX_REMAP2_CMP_MUX_Pos)      /*!< 0x0C000000 */
#define IOMUX_REMAP2_CMP_MUX                IOMUX_REMAP2_CMP_MUX_Msk                /*!< CMP_MUX[1:0] bits (CMP internal remap) */
#define IOMUX_REMAP2_CMP_MUX_0              (0x1U << IOMUX_REMAP2_CMP_MUX_Pos)      /*!< 0x04000000 */
#define IOMUX_REMAP2_CMP_MUX_1              (0x2U << IOMUX_REMAP2_CMP_MUX_Pos)      /*!< 0x08000000 */

#define IOMUX_REMAP2_CMP_MUX_MUX0           0x00000000U                             /*!< CMP1_OUT is connected to PA0, CMP2_OUT is connected to PA2 */
#define IOMUX_REMAP2_CMP_MUX_MUX1_Pos       (26U)
#define IOMUX_REMAP2_CMP_MUX_MUX1_Msk       (0x1U << IOMUX_REMAP2_CMP_MUX_MUX1_Pos) /*!< 0x04000000 */
#define IOMUX_REMAP2_CMP_MUX_MUX1           IOMUX_REMAP2_CMP_MUX_MUX1_Msk           /*!< CMP1_OUT is connected to PA6, CMP2_OUT is connected to PA7 */
#define IOMUX_REMAP2_CMP_MUX_MUX2_Pos       (27U)
#define IOMUX_REMAP2_CMP_MUX_MUX2_Msk       (0x1U << IOMUX_REMAP2_CMP_MUX_MUX2_Pos) /*!< 0x08000000 */
#define IOMUX_REMAP2_CMP_MUX_MUX2           IOMUX_REMAP2_CMP_MUX_MUX2_Msk           /*!< CMP1_OUT is connected to PA11, CMP2_OUT is connected to PA12 */

/*****************  Bit definition for IOMUX_REMAP3 register  *****************/
/*!< TMR9_GMUX configuration */
#define IOMUX_REMAP3_TMR9_GMUX_Pos          (0U)
#define IOMUX_REMAP3_TMR9_GMUX_Msk          (0xFU << IOMUX_REMAP3_TMR9_GMUX_Pos)    /*!< 0x0000000F */
#define IOMUX_REMAP3_TMR9_GMUX              IOMUX_REMAP3_TMR9_GMUX_Msk              /*!< TMR9_GMUX[3:0] bits (TMR9 IO general multiplexing) */
#define IOMUX_REMAP3_TMR9_GMUX_0            (0x1U << IOMUX_REMAP3_TMR9_GMUX_Pos)    /*!< 0x00000001 */
#define IOMUX_REMAP3_TMR9_GMUX_1            (0x2U << IOMUX_REMAP3_TMR9_GMUX_Pos)    /*!< 0x00000002 */
#define IOMUX_REMAP3_TMR9_GMUX_2            (0x4U << IOMUX_REMAP3_TMR9_GMUX_Pos)    /*!< 0x00000004 */
#define IOMUX_REMAP3_TMR9_GMUX_3            (0x8U << IOMUX_REMAP3_TMR9_GMUX_Pos)    /*!< 0x00000008 */

#define IOMUX_REMAP3_TMR9_GMUX_MUX0         0x00000000U                             /*!< CH1/PA2, CH2/PA3 */
#define IOMUX_REMAP3_TMR9_GMUX_MUX2_Pos     (1U)                                    /*!< 0x00000002 */
#define IOMUX_REMAP3_TMR9_GMUX_MUX2_Msk     (0x1U << IOMUX_REMAP3_TMR9_GMUX_MUX2_Pos)
#define IOMUX_REMAP3_TMR9_GMUX_MUX2         IOMUX_REMAP3_TMR9_GMUX_MUX2_Msk         /*!< CH1/PB14, CH2/PB15 */

/*!< TMR10_GMUX configuration */
#define IOMUX_REMAP3_TMR10_GMUX_Pos         (4U)
#define IOMUX_REMAP3_TMR10_GMUX_Msk         (0xFU << IOMUX_REMAP3_TMR10_GMUX_Pos)   /*!< 0x000000F0 */
#define IOMUX_REMAP3_TMR10_GMUX             IOMUX_REMAP3_TMR10_GMUX_Msk             /*!< TMR10_GMUX[3:0] bits (TMR10 IO general multiplexing) */
#define IOMUX_REMAP3_TMR10_GMUX_0           (0x1U << IOMUX_REMAP3_TMR10_GMUX_Pos)   /*!< 0x00000010 */
#define IOMUX_REMAP3_TMR10_GMUX_1           (0x2U << IOMUX_REMAP3_TMR10_GMUX_Pos)   /*!< 0x00000020 */
#define IOMUX_REMAP3_TMR10_GMUX_2           (0x4U << IOMUX_REMAP3_TMR10_GMUX_Pos)   /*!< 0x00000040 */
#define IOMUX_REMAP3_TMR10_GMUX_3           (0x8U << IOMUX_REMAP3_TMR10_GMUX_Pos)   /*!< 0x00000080 */

#define IOMUX_REMAP3_TMR10_GMUX_MUX0        0x00000000U                             /*!< CH1/PB8 */
#define IOMUX_REMAP3_TMR10_GMUX_MUX2_Pos    (5U)                                    /*!< 0x00000020 */
#define IOMUX_REMAP3_TMR10_GMUX_MUX2_Msk    (0x1U << IOMUX_REMAP3_TMR10_GMUX_MUX2_Pos)
#define IOMUX_REMAP3_TMR10_GMUX_MUX2        IOMUX_REMAP3_TMR10_GMUX_MUX2_Msk        /*!< CH1/PA6 */

/*!< TMR11_GMUX configuration */
#define IOMUX_REMAP3_TMR11_GMUX_Pos         (8U)
#define IOMUX_REMAP3_TMR11_GMUX_Msk         (0xFU << IOMUX_REMAP3_TMR11_GMUX_Pos)   /*!< 0x00000F00 */
#define IOMUX_REMAP3_TMR11_GMUX             IOMUX_REMAP3_TMR11_GMUX_Msk             /*!< TMR11_GMUX[3:0] bits (TMR11 IO general multiplexing) */
#define IOMUX_REMAP3_TMR11_GMUX_0           (0x1U << IOMUX_REMAP3_TMR11_GMUX_Pos)   /*!< 0x00000100 */
#define IOMUX_REMAP3_TMR11_GMUX_1           (0x2U << IOMUX_REMAP3_TMR11_GMUX_Pos)   /*!< 0x00000200 */
#define IOMUX_REMAP3_TMR11_GMUX_2           (0x4U << IOMUX_REMAP3_TMR11_GMUX_Pos)   /*!< 0x00000400 */
#define IOMUX_REMAP3_TMR11_GMUX_3           (0x8U << IOMUX_REMAP3_TMR11_GMUX_Pos)   /*!< 0x00000800 */

#define IOMUX_REMAP3_TMR11_GMUX_MUX0        0x00000000U                             /*!< CH1/PB9 */
#define IOMUX_REMAP3_TMR11_GMUX_MUX2_Pos    (9U)                                    /*!< 0x00000002 */
#define IOMUX_REMAP3_TMR11_GMUX_MUX2_Msk    (0x1U << IOMUX_REMAP3_TMR11_GMUX_MUX2_Pos)
#define IOMUX_REMAP3_TMR11_GMUX_MUX2        IOMUX_REMAP3_TMR11_GMUX_MUX2_Msk        /*!< CH1/PA7 */

/*****************  Bit definition for IOMUX_REMAP4 register  *****************/
/*!< TMR1_GMUX configuration */
#define IOMUX_REMAP4_TMR1_GMUX_Pos          (0U)
#define IOMUX_REMAP4_TMR1_GMUX_Msk          (0xFU << IOMUX_REMAP4_TMR1_GMUX_Pos)    /*!< 0x0000000F */
#define IOMUX_REMAP4_TMR1_GMUX              IOMUX_REMAP4_TMR1_GMUX_Msk              /*!< TMR1_GMUX[3:0] bits (TMR1 IO general multiplexing) */
#define IOMUX_REMAP4_TMR1_GMUX_0            (0x1U << IOMUX_REMAP4_TMR1_GMUX_Pos)    /*!< 0x00000001 */
#define IOMUX_REMAP4_TMR1_GMUX_1            (0x2U << IOMUX_REMAP4_TMR1_GMUX_Pos)    /*!< 0x00000002 */
#define IOMUX_REMAP4_TMR1_GMUX_2            (0x4U << IOMUX_REMAP4_TMR1_GMUX_Pos)    /*!< 0x00000004 */
#define IOMUX_REMAP4_TMR1_GMUX_3            (0x8U << IOMUX_REMAP4_TMR1_GMUX_Pos)    /*!< 0x00000008 */

#define IOMUX_REMAP4_TMR1_GMUX_MUX0         0x00000000U                             /*!< EXT/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BRK/PB12, CH1C/PB13, CH2C/PB14, CH3C/PB15 */
#define IOMUX_REMAP4_TMR1_GMUX_MUX1_Pos     (0U)                                    /*!< 0x00000001 */
#define IOMUX_REMAP4_TMR1_GMUX_MUX1_Msk     (0x1U << IOMUX_REMAP4_TMR1_GMUX_MUX1_Pos)
#define IOMUX_REMAP4_TMR1_GMUX_MUX1         IOMUX_REMAP4_TMR1_GMUX_MUX1_Msk         /*!< EXT/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BRK/PA6, CH1C/PA7, CH2C/PB0, CH3C/PB1 */
#define IOMUX_REMAP4_TMR1_GMUX_MUX2_Pos     (1U)                                    /*!< 0x00000002 */
#define IOMUX_REMAP4_TMR1_GMUX_MUX2_Msk     (0x1U << IOMUX_REMAP4_TMR1_GMUX_MUX2_Pos)
#define IOMUX_REMAP4_TMR1_GMUX_MUX2         IOMUX_REMAP4_TMR1_GMUX_MUX2_Msk         /*!< EXT/PA0, CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9, BRK/PA6, CH1C/PA7, CH2C/PB0, CH3C/PB1 */

/*!< TMR2_GMUX configuration */
#define IOMUX_REMAP4_TMR2_GMUX_Pos          (4U)
#define IOMUX_REMAP4_TMR2_GMUX_Msk          (0x7U << IOMUX_REMAP4_TMR2_GMUX_Pos)    /*!< 0x00000070 */
#define IOMUX_REMAP4_TMR2_GMUX              IOMUX_REMAP4_TMR2_GMUX_Msk              /*!< TMR2_GMUX[2:0] bits (TMR2 IO general multiplexing) */
#define IOMUX_REMAP4_TMR2_GMUX_0            (0x1U << IOMUX_REMAP4_TMR2_GMUX_Pos)    /*!< 0x00000010 */
#define IOMUX_REMAP4_TMR2_GMUX_1            (0x2U << IOMUX_REMAP4_TMR2_GMUX_Pos)    /*!< 0x00000020 */
#define IOMUX_REMAP4_TMR2_GMUX_2            (0x4U << IOMUX_REMAP4_TMR2_GMUX_Pos)    /*!< 0x00000040 */

#define IOMUX_REMAP4_TMR2_GMUX_MUX0         0x00000000U                             /*!< CH1_EXT/PA0, CH2/PA1, CH3/PA2, CH4/PA3 */
#define IOMUX_REMAP4_TMR2_GMUX_MUX1_Pos     (4U)                                    /*!< 0x00000010 */
#define IOMUX_REMAP4_TMR2_GMUX_MUX1_Msk     (0x1U << IOMUX_REMAP4_TMR2_GMUX_MUX1_Pos)
#define IOMUX_REMAP4_TMR2_GMUX_MUX1         IOMUX_REMAP4_TMR2_GMUX_MUX1_Msk         /*!< CH1_EXT/PA15, CH2/PB3, CH3/PA2, CH4/PA3 */
#define IOMUX_REMAP4_TMR2_GMUX_MUX2_Pos     (5U)                                    /*!< 0x00000020 */
#define IOMUX_REMAP4_TMR2_GMUX_MUX2_Msk     (0x1U << IOMUX_REMAP4_TMR2_GMUX_MUX2_Pos)
#define IOMUX_REMAP4_TMR2_GMUX_MUX2         IOMUX_REMAP4_TMR2_GMUX_MUX2_Msk         /*!< CH1_EXT/PA0, CH2/PA1, CH3/PB10, CH4/PB11 */
#define IOMUX_REMAP4_TMR2_GMUX_MUX3_Pos     (4U)                                    /*!< 0x00000030 */
#define IOMUX_REMAP4_TMR2_GMUX_MUX3_Msk     (0x3U << IOMUX_REMAP4_TMR2_GMUX_MUX3_Pos)
#define IOMUX_REMAP4_TMR2_GMUX_MUX3         IOMUX_REMAP4_TMR2_GMUX_MUX3_Msk         /*!< CH1_EXT/PA15, CH2/PB3, CH3/PB10, CH4/PB11 */

/*!< TMR3_GMUX configuration */
#define IOMUX_REMAP4_TMR3_GMUX_Pos          (8U)
#define IOMUX_REMAP4_TMR3_GMUX_Msk          (0xFU << IOMUX_REMAP4_TMR3_GMUX_Pos)    /*!< 0x00000F00 */
#define IOMUX_REMAP4_TMR3_GMUX              IOMUX_REMAP4_TMR3_GMUX_Msk              /*!< TMR3_GMUX[3:0] bits (TMR3 IO general multiplexing) */
#define IOMUX_REMAP4_TMR3_GMUX_0            (0x1U << IOMUX_REMAP4_TMR3_GMUX_Pos)    /*!< 0x00000100 */
#define IOMUX_REMAP4_TMR3_GMUX_1            (0x2U << IOMUX_REMAP4_TMR3_GMUX_Pos)    /*!< 0x00000200 */
#define IOMUX_REMAP4_TMR3_GMUX_2            (0x4U << IOMUX_REMAP4_TMR3_GMUX_Pos)    /*!< 0x00000400 */
#define IOMUX_REMAP4_TMR3_GMUX_3            (0x8U << IOMUX_REMAP4_TMR3_GMUX_Pos)    /*!< 0x00000800 */

#define IOMUX_REMAP4_TMR3_GMUX_MUX0         0x00000000U                             /*!< CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1 */
#define IOMUX_REMAP4_TMR3_GMUX_MUX1_Pos     (8U)                                    /*!< 0x00000100 */
#define IOMUX_REMAP4_TMR3_GMUX_MUX1_Msk     (0x1U << IOMUX_REMAP4_TMR3_GMUX_MUX1_Pos)
#define IOMUX_REMAP4_TMR3_GMUX_MUX1         IOMUX_REMAP4_TMR3_GMUX_MUX1_Msk         /*!< CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1 */

/*!< TMR5_GMUX configuration */
#define IOMUX_REMAP4_TMR5_GMUX_Pos          (16U)
#define IOMUX_REMAP4_TMR5_GMUX_Msk          (0x7U << IOMUX_REMAP4_TMR5_GMUX_Pos)    /*!< 0x00070000 */
#define IOMUX_REMAP4_TMR5_GMUX              IOMUX_REMAP4_TMR5_GMUX_Msk              /*!< TMR5_GMUX[2:0] bits (TMR5 IO general multiplexing) */
#define IOMUX_REMAP4_TMR5_GMUX_0            (0x1U << IOMUX_REMAP4_TMR5_GMUX_Pos)    /*!< 0x00010000 */
#define IOMUX_REMAP4_TMR5_GMUX_1            (0x2U << IOMUX_REMAP4_TMR5_GMUX_Pos)    /*!< 0x00020000 */
#define IOMUX_REMAP4_TMR5_GMUX_2            (0x4U << IOMUX_REMAP4_TMR5_GMUX_Pos)    /*!< 0x00040000 */

#define IOMUX_REMAP4_TMR5_GMUX_MUX0         0x00000000U                             /*!< CH1/PA0, CH2/PA1, CH3/PA2, CH4/PA3 */
#define IOMUX_REMAP4_TMR5_GMUX_MUX1_Pos     (16U)                                   /*!< 0x00010000 */
#define IOMUX_REMAP4_TMR5_GMUX_MUX1_Msk     (0x1U << IOMUX_REMAP4_TMR5_GMUX_MUX1_Pos)
#define IOMUX_REMAP4_TMR5_GMUX_MUX1         IOMUX_REMAP4_TMR5_GMUX_MUX1_Msk         /*!< CH1/PF4, CH2/PF5, CH3/PA2, CH4/PA3 */

#define IOMUX_REMAP4_TMR5CH4_GMUX_Pos       (19U)
#define IOMUX_REMAP4_TMR5CH4_GMUX_Msk       (0x1U << IOMUX_REMAP4_TMR5CH4_GMUX_Pos) /*!< 0x00080000 */
#define IOMUX_REMAP4_TMR5CH4_GMUX           IOMUX_REMAP4_TMR5CH4_GMUX_Msk           /*!< TMR5 channel 4 general multiplexing */

/*****************  Bit definition for IOMUX_REMAP5 register  *****************/
/*!< I2C1_GMUX configuration */
#define IOMUX_REMAP5_I2C1_GMUX_Pos          (4U)
#define IOMUX_REMAP5_I2C1_GMUX_Msk          (0xFU << IOMUX_REMAP5_I2C1_GMUX_Pos)    /*!< 0x000000F0 */
#define IOMUX_REMAP5_I2C1_GMUX              IOMUX_REMAP5_I2C1_GMUX_Msk              /*!< I2C1_GMUX[3:0] bits (I2C1 IO general multiplexing) */
#define IOMUX_REMAP5_I2C1_GMUX_0            (0x1U << IOMUX_REMAP5_I2C1_GMUX_Pos)    /*!< 0x00000010 */
#define IOMUX_REMAP5_I2C1_GMUX_1            (0x2U << IOMUX_REMAP5_I2C1_GMUX_Pos)    /*!< 0x00000020 */
#define IOMUX_REMAP5_I2C1_GMUX_2            (0x4U << IOMUX_REMAP5_I2C1_GMUX_Pos)    /*!< 0x00000040 */
#define IOMUX_REMAP5_I2C1_GMUX_3            (0x8U << IOMUX_REMAP5_I2C1_GMUX_Pos)    /*!< 0x00000080 */

#define IOMUX_REMAP5_I2C1_GMUX_MUX0         0x00000000U                             /*!< SCL/PB6, SDA/PB7, SMBA/PB5 */
#define IOMUX_REMAP5_I2C1_GMUX_MUX1_Pos     (4U)                                    /*!< 0x00000010 */
#define IOMUX_REMAP5_I2C1_GMUX_MUX1_Msk     (0x1U << IOMUX_REMAP5_I2C1_GMUX_MUX1_Pos)
#define IOMUX_REMAP5_I2C1_GMUX_MUX1         IOMUX_REMAP5_I2C1_GMUX_MUX1_Msk         /*!< SCL/PB8, SDA/PB9, SMBA/PB5 */
#define IOMUX_REMAP5_I2C1_GMUX_MUX2_Pos     (5U)                                    /*!< 0x00000020 */
#define IOMUX_REMAP5_I2C1_GMUX_MUX2_Msk     (0x1U << IOMUX_REMAP5_I2C1_GMUX_MUX2_Pos)
#define IOMUX_REMAP5_I2C1_GMUX_MUX2         IOMUX_REMAP5_I2C1_GMUX_MUX2_Msk         /*!< SCL/PF6, SDA/PF7, SMBA/PB5 */

/*!< I2C2_GMUX configuration */
#define IOMUX_REMAP5_I2C2_GMUX_Pos          (8U)
#define IOMUX_REMAP5_I2C2_GMUX_Msk          (0xFU << IOMUX_REMAP5_I2C2_GMUX_Pos)    /*!< 0x00000F00 */
#define IOMUX_REMAP5_I2C2_GMUX              IOMUX_REMAP5_I2C2_GMUX_Msk              /*!< I2C2_GMUX[3:0] bits (I2C2 IO general multiplexing) */
#define IOMUX_REMAP5_I2C2_GMUX_0            (0x1U << IOMUX_REMAP5_I2C2_GMUX_Pos)    /*!< 0x00000100 */
#define IOMUX_REMAP5_I2C2_GMUX_1            (0x2U << IOMUX_REMAP5_I2C2_GMUX_Pos)    /*!< 0x00000200 */
#define IOMUX_REMAP5_I2C2_GMUX_2            (0x4U << IOMUX_REMAP5_I2C2_GMUX_Pos)    /*!< 0x00000400 */
#define IOMUX_REMAP5_I2C2_GMUX_3            (0x8U << IOMUX_REMAP5_I2C2_GMUX_Pos)    /*!< 0x00000800 */

#define IOMUX_REMAP5_I2C2_GMUX_MUX0         0x00000000U                             /*!< SCL/PB10, SDA/PB11, SMBA/PB12 */
#define IOMUX_REMAP5_I2C2_GMUX_MUX1_Pos     (8U)                                    /*!< 0x00000100 */
#define IOMUX_REMAP5_I2C2_GMUX_MUX1_Msk     (0x1U << IOMUX_REMAP5_I2C2_GMUX_MUX1_Pos)
#define IOMUX_REMAP5_I2C2_GMUX_MUX1         IOMUX_REMAP5_I2C2_GMUX_MUX1_Msk         /*!< SCL/PA8, SDA/PC9, SMBA/PA9 */
#define IOMUX_REMAP5_I2C2_GMUX_MUX2_Pos     (9U)                                    /*!< 0x00000200 */
#define IOMUX_REMAP5_I2C2_GMUX_MUX2_Msk     (0x1U << IOMUX_REMAP5_I2C2_GMUX_MUX2_Pos)
#define IOMUX_REMAP5_I2C2_GMUX_MUX2         IOMUX_REMAP5_I2C2_GMUX_MUX2_Msk         /*!< SCL/PA8, SDA/PB4, SMBA/PA9 */
#define IOMUX_REMAP5_I2C2_GMUX_MUX3_Pos     (8U)                                    /*!< 0x00000300 */
#define IOMUX_REMAP5_I2C2_GMUX_MUX3_Msk     (0x3U << IOMUX_REMAP5_I2C2_GMUX_MUX3_Pos)
#define IOMUX_REMAP5_I2C2_GMUX_MUX3         IOMUX_REMAP5_I2C2_GMUX_MUX3_Msk         /*!< SCL/PF6, SDA/PF7, SMBA/PA9 */

/*!< SPI1_GMUX configuration */
#define IOMUX_REMAP5_SPI1_GMUX_Pos          (16U)
#define IOMUX_REMAP5_SPI1_GMUX_Msk          (0xFU << IOMUX_REMAP5_SPI1_GMUX_Pos)    /*!< 0x000F0000 */
#define IOMUX_REMAP5_SPI1_GMUX              IOMUX_REMAP5_SPI1_GMUX_Msk              /*!< SPI1_GMUX[3:0] bits (SPI1 IO general multiplexing) */
#define IOMUX_REMAP5_SPI1_GMUX_0            (0x1U << IOMUX_REMAP5_SPI1_GMUX_Pos)    /*!< 0x00010000 */
#define IOMUX_REMAP5_SPI1_GMUX_1            (0x2U << IOMUX_REMAP5_SPI1_GMUX_Pos)    /*!< 0x00020000 */
#define IOMUX_REMAP5_SPI1_GMUX_2            (0x4U << IOMUX_REMAP5_SPI1_GMUX_Pos)    /*!< 0x00040000 */
#define IOMUX_REMAP5_SPI1_GMUX_3            (0x8U << IOMUX_REMAP5_SPI1_GMUX_Pos)    /*!< 0x00080000 */

#define IOMUX_REMAP5_SPI1_GMUX_MUX0         0x00000000U                             /*!< CS/PA4, SCK/PA5, MISO/PA6, MOSI/PA7, MCK/PB0 */
#define IOMUX_REMAP5_SPI1_GMUX_MUX1_Pos     (16U)                                   /*!< 0x00010000 */
#define IOMUX_REMAP5_SPI1_GMUX_MUX1_Msk     (0x1U << IOMUX_REMAP5_SPI1_GMUX_MUX1_Pos)
#define IOMUX_REMAP5_SPI1_GMUX_MUX1         IOMUX_REMAP5_SPI1_GMUX_MUX1_Msk         /*!< CS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5, MCK/PB6 */

/*!< SPI2_GMUX configuration */
#define IOMUX_REMAP5_SPI2_GMUX_Pos          (20U)
#define IOMUX_REMAP5_SPI2_GMUX_Msk          (0xFU << IOMUX_REMAP5_SPI2_GMUX_Pos)    /*!< 0x00F00000 */
#define IOMUX_REMAP5_SPI2_GMUX              IOMUX_REMAP5_SPI2_GMUX_Msk              /*!< SPI2_GMUX[3:0] bits (SPI2 IO general multiplexing) */
#define IOMUX_REMAP5_SPI2_GMUX_0            (0x1U << IOMUX_REMAP5_SPI2_GMUX_Pos)    /*!< 0x00100000 */
#define IOMUX_REMAP5_SPI2_GMUX_1            (0x2U << IOMUX_REMAP5_SPI2_GMUX_Pos)    /*!< 0x00200000 */
#define IOMUX_REMAP5_SPI2_GMUX_2            (0x4U << IOMUX_REMAP5_SPI2_GMUX_Pos)    /*!< 0x00400000 */
#define IOMUX_REMAP5_SPI2_GMUX_3            (0x8U << IOMUX_REMAP5_SPI2_GMUX_Pos)    /*!< 0x00800000 */

#define IOMUX_REMAP5_SPI2_GMUX_MUX0         0x00000000U                             /*!< CS/PB12, SCK/PB13, MISO/PB14, MOSI/PB15, MCK/PC6 */
#define IOMUX_REMAP5_SPI2_GMUX_MUX1_Pos     (20U)                                   /*!< 0x00100000 */
#define IOMUX_REMAP5_SPI2_GMUX_MUX1_Msk     (0x1U << IOMUX_REMAP5_SPI2_GMUX_MUX1_Pos)
#define IOMUX_REMAP5_SPI2_GMUX_MUX1         IOMUX_REMAP5_SPI2_GMUX_MUX1_Msk         /*!< CS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5, MCK/PC7 */

/*****************  Bit definition for IOMUX_REMAP6 register  *****************/
/*!< CAN1_GMUX configuration */
#define IOMUX_REMAP6_CAN1_GMUX_Pos          (0U)
#define IOMUX_REMAP6_CAN1_GMUX_Msk          (0xFU << IOMUX_REMAP6_CAN1_GMUX_Pos)    /*!< 0x0000000F */
#define IOMUX_REMAP6_CAN1_GMUX              IOMUX_REMAP6_CAN1_GMUX_Msk              /*!< CAN1_GMUX[3:0] bits (CAN1 IO general multiplexing) */
#define IOMUX_REMAP6_CAN1_GMUX_0            (0x1U << IOMUX_REMAP6_CAN1_GMUX_Pos)    /*!< 0x00000001 */
#define IOMUX_REMAP6_CAN1_GMUX_1            (0x2U << IOMUX_REMAP6_CAN1_GMUX_Pos)    /*!< 0x00000002 */
#define IOMUX_REMAP6_CAN1_GMUX_2            (0x4U << IOMUX_REMAP6_CAN1_GMUX_Pos)    /*!< 0x00000004 */
#define IOMUX_REMAP6_CAN1_GMUX_3            (0x8U << IOMUX_REMAP6_CAN1_GMUX_Pos)    /*!< 0x00000008 */

#define IOMUX_REMAP6_CAN1_GMUX_MUX0         0x00000000U                             /*!< RX/PA11, TX/PA12 */
#define IOMUX_REMAP6_CAN1_GMUX_MUX2_Pos     (1U)                                    /*!< 0x00000002 */
#define IOMUX_REMAP6_CAN1_GMUX_MUX2_Msk     (0x1U << IOMUX_REMAP6_CAN1_GMUX_MUX2_Pos)
#define IOMUX_REMAP6_CAN1_GMUX_MUX2         IOMUX_REMAP6_CAN1_GMUX_MUX2_Msk         /*!< RX/PB8, TX/PB9 */

/*!< SDIO_GMUX configuration */
#define IOMUX_REMAP6_SDIO_GMUX_Pos          (8U)
#define IOMUX_REMAP6_SDIO_GMUX_Msk          (0xFU << IOMUX_REMAP6_SDIO_GMUX_Pos)    /*!< 0x00000F00 */
#define IOMUX_REMAP6_SDIO_GMUX              IOMUX_REMAP6_SDIO_GMUX_Msk              /*!< SDIO_GMUX[3:0] bits (SDIO IO general multiplexing) */
#define IOMUX_REMAP6_SDIO_GMUX_0            (0x1U << IOMUX_REMAP6_SDIO_GMUX_Pos)    /*!< 0x00000100 */
#define IOMUX_REMAP6_SDIO_GMUX_1            (0x2U << IOMUX_REMAP6_SDIO_GMUX_Pos)    /*!< 0x00000200 */
#define IOMUX_REMAP6_SDIO_GMUX_2            (0x4U << IOMUX_REMAP6_SDIO_GMUX_Pos)    /*!< 0x00000400 */
#define IOMUX_REMAP6_SDIO_GMUX_3            (0x8U << IOMUX_REMAP6_SDIO_GMUX_Pos)    /*!< 0x00000800 */

#define IOMUX_REMAP6_SDIO_GMUX_MUX0         0x00000000U                             /*!< D0/PC8, D1/PC9, D2/PC10, D3/PC11, D4/PB8, D5/PB9, D6/PC6, D7/PC7, CK/PC12, CMD/PD2 */
#define IOMUX_REMAP6_SDIO_GMUX_MUX4_Pos     (10U)                                   /*!< 0x00000400 */
#define IOMUX_REMAP6_SDIO_GMUX_MUX4_Msk     (0x1U << IOMUX_REMAP6_SDIO_GMUX_MUX4_Pos)
#define IOMUX_REMAP6_SDIO_GMUX_MUX4         IOMUX_REMAP6_SDIO_GMUX_MUX4_Msk         /*!< D0/PC0, D1/PC1, D2/PC2, D3/PC3, D4/PA4, D5/PA5, D6/PA6, D7/PA7, CK/PC4, CMD/PC5 */
#define IOMUX_REMAP6_SDIO_GMUX_MUX5_Pos     (8U)                                    /*!< 0x00000500 */
#define IOMUX_REMAP6_SDIO_GMUX_MUX5_Msk     (0x5U << IOMUX_REMAP6_SDIO_GMUX_MUX5_Pos)
#define IOMUX_REMAP6_SDIO_GMUX_MUX5         IOMUX_REMAP6_SDIO_GMUX_MUX5_Msk         /*!< D0/PA4, D1/PA5, D2/PA6, D3/PA7, CK/PC4, CMD/PC5 */
#define IOMUX_REMAP6_SDIO_GMUX_MUX6_Pos     (9U)                                    /*!< 0x00000600 */
#define IOMUX_REMAP6_SDIO_GMUX_MUX6_Msk     (0x3U << IOMUX_REMAP6_SDIO_GMUX_MUX6_Pos)
#define IOMUX_REMAP6_SDIO_GMUX_MUX6         IOMUX_REMAP6_SDIO_GMUX_MUX6_Msk         /*!< D0/PC0, D1/PC1, D2/PC2, D3/PC3, D4/PA4, D5/PA5, D6/PA6, D7/PA7, CK/PA2, CMD/PA3 */
#define IOMUX_REMAP6_SDIO_GMUX_MUX7_Pos     (8U)                                    /*!< 0x00000700 */
#define IOMUX_REMAP6_SDIO_GMUX_MUX7_Msk     (0x7U << IOMUX_REMAP6_SDIO_GMUX_MUX7_Pos)
#define IOMUX_REMAP6_SDIO_GMUX_MUX7         IOMUX_REMAP6_SDIO_GMUX_MUX7_Msk         /*!< D0/PA4, D1/PA5, D2/PA6, D3/PA7, CK/PA2, CMD/PA3 */

/*!< USART1_GMUX configuration */
#define IOMUX_REMAP6_USART1_GMUX_Pos        (16U)
#define IOMUX_REMAP6_USART1_GMUX_Msk        (0xFU << IOMUX_REMAP6_USART1_GMUX_Pos)  /*!< 0x000F0000 */
#define IOMUX_REMAP6_USART1_GMUX            IOMUX_REMAP6_USART1_GMUX_Msk            /*!< USART1_GMUX[3:0] bits (USART1 IO general multiplexing) */
#define IOMUX_REMAP6_USART1_GMUX_0          (0x1U << IOMUX_REMAP6_USART1_GMUX_Pos)  /*!< 0x00010000 */
#define IOMUX_REMAP6_USART1_GMUX_1          (0x2U << IOMUX_REMAP6_USART1_GMUX_Pos)  /*!< 0x00020000 */
#define IOMUX_REMAP6_USART1_GMUX_2          (0x4U << IOMUX_REMAP6_USART1_GMUX_Pos)  /*!< 0x00040000 */
#define IOMUX_REMAP6_USART1_GMUX_3          (0x8U << IOMUX_REMAP6_USART1_GMUX_Pos)  /*!< 0x00080000 */

#define IOMUX_REMAP6_USART1_GMUX_MUX0       0x00000000U                             /*!< TX/PA9, RX/PA10 */
#define IOMUX_REMAP6_USART1_GMUX_MUX1_Pos   (16U)                                   /*!< 0x00010000 */
#define IOMUX_REMAP6_USART1_GMUX_MUX1_Msk   (0x1U << IOMUX_REMAP6_USART1_GMUX_MUX1_Pos)
#define IOMUX_REMAP6_USART1_GMUX_MUX1       IOMUX_REMAP6_USART1_GMUX_MUX1_Msk       /*!< TX/PB6, RX/PB7 */

/*!< USART3_GMUX configuration */
#define IOMUX_REMAP6_USART3_GMUX_Pos        (24U)
#define IOMUX_REMAP6_USART3_GMUX_Msk        (0xFU << IOMUX_REMAP6_USART3_GMUX_Pos)  /*!< 0x0F000000 */
#define IOMUX_REMAP6_USART3_GMUX            IOMUX_REMAP6_USART3_GMUX_Msk            /*!< USART3_GMUX[3:0] bits (USART3 IO general multiplexing) */
#define IOMUX_REMAP6_USART3_GMUX_0          (0x1U << IOMUX_REMAP6_USART3_GMUX_Pos)  /*!< 0x01000000 */
#define IOMUX_REMAP6_USART3_GMUX_1          (0x2U << IOMUX_REMAP6_USART3_GMUX_Pos)  /*!< 0x02000000 */
#define IOMUX_REMAP6_USART3_GMUX_2          (0x4U << IOMUX_REMAP6_USART3_GMUX_Pos)  /*!< 0x04000000 */
#define IOMUX_REMAP6_USART3_GMUX_3          (0x8U << IOMUX_REMAP6_USART3_GMUX_Pos)  /*!< 0x08000000 */

#define IOMUX_REMAP6_USART3_GMUX_MUX0       0x00000000U                             /*!< TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14 */
#define IOMUX_REMAP6_USART3_GMUX_MUX1_Pos   (24U)                                   /*!< 0x01000000 */
#define IOMUX_REMAP6_USART3_GMUX_MUX1_Msk   (0x1U << IOMUX_REMAP6_USART3_GMUX_MUX1_Pos)
#define IOMUX_REMAP6_USART3_GMUX_MUX1       IOMUX_REMAP6_USART3_GMUX_MUX1_Msk       /*!< TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14 */
#define IOMUX_REMAP6_USART3_GMUX_MUX2_Pos   (25U)                                   /*!< 0x02000000 */
#define IOMUX_REMAP6_USART3_GMUX_MUX2_Msk   (0x1U << IOMUX_REMAP6_USART3_GMUX_MUX2_Pos)
#define IOMUX_REMAP6_USART3_GMUX_MUX2       IOMUX_REMAP6_USART3_GMUX_MUX2_Msk       /*!< TX/PA7, RX/PA6, CK/PA5, CTS/PB1, RTS/PB0 */

/*****************  Bit definition for IOMUX_REMAP7 register  *****************/
#define IOMUX_REMAP7_ADC1_ETP_GMUX_Pos      (4U)                                    /*!< 0x00000010 */
#define IOMUX_REMAP7_ADC1_ETP_GMUX_Msk      (0x1U << IOMUX_REMAP7_ADC1_ETP_GMUX_Pos)
#define IOMUX_REMAP7_ADC1_ETP_GMUX          IOMUX_REMAP7_ADC1_ETP_GMUX_Msk          /*!< ADC1 External trigger preempted conversion general multiplexing */
#define IOMUX_REMAP7_ADC1_ETO_GMUX_Pos      (5U)                                    /*!< 0x00000020 */
#define IOMUX_REMAP7_ADC1_ETO_GMUX_Msk      (0x1U << IOMUX_REMAP7_ADC1_ETO_GMUX_Pos)
#define IOMUX_REMAP7_ADC1_ETO_GMUX          IOMUX_REMAP7_ADC1_ETO_GMUX_Msk          /*!< ADC1 external trigger regular conversion general multiplexing */

/*!< SWJTAG_GMUX configuration */
#define IOMUX_REMAP7_SWJTAG_GMUX_Pos        (16U)
#define IOMUX_REMAP7_SWJTAG_GMUX_Msk        (0x7U << IOMUX_REMAP7_SWJTAG_GMUX_Pos)  /*!< 0x00070000 */
#define IOMUX_REMAP7_SWJTAG_GMUX            IOMUX_REMAP7_SWJTAG_GMUX_Msk            /*!< SWJTAG_GMUX[2:0] bits (SWD JTAG IO general mutiplexing) */
#define IOMUX_REMAP7_SWJTAG_GMUX_0          (0x1U << IOMUX_REMAP7_SWJTAG_GMUX_Pos)  /*!< 0x00010000 */
#define IOMUX_REMAP7_SWJTAG_GMUX_1          (0x2U << IOMUX_REMAP7_SWJTAG_GMUX_Pos)  /*!< 0x00020000 */
#define IOMUX_REMAP7_SWJTAG_GMUX_2          (0x4U << IOMUX_REMAP7_SWJTAG_GMUX_Pos)  /*!< 0x00040000 */

#define IOMUX_REMAP7_SWJTAG_GMUX_RESET        0x00000000U                           /*!< Supports SWD and JTAG. All SWJTAG pins cannot be used as GPIO */
#define IOMUX_REMAP7_SWJTAG_GMUX_NONJTRST_Pos (16U)                                 /*!< 0x00010000 */
#define IOMUX_REMAP7_SWJTAG_GMUX_NONJTRST_Msk (0x1U << IOMUX_REMAP7_SWJTAG_GMUX_NONJTRST_Pos)
#define IOMUX_REMAP7_SWJTAG_GMUX_NONJTRST     IOMUX_REMAP7_SWJTAG_GMUX_NONJTRST_Msk /*!< Supports SWD and JTAG. NJTRST is disabled. PB4 can be used as GPIO */
#define IOMUX_REMAP7_SWJTAG_GMUX_JTAGDIS_Pos  (17U)                                 /*!< 0x00020000 */
#define IOMUX_REMAP7_SWJTAG_GMUX_JTAGDIS_Msk  (0x1U << IOMUX_REMAP7_SWJTAG_GMUX_JTAGDIS_Pos)
#define IOMUX_REMAP7_SWJTAG_GMUX_JTAGDIS      IOMUX_REMAP7_SWJTAG_GMUX_JTAGDIS_Msk  /*!< Supports SWD. But JTAG is disabled. PA15/PB3/PB4 can be used as GPIO */
#define IOMUX_REMAP7_SWJTAG_GMUX_DISABLE_Pos  (18U)                                 /*!< 0x00040000 */
#define IOMUX_REMAP7_SWJTAG_GMUX_DISABLE_Msk  (0x1U << IOMUX_REMAP7_SWJTAG_GMUX_DISABLE_Pos)
#define IOMUX_REMAP7_SWJTAG_GMUX_DISABLE      IOMUX_REMAP7_SWJTAG_GMUX_DISABLE_Msk  /*!< SWD and JTAG are disabled. All SWJTAG pins can be used as GPIO */

#define IOMUX_REMAP7_PD01_GMUX_Pos          (20U)
#define IOMUX_REMAP7_PD01_GMUX_Msk          (0x1U << IOMUX_REMAP7_PD01_GMUX_Pos)    /*!< 0x00100000 */
#define IOMUX_REMAP7_PD01_GMUX              IOMUX_REMAP7_PD01_GMUX_Msk              /*!< PD0/PD1 mapped onto HEXT_IN / HEXT_OUT */

/*****************  Bit definition for IOMUX_REMAP8 register  *****************/
/*!< TMR1_BK1_CMP_GMUX configuration */
#define IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_Pos  (0U)                                    /*!< 0x00000003 */
#define IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_Msk  (0x3U << IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_Pos)
#define IOMUX_REMAP8_TMR1_BK1_CMP_GMUX      IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_Msk      /*!< TMR1_BK1_CMP_GMUX[1:0] bits (TMR1 break channel 1 internal mapping) */
#define IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_0    (0x1U << IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_Pos)  /*!< 0x00000001 */
#define IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_1    (0x2U << IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_Pos)  /*!< 0x00000002 */

#define IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX0     0x00000000U                             /*!< TMR1_GMUX IO signal is connected to TMR1 BRK channel 1 */
#define IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX1_Pos (0U)                                    /*!< 0x00000001 */
#define IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX1_Msk (0x1U << IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX1_Pos)
#define IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX1     IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX1_Msk /*!< TMR1_GMUX IO signal is connected to TMR1 BRK channel 1 */
#define IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX2_Pos (1U)                                    /*!< 0x00000002 */
#define IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX2_Msk (0x1U << IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX2_Pos)
#define IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX2     IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX2_Msk /*!< CMP output signal is connected to TMR1 BRK channel 1 */
#define IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX3_Pos (0U)                                    /*!< 0x00000003 */
#define IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX3_Msk (0x3U << IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX3_Pos)
#define IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX3     IOMUX_REMAP8_TMR1_BK1_CMP_GMUX_MUX3_Msk /*!< Either CMP output signal or TMR1_GMUX IO signal is connected to TMR1 BRK channel 1 */

/*!< TMR1_CH1_CMP_GMUX configuration */
#define IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_Pos  (2U)                                    /*!< 0x0000000C */
#define IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_Msk  (0x3U << IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_Pos)
#define IOMUX_REMAP8_TMR1_CH1_CMP_GMUX      IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_Msk      /*!< TMR1_CH1_CMP_GMUX[1:0] bits (TMR1 channel 1 internal mapping) */
#define IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_0    (0x1U << IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_Pos)  /*!< 0x00000004 */
#define IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_1    (0x2U << IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_Pos)  /*!< 0x00000008 */

#define IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX0     0x00000000U                             /*!< TMR1_GMUX IO signal is connected to TMR1 channel 1 */
#define IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX1_Pos (2U)                                    /*!< 0x00000004 */
#define IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX1_Msk (0x1U << IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX1_Pos)
#define IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX1     IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX1_Msk /*!< TMR1_GMUX IO signal is connected to TMR1 channel 1 */
#define IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX2_Pos (3U)                                    /*!< 0x00000008 */
#define IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX2_Msk (0x1U << IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX2_Pos)
#define IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX2     IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX2_Msk /*!< CMP output signal is connected to TMR1 channel 1 */
#define IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX3_Pos (2U)                                    /*!< 0x0000000C */
#define IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX3_Msk (0x3U << IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX3_Pos)
#define IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX3     IOMUX_REMAP8_TMR1_CH1_CMP_GMUX_MUX3_Msk /*!< Either CMP output signal or TMR1_GMUX IO signal is connected to TMR1 channel 1 */

/*!< TMR2_CH4_CMP_GMUX configuration */
#define IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_Pos  (4U)                                    /*!< 0x00000030 */
#define IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_Msk  (0x3U << IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_Pos)
#define IOMUX_REMAP8_TMR2_CH4_CMP_GMUX      IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_Msk      /*!< TMR2_CH4_CMP_GMUX[1:0] bits (TMR2 channel 4 internal mapping) */
#define IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_0    (0x1U << IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_Pos)  /*!< 0x00000010 */
#define IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_1    (0x2U << IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_Pos)  /*!< 0x00000020 */

#define IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX0     0x00000000U                             /*!< TMR2_GMUX IO signal is connected to TMR2 channel 4 */
#define IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX1_Pos (4U)                                    /*!< 0x00000010 */
#define IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX1_Msk (0x1U << IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX1_Pos)
#define IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX1     IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX1_Msk /*!< TMR2_GMUX IO signal is connected to TMR2 channel 4 */
#define IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX2_Pos (5U)                                    /*!< 0x00000020 */
#define IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX2_Msk (0x1U << IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX2_Pos)
#define IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX2     IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX2_Msk /*!< CMP output signal is connected to TMR2 channel 4 */
#define IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX3_Pos (4U)                                    /*!< 0x00000030 */
#define IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX3_Msk (0x3U << IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX3_Pos)
#define IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX3     IOMUX_REMAP8_TMR2_CH4_CMP_GMUX_MUX3_Msk /*!< Either CMP output signal or TMR2_GMUX IO signal is connected to TMR2 channel 4 */

/*!< TMR3_CH1_CMP_GMUX configuration */
#define IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_Pos  (6U)                                    /*!< 0x000000C0 */
#define IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_Msk  (0x3U << IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_Pos)
#define IOMUX_REMAP8_TMR3_CH1_CMP_GMUX      IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_Msk      /*!< TMR3_CH1_CMP_GMUX[1:0] bits (TMR3 channel 1 internal mapping) */
#define IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_0    (0x1U << IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_Pos)  /*!< 0x00000040 */
#define IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_1    (0x2U << IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_Pos)  /*!< 0x00000080 */

#define IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX0     0x00000000U                             /*!< TMR3_GMUX IO signal is connected to TMR3 channel 1 */
#define IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX1_Pos (6U)                                    /*!< 0x00000040 */
#define IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX1_Msk (0x1U << IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX1_Pos)
#define IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX1     IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX1_Msk /*!< TMR3_GMUX IO signal is connected to TMR3 channel 1 */
#define IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX2_Pos (7U)                                    /*!< 0x00000080 */
#define IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX2_Msk (0x1U << IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX2_Pos)
#define IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX2     IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX2_Msk /*!< CMP output signal is connected to TMR3 channel 1 */
#define IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX3_Pos (6U)                                    /*!< 0x000000C0 */
#define IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX3_Msk (0x3U << IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX3_Pos)
#define IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX3     IOMUX_REMAP8_TMR3_CH1_CMP_GMUX_MUX3_Msk /*!< Either CMP output signal or TMR3_GMUX IO signal is connected to TMR3 channel 1 */

/******************************************************************************/
/*                                                                            */
/*                External interrupt/Event controller (EXINT)                 */
/*                                                                            */
/******************************************************************************/

/*****************  Bit definition for EXINT_INTEN register  ******************/
#define EXINT_INTEN_INTEN0_Pos              (0U)
#define EXINT_INTEN_INTEN0_Msk              (0x1U << EXINT_INTEN_INTEN0_Pos)        /*!< 0x00000001 */
#define EXINT_INTEN_INTEN0                  EXINT_INTEN_INTEN0_Msk                  /*!< Interrupt enable or disable on line 0 */
#define EXINT_INTEN_INTEN1_Pos              (1U)
#define EXINT_INTEN_INTEN1_Msk              (0x1U << EXINT_INTEN_INTEN1_Pos)        /*!< 0x00000002 */
#define EXINT_INTEN_INTEN1                  EXINT_INTEN_INTEN1_Msk                  /*!< Interrupt enable or disable on line 1 */
#define EXINT_INTEN_INTEN2_Pos              (2U)
#define EXINT_INTEN_INTEN2_Msk              (0x1U << EXINT_INTEN_INTEN2_Pos)        /*!< 0x00000004 */
#define EXINT_INTEN_INTEN2                  EXINT_INTEN_INTEN2_Msk                  /*!< Interrupt enable or disable on line 2 */
#define EXINT_INTEN_INTEN3_Pos              (3U)
#define EXINT_INTEN_INTEN3_Msk              (0x1U << EXINT_INTEN_INTEN3_Pos)        /*!< 0x00000008 */
#define EXINT_INTEN_INTEN3                  EXINT_INTEN_INTEN3_Msk                  /*!< Interrupt enable or disable on line 3 */
#define EXINT_INTEN_INTEN4_Pos              (4U)
#define EXINT_INTEN_INTEN4_Msk              (0x1U << EXINT_INTEN_INTEN4_Pos)        /*!< 0x00000010 */
#define EXINT_INTEN_INTEN4                  EXINT_INTEN_INTEN4_Msk                  /*!< Interrupt enable or disable on line 4 */
#define EXINT_INTEN_INTEN5_Pos              (5U)
#define EXINT_INTEN_INTEN5_Msk              (0x1U << EXINT_INTEN_INTEN5_Pos)        /*!< 0x00000020 */
#define EXINT_INTEN_INTEN5                  EXINT_INTEN_INTEN5_Msk                  /*!< Interrupt enable or disable on line 5 */
#define EXINT_INTEN_INTEN6_Pos              (6U)
#define EXINT_INTEN_INTEN6_Msk              (0x1U << EXINT_INTEN_INTEN6_Pos)        /*!< 0x00000040 */
#define EXINT_INTEN_INTEN6                  EXINT_INTEN_INTEN6_Msk                  /*!< Interrupt enable or disable on line 6 */
#define EXINT_INTEN_INTEN7_Pos              (7U)
#define EXINT_INTEN_INTEN7_Msk              (0x1U << EXINT_INTEN_INTEN7_Pos)        /*!< 0x00000080 */
#define EXINT_INTEN_INTEN7                  EXINT_INTEN_INTEN7_Msk                  /*!< Interrupt enable or disable on line 7 */
#define EXINT_INTEN_INTEN8_Pos              (8U)
#define EXINT_INTEN_INTEN8_Msk              (0x1U << EXINT_INTEN_INTEN8_Pos)        /*!< 0x00000100 */
#define EXINT_INTEN_INTEN8                  EXINT_INTEN_INTEN8_Msk                  /*!< Interrupt enable or disable on line 8 */
#define EXINT_INTEN_INTEN9_Pos              (9U)
#define EXINT_INTEN_INTEN9_Msk              (0x1U << EXINT_INTEN_INTEN9_Pos)        /*!< 0x00000200 */
#define EXINT_INTEN_INTEN9                  EXINT_INTEN_INTEN9_Msk                  /*!< Interrupt enable or disable on line 9 */
#define EXINT_INTEN_INTEN10_Pos             (10U)
#define EXINT_INTEN_INTEN10_Msk             (0x1U << EXINT_INTEN_INTEN10_Pos)       /*!< 0x00000400 */
#define EXINT_INTEN_INTEN10                 EXINT_INTEN_INTEN10_Msk                 /*!< Interrupt enable or disable on line 10 */
#define EXINT_INTEN_INTEN11_Pos             (11U)
#define EXINT_INTEN_INTEN11_Msk             (0x1U << EXINT_INTEN_INTEN11_Pos)       /*!< 0x00000800 */
#define EXINT_INTEN_INTEN11                 EXINT_INTEN_INTEN11_Msk                 /*!< Interrupt enable or disable on line 11 */
#define EXINT_INTEN_INTEN12_Pos             (12U)
#define EXINT_INTEN_INTEN12_Msk             (0x1U << EXINT_INTEN_INTEN12_Pos)       /*!< 0x00001000 */
#define EXINT_INTEN_INTEN12                 EXINT_INTEN_INTEN12_Msk                 /*!< Interrupt enable or disable on line 12 */
#define EXINT_INTEN_INTEN13_Pos             (13U)
#define EXINT_INTEN_INTEN13_Msk             (0x1U << EXINT_INTEN_INTEN13_Pos)       /*!< 0x00002000 */
#define EXINT_INTEN_INTEN13                 EXINT_INTEN_INTEN13_Msk                 /*!< Interrupt enable or disable on line 13 */
#define EXINT_INTEN_INTEN14_Pos             (14U)
#define EXINT_INTEN_INTEN14_Msk             (0x1U << EXINT_INTEN_INTEN14_Pos)       /*!< 0x00004000 */
#define EXINT_INTEN_INTEN14                 EXINT_INTEN_INTEN14_Msk                 /*!< Interrupt enable or disable on line 14 */
#define EXINT_INTEN_INTEN15_Pos             (15U)
#define EXINT_INTEN_INTEN15_Msk             (0x1U << EXINT_INTEN_INTEN15_Pos)       /*!< 0x00008000 */
#define EXINT_INTEN_INTEN15                 EXINT_INTEN_INTEN15_Msk                 /*!< Interrupt enable or disable on line 15 */
#define EXINT_INTEN_INTEN16_Pos             (16U)
#define EXINT_INTEN_INTEN16_Msk             (0x1U << EXINT_INTEN_INTEN16_Pos)       /*!< 0x00010000 */
#define EXINT_INTEN_INTEN16                 EXINT_INTEN_INTEN16_Msk                 /*!< Interrupt enable or disable on line 16 */
#define EXINT_INTEN_INTEN17_Pos             (17U)
#define EXINT_INTEN_INTEN17_Msk             (0x1U << EXINT_INTEN_INTEN17_Pos)       /*!< 0x00020000 */
#define EXINT_INTEN_INTEN17                 EXINT_INTEN_INTEN17_Msk                 /*!< Interrupt enable or disable on line 17 */
#define EXINT_INTEN_INTEN18_Pos             (18U)
#define EXINT_INTEN_INTEN18_Msk             (0x1U << EXINT_INTEN_INTEN18_Pos)       /*!< 0x00040000 */
#define EXINT_INTEN_INTEN18                 EXINT_INTEN_INTEN18_Msk                 /*!< Interrupt enable or disable on line 18 */
#define EXINT_INTEN_INTEN19_Pos             (19U)
#define EXINT_INTEN_INTEN19_Msk             (0x1U << EXINT_INTEN_INTEN19_Pos)       /*!< 0x00080000 */
#define EXINT_INTEN_INTEN19                 EXINT_INTEN_INTEN19_Msk                 /*!< Interrupt enable or disable on line 19 */
#define EXINT_INTEN_INTEN20_Pos             (20U)
#define EXINT_INTEN_INTEN20_Msk             (0x1U << EXINT_INTEN_INTEN20_Pos)       /*!< 0x00100000 */
#define EXINT_INTEN_INTEN20                 EXINT_INTEN_INTEN20_Msk                 /*!< Interrupt enable or disable on line 20 */
#define EXINT_INTEN_INTEN21_Pos             (21U)
#define EXINT_INTEN_INTEN21_Msk             (0x1U << EXINT_INTEN_INTEN21_Pos)       /*!< 0x00200000 */
#define EXINT_INTEN_INTEN21                 EXINT_INTEN_INTEN21_Msk                 /*!< Interrupt enable or disable on line 21 */
#define EXINT_INTEN_INTEN22_Pos             (22U)
#define EXINT_INTEN_INTEN22_Msk             (0x1U << EXINT_INTEN_INTEN22_Pos)       /*!< 0x00400000 */
#define EXINT_INTEN_INTEN22                 EXINT_INTEN_INTEN22_Msk                 /*!< Interrupt enable or disable on line 22 */

/* References Defines */
#define EXINT_INTEN_INT0                    EXINT_INTEN_INTEN0
#define EXINT_INTEN_INT1                    EXINT_INTEN_INTEN1
#define EXINT_INTEN_INT2                    EXINT_INTEN_INTEN2
#define EXINT_INTEN_INT3                    EXINT_INTEN_INTEN3
#define EXINT_INTEN_INT4                    EXINT_INTEN_INTEN4
#define EXINT_INTEN_INT5                    EXINT_INTEN_INTEN5
#define EXINT_INTEN_INT6                    EXINT_INTEN_INTEN6
#define EXINT_INTEN_INT7                    EXINT_INTEN_INTEN7
#define EXINT_INTEN_INT8                    EXINT_INTEN_INTEN8
#define EXINT_INTEN_INT9                    EXINT_INTEN_INTEN9
#define EXINT_INTEN_INT10                   EXINT_INTEN_INTEN10
#define EXINT_INTEN_INT11                   EXINT_INTEN_INTEN11
#define EXINT_INTEN_INT12                   EXINT_INTEN_INTEN12
#define EXINT_INTEN_INT13                   EXINT_INTEN_INTEN13
#define EXINT_INTEN_INT14                   EXINT_INTEN_INTEN14
#define EXINT_INTEN_INT15                   EXINT_INTEN_INTEN15
#define EXINT_INTEN_INT16                   EXINT_INTEN_INTEN16
#define EXINT_INTEN_INT17                   EXINT_INTEN_INTEN17
#define EXINT_INTEN_INT18                   EXINT_INTEN_INTEN18
#define EXINT_INTEN_INT19                   EXINT_INTEN_INTEN19
#define EXINT_INTEN_INT20                   EXINT_INTEN_INTEN20
#define EXINT_INTEN_INT21                   EXINT_INTEN_INTEN21
#define EXINT_INTEN_INT22                   EXINT_INTEN_INTEN22
#define EXINT_INTEN_INT                     0x007FFFFFU                             /*!< Interrupt enable or disable all */
 
/*****************  Bit definition for EXINT_EVTEN register  ******************/
#define EXINT_EVTEN_EVTEN0_Pos              (0U)
#define EXINT_EVTEN_EVTEN0_Msk              (0x1U << EXINT_EVTEN_EVTEN0_Pos)        /*!< 0x00000001 */
#define EXINT_EVTEN_EVTEN0                  EXINT_EVTEN_EVTEN0_Msk                  /*!< Event enable or disable on line 0 */
#define EXINT_EVTEN_EVTEN1_Pos              (1U)
#define EXINT_EVTEN_EVTEN1_Msk              (0x1U << EXINT_EVTEN_EVTEN1_Pos)        /*!< 0x00000002 */
#define EXINT_EVTEN_EVTEN1                  EXINT_EVTEN_EVTEN1_Msk                  /*!< Event enable or disable on line 1 */
#define EXINT_EVTEN_EVTEN2_Pos              (2U)
#define EXINT_EVTEN_EVTEN2_Msk              (0x1U << EXINT_EVTEN_EVTEN2_Pos)        /*!< 0x00000004 */
#define EXINT_EVTEN_EVTEN2                  EXINT_EVTEN_EVTEN2_Msk                  /*!< Event enable or disable on line 2 */
#define EXINT_EVTEN_EVTEN3_Pos              (3U)
#define EXINT_EVTEN_EVTEN3_Msk              (0x1U << EXINT_EVTEN_EVTEN3_Pos)        /*!< 0x00000008 */
#define EXINT_EVTEN_EVTEN3                  EXINT_EVTEN_EVTEN3_Msk                  /*!< Event enable or disable on line 3 */
#define EXINT_EVTEN_EVTEN4_Pos              (4U)
#define EXINT_EVTEN_EVTEN4_Msk              (0x1U << EXINT_EVTEN_EVTEN4_Pos)        /*!< 0x00000010 */
#define EXINT_EVTEN_EVTEN4                  EXINT_EVTEN_EVTEN4_Msk                  /*!< Event enable or disable on line 4 */
#define EXINT_EVTEN_EVTEN5_Pos              (5U)
#define EXINT_EVTEN_EVTEN5_Msk              (0x1U << EXINT_EVTEN_EVTEN5_Pos)        /*!< 0x00000020 */
#define EXINT_EVTEN_EVTEN5                  EXINT_EVTEN_EVTEN5_Msk                  /*!< Event enable or disable on line 5 */
#define EXINT_EVTEN_EVTEN6_Pos              (6U)
#define EXINT_EVTEN_EVTEN6_Msk              (0x1U << EXINT_EVTEN_EVTEN6_Pos)        /*!< 0x00000040 */
#define EXINT_EVTEN_EVTEN6                  EXINT_EVTEN_EVTEN6_Msk                  /*!< Event enable or disable on line 6 */
#define EXINT_EVTEN_EVTEN7_Pos              (7U)
#define EXINT_EVTEN_EVTEN7_Msk              (0x1U << EXINT_EVTEN_EVTEN7_Pos)        /*!< 0x00000080 */
#define EXINT_EVTEN_EVTEN7                  EXINT_EVTEN_EVTEN7_Msk                  /*!< Event enable or disable on line 7 */
#define EXINT_EVTEN_EVTEN8_Pos              (8U)
#define EXINT_EVTEN_EVTEN8_Msk              (0x1U << EXINT_EVTEN_EVTEN8_Pos)        /*!< 0x00000100 */
#define EXINT_EVTEN_EVTEN8                  EXINT_EVTEN_EVTEN8_Msk                  /*!< Event enable or disable on line 8 */
#define EXINT_EVTEN_EVTEN9_Pos              (9U)
#define EXINT_EVTEN_EVTEN9_Msk              (0x1U << EXINT_EVTEN_EVTEN9_Pos)        /*!< 0x00000200 */
#define EXINT_EVTEN_EVTEN9                  EXINT_EVTEN_EVTEN9_Msk                  /*!< Event enable or disable on line 9 */
#define EXINT_EVTEN_EVTEN10_Pos             (10U)
#define EXINT_EVTEN_EVTEN10_Msk             (0x1U << EXINT_EVTEN_EVTEN10_Pos)       /*!< 0x00000400 */
#define EXINT_EVTEN_EVTEN10                 EXINT_EVTEN_EVTEN10_Msk                 /*!< Event enable or disable on line 10 */
#define EXINT_EVTEN_EVTEN11_Pos             (11U)
#define EXINT_EVTEN_EVTEN11_Msk             (0x1U << EXINT_EVTEN_EVTEN11_Pos)       /*!< 0x00000800 */
#define EXINT_EVTEN_EVTEN11                 EXINT_EVTEN_EVTEN11_Msk                 /*!< Event enable or disable on line 11 */
#define EXINT_EVTEN_EVTEN12_Pos             (12U)
#define EXINT_EVTEN_EVTEN12_Msk             (0x1U << EXINT_EVTEN_EVTEN12_Pos)       /*!< 0x00001000 */
#define EXINT_EVTEN_EVTEN12                 EXINT_EVTEN_EVTEN12_Msk                 /*!< Event enable or disable on line 12 */
#define EXINT_EVTEN_EVTEN13_Pos             (13U)
#define EXINT_EVTEN_EVTEN13_Msk             (0x1U << EXINT_EVTEN_EVTEN13_Pos)       /*!< 0x00002000 */
#define EXINT_EVTEN_EVTEN13                 EXINT_EVTEN_EVTEN13_Msk                 /*!< Event enable or disable on line 13 */
#define EXINT_EVTEN_EVTEN14_Pos             (14U)
#define EXINT_EVTEN_EVTEN14_Msk             (0x1U << EXINT_EVTEN_EVTEN14_Pos)       /*!< 0x00004000 */
#define EXINT_EVTEN_EVTEN14                 EXINT_EVTEN_EVTEN14_Msk                 /*!< Event enable or disable on line 14 */
#define EXINT_EVTEN_EVTEN15_Pos             (15U)
#define EXINT_EVTEN_EVTEN15_Msk             (0x1U << EXINT_EVTEN_EVTEN15_Pos)       /*!< 0x00008000 */
#define EXINT_EVTEN_EVTEN15                 EXINT_EVTEN_EVTEN15_Msk                 /*!< Event enable or disable on line 15 */
#define EXINT_EVTEN_EVTEN16_Pos             (16U)
#define EXINT_EVTEN_EVTEN16_Msk             (0x1U << EXINT_EVTEN_EVTEN16_Pos)       /*!< 0x00010000 */
#define EXINT_EVTEN_EVTEN16                 EXINT_EVTEN_EVTEN16_Msk                 /*!< Event enable or disable on line 16 */
#define EXINT_EVTEN_EVTEN17_Pos             (17U)
#define EXINT_EVTEN_EVTEN17_Msk             (0x1U << EXINT_EVTEN_EVTEN17_Pos)       /*!< 0x00020000 */
#define EXINT_EVTEN_EVTEN17                 EXINT_EVTEN_EVTEN17_Msk                 /*!< Event enable or disable on line 17 */
#define EXINT_EVTEN_EVTEN18_Pos             (18U)
#define EXINT_EVTEN_EVTEN18_Msk             (0x1U << EXINT_EVTEN_EVTEN18_Pos)       /*!< 0x00040000 */
#define EXINT_EVTEN_EVTEN18                 EXINT_EVTEN_EVTEN18_Msk                 /*!< Event enable or disable on line 18 */
#define EXINT_EVTEN_EVTEN19_Pos             (19U)
#define EXINT_EVTEN_EVTEN19_Msk             (0x1U << EXINT_EVTEN_EVTEN19_Pos)       /*!< 0x00080000 */
#define EXINT_EVTEN_EVTEN19                 EXINT_EVTEN_EVTEN19_Msk                 /*!< Event enable or disable on line 19 */
#define EXINT_EVTEN_EVTEN20_Pos             (20U)
#define EXINT_EVTEN_EVTEN20_Msk             (0x1U << EXINT_EVTEN_EVTEN20_Pos)       /*!< 0x00100000 */
#define EXINT_EVTEN_EVTEN20                 EXINT_EVTEN_EVTEN20_Msk                 /*!< Event enable or disable on line 20 */
#define EXINT_EVTEN_EVTEN21_Pos             (21U)
#define EXINT_EVTEN_EVTEN21_Msk             (0x1U << EXINT_EVTEN_EVTEN21_Pos)       /*!< 0x00200000 */
#define EXINT_EVTEN_EVTEN21                 EXINT_EVTEN_EVTEN21_Msk                 /*!< Event enable or disable on line 21 */
#define EXINT_EVTEN_EVTEN22_Pos             (22U)
#define EXINT_EVTEN_EVTEN22_Msk             (0x1U << EXINT_EVTEN_EVTEN22_Pos)       /*!< 0x00400000 */
#define EXINT_EVTEN_EVTEN22                 EXINT_EVTEN_EVTEN22_Msk                 /*!< Event enable or disable on line 22 */

/* References Defines */
#define EXINT_EVTEN_EVT0                    EXINT_EVTEN_EVTEN0
#define EXINT_EVTEN_EVT1                    EXINT_EVTEN_EVTEN1
#define EXINT_EVTEN_EVT2                    EXINT_EVTEN_EVTEN2
#define EXINT_EVTEN_EVT3                    EXINT_EVTEN_EVTEN3
#define EXINT_EVTEN_EVT4                    EXINT_EVTEN_EVTEN4
#define EXINT_EVTEN_EVT5                    EXINT_EVTEN_EVTEN5
#define EXINT_EVTEN_EVT6                    EXINT_EVTEN_EVTEN6
#define EXINT_EVTEN_EVT7                    EXINT_EVTEN_EVTEN7
#define EXINT_EVTEN_EVT8                    EXINT_EVTEN_EVTEN8
#define EXINT_EVTEN_EVT9                    EXINT_EVTEN_EVTEN9
#define EXINT_EVTEN_EVT10                   EXINT_EVTEN_EVTEN10
#define EXINT_EVTEN_EVT11                   EXINT_EVTEN_EVTEN11
#define EXINT_EVTEN_EVT12                   EXINT_EVTEN_EVTEN12
#define EXINT_EVTEN_EVT13                   EXINT_EVTEN_EVTEN13
#define EXINT_EVTEN_EVT14                   EXINT_EVTEN_EVTEN14
#define EXINT_EVTEN_EVT15                   EXINT_EVTEN_EVTEN15
#define EXINT_EVTEN_EVT16                   EXINT_EVTEN_EVTEN16
#define EXINT_EVTEN_EVT17                   EXINT_EVTEN_EVTEN17
#define EXINT_EVTEN_EVT18                   EXINT_EVTEN_EVTEN18
#define EXINT_EVTEN_EVT19                   EXINT_EVTEN_EVTEN19
#define EXINT_EVTEN_EVT20                   EXINT_EVTEN_EVTEN20
#define EXINT_EVTEN_EVT21                   EXINT_EVTEN_EVTEN21
#define EXINT_EVTEN_EVT22                   EXINT_EVTEN_EVTEN22

/****************  Bit definition for EXINT_POLCFG1 register  *****************/
#define EXINT_POLCFG1_RP0_Pos               (0U)
#define EXINT_POLCFG1_RP0_Msk               (0x1U << EXINT_POLCFG1_RP0_Pos)         /*!< 0x00000001 */
#define EXINT_POLCFG1_RP0                   EXINT_POLCFG1_RP0_Msk                   /*!< Rising edge event configuration bit on line 0 */
#define EXINT_POLCFG1_RP1_Pos               (1U)
#define EXINT_POLCFG1_RP1_Msk               (0x1U << EXINT_POLCFG1_RP1_Pos)         /*!< 0x00000002 */
#define EXINT_POLCFG1_RP1                   EXINT_POLCFG1_RP1_Msk                   /*!< Rising edge event configuration bit on line 1 */
#define EXINT_POLCFG1_RP2_Pos               (2U)
#define EXINT_POLCFG1_RP2_Msk               (0x1U << EXINT_POLCFG1_RP2_Pos)         /*!< 0x00000004 */
#define EXINT_POLCFG1_RP2                   EXINT_POLCFG1_RP2_Msk                   /*!< Rising edge event configuration bit on line 2 */
#define EXINT_POLCFG1_RP3_Pos               (3U)
#define EXINT_POLCFG1_RP3_Msk               (0x1U << EXINT_POLCFG1_RP3_Pos)         /*!< 0x00000008 */
#define EXINT_POLCFG1_RP3                   EXINT_POLCFG1_RP3_Msk                   /*!< Rising edge event configuration bit on line 3 */
#define EXINT_POLCFG1_RP4_Pos               (4U)
#define EXINT_POLCFG1_RP4_Msk               (0x1U << EXINT_POLCFG1_RP4_Pos)         /*!< 0x00000010 */
#define EXINT_POLCFG1_RP4                   EXINT_POLCFG1_RP4_Msk                   /*!< Rising edge event configuration bit on line 4 */
#define EXINT_POLCFG1_RP5_Pos               (5U)
#define EXINT_POLCFG1_RP5_Msk               (0x1U << EXINT_POLCFG1_RP5_Pos)         /*!< 0x00000020 */
#define EXINT_POLCFG1_RP5                   EXINT_POLCFG1_RP5_Msk                   /*!< Rising edge event configuration bit on line 5 */
#define EXINT_POLCFG1_RP6_Pos               (6U)
#define EXINT_POLCFG1_RP6_Msk               (0x1U << EXINT_POLCFG1_RP6_Pos)         /*!< 0x00000040 */
#define EXINT_POLCFG1_RP6                   EXINT_POLCFG1_RP6_Msk                   /*!< Rising edge event configuration bit on line 6 */
#define EXINT_POLCFG1_RP7_Pos               (7U)
#define EXINT_POLCFG1_RP7_Msk               (0x1U << EXINT_POLCFG1_RP7_Pos)         /*!< 0x00000080 */
#define EXINT_POLCFG1_RP7                   EXINT_POLCFG1_RP7_Msk                   /*!< Rising edge event configuration bit on line 7 */
#define EXINT_POLCFG1_RP8_Pos               (8U)
#define EXINT_POLCFG1_RP8_Msk               (0x1U << EXINT_POLCFG1_RP8_Pos)         /*!< 0x00000100 */
#define EXINT_POLCFG1_RP8                   EXINT_POLCFG1_RP8_Msk                   /*!< Rising edge event configuration bit on line 8 */
#define EXINT_POLCFG1_RP9_Pos               (9U)
#define EXINT_POLCFG1_RP9_Msk               (0x1U << EXINT_POLCFG1_RP9_Pos)         /*!< 0x00000200 */
#define EXINT_POLCFG1_RP9                   EXINT_POLCFG1_RP9_Msk                   /*!< Rising edge event configuration bit on line 9 */
#define EXINT_POLCFG1_RP10_Pos              (10U)
#define EXINT_POLCFG1_RP10_Msk              (0x1U << EXINT_POLCFG1_RP10_Pos)        /*!< 0x00000400 */
#define EXINT_POLCFG1_RP10                  EXINT_POLCFG1_RP10_Msk                  /*!< Rising edge event configuration bit on line 10 */
#define EXINT_POLCFG1_RP11_Pos              (11U)
#define EXINT_POLCFG1_RP11_Msk              (0x1U << EXINT_POLCFG1_RP11_Pos)        /*!< 0x00000800 */
#define EXINT_POLCFG1_RP11                  EXINT_POLCFG1_RP11_Msk                  /*!< Rising edge event configuration bit on line 11 */
#define EXINT_POLCFG1_RP12_Pos              (12U)
#define EXINT_POLCFG1_RP12_Msk              (0x1U << EXINT_POLCFG1_RP12_Pos)        /*!< 0x00001000 */
#define EXINT_POLCFG1_RP12                  EXINT_POLCFG1_RP12_Msk                  /*!< Rising edge event configuration bit on line 12 */
#define EXINT_POLCFG1_RP13_Pos              (13U)
#define EXINT_POLCFG1_RP13_Msk              (0x1U << EXINT_POLCFG1_RP13_Pos)        /*!< 0x00002000 */
#define EXINT_POLCFG1_RP13                  EXINT_POLCFG1_RP13_Msk                  /*!< Rising edge event configuration bit on line 13 */
#define EXINT_POLCFG1_RP14_Pos              (14U)
#define EXINT_POLCFG1_RP14_Msk              (0x1U << EXINT_POLCFG1_RP14_Pos)        /*!< 0x00004000 */
#define EXINT_POLCFG1_RP14                  EXINT_POLCFG1_RP14_Msk                  /*!< Rising edge event configuration bit on line 14 */
#define EXINT_POLCFG1_RP15_Pos              (15U)
#define EXINT_POLCFG1_RP15_Msk              (0x1U << EXINT_POLCFG1_RP15_Pos)        /*!< 0x00008000 */
#define EXINT_POLCFG1_RP15                  EXINT_POLCFG1_RP15_Msk                  /*!< Rising edge event configuration bit on line 15 */
#define EXINT_POLCFG1_RP16_Pos              (16U)
#define EXINT_POLCFG1_RP16_Msk              (0x1U << EXINT_POLCFG1_RP16_Pos)        /*!< 0x00010000 */
#define EXINT_POLCFG1_RP16                  EXINT_POLCFG1_RP16_Msk                  /*!< Rising edge event configuration bit on line 16 */
#define EXINT_POLCFG1_RP17_Pos              (17U)
#define EXINT_POLCFG1_RP17_Msk              (0x1U << EXINT_POLCFG1_RP17_Pos)        /*!< 0x00020000 */
#define EXINT_POLCFG1_RP17                  EXINT_POLCFG1_RP17_Msk                  /*!< Rising edge event configuration bit on line 17 */
#define EXINT_POLCFG1_RP18_Pos              (18U)
#define EXINT_POLCFG1_RP18_Msk              (0x1U << EXINT_POLCFG1_RP18_Pos)        /*!< 0x00040000 */
#define EXINT_POLCFG1_RP18                  EXINT_POLCFG1_RP18_Msk                  /*!< Rising edge event configuration bit on line 18 */
#define EXINT_POLCFG1_RP19_Pos              (19U)
#define EXINT_POLCFG1_RP19_Msk              (0x1U << EXINT_POLCFG1_RP19_Pos)        /*!< 0x00080000 */
#define EXINT_POLCFG1_RP19                  EXINT_POLCFG1_RP19_Msk                  /*!< Rising edge event configuration bit on line 19 */
#define EXINT_POLCFG1_RP20_Pos              (20U)
#define EXINT_POLCFG1_RP20_Msk              (0x1U << EXINT_POLCFG1_RP20_Pos)        /*!< 0x00100000 */
#define EXINT_POLCFG1_RP20                  EXINT_POLCFG1_RP20_Msk                  /*!< Rising edge event configuration bit on line 20 */
#define EXINT_POLCFG1_RP21_Pos              (21U)
#define EXINT_POLCFG1_RP21_Msk              (0x1U << EXINT_POLCFG1_RP21_Pos)        /*!< 0x00200000 */
#define EXINT_POLCFG1_RP21                  EXINT_POLCFG1_RP21_Msk                  /*!< Rising edge event configuration bit on line 21 */
#define EXINT_POLCFG1_RP22_Pos              (22U)
#define EXINT_POLCFG1_RP22_Msk              (0x1U << EXINT_POLCFG1_RP22_Pos)        /*!< 0x00400000 */
#define EXINT_POLCFG1_RP22                  EXINT_POLCFG1_RP22_Msk                  /*!< Rising edge event configuration bit on line 22 */

/* References Defines */
#define EXINT_POLCFG1_POL0                  EXINT_POLCFG1_RP0
#define EXINT_POLCFG1_POL1                  EXINT_POLCFG1_RP1
#define EXINT_POLCFG1_POL2                  EXINT_POLCFG1_RP2
#define EXINT_POLCFG1_POL3                  EXINT_POLCFG1_RP3
#define EXINT_POLCFG1_POL4                  EXINT_POLCFG1_RP4
#define EXINT_POLCFG1_POL5                  EXINT_POLCFG1_RP5
#define EXINT_POLCFG1_POL6                  EXINT_POLCFG1_RP6
#define EXINT_POLCFG1_POL7                  EXINT_POLCFG1_RP7
#define EXINT_POLCFG1_POL8                  EXINT_POLCFG1_RP8
#define EXINT_POLCFG1_POL9                  EXINT_POLCFG1_RP9
#define EXINT_POLCFG1_POL10                 EXINT_POLCFG1_RP10
#define EXINT_POLCFG1_POL11                 EXINT_POLCFG1_RP11
#define EXINT_POLCFG1_POL12                 EXINT_POLCFG1_RP12
#define EXINT_POLCFG1_POL13                 EXINT_POLCFG1_RP13
#define EXINT_POLCFG1_POL14                 EXINT_POLCFG1_RP14
#define EXINT_POLCFG1_POL15                 EXINT_POLCFG1_RP15
#define EXINT_POLCFG1_POL16                 EXINT_POLCFG1_RP16
#define EXINT_POLCFG1_POL17                 EXINT_POLCFG1_RP17
#define EXINT_POLCFG1_POL18                 EXINT_POLCFG1_RP18
#define EXINT_POLCFG1_POL19                 EXINT_POLCFG1_RP19
#define EXINT_POLCFG1_POL20                 EXINT_POLCFG1_RP20
#define EXINT_POLCFG1_POL21                 EXINT_POLCFG1_RP21
#define EXINT_POLCFG1_POL22                 EXINT_POLCFG1_RP22

/****************  Bit definition for EXINT_POLCFG2 register  *****************/
#define EXINT_POLCFG2_FP0_Pos               (0U)
#define EXINT_POLCFG2_FP0_Msk               (0x1U << EXINT_POLCFG2_FP0_Pos)         /*!< 0x00000001 */
#define EXINT_POLCFG2_FP0                   EXINT_POLCFG2_FP0_Msk                   /*!< Falling edge event configuration bit on line 0 */
#define EXINT_POLCFG2_FP1_Pos               (1U)
#define EXINT_POLCFG2_FP1_Msk               (0x1U << EXINT_POLCFG2_FP1_Pos)         /*!< 0x00000002 */
#define EXINT_POLCFG2_FP1                   EXINT_POLCFG2_FP1_Msk                   /*!< Falling edge event configuration bit on line 1 */
#define EXINT_POLCFG2_FP2_Pos               (2U)
#define EXINT_POLCFG2_FP2_Msk               (0x1U << EXINT_POLCFG2_FP2_Pos)         /*!< 0x00000004 */
#define EXINT_POLCFG2_FP2                   EXINT_POLCFG2_FP2_Msk                   /*!< Falling edge event configuration bit on line 2 */
#define EXINT_POLCFG2_FP3_Pos               (3U)
#define EXINT_POLCFG2_FP3_Msk               (0x1U << EXINT_POLCFG2_FP3_Pos)         /*!< 0x00000008 */
#define EXINT_POLCFG2_FP3                   EXINT_POLCFG2_FP3_Msk                   /*!< Falling edge event configuration bit on line 3 */
#define EXINT_POLCFG2_FP4_Pos               (4U)
#define EXINT_POLCFG2_FP4_Msk               (0x1U << EXINT_POLCFG2_FP4_Pos)         /*!< 0x00000010 */
#define EXINT_POLCFG2_FP4                   EXINT_POLCFG2_FP4_Msk                   /*!< Falling edge event configuration bit on line 4 */
#define EXINT_POLCFG2_FP5_Pos               (5U)
#define EXINT_POLCFG2_FP5_Msk               (0x1U << EXINT_POLCFG2_FP5_Pos)         /*!< 0x00000020 */
#define EXINT_POLCFG2_FP5                   EXINT_POLCFG2_FP5_Msk                   /*!< Falling edge event configuration bit on line 5 */
#define EXINT_POLCFG2_FP6_Pos               (6U)
#define EXINT_POLCFG2_FP6_Msk               (0x1U << EXINT_POLCFG2_FP6_Pos)         /*!< 0x00000040 */
#define EXINT_POLCFG2_FP6                   EXINT_POLCFG2_FP6_Msk                   /*!< Falling edge event configuration bit on line 6 */
#define EXINT_POLCFG2_FP7_Pos               (7U)
#define EXINT_POLCFG2_FP7_Msk               (0x1U << EXINT_POLCFG2_FP7_Pos)         /*!< 0x00000080 */
#define EXINT_POLCFG2_FP7                   EXINT_POLCFG2_FP7_Msk                   /*!< Falling edge event configuration bit on line 7 */
#define EXINT_POLCFG2_FP8_Pos               (8U)
#define EXINT_POLCFG2_FP8_Msk               (0x1U << EXINT_POLCFG2_FP8_Pos)         /*!< 0x00000100 */
#define EXINT_POLCFG2_FP8                   EXINT_POLCFG2_FP8_Msk                   /*!< Falling edge event configuration bit on line 8 */
#define EXINT_POLCFG2_FP9_Pos               (9U)
#define EXINT_POLCFG2_FP9_Msk               (0x1U << EXINT_POLCFG2_FP9_Pos)         /*!< 0x00000200 */
#define EXINT_POLCFG2_FP9                   EXINT_POLCFG2_FP9_Msk                   /*!< Falling edge event configuration bit on line 9 */
#define EXINT_POLCFG2_FP10_Pos              (10U)
#define EXINT_POLCFG2_FP10_Msk              (0x1U << EXINT_POLCFG2_FP10_Pos)        /*!< 0x00000400 */
#define EXINT_POLCFG2_FP10                  EXINT_POLCFG2_FP10_Msk                  /*!< Falling edge event configuration bit on line 10 */
#define EXINT_POLCFG2_FP11_Pos              (11U)
#define EXINT_POLCFG2_FP11_Msk              (0x1U << EXINT_POLCFG2_FP11_Pos)        /*!< 0x00000800 */
#define EXINT_POLCFG2_FP11                  EXINT_POLCFG2_FP11_Msk                  /*!< Falling edge event configuration bit on line 11 */
#define EXINT_POLCFG2_FP12_Pos              (12U)
#define EXINT_POLCFG2_FP12_Msk              (0x1U << EXINT_POLCFG2_FP12_Pos)        /*!< 0x00001000 */
#define EXINT_POLCFG2_FP12                  EXINT_POLCFG2_FP12_Msk                  /*!< Falling edge event configuration bit on line 12 */
#define EXINT_POLCFG2_FP13_Pos              (13U)
#define EXINT_POLCFG2_FP13_Msk              (0x1U << EXINT_POLCFG2_FP13_Pos)        /*!< 0x00002000 */
#define EXINT_POLCFG2_FP13                  EXINT_POLCFG2_FP13_Msk                  /*!< Falling edge event configuration bit on line 13 */
#define EXINT_POLCFG2_FP14_Pos              (14U)
#define EXINT_POLCFG2_FP14_Msk              (0x1U << EXINT_POLCFG2_FP14_Pos)        /*!< 0x00004000 */
#define EXINT_POLCFG2_FP14                  EXINT_POLCFG2_FP14_Msk                  /*!< Falling edge event configuration bit on line 14 */
#define EXINT_POLCFG2_FP15_Pos              (15U)
#define EXINT_POLCFG2_FP15_Msk              (0x1U << EXINT_POLCFG2_FP15_Pos)        /*!< 0x00008000 */
#define EXINT_POLCFG2_FP15                  EXINT_POLCFG2_FP15_Msk                  /*!< Falling edge event configuration bit on line 15 */
#define EXINT_POLCFG2_FP16_Pos              (16U)
#define EXINT_POLCFG2_FP16_Msk              (0x1U << EXINT_POLCFG2_FP16_Pos)        /*!< 0x00010000 */
#define EXINT_POLCFG2_FP16                  EXINT_POLCFG2_FP16_Msk                  /*!< Falling edge event configuration bit on line 16 */
#define EXINT_POLCFG2_FP17_Pos              (17U)
#define EXINT_POLCFG2_FP17_Msk              (0x1U << EXINT_POLCFG2_FP17_Pos)        /*!< 0x00020000 */
#define EXINT_POLCFG2_FP17                  EXINT_POLCFG2_FP17_Msk                  /*!< Falling edge event configuration bit on line 17 */
#define EXINT_POLCFG2_FP18_Pos              (18U)
#define EXINT_POLCFG2_FP18_Msk              (0x1U << EXINT_POLCFG2_FP18_Pos)        /*!< 0x00040000 */
#define EXINT_POLCFG2_FP18                  EXINT_POLCFG2_FP18_Msk                  /*!< Falling edge event configuration bit on line 18 */
#define EXINT_POLCFG2_FP19_Pos              (19U)
#define EXINT_POLCFG2_FP19_Msk              (0x1U << EXINT_POLCFG2_FP19_Pos)        /*!< 0x00080000 */
#define EXINT_POLCFG2_FP19                  EXINT_POLCFG2_FP19_Msk                  /*!< Falling edge event configuration bit on line 19 */
#define EXINT_POLCFG2_FP20_Pos              (20U)
#define EXINT_POLCFG2_FP20_Msk              (0x1U << EXINT_POLCFG2_FP20_Pos)        /*!< 0x00100000 */
#define EXINT_POLCFG2_FP20                  EXINT_POLCFG2_FP20_Msk                  /*!< Falling edge event configuration bit on line 20 */
#define EXINT_POLCFG2_FP21_Pos              (21U)
#define EXINT_POLCFG2_FP21_Msk              (0x1U << EXINT_POLCFG2_FP21_Pos)        /*!< 0x00200000 */
#define EXINT_POLCFG2_FP21                  EXINT_POLCFG2_FP21_Msk                  /*!< Falling edge event configuration bit on line 21 */
#define EXINT_POLCFG2_FP22_Pos              (22U)
#define EXINT_POLCFG2_FP22_Msk              (0x1U << EXINT_POLCFG2_FP22_Pos)        /*!< 0x00400000 */
#define EXINT_POLCFG2_FP22                  EXINT_POLCFG2_FP22_Msk                  /*!< Falling edge event configuration bit on line 22 */

/* References Defines */
#define EXINT_POLCFG2_POL0                  EXINT_POLCFG2_FP0
#define EXINT_POLCFG2_POL1                  EXINT_POLCFG2_FP1
#define EXINT_POLCFG2_POL2                  EXINT_POLCFG2_FP2
#define EXINT_POLCFG2_POL3                  EXINT_POLCFG2_FP3
#define EXINT_POLCFG2_POL4                  EXINT_POLCFG2_FP4
#define EXINT_POLCFG2_POL5                  EXINT_POLCFG2_FP5
#define EXINT_POLCFG2_POL6                  EXINT_POLCFG2_FP6
#define EXINT_POLCFG2_POL7                  EXINT_POLCFG2_FP7
#define EXINT_POLCFG2_POL8                  EXINT_POLCFG2_FP8
#define EXINT_POLCFG2_POL9                  EXINT_POLCFG2_FP9
#define EXINT_POLCFG2_POL10                 EXINT_POLCFG2_FP10
#define EXINT_POLCFG2_POL11                 EXINT_POLCFG2_FP11
#define EXINT_POLCFG2_POL12                 EXINT_POLCFG2_FP12
#define EXINT_POLCFG2_POL13                 EXINT_POLCFG2_FP13
#define EXINT_POLCFG2_POL14                 EXINT_POLCFG2_FP14
#define EXINT_POLCFG2_POL15                 EXINT_POLCFG2_FP15
#define EXINT_POLCFG2_POL16                 EXINT_POLCFG2_FP16
#define EXINT_POLCFG2_POL17                 EXINT_POLCFG2_FP17
#define EXINT_POLCFG2_POL18                 EXINT_POLCFG2_FP18
#define EXINT_POLCFG2_POL19                 EXINT_POLCFG2_FP19
#define EXINT_POLCFG2_POL20                 EXINT_POLCFG2_FP20
#define EXINT_POLCFG2_POL21                 EXINT_POLCFG2_FP21
#define EXINT_POLCFG2_POL22                 EXINT_POLCFG2_FP22

/*****************  Bit definition for EXINT_SWTRG register  ******************/
#define EXINT_SWTRG_SWT0_Pos                (0U)
#define EXINT_SWTRG_SWT0_Msk                (0x1U << EXINT_SWTRG_SWT0_Pos)          /*!< 0x00000001 */
#define EXINT_SWTRG_SWT0                    EXINT_SWTRG_SWT0_Msk                    /*!< Software trigger on line 0 */
#define EXINT_SWTRG_SWT1_Pos                (1U)
#define EXINT_SWTRG_SWT1_Msk                (0x1U << EXINT_SWTRG_SWT1_Pos)          /*!< 0x00000002 */
#define EXINT_SWTRG_SWT1                    EXINT_SWTRG_SWT1_Msk                    /*!< Software trigger on line 1 */
#define EXINT_SWTRG_SWT2_Pos                (2U)
#define EXINT_SWTRG_SWT2_Msk                (0x1U << EXINT_SWTRG_SWT2_Pos)          /*!< 0x00000004 */
#define EXINT_SWTRG_SWT2                    EXINT_SWTRG_SWT2_Msk                    /*!< Software trigger on line 2 */
#define EXINT_SWTRG_SWT3_Pos                (3U)
#define EXINT_SWTRG_SWT3_Msk                (0x1U << EXINT_SWTRG_SWT3_Pos)          /*!< 0x00000008 */
#define EXINT_SWTRG_SWT3                    EXINT_SWTRG_SWT3_Msk                    /*!< Software trigger on line 3 */
#define EXINT_SWTRG_SWT4_Pos                (4U)
#define EXINT_SWTRG_SWT4_Msk                (0x1U << EXINT_SWTRG_SWT4_Pos)          /*!< 0x00000010 */
#define EXINT_SWTRG_SWT4                    EXINT_SWTRG_SWT4_Msk                    /*!< Software trigger on line 4 */
#define EXINT_SWTRG_SWT5_Pos                (5U)
#define EXINT_SWTRG_SWT5_Msk                (0x1U << EXINT_SWTRG_SWT5_Pos)          /*!< 0x00000020 */
#define EXINT_SWTRG_SWT5                    EXINT_SWTRG_SWT5_Msk                    /*!< Software trigger on line 5 */
#define EXINT_SWTRG_SWT6_Pos                (6U)
#define EXINT_SWTRG_SWT6_Msk                (0x1U << EXINT_SWTRG_SWT6_Pos)          /*!< 0x00000040 */
#define EXINT_SWTRG_SWT6                    EXINT_SWTRG_SWT6_Msk                    /*!< Software trigger on line 6 */
#define EXINT_SWTRG_SWT7_Pos                (7U)
#define EXINT_SWTRG_SWT7_Msk                (0x1U << EXINT_SWTRG_SWT7_Pos)          /*!< 0x00000080 */
#define EXINT_SWTRG_SWT7                    EXINT_SWTRG_SWT7_Msk                    /*!< Software trigger on line 7 */
#define EXINT_SWTRG_SWT8_Pos                (8U)
#define EXINT_SWTRG_SWT8_Msk                (0x1U << EXINT_SWTRG_SWT8_Pos)          /*!< 0x00000100 */
#define EXINT_SWTRG_SWT8                    EXINT_SWTRG_SWT8_Msk                    /*!< Software trigger on line 8 */
#define EXINT_SWTRG_SWT9_Pos                (9U)
#define EXINT_SWTRG_SWT9_Msk                (0x1U << EXINT_SWTRG_SWT9_Pos)          /*!< 0x00000200 */
#define EXINT_SWTRG_SWT9                    EXINT_SWTRG_SWT9_Msk                    /*!< Software trigger on line 9 */
#define EXINT_SWTRG_SWT10_Pos               (10U)
#define EXINT_SWTRG_SWT10_Msk               (0x1U << EXINT_SWTRG_SWT10_Pos)         /*!< 0x00000400 */
#define EXINT_SWTRG_SWT10                   EXINT_SWTRG_SWT10_Msk                   /*!< Software trigger on line 10 */
#define EXINT_SWTRG_SWT11_Pos               (11U)
#define EXINT_SWTRG_SWT11_Msk               (0x1U << EXINT_SWTRG_SWT11_Pos)         /*!< 0x00000800 */
#define EXINT_SWTRG_SWT11                   EXINT_SWTRG_SWT11_Msk                   /*!< Software trigger on line 11 */
#define EXINT_SWTRG_SWT12_Pos               (12U)
#define EXINT_SWTRG_SWT12_Msk               (0x1U << EXINT_SWTRG_SWT12_Pos)         /*!< 0x00001000 */
#define EXINT_SWTRG_SWT12                   EXINT_SWTRG_SWT12_Msk                   /*!< Software trigger on line 12 */
#define EXINT_SWTRG_SWT13_Pos               (13U)
#define EXINT_SWTRG_SWT13_Msk               (0x1U << EXINT_SWTRG_SWT13_Pos)         /*!< 0x00002000 */
#define EXINT_SWTRG_SWT13                   EXINT_SWTRG_SWT13_Msk                   /*!< Software trigger on line 13 */
#define EXINT_SWTRG_SWT14_Pos               (14U)
#define EXINT_SWTRG_SWT14_Msk               (0x1U << EXINT_SWTRG_SWT14_Pos)         /*!< 0x00004000 */
#define EXINT_SWTRG_SWT14                   EXINT_SWTRG_SWT14_Msk                   /*!< Software trigger on line 14 */
#define EXINT_SWTRG_SWT15_Pos               (15U)
#define EXINT_SWTRG_SWT15_Msk               (0x1U << EXINT_SWTRG_SWT15_Pos)         /*!< 0x00008000 */
#define EXINT_SWTRG_SWT15                   EXINT_SWTRG_SWT15_Msk                   /*!< Software trigger on line 15 */
#define EXINT_SWTRG_SWT16_Pos               (16U)
#define EXINT_SWTRG_SWT16_Msk               (0x1U << EXINT_SWTRG_SWT16_Pos)         /*!< 0x00010000 */
#define EXINT_SWTRG_SWT16                   EXINT_SWTRG_SWT16_Msk                   /*!< Software trigger on line 16 */
#define EXINT_SWTRG_SWT17_Pos               (17U)
#define EXINT_SWTRG_SWT17_Msk               (0x1U << EXINT_SWTRG_SWT17_Pos)         /*!< 0x00020000 */
#define EXINT_SWTRG_SWT17                   EXINT_SWTRG_SWT17_Msk                   /*!< Software trigger on line 17 */
#define EXINT_SWTRG_SWT18_Pos               (18U)
#define EXINT_SWTRG_SWT18_Msk               (0x1U << EXINT_SWTRG_SWT18_Pos)         /*!< 0x00040000 */
#define EXINT_SWTRG_SWT18                   EXINT_SWTRG_SWT18_Msk                   /*!< Software trigger on line 18 */
#define EXINT_SWTRG_SWT19_Pos               (19U)
#define EXINT_SWTRG_SWT19_Msk               (0x1U << EXINT_SWTRG_SWT19_Pos)         /*!< 0x00080000 */
#define EXINT_SWTRG_SWT19                   EXINT_SWTRG_SWT19_Msk                   /*!< Software trigger on line 19 */
#define EXINT_SWTRG_SWT20_Pos               (20U)
#define EXINT_SWTRG_SWT20_Msk               (0x1U << EXINT_SWTRG_SWT20_Pos)         /*!< 0x00100000 */
#define EXINT_SWTRG_SWT20                   EXINT_SWTRG_SWT20_Msk                   /*!< Software trigger on line 20 */
#define EXINT_SWTRG_SWT21_Pos               (21U)
#define EXINT_SWTRG_SWT21_Msk               (0x1U << EXINT_SWTRG_SWT21_Pos)         /*!< 0x00200000 */
#define EXINT_SWTRG_SWT21                   EXINT_SWTRG_SWT21_Msk                   /*!< Software trigger on line 21 */
#define EXINT_SWTRG_SWT22_Pos               (22U)
#define EXINT_SWTRG_SWT22_Msk               (0x1U << EXINT_SWTRG_SWT22_Pos)         /*!< 0x00400000 */
#define EXINT_SWTRG_SWT22                   EXINT_SWTRG_SWT22_Msk                   /*!< Software trigger on line 22 */

/* References Defines */
#define EXINT_SWTRG_SW0                     EXINT_SWTRG_SWT0
#define EXINT_SWTRG_SW1                     EXINT_SWTRG_SWT1
#define EXINT_SWTRG_SW2                     EXINT_SWTRG_SWT2
#define EXINT_SWTRG_SW3                     EXINT_SWTRG_SWT3
#define EXINT_SWTRG_SW4                     EXINT_SWTRG_SWT4
#define EXINT_SWTRG_SW5                     EXINT_SWTRG_SWT5
#define EXINT_SWTRG_SW6                     EXINT_SWTRG_SWT6
#define EXINT_SWTRG_SW7                     EXINT_SWTRG_SWT7
#define EXINT_SWTRG_SW8                     EXINT_SWTRG_SWT8
#define EXINT_SWTRG_SW9                     EXINT_SWTRG_SWT9
#define EXINT_SWTRG_SW10                    EXINT_SWTRG_SWT10
#define EXINT_SWTRG_SW11                    EXINT_SWTRG_SWT11
#define EXINT_SWTRG_SW12                    EXINT_SWTRG_SWT12
#define EXINT_SWTRG_SW13                    EXINT_SWTRG_SWT13
#define EXINT_SWTRG_SW14                    EXINT_SWTRG_SWT14
#define EXINT_SWTRG_SW15                    EXINT_SWTRG_SWT15
#define EXINT_SWTRG_SW16                    EXINT_SWTRG_SWT16
#define EXINT_SWTRG_SW17                    EXINT_SWTRG_SWT17
#define EXINT_SWTRG_SW18                    EXINT_SWTRG_SWT18
#define EXINT_SWTRG_SW19                    EXINT_SWTRG_SWT19
#define EXINT_SWTRG_SW20                    EXINT_SWTRG_SWT20
#define EXINT_SWTRG_SW21                    EXINT_SWTRG_SWT21
#define EXINT_SWTRG_SW22                    EXINT_SWTRG_SWT22

/*****************  Bit definition for EXINT_INTSTS register  *****************/
#define EXINT_INTSTS_LINE0_Pos              (0U)
#define EXINT_INTSTS_LINE0_Msk              (0x1U << EXINT_INTSTS_LINE0_Pos)        /*!< 0x00000001 */
#define EXINT_INTSTS_LINE0                  EXINT_INTSTS_LINE0_Msk                  /*!< Status bit for line 0 */
#define EXINT_INTSTS_LINE1_Pos              (1U)
#define EXINT_INTSTS_LINE1_Msk              (0x1U << EXINT_INTSTS_LINE1_Pos)        /*!< 0x00000002 */
#define EXINT_INTSTS_LINE1                  EXINT_INTSTS_LINE1_Msk                  /*!< Status bit for line 1 */
#define EXINT_INTSTS_LINE2_Pos              (2U)
#define EXINT_INTSTS_LINE2_Msk              (0x1U << EXINT_INTSTS_LINE2_Pos)        /*!< 0x00000004 */
#define EXINT_INTSTS_LINE2                  EXINT_INTSTS_LINE2_Msk                  /*!< Status bit for line 2 */
#define EXINT_INTSTS_LINE3_Pos              (3U)
#define EXINT_INTSTS_LINE3_Msk              (0x1U << EXINT_INTSTS_LINE3_Pos)        /*!< 0x00000008 */
#define EXINT_INTSTS_LINE3                  EXINT_INTSTS_LINE3_Msk                  /*!< Status bit for line 3 */
#define EXINT_INTSTS_LINE4_Pos              (4U)
#define EXINT_INTSTS_LINE4_Msk              (0x1U << EXINT_INTSTS_LINE4_Pos)        /*!< 0x00000010 */
#define EXINT_INTSTS_LINE4                  EXINT_INTSTS_LINE4_Msk                  /*!< Status bit for line 4 */
#define EXINT_INTSTS_LINE5_Pos              (5U)
#define EXINT_INTSTS_LINE5_Msk              (0x1U << EXINT_INTSTS_LINE5_Pos)        /*!< 0x00000020 */
#define EXINT_INTSTS_LINE5                  EXINT_INTSTS_LINE5_Msk                  /*!< Status bit for line 5 */
#define EXINT_INTSTS_LINE6_Pos              (6U)
#define EXINT_INTSTS_LINE6_Msk              (0x1U << EXINT_INTSTS_LINE6_Pos)        /*!< 0x00000040 */
#define EXINT_INTSTS_LINE6                  EXINT_INTSTS_LINE6_Msk                  /*!< Status bit for line 6 */
#define EXINT_INTSTS_LINE7_Pos              (7U)
#define EXINT_INTSTS_LINE7_Msk              (0x1U << EXINT_INTSTS_LINE7_Pos)        /*!< 0x00000080 */
#define EXINT_INTSTS_LINE7                  EXINT_INTSTS_LINE7_Msk                  /*!< Status bit for line 7 */
#define EXINT_INTSTS_LINE8_Pos              (8U)
#define EXINT_INTSTS_LINE8_Msk              (0x1U << EXINT_INTSTS_LINE8_Pos)        /*!< 0x00000100 */
#define EXINT_INTSTS_LINE8                  EXINT_INTSTS_LINE8_Msk                  /*!< Status bit for line 8 */
#define EXINT_INTSTS_LINE9_Pos              (9U)
#define EXINT_INTSTS_LINE9_Msk              (0x1U << EXINT_INTSTS_LINE9_Pos)        /*!< 0x00000200 */
#define EXINT_INTSTS_LINE9                  EXINT_INTSTS_LINE9_Msk                  /*!< Status bit for line 9 */
#define EXINT_INTSTS_LINE10_Pos             (10U)
#define EXINT_INTSTS_LINE10_Msk             (0x1U << EXINT_INTSTS_LINE10_Pos)       /*!< 0x00000400 */
#define EXINT_INTSTS_LINE10                 EXINT_INTSTS_LINE10_Msk                 /*!< Status bit for line 10 */
#define EXINT_INTSTS_LINE11_Pos             (11U)
#define EXINT_INTSTS_LINE11_Msk             (0x1U << EXINT_INTSTS_LINE11_Pos)       /*!< 0x00000800 */
#define EXINT_INTSTS_LINE11                 EXINT_INTSTS_LINE11_Msk                 /*!< Status bit for line 11 */
#define EXINT_INTSTS_LINE12_Pos             (12U)
#define EXINT_INTSTS_LINE12_Msk             (0x1U << EXINT_INTSTS_LINE12_Pos)       /*!< 0x00001000 */
#define EXINT_INTSTS_LINE12                 EXINT_INTSTS_LINE12_Msk                 /*!< Status bit for line 12 */
#define EXINT_INTSTS_LINE13_Pos             (13U)
#define EXINT_INTSTS_LINE13_Msk             (0x1U << EXINT_INTSTS_LINE13_Pos)       /*!< 0x00002000 */
#define EXINT_INTSTS_LINE13                 EXINT_INTSTS_LINE13_Msk                 /*!< Status bit for line 13 */
#define EXINT_INTSTS_LINE14_Pos             (14U)
#define EXINT_INTSTS_LINE14_Msk             (0x1U << EXINT_INTSTS_LINE14_Pos)       /*!< 0x00004000 */
#define EXINT_INTSTS_LINE14                 EXINT_INTSTS_LINE14_Msk                 /*!< Status bit for line 14 */
#define EXINT_INTSTS_LINE15_Pos             (15U)
#define EXINT_INTSTS_LINE15_Msk             (0x1U << EXINT_INTSTS_LINE15_Pos)       /*!< 0x00008000 */
#define EXINT_INTSTS_LINE15                 EXINT_INTSTS_LINE15_Msk                 /*!< Status bit for line 15 */
#define EXINT_INTSTS_LINE16_Pos             (16U)
#define EXINT_INTSTS_LINE16_Msk             (0x1U << EXINT_INTSTS_LINE16_Pos)       /*!< 0x00010000 */
#define EXINT_INTSTS_LINE16                 EXINT_INTSTS_LINE16_Msk                 /*!< Status bit for line 16 */
#define EXINT_INTSTS_LINE17_Pos             (17U)
#define EXINT_INTSTS_LINE17_Msk             (0x1U << EXINT_INTSTS_LINE17_Pos)       /*!< 0x00020000 */
#define EXINT_INTSTS_LINE17                 EXINT_INTSTS_LINE17_Msk                 /*!< Status bit for line 17 */
#define EXINT_INTSTS_LINE18_Pos             (18U)
#define EXINT_INTSTS_LINE18_Msk             (0x1U << EXINT_INTSTS_LINE18_Pos)       /*!< 0x00040000 */
#define EXINT_INTSTS_LINE18                 EXINT_INTSTS_LINE18_Msk                 /*!< Status bit for line 18 */
#define EXINT_INTSTS_LINE19_Pos             (19U)
#define EXINT_INTSTS_LINE19_Msk             (0x1U << EXINT_INTSTS_LINE19_Pos)       /*!< 0x00080000 */
#define EXINT_INTSTS_LINE19                 EXINT_INTSTS_LINE19_Msk                 /*!< Status bit for line 19 */
#define EXINT_INTSTS_LINE20_Pos             (20U)
#define EXINT_INTSTS_LINE20_Msk             (0x1U << EXINT_INTSTS_LINE20_Pos)       /*!< 0x00100000 */
#define EXINT_INTSTS_LINE20                 EXINT_INTSTS_LINE20_Msk                 /*!< Status bit for line 20 */
#define EXINT_INTSTS_LINE21_Pos             (21U)
#define EXINT_INTSTS_LINE21_Msk             (0x1U << EXINT_INTSTS_LINE21_Pos)       /*!< 0x00200000 */
#define EXINT_INTSTS_LINE21                 EXINT_INTSTS_LINE21_Msk                 /*!< Status bit for line 21 */
#define EXINT_INTSTS_LINE22_Pos             (22U)
#define EXINT_INTSTS_LINE22_Msk             (0x1U << EXINT_INTSTS_LINE22_Pos)       /*!< 0x00400000 */
#define EXINT_INTSTS_LINE22                 EXINT_INTSTS_LINE22_Msk                 /*!< Status bit for line 22 */

/* References Defines */
#define EXINT_INTSTS_INT0                   EXINT_INTSTS_LINE0
#define EXINT_INTSTS_INT1                   EXINT_INTSTS_LINE1
#define EXINT_INTSTS_INT2                   EXINT_INTSTS_LINE2
#define EXINT_INTSTS_INT3                   EXINT_INTSTS_LINE3
#define EXINT_INTSTS_INT4                   EXINT_INTSTS_LINE4
#define EXINT_INTSTS_INT5                   EXINT_INTSTS_LINE5
#define EXINT_INTSTS_INT6                   EXINT_INTSTS_LINE6
#define EXINT_INTSTS_INT7                   EXINT_INTSTS_LINE7
#define EXINT_INTSTS_INT8                   EXINT_INTSTS_LINE8
#define EXINT_INTSTS_INT9                   EXINT_INTSTS_LINE9
#define EXINT_INTSTS_INT10                  EXINT_INTSTS_LINE10
#define EXINT_INTSTS_INT11                  EXINT_INTSTS_LINE11
#define EXINT_INTSTS_INT12                  EXINT_INTSTS_LINE12
#define EXINT_INTSTS_INT13                  EXINT_INTSTS_LINE13
#define EXINT_INTSTS_INT14                  EXINT_INTSTS_LINE14
#define EXINT_INTSTS_INT15                  EXINT_INTSTS_LINE15
#define EXINT_INTSTS_INT16                  EXINT_INTSTS_LINE16
#define EXINT_INTSTS_INT17                  EXINT_INTSTS_LINE17
#define EXINT_INTSTS_INT18                  EXINT_INTSTS_LINE18
#define EXINT_INTSTS_INT19                  EXINT_INTSTS_LINE19
#define EXINT_INTSTS_INT20                  EXINT_INTSTS_LINE20
#define EXINT_INTSTS_INT21                  EXINT_INTSTS_LINE21
#define EXINT_INTSTS_INT22                  EXINT_INTSTS_LINE22

/******************************************************************************/
/*                                                                            */
/*                            DMA controller (DMA)                            */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for DMA_STS register  ********************/
#define DMA_STS_GF1_Pos                     (0U)
#define DMA_STS_GF1_Msk                     (0x1U << DMA_STS_GF1_Pos)               /*!< 0x00000001 */
#define DMA_STS_GF1                         DMA_STS_GF1_Msk                         /*!< Channel 1 global event flag */
#define DMA_STS_FDTF1_Pos                   (1U)
#define DMA_STS_FDTF1_Msk                   (0x1U << DMA_STS_FDTF1_Pos)             /*!< 0x00000002 */
#define DMA_STS_FDTF1                       DMA_STS_FDTF1_Msk                       /*!< Channel 1 transfer complete event flag */
#define DMA_STS_HDTF1_Pos                   (2U)
#define DMA_STS_HDTF1_Msk                   (0x1U << DMA_STS_HDTF1_Pos)             /*!< 0x00000004 */
#define DMA_STS_HDTF1                       DMA_STS_HDTF1_Msk                       /*!< Channel 1 half transfer event flag */
#define DMA_STS_DTERRF1_Pos                 (3U)
#define DMA_STS_DTERRF1_Msk                 (0x1U << DMA_STS_DTERRF1_Pos)           /*!< 0x00000008 */
#define DMA_STS_DTERRF1                     DMA_STS_DTERRF1_Msk                     /*!< Channel 1 transfer error event flag */
#define DMA_STS_GF2_Pos                     (4U)
#define DMA_STS_GF2_Msk                     (0x1U << DMA_STS_GF2_Pos)               /*!< 0x00000010 */
#define DMA_STS_GF2                         DMA_STS_GF2_Msk                         /*!< Channel 2 global event flag */
#define DMA_STS_FDTF2_Pos                   (5U)
#define DMA_STS_FDTF2_Msk                   (0x1U << DMA_STS_FDTF2_Pos)             /*!< 0x00000020 */
#define DMA_STS_FDTF2                       DMA_STS_FDTF2_Msk                       /*!< Channel 2 transfer complete event flag */
#define DMA_STS_HDTF2_Pos                   (6U)
#define DMA_STS_HDTF2_Msk                   (0x1U << DMA_STS_HDTF2_Pos)             /*!< 0x00000040 */
#define DMA_STS_HDTF2                       DMA_STS_HDTF2_Msk                       /*!< Channel 2 half transfer event flag */
#define DMA_STS_DTERRF2_Pos                 (7U)
#define DMA_STS_DTERRF2_Msk                 (0x1U << DMA_STS_DTERRF2_Pos)           /*!< 0x00000080 */
#define DMA_STS_DTERRF2                     DMA_STS_DTERRF2_Msk                     /*!< Channel 2 transfer error event flag */
#define DMA_STS_GF3_Pos                     (8U)
#define DMA_STS_GF3_Msk                     (0x1U << DMA_STS_GF3_Pos)               /*!< 0x00000100 */
#define DMA_STS_GF3                         DMA_STS_GF3_Msk                         /*!< Channel 3 global event flag */
#define DMA_STS_FDTF3_Pos                   (9U)
#define DMA_STS_FDTF3_Msk                   (0x1U << DMA_STS_FDTF3_Pos)             /*!< 0x00000200 */
#define DMA_STS_FDTF3                       DMA_STS_FDTF3_Msk                       /*!< Channel 3 transfer complete event flag */
#define DMA_STS_HDTF3_Pos                   (10U)
#define DMA_STS_HDTF3_Msk                   (0x1U << DMA_STS_HDTF3_Pos)             /*!< 0x00000400 */
#define DMA_STS_HDTF3                       DMA_STS_HDTF3_Msk                       /*!< Channel 3 half transfer event flag */
#define DMA_STS_DTERRF3_Pos                 (11U)
#define DMA_STS_DTERRF3_Msk                 (0x1U << DMA_STS_DTERRF3_Pos)           /*!< 0x00000800 */
#define DMA_STS_DTERRF3                     DMA_STS_DTERRF3_Msk                     /*!< Channel 3 transfer error event flag */
#define DMA_STS_GF4_Pos                     (12U)
#define DMA_STS_GF4_Msk                     (0x1U << DMA_STS_GF4_Pos)               /*!< 0x00001000 */
#define DMA_STS_GF4                         DMA_STS_GF4_Msk                         /*!< Channel 4 global event flag */
#define DMA_STS_FDTF4_Pos                   (13U)
#define DMA_STS_FDTF4_Msk                   (0x1U << DMA_STS_FDTF4_Pos)             /*!< 0x00002000 */
#define DMA_STS_FDTF4                       DMA_STS_FDTF4_Msk                       /*!< Channel 4 transfer complete event flag */
#define DMA_STS_HDTF4_Pos                   (14U)
#define DMA_STS_HDTF4_Msk                   (0x1U << DMA_STS_HDTF4_Pos)             /*!< 0x00004000 */
#define DMA_STS_HDTF4                       DMA_STS_HDTF4_Msk                       /*!< Channel 4 half transfer event flag */
#define DMA_STS_DTERRF4_Pos                 (15U)
#define DMA_STS_DTERRF4_Msk                 (0x1U << DMA_STS_DTERRF4_Pos)           /*!< 0x00008000 */
#define DMA_STS_DTERRF4                     DMA_STS_DTERRF4_Msk                     /*!< Channel 4 transfer error event flag */
#define DMA_STS_GF5_Pos                     (16U)
#define DMA_STS_GF5_Msk                     (0x1U << DMA_STS_GF5_Pos)               /*!< 0x00010000 */
#define DMA_STS_GF5                         DMA_STS_GF5_Msk                         /*!< Channel 5 global event flag */
#define DMA_STS_FDTF5_Pos                   (17U)
#define DMA_STS_FDTF5_Msk                   (0x1U << DMA_STS_FDTF5_Pos)             /*!< 0x00020000 */
#define DMA_STS_FDTF5                       DMA_STS_FDTF5_Msk                       /*!< Channel 5 transfer complete event flag */
#define DMA_STS_HDTF5_Pos                   (18U)
#define DMA_STS_HDTF5_Msk                   (0x1U << DMA_STS_HDTF5_Pos)             /*!< 0x00040000 */
#define DMA_STS_HDTF5                       DMA_STS_HDTF5_Msk                       /*!< Channel 5 half transfer event flag */
#define DMA_STS_DTERRF5_Pos                 (19U)
#define DMA_STS_DTERRF5_Msk                 (0x1U << DMA_STS_DTERRF5_Pos)           /*!< 0x00080000 */
#define DMA_STS_DTERRF5                     DMA_STS_DTERRF5_Msk                     /*!< Channel 5 transfer error event flag */
#define DMA_STS_GF6_Pos                     (20U)
#define DMA_STS_GF6_Msk                     (0x1U << DMA_STS_GF6_Pos)               /*!< 0x00100000 */
#define DMA_STS_GF6                         DMA_STS_GF6_Msk                         /*!< Channel 6 global event flag */
#define DMA_STS_FDTF6_Pos                   (21U)
#define DMA_STS_FDTF6_Msk                   (0x1U << DMA_STS_FDTF6_Pos)             /*!< 0x00200000 */
#define DMA_STS_FDTF6                       DMA_STS_FDTF6_Msk                       /*!< Channel 6 transfer complete event flag */
#define DMA_STS_HDTF6_Pos                   (22U)
#define DMA_STS_HDTF6_Msk                   (0x1U << DMA_STS_HDTF6_Pos)             /*!< 0x00400000 */
#define DMA_STS_HDTF6                       DMA_STS_HDTF6_Msk                       /*!< Channel 6 half transfer event flag */
#define DMA_STS_DTERRF6_Pos                 (23U)
#define DMA_STS_DTERRF6_Msk                 (0x1U << DMA_STS_DTERRF6_Pos)           /*!< 0x00800000 */
#define DMA_STS_DTERRF6                     DMA_STS_DTERRF6_Msk                     /*!< Channel 6 transfer error event flag */
#define DMA_STS_GF7_Pos                     (24U)
#define DMA_STS_GF7_Msk                     (0x1U << DMA_STS_GF7_Pos)               /*!< 0x01000000 */
#define DMA_STS_GF7                         DMA_STS_GF7_Msk                         /*!< Channel 7 global event flag */
#define DMA_STS_FDTF7_Pos                   (25U)
#define DMA_STS_FDTF7_Msk                   (0x1U << DMA_STS_FDTF7_Pos)             /*!< 0x02000000 */
#define DMA_STS_FDTF7                       DMA_STS_FDTF7_Msk                       /*!< Channel 7 transfer complete event flag */
#define DMA_STS_HDTF7_Pos                   (26U)
#define DMA_STS_HDTF7_Msk                   (0x1U << DMA_STS_HDTF7_Pos)             /*!< 0x04000000 */
#define DMA_STS_HDTF7                       DMA_STS_HDTF7_Msk                       /*!< Channel 7 half transfer event flag */
#define DMA_STS_DTERRF7_Pos                 (27U)
#define DMA_STS_DTERRF7_Msk                 (0x1U << DMA_STS_DTERRF7_Pos)           /*!< 0x08000000 */
#define DMA_STS_DTERRF7                     DMA_STS_DTERRF7_Msk                     /*!< Channel 7 transfer error event flag */

/*******************  Bit definition for DMA_CLR register  ********************/
#define DMA_CLR_GFC1_Pos                    (0U)
#define DMA_CLR_GFC1_Msk                    (0x1U << DMA_CLR_GFC1_Pos)              /*!< 0x00000001 */
#define DMA_CLR_GFC1                        DMA_CLR_GFC1_Msk                        /*!< Channel 1 global interrupt flag clear */
#define DMA_CLR_FDTFC1_Pos                  (1U)
#define DMA_CLR_FDTFC1_Msk                  (0x1U << DMA_CLR_FDTFC1_Pos)            /*!< 0x00000002 */
#define DMA_CLR_FDTFC1                      DMA_CLR_FDTFC1_Msk                      /*!< Channel 1 transfer complete flag clear */
#define DMA_CLR_HDTFC1_Pos                  (2U)
#define DMA_CLR_HDTFC1_Msk                  (0x1U << DMA_CLR_HDTFC1_Pos)            /*!< 0x00000004 */
#define DMA_CLR_HDTFC1                      DMA_CLR_HDTFC1_Msk                      /*!< Channel 1 half transfer flag clear */
#define DMA_CLR_DTERRFC1_Pos                (3U)
#define DMA_CLR_DTERRFC1_Msk                (0x1U << DMA_CLR_DTERRFC1_Pos)          /*!< 0x00000008 */
#define DMA_CLR_DTERRFC1                    DMA_CLR_DTERRFC1_Msk                    /*!< Channel 1 data transfer error flag clear */
#define DMA_CLR_GFC2_Pos                    (4U)
#define DMA_CLR_GFC2_Msk                    (0x1U << DMA_CLR_GFC2_Pos)              /*!< 0x00000010 */
#define DMA_CLR_GFC2                        DMA_CLR_GFC2_Msk                        /*!< Channel 2 global interrupt flag clear */
#define DMA_CLR_FDTFC2_Pos                  (5U)
#define DMA_CLR_FDTFC2_Msk                  (0x1U << DMA_CLR_FDTFC2_Pos)            /*!< 0x00000020 */
#define DMA_CLR_FDTFC2                      DMA_CLR_FDTFC2_Msk                      /*!< Channel 2 transfer complete flag clear */
#define DMA_CLR_HDTFC2_Pos                  (6U)
#define DMA_CLR_HDTFC2_Msk                  (0x1U << DMA_CLR_HDTFC2_Pos)            /*!< 0x00000040 */
#define DMA_CLR_HDTFC2                      DMA_CLR_HDTFC2_Msk                      /*!< Channel 2 half transfer flag clear */
#define DMA_CLR_DTERRFC2_Pos                (7U)
#define DMA_CLR_DTERRFC2_Msk                (0x1U << DMA_CLR_DTERRFC2_Pos)          /*!< 0x00000080 */
#define DMA_CLR_DTERRFC2                    DMA_CLR_DTERRFC2_Msk                    /*!< Channel 2 data transfer error flag clear */
#define DMA_CLR_GFC3_Pos                    (8U)
#define DMA_CLR_GFC3_Msk                    (0x1U << DMA_CLR_GFC3_Pos)              /*!< 0x00000100 */
#define DMA_CLR_GFC3                        DMA_CLR_GFC3_Msk                        /*!< Channel 3 global interrupt flag clear */
#define DMA_CLR_FDTFC3_Pos                  (9U)
#define DMA_CLR_FDTFC3_Msk                  (0x1U << DMA_CLR_FDTFC3_Pos)            /*!< 0x00000200 */
#define DMA_CLR_FDTFC3                      DMA_CLR_FDTFC3_Msk                      /*!< Channel 3 transfer complete flag clear */
#define DMA_CLR_HDTFC3_Pos                  (10U)
#define DMA_CLR_HDTFC3_Msk                  (0x1U << DMA_CLR_HDTFC3_Pos)            /*!< 0x00000400 */
#define DMA_CLR_HDTFC3                      DMA_CLR_HDTFC3_Msk                      /*!< Channel 3 half transfer flag clear */
#define DMA_CLR_DTERRFC3_Pos                (11U)
#define DMA_CLR_DTERRFC3_Msk                (0x1U << DMA_CLR_DTERRFC3_Pos)          /*!< 0x00000800 */
#define DMA_CLR_DTERRFC3                    DMA_CLR_DTERRFC3_Msk                    /*!< Channel 3 data transfer error flag clear */
#define DMA_CLR_GFC4_Pos                    (12U)
#define DMA_CLR_GFC4_Msk                    (0x1U << DMA_CLR_GFC4_Pos)              /*!< 0x00001000 */
#define DMA_CLR_GFC4                        DMA_CLR_GFC4_Msk                        /*!< Channel 4 global interrupt flag clear */
#define DMA_CLR_FDTFC4_Pos                  (13U)
#define DMA_CLR_FDTFC4_Msk                  (0x1U << DMA_CLR_FDTFC4_Pos)            /*!< 0x00002000 */
#define DMA_CLR_FDTFC4                      DMA_CLR_FDTFC4_Msk                      /*!< Channel 4 transfer complete flag clear */
#define DMA_CLR_HDTFC4_Pos                  (14U)
#define DMA_CLR_HDTFC4_Msk                  (0x1U << DMA_CLR_HDTFC4_Pos)            /*!< 0x00004000 */
#define DMA_CLR_HDTFC4                      DMA_CLR_HDTFC4_Msk                      /*!< Channel 4 half transfer flag clear */
#define DMA_CLR_DTERRFC4_Pos                (15U)
#define DMA_CLR_DTERRFC4_Msk                (0x1U << DMA_CLR_DTERRFC4_Pos)          /*!< 0x00008000 */
#define DMA_CLR_DTERRFC4                    DMA_CLR_DTERRFC4_Msk                    /*!< Channel 4 data transfer error flag clear */
#define DMA_CLR_GFC5_Pos                    (16U)
#define DMA_CLR_GFC5_Msk                    (0x1U << DMA_CLR_GFC5_Pos)              /*!< 0x00010000 */
#define DMA_CLR_GFC5                        DMA_CLR_GFC5_Msk                        /*!< Channel 5 global interrupt flag clear */
#define DMA_CLR_FDTFC5_Pos                  (17U)
#define DMA_CLR_FDTFC5_Msk                  (0x1U << DMA_CLR_FDTFC5_Pos)            /*!< 0x00020000 */
#define DMA_CLR_FDTFC5                      DMA_CLR_FDTFC5_Msk                      /*!< Channel 5 transfer complete flag clear */
#define DMA_CLR_HDTFC5_Pos                  (18U)
#define DMA_CLR_HDTFC5_Msk                  (0x1U << DMA_CLR_HDTFC5_Pos)            /*!< 0x00040000 */
#define DMA_CLR_HDTFC5                      DMA_CLR_HDTFC5_Msk                      /*!< Channel 5 half transfer flag clear */
#define DMA_CLR_DTERRFC5_Pos                (19U)
#define DMA_CLR_DTERRFC5_Msk                (0x1U << DMA_CLR_DTERRFC5_Pos)          /*!< 0x00080000 */
#define DMA_CLR_DTERRFC5                    DMA_CLR_DTERRFC5_Msk                    /*!< Channel 5 data transfer error flag clear */
#define DMA_CLR_GFC6_Pos                    (20U)
#define DMA_CLR_GFC6_Msk                    (0x1U << DMA_CLR_GFC6_Pos)              /*!< 0x00100000 */
#define DMA_CLR_GFC6                        DMA_CLR_GFC6_Msk                        /*!< Channel 6 global interrupt flag clear */
#define DMA_CLR_FDTFC6_Pos                  (21U)
#define DMA_CLR_FDTFC6_Msk                  (0x1U << DMA_CLR_FDTFC6_Pos)            /*!< 0x00200000 */
#define DMA_CLR_FDTFC6                      DMA_CLR_FDTFC6_Msk                      /*!< Channel 6 transfer complete flag clear */
#define DMA_CLR_HDTFC6_Pos                  (22U)
#define DMA_CLR_HDTFC6_Msk                  (0x1U << DMA_CLR_HDTFC6_Pos)            /*!< 0x00400000 */
#define DMA_CLR_HDTFC6                      DMA_CLR_HDTFC6_Msk                      /*!< Channel 6 half transfer flag clear */
#define DMA_CLR_DTERRFC6_Pos                (23U)
#define DMA_CLR_DTERRFC6_Msk                (0x1U << DMA_CLR_DTERRFC6_Pos)          /*!< 0x00800000 */
#define DMA_CLR_DTERRFC6                    DMA_CLR_DTERRFC6_Msk                    /*!< Channel 6 data transfer error flag clear */
#define DMA_CLR_GFC7_Pos                    (24U)
#define DMA_CLR_GFC7_Msk                    (0x1U << DMA_CLR_GFC7_Pos)              /*!< 0x01000000 */
#define DMA_CLR_GFC7                        DMA_CLR_GFC7_Msk                        /*!< Channel 7 global interrupt flag clear */
#define DMA_CLR_FDTFC7_Pos                  (25U)
#define DMA_CLR_FDTFC7_Msk                  (0x1U << DMA_CLR_FDTFC7_Pos)            /*!< 0x02000000 */
#define DMA_CLR_FDTFC7                      DMA_CLR_FDTFC7_Msk                      /*!< Channel 7 transfer complete flag clear */
#define DMA_CLR_HDTFC7_Pos                  (26U)
#define DMA_CLR_HDTFC7_Msk                  (0x1U << DMA_CLR_HDTFC7_Pos)            /*!< 0x04000000 */
#define DMA_CLR_HDTFC7                      DMA_CLR_HDTFC7_Msk                      /*!< Channel 7 half transfer flag clear */
#define DMA_CLR_DTERRFC7_Pos                (27U)
#define DMA_CLR_DTERRFC7_Msk                (0x1U << DMA_CLR_DTERRFC7_Pos)          /*!< 0x08000000 */
#define DMA_CLR_DTERRFC7                    DMA_CLR_DTERRFC7_Msk                    /*!< Channel 7 data transfer error flag clear */

/******************  Bit definition for DMA_CCTRL register  *******************/
#define DMA_CCTRL_CHEN_Pos                  (0U)
#define DMA_CCTRL_CHEN_Msk                  (0x1U << DMA_CCTRL_CHEN_Pos)            /*!< 0x00000001 */
#define DMA_CCTRL_CHEN                      DMA_CCTRL_CHEN_Msk                      /*!< Channel enable */
#define DMA_CCTRL_FDTIEN_Pos                (1U)
#define DMA_CCTRL_FDTIEN_Msk                (0x1U << DMA_CCTRL_FDTIEN_Pos)          /*!< 0x00000002 */
#define DMA_CCTRL_FDTIEN                    DMA_CCTRL_FDTIEN_Msk                    /*!< Transfer complete interrupt enable */
#define DMA_CCTRL_HDTIEN_Pos                (2U)
#define DMA_CCTRL_HDTIEN_Msk                (0x1U << DMA_CCTRL_HDTIEN_Pos)          /*!< 0x00000004 */
#define DMA_CCTRL_HDTIEN                    DMA_CCTRL_HDTIEN_Msk                    /*!< Half-transfer interrupt enable */
#define DMA_CCTRL_DTERRIEN_Pos              (3U)
#define DMA_CCTRL_DTERRIEN_Msk              (0x1U << DMA_CCTRL_DTERRIEN_Pos)        /*!< 0x00000008 */
#define DMA_CCTRL_DTERRIEN                  DMA_CCTRL_DTERRIEN_Msk                  /*!< Data transfer error interrupt enable */
#define DMA_CCTRL_DTD_Pos                   (4U)
#define DMA_CCTRL_DTD_Msk                   (0x1U << DMA_CCTRL_DTD_Pos)             /*!< 0x00000010 */
#define DMA_CCTRL_DTD                       DMA_CCTRL_DTD_Msk                       /*!< Data transfer direction */
#define DMA_CCTRL_LM_Pos                    (5U)
#define DMA_CCTRL_LM_Msk                    (0x1U << DMA_CCTRL_LM_Pos)              /*!< 0x00000020 */
#define DMA_CCTRL_LM                        DMA_CCTRL_LM_Msk                        /*!< Circular mode */
#define DMA_CCTRL_PINCM_Pos                 (6U)
#define DMA_CCTRL_PINCM_Msk                 (0x1U << DMA_CCTRL_PINCM_Pos)           /*!< 0x00000040 */
#define DMA_CCTRL_PINCM                     DMA_CCTRL_PINCM_Msk                     /*!< Peripheral address increment mode */
#define DMA_CCTRL_MINCM_Pos                 (7U)
#define DMA_CCTRL_MINCM_Msk                 (0x1U << DMA_CCTRL_MINCM_Pos)           /*!< 0x00000080 */
#define DMA_CCTRL_MINCM                     DMA_CCTRL_MINCM_Msk                     /*!< Memory address increment mode */

#define DMA_CCTRL_PWIDTH_Pos                (8U)
#define DMA_CCTRL_PWIDTH_Msk                (0x3U << DMA_CCTRL_PWIDTH_Pos)          /*!< 0x00000300 */
#define DMA_CCTRL_PWIDTH                    DMA_CCTRL_PWIDTH_Msk                    /*!< PWIDTH[1:0] bits (Peripheral data bit width) */
#define DMA_CCTRL_PWIDTH_0                  (0x1U << DMA_CCTRL_PWIDTH_Pos)          /*!< 0x00000100 */
#define DMA_CCTRL_PWIDTH_1                  (0x2U << DMA_CCTRL_PWIDTH_Pos)          /*!< 0x00000200 */

#define DMA_CCTRL_MWIDTH_Pos                (10U)
#define DMA_CCTRL_MWIDTH_Msk                (0x3U << DMA_CCTRL_MWIDTH_Pos)          /*!< 0x00000C00 */
#define DMA_CCTRL_MWIDTH                    DMA_CCTRL_MWIDTH_Msk                    /*!< MWIDTH[1:0] bits (Memory data bit width) */
#define DMA_CCTRL_MWIDTH_0                  (0x1U << DMA_CCTRL_MWIDTH_Pos)          /*!< 0x00000400 */
#define DMA_CCTRL_MWIDTH_1                  (0x2U << DMA_CCTRL_MWIDTH_Pos)          /*!< 0x00000800 */

#define DMA_CCTRL_CHPL_Pos                  (12U)
#define DMA_CCTRL_CHPL_Msk                  (0x3U << DMA_CCTRL_CHPL_Pos)            /*!< 0x00003000 */
#define DMA_CCTRL_CHPL                      DMA_CCTRL_CHPL_Msk                      /*!< CHPL[1:0] bits(Channel priority level) */
#define DMA_CCTRL_CHPL_0                    (0x1U << DMA_CCTRL_CHPL_Pos)            /*!< 0x00001000 */
#define DMA_CCTRL_CHPL_1                    (0x2U << DMA_CCTRL_CHPL_Pos)            /*!< 0x00002000 */

#define DMA_CCTRL_M2M_Pos                   (14U)
#define DMA_CCTRL_M2M_Msk                   (0x1U << DMA_CCTRL_M2M_Pos)             /*!< 0x00004000 */
#define DMA_CCTRL_M2M                       DMA_CCTRL_M2M_Msk                       /*!< Memory to memory mode */

/******************  Bit definition for DMA_CDTCNT register  ******************/
#define DMA_CDTCNT_CNT_Pos                  (0U)
#define DMA_CDTCNT_CNT_Msk                  (0xFFFFU << DMA_CDTCNT_CNT_Pos)         /*!< 0x0000FFFF */
#define DMA_CDTCNT_CNT                      DMA_CDTCNT_CNT_Msk                      /*!< Number of data to transfer */

/******************  Bit definition for DMA_CPADDR register  ******************/
#define DMA_CPADDR_PADDR_Pos                (0U)
#define DMA_CPADDR_PADDR_Msk                (0xFFFFFFFFU << DMA_CPADDR_PADDR_Pos)   /*!< 0xFFFFFFFF */
#define DMA_CPADDR_PADDR                    DMA_CPADDR_PADDR_Msk                    /*!< Peripheral base address */

/******************  Bit definition for DMA_CMADDR register  ******************/
#define DMA_CMADDR_MADDR_Pos                (0U)
#define DMA_CMADDR_MADDR_Msk                (0xFFFFFFFFU << DMA_CMADDR_MADDR_Pos)   /*!< 0xFFFFFFFF */
#define DMA_CMADDR_MADDR                    DMA_CMADDR_MADDR_Msk                    /*!< Memory base address */

/*****************  Bit definition for DMA_SRC_SEL0 register  *****************/
#define DMA_SRC_SEL0_CH1_SRC_Pos            (0U)
#define DMA_SRC_SEL0_CH1_SRC_Msk            (0xFFU << DMA_SRC_SEL0_CH1_SRC_Pos)     /*!< 0x000000FF */
#define DMA_SRC_SEL0_CH1_SRC                DMA_SRC_SEL0_CH1_SRC_Msk                /*!< CH1 source select */
#define DMA_SRC_SEL0_CH2_SRC_Pos            (8U)
#define DMA_SRC_SEL0_CH2_SRC_Msk            (0xFFU << DMA_SRC_SEL0_CH2_SRC_Pos)     /*!< 0x0000FF00 */
#define DMA_SRC_SEL0_CH2_SRC                DMA_SRC_SEL0_CH2_SRC_Msk                /*!< CH2 source select */
#define DMA_SRC_SEL0_CH3_SRC_Pos            (16U)
#define DMA_SRC_SEL0_CH3_SRC_Msk            (0xFFU << DMA_SRC_SEL0_CH3_SRC_Pos)     /*!< 0x00FF0000 */
#define DMA_SRC_SEL0_CH3_SRC                DMA_SRC_SEL0_CH3_SRC_Msk                /*!< CH3 source select */
#define DMA_SRC_SEL0_CH4_SRC_Pos            (24U)
#define DMA_SRC_SEL0_CH4_SRC_Msk            (0xFFU << DMA_SRC_SEL0_CH4_SRC_Pos)     /*!< 0xFF000000 */
#define DMA_SRC_SEL0_CH4_SRC                DMA_SRC_SEL0_CH4_SRC_Msk                /*!< CH4 source select */

/*****************  Bit definition for DMA_SRC_SEL1 register  *****************/
#define DMA_SRC_SEL1_CH5_SRC_Pos            (0U)
#define DMA_SRC_SEL1_CH5_SRC_Msk            (0xFFU << DMA_SRC_SEL1_CH5_SRC_Pos)     /*!< 0x000000FF */
#define DMA_SRC_SEL1_CH5_SRC                DMA_SRC_SEL1_CH5_SRC_Msk                /*!< CH5 source select */
#define DMA_SRC_SEL1_CH6_SRC_Pos            (8U)
#define DMA_SRC_SEL1_CH6_SRC_Msk            (0xFFU << DMA_SRC_SEL1_CH6_SRC_Pos)     /*!< 0x0000FF00 */
#define DMA_SRC_SEL1_CH6_SRC                DMA_SRC_SEL1_CH6_SRC_Msk                /*!< CH6 source select */
#define DMA_SRC_SEL1_CH7_SRC_Pos            (16U)
#define DMA_SRC_SEL1_CH7_SRC_Msk            (0xFFU << DMA_SRC_SEL1_CH7_SRC_Pos)     /*!< 0x00FF0000 */
#define DMA_SRC_SEL1_CH7_SRC                DMA_SRC_SEL1_CH7_SRC_Msk                /*!< CH7 source select */
#define DMA_SRC_SEL1_DMA_FLEX_EN_Pos        (24U)
#define DMA_SRC_SEL1_DMA_FLEX_EN_Msk        (0x1U << DMA_SRC_SEL1_DMA_FLEX_EN_Pos)  /*!< 0x01000000 */
#define DMA_SRC_SEL1_DMA_FLEX_EN            DMA_SRC_SEL1_DMA_FLEX_EN_Msk            /*!< DMA flexible request mapping enable */

/******************************************************************************/
/*                                                                            */
/*                         CRC calculation unit (CRC)                         */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for CRC_DT register  ********************/
#define CRC_DT_DT_Pos                       (0U)
#define CRC_DT_DT_Msk                       (0xFFFFFFFFU << CRC_DT_DT_Pos)          /*!< 0xFFFFFFFF */
#define CRC_DT_DT                           CRC_DT_DT_Msk                           /*!< Data register bits */

/*******************  Bit definition for CRC_CDT register  ********************/
#define CRC_CDT_CDT_Pos                     (0U)
#define CRC_CDT_CDT_Msk                     (0xFFU << CRC_CDT_CDT_Pos)              /*!< 0x000000FF */
#define CRC_CDT_CDT                         CRC_CDT_CDT_Msk                         /*!< General-purpose 8-bit data register bits */

/*******************  Bit definition for CRC_CTRL register  *******************/
#define CRC_CTRL_RST_Pos                    (0U)
#define CRC_CTRL_RST_Msk                    (0x1U << CRC_CTRL_RST_Pos)              /*!< 0x00000001 */
#define CRC_CTRL_RST                        CRC_CTRL_RST_Msk                        /*!< Reset CRC calculation unit */

/*!< REVID configuration */
#define CRC_CTRL_REVID_Pos                  (5U)
#define CRC_CTRL_REVID_Msk                  (0x3U << CRC_CTRL_REVID_Pos)            /*!< 0x00000060 */
#define CRC_CTRL_REVID                      CRC_CTRL_REVID_Msk                      /*!< REVID[1:0] bits (Reverse input data) */
#define CRC_CTRL_REVID_0                    (0x1U << CRC_CTRL_REVID_Pos)            /*!< 0x00000020 */
#define CRC_CTRL_REVID_1                    (0x2U << CRC_CTRL_REVID_Pos)            /*!< 0x00000040 */

#define CRC_CTRL_REVID_NOREV                0x00000000U                             /*!< No effect */
#define CRC_CTRL_REVID_BYTEREV_Pos          (5U)
#define CRC_CTRL_REVID_BYTEREV_Msk          (0x1U << CRC_CTRL_REVID_BYTEREV_Pos)    /*!< 0x00000020 */
#define CRC_CTRL_REVID_BYTEREV              CRC_CTRL_REVID_BYTEREV_Msk              /*!< Byte reverse */
#define CRC_CTRL_REVID_HALFREV_Pos          (6U)
#define CRC_CTRL_REVID_HALFREV_Msk          (0x1U << CRC_CTRL_REVID_HALFREV_Pos)    /*!< 0x00000040 */
#define CRC_CTRL_REVID_HALFREV              CRC_CTRL_REVID_HALFREV_Msk              /*!< Half-word reverse */
#define CRC_CTRL_REVID_WORDREV_Pos          (5U)
#define CRC_CTRL_REVID_WORDREV_Msk          (0x3U << CRC_CTRL_REVID_WORDREV_Pos)    /*!< 0x00000060 */
#define CRC_CTRL_REVID_WORDREV              CRC_CTRL_REVID_WORDREV_Msk              /*!< Word reverse */

#define CRC_CTRL_REVOD_Pos                  (7U)
#define CRC_CTRL_REVOD_Msk                  (0x1U << CRC_CTRL_REVOD_Pos)            /*!< 0x00000080 */
#define CRC_CTRL_REVOD                      CRC_CTRL_REVOD_Msk                      /*!< Reverse output data */

/*******************  Bit definition for CRC_IDT register  ********************/
#define CRC_IDT_IDT_Pos                     (0U)
#define CRC_IDT_IDT_Msk                     (0xFFFFFFFFU << CRC_IDT_IDT_Pos)        /*!< 0xFFFFFFFF */
#define CRC_IDT_IDT                         CRC_IDT_IDT_Msk                         /*!< Initialization data register */

/******************************************************************************/
/*                                                                            */
/*                  Inter-integrated circuit interface (I2C)                  */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for I2C_CTRL1 register  *******************/
#define I2C_CTRL1_I2CEN_Pos                 (0U)
#define I2C_CTRL1_I2CEN_Msk                 (0x1U << I2C_CTRL1_I2CEN_Pos)           /*!< 0x00000001 */
#define I2C_CTRL1_I2CEN                     I2C_CTRL1_I2CEN_Msk                     /*!< I2C peripheral enable */
#define I2C_CTRL1_PERMODE_Pos               (1U)
#define I2C_CTRL1_PERMODE_Msk               (0x1U << I2C_CTRL1_PERMODE_Pos)         /*!< 0x00000002 */
#define I2C_CTRL1_PERMODE                   I2C_CTRL1_PERMODE_Msk                   /*!< I2C peripheral mode */
#define I2C_CTRL1_SMBMODE_Pos               (3U)
#define I2C_CTRL1_SMBMODE_Msk               (0x1U << I2C_CTRL1_SMBMODE_Pos)         /*!< 0x00000008 */
#define I2C_CTRL1_SMBMODE                   I2C_CTRL1_SMBMODE_Msk                   /*!< SMBus device mode */
#define I2C_CTRL1_ARPEN_Pos                 (4U)
#define I2C_CTRL1_ARPEN_Msk                 (0x1U << I2C_CTRL1_ARPEN_Pos)           /*!< 0x00000010 */
#define I2C_CTRL1_ARPEN                     I2C_CTRL1_ARPEN_Msk                     /*!< SMBus address resolution protocol enable */
#define I2C_CTRL1_PECEN_Pos                 (5U)
#define I2C_CTRL1_PECEN_Msk                 (0x1U << I2C_CTRL1_PECEN_Pos)           /*!< 0x00000020 */
#define I2C_CTRL1_PECEN                     I2C_CTRL1_PECEN_Msk                     /*!< PEC calculation enable */
#define I2C_CTRL1_GCAEN_Pos                 (6U)
#define I2C_CTRL1_GCAEN_Msk                 (0x1U << I2C_CTRL1_GCAEN_Pos)           /*!< 0x00000040 */
#define I2C_CTRL1_GCAEN                     I2C_CTRL1_GCAEN_Msk                     /*!< General call address enable */
#define I2C_CTRL1_STRETCH_Pos               (7U)
#define I2C_CTRL1_STRETCH_Msk               (0x1U << I2C_CTRL1_STRETCH_Pos)         /*!< 0x00000080 */
#define I2C_CTRL1_STRETCH                   I2C_CTRL1_STRETCH_Msk                   /*!< Clock stretching mode */
#define I2C_CTRL1_GENSTART_Pos              (8U)
#define I2C_CTRL1_GENSTART_Msk              (0x1U << I2C_CTRL1_GENSTART_Pos)        /*!< 0x00000100 */
#define I2C_CTRL1_GENSTART                  I2C_CTRL1_GENSTART_Msk                  /*!< Generate start condition */
#define I2C_CTRL1_GENSTOP_Pos               (9U)
#define I2C_CTRL1_GENSTOP_Msk               (0x1U << I2C_CTRL1_GENSTOP_Pos)         /*!< 0x00000200 */
#define I2C_CTRL1_GENSTOP                   I2C_CTRL1_GENSTOP_Msk                   /*!< Generate stop condition */
#define I2C_CTRL1_ACKEN_Pos                 (10U)
#define I2C_CTRL1_ACKEN_Msk                 (0x1U << I2C_CTRL1_ACKEN_Pos)           /*!< 0x00000400 */
#define I2C_CTRL1_ACKEN                     I2C_CTRL1_ACKEN_Msk                     /*!< Acknowledge enable */
#define I2C_CTRL1_MACKCTRL_Pos              (11U)
#define I2C_CTRL1_MACKCTRL_Msk              (0x1U << I2C_CTRL1_MACKCTRL_Pos)        /*!< 0x00000800 */
#define I2C_CTRL1_MACKCTRL                  I2C_CTRL1_MACKCTRL_Msk                  /*!< Master receive mode acknowledge control */
#define I2C_CTRL1_PECTEN_Pos                (12U)
#define I2C_CTRL1_PECTEN_Msk                (0x1U << I2C_CTRL1_PECTEN_Pos)          /*!< 0x00001000 */
#define I2C_CTRL1_PECTEN                    I2C_CTRL1_PECTEN_Msk                    /*!< Request PEC transfer enable */
#define I2C_CTRL1_SMBALERT_Pos              (13U)
#define I2C_CTRL1_SMBALERT_Msk              (0x1U << I2C_CTRL1_SMBALERT_Pos)        /*!< 0x00002000 */
#define I2C_CTRL1_SMBALERT                  I2C_CTRL1_SMBALERT_Msk                  /*!< SMBus alert pin set */
#define I2C_CTRL1_RESET_Pos                 (15U)
#define I2C_CTRL1_RESET_Msk                 (0x1U << I2C_CTRL1_RESET_Pos)           /*!< 0x00008000 */
#define I2C_CTRL1_RESET                     I2C_CTRL1_RESET_Msk                     /*!< I2C peripheral reset */

/******************  Bit definition for I2C_CTRL2 register  *******************/
/*!< CLKFREQ configuration */
#define I2C_CTRL2_CLKFREQ_Pos               (0U)
#define I2C_CTRL2_CLKFREQ_Msk               (0xFFU << I2C_CTRL2_CLKFREQ_Pos)        /*!< 0x000000FF */
#define I2C_CTRL2_CLKFREQ                   I2C_CTRL2_CLKFREQ_Msk                   /*!< CLKFREQ[7:0] bits (I2C input clock frequency) */
#define I2C_CTRL2_CLKFREQ_0                 (0x01U << I2C_CTRL2_CLKFREQ_Pos)        /*!< 0x00000001 */
#define I2C_CTRL2_CLKFREQ_1                 (0x02U << I2C_CTRL2_CLKFREQ_Pos)        /*!< 0x00000002 */
#define I2C_CTRL2_CLKFREQ_2                 (0x04U << I2C_CTRL2_CLKFREQ_Pos)        /*!< 0x00000004 */
#define I2C_CTRL2_CLKFREQ_3                 (0x08U << I2C_CTRL2_CLKFREQ_Pos)        /*!< 0x00000008 */
#define I2C_CTRL2_CLKFREQ_4                 (0x10U << I2C_CTRL2_CLKFREQ_Pos)        /*!< 0x00000010 */
#define I2C_CTRL2_CLKFREQ_5                 (0x20U << I2C_CTRL2_CLKFREQ_Pos)        /*!< 0x00000020 */
#define I2C_CTRL2_CLKFREQ_6                 (0x40U << I2C_CTRL2_CLKFREQ_Pos)        /*!< 0x00000040 */
#define I2C_CTRL2_CLKFREQ_7                 (0x80U << I2C_CTRL2_CLKFREQ_Pos)        /*!< 0x00000080 */

#define I2C_CTRL2_ERRIEN_Pos                (8U)
#define I2C_CTRL2_ERRIEN_Msk                (0x1U << I2C_CTRL2_ERRIEN_Pos)          /*!< 0x00000100 */
#define I2C_CTRL2_ERRIEN                    I2C_CTRL2_ERRIEN_Msk                    /*!< Error interrupt enable */
#define I2C_CTRL2_EVTIEN_Pos                (9U)
#define I2C_CTRL2_EVTIEN_Msk                (0x1U << I2C_CTRL2_EVTIEN_Pos)          /*!< 0x00000200 */
#define I2C_CTRL2_EVTIEN                    I2C_CTRL2_EVTIEN_Msk                    /*!< Event interrupt enable */
#define I2C_CTRL2_DATAIEN_Pos               (10U)
#define I2C_CTRL2_DATAIEN_Msk               (0x1U << I2C_CTRL2_DATAIEN_Pos)         /*!< 0x00000400 */
#define I2C_CTRL2_DATAIEN                   I2C_CTRL2_DATAIEN_Msk                   /*!< Data transfer interrupt enable */
#define I2C_CTRL2_DMAEN_Pos                 (11U)
#define I2C_CTRL2_DMAEN_Msk                 (0x1U << I2C_CTRL2_DMAEN_Pos)           /*!< 0x00000800 */
#define I2C_CTRL2_DMAEN                     I2C_CTRL2_DMAEN_Msk                     /*!< DMA transfer enable */
#define I2C_CTRL2_DMAEND_Pos                (12U)
#define I2C_CTRL2_DMAEND_Msk                (0x1U << I2C_CTRL2_DMAEND_Pos)          /*!< 0x00001000 */
#define I2C_CTRL2_DMAEND                    I2C_CTRL2_DMAEND_Msk                    /*!< End of DMA transfer */

/******************  Bit definition for I2C_OADDR1 register  ******************/
/*!< ADDR1 configuration */
#define I2C_OADDR1_ADDR1_1_7                0x000000FEU                             /*!< Interface Address */
#define I2C_OADDR1_ADDR1_8_9                0x00000300U                             /*!< Interface Address */

#define I2C_OADDR1_ADDR1_0_Pos              (0U)                               
#define I2C_OADDR1_ADDR1_0_Msk              (0x1U << I2C_OADDR1_ADDR1_0_Pos)        /*!< 0x00000001 */
#define I2C_OADDR1_ADDR1_0                  I2C_OADDR1_ADDR1_0_Msk                  /*!< Bit 0 */
#define I2C_OADDR1_ADDR1_1_Pos              (1U)                               
#define I2C_OADDR1_ADDR1_1_Msk              (0x1U << I2C_OADDR1_ADDR1_1_Pos)        /*!< 0x00000002 */
#define I2C_OADDR1_ADDR1_1                  I2C_OADDR1_ADDR1_1_Msk                  /*!< Bit 1 */
#define I2C_OADDR1_ADDR1_2_Pos              (2U)                               
#define I2C_OADDR1_ADDR1_2_Msk              (0x1U << I2C_OADDR1_ADDR1_2_Pos)        /*!< 0x00000004 */
#define I2C_OADDR1_ADDR1_2                  I2C_OADDR1_ADDR1_2_Msk                  /*!< Bit 2 */
#define I2C_OADDR1_ADDR1_3_Pos              (3U)                               
#define I2C_OADDR1_ADDR1_3_Msk              (0x1U << I2C_OADDR1_ADDR1_3_Pos)        /*!< 0x00000008 */
#define I2C_OADDR1_ADDR1_3                  I2C_OADDR1_ADDR1_3_Msk                  /*!< Bit 3 */
#define I2C_OADDR1_ADDR1_4_Pos              (4U)                               
#define I2C_OADDR1_ADDR1_4_Msk              (0x1U << I2C_OADDR1_ADDR1_4_Pos)        /*!< 0x00000010 */
#define I2C_OADDR1_ADDR1_4                  I2C_OADDR1_ADDR1_4_Msk                  /*!< Bit 4 */
#define I2C_OADDR1_ADDR1_5_Pos              (5U)                               
#define I2C_OADDR1_ADDR1_5_Msk              (0x1U << I2C_OADDR1_ADDR1_5_Pos)        /*!< 0x00000020 */
#define I2C_OADDR1_ADDR1_5                  I2C_OADDR1_ADDR1_5_Msk                  /*!< Bit 5 */
#define I2C_OADDR1_ADDR1_6_Pos              (6U)                               
#define I2C_OADDR1_ADDR1_6_Msk              (0x1U << I2C_OADDR1_ADDR1_6_Pos)        /*!< 0x00000040 */
#define I2C_OADDR1_ADDR1_6                  I2C_OADDR1_ADDR1_6_Msk                  /*!< Bit 6 */
#define I2C_OADDR1_ADDR1_7_Pos              (7U)                               
#define I2C_OADDR1_ADDR1_7_Msk              (0x1U << I2C_OADDR1_ADDR1_7_Pos)        /*!< 0x00000080 */
#define I2C_OADDR1_ADDR1_7                  I2C_OADDR1_ADDR1_7_Msk                  /*!< Bit 7 */
#define I2C_OADDR1_ADDR1_8_Pos              (8U)                               
#define I2C_OADDR1_ADDR1_8_Msk              (0x1U << I2C_OADDR1_ADDR1_8_Pos)        /*!< 0x00000100 */
#define I2C_OADDR1_ADDR1_8                  I2C_OADDR1_ADDR1_8_Msk                  /*!< Bit 8 */
#define I2C_OADDR1_ADDR1_9_Pos              (9U)                               
#define I2C_OADDR1_ADDR1_9_Msk              (0x1U << I2C_OADDR1_ADDR1_9_Pos)        /*!< 0x00000200 */
#define I2C_OADDR1_ADDR1_9                  I2C_OADDR1_ADDR1_9_Msk                  /*!< Bit 9 */

#define I2C_OADDR1_ADDR1MODE_Pos            (15U)
#define I2C_OADDR1_ADDR1MODE_Msk            (0x1U << I2C_OADDR1_ADDR1MODE_Pos)      /*!< 0x00008000 */
#define I2C_OADDR1_ADDR1MODE                I2C_OADDR1_ADDR1MODE_Msk                /*!< Address mode */

/******************  Bit definition for I2C_OADDR2 register  ******************/
#define I2C_OADDR2_ADDR2EN_Pos              (0U)
#define I2C_OADDR2_ADDR2EN_Msk              (0x1U << I2C_OADDR2_ADDR2EN_Pos)        /*!< 0x00000001 */
#define I2C_OADDR2_ADDR2EN                  I2C_OADDR2_ADDR2EN_Msk                  /*!< Own address 2 enable */
#define I2C_OADDR2_ADDR2_Pos                (1U)
#define I2C_OADDR2_ADDR2_Msk                (0x7FU << I2C_OADDR2_ADDR2_Pos)         /*!< 0x000000FE */
#define I2C_OADDR2_ADDR2                    I2C_OADDR2_ADDR2_Msk                    /*!< Own address 2 */

/********************  Bit definition for I2C_DT register  ********************/
#define I2C_DT_DT_Pos                       (0U)
#define I2C_DT_DT_Msk                       (0xFFU << I2C_DT_DT_Pos)                /*!< 0x000000FF */
#define I2C_DT_DT                           I2C_DT_DT_Msk                           /*!< This field is used to store data received or to be transferred */

/*******************  Bit definition for I2C_STS1 register  *******************/
#define I2C_STS1_STARTF_Pos                 (0U)
#define I2C_STS1_STARTF_Msk                 (0x1U << I2C_STS1_STARTF_Pos)           /*!< 0x00000001 */
#define I2C_STS1_STARTF                     I2C_STS1_STARTF_Msk                     /*!< Start condition generation complete flag */
#define I2C_STS1_ADDR7F_Pos                 (1U)
#define I2C_STS1_ADDR7F_Msk                 (0x1U << I2C_STS1_ADDR7F_Pos)           /*!< 0x00000002 */
#define I2C_STS1_ADDR7F                     I2C_STS1_ADDR7F_Msk                     /*!< 0 ~ 7 bit address match flag */
#define I2C_STS1_TDC_Pos                    (2U)
#define I2C_STS1_TDC_Msk                    (0x1U << I2C_STS1_TDC_Pos)              /*!< 0x00000004 */
#define I2C_STS1_TDC                        I2C_STS1_TDC_Msk                        /*!< Data transfer complete flag */
#define I2C_STS1_ADDRHF_Pos                 (3U)
#define I2C_STS1_ADDRHF_Msk                 (0x1U << I2C_STS1_ADDRHF_Pos)           /*!< 0x00000008 */
#define I2C_STS1_ADDRHF                     I2C_STS1_ADDRHF_Msk                     /*!< Master 9 ~ 8 bit address head match flag */
#define I2C_STS1_STOPF_Pos                  (4U)
#define I2C_STS1_STOPF_Msk                  (0x1U << I2C_STS1_STOPF_Pos)            /*!< 0x00000010 */
#define I2C_STS1_STOPF                      I2C_STS1_STOPF_Msk                      /*!< Stop condition generation complete flag */
#define I2C_STS1_RDBF_Pos                   (6U)
#define I2C_STS1_RDBF_Msk                   (0x1U << I2C_STS1_RDBF_Pos)             /*!< 0x00000040 */
#define I2C_STS1_RDBF                       I2C_STS1_RDBF_Msk                       /*!< Receive data buffer full flag */
#define I2C_STS1_TDBE_Pos                   (7U)
#define I2C_STS1_TDBE_Msk                   (0x1U << I2C_STS1_TDBE_Pos)             /*!< 0x00000080 */
#define I2C_STS1_TDBE                       I2C_STS1_TDBE_Msk                       /*!< Transmit data buffer empty flag */
#define I2C_STS1_BUSERR_Pos                 (8U)
#define I2C_STS1_BUSERR_Msk                 (0x1U << I2C_STS1_BUSERR_Pos)           /*!< 0x00000100 */
#define I2C_STS1_BUSERR                     I2C_STS1_BUSERR_Msk                     /*!< Bus error flag */
#define I2C_STS1_ARLOST_Pos                 (9U)
#define I2C_STS1_ARLOST_Msk                 (0x1U << I2C_STS1_ARLOST_Pos)           /*!< 0x00000200 */
#define I2C_STS1_ARLOST                     I2C_STS1_ARLOST_Msk                     /*!< Arbitration lost flag */
#define I2C_STS1_ACKFAIL_Pos                (10U)
#define I2C_STS1_ACKFAIL_Msk                (0x1U << I2C_STS1_ACKFAIL_Pos)          /*!< 0x00000400 */
#define I2C_STS1_ACKFAIL                    I2C_STS1_ACKFAIL_Msk                    /*!< Acknowledge failure flag */
#define I2C_STS1_OUF_Pos                    (11U)
#define I2C_STS1_OUF_Msk                    (0x1U << I2C_STS1_OUF_Pos)              /*!< 0x00000800 */
#define I2C_STS1_OUF                        I2C_STS1_OUF_Msk                        /*!< Overload / underload flag */
#define I2C_STS1_PECERR_Pos                 (12U)
#define I2C_STS1_PECERR_Msk                 (0x1U << I2C_STS1_PECERR_Pos)           /*!< 0x00001000 */
#define I2C_STS1_PECERR                     I2C_STS1_PECERR_Msk                     /*!< PEC receive error flag */
#define I2C_STS1_TMOUT_Pos                  (14U)
#define I2C_STS1_TMOUT_Msk                  (0x1U << I2C_STS1_TMOUT_Pos)            /*!< 0x00004000 */
#define I2C_STS1_TMOUT                      I2C_STS1_TMOUT_Msk                      /*!< SMBus timeout flag */
#define I2C_STS1_ALERTF_Pos                 (15U)
#define I2C_STS1_ALERTF_Msk                 (0x1U << I2C_STS1_ALERTF_Pos)           /*!< 0x00008000 */
#define I2C_STS1_ALERTF                     I2C_STS1_ALERTF_Msk                     /*!< SMBus alert flag */

/*******************  Bit definition for I2C_STS2 register  *******************/
#define I2C_STS2_TRMODE_Pos                 (0U)
#define I2C_STS2_TRMODE_Msk                 (0x1U << I2C_STS2_TRMODE_Pos)           /*!< 0x00000001 */
#define I2C_STS2_TRMODE                     I2C_STS2_TRMODE_Msk                     /*!< Transmission mode */
#define I2C_STS2_BUSYF_Pos                  (1U)
#define I2C_STS2_BUSYF_Msk                  (0x1U << I2C_STS2_BUSYF_Pos)            /*!< 0x00000002 */
#define I2C_STS2_BUSYF                      I2C_STS2_BUSYF_Msk                      /*!< Bus busy flag transmission mode */
#define I2C_STS2_DIRF_Pos                   (2U)
#define I2C_STS2_DIRF_Msk                   (0x1U << I2C_STS2_DIRF_Pos)             /*!< 0x00000004 */
#define I2C_STS2_DIRF                       I2C_STS2_DIRF_Msk                       /*!< Transmission direction flag */
#define I2C_STS2_GCADDRF_Pos                (4U)
#define I2C_STS2_GCADDRF_Msk                (0x1U << I2C_STS2_GCADDRF_Pos)          /*!< 0x00000010 */
#define I2C_STS2_GCADDRF                    I2C_STS2_GCADDRF_Msk                    /*!< General call address reception flag */
#define I2C_STS2_DEVADDRF_Pos               (5U)
#define I2C_STS2_DEVADDRF_Msk               (0x1U << I2C_STS2_DEVADDRF_Pos)         /*!< 0x00000020 */
#define I2C_STS2_DEVADDRF                   I2C_STS2_DEVADDRF_Msk                   /*!< SMBus device address reception flag */
#define I2C_STS2_HOSTADDRF_Pos              (6U)
#define I2C_STS2_HOSTADDRF_Msk              (0x1U << I2C_STS2_HOSTADDRF_Pos)        /*!< 0x00000040 */
#define I2C_STS2_HOSTADDRF                  I2C_STS2_HOSTADDRF_Msk                  /*!< SMBus host address reception flag */
#define I2C_STS2_ADDR2F_Pos                 (7U)
#define I2C_STS2_ADDR2F_Msk                 (0x1U << I2C_STS2_ADDR2F_Pos)           /*!< 0x00000080 */
#define I2C_STS2_ADDR2F                     I2C_STS2_ADDR2F_Msk                     /*!< Received address 2 flag */
#define I2C_STS2_PECVAL_Pos                 (8U)
#define I2C_STS2_PECVAL_Msk                 (0xFFU << I2C_STS2_PECVAL_Pos)          /*!< 0x0000FF00 */
#define I2C_STS2_PECVAL                     I2C_STS2_PECVAL_Msk                     /*!< PEC value */

/*****************  Bit definition for I2C_CLKCTRL register  ******************/
#define I2C_CLKCTRL_SPEED_Pos               (0U)
#define I2C_CLKCTRL_SPEED_Msk               (0xFFFU << I2C_CLKCTRL_SPEED_Pos)       /*!< 0x00000FFF */
#define I2C_CLKCTRL_SPEED                   I2C_CLKCTRL_SPEED_Msk                   /*!< I2C bus speed config */
#define I2C_CLKCTRL_DUTYMODE_Pos            (14U)
#define I2C_CLKCTRL_DUTYMODE_Msk            (0x1U << I2C_CLKCTRL_DUTYMODE_Pos)      /*!< 0x00004000 */
#define I2C_CLKCTRL_DUTYMODE                I2C_CLKCTRL_DUTYMODE_Msk                /*!< Fast mode duty cycle */
#define I2C_CLKCTRL_SPEEDMODE_Pos           (15U)
#define I2C_CLKCTRL_SPEEDMODE_Msk           (0x1U << I2C_CLKCTRL_SPEEDMODE_Pos)     /*!< 0x00008000 */
#define I2C_CLKCTRL_SPEEDMODE               I2C_CLKCTRL_SPEEDMODE_Msk               /*!< Speed mode selection */

/******************  Bit definition for I2C_TMRISE register  ******************/
#define I2C_TMRISE_RISETIME_Pos             (0U)
#define I2C_TMRISE_RISETIME_Msk             (0x3FU << I2C_TMRISE_RISETIME_Pos)      /*!< 0x0000003F */
#define I2C_TMRISE_RISETIME                 I2C_TMRISE_RISETIME_Msk                 /*!< I2C bus rise time */

/******************************************************************************/
/*                                                                            */
/*      Universal synchronous/asynchronous receiver/transmitter (USART)       */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for USART_STS register  *******************/
#define USART_STS_PERR_Pos                  (0U)
#define USART_STS_PERR_Msk                  (0x1U << USART_STS_PERR_Pos)            /*!< 0x00000001 */
#define USART_STS_PERR                      USART_STS_PERR_Msk                      /*!< Parity error */
#define USART_STS_FERR_Pos                  (1U)
#define USART_STS_FERR_Msk                  (0x1U << USART_STS_FERR_Pos)            /*!< 0x00000002 */
#define USART_STS_FERR                      USART_STS_FERR_Msk                      /*!< Framing error */
#define USART_STS_NERR_Pos                  (2U)
#define USART_STS_NERR_Msk                  (0x1U << USART_STS_NERR_Pos)            /*!< 0x00000004 */
#define USART_STS_NERR                      USART_STS_NERR_Msk                      /*!< Noise error */
#define USART_STS_ROERR_Pos                 (3U)
#define USART_STS_ROERR_Msk                 (0x1U << USART_STS_ROERR_Pos)           /*!< 0x00000008 */
#define USART_STS_ROERR                     USART_STS_ROERR_Msk                     /*!< Receiver overflow error */
#define USART_STS_IDLEF_Pos                 (4U)
#define USART_STS_IDLEF_Msk                 (0x1U << USART_STS_IDLEF_Pos)           /*!< 0x00000010 */
#define USART_STS_IDLEF                     USART_STS_IDLEF_Msk                     /*!< Idle flag */
#define USART_STS_RDBF_Pos                  (5U)
#define USART_STS_RDBF_Msk                  (0x1U << USART_STS_RDBF_Pos)            /*!< 0x00000020 */
#define USART_STS_RDBF                      USART_STS_RDBF_Msk                      /*!< Receive data buffer full */
#define USART_STS_TDC_Pos                   (6U)
#define USART_STS_TDC_Msk                   (0x1U << USART_STS_TDC_Pos)             /*!< 0x00000040 */
#define USART_STS_TDC                       USART_STS_TDC_Msk                       /*!< Transmit data complete */
#define USART_STS_TDBE_Pos                  (7U)
#define USART_STS_TDBE_Msk                  (0x1U << USART_STS_TDBE_Pos)            /*!< 0x00000080 */
#define USART_STS_TDBE                      USART_STS_TDBE_Msk                      /*!< Transmit data buffer empty */
#define USART_STS_BFF_Pos                   (8U)
#define USART_STS_BFF_Msk                   (0x1U << USART_STS_BFF_Pos)             /*!< 0x00000100 */
#define USART_STS_BFF                       USART_STS_BFF_Msk                       /*!< Break frame flag */
#define USART_STS_CTSCF_Pos                 (9U)
#define USART_STS_CTSCF_Msk                 (0x1U << USART_STS_CTSCF_Pos)           /*!< 0x00000200 */
#define USART_STS_CTSCF                     USART_STS_CTSCF_Msk                     /*!< CTS change flag */

/*******************  Bit definition for USART_DT register  *******************/
#define USART_DT_DT_Pos                     (0U)
#define USART_DT_DT_Msk                     (0x1FFU << USART_DT_DT_Pos)             /*!< 0x000001FF */
#define USART_DT_DT                         USART_DT_DT_Msk                         /*!< Data value */

/*****************  Bit definition for USART_BAUDR register  ******************/
#define USART_BAUDR_DIV_Pos                 (0U)
#define USART_BAUDR_DIV_Msk                 (0xFFFFU << USART_BAUDR_DIV_Pos)        /*!< 0x0000FFFF */
#define USART_BAUDR_DIV                     USART_BAUDR_DIV_Msk                     /*!< Divider */

/*****************  Bit definition for USART_CTRL1 register  ******************/
#define USART_CTRL1_SBF_Pos                 (0U)
#define USART_CTRL1_SBF_Msk                 (0x1U << USART_CTRL1_SBF_Pos)           /*!< 0x00000001 */
#define USART_CTRL1_SBF                     USART_CTRL1_SBF_Msk                     /*!< Send break frame */
#define USART_CTRL1_RM_Pos                  (1U)
#define USART_CTRL1_RM_Msk                  (0x1U << USART_CTRL1_RM_Pos)            /*!< 0x00000002 */
#define USART_CTRL1_RM                      USART_CTRL1_RM_Msk                      /*!< Receiver mute */
#define USART_CTRL1_REN_Pos                 (2U)
#define USART_CTRL1_REN_Msk                 (0x1U << USART_CTRL1_REN_Pos)           /*!< 0x00000004 */
#define USART_CTRL1_REN                     USART_CTRL1_REN_Msk                     /*!< Receiver enable */
#define USART_CTRL1_TEN_Pos                 (3U)
#define USART_CTRL1_TEN_Msk                 (0x1U << USART_CTRL1_TEN_Pos)           /*!< 0x00000008 */
#define USART_CTRL1_TEN                     USART_CTRL1_TEN_Msk                     /*!< Transmitter enable */
#define USART_CTRL1_IDLEIEN_Pos             (4U)
#define USART_CTRL1_IDLEIEN_Msk             (0x1U << USART_CTRL1_IDLEIEN_Pos)       /*!< 0x00000010 */
#define USART_CTRL1_IDLEIEN                 USART_CTRL1_IDLEIEN_Msk                 /*!< IDLE interrupt enable */
#define USART_CTRL1_RDBFIEN_Pos             (5U)
#define USART_CTRL1_RDBFIEN_Msk             (0x1U << USART_CTRL1_RDBFIEN_Pos)       /*!< 0x00000020 */
#define USART_CTRL1_RDBFIEN                 USART_CTRL1_RDBFIEN_Msk                 /*!< RDBF interrupt enable */
#define USART_CTRL1_TDCIEN_Pos              (6U)
#define USART_CTRL1_TDCIEN_Msk              (0x1U << USART_CTRL1_TDCIEN_Pos)        /*!< 0x00000040 */
#define USART_CTRL1_TDCIEN                  USART_CTRL1_TDCIEN_Msk                  /*!< TDC interrupt enable */
#define USART_CTRL1_TDBEIEN_Pos             (7U)
#define USART_CTRL1_TDBEIEN_Msk             (0x1U << USART_CTRL1_TDBEIEN_Pos)       /*!< 0x00000080 */
#define USART_CTRL1_TDBEIEN                 USART_CTRL1_TDBEIEN_Msk                 /*!< TDBE interrupt enable */
#define USART_CTRL1_PERRIEN_Pos             (8U)
#define USART_CTRL1_PERRIEN_Msk             (0x1U << USART_CTRL1_PERRIEN_Pos)       /*!< 0x00000100 */
#define USART_CTRL1_PERRIEN                 USART_CTRL1_PERRIEN_Msk                 /*!< PERR interrupt enable */
#define USART_CTRL1_PSEL_Pos                (9U)
#define USART_CTRL1_PSEL_Msk                (0x1U << USART_CTRL1_PSEL_Pos)          /*!< 0x00000200 */
#define USART_CTRL1_PSEL                    USART_CTRL1_PSEL_Msk                    /*!< Parity selection */
#define USART_CTRL1_PEN_Pos                 (10U)
#define USART_CTRL1_PEN_Msk                 (0x1U << USART_CTRL1_PEN_Pos)           /*!< 0x00000400 */
#define USART_CTRL1_PEN                     USART_CTRL1_PEN_Msk                     /*!< Parity enable */
#define USART_CTRL1_WUM_Pos                 (11U)
#define USART_CTRL1_WUM_Msk                 (0x1U << USART_CTRL1_WUM_Pos)           /*!< 0x00000800 */
#define USART_CTRL1_WUM                     USART_CTRL1_WUM_Msk                     /*!< Wakeup mode */
#define USART_CTRL1_DBN_Pos                 (12U)
#define USART_CTRL1_DBN_Msk                 (0x1U << USART_CTRL1_DBN_Pos)           /*!< 0x00001000 */
#define USART_CTRL1_DBN                     USART_CTRL1_DBN_Msk                     /*!< Data bit num */
#define USART_CTRL1_UEN_Pos                 (13U)
#define USART_CTRL1_UEN_Msk                 (0x1U << USART_CTRL1_UEN_Pos)           /*!< 0x00002000 */
#define USART_CTRL1_UEN                     USART_CTRL1_UEN_Msk                     /*!< USART enable */

/*****************  Bit definition for USART_CTRL2 register  ******************/
#define USART_CTRL2_ID_Pos                  (0U)
#define USART_CTRL2_ID_Msk                  (0xFU << USART_CTRL2_ID_Pos)            /*!< 0x0000000F */
#define USART_CTRL2_ID                      USART_CTRL2_ID_Msk                      /*!< USART identification */
#define USART_CTRL2_BFBN_Pos                (5U)
#define USART_CTRL2_BFBN_Msk                (0x1U << USART_CTRL2_BFBN_Pos)          /*!< 0x00000020 */
#define USART_CTRL2_BFBN                    USART_CTRL2_BFBN_Msk                    /*!< Break frame bit num */
#define USART_CTRL2_BFIEN_Pos               (6U)
#define USART_CTRL2_BFIEN_Msk               (0x1U << USART_CTRL2_BFIEN_Pos)         /*!< 0x00000040 */
#define USART_CTRL2_BFIEN                   USART_CTRL2_BFIEN_Msk                   /*!< Break frame interrupt enable */
#define USART_CTRL2_LBCP_Pos                (8U)
#define USART_CTRL2_LBCP_Msk                (0x1U << USART_CTRL2_LBCP_Pos)          /*!< 0x00000100 */
#define USART_CTRL2_LBCP                    USART_CTRL2_LBCP_Msk                    /*!< Last bit clock pulse */
#define USART_CTRL2_CLKPHA_Pos              (9U)
#define USART_CTRL2_CLKPHA_Msk              (0x1U << USART_CTRL2_CLKPHA_Pos)        /*!< 0x00000200 */
#define USART_CTRL2_CLKPHA                  USART_CTRL2_CLKPHA_Msk                  /*!< Clock phase */
#define USART_CTRL2_CLKPOL_Pos              (10U)
#define USART_CTRL2_CLKPOL_Msk              (0x1U << USART_CTRL2_CLKPOL_Pos)        /*!< 0x00000400 */
#define USART_CTRL2_CLKPOL                  USART_CTRL2_CLKPOL_Msk                  /*!< Clock polarity */
#define USART_CTRL2_CLKEN_Pos               (11U)
#define USART_CTRL2_CLKEN_Msk               (0x1U << USART_CTRL2_CLKEN_Pos)         /*!< 0x00000800 */
#define USART_CTRL2_CLKEN                   USART_CTRL2_CLKEN_Msk                   /*!< Clock enable */

#define USART_CTRL2_STOPBN_Pos              (12U)
#define USART_CTRL2_STOPBN_Msk              (0x3U << USART_CTRL2_STOPBN_Pos)        /*!< 0x00003000 */
#define USART_CTRL2_STOPBN                  USART_CTRL2_STOPBN_Msk                  /*!< STOPBN[1:0] bits (STOP bit num) */
#define USART_CTRL2_STOPBN_0                (0x1U << USART_CTRL2_STOPBN_Pos)        /*!< 0x00001000 */
#define USART_CTRL2_STOPBN_1                (0x2U << USART_CTRL2_STOPBN_Pos)        /*!< 0x00002000 */

#define USART_CTRL2_LINEN_Pos               (14U)
#define USART_CTRL2_LINEN_Msk               (0x1U << USART_CTRL2_LINEN_Pos)         /*!< 0x00004000 */
#define USART_CTRL2_LINEN                   USART_CTRL2_LINEN_Msk                   /*!< LIN mode enable */

/*****************  Bit definition for USART_CTRL3 register  ******************/
#define USART_CTRL3_ERRIEN_Pos              (0U)
#define USART_CTRL3_ERRIEN_Msk              (0x1U << USART_CTRL3_ERRIEN_Pos)        /*!< 0x00000001 */
#define USART_CTRL3_ERRIEN                  USART_CTRL3_ERRIEN_Msk                  /*!< Error interrupt enable */
#define USART_CTRL3_IRDAEN_Pos              (1U)
#define USART_CTRL3_IRDAEN_Msk              (0x1U << USART_CTRL3_IRDAEN_Pos)        /*!< 0x00000002 */
#define USART_CTRL3_IRDAEN                  USART_CTRL3_IRDAEN_Msk                  /*!< IrDA enable */
#define USART_CTRL3_IRDALP_Pos              (2U)
#define USART_CTRL3_IRDALP_Msk              (0x1U << USART_CTRL3_IRDALP_Pos)        /*!< 0x00000004 */
#define USART_CTRL3_IRDALP                  USART_CTRL3_IRDALP_Msk                  /*!< IrDA low-power mode */
#define USART_CTRL3_SLBEN_Pos               (3U)
#define USART_CTRL3_SLBEN_Msk               (0x1U << USART_CTRL3_SLBEN_Pos)         /*!< 0x00000008 */
#define USART_CTRL3_SLBEN                   USART_CTRL3_SLBEN_Msk                   /*!< Single-wire bidirectional half-duplex enable */
#define USART_CTRL3_SCNACKEN_Pos            (4U)
#define USART_CTRL3_SCNACKEN_Msk            (0x1U << USART_CTRL3_SCNACKEN_Pos)      /*!< 0x00000010 */
#define USART_CTRL3_SCNACKEN                USART_CTRL3_SCNACKEN_Msk                /*!< Smart Card NACK enable */
#define USART_CTRL3_SCMEN_Pos               (5U)
#define USART_CTRL3_SCMEN_Msk               (0x1U << USART_CTRL3_SCMEN_Pos)         /*!< 0x00000020 */
#define USART_CTRL3_SCMEN                   USART_CTRL3_SCMEN_Msk                   /*!< Smart Card mode enable */
#define USART_CTRL3_DMAREN_Pos              (6U)
#define USART_CTRL3_DMAREN_Msk              (0x1U << USART_CTRL3_DMAREN_Pos)        /*!< 0x00000040 */
#define USART_CTRL3_DMAREN                  USART_CTRL3_DMAREN_Msk                  /*!< DMA receiver enable */
#define USART_CTRL3_DMATEN_Pos              (7U)
#define USART_CTRL3_DMATEN_Msk              (0x1U << USART_CTRL3_DMATEN_Pos)        /*!< 0x00000080 */
#define USART_CTRL3_DMATEN                  USART_CTRL3_DMATEN_Msk                  /*!< DMA transmitter enable */
#define USART_CTRL3_RTSEN_Pos               (8U)
#define USART_CTRL3_RTSEN_Msk               (0x1U << USART_CTRL3_RTSEN_Pos)         /*!< 0x00000100 */
#define USART_CTRL3_RTSEN                   USART_CTRL3_RTSEN_Msk                   /*!< RTS enable */
#define USART_CTRL3_CTSEN_Pos               (9U)
#define USART_CTRL3_CTSEN_Msk               (0x1U << USART_CTRL3_CTSEN_Pos)         /*!< 0x00000200 */
#define USART_CTRL3_CTSEN                   USART_CTRL3_CTSEN_Msk                   /*!< CTS enable */
#define USART_CTRL3_CTSCFIEN_Pos            (10U)
#define USART_CTRL3_CTSCFIEN_Msk            (0x1U << USART_CTRL3_CTSCFIEN_Pos)      /*!< 0x00000400 */
#define USART_CTRL3_CTSCFIEN                USART_CTRL3_CTSCFIEN_Msk                /*!< CTSCF interrupt enable */

/******************  Bit definition for USART_GDIV register  ******************/
#define USART_GDIV_ISDIV_Pos                (0U)
#define USART_GDIV_ISDIV_Msk                (0xFFU << USART_GDIV_ISDIV_Pos)         /*!< 0x000000FF */
#define USART_GDIV_ISDIV                    USART_GDIV_ISDIV_Msk                    /*!< ISDIV[7:0] bits (IrDA/Smart Card division) */
#define USART_GDIV_ISDIV_0                  (0x01U << USART_GDIV_ISDIV_Pos)         /*!< 0x00000001 */
#define USART_GDIV_ISDIV_1                  (0x02U << USART_GDIV_ISDIV_Pos)         /*!< 0x00000002 */
#define USART_GDIV_ISDIV_2                  (0x04U << USART_GDIV_ISDIV_Pos)         /*!< 0x00000004 */
#define USART_GDIV_ISDIV_3                  (0x08U << USART_GDIV_ISDIV_Pos)         /*!< 0x00000008 */
#define USART_GDIV_ISDIV_4                  (0x10U << USART_GDIV_ISDIV_Pos)         /*!< 0x00000010 */
#define USART_GDIV_ISDIV_5                  (0x20U << USART_GDIV_ISDIV_Pos)         /*!< 0x00000020 */
#define USART_GDIV_ISDIV_6                  (0x40U << USART_GDIV_ISDIV_Pos)         /*!< 0x00000040 */
#define USART_GDIV_ISDIV_7                  (0x80U << USART_GDIV_ISDIV_Pos)         /*!< 0x00000080 */

#define USART_GDIV_SCGT_Pos                 (8U)
#define USART_GDIV_SCGT_Msk                 (0xFFU << USART_GDIV_SCGT_Pos)          /*!< 0x0000FF00 */
#define USART_GDIV_SCGT                     USART_GDIV_SCGT_Msk                     /*!< Smart Card guard time value */

/******************************************************************************/
/*                                                                            */
/*                     Serial peripheral interface (SPI)                      */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for SPI_CTRL1 register  *******************/
#define SPI_CTRL1_CLKPHA_Pos                (0U)
#define SPI_CTRL1_CLKPHA_Msk                (0x1U << SPI_CTRL1_CLKPHA_Pos)          /*!< 0x00000001 */
#define SPI_CTRL1_CLKPHA                    SPI_CTRL1_CLKPHA_Msk                    /*!< Clock phase */
#define SPI_CTRL1_CLKPOL_Pos                (1U)
#define SPI_CTRL1_CLKPOL_Msk                (0x1U << SPI_CTRL1_CLKPOL_Pos)          /*!< 0x00000002 */
#define SPI_CTRL1_CLKPOL                    SPI_CTRL1_CLKPOL_Msk                    /*!< Clock polarity */
#define SPI_CTRL1_MSTEN_Pos                 (2U)
#define SPI_CTRL1_MSTEN_Msk                 (0x1U << SPI_CTRL1_MSTEN_Pos)           /*!< 0x00000004 */
#define SPI_CTRL1_MSTEN                     SPI_CTRL1_MSTEN_Msk                     /*!< Master enable */

/*!< MDIV configuration */
#define SPI_CTRL1_MDIV_Msk                  ((SPI_CTRL2_MDIV) | (0x7U << 3)         /*!< 0x00000138 */
#define SPI_CTRL1_MDIV                      SPI_CTRL1_MDIV_Msk                      /*!< MDIV[3:0] bits (Master clock frequency division) */
#define SPI_CTRL1_MDIV_0                    (0x1U << 3)                             /*!< 0x00000008 */
#define SPI_CTRL1_MDIV_1                    (0x2U << 3)                             /*!< 0x00000010 */
#define SPI_CTRL1_MDIV_2                    (0x4U << 3)                             /*!< 0x00000020 */
#define SPI_CTRL1_MDIV_3                    SPI_CTRL2_MDIV                          /*!< 0x00000100 */

#define SPI_CTRL1_SPIEN_Pos                 (6U)
#define SPI_CTRL1_SPIEN_Msk                 (0x1U << SPI_CTRL1_SPIEN_Pos)           /*!< 0x00000040 */
#define SPI_CTRL1_SPIEN                     SPI_CTRL1_SPIEN_Msk                     /*!< SPI enable */
#define SPI_CTRL1_LTF_Pos                   (7U)
#define SPI_CTRL1_LTF_Msk                   (0x1U << SPI_CTRL1_LTF_Pos)             /*!< 0x00000080 */
#define SPI_CTRL1_LTF                       SPI_CTRL1_LTF_Msk                       /*!< LSB transmit first */
#define SPI_CTRL1_SWCSIL_Pos                (8U)
#define SPI_CTRL1_SWCSIL_Msk                (0x1U << SPI_CTRL1_SWCSIL_Pos)          /*!< 0x00000100 */
#define SPI_CTRL1_SWCSIL                    SPI_CTRL1_SWCSIL_Msk                    /*!< Software CS internal level */
#define SPI_CTRL1_SWCSEN_Pos                (9U)
#define SPI_CTRL1_SWCSEN_Msk                (0x1U << SPI_CTRL1_SWCSEN_Pos)          /*!< 0x00000200 */
#define SPI_CTRL1_SWCSEN                    SPI_CTRL1_SWCSEN_Msk                    /*!< Software CS enable */
#define SPI_CTRL1_ORA_Pos                   (10U)
#define SPI_CTRL1_ORA_Msk                   (0x1U << SPI_CTRL1_ORA_Pos)             /*!< 0x00000400 */
#define SPI_CTRL1_ORA                       SPI_CTRL1_ORA_Msk                       /*!< Receive-only active */
#define SPI_CTRL1_FBN_Pos                   (11U)
#define SPI_CTRL1_FBN_Msk                   (0x1U << SPI_CTRL1_FBN_Pos)             /*!< 0x00000800 */
#define SPI_CTRL1_FBN                       SPI_CTRL1_FBN_Msk                       /*!< Frame bit num */
#define SPI_CTRL1_NTC_Pos                   (12U)
#define SPI_CTRL1_NTC_Msk                   (0x1U << SPI_CTRL1_NTC_Pos)             /*!< 0x00001000 */
#define SPI_CTRL1_NTC                       SPI_CTRL1_NTC_Msk                       /*!< Transmit CRC next */
#define SPI_CTRL1_CCEN_Pos                  (13U)
#define SPI_CTRL1_CCEN_Msk                  (0x1U << SPI_CTRL1_CCEN_Pos)            /*!< 0x00002000 */
#define SPI_CTRL1_CCEN                      SPI_CTRL1_CCEN_Msk                      /*!< RC calculation enable */
#define SPI_CTRL1_SLBTD_Pos                 (14U)
#define SPI_CTRL1_SLBTD_Msk                 (0x1U << SPI_CTRL1_SLBTD_Pos)           /*!< 0x00004000 */
#define SPI_CTRL1_SLBTD                     SPI_CTRL1_SLBTD_Msk                     /*!< Single line bidirectional half-duplex transmission direction */
#define SPI_CTRL1_SLBEN_Pos                 (15U)
#define SPI_CTRL1_SLBEN_Msk                 (0x1U << SPI_CTRL1_SLBEN_Pos)           /*!< 0x00008000 */
#define SPI_CTRL1_SLBEN                     SPI_CTRL1_SLBEN_Msk                     /*!< Single line bidirectional half-duplex enable */

/******************  Bit definition for SPI_CTRL2 register  *******************/
#define SPI_CTRL2_DMAREN_Pos                (0U)
#define SPI_CTRL2_DMAREN_Msk                (0x1U << SPI_CTRL2_DMAREN_Pos)          /*!< 0x00000001 */
#define SPI_CTRL2_DMAREN                    SPI_CTRL2_DMAREN_Msk                    /*!< DMA receive enable */
#define SPI_CTRL2_DMATEN_Pos                (1U)
#define SPI_CTRL2_DMATEN_Msk                (0x1U << SPI_CTRL2_DMATEN_Pos)          /*!< 0x00000002 */
#define SPI_CTRL2_DMATEN                    SPI_CTRL2_DMATEN_Msk                    /*!< DMA transmit enable */
#define SPI_CTRL2_HWCSOE_Pos                (2U)
#define SPI_CTRL2_HWCSOE_Msk                (0x1U << SPI_CTRL2_HWCSOE_Pos)          /*!< 0x00000004 */
#define SPI_CTRL2_HWCSOE                    SPI_CTRL2_HWCSOE_Msk                    /*!< Hardware CS output enable */
#define SPI_CTRL2_ERRIE_Pos                 (5U)
#define SPI_CTRL2_ERRIE_Msk                 (0x1U << SPI_CTRL2_ERRIE_Pos)           /*!< 0x00000020 */
#define SPI_CTRL2_ERRIE                     SPI_CTRL2_ERRIE_Msk                     /*!< Error interrupt enable */
#define SPI_CTRL2_RDBFIE_Pos                (6U)
#define SPI_CTRL2_RDBFIE_Msk                (0x1U << SPI_CTRL2_RDBFIE_Pos)          /*!< 0x00000040 */
#define SPI_CTRL2_RDBFIE                    SPI_CTRL2_RDBFIE_Msk                    /*!< Receive data buffer full interrupt enable */
#define SPI_CTRL2_TDBEIE_Pos                (7U)
#define SPI_CTRL2_TDBEIE_Msk                (0x1U << SPI_CTRL2_TDBEIE_Pos)          /*!< 0x00000080 */
#define SPI_CTRL2_TDBEIE                    SPI_CTRL2_TDBEIE_Msk                    /*!< Transmit data buffer empty interrupt enable */
#define SPI_CTRL2_MDIV_Pos                  (8U)
#define SPI_CTRL2_MDIV_Msk                  (0x1U << SPI_CTRL2_MDIV_Pos)            /*!< 0x00000100 */
#define SPI_CTRL2_MDIV                      SPI_CTRL2_MDIV_Msk                      /*!< Master clock frequency division */

/*******************  Bit definition for SPI_STS register  ********************/
#define SPI_STS_RDBF_Pos                    (0U)
#define SPI_STS_RDBF_Msk                    (0x1U << SPI_STS_RDBF_Pos)              /*!< 0x00000001 */
#define SPI_STS_RDBF                        SPI_STS_RDBF_Msk                        /*!< Receive data buffer full */
#define SPI_STS_TDBE_Pos                    (1U)
#define SPI_STS_TDBE_Msk                    (0x1U << SPI_STS_TDBE_Pos)              /*!< 0x00000002 */
#define SPI_STS_TDBE                        SPI_STS_TDBE_Msk                        /*!< Transmit data buffer empty */
#define SPI_STS_ACS_Pos                     (2U)
#define SPI_STS_ACS_Msk                     (0x1U << SPI_STS_ACS_Pos)               /*!< 0x00000004 */
#define SPI_STS_ACS                         SPI_STS_ACS_Msk                         /*!< Audio channel state */
#define SPI_STS_TUERR_Pos                   (3U)
#define SPI_STS_TUERR_Msk                   (0x1U << SPI_STS_TUERR_Pos)             /*!< 0x00000008 */
#define SPI_STS_TUERR                       SPI_STS_TUERR_Msk                       /*!< Transmitter underload error */
#define SPI_STS_CCERR_Pos                   (4U)
#define SPI_STS_CCERR_Msk                   (0x1U << SPI_STS_CCERR_Pos)             /*!< 0x00000010 */
#define SPI_STS_CCERR                       SPI_STS_CCERR_Msk                       /*!< CRC error */
#define SPI_STS_MMERR_Pos                   (5U)
#define SPI_STS_MMERR_Msk                   (0x1U << SPI_STS_MMERR_Pos)             /*!< 0x00000020 */
#define SPI_STS_MMERR                       SPI_STS_MMERR_Msk                       /*!< Master mode error */
#define SPI_STS_ROERR_Pos                   (6U)
#define SPI_STS_ROERR_Msk                   (0x1U << SPI_STS_ROERR_Pos)             /*!< 0x00000040 */
#define SPI_STS_ROERR                       SPI_STS_ROERR_Msk                       /*!< Receiver overflow error */
#define SPI_STS_BF_Pos                      (7U)
#define SPI_STS_BF_Msk                      (0x1U << SPI_STS_BF_Pos)                /*!< 0x00000080 */
#define SPI_STS_BF                          SPI_STS_BF_Msk                          /*!< Busy flag */

/********************  Bit definition for SPI_DT register  ********************/
#define SPI_DT_DT_Pos                       (0U)
#define SPI_DT_DT_Msk                       (0xFFFFU << SPI_DT_DT_Pos)              /*!< 0x0000FFFF */
#define SPI_DT_DT                           SPI_DT_DT_Msk                           /*!< Data value */

/*******************  Bit definition for SPI_CPOLY register  ******************/
#define SPI_CPOLY_CPOLY_Pos                 (0U)
#define SPI_CPOLY_CPOLY_Msk                 (0xFFFFU << SPI_CPOLY_CPOLY_Pos)        /*!< 0x0000FFFF */
#define SPI_CPOLY_CPOLY                     SPI_CPOLY_CPOLY_Msk                     /*!< CRC polynomial */

/*******************  Bit definition for SPI_RCRC register  *******************/
#define SPI_RCRC_RCRC_Pos                   (0U)
#define SPI_RCRC_RCRC_Msk                   (0xFFFFU << SPI_RCRC_RCRC_Pos)          /*!< 0x0000FFFF */
#define SPI_RCRC_RCRC                       SPI_RCRC_RCRC_Msk                       /*!< Receive CRC */

/*******************  Bit definition for SPI_TCRC register  *******************/
#define SPI_TCRC_TCRC_Pos                   (0U)
#define SPI_TCRC_TCRC_Msk                   (0xFFFFU << SPI_TCRC_TCRC_Pos)          /*!< 0x0000FFFF */
#define SPI_TCRC_TCRC                       SPI_TCRC_TCRC_Msk                       /*!< Transmit CRC */

/*****************  Bit definition for SPI_I2SCTRL register  ******************/
#define SPI_I2SCTRL_I2SCBN_Pos              (0U)
#define SPI_I2SCTRL_I2SCBN_Msk              (0x1U << SPI_I2SCTRL_I2SCBN_Pos)        /*!< 0x00000001 */
#define SPI_I2SCTRL_I2SCBN                  SPI_I2SCTRL_I2SCBN_Msk                  /*!< Channel length (I2S channel bit num) */

#define SPI_I2SCTRL_I2SDBN_Pos              (1U)
#define SPI_I2SCTRL_I2SDBN_Msk              (0x3U << SPI_I2SCTRL_I2SDBN_Pos)        /*!< 0x00000006 */
#define SPI_I2SCTRL_I2SDBN                  SPI_I2SCTRL_I2SDBN_Msk                  /*!< I2SDBN[1:0] bits (I2S data bit num) */
#define SPI_I2SCTRL_I2SDBN_0                (0x1U << SPI_I2SCTRL_I2SDBN_Pos)        /*!< 0x00000002 */
#define SPI_I2SCTRL_I2SDBN_1                (0x2U << SPI_I2SCTRL_I2SDBN_Pos)        /*!< 0x00000004 */

#define SPI_I2SCTRL_I2SCLKPOL_Pos           (3U)
#define SPI_I2SCTRL_I2SCLKPOL_Msk           (0x1U << SPI_I2SCTRL_I2SCLKPOL_Pos)     /*!< 0x00000008 */
#define SPI_I2SCTRL_I2SCLKPOL               SPI_I2SCTRL_I2SCLKPOL_Msk               /*!< I2S clock polarity */

#define SPI_I2SCTRL_STDSEL_Pos              (4U)
#define SPI_I2SCTRL_STDSEL_Msk              (0x3U << SPI_I2SCTRL_STDSEL_Pos)        /*!< 0x00000030 */
#define SPI_I2SCTRL_STDSEL                  SPI_I2SCTRL_STDSEL_Msk                  /*!< STDSEL[1:0] bits (I2S standard select) */
#define SPI_I2SCTRL_STDSEL_0                (0x1U << SPI_I2SCTRL_STDSEL_Pos)        /*!< 0x00000010 */
#define SPI_I2SCTRL_STDSEL_1                (0x2U << SPI_I2SCTRL_STDSEL_Pos)        /*!< 0x00000020 */

#define SPI_I2SCTRL_PCMFSSEL_Pos            (7U)
#define SPI_I2SCTRL_PCMFSSEL_Msk            (0x1U << SPI_I2SCTRL_PCMFSSEL_Pos)      /*!< 0x00000080 */
#define SPI_I2SCTRL_PCMFSSEL                SPI_I2SCTRL_PCMFSSEL_Msk                /*!< PCM frame synchronization */

#define SPI_I2SCTRL_OPERSEL_Pos             (8U)
#define SPI_I2SCTRL_OPERSEL_Msk             (0x3U << SPI_I2SCTRL_OPERSEL_Pos)       /*!< 0x00000300 */
#define SPI_I2SCTRL_OPERSEL                 SPI_I2SCTRL_OPERSEL_Msk                 /*!< OPERSEL[1:0] bits (I2S operation mode select) */
#define SPI_I2SCTRL_OPERSEL_0               (0x1U << SPI_I2SCTRL_OPERSEL_Pos)       /*!< 0x00000100 */
#define SPI_I2SCTRL_OPERSEL_1               (0x2U << SPI_I2SCTRL_OPERSEL_Pos)       /*!< 0x00000200 */

#define SPI_I2SCTRL_I2SEN_Pos               (10U)
#define SPI_I2SCTRL_I2SEN_Msk               (0x1U << SPI_I2SCTRL_I2SEN_Pos)         /*!< 0x00000400 */
#define SPI_I2SCTRL_I2SEN                   SPI_I2SCTRL_I2SEN_Msk                   /*!< I2S enable */
#define SPI_I2SCTRL_I2SMSEL_Pos             (11U)
#define SPI_I2SCTRL_I2SMSEL_Msk             (0x1U << SPI_I2SCTRL_I2SMSEL_Pos)       /*!< 0x00000800 */
#define SPI_I2SCTRL_I2SMSEL                 SPI_I2SCTRL_I2SMSEL_Msk                 /*!< I2S mode select */

/*****************  Bit definition for SPI_I2SCLKP register  ******************/
#define SPI_I2SCLKP_I2SDIV_Msk              ((0xFFU << 0) | (0x3U << 10))           /*!< 0x00000CFF */
#define SPI_I2SCLKP_I2SDIV                  SPI_I2SCLKP_I2SDIV_Msk                  /*!< I2SDIV[9:0] bits (I2S division) */
#define SPI_I2SCLKP_I2SODD_Pos              (8U)
#define SPI_I2SCLKP_I2SODD_Msk              (0x1U << SPI_I2SCLKP_I2SODD_Pos)        /*!< 0x00000100 */
#define SPI_I2SCLKP_I2SODD                  SPI_I2SCLKP_I2SODD_Msk                  /*!< Odd factor for I2S division */
#define SPI_I2SCLKP_I2SMCLKOE_Pos           (9U)
#define SPI_I2SCLKP_I2SMCLKOE_Msk           (0x1U << SPI_I2SCLKP_I2SMCLKOE_Pos)     /*!< 0x00000200 */
#define SPI_I2SCLKP_I2SMCLKOE               SPI_I2SCLKP_I2SMCLKOE_Msk               /*!< I2S Master clock output enable */

/******************************************************************************/
/*                                                                            */
/*                        Window watchdog timer (WWDT)                        */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for WWDT_CTRL register  *******************/
#define WWDT_CTRL_CNT_Pos                   (0U)
#define WWDT_CTRL_CNT_Msk                   (0x7FU << WWDT_CTRL_CNT_Pos)            /*!< 0x0000007F */
#define WWDT_CTRL_CNT                       WWDT_CTRL_CNT_Msk                       /*!< CNT[6:0] bits (Down counter) */
#define WWDT_CTRL_CNT_0                     (0x01U << WWDT_CTRL_CNT_Pos)            /*!< 0x00000001 */
#define WWDT_CTRL_CNT_1                     (0x02U << WWDT_CTRL_CNT_Pos)            /*!< 0x00000002 */
#define WWDT_CTRL_CNT_2                     (0x04U << WWDT_CTRL_CNT_Pos)            /*!< 0x00000004 */
#define WWDT_CTRL_CNT_3                     (0x08U << WWDT_CTRL_CNT_Pos)            /*!< 0x00000008 */
#define WWDT_CTRL_CNT_4                     (0x10U << WWDT_CTRL_CNT_Pos)            /*!< 0x00000010 */
#define WWDT_CTRL_CNT_5                     (0x20U << WWDT_CTRL_CNT_Pos)            /*!< 0x00000020 */
#define WWDT_CTRL_CNT_6                     (0x40U << WWDT_CTRL_CNT_Pos)            /*!< 0x00000040 */

/* Legacy defines */
#define WWDT_CTRL_CNT0                      WWDT_CTRL_CNT_0
#define WWDT_CTRL_CNT1                      WWDT_CTRL_CNT_1
#define WWDT_CTRL_CNT2                      WWDT_CTRL_CNT_2
#define WWDT_CTRL_CNT3                      WWDT_CTRL_CNT_3
#define WWDT_CTRL_CNT4                      WWDT_CTRL_CNT_4
#define WWDT_CTRL_CNT5                      WWDT_CTRL_CNT_5
#define WWDT_CTRL_CNT6                      WWDT_CTRL_CNT_6

#define WWDT_CTRL_WWDTEN_Pos                (7U)
#define WWDT_CTRL_WWDTEN_Msk                (0x1U << WWDT_CTRL_WWDTEN_Pos)          /*!< 0x00000080 */
#define WWDT_CTRL_WWDTEN                    WWDT_CTRL_WWDTEN_Msk                    /*!< Window watchdog enable */

/*******************  Bit definition for WWDT_CFG register  *******************/
#define WWDT_CFG_WIN_Pos                    (0U)
#define WWDT_CFG_WIN_Msk                    (0x7FU << WWDT_CFG_WIN_Pos)             /*!< 0x0000007F */
#define WWDT_CFG_WIN                        WWDT_CFG_WIN_Msk                        /*!< WIN[6:0] bits (Window value) */
#define WWDT_CFG_WIN_0                      (0x01U << WWDT_CFG_WIN_Pos)             /*!< 0x00000001 */
#define WWDT_CFG_WIN_1                      (0x02U << WWDT_CFG_WIN_Pos)             /*!< 0x00000002 */
#define WWDT_CFG_WIN_2                      (0x04U << WWDT_CFG_WIN_Pos)             /*!< 0x00000004 */
#define WWDT_CFG_WIN_3                      (0x08U << WWDT_CFG_WIN_Pos)             /*!< 0x00000008 */
#define WWDT_CFG_WIN_4                      (0x10U << WWDT_CFG_WIN_Pos)             /*!< 0x00000010 */
#define WWDT_CFG_WIN_5                      (0x20U << WWDT_CFG_WIN_Pos)             /*!< 0x00000020 */
#define WWDT_CFG_WIN_6                      (0x40U << WWDT_CFG_WIN_Pos)             /*!< 0x00000040 */

/* Legacy defines */
#define WWDT_CFG_WIN0                       WWDT_CFG_WIN_0
#define WWDT_CFG_WIN1                       WWDT_CFG_WIN_1
#define WWDT_CFG_WIN2                       WWDT_CFG_WIN_2
#define WWDT_CFG_WIN3                       WWDT_CFG_WIN_3
#define WWDT_CFG_WIN4                       WWDT_CFG_WIN_4
#define WWDT_CFG_WIN5                       WWDT_CFG_WIN_5
#define WWDT_CFG_WIN6                       WWDT_CFG_WIN_6

#define WWDT_CFG_DIV_Pos                    (7U)
#define WWDT_CFG_DIV_Msk                    (0x3U << WWDT_CFG_DIV_Pos)              /*!< 0x00000180 */
#define WWDT_CFG_DIV                        WWDT_CFG_DIV_Msk                        /*!< DIV[1:0] bits (Clock division value) */
#define WWDT_CFG_DIV_0                      (0x1U << WWDT_CFG_DIV_Pos)              /*!< 0x00000080 */
#define WWDT_CFG_DIV_1                      (0x2U << WWDT_CFG_DIV_Pos)              /*!< 0x00000100 */

/* Legacy defines */
#define WWDT_CFG_DIV0                       WWDT_CFG_DIV_0
#define WWDT_CFG_DIV1                       WWDT_CFG_DIV_1

#define WWDT_CFG_RLDIEN_Pos                 (9U)
#define WWDT_CFG_RLDIEN_Msk                 (0x1U << WWDT_CFG_RLDIEN_Pos)           /*!< 0x00000200 */
#define WWDT_CFG_RLDIEN                     WWDT_CFG_RLDIEN_Msk                     /*!< Reload counter interrupt */

/*******************  Bit definition for WWDT_STS register  *******************/
#define WWDT_STS_RLDF_Pos                   (0U)
#define WWDT_STS_RLDF_Msk                   (0x1U << WWDT_STS_RLDF_Pos)             /*!< 0x00000001 */
#define WWDT_STS_RLDF                       WWDT_STS_RLDF_Msk                       /*!< Reload counter interrupt flag */

/******************************************************************************/
/*                                                                            */
/*                            Watchdog timer (WDT)                            */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for WDT_CMD register  ********************/
#define WDT_CMD_CMD_Pos                     (0U)
#define WDT_CMD_CMD_Msk                     (0xFFFFU << WDT_CMD_CMD_Pos)            /*!< 0x0000FFFF */
#define WDT_CMD_CMD                         WDT_CMD_CMD_Msk                         /*!< Command register */

/*******************  Bit definition for WDT_DIV register  ********************/
#define WDT_DIV_DIV_Pos                     (0U)
#define WDT_DIV_DIV_Msk                     (0x7U << WDT_DIV_DIV_Pos)               /*!< 0x00000007 */
#define WDT_DIV_DIV                         WDT_DIV_DIV_Msk                         /*!< DIV[2:0] (Clock division value) */
#define WDT_DIV_DIV_0                       (0x1U << WDT_DIV_DIV_Pos)               /*!< 0x00000001 */
#define WDT_DIV_DIV_1                       (0x2U << WDT_DIV_DIV_Pos)               /*!< 0x00000002 */
#define WDT_DIV_DIV_2                       (0x4U << WDT_DIV_DIV_Pos)               /*!< 0x00000004 */

/*******************  Bit definition for WDT_RLD register  ********************/
#define WDT_RLD_RLD_Pos                     (0U)
#define WDT_RLD_RLD_Msk                     (0xFFFU << WDT_RLD_RLD_Pos)             /*!< 0x00000FFF */
#define WDT_RLD_RLD                         WDT_RLD_RLD_Msk                         /*!< Reload value */

/*******************  Bit definition for WDT_STS register  ********************/
#define WDT_STS_DIVF_Pos                    (0U)
#define WDT_STS_DIVF_Msk                    (0x1U << WDT_STS_DIVF_Pos)              /*!< 0x00000001 */
#define WDT_STS_DIVF                        WDT_STS_DIVF_Msk                        /*!< Division value update complete flag */
#define WDT_STS_RLDF_Pos                    (1U)
#define WDT_STS_RLDF_Msk                    (0x1U << WDT_STS_RLDF_Pos)              /*!< 0x00000002 */
#define WDT_STS_RLDF                        WDT_STS_RLDF_Msk                        /*!< Reload value update complete flag */

/******************************************************************************/
/*                                                                            */
/*                      Enhanced real-time clock (ERTC)                       */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for ERTC_TIME register  *******************/
#define ERTC_TIME_SU_Pos                    (0U)
#define ERTC_TIME_SU_Msk                    (0xFU << ERTC_TIME_SU_Pos)              /*!< 0x0000000F */
#define ERTC_TIME_SU                        ERTC_TIME_SU_Msk                        /*!< SU[3:0] (Second units) */
#define ERTC_TIME_SU_0                      (0x1U << ERTC_TIME_SU_Pos)              /*!< 0x00000001 */
#define ERTC_TIME_SU_1                      (0x2U << ERTC_TIME_SU_Pos)              /*!< 0x00000002 */
#define ERTC_TIME_SU_2                      (0x4U << ERTC_TIME_SU_Pos)              /*!< 0x00000004 */
#define ERTC_TIME_SU_3                      (0x8U << ERTC_TIME_SU_Pos)              /*!< 0x00000008 */

#define ERTC_TIME_ST_Pos                    (4U)
#define ERTC_TIME_ST_Msk                    (0x7U << ERTC_TIME_ST_Pos)              /*!< 0x00000070 */
#define ERTC_TIME_ST                        ERTC_TIME_ST_Msk                        /*!< ST[2:0] (Second tens) */
#define ERTC_TIME_ST_0                      (0x1U << ERTC_TIME_ST_Pos)              /*!< 0x00000010 */
#define ERTC_TIME_ST_1                      (0x2U << ERTC_TIME_ST_Pos)              /*!< 0x00000020 */
#define ERTC_TIME_ST_2                      (0x4U << ERTC_TIME_ST_Pos)              /*!< 0x00000040 */

#define ERTC_TIME_MU_Pos                    (8U)
#define ERTC_TIME_MU_Msk                    (0xFU << ERTC_TIME_MU_Pos)              /*!< 0x00000F00 */
#define ERTC_TIME_MU                        ERTC_TIME_MU_Msk                        /*!< MU[3:0] (Minute units) */
#define ERTC_TIME_MU_0                      (0x1U << ERTC_TIME_MU_Pos)              /*!< 0x00000100 */
#define ERTC_TIME_MU_1                      (0x2U << ERTC_TIME_MU_Pos)              /*!< 0x00000200 */
#define ERTC_TIME_MU_2                      (0x4U << ERTC_TIME_MU_Pos)              /*!< 0x00000400 */
#define ERTC_TIME_MU_3                      (0x8U << ERTC_TIME_MU_Pos)              /*!< 0x00000800 */

#define ERTC_TIME_MT_Pos                    (12U)
#define ERTC_TIME_MT_Msk                    (0x7U << ERTC_TIME_MT_Pos)              /*!< 0x00007000 */
#define ERTC_TIME_MT                        ERTC_TIME_MT_Msk                        /*!< MT[2:0] (Minute tens) */
#define ERTC_TIME_MT_0                      (0x1U << ERTC_TIME_MT_Pos)              /*!< 0x00001000 */
#define ERTC_TIME_MT_1                      (0x2U << ERTC_TIME_MT_Pos)              /*!< 0x00002000 */
#define ERTC_TIME_MT_2                      (0x4U << ERTC_TIME_MT_Pos)              /*!< 0x00004000 */

#define ERTC_TIME_HU_Pos                    (16U)
#define ERTC_TIME_HU_Msk                    (0xFU << ERTC_TIME_HU_Pos)              /*!< 0x000F0000 */
#define ERTC_TIME_HU                        ERTC_TIME_HU_Msk                        /*!< HU[3:0] (Hour units) */
#define ERTC_TIME_HU_0                      (0x1U << ERTC_TIME_HU_Pos)              /*!< 0x00010000 */
#define ERTC_TIME_HU_1                      (0x2U << ERTC_TIME_HU_Pos)              /*!< 0x00020000 */
#define ERTC_TIME_HU_2                      (0x4U << ERTC_TIME_HU_Pos)              /*!< 0x00040000 */
#define ERTC_TIME_HU_3                      (0x8U << ERTC_TIME_HU_Pos)              /*!< 0x00080000 */

#define ERTC_TIME_HT_Pos                    (20U)
#define ERTC_TIME_HT_Msk                    (0x3U << ERTC_TIME_HT_Pos)              /*!< 0x00300000 */
#define ERTC_TIME_HT                        ERTC_TIME_HT_Msk                        /*!< HT[1:0] (Hour tens) */
#define ERTC_TIME_HT_0                      (0x1U << ERTC_TIME_HT_Pos)              /*!< 0x00100000 */
#define ERTC_TIME_HT_1                      (0x2U << ERTC_TIME_HT_Pos)              /*!< 0x00200000 */

#define ERTC_TIME_AMPM_Pos                  (22U)
#define ERTC_TIME_AMPM_Msk                  (0x1U << ERTC_TIME_AMPM_Pos)            /*!< 0x00400000 */
#define ERTC_TIME_AMPM                      ERTC_TIME_AMPM_Msk                      /*!< AM/PM */

/******************  Bit definition for ERTC_DATE register  *******************/
#define ERTC_DATE_DU_Pos                    (0U)
#define ERTC_DATE_DU_Msk                    (0xFU << ERTC_DATE_DU_Pos)              /*!< 0x0000000F */
#define ERTC_DATE_DU                        ERTC_DATE_DU_Msk                        /*!< DU[3:0] (Date units) */
#define ERTC_DATE_DU_0                      (0x1U << ERTC_DATE_DU_Pos)              /*!< 0x00000001 */
#define ERTC_DATE_DU_1                      (0x2U << ERTC_DATE_DU_Pos)              /*!< 0x00000002 */
#define ERTC_DATE_DU_2                      (0x4U << ERTC_DATE_DU_Pos)              /*!< 0x00000004 */
#define ERTC_DATE_DU_3                      (0x8U << ERTC_DATE_DU_Pos)              /*!< 0x00000008 */

#define ERTC_DATE_DT_Pos                    (4U)
#define ERTC_DATE_DT_Msk                    (0x3U << ERTC_DATE_DT_Pos)              /*!< 0x00300000 */
#define ERTC_DATE_DT                        ERTC_DATE_DT_Msk                        /*!< DT[1:0] (Date tens) */
#define ERTC_DATE_DT_0                      (0x1U << ERTC_DATE_DT_Pos)              /*!< 0x00000010 */
#define ERTC_DATE_DT_1                      (0x2U << ERTC_DATE_DT_Pos)              /*!< 0x00000020 */

#define ERTC_DATE_MU_Pos                    (8U)
#define ERTC_DATE_MU_Msk                    (0xFU << ERTC_DATE_MU_Pos)              /*!< 0x00000F00 */
#define ERTC_DATE_MU                        ERTC_DATE_MU_Msk                        /*!< MU[3:0] (Month units) */
#define ERTC_DATE_MU_0                      (0x1U << ERTC_DATE_MU_Pos)              /*!< 0x00000100 */
#define ERTC_DATE_MU_1                      (0x2U << ERTC_DATE_MU_Pos)              /*!< 0x00000200 */
#define ERTC_DATE_MU_2                      (0x4U << ERTC_DATE_MU_Pos)              /*!< 0x00000400 */
#define ERTC_DATE_MU_3                      (0x8U << ERTC_DATE_MU_Pos)              /*!< 0x00000800 */

#define ERTC_DATE_MT_Pos                    (12U)
#define ERTC_DATE_MT_Msk                    (0x1U << ERTC_DATE_MT_Pos)              /*!< 0x00001000 */
#define ERTC_DATE_MT                        ERTC_DATE_MT_Msk                        /*!< Month tens */

#define ERTC_DATE_WK_Pos                    (13U)
#define ERTC_DATE_WK_Msk                    (0x7U << ERTC_DATE_WK_Pos)              /*!< 0x0000E000 */
#define ERTC_DATE_WK                        ERTC_DATE_WK_Msk                        /*!< WK[2:0] (Week day) */
#define ERTC_DATE_WK_0                      (0x1U << ERTC_DATE_WK_Pos)              /*!< 0x00002000 */
#define ERTC_DATE_WK_1                      (0x2U << ERTC_DATE_WK_Pos)              /*!< 0x00004000 */
#define ERTC_DATE_WK_2                      (0x4U << ERTC_DATE_WK_Pos)              /*!< 0x00008000 */

#define ERTC_DATE_YU_Pos                    (16U)
#define ERTC_DATE_YU_Msk                    (0xFU << ERTC_DATE_YU_Pos)              /*!< 0x000F0000 */
#define ERTC_DATE_YU                        ERTC_DATE_YU_Msk                        /*!< YU[3:0] (Year units) */
#define ERTC_DATE_YU_0                      (0x1U << ERTC_DATE_YU_Pos)              /*!< 0x00010000 */
#define ERTC_DATE_YU_1                      (0x2U << ERTC_DATE_YU_Pos)              /*!< 0x00020000 */
#define ERTC_DATE_YU_2                      (0x4U << ERTC_DATE_YU_Pos)              /*!< 0x00040000 */
#define ERTC_DATE_YU_3                      (0x8U << ERTC_DATE_YU_Pos)              /*!< 0x00080000 */

#define ERTC_DATE_YT_Pos                    (20U)
#define ERTC_DATE_YT_Msk                    (0xFU << ERTC_DATE_YT_Pos)              /*!< 0x00F00000 */
#define ERTC_DATE_YT                        ERTC_DATE_YT_Msk                        /*!< YT[3:0] (Year tens) */
#define ERTC_DATE_YT_0                      (0x1U << ERTC_DATE_YT_Pos)              /*!< 0x00100000 */
#define ERTC_DATE_YT_1                      (0x2U << ERTC_DATE_YT_Pos)              /*!< 0x00200000 */
#define ERTC_DATE_YT_2                      (0x4U << ERTC_DATE_YT_Pos)              /*!< 0x00400000 */
#define ERTC_DATE_YT_3                      (0x8U << ERTC_DATE_YT_Pos)              /*!< 0x00800000 */

/******************  Bit definition for ERTC_CTRL register  *******************/
#define ERTC_CTRL_WATCLK_Pos                (0U)
#define ERTC_CTRL_WATCLK_Msk                (0x7U << ERTC_CTRL_WATCLK_Pos)          /*!< 0x00000007 */
#define ERTC_CTRL_WATCLK                    ERTC_CTRL_WATCLK_Msk                    /*!< WATCLK[2:0] (Wakeup timer clock selection) */
#define ERTC_CTRL_WATCLK_0                  (0x1U << ERTC_CTRL_WATCLK_Pos)          /*!< 0x00000001 */
#define ERTC_CTRL_WATCLK_1                  (0x2U << ERTC_CTRL_WATCLK_Pos)          /*!< 0x00000002 */
#define ERTC_CTRL_WATCLK_2                  (0x4U << ERTC_CTRL_WATCLK_Pos)          /*!< 0x00000004 */

#define ERTC_CTRL_TSEDG_Pos                 (3U)
#define ERTC_CTRL_TSEDG_Msk                 (0x1U << ERTC_CTRL_TSEDG_Pos)           /*!< 0x00000008 */
#define ERTC_CTRL_TSEDG                     ERTC_CTRL_TSEDG_Msk                     /*!< Timestamp trigger edge */
#define ERTC_CTRL_RCDEN_Pos                 (4U)
#define ERTC_CTRL_RCDEN_Msk                 (0x1U << ERTC_CTRL_RCDEN_Pos)           /*!< 0x00000010 */
#define ERTC_CTRL_RCDEN                     ERTC_CTRL_RCDEN_Msk                     /*!< Reference clock detection enable */
#define ERTC_CTRL_DREN_Pos                  (5U)
#define ERTC_CTRL_DREN_Msk                  (0x1U << ERTC_CTRL_DREN_Pos)            /*!< 0x00000020 */
#define ERTC_CTRL_DREN                      ERTC_CTRL_DREN_Msk                      /*!< Date/time register direct read enable */
#define ERTC_CTRL_HM_Pos                    (6U)
#define ERTC_CTRL_HM_Msk                    (0x1U << ERTC_CTRL_HM_Pos)              /*!< 0x00000040 */
#define ERTC_CTRL_HM                        ERTC_CTRL_HM_Msk                        /*!< Hour mode */
#define ERTC_CTRL_CCALEN_Pos                (7U)
#define ERTC_CTRL_CCALEN_Msk                (0x1U << ERTC_CTRL_CCALEN_Pos)          /*!< 0x00000080 */
#define ERTC_CTRL_CCALEN                    ERTC_CTRL_CCALEN_Msk                    /*!< Coarse calibration enable */
#define ERTC_CTRL_ALAEN_Pos                 (8U)
#define ERTC_CTRL_ALAEN_Msk                 (0x1U << ERTC_CTRL_ALAEN_Pos)           /*!< 0x00000100 */
#define ERTC_CTRL_ALAEN                     ERTC_CTRL_ALAEN_Msk                     /*!< Alarm A enable */
#define ERTC_CTRL_ALBEN_Pos                 (9U)
#define ERTC_CTRL_ALBEN_Msk                 (0x1U << ERTC_CTRL_ALBEN_Pos)           /*!< 0x00000200 */
#define ERTC_CTRL_ALBEN                     ERTC_CTRL_ALBEN_Msk                     /*!< Alarm B enable */
#define ERTC_CTRL_WATEN_Pos                 (10U)
#define ERTC_CTRL_WATEN_Msk                 (0x1U << ERTC_CTRL_WATEN_Pos)           /*!< 0x00000400 */
#define ERTC_CTRL_WATEN                     ERTC_CTRL_WATEN_Msk                     /*!< Wakeup timer enable */
#define ERTC_CTRL_TSEN_Pos                  (11U)
#define ERTC_CTRL_TSEN_Msk                  (0x1U << ERTC_CTRL_TSEN_Pos)            /*!< 0x00000800 */
#define ERTC_CTRL_TSEN                      ERTC_CTRL_TSEN_Msk                      /*!< Timestamp enable */
#define ERTC_CTRL_ALAIEN_Pos                (12U)
#define ERTC_CTRL_ALAIEN_Msk                (0x1U << ERTC_CTRL_ALAIEN_Pos)          /*!< 0x00001000 */
#define ERTC_CTRL_ALAIEN                    ERTC_CTRL_ALAIEN_Msk                    /*!< Alarm A interrupt enable */
#define ERTC_CTRL_ALBIEN_Pos                (13U)
#define ERTC_CTRL_ALBIEN_Msk                (0x1U << ERTC_CTRL_ALBIEN_Pos)          /*!< 0x00002000 */
#define ERTC_CTRL_ALBIEN                    ERTC_CTRL_ALBIEN_Msk                    /*!< Alarm B interrupt enable */
#define ERTC_CTRL_WATIEN_Pos                (14U)
#define ERTC_CTRL_WATIEN_Msk                (0x1U << ERTC_CTRL_WATIEN_Pos)          /*!< 0x00004000 */
#define ERTC_CTRL_WATIEN                    ERTC_CTRL_WATIEN_Msk                    /*!< Wakeup timer interrupt enable */
#define ERTC_CTRL_TSIEN_Pos                 (15U)
#define ERTC_CTRL_TSIEN_Msk                 (0x1U << ERTC_CTRL_TSIEN_Pos)           /*!< 0x000008000 */
#define ERTC_CTRL_TSIEN                     ERTC_CTRL_TSIEN_Msk                     /*!< Timestamp interrupt enable */
#define ERTC_CTRL_ADD1H_Pos                 (16U)
#define ERTC_CTRL_ADD1H_Msk                 (0x1U << ERTC_CTRL_ADD1H_Pos)           /*!< 0x00010000 */
#define ERTC_CTRL_ADD1H                     ERTC_CTRL_ADD1H_Msk                     /*!< Add 1 hour */
#define ERTC_CTRL_DEC1H_Pos                 (17U)
#define ERTC_CTRL_DEC1H_Msk                 (0x1U << ERTC_CTRL_DEC1H_Pos)           /*!< 0x00020000 */
#define ERTC_CTRL_DEC1H                     ERTC_CTRL_DEC1H_Msk                     /*!< Decrease 1 hour */
#define ERTC_CTRL_BPR_Pos                   (18U)
#define ERTC_CTRL_BPR_Msk                   (0x1U << ERTC_CTRL_BPR_Pos)             /*!< 0x00040000 */
#define ERTC_CTRL_BPR                       ERTC_CTRL_BPR_Msk                       /*!< Battery powered domain data register */
#define ERTC_CTRL_CALOSEL_Pos               (19U)
#define ERTC_CTRL_CALOSEL_Msk               (0x1U << ERTC_CTRL_CALOSEL_Pos)         /*!< 0x00080000 */
#define ERTC_CTRL_CALOSEL                   ERTC_CTRL_CALOSEL_Msk                   /*!< Calibration output selection */
#define ERTC_CTRL_OUTP_Pos                  (20U)
#define ERTC_CTRL_OUTP_Msk                  (0x1U << ERTC_CTRL_OUTP_Pos)            /*!< 0x00100000 */
#define ERTC_CTRL_OUTP                      ERTC_CTRL_OUTP_Msk                      /*!< Output polarity */

#define ERTC_CTRL_OUTSEL_Pos                (21U)
#define ERTC_CTRL_OUTSEL_Msk                (0x3U << ERTC_CTRL_OUTSEL_Pos)          /*!< 0x00600000 */
#define ERTC_CTRL_OUTSEL                    ERTC_CTRL_OUTSEL_Msk                    /*!< WATCLK[1:0] (Output source selection) */
#define ERTC_CTRL_OUTSEL_0                  (0x1U << ERTC_CTRL_OUTSEL_Pos)          /*!< 0x00200000 */
#define ERTC_CTRL_OUTSEL_1                  (0x2U << ERTC_CTRL_OUTSEL_Pos)          /*!< 0x00400000 */

#define ERTC_CTRL_CALOEN_Pos                (23U)
#define ERTC_CTRL_CALOEN_Msk                (0x1U << ERTC_CTRL_CALOEN_Pos)          /*!< 0x00800000 */
#define ERTC_CTRL_CALOEN                    ERTC_CTRL_CALOEN_Msk                    /*!< Calibration output enable */

/*******************  Bit definition for ERTC_STS register  *******************/
#define ERTC_STS_ALAWF_Pos                  (0U)
#define ERTC_STS_ALAWF_Msk                  (0x1U << ERTC_STS_ALAWF_Pos)            /*!< 0x00000001 */
#define ERTC_STS_ALAWF                      ERTC_STS_ALAWF_Msk                      /*!< Alarm A register allows write flag */
#define ERTC_STS_ALBWF_Pos                  (1U)
#define ERTC_STS_ALBWF_Msk                  (0x1U << ERTC_STS_ALBWF_Pos)            /*!< 0x00000002 */
#define ERTC_STS_ALBWF                      ERTC_STS_ALBWF_Msk                      /*!< Alarm B register allows write flag */
#define ERTC_STS_WATWF_Pos                  (2U)
#define ERTC_STS_WATWF_Msk                  (0x1U << ERTC_STS_WATWF_Pos)            /*!< 0x00000004 */
#define ERTC_STS_WATWF                      ERTC_STS_WATWF_Msk                      /*!< Wakeup timer register allows write flag */
#define ERTC_STS_TADJF_Pos                  (3U)
#define ERTC_STS_TADJF_Msk                  (0x1U << ERTC_STS_TADJF_Pos)            /*!< 0x00000008 */
#define ERTC_STS_TADJF                      ERTC_STS_TADJF_Msk                      /*!< Time adjustment flag */
#define ERTC_STS_INITF_Pos                  (4U)
#define ERTC_STS_INITF_Msk                  (0x1U << ERTC_STS_INITF_Pos)            /*!< 0x00000010 */
#define ERTC_STS_INITF                      ERTC_STS_INITF_Msk                      /*!< Calendar initialization flag */
#define ERTC_STS_UPDF_Pos                   (5U)
#define ERTC_STS_UPDF_Msk                   (0x1U << ERTC_STS_UPDF_Pos)             /*!< 0x00000020 */
#define ERTC_STS_UPDF                       ERTC_STS_UPDF_Msk                       /*!< Calendar update flag */
#define ERTC_STS_IMF_Pos                    (6U)
#define ERTC_STS_IMF_Msk                    (0x1U << ERTC_STS_IMF_Pos)              /*!< 0x00000040 */
#define ERTC_STS_IMF                        ERTC_STS_IMF_Msk                        /*!< Enter initialization mode flag */
#define ERTC_STS_IMEN_Pos                   (7U)
#define ERTC_STS_IMEN_Msk                   (0x1U << ERTC_STS_IMEN_Pos)             /*!< 0x00000080 */
#define ERTC_STS_IMEN                       ERTC_STS_IMEN_Msk                       /*!< Initialization mode enable */
#define ERTC_STS_ALAF_Pos                   (8U)
#define ERTC_STS_ALAF_Msk                   (0x1U << ERTC_STS_ALAF_Pos)             /*!< 0x00000100 */
#define ERTC_STS_ALAF                       ERTC_STS_ALAF_Msk                       /*!< Alarm clock A flag */
#define ERTC_STS_ALBF_Pos                   (9U)
#define ERTC_STS_ALBF_Msk                   (0x1U << ERTC_STS_ALBF_Pos)             /*!< 0x00000200 */
#define ERTC_STS_ALBF                       ERTC_STS_ALBF_Msk                       /*!< Alarm clock B flag */
#define ERTC_STS_WATF_Pos                   (10U)
#define ERTC_STS_WATF_Msk                   (0x1U << ERTC_STS_WATF_Pos)             /*!< 0x00000400 */
#define ERTC_STS_WATF                       ERTC_STS_WATF_Msk                       /*!< Wakeup timer flag */
#define ERTC_STS_TSF_Pos                    (11U)
#define ERTC_STS_TSF_Msk                    (0x1U << ERTC_STS_TSF_Pos)              /*!< 0x00000800 */
#define ERTC_STS_TSF                        ERTC_STS_TSF_Msk                        /*!< Timestamp flag */
#define ERTC_STS_TSOF_Pos                   (12U)
#define ERTC_STS_TSOF_Msk                   (0x1U << ERTC_STS_TSOF_Pos)             /*!< 0x00001000 */
#define ERTC_STS_TSOF                       ERTC_STS_TSOF_Msk                       /*!< Timestamp overflow flag */
#define ERTC_STS_TP1F_Pos                   (13U)
#define ERTC_STS_TP1F_Msk                   (0x1U << ERTC_STS_TP1F_Pos)             /*!< 0x00002000 */
#define ERTC_STS_TP1F                       ERTC_STS_TP1F_Msk                       /*!< Tamper detection 1 flag */
#define ERTC_STS_CALUPDF_Pos                (16U)
#define ERTC_STS_CALUPDF_Msk                (0x1U << ERTC_STS_CALUPDF_Pos)          /*!< 0x00010000 */
#define ERTC_STS_CALUPDF                    ERTC_STS_CALUPDF_Msk                    /*!< Calibration value update complete flag */

/*******************  Bit definition for ERTC_DIV register  *******************/
#define ERTC_DIV_DIVB_Pos                   (0U)
#define ERTC_DIV_DIVB_Msk                   (0x7FFFU << ERTC_DIV_DIVB_Pos)          /*!< 0x00007FFF */
#define ERTC_DIV_DIVB                       ERTC_DIV_DIVB_Msk                       /*!< Divider B */
#define ERTC_DIV_DIVA_Pos                   (16U)
#define ERTC_DIV_DIVA_Msk                   (0x7FU << ERTC_DIV_DIVA_Pos)            /*!< 0x007F0000 */
#define ERTC_DIV_DIVA                       ERTC_DIV_DIVA_Msk                       /*!< Divider A */

/*******************  Bit definition for ERTC_WAT register  *******************/
#define ERTC_WAT_VAL_Pos                    (0U)
#define ERTC_WAT_VAL_Msk                    (0xFFFFU << ERTC_WAT_VAL_Pos)           /*!< 0x0000FFFF */
#define ERTC_WAT_VAL                        ERTC_WAT_VAL_Msk                        /*!< Wakeup timer reload value */

/******************  Bit definition for ERTC_CCAL register  *******************/
#define ERTC_CCAL_CALVAL_Pos                (0U)
#define ERTC_CCAL_CALVAL_Msk                (0x1FU << ERTC_CCAL_CALVAL_Pos)         /*!< 0x0000001F */
#define ERTC_CCAL_CALVAL                    ERTC_CCAL_CALVAL_Msk                    /*!< CALVAL[4:0] (Calibration value) */
#define ERTC_CCAL_CALVAL_0                  (0x1U << ERTC_CCAL_CALVAL_Pos)          /*!< 0x00000001 */
#define ERTC_CCAL_CALVAL_1                  (0x2U << ERTC_CCAL_CALVAL_Pos)          /*!< 0x00000002 */
#define ERTC_CCAL_CALVAL_2                  (0x4U << ERTC_CCAL_CALVAL_Pos)          /*!< 0x00000004 */
#define ERTC_CCAL_CALVAL_3                  (0x8U << ERTC_CCAL_CALVAL_Pos)          /*!< 0x00000008 */
#define ERTC_CCAL_CALVAL_4                  (0x10U << ERTC_CCAL_CALVAL_Pos)         /*!< 0x00000010 */

#define ERTC_CCAL_CALDIR_Pos                (7U)
#define ERTC_CCAL_CALDIR_Msk                (0x1U << ERTC_CCAL_CALDIR_Pos)          /*!< 0x00000080 */
#define ERTC_CCAL_CALDIR                    ERTC_CCAL_CALDIR_Msk                    /*!< Calibration direction */

/*******************  Bit definition for ERTC_ALA register  *******************/
#define ERTC_ALA_SU_Pos                     (0U)
#define ERTC_ALA_SU_Msk                     (0xFU << ERTC_ALA_SU_Pos)               /*!< 0x0000000F */
#define ERTC_ALA_SU                         ERTC_ALA_SU_Msk                         /*!< SU[3:0] (Second units) */
#define ERTC_ALA_SU_0                       (0x1U << ERTC_ALA_SU_Pos)               /*!< 0x00000001 */
#define ERTC_ALA_SU_1                       (0x2U << ERTC_ALA_SU_Pos)               /*!< 0x00000002 */
#define ERTC_ALA_SU_2                       (0x4U << ERTC_ALA_SU_Pos)               /*!< 0x00000004 */
#define ERTC_ALA_SU_3                       (0x8U << ERTC_ALA_SU_Pos)               /*!< 0x00000008 */

#define ERTC_ALA_ST_Pos                     (4U)
#define ERTC_ALA_ST_Msk                     (0x7U << ERTC_ALA_ST_Pos)               /*!< 0x00000070 */
#define ERTC_ALA_ST                         ERTC_ALA_ST_Msk                         /*!< ST[2:0] (Second tens) */
#define ERTC_ALA_ST_0                       (0x1U << ERTC_ALA_ST_Pos)               /*!< 0x00000010 */
#define ERTC_ALA_ST_1                       (0x2U << ERTC_ALA_ST_Pos)               /*!< 0x00000020 */
#define ERTC_ALA_ST_2                       (0x4U << ERTC_ALA_ST_Pos)               /*!< 0x00000040 */

#define ERTC_ALA_MASK1_Pos                  (7U)
#define ERTC_ALA_MASK1_Msk                  (0x1U << ERTC_ALA_MASK1_Pos)            /*!< 0x00000080 */
#define ERTC_ALA_MASK1                      ERTC_ALA_MASK1_Msk                      /*!< Second mask */

#define ERTC_ALA_MU_Pos                     (8U)
#define ERTC_ALA_MU_Msk                     (0xFU << ERTC_ALA_MU_Pos)               /*!< 0x00000F00 */
#define ERTC_ALA_MU                         ERTC_ALA_MU_Msk                         /*!< MU[3:0] (Minute units) */
#define ERTC_ALA_MU_0                       (0x1U << ERTC_ALA_MU_Pos)               /*!< 0x00000100 */
#define ERTC_ALA_MU_1                       (0x2U << ERTC_ALA_MU_Pos)               /*!< 0x00000200 */
#define ERTC_ALA_MU_2                       (0x4U << ERTC_ALA_MU_Pos)               /*!< 0x00000400 */
#define ERTC_ALA_MU_3                       (0x8U << ERTC_ALA_MU_Pos)               /*!< 0x00000800 */

#define ERTC_ALA_MT_Pos                     (12U)
#define ERTC_ALA_MT_Msk                     (0x7U << ERTC_ALA_MT_Pos)               /*!< 0x00007000 */
#define ERTC_ALA_MT                         ERTC_ALA_MT_Msk                         /*!< MT[2:0] (Minute tens) */
#define ERTC_ALA_MT_0                       (0x1U << ERTC_ALA_MT_Pos)               /*!< 0x00001000 */
#define ERTC_ALA_MT_1                       (0x2U << ERTC_ALA_MT_Pos)               /*!< 0x00002000 */
#define ERTC_ALA_MT_2                       (0x4U << ERTC_ALA_MT_Pos)               /*!< 0x00004000 */

#define ERTC_ALA_MASK2_Pos                  (15U)
#define ERTC_ALA_MASK2_Msk                  (0x1U << ERTC_ALA_MASK2_Pos)            /*!< 0x00008000 */
#define ERTC_ALA_MASK2                      ERTC_ALA_MASK2_Msk                      /*!< Minute mask */

#define ERTC_ALA_HU_Pos                     (16U)
#define ERTC_ALA_HU_Msk                     (0xFU << ERTC_ALA_HU_Pos)               /*!< 0x000F0000 */
#define ERTC_ALA_HU                         ERTC_ALA_HU_Msk                         /*!< HU[3:0] (Hour units) */
#define ERTC_ALA_HU_0                       (0x1U << ERTC_ALA_HU_Pos)               /*!< 0x00010000 */
#define ERTC_ALA_HU_1                       (0x2U << ERTC_ALA_HU_Pos)               /*!< 0x00020000 */
#define ERTC_ALA_HU_2                       (0x4U << ERTC_ALA_HU_Pos)               /*!< 0x00040000 */
#define ERTC_ALA_HU_3                       (0x8U << ERTC_ALA_HU_Pos)               /*!< 0x00080000 */

#define ERTC_ALA_HT_Pos                     (20U)
#define ERTC_ALA_HT_Msk                     (0x3U << ERTC_ALA_HT_Pos)               /*!< 0x00300000 */
#define ERTC_ALA_HT                         ERTC_ALA_HT_Msk                         /*!< HT[1:0] (Hour tens) */
#define ERTC_ALA_HT_0                       (0x1U << ERTC_ALA_HT_Pos)               /*!< 0x00100000 */
#define ERTC_ALA_HT_1                       (0x2U << ERTC_ALA_HT_Pos)               /*!< 0x00200000 */

#define ERTC_ALA_AMPM_Pos                   (22U)
#define ERTC_ALA_AMPM_Msk                   (0x1U << ERTC_ALA_AMPM_Pos)             /*!< 0x00400000 */
#define ERTC_ALA_AMPM                       ERTC_ALA_AMPM_Msk                       /*!< AM/PM */
#define ERTC_ALA_MASK3_Pos                  (23U)
#define ERTC_ALA_MASK3_Msk                  (0x1U << ERTC_ALA_MASK3_Pos)            /*!< 0x00800000 */
#define ERTC_ALA_MASK3                      ERTC_ALA_MASK3_Msk                      /*!< Hour mask */

#define ERTC_ALA_DU_Pos                     (24U)
#define ERTC_ALA_DU_Msk                     (0xFU << ERTC_ALA_DU_Pos)               /*!< 0x0F000000 */
#define ERTC_ALA_DU                         ERTC_ALA_DU_Msk                         /*!< DU[3:0] (Date/week day units) */
#define ERTC_ALA_DU_0                       (0x1U << ERTC_ALA_DU_Pos)               /*!< 0x01000000 */
#define ERTC_ALA_DU_1                       (0x2U << ERTC_ALA_DU_Pos)               /*!< 0x02000000 */
#define ERTC_ALA_DU_2                       (0x4U << ERTC_ALA_DU_Pos)               /*!< 0x04000000 */
#define ERTC_ALA_DU_3                       (0x8U << ERTC_ALA_DU_Pos)               /*!< 0x08000000 */

#define ERTC_ALA_DT_Pos                     (28U)
#define ERTC_ALA_DT_Msk                     (0x3U << ERTC_ALA_DT_Pos)               /*!< 0x30000000 */
#define ERTC_ALA_DT                         ERTC_ALA_DT_Msk                         /*!< DT[1:0] (Date/week day tens) */
#define ERTC_ALA_DT_0                       (0x1U << ERTC_ALA_DT_Pos)               /*!< 0x10000000 */
#define ERTC_ALA_DT_1                       (0x2U << ERTC_ALA_DT_Pos)               /*!< 0x20000000 */

#define ERTC_ALA_WKSEL_Pos                  (30U)
#define ERTC_ALA_WKSEL_Msk                  (0x1U << ERTC_ALA_WKSEL_Pos)            /*!< 0x40000000 */
#define ERTC_ALA_WKSEL                      ERTC_ALA_WKSEL_Msk                      /*!< Date/week day select */
#define ERTC_ALA_MASK4_Pos                  (31U)
#define ERTC_ALA_MASK4_Msk                  (0x1U << ERTC_ALA_MASK4_Pos)            /*!< 0x80000000 */
#define ERTC_ALA_MASK4                      ERTC_ALA_MASK4_Msk                      /*!< Date/week day mask */

/*******************  Bit definition for ERTC_ALB register  *******************/
#define ERTC_ALB_SU_Pos                     (0U)
#define ERTC_ALB_SU_Msk                     (0xFU << ERTC_ALB_SU_Pos)               /*!< 0x0000000F */
#define ERTC_ALB_SU                         ERTC_ALB_SU_Msk                         /*!< SU[3:0] (Second units) */
#define ERTC_ALB_SU_0                       (0x1U << ERTC_ALB_SU_Pos)               /*!< 0x00000001 */
#define ERTC_ALB_SU_1                       (0x2U << ERTC_ALB_SU_Pos)               /*!< 0x00000002 */
#define ERTC_ALB_SU_2                       (0x4U << ERTC_ALB_SU_Pos)               /*!< 0x00000004 */
#define ERTC_ALB_SU_3                       (0x8U << ERTC_ALB_SU_Pos)               /*!< 0x00000008 */

#define ERTC_ALB_ST_Pos                     (4U)
#define ERTC_ALB_ST_Msk                     (0x7U << ERTC_ALB_ST_Pos)               /*!< 0x00000070 */
#define ERTC_ALB_ST                         ERTC_ALB_ST_Msk                         /*!< ST[2:0] (Second tens) */
#define ERTC_ALB_ST_0                       (0x1U << ERTC_ALB_ST_Pos)               /*!< 0x00000010 */
#define ERTC_ALB_ST_1                       (0x2U << ERTC_ALB_ST_Pos)               /*!< 0x00000020 */
#define ERTC_ALB_ST_2                       (0x4U << ERTC_ALB_ST_Pos)               /*!< 0x00000040 */

#define ERTC_ALB_MASK1_Pos                  (7U)
#define ERTC_ALB_MASK1_Msk                  (0x1U << ERTC_ALB_MASK1_Pos)            /*!< 0x00000080 */
#define ERTC_ALB_MASK1                      ERTC_ALB_MASK1_Msk                      /*!< Second mask */

#define ERTC_ALB_MU_Pos                     (8U)
#define ERTC_ALB_MU_Msk                     (0xFU << ERTC_ALB_MU_Pos)               /*!< 0x00000F00 */
#define ERTC_ALB_MU                         ERTC_ALB_MU_Msk                         /*!< MU[3:0] (Minute units) */
#define ERTC_ALB_MU_0                       (0x1U << ERTC_ALB_MU_Pos)               /*!< 0x00000100 */
#define ERTC_ALB_MU_1                       (0x2U << ERTC_ALB_MU_Pos)               /*!< 0x00000200 */
#define ERTC_ALB_MU_2                       (0x4U << ERTC_ALB_MU_Pos)               /*!< 0x00000400 */
#define ERTC_ALB_MU_3                       (0x8U << ERTC_ALB_MU_Pos)               /*!< 0x00000800 */

#define ERTC_ALB_MT_Pos                     (12U)
#define ERTC_ALB_MT_Msk                     (0x7U << ERTC_ALB_MT_Pos)               /*!< 0x00007000 */
#define ERTC_ALB_MT                         ERTC_ALB_MT_Msk                         /*!< MT[2:0] (Minute tens) */
#define ERTC_ALB_MT_0                       (0x1U << ERTC_ALB_MT_Pos)               /*!< 0x00001000 */
#define ERTC_ALB_MT_1                       (0x2U << ERTC_ALB_MT_Pos)               /*!< 0x00002000 */
#define ERTC_ALB_MT_2                       (0x4U << ERTC_ALB_MT_Pos)               /*!< 0x00004000 */

#define ERTC_ALB_MASK2_Pos                  (15U)
#define ERTC_ALB_MASK2_Msk                  (0x1U << ERTC_ALB_MASK2_Pos)            /*!< 0x00008000 */
#define ERTC_ALB_MASK2                      ERTC_ALB_MASK2_Msk                      /*!< Minute mask */

#define ERTC_ALB_HU_Pos                     (16U)
#define ERTC_ALB_HU_Msk                     (0xFU << ERTC_ALB_HU_Pos)               /*!< 0x000F0000 */
#define ERTC_ALB_HU                         ERTC_ALB_HU_Msk                         /*!< HU[3:0] (Hour units) */
#define ERTC_ALB_HU_0                       (0x1U << ERTC_ALB_HU_Pos)               /*!< 0x00010000 */
#define ERTC_ALB_HU_1                       (0x2U << ERTC_ALB_HU_Pos)               /*!< 0x00020000 */
#define ERTC_ALB_HU_2                       (0x4U << ERTC_ALB_HU_Pos)               /*!< 0x00040000 */
#define ERTC_ALB_HU_3                       (0x8U << ERTC_ALB_HU_Pos)               /*!< 0x00080000 */

#define ERTC_ALB_HT_Pos                     (20U)
#define ERTC_ALB_HT_Msk                     (0x3U << ERTC_ALB_HT_Pos)               /*!< 0x00300000 */
#define ERTC_ALB_HT                         ERTC_ALB_HT_Msk                         /*!< HT[1:0] (Hour tens) */
#define ERTC_ALB_HT_0                       (0x1U << ERTC_ALB_HT_Pos)               /*!< 0x00100000 */
#define ERTC_ALB_HT_1                       (0x2U << ERTC_ALB_HT_Pos)               /*!< 0x00200000 */

#define ERTC_ALB_AMPM_Pos                   (22U)
#define ERTC_ALB_AMPM_Msk                   (0x1U << ERTC_ALB_AMPM_Pos)             /*!< 0x00400000 */
#define ERTC_ALB_AMPM                       ERTC_ALB_AMPM_Msk                       /*!< AM/PM */
#define ERTC_ALB_MASK3_Pos                  (23U)
#define ERTC_ALB_MASK3_Msk                  (0x1U << ERTC_ALB_MASK3_Pos)            /*!< 0x00800000 */
#define ERTC_ALB_MASK3                      ERTC_ALB_MASK3_Msk                      /*!< Hour mask */

#define ERTC_ALB_DU_Pos                     (24U)
#define ERTC_ALB_DU_Msk                     (0xFU << ERTC_ALB_DU_Pos)               /*!< 0x0F000000 */
#define ERTC_ALB_DU                         ERTC_ALB_DU_Msk                         /*!< DU[3:0] (Date/week day units) */
#define ERTC_ALB_DU_0                       (0x1U << ERTC_ALB_DU_Pos)               /*!< 0x01000000 */
#define ERTC_ALB_DU_1                       (0x2U << ERTC_ALB_DU_Pos)               /*!< 0x02000000 */
#define ERTC_ALB_DU_2                       (0x4U << ERTC_ALB_DU_Pos)               /*!< 0x04000000 */
#define ERTC_ALB_DU_3                       (0x8U << ERTC_ALB_DU_Pos)               /*!< 0x08000000 */

#define ERTC_ALB_DT_Pos                     (28U)
#define ERTC_ALB_DT_Msk                     (0x3U << ERTC_ALB_DT_Pos)               /*!< 0x30000000 */
#define ERTC_ALB_DT                         ERTC_ALB_DT_Msk                         /*!< DT[1:0] (Date/week day tens) */
#define ERTC_ALB_DT_0                       (0x1U << ERTC_ALB_DT_Pos)               /*!< 0x10000000 */
#define ERTC_ALB_DT_1                       (0x2U << ERTC_ALB_DT_Pos)               /*!< 0x20000000 */

#define ERTC_ALB_WKSEL_Pos                  (30U)
#define ERTC_ALB_WKSEL_Msk                  (0x1U << ERTC_ALB_WKSEL_Pos)            /*!< 0x40000000 */
#define ERTC_ALB_WKSEL                      ERTC_ALB_WKSEL_Msk                      /*!< Date/week day select */
#define ERTC_ALB_MASK4_Pos                  (31U)
#define ERTC_ALB_MASK4_Msk                  (0x1U << ERTC_ALB_MASK4_Pos)            /*!< 0x80000000 */
#define ERTC_ALB_MASK4                      ERTC_ALB_MASK4_Msk                      /*!< Date/week day mask */

/*******************  Bit definition for ERTC_WP register  ********************/
#define ERTC_WP_CMD_Pos                     (0U)
#define ERTC_WP_CMD_Msk                     (0xFFU << ERTC_WP_CMD_Pos)              /*!< 0x000000FF */
#define ERTC_WP_CMD                         ERTC_WP_CMD_Msk                         /*!< Command register */

/*******************  Bit definition for ERTC_SBS register  *******************/
#define ERTC_SBS_SBS_Pos                    (0U)
#define ERTC_SBS_SBS_Msk                    (0xFFFFU << ERTC_SBS_SBS_Pos)           /*!< 0x0000FFFF */
#define ERTC_SBS_SBS                        ERTC_SBS_SBS_Msk                        /*!< Sub-second value */

/******************  Bit definition for ERTC_TADJ register  *******************/
#define ERTC_TADJ_DECSBS_Pos                (0U)
#define ERTC_TADJ_DECSBS_Msk                (0x7FFFU << ERTC_TADJ_DECSBS_Pos)       /*!< 0x00007FFF */
#define ERTC_TADJ_DECSBS                    ERTC_TADJ_DECSBS_Msk                    /*!< Decrease sub-second value */
#define ERTC_TADJ_ADD1S_Pos                 (31U)
#define ERTC_TADJ_ADD1S_Msk                 (0x1U << ERTC_TADJ_ADD1S_Pos)           /*!< 0x80000000 */
#define ERTC_TADJ_ADD1S                     ERTC_TADJ_ADD1S_Msk                     /*!< Add 1 second */

/******************  Bit definition for ERTC_TSTM register  *******************/
#define ERTC_TSTM_SU_Pos                    (0U)
#define ERTC_TSTM_SU_Msk                    (0xFU << ERTC_TSTM_SU_Pos)              /*!< 0x0000000F */
#define ERTC_TSTM_SU                        ERTC_TSTM_SU_Msk                        /*!< SU[3:0] (Second units) */
#define ERTC_TSTM_SU_0                      (0x1U << ERTC_TSTM_SU_Pos)              /*!< 0x00000001 */
#define ERTC_TSTM_SU_1                      (0x2U << ERTC_TSTM_SU_Pos)              /*!< 0x00000002 */
#define ERTC_TSTM_SU_2                      (0x4U << ERTC_TSTM_SU_Pos)              /*!< 0x00000004 */
#define ERTC_TSTM_SU_3                      (0x8U << ERTC_TSTM_SU_Pos)              /*!< 0x00000008 */

#define ERTC_TSTM_ST_Pos                    (4U)
#define ERTC_TSTM_ST_Msk                    (0x7U << ERTC_TSTM_ST_Pos)              /*!< 0x00000070 */
#define ERTC_TSTM_ST                        ERTC_TSTM_ST_Msk                        /*!< ST[2:0] (Second tens) */
#define ERTC_TSTM_ST_0                      (0x1U << ERTC_TSTM_ST_Pos)              /*!< 0x00000010 */
#define ERTC_TSTM_ST_1                      (0x2U << ERTC_TSTM_ST_Pos)              /*!< 0x00000020 */
#define ERTC_TSTM_ST_2                      (0x4U << ERTC_TSTM_ST_Pos)              /*!< 0x00000040 */

#define ERTC_TSTM_MU_Pos                    (8U)
#define ERTC_TSTM_MU_Msk                    (0xFU << ERTC_TSTM_MU_Pos)              /*!< 0x00000F00 */
#define ERTC_TSTM_MU                        ERTC_TSTM_MU_Msk                        /*!< MU[3:0] (Minute units) */
#define ERTC_TSTM_MU_0                      (0x1U << ERTC_TSTM_MU_Pos)              /*!< 0x00000100 */
#define ERTC_TSTM_MU_1                      (0x2U << ERTC_TSTM_MU_Pos)              /*!< 0x00000200 */
#define ERTC_TSTM_MU_2                      (0x4U << ERTC_TSTM_MU_Pos)              /*!< 0x00000400 */
#define ERTC_TSTM_MU_3                      (0x8U << ERTC_TSTM_MU_Pos)              /*!< 0x00000800 */

#define ERTC_TSTM_MT_Pos                    (12U)
#define ERTC_TSTM_MT_Msk                    (0x7U << ERTC_TSTM_MT_Pos)              /*!< 0x00007000 */
#define ERTC_TSTM_MT                        ERTC_TSTM_MT_Msk                        /*!< MT[2:0] (Minute tens) */
#define ERTC_TSTM_MT_0                      (0x1U << ERTC_TSTM_MT_Pos)              /*!< 0x00001000 */
#define ERTC_TSTM_MT_1                      (0x2U << ERTC_TSTM_MT_Pos)              /*!< 0x00002000 */
#define ERTC_TSTM_MT_2                      (0x4U << ERTC_TSTM_MT_Pos)              /*!< 0x00004000 */

#define ERTC_TSTM_HU_Pos                    (16U)
#define ERTC_TSTM_HU_Msk                    (0xFU << ERTC_TSTM_HU_Pos)              /*!< 0x000F0000 */
#define ERTC_TSTM_HU                        ERTC_TSTM_HU_Msk                        /*!< HU[3:0] (Hour units) */
#define ERTC_TSTM_HU_0                      (0x1U << ERTC_TSTM_HU_Pos)              /*!< 0x00010000 */
#define ERTC_TSTM_HU_1                      (0x2U << ERTC_TSTM_HU_Pos)              /*!< 0x00020000 */
#define ERTC_TSTM_HU_2                      (0x4U << ERTC_TSTM_HU_Pos)              /*!< 0x00040000 */
#define ERTC_TSTM_HU_3                      (0x8U << ERTC_TSTM_HU_Pos)              /*!< 0x00080000 */

#define ERTC_TSTM_HT_Pos                    (20U)
#define ERTC_TSTM_HT_Msk                    (0x3U << ERTC_TSTM_HT_Pos)              /*!< 0x00300000 */
#define ERTC_TSTM_HT                        ERTC_TSTM_HT_Msk                        /*!< HT[1:0] (Hour tens) */
#define ERTC_TSTM_HT_0                      (0x1U << ERTC_TSTM_HT_Pos)              /*!< 0x00100000 */
#define ERTC_TSTM_HT_1                      (0x2U << ERTC_TSTM_HT_Pos)              /*!< 0x00200000 */

#define ERTC_TSTM_AMPM_Pos                  (22U)
#define ERTC_TSTM_AMPM_Msk                  (0x1U << ERTC_TSTM_AMPM_Pos)            /*!< 0x00400000 */
#define ERTC_TSTM_AMPM                      ERTC_TSTM_AMPM_Msk                      /*!< AM/PM */

/******************  Bit definition for ERTC_TSDT register  *******************/
#define ERTC_TSDT_DU_Pos                    (0U)
#define ERTC_TSDT_DU_Msk                    (0xFU << ERTC_TSDT_DU_Pos)              /*!< 0x0000000F */
#define ERTC_TSDT_DU                        ERTC_TSDT_DU_Msk                        /*!< DU[3:0] (Date units) */
#define ERTC_TSDT_DU_0                      (0x1U << ERTC_TSDT_DU_Pos)              /*!< 0x00000001 */
#define ERTC_TSDT_DU_1                      (0x2U << ERTC_TSDT_DU_Pos)              /*!< 0x00000002 */
#define ERTC_TSDT_DU_2                      (0x4U << ERTC_TSDT_DU_Pos)              /*!< 0x00000004 */
#define ERTC_TSDT_DU_3                      (0x8U << ERTC_TSDT_DU_Pos)              /*!< 0x00000008 */

#define ERTC_TSDT_DT_Pos                    (4U)
#define ERTC_TSDT_DT_Msk                    (0x3U << ERTC_TSDT_DT_Pos)              /*!< 0x00000030 */
#define ERTC_TSDT_DT                        ERTC_TSDT_DT_Msk                        /*!< DT[1:0] (Date tens) */
#define ERTC_TSDT_DT_0                      (0x1U << ERTC_TSDT_DT_Pos)              /*!< 0x00000010 */
#define ERTC_TSDT_DT_1                      (0x2U << ERTC_TSDT_DT_Pos)              /*!< 0x00000020 */

#define ERTC_TSDT_MU_Pos                    (8U)
#define ERTC_TSDT_MU_Msk                    (0xFU << ERTC_TSDT_MU_Pos)              /*!< 0x00000F00 */
#define ERTC_TSDT_MU                        ERTC_TSDT_MU_Msk                        /*!< MU[3:0] (Month units) */
#define ERTC_TSDT_MU_0                      (0x1U << ERTC_TSDT_MU_Pos)              /*!< 0x00000100 */
#define ERTC_TSDT_MU_1                      (0x2U << ERTC_TSDT_MU_Pos)              /*!< 0x00000200 */
#define ERTC_TSDT_MU_2                      (0x4U << ERTC_TSDT_MU_Pos)              /*!< 0x00000400 */
#define ERTC_TSDT_MU_3                      (0x8U << ERTC_TSDT_MU_Pos)              /*!< 0x00000800 */

#define ERTC_TSDT_MT_Pos                    (12U)
#define ERTC_TSDT_MT_Msk                    (0x1U << ERTC_TSDT_MT_Pos)              /*!< 0x00001000 */
#define ERTC_TSDT_MT                        ERTC_TSDT_MT_Msk                        /*!< Month tens */

#define ERTC_TSDT_WK_Pos                    (13U)
#define ERTC_TSDT_WK_Msk                    (0x7U << ERTC_TSDT_WK_Pos)              /*!< 0x0000E000 */
#define ERTC_TSDT_WK                        ERTC_TSDT_WK_Msk                        /*!< WK[2:0] (Week day) */
#define ERTC_TSDT_WK_0                      (0x1U << ERTC_TSDT_WK_Pos)              /*!< 0x00002000 */
#define ERTC_TSDT_WK_1                      (0x2U << ERTC_TSDT_WK_Pos)              /*!< 0x00004000 */
#define ERTC_TSDT_WK_2                      (0x4U << ERTC_TSDT_WK_Pos)              /*!< 0x00008000 */

/******************  Bit definition for ERTC_TSSBS register  ******************/
#define ERTC_TSSBS_SBS_Pos                  (0U)
#define ERTC_TSSBS_SBS_Msk                  (0xFFFFU << ERTC_TSSBS_SBS_Pos)         /*!< 0x0000FFFF */
#define ERTC_TSSBS_SBS                      ERTC_TSSBS_SBS_Msk                      /*!< Sub-second value */

/******************  Bit definition for ERTC_SCAL register  *******************/
#define ERTC_SCAL_DEC_Pos                   (0U)
#define ERTC_SCAL_DEC_Msk                   (0x1FFU << ERTC_SCAL_DEC_Pos)           /*!< 0x000001FF */
#define ERTC_SCAL_DEC                       ERTC_SCAL_DEC_Msk                       /*!< Decrease ERTC clock */
#define ERTC_SCAL_CAL16_Pos                 (13U)
#define ERTC_SCAL_CAL16_Msk                 (0x1U << ERTC_SCAL_CAL16_Pos)           /*!< 0x00002000 */
#define ERTC_SCAL_CAL16                     ERTC_SCAL_CAL16_Msk                     /*!< 16 second calibration period */
#define ERTC_SCAL_CAL8_Pos                  (14U)
#define ERTC_SCAL_CAL8_Msk                  (0x1U << ERTC_SCAL_CAL8_Pos)            /*!< 0x00004000 */
#define ERTC_SCAL_CAL8                      ERTC_SCAL_CAL8_Msk                      /*!< 8 second calibration period */
#define ERTC_SCAL_ADD_Pos                   (15U)
#define ERTC_SCAL_ADD_Msk                   (0x1U << ERTC_SCAL_ADD_Pos)             /*!< 0x00008000 */
#define ERTC_SCAL_ADD                       ERTC_SCAL_ADD_Msk                       /*!< Add ERTC clock */

/******************  Bit definition for ERTC_TAMP register  *******************/
#define ERTC_TAMP_TP1EN_Pos                 (0U)
#define ERTC_TAMP_TP1EN_Msk                 (0x1U << ERTC_TAMP_TP1EN_Pos)           /*!< 0x00000001 */
#define ERTC_TAMP_TP1EN                     ERTC_TAMP_TP1EN_Msk                     /*!< Tamper detection 1 enable */
#define ERTC_TAMP_TP1EDG_Pos                (1U)
#define ERTC_TAMP_TP1EDG_Msk                (0x1U << ERTC_TAMP_TP1EDG_Pos)          /*!< 0x00000002 */
#define ERTC_TAMP_TP1EDG                    ERTC_TAMP_TP1EDG_Msk                    /*!< Tamper detection 1 valid edge */
#define ERTC_TAMP_TPIEN_Pos                 (2U)
#define ERTC_TAMP_TPIEN_Msk                 (0x1U << ERTC_TAMP_TPIEN_Pos)           /*!< 0x00000004 */
#define ERTC_TAMP_TPIEN                     ERTC_TAMP_TPIEN_Msk                     /*!< Tamper detection interrupt enable */
#define ERTC_TAMP_TPTSEN_Pos                (7U)
#define ERTC_TAMP_TPTSEN_Msk                (0x1U << ERTC_TAMP_TPTSEN_Pos)          /*!< 0x00000080 */
#define ERTC_TAMP_TPTSEN                    ERTC_TAMP_TPTSEN_Msk                    /*!< Tamper detection timestamp enable */

#define ERTC_TAMP_TPFREQ_Pos                (8U)
#define ERTC_TAMP_TPFREQ_Msk                (0x7U << ERTC_TAMP_TPFREQ_Pos)          /*!< 0x00000700 */
#define ERTC_TAMP_TPFREQ                    ERTC_TAMP_TPFREQ_Msk                    /*!< TPFREQ[2:0] (Tamper detection frequency) */
#define ERTC_TAMP_TPFREQ_0                  (0x1U << ERTC_TAMP_TPFREQ_Pos)          /*!< 0x00000100 */
#define ERTC_TAMP_TPFREQ_1                  (0x2U << ERTC_TAMP_TPFREQ_Pos)          /*!< 0x00000200 */
#define ERTC_TAMP_TPFREQ_2                  (0x4U << ERTC_TAMP_TPFREQ_Pos)          /*!< 0x00000400 */

#define ERTC_TAMP_TPFLT_Pos                 (11U)
#define ERTC_TAMP_TPFLT_Msk                 (0x3U << ERTC_TAMP_TPFLT_Pos)           /*!< 0x00001800 */
#define ERTC_TAMP_TPFLT                     ERTC_TAMP_TPFLT_Msk                     /*!< TPFLT[1:0] (Tamper detection filter time) */
#define ERTC_TAMP_TPFLT_0                   (0x1U << ERTC_TAMP_TPFLT_Pos)           /*!< 0x00000800 */
#define ERTC_TAMP_TPFLT_1                   (0x2U << ERTC_TAMP_TPFLT_Pos)           /*!< 0x00001000 */

#define ERTC_TAMP_TPPR_Pos                  (13U)
#define ERTC_TAMP_TPPR_Msk                  (0x3U << ERTC_TAMP_TPPR_Pos)            /*!< 0x00006000 */
#define ERTC_TAMP_TPPR                      ERTC_TAMP_TPPR_Msk                      /*!< TPPR[1:0] (Tamper detection pre-charge time) */
#define ERTC_TAMP_TPPR_0                    (0x1U << ERTC_TAMP_TPPR_Pos)            /*!< 0x00002000 */
#define ERTC_TAMP_TPPR_1                    (0x2U << ERTC_TAMP_TPPR_Pos)            /*!< 0x00004000 */

#define ERTC_TAMP_TPPU_Pos                  (15U)
#define ERTC_TAMP_TPPU_Msk                  (0x1U << ERTC_TAMP_TPPU_Pos)            /*!< 0x00008000 */
#define ERTC_TAMP_TPPU                      ERTC_TAMP_TPPU_Msk                      /*!< Tamper detection pull-up */
#define ERTC_TAMP_OUTTYPE_Pos               (18U)
#define ERTC_TAMP_OUTTYPE_Msk               (0x1U << ERTC_TAMP_OUTTYPE_Pos)         /*!< 0x00040000 */
#define ERTC_TAMP_OUTTYPE                   ERTC_TAMP_OUTTYPE_Msk                   /*!< Output type */

/*****************  Bit definition for ERTC_ALASBS register  ******************/
#define ERTC_ALASBS_SBS_Pos                 (0U)
#define ERTC_ALASBS_SBS_Msk                 (0x7FFFU << ERTC_ALASBS_SBS_Pos)        /*!< 0x00007FFF */
#define ERTC_ALASBS_SBS                     ERTC_ALASBS_SBS_Msk                     /*!< Sub-second value */

#define ERTC_ALASBS_SBSMSK_Pos              (24U)
#define ERTC_ALASBS_SBSMSK_Msk              (0xFU << ERTC_ALASBS_SBSMSK_Pos)        /*!< 0x0F000000 */
#define ERTC_ALASBS_SBSMSK                  ERTC_ALASBS_SBSMSK_Msk                  /*!< Sub-second mask */
#define ERTC_ALASBS_SBSMSK_0                (0x1U << ERTC_ALASBS_SBSMSK_Pos)        /*!< 0x01000000 */
#define ERTC_ALASBS_SBSMSK_1                (0x2U << ERTC_ALASBS_SBSMSK_Pos)        /*!< 0x02000000 */
#define ERTC_ALASBS_SBSMSK_2                (0x4U << ERTC_ALASBS_SBSMSK_Pos)        /*!< 0x04000000 */
#define ERTC_ALASBS_SBSMSK_3                (0x8U << ERTC_ALASBS_SBSMSK_Pos)        /*!< 0x08000000 */

/*****************  Bit definition for ERTC_ALBSBS register  ******************/
#define ERTC_ALBSBS_SBS_Pos                 (0U)
#define ERTC_ALBSBS_SBS_Msk                 (0x7FFFU << ERTC_ALBSBS_SBS_Pos)        /*!< 0x00007FFF */
#define ERTC_ALBSBS_SBS                     ERTC_ALBSBS_SBS_Msk                     /*!< Sub-second value */

#define ERTC_ALBSBS_SBSMSK_Pos              (24U)
#define ERTC_ALBSBS_SBSMSK_Msk              (0xFU << ERTC_ALBSBS_SBSMSK_Pos)        /*!< 0x0F000000 */
#define ERTC_ALBSBS_SBSMSK                  ERTC_ALBSBS_SBSMSK_Msk                  /*!< Sub-second mask */
#define ERTC_ALBSBS_SBSMSK_0                (0x1U << ERTC_ALBSBS_SBSMSK_Pos)        /*!< 0x01000000 */
#define ERTC_ALBSBS_SBSMSK_1                (0x2U << ERTC_ALBSBS_SBSMSK_Pos)        /*!< 0x02000000 */
#define ERTC_ALBSBS_SBSMSK_2                (0x4U << ERTC_ALBSBS_SBSMSK_Pos)        /*!< 0x04000000 */
#define ERTC_ALBSBS_SBSMSK_3                (0x8U << ERTC_ALBSBS_SBSMSK_Pos)        /*!< 0x08000000 */

/******************  Bit definition for ERTC_BPR1 register  *******************/
#define ERTC_BPR1_DT_Pos                    (0U)
#define ERTC_BPR1_DT_Msk                    (0xFFFFFFFFU << ERTC_BPR1_DT_Pos)       /*!< 0xFFFFFFFF */
#define ERTC_BPR1_DT                        ERTC_BPR1_DT_Msk                        /*!< Battery powered domain data 1 */

/******************  Bit definition for ERTC_BPR2 register  *******************/
#define ERTC_BPR2_DT_Pos                    (0U)
#define ERTC_BPR2_DT_Msk                    (0xFFFFFFFFU << ERTC_BPR2_DT_Pos)       /*!< 0xFFFFFFFF */
#define ERTC_BPR2_DT                        ERTC_BPR2_DT_Msk                        /*!< Battery powered domain data 2 */

/******************  Bit definition for ERTC_BPR3 register  *******************/
#define ERTC_BPR3_DT_Pos                    (0U)
#define ERTC_BPR3_DT_Msk                    (0xFFFFFFFFU << ERTC_BPR3_DT_Pos)       /*!< 0xFFFFFFFF */
#define ERTC_BPR3_DT                        ERTC_BPR3_DT_Msk                        /*!< Battery powered domain data 3 */

/******************  Bit definition for ERTC_BPR4 register  *******************/
#define ERTC_BPR4_DT_Pos                    (0U)
#define ERTC_BPR4_DT_Msk                    (0xFFFFFFFFU << ERTC_BPR4_DT_Pos)       /*!< 0xFFFFFFFF */
#define ERTC_BPR4_DT                        ERTC_BPR4_DT_Msk                        /*!< Battery powered domain data 4 */

/******************  Bit definition for ERTC_BPR5 register  *******************/
#define ERTC_BPR5_DT_Pos                    (0U)
#define ERTC_BPR5_DT_Msk                    (0xFFFFFFFFU << ERTC_BPR5_DT_Pos)       /*!< 0xFFFFFFFF */
#define ERTC_BPR5_DT                        ERTC_BPR5_DT_Msk                        /*!< Battery powered domain data 5 */

/******************  Bit definition for ERTC_BPR6 register  *******************/
#define ERTC_BPR6_DT_Pos                    (0U)
#define ERTC_BPR6_DT_Msk                    (0xFFFFFFFFU << ERTC_BPR6_DT_Pos)       /*!< 0xFFFFFFFF */
#define ERTC_BPR6_DT                        ERTC_BPR6_DT_Msk                        /*!< Battery powered domain data 6 */

/******************  Bit definition for ERTC_BPR7 register  *******************/
#define ERTC_BPR7_DT_Pos                    (0U)
#define ERTC_BPR7_DT_Msk                    (0xFFFFFFFFU << ERTC_BPR7_DT_Pos)       /*!< 0xFFFFFFFF */
#define ERTC_BPR7_DT                        ERTC_BPR7_DT_Msk                        /*!< Battery powered domain data 7 */

/******************  Bit definition for ERTC_BPR8 register  *******************/
#define ERTC_BPR8_DT_Pos                    (0U)
#define ERTC_BPR8_DT_Msk                    (0xFFFFFFFFU << ERTC_BPR8_DT_Pos)       /*!< 0xFFFFFFFF */
#define ERTC_BPR8_DT                        ERTC_BPR8_DT_Msk                        /*!< Battery powered domain data 8 */

/******************  Bit definition for ERTC_BPR9 register  *******************/
#define ERTC_BPR9_DT_Pos                    (0U)
#define ERTC_BPR9_DT_Msk                    (0xFFFFFFFFU << ERTC_BPR9_DT_Pos)       /*!< 0xFFFFFFFF */
#define ERTC_BPR9_DT                        ERTC_BPR9_DT_Msk                        /*!< Battery powered domain data 9 */

/******************  Bit definition for ERTC_BPR10 register  ******************/
#define ERTC_BPR10_DT_Pos                   (0U)
#define ERTC_BPR10_DT_Msk                   (0xFFFFFFFFU << ERTC_BPR10_DT_Pos)      /*!< 0xFFFFFFFF */
#define ERTC_BPR10_DT                       ERTC_BPR10_DT_Msk                       /*!< Battery powered domain data 10 */

/******************  Bit definition for ERTC_BPR11 register  ******************/
#define ERTC_BPR11_DT_Pos                   (0U)
#define ERTC_BPR11_DT_Msk                   (0xFFFFFFFFU << ERTC_BPR11_DT_Pos)      /*!< 0xFFFFFFFF */
#define ERTC_BPR11_DT                       ERTC_BPR11_DT_Msk                       /*!< Battery powered domain data 11 */

/******************  Bit definition for ERTC_BPR12 register  ******************/
#define ERTC_BPR12_DT_Pos                   (0U)
#define ERTC_BPR12_DT_Msk                   (0xFFFFFFFFU << ERTC_BPR12_DT_Pos)      /*!< 0xFFFFFFFF */
#define ERTC_BPR12_DT                       ERTC_BPR12_DT_Msk                       /*!< Battery powered domain data 12 */

/******************  Bit definition for ERTC_BPR13 register  ******************/
#define ERTC_BPR13_DT_Pos                   (0U)
#define ERTC_BPR13_DT_Msk                   (0xFFFFFFFFU << ERTC_BPR13_DT_Pos)      /*!< 0xFFFFFFFF */
#define ERTC_BPR13_DT                       ERTC_BPR13_DT_Msk                       /*!< Battery powered domain data 13 */

/******************  Bit definition for ERTC_BPR14 register  ******************/
#define ERTC_BPR14_DT_Pos                   (0U)
#define ERTC_BPR14_DT_Msk                   (0xFFFFFFFFU << ERTC_BPR14_DT_Pos)      /*!< 0xFFFFFFFF */
#define ERTC_BPR14_DT                       ERTC_BPR14_DT_Msk                       /*!< Battery powered domain data 14 */

/******************  Bit definition for ERTC_BPR15 register  ******************/
#define ERTC_BPR15_DT_Pos                   (0U)
#define ERTC_BPR15_DT_Msk                   (0xFFFFFFFFU << ERTC_BPR15_DT_Pos)      /*!< 0xFFFFFFFF */
#define ERTC_BPR15_DT                       ERTC_BPR15_DT_Msk                       /*!< Battery powered domain data 15 */

/******************  Bit definition for ERTC_BPR16 register  ******************/
#define ERTC_BPR16_DT_Pos                   (0U)
#define ERTC_BPR16_DT_Msk                   (0xFFFFFFFFU << ERTC_BPR16_DT_Pos)      /*!< 0xFFFFFFFF */
#define ERTC_BPR16_DT                       ERTC_BPR16_DT_Msk                       /*!< Battery powered domain data 16 */

/******************  Bit definition for ERTC_BPR17 register  ******************/
#define ERTC_BPR17_DT_Pos                   (0U)
#define ERTC_BPR17_DT_Msk                   (0xFFFFFFFFU << ERTC_BPR17_DT_Pos)      /*!< 0xFFFFFFFF */
#define ERTC_BPR17_DT                       ERTC_BPR17_DT_Msk                       /*!< Battery powered domain data 17 */

/******************  Bit definition for ERTC_BPR18 register  ******************/
#define ERTC_BPR18_DT_Pos                   (0U)
#define ERTC_BPR18_DT_Msk                   (0xFFFFFFFFU << ERTC_BPR18_DT_Pos)      /*!< 0xFFFFFFFF */
#define ERTC_BPR18_DT                       ERTC_BPR18_DT_Msk                       /*!< Battery powered domain data 18 */

/******************  Bit definition for ERTC_BPR19 register  ******************/
#define ERTC_BPR19_DT_Pos                   (0U)
#define ERTC_BPR19_DT_Msk                   (0xFFFFFFFFU << ERTC_BPR19_DT_Pos)      /*!< 0xFFFFFFFF */
#define ERTC_BPR19_DT                       ERTC_BPR19_DT_Msk                       /*!< Battery powered domain data 19 */

/******************  Bit definition for ERTC_BPR20 register  ******************/
#define ERTC_BPR20_DT_Pos                   (0U)
#define ERTC_BPR20_DT_Msk                   (0xFFFFFFFFU << ERTC_BPR20_DT_Pos)      /*!< 0xFFFFFFFF */
#define ERTC_BPR20_DT                       ERTC_BPR20_DT_Msk                       /*!< Battery powered domain data 20 */

/************************* Number of backup registers *************************/
#define ERTC_BPR_NUMBER                     0x000000014U

/******************************************************************************/
/*                                                                            */
/*                     Analog-to-digital converter (ADC)                      */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for ADC_STS register  ********************/
#define ADC_STS_VMOR_Pos                    (0U)
#define ADC_STS_VMOR_Msk                    (0x1U << ADC_STS_VMOR_Pos)              /*!< 0x00000001 */
#define ADC_STS_VMOR                        ADC_STS_VMOR_Msk                        /*!< Voltage monitoring out of range flag */
#define ADC_STS_OCCC_Pos                    (1U)
#define ADC_STS_OCCC_Msk                    (0x1U << ADC_STS_OCCC_Pos)              /*!< 0x00000002 */
#define ADC_STS_OCCC                        ADC_STS_OCCC_Msk                        /*!< End of conversion flag */
#define ADC_STS_PCCC_Pos                    (2U)
#define ADC_STS_PCCC_Msk                    (0x1U << ADC_STS_PCCC_Pos)              /*!< 0x00000004 */
#define ADC_STS_PCCC                        ADC_STS_PCCC_Msk                        /*!< Preempted channel end of conversion flag */
#define ADC_STS_PCCS_Pos                    (3U)
#define ADC_STS_PCCS_Msk                    (0x1U << ADC_STS_PCCS_Pos)              /*!< 0x00000008 */
#define ADC_STS_PCCS                        ADC_STS_PCCS_Msk                        /*!< Preempted channel conversion start flag */
#define ADC_STS_OCCS_Pos                    (4U)
#define ADC_STS_OCCS_Msk                    (0x1U << ADC_STS_OCCS_Pos)              /*!< 0x00000010 */
#define ADC_STS_OCCS                        ADC_STS_OCCS_Msk                        /*!< Ordinary channel conversion start flag */

/* Legacy defines */
#define ADC_STS_OCCE                        (ADC_STS_OCCC)
#define ADC_STS_PCCE                        (ADC_STS_PCCC)

/******************  Bit definition for ADC_CTRL1 register  *******************/
#define ADC_CTRL1_VMCSEL_Pos                (0U)
#define ADC_CTRL1_VMCSEL_Msk                (0x1FU << ADC_CTRL1_VMCSEL_Pos)         /*!< 0x0000001F */
#define ADC_CTRL1_VMCSEL                    ADC_CTRL1_VMCSEL_Msk                    /*!< VMCSEL[4:0] bits (Voltage monitoring channel select) */
#define ADC_CTRL1_VMCSEL_0                  (0x01U << ADC_CTRL1_VMCSEL_Pos)         /*!< 0x00000001 */
#define ADC_CTRL1_VMCSEL_1                  (0x02U << ADC_CTRL1_VMCSEL_Pos)         /*!< 0x00000002 */
#define ADC_CTRL1_VMCSEL_2                  (0x04U << ADC_CTRL1_VMCSEL_Pos)         /*!< 0x00000004 */
#define ADC_CTRL1_VMCSEL_3                  (0x08U << ADC_CTRL1_VMCSEL_Pos)         /*!< 0x00000008 */
#define ADC_CTRL1_VMCSEL_4                  (0x10U << ADC_CTRL1_VMCSEL_Pos)         /*!< 0x00000010 */

#define ADC_CTRL1_CCCIEN_Pos                (5U)
#define ADC_CTRL1_CCCIEN_Msk                (0x1U << ADC_CTRL1_CCCIEN_Pos)          /*!< 0x00000020 */
#define ADC_CTRL1_CCCIEN                    ADC_CTRL1_CCCIEN_Msk                    /*!< Channel conversion end interrupt enable */
#define ADC_CTRL1_VMORIEN_Pos               (6U)
#define ADC_CTRL1_VMORIEN_Msk               (0x1U << ADC_CTRL1_VMORIEN_Pos)         /*!< 0x00000040 */
#define ADC_CTRL1_VMORIEN                   ADC_CTRL1_VMORIEN_Msk                   /*!< Voltage monitoring out of range interrupt enable */
#define ADC_CTRL1_PCCCIEN_Pos               (7U)
#define ADC_CTRL1_PCCCIEN_Msk               (0x1U << ADC_CTRL1_PCCCIEN_Pos)         /*!< 0x00000080 */
#define ADC_CTRL1_PCCCIEN                   ADC_CTRL1_PCCCIEN_Msk                   /*!< Conversion end interrupt enable on Preempted channels */
#define ADC_CTRL1_SQEN_Pos                  (8U)
#define ADC_CTRL1_SQEN_Msk                  (0x1U << ADC_CTRL1_SQEN_Pos)            /*!< 0x00000100 */
#define ADC_CTRL1_SQEN                      ADC_CTRL1_SQEN_Msk                      /*!< Sequence mode enable */
#define ADC_CTRL1_VMSGEN_Pos                (9U)
#define ADC_CTRL1_VMSGEN_Msk                (0x1U << ADC_CTRL1_VMSGEN_Pos)          /*!< 0x00000200 */
#define ADC_CTRL1_VMSGEN                    ADC_CTRL1_VMSGEN_Msk                    /*!< Voltage monitoring enable on a single channel */
#define ADC_CTRL1_PCAUTOEN_Pos              (10U)
#define ADC_CTRL1_PCAUTOEN_Msk              (0x1U << ADC_CTRL1_PCAUTOEN_Pos)        /*!< 0x00000400 */
#define ADC_CTRL1_PCAUTOEN                  ADC_CTRL1_PCAUTOEN_Msk                  /*!< Preempted group automatic conversion enable after ordinary group */
#define ADC_CTRL1_OCPEN_Pos                 (11U)
#define ADC_CTRL1_OCPEN_Msk                 (0x1U << ADC_CTRL1_OCPEN_Pos)           /*!< 0x00000800 */
#define ADC_CTRL1_OCPEN                     ADC_CTRL1_OCPEN_Msk                     /*!< Partitioned mode enable on ordinary channels */
#define ADC_CTRL1_PCPEN_Pos                 (12U)
#define ADC_CTRL1_PCPEN_Msk                 (0x1U << ADC_CTRL1_PCPEN_Pos)           /*!< 0x00001000 */
#define ADC_CTRL1_PCPEN                     ADC_CTRL1_PCPEN_Msk                     /*!< Partitioned mode enable on preempted channels */

#define ADC_CTRL1_OCPCNT_Pos                (13U)
#define ADC_CTRL1_OCPCNT_Msk                (0x7U << ADC_CTRL1_OCPCNT_Pos)          /*!< 0x0000E000 */
#define ADC_CTRL1_OCPCNT                    ADC_CTRL1_OCPCNT_Msk                    /*!< OCPCNT[2:0] bits (Partitioned mode conversion count of ordinary channels) */
#define ADC_CTRL1_OCPCNT_0                  (0x1U << ADC_CTRL1_OCPCNT_Pos)          /*!< 0x00002000 */
#define ADC_CTRL1_OCPCNT_1                  (0x2U << ADC_CTRL1_OCPCNT_Pos)          /*!< 0x00004000 */
#define ADC_CTRL1_OCPCNT_2                  (0x4U << ADC_CTRL1_OCPCNT_Pos)          /*!< 0x00008000 */

#define ADC_CTRL1_PCVMEN_Pos                (22U)
#define ADC_CTRL1_PCVMEN_Msk                (0x1U << ADC_CTRL1_PCVMEN_Pos)          /*!< 0x00400000 */
#define ADC_CTRL1_PCVMEN                    ADC_CTRL1_PCVMEN_Msk                    /*!< Voltage monitoring enable on preempted channels */
#define ADC_CTRL1_OCVMEN_Pos                (23U)
#define ADC_CTRL1_OCVMEN_Msk                (0x1U << ADC_CTRL1_OCVMEN_Pos)          /*!< 0x00800000 */
#define ADC_CTRL1_OCVMEN                    ADC_CTRL1_OCVMEN_Msk                    /*!< Voltage monitoring enable on ordinary channels */

/* Legacy defines */
#define ADC_CTRL1_CCEIEN                    (ADC_CTRL1_CCCIEN)
#define ADC_CTRL1_PCCEIEN                   (ADC_CTRL1_PCCCIEN)

/******************  Bit definition for ADC_CTRL2 register  *******************/
#define ADC_CTRL2_ADCEN_Pos                 (0U)
#define ADC_CTRL2_ADCEN_Msk                 (0x1U << ADC_CTRL2_ADCEN_Pos)           /*!< 0x00000001 */
#define ADC_CTRL2_ADCEN                     ADC_CTRL2_ADCEN_Msk                     /*!< A/D converter enable */
#define ADC_CTRL2_RPEN_Pos                  (1U)
#define ADC_CTRL2_RPEN_Msk                  (0x1U << ADC_CTRL2_RPEN_Pos)            /*!< 0x00000002 */
#define ADC_CTRL2_RPEN                      ADC_CTRL2_RPEN_Msk                      /*!< Repition mode enable */
#define ADC_CTRL2_ADCAL_Pos                 (2U)
#define ADC_CTRL2_ADCAL_Msk                 (0x1U << ADC_CTRL2_ADCAL_Pos)           /*!< 0x00000004 */
#define ADC_CTRL2_ADCAL                     ADC_CTRL2_ADCAL_Msk                     /*!< A/D calibration */
#define ADC_CTRL2_ADCALINIT_Pos             (3U)
#define ADC_CTRL2_ADCALINIT_Msk             (0x1U << ADC_CTRL2_ADCALINIT_Pos)       /*!< 0x00000008 */
#define ADC_CTRL2_ADCALINIT                 ADC_CTRL2_ADCALINIT_Msk                 /*!< Initialize A/D calibration */
#define ADC_CTRL2_OCDMAEN_Pos               (8U)
#define ADC_CTRL2_OCDMAEN_Msk               (0x1U << ADC_CTRL2_OCDMAEN_Pos)         /*!< 0x00000100 */
#define ADC_CTRL2_OCDMAEN                   ADC_CTRL2_OCDMAEN_Msk                   /*!< DMA transfer enable of ordinary channels */
#define ADC_CTRL2_DTALIGN_Pos               (11U)
#define ADC_CTRL2_DTALIGN_Msk               (0x1U << ADC_CTRL2_DTALIGN_Pos)         /*!< 0x00000800 */
#define ADC_CTRL2_DTALIGN                   ADC_CTRL2_DTALIGN_Msk                   /*!< Data alignment */

/*!< PCTESEL configuration */
#define ADC_CTRL2_PCTESEL_Msk               ((0x7U << 12) | (0x1U << 24))           /*!< 0x01007000 */
#define ADC_CTRL2_PCTESEL                   ADC_CTRL2_PCTESEL_Msk                   /*!< PCTESEL[3:0] bits (Trigger event select for preempted channels conversion) */
#define ADC_CTRL2_PCTESEL_0                 (0x1U << 12)                            /*!< 0x00001000 */
#define ADC_CTRL2_PCTESEL_1                 (0x2U << 12)                            /*!< 0x00002000 */
#define ADC_CTRL2_PCTESEL_2                 (0x4U << 12)                            /*!< 0x00004000 */
#define ADC_CTRL2_PCTESEL_3                 (0x1U << 24)                            /*!< 0x01000000 */

#define ADC_CTRL2_PCTEN_Pos                 (15U)
#define ADC_CTRL2_PCTEN_Msk                 (0x1U << ADC_CTRL2_PCTEN_Pos)           /*!< 0x00008000 */
#define ADC_CTRL2_PCTEN                     ADC_CTRL2_PCTEN_Msk                     /*!< Trigger mode enable for preempted channels conversion */

/*!< OCTESEL configuration */
#define ADC_CTRL2_OCTESEL_Msk               ((0x7U << 17) | (0x1U << 25))           /*!< 0x020E0000 */
#define ADC_CTRL2_OCTESEL                   ADC_CTRL2_OCTESEL_Msk                   /*!< OCTESEL[3:0] bits (Trigger event select for ordinary channels conversion) */
#define ADC_CTRL2_OCTESEL_0                 (0x1U << 17)                            /*!< 0x00020000 */
#define ADC_CTRL2_OCTESEL_1                 (0x2U << 17)                            /*!< 0x00040000 */
#define ADC_CTRL2_OCTESEL_2                 (0x4U << 17)                            /*!< 0x00080000 */
#define ADC_CTRL2_OCTESEL_3                 (0x1U << 25)                            /*!< 0x02000000 */

#define ADC_CTRL2_OCTEN_Pos                 (20U)
#define ADC_CTRL2_OCTEN_Msk                 (0x1U << ADC_CTRL2_OCTEN_Pos)           /*!< 0x00100000 */
#define ADC_CTRL2_OCTEN                     ADC_CTRL2_OCTEN_Msk                     /*!< Trigger mode enable for ordinary channels conversion */
#define ADC_CTRL2_PCSWTRG_Pos               (21U)
#define ADC_CTRL2_PCSWTRG_Msk               (0x1U << ADC_CTRL2_PCSWTRG_Pos)         /*!< 0x00200000 */
#define ADC_CTRL2_PCSWTRG                   ADC_CTRL2_PCSWTRG_Msk                   /*!< Conversion of preempted channels triggered by software */
#define ADC_CTRL2_OCSWTRG_Pos               (22U)
#define ADC_CTRL2_OCSWTRG_Msk               (0x1U << ADC_CTRL2_OCSWTRG_Pos)         /*!< 0x00400000 */
#define ADC_CTRL2_OCSWTRG                   ADC_CTRL2_OCSWTRG_Msk                   /*!< Conversion of ordinary channels triggered by software */
#define ADC_CTRL2_ITSRVEN_Pos               (23U)
#define ADC_CTRL2_ITSRVEN_Msk               (0x1U << ADC_CTRL2_ITSRVEN_Pos)         /*!< 0x00800000 */
#define ADC_CTRL2_ITSRVEN                   ADC_CTRL2_ITSRVEN_Msk                   /*!< Internal temperature sensor and VINTRV enable */

/*******************  Bit definition for ADC_SPT1 register  *******************/
#define ADC_SPT1_CSPT10_Pos                 (0U)
#define ADC_SPT1_CSPT10_Msk                 (0x7U << ADC_SPT1_CSPT10_Pos)           /*!< 0x00000007 */
#define ADC_SPT1_CSPT10                     ADC_SPT1_CSPT10_Msk                     /*!< CSPT10[2:0] bits (Sample time selection of channel ADC_IN10) */
#define ADC_SPT1_CSPT10_0                   (0x1U << ADC_SPT1_CSPT10_Pos)           /*!< 0x00000001 */
#define ADC_SPT1_CSPT10_1                   (0x2U << ADC_SPT1_CSPT10_Pos)           /*!< 0x00000002 */
#define ADC_SPT1_CSPT10_2                   (0x4U << ADC_SPT1_CSPT10_Pos)           /*!< 0x00000004 */

#define ADC_SPT1_CSPT11_Pos                 (3U)
#define ADC_SPT1_CSPT11_Msk                 (0x7U << ADC_SPT1_CSPT11_Pos)           /*!< 0x00000038 */
#define ADC_SPT1_CSPT11                     ADC_SPT1_CSPT11_Msk                     /*!< CSPT11[2:0] bits (Sample time selection of channel ADC_IN11) */
#define ADC_SPT1_CSPT11_0                   (0x1U << ADC_SPT1_CSPT11_Pos)           /*!< 0x00000008 */
#define ADC_SPT1_CSPT11_1                   (0x2U << ADC_SPT1_CSPT11_Pos)           /*!< 0x00000010 */
#define ADC_SPT1_CSPT11_2                   (0x4U << ADC_SPT1_CSPT11_Pos)           /*!< 0x00000020 */

#define ADC_SPT1_CSPT12_Pos                 (6U)
#define ADC_SPT1_CSPT12_Msk                 (0x7U << ADC_SPT1_CSPT12_Pos)           /*!< 0x000001C0 */
#define ADC_SPT1_CSPT12                     ADC_SPT1_CSPT12_Msk                     /*!< CSPT12[2:0] bits (Sample time selection of channel ADC_IN12) */
#define ADC_SPT1_CSPT12_0                   (0x1U << ADC_SPT1_CSPT12_Pos)           /*!< 0x00000040 */
#define ADC_SPT1_CSPT12_1                   (0x2U << ADC_SPT1_CSPT12_Pos)           /*!< 0x00000080 */
#define ADC_SPT1_CSPT12_2                   (0x4U << ADC_SPT1_CSPT12_Pos)           /*!< 0x00000100 */

#define ADC_SPT1_CSPT13_Pos                 (9U)
#define ADC_SPT1_CSPT13_Msk                 (0x7U << ADC_SPT1_CSPT13_Pos)           /*!< 0x00000E00 */
#define ADC_SPT1_CSPT13                     ADC_SPT1_CSPT13_Msk                     /*!< CSPT13[2:0] bits (Sample time selection of channel ADC_IN13) */
#define ADC_SPT1_CSPT13_0                   (0x1U << ADC_SPT1_CSPT13_Pos)           /*!< 0x00000200 */
#define ADC_SPT1_CSPT13_1                   (0x2U << ADC_SPT1_CSPT13_Pos)           /*!< 0x00000400 */
#define ADC_SPT1_CSPT13_2                   (0x4U << ADC_SPT1_CSPT13_Pos)           /*!< 0x00000800 */

#define ADC_SPT1_CSPT14_Pos                 (12U)
#define ADC_SPT1_CSPT14_Msk                 (0x7U << ADC_SPT1_CSPT14_Pos)           /*!< 0x00007000 */
#define ADC_SPT1_CSPT14                     ADC_SPT1_CSPT14_Msk                     /*!< CSPT14[2:0] bits (Sample time selection of channel ADC_IN14) */
#define ADC_SPT1_CSPT14_0                   (0x1U << ADC_SPT1_CSPT14_Pos)           /*!< 0x00001000 */
#define ADC_SPT1_CSPT14_1                   (0x2U << ADC_SPT1_CSPT14_Pos)           /*!< 0x00002000 */
#define ADC_SPT1_CSPT14_2                   (0x4U << ADC_SPT1_CSPT14_Pos)           /*!< 0x00004000 */

#define ADC_SPT1_CSPT15_Pos                 (15U)
#define ADC_SPT1_CSPT15_Msk                 (0x7U << ADC_SPT1_CSPT15_Pos)           /*!< 0x00038000 */
#define ADC_SPT1_CSPT15                     ADC_SPT1_CSPT15_Msk                     /*!< CSPT15[2:0] bits (Sample time selection of channel ADC_IN15) */
#define ADC_SPT1_CSPT15_0                   (0x1U << ADC_SPT1_CSPT15_Pos)           /*!< 0x00008000 */
#define ADC_SPT1_CSPT15_1                   (0x2U << ADC_SPT1_CSPT15_Pos)           /*!< 0x00010000 */
#define ADC_SPT1_CSPT15_2                   (0x4U << ADC_SPT1_CSPT15_Pos)           /*!< 0x00020000 */

#define ADC_SPT1_CSPT16_Pos                 (18U)
#define ADC_SPT1_CSPT16_Msk                 (0x7U << ADC_SPT1_CSPT16_Pos)           /*!< 0x001C0000 */
#define ADC_SPT1_CSPT16                     ADC_SPT1_CSPT16_Msk                     /*!< CSPT16[2:0] bits (Sample time selection of channel ADC_IN16) */
#define ADC_SPT1_CSPT16_0                   (0x1U << ADC_SPT1_CSPT16_Pos)           /*!< 0x00040000 */
#define ADC_SPT1_CSPT16_1                   (0x2U << ADC_SPT1_CSPT16_Pos)           /*!< 0x00080000 */
#define ADC_SPT1_CSPT16_2                   (0x4U << ADC_SPT1_CSPT16_Pos)           /*!< 0x00100000 */

#define ADC_SPT1_CSPT17_Pos                 (21U)
#define ADC_SPT1_CSPT17_Msk                 (0x7U << ADC_SPT1_CSPT17_Pos)           /*!< 0x00E00000 */
#define ADC_SPT1_CSPT17                     ADC_SPT1_CSPT17_Msk                     /*!< CSPT17[2:0] bits (Sample time selection of channel ADC_IN17) */
#define ADC_SPT1_CSPT17_0                   (0x1U << ADC_SPT1_CSPT17_Pos)           /*!< 0x00200000 */
#define ADC_SPT1_CSPT17_1                   (0x2U << ADC_SPT1_CSPT17_Pos)           /*!< 0x00400000 */
#define ADC_SPT1_CSPT17_2                   (0x4U << ADC_SPT1_CSPT17_Pos)           /*!< 0x00800000 */

/*******************  Bit definition for ADC_SPT2 register  *******************/
#define ADC_SPT2_CSPT0_Pos                  (0U)
#define ADC_SPT2_CSPT0_Msk                  (0x7U << ADC_SPT2_CSPT0_Pos)            /*!< 0x00000007 */
#define ADC_SPT2_CSPT0                      ADC_SPT2_CSPT0_Msk                      /*!< CSPT0[2:0] bits (Sample time selection of channel ADC_IN0) */
#define ADC_SPT2_CSPT0_0                    (0x1U << ADC_SPT2_CSPT0_Pos)            /*!< 0x00000001 */
#define ADC_SPT2_CSPT0_1                    (0x2U << ADC_SPT2_CSPT0_Pos)            /*!< 0x00000002 */
#define ADC_SPT2_CSPT0_2                    (0x4U << ADC_SPT2_CSPT0_Pos)            /*!< 0x00000004 */

#define ADC_SPT2_CSPT1_Pos                  (3U)
#define ADC_SPT2_CSPT1_Msk                  (0x7U << ADC_SPT2_CSPT1_Pos)            /*!< 0x00000038 */
#define ADC_SPT2_CSPT1                      ADC_SPT2_CSPT1_Msk                      /*!< CSPT1[2:0] bits (Sample time selection of channel ADC_IN1) */
#define ADC_SPT2_CSPT1_0                    (0x1U << ADC_SPT2_CSPT1_Pos)            /*!< 0x00000008 */
#define ADC_SPT2_CSPT1_1                    (0x2U << ADC_SPT2_CSPT1_Pos)            /*!< 0x00000010 */
#define ADC_SPT2_CSPT1_2                    (0x4U << ADC_SPT2_CSPT1_Pos)            /*!< 0x00000020 */

#define ADC_SPT2_CSPT2_Pos                  (6U)
#define ADC_SPT2_CSPT2_Msk                  (0x7U << ADC_SPT2_CSPT2_Pos)            /*!< 0x000001C0 */
#define ADC_SPT2_CSPT2                      ADC_SPT2_CSPT2_Msk                      /*!< CSPT2[2:0] bits (Sample time selection of channel ADC_IN2) */
#define ADC_SPT2_CSPT2_0                    (0x1U << ADC_SPT2_CSPT2_Pos)            /*!< 0x00000040 */
#define ADC_SPT2_CSPT2_1                    (0x2U << ADC_SPT2_CSPT2_Pos)            /*!< 0x00000080 */
#define ADC_SPT2_CSPT2_2                    (0x4U << ADC_SPT2_CSPT2_Pos)            /*!< 0x00000100 */

#define ADC_SPT2_CSPT3_Pos                  (9U)
#define ADC_SPT2_CSPT3_Msk                  (0x7U << ADC_SPT2_CSPT3_Pos)            /*!< 0x00000E00 */
#define ADC_SPT2_CSPT3                      ADC_SPT2_CSPT3_Msk                      /*!< CSPT3[2:0] bits (Sample time selection of channel ADC_IN3) */
#define ADC_SPT2_CSPT3_0                    (0x1U << ADC_SPT2_CSPT3_Pos)            /*!< 0x00000200 */
#define ADC_SPT2_CSPT3_1                    (0x2U << ADC_SPT2_CSPT3_Pos)            /*!< 0x00000400 */
#define ADC_SPT2_CSPT3_2                    (0x4U << ADC_SPT2_CSPT3_Pos)            /*!< 0x00000800 */

#define ADC_SPT2_CSPT4_Pos                  (12U)
#define ADC_SPT2_CSPT4_Msk                  (0x7U << ADC_SPT2_CSPT4_Pos)            /*!< 0x00007000 */
#define ADC_SPT2_CSPT4                      ADC_SPT2_CSPT4_Msk                      /*!< CSPT4[2:0] bits (Sample time selection of channel ADC_IN4) */
#define ADC_SPT2_CSPT4_0                    (0x1U << ADC_SPT2_CSPT4_Pos)            /*!< 0x00001000 */
#define ADC_SPT2_CSPT4_1                    (0x2U << ADC_SPT2_CSPT4_Pos)            /*!< 0x00002000 */
#define ADC_SPT2_CSPT4_2                    (0x4U << ADC_SPT2_CSPT4_Pos)            /*!< 0x00004000 */

#define ADC_SPT2_CSPT5_Pos                  (15U)
#define ADC_SPT2_CSPT5_Msk                  (0x7U << ADC_SPT2_CSPT5_Pos)            /*!< 0x00038000 */
#define ADC_SPT2_CSPT5                      ADC_SPT2_CSPT5_Msk                      /*!< CSPT5[2:0] bits (Sample time selection of channel ADC_IN5) */
#define ADC_SPT2_CSPT5_0                    (0x1U << ADC_SPT2_CSPT5_Pos)            /*!< 0x00008000 */
#define ADC_SPT2_CSPT5_1                    (0x2U << ADC_SPT2_CSPT5_Pos)            /*!< 0x00010000 */
#define ADC_SPT2_CSPT5_2                    (0x4U << ADC_SPT2_CSPT5_Pos)            /*!< 0x00020000 */

#define ADC_SPT2_CSPT6_Pos                  (18U)
#define ADC_SPT2_CSPT6_Msk                  (0x7U << ADC_SPT2_CSPT6_Pos)            /*!< 0x001C0000 */
#define ADC_SPT2_CSPT6                      ADC_SPT2_CSPT6_Msk                      /*!< CSPT6[2:0] bits (Sample time selection of channel ADC_IN6) */
#define ADC_SPT2_CSPT6_0                    (0x1U << ADC_SPT2_CSPT6_Pos)            /*!< 0x00040000 */
#define ADC_SPT2_CSPT6_1                    (0x2U << ADC_SPT2_CSPT6_Pos)            /*!< 0x00080000 */
#define ADC_SPT2_CSPT6_2                    (0x4U << ADC_SPT2_CSPT6_Pos)            /*!< 0x00100000 */

#define ADC_SPT2_CSPT7_Pos                  (21U)
#define ADC_SPT2_CSPT7_Msk                  (0x7U << ADC_SPT2_CSPT7_Pos)            /*!< 0x00E00000 */
#define ADC_SPT2_CSPT7                      ADC_SPT2_CSPT7_Msk                      /*!< CSPT7[2:0] bits (Sample time selection of channel ADC_IN7) */
#define ADC_SPT2_CSPT7_0                    (0x1U << ADC_SPT2_CSPT7_Pos)            /*!< 0x00200000 */
#define ADC_SPT2_CSPT7_1                    (0x2U << ADC_SPT2_CSPT7_Pos)            /*!< 0x00400000 */
#define ADC_SPT2_CSPT7_2                    (0x4U << ADC_SPT2_CSPT7_Pos)            /*!< 0x00800000 */

#define ADC_SPT2_CSPT8_Pos                  (24U)
#define ADC_SPT2_CSPT8_Msk                  (0x7U << ADC_SPT2_CSPT8_Pos)            /*!< 0x07000000 */
#define ADC_SPT2_CSPT8                      ADC_SPT2_CSPT8_Msk                      /*!< CSPT8[2:0] bits (Sample time selection of channel ADC_IN8) */
#define ADC_SPT2_CSPT8_0                    (0x1U << ADC_SPT2_CSPT8_Pos)            /*!< 0x01000000 */
#define ADC_SPT2_CSPT8_1                    (0x2U << ADC_SPT2_CSPT8_Pos)            /*!< 0x02000000 */
#define ADC_SPT2_CSPT8_2                    (0x4U << ADC_SPT2_CSPT8_Pos)            /*!< 0x04000000 */

#define ADC_SPT2_CSPT9_Pos                  (27U)
#define ADC_SPT2_CSPT9_Msk                  (0x7U << ADC_SPT2_CSPT9_Pos)            /*!< 0x38000000 */
#define ADC_SPT2_CSPT9                      ADC_SPT2_CSPT9_Msk                      /*!< CSPT9[2:0] bits (Sample time selection of channel ADC_IN9) */
#define ADC_SPT2_CSPT9_0                    (0x1U << ADC_SPT2_CSPT9_Pos)            /*!< 0x08000000 */
#define ADC_SPT2_CSPT9_1                    (0x2U << ADC_SPT2_CSPT9_Pos)            /*!< 0x10000000 */
#define ADC_SPT2_CSPT9_2                    (0x4U << ADC_SPT2_CSPT9_Pos)            /*!< 0x20000000 */

/******************  Bit definition for ADC_PCDTO1 register  ******************/
#define ADC_PCDTO1_PCDTO1_Pos               (0U)
#define ADC_PCDTO1_PCDTO1_Msk               (0xFFFU << ADC_PCDTO1_PCDTO1_Pos)       /*!< 0x00000FFF */
#define ADC_PCDTO1_PCDTO1                   ADC_PCDTO1_PCDTO1_Msk                   /*!< Data offset for Preempted channel 1 */

/******************  Bit definition for ADC_PCDTO2 register  ******************/
#define ADC_PCDTO2_PCDTO2_Pos               (0U)
#define ADC_PCDTO2_PCDTO2_Msk               (0xFFFU << ADC_PCDTO2_PCDTO2_Pos)       /*!< 0x00000FFF */
#define ADC_PCDTO2_PCDTO2                   ADC_PCDTO2_PCDTO2_Msk                   /*!< Data offset for Preempted channel 2 */

/******************  Bit definition for ADC_PCDTO3 register  ******************/
#define ADC_PCDTO3_PCDTO3_Pos               (0U)
#define ADC_PCDTO3_PCDTO3_Msk               (0xFFFU << ADC_PCDTO3_PCDTO3_Pos)       /*!< 0x00000FFF */
#define ADC_PCDTO3_PCDTO3                   ADC_PCDTO3_PCDTO3_Msk                   /*!< Data offset for Preempted channel 3 */

/******************  Bit definition for ADC_PCDTO4 register  ******************/
#define ADC_PCDTO4_PCDTO4_Pos               (0U)
#define ADC_PCDTO4_PCDTO4_Msk               (0xFFFU << ADC_PCDTO4_PCDTO4_Pos)       /*!< 0x00000FFF */
#define ADC_PCDTO4_PCDTO4                   ADC_PCDTO4_PCDTO4_Msk                   /*!< Data offset for Preempted channel 4 */

/*******************  Bit definition for ADC_VMHB register  ********************/
#define ADC_VMHB_VMHB_Pos                   (0U)
#define ADC_VMHB_VMHB_Msk                   (0xFFFU << ADC_VMHB_VMHB_Pos)           /*!< 0x00000FFF */
#define ADC_VMHB_VMHB                       ADC_VMHB_VMHB_Msk                       /*!< Voltage monitoring high boundary */

/*******************  Bit definition for ADC_VMLB register  ********************/
#define ADC_VMLB_VMLB_Pos                   (0U)
#define ADC_VMLB_VMLB_Msk                   (0xFFFU << ADC_VMLB_VMLB_Pos)           /*!< 0x00000FFF */
#define ADC_VMLB_VMLB                       ADC_VMLB_VMLB_Msk                       /*!< Voltage monitoring low boundary */

/*******************  Bit definition for ADC_OSQ1 register  *******************/
#define ADC_OSQ1_OSN13_Pos                  (0U)
#define ADC_OSQ1_OSN13_Msk                  (0x1FU << ADC_OSQ1_OSN13_Pos)           /*!< 0x0000001F */
#define ADC_OSQ1_OSN13                      ADC_OSQ1_OSN13_Msk                      /*!< OSN13[4:0] bits (Number of 13th conversion in ordinary sequence) */
#define ADC_OSQ1_OSN13_0                    (0x01U << ADC_OSQ1_OSN13_Pos)           /*!< 0x00000001 */
#define ADC_OSQ1_OSN13_1                    (0x02U << ADC_OSQ1_OSN13_Pos)           /*!< 0x00000002 */
#define ADC_OSQ1_OSN13_2                    (0x04U << ADC_OSQ1_OSN13_Pos)           /*!< 0x00000004 */
#define ADC_OSQ1_OSN13_3                    (0x08U << ADC_OSQ1_OSN13_Pos)           /*!< 0x00000008 */
#define ADC_OSQ1_OSN13_4                    (0x10U << ADC_OSQ1_OSN13_Pos)           /*!< 0x00000010 */

#define ADC_OSQ1_OSN14_Pos                  (5U)
#define ADC_OSQ1_OSN14_Msk                  (0x1FU << ADC_OSQ1_OSN14_Pos)           /*!< 0x000003E0 */
#define ADC_OSQ1_OSN14                      ADC_OSQ1_OSN14_Msk                      /*!< OSN14[4:0] bits (Number of 14th conversion in ordinary sequence) */
#define ADC_OSQ1_OSN14_0                    (0x01U << ADC_OSQ1_OSN14_Pos)           /*!< 0x00000020 */
#define ADC_OSQ1_OSN14_1                    (0x02U << ADC_OSQ1_OSN14_Pos)           /*!< 0x00000040 */
#define ADC_OSQ1_OSN14_2                    (0x04U << ADC_OSQ1_OSN14_Pos)           /*!< 0x00000080 */
#define ADC_OSQ1_OSN14_3                    (0x08U << ADC_OSQ1_OSN14_Pos)           /*!< 0x00000100 */
#define ADC_OSQ1_OSN14_4                    (0x10U << ADC_OSQ1_OSN14_Pos)           /*!< 0x00000200 */

#define ADC_OSQ1_OSN15_Pos                  (10U)
#define ADC_OSQ1_OSN15_Msk                  (0x1FU << ADC_OSQ1_OSN15_Pos)           /*!< 0x00007C00 */
#define ADC_OSQ1_OSN15                      ADC_OSQ1_OSN15_Msk                      /*!< OSN15[4:0] bits (Number of 15th conversion in ordinary sequence) */
#define ADC_OSQ1_OSN15_0                    (0x01U << ADC_OSQ1_OSN15_Pos)           /*!< 0x00000400 */
#define ADC_OSQ1_OSN15_1                    (0x02U << ADC_OSQ1_OSN15_Pos)           /*!< 0x00000800 */
#define ADC_OSQ1_OSN15_2                    (0x04U << ADC_OSQ1_OSN15_Pos)           /*!< 0x00001000 */
#define ADC_OSQ1_OSN15_3                    (0x08U << ADC_OSQ1_OSN15_Pos)           /*!< 0x00002000 */
#define ADC_OSQ1_OSN15_4                    (0x10U << ADC_OSQ1_OSN15_Pos)           /*!< 0x00004000 */

#define ADC_OSQ1_OSN16_Pos                  (15U)
#define ADC_OSQ1_OSN16_Msk                  (0x1FU << ADC_OSQ1_OSN16_Pos)           /*!< 0x000F8000 */
#define ADC_OSQ1_OSN16                      ADC_OSQ1_OSN16_Msk                      /*!< OSN16[4:0] bits (Number of 16th conversion in ordinary sequence) */
#define ADC_OSQ1_OSN16_0                    (0x01U << ADC_OSQ1_OSN16_Pos)           /*!< 0x00008000 */
#define ADC_OSQ1_OSN16_1                    (0x02U << ADC_OSQ1_OSN16_Pos)           /*!< 0x00010000 */
#define ADC_OSQ1_OSN16_2                    (0x04U << ADC_OSQ1_OSN16_Pos)           /*!< 0x00020000 */
#define ADC_OSQ1_OSN16_3                    (0x08U << ADC_OSQ1_OSN16_Pos)           /*!< 0x00040000 */
#define ADC_OSQ1_OSN16_4                    (0x10U << ADC_OSQ1_OSN16_Pos)           /*!< 0x00080000 */

#define ADC_OSQ1_OCLEN_Pos                  (20U)
#define ADC_OSQ1_OCLEN_Msk                  (0xFU << ADC_OSQ1_OCLEN_Pos)            /*!< 0x00F00000 */
#define ADC_OSQ1_OCLEN                      ADC_OSQ1_OCLEN_Msk                      /*!< OCLEN[3:0] bits (Ordinary conversion sequence length) */
#define ADC_OSQ1_OCLEN_0                    (0x1U << ADC_OSQ1_OCLEN_Pos)            /*!< 0x00100000 */
#define ADC_OSQ1_OCLEN_1                    (0x2U << ADC_OSQ1_OCLEN_Pos)            /*!< 0x00200000 */
#define ADC_OSQ1_OCLEN_2                    (0x4U << ADC_OSQ1_OCLEN_Pos)            /*!< 0x00400000 */
#define ADC_OSQ1_OCLEN_3                    (0x8U << ADC_OSQ1_OCLEN_Pos)            /*!< 0x00800000 */

/*******************  Bit definition for ADC_OSQ2 register  *******************/
#define ADC_OSQ2_OSN7_Pos                   (0U)
#define ADC_OSQ2_OSN7_Msk                   (0x1FU << ADC_OSQ2_OSN7_Pos)            /*!< 0x0000001F */
#define ADC_OSQ2_OSN7                       ADC_OSQ2_OSN7_Msk                       /*!< OSN7[4:0] bits (Number of 7th conversion in ordinary sequence) */
#define ADC_OSQ2_OSN7_0                     (0x01U << ADC_OSQ2_OSN7_Pos)            /*!< 0x00000001 */
#define ADC_OSQ2_OSN7_1                     (0x02U << ADC_OSQ2_OSN7_Pos)            /*!< 0x00000002 */
#define ADC_OSQ2_OSN7_2                     (0x04U << ADC_OSQ2_OSN7_Pos)            /*!< 0x00000004 */
#define ADC_OSQ2_OSN7_3                     (0x08U << ADC_OSQ2_OSN7_Pos)            /*!< 0x00000008 */
#define ADC_OSQ2_OSN7_4                     (0x10U << ADC_OSQ2_OSN7_Pos)            /*!< 0x00000010 */

#define ADC_OSQ2_OSN8_Pos                   (5U)
#define ADC_OSQ2_OSN8_Msk                   (0x1FU << ADC_OSQ2_OSN8_Pos)            /*!< 0x000003E0 */
#define ADC_OSQ2_OSN8                       ADC_OSQ2_OSN8_Msk                       /*!< OSN8[4:0] bits (Number of 8th conversion in ordinary sequence) */
#define ADC_OSQ2_OSN8_0                     (0x01U << ADC_OSQ2_OSN8_Pos)            /*!< 0x00000020 */
#define ADC_OSQ2_OSN8_1                     (0x02U << ADC_OSQ2_OSN8_Pos)            /*!< 0x00000040 */
#define ADC_OSQ2_OSN8_2                     (0x04U << ADC_OSQ2_OSN8_Pos)            /*!< 0x00000080 */
#define ADC_OSQ2_OSN8_3                     (0x08U << ADC_OSQ2_OSN8_Pos)            /*!< 0x00000100 */
#define ADC_OSQ2_OSN8_4                     (0x10U << ADC_OSQ2_OSN8_Pos)            /*!< 0x00000200 */

#define ADC_OSQ2_OSN9_Pos                   (10U)
#define ADC_OSQ2_OSN9_Msk                   (0x1FU << ADC_OSQ2_OSN9_Pos)            /*!< 0x00007C00 */
#define ADC_OSQ2_OSN9                       ADC_OSQ2_OSN9_Msk                       /*!< OSN9[4:0] bits (Number of 9th conversion in ordinary sequence) */
#define ADC_OSQ2_OSN9_0                     (0x01U << ADC_OSQ2_OSN9_Pos)            /*!< 0x00000400 */
#define ADC_OSQ2_OSN9_1                     (0x02U << ADC_OSQ2_OSN9_Pos)            /*!< 0x00000800 */
#define ADC_OSQ2_OSN9_2                     (0x04U << ADC_OSQ2_OSN9_Pos)            /*!< 0x00001000 */
#define ADC_OSQ2_OSN9_3                     (0x08U << ADC_OSQ2_OSN9_Pos)            /*!< 0x00002000 */
#define ADC_OSQ2_OSN9_4                     (0x10U << ADC_OSQ2_OSN9_Pos)            /*!< 0x00004000 */

#define ADC_OSQ2_OSN10_Pos                  (15U)
#define ADC_OSQ2_OSN10_Msk                  (0x1FU << ADC_OSQ2_OSN10_Pos)           /*!< 0x000F8000 */
#define ADC_OSQ2_OSN10                      ADC_OSQ2_OSN10_Msk                      /*!< OSN10[4:0] bits (Number of 10th conversion in ordinary sequence) */
#define ADC_OSQ2_OSN10_0                    (0x01U << ADC_OSQ2_OSN10_Pos)           /*!< 0x00008000 */
#define ADC_OSQ2_OSN10_1                    (0x02U << ADC_OSQ2_OSN10_Pos)           /*!< 0x00010000 */
#define ADC_OSQ2_OSN10_2                    (0x04U << ADC_OSQ2_OSN10_Pos)           /*!< 0x00020000 */
#define ADC_OSQ2_OSN10_3                    (0x08U << ADC_OSQ2_OSN10_Pos)           /*!< 0x00040000 */
#define ADC_OSQ2_OSN10_4                    (0x10U << ADC_OSQ2_OSN10_Pos)           /*!< 0x00080000 */

#define ADC_OSQ2_OSN11_Pos                  (20U)
#define ADC_OSQ2_OSN11_Msk                  (0x1FU << ADC_OSQ2_OSN11_Pos)           /*!< 0x01F00000 */
#define ADC_OSQ2_OSN11                      ADC_OSQ2_OSN11_Msk                      /*!< OSN11[4:0] bits (Number of 11th conversion in ordinary sequence) */
#define ADC_OSQ2_OSN11_0                    (0x01U << ADC_OSQ2_OSN11_Pos)           /*!< 0x00100000 */
#define ADC_OSQ2_OSN11_1                    (0x02U << ADC_OSQ2_OSN11_Pos)           /*!< 0x00200000 */
#define ADC_OSQ2_OSN11_2                    (0x04U << ADC_OSQ2_OSN11_Pos)           /*!< 0x00400000 */
#define ADC_OSQ2_OSN11_3                    (0x08U << ADC_OSQ2_OSN11_Pos)           /*!< 0x00800000 */
#define ADC_OSQ2_OSN11_4                    (0x10U << ADC_OSQ2_OSN11_Pos)           /*!< 0x01000000 */

#define ADC_OSQ2_OSN12_Pos                  (25U)
#define ADC_OSQ2_OSN12_Msk                  (0x1FU << ADC_OSQ2_OSN12_Pos)           /*!< 0x3E000000 */
#define ADC_OSQ2_OSN12                      ADC_OSQ2_OSN12_Msk                      /*!< OSN12[4:0] bits (Number of 12th conversion in ordinary sequence) */
#define ADC_OSQ2_OSN12_0                    (0x01U << ADC_OSQ2_OSN12_Pos)           /*!< 0x02000000 */
#define ADC_OSQ2_OSN12_1                    (0x02U << ADC_OSQ2_OSN12_Pos)           /*!< 0x04000000 */
#define ADC_OSQ2_OSN12_2                    (0x04U << ADC_OSQ2_OSN12_Pos)           /*!< 0x08000000 */
#define ADC_OSQ2_OSN12_3                    (0x08U << ADC_OSQ2_OSN12_Pos)           /*!< 0x10000000 */
#define ADC_OSQ2_OSN12_4                    (0x10U << ADC_OSQ2_OSN12_Pos)           /*!< 0x20000000 */

/*******************  Bit definition for ADC_OSQ3 register  *******************/
#define ADC_OSQ3_OSN1_Pos                   (0U)
#define ADC_OSQ3_OSN1_Msk                   (0x1FU << ADC_OSQ3_OSN1_Pos)            /*!< 0x0000001F */
#define ADC_OSQ3_OSN1                       ADC_OSQ3_OSN1_Msk                       /*!< OSN1[4:0] bits (Number of 1st conversion in ordinary sequence) */
#define ADC_OSQ3_OSN1_0                     (0x01U << ADC_OSQ3_OSN1_Pos)            /*!< 0x00000001 */
#define ADC_OSQ3_OSN1_1                     (0x02U << ADC_OSQ3_OSN1_Pos)            /*!< 0x00000002 */
#define ADC_OSQ3_OSN1_2                     (0x04U << ADC_OSQ3_OSN1_Pos)            /*!< 0x00000004 */
#define ADC_OSQ3_OSN1_3                     (0x08U << ADC_OSQ3_OSN1_Pos)            /*!< 0x00000008 */
#define ADC_OSQ3_OSN1_4                     (0x10U << ADC_OSQ3_OSN1_Pos)            /*!< 0x00000010 */

#define ADC_OSQ3_OSN2_Pos                   (5U)
#define ADC_OSQ3_OSN2_Msk                   (0x1FU << ADC_OSQ3_OSN2_Pos)            /*!< 0x000003E0 */
#define ADC_OSQ3_OSN2                       ADC_OSQ3_OSN2_Msk                       /*!< OSN2[4:0] bits (Number of 2nd conversion in ordinary sequence) */
#define ADC_OSQ3_OSN2_0                     (0x01U << ADC_OSQ3_OSN2_Pos)            /*!< 0x00000020 */
#define ADC_OSQ3_OSN2_1                     (0x02U << ADC_OSQ3_OSN2_Pos)            /*!< 0x00000040 */
#define ADC_OSQ3_OSN2_2                     (0x04U << ADC_OSQ3_OSN2_Pos)            /*!< 0x00000080 */
#define ADC_OSQ3_OSN2_3                     (0x08U << ADC_OSQ3_OSN2_Pos)            /*!< 0x00000100 */
#define ADC_OSQ3_OSN2_4                     (0x10U << ADC_OSQ3_OSN2_Pos)            /*!< 0x00000200 */

#define ADC_OSQ3_OSN3_Pos                   (10U)
#define ADC_OSQ3_OSN3_Msk                   (0x1FU << ADC_OSQ3_OSN3_Pos)            /*!< 0x00007C00 */
#define ADC_OSQ3_OSN3                       ADC_OSQ3_OSN3_Msk                       /*!< OSN3[4:0] bits (Number of 3rd conversion in ordinary sequence) */
#define ADC_OSQ3_OSN3_0                     (0x01U << ADC_OSQ3_OSN3_Pos)            /*!< 0x00000400 */
#define ADC_OSQ3_OSN3_1                     (0x02U << ADC_OSQ3_OSN3_Pos)            /*!< 0x00000800 */
#define ADC_OSQ3_OSN3_2                     (0x04U << ADC_OSQ3_OSN3_Pos)            /*!< 0x00001000 */
#define ADC_OSQ3_OSN3_3                     (0x08U << ADC_OSQ3_OSN3_Pos)            /*!< 0x00002000 */
#define ADC_OSQ3_OSN3_4                     (0x10U << ADC_OSQ3_OSN3_Pos)            /*!< 0x00004000 */

#define ADC_OSQ3_OSN4_Pos                   (15U)
#define ADC_OSQ3_OSN4_Msk                   (0x1FU << ADC_OSQ3_OSN4_Pos)            /*!< 0x000F8000 */
#define ADC_OSQ3_OSN4                       ADC_OSQ3_OSN4_Msk                       /*!< OSN4[4:0] bits (Number of 4th conversion in ordinary sequence) */
#define ADC_OSQ3_OSN4_0                     (0x01U << ADC_OSQ3_OSN4_Pos)            /*!< 0x00008000 */
#define ADC_OSQ3_OSN4_1                     (0x02U << ADC_OSQ3_OSN4_Pos)            /*!< 0x00010000 */
#define ADC_OSQ3_OSN4_2                     (0x04U << ADC_OSQ3_OSN4_Pos)            /*!< 0x00020000 */
#define ADC_OSQ3_OSN4_3                     (0x08U << ADC_OSQ3_OSN4_Pos)            /*!< 0x00040000 */
#define ADC_OSQ3_OSN4_4                     (0x10U << ADC_OSQ3_OSN4_Pos)            /*!< 0x00080000 */

#define ADC_OSQ3_OSN5_Pos                   (20U)
#define ADC_OSQ3_OSN5_Msk                   (0x1FU << ADC_OSQ3_OSN5_Pos)            /*!< 0x01F00000 */
#define ADC_OSQ3_OSN5                       ADC_OSQ3_OSN5_Msk                       /*!< OSN5[4:0] bits (Number of 5th conversion in ordinary sequence) */
#define ADC_OSQ3_OSN5_0                     (0x01U << ADC_OSQ3_OSN5_Pos)            /*!< 0x00100000 */
#define ADC_OSQ3_OSN5_1                     (0x02U << ADC_OSQ3_OSN5_Pos)            /*!< 0x00200000 */
#define ADC_OSQ3_OSN5_2                     (0x04U << ADC_OSQ3_OSN5_Pos)            /*!< 0x00400000 */
#define ADC_OSQ3_OSN5_3                     (0x08U << ADC_OSQ3_OSN5_Pos)            /*!< 0x00800000 */
#define ADC_OSQ3_OSN5_4                     (0x10U << ADC_OSQ3_OSN5_Pos)            /*!< 0x01000000 */

#define ADC_OSQ3_OSN6_Pos                   (25U)
#define ADC_OSQ3_OSN6_Msk                   (0x1FU << ADC_OSQ3_OSN6_Pos)            /*!< 0x3E000000 */
#define ADC_OSQ3_OSN6                       ADC_OSQ3_OSN6_Msk                       /*!< OSN6[4:0] bits (Number of 6th conversion in ordinary sequence) */
#define ADC_OSQ3_OSN6_0                     (0x01U << ADC_OSQ3_OSN6_Pos)            /*!< 0x02000000 */
#define ADC_OSQ3_OSN6_1                     (0x02U << ADC_OSQ3_OSN6_Pos)            /*!< 0x04000000 */
#define ADC_OSQ3_OSN6_2                     (0x04U << ADC_OSQ3_OSN6_Pos)            /*!< 0x08000000 */
#define ADC_OSQ3_OSN6_3                     (0x08U << ADC_OSQ3_OSN6_Pos)            /*!< 0x10000000 */
#define ADC_OSQ3_OSN6_4                     (0x10U << ADC_OSQ3_OSN6_Pos)            /*!< 0x20000000 */

/*******************  Bit definition for ADC_PSQ register  ********************/
#define ADC_PSQ_PSN1_Pos                    (0U)
#define ADC_PSQ_PSN1_Msk                    (0x1FU << ADC_PSQ_PSN1_Pos)             /*!< 0x0000001F */
#define ADC_PSQ_PSN1                        ADC_PSQ_PSN1_Msk                        /*!< PSN1[4:0] bits (Number of 1st conversion in preempted sequence) */
#define ADC_PSQ_PSN1_0                      (0x01U << ADC_PSQ_PSN1_Pos)             /*!< 0x00000001 */
#define ADC_PSQ_PSN1_1                      (0x02U << ADC_PSQ_PSN1_Pos)             /*!< 0x00000002 */
#define ADC_PSQ_PSN1_2                      (0x04U << ADC_PSQ_PSN1_Pos)             /*!< 0x00000004 */
#define ADC_PSQ_PSN1_3                      (0x08U << ADC_PSQ_PSN1_Pos)             /*!< 0x00000008 */
#define ADC_PSQ_PSN1_4                      (0x10U << ADC_PSQ_PSN1_Pos)             /*!< 0x00000010 */

#define ADC_PSQ_PSN2_Pos                    (5U)
#define ADC_PSQ_PSN2_Msk                    (0x1FU << ADC_PSQ_PSN2_Pos)             /*!< 0x000003E0 */
#define ADC_PSQ_PSN2                        ADC_PSQ_PSN2_Msk                        /*!< PSN2[4:0] bits (Number of 2nd conversion in preempted sequence) */
#define ADC_PSQ_PSN2_0                      (0x01U << ADC_PSQ_PSN2_Pos)             /*!< 0x00000020 */
#define ADC_PSQ_PSN2_1                      (0x02U << ADC_PSQ_PSN2_Pos)             /*!< 0x00000040 */
#define ADC_PSQ_PSN2_2                      (0x04U << ADC_PSQ_PSN2_Pos)             /*!< 0x00000080 */
#define ADC_PSQ_PSN2_3                      (0x08U << ADC_PSQ_PSN2_Pos)             /*!< 0x00000100 */
#define ADC_PSQ_PSN2_4                      (0x10U << ADC_PSQ_PSN2_Pos)             /*!< 0x00000200 */

#define ADC_PSQ_PSN3_Pos                    (10U)
#define ADC_PSQ_PSN3_Msk                    (0x1FU << ADC_PSQ_PSN3_Pos)             /*!< 0x00007C00 */
#define ADC_PSQ_PSN3                        ADC_PSQ_PSN3_Msk                        /*!< PSN3[4:0] bits (Number of 3rd conversion in preempted sequence) */
#define ADC_PSQ_PSN3_0                      (0x01U << ADC_PSQ_PSN3_Pos)             /*!< 0x00000400 */
#define ADC_PSQ_PSN3_1                      (0x02U << ADC_PSQ_PSN3_Pos)             /*!< 0x00000800 */
#define ADC_PSQ_PSN3_2                      (0x04U << ADC_PSQ_PSN3_Pos)             /*!< 0x00001000 */
#define ADC_PSQ_PSN3_3                      (0x08U << ADC_PSQ_PSN3_Pos)             /*!< 0x00002000 */
#define ADC_PSQ_PSN3_4                      (0x10U << ADC_PSQ_PSN3_Pos)             /*!< 0x00004000 */

#define ADC_PSQ_PSN4_Pos                    (15U)
#define ADC_PSQ_PSN4_Msk                    (0x1FU << ADC_PSQ_PSN4_Pos)             /*!< 0x000F8000 */
#define ADC_PSQ_PSN4                        ADC_PSQ_PSN4_Msk                        /*!< PSN4[4:0] bits (Number of 4th conversion in preempted sequence) */
#define ADC_PSQ_PSN4_0                      (0x01U << ADC_PSQ_PSN4_Pos)             /*!< 0x00008000 */
#define ADC_PSQ_PSN4_1                      (0x02U << ADC_PSQ_PSN4_Pos)             /*!< 0x00010000 */
#define ADC_PSQ_PSN4_2                      (0x04U << ADC_PSQ_PSN4_Pos)             /*!< 0x00020000 */
#define ADC_PSQ_PSN4_3                      (0x08U << ADC_PSQ_PSN4_Pos)             /*!< 0x00040000 */
#define ADC_PSQ_PSN4_4                      (0x10U << ADC_PSQ_PSN4_Pos)             /*!< 0x00080000 */

#define ADC_PSQ_PCLEN_Pos                   (20U)
#define ADC_PSQ_PCLEN_Msk                   (0x3U << ADC_PSQ_PCLEN_Pos)             /*!< 0x00300000 */
#define ADC_PSQ_PCLEN                       ADC_PSQ_PCLEN_Msk                       /*!< PCLEN[1:0] bits (Preempted conversion sequence length) */
#define ADC_PSQ_PCLEN_0                     (0x1U << ADC_PSQ_PCLEN_Pos)             /*!< 0x00100000 */
#define ADC_PSQ_PCLEN_1                     (0x2U << ADC_PSQ_PCLEN_Pos)             /*!< 0x00200000 */

/*******************  Bit definition for ADC_PDT1 register  *******************/
#define ADC_PDT1_PDT1_Pos                   (0U)
#define ADC_PDT1_PDT1_Msk                   (0xFFFFU << ADC_PDT1_PDT1_Pos)          /*!< 0x0000FFFF */
#define ADC_PDT1_PDT1                       ADC_PDT1_PDT1_Msk                       /*!< Conversion data from preempted channel 1 */

/*******************  Bit definition for ADC_PDT2 register  *******************/
#define ADC_PDT2_PDT2_Pos                   (0U)
#define ADC_PDT2_PDT2_Msk                   (0xFFFFU << ADC_PDT2_PDT2_Pos)          /*!< 0x0000FFFF */
#define ADC_PDT2_PDT2                       ADC_PDT2_PDT2_Msk                       /*!< Conversion data from preempted channel 2 */

/*******************  Bit definition for ADC_PDT3 register  *******************/
#define ADC_PDT3_PDT3_Pos                   (0U)
#define ADC_PDT3_PDT3_Msk                   (0xFFFFU << ADC_PDT3_PDT3_Pos)          /*!< 0x0000FFFF */
#define ADC_PDT3_PDT3                       ADC_PDT3_PDT3_Msk                       /*!< Conversion data from preempted channel 3 */

/*******************  Bit definition for ADC_PDT4 register  *******************/
#define ADC_PDT4_PDT4_Pos                   (0U)
#define ADC_PDT4_PDT4_Msk                   (0xFFFFU << ADC_PDT4_PDT4_Pos)          /*!< 0x0000FFFF */
#define ADC_PDT4_PDT4                       ADC_PDT4_PDT4_Msk                       /*!< Conversion data from preempted channel 4 */

/*******************  Bit definition for ADC_ODT register  ********************/
#define ADC_ODT_ODT_Pos                     (0U)
#define ADC_ODT_ODT_Msk                     (0xFFFFU << ADC_ODT_ODT_Pos)            /*!< 0x0000FFFF */
#define ADC_ODT_ODT                         ADC_ODT_ODT_Msk                         /*!< Conversion data of ordinary channel */
#define ADC_ODT_ADC2ODT_Pos                 (16U)
#define ADC_ODT_ADC2ODT_Msk                 (0xFFFFU << ADC_ODT_ADC2ODT_Pos)        /*!< 0xFFFF0000 */
#define ADC_ODT_ADC2ODT                     ADC_ODT_ADC2ODT_Msk                     /*!< ADC2 conversion data of ordinary channel */

/******************************************************************************/
/*                                                                            */
/*                       Controller Area Network (CAN)                        */
/*                                                                            */
/******************************************************************************/

/*!< CAN control and status registers */
/******************  Bit definition for CAN_MCTRL register  *******************/
#define CAN_MCTRL_FZEN_Pos                  (0U)
#define CAN_MCTRL_FZEN_Msk                  (0x1U << CAN_MCTRL_FZEN_Pos)            /*!< 0x00000001 */
#define CAN_MCTRL_FZEN                      CAN_MCTRL_FZEN_Msk                      /*!< Freeze mode enable */
#define CAN_MCTRL_DZEN_Pos                  (1U)
#define CAN_MCTRL_DZEN_Msk                  (0x1U << CAN_MCTRL_DZEN_Pos)            /*!< 0x00000002 */
#define CAN_MCTRL_DZEN                      CAN_MCTRL_DZEN_Msk                      /*!< Doze mode enable */
#define CAN_MCTRL_MMSSR_Pos                 (2U)
#define CAN_MCTRL_MMSSR_Msk                 (0x1U << CAN_MCTRL_MMSSR_Pos)           /*!< 0x00000004 */
#define CAN_MCTRL_MMSSR                     CAN_MCTRL_MMSSR_Msk                     /*!< Multiple message transmit sequence rule */
#define CAN_MCTRL_MDRSEL_Pos                (3U)
#define CAN_MCTRL_MDRSEL_Msk                (0x1U << CAN_MCTRL_MDRSEL_Pos)          /*!< 0x00000008 */
#define CAN_MCTRL_MDRSEL                    CAN_MCTRL_MDRSEL_Msk                    /*!< Message discard rule select when overflow */
#define CAN_MCTRL_PRSFEN_Pos                (4U)
#define CAN_MCTRL_PRSFEN_Msk                (0x1U << CAN_MCTRL_PRSFEN_Pos)          /*!< 0x00000010 */
#define CAN_MCTRL_PRSFEN                    CAN_MCTRL_PRSFEN_Msk                    /*!< Prohibit retransmission enable when sending fails enable */
#define CAN_MCTRL_AEDEN_Pos                 (5U)
#define CAN_MCTRL_AEDEN_Msk                 (0x1U << CAN_MCTRL_AEDEN_Pos)           /*!< 0x00000020 */
#define CAN_MCTRL_AEDEN                     CAN_MCTRL_AEDEN_Msk                     /*!< Automatic exit doze mode enable */
#define CAN_MCTRL_AEBOEN_Pos                (6U)
#define CAN_MCTRL_AEBOEN_Msk                (0x1U << CAN_MCTRL_AEBOEN_Pos)          /*!< 0x00000040 */
#define CAN_MCTRL_AEBOEN                    CAN_MCTRL_AEBOEN_Msk                    /*!< Automatic exit bus-off enable */
#define CAN_MCTRL_TTCEN_Pos                 (7U)
#define CAN_MCTRL_TTCEN_Msk                 (0x1U << CAN_MCTRL_TTCEN_Pos)           /*!< 0x00000080 */
#define CAN_MCTRL_TTCEN                     CAN_MCTRL_TTCEN_Msk                     /*!< Time triggered communication mode enable */
#define CAN_MCTRL_SPRST_Pos                 (15U)
#define CAN_MCTRL_SPRST_Msk                 (0x1U << CAN_MCTRL_SPRST_Pos)           /*!< 0x00008000 */
#define CAN_MCTRL_SPRST                     CAN_MCTRL_SPRST_Msk                     /*!< Software partial reset */
#define CAN_MCTRL_PTD_Pos                   (16U)
#define CAN_MCTRL_PTD_Msk                   (0x1U << CAN_MCTRL_PTD_Pos)             /*!< 0x00010000 */
#define CAN_MCTRL_PTD                       CAN_MCTRL_PTD_Msk                       /*!< Prohibit trans when debug */

/*******************  Bit definition for CAN_MSTS register  *******************/
#define CAN_MSTS_FZC_Pos                    (0U)
#define CAN_MSTS_FZC_Msk                    (0x1U << CAN_MSTS_FZC_Pos)              /*!< 0x00000001 */
#define CAN_MSTS_FZC                        CAN_MSTS_FZC_Msk                        /*!< Freeze mode confirm */
#define CAN_MSTS_DZC_Pos                    (1U)
#define CAN_MSTS_DZC_Msk                    (0x1U << CAN_MSTS_DZC_Pos)              /*!< 0x00000002 */
#define CAN_MSTS_DZC                        CAN_MSTS_DZC_Msk                        /*!< Doze mode acknowledge */
#define CAN_MSTS_EOIF_Pos                   (2U)
#define CAN_MSTS_EOIF_Msk                   (0x1U << CAN_MSTS_EOIF_Pos)             /*!< 0x00000004 */
#define CAN_MSTS_EOIF                       CAN_MSTS_EOIF_Msk                       /*!< Error occur interrupt flag */
#define CAN_MSTS_QDZIF_Pos                  (3U)
#define CAN_MSTS_QDZIF_Msk                  (0x1U << CAN_MSTS_QDZIF_Pos)            /*!< 0x00000008 */
#define CAN_MSTS_QDZIF                      CAN_MSTS_QDZIF_Msk                      /*!< Exit doze mode interrupt flag */
#define CAN_MSTS_EDZIF_Pos                  (4U)
#define CAN_MSTS_EDZIF_Msk                  (0x1U << CAN_MSTS_EDZIF_Pos)            /*!< 0x00000010 */
#define CAN_MSTS_EDZIF                      CAN_MSTS_EDZIF_Msk                      /*!< Enter doze mode interrupt flag */
#define CAN_MSTS_CUSS_Pos                   (8U)
#define CAN_MSTS_CUSS_Msk                   (0x1U << CAN_MSTS_CUSS_Pos)             /*!< 0x00000100 */
#define CAN_MSTS_CUSS                       CAN_MSTS_CUSS_Msk                       /*!< Current transmit status */
#define CAN_MSTS_CURS_Pos                   (9U)
#define CAN_MSTS_CURS_Msk                   (0x1U << CAN_MSTS_CURS_Pos)             /*!< 0x00000200 */
#define CAN_MSTS_CURS                       CAN_MSTS_CURS_Msk                       /*!< Current receive status */
#define CAN_MSTS_LSAMPRX_Pos                (10U)
#define CAN_MSTS_LSAMPRX_Msk                (0x1U << CAN_MSTS_LSAMPRX_Pos)          /*!< 0x00000400 */
#define CAN_MSTS_LSAMPRX                    CAN_MSTS_LSAMPRX_Msk                    /*!< Last sample level on RX pin */
#define CAN_MSTS_REALRX_Pos                 (11U)
#define CAN_MSTS_REALRX_Msk                 (0x1U << CAN_MSTS_REALRX_Pos)           /*!< 0x00000800 */
#define CAN_MSTS_REALRX                     CAN_MSTS_REALRX_Msk                     /*!< Real time level on RX pin */

/*******************  Bit definition for CAN_TSTS register  *******************/
#define CAN_TSTS_TM0TCF_Pos                 (0U)
#define CAN_TSTS_TM0TCF_Msk                 (0x1U << CAN_TSTS_TM0TCF_Pos)           /*!< 0x00000001 */
#define CAN_TSTS_TM0TCF                     CAN_TSTS_TM0TCF_Msk                     /*!< Transmit mailbox 0 transmission completed flag */
#define CAN_TSTS_TM0TSF_Pos                 (1U)
#define CAN_TSTS_TM0TSF_Msk                 (0x1U << CAN_TSTS_TM0TSF_Pos)           /*!< 0x00000002 */
#define CAN_TSTS_TM0TSF                     CAN_TSTS_TM0TSF_Msk                     /*!< Transmit mailbox 0 transmission success flag */
#define CAN_TSTS_TM0ALF_Pos                 (2U)
#define CAN_TSTS_TM0ALF_Msk                 (0x1U << CAN_TSTS_TM0ALF_Pos)           /*!< 0x00000004 */
#define CAN_TSTS_TM0ALF                     CAN_TSTS_TM0ALF_Msk                     /*!< Transmit mailbox 0 arbitration lost flag */
#define CAN_TSTS_TM0TEF_Pos                 (3U)
#define CAN_TSTS_TM0TEF_Msk                 (0x1U << CAN_TSTS_TM0TEF_Pos)           /*!< 0x00000008 */
#define CAN_TSTS_TM0TEF                     CAN_TSTS_TM0TEF_Msk                     /*!< Transmit mailbox 0 transmission error flag */
#define CAN_TSTS_TM0CT_Pos                  (7U)
#define CAN_TSTS_TM0CT_Msk                  (0x1U << CAN_TSTS_TM0CT_Pos)            /*!< 0x00000080 */
#define CAN_TSTS_TM0CT                      CAN_TSTS_TM0CT_Msk                      /*!< Transmit mailbox 0 cancel transmit */
#define CAN_TSTS_TM1TCF_Pos                 (8U)
#define CAN_TSTS_TM1TCF_Msk                 (0x1U << CAN_TSTS_TM1TCF_Pos)           /*!< 0x00000100 */
#define CAN_TSTS_TM1TCF                     CAN_TSTS_TM1TCF_Msk                     /*!< Transmit mailbox 1 transmission completed flag */
#define CAN_TSTS_TM1TSF_Pos                 (9U)
#define CAN_TSTS_TM1TSF_Msk                 (0x1U << CAN_TSTS_TM1TSF_Pos)           /*!< 0x00000200 */
#define CAN_TSTS_TM1TSF                     CAN_TSTS_TM1TSF_Msk                     /*!< Transmit mailbox 1 transmission success flag */
#define CAN_TSTS_TM1ALF_Pos                 (10U)
#define CAN_TSTS_TM1ALF_Msk                 (0x1U << CAN_TSTS_TM1ALF_Pos)           /*!< 0x00000400 */
#define CAN_TSTS_TM1ALF                     CAN_TSTS_TM1ALF_Msk                     /*!< Transmit mailbox 1 arbitration lost flag */
#define CAN_TSTS_TM1TEF_Pos                 (11U)
#define CAN_TSTS_TM1TEF_Msk                 (0x1U << CAN_TSTS_TM1TEF_Pos)           /*!< 0x00000800 */
#define CAN_TSTS_TM1TEF                     CAN_TSTS_TM1TEF_Msk                     /*!< Transmit mailbox 1 transmission error flag */
#define CAN_TSTS_TM1CT_Pos                  (15U)
#define CAN_TSTS_TM1CT_Msk                  (0x1U << CAN_TSTS_TM1CT_Pos)            /*!< 0x00008000 */
#define CAN_TSTS_TM1CT                      CAN_TSTS_TM1CT_Msk                      /*!< Transmit mailbox 1 cancel transmit */
#define CAN_TSTS_TM2TCF_Pos                 (16U)
#define CAN_TSTS_TM2TCF_Msk                 (0x1U << CAN_TSTS_TM2TCF_Pos)           /*!< 0x00010000 */
#define CAN_TSTS_TM2TCF                     CAN_TSTS_TM2TCF_Msk                     /*!< Transmit mailbox 2 transmission completed flag */
#define CAN_TSTS_TM2TSF_Pos                 (17U)
#define CAN_TSTS_TM2TSF_Msk                 (0x1U << CAN_TSTS_TM2TSF_Pos)           /*!< 0x00020000 */
#define CAN_TSTS_TM2TSF                     CAN_TSTS_TM2TSF_Msk                     /*!< Transmit mailbox 2 transmission success flag */
#define CAN_TSTS_TM2ALF_Pos                 (18U)
#define CAN_TSTS_TM2ALF_Msk                 (0x1U << CAN_TSTS_TM2ALF_Pos)           /*!< 0x00040000 */
#define CAN_TSTS_TM2ALF                     CAN_TSTS_TM2ALF_Msk                     /*!< Transmit mailbox 2 arbitration lost flag */
#define CAN_TSTS_TM2TEF_Pos                 (19U)
#define CAN_TSTS_TM2TEF_Msk                 (0x1U << CAN_TSTS_TM2TEF_Pos)           /*!< 0x00080000 */
#define CAN_TSTS_TM2TEF                     CAN_TSTS_TM2TEF_Msk                     /*!< Transmit mailbox 2 transmission error flag */
#define CAN_TSTS_TM2CT_Pos                  (23U)
#define CAN_TSTS_TM2CT_Msk                  (0x1U << CAN_TSTS_TM2CT_Pos)            /*!< 0x00800000 */
#define CAN_TSTS_TM2CT                      CAN_TSTS_TM2CT_Msk                      /*!< Transmit mailbox 2 cancel transmit */
#define CAN_TSTS_TMNR_Pos                   (24U)
#define CAN_TSTS_TMNR_Msk                   (0x3U << CAN_TSTS_TMNR_Pos)             /*!< 0x03000000 */
#define CAN_TSTS_TMNR                       CAN_TSTS_TMNR_Msk                       /*!< TMNR[1:0] bits (Transmit mailbox number record) */

#define CAN_TSTS_TMEF_Pos                   (26U)
#define CAN_TSTS_TMEF_Msk                   (0x7U << CAN_TSTS_TMEF_Pos)             /*!< 0x1C000000 */
#define CAN_TSTS_TMEF                       CAN_TSTS_TMEF_Msk                       /*!< TMEF[2:0] bits (Transmit mailbox empty flag) */
#define CAN_TSTS_TM0EF_Pos                  (26U)
#define CAN_TSTS_TM0EF_Msk                  (0x1U << CAN_TSTS_TM0EF_Pos)            /*!< 0x04000000 */
#define CAN_TSTS_TM0EF                      CAN_TSTS_TM0EF_Msk                      /*!< Transmit mailbox 0 empty flag */
#define CAN_TSTS_TM1EF_Pos                  (27U)
#define CAN_TSTS_TM1EF_Msk                  (0x1U << CAN_TSTS_TM1EF_Pos)            /*!< 0x08000000 */
#define CAN_TSTS_TM1EF                      CAN_TSTS_TM1EF_Msk                      /*!< Transmit mailbox 1 empty flag */
#define CAN_TSTS_TM2EF_Pos                  (28U)
#define CAN_TSTS_TM2EF_Msk                  (0x1U << CAN_TSTS_TM2EF_Pos)            /*!< 0x10000000 */
#define CAN_TSTS_TM2EF                      CAN_TSTS_TM2EF_Msk                      /*!< Transmit mailbox 2 empty flag */

#define CAN_TSTS_TMLPF_Pos                  (29U)
#define CAN_TSTS_TMLPF_Msk                  (0x7U << CAN_TSTS_TMLPF_Pos)            /*!< 0xE0000000 */
#define CAN_TSTS_TMLPF                      CAN_TSTS_TMLPF_Msk                      /*!< TMLPF[2:0] bits (Transmit mailbox lowest priority flag) */
#define CAN_TSTS_TM0LPF_Pos                 (29U)
#define CAN_TSTS_TM0LPF_Msk                 (0x1U << CAN_TSTS_TM0LPF_Pos)           /*!< 0x20000000 */
#define CAN_TSTS_TM0LPF                     CAN_TSTS_TM0LPF_Msk                     /*!< Transmit mailbox 0 lowest priority flag */
#define CAN_TSTS_TM1LPF_Pos                 (30U)
#define CAN_TSTS_TM1LPF_Msk                 (0x1U << CAN_TSTS_TM1LPF_Pos)           /*!< 0x40000000 */
#define CAN_TSTS_TM1LPF                     CAN_TSTS_TM1LPF_Msk                     /*!< Transmit mailbox 1 lowest priority flag */
#define CAN_TSTS_TM2LPF_Pos                 (31U)
#define CAN_TSTS_TM2LPF_Msk                 (0x1U << CAN_TSTS_TM2LPF_Pos)           /*!< 0x80000000 */
#define CAN_TSTS_TM2LPF                     CAN_TSTS_TM2LPF_Msk                     /*!< Transmit mailbox 2 lowest priority flag */

/*******************  Bit definition for CAN_RF0 register  ********************/
#define CAN_RF0_RF0MN_Pos                   (0U)
#define CAN_RF0_RF0MN_Msk                   (0x3U << CAN_RF0_RF0MN_Pos)             /*!< 0x00000003 */
#define CAN_RF0_RF0MN                       CAN_RF0_RF0MN_Msk                       /*!< Receive FIFO 0 message num */
#define CAN_RF0_RF0FF_Pos                   (3U)
#define CAN_RF0_RF0FF_Msk                   (0x1U << CAN_RF0_RF0FF_Pos)             /*!< 0x00000008 */
#define CAN_RF0_RF0FF                       CAN_RF0_RF0FF_Msk                       /*!< Receive FIFO 0 full flag */
#define CAN_RF0_RF0OF_Pos                   (4U)
#define CAN_RF0_RF0OF_Msk                   (0x1U << CAN_RF0_RF0OF_Pos)             /*!< 0x00000010 */
#define CAN_RF0_RF0OF                       CAN_RF0_RF0OF_Msk                       /*!< Receive FIFO 0 overflow flag */
#define CAN_RF0_RF0R_Pos                    (5U)
#define CAN_RF0_RF0R_Msk                    (0x1U << CAN_RF0_RF0R_Pos)              /*!< 0x00000020 */
#define CAN_RF0_RF0R                        CAN_RF0_RF0R_Msk                        /*!< Receive FIFO 0 release */

/*******************  Bit definition for CAN_RF1 register  ********************/
#define CAN_RF1_RF1MN_Pos                   (0U)
#define CAN_RF1_RF1MN_Msk                   (0x3U << CAN_RF1_RF1MN_Pos)             /*!< 0x00000003 */
#define CAN_RF1_RF1MN                       CAN_RF1_RF1MN_Msk                       /*!< Receive FIFO 1 message num */
#define CAN_RF1_RF1FF_Pos                   (3U)
#define CAN_RF1_RF1FF_Msk                   (0x1U << CAN_RF1_RF1FF_Pos)             /*!< 0x00000008 */
#define CAN_RF1_RF1FF                       CAN_RF1_RF1FF_Msk                       /*!< Receive FIFO 1 full flag */
#define CAN_RF1_RF1OF_Pos                   (4U)
#define CAN_RF1_RF1OF_Msk                   (0x1U << CAN_RF1_RF1OF_Pos)             /*!< 0x00000010 */
#define CAN_RF1_RF1OF                       CAN_RF1_RF1OF_Msk                       /*!< Receive FIFO 1 overflow flag */
#define CAN_RF1_RF1R_Pos                    (5U)
#define CAN_RF1_RF1R_Msk                    (0x1U << CAN_RF1_RF1R_Pos)              /*!< 0x00000020 */
#define CAN_RF1_RF1R                        CAN_RF1_RF1R_Msk                        /*!< Receive FIFO 1 release */

/******************  Bit definition for CAN_INTEN register  *******************/
#define CAN_INTEN_TCIEN_Pos                 (0U)
#define CAN_INTEN_TCIEN_Msk                 (0x1U << CAN_INTEN_TCIEN_Pos)           /*!< 0x00000001 */
#define CAN_INTEN_TCIEN                     CAN_INTEN_TCIEN_Msk                     /*!< Transmit mailbox empty interrupt enable */
#define CAN_INTEN_RF0MIEN_Pos               (1U)
#define CAN_INTEN_RF0MIEN_Msk               (0x1U << CAN_INTEN_RF0MIEN_Pos)         /*!< 0x00000002 */
#define CAN_INTEN_RF0MIEN                   CAN_INTEN_RF0MIEN_Msk                   /*!< FIFO 0 receive message interrupt enable */
#define CAN_INTEN_RF0FIEN_Pos               (2U)
#define CAN_INTEN_RF0FIEN_Msk               (0x1U << CAN_INTEN_RF0FIEN_Pos)         /*!< 0x00000004 */
#define CAN_INTEN_RF0FIEN                   CAN_INTEN_RF0FIEN_Msk                   /*!< Receive FIFO 0 full interrupt enable */
#define CAN_INTEN_RF0OIEN_Pos               (3U)
#define CAN_INTEN_RF0OIEN_Msk               (0x1U << CAN_INTEN_RF0OIEN_Pos)         /*!< 0x00000008 */
#define CAN_INTEN_RF0OIEN                   CAN_INTEN_RF0OIEN_Msk                   /*!< Receive FIFO 0 overflow interrupt enable */
#define CAN_INTEN_RF1MIEN_Pos               (4U)
#define CAN_INTEN_RF1MIEN_Msk               (0x1U << CAN_INTEN_RF1MIEN_Pos)         /*!< 0x00000010 */
#define CAN_INTEN_RF1MIEN                   CAN_INTEN_RF1MIEN_Msk                   /*!< FIFO 1 receive message interrupt enable */
#define CAN_INTEN_RF1FIEN_Pos               (5U)
#define CAN_INTEN_RF1FIEN_Msk               (0x1U << CAN_INTEN_RF1FIEN_Pos)         /*!< 0x00000020 */
#define CAN_INTEN_RF1FIEN                   CAN_INTEN_RF1FIEN_Msk                   /*!< Receive FIFO 1 full interrupt enable */
#define CAN_INTEN_RF1OIEN_Pos               (6U)
#define CAN_INTEN_RF1OIEN_Msk               (0x1U << CAN_INTEN_RF1OIEN_Pos)         /*!< 0x00000040 */
#define CAN_INTEN_RF1OIEN                   CAN_INTEN_RF1OIEN_Msk                   /*!< Receive FIFO 1 overflow interrupt enable */
#define CAN_INTEN_EAIEN_Pos                 (8U)
#define CAN_INTEN_EAIEN_Msk                 (0x1U << CAN_INTEN_EAIEN_Pos)           /*!< 0x00000100 */
#define CAN_INTEN_EAIEN                     CAN_INTEN_EAIEN_Msk                     /*!< Error active interrupt enable */
#define CAN_INTEN_EPIEN_Pos                 (9U)
#define CAN_INTEN_EPIEN_Msk                 (0x1U << CAN_INTEN_EPIEN_Pos)           /*!< 0x00000200 */
#define CAN_INTEN_EPIEN                     CAN_INTEN_EPIEN_Msk                     /*!< Error passive interrupt enable */
#define CAN_INTEN_BOIEN_Pos                 (10U)
#define CAN_INTEN_BOIEN_Msk                 (0x1U << CAN_INTEN_BOIEN_Pos)           /*!< 0x00000400 */
#define CAN_INTEN_BOIEN                     CAN_INTEN_BOIEN_Msk                     /*!< Bus-off interrupt enable */
#define CAN_INTEN_ETRIEN_Pos                (11U)
#define CAN_INTEN_ETRIEN_Msk                (0x1U << CAN_INTEN_ETRIEN_Pos)          /*!< 0x00000800 */
#define CAN_INTEN_ETRIEN                    CAN_INTEN_ETRIEN_Msk                    /*!< Error type record interrupt enable */
#define CAN_INTEN_EOIEN_Pos                 (15U)
#define CAN_INTEN_EOIEN_Msk                 (0x1U << CAN_INTEN_EOIEN_Pos)           /*!< 0x00008000 */
#define CAN_INTEN_EOIEN                     CAN_INTEN_EOIEN_Msk                     /*!< Error occur interrupt enable */
#define CAN_INTEN_QDZIEN_Pos                (16U)
#define CAN_INTEN_QDZIEN_Msk                (0x1U << CAN_INTEN_QDZIEN_Pos)          /*!< 0x00010000 */
#define CAN_INTEN_QDZIEN                    CAN_INTEN_QDZIEN_Msk                    /*!< Quit doze mode interrupt enable */
#define CAN_INTEN_EDZIEN_Pos                (17U)
#define CAN_INTEN_EDZIEN_Msk                (0x1U << CAN_INTEN_EDZIEN_Pos)          /*!< 0x00020000 */
#define CAN_INTEN_EDZIEN                    CAN_INTEN_EDZIEN_Msk                    /*!< Enter doze mode interrupt enable */

/*******************  Bit definition for CAN_ESTS register  *******************/
#define CAN_ESTS_EAF_Pos                    (0U)
#define CAN_ESTS_EAF_Msk                    (0x1U << CAN_ESTS_EAF_Pos)              /*!< 0x00000001 */
#define CAN_ESTS_EAF                        CAN_ESTS_EAF_Msk                        /*!< Error active flag */
#define CAN_ESTS_EPF_Pos                    (1U)
#define CAN_ESTS_EPF_Msk                    (0x1U << CAN_ESTS_EPF_Pos)              /*!< 0x00000002 */
#define CAN_ESTS_EPF                        CAN_ESTS_EPF_Msk                        /*!< Error passive flag */
#define CAN_ESTS_BOF_Pos                    (2U)
#define CAN_ESTS_BOF_Msk                    (0x1U << CAN_ESTS_BOF_Pos)              /*!< 0x00000004 */
#define CAN_ESTS_BOF                        CAN_ESTS_BOF_Msk                        /*!< Bus-off flag */

#define CAN_ESTS_ETR_Pos                    (4U)
#define CAN_ESTS_ETR_Msk                    (0x7U << CAN_ESTS_ETR_Pos)              /*!< 0x00000070 */
#define CAN_ESTS_ETR                        CAN_ESTS_ETR_Msk                        /*!< ETR[2:0] bits (Error type record) */
#define CAN_ESTS_ETR_0                      (0x1U << CAN_ESTS_ETR_Pos)              /*!< 0x00000010 */
#define CAN_ESTS_ETR_1                      (0x2U << CAN_ESTS_ETR_Pos)              /*!< 0x00000020 */
#define CAN_ESTS_ETR_2                      (0x4U << CAN_ESTS_ETR_Pos)              /*!< 0x00000040 */

#define CAN_ESTS_TEC_Pos                    (16U)
#define CAN_ESTS_TEC_Msk                    (0xFFU << CAN_ESTS_TEC_Pos)             /*!< 0x00FF0000 */
#define CAN_ESTS_TEC                        CAN_ESTS_TEC_Msk                        /*!< Transmit error counter */
#define CAN_ESTS_REC_Pos                    (24U)
#define CAN_ESTS_REC_Msk                    (0xFFU << CAN_ESTS_REC_Pos)             /*!< 0xFF000000 */
#define CAN_ESTS_REC                        CAN_ESTS_REC_Msk                        /*!< Receive error counter */

/*******************  Bit definition for CAN_BTMG register  ********************/
#define CAN_BTMG_BRDIV_Pos                  (0U)
#define CAN_BTMG_BRDIV_Msk                  (0xFFFU << CAN_BTMG_BRDIV_Pos)          /*!< 0x00000FFF */
#define CAN_BTMG_BRDIV                      CAN_BTMG_BRDIV_Msk                      /*!< Baud rate division */

#define CAN_BTMG_BTS1_Pos                   (16U)
#define CAN_BTMG_BTS1_Msk                   (0xFU << CAN_BTMG_BTS1_Pos)             /*!< 0x000F0000 */
#define CAN_BTMG_BTS1                       CAN_BTMG_BTS1_Msk                       /*!< BTS1[3:0] bits (Bit time segment 1) */
#define CAN_BTMG_BTS1_0                     (0x1U << CAN_BTMG_BTS1_Pos)             /*!< 0x00010000 */
#define CAN_BTMG_BTS1_1                     (0x2U << CAN_BTMG_BTS1_Pos)             /*!< 0x00020000 */
#define CAN_BTMG_BTS1_2                     (0x4U << CAN_BTMG_BTS1_Pos)             /*!< 0x00040000 */
#define CAN_BTMG_BTS1_3                     (0x8U << CAN_BTMG_BTS1_Pos)             /*!< 0x00080000 */

#define CAN_BTMG_BTS2_Pos                   (20U)
#define CAN_BTMG_BTS2_Msk                   (0x7U << CAN_BTMG_BTS2_Pos)             /*!< 0x00700000 */
#define CAN_BTMG_BTS2                       CAN_BTMG_BTS2_Msk                       /*!< BTS2[2:0] bits (Bit time segment 2) */
#define CAN_BTMG_BTS2_0                     (0x1U << CAN_BTMG_BTS2_Pos)             /*!< 0x00100000 */
#define CAN_BTMG_BTS2_1                     (0x2U << CAN_BTMG_BTS2_Pos)             /*!< 0x00200000 */
#define CAN_BTMG_BTS2_2                     (0x4U << CAN_BTMG_BTS2_Pos)             /*!< 0x00400000 */

#define CAN_BTMG_RSAW_Pos                   (24U)
#define CAN_BTMG_RSAW_Msk                   (0x3U << CAN_BTMG_RSAW_Pos)             /*!< 0x03000000 */
#define CAN_BTMG_RSAW                       CAN_BTMG_RSAW_Msk                       /*!< RSAW[1:0] bits (Resynchronization width) */
#define CAN_BTMG_RSAW_0                     (0x1U << CAN_BTMG_RSAW_Pos)             /*!< 0x01000000 */
#define CAN_BTMG_RSAW_1                     (0x2U << CAN_BTMG_RSAW_Pos)             /*!< 0x02000000 */

#define CAN_BTMG_LBEN_Pos                   (30U)
#define CAN_BTMG_LBEN_Msk                   (0x1U << CAN_BTMG_LBEN_Pos)             /*!< 0x40000000 */
#define CAN_BTMG_LBEN                       CAN_BTMG_LBEN_Msk                       /*!< Loop back mode */
#define CAN_BTMG_LOEN_Pos                   (31U)
#define CAN_BTMG_LOEN_Msk                   (0x1U << CAN_BTMG_LOEN_Pos)             /*!< 0x80000000 */
#define CAN_BTMG_LOEN                       CAN_BTMG_LOEN_Msk                       /*!< Listen-Only mode */

/*!< Mailbox registers */
/*******************  Bit definition for CAN_TMI0 register  *******************/
#define CAN_TMI0_TMSR_Pos                   (0U)
#define CAN_TMI0_TMSR_Msk                   (0x1U << CAN_TMI0_TMSR_Pos)             /*!< 0x00000001 */
#define CAN_TMI0_TMSR                       CAN_TMI0_TMSR_Msk                       /*!< Transmit mailbox send request */
#define CAN_TMI0_TMFRSEL_Pos                (1U)
#define CAN_TMI0_TMFRSEL_Msk                (0x1U << CAN_TMI0_TMFRSEL_Pos)          /*!< 0x00000002 */
#define CAN_TMI0_TMFRSEL                    CAN_TMI0_TMFRSEL_Msk                    /*!< Transmit mailbox frame type select */
#define CAN_TMI0_TMIDSEL_Pos                (2U)
#define CAN_TMI0_TMIDSEL_Msk                (0x1U << CAN_TMI0_TMIDSEL_Pos)          /*!< 0x00000004 */
#define CAN_TMI0_TMIDSEL                    CAN_TMI0_TMIDSEL_Msk                    /*!< Transmit mailbox identifier type select */
#define CAN_TMI0_TMEID_Pos                  (3U)
#define CAN_TMI0_TMEID_Msk                  (0x3FFFFU << CAN_TMI0_TMEID_Pos)        /*!< 0x001FFFF8 */
#define CAN_TMI0_TMEID                      CAN_TMI0_TMEID_Msk                      /*!< Transmit mailbox extended identifier */
#define CAN_TMI0_TMSID_Pos                  (21U)
#define CAN_TMI0_TMSID_Msk                  (0x7FFU << CAN_TMI0_TMSID_Pos)          /*!< 0xFFE00000 */
#define CAN_TMI0_TMSID                      CAN_TMI0_TMSID_Msk                      /*!< Transmit mailbox standard identifier or extended identifier high bytes */

/*******************  Bit definition for CAN_TMC0 register  *******************/
#define CAN_TMC0_TMDTBL_Pos                 (0U)
#define CAN_TMC0_TMDTBL_Msk                 (0xFU << CAN_TMC0_TMDTBL_Pos)           /*!< 0x0000000F */
#define CAN_TMC0_TMDTBL                     CAN_TMC0_TMDTBL_Msk                     /*!< Transmit mailbox data byte length */
#define CAN_TMC0_TMTSTEN_Pos                (8U)
#define CAN_TMC0_TMTSTEN_Msk                (0x1U << CAN_TMC0_TMTSTEN_Pos)          /*!< 0x00000100 */
#define CAN_TMC0_TMTSTEN                    CAN_TMC0_TMTSTEN_Msk                    /*!< Transmit mailbox time stamp transmit enable */
#define CAN_TMC0_TMTS_Pos                   (16U)
#define CAN_TMC0_TMTS_Msk                   (0xFFFFU << CAN_TMC0_TMTS_Pos)          /*!< 0xFFFF0000 */
#define CAN_TMC0_TMTS                       CAN_TMC0_TMTS_Msk                       /*!< Transmit mailbox time stamp */

/******************  Bit definition for CAN_TMDTL0 register  ******************/
#define CAN_TMDTL0_TMDT0_Pos                (0U)
#define CAN_TMDTL0_TMDT0_Msk                (0xFFU << CAN_TMDTL0_TMDT0_Pos)         /*!< 0x000000FF */
#define CAN_TMDTL0_TMDT0                    CAN_TMDTL0_TMDT0_Msk                    /*!< Transmit mailbox data byte 0 */
#define CAN_TMDTL0_TMDT1_Pos                (8U)
#define CAN_TMDTL0_TMDT1_Msk                (0xFFU << CAN_TMDTL0_TMDT1_Pos)         /*!< 0x0000FF00 */
#define CAN_TMDTL0_TMDT1                    CAN_TMDTL0_TMDT1_Msk                    /*!< Transmit mailbox data byte 1 */
#define CAN_TMDTL0_TMDT2_Pos                (16U)
#define CAN_TMDTL0_TMDT2_Msk                (0xFFU << CAN_TMDTL0_TMDT2_Pos)         /*!< 0x00FF0000 */
#define CAN_TMDTL0_TMDT2                    CAN_TMDTL0_TMDT2_Msk                    /*!< Transmit mailbox data byte 2 */
#define CAN_TMDTL0_TMDT3_Pos                (24U)
#define CAN_TMDTL0_TMDT3_Msk                (0xFFU << CAN_TMDTL0_TMDT3_Pos)         /*!< 0xFF000000 */
#define CAN_TMDTL0_TMDT3                    CAN_TMDTL0_TMDT3_Msk                    /*!< Transmit mailbox data byte 3 */

/******************  Bit definition for CAN_TMDTH0 register  ******************/
#define CAN_TMDTH0_TMDT4_Pos                (0U)
#define CAN_TMDTH0_TMDT4_Msk                (0xFFU << CAN_TMDTH0_TMDT4_Pos)         /*!< 0x000000FF */
#define CAN_TMDTH0_TMDT4                    CAN_TMDTH0_TMDT4_Msk                    /*!< Transmit mailbox data byte 4 */
#define CAN_TMDTH0_TMDT5_Pos                (8U)
#define CAN_TMDTH0_TMDT5_Msk                (0xFFU << CAN_TMDTH0_TMDT5_Pos)         /*!< 0x0000FF00 */
#define CAN_TMDTH0_TMDT5                    CAN_TMDTH0_TMDT5_Msk                    /*!< Transmit mailbox data byte 5 */
#define CAN_TMDTH0_TMDT6_Pos                (16U)
#define CAN_TMDTH0_TMDT6_Msk                (0xFFU << CAN_TMDTH0_TMDT6_Pos)         /*!< 0x00FF0000 */
#define CAN_TMDTH0_TMDT6                    CAN_TMDTH0_TMDT6_Msk                    /*!< Transmit mailbox data byte 6 */
#define CAN_TMDTH0_TMDT7_Pos                (24U)
#define CAN_TMDTH0_TMDT7_Msk                (0xFFU << CAN_TMDTH0_TMDT7_Pos)         /*!< 0xFF000000 */
#define CAN_TMDTH0_TMDT7                    CAN_TMDTH0_TMDT7_Msk                    /*!< Transmit mailbox data byte 7 */

/*******************  Bit definition for CAN_TMI1 register  *******************/
#define CAN_TMI1_TMSR_Pos                   (0U)
#define CAN_TMI1_TMSR_Msk                   (0x1U << CAN_TMI1_TMSR_Pos)             /*!< 0x00000001 */
#define CAN_TMI1_TMSR                       CAN_TMI1_TMSR_Msk                       /*!< Transmit mailbox send request */
#define CAN_TMI1_TMFRSEL_Pos                (1U)
#define CAN_TMI1_TMFRSEL_Msk                (0x1U << CAN_TMI1_TMFRSEL_Pos)          /*!< 0x00000002 */
#define CAN_TMI1_TMFRSEL                    CAN_TMI1_TMFRSEL_Msk                    /*!< Transmit mailbox frame type select */
#define CAN_TMI1_TMIDSEL_Pos                (2U)
#define CAN_TMI1_TMIDSEL_Msk                (0x1U << CAN_TMI1_TMIDSEL_Pos)          /*!< 0x00000004 */
#define CAN_TMI1_TMIDSEL                    CAN_TMI1_TMIDSEL_Msk                    /*!< Transmit mailbox identifier type select */
#define CAN_TMI1_TMEID_Pos                  (3U)
#define CAN_TMI1_TMEID_Msk                  (0x3FFFFU << CAN_TMI1_TMEID_Pos)        /*!< 0x001FFFF8 */
#define CAN_TMI1_TMEID                      CAN_TMI1_TMEID_Msk                      /*!< Transmit mailbox extended identifier */
#define CAN_TMI1_TMSID_Pos                  (21U)
#define CAN_TMI1_TMSID_Msk                  (0x7FFU << CAN_TMI1_TMSID_Pos)          /*!< 0xFFE00000 */
#define CAN_TMI1_TMSID                      CAN_TMI1_TMSID_Msk                      /*!< Transmit mailbox standard identifier or extended identifier high bytes */

/*******************  Bit definition for CAN_TMC1 register  *******************/
#define CAN_TMC1_TMDTBL_Pos                 (0U)
#define CAN_TMC1_TMDTBL_Msk                 (0xFU << CAN_TMC1_TMDTBL_Pos)           /*!< 0x0000000F */
#define CAN_TMC1_TMDTBL                     CAN_TMC1_TMDTBL_Msk                     /*!< Transmit mailbox data byte length */
#define CAN_TMC1_TMTSTEN_Pos                (8U)
#define CAN_TMC1_TMTSTEN_Msk                (0x1U << CAN_TMC1_TMTSTEN_Pos)          /*!< 0x00000100 */
#define CAN_TMC1_TMTSTEN                    CAN_TMC1_TMTSTEN_Msk                    /*!< Transmit mailbox time stamp transmit enable */
#define CAN_TMC1_TMTS_Pos                   (16U)
#define CAN_TMC1_TMTS_Msk                   (0xFFFFU << CAN_TMC1_TMTS_Pos)          /*!< 0xFFFF0000 */
#define CAN_TMC1_TMTS                       CAN_TMC1_TMTS_Msk                       /*!< Transmit mailbox time stamp */

/******************  Bit definition for CAN_TMDTL1 register  ******************/
#define CAN_TMDTL1_TMDT0_Pos                (0U)
#define CAN_TMDTL1_TMDT0_Msk                (0xFFU << CAN_TMDTL1_TMDT0_Pos)         /*!< 0x000000FF */
#define CAN_TMDTL1_TMDT0                    CAN_TMDTL1_TMDT0_Msk                    /*!< Transmit mailbox data byte 0 */
#define CAN_TMDTL1_TMDT1_Pos                (8U)
#define CAN_TMDTL1_TMDT1_Msk                (0xFFU << CAN_TMDTL1_TMDT1_Pos)         /*!< 0x0000FF00 */
#define CAN_TMDTL1_TMDT1                    CAN_TMDTL1_TMDT1_Msk                    /*!< Transmit mailbox data byte 1 */
#define CAN_TMDTL1_TMDT2_Pos                (16U)
#define CAN_TMDTL1_TMDT2_Msk                (0xFFU << CAN_TMDTL1_TMDT2_Pos)         /*!< 0x00FF0000 */
#define CAN_TMDTL1_TMDT2                    CAN_TMDTL1_TMDT2_Msk                    /*!< Transmit mailbox data byte 2 */
#define CAN_TMDTL1_TMDT3_Pos                (24U)
#define CAN_TMDTL1_TMDT3_Msk                (0xFFU << CAN_TMDTL1_TMDT3_Pos)         /*!< 0xFF000000 */
#define CAN_TMDTL1_TMDT3                    CAN_TMDTL1_TMDT3_Msk                    /*!< Transmit mailbox data byte 3 */

/******************  Bit definition for CAN_TMDTH1 register  ******************/
#define CAN_TMDTH1_TMDT4_Pos                (0U)
#define CAN_TMDTH1_TMDT4_Msk                (0xFFU << CAN_TMDTH1_TMDT4_Pos)         /*!< 0x000000FF */
#define CAN_TMDTH1_TMDT4                    CAN_TMDTH1_TMDT4_Msk                    /*!< Transmit mailbox data byte 4 */
#define CAN_TMDTH1_TMDT5_Pos                (8U)
#define CAN_TMDTH1_TMDT5_Msk                (0xFFU << CAN_TMDTH1_TMDT5_Pos)         /*!< 0x0000FF00 */
#define CAN_TMDTH1_TMDT5                    CAN_TMDTH1_TMDT5_Msk                    /*!< Transmit mailbox data byte 5 */
#define CAN_TMDTH1_TMDT6_Pos                (16U)
#define CAN_TMDTH1_TMDT6_Msk                (0xFFU << CAN_TMDTH1_TMDT6_Pos)         /*!< 0x00FF0000 */
#define CAN_TMDTH1_TMDT6                    CAN_TMDTH1_TMDT6_Msk                    /*!< Transmit mailbox data byte 6 */
#define CAN_TMDTH1_TMDT7_Pos                (24U)
#define CAN_TMDTH1_TMDT7_Msk                (0xFFU << CAN_TMDTH1_TMDT7_Pos)         /*!< 0xFF000000 */
#define CAN_TMDTH1_TMDT7                    CAN_TMDTH1_TMDT7_Msk                    /*!< Transmit mailbox data byte 7 */

/*******************  Bit definition for CAN_TMI2 register  *******************/
#define CAN_TMI2_TMSR_Pos                   (0U)
#define CAN_TMI2_TMSR_Msk                   (0x1U << CAN_TMI2_TMSR_Pos)             /*!< 0x00000001 */
#define CAN_TMI2_TMSR                       CAN_TMI2_TMSR_Msk                       /*!< Transmit mailbox send request */
#define CAN_TMI2_TMFRSEL_Pos                (1U)
#define CAN_TMI2_TMFRSEL_Msk                (0x1U << CAN_TMI2_TMFRSEL_Pos)          /*!< 0x00000002 */
#define CAN_TMI2_TMFRSEL                    CAN_TMI2_TMFRSEL_Msk                    /*!< Transmit mailbox frame type select */
#define CAN_TMI2_TMIDSEL_Pos                (2U)
#define CAN_TMI2_TMIDSEL_Msk                (0x1U << CAN_TMI2_TMIDSEL_Pos)          /*!< 0x00000004 */
#define CAN_TMI2_TMIDSEL                    CAN_TMI2_TMIDSEL_Msk                    /*!< Transmit mailbox identifier type select */
#define CAN_TMI2_TMEID_Pos                  (3U)
#define CAN_TMI2_TMEID_Msk                  (0x3FFFFU << CAN_TMI2_TMEID_Pos)        /*!< 0x001FFFF8 */
#define CAN_TMI2_TMEID                      CAN_TMI2_TMEID_Msk                      /*!< Transmit mailbox extended identifier */
#define CAN_TMI2_TMSID_Pos                  (21U)
#define CAN_TMI2_TMSID_Msk                  (0x7FFU << CAN_TMI2_TMSID_Pos)          /*!< 0xFFE00000 */
#define CAN_TMI2_TMSID                      CAN_TMI2_TMSID_Msk                      /*!< Transmit mailbox standard identifier or extended identifier high bytes */

/*******************  Bit definition for CAN_TMC2 register  *******************/
#define CAN_TMC2_TMDTBL_Pos                 (0U)
#define CAN_TMC2_TMDTBL_Msk                 (0xFU << CAN_TMC2_TMDTBL_Pos)           /*!< 0x0000000F */
#define CAN_TMC2_TMDTBL                     CAN_TMC2_TMDTBL_Msk                     /*!< Transmit mailbox data byte length */
#define CAN_TMC2_TMTSTEN_Pos                (8U)
#define CAN_TMC2_TMTSTEN_Msk                (0x1U << CAN_TMC2_TMTSTEN_Pos)          /*!< 0x00000100 */
#define CAN_TMC2_TMTSTEN                    CAN_TMC2_TMTSTEN_Msk                    /*!< Transmit mailbox time stamp transmit enable */
#define CAN_TMC2_TMTS_Pos                   (16U)
#define CAN_TMC2_TMTS_Msk                   (0xFFFFU << CAN_TMC2_TMTS_Pos)          /*!< 0xFFFF0000 */
#define CAN_TMC2_TMTS                       CAN_TMC2_TMTS_Msk                       /*!< Transmit mailbox time stamp */

/******************  Bit definition for CAN_TMDTL2 register  ******************/
#define CAN_TMDTL2_TMDT0_Pos                (0U)
#define CAN_TMDTL2_TMDT0_Msk                (0xFFU << CAN_TMDTL2_TMDT0_Pos)         /*!< 0x000000FF */
#define CAN_TMDTL2_TMDT0                    CAN_TMDTL2_TMDT0_Msk                    /*!< Transmit mailbox data byte 0 */
#define CAN_TMDTL2_TMDT1_Pos                (8U)
#define CAN_TMDTL2_TMDT1_Msk                (0xFFU << CAN_TMDTL2_TMDT1_Pos)         /*!< 0x0000FF00 */
#define CAN_TMDTL2_TMDT1                    CAN_TMDTL2_TMDT1_Msk                    /*!< Transmit mailbox data byte 1 */
#define CAN_TMDTL2_TMDT2_Pos                (16U)
#define CAN_TMDTL2_TMDT2_Msk                (0xFFU << CAN_TMDTL2_TMDT2_Pos)         /*!< 0x00FF0000 */
#define CAN_TMDTL2_TMDT2                    CAN_TMDTL2_TMDT2_Msk                    /*!< Transmit mailbox data byte 2 */
#define CAN_TMDTL2_TMDT3_Pos                (24U)
#define CAN_TMDTL2_TMDT3_Msk                (0xFFU << CAN_TMDTL2_TMDT3_Pos)         /*!< 0xFF000000 */
#define CAN_TMDTL2_TMDT3                    CAN_TMDTL2_TMDT3_Msk                    /*!< Transmit mailbox data byte 3 */

/******************  Bit definition for CAN_TMDTH2 register  ******************/
#define CAN_TMDTH2_TMDT4_Pos                (0U)
#define CAN_TMDTH2_TMDT4_Msk                (0xFFU << CAN_TMDTH2_TMDT4_Pos)         /*!< 0x000000FF */
#define CAN_TMDTH2_TMDT4                    CAN_TMDTH2_TMDT4_Msk                    /*!< Transmit mailbox data byte 4 */
#define CAN_TMDTH2_TMDT5_Pos                (8U)
#define CAN_TMDTH2_TMDT5_Msk                (0xFFU << CAN_TMDTH2_TMDT5_Pos)         /*!< 0x0000FF00 */
#define CAN_TMDTH2_TMDT5                    CAN_TMDTH2_TMDT5_Msk                    /*!< Transmit mailbox data byte 5 */
#define CAN_TMDTH2_TMDT6_Pos                (16U)
#define CAN_TMDTH2_TMDT6_Msk                (0xFFU << CAN_TMDTH2_TMDT6_Pos)         /*!< 0x00FF0000 */
#define CAN_TMDTH2_TMDT6                    CAN_TMDTH2_TMDT6_Msk                    /*!< Transmit mailbox data byte 6 */
#define CAN_TMDTH2_TMDT7_Pos                (24U)
#define CAN_TMDTH2_TMDT7_Msk                (0xFFU << CAN_TMDTH2_TMDT7_Pos)         /*!< 0xFF000000 */
#define CAN_TMDTH2_TMDT7                    CAN_TMDTH2_TMDT7_Msk                    /*!< Transmit mailbox data byte 7 */

/*******************  Bit definition for CAN_RFI0 register  *******************/
#define CAN_RFI0_RFFRI_Pos                  (1U)
#define CAN_RFI0_RFFRI_Msk                  (0x1U << CAN_RFI0_RFFRI_Pos)            /*!< 0x00000002 */
#define CAN_RFI0_RFFRI                      CAN_RFI0_RFFRI_Msk                      /*!< Receive FIFO frame type indication */
#define CAN_RFI0_RFIDI_Pos                  (2U)
#define CAN_RFI0_RFIDI_Msk                  (0x1U << CAN_RFI0_RFIDI_Pos)            /*!< 0x00000004 */
#define CAN_RFI0_RFIDI                      CAN_RFI0_RFIDI_Msk                      /*!< Receive FIFO identifier type indication */
#define CAN_RFI0_RFEID_Pos                  (3U)
#define CAN_RFI0_RFEID_Msk                  (0x3FFFFU << CAN_RFI0_RFEID_Pos)        /*!< 0x001FFFF8 */
#define CAN_RFI0_RFEID                      CAN_RFI0_RFEID_Msk                      /*!< Receive FIFO extended identifier */
#define CAN_RFI0_RFSID_Pos                  (21U)
#define CAN_RFI0_RFSID_Msk                  (0x7FFU << CAN_RFI0_RFSID_Pos)          /*!< 0xFFE00000 */
#define CAN_RFI0_RFSID                      CAN_RFI0_RFSID_Msk                      /*!< Receive FIFO standard identifier or receive FIFO extended identifier */

/*******************  Bit definition for CAN_RFC0 register  *******************/
#define CAN_RFC0_RFDTL_Pos                  (0U)
#define CAN_RFC0_RFDTL_Msk                  (0xFU << CAN_RFC0_RFDTL_Pos)            /*!< 0x0000000F */
#define CAN_RFC0_RFDTL                      CAN_RFC0_RFDTL_Msk                      /*!< Receive FIFO data length */
#define CAN_RFC0_RFFMN_Pos                  (8U)
#define CAN_RFC0_RFFMN_Msk                  (0xFFU << CAN_RFC0_RFFMN_Pos)           /*!< 0x0000FF00 */
#define CAN_RFC0_RFFMN                      CAN_RFC0_RFFMN_Msk                      /*!< Receive FIFO filter match number */
#define CAN_RFC0_RFTS_Pos                   (16U)
#define CAN_RFC0_RFTS_Msk                   (0xFFFFU << CAN_RFC0_RFTS_Pos)          /*!< 0xFFFF0000 */
#define CAN_RFC0_RFTS                       CAN_RFC0_RFTS_Msk                       /*!< Receive FIFO time stamp */

/******************  Bit definition for CAN_RFDTL0 register  ******************/
#define CAN_RFDTL0_RFDT0_Pos                (0U)
#define CAN_RFDTL0_RFDT0_Msk                (0xFFU << CAN_RFDTL0_RFDT0_Pos)         /*!< 0x000000FF */
#define CAN_RFDTL0_RFDT0                    CAN_RFDTL0_RFDT0_Msk                    /*!< Receive FIFO data byte 0 */
#define CAN_RFDTL0_RFDT1_Pos                (8U)
#define CAN_RFDTL0_RFDT1_Msk                (0xFFU << CAN_RFDTL0_RFDT1_Pos)         /*!< 0x0000FF00 */
#define CAN_RFDTL0_RFDT1                    CAN_RFDTL0_RFDT1_Msk                    /*!< Receive FIFO data byte 1 */
#define CAN_RFDTL0_RFDT2_Pos                (16U)
#define CAN_RFDTL0_RFDT2_Msk                (0xFFU << CAN_RFDTL0_RFDT2_Pos)         /*!< 0x00FF0000 */
#define CAN_RFDTL0_RFDT2                    CAN_RFDTL0_RFDT2_Msk                    /*!< Receive FIFO data byte 2 */
#define CAN_RFDTL0_RFDT3_Pos                (24U)
#define CAN_RFDTL0_RFDT3_Msk                (0xFFU << CAN_RFDTL0_RFDT3_Pos)         /*!< 0xFF000000 */
#define CAN_RFDTL0_RFDT3                    CAN_RFDTL0_RFDT3_Msk                    /*!< Receive FIFO data byte 3 */

/******************  Bit definition for CAN_RFDTH0 register  ******************/
#define CAN_RFDTH0_RFDT4_Pos                (0U)
#define CAN_RFDTH0_RFDT4_Msk                (0xFFU << CAN_RFDTH0_RFDT4_Pos)         /*!< 0x000000FF */
#define CAN_RFDTH0_RFDT4                    CAN_RFDTH0_RFDT4_Msk                    /*!< Receive FIFO data byte 4 */
#define CAN_RFDTH0_RFDT5_Pos                (8U)
#define CAN_RFDTH0_RFDT5_Msk                (0xFFU << CAN_RFDTH0_RFDT5_Pos)         /*!< 0x0000FF00 */
#define CAN_RFDTH0_RFDT5                    CAN_RFDTH0_RFDT5_Msk                    /*!< Receive FIFO data byte 5 */
#define CAN_RFDTH0_RFDT6_Pos                (16U)
#define CAN_RFDTH0_RFDT6_Msk                (0xFFU << CAN_RFDTH0_RFDT6_Pos)         /*!< 0x00FF0000 */
#define CAN_RFDTH0_RFDT6                    CAN_RFDTH0_RFDT6_Msk                    /*!< Receive FIFO data byte 6 */
#define CAN_RFDTH0_RFDT7_Pos                (24U)
#define CAN_RFDTH0_RFDT7_Msk                (0xFFU << CAN_RFDTH0_RFDT7_Pos)         /*!< 0xFF000000 */
#define CAN_RFDTH0_RFDT7                    CAN_RFDTH0_RFDT7_Msk                    /*!< Receive FIFO data byte 7 */

/*******************  Bit definition for CAN_RFI1 register  *******************/
#define CAN_RFI1_RFFRI_Pos                  (1U)
#define CAN_RFI1_RFFRI_Msk                  (0x1U << CAN_RFI1_RFFRI_Pos)            /*!< 0x00000002 */
#define CAN_RFI1_RFFRI                      CAN_RFI1_RFFRI_Msk                      /*!< Receive FIFO frame type indication */
#define CAN_RFI1_RFIDI_Pos                  (2U)
#define CAN_RFI1_RFIDI_Msk                  (0x1U << CAN_RFI1_RFIDI_Pos)            /*!< 0x00000004 */
#define CAN_RFI1_RFIDI                      CAN_RFI1_RFIDI_Msk                      /*!< Receive FIFO identifier type indication */
#define CAN_RFI1_RFEID_Pos                  (3U)
#define CAN_RFI1_RFEID_Msk                  (0x3FFFFU << CAN_RFI1_RFEID_Pos)        /*!< 0x001FFFF8 */
#define CAN_RFI1_RFEID                      CAN_RFI1_RFEID_Msk                      /*!< Receive FIFO extended identifier */
#define CAN_RFI1_RFSID_Pos                  (21U)
#define CAN_RFI1_RFSID_Msk                  (0x7FFU << CAN_RFI1_RFSID_Pos)          /*!< 0xFFE00000 */
#define CAN_RFI1_RFSID                      CAN_RFI1_RFSID_Msk                      /*!< Receive FIFO standard identifier or receive FIFO extended identifier */

/*******************  Bit definition for CAN_RFC1 register  *******************/
#define CAN_RFC1_RFDTL_Pos                  (0U)
#define CAN_RFC1_RFDTL_Msk                  (0xFU << CAN_RFC1_RFDTL_Pos)            /*!< 0x0000000F */
#define CAN_RFC1_RFDTL                      CAN_RFC1_RFDTL_Msk                      /*!< Receive FIFO data length */
#define CAN_RFC1_RFFMN_Pos                  (8U)
#define CAN_RFC1_RFFMN_Msk                  (0xFFU << CAN_RFC1_RFFMN_Pos)           /*!< 0x0000FF00 */
#define CAN_RFC1_RFFMN                      CAN_RFC1_RFFMN_Msk                      /*!< Receive FIFO filter match number */
#define CAN_RFC1_RFTS_Pos                   (16U)
#define CAN_RFC1_RFTS_Msk                   (0xFFFFU << CAN_RFC1_RFTS_Pos)          /*!< 0xFFFF0000 */
#define CAN_RFC1_RFTS                       CAN_RFC1_RFTS_Msk                       /*!< Receive FIFO time stamp */

/******************  Bit definition for CAN_RFDTL1 register  ******************/
#define CAN_RFDTL1_RFDT0_Pos                (0U)
#define CAN_RFDTL1_RFDT0_Msk                (0xFFU << CAN_RFDTL1_RFDT0_Pos)         /*!< 0x000000FF */
#define CAN_RFDTL1_RFDT0                    CAN_RFDTL1_RFDT0_Msk                    /*!< Receive FIFO data byte 0 */
#define CAN_RFDTL1_RFDT1_Pos                (8U)
#define CAN_RFDTL1_RFDT1_Msk                (0xFFU << CAN_RFDTL1_RFDT1_Pos)         /*!< 0x0000FF00 */
#define CAN_RFDTL1_RFDT1                    CAN_RFDTL1_RFDT1_Msk                    /*!< Receive FIFO data byte 1 */
#define CAN_RFDTL1_RFDT2_Pos                (16U)
#define CAN_RFDTL1_RFDT2_Msk                (0xFFU << CAN_RFDTL1_RFDT2_Pos)         /*!< 0x00FF0000 */
#define CAN_RFDTL1_RFDT2                    CAN_RFDTL1_RFDT2_Msk                    /*!< Receive FIFO data byte 2 */
#define CAN_RFDTL1_RFDT3_Pos                (24U)
#define CAN_RFDTL1_RFDT3_Msk                (0xFFU << CAN_RFDTL1_RFDT3_Pos)         /*!< 0xFF000000 */
#define CAN_RFDTL1_RFDT3                    CAN_RFDTL1_RFDT3_Msk                    /*!< Receive FIFO data byte 3 */

/******************  Bit definition for CAN_RFDTH1 register  ******************/
#define CAN_RFDTH1_RFDT4_Pos                (0U)
#define CAN_RFDTH1_RFDT4_Msk                (0xFFU << CAN_RFDTH1_RFDT4_Pos)         /*!< 0x000000FF */
#define CAN_RFDTH1_RFDT4                    CAN_RFDTH1_RFDT4_Msk                    /*!< Receive FIFO data byte 4 */
#define CAN_RFDTH1_RFDT5_Pos                (8U)
#define CAN_RFDTH1_RFDT5_Msk                (0xFFU << CAN_RFDTH1_RFDT5_Pos)         /*!< 0x0000FF00 */
#define CAN_RFDTH1_RFDT5                    CAN_RFDTH1_RFDT5_Msk                    /*!< Receive FIFO data byte 5 */
#define CAN_RFDTH1_RFDT6_Pos                (16U)
#define CAN_RFDTH1_RFDT6_Msk                (0xFFU << CAN_RFDTH1_RFDT6_Pos)         /*!< 0x00FF0000 */
#define CAN_RFDTH1_RFDT6                    CAN_RFDTH1_RFDT6_Msk                    /*!< Receive FIFO data byte 6 */
#define CAN_RFDTH1_RFDT7_Pos                (24U)
#define CAN_RFDTH1_RFDT7_Msk                (0xFFU << CAN_RFDTH1_RFDT7_Pos)         /*!< 0xFF000000 */
#define CAN_RFDTH1_RFDT7                    CAN_RFDTH1_RFDT7_Msk                    /*!< Receive FIFO data byte 7 */

/*!< CAN filter registers */
/******************  Bit definition for CAN_FCTRL register  *******************/
#define CAN_FCTRL_FCS_Pos                   (0U)
#define CAN_FCTRL_FCS_Msk                   (0x1U << CAN_FCTRL_FCS_Pos)             /*!< 0x00000001 */
#define CAN_FCTRL_FCS                       CAN_FCTRL_FCS_Msk                       /*!< Filter configuration switch */

/******************  Bit definition for CAN_FMCFG register  *******************/
#define CAN_FMCFG_FMSEL_Pos                 (0U)
#define CAN_FMCFG_FMSEL_Msk                 (0x3FFFU << CAN_FMCFG_FMSEL_Pos)        /*!< 0x00003FFF */
#define CAN_FMCFG_FMSEL                     CAN_FMCFG_FMSEL_Msk                     /*!< Filter mode select */
#define CAN_FMCFG_FMSEL0_Pos                (0U)
#define CAN_FMCFG_FMSEL0_Msk                (0x1U << CAN_FMCFG_FMSEL0_Pos)          /*!< 0x00000001 */
#define CAN_FMCFG_FMSEL0                    CAN_FMCFG_FMSEL0_Msk                    /*!< Filter mode select for filter 0 */
#define CAN_FMCFG_FMSEL1_Pos                (1U)
#define CAN_FMCFG_FMSEL1_Msk                (0x1U << CAN_FMCFG_FMSEL1_Pos)          /*!< 0x00000002 */
#define CAN_FMCFG_FMSEL1                    CAN_FMCFG_FMSEL1_Msk                    /*!< Filter mode select for filter 1 */
#define CAN_FMCFG_FMSEL2_Pos                (2U)
#define CAN_FMCFG_FMSEL2_Msk                (0x1U << CAN_FMCFG_FMSEL2_Pos)          /*!< 0x00000004 */
#define CAN_FMCFG_FMSEL2                    CAN_FMCFG_FMSEL2_Msk                    /*!< Filter mode select for filter 2 */
#define CAN_FMCFG_FMSEL3_Pos                (3U)
#define CAN_FMCFG_FMSEL3_Msk                (0x1U << CAN_FMCFG_FMSEL3_Pos)          /*!< 0x00000008 */
#define CAN_FMCFG_FMSEL3                    CAN_FMCFG_FMSEL3_Msk                    /*!< Filter mode select for filter 3 */
#define CAN_FMCFG_FMSEL4_Pos                (4U)
#define CAN_FMCFG_FMSEL4_Msk                (0x1U << CAN_FMCFG_FMSEL4_Pos)          /*!< 0x00000010 */
#define CAN_FMCFG_FMSEL4                    CAN_FMCFG_FMSEL4_Msk                    /*!< Filter mode select for filter 4 */
#define CAN_FMCFG_FMSEL5_Pos                (5U)
#define CAN_FMCFG_FMSEL5_Msk                (0x1U << CAN_FMCFG_FMSEL5_Pos)          /*!< 0x00000020 */
#define CAN_FMCFG_FMSEL5                    CAN_FMCFG_FMSEL5_Msk                    /*!< Filter mode select for filter 5 */
#define CAN_FMCFG_FMSEL6_Pos                (6U)
#define CAN_FMCFG_FMSEL6_Msk                (0x1U << CAN_FMCFG_FMSEL6_Pos)          /*!< 0x00000040 */
#define CAN_FMCFG_FMSEL6                    CAN_FMCFG_FMSEL6_Msk                    /*!< Filter mode select for filter 6 */
#define CAN_FMCFG_FMSEL7_Pos                (7U)
#define CAN_FMCFG_FMSEL7_Msk                (0x1U << CAN_FMCFG_FMSEL7_Pos)          /*!< 0x00000080 */
#define CAN_FMCFG_FMSEL7                    CAN_FMCFG_FMSEL7_Msk                    /*!< Filter mode select for filter 7 */
#define CAN_FMCFG_FMSEL8_Pos                (8U)
#define CAN_FMCFG_FMSEL8_Msk                (0x1U << CAN_FMCFG_FMSEL8_Pos)          /*!< 0x00000100 */
#define CAN_FMCFG_FMSEL8                    CAN_FMCFG_FMSEL8_Msk                    /*!< Filter mode select for filter 8 */
#define CAN_FMCFG_FMSEL9_Pos                (9U)
#define CAN_FMCFG_FMSEL9_Msk                (0x1U << CAN_FMCFG_FMSEL9_Pos)          /*!< 0x00000200 */
#define CAN_FMCFG_FMSEL9                    CAN_FMCFG_FMSEL9_Msk                    /*!< Filter mode select for filter 9 */
#define CAN_FMCFG_FMSEL10_Pos               (10U)
#define CAN_FMCFG_FMSEL10_Msk               (0x1U << CAN_FMCFG_FMSEL10_Pos)         /*!< 0x00000400 */
#define CAN_FMCFG_FMSEL10                   CAN_FMCFG_FMSEL10_Msk                   /*!< Filter mode select for filter 10 */
#define CAN_FMCFG_FMSEL11_Pos               (11U)
#define CAN_FMCFG_FMSEL11_Msk               (0x1U << CAN_FMCFG_FMSEL11_Pos)         /*!< 0x00000800 */
#define CAN_FMCFG_FMSEL11                   CAN_FMCFG_FMSEL11_Msk                   /*!< Filter mode select for filter 11 */
#define CAN_FMCFG_FMSEL12_Pos               (12U)
#define CAN_FMCFG_FMSEL12_Msk               (0x1U << CAN_FMCFG_FMSEL12_Pos)         /*!< 0x00001000 */
#define CAN_FMCFG_FMSEL12                   CAN_FMCFG_FMSEL12_Msk                   /*!< Filter mode select for filter 12 */
#define CAN_FMCFG_FMSEL13_Pos               (13U)
#define CAN_FMCFG_FMSEL13_Msk               (0x1U << CAN_FMCFG_FMSEL13_Pos)         /*!< 0x00002000 */
#define CAN_FMCFG_FMSEL13                   CAN_FMCFG_FMSEL13_Msk                   /*!< Filter mode select for filter 13 */

/******************  Bit definition for CAN_FBWCFG register  ******************/
#define CAN_FBWCFG_FBWSEL_Pos               (0U)
#define CAN_FBWCFG_FBWSEL_Msk               (0x3FFFU << CAN_FBWCFG_FBWSEL_Pos)      /*!< 0x00003FFF */
#define CAN_FBWCFG_FBWSEL                   CAN_FBWCFG_FBWSEL_Msk                   /*!< Filter bit width select */
#define CAN_FBWCFG_FBWSEL0_Pos              (0U)
#define CAN_FBWCFG_FBWSEL0_Msk              (0x1U << CAN_FBWCFG_FBWSEL0_Pos)        /*!< 0x00000001 */
#define CAN_FBWCFG_FBWSEL0                  CAN_FBWCFG_FBWSEL0_Msk                  /*!< Filter bit width select for filter 0 */
#define CAN_FBWCFG_FBWSEL1_Pos              (1U)
#define CAN_FBWCFG_FBWSEL1_Msk              (0x1U << CAN_FBWCFG_FBWSEL1_Pos)        /*!< 0x00000002 */
#define CAN_FBWCFG_FBWSEL1                  CAN_FBWCFG_FBWSEL1_Msk                  /*!< Filter bit width select for filter 1 */
#define CAN_FBWCFG_FBWSEL2_Pos              (2U)
#define CAN_FBWCFG_FBWSEL2_Msk              (0x1U << CAN_FBWCFG_FBWSEL2_Pos)        /*!< 0x00000004 */
#define CAN_FBWCFG_FBWSEL2                  CAN_FBWCFG_FBWSEL2_Msk                  /*!< Filter bit width select for filter 2 */
#define CAN_FBWCFG_FBWSEL3_Pos              (3U)
#define CAN_FBWCFG_FBWSEL3_Msk              (0x1U << CAN_FBWCFG_FBWSEL3_Pos)        /*!< 0x00000008 */
#define CAN_FBWCFG_FBWSEL3                  CAN_FBWCFG_FBWSEL3_Msk                  /*!< Filter bit width select for filter 3 */
#define CAN_FBWCFG_FBWSEL4_Pos              (4U)
#define CAN_FBWCFG_FBWSEL4_Msk              (0x1U << CAN_FBWCFG_FBWSEL4_Pos)        /*!< 0x00000010 */
#define CAN_FBWCFG_FBWSEL4                  CAN_FBWCFG_FBWSEL4_Msk                  /*!< Filter bit width select for filter 4 */
#define CAN_FBWCFG_FBWSEL5_Pos              (5U)
#define CAN_FBWCFG_FBWSEL5_Msk              (0x1U << CAN_FBWCFG_FBWSEL5_Pos)        /*!< 0x00000020 */
#define CAN_FBWCFG_FBWSEL5                  CAN_FBWCFG_FBWSEL5_Msk                  /*!< Filter bit width select for filter 5 */
#define CAN_FBWCFG_FBWSEL6_Pos              (6U)
#define CAN_FBWCFG_FBWSEL6_Msk              (0x1U << CAN_FBWCFG_FBWSEL6_Pos)        /*!< 0x00000040 */
#define CAN_FBWCFG_FBWSEL6                  CAN_FBWCFG_FBWSEL6_Msk                  /*!< Filter bit width select for filter 6 */
#define CAN_FBWCFG_FBWSEL7_Pos              (7U)
#define CAN_FBWCFG_FBWSEL7_Msk              (0x1U << CAN_FBWCFG_FBWSEL7_Pos)        /*!< 0x00000080 */
#define CAN_FBWCFG_FBWSEL7                  CAN_FBWCFG_FBWSEL7_Msk                  /*!< Filter bit width select for filter 7 */
#define CAN_FBWCFG_FBWSEL8_Pos              (8U)
#define CAN_FBWCFG_FBWSEL8_Msk              (0x1U << CAN_FBWCFG_FBWSEL8_Pos)        /*!< 0x00000100 */
#define CAN_FBWCFG_FBWSEL8                  CAN_FBWCFG_FBWSEL8_Msk                  /*!< Filter bit width select for filter 8 */
#define CAN_FBWCFG_FBWSEL9_Pos              (9U)
#define CAN_FBWCFG_FBWSEL9_Msk              (0x1U << CAN_FBWCFG_FBWSEL9_Pos)        /*!< 0x00000200 */
#define CAN_FBWCFG_FBWSEL9                  CAN_FBWCFG_FBWSEL9_Msk                  /*!< Filter bit width select for filter 9 */
#define CAN_FBWCFG_FBWSEL10_Pos             (10U)
#define CAN_FBWCFG_FBWSEL10_Msk             (0x1U << CAN_FBWCFG_FBWSEL10_Pos)       /*!< 0x00000400 */
#define CAN_FBWCFG_FBWSEL10                 CAN_FBWCFG_FBWSEL10_Msk                 /*!< Filter bit width select for filter 10 */
#define CAN_FBWCFG_FBWSEL11_Pos             (11U)
#define CAN_FBWCFG_FBWSEL11_Msk             (0x1U << CAN_FBWCFG_FBWSEL11_Pos)       /*!< 0x00000800 */
#define CAN_FBWCFG_FBWSEL11                 CAN_FBWCFG_FBWSEL11_Msk                 /*!< Filter bit width select for filter 11 */
#define CAN_FBWCFG_FBWSEL12_Pos             (12U)
#define CAN_FBWCFG_FBWSEL12_Msk             (0x1U << CAN_FBWCFG_FBWSEL12_Pos)       /*!< 0x00001000 */
#define CAN_FBWCFG_FBWSEL12                 CAN_FBWCFG_FBWSEL12_Msk                 /*!< Filter bit width select for filter 12 */
#define CAN_FBWCFG_FBWSEL13_Pos             (13U)
#define CAN_FBWCFG_FBWSEL13_Msk             (0x1U << CAN_FBWCFG_FBWSEL13_Pos)       /*!< 0x00002000 */
#define CAN_FBWCFG_FBWSEL13                 CAN_FBWCFG_FBWSEL13_Msk                 /*!< Filter bit width select for filter 13 */

/*******************  Bit definition for CAN_FRF register  ********************/
#define CAN_FRF_FRFSEL_Pos                  (0U)
#define CAN_FRF_FRFSEL_Msk                  (0x3FFFU << CAN_FRF_FRFSEL_Pos)         /*!< 0x00003FFF */
#define CAN_FRF_FRFSEL                      CAN_FRF_FRFSEL_Msk                      /*!< Filter relation FIFO select */
#define CAN_FRF_FRFSEL0_Pos                 (0U)
#define CAN_FRF_FRFSEL0_Msk                 (0x1U << CAN_FRF_FRFSEL0_Pos)           /*!< 0x00000001 */
#define CAN_FRF_FRFSEL0                     CAN_FRF_FRFSEL0_Msk                     /*!< Filter relation FIFO select for filter 0 */
#define CAN_FRF_FRFSEL1_Pos                 (1U)
#define CAN_FRF_FRFSEL1_Msk                 (0x1U << CAN_FRF_FRFSEL1_Pos)           /*!< 0x00000002 */
#define CAN_FRF_FRFSEL1                     CAN_FRF_FRFSEL1_Msk                     /*!< Filter relation FIFO select for filter 1 */
#define CAN_FRF_FRFSEL2_Pos                 (2U)
#define CAN_FRF_FRFSEL2_Msk                 (0x1U << CAN_FRF_FRFSEL2_Pos)           /*!< 0x00000004 */
#define CAN_FRF_FRFSEL2                     CAN_FRF_FRFSEL2_Msk                     /*!< Filter relation FIFO select for filter 2 */
#define CAN_FRF_FRFSEL3_Pos                 (3U)
#define CAN_FRF_FRFSEL3_Msk                 (0x1U << CAN_FRF_FRFSEL3_Pos)           /*!< 0x00000008 */
#define CAN_FRF_FRFSEL3                     CAN_FRF_FRFSEL3_Msk                     /*!< Filter relation FIFO select for filter 3 */
#define CAN_FRF_FRFSEL4_Pos                 (4U)
#define CAN_FRF_FRFSEL4_Msk                 (0x1U << CAN_FRF_FRFSEL4_Pos)           /*!< 0x00000010 */
#define CAN_FRF_FRFSEL4                     CAN_FRF_FRFSEL4_Msk                     /*!< Filter relation FIFO select for filter 4 */
#define CAN_FRF_FRFSEL5_Pos                 (5U)
#define CAN_FRF_FRFSEL5_Msk                 (0x1U << CAN_FRF_FRFSEL5_Pos)           /*!< 0x00000020 */
#define CAN_FRF_FRFSEL5                     CAN_FRF_FRFSEL5_Msk                     /*!< Filter relation FIFO select for filter 5 */
#define CAN_FRF_FRFSEL6_Pos                 (6U)
#define CAN_FRF_FRFSEL6_Msk                 (0x1U << CAN_FRF_FRFSEL6_Pos)           /*!< 0x00000040 */
#define CAN_FRF_FRFSEL6                     CAN_FRF_FRFSEL6_Msk                     /*!< Filter relation FIFO select for filter 6 */
#define CAN_FRF_FRFSEL7_Pos                 (7U)
#define CAN_FRF_FRFSEL7_Msk                 (0x1U << CAN_FRF_FRFSEL7_Pos)           /*!< 0x00000080 */
#define CAN_FRF_FRFSEL7                     CAN_FRF_FRFSEL7_Msk                     /*!< Filter relation FIFO select for filter 7 */
#define CAN_FRF_FRFSEL8_Pos                 (8U)
#define CAN_FRF_FRFSEL8_Msk                 (0x1U << CAN_FRF_FRFSEL8_Pos)           /*!< 0x00000100 */
#define CAN_FRF_FRFSEL8                     CAN_FRF_FRFSEL8_Msk                     /*!< Filter relation FIFO select for filter 8 */
#define CAN_FRF_FRFSEL9_Pos                 (9U)
#define CAN_FRF_FRFSEL9_Msk                 (0x1U << CAN_FRF_FRFSEL9_Pos)           /*!< 0x00000200 */
#define CAN_FRF_FRFSEL9                     CAN_FRF_FRFSEL9_Msk                     /*!< Filter relation FIFO select for filter 9 */
#define CAN_FRF_FRFSEL10_Pos                (10U)
#define CAN_FRF_FRFSEL10_Msk                (0x1U << CAN_FRF_FRFSEL10_Pos)          /*!< 0x00000400 */
#define CAN_FRF_FRFSEL10                    CAN_FRF_FRFSEL10_Msk                    /*!< Filter relation FIFO select for filter 10 */
#define CAN_FRF_FRFSEL11_Pos                (11U)
#define CAN_FRF_FRFSEL11_Msk                (0x1U << CAN_FRF_FRFSEL11_Pos)          /*!< 0x00000800 */
#define CAN_FRF_FRFSEL11                    CAN_FRF_FRFSEL11_Msk                    /*!< Filter relation FIFO select for filter 11 */
#define CAN_FRF_FRFSEL12_Pos                (12U)
#define CAN_FRF_FRFSEL12_Msk                (0x1U << CAN_FRF_FRFSEL12_Pos)          /*!< 0x00001000 */
#define CAN_FRF_FRFSEL12                    CAN_FRF_FRFSEL12_Msk                    /*!< Filter relation FIFO select for filter 12 */
#define CAN_FRF_FRFSEL13_Pos                (13U)
#define CAN_FRF_FRFSEL13_Msk                (0x1U << CAN_FRF_FRFSEL13_Pos)          /*!< 0x00002000 */
#define CAN_FRF_FRFSEL13                    CAN_FRF_FRFSEL13_Msk                    /*!< Filter relation FIFO select for filter 13 */

/******************  Bit definition for CAN_FACFG register  *******************/
#define CAN_FACFG_FAEN_Pos                  (0U)
#define CAN_FACFG_FAEN_Msk                  (0x3FFFU << CAN_FACFG_FAEN_Pos)         /*!< 0x00003FFF */
#define CAN_FACFG_FAEN                      CAN_FACFG_FAEN_Msk                      /*!< Filter active enable */
#define CAN_FACFG_FAEN0_Pos                 (0U)
#define CAN_FACFG_FAEN0_Msk                 (0x1U << CAN_FACFG_FAEN0_Pos)           /*!< 0x00000001 */
#define CAN_FACFG_FAEN0                     CAN_FACFG_FAEN0_Msk                     /*!< Filter 0 active enable */
#define CAN_FACFG_FAEN1_Pos                 (1U)
#define CAN_FACFG_FAEN1_Msk                 (0x1U << CAN_FACFG_FAEN1_Pos)           /*!< 0x00000002 */
#define CAN_FACFG_FAEN1                     CAN_FACFG_FAEN1_Msk                     /*!< Filter 1 active enable */
#define CAN_FACFG_FAEN2_Pos                 (2U)
#define CAN_FACFG_FAEN2_Msk                 (0x1U << CAN_FACFG_FAEN2_Pos)           /*!< 0x00000004 */
#define CAN_FACFG_FAEN2                     CAN_FACFG_FAEN2_Msk                     /*!< Filter 2 active enable */
#define CAN_FACFG_FAEN3_Pos                 (3U)
#define CAN_FACFG_FAEN3_Msk                 (0x1U << CAN_FACFG_FAEN3_Pos)           /*!< 0x00000008 */
#define CAN_FACFG_FAEN3                     CAN_FACFG_FAEN3_Msk                     /*!< Filter 3 active enable */
#define CAN_FACFG_FAEN4_Pos                 (4U)
#define CAN_FACFG_FAEN4_Msk                 (0x1U << CAN_FACFG_FAEN4_Pos)           /*!< 0x00000010 */
#define CAN_FACFG_FAEN4                     CAN_FACFG_FAEN4_Msk                     /*!< Filter 4 active enable */
#define CAN_FACFG_FAEN5_Pos                 (5U)
#define CAN_FACFG_FAEN5_Msk                 (0x1U << CAN_FACFG_FAEN5_Pos)           /*!< 0x00000020 */
#define CAN_FACFG_FAEN5                     CAN_FACFG_FAEN5_Msk                     /*!< Filter 5 active enable */
#define CAN_FACFG_FAEN6_Pos                 (6U)
#define CAN_FACFG_FAEN6_Msk                 (0x1U << CAN_FACFG_FAEN6_Pos)           /*!< 0x00000040 */
#define CAN_FACFG_FAEN6                     CAN_FACFG_FAEN6_Msk                     /*!< Filter 6 active enable */
#define CAN_FACFG_FAEN7_Pos                 (7U)
#define CAN_FACFG_FAEN7_Msk                 (0x1U << CAN_FACFG_FAEN7_Pos)           /*!< 0x00000080 */
#define CAN_FACFG_FAEN7                     CAN_FACFG_FAEN7_Msk                     /*!< Filter 7 active enable */
#define CAN_FACFG_FAEN8_Pos                 (8U)
#define CAN_FACFG_FAEN8_Msk                 (0x1U << CAN_FACFG_FAEN8_Pos)           /*!< 0x00000100 */
#define CAN_FACFG_FAEN8                     CAN_FACFG_FAEN8_Msk                     /*!< Filter 8 active enable */
#define CAN_FACFG_FAEN9_Pos                 (9U)
#define CAN_FACFG_FAEN9_Msk                 (0x1U << CAN_FACFG_FAEN9_Pos)           /*!< 0x00000200 */
#define CAN_FACFG_FAEN9                     CAN_FACFG_FAEN9_Msk                     /*!< Filter 9 active enable */
#define CAN_FACFG_FAEN10_Pos                (10U)
#define CAN_FACFG_FAEN10_Msk                (0x1U << CAN_FACFG_FAEN10_Pos)          /*!< 0x00000400 */
#define CAN_FACFG_FAEN10                    CAN_FACFG_FAEN10_Msk                    /*!< Filter 10 active enable */
#define CAN_FACFG_FAEN11_Pos                (11U)
#define CAN_FACFG_FAEN11_Msk                (0x1U << CAN_FACFG_FAEN11_Pos)          /*!< 0x00000800 */
#define CAN_FACFG_FAEN11                    CAN_FACFG_FAEN11_Msk                    /*!< Filter 11 active enable */
#define CAN_FACFG_FAEN12_Pos                (12U)
#define CAN_FACFG_FAEN12_Msk                (0x1U << CAN_FACFG_FAEN12_Pos)          /*!< 0x00001000 */
#define CAN_FACFG_FAEN12                    CAN_FACFG_FAEN12_Msk                    /*!< Filter 12 active enable */
#define CAN_FACFG_FAEN13_Pos                (13U)
#define CAN_FACFG_FAEN13_Msk                (0x1U << CAN_FACFG_FAEN13_Pos)          /*!< 0x00002000 */
#define CAN_FACFG_FAEN13                    CAN_FACFG_FAEN13_Msk                    /*!< Filter 13 active enable */

/******************  Bit definition for CAN_F0FB1 register  *******************/
#define CAN_F0FB1_FFDB0_Pos                 (0U)
#define CAN_F0FB1_FFDB0_Msk                 (0x1U << CAN_F0FB1_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F0FB1_FFDB0                     CAN_F0FB1_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F0FB1_FFDB1_Pos                 (1U)
#define CAN_F0FB1_FFDB1_Msk                 (0x1U << CAN_F0FB1_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F0FB1_FFDB1                     CAN_F0FB1_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F0FB1_FFDB2_Pos                 (2U)
#define CAN_F0FB1_FFDB2_Msk                 (0x1U << CAN_F0FB1_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F0FB1_FFDB2                     CAN_F0FB1_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F0FB1_FFDB3_Pos                 (3U)
#define CAN_F0FB1_FFDB3_Msk                 (0x1U << CAN_F0FB1_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F0FB1_FFDB3                     CAN_F0FB1_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F0FB1_FFDB4_Pos                 (4U)
#define CAN_F0FB1_FFDB4_Msk                 (0x1U << CAN_F0FB1_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F0FB1_FFDB4                     CAN_F0FB1_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F0FB1_FFDB5_Pos                 (5U)
#define CAN_F0FB1_FFDB5_Msk                 (0x1U << CAN_F0FB1_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F0FB1_FFDB5                     CAN_F0FB1_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F0FB1_FFDB6_Pos                 (6U)
#define CAN_F0FB1_FFDB6_Msk                 (0x1U << CAN_F0FB1_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F0FB1_FFDB6                     CAN_F0FB1_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F0FB1_FFDB7_Pos                 (7U)
#define CAN_F0FB1_FFDB7_Msk                 (0x1U << CAN_F0FB1_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F0FB1_FFDB7                     CAN_F0FB1_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F0FB1_FFDB8_Pos                 (8U)
#define CAN_F0FB1_FFDB8_Msk                 (0x1U << CAN_F0FB1_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F0FB1_FFDB8                     CAN_F0FB1_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F0FB1_FFDB9_Pos                 (9U)
#define CAN_F0FB1_FFDB9_Msk                 (0x1U << CAN_F0FB1_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F0FB1_FFDB9                     CAN_F0FB1_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F0FB1_FFDB10_Pos                (10U)
#define CAN_F0FB1_FFDB10_Msk                (0x1U << CAN_F0FB1_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F0FB1_FFDB10                    CAN_F0FB1_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F0FB1_FFDB11_Pos                (11U)
#define CAN_F0FB1_FFDB11_Msk                (0x1U << CAN_F0FB1_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F0FB1_FFDB11                    CAN_F0FB1_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F0FB1_FFDB12_Pos                (12U)
#define CAN_F0FB1_FFDB12_Msk                (0x1U << CAN_F0FB1_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F0FB1_FFDB12                    CAN_F0FB1_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F0FB1_FFDB13_Pos                (13U)
#define CAN_F0FB1_FFDB13_Msk                (0x1U << CAN_F0FB1_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F0FB1_FFDB13                    CAN_F0FB1_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F0FB1_FFDB14_Pos                (14U)
#define CAN_F0FB1_FFDB14_Msk                (0x1U << CAN_F0FB1_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F0FB1_FFDB14                    CAN_F0FB1_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F0FB1_FFDB15_Pos                (15U)
#define CAN_F0FB1_FFDB15_Msk                (0x1U << CAN_F0FB1_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F0FB1_FFDB15                    CAN_F0FB1_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F0FB1_FFDB16_Pos                (16U)
#define CAN_F0FB1_FFDB16_Msk                (0x1U << CAN_F0FB1_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F0FB1_FFDB16                    CAN_F0FB1_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F0FB1_FFDB17_Pos                (17U)
#define CAN_F0FB1_FFDB17_Msk                (0x1U << CAN_F0FB1_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F0FB1_FFDB17                    CAN_F0FB1_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F0FB1_FFDB18_Pos                (18U)
#define CAN_F0FB1_FFDB18_Msk                (0x1U << CAN_F0FB1_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F0FB1_FFDB18                    CAN_F0FB1_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F0FB1_FFDB19_Pos                (19U)
#define CAN_F0FB1_FFDB19_Msk                (0x1U << CAN_F0FB1_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F0FB1_FFDB19                    CAN_F0FB1_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F0FB1_FFDB20_Pos                (20U)
#define CAN_F0FB1_FFDB20_Msk                (0x1U << CAN_F0FB1_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F0FB1_FFDB20                    CAN_F0FB1_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F0FB1_FFDB21_Pos                (21U)
#define CAN_F0FB1_FFDB21_Msk                (0x1U << CAN_F0FB1_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F0FB1_FFDB21                    CAN_F0FB1_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F0FB1_FFDB22_Pos                (22U)
#define CAN_F0FB1_FFDB22_Msk                (0x1U << CAN_F0FB1_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F0FB1_FFDB22                    CAN_F0FB1_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F0FB1_FFDB23_Pos                (23U)
#define CAN_F0FB1_FFDB23_Msk                (0x1U << CAN_F0FB1_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F0FB1_FFDB23                    CAN_F0FB1_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F0FB1_FFDB24_Pos                (24U)
#define CAN_F0FB1_FFDB24_Msk                (0x1U << CAN_F0FB1_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F0FB1_FFDB24                    CAN_F0FB1_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F0FB1_FFDB25_Pos                (25U)
#define CAN_F0FB1_FFDB25_Msk                (0x1U << CAN_F0FB1_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F0FB1_FFDB25                    CAN_F0FB1_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F0FB1_FFDB26_Pos                (26U)
#define CAN_F0FB1_FFDB26_Msk                (0x1U << CAN_F0FB1_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F0FB1_FFDB26                    CAN_F0FB1_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F0FB1_FFDB27_Pos                (27U)
#define CAN_F0FB1_FFDB27_Msk                (0x1U << CAN_F0FB1_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F0FB1_FFDB27                    CAN_F0FB1_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F0FB1_FFDB28_Pos                (28U)
#define CAN_F0FB1_FFDB28_Msk                (0x1U << CAN_F0FB1_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F0FB1_FFDB28                    CAN_F0FB1_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F0FB1_FFDB29_Pos                (29U)
#define CAN_F0FB1_FFDB29_Msk                (0x1U << CAN_F0FB1_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F0FB1_FFDB29                    CAN_F0FB1_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F0FB1_FFDB30_Pos                (30U)
#define CAN_F0FB1_FFDB30_Msk                (0x1U << CAN_F0FB1_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F0FB1_FFDB30                    CAN_F0FB1_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F0FB1_FFDB31_Pos                (31U)
#define CAN_F0FB1_FFDB31_Msk                (0x1U << CAN_F0FB1_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F0FB1_FFDB31                    CAN_F0FB1_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F1FB1 register  *******************/
#define CAN_F1FB1_FFDB0_Pos                 (0U)
#define CAN_F1FB1_FFDB0_Msk                 (0x1U << CAN_F1FB1_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F1FB1_FFDB0                     CAN_F1FB1_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F1FB1_FFDB1_Pos                 (1U)
#define CAN_F1FB1_FFDB1_Msk                 (0x1U << CAN_F1FB1_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F1FB1_FFDB1                     CAN_F1FB1_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F1FB1_FFDB2_Pos                 (2U)
#define CAN_F1FB1_FFDB2_Msk                 (0x1U << CAN_F1FB1_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F1FB1_FFDB2                     CAN_F1FB1_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F1FB1_FFDB3_Pos                 (3U)
#define CAN_F1FB1_FFDB3_Msk                 (0x1U << CAN_F1FB1_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F1FB1_FFDB3                     CAN_F1FB1_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F1FB1_FFDB4_Pos                 (4U)
#define CAN_F1FB1_FFDB4_Msk                 (0x1U << CAN_F1FB1_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F1FB1_FFDB4                     CAN_F1FB1_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F1FB1_FFDB5_Pos                 (5U)
#define CAN_F1FB1_FFDB5_Msk                 (0x1U << CAN_F1FB1_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F1FB1_FFDB5                     CAN_F1FB1_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F1FB1_FFDB6_Pos                 (6U)
#define CAN_F1FB1_FFDB6_Msk                 (0x1U << CAN_F1FB1_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F1FB1_FFDB6                     CAN_F1FB1_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F1FB1_FFDB7_Pos                 (7U)
#define CAN_F1FB1_FFDB7_Msk                 (0x1U << CAN_F1FB1_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F1FB1_FFDB7                     CAN_F1FB1_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F1FB1_FFDB8_Pos                 (8U)
#define CAN_F1FB1_FFDB8_Msk                 (0x1U << CAN_F1FB1_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F1FB1_FFDB8                     CAN_F1FB1_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F1FB1_FFDB9_Pos                 (9U)
#define CAN_F1FB1_FFDB9_Msk                 (0x1U << CAN_F1FB1_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F1FB1_FFDB9                     CAN_F1FB1_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F1FB1_FFDB10_Pos                (10U)
#define CAN_F1FB1_FFDB10_Msk                (0x1U << CAN_F1FB1_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F1FB1_FFDB10                    CAN_F1FB1_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F1FB1_FFDB11_Pos                (11U)
#define CAN_F1FB1_FFDB11_Msk                (0x1U << CAN_F1FB1_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F1FB1_FFDB11                    CAN_F1FB1_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F1FB1_FFDB12_Pos                (12U)
#define CAN_F1FB1_FFDB12_Msk                (0x1U << CAN_F1FB1_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F1FB1_FFDB12                    CAN_F1FB1_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F1FB1_FFDB13_Pos                (13U)
#define CAN_F1FB1_FFDB13_Msk                (0x1U << CAN_F1FB1_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F1FB1_FFDB13                    CAN_F1FB1_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F1FB1_FFDB14_Pos                (14U)
#define CAN_F1FB1_FFDB14_Msk                (0x1U << CAN_F1FB1_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F1FB1_FFDB14                    CAN_F1FB1_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F1FB1_FFDB15_Pos                (15U)
#define CAN_F1FB1_FFDB15_Msk                (0x1U << CAN_F1FB1_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F1FB1_FFDB15                    CAN_F1FB1_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F1FB1_FFDB16_Pos                (16U)
#define CAN_F1FB1_FFDB16_Msk                (0x1U << CAN_F1FB1_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F1FB1_FFDB16                    CAN_F1FB1_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F1FB1_FFDB17_Pos                (17U)
#define CAN_F1FB1_FFDB17_Msk                (0x1U << CAN_F1FB1_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F1FB1_FFDB17                    CAN_F1FB1_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F1FB1_FFDB18_Pos                (18U)
#define CAN_F1FB1_FFDB18_Msk                (0x1U << CAN_F1FB1_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F1FB1_FFDB18                    CAN_F1FB1_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F1FB1_FFDB19_Pos                (19U)
#define CAN_F1FB1_FFDB19_Msk                (0x1U << CAN_F1FB1_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F1FB1_FFDB19                    CAN_F1FB1_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F1FB1_FFDB20_Pos                (20U)
#define CAN_F1FB1_FFDB20_Msk                (0x1U << CAN_F1FB1_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F1FB1_FFDB20                    CAN_F1FB1_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F1FB1_FFDB21_Pos                (21U)
#define CAN_F1FB1_FFDB21_Msk                (0x1U << CAN_F1FB1_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F1FB1_FFDB21                    CAN_F1FB1_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F1FB1_FFDB22_Pos                (22U)
#define CAN_F1FB1_FFDB22_Msk                (0x1U << CAN_F1FB1_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F1FB1_FFDB22                    CAN_F1FB1_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F1FB1_FFDB23_Pos                (23U)
#define CAN_F1FB1_FFDB23_Msk                (0x1U << CAN_F1FB1_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F1FB1_FFDB23                    CAN_F1FB1_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F1FB1_FFDB24_Pos                (24U)
#define CAN_F1FB1_FFDB24_Msk                (0x1U << CAN_F1FB1_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F1FB1_FFDB24                    CAN_F1FB1_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F1FB1_FFDB25_Pos                (25U)
#define CAN_F1FB1_FFDB25_Msk                (0x1U << CAN_F1FB1_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F1FB1_FFDB25                    CAN_F1FB1_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F1FB1_FFDB26_Pos                (26U)
#define CAN_F1FB1_FFDB26_Msk                (0x1U << CAN_F1FB1_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F1FB1_FFDB26                    CAN_F1FB1_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F1FB1_FFDB27_Pos                (27U)
#define CAN_F1FB1_FFDB27_Msk                (0x1U << CAN_F1FB1_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F1FB1_FFDB27                    CAN_F1FB1_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F1FB1_FFDB28_Pos                (28U)
#define CAN_F1FB1_FFDB28_Msk                (0x1U << CAN_F1FB1_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F1FB1_FFDB28                    CAN_F1FB1_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F1FB1_FFDB29_Pos                (29U)
#define CAN_F1FB1_FFDB29_Msk                (0x1U << CAN_F1FB1_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F1FB1_FFDB29                    CAN_F1FB1_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F1FB1_FFDB30_Pos                (30U)
#define CAN_F1FB1_FFDB30_Msk                (0x1U << CAN_F1FB1_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F1FB1_FFDB30                    CAN_F1FB1_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F1FB1_FFDB31_Pos                (31U)
#define CAN_F1FB1_FFDB31_Msk                (0x1U << CAN_F1FB1_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F1FB1_FFDB31                    CAN_F1FB1_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F2FB1 register  *******************/
#define CAN_F2FB1_FFDB0_Pos                 (0U)
#define CAN_F2FB1_FFDB0_Msk                 (0x1U << CAN_F2FB1_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F2FB1_FFDB0                     CAN_F2FB1_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F2FB1_FFDB1_Pos                 (1U)
#define CAN_F2FB1_FFDB1_Msk                 (0x1U << CAN_F2FB1_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F2FB1_FFDB1                     CAN_F2FB1_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F2FB1_FFDB2_Pos                 (2U)
#define CAN_F2FB1_FFDB2_Msk                 (0x1U << CAN_F2FB1_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F2FB1_FFDB2                     CAN_F2FB1_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F2FB1_FFDB3_Pos                 (3U)
#define CAN_F2FB1_FFDB3_Msk                 (0x1U << CAN_F2FB1_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F2FB1_FFDB3                     CAN_F2FB1_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F2FB1_FFDB4_Pos                 (4U)
#define CAN_F2FB1_FFDB4_Msk                 (0x1U << CAN_F2FB1_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F2FB1_FFDB4                     CAN_F2FB1_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F2FB1_FFDB5_Pos                 (5U)
#define CAN_F2FB1_FFDB5_Msk                 (0x1U << CAN_F2FB1_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F2FB1_FFDB5                     CAN_F2FB1_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F2FB1_FFDB6_Pos                 (6U)
#define CAN_F2FB1_FFDB6_Msk                 (0x1U << CAN_F2FB1_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F2FB1_FFDB6                     CAN_F2FB1_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F2FB1_FFDB7_Pos                 (7U)
#define CAN_F2FB1_FFDB7_Msk                 (0x1U << CAN_F2FB1_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F2FB1_FFDB7                     CAN_F2FB1_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F2FB1_FFDB8_Pos                 (8U)
#define CAN_F2FB1_FFDB8_Msk                 (0x1U << CAN_F2FB1_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F2FB1_FFDB8                     CAN_F2FB1_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F2FB1_FFDB9_Pos                 (9U)
#define CAN_F2FB1_FFDB9_Msk                 (0x1U << CAN_F2FB1_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F2FB1_FFDB9                     CAN_F2FB1_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F2FB1_FFDB10_Pos                (10U)
#define CAN_F2FB1_FFDB10_Msk                (0x1U << CAN_F2FB1_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F2FB1_FFDB10                    CAN_F2FB1_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F2FB1_FFDB11_Pos                (11U)
#define CAN_F2FB1_FFDB11_Msk                (0x1U << CAN_F2FB1_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F2FB1_FFDB11                    CAN_F2FB1_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F2FB1_FFDB12_Pos                (12U)
#define CAN_F2FB1_FFDB12_Msk                (0x1U << CAN_F2FB1_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F2FB1_FFDB12                    CAN_F2FB1_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F2FB1_FFDB13_Pos                (13U)
#define CAN_F2FB1_FFDB13_Msk                (0x1U << CAN_F2FB1_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F2FB1_FFDB13                    CAN_F2FB1_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F2FB1_FFDB14_Pos                (14U)
#define CAN_F2FB1_FFDB14_Msk                (0x1U << CAN_F2FB1_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F2FB1_FFDB14                    CAN_F2FB1_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F2FB1_FFDB15_Pos                (15U)
#define CAN_F2FB1_FFDB15_Msk                (0x1U << CAN_F2FB1_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F2FB1_FFDB15                    CAN_F2FB1_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F2FB1_FFDB16_Pos                (16U)
#define CAN_F2FB1_FFDB16_Msk                (0x1U << CAN_F2FB1_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F2FB1_FFDB16                    CAN_F2FB1_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F2FB1_FFDB17_Pos                (17U)
#define CAN_F2FB1_FFDB17_Msk                (0x1U << CAN_F2FB1_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F2FB1_FFDB17                    CAN_F2FB1_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F2FB1_FFDB18_Pos                (18U)
#define CAN_F2FB1_FFDB18_Msk                (0x1U << CAN_F2FB1_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F2FB1_FFDB18                    CAN_F2FB1_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F2FB1_FFDB19_Pos                (19U)
#define CAN_F2FB1_FFDB19_Msk                (0x1U << CAN_F2FB1_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F2FB1_FFDB19                    CAN_F2FB1_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F2FB1_FFDB20_Pos                (20U)
#define CAN_F2FB1_FFDB20_Msk                (0x1U << CAN_F2FB1_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F2FB1_FFDB20                    CAN_F2FB1_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F2FB1_FFDB21_Pos                (21U)
#define CAN_F2FB1_FFDB21_Msk                (0x1U << CAN_F2FB1_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F2FB1_FFDB21                    CAN_F2FB1_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F2FB1_FFDB22_Pos                (22U)
#define CAN_F2FB1_FFDB22_Msk                (0x1U << CAN_F2FB1_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F2FB1_FFDB22                    CAN_F2FB1_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F2FB1_FFDB23_Pos                (23U)
#define CAN_F2FB1_FFDB23_Msk                (0x1U << CAN_F2FB1_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F2FB1_FFDB23                    CAN_F2FB1_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F2FB1_FFDB24_Pos                (24U)
#define CAN_F2FB1_FFDB24_Msk                (0x1U << CAN_F2FB1_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F2FB1_FFDB24                    CAN_F2FB1_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F2FB1_FFDB25_Pos                (25U)
#define CAN_F2FB1_FFDB25_Msk                (0x1U << CAN_F2FB1_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F2FB1_FFDB25                    CAN_F2FB1_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F2FB1_FFDB26_Pos                (26U)
#define CAN_F2FB1_FFDB26_Msk                (0x1U << CAN_F2FB1_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F2FB1_FFDB26                    CAN_F2FB1_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F2FB1_FFDB27_Pos                (27U)
#define CAN_F2FB1_FFDB27_Msk                (0x1U << CAN_F2FB1_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F2FB1_FFDB27                    CAN_F2FB1_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F2FB1_FFDB28_Pos                (28U)
#define CAN_F2FB1_FFDB28_Msk                (0x1U << CAN_F2FB1_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F2FB1_FFDB28                    CAN_F2FB1_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F2FB1_FFDB29_Pos                (29U)
#define CAN_F2FB1_FFDB29_Msk                (0x1U << CAN_F2FB1_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F2FB1_FFDB29                    CAN_F2FB1_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F2FB1_FFDB30_Pos                (30U)
#define CAN_F2FB1_FFDB30_Msk                (0x1U << CAN_F2FB1_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F2FB1_FFDB30                    CAN_F2FB1_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F2FB1_FFDB31_Pos                (31U)
#define CAN_F2FB1_FFDB31_Msk                (0x1U << CAN_F2FB1_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F2FB1_FFDB31                    CAN_F2FB1_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F3FB1 register  *******************/
#define CAN_F3FB1_FFDB0_Pos                 (0U)
#define CAN_F3FB1_FFDB0_Msk                 (0x1U << CAN_F3FB1_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F3FB1_FFDB0                     CAN_F3FB1_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F3FB1_FFDB1_Pos                 (1U)
#define CAN_F3FB1_FFDB1_Msk                 (0x1U << CAN_F3FB1_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F3FB1_FFDB1                     CAN_F3FB1_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F3FB1_FFDB2_Pos                 (2U)
#define CAN_F3FB1_FFDB2_Msk                 (0x1U << CAN_F3FB1_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F3FB1_FFDB2                     CAN_F3FB1_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F3FB1_FFDB3_Pos                 (3U)
#define CAN_F3FB1_FFDB3_Msk                 (0x1U << CAN_F3FB1_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F3FB1_FFDB3                     CAN_F3FB1_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F3FB1_FFDB4_Pos                 (4U)
#define CAN_F3FB1_FFDB4_Msk                 (0x1U << CAN_F3FB1_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F3FB1_FFDB4                     CAN_F3FB1_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F3FB1_FFDB5_Pos                 (5U)
#define CAN_F3FB1_FFDB5_Msk                 (0x1U << CAN_F3FB1_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F3FB1_FFDB5                     CAN_F3FB1_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F3FB1_FFDB6_Pos                 (6U)
#define CAN_F3FB1_FFDB6_Msk                 (0x1U << CAN_F3FB1_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F3FB1_FFDB6                     CAN_F3FB1_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F3FB1_FFDB7_Pos                 (7U)
#define CAN_F3FB1_FFDB7_Msk                 (0x1U << CAN_F3FB1_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F3FB1_FFDB7                     CAN_F3FB1_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F3FB1_FFDB8_Pos                 (8U)
#define CAN_F3FB1_FFDB8_Msk                 (0x1U << CAN_F3FB1_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F3FB1_FFDB8                     CAN_F3FB1_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F3FB1_FFDB9_Pos                 (9U)
#define CAN_F3FB1_FFDB9_Msk                 (0x1U << CAN_F3FB1_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F3FB1_FFDB9                     CAN_F3FB1_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F3FB1_FFDB10_Pos                (10U)
#define CAN_F3FB1_FFDB10_Msk                (0x1U << CAN_F3FB1_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F3FB1_FFDB10                    CAN_F3FB1_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F3FB1_FFDB11_Pos                (11U)
#define CAN_F3FB1_FFDB11_Msk                (0x1U << CAN_F3FB1_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F3FB1_FFDB11                    CAN_F3FB1_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F3FB1_FFDB12_Pos                (12U)
#define CAN_F3FB1_FFDB12_Msk                (0x1U << CAN_F3FB1_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F3FB1_FFDB12                    CAN_F3FB1_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F3FB1_FFDB13_Pos                (13U)
#define CAN_F3FB1_FFDB13_Msk                (0x1U << CAN_F3FB1_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F3FB1_FFDB13                    CAN_F3FB1_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F3FB1_FFDB14_Pos                (14U)
#define CAN_F3FB1_FFDB14_Msk                (0x1U << CAN_F3FB1_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F3FB1_FFDB14                    CAN_F3FB1_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F3FB1_FFDB15_Pos                (15U)
#define CAN_F3FB1_FFDB15_Msk                (0x1U << CAN_F3FB1_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F3FB1_FFDB15                    CAN_F3FB1_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F3FB1_FFDB16_Pos                (16U)
#define CAN_F3FB1_FFDB16_Msk                (0x1U << CAN_F3FB1_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F3FB1_FFDB16                    CAN_F3FB1_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F3FB1_FFDB17_Pos                (17U)
#define CAN_F3FB1_FFDB17_Msk                (0x1U << CAN_F3FB1_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F3FB1_FFDB17                    CAN_F3FB1_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F3FB1_FFDB18_Pos                (18U)
#define CAN_F3FB1_FFDB18_Msk                (0x1U << CAN_F3FB1_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F3FB1_FFDB18                    CAN_F3FB1_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F3FB1_FFDB19_Pos                (19U)
#define CAN_F3FB1_FFDB19_Msk                (0x1U << CAN_F3FB1_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F3FB1_FFDB19                    CAN_F3FB1_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F3FB1_FFDB20_Pos                (20U)
#define CAN_F3FB1_FFDB20_Msk                (0x1U << CAN_F3FB1_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F3FB1_FFDB20                    CAN_F3FB1_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F3FB1_FFDB21_Pos                (21U)
#define CAN_F3FB1_FFDB21_Msk                (0x1U << CAN_F3FB1_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F3FB1_FFDB21                    CAN_F3FB1_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F3FB1_FFDB22_Pos                (22U)
#define CAN_F3FB1_FFDB22_Msk                (0x1U << CAN_F3FB1_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F3FB1_FFDB22                    CAN_F3FB1_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F3FB1_FFDB23_Pos                (23U)
#define CAN_F3FB1_FFDB23_Msk                (0x1U << CAN_F3FB1_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F3FB1_FFDB23                    CAN_F3FB1_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F3FB1_FFDB24_Pos                (24U)
#define CAN_F3FB1_FFDB24_Msk                (0x1U << CAN_F3FB1_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F3FB1_FFDB24                    CAN_F3FB1_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F3FB1_FFDB25_Pos                (25U)
#define CAN_F3FB1_FFDB25_Msk                (0x1U << CAN_F3FB1_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F3FB1_FFDB25                    CAN_F3FB1_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F3FB1_FFDB26_Pos                (26U)
#define CAN_F3FB1_FFDB26_Msk                (0x1U << CAN_F3FB1_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F3FB1_FFDB26                    CAN_F3FB1_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F3FB1_FFDB27_Pos                (27U)
#define CAN_F3FB1_FFDB27_Msk                (0x1U << CAN_F3FB1_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F3FB1_FFDB27                    CAN_F3FB1_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F3FB1_FFDB28_Pos                (28U)
#define CAN_F3FB1_FFDB28_Msk                (0x1U << CAN_F3FB1_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F3FB1_FFDB28                    CAN_F3FB1_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F3FB1_FFDB29_Pos                (29U)
#define CAN_F3FB1_FFDB29_Msk                (0x1U << CAN_F3FB1_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F3FB1_FFDB29                    CAN_F3FB1_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F3FB1_FFDB30_Pos                (30U)
#define CAN_F3FB1_FFDB30_Msk                (0x1U << CAN_F3FB1_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F3FB1_FFDB30                    CAN_F3FB1_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F3FB1_FFDB31_Pos                (31U)
#define CAN_F3FB1_FFDB31_Msk                (0x1U << CAN_F3FB1_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F3FB1_FFDB31                    CAN_F3FB1_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F4FB1 register  *******************/
#define CAN_F4FB1_FFDB0_Pos                 (0U)
#define CAN_F4FB1_FFDB0_Msk                 (0x1U << CAN_F4FB1_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F4FB1_FFDB0                     CAN_F4FB1_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F4FB1_FFDB1_Pos                 (1U)
#define CAN_F4FB1_FFDB1_Msk                 (0x1U << CAN_F4FB1_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F4FB1_FFDB1                     CAN_F4FB1_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F4FB1_FFDB2_Pos                 (2U)
#define CAN_F4FB1_FFDB2_Msk                 (0x1U << CAN_F4FB1_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F4FB1_FFDB2                     CAN_F4FB1_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F4FB1_FFDB3_Pos                 (3U)
#define CAN_F4FB1_FFDB3_Msk                 (0x1U << CAN_F4FB1_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F4FB1_FFDB3                     CAN_F4FB1_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F4FB1_FFDB4_Pos                 (4U)
#define CAN_F4FB1_FFDB4_Msk                 (0x1U << CAN_F4FB1_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F4FB1_FFDB4                     CAN_F4FB1_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F4FB1_FFDB5_Pos                 (5U)
#define CAN_F4FB1_FFDB5_Msk                 (0x1U << CAN_F4FB1_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F4FB1_FFDB5                     CAN_F4FB1_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F4FB1_FFDB6_Pos                 (6U)
#define CAN_F4FB1_FFDB6_Msk                 (0x1U << CAN_F4FB1_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F4FB1_FFDB6                     CAN_F4FB1_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F4FB1_FFDB7_Pos                 (7U)
#define CAN_F4FB1_FFDB7_Msk                 (0x1U << CAN_F4FB1_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F4FB1_FFDB7                     CAN_F4FB1_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F4FB1_FFDB8_Pos                 (8U)
#define CAN_F4FB1_FFDB8_Msk                 (0x1U << CAN_F4FB1_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F4FB1_FFDB8                     CAN_F4FB1_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F4FB1_FFDB9_Pos                 (9U)
#define CAN_F4FB1_FFDB9_Msk                 (0x1U << CAN_F4FB1_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F4FB1_FFDB9                     CAN_F4FB1_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F4FB1_FFDB10_Pos                (10U)
#define CAN_F4FB1_FFDB10_Msk                (0x1U << CAN_F4FB1_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F4FB1_FFDB10                    CAN_F4FB1_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F4FB1_FFDB11_Pos                (11U)
#define CAN_F4FB1_FFDB11_Msk                (0x1U << CAN_F4FB1_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F4FB1_FFDB11                    CAN_F4FB1_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F4FB1_FFDB12_Pos                (12U)
#define CAN_F4FB1_FFDB12_Msk                (0x1U << CAN_F4FB1_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F4FB1_FFDB12                    CAN_F4FB1_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F4FB1_FFDB13_Pos                (13U)
#define CAN_F4FB1_FFDB13_Msk                (0x1U << CAN_F4FB1_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F4FB1_FFDB13                    CAN_F4FB1_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F4FB1_FFDB14_Pos                (14U)
#define CAN_F4FB1_FFDB14_Msk                (0x1U << CAN_F4FB1_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F4FB1_FFDB14                    CAN_F4FB1_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F4FB1_FFDB15_Pos                (15U)
#define CAN_F4FB1_FFDB15_Msk                (0x1U << CAN_F4FB1_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F4FB1_FFDB15                    CAN_F4FB1_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F4FB1_FFDB16_Pos                (16U)
#define CAN_F4FB1_FFDB16_Msk                (0x1U << CAN_F4FB1_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F4FB1_FFDB16                    CAN_F4FB1_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F4FB1_FFDB17_Pos                (17U)
#define CAN_F4FB1_FFDB17_Msk                (0x1U << CAN_F4FB1_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F4FB1_FFDB17                    CAN_F4FB1_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F4FB1_FFDB18_Pos                (18U)
#define CAN_F4FB1_FFDB18_Msk                (0x1U << CAN_F4FB1_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F4FB1_FFDB18                    CAN_F4FB1_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F4FB1_FFDB19_Pos                (19U)
#define CAN_F4FB1_FFDB19_Msk                (0x1U << CAN_F4FB1_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F4FB1_FFDB19                    CAN_F4FB1_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F4FB1_FFDB20_Pos                (20U)
#define CAN_F4FB1_FFDB20_Msk                (0x1U << CAN_F4FB1_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F4FB1_FFDB20                    CAN_F4FB1_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F4FB1_FFDB21_Pos                (21U)
#define CAN_F4FB1_FFDB21_Msk                (0x1U << CAN_F4FB1_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F4FB1_FFDB21                    CAN_F4FB1_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F4FB1_FFDB22_Pos                (22U)
#define CAN_F4FB1_FFDB22_Msk                (0x1U << CAN_F4FB1_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F4FB1_FFDB22                    CAN_F4FB1_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F4FB1_FFDB23_Pos                (23U)
#define CAN_F4FB1_FFDB23_Msk                (0x1U << CAN_F4FB1_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F4FB1_FFDB23                    CAN_F4FB1_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F4FB1_FFDB24_Pos                (24U)
#define CAN_F4FB1_FFDB24_Msk                (0x1U << CAN_F4FB1_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F4FB1_FFDB24                    CAN_F4FB1_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F4FB1_FFDB25_Pos                (25U)
#define CAN_F4FB1_FFDB25_Msk                (0x1U << CAN_F4FB1_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F4FB1_FFDB25                    CAN_F4FB1_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F4FB1_FFDB26_Pos                (26U)
#define CAN_F4FB1_FFDB26_Msk                (0x1U << CAN_F4FB1_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F4FB1_FFDB26                    CAN_F4FB1_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F4FB1_FFDB27_Pos                (27U)
#define CAN_F4FB1_FFDB27_Msk                (0x1U << CAN_F4FB1_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F4FB1_FFDB27                    CAN_F4FB1_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F4FB1_FFDB28_Pos                (28U)
#define CAN_F4FB1_FFDB28_Msk                (0x1U << CAN_F4FB1_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F4FB1_FFDB28                    CAN_F4FB1_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F4FB1_FFDB29_Pos                (29U)
#define CAN_F4FB1_FFDB29_Msk                (0x1U << CAN_F4FB1_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F4FB1_FFDB29                    CAN_F4FB1_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F4FB1_FFDB30_Pos                (30U)
#define CAN_F4FB1_FFDB30_Msk                (0x1U << CAN_F4FB1_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F4FB1_FFDB30                    CAN_F4FB1_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F4FB1_FFDB31_Pos                (31U)
#define CAN_F4FB1_FFDB31_Msk                (0x1U << CAN_F4FB1_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F4FB1_FFDB31                    CAN_F4FB1_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F5FB1 register  *******************/
#define CAN_F5FB1_FFDB0_Pos                 (0U)
#define CAN_F5FB1_FFDB0_Msk                 (0x1U << CAN_F5FB1_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F5FB1_FFDB0                     CAN_F5FB1_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F5FB1_FFDB1_Pos                 (1U)
#define CAN_F5FB1_FFDB1_Msk                 (0x1U << CAN_F5FB1_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F5FB1_FFDB1                     CAN_F5FB1_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F5FB1_FFDB2_Pos                 (2U)
#define CAN_F5FB1_FFDB2_Msk                 (0x1U << CAN_F5FB1_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F5FB1_FFDB2                     CAN_F5FB1_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F5FB1_FFDB3_Pos                 (3U)
#define CAN_F5FB1_FFDB3_Msk                 (0x1U << CAN_F5FB1_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F5FB1_FFDB3                     CAN_F5FB1_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F5FB1_FFDB4_Pos                 (4U)
#define CAN_F5FB1_FFDB4_Msk                 (0x1U << CAN_F5FB1_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F5FB1_FFDB4                     CAN_F5FB1_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F5FB1_FFDB5_Pos                 (5U)
#define CAN_F5FB1_FFDB5_Msk                 (0x1U << CAN_F5FB1_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F5FB1_FFDB5                     CAN_F5FB1_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F5FB1_FFDB6_Pos                 (6U)
#define CAN_F5FB1_FFDB6_Msk                 (0x1U << CAN_F5FB1_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F5FB1_FFDB6                     CAN_F5FB1_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F5FB1_FFDB7_Pos                 (7U)
#define CAN_F5FB1_FFDB7_Msk                 (0x1U << CAN_F5FB1_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F5FB1_FFDB7                     CAN_F5FB1_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F5FB1_FFDB8_Pos                 (8U)
#define CAN_F5FB1_FFDB8_Msk                 (0x1U << CAN_F5FB1_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F5FB1_FFDB8                     CAN_F5FB1_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F5FB1_FFDB9_Pos                 (9U)
#define CAN_F5FB1_FFDB9_Msk                 (0x1U << CAN_F5FB1_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F5FB1_FFDB9                     CAN_F5FB1_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F5FB1_FFDB10_Pos                (10U)
#define CAN_F5FB1_FFDB10_Msk                (0x1U << CAN_F5FB1_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F5FB1_FFDB10                    CAN_F5FB1_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F5FB1_FFDB11_Pos                (11U)
#define CAN_F5FB1_FFDB11_Msk                (0x1U << CAN_F5FB1_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F5FB1_FFDB11                    CAN_F5FB1_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F5FB1_FFDB12_Pos                (12U)
#define CAN_F5FB1_FFDB12_Msk                (0x1U << CAN_F5FB1_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F5FB1_FFDB12                    CAN_F5FB1_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F5FB1_FFDB13_Pos                (13U)
#define CAN_F5FB1_FFDB13_Msk                (0x1U << CAN_F5FB1_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F5FB1_FFDB13                    CAN_F5FB1_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F5FB1_FFDB14_Pos                (14U)
#define CAN_F5FB1_FFDB14_Msk                (0x1U << CAN_F5FB1_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F5FB1_FFDB14                    CAN_F5FB1_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F5FB1_FFDB15_Pos                (15U)
#define CAN_F5FB1_FFDB15_Msk                (0x1U << CAN_F5FB1_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F5FB1_FFDB15                    CAN_F5FB1_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F5FB1_FFDB16_Pos                (16U)
#define CAN_F5FB1_FFDB16_Msk                (0x1U << CAN_F5FB1_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F5FB1_FFDB16                    CAN_F5FB1_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F5FB1_FFDB17_Pos                (17U)
#define CAN_F5FB1_FFDB17_Msk                (0x1U << CAN_F5FB1_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F5FB1_FFDB17                    CAN_F5FB1_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F5FB1_FFDB18_Pos                (18U)
#define CAN_F5FB1_FFDB18_Msk                (0x1U << CAN_F5FB1_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F5FB1_FFDB18                    CAN_F5FB1_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F5FB1_FFDB19_Pos                (19U)
#define CAN_F5FB1_FFDB19_Msk                (0x1U << CAN_F5FB1_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F5FB1_FFDB19                    CAN_F5FB1_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F5FB1_FFDB20_Pos                (20U)
#define CAN_F5FB1_FFDB20_Msk                (0x1U << CAN_F5FB1_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F5FB1_FFDB20                    CAN_F5FB1_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F5FB1_FFDB21_Pos                (21U)
#define CAN_F5FB1_FFDB21_Msk                (0x1U << CAN_F5FB1_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F5FB1_FFDB21                    CAN_F5FB1_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F5FB1_FFDB22_Pos                (22U)
#define CAN_F5FB1_FFDB22_Msk                (0x1U << CAN_F5FB1_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F5FB1_FFDB22                    CAN_F5FB1_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F5FB1_FFDB23_Pos                (23U)
#define CAN_F5FB1_FFDB23_Msk                (0x1U << CAN_F5FB1_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F5FB1_FFDB23                    CAN_F5FB1_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F5FB1_FFDB24_Pos                (24U)
#define CAN_F5FB1_FFDB24_Msk                (0x1U << CAN_F5FB1_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F5FB1_FFDB24                    CAN_F5FB1_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F5FB1_FFDB25_Pos                (25U)
#define CAN_F5FB1_FFDB25_Msk                (0x1U << CAN_F5FB1_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F5FB1_FFDB25                    CAN_F5FB1_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F5FB1_FFDB26_Pos                (26U)
#define CAN_F5FB1_FFDB26_Msk                (0x1U << CAN_F5FB1_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F5FB1_FFDB26                    CAN_F5FB1_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F5FB1_FFDB27_Pos                (27U)
#define CAN_F5FB1_FFDB27_Msk                (0x1U << CAN_F5FB1_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F5FB1_FFDB27                    CAN_F5FB1_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F5FB1_FFDB28_Pos                (28U)
#define CAN_F5FB1_FFDB28_Msk                (0x1U << CAN_F5FB1_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F5FB1_FFDB28                    CAN_F5FB1_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F5FB1_FFDB29_Pos                (29U)
#define CAN_F5FB1_FFDB29_Msk                (0x1U << CAN_F5FB1_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F5FB1_FFDB29                    CAN_F5FB1_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F5FB1_FFDB30_Pos                (30U)
#define CAN_F5FB1_FFDB30_Msk                (0x1U << CAN_F5FB1_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F5FB1_FFDB30                    CAN_F5FB1_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F5FB1_FFDB31_Pos                (31U)
#define CAN_F5FB1_FFDB31_Msk                (0x1U << CAN_F5FB1_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F5FB1_FFDB31                    CAN_F5FB1_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F6FB1 register  *******************/
#define CAN_F6FB1_FFDB0_Pos                 (0U)
#define CAN_F6FB1_FFDB0_Msk                 (0x1U << CAN_F6FB1_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F6FB1_FFDB0                     CAN_F6FB1_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F6FB1_FFDB1_Pos                 (1U)
#define CAN_F6FB1_FFDB1_Msk                 (0x1U << CAN_F6FB1_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F6FB1_FFDB1                     CAN_F6FB1_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F6FB1_FFDB2_Pos                 (2U)
#define CAN_F6FB1_FFDB2_Msk                 (0x1U << CAN_F6FB1_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F6FB1_FFDB2                     CAN_F6FB1_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F6FB1_FFDB3_Pos                 (3U)
#define CAN_F6FB1_FFDB3_Msk                 (0x1U << CAN_F6FB1_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F6FB1_FFDB3                     CAN_F6FB1_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F6FB1_FFDB4_Pos                 (4U)
#define CAN_F6FB1_FFDB4_Msk                 (0x1U << CAN_F6FB1_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F6FB1_FFDB4                     CAN_F6FB1_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F6FB1_FFDB5_Pos                 (5U)
#define CAN_F6FB1_FFDB5_Msk                 (0x1U << CAN_F6FB1_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F6FB1_FFDB5                     CAN_F6FB1_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F6FB1_FFDB6_Pos                 (6U)
#define CAN_F6FB1_FFDB6_Msk                 (0x1U << CAN_F6FB1_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F6FB1_FFDB6                     CAN_F6FB1_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F6FB1_FFDB7_Pos                 (7U)
#define CAN_F6FB1_FFDB7_Msk                 (0x1U << CAN_F6FB1_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F6FB1_FFDB7                     CAN_F6FB1_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F6FB1_FFDB8_Pos                 (8U)
#define CAN_F6FB1_FFDB8_Msk                 (0x1U << CAN_F6FB1_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F6FB1_FFDB8                     CAN_F6FB1_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F6FB1_FFDB9_Pos                 (9U)
#define CAN_F6FB1_FFDB9_Msk                 (0x1U << CAN_F6FB1_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F6FB1_FFDB9                     CAN_F6FB1_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F6FB1_FFDB10_Pos                (10U)
#define CAN_F6FB1_FFDB10_Msk                (0x1U << CAN_F6FB1_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F6FB1_FFDB10                    CAN_F6FB1_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F6FB1_FFDB11_Pos                (11U)
#define CAN_F6FB1_FFDB11_Msk                (0x1U << CAN_F6FB1_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F6FB1_FFDB11                    CAN_F6FB1_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F6FB1_FFDB12_Pos                (12U)
#define CAN_F6FB1_FFDB12_Msk                (0x1U << CAN_F6FB1_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F6FB1_FFDB12                    CAN_F6FB1_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F6FB1_FFDB13_Pos                (13U)
#define CAN_F6FB1_FFDB13_Msk                (0x1U << CAN_F6FB1_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F6FB1_FFDB13                    CAN_F6FB1_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F6FB1_FFDB14_Pos                (14U)
#define CAN_F6FB1_FFDB14_Msk                (0x1U << CAN_F6FB1_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F6FB1_FFDB14                    CAN_F6FB1_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F6FB1_FFDB15_Pos                (15U)
#define CAN_F6FB1_FFDB15_Msk                (0x1U << CAN_F6FB1_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F6FB1_FFDB15                    CAN_F6FB1_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F6FB1_FFDB16_Pos                (16U)
#define CAN_F6FB1_FFDB16_Msk                (0x1U << CAN_F6FB1_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F6FB1_FFDB16                    CAN_F6FB1_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F6FB1_FFDB17_Pos                (17U)
#define CAN_F6FB1_FFDB17_Msk                (0x1U << CAN_F6FB1_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F6FB1_FFDB17                    CAN_F6FB1_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F6FB1_FFDB18_Pos                (18U)
#define CAN_F6FB1_FFDB18_Msk                (0x1U << CAN_F6FB1_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F6FB1_FFDB18                    CAN_F6FB1_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F6FB1_FFDB19_Pos                (19U)
#define CAN_F6FB1_FFDB19_Msk                (0x1U << CAN_F6FB1_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F6FB1_FFDB19                    CAN_F6FB1_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F6FB1_FFDB20_Pos                (20U)
#define CAN_F6FB1_FFDB20_Msk                (0x1U << CAN_F6FB1_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F6FB1_FFDB20                    CAN_F6FB1_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F6FB1_FFDB21_Pos                (21U)
#define CAN_F6FB1_FFDB21_Msk                (0x1U << CAN_F6FB1_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F6FB1_FFDB21                    CAN_F6FB1_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F6FB1_FFDB22_Pos                (22U)
#define CAN_F6FB1_FFDB22_Msk                (0x1U << CAN_F6FB1_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F6FB1_FFDB22                    CAN_F6FB1_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F6FB1_FFDB23_Pos                (23U)
#define CAN_F6FB1_FFDB23_Msk                (0x1U << CAN_F6FB1_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F6FB1_FFDB23                    CAN_F6FB1_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F6FB1_FFDB24_Pos                (24U)
#define CAN_F6FB1_FFDB24_Msk                (0x1U << CAN_F6FB1_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F6FB1_FFDB24                    CAN_F6FB1_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F6FB1_FFDB25_Pos                (25U)
#define CAN_F6FB1_FFDB25_Msk                (0x1U << CAN_F6FB1_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F6FB1_FFDB25                    CAN_F6FB1_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F6FB1_FFDB26_Pos                (26U)
#define CAN_F6FB1_FFDB26_Msk                (0x1U << CAN_F6FB1_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F6FB1_FFDB26                    CAN_F6FB1_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F6FB1_FFDB27_Pos                (27U)
#define CAN_F6FB1_FFDB27_Msk                (0x1U << CAN_F6FB1_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F6FB1_FFDB27                    CAN_F6FB1_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F6FB1_FFDB28_Pos                (28U)
#define CAN_F6FB1_FFDB28_Msk                (0x1U << CAN_F6FB1_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F6FB1_FFDB28                    CAN_F6FB1_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F6FB1_FFDB29_Pos                (29U)
#define CAN_F6FB1_FFDB29_Msk                (0x1U << CAN_F6FB1_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F6FB1_FFDB29                    CAN_F6FB1_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F6FB1_FFDB30_Pos                (30U)
#define CAN_F6FB1_FFDB30_Msk                (0x1U << CAN_F6FB1_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F6FB1_FFDB30                    CAN_F6FB1_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F6FB1_FFDB31_Pos                (31U)
#define CAN_F6FB1_FFDB31_Msk                (0x1U << CAN_F6FB1_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F6FB1_FFDB31                    CAN_F6FB1_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F7FB1 register  *******************/
#define CAN_F7FB1_FFDB0_Pos                 (0U)
#define CAN_F7FB1_FFDB0_Msk                 (0x1U << CAN_F7FB1_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F7FB1_FFDB0                     CAN_F7FB1_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F7FB1_FFDB1_Pos                 (1U)
#define CAN_F7FB1_FFDB1_Msk                 (0x1U << CAN_F7FB1_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F7FB1_FFDB1                     CAN_F7FB1_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F7FB1_FFDB2_Pos                 (2U)
#define CAN_F7FB1_FFDB2_Msk                 (0x1U << CAN_F7FB1_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F7FB1_FFDB2                     CAN_F7FB1_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F7FB1_FFDB3_Pos                 (3U)
#define CAN_F7FB1_FFDB3_Msk                 (0x1U << CAN_F7FB1_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F7FB1_FFDB3                     CAN_F7FB1_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F7FB1_FFDB4_Pos                 (4U)
#define CAN_F7FB1_FFDB4_Msk                 (0x1U << CAN_F7FB1_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F7FB1_FFDB4                     CAN_F7FB1_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F7FB1_FFDB5_Pos                 (5U)
#define CAN_F7FB1_FFDB5_Msk                 (0x1U << CAN_F7FB1_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F7FB1_FFDB5                     CAN_F7FB1_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F7FB1_FFDB6_Pos                 (6U)
#define CAN_F7FB1_FFDB6_Msk                 (0x1U << CAN_F7FB1_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F7FB1_FFDB6                     CAN_F7FB1_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F7FB1_FFDB7_Pos                 (7U)
#define CAN_F7FB1_FFDB7_Msk                 (0x1U << CAN_F7FB1_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F7FB1_FFDB7                     CAN_F7FB1_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F7FB1_FFDB8_Pos                 (8U)
#define CAN_F7FB1_FFDB8_Msk                 (0x1U << CAN_F7FB1_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F7FB1_FFDB8                     CAN_F7FB1_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F7FB1_FFDB9_Pos                 (9U)
#define CAN_F7FB1_FFDB9_Msk                 (0x1U << CAN_F7FB1_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F7FB1_FFDB9                     CAN_F7FB1_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F7FB1_FFDB10_Pos                (10U)
#define CAN_F7FB1_FFDB10_Msk                (0x1U << CAN_F7FB1_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F7FB1_FFDB10                    CAN_F7FB1_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F7FB1_FFDB11_Pos                (11U)
#define CAN_F7FB1_FFDB11_Msk                (0x1U << CAN_F7FB1_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F7FB1_FFDB11                    CAN_F7FB1_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F7FB1_FFDB12_Pos                (12U)
#define CAN_F7FB1_FFDB12_Msk                (0x1U << CAN_F7FB1_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F7FB1_FFDB12                    CAN_F7FB1_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F7FB1_FFDB13_Pos                (13U)
#define CAN_F7FB1_FFDB13_Msk                (0x1U << CAN_F7FB1_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F7FB1_FFDB13                    CAN_F7FB1_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F7FB1_FFDB14_Pos                (14U)
#define CAN_F7FB1_FFDB14_Msk                (0x1U << CAN_F7FB1_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F7FB1_FFDB14                    CAN_F7FB1_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F7FB1_FFDB15_Pos                (15U)
#define CAN_F7FB1_FFDB15_Msk                (0x1U << CAN_F7FB1_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F7FB1_FFDB15                    CAN_F7FB1_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F7FB1_FFDB16_Pos                (16U)
#define CAN_F7FB1_FFDB16_Msk                (0x1U << CAN_F7FB1_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F7FB1_FFDB16                    CAN_F7FB1_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F7FB1_FFDB17_Pos                (17U)
#define CAN_F7FB1_FFDB17_Msk                (0x1U << CAN_F7FB1_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F7FB1_FFDB17                    CAN_F7FB1_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F7FB1_FFDB18_Pos                (18U)
#define CAN_F7FB1_FFDB18_Msk                (0x1U << CAN_F7FB1_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F7FB1_FFDB18                    CAN_F7FB1_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F7FB1_FFDB19_Pos                (19U)
#define CAN_F7FB1_FFDB19_Msk                (0x1U << CAN_F7FB1_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F7FB1_FFDB19                    CAN_F7FB1_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F7FB1_FFDB20_Pos                (20U)
#define CAN_F7FB1_FFDB20_Msk                (0x1U << CAN_F7FB1_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F7FB1_FFDB20                    CAN_F7FB1_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F7FB1_FFDB21_Pos                (21U)
#define CAN_F7FB1_FFDB21_Msk                (0x1U << CAN_F7FB1_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F7FB1_FFDB21                    CAN_F7FB1_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F7FB1_FFDB22_Pos                (22U)
#define CAN_F7FB1_FFDB22_Msk                (0x1U << CAN_F7FB1_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F7FB1_FFDB22                    CAN_F7FB1_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F7FB1_FFDB23_Pos                (23U)
#define CAN_F7FB1_FFDB23_Msk                (0x1U << CAN_F7FB1_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F7FB1_FFDB23                    CAN_F7FB1_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F7FB1_FFDB24_Pos                (24U)
#define CAN_F7FB1_FFDB24_Msk                (0x1U << CAN_F7FB1_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F7FB1_FFDB24                    CAN_F7FB1_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F7FB1_FFDB25_Pos                (25U)
#define CAN_F7FB1_FFDB25_Msk                (0x1U << CAN_F7FB1_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F7FB1_FFDB25                    CAN_F7FB1_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F7FB1_FFDB26_Pos                (26U)
#define CAN_F7FB1_FFDB26_Msk                (0x1U << CAN_F7FB1_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F7FB1_FFDB26                    CAN_F7FB1_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F7FB1_FFDB27_Pos                (27U)
#define CAN_F7FB1_FFDB27_Msk                (0x1U << CAN_F7FB1_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F7FB1_FFDB27                    CAN_F7FB1_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F7FB1_FFDB28_Pos                (28U)
#define CAN_F7FB1_FFDB28_Msk                (0x1U << CAN_F7FB1_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F7FB1_FFDB28                    CAN_F7FB1_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F7FB1_FFDB29_Pos                (29U)
#define CAN_F7FB1_FFDB29_Msk                (0x1U << CAN_F7FB1_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F7FB1_FFDB29                    CAN_F7FB1_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F7FB1_FFDB30_Pos                (30U)
#define CAN_F7FB1_FFDB30_Msk                (0x1U << CAN_F7FB1_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F7FB1_FFDB30                    CAN_F7FB1_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F7FB1_FFDB31_Pos                (31U)
#define CAN_F7FB1_FFDB31_Msk                (0x1U << CAN_F7FB1_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F7FB1_FFDB31                    CAN_F7FB1_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F8FB1 register  *******************/
#define CAN_F8FB1_FFDB0_Pos                 (0U)
#define CAN_F8FB1_FFDB0_Msk                 (0x1U << CAN_F8FB1_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F8FB1_FFDB0                     CAN_F8FB1_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F8FB1_FFDB1_Pos                 (1U)
#define CAN_F8FB1_FFDB1_Msk                 (0x1U << CAN_F8FB1_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F8FB1_FFDB1                     CAN_F8FB1_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F8FB1_FFDB2_Pos                 (2U)
#define CAN_F8FB1_FFDB2_Msk                 (0x1U << CAN_F8FB1_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F8FB1_FFDB2                     CAN_F8FB1_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F8FB1_FFDB3_Pos                 (3U)
#define CAN_F8FB1_FFDB3_Msk                 (0x1U << CAN_F8FB1_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F8FB1_FFDB3                     CAN_F8FB1_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F8FB1_FFDB4_Pos                 (4U)
#define CAN_F8FB1_FFDB4_Msk                 (0x1U << CAN_F8FB1_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F8FB1_FFDB4                     CAN_F8FB1_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F8FB1_FFDB5_Pos                 (5U)
#define CAN_F8FB1_FFDB5_Msk                 (0x1U << CAN_F8FB1_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F8FB1_FFDB5                     CAN_F8FB1_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F8FB1_FFDB6_Pos                 (6U)
#define CAN_F8FB1_FFDB6_Msk                 (0x1U << CAN_F8FB1_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F8FB1_FFDB6                     CAN_F8FB1_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F8FB1_FFDB7_Pos                 (7U)
#define CAN_F8FB1_FFDB7_Msk                 (0x1U << CAN_F8FB1_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F8FB1_FFDB7                     CAN_F8FB1_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F8FB1_FFDB8_Pos                 (8U)
#define CAN_F8FB1_FFDB8_Msk                 (0x1U << CAN_F8FB1_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F8FB1_FFDB8                     CAN_F8FB1_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F8FB1_FFDB9_Pos                 (9U)
#define CAN_F8FB1_FFDB9_Msk                 (0x1U << CAN_F8FB1_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F8FB1_FFDB9                     CAN_F8FB1_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F8FB1_FFDB10_Pos                (10U)
#define CAN_F8FB1_FFDB10_Msk                (0x1U << CAN_F8FB1_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F8FB1_FFDB10                    CAN_F8FB1_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F8FB1_FFDB11_Pos                (11U)
#define CAN_F8FB1_FFDB11_Msk                (0x1U << CAN_F8FB1_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F8FB1_FFDB11                    CAN_F8FB1_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F8FB1_FFDB12_Pos                (12U)
#define CAN_F8FB1_FFDB12_Msk                (0x1U << CAN_F8FB1_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F8FB1_FFDB12                    CAN_F8FB1_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F8FB1_FFDB13_Pos                (13U)
#define CAN_F8FB1_FFDB13_Msk                (0x1U << CAN_F8FB1_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F8FB1_FFDB13                    CAN_F8FB1_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F8FB1_FFDB14_Pos                (14U)
#define CAN_F8FB1_FFDB14_Msk                (0x1U << CAN_F8FB1_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F8FB1_FFDB14                    CAN_F8FB1_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F8FB1_FFDB15_Pos                (15U)
#define CAN_F8FB1_FFDB15_Msk                (0x1U << CAN_F8FB1_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F8FB1_FFDB15                    CAN_F8FB1_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F8FB1_FFDB16_Pos                (16U)
#define CAN_F8FB1_FFDB16_Msk                (0x1U << CAN_F8FB1_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F8FB1_FFDB16                    CAN_F8FB1_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F8FB1_FFDB17_Pos                (17U)
#define CAN_F8FB1_FFDB17_Msk                (0x1U << CAN_F8FB1_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F8FB1_FFDB17                    CAN_F8FB1_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F8FB1_FFDB18_Pos                (18U)
#define CAN_F8FB1_FFDB18_Msk                (0x1U << CAN_F8FB1_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F8FB1_FFDB18                    CAN_F8FB1_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F8FB1_FFDB19_Pos                (19U)
#define CAN_F8FB1_FFDB19_Msk                (0x1U << CAN_F8FB1_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F8FB1_FFDB19                    CAN_F8FB1_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F8FB1_FFDB20_Pos                (20U)
#define CAN_F8FB1_FFDB20_Msk                (0x1U << CAN_F8FB1_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F8FB1_FFDB20                    CAN_F8FB1_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F8FB1_FFDB21_Pos                (21U)
#define CAN_F8FB1_FFDB21_Msk                (0x1U << CAN_F8FB1_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F8FB1_FFDB21                    CAN_F8FB1_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F8FB1_FFDB22_Pos                (22U)
#define CAN_F8FB1_FFDB22_Msk                (0x1U << CAN_F8FB1_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F8FB1_FFDB22                    CAN_F8FB1_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F8FB1_FFDB23_Pos                (23U)
#define CAN_F8FB1_FFDB23_Msk                (0x1U << CAN_F8FB1_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F8FB1_FFDB23                    CAN_F8FB1_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F8FB1_FFDB24_Pos                (24U)
#define CAN_F8FB1_FFDB24_Msk                (0x1U << CAN_F8FB1_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F8FB1_FFDB24                    CAN_F8FB1_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F8FB1_FFDB25_Pos                (25U)
#define CAN_F8FB1_FFDB25_Msk                (0x1U << CAN_F8FB1_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F8FB1_FFDB25                    CAN_F8FB1_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F8FB1_FFDB26_Pos                (26U)
#define CAN_F8FB1_FFDB26_Msk                (0x1U << CAN_F8FB1_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F8FB1_FFDB26                    CAN_F8FB1_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F8FB1_FFDB27_Pos                (27U)
#define CAN_F8FB1_FFDB27_Msk                (0x1U << CAN_F8FB1_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F8FB1_FFDB27                    CAN_F8FB1_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F8FB1_FFDB28_Pos                (28U)
#define CAN_F8FB1_FFDB28_Msk                (0x1U << CAN_F8FB1_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F8FB1_FFDB28                    CAN_F8FB1_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F8FB1_FFDB29_Pos                (29U)
#define CAN_F8FB1_FFDB29_Msk                (0x1U << CAN_F8FB1_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F8FB1_FFDB29                    CAN_F8FB1_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F8FB1_FFDB30_Pos                (30U)
#define CAN_F8FB1_FFDB30_Msk                (0x1U << CAN_F8FB1_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F8FB1_FFDB30                    CAN_F8FB1_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F8FB1_FFDB31_Pos                (31U)
#define CAN_F8FB1_FFDB31_Msk                (0x1U << CAN_F8FB1_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F8FB1_FFDB31                    CAN_F8FB1_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F9FB1 register  *******************/
#define CAN_F9FB1_FFDB0_Pos                 (0U)
#define CAN_F9FB1_FFDB0_Msk                 (0x1U << CAN_F9FB1_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F9FB1_FFDB0                     CAN_F9FB1_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F9FB1_FFDB1_Pos                 (1U)
#define CAN_F9FB1_FFDB1_Msk                 (0x1U << CAN_F9FB1_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F9FB1_FFDB1                     CAN_F9FB1_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F9FB1_FFDB2_Pos                 (2U)
#define CAN_F9FB1_FFDB2_Msk                 (0x1U << CAN_F9FB1_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F9FB1_FFDB2                     CAN_F9FB1_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F9FB1_FFDB3_Pos                 (3U)
#define CAN_F9FB1_FFDB3_Msk                 (0x1U << CAN_F9FB1_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F9FB1_FFDB3                     CAN_F9FB1_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F9FB1_FFDB4_Pos                 (4U)
#define CAN_F9FB1_FFDB4_Msk                 (0x1U << CAN_F9FB1_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F9FB1_FFDB4                     CAN_F9FB1_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F9FB1_FFDB5_Pos                 (5U)
#define CAN_F9FB1_FFDB5_Msk                 (0x1U << CAN_F9FB1_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F9FB1_FFDB5                     CAN_F9FB1_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F9FB1_FFDB6_Pos                 (6U)
#define CAN_F9FB1_FFDB6_Msk                 (0x1U << CAN_F9FB1_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F9FB1_FFDB6                     CAN_F9FB1_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F9FB1_FFDB7_Pos                 (7U)
#define CAN_F9FB1_FFDB7_Msk                 (0x1U << CAN_F9FB1_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F9FB1_FFDB7                     CAN_F9FB1_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F9FB1_FFDB8_Pos                 (8U)
#define CAN_F9FB1_FFDB8_Msk                 (0x1U << CAN_F9FB1_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F9FB1_FFDB8                     CAN_F9FB1_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F9FB1_FFDB9_Pos                 (9U)
#define CAN_F9FB1_FFDB9_Msk                 (0x1U << CAN_F9FB1_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F9FB1_FFDB9                     CAN_F9FB1_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F9FB1_FFDB10_Pos                (10U)
#define CAN_F9FB1_FFDB10_Msk                (0x1U << CAN_F9FB1_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F9FB1_FFDB10                    CAN_F9FB1_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F9FB1_FFDB11_Pos                (11U)
#define CAN_F9FB1_FFDB11_Msk                (0x1U << CAN_F9FB1_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F9FB1_FFDB11                    CAN_F9FB1_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F9FB1_FFDB12_Pos                (12U)
#define CAN_F9FB1_FFDB12_Msk                (0x1U << CAN_F9FB1_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F9FB1_FFDB12                    CAN_F9FB1_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F9FB1_FFDB13_Pos                (13U)
#define CAN_F9FB1_FFDB13_Msk                (0x1U << CAN_F9FB1_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F9FB1_FFDB13                    CAN_F9FB1_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F9FB1_FFDB14_Pos                (14U)
#define CAN_F9FB1_FFDB14_Msk                (0x1U << CAN_F9FB1_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F9FB1_FFDB14                    CAN_F9FB1_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F9FB1_FFDB15_Pos                (15U)
#define CAN_F9FB1_FFDB15_Msk                (0x1U << CAN_F9FB1_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F9FB1_FFDB15                    CAN_F9FB1_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F9FB1_FFDB16_Pos                (16U)
#define CAN_F9FB1_FFDB16_Msk                (0x1U << CAN_F9FB1_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F9FB1_FFDB16                    CAN_F9FB1_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F9FB1_FFDB17_Pos                (17U)
#define CAN_F9FB1_FFDB17_Msk                (0x1U << CAN_F9FB1_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F9FB1_FFDB17                    CAN_F9FB1_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F9FB1_FFDB18_Pos                (18U)
#define CAN_F9FB1_FFDB18_Msk                (0x1U << CAN_F9FB1_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F9FB1_FFDB18                    CAN_F9FB1_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F9FB1_FFDB19_Pos                (19U)
#define CAN_F9FB1_FFDB19_Msk                (0x1U << CAN_F9FB1_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F9FB1_FFDB19                    CAN_F9FB1_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F9FB1_FFDB20_Pos                (20U)
#define CAN_F9FB1_FFDB20_Msk                (0x1U << CAN_F9FB1_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F9FB1_FFDB20                    CAN_F9FB1_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F9FB1_FFDB21_Pos                (21U)
#define CAN_F9FB1_FFDB21_Msk                (0x1U << CAN_F9FB1_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F9FB1_FFDB21                    CAN_F9FB1_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F9FB1_FFDB22_Pos                (22U)
#define CAN_F9FB1_FFDB22_Msk                (0x1U << CAN_F9FB1_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F9FB1_FFDB22                    CAN_F9FB1_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F9FB1_FFDB23_Pos                (23U)
#define CAN_F9FB1_FFDB23_Msk                (0x1U << CAN_F9FB1_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F9FB1_FFDB23                    CAN_F9FB1_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F9FB1_FFDB24_Pos                (24U)
#define CAN_F9FB1_FFDB24_Msk                (0x1U << CAN_F9FB1_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F9FB1_FFDB24                    CAN_F9FB1_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F9FB1_FFDB25_Pos                (25U)
#define CAN_F9FB1_FFDB25_Msk                (0x1U << CAN_F9FB1_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F9FB1_FFDB25                    CAN_F9FB1_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F9FB1_FFDB26_Pos                (26U)
#define CAN_F9FB1_FFDB26_Msk                (0x1U << CAN_F9FB1_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F9FB1_FFDB26                    CAN_F9FB1_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F9FB1_FFDB27_Pos                (27U)
#define CAN_F9FB1_FFDB27_Msk                (0x1U << CAN_F9FB1_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F9FB1_FFDB27                    CAN_F9FB1_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F9FB1_FFDB28_Pos                (28U)
#define CAN_F9FB1_FFDB28_Msk                (0x1U << CAN_F9FB1_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F9FB1_FFDB28                    CAN_F9FB1_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F9FB1_FFDB29_Pos                (29U)
#define CAN_F9FB1_FFDB29_Msk                (0x1U << CAN_F9FB1_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F9FB1_FFDB29                    CAN_F9FB1_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F9FB1_FFDB30_Pos                (30U)
#define CAN_F9FB1_FFDB30_Msk                (0x1U << CAN_F9FB1_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F9FB1_FFDB30                    CAN_F9FB1_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F9FB1_FFDB31_Pos                (31U)
#define CAN_F9FB1_FFDB31_Msk                (0x1U << CAN_F9FB1_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F9FB1_FFDB31                    CAN_F9FB1_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F10FB1 register  ******************/
#define CAN_F10FB1_FFDB0_Pos                (0U)
#define CAN_F10FB1_FFDB0_Msk                (0x1U << CAN_F10FB1_FFDB0_Pos)          /*!< 0x00000001 */
#define CAN_F10FB1_FFDB0                    CAN_F10FB1_FFDB0_Msk                    /*!< Filter data bit 0 */
#define CAN_F10FB1_FFDB1_Pos                (1U)
#define CAN_F10FB1_FFDB1_Msk                (0x1U << CAN_F10FB1_FFDB1_Pos)          /*!< 0x00000002 */
#define CAN_F10FB1_FFDB1                    CAN_F10FB1_FFDB1_Msk                    /*!< Filter data bit 1 */
#define CAN_F10FB1_FFDB2_Pos                (2U)
#define CAN_F10FB1_FFDB2_Msk                (0x1U << CAN_F10FB1_FFDB2_Pos)          /*!< 0x00000004 */
#define CAN_F10FB1_FFDB2                    CAN_F10FB1_FFDB2_Msk                    /*!< Filter data bit 2 */
#define CAN_F10FB1_FFDB3_Pos                (3U)
#define CAN_F10FB1_FFDB3_Msk                (0x1U << CAN_F10FB1_FFDB3_Pos)          /*!< 0x00000008 */
#define CAN_F10FB1_FFDB3                    CAN_F10FB1_FFDB3_Msk                    /*!< Filter data bit 3 */
#define CAN_F10FB1_FFDB4_Pos                (4U)
#define CAN_F10FB1_FFDB4_Msk                (0x1U << CAN_F10FB1_FFDB4_Pos)          /*!< 0x00000010 */
#define CAN_F10FB1_FFDB4                    CAN_F10FB1_FFDB4_Msk                    /*!< Filter data bit 4 */
#define CAN_F10FB1_FFDB5_Pos                (5U)
#define CAN_F10FB1_FFDB5_Msk                (0x1U << CAN_F10FB1_FFDB5_Pos)          /*!< 0x00000020 */
#define CAN_F10FB1_FFDB5                    CAN_F10FB1_FFDB5_Msk                    /*!< Filter data bit 5 */
#define CAN_F10FB1_FFDB6_Pos                (6U)
#define CAN_F10FB1_FFDB6_Msk                (0x1U << CAN_F10FB1_FFDB6_Pos)          /*!< 0x00000040 */
#define CAN_F10FB1_FFDB6                    CAN_F10FB1_FFDB6_Msk                    /*!< Filter data bit 6 */
#define CAN_F10FB1_FFDB7_Pos                (7U)
#define CAN_F10FB1_FFDB7_Msk                (0x1U << CAN_F10FB1_FFDB7_Pos)          /*!< 0x00000080 */
#define CAN_F10FB1_FFDB7                    CAN_F10FB1_FFDB7_Msk                    /*!< Filter data bit 7 */
#define CAN_F10FB1_FFDB8_Pos                (8U)
#define CAN_F10FB1_FFDB8_Msk                (0x1U << CAN_F10FB1_FFDB8_Pos)          /*!< 0x00000100 */
#define CAN_F10FB1_FFDB8                    CAN_F10FB1_FFDB8_Msk                    /*!< Filter data bit 8 */
#define CAN_F10FB1_FFDB9_Pos                (9U)
#define CAN_F10FB1_FFDB9_Msk                (0x1U << CAN_F10FB1_FFDB9_Pos)          /*!< 0x00000200 */
#define CAN_F10FB1_FFDB9                    CAN_F10FB1_FFDB9_Msk                    /*!< Filter data bit 9 */
#define CAN_F10FB1_FFDB10_Pos               (10U)
#define CAN_F10FB1_FFDB10_Msk               (0x1U << CAN_F10FB1_FFDB10_Pos)         /*!< 0x00000400 */
#define CAN_F10FB1_FFDB10                   CAN_F10FB1_FFDB10_Msk                   /*!< Filter data bit 10 */
#define CAN_F10FB1_FFDB11_Pos               (11U)
#define CAN_F10FB1_FFDB11_Msk               (0x1U << CAN_F10FB1_FFDB11_Pos)         /*!< 0x00000800 */
#define CAN_F10FB1_FFDB11                   CAN_F10FB1_FFDB11_Msk                   /*!< Filter data bit 11 */
#define CAN_F10FB1_FFDB12_Pos               (12U)
#define CAN_F10FB1_FFDB12_Msk               (0x1U << CAN_F10FB1_FFDB12_Pos)         /*!< 0x00001000 */
#define CAN_F10FB1_FFDB12                   CAN_F10FB1_FFDB12_Msk                   /*!< Filter data bit 12 */
#define CAN_F10FB1_FFDB13_Pos               (13U)
#define CAN_F10FB1_FFDB13_Msk               (0x1U << CAN_F10FB1_FFDB13_Pos)         /*!< 0x00002000 */
#define CAN_F10FB1_FFDB13                   CAN_F10FB1_FFDB13_Msk                   /*!< Filter data bit 13 */
#define CAN_F10FB1_FFDB14_Pos               (14U)
#define CAN_F10FB1_FFDB14_Msk               (0x1U << CAN_F10FB1_FFDB14_Pos)         /*!< 0x00004000 */
#define CAN_F10FB1_FFDB14                   CAN_F10FB1_FFDB14_Msk                   /*!< Filter data bit 14 */
#define CAN_F10FB1_FFDB15_Pos               (15U)
#define CAN_F10FB1_FFDB15_Msk               (0x1U << CAN_F10FB1_FFDB15_Pos)         /*!< 0x00008000 */
#define CAN_F10FB1_FFDB15                   CAN_F10FB1_FFDB15_Msk                   /*!< Filter data bit 15 */
#define CAN_F10FB1_FFDB16_Pos               (16U)
#define CAN_F10FB1_FFDB16_Msk               (0x1U << CAN_F10FB1_FFDB16_Pos)         /*!< 0x00010000 */
#define CAN_F10FB1_FFDB16                   CAN_F10FB1_FFDB16_Msk                   /*!< Filter data bit 16 */
#define CAN_F10FB1_FFDB17_Pos               (17U)
#define CAN_F10FB1_FFDB17_Msk               (0x1U << CAN_F10FB1_FFDB17_Pos)         /*!< 0x00020000 */
#define CAN_F10FB1_FFDB17                   CAN_F10FB1_FFDB17_Msk                   /*!< Filter data bit 17 */
#define CAN_F10FB1_FFDB18_Pos               (18U)
#define CAN_F10FB1_FFDB18_Msk               (0x1U << CAN_F10FB1_FFDB18_Pos)         /*!< 0x00040000 */
#define CAN_F10FB1_FFDB18                   CAN_F10FB1_FFDB18_Msk                   /*!< Filter data bit 18 */
#define CAN_F10FB1_FFDB19_Pos               (19U)
#define CAN_F10FB1_FFDB19_Msk               (0x1U << CAN_F10FB1_FFDB19_Pos)         /*!< 0x00080000 */
#define CAN_F10FB1_FFDB19                   CAN_F10FB1_FFDB19_Msk                   /*!< Filter data bit 19 */
#define CAN_F10FB1_FFDB20_Pos               (20U)
#define CAN_F10FB1_FFDB20_Msk               (0x1U << CAN_F10FB1_FFDB20_Pos)         /*!< 0x00100000 */
#define CAN_F10FB1_FFDB20                   CAN_F10FB1_FFDB20_Msk                   /*!< Filter data bit 20 */
#define CAN_F10FB1_FFDB21_Pos               (21U)
#define CAN_F10FB1_FFDB21_Msk               (0x1U << CAN_F10FB1_FFDB21_Pos)         /*!< 0x00200000 */
#define CAN_F10FB1_FFDB21                   CAN_F10FB1_FFDB21_Msk                   /*!< Filter data bit 21 */
#define CAN_F10FB1_FFDB22_Pos               (22U)
#define CAN_F10FB1_FFDB22_Msk               (0x1U << CAN_F10FB1_FFDB22_Pos)         /*!< 0x00400000 */
#define CAN_F10FB1_FFDB22                   CAN_F10FB1_FFDB22_Msk                   /*!< Filter data bit 22 */
#define CAN_F10FB1_FFDB23_Pos               (23U)
#define CAN_F10FB1_FFDB23_Msk               (0x1U << CAN_F10FB1_FFDB23_Pos)         /*!< 0x00800000 */
#define CAN_F10FB1_FFDB23                   CAN_F10FB1_FFDB23_Msk                   /*!< Filter data bit 23 */
#define CAN_F10FB1_FFDB24_Pos               (24U)
#define CAN_F10FB1_FFDB24_Msk               (0x1U << CAN_F10FB1_FFDB24_Pos)         /*!< 0x01000000 */
#define CAN_F10FB1_FFDB24                   CAN_F10FB1_FFDB24_Msk                   /*!< Filter data bit 24 */
#define CAN_F10FB1_FFDB25_Pos               (25U)
#define CAN_F10FB1_FFDB25_Msk               (0x1U << CAN_F10FB1_FFDB25_Pos)         /*!< 0x02000000 */
#define CAN_F10FB1_FFDB25                   CAN_F10FB1_FFDB25_Msk                   /*!< Filter data bit 25 */
#define CAN_F10FB1_FFDB26_Pos               (26U)
#define CAN_F10FB1_FFDB26_Msk               (0x1U << CAN_F10FB1_FFDB26_Pos)         /*!< 0x04000000 */
#define CAN_F10FB1_FFDB26                   CAN_F10FB1_FFDB26_Msk                   /*!< Filter data bit 26 */
#define CAN_F10FB1_FFDB27_Pos               (27U)
#define CAN_F10FB1_FFDB27_Msk               (0x1U << CAN_F10FB1_FFDB27_Pos)         /*!< 0x08000000 */
#define CAN_F10FB1_FFDB27                   CAN_F10FB1_FFDB27_Msk                   /*!< Filter data bit 27 */
#define CAN_F10FB1_FFDB28_Pos               (28U)
#define CAN_F10FB1_FFDB28_Msk               (0x1U << CAN_F10FB1_FFDB28_Pos)         /*!< 0x10000000 */
#define CAN_F10FB1_FFDB28                   CAN_F10FB1_FFDB28_Msk                   /*!< Filter data bit 28 */
#define CAN_F10FB1_FFDB29_Pos               (29U)
#define CAN_F10FB1_FFDB29_Msk               (0x1U << CAN_F10FB1_FFDB29_Pos)         /*!< 0x20000000 */
#define CAN_F10FB1_FFDB29                   CAN_F10FB1_FFDB29_Msk                   /*!< Filter data bit 29 */
#define CAN_F10FB1_FFDB30_Pos               (30U)
#define CAN_F10FB1_FFDB30_Msk               (0x1U << CAN_F10FB1_FFDB30_Pos)         /*!< 0x40000000 */
#define CAN_F10FB1_FFDB30                   CAN_F10FB1_FFDB30_Msk                   /*!< Filter data bit 30 */
#define CAN_F10FB1_FFDB31_Pos               (31U)
#define CAN_F10FB1_FFDB31_Msk               (0x1U << CAN_F10FB1_FFDB31_Pos)         /*!< 0x80000000 */
#define CAN_F10FB1_FFDB31                   CAN_F10FB1_FFDB31_Msk                   /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F11FB1 register  ******************/
#define CAN_F11FB1_FFDB0_Pos                (0U)
#define CAN_F11FB1_FFDB0_Msk                (0x1U << CAN_F11FB1_FFDB0_Pos)          /*!< 0x00000001 */
#define CAN_F11FB1_FFDB0                    CAN_F11FB1_FFDB0_Msk                    /*!< Filter data bit 0 */
#define CAN_F11FB1_FFDB1_Pos                (1U)
#define CAN_F11FB1_FFDB1_Msk                (0x1U << CAN_F11FB1_FFDB1_Pos)          /*!< 0x00000002 */
#define CAN_F11FB1_FFDB1                    CAN_F11FB1_FFDB1_Msk                    /*!< Filter data bit 1 */
#define CAN_F11FB1_FFDB2_Pos                (2U)
#define CAN_F11FB1_FFDB2_Msk                (0x1U << CAN_F11FB1_FFDB2_Pos)          /*!< 0x00000004 */
#define CAN_F11FB1_FFDB2                    CAN_F11FB1_FFDB2_Msk                    /*!< Filter data bit 2 */
#define CAN_F11FB1_FFDB3_Pos                (3U)
#define CAN_F11FB1_FFDB3_Msk                (0x1U << CAN_F11FB1_FFDB3_Pos)          /*!< 0x00000008 */
#define CAN_F11FB1_FFDB3                    CAN_F11FB1_FFDB3_Msk                    /*!< Filter data bit 3 */
#define CAN_F11FB1_FFDB4_Pos                (4U)
#define CAN_F11FB1_FFDB4_Msk                (0x1U << CAN_F11FB1_FFDB4_Pos)          /*!< 0x00000010 */
#define CAN_F11FB1_FFDB4                    CAN_F11FB1_FFDB4_Msk                    /*!< Filter data bit 4 */
#define CAN_F11FB1_FFDB5_Pos                (5U)
#define CAN_F11FB1_FFDB5_Msk                (0x1U << CAN_F11FB1_FFDB5_Pos)          /*!< 0x00000020 */
#define CAN_F11FB1_FFDB5                    CAN_F11FB1_FFDB5_Msk                    /*!< Filter data bit 5 */
#define CAN_F11FB1_FFDB6_Pos                (6U)
#define CAN_F11FB1_FFDB6_Msk                (0x1U << CAN_F11FB1_FFDB6_Pos)          /*!< 0x00000040 */
#define CAN_F11FB1_FFDB6                    CAN_F11FB1_FFDB6_Msk                    /*!< Filter data bit 6 */
#define CAN_F11FB1_FFDB7_Pos                (7U)
#define CAN_F11FB1_FFDB7_Msk                (0x1U << CAN_F11FB1_FFDB7_Pos)          /*!< 0x00000080 */
#define CAN_F11FB1_FFDB7                    CAN_F11FB1_FFDB7_Msk                    /*!< Filter data bit 7 */
#define CAN_F11FB1_FFDB8_Pos                (8U)
#define CAN_F11FB1_FFDB8_Msk                (0x1U << CAN_F11FB1_FFDB8_Pos)          /*!< 0x00000100 */
#define CAN_F11FB1_FFDB8                    CAN_F11FB1_FFDB8_Msk                    /*!< Filter data bit 8 */
#define CAN_F11FB1_FFDB9_Pos                (9U)
#define CAN_F11FB1_FFDB9_Msk                (0x1U << CAN_F11FB1_FFDB9_Pos)          /*!< 0x00000200 */
#define CAN_F11FB1_FFDB9                    CAN_F11FB1_FFDB9_Msk                    /*!< Filter data bit 9 */
#define CAN_F11FB1_FFDB10_Pos               (10U)
#define CAN_F11FB1_FFDB10_Msk               (0x1U << CAN_F11FB1_FFDB10_Pos)         /*!< 0x00000400 */
#define CAN_F11FB1_FFDB10                   CAN_F11FB1_FFDB10_Msk                   /*!< Filter data bit 10 */
#define CAN_F11FB1_FFDB11_Pos               (11U)
#define CAN_F11FB1_FFDB11_Msk               (0x1U << CAN_F11FB1_FFDB11_Pos)         /*!< 0x00000800 */
#define CAN_F11FB1_FFDB11                   CAN_F11FB1_FFDB11_Msk                   /*!< Filter data bit 11 */
#define CAN_F11FB1_FFDB12_Pos               (12U)
#define CAN_F11FB1_FFDB12_Msk               (0x1U << CAN_F11FB1_FFDB12_Pos)         /*!< 0x00001000 */
#define CAN_F11FB1_FFDB12                   CAN_F11FB1_FFDB12_Msk                   /*!< Filter data bit 12 */
#define CAN_F11FB1_FFDB13_Pos               (13U)
#define CAN_F11FB1_FFDB13_Msk               (0x1U << CAN_F11FB1_FFDB13_Pos)         /*!< 0x00002000 */
#define CAN_F11FB1_FFDB13                   CAN_F11FB1_FFDB13_Msk                   /*!< Filter data bit 13 */
#define CAN_F11FB1_FFDB14_Pos               (14U)
#define CAN_F11FB1_FFDB14_Msk               (0x1U << CAN_F11FB1_FFDB14_Pos)         /*!< 0x00004000 */
#define CAN_F11FB1_FFDB14                   CAN_F11FB1_FFDB14_Msk                   /*!< Filter data bit 14 */
#define CAN_F11FB1_FFDB15_Pos               (15U)
#define CAN_F11FB1_FFDB15_Msk               (0x1U << CAN_F11FB1_FFDB15_Pos)         /*!< 0x00008000 */
#define CAN_F11FB1_FFDB15                   CAN_F11FB1_FFDB15_Msk                   /*!< Filter data bit 15 */
#define CAN_F11FB1_FFDB16_Pos               (16U)
#define CAN_F11FB1_FFDB16_Msk               (0x1U << CAN_F11FB1_FFDB16_Pos)         /*!< 0x00010000 */
#define CAN_F11FB1_FFDB16                   CAN_F11FB1_FFDB16_Msk                   /*!< Filter data bit 16 */
#define CAN_F11FB1_FFDB17_Pos               (17U)
#define CAN_F11FB1_FFDB17_Msk               (0x1U << CAN_F11FB1_FFDB17_Pos)         /*!< 0x00020000 */
#define CAN_F11FB1_FFDB17                   CAN_F11FB1_FFDB17_Msk                   /*!< Filter data bit 17 */
#define CAN_F11FB1_FFDB18_Pos               (18U)
#define CAN_F11FB1_FFDB18_Msk               (0x1U << CAN_F11FB1_FFDB18_Pos)         /*!< 0x00040000 */
#define CAN_F11FB1_FFDB18                   CAN_F11FB1_FFDB18_Msk                   /*!< Filter data bit 18 */
#define CAN_F11FB1_FFDB19_Pos               (19U)
#define CAN_F11FB1_FFDB19_Msk               (0x1U << CAN_F11FB1_FFDB19_Pos)         /*!< 0x00080000 */
#define CAN_F11FB1_FFDB19                   CAN_F11FB1_FFDB19_Msk                   /*!< Filter data bit 19 */
#define CAN_F11FB1_FFDB20_Pos               (20U)
#define CAN_F11FB1_FFDB20_Msk               (0x1U << CAN_F11FB1_FFDB20_Pos)         /*!< 0x00100000 */
#define CAN_F11FB1_FFDB20                   CAN_F11FB1_FFDB20_Msk                   /*!< Filter data bit 20 */
#define CAN_F11FB1_FFDB21_Pos               (21U)
#define CAN_F11FB1_FFDB21_Msk               (0x1U << CAN_F11FB1_FFDB21_Pos)         /*!< 0x00200000 */
#define CAN_F11FB1_FFDB21                   CAN_F11FB1_FFDB21_Msk                   /*!< Filter data bit 21 */
#define CAN_F11FB1_FFDB22_Pos               (22U)
#define CAN_F11FB1_FFDB22_Msk               (0x1U << CAN_F11FB1_FFDB22_Pos)         /*!< 0x00400000 */
#define CAN_F11FB1_FFDB22                   CAN_F11FB1_FFDB22_Msk                   /*!< Filter data bit 22 */
#define CAN_F11FB1_FFDB23_Pos               (23U)
#define CAN_F11FB1_FFDB23_Msk               (0x1U << CAN_F11FB1_FFDB23_Pos)         /*!< 0x00800000 */
#define CAN_F11FB1_FFDB23                   CAN_F11FB1_FFDB23_Msk                   /*!< Filter data bit 23 */
#define CAN_F11FB1_FFDB24_Pos               (24U)
#define CAN_F11FB1_FFDB24_Msk               (0x1U << CAN_F11FB1_FFDB24_Pos)         /*!< 0x01000000 */
#define CAN_F11FB1_FFDB24                   CAN_F11FB1_FFDB24_Msk                   /*!< Filter data bit 24 */
#define CAN_F11FB1_FFDB25_Pos               (25U)
#define CAN_F11FB1_FFDB25_Msk               (0x1U << CAN_F11FB1_FFDB25_Pos)         /*!< 0x02000000 */
#define CAN_F11FB1_FFDB25                   CAN_F11FB1_FFDB25_Msk                   /*!< Filter data bit 25 */
#define CAN_F11FB1_FFDB26_Pos               (26U)
#define CAN_F11FB1_FFDB26_Msk               (0x1U << CAN_F11FB1_FFDB26_Pos)         /*!< 0x04000000 */
#define CAN_F11FB1_FFDB26                   CAN_F11FB1_FFDB26_Msk                   /*!< Filter data bit 26 */
#define CAN_F11FB1_FFDB27_Pos               (27U)
#define CAN_F11FB1_FFDB27_Msk               (0x1U << CAN_F11FB1_FFDB27_Pos)         /*!< 0x08000000 */
#define CAN_F11FB1_FFDB27                   CAN_F11FB1_FFDB27_Msk                   /*!< Filter data bit 27 */
#define CAN_F11FB1_FFDB28_Pos               (28U)
#define CAN_F11FB1_FFDB28_Msk               (0x1U << CAN_F11FB1_FFDB28_Pos)         /*!< 0x10000000 */
#define CAN_F11FB1_FFDB28                   CAN_F11FB1_FFDB28_Msk                   /*!< Filter data bit 28 */
#define CAN_F11FB1_FFDB29_Pos               (29U)
#define CAN_F11FB1_FFDB29_Msk               (0x1U << CAN_F11FB1_FFDB29_Pos)         /*!< 0x20000000 */
#define CAN_F11FB1_FFDB29                   CAN_F11FB1_FFDB29_Msk                   /*!< Filter data bit 29 */
#define CAN_F11FB1_FFDB30_Pos               (30U)
#define CAN_F11FB1_FFDB30_Msk               (0x1U << CAN_F11FB1_FFDB30_Pos)         /*!< 0x40000000 */
#define CAN_F11FB1_FFDB30                   CAN_F11FB1_FFDB30_Msk                   /*!< Filter data bit 30 */
#define CAN_F11FB1_FFDB31_Pos               (31U)
#define CAN_F11FB1_FFDB31_Msk               (0x1U << CAN_F11FB1_FFDB31_Pos)         /*!< 0x80000000 */
#define CAN_F11FB1_FFDB31                   CAN_F11FB1_FFDB31_Msk                   /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F12FB1 register  ******************/
#define CAN_F12FB1_FFDB0_Pos                (0U)
#define CAN_F12FB1_FFDB0_Msk                (0x1U << CAN_F12FB1_FFDB0_Pos)          /*!< 0x00000001 */
#define CAN_F12FB1_FFDB0                    CAN_F12FB1_FFDB0_Msk                    /*!< Filter data bit 0 */
#define CAN_F12FB1_FFDB1_Pos                (1U)
#define CAN_F12FB1_FFDB1_Msk                (0x1U << CAN_F12FB1_FFDB1_Pos)          /*!< 0x00000002 */
#define CAN_F12FB1_FFDB1                    CAN_F12FB1_FFDB1_Msk                    /*!< Filter data bit 1 */
#define CAN_F12FB1_FFDB2_Pos                (2U)
#define CAN_F12FB1_FFDB2_Msk                (0x1U << CAN_F12FB1_FFDB2_Pos)          /*!< 0x00000004 */
#define CAN_F12FB1_FFDB2                    CAN_F12FB1_FFDB2_Msk                    /*!< Filter data bit 2 */
#define CAN_F12FB1_FFDB3_Pos                (3U)
#define CAN_F12FB1_FFDB3_Msk                (0x1U << CAN_F12FB1_FFDB3_Pos)          /*!< 0x00000008 */
#define CAN_F12FB1_FFDB3                    CAN_F12FB1_FFDB3_Msk                    /*!< Filter data bit 3 */
#define CAN_F12FB1_FFDB4_Pos                (4U)
#define CAN_F12FB1_FFDB4_Msk                (0x1U << CAN_F12FB1_FFDB4_Pos)          /*!< 0x00000010 */
#define CAN_F12FB1_FFDB4                    CAN_F12FB1_FFDB4_Msk                    /*!< Filter data bit 4 */
#define CAN_F12FB1_FFDB5_Pos                (5U)
#define CAN_F12FB1_FFDB5_Msk                (0x1U << CAN_F12FB1_FFDB5_Pos)          /*!< 0x00000020 */
#define CAN_F12FB1_FFDB5                    CAN_F12FB1_FFDB5_Msk                    /*!< Filter data bit 5 */
#define CAN_F12FB1_FFDB6_Pos                (6U)
#define CAN_F12FB1_FFDB6_Msk                (0x1U << CAN_F12FB1_FFDB6_Pos)          /*!< 0x00000040 */
#define CAN_F12FB1_FFDB6                    CAN_F12FB1_FFDB6_Msk                    /*!< Filter data bit 6 */
#define CAN_F12FB1_FFDB7_Pos                (7U)
#define CAN_F12FB1_FFDB7_Msk                (0x1U << CAN_F12FB1_FFDB7_Pos)          /*!< 0x00000080 */
#define CAN_F12FB1_FFDB7                    CAN_F12FB1_FFDB7_Msk                    /*!< Filter data bit 7 */
#define CAN_F12FB1_FFDB8_Pos                (8U)
#define CAN_F12FB1_FFDB8_Msk                (0x1U << CAN_F12FB1_FFDB8_Pos)          /*!< 0x00000100 */
#define CAN_F12FB1_FFDB8                    CAN_F12FB1_FFDB8_Msk                    /*!< Filter data bit 8 */
#define CAN_F12FB1_FFDB9_Pos                (9U)
#define CAN_F12FB1_FFDB9_Msk                (0x1U << CAN_F12FB1_FFDB9_Pos)          /*!< 0x00000200 */
#define CAN_F12FB1_FFDB9                    CAN_F12FB1_FFDB9_Msk                    /*!< Filter data bit 9 */
#define CAN_F12FB1_FFDB10_Pos               (10U)
#define CAN_F12FB1_FFDB10_Msk               (0x1U << CAN_F12FB1_FFDB10_Pos)         /*!< 0x00000400 */
#define CAN_F12FB1_FFDB10                   CAN_F12FB1_FFDB10_Msk                   /*!< Filter data bit 10 */
#define CAN_F12FB1_FFDB11_Pos               (11U)
#define CAN_F12FB1_FFDB11_Msk               (0x1U << CAN_F12FB1_FFDB11_Pos)         /*!< 0x00000800 */
#define CAN_F12FB1_FFDB11                   CAN_F12FB1_FFDB11_Msk                   /*!< Filter data bit 11 */
#define CAN_F12FB1_FFDB12_Pos               (12U)
#define CAN_F12FB1_FFDB12_Msk               (0x1U << CAN_F12FB1_FFDB12_Pos)         /*!< 0x00001000 */
#define CAN_F12FB1_FFDB12                   CAN_F12FB1_FFDB12_Msk                   /*!< Filter data bit 12 */
#define CAN_F12FB1_FFDB13_Pos               (13U)
#define CAN_F12FB1_FFDB13_Msk               (0x1U << CAN_F12FB1_FFDB13_Pos)         /*!< 0x00002000 */
#define CAN_F12FB1_FFDB13                   CAN_F12FB1_FFDB13_Msk                   /*!< Filter data bit 13 */
#define CAN_F12FB1_FFDB14_Pos               (14U)
#define CAN_F12FB1_FFDB14_Msk               (0x1U << CAN_F12FB1_FFDB14_Pos)         /*!< 0x00004000 */
#define CAN_F12FB1_FFDB14                   CAN_F12FB1_FFDB14_Msk                   /*!< Filter data bit 14 */
#define CAN_F12FB1_FFDB15_Pos               (15U)
#define CAN_F12FB1_FFDB15_Msk               (0x1U << CAN_F12FB1_FFDB15_Pos)         /*!< 0x00008000 */
#define CAN_F12FB1_FFDB15                   CAN_F12FB1_FFDB15_Msk                   /*!< Filter data bit 15 */
#define CAN_F12FB1_FFDB16_Pos               (16U)
#define CAN_F12FB1_FFDB16_Msk               (0x1U << CAN_F12FB1_FFDB16_Pos)         /*!< 0x00010000 */
#define CAN_F12FB1_FFDB16                   CAN_F12FB1_FFDB16_Msk                   /*!< Filter data bit 16 */
#define CAN_F12FB1_FFDB17_Pos               (17U)
#define CAN_F12FB1_FFDB17_Msk               (0x1U << CAN_F12FB1_FFDB17_Pos)         /*!< 0x00020000 */
#define CAN_F12FB1_FFDB17                   CAN_F12FB1_FFDB17_Msk                   /*!< Filter data bit 17 */
#define CAN_F12FB1_FFDB18_Pos               (18U)
#define CAN_F12FB1_FFDB18_Msk               (0x1U << CAN_F12FB1_FFDB18_Pos)         /*!< 0x00040000 */
#define CAN_F12FB1_FFDB18                   CAN_F12FB1_FFDB18_Msk                   /*!< Filter data bit 18 */
#define CAN_F12FB1_FFDB19_Pos               (19U)
#define CAN_F12FB1_FFDB19_Msk               (0x1U << CAN_F12FB1_FFDB19_Pos)         /*!< 0x00080000 */
#define CAN_F12FB1_FFDB19                   CAN_F12FB1_FFDB19_Msk                   /*!< Filter data bit 19 */
#define CAN_F12FB1_FFDB20_Pos               (20U)
#define CAN_F12FB1_FFDB20_Msk               (0x1U << CAN_F12FB1_FFDB20_Pos)         /*!< 0x00100000 */
#define CAN_F12FB1_FFDB20                   CAN_F12FB1_FFDB20_Msk                   /*!< Filter data bit 20 */
#define CAN_F12FB1_FFDB21_Pos               (21U)
#define CAN_F12FB1_FFDB21_Msk               (0x1U << CAN_F12FB1_FFDB21_Pos)         /*!< 0x00200000 */
#define CAN_F12FB1_FFDB21                   CAN_F12FB1_FFDB21_Msk                   /*!< Filter data bit 21 */
#define CAN_F12FB1_FFDB22_Pos               (22U)
#define CAN_F12FB1_FFDB22_Msk               (0x1U << CAN_F12FB1_FFDB22_Pos)         /*!< 0x00400000 */
#define CAN_F12FB1_FFDB22                   CAN_F12FB1_FFDB22_Msk                   /*!< Filter data bit 22 */
#define CAN_F12FB1_FFDB23_Pos               (23U)
#define CAN_F12FB1_FFDB23_Msk               (0x1U << CAN_F12FB1_FFDB23_Pos)         /*!< 0x00800000 */
#define CAN_F12FB1_FFDB23                   CAN_F12FB1_FFDB23_Msk                   /*!< Filter data bit 23 */
#define CAN_F12FB1_FFDB24_Pos               (24U)
#define CAN_F12FB1_FFDB24_Msk               (0x1U << CAN_F12FB1_FFDB24_Pos)         /*!< 0x01000000 */
#define CAN_F12FB1_FFDB24                   CAN_F12FB1_FFDB24_Msk                   /*!< Filter data bit 24 */
#define CAN_F12FB1_FFDB25_Pos               (25U)
#define CAN_F12FB1_FFDB25_Msk               (0x1U << CAN_F12FB1_FFDB25_Pos)         /*!< 0x02000000 */
#define CAN_F12FB1_FFDB25                   CAN_F12FB1_FFDB25_Msk                   /*!< Filter data bit 25 */
#define CAN_F12FB1_FFDB26_Pos               (26U)
#define CAN_F12FB1_FFDB26_Msk               (0x1U << CAN_F12FB1_FFDB26_Pos)         /*!< 0x04000000 */
#define CAN_F12FB1_FFDB26                   CAN_F12FB1_FFDB26_Msk                   /*!< Filter data bit 26 */
#define CAN_F12FB1_FFDB27_Pos               (27U)
#define CAN_F12FB1_FFDB27_Msk               (0x1U << CAN_F12FB1_FFDB27_Pos)         /*!< 0x08000000 */
#define CAN_F12FB1_FFDB27                   CAN_F12FB1_FFDB27_Msk                   /*!< Filter data bit 27 */
#define CAN_F12FB1_FFDB28_Pos               (28U)
#define CAN_F12FB1_FFDB28_Msk               (0x1U << CAN_F12FB1_FFDB28_Pos)         /*!< 0x10000000 */
#define CAN_F12FB1_FFDB28                   CAN_F12FB1_FFDB28_Msk                   /*!< Filter data bit 28 */
#define CAN_F12FB1_FFDB29_Pos               (29U)
#define CAN_F12FB1_FFDB29_Msk               (0x1U << CAN_F12FB1_FFDB29_Pos)         /*!< 0x20000000 */
#define CAN_F12FB1_FFDB29                   CAN_F12FB1_FFDB29_Msk                   /*!< Filter data bit 29 */
#define CAN_F12FB1_FFDB30_Pos               (30U)
#define CAN_F12FB1_FFDB30_Msk               (0x1U << CAN_F12FB1_FFDB30_Pos)         /*!< 0x40000000 */
#define CAN_F12FB1_FFDB30                   CAN_F12FB1_FFDB30_Msk                   /*!< Filter data bit 30 */
#define CAN_F12FB1_FFDB31_Pos               (31U)
#define CAN_F12FB1_FFDB31_Msk               (0x1U << CAN_F12FB1_FFDB31_Pos)         /*!< 0x80000000 */
#define CAN_F12FB1_FFDB31                   CAN_F12FB1_FFDB31_Msk                   /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F13FB1 register  ******************/
#define CAN_F13FB1_FFDB0_Pos                (0U)
#define CAN_F13FB1_FFDB0_Msk                (0x1U << CAN_F13FB1_FFDB0_Pos)          /*!< 0x00000001 */
#define CAN_F13FB1_FFDB0                    CAN_F13FB1_FFDB0_Msk                    /*!< Filter data bit 0 */
#define CAN_F13FB1_FFDB1_Pos                (1U)
#define CAN_F13FB1_FFDB1_Msk                (0x1U << CAN_F13FB1_FFDB1_Pos)          /*!< 0x00000002 */
#define CAN_F13FB1_FFDB1                    CAN_F13FB1_FFDB1_Msk                    /*!< Filter data bit 1 */
#define CAN_F13FB1_FFDB2_Pos                (2U)
#define CAN_F13FB1_FFDB2_Msk                (0x1U << CAN_F13FB1_FFDB2_Pos)          /*!< 0x00000004 */
#define CAN_F13FB1_FFDB2                    CAN_F13FB1_FFDB2_Msk                    /*!< Filter data bit 2 */
#define CAN_F13FB1_FFDB3_Pos                (3U)
#define CAN_F13FB1_FFDB3_Msk                (0x1U << CAN_F13FB1_FFDB3_Pos)          /*!< 0x00000008 */
#define CAN_F13FB1_FFDB3                    CAN_F13FB1_FFDB3_Msk                    /*!< Filter data bit 3 */
#define CAN_F13FB1_FFDB4_Pos                (4U)
#define CAN_F13FB1_FFDB4_Msk                (0x1U << CAN_F13FB1_FFDB4_Pos)          /*!< 0x00000010 */
#define CAN_F13FB1_FFDB4                    CAN_F13FB1_FFDB4_Msk                    /*!< Filter data bit 4 */
#define CAN_F13FB1_FFDB5_Pos                (5U)
#define CAN_F13FB1_FFDB5_Msk                (0x1U << CAN_F13FB1_FFDB5_Pos)          /*!< 0x00000020 */
#define CAN_F13FB1_FFDB5                    CAN_F13FB1_FFDB5_Msk                    /*!< Filter data bit 5 */
#define CAN_F13FB1_FFDB6_Pos                (6U)
#define CAN_F13FB1_FFDB6_Msk                (0x1U << CAN_F13FB1_FFDB6_Pos)          /*!< 0x00000040 */
#define CAN_F13FB1_FFDB6                    CAN_F13FB1_FFDB6_Msk                    /*!< Filter data bit 6 */
#define CAN_F13FB1_FFDB7_Pos                (7U)
#define CAN_F13FB1_FFDB7_Msk                (0x1U << CAN_F13FB1_FFDB7_Pos)          /*!< 0x00000080 */
#define CAN_F13FB1_FFDB7                    CAN_F13FB1_FFDB7_Msk                    /*!< Filter data bit 7 */
#define CAN_F13FB1_FFDB8_Pos                (8U)
#define CAN_F13FB1_FFDB8_Msk                (0x1U << CAN_F13FB1_FFDB8_Pos)          /*!< 0x00000100 */
#define CAN_F13FB1_FFDB8                    CAN_F13FB1_FFDB8_Msk                    /*!< Filter data bit 8 */
#define CAN_F13FB1_FFDB9_Pos                (9U)
#define CAN_F13FB1_FFDB9_Msk                (0x1U << CAN_F13FB1_FFDB9_Pos)          /*!< 0x00000200 */
#define CAN_F13FB1_FFDB9                    CAN_F13FB1_FFDB9_Msk                    /*!< Filter data bit 9 */
#define CAN_F13FB1_FFDB10_Pos               (10U)
#define CAN_F13FB1_FFDB10_Msk               (0x1U << CAN_F13FB1_FFDB10_Pos)         /*!< 0x00000400 */
#define CAN_F13FB1_FFDB10                   CAN_F13FB1_FFDB10_Msk                   /*!< Filter data bit 10 */
#define CAN_F13FB1_FFDB11_Pos               (11U)
#define CAN_F13FB1_FFDB11_Msk               (0x1U << CAN_F13FB1_FFDB11_Pos)         /*!< 0x00000800 */
#define CAN_F13FB1_FFDB11                   CAN_F13FB1_FFDB11_Msk                   /*!< Filter data bit 11 */
#define CAN_F13FB1_FFDB12_Pos               (12U)
#define CAN_F13FB1_FFDB12_Msk               (0x1U << CAN_F13FB1_FFDB12_Pos)         /*!< 0x00001000 */
#define CAN_F13FB1_FFDB12                   CAN_F13FB1_FFDB12_Msk                   /*!< Filter data bit 12 */
#define CAN_F13FB1_FFDB13_Pos               (13U)
#define CAN_F13FB1_FFDB13_Msk               (0x1U << CAN_F13FB1_FFDB13_Pos)         /*!< 0x00002000 */
#define CAN_F13FB1_FFDB13                   CAN_F13FB1_FFDB13_Msk                   /*!< Filter data bit 13 */
#define CAN_F13FB1_FFDB14_Pos               (14U)
#define CAN_F13FB1_FFDB14_Msk               (0x1U << CAN_F13FB1_FFDB14_Pos)         /*!< 0x00004000 */
#define CAN_F13FB1_FFDB14                   CAN_F13FB1_FFDB14_Msk                   /*!< Filter data bit 14 */
#define CAN_F13FB1_FFDB15_Pos               (15U)
#define CAN_F13FB1_FFDB15_Msk               (0x1U << CAN_F13FB1_FFDB15_Pos)         /*!< 0x00008000 */
#define CAN_F13FB1_FFDB15                   CAN_F13FB1_FFDB15_Msk                   /*!< Filter data bit 15 */
#define CAN_F13FB1_FFDB16_Pos               (16U)
#define CAN_F13FB1_FFDB16_Msk               (0x1U << CAN_F13FB1_FFDB16_Pos)         /*!< 0x00010000 */
#define CAN_F13FB1_FFDB16                   CAN_F13FB1_FFDB16_Msk                   /*!< Filter data bit 16 */
#define CAN_F13FB1_FFDB17_Pos               (17U)
#define CAN_F13FB1_FFDB17_Msk               (0x1U << CAN_F13FB1_FFDB17_Pos)         /*!< 0x00020000 */
#define CAN_F13FB1_FFDB17                   CAN_F13FB1_FFDB17_Msk                   /*!< Filter data bit 17 */
#define CAN_F13FB1_FFDB18_Pos               (18U)
#define CAN_F13FB1_FFDB18_Msk               (0x1U << CAN_F13FB1_FFDB18_Pos)         /*!< 0x00040000 */
#define CAN_F13FB1_FFDB18                   CAN_F13FB1_FFDB18_Msk                   /*!< Filter data bit 18 */
#define CAN_F13FB1_FFDB19_Pos               (19U)
#define CAN_F13FB1_FFDB19_Msk               (0x1U << CAN_F13FB1_FFDB19_Pos)         /*!< 0x00080000 */
#define CAN_F13FB1_FFDB19                   CAN_F13FB1_FFDB19_Msk                   /*!< Filter data bit 19 */
#define CAN_F13FB1_FFDB20_Pos               (20U)
#define CAN_F13FB1_FFDB20_Msk               (0x1U << CAN_F13FB1_FFDB20_Pos)         /*!< 0x00100000 */
#define CAN_F13FB1_FFDB20                   CAN_F13FB1_FFDB20_Msk                   /*!< Filter data bit 20 */
#define CAN_F13FB1_FFDB21_Pos               (21U)
#define CAN_F13FB1_FFDB21_Msk               (0x1U << CAN_F13FB1_FFDB21_Pos)         /*!< 0x00200000 */
#define CAN_F13FB1_FFDB21                   CAN_F13FB1_FFDB21_Msk                   /*!< Filter data bit 21 */
#define CAN_F13FB1_FFDB22_Pos               (22U)
#define CAN_F13FB1_FFDB22_Msk               (0x1U << CAN_F13FB1_FFDB22_Pos)         /*!< 0x00400000 */
#define CAN_F13FB1_FFDB22                   CAN_F13FB1_FFDB22_Msk                   /*!< Filter data bit 22 */
#define CAN_F13FB1_FFDB23_Pos               (23U)
#define CAN_F13FB1_FFDB23_Msk               (0x1U << CAN_F13FB1_FFDB23_Pos)         /*!< 0x00800000 */
#define CAN_F13FB1_FFDB23                   CAN_F13FB1_FFDB23_Msk                   /*!< Filter data bit 23 */
#define CAN_F13FB1_FFDB24_Pos               (24U)
#define CAN_F13FB1_FFDB24_Msk               (0x1U << CAN_F13FB1_FFDB24_Pos)         /*!< 0x01000000 */
#define CAN_F13FB1_FFDB24                   CAN_F13FB1_FFDB24_Msk                   /*!< Filter data bit 24 */
#define CAN_F13FB1_FFDB25_Pos               (25U)
#define CAN_F13FB1_FFDB25_Msk               (0x1U << CAN_F13FB1_FFDB25_Pos)         /*!< 0x02000000 */
#define CAN_F13FB1_FFDB25                   CAN_F13FB1_FFDB25_Msk                   /*!< Filter data bit 25 */
#define CAN_F13FB1_FFDB26_Pos               (26U)
#define CAN_F13FB1_FFDB26_Msk               (0x1U << CAN_F13FB1_FFDB26_Pos)         /*!< 0x04000000 */
#define CAN_F13FB1_FFDB26                   CAN_F13FB1_FFDB26_Msk                   /*!< Filter data bit 26 */
#define CAN_F13FB1_FFDB27_Pos               (27U)
#define CAN_F13FB1_FFDB27_Msk               (0x1U << CAN_F13FB1_FFDB27_Pos)         /*!< 0x08000000 */
#define CAN_F13FB1_FFDB27                   CAN_F13FB1_FFDB27_Msk                   /*!< Filter data bit 27 */
#define CAN_F13FB1_FFDB28_Pos               (28U)
#define CAN_F13FB1_FFDB28_Msk               (0x1U << CAN_F13FB1_FFDB28_Pos)         /*!< 0x10000000 */
#define CAN_F13FB1_FFDB28                   CAN_F13FB1_FFDB28_Msk                   /*!< Filter data bit 28 */
#define CAN_F13FB1_FFDB29_Pos               (29U)
#define CAN_F13FB1_FFDB29_Msk               (0x1U << CAN_F13FB1_FFDB29_Pos)         /*!< 0x20000000 */
#define CAN_F13FB1_FFDB29                   CAN_F13FB1_FFDB29_Msk                   /*!< Filter data bit 29 */
#define CAN_F13FB1_FFDB30_Pos               (30U)
#define CAN_F13FB1_FFDB30_Msk               (0x1U << CAN_F13FB1_FFDB30_Pos)         /*!< 0x40000000 */
#define CAN_F13FB1_FFDB30                   CAN_F13FB1_FFDB30_Msk                   /*!< Filter data bit 30 */
#define CAN_F13FB1_FFDB31_Pos               (31U)
#define CAN_F13FB1_FFDB31_Msk               (0x1U << CAN_F13FB1_FFDB31_Pos)         /*!< 0x80000000 */
#define CAN_F13FB1_FFDB31                   CAN_F13FB1_FFDB31_Msk                   /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F0FB2 register  *******************/
#define CAN_F0FB2_FFDB0_Pos                 (0U)
#define CAN_F0FB2_FFDB0_Msk                 (0x1U << CAN_F0FB2_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F0FB2_FFDB0                     CAN_F0FB2_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F0FB2_FFDB1_Pos                 (1U)
#define CAN_F0FB2_FFDB1_Msk                 (0x1U << CAN_F0FB2_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F0FB2_FFDB1                     CAN_F0FB2_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F0FB2_FFDB2_Pos                 (2U)
#define CAN_F0FB2_FFDB2_Msk                 (0x1U << CAN_F0FB2_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F0FB2_FFDB2                     CAN_F0FB2_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F0FB2_FFDB3_Pos                 (3U)
#define CAN_F0FB2_FFDB3_Msk                 (0x1U << CAN_F0FB2_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F0FB2_FFDB3                     CAN_F0FB2_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F0FB2_FFDB4_Pos                 (4U)
#define CAN_F0FB2_FFDB4_Msk                 (0x1U << CAN_F0FB2_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F0FB2_FFDB4                     CAN_F0FB2_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F0FB2_FFDB5_Pos                 (5U)
#define CAN_F0FB2_FFDB5_Msk                 (0x1U << CAN_F0FB2_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F0FB2_FFDB5                     CAN_F0FB2_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F0FB2_FFDB6_Pos                 (6U)
#define CAN_F0FB2_FFDB6_Msk                 (0x1U << CAN_F0FB2_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F0FB2_FFDB6                     CAN_F0FB2_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F0FB2_FFDB7_Pos                 (7U)
#define CAN_F0FB2_FFDB7_Msk                 (0x1U << CAN_F0FB2_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F0FB2_FFDB7                     CAN_F0FB2_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F0FB2_FFDB8_Pos                 (8U)
#define CAN_F0FB2_FFDB8_Msk                 (0x1U << CAN_F0FB2_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F0FB2_FFDB8                     CAN_F0FB2_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F0FB2_FFDB9_Pos                 (9U)
#define CAN_F0FB2_FFDB9_Msk                 (0x1U << CAN_F0FB2_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F0FB2_FFDB9                     CAN_F0FB2_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F0FB2_FFDB10_Pos                (10U)
#define CAN_F0FB2_FFDB10_Msk                (0x1U << CAN_F0FB2_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F0FB2_FFDB10                    CAN_F0FB2_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F0FB2_FFDB11_Pos                (11U)
#define CAN_F0FB2_FFDB11_Msk                (0x1U << CAN_F0FB2_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F0FB2_FFDB11                    CAN_F0FB2_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F0FB2_FFDB12_Pos                (12U)
#define CAN_F0FB2_FFDB12_Msk                (0x1U << CAN_F0FB2_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F0FB2_FFDB12                    CAN_F0FB2_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F0FB2_FFDB13_Pos                (13U)
#define CAN_F0FB2_FFDB13_Msk                (0x1U << CAN_F0FB2_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F0FB2_FFDB13                    CAN_F0FB2_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F0FB2_FFDB14_Pos                (14U)
#define CAN_F0FB2_FFDB14_Msk                (0x1U << CAN_F0FB2_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F0FB2_FFDB14                    CAN_F0FB2_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F0FB2_FFDB15_Pos                (15U)
#define CAN_F0FB2_FFDB15_Msk                (0x1U << CAN_F0FB2_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F0FB2_FFDB15                    CAN_F0FB2_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F0FB2_FFDB16_Pos                (16U)
#define CAN_F0FB2_FFDB16_Msk                (0x1U << CAN_F0FB2_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F0FB2_FFDB16                    CAN_F0FB2_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F0FB2_FFDB17_Pos                (17U)
#define CAN_F0FB2_FFDB17_Msk                (0x1U << CAN_F0FB2_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F0FB2_FFDB17                    CAN_F0FB2_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F0FB2_FFDB18_Pos                (18U)
#define CAN_F0FB2_FFDB18_Msk                (0x1U << CAN_F0FB2_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F0FB2_FFDB18                    CAN_F0FB2_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F0FB2_FFDB19_Pos                (19U)
#define CAN_F0FB2_FFDB19_Msk                (0x1U << CAN_F0FB2_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F0FB2_FFDB19                    CAN_F0FB2_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F0FB2_FFDB20_Pos                (20U)
#define CAN_F0FB2_FFDB20_Msk                (0x1U << CAN_F0FB2_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F0FB2_FFDB20                    CAN_F0FB2_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F0FB2_FFDB21_Pos                (21U)
#define CAN_F0FB2_FFDB21_Msk                (0x1U << CAN_F0FB2_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F0FB2_FFDB21                    CAN_F0FB2_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F0FB2_FFDB22_Pos                (22U)
#define CAN_F0FB2_FFDB22_Msk                (0x1U << CAN_F0FB2_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F0FB2_FFDB22                    CAN_F0FB2_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F0FB2_FFDB23_Pos                (23U)
#define CAN_F0FB2_FFDB23_Msk                (0x1U << CAN_F0FB2_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F0FB2_FFDB23                    CAN_F0FB2_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F0FB2_FFDB24_Pos                (24U)
#define CAN_F0FB2_FFDB24_Msk                (0x1U << CAN_F0FB2_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F0FB2_FFDB24                    CAN_F0FB2_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F0FB2_FFDB25_Pos                (25U)
#define CAN_F0FB2_FFDB25_Msk                (0x1U << CAN_F0FB2_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F0FB2_FFDB25                    CAN_F0FB2_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F0FB2_FFDB26_Pos                (26U)
#define CAN_F0FB2_FFDB26_Msk                (0x1U << CAN_F0FB2_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F0FB2_FFDB26                    CAN_F0FB2_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F0FB2_FFDB27_Pos                (27U)
#define CAN_F0FB2_FFDB27_Msk                (0x1U << CAN_F0FB2_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F0FB2_FFDB27                    CAN_F0FB2_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F0FB2_FFDB28_Pos                (28U)
#define CAN_F0FB2_FFDB28_Msk                (0x1U << CAN_F0FB2_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F0FB2_FFDB28                    CAN_F0FB2_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F0FB2_FFDB29_Pos                (29U)
#define CAN_F0FB2_FFDB29_Msk                (0x1U << CAN_F0FB2_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F0FB2_FFDB29                    CAN_F0FB2_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F0FB2_FFDB30_Pos                (30U)
#define CAN_F0FB2_FFDB30_Msk                (0x1U << CAN_F0FB2_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F0FB2_FFDB30                    CAN_F0FB2_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F0FB2_FFDB31_Pos                (31U)
#define CAN_F0FB2_FFDB31_Msk                (0x1U << CAN_F0FB2_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F0FB2_FFDB31                    CAN_F0FB2_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F1FB2 register  *******************/
#define CAN_F1FB2_FFDB0_Pos                 (0U)
#define CAN_F1FB2_FFDB0_Msk                 (0x1U << CAN_F1FB2_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F1FB2_FFDB0                     CAN_F1FB2_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F1FB2_FFDB1_Pos                 (1U)
#define CAN_F1FB2_FFDB1_Msk                 (0x1U << CAN_F1FB2_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F1FB2_FFDB1                     CAN_F1FB2_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F1FB2_FFDB2_Pos                 (2U)
#define CAN_F1FB2_FFDB2_Msk                 (0x1U << CAN_F1FB2_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F1FB2_FFDB2                     CAN_F1FB2_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F1FB2_FFDB3_Pos                 (3U)
#define CAN_F1FB2_FFDB3_Msk                 (0x1U << CAN_F1FB2_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F1FB2_FFDB3                     CAN_F1FB2_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F1FB2_FFDB4_Pos                 (4U)
#define CAN_F1FB2_FFDB4_Msk                 (0x1U << CAN_F1FB2_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F1FB2_FFDB4                     CAN_F1FB2_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F1FB2_FFDB5_Pos                 (5U)
#define CAN_F1FB2_FFDB5_Msk                 (0x1U << CAN_F1FB2_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F1FB2_FFDB5                     CAN_F1FB2_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F1FB2_FFDB6_Pos                 (6U)
#define CAN_F1FB2_FFDB6_Msk                 (0x1U << CAN_F1FB2_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F1FB2_FFDB6                     CAN_F1FB2_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F1FB2_FFDB7_Pos                 (7U)
#define CAN_F1FB2_FFDB7_Msk                 (0x1U << CAN_F1FB2_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F1FB2_FFDB7                     CAN_F1FB2_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F1FB2_FFDB8_Pos                 (8U)
#define CAN_F1FB2_FFDB8_Msk                 (0x1U << CAN_F1FB2_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F1FB2_FFDB8                     CAN_F1FB2_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F1FB2_FFDB9_Pos                 (9U)
#define CAN_F1FB2_FFDB9_Msk                 (0x1U << CAN_F1FB2_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F1FB2_FFDB9                     CAN_F1FB2_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F1FB2_FFDB10_Pos                (10U)
#define CAN_F1FB2_FFDB10_Msk                (0x1U << CAN_F1FB2_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F1FB2_FFDB10                    CAN_F1FB2_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F1FB2_FFDB11_Pos                (11U)
#define CAN_F1FB2_FFDB11_Msk                (0x1U << CAN_F1FB2_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F1FB2_FFDB11                    CAN_F1FB2_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F1FB2_FFDB12_Pos                (12U)
#define CAN_F1FB2_FFDB12_Msk                (0x1U << CAN_F1FB2_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F1FB2_FFDB12                    CAN_F1FB2_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F1FB2_FFDB13_Pos                (13U)
#define CAN_F1FB2_FFDB13_Msk                (0x1U << CAN_F1FB2_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F1FB2_FFDB13                    CAN_F1FB2_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F1FB2_FFDB14_Pos                (14U)
#define CAN_F1FB2_FFDB14_Msk                (0x1U << CAN_F1FB2_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F1FB2_FFDB14                    CAN_F1FB2_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F1FB2_FFDB15_Pos                (15U)
#define CAN_F1FB2_FFDB15_Msk                (0x1U << CAN_F1FB2_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F1FB2_FFDB15                    CAN_F1FB2_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F1FB2_FFDB16_Pos                (16U)
#define CAN_F1FB2_FFDB16_Msk                (0x1U << CAN_F1FB2_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F1FB2_FFDB16                    CAN_F1FB2_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F1FB2_FFDB17_Pos                (17U)
#define CAN_F1FB2_FFDB17_Msk                (0x1U << CAN_F1FB2_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F1FB2_FFDB17                    CAN_F1FB2_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F1FB2_FFDB18_Pos                (18U)
#define CAN_F1FB2_FFDB18_Msk                (0x1U << CAN_F1FB2_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F1FB2_FFDB18                    CAN_F1FB2_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F1FB2_FFDB19_Pos                (19U)
#define CAN_F1FB2_FFDB19_Msk                (0x1U << CAN_F1FB2_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F1FB2_FFDB19                    CAN_F1FB2_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F1FB2_FFDB20_Pos                (20U)
#define CAN_F1FB2_FFDB20_Msk                (0x1U << CAN_F1FB2_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F1FB2_FFDB20                    CAN_F1FB2_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F1FB2_FFDB21_Pos                (21U)
#define CAN_F1FB2_FFDB21_Msk                (0x1U << CAN_F1FB2_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F1FB2_FFDB21                    CAN_F1FB2_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F1FB2_FFDB22_Pos                (22U)
#define CAN_F1FB2_FFDB22_Msk                (0x1U << CAN_F1FB2_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F1FB2_FFDB22                    CAN_F1FB2_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F1FB2_FFDB23_Pos                (23U)
#define CAN_F1FB2_FFDB23_Msk                (0x1U << CAN_F1FB2_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F1FB2_FFDB23                    CAN_F1FB2_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F1FB2_FFDB24_Pos                (24U)
#define CAN_F1FB2_FFDB24_Msk                (0x1U << CAN_F1FB2_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F1FB2_FFDB24                    CAN_F1FB2_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F1FB2_FFDB25_Pos                (25U)
#define CAN_F1FB2_FFDB25_Msk                (0x1U << CAN_F1FB2_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F1FB2_FFDB25                    CAN_F1FB2_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F1FB2_FFDB26_Pos                (26U)
#define CAN_F1FB2_FFDB26_Msk                (0x1U << CAN_F1FB2_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F1FB2_FFDB26                    CAN_F1FB2_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F1FB2_FFDB27_Pos                (27U)
#define CAN_F1FB2_FFDB27_Msk                (0x1U << CAN_F1FB2_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F1FB2_FFDB27                    CAN_F1FB2_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F1FB2_FFDB28_Pos                (28U)
#define CAN_F1FB2_FFDB28_Msk                (0x1U << CAN_F1FB2_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F1FB2_FFDB28                    CAN_F1FB2_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F1FB2_FFDB29_Pos                (29U)
#define CAN_F1FB2_FFDB29_Msk                (0x1U << CAN_F1FB2_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F1FB2_FFDB29                    CAN_F1FB2_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F1FB2_FFDB30_Pos                (30U)
#define CAN_F1FB2_FFDB30_Msk                (0x1U << CAN_F1FB2_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F1FB2_FFDB30                    CAN_F1FB2_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F1FB2_FFDB31_Pos                (31U)
#define CAN_F1FB2_FFDB31_Msk                (0x1U << CAN_F1FB2_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F1FB2_FFDB31                    CAN_F1FB2_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F2FB2 register  *******************/
#define CAN_F2FB2_FFDB0_Pos                 (0U)
#define CAN_F2FB2_FFDB0_Msk                 (0x1U << CAN_F2FB2_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F2FB2_FFDB0                     CAN_F2FB2_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F2FB2_FFDB1_Pos                 (1U)
#define CAN_F2FB2_FFDB1_Msk                 (0x1U << CAN_F2FB2_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F2FB2_FFDB1                     CAN_F2FB2_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F2FB2_FFDB2_Pos                 (2U)
#define CAN_F2FB2_FFDB2_Msk                 (0x1U << CAN_F2FB2_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F2FB2_FFDB2                     CAN_F2FB2_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F2FB2_FFDB3_Pos                 (3U)
#define CAN_F2FB2_FFDB3_Msk                 (0x1U << CAN_F2FB2_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F2FB2_FFDB3                     CAN_F2FB2_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F2FB2_FFDB4_Pos                 (4U)
#define CAN_F2FB2_FFDB4_Msk                 (0x1U << CAN_F2FB2_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F2FB2_FFDB4                     CAN_F2FB2_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F2FB2_FFDB5_Pos                 (5U)
#define CAN_F2FB2_FFDB5_Msk                 (0x1U << CAN_F2FB2_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F2FB2_FFDB5                     CAN_F2FB2_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F2FB2_FFDB6_Pos                 (6U)
#define CAN_F2FB2_FFDB6_Msk                 (0x1U << CAN_F2FB2_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F2FB2_FFDB6                     CAN_F2FB2_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F2FB2_FFDB7_Pos                 (7U)
#define CAN_F2FB2_FFDB7_Msk                 (0x1U << CAN_F2FB2_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F2FB2_FFDB7                     CAN_F2FB2_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F2FB2_FFDB8_Pos                 (8U)
#define CAN_F2FB2_FFDB8_Msk                 (0x1U << CAN_F2FB2_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F2FB2_FFDB8                     CAN_F2FB2_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F2FB2_FFDB9_Pos                 (9U)
#define CAN_F2FB2_FFDB9_Msk                 (0x1U << CAN_F2FB2_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F2FB2_FFDB9                     CAN_F2FB2_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F2FB2_FFDB10_Pos                (10U)
#define CAN_F2FB2_FFDB10_Msk                (0x1U << CAN_F2FB2_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F2FB2_FFDB10                    CAN_F2FB2_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F2FB2_FFDB11_Pos                (11U)
#define CAN_F2FB2_FFDB11_Msk                (0x1U << CAN_F2FB2_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F2FB2_FFDB11                    CAN_F2FB2_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F2FB2_FFDB12_Pos                (12U)
#define CAN_F2FB2_FFDB12_Msk                (0x1U << CAN_F2FB2_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F2FB2_FFDB12                    CAN_F2FB2_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F2FB2_FFDB13_Pos                (13U)
#define CAN_F2FB2_FFDB13_Msk                (0x1U << CAN_F2FB2_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F2FB2_FFDB13                    CAN_F2FB2_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F2FB2_FFDB14_Pos                (14U)
#define CAN_F2FB2_FFDB14_Msk                (0x1U << CAN_F2FB2_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F2FB2_FFDB14                    CAN_F2FB2_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F2FB2_FFDB15_Pos                (15U)
#define CAN_F2FB2_FFDB15_Msk                (0x1U << CAN_F2FB2_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F2FB2_FFDB15                    CAN_F2FB2_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F2FB2_FFDB16_Pos                (16U)
#define CAN_F2FB2_FFDB16_Msk                (0x1U << CAN_F2FB2_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F2FB2_FFDB16                    CAN_F2FB2_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F2FB2_FFDB17_Pos                (17U)
#define CAN_F2FB2_FFDB17_Msk                (0x1U << CAN_F2FB2_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F2FB2_FFDB17                    CAN_F2FB2_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F2FB2_FFDB18_Pos                (18U)
#define CAN_F2FB2_FFDB18_Msk                (0x1U << CAN_F2FB2_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F2FB2_FFDB18                    CAN_F2FB2_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F2FB2_FFDB19_Pos                (19U)
#define CAN_F2FB2_FFDB19_Msk                (0x1U << CAN_F2FB2_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F2FB2_FFDB19                    CAN_F2FB2_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F2FB2_FFDB20_Pos                (20U)
#define CAN_F2FB2_FFDB20_Msk                (0x1U << CAN_F2FB2_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F2FB2_FFDB20                    CAN_F2FB2_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F2FB2_FFDB21_Pos                (21U)
#define CAN_F2FB2_FFDB21_Msk                (0x1U << CAN_F2FB2_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F2FB2_FFDB21                    CAN_F2FB2_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F2FB2_FFDB22_Pos                (22U)
#define CAN_F2FB2_FFDB22_Msk                (0x1U << CAN_F2FB2_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F2FB2_FFDB22                    CAN_F2FB2_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F2FB2_FFDB23_Pos                (23U)
#define CAN_F2FB2_FFDB23_Msk                (0x1U << CAN_F2FB2_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F2FB2_FFDB23                    CAN_F2FB2_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F2FB2_FFDB24_Pos                (24U)
#define CAN_F2FB2_FFDB24_Msk                (0x1U << CAN_F2FB2_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F2FB2_FFDB24                    CAN_F2FB2_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F2FB2_FFDB25_Pos                (25U)
#define CAN_F2FB2_FFDB25_Msk                (0x1U << CAN_F2FB2_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F2FB2_FFDB25                    CAN_F2FB2_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F2FB2_FFDB26_Pos                (26U)
#define CAN_F2FB2_FFDB26_Msk                (0x1U << CAN_F2FB2_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F2FB2_FFDB26                    CAN_F2FB2_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F2FB2_FFDB27_Pos                (27U)
#define CAN_F2FB2_FFDB27_Msk                (0x1U << CAN_F2FB2_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F2FB2_FFDB27                    CAN_F2FB2_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F2FB2_FFDB28_Pos                (28U)
#define CAN_F2FB2_FFDB28_Msk                (0x1U << CAN_F2FB2_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F2FB2_FFDB28                    CAN_F2FB2_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F2FB2_FFDB29_Pos                (29U)
#define CAN_F2FB2_FFDB29_Msk                (0x1U << CAN_F2FB2_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F2FB2_FFDB29                    CAN_F2FB2_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F2FB2_FFDB30_Pos                (30U)
#define CAN_F2FB2_FFDB30_Msk                (0x1U << CAN_F2FB2_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F2FB2_FFDB30                    CAN_F2FB2_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F2FB2_FFDB31_Pos                (31U)
#define CAN_F2FB2_FFDB31_Msk                (0x1U << CAN_F2FB2_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F2FB2_FFDB31                    CAN_F2FB2_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F3FB2 register  *******************/
#define CAN_F3FB2_FFDB0_Pos                 (0U)
#define CAN_F3FB2_FFDB0_Msk                 (0x1U << CAN_F3FB2_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F3FB2_FFDB0                     CAN_F3FB2_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F3FB2_FFDB1_Pos                 (1U)
#define CAN_F3FB2_FFDB1_Msk                 (0x1U << CAN_F3FB2_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F3FB2_FFDB1                     CAN_F3FB2_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F3FB2_FFDB2_Pos                 (2U)
#define CAN_F3FB2_FFDB2_Msk                 (0x1U << CAN_F3FB2_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F3FB2_FFDB2                     CAN_F3FB2_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F3FB2_FFDB3_Pos                 (3U)
#define CAN_F3FB2_FFDB3_Msk                 (0x1U << CAN_F3FB2_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F3FB2_FFDB3                     CAN_F3FB2_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F3FB2_FFDB4_Pos                 (4U)
#define CAN_F3FB2_FFDB4_Msk                 (0x1U << CAN_F3FB2_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F3FB2_FFDB4                     CAN_F3FB2_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F3FB2_FFDB5_Pos                 (5U)
#define CAN_F3FB2_FFDB5_Msk                 (0x1U << CAN_F3FB2_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F3FB2_FFDB5                     CAN_F3FB2_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F3FB2_FFDB6_Pos                 (6U)
#define CAN_F3FB2_FFDB6_Msk                 (0x1U << CAN_F3FB2_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F3FB2_FFDB6                     CAN_F3FB2_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F3FB2_FFDB7_Pos                 (7U)
#define CAN_F3FB2_FFDB7_Msk                 (0x1U << CAN_F3FB2_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F3FB2_FFDB7                     CAN_F3FB2_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F3FB2_FFDB8_Pos                 (8U)
#define CAN_F3FB2_FFDB8_Msk                 (0x1U << CAN_F3FB2_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F3FB2_FFDB8                     CAN_F3FB2_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F3FB2_FFDB9_Pos                 (9U)
#define CAN_F3FB2_FFDB9_Msk                 (0x1U << CAN_F3FB2_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F3FB2_FFDB9                     CAN_F3FB2_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F3FB2_FFDB10_Pos                (10U)
#define CAN_F3FB2_FFDB10_Msk                (0x1U << CAN_F3FB2_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F3FB2_FFDB10                    CAN_F3FB2_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F3FB2_FFDB11_Pos                (11U)
#define CAN_F3FB2_FFDB11_Msk                (0x1U << CAN_F3FB2_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F3FB2_FFDB11                    CAN_F3FB2_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F3FB2_FFDB12_Pos                (12U)
#define CAN_F3FB2_FFDB12_Msk                (0x1U << CAN_F3FB2_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F3FB2_FFDB12                    CAN_F3FB2_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F3FB2_FFDB13_Pos                (13U)
#define CAN_F3FB2_FFDB13_Msk                (0x1U << CAN_F3FB2_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F3FB2_FFDB13                    CAN_F3FB2_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F3FB2_FFDB14_Pos                (14U)
#define CAN_F3FB2_FFDB14_Msk                (0x1U << CAN_F3FB2_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F3FB2_FFDB14                    CAN_F3FB2_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F3FB2_FFDB15_Pos                (15U)
#define CAN_F3FB2_FFDB15_Msk                (0x1U << CAN_F3FB2_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F3FB2_FFDB15                    CAN_F3FB2_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F3FB2_FFDB16_Pos                (16U)
#define CAN_F3FB2_FFDB16_Msk                (0x1U << CAN_F3FB2_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F3FB2_FFDB16                    CAN_F3FB2_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F3FB2_FFDB17_Pos                (17U)
#define CAN_F3FB2_FFDB17_Msk                (0x1U << CAN_F3FB2_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F3FB2_FFDB17                    CAN_F3FB2_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F3FB2_FFDB18_Pos                (18U)
#define CAN_F3FB2_FFDB18_Msk                (0x1U << CAN_F3FB2_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F3FB2_FFDB18                    CAN_F3FB2_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F3FB2_FFDB19_Pos                (19U)
#define CAN_F3FB2_FFDB19_Msk                (0x1U << CAN_F3FB2_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F3FB2_FFDB19                    CAN_F3FB2_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F3FB2_FFDB20_Pos                (20U)
#define CAN_F3FB2_FFDB20_Msk                (0x1U << CAN_F3FB2_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F3FB2_FFDB20                    CAN_F3FB2_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F3FB2_FFDB21_Pos                (21U)
#define CAN_F3FB2_FFDB21_Msk                (0x1U << CAN_F3FB2_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F3FB2_FFDB21                    CAN_F3FB2_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F3FB2_FFDB22_Pos                (22U)
#define CAN_F3FB2_FFDB22_Msk                (0x1U << CAN_F3FB2_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F3FB2_FFDB22                    CAN_F3FB2_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F3FB2_FFDB23_Pos                (23U)
#define CAN_F3FB2_FFDB23_Msk                (0x1U << CAN_F3FB2_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F3FB2_FFDB23                    CAN_F3FB2_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F3FB2_FFDB24_Pos                (24U)
#define CAN_F3FB2_FFDB24_Msk                (0x1U << CAN_F3FB2_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F3FB2_FFDB24                    CAN_F3FB2_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F3FB2_FFDB25_Pos                (25U)
#define CAN_F3FB2_FFDB25_Msk                (0x1U << CAN_F3FB2_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F3FB2_FFDB25                    CAN_F3FB2_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F3FB2_FFDB26_Pos                (26U)
#define CAN_F3FB2_FFDB26_Msk                (0x1U << CAN_F3FB2_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F3FB2_FFDB26                    CAN_F3FB2_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F3FB2_FFDB27_Pos                (27U)
#define CAN_F3FB2_FFDB27_Msk                (0x1U << CAN_F3FB2_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F3FB2_FFDB27                    CAN_F3FB2_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F3FB2_FFDB28_Pos                (28U)
#define CAN_F3FB2_FFDB28_Msk                (0x1U << CAN_F3FB2_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F3FB2_FFDB28                    CAN_F3FB2_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F3FB2_FFDB29_Pos                (29U)
#define CAN_F3FB2_FFDB29_Msk                (0x1U << CAN_F3FB2_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F3FB2_FFDB29                    CAN_F3FB2_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F3FB2_FFDB30_Pos                (30U)
#define CAN_F3FB2_FFDB30_Msk                (0x1U << CAN_F3FB2_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F3FB2_FFDB30                    CAN_F3FB2_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F3FB2_FFDB31_Pos                (31U)
#define CAN_F3FB2_FFDB31_Msk                (0x1U << CAN_F3FB2_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F3FB2_FFDB31                    CAN_F3FB2_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F4FB2 register  *******************/
#define CAN_F4FB2_FFDB0_Pos                 (0U)
#define CAN_F4FB2_FFDB0_Msk                 (0x1U << CAN_F4FB2_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F4FB2_FFDB0                     CAN_F4FB2_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F4FB2_FFDB1_Pos                 (1U)
#define CAN_F4FB2_FFDB1_Msk                 (0x1U << CAN_F4FB2_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F4FB2_FFDB1                     CAN_F4FB2_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F4FB2_FFDB2_Pos                 (2U)
#define CAN_F4FB2_FFDB2_Msk                 (0x1U << CAN_F4FB2_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F4FB2_FFDB2                     CAN_F4FB2_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F4FB2_FFDB3_Pos                 (3U)
#define CAN_F4FB2_FFDB3_Msk                 (0x1U << CAN_F4FB2_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F4FB2_FFDB3                     CAN_F4FB2_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F4FB2_FFDB4_Pos                 (4U)
#define CAN_F4FB2_FFDB4_Msk                 (0x1U << CAN_F4FB2_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F4FB2_FFDB4                     CAN_F4FB2_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F4FB2_FFDB5_Pos                 (5U)
#define CAN_F4FB2_FFDB5_Msk                 (0x1U << CAN_F4FB2_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F4FB2_FFDB5                     CAN_F4FB2_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F4FB2_FFDB6_Pos                 (6U)
#define CAN_F4FB2_FFDB6_Msk                 (0x1U << CAN_F4FB2_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F4FB2_FFDB6                     CAN_F4FB2_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F4FB2_FFDB7_Pos                 (7U)
#define CAN_F4FB2_FFDB7_Msk                 (0x1U << CAN_F4FB2_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F4FB2_FFDB7                     CAN_F4FB2_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F4FB2_FFDB8_Pos                 (8U)
#define CAN_F4FB2_FFDB8_Msk                 (0x1U << CAN_F4FB2_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F4FB2_FFDB8                     CAN_F4FB2_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F4FB2_FFDB9_Pos                 (9U)
#define CAN_F4FB2_FFDB9_Msk                 (0x1U << CAN_F4FB2_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F4FB2_FFDB9                     CAN_F4FB2_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F4FB2_FFDB10_Pos                (10U)
#define CAN_F4FB2_FFDB10_Msk                (0x1U << CAN_F4FB2_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F4FB2_FFDB10                    CAN_F4FB2_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F4FB2_FFDB11_Pos                (11U)
#define CAN_F4FB2_FFDB11_Msk                (0x1U << CAN_F4FB2_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F4FB2_FFDB11                    CAN_F4FB2_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F4FB2_FFDB12_Pos                (12U)
#define CAN_F4FB2_FFDB12_Msk                (0x1U << CAN_F4FB2_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F4FB2_FFDB12                    CAN_F4FB2_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F4FB2_FFDB13_Pos                (13U)
#define CAN_F4FB2_FFDB13_Msk                (0x1U << CAN_F4FB2_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F4FB2_FFDB13                    CAN_F4FB2_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F4FB2_FFDB14_Pos                (14U)
#define CAN_F4FB2_FFDB14_Msk                (0x1U << CAN_F4FB2_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F4FB2_FFDB14                    CAN_F4FB2_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F4FB2_FFDB15_Pos                (15U)
#define CAN_F4FB2_FFDB15_Msk                (0x1U << CAN_F4FB2_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F4FB2_FFDB15                    CAN_F4FB2_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F4FB2_FFDB16_Pos                (16U)
#define CAN_F4FB2_FFDB16_Msk                (0x1U << CAN_F4FB2_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F4FB2_FFDB16                    CAN_F4FB2_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F4FB2_FFDB17_Pos                (17U)
#define CAN_F4FB2_FFDB17_Msk                (0x1U << CAN_F4FB2_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F4FB2_FFDB17                    CAN_F4FB2_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F4FB2_FFDB18_Pos                (18U)
#define CAN_F4FB2_FFDB18_Msk                (0x1U << CAN_F4FB2_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F4FB2_FFDB18                    CAN_F4FB2_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F4FB2_FFDB19_Pos                (19U)
#define CAN_F4FB2_FFDB19_Msk                (0x1U << CAN_F4FB2_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F4FB2_FFDB19                    CAN_F4FB2_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F4FB2_FFDB20_Pos                (20U)
#define CAN_F4FB2_FFDB20_Msk                (0x1U << CAN_F4FB2_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F4FB2_FFDB20                    CAN_F4FB2_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F4FB2_FFDB21_Pos                (21U)
#define CAN_F4FB2_FFDB21_Msk                (0x1U << CAN_F4FB2_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F4FB2_FFDB21                    CAN_F4FB2_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F4FB2_FFDB22_Pos                (22U)
#define CAN_F4FB2_FFDB22_Msk                (0x1U << CAN_F4FB2_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F4FB2_FFDB22                    CAN_F4FB2_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F4FB2_FFDB23_Pos                (23U)
#define CAN_F4FB2_FFDB23_Msk                (0x1U << CAN_F4FB2_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F4FB2_FFDB23                    CAN_F4FB2_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F4FB2_FFDB24_Pos                (24U)
#define CAN_F4FB2_FFDB24_Msk                (0x1U << CAN_F4FB2_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F4FB2_FFDB24                    CAN_F4FB2_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F4FB2_FFDB25_Pos                (25U)
#define CAN_F4FB2_FFDB25_Msk                (0x1U << CAN_F4FB2_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F4FB2_FFDB25                    CAN_F4FB2_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F4FB2_FFDB26_Pos                (26U)
#define CAN_F4FB2_FFDB26_Msk                (0x1U << CAN_F4FB2_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F4FB2_FFDB26                    CAN_F4FB2_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F4FB2_FFDB27_Pos                (27U)
#define CAN_F4FB2_FFDB27_Msk                (0x1U << CAN_F4FB2_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F4FB2_FFDB27                    CAN_F4FB2_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F4FB2_FFDB28_Pos                (28U)
#define CAN_F4FB2_FFDB28_Msk                (0x1U << CAN_F4FB2_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F4FB2_FFDB28                    CAN_F4FB2_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F4FB2_FFDB29_Pos                (29U)
#define CAN_F4FB2_FFDB29_Msk                (0x1U << CAN_F4FB2_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F4FB2_FFDB29                    CAN_F4FB2_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F4FB2_FFDB30_Pos                (30U)
#define CAN_F4FB2_FFDB30_Msk                (0x1U << CAN_F4FB2_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F4FB2_FFDB30                    CAN_F4FB2_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F4FB2_FFDB31_Pos                (31U)
#define CAN_F4FB2_FFDB31_Msk                (0x1U << CAN_F4FB2_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F4FB2_FFDB31                    CAN_F4FB2_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F5FB2 register  *******************/
#define CAN_F5FB2_FFDB0_Pos                 (0U)
#define CAN_F5FB2_FFDB0_Msk                 (0x1U << CAN_F5FB2_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F5FB2_FFDB0                     CAN_F5FB2_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F5FB2_FFDB1_Pos                 (1U)
#define CAN_F5FB2_FFDB1_Msk                 (0x1U << CAN_F5FB2_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F5FB2_FFDB1                     CAN_F5FB2_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F5FB2_FFDB2_Pos                 (2U)
#define CAN_F5FB2_FFDB2_Msk                 (0x1U << CAN_F5FB2_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F5FB2_FFDB2                     CAN_F5FB2_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F5FB2_FFDB3_Pos                 (3U)
#define CAN_F5FB2_FFDB3_Msk                 (0x1U << CAN_F5FB2_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F5FB2_FFDB3                     CAN_F5FB2_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F5FB2_FFDB4_Pos                 (4U)
#define CAN_F5FB2_FFDB4_Msk                 (0x1U << CAN_F5FB2_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F5FB2_FFDB4                     CAN_F5FB2_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F5FB2_FFDB5_Pos                 (5U)
#define CAN_F5FB2_FFDB5_Msk                 (0x1U << CAN_F5FB2_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F5FB2_FFDB5                     CAN_F5FB2_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F5FB2_FFDB6_Pos                 (6U)
#define CAN_F5FB2_FFDB6_Msk                 (0x1U << CAN_F5FB2_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F5FB2_FFDB6                     CAN_F5FB2_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F5FB2_FFDB7_Pos                 (7U)
#define CAN_F5FB2_FFDB7_Msk                 (0x1U << CAN_F5FB2_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F5FB2_FFDB7                     CAN_F5FB2_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F5FB2_FFDB8_Pos                 (8U)
#define CAN_F5FB2_FFDB8_Msk                 (0x1U << CAN_F5FB2_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F5FB2_FFDB8                     CAN_F5FB2_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F5FB2_FFDB9_Pos                 (9U)
#define CAN_F5FB2_FFDB9_Msk                 (0x1U << CAN_F5FB2_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F5FB2_FFDB9                     CAN_F5FB2_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F5FB2_FFDB10_Pos                (10U)
#define CAN_F5FB2_FFDB10_Msk                (0x1U << CAN_F5FB2_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F5FB2_FFDB10                    CAN_F5FB2_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F5FB2_FFDB11_Pos                (11U)
#define CAN_F5FB2_FFDB11_Msk                (0x1U << CAN_F5FB2_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F5FB2_FFDB11                    CAN_F5FB2_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F5FB2_FFDB12_Pos                (12U)
#define CAN_F5FB2_FFDB12_Msk                (0x1U << CAN_F5FB2_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F5FB2_FFDB12                    CAN_F5FB2_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F5FB2_FFDB13_Pos                (13U)
#define CAN_F5FB2_FFDB13_Msk                (0x1U << CAN_F5FB2_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F5FB2_FFDB13                    CAN_F5FB2_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F5FB2_FFDB14_Pos                (14U)
#define CAN_F5FB2_FFDB14_Msk                (0x1U << CAN_F5FB2_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F5FB2_FFDB14                    CAN_F5FB2_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F5FB2_FFDB15_Pos                (15U)
#define CAN_F5FB2_FFDB15_Msk                (0x1U << CAN_F5FB2_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F5FB2_FFDB15                    CAN_F5FB2_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F5FB2_FFDB16_Pos                (16U)
#define CAN_F5FB2_FFDB16_Msk                (0x1U << CAN_F5FB2_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F5FB2_FFDB16                    CAN_F5FB2_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F5FB2_FFDB17_Pos                (17U)
#define CAN_F5FB2_FFDB17_Msk                (0x1U << CAN_F5FB2_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F5FB2_FFDB17                    CAN_F5FB2_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F5FB2_FFDB18_Pos                (18U)
#define CAN_F5FB2_FFDB18_Msk                (0x1U << CAN_F5FB2_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F5FB2_FFDB18                    CAN_F5FB2_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F5FB2_FFDB19_Pos                (19U)
#define CAN_F5FB2_FFDB19_Msk                (0x1U << CAN_F5FB2_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F5FB2_FFDB19                    CAN_F5FB2_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F5FB2_FFDB20_Pos                (20U)
#define CAN_F5FB2_FFDB20_Msk                (0x1U << CAN_F5FB2_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F5FB2_FFDB20                    CAN_F5FB2_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F5FB2_FFDB21_Pos                (21U)
#define CAN_F5FB2_FFDB21_Msk                (0x1U << CAN_F5FB2_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F5FB2_FFDB21                    CAN_F5FB2_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F5FB2_FFDB22_Pos                (22U)
#define CAN_F5FB2_FFDB22_Msk                (0x1U << CAN_F5FB2_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F5FB2_FFDB22                    CAN_F5FB2_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F5FB2_FFDB23_Pos                (23U)
#define CAN_F5FB2_FFDB23_Msk                (0x1U << CAN_F5FB2_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F5FB2_FFDB23                    CAN_F5FB2_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F5FB2_FFDB24_Pos                (24U)
#define CAN_F5FB2_FFDB24_Msk                (0x1U << CAN_F5FB2_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F5FB2_FFDB24                    CAN_F5FB2_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F5FB2_FFDB25_Pos                (25U)
#define CAN_F5FB2_FFDB25_Msk                (0x1U << CAN_F5FB2_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F5FB2_FFDB25                    CAN_F5FB2_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F5FB2_FFDB26_Pos                (26U)
#define CAN_F5FB2_FFDB26_Msk                (0x1U << CAN_F5FB2_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F5FB2_FFDB26                    CAN_F5FB2_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F5FB2_FFDB27_Pos                (27U)
#define CAN_F5FB2_FFDB27_Msk                (0x1U << CAN_F5FB2_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F5FB2_FFDB27                    CAN_F5FB2_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F5FB2_FFDB28_Pos                (28U)
#define CAN_F5FB2_FFDB28_Msk                (0x1U << CAN_F5FB2_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F5FB2_FFDB28                    CAN_F5FB2_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F5FB2_FFDB29_Pos                (29U)
#define CAN_F5FB2_FFDB29_Msk                (0x1U << CAN_F5FB2_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F5FB2_FFDB29                    CAN_F5FB2_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F5FB2_FFDB30_Pos                (30U)
#define CAN_F5FB2_FFDB30_Msk                (0x1U << CAN_F5FB2_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F5FB2_FFDB30                    CAN_F5FB2_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F5FB2_FFDB31_Pos                (31U)
#define CAN_F5FB2_FFDB31_Msk                (0x1U << CAN_F5FB2_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F5FB2_FFDB31                    CAN_F5FB2_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F6FB2 register  *******************/
#define CAN_F6FB2_FFDB0_Pos                 (0U)
#define CAN_F6FB2_FFDB0_Msk                 (0x1U << CAN_F6FB2_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F6FB2_FFDB0                     CAN_F6FB2_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F6FB2_FFDB1_Pos                 (1U)
#define CAN_F6FB2_FFDB1_Msk                 (0x1U << CAN_F6FB2_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F6FB2_FFDB1                     CAN_F6FB2_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F6FB2_FFDB2_Pos                 (2U)
#define CAN_F6FB2_FFDB2_Msk                 (0x1U << CAN_F6FB2_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F6FB2_FFDB2                     CAN_F6FB2_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F6FB2_FFDB3_Pos                 (3U)
#define CAN_F6FB2_FFDB3_Msk                 (0x1U << CAN_F6FB2_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F6FB2_FFDB3                     CAN_F6FB2_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F6FB2_FFDB4_Pos                 (4U)
#define CAN_F6FB2_FFDB4_Msk                 (0x1U << CAN_F6FB2_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F6FB2_FFDB4                     CAN_F6FB2_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F6FB2_FFDB5_Pos                 (5U)
#define CAN_F6FB2_FFDB5_Msk                 (0x1U << CAN_F6FB2_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F6FB2_FFDB5                     CAN_F6FB2_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F6FB2_FFDB6_Pos                 (6U)
#define CAN_F6FB2_FFDB6_Msk                 (0x1U << CAN_F6FB2_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F6FB2_FFDB6                     CAN_F6FB2_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F6FB2_FFDB7_Pos                 (7U)
#define CAN_F6FB2_FFDB7_Msk                 (0x1U << CAN_F6FB2_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F6FB2_FFDB7                     CAN_F6FB2_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F6FB2_FFDB8_Pos                 (8U)
#define CAN_F6FB2_FFDB8_Msk                 (0x1U << CAN_F6FB2_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F6FB2_FFDB8                     CAN_F6FB2_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F6FB2_FFDB9_Pos                 (9U)
#define CAN_F6FB2_FFDB9_Msk                 (0x1U << CAN_F6FB2_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F6FB2_FFDB9                     CAN_F6FB2_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F6FB2_FFDB10_Pos                (10U)
#define CAN_F6FB2_FFDB10_Msk                (0x1U << CAN_F6FB2_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F6FB2_FFDB10                    CAN_F6FB2_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F6FB2_FFDB11_Pos                (11U)
#define CAN_F6FB2_FFDB11_Msk                (0x1U << CAN_F6FB2_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F6FB2_FFDB11                    CAN_F6FB2_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F6FB2_FFDB12_Pos                (12U)
#define CAN_F6FB2_FFDB12_Msk                (0x1U << CAN_F6FB2_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F6FB2_FFDB12                    CAN_F6FB2_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F6FB2_FFDB13_Pos                (13U)
#define CAN_F6FB2_FFDB13_Msk                (0x1U << CAN_F6FB2_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F6FB2_FFDB13                    CAN_F6FB2_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F6FB2_FFDB14_Pos                (14U)
#define CAN_F6FB2_FFDB14_Msk                (0x1U << CAN_F6FB2_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F6FB2_FFDB14                    CAN_F6FB2_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F6FB2_FFDB15_Pos                (15U)
#define CAN_F6FB2_FFDB15_Msk                (0x1U << CAN_F6FB2_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F6FB2_FFDB15                    CAN_F6FB2_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F6FB2_FFDB16_Pos                (16U)
#define CAN_F6FB2_FFDB16_Msk                (0x1U << CAN_F6FB2_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F6FB2_FFDB16                    CAN_F6FB2_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F6FB2_FFDB17_Pos                (17U)
#define CAN_F6FB2_FFDB17_Msk                (0x1U << CAN_F6FB2_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F6FB2_FFDB17                    CAN_F6FB2_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F6FB2_FFDB18_Pos                (18U)
#define CAN_F6FB2_FFDB18_Msk                (0x1U << CAN_F6FB2_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F6FB2_FFDB18                    CAN_F6FB2_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F6FB2_FFDB19_Pos                (19U)
#define CAN_F6FB2_FFDB19_Msk                (0x1U << CAN_F6FB2_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F6FB2_FFDB19                    CAN_F6FB2_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F6FB2_FFDB20_Pos                (20U)
#define CAN_F6FB2_FFDB20_Msk                (0x1U << CAN_F6FB2_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F6FB2_FFDB20                    CAN_F6FB2_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F6FB2_FFDB21_Pos                (21U)
#define CAN_F6FB2_FFDB21_Msk                (0x1U << CAN_F6FB2_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F6FB2_FFDB21                    CAN_F6FB2_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F6FB2_FFDB22_Pos                (22U)
#define CAN_F6FB2_FFDB22_Msk                (0x1U << CAN_F6FB2_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F6FB2_FFDB22                    CAN_F6FB2_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F6FB2_FFDB23_Pos                (23U)
#define CAN_F6FB2_FFDB23_Msk                (0x1U << CAN_F6FB2_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F6FB2_FFDB23                    CAN_F6FB2_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F6FB2_FFDB24_Pos                (24U)
#define CAN_F6FB2_FFDB24_Msk                (0x1U << CAN_F6FB2_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F6FB2_FFDB24                    CAN_F6FB2_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F6FB2_FFDB25_Pos                (25U)
#define CAN_F6FB2_FFDB25_Msk                (0x1U << CAN_F6FB2_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F6FB2_FFDB25                    CAN_F6FB2_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F6FB2_FFDB26_Pos                (26U)
#define CAN_F6FB2_FFDB26_Msk                (0x1U << CAN_F6FB2_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F6FB2_FFDB26                    CAN_F6FB2_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F6FB2_FFDB27_Pos                (27U)
#define CAN_F6FB2_FFDB27_Msk                (0x1U << CAN_F6FB2_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F6FB2_FFDB27                    CAN_F6FB2_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F6FB2_FFDB28_Pos                (28U)
#define CAN_F6FB2_FFDB28_Msk                (0x1U << CAN_F6FB2_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F6FB2_FFDB28                    CAN_F6FB2_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F6FB2_FFDB29_Pos                (29U)
#define CAN_F6FB2_FFDB29_Msk                (0x1U << CAN_F6FB2_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F6FB2_FFDB29                    CAN_F6FB2_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F6FB2_FFDB30_Pos                (30U)
#define CAN_F6FB2_FFDB30_Msk                (0x1U << CAN_F6FB2_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F6FB2_FFDB30                    CAN_F6FB2_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F6FB2_FFDB31_Pos                (31U)
#define CAN_F6FB2_FFDB31_Msk                (0x1U << CAN_F6FB2_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F6FB2_FFDB31                    CAN_F6FB2_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F7FB2 register  *******************/
#define CAN_F7FB2_FFDB0_Pos                 (0U)
#define CAN_F7FB2_FFDB0_Msk                 (0x1U << CAN_F7FB2_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F7FB2_FFDB0                     CAN_F7FB2_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F7FB2_FFDB1_Pos                 (1U)
#define CAN_F7FB2_FFDB1_Msk                 (0x1U << CAN_F7FB2_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F7FB2_FFDB1                     CAN_F7FB2_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F7FB2_FFDB2_Pos                 (2U)
#define CAN_F7FB2_FFDB2_Msk                 (0x1U << CAN_F7FB2_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F7FB2_FFDB2                     CAN_F7FB2_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F7FB2_FFDB3_Pos                 (3U)
#define CAN_F7FB2_FFDB3_Msk                 (0x1U << CAN_F7FB2_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F7FB2_FFDB3                     CAN_F7FB2_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F7FB2_FFDB4_Pos                 (4U)
#define CAN_F7FB2_FFDB4_Msk                 (0x1U << CAN_F7FB2_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F7FB2_FFDB4                     CAN_F7FB2_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F7FB2_FFDB5_Pos                 (5U)
#define CAN_F7FB2_FFDB5_Msk                 (0x1U << CAN_F7FB2_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F7FB2_FFDB5                     CAN_F7FB2_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F7FB2_FFDB6_Pos                 (6U)
#define CAN_F7FB2_FFDB6_Msk                 (0x1U << CAN_F7FB2_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F7FB2_FFDB6                     CAN_F7FB2_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F7FB2_FFDB7_Pos                 (7U)
#define CAN_F7FB2_FFDB7_Msk                 (0x1U << CAN_F7FB2_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F7FB2_FFDB7                     CAN_F7FB2_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F7FB2_FFDB8_Pos                 (8U)
#define CAN_F7FB2_FFDB8_Msk                 (0x1U << CAN_F7FB2_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F7FB2_FFDB8                     CAN_F7FB2_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F7FB2_FFDB9_Pos                 (9U)
#define CAN_F7FB2_FFDB9_Msk                 (0x1U << CAN_F7FB2_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F7FB2_FFDB9                     CAN_F7FB2_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F7FB2_FFDB10_Pos                (10U)
#define CAN_F7FB2_FFDB10_Msk                (0x1U << CAN_F7FB2_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F7FB2_FFDB10                    CAN_F7FB2_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F7FB2_FFDB11_Pos                (11U)
#define CAN_F7FB2_FFDB11_Msk                (0x1U << CAN_F7FB2_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F7FB2_FFDB11                    CAN_F7FB2_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F7FB2_FFDB12_Pos                (12U)
#define CAN_F7FB2_FFDB12_Msk                (0x1U << CAN_F7FB2_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F7FB2_FFDB12                    CAN_F7FB2_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F7FB2_FFDB13_Pos                (13U)
#define CAN_F7FB2_FFDB13_Msk                (0x1U << CAN_F7FB2_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F7FB2_FFDB13                    CAN_F7FB2_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F7FB2_FFDB14_Pos                (14U)
#define CAN_F7FB2_FFDB14_Msk                (0x1U << CAN_F7FB2_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F7FB2_FFDB14                    CAN_F7FB2_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F7FB2_FFDB15_Pos                (15U)
#define CAN_F7FB2_FFDB15_Msk                (0x1U << CAN_F7FB2_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F7FB2_FFDB15                    CAN_F7FB2_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F7FB2_FFDB16_Pos                (16U)
#define CAN_F7FB2_FFDB16_Msk                (0x1U << CAN_F7FB2_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F7FB2_FFDB16                    CAN_F7FB2_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F7FB2_FFDB17_Pos                (17U)
#define CAN_F7FB2_FFDB17_Msk                (0x1U << CAN_F7FB2_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F7FB2_FFDB17                    CAN_F7FB2_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F7FB2_FFDB18_Pos                (18U)
#define CAN_F7FB2_FFDB18_Msk                (0x1U << CAN_F7FB2_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F7FB2_FFDB18                    CAN_F7FB2_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F7FB2_FFDB19_Pos                (19U)
#define CAN_F7FB2_FFDB19_Msk                (0x1U << CAN_F7FB2_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F7FB2_FFDB19                    CAN_F7FB2_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F7FB2_FFDB20_Pos                (20U)
#define CAN_F7FB2_FFDB20_Msk                (0x1U << CAN_F7FB2_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F7FB2_FFDB20                    CAN_F7FB2_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F7FB2_FFDB21_Pos                (21U)
#define CAN_F7FB2_FFDB21_Msk                (0x1U << CAN_F7FB2_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F7FB2_FFDB21                    CAN_F7FB2_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F7FB2_FFDB22_Pos                (22U)
#define CAN_F7FB2_FFDB22_Msk                (0x1U << CAN_F7FB2_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F7FB2_FFDB22                    CAN_F7FB2_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F7FB2_FFDB23_Pos                (23U)
#define CAN_F7FB2_FFDB23_Msk                (0x1U << CAN_F7FB2_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F7FB2_FFDB23                    CAN_F7FB2_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F7FB2_FFDB24_Pos                (24U)
#define CAN_F7FB2_FFDB24_Msk                (0x1U << CAN_F7FB2_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F7FB2_FFDB24                    CAN_F7FB2_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F7FB2_FFDB25_Pos                (25U)
#define CAN_F7FB2_FFDB25_Msk                (0x1U << CAN_F7FB2_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F7FB2_FFDB25                    CAN_F7FB2_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F7FB2_FFDB26_Pos                (26U)
#define CAN_F7FB2_FFDB26_Msk                (0x1U << CAN_F7FB2_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F7FB2_FFDB26                    CAN_F7FB2_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F7FB2_FFDB27_Pos                (27U)
#define CAN_F7FB2_FFDB27_Msk                (0x1U << CAN_F7FB2_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F7FB2_FFDB27                    CAN_F7FB2_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F7FB2_FFDB28_Pos                (28U)
#define CAN_F7FB2_FFDB28_Msk                (0x1U << CAN_F7FB2_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F7FB2_FFDB28                    CAN_F7FB2_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F7FB2_FFDB29_Pos                (29U)
#define CAN_F7FB2_FFDB29_Msk                (0x1U << CAN_F7FB2_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F7FB2_FFDB29                    CAN_F7FB2_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F7FB2_FFDB30_Pos                (30U)
#define CAN_F7FB2_FFDB30_Msk                (0x1U << CAN_F7FB2_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F7FB2_FFDB30                    CAN_F7FB2_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F7FB2_FFDB31_Pos                (31U)
#define CAN_F7FB2_FFDB31_Msk                (0x1U << CAN_F7FB2_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F7FB2_FFDB31                    CAN_F7FB2_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F8FB2 register  *******************/
#define CAN_F8FB2_FFDB0_Pos                 (0U)
#define CAN_F8FB2_FFDB0_Msk                 (0x1U << CAN_F8FB2_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F8FB2_FFDB0                     CAN_F8FB2_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F8FB2_FFDB1_Pos                 (1U)
#define CAN_F8FB2_FFDB1_Msk                 (0x1U << CAN_F8FB2_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F8FB2_FFDB1                     CAN_F8FB2_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F8FB2_FFDB2_Pos                 (2U)
#define CAN_F8FB2_FFDB2_Msk                 (0x1U << CAN_F8FB2_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F8FB2_FFDB2                     CAN_F8FB2_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F8FB2_FFDB3_Pos                 (3U)
#define CAN_F8FB2_FFDB3_Msk                 (0x1U << CAN_F8FB2_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F8FB2_FFDB3                     CAN_F8FB2_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F8FB2_FFDB4_Pos                 (4U)
#define CAN_F8FB2_FFDB4_Msk                 (0x1U << CAN_F8FB2_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F8FB2_FFDB4                     CAN_F8FB2_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F8FB2_FFDB5_Pos                 (5U)
#define CAN_F8FB2_FFDB5_Msk                 (0x1U << CAN_F8FB2_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F8FB2_FFDB5                     CAN_F8FB2_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F8FB2_FFDB6_Pos                 (6U)
#define CAN_F8FB2_FFDB6_Msk                 (0x1U << CAN_F8FB2_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F8FB2_FFDB6                     CAN_F8FB2_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F8FB2_FFDB7_Pos                 (7U)
#define CAN_F8FB2_FFDB7_Msk                 (0x1U << CAN_F8FB2_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F8FB2_FFDB7                     CAN_F8FB2_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F8FB2_FFDB8_Pos                 (8U)
#define CAN_F8FB2_FFDB8_Msk                 (0x1U << CAN_F8FB2_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F8FB2_FFDB8                     CAN_F8FB2_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F8FB2_FFDB9_Pos                 (9U)
#define CAN_F8FB2_FFDB9_Msk                 (0x1U << CAN_F8FB2_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F8FB2_FFDB9                     CAN_F8FB2_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F8FB2_FFDB10_Pos                (10U)
#define CAN_F8FB2_FFDB10_Msk                (0x1U << CAN_F8FB2_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F8FB2_FFDB10                    CAN_F8FB2_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F8FB2_FFDB11_Pos                (11U)
#define CAN_F8FB2_FFDB11_Msk                (0x1U << CAN_F8FB2_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F8FB2_FFDB11                    CAN_F8FB2_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F8FB2_FFDB12_Pos                (12U)
#define CAN_F8FB2_FFDB12_Msk                (0x1U << CAN_F8FB2_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F8FB2_FFDB12                    CAN_F8FB2_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F8FB2_FFDB13_Pos                (13U)
#define CAN_F8FB2_FFDB13_Msk                (0x1U << CAN_F8FB2_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F8FB2_FFDB13                    CAN_F8FB2_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F8FB2_FFDB14_Pos                (14U)
#define CAN_F8FB2_FFDB14_Msk                (0x1U << CAN_F8FB2_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F8FB2_FFDB14                    CAN_F8FB2_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F8FB2_FFDB15_Pos                (15U)
#define CAN_F8FB2_FFDB15_Msk                (0x1U << CAN_F8FB2_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F8FB2_FFDB15                    CAN_F8FB2_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F8FB2_FFDB16_Pos                (16U)
#define CAN_F8FB2_FFDB16_Msk                (0x1U << CAN_F8FB2_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F8FB2_FFDB16                    CAN_F8FB2_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F8FB2_FFDB17_Pos                (17U)
#define CAN_F8FB2_FFDB17_Msk                (0x1U << CAN_F8FB2_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F8FB2_FFDB17                    CAN_F8FB2_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F8FB2_FFDB18_Pos                (18U)
#define CAN_F8FB2_FFDB18_Msk                (0x1U << CAN_F8FB2_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F8FB2_FFDB18                    CAN_F8FB2_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F8FB2_FFDB19_Pos                (19U)
#define CAN_F8FB2_FFDB19_Msk                (0x1U << CAN_F8FB2_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F8FB2_FFDB19                    CAN_F8FB2_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F8FB2_FFDB20_Pos                (20U)
#define CAN_F8FB2_FFDB20_Msk                (0x1U << CAN_F8FB2_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F8FB2_FFDB20                    CAN_F8FB2_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F8FB2_FFDB21_Pos                (21U)
#define CAN_F8FB2_FFDB21_Msk                (0x1U << CAN_F8FB2_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F8FB2_FFDB21                    CAN_F8FB2_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F8FB2_FFDB22_Pos                (22U)
#define CAN_F8FB2_FFDB22_Msk                (0x1U << CAN_F8FB2_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F8FB2_FFDB22                    CAN_F8FB2_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F8FB2_FFDB23_Pos                (23U)
#define CAN_F8FB2_FFDB23_Msk                (0x1U << CAN_F8FB2_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F8FB2_FFDB23                    CAN_F8FB2_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F8FB2_FFDB24_Pos                (24U)
#define CAN_F8FB2_FFDB24_Msk                (0x1U << CAN_F8FB2_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F8FB2_FFDB24                    CAN_F8FB2_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F8FB2_FFDB25_Pos                (25U)
#define CAN_F8FB2_FFDB25_Msk                (0x1U << CAN_F8FB2_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F8FB2_FFDB25                    CAN_F8FB2_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F8FB2_FFDB26_Pos                (26U)
#define CAN_F8FB2_FFDB26_Msk                (0x1U << CAN_F8FB2_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F8FB2_FFDB26                    CAN_F8FB2_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F8FB2_FFDB27_Pos                (27U)
#define CAN_F8FB2_FFDB27_Msk                (0x1U << CAN_F8FB2_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F8FB2_FFDB27                    CAN_F8FB2_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F8FB2_FFDB28_Pos                (28U)
#define CAN_F8FB2_FFDB28_Msk                (0x1U << CAN_F8FB2_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F8FB2_FFDB28                    CAN_F8FB2_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F8FB2_FFDB29_Pos                (29U)
#define CAN_F8FB2_FFDB29_Msk                (0x1U << CAN_F8FB2_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F8FB2_FFDB29                    CAN_F8FB2_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F8FB2_FFDB30_Pos                (30U)
#define CAN_F8FB2_FFDB30_Msk                (0x1U << CAN_F8FB2_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F8FB2_FFDB30                    CAN_F8FB2_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F8FB2_FFDB31_Pos                (31U)
#define CAN_F8FB2_FFDB31_Msk                (0x1U << CAN_F8FB2_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F8FB2_FFDB31                    CAN_F8FB2_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F9FB2 register  *******************/
#define CAN_F9FB2_FFDB0_Pos                 (0U)
#define CAN_F9FB2_FFDB0_Msk                 (0x1U << CAN_F9FB2_FFDB0_Pos)           /*!< 0x00000001 */
#define CAN_F9FB2_FFDB0                     CAN_F9FB2_FFDB0_Msk                     /*!< Filter data bit 0 */
#define CAN_F9FB2_FFDB1_Pos                 (1U)
#define CAN_F9FB2_FFDB1_Msk                 (0x1U << CAN_F9FB2_FFDB1_Pos)           /*!< 0x00000002 */
#define CAN_F9FB2_FFDB1                     CAN_F9FB2_FFDB1_Msk                     /*!< Filter data bit 1 */
#define CAN_F9FB2_FFDB2_Pos                 (2U)
#define CAN_F9FB2_FFDB2_Msk                 (0x1U << CAN_F9FB2_FFDB2_Pos)           /*!< 0x00000004 */
#define CAN_F9FB2_FFDB2                     CAN_F9FB2_FFDB2_Msk                     /*!< Filter data bit 2 */
#define CAN_F9FB2_FFDB3_Pos                 (3U)
#define CAN_F9FB2_FFDB3_Msk                 (0x1U << CAN_F9FB2_FFDB3_Pos)           /*!< 0x00000008 */
#define CAN_F9FB2_FFDB3                     CAN_F9FB2_FFDB3_Msk                     /*!< Filter data bit 3 */
#define CAN_F9FB2_FFDB4_Pos                 (4U)
#define CAN_F9FB2_FFDB4_Msk                 (0x1U << CAN_F9FB2_FFDB4_Pos)           /*!< 0x00000010 */
#define CAN_F9FB2_FFDB4                     CAN_F9FB2_FFDB4_Msk                     /*!< Filter data bit 4 */
#define CAN_F9FB2_FFDB5_Pos                 (5U)
#define CAN_F9FB2_FFDB5_Msk                 (0x1U << CAN_F9FB2_FFDB5_Pos)           /*!< 0x00000020 */
#define CAN_F9FB2_FFDB5                     CAN_F9FB2_FFDB5_Msk                     /*!< Filter data bit 5 */
#define CAN_F9FB2_FFDB6_Pos                 (6U)
#define CAN_F9FB2_FFDB6_Msk                 (0x1U << CAN_F9FB2_FFDB6_Pos)           /*!< 0x00000040 */
#define CAN_F9FB2_FFDB6                     CAN_F9FB2_FFDB6_Msk                     /*!< Filter data bit 6 */
#define CAN_F9FB2_FFDB7_Pos                 (7U)
#define CAN_F9FB2_FFDB7_Msk                 (0x1U << CAN_F9FB2_FFDB7_Pos)           /*!< 0x00000080 */
#define CAN_F9FB2_FFDB7                     CAN_F9FB2_FFDB7_Msk                     /*!< Filter data bit 7 */
#define CAN_F9FB2_FFDB8_Pos                 (8U)
#define CAN_F9FB2_FFDB8_Msk                 (0x1U << CAN_F9FB2_FFDB8_Pos)           /*!< 0x00000100 */
#define CAN_F9FB2_FFDB8                     CAN_F9FB2_FFDB8_Msk                     /*!< Filter data bit 8 */
#define CAN_F9FB2_FFDB9_Pos                 (9U)
#define CAN_F9FB2_FFDB9_Msk                 (0x1U << CAN_F9FB2_FFDB9_Pos)           /*!< 0x00000200 */
#define CAN_F9FB2_FFDB9                     CAN_F9FB2_FFDB9_Msk                     /*!< Filter data bit 9 */
#define CAN_F9FB2_FFDB10_Pos                (10U)
#define CAN_F9FB2_FFDB10_Msk                (0x1U << CAN_F9FB2_FFDB10_Pos)          /*!< 0x00000400 */
#define CAN_F9FB2_FFDB10                    CAN_F9FB2_FFDB10_Msk                    /*!< Filter data bit 10 */
#define CAN_F9FB2_FFDB11_Pos                (11U)
#define CAN_F9FB2_FFDB11_Msk                (0x1U << CAN_F9FB2_FFDB11_Pos)          /*!< 0x00000800 */
#define CAN_F9FB2_FFDB11                    CAN_F9FB2_FFDB11_Msk                    /*!< Filter data bit 11 */
#define CAN_F9FB2_FFDB12_Pos                (12U)
#define CAN_F9FB2_FFDB12_Msk                (0x1U << CAN_F9FB2_FFDB12_Pos)          /*!< 0x00001000 */
#define CAN_F9FB2_FFDB12                    CAN_F9FB2_FFDB12_Msk                    /*!< Filter data bit 12 */
#define CAN_F9FB2_FFDB13_Pos                (13U)
#define CAN_F9FB2_FFDB13_Msk                (0x1U << CAN_F9FB2_FFDB13_Pos)          /*!< 0x00002000 */
#define CAN_F9FB2_FFDB13                    CAN_F9FB2_FFDB13_Msk                    /*!< Filter data bit 13 */
#define CAN_F9FB2_FFDB14_Pos                (14U)
#define CAN_F9FB2_FFDB14_Msk                (0x1U << CAN_F9FB2_FFDB14_Pos)          /*!< 0x00004000 */
#define CAN_F9FB2_FFDB14                    CAN_F9FB2_FFDB14_Msk                    /*!< Filter data bit 14 */
#define CAN_F9FB2_FFDB15_Pos                (15U)
#define CAN_F9FB2_FFDB15_Msk                (0x1U << CAN_F9FB2_FFDB15_Pos)          /*!< 0x00008000 */
#define CAN_F9FB2_FFDB15                    CAN_F9FB2_FFDB15_Msk                    /*!< Filter data bit 15 */
#define CAN_F9FB2_FFDB16_Pos                (16U)
#define CAN_F9FB2_FFDB16_Msk                (0x1U << CAN_F9FB2_FFDB16_Pos)          /*!< 0x00010000 */
#define CAN_F9FB2_FFDB16                    CAN_F9FB2_FFDB16_Msk                    /*!< Filter data bit 16 */
#define CAN_F9FB2_FFDB17_Pos                (17U)
#define CAN_F9FB2_FFDB17_Msk                (0x1U << CAN_F9FB2_FFDB17_Pos)          /*!< 0x00020000 */
#define CAN_F9FB2_FFDB17                    CAN_F9FB2_FFDB17_Msk                    /*!< Filter data bit 17 */
#define CAN_F9FB2_FFDB18_Pos                (18U)
#define CAN_F9FB2_FFDB18_Msk                (0x1U << CAN_F9FB2_FFDB18_Pos)          /*!< 0x00040000 */
#define CAN_F9FB2_FFDB18                    CAN_F9FB2_FFDB18_Msk                    /*!< Filter data bit 18 */
#define CAN_F9FB2_FFDB19_Pos                (19U)
#define CAN_F9FB2_FFDB19_Msk                (0x1U << CAN_F9FB2_FFDB19_Pos)          /*!< 0x00080000 */
#define CAN_F9FB2_FFDB19                    CAN_F9FB2_FFDB19_Msk                    /*!< Filter data bit 19 */
#define CAN_F9FB2_FFDB20_Pos                (20U)
#define CAN_F9FB2_FFDB20_Msk                (0x1U << CAN_F9FB2_FFDB20_Pos)          /*!< 0x00100000 */
#define CAN_F9FB2_FFDB20                    CAN_F9FB2_FFDB20_Msk                    /*!< Filter data bit 20 */
#define CAN_F9FB2_FFDB21_Pos                (21U)
#define CAN_F9FB2_FFDB21_Msk                (0x1U << CAN_F9FB2_FFDB21_Pos)          /*!< 0x00200000 */
#define CAN_F9FB2_FFDB21                    CAN_F9FB2_FFDB21_Msk                    /*!< Filter data bit 21 */
#define CAN_F9FB2_FFDB22_Pos                (22U)
#define CAN_F9FB2_FFDB22_Msk                (0x1U << CAN_F9FB2_FFDB22_Pos)          /*!< 0x00400000 */
#define CAN_F9FB2_FFDB22                    CAN_F9FB2_FFDB22_Msk                    /*!< Filter data bit 22 */
#define CAN_F9FB2_FFDB23_Pos                (23U)
#define CAN_F9FB2_FFDB23_Msk                (0x1U << CAN_F9FB2_FFDB23_Pos)          /*!< 0x00800000 */
#define CAN_F9FB2_FFDB23                    CAN_F9FB2_FFDB23_Msk                    /*!< Filter data bit 23 */
#define CAN_F9FB2_FFDB24_Pos                (24U)
#define CAN_F9FB2_FFDB24_Msk                (0x1U << CAN_F9FB2_FFDB24_Pos)          /*!< 0x01000000 */
#define CAN_F9FB2_FFDB24                    CAN_F9FB2_FFDB24_Msk                    /*!< Filter data bit 24 */
#define CAN_F9FB2_FFDB25_Pos                (25U)
#define CAN_F9FB2_FFDB25_Msk                (0x1U << CAN_F9FB2_FFDB25_Pos)          /*!< 0x02000000 */
#define CAN_F9FB2_FFDB25                    CAN_F9FB2_FFDB25_Msk                    /*!< Filter data bit 25 */
#define CAN_F9FB2_FFDB26_Pos                (26U)
#define CAN_F9FB2_FFDB26_Msk                (0x1U << CAN_F9FB2_FFDB26_Pos)          /*!< 0x04000000 */
#define CAN_F9FB2_FFDB26                    CAN_F9FB2_FFDB26_Msk                    /*!< Filter data bit 26 */
#define CAN_F9FB2_FFDB27_Pos                (27U)
#define CAN_F9FB2_FFDB27_Msk                (0x1U << CAN_F9FB2_FFDB27_Pos)          /*!< 0x08000000 */
#define CAN_F9FB2_FFDB27                    CAN_F9FB2_FFDB27_Msk                    /*!< Filter data bit 27 */
#define CAN_F9FB2_FFDB28_Pos                (28U)
#define CAN_F9FB2_FFDB28_Msk                (0x1U << CAN_F9FB2_FFDB28_Pos)          /*!< 0x10000000 */
#define CAN_F9FB2_FFDB28                    CAN_F9FB2_FFDB28_Msk                    /*!< Filter data bit 28 */
#define CAN_F9FB2_FFDB29_Pos                (29U)
#define CAN_F9FB2_FFDB29_Msk                (0x1U << CAN_F9FB2_FFDB29_Pos)          /*!< 0x20000000 */
#define CAN_F9FB2_FFDB29                    CAN_F9FB2_FFDB29_Msk                    /*!< Filter data bit 29 */
#define CAN_F9FB2_FFDB30_Pos                (30U)
#define CAN_F9FB2_FFDB30_Msk                (0x1U << CAN_F9FB2_FFDB30_Pos)          /*!< 0x40000000 */
#define CAN_F9FB2_FFDB30                    CAN_F9FB2_FFDB30_Msk                    /*!< Filter data bit 30 */
#define CAN_F9FB2_FFDB31_Pos                (31U)
#define CAN_F9FB2_FFDB31_Msk                (0x1U << CAN_F9FB2_FFDB31_Pos)          /*!< 0x80000000 */
#define CAN_F9FB2_FFDB31                    CAN_F9FB2_FFDB31_Msk                    /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F10FB2 register  ******************/
#define CAN_F10FB2_FFDB0_Pos                (0U)
#define CAN_F10FB2_FFDB0_Msk                (0x1U << CAN_F10FB2_FFDB0_Pos)          /*!< 0x00000001 */
#define CAN_F10FB2_FFDB0                    CAN_F10FB2_FFDB0_Msk                    /*!< Filter data bit 0 */
#define CAN_F10FB2_FFDB1_Pos                (1U)
#define CAN_F10FB2_FFDB1_Msk                (0x1U << CAN_F10FB2_FFDB1_Pos)          /*!< 0x00000002 */
#define CAN_F10FB2_FFDB1                    CAN_F10FB2_FFDB1_Msk                    /*!< Filter data bit 1 */
#define CAN_F10FB2_FFDB2_Pos                (2U)
#define CAN_F10FB2_FFDB2_Msk                (0x1U << CAN_F10FB2_FFDB2_Pos)          /*!< 0x00000004 */
#define CAN_F10FB2_FFDB2                    CAN_F10FB2_FFDB2_Msk                    /*!< Filter data bit 2 */
#define CAN_F10FB2_FFDB3_Pos                (3U)
#define CAN_F10FB2_FFDB3_Msk                (0x1U << CAN_F10FB2_FFDB3_Pos)          /*!< 0x00000008 */
#define CAN_F10FB2_FFDB3                    CAN_F10FB2_FFDB3_Msk                    /*!< Filter data bit 3 */
#define CAN_F10FB2_FFDB4_Pos                (4U)
#define CAN_F10FB2_FFDB4_Msk                (0x1U << CAN_F10FB2_FFDB4_Pos)          /*!< 0x00000010 */
#define CAN_F10FB2_FFDB4                    CAN_F10FB2_FFDB4_Msk                    /*!< Filter data bit 4 */
#define CAN_F10FB2_FFDB5_Pos                (5U)
#define CAN_F10FB2_FFDB5_Msk                (0x1U << CAN_F10FB2_FFDB5_Pos)          /*!< 0x00000020 */
#define CAN_F10FB2_FFDB5                    CAN_F10FB2_FFDB5_Msk                    /*!< Filter data bit 5 */
#define CAN_F10FB2_FFDB6_Pos                (6U)
#define CAN_F10FB2_FFDB6_Msk                (0x1U << CAN_F10FB2_FFDB6_Pos)          /*!< 0x00000040 */
#define CAN_F10FB2_FFDB6                    CAN_F10FB2_FFDB6_Msk                    /*!< Filter data bit 6 */
#define CAN_F10FB2_FFDB7_Pos                (7U)
#define CAN_F10FB2_FFDB7_Msk                (0x1U << CAN_F10FB2_FFDB7_Pos)          /*!< 0x00000080 */
#define CAN_F10FB2_FFDB7                    CAN_F10FB2_FFDB7_Msk                    /*!< Filter data bit 7 */
#define CAN_F10FB2_FFDB8_Pos                (8U)
#define CAN_F10FB2_FFDB8_Msk                (0x1U << CAN_F10FB2_FFDB8_Pos)          /*!< 0x00000100 */
#define CAN_F10FB2_FFDB8                    CAN_F10FB2_FFDB8_Msk                    /*!< Filter data bit 8 */
#define CAN_F10FB2_FFDB9_Pos                (9U)
#define CAN_F10FB2_FFDB9_Msk                (0x1U << CAN_F10FB2_FFDB9_Pos)          /*!< 0x00000200 */
#define CAN_F10FB2_FFDB9                    CAN_F10FB2_FFDB9_Msk                    /*!< Filter data bit 9 */
#define CAN_F10FB2_FFDB10_Pos               (10U)
#define CAN_F10FB2_FFDB10_Msk               (0x1U << CAN_F10FB2_FFDB10_Pos)         /*!< 0x00000400 */
#define CAN_F10FB2_FFDB10                   CAN_F10FB2_FFDB10_Msk                   /*!< Filter data bit 10 */
#define CAN_F10FB2_FFDB11_Pos               (11U)
#define CAN_F10FB2_FFDB11_Msk               (0x1U << CAN_F10FB2_FFDB11_Pos)         /*!< 0x00000800 */
#define CAN_F10FB2_FFDB11                   CAN_F10FB2_FFDB11_Msk                   /*!< Filter data bit 11 */
#define CAN_F10FB2_FFDB12_Pos               (12U)
#define CAN_F10FB2_FFDB12_Msk               (0x1U << CAN_F10FB2_FFDB12_Pos)         /*!< 0x00001000 */
#define CAN_F10FB2_FFDB12                   CAN_F10FB2_FFDB12_Msk                   /*!< Filter data bit 12 */
#define CAN_F10FB2_FFDB13_Pos               (13U)
#define CAN_F10FB2_FFDB13_Msk               (0x1U << CAN_F10FB2_FFDB13_Pos)         /*!< 0x00002000 */
#define CAN_F10FB2_FFDB13                   CAN_F10FB2_FFDB13_Msk                   /*!< Filter data bit 13 */
#define CAN_F10FB2_FFDB14_Pos               (14U)
#define CAN_F10FB2_FFDB14_Msk               (0x1U << CAN_F10FB2_FFDB14_Pos)         /*!< 0x00004000 */
#define CAN_F10FB2_FFDB14                   CAN_F10FB2_FFDB14_Msk                   /*!< Filter data bit 14 */
#define CAN_F10FB2_FFDB15_Pos               (15U)
#define CAN_F10FB2_FFDB15_Msk               (0x1U << CAN_F10FB2_FFDB15_Pos)         /*!< 0x00008000 */
#define CAN_F10FB2_FFDB15                   CAN_F10FB2_FFDB15_Msk                   /*!< Filter data bit 15 */
#define CAN_F10FB2_FFDB16_Pos               (16U)
#define CAN_F10FB2_FFDB16_Msk               (0x1U << CAN_F10FB2_FFDB16_Pos)         /*!< 0x00010000 */
#define CAN_F10FB2_FFDB16                   CAN_F10FB2_FFDB16_Msk                   /*!< Filter data bit 16 */
#define CAN_F10FB2_FFDB17_Pos               (17U)
#define CAN_F10FB2_FFDB17_Msk               (0x1U << CAN_F10FB2_FFDB17_Pos)         /*!< 0x00020000 */
#define CAN_F10FB2_FFDB17                   CAN_F10FB2_FFDB17_Msk                   /*!< Filter data bit 17 */
#define CAN_F10FB2_FFDB18_Pos               (18U)
#define CAN_F10FB2_FFDB18_Msk               (0x1U << CAN_F10FB2_FFDB18_Pos)         /*!< 0x00040000 */
#define CAN_F10FB2_FFDB18                   CAN_F10FB2_FFDB18_Msk                   /*!< Filter data bit 18 */
#define CAN_F10FB2_FFDB19_Pos               (19U)
#define CAN_F10FB2_FFDB19_Msk               (0x1U << CAN_F10FB2_FFDB19_Pos)         /*!< 0x00080000 */
#define CAN_F10FB2_FFDB19                   CAN_F10FB2_FFDB19_Msk                   /*!< Filter data bit 19 */
#define CAN_F10FB2_FFDB20_Pos               (20U)
#define CAN_F10FB2_FFDB20_Msk               (0x1U << CAN_F10FB2_FFDB20_Pos)         /*!< 0x00100000 */
#define CAN_F10FB2_FFDB20                   CAN_F10FB2_FFDB20_Msk                   /*!< Filter data bit 20 */
#define CAN_F10FB2_FFDB21_Pos               (21U)
#define CAN_F10FB2_FFDB21_Msk               (0x1U << CAN_F10FB2_FFDB21_Pos)         /*!< 0x00200000 */
#define CAN_F10FB2_FFDB21                   CAN_F10FB2_FFDB21_Msk                   /*!< Filter data bit 21 */
#define CAN_F10FB2_FFDB22_Pos               (22U)
#define CAN_F10FB2_FFDB22_Msk               (0x1U << CAN_F10FB2_FFDB22_Pos)         /*!< 0x00400000 */
#define CAN_F10FB2_FFDB22                   CAN_F10FB2_FFDB22_Msk                   /*!< Filter data bit 22 */
#define CAN_F10FB2_FFDB23_Pos               (23U)
#define CAN_F10FB2_FFDB23_Msk               (0x1U << CAN_F10FB2_FFDB23_Pos)         /*!< 0x00800000 */
#define CAN_F10FB2_FFDB23                   CAN_F10FB2_FFDB23_Msk                   /*!< Filter data bit 23 */
#define CAN_F10FB2_FFDB24_Pos               (24U)
#define CAN_F10FB2_FFDB24_Msk               (0x1U << CAN_F10FB2_FFDB24_Pos)         /*!< 0x01000000 */
#define CAN_F10FB2_FFDB24                   CAN_F10FB2_FFDB24_Msk                   /*!< Filter data bit 24 */
#define CAN_F10FB2_FFDB25_Pos               (25U)
#define CAN_F10FB2_FFDB25_Msk               (0x1U << CAN_F10FB2_FFDB25_Pos)         /*!< 0x02000000 */
#define CAN_F10FB2_FFDB25                   CAN_F10FB2_FFDB25_Msk                   /*!< Filter data bit 25 */
#define CAN_F10FB2_FFDB26_Pos               (26U)
#define CAN_F10FB2_FFDB26_Msk               (0x1U << CAN_F10FB2_FFDB26_Pos)         /*!< 0x04000000 */
#define CAN_F10FB2_FFDB26                   CAN_F10FB2_FFDB26_Msk                   /*!< Filter data bit 26 */
#define CAN_F10FB2_FFDB27_Pos               (27U)
#define CAN_F10FB2_FFDB27_Msk               (0x1U << CAN_F10FB2_FFDB27_Pos)         /*!< 0x08000000 */
#define CAN_F10FB2_FFDB27                   CAN_F10FB2_FFDB27_Msk                   /*!< Filter data bit 27 */
#define CAN_F10FB2_FFDB28_Pos               (28U)
#define CAN_F10FB2_FFDB28_Msk               (0x1U << CAN_F10FB2_FFDB28_Pos)         /*!< 0x10000000 */
#define CAN_F10FB2_FFDB28                   CAN_F10FB2_FFDB28_Msk                   /*!< Filter data bit 28 */
#define CAN_F10FB2_FFDB29_Pos               (29U)
#define CAN_F10FB2_FFDB29_Msk               (0x1U << CAN_F10FB2_FFDB29_Pos)         /*!< 0x20000000 */
#define CAN_F10FB2_FFDB29                   CAN_F10FB2_FFDB29_Msk                   /*!< Filter data bit 29 */
#define CAN_F10FB2_FFDB30_Pos               (30U)
#define CAN_F10FB2_FFDB30_Msk               (0x1U << CAN_F10FB2_FFDB30_Pos)         /*!< 0x40000000 */
#define CAN_F10FB2_FFDB30                   CAN_F10FB2_FFDB30_Msk                   /*!< Filter data bit 30 */
#define CAN_F10FB2_FFDB31_Pos               (31U)
#define CAN_F10FB2_FFDB31_Msk               (0x1U << CAN_F10FB2_FFDB31_Pos)         /*!< 0x80000000 */
#define CAN_F10FB2_FFDB31                   CAN_F10FB2_FFDB31_Msk                   /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F11FB2 register  ******************/
#define CAN_F11FB2_FFDB0_Pos                (0U)
#define CAN_F11FB2_FFDB0_Msk                (0x1U << CAN_F11FB2_FFDB0_Pos)          /*!< 0x00000001 */
#define CAN_F11FB2_FFDB0                    CAN_F11FB2_FFDB0_Msk                    /*!< Filter data bit 0 */
#define CAN_F11FB2_FFDB1_Pos                (1U)
#define CAN_F11FB2_FFDB1_Msk                (0x1U << CAN_F11FB2_FFDB1_Pos)          /*!< 0x00000002 */
#define CAN_F11FB2_FFDB1                    CAN_F11FB2_FFDB1_Msk                    /*!< Filter data bit 1 */
#define CAN_F11FB2_FFDB2_Pos                (2U)
#define CAN_F11FB2_FFDB2_Msk                (0x1U << CAN_F11FB2_FFDB2_Pos)          /*!< 0x00000004 */
#define CAN_F11FB2_FFDB2                    CAN_F11FB2_FFDB2_Msk                    /*!< Filter data bit 2 */
#define CAN_F11FB2_FFDB3_Pos                (3U)
#define CAN_F11FB2_FFDB3_Msk                (0x1U << CAN_F11FB2_FFDB3_Pos)          /*!< 0x00000008 */
#define CAN_F11FB2_FFDB3                    CAN_F11FB2_FFDB3_Msk                    /*!< Filter data bit 3 */
#define CAN_F11FB2_FFDB4_Pos                (4U)
#define CAN_F11FB2_FFDB4_Msk                (0x1U << CAN_F11FB2_FFDB4_Pos)          /*!< 0x00000010 */
#define CAN_F11FB2_FFDB4                    CAN_F11FB2_FFDB4_Msk                    /*!< Filter data bit 4 */
#define CAN_F11FB2_FFDB5_Pos                (5U)
#define CAN_F11FB2_FFDB5_Msk                (0x1U << CAN_F11FB2_FFDB5_Pos)          /*!< 0x00000020 */
#define CAN_F11FB2_FFDB5                    CAN_F11FB2_FFDB5_Msk                    /*!< Filter data bit 5 */
#define CAN_F11FB2_FFDB6_Pos                (6U)
#define CAN_F11FB2_FFDB6_Msk                (0x1U << CAN_F11FB2_FFDB6_Pos)          /*!< 0x00000040 */
#define CAN_F11FB2_FFDB6                    CAN_F11FB2_FFDB6_Msk                    /*!< Filter data bit 6 */
#define CAN_F11FB2_FFDB7_Pos                (7U)
#define CAN_F11FB2_FFDB7_Msk                (0x1U << CAN_F11FB2_FFDB7_Pos)          /*!< 0x00000080 */
#define CAN_F11FB2_FFDB7                    CAN_F11FB2_FFDB7_Msk                    /*!< Filter data bit 7 */
#define CAN_F11FB2_FFDB8_Pos                (8U)
#define CAN_F11FB2_FFDB8_Msk                (0x1U << CAN_F11FB2_FFDB8_Pos)          /*!< 0x00000100 */
#define CAN_F11FB2_FFDB8                    CAN_F11FB2_FFDB8_Msk                    /*!< Filter data bit 8 */
#define CAN_F11FB2_FFDB9_Pos                (9U)
#define CAN_F11FB2_FFDB9_Msk                (0x1U << CAN_F11FB2_FFDB9_Pos)          /*!< 0x00000200 */
#define CAN_F11FB2_FFDB9                    CAN_F11FB2_FFDB9_Msk                    /*!< Filter data bit 9 */
#define CAN_F11FB2_FFDB10_Pos               (10U)
#define CAN_F11FB2_FFDB10_Msk               (0x1U << CAN_F11FB2_FFDB10_Pos)         /*!< 0x00000400 */
#define CAN_F11FB2_FFDB10                   CAN_F11FB2_FFDB10_Msk                   /*!< Filter data bit 10 */
#define CAN_F11FB2_FFDB11_Pos               (11U)
#define CAN_F11FB2_FFDB11_Msk               (0x1U << CAN_F11FB2_FFDB11_Pos)         /*!< 0x00000800 */
#define CAN_F11FB2_FFDB11                   CAN_F11FB2_FFDB11_Msk                   /*!< Filter data bit 11 */
#define CAN_F11FB2_FFDB12_Pos               (12U)
#define CAN_F11FB2_FFDB12_Msk               (0x1U << CAN_F11FB2_FFDB12_Pos)         /*!< 0x00001000 */
#define CAN_F11FB2_FFDB12                   CAN_F11FB2_FFDB12_Msk                   /*!< Filter data bit 12 */
#define CAN_F11FB2_FFDB13_Pos               (13U)
#define CAN_F11FB2_FFDB13_Msk               (0x1U << CAN_F11FB2_FFDB13_Pos)         /*!< 0x00002000 */
#define CAN_F11FB2_FFDB13                   CAN_F11FB2_FFDB13_Msk                   /*!< Filter data bit 13 */
#define CAN_F11FB2_FFDB14_Pos               (14U)
#define CAN_F11FB2_FFDB14_Msk               (0x1U << CAN_F11FB2_FFDB14_Pos)         /*!< 0x00004000 */
#define CAN_F11FB2_FFDB14                   CAN_F11FB2_FFDB14_Msk                   /*!< Filter data bit 14 */
#define CAN_F11FB2_FFDB15_Pos               (15U)
#define CAN_F11FB2_FFDB15_Msk               (0x1U << CAN_F11FB2_FFDB15_Pos)         /*!< 0x00008000 */
#define CAN_F11FB2_FFDB15                   CAN_F11FB2_FFDB15_Msk                   /*!< Filter data bit 15 */
#define CAN_F11FB2_FFDB16_Pos               (16U)
#define CAN_F11FB2_FFDB16_Msk               (0x1U << CAN_F11FB2_FFDB16_Pos)         /*!< 0x00010000 */
#define CAN_F11FB2_FFDB16                   CAN_F11FB2_FFDB16_Msk                   /*!< Filter data bit 16 */
#define CAN_F11FB2_FFDB17_Pos               (17U)
#define CAN_F11FB2_FFDB17_Msk               (0x1U << CAN_F11FB2_FFDB17_Pos)         /*!< 0x00020000 */
#define CAN_F11FB2_FFDB17                   CAN_F11FB2_FFDB17_Msk                   /*!< Filter data bit 17 */
#define CAN_F11FB2_FFDB18_Pos               (18U)
#define CAN_F11FB2_FFDB18_Msk               (0x1U << CAN_F11FB2_FFDB18_Pos)         /*!< 0x00040000 */
#define CAN_F11FB2_FFDB18                   CAN_F11FB2_FFDB18_Msk                   /*!< Filter data bit 18 */
#define CAN_F11FB2_FFDB19_Pos               (19U)
#define CAN_F11FB2_FFDB19_Msk               (0x1U << CAN_F11FB2_FFDB19_Pos)         /*!< 0x00080000 */
#define CAN_F11FB2_FFDB19                   CAN_F11FB2_FFDB19_Msk                   /*!< Filter data bit 19 */
#define CAN_F11FB2_FFDB20_Pos               (20U)
#define CAN_F11FB2_FFDB20_Msk               (0x1U << CAN_F11FB2_FFDB20_Pos)         /*!< 0x00100000 */
#define CAN_F11FB2_FFDB20                   CAN_F11FB2_FFDB20_Msk                   /*!< Filter data bit 20 */
#define CAN_F11FB2_FFDB21_Pos               (21U)
#define CAN_F11FB2_FFDB21_Msk               (0x1U << CAN_F11FB2_FFDB21_Pos)         /*!< 0x00200000 */
#define CAN_F11FB2_FFDB21                   CAN_F11FB2_FFDB21_Msk                   /*!< Filter data bit 21 */
#define CAN_F11FB2_FFDB22_Pos               (22U)
#define CAN_F11FB2_FFDB22_Msk               (0x1U << CAN_F11FB2_FFDB22_Pos)         /*!< 0x00400000 */
#define CAN_F11FB2_FFDB22                   CAN_F11FB2_FFDB22_Msk                   /*!< Filter data bit 22 */
#define CAN_F11FB2_FFDB23_Pos               (23U)
#define CAN_F11FB2_FFDB23_Msk               (0x1U << CAN_F11FB2_FFDB23_Pos)         /*!< 0x00800000 */
#define CAN_F11FB2_FFDB23                   CAN_F11FB2_FFDB23_Msk                   /*!< Filter data bit 23 */
#define CAN_F11FB2_FFDB24_Pos               (24U)
#define CAN_F11FB2_FFDB24_Msk               (0x1U << CAN_F11FB2_FFDB24_Pos)         /*!< 0x01000000 */
#define CAN_F11FB2_FFDB24                   CAN_F11FB2_FFDB24_Msk                   /*!< Filter data bit 24 */
#define CAN_F11FB2_FFDB25_Pos               (25U)
#define CAN_F11FB2_FFDB25_Msk               (0x1U << CAN_F11FB2_FFDB25_Pos)         /*!< 0x02000000 */
#define CAN_F11FB2_FFDB25                   CAN_F11FB2_FFDB25_Msk                   /*!< Filter data bit 25 */
#define CAN_F11FB2_FFDB26_Pos               (26U)
#define CAN_F11FB2_FFDB26_Msk               (0x1U << CAN_F11FB2_FFDB26_Pos)         /*!< 0x04000000 */
#define CAN_F11FB2_FFDB26                   CAN_F11FB2_FFDB26_Msk                   /*!< Filter data bit 26 */
#define CAN_F11FB2_FFDB27_Pos               (27U)
#define CAN_F11FB2_FFDB27_Msk               (0x1U << CAN_F11FB2_FFDB27_Pos)         /*!< 0x08000000 */
#define CAN_F11FB2_FFDB27                   CAN_F11FB2_FFDB27_Msk                   /*!< Filter data bit 27 */
#define CAN_F11FB2_FFDB28_Pos               (28U)
#define CAN_F11FB2_FFDB28_Msk               (0x1U << CAN_F11FB2_FFDB28_Pos)         /*!< 0x10000000 */
#define CAN_F11FB2_FFDB28                   CAN_F11FB2_FFDB28_Msk                   /*!< Filter data bit 28 */
#define CAN_F11FB2_FFDB29_Pos               (29U)
#define CAN_F11FB2_FFDB29_Msk               (0x1U << CAN_F11FB2_FFDB29_Pos)         /*!< 0x20000000 */
#define CAN_F11FB2_FFDB29                   CAN_F11FB2_FFDB29_Msk                   /*!< Filter data bit 29 */
#define CAN_F11FB2_FFDB30_Pos               (30U)
#define CAN_F11FB2_FFDB30_Msk               (0x1U << CAN_F11FB2_FFDB30_Pos)         /*!< 0x40000000 */
#define CAN_F11FB2_FFDB30                   CAN_F11FB2_FFDB30_Msk                   /*!< Filter data bit 30 */
#define CAN_F11FB2_FFDB31_Pos               (31U)
#define CAN_F11FB2_FFDB31_Msk               (0x1U << CAN_F11FB2_FFDB31_Pos)         /*!< 0x80000000 */
#define CAN_F11FB2_FFDB31                   CAN_F11FB2_FFDB31_Msk                   /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F12FB2 register  ******************/
#define CAN_F12FB2_FFDB0_Pos                (0U)
#define CAN_F12FB2_FFDB0_Msk                (0x1U << CAN_F12FB2_FFDB0_Pos)          /*!< 0x00000001 */
#define CAN_F12FB2_FFDB0                    CAN_F12FB2_FFDB0_Msk                    /*!< Filter data bit 0 */
#define CAN_F12FB2_FFDB1_Pos                (1U)
#define CAN_F12FB2_FFDB1_Msk                (0x1U << CAN_F12FB2_FFDB1_Pos)          /*!< 0x00000002 */
#define CAN_F12FB2_FFDB1                    CAN_F12FB2_FFDB1_Msk                    /*!< Filter data bit 1 */
#define CAN_F12FB2_FFDB2_Pos                (2U)
#define CAN_F12FB2_FFDB2_Msk                (0x1U << CAN_F12FB2_FFDB2_Pos)          /*!< 0x00000004 */
#define CAN_F12FB2_FFDB2                    CAN_F12FB2_FFDB2_Msk                    /*!< Filter data bit 2 */
#define CAN_F12FB2_FFDB3_Pos                (3U)
#define CAN_F12FB2_FFDB3_Msk                (0x1U << CAN_F12FB2_FFDB3_Pos)          /*!< 0x00000008 */
#define CAN_F12FB2_FFDB3                    CAN_F12FB2_FFDB3_Msk                    /*!< Filter data bit 3 */
#define CAN_F12FB2_FFDB4_Pos                (4U)
#define CAN_F12FB2_FFDB4_Msk                (0x1U << CAN_F12FB2_FFDB4_Pos)          /*!< 0x00000010 */
#define CAN_F12FB2_FFDB4                    CAN_F12FB2_FFDB4_Msk                    /*!< Filter data bit 4 */
#define CAN_F12FB2_FFDB5_Pos                (5U)
#define CAN_F12FB2_FFDB5_Msk                (0x1U << CAN_F12FB2_FFDB5_Pos)          /*!< 0x00000020 */
#define CAN_F12FB2_FFDB5                    CAN_F12FB2_FFDB5_Msk                    /*!< Filter data bit 5 */
#define CAN_F12FB2_FFDB6_Pos                (6U)
#define CAN_F12FB2_FFDB6_Msk                (0x1U << CAN_F12FB2_FFDB6_Pos)          /*!< 0x00000040 */
#define CAN_F12FB2_FFDB6                    CAN_F12FB2_FFDB6_Msk                    /*!< Filter data bit 6 */
#define CAN_F12FB2_FFDB7_Pos                (7U)
#define CAN_F12FB2_FFDB7_Msk                (0x1U << CAN_F12FB2_FFDB7_Pos)          /*!< 0x00000080 */
#define CAN_F12FB2_FFDB7                    CAN_F12FB2_FFDB7_Msk                    /*!< Filter data bit 7 */
#define CAN_F12FB2_FFDB8_Pos                (8U)
#define CAN_F12FB2_FFDB8_Msk                (0x1U << CAN_F12FB2_FFDB8_Pos)          /*!< 0x00000100 */
#define CAN_F12FB2_FFDB8                    CAN_F12FB2_FFDB8_Msk                    /*!< Filter data bit 8 */
#define CAN_F12FB2_FFDB9_Pos                (9U)
#define CAN_F12FB2_FFDB9_Msk                (0x1U << CAN_F12FB2_FFDB9_Pos)          /*!< 0x00000200 */
#define CAN_F12FB2_FFDB9                    CAN_F12FB2_FFDB9_Msk                    /*!< Filter data bit 9 */
#define CAN_F12FB2_FFDB10_Pos               (10U)
#define CAN_F12FB2_FFDB10_Msk               (0x1U << CAN_F12FB2_FFDB10_Pos)         /*!< 0x00000400 */
#define CAN_F12FB2_FFDB10                   CAN_F12FB2_FFDB10_Msk                   /*!< Filter data bit 10 */
#define CAN_F12FB2_FFDB11_Pos               (11U)
#define CAN_F12FB2_FFDB11_Msk               (0x1U << CAN_F12FB2_FFDB11_Pos)         /*!< 0x00000800 */
#define CAN_F12FB2_FFDB11                   CAN_F12FB2_FFDB11_Msk                   /*!< Filter data bit 11 */
#define CAN_F12FB2_FFDB12_Pos               (12U)
#define CAN_F12FB2_FFDB12_Msk               (0x1U << CAN_F12FB2_FFDB12_Pos)         /*!< 0x00001000 */
#define CAN_F12FB2_FFDB12                   CAN_F12FB2_FFDB12_Msk                   /*!< Filter data bit 12 */
#define CAN_F12FB2_FFDB13_Pos               (13U)
#define CAN_F12FB2_FFDB13_Msk               (0x1U << CAN_F12FB2_FFDB13_Pos)         /*!< 0x00002000 */
#define CAN_F12FB2_FFDB13                   CAN_F12FB2_FFDB13_Msk                   /*!< Filter data bit 13 */
#define CAN_F12FB2_FFDB14_Pos               (14U)
#define CAN_F12FB2_FFDB14_Msk               (0x1U << CAN_F12FB2_FFDB14_Pos)         /*!< 0x00004000 */
#define CAN_F12FB2_FFDB14                   CAN_F12FB2_FFDB14_Msk                   /*!< Filter data bit 14 */
#define CAN_F12FB2_FFDB15_Pos               (15U)
#define CAN_F12FB2_FFDB15_Msk               (0x1U << CAN_F12FB2_FFDB15_Pos)         /*!< 0x00008000 */
#define CAN_F12FB2_FFDB15                   CAN_F12FB2_FFDB15_Msk                   /*!< Filter data bit 15 */
#define CAN_F12FB2_FFDB16_Pos               (16U)
#define CAN_F12FB2_FFDB16_Msk               (0x1U << CAN_F12FB2_FFDB16_Pos)         /*!< 0x00010000 */
#define CAN_F12FB2_FFDB16                   CAN_F12FB2_FFDB16_Msk                   /*!< Filter data bit 16 */
#define CAN_F12FB2_FFDB17_Pos               (17U)
#define CAN_F12FB2_FFDB17_Msk               (0x1U << CAN_F12FB2_FFDB17_Pos)         /*!< 0x00020000 */
#define CAN_F12FB2_FFDB17                   CAN_F12FB2_FFDB17_Msk                   /*!< Filter data bit 17 */
#define CAN_F12FB2_FFDB18_Pos               (18U)
#define CAN_F12FB2_FFDB18_Msk               (0x1U << CAN_F12FB2_FFDB18_Pos)         /*!< 0x00040000 */
#define CAN_F12FB2_FFDB18                   CAN_F12FB2_FFDB18_Msk                   /*!< Filter data bit 18 */
#define CAN_F12FB2_FFDB19_Pos               (19U)
#define CAN_F12FB2_FFDB19_Msk               (0x1U << CAN_F12FB2_FFDB19_Pos)         /*!< 0x00080000 */
#define CAN_F12FB2_FFDB19                   CAN_F12FB2_FFDB19_Msk                   /*!< Filter data bit 19 */
#define CAN_F12FB2_FFDB20_Pos               (20U)
#define CAN_F12FB2_FFDB20_Msk               (0x1U << CAN_F12FB2_FFDB20_Pos)         /*!< 0x00100000 */
#define CAN_F12FB2_FFDB20                   CAN_F12FB2_FFDB20_Msk                   /*!< Filter data bit 20 */
#define CAN_F12FB2_FFDB21_Pos               (21U)
#define CAN_F12FB2_FFDB21_Msk               (0x1U << CAN_F12FB2_FFDB21_Pos)         /*!< 0x00200000 */
#define CAN_F12FB2_FFDB21                   CAN_F12FB2_FFDB21_Msk                   /*!< Filter data bit 21 */
#define CAN_F12FB2_FFDB22_Pos               (22U)
#define CAN_F12FB2_FFDB22_Msk               (0x1U << CAN_F12FB2_FFDB22_Pos)         /*!< 0x00400000 */
#define CAN_F12FB2_FFDB22                   CAN_F12FB2_FFDB22_Msk                   /*!< Filter data bit 22 */
#define CAN_F12FB2_FFDB23_Pos               (23U)
#define CAN_F12FB2_FFDB23_Msk               (0x1U << CAN_F12FB2_FFDB23_Pos)         /*!< 0x00800000 */
#define CAN_F12FB2_FFDB23                   CAN_F12FB2_FFDB23_Msk                   /*!< Filter data bit 23 */
#define CAN_F12FB2_FFDB24_Pos               (24U)
#define CAN_F12FB2_FFDB24_Msk               (0x1U << CAN_F12FB2_FFDB24_Pos)         /*!< 0x01000000 */
#define CAN_F12FB2_FFDB24                   CAN_F12FB2_FFDB24_Msk                   /*!< Filter data bit 24 */
#define CAN_F12FB2_FFDB25_Pos               (25U)
#define CAN_F12FB2_FFDB25_Msk               (0x1U << CAN_F12FB2_FFDB25_Pos)         /*!< 0x02000000 */
#define CAN_F12FB2_FFDB25                   CAN_F12FB2_FFDB25_Msk                   /*!< Filter data bit 25 */
#define CAN_F12FB2_FFDB26_Pos               (26U)
#define CAN_F12FB2_FFDB26_Msk               (0x1U << CAN_F12FB2_FFDB26_Pos)         /*!< 0x04000000 */
#define CAN_F12FB2_FFDB26                   CAN_F12FB2_FFDB26_Msk                   /*!< Filter data bit 26 */
#define CAN_F12FB2_FFDB27_Pos               (27U)
#define CAN_F12FB2_FFDB27_Msk               (0x1U << CAN_F12FB2_FFDB27_Pos)         /*!< 0x08000000 */
#define CAN_F12FB2_FFDB27                   CAN_F12FB2_FFDB27_Msk                   /*!< Filter data bit 27 */
#define CAN_F12FB2_FFDB28_Pos               (28U)
#define CAN_F12FB2_FFDB28_Msk               (0x1U << CAN_F12FB2_FFDB28_Pos)         /*!< 0x10000000 */
#define CAN_F12FB2_FFDB28                   CAN_F12FB2_FFDB28_Msk                   /*!< Filter data bit 28 */
#define CAN_F12FB2_FFDB29_Pos               (29U)
#define CAN_F12FB2_FFDB29_Msk               (0x1U << CAN_F12FB2_FFDB29_Pos)         /*!< 0x20000000 */
#define CAN_F12FB2_FFDB29                   CAN_F12FB2_FFDB29_Msk                   /*!< Filter data bit 29 */
#define CAN_F12FB2_FFDB30_Pos               (30U)
#define CAN_F12FB2_FFDB30_Msk               (0x1U << CAN_F12FB2_FFDB30_Pos)         /*!< 0x40000000 */
#define CAN_F12FB2_FFDB30                   CAN_F12FB2_FFDB30_Msk                   /*!< Filter data bit 30 */
#define CAN_F12FB2_FFDB31_Pos               (31U)
#define CAN_F12FB2_FFDB31_Msk               (0x1U << CAN_F12FB2_FFDB31_Pos)         /*!< 0x80000000 */
#define CAN_F12FB2_FFDB31                   CAN_F12FB2_FFDB31_Msk                   /*!< Filter data bit 31 */

/******************  Bit definition for CAN_F13FB2 register  ******************/
#define CAN_F13FB2_FFDB0_Pos                (0U)
#define CAN_F13FB2_FFDB0_Msk                (0x1U << CAN_F13FB2_FFDB0_Pos)          /*!< 0x00000001 */
#define CAN_F13FB2_FFDB0                    CAN_F13FB2_FFDB0_Msk                    /*!< Filter data bit 0 */
#define CAN_F13FB2_FFDB1_Pos                (1U)
#define CAN_F13FB2_FFDB1_Msk                (0x1U << CAN_F13FB2_FFDB1_Pos)          /*!< 0x00000002 */
#define CAN_F13FB2_FFDB1                    CAN_F13FB2_FFDB1_Msk                    /*!< Filter data bit 1 */
#define CAN_F13FB2_FFDB2_Pos                (2U)
#define CAN_F13FB2_FFDB2_Msk                (0x1U << CAN_F13FB2_FFDB2_Pos)          /*!< 0x00000004 */
#define CAN_F13FB2_FFDB2                    CAN_F13FB2_FFDB2_Msk                    /*!< Filter data bit 2 */
#define CAN_F13FB2_FFDB3_Pos                (3U)
#define CAN_F13FB2_FFDB3_Msk                (0x1U << CAN_F13FB2_FFDB3_Pos)          /*!< 0x00000008 */
#define CAN_F13FB2_FFDB3                    CAN_F13FB2_FFDB3_Msk                    /*!< Filter data bit 3 */
#define CAN_F13FB2_FFDB4_Pos                (4U)
#define CAN_F13FB2_FFDB4_Msk                (0x1U << CAN_F13FB2_FFDB4_Pos)          /*!< 0x00000010 */
#define CAN_F13FB2_FFDB4                    CAN_F13FB2_FFDB4_Msk                    /*!< Filter data bit 4 */
#define CAN_F13FB2_FFDB5_Pos                (5U)
#define CAN_F13FB2_FFDB5_Msk                (0x1U << CAN_F13FB2_FFDB5_Pos)          /*!< 0x00000020 */
#define CAN_F13FB2_FFDB5                    CAN_F13FB2_FFDB5_Msk                    /*!< Filter data bit 5 */
#define CAN_F13FB2_FFDB6_Pos                (6U)
#define CAN_F13FB2_FFDB6_Msk                (0x1U << CAN_F13FB2_FFDB6_Pos)          /*!< 0x00000040 */
#define CAN_F13FB2_FFDB6                    CAN_F13FB2_FFDB6_Msk                    /*!< Filter data bit 6 */
#define CAN_F13FB2_FFDB7_Pos                (7U)
#define CAN_F13FB2_FFDB7_Msk                (0x1U << CAN_F13FB2_FFDB7_Pos)          /*!< 0x00000080 */
#define CAN_F13FB2_FFDB7                    CAN_F13FB2_FFDB7_Msk                    /*!< Filter data bit 7 */
#define CAN_F13FB2_FFDB8_Pos                (8U)
#define CAN_F13FB2_FFDB8_Msk                (0x1U << CAN_F13FB2_FFDB8_Pos)          /*!< 0x00000100 */
#define CAN_F13FB2_FFDB8                    CAN_F13FB2_FFDB8_Msk                    /*!< Filter data bit 8 */
#define CAN_F13FB2_FFDB9_Pos                (9U)
#define CAN_F13FB2_FFDB9_Msk                (0x1U << CAN_F13FB2_FFDB9_Pos)          /*!< 0x00000200 */
#define CAN_F13FB2_FFDB9                    CAN_F13FB2_FFDB9_Msk                    /*!< Filter data bit 9 */
#define CAN_F13FB2_FFDB10_Pos               (10U)
#define CAN_F13FB2_FFDB10_Msk               (0x1U << CAN_F13FB2_FFDB10_Pos)         /*!< 0x00000400 */
#define CAN_F13FB2_FFDB10                   CAN_F13FB2_FFDB10_Msk                   /*!< Filter data bit 10 */
#define CAN_F13FB2_FFDB11_Pos               (11U)
#define CAN_F13FB2_FFDB11_Msk               (0x1U << CAN_F13FB2_FFDB11_Pos)         /*!< 0x00000800 */
#define CAN_F13FB2_FFDB11                   CAN_F13FB2_FFDB11_Msk                   /*!< Filter data bit 11 */
#define CAN_F13FB2_FFDB12_Pos               (12U)
#define CAN_F13FB2_FFDB12_Msk               (0x1U << CAN_F13FB2_FFDB12_Pos)         /*!< 0x00001000 */
#define CAN_F13FB2_FFDB12                   CAN_F13FB2_FFDB12_Msk                   /*!< Filter data bit 12 */
#define CAN_F13FB2_FFDB13_Pos               (13U)
#define CAN_F13FB2_FFDB13_Msk               (0x1U << CAN_F13FB2_FFDB13_Pos)         /*!< 0x00002000 */
#define CAN_F13FB2_FFDB13                   CAN_F13FB2_FFDB13_Msk                   /*!< Filter data bit 13 */
#define CAN_F13FB2_FFDB14_Pos               (14U)
#define CAN_F13FB2_FFDB14_Msk               (0x1U << CAN_F13FB2_FFDB14_Pos)         /*!< 0x00004000 */
#define CAN_F13FB2_FFDB14                   CAN_F13FB2_FFDB14_Msk                   /*!< Filter data bit 14 */
#define CAN_F13FB2_FFDB15_Pos               (15U)
#define CAN_F13FB2_FFDB15_Msk               (0x1U << CAN_F13FB2_FFDB15_Pos)         /*!< 0x00008000 */
#define CAN_F13FB2_FFDB15                   CAN_F13FB2_FFDB15_Msk                   /*!< Filter data bit 15 */
#define CAN_F13FB2_FFDB16_Pos               (16U)
#define CAN_F13FB2_FFDB16_Msk               (0x1U << CAN_F13FB2_FFDB16_Pos)         /*!< 0x00010000 */
#define CAN_F13FB2_FFDB16                   CAN_F13FB2_FFDB16_Msk                   /*!< Filter data bit 16 */
#define CAN_F13FB2_FFDB17_Pos               (17U)
#define CAN_F13FB2_FFDB17_Msk               (0x1U << CAN_F13FB2_FFDB17_Pos)         /*!< 0x00020000 */
#define CAN_F13FB2_FFDB17                   CAN_F13FB2_FFDB17_Msk                   /*!< Filter data bit 17 */
#define CAN_F13FB2_FFDB18_Pos               (18U)
#define CAN_F13FB2_FFDB18_Msk               (0x1U << CAN_F13FB2_FFDB18_Pos)         /*!< 0x00040000 */
#define CAN_F13FB2_FFDB18                   CAN_F13FB2_FFDB18_Msk                   /*!< Filter data bit 18 */
#define CAN_F13FB2_FFDB19_Pos               (19U)
#define CAN_F13FB2_FFDB19_Msk               (0x1U << CAN_F13FB2_FFDB19_Pos)         /*!< 0x00080000 */
#define CAN_F13FB2_FFDB19                   CAN_F13FB2_FFDB19_Msk                   /*!< Filter data bit 19 */
#define CAN_F13FB2_FFDB20_Pos               (20U)
#define CAN_F13FB2_FFDB20_Msk               (0x1U << CAN_F13FB2_FFDB20_Pos)         /*!< 0x00100000 */
#define CAN_F13FB2_FFDB20                   CAN_F13FB2_FFDB20_Msk                   /*!< Filter data bit 20 */
#define CAN_F13FB2_FFDB21_Pos               (21U)
#define CAN_F13FB2_FFDB21_Msk               (0x1U << CAN_F13FB2_FFDB21_Pos)         /*!< 0x00200000 */
#define CAN_F13FB2_FFDB21                   CAN_F13FB2_FFDB21_Msk                   /*!< Filter data bit 21 */
#define CAN_F13FB2_FFDB22_Pos               (22U)
#define CAN_F13FB2_FFDB22_Msk               (0x1U << CAN_F13FB2_FFDB22_Pos)         /*!< 0x00400000 */
#define CAN_F13FB2_FFDB22                   CAN_F13FB2_FFDB22_Msk                   /*!< Filter data bit 22 */
#define CAN_F13FB2_FFDB23_Pos               (23U)
#define CAN_F13FB2_FFDB23_Msk               (0x1U << CAN_F13FB2_FFDB23_Pos)         /*!< 0x00800000 */
#define CAN_F13FB2_FFDB23                   CAN_F13FB2_FFDB23_Msk                   /*!< Filter data bit 23 */
#define CAN_F13FB2_FFDB24_Pos               (24U)
#define CAN_F13FB2_FFDB24_Msk               (0x1U << CAN_F13FB2_FFDB24_Pos)         /*!< 0x01000000 */
#define CAN_F13FB2_FFDB24                   CAN_F13FB2_FFDB24_Msk                   /*!< Filter data bit 24 */
#define CAN_F13FB2_FFDB25_Pos               (25U)
#define CAN_F13FB2_FFDB25_Msk               (0x1U << CAN_F13FB2_FFDB25_Pos)         /*!< 0x02000000 */
#define CAN_F13FB2_FFDB25                   CAN_F13FB2_FFDB25_Msk                   /*!< Filter data bit 25 */
#define CAN_F13FB2_FFDB26_Pos               (26U)
#define CAN_F13FB2_FFDB26_Msk               (0x1U << CAN_F13FB2_FFDB26_Pos)         /*!< 0x04000000 */
#define CAN_F13FB2_FFDB26                   CAN_F13FB2_FFDB26_Msk                   /*!< Filter data bit 26 */
#define CAN_F13FB2_FFDB27_Pos               (27U)
#define CAN_F13FB2_FFDB27_Msk               (0x1U << CAN_F13FB2_FFDB27_Pos)         /*!< 0x08000000 */
#define CAN_F13FB2_FFDB27                   CAN_F13FB2_FFDB27_Msk                   /*!< Filter data bit 27 */
#define CAN_F13FB2_FFDB28_Pos               (28U)
#define CAN_F13FB2_FFDB28_Msk               (0x1U << CAN_F13FB2_FFDB28_Pos)         /*!< 0x10000000 */
#define CAN_F13FB2_FFDB28                   CAN_F13FB2_FFDB28_Msk                   /*!< Filter data bit 28 */
#define CAN_F13FB2_FFDB29_Pos               (29U)
#define CAN_F13FB2_FFDB29_Msk               (0x1U << CAN_F13FB2_FFDB29_Pos)         /*!< 0x20000000 */
#define CAN_F13FB2_FFDB29                   CAN_F13FB2_FFDB29_Msk                   /*!< Filter data bit 29 */
#define CAN_F13FB2_FFDB30_Pos               (30U)
#define CAN_F13FB2_FFDB30_Msk               (0x1U << CAN_F13FB2_FFDB30_Pos)         /*!< 0x40000000 */
#define CAN_F13FB2_FFDB30                   CAN_F13FB2_FFDB30_Msk                   /*!< Filter data bit 30 */
#define CAN_F13FB2_FFDB31_Pos               (31U)
#define CAN_F13FB2_FFDB31_Msk               (0x1U << CAN_F13FB2_FFDB31_Pos)         /*!< 0x80000000 */
#define CAN_F13FB2_FFDB31                   CAN_F13FB2_FFDB31_Msk                   /*!< Filter data bit 31 */

/******************************************************************************/
/*                                                                            */
/*                   SD/SDIO MMC card host interface (SDIO)                   */
/*                                                                            */
/******************************************************************************/

/*****************  Bit definition for SDIO_PWRCTRL register  *****************/
#define SDIO_PWRCTRL_PS_Pos                 (0U)
#define SDIO_PWRCTRL_PS_Msk                 (0x3U << SDIO_PWRCTRL_PS_Pos)           /*!< 0x00000003 */
#define SDIO_PWRCTRL_PS                     SDIO_PWRCTRL_PS_Msk                     /*!< PS[1:0] bits (Power switch) */
#define SDIO_PWRCTRL_PS_0                   (0x1U << SDIO_PWRCTRL_PS_Pos)           /*!< 0x00000001 */
#define SDIO_PWRCTRL_PS_1                   (0x2U << SDIO_PWRCTRL_PS_Pos)           /*!< 0x00000002 */

/*****************  Bit definition for SDIO_CLKCTRL register  *****************/
#define SDIO_CLKCTRL_CLKDIV_Msk             ((0xFFU << 0) | (0x3U << 15))           /*!< 0x000180FF */
#define SDIO_CLKCTRL_CLKDIV                 SDIO_CLKCTRL_CLKDIV_Msk                 /*!< CLKDIV[9:0] bits (Clock division) */
#define SDIO_CLKCTRL_CLKOEN_Pos             (8U)
#define SDIO_CLKCTRL_CLKOEN_Msk             (0x1U << SDIO_CLKCTRL_CLKOEN_Pos)       /*!< 0x00000100 */
#define SDIO_CLKCTRL_CLKOEN                 SDIO_CLKCTRL_CLKOEN_Msk                 /*!< Clock output enable */
#define SDIO_CLKCTRL_PWRSVEN_Pos            (9U)
#define SDIO_CLKCTRL_PWRSVEN_Msk            (0x1U << SDIO_CLKCTRL_PWRSVEN_Pos)      /*!< 0x00000200 */
#define SDIO_CLKCTRL_PWRSVEN                SDIO_CLKCTRL_PWRSVEN_Msk                /*!< Power saving mode enable */
#define SDIO_CLKCTRL_BYPSEN_Pos             (10U)
#define SDIO_CLKCTRL_BYPSEN_Msk             (0x1U << SDIO_CLKCTRL_BYPSEN_Pos)       /*!< 0x00000400 */
#define SDIO_CLKCTRL_BYPSEN                 SDIO_CLKCTRL_BYPSEN_Msk                 /*!< Clock divider bypass enable bit */

#define SDIO_CLKCTRL_BUSWS_Pos              (11U)
#define SDIO_CLKCTRL_BUSWS_Msk              (0x3U << SDIO_CLKCTRL_BUSWS_Pos)        /*!< 0x00001800 */
#define SDIO_CLKCTRL_BUSWS                  SDIO_CLKCTRL_BUSWS_Msk                  /*!< BUSWS[1:0] bits (Bus width selection) */
#define SDIO_CLKCTRL_BUSWS_0                (0x1U << SDIO_CLKCTRL_BUSWS_Pos)        /*!< 0x00000800 */
#define SDIO_CLKCTRL_BUSWS_1                (0x2U << SDIO_CLKCTRL_BUSWS_Pos)        /*!< 0x00001000 */

#define SDIO_CLKCTRL_CLKEGS_Pos             (13U)
#define SDIO_CLKCTRL_CLKEGS_Msk             (0x1U << SDIO_CLKCTRL_CLKEGS_Pos)       /*!< 0x00002000 */
#define SDIO_CLKCTRL_CLKEGS                 SDIO_CLKCTRL_CLKEGS_Msk                 /*!< SDIO_CK edge selection */
#define SDIO_CLKCTRL_HFCEN_Pos              (14U)
#define SDIO_CLKCTRL_HFCEN_Msk              (0x1U << SDIO_CLKCTRL_HFCEN_Pos)        /*!< 0x00004000 */
#define SDIO_CLKCTRL_HFCEN                  SDIO_CLKCTRL_HFCEN_Msk                  /*!< Hardware flow control enable */

/*******************  Bit definition for SDIO_ARG register  *******************/
#define SDIO_ARG_ARGU_Pos                   (0U)
#define SDIO_ARG_ARGU_Msk                   (0xFFFFFFFFU << SDIO_ARG_ARGU_Pos)      /*!< 0xFFFFFFFF */
#define SDIO_ARG_ARGU                       SDIO_ARG_ARGU_Msk                       /*!< Command argument */

/*******************  Bit definition for SDIO_CMD register  *******************/
#define SDIO_CMD_CMDIDX_Pos                 (0U)
#define SDIO_CMD_CMDIDX_Msk                 (0x3FU << SDIO_CMD_CMDIDX_Pos)          /*!< 0x0000003F */
#define SDIO_CMD_CMDIDX                     SDIO_CMD_CMDIDX_Msk                     /*!< Command index */

#define SDIO_CMD_RSPWT_Pos                  (6U)
#define SDIO_CMD_RSPWT_Msk                  (0x3U << SDIO_CMD_RSPWT_Pos)            /*!< 0x000000C0 */
#define SDIO_CMD_RSPWT                      SDIO_CMD_RSPWT_Msk                      /*!< RSPWT[1:0] bits (Wait for response bits) */
#define SDIO_CMD_RSPWT_0                    (0x1U << SDIO_CMD_RSPWT_Pos)            /*!< 0x00000040 */
#define SDIO_CMD_RSPWT_1                    (0x2U << SDIO_CMD_RSPWT_Pos)            /*!< 0x00000080 */

#define SDIO_CMD_INTWT_Pos                  (8U)
#define SDIO_CMD_INTWT_Msk                  (0x1U << SDIO_CMD_INTWT_Pos)            /*!< 0x00000100 */
#define SDIO_CMD_INTWT                      SDIO_CMD_INTWT_Msk                      /*!< CCSM waits for interrupt request */
#define SDIO_CMD_PNDWT_Pos                  (9U)
#define SDIO_CMD_PNDWT_Msk                  (0x1U << SDIO_CMD_PNDWT_Pos)            /*!< 0x00000200 */
#define SDIO_CMD_PNDWT                      SDIO_CMD_PNDWT_Msk                      /*!< CCSM Waits for ends of data transfer (CmdPend internal signal) */
#define SDIO_CMD_CCSMEN_Pos                 (10U)
#define SDIO_CMD_CCSMEN_Msk                 (0x1U << SDIO_CMD_CCSMEN_Pos)           /*!< 0x00000400 */
#define SDIO_CMD_CCSMEN                     SDIO_CMD_CCSMEN_Msk                     /*!< Command channel state machine (CCSM) enable bit */
#define SDIO_CMD_IOSUSP_Pos                 (11U)
#define SDIO_CMD_IOSUSP_Msk                 (0x1U << SDIO_CMD_IOSUSP_Pos)           /*!< 0x00000800 */
#define SDIO_CMD_IOSUSP                     SDIO_CMD_IOSUSP_Msk                     /*!< SD I/O suspend command */

/*****************  Bit definition for SDIO_RSPCMD register  ******************/
#define SDIO_RSPCMD_RSPCMD_Pos              (0U)
#define SDIO_RSPCMD_RSPCMD_Msk              (0x3FU << SDIO_RSPCMD_RSPCMD_Pos)       /*!< 0x0000003F */
#define SDIO_RSPCMD_RSPCMD                  SDIO_RSPCMD_RSPCMD_Msk                  /*!< Response command index */

/******************  Bit definition for SDIO_RSP1 register  *******************/
#define SDIO_RSP1_CARDSTS1_Pos              (0U)
#define SDIO_RSP1_CARDSTS1_Msk              (0xFFFFFFFFU << SDIO_RSP1_CARDSTS1_Pos) /*!< 0xFFFFFFFF */
#define SDIO_RSP1_CARDSTS1                  SDIO_RSP1_CARDSTS1_Msk                  /*!< Card status */

/******************  Bit definition for SDIO_RSP2 register  *******************/
#define SDIO_RSP2_CARDSTS2_Pos              (0U)
#define SDIO_RSP2_CARDSTS2_Msk              (0xFFFFFFFFU << SDIO_RSP2_CARDSTS2_Pos) /*!< 0xFFFFFFFF */
#define SDIO_RSP2_CARDSTS2                  SDIO_RSP2_CARDSTS2_Msk                  /*!< Card status */

/******************  Bit definition for SDIO_RSP3 register  *******************/
#define SDIO_RSP3_CARDSTS3_Pos              (0U)
#define SDIO_RSP3_CARDSTS3_Msk              (0xFFFFFFFFU << SDIO_RSP3_CARDSTS3_Pos) /*!< 0xFFFFFFFF */
#define SDIO_RSP3_CARDSTS3                  SDIO_RSP3_CARDSTS3_Msk                  /*!< Card status */

/******************  Bit definition for SDIO_RSP4 register  *******************/
#define SDIO_RSP4_CARDSTS4_Pos              (0U)
#define SDIO_RSP4_CARDSTS4_Msk              (0xFFFFFFFFU << SDIO_RSP4_CARDSTS4_Pos) /*!< 0xFFFFFFFF */
#define SDIO_RSP4_CARDSTS4                  SDIO_RSP4_CARDSTS4_Msk                  /*!< Card status */

/******************  Bit definition for SDIO_DTTMR register  ******************/
#define SDIO_DTTMR_TIMEOUT_Pos              (0U)
#define SDIO_DTTMR_TIMEOUT_Msk              (0xFFFFFFFFU << SDIO_DTTMR_TIMEOUT_Pos) /*!< 0xFFFFFFFF */
#define SDIO_DTTMR_TIMEOUT                  SDIO_DTTMR_TIMEOUT_Msk                  /*!< Data timeout period */

/******************  Bit definition for SDIO_DTLEN register  ******************/
#define SDIO_DTLEN_DTLEN_Pos                (0U)                               
#define SDIO_DTLEN_DTLEN_Msk                (0x1FFFFFFU << SDIO_DTLEN_DTLEN_Pos)    /*!< 0x01FFFFFF */
#define SDIO_DTLEN_DTLEN                    SDIO_DTLEN_DTLEN_Msk                    /*!< Data length value */

/*****************  Bit definition for SDIO_DTCTRL register  ******************/
#define SDIO_DTCTRL_TFREN_Pos               (0U)
#define SDIO_DTCTRL_TFREN_Msk               (0x1U << SDIO_DTCTRL_TFREN_Pos)         /*!< 0x00000001 */
#define SDIO_DTCTRL_TFREN                   SDIO_DTCTRL_TFREN_Msk                   /*!< Data transfer enabled bit */
#define SDIO_DTCTRL_TFRDIR_Pos              (1U)
#define SDIO_DTCTRL_TFRDIR_Msk              (0x1U << SDIO_DTCTRL_TFRDIR_Pos)        /*!< 0x00000002 */
#define SDIO_DTCTRL_TFRDIR                  SDIO_DTCTRL_TFRDIR_Msk                  /*!< Data transfer direction selection */
#define SDIO_DTCTRL_TFRMODE_Pos             (2U)
#define SDIO_DTCTRL_TFRMODE_Msk             (0x1U << SDIO_DTCTRL_TFRMODE_Pos)       /*!< 0x00000004 */
#define SDIO_DTCTRL_TFRMODE                 SDIO_DTCTRL_TFRMODE_Msk                 /*!< Data transfer mode selection */
#define SDIO_DTCTRL_DMAEN_Pos               (3U)
#define SDIO_DTCTRL_DMAEN_Msk               (0x1U << SDIO_DTCTRL_DMAEN_Pos)         /*!< 0x00000008 */
#define SDIO_DTCTRL_DMAEN                   SDIO_DTCTRL_DMAEN_Msk                   /*!< DMA enable bit */

#define SDIO_DTCTRL_BLKSIZE_Pos             (4U)
#define SDIO_DTCTRL_BLKSIZE_Msk             (0xFU << SDIO_DTCTRL_BLKSIZE_Pos)       /*!< 0x000000F0 */
#define SDIO_DTCTRL_BLKSIZE                 SDIO_DTCTRL_BLKSIZE_Msk                 /*!< BLKSIZE[3:0] bits (Data block size) */
#define SDIO_DTCTRL_BLKSIZE_0               (0x1U << SDIO_DTCTRL_BLKSIZE_Pos)       /*!< 0x00000010 */
#define SDIO_DTCTRL_BLKSIZE_1               (0x2U << SDIO_DTCTRL_BLKSIZE_Pos)       /*!< 0x00000020 */
#define SDIO_DTCTRL_BLKSIZE_2               (0x4U << SDIO_DTCTRL_BLKSIZE_Pos)       /*!< 0x00000040 */
#define SDIO_DTCTRL_BLKSIZE_3               (0x8U << SDIO_DTCTRL_BLKSIZE_Pos)       /*!< 0x00000080 */

#define SDIO_DTCTRL_RDWTSTART_Pos           (8U)
#define SDIO_DTCTRL_RDWTSTART_Msk           (0x1U << SDIO_DTCTRL_RDWTSTART_Pos)     /*!< 0x00000100 */
#define SDIO_DTCTRL_RDWTSTART               SDIO_DTCTRL_RDWTSTART_Msk               /*!< Read wait start */
#define SDIO_DTCTRL_RDWTSTOP_Pos            (9U)
#define SDIO_DTCTRL_RDWTSTOP_Msk            (0x1U << SDIO_DTCTRL_RDWTSTOP_Pos)      /*!< 0x00000200 */
#define SDIO_DTCTRL_RDWTSTOP                SDIO_DTCTRL_RDWTSTOP_Msk                /*!< Read wait stop */
#define SDIO_DTCTRL_RDWTMODE_Pos            (10U)
#define SDIO_DTCTRL_RDWTMODE_Msk            (0x1U << SDIO_DTCTRL_RDWTMODE_Pos)      /*!< 0x00000400 */
#define SDIO_DTCTRL_RDWTMODE                SDIO_DTCTRL_RDWTMODE_Msk                /*!< Read wait mode */
#define SDIO_DTCTRL_IOEN_Pos                (11U)
#define SDIO_DTCTRL_IOEN_Msk                (0x1U << SDIO_DTCTRL_IOEN_Pos)          /*!< 0x00000800 */
#define SDIO_DTCTRL_IOEN                    SDIO_DTCTRL_IOEN_Msk                    /*!< SD I/O enable functions */

/*****************  Bit definition for SDIO_DTCNTR register  ******************/
#define SDIO_DTCNTR_CNT_Pos                 (0U)
#define SDIO_DTCNTR_CNT_Msk                 (0x1FFFFFFU << SDIO_DTCNTR_CNT_Pos)     /*!< 0x01FFFFFF */
#define SDIO_DTCNTR_CNT                     SDIO_DTCNTR_CNT_Msk                     /*!< Data count value */

/*******************  Bit definition for SDIO_STS register  *******************/
#define SDIO_STS_CMDFAIL_Pos                (0U)
#define SDIO_STS_CMDFAIL_Msk                (0x1U << SDIO_STS_CMDFAIL_Pos)          /*!< 0x00000001 */
#define SDIO_STS_CMDFAIL                    SDIO_STS_CMDFAIL_Msk                    /*!< Command response received (CRC check failed) */
#define SDIO_STS_DTFAIL_Pos                 (1U)
#define SDIO_STS_DTFAIL_Msk                 (0x1U << SDIO_STS_DTFAIL_Pos)           /*!< 0x00000002 */
#define SDIO_STS_DTFAIL                     SDIO_STS_DTFAIL_Msk                     /*!< Data block sent/received (CRC check failed) */
#define SDIO_STS_CMDTIMEOUT_Pos             (2U)
#define SDIO_STS_CMDTIMEOUT_Msk             (0x1U << SDIO_STS_CMDTIMEOUT_Pos)       /*!< 0x00000004 */
#define SDIO_STS_CMDTIMEOUT                 SDIO_STS_CMDTIMEOUT_Msk                 /*!< Command response timeout */
#define SDIO_STS_DTTIMEOUT_Pos              (3U)
#define SDIO_STS_DTTIMEOUT_Msk              (0x1U << SDIO_STS_DTTIMEOUT_Pos)        /*!< 0x00000008 */
#define SDIO_STS_DTTIMEOUT                  SDIO_STS_DTTIMEOUT_Msk                  /*!< Data timeout */
#define SDIO_STS_TXERRU_Pos                 (4U)
#define SDIO_STS_TXERRU_Msk                 (0x1U << SDIO_STS_TXERRU_Pos)           /*!< 0x00000010 */
#define SDIO_STS_TXERRU                     SDIO_STS_TXERRU_Msk                     /*!< Transmit BUF underrun error */
#define SDIO_STS_RXERRO_Pos                 (5U)
#define SDIO_STS_RXERRO_Msk                 (0x1U << SDIO_STS_RXERRO_Pos)           /*!< 0x00000020 */
#define SDIO_STS_RXERRO                     SDIO_STS_RXERRO_Msk                     /*!< Received BUF overrun error */
#define SDIO_STS_CMDRSPCMPL_Pos             (6U)
#define SDIO_STS_CMDRSPCMPL_Msk             (0x1U << SDIO_STS_CMDRSPCMPL_Pos)       /*!< 0x00000040 */
#define SDIO_STS_CMDRSPCMPL                 SDIO_STS_CMDRSPCMPL_Msk                 /*!< Command response (CRC check passed) */
#define SDIO_STS_CMDCMPL_Pos                (7U)
#define SDIO_STS_CMDCMPL_Msk                (0x1U << SDIO_STS_CMDCMPL_Pos)          /*!< 0x00000080 */
#define SDIO_STS_CMDCMPL                    SDIO_STS_CMDCMPL_Msk                    /*!< Command sent (no response required) */
#define SDIO_STS_DTCMPL_Pos                 (8U)
#define SDIO_STS_DTCMPL_Msk                 (0x1U << SDIO_STS_DTCMPL_Pos)           /*!< 0x00000100 */
#define SDIO_STS_DTCMPL                     SDIO_STS_DTCMPL_Msk                     /*!< Data end (data counter, SDIO CNT, is zero) */
#define SDIO_STS_SBITERR_Pos                (9U)
#define SDIO_STS_SBITERR_Msk                (0x1U << SDIO_STS_SBITERR_Pos)          /*!< 0x00000200 */
#define SDIO_STS_SBITERR                    SDIO_STS_SBITERR_Msk                    /*!< Start bit not detected on all data signals in wide bus mode */
#define SDIO_STS_DTBLKCMPL_Pos              (10U)
#define SDIO_STS_DTBLKCMPL_Msk              (0x1U << SDIO_STS_DTBLKCMPL_Pos)        /*!< 0x00000400 */
#define SDIO_STS_DTBLKCMPL                  SDIO_STS_DTBLKCMPL_Msk                  /*!< Data block sent/received (CRC check passed) */
#define SDIO_STS_DOCMD_Pos                  (11U)
#define SDIO_STS_DOCMD_Msk                  (0x1U << SDIO_STS_DOCMD_Pos)            /*!< 0x00000800 */
#define SDIO_STS_DOCMD                      SDIO_STS_DOCMD_Msk                      /*!< Command transfer in progress */
#define SDIO_STS_DOTX_Pos                   (12U)
#define SDIO_STS_DOTX_Msk                   (0x1U << SDIO_STS_DOTX_Pos)             /*!< 0x00001000 */
#define SDIO_STS_DOTX                       SDIO_STS_DOTX_Msk                       /*!< Data transmit in progress */
#define SDIO_STS_DORX_Pos                   (13U)
#define SDIO_STS_DORX_Msk                   (0x1U << SDIO_STS_DORX_Pos)             /*!< 0x00002000 */
#define SDIO_STS_DORX                       SDIO_STS_DORX_Msk                       /*!< Data receive in progress */
#define SDIO_STS_TXBUFH_Pos                 (14U)
#define SDIO_STS_TXBUFH_Msk                 (0x1U << SDIO_STS_TXBUFH_Pos)           /*!< 0x00004000 */
#define SDIO_STS_TXBUFH                     SDIO_STS_TXBUFH_Msk                     /*!< Transmit BUF half empty: At least 8 words can be written to the BUF */
#define SDIO_STS_RXBUFH_Pos                 (15U)
#define SDIO_STS_RXBUFH_Msk                 (0x1U << SDIO_STS_RXBUFH_Pos)           /*!< 0x00008000 */
#define SDIO_STS_RXBUFH                     SDIO_STS_RXBUFH_Msk                     /*!< Receive BUF half full: There are at least 8 words in the BUF */
#define SDIO_STS_TXBUFF_Pos                 (16U)
#define SDIO_STS_TXBUFF_Msk                 (0x1U << SDIO_STS_TXBUFF_Pos)           /*!< 0x00010000 */
#define SDIO_STS_TXBUFF                     SDIO_STS_TXBUFF_Msk                     /*!< Transmit BUF full */
#define SDIO_STS_RXBUFF_Pos                 (17U)
#define SDIO_STS_RXBUFF_Msk                 (0x1U << SDIO_STS_RXBUFF_Pos)           /*!< 0x00020000 */
#define SDIO_STS_RXBUFF                     SDIO_STS_RXBUFF_Msk                     /*!< Receive BUF full */
#define SDIO_STS_TXBUFE_Pos                 (18U)
#define SDIO_STS_TXBUFE_Msk                 (0x1U << SDIO_STS_TXBUFE_Pos)           /*!< 0x00040000 */
#define SDIO_STS_TXBUFE                     SDIO_STS_TXBUFE_Msk                     /*!< Transmit BUF empty */
#define SDIO_STS_RXBUFE_Pos                 (19U)
#define SDIO_STS_RXBUFE_Msk                 (0x1U << SDIO_STS_RXBUFE_Pos)           /*!< 0x00080000 */
#define SDIO_STS_RXBUFE                     SDIO_STS_RXBUFE_Msk                     /*!< Receive BUF empty */
#define SDIO_STS_TXBUF_Pos                  (20U)
#define SDIO_STS_TXBUF_Msk                  (0x1U << SDIO_STS_TXBUF_Pos)            /*!< 0x00100000 */
#define SDIO_STS_TXBUF                      SDIO_STS_TXBUF_Msk                      /*!< Data available in transmit BUF */
#define SDIO_STS_RXBUF_Pos                  (21U)
#define SDIO_STS_RXBUF_Msk                  (0x1U << SDIO_STS_RXBUF_Pos)            /*!< 0x00200000 */
#define SDIO_STS_RXBUF                      SDIO_STS_RXBUF_Msk                      /*!< Data available in receive BUF */
#define SDIO_STS_IOIF_Pos                   (22U)
#define SDIO_STS_IOIF_Msk                   (0x1U << SDIO_STS_IOIF_Pos)             /*!< 0x00400000 */
#define SDIO_STS_IOIF                       SDIO_STS_IOIF_Msk                       /*!< SD I/O interrupt received */

/*****************  Bit definition for SDIO_INTCLR register  ******************/
#define SDIO_INTCLR_CMDFAIL_Pos             (0U)
#define SDIO_INTCLR_CMDFAIL_Msk             (0x1U << SDIO_INTCLR_CMDFAIL_Pos)       /*!< 0x00000001 */
#define SDIO_INTCLR_CMDFAIL                 SDIO_INTCLR_CMDFAIL_Msk                 /*!< CMDFAIL flag clear bit */
#define SDIO_INTCLR_DTFAIL_Pos              (1U)
#define SDIO_INTCLR_DTFAIL_Msk              (0x1U << SDIO_INTCLR_DTFAIL_Pos)        /*!< 0x00000002 */
#define SDIO_INTCLR_DTFAIL                  SDIO_INTCLR_DTFAIL_Msk                  /*!< DTFAIL flag clear bit */
#define SDIO_INTCLR_CMDTIMEOUT_Pos          (2U)
#define SDIO_INTCLR_CMDTIMEOUT_Msk          (0x1U << SDIO_INTCLR_CMDTIMEOUT_Pos)    /*!< 0x00000004 */
#define SDIO_INTCLR_CMDTIMEOUT              SDIO_INTCLR_CMDTIMEOUT_Msk              /*!< CMDTIMEOUT flag clear bit */
#define SDIO_INTCLR_DTTIMEOUT_Pos           (3U)
#define SDIO_INTCLR_DTTIMEOUT_Msk           (0x1U << SDIO_INTCLR_DTTIMEOUT_Pos)     /*!< 0x00000008 */
#define SDIO_INTCLR_DTTIMEOUT               SDIO_INTCLR_DTTIMEOUT_Msk               /*!< DTTIMEOUT flag clear bit */
#define SDIO_INTCLR_TXERRU_Pos              (4U)
#define SDIO_INTCLR_TXERRU_Msk              (0x1U << SDIO_INTCLR_TXERRU_Pos)        /*!< 0x00000010 */
#define SDIO_INTCLR_TXERRU                  SDIO_INTCLR_TXERRU_Msk                  /*!< TXERRU flag clear bit */
#define SDIO_INTCLR_RXERRO_Pos              (5U)
#define SDIO_INTCLR_RXERRO_Msk              (0x1U << SDIO_INTCLR_RXERRO_Pos)        /*!< 0x00000020 */
#define SDIO_INTCLR_RXERRO                  SDIO_INTCLR_RXERRO_Msk                  /*!< RXERRO flag clear bit */
#define SDIO_INTCLR_CMDRSPCMPL_Pos          (6U)
#define SDIO_INTCLR_CMDRSPCMPL_Msk          (0x1U << SDIO_INTCLR_CMDRSPCMPL_Pos)    /*!< 0x00000040 */
#define SDIO_INTCLR_CMDRSPCMPL              SDIO_INTCLR_CMDRSPCMPL_Msk              /*!< CMDRSPCMPL flag clear bit */
#define SDIO_INTCLR_CMDCMPL_Pos             (7U)
#define SDIO_INTCLR_CMDCMPL_Msk             (0x1U << SDIO_INTCLR_CMDCMPL_Pos)       /*!< 0x00000080 */
#define SDIO_INTCLR_CMDCMPL                 SDIO_INTCLR_CMDCMPL_Msk                 /*!< CMDCMPL flag clear bit */
#define SDIO_INTCLR_DTCMPL_Pos              (8U)
#define SDIO_INTCLR_DTCMPL_Msk              (0x1U << SDIO_INTCLR_DTCMPL_Pos)        /*!< 0x00000100 */
#define SDIO_INTCLR_DTCMPL                  SDIO_INTCLR_DTCMPL_Msk                  /*!< DTCMPL flag clear bit */
#define SDIO_INTCLR_SBITERR_Pos             (9U)
#define SDIO_INTCLR_SBITERR_Msk             (0x1U << SDIO_INTCLR_SBITERR_Pos)       /*!< 0x00000200 */
#define SDIO_INTCLR_SBITERR                 SDIO_INTCLR_SBITERR_Msk                 /*!< SBITERR flag clear bit */
#define SDIO_INTCLR_DTBLKCMPL_Pos           (10U)
#define SDIO_INTCLR_DTBLKCMPL_Msk           (0x1U << SDIO_INTCLR_DTBLKCMPL_Pos)     /*!< 0x00000400 */
#define SDIO_INTCLR_DTBLKCMPL               SDIO_INTCLR_DTBLKCMPL_Msk               /*!< DTBLKCMPL flag clear bit */
#define SDIO_INTCLR_IOIF_Pos                (22U)
#define SDIO_INTCLR_IOIF_Msk                (0x1U << SDIO_INTCLR_IOIF_Pos)          /*!< 0x00400000 */
#define SDIO_INTCLR_IOIF                    SDIO_INTCLR_IOIF_Msk                    /*!< SD I/O interface flag clear bit */

/******************  Bit definition for SDIO_INTEN register  ******************/
#define SDIO_INTEN_CMDFAILIEN_Pos           (0U)
#define SDIO_INTEN_CMDFAILIEN_Msk           (0x1U << SDIO_INTEN_CMDFAILIEN_Pos)     /*!< 0x00000001 */
#define SDIO_INTEN_CMDFAILIEN               SDIO_INTEN_CMDFAILIEN_Msk               /*!< Command CRC fail interrupt enable */
#define SDIO_INTEN_DTFAILIEN_Pos            (1U)
#define SDIO_INTEN_DTFAILIEN_Msk            (0x1U << SDIO_INTEN_DTFAILIEN_Pos)      /*!< 0x00000002 */
#define SDIO_INTEN_DTFAILIEN                SDIO_INTEN_DTFAILIEN_Msk                /*!< Data CRC fail interrupt enable */
#define SDIO_INTEN_CMDTIMEOUTIEN_Pos        (2U)
#define SDIO_INTEN_CMDTIMEOUTIEN_Msk        (0x1U << SDIO_INTEN_CMDTIMEOUTIEN_Pos)  /*!< 0x00000004 */
#define SDIO_INTEN_CMDTIMEOUTIEN            SDIO_INTEN_CMDTIMEOUTIEN_Msk            /*!< Command timeout interrupt enable */
#define SDIO_INTEN_DTTIMEOUTIEN_Pos         (3U)
#define SDIO_INTEN_DTTIMEOUTIEN_Msk         (0x1U << SDIO_INTEN_DTTIMEOUTIEN_Pos)   /*!< 0x00000008 */
#define SDIO_INTEN_DTTIMEOUTIEN             SDIO_INTEN_DTTIMEOUTIEN_Msk             /*!< Data timeout interrupt enable */
#define SDIO_INTEN_TXERRUIEN_Pos            (4U)
#define SDIO_INTEN_TXERRUIEN_Msk            (0x1U << SDIO_INTEN_TXERRUIEN_Pos)      /*!< 0x00000010 */
#define SDIO_INTEN_TXERRUIEN                SDIO_INTEN_TXERRUIEN_Msk                /*!< TxBUF underrun error interrupt enable */
#define SDIO_INTEN_RXERROIEN_Pos            (5U)
#define SDIO_INTEN_RXERROIEN_Msk            (0x1U << SDIO_INTEN_RXERROIEN_Pos)      /*!< 0x00000020 */
#define SDIO_INTEN_RXERROIEN                SDIO_INTEN_RXERROIEN_Msk                /*!< RxBUF overrun error interrupt enable */
#define SDIO_INTEN_CMDRSPCMPLIEN_Pos        (6U)
#define SDIO_INTEN_CMDRSPCMPLIEN_Msk        (0x1U << SDIO_INTEN_CMDRSPCMPLIEN_Pos)  /*!< 0x00000040 */
#define SDIO_INTEN_CMDRSPCMPLIEN            SDIO_INTEN_CMDRSPCMPLIEN_Msk            /*!< Command response received interrupt enable */
#define SDIO_INTEN_CMDCMPLIEN_Pos           (7U)
#define SDIO_INTEN_CMDCMPLIEN_Msk           (0x1U << SDIO_INTEN_CMDCMPLIEN_Pos)     /*!< 0x00000080 */
#define SDIO_INTEN_CMDCMPLIEN               SDIO_INTEN_CMDCMPLIEN_Msk               /*!< Command sent interrupt enable */
#define SDIO_INTEN_DTCMPLIEN_Pos            (8U)
#define SDIO_INTEN_DTCMPLIEN_Msk            (0x1U << SDIO_INTEN_DTCMPLIEN_Pos)      /*!< 0x00000100 */
#define SDIO_INTEN_DTCMPLIEN                SDIO_INTEN_DTCMPLIEN_Msk                /*!< Data end interrupt enable */
#define SDIO_INTEN_SBITERRIEN_Pos           (9U)
#define SDIO_INTEN_SBITERRIEN_Msk           (0x1U << SDIO_INTEN_SBITERRIEN_Pos)     /*!< 0x00000200 */
#define SDIO_INTEN_SBITERRIEN               SDIO_INTEN_SBITERRIEN_Msk               /*!< Start bit error interrupt enable */
#define SDIO_INTEN_DTBLKCMPLIEN_Pos         (10U)
#define SDIO_INTEN_DTBLKCMPLIEN_Msk         (0x1U << SDIO_INTEN_DTBLKCMPLIEN_Pos)   /*!< 0x00000400 */
#define SDIO_INTEN_DTBLKCMPLIEN             SDIO_INTEN_DTBLKCMPLIEN_Msk             /*!< Data block end interrupt enable */
#define SDIO_INTEN_DOCMDIEN_Pos             (11U)
#define SDIO_INTEN_DOCMDIEN_Msk             (0x1U << SDIO_INTEN_DOCMDIEN_Pos)       /*!< 0x00000800 */
#define SDIO_INTEN_DOCMDIEN                 SDIO_INTEN_DOCMDIEN_Msk                 /*!< Command acting interrupt enable */
#define SDIO_INTEN_DOTXIEN_Pos              (12U)
#define SDIO_INTEN_DOTXIEN_Msk              (0x1U << SDIO_INTEN_DOTXIEN_Pos)        /*!< 0x00001000 */
#define SDIO_INTEN_DOTXIEN                  SDIO_INTEN_DOTXIEN_Msk                  /*!< Data transmit acting interrupt enable */
#define SDIO_INTEN_DORXIEN_Pos              (13U)
#define SDIO_INTEN_DORXIEN_Msk              (0x1U << SDIO_INTEN_DORXIEN_Pos)        /*!< 0x00002000 */
#define SDIO_INTEN_DORXIEN                  SDIO_INTEN_DORXIEN_Msk                  /*!< Data receive acting interrupt enable */
#define SDIO_INTEN_TXBUFHIEN_Pos            (14U)
#define SDIO_INTEN_TXBUFHIEN_Msk            (0x1U << SDIO_INTEN_TXBUFHIEN_Pos)      /*!< 0x00004000 */
#define SDIO_INTEN_TXBUFHIEN                SDIO_INTEN_TXBUFHIEN_Msk                /*!< TxBUF half empty interrupt enable */
#define SDIO_INTEN_RXBUFHIEN_Pos            (15U)
#define SDIO_INTEN_RXBUFHIEN_Msk            (0x1U << SDIO_INTEN_RXBUFHIEN_Pos)      /*!< 0x00008000 */
#define SDIO_INTEN_RXBUFHIEN                SDIO_INTEN_RXBUFHIEN_Msk                /*!< RxBUF half full interrupt enable */
#define SDIO_INTEN_TXBUFFIEN_Pos            (16U)
#define SDIO_INTEN_TXBUFFIEN_Msk            (0x1U << SDIO_INTEN_TXBUFFIEN_Pos)      /*!< 0x00010000 */
#define SDIO_INTEN_TXBUFFIEN                SDIO_INTEN_TXBUFFIEN_Msk                /*!< TxBUF full interrupt enable */
#define SDIO_INTEN_RXBUFFIEN_Pos            (17U)
#define SDIO_INTEN_RXBUFFIEN_Msk            (0x1U << SDIO_INTEN_RXBUFFIEN_Pos)      /*!< 0x00020000 */
#define SDIO_INTEN_RXBUFFIEN                SDIO_INTEN_RXBUFFIEN_Msk                /*!< RxBUF full interrupt enable */
#define SDIO_INTEN_TXBUFEIEN_Pos            (18U)
#define SDIO_INTEN_TXBUFEIEN_Msk            (0x1U << SDIO_INTEN_TXBUFEIEN_Pos)      /*!< 0x00040000 */
#define SDIO_INTEN_TXBUFEIEN                SDIO_INTEN_TXBUFEIEN_Msk                /*!< TxBUF empty interrupt enable */
#define SDIO_INTEN_RXBUFEIEN_Pos            (19U)
#define SDIO_INTEN_RXBUFEIEN_Msk            (0x1U << SDIO_INTEN_RXBUFEIEN_Pos)      /*!< 0x00080000 */
#define SDIO_INTEN_RXBUFEIEN                SDIO_INTEN_RXBUFEIEN_Msk                /*!< RxBUF empty interrupt enable */
#define SDIO_INTEN_TXBUFIEN_Pos             (20U)
#define SDIO_INTEN_TXBUFIEN_Msk             (0x1U << SDIO_INTEN_TXBUFIEN_Pos)       /*!< 0x00100000 */
#define SDIO_INTEN_TXBUFIEN                 SDIO_INTEN_TXBUFIEN_Msk                 /*!< Data available in TxBUF interrupt enable */
#define SDIO_INTEN_RXBUFIEN_Pos             (21U)
#define SDIO_INTEN_RXBUFIEN_Msk             (0x1U << SDIO_INTEN_RXBUFIEN_Pos)       /*!< 0x00200000 */
#define SDIO_INTEN_RXBUFIEN                 SDIO_INTEN_RXBUFIEN_Msk                 /*!< Data available in RxBUF interrupt enable */
#define SDIO_INTEN_IOIFIEN_Pos              (22U)
#define SDIO_INTEN_IOIFIEN_Msk              (0x1U << SDIO_INTEN_IOIFIEN_Pos)        /*!< 0x00400000 */
#define SDIO_INTEN_IOIFIEN                  SDIO_INTEN_IOIFIEN_Msk                  /*!< SD I/O mode received interrupt enable */

/*****************  Bit definition for SDIO_BUFCNTR register  ******************/
#define SDIO_BUFCNTR_CNT_Pos                (0U)
#define SDIO_BUFCNTR_CNT_Msk                (0xFFFFFFU << SDIO_BUFCNTR_CNT_Pos)     /*!< 0x00FFFFFF */
#define SDIO_BUFCNTR_CNT                    SDIO_BUFCNTR_CNT_Msk                    /*!< Number of words to be written to or read from the BUF */

/*******************  Bit definition for SDIO_BUF register  *******************/
#define SDIO_BUF_DT_Pos                     (0U)
#define SDIO_BUF_DT_Msk                     (0xFFFFFFFFU << SDIO_BUF_DT_Pos)        /*!< 0xFFFFFFFF */
#define SDIO_BUF_DT                         SDIO_BUF_DT_Msk                         /*!< Receive and transmit BUF data */

/******************************************************************************/
/*                                                                            */
/*                             Comparator (COMP)                              */
/*                                                                            */
/******************************************************************************/

/*****************  Bit definition for CMP_CTRLSTS1 register  *****************/
#define CMP_CTRLSTS1_CMP1EN_Pos             (0U)
#define CMP_CTRLSTS1_CMP1EN_Msk             (0x1U << CMP_CTRLSTS1_CMP1EN_Pos)       /*!< 0x00000001 */
#define CMP_CTRLSTS1_CMP1EN                 CMP_CTRLSTS1_CMP1EN_Msk                 /*!< Comparator 1 enable */
#define CMP_CTRLSTS1_CMP1IS_Pos             (1U)
#define CMP_CTRLSTS1_CMP1IS_Msk             (0x1U << CMP_CTRLSTS1_CMP1IS_Pos)       /*!< 0x00000002 */
#define CMP_CTRLSTS1_CMP1IS                 CMP_CTRLSTS1_CMP1IS_Msk                 /*!< Comparator 1 input shift */
#define CMP_CTRLSTS1_CMP1SSEL_Pos           (2U)
#define CMP_CTRLSTS1_CMP1SSEL_Msk           (0x1U << CMP_CTRLSTS1_CMP1SSEL_Pos)     /*!< 0x00000004 */
#define CMP_CTRLSTS1_CMP1SSEL               CMP_CTRLSTS1_CMP1SSEL_Msk               /*!< Comparator 1 speed selection */

#define CMP_CTRLSTS1_CMP1INVSEL_Pos         (4U)
#define CMP_CTRLSTS1_CMP1INVSEL_Msk         (0x7U << CMP_CTRLSTS1_CMP1INVSEL_Pos)   /*!< 0x00000070 */
#define CMP_CTRLSTS1_CMP1INVSEL             CMP_CTRLSTS1_CMP1INVSEL_Msk             /*!< CMP1INVSEL[2:0] bits (Comparator 1 inverting selection) */
#define CMP_CTRLSTS1_CMP1INVSEL_0           (0x1U << CMP_CTRLSTS1_CMP1INVSEL_Pos)   /*!< 0x00000010 */
#define CMP_CTRLSTS1_CMP1INVSEL_1           (0x2U << CMP_CTRLSTS1_CMP1INVSEL_Pos)   /*!< 0x00000020 */
#define CMP_CTRLSTS1_CMP1INVSEL_2           (0x4U << CMP_CTRLSTS1_CMP1INVSEL_Pos)   /*!< 0x00000040 */

#define CMP_CTRLSTS1_CMP1TAG_Pos            (8U)
#define CMP_CTRLSTS1_CMP1TAG_Msk            (0x7U << CMP_CTRLSTS1_CMP1TAG_Pos)      /*!< 0x00000700 */
#define CMP_CTRLSTS1_CMP1TAG                CMP_CTRLSTS1_CMP1TAG_Msk                /*!< CMP1TAG[2:0] bits (Comparator 1 output target) */
#define CMP_CTRLSTS1_CMP1TAG_0              (0x1U << CMP_CTRLSTS1_CMP1TAG_Pos)      /*!< 0x00000100 */
#define CMP_CTRLSTS1_CMP1TAG_1              (0x2U << CMP_CTRLSTS1_CMP1TAG_Pos)      /*!< 0x00000200 */
#define CMP_CTRLSTS1_CMP1TAG_2              (0x4U << CMP_CTRLSTS1_CMP1TAG_Pos)      /*!< 0x00000400 */

#define CMP_CTRLSTS1_CMP1P_Pos              (11U)
#define CMP_CTRLSTS1_CMP1P_Msk              (0x1U << CMP_CTRLSTS1_CMP1P_Pos)        /*!< 0x00000800 */
#define CMP_CTRLSTS1_CMP1P                  CMP_CTRLSTS1_CMP1P_Msk                  /*!< Comparator 1 polarity */

#define CMP_CTRLSTS1_CMP1HYST_Pos           (12U)
#define CMP_CTRLSTS1_CMP1HYST_Msk           (0x3U << CMP_CTRLSTS1_CMP1HYST_Pos)     /*!< 0x00003000 */
#define CMP_CTRLSTS1_CMP1HYST               CMP_CTRLSTS1_CMP1HYST_Msk               /*!< CMP1HYST[1:0] bits (Comparator 1 hysteresis) */
#define CMP_CTRLSTS1_CMP1HYST_0             (0x1U << CMP_CTRLSTS1_CMP1HYST_Pos)     /*!< 0x00001000 */
#define CMP_CTRLSTS1_CMP1HYST_1             (0x2U << CMP_CTRLSTS1_CMP1HYST_Pos)     /*!< 0x00002000 */

#define CMP_CTRLSTS1_CMP1VALUE_Pos          (14U)
#define CMP_CTRLSTS1_CMP1VALUE_Msk          (0x1U << CMP_CTRLSTS1_CMP1VALUE_Pos)    /*!< 0x00004000 */
#define CMP_CTRLSTS1_CMP1VALUE              CMP_CTRLSTS1_CMP1VALUE_Msk              /*!< Comparator 1 output value */
#define CMP_CTRLSTS1_CMP1WP_Pos             (15U)
#define CMP_CTRLSTS1_CMP1WP_Msk             (0x1U << CMP_CTRLSTS1_CMP1WP_Pos)       /*!< 0x00008000 */
#define CMP_CTRLSTS1_CMP1WP                 CMP_CTRLSTS1_CMP1WP_Msk                 /*!< Comparator 1 write protect */
#define CMP_CTRLSTS1_CMP2EN_Pos             (16U)
#define CMP_CTRLSTS1_CMP2EN_Msk             (0x1U << CMP_CTRLSTS1_CMP2EN_Pos)       /*!< 0x00010000 */
#define CMP_CTRLSTS1_CMP2EN                 CMP_CTRLSTS1_CMP2EN_Msk                 /*!< Comparator 2 enable */
#define CMP_CTRLSTS1_CMP2SSEL_Pos           (18U)
#define CMP_CTRLSTS1_CMP2SSEL_Msk           (0x1U << CMP_CTRLSTS1_CMP2SSEL_Pos)     /*!< 0x00040000 */
#define CMP_CTRLSTS1_CMP2SSEL               CMP_CTRLSTS1_CMP2SSEL_Msk               /*!< Comparator 2 speed selection */

#define CMP_CTRLSTS1_CMP2INVSEL_Pos         (20U)
#define CMP_CTRLSTS1_CMP2INVSEL_Msk         (0x7U << CMP_CTRLSTS1_CMP2INVSEL_Pos)   /*!< 0x00700000 */
#define CMP_CTRLSTS1_CMP2INVSEL             CMP_CTRLSTS1_CMP2INVSEL_Msk             /*!< CMP2INVSEL[2:0] bits (Comparator 2 inverting selection) */
#define CMP_CTRLSTS1_CMP2INVSEL_0           (0x1U << CMP_CTRLSTS1_CMP2INVSEL_Pos)   /*!< 0x00100000 */
#define CMP_CTRLSTS1_CMP2INVSEL_1           (0x2U << CMP_CTRLSTS1_CMP2INVSEL_Pos)   /*!< 0x00200000 */
#define CMP_CTRLSTS1_CMP2INVSEL_2           (0x4U << CMP_CTRLSTS1_CMP2INVSEL_Pos)   /*!< 0x00400000 */

#define CMP_CTRLSTS1_DCMPEN_Pos             (23U)
#define CMP_CTRLSTS1_DCMPEN_Msk             (0x1U << CMP_CTRLSTS1_DCMPEN_Pos)       /*!< 0x00800000 */
#define CMP_CTRLSTS1_DCMPEN                 CMP_CTRLSTS1_DCMPEN_Msk                 /*!< Double comparator mode enable */

#define CMP_CTRLSTS1_CMP2TAG_Pos            (24U)
#define CMP_CTRLSTS1_CMP2TAG_Msk            (0x7U << CMP_CTRLSTS1_CMP2TAG_Pos)      /*!< 0x07000000 */
#define CMP_CTRLSTS1_CMP2TAG                CMP_CTRLSTS1_CMP2TAG_Msk                /*!< CMP2TAG[2:0] bits (Comparator 2 output target) */
#define CMP_CTRLSTS1_CMP2TAG_0              (0x1U << CMP_CTRLSTS1_CMP2TAG_Pos)      /*!< 0x01000000 */
#define CMP_CTRLSTS1_CMP2TAG_1              (0x2U << CMP_CTRLSTS1_CMP2TAG_Pos)      /*!< 0x02000000 */
#define CMP_CTRLSTS1_CMP2TAG_2              (0x4U << CMP_CTRLSTS1_CMP2TAG_Pos)      /*!< 0x04000000 */

#define CMP_CTRLSTS1_CMP2P_Pos              (27U)
#define CMP_CTRLSTS1_CMP2P_Msk              (0x1U << CMP_CTRLSTS1_CMP2P_Pos)        /*!< 0x08000000 */
#define CMP_CTRLSTS1_CMP2P                  CMP_CTRLSTS1_CMP2P_Msk                  /*!< Comparator 2 polarity */

#define CMP_CTRLSTS1_CMP2HYST_Pos           (28U)
#define CMP_CTRLSTS1_CMP2HYST_Msk           (0x3U << CMP_CTRLSTS1_CMP2HYST_Pos)     /*!< 0x30000000 */
#define CMP_CTRLSTS1_CMP2HYST               CMP_CTRLSTS1_CMP2HYST_Msk               /*!< CMP2HYST[1:0] bits (Comparator 2 hysteresis) */
#define CMP_CTRLSTS1_CMP2HYST_0             (0x1U << CMP_CTRLSTS1_CMP2HYST_Pos)     /*!< 0x10000000 */
#define CMP_CTRLSTS1_CMP2HYST_1             (0x2U << CMP_CTRLSTS1_CMP2HYST_Pos)     /*!< 0x20000000 */

#define CMP_CTRLSTS1_CMP2VALUE_Pos          (30U)
#define CMP_CTRLSTS1_CMP2VALUE_Msk          (0x1U << CMP_CTRLSTS1_CMP2VALUE_Pos)    /*!< 0x40000000 */
#define CMP_CTRLSTS1_CMP2VALUE              CMP_CTRLSTS1_CMP2VALUE_Msk              /*!< Comparator 2 output value */
#define CMP_CTRLSTS1_CMP2WP_Pos             (31U)
#define CMP_CTRLSTS1_CMP2WP_Msk             (0x1U << CMP_CTRLSTS1_CMP2WP_Pos)       /*!< 0x80000000 */
#define CMP_CTRLSTS1_CMP2WP                 CMP_CTRLSTS1_CMP2WP_Msk                 /*!< Comparator 2 write protect */

/*****************  Bit definition for CMP_CTRLSTS2 register  *****************/
#define CMP_CTRLSTS2_CMP1NINVSEL_Pos        (0U)
#define CMP_CTRLSTS2_CMP1NINVSEL_Msk        (0x3U << CMP_CTRLSTS2_CMP1NINVSEL_Pos)  /*!< 0x00000003 */
#define CMP_CTRLSTS2_CMP1NINVSEL            CMP_CTRLSTS2_CMP1NINVSEL_Msk            /*!< Comparator 1 non-inverting input selection */
#define CMP_CTRLSTS2_CMP1NINVSEL_0          (0x1U << CMP_CTRLSTS2_CMP1NINVSEL_Pos)  /*!< 0x00000001 */
#define CMP_CTRLSTS2_CMP1NINVSEL_1          (0x2U << CMP_CTRLSTS2_CMP1NINVSEL_Pos)  /*!< 0x00000002 */

#define CMP_CTRLSTS2_CMP2NINVSEL_Pos        (16U)
#define CMP_CTRLSTS2_CMP2NINVSEL_Msk        (0x3U << CMP_CTRLSTS2_CMP2NINVSEL_Pos)  /*!< 0x00030000 */
#define CMP_CTRLSTS2_CMP2NINVSEL            CMP_CTRLSTS2_CMP2NINVSEL_Msk            /*!< Comparator 2 non-inverting input selection */
#define CMP_CTRLSTS2_CMP2NINVSEL_0          (0x1U << CMP_CTRLSTS2_CMP2NINVSEL_Pos)  /*!< 0x00010000 */
#define CMP_CTRLSTS2_CMP2NINVSEL_1          (0x2U << CMP_CTRLSTS2_CMP2NINVSEL_Pos)  /*!< 0x00020000 */

/******************************************************************************/
/*                                                                            */
/*                             Debug MCU (DEBUG)                              */
/*                                                                            */
/******************************************************************************/

/*****************  Bit definition for DEBUG_IDCODE register  *****************/
#define DEBUG_IDCODE_PID_Pos                (0U)
#define DEBUG_IDCODE_PID_Msk                (0xFFFFFFFFU << DEBUG_IDCODE_PID_Pos)   /*!< 0xFFFFFFFF */
#define DEBUG_IDCODE_PID                    DEBUG_IDCODE_PID_Msk                    /*!< PID[31:0] bits (PID information) */
#define DEBUG_IDCODE_PID_0                  (0x00000001U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00000001 */
#define DEBUG_IDCODE_PID_1                  (0x00000002U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00000002 */
#define DEBUG_IDCODE_PID_2                  (0x00000004U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00000004 */
#define DEBUG_IDCODE_PID_3                  (0x00000008U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00000008 */
#define DEBUG_IDCODE_PID_4                  (0x00000010U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00000010 */
#define DEBUG_IDCODE_PID_5                  (0x00000020U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00000020 */
#define DEBUG_IDCODE_PID_6                  (0x00000040U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00000040 */
#define DEBUG_IDCODE_PID_7                  (0x00000080U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00000080 */
#define DEBUG_IDCODE_PID_8                  (0x00000100U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00000100 */
#define DEBUG_IDCODE_PID_9                  (0x00000200U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00000200 */
#define DEBUG_IDCODE_PID_10                 (0x00000400U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00000400 */
#define DEBUG_IDCODE_PID_11                 (0x00000800U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00000800 */
#define DEBUG_IDCODE_PID_12                 (0x00001000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00001000 */
#define DEBUG_IDCODE_PID_13                 (0x00002000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00002000 */
#define DEBUG_IDCODE_PID_14                 (0x00004000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00004000 */
#define DEBUG_IDCODE_PID_15                 (0x00008000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00008000 */
#define DEBUG_IDCODE_PID_16                 (0x00010000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00010000 */
#define DEBUG_IDCODE_PID_17                 (0x00020000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00020000 */
#define DEBUG_IDCODE_PID_18                 (0x00040000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00040000 */
#define DEBUG_IDCODE_PID_19                 (0x00080000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00080000 */
#define DEBUG_IDCODE_PID_20                 (0x00100000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00100000 */
#define DEBUG_IDCODE_PID_21                 (0x00200000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00200000 */
#define DEBUG_IDCODE_PID_22                 (0x00400000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00400000 */
#define DEBUG_IDCODE_PID_23                 (0x00800000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x00800000 */
#define DEBUG_IDCODE_PID_24                 (0x01000000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x01000000 */
#define DEBUG_IDCODE_PID_25                 (0x02000000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x02000000 */
#define DEBUG_IDCODE_PID_26                 (0x04000000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x04000000 */
#define DEBUG_IDCODE_PID_27                 (0x08000000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x08000000 */
#define DEBUG_IDCODE_PID_28                 (0x10000000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x10000000 */
#define DEBUG_IDCODE_PID_29                 (0x20000000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x20000000 */
#define DEBUG_IDCODE_PID_30                 (0x40000000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x40000000 */
#define DEBUG_IDCODE_PID_31                 (0x80000000U << DEBUG_IDCODE_PID_Pos)   /*!< 0x80000000 */

/******************  Bit definition for DEBUG_CTRL register  ******************/
#define DEBUG_CTRL_SLEEP_DEBUG_Pos          (0U)
#define DEBUG_CTRL_SLEEP_DEBUG_Msk          (0x1U << DEBUG_CTRL_SLEEP_DEBUG_Pos)    /*!< 0x00000001 */
#define DEBUG_CTRL_SLEEP_DEBUG              DEBUG_CTRL_SLEEP_DEBUG_Msk              /*!< Debug Sleep mode control bit */
#define DEBUG_CTRL_DEEPSLEEP_DEBUG_Pos      (1U)                                    /*!< 0x00000002 */
#define DEBUG_CTRL_DEEPSLEEP_DEBUG_Msk      (0x1U << DEBUG_CTRL_DEEPSLEEP_DEBUG_Pos)
#define DEBUG_CTRL_DEEPSLEEP_DEBUG          DEBUG_CTRL_DEEPSLEEP_DEBUG_Msk          /*!< Debug Deep sleep mode control bit */
#define DEBUG_CTRL_STANDBY_DEBUG_Pos        (2U)
#define DEBUG_CTRL_STANDBY_DEBUG_Msk        (0x1U << DEBUG_CTRL_STANDBY_DEBUG_Pos)  /*!< 0x00000004 */
#define DEBUG_CTRL_STANDBY_DEBUG            DEBUG_CTRL_STANDBY_DEBUG_Msk            /*!< Debug Standby mode control bit */
#define DEBUG_CTRL_TRACE_IOEN_Pos           (5U)
#define DEBUG_CTRL_TRACE_IOEN_Msk           (0x1U << DEBUG_CTRL_TRACE_IOEN_Pos)     /*!< 0x00000020 */
#define DEBUG_CTRL_TRACE_IOEN               DEBUG_CTRL_TRACE_IOEN_Msk               /*!< Trace pin assignment enable */

#define DEBUG_CTRL_TRACE_MODE_Pos           (6U)
#define DEBUG_CTRL_TRACE_MODE_Msk           (0x3U << DEBUG_CTRL_TRACE_MODE_Pos)     /*!< 0x000000C0 */
#define DEBUG_CTRL_TRACE_MODE               DEBUG_CTRL_TRACE_MODE_Msk               /*!< TRACE_MODE[1:0] bits (Trace pin assignment control) */
#define DEBUG_CTRL_TRACE_MODE_0             (0x1U << DEBUG_CTRL_TRACE_MODE_Pos)     /*!< 0x00000040 */
#define DEBUG_CTRL_TRACE_MODE_1             (0x2U << DEBUG_CTRL_TRACE_MODE_Pos)     /*!< 0x00000080 */

#define DEBUG_CTRL_WDT_PAUSE_Pos            (8U)
#define DEBUG_CTRL_WDT_PAUSE_Msk            (0x1U << DEBUG_CTRL_WDT_PAUSE_Pos)      /*!< 0x00000100 */
#define DEBUG_CTRL_WDT_PAUSE                DEBUG_CTRL_WDT_PAUSE_Msk                /*!< Watchdog pause control bit */
#define DEBUG_CTRL_WWDT_PAUSE_Pos           (9U)
#define DEBUG_CTRL_WWDT_PAUSE_Msk           (0x1U << DEBUG_CTRL_WWDT_PAUSE_Pos)     /*!< 0x00000200 */
#define DEBUG_CTRL_WWDT_PAUSE               DEBUG_CTRL_WWDT_PAUSE_Msk               /*!< Window watchdog pause control bit */
#define DEBUG_CTRL_TMR1_PAUSE_Pos           (10U)
#define DEBUG_CTRL_TMR1_PAUSE_Msk           (0x1U << DEBUG_CTRL_TMR1_PAUSE_Pos)     /*!< 0x00000400 */
#define DEBUG_CTRL_TMR1_PAUSE               DEBUG_CTRL_TMR1_PAUSE_Msk               /*!< TMR1 pause control bit */
#define DEBUG_CTRL_TMR2_PAUSE_Pos           (11U)
#define DEBUG_CTRL_TMR2_PAUSE_Msk           (0x1U << DEBUG_CTRL_TMR2_PAUSE_Pos)     /*!< 0x00000800 */
#define DEBUG_CTRL_TMR2_PAUSE               DEBUG_CTRL_TMR2_PAUSE_Msk               /*!< TMR2 pause control bit */
#define DEBUG_CTRL_TMR3_PAUSE_Pos           (12U)
#define DEBUG_CTRL_TMR3_PAUSE_Msk           (0x1U << DEBUG_CTRL_TMR3_PAUSE_Pos)     /*!< 0x00001000 */
#define DEBUG_CTRL_TMR3_PAUSE               DEBUG_CTRL_TMR3_PAUSE_Msk               /*!< TMR3 pause control bit */
#define DEBUG_CTRL_TMR4_PAUSE_Pos           (13U)
#define DEBUG_CTRL_TMR4_PAUSE_Msk           (0x1U << DEBUG_CTRL_TMR4_PAUSE_Pos)     /*!< 0x00002000 */
#define DEBUG_CTRL_TMR4_PAUSE               DEBUG_CTRL_TMR4_PAUSE_Msk               /*!< TMR4 pause control bit */
#define DEBUG_CTRL_CAN1_PAUSE_Pos           (14U)
#define DEBUG_CTRL_CAN1_PAUSE_Msk           (0x1U << DEBUG_CTRL_CAN1_PAUSE_Pos)     /*!< 0x00004000 */
#define DEBUG_CTRL_CAN1_PAUSE               DEBUG_CTRL_CAN1_PAUSE_Msk               /*!< CAN1 pause control bit */
#define DEBUG_CTRL_I2C1_SMBUS_TIMEOUT_Pos   (15U)                                   /*!< 0x00008000 */
#define DEBUG_CTRL_I2C1_SMBUS_TIMEOUT_Msk   (0x1U << DEBUG_CTRL_I2C1_SMBUS_TIMEOUT_Pos)
#define DEBUG_CTRL_I2C1_SMBUS_TIMEOUT       DEBUG_CTRL_I2C1_SMBUS_TIMEOUT_Msk       /*!< I2C1 pause control bit */
#define DEBUG_CTRL_I2C2_SMBUS_TIMEOUT_Pos   (16U)                                   /*!< 0x00010000 */
#define DEBUG_CTRL_I2C2_SMBUS_TIMEOUT_Msk   (0x1U << DEBUG_CTRL_I2C2_SMBUS_TIMEOUT_Pos)
#define DEBUG_CTRL_I2C2_SMBUS_TIMEOUT       DEBUG_CTRL_I2C2_SMBUS_TIMEOUT_Msk       /*!< I2C2 pause control bit */
#define DEBUG_CTRL_TMR5_PAUSE_Pos           (18U)
#define DEBUG_CTRL_TMR5_PAUSE_Msk           (0x1U << DEBUG_CTRL_TMR5_PAUSE_Pos)     /*!< 0x00040000 */
#define DEBUG_CTRL_TMR5_PAUSE               DEBUG_CTRL_TMR5_PAUSE_Msk               /*!< TMR5 pause control bit */
#define DEBUG_CTRL_TMR9_PAUSE_Pos           (28U)
#define DEBUG_CTRL_TMR9_PAUSE_Msk           (0x1U << DEBUG_CTRL_TMR9_PAUSE_Pos)     /*!< 0x10000000 */
#define DEBUG_CTRL_TMR9_PAUSE               DEBUG_CTRL_TMR9_PAUSE_Msk               /*!< TMR9 pause control bit */
#define DEBUG_CTRL_TMR10_PAUSE_Pos          (29U)
#define DEBUG_CTRL_TMR10_PAUSE_Msk          (0x1U << DEBUG_CTRL_TMR10_PAUSE_Pos)    /*!< 0x20000000 */
#define DEBUG_CTRL_TMR10_PAUSE              DEBUG_CTRL_TMR10_PAUSE_Msk              /*!< TMR10 pause control bit */
#define DEBUG_CTRL_TMR11_PAUSE_Pos          (30U)
#define DEBUG_CTRL_TMR11_PAUSE_Msk          (0x1U << DEBUG_CTRL_TMR11_PAUSE_Pos)    /*!< 0x40000000 */
#define DEBUG_CTRL_TMR11_PAUSE              DEBUG_CTRL_TMR11_PAUSE_Msk              /*!< TMR11 pause control bit */

/**
  * @}
*/

/**
  * @}
*/ 

/** @addtogroup Exported_macro
  * @{
  */

/******************************* ADC Instances ********************************/
#define IS_ADC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == ADC1)
                                       
#define IS_ADC_MULTIMODE_MASTER_INSTANCE(INSTANCE) ((INSTANCE) == ADC1)

#define IS_ADC_DMA_CAPABILITY_INSTANCE(INSTANCE) ((INSTANCE) == ADC1)

/******************************* CAN Instances ********************************/    
#define IS_CAN_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CAN1)

/******************************* CRC Instances ********************************/
#define IS_CRC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CRC)

/******************************* DMA Instances ********************************/
#define IS_DMA_ALL_INSTANCE(INSTANCE) (((INSTANCE) == DMA1_Channel1) || \
                                       ((INSTANCE) == DMA1_Channel2) || \
                                       ((INSTANCE) == DMA1_Channel3) || \
                                       ((INSTANCE) == DMA1_Channel4) || \
                                       ((INSTANCE) == DMA1_Channel5) || \
                                       ((INSTANCE) == DMA1_Channel6) || \
                                       ((INSTANCE) == DMA1_Channel7) || \
                                       ((INSTANCE) == DMA2_Channel1) || \
                                       ((INSTANCE) == DMA2_Channel2) || \
                                       ((INSTANCE) == DMA2_Channel3) || \
                                       ((INSTANCE) == DMA2_Channel4) || \
                                       ((INSTANCE) == DMA2_Channel5) || \
                                       ((INSTANCE) == DMA2_Channel6) || \
                                       ((INSTANCE) == DMA2_Channel7))
  
/******************************* GPIO Instances *******************************/
#define IS_GPIO_ALL_INSTANCE(INSTANCE) (((INSTANCE) == GPIOA) || \
                                        ((INSTANCE) == GPIOB) || \
                                        ((INSTANCE) == GPIOC) || \
                                        ((INSTANCE) == GPIOD) || \
                                        ((INSTANCE) == GPIOF))

/********************* IOMUX Multiplex Function Instances *********************/
#define IS_IOMUX_ALL_INSTANCE(INSTANCE) IS_GPIO_ALL_INSTANCE(INSTANCE)

/**************************** GPIO Lock Instances *****************************/
#define IS_GPIO_LOCK_INSTANCE(INSTANCE) IS_GPIO_ALL_INSTANCE(INSTANCE)

/******************************* I2C Instances ********************************/
#define IS_I2C_ALL_INSTANCE(INSTANCE) (((INSTANCE) == I2C1) || \
                                       ((INSTANCE) == I2C2))

/****************************** SMBUS Instances *******************************/
#define IS_SMBUS_ALL_INSTANCE         IS_I2C_ALL_INSTANCE

/******************************* I2S Instances ********************************/
#define IS_I2S_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI1) || \
                                       ((INSTANCE) == SPI2))

/******************************* WDT Instances ********************************/
#define IS_WDT_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == WDT)

/******************************* SDIO Instances *******************************/
#define IS_SDIO_ALL_INSTANCE(INSTANCE) ((INSTANCE) == SDIO)

/******************************* SPI Instances ********************************/
#define IS_SPI_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI1) || \
                                       ((INSTANCE) == SPI2))

/**************************** START TMR Instances *****************************/
/******************************* TMR Instances ********************************/
#define IS_TMR_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5)    || \
   ((INSTANCE) == TMR9)    || \
   ((INSTANCE) == TMR10)   || \
   ((INSTANCE) == TMR11))

#define IS_TMR_ADVANCED_INSTANCE(INSTANCE)\
  ((INSTANCE) == TMR1)

#define IS_TMR_C1_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5)    || \
   ((INSTANCE) == TMR9)    || \
   ((INSTANCE) == TMR10)   || \
   ((INSTANCE) == TMR11))

#define IS_TMR_C2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5)    || \
   ((INSTANCE) == TMR9))

#define IS_TMR_C3_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5))

#define IS_TMR_C4_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5))

#define IS_TMR_CLOCKSOURCE_EXTMODE1_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5)    || \
   ((INSTANCE) == TMR9))

#define IS_TMR_CLOCKSOURCE_EXTMODE2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5))

#define IS_TMR_CLOCKSOURCE_TRGIN_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5)    || \
   ((INSTANCE) == TMR9))

#define IS_TMR_CLOCKSOURCE_ISX_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5)    || \
   ((INSTANCE) == TMR9))

#define IS_TMR_OCXREF_CLEAR_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5))

#define IS_TMR_ENCODER_INTERFACE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5))

#define IS_TMR_XOR_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5))

#define IS_TMR_MASTER_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5))

#define IS_TMR_SLAVE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5)    || \
   ((INSTANCE) == TMR9))

#define IS_TMR_DMABURST_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5))

#define IS_TMR_BREAK_INSTANCE(INSTANCE)\
  ((INSTANCE) == TMR1)

#define IS_TMR_CX_INSTANCE(INSTANCE, CHANNEL)  \
   ((((INSTANCE) == TMR1) &&                   \
     (((CHANNEL) == TMR_CHANNEL_1) ||          \
      ((CHANNEL) == TMR_CHANNEL_2) ||          \
      ((CHANNEL) == TMR_CHANNEL_3) ||          \
      ((CHANNEL) == TMR_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TMR2) &&                   \
     (((CHANNEL) == TMR_CHANNEL_1) ||          \
      ((CHANNEL) == TMR_CHANNEL_2) ||          \
      ((CHANNEL) == TMR_CHANNEL_3) ||          \
      ((CHANNEL) == TMR_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TMR3) &&                   \
     (((CHANNEL) == TMR_CHANNEL_1) ||          \
      ((CHANNEL) == TMR_CHANNEL_2) ||          \
      ((CHANNEL) == TMR_CHANNEL_3) ||          \
      ((CHANNEL) == TMR_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TMR4) &&                   \
     (((CHANNEL) == TMR_CHANNEL_1) ||          \
      ((CHANNEL) == TMR_CHANNEL_2) ||          \
      ((CHANNEL) == TMR_CHANNEL_3) ||          \
      ((CHANNEL) == TMR_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TMR5) &&                   \
     (((CHANNEL) == TMR_CHANNEL_1) ||          \
      ((CHANNEL) == TMR_CHANNEL_2) ||          \
      ((CHANNEL) == TMR_CHANNEL_3) ||          \
      ((CHANNEL) == TMR_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TMR9) &&                   \
     (((CHANNEL) == TMR_CHANNEL_1) ||          \
      ((CHANNEL) == TMR_CHANNEL_2)))           \
    ||                                         \
    (((INSTANCE) == TMR10) &&                  \
     (((CHANNEL) == TMR_CHANNEL_1)))           \
    ||                                         \
    (((INSTANCE) == TMR11) &&                  \
     (((CHANNEL) == TMR_CHANNEL_1))))

#define IS_TMR_CXN_INSTANCE(INSTANCE, CHANNEL) \
    (((INSTANCE) == TMR1) &&                   \
     (((CHANNEL) == TMR_CHANNEL_1) ||          \
      ((CHANNEL) == TMR_CHANNEL_2) ||          \
      ((CHANNEL) == TMR_CHANNEL_3)))

#define IS_TMR_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5))

#define IS_TMR_REPETITION_COUNTER_INSTANCE(INSTANCE)\
  ((INSTANCE) == TMR1)

#define IS_TMR_CLOCK_DIVISION_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5)    || \
   ((INSTANCE) == TMR9)    || \
   ((INSTANCE) == TMR10)   || \
   ((INSTANCE) == TMR11))

#define IS_TMR_DMA_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5))

#define IS_TMR_DMA_CC_INSTANCE(INSTANCE)\
  (((INSTANCE) == TMR1)    || \
   ((INSTANCE) == TMR2)    || \
   ((INSTANCE) == TMR3)    || \
   ((INSTANCE) == TMR4)    || \
   ((INSTANCE) == TMR5))

#define IS_TMR_COMMUTATION_EVENT_INSTANCE(INSTANCE)\
  ((INSTANCE) == TMR1))

#define IS_TMR_ETR_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1)    || \
                                        ((INSTANCE) == TMR2)    || \
                                        ((INSTANCE) == TMR3)    || \
                                        ((INSTANCE) == TMR4)    || \
                                        ((INSTANCE) == TMR5))

#define IS_TMR_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE) (((INSTANCE) == TMR1)    || \
                                                         ((INSTANCE) == TMR2)    || \
                                                         ((INSTANCE) == TMR3)    || \
                                                         ((INSTANCE) == TMR4)    || \
                                                         ((INSTANCE) == TMR5))

#define IS_TMR_32B_COUNTER_INSTANCE(INSTANCE)           0U

/***************************** END TMR Instances ******************************/

/********************* USART Instances : Synchronous mode *********************/
#define IS_USART_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                     ((INSTANCE) == USART2) || \
                                     ((INSTANCE) == USART3))

/********************* UART Instances : Asynchronous mode *********************/
#define IS_UART_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                    ((INSTANCE) == USART2) || \
                                    ((INSTANCE) == USART3))

/********************* UART Instances : Half-Duplex mode **********************/
#define IS_UART_HALFDUPLEX_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                               ((INSTANCE) == USART2) || \
                                               ((INSTANCE) == USART3))

/************************* UART Instances : LIN mode **************************/
#define IS_UART_LIN_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                        ((INSTANCE) == USART2) || \
                                        ((INSTANCE) == USART3))

/******************* UART Instances : Hardware Flow control *******************/
#define IS_UART_HWFLOW_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                           ((INSTANCE) == USART2) || \
                                           ((INSTANCE) == USART3))

/********************* UART Instances : Smard card mode ***********************/
#define IS_SMARTCARD_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                         ((INSTANCE) == USART2) || \
                                         ((INSTANCE) == USART3))

/************************* UART Instances : IRDA mode *************************/
#define IS_IRDA_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                    ((INSTANCE) == USART2) || \
                                    ((INSTANCE) == USART3))

/******************* UART Instances : Multi-Processor mode ********************/
#define IS_UART_MULTIPROCESSOR_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                                   ((INSTANCE) == USART2) || \
                                                   ((INSTANCE) == USART3))

/******************** UART Instances : DMA mode available *********************/
#define IS_UART_DMA_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                        ((INSTANCE) == USART2) || \
                                        ((INSTANCE) == USART3))

/******************************* ERTC Instances *******************************/
#define IS_ERTC_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == ERTC)

/******************************* WWDT Instances *******************************/
#define IS_WWDT_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == WWDT)

#define CRM_HEXT_MIN        4000000U
#define CRM_HEXT_MAX       25000000U

#define CRM_MAX_FREQUENCY 150000000U

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __AT32F415Cx_H */

/*********************** (C) COPYRIGHT Artery Technology *****END OF FILE****/
