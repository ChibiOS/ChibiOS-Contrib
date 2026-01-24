/**
  **************************************************************************
  * @file     at32f435_437rx.h
  * @author   Artery Technology & HorrorTroll & Zhaqian & Maxjta
  * @brief    at32f435_437rx header file
  **************************************************************************
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

/** @addtogroup AT32F435_437rx
  * @{
  */

#ifndef __AT32F435_437Rx_H
#define __AT32F435_437Rx_H

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief at32f435_437 standard peripheral library version number
  */
 #define __AT32F435_437_LIBRARY_VERSION_MAJOR    (0x02) /*!< [31:24] major version */
 #define __AT32F435_437_LIBRARY_VERSION_MIDDLE   (0x02) /*!< [23:16] middle version */
 #define __AT32F435_437_LIBRARY_VERSION_MINOR    (0x02) /*!< [15:8]  minor version */
 #define __AT32F435_437_LIBRARY_VERSION_RC       (0x00) /*!< [7:0]  release candidate */
 #define __AT32F435_437_LIBRARY_VERSION          ((__AT32F435_437_LIBRARY_VERSION_MAJOR << 24)  | \
                                                  (__AT32F435_437_LIBRARY_VERSION_MIDDLE << 16) | \
                                                  (__AT32F435_437_LIBRARY_VERSION_MINOR << 8)   | \
                                                  (__AT32F435_437_LIBRARY_VERSION_RC))
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
#define __FPU_PRESENT              1U       /*!< AT32 devices provide an FPU                  */

/**
  * @}
  */

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */
/**
  * @brief at32f435_437 interrupt number definition, according to the selected device
  *        in @ref library_configuration_section
  */
 typedef enum IRQn
 {
     /******  cortex-m4 processor exceptions numbers ***************************************************/
     Reset_IRQn                  = -15,    /*!< 1 reset vector, invoked on power up and warm reset   */
     NonMaskableInt_IRQn         = -14,    /*!< 2 non maskable interrupt                             */
     HardFault_IRQn              = -13,    /*!< 3 hard fault, all classes of fault                   */
     MemoryManagement_IRQn       = -12,    /*!< 4 cortex-m4 memory management interrupt              */
     BusFault_IRQn               = -11,    /*!< 5 cortex-m4 bus fault interrupt                      */
     UsageFault_IRQn             = -10,    /*!< 6 cortex-m4 usage fault interrupt                    */
     SVCall_IRQn                 = -5,     /*!< 11 cortex-m4 sv call interrupt                       */
     DebugMonitor_IRQn           = -4,     /*!< 12 cortex-m4 debug monitor interrupt                 */
     PendSV_IRQn                 = -2,     /*!< 14 cortex-m4 pend sv interrupt                       */
     SysTick_IRQn                = -1,     /*!< 15 cortex-m4 system tick interrupt                   */
 
     /******  at32 specific interrupt numbers *********************************************************/
     WWDT_IRQn                   = 0,      /*!< window watchdog timer interrupt                      */
     PVM_IRQn                    = 1,      /*!< pvm through exint line detection interrupt           */
     TAMP_STAMP_IRQn             = 2,      /*!< tamper and timestamp interrupts through the exint line */
     ERTC_WKUP_IRQn              = 3,      /*!< ertc wakeup through the exint line                   */
     FLASH_IRQn                  = 4,      /*!< flash global interrupt                               */
     CRM_IRQn                    = 5,      /*!< crm global interrupt                                 */
     EXINT0_IRQn                 = 6,      /*!< exint line0 interrupt                                */
     EXINT1_IRQn                 = 7,      /*!< exint line1 interrupt                                */
     EXINT2_IRQn                 = 8,      /*!< exint line2 interrupt                                */
     EXINT3_IRQn                 = 9,      /*!< exint line3 interrupt                                */
     EXINT4_IRQn                 = 10,     /*!< exint line4 interrupt                                */
     EDMA_Stream1_IRQn           = 11,     /*!< edma stream 1 global interrupt                       */
     EDMA_Stream2_IRQn           = 12,     /*!< edma stream 2 global interrupt                       */
     EDMA_Stream3_IRQn           = 13,     /*!< edma stream 3 global interrupt                       */
     EDMA_Stream4_IRQn           = 14,     /*!< edma stream 4 global interrupt                       */
     EDMA_Stream5_IRQn           = 15,     /*!< edma stream 5 global interrupt                       */
     EDMA_Stream6_IRQn           = 16,     /*!< edma stream 6 global interrupt                       */
     EDMA_Stream7_IRQn           = 17,     /*!< edma stream 7 global interrupt                       */
     ADC1_2_3_IRQn               = 18,     /*!< adc1 adc2 and adc3 global interrupt                  */
     CAN1_TX_IRQn                = 19,     /*!< can1 tx interrupts                                   */
     CAN1_RX0_IRQn               = 20,     /*!< can1 rx0 interrupts                                  */
     CAN1_RX1_IRQn               = 21,     /*!< can1 rx1 interrupt                                   */
     CAN1_SE_IRQn                = 22,     /*!< can1 se interrupt                                    */
     EXINT9_5_IRQn               = 23,     /*!< external line[9:5] interrupts                        */
     TMR1_BRK_TMR9_IRQn          = 24,     /*!< tmr1 brake interrupt                                 */
     TMR1_OVF_TMR10_IRQn         = 25,     /*!< tmr1 overflow interrupt                              */
     TMR1_TRG_HALL_TMR11_IRQn    = 26,     /*!< tmr1 trigger and hall interrupt                      */
     TMR1_CH_IRQn                = 27,     /*!< tmr1 channel interrupt                               */
     TMR2_GLOBAL_IRQn            = 28,     /*!< tmr2 global interrupt                                */
     TMR3_GLOBAL_IRQn            = 29,     /*!< tmr3 global interrupt                                */
     TMR4_GLOBAL_IRQn            = 30,     /*!< tmr4 global interrupt                                */
     I2C1_EVT_IRQn               = 31,     /*!< i2c1 event interrupt                                 */
     I2C1_ERR_IRQn               = 32,     /*!< i2c1 error interrupt                                 */
     I2C2_EVT_IRQn               = 33,     /*!< i2c2 event interrupt                                 */
     I2C2_ERR_IRQn               = 34,     /*!< i2c2 error interrupt                                 */
     SPI1_IRQn                   = 35,     /*!< spi1 global interrupt                                */
     SPI2_I2S2EXT_IRQn           = 36,     /*!< spi2 global interrupt                                */
     USART1_IRQn                 = 37,     /*!< usart1 global interrupt                              */
     USART2_IRQn                 = 38,     /*!< usart2 global interrupt                              */
     USART3_IRQn                 = 39,     /*!< usart3 global interrupt                              */
     EXINT15_10_IRQn             = 40,     /*!< external line[15:10] interrupts                      */
     ERTCAlarm_IRQn              = 41,     /*!< ertc alarm through exint line interrupt              */
     OTGFS1_WKUP_IRQn            = 42,     /*!< otgfs1 wakeup from suspend through exint line interrupt */
     TMR8_BRK_TMR12_IRQn         = 43,     /*!< tmr8 brake interrupt                                 */
     TMR8_OVF_TMR13_IRQn         = 44,     /*!< tmr8 overflow interrupt                              */
     TMR8_TRG_HALL_TMR14_IRQn    = 45,     /*!< tmr8 trigger and hall interrupt                      */
     TMR8_CH_IRQn                = 46,     /*!< tmr8 channel interrupt                               */
     EDMA_Stream8_IRQn           = 47,     /*!< dma1 stream 8 global interrupt                       */
     XMC_IRQn                    = 48,     /*!< xmc global interrupt                                 */
     SDIO1_IRQn                  = 49,     /*!< sdio global interrupt                                */
     TMR5_GLOBAL_IRQn            = 50,     /*!< tmr5 global interrupt                                */
     SPI3_I2S3EXT_IRQn           = 51,     /*!< spi3 global interrupt                                */
     UART4_IRQn                  = 52,     /*!< uart4 global interrupt                               */
     UART5_IRQn                  = 53,     /*!< uart5 global interrupt                               */
     TMR6_DAC_GLOBAL_IRQn        = 54,     /*!< tmr6 and dac global interrupt                        */
     TMR7_GLOBAL_IRQn            = 55,     /*!< tmr7 global interrupt                                */
     DMA1_Channel1_IRQn          = 56,     /*!< dma1 channel 0 global interrupt                      */
     DMA1_Channel2_IRQn          = 57,     /*!< dma1 channel 1 global interrupt                      */
     DMA1_Channel3_IRQn          = 58,     /*!< dma1 channel 2 global interrupt                      */
     DMA1_Channel4_IRQn          = 59,     /*!< dma1 channel 3 global interrupt                      */
     DMA1_Channel5_IRQn          = 60,     /*!< dma1 channel 4 global interrupt                      */
     EMAC_IRQn                   = 61,     /*!< emac interrupt                                       */
     EMAC_WKUP_IRQn              = 62,     /*!< emac wakeup interrupt                                */
     CAN2_TX_IRQn                = 63,     /*!< can2 tx interrupt                                    */
     CAN2_RX0_IRQn               = 64,     /*!< can2 rx0 interrupt                                   */
     CAN2_RX1_IRQn               = 65,     /*!< can2 rx1 interrupt                                   */
     CAN2_SE_IRQn                = 66,     /*!< can2 se interrupt                                    */
     OTGFS1_IRQn                 = 67,     /*!< otgfs1 interrupt                                     */
     DMA1_Channel6_IRQn          = 68,     /*!< dma1 channel 5 global interrupt                      */
     DMA1_Channel7_IRQn          = 69,     /*!< dma1 channel 6 global interrupt                      */
     USART6_IRQn                 = 71,     /*!< usart6 interrupt                                     */
     I2C3_EVT_IRQn               = 72,     /*!< i2c3 event interrupt                                 */
     I2C3_ERR_IRQn               = 73,     /*!< i2c3 error interrupt                                 */
     OTGFS2_WKUP_IRQn            = 76,     /*!< otgfs2 wakeup from suspend through exint line interrupt */
     OTGFS2_IRQn                 = 77,     /*!< otgfs2 interrupt                                     */
     DVP_IRQn                    = 78,     /*!< dvp interrupt                                        */
     FPU_IRQn                    = 81,     /*!< fpu interrupt                                        */
     UART7_IRQn                  = 82,     /*!< uart7 interrupt                                      */
     UART8_IRQn                  = 83,     /*!< uart8 interrupt                                      */
     SPI4_IRQn                   = 84,     /*!< spi4 global interrupt                                */
     QSPI2_IRQn                  = 91,     /*!< qspi2 global interrupt                               */
     QSPI1_IRQn                  = 92,     /*!< qspi1 global interrupt                               */
     DMAMUX_IRQn                 = 94,     /*!< dmamux global interrupt                              */
     SDIO2_IRQn                  = 102,    /*!< sdio2 global interrupt                               */
     ACC_IRQn                    = 103,    /*!< acc interrupt                                        */
     TMR20_BRK_IRQn              = 104,    /*!< tmr20 brake interrupt                                */
     TMR20_OVF_IRQn              = 105,    /*!< tmr20 overflow interrupt                             */
     TMR20_TRG_HALL_IRQn         = 106,    /*!< tmr20 trigger and hall interrupt                     */
     TMR20_CH_IRQn               = 107,    /*!< tmr20 channel interrupt                              */
     DMA2_Channel1_IRQn          = 108,    /*!< dma2 channel 1 global interrupt                      */
     DMA2_Channel2_IRQn          = 109,    /*!< dma2 channel 2 global interrupt                      */
     DMA2_Channel3_IRQn          = 110,    /*!< dma2 channel 3 global interrupt                      */
     DMA2_Channel4_IRQn          = 111,    /*!< dma2 channel 4 global interrupt                      */
     DMA2_Channel5_IRQn          = 112,    /*!< dma2 channel 5 global interrupt                      */
     DMA2_Channel6_IRQn          = 113,    /*!< dma2 channel 6 global interrupt                      */
     DMA2_Channel7_IRQn          = 114,    /*!< dma2 channel 7 global interrupt                      */
 } IRQn_Type;

/**
  * @}
  */

#include "core_cm4.h"
#include "system_at32f435_437.h"
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */

/**
  * @brief HICK Auto Clock Calibration (ACC)
  */

typedef struct
{                                                   /*!< ACC Structure                                                         */
  __IO uint32_t  STS;                               /*!< status register                                                       */
  __IO uint32_t  CTRL1;                             /*!< control register 1                                                    */
  __IO uint32_t  CTRL2;                             /*!< control register 2                                                    */
  __IO uint32_t  CC1;                               /*!< compare value 1                                                       */
  __IO uint32_t  CC2;                               /*!< compare value 2                                                       */
  __IO uint32_t  CC3;                               /*!< compare value 3                                                       */
} ACC_TypeDef;

/**
  * @brief Analog to digital converter (ADC)
  */

typedef struct
{                                                   /*!< ADC Structure                                                         */
  __IO uint32_t  STS;                               /*!< status register                                                       */
  __IO uint32_t  CTRL1;                             /*!< control register 1                                                    */
  __IO uint32_t  CTRL2;                             /*!< control register 2                                                    */
  __IO uint32_t  SPT1;                              /*!< sample time register 1                                                */
  __IO uint32_t  SPT2;                              /*!< sample time register 2                                                */
  __IO uint32_t  PCDTO1;                            /*!< Preempted channel 1 data offset register                              */
  __IO uint32_t  PCDTO2;                            /*!< Preempted channel 2 data offset register                              */
  __IO uint32_t  PCDTO3;                            /*!< Preempted channel 3 data offset register                              */
  __IO uint32_t  PCDTO4;                            /*!< Preempted channel 4 data offset register                              */
  __IO uint32_t  VMHB;                              /*!< Voltage monitoring high boundary register                             */
  __IO uint32_t  VMLB;                              /*!< Voltage monitoring low boundary register                              */
  __IO uint32_t  OSQ1;                              /*!< Ordinary sequence register 1                                          */
  __IO uint32_t  OSQ2;                              /*!< Ordinary sequence register 2                                          */
  __IO uint32_t  OSQ3;                              /*!< Ordinary sequence register 3                                          */
  __IO uint32_t  PSQ;                               /*!< Preempted sequence register                                           */
  __IO uint32_t  PDT1;                              /*!< Preempted data register 1                                             */
  __IO uint32_t  PDT2;                              /*!< Preempted data register 2                                             */
  __IO uint32_t  PDT3;                              /*!< Preempted data register 3                                             */
  __IO uint32_t  PDT4;                              /*!< Preempted data register 4                                             */
  __IO uint32_t  ODT;                               /*!< Ordinary data register                                                */
  __IO uint32_t  RESERVED0[12];
  __IO uint32_t  OVSP;                              /*!< oversampling register                                                 */
  __IO uint32_t  RESERVED1[12];
  __IO uint32_t  CALVAL;                            /*!< A/D calibration value                                                 */
} ADC_TypeDef;

/**
  * @brief ADC common area (ADCCOM)
  */

typedef struct
{                                                   /*!< ADCCOM Structure                                                      */
  __IO uint32_t  CSTS;                              /*!< Common status register                                                */
  __IO uint32_t  CCTRL;                             /*!< Common control register                                               */
  __IO uint32_t  CODT;                              /*!< Common data register                                                  */
} ADC_Common_TypeDef;

/**
  * @brief Controller Area Network TX Mailbox Registers
  */

typedef struct
{
  __IO uint32_t  TMI;                               /*!< Transmit mailbox identifier register                                  */
  __IO uint32_t  TMC;                               /*!< Transmit mailbox data length and time stamp register                  */
  __IO uint32_t  TMDTL;                             /*!< Transmit mailbox low byte data register                               */
  __IO uint32_t  TMDTH;                             /*!< Transmit mailbox high byte data register                              */
} CAN_TxMailBox_TypeDef;

/**
  * @brief Controller Area Network FIFO Mailbox Registers
  */

typedef struct
{
  __IO uint32_t  RFI;                               /*!< Receive FIFO register                                                 */
  __IO uint32_t  RFC;                               /*!< Receive FIFO data length and time stamp register                      */
  __IO uint32_t  RFDTL;                             /*!< Receive FIFO low byte data register                                   */
  __IO uint32_t  RFDTH;                             /*!< Receive FIFO high byte data register                                  */
} CAN_FIFOMailBox_TypeDef;

/**
  * @brief Controller Area Network Filter Registers
  */

typedef struct
{
  __IO uint32_t  FFB1;                              /*!< Filter bank filtrate bit register 1                                   */
  __IO uint32_t  FFB2;                              /*!< Filter bank filtrate bit register 2                                   */
} CAN_FilterRegister_TypeDef;

/**
  * @brief Controller Area Network
  */

typedef struct
{                                                   /*!< CAN Structure                                                         */
  __IO uint32_t  MCTRL;                             /*!< Main control register                                                 */
  __IO uint32_t  MSTS;                              /*!< Main status register                                                  */
  __IO uint32_t  TSTS;                              /*!< Transmit status register                                              */
  __IO uint32_t  RF0;                               /*!< Receive FIFO 0 register                                               */
  __IO uint32_t  RF1;                               /*!< Receive FIFO 1 register                                               */
  __IO uint32_t  INTEN;                             /*!< Interrupt enable register                                             */
  __IO uint32_t  ESTS;                              /*!< Error status register                                                 */
  __IO uint32_t  BTMG;                              /*!< Bit timing register                                                   */
  __IO uint32_t  RESERVED0[88];
  CAN_TxMailBox_TypeDef  sTxMailBox[3];             /*!< Transmit mailbox registers                                            */
  CAN_FIFOMailBox_TypeDef  sFIFOMailBox[2];         /*!< Receive FIFO registers                                                */
  __IO uint32_t  RESERVED1[12];
  __IO uint32_t  FCTRL;                              /*!< Filter control register                                              */
  __IO uint32_t  FMCFG;                              /*!< Filter mode config register                                          */
  __IO uint32_t  RESERVED2;
  __IO uint32_t  FBWCFG;                             /*!< Filter bit width config register                                     */
  __IO uint32_t  RESERVED3;
  __IO uint32_t  FRF;                                /*!< Filter related FIFO register                                         */
  __IO uint32_t  RESERVED4;
  __IO uint32_t  FACFG;                              /*!< Filter activate configuration register                               */
  __IO uint32_t  RESERVED5[8];
  CAN_FilterRegister_TypeDef  sFilterRegister[14];   /*!< Filter registers                                                     */
} CAN_TypeDef;

/**
  * @brief CRC calculation unit (CRC)
  */

typedef struct
{                                                   /*!< CRC Structure                                                         */
  __IO uint32_t  DT;                                /*!< Data register                                                         */
  __IO uint32_t  CDT;                               /*!< Common data register                                                  */
  __IO uint32_t  CTRL;                              /*!< Control register                                                      */
  __IO uint32_t  RESERVED0;
  __IO uint32_t  IDT;                               /*!< Initial data register                                                 */
  __IO uint32_t  POLY;                              /*!< Polynomial coefficient register                                       */
} CRC_TypeDef;

/**
  * @brief Clock and reset management (CRM)
  */

typedef struct
{                                                   /*!< CRM Structure                                                         */
  __IO uint32_t  CTRL;                              /*!< Clock control register                                                */
  __IO uint32_t  PLLCFG;                            /*!< PLL configuration register (CRM_PLLCFG)                               */
  __IO uint32_t  CFG;                               /*!< Clock configuration register(CRM_CFG)                                 */
  __IO uint32_t  CLKINT;                            /*!< Clock interrupt register (CRM_CLKINT)                                 */
  __IO uint32_t  AHBRST1;                           /*!< AHB peripheral reset register1 (CRM_AHBRST1)                          */
  __IO uint32_t  AHBRST2;                           /*!< AHB peripheral reset register 2 (CRM_AHBRST2)                         */
  __IO uint32_t  AHBRST3;                           /*!< AHB peripheral reset register 3 (CRM_AHBRST3)                         */
  __IO uint32_t  RESERVED0;
  __IO uint32_t  APB1RST;                           /*!< APB1 peripheral reset register (CRM_APB1RST)                          */
  __IO uint32_t  APB2RST;                           /*!< APB2 peripheral reset register (CRM_APB2RST)                          */
  __IO uint32_t  RESERVED1[2];
  __IO uint32_t  AHBEN1;                            /*!< AHB Peripheral Clock enable register 1 (CRM_AHBEN1)                   */
  __IO uint32_t  AHBEN2;                            /*!< AHB peripheral clock enable register 2 (CRM_AHBEN2)                   */
  __IO uint32_t  AHBEN3;                            /*!< AHB peripheral clock enable register 3 (CRM_AHBEN3)                   */
  __IO uint32_t  RESERVED2;
  __IO uint32_t  APB1EN;                            /*!< APB1 peripheral clock enable register (CRM_APB1EN)                    */
  __IO uint32_t  APB2EN;                            /*!< APB2 peripheral clock enable register (CRM_APB2EN)                    */
  __IO uint32_t  RESERVED3[2];
  __IO uint32_t  AHBLPEN1;                          /*!< AHB Low-power Peripheral Clock enable register 1 (CRM_AHBLPEN1)       */
  __IO uint32_t  AHBLPEN2;                          /*!< AHB peripheral Low-power clock enable register 2 (CRM_AHBLPEN2)       */
  __IO uint32_t  AHBLPEN3;                          /*!< AHB peripheral Low-power clock enable register 3 (CRM_AHBLPEN3)       */
  __IO uint32_t  RESERVED4;
  __IO uint32_t  APB1LPEN;                          /*!< APB1 peripheral Low-power clock enable register (CRM_APB1LPEN)        */
  __IO uint32_t  APB2LPEN;                          /*!< APB2 peripheral Low-power clock enable register (CRM_APB2LPEN)        */
  __IO uint32_t  RESERVED5[2];
  __IO uint32_t  BPDC;                              /*!< Battery powered domain control register (CRM_BPDC)                    */
  __IO uint32_t  CTRLSTS;                           /*!< Control/status register (CRM_CTRLSTS)                                 */
  __IO uint32_t  RESERVED6[10];
  __IO uint32_t  MISC1;                             /*!< Miscellaneous register1                                               */
  __IO uint32_t  MISC2;                             /*!< Miscellaneous register2                                               */
} CRM_TypeDef;

/**
  * @brief Debug support (DEBUG)
  */

typedef struct
{                                                   /*!< DEBUG Structure                                                       */
  __IO uint32_t  IDCODE;                            /*!< DEBUG IDCODE                                                          */
  __IO uint32_t  CTRL;                              /*!< DEBUG CTRL                                                            */
  __IO uint32_t  APB1_PAUSE;                        /*!< DEBUG APB1 PAUSE                                                      */
  __IO uint32_t  APB2_PAUSE;                        /*!< DEBUG APB2 PAUSE                                                      */
} DEBUG_TypeDef;

/**
  * @brief DMA controller (DMA)
  */

typedef struct
{                                                   /*!< DMA Structure                                                         */
  __IO uint32_t  STS;                               /*!< DMA interrupt status register (DMA_STS)                               */
  __IO uint32_t  CLR;                               /*!< DMA interrupt flag clear register (DMA_CLR)                           */
  __IO uint32_t  RESERVED1[62];
  __IO uint32_t  MUXSEL;                            /*!< DMAMUX Table Selection                                                */
} DMA_TypeDef;

/**
  * @brief DMA controller Channel(DMA Channel)
  */
typedef struct
{                                                   /*!< DMA Channel Structure                                                 */
  __IO uint32_t  CCTRL;                              /*!< DMA channel configuration register                                    */
  __IO uint32_t  CDTCNT;                             /*!< DMA channel number of data to transfer register                       */
  __IO uint32_t  CPADDR;                             /*!< DMA channel peripheral base address register                          */
  __IO uint32_t  CMADDR;                             /*!< DMA channel memory base address register                              */
} DMA_Channel_TypeDef;

/**
  * @brief DMA MUX controller
  */
typedef struct
{
  __IO uint32_t  MUXCCTRL;                            /*!< Channel Configuration Register                                       */

} DMAMUX_Channel_TypeDef;

typedef struct
{
  __IO uint32_t MUXSYNCSTS;      /*!< DMA multiplexed channel sync status reg,     Address offset: 0x130 */
  __IO uint32_t MUXSYNCCLR;      /*!< DMA multiplexed channel irq flag clear reg,  Address offset: 0x134 */
} DMAMUX_ChannelStatus_TypeDef;

typedef struct
{
  __IO uint32_t MUXGCTRL;        /*!< DMA multiplexed generator x control reg,     Address offset: 0x120 + 4 * (x - 1) (x = 1 ... 4) */
} DMAMUX_Generator_TypeDef;

typedef struct
{
  __IO uint32_t MUXGSTS;         /*!< DMA multiplexed generator irq status reg,    Address offset: 0x138 */
  __IO uint32_t MUXGCLR;         /*!< DMA mux generator irq flag clear register,   Address offset: 0x13c */
} DMAMUX_GeneratorStatus_TypeDef;

/**
  * @brief Real-time clock (ERTC)
  */

typedef struct
{                                                   /*!< ERTC Structure                                                        */
  __IO uint32_t  TIME;                              /*!< time register                                                         */
  __IO uint32_t  DATE;                              /*!< date register                                                         */
  __IO uint32_t  CTRL;                              /*!< control register                                                      */
  __IO uint32_t  STS;                               /*!< initialization and status register                                    */
  __IO uint32_t  DIV;                               /*!< Diveder register                                                      */
  __IO uint32_t  WAT;                               /*!< Wakeup timer register                                                 */
  __IO uint32_t  CCAL;                              /*!< Calibration register                                                  */
  __IO uint32_t  ALA;                               /*!< Alarm A register                                                      */
  __IO uint32_t  ALB;                               /*!< Alarm B register                                                      */
  __IO uint32_t  WP;                                /*!< write protection register                                             */
  __IO uint32_t  SBS;                               /*!< sub second register                                                   */
  __IO uint32_t  TADJ;                              /*!< time adjust register                                                  */
  __IO uint32_t  TSTM;                              /*!< time stamp time register                                              */
  __IO uint32_t  TSDT;                              /*!< timestamp date register                                               */
  __IO uint32_t  TSSBS;                             /*!< timestamp sub second register                                         */
  __IO uint32_t  SCAL;                              /*!< calibration register                                                  */
  __IO uint32_t  TAMP;                              /*!< tamper and alternate function configuration register                  */
  __IO uint32_t  ALASBS;                            /*!< alarm A sub second register                                           */
  __IO uint32_t  ALBSBS;                            /*!< alarm B sub second register                                           */
  __IO uint32_t  RESERVED0;
  __IO uint32_t  BPR1;                              /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR2;                              /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR3;                              /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR4;                              /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR5;                              /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR6;                              /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR7;                              /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR8;                              /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR9;                              /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR10;                             /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR11;                             /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR12;                             /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR13;                             /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR14;                             /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR15;                             /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR16;                             /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR17;                             /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR18;                             /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR19;                             /*!< Battery powered domain register                                       */
  __IO uint32_t  BPR20;                             /*!< Battery powered domain register                                       */
} ERTC_TypeDef;

/**
  * @brief External Interrupt/Event Controller
  */

typedef struct
{                                                   /*!< EXINT Structure                                                       */
  __IO uint32_t  INTEN;                             /*!< Interrupt enable register                                             */
  __IO uint32_t  EVTEN;                             /*!< Event enable register                                                 */
  __IO uint32_t  POLCFG1;                           /*!< Rising polarity configuration register                                */
  __IO uint32_t  POLCFG2;                           /*!< Falling polarity configuration register                               */
  __IO uint32_t  SWTRG;                             /*!< Software triggle register                                             */
  __IO uint32_t  INTSTS;                            /*!< Interrupt status register                                             */
} EXINT_TypeDef;

/**
  * @brief Flash memory controler (FLASH)
  */

typedef struct
{                                                   /*!< FLASH Structure                                                       */
  __IO uint32_t  PSR;                               /*!< Performance selection register                                        */
  __IO uint32_t  UNLOCK;                            /*!< Unlock register                                                       */
  __IO uint32_t  USD_UNLOCK;                        /*!< USD unlock register                                                   */
  __IO uint32_t  STS;                               /*!< Status register                                                       */
  __IO uint32_t  CTRL;                              /*!< Control register                                                      */
  __IO uint32_t  ADDR;                              /*!< Address register                                                      */
  __IO uint32_t  RESERVED0;
  __IO uint32_t  USD;                               /*!< User system data register                                             */
  __IO uint32_t  EPPS0;                             /*!< Erase/program protection status register                              */
  __IO uint32_t  RESERVED1[2];
  __IO uint32_t  EPPS1;                             /*!< Erase/program protection status register                              */
  __IO uint32_t  RESERVED2[5];
  __IO uint32_t  UNLOCK2;                           /*!< Bank2 Unlock register                                                 */
  __IO uint32_t  RESERVED3;
  __IO uint32_t  STS2;                              /*!< Bank2 Status register                                                 */
  __IO uint32_t  CTRL2;                             /*!< Bank2 Control register                                                */
  __IO uint32_t  ADDR2;                             /*!< Bank2 Address register                                                */
  __IO uint32_t  CONTR;                             /*!< Flash continue read enable register                                   */
  __IO uint32_t  RESERVED4;
  __IO uint32_t  DIVR;                              /*!< Flash divider register                                                */
  __IO uint32_t  RESERVED5[25];
  __IO uint32_t  SLIB_STS2;                         /*!< sLib status 2 register                                                */
  __IO uint32_t  SLIB_STS0;                         /*!< sLib status 0 register                                                */
  __IO uint32_t  SLIB_STS1;                         /*!< sLib status 1 register                                                */
  __IO uint32_t  SLIB_PWD_CLR;                      /*!< SLIB password clear register                                          */
  __IO uint32_t  SLIB_MISC_STS;                     /*!< sLib misc status register                                             */
  __IO uint32_t  SLIB_SET_PWD;                      /*!< sLib password setting register                                        */
  __IO uint32_t  SLIB_SET_RANGE0;                   /*!< Configure sLib range 0 register                                       */
  __IO uint32_t  SLIB_SET_RANGE1;                   /*!< Configure sLib range 1 register                                       */
  __IO uint32_t  RESERVED6[2];
  __IO uint32_t  SLIB_UNLOCK;                       /*!< sLib unlock register                                                  */
  __IO uint32_t  CRC_CTRL;                          /*!< Flash CRC controll register                                           */
  __IO uint32_t  CRC_CHKR;                          /*!< FLASH CRC check result register                                       */
} FLASH_TypeDef;

/**
  * @brief General purpose I/Os (GPIO)
  */

typedef struct
{                                                   /*!< GPIO Structure                                                       */
  __IO uint32_t  CFGR;                              /*!< GPIO configuration register                                           */
  __IO uint32_t  OMODE;                             /*!< GPIO output mode register                                             */
  __IO uint32_t  ODRVR;                             /*!< GPIO drive capability register                                        */
  __IO uint32_t  PULL;                              /*!< GPIO pull-up/pull-down register                                       */
  __IO uint32_t  IDT;                               /*!< GPIO input data register                                              */
  __IO uint32_t  ODT;                               /*!< GPIO output data register                                             */
  __IO uint32_t  SCR;                               /*!< Port bit set/clear register                                           */
  __IO uint32_t  WPR;                               /*!< Port write protect register                                           */
  __IO uint32_t  MUXL;                              /*!< GPIO muxing function low register                                     */
  __IO uint32_t  MUXH;                              /*!< GPIO muxing function high register                                    */
  __IO uint32_t  CLR;                               /*!< GPIO bit reset register                                               */
  __IO uint32_t  RESERVED0[4];
  __IO uint32_t  HDRV;                              /*!< Huge current driver                                                   */
} GPIO_TypeDef;

/**
  * @brief Inter-integrated circuit (I2C)
  */

typedef struct
{                                                   /*!< I2C Structure                                                         */
  __IO uint32_t  CTRL1;                             /*!< Control register 1                                                    */
  __IO uint32_t  CTRL2;                             /*!< Control register 2                                                    */
  __IO uint32_t  OADDR1;                            /*!< Own address register 1                                                */
  __IO uint32_t  OADDR2;                            /*!< Own address register 2                                                */
  __IO uint32_t  CLKCTRL;                           /*!< Clock contorl register                                                */
  __IO uint32_t  TIMEOUT;                           /*!< Timeout register                                                      */
  __IO uint32_t  STS;                               /*!< Interrupt and Status register                                         */
  __IO uint32_t  CLR;                               /*!< Interrupt clear register                                              */
  __IO uint32_t  PEC;                               /*!< PEC register                                                          */
  __IO uint32_t  RXDT;                              /*!< Receive data register                                                 */
  __IO uint32_t  TXDT;                              /*!< Transmit data register                                                */
} I2C_TypeDef;

/**
  * @brief Power control (PWC)
  */

typedef struct
{                                                   /*!< PWC Structure                                                         */
  __IO uint32_t  CTRL;                              /*!< Power control register (PWC_CTRL)                                     */
  __IO uint32_t  CTRLSTS;                           /*!< Power control and status register (PWC_CTRLSTS)                       */
  __IO uint32_t  RESERVED0[2];
  __IO uint32_t  LDOOV;                             /*!< LDO output voltage register                                           */
} PWC_TypeDef;

/**
  * @brief Quad SPI Controller (QSPI)
  */

typedef struct
{                                                   /*!< QSPI Structure                                                       */
  __IO uint32_t  CMD_W0;                            /*!< Command word 0                                                        */
  __IO uint32_t  CMD_W1;                            /*!< Command word 1                                                        */
  __IO uint32_t  CMD_W2;                            /*!< Command word 2                                                        */
  __IO uint32_t  CMD_W3;                            /*!< Command word 3                                                        */
  __IO uint32_t  CTRL;                              /*!< Control register                                                      */
  __IO uint32_t  RESERVED0;
  __IO uint32_t  FIFOSTS;                           /*!< FIFO Status register                                                  */
  __IO uint32_t  RESERVED1;
  __IO uint32_t  CTRL2;                             /*!< control register 2                                                    */
  __IO uint32_t  CMDSTS;                            /*!< CMD status register                                                   */
  __IO uint32_t  RSTS;                              /*!< SPI read status register                                              */
  __IO uint32_t  FSIZE;                             /*!< SPI flash size                                                        */
  __IO uint32_t  XIP_CMD_W0;                        /*!< XIP command word 0                                                    */
  __IO uint32_t  XIP_CMD_W1;                        /*!< XIP command word 1                                                    */
  __IO uint32_t  XIP_CMD_W2;                        /*!< XIP command word 2                                                    */
  __IO uint32_t  XIP_CMD_W3;                        /*!< XIP command word 3                                                    */
  __IO uint32_t  CTRL3;                             /*!< control register 3                                                    */
  __IO uint32_t  RESERVED2[3];
  __IO uint32_t  REV;                               /*!< Revision                                                              */
  __IO uint32_t  RESERVED3[43];
  __IO uint32_t  DT;                                /*!< 32/16/8 bit data port register                                        */
} QSPI_TypeDef;

/**
  * @brief System configuration controller (SCFG)
  */

typedef struct
{                                                   /*!< SCFG Structure                                                        */
  __IO uint32_t  CFG1;                              /*!< configuration register 1                                              */
  __IO uint32_t  CFG2;                              /*!< configuration register 2                                              */
  __IO uint32_t  EXINTC[4];                         /*!< external interrupt configuration register 1,2,3,4                     */
  __IO uint32_t  RESERVED0[5];
  __IO uint32_t  UHDRV;                             /*!< Ultra high drive register                                             */
} SCFG_TypeDef;

/**
  * @brief SD Host Interface
  */

typedef struct
{
  __IO uint32_t  PWRCTRL;          /*!< SDIO power control register,                 Address offset: 0x00        */
  __IO uint32_t  CLKCTRL;          /*!< SDIO clock control register,                 Address offset: 0x04        */
  __IO uint32_t  ARG;              /*!< SDIO argument register,                      Address offset: 0x08        */
  __IO uint32_t  CMD;              /*!< SDIO command register,                       Address offset: 0x0C        */
  __I  uint32_t  RSPCMD;           /*!< SDIO command response register,              Address offset: 0x10        */
  __I  uint32_t  RSP1;             /*!< SDIO response register 1,                    Address offset: 0x14        */
  __I  uint32_t  RSP2;             /*!< SDIO response register 2,                    Address offset: 0x18        */
  __I  uint32_t  RSP3;             /*!< SDIO response register 3,                    Address offset: 0x1C        */
  __I  uint32_t  RSP4;             /*!< SDIO response register 4,                    Address offset: 0x20        */
  __IO uint32_t  DTTMR;            /*!< SDIO data timer register,                    Address offset: 0x24        */
  __IO uint32_t  DTLEN;            /*!< SDIO data length register,                   Address offset: 0x28        */
  __IO uint32_t  DTCTRL;           /*!< SDIO data control register,                  Address offset: 0x2C        */
  __I  uint32_t  DTCNTR;           /*!< SDIO data counter register,                  Address offset: 0x30        */
  __I  uint32_t  STS;              /*!< SDIO status register,                        Address offset: 0x34        */
  __IO uint32_t  INTCLR;           /*!< SDIO clear interrupt register,               Address offset: 0x38        */
  __IO uint32_t  INTEN;            /*!< SDIO interrupt mask register,                Address offset: 0x3C        */
  uint32_t       RESERVED0[2];     /*!< Reserved,                                    Address offset: 0x40 ~ 0x44 */
  __I  uint32_t  BUFCNTR;          /*!< SDIO BUF counter register,                   Address offset: 0x48        */
  uint32_t       RESERVED1[13];    /*!< Reserved,                                    Address offset: 0x4C ~ 0x7C */
  __IO uint32_t  BUF;              /*!< SDIO data BUF register,                      Address offset: 0x80        */
} SDIO_TypeDef;

/**
  * @brief Serial peripheral interface (SPI)
  */

typedef struct
{                                                   /*!< SPI Structure                                                         */
  __IO uint32_t  CTRL1;                             /*!< control register 1                                                    */
  __IO uint32_t  CTRL2;                             /*!< control register 2                                                    */
  __IO uint32_t  STS;                               /*!< status register                                                       */
  __IO uint32_t  DT;                                /*!< data register                                                         */
  __IO uint32_t  CPOLY;                             /*!< CRC polynomial register                                               */
  __IO uint32_t  RCRC;                              /*!< Receive CRC register                                                  */
  __IO uint32_t  TCRC;                              /*!< Transmit CRC register                                                 */
  __IO uint32_t  I2SCTRL;                           /*!< I2S control register                                                  */
  __IO uint32_t  I2SCLK;                            /*!< I2S clock register                                                    */
} SPI_TypeDef;

/**
  * @brief timer (TMR)
  */

typedef struct
{                                                   /*!< TMR Structure                                                         */
  __IO uint32_t  CTRL1;                             /*!< Control register 1                                                    */
  __IO uint32_t  CTRL2;                             /*!< Control register 2                                                    */
  __IO uint32_t  STCTRL;                            /*!< Subordinate TMR control register                                      */
  __IO uint32_t  IDEN;                              /*!< Interrupt/DMA enable register                                         */
  __IO uint32_t  ISTS;                              /*!< Interrupt status register                                             */
  __IO uint32_t  SWEVT;                             /*!< Software event register                                               */
  __IO uint32_t  CM1;                               /*!< Channel mode register 1                                               */
  __IO uint32_t  CM2;                               /*!< Channel mode register 2                                               */
  __IO uint32_t  CCTRL;                             /*!< Channel control register                                              */
  __IO uint32_t  CVAL;                              /*!< Counter value                                                         */
  __IO uint32_t  DIV;                               /*!< Divider value                                                         */
  __IO uint32_t  PR;                                /*!< Period value                                                          */
  __IO uint32_t  RPR;                               /*!< Repetition of period value                                            */
  __IO uint32_t  C1DT;                              /*!< Channel 1 data register                                               */
  __IO uint32_t  C2DT;                              /*!< Channel 2 data register                                               */
  __IO uint32_t  C3DT;                              /*!< Channel 3 data register                                               */
  __IO uint32_t  C4DT;                              /*!< Channel 4 data register                                               */
  __IO uint32_t  BRK;                               /*!< Brake register                                                        */
  __IO uint32_t  DMACTRL;                           /*!< DMA control register                                                  */
  __IO uint32_t  DMADT;                             /*!< DMA data register                                                     */
  __IO uint32_t  RMP;                               /*!< TMR input remap register                                             */
  __IO uint32_t  RESERVED0[7];
  __IO uint32_t  CM3;                               /*!< Channel output mode register                                          */
  __IO uint32_t  C5DT;                              /*!< Channel 5 data register                                               */
} TMR_TypeDef;

/**
  * @brief Universal synchronous asynchronous receiver transmitter (USART)
  */

typedef struct
{                                                   /*!< USART Structure                                                       */
  __IO uint32_t  STS;                               /*!< Status register                                                       */
  __IO uint32_t  DT;                                /*!< Data register                                                         */
  __IO uint32_t  BAUDR;                             /*!< Baud rate register                                                    */
  __IO uint32_t  CTRL1;                             /*!< Control register 1                                                    */
  __IO uint32_t  CTRL2;                             /*!< Control register 2                                                    */
  __IO uint32_t  CTRL3;                             /*!< Control register 3                                                    */
  __IO uint32_t  GDIV;                              /*!< Guard time and division register                                      */
} USART_TypeDef;

/**
  * @brief Watchdog (WDT)
  */

typedef struct
{                                                   /*!< WDT Structure                                                         */
  __IO uint32_t  CMD;                               /*!< Command register                                                      */
  __IO uint32_t  DIV;                               /*!< Division register                                                     */
  __IO uint32_t  RLD;                               /*!< Reload register                                                       */
  __IO uint32_t  STS;                               /*!< Status register                                                       */
  __IO uint32_t  WIN;                               /*!< Window register                                                       */
} WDT_TypeDef;

/**
  * @brief Window watchdog (WWDT)
  */

typedef struct
{                                                   /*!< WWDT Structure                                                        */
  __IO uint32_t  CTRL;                              /*!< Control register                                                      */
  __IO uint32_t  CFG;                               /*!< Configuration register                                                */
  __IO uint32_t  STS;                               /*!< Status register                                                       */
} WWDT_TypeDef;


/**
  * @}
  */


/** @addtogroup Peripheral_memory_map
  * @{
  */

#define XMC_SDRAM_MEM_BASE               ((uint32_t)0xC0000000)
#define QSPI2_MEM_BASE                   ((uint32_t)0xB0000000)
#define XMC_CARD_MEM_BASE                ((uint32_t)0xA8000000)
#define QSPI2_REG_BASE                   ((uint32_t)0xA0002000)
#define QSPI1_REG_BASE                   ((uint32_t)0xA0001000)
#define XMC_REG_BASE                     ((uint32_t)0xA0000000)
#define XMC_BANK1_REG_BASE               (XMC_REG_BASE + 0x0000)
#define XMC_BANK2_REG_BASE               (XMC_REG_BASE + 0x0060)
#define XMC_BANK3_REG_BASE               (XMC_REG_BASE + 0x0080)
#define XMC_BANK4_REG_BASE               (XMC_REG_BASE + 0x00A0)
#define XMC_SDRAM_REG_BASE               (XMC_REG_BASE + 0x0140)
#define QSPI1_MEM_BASE                   ((uint32_t)0x90000000)
#define XMC_MEM_BASE                     ((uint32_t)0x60000000)
#define PERIPH_BASE                      ((uint32_t)0x40000000)
#define SRAM_BB_BASE                     ((uint32_t)0x22000000)
#define PERIPH_BB_BASE                   ((uint32_t)0x42000000)
#define SRAM_BASE                        ((uint32_t)0x20000000)
#define USD_BASE                         ((uint32_t)0x1FFFC000)
#define FLASH_BASE                       ((uint32_t)0x08000000)
#define DEBUG_BASE                       ((uint32_t)0xE0042000)
#define APB1PERIPH_BASE                  (PERIPH_BASE)
#define APB2PERIPH_BASE                  (PERIPH_BASE + 0x10000)
#define AHBPERIPH1_BASE                  (PERIPH_BASE + 0x20000)
#define AHBPERIPH2_BASE                  (PERIPH_BASE + 0x10000000)

/* apb1 bus base address */
#define UART8_BASE                       (APB1PERIPH_BASE + 0x7C00)
#define UART7_BASE                       (APB1PERIPH_BASE + 0x7800)
#define DAC_BASE                         (APB1PERIPH_BASE + 0x7400)
#define PWC_BASE                         (APB1PERIPH_BASE + 0x7000)
#define CAN2_BASE                        (APB1PERIPH_BASE + 0x6800)
#define CAN1_BASE                        (APB1PERIPH_BASE + 0x6400)
#define I2C3_BASE                        (APB1PERIPH_BASE + 0x5C00)
#define I2C2_BASE                        (APB1PERIPH_BASE + 0x5800)
#define I2C1_BASE                        (APB1PERIPH_BASE + 0x5400)
#define UART5_BASE                       (APB1PERIPH_BASE + 0x5000)
#define UART4_BASE                       (APB1PERIPH_BASE + 0x4C00)
#define USART3_BASE                      (APB1PERIPH_BASE + 0x4800)
#define USART2_BASE                      (APB1PERIPH_BASE + 0x4400)
#define SPI3_BASE                        (APB1PERIPH_BASE + 0x3C00)
#define SPI2_BASE                        (APB1PERIPH_BASE + 0x3800)
#define WDT_BASE                         (APB1PERIPH_BASE + 0x3000)
#define WWDT_BASE                        (APB1PERIPH_BASE + 0x2C00)
#define ERTC_BASE                        (APB1PERIPH_BASE + 0x2800)
#define TMR14_BASE                       (APB1PERIPH_BASE + 0x2000)
#define TMR13_BASE                       (APB1PERIPH_BASE + 0x1C00)
#define TMR12_BASE                       (APB1PERIPH_BASE + 0x1800)
#define TMR7_BASE                        (APB1PERIPH_BASE + 0x1400)
#define TMR6_BASE                        (APB1PERIPH_BASE + 0x1000)
#define TMR5_BASE                        (APB1PERIPH_BASE + 0x0C00)
#define TMR4_BASE                        (APB1PERIPH_BASE + 0x0800)
#define TMR3_BASE                        (APB1PERIPH_BASE + 0x0400)
#define TMR2_BASE                        (APB1PERIPH_BASE + 0x0000)
/* apb2 bus base address */
#define I2S2EXT_BASE                     (APB2PERIPH_BASE + 0x7800)
#define I2S3EXT_BASE                     (APB2PERIPH_BASE + 0x7C00)
#define ACC_BASE                         (APB2PERIPH_BASE + 0x7400)
#define TMR20_BASE                       (APB2PERIPH_BASE + 0x4C00)
#define TMR11_BASE                       (APB2PERIPH_BASE + 0x4800)
#define TMR10_BASE                       (APB2PERIPH_BASE + 0x4400)
#define TMR9_BASE                        (APB2PERIPH_BASE + 0x4000)
#define EXINT_BASE                       (APB2PERIPH_BASE + 0x3C00)
#define SCFG_BASE                        (APB2PERIPH_BASE + 0x3800)
#define SPI4_BASE                        (APB2PERIPH_BASE + 0x3400)
#define SPI1_BASE                        (APB2PERIPH_BASE + 0x3000)
#define ADC1_BASE                        (APB2PERIPH_BASE + 0x2000)
#define ADC2_BASE                        (APB2PERIPH_BASE + 0x2100)
#define ADC3_BASE                        (APB2PERIPH_BASE + 0x2200)
#define ADCCOM_BASE                      (APB2PERIPH_BASE + 0x2300)
#define USART6_BASE                      (APB2PERIPH_BASE + 0x1400)
#define USART1_BASE                      (APB2PERIPH_BASE + 0x1000)
#define TMR8_BASE                        (APB2PERIPH_BASE + 0x0400)
#define TMR1_BASE                        (APB2PERIPH_BASE + 0x0000)
/* ahb bus base address */
#define OTGFS2_BASE                      (AHBPERIPH1_BASE + 0x20000)
#define SDIO1_BASE                       (AHBPERIPH1_BASE + 0xC400)
#define EMAC_BASE                        (AHBPERIPH1_BASE + 0x8000)
#define GPIOH_BASE                       (AHBPERIPH1_BASE + 0x1C00)
#define GPIOG_BASE                       (AHBPERIPH1_BASE + 0x1800)
#define GPIOF_BASE                       (AHBPERIPH1_BASE + 0x1400)
#define GPIOE_BASE                       (AHBPERIPH1_BASE + 0x1000)
#define GPIOD_BASE                       (AHBPERIPH1_BASE + 0x0C00)
#define GPIOC_BASE                       (AHBPERIPH1_BASE + 0x0800)
#define GPIOB_BASE                       (AHBPERIPH1_BASE + 0x0400)
#define GPIOA_BASE                       (AHBPERIPH1_BASE + 0x0000)

#define DMA1_BASE                        (AHBPERIPH1_BASE + 0x6400)
#define DMA1_CHANNEL1_BASE               (DMA1_BASE + 0x0008)
#define DMA1_CHANNEL2_BASE               (DMA1_BASE + 0x001C)
#define DMA1_CHANNEL3_BASE               (DMA1_BASE + 0x0030)
#define DMA1_CHANNEL4_BASE               (DMA1_BASE + 0x0044)
#define DMA1_CHANNEL5_BASE               (DMA1_BASE + 0x0058)
#define DMA1_CHANNEL6_BASE               (DMA1_BASE + 0x006C)
#define DMA1_CHANNEL7_BASE               (DMA1_BASE + 0x0080)

#define DMA1MUX_BASE                     (DMA1_BASE + 0x0104)
#define DMA1MUX_CHANNEL1_BASE            (DMA1MUX_BASE)
#define DMA1MUX_CHANNEL2_BASE            (DMA1MUX_BASE + 0x0004)
#define DMA1MUX_CHANNEL3_BASE            (DMA1MUX_BASE + 0x0008)
#define DMA1MUX_CHANNEL4_BASE            (DMA1MUX_BASE + 0x000C)
#define DMA1MUX_CHANNEL5_BASE            (DMA1MUX_BASE + 0x0010)
#define DMA1MUX_CHANNEL6_BASE            (DMA1MUX_BASE + 0x0014)
#define DMA1MUX_CHANNEL7_BASE            (DMA1MUX_BASE + 0x0018)

#define DMA1MUX_GENERATOR1_BASE          (DMA1_BASE + 0x0120)
#define DMA1MUX_GENERATOR2_BASE          (DMA1_BASE + 0x0124)
#define DMA1MUX_GENERATOR3_BASE          (DMA1_BASE + 0x0128)
#define DMA1MUX_GENERATOR4_BASE          (DMA1_BASE + 0x012C)

#define DMA2_BASE                        (AHBPERIPH1_BASE + 0x6600)
#define DMA2_CHANNEL1_BASE               (DMA2_BASE + 0x0008)
#define DMA2_CHANNEL2_BASE               (DMA2_BASE + 0x001C)
#define DMA2_CHANNEL3_BASE               (DMA2_BASE + 0x0030)
#define DMA2_CHANNEL4_BASE               (DMA2_BASE + 0x0044)
#define DMA2_CHANNEL5_BASE               (DMA2_BASE + 0x0058)
#define DMA2_CHANNEL6_BASE               (DMA2_BASE + 0x006C)
#define DMA2_CHANNEL7_BASE               (DMA2_BASE + 0x0080)

#define DMA2MUX_BASE                     (DMA2_BASE + 0x0104)
#define DMA2MUX_CHANNEL1_BASE            (DMA2MUX_BASE)
#define DMA2MUX_CHANNEL2_BASE            (DMA2MUX_BASE + 0x0004)
#define DMA2MUX_CHANNEL3_BASE            (DMA2MUX_BASE + 0x0008)
#define DMA2MUX_CHANNEL4_BASE            (DMA2MUX_BASE + 0x000C)
#define DMA2MUX_CHANNEL5_BASE            (DMA2MUX_BASE + 0x0010)
#define DMA2MUX_CHANNEL6_BASE            (DMA2MUX_BASE + 0x0014)
#define DMA2MUX_CHANNEL7_BASE            (DMA2MUX_BASE + 0x0018)

#define DMA2MUX_GENERATOR1_BASE          (DMA2_BASE + 0x0120)
#define DMA2MUX_GENERATOR2_BASE          (DMA2_BASE + 0x0124)
#define DMA2MUX_GENERATOR3_BASE          (DMA2_BASE + 0x0128)
#define DMA2MUX_GENERATOR4_BASE          (DMA2_BASE + 0x012C)

#define EDMA_BASE                        (AHBPERIPH1_BASE + 0x6000)
#define EDMA_STREAM1_BASE                (EDMA_BASE + 0x0010)
#define EDMA_STREAM2_BASE                (EDMA_BASE + 0x0028)
#define EDMA_STREAM3_BASE                (EDMA_BASE + 0x0040)
#define EDMA_STREAM4_BASE                (EDMA_BASE + 0x0058)
#define EDMA_STREAM5_BASE                (EDMA_BASE + 0x0070)
#define EDMA_STREAM6_BASE                (EDMA_BASE + 0x0088)
#define EDMA_STREAM7_BASE                (EDMA_BASE + 0x00A0)
#define EDMA_STREAM8_BASE                (EDMA_BASE + 0x00B8)

#define EDMA_2D_BASE                     (EDMA_BASE + 0x00F4)
#define EDMA_STREAM1_2D_BASE             (EDMA_2D_BASE + 0x0004)
#define EDMA_STREAM2_2D_BASE             (EDMA_2D_BASE + 0x000C)
#define EDMA_STREAM3_2D_BASE             (EDMA_2D_BASE + 0x0014)
#define EDMA_STREAM4_2D_BASE             (EDMA_2D_BASE + 0x001C)
#define EDMA_STREAM5_2D_BASE             (EDMA_2D_BASE + 0x0024)
#define EDMA_STREAM6_2D_BASE             (EDMA_2D_BASE + 0x002C)
#define EDMA_STREAM7_2D_BASE             (EDMA_2D_BASE + 0x0034)
#define EDMA_STREAM8_2D_BASE             (EDMA_2D_BASE + 0x003C)

#define EDMA_LL_BASE                     (EDMA_BASE + 0x00D0)
#define EDMA_STREAM1_LL_BASE             (EDMA_LL_BASE + 0x0004)
#define EDMA_STREAM2_LL_BASE             (EDMA_LL_BASE + 0x0008)
#define EDMA_STREAM3_LL_BASE             (EDMA_LL_BASE + 0x000C)
#define EDMA_STREAM4_LL_BASE             (EDMA_LL_BASE + 0x0010)
#define EDMA_STREAM5_LL_BASE             (EDMA_LL_BASE + 0x0014)
#define EDMA_STREAM6_LL_BASE             (EDMA_LL_BASE + 0x0018)
#define EDMA_STREAM7_LL_BASE             (EDMA_LL_BASE + 0x001C)
#define EDMA_STREAM8_LL_BASE             (EDMA_LL_BASE + 0x0020)

#define EDMAMUX_BASE                     (EDMA_BASE + 0x0140)
#define EDMAMUX_CHANNEL1_BASE            (EDMAMUX_BASE)
#define EDMAMUX_CHANNEL2_BASE            (EDMAMUX_BASE + 0x0004)
#define EDMAMUX_CHANNEL3_BASE            (EDMAMUX_BASE + 0x0008)
#define EDMAMUX_CHANNEL4_BASE            (EDMAMUX_BASE + 0x000C)
#define EDMAMUX_CHANNEL5_BASE            (EDMAMUX_BASE + 0x0010)
#define EDMAMUX_CHANNEL6_BASE            (EDMAMUX_BASE + 0x0014)
#define EDMAMUX_CHANNEL7_BASE            (EDMAMUX_BASE + 0x0018)
#define EDMAMUX_CHANNEL8_BASE            (EDMAMUX_BASE + 0x001C)

#define EDMAMUX_GENERATOR1_BASE          (EDMA_BASE + 0x0160)
#define EDMAMUX_GENERATOR2_BASE          (EDMA_BASE + 0x0164)
#define EDMAMUX_GENERATOR3_BASE          (EDMA_BASE + 0x0168)
#define EDMAMUX_GENERATOR4_BASE          (EDMA_BASE + 0x016C)

#define FLASH_REG_BASE                   (AHBPERIPH1_BASE + 0x3C00)
#define CRM_BASE                         (AHBPERIPH1_BASE + 0x3800)
#define CRC_BASE                         (AHBPERIPH1_BASE + 0x3000)
#define SDIO2_BASE                       (AHBPERIPH2_BASE + 0x61000)
#define DVP_BASE                         (AHBPERIPH2_BASE + 0x50000)
#define OTGFS1_BASE                      (AHBPERIPH2_BASE + 0x00000)

/* EMAC (F437 only) */
#define EMAC_MAC_BASE                    (EMAC_BASE)
#define EMAC_MMC_BASE                    (EMAC_BASE + 0x0100)
#define EMAC_PTP_BASE                    (EMAC_BASE + 0x0700)
#define EMAC_DMA_BASE                    (EMAC_BASE + 0x1000)

/**
  * @}
  */


/** @addtogroup Peripheral_instance
  * @{
  */

#define EXINT                             ((EXINT_TypeDef *) EXINT_BASE)
#define CRM                               ((CRM_TypeDef *) CRM_BASE)
#define PWC                               ((PWC_TypeDef *) PWC_BASE)
#define FLASH                             ((FLASH_TypeDef *) FLASH_REG_BASE)
#define GPIOA                             ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB                             ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC                             ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD                             ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE                             ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF                             ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG                             ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH                             ((GPIO_TypeDef *) GPIOH_BASE)
#define SCFG                              ((SCFG_TypeDef *) SCFG_BASE)
#define TMR1                              ((TMR_TypeDef *) TMR1_BASE)
#define TMR2                              ((TMR_TypeDef *) TMR2_BASE)
#define TMR3                              ((TMR_TypeDef *) TMR3_BASE)
#define TMR4                              ((TMR_TypeDef *) TMR4_BASE)
#define TMR5                              ((TMR_TypeDef *) TMR5_BASE)
#define TMR6                              ((TMR_TypeDef *) TMR6_BASE)
#define TMR7                              ((TMR_TypeDef *) TMR7_BASE)
#define TMR8                              ((TMR_TypeDef *) TMR8_BASE)
#define TMR9                              ((TMR_TypeDef *) TMR9_BASE)
#define TMR10                             ((TMR_TypeDef *) TMR10_BASE)
#define TMR11                             ((TMR_TypeDef *) TMR11_BASE)
#define TMR12                             ((TMR_TypeDef *) TMR12_BASE)
#define TMR13                             ((TMR_TypeDef *) TMR13_BASE)
#define TMR14                             ((TMR_TypeDef *) TMR14_BASE)
#define TMR20                             ((TMR_TypeDef *) TMR20_BASE)
#define DEBUGMCU                          ((DEBUG_TypeDef *) DEBUG_BASE)
#define DEBUG                             ((DEBUG_TypeDef *) DEBUG_BASE)
#define DMA1                              ((DMA_TypeDef *) DMA1_BASE)
#define DMA2                              ((DMA_TypeDef *) DMA2_BASE)
#define DMA1_Channel1                     ((DMA_Channel_TypeDef *) DMA1_CHANNEL1_BASE)
#define DMA1_Channel2                     ((DMA_Channel_TypeDef *) DMA1_CHANNEL2_BASE)
#define DMA1_Channel3                     ((DMA_Channel_TypeDef *) DMA1_CHANNEL3_BASE)
#define DMA1_Channel4                     ((DMA_Channel_TypeDef *) DMA1_CHANNEL4_BASE)
#define DMA1_Channel5                     ((DMA_Channel_TypeDef *) DMA1_CHANNEL5_BASE)
#define DMA1_Channel6                     ((DMA_Channel_TypeDef *) DMA1_CHANNEL6_BASE)
#define DMA1_Channel7                     ((DMA_Channel_TypeDef *) DMA1_CHANNEL7_BASE)
#define DMA2_Channel1                     ((DMA_Channel_TypeDef *) DMA2_CHANNEL1_BASE)
#define DMA2_Channel2                     ((DMA_Channel_TypeDef *) DMA2_CHANNEL2_BASE)
#define DMA2_Channel3                     ((DMA_Channel_TypeDef *) DMA2_CHANNEL3_BASE)
#define DMA2_Channel4                     ((DMA_Channel_TypeDef *) DMA2_CHANNEL4_BASE)
#define DMA2_Channel5                     ((DMA_Channel_TypeDef *) DMA2_CHANNEL5_BASE)
#define DMA2_Channel6                     ((DMA_Channel_TypeDef *) DMA2_CHANNEL6_BASE)
#define DMA2_Channel7                     ((DMA_Channel_TypeDef *) DMA2_CHANNEL7_BASE)
#define DMA1MUX_CHANNEL1                  ((DMAMUX_Channel_TypeDef *) DMA1MUX_CHANNEL1_BASE)
#define DMA1MUX_CHANNEL2                  ((DMAMUX_Channel_TypeDef *) DMA1MUX_CHANNEL2_BASE)
#define DMA1MUX_CHANNEL3                  ((DMAMUX_Channel_TypeDef *) DMA1MUX_CHANNEL3_BASE)
#define DMA1MUX_CHANNEL4                  ((DMAMUX_Channel_TypeDef *) DMA1MUX_CHANNEL4_BASE)
#define DMA1MUX_CHANNEL5                  ((DMAMUX_Channel_TypeDef *) DMA1MUX_CHANNEL5_BASE)
#define DMA1MUX_CHANNEL6                  ((DMAMUX_Channel_TypeDef *) DMA1MUX_CHANNEL6_BASE)
#define DMA1MUX_CHANNEL7                  ((DMAMUX_Channel_TypeDef *) DMA1MUX_CHANNEL7_BASE)
#define DMA2MUX_CHANNEL1                  ((DMAMUX_Channel_TypeDef *) DMA2MUX_CHANNEL1_BASE)
#define DMA2MUX_CHANNEL2                  ((DMAMUX_Channel_TypeDef *) DMA2MUX_CHANNEL2_BASE)
#define DMA2MUX_CHANNEL3                  ((DMAMUX_Channel_TypeDef *) DMA2MUX_CHANNEL3_BASE)
#define DMA2MUX_CHANNEL4                  ((DMAMUX_Channel_TypeDef *) DMA2MUX_CHANNEL4_BASE)
#define DMA2MUX_CHANNEL5                  ((DMAMUX_Channel_TypeDef *) DMA2MUX_CHANNEL5_BASE)
#define DMA2MUX_CHANNEL6                  ((DMAMUX_Channel_TypeDef *) DMA2MUX_CHANNEL6_BASE)
#define DMA2MUX_CHANNEL7                  ((DMAMUX_Channel_TypeDef *) DMA2MUX_CHANNEL7_BASE)
#define DMA1MUX_GENERATOR1                ((DMAMUX_Generator_TypeDef *) DMA1MUX_GENERATOR1_BASE)
#define DMA1MUX_GENERATOR2                ((DMAMUX_Generator_TypeDef *) DMA1MUX_GENERATOR2_BASE)
#define DMA1MUX_GENERATOR3                ((DMAMUX_Generator_TypeDef *) DMA1MUX_GENERATOR3_BASE)
#define DMA1MUX_GENERATOR4                ((DMAMUX_Generator_TypeDef *) DMA1MUX_GENERATOR4_BASE)
#define DMA2MUX_GENERATOR1                ((DMAMUX_Generator_TypeDef *) DMA2MUX_GENERATOR1_BASE)
#define DMA2MUX_GENERATOR2                ((DMAMUX_Generator_TypeDef *) DMA2MUX_GENERATOR2_BASE)
#define DMA2MUX_GENERATOR3                ((DMAMUX_Generator_TypeDef *) DMA2MUX_GENERATOR3_BASE)
#define DMA2MUX_GENERATOR4                ((DMAMUX_Generator_TypeDef *) DMA2MUX_GENERATOR4_BASE)
#define EDMA1                             ((EDMA_TypeDef *) EDMA_BASE)
#define EDMA1_STREAM1                     ((EDMA_Stream_TypeDef *) EDMA_STREAM1_BASE)
#define EDMA1_STREAM2                     ((EDMA_Stream_TypeDef *) EDMA_STREAM2_BASE)
#define EDMA1_STREAM3                     ((EDMA_Stream_TypeDef *) EDMA_STREAM3_BASE)
#define EDMA1_STREAM4                     ((EDMA_Stream_TypeDef *) EDMA_STREAM4_BASE)
#define EDMA1_STREAM5                     ((EDMA_Stream_TypeDef *) EDMA_STREAM5_BASE)
#define EDMA1_STREAM6                     ((EDMA_Stream_TypeDef *) EDMA_STREAM6_BASE)
#define EDMA1_STREAM7                     ((EDMA_Stream_TypeDef *) EDMA_STREAM7_BASE)
#define EDMA1_STREAM8                     ((EDMA_Stream_TypeDef *) EDMA_STREAM8_BASE)
#define EDMA1_STREAM1_2D                  ((EDMA_Stream_2D_TypeDef *) EDMA_STREAM1_2D_BASE)
#define EDMA1_STREAM2_2D                  ((EDMA_Stream_2D_TypeDef *) EDMA_STREAM2_2D_BASE)
#define EDMA1_STREAM3_2D                  ((EDMA_Stream_2D_TypeDef *) EDMA_STREAM3_2D_BASE)
#define EDMA1_STREAM4_2D                  ((EDMA_Stream_2D_TypeDef *) EDMA_STREAM4_2D_BASE)
#define EDMA1_STREAM5_2D                  ((EDMA_Stream_2D_TypeDef *) EDMA_STREAM5_2D_BASE)
#define EDMA1_STREAM6_2D                  ((EDMA_Stream_2D_TypeDef *) EDMA_STREAM6_2D_BASE)
#define EDMA1_STREAM7_2D                  ((EDMA_Stream_2D_TypeDef *) EDMA_STREAM7_2D_BASE)
#define EDMA1_STREAM8_2D                  ((EDMA_Stream_2D_TypeDef *) EDMA_STREAM8_2D_BASE)
#define EDMA1_STREAM1_LL                  ((EDMA_Stream_Link_List_TypeDef *) EDMA_STREAM1_LL_BASE)
#define EDMA1_STREAM2_LL                  ((EDMA_Stream_Link_List_TypeDef *) EDMA_STREAM2_LL_BASE)
#define EDMA1_STREAM3_LL                  ((EDMA_Stream_Link_List_TypeDef *) EDMA_STREAM3_LL_BASE)
#define EDMA1_STREAM4_LL                  ((EDMA_Stream_Link_List_TypeDef *) EDMA_STREAM4_LL_BASE)
#define EDMA1_STREAM5_LL                  ((EDMA_Stream_Link_List_TypeDef *) EDMA_STREAM5_LL_BASE)
#define EDMA1_STREAM6_LL                  ((EDMA_Stream_Link_List_TypeDef *) EDMA_STREAM6_LL_BASE)
#define EDMA1_STREAM7_LL                  ((EDMA_Stream_Link_List_TypeDef *) EDMA_STREAM7_LL_BASE)
#define EDMA1_STREAM8_LL                  ((EDMA_Stream_Link_List_TypeDef *) EDMA_STREAM8_LL_BASE)
#define EDMA1MUX_CHANNEL1                 ((EDMAMUX_Channel_TypeDef *) EDMAMUX_CHANNEL1_BASE)
#define EDMA1MUX_CHANNEL2                 ((EDMAMUX_Channel_TypeDef *) EDMAMUX_CHANNEL2_BASE)
#define EDMA1MUX_CHANNEL3                 ((EDMAMUX_Channel_TypeDef *) EDMAMUX_CHANNEL3_BASE)
#define EDMA1MUX_CHANNEL4                 ((EDMAMUX_Channel_TypeDef *) EDMAMUX_CHANNEL4_BASE)
#define EDMA1MUX_CHANNEL5                 ((EDMAMUX_Channel_TypeDef *) EDMAMUX_CHANNEL5_BASE)
#define EDMA1MUX_CHANNEL6                 ((EDMAMUX_Channel_TypeDef *) EDMAMUX_CHANNEL6_BASE)
#define EDMA1MUX_CHANNEL7                 ((EDMAMUX_Channel_TypeDef *) EDMAMUX_CHANNEL7_BASE)
#define EDMA1MUX_CHANNEL8                 ((EDMAMUX_Channel_TypeDef *) EDMAMUX_CHANNEL8_BASE)
#define EDMA1MUX_GENERATOR1               ((EDMAMUX_Generator_TypeDef *) EDMAMUX_GENERATOR1_BASE)
#define EDMA1MUX_GENERATOR2               ((EDMAMUX_Generator_TypeDef *) EDMAMUX_GENERATOR2_BASE)
#define EDMA1MUX_GENERATOR3               ((EDMAMUX_Generator_TypeDef *) EDMAMUX_GENERATOR3_BASE)
#define EDMA1MUX_GENERATOR4               ((EDMAMUX_Generator_TypeDef *) EDMAMUX_GENERATOR4_BASE)
#define ERTC                              ((ERTC_TypeDef *) ERTC_BASE)
#define ADC1                              ((ADC_TypeDef *) ADC1_BASE)
#define ADC2                              ((ADC_TypeDef *) ADC2_BASE)
#define ADC3                              ((ADC_TypeDef *) ADC3_BASE)
#define ADC_COMMON                        ((ADC_Common_TypeDef *) ADCCOM_BASE)
#define I2C1                              ((I2C_TypeDef *) I2C1_BASE)
#define I2C2                              ((I2C_TypeDef *) I2C2_BASE)
#define I2C3                              ((I2C_TypeDef *) I2C3_BASE)
#define USART1                            ((USART_TypeDef *) USART1_BASE)
#define USART2                            ((USART_TypeDef *) USART2_BASE)
#define USART3                            ((USART_TypeDef *) USART3_BASE)
#define UART4                             ((USART_TypeDef *) UART4_BASE)
#define UART5                             ((USART_TypeDef *) UART5_BASE)
#define USART6                            ((USART_TypeDef *) USART6_BASE)
#define UART7                             ((USART_TypeDef *) UART7_BASE)
#define UART8                             ((USART_TypeDef *) UART8_BASE)
#define SPI1                              ((SPI_TypeDef *) SPI1_BASE)
#define SPI2                              ((SPI_TypeDef *) SPI2_BASE)
#define SPI3                              ((SPI_TypeDef *) SPI3_BASE)
#define SPI4                              ((SPI_TypeDef *) SPI4_BASE)
#define I2S2EXT                           ((SPI_TypeDef *) I2S2EXT_BASE)
#define I2S3EXT                           ((SPI_TypeDef *) I2S3EXT_BASE)
#define SDIO1                             ((SDIO_TypeDef *) SDIO1_BASE)
#define SDIO2                             ((SDIO_TypeDef *) SDIO2_BASE)
#define SDIO                              ((SDIO_TypeDef *) SDIO1_BASE)
#define CRC                               ((CRC_TypeDef *)CRC_BASE)
/**
  * @}
  */
 
/** @addtogroup Bit_definition
  * @{
  */

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

/*!< POLY_SIZE configuration */
#define CRC_CTRL_POLY_SIZE_Pos              (3U)
#define CRC_CTRL_POLY_SIZE_Msk              (0x3U << CRC_CTRL_POLY_SIZE_Pos)        /*!< 0x00000018 */
#define CRC_CTRL_POLY_SIZE                  CRC_CTRL_POLY_SIZE_Msk                  /*!< POLY_SIZE[1:0] bits (Polynomial size) */
#define CRC_CTRL_POLY_SIZE_0                (0x1U << CRC_CTRL_POLY_SIZE_Pos)        /*!< 0x00000008 */
#define CRC_CTRL_POLY_SIZE_1                (0x2U << CRC_CTRL_POLY_SIZE_Pos)        /*!< 0x00000010 */

#define CRC_CTRL_POLY_SIZE_32BIT            0x00000000U                             /*!< 32-bit */
#define CRC_CTRL_POLY_SIZE_16BIT_Pos        (3U)
#define CRC_CTRL_POLY_SIZE_16BIT_Msk        (0x1U << CRC_CTRL_POLY_SIZE_16BIT_Pos)  /*!< 0x00000008 */
#define CRC_CTRL_POLY_SIZE_16BIT            CRC_CTRL_POLY_SIZE_16BIT_Msk            /*!< 16-bit */
#define CRC_CTRL_POLY_SIZE_8BIT_Pos         (4U)
#define CRC_CTRL_POLY_SIZE_8BIT_Msk         (0x1U << CRC_CTRL_POLY_SIZE_8BIT_Pos)   /*!< 0x00000010 */
#define CRC_CTRL_POLY_SIZE_8BIT             CRC_CTRL_POLY_SIZE_8BIT_Msk             /*!< 8-bit */
#define CRC_CTRL_POLY_SIZE_7BIT_Pos         (3U)
#define CRC_CTRL_POLY_SIZE_7BIT_Msk         (0x3U << CRC_CTRL_POLY_SIZE_7BIT_Pos)   /*!< 0x00000018 */
#define CRC_CTRL_POLY_SIZE_7BIT             CRC_CTRL_POLY_SIZE_7BIT_Msk             /*!< 7-bit */

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

/*******************  Bit definition for CRC_POLY register  *******************/
#define CRC_POLY_POLY_Pos                   (0U)
#define CRC_POLY_POLY_Msk                   (0xFFFFFFFFU << CRC_POLY_POLY_Pos)      /*!< 0xFFFFFFFF */
#define CRC_POLY_POLY                       CRC_POLY_POLY_Msk                       /*!< Polynomial coefficient */

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

/******************  Bit definition for CRM_PLLCFG register  ******************/
/*!< PLL_MS congiguration */
#define CRM_PLLCFG_PLL_MS_Pos               (0U)
#define CRM_PLLCFG_PLL_MS_Msk               (0xFU << CRM_PLLCFG_PLL_MS_Pos)         /*!< 0x0000000F */
#define CRM_PLLCFG_PLL_MS                   CRM_PLLCFG_PLL_MS_Msk                   /*!< PLL_MS[3:0] bits (PLL pre-division) */
#define CRM_PLLCFG_PLL_MS_0                 (0x1U << CRM_PLLCFG_PLL_MS_Pos)         /*!< 0x00000001 */
#define CRM_PLLCFG_PLL_MS_1                 (0x2U << CRM_PLLCFG_PLL_MS_Pos)         /*!< 0x00000002 */
#define CRM_PLLCFG_PLL_MS_2                 (0x4U << CRM_PLLCFG_PLL_MS_Pos)         /*!< 0x00000004 */
#define CRM_PLLCFG_PLL_MS_3                 (0x8U << CRM_PLLCFG_PLL_MS_Pos)         /*!< 0x00000008 */

/*!< PLL_NS congiguration */
#define CRM_PLLCFG_PLL_NS_Pos               (6U)
#define CRM_PLLCFG_PLL_NS_Msk               (0x1FFU << CRM_PLLCFG_PLL_NS_Pos)       /*!< 0x00007FC0 */
#define CRM_PLLCFG_PLL_NS                   CRM_PLLCFG_PLL_NS_Msk                   /*!< PLL_NS[8:0] bits (PLL multiplication factor) */
#define CRM_PLLCFG_PLL_NS_0                 (0x001U << CRM_PLLCFG_PLL_NS_Pos)       /*!< 0x00000040 */
#define CRM_PLLCFG_PLL_NS_1                 (0x002U << CRM_PLLCFG_PLL_NS_Pos)       /*!< 0x00000080 */
#define CRM_PLLCFG_PLL_NS_2                 (0x004U << CRM_PLLCFG_PLL_NS_Pos)       /*!< 0x00000100 */
#define CRM_PLLCFG_PLL_NS_3                 (0x008U << CRM_PLLCFG_PLL_NS_Pos)       /*!< 0x00000200 */
#define CRM_PLLCFG_PLL_NS_4                 (0x010U << CRM_PLLCFG_PLL_NS_Pos)       /*!< 0x00000400 */
#define CRM_PLLCFG_PLL_NS_5                 (0x020U << CRM_PLLCFG_PLL_NS_Pos)       /*!< 0x00000800 */
#define CRM_PLLCFG_PLL_NS_6                 (0x040U << CRM_PLLCFG_PLL_NS_Pos)       /*!< 0x00001000 */
#define CRM_PLLCFG_PLL_NS_7                 (0x080U << CRM_PLLCFG_PLL_NS_Pos)       /*!< 0x00002000 */
#define CRM_PLLCFG_PLL_NS_8                 (0x100U << CRM_PLLCFG_PLL_NS_Pos)       /*!< 0x00004000 */

/*!< PLL_FR congiguration */
#define CRM_PLLCFG_PLL_FR_Pos               (16U)
#define CRM_PLLCFG_PLL_FR_Msk               (0x7U << CRM_PLLCFG_PLL_FR_Pos)         /*!< 0x00070000 */
#define CRM_PLLCFG_PLL_FR                   CRM_PLLCFG_PLL_FR_Msk                   /*!< PLL_FP[2:0] bits (PLLP post-division) */
#define CRM_PLLCFG_PLL_FR_0                 (0x1U << CRM_PLLCFG_PLL_FR_Pos)         /*!< 0x00010000 */
#define CRM_PLLCFG_PLL_FR_1                 (0x2U << CRM_PLLCFG_PLL_FR_Pos)         /*!< 0x00020000 */
#define CRM_PLLCFG_PLL_FR_2                 (0x4U << CRM_PLLCFG_PLL_FR_Pos)         /*!< 0x00040000 */
#define CRM_PLLCFG_PLL_FR_3                 (0x8U << CRM_PLLCFG_PLL_FR_Pos)         /*!< 0x00080000 */

#define CRM_PLLCFG_PLLRCS_Pos               (22U)
#define CRM_PLLCFG_PLLRCS_Msk               (0x1U << CRM_PLLCFG_PLLRCS_Pos)         /*!< 0x40000000 */
#define CRM_PLLCFG_PLLRCS                   CRM_PLLCFG_PLLRCS_Msk                   /*!< PLL reference clock select */

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
#define CRM_CFG_APB1DIV_Pos                 (10U)
#define CRM_CFG_APB1DIV_Msk                 (0x7U << CRM_CFG_APB1DIV_Pos)           /*!< 0x00001C00 */
#define CRM_CFG_APB1DIV                     CRM_CFG_APB1DIV_Msk                     /*!< APB1DIV[2:0] bits (APB1 division) */
#define CRM_CFG_APB1DIV_0                   (0x1U << CRM_CFG_APB1DIV_Pos)           /*!< 0x00000400 */
#define CRM_CFG_APB1DIV_1                   (0x2U << CRM_CFG_APB1DIV_Pos)           /*!< 0x00000800 */
#define CRM_CFG_APB1DIV_2                   (0x4U << CRM_CFG_APB1DIV_Pos)           /*!< 0x00001000 */

#define CRM_CFG_APB1DIV_DIV1                0x00000000U                             /*!< HCLK is not divided */
#define CRM_CFG_APB1DIV_DIV2                0x00001000U                             /*!< HCLK is divided by 2 */
#define CRM_CFG_APB1DIV_DIV4                0x00001400U                             /*!< HCLK is divided by 4 */
#define CRM_CFG_APB1DIV_DIV8                0x00001800U                             /*!< HCLK is divided by 8 */
#define CRM_CFG_APB1DIV_DIV16               0x00001C00U                             /*!< HCLK is divided by 16 */

/*!< APB2DIV configuration */
#define CRM_CFG_APB2DIV_Pos                 (13U)
#define CRM_CFG_APB2DIV_Msk                 (0x7U << CRM_CFG_APB2DIV_Pos)           /*!< 0x0000E000 */
#define CRM_CFG_APB2DIV                     CRM_CFG_APB2DIV_Msk                     /*!< APB2DIV[2:0] bits (APB2 division) */
#define CRM_CFG_APB2DIV_0                   (0x1U << CRM_CFG_APB2DIV_Pos)           /*!< 0x00002000 */
#define CRM_CFG_APB2DIV_1                   (0x2U << CRM_CFG_APB2DIV_Pos)           /*!< 0x00004000 */
#define CRM_CFG_APB2DIV_2                   (0x4U << CRM_CFG_APB2DIV_Pos)           /*!< 0x00008000 */

#define CRM_CFG_APB2DIV_DIV1                0x00000000U                             /*!< HCLK is not divided */
#define CRM_CFG_APB2DIV_DIV2                0x00008000U                             /*!< HCLK is divided by 2 */
#define CRM_CFG_APB2DIV_DIV4                0x0000A000U                             /*!< HCLK is divided by 4 */
#define CRM_CFG_APB2DIV_DIV8                0x0000C000U                             /*!< HCLK is divided by 8 */
#define CRM_CFG_APB2DIV_DIV16               0x0000E000U                             /*!< HCLK is divided by 16 */

/*!< ERTCDIV configuration */
#define CRM_CFG_ERTCDIV_Pos                 (16U)
#define CRM_CFG_ERTCDIV_Msk                 (0x1FU << CRM_CFG_ERTCDIV_Pos)          /*!< 0x001F0000 */
#define CRM_CFG_ERTCDIV                     CRM_CFG_ERTCDIV_Msk                     /*!< ERTCDIV[4:0] bits (HEXT division for ERTC clock) */
#define CRM_CFG_ERTCDIV_0                   (0x01U << CRM_CFG_ERTCDIV_Pos)          /*!< 0x00010000 */
#define CRM_CFG_ERTCDIV_1                   (0x02U << CRM_CFG_ERTCDIV_Pos)          /*!< 0x00020000 */
#define CRM_CFG_ERTCDIV_2                   (0x04U << CRM_CFG_ERTCDIV_Pos)          /*!< 0x00040000 */
#define CRM_CFG_ERTCDIV_3                   (0x08U << CRM_CFG_ERTCDIV_Pos)          /*!< 0x00080000 */
#define CRM_CFG_ERTCDIV_4                   (0x10U << CRM_CFG_ERTCDIV_Pos)          /*!< 0x00100000 */

#define CRM_CFG_ERTCDIV_DIV2                0x00020000U                             /*!< HEXT/2 */
#define CRM_CFG_ERTCDIV_DIV3                0x00030000U                             /*!< HEXT/3 */
#define CRM_CFG_ERTCDIV_DIV4                0x00040000U                             /*!< HEXT/4 */
#define CRM_CFG_ERTCDIV_DIV5                0x00050000U                             /*!< HEXT/5 */
#define CRM_CFG_ERTCDIV_DIV6                0x00060000U                             /*!< HEXT/6 */
#define CRM_CFG_ERTCDIV_DIV7                0x00070000U                             /*!< HEXT/7 */
#define CRM_CFG_ERTCDIV_DIV8                0x00080000U                             /*!< HEXT/8 */
#define CRM_CFG_ERTCDIV_DIV9                0x00090000U                             /*!< HEXT/9 */
#define CRM_CFG_ERTCDIV_DIV10               0x000A0000U                             /*!< HEXT/10 */
#define CRM_CFG_ERTCDIV_DIV11               0x000B0000U                             /*!< HEXT/11 */
#define CRM_CFG_ERTCDIV_DIV12               0x000C0000U                             /*!< HEXT/12 */
#define CRM_CFG_ERTCDIV_DIV13               0x000D0000U                             /*!< HEXT/13 */
#define CRM_CFG_ERTCDIV_DIV14               0x000E0000U                             /*!< HEXT/14 */
#define CRM_CFG_ERTCDIV_DIV15               0x000F0000U                             /*!< HEXT/15 */
#define CRM_CFG_ERTCDIV_DIV16               0x00100000U                             /*!< HEXT/16 */
#define CRM_CFG_ERTCDIV_DIV17               0x00110000U                             /*!< HEXT/17 */
#define CRM_CFG_ERTCDIV_DIV18               0x00120000U                             /*!< HEXT/18 */
#define CRM_CFG_ERTCDIV_DIV19               0x00130000U                             /*!< HEXT/19 */
#define CRM_CFG_ERTCDIV_DIV20               0x00140000U                             /*!< HEXT/20 */
#define CRM_CFG_ERTCDIV_DIV21               0x00150000U                             /*!< HEXT/21 */
#define CRM_CFG_ERTCDIV_DIV22               0x00160000U                             /*!< HEXT/22 */
#define CRM_CFG_ERTCDIV_DIV23               0x00170000U                             /*!< HEXT/23 */
#define CRM_CFG_ERTCDIV_DIV24               0x00180000U                             /*!< HEXT/24 */
#define CRM_CFG_ERTCDIV_DIV25               0x00190000U                             /*!< HEXT/25 */
#define CRM_CFG_ERTCDIV_DIV26               0x001A0000U                             /*!< HEXT/26 */
#define CRM_CFG_ERTCDIV_DIV27               0x001B0000U                             /*!< HEXT/27 */
#define CRM_CFG_ERTCDIV_DIV28               0x001C0000U                             /*!< HEXT/28 */
#define CRM_CFG_ERTCDIV_DIV29               0x001D0000U                             /*!< HEXT/29 */
#define CRM_CFG_ERTCDIV_DIV30               0x001E0000U                             /*!< HEXT/30 */
#define CRM_CFG_ERTCDIV_DIV31               0x001F0000U                             /*!< HEXT/31 */

/*!< CLKOUTDIV1 configuration */
#define CRM_CFG_CLKOUTDIV1_Pos              (27U)
#define CRM_CFG_CLKOUTDIV1_Msk              (0x7U << CRM_CFG_CLKOUTDIV1_Pos)        /*!< 0x38000000 */
#define CRM_CFG_CLKOUTDIV1                  CRM_CFG_CLKOUTDIV1_Msk                  /*!< CLKOUTDIV1[2:0] bits (Clock output division 1) */
#define CRM_CFG_CLKOUTDIV1_0                (0x1U << CRM_CFG_CLKOUTDIV1_Pos)        /*!< 0x08000000 */
#define CRM_CFG_CLKOUTDIV1_1                (0x2U << CRM_CFG_CLKOUTDIV1_Pos)        /*!< 0x10000000 */
#define CRM_CFG_CLKOUTDIV1_2                (0x4U << CRM_CFG_CLKOUTDIV1_Pos)        /*!< 0x20000000 */

#define CRM_CFG_CLKOUTDIV1_DIV1             0x00000000U                             /*!< No clock output */
#define CRM_CFG_CLKOUTDIV1_DIV2             0x20000000U                             /*!< Clock output divided by 2 */
#define CRM_CFG_CLKOUTDIV1_DIV3             0x28000000U                             /*!< Clock output divided by 3 */
#define CRM_CFG_CLKOUTDIV1_DIV4             0x30000000U                             /*!< Clock output divided by 4 */
#define CRM_CFG_CLKOUTDIV1_DIV5             0x38000000U                             /*!< Clock output divided by 5 */

/*!< CLKOUT_SEL1 configuration */
#define CRM_CFG_CLKOUT_SEL1_Pos             (30U)
#define CRM_CFG_CLKOUT_SEL1_Msk             (0x3U << CRM_CFG_CLKOUT_SEL1_Pos)       /*!< 0xC0000000 */
#define CRM_CFG_CLKOUT_SEL1                 CRM_CFG_CLKOUT_SEL1_Msk                 /*!< CLKOUT_SEL1[1:0] bits (Clock output selection 1) */
#define CRM_CFG_CLKOUT_SEL1_0               (0x1U << CRM_CFG_CLKOUT_SEL1_Pos)       /*!< 0x40000000 */
#define CRM_CFG_CLKOUT_SEL1_1               (0x2U << CRM_CFG_CLKOUT_SEL1_Pos)       /*!< 0x80000000 */

#define CRM_CFG_CLKOUT_SEL1_SCLK            0x00000000U                             /*!< System clock */
#define CRM_CFG_CLKOUT_SEL1_CLKOUT_SEL2     0x40000000U                             /*!< CLKOUT_SEL2 bit in the CRM_MISC1 register */
#define CRM_CFG_CLKOUT_SEL1_HEXT            0x80000000U                             /*!< HEXT */
#define CRM_CFG_CLKOUT_SEL1_PLL             0xC0000000U                             /*!< PLL */

/* Reference defines */
#define CRM_CFG_CLKSEL1                     CRM_CFG_CLKOUT_SEL1
#define CRM_CFG_CLKSEL1_0                   CRM_CFG_CLKOUT_SEL1_0
#define CRM_CFG_CLKSEL1_1                   CRM_CFG_CLKOUT_SEL1_1
#define CRM_CFG_CLKSEL1_SCLK                CRM_CFG_CLKOUT_SEL1_SCLK
#define CRM_CFG_CLKSEL1_CLKOUT_SEL2         CRM_CFG_CLKOUT_SEL1_CLKOUT_SEL2
#define CRM_CFG_CLKSEL1_HEXT                CRM_CFG_CLKOUT_SEL1_HEXT
#define CRM_CFG_CLKSEL1_PLL                 CRM_CFG_CLKOUT_SEL1_PLL

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
#define CRM_CLKINT_CFDF                     CRM_CLKINT_CFDF_Msk                     /*!< Clock failure detection flag */
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

/*****************  Bit definition for CRM_AHBRST1 register  ******************/
#define CRM_AHBRST1_GPIOARST_Pos            (0U)
#define CRM_AHBRST1_GPIOARST_Msk            (0x1U << CRM_AHBRST1_GPIOARST_Pos)      /*!< 0x00000001 */
#define CRM_AHBRST1_GPIOARST                CRM_AHBRST1_GPIOARST_Msk                /*!< IO port A reset */
#define CRM_AHBRST1_GPIOBRST_Pos            (1U)
#define CRM_AHBRST1_GPIOBRST_Msk            (0x1U << CRM_AHBRST1_GPIOBRST_Pos)      /*!< 0x00000002 */
#define CRM_AHBRST1_GPIOBRST                CRM_AHBRST1_GPIOBRST_Msk                /*!< IO port B reset */
#define CRM_AHBRST1_GPIOCRST_Pos            (2U)
#define CRM_AHBRST1_GPIOCRST_Msk            (0x1U << CRM_AHBRST1_GPIOCRST_Pos)      /*!< 0x00000004 */
#define CRM_AHBRST1_GPIOCRST                CRM_AHBRST1_GPIOCRST_Msk                /*!< IO port C reset */
#define CRM_AHBRST1_GPIODRST_Pos            (3U)
#define CRM_AHBRST1_GPIODRST_Msk            (0x1U << CRM_AHBRST1_GPIODRST_Pos)      /*!< 0x00000008 */
#define CRM_AHBRST1_GPIODRST                CRM_AHBRST1_GPIODRST_Msk                /*!< IO port D reset */
#define CRM_AHBRST1_GPIOERST_Pos            (4U)
#define CRM_AHBRST1_GPIOERST_Msk            (0x1U << CRM_AHBRST1_GPIOERST_Pos)      /*!< 0x00000010 */
#define CRM_AHBRST1_GPIOERST                CRM_AHBRST1_GPIOERST_Msk                /*!< IO port E reset */
#define CRM_AHBRST1_GPIOFRST_Pos            (5U)
#define CRM_AHBRST1_GPIOFRST_Msk            (0x1U << CRM_AHBRST1_GPIOFRST_Pos)      /*!< 0x00000020 */
#define CRM_AHBRST1_GPIOFRST                CRM_AHBRST1_GPIOFRST_Msk                /*!< IO port F reset */
#define CRM_AHBRST1_GPIOGRST_Pos            (6U)
#define CRM_AHBRST1_GPIOGRST_Msk            (0x1U << CRM_AHBRST1_GPIOGRST_Pos)      /*!< 0x00000040 */
#define CRM_AHBRST1_GPIOGRST                CRM_AHBRST1_GPIOGRST_Msk                /*!< IO port G reset */
#define CRM_AHBRST1_GPIOHRST_Pos            (7U)
#define CRM_AHBRST1_GPIOHRST_Msk            (0x1U << CRM_AHBRST1_GPIOHRST_Pos)      /*!< 0x00000080 */
#define CRM_AHBRST1_GPIOHRST                CRM_AHBRST1_GPIOHRST_Msk                /*!< IO port H reset */
#define CRM_AHBRST1_CRCRST_Pos              (12U)
#define CRM_AHBRST1_CRCRST_Msk              (0x1U << CRM_AHBRST1_CRCRST_Pos)        /*!< 0x00001000 */
#define CRM_AHBRST1_CRCRST                  CRM_AHBRST1_CRCRST_Msk                  /*!< CRC reset */
#define CRM_AHBRST1_EDMARST_Pos             (21U)
#define CRM_AHBRST1_EDMARST_Msk             (0x1U << CRM_AHBRST1_EDMARST_Pos)       /*!< 0x00200000 */
#define CRM_AHBRST1_EDMARST                 CRM_AHBRST1_EDMARST_Msk                 /*!< EDMA reset */
#define CRM_AHBRST1_DMA1RST_Pos             (22U)
#define CRM_AHBRST1_DMA1RST_Msk             (0x1U << CRM_AHBRST1_DMA1RST_Pos)       /*!< 0x00400000 */
#define CRM_AHBRST1_DMA1RST                 CRM_AHBRST1_DMA1RST_Msk                 /*!< DMA1 reset */
#define CRM_AHBRST1_DMA2RST_Pos             (24U)
#define CRM_AHBRST1_DMA2RST_Msk             (0x1U << CRM_AHBRST1_DMA2RST_Pos)       /*!< 0x01000000 */
#define CRM_AHBRST1_DMA2RST                 CRM_AHBRST1_DMA2RST_Msk                 /*!< DMA2 reset */
#define CRM_AHBRST1_EMACRST_Pos             (25U)
#define CRM_AHBRST1_EMACRST_Msk             (0x1U << CRM_AHBRST1_EMACRST_Pos)       /*!< 0x02000000 */
#define CRM_AHBRST1_EMACRST                 CRM_AHBRST1_EMACRST_Msk                 /*!< EMAC reset */

#define CRM_AHBRST1_OTGFS2RST_Pos           (29U)
#define CRM_AHBRST1_OTGFS2RST_Msk           (0x1U << CRM_AHBRST1_OTGFS2RST_Pos)      /*!< 0x20000000 */
#define CRM_AHBRST1_OTGFS2RST               CRM_AHBRST1_OTGFS2RST_Msk                /*!< OTGFS2 reset */

/*****************  Bit definition for CRM_AHBRST2 register  ******************/
#define CRM_AHBRST2_DVPRST_Pos              (0U)
#define CRM_AHBRST2_DVPRST_Msk              (0x1U << CRM_AHBRST2_DVPRST_Pos)        /*!< 0x00000001 */
#define CRM_AHBRST2_DVPRST                  CRM_AHBRST2_DVPRST_Msk                  /*!< DVP reset */
#define CRM_AHBRST2_OTGFSRST_Pos            (7U)
#define CRM_AHBRST2_OTGFSRST_Msk            (0x1U << CRM_AHBRST2_OTGFSRST_Pos)      /*!< 0x00000080 */
#define CRM_AHBRST2_OTGFSRST                CRM_AHBRST2_OTGFSRST_Msk                /*!< OTGFS reset */
#define CRM_AHBRST2_SDIO1RST_Pos            (15U)
#define CRM_AHBRST2_SDIO1RST_Msk            (0x1U << CRM_AHBRST2_SDIO1RST_Pos)      /*!< 0x00008000 */
#define CRM_AHBRST2_SDIO1RST                CRM_AHBRST2_SDIO1RST_Msk                /*!< SDIO1 reset */

/*****************  Bit definition for CRM_AHBRST3 register  ******************/
#define CRM_AHBRST3_XMCRST_Pos              (0U)
#define CRM_AHBRST3_XMCRST_Msk              (0x1U << CRM_AHBRST2_XMCRST_Pos)        /*!< 0x00000001 */
#define CRM_AHBRST3_XMCRST                  CRM_AHBRST2_XMCRST_Msk                  /*!< XMC reset */
#define CRM_AHBRST3_QSPI1RST_Pos            (1U)
#define CRM_AHBRST3_QSPI1RST_Msk            (0x1U << CRM_AHBRST2_QSPI1RST_Pos)        /*!< 0x00000002 */
#define CRM_AHBRST3_QSPI1RST                CRM_AHBRST2_QSPI1RST_Msk                  /*!< QSPI1 reset */
#define CRM_AHBRST3_QSPI2RST_Pos            (14U)
#define CRM_AHBRST3_QSPI2RST_Msk            (0x1U << CRM_AHBRST2_QSPI2RST_Pos)        /*!< 0x00004000 */
#define CRM_AHBRST3_QSPI2RST                CRM_AHBRST2_QSPI2RST_Msk                  /*!< QSPI2 reset */
#define CRM_AHBRST3_SDIO2RST_Pos            (15U)
#define CRM_AHBRST3_SDIO2RST_Msk            (0x1U << CRM_AHBRST3_SDIO2RST_Pos)        /*!< 0x00008000 */
#define CRM_AHBRST3_SDIO2RST                CRM_AHBRST3_SDIO2RST_Msk                  /*!< SDIO2 reset */


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
#define CRM_APB1RST_TMR6RST_Pos             (4U)
#define CRM_APB1RST_TMR6RST_Msk             (0x1U << CRM_APB1RST_TMR6RST_Pos)       /*!< 0x00000010 */
#define CRM_APB1RST_TMR6RST                 CRM_APB1RST_TMR6RST_Msk                 /*!< TMR6 reset */
#define CRM_APB1RST_TMR7RST_Pos             (5U)
#define CRM_APB1RST_TMR7RST_Msk             (0x1U << CRM_APB1RST_TMR7RST_Pos)       /*!< 0x00000020 */
#define CRM_APB1RST_TMR7RST                 CRM_APB1RST_TMR7RST_Msk                 /*!< TMR7 reset */
#define CRM_APB1RST_TMR12RST_Pos            (6U)
#define CRM_APB1RST_TMR12RST_Msk            (0x1U << CRM_APB1RST_TMR12RST_Pos)       /*!< 0x00000040 */
#define CRM_APB1RST_TMR12RST                CRM_APB1RST_TMR12RST_Msk                 /*!< TMR12 reset */
#define CRM_APB1RST_TMR13RST_Pos            (7U)
#define CRM_APB1RST_TMR13RST_Msk            (0x1U << CRM_APB1RST_TMR13RST_Pos)      /*!< 0x00000080 */
#define CRM_APB1RST_TMR13RST                CRM_APB1RST_TMR13RST_Msk                /*!< TMR13 reset */
#define CRM_APB1RST_TMR14RST_Pos            (8U)
#define CRM_APB1RST_TMR14RST_Msk            (0x1U << CRM_APB1RST_TMR14RST_Pos)      /*!< 0x00000100 */
#define CRM_APB1RST_TMR14RST                CRM_APB1RST_TMR14RST_Msk                /*!< TMR14 reset */
#define CRM_APB1RST_WWDTRST_Pos             (11U)
#define CRM_APB1RST_WWDTRST_Msk             (0x1U << CRM_APB1RST_WWDTRST_Pos)       /*!< 0x00000800 */
#define CRM_APB1RST_WWDTRST                 CRM_APB1RST_WWDTRST_Msk                 /*!< WWDT reset */
#define CRM_APB1RST_SPI2RST_Pos             (14U)
#define CRM_APB1RST_SPI2RST_Msk             (0x1U << CRM_APB1RST_SPI2RST_Pos)       /*!< 0x00004000 */
#define CRM_APB1RST_SPI2RST                 CRM_APB1RST_SPI2RST_Msk                 /*!< SPI2 reset */
#define CRM_APB1RST_SPI3RST_Pos             (15U)
#define CRM_APB1RST_SPI3RST_Msk             (0x1U << CRM_APB1RST_SPI3RST_Pos)       /*!< 0x00008000 */
#define CRM_APB1RST_SPI3RST                 CRM_APB1RST_SPI3RST_Msk                 /*!< SPI3 reset */
#define CRM_APB1RST_USART2RST_Pos           (17U)
#define CRM_APB1RST_USART2RST_Msk           (0x1U << CRM_APB1RST_USART2RST_Pos)     /*!< 0x00020000 */
#define CRM_APB1RST_USART2RST               CRM_APB1RST_USART2RST_Msk               /*!< USART2 reset */
#define CRM_APB1RST_USART3RST_Pos           (18U)
#define CRM_APB1RST_USART3RST_Msk           (0x1U << CRM_APB1RST_USART3RST_Pos)     /*!< 0x00040000 */
#define CRM_APB1RST_USART3RST               CRM_APB1RST_USART3RST_Msk               /*!< USART3 reset */
#define CRM_APB1RST_USART4RST_Pos           (19U)
#define CRM_APB1RST_USART4RST_Msk           (0x1U << CRM_APB1RST_USART4RST_Pos)     /*!< 0x00080000 */
#define CRM_APB1RST_USART4RST               CRM_APB1RST_USART4RST_Msk               /*!< USART4 reset */
#define CRM_APB1RST_USART5RST_Pos           (20U)
#define CRM_APB1RST_USART5RST_Msk           (0x1U << CRM_APB1RST_USART5RST_Pos)     /*!< 0x00100000 */
#define CRM_APB1RST_USART5RST               CRM_APB1RST_USART5RST_Msk               /*!< USART5 reset */
#define CRM_APB1RST_I2C1RST_Pos             (21U)
#define CRM_APB1RST_I2C1RST_Msk             (0x1U << CRM_APB1RST_I2C1RST_Pos)       /*!< 0x00200000 */
#define CRM_APB1RST_I2C1RST                 CRM_APB1RST_I2C1RST_Msk                 /*!< I2C1 reset */
#define CRM_APB1RST_I2C2RST_Pos             (22U)
#define CRM_APB1RST_I2C2RST_Msk             (0x1U << CRM_APB1RST_I2C2RST_Pos)       /*!< 0x00400000 */
#define CRM_APB1RST_I2C2RST                 CRM_APB1RST_I2C2RST_Msk                 /*!< I2C2 reset */
#define CRM_APB1RST_I2C3RST_Pos             (23U)
#define CRM_APB1RST_I2C3RST_Msk             (0x1U << CRM_APB1RST_I2C3RST_Pos)       /*!< 0x00800000 */
#define CRM_APB1RST_I2C3RST                 CRM_APB1RST_I2C3RST_Msk                 /*!< I2C3 reset */
#define CRM_APB1RST_CAN1RST_Pos             (25U)
#define CRM_APB1RST_CAN1RST_Msk             (0x1U << CRM_APB1RST_CAN1RST_Pos)       /*!< 0x02000000 */
#define CRM_APB1RST_CAN1RST                 CRM_APB1RST_CAN1RST_Msk                 /*!< CAN1 reset */
#define CRM_APB1RST_CAN2RST_Pos             (26U)
#define CRM_APB1RST_CAN2RST_Msk             (0x1U << CRM_APB1RST_CAN2RST_Pos)       /*!< 0x04000000 */
#define CRM_APB1RST_CAN2RST                 CRM_APB1RST_CAN2RST_Msk                 /*!< CAN2 reset */
#define CRM_APB1RST_PWCRST_Pos              (28U)
#define CRM_APB1RST_PWCRST_Msk              (0x1U << CRM_APB1RST_PWCRST_Pos)        /*!< 0x10000000 */
#define CRM_APB1RST_PWCRST                  CRM_APB1RST_PWCRST_Msk                  /*!< PWC reset */
#define CRM_APB1RST_DACRST_Pos              (29U)
#define CRM_APB1RST_DACRST_Msk              (0x1U << CRM_APB1RST_DACRST_Pos)        /*!< 0x20000000 */
#define CRM_APB1RST_DACRST                  CRM_APB1RST_DACRST_Msk                  /*!< DAC reset */
#define CRM_APB1RST_UART7RST_Pos            (30U)
#define CRM_APB1RST_UART7RST_Msk            (0x1U << CRM_APB1RST_UART7RST_Pos)      /*!< 0x40000000 */
#define CRM_APB1RST_UART7RST                CRM_APB1RST_UART7RST_Msk                /*!< UART7 reset */
#define CRM_APB1RST_UART8RST_Pos            (31U)
#define CRM_APB1RST_UART8RST_Msk            (0x1U << CRM_APB1RST_UART8RST_Pos)      /*!< 0x80000000 */
#define CRM_APB1RST_UART8RST                CRM_APB1RST_UART8RST_Msk                /*!< UART8 reset */

/*****************  Bit definition for CRM_APB2RST register  ******************/
#define CRM_APB2RST_TMR1RST_Pos             (0U)
#define CRM_APB2RST_TMR1RST_Msk             (0x1U << CRM_APB2RST_TMR1RST_Pos)       /*!< 0x00000001 */
#define CRM_APB2RST_TMR1RST                 CRM_APB2RST_TMR1RST_Msk                 /*!< TMR1 reset */
#define CRM_APB2RST_TMR8RST_Pos             (1U)
#define CRM_APB2RST_TMR8RST_Msk             (0x1U << CRM_APB2RST_TMR8RST_Pos)       /*!< 0x00000002 */
#define CRM_APB2RST_TMR8RST                 CRM_APB2RST_TMR8RST_Msk                 /*!< TMR8 reset */
#define CRM_APB2RST_USART1RST_Pos           (4U)
#define CRM_APB2RST_USART1RST_Msk           (0x1U << CRM_APB2RST_USART1RST_Pos)     /*!< 0x00000010 */
#define CRM_APB2RST_USART1RST               CRM_APB2RST_USART1RST_Msk               /*!< USART1 reset */
#define CRM_APB2RST_USART6RST_Pos           (5U)
#define CRM_APB2RST_USART6RST_Msk           (0x1U << CRM_APB2RST_USART6RST_Pos)     /*!< 0x00000020 */
#define CRM_APB2RST_USART6RST               CRM_APB2RST_USART6RST_Msk               /*!< USART6 reset */
#define CRM_APB2RST_ADCRST_Pos              (8U)
#define CRM_APB2RST_ADCRST_Msk              (0x1U << CRM_APB2RST_ADCRST_Pos)        /*!< 0x00000100 */
#define CRM_APB2RST_ADCRST                  CRM_APB2RST_ADCRST_Msk                  /*!< ADC1 reset */
#define CRM_APB2RST_ADC2RST_Pos             (9U)
#define CRM_APB2RST_ADC2RST_Msk             (0x1U << CRM_APB2RST_ADC2RST_Pos)       /*!< 0x00000200 */
#define CRM_APB2RST_ADC2RST                 CRM_APB2RST_ADC2RST_Msk                 /*!< ADC2 reset */
#define CRM_APB2RST_ADC3RST_Pos             (10U)
#define CRM_APB2RST_ADC3RST_Msk             (0x1U << CRM_APB2RST_ADC3RST_Pos)       /*!< 0x00000400 */
#define CRM_APB2RST_ADC3RST                 CRM_APB2RST_ADC3RST_Msk                 /*!< ADC3 reset */
#define CRM_APB2RST_SPI1RST_Pos             (12U)
#define CRM_APB2RST_SPI1RST_Msk             (0x1U << CRM_APB2RST_SPI1RST_Pos)       /*!< 0x00001000 */
#define CRM_APB2RST_SPI1RST                 CRM_APB2RST_SPI1RST_Msk                 /*!< SPI1 reset */
#define CRM_APB2RST_SPI4RST_Pos             (13U)
#define CRM_APB2RST_SPI4RST_Msk             (0x1U << CRM_APB2RST_SPI4RST_Pos)       /*!< 0x00002000 */
#define CRM_APB2RST_SPI4RST                 CRM_APB2RST_SPI4RST_Msk                 /*!< SPI4 reset */
#define CRM_APB2RST_SCFGRST_Pos             (14U)
#define CRM_APB2RST_SCFGRST_Msk             (0x1U << CRM_APB2RST_SCFGRST_Pos)       /*!< 0x00004000 */
#define CRM_APB2RST_SCFGRST                 CRM_APB2RST_SCFGRST_Msk                 /*!< SCFG reset */
#define CRM_APB2RST_EXINTRST_Pos            (15U)
#define CRM_APB2RST_EXINTRST_Msk            (0x1U << CRM_APB2RST_EXINTRST_Pos)      /*!< 0x00008000 */
#define CRM_APB2RST_EXINTRST                CRM_APB2RST_EXINTRST_Msk                /*!< EXINT reset */
#define CRM_APB2RST_TMR9RST_Pos             (16U)
#define CRM_APB2RST_TMR9RST_Msk             (0x1U << CRM_APB2RST_TMR9RST_Pos)       /*!< 0x00010000 */
#define CRM_APB2RST_TMR9RST                 CRM_APB2RST_TMR9RST_Msk                 /*!< TMR9 reset */
#define CRM_APB2RST_TMR10RST_Pos            (17U)
#define CRM_APB2RST_TMR10RST_Msk            (0x1U << CRM_APB2RST_TMR10RST_Pos)      /*!< 0x00020000 */
#define CRM_APB2RST_TMR10RST                CRM_APB2RST_TMR10RST_Msk                /*!< TMR10 reset */
#define CRM_APB2RST_TMR11RST_Pos            (18U)
#define CRM_APB2RST_TMR11RST_Msk            (0x1U << CRM_APB2RST_TMR11RST_Pos)      /*!< 0x00040000 */
#define CRM_APB2RST_TMR11RST                CRM_APB2RST_TMR11RST_Msk                /*!< TMR11 reset */
#define CRM_APB2RST_TMR20RST_Pos            (20U)
#define CRM_APB2RST_TMR20RST_Msk            (0x1U << CRM_APB2RST_TMR20RST_Pos)      /*!< 0x00100000 */
#define CRM_APB2RST_TMR20RST                CRM_APB2RST_TMR20RST_Msk                /*!< TMR20 reset */
#define CRM_APB2RST_ACCRST_Pos              (29U)
#define CRM_APB2RST_ACCRST_Msk              (0x1U << CRM_APB2RST_ACCRST_Pos)        /*!< 0x20000000 */
#define CRM_APB2RST_ACCRST                  CRM_APB2RST_ACCRST_Msk                  /*!< ACC reset */

/******************  Bit definition for CRM_AHBEN1 register  ******************/
#define CRM_AHBEN1_GPIOAEN_Pos              (0U)
#define CRM_AHBEN1_GPIOAEN_Msk              (0x1U << CRM_AHBEN1_GPIOAEN_Pos)        /*!< 0x00000001 */
#define CRM_AHBEN1_GPIOAEN                  CRM_AHBEN1_GPIOAEN_Msk                  /*!< IO port A clock enable */
#define CRM_AHBEN1_GPIOBEN_Pos              (1U)
#define CRM_AHBEN1_GPIOBEN_Msk              (0x1U << CRM_AHBEN1_GPIOBEN_Pos)        /*!< 0x00000002 */
#define CRM_AHBEN1_GPIOBEN                  CRM_AHBEN1_GPIOBEN_Msk                  /*!< IO port B clock enable */
#define CRM_AHBEN1_GPIOCEN_Pos              (2U)
#define CRM_AHBEN1_GPIOCEN_Msk              (0x1U << CRM_AHBEN1_GPIOCEN_Pos)        /*!< 0x00000004 */
#define CRM_AHBEN1_GPIOCEN                  CRM_AHBEN1_GPIOCEN_Msk                  /*!< IO port C clock enable */
#define CRM_AHBEN1_GPIODEN_Pos              (3U)
#define CRM_AHBEN1_GPIODEN_Msk              (0x1U << CRM_AHBEN1_GPIODEN_Pos)        /*!< 0x00000008 */
#define CRM_AHBEN1_GPIODEN                  CRM_AHBEN1_GPIODEN_Msk                  /*!< IO port D clock enable */
#define CRM_AHBEN1_GPIOEEN_Pos              (4U)
#define CRM_AHBEN1_GPIOEEN_Msk              (0x1U << CRM_AHBEN1_GPIOEEN_Pos)        /*!< 0x00000010 */
#define CRM_AHBEN1_GPIOEEN                  CRM_AHBEN1_GPIOEEN_Msk                  /*!< IO port E clock enable */
#define CRM_AHBEN1_GPIOFEN_Pos              (5U)
#define CRM_AHBEN1_GPIOFEN_Msk              (0x1U << CRM_AHBEN1_GPIOFEN_Pos)        /*!< 0x00000020 */
#define CRM_AHBEN1_GPIOFEN                  CRM_AHBEN1_GPIOFEN_Msk                  /*!< IO port F clock enable */
#define CRM_AHBEN1_GPIOGEN_Pos              (6U)
#define CRM_AHBEN1_GPIOGEN_Msk              (0x1U << CRM_AHBEN1_GPIOGEN_Pos)        /*!< 0x00000040 */
#define CRM_AHBEN1_GPIOGEN                  CRM_AHBEN1_GPIOGEN_Msk                  /*!< IO port G clock enable */
#define CRM_AHBEN1_GPIOHEN_Pos              (7U)
#define CRM_AHBEN1_GPIOHEN_Msk              (0x1U << CRM_AHBEN1_GPIOHEN_Pos)        /*!< 0x00000080 */
#define CRM_AHBEN1_GPIOHEN                  CRM_AHBEN1_GPIOHEN_Msk                  /*!< IO port H clock enable */
#define CRM_AHBEN1_CRCEN_Pos                (12U)
#define CRM_AHBEN1_CRCEN_Msk                (0x1U << CRM_AHBEN1_CRCEN_Pos)          /*!< 0x00001000 */
#define CRM_AHBEN1_CRCEN                    CRM_AHBEN1_CRCEN_Msk                    /*!< CRC clock enable */
#define CRM_AHBEN1_EDMAEN_Pos               (21U)
#define CRM_AHBEN1_EDMAEN_Msk               (0x1U << CRM_AHBEN1_EDMAEN_Pos)         /*!< 0x00200000 */
#define CRM_AHBEN1_EDMAEN                   CRM_AHBEN1_EDMAEN_Msk                   /*!< EDMA clock enable */
#define CRM_AHBEN1_DMA1EN_Pos               (22U)
#define CRM_AHBEN1_DMA1EN_Msk               (0x1U << CRM_AHBEN1_DMA1EN_Pos)         /*!< 0x00400000 */
#define CRM_AHBEN1_DMA1EN                   CRM_AHBEN1_DMA1EN_Msk                   /*!< DMA1 clock enable */
#define CRM_AHBEN1_DMA2EN_Pos               (24U)
#define CRM_AHBEN1_DMA2EN_Msk               (0x1U << CRM_AHBEN1_DMA2EN_Pos)         /*!< 0x01000000 */
#define CRM_AHBEN1_DMA2EN                   CRM_AHBEN1_DMA2EN_Msk                   /*!< DMA2 clock enable */
#define CRM_AHBEN1_EMACEN_Pos               (25U)
#define CRM_AHBEN1_EMACEN_Msk               (0x1U << CRM_AHBEN1_EMACEN_Pos)         /*!< 0x02000000 */
#define CRM_AHBEN1_EMACEN                   CRM_AHBEN1_EMACEN_Msk                   /*!< EMAC clock enable */
#define CRM_AHBEN1_EMACTXEN_Pos             (26U)
#define CRM_AHBEN1_EMACTXEN_Msk             (0x1U << CRM_AHBEN1_EMACTXEN_Pos)       /*!< 0x04000000 */
#define CRM_AHBEN1_EMACTXEN                 CRM_AHBEN1_EMACTXEN_Msk                 /*!< EMACTX clock enable */
#define CRM_AHBEN1_EMACRXEN_Pos             (27U)
#define CRM_AHBEN1_EMACRXEN_Msk             (0x1U << CRM_AHBEN1_EMACRXEN_Pos)       /*!< 0x08000000 */
#define CRM_AHBEN1_EMACRXEN                 CRM_AHBEN1_EMACRXEN_Msk                 /*!< EMACRX clock enable */
#define CRM_AHBEN1_EMACPTPEN_Pos            (28U)
#define CRM_AHBEN1_EMACPTPEN_Msk            (0x1U << CRM_AHBEN1_EMACPTPEN_Pos)       /*!< 0x10000000 */
#define CRM_AHBEN1_EMACPTPEN                CRM_AHBEN1_EMACPTPEN_Msk                 /*!< EMACPTP clock enable */
#define CRM_AHBEN1_OTGFS2EN_Pos             (29U)
#define CRM_AHBEN1_OTGFS2EN_Msk             (0x1U << CRM_AHBEN1_OTGFS2EN_Pos)        /*!< 0x20000000 */
#define CRM_AHBEN1_OTGFS2EN                 CRM_AHBEN1_OTGFS2EN_Msk                  /*!< OTGFS2 clock enable */

/******************  Bit definition for CRM_AHBEN2 register  ******************/
#define CRM_AHBEN2_DVPEN_Pos                (0U)
#define CRM_AHBEN2_DVPEN_Msk                (0x1U << CRM_AHBEN2_DVPEN_Pos)          /*!< 0x00000001 */
#define CRM_AHBEN2_DVPEN                    CRM_AHBEN2_DVPEN_Msk                    /*!< DVP clock enable */
#define CRM_AHBEN2_OTGFSEN_Pos              (7U)
#define CRM_AHBEN2_OTGFSEN_Msk              (0x1U << CRM_AHBEN2_OTGFSEN_Pos)        /*!< 0x00000080 */
#define CRM_AHBEN2_OTGFSEN                  CRM_AHBEN2_OTGFSEN_Msk                  /*!< OTGFS clock enable */
#define CRM_AHBEN2_SDIO1EN_Pos              (15U)
#define CRM_AHBEN2_SDIO1EN_Msk              (0x1U << CRM_AHBEN2_SDIO1EN_Pos)        /*!< 0x00008000 */
#define CRM_AHBEN2_SDIO1EN                  CRM_AHBEN2_SDIO1EN_Msk                  /*!< SDIO1 clock enable */

/******************  Bit definition for CRM_AHBEN3 register  ******************/
#define CRM_AHBEN3_XMCEN_Pos                (0U)
#define CRM_AHBEN3_XMCEN_Msk                (0x1U << CRM_AHBEN3_XMCEN_Pos)          /*!< 0x00000001 */
#define CRM_AHBEN3_XMCEN                    CRM_AHBEN3_XMCEN_Msk                    /*!< XMC clock enable */
#define CRM_AHBEN3_QSPI1EN_Pos              (1U)
#define CRM_AHBEN3_QSPI1EN_Msk              (0x1U << CRM_AHBEN3_QSPI1EN_Pos)        /*!< 0x00000002 */
#define CRM_AHBEN3_QSPI1EN                  CRM_AHBEN3_QSPI1EN_Msk                  /*!< QSPI1 clock enable */
#define CRM_AHBEN3_QSPI2EN_Pos              (14U)
#define CRM_AHBEN3_QSPI2EN_Msk              (0x1U << CRM_AHBEN3_QSPI2EN_Pos)        /*!< 0x00004000 */
#define CRM_AHBEN3_QSPI2EN                  CRM_AHBEN3_QSPI2EN_Msk                  /*!< QSPI2 clock enable */
#define CRM_AHBEN3_SDIO2EN_Pos              (15U)
#define CRM_AHBEN3_SDIO2EN_Msk              (0x1U << CRM_AHBEN3_SDIO2EN_Pos)        /*!< 0x00008000 */
#define CRM_AHBEN3_SDIO2EN                  CRM_AHBEN3_SDIO2EN_Msk                  /*!< SDIO2 clock enable */

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
#define CRM_APB1EN_TMR6EN_Pos               (4U)
#define CRM_APB1EN_TMR6EN_Msk               (0x1U << CRM_APB1EN_TMR6EN_Pos)         /*!< 0x00000010 */
#define CRM_APB1EN_TMR6EN                   CRM_APB1EN_TMR6EN_Msk                   /*!< TMR6 clock enable */
#define CRM_APB1EN_TMR7EN_Pos               (5U)
#define CRM_APB1EN_TMR7EN_Msk               (0x1U << CRM_APB1EN_TMR7EN_Pos)         /*!< 0x00000020 */
#define CRM_APB1EN_TMR7EN                   CRM_APB1EN_TMR7EN_Msk                   /*!< TMR7 clock enable */
#define CRM_APB1EN_TMR12EN_Pos              (6U)
#define CRM_APB1EN_TMR12EN_Msk              (0x1U << CRM_APB1EN_TMR12EN_Pos)        /*!< 0x00000040 */
#define CRM_APB1EN_TMR12EN                  CRM_APB1EN_TMR12EN_Msk                  /*!< TMR12 clock enable */
#define CRM_APB1EN_TMR13EN_Pos              (7U)
#define CRM_APB1EN_TMR13EN_Msk              (0x1U << CRM_APB1EN_TMR13EN_Pos)        /*!< 0x00000080 */
#define CRM_APB1EN_TMR13EN                  CRM_APB1EN_TMR13EN_Msk                  /*!< TMR13 clock enable */
#define CRM_APB1EN_TMR14EN_Pos              (8U)
#define CRM_APB1EN_TMR14EN_Msk              (0x1U << CRM_APB1EN_TMR14EN_Pos)        /*!< 0x00000100 */
#define CRM_APB1EN_TMR14EN                  CRM_APB1EN_TMR14EN_Msk                  /*!< TMR14 clock enable */
#define CRM_APB1EN_WWDTEN_Pos               (11U)
#define CRM_APB1EN_WWDTEN_Msk               (0x1U << CRM_APB1EN_WWDTEN_Pos)         /*!< 0x00000800 */
#define CRM_APB1EN_WWDTEN                   CRM_APB1EN_WWDTEN_Msk                   /*!< WWDT clock enable */
#define CRM_APB1EN_SPI2EN_Pos               (14U)
#define CRM_APB1EN_SPI2EN_Msk               (0x1U << CRM_APB1EN_SPI2EN_Pos)         /*!< 0x00004000 */
#define CRM_APB1EN_SPI2EN                   CRM_APB1EN_SPI2EN_Msk                   /*!< SPI2 clock enable */
#define CRM_APB1EN_SPI3EN_Pos               (15U)
#define CRM_APB1EN_SPI3EN_Msk               (0x1U << CRM_APB1EN_SPI3EN_Pos)         /*!< 0x00008000 */
#define CRM_APB1EN_SPI3EN                   CRM_APB1EN_SPI3EN_Msk                   /*!< SPI3 clock enable */
#define CRM_APB1EN_USART2EN_Pos             (17U)
#define CRM_APB1EN_USART2EN_Msk             (0x1U << CRM_APB1EN_USART2EN_Pos)       /*!< 0x00020000 */
#define CRM_APB1EN_USART2EN                 CRM_APB1EN_USART2EN_Msk                 /*!< USART2 clock enable */
#define CRM_APB1EN_USART3EN_Pos             (18U)
#define CRM_APB1EN_USART3EN_Msk             (0x1U << CRM_APB1EN_USART3EN_Pos)       /*!< 0x00040000 */
#define CRM_APB1EN_USART3EN                 CRM_APB1EN_USART3EN_Msk                 /*!< USART3 clock enable */
#define CRM_APB1EN_USART4EN_Pos             (19U)
#define CRM_APB1EN_USART4EN_Msk             (0x1U << CRM_APB1EN_USART4EN_Pos)       /*!< 0x00080000 */
#define CRM_APB1EN_USART4EN                 CRM_APB1EN_USART4EN_Msk                 /*!< USART4 clock enable */
#define CRM_APB1EN_USART5EN_Pos             (20U)
#define CRM_APB1EN_USART5EN_Msk             (0x1U << CRM_APB1EN_USART5EN_Pos)       /*!< 0x00100000 */
#define CRM_APB1EN_USART5EN                 CRM_APB1EN_USART5EN_Msk                 /*!< USART5 clock enable */
#define CRM_APB1EN_I2C1EN_Pos               (21U)
#define CRM_APB1EN_I2C1EN_Msk               (0x1U << CRM_APB1EN_I2C1EN_Pos)         /*!< 0x00200000 */
#define CRM_APB1EN_I2C1EN                   CRM_APB1EN_I2C1EN_Msk                   /*!< I2C1 clock enable */
#define CRM_APB1EN_I2C2EN_Pos               (22U)
#define CRM_APB1EN_I2C2EN_Msk               (0x1U << CRM_APB1EN_I2C2EN_Pos)         /*!< 0x00400000 */
#define CRM_APB1EN_I2C2EN                   CRM_APB1EN_I2C2EN_Msk                   /*!< I2C2 clock enable */
#define CRM_APB1EN_I2C3EN_Pos               (23U)
#define CRM_APB1EN_I2C3EN_Msk               (0x1U << CRM_APB1EN_I2C3EN_Pos)         /*!< 0x00800000 */
#define CRM_APB1EN_I2C3EN                   CRM_APB1EN_I2C3EN_Msk                   /*!< I2C3 clock enable */
#define CRM_APB1EN_CAN1EN_Pos               (25U)
#define CRM_APB1EN_CAN1EN_Msk               (0x1U << CRM_APB1EN_CAN1EN_Pos)         /*!< 0x02000000 */
#define CRM_APB1EN_CAN1EN                   CRM_APB1EN_CAN1EN_Msk                   /*!< CAN1 clock enable */
#define CRM_APB1EN_CAN2EN_Pos               (26U)
#define CRM_APB1EN_CAN2EN_Msk               (0x1U << CRM_APB1EN_CAN2EN_Pos)         /*!< 0x04000000 */
#define CRM_APB1EN_CAN2EN                   CRM_APB1EN_CAN2EN_Msk                   /*!< CAN2 clock enable */
#define CRM_APB1EN_PWCEN_Pos                (28U)
#define CRM_APB1EN_PWCEN_Msk                (0x1U << CRM_APB1EN_PWCEN_Pos)          /*!< 0x10000000 */
#define CRM_APB1EN_PWCEN                    CRM_APB1EN_PWCEN_Msk                    /*!< Power control clock enable */
#define CRM_APB1EN_DACEN_Pos                (29U)
#define CRM_APB1EN_DACEN_Msk                (0x1U << CRM_APB1EN_DACEN_Pos)          /*!< 0x20000000 */
#define CRM_APB1EN_DACEN                    CRM_APB1EN_DACEN_Msk                    /*!< DAC clock enable */
#define CRM_APB1EN_UART7EN_Pos              (30U)
#define CRM_APB1EN_UART7EN_Msk              (0x1U << CRM_APB1EN_UART7EN_Pos)        /*!< 0x40000000 */
#define CRM_APB1EN_UART7EN                  CRM_APB1EN_UART7EN_Msk                  /*!< UART7 clock enable */
#define CRM_APB1EN_UART8EN_Pos              (31U)
#define CRM_APB1EN_UART8EN_Msk              (0x1U << CRM_APB1EN_UART8EN_Pos)        /*!< 0x80000000 */
#define CRM_APB1EN_UART8EN                  CRM_APB1EN_UART8EN_Msk                  /*!< UART8 clock enable */

/******************  Bit definition for CRM_APB2EN register  ******************/
#define CRM_APB2EN_TMR1EN_Pos               (0U)
#define CRM_APB2EN_TMR1EN_Msk               (0x1U << CRM_APB2EN_TMR1EN_Pos)         /*!< 0x00000001 */
#define CRM_APB2EN_TMR1EN                   CRM_APB2EN_TMR1EN_Msk                   /*!< TMR1 clock enable */
#define CRM_APB2EN_TMR8EN_Pos               (1U)
#define CRM_APB2EN_TMR8EN_Msk               (0x1U << CRM_APB2EN_TMR8EN_Pos)         /*!< 0x00000002 */
#define CRM_APB2EN_TMR8EN                   CRM_APB2EN_TMR8EN_Msk                   /*!< TMR8 clock enable */
#define CRM_APB2EN_USART1EN_Pos             (4U)
#define CRM_APB2EN_USART1EN_Msk             (0x1U << CRM_APB2EN_USART1EN_Pos)       /*!< 0x00000010 */
#define CRM_APB2EN_USART1EN                 CRM_APB2EN_USART1EN_Msk                 /*!< USART1 clock enable */
#define CRM_APB2EN_USART6EN_Pos             (5U)
#define CRM_APB2EN_USART6EN_Msk             (0x1U << CRM_APB2EN_USART6EN_Pos)       /*!< 0x00000020 */
#define CRM_APB2EN_USART6EN                 CRM_APB2EN_USART6EN_Msk                 /*!< USART6 clock enable */
#define CRM_APB2EN_ADC1EN_Pos               (8U)
#define CRM_APB2EN_ADC1EN_Msk               (0x1U << CRM_APB2EN_ADC1EN_Pos)         /*!< 0x00000100 */
#define CRM_APB2EN_ADC1EN                   CRM_APB2EN_ADC1EN_Msk                   /*!< ADC1 clock enable */
#define CRM_APB2EN_ADC2EN_Pos               (9U)
#define CRM_APB2EN_ADC2EN_Msk               (0x1U << CRM_APB2EN_ADC2EN_Pos)         /*!< 0x00000200 */
#define CRM_APB2EN_ADC2EN                   CRM_APB2EN_ADC2EN_Msk                   /*!< ADC2 clock enable */
#define CRM_APB2EN_ADC3EN_Pos               (10U)
#define CRM_APB2EN_ADC3EN_Msk               (0x1U << CRM_APB2EN_ADC3EN_Pos)         /*!< 0x00000400 */
#define CRM_APB2EN_ADC3EN                   CRM_APB2EN_ADC3EN_Msk                   /*!< ADC3 clock enable */
#define CRM_APB2EN_SPI1EN_Pos               (12U)
#define CRM_APB2EN_SPI1EN_Msk               (0x1U << CRM_APB2EN_SPI1EN_Pos)         /*!< 0x00001000 */
#define CRM_APB2EN_SPI1EN                   CRM_APB2EN_SPI1EN_Msk                   /*!< SPI1 clock enable */
#define CRM_APB2EN_SPI4EN_Pos               (13U)
#define CRM_APB2EN_SPI4EN_Msk               (0x1U << CRM_APB2EN_SPI4EN_Pos)         /*!< 0x00002000 */
#define CRM_APB2EN_SPI4EN                   CRM_APB2EN_SPI4EN_Msk                   /*!< SPI4 clock enable */
#define CRM_APB2EN_SCFGEN_Pos               (14U)
#define CRM_APB2EN_SCFGEN_Msk               (0x1U << CRM_APB2EN_SCFGEN_Pos)         /*!< 0x00004000 */
#define CRM_APB2EN_SCFGEN                   CRM_APB2EN_SCFGEN_Msk                   /*!< SCFG clock enable */
#define CRM_APB2EN_TMR9EN_Pos               (16U)
#define CRM_APB2EN_TMR9EN_Msk               (0x1U << CRM_APB2EN_TMR9EN_Pos)         /*!< 0x00010000 */
#define CRM_APB2EN_TMR9EN                   CRM_APB2EN_TMR9EN_Msk                   /*!< TMR9 clock enable */
#define CRM_APB2EN_TMR10EN_Pos              (17U)
#define CRM_APB2EN_TMR10EN_Msk              (0x1U << CRM_APB2EN_TMR10EN_Pos)        /*!< 0x00020000 */
#define CRM_APB2EN_TMR10EN                  CRM_APB2EN_TMR10EN_Msk                  /*!< TMR10 clock enable */
#define CRM_APB2EN_TMR11EN_Pos              (18U)
#define CRM_APB2EN_TMR11EN_Msk              (0x1U << CRM_APB2EN_TMR11EN_Pos)        /*!< 0x00040000 */
#define CRM_APB2EN_TMR11EN                  CRM_APB2EN_TMR11EN_Msk                  /*!< TMR11 clock enable */
#define CRM_APB2EN_TMR20EN_Pos              (20U)
#define CRM_APB2EN_TMR20EN_Msk              (0x1U << CRM_APB2EN_TMR20EN_Pos)        /*!< 0x00100000 */
#define CRM_APB2EN_TMR20EN                  CRM_APB2EN_TMR20EN_Msk                  /*!< TMR20 clock enable */
#define CRM_APB2EN_ACCEN_Pos                (29U)
#define CRM_APB2EN_ACCEN_Msk                (0x1U << CRM_APB2EN_ACCEN_Pos)          /*!< 0x20000000 */
#define CRM_APB2EN_ACCEN                    CRM_APB2EN_ACCEN_Msk                    /*!< ACC clock enable */

/*****************  Bit definition for CRM_AHBLPEN1 register  *****************/
#define CRM_AHBLPEN1_GPIOALPEN_Pos          (0U)
#define CRM_AHBLPEN1_GPIOALPEN_Msk          (0x1U << CRM_AHBLPEN1_GPIOALPEN_Pos)    /*!< 0x00000001 */
#define CRM_AHBLPEN1_GPIOALPEN              CRM_AHBLPEN1_GPIOALPEN_Msk              /*!< IO port A clock enable in sleep mode */
#define CRM_AHBLPEN1_GPIOBLPEN_Pos          (1U)
#define CRM_AHBLPEN1_GPIOBLPEN_Msk          (0x1U << CRM_AHBLPEN1_GPIOBLPEN_Pos)    /*!< 0x00000002 */
#define CRM_AHBLPEN1_GPIOBLPEN              CRM_AHBLPEN1_GPIOBLPEN_Msk              /*!< IO port B clock enable in sleep mode */
#define CRM_AHBLPEN1_GPIOCLPEN_Pos          (2U)
#define CRM_AHBLPEN1_GPIOCLPEN_Msk          (0x1U << CRM_AHBLPEN1_GPIOCLPEN_Pos)    /*!< 0x00000004 */
#define CRM_AHBLPEN1_GPIOCLPEN              CRM_AHBLPEN1_GPIOCLPEN_Msk              /*!< IO port C clock enable in sleep mode */
#define CRM_AHBLPEN1_GPIODLPEN_Pos          (3U)
#define CRM_AHBLPEN1_GPIODLPEN_Msk          (0x1U << CRM_AHBLPEN1_GPIODLPEN_Pos)    /*!< 0x00000008 */
#define CRM_AHBLPEN1_GPIODLPEN              CRM_AHBLPEN1_GPIODLPEN_Msk              /*!< IO port D clock enable in sleep mode */
#define CRM_AHBLPEN1_GPIOELPEN_Pos          (4U)
#define CRM_AHBLPEN1_GPIOELPEN_Msk          (0x1U << CRM_AHBLPEN1_GPIOELPEN_Pos)    /*!< 0x00000010 */
#define CRM_AHBLPEN1_GPIOELPEN              CRM_AHBLPEN1_GPIOELPEN_Msk              /*!< IO port E clock enable in sleep mode */
#define CRM_AHBLPEN1_GPIOFLPEN_Pos          (5U)
#define CRM_AHBLPEN1_GPIOFLPEN_Msk          (0x1U << CRM_AHBLPEN1_GPIOFLPEN_Pos)    /*!< 0x00000020 */
#define CRM_AHBLPEN1_GPIOFLPEN              CRM_AHBLPEN1_GPIOFLPEN_Msk              /*!< IO port F clock enable in sleep mode */
#define CRM_AHBLPEN1_GPIOGLPEN_Pos          (6U)
#define CRM_AHBLPEN1_GPIOGLPEN_Msk          (0x1U << CRM_AHBLPEN1_GPIOGLPEN_Pos)    /*!< 0x00000040 */
#define CRM_AHBLPEN1_GPIOGLPEN              CRM_AHBLPEN1_GPIOGLPEN_Msk              /*!< IO port G clock enable in sleep mode */
#define CRM_AHBLPEN1_GPIOHLPEN_Pos          (7U)
#define CRM_AHBLPEN1_GPIOHLPEN_Msk          (0x1U << CRM_AHBLPEN1_GPIOHLPEN_Pos)    /*!< 0x00000080 */
#define CRM_AHBLPEN1_GPIOHLPEN              CRM_AHBLPEN1_GPIOHLPEN_Msk              /*!< IO port H clock enable in sleep mode */
#define CRM_AHBLPEN1_CRCLPEN_Pos            (12U)
#define CRM_AHBLPEN1_CRCLPEN_Msk            (0x1U << CRM_AHBLPEN1_CRCLPEN_Pos)      /*!< 0x00001000 */
#define CRM_AHBLPEN1_CRCLPEN                CRM_AHBLPEN1_CRCLPEN_Msk                /*!< CRC clock enable in sleep mode */
#define CRM_AHBLPEN1_FLASHLPEN_Pos          (15U)
#define CRM_AHBLPEN1_FLASHLPEN_Msk          (0x1U << CRM_AHBLPEN1_FLASHLPEN_Pos)    /*!< 0x00008000 */
#define CRM_AHBLPEN1_FLASHLPEN              CRM_AHBLPEN1_FLASHLPEN_Msk              /*!< FLASH clock enable in sleep mode */
#define CRM_AHBLPEN1_SRAMLPEN_Pos           (16U)
#define CRM_AHBLPEN1_SRAMLPEN_Msk           (0x1U << CRM_AHBLPEN1_SRAMLPEN_Pos)     /*!< 0x00010000 */
#define CRM_AHBLPEN1_SRAMLPEN               CRM_AHBLPEN1_SRAMLPEN_Msk               /*!< SRAM clock enable in sleep mode */
#define CRM_AHBLPEN1_SRAM2LPEN_Pos           (17U)
#define CRM_AHBLPEN1_SRAM2LPEN_Msk           (0x1U << CRM_AHBLPEN1_SRAM2LPEN_Pos)   /*!< 0x00020000 */
#define CRM_AHBLPEN1_SRAM2LPEN               CRM_AHBLPEN1_SRAM2LPEN_Msk             /*!< SRAM2 clock enable in sleep mode */
#define CRM_AHBLPEN1_EDMALPEN_Pos           (21U)
#define CRM_AHBLPEN1_EDMALPEN_Msk           (0x1U << CRM_AHBLPEN1_EDMALPEN_Pos)     /*!< 0x00200000 */
#define CRM_AHBLPEN1_EDMALPEN               CRM_AHBLPEN1_EDMALPEN_Msk               /*!< EDMA clock enable in sleep mode */
#define CRM_AHBLPEN1_DMA1LPEN_Pos           (22U)
#define CRM_AHBLPEN1_DMA1LPEN_Msk           (0x1U << CRM_AHBLPEN1_DMA1LPEN_Pos)     /*!< 0x00400000 */
#define CRM_AHBLPEN1_DMA1LPEN               CRM_AHBLPEN1_DMA1LPEN_Msk               /*!< DMA1 clock enable in sleep mode */
#define CRM_AHBLPEN1_DMA2LPEN_Pos           (24U)
#define CRM_AHBLPEN1_DMA2LPEN_Msk           (0x1U << CRM_AHBLPEN1_DMA2LPEN_Pos)     /*!< 0x01000000 */
#define CRM_AHBLPEN1_DMA2LPEN               CRM_AHBLPEN1_DMA2LPEN_Msk               /*!< DMA2 clock enable in sleep mode */
#define CRM_AHBLPEN1_EMACLPEN_Pos           (25U)
#define CRM_AHBLPEN1_EMACLPEN_Msk           (0x1U << CRM_AHBLPEN1_EMACLPEN_Pos)     /*!< 0x02000000 */
#define CRM_AHBLPEN1_EMACLPEN               CRM_AHBLPEN1_EMACLPEN_Msk               /*!< EMAC clock enable in sleep mode */
#define CRM_AHBLPEN1_EMACTXLPEN_Pos         (26U)
#define CRM_AHBLPEN1_EMACTXLPEN_Msk         (0x1U << CRM_AHBLPEN1_EMACTXLPEN_Pos)   /*!< 0x04000000 */
#define CRM_AHBLPEN1_EMACTXLPEN             CRM_AHBLPEN1_EMACTXLPEN_Msk             /*!< EMACTX clock enable in sleep mode */
#define CRM_AHBLPEN1_EMACRXLPEN_Pos         (27U)
#define CRM_AHBLPEN1_EMACRXLPEN_Msk         (0x1U << CRM_AHBLPEN1_EMACRXLPEN_Pos)     /*!< 0x08000000 */
#define CRM_AHBLPEN1_EMACRXLPEN             CRM_AHBLPEN1_EMACRXLPEN_Msk               /*!< EMACRX clock enable in sleep mode */
#define CRM_AHBLPEN1_EMACPTPLPEN_Pos        (27U)
#define CRM_AHBLPEN1_EMACPTPLPEN_Msk        (0x1U << CRM_AHBLPEN1_EMACPTPLPEN_Pos)    /*!< 0x10000000 */
#define CRM_AHBLPEN1_EMACPTPLPEN            CRM_AHBLPEN1_EMACPTPLPEN_Msk              /*!< EMACPTP clock enable in sleep mode */
#define CRM_AHBLPEN1_OTGFS2LPEN_Pos         (29U)
#define CRM_AHBLPEN1_OTGFS2LPEN_Msk         (0x1U << CRM_AHBLPEN1_OTGFS2LPEN_Pos)    /*!< 0x20000000 */
#define CRM_AHBLPEN1_OTGFS2LPEN             CRM_AHBLPEN1_OTGFS2LPEN_Msk              /*!< OTGFS2 clock enable in sleep mode (F405 only) */

/*****************  Bit definition for CRM_AHBLPEN2 register  *****************/
#define CRM_AHBLPEN2_DVPLPEN_Pos            (0U)
#define CRM_AHBLPEN2_DVPLPEN_Msk            (0x1U << CRM_AHBLPEN2_DVPLPEN_Pos)      /*!< 0x00000001 */
#define CRM_AHBLPEN2_DVPLPEN                CRM_AHBLPEN2_DVPLPEN_Msk                /*!< DVP clock enable in sleep mode */
#define CRM_AHBLPEN2_OTGFSLPEN_Pos          (7U)
#define CRM_AHBLPEN2_OTGFSLPEN_Msk          (0x1U << CRM_AHBLPEN2_OTGFSLPEN_Pos)    /*!< 0x00008000 */
#define CRM_AHBLPEN2_OTGFSLPEN              CRM_AHBLPEN2_OTGFSLPEN_Msk              /*!< OTGFS clock enable in sleep mode */
#define CRM_AHBLPEN2_SDIO1LPEN_Pos          (15U)
#define CRM_AHBLPEN2_SDIO1LPEN_Msk          (0x1U << CRM_AHBLPEN2_SDIO1LPEN_Pos)    /*!< 0x00000080 */
#define CRM_AHBLPEN2_SDIO1LPEN              CRM_AHBLPEN2_SDIO1LPEN_Msk              /*!< SDIO1 clock enable in sleep mode */

/*****************  Bit definition for CRM_AHBLPEN3 register  *****************/
#define CRM_AHBLPEN3_XMCLPEN_Pos            (0U)
#define CRM_AHBLPEN3_XMCLPEN_Msk            (0x1U << CRM_AHBLPEN2_XMCLPEN_Pos)      /*!< 0x00000001 */
#define CRM_AHBLPEN3_XMCLPEN                CRM_AHBLPEN2_XMCLPEN_Msk                /*!< XMC clock enable in sleep mode */
#define CRM_AHBLPEN3_QSPI1LPEN_Pos          (1U)
#define CRM_AHBLPEN3_QSPI1LPEN_Msk          (0x1U << CRM_AHBLPEN3_QSPI1LPEN_Pos)    /*!< 0x00000002 */
#define CRM_AHBLPEN3_QSPI1LPEN              CRM_AHBLPEN3_QSPI1LPEN_Msk              /*!< QSPI1 clock enable in sleep mode */
#define CRM_AHBLPEN3_QSPI2LPEN_Pos          (14U)
#define CRM_AHBLPEN3_QSPI2LPEN_Msk          (0x1U << CRM_AHBLPEN3_QSPI2LPEN_Pos)    /*!< 0x00004000 */
#define CRM_AHBLPEN3_QSPI2LPEN              CRM_AHBLPEN3_QSPI2LPEN_Msk              /*!< QSPI2 clock enable in sleep mode */
#define CRM_AHBLPEN3_SDIO2LPEN_Pos          (15U)
#define CRM_AHBLPEN3_SDIO2LPEN_Msk          (0x1U << CRM_AHBLPEN2_SDIO2LPEN_Pos)    /*!< 0x00000080 */
#define CRM_AHBLPEN3_SDIO2LPEN              CRM_AHBLPEN2_SDIO2LPEN_Msk              /*!< SDIO2 clock enable in sleep mode */

/*****************  Bit definition for CRM_APB1LPEN register  *****************/
#define CRM_APB1LPEN_TMR2LPEN_Pos           (0U)
#define CRM_APB1LPEN_TMR2LPEN_Msk           (0x1U << CRM_APB1LPEN_TMR2LPEN_Pos)     /*!< 0x00000001 */
#define CRM_APB1LPEN_TMR2LPEN               CRM_APB1LPEN_TMR2LPEN_Msk               /*!< TMR2 clock enable in sleep mode */
#define CRM_APB1LPEN_TMR3LPEN_Pos           (1U)
#define CRM_APB1LPEN_TMR3LPEN_Msk           (0x1U << CRM_APB1LPEN_TMR3LPEN_Pos)     /*!< 0x00000002 */
#define CRM_APB1LPEN_TMR3LPEN               CRM_APB1LPEN_TMR3LPEN_Msk               /*!< TMR3 clock enable in sleep mode */
#define CRM_APB1LPEN_TMR4LPEN_Pos           (2U)
#define CRM_APB1LPEN_TMR4LPEN_Msk           (0x1U << CRM_APB1LPEN_TMR4LPEN_Pos)     /*!< 0x00000004 */
#define CRM_APB1LPEN_TMR4LPEN               CRM_APB1LPEN_TMR4LPEN_Msk               /*!< TMR4 clock enable in sleep mode */
#define CRM_APB1LPEN_TMR5LPEN_Pos           (3U)
#define CRM_APB1LPEN_TMR5LPEN_Msk           (0x1U << CRM_APB1LPEN_TMR5LPEN_Pos)     /*!< 0x00000008 */
#define CRM_APB1LPEN_TMR5LPEN               CRM_APB1LPEN_TMR5LPEN_Msk               /*!< TMR5 clock enable in sleep mode */
#define CRM_APB1LPEN_TMR6LPEN_Pos           (4U)
#define CRM_APB1LPEN_TMR6LPEN_Msk           (0x1U << CRM_APB1LPEN_TMR6LPEN_Pos)     /*!< 0x00000010 */
#define CRM_APB1LPEN_TMR6LPEN               CRM_APB1LPEN_TMR6LPEN_Msk               /*!< TMR6 clock enable in sleep mode */
#define CRM_APB1LPEN_TMR7LPEN_Pos           (5U)
#define CRM_APB1LPEN_TMR7LPEN_Msk           (0x1U << CRM_APB1LPEN_TMR7LPEN_Pos)     /*!< 0x00000020 */
#define CRM_APB1LPEN_TMR7LPEN               CRM_APB1LPEN_TMR7LPEN_Msk               /*!< TMR7 clock enable in sleep mode */
#define CRM_APB1LPEN_TMR12LPEN_Pos          (6U)
#define CRM_APB1LPEN_TMR12LPEN_Msk          (0x1U << CRM_APB1LPEN_TMR12LPEN_Pos)    /*!< 0x00000040 */
#define CRM_APB1LPEN_TMR12LPEN              CRM_APB1LPEN_TMR12LPEN_Msk              /*!< TMR12 clock enable in sleep mode */
#define CRM_APB1LPEN_TMR13LPEN_Pos          (7U)
#define CRM_APB1LPEN_TMR13LPEN_Msk          (0x1U << CRM_APB1LPEN_TMR13LPEN_Pos)    /*!< 0x00000080 */
#define CRM_APB1LPEN_TMR13LPEN              CRM_APB1LPEN_TMR13LPEN_Msk              /*!< TMR13 clock enable in sleep mode */
#define CRM_APB1LPEN_TMR14LPEN_Pos          (8U)
#define CRM_APB1LPEN_TMR14LPEN_Msk          (0x1U << CRM_APB1LPEN_TMR14LPEN_Pos)    /*!< 0x00000100 */
#define CRM_APB1LPEN_TMR14LPEN              CRM_APB1LPEN_TMR14LPEN_Msk              /*!< TMR14 clock enable in sleep mode */
#define CRM_APB1LPEN_WWDTLPEN_Pos           (11U)
#define CRM_APB1LPEN_WWDTLPEN_Msk           (0x1U << CRM_APB1LPEN_WWDTLPEN_Pos)     /*!< 0x00000800 */
#define CRM_APB1LPEN_WWDTLPEN               CRM_APB1LPEN_WWDTLPEN_Msk               /*!< WWDT clock enable in sleep mode */
#define CRM_APB1LPEN_SPI2LPEN_Pos           (14U)
#define CRM_APB1LPEN_SPI2LPEN_Msk           (0x1U << CRM_APB1LPEN_SPI2LPEN_Pos)     /*!< 0x00004000 */
#define CRM_APB1LPEN_SPI2LPEN               CRM_APB1LPEN_SPI2LPEN_Msk               /*!< SPI2 clock enable in sleep mode */
#define CRM_APB1LPEN_SPI3LPEN_Pos           (15U)
#define CRM_APB1LPEN_SPI3LPEN_Msk           (0x1U << CRM_APB1LPEN_SPI3LPEN_Pos)     /*!< 0x00008000 */
#define CRM_APB1LPEN_SPI3LPEN               CRM_APB1LPEN_SPI3LPEN_Msk               /*!< SPI3 clock enable in sleep mode */
#define CRM_APB1LPEN_USART2LPEN_Pos         (17U)
#define CRM_APB1LPEN_USART2LPEN_Msk         (0x1U << CRM_APB1LPEN_USART2LPEN_Pos)   /*!< 0x00020000 */
#define CRM_APB1LPEN_USART2LPEN             CRM_APB1LPEN_USART2LPEN_Msk             /*!< USART2 clock enable in sleep mode */
#define CRM_APB1LPEN_USART3LPEN_Pos         (18U)
#define CRM_APB1LPEN_USART3LPEN_Msk         (0x1U << CRM_APB1LPEN_USART3LPEN_Pos)   /*!< 0x00040000 */
#define CRM_APB1LPEN_USART3LPEN             CRM_APB1LPEN_USART3LPEN_Msk             /*!< USART3 clock enable in sleep mode */
#define CRM_APB1LPEN_USART4LPEN_Pos         (19U)
#define CRM_APB1LPEN_USART4LPEN_Msk         (0x1U << CRM_APB1LPEN_USART4LPEN_Pos)   /*!< 0x00080000 */
#define CRM_APB1LPEN_USART4LPEN             CRM_APB1LPEN_USART4LPEN_Msk             /*!< USART4 clock enable in sleep mode */
#define CRM_APB1LPEN_USART5LPEN_Pos         (20U)
#define CRM_APB1LPEN_USART5LPEN_Msk         (0x1U << CRM_APB1LPEN_USART5LPEN_Pos)   /*!< 0x00100000 */
#define CRM_APB1LPEN_USART5LPEN             CRM_APB1LPEN_USART5LPEN_Msk             /*!< USART5 clock enable in sleep mode */
#define CRM_APB1LPEN_I2C1LPEN_Pos           (21U)
#define CRM_APB1LPEN_I2C1LPEN_Msk           (0x1U << CRM_APB1LPEN_I2C1LPEN_Pos)     /*!< 0x00200000 */
#define CRM_APB1LPEN_I2C1LPEN               CRM_APB1LPEN_I2C1LPEN_Msk               /*!< I2C1 clock enable in sleep mode */
#define CRM_APB1LPEN_I2C2LPEN_Pos           (22U)
#define CRM_APB1LPEN_I2C2LPEN_Msk           (0x1U << CRM_APB1LPEN_I2C2LPEN_Pos)     /*!< 0x00400000 */
#define CRM_APB1LPEN_I2C2LPEN               CRM_APB1LPEN_I2C2LPEN_Msk               /*!< I2C2 clock enable in sleep mode */
#define CRM_APB1LPEN_I2C3LPEN_Pos           (23U)
#define CRM_APB1LPEN_I2C3LPEN_Msk           (0x1U << CRM_APB1LPEN_I2C3LPEN_Pos)     /*!< 0x00800000 */
#define CRM_APB1LPEN_I2C3LPEN               CRM_APB1LPEN_I2C3LPEN_Msk               /*!< I2C3 clock enable in sleep mode */
#define CRM_APB1LPEN_CAN1LPEN_Pos           (25U)
#define CRM_APB1LPEN_CAN1LPEN_Msk           (0x1U << CRM_APB1LPEN_CAN1LPEN_Pos)     /*!< 0x02000000 */
#define CRM_APB1LPEN_CAN1LPEN               CRM_APB1LPEN_CAN1LPEN_Msk               /*!< CAN1 clock enable in sleep mode */
#define CRM_APB1LPEN_CAN2LPEN_Pos           (26U)
#define CRM_APB1LPEN_CAN2LPEN_Msk           (0x1U << CRM_APB1LPEN_CAN2LPEN_Pos)     /*!< 0x04000000 */
#define CRM_APB1LPEN_CAN2LPEN               CRM_APB1LPEN_CAN2LPEN_Msk               /*!< CAN2 clock enable in sleep mode */
#define CRM_APB1LPEN_PWCLPEN_Pos            (28U)
#define CRM_APB1LPEN_PWCLPEN_Msk            (0x1U << CRM_APB1LPEN_PWCLPEN_Pos)      /*!< 0x10000000 */
#define CRM_APB1LPEN_PWCLPEN                CRM_APB1LPEN_PWCLPEN_Msk                /*!< Power control clock enable in sleep mode */
#define CRM_APB1LPEN_DACLPEN_Pos            (29U)
#define CRM_APB1LPEN_DACLPEN_Msk            (0x1U << CRM_APB1LPEN_DACLPEN_Pos)      /*!< 0x20000000 */
#define CRM_APB1LPEN_DACLPEN                CRM_APB1LPEN_DACLPEN_Msk                /*!< DAC enable in sleep mode */
#define CRM_APB1LPEN_UART7LPEN_Pos          (30U)
#define CRM_APB1LPEN_UART7LPEN_Msk          (0x1U << CRM_APB1LPEN_UART7LPEN_Pos)    /*!< 0x40000000 */
#define CRM_APB1LPEN_UART7LPEN              CRM_APB1LPEN_UART7LPEN_Msk              /*!< UART7 clock enable in sleep mode */
#define CRM_APB1LPEN_UART8LPEN_Pos          (31U)
#define CRM_APB1LPEN_UART8LPEN_Msk          (0x1U << CRM_APB1LPEN_UART8LPEN_Pos)    /*!< 0x80000000 */
#define CRM_APB1LPEN_UART8LPEN              CRM_APB1LPEN_UART8LPEN_Msk              /*!< UART8 clock enable in sleep mode */

/*****************  Bit definition for CRM_APB2LPEN register  *****************/
#define CRM_APB2LPEN_TMR1LPEN_Pos           (0U)
#define CRM_APB2LPEN_TMR1LPEN_Msk           (0x1U << CRM_APB2LPEN_TMR1LPEN_Pos)     /*!< 0x00000001 */
#define CRM_APB2LPEN_TMR1LPEN               CRM_APB2LPEN_TMR1LPEN_Msk               /*!< TMR1 clock enable in sleep mode */
#define CRM_APB2LPEN_TMR8LPEN_Pos           (1U)
#define CRM_APB2LPEN_TMR8LPEN_Msk           (0x1U << CRM_APB2LPEN_TMR8LPEN_Pos)     /*!< 0x00000002 */
#define CRM_APB2LPEN_TMR8LPEN               CRM_APB2LPEN_TMR8LPEN_Msk               /*!< TMR8 clock enable in sleep mode */
#define CRM_APB2LPEN_USART1LPEN_Pos         (4U)
#define CRM_APB2LPEN_USART1LPEN_Msk         (0x1U << CRM_APB2LPEN_USART1LPEN_Pos)   /*!< 0x00000010 */
#define CRM_APB2LPEN_USART1LPEN             CRM_APB2LPEN_USART1LPEN_Msk             /*!< USART1 clock enable in sleep mode */
#define CRM_APB2LPEN_USART6LPEN_Pos         (5U)
#define CRM_APB2LPEN_USART6LPEN_Msk         (0x1U << CRM_APB2LPEN_USART6LPEN_Pos)   /*!< 0x00000020 */
#define CRM_APB2LPEN_USART6LPEN             CRM_APB2LPEN_USART6LPEN_Msk             /*!< USART6 clock enable in sleep mode */
#define CRM_APB2LPEN_ADC1LPEN_Pos           (8U)
#define CRM_APB2LPEN_ADC1LPEN_Msk           (0x1U << CRM_APB2LPEN_ADC1LPEN_Pos)     /*!< 0x00000100 */
#define CRM_APB2LPEN_ADC1LPEN               CRM_APB2LPEN_ADC1LPEN_Msk               /*!< ADC1 clock enable in sleep mode */
#define CRM_APB2LPEN_ADC2LPEN_Pos           (9U)
#define CRM_APB2LPEN_ADC2LPEN_Msk           (0x1U << CRM_APB2LPEN_ADC2LPEN_Pos)     /*!< 0x00000200 */
#define CRM_APB2LPEN_ADC2LPEN               CRM_APB2LPEN_ADC2LPEN_Msk               /*!< ADC2 clock enable in sleep mode */
#define CRM_APB2LPEN_ADC3LPEN_Pos           (10U)
#define CRM_APB2LPEN_ADC3LPEN_Msk           (0x1U << CRM_APB2LPEN_ADC3LPEN_Pos)     /*!< 0x00000400 */
#define CRM_APB2LPEN_ADC3LPEN               CRM_APB2LPEN_ADC3LPEN_Msk               /*!< ADC3 clock enable in sleep mode */
#define CRM_APB2LPEN_SPI1LPEN_Pos           (12U)
#define CRM_APB2LPEN_SPI1LPEN_Msk           (0x1U << CRM_APB2LPEN_SPI1LPEN_Pos)     /*!< 0x00001000 */
#define CRM_APB2LPEN_SPI1LPEN               CRM_APB2LPEN_SPI1LPEN_Msk               /*!< SPI1 clock enable in sleep mode */
#define CRM_APB2LPEN_SPI4LPEN_Pos           (13U)
#define CRM_APB2LPEN_SPI4LPEN_Msk           (0x1U << CRM_APB2LPEN_SPI4LPEN_Pos)     /*!< 0x00002000 */
#define CRM_APB2LPEN_SPI4LPEN               CRM_APB2LPEN_SPI4LPEN_Msk               /*!< SPI4 clock enable in sleep mode */
#define CRM_APB2LPEN_SCFGLPEN_Pos           (14U)
#define CRM_APB2LPEN_SCFGLPEN_Msk           (0x1U << CRM_APB2LPEN_SCFGLPEN_Pos)     /*!< 0x00004000 */
#define CRM_APB2LPEN_SCFGLPEN               CRM_APB2LPEN_SCFGLPEN_Msk               /*!< SCFG clock enable in sleep mode */
#define CRM_APB2LPEN_TMR9LPEN_Pos           (16U)
#define CRM_APB2LPEN_TMR9LPEN_Msk           (0x1U << CRM_APB2LPEN_TMR9LPEN_Pos)     /*!< 0x00010000 */
#define CRM_APB2LPEN_TMR9LPEN               CRM_APB2LPEN_TMR9LPEN_Msk               /*!< TMR9 clock enable in sleep mode */
#define CRM_APB2LPEN_TMR10LPEN_Pos          (17U)
#define CRM_APB2LPEN_TMR10LPEN_Msk          (0x1U << CRM_APB2LPEN_TMR10LPEN_Pos)    /*!< 0x00020000 */
#define CRM_APB2LPEN_TMR10LPEN              CRM_APB2LPEN_TMR10LPEN_Msk              /*!< TMR10 clock enable in sleep mode */
#define CRM_APB2LPEN_TMR11LPEN_Pos          (18U)
#define CRM_APB2LPEN_TMR11LPEN_Msk          (0x1U << CRM_APB2LPEN_TMR11LPEN_Pos)    /*!< 0x00040000 */
#define CRM_APB2LPEN_TMR11LPEN              CRM_APB2LPEN_TMR11LPEN_Msk              /*!< TMR11 clock enable in sleep mode */
#define CRM_APB2LPEN_TMR20LPEN_Pos          (20U)
#define CRM_APB2LPEN_TMR20LPEN_Msk          (0x1U << CRM_APB2LPEN_TMR20LPEN_Pos)    /*!< 0x00100000 */
#define CRM_APB2LPEN_TMR20LPEN              CRM_APB2LPEN_TMR20LPEN_Msk              /*!< TMR20 clock enable in sleep mode */
#define CRM_APB2LPEN_ACCLPEN_Pos            (29U)
#define CRM_APB2LPEN_ACCLPEN_Msk            (0x1U << CRM_APB2LPEN_ACCLPEN_Pos)      /*!< 0x20000000 */
#define CRM_APB2LPEN_ACCLPEN                CRM_APB2LPEN_ACCLPEN_Msk                /*!< ACC clock enable in sleep mode */

/*******************  Bit definition for CRM_BPDC register  *******************/
#define CRM_BPDC_LEXTEN_Pos                 (0U)
#define CRM_BPDC_LEXTEN_Msk                 (0x1U << CRM_BPDC_LEXTEN_Pos)           /*!< 0x00000001 */
#define CRM_BPDC_LEXTEN                     CRM_BPDC_LEXTEN_Msk                     /*!< External low-speed oscillator enable */
#define CRM_BPDC_LEXTSTBL_Pos               (1U)
#define CRM_BPDC_LEXTSTBL_Msk               (0x1U << CRM_BPDC_LEXTSTBL_Pos)         /*!< 0x00000002 */
#define CRM_BPDC_LEXTSTBL                   CRM_BPDC_LEXTSTBL_Msk                   /*!< External low-speed oscillator stable */
#define CRM_BPDC_LEXTBYPS_Pos               (2U)
#define CRM_BPDC_LEXTBYPS_Msk               (0x1U << CRM_BPDC_LEXTBYPS_Pos)         /*!< 0x00000004 */
#define CRM_BPDC_LEXTBYPS                   CRM_BPDC_LEXTBYPS_Msk                   /*!< External low-speed crystal bypass */

/*!< ERTCSEL congiguration */
#define CRM_BPDC_ERTCSEL_Pos                (8U)
#define CRM_BPDC_ERTCSEL_Msk                (0x3U << CRM_BPDC_ERTCSEL_Pos)          /*!< 0x00000300 */
#define CRM_BPDC_ERTCSEL                    CRM_BPDC_ERTCSEL_Msk                    /*!< ERTCSEL[1:0] bits (ERTC clock selection) */
#define CRM_BPDC_ERTCSEL_0                  (0x1U << CRM_BPDC_ERTCSEL_Pos)          /*!< 0x00000100 */
#define CRM_BPDC_ERTCSEL_1                  (0x2U << CRM_BPDC_ERTCSEL_Pos)          /*!< 0x00000200 */

#define CRM_BPDC_ERTCSEL_NOCLOCK            0x00000000U                             /*!< No clock */
#define CRM_BPDC_ERTCSEL_LEXT               0x00000100U                             /*!< LEXT */
#define CRM_BPDC_ERTCSEL_LICK               0x00000200U                             /*!< LICK */
#define CRM_BPDC_ERTCSEL_HEXT               0x00000300U                             /*!< Devided HEXT with ERTCDIV bit in CRM_CFG */

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

/******************  Bit definition for CRM_MISC1 register  *******************/
#define CRM_MISC1_HICKCAL_KEY_Pos           (0U)
#define CRM_MISC1_HICKCAL_KEY_Msk           (0xFFU << CRM_MISC1_HICKCAL_KEY_Pos)    /*!< 0x000000FF */
#define CRM_MISC1_HICKCAL_KEY               CRM_MISC1_HICKCAL_KEY_Msk               /*!< HICK calibration key */
#define CRM_MISC1_HICKDIV_Pos               (12U)
#define CRM_MISC1_HICKDIV_Msk               (0x1U << CRM_MISC1_HICKDIV_Pos)         /*!< 0x00001000 */
#define CRM_MISC1_HICKDIV                   CRM_MISC1_HICKDIV_Msk                   /*!< HICK 6 divider selection */
#define CRM_MISC1_HICK_TO_USB_Pos           (13U)
#define CRM_MISC1_HICK_TO_USB_Msk           (0x1U << CRM_MISC1_HICK_TO_USB_Pos)     /*!< 0x00002000 */
#define CRM_MISC1_HICK_TO_USB               CRM_MISC1_HICK_TO_USB_Msk               /*!< HICK to USB selection */
#define CRM_MISC1_HICK_TO_SCLK_Pos          (14U)
#define CRM_MISC1_HICK_TO_SCLK_Msk          (0x1U << CRM_MISC1_HICK_TO_SCLK_Pos)    /*!< 0x00004000 */
#define CRM_MISC1_HICK_TO_SCLK              CRM_MISC1_HICK_TO_SCLK_Msk              /*!< HICK as system clock frequency select */
#define CRM_MISC1_HICKRST_Pos               (15U)
#define CRM_MISC1_HICKRST_Msk               (0x1U << CRM_MISC1_HICKRST_Pos)         /*!< 0x00008000 */
#define CRM_MISC1_HICKRST                   CRM_MISC1_HICKRST_Msk                   /*!< HICKRST */

/*!< CLKOUT_SEL2 congiguration */
#define CRM_MISC1_CLKOUT_SEL2_Pos           (16U)
#define CRM_MISC1_CLKOUT_SEL2_Msk           (0xFU << CRM_MISC1_CLKOUT_SEL2_Pos)     /*!< 0x000F0000 */
#define CRM_MISC1_CLKOUT_SEL2               CRM_MISC1_CLKOUT_SEL2_Msk               /*!< CLKOUT_SEL2[3:0] bits (Clock output selection 2) */
#define CRM_MISC1_CLKOUT_SEL2_0             (0x1U << CRM_MISC1_CLKOUT_SEL2_Pos)     /*!< 0x00010000 */
#define CRM_MISC1_CLKOUT_SEL2_1             (0x2U << CRM_MISC1_CLKOUT_SEL2_Pos)     /*!< 0x00020000 */
#define CRM_MISC1_CLKOUT_SEL2_2             (0x4U << CRM_MISC1_CLKOUT_SEL2_Pos)     /*!< 0x00040000 */
#define CRM_MISC1_CLKOUT_SEL2_3             (0x8U << CRM_MISC1_CLKOUT_SEL2_Pos)     /*!< 0x00080000 */

#define CRM_MISC1_CLKOUT_SEL2_USBFS         0x00000000U                             /*!< USBFS 48M */
#define CRM_MISC1_CLKOUT_SEL2_ADC           0x00010000U                             /*!< ADC */
#define CRM_MISC1_CLKOUT_SEL2_HICK          0x00020000U                             /*!< HICK */
#define CRM_MISC1_CLKOUT_SEL2_LICK          0x00030000U                             /*!< LICK */
#define CRM_MISC1_CLKOUT_SEL2_LEXT          0x00040000U                             /*!< LEXT */

/* Reference defines */
#define CRM_MISC1_CLKSEL2                   CRM_MISC1_CLKOUT_SEL2
#define CRM_MISC1_CLKSEL2_0                 CRM_MISC1_CLKOUT_SEL2_0
#define CRM_MISC1_CLKSEL2_1                 CRM_MISC1_CLKOUT_SEL2_1
#define CRM_MISC1_CLKSEL2_2                 CRM_MISC1_CLKOUT_SEL2_2
#define CRM_MISC1_CLKSEL2_3                 CRM_MISC1_CLKOUT_SEL2_3
#define CRM_MISC1_CLKSEL2_USBFS             CRM_MISC1_CLKOUT_SEL2_USBFS
#define CRM_MISC1_CLKSEL2_ADC               CRM_MISC1_CLKOUT_SEL2_ADC
#define CRM_MISC1_CLKSEL2_HICK              CRM_MISC1_CLKOUT_SEL2_HICK
#define CRM_MISC1_CLKSEL2_LICK              CRM_MISC1_CLKOUT_SEL2_LICK
#define CRM_MISC1_CLKSEL2_LEXT              CRM_MISC1_CLKOUT_SEL2_LEXT

/*!< CLKOUTDIV2 congiguration */
#define CRM_MISC1_CLKOUTDIV2_Pos            (28U)
#define CRM_MISC1_CLKOUTDIV2_Msk            (0xFU << CRM_MISC1_CLKOUTDIV2_Pos)      /*!< 0xF0000000 */
#define CRM_MISC1_CLKOUTDIV2                CRM_MISC1_CLKOUTDIV2_Msk                /*!< CLKOUTDIV2[3:0] bits (Clock output division 2) */
#define CRM_MISC1_CLKOUTDIV2_0              (0x1U << CRM_MISC1_CLKOUTDIV2_Pos)      /*!< 0x10000000 */
#define CRM_MISC1_CLKOUTDIV2_1              (0x2U << CRM_MISC1_CLKOUTDIV2_Pos)      /*!< 0x20000000 */
#define CRM_MISC1_CLKOUTDIV2_2              (0x4U << CRM_MISC1_CLKOUTDIV2_Pos)      /*!< 0x40000000 */
#define CRM_MISC1_CLKOUTDIV2_3              (0x8U << CRM_MISC1_CLKOUTDIV2_Pos)      /*!< 0x80000000 */

#define CRM_MISC1_CLKOUTDIV2_DIV1           0x00000000U                             /*!< No clock output */
#define CRM_MISC1_CLKOUTDIV2_DIV2           0x80000000U                             /*!< Clock output divided by 2 */
#define CRM_MISC1_CLKOUTDIV2_DIV4           0x90000000U                             /*!< Clock output divided by 4 */
#define CRM_MISC1_CLKOUTDIV2_DIV8           0xA0000000U                             /*!< Clock output divided by 8 */
#define CRM_MISC1_CLKOUTDIV2_DIV16          0xB0000000U                             /*!< Clock output divided by 16 */
#define CRM_MISC1_CLKOUTDIV2_DIV64          0xC0000000U                             /*!< Clock output divided by 64 */
#define CRM_MISC1_CLKOUTDIV2_DIV128         0xD0000000U                             /*!< Clock output divided by 128 */
#define CRM_MISC1_CLKOUTDIV2_DIV256         0xE0000000U                             /*!< Clock output divided by 256 */
#define CRM_MISC1_CLKOUTDIV2_DIV512         0xF0000000U                             /*!< Clock output divided by 512 */

/******************  Bit definition for CRM_MISC2 register  *******************/
/*!< AUTO_STEP_EN congiguration */
#define CRM_MISC2_AUTO_STEP_EN_Pos          (4U)
#define CRM_MISC2_AUTO_STEP_EN_Msk          (0x3U << CRM_MISC2_AUTO_STEP_EN_Pos)    /*!< 0x00000030 */
#define CRM_MISC2_AUTO_STEP_EN              CRM_MISC2_AUTO_STEP_EN_Msk              /*!< AUTO_STEP_EN[1:0] bits (Auto step-by-step SCLK switch enable) */
#define CRM_MISC2_AUTO_STEP_EN_0            (0x1U << CRM_MISC2_AUTO_STEP_EN_Pos)    /*!< 0x00000010 */
#define CRM_MISC2_AUTO_STEP_EN_1            (0x2U << CRM_MISC2_AUTO_STEP_EN_Pos)    /*!< 0x00000020 */

#define CRM_MISC2_CLK1_TO_TMR_Pos           (8U)
#define CRM_MISC2_CLK1_TO_TMR_Msk           (0x1U << CRM_MISC1_CLK1_TO_TMR_Pos)    /*!< 0x00000100 */
#define CRM_MISC2_CLK1_TO_TMR               CRM_MISC1_CLK1_TO_TMR_Msk              /*!< CLK1 to timer select */

#define CRM_MISC2_EMAC_PPS_SEL_Pos          (9U)
#define CRM_MISC2_EMAC_PPS_SEL_Msk          (0x1U << CRM_MISC1_EMAC_PPS_SEL_Pos)    /*!< 0x00000200 */
#define CRM_MISC2_EMAC_PPS_SEL              CRM_MISC1_EMAC_PPS_SEL_Msk              /*!< Ethernet pulse width select */

/*!< USBDIV configuration */
#define CRM_MISC2_USBDIV_Pos                (12U)
#define CRM_MISC2_USBDIV_Msk                (0xFU << CRM_MISC2_USBDIV_Pos)          /*!< 0x0000F000 */
#define CRM_MISC2_USBDIV                    CRM_MISC2_USBDIV_Msk                    /*!< USB division */
#define CRM_MISC2_USBDIV_0                  (0x1U << CRM_MISC2_USBDIV_Pos)          /*!< 0x00001000 */
#define CRM_MISC2_USBDIV_1                  (0x2U << CRM_MISC2_USBDIV_Pos)          /*!< 0x00002000 */
#define CRM_MISC2_USBDIV_2                  (0x4U << CRM_MISC2_USBDIV_Pos)          /*!< 0x00004000 */
#define CRM_MISC2_USBDIV_4                  (0x8U << CRM_MISC2_USBDIV_Pos)          /*!< 0x00008000 */
#define CRM_MISC2_USBDIV_DIV1_5             0x00000000U                             /*!< PLL/1.5 */
#define CRM_MISC2_USBDIV_DIV1               0x00001000U                             /*!< PLL/1 */
#define CRM_MISC2_USBDIV_DIV2_5             0x00002000U                             /*!< PLL/2.5 */
#define CRM_MISC2_USBDIV_DIV2               0x00003000U                             /*!< PLL/2 */
#define CRM_MISC2_USBDIV_DIV3_5             0x00004000U                             /*!< PLL/3.5 */
#define CRM_MISC2_USBDIV_DIV3               0x00005000U                             /*!< PLL/3 */
#define CRM_MISC2_USBDIV_DIV4_5             0x00006000U                             /*!< PLL/4.5 */
#define CRM_MISC2_USBDIV_DIV4               0x00007000U                             /*!< PLL/4 */
#define CRM_MISC2_USBDIV_DIV5_5             0x00008000U                             /*!< PLL/5.5 */
#define CRM_MISC2_USBDIV_DIV5               0x00009000U                             /*!< PLL/5 */
#define CRM_MISC2_USBDIV_DIV6_5             0x0000A000U                             /*!< PLL/6.5 */
#define CRM_MISC2_USBDIV_DIV6               0x0000B000U                             /*!< PLL/6 */
#define CRM_MISC2_USBDIV_DIV7               0x0000C000U                             /*!< PLL/7 */

/******************************************************************************/
/*                                                                            */
/*                      Enhanced real-time clock (ERTC)                       */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for ERTC_TIME register  *******************/
/*!< SU configuration */
#define ERTC_TIME_SU_Pos                    (0U)
#define ERTC_TIME_SU_Msk                    (0xFU << ERTC_TIME_SU_Pos)              /*!< 0x0000000F */
#define ERTC_TIME_SU                        ERTC_TIME_SU_Msk                        /*!< SU[3:0] (Second units) */
#define ERTC_TIME_SU_0                      (0x1U << ERTC_TIME_SU_Pos)              /*!< 0x00000001 */
#define ERTC_TIME_SU_1                      (0x2U << ERTC_TIME_SU_Pos)              /*!< 0x00000002 */
#define ERTC_TIME_SU_2                      (0x4U << ERTC_TIME_SU_Pos)              /*!< 0x00000004 */
#define ERTC_TIME_SU_3                      (0x8U << ERTC_TIME_SU_Pos)              /*!< 0x00000008 */

/*!< ST configuration */
#define ERTC_TIME_ST_Pos                    (4U)
#define ERTC_TIME_ST_Msk                    (0x7U << ERTC_TIME_ST_Pos)              /*!< 0x00000070 */
#define ERTC_TIME_ST                        ERTC_TIME_ST_Msk                        /*!< ST[2:0] (Second tens) */
#define ERTC_TIME_ST_0                      (0x1U << ERTC_TIME_ST_Pos)              /*!< 0x00000010 */
#define ERTC_TIME_ST_1                      (0x2U << ERTC_TIME_ST_Pos)              /*!< 0x00000020 */
#define ERTC_TIME_ST_2                      (0x4U << ERTC_TIME_ST_Pos)              /*!< 0x00000040 */

/*!< MU configuration */
#define ERTC_TIME_MU_Pos                    (8U)
#define ERTC_TIME_MU_Msk                    (0xFU << ERTC_TIME_MU_Pos)              /*!< 0x00000F00 */
#define ERTC_TIME_MU                        ERTC_TIME_MU_Msk                        /*!< MU[3:0] (Minute units) */
#define ERTC_TIME_MU_0                      (0x1U << ERTC_TIME_MU_Pos)              /*!< 0x00000100 */
#define ERTC_TIME_MU_1                      (0x2U << ERTC_TIME_MU_Pos)              /*!< 0x00000200 */
#define ERTC_TIME_MU_2                      (0x4U << ERTC_TIME_MU_Pos)              /*!< 0x00000400 */
#define ERTC_TIME_MU_3                      (0x8U << ERTC_TIME_MU_Pos)              /*!< 0x00000800 */

/*!< MT configuration */
#define ERTC_TIME_MT_Pos                    (12U)
#define ERTC_TIME_MT_Msk                    (0x7U << ERTC_TIME_MT_Pos)              /*!< 0x00007000 */
#define ERTC_TIME_MT                        ERTC_TIME_MT_Msk                        /*!< MT[2:0] (Minute tens) */
#define ERTC_TIME_MT_0                      (0x1U << ERTC_TIME_MT_Pos)              /*!< 0x00001000 */
#define ERTC_TIME_MT_1                      (0x2U << ERTC_TIME_MT_Pos)              /*!< 0x00002000 */
#define ERTC_TIME_MT_2                      (0x4U << ERTC_TIME_MT_Pos)              /*!< 0x00004000 */

/*!< HU configuration */
#define ERTC_TIME_HU_Pos                    (16U)
#define ERTC_TIME_HU_Msk                    (0xFU << ERTC_TIME_HU_Pos)              /*!< 0x000F0000 */
#define ERTC_TIME_HU                        ERTC_TIME_HU_Msk                        /*!< HU[3:0] (Hour units) */
#define ERTC_TIME_HU_0                      (0x1U << ERTC_TIME_HU_Pos)              /*!< 0x00010000 */
#define ERTC_TIME_HU_1                      (0x2U << ERTC_TIME_HU_Pos)              /*!< 0x00020000 */
#define ERTC_TIME_HU_2                      (0x4U << ERTC_TIME_HU_Pos)              /*!< 0x00040000 */
#define ERTC_TIME_HU_3                      (0x8U << ERTC_TIME_HU_Pos)              /*!< 0x00080000 */

/*!< HT configuration */
#define ERTC_TIME_HT_Pos                    (20U)
#define ERTC_TIME_HT_Msk                    (0x3U << ERTC_TIME_HT_Pos)              /*!< 0x00300000 */
#define ERTC_TIME_HT                        ERTC_TIME_HT_Msk                        /*!< HT[1:0] (Hour tens) */
#define ERTC_TIME_HT_0                      (0x1U << ERTC_TIME_HT_Pos)              /*!< 0x00100000 */
#define ERTC_TIME_HT_1                      (0x2U << ERTC_TIME_HT_Pos)              /*!< 0x00200000 */

#define ERTC_TIME_AMPM_Pos                  (22U)
#define ERTC_TIME_AMPM_Msk                  (0x1U << ERTC_TIME_AMPM_Pos)            /*!< 0x00400000 */
#define ERTC_TIME_AMPM                      ERTC_TIME_AMPM_Msk                      /*!< AM/PM */

/******************  Bit definition for ERTC_DATE register  *******************/
/*!< DU configuration */
#define ERTC_DATE_DU_Pos                    (0U)
#define ERTC_DATE_DU_Msk                    (0xFU << ERTC_DATE_DU_Pos)              /*!< 0x0000000F */
#define ERTC_DATE_DU                        ERTC_DATE_DU_Msk                        /*!< DU[3:0] (Date units) */
#define ERTC_DATE_DU_0                      (0x1U << ERTC_DATE_DU_Pos)              /*!< 0x00000001 */
#define ERTC_DATE_DU_1                      (0x2U << ERTC_DATE_DU_Pos)              /*!< 0x00000002 */
#define ERTC_DATE_DU_2                      (0x4U << ERTC_DATE_DU_Pos)              /*!< 0x00000004 */
#define ERTC_DATE_DU_3                      (0x8U << ERTC_DATE_DU_Pos)              /*!< 0x00000008 */

/*!< DT configuration */
#define ERTC_DATE_DT_Pos                    (4U)
#define ERTC_DATE_DT_Msk                    (0x3U << ERTC_DATE_DT_Pos)              /*!< 0x00300000 */
#define ERTC_DATE_DT                        ERTC_DATE_DT_Msk                        /*!< DT[1:0] (Date tens) */
#define ERTC_DATE_DT_0                      (0x1U << ERTC_DATE_DT_Pos)              /*!< 0x00000010 */
#define ERTC_DATE_DT_1                      (0x2U << ERTC_DATE_DT_Pos)              /*!< 0x00000020 */

/*!< MU configuration */
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

/*!< WK configuration */
#define ERTC_DATE_WK_Pos                    (13U)
#define ERTC_DATE_WK_Msk                    (0x7U << ERTC_DATE_WK_Pos)              /*!< 0x0000E000 */
#define ERTC_DATE_WK                        ERTC_DATE_WK_Msk                        /*!< WK[2:0] (Week day) */
#define ERTC_DATE_WK_0                      (0x1U << ERTC_DATE_WK_Pos)              /*!< 0x00002000 */
#define ERTC_DATE_WK_1                      (0x2U << ERTC_DATE_WK_Pos)              /*!< 0x00004000 */
#define ERTC_DATE_WK_2                      (0x4U << ERTC_DATE_WK_Pos)              /*!< 0x00008000 */

/*!< YU configuration */
#define ERTC_DATE_YU_Pos                    (16U)
#define ERTC_DATE_YU_Msk                    (0xFU << ERTC_DATE_YU_Pos)              /*!< 0x000F0000 */
#define ERTC_DATE_YU                        ERTC_DATE_YU_Msk                        /*!< YU[3:0] (Year units) */
#define ERTC_DATE_YU_0                      (0x1U << ERTC_DATE_YU_Pos)              /*!< 0x00010000 */
#define ERTC_DATE_YU_1                      (0x2U << ERTC_DATE_YU_Pos)              /*!< 0x00020000 */
#define ERTC_DATE_YU_2                      (0x4U << ERTC_DATE_YU_Pos)              /*!< 0x00040000 */
#define ERTC_DATE_YU_3                      (0x8U << ERTC_DATE_YU_Pos)              /*!< 0x00080000 */

/*!< YT configuration */
#define ERTC_DATE_YT_Pos                    (20U)
#define ERTC_DATE_YT_Msk                    (0xFU << ERTC_DATE_YT_Pos)              /*!< 0x00F00000 */
#define ERTC_DATE_YT                        ERTC_DATE_YT_Msk                        /*!< YT[3:0] (Year tens) */
#define ERTC_DATE_YT_0                      (0x1U << ERTC_DATE_YT_Pos)              /*!< 0x00100000 */
#define ERTC_DATE_YT_1                      (0x2U << ERTC_DATE_YT_Pos)              /*!< 0x00200000 */
#define ERTC_DATE_YT_2                      (0x4U << ERTC_DATE_YT_Pos)              /*!< 0x00400000 */
#define ERTC_DATE_YT_3                      (0x8U << ERTC_DATE_YT_Pos)              /*!< 0x00800000 */

/******************  Bit definition for ERTC_CTRL register  *******************/
/*!< WATCLK configuration */
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

/*!< OUTSEL configuration */
#define ERTC_CTRL_OUTSEL_Pos                (21U)
#define ERTC_CTRL_OUTSEL_Msk                (0x3U << ERTC_CTRL_OUTSEL_Pos)          /*!< 0x00600000 */
#define ERTC_CTRL_OUTSEL                    ERTC_CTRL_OUTSEL_Msk                    /*!< OUTSEL[1:0] (Output source selection) */
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
#define ERTC_STS_TP2F_Pos                   (14U)
#define ERTC_STS_TP2F_Msk                   (0x1U << ERTC_STS_TP2F_Pos)             /*!< 0x00004000 */
#define ERTC_STS_TP2F                       ERTC_STS_TP2F_Msk                       /*!< Tamper detection 2 flag */
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

/*******************  Bit definition for ERTC_ALA register  *******************/
/*!< SU configuration */
#define ERTC_ALA_SU_Pos                     (0U)
#define ERTC_ALA_SU_Msk                     (0xFU << ERTC_ALA_SU_Pos)               /*!< 0x0000000F */
#define ERTC_ALA_SU                         ERTC_ALA_SU_Msk                         /*!< SU[3:0] (Second units) */
#define ERTC_ALA_SU_0                       (0x1U << ERTC_ALA_SU_Pos)               /*!< 0x00000001 */
#define ERTC_ALA_SU_1                       (0x2U << ERTC_ALA_SU_Pos)               /*!< 0x00000002 */
#define ERTC_ALA_SU_2                       (0x4U << ERTC_ALA_SU_Pos)               /*!< 0x00000004 */
#define ERTC_ALA_SU_3                       (0x8U << ERTC_ALA_SU_Pos)               /*!< 0x00000008 */

/*!< ST configuration */
#define ERTC_ALA_ST_Pos                     (4U)
#define ERTC_ALA_ST_Msk                     (0x7U << ERTC_ALA_ST_Pos)               /*!< 0x00000070 */
#define ERTC_ALA_ST                         ERTC_ALA_ST_Msk                         /*!< ST[2:0] (Second tens) */
#define ERTC_ALA_ST_0                       (0x1U << ERTC_ALA_ST_Pos)               /*!< 0x00000010 */
#define ERTC_ALA_ST_1                       (0x2U << ERTC_ALA_ST_Pos)               /*!< 0x00000020 */
#define ERTC_ALA_ST_2                       (0x4U << ERTC_ALA_ST_Pos)               /*!< 0x00000040 */

#define ERTC_ALA_MASK1_Pos                  (7U)
#define ERTC_ALA_MASK1_Msk                  (0x1U << ERTC_ALA_MASK1_Pos)            /*!< 0x00000080 */
#define ERTC_ALA_MASK1                      ERTC_ALA_MASK1_Msk                      /*!< Second mask */

/*!< MU configuration */
#define ERTC_ALA_MU_Pos                     (8U)
#define ERTC_ALA_MU_Msk                     (0xFU << ERTC_ALA_MU_Pos)               /*!< 0x00000F00 */
#define ERTC_ALA_MU                         ERTC_ALA_MU_Msk                         /*!< MU[3:0] (Minute units) */
#define ERTC_ALA_MU_0                       (0x1U << ERTC_ALA_MU_Pos)               /*!< 0x00000100 */
#define ERTC_ALA_MU_1                       (0x2U << ERTC_ALA_MU_Pos)               /*!< 0x00000200 */
#define ERTC_ALA_MU_2                       (0x4U << ERTC_ALA_MU_Pos)               /*!< 0x00000400 */
#define ERTC_ALA_MU_3                       (0x8U << ERTC_ALA_MU_Pos)               /*!< 0x00000800 */

/*!< MT configuration */
#define ERTC_ALA_MT_Pos                     (12U)
#define ERTC_ALA_MT_Msk                     (0x7U << ERTC_ALA_MT_Pos)               /*!< 0x00007000 */
#define ERTC_ALA_MT                         ERTC_ALA_MT_Msk                         /*!< MT[2:0] (Minute tens) */
#define ERTC_ALA_MT_0                       (0x1U << ERTC_ALA_MT_Pos)               /*!< 0x00001000 */
#define ERTC_ALA_MT_1                       (0x2U << ERTC_ALA_MT_Pos)               /*!< 0x00002000 */
#define ERTC_ALA_MT_2                       (0x4U << ERTC_ALA_MT_Pos)               /*!< 0x00004000 */

#define ERTC_ALA_MASK2_Pos                  (15U)
#define ERTC_ALA_MASK2_Msk                  (0x1U << ERTC_ALA_MASK2_Pos)            /*!< 0x00008000 */
#define ERTC_ALA_MASK2                      ERTC_ALA_MASK2_Msk                      /*!< Minute mask */

/*!< HU configuration */
#define ERTC_ALA_HU_Pos                     (16U)
#define ERTC_ALA_HU_Msk                     (0xFU << ERTC_ALA_HU_Pos)               /*!< 0x000F0000 */
#define ERTC_ALA_HU                         ERTC_ALA_HU_Msk                         /*!< HU[3:0] (Hour units) */
#define ERTC_ALA_HU_0                       (0x1U << ERTC_ALA_HU_Pos)               /*!< 0x00010000 */
#define ERTC_ALA_HU_1                       (0x2U << ERTC_ALA_HU_Pos)               /*!< 0x00020000 */
#define ERTC_ALA_HU_2                       (0x4U << ERTC_ALA_HU_Pos)               /*!< 0x00040000 */
#define ERTC_ALA_HU_3                       (0x8U << ERTC_ALA_HU_Pos)               /*!< 0x00080000 */

/*!< HT configuration */
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

/*!< DU configuration */
#define ERTC_ALA_DU_Pos                     (24U)
#define ERTC_ALA_DU_Msk                     (0xFU << ERTC_ALA_DU_Pos)               /*!< 0x0F000000 */
#define ERTC_ALA_DU                         ERTC_ALA_DU_Msk                         /*!< DU[3:0] (Date/week day units) */
#define ERTC_ALA_DU_0                       (0x1U << ERTC_ALA_DU_Pos)               /*!< 0x01000000 */
#define ERTC_ALA_DU_1                       (0x2U << ERTC_ALA_DU_Pos)               /*!< 0x02000000 */
#define ERTC_ALA_DU_2                       (0x4U << ERTC_ALA_DU_Pos)               /*!< 0x04000000 */
#define ERTC_ALA_DU_3                       (0x8U << ERTC_ALA_DU_Pos)               /*!< 0x08000000 */

/*!< DT configuration */
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
/*!< SU configuration */
#define ERTC_ALB_SU_Pos                     (0U)
#define ERTC_ALB_SU_Msk                     (0xFU << ERTC_ALB_SU_Pos)               /*!< 0x0000000F */
#define ERTC_ALB_SU                         ERTC_ALB_SU_Msk                         /*!< SU[3:0] (Second units) */
#define ERTC_ALB_SU_0                       (0x1U << ERTC_ALB_SU_Pos)               /*!< 0x00000001 */
#define ERTC_ALB_SU_1                       (0x2U << ERTC_ALB_SU_Pos)               /*!< 0x00000002 */
#define ERTC_ALB_SU_2                       (0x4U << ERTC_ALB_SU_Pos)               /*!< 0x00000004 */
#define ERTC_ALB_SU_3                       (0x8U << ERTC_ALB_SU_Pos)               /*!< 0x00000008 */

/*!< ST configuration */
#define ERTC_ALB_ST_Pos                     (4U)
#define ERTC_ALB_ST_Msk                     (0x7U << ERTC_ALB_ST_Pos)               /*!< 0x00000070 */
#define ERTC_ALB_ST                         ERTC_ALB_ST_Msk                         /*!< ST[2:0] (Second tens) */
#define ERTC_ALB_ST_0                       (0x1U << ERTC_ALB_ST_Pos)               /*!< 0x00000010 */
#define ERTC_ALB_ST_1                       (0x2U << ERTC_ALB_ST_Pos)               /*!< 0x00000020 */
#define ERTC_ALB_ST_2                       (0x4U << ERTC_ALB_ST_Pos)               /*!< 0x00000040 */

#define ERTC_ALB_MASK1_Pos                  (7U)
#define ERTC_ALB_MASK1_Msk                  (0x1U << ERTC_ALB_MASK1_Pos)            /*!< 0x00000080 */
#define ERTC_ALB_MASK1                      ERTC_ALB_MASK1_Msk                      /*!< Second mask */

/*!< MU configuration */
#define ERTC_ALB_MU_Pos                     (8U)
#define ERTC_ALB_MU_Msk                     (0xFU << ERTC_ALB_MU_Pos)               /*!< 0x00000F00 */
#define ERTC_ALB_MU                         ERTC_ALB_MU_Msk                         /*!< MU[3:0] (Minute units) */
#define ERTC_ALB_MU_0                       (0x1U << ERTC_ALB_MU_Pos)               /*!< 0x00000100 */
#define ERTC_ALB_MU_1                       (0x2U << ERTC_ALB_MU_Pos)               /*!< 0x00000200 */
#define ERTC_ALB_MU_2                       (0x4U << ERTC_ALB_MU_Pos)               /*!< 0x00000400 */
#define ERTC_ALB_MU_3                       (0x8U << ERTC_ALB_MU_Pos)               /*!< 0x00000800 */

/*!< MT configuration */
#define ERTC_ALB_MT_Pos                     (12U)
#define ERTC_ALB_MT_Msk                     (0x7U << ERTC_ALB_MT_Pos)               /*!< 0x00007000 */
#define ERTC_ALB_MT                         ERTC_ALB_MT_Msk                         /*!< MT[2:0] (Minute tens) */
#define ERTC_ALB_MT_0                       (0x1U << ERTC_ALB_MT_Pos)               /*!< 0x00001000 */
#define ERTC_ALB_MT_1                       (0x2U << ERTC_ALB_MT_Pos)               /*!< 0x00002000 */
#define ERTC_ALB_MT_2                       (0x4U << ERTC_ALB_MT_Pos)               /*!< 0x00004000 */

#define ERTC_ALB_MASK2_Pos                  (15U)
#define ERTC_ALB_MASK2_Msk                  (0x1U << ERTC_ALB_MASK2_Pos)            /*!< 0x00008000 */
#define ERTC_ALB_MASK2                      ERTC_ALB_MASK2_Msk                      /*!< Minute mask */

/*!< HU configuration */
#define ERTC_ALB_HU_Pos                     (16U)
#define ERTC_ALB_HU_Msk                     (0xFU << ERTC_ALB_HU_Pos)               /*!< 0x000F0000 */
#define ERTC_ALB_HU                         ERTC_ALB_HU_Msk                         /*!< HU[3:0] (Hour units) */
#define ERTC_ALB_HU_0                       (0x1U << ERTC_ALB_HU_Pos)               /*!< 0x00010000 */
#define ERTC_ALB_HU_1                       (0x2U << ERTC_ALB_HU_Pos)               /*!< 0x00020000 */
#define ERTC_ALB_HU_2                       (0x4U << ERTC_ALB_HU_Pos)               /*!< 0x00040000 */
#define ERTC_ALB_HU_3                       (0x8U << ERTC_ALB_HU_Pos)               /*!< 0x00080000 */

/*!< HT configuration */
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

/*!< DU configuration */
#define ERTC_ALB_DU_Pos                     (24U)
#define ERTC_ALB_DU_Msk                     (0xFU << ERTC_ALB_DU_Pos)               /*!< 0x0F000000 */
#define ERTC_ALB_DU                         ERTC_ALB_DU_Msk                         /*!< DU[3:0] (Date/week day units) */
#define ERTC_ALB_DU_0                       (0x1U << ERTC_ALB_DU_Pos)               /*!< 0x01000000 */
#define ERTC_ALB_DU_1                       (0x2U << ERTC_ALB_DU_Pos)               /*!< 0x02000000 */
#define ERTC_ALB_DU_2                       (0x4U << ERTC_ALB_DU_Pos)               /*!< 0x04000000 */
#define ERTC_ALB_DU_3                       (0x8U << ERTC_ALB_DU_Pos)               /*!< 0x08000000 */

/*!< DT configuration */
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
/*!< SU configuration */
#define ERTC_TSTM_SU_Pos                    (0U)
#define ERTC_TSTM_SU_Msk                    (0xFU << ERTC_TSTM_SU_Pos)              /*!< 0x0000000F */
#define ERTC_TSTM_SU                        ERTC_TSTM_SU_Msk                        /*!< SU[3:0] (Second units) */
#define ERTC_TSTM_SU_0                      (0x1U << ERTC_TSTM_SU_Pos)              /*!< 0x00000001 */
#define ERTC_TSTM_SU_1                      (0x2U << ERTC_TSTM_SU_Pos)              /*!< 0x00000002 */
#define ERTC_TSTM_SU_2                      (0x4U << ERTC_TSTM_SU_Pos)              /*!< 0x00000004 */
#define ERTC_TSTM_SU_3                      (0x8U << ERTC_TSTM_SU_Pos)              /*!< 0x00000008 */

/*!< ST configuration */
#define ERTC_TSTM_ST_Pos                    (4U)
#define ERTC_TSTM_ST_Msk                    (0x7U << ERTC_TSTM_ST_Pos)              /*!< 0x00000070 */
#define ERTC_TSTM_ST                        ERTC_TSTM_ST_Msk                        /*!< ST[2:0] (Second tens) */
#define ERTC_TSTM_ST_0                      (0x1U << ERTC_TSTM_ST_Pos)              /*!< 0x00000010 */
#define ERTC_TSTM_ST_1                      (0x2U << ERTC_TSTM_ST_Pos)              /*!< 0x00000020 */
#define ERTC_TSTM_ST_2                      (0x4U << ERTC_TSTM_ST_Pos)              /*!< 0x00000040 */

/*!< MU configuration */
#define ERTC_TSTM_MU_Pos                    (8U)
#define ERTC_TSTM_MU_Msk                    (0xFU << ERTC_TSTM_MU_Pos)              /*!< 0x00000F00 */
#define ERTC_TSTM_MU                        ERTC_TSTM_MU_Msk                        /*!< MU[3:0] (Minute units) */
#define ERTC_TSTM_MU_0                      (0x1U << ERTC_TSTM_MU_Pos)              /*!< 0x00000100 */
#define ERTC_TSTM_MU_1                      (0x2U << ERTC_TSTM_MU_Pos)              /*!< 0x00000200 */
#define ERTC_TSTM_MU_2                      (0x4U << ERTC_TSTM_MU_Pos)              /*!< 0x00000400 */
#define ERTC_TSTM_MU_3                      (0x8U << ERTC_TSTM_MU_Pos)              /*!< 0x00000800 */

/*!< MT configuration */
#define ERTC_TSTM_MT_Pos                    (12U)
#define ERTC_TSTM_MT_Msk                    (0x7U << ERTC_TSTM_MT_Pos)              /*!< 0x00007000 */
#define ERTC_TSTM_MT                        ERTC_TSTM_MT_Msk                        /*!< MT[2:0] (Minute tens) */
#define ERTC_TSTM_MT_0                      (0x1U << ERTC_TSTM_MT_Pos)              /*!< 0x00001000 */
#define ERTC_TSTM_MT_1                      (0x2U << ERTC_TSTM_MT_Pos)              /*!< 0x00002000 */
#define ERTC_TSTM_MT_2                      (0x4U << ERTC_TSTM_MT_Pos)              /*!< 0x00004000 */

/*!< HU configuration */
#define ERTC_TSTM_HU_Pos                    (16U)
#define ERTC_TSTM_HU_Msk                    (0xFU << ERTC_TSTM_HU_Pos)              /*!< 0x000F0000 */
#define ERTC_TSTM_HU                        ERTC_TSTM_HU_Msk                        /*!< HU[3:0] (Hour units) */
#define ERTC_TSTM_HU_0                      (0x1U << ERTC_TSTM_HU_Pos)              /*!< 0x00010000 */
#define ERTC_TSTM_HU_1                      (0x2U << ERTC_TSTM_HU_Pos)              /*!< 0x00020000 */
#define ERTC_TSTM_HU_2                      (0x4U << ERTC_TSTM_HU_Pos)              /*!< 0x00040000 */
#define ERTC_TSTM_HU_3                      (0x8U << ERTC_TSTM_HU_Pos)              /*!< 0x00080000 */

/*!< HT configuration */
#define ERTC_TSTM_HT_Pos                    (20U)
#define ERTC_TSTM_HT_Msk                    (0x3U << ERTC_TSTM_HT_Pos)              /*!< 0x00300000 */
#define ERTC_TSTM_HT                        ERTC_TSTM_HT_Msk                        /*!< HT[1:0] (Hour tens) */
#define ERTC_TSTM_HT_0                      (0x1U << ERTC_TSTM_HT_Pos)              /*!< 0x00100000 */
#define ERTC_TSTM_HT_1                      (0x2U << ERTC_TSTM_HT_Pos)              /*!< 0x00200000 */

#define ERTC_TSTM_AMPM_Pos                  (22U)
#define ERTC_TSTM_AMPM_Msk                  (0x1U << ERTC_TSTM_AMPM_Pos)            /*!< 0x00400000 */
#define ERTC_TSTM_AMPM                      ERTC_TSTM_AMPM_Msk                      /*!< AM/PM */

/******************  Bit definition for ERTC_TSDT register  *******************/
/*!< DU configuration */
#define ERTC_TSDT_DU_Pos                    (0U)
#define ERTC_TSDT_DU_Msk                    (0xFU << ERTC_TSDT_DU_Pos)              /*!< 0x0000000F */
#define ERTC_TSDT_DU                        ERTC_TSDT_DU_Msk                        /*!< DU[3:0] (Date units) */
#define ERTC_TSDT_DU_0                      (0x1U << ERTC_TSDT_DU_Pos)              /*!< 0x00000001 */
#define ERTC_TSDT_DU_1                      (0x2U << ERTC_TSDT_DU_Pos)              /*!< 0x00000002 */
#define ERTC_TSDT_DU_2                      (0x4U << ERTC_TSDT_DU_Pos)              /*!< 0x00000004 */
#define ERTC_TSDT_DU_3                      (0x8U << ERTC_TSDT_DU_Pos)              /*!< 0x00000008 */

/*!< DT configuration */
#define ERTC_TSDT_DT_Pos                    (4U)
#define ERTC_TSDT_DT_Msk                    (0x3U << ERTC_TSDT_DT_Pos)              /*!< 0x00000030 */
#define ERTC_TSDT_DT                        ERTC_TSDT_DT_Msk                        /*!< DT[1:0] (Date tens) */
#define ERTC_TSDT_DT_0                      (0x1U << ERTC_TSDT_DT_Pos)              /*!< 0x00000010 */
#define ERTC_TSDT_DT_1                      (0x2U << ERTC_TSDT_DT_Pos)              /*!< 0x00000020 */

/*!< MU configuration */
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

/*!< WK configuration */
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
#define ERTC_TAMP_TP2EN_Pos                 (3U)
#define ERTC_TAMP_TP2EN_Msk                 (0x1U << ERTC_TAMP_TP2EN_Pos)           /*!< 0x00000008 */
#define ERTC_TAMP_TP2EN                     ERTC_TAMP_TP2EN_Msk                     /*!< Tamper detection 2 enable */
#define ERTC_TAMP_TP2EDG_Pos                (4U)
#define ERTC_TAMP_TP2EDG_Msk                (0x1U << ERTC_TAMP_TP2EDG_Pos)          /*!< 0x00000010 */
#define ERTC_TAMP_TP2EDG                    ERTC_TAMP_TP2EDG_Msk                    /*!< Tamper detection 2 valid edge */
#define ERTC_TAMP_TPTSEN_Pos                (7U)
#define ERTC_TAMP_TPTSEN_Msk                (0x1U << ERTC_TAMP_TPTSEN_Pos)          /*!< 0x00000080 */
#define ERTC_TAMP_TPTSEN                    ERTC_TAMP_TPTSEN_Msk                    /*!< Tamper detection timestamp enable */

/*!< TPFREQ configuration */
#define ERTC_TAMP_TPFREQ_Pos                (8U)
#define ERTC_TAMP_TPFREQ_Msk                (0x7U << ERTC_TAMP_TPFREQ_Pos)          /*!< 0x00000700 */
#define ERTC_TAMP_TPFREQ                    ERTC_TAMP_TPFREQ_Msk                    /*!< TPFREQ[2:0] (Tamper detection frequency) */
#define ERTC_TAMP_TPFREQ_0                  (0x1U << ERTC_TAMP_TPFREQ_Pos)          /*!< 0x00000100 */
#define ERTC_TAMP_TPFREQ_1                  (0x2U << ERTC_TAMP_TPFREQ_Pos)          /*!< 0x00000200 */
#define ERTC_TAMP_TPFREQ_2                  (0x4U << ERTC_TAMP_TPFREQ_Pos)          /*!< 0x00000400 */

/*!< TPFLT configuration */
#define ERTC_TAMP_TPFLT_Pos                 (11U)
#define ERTC_TAMP_TPFLT_Msk                 (0x3U << ERTC_TAMP_TPFLT_Pos)           /*!< 0x00001800 */
#define ERTC_TAMP_TPFLT                     ERTC_TAMP_TPFLT_Msk                     /*!< TPFLT[1:0] (Tamper detection filter time) */
#define ERTC_TAMP_TPFLT_0                   (0x1U << ERTC_TAMP_TPFLT_Pos)           /*!< 0x00000800 */
#define ERTC_TAMP_TPFLT_1                   (0x2U << ERTC_TAMP_TPFLT_Pos)           /*!< 0x00001000 */

/*!< TPPR configuration */
#define ERTC_TAMP_TPPR_Pos                  (13U)
#define ERTC_TAMP_TPPR_Msk                  (0x3U << ERTC_TAMP_TPPR_Pos)            /*!< 0x00006000 */
#define ERTC_TAMP_TPPR                      ERTC_TAMP_TPPR_Msk                      /*!< TPPR[1:0] (Tamper detection pre-charge time) */
#define ERTC_TAMP_TPPR_0                    (0x1U << ERTC_TAMP_TPPR_Pos)            /*!< 0x00002000 */
#define ERTC_TAMP_TPPR_1                    (0x2U << ERTC_TAMP_TPPR_Pos)            /*!< 0x00004000 */

#define ERTC_TAMP_TPPU_Pos                  (15U)
#define ERTC_TAMP_TPPU_Msk                  (0x1U << ERTC_TAMP_TPPU_Pos)            /*!< 0x00008000 */
#define ERTC_TAMP_TPPU                      ERTC_TAMP_TPPU_Msk                      /*!< Tamper detection pull-up */
#define ERTC_TAMP_TP1PIN_Pos                (16U)
#define ERTC_TAMP_TP1PIN_Msk                (0x1U << ERTC_TAMP_TP1PIN_Pos)          /*!< 0x00010000 */
#define ERTC_TAMP_TP1PIN                    ERTC_TAMP_TP1PIN_Msk                    /*!< Tamper detection pin selection */
#define ERTC_TAMP_TSPIN_Pos                 (17U)
#define ERTC_TAMP_TSPIN_Msk                 (0x1U << ERTC_TAMP_TSPIN_Pos)           /*!< 0x00020000 */
#define ERTC_TAMP_TSPIN                     ERTC_TAMP_TSPIN_Msk                     /*!< Time stamp detection pin selection */
#define ERTC_TAMP_OUTTYPE_Pos               (18U)
#define ERTC_TAMP_OUTTYPE_Msk               (0x1U << ERTC_TAMP_OUTTYPE_Pos)         /*!< 0x00040000 */
#define ERTC_TAMP_OUTTYPE                   ERTC_TAMP_OUTTYPE_Msk                   /*!< Output type */

/*****************  Bit definition for ERTC_ALASBS register  ******************/
#define ERTC_ALASBS_SBS_Pos                 (0U)
#define ERTC_ALASBS_SBS_Msk                 (0x7FFFU << ERTC_ALASBS_SBS_Pos)        /*!< 0x00007FFF */
#define ERTC_ALASBS_SBS                     ERTC_ALASBS_SBS_Msk                     /*!< Sub-second value */

/*!< SBSMSK configuration */
#define ERTC_ALASBS_SBSMSK_Pos              (24U)
#define ERTC_ALASBS_SBSMSK_Msk              (0xFU << ERTC_ALASBS_SBSMSK_Pos)        /*!< 0x0F000000 */
#define ERTC_ALASBS_SBSMSK                  ERTC_ALASBS_SBSMSK_Msk                  /*!< SBSMSK[3:0] (Sub-second mask) */
#define ERTC_ALASBS_SBSMSK_0                (0x1U << ERTC_ALASBS_SBSMSK_Pos)        /*!< 0x01000000 */
#define ERTC_ALASBS_SBSMSK_1                (0x2U << ERTC_ALASBS_SBSMSK_Pos)        /*!< 0x02000000 */
#define ERTC_ALASBS_SBSMSK_2                (0x4U << ERTC_ALASBS_SBSMSK_Pos)        /*!< 0x04000000 */
#define ERTC_ALASBS_SBSMSK_3                (0x8U << ERTC_ALASBS_SBSMSK_Pos)        /*!< 0x08000000 */

/*****************  Bit definition for ERTC_ALBSBS register  ******************/
#define ERTC_ALBSBS_SBS_Pos                 (0U)
#define ERTC_ALBSBS_SBS_Msk                 (0x7FFFU << ERTC_ALBSBS_SBS_Pos)        /*!< 0x00007FFF */
#define ERTC_ALBSBS_SBS                     ERTC_ALBSBS_SBS_Msk                     /*!< Sub-second value */

/*!< SBSMSK configuration */
#define ERTC_ALBSBS_SBSMSK_Pos              (24U)
#define ERTC_ALBSBS_SBSMSK_Msk              (0xFU << ERTC_ALBSBS_SBSMSK_Pos)        /*!< 0x0F000000 */
#define ERTC_ALBSBS_SBSMSK                  ERTC_ALBSBS_SBSMSK_Msk                  /*!< SBSMSK[3:0] (Sub-second mask) */
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
/*                             Power Control (PWC)                            */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for PWC_CTRL register  *******************/
#define PWC_CTRL_VRSEL_Pos                  (0U)
#define PWC_CTRL_VRSEL_Msk                  (0x1U << PWC_CTRL_VRSEL_Pos)            /*!< 0x00000001 */
#define PWC_CTRL_VRSEL                      PWC_CTRL_VRSEL_Msk                      /*!< LDO state select in deep sleep mode */
#define PWC_CTRL_LPSEL_Pos                  (1U)
#define PWC_CTRL_LPSEL_Msk                  (0x1U << PWC_CTRL_LPSEL_Pos)            /*!< 0x00000002 */
#define PWC_CTRL_LPSEL                      PWC_CTRL_LPSEL_Msk                      /*!< Low power mode select in deep sleep mode */
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
#define PWC_CTRLSTS_SWPEN1_Pos              (8U)
#define PWC_CTRLSTS_SWPEN1_Msk              (0x1U << PWC_CTRLSTS_SWPEN1_Pos)        /*!< 0x00000100 */
#define PWC_CTRLSTS_SWPEN1                  PWC_CTRLSTS_SWPEN1_Msk                  /*!< Standby wake-up pin 1 enable */
#define PWC_CTRLSTS_SWPEN2_Pos              (9U)
#define PWC_CTRLSTS_SWPEN2_Msk              (0x1U << PWC_CTRLSTS_SWPEN2_Pos)        /*!< 0x00000200 */
#define PWC_CTRLSTS_SWPEN2                  PWC_CTRLSTS_SWPEN2_Msk                  /*!< Standby wake-up pin 2 enable */

/******************  Bit definition for PWC_LDOOV register  *******************/
/*!< LDOOVSEL congiguration */
#define PWC_LDOOV_LDOOVSEL_Pos              (0U)
#define PWC_LDOOV_LDOOVSEL_Msk              (0x7U << PWC_LDOOV_LDOOVSEL_Pos)        /*!< 0x00000003 */
#define PWC_LDOOV_LDOOVSEL                  PWC_LDOOV_LDOOVSEL_Msk                  /*!< LDOOVSEL[2:0] bits (Voltage regulator output voltage select) */
#define PWC_LDOOV_LDOOVSEL_0                (0x1U << PWC_LDOOV_LDOOVSEL_Pos)        /*!< 0x00000001 */
#define PWC_LDOOV_LDOOVSEL_1                (0x2U << PWC_LDOOV_LDOOVSEL_Pos)        /*!< 0x00000002 */
#define PWC_LDOOV_LDOOVSEL_2                (0x4U << PWC_LDOOV_LDOOVSEL_Pos)        /*!< 0x00000004 */

#define PWC_LDOOV_LDOOVSEL_LEV1             0x00000004U                             /*!< Voltage output level 1.1V */
#define PWC_LDOOV_LDOOVSEL_LEV2             0x00000000U                             /*!< Voltage output level 1.2V */
#define PWC_LDOOV_LDOOVSEL_LEV3             0x00000001U                             /*!< Voltage output level 1.3V */

/* Legacy defines */
#define PWC_LDOOV_LDOOVSEL_1V1              PWC_LDOOV_LDOOVSEL_LEV1
#define PWC_LDOOV_LDOOVSEL_1V2              PWC_LDOOV_LDOOVSEL_LEV2
#define PWC_LDOOV_LDOOVSEL_1V3              PWC_LDOOV_LDOOVSEL_LEV3

/******************************************************************************/
/*                                                                            */
/*                Flash and User System Data Registers (FLASH)                */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for FLASH_PSR register  ******************/
#define FLASH_PSR_NZW_BST_STS_Pos           (13UL)                                  /*!< NZW_BST_STS (Bit 13) */
#define FLASH_PSR_NZW_BST_STS_Msk           (0x1U << FLASH_PSR_NZW_BST_STS_Pos)     /*!< NZW_BST_STS (Bitfield-Mask: 0x01) */
#define FLASH_PSR_NZW_BST_STS               FLASH_PSR_NZW_BST_STS_Msk               /*!< Flash non-zero wait area boost status */
#define FLASH_PSR_NZW_BST_Pos               (12UL)                                  /*!< NZW_BST (Bit 12) */
#define FLASH_PSR_NZW_BST_Msk               (0x1U << FLASH_PSR_NZW_BST_Pos)         /*!< NZW_BST (Bitfield-Mask: 0x01) */
#define FLASH_PSR_NZW_BST                   FLASH_PSR_NZW_BST_Msk

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
#define FLASH_STS_OBF                       FLASH_STS_OBF_Msk                       /*!< Operation busy flag */
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
#define FLASH_CTRL_BLKERS_Pos               (2U)
#define FLASH_CTRL_BLKERS_Msk               (0x1U << FLASH_CTRL_BLKERS_Pos)         /*!< 0x00000008 */
#define FLASH_CTRL_BLKERS                   FLASH_CTRL_BLKERS_Msk                   /*!< Block erase */
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
#define FLASH_USD_BTOPT_Pos                 (5U)
#define FLASH_USD_BTOPT_Msk                 (0x1U << FLASH_USD_BTOPT_Pos)           /*!< 0x00000040 */
#define FLASH_USD_BTOPT                     FLASH_USD_BTOPT_Msk                     /*!< BTOPT */
#define FLASH_USD_DEPSLP_WDT_Pos            (7U)
#define FLASH_USD_DEPSLP_WDT_Msk            (0x1U << FLASH_USD_DEPSLP_WDT_Pos)      /*!< 0x00000080 */
#define FLASH_USD_DEPSLP_WDT                FLASH_USD_DEPSLP_WDT_Msk                /*!< nDEPSLP_WDT */
#define FLASH_USD_STDBY_WDT_Pos             (8U)
#define FLASH_USD_STDBY_WDT_Msk             (0x1U << FLASH_USD_STDBY_WDT_Pos)       /*!< 0x00000100 */
#define FLASH_USD_STDBY_WDT                 FLASH_USD_STDBY_WDT_Msk                 /*!< nSTDBY_WDT */
#define FLASH_USD_USER_D0_Pos               (10U)
#define FLASH_USD_USER_D0_Msk               (0xFFU << FLASH_USD_USER_D0_Pos)        /*!< 0x0003FC00 */
#define FLASH_USD_USER_D0                   FLASH_USD_USER_D0_Msk                   /*!< User data 0 */
#define FLASH_USD_USER_D1_Pos               (18U)
#define FLASH_USD_USER_D1_Msk               (0xFFU << FLASH_USD_USER_D1_Pos)        /*!< 0x03FC0000 */
#define FLASH_USD_USER_D1                   FLASH_USD_USER_D1_Msk                   /*!< User data 1 */

/******************  Bit definition for FLASH_EPPS0 register  ******************/
#define FLASH_EPPS0_EPPS_Pos                (0U)
#define FLASH_EPPS0_EPPS_Msk                (0xFFFFFFFFU << FLASH_EPPS0_EPPS_Pos)    /*!< 0xFFFFFFFF */
#define FLASH_EPPS0_EPPS                    FLASH_EPPS0_EPPS_Msk                     /*!< Erase/Program protection status */

/******************  Bit definition for FLASH_EPPS1 register  ******************/
#define FLASH_EPPS1_EPPS_Pos                (0U)
#define FLASH_EPPS1_EPPS_Msk                (0xFFFFFFFFU << FLASH_EPPS1_EPPS_Pos)    /*!< 0xFFFFFFFF */
#define FLASH_EPPS1_EPPS                    FLASH_EPPS1_EPPS_Msk                     /*!< Erase/Program protection status */

/******************  Bit definition for FLASH_CONTR register  ******************/
#define FLASH_CONTR_FCONTR_EN_Pos           (31U)
#define FLASH_CONTR_FCONTR_EN_Msk           (0x1U << FLASH_CONTR_FCONTR_EN_Pos)       /*!< 0x80000000 */
#define FLASH_CONTR_FCONTR_EN               FLASH_CONTR_FCONTR_EN_Msk                 /*!< Erase/Program protection status */

/******************  Bit definition for FLASH_DIVR register  ******************/
#define FLASH_DIVR_FDIV_Pos                 (0U)
#define FLASH_DIVR_FDIV_Msk                 (0x3U << FLASH_DIVR_FDIV_Pos)             /*!< 0x80000000 */
#define FLASH_DIVR_FDIV                     FLASH_DIVR_FDIV_Msk                       /*!< Erase/Program protection status */
#define FLASH_DIVR_FDIV_0                   (0x00000001)
#define FLASH_DIVR_FDIV_1                   (0x00000002)

#define FLASH_DIVR_FDIV_DIV2                (0x00000000)
#define FLASH_DIVR_FDIV_DIV3                (0x00000001)
#define FLASH_DIVR_FDIV_DIV4                (0x00000002)

/******************************************************************************/
/*                                                                            */
/*       General-purpose I/Os (GPIO) & Multiplex function I/Os (IOMUX)        */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for GPIO_CFGR register  *******************/
#define GPIO_CFGR_IOMC_Pos                  (0U)
#define GPIO_CFGR_IOMC_Msk                  (0xFFFFFFFFU << GPIO_CFGR_IOMC_Pos)     /*!< 0xFFFFFFFF */
#define GPIO_CFGR_IOMC                      GPIO_CFGR_IOMC_Msk                      /*!< GPIO x mode configuration */

/*!< IOMC0 configuration */
#define GPIO_CFGR_IOMC0_Pos                 (0U)
#define GPIO_CFGR_IOMC0_Msk                 (0x3U << GPIO_CFGR_IOMC0_Pos)           /*!< 0x00000003 */
#define GPIO_CFGR_IOMC0                     GPIO_CFGR_IOMC0_Msk                     /*!< IOMC0[1:0] bits (GPIO x mode configuration, pin 0) */
#define GPIO_CFGR_IOMC0_0                   (0x1U << GPIO_CFGR_IOMC0_Pos)           /*!< 0x00000001 */
#define GPIO_CFGR_IOMC0_1                   (0x2U << GPIO_CFGR_IOMC0_Pos)           /*!< 0x00000002 */

/*!< IOMC1 configuration */
#define GPIO_CFGR_IOMC1_Pos                 (2U)
#define GPIO_CFGR_IOMC1_Msk                 (0x3U << GPIO_CFGR_IOMC1_Pos)           /*!< 0x0000000C */
#define GPIO_CFGR_IOMC1                     GPIO_CFGR_IOMC1_Msk                     /*!< IOMC1[1:0] bits (GPIO x mode configuration, pin 1) */
#define GPIO_CFGR_IOMC1_0                   (0x1U << GPIO_CFGR_IOMC1_Pos)           /*!< 0x00000004 */
#define GPIO_CFGR_IOMC1_1                   (0x2U << GPIO_CFGR_IOMC1_Pos)           /*!< 0x00000008 */

/*!< IOMC2 configuration */
#define GPIO_CFGR_IOMC2_Pos                 (4U)
#define GPIO_CFGR_IOMC2_Msk                 (0x3U << GPIO_CFGR_IOMC2_Pos)           /*!< 0x00000030 */
#define GPIO_CFGR_IOMC2                     GPIO_CFGR_IOMC2_Msk                     /*!< IOMC2[1:0] bits (GPIO x mode configuration, pin 2) */
#define GPIO_CFGR_IOMC2_0                   (0x1U << GPIO_CFGR_IOMC2_Pos)           /*!< 0x00000010 */
#define GPIO_CFGR_IOMC2_1                   (0x2U << GPIO_CFGR_IOMC2_Pos)           /*!< 0x00000020 */

/*!< IOMC3 configuration */
#define GPIO_CFGR_IOMC3_Pos                 (6U)
#define GPIO_CFGR_IOMC3_Msk                 (0x3U << GPIO_CFGR_IOMC3_Pos)           /*!< 0x000000C0 */
#define GPIO_CFGR_IOMC3                     GPIO_CFGR_IOMC3_Msk                     /*!< IOMC3[1:0] bits (GPIO x mode configuration, pin 3) */
#define GPIO_CFGR_IOMC3_0                   (0x1U << GPIO_CFGR_IOMC3_Pos)           /*!< 0x00000040 */
#define GPIO_CFGR_IOMC3_1                   (0x2U << GPIO_CFGR_IOMC3_Pos)           /*!< 0x00000080 */

/*!< IOMC4 configuration */
#define GPIO_CFGR_IOMC4_Pos                 (8U)
#define GPIO_CFGR_IOMC4_Msk                 (0x3U << GPIO_CFGR_IOMC4_Pos)           /*!< 0x00000300 */
#define GPIO_CFGR_IOMC4                     GPIO_CFGR_IOMC4_Msk                     /*!< IOMC4[1:0] bits (GPIO x mode configuration, pin 4) */
#define GPIO_CFGR_IOMC4_0                   (0x1U << GPIO_CFGR_IOMC4_Pos)           /*!< 0x00000100 */
#define GPIO_CFGR_IOMC4_1                   (0x2U << GPIO_CFGR_IOMC4_Pos)           /*!< 0x00000200 */

/*!< IOMC5 configuration */
#define GPIO_CFGR_IOMC5_Pos                 (10U)
#define GPIO_CFGR_IOMC5_Msk                 (0x3U << GPIO_CFGR_IOMC5_Pos)           /*!< 0x00000C00 */
#define GPIO_CFGR_IOMC5                     GPIO_CFGR_IOMC5_Msk                     /*!< IOMC5[1:0] bits (GPIO x mode configuration, pin 5) */
#define GPIO_CFGR_IOMC5_0                   (0x1U << GPIO_CFGR_IOMC5_Pos)           /*!< 0x00000400 */
#define GPIO_CFGR_IOMC5_1                   (0x2U << GPIO_CFGR_IOMC5_Pos)           /*!< 0x00000800 */

/*!< IOMC6 configuration */
#define GPIO_CFGR_IOMC6_Pos                 (12U)
#define GPIO_CFGR_IOMC6_Msk                 (0x3U << GPIO_CFGR_IOMC6_Pos)           /*!< 0x00003000 */
#define GPIO_CFGR_IOMC6                     GPIO_CFGR_IOMC6_Msk                     /*!< IOMC6[1:0] bits (GPIO x mode configuration, pin 6) */
#define GPIO_CFGR_IOMC6_0                   (0x1U << GPIO_CFGR_IOMC6_Pos)           /*!< 0x00001000 */
#define GPIO_CFGR_IOMC6_1                   (0x2U << GPIO_CFGR_IOMC6_Pos)           /*!< 0x00002000 */

/*!< IOMC7 configuration */
#define GPIO_CFGR_IOMC7_Pos                 (14U)
#define GPIO_CFGR_IOMC7_Msk                 (0x3U << GPIO_CFGR_IOMC7_Pos)           /*!< 0x0000C000 */
#define GPIO_CFGR_IOMC7                     GPIO_CFGR_IOMC7_Msk                     /*!< IOMC7[1:0] bits (GPIO x mode configuration, pin 7) */
#define GPIO_CFGR_IOMC7_0                   (0x1U << GPIO_CFGR_IOMC7_Pos)           /*!< 0x00004000 */
#define GPIO_CFGR_IOMC7_1                   (0x2U << GPIO_CFGR_IOMC7_Pos)           /*!< 0x00008000 */

/*!< IOMC8 configuration */
#define GPIO_CFGR_IOMC8_Pos                 (16U)
#define GPIO_CFGR_IOMC8_Msk                 (0x3U << GPIO_CFGR_IOMC8_Pos)           /*!< 0x00030000 */
#define GPIO_CFGR_IOMC8                     GPIO_CFGR_IOMC8_Msk                     /*!< IOMC8[1:0] bits (GPIO x mode configuration, pin 8) */
#define GPIO_CFGR_IOMC8_0                   (0x1U << GPIO_CFGR_IOMC8_Pos)           /*!< 0x00010000 */
#define GPIO_CFGR_IOMC8_1                   (0x2U << GPIO_CFGR_IOMC8_Pos)           /*!< 0x00020000 */

/*!< IOMC9 configuration */
#define GPIO_CFGR_IOMC9_Pos                 (18U)
#define GPIO_CFGR_IOMC9_Msk                 (0x3U << GPIO_CFGR_IOMC9_Pos)           /*!< 0x000C0000 */
#define GPIO_CFGR_IOMC9                     GPIO_CFGR_IOMC9_Msk                     /*!< IOMC9[1:0] bits (GPIO x mode configuration, pin 9) */
#define GPIO_CFGR_IOMC9_0                   (0x1U << GPIO_CFGR_IOMC9_Pos)           /*!< 0x00040000 */
#define GPIO_CFGR_IOMC9_1                   (0x2U << GPIO_CFGR_IOMC9_Pos)           /*!< 0x00080000 */

/*!< IOMC10 configuration */
#define GPIO_CFGR_IOMC10_Pos                (20U)
#define GPIO_CFGR_IOMC10_Msk                (0x3U << GPIO_CFGR_IOMC10_Pos)          /*!< 0x00300000 */
#define GPIO_CFGR_IOMC10                    GPIO_CFGR_IOMC10_Msk                    /*!< IOMC10[1:0] bits (GPIO x mode configuration, pin 10) */
#define GPIO_CFGR_IOMC10_0                  (0x1U << GPIO_CFGR_IOMC10_Pos)          /*!< 0x00100000 */
#define GPIO_CFGR_IOMC10_1                  (0x2U << GPIO_CFGR_IOMC10_Pos)          /*!< 0x00200000 */

/*!< IOMC11 configuration */
#define GPIO_CFGR_IOMC11_Pos                (22U)
#define GPIO_CFGR_IOMC11_Msk                (0x3U << GPIO_CFGR_IOMC11_Pos)          /*!< 0x00C00000 */
#define GPIO_CFGR_IOMC11                    GPIO_CFGR_IOMC11_Msk                    /*!< IOMC11[1:0] bits (GPIO x mode configuration, pin 11) */
#define GPIO_CFGR_IOMC11_0                  (0x1U << GPIO_CFGR_IOMC11_Pos)          /*!< 0x00400000 */
#define GPIO_CFGR_IOMC11_1                  (0x2U << GPIO_CFGR_IOMC11_Pos)          /*!< 0x00800000 */

/*!< IOMC12 configuration */
#define GPIO_CFGR_IOMC12_Pos                (24U)
#define GPIO_CFGR_IOMC12_Msk                (0x3U << GPIO_CFGR_IOMC12_Pos)          /*!< 0x03000000 */
#define GPIO_CFGR_IOMC12                    GPIO_CFGR_IOMC12_Msk                    /*!< IOMC12[1:0] bits (GPIO x mode configuration, pin 12) */
#define GPIO_CFGR_IOMC12_0                  (0x1U << GPIO_CFGR_IOMC12_Pos)          /*!< 0x01000000 */
#define GPIO_CFGR_IOMC12_1                  (0x2U << GPIO_CFGR_IOMC12_Pos)          /*!< 0x02000000 */

/*!< IOMC13 configuration */
#define GPIO_CFGR_IOMC13_Pos                (26U)
#define GPIO_CFGR_IOMC13_Msk                (0x3U << GPIO_CFGR_IOMC13_Pos)          /*!< 0x0C000000 */
#define GPIO_CFGR_IOMC13                    GPIO_CFGR_IOMC13_Msk                    /*!< IOMC13[1:0] bits (GPIO x mode configuration, pin 13) */
#define GPIO_CFGR_IOMC13_0                  (0x1U << GPIO_CFGR_IOMC13_Pos)          /*!< 0x04000000 */
#define GPIO_CFGR_IOMC13_1                  (0x2U << GPIO_CFGR_IOMC13_Pos)          /*!< 0x08000000 */

/*!< IOMC14 configuration */
#define GPIO_CFGR_IOMC14_Pos                (28U)
#define GPIO_CFGR_IOMC14_Msk                (0x3U << GPIO_CFGR_IOMC14_Pos)          /*!< 0x30000000 */
#define GPIO_CFGR_IOMC14                    GPIO_CFGR_IOMC14_Msk                    /*!< IOMC14[1:0] bits (GPIO x mode configuration, pin 14) */
#define GPIO_CFGR_IOMC14_0                  (0x1U << GPIO_CFGR_IOMC14_Pos)          /*!< 0x10000000 */
#define GPIO_CFGR_IOMC14_1                  (0x2U << GPIO_CFGR_IOMC14_Pos)          /*!< 0x20000000 */

/*!< IOMC15 configuration */
#define GPIO_CFGR_IOMC15_Pos                (30U)
#define GPIO_CFGR_IOMC15_Msk                (0x3U << GPIO_CFGR_IOMC15_Pos)          /*!< 0xC0000000 */
#define GPIO_CFGR_IOMC15                    GPIO_CFGR_IOMC15_Msk                    /*!< IOMC15[1:0] bits (GPIO x mode configuration, pin 15) */
#define GPIO_CFGR_IOMC15_0                  (0x1U << GPIO_CFGR_IOMC15_Pos)          /*!< 0x40000000 */
#define GPIO_CFGR_IOMC15_1                  (0x2U << GPIO_CFGR_IOMC15_Pos)          /*!< 0x80000000 */

/******************  Bit definition for GPIO_OMODE register  ******************/
#define GPIO_OMODE_OM0_Pos                  (0U)
#define GPIO_OMODE_OM0_Msk                  (0x1U << GPIO_OMODE_OM0_Pos)            /*!< 0x00000001 */
#define GPIO_OMODE_OM0                      GPIO_OMODE_OM0_Msk                      /*!< GPIO x output mode configuration, pin 0 */
#define GPIO_OMODE_OM1_Pos                  (1U)
#define GPIO_OMODE_OM1_Msk                  (0x3U << GPIO_OMODE_OM1_Pos)            /*!< 0x00000002 */
#define GPIO_OMODE_OM1                      GPIO_OMODE_OM1_Msk                      /*!< GPIO x output mode configuration, pin 1 */
#define GPIO_OMODE_OM2_Pos                  (2U)
#define GPIO_OMODE_OM2_Msk                  (0x3U << GPIO_OMODE_OM2_Pos)            /*!< 0x00000004 */
#define GPIO_OMODE_OM2                      GPIO_OMODE_OM2_Msk                      /*!< GPIO x output mode configuration, pin 2 */
#define GPIO_OMODE_OM3_Pos                  (3U)
#define GPIO_OMODE_OM3_Msk                  (0x3U << GPIO_OMODE_OM3_Pos)            /*!< 0x00000008 */
#define GPIO_OMODE_OM3                      GPIO_OMODE_OM3_Msk                      /*!< GPIO x output mode configuration, pin 3 */
#define GPIO_OMODE_OM4_Pos                  (4U)
#define GPIO_OMODE_OM4_Msk                  (0x3U << GPIO_OMODE_OM4_Pos)            /*!< 0x00000010 */
#define GPIO_OMODE_OM4                      GPIO_OMODE_OM4_Msk                      /*!< GPIO x output mode configuration, pin 4 */
#define GPIO_OMODE_OM5_Pos                  (5U)
#define GPIO_OMODE_OM5_Msk                  (0x3U << GPIO_OMODE_OM5_Pos)            /*!< 0x00000020 */
#define GPIO_OMODE_OM5                      GPIO_OMODE_OM5_Msk                      /*!< GPIO x output mode configuration, pin 5 */
#define GPIO_OMODE_OM6_Pos                  (6U)
#define GPIO_OMODE_OM6_Msk                  (0x3U << GPIO_OMODE_OM6_Pos)            /*!< 0x00000040 */
#define GPIO_OMODE_OM6                      GPIO_OMODE_OM6_Msk                      /*!< GPIO x output mode configuration, pin 6 */
#define GPIO_OMODE_OM7_Pos                  (7U)
#define GPIO_OMODE_OM7_Msk                  (0x3U << GPIO_OMODE_OM7_Pos)            /*!< 0x00000080 */
#define GPIO_OMODE_OM7                      GPIO_OMODE_OM7_Msk                      /*!< GPIO x output mode configuration, pin 7 */
#define GPIO_OMODE_OM8_Pos                  (8U)
#define GPIO_OMODE_OM8_Msk                  (0x1U << GPIO_OMODE_OM8_Pos)            /*!< 0x00000100 */
#define GPIO_OMODE_OM8                      GPIO_OMODE_OM8_Msk                      /*!< GPIO x output mode configuration, pin 8 */
#define GPIO_OMODE_OM9_Pos                  (9U)
#define GPIO_OMODE_OM9_Msk                  (0x1U << GPIO_OMODE_OM9_Pos)            /*!< 0x00000200 */
#define GPIO_OMODE_OM9                      GPIO_OMODE_OM9_Msk                      /*!< GPIO x output mode configuration, pin 9 */
#define GPIO_OMODE_OM10_Pos                 (10U)
#define GPIO_OMODE_OM10_Msk                 (0x1U << GPIO_OMODE_OM10_Pos)           /*!< 0x00000400 */
#define GPIO_OMODE_OM10                     GPIO_OMODE_OM10_Msk                     /*!< GPIO x output mode configuration, pin 10 */
#define GPIO_OMODE_OM11_Pos                 (11U)
#define GPIO_OMODE_OM11_Msk                 (0x1U << GPIO_OMODE_OM11_Pos)           /*!< 0x00000800 */
#define GPIO_OMODE_OM11                     GPIO_OMODE_OM11_Msk                     /*!< GPIO x output mode configuration, pin 11 */
#define GPIO_OMODE_OM12_Pos                 (12U)
#define GPIO_OMODE_OM12_Msk                 (0x1U << GPIO_OMODE_OM12_Pos)           /*!< 0x00001000 */
#define GPIO_OMODE_OM12                     GPIO_OMODE_OM12_Msk                     /*!< GPIO x output mode configuration, pin 12 */
#define GPIO_OMODE_OM13_Pos                 (13U)
#define GPIO_OMODE_OM13_Msk                 (0x1U << GPIO_OMODE_OM13_Pos)           /*!< 0x00002000 */
#define GPIO_OMODE_OM13                     GPIO_OMODE_OM13_Msk                     /*!< GPIO x output mode configuration, pin 13 */
#define GPIO_OMODE_OM14_Pos                 (14U)
#define GPIO_OMODE_OM14_Msk                 (0x1U << GPIO_OMODE_OM14_Pos)           /*!< 0x00004000 */
#define GPIO_OMODE_OM14                     GPIO_OMODE_OM14_Msk                     /*!< GPIO x output mode configuration, pin 14 */
#define GPIO_OMODE_OM15_Pos                 (15U)
#define GPIO_OMODE_OM15_Msk                 (0x1U << GPIO_OMODE_OM15_Pos)           /*!< 0x00008000 */
#define GPIO_OMODE_OM15                     GPIO_OMODE_OM15_Msk                     /*!< GPIO x output mode configuration, pin 15 */

/*!<***************  Bit definition for GPIO_ODRVR register  ******************/
#define GPIO_ODRVR_ODRV_Pos                 (0U)
#define GPIO_ODRVR_ODRV_Msk                 (0xFFFFFFFFU << GPIO_ODRVR_ODRV_Pos)    /*!< 0xFFFFFFFF */
#define GPIO_ODRVR_ODRV                     GPIO_ODRVR_ODRV_Msk                     /*!< GPIO x drive capability */

/*!< ODRV0 configuration */
#define GPIO_ODRVR_ODRV0_Pos                (0U)
#define GPIO_ODRVR_ODRV0_Msk                (0x3U << GPIO_ODRVR_ODRV0_Pos)          /*!< 0x00000003 */
#define GPIO_ODRVR_ODRV0                    GPIO_ODRVR_ODRV0_Msk                    /*!< ODRV0[1:0] bits (GPIO x drive capability, pin 0) */
#define GPIO_ODRVR_ODRV0_0                  (0x1U << GPIO_ODRVR_ODRV0_Pos)          /*!< 0x00000001 */
#define GPIO_ODRVR_ODRV0_1                  (0x2U << GPIO_ODRVR_ODRV0_Pos)          /*!< 0x00000002 */

/*!< ODRV1 configuration */
#define GPIO_ODRVR_ODRV1_Pos                (2U)
#define GPIO_ODRVR_ODRV1_Msk                (0x3U << GPIO_ODRVR_ODRV1_Pos)          /*!< 0x0000000C */
#define GPIO_ODRVR_ODRV1                    GPIO_ODRVR_ODRV1_Msk                    /*!< ODRV1[1:0] bits (GPIO x drive capability, pin 1) */
#define GPIO_ODRVR_ODRV1_0                  (0x1U << GPIO_ODRVR_ODRV1_Pos)          /*!< 0x00000004 */
#define GPIO_ODRVR_ODRV1_1                  (0x2U << GPIO_ODRVR_ODRV1_Pos)          /*!< 0x00000008 */

/*!< ODRV2 configuration */
#define GPIO_ODRVR_ODRV2_Pos                (4U)
#define GPIO_ODRVR_ODRV2_Msk                (0x3U << GPIO_ODRVR_ODRV2_Pos)          /*!< 0x00000030 */
#define GPIO_ODRVR_ODRV2                    GPIO_ODRVR_ODRV2_Msk                    /*!< ODRV2[1:0] bits (GPIO x drive capability, pin 2) */
#define GPIO_ODRVR_ODRV2_0                  (0x1U << GPIO_ODRVR_ODRV2_Pos)          /*!< 0x00000010 */
#define GPIO_ODRVR_ODRV2_1                  (0x2U << GPIO_ODRVR_ODRV2_Pos)          /*!< 0x00000020 */

/*!< ODRV3 configuration */
#define GPIO_ODRVR_ODRV3_Pos                (6U)
#define GPIO_ODRVR_ODRV3_Msk                (0x3U << GPIO_ODRVR_ODRV3_Pos)          /*!< 0x000000C0 */
#define GPIO_ODRVR_ODRV3                    GPIO_ODRVR_ODRV3_Msk                    /*!< ODRV3[1:0] bits (GPIO x drive capability, pin 3) */
#define GPIO_ODRVR_ODRV3_0                  (0x1U << GPIO_ODRVR_ODRV3_Pos)          /*!< 0x00000040 */
#define GPIO_ODRVR_ODRV3_1                  (0x2U << GPIO_ODRVR_ODRV3_Pos)          /*!< 0x00000080 */

/*!< ODRV4 configuration */
#define GPIO_ODRVR_ODRV4_Pos                (8U)
#define GPIO_ODRVR_ODRV4_Msk                (0x3U << GPIO_ODRVR_ODRV4_Pos)          /*!< 0x00000300 */
#define GPIO_ODRVR_ODRV4                    GPIO_ODRVR_ODRV4_Msk                    /*!< ODRV4[1:0] bits (GPIO x drive capability, pin 4) */
#define GPIO_ODRVR_ODRV4_0                  (0x1U << GPIO_ODRVR_ODRV4_Pos)          /*!< 0x00000100 */
#define GPIO_ODRVR_ODRV4_1                  (0x2U << GPIO_ODRVR_ODRV4_Pos)          /*!< 0x00000200 */

/*!< ODRV5 configuration */
#define GPIO_ODRVR_ODRV5_Pos                (10U)
#define GPIO_ODRVR_ODRV5_Msk                (0x3U << GPIO_ODRVR_ODRV5_Pos)          /*!< 0x00000C00 */
#define GPIO_ODRVR_ODRV5                    GPIO_ODRVR_ODRV5_Msk                    /*!< ODRV5[1:0] bits (GPIO x drive capability, pin 5) */
#define GPIO_ODRVR_ODRV5_0                  (0x1U << GPIO_ODRVR_ODRV5_Pos)          /*!< 0x00000400 */
#define GPIO_ODRVR_ODRV5_1                  (0x2U << GPIO_ODRVR_ODRV5_Pos)          /*!< 0x00000800 */

/*!< ODRV6 configuration */
#define GPIO_ODRVR_ODRV6_Pos                (12U)
#define GPIO_ODRVR_ODRV6_Msk                (0x3U << GPIO_ODRVR_ODRV6_Pos)          /*!< 0x00003000 */
#define GPIO_ODRVR_ODRV6                    GPIO_ODRVR_ODRV6_Msk                    /*!< ODRV6[1:0] bits (GPIO x drive capability, pin 6) */
#define GPIO_ODRVR_ODRV6_0                  (0x1U << GPIO_ODRVR_ODRV6_Pos)          /*!< 0x00001000 */
#define GPIO_ODRVR_ODRV6_1                  (0x2U << GPIO_ODRVR_ODRV6_Pos)          /*!< 0x00002000 */

/*!< ODRV7 configuration */
#define GPIO_ODRVR_ODRV7_Pos                (14U)
#define GPIO_ODRVR_ODRV7_Msk                (0x3U << GPIO_ODRVR_ODRV7_Pos)          /*!< 0x0000C000 */
#define GPIO_ODRVR_ODRV7                    GPIO_ODRVR_ODRV7_Msk                    /*!< ODRV7[1:0] bits (GPIO x drive capability, pin 7) */
#define GPIO_ODRVR_ODRV7_0                  (0x1U << GPIO_ODRVR_ODRV7_Pos)          /*!< 0x00004000 */
#define GPIO_ODRVR_ODRV7_1                  (0x2U << GPIO_ODRVR_ODRV7_Pos)          /*!< 0x00008000 */

/*!< ODRV8 configuration */
#define GPIO_ODRVR_ODRV8_Pos                (16U)
#define GPIO_ODRVR_ODRV8_Msk                (0x3U << GPIO_ODRVR_ODRV8_Pos)          /*!< 0x00030000 */
#define GPIO_ODRVR_ODRV8                    GPIO_ODRVR_ODRV8_Msk                    /*!< ODRV8[1:0] bits (GPIO x drive capability, pin 8) */
#define GPIO_ODRVR_ODRV8_0                  (0x1U << GPIO_ODRVR_ODRV8_Pos)          /*!< 0x00010000 */
#define GPIO_ODRVR_ODRV8_1                  (0x2U << GPIO_ODRVR_ODRV8_Pos)          /*!< 0x00020000 */

/*!< ODRV9 configuration */
#define GPIO_ODRVR_ODRV9_Pos                (18U)
#define GPIO_ODRVR_ODRV9_Msk                (0x3U << GPIO_ODRVR_ODRV9_Pos)          /*!< 0x000C0000 */
#define GPIO_ODRVR_ODRV9                    GPIO_ODRVR_ODRV9_Msk                    /*!< ODRV9[1:0] bits (GPIO x drive capability, pin 9) */
#define GPIO_ODRVR_ODRV9_0                  (0x1U << GPIO_ODRVR_ODRV9_Pos)          /*!< 0x00040000 */
#define GPIO_ODRVR_ODRV9_1                  (0x2U << GPIO_ODRVR_ODRV9_Pos)          /*!< 0x00080000 */

/*!< ODRV10 configuration */
#define GPIO_ODRVR_ODRV10_Pos               (20U)
#define GPIO_ODRVR_ODRV10_Msk               (0x3U << GPIO_ODRVR_ODRV10_Pos)         /*!< 0x00300000 */
#define GPIO_ODRVR_ODRV10                   GPIO_ODRVR_ODRV10_Msk                   /*!< ODRV10[1:0] bits (GPIO x drive capability, pin 10) */
#define GPIO_ODRVR_ODRV10_0                 (0x1U << GPIO_ODRVR_ODRV10_Pos)         /*!< 0x00100000 */
#define GPIO_ODRVR_ODRV10_1                 (0x2U << GPIO_ODRVR_ODRV10_Pos)         /*!< 0x00200000 */

/*!< ODRV11 configuration */
#define GPIO_ODRVR_ODRV11_Pos               (22U)
#define GPIO_ODRVR_ODRV11_Msk               (0x3U << GPIO_ODRVR_ODRV11_Pos)         /*!< 0x00C00000 */
#define GPIO_ODRVR_ODRV11                   GPIO_ODRVR_ODRV11_Msk                   /*!< ODRV11[1:0] bits (GPIO x drive capability, pin 11) */
#define GPIO_ODRVR_ODRV11_0                 (0x1U << GPIO_ODRVR_ODRV11_Pos)         /*!< 0x00400000 */
#define GPIO_ODRVR_ODRV11_1                 (0x2U << GPIO_ODRVR_ODRV11_Pos)         /*!< 0x00800000 */

/*!< ODRV12 configuration */
#define GPIO_ODRVR_ODRV12_Pos               (24U)
#define GPIO_ODRVR_ODRV12_Msk               (0x3U << GPIO_ODRVR_ODRV12_Pos)         /*!< 0x03000000 */
#define GPIO_ODRVR_ODRV12                   GPIO_ODRVR_ODRV12_Msk                   /*!< ODRV12[1:0] bits (GPIO x drive capability, pin 12) */
#define GPIO_ODRVR_ODRV12_0                 (0x1U << GPIO_ODRVR_ODRV12_Pos)         /*!< 0x01000000 */
#define GPIO_ODRVR_ODRV12_1                 (0x2U << GPIO_ODRVR_ODRV12_Pos)         /*!< 0x02000000 */

/*!< ODRV13 configuration */
#define GPIO_ODRVR_ODRV13_Pos               (26U)
#define GPIO_ODRVR_ODRV13_Msk               (0x3U << GPIO_ODRVR_ODRV13_Pos)         /*!< 0x0C000000 */
#define GPIO_ODRVR_ODRV13                   GPIO_ODRVR_ODRV13_Msk                   /*!< ODRV13[1:0] bits (GPIO x drive capability, pin 13) */
#define GPIO_ODRVR_ODRV13_0                 (0x1U << GPIO_ODRVR_ODRV13_Pos)         /*!< 0x04000000 */
#define GPIO_ODRVR_ODRV13_1                 (0x2U << GPIO_ODRVR_ODRV13_Pos)         /*!< 0x08000000 */

/*!< ODRV14 configuration */
#define GPIO_ODRVR_ODRV14_Pos               (28U)
#define GPIO_ODRVR_ODRV14_Msk               (0x3U << GPIO_ODRVR_ODRV14_Pos)         /*!< 0x30000000 */
#define GPIO_ODRVR_ODRV14                   GPIO_ODRVR_ODRV14_Msk                   /*!< ODRV14[1:0] bits (GPIO x drive capability, pin 14) */
#define GPIO_ODRVR_ODRV14_0                 (0x1U << GPIO_ODRVR_ODRV14_Pos)         /*!< 0x10000000 */
#define GPIO_ODRVR_ODRV14_1                 (0x2U << GPIO_ODRVR_ODRV14_Pos)         /*!< 0x20000000 */

/*!< ODRV15 configuration */
#define GPIO_ODRVR_ODRV15_Pos               (30U)
#define GPIO_ODRVR_ODRV15_Msk               (0x3U << GPIO_ODRVR_ODRV15_Pos)         /*!< 0xC0000000 */
#define GPIO_ODRVR_ODRV15                   GPIO_ODRVR_ODRV15_Msk                   /*!< ODRV15[1:0] bits (GPIO x drive capability, pin 15) */
#define GPIO_ODRVR_ODRV15_0                 (0x1U << GPIO_ODRVR_ODRV15_Pos)         /*!< 0x40000000 */
#define GPIO_ODRVR_ODRV15_1                 (0x2U << GPIO_ODRVR_ODRV15_Pos)         /*!< 0x80000000 */

/*!<***************  Bit definition for GPIO_PULL register  *******************/
#define GPIO_PULL_PULL_Pos                  (0U)
#define GPIO_PULL_PULL_Msk                  (0xFFFFFFFFU << GPIO_PULL_PULL_Pos)     /*!< 0xFFFFFFFF */
#define GPIO_PULL_PULL                      GPIO_PULL_PULL_Msk                      /*!< GPIO x pull-up/pull-down configuration */

/*!< PULL0 configuration */
#define GPIO_PULL_PULL0_Pos                 (0U)
#define GPIO_PULL_PULL0_Msk                 (0x3U << GPIO_PULL_PULL0_Pos)           /*!< 0x00000003 */
#define GPIO_PULL_PULL0                     GPIO_PULL_PULL0_Msk                     /*!< PULL0[1:0] bits (GPIO x pull-up/pull-down configuration, pin 0) */
#define GPIO_PULL_PULL0_0                   (0x1U << GPIO_PULL_PULL0_Pos)           /*!< 0x00000001 */
#define GPIO_PULL_PULL0_1                   (0x2U << GPIO_PULL_PULL0_Pos)           /*!< 0x00000002 */

/*!< PULL1 configuration */
#define GPIO_PULL_PULL1_Pos                 (2U)
#define GPIO_PULL_PULL1_Msk                 (0x3U << GPIO_PULL_PULL1_Pos)           /*!< 0x0000000C */
#define GPIO_PULL_PULL1                     GPIO_PULL_PULL1_Msk                     /*!< PULL1[1:0] bits (GPIO x pull-up/pull-down configuration, pin 1) */
#define GPIO_PULL_PULL1_0                   (0x1U << GPIO_PULL_PULL1_Pos)           /*!< 0x00000004 */
#define GPIO_PULL_PULL1_1                   (0x2U << GPIO_PULL_PULL1_Pos)           /*!< 0x00000008 */

/*!< PULL2 configuration */
#define GPIO_PULL_PULL2_Pos                 (4U)
#define GPIO_PULL_PULL2_Msk                 (0x3U << GPIO_PULL_PULL2_Pos)           /*!< 0x00000030 */
#define GPIO_PULL_PULL2                     GPIO_PULL_PULL2_Msk                     /*!< PULL2[1:0] bits (GPIO x pull-up/pull-down configuration, pin 2) */
#define GPIO_PULL_PULL2_0                   (0x1U << GPIO_PULL_PULL2_Pos)           /*!< 0x00000010 */
#define GPIO_PULL_PULL2_1                   (0x2U << GPIO_PULL_PULL2_Pos)           /*!< 0x00000020 */

/*!< PULL3 configuration */
#define GPIO_PULL_PULL3_Pos                 (6U)
#define GPIO_PULL_PULL3_Msk                 (0x3U << GPIO_PULL_PULL3_Pos)           /*!< 0x000000C0 */
#define GPIO_PULL_PULL3                     GPIO_PULL_PULL3_Msk                     /*!< PULL3[1:0] bits (GPIO x pull-up/pull-down configuration, pin 3) */
#define GPIO_PULL_PULL3_0                   (0x1U << GPIO_PULL_PULL3_Pos)           /*!< 0x00000040 */
#define GPIO_PULL_PULL3_1                   (0x2U << GPIO_PULL_PULL3_Pos)           /*!< 0x00000080 */

/*!< PULL4 configuration */
#define GPIO_PULL_PULL4_Pos                 (8U)
#define GPIO_PULL_PULL4_Msk                 (0x3U << GPIO_PULL_PULL4_Pos)           /*!< 0x00000300 */
#define GPIO_PULL_PULL4                     GPIO_PULL_PULL4_Msk                     /*!< PULL4[1:0] bits (GPIO x pull-up/pull-down configuration, pin 4) */
#define GPIO_PULL_PULL4_0                   (0x1U << GPIO_PULL_PULL4_Pos)           /*!< 0x00000100 */
#define GPIO_PULL_PULL4_1                   (0x2U << GPIO_PULL_PULL4_Pos)           /*!< 0x00000200 */

/*!< PULL5 configuration */
#define GPIO_PULL_PULL5_Pos                 (10U)
#define GPIO_PULL_PULL5_Msk                 (0x3U << GPIO_PULL_PULL5_Pos)           /*!< 0x00000C00 */
#define GPIO_PULL_PULL5                     GPIO_PULL_PULL5_Msk                     /*!< PULL5[1:0] bits (GPIO x pull-up/pull-down configuration, pin 5) */
#define GPIO_PULL_PULL5_0                   (0x1U << GPIO_PULL_PULL5_Pos)           /*!< 0x00000400 */
#define GPIO_PULL_PULL5_1                   (0x2U << GPIO_PULL_PULL5_Pos)           /*!< 0x00000800 */

/*!< PULL6 configuration */
#define GPIO_PULL_PULL6_Pos                 (12U)
#define GPIO_PULL_PULL6_Msk                 (0x3U << GPIO_PULL_PULL6_Pos)           /*!< 0x00003000 */
#define GPIO_PULL_PULL6                     GPIO_PULL_PULL6_Msk                     /*!< PULL6[1:0] bits (GPIO x pull-up/pull-down configuration, pin 6) */
#define GPIO_PULL_PULL6_0                   (0x1U << GPIO_PULL_PULL6_Pos)           /*!< 0x00001000 */
#define GPIO_PULL_PULL6_1                   (0x2U << GPIO_PULL_PULL6_Pos)           /*!< 0x00002000 */

/*!< PULL7 configuration */
#define GPIO_PULL_PULL7_Pos                 (14U)
#define GPIO_PULL_PULL7_Msk                 (0x3U << GPIO_PULL_PULL7_Pos)           /*!< 0x0000C000 */
#define GPIO_PULL_PULL7                     GPIO_PULL_PULL7_Msk                     /*!< PULL7[1:0] bits (GPIO x pull-up/pull-down configuration, pin 7) */
#define GPIO_PULL_PULL7_0                   (0x1U << GPIO_PULL_PULL7_Pos)           /*!< 0x00004000 */
#define GPIO_PULL_PULL7_1                   (0x2U << GPIO_PULL_PULL7_Pos)           /*!< 0x00008000 */

/*!< PULL8 configuration */
#define GPIO_PULL_PULL8_Pos                 (16U)
#define GPIO_PULL_PULL8_Msk                 (0x3U << GPIO_PULL_PULL8_Pos)           /*!< 0x00030000 */
#define GPIO_PULL_PULL8                     GPIO_PULL_PULL8_Msk                     /*!< PULL8[1:0] bits (GPIO x pull-up/pull-down configuration, pin 8) */
#define GPIO_PULL_PULL8_0                   (0x1U << GPIO_PULL_PULL8_Pos)           /*!< 0x00010000 */
#define GPIO_PULL_PULL8_1                   (0x2U << GPIO_PULL_PULL8_Pos)           /*!< 0x00020000 */

/*!< PULL9 configuration */
#define GPIO_PULL_PULL9_Pos                 (18U)
#define GPIO_PULL_PULL9_Msk                 (0x3U << GPIO_PULL_PULL9_Pos)           /*!< 0x000C0000 */
#define GPIO_PULL_PULL9                     GPIO_PULL_PULL9_Msk                     /*!< PULL9[1:0] bits (GPIO x pull-up/pull-down configuration, pin 9) */
#define GPIO_PULL_PULL9_0                   (0x1U << GPIO_PULL_PULL9_Pos)           /*!< 0x00040000 */
#define GPIO_PULL_PULL9_1                   (0x2U << GPIO_PULL_PULL9_Pos)           /*!< 0x00080000 */

/*!< PULL10 configuration */
#define GPIO_PULL_PULL10_Pos                (20U)
#define GPIO_PULL_PULL10_Msk                (0x3U << GPIO_PULL_PULL10_Pos)          /*!< 0x00300000 */
#define GPIO_PULL_PULL10                    GPIO_PULL_PULL10_Msk                    /*!< PULL10[1:0] bits (GPIO x pull-up/pull-down configuration, pin 10) */
#define GPIO_PULL_PULL10_0                  (0x1U << GPIO_PULL_PULL10_Pos)          /*!< 0x00100000 */
#define GPIO_PULL_PULL10_1                  (0x2U << GPIO_PULL_PULL10_Pos)          /*!< 0x00200000 */

/*!< PULL11 configuration */
#define GPIO_PULL_PULL11_Pos                (22U)
#define GPIO_PULL_PULL11_Msk                (0x3U << GPIO_PULL_PULL11_Pos)          /*!< 0x00C00000 */
#define GPIO_PULL_PULL11                    GPIO_PULL_PULL11_Msk                    /*!< PULL11[1:0] bits (GPIO x pull-up/pull-down configuration, pin 11) */
#define GPIO_PULL_PULL11_0                  (0x1U << GPIO_PULL_PULL11_Pos)          /*!< 0x00400000 */
#define GPIO_PULL_PULL11_1                  (0x2U << GPIO_PULL_PULL11_Pos)          /*!< 0x00800000 */

/*!< PULL12 configuration */
#define GPIO_PULL_PULL12_Pos                (24U)
#define GPIO_PULL_PULL12_Msk                (0x3U << GPIO_PULL_PULL12_Pos)          /*!< 0x03000000 */
#define GPIO_PULL_PULL12                    GPIO_PULL_PULL12_Msk                    /*!< PULL12[1:0] bits (GPIO x pull-up/pull-down configuration, pin 12) */
#define GPIO_PULL_PULL12_0                  (0x1U << GPIO_PULL_PULL12_Pos)          /*!< 0x01000000 */
#define GPIO_PULL_PULL12_1                  (0x2U << GPIO_PULL_PULL12_Pos)          /*!< 0x02000000 */

/*!< PULL13 configuration */
#define GPIO_PULL_PULL13_Pos                (26U)
#define GPIO_PULL_PULL13_Msk                (0x3U << GPIO_PULL_PULL13_Pos)          /*!< 0x0C000000 */
#define GPIO_PULL_PULL13                    GPIO_PULL_PULL13_Msk                    /*!< PULL13[1:0] bits (GPIO x pull-up/pull-down configuration, pin 13) */
#define GPIO_PULL_PULL13_0                  (0x1U << GPIO_PULL_PULL13_Pos)          /*!< 0x04000000 */
#define GPIO_PULL_PULL13_1                  (0x2U << GPIO_PULL_PULL13_Pos)          /*!< 0x08000000 */

/*!< PULL14 configuration */
#define GPIO_PULL_PULL14_Pos                (28U)
#define GPIO_PULL_PULL14_Msk                (0x3U << GPIO_PULL_PULL14_Pos)          /*!< 0x30000000 */
#define GPIO_PULL_PULL14                    GPIO_PULL_PULL14_Msk                    /*!< PULL14[1:0] bits (GPIO x pull-up/pull-down configuration, pin 14) */
#define GPIO_PULL_PULL14_0                  (0x1U << GPIO_PULL_PULL14_Pos)          /*!< 0x10000000 */
#define GPIO_PULL_PULL14_1                  (0x2U << GPIO_PULL_PULL14_Pos)          /*!< 0x20000000 */

/*!< PULL15 configuration */
#define GPIO_PULL_PULL15_Pos                (30U)
#define GPIO_PULL_PULL15_Msk                (0x3U << GPIO_PULL_PULL15_Pos)          /*!< 0xC0000000 */
#define GPIO_PULL_PULL15                    GPIO_PULL_PULL15_Msk                    /*!< PULL15[1:0] bits (GPIO x pull-up/pull-down configuration, pin 15) */
#define GPIO_PULL_PULL15_0                  (0x1U << GPIO_PULL_PULL15_Pos)          /*!< 0x40000000 */
#define GPIO_PULL_PULL15_1                  (0x2U << GPIO_PULL_PULL15_Pos)          /*!< 0x80000000 */

/*!<****************  Bit definition for GPIO_IDT register  *******************/
#define GPIO_IDT_IDT0_Pos                   (0U)
#define GPIO_IDT_IDT0_Msk                   (0x1U << GPIO_IDT_IDT0_Pos)             /*!< 0x00000001 */
#define GPIO_IDT_IDT0                       GPIO_IDT_IDT0_Msk                       /*!< GPIO x input data, pin 0 */
#define GPIO_IDT_IDT1_Pos                   (1U)
#define GPIO_IDT_IDT1_Msk                   (0x1U << GPIO_IDT_IDT1_Pos)             /*!< 0x00000002 */
#define GPIO_IDT_IDT1                       GPIO_IDT_IDT1_Msk                       /*!< GPIO x input data, pin 1 */
#define GPIO_IDT_IDT2_Pos                   (2U)
#define GPIO_IDT_IDT2_Msk                   (0x1U << GPIO_IDT_IDT2_Pos)             /*!< 0x00000004 */
#define GPIO_IDT_IDT2                       GPIO_IDT_IDT2_Msk                       /*!< GPIO x input data, pin 2 */
#define GPIO_IDT_IDT3_Pos                   (3U)
#define GPIO_IDT_IDT3_Msk                   (0x1U << GPIO_IDT_IDT3_Pos)             /*!< 0x00000008 */
#define GPIO_IDT_IDT3                       GPIO_IDT_IDT3_Msk                       /*!< GPIO x input data, pin 3 */
#define GPIO_IDT_IDT4_Pos                   (4U)
#define GPIO_IDT_IDT4_Msk                   (0x1U << GPIO_IDT_IDT4_Pos)             /*!< 0x00000010 */
#define GPIO_IDT_IDT4                       GPIO_IDT_IDT4_Msk                       /*!< GPIO x input data, pin 4 */
#define GPIO_IDT_IDT5_Pos                   (5U)
#define GPIO_IDT_IDT5_Msk                   (0x1U << GPIO_IDT_IDT5_Pos)             /*!< 0x00000020 */
#define GPIO_IDT_IDT5                       GPIO_IDT_IDT5_Msk                       /*!< GPIO x input data, pin 5 */
#define GPIO_IDT_IDT6_Pos                   (6U)
#define GPIO_IDT_IDT6_Msk                   (0x1U << GPIO_IDT_IDT6_Pos)             /*!< 0x00000040 */
#define GPIO_IDT_IDT6                       GPIO_IDT_IDT6_Msk                       /*!< GPIO x input data, pin 6 */
#define GPIO_IDT_IDT7_Pos                   (7U)
#define GPIO_IDT_IDT7_Msk                   (0x1U << GPIO_IDT_IDT7_Pos)             /*!< 0x00000080 */
#define GPIO_IDT_IDT7                       GPIO_IDT_IDT7_Msk                       /*!< GPIO x input data, pin 7 */
#define GPIO_IDT_IDT8_Pos                   (8U)
#define GPIO_IDT_IDT8_Msk                   (0x1U << GPIO_IDT_IDT8_Pos)             /*!< 0x00000100 */
#define GPIO_IDT_IDT8                       GPIO_IDT_IDT8_Msk                       /*!< GPIO x input data, pin 8 */
#define GPIO_IDT_IDT9_Pos                   (9U)
#define GPIO_IDT_IDT9_Msk                   (0x1U << GPIO_IDT_IDT9_Pos)             /*!< 0x00000200 */
#define GPIO_IDT_IDT9                       GPIO_IDT_IDT9_Msk                       /*!< GPIO x input data, pin 9 */
#define GPIO_IDT_IDT10_Pos                  (10U)
#define GPIO_IDT_IDT10_Msk                  (0x1U << GPIO_IDT_IDT10_Pos)            /*!< 0x00000400 */
#define GPIO_IDT_IDT10                      GPIO_IDT_IDT10_Msk                      /*!< GPIO x input data, pin 10 */
#define GPIO_IDT_IDT11_Pos                  (11U)
#define GPIO_IDT_IDT11_Msk                  (0x1U << GPIO_IDT_IDT11_Pos)            /*!< 0x00000800 */
#define GPIO_IDT_IDT11                      GPIO_IDT_IDT11_Msk                      /*!< GPIO x input data, pin 11 */
#define GPIO_IDT_IDT12_Pos                  (12U)
#define GPIO_IDT_IDT12_Msk                  (0x1U << GPIO_IDT_IDT12_Pos)            /*!< 0x00001000 */
#define GPIO_IDT_IDT12                      GPIO_IDT_IDT12_Msk                      /*!< GPIO x input data, pin 12 */
#define GPIO_IDT_IDT13_Pos                  (13U)
#define GPIO_IDT_IDT13_Msk                  (0x1U << GPIO_IDT_IDT13_Pos)            /*!< 0x00002000 */
#define GPIO_IDT_IDT13                      GPIO_IDT_IDT13_Msk                      /*!< GPIO x input data, pin 13 */
#define GPIO_IDT_IDT14_Pos                  (14U)
#define GPIO_IDT_IDT14_Msk                  (0x1U << GPIO_IDT_IDT14_Pos)            /*!< 0x00004000 */
#define GPIO_IDT_IDT14                      GPIO_IDT_IDT14_Msk                      /*!< GPIO x input data, pin 14 */
#define GPIO_IDT_IDT15_Pos                  (15U)
#define GPIO_IDT_IDT15_Msk                  (0x1U << GPIO_IDT_IDT15_Pos)            /*!< 0x00008000 */
#define GPIO_IDT_IDT15                      GPIO_IDT_IDT15_Msk                      /*!< GPIO x input data, pin 15 */

/*******************  Bit definition for GPIO_ODT register  *******************/
#define GPIO_ODT_ODT0_Pos                   (0U)
#define GPIO_ODT_ODT0_Msk                   (0x1U << GPIO_ODT_ODT0_Pos)             /*!< 0x00000001 */
#define GPIO_ODT_ODT0                       GPIO_ODT_ODT0_Msk                       /*!< GPIO x output data, pin 0 */
#define GPIO_ODT_ODT1_Pos                   (1U)
#define GPIO_ODT_ODT1_Msk                   (0x1U << GPIO_ODT_ODT1_Pos)             /*!< 0x00000002 */
#define GPIO_ODT_ODT1                       GPIO_ODT_ODT1_Msk                       /*!< GPIO x output data, pin 1 */
#define GPIO_ODT_ODT2_Pos                   (2U)
#define GPIO_ODT_ODT2_Msk                   (0x1U << GPIO_ODT_ODT2_Pos)             /*!< 0x00000004 */
#define GPIO_ODT_ODT2                       GPIO_ODT_ODT2_Msk                       /*!< GPIO x output data, pin 2 */
#define GPIO_ODT_ODT3_Pos                   (3U)
#define GPIO_ODT_ODT3_Msk                   (0x1U << GPIO_ODT_ODT3_Pos)             /*!< 0x00000008 */
#define GPIO_ODT_ODT3                       GPIO_ODT_ODT3_Msk                       /*!< GPIO x output data, pin 3 */
#define GPIO_ODT_ODT4_Pos                   (4U)
#define GPIO_ODT_ODT4_Msk                   (0x1U << GPIO_ODT_ODT4_Pos)             /*!< 0x00000010 */
#define GPIO_ODT_ODT4                       GPIO_ODT_ODT4_Msk                       /*!< GPIO x output data, pin 4 */
#define GPIO_ODT_ODT5_Pos                   (5U)
#define GPIO_ODT_ODT5_Msk                   (0x1U << GPIO_ODT_ODT5_Pos)             /*!< 0x00000020 */
#define GPIO_ODT_ODT5                       GPIO_ODT_ODT5_Msk                       /*!< GPIO x output data, pin 5 */
#define GPIO_ODT_ODT6_Pos                   (6U)
#define GPIO_ODT_ODT6_Msk                   (0x1U << GPIO_ODT_ODT6_Pos)             /*!< 0x00000040 */
#define GPIO_ODT_ODT6                       GPIO_ODT_ODT6_Msk                       /*!< GPIO x output data, pin 6 */
#define GPIO_ODT_ODT7_Pos                   (7U)
#define GPIO_ODT_ODT7_Msk                   (0x1U << GPIO_ODT_ODT7_Pos)             /*!< 0x00000080 */
#define GPIO_ODT_ODT7                       GPIO_ODT_ODT7_Msk                       /*!< GPIO x output data, pin 7 */
#define GPIO_ODT_ODT8_Pos                   (8U)
#define GPIO_ODT_ODT8_Msk                   (0x1U << GPIO_ODT_ODT8_Pos)             /*!< 0x00000100 */
#define GPIO_ODT_ODT8                       GPIO_ODT_ODT8_Msk                       /*!< GPIO x output data, pin 8 */
#define GPIO_ODT_ODT9_Pos                   (9U)
#define GPIO_ODT_ODT9_Msk                   (0x1U << GPIO_ODT_ODT9_Pos)             /*!< 0x00000200 */
#define GPIO_ODT_ODT9                       GPIO_ODT_ODT9_Msk                       /*!< GPIO x output data, pin 9 */
#define GPIO_ODT_ODT10_Pos                  (10U)
#define GPIO_ODT_ODT10_Msk                  (0x1U << GPIO_ODT_ODT10_Pos)            /*!< 0x00000400 */
#define GPIO_ODT_ODT10                      GPIO_ODT_ODT10_Msk                      /*!< GPIO x output data, pin 10 */
#define GPIO_ODT_ODT11_Pos                  (11U)
#define GPIO_ODT_ODT11_Msk                  (0x1U << GPIO_ODT_ODT11_Pos)            /*!< 0x00000800 */
#define GPIO_ODT_ODT11                      GPIO_ODT_ODT11_Msk                      /*!< GPIO x output data, pin 11 */
#define GPIO_ODT_ODT12_Pos                  (12U)
#define GPIO_ODT_ODT12_Msk                  (0x1U << GPIO_ODT_ODT12_Pos)            /*!< 0x00001000 */
#define GPIO_ODT_ODT12                      GPIO_ODT_ODT12_Msk                      /*!< GPIO x output data, pin 12 */
#define GPIO_ODT_ODT13_Pos                  (13U)
#define GPIO_ODT_ODT13_Msk                  (0x1U << GPIO_ODT_ODT13_Pos)            /*!< 0x00002000 */
#define GPIO_ODT_ODT13                      GPIO_ODT_ODT13_Msk                      /*!< GPIO x output data, pin 13 */
#define GPIO_ODT_ODT14_Pos                  (14U)
#define GPIO_ODT_ODT14_Msk                  (0x1U << GPIO_ODT_ODT14_Pos)            /*!< 0x00004000 */
#define GPIO_ODT_ODT14                      GPIO_ODT_ODT14_Msk                      /*!< GPIO x output data, pin 14 */
#define GPIO_ODT_ODT15_Pos                  (15U)
#define GPIO_ODT_ODT15_Msk                  (0x1U << GPIO_ODT_ODT15_Pos)            /*!< 0x00008000 */
#define GPIO_ODT_ODT15                      GPIO_ODT_ODT15_Msk                      /*!< GPIO x output data, pin 15 */

/*******************  Bit definition for GPIO_SCR register  *******************/
#define GPIO_SCR_IOSB0_Pos                  (0U)
#define GPIO_SCR_IOSB0_Msk                  (0x1U << GPIO_SCR_IOSB0_Pos)            /*!< 0x00000001 */
#define GPIO_SCR_IOSB0                      GPIO_SCR_IOSB0_Msk                      /*!< GPIO x set bit, pin 0 */
#define GPIO_SCR_IOSB1_Pos                  (1U)
#define GPIO_SCR_IOSB1_Msk                  (0x1U << GPIO_SCR_IOSB1_Pos)            /*!< 0x00000002 */
#define GPIO_SCR_IOSB1                      GPIO_SCR_IOSB1_Msk                      /*!< GPIO x set bit, pin 1 */
#define GPIO_SCR_IOSB2_Pos                  (2U)
#define GPIO_SCR_IOSB2_Msk                  (0x1U << GPIO_SCR_IOSB2_Pos)            /*!< 0x00000004 */
#define GPIO_SCR_IOSB2                      GPIO_SCR_IOSB2_Msk                      /*!< GPIO x set bit, pin 2 */
#define GPIO_SCR_IOSB3_Pos                  (3U)
#define GPIO_SCR_IOSB3_Msk                  (0x1U << GPIO_SCR_IOSB3_Pos)            /*!< 0x00000008 */
#define GPIO_SCR_IOSB3                      GPIO_SCR_IOSB3_Msk                      /*!< GPIO x set bit, pin 3 */
#define GPIO_SCR_IOSB4_Pos                  (4U)
#define GPIO_SCR_IOSB4_Msk                  (0x1U << GPIO_SCR_IOSB4_Pos)            /*!< 0x00000010 */
#define GPIO_SCR_IOSB4                      GPIO_SCR_IOSB4_Msk                      /*!< GPIO x set bit, pin 4 */
#define GPIO_SCR_IOSB5_Pos                  (5U)
#define GPIO_SCR_IOSB5_Msk                  (0x1U << GPIO_SCR_IOSB5_Pos)            /*!< 0x00000020 */
#define GPIO_SCR_IOSB5                      GPIO_SCR_IOSB5_Msk                      /*!< GPIO x set bit, pin 5 */
#define GPIO_SCR_IOSB6_Pos                  (6U)
#define GPIO_SCR_IOSB6_Msk                  (0x1U << GPIO_SCR_IOSB6_Pos)            /*!< 0x00000040 */
#define GPIO_SCR_IOSB6                      GPIO_SCR_IOSB6_Msk                      /*!< GPIO x set bit, pin 6 */
#define GPIO_SCR_IOSB7_Pos                  (7U)
#define GPIO_SCR_IOSB7_Msk                  (0x1U << GPIO_SCR_IOSB7_Pos)            /*!< 0x00000080 */
#define GPIO_SCR_IOSB7                      GPIO_SCR_IOSB7_Msk                      /*!< GPIO x set bit, pin 7 */
#define GPIO_SCR_IOSB8_Pos                  (8U)
#define GPIO_SCR_IOSB8_Msk                  (0x1U << GPIO_SCR_IOSB8_Pos)            /*!< 0x00000100 */
#define GPIO_SCR_IOSB8                      GPIO_SCR_IOSB8_Msk                      /*!< GPIO x set bit, pin 8 */
#define GPIO_SCR_IOSB9_Pos                  (9U)
#define GPIO_SCR_IOSB9_Msk                  (0x1U << GPIO_SCR_IOSB9_Pos)            /*!< 0x00000200 */
#define GPIO_SCR_IOSB9                      GPIO_SCR_IOSB9_Msk                      /*!< GPIO x set bit, pin 9 */
#define GPIO_SCR_IOSB10_Pos                 (10U)
#define GPIO_SCR_IOSB10_Msk                 (0x1U << GPIO_SCR_IOSB10_Pos)           /*!< 0x00000400 */
#define GPIO_SCR_IOSB10                     GPIO_SCR_IOSB10_Msk                     /*!< GPIO x set bit, pin 10 */
#define GPIO_SCR_IOSB11_Pos                 (11U)
#define GPIO_SCR_IOSB11_Msk                 (0x1U << GPIO_SCR_IOSB11_Pos)           /*!< 0x00000800 */
#define GPIO_SCR_IOSB11                     GPIO_SCR_IOSB11_Msk                     /*!< GPIO x set bit, pin 11 */
#define GPIO_SCR_IOSB12_Pos                 (12U)
#define GPIO_SCR_IOSB12_Msk                 (0x1U << GPIO_SCR_IOSB12_Pos)           /*!< 0x00001000 */
#define GPIO_SCR_IOSB12                     GPIO_SCR_IOSB12_Msk                     /*!< GPIO x set bit, pin 12 */
#define GPIO_SCR_IOSB13_Pos                 (13U)
#define GPIO_SCR_IOSB13_Msk                 (0x1U << GPIO_SCR_IOSB13_Pos)           /*!< 0x00002000 */
#define GPIO_SCR_IOSB13                     GPIO_SCR_IOSB13_Msk                     /*!< GPIO x set bit, pin 13 */
#define GPIO_SCR_IOSB14_Pos                 (14U)
#define GPIO_SCR_IOSB14_Msk                 (0x1U << GPIO_SCR_IOSB14_Pos)           /*!< 0x00004000 */
#define GPIO_SCR_IOSB14                     GPIO_SCR_IOSB14_Msk                     /*!< GPIO x set bit, pin 14 */
#define GPIO_SCR_IOSB15_Pos                 (15U)
#define GPIO_SCR_IOSB15_Msk                 (0x1U << GPIO_SCR_IOSB15_Pos)           /*!< 0x00008000 */
#define GPIO_SCR_IOSB15                     GPIO_SCR_IOSB15_Msk                     /*!< GPIO x set bit, pin 15 */
#define GPIO_SCR_IOCB0_Pos                  (16U)
#define GPIO_SCR_IOCB0_Msk                  (0x1U << GPIO_SCR_IOCB0_Pos)            /*!< 0x00010000 */
#define GPIO_SCR_IOCB0                      GPIO_SCR_IOCB0_Msk                      /*!< GPIO x clear bit, pin 0 */
#define GPIO_SCR_IOCB1_Pos                  (17U)
#define GPIO_SCR_IOCB1_Msk                  (0x1U << GPIO_SCR_IOCB1_Pos)            /*!< 0x00020000 */
#define GPIO_SCR_IOCB1                      GPIO_SCR_IOCB1_Msk                      /*!< GPIO x clear bit, pin 1 */
#define GPIO_SCR_IOCB2_Pos                  (18U)
#define GPIO_SCR_IOCB2_Msk                  (0x1U << GPIO_SCR_IOCB2_Pos)            /*!< 0x00040000 */
#define GPIO_SCR_IOCB2                      GPIO_SCR_IOCB2_Msk                      /*!< GPIO x clear bit, pin 2 */
#define GPIO_SCR_IOCB3_Pos                  (19U)
#define GPIO_SCR_IOCB3_Msk                  (0x1U << GPIO_SCR_IOCB3_Pos)            /*!< 0x00080000 */
#define GPIO_SCR_IOCB3                      GPIO_SCR_IOCB3_Msk                      /*!< GPIO x clear bit, pin 3 */
#define GPIO_SCR_IOCB4_Pos                  (20U)
#define GPIO_SCR_IOCB4_Msk                  (0x1U << GPIO_SCR_IOCB4_Pos)            /*!< 0x00100000 */
#define GPIO_SCR_IOCB4                      GPIO_SCR_IOCB4_Msk                      /*!< GPIO x clear bit, pin 4 */
#define GPIO_SCR_IOCB5_Pos                  (21U)
#define GPIO_SCR_IOCB5_Msk                  (0x1U << GPIO_SCR_IOCB5_Pos)            /*!< 0x00200000 */
#define GPIO_SCR_IOCB5                      GPIO_SCR_IOCB5_Msk                      /*!< GPIO x clear bit, pin 5 */
#define GPIO_SCR_IOCB6_Pos                  (22U)
#define GPIO_SCR_IOCB6_Msk                  (0x1U << GPIO_SCR_IOCB6_Pos)            /*!< 0x00400000 */
#define GPIO_SCR_IOCB6                      GPIO_SCR_IOCB6_Msk                      /*!< GPIO x clear bit, pin 6 */
#define GPIO_SCR_IOCB7_Pos                  (23U)
#define GPIO_SCR_IOCB7_Msk                  (0x1U << GPIO_SCR_IOCB7_Pos)            /*!< 0x00800000 */
#define GPIO_SCR_IOCB7                      GPIO_SCR_IOCB7_Msk                      /*!< GPIO x clear bit, pin 7 */
#define GPIO_SCR_IOCB8_Pos                  (24U)
#define GPIO_SCR_IOCB8_Msk                  (0x1U << GPIO_SCR_IOCB8_Pos)            /*!< 0x01000000 */
#define GPIO_SCR_IOCB8                      GPIO_SCR_IOCB8_Msk                      /*!< GPIO x clear bit, pin 8 */
#define GPIO_SCR_IOCB9_Pos                  (25U)
#define GPIO_SCR_IOCB9_Msk                  (0x1U << GPIO_SCR_IOCB9_Pos)            /*!< 0x02000000 */
#define GPIO_SCR_IOCB9                      GPIO_SCR_IOCB9_Msk                      /*!< GPIO x clear bit, pin 9 */
#define GPIO_SCR_IOCB10_Pos                 (26U)
#define GPIO_SCR_IOCB10_Msk                 (0x1U << GPIO_SCR_IOCB10_Pos)           /*!< 0x04000000 */
#define GPIO_SCR_IOCB10                     GPIO_SCR_IOCB10_Msk                     /*!< GPIO x clear bit, pin 10 */
#define GPIO_SCR_IOCB11_Pos                 (27U)
#define GPIO_SCR_IOCB11_Msk                 (0x1U << GPIO_SCR_IOCB11_Pos)           /*!< 0x08000000 */
#define GPIO_SCR_IOCB11                     GPIO_SCR_IOCB11_Msk                     /*!< GPIO x clear bit, pin 11 */
#define GPIO_SCR_IOCB12_Pos                 (28U)
#define GPIO_SCR_IOCB12_Msk                 (0x1U << GPIO_SCR_IOCB12_Pos)           /*!< 0x10000000 */
#define GPIO_SCR_IOCB12                     GPIO_SCR_IOCB12_Msk                     /*!< GPIO x clear bit, pin 12 */
#define GPIO_SCR_IOCB13_Pos                 (29U)
#define GPIO_SCR_IOCB13_Msk                 (0x1U << GPIO_SCR_IOCB13_Pos)           /*!< 0x20000000 */
#define GPIO_SCR_IOCB13                     GPIO_SCR_IOCB13_Msk                     /*!< GPIO x clear bit, pin 13 */
#define GPIO_SCR_IOCB14_Pos                 (30U)
#define GPIO_SCR_IOCB14_Msk                 (0x1U << GPIO_SCR_IOCB14_Pos)           /*!< 0x40000000 */
#define GPIO_SCR_IOCB14                     GPIO_SCR_IOCB14_Msk                     /*!< GPIO x clear bit, pin 14 */
#define GPIO_SCR_IOCB15_Pos                 (31U)
#define GPIO_SCR_IOCB15_Msk                 (0x1U << GPIO_SCR_IOCB15_Pos)           /*!< 0x80000000 */
#define GPIO_SCR_IOCB15                     GPIO_SCR_IOCB15_Msk                     /*!< GPIO x clear bit, pin 15 */

/*******************  Bit definition for GPIO_WPR register  *******************/
#define GPIO_WPR_WPEN0_Pos                  (0U)
#define GPIO_WPR_WPEN0_Msk                  (0x1U << GPIO_WPR_WPEN0_Pos)            /*!< 0x00000001 */
#define GPIO_WPR_WPEN0                      GPIO_WPR_WPEN0_Msk                      /*!< Write protect enable, pin 0 */
#define GPIO_WPR_WPEN1_Pos                  (1U)
#define GPIO_WPR_WPEN1_Msk                  (0x1U << GPIO_WPR_WPEN1_Pos)            /*!< 0x00000002 */
#define GPIO_WPR_WPEN1                      GPIO_WPR_WPEN1_Msk                      /*!< Write protect enable, pin 1 */
#define GPIO_WPR_WPEN2_Pos                  (2U)
#define GPIO_WPR_WPEN2_Msk                  (0x1U << GPIO_WPR_WPEN2_Pos)            /*!< 0x00000004 */
#define GPIO_WPR_WPEN2                      GPIO_WPR_WPEN2_Msk                      /*!< Write protect enable, pin 2 */
#define GPIO_WPR_WPEN3_Pos                  (3U)
#define GPIO_WPR_WPEN3_Msk                  (0x1U << GPIO_WPR_WPEN3_Pos)            /*!< 0x00000008 */
#define GPIO_WPR_WPEN3                      GPIO_WPR_WPEN3_Msk                      /*!< Write protect enable, pin 3 */
#define GPIO_WPR_WPEN4_Pos                  (4U)
#define GPIO_WPR_WPEN4_Msk                  (0x1U << GPIO_WPR_WPEN4_Pos)            /*!< 0x00000010 */
#define GPIO_WPR_WPEN4                      GPIO_WPR_WPEN4_Msk                      /*!< Write protect enable, pin 4 */
#define GPIO_WPR_WPEN5_Pos                  (5U)
#define GPIO_WPR_WPEN5_Msk                  (0x1U << GPIO_WPR_WPEN5_Pos)            /*!< 0x00000020 */
#define GPIO_WPR_WPEN5                      GPIO_WPR_WPEN5_Msk                      /*!< Write protect enable, pin 5 */
#define GPIO_WPR_WPEN6_Pos                  (6U)
#define GPIO_WPR_WPEN6_Msk                  (0x1U << GPIO_WPR_WPEN6_Pos)            /*!< 0x00000040 */
#define GPIO_WPR_WPEN6                      GPIO_WPR_WPEN6_Msk                      /*!< Write protect enable, pin 6 */
#define GPIO_WPR_WPEN7_Pos                  (7U)
#define GPIO_WPR_WPEN7_Msk                  (0x1U << GPIO_WPR_WPEN7_Pos)            /*!< 0x00000080 */
#define GPIO_WPR_WPEN7                      GPIO_WPR_WPEN7_Msk                      /*!< Write protect enable, pin 7 */
#define GPIO_WPR_WPEN8_Pos                  (8U)
#define GPIO_WPR_WPEN8_Msk                  (0x1U << GPIO_WPR_WPEN8_Pos)            /*!< 0x00000100 */
#define GPIO_WPR_WPEN8                      GPIO_WPR_WPEN8_Msk                      /*!< Write protect enable, pin 8 */
#define GPIO_WPR_WPEN9_Pos                  (9U)
#define GPIO_WPR_WPEN9_Msk                  (0x1U << GPIO_WPR_WPEN9_Pos)            /*!< 0x00000200 */
#define GPIO_WPR_WPEN9                      GPIO_WPR_WPEN9_Msk                      /*!< Write protect enable, pin 9 */
#define GPIO_WPR_WPEN10_Pos                 (10U)
#define GPIO_WPR_WPEN10_Msk                 (0x1U << GPIO_WPR_WPEN10_Pos)           /*!< 0x00000400 */
#define GPIO_WPR_WPEN10                     GPIO_WPR_WPEN10_Msk                     /*!< Write protect enable, pin 10 */
#define GPIO_WPR_WPEN11_Pos                 (11U)
#define GPIO_WPR_WPEN11_Msk                 (0x1U << GPIO_WPR_WPEN11_Pos)           /*!< 0x00000800 */
#define GPIO_WPR_WPEN11                     GPIO_WPR_WPEN11_Msk                     /*!< Write protect enable, pin 11 */
#define GPIO_WPR_WPEN12_Pos                 (12U)
#define GPIO_WPR_WPEN12_Msk                 (0x1U << GPIO_WPR_WPEN12_Pos)           /*!< 0x00001000 */
#define GPIO_WPR_WPEN12                     GPIO_WPR_WPEN12_Msk                     /*!< Write protect enable, pin 12 */
#define GPIO_WPR_WPEN13_Pos                 (13U)
#define GPIO_WPR_WPEN13_Msk                 (0x1U << GPIO_WPR_WPEN13_Pos)           /*!< 0x00002000 */
#define GPIO_WPR_WPEN13                     GPIO_WPR_WPEN13_Msk                     /*!< Write protect enable, pin 13 */
#define GPIO_WPR_WPEN14_Pos                 (14U)
#define GPIO_WPR_WPEN14_Msk                 (0x1U << GPIO_WPR_WPEN14_Pos)           /*!< 0x00004000 */
#define GPIO_WPR_WPEN14                     GPIO_WPR_WPEN14_Msk                     /*!< Write protect enable, pin 14 */
#define GPIO_WPR_WPEN15_Pos                 (15U)
#define GPIO_WPR_WPEN15_Msk                 (0x1U << GPIO_WPR_WPEN15_Pos)           /*!< 0x00008000 */
#define GPIO_WPR_WPEN15                     GPIO_WPR_WPEN15_Msk                     /*!< Write protect enable, pin 15 */
#define GPIO_WPR_WPSEQ_Pos                  (16U)
#define GPIO_WPR_WPSEQ_Msk                  (0x1U << GPIO_WPR_WPSEQ_Pos)            /*!< 0x00010000 */
#define GPIO_WPR_WPSEQ                      GPIO_WPR_WPSEQ_Msk                      /*!< Write protect sequence */

/******************  Bit definition for GPIO_MUXL register  *******************/
#define GPIO_MUXL_MUXL_Pos                  (0U)
#define GPIO_MUXL_MUXL_Msk                  (0xFFFFFFFFU << GPIO_MUXL_MUXL_Pos)     /*!< 0xFFFFFFFF */
#define GPIO_MUXL_MUXL                      GPIO_MUXL_MUXL_Msk                      /*!< Multiplexed function select for GPIO x */

/*!< MUXL0 configuration */
#define GPIO_MUXL_MUXL0_Pos                 (0U)
#define GPIO_MUXL_MUXL0_Msk                 (0xFU << GPIO_MUXL_MUXL0_Pos)           /*!< 0x0000000F */
#define GPIO_MUXL_MUXL0                     GPIO_MUXL_MUXL0_Msk                     /*!< MUXL0[3:0] bits (Multiplexed function select for GPIO x, pin 0) */
#define GPIO_MUXL_MUXL0_0                   (0x1U << GPIO_MUXL_MUXL0_Pos)           /*!< 0x00000001 */
#define GPIO_MUXL_MUXL0_1                   (0x2U << GPIO_MUXL_MUXL0_Pos)           /*!< 0x00000002 */
#define GPIO_MUXL_MUXL0_2                   (0x4U << GPIO_MUXL_MUXL0_Pos)           /*!< 0x00000004 */
#define GPIO_MUXL_MUXL0_3                   (0x8U << GPIO_MUXL_MUXL0_Pos)           /*!< 0x00000008 */

/*!< MUXL1 configuration */
#define GPIO_MUXL_MUXL1_Pos                 (4U)
#define GPIO_MUXL_MUXL1_Msk                 (0xFU << GPIO_MUXL_MUXL1_Pos)           /*!< 0x000000F0 */
#define GPIO_MUXL_MUXL1                     GPIO_MUXL_MUXL1_Msk                     /*!< MUXL1[3:0] bits (Multiplexed function select for GPIO x, pin 1) */
#define GPIO_MUXL_MUXL1_0                   (0x1U << GPIO_MUXL_MUXL1_Pos)           /*!< 0x00000010 */
#define GPIO_MUXL_MUXL1_1                   (0x2U << GPIO_MUXL_MUXL1_Pos)           /*!< 0x00000020 */
#define GPIO_MUXL_MUXL1_2                   (0x4U << GPIO_MUXL_MUXL1_Pos)           /*!< 0x00000040 */
#define GPIO_MUXL_MUXL1_3                   (0x8U << GPIO_MUXL_MUXL1_Pos)           /*!< 0x00000080 */

/*!< MUXL2 configuration */
#define GPIO_MUXL_MUXL2_Pos                 (8U)
#define GPIO_MUXL_MUXL2_Msk                 (0xFU << GPIO_MUXL_MUXL2_Pos)           /*!< 0x00000F00 */
#define GPIO_MUXL_MUXL2                     GPIO_MUXL_MUXL2_Msk                     /*!< MUXL2[3:0] bits (Multiplexed function select for GPIO x, pin 2) */
#define GPIO_MUXL_MUXL2_0                   (0x1U << GPIO_MUXL_MUXL2_Pos)           /*!< 0x00000100 */
#define GPIO_MUXL_MUXL2_1                   (0x2U << GPIO_MUXL_MUXL2_Pos)           /*!< 0x00000200 */
#define GPIO_MUXL_MUXL2_2                   (0x4U << GPIO_MUXL_MUXL2_Pos)           /*!< 0x00000400 */
#define GPIO_MUXL_MUXL2_3                   (0x8U << GPIO_MUXL_MUXL2_Pos)           /*!< 0x00000800 */

/*!< MUXL3 configuration */
#define GPIO_MUXL_MUXL3_Pos                 (12U)
#define GPIO_MUXL_MUXL3_Msk                 (0xFU << GPIO_MUXL_MUXL3_Pos)           /*!< 0x0000F000 */
#define GPIO_MUXL_MUXL3                     GPIO_MUXL_MUXL3_Msk                     /*!< MUXL3[3:0] bits (Multiplexed function select for GPIO x, pin 3) */
#define GPIO_MUXL_MUXL3_0                   (0x1U << GPIO_MUXL_MUXL3_Pos)           /*!< 0x00001000 */
#define GPIO_MUXL_MUXL3_1                   (0x2U << GPIO_MUXL_MUXL3_Pos)           /*!< 0x00002000 */
#define GPIO_MUXL_MUXL3_2                   (0x4U << GPIO_MUXL_MUXL3_Pos)           /*!< 0x00004000 */
#define GPIO_MUXL_MUXL3_3                   (0x8U << GPIO_MUXL_MUXL3_Pos)           /*!< 0x00008000 */

/*!< MUXL4 configuration */
#define GPIO_MUXL_MUXL4_Pos                 (16U)
#define GPIO_MUXL_MUXL4_Msk                 (0xFU << GPIO_MUXL_MUXL4_Pos)           /*!< 0x000F0000 */
#define GPIO_MUXL_MUXL4                     GPIO_MUXL_MUXL4_Msk                     /*!< MUXL4[3:0] bits (Multiplexed function select for GPIO x, pin 4) */
#define GPIO_MUXL_MUXL4_0                   (0x1U << GPIO_MUXL_MUXL4_Pos)           /*!< 0x00010000 */
#define GPIO_MUXL_MUXL4_1                   (0x2U << GPIO_MUXL_MUXL4_Pos)           /*!< 0x00020000 */
#define GPIO_MUXL_MUXL4_2                   (0x4U << GPIO_MUXL_MUXL4_Pos)           /*!< 0x00040000 */
#define GPIO_MUXL_MUXL4_3                   (0x8U << GPIO_MUXL_MUXL4_Pos)           /*!< 0x00080000 */

/*!< MUXL5 configuration */
#define GPIO_MUXL_MUXL5_Pos                 (20U)
#define GPIO_MUXL_MUXL5_Msk                 (0xFU << GPIO_MUXL_MUXL5_Pos)           /*!< 0x00F00000 */
#define GPIO_MUXL_MUXL5                     GPIO_MUXL_MUXL5_Msk                     /*!< MUXL5[3:0] bits (Multiplexed function select for GPIO x, pin 5) */
#define GPIO_MUXL_MUXL5_0                   (0x1U << GPIO_MUXL_MUXL5_Pos)           /*!< 0x00100000 */
#define GPIO_MUXL_MUXL5_1                   (0x2U << GPIO_MUXL_MUXL5_Pos)           /*!< 0x00200000 */
#define GPIO_MUXL_MUXL5_2                   (0x4U << GPIO_MUXL_MUXL5_Pos)           /*!< 0x00400000 */
#define GPIO_MUXL_MUXL5_3                   (0x8U << GPIO_MUXL_MUXL5_Pos)           /*!< 0x00800000 */

/*!< MUXL6 configuration */
#define GPIO_MUXL_MUXL6_Pos                 (24U)
#define GPIO_MUXL_MUXL6_Msk                 (0xFU << GPIO_MUXL_MUXL6_Pos)           /*!< 0x0F000000 */
#define GPIO_MUXL_MUXL6                     GPIO_MUXL_MUXL6_Msk                     /*!< MUXL6[3:0] bits (Multiplexed function select for GPIO x, pin 6) */
#define GPIO_MUXL_MUXL6_0                   (0x1U << GPIO_MUXL_MUXL6_Pos)           /*!< 0x01000000 */
#define GPIO_MUXL_MUXL6_1                   (0x2U << GPIO_MUXL_MUXL6_Pos)           /*!< 0x02000000 */
#define GPIO_MUXL_MUXL6_2                   (0x4U << GPIO_MUXL_MUXL6_Pos)           /*!< 0x04000000 */
#define GPIO_MUXL_MUXL6_3                   (0x8U << GPIO_MUXL_MUXL6_Pos)           /*!< 0x08000000 */

/*!< MUXL7 configuration */
#define GPIO_MUXL_MUXL7_Pos                 (28U)
#define GPIO_MUXL_MUXL7_Msk                 (0xFU << GPIO_MUXL_MUXL7_Pos)           /*!< 0xF0000000 */
#define GPIO_MUXL_MUXL7                     GPIO_MUXL_MUXL7_Msk                     /*!< MUXL7[3:0] bits (Multiplexed function select for GPIO x, pin 7) */
#define GPIO_MUXL_MUXL7_0                   (0x1U << GPIO_MUXL_MUXL7_Pos)           /*!< 0x10000000 */
#define GPIO_MUXL_MUXL7_1                   (0x2U << GPIO_MUXL_MUXL7_Pos)           /*!< 0x20000000 */
#define GPIO_MUXL_MUXL7_2                   (0x4U << GPIO_MUXL_MUXL7_Pos)           /*!< 0x40000000 */
#define GPIO_MUXL_MUXL7_3                   (0x8U << GPIO_MUXL_MUXL7_Pos)           /*!< 0x80000000 */

/******************  Bit definition for GPIO_MUXH register  *******************/
#define GPIO_MUXH_MUXH_Pos                  (0U)
#define GPIO_MUXH_MUXH_Msk                  (0xFFFFFFFFU << GPIO_MUXH_MUXH_Pos)     /*!< 0xFFFFFFFF */
#define GPIO_MUXH_MUXH                      GPIO_MUXH_MUXH_Msk                      /*!< Multiplexed function select for GPIO x */

/*!< MUXH8 configuration */
#define GPIO_MUXH_MUXH8_Pos                 (0U)
#define GPIO_MUXH_MUXH8_Msk                 (0xFU << GPIO_MUXH_MUXH8_Pos)           /*!< 0x0000000F */
#define GPIO_MUXH_MUXH8                     GPIO_MUXH_MUXH8_Msk                     /*!< MUXH8[3:0] bits (Multiplexed function select for GPIO x, pin 8) */
#define GPIO_MUXH_MUXH8_0                   (0x1U << GPIO_MUXH_MUXH8_Pos)           /*!< 0x00000001 */
#define GPIO_MUXH_MUXH8_1                   (0x2U << GPIO_MUXH_MUXH8_Pos)           /*!< 0x00000002 */
#define GPIO_MUXH_MUXH8_2                   (0x4U << GPIO_MUXH_MUXH8_Pos)           /*!< 0x00000004 */
#define GPIO_MUXH_MUXH8_3                   (0x8U << GPIO_MUXH_MUXH8_Pos)           /*!< 0x00000008 */

/*!< MUXH9 configuration */
#define GPIO_MUXH_MUXH9_Pos                 (4U)
#define GPIO_MUXH_MUXH9_Msk                 (0xFU << GPIO_MUXH_MUXH9_Pos)           /*!< 0x000000F0 */
#define GPIO_MUXH_MUXH9                     GPIO_MUXH_MUXH9_Msk                     /*!< MUXH9[3:0] bits (Multiplexed function select for GPIO x, pin 9) */
#define GPIO_MUXH_MUXH9_0                   (0x1U << GPIO_MUXH_MUXH9_Pos)           /*!< 0x00000010 */
#define GPIO_MUXH_MUXH9_1                   (0x2U << GPIO_MUXH_MUXH9_Pos)           /*!< 0x00000020 */
#define GPIO_MUXH_MUXH9_2                   (0x4U << GPIO_MUXH_MUXH9_Pos)           /*!< 0x00000040 */
#define GPIO_MUXH_MUXH9_3                   (0x8U << GPIO_MUXH_MUXH9_Pos)           /*!< 0x00000080 */

/*!< MUXH10 configuration */
#define GPIO_MUXH_MUXH10_Pos                (8U)
#define GPIO_MUXH_MUXH10_Msk                (0xFU << GPIO_MUXH_MUXH10_Pos)          /*!< 0x00000F00 */
#define GPIO_MUXH_MUXH10                    GPIO_MUXH_MUXH10_Msk                    /*!< MUXH10[3:0] bits (Multiplexed function select for GPIO x, pin 10) */
#define GPIO_MUXH_MUXH10_0                  (0x1U << GPIO_MUXH_MUXH10_Pos)          /*!< 0x00000100 */
#define GPIO_MUXH_MUXH10_1                  (0x2U << GPIO_MUXH_MUXH10_Pos)          /*!< 0x00000200 */
#define GPIO_MUXH_MUXH10_2                  (0x4U << GPIO_MUXH_MUXH10_Pos)          /*!< 0x00000400 */
#define GPIO_MUXH_MUXH10_3                  (0x8U << GPIO_MUXH_MUXH10_Pos)          /*!< 0x00000800 */

/*!< MUXH11 configuration */
#define GPIO_MUXH_MUXH11_Pos                (12U)
#define GPIO_MUXH_MUXH11_Msk                (0xFU << GPIO_MUXH_MUXH11_Pos)          /*!< 0x0000F000 */
#define GPIO_MUXH_MUXH11                    GPIO_MUXH_MUXH11_Msk                    /*!< MUXH11[3:0] bits (Multiplexed function select for GPIO x, pin 11) */
#define GPIO_MUXH_MUXH11_0                  (0x1U << GPIO_MUXH_MUXH11_Pos)          /*!< 0x00001000 */
#define GPIO_MUXH_MUXH11_1                  (0x2U << GPIO_MUXH_MUXH11_Pos)          /*!< 0x00002000 */
#define GPIO_MUXH_MUXH11_2                  (0x4U << GPIO_MUXH_MUXH11_Pos)          /*!< 0x00004000 */
#define GPIO_MUXH_MUXH11_3                  (0x8U << GPIO_MUXH_MUXH11_Pos)          /*!< 0x00008000 */

/*!< MUXH12 configuration */
#define GPIO_MUXH_MUXH12_Pos                (16U)
#define GPIO_MUXH_MUXH12_Msk                (0xFU << GPIO_MUXH_MUXH12_Pos)          /*!< 0x000F0000 */
#define GPIO_MUXH_MUXH12                    GPIO_MUXH_MUXH12_Msk                    /*!< MUXH12[3:0] bits (Multiplexed function select for GPIO x, pin 12) */
#define GPIO_MUXH_MUXH12_0                  (0x1U << GPIO_MUXH_MUXH12_Pos)          /*!< 0x00010000 */
#define GPIO_MUXH_MUXH12_1                  (0x2U << GPIO_MUXH_MUXH12_Pos)          /*!< 0x00020000 */
#define GPIO_MUXH_MUXH12_2                  (0x4U << GPIO_MUXH_MUXH12_Pos)          /*!< 0x00040000 */
#define GPIO_MUXH_MUXH12_3                  (0x8U << GPIO_MUXH_MUXH12_Pos)          /*!< 0x00080000 */

/*!< MUXH13 configuration */
#define GPIO_MUXH_MUXH13_Pos                (20U)
#define GPIO_MUXH_MUXH13_Msk                (0xFU << GPIO_MUXH_MUXH13_Pos)          /*!< 0x00F00000 */
#define GPIO_MUXH_MUXH13                    GPIO_MUXH_MUXH13_Msk                    /*!< MUXH13[3:0] bits (Multiplexed function select for GPIO x, pin 13) */
#define GPIO_MUXH_MUXH13_0                  (0x1U << GPIO_MUXH_MUXH13_Pos)          /*!< 0x00100000 */
#define GPIO_MUXH_MUXH13_1                  (0x2U << GPIO_MUXH_MUXH13_Pos)          /*!< 0x00200000 */
#define GPIO_MUXH_MUXH13_2                  (0x4U << GPIO_MUXH_MUXH13_Pos)          /*!< 0x00400000 */
#define GPIO_MUXH_MUXH13_3                  (0x8U << GPIO_MUXH_MUXH13_Pos)          /*!< 0x00800000 */

/*!< MUXH14 configuration */
#define GPIO_MUXH_MUXH14_Pos                (24U)
#define GPIO_MUXH_MUXH14_Msk                (0xFU << GPIO_MUXH_MUXH14_Pos)          /*!< 0x0F000000 */
#define GPIO_MUXH_MUXH14                    GPIO_MUXH_MUXH14_Msk                    /*!< MUXH14[3:0] bits (Multiplexed function select for GPIO x, pin 14) */
#define GPIO_MUXH_MUXH14_0                  (0x1U << GPIO_MUXH_MUXH14_Pos)          /*!< 0x01000000 */
#define GPIO_MUXH_MUXH14_1                  (0x2U << GPIO_MUXH_MUXH14_Pos)          /*!< 0x02000000 */
#define GPIO_MUXH_MUXH14_2                  (0x4U << GPIO_MUXH_MUXH14_Pos)          /*!< 0x04000000 */
#define GPIO_MUXH_MUXH14_3                  (0x8U << GPIO_MUXH_MUXH14_Pos)          /*!< 0x08000000 */

/*!< MUXH15 configuration */
#define GPIO_MUXH_MUXH15_Pos                (28U)
#define GPIO_MUXH_MUXH15_Msk                (0xFU << GPIO_MUXH_MUXH15_Pos)          /*!< 0xF0000000 */
#define GPIO_MUXH_MUXH15                    GPIO_MUXH_MUXH15_Msk                    /*!< MUXH15[3:0] bits (Multiplexed function select for GPIO x, pin 15) */
#define GPIO_MUXH_MUXH15_0                  (0x1U << GPIO_MUXH_MUXH15_Pos)          /*!< 0x10000000 */
#define GPIO_MUXH_MUXH15_1                  (0x2U << GPIO_MUXH_MUXH15_Pos)          /*!< 0x20000000 */
#define GPIO_MUXH_MUXH15_2                  (0x4U << GPIO_MUXH_MUXH15_Pos)          /*!< 0x40000000 */
#define GPIO_MUXH_MUXH15_3                  (0x8U << GPIO_MUXH_MUXH15_Pos)          /*!< 0x80000000 */

/*******************  Bit definition for GPIO_CLR register  *******************/
#define GPIO_CLR_IOCB0_Pos                  (0U)
#define GPIO_CLR_IOCB0_Msk                  (0x1U << GPIO_CLR_IOCB0_Pos)            /*!< 0x00000001 */
#define GPIO_CLR_IOCB0                      GPIO_CLR_IOCB0_Msk                      /*!< GPIO x clear bit, pin 0 */
#define GPIO_CLR_IOCB1_Pos                  (1U)
#define GPIO_CLR_IOCB1_Msk                  (0x1U << GPIO_CLR_IOCB1_Pos)            /*!< 0x00000002 */
#define GPIO_CLR_IOCB1                      GPIO_CLR_IOCB1_Msk                      /*!< GPIO x clear bit, pin 1 */
#define GPIO_CLR_IOCB2_Pos                  (2U)
#define GPIO_CLR_IOCB2_Msk                  (0x1U << GPIO_CLR_IOCB2_Pos)            /*!< 0x00000004 */
#define GPIO_CLR_IOCB2                      GPIO_CLR_IOCB2_Msk                      /*!< GPIO x clear bit, pin 2 */
#define GPIO_CLR_IOCB3_Pos                  (3U)
#define GPIO_CLR_IOCB3_Msk                  (0x1U << GPIO_CLR_IOCB3_Pos)            /*!< 0x00000008 */
#define GPIO_CLR_IOCB3                      GPIO_CLR_IOCB3_Msk                      /*!< GPIO x clear bit, pin 3 */
#define GPIO_CLR_IOCB4_Pos                  (4U)
#define GPIO_CLR_IOCB4_Msk                  (0x1U << GPIO_CLR_IOCB4_Pos)            /*!< 0x00000010 */
#define GPIO_CLR_IOCB4                      GPIO_CLR_IOCB4_Msk                      /*!< GPIO x clear bit, pin 4 */
#define GPIO_CLR_IOCB5_Pos                  (5U)
#define GPIO_CLR_IOCB5_Msk                  (0x1U << GPIO_CLR_IOCB5_Pos)            /*!< 0x00000020 */
#define GPIO_CLR_IOCB5                      GPIO_CLR_IOCB5_Msk                      /*!< GPIO x clear bit, pin 5 */
#define GPIO_CLR_IOCB6_Pos                  (6U)
#define GPIO_CLR_IOCB6_Msk                  (0x1U << GPIO_CLR_IOCB6_Pos)            /*!< 0x00000040 */
#define GPIO_CLR_IOCB6                      GPIO_CLR_IOCB6_Msk                      /*!< GPIO x clear bit, pin 6 */
#define GPIO_CLR_IOCB7_Pos                  (7U)
#define GPIO_CLR_IOCB7_Msk                  (0x1U << GPIO_CLR_IOCB7_Pos)            /*!< 0x00000080 */
#define GPIO_CLR_IOCB7                      GPIO_CLR_IOCB7_Msk                      /*!< GPIO x clear bit, pin 7 */
#define GPIO_CLR_IOCB8_Pos                  (8U)
#define GPIO_CLR_IOCB8_Msk                  (0x1U << GPIO_CLR_IOCB8_Pos)            /*!< 0x00000100 */
#define GPIO_CLR_IOCB8                      GPIO_CLR_IOCB8_Msk                      /*!< GPIO x clear bit, pin 8 */
#define GPIO_CLR_IOCB9_Pos                  (9U)
#define GPIO_CLR_IOCB9_Msk                  (0x1U << GPIO_CLR_IOCB9_Pos)            /*!< 0x00000200 */
#define GPIO_CLR_IOCB9                      GPIO_CLR_IOCB9_Msk                      /*!< GPIO x clear bit, pin 9 */
#define GPIO_CLR_IOCB10_Pos                 (10U)
#define GPIO_CLR_IOCB10_Msk                 (0x1U << GPIO_CLR_IOCB10_Pos)           /*!< 0x00000400 */
#define GPIO_CLR_IOCB10                     GPIO_CLR_IOCB10_Msk                     /*!< GPIO x clear bit, pin 10 */
#define GPIO_CLR_IOCB11_Pos                 (11U)
#define GPIO_CLR_IOCB11_Msk                 (0x1U << GPIO_CLR_IOCB11_Pos)           /*!< 0x00000800 */
#define GPIO_CLR_IOCB11                     GPIO_CLR_IOCB11_Msk                     /*!< GPIO x clear bit, pin 11 */
#define GPIO_CLR_IOCB12_Pos                 (12U)
#define GPIO_CLR_IOCB12_Msk                 (0x1U << GPIO_CLR_IOCB12_Pos)           /*!< 0x00001000 */
#define GPIO_CLR_IOCB12                     GPIO_CLR_IOCB12_Msk                     /*!< GPIO x clear bit, pin 12 */
#define GPIO_CLR_IOCB13_Pos                 (13U)
#define GPIO_CLR_IOCB13_Msk                 (0x1U << GPIO_CLR_IOCB13_Pos)           /*!< 0x00002000 */
#define GPIO_CLR_IOCB13                     GPIO_CLR_IOCB13_Msk                     /*!< GPIO x clear bit, pin 13 */
#define GPIO_CLR_IOCB14_Pos                 (14U)
#define GPIO_CLR_IOCB14_Msk                 (0x1U << GPIO_CLR_IOCB14_Pos)           /*!< 0x00004000 */
#define GPIO_CLR_IOCB14                     GPIO_CLR_IOCB14_Msk                     /*!< GPIO x clear bit, pin 14 */
#define GPIO_CLR_IOCB15_Pos                 (15U)
#define GPIO_CLR_IOCB15_Msk                 (0x1U << GPIO_CLR_IOCB15_Pos)           /*!< 0x00008000 */
#define GPIO_CLR_IOCB15                     GPIO_CLR_IOCB15_Msk                     /*!< GPIO x clear bit, pin 15 */

/******************  Bit definition for GPIO_HDRV register  *******************/
#define GPIO_HDRV_HDRV0_Pos                 (0U)
#define GPIO_HDRV_HDRV0_Msk                 (0x1U << GPIO_HDRV_HDRV0_Pos)           /*!< 0x00000001 */
#define GPIO_HDRV_HDRV0                     GPIO_HDRV_HDRV0_Msk                     /*!< GPIO x huge sourcing/sinking strength control, pin 0 */
#define GPIO_HDRV_HDRV1_Pos                 (1U)
#define GPIO_HDRV_HDRV1_Msk                 (0x1U << GPIO_HDRV_HDRV1_Pos)           /*!< 0x00000002 */
#define GPIO_HDRV_HDRV1                     GPIO_HDRV_HDRV1_Msk                     /*!< GPIO x huge sourcing/sinking strength control, pin 1 */
#define GPIO_HDRV_HDRV2_Pos                 (2U)
#define GPIO_HDRV_HDRV2_Msk                 (0x1U << GPIO_HDRV_HDRV2_Pos)           /*!< 0x00000004 */
#define GPIO_HDRV_HDRV2                     GPIO_HDRV_HDRV2_Msk                     /*!< GPIO x huge sourcing/sinking strength control, pin 2 */
#define GPIO_HDRV_HDRV3_Pos                 (3U)
#define GPIO_HDRV_HDRV3_Msk                 (0x1U << GPIO_HDRV_HDRV3_Pos)           /*!< 0x00000008 */
#define GPIO_HDRV_HDRV3                     GPIO_HDRV_HDRV3_Msk                     /*!< GPIO x huge sourcing/sinking strength control, pin 3 */
#define GPIO_HDRV_HDRV4_Pos                 (4U)
#define GPIO_HDRV_HDRV4_Msk                 (0x1U << GPIO_HDRV_HDRV4_Pos)           /*!< 0x00000010 */
#define GPIO_HDRV_HDRV4                     GPIO_HDRV_HDRV4_Msk                     /*!< GPIO x huge sourcing/sinking strength control, pin 4 */
#define GPIO_HDRV_HDRV5_Pos                 (5U)
#define GPIO_HDRV_HDRV5_Msk                 (0x1U << GPIO_HDRV_HDRV5_Pos)           /*!< 0x00000020 */
#define GPIO_HDRV_HDRV5                     GPIO_HDRV_HDRV5_Msk                     /*!< GPIO x huge sourcing/sinking strength control, pin 5 */
#define GPIO_HDRV_HDRV6_Pos                 (6U)
#define GPIO_HDRV_HDRV6_Msk                 (0x1U << GPIO_HDRV_HDRV6_Pos)           /*!< 0x00000040 */
#define GPIO_HDRV_HDRV6                     GPIO_HDRV_HDRV6_Msk                     /*!< GPIO x huge sourcing/sinking strength control, pin 6 */
#define GPIO_HDRV_HDRV7_Pos                 (7U)
#define GPIO_HDRV_HDRV7_Msk                 (0x1U << GPIO_HDRV_HDRV7_Pos)           /*!< 0x00000080 */
#define GPIO_HDRV_HDRV7                     GPIO_HDRV_HDRV7_Msk                     /*!< GPIO x huge sourcing/sinking strength control, pin 7 */
#define GPIO_HDRV_HDRV8_Pos                 (8U)
#define GPIO_HDRV_HDRV8_Msk                 (0x1U << GPIO_HDRV_HDRV8_Pos)           /*!< 0x00000100 */
#define GPIO_HDRV_HDRV8                     GPIO_HDRV_HDRV8_Msk                     /*!< GPIO x huge sourcing/sinking strength control, pin 8 */
#define GPIO_HDRV_HDRV9_Pos                 (9U)
#define GPIO_HDRV_HDRV9_Msk                 (0x1U << GPIO_HDRV_HDRV9_Pos)           /*!< 0x00000200 */
#define GPIO_HDRV_HDRV9                     GPIO_HDRV_HDRV9_Msk                     /*!< GPIO x huge sourcing/sinking strength control, pin 9 */
#define GPIO_HDRV_HDRV10_Pos                (10U)
#define GPIO_HDRV_HDRV10_Msk                (0x1U << GPIO_HDRV_HDRV10_Pos)          /*!< 0x00000400 */
#define GPIO_HDRV_HDRV10                    GPIO_HDRV_HDRV10_Msk                    /*!< GPIO x huge sourcing/sinking strength control, pin 10 */
#define GPIO_HDRV_HDRV11_Pos                (11U)
#define GPIO_HDRV_HDRV11_Msk                (0x1U << GPIO_HDRV_HDRV11_Pos)          /*!< 0x00000800 */
#define GPIO_HDRV_HDRV11                    GPIO_HDRV_HDRV11_Msk                    /*!< GPIO x huge sourcing/sinking strength control, pin 11 */
#define GPIO_HDRV_HDRV12_Pos                (12U)
#define GPIO_HDRV_HDRV12_Msk                (0x1U << GPIO_HDRV_HDRV12_Pos)          /*!< 0x00001000 */
#define GPIO_HDRV_HDRV12                    GPIO_HDRV_HDRV12_Msk                    /*!< GPIO x huge sourcing/sinking strength control, pin 12 */
#define GPIO_HDRV_HDRV13_Pos                (13U)
#define GPIO_HDRV_HDRV13_Msk                (0x1U << GPIO_HDRV_HDRV13_Pos)          /*!< 0x00002000 */
#define GPIO_HDRV_HDRV13                    GPIO_HDRV_HDRV13_Msk                    /*!< GPIO x huge sourcing/sinking strength control, pin 13 */
#define GPIO_HDRV_HDRV14_Pos                (14U)
#define GPIO_HDRV_HDRV14_Msk                (0x1U << GPIO_HDRV_HDRV14_Pos)          /*!< 0x00004000 */
#define GPIO_HDRV_HDRV14                    GPIO_HDRV_HDRV14_Msk                    /*!< GPIO x huge sourcing/sinking strength control, pin 14 */
#define GPIO_HDRV_HDRV15_Pos                (15U)
#define GPIO_HDRV_HDRV15_Msk                (0x1U << GPIO_HDRV_HDRV15_Pos)          /*!< 0x00008000 */
#define GPIO_HDRV_HDRV15                    GPIO_HDRV_HDRV15_Msk                    /*!< GPIO x huge sourcing/sinking strength control, pin 15 */

/******************************************************************************/
/*                                                                            */
/*                   System configuration controller (SCFG)                   */
/*                                                                            */
/******************************************************************************/
/*!< MEM_MAP_SEL configuration */
#define SCFG_CFG1_MEM_MAP_SEL_Pos           (0U)
#define SCFG_CFG1_MEM_MAP_SEL_Msk           (0x7U << SCFG_CFG1_MEM_MAP_SEL_Pos)     /*!< 0x00000007 */
#define SCFG_CFG1_MEM_MAP_SEL               SCFG_CFG1_MEM_MAP_SEL_Msk               /*!< MEM_MAP_SEL[3:0] bits (Boot mode status bit) */
#define SCFG_CFG1_MEM_MAP_SEL_0             (0x1U << SCFG_CFG1_MEM_MAP_SEL_Pos)     /*!< 0x00000001 */
#define SCFG_CFG1_MEM_MAP_SEL_1             (0x2U << SCFG_CFG1_MEM_MAP_SEL_Pos)     /*!< 0x00000002 */
#define SCFG_CFG1_MEM_MAP_SEL_2             (0x4U << SCFG_CFG1_MEM_MAP_SEL_Pos)     /*!< 0x00000002 */

#define SCFG_CFG1_MEM_MAP_SEL_FLASHMEM      0x00000000U                             /*!< Boot from main flash memory */
#define SCFG_CFG1_MEM_MAP_SEL_SYSMEM        0x00000001U                             /*!< Boot from system memory */
#define SCFG_CFG1_MEM_MAP_SEL_XMC_BANK1     0x00000002U                             /*!< Boot from XMC BANK1 */
#define SCFG_CFG1_MEM_MAP_SEL_INTSRAM       0x00000003U                             /*!< Boot from internal SRAM */
#define SCFG_CFG1_MEM_MAP_SEL_XMC_SDRAM     0x00000004U                             /*!< Boot from XMC SDRAM */

#define SCFG_CFG1_IR_POL_Pos                (5U)
#define SCFG_CFG1_IR_POL_Msk                (0x1U << SCFG_CFG1_IR_POL_Pos)          /*!< 0x00000020 */
#define SCFG_CFG1_IR_POL                    SCFG_CFG1_IR_POL_Msk                    /*!< Infrared output polarity selection */

/*!< IR_SRC_SEL configuration */
#define SCFG_CFG1_IR_SRC_SEL_Pos            (6U)
#define SCFG_CFG1_IR_SRC_SEL_Msk            (0x3U << SCFG_CFG1_IR_SRC_SEL_Pos)      /*!< 0x000000C0 */
#define SCFG_CFG1_IR_SRC_SEL                SCFG_CFG1_IR_SRC_SEL_Msk                /*!< IR_SRC_SEL[1:0] bits (IR modulation envelope signal source selection) */
#define SCFG_CFG1_IR_SRC_SEL_0              (0x1U << SCFG_CFG1_IR_SRC_SEL_Pos)      /*!< 0x00000040 */
#define SCFG_CFG1_IR_SRC_SEL_1              (0x2U << SCFG_CFG1_IR_SRC_SEL_Pos)      /*!< 0x00000080 */

#define SCFG_CFG1_IR_SRC_SEL_TMR10          0x00000000U                             /*!< TMR10 */

/*!< SWAP_XMC configuration */
#define SCFG_CFG1_SWAP_XMC_Pos              (10U)
#define SCFG_CFG1_SWAP_XMC_Msk              (0x3U << SCFG_CFG1_SWAP_XMC_Pos)        /*!< 0x00000C00 */
#define SCFG_CFG1_SWAP_XMC                  SCFG_CFG1_SWAP_XMC_Msk                  /*!< SWAP_XMC[1:0] bits (swap xmc source selection) */
#define SCFG_CFG1_SWAP_XMC_0                (0x1U << SCFG_CFG1_SWAP_XMC_Pos)        /*!< 0x00000400 */
#define SCFG_CFG1_SWAP_XMC_1                (0x2U << SCFG_CFG1_SWAP_XMC_Pos)        /*!< 0x00000800 */

#define SCFG_CFG2_MII_RMII_SEL_Pos          (23U)
#define SCFG_CFG2_MII_RMII_SEL_Msk          (0x1U << SCFG_CFG2_MII_RMII_SEL_Pos)     /*!< 0x00800020 */
#define SCFG_CFG2_MII_RMII_SEL              SCFG_CFG2_MII_RMII_SEL_Msk               /*!< mii rmii selection */


/*****************  Bit definition for SCFG_EXINTC1 register  *****************/
/*!< EXINT0 configuration */
#define SCFG_EXINTC1_EXINT0_Pos             (0U)
#define SCFG_EXINTC1_EXINT0_Msk             (0xFU << SCFG_EXINTC1_EXINT0_Pos)       /*!< 0x0000000F */
#define SCFG_EXINTC1_EXINT0                 SCFG_EXINTC1_EXINT0_Msk                 /*!< EXINT0[3:0] bits (EXINT0 input source configuration) */

#define SCFG_EXINTC1_EXINT0_GPA             0x00000000U                             /*!< GPIOA pin 0 */
#define SCFG_EXINTC1_EXINT0_GPB_Pos         (0U)
#define SCFG_EXINTC1_EXINT0_GPB_Msk         (0x1U << SCFG_EXINTC1_EXINT0_GPB_Pos)   /*!< 0x00000001 */
#define SCFG_EXINTC1_EXINT0_GPB             SCFG_EXINTC1_EXINT0_GPB_Msk             /*!< GPIOB pin 0 */
#define SCFG_EXINTC1_EXINT0_GPC_Pos         (1U)
#define SCFG_EXINTC1_EXINT0_GPC_Msk         (0x1U << SCFG_EXINTC1_EXINT0_GPC_Pos)   /*!< 0x00000002 */
#define SCFG_EXINTC1_EXINT0_GPC             SCFG_EXINTC1_EXINT0_GPC_Msk             /*!< GPIOC pin 0 */
#define SCFG_EXINTC1_EXINT0_GPD_Pos         (0U)
#define SCFG_EXINTC1_EXINT0_GPD_Msk         (0x3U << SCFG_EXINTC1_EXINT0_GPD_Pos)   /*!< 0x00000003 */
#define SCFG_EXINTC1_EXINT0_GPD             SCFG_EXINTC1_EXINT0_GPD_Msk             /*!< GPIOD pin 0 */
#define SCFG_EXINTC1_EXINT0_GPE_Pos         (2U)
#define SCFG_EXINTC1_EXINT0_GPE_Msk         (0x1U << SCFG_EXINTC1_EXINT0_GPE_Pos)   /*!< 0x00000004 */
#define SCFG_EXINTC1_EXINT0_GPE             SCFG_EXINTC1_EXINT0_GPE_Msk             /*!< GPIOE pin 0 */
#define SCFG_EXINTC1_EXINT0_GPF_Pos         (0U)
#define SCFG_EXINTC1_EXINT0_GPF_Msk         (0x5U << SCFG_EXINTC1_EXINT0_GPF_Pos)   /*!< 0x00000005 */
#define SCFG_EXINTC1_EXINT0_GPF             SCFG_EXINTC1_EXINT0_GPF_Msk             /*!< GPIOF pin 0 */
#define SCFG_EXINTC1_EXINT0_GPG_Pos         (0U)
#define SCFG_EXINTC1_EXINT0_GPG_Msk         (0x6U << SCFG_EXINTC1_EXINT0_GPG_Pos)   /*!< 0x00000006 */
#define SCFG_EXINTC1_EXINT0_GPG             SCFG_EXINTC1_EXINT0_GPG_Msk             /*!< GPIOG pin 0 */
#define SCFG_EXINTC1_EXINT0_GPH_Pos         (0U)
#define SCFG_EXINTC1_EXINT0_GPH_Msk         (0x7U << SCFG_EXINTC1_EXINT0_GPH_Pos)   /*!< 0x00000007 */
#define SCFG_EXINTC1_EXINT0_GPH             SCFG_EXINTC1_EXINT0_GPH_Msk             /*!< GPIOH pin 0 */

/*!< EXINT1 configuration */
#define SCFG_EXINTC1_EXINT1_Pos             (4U)
#define SCFG_EXINTC1_EXINT1_Msk             (0xFU << SCFG_EXINTC1_EXINT1_Pos)       /*!< 0x000000F0 */
#define SCFG_EXINTC1_EXINT1                 SCFG_EXINTC1_EXINT1_Msk                 /*!< EXINT1[3:0] bits (EXINT1 input source configuration) */

#define SCFG_EXINTC1_EXINT1_GPA             0x00000000U                             /*!< GPIOA pin 1 */
#define SCFG_EXINTC1_EXINT1_GPB_Pos         (4U)
#define SCFG_EXINTC1_EXINT1_GPB_Msk         (0x1U << SCFG_EXINTC1_EXINT1_GPB_Pos)   /*!< 0x00000010 */
#define SCFG_EXINTC1_EXINT1_GPB             SCFG_EXINTC1_EXINT1_GPB_Msk             /*!< GPIOB pin 1 */
#define SCFG_EXINTC1_EXINT1_GPC_Pos         (5U)
#define SCFG_EXINTC1_EXINT1_GPC_Msk         (0x1U << SCFG_EXINTC1_EXINT1_GPC_Pos)   /*!< 0x00000020 */
#define SCFG_EXINTC1_EXINT1_GPC             SCFG_EXINTC1_EXINT1_GPC_Msk             /*!< GPIOC pin 1 */
#define SCFG_EXINTC1_EXINT1_GPD_Pos         (4U)
#define SCFG_EXINTC1_EXINT1_GPD_Msk         (0x3U << SCFG_EXINTC1_EXINT1_GPD_Pos)   /*!< 0x00000030 */
#define SCFG_EXINTC1_EXINT1_GPD             SCFG_EXINTC1_EXINT1_GPD_Msk             /*!< GPIOD pin 1 */
#define SCFG_EXINTC1_EXINT1_GPE_Pos         (4U)
#define SCFG_EXINTC1_EXINT1_GPE_Msk         (0x4U << SCFG_EXINTC1_EXINT1_GPE_Pos)   /*!< 0x00000040 */
#define SCFG_EXINTC1_EXINT1_GPE             SCFG_EXINTC1_EXINT1_GPE_Msk             /*!< GPIOE pin 1 */
#define SCFG_EXINTC1_EXINT1_GPF_Pos         (4U)
#define SCFG_EXINTC1_EXINT1_GPF_Msk         (0x5U << SCFG_EXINTC1_EXINT1_GPF_Pos)   /*!< 0x00000050 */
#define SCFG_EXINTC1_EXINT1_GPF             SCFG_EXINTC1_EXINT1_GPF_Msk             /*!< GPIOF pin 1 */
#define SCFG_EXINTC1_EXINT1_GPG_Pos         (4U)
#define SCFG_EXINTC1_EXINT1_GPG_Msk         (0x6U << SCFG_EXINTC1_EXINT1_GPG_Pos)   /*!< 0x00000060 */
#define SCFG_EXINTC1_EXINT1_GPG             SCFG_EXINTC1_EXINT1_GPG_Msk             /*!< GPIOG pin 1 */
#define SCFG_EXINTC1_EXINT1_GPH_Pos         (4U)
#define SCFG_EXINTC1_EXINT1_GPH_Msk         (0x7U << SCFG_EXINTC1_EXINT1_GPH_Pos)   /*!< 0x00000060 */
#define SCFG_EXINTC1_EXINT1_GPH             SCFG_EXINTC1_EXINT1_GPH_Msk             /*!< GPIOH pin 1 */

/*!< EXINT2 configuration */
#define SCFG_EXINTC1_EXINT2_Pos             (8U)
#define SCFG_EXINTC1_EXINT2_Msk             (0xFU << SCFG_EXINTC1_EXINT2_Pos)       /*!< 0x00000F00 */
#define SCFG_EXINTC1_EXINT2                 SCFG_EXINTC1_EXINT2_Msk                 /*!< EXINT2[3:0] bits (EXINT2 input source configuration) */

#define SCFG_EXINTC1_EXINT2_GPA             0x00000000U                             /*!< GPIOA pin 2 */
#define SCFG_EXINTC1_EXINT2_GPB_Pos         (8U)
#define SCFG_EXINTC1_EXINT2_GPB_Msk         (0x1U << SCFG_EXINTC1_EXINT2_GPB_Pos)   /*!< 0x00000100 */
#define SCFG_EXINTC1_EXINT2_GPB             SCFG_EXINTC1_EXINT2_GPB_Msk             /*!< GPIOB pin 2 */
#define SCFG_EXINTC1_EXINT2_GPC_Pos         (9U)
#define SCFG_EXINTC1_EXINT2_GPC_Msk         (0x1U << SCFG_EXINTC1_EXINT2_GPC_Pos)   /*!< 0x00000200 */
#define SCFG_EXINTC1_EXINT2_GPC             SCFG_EXINTC1_EXINT2_GPC_Msk             /*!< GPIOC pin 2 */
#define SCFG_EXINTC1_EXINT2_GPD_Pos         (8U)
#define SCFG_EXINTC1_EXINT2_GPD_Msk         (0x3U << SCFG_EXINTC1_EXINT2_GPD_Pos)   /*!< 0x00000300 */
#define SCFG_EXINTC1_EXINT2_GPD             SCFG_EXINTC1_EXINT2_GPD_Msk             /*!< GPIOD pin 2 */
#define SCFG_EXINTC1_EXINT2_GPE_Pos         (8U)
#define SCFG_EXINTC1_EXINT2_GPE_Msk         (0x4U << SCFG_EXINTC1_EXINT2_GPE_Pos)   /*!< 0x00000400 */
#define SCFG_EXINTC1_EXINT2_GPE             SCFG_EXINTC1_EXINT2_GPE_Msk             /*!< GPIOE pin 2 */
#define SCFG_EXINTC1_EXINT2_GPF_Pos         (8U)
#define SCFG_EXINTC1_EXINT2_GPF_Msk         (0x5U << SCFG_EXINTC1_EXINT2_GPF_Pos)   /*!< 0x00000500 */
#define SCFG_EXINTC1_EXINT2_GPF             SCFG_EXINTC1_EXINT2_GPF_Msk             /*!< GPIOF pin 2 */
#define SCFG_EXINTC1_EXINT2_GPG_Pos         (8U)
#define SCFG_EXINTC1_EXINT2_GPG_Msk         (0x6U << SCFG_EXINTC1_EXINT2_GPG_Pos)   /*!< 0x00000600 */
#define SCFG_EXINTC1_EXINT2_GPG             SCFG_EXINTC1_EXINT2_GPG_Msk             /*!< GPIOG pin 2 */
#define SCFG_EXINTC1_EXINT2_GPH_Pos         (8U)
#define SCFG_EXINTC1_EXINT2_GPH_Msk         (0x7U << SCFG_EXINTC1_EXINT2_GPH_Pos)   /*!< 0x00000700 */
#define SCFG_EXINTC1_EXINT2_GPH             SCFG_EXINTC1_EXINT2_GPH_Msk             /*!< GPIOH pin 2 */

/*!< EXINT3 configuration */
#define SCFG_EXINTC1_EXINT3_Pos             (12U)
#define SCFG_EXINTC1_EXINT3_Msk             (0xFU << SCFG_EXINTC1_EXINT3_Pos)       /*!< 0x0000F000 */
#define SCFG_EXINTC1_EXINT3                 SCFG_EXINTC1_EXINT3_Msk                 /*!< EXINT3[3:0] bits (EXINT3 input source configuration) */

#define SCFG_EXINTC1_EXINT3_GPA             0x00000000U                             /*!< GPIOA pin 3 */
#define SCFG_EXINTC1_EXINT3_GPB_Pos         (12U)
#define SCFG_EXINTC1_EXINT3_GPB_Msk         (0x1U << SCFG_EXINTC1_EXINT3_GPB_Pos)   /*!< 0x00001000 */
#define SCFG_EXINTC1_EXINT3_GPB             SCFG_EXINTC1_EXINT3_GPB_Msk             /*!< GPIOB pin 3 */
#define SCFG_EXINTC1_EXINT3_GPC_Pos         (13U)
#define SCFG_EXINTC1_EXINT3_GPC_Msk         (0x1U << SCFG_EXINTC1_EXINT3_GPC_Pos)   /*!< 0x00002000 */
#define SCFG_EXINTC1_EXINT3_GPC             SCFG_EXINTC1_EXINT3_GPC_Msk             /*!< GPIOC pin 3 */
#define SCFG_EXINTC1_EXINT3_GPD_Pos         (12U)
#define SCFG_EXINTC1_EXINT3_GPD_Msk         (0x3U << SCFG_EXINTC1_EXINT3_GPD_Pos)   /*!< 0x00003000 */
#define SCFG_EXINTC1_EXINT3_GPD             SCFG_EXINTC1_EXINT3_GPD_Msk             /*!< GPIOD pin 3 */
#define SCFG_EXINTC1_EXINT3_GPE_Pos         (12U)
#define SCFG_EXINTC1_EXINT3_GPE_Msk         (0x4U << SCFG_EXINTC1_EXINT3_GPE_Pos)   /*!< 0x00004000 */
#define SCFG_EXINTC1_EXINT3_GPE             SCFG_EXINTC1_EXINT3_GPE_Msk             /*!< GPIOE pin 3 */
#define SCFG_EXINTC1_EXINT3_GPF_Pos         (12U)
#define SCFG_EXINTC1_EXINT3_GPF_Msk         (0x5U << SCFG_EXINTC1_EXINT3_GPF_Pos)   /*!< 0x00005000 */
#define SCFG_EXINTC1_EXINT3_GPF             SCFG_EXINTC1_EXINT3_GPF_Msk             /*!< GPIOF pin 3 */
#define SCFG_EXINTC1_EXINT3_GPG_Pos         (12U)
#define SCFG_EXINTC1_EXINT3_GPG_Msk         (0x6U << SCFG_EXINTC1_EXINT3_GPG_Pos)   /*!< 0x00006000 */
#define SCFG_EXINTC1_EXINT3_GPG             SCFG_EXINTC1_EXINT3_GPG_Msk             /*!< GPIOG pin 3 */
#define SCFG_EXINTC1_EXINT3_GPH_Pos         (12U)
#define SCFG_EXINTC1_EXINT3_GPH_Msk         (0x7U << SCFG_EXINTC1_EXINT3_GPH_Pos)   /*!< 0x00007000 */
#define SCFG_EXINTC1_EXINT3_GPH             SCFG_EXINTC1_EXINT3_GPH_Msk             /*!< GPIOH pin 3 */

/*****************  Bit definition for SCFG_EXINTC2 register  *****************/
/*!< EXINT4 configuration */
#define SCFG_EXINTC2_EXINT4_Pos             (0U)
#define SCFG_EXINTC2_EXINT4_Msk             (0xFU << SCFG_EXINTC2_EXINT4_Pos)       /*!< 0x0000000F */
#define SCFG_EXINTC2_EXINT4                 SCFG_EXINTC2_EXINT4_Msk                 /*!< EXINT4[3:0] bits (EXINT4 input source configuration) */

#define SCFG_EXINTC2_EXINT4_GPA             0x00000000U                             /*!< GPIOA pin 4 */
#define SCFG_EXINTC2_EXINT4_GPB_Pos         (0U)
#define SCFG_EXINTC2_EXINT4_GPB_Msk         (0x1U << SCFG_EXINTC2_EXINT4_GPB_Pos)   /*!< 0x00000001 */
#define SCFG_EXINTC2_EXINT4_GPB             SCFG_EXINTC2_EXINT4_GPB_Msk             /*!< GPIOB pin 4 */
#define SCFG_EXINTC2_EXINT4_GPC_Pos         (1U)
#define SCFG_EXINTC2_EXINT4_GPC_Msk         (0x1U << SCFG_EXINTC2_EXINT4_GPC_Pos)   /*!< 0x00000002 */
#define SCFG_EXINTC2_EXINT4_GPC             SCFG_EXINTC2_EXINT4_GPC_Msk             /*!< GPIOC pin 4 */
#define SCFG_EXINTC2_EXINT4_GPD_Pos         (0U)
#define SCFG_EXINTC2_EXINT4_GPD_Msk         (0x3U << SCFG_EXINTC2_EXINT4_GPD_Pos)   /*!< 0x00000003 */
#define SCFG_EXINTC2_EXINT4_GPD             SCFG_EXINTC2_EXINT4_GPD_Msk             /*!< GPIOD pin 4 */
#define SCFG_EXINTC2_EXINT4_GPE_Pos         (0U)
#define SCFG_EXINTC2_EXINT4_GPE_Msk         (0x4U << SCFG_EXINTC2_EXINT4_GPE_Pos)   /*!< 0x00000004 */
#define SCFG_EXINTC2_EXINT4_GPE             SCFG_EXINTC2_EXINT4_GPE_Msk             /*!< GPIOE pin 4 */
#define SCFG_EXINTC2_EXINT4_GPF_Pos         (0U)
#define SCFG_EXINTC2_EXINT4_GPF_Msk         (0x5U << SCFG_EXINTC2_EXINT4_GPF_Pos)   /*!< 0x00000005 */
#define SCFG_EXINTC2_EXINT4_GPF             SCFG_EXINTC2_EXINT4_GPF_Msk             /*!< GPIOF pin 4 */
#define SCFG_EXINTC2_EXINT4_GPG_Pos         (0U)
#define SCFG_EXINTC2_EXINT4_GPG_Msk         (0x6U << SCFG_EXINTC2_EXINT4_GPG_Pos)   /*!< 0x00000006 */
#define SCFG_EXINTC2_EXINT4_GPG             SCFG_EXINTC2_EXINT4_GPG_Msk             /*!< GPIOG pin 4 */
#define SCFG_EXINTC2_EXINT4_GPH_Pos         (0U)
#define SCFG_EXINTC2_EXINT4_GPH_Msk         (0x7U << SCFG_EXINTC2_EXINT4_GPH_Pos)   /*!< 0x00000007 */
#define SCFG_EXINTC2_EXINT4_GPH             SCFG_EXINTC2_EXINT4_GPH_Msk             /*!< GPIOH pin 4 */

/* EXINT5 configuration */
#define SCFG_EXINTC2_EXINT5_Pos             (4U)
#define SCFG_EXINTC2_EXINT5_Msk             (0xFU << SCFG_EXINTC2_EXINT5_Pos)       /*!< 0x000000F0 */
#define SCFG_EXINTC2_EXINT5                 SCFG_EXINTC2_EXINT5_Msk                 /*!< EXINT5[3:0] bits (EXINT5 input source configuration) */

#define SCFG_EXINTC2_EXINT5_GPA             0x00000000U                             /*!< GPIOA pin 5 */
#define SCFG_EXINTC2_EXINT5_GPB_Pos         (4U)
#define SCFG_EXINTC2_EXINT5_GPB_Msk         (0x1U << SCFG_EXINTC2_EXINT5_GPB_Pos)   /*!< 0x00000010 */
#define SCFG_EXINTC2_EXINT5_GPB             SCFG_EXINTC2_EXINT5_GPB_Msk             /*!< GPIOB pin 5 */
#define SCFG_EXINTC2_EXINT5_GPC_Pos         (5U)
#define SCFG_EXINTC2_EXINT5_GPC_Msk         (0x1U << SCFG_EXINTC2_EXINT5_GPC_Pos)   /*!< 0x00000020 */
#define SCFG_EXINTC2_EXINT5_GPC             SCFG_EXINTC2_EXINT5_GPC_Msk             /*!< GPIOC pin 5 */
#define SCFG_EXINTC2_EXINT5_GPD_Pos         (4U)
#define SCFG_EXINTC2_EXINT5_GPD_Msk         (0x3U << SCFG_EXINTC2_EXINT5_GPD_Pos)   /*!< 0x00000030 */
#define SCFG_EXINTC2_EXINT5_GPD             SCFG_EXINTC2_EXINT5_GPD_Msk             /*!< GPIOD pin 5 */
#define SCFG_EXINTC2_EXINT5_GPE_Pos         (4U)
#define SCFG_EXINTC2_EXINT5_GPE_Msk         (0x4U << SCFG_EXINTC2_EXINT5_GPE_Pos)   /*!< 0x00000040 */
#define SCFG_EXINTC2_EXINT5_GPE             SCFG_EXINTC2_EXINT5_GPE_Msk             /*!< GPIOD pin 5 */
#define SCFG_EXINTC2_EXINT5_GPF_Pos         (4U)
#define SCFG_EXINTC2_EXINT5_GPF_Msk         (0x5U << SCFG_EXINTC2_EXINT5_GPF_Pos)   /*!< 0x00000050 */
#define SCFG_EXINTC2_EXINT5_GPF             SCFG_EXINTC2_EXINT5_GPF_Msk             /*!< GPIOF pin 5 */
#define SCFG_EXINTC2_EXINT5_GPG_Pos         (4U)
#define SCFG_EXINTC2_EXINT5_GPG_Msk         (0x6U << SCFG_EXINTC2_EXINT5_GPG_Pos)   /*!< 0x00000060 */
#define SCFG_EXINTC2_EXINT5_GPG             SCFG_EXINTC2_EXINT5_GPG_Msk             /*!< GPIOF pin 5 */
#define SCFG_EXINTC2_EXINT5_GPH_Pos         (4U)
#define SCFG_EXINTC2_EXINT5_GPH_Msk         (0x7U << SCFG_EXINTC2_EXINT5_GPH_Pos)   /*!< 0x00000070 */
#define SCFG_EXINTC2_EXINT5_GPH             SCFG_EXINTC2_EXINT5_GPH_Msk             /*!< GPIOF pin 5 */

/*!< EXINT6 configuration */
#define SCFG_EXINTC2_EXINT6_Pos             (8U)
#define SCFG_EXINTC2_EXINT6_Msk             (0xFU << SCFG_EXINTC2_EXINT6_Pos)       /*!< 0x00000F00 */
#define SCFG_EXINTC2_EXINT6                 SCFG_EXINTC2_EXINT6_Msk                 /*!< EXINT6[3:0] bits (EXINT6 input source configuration) */

#define SCFG_EXINTC2_EXINT6_GPA             0x00000000U                             /*!< GPIOA pin 6 */
#define SCFG_EXINTC2_EXINT6_GPB_Pos         (8U)
#define SCFG_EXINTC2_EXINT6_GPB_Msk         (0x1U << SCFG_EXINTC2_EXINT6_GPB_Pos)   /*!< 0x00000100 */
#define SCFG_EXINTC2_EXINT6_GPB             SCFG_EXINTC2_EXINT6_GPB_Msk             /*!< GPIOB pin 6 */
#define SCFG_EXINTC2_EXINT6_GPC_Pos         (9U)
#define SCFG_EXINTC2_EXINT6_GPC_Msk         (0x1U << SCFG_EXINTC2_EXINT6_GPC_Pos)   /*!< 0x00000200 */
#define SCFG_EXINTC2_EXINT6_GPC             SCFG_EXINTC2_EXINT6_GPC_Msk             /*!< GPIOC pin 6 */
#define SCFG_EXINTC2_EXINT6_GPD_Pos         (8U)
#define SCFG_EXINTC2_EXINT6_GPD_Msk         (0x3U << SCFG_EXINTC2_EXINT6_GPD_Pos)   /*!< 0x00000300 */
#define SCFG_EXINTC2_EXINT6_GPD             SCFG_EXINTC2_EXINT6_GPD_Msk             /*!< GPIOD pin 6 */
#define SCFG_EXINTC2_EXINT6_GPE_Pos         (8U)
#define SCFG_EXINTC2_EXINT6_GPE_Msk         (0x4U << SCFG_EXINTC2_EXINT6_GPE_Pos)   /*!< 0x00000400 */
#define SCFG_EXINTC2_EXINT6_GPE             SCFG_EXINTC2_EXINT6_GPE_Msk             /*!< GPIOD pin 6 */
#define SCFG_EXINTC2_EXINT6_GPF_Pos         (8U)
#define SCFG_EXINTC2_EXINT6_GPF_Msk         (0x5U << SCFG_EXINTC2_EXINT6_GPF_Pos)   /*!< 0x00000500 */
#define SCFG_EXINTC2_EXINT6_GPF             SCFG_EXINTC2_EXINT6_GPF_Msk             /*!< GPIOF pin 6 */
#define SCFG_EXINTC2_EXINT6_GPG_Pos         (8U)
#define SCFG_EXINTC2_EXINT6_GPG_Msk         (0x6U << SCFG_EXINTC2_EXINT6_GPG_Pos)   /*!< 0x00000600 */
#define SCFG_EXINTC2_EXINT6_GPG             SCFG_EXINTC2_EXINT6_GPG_Msk             /*!< GPIOD pin 6 */
#define SCFG_EXINTC2_EXINT6_GPH_Pos         (8U)
#define SCFG_EXINTC2_EXINT6_GPH_Msk         (0x7U << SCFG_EXINTC2_EXINT6_GPH_Pos)   /*!< 0x00000700 */
#define SCFG_EXINTC2_EXINT6_GPH             SCFG_EXINTC2_EXINT6_GPH_Msk             /*!< GPIOD pin 6 */

/*!< EXINT7 configuration */
#define SCFG_EXINTC2_EXINT7_Pos             (12U)
#define SCFG_EXINTC2_EXINT7_Msk             (0xFU << SCFG_EXINTC2_EXINT7_Pos)       /*!< 0x0000F000 */
#define SCFG_EXINTC2_EXINT7                 SCFG_EXINTC2_EXINT7_Msk                 /*!< EXINT7[3:0] bits (EXINT7 input source configuration) */

#define SCFG_EXINTC2_EXINT7_GPA             0x00000000U                             /*!< GPIOA pin 7 */
#define SCFG_EXINTC2_EXINT7_GPB_Pos         (12U)
#define SCFG_EXINTC2_EXINT7_GPB_Msk         (0x1U << SCFG_EXINTC2_EXINT7_GPB_Pos)   /*!< 0x00001000 */
#define SCFG_EXINTC2_EXINT7_GPB             SCFG_EXINTC2_EXINT7_GPB_Msk             /*!< GPIOB pin 7 */
#define SCFG_EXINTC2_EXINT7_GPC_Pos         (13U)
#define SCFG_EXINTC2_EXINT7_GPC_Msk         (0x1U << SCFG_EXINTC2_EXINT7_GPC_Pos)   /*!< 0x00002000 */
#define SCFG_EXINTC2_EXINT7_GPC             SCFG_EXINTC2_EXINT7_GPC_Msk             /*!< GPIOC pin 7 */
#define SCFG_EXINTC2_EXINT7_GPD_Pos         (12U)
#define SCFG_EXINTC2_EXINT7_GPD_Msk         (0x3U << SCFG_EXINTC2_EXINT7_GPD_Pos)   /*!< 0x00003000 */
#define SCFG_EXINTC2_EXINT7_GPD             SCFG_EXINTC2_EXINT7_GPD_Msk             /*!< GPIOD pin 7 */
#define SCFG_EXINTC2_EXINT7_GPE_Pos         (12U)
#define SCFG_EXINTC2_EXINT7_GPE_Msk         (0x4U << SCFG_EXINTC2_EXINT7_GPE_Pos)   /*!< 0x00004000 */
#define SCFG_EXINTC2_EXINT7_GPE             SCFG_EXINTC2_EXINT7_GPE_Msk             /*!< GPIOD pin 7 */
#define SCFG_EXINTC2_EXINT7_GPF_Pos         (12U)
#define SCFG_EXINTC2_EXINT7_GPF_Msk         (0x5U << SCFG_EXINTC2_EXINT7_GPF_Pos)   /*!< 0x00005000 */
#define SCFG_EXINTC2_EXINT7_GPF             SCFG_EXINTC2_EXINT7_GPF_Msk             /*!< GPIOF pin 7 */
#define SCFG_EXINTC2_EXINT7_GPG_Pos         (12U)
#define SCFG_EXINTC2_EXINT7_GPG_Msk         (0x6U << SCFG_EXINTC2_EXINT7_GPG_Pos)   /*!< 0x00006000 */
#define SCFG_EXINTC2_EXINT7_GPG             SCFG_EXINTC2_EXINT7_GPG_Msk             /*!< GPIOF pin 7 */
#define SCFG_EXINTC2_EXINT7_GPH_Pos         (12U)
#define SCFG_EXINTC2_EXINT7_GPH_Msk         (0x7U << SCFG_EXINTC2_EXINT7_GPH_Pos)   /*!< 0x00007000 */
#define SCFG_EXINTC2_EXINT7_GPH             SCFG_EXINTC2_EXINT7_GPH_Msk             /*!< GPIOF pin 7 */

/*****************  Bit definition for SCFG_EXINTC3 register  *****************/
/*!< EXINT8 configuration */
#define SCFG_EXINTC3_EXINT8_Pos             (0U)
#define SCFG_EXINTC3_EXINT8_Msk             (0xFU << SCFG_EXINTC3_EXINT8_Pos)       /*!< 0x0000000F */
#define SCFG_EXINTC3_EXINT8                 SCFG_EXINTC3_EXINT8_Msk                 /*!< EXINT8[3:0] bits (EXINT8 input source configuration) */

#define SCFG_EXINTC3_EXINT8_GPA             0x00000000U                             /*!< GPIOA pin 8 */
#define SCFG_EXINTC3_EXINT8_GPB_Pos         (0U)
#define SCFG_EXINTC3_EXINT8_GPB_Msk         (0x1U << SCFG_EXINTC3_EXINT8_GPB_Pos)   /*!< 0x00000001 */
#define SCFG_EXINTC3_EXINT8_GPB             SCFG_EXINTC3_EXINT8_GPB_Msk             /*!< GPIOB pin 8 */
#define SCFG_EXINTC3_EXINT8_GPC_Pos         (1U)
#define SCFG_EXINTC3_EXINT8_GPC_Msk         (0x1U << SCFG_EXINTC3_EXINT8_GPC_Pos)   /*!< 0x00000002 */
#define SCFG_EXINTC3_EXINT8_GPC             SCFG_EXINTC3_EXINT8_GPC_Msk             /*!< GPIOC pin 8 */
#define SCFG_EXINTC3_EXINT8_GPD_Pos         (0U)
#define SCFG_EXINTC3_EXINT8_GPD_Msk         (0x3U << SCFG_EXINTC3_EXINT8_GPD_Pos)   /*!< 0x00000003 */
#define SCFG_EXINTC3_EXINT8_GPD             SCFG_EXINTC3_EXINT8_GPD_Msk             /*!< GPIOD pin 8 */
#define SCFG_EXINTC3_EXINT8_GPE_Pos         (0U)
#define SCFG_EXINTC3_EXINT8_GPE_Msk         (0x4U << SCFG_EXINTC3_EXINT8_GPE_Pos)   /*!< 0x00000004 */
#define SCFG_EXINTC3_EXINT8_GPE             SCFG_EXINTC3_EXINT8_GPE_Msk             /*!< GPIOD pin 8 */
#define SCFG_EXINTC3_EXINT8_GPF_Pos         (0U)
#define SCFG_EXINTC3_EXINT8_GPF_Msk         (0x5U << SCFG_EXINTC3_EXINT8_GPF_Pos)   /*!< 0x00000005 */
#define SCFG_EXINTC3_EXINT8_GPF             SCFG_EXINTC3_EXINT8_GPF_Msk             /*!< GPIOF pin 8 */
#define SCFG_EXINTC3_EXINT8_GPG_Pos         (0U)
#define SCFG_EXINTC3_EXINT8_GPG_Msk         (0x6U << SCFG_EXINTC3_EXINT8_GPG_Pos)   /*!< 0x00000006 */
#define SCFG_EXINTC3_EXINT8_GPG             SCFG_EXINTC3_EXINT8_GPG_Msk             /*!< GPIOF pin 8 */
#define SCFG_EXINTC3_EXINT8_GPH_Pos         (0U)
#define SCFG_EXINTC3_EXINT8_GPH_Msk         (0x7U << SCFG_EXINTC3_EXINT8_GPH_Pos)   /*!< 0x00000007 */
#define SCFG_EXINTC3_EXINT8_GPH             SCFG_EXINTC3_EXINT8_GPH_Msk             /*!< GPIOF pin 8 */

/*!< EXINT9 configuration */
#define SCFG_EXINTC3_EXINT9_Pos             (4U)
#define SCFG_EXINTC3_EXINT9_Msk             (0xFU << SCFG_EXINTC3_EXINT9_Pos)       /*!< 0x000000F0 */
#define SCFG_EXINTC3_EXINT9                 SCFG_EXINTC3_EXINT9_Msk                 /*!< EXINT9[3:0] bits (EXINT9 input source configuration) */

#define SCFG_EXINTC3_EXINT9_GPA             0x00000000U                             /*!< GPIOA pin 9 */
#define SCFG_EXINTC3_EXINT9_GPB_Pos         (4U)
#define SCFG_EXINTC3_EXINT9_GPB_Msk         (0x1U << SCFG_EXINTC3_EXINT9_GPB_Pos)   /*!< 0x00000010 */
#define SCFG_EXINTC3_EXINT9_GPB             SCFG_EXINTC3_EXINT9_GPB_Msk             /*!< GPIOB pin 9 */
#define SCFG_EXINTC3_EXINT9_GPC_Pos         (5U)
#define SCFG_EXINTC3_EXINT9_GPC_Msk         (0x1U << SCFG_EXINTC3_EXINT9_GPC_Pos)   /*!< 0x00000020 */
#define SCFG_EXINTC3_EXINT9_GPC             SCFG_EXINTC3_EXINT9_GPC_Msk             /*!< GPIOC pin 9 */
#define SCFG_EXINTC3_EXINT9_GPD_Pos         (4U)
#define SCFG_EXINTC3_EXINT9_GPD_Msk         (0x3U << SCFG_EXINTC3_EXINT9_GPD_Pos)   /*!< 0x00000030 */
#define SCFG_EXINTC3_EXINT9_GPD             SCFG_EXINTC3_EXINT9_GPD_Msk             /*!< GPIOD pin 9 */
#define SCFG_EXINTC3_EXINT9_GPE_Pos         (4U)
#define SCFG_EXINTC3_EXINT9_GPE_Msk         (0x4U << SCFG_EXINTC3_EXINT9_GPE_Pos)   /*!< 0x00000040 */
#define SCFG_EXINTC3_EXINT9_GPE             SCFG_EXINTC3_EXINT9_GPE_Msk             /*!< GPIOD pin 9 */
#define SCFG_EXINTC3_EXINT9_GPF_Pos         (4U)
#define SCFG_EXINTC3_EXINT9_GPF_Msk         (0x5U << SCFG_EXINTC3_EXINT9_GPF_Pos)   /*!< 0x00000050 */
#define SCFG_EXINTC3_EXINT9_GPF             SCFG_EXINTC3_EXINT9_GPF_Msk             /*!< GPIOF pin 9 */
#define SCFG_EXINTC3_EXINT9_GPG_Pos         (4U)
#define SCFG_EXINTC3_EXINT9_GPG_Msk         (0x6U << SCFG_EXINTC3_EXINT9_GPG_Pos)   /*!< 0x00000060 */
#define SCFG_EXINTC3_EXINT9_GPG             SCFG_EXINTC3_EXINT9_GPG_Msk             /*!< GPIOF pin 9 */
#define SCFG_EXINTC3_EXINT9_GPH_Pos         (4U)
#define SCFG_EXINTC3_EXINT9_GPH_Msk         (0x7U << SCFG_EXINTC3_EXINT9_GPH_Pos)   /*!< 0x00000070 */
#define SCFG_EXINTC3_EXINT9_GPH             SCFG_EXINTC3_EXINT9_GPH_Msk             /*!< GPIOF pin 9 */

/*!< EXINT10 configuration */
#define SCFG_EXINTC3_EXINT10_Pos            (8U)
#define SCFG_EXINTC3_EXINT10_Msk            (0xFU << SCFG_EXINTC3_EXINT10_Pos)      /*!< 0x00000F00 */
#define SCFG_EXINTC3_EXINT10                SCFG_EXINTC3_EXINT10_Msk                /*!< EXINT10[3:0] bits (EXINT10 input source configuration) */

#define SCFG_EXINTC3_EXINT10_GPA            0x00000000U                             /*!< GPIOA pin 10 */
#define SCFG_EXINTC3_EXINT10_GPB_Pos        (8U)
#define SCFG_EXINTC3_EXINT10_GPB_Msk        (0x1U << SCFG_EXINTC3_EXINT10_GPB_Pos)  /*!< 0x00000100 */
#define SCFG_EXINTC3_EXINT10_GPB            SCFG_EXINTC3_EXINT10_GPB_Msk            /*!< GPIOB pin 10 */
#define SCFG_EXINTC3_EXINT10_GPC_Pos        (9U)
#define SCFG_EXINTC3_EXINT10_GPC_Msk        (0x1U << SCFG_EXINTC3_EXINT10_GPC_Pos)  /*!< 0x00000200 */
#define SCFG_EXINTC3_EXINT10_GPC            SCFG_EXINTC3_EXINT10_GPC_Msk            /*!< GPIOC pin 10 */
#define SCFG_EXINTC3_EXINT10_GPD_Pos        (8U)
#define SCFG_EXINTC3_EXINT10_GPD_Msk        (0x3U << SCFG_EXINTC3_EXINT10_GPD_Pos)  /*!< 0x00000300 */
#define SCFG_EXINTC3_EXINT10_GPD            SCFG_EXINTC3_EXINT10_GPD_Msk            /*!< GPIOD pin 10 */
#define SCFG_EXINTC3_EXINT10_GPE_Pos        (8U)
#define SCFG_EXINTC3_EXINT10_GPE_Msk        (0x4U << SCFG_EXINTC3_EXINT10_GPE_Pos)  /*!< 0x00000400 */
#define SCFG_EXINTC3_EXINT10_GPE            SCFG_EXINTC3_EXINT10_GPE_Msk            /*!< GPIOD pin 10 */
#define SCFG_EXINTC3_EXINT10_GPF_Pos        (8U)
#define SCFG_EXINTC3_EXINT10_GPF_Msk        (0x5U << SCFG_EXINTC3_EXINT10_GPF_Pos)  /*!< 0x00000500 */
#define SCFG_EXINTC3_EXINT10_GPF            SCFG_EXINTC3_EXINT10_GPF_Msk            /*!< GPIOF pin 10 */
#define SCFG_EXINTC3_EXINT10_GPG_Pos        (8U)
#define SCFG_EXINTC3_EXINT10_GPG_Msk        (0x6U << SCFG_EXINTC3_EXINT10_GPG_Pos)  /*!< 0x00000600 */
#define SCFG_EXINTC3_EXINT10_GPG            SCFG_EXINTC3_EXINT10_GPG_Msk            /*!< GPIOF pin 10 */
#define SCFG_EXINTC3_EXINT10_GPH_Pos        (8U)
#define SCFG_EXINTC3_EXINT10_GPH_Msk        (0x7U << SCFG_EXINTC3_EXINT10_GPH_Pos)  /*!< 0x00000500 */
#define SCFG_EXINTC3_EXINT10_GPH            SCFG_EXINTC3_EXINT10_GPH_Msk            /*!< GPIOF pin 10 */

/*!< EXINT11 configuration */
#define SCFG_EXINTC3_EXINT11_Pos            (12U)
#define SCFG_EXINTC3_EXINT11_Msk            (0xFU << SCFG_EXINTC3_EXINT11_Pos)      /*!< 0x0000F000 */
#define SCFG_EXINTC3_EXINT11                SCFG_EXINTC3_EXINT11_Msk                /*!< EXINT11[3:0] bits (EXINT11 input source configuration) */

#define SCFG_EXINTC3_EXINT11_GPA            0x00000000U                             /*!< GPIOA pin 11 */
#define SCFG_EXINTC3_EXINT11_GPB_Pos        (12U)
#define SCFG_EXINTC3_EXINT11_GPB_Msk        (0x1U << SCFG_EXINTC3_EXINT11_GPB_Pos)  /*!< 0x00001000 */
#define SCFG_EXINTC3_EXINT11_GPB            SCFG_EXINTC3_EXINT11_GPB_Msk            /*!< GPIOB pin 11 */
#define SCFG_EXINTC3_EXINT11_GPC_Pos        (13U)
#define SCFG_EXINTC3_EXINT11_GPC_Msk        (0x1U << SCFG_EXINTC3_EXINT11_GPC_Pos)  /*!< 0x00002000 */
#define SCFG_EXINTC3_EXINT11_GPC            SCFG_EXINTC3_EXINT11_GPC_Msk            /*!< GPIOC pin 11 */
#define SCFG_EXINTC3_EXINT11_GPD_Pos        (12U)
#define SCFG_EXINTC3_EXINT11_GPD_Msk        (0x3U << SCFG_EXINTC3_EXINT11_GPD_Pos)  /*!< 0x00003000 */
#define SCFG_EXINTC3_EXINT11_GPD            SCFG_EXINTC3_EXINT11_GPD_Msk            /*!< GPIOD pin 11 */
#define SCFG_EXINTC3_EXINT11_GPE_Pos        (12U)
#define SCFG_EXINTC3_EXINT11_GPE_Msk        (0x4U << SCFG_EXINTC3_EXINT11_GPE_Pos)  /*!< 0x00004000 */
#define SCFG_EXINTC3_EXINT11_GPE            SCFG_EXINTC3_EXINT11_GPE_Msk            /*!< GPIOD pin 11 */
#define SCFG_EXINTC3_EXINT11_GPF_Pos        (12U)
#define SCFG_EXINTC3_EXINT11_GPF_Msk        (0x5U << SCFG_EXINTC3_EXINT11_GPF_Pos)  /*!< 0x00005000 */
#define SCFG_EXINTC3_EXINT11_GPF            SCFG_EXINTC3_EXINT11_GPF_Msk            /*!< GPIOF pin 11 */
#define SCFG_EXINTC3_EXINT11_GPG_Pos        (12U)
#define SCFG_EXINTC3_EXINT11_GPG_Msk        (0x6U << SCFG_EXINTC3_EXINT11_GPG_Pos)  /*!< 0x00006000 */
#define SCFG_EXINTC3_EXINT11_GPG            SCFG_EXINTC3_EXINT11_GPG_Msk            /*!< GPIOF pin 11 */
#define SCFG_EXINTC3_EXINT11_GPH_Pos        (12U)
#define SCFG_EXINTC3_EXINT11_GPH_Msk        (0x7U << SCFG_EXINTC3_EXINT11_GPH_Pos)  /*!< 0x00007000 */
#define SCFG_EXINTC3_EXINT11_GPH            SCFG_EXINTC3_EXINT11_GPH_Msk            /*!< GPIOF pin 11 */

/*****************  Bit definition for SCFG_EXINTC4 register  *****************/
/* EXINT12 configuration */
#define SCFG_EXINTC4_EXINT12_Pos            (0U)
#define SCFG_EXINTC4_EXINT12_Msk            (0xFU << SCFG_EXINTC4_EXINT12_Pos)      /*!< 0x0000000F */
#define SCFG_EXINTC4_EXINT12                SCFG_EXINTC4_EXINT12_Msk                /*!< EXINT12[3:0] bits (EXINT12 input source configuration) */

#define SCFG_EXINTC4_EXINT12_GPA            0x00000000U                             /*!< GPIOA pin 12 */
#define SCFG_EXINTC4_EXINT12_GPB_Pos        (0U)
#define SCFG_EXINTC4_EXINT12_GPB_Msk        (0x1U << SCFG_EXINTC4_EXINT12_GPB_Pos)  /*!< 0x00000001 */
#define SCFG_EXINTC4_EXINT12_GPB            SCFG_EXINTC4_EXINT12_GPB_Msk            /*!< GPIOB pin 12 */
#define SCFG_EXINTC4_EXINT12_GPC_Pos        (1U)
#define SCFG_EXINTC4_EXINT12_GPC_Msk        (0x1U << SCFG_EXINTC4_EXINT12_GPC_Pos)  /*!< 0x00000002 */
#define SCFG_EXINTC4_EXINT12_GPC            SCFG_EXINTC4_EXINT12_GPC_Msk            /*!< GPIOC pin 12 */
#define SCFG_EXINTC4_EXINT12_GPD_Pos        (0U)
#define SCFG_EXINTC4_EXINT12_GPD_Msk        (0x3U << SCFG_EXINTC4_EXINT12_GPD_Pos)  /*!< 0x00000003 */
#define SCFG_EXINTC4_EXINT12_GPD            SCFG_EXINTC4_EXINT12_GPD_Msk            /*!< GPIOD pin 12 */
#define SCFG_EXINTC4_EXINT12_GPE_Pos        (0U)
#define SCFG_EXINTC4_EXINT12_GPE_Msk        (0x4U << SCFG_EXINTC4_EXINT12_GPE_Pos)  /*!< 0x00000004 */
#define SCFG_EXINTC4_EXINT12_GPE            SCFG_EXINTC4_EXINT12_GPE_Msk            /*!< GPIOD pin 12 */
#define SCFG_EXINTC4_EXINT12_GPF_Pos        (0U)
#define SCFG_EXINTC4_EXINT12_GPF_Msk        (0x5U << SCFG_EXINTC4_EXINT12_GPF_Pos)  /*!< 0x00000005 */
#define SCFG_EXINTC4_EXINT12_GPF            SCFG_EXINTC4_EXINT12_GPF_Msk            /*!< GPIOF pin 12 */
#define SCFG_EXINTC4_EXINT12_GPG_Pos        (0U)
#define SCFG_EXINTC4_EXINT12_GPG_Msk        (0x6U << SCFG_EXINTC4_EXINT12_GPG_Pos)  /*!< 0x00000006 */
#define SCFG_EXINTC4_EXINT12_GPG            SCFG_EXINTC4_EXINT12_GPG_Msk            /*!< GPIOF pin 12 */
#define SCFG_EXINTC4_EXINT12_GPH_Pos        (0U)
#define SCFG_EXINTC4_EXINT12_GPH_Msk        (0x7U << SCFG_EXINTC4_EXINT12_GPH_Pos)  /*!< 0x00000007 */
#define SCFG_EXINTC4_EXINT12_GPH            SCFG_EXINTC4_EXINT12_GPH_Msk            /*!< GPIOF pin 12 */

/* EXINT13 configuration */
#define SCFG_EXINTC4_EXINT13_Pos            (4U)
#define SCFG_EXINTC4_EXINT13_Msk            (0xFU << SCFG_EXINTC4_EXINT13_Pos)      /*!< 0x000000F0 */
#define SCFG_EXINTC4_EXINT13                SCFG_EXINTC4_EXINT13_Msk                /*!< EXINT13[3:0] bits (EXINT13 input source configuration) */

#define SCFG_EXINTC4_EXINT13_GPA            0x00000000U                             /*!< GPIOA pin 13 */
#define SCFG_EXINTC4_EXINT13_GPB_Pos        (4U)
#define SCFG_EXINTC4_EXINT13_GPB_Msk        (0x1U << SCFG_EXINTC4_EXINT13_GPB_Pos)  /*!< 0x00000010 */
#define SCFG_EXINTC4_EXINT13_GPB            SCFG_EXINTC4_EXINT13_GPB_Msk            /*!< GPIOB pin 13 */
#define SCFG_EXINTC4_EXINT13_GPC_Pos        (5U)
#define SCFG_EXINTC4_EXINT13_GPC_Msk        (0x1U << SCFG_EXINTC4_EXINT13_GPC_Pos)  /*!< 0x00000020 */
#define SCFG_EXINTC4_EXINT13_GPC            SCFG_EXINTC4_EXINT13_GPC_Msk            /*!< GPIOC pin 13 */
#define SCFG_EXINTC4_EXINT13_GPD_Pos        (4U)
#define SCFG_EXINTC4_EXINT13_GPD_Msk        (0x3U << SCFG_EXINTC4_EXINT13_GPD_Pos)  /*!< 0x00000030 */
#define SCFG_EXINTC4_EXINT13_GPD            SCFG_EXINTC4_EXINT13_GPD_Msk            /*!< GPIOD pin 13 */
#define SCFG_EXINTC4_EXINT13_GPE_Pos        (4U)
#define SCFG_EXINTC4_EXINT13_GPE_Msk        (0x4U << SCFG_EXINTC4_EXINT13_GPE_Pos)  /*!< 0x00000040 */
#define SCFG_EXINTC4_EXINT13_GPE            SCFG_EXINTC4_EXINT13_GPE_Msk            /*!< GPIOD pin 13 */
#define SCFG_EXINTC4_EXINT13_GPF_Pos        (4U)
#define SCFG_EXINTC4_EXINT13_GPF_Msk        (0x5U << SCFG_EXINTC4_EXINT13_GPF_Pos)  /*!< 0x00000050 */
#define SCFG_EXINTC4_EXINT13_GPF            SCFG_EXINTC4_EXINT13_GPF_Msk            /*!< GPIOF pin 13 */
#define SCFG_EXINTC4_EXINT13_GPG_Pos        (4U)
#define SCFG_EXINTC4_EXINT13_GPG_Msk        (0x6U << SCFG_EXINTC4_EXINT13_GPG_Pos)  /*!< 0x00000060 */
#define SCFG_EXINTC4_EXINT13_GPG            SCFG_EXINTC4_EXINT13_GPG_Msk            /*!< GPIOF pin 13 */
#define SCFG_EXINTC4_EXINT13_GPH_Pos        (4U)
#define SCFG_EXINTC4_EXINT13_GPH_Msk        (0x7U << SCFG_EXINTC4_EXINT13_GPH_Pos)  /*!< 0x00000070 */
#define SCFG_EXINTC4_EXINT13_GPH            SCFG_EXINTC4_EXINT13_GPH_Msk            /*!< GPIOF pin 13 */

/*!< EXINT14 configuration */
#define SCFG_EXINTC4_EXINT14_Pos            (8U)
#define SCFG_EXINTC4_EXINT14_Msk            (0xFU << SCFG_EXINTC4_EXINT14_Pos)      /*!< 0x00000F00 */
#define SCFG_EXINTC4_EXINT14                SCFG_EXINTC4_EXINT14_Msk                /*!< EXINT14[3:0] bits (EXINT14 input source configuration) */

#define SCFG_EXINTC4_EXINT14_GPA            0x00000000U                             /*!< GPIOA pin 14 */
#define SCFG_EXINTC4_EXINT14_GPB_Pos        (8U)
#define SCFG_EXINTC4_EXINT14_GPB_Msk        (0x1U << SCFG_EXINTC4_EXINT14_GPB_Pos)  /*!< 0x00000100 */
#define SCFG_EXINTC4_EXINT14_GPB            SCFG_EXINTC4_EXINT14_GPB_Msk            /*!< GPIOB pin 14 */
#define SCFG_EXINTC4_EXINT14_GPC_Pos        (9U)
#define SCFG_EXINTC4_EXINT14_GPC_Msk        (0x1U << SCFG_EXINTC4_EXINT14_GPC_Pos)  /*!< 0x00000200 */
#define SCFG_EXINTC4_EXINT14_GPC            SCFG_EXINTC4_EXINT14_GPC_Msk            /*!< GPIOC pin 14 */
#define SCFG_EXINTC4_EXINT14_GPD_Pos        (8U)
#define SCFG_EXINTC4_EXINT14_GPD_Msk        (0x3U << SCFG_EXINTC4_EXINT14_GPD_Pos)  /*!< 0x00000300 */
#define SCFG_EXINTC4_EXINT14_GPD            SCFG_EXINTC4_EXINT14_GPD_Msk            /*!< GPIOD pin 14 */
#define SCFG_EXINTC4_EXINT14_GPE_Pos        (8U)
#define SCFG_EXINTC4_EXINT14_GPE_Msk        (0x4U << SCFG_EXINTC4_EXINT14_GPE_Pos)  /*!< 0x00000400 */
#define SCFG_EXINTC4_EXINT14_GPE            SCFG_EXINTC4_EXINT14_GPE_Msk            /*!< GPIOD pin 14 */
#define SCFG_EXINTC4_EXINT14_GPF_Pos        (8U)
#define SCFG_EXINTC4_EXINT14_GPF_Msk        (0x5U << SCFG_EXINTC4_EXINT14_GPF_Pos)  /*!< 0x00000500 */
#define SCFG_EXINTC4_EXINT14_GPF            SCFG_EXINTC4_EXINT14_GPF_Msk            /*!< GPIOF pin 14 */
#define SCFG_EXINTC4_EXINT14_GPG_Pos        (8U)
#define SCFG_EXINTC4_EXINT14_GPG_Msk        (0x6U << SCFG_EXINTC4_EXINT14_GPG_Pos)  /*!< 0x00000600 */
#define SCFG_EXINTC4_EXINT14_GPG            SCFG_EXINTC4_EXINT14_GPG_Msk            /*!< GPIOF pin 14 */
#define SCFG_EXINTC4_EXINT14_GPH_Pos        (8U)
#define SCFG_EXINTC4_EXINT14_GPH_Msk        (0x6U << SCFG_EXINTC4_EXINT14_GPH_Pos)  /*!< 0x00000700 */
#define SCFG_EXINTC4_EXINT14_GPH            SCFG_EXINTC4_EXINT14_GPH_Msk            /*!< GPIOF pin 14 */

/*!< EXINT15 configuration */
#define SCFG_EXINTC4_EXINT15_Pos            (12U)
#define SCFG_EXINTC4_EXINT15_Msk            (0xFU << SCFG_EXINTC4_EXINT15_Pos)      /*!< 0x0000F000 */
#define SCFG_EXINTC4_EXINT15                SCFG_EXINTC4_EXINT15_Msk                /*!< EXINT15[3:0] bits (EXINT15 input source configuration) */

#define SCFG_EXINTC4_EXINT15_GPA            0x00000000U                             /*!< GPIOA pin 15 */
#define SCFG_EXINTC4_EXINT15_GPB_Pos        (12U)
#define SCFG_EXINTC4_EXINT15_GPB_Msk        (0x1U << SCFG_EXINTC4_EXINT15_GPB_Pos)  /*!< 0x00001000 */
#define SCFG_EXINTC4_EXINT15_GPB            SCFG_EXINTC4_EXINT15_GPB_Msk            /*!< GPIOB pin 15 */
#define SCFG_EXINTC4_EXINT15_GPC_Pos        (13U)
#define SCFG_EXINTC4_EXINT15_GPC_Msk        (0x1U << SCFG_EXINTC4_EXINT15_GPC_Pos)  /*!< 0x00002000 */
#define SCFG_EXINTC4_EXINT15_GPC            SCFG_EXINTC4_EXINT15_GPC_Msk            /*!< GPIOC pin 15 */
#define SCFG_EXINTC4_EXINT15_GPD_Pos        (12U)
#define SCFG_EXINTC4_EXINT15_GPD_Msk        (0x3U << SCFG_EXINTC4_EXINT15_GPD_Pos)  /*!< 0x00003000 */
#define SCFG_EXINTC4_EXINT15_GPD            SCFG_EXINTC4_EXINT15_GPD_Msk            /*!< GPIOD pin 15 */
#define SCFG_EXINTC4_EXINT15_GPE_Pos        (12U)
#define SCFG_EXINTC4_EXINT15_GPE_Msk        (0x4U << SCFG_EXINTC4_EXINT15_GPE_Pos)  /*!< 0x00004000 */
#define SCFG_EXINTC4_EXINT15_GPE            SCFG_EXINTC4_EXINT15_GPE_Msk            /*!< GPIOD pin 15 */
#define SCFG_EXINTC4_EXINT15_GPF_Pos        (12U)
#define SCFG_EXINTC4_EXINT15_GPF_Msk        (0x5U << SCFG_EXINTC4_EXINT15_GPF_Pos)  /*!< 0x00005000 */
#define SCFG_EXINTC4_EXINT15_GPF            SCFG_EXINTC4_EXINT15_GPF_Msk            /*!< GPIOF pin 15 */
#define SCFG_EXINTC4_EXINT15_GPG_Pos        (12U)
#define SCFG_EXINTC4_EXINT15_GPG_Msk        (0x6U << SCFG_EXINTC4_EXINT15_GPG_Pos)  /*!< 0x00006000 */
#define SCFG_EXINTC4_EXINT15_GPG            SCFG_EXINTC4_EXINT15_GPG_Msk            /*!< GPIOF pin 15 */
#define SCFG_EXINTC4_EXINT15_GPH_Pos        (12U)
#define SCFG_EXINTC4_EXINT15_GPH_Msk        (0x7U << SCFG_EXINTC4_EXINT15_GPH_Pos)  /*!< 0x00007000 */
#define SCFG_EXINTC4_EXINT15_GPH            SCFG_EXINTC4_EXINT15_GPH_Msk            /*!< GPIOF pin 15 */

/******************  Bit definition for SCFG_UHDRV register  ******************/
#define SCFG_UHDRV_PB3_UH_Pos               (0U)
#define SCFG_UHDRV_PB3_UH_Msk               (0x1U << SCFG_UHDRV_PB3_UH_Pos)         /*!< 0x00000001 */
#define SCFG_UHDRV_PB3_UH                   SCFG_UHDRV_PB3_UH_Msk                   /*!< PB3 Ultra high sourcing/sinking strength */
#define SCFG_UHDRV_PB9_UH_Pos               (1U)
#define SCFG_UHDRV_PB9_UH_Msk               (0x1U << SCFG_UHDRV_PB9_UH_Pos)         /*!< 0x00000002 */
#define SCFG_UHDRV_PB9_UH                   SCFG_UHDRV_PB9_UH_Msk                   /*!< PB9 Ultra high sourcing/sinking strength */
#define SCFG_UHDRV_PB10_UH_Pos              (2U)
#define SCFG_UHDRV_PB10_UH_Msk              (0x1U << SCFG_UHDRV_PB10_UH_Pos)        /*!< 0x00000004 */
#define SCFG_UHDRV_PB10_UH                  SCFG_UHDRV_PB10_UH_Msk                  /*!< PB10 Ultra high sourcing/sinking strength */
#define SCFG_UHDRV_PD12_UH_Pos              (5U)
#define SCFG_UHDRV_PD12_UH_Msk              (0x1U << SCFG_UHDRV_PD12_UH_Pos)        /*!< 0x00000020 */
#define SCFG_UHDRV_PD12_UH                  SCFG_UHDRV_PD12_UH_Msk                  /*!< PD12 Ultra high sourcing/sinking strength */
#define SCFG_UHDRV_PD13_UH_Pos              (6U)
#define SCFG_UHDRV_PD13_UH_Msk              (0x1U << SCFG_UHDRV_PD13_UH_Pos)        /*!< 0x00000040 */
#define SCFG_UHDRV_PD13_UH                  SCFG_UHDRV_PD13_UH_Msk                  /*!< PD13 Ultra high sourcing/sinking strength */
#define SCFG_UHDRV_PD14_UH_Pos              (7U)
#define SCFG_UHDRV_PD14_UH_Msk              (0x1U << SCFG_UHDRV_PD14_UH_Pos)        /*!< 0x00000080 */
#define SCFG_UHDRV_PD14_UH                  SCFG_UHDRV_PD14_UH_Msk                  /*!< PD14 Ultra high sourcing/sinking strength */
#define SCFG_UHDRV_PD15_UH_Pos              (8U)
#define SCFG_UHDRV_PD15_UH_Msk              (0x1U << SCFG_UHDRV_PD15_UH_Pos)        /*!< 0x00000100 */
#define SCFG_UHDRV_PD15_UH                  SCFG_UHDRV_PD15_UH_Msk                  /*!< PD15 Ultra high sourcing/sinking strength */
#define SCFG_UHDRV_PF14_UH_Pos              (9U)
#define SCFG_UHDRV_PF14_UH_Msk              (0x1U << SCFG_UHDRV_PF14_UH_Pos)        /*!< 0x00000020 */
#define SCFG_UHDRV_PF14_UH                  SCFG_UHDRV_PF14_UH_Msk                  /*!< PF14 Ultra high sourcing/sinking strength */
#define SCFG_UHDRV_PF15_UH_Pos              (10U)
#define SCFG_UHDRV_PF15_UH_Msk              (0x1U << SCFG_UHDRV_PF15_UH_Pos)        /*!< 0x00000040 */
#define SCFG_UHDRV_PF15_UH                  SCFG_UHDRV_PF15_UH_Msk                  /*!< PF15 Ultra high sourcing/sinking strength */

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
#define EXINT_INTEN_INTEN20_Pos             (20U)
#define EXINT_INTEN_INTEN20_Msk             (0x1U << EXINT_INTEN_INTEN20_Pos)       /*!< 0x00100000 */
#define EXINT_INTEN_INTEN20                 EXINT_INTEN_INTEN20_Msk                 /*!< Interrupt enable or disable on line 20 (F405 only) */
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
#define EXINT_INTEN_INT20                   EXINT_INTEN_INTEN20
#define EXINT_INTEN_INT21                   EXINT_INTEN_INTEN21
#define EXINT_INTEN_INT22                   EXINT_INTEN_INTEN22
#define EXINT_INTEN_INT                     0x0077FFFFU                             /*!< Interrupt enable or disable all */
 
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
#define EXINT_EVTEN_EVTEN20_Pos             (20U)
#define EXINT_EVTEN_EVTEN20_Msk             (0x1U << EXINT_EVTEN_EVTEN20_Pos)       /*!< 0x00100000 */
#define EXINT_EVTEN_EVTEN20                 EXINT_EVTEN_EVTEN20_Msk                 /*!< Event enable or disable on line 20 (F405 only) */
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
#define EXINT_POLCFG1_RP20_Pos              (20U)
#define EXINT_POLCFG1_RP20_Msk              (0x1U << EXINT_POLCFG1_RP20_Pos)        /*!< 0x00100000 */
#define EXINT_POLCFG1_RP20                  EXINT_POLCFG1_RP20_Msk                  /*!< Rising edge event configuration bit on line 20 (F405 only) */
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
#define EXINT_POLCFG2_FP20_Pos              (20U)
#define EXINT_POLCFG2_FP20_Msk              (0x1U << EXINT_POLCFG2_FP20_Pos)        /*!< 0x00100000 */
#define EXINT_POLCFG2_FP20                  EXINT_POLCFG2_FP20_Msk                  /*!< Falling edge event configuration bit on line 20 (F405 only) */
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
#define EXINT_SWTRG_SWT20_Pos               (20U)
#define EXINT_SWTRG_SWT20_Msk               (0x1U << EXINT_SWTRG_SWT20_Pos)         /*!< 0x00100000 */
#define EXINT_SWTRG_SWT20                   EXINT_SWTRG_SWT20_Msk                   /*!< Software trigger on line 20 (F405 only) */
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
#define EXINT_INTSTS_LINE20_Pos             (20U)
#define EXINT_INTSTS_LINE20_Msk             (0x1U << EXINT_INTSTS_LINE20_Pos)       /*!< 0x00100000 */
#define EXINT_INTSTS_LINE20                 EXINT_INTSTS_LINE20_Msk                 /*!< Status bit for line 20 (F405 only) */
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

/*!< PWIDTH configuration */
#define DMA_CCTRL_PWIDTH_Pos                (8U)
#define DMA_CCTRL_PWIDTH_Msk                (0x3U << DMA_CCTRL_PWIDTH_Pos)          /*!< 0x00000300 */
#define DMA_CCTRL_PWIDTH                    DMA_CCTRL_PWIDTH_Msk                    /*!< PWIDTH[1:0] bits (Peripheral data bit width) */
#define DMA_CCTRL_PWIDTH_0                  (0x1U << DMA_CCTRL_PWIDTH_Pos)          /*!< 0x00000100 */
#define DMA_CCTRL_PWIDTH_1                  (0x2U << DMA_CCTRL_PWIDTH_Pos)          /*!< 0x00000200 */

/*!< MWIDTH configuration */
#define DMA_CCTRL_MWIDTH_Pos                (10U)
#define DMA_CCTRL_MWIDTH_Msk                (0x3U << DMA_CCTRL_MWIDTH_Pos)          /*!< 0x00000C00 */
#define DMA_CCTRL_MWIDTH                    DMA_CCTRL_MWIDTH_Msk                    /*!< MWIDTH[1:0] bits (Memory data bit width) */
#define DMA_CCTRL_MWIDTH_0                  (0x1U << DMA_CCTRL_MWIDTH_Pos)          /*!< 0x00000400 */
#define DMA_CCTRL_MWIDTH_1                  (0x2U << DMA_CCTRL_MWIDTH_Pos)          /*!< 0x00000800 */

/*!< CHPL configuration */
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

/******************  Bit definition for DMA_MUXSEL register  ******************/
#define DMA_MUXSEL_TBL_SEL_Pos              (0U)
#define DMA_MUXSEL_TBL_SEL_Msk              (0x1U << DMA_MUXSEL_TBL_SEL_Pos)        /*!< 0x00000001 */
#define DMA_MUXSEL_TBL_SEL                  DMA_MUXSEL_TBL_SEL_Msk                  /*!< Multiplexer table select */

/*****************  Bit definition for DMA_MUXCCTRL register  *****************/
#define DMA_MUXCCTRL_REQSEL_Pos             (0U)
#define DMA_MUXCCTRL_REQSEL_Msk             (0x7FU << DMA_MUXCCTRL_REQSEL_Pos)      /*!< 0x0000007F */
#define DMA_MUXCCTRL_REQSEL                 DMA_MUXCCTRL_REQSEL_Msk                 /*!< DMA request select */
#define DMA_MUXCCTRL_SYNCOVIEN_Pos          (8U)
#define DMA_MUXCCTRL_SYNCOVIEN_Msk          (0x1U << DMA_MUXCCTRL_SYNCOVIEN_Pos)    /*!< 0x00000100 */
#define DMA_MUXCCTRL_SYNCOVIEN              DMA_MUXCCTRL_SYNCOVIEN_Msk              /*!< Synchronization overrun interrupt enable */
#define DMA_MUXCCTRL_EVTGEN_Pos             (9U)
#define DMA_MUXCCTRL_EVTGEN_Msk             (0x1U << DMA_MUXCCTRL_EVTGEN_Pos)       /*!< 0x00000200 */
#define DMA_MUXCCTRL_EVTGEN                 DMA_MUXCCTRL_EVTGEN_Msk                 /*!< Event generate enable */
#define DMA_MUXCCTRL_SYNCEN_Pos             (16U)
#define DMA_MUXCCTRL_SYNCEN_Msk             (0x1U << DMA_MUXCCTRL_SYNCEN_Pos)       /*!< 0x00010000 */
#define DMA_MUXCCTRL_SYNCEN                 DMA_MUXCCTRL_SYNCEN_Msk                 /*!< Synchronization enable */

/*!< SYNCPOL configuration */
#define DMA_MUXCCTRL_SYNCPOL_Pos            (17U)
#define DMA_MUXCCTRL_SYNCPOL_Msk            (0x3U << DMA_MUXCCTRL_SYNCPOL_Pos)      /*!< 0x00060000 */
#define DMA_MUXCCTRL_SYNCPOL                DMA_MUXCCTRL_SYNCPOL_Msk                /*!< SYNCPOL[1:0] bits (Synchronization polarity) */
#define DMA_MUXCCTRL_SYNCPOL_0              (0x1U << DMA_MUXCCTRL_SYNCPOL_Pos)      /*!< 0x00020000 */
#define DMA_MUXCCTRL_SYNCPOL_1              (0x2U << DMA_MUXCCTRL_SYNCPOL_Pos)      /*!< 0x00040000 */

/*!< REQCNT configuration */
#define DMA_MUXCCTRL_REQCNT_Pos             (19U)
#define DMA_MUXCCTRL_REQCNT_Msk             (0x1FU << DMA_MUXCCTRL_REQCNT_Pos)      /*!< 0x00F80000 */
#define DMA_MUXCCTRL_REQCNT                 DMA_MUXCCTRL_REQCNT_Msk                 /*!< REQCNT[4:0] bits (DMA request count) */
#define DMA_MUXCCTRL_REQCNT_0               (0x1U << DMA_MUXCCTRL_REQCNT_Pos)       /*!< 0x00080000 */
#define DMA_MUXCCTRL_REQCNT_1               (0x2U << DMA_MUXCCTRL_REQCNT_Pos)       /*!< 0x00100000 */
#define DMA_MUXCCTRL_REQCNT_2               (0x4U << DMA_MUXCCTRL_REQCNT_Pos)       /*!< 0x00200000 */
#define DMA_MUXCCTRL_REQCNT_3               (0x8U << DMA_MUXCCTRL_REQCNT_Pos)       /*!< 0x00400000 */
#define DMA_MUXCCTRL_REQCNT_4               (0x10U << DMA_MUXCCTRL_REQCNT_Pos)      /*!< 0x00800000 */

/*!< SYNCSEL configuration */
#define DMA_MUXCCTRL_SYNCSEL_Pos            (24U)
#define DMA_MUXCCTRL_SYNCSEL_Msk            (0x1FU << DMA_MUXCCTRL_SYNCSEL_Pos)     /*!< 0x1F000000 */
#define DMA_MUXCCTRL_SYNCSEL                DMA_MUXCCTRL_SYNCSEL_Msk                /*!< SYNCSEL[4:0] bits (Synchronization select) */
#define DMA_MUXCCTRL_SYNCSEL_0              (0x1U << DMA_MUXCCTRL_SYNCSEL_Pos)      /*!< 0x01000000 */
#define DMA_MUXCCTRL_SYNCSEL_1              (0x2U << DMA_MUXCCTRL_SYNCSEL_Pos)      /*!< 0x02000000 */
#define DMA_MUXCCTRL_SYNCSEL_2              (0x4U << DMA_MUXCCTRL_SYNCSEL_Pos)      /*!< 0x04000000 */
#define DMA_MUXCCTRL_SYNCSEL_3              (0x8U << DMA_MUXCCTRL_SYNCSEL_Pos)      /*!< 0x08000000 */
#define DMA_MUXCCTRL_SYNCSEL_4              (0x10U << DMA_MUXCCTRL_SYNCSEL_Pos)     /*!< 0x10000000 */

/*****************  Bit definition for DMA_MUXGCTRL register  *****************/
#define DMA_MUXGCTRL_SIGSEL_Pos             (0U)
#define DMA_MUXGCTRL_SIGSEL_Msk             (0x1FU << DMA_MUXGCTRL_SIGSEL_Pos)      /*!< 0x0000001F */
#define DMA_MUXGCTRL_SIGSEL                 DMA_MUXGCTRL_SIGSEL_Msk                 /*!< Signal select */
#define DMA_MUXGCTRL_TRGOVIEN_Pos           (8U)
#define DMA_MUXGCTRL_TRGOVIEN_Msk           (0x1U << DMA_MUXGCTRL_TRGOVIEN_Pos)     /*!< 0x00000100 */
#define DMA_MUXGCTRL_TRGOVIEN               DMA_MUXGCTRL_TRGOVIEN_Msk               /*!< Trigger overrun interrupt enable */
#define DMA_MUXGCTRL_GEN_Pos                (16U)
#define DMA_MUXGCTRL_GEN_Msk                (0x1U << DMA_MUXGCTRL_GEN_Pos)          /*!< 0x00010000 */
#define DMA_MUXGCTRL_GEN                    DMA_MUXGCTRL_GEN_Msk                    /*!< DMA request generation enable */

/*!< GPOL configuration */
#define DMA_MUXGCTRL_GPOL_Pos               (17U)
#define DMA_MUXGCTRL_GPOL_Msk               (0x3U << DMA_MUXGCTRL_GPOL_Pos)         /*!< 0x00060000 */
#define DMA_MUXGCTRL_GPOL                   DMA_MUXGCTRL_GPOL_Msk                   /*!< GPOL[1:0] bits (DMA request generation polarity) */
#define DMA_MUXGCTRL_GPOL_0                 (0x1U << DMA_MUXGCTRL_GPOL_Pos)         /*!< 0x00020000 */
#define DMA_MUXGCTRL_GPOL_1                 (0x2U << DMA_MUXGCTRL_GPOL_Pos)         /*!< 0x00040000 */

/*!< GREQCNT configuration */
#define DMA_MUXGCTRL_GREQCNT_Pos            (19U)
#define DMA_MUXGCTRL_GREQCNT_Msk            (0x1FU << DMA_MUXGCTRL_GREQCNT_Pos)     /*!< 0x00F80000 */
#define DMA_MUXGCTRL_GREQCNT                DMA_MUXGCTRL_GREQCNT_Msk                /*!< GREQCNT[4:0] bits (DMA request generation count) */
#define DMA_MUXGCTRL_GREQCNT_0              (0x1U << DMA_MUXGCTRL_GREQCNT_Pos)      /*!< 0x00080000 */
#define DMA_MUXGCTRL_GREQCNT_1              (0x2U << DMA_MUXGCTRL_GREQCNT_Pos)      /*!< 0x00100000 */
#define DMA_MUXGCTRL_GREQCNT_2              (0x4U << DMA_MUXGCTRL_GREQCNT_Pos)      /*!< 0x00200000 */
#define DMA_MUXGCTRL_GREQCNT_3              (0x8U << DMA_MUXGCTRL_GREQCNT_Pos)      /*!< 0x00400000 */
#define DMA_MUXGCTRL_GREQCNT_4              (0x10U << DMA_MUXGCTRL_GREQCNT_Pos)     /*!< 0x00800000 */

/****************  Bit definition for DMA_MUXSYNCSTS register  ****************/
#define DMA_MUXSYNCSTS_SYNCOVF_Pos          (0U)
#define DMA_MUXSYNCSTS_SYNCOVF_Msk          (0xFFU << DMA_MUXSYNCSTS_SYNCOVF_Pos)   /*!< 0x000000FF */
#define DMA_MUXSYNCSTS_SYNCOVF              DMA_MUXSYNCSTS_SYNCOVF_Msk              /*!< Synchronization overrun interrupt flag */

/****************  Bit definition for DMA_MUXSYNCCLR register  ****************/
#define DMA_MUXSYNCCLR_SYNCOVFC_Pos         (0U)
#define DMA_MUXSYNCCLR_SYNCOVFC_Msk         (0xFFU << DMA_MUXSYNCCLR_SYNCOVFC_Pos)  /*!< 0x000000FF */
#define DMA_MUXSYNCCLR_SYNCOVFC             DMA_MUXSYNCCLR_SYNCOVFC_Msk             /*!< Synchronization overrun interrupt flag clear */

/*****************  Bit definition for DMA_MUXGSTS register  ******************/
#define DMA_MUXGSTS_TRGOVF_Pos              (0U)
#define DMA_MUXGSTS_TRGOVF_Msk              (0xFU << DMA_MUXGSTS_TRGOVF_Pos)        /*!< 0x0000000F */
#define DMA_MUXGSTS_TRGOVF                  DMA_MUXGSTS_TRGOVF_Msk                  /*!< Trigger overrun interrupt flag */

/*****************  Bit definition for DMA_MUXGCLR register  ******************/
#define DMA_MUXGCLR_TRGOVFC_Pos             (0U)
#define DMA_MUXGCLR_TRGOVFC_Msk             (0xFU << DMA_MUXGCLR_TRGOVFC_Pos)       /*!< 0x0000000F */
#define DMA_MUXGCLR_TRGOVFC                 DMA_MUXGCLR_TRGOVFC_Msk                 /*!< Trigger overrun interrupt flag clear */

/******************************************************************************/
/*                                                                            */
/*                  Inter-integrated circuit interface (I2C)                  */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for I2C_CTRL1 register  *******************/
#define I2C_CTRL1_I2CEN_Pos                 (0U)
#define I2C_CTRL1_I2CEN_Msk                 (0x1U << I2C_CTRL1_I2CEN_Pos)           /*!< 0x00000001 */
#define I2C_CTRL1_I2CEN                     I2C_CTRL1_I2CEN_Msk                     /*!< I2C peripheral enable */
#define I2C_CTRL1_TDIEN_Pos                 (1U)
#define I2C_CTRL1_TDIEN_Msk                 (0x1U << I2C_CTRL1_TDIEN_Pos)           /*!< 0x00000002 */
#define I2C_CTRL1_TDIEN                     I2C_CTRL1_TDIEN_Msk                     /*!< Data transmit data interrupt enable */
#define I2C_CTRL1_RDIEN_Pos                 (2U)
#define I2C_CTRL1_RDIEN_Msk                 (0x1U << I2C_CTRL1_RDIEN_Pos)           /*!< 0x00000004 */
#define I2C_CTRL1_RDIEN                     I2C_CTRL1_RDIEN_Msk                     /*!< Data receive interrupt enable */
#define I2C_CTRL1_ADDRIEN_Pos               (3U)
#define I2C_CTRL1_ADDRIEN_Msk               (0x1U << I2C_CTRL1_ADDRIEN_Pos)         /*!< 0x00000008 */
#define I2C_CTRL1_ADDRIEN                   I2C_CTRL1_ADDRIEN_Msk                   /*!< Address match interrupt enable */
#define I2C_CTRL1_ACKFAILIEN_Pos            (4U)
#define I2C_CTRL1_ACKFAILIEN_Msk            (0x1U << I2C_CTRL1_ACKFAILIEN_Pos)      /*!< 0x00000010 */
#define I2C_CTRL1_ACKFAILIEN                I2C_CTRL1_ACKFAILIEN_Msk                /*!< Acknowledge fail interrupt enable */
#define I2C_CTRL1_STOPIEN_Pos               (5U)
#define I2C_CTRL1_STOPIEN_Msk               (0x1U << I2C_CTRL1_STOPIEN_Pos)         /*!< 0x00000020 */
#define I2C_CTRL1_STOPIEN                   I2C_CTRL1_STOPIEN_Msk                   /*!< Stop generation complete interrupt enable */
#define I2C_CTRL1_TDCIEN_Pos                (6U)
#define I2C_CTRL1_TDCIEN_Msk                (0x1U << I2C_CTRL1_TDCIEN_Pos)          /*!< 0x00000040 */
#define I2C_CTRL1_TDCIEN                    I2C_CTRL1_TDCIEN_Msk                    /*!< Data transfer complete interrupt enable */
#define I2C_CTRL1_ERRIEN_Pos                (7U)
#define I2C_CTRL1_ERRIEN_Msk                (0x1U << I2C_CTRL1_ERRIEN_Pos)          /*!< 0x00000080 */
#define I2C_CTRL1_ERRIEN                    I2C_CTRL1_ERRIEN_Msk                    /*!< Error interrupt enable */
#define I2C_CTRL1_DFLT_Pos                  (8U)
#define I2C_CTRL1_DFLT_Msk                  (0xFU << I2C_CTRL1_DFLT_Pos)            /*!< 0x00000F00 */
#define I2C_CTRL1_DFLT                      I2C_CTRL1_DFLT_Msk                      /*!< Digital filter value */
#define I2C_CTRL1_DMATEN_Pos                (14U)
#define I2C_CTRL1_DMATEN_Msk                (0x1U << I2C_CTRL1_DMATEN_Pos)          /*!< 0x00004000 */
#define I2C_CTRL1_DMATEN                    I2C_CTRL1_DMATEN_Msk                    /*!< DMA transmit data request enable */
#define I2C_CTRL1_DMAREN_Pos                (15U)
#define I2C_CTRL1_DMAREN_Msk                (0x1U << I2C_CTRL1_DMAREN_Pos)          /*!< 0x00008000 */
#define I2C_CTRL1_DMAREN                    I2C_CTRL1_DMAREN_Msk                    /*!< DMA receive data request enable */
#define I2C_CTRL1_SCTRL_Pos                 (16U)
#define I2C_CTRL1_SCTRL_Msk                 (0x1U << I2C_CTRL1_SCTRL_Pos)           /*!< 0x00010000 */
#define I2C_CTRL1_SCTRL                     I2C_CTRL1_SCTRL_Msk                     /*!< Slave receiving data control */
#define I2C_CTRL1_STRETCH_Pos               (17U)
#define I2C_CTRL1_STRETCH_Msk               (0x1U << I2C_CTRL1_STRETCH_Pos)         /*!< 0x00020000 */
#define I2C_CTRL1_STRETCH                   I2C_CTRL1_STRETCH_Msk                   /*!< Clock stretching mode */
#define I2C_CTRL1_GCAEN_Pos                 (19U)
#define I2C_CTRL1_GCAEN_Msk                 (0x1U << I2C_CTRL1_GCAEN_Pos)           /*!< 0x00080000 */
#define I2C_CTRL1_GCAEN                     I2C_CTRL1_GCAEN_Msk                     /*!< General call address enable */
#define I2C_CTRL1_HADDREN_Pos               (20U)
#define I2C_CTRL1_HADDREN_Msk               (0x1U << I2C_CTRL1_HADDREN_Pos)         /*!< 0x00100000 */
#define I2C_CTRL1_HADDREN                   I2C_CTRL1_HADDREN_Msk                   /*!< SMBus host address enable */
#define I2C_CTRL1_DEVADDREN_Pos             (21U)
#define I2C_CTRL1_DEVADDREN_Msk             (0x1U << I2C_CTRL1_DEVADDREN_Pos)       /*!< 0x00200000 */
#define I2C_CTRL1_DEVADDREN                 I2C_CTRL1_DEVADDREN_Msk                 /*!< SMBus device default address enable */
#define I2C_CTRL1_SMBALERT_Pos              (22U)
#define I2C_CTRL1_SMBALERT_Msk              (0x1U << I2C_CTRL1_SMBALERT_Pos)        /*!< 0x00400000 */
#define I2C_CTRL1_SMBALERT                  I2C_CTRL1_SMBALERT_Msk                  /*!< SMBus alert enable / pin set */
#define I2C_CTRL1_PECEN_Pos                 (23U)
#define I2C_CTRL1_PECEN_Msk                 (0x1U << I2C_CTRL1_PECEN_Pos)           /*!< 0x00800000 */
#define I2C_CTRL1_PECEN                     I2C_CTRL1_PECEN_Msk                     /*!< PEC calculation enable */

/******************  Bit definition for I2C_CTRL2 register  *******************/
/*!< SADDR configuration */
#define I2C_CTRL2_SADDR_Pos                 (0U)
#define I2C_CTRL2_SADDR_Msk                 (0x3FFU << I2C_CTRL2_SADDR_Pos)         /*!< 0x000003FF */
#define I2C_CTRL2_SADDR                     I2C_CTRL2_SADDR_Msk                     /*!< SADDR[9:0] bits (Slave address sent by the master) */
#define I2C_CTRL2_SADDR_0                   (0x001U << I2C_CTRL2_SADDR_Pos)         /*!< 0x00000001 */
#define I2C_CTRL2_SADDR_1                   (0x002U << I2C_CTRL2_SADDR_Pos)         /*!< 0x00000002 */
#define I2C_CTRL2_SADDR_2                   (0x004U << I2C_CTRL2_SADDR_Pos)         /*!< 0x00000004 */
#define I2C_CTRL2_SADDR_3                   (0x008U << I2C_CTRL2_SADDR_Pos)         /*!< 0x00000008 */
#define I2C_CTRL2_SADDR_4                   (0x010U << I2C_CTRL2_SADDR_Pos)         /*!< 0x00000010 */
#define I2C_CTRL2_SADDR_5                   (0x020U << I2C_CTRL2_SADDR_Pos)         /*!< 0x00000020 */
#define I2C_CTRL2_SADDR_6                   (0x040U << I2C_CTRL2_SADDR_Pos)         /*!< 0x00000040 */
#define I2C_CTRL2_SADDR_7                   (0x080U << I2C_CTRL2_SADDR_Pos)         /*!< 0x00000080 */
#define I2C_CTRL2_SADDR_8                   (0x100U << I2C_CTRL2_SADDR_Pos)         /*!< 0x00000100 */
#define I2C_CTRL2_SADDR_9                   (0x200U << I2C_CTRL2_SADDR_Pos)         /*!< 0x00000200 */

#define I2C_CTRL2_DIR_Pos                   (10U)
#define I2C_CTRL2_DIR_Msk                   (0x1U << I2C_CTRL2_DIR_Pos)             /*!< 0x00000400 */
#define I2C_CTRL2_DIR                       I2C_CTRL2_DIR_Msk                       /*!< Master data transmission direction */
#define I2C_CTRL2_ADDR10_Pos                (11U)
#define I2C_CTRL2_ADDR10_Msk                (0x1U << I2C_CTRL2_ADDR10_Pos)          /*!< 0x00000800 */
#define I2C_CTRL2_ADDR10                    I2C_CTRL2_ADDR10_Msk                    /*!< Host sends 10-bit address mode enable */
#define I2C_CTRL2_READH10_Pos               (12U)
#define I2C_CTRL2_READH10_Msk               (0x1U << I2C_CTRL2_READH10_Pos)         /*!< 0x00001000 */
#define I2C_CTRL2_READH10                   I2C_CTRL2_READH10_Msk                   /*!< 10-bit address header read enable */
#define I2C_CTRL2_GENSTART_Pos              (13U)
#define I2C_CTRL2_GENSTART_Msk              (0x1U << I2C_CTRL2_GENSTART_Pos)        /*!< 0x00002000 */
#define I2C_CTRL2_GENSTART                  I2C_CTRL2_GENSTART_Msk                  /*!< Generate start condition */
#define I2C_CTRL2_GENSTOP_Pos               (14U)
#define I2C_CTRL2_GENSTOP_Msk               (0x1U << I2C_CTRL2_GENSTOP_Pos)         /*!< 0x00004000 */
#define I2C_CTRL2_GENSTOP                   I2C_CTRL2_GENSTOP_Msk                   /*!< Generate stop condition */
#define I2C_CTRL2_NACKEN_Pos                (15U)
#define I2C_CTRL2_NACKEN_Msk                (0x1U << I2C_CTRL2_NACKEN_Pos)          /*!< 0x00008000 */
#define I2C_CTRL2_NACKEN                    I2C_CTRL2_NACKEN_Msk                    /*!< Not acknowledge enable */

/*!< CNT configuration */
#define I2C_CTRL2_CNT_Pos                   (16U)
#define I2C_CTRL2_CNT_Msk                   (0xFFU << I2C_CTRL2_CNT_Pos)            /*!< 0x00FF0000 */
#define I2C_CTRL2_CNT                       I2C_CTRL2_CNT_Msk                       /*!< CNT[7:0] bits (CNT) */
#define I2C_CTRL2_CNT_0                     (0x01U << I2C_CTRL2_CNT_Pos)            /*!< 0x00010000 */
#define I2C_CTRL2_CNT_1                     (0x02U << I2C_CTRL2_CNT_Pos)            /*!< 0x00020000 */
#define I2C_CTRL2_CNT_2                     (0x04U << I2C_CTRL2_CNT_Pos)            /*!< 0x00040000 */
#define I2C_CTRL2_CNT_3                     (0x08U << I2C_CTRL2_CNT_Pos)            /*!< 0x00080000 */
#define I2C_CTRL2_CNT_4                     (0x10U << I2C_CTRL2_CNT_Pos)            /*!< 0x00100000 */
#define I2C_CTRL2_CNT_5                     (0x20U << I2C_CTRL2_CNT_Pos)            /*!< 0x00200000 */
#define I2C_CTRL2_CNT_6                     (0x40U << I2C_CTRL2_CNT_Pos)            /*!< 0x00400000 */
#define I2C_CTRL2_CNT_7                     (0x80U << I2C_CTRL2_CNT_Pos)            /*!< 0x00800000 */

#define I2C_CTRL2_RLDEN_Pos                 (24U)
#define I2C_CTRL2_RLDEN_Msk                 (0x1U << I2C_CTRL2_RLDEN_Pos)           /*!< 0x01000000 */
#define I2C_CTRL2_RLDEN                     I2C_CTRL2_RLDEN_Msk                     /*!< Send data reload mode enable */
#define I2C_CTRL2_ASTOPEN_Pos               (25U)
#define I2C_CTRL2_ASTOPEN_Msk               (0x1U << I2C_CTRL2_ASTOPEN_Pos)         /*!< 0x02000000 */
#define I2C_CTRL2_ASTOPEN                   I2C_CTRL2_ASTOPEN_Msk                   /*!< Automatically send stop condition enable */
#define I2C_CTRL2_PECTEN_Pos                (26U)
#define I2C_CTRL2_PECTEN_Msk                (0x1U << I2C_CTRL2_PECTEN_Pos)          /*!< 0x04000000 */
#define I2C_CTRL2_PECTEN                    I2C_CTRL2_PECTEN_Msk                    /*!< Request PEC transmission enable */

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

#define I2C_OADDR1_ADDR1MODE_Pos            (10U)
#define I2C_OADDR1_ADDR1MODE_Msk            (0x1U << I2C_OADDR1_ADDR1MODE_Pos)      /*!< 0x00000400 */
#define I2C_OADDR1_ADDR1MODE                I2C_OADDR1_ADDR1MODE_Msk                /*!< Own Address 1 mode */
#define I2C_OADDR1_ADDR1EN_Pos              (15U)
#define I2C_OADDR1_ADDR1EN_Msk              (0x1U << I2C_OADDR1_ADDR1EN_Pos)        /*!< 0x00008000 */
#define I2C_OADDR1_ADDR1EN                  I2C_OADDR1_ADDR1EN_Msk                  /*!< Own Address 1 enable */

/******************  Bit definition for I2C_OADDR2 register  ******************/
#define I2C_OADDR2_ADDR2_Pos                (1U)
#define I2C_OADDR2_ADDR2_Msk                (0x7FU << I2C_OADDR2_ADDR2_Pos)         /*!< 0x000000FE */
#define I2C_OADDR2_ADDR2                    I2C_OADDR2_ADDR2_Msk                    /*!< Own address 2 */

/*!< ADDR2MASK configuration */
#define I2C_OADDR2_ADDR2MASK_Pos            (8U)
#define I2C_OADDR2_ADDR2MASK_Msk            (0x7U << I2C_OADDR2_ADDR2MASK_Pos)      /*!< 0x00000700 */
#define I2C_OADDR2_ADDR2MASK                I2C_OADDR2_ADDR2MASK_Msk                /*!< CNT[2:0] bits (Own address 2 bit mask) */
#define I2C_OADDR2_ADDR2MASK_0              (0x01U << I2C_OADDR2_ADDR2MASK_Pos)     /*!< 0x00000100 */
#define I2C_OADDR2_ADDR2MASK_1              (0x02U << I2C_OADDR2_ADDR2MASK_Pos)     /*!< 0x00000200 */
#define I2C_OADDR2_ADDR2MASK_2              (0x04U << I2C_OADDR2_ADDR2MASK_Pos)     /*!< 0x00000400 */

#define I2C_OADDR2_ADDR2EN_Pos              (15U)
#define I2C_OADDR2_ADDR2EN_Msk              (0x1U << I2C_OADDR2_ADDR2EN_Pos)        /*!< 0x00008000 */
#define I2C_OADDR2_ADDR2EN                  I2C_OADDR2_ADDR2EN_Msk                  /*!< Own Address 2 enable */

/*****************  Bit definition for I2C_CLKCTRL register  ******************/
#define I2C_CLKCTRL_SCLL_Pos                (0U)
#define I2C_CLKCTRL_SCLL_Msk                (0xFFU << I2C_CLKCTRL_SCLL_Pos)         /*!< 0x000000FF */
#define I2C_CLKCTRL_SCLL                    I2C_CLKCTRL_SCLL_Msk                    /*!< SCL low level */
#define I2C_CLKCTRL_SCLH_Pos                (8U)
#define I2C_CLKCTRL_SCLH_Msk                (0xFFU << I2C_CLKCTRL_SCLH_Pos)         /*!< 0x0000FF00 */
#define I2C_CLKCTRL_SCLH                    I2C_CLKCTRL_SCLH_Msk                    /*!< SCL high level */
#define I2C_CLKCTRL_SDAD_Pos                (16U)
#define I2C_CLKCTRL_SDAD_Msk                (0xFU << I2C_CLKCTRL_SDAD_Pos)          /*!< 0x000F0000 */
#define I2C_CLKCTRL_SDAD                    I2C_CLKCTRL_SDAD_Msk                    /*!< SDA output delay */
#define I2C_CLKCTRL_SCLD_Pos                (20U)
#define I2C_CLKCTRL_SCLD_Msk                (0xFU << I2C_CLKCTRL_SCLD_Pos)          /*!< 0x00F00000 */
#define I2C_CLKCTRL_SCLD                    I2C_CLKCTRL_SCLD_Msk                    /*!< SCL output delay */
#define I2C_CLKCTRL_DIVH_Pos                (24U)
#define I2C_CLKCTRL_DIVH_Msk                (0xFU << I2C_CLKCTRL_DIVH_Pos)          /*!< 0x0F000000 */
#define I2C_CLKCTRL_DIVH                    I2C_CLKCTRL_DIVH_Msk                    /*!< High 4 bits of clock divider value */
#define I2C_CLKCTRL_DIVL_Pos                (28U)
#define I2C_CLKCTRL_DIVL_Msk                (0xFU << I2C_CLKCTRL_DIVL_Pos)          /*!< 0xF0000000 */
#define I2C_CLKCTRL_DIVL                    I2C_CLKCTRL_DIVL_Msk                    /*!< Low 4 bits of clock divider value */

/*****************  Bit definition for I2C_TIMEOUT register  ******************/
#define I2C_TIMEOUT_TOTIME_Pos              (0U)
#define I2C_TIMEOUT_TOTIME_Msk              (0xFFFU << I2C_TIMEOUT_TOTIME_Pos)      /*!< 0x00000FFF */
#define I2C_TIMEOUT_TOTIME                  I2C_TIMEOUT_TOTIME_Msk                  /*!< Clock timeout detection time */
#define I2C_TIMEOUT_TOMODE_Pos              (12U)
#define I2C_TIMEOUT_TOMODE_Msk              (0x1U << I2C_TIMEOUT_TOMODE_Pos)        /*!< 0x00001000 */
#define I2C_TIMEOUT_TOMODE                  I2C_TIMEOUT_TOMODE_Msk                  /*!< Clock timeout detection mode */
#define I2C_TIMEOUT_TOEN_Pos                (15U)
#define I2C_TIMEOUT_TOEN_Msk                (0x1U << I2C_TIMEOUT_TOEN_Pos)          /*!< 0x00008000 */
#define I2C_TIMEOUT_TOEN                    I2C_TIMEOUT_TOEN_Msk                    /*!< Detect clock low/high timeout enable */
#define I2C_TIMEOUT_EXTTIME_Pos             (16U)
#define I2C_TIMEOUT_EXTTIME_Msk             (0xFFFU << I2C_TIMEOUT_EXTTIME_Pos)     /*!< 0x0FFF0000 */
#define I2C_TIMEOUT_EXTTIME                 I2C_TIMEOUT_EXTTIME_Msk                 /*!< Cumulative clock low extend timeout value */
#define I2C_TIMEOUT_EXTEN_Pos               (31U)
#define I2C_TIMEOUT_EXTEN_Msk               (0x1U << I2C_TIMEOUT_EXTEN_Pos)         /*!< 0x80000000 */
#define I2C_TIMEOUT_EXTEN                   I2C_TIMEOUT_EXTEN_Msk                   /*!< Cumulative clock low extend timeout enable */

/*******************  Bit definition for I2C_STS register  ********************/
#define I2C_STS_TDBE_Pos                    (0U)
#define I2C_STS_TDBE_Msk                    (0x1U << I2C_STS_TDBE_Pos)              /*!< 0x00000001 */
#define I2C_STS_TDBE                        I2C_STS_TDBE_Msk                        /*!< Transmit data buffer empty flag */
#define I2C_STS_TDIS_Pos                    (1U)
#define I2C_STS_TDIS_Msk                    (0x1U << I2C_STS_TDIS_Pos)              /*!< 0x00000002 */
#define I2C_STS_TDIS                        I2C_STS_TDIS_Msk                        /*!< Transmit data interrupt status */
#define I2C_STS_RDBF_Pos                    (2U)
#define I2C_STS_RDBF_Msk                    (0x1U << I2C_STS_RDBF_Pos)              /*!< 0x00000004 */
#define I2C_STS_RDBF                        I2C_STS_RDBF_Msk                        /*!< Receive data buffer full flag */
#define I2C_STS_ADDRF_Pos                   (3U)
#define I2C_STS_ADDRF_Msk                   (0x1U << I2C_STS_ADDRF_Pos)             /*!< 0x00000008 */
#define I2C_STS_ADDRF                       I2C_STS_ADDRF_Msk                       /*!< 0 ~ 7 bit address match flag */
#define I2C_STS_ACKFAILF_Pos                (4U)
#define I2C_STS_ACKFAILF_Msk                (0x1U << I2C_STS_ACKFAILF_Pos)          /*!< 0x00000010 */
#define I2C_STS_ACKFAILF                    I2C_STS_ACKFAILF_Msk                    /*!< Acknowledge failure flag */
#define I2C_STS_STOPF_Pos                   (5U)
#define I2C_STS_STOPF_Msk                   (0x1U << I2C_STS_STOPF_Pos)             /*!< 0x00000020 */
#define I2C_STS_STOPF                       I2C_STS_STOPF_Msk                       /*!< Stop condition generation complete flag */
#define I2C_STS_TDC_Pos                     (6U)
#define I2C_STS_TDC_Msk                     (0x1U << I2C_STS_TDC_Pos)               /*!< 0x00000040 */
#define I2C_STS_TDC                         I2C_STS_TDC_Msk                         /*!< Data transfer complete flag */
#define I2C_STS_TCRLD_Pos                   (7U)
#define I2C_STS_TCRLD_Msk                   (0x1U << I2C_STS_TCRLD_Pos)             /*!< 0x00000080 */
#define I2C_STS_TCRLD                       I2C_STS_TCRLD_Msk                       /*!< Transmission is complete, waiting to load data */
#define I2C_STS_BUSERR_Pos                  (8U)
#define I2C_STS_BUSERR_Msk                  (0x1U << I2C_STS_BUSERR_Pos)            /*!< 0x00000100 */
#define I2C_STS_BUSERR                      I2C_STS_BUSERR_Msk                      /*!< Bus error flag */
#define I2C_STS_ARLOST_Pos                  (9U)
#define I2C_STS_ARLOST_Msk                  (0x1U << I2C_STS_ARLOST_Pos)            /*!< 0x00000200 */
#define I2C_STS_ARLOST                      I2C_STS_ARLOST_Msk                      /*!< Arbitration lost flag */
#define I2C_STS_OUF_Pos                     (10U)
#define I2C_STS_OUF_Msk                     (0x1U << I2C_STS_OUF_Pos)               /*!< 0x00000400 */
#define I2C_STS_OUF                         I2C_STS_OUF_Msk                         /*!< Overflow or underflow flag */
#define I2C_STS_PECERR_Pos                  (11U)
#define I2C_STS_PECERR_Msk                  (0x1U << I2C_STS_PECERR_Pos)            /*!< 0x00000800 */
#define I2C_STS_PECERR                      I2C_STS_PECERR_Msk                      /*!< PEC receive error flag */
#define I2C_STS_TMOUT_Pos                   (12U)
#define I2C_STS_TMOUT_Msk                   (0x1U << I2C_STS_TMOUT_Pos)             /*!< 0x00001000 */
#define I2C_STS_TMOUT                       I2C_STS_TMOUT_Msk                       /*!< SMBus timeout flag */
#define I2C_STS_ALERTF_Pos                  (13U)
#define I2C_STS_ALERTF_Msk                  (0x1U << I2C_STS_ALERTF_Pos)            /*!< 0x00002000 */
#define I2C_STS_ALERTF                      I2C_STS_ALERTF_Msk                      /*!< SMBus alert flag */
#define I2C_STS_BUSYF_Pos                   (15U)
#define I2C_STS_BUSYF_Msk                   (0x1U << I2C_STS_BUSYF_Pos)             /*!< 0x00008000 */
#define I2C_STS_BUSYF                       I2C_STS_BUSYF_Msk                       /*!< Bus busy flag transmission mode */
#define I2C_STS_SDIR_Pos                    (16U)
#define I2C_STS_SDIR_Msk                    (0x1U << I2C_STS_SDIR_Pos)              /*!< 0x00010000 */
#define I2C_STS_SDIR                        I2C_STS_SDIR_Msk                        /*!< Slave data transmit direction */
#define I2C_STS_ADDR_Pos                    (17U)
#define I2C_STS_ADDR_Msk                    (0x7FU << I2C_STS_ADDR_Pos)             /*!< 0x00FE0000 */
#define I2C_STS_ADDR                        I2C_STS_ADDR_Msk                        /*!< Slave address matching value */

/*******************  Bit definition for I2C_CLR register  ********************/
#define I2C_CLR_ADDRC_Pos                   (3U)
#define I2C_CLR_ADDRC_Msk                   (0x1U << I2C_CLR_ADDRC_Pos)             /*!< 0x00000008 */
#define I2C_CLR_ADDRC                       I2C_CLR_ADDRC_Msk                       /*!< Clear 0 ~ 7 bit address match flag */
#define I2C_CLR_ACKFAILC_Pos                (4U)
#define I2C_CLR_ACKFAILC_Msk                (0x1U << I2C_CLR_ACKFAILC_Pos)          /*!< 0x00000010 */
#define I2C_CLR_ACKFAILC                    I2C_CLR_ACKFAILC_Msk                    /*!< Clear acknowledge failure flag */
#define I2C_CLR_STOPC_Pos                   (5U)
#define I2C_CLR_STOPC_Msk                   (0x1U << I2C_CLR_STOPC_Pos)             /*!< 0x00000020 */
#define I2C_CLR_STOPC                       I2C_CLR_STOPC_Msk                       /*!< Clear stop condition generation complete flag */
#define I2C_CLR_BUSERRC_Pos                 (8U)
#define I2C_CLR_BUSERRC_Msk                 (0x1U << I2C_CLR_BUSERRC_Pos)           /*!< 0x00000100 */
#define I2C_CLR_BUSERRC                     I2C_CLR_BUSERRC_Msk                     /*!< Clear bus error flag */
#define I2C_CLR_ARLOSTC_Pos                 (9U)
#define I2C_CLR_ARLOSTC_Msk                 (0x1U << I2C_CLR_ARLOSTC_Pos)           /*!< 0x00000200 */
#define I2C_CLR_ARLOSTC                     I2C_CLR_ARLOSTC_Msk                     /*!< Clear arbitration lost flag */
#define I2C_CLR_OUFC_Pos                    (10U)
#define I2C_CLR_OUFC_Msk                    (0x1U << I2C_CLR_OUFC_Pos)              /*!< 0x00000400 */
#define I2C_CLR_OUFC                        I2C_CLR_OUFC_Msk                        /*!< Clear overload / underload flag */
#define I2C_CLR_PECERRC_Pos                 (11U)
#define I2C_CLR_PECERRC_Msk                 (0x1U << I2C_CLR_PECERRC_Pos)           /*!< 0x00000800 */
#define I2C_CLR_PECERRC                     I2C_CLR_PECERRC_Msk                     /*!< Clear PEC receive error flag */
#define I2C_CLR_TMOUTC_Pos                  (12U)
#define I2C_CLR_TMOUTC_Msk                  (0x1U << I2C_CLR_TMOUTC_Pos)            /*!< 0x00001000 */
#define I2C_CLR_TMOUTC                      I2C_CLR_TMOUTC_Msk                      /*!< Clear SMBus timeout flag */
#define I2C_CLR_ALERTC_Pos                  (13U)
#define I2C_CLR_ALERTC_Msk                  (0x1U << I2C_CLR_ALERTC_Pos)            /*!< 0x00002000 */
#define I2C_CLR_ALERTC                      I2C_CLR_ALERTC_Msk                      /*!< Clear SMBus alert flag */

/*******************  Bit definition for I2C_PEC register  ********************/
#define I2C_PEC_PECVAL_Pos                  (0U)
#define I2C_PEC_PECVAL_Msk                  (0xFFU << I2C_PEC_PECVAL_Pos)           /*!< 0x000000FF */
#define I2C_PEC_PECVAL                      I2C_PEC_PECVAL_Msk                      /*!< PEC value */

/*******************  Bit definition for I2C_RXDT register  *******************/
#define I2C_RXDT_DT_Pos                     (0U)
#define I2C_RXDT_DT_Msk                     (0xFFU << I2C_RXDT_DT_Pos)              /*!< 0x000000FF */
#define I2C_RXDT_DT                         I2C_RXDT_DT_Msk                         /*!< Receive data register */

/*******************  Bit definition for I2C_TXDT register  *******************/
#define I2C_TXDT_DT_Pos                     (0U)
#define I2C_TXDT_DT_Msk                     (0xFFU << I2C_TXDT_DT_Pos)              /*!< 0x000000FF */
#define I2C_TXDT_DT                         I2C_TXDT_DT_Msk                         /*!< Transmit data register */

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
#define USART_STS_RTODF_Pos                 (11U)
#define USART_STS_RTODF_Msk                 (0x1U << USART_STS_RTODF_Pos)           /*!< 0x00000800 */
#define USART_STS_RTODF                     USART_STS_RTODF_Msk                     /*!< Receiver timeout detection flag */
#define USART_STS_CMDF_Pos                  (17U)
#define USART_STS_CMDF_Msk                  (0x1U << USART_STS_CMDF_Pos)            /*!< 0x00020000 */
#define USART_STS_CMDF                      USART_STS_CMDF_Msk                      /*!< Byte match detection flag */

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
#define USART_CTRL1_DBN0_Pos                (12U)
#define USART_CTRL1_DBN0_Msk                (0x1U << USART_CTRL1_DBN0_Pos)          /*!< 0x00001000 */
#define USART_CTRL1_DBN0                    USART_CTRL1_DBN0_Msk                    /*!< Data bit num 0 */
#define USART_CTRL1_UEN_Pos                 (13U)
#define USART_CTRL1_UEN_Msk                 (0x1U << USART_CTRL1_UEN_Pos)           /*!< 0x00002000 */
#define USART_CTRL1_UEN                     USART_CTRL1_UEN_Msk                     /*!< USART enable */
#define USART_CTRL1_CMDIE_Pos               (14U)
#define USART_CTRL1_CMDIE_Msk               (0x1U << USART_CTRL1_CMDIE_Pos)         /*!< 0x00004000 */
#define USART_CTRL1_CMDIE                   USART_CTRL1_CMDIE_Msk                   /*!< Character match detection interrupt enable */
#define USART_CTRL1_TCDT_Pos                (16U)
#define USART_CTRL1_TCDT_Msk                (0x1FU << USART_CTRL1_TCDT_Pos)         /*!< 0x001F0000 */
#define USART_CTRL1_TCDT                    USART_CTRL1_TCDT_Msk                    /*!< Transmit complete delay time */
#define USART_CTRL1_TSDT_Pos                (21U)
#define USART_CTRL1_TSDT_Msk                (0x1FU << USART_CTRL1_TSDT_Pos)         /*!< 0x03E00000 */
#define USART_CTRL1_TSDT                    USART_CTRL1_TSDT_Msk                    /*!< Transmit start delay time */
#define USART_CTRL1_RETODIE_Pos             (26U)
#define USART_CTRL1_RETODIE_Msk             (0x1U << USART_CTRL1_RETODIE_Pos)       /*!< 0x04000000 */
#define USART_CTRL1_RETODIE                 USART_CTRL1_RETODIE_Msk                 /*!< Receiver timeout detection interrupt enable */
#define USART_CTRL1_RTODEN_Pos              (27U)
#define USART_CTRL1_RTODEN_Msk              (0x1U << USART_CTRL1_RTODEN_Pos)        /*!< 0x08000000 */
#define USART_CTRL1_RTODEN                  USART_CTRL1_RTODEN_Msk                  /*!< Receiver timeout detection enable */
#define USART_CTRL1_DBN1_Pos                (28U)
#define USART_CTRL1_DBN1_Msk                (0x1U << USART_CTRL1_DBN1_Pos)          /*!< 0x10000000 */
#define USART_CTRL1_DBN1                    USART_CTRL1_DBN1_Msk                    /*!< Data bit num 1 */

/*****************  Bit definition for USART_CTRL2 register  ******************/
#define USART_CTRL2_IDL_Pos                 (0U)
#define USART_CTRL2_IDL_Msk                 (0xFU << USART_CTRL2_IDL_Pos)           /*!< 0x0000000F */
#define USART_CTRL2_IDL                     USART_CTRL2_IDL_Msk                     /*!< USART identification low */
#define USART_CTRL2_IDBN_Pos                (4U)
#define USART_CTRL2_IDBN_Msk                (0x1U << USART_CTRL2_IDBN_Pos)          /*!< 0x00000010 */
#define USART_CTRL2_IDBN                    USART_CTRL2_IDBN_Msk                    /*!< Identification bit number */
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

/*!< STOPBN configuration */
#define USART_CTRL2_STOPBN_Pos              (12U)
#define USART_CTRL2_STOPBN_Msk              (0x3U << USART_CTRL2_STOPBN_Pos)        /*!< 0x00003000 */
#define USART_CTRL2_STOPBN                  USART_CTRL2_STOPBN_Msk                  /*!< STOPBN[1:0] bits (STOP bit num) */
#define USART_CTRL2_STOPBN_0                (0x1U << USART_CTRL2_STOPBN_Pos)        /*!< 0x00001000 */
#define USART_CTRL2_STOPBN_1                (0x2U << USART_CTRL2_STOPBN_Pos)        /*!< 0x00002000 */

#define USART_CTRL2_LINEN_Pos               (14U)
#define USART_CTRL2_LINEN_Msk               (0x1U << USART_CTRL2_LINEN_Pos)         /*!< 0x00004000 */
#define USART_CTRL2_LINEN                   USART_CTRL2_LINEN_Msk                   /*!< LIN mode enable */
#define USART_CTRL2_TRPSWAP_Pos             (15U)
#define USART_CTRL2_TRPSWAP_Msk             (0x1U << USART_CTRL2_TRPSWAP_Pos)       /*!< 0x00008000 */
#define USART_CTRL2_TRPSWAP                 USART_CTRL2_TRPSWAP_Msk                 /*!< Transmit/receive pin swap */
#define USART_CTRL2_RXREV_Pos               (16U)
#define USART_CTRL2_RXREV_Msk               (0x1U << USART_CTRL2_RXREV_Pos)         /*!< 0x00010000 */
#define USART_CTRL2_RXREV                   USART_CTRL2_RXREV_Msk                   /*!< RX polarity reverse */
#define USART_CTRL2_TXREV_Pos               (17U)
#define USART_CTRL2_TXREV_Msk               (0x1U << USART_CTRL2_TXREV_Pos)         /*!< 0x00020000 */
#define USART_CTRL2_TXREV                   USART_CTRL2_TXREV_Msk                   /*!< TX polarity reverse */
#define USART_CTRL2_DTREV_Pos               (18U)
#define USART_CTRL2_DTREV_Msk               (0x1U << USART_CTRL2_DTREV_Pos)         /*!< 0x00040000 */
#define USART_CTRL2_DTREV                   USART_CTRL2_DTREV_Msk                   /*!< DT register polarity reverse */
#define USART_CTRL2_MTF_Pos                 (19U)
#define USART_CTRL2_MTF_Msk                 (0x1U << USART_CTRL2_MTF_Pos)           /*!< 0x00080000 */
#define USART_CTRL2_MTF                     USART_CTRL2_MTF_Msk                     /*!< MSB transmit first */
#define USART_CTRL2_IDH_Pos                 (28U)
#define USART_CTRL2_IDH_Msk                 (0xFU << USART_CTRL2_IDH_Pos)           /*!< 0xF0000000 */
#define USART_CTRL2_IDH                     USART_CTRL2_IDH_Msk                     /*!< USART identification high */

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
#define USART_CTRL3_RS485EN_Pos             (14U)
#define USART_CTRL3_RS485EN_Msk             (0x1U << USART_CTRL3_RS485EN_Pos)       /*!< 0x00004000 */
#define USART_CTRL3_RS485EN                 USART_CTRL3_RS485EN_Msk                 /*!< RS485 enable */
#define USART_CTRL3_DEP_Pos                 (15U)
#define USART_CTRL3_DEP_Msk                 (0x1U << USART_CTRL3_DEP_Pos)           /*!< 0x00008000 */
#define USART_CTRL3_DEP                     USART_CTRL3_DEP_Msk                     /*!< DE polarity selection */

/******************  Bit definition for USART_GDIV register  ******************/
/*!< ISDIV configuration */
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
#define SPI_CTRL2_TIEN_Pos                  (4U)
#define SPI_CTRL2_TIEN_Msk                  (0x1U << SPI_CTRL2_TIEN_Pos)            /*!< 0x00000010 */
#define SPI_CTRL2_TIEN                      SPI_CTRL2_TIEN_Msk                      /*!< TI mode enable */
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
#define SPI_CTRL2_MDIV3EN_Pos               (9U)
#define SPI_CTRL2_MDIV3EN_Msk               (0x1U << SPI_CTRL2_MDIV3EN_Pos)         /*!< 0x00000200 */
#define SPI_CTRL2_MDIV3EN                   SPI_CTRL2_MDIV3EN_Msk                   /*!< Master clock frequency divided by 3 enable */

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
#define SPI_STS_CSPAS_Pos                   (8U)
#define SPI_STS_CSPAS_Msk                   (0x1U << SPI_STS_CSPAS_Pos)             /*!< 0x00000100 */
#define SPI_STS_CSPAS                       SPI_STS_CSPAS_Msk                       /*!< CS pulse abnormal setting flag */

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

/*!< I2SDBN configuration */
#define SPI_I2SCTRL_I2SDBN_Pos              (1U)
#define SPI_I2SCTRL_I2SDBN_Msk              (0x3U << SPI_I2SCTRL_I2SDBN_Pos)        /*!< 0x00000006 */
#define SPI_I2SCTRL_I2SDBN                  SPI_I2SCTRL_I2SDBN_Msk                  /*!< I2SDBN[1:0] bits (I2S data bit num) */
#define SPI_I2SCTRL_I2SDBN_0                (0x1U << SPI_I2SCTRL_I2SDBN_Pos)        /*!< 0x00000002 */
#define SPI_I2SCTRL_I2SDBN_1                (0x2U << SPI_I2SCTRL_I2SDBN_Pos)        /*!< 0x00000004 */

#define SPI_I2SCTRL_I2SCLKPOL_Pos           (3U)
#define SPI_I2SCTRL_I2SCLKPOL_Msk           (0x1U << SPI_I2SCTRL_I2SCLKPOL_Pos)     /*!< 0x00000008 */
#define SPI_I2SCTRL_I2SCLKPOL               SPI_I2SCTRL_I2SCLKPOL_Msk               /*!< I2S clock polarity */

/*!< STDSEL configuration */
#define SPI_I2SCTRL_STDSEL_Pos              (4U)
#define SPI_I2SCTRL_STDSEL_Msk              (0x3U << SPI_I2SCTRL_STDSEL_Pos)        /*!< 0x00000030 */
#define SPI_I2SCTRL_STDSEL                  SPI_I2SCTRL_STDSEL_Msk                  /*!< STDSEL[1:0] bits (I2S standard select) */
#define SPI_I2SCTRL_STDSEL_0                (0x1U << SPI_I2SCTRL_STDSEL_Pos)        /*!< 0x00000010 */
#define SPI_I2SCTRL_STDSEL_1                (0x2U << SPI_I2SCTRL_STDSEL_Pos)        /*!< 0x00000020 */

#define SPI_I2SCTRL_PCMFSSEL_Pos            (7U)
#define SPI_I2SCTRL_PCMFSSEL_Msk            (0x1U << SPI_I2SCTRL_PCMFSSEL_Pos)      /*!< 0x00000080 */
#define SPI_I2SCTRL_PCMFSSEL                SPI_I2SCTRL_PCMFSSEL_Msk                /*!< PCM frame synchronization */

/*!< OPERSEL configuration */
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
#define SPI_I2SCTRL_I2SFDUPEN_Pos           (13U)
#define SPI_I2SCTRL_I2SFDUPEN_Msk           (0x1U << SPI_I2SCTRL_I2SFDUPEN_Pos)     /*!< 0x00002000 */
#define SPI_I2SCTRL_I2SFDUPEN               SPI_I2SCTRL_I2SFDUPEN_Msk               /*!< I2S full duplex enable */

/*****************  Bit definition for SPI_I2SCLKP register  ******************/
#define SPI_I2SCLKP_I2SDIV_Msk              ((0xFFU << 0) | (0x3U << 10))           /*!< 0x00000CFF */
#define SPI_I2SCLKP_I2SDIV                  SPI_I2SCLKP_I2SDIV_Msk                  /*!< I2SDIV[9:0] bits (I2S division) */
#define SPI_I2SCLKP_I2SODD_Pos              (8U)
#define SPI_I2SCLKP_I2SODD_Msk              (0x1U << SPI_I2SCLKP_I2SODD_Pos)        /*!< 0x00000100 */
#define SPI_I2SCLKP_I2SODD                  SPI_I2SCLKP_I2SODD_Msk                  /*!< Odd factor for I2S division */
#define SPI_I2SCLKP_I2SMCLKOE_Pos           (9U)
#define SPI_I2SCLKP_I2SMCLKOE_Msk           (0x1U << SPI_I2SCLKP_I2SMCLKOE_Pos)     /*!< 0x00000200 */
#define SPI_I2SCLKP_I2SMCLKOE               SPI_I2SCLKP_I2SMCLKOE_Msk               /*!< I2S Master clock output enable */

/******************  Bit definition for SPI_MISC1 register  *******************/
#define SPI_MISC1_I2SFPCMCKSEL_Pos          (0U)
#define SPI_MISC1_I2SFPCMCKSEL_Msk          (0x1U << SPI_MISC1_I2SFPCMCKSEL_Pos)    /*!< 0x00000001 */
#define SPI_MISC1_I2SFPCMCKSEL              SPI_MISC1_I2SFPCMCKSEL_Msk              /*!< I2S PCM clock edge select */

/******************************************************************************/
/*                                                                            */
/*                        Window watchdog timer (WWDT)                        */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for WWDT_CTRL register  *******************/
/*!< CNT configuration */
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
/*!< WIN configuration */
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

/*!< DIV configuration */
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
/*!< DIV configuration */
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
#define WDT_STS_WINF_Pos                    (2U)
#define WDT_STS_WINF_Msk                    (0x1U << WDT_STS_WINF_Pos)              /*!< 0x00000004 */
#define WDT_STS_WINF                        WDT_STS_WINF_Msk                        /*!< Window value update complete flag */

/*******************  Bit definition for WDT_WIN register  ********************/
#define WDT_WIN_WIN_Pos                     (0U)
#define WDT_WIN_WIN_Msk                     (0xFFFU << WDT_WIN_WIN_Pos)             /*!< 0x00000FFF */
#define WDT_WIN_WIN                         WDT_WIN_WIN_Msk                         /*!< Window value */

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
#define ADC_STS_OCCO_Pos                    (5U)
#define ADC_STS_OCCO_Msk                    (0x1U << ADC_STS_OCCO_Pos)              /*!< 0x00000020 */
#define ADC_STS_OCCO                        ADC_STS_OCCO_Msk                        /*!< Ordinary channel conversion overflow flag */
#define ADC_STS_RDY_Pos                     (6U)
#define ADC_STS_RDY_Msk                     (0x1U << ADC_STS_RDY_Pos)              /*!< 0x00000040 */
#define ADC_STS_RDY                         ADC_STS_RDY_Msk                        /*!< ADC ready to conversion flag */

/* Legacy defines */
#define ADC_STS_OCCE                        (ADC_STS_OCCC)
#define ADC_STS_PCCE                        (ADC_STS_PCCC)

/******************  Bit definition for ADC_CTRL1 register  *******************/
/*!< VMCSEL configuration */
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

/*!< OCPCNT configuration */
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
#define ADC_CTRL1_OCVMEN_Pos                (23U)
#define ADC_CTRL1_OCVMEN_Msk                (0x1U << ADC_CTRL1_OCVMEN_Pos)          /*!< 0x00400000 */
#define ADC_CTRL1_OCVMEN                    ADC_CTRL1_OCVMEN_Msk                    /*!< Voltage monitoring enableon ordinary channels */
#define ADC_CTRL1_CRSEL_Pos                 (24U)
#define ADC_CTRL1_CRSEL_Msk                 (0x3U << ADC_CTRL1_CRSEL_Pos)           /*!< 0x0000E000 */
#define ADC_CTRL1_CRSEL                     ADC_CTRL1_CRSEL_Msk                     /*!< CRSEL[1:0] bits Conversion resolution select */
#define ADC_CTRL1_CRSEL_0                   (0x01U << ADC_CTRL1_CRSEL_Pos)          /*!< 0x00000001 */
#define ADC_CTRL1_CRSEL_1                   (0x02U << ADC_CTRL1_CRSEL_Pos)          /*!< 0x00000002 */
#define ADC_CTRL1_CRSEL_12                  0x00000000U
#define ADC_CTRL1_CRSEL_10                  ADC_CTRL1_CRSEL_0
#define ADC_CTRL1_CRSEL_8                   ADC_CTRL1_CRSEL_1
#define ADC_CTRL1_CRSEL_6                   (ADC_CTRL1_CRSEL_0 | ADC_CTRL1_CRSEL_1)
#define ADC_CTRL1_OCCOIE_Pos                (26U)
#define ADC_CTRL1_OCCOIE_Msk                (0x1U << ADC_CTRL1_OCCOIE_Pos)          /*!< 0x00400000 */
#define ADC_CTRL1_OCCOIE                    ADC_CTRL1_OCCOIE_Msk                    /*!< Ordinary channel conversion overflow interrupt enable */

/* Legacy defines */
#define ADC_CTRL1_CCEIEN                    (ADC_CTRL1_CCCIEN)
#define ADC_CTRL1_PCCEIEN                   (ADC_CTRL1_PCCCIEN)

/******************  Bit definition for ADC_CTRL2 register  *******************/
#define ADC_CTRL2_ADCEN_Pos                 (0U)
#define ADC_CTRL2_ADCEN_Msk                 (0x1U << ADC_CTRL2_ADCEN_Pos)           /*!< 0x00000001 */
#define ADC_CTRL2_ADCEN                     ADC_CTRL2_ADCEN_Msk                     /*!< A/D converter enable */
#define ADC_CTRL2_RPEN_Pos                  (1U)
#define ADC_CTRL2_RPEN_Msk                  (0x1U << ADC_CTRL2_RPEN_Pos)            /*!< 0x00000002 */
#define ADC_CTRL2_RPEN                      ADC_CTRL2_RPEN_Msk                      /*!< Repetition mode enable */
#define ADC_CTRL2_ADCAL_Pos                 (2U)
#define ADC_CTRL2_ADCAL_Msk                 (0x1U << ADC_CTRL2_ADCAL_Pos)           /*!< 0x00000004 */
#define ADC_CTRL2_ADCAL                     ADC_CTRL2_ADCAL_Msk                     /*!< A/D calibration */
#define ADC_CTRL2_ADCALINIT_Pos             (3U)
#define ADC_CTRL2_ADCALINIT_Msk             (0x1U << ADC_CTRL2_ADCALINIT_Pos)       /*!< 0x00000008 */
#define ADC_CTRL2_ADCALINIT                 ADC_CTRL2_ADCALINIT_Msk                 /*!< Initialize A/D calibration */
#define ADC_CTRL2_ADABRT_Pos                (4U)
#define ADC_CTRL2_ADABRT_Msk                (0x1U << ADC_CTRL2_ADABRT_Pos)          /*!< 0x00000010 */
#define ADC_CTRL2_ADABRT                    ADC_CTRL2_ADABRT_Msk                    /*!< ADC conversion abort */
#define ADC_CTRL2_OCDMAEN_Pos               (8U)
#define ADC_CTRL2_OCDMAEN_Msk               (0x1U << ADC_CTRL2_OCDMAEN_Pos)         /*!< 0x00000100 */
#define ADC_CTRL2_OCDMAEN                   ADC_CTRL2_OCDMAEN_Msk                   /*!< DMA transfer enable of ordinary channels */
#define ADC_CTRL2_OCDRCEN_Pos               (9U)
#define ADC_CTRL2_OCDRCEN_Msk               (0x1U << ADC_CTRL2_OCDRCEN_Pos)         /*!< 0x00000200 */
#define ADC_CTRL2_OCDRCEN                   ADC_CTRL2_OCDRCEN_Msk                   /*!< Ordinary channels DMA request continuation enable for independent mode */
#define ADC_CTRL2_EOCSFEN_Pos               (10U)
#define ADC_CTRL2_EOCSFEN_Msk               (0x1U << ADC_CTRL2_EOCSFEN_Pos)         /*!< 0x00000400 */
#define ADC_CTRL2_EOCSFEN                   ADC_CTRL2_EOCSFEN_Msk                   /*!< Each ordinary channel conversion set OCCE flag enable */
#define ADC_CTRL2_DTALIGN_Pos               (11U)
#define ADC_CTRL2_DTALIGN_Msk               (0x1U << ADC_CTRL2_DTALIGN_Pos)         /*!< 0x00000800 */
#define ADC_CTRL2_DTALIGN                   ADC_CTRL2_DTALIGN_Msk                   /*!< Data alignment */

/*!< PCTESEL configuration */
#define ADC_CTRL2_PCTESEL_Pos               (16U)
#define ADC_CTRL2_PCTESEL_Msk               ((0xFU << ADC_CTRL2_PCTESEL_Pos) | (0x1U << 23))         /*!< 0x008F0000 */
#define ADC_CTRL2_PCTESEL                   ADC_CTRL2_PCTESEL_Msk                   /*!< PCTESEL[4:0] bits Trigger event select for preempted channels conversion */
#define ADC_CTRL2_PCTESEL_0                 (0x1U << ADC_CTRL2_PCTESEL_Pos)         /*!< 0x00010000 */
#define ADC_CTRL2_PCTESEL_1                 (0x2U << ADC_CTRL2_PCTESEL_Pos)         /*!< 0x00020000 */
#define ADC_CTRL2_PCTESEL_2                 (0x4U << ADC_CTRL2_PCTESEL_Pos)         /*!< 0x00040000 */
#define ADC_CTRL2_PCTESEL_3                 (0x8U << ADC_CTRL2_PCTESEL_Pos)         /*!< 0x00080000 */
#define ADC_CTRL2_PCTESEL_4                 (0x1U << 23)                            /*!< 0x00800000 */
#define ADC_CTRL2_PCETE_Pos                 (20U)
#define ADC_CTRL2_PCETE_Msk                 (0x3U << ADC_CTRL2_PCETE_Pos)           /*!< 0x00300000 */
#define ADC_CTRL2_PCETE                     ADC_CTRL2_PCETE_Msk                     /*!< PCTESEL[1:0] bits Preempted channels external trigger edge select */
#define ADC_CTRL2_PCETE_0                   (0x1U << ADC_CTRL2_PCTESEL_Pos)         /*!< 0x00100000 */
#define ADC_CTRL2_PCETE_1                   (0x2U << ADC_CTRL2_PCTESEL_Pos)         /*!< 0x00200000 */
#define ADC_CTRL2_PCETE_DISABLE             (0U)
#define ADC_CTRL2_PCETE_RISING              ADC_CTRL2_PCETE_0
#define ADC_CTRL2_PCETE_FALLING             ADC_CTRL2_PCETE_1
#define ADC_CTRL2_PCETE_ANY                 ADC_CTRL2_PCETE
#define ADC_CTRL2_PCTEN                     ADC_CTRL2_PCETE_RISING 
#define ADC_CTRL2_PCSWTRG_Pos               (22U)
#define ADC_CTRL2_PCSWTRG_Msk               (0x1U << ADC_CTRL2_PCSWTRG_Pos)         /*!< 0x00400000 */
#define ADC_CTRL2_PCSWTRG                   ADC_CTRL2_PCSWTRG_Msk                   /*!< Conversion of preempted channels triggered by software */

/*!< OCTESEL configuration */
#define ADC_CTRL2_OCTESEL_Pos               (24U)
#define ADC_CTRL2_OCTESEL_Msk               ((0xFU << ADC_CTRL2_OCTESEL_Pos)  | (0x1U << 31))         /*!< 0x8F000000 */
#define ADC_CTRL2_OCTESEL                   ADC_CTRL2_OCTESEL_Msk                   /*!< OCTESEL[4:0] bits Trigger event select for ordinary channels conversion */
#define ADC_CTRL2_OCTESEL_0                 (0x1U << ADC_CTRL2_OCTESEL_Pos)         /*!< 0x01000000 */
#define ADC_CTRL2_OCTESEL_1                 (0x2U << ADC_CTRL2_OCTESEL_Pos)         /*!< 0x02000000 */
#define ADC_CTRL2_OCTESEL_2                 (0x4U << ADC_CTRL2_OCTESEL_Pos)         /*!< 0x03000000 */
#define ADC_CTRL2_OCTESEL_3                 (0x8U << ADC_CTRL2_OCTESEL_Pos)         /*!< 0x04000000 */
#define ADC_CTRL2_OCTESEL_4                 (0x1U << 31)                            /*!< 0x80000000 */
#define ADC_CTRL2_OCETE_Pos                 (28U)
#define ADC_CTRL2_OCETE_Msk                 (0x3U << ADC_CTRL2_OCETE_Pos)           /*!< 0x30000000 */
#define ADC_CTRL2_OCETE                     ADC_CTRL2_OCETE_Msk                     /*!< OCETE[1:0] bitsO rdinary channels external trigger edge select */
#define ADC_CTRL2_OCETE_0                   (0x1U << ADC_CTRL2_OCETE_Pos)           /*!< 0x10000000 */
#define ADC_CTRL2_OCETE_1                   (0x2U << ADC_CTRL2_OCETE_Pos)           /*!< 0x20000000 */
#define ADC_CTRL2_OCETE_DISABLE             (0U)
#define ADC_CTRL2_OCETE_RISING              ADC_CTRL2_OCETE_0
#define ADC_CTRL2_OCETE_FALLING             ADC_CTRL2_OCETE_1
#define ADC_CTRL2_OCETE_ANY                 ADC_CTRL2_OCETE
#define ADC_CTRL2_OCTEN                     ADC_CTRL2_OCETE_RISING 
#define ADC_CTRL2_OCSWTRG_Pos               (30U)
#define ADC_CTRL2_OCSWTRG_Msk               (0x1U << ADC_CTRL2_OCSWTRG_Pos)         /*!< 0x00400000 */
#define ADC_CTRL2_OCSWTRG                   ADC_CTRL2_OCSWTRG_Msk                   /*!< Conversion of ordinary channels triggered by software */

/*******************  Bit definition for ADC_SPT1 register  *******************/
/*!< CSPT10 configuration */
#define ADC_SPT1_CSPT10_Pos                 (0U)
#define ADC_SPT1_CSPT10_Msk                 (0x7U << ADC_SPT1_CSPT10_Pos)           /*!< 0x00000007 */
#define ADC_SPT1_CSPT10                     ADC_SPT1_CSPT10_Msk                     /*!< CSPT10[2:0] bits (Sample time selection of channel ADC_IN10) */
#define ADC_SPT1_CSPT10_0                   (0x1U << ADC_SPT1_CSPT10_Pos)           /*!< 0x00000001 */
#define ADC_SPT1_CSPT10_1                   (0x2U << ADC_SPT1_CSPT10_Pos)           /*!< 0x00000002 */
#define ADC_SPT1_CSPT10_2                   (0x4U << ADC_SPT1_CSPT10_Pos)           /*!< 0x00000004 */

/*!< CSPT11 configuration */
#define ADC_SPT1_CSPT11_Pos                 (3U)
#define ADC_SPT1_CSPT11_Msk                 (0x7U << ADC_SPT1_CSPT11_Pos)           /*!< 0x00000038 */
#define ADC_SPT1_CSPT11                     ADC_SPT1_CSPT11_Msk                     /*!< CSPT11[2:0] bits (Sample time selection of channel ADC_IN11) */
#define ADC_SPT1_CSPT11_0                   (0x1U << ADC_SPT1_CSPT11_Pos)           /*!< 0x00000008 */
#define ADC_SPT1_CSPT11_1                   (0x2U << ADC_SPT1_CSPT11_Pos)           /*!< 0x00000010 */
#define ADC_SPT1_CSPT11_2                   (0x4U << ADC_SPT1_CSPT11_Pos)           /*!< 0x00000020 */

/*!< CSPT12 configuration */
#define ADC_SPT1_CSPT12_Pos                 (6U)
#define ADC_SPT1_CSPT12_Msk                 (0x7U << ADC_SPT1_CSPT12_Pos)           /*!< 0x000001C0 */
#define ADC_SPT1_CSPT12                     ADC_SPT1_CSPT12_Msk                     /*!< CSPT12[2:0] bits (Sample time selection of channel ADC_IN12) */
#define ADC_SPT1_CSPT12_0                   (0x1U << ADC_SPT1_CSPT12_Pos)           /*!< 0x00000040 */
#define ADC_SPT1_CSPT12_1                   (0x2U << ADC_SPT1_CSPT12_Pos)           /*!< 0x00000080 */
#define ADC_SPT1_CSPT12_2                   (0x4U << ADC_SPT1_CSPT12_Pos)           /*!< 0x00000100 */

/*!< CSPT13 configuration */
#define ADC_SPT1_CSPT13_Pos                 (9U)
#define ADC_SPT1_CSPT13_Msk                 (0x7U << ADC_SPT1_CSPT13_Pos)           /*!< 0x00000E00 */
#define ADC_SPT1_CSPT13                     ADC_SPT1_CSPT13_Msk                     /*!< CSPT13[2:0] bits (Sample time selection of channel ADC_IN13) */
#define ADC_SPT1_CSPT13_0                   (0x1U << ADC_SPT1_CSPT13_Pos)           /*!< 0x00000200 */
#define ADC_SPT1_CSPT13_1                   (0x2U << ADC_SPT1_CSPT13_Pos)           /*!< 0x00000400 */
#define ADC_SPT1_CSPT13_2                   (0x4U << ADC_SPT1_CSPT13_Pos)           /*!< 0x00000800 */

/*!< CSPT14 configuration */
#define ADC_SPT1_CSPT14_Pos                 (12U)
#define ADC_SPT1_CSPT14_Msk                 (0x7U << ADC_SPT1_CSPT14_Pos)           /*!< 0x00007000 */
#define ADC_SPT1_CSPT14                     ADC_SPT1_CSPT14_Msk                     /*!< CSPT14[2:0] bits (Sample time selection of channel ADC_IN14) */
#define ADC_SPT1_CSPT14_0                   (0x1U << ADC_SPT1_CSPT14_Pos)           /*!< 0x00001000 */
#define ADC_SPT1_CSPT14_1                   (0x2U << ADC_SPT1_CSPT14_Pos)           /*!< 0x00002000 */
#define ADC_SPT1_CSPT14_2                   (0x4U << ADC_SPT1_CSPT14_Pos)           /*!< 0x00004000 */

/*!< CSPT15 configuration */
#define ADC_SPT1_CSPT15_Pos                 (15U)
#define ADC_SPT1_CSPT15_Msk                 (0x7U << ADC_SPT1_CSPT15_Pos)           /*!< 0x00038000 */
#define ADC_SPT1_CSPT15                     ADC_SPT1_CSPT15_Msk                     /*!< CSPT15[2:0] bits (Sample time selection of channel ADC_IN15) */
#define ADC_SPT1_CSPT15_0                   (0x1U << ADC_SPT1_CSPT15_Pos)           /*!< 0x00008000 */
#define ADC_SPT1_CSPT15_1                   (0x2U << ADC_SPT1_CSPT15_Pos)           /*!< 0x00010000 */
#define ADC_SPT1_CSPT15_2                   (0x4U << ADC_SPT1_CSPT15_Pos)           /*!< 0x00020000 */

/*!< CSPT16 configuration */
#define ADC_SPT1_CSPT16_Pos                 (18U)
#define ADC_SPT1_CSPT16_Msk                 (0x7U << ADC_SPT1_CSPT16_Pos)           /*!< 0x001C0000 */
#define ADC_SPT1_CSPT16                     ADC_SPT1_CSPT16_Msk                     /*!< CSPT16[2:0] bits (Sample time selection of channel ADC_IN16) */
#define ADC_SPT1_CSPT16_0                   (0x1U << ADC_SPT1_CSPT16_Pos)           /*!< 0x00040000 */
#define ADC_SPT1_CSPT16_1                   (0x2U << ADC_SPT1_CSPT16_Pos)           /*!< 0x00080000 */
#define ADC_SPT1_CSPT16_2                   (0x4U << ADC_SPT1_CSPT16_Pos)           /*!< 0x00100000 */

/*!< CSPT17 configuration */
#define ADC_SPT1_CSPT17_Pos                 (21U)
#define ADC_SPT1_CSPT17_Msk                 (0x7U << ADC_SPT1_CSPT17_Pos)           /*!< 0x00E00000 */
#define ADC_SPT1_CSPT17                     ADC_SPT1_CSPT17_Msk                     /*!< CSPT17[2:0] bits (Sample time selection of channel ADC_IN17) */
#define ADC_SPT1_CSPT17_0                   (0x1U << ADC_SPT1_CSPT17_Pos)           /*!< 0x00200000 */
#define ADC_SPT1_CSPT17_1                   (0x2U << ADC_SPT1_CSPT17_Pos)           /*!< 0x00400000 */
#define ADC_SPT1_CSPT17_2                   (0x4U << ADC_SPT1_CSPT17_Pos)           /*!< 0x00800000 */

/*!< CSPT18 configuration */
#define ADC_SPT1_CSPT18_Pos                 (24U)
#define ADC_SPT1_CSPT18_Msk                 (0x7U << ADC_SPT1_CSPT18_Pos)           /*!< 0x07000000 */
#define ADC_SPT1_CSPT18                     ADC_SPT1_CSPT18_Msk                     /*!< CSPT18[2:0] bits (Sample time selection of channel ADC_IN18) */
#define ADC_SPT1_CSPT18_0                   (0x1U << ADC_SPT1_CSPT18_Pos)           /*!< 0x01000000 */
#define ADC_SPT1_CSPT18_1                   (0x2U << ADC_SPT1_CSPT18_Pos)           /*!< 0x02000000 */
#define ADC_SPT1_CSPT18_2                   (0x4U << ADC_SPT1_CSPT18_Pos)           /*!< 0x04000000 */

/*******************  Bit definition for ADC_SPT2 register  *******************/
/*!< CSPT0 configuration */
#define ADC_SPT2_CSPT0_Pos                  (0U)
#define ADC_SPT2_CSPT0_Msk                  (0x7U << ADC_SPT2_CSPT0_Pos)            /*!< 0x00000007 */
#define ADC_SPT2_CSPT0                      ADC_SPT2_CSPT0_Msk                      /*!< CSPT0[2:0] bits (Sample time selection of channel ADC_IN0) */
#define ADC_SPT2_CSPT0_0                    (0x1U << ADC_SPT2_CSPT0_Pos)            /*!< 0x00000001 */
#define ADC_SPT2_CSPT0_1                    (0x2U << ADC_SPT2_CSPT0_Pos)            /*!< 0x00000002 */
#define ADC_SPT2_CSPT0_2                    (0x4U << ADC_SPT2_CSPT0_Pos)            /*!< 0x00000004 */

/*!< CSPT1 configuration */
#define ADC_SPT2_CSPT1_Pos                  (3U)
#define ADC_SPT2_CSPT1_Msk                  (0x7U << ADC_SPT2_CSPT1_Pos)            /*!< 0x00000038 */
#define ADC_SPT2_CSPT1                      ADC_SPT2_CSPT1_Msk                      /*!< CSPT1[2:0] bits (Sample time selection of channel ADC_IN1) */
#define ADC_SPT2_CSPT1_0                    (0x1U << ADC_SPT2_CSPT1_Pos)            /*!< 0x00000008 */
#define ADC_SPT2_CSPT1_1                    (0x2U << ADC_SPT2_CSPT1_Pos)            /*!< 0x00000010 */
#define ADC_SPT2_CSPT1_2                    (0x4U << ADC_SPT2_CSPT1_Pos)            /*!< 0x00000020 */

/*!< CSPT2 configuration */
#define ADC_SPT2_CSPT2_Pos                  (6U)
#define ADC_SPT2_CSPT2_Msk                  (0x7U << ADC_SPT2_CSPT2_Pos)            /*!< 0x000001C0 */
#define ADC_SPT2_CSPT2                      ADC_SPT2_CSPT2_Msk                      /*!< CSPT2[2:0] bits (Sample time selection of channel ADC_IN2) */
#define ADC_SPT2_CSPT2_0                    (0x1U << ADC_SPT2_CSPT2_Pos)            /*!< 0x00000040 */
#define ADC_SPT2_CSPT2_1                    (0x2U << ADC_SPT2_CSPT2_Pos)            /*!< 0x00000080 */
#define ADC_SPT2_CSPT2_2                    (0x4U << ADC_SPT2_CSPT2_Pos)            /*!< 0x00000100 */

/*!< CSPT3 configuration */
#define ADC_SPT2_CSPT3_Pos                  (9U)
#define ADC_SPT2_CSPT3_Msk                  (0x7U << ADC_SPT2_CSPT3_Pos)            /*!< 0x00000E00 */
#define ADC_SPT2_CSPT3                      ADC_SPT2_CSPT3_Msk                      /*!< CSPT3[2:0] bits (Sample time selection of channel ADC_IN3) */
#define ADC_SPT2_CSPT3_0                    (0x1U << ADC_SPT2_CSPT3_Pos)            /*!< 0x00000200 */
#define ADC_SPT2_CSPT3_1                    (0x2U << ADC_SPT2_CSPT3_Pos)            /*!< 0x00000400 */
#define ADC_SPT2_CSPT3_2                    (0x4U << ADC_SPT2_CSPT3_Pos)            /*!< 0x00000800 */

/*!< CSPT4 configuration */
#define ADC_SPT2_CSPT4_Pos                  (12U)
#define ADC_SPT2_CSPT4_Msk                  (0x7U << ADC_SPT2_CSPT4_Pos)            /*!< 0x00007000 */
#define ADC_SPT2_CSPT4                      ADC_SPT2_CSPT4_Msk                      /*!< CSPT4[2:0] bits (Sample time selection of channel ADC_IN4) */
#define ADC_SPT2_CSPT4_0                    (0x1U << ADC_SPT2_CSPT4_Pos)            /*!< 0x00001000 */
#define ADC_SPT2_CSPT4_1                    (0x2U << ADC_SPT2_CSPT4_Pos)            /*!< 0x00002000 */
#define ADC_SPT2_CSPT4_2                    (0x4U << ADC_SPT2_CSPT4_Pos)            /*!< 0x00004000 */

/*!< CSPT5 configuration */
#define ADC_SPT2_CSPT5_Pos                  (15U)
#define ADC_SPT2_CSPT5_Msk                  (0x7U << ADC_SPT2_CSPT5_Pos)            /*!< 0x00038000 */
#define ADC_SPT2_CSPT5                      ADC_SPT2_CSPT5_Msk                      /*!< CSPT5[2:0] bits (Sample time selection of channel ADC_IN5) */
#define ADC_SPT2_CSPT5_0                    (0x1U << ADC_SPT2_CSPT5_Pos)            /*!< 0x00008000 */
#define ADC_SPT2_CSPT5_1                    (0x2U << ADC_SPT2_CSPT5_Pos)            /*!< 0x00010000 */
#define ADC_SPT2_CSPT5_2                    (0x4U << ADC_SPT2_CSPT5_Pos)            /*!< 0x00020000 */

/*!< CSPT6 configuration */
#define ADC_SPT2_CSPT6_Pos                  (18U)
#define ADC_SPT2_CSPT6_Msk                  (0x7U << ADC_SPT2_CSPT6_Pos)            /*!< 0x001C0000 */
#define ADC_SPT2_CSPT6                      ADC_SPT2_CSPT6_Msk                      /*!< CSPT6[2:0] bits (Sample time selection of channel ADC_IN6) */
#define ADC_SPT2_CSPT6_0                    (0x1U << ADC_SPT2_CSPT6_Pos)            /*!< 0x00040000 */
#define ADC_SPT2_CSPT6_1                    (0x2U << ADC_SPT2_CSPT6_Pos)            /*!< 0x00080000 */
#define ADC_SPT2_CSPT6_2                    (0x4U << ADC_SPT2_CSPT6_Pos)            /*!< 0x00100000 */

/*!< CSPT7 configuration */
#define ADC_SPT2_CSPT7_Pos                  (21U)
#define ADC_SPT2_CSPT7_Msk                  (0x7U << ADC_SPT2_CSPT7_Pos)            /*!< 0x00E00000 */
#define ADC_SPT2_CSPT7                      ADC_SPT2_CSPT7_Msk                      /*!< CSPT7[2:0] bits (Sample time selection of channel ADC_IN7) */
#define ADC_SPT2_CSPT7_0                    (0x1U << ADC_SPT2_CSPT7_Pos)            /*!< 0x00200000 */
#define ADC_SPT2_CSPT7_1                    (0x2U << ADC_SPT2_CSPT7_Pos)            /*!< 0x00400000 */
#define ADC_SPT2_CSPT7_2                    (0x4U << ADC_SPT2_CSPT7_Pos)            /*!< 0x00800000 */

/*!< CSPT8 configuration */
#define ADC_SPT2_CSPT8_Pos                  (24U)
#define ADC_SPT2_CSPT8_Msk                  (0x7U << ADC_SPT2_CSPT8_Pos)            /*!< 0x07000000 */
#define ADC_SPT2_CSPT8                      ADC_SPT2_CSPT8_Msk                      /*!< CSPT8[2:0] bits (Sample time selection of channel ADC_IN8) */
#define ADC_SPT2_CSPT8_0                    (0x1U << ADC_SPT2_CSPT8_Pos)            /*!< 0x01000000 */
#define ADC_SPT2_CSPT8_1                    (0x2U << ADC_SPT2_CSPT8_Pos)            /*!< 0x02000000 */
#define ADC_SPT2_CSPT8_2                    (0x4U << ADC_SPT2_CSPT8_Pos)            /*!< 0x04000000 */

/*!< CSPT9 configuration */
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
#define ADC_VMHB_VMHB_Msk                   (0xFFFFU << ADC_VMHB_VMHB_Pos)          /*!< 0x0000FFFF */
#define ADC_VMHB_VMHB                       ADC_VMHB_VMHB_Msk                       /*!< Voltage monitoring high boundary */

/*******************  Bit definition for ADC_VMLB register  ********************/
#define ADC_VMLB_VMLB_Pos                   (0U)
#define ADC_VMLB_VMLB_Msk                   (0xFFFFU << ADC_VMLB_VMLB_Pos)          /*!< 0x0000FFFF */
#define ADC_VMLB_VMLB                       ADC_VMLB_VMLB_Msk                       /*!< Voltage monitoring low boundary */

/*******************  Bit definition for ADC_OSQ1 register  *******************/
/*!< OSN13 configuration */
#define ADC_OSQ1_OSN13_Pos                  (0U)
#define ADC_OSQ1_OSN13_Msk                  (0x1FU << ADC_OSQ1_OSN13_Pos)           /*!< 0x0000001F */
#define ADC_OSQ1_OSN13                      ADC_OSQ1_OSN13_Msk                      /*!< OSN13[4:0] bits (Number of 13th conversion in ordinary sequence) */
#define ADC_OSQ1_OSN13_0                    (0x01U << ADC_OSQ1_OSN13_Pos)           /*!< 0x00000001 */
#define ADC_OSQ1_OSN13_1                    (0x02U << ADC_OSQ1_OSN13_Pos)           /*!< 0x00000002 */
#define ADC_OSQ1_OSN13_2                    (0x04U << ADC_OSQ1_OSN13_Pos)           /*!< 0x00000004 */
#define ADC_OSQ1_OSN13_3                    (0x08U << ADC_OSQ1_OSN13_Pos)           /*!< 0x00000008 */
#define ADC_OSQ1_OSN13_4                    (0x10U << ADC_OSQ1_OSN13_Pos)           /*!< 0x00000010 */

/*!< OSN14 configuration */
#define ADC_OSQ1_OSN14_Pos                  (5U)
#define ADC_OSQ1_OSN14_Msk                  (0x1FU << ADC_OSQ1_OSN14_Pos)           /*!< 0x000003E0 */
#define ADC_OSQ1_OSN14                      ADC_OSQ1_OSN14_Msk                      /*!< OSN14[4:0] bits (Number of 14th conversion in ordinary sequence) */
#define ADC_OSQ1_OSN14_0                    (0x01U << ADC_OSQ1_OSN14_Pos)           /*!< 0x00000020 */
#define ADC_OSQ1_OSN14_1                    (0x02U << ADC_OSQ1_OSN14_Pos)           /*!< 0x00000040 */
#define ADC_OSQ1_OSN14_2                    (0x04U << ADC_OSQ1_OSN14_Pos)           /*!< 0x00000080 */
#define ADC_OSQ1_OSN14_3                    (0x08U << ADC_OSQ1_OSN14_Pos)           /*!< 0x00000100 */
#define ADC_OSQ1_OSN14_4                    (0x10U << ADC_OSQ1_OSN14_Pos)           /*!< 0x00000200 */

/*!< OSN15 configuration */
#define ADC_OSQ1_OSN15_Pos                  (10U)
#define ADC_OSQ1_OSN15_Msk                  (0x1FU << ADC_OSQ1_OSN15_Pos)           /*!< 0x00007C00 */
#define ADC_OSQ1_OSN15                      ADC_OSQ1_OSN15_Msk                      /*!< OSN15[4:0] bits (Number of 15th conversion in ordinary sequence) */
#define ADC_OSQ1_OSN15_0                    (0x01U << ADC_OSQ1_OSN15_Pos)           /*!< 0x00000400 */
#define ADC_OSQ1_OSN15_1                    (0x02U << ADC_OSQ1_OSN15_Pos)           /*!< 0x00000800 */
#define ADC_OSQ1_OSN15_2                    (0x04U << ADC_OSQ1_OSN15_Pos)           /*!< 0x00001000 */
#define ADC_OSQ1_OSN15_3                    (0x08U << ADC_OSQ1_OSN15_Pos)           /*!< 0x00002000 */
#define ADC_OSQ1_OSN15_4                    (0x10U << ADC_OSQ1_OSN15_Pos)           /*!< 0x00004000 */

/*!< OSN16 configuration */
#define ADC_OSQ1_OSN16_Pos                  (15U)
#define ADC_OSQ1_OSN16_Msk                  (0x1FU << ADC_OSQ1_OSN16_Pos)           /*!< 0x000F8000 */
#define ADC_OSQ1_OSN16                      ADC_OSQ1_OSN16_Msk                      /*!< OSN16[4:0] bits (Number of 16th conversion in ordinary sequence) */
#define ADC_OSQ1_OSN16_0                    (0x01U << ADC_OSQ1_OSN16_Pos)           /*!< 0x00008000 */
#define ADC_OSQ1_OSN16_1                    (0x02U << ADC_OSQ1_OSN16_Pos)           /*!< 0x00010000 */
#define ADC_OSQ1_OSN16_2                    (0x04U << ADC_OSQ1_OSN16_Pos)           /*!< 0x00020000 */
#define ADC_OSQ1_OSN16_3                    (0x08U << ADC_OSQ1_OSN16_Pos)           /*!< 0x00040000 */
#define ADC_OSQ1_OSN16_4                    (0x10U << ADC_OSQ1_OSN16_Pos)           /*!< 0x00080000 */

/*!< OCLEN configuration */
#define ADC_OSQ1_OCLEN_Pos                  (20U)
#define ADC_OSQ1_OCLEN_Msk                  (0xFU << ADC_OSQ1_OCLEN_Pos)            /*!< 0x00F00000 */
#define ADC_OSQ1_OCLEN                      ADC_OSQ1_OCLEN_Msk                      /*!< OCLEN[3:0] bits (Ordinary conversion sequence length) */
#define ADC_OSQ1_OCLEN_0                    (0x1U << ADC_OSQ1_OCLEN_Pos)            /*!< 0x00100000 */
#define ADC_OSQ1_OCLEN_1                    (0x2U << ADC_OSQ1_OCLEN_Pos)            /*!< 0x00200000 */
#define ADC_OSQ1_OCLEN_2                    (0x4U << ADC_OSQ1_OCLEN_Pos)            /*!< 0x00400000 */
#define ADC_OSQ1_OCLEN_3                    (0x8U << ADC_OSQ1_OCLEN_Pos)            /*!< 0x00800000 */

/*******************  Bit definition for ADC_OSQ2 register  *******************/
/*!< OSN7 configuration */
#define ADC_OSQ2_OSN7_Pos                   (0U)
#define ADC_OSQ2_OSN7_Msk                   (0x1FU << ADC_OSQ2_OSN7_Pos)            /*!< 0x0000001F */
#define ADC_OSQ2_OSN7                       ADC_OSQ2_OSN7_Msk                       /*!< OSN7[4:0] bits (Number of 7th conversion in ordinary sequence) */
#define ADC_OSQ2_OSN7_0                     (0x01U << ADC_OSQ2_OSN7_Pos)            /*!< 0x00000001 */
#define ADC_OSQ2_OSN7_1                     (0x02U << ADC_OSQ2_OSN7_Pos)            /*!< 0x00000002 */
#define ADC_OSQ2_OSN7_2                     (0x04U << ADC_OSQ2_OSN7_Pos)            /*!< 0x00000004 */
#define ADC_OSQ2_OSN7_3                     (0x08U << ADC_OSQ2_OSN7_Pos)            /*!< 0x00000008 */
#define ADC_OSQ2_OSN7_4                     (0x10U << ADC_OSQ2_OSN7_Pos)            /*!< 0x00000010 */

/*!< OSN8 configuration */
#define ADC_OSQ2_OSN8_Pos                   (5U)
#define ADC_OSQ2_OSN8_Msk                   (0x1FU << ADC_OSQ2_OSN8_Pos)            /*!< 0x000003E0 */
#define ADC_OSQ2_OSN8                       ADC_OSQ2_OSN8_Msk                       /*!< OSN8[4:0] bits (Number of 8th conversion in ordinary sequence) */
#define ADC_OSQ2_OSN8_0                     (0x01U << ADC_OSQ2_OSN8_Pos)            /*!< 0x00000020 */
#define ADC_OSQ2_OSN8_1                     (0x02U << ADC_OSQ2_OSN8_Pos)            /*!< 0x00000040 */
#define ADC_OSQ2_OSN8_2                     (0x04U << ADC_OSQ2_OSN8_Pos)            /*!< 0x00000080 */
#define ADC_OSQ2_OSN8_3                     (0x08U << ADC_OSQ2_OSN8_Pos)            /*!< 0x00000100 */
#define ADC_OSQ2_OSN8_4                     (0x10U << ADC_OSQ2_OSN8_Pos)            /*!< 0x00000200 */

/*!< OSN9 configuration */
#define ADC_OSQ2_OSN9_Pos                   (10U)
#define ADC_OSQ2_OSN9_Msk                   (0x1FU << ADC_OSQ2_OSN9_Pos)            /*!< 0x00007C00 */
#define ADC_OSQ2_OSN9                       ADC_OSQ2_OSN9_Msk                       /*!< OSN9[4:0] bits (Number of 9th conversion in ordinary sequence) */
#define ADC_OSQ2_OSN9_0                     (0x01U << ADC_OSQ2_OSN9_Pos)            /*!< 0x00000400 */
#define ADC_OSQ2_OSN9_1                     (0x02U << ADC_OSQ2_OSN9_Pos)            /*!< 0x00000800 */
#define ADC_OSQ2_OSN9_2                     (0x04U << ADC_OSQ2_OSN9_Pos)            /*!< 0x00001000 */
#define ADC_OSQ2_OSN9_3                     (0x08U << ADC_OSQ2_OSN9_Pos)            /*!< 0x00002000 */
#define ADC_OSQ2_OSN9_4                     (0x10U << ADC_OSQ2_OSN9_Pos)            /*!< 0x00004000 */

/*!< OSN10 configuration */
#define ADC_OSQ2_OSN10_Pos                  (15U)
#define ADC_OSQ2_OSN10_Msk                  (0x1FU << ADC_OSQ2_OSN10_Pos)           /*!< 0x000F8000 */
#define ADC_OSQ2_OSN10                      ADC_OSQ2_OSN10_Msk                      /*!< OSN10[4:0] bits (Number of 10th conversion in ordinary sequence) */
#define ADC_OSQ2_OSN10_0                    (0x01U << ADC_OSQ2_OSN10_Pos)           /*!< 0x00008000 */
#define ADC_OSQ2_OSN10_1                    (0x02U << ADC_OSQ2_OSN10_Pos)           /*!< 0x00010000 */
#define ADC_OSQ2_OSN10_2                    (0x04U << ADC_OSQ2_OSN10_Pos)           /*!< 0x00020000 */
#define ADC_OSQ2_OSN10_3                    (0x08U << ADC_OSQ2_OSN10_Pos)           /*!< 0x00040000 */
#define ADC_OSQ2_OSN10_4                    (0x10U << ADC_OSQ2_OSN10_Pos)           /*!< 0x00080000 */

/*!< OSN11 configuration */
#define ADC_OSQ2_OSN11_Pos                  (20U)
#define ADC_OSQ2_OSN11_Msk                  (0x1FU << ADC_OSQ2_OSN11_Pos)           /*!< 0x01F00000 */
#define ADC_OSQ2_OSN11                      ADC_OSQ2_OSN11_Msk                      /*!< OSN11[4:0] bits (Number of 11th conversion in ordinary sequence) */
#define ADC_OSQ2_OSN11_0                    (0x01U << ADC_OSQ2_OSN11_Pos)           /*!< 0x00100000 */
#define ADC_OSQ2_OSN11_1                    (0x02U << ADC_OSQ2_OSN11_Pos)           /*!< 0x00200000 */
#define ADC_OSQ2_OSN11_2                    (0x04U << ADC_OSQ2_OSN11_Pos)           /*!< 0x00400000 */
#define ADC_OSQ2_OSN11_3                    (0x08U << ADC_OSQ2_OSN11_Pos)           /*!< 0x00800000 */
#define ADC_OSQ2_OSN11_4                    (0x10U << ADC_OSQ2_OSN11_Pos)           /*!< 0x01000000 */

/*!< OSN12 configuration */
#define ADC_OSQ2_OSN12_Pos                  (25U)
#define ADC_OSQ2_OSN12_Msk                  (0x1FU << ADC_OSQ2_OSN12_Pos)           /*!< 0x3E000000 */
#define ADC_OSQ2_OSN12                      ADC_OSQ2_OSN12_Msk                      /*!< OSN12[4:0] bits (Number of 12th conversion in ordinary sequence) */
#define ADC_OSQ2_OSN12_0                    (0x01U << ADC_OSQ2_OSN12_Pos)           /*!< 0x02000000 */
#define ADC_OSQ2_OSN12_1                    (0x02U << ADC_OSQ2_OSN12_Pos)           /*!< 0x04000000 */
#define ADC_OSQ2_OSN12_2                    (0x04U << ADC_OSQ2_OSN12_Pos)           /*!< 0x08000000 */
#define ADC_OSQ2_OSN12_3                    (0x08U << ADC_OSQ2_OSN12_Pos)           /*!< 0x10000000 */
#define ADC_OSQ2_OSN12_4                    (0x10U << ADC_OSQ2_OSN12_Pos)           /*!< 0x20000000 */

/*******************  Bit definition for ADC_OSQ3 register  *******************/
/*!< OSN1 configuration */
#define ADC_OSQ3_OSN1_Pos                   (0U)
#define ADC_OSQ3_OSN1_Msk                   (0x1FU << ADC_OSQ3_OSN1_Pos)            /*!< 0x0000001F */
#define ADC_OSQ3_OSN1                       ADC_OSQ3_OSN1_Msk                       /*!< OSN1[4:0] bits (Number of 1st conversion in ordinary sequence) */
#define ADC_OSQ3_OSN1_0                     (0x01U << ADC_OSQ3_OSN1_Pos)            /*!< 0x00000001 */
#define ADC_OSQ3_OSN1_1                     (0x02U << ADC_OSQ3_OSN1_Pos)            /*!< 0x00000002 */
#define ADC_OSQ3_OSN1_2                     (0x04U << ADC_OSQ3_OSN1_Pos)            /*!< 0x00000004 */
#define ADC_OSQ3_OSN1_3                     (0x08U << ADC_OSQ3_OSN1_Pos)            /*!< 0x00000008 */
#define ADC_OSQ3_OSN1_4                     (0x10U << ADC_OSQ3_OSN1_Pos)            /*!< 0x00000010 */

/*!< OSN2 configuration */
#define ADC_OSQ3_OSN2_Pos                   (5U)
#define ADC_OSQ3_OSN2_Msk                   (0x1FU << ADC_OSQ3_OSN2_Pos)            /*!< 0x000003E0 */
#define ADC_OSQ3_OSN2                       ADC_OSQ3_OSN2_Msk                       /*!< OSN2[4:0] bits (Number of 2nd conversion in ordinary sequence) */
#define ADC_OSQ3_OSN2_0                     (0x01U << ADC_OSQ3_OSN2_Pos)            /*!< 0x00000020 */
#define ADC_OSQ3_OSN2_1                     (0x02U << ADC_OSQ3_OSN2_Pos)            /*!< 0x00000040 */
#define ADC_OSQ3_OSN2_2                     (0x04U << ADC_OSQ3_OSN2_Pos)            /*!< 0x00000080 */
#define ADC_OSQ3_OSN2_3                     (0x08U << ADC_OSQ3_OSN2_Pos)            /*!< 0x00000100 */
#define ADC_OSQ3_OSN2_4                     (0x10U << ADC_OSQ3_OSN2_Pos)            /*!< 0x00000200 */

/*!< OSN3 configuration */
#define ADC_OSQ3_OSN3_Pos                   (10U)
#define ADC_OSQ3_OSN3_Msk                   (0x1FU << ADC_OSQ3_OSN3_Pos)            /*!< 0x00007C00 */
#define ADC_OSQ3_OSN3                       ADC_OSQ3_OSN3_Msk                       /*!< OSN3[4:0] bits (Number of 3rd conversion in ordinary sequence) */
#define ADC_OSQ3_OSN3_0                     (0x01U << ADC_OSQ3_OSN3_Pos)            /*!< 0x00000400 */
#define ADC_OSQ3_OSN3_1                     (0x02U << ADC_OSQ3_OSN3_Pos)            /*!< 0x00000800 */
#define ADC_OSQ3_OSN3_2                     (0x04U << ADC_OSQ3_OSN3_Pos)            /*!< 0x00001000 */
#define ADC_OSQ3_OSN3_3                     (0x08U << ADC_OSQ3_OSN3_Pos)            /*!< 0x00002000 */
#define ADC_OSQ3_OSN3_4                     (0x10U << ADC_OSQ3_OSN3_Pos)            /*!< 0x00004000 */

/*!< OSN4 configuration */
#define ADC_OSQ3_OSN4_Pos                   (15U)
#define ADC_OSQ3_OSN4_Msk                   (0x1FU << ADC_OSQ3_OSN4_Pos)            /*!< 0x000F8000 */
#define ADC_OSQ3_OSN4                       ADC_OSQ3_OSN4_Msk                       /*!< OSN4[4:0] bits (Number of 4th conversion in ordinary sequence) */
#define ADC_OSQ3_OSN4_0                     (0x01U << ADC_OSQ3_OSN4_Pos)            /*!< 0x00008000 */
#define ADC_OSQ3_OSN4_1                     (0x02U << ADC_OSQ3_OSN4_Pos)            /*!< 0x00010000 */
#define ADC_OSQ3_OSN4_2                     (0x04U << ADC_OSQ3_OSN4_Pos)            /*!< 0x00020000 */
#define ADC_OSQ3_OSN4_3                     (0x08U << ADC_OSQ3_OSN4_Pos)            /*!< 0x00040000 */
#define ADC_OSQ3_OSN4_4                     (0x10U << ADC_OSQ3_OSN4_Pos)            /*!< 0x00080000 */

/*!< OSN5 configuration */
#define ADC_OSQ3_OSN5_Pos                   (20U)
#define ADC_OSQ3_OSN5_Msk                   (0x1FU << ADC_OSQ3_OSN5_Pos)            /*!< 0x01F00000 */
#define ADC_OSQ3_OSN5                       ADC_OSQ3_OSN5_Msk                       /*!< OSN5[4:0] bits (Number of 5th conversion in ordinary sequence) */
#define ADC_OSQ3_OSN5_0                     (0x01U << ADC_OSQ3_OSN5_Pos)            /*!< 0x00100000 */
#define ADC_OSQ3_OSN5_1                     (0x02U << ADC_OSQ3_OSN5_Pos)            /*!< 0x00200000 */
#define ADC_OSQ3_OSN5_2                     (0x04U << ADC_OSQ3_OSN5_Pos)            /*!< 0x00400000 */
#define ADC_OSQ3_OSN5_3                     (0x08U << ADC_OSQ3_OSN5_Pos)            /*!< 0x00800000 */
#define ADC_OSQ3_OSN5_4                     (0x10U << ADC_OSQ3_OSN5_Pos)            /*!< 0x01000000 */

/*!< OSN6 configuration */
#define ADC_OSQ3_OSN6_Pos                   (25U)
#define ADC_OSQ3_OSN6_Msk                   (0x1FU << ADC_OSQ3_OSN6_Pos)            /*!< 0x3E000000 */
#define ADC_OSQ3_OSN6                       ADC_OSQ3_OSN6_Msk                       /*!< OSN6[4:0] bits (Number of 6th conversion in ordinary sequence) */
#define ADC_OSQ3_OSN6_0                     (0x01U << ADC_OSQ3_OSN6_Pos)            /*!< 0x02000000 */
#define ADC_OSQ3_OSN6_1                     (0x02U << ADC_OSQ3_OSN6_Pos)            /*!< 0x04000000 */
#define ADC_OSQ3_OSN6_2                     (0x04U << ADC_OSQ3_OSN6_Pos)            /*!< 0x08000000 */
#define ADC_OSQ3_OSN6_3                     (0x08U << ADC_OSQ3_OSN6_Pos)            /*!< 0x10000000 */
#define ADC_OSQ3_OSN6_4                     (0x10U << ADC_OSQ3_OSN6_Pos)            /*!< 0x20000000 */

/*******************  Bit definition for ADC_PSQ register  ********************/
/*!< PSN1 configuration */
#define ADC_PSQ_PSN1_Pos                    (0U)
#define ADC_PSQ_PSN1_Msk                    (0x1FU << ADC_PSQ_PSN1_Pos)             /*!< 0x0000001F */
#define ADC_PSQ_PSN1                        ADC_PSQ_PSN1_Msk                        /*!< PSN1[4:0] bits (Number of 1st conversion in preempted sequence) */
#define ADC_PSQ_PSN1_0                      (0x01U << ADC_PSQ_PSN1_Pos)             /*!< 0x00000001 */
#define ADC_PSQ_PSN1_1                      (0x02U << ADC_PSQ_PSN1_Pos)             /*!< 0x00000002 */
#define ADC_PSQ_PSN1_2                      (0x04U << ADC_PSQ_PSN1_Pos)             /*!< 0x00000004 */
#define ADC_PSQ_PSN1_3                      (0x08U << ADC_PSQ_PSN1_Pos)             /*!< 0x00000008 */
#define ADC_PSQ_PSN1_4                      (0x10U << ADC_PSQ_PSN1_Pos)             /*!< 0x00000010 */

/*!< PSN2 configuration */
#define ADC_PSQ_PSN2_Pos                    (5U)
#define ADC_PSQ_PSN2_Msk                    (0x1FU << ADC_PSQ_PSN2_Pos)             /*!< 0x000003E0 */
#define ADC_PSQ_PSN2                        ADC_PSQ_PSN2_Msk                        /*!< PSN2[4:0] bits (Number of 2nd conversion in preempted sequence) */
#define ADC_PSQ_PSN2_0                      (0x01U << ADC_PSQ_PSN2_Pos)             /*!< 0x00000020 */
#define ADC_PSQ_PSN2_1                      (0x02U << ADC_PSQ_PSN2_Pos)             /*!< 0x00000040 */
#define ADC_PSQ_PSN2_2                      (0x04U << ADC_PSQ_PSN2_Pos)             /*!< 0x00000080 */
#define ADC_PSQ_PSN2_3                      (0x08U << ADC_PSQ_PSN2_Pos)             /*!< 0x00000100 */
#define ADC_PSQ_PSN2_4                      (0x10U << ADC_PSQ_PSN2_Pos)             /*!< 0x00000200 */

/*!< PSN3 configuration */
#define ADC_PSQ_PSN3_Pos                    (10U)
#define ADC_PSQ_PSN3_Msk                    (0x1FU << ADC_PSQ_PSN3_Pos)             /*!< 0x00007C00 */
#define ADC_PSQ_PSN3                        ADC_PSQ_PSN3_Msk                        /*!< PSN3[4:0] bits (Number of 3rd conversion in preempted sequence) */
#define ADC_PSQ_PSN3_0                      (0x01U << ADC_PSQ_PSN3_Pos)             /*!< 0x00000400 */
#define ADC_PSQ_PSN3_1                      (0x02U << ADC_PSQ_PSN3_Pos)             /*!< 0x00000800 */
#define ADC_PSQ_PSN3_2                      (0x04U << ADC_PSQ_PSN3_Pos)             /*!< 0x00001000 */
#define ADC_PSQ_PSN3_3                      (0x08U << ADC_PSQ_PSN3_Pos)             /*!< 0x00002000 */
#define ADC_PSQ_PSN3_4                      (0x10U << ADC_PSQ_PSN3_Pos)             /*!< 0x00004000 */

/*!< PSN4 configuration */
#define ADC_PSQ_PSN4_Pos                    (15U)
#define ADC_PSQ_PSN4_Msk                    (0x1FU << ADC_PSQ_PSN4_Pos)             /*!< 0x000F8000 */
#define ADC_PSQ_PSN4                        ADC_PSQ_PSN4_Msk                        /*!< PSN4[4:0] bits (Number of 4th conversion in preempted sequence) */
#define ADC_PSQ_PSN4_0                      (0x01U << ADC_PSQ_PSN4_Pos)             /*!< 0x00008000 */
#define ADC_PSQ_PSN4_1                      (0x02U << ADC_PSQ_PSN4_Pos)             /*!< 0x00010000 */
#define ADC_PSQ_PSN4_2                      (0x04U << ADC_PSQ_PSN4_Pos)             /*!< 0x00020000 */
#define ADC_PSQ_PSN4_3                      (0x08U << ADC_PSQ_PSN4_Pos)             /*!< 0x00040000 */
#define ADC_PSQ_PSN4_4                      (0x10U << ADC_PSQ_PSN4_Pos)             /*!< 0x00080000 */

/*!< PCLEN configuration */
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

/*******************  Bit definition for ADC_OVSP register  *******************/
#define ADC_OVSP_OOSEN_Pos                  (0U)
#define ADC_OVSP_OOSEN_Msk                  (0x1U << ADC_OVSP_OOSEN_Pos)            /*!< 0x00000001 */
#define ADC_OVSP_OOSEN                      ADC_OVSP_OOSEN_Msk                      /*!< Ordinary oversampling enable */
#define ADC_OVSP_POSEN_Pos                  (1U)
#define ADC_OVSP_POSEN_Msk                  (0x1U << ADC_OVSP_POSEN_Pos)            /*!< 0x00000002 */
#define ADC_OVSP_POSEN                      ADC_OVSP_POSEN_Msk                      /*!< Preempted oversampling enable */

/*!< OSRSEL configuration */
#define ADC_OVSP_OSRSEL_Pos                 (2U)
#define ADC_OVSP_OSRSEL_Msk                 (0x7U << ADC_OVSP_OSRSEL_Pos)           /*!< 0x0000001C */
#define ADC_OVSP_OSRSEL                     ADC_OVSP_OSRSEL_Msk                     /*!< OSRSEL[2:0] bits (Oversampling ratio select) */
#define ADC_OVSP_OSRSEL_0                   (0x1U << ADC_OVSP_OSRSEL_Pos)           /*!< 0x00000004 */
#define ADC_OVSP_OSRSEL_1                   (0x2U << ADC_OVSP_OSRSEL_Pos)           /*!< 0x00000008 */
#define ADC_OVSP_OSRSEL_2                   (0x4U << ADC_OVSP_OSRSEL_Pos)           /*!< 0x00000010 */

#define ADC_OVSP_OSRSEL_MULTI2              0x00000000U                             /*!< 2x */
#define ADC_OVSP_OSRSEL_MULTI4              0x00000004U                             /*!< 4x */
#define ADC_OVSP_OSRSEL_MULTI8              0x00000008U                             /*!< 8x */
#define ADC_OVSP_OSRSEL_MULTI16             0x0000000CU                             /*!< 16x */
#define ADC_OVSP_OSRSEL_MULTI32             0x00000010U                             /*!< 32x */
#define ADC_OVSP_OSRSEL_MULTI64             0x00000014U                             /*!< 64x */
#define ADC_OVSP_OSRSEL_MULTI128            0x00000018U                             /*!< 128x */
#define ADC_OVSP_OSRSEL_MULTI256            0x0000001CU                             /*!< 256x */

/*!< OSSSEL configuration */
#define ADC_OVSP_OSSSEL_Pos                 (5U)
#define ADC_OVSP_OSSSEL_Msk                 (0xFU << ADC_OVSP_OSSSEL_Pos)           /*!< 0x000001E0 */
#define ADC_OVSP_OSSSEL                     ADC_OVSP_OSSSEL_Msk                     /*!< OSSSEL[3:0] bits (Oversampling shift select) */
#define ADC_OVSP_OSSSEL_0                   (0x1U << ADC_OVSP_OSSSEL_Pos)           /*!< 0x00000020 */
#define ADC_OVSP_OSSSEL_1                   (0x2U << ADC_OVSP_OSSSEL_Pos)           /*!< 0x00000040 */
#define ADC_OVSP_OSSSEL_2                   (0x4U << ADC_OVSP_OSSSEL_Pos)           /*!< 0x00000080 */
#define ADC_OVSP_OSSSEL_3                   (0x8U << ADC_OVSP_OSSSEL_Pos)           /*!< 0x00000100 */

#define ADC_OVSP_OSSSEL_NOSHIFT             0x00000000U                             /*!< No shift */
#define ADC_OVSP_OSSSEL_SHIFT1              0x00000020U                             /*!< Shift 1 bit */
#define ADC_OVSP_OSSSEL_SHIFT2              0x00000040U                             /*!< Shift 2 bit */
#define ADC_OVSP_OSSSEL_SHIFT3              0x00000060U                             /*!< Shift 3 bit */
#define ADC_OVSP_OSSSEL_SHIFT4              0x00000080U                             /*!< Shift 4 bit */
#define ADC_OVSP_OSSSEL_SHIFT5              0x000000A0U                             /*!< Shift 5 bit */
#define ADC_OVSP_OSSSEL_SHIFT6              0x000000C0U                             /*!< Shift 6 bit */
#define ADC_OVSP_OSSSEL_SHIFT7              0x000000E0U                             /*!< Shift 7 bit */
#define ADC_OVSP_OSSSEL_SHIFT8              0x00000100U                             /*!< Shift 8 bit */

#define ADC_OVSP_OOSTREN_Pos                (9U)
#define ADC_OVSP_OOSTREN_Msk                (0x1U << ADC_OVSP_OOSTREN_Pos)          /*!< 0x00000200 */
#define ADC_OVSP_OOSTREN                    ADC_OVSP_OOSTREN_Msk                    /*!< Ordinary oversampling trigger mode enable */
#define ADC_OVSP_OOSRSEL_Pos                (10U)
#define ADC_OVSP_OOSRSEL_Msk                (0x1U << ADC_OVSP_OOSRSEL_Pos)          /*!< 0x00000400 */
#define ADC_OVSP_OOSRSEL                    ADC_OVSP_OOSRSEL_Msk                    /*!< Ordinary oversampling restart mode select */

/*******************  Bit definition for ADC_CALVAL register  ********************/
#define ADC_CALVAL_CALVAL_Pos               (0U)
#define ADC_CALVAL_CALVA_Msk                (0x7FU << ADC_CALVAL_CALVAL_Pos)        /*!< 0x0000007F */
#define ADC_CALVAL_CALVA                    ADC_CALVAL_CALVA_Msk                    /*!< A/D Calibration value */

/*******************  Bit definition for ADC_CSTS register  ********************/
#define ADC_CSTS_VMOR1_Pos                  (0U)
#define ADC_CSTS_VMOR1_Msk                  (0x1U << ADC_CSTS_VMOR1_Pos)            /*!< 0x00000001 */
#define ADC_CSTS_VMOR1                      ADC_CSTS_VMOR1_Msk                      /*!< Voltage monitoring out of range flag of ADC1 */
#define ADC_CSTS_OCCE1_Pos                  (1U)
#define ADC_CSTS_OCCE1_Msk                  (0x1U << ADC_CSTS_OCCE1_Pos)            /*!< 0x00000002 */
#define ADC_CSTS_OCCE1                      ADC_CSTS_OCCE1_Msk                      /*!< Ordinary channels conversion end flag of ADC1 */
#define ADC_CSTS_PCCE1_Pos                  (2U)
#define ADC_CSTS_PCCE1_Msk                  (0x1U << ADC_CSTS_PCCE1_Pos)            /*!< 0x00000004 */
#define ADC_CSTS_PCCE1                      ADC_CSTS_PCCE1_Msk                      /*!< preempted channels conversion end flag of ADC1 */
#define ADC_CSTS_PCCS1_Pos                  (3U)
#define ADC_CSTS_PCCS1_Msk                  (0x1U << ADC_CSTS_PCCS1_Pos)            /*!< 0x00000008 */
#define ADC_CSTS_PCCS1                      ADC_CSTS_PCCS1_Msk                      /*!< ADC1 Preempted channel conversion start flag */
#define ADC_CSTS_OCCS1_Pos                  (4U)
#define ADC_CSTS_OCCS1_Msk                  (0x1U << ADC_CSTS_OCCS1_Pos)            /*!< 0x00000010 */
#define ADC_CSTS_OCCS1                      ADC_CSTS_OCCS1_Msk                      /*!< ADC1 ordinary channel conversion start flag */
#define ADC_CSTS_OCCO1_Pos                  (5U)
#define ADC_CSTS_OCCO1_Msk                  (0x1U << ADC_CSTS_OCCO1_Pos)            /*!< 0x00000020 */
#define ADC_CSTS_OCCO1                      ADC_CSTS_OCCO1_Msk                      /*!< ADC1 ordinary channel conversion overflow flag */
#define ADC_CSTS_RDY1_Pos                   (6U)
#define ADC_CSTS_RDY1_Msk                   (0x1U << ADC_CSTS_RDY1_Pos)             /*!< 0x00000040 */
#define ADC_CSTS_RDY1                       ADC_CSTS_RDY1_Msk                       /*!< ADC1 conversion ready flag */
#define ADC_CSTS_VMOR2_Pos                  (8U)
#define ADC_CSTS_VMOR2_Msk                  (0x1U << ADC_CSTS_VMOR2_Pos)            /*!< 0x00000100 */
#define ADC_CSTS_VMOR2                      ADC_CSTS_VMOR2_Msk                      /*!< Voltage monitoring out of range flag of ADC2 */
#define ADC_CSTS_OCCE2_Pos                  (9U)
#define ADC_CSTS_OCCE2_Msk                  (0x1U << ADC_CSTS_OCCE2_Pos)            /*!< 0x00000200 */
#define ADC_CSTS_OCCE2                      ADC_CSTS_OCCE2_Msk                      /*!< Ordinary channels conversion end flag of ADC2 */
#define ADC_CSTS_PCCE2_Pos                  (10U)
#define ADC_CSTS_PCCE2_Msk                  (0x1U << ADC_CSTS_PCCE2_Pos)            /*!< 0x00000400 */
#define ADC_CSTS_PCCE2                      ADC_CSTS_PCCE2_Msk                      /*!< preempted channels conversion end flag of ADC2 */
#define ADC_CSTS_PCCS2_Pos                  (11U)
#define ADC_CSTS_PCCS2_Msk                  (0x1U << ADC_CSTS_PCCS2_Pos)            /*!< 0x00000800 */
#define ADC_CSTS_PCCS2                      ADC_CSTS_PCCS2_Msk                      /*!< ADC2 Preempted channel conversion start flag */
#define ADC_CSTS_OCCS2_Pos                  (12U)
#define ADC_CSTS_OCCS2_Msk                  (0x1U << ADC_CSTS_OCCS2_Pos)            /*!< 0x00001000 */
#define ADC_CSTS_OCCS2                      ADC_CSTS_OCCS2_Msk                      /*!< ADC2 ordinary channel conversion start flag */
#define ADC_CSTS_OCCO2_Pos                  (13U)
#define ADC_CSTS_OCCO2_Msk                  (0x1U << ADC_CSTS_OCCO2_Pos)            /*!< 0x00002000 */
#define ADC_CSTS_OCCO2                      ADC_CSTS_OCCO2_Msk                      /*!< ADC2 ordinary channel conversion overflow flag */
#define ADC_CSTS_RDY2_Pos                   (14U)
#define ADC_CSTS_RDY2_Msk                   (0x1U << ADC_CSTS_RDY2_Pos)             /*!< 0x00004000 */
#define ADC_CSTS_RDY2                       ADC_CSTS_RDY2_Msk                       /*!< ADC2 conversion ready flag */
#define ADC_CSTS_VMOR3_Pos                  (16U)
#define ADC_CSTS_VMOR3_Msk                  (0x1U << ADC_CSTS_VMOR3_Pos)            /*!< 0x00010000 */
#define ADC_CSTS_VMOR3                      ADC_CSTS_VMOR3_Msk                      /*!< Voltage monitoring out of range flag of ADC3 */
#define ADC_CSTS_OCCE3_Pos                  (17U)
#define ADC_CSTS_OCCE3_Msk                  (0x1U << ADC_CSTS_OCCE3_Pos)            /*!< 0x00020000 */
#define ADC_CSTS_OCCE3                      ADC_CSTS_OCCE3_Msk                      /*!< Ordinary channels conversion end flag of ADC3 */
#define ADC_CSTS_PCCE3_Pos                  (18U)
#define ADC_CSTS_PCCE3_Msk                  (0x1U << ADC_CSTS_PCCE3_Pos)            /*!< 0x00040000 */
#define ADC_CSTS_PCCE3                      ADC_CSTS_PCCE3_Msk                      /*!< preempted channels conversion end flag of ADC3 */
#define ADC_CSTS_PCCS3_Pos                  (19U)
#define ADC_CSTS_PCCS3_Msk                  (0x1U << ADC_CSTS_PCCS3_Pos)            /*!< 0x00080000 */
#define ADC_CSTS_PCCS3                      ADC_CSTS_PCCS3_Msk                      /*!< ADC3 Preempted channel conversion start flag */
#define ADC_CSTS_OCCS3_Pos                  (20U)
#define ADC_CSTS_OCCS3_Msk                  (0x1U << ADC_CSTS_OCCS3_Pos)            /*!< 0x00100000 */
#define ADC_CSTS_OCCS3                      ADC_CSTS_OCCS3_Msk                      /*!< ADC3 ordinary channel conversion start flag */
#define ADC_CSTS_OCCO3_Pos                  (21U)
#define ADC_CSTS_OCCO3_Msk                  (0x1U << ADC_CSTS_OCCO3_Pos)            /*!< 0x00200000 */
#define ADC_CSTS_OCCO3                      ADC_CSTS_OCCO3_Msk                      /*!< ADC3 ordinary channel conversion overflow flag */
#define ADC_CSTS_RDY3_Pos                   (22U)
#define ADC_CSTS_RDY3_Msk                   (0x1U << ADC_CSTS_RDY3_Pos)             /*!< 0x00400000 */
#define ADC_CSTS_RDY3                       ADC_CSTS_RDY3_Msk                       /*!< ADC3 conversion ready flag */

/******************  Bit definition for ADC_CCTRL register  *******************/
/*!< ADC Master slave mode select */
#define ADC_CCTRL_MSSEL_Pos                 (0U)
#define ADC_CCTRL_MSSEL_Msk                 (0x1FU << ADC_CCTRL_MSSEL_Pos)          /*!< 0x0000001F */
#define ADC_CCTRL_MSSEL                     ADC_CCTRL_MSSEL_Msk                     /*!< MSSEL[4:0] bits Master slave mode select */
#define ADC_CCTRL_MSSEL_0                   (0x1U << ADC_CCTRL_MSSEL_Pos)           /*!< 0x00000001 */
#define ADC_CCTRL_MSSEL_1                   (0x2U << ADC_CCTRL_MSSEL_Pos)           /*!< 0x00000002 */
#define ADC_CCTRL_MSSEL_2                   (0x4U << ADC_CCTRL_MSSEL_Pos)           /*!< 0x00000004 */
#define ADC_CCTRL_MSSEL_3                   (0x8U << ADC_CCTRL_MSSEL_Pos)           /*!< 0x00000008 */
#define ADC_CCTRL_MSSEL_4                   (0x10U << ADC_CCTRL_MSSEL_Pos)          /*!< 0x00000010 */
#define ADC_CCTRL_ASISEL_Pos                (8U)
#define ADC_CCTRL_ASISEL_Msk                (0xFU << ADC_CCTRL_ASISEL_Pos)          /*!< 0x00000F00 */
#define ADC_CCTRL_ASISEL                    ADC_CCTRL_ASISEL_Msk                    /*!< ASISEL[3:0] bits Adjacent ADC sampling interval select for ordinary shifting mode */
#define ADC_CCTRL_ASISEL_0                  (0x1U << ADC_CCTRL_ASISEL_Pos)          /*!< 0x00000100 */
#define ADC_CCTRL_ASISEL_1                  (0x2U << ADC_CCTRL_ASISEL_Pos)          /*!< 0x00000200 */
#define ADC_CCTRL_ASISEL_2                  (0x4U << ADC_CCTRL_ASISEL_Pos)          /*!< 0x00000400 */
#define ADC_CCTRL_ASISEL_3                  (0x8U << ADC_CCTRL_ASISEL_Pos)          /*!< 0x00000800 */
#define ADC_CCTRL_MSDRCEN_Pos               (13U)
#define ADC_CCTRL_MSDRCEN_Msk               (0x1U << ADC_CCTRL_MSDRCEN_Pos)         /*!< 0x00002000 */
#define ADC_CCTRL_MSDRCEN                   ADC_CCTRL_MSDRCEN_Msk                   /*!< MSDRCEN bits Ordinary channel’s DMA request continuation enable for master slave mode */
#define ADC_CCTRL_MSDMASEL_Pos              (14U)
#define ADC_CCTRL_MSDMASEL_Msk              ((0x3U << ADC_CCTRL_MSDMASEL_Pos) | (0x1U << 28))        /*!< 0x00000F00 */
#define ADC_CCTRL_MSDMASEL                  ADC_CCTRL_MSDMASEL_Msk                  /*!< MSDMASEL[2:0] bits Adjacent ADC sampling interval select for ordinary shifting mode */
#define ADC_CCTRL_MSDMASEL_0                (0x1U << ADC_CCTRL_MSDMASEL_Pos)        /*!< 0x00000100 */
#define ADC_CCTRL_MSDMASEL_1                (0x2U << ADC_CCTRL_MSDMASEL_Pos)        /*!< 0x00000200 */
#define ADC_CCTRL_MSDMASEL_2                (0x1U << 28)                            /*!< 0x00000400 */

/*!< ADCDIV configuration */
#define ADC_CCTRL_ADCDIV_Pos                (16U)
#define ADC_CCTRL_ADCDIV_Msk                (0xFU << ADC_CCTRL_ADCDIV_Pos)          /*!< 0x000F0000 */
#define ADC_CCTRL_ADCDIV                    ADC_CCTRL_ADCDIV_Msk                    /*!< ADCDIV[3:0] bits (ADC division) */
#define ADC_CCTRL_ADCDIV_0                  (0x1U << ADC_CCTRL_ADCDIV_Pos)          /*!< 0x00010000 */
#define ADC_CCTRL_ADCDIV_1                  (0x2U << ADC_CCTRL_ADCDIV_Pos)          /*!< 0x00020000 */
#define ADC_CCTRL_ADCDIV_2                  (0x4U << ADC_CCTRL_ADCDIV_Pos)          /*!< 0x00040000 */
#define ADC_CCTRL_ADCDIV_3                  (0x8U << ADC_CCTRL_ADCDIV_Pos)          /*!< 0x00080000 */

#define ADC_CCTRL_ADCDIV_DIV2               0x00000000U                             /*!< HCLK/2 */
#define ADC_CCTRL_ADCDIV_DIV3               0x00010000U                             /*!< HCLK/3 */
#define ADC_CCTRL_ADCDIV_DIV4               0x00020000U                             /*!< HCLK/4 */
#define ADC_CCTRL_ADCDIV_DIV5               0x00030000U                             /*!< HCLK/5 */
#define ADC_CCTRL_ADCDIV_DIV6               0x00040000U                             /*!< HCLK/6 */
#define ADC_CCTRL_ADCDIV_DIV7               0x00050000U                             /*!< HCLK/7 */
#define ADC_CCTRL_ADCDIV_DIV8               0x00060000U                             /*!< HCLK/8 */
#define ADC_CCTRL_ADCDIV_DIV9               0x00070000U                             /*!< HCLK/9 */
#define ADC_CCTRL_ADCDIV_DIV10              0x00080000U                             /*!< HCLK/10 */
#define ADC_CCTRL_ADCDIV_DIV11              0x00090000U                             /*!< HCLK/11 */
#define ADC_CCTRL_ADCDIV_DIV12              0x000A0000U                             /*!< HCLK/12 */
#define ADC_CCTRL_ADCDIV_DIV13              0x000B0000U                             /*!< HCLK/13 */
#define ADC_CCTRL_ADCDIV_DIV14              0x000C0000U                             /*!< HCLK/14 */
#define ADC_CCTRL_ADCDIV_DIV15              0x000D0000U                             /*!< HCLK/15 */
#define ADC_CCTRL_ADCDIV_DIV16              0x000E0000U                             /*!< HCLK/16 */
#define ADC_CCTRL_ADCDIV_DIV17              0x000F0000U                             /*!< HCLK/17 */

#define ADC_CCTRL_VBATEN_Pos                (22U)
#define ADC_CCTRL_VBATEN_Msk                (0x1U << ADC_CCTRL_VBATEN_Pos)          /*!< 0x00400000 */
#define ADC_CCTRL_VBATEN                    ADC_CCTRL_VBATEN_Msk                    /*!< VBATEN bits VBAT enable */
#define ADC_CCTRL_ITSRVEN_Pos               (23U)
#define ADC_CCTRL_ITSRVEN_Msk               (0x1U << ADC_CCTRL_VBATEN_Pos)          /*!< 0x00800000 */
#define ADC_CCTRL_ITSRVEN                   ADC_CCTRL_VBATEN_Msk                    /*!< ITSRVEN bits Internal temperature sensor and VINTRV enable */

/******************  Bit definition for ADC_CODT register  *******************/
#define ADC_CODT_CODTL_Pos                  (0U)
#define ADC_CODT_CODTL_Msk                  (0xFFFFU << ADC_CODT_CODTL_Pos)         /*!< 0x0000FFFF */
#define ADC_CODT_CODTL                      ADC_CODT_CODTL_Msk                      /*!< conversions low halfword data for master slave mode */

#define ADC_CODT_CODTH_Pos                  (16U)
#define ADC_CODT_CODTH_Msk                  (0xFFFFU << ADC_CODT_CODTH_Pos)         /*!< 0x0000FFFF */
#define ADC_CODT_CODTH                      ADC_CODT_CODTH_Msk                      /*!< conversions high halfword data for master slave mode */

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

/*!< TMEF congiguration */
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

/*!< TMLPF congiguration */
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

/*!< ETR congiguration */
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

/*!< BTS1 congiguration */
#define CAN_BTMG_BTS1_Pos                   (16U)
#define CAN_BTMG_BTS1_Msk                   (0xFU << CAN_BTMG_BTS1_Pos)             /*!< 0x000F0000 */
#define CAN_BTMG_BTS1                       CAN_BTMG_BTS1_Msk                       /*!< BTS1[3:0] bits (Bit time segment 1) */
#define CAN_BTMG_BTS1_0                     (0x1U << CAN_BTMG_BTS1_Pos)             /*!< 0x00010000 */
#define CAN_BTMG_BTS1_1                     (0x2U << CAN_BTMG_BTS1_Pos)             /*!< 0x00020000 */
#define CAN_BTMG_BTS1_2                     (0x4U << CAN_BTMG_BTS1_Pos)             /*!< 0x00040000 */
#define CAN_BTMG_BTS1_3                     (0x8U << CAN_BTMG_BTS1_Pos)             /*!< 0x00080000 */

/*!< BTS2 congiguration */
#define CAN_BTMG_BTS2_Pos                   (20U)
#define CAN_BTMG_BTS2_Msk                   (0x7U << CAN_BTMG_BTS2_Pos)             /*!< 0x00700000 */
#define CAN_BTMG_BTS2                       CAN_BTMG_BTS2_Msk                       /*!< BTS2[2:0] bits (Bit time segment 2) */
#define CAN_BTMG_BTS2_0                     (0x1U << CAN_BTMG_BTS2_Pos)             /*!< 0x00100000 */
#define CAN_BTMG_BTS2_1                     (0x2U << CAN_BTMG_BTS2_Pos)             /*!< 0x00200000 */
#define CAN_BTMG_BTS2_2                     (0x4U << CAN_BTMG_BTS2_Pos)             /*!< 0x00400000 */

/*!< RSAW congiguration */
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
#define CAN_FMCFG_FMSEL_Msk                 (0xFFFFFFFU << CAN_FMCFG_FMSEL_Pos)     /*!< 0x0FFFFFFF */
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
#define CAN_FMCFG_FMSEL14_Pos               (14U)
#define CAN_FMCFG_FMSEL14_Msk               (0x1U << CAN_FMCFG_FMSEL14_Pos)         /*!< 0x00004000 */
#define CAN_FMCFG_FMSEL14                   CAN_FMCFG_FMSEL14_Msk                   /*!< Filter mode select for filter 14 */
#define CAN_FMCFG_FMSEL15_Pos               (15U)
#define CAN_FMCFG_FMSEL15_Msk               (0x1U << CAN_FMCFG_FMSEL15_Pos)         /*!< 0x00008000 */
#define CAN_FMCFG_FMSEL15                   CAN_FMCFG_FMSEL15_Msk                   /*!< Filter mode select for filter 15 */
#define CAN_FMCFG_FMSEL16_Pos               (16U)
#define CAN_FMCFG_FMSEL16_Msk               (0x1U << CAN_FMCFG_FMSEL16_Pos)         /*!< 0x00010000 */
#define CAN_FMCFG_FMSEL16                   CAN_FMCFG_FMSEL16_Msk                   /*!< Filter mode select for filter 16 */
#define CAN_FMCFG_FMSEL17_Pos               (17U)
#define CAN_FMCFG_FMSEL17_Msk               (0x1U << CAN_FMCFG_FMSEL17_Pos)         /*!< 0x00020000 */
#define CAN_FMCFG_FMSEL17                   CAN_FMCFG_FMSEL17_Msk                   /*!< Filter mode select for filter 17 */
#define CAN_FMCFG_FMSEL18_Pos               (18U)
#define CAN_FMCFG_FMSEL18_Msk               (0x1U << CAN_FMCFG_FMSEL18_Pos)         /*!< 0x00040000 */
#define CAN_FMCFG_FMSEL18                   CAN_FMCFG_FMSEL18_Msk                   /*!< Filter mode select for filter 18 */
#define CAN_FMCFG_FMSEL19_Pos               (19U)
#define CAN_FMCFG_FMSEL19_Msk               (0x1U << CAN_FMCFG_FMSEL19_Pos)         /*!< 0x00080000 */
#define CAN_FMCFG_FMSEL19                   CAN_FMCFG_FMSEL19_Msk                   /*!< Filter mode select for filter 19 */
#define CAN_FMCFG_FMSEL20_Pos               (20U)
#define CAN_FMCFG_FMSEL20_Msk               (0x1U << CAN_FMCFG_FMSEL20_Pos)         /*!< 0x00100000 */
#define CAN_FMCFG_FMSEL20                   CAN_FMCFG_FMSEL20_Msk                   /*!< Filter mode select for filter 20 */
#define CAN_FMCFG_FMSEL21_Pos               (21U)
#define CAN_FMCFG_FMSEL21_Msk               (0x1U << CAN_FMCFG_FMSEL21_Pos)         /*!< 0x00200000 */
#define CAN_FMCFG_FMSEL21                   CAN_FMCFG_FMSEL21_Msk                   /*!< Filter mode select for filter 21 */
#define CAN_FMCFG_FMSEL22_Pos               (22U)
#define CAN_FMCFG_FMSEL22_Msk               (0x1U << CAN_FMCFG_FMSEL22_Pos)         /*!< 0x00400000 */
#define CAN_FMCFG_FMSEL22                   CAN_FMCFG_FMSEL22_Msk                   /*!< Filter mode select for filter 22 */
#define CAN_FMCFG_FMSEL23_Pos               (23U)
#define CAN_FMCFG_FMSEL23_Msk               (0x1U << CAN_FMCFG_FMSEL23_Pos)         /*!< 0x00800000 */
#define CAN_FMCFG_FMSEL23                   CAN_FMCFG_FMSEL23_Msk                   /*!< Filter mode select for filter 23 */
#define CAN_FMCFG_FMSEL24_Pos               (24U)
#define CAN_FMCFG_FMSEL24_Msk               (0x1U << CAN_FMCFG_FMSEL24_Pos)         /*!< 0x01000000 */
#define CAN_FMCFG_FMSEL24                   CAN_FMCFG_FMSEL24_Msk                   /*!< Filter mode select for filter 24 */
#define CAN_FMCFG_FMSEL25_Pos               (25U)
#define CAN_FMCFG_FMSEL25_Msk               (0x1U << CAN_FMCFG_FMSEL25_Pos)         /*!< 0x02000000 */
#define CAN_FMCFG_FMSEL25                   CAN_FMCFG_FMSEL25_Msk                   /*!< Filter mode select for filter 25 */
#define CAN_FMCFG_FMSEL26_Pos               (26U)
#define CAN_FMCFG_FMSEL26_Msk               (0x1U << CAN_FMCFG_FMSEL26_Pos)         /*!< 0x04000000 */
#define CAN_FMCFG_FMSEL26                   CAN_FMCFG_FMSEL26_Msk                   /*!< Filter mode select for filter 26 */
#define CAN_FMCFG_FMSEL27_Pos               (27U)
#define CAN_FMCFG_FMSEL27_Msk               (0x1U << CAN_FMCFG_FMSEL27_Pos)         /*!< 0x08000000 */
#define CAN_FMCFG_FMSEL27                   CAN_FMCFG_FMSEL27_Msk                   /*!< Filter mode select for filter 27 */

/******************  Bit definition for CAN_FBWCFG register  ******************/
#define CAN_FBWCFG_FBWSEL_Pos               (0U)
#define CAN_FBWCFG_FBWSEL_Msk               (0xFFFFFFFU << CAN_FBWCFG_FBWSEL_Pos)   /*!< 0x0FFFFFFF */
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
#define CAN_FBWCFG_FBWSEL14_Pos             (14U)
#define CAN_FBWCFG_FBWSEL14_Msk             (0x1U << CAN_FBWCFG_FBWSEL14_Pos)       /*!< 0x00004000 */
#define CAN_FBWCFG_FBWSEL14                 CAN_FBWCFG_FBWSEL14_Msk                 /*!< Filter bit width select for filter 14 */
#define CAN_FBWCFG_FBWSEL15_Pos             (15U)
#define CAN_FBWCFG_FBWSEL15_Msk             (0x1U << CAN_FBWCFG_FBWSEL15_Pos)       /*!< 0x00008000 */
#define CAN_FBWCFG_FBWSEL15                 CAN_FBWCFG_FBWSEL15_Msk                 /*!< Filter bit width select for filter 15 */
#define CAN_FBWCFG_FBWSEL16_Pos             (16U)
#define CAN_FBWCFG_FBWSEL16_Msk             (0x1U << CAN_FBWCFG_FBWSEL16_Pos)       /*!< 0x00010000 */
#define CAN_FBWCFG_FBWSEL16                 CAN_FBWCFG_FBWSEL16_Msk                 /*!< Filter bit width select for filter 16 */
#define CAN_FBWCFG_FBWSEL17_Pos             (17U)
#define CAN_FBWCFG_FBWSEL17_Msk             (0x1U << CAN_FBWCFG_FBWSEL17_Pos)       /*!< 0x00020000 */
#define CAN_FBWCFG_FBWSEL17                 CAN_FBWCFG_FBWSEL17_Msk                 /*!< Filter bit width select for filter 17 */
#define CAN_FBWCFG_FBWSEL18_Pos             (18U)
#define CAN_FBWCFG_FBWSEL18_Msk             (0x1U << CAN_FBWCFG_FBWSEL18_Pos)       /*!< 0x00040000 */
#define CAN_FBWCFG_FBWSEL18                 CAN_FBWCFG_FBWSEL18_Msk                 /*!< Filter bit width select for filter 18 */
#define CAN_FBWCFG_FBWSEL19_Pos             (19U)
#define CAN_FBWCFG_FBWSEL19_Msk             (0x1U << CAN_FBWCFG_FBWSEL19_Pos)       /*!< 0x00080000 */
#define CAN_FBWCFG_FBWSEL19                 CAN_FBWCFG_FBWSEL19_Msk                 /*!< Filter bit width select for filter 19 */
#define CAN_FBWCFG_FBWSEL20_Pos             (20U)
#define CAN_FBWCFG_FBWSEL20_Msk             (0x1U << CAN_FBWCFG_FBWSEL20_Pos)       /*!< 0x00100000 */
#define CAN_FBWCFG_FBWSEL20                 CAN_FBWCFG_FBWSEL20_Msk                 /*!< Filter bit width select for filter 20 */
#define CAN_FBWCFG_FBWSEL21_Pos             (21U)
#define CAN_FBWCFG_FBWSEL21_Msk             (0x1U << CAN_FBWCFG_FBWSEL21_Pos)       /*!< 0x00200000 */
#define CAN_FBWCFG_FBWSEL21                 CAN_FBWCFG_FBWSEL21_Msk                 /*!< Filter bit width select for filter 21 */
#define CAN_FBWCFG_FBWSEL22_Pos             (22U)
#define CAN_FBWCFG_FBWSEL22_Msk             (0x1U << CAN_FBWCFG_FBWSEL22_Pos)       /*!< 0x00400000 */
#define CAN_FBWCFG_FBWSEL22                 CAN_FBWCFG_FBWSEL22_Msk                 /*!< Filter bit width select for filter 22 */
#define CAN_FBWCFG_FBWSEL23_Pos             (23U)
#define CAN_FBWCFG_FBWSEL23_Msk             (0x1U << CAN_FBWCFG_FBWSEL23_Pos)       /*!< 0x00800000 */
#define CAN_FBWCFG_FBWSEL23                 CAN_FBWCFG_FBWSEL23_Msk                 /*!< Filter bit width select for filter 23 */
#define CAN_FBWCFG_FBWSEL24_Pos             (24U)
#define CAN_FBWCFG_FBWSEL24_Msk             (0x1U << CAN_FBWCFG_FBWSEL24_Pos)       /*!< 0x01000000 */
#define CAN_FBWCFG_FBWSEL24                 CAN_FBWCFG_FBWSEL24_Msk                 /*!< Filter bit width select for filter 24 */
#define CAN_FBWCFG_FBWSEL25_Pos             (25U)
#define CAN_FBWCFG_FBWSEL25_Msk             (0x1U << CAN_FBWCFG_FBWSEL25_Pos)       /*!< 0x02000000 */
#define CAN_FBWCFG_FBWSEL25                 CAN_FBWCFG_FBWSEL25_Msk                 /*!< Filter bit width select for filter 25 */
#define CAN_FBWCFG_FBWSEL26_Pos             (26U)
#define CAN_FBWCFG_FBWSEL26_Msk             (0x1U << CAN_FBWCFG_FBWSEL26_Pos)       /*!< 0x04000000 */
#define CAN_FBWCFG_FBWSEL26                 CAN_FBWCFG_FBWSEL26_Msk                 /*!< Filter bit width select for filter 26 */
#define CAN_FBWCFG_FBWSEL27_Pos             (27U)
#define CAN_FBWCFG_FBWSEL27_Msk             (0x1U << CAN_FBWCFG_FBWSEL27_Pos)       /*!< 0x08000000 */
#define CAN_FBWCFG_FBWSEL27                 CAN_FBWCFG_FBWSEL27_Msk                 /*!< Filter bit width select for filter 27 */

/*******************  Bit definition for CAN_FRF register  ********************/
#define CAN_FRF_FRFSEL_Pos                  (0U)
#define CAN_FRF_FRFSEL_Msk                  (0xFFFFFFFU << CAN_FRF_FRFSEL_Pos)      /*!< 0x0FFFFFFF */
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
#define CAN_FRF_FRFSEL14_Pos                (14U)
#define CAN_FRF_FRFSEL14_Msk                (0x1U << CAN_FRF_FRFSEL14_Pos)          /*!< 0x00004000 */
#define CAN_FRF_FRFSEL14                    CAN_FRF_FRFSEL14_Msk                    /*!< Filter relation FIFO select for filter 14 */
#define CAN_FRF_FRFSEL15_Pos                (15U)
#define CAN_FRF_FRFSEL15_Msk                (0x1U << CAN_FRF_FRFSEL15_Pos)          /*!< 0x00008000 */
#define CAN_FRF_FRFSEL15                    CAN_FRF_FRFSEL15_Msk                    /*!< Filter relation FIFO select for filter 15 */
#define CAN_FRF_FRFSEL16_Pos                (16U)
#define CAN_FRF_FRFSEL16_Msk                (0x1U << CAN_FRF_FRFSEL16_Pos)          /*!< 0x00010000 */
#define CAN_FRF_FRFSEL16                    CAN_FRF_FRFSEL16_Msk                    /*!< Filter relation FIFO select for filter 16 */
#define CAN_FRF_FRFSEL17_Pos                (17U)
#define CAN_FRF_FRFSEL17_Msk                (0x1U << CAN_FRF_FRFSEL17_Pos)          /*!< 0x00020000 */
#define CAN_FRF_FRFSEL17                    CAN_FRF_FRFSEL17_Msk                    /*!< Filter relation FIFO select for filter 17 */
#define CAN_FRF_FRFSEL18_Pos                (18U)
#define CAN_FRF_FRFSEL18_Msk                (0x1U << CAN_FRF_FRFSEL18_Pos)          /*!< 0x00040000 */
#define CAN_FRF_FRFSEL18                    CAN_FRF_FRFSEL18_Msk                    /*!< Filter relation FIFO select for filter 18 */
#define CAN_FRF_FRFSEL19_Pos                (19U)
#define CAN_FRF_FRFSEL19_Msk                (0x1U << CAN_FRF_FRFSEL19_Pos)          /*!< 0x00080000 */
#define CAN_FRF_FRFSEL19                    CAN_FRF_FRFSEL19_Msk                    /*!< Filter relation FIFO select for filter 19 */
#define CAN_FRF_FRFSEL20_Pos                (20U)
#define CAN_FRF_FRFSEL20_Msk                (0x1U << CAN_FRF_FRFSEL20_Pos)          /*!< 0x00100000 */
#define CAN_FRF_FRFSEL20                    CAN_FRF_FRFSEL20_Msk                    /*!< Filter relation FIFO select for filter 20 */
#define CAN_FRF_FRFSEL21_Pos                (21U)
#define CAN_FRF_FRFSEL21_Msk                (0x1U << CAN_FRF_FRFSEL21_Pos)          /*!< 0x00200000 */
#define CAN_FRF_FRFSEL21                    CAN_FRF_FRFSEL21_Msk                    /*!< Filter relation FIFO select for filter 21 */
#define CAN_FRF_FRFSEL22_Pos                (22U)
#define CAN_FRF_FRFSEL22_Msk                (0x1U << CAN_FRF_FRFSEL22_Pos)          /*!< 0x00400000 */
#define CAN_FRF_FRFSEL22                    CAN_FRF_FRFSEL22_Msk                    /*!< Filter relation FIFO select for filter 22 */
#define CAN_FRF_FRFSEL23_Pos                (23U)
#define CAN_FRF_FRFSEL23_Msk                (0x1U << CAN_FRF_FRFSEL23_Pos)          /*!< 0x00800000 */
#define CAN_FRF_FRFSEL23                    CAN_FRF_FRFSEL23_Msk                    /*!< Filter relation FIFO select for filter 23 */
#define CAN_FRF_FRFSEL24_Pos                (24U)
#define CAN_FRF_FRFSEL24_Msk                (0x1U << CAN_FRF_FRFSEL24_Pos)          /*!< 0x01000000 */
#define CAN_FRF_FRFSEL24                    CAN_FRF_FRFSEL24_Msk                    /*!< Filter relation FIFO select for filter 24 */
#define CAN_FRF_FRFSEL25_Pos                (25U)
#define CAN_FRF_FRFSEL25_Msk                (0x1U << CAN_FRF_FRFSEL25_Pos)          /*!< 0x02000000 */
#define CAN_FRF_FRFSEL25                    CAN_FRF_FRFSEL25_Msk                    /*!< Filter relation FIFO select for filter 25 */
#define CAN_FRF_FRFSEL26_Pos                (26U)
#define CAN_FRF_FRFSEL26_Msk                (0x1U << CAN_FRF_FRFSEL26_Pos)          /*!< 0x04000000 */
#define CAN_FRF_FRFSEL26                    CAN_FRF_FRFSEL26_Msk                    /*!< Filter relation FIFO select for filter 26 */
#define CAN_FRF_FRFSEL27_Pos                (27U)
#define CAN_FRF_FRFSEL27_Msk                (0x1U << CAN_FRF_FRFSEL27_Pos)          /*!< 0x08000000 */
#define CAN_FRF_FRFSEL27                    CAN_FRF_FRFSEL27_Msk                    /*!< Filter relation FIFO select for filter 27 */

/******************  Bit definition for CAN_FACFG register  *******************/
#define CAN_FACFG_FAEN_Pos                  (0U)
#define CAN_FACFG_FAEN_Msk                  (0xFFFFFFFU << CAN_FACFG_FAEN_Pos)      /*!< 0x0FFFFFFF */
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
#define CAN_FACFG_FAEN14_Pos                (14U)
#define CAN_FACFG_FAEN14_Msk                (0x1U << CAN_FACFG_FAEN14_Pos)          /*!< 0x00004000 */
#define CAN_FACFG_FAEN14                    CAN_FACFG_FAEN14_Msk                    /*!< Filter 14 active enable */
#define CAN_FACFG_FAEN15_Pos                (15U)
#define CAN_FACFG_FAEN15_Msk                (0x1U << CAN_FACFG_FAEN15_Pos)          /*!< 0x00008000 */
#define CAN_FACFG_FAEN15                    CAN_FACFG_FAEN15_Msk                    /*!< Filter 15 active enable */
#define CAN_FACFG_FAEN16_Pos                (16U)
#define CAN_FACFG_FAEN16_Msk                (0x1U << CAN_FACFG_FAEN16_Pos)          /*!< 0x00010000 */
#define CAN_FACFG_FAEN16                    CAN_FACFG_FAEN16_Msk                    /*!< Filter 16 active enable */
#define CAN_FACFG_FAEN17_Pos                (17U)
#define CAN_FACFG_FAEN17_Msk                (0x1U << CAN_FACFG_FAEN17_Pos)          /*!< 0x00020000 */
#define CAN_FACFG_FAEN17                    CAN_FACFG_FAEN17_Msk                    /*!< Filter 17 active enable */
#define CAN_FACFG_FAEN18_Pos                (18U)
#define CAN_FACFG_FAEN18_Msk                (0x1U << CAN_FACFG_FAEN18_Pos)          /*!< 0x00040000 */
#define CAN_FACFG_FAEN18                    CAN_FACFG_FAEN18_Msk                    /*!< Filter 18 active enable */
#define CAN_FACFG_FAEN19_Pos                (19U)
#define CAN_FACFG_FAEN19_Msk                (0x1U << CAN_FACFG_FAEN19_Pos)          /*!< 0x00080000 */
#define CAN_FACFG_FAEN19                    CAN_FACFG_FAEN19_Msk                    /*!< Filter 19 active enable */
#define CAN_FACFG_FAEN20_Pos                (20U)
#define CAN_FACFG_FAEN20_Msk                (0x1U << CAN_FACFG_FAEN20_Pos)          /*!< 0x00100000 */
#define CAN_FACFG_FAEN20                    CAN_FACFG_FAEN20_Msk                    /*!< Filter 20 active enable */
#define CAN_FACFG_FAEN21_Pos                (21U)
#define CAN_FACFG_FAEN21_Msk                (0x1U << CAN_FACFG_FAEN21_Pos)          /*!< 0x00200000 */
#define CAN_FACFG_FAEN21                    CAN_FACFG_FAEN21_Msk                    /*!< Filter 21 active enable */
#define CAN_FACFG_FAEN22_Pos                (22U)
#define CAN_FACFG_FAEN22_Msk                (0x1U << CAN_FACFG_FAEN22_Pos)          /*!< 0x00400000 */
#define CAN_FACFG_FAEN22                    CAN_FACFG_FAEN22_Msk                    /*!< Filter 22 active enable */
#define CAN_FACFG_FAEN23_Pos                (23U)
#define CAN_FACFG_FAEN23_Msk                (0x1U << CAN_FACFG_FAEN23_Pos)          /*!< 0x00800000 */
#define CAN_FACFG_FAEN23                    CAN_FACFG_FAEN23_Msk                    /*!< Filter 23 active enable */
#define CAN_FACFG_FAEN24_Pos                (24U)
#define CAN_FACFG_FAEN24_Msk                (0x1U << CAN_FACFG_FAEN24_Pos)          /*!< 0x01000000 */
#define CAN_FACFG_FAEN24                    CAN_FACFG_FAEN24_Msk                    /*!< Filter 24 active enable */
#define CAN_FACFG_FAEN25_Pos                (25U)
#define CAN_FACFG_FAEN25_Msk                (0x1U << CAN_FACFG_FAEN25_Pos)          /*!< 0x02000000 */
#define CAN_FACFG_FAEN25                    CAN_FACFG_FAEN25_Msk                    /*!< Filter 25 active enable */
#define CAN_FACFG_FAEN26_Pos                (26U)
#define CAN_FACFG_FAEN26_Msk                (0x1U << CAN_FACFG_FAEN26_Pos)          /*!< 0x04000000 */
#define CAN_FACFG_FAEN26                    CAN_FACFG_FAEN26_Msk                    /*!< Filter 26 active enable */
#define CAN_FACFG_FAEN27_Pos                (27U)
#define CAN_FACFG_FAEN27_Msk                (0x1U << CAN_FACFG_FAEN27_Pos)          /*!< 0x08000000 */
#define CAN_FACFG_FAEN27                    CAN_FACFG_FAEN27_Msk                    /*!< Filter 27 active enable */

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
/*                     HICK auto clock calibration (ACC)                      */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for ACC_STS register  ********************/
#define ACC_STS_CALRDY_Pos                  (0U)
#define ACC_STS_CALRDY_Msk                  (0x1U << ACC_STS_CALRDY_Pos)            /*!< 0x00000001 */
#define ACC_STS_CALRDY                      ACC_STS_CALRDY_Msk                      /*!< Internal high-speed clock calibration ready */
#define ACC_STS_RSLOST_Pos                  (1U)
#define ACC_STS_RSLOST_Msk                  (0x1U << ACC_STS_RSLOST_Pos)            /*!< 0x00000002 */
#define ACC_STS_RSLOST                      ACC_STS_RSLOST_Msk                      /*!< Reference signal lost */

/******************  Bit definition for ACC_CTRL1 register  *******************/
#define ACC_CTRL1_CALON_Pos                 (0U)
#define ACC_CTRL1_CALON_Msk                 (0x1U << ACC_CTRL1_CALON_Pos)           /*!< 0x00000001 */
#define ACC_CTRL1_CALON                     ACC_CTRL1_CALON_Msk                     /*!< Calibration on */
#define ACC_CTRL1_ENTRIM_Pos                (1U)
#define ACC_CTRL1_ENTRIM_Msk                (0x1U << ACC_CTRL1_ENTRIM_Pos)          /*!< 0x00000002 */
#define ACC_CTRL1_ENTRIM                    ACC_CTRL1_ENTRIM_Msk                    /*!< Enable trim */
#define ACC_CTRL1_SOFSEL_Pos                (2U)
#define ACC_CTRL1_SOFSEL_Msk                (0x1U << ACC_CTRL1_SOFSEL_Pos)          /*!< 0x00000004 */
#define ACC_CTRL1_SOFSEL                    ACC_CTRL1_SOFSEL_Msk                    /*!< SOF select */
#define ACC_CTRL1_SOFSEL_USB1               0
#define ACC_CTRL1_SOFSEL_USB2               ACC_CTRL1_SOFSEL
#define ACC_CTRL1_EIEN_Pos                  (4U)
#define ACC_CTRL1_EIEN_Msk                  (0x1U << ACC_CTRL1_EIEN_Pos)            /*!< 0x00000010 */
#define ACC_CTRL1_EIEN                      ACC_CTRL1_EIEN_Msk                      /*!< RSLOST error interrupt enable */
#define ACC_CTRL1_CALRDYIEN_Pos             (5U)
#define ACC_CTRL1_CALRDYIEN_Msk             (0x1U << ACC_CTRL1_CALRDYIEN_Pos)       /*!< 0x00000020 */
#define ACC_CTRL1_CALRDYIEN                 ACC_CTRL1_CALRDYIEN_Msk                 /*!< CALRDY interrupt enable */
#define ACC_CTRL1_STEP_Pos                  (8U)
#define ACC_CTRL1_STEP_Msk                  (0xFU << ACC_CTRL1_STEP_Pos)            /*!< 0x00000F00 */
#define ACC_CTRL1_STEP                      ACC_CTRL1_STEP_Msk                      /*!< Calibrated step */

/******************  Bit definition for ACC_CTRL2 register  *******************/
#define ACC_CTRL2_HICKCAL_Pos               (0U)
#define ACC_CTRL2_HICKCAL_Msk               (0xFFU << ACC_CTRL2_HICKCAL_Pos)        /*!< 0x000000FF */
#define ACC_CTRL2_HICKCAL                   ACC_CTRL2_HICKCAL_Msk                   /*!< Internal high-speed auto clock calibration */
#define ACC_CTRL2_HICKTRIM_Pos              (8U)
#define ACC_CTRL2_HICKTRIM_Msk              (0x3FU << ACC_CTRL2_HICKTRIM_Pos)       /*!< 0x00003F00 */
#define ACC_CTRL2_HICKTRIM                  ACC_CTRL2_HICKTRIM_Msk                  /*!< Internal high-speed auto clock trimming */

/*******************  Bit definition for ACC_CP1 register  ********************/
#define ACC_CP1_C1_Pos                      (0U)
#define ACC_CP1_C1_Msk                      (0xFFFFU << ACC_CP1_C1_Pos)             /*!< 0x0000FFFF */
#define ACC_CP1_C1                          ACC_CP1_C1_Msk                          /*!< Compare 1 */

/*******************  Bit definition for ACC_CP2 register  ********************/
#define ACC_CP2_C2_Pos                      (0U)
#define ACC_CP2_C2_Msk                      (0xFFFFU << ACC_CP2_C2_Pos)             /*!< 0x0000FFFF */
#define ACC_CP2_C2                          ACC_CP2_C2_Msk                          /*!< Compare 2 */

/*******************  Bit definition for ACC_CP3 register  ********************/
#define ACC_CP3_C3_Pos                      (0U)
#define ACC_CP3_C3_Msk                      (0xFFFFU << ACC_CP3_C3_Pos)             /*!< 0x0000FFFF */
#define ACC_CP3_C3                          ACC_CP3_C3_Msk                          /*!< Compare 3 */

/******************************************************************************/
/*                                                                            */
/*                         Quad-SPI interface (QSPI)                          */
/*                                                                            */
/******************************************************************************/

/*****************  Bit definition for QSPI_CMD_W0 register  ******************/
#define QSPI_CMD_W0_SPIADR_Pos              (0U)
#define QSPI_CMD_W0_SPIADR_Msk              (0xFFFFFFFFU << QSPI_CMD_W0_SPIADR_Pos) /*!< 0xFFFFFFFF */
#define QSPI_CMD_W0_SPIADR                  QSPI_CMD_W0_SPIADR_Msk                  /*!< SPI Flash address */

/*****************  Bit definition for QSPI_CMD_W1 register  ******************/
/*!< ADRLEN congiguration */
#define QSPI_CMD_W1_ADRLEN_Pos              (0U)
#define QSPI_CMD_W1_ADRLEN_Msk              (0x7U << QSPI_CMD_W1_ADRLEN_Pos)        /*!< 0x00000007 */
#define QSPI_CMD_W1_ADRLEN                  QSPI_CMD_W1_ADRLEN_Msk                  /*!< ADRLEN[2:0] bits (SPI address length) */
#define QSPI_CMD_W1_ADRLEN_0                (0x1U << QSPI_CMD_W1_ADRLEN_Pos)        /*!< 0x00000001 */
#define QSPI_CMD_W1_ADRLEN_1                (0x2U << QSPI_CMD_W1_ADRLEN_Pos)        /*!< 0x00000002 */
#define QSPI_CMD_W1_ADRLEN_2                (0x4U << QSPI_CMD_W1_ADRLEN_Pos)        /*!< 0x00000004 */

#define QSPI_CMD_W1_ADRLEN_NOBYTE           0x00000000U                             /*!< No address state */
#define QSPI_CMD_W1_ADRLEN_1BYTE            0x00000001U                             /*!< 1-byte address */
#define QSPI_CMD_W1_ADRLEN_2BYTE            0x00000002U                             /*!< 2-byte address */
#define QSPI_CMD_W1_ADRLEN_3BYTE            0x00000003U                             /*!< 3-byte address */
#define QSPI_CMD_W1_ADRLEN_4BYTE            0x00000004U                             /*!< 4-byte address */

/*!< DUM2 congiguration */
#define QSPI_CMD_W1_DUM2_Pos                (16U)
#define QSPI_CMD_W1_DUM2_Msk                (0xFFU << QSPI_CMD_W1_DUM2_Pos)         /*!< 0x00FF0000 */
#define QSPI_CMD_W1_DUM2                    QSPI_CMD_W1_DUM2_Msk                    /*!< DUM2[7:0] bits (Second dummy state cycle) */
#define QSPI_CMD_W1_DUM2_0                  (0x01U << QSPI_CMD_W1_DUM2_Pos)         /*!< 0x00010000 */
#define QSPI_CMD_W1_DUM2_1                  (0x02U << QSPI_CMD_W1_DUM2_Pos)         /*!< 0x00020000 */
#define QSPI_CMD_W1_DUM2_2                  (0x04U << QSPI_CMD_W1_DUM2_Pos)         /*!< 0x00040000 */
#define QSPI_CMD_W1_DUM2_3                  (0x08U << QSPI_CMD_W1_DUM2_Pos)         /*!< 0x00080000 */
#define QSPI_CMD_W1_DUM2_4                  (0x10U << QSPI_CMD_W1_DUM2_Pos)         /*!< 0x00100000 */
#define QSPI_CMD_W1_DUM2_5                  (0x20U << QSPI_CMD_W1_DUM2_Pos)         /*!< 0x00200000 */
#define QSPI_CMD_W1_DUM2_6                  (0x40U << QSPI_CMD_W1_DUM2_Pos)         /*!< 0x00400000 */
#define QSPI_CMD_W1_DUM2_7                  (0x80U << QSPI_CMD_W1_DUM2_Pos)         /*!< 0x00800000 */

/*!< INSLEN congiguration */
#define QSPI_CMD_W1_INSLEN_Pos              (24U)
#define QSPI_CMD_W1_INSLEN_Msk              (0x3U << QSPI_CMD_W1_INSLEN_Pos)        /*!< 0x03000000 */
#define QSPI_CMD_W1_INSLEN                  QSPI_CMD_W1_INSLEN_Msk                  /*!< INSLEN[1:0] bits (Instruction code length) */
#define QSPI_CMD_W1_INSLEN_0                (0x1U << QSPI_CMD_W1_INSLEN_Pos)        /*!< 0x01000000 */
#define QSPI_CMD_W1_INSLEN_1                (0x2U << QSPI_CMD_W1_INSLEN_Pos)        /*!< 0x02000000 */

#define QSPI_CMD_W1_INSLEN_NOINS            0x00000000U                             /*!< No instruction code */
#define QSPI_CMD_W1_INSLEN_1INS             0x01000000U                             /*!< 1-byte instruction code */
#define QSPI_CMD_W1_INSLEN_2INS             0x02000000U                             /*!< 2-byte instruction code (repeated instruction code) */

#define QSPI_CMD_W1_PEMEN_Pos               (28U)
#define QSPI_CMD_W1_PEMEN_Msk               (0x1U << QSPI_CMD_W1_PEMEN_Pos)         /*!< 0x10000000 */
#define QSPI_CMD_W1_PEMEN                   QSPI_CMD_W1_PEMEN_Msk                   /*!< Performance enhanced mode enable */

/*****************  Bit definition for QSPI_CMD_W2 register  ******************/
#define QSPI_CMD_W2_DCNT_Pos                (0U)
#define QSPI_CMD_W2_DCNT_Msk                (0xFFFFFFFFU << QSPI_CMD_W2_DCNT_Pos)   /*!< 0xFFFFFFFF */
#define QSPI_CMD_W2_DCNT                    QSPI_CMD_W2_DCNT_Msk                    /*!< Read/Write data counter */

/*****************  Bit definition for QSPI_CMD_W3 register  ******************/
#define QSPI_CMD_W3_WEN_Pos                 (1U)
#define QSPI_CMD_W3_WEN_Msk                 (0x1U << QSPI_CMD_W3_WEN_Pos)           /*!< 0x00000002 */
#define QSPI_CMD_W3_WEN                     QSPI_CMD_W3_WEN_Msk                     /*!< Write data enable */
#define QSPI_CMD_W3_RSTSEN_Pos              (2U)
#define QSPI_CMD_W3_RSTSEN_Msk              (0x1U << QSPI_CMD_W3_RSTSEN_Pos)        /*!< 0x00000004 */
#define QSPI_CMD_W3_RSTSEN                  QSPI_CMD_W3_RSTSEN_Msk                  /*!< Read SPI status enable */
#define QSPI_CMD_W3_RSTSC_Pos               (3U)
#define QSPI_CMD_W3_RSTSC_Msk               (0x1U << QSPI_CMD_W3_RSTSC_Pos)         /*!< 0x00000008 */
#define QSPI_CMD_W3_RSTSC                   QSPI_CMD_W3_RSTSC_Msk                   /*!< Read SPI status configuration */

/*!< OPMODE congiguration */
#define QSPI_CMD_W3_OPMODE_Pos              (5U)
#define QSPI_CMD_W3_OPMODE_Msk              (0x7U << QSPI_CMD_W3_OPMODE_Pos)        /*!< 0x000000E0 */
#define QSPI_CMD_W3_OPMODE                  QSPI_CMD_W3_OPMODE_Msk                  /*!< OPMODE[2:0] bits (SPI Operation mode) */
#define QSPI_CMD_W3_OPMODE_0                (0x1U << QSPI_CMD_W3_OPMODE_Pos)        /*!< 0x00000020 */
#define QSPI_CMD_W3_OPMODE_1                (0x2U << QSPI_CMD_W3_OPMODE_Pos)        /*!< 0x00000040 */
#define QSPI_CMD_W3_OPMODE_2                (0x4U << QSPI_CMD_W3_OPMODE_Pos)        /*!< 0x00000080 */

#define QSPI_CMD_W3_OPMODE_SERIAL           0x00000000U                             /*!< Serial mode (1-1-1) */
#define QSPI_CMD_W3_OPMODE_DUAL             0x00000020U                             /*!< Dual-wire mode (1-1-2) */
#define QSPI_CMD_W3_OPMODE_QUAD             0x00000040U                             /*!< Quad mode (1-1-4) */
#define QSPI_CMD_W3_OPMODE_DUALIO           0x00000060U                             /*!< Dual-wire I/O mode (1-2-2) */
#define QSPI_CMD_W3_OPMODE_QUADIO           0x00000080U                             /*!< Quad I/O mode (1-4-4) */
#define QSPI_CMD_W3_OPMODE_DPI              0x000000A0U                             /*!< DPI mode (2-2-2) */
#define QSPI_CMD_W3_OPMODE_QPI              0x000000C0U                             /*!< QPI mode (4-4-4) */

#define QSPI_CMD_W3_PEMOPC_Pos              (16U)
#define QSPI_CMD_W3_PEMOPC_Msk              (0xFFU << QSPI_CMD_W3_PEMOPC_Pos)       /*!< 0x00FF0000 */
#define QSPI_CMD_W3_PEMOPC                  QSPI_CMD_W3_PEMOPC_Msk                  /*!< Performance enhanced mode operation code */
#define QSPI_CMD_W3_INSC_Pos                (24U)
#define QSPI_CMD_W3_INSC_Msk                (0xFFU << QSPI_CMD_W3_INSC_Pos)         /*!< 0xFF000000 */
#define QSPI_CMD_W3_INSC                    QSPI_CMD_W3_INSC_Msk                    /*!< Instruction code */

/******************  Bit definition for QSPI_CTRL register  *******************/
/*!< CLKDIV congiguration */
#define QSPI_CTRL_CLKDIV_Pos                (0U)
#define QSPI_CTRL_CLKDIV_Msk                (0x7U << QSPI_CTRL_CLKDIV_Pos)          /*!< 0x00000007 */
#define QSPI_CTRL_CLKDIV                    QSPI_CTRL_CLKDIV_Msk                    /*!< CLKDIV[2:0] bits (Clock divider) */
#define QSPI_CTRL_CLKDIV_0                  (0x1U << QSPI_CTRL_CLKDIV_Pos)          /*!< 0x00000001 */
#define QSPI_CTRL_CLKDIV_1                  (0x2U << QSPI_CTRL_CLKDIV_Pos)          /*!< 0x00000002 */
#define QSPI_CTRL_CLKDIV_2                  (0x4U << QSPI_CTRL_CLKDIV_Pos)          /*!< 0x00000004 */

#define QSPI_CTRL_CLKDIV_DIV2               0x00000000U                             /*!< Clock is divided by 2 */
#define QSPI_CTRL_CLKDIV_DIV4               0x00000001U                             /*!< Clock is divided by 4 */
#define QSPI_CTRL_CLKDIV_DIV6               0x00000002U                             /*!< Clock is divided by 6 */
#define QSPI_CTRL_CLKDIV_DIV8               0x00000003U                             /*!< Clock is divided by 8 */
#define QSPI_CTRL_CLKDIV_DIV3               0x00000004U                             /*!< Clock is divided by 3 */
#define QSPI_CTRL_CLKDIV_DIV5               0x00000005U                             /*!< Clock is divided by 5 */
#define QSPI_CTRL_CLKDIV_DIV10              0x00000006U                             /*!< Clock is divided by 10 */
#define QSPI_CTRL_CLKDIV_DIV12              0x00000007U                             /*!< Clock is divided by 12 */

#define QSPI_CTRL_SCKMODE_Pos               (4U)
#define QSPI_CTRL_SCKMODE_Msk               (0x1U << QSPI_CTRL_SCKMODE_Pos)         /*!< 0x00000010 */
#define QSPI_CTRL_SCKMODE                   QSPI_CTRL_SCKMODE_Msk                   /*!< SCK output mode */
#define QSPI_CTRL_XIPIDLE_Pos               (7U)
#define QSPI_CTRL_XIPIDLE_Msk               (0x1U << QSPI_CTRL_XIPIDLE_Pos)         /*!< 0x00000080 */
#define QSPI_CTRL_XIPIDLE                   QSPI_CTRL_XIPIDLE_Msk                   /*!< XIP port idle status */
#define QSPI_CTRL_ABORT_Pos                 (8U)
#define QSPI_CTRL_ABORT_Msk                 (0x1U << QSPI_CTRL_ABORT_Pos)           /*!< 0x00000100 */
#define QSPI_CTRL_ABORT                     QSPI_CTRL_ABORT_Msk                     /*!< Refresh all commands/FIFOs and reset state machine */

/*!< BUSY congiguration */
#define QSPI_CTRL_BUSY_Pos                  (16U)
#define QSPI_CTRL_BUSY_Msk                  (0x7U << QSPI_CTRL_BUSY_Pos)            /*!< 0x00070000 */
#define QSPI_CTRL_BUSY                      QSPI_CTRL_BUSY_Msk                      /*!< BUSY[2:0] bits (Busy bit of SPI status) */
#define QSPI_CTRL_BUSY_0                    (0x1U << QSPI_CTRL_BUSY_Pos)            /*!< 0x00010000 */
#define QSPI_CTRL_BUSY_1                    (0x2U << QSPI_CTRL_BUSY_Pos)            /*!< 0x00020000 */
#define QSPI_CTRL_BUSY_2                    (0x4U << QSPI_CTRL_BUSY_Pos)            /*!< 0x00040000 */

#define QSPI_CTRL_BUSY_BIT0                 0x00000000U                             /*!< Bit 0 */
#define QSPI_CTRL_BUSY_BIT1                 0x00010000U                             /*!< Bit 1 */
#define QSPI_CTRL_BUSY_BIT2                 0x00020000U                             /*!< Bit 2 */
#define QSPI_CTRL_BUSY_BIT3                 0x00030000U                             /*!< Bit 3 */
#define QSPI_CTRL_BUSY_BIT4                 0x00040000U                             /*!< Bit 4 */
#define QSPI_CTRL_BUSY_BIT5                 0x00050000U                             /*!< Bit 5 */
#define QSPI_CTRL_BUSY_BIT6                 0x00060000U                             /*!< Bit 6 */
#define QSPI_CTRL_BUSY_BIT7                 0x00070000U                             /*!< Bit 7 */

#define QSPI_CTRL_XIPRCMDF_Pos              (19U)
#define QSPI_CTRL_XIPRCMDF_Msk              (0x1U << QSPI_CTRL_XIPRCMDF_Pos)        /*!< 0x00080000 */
#define QSPI_CTRL_XIPRCMDF                  QSPI_CTRL_XIPRCMDF_Msk                  /*!< XIP read command flush */
#define QSPI_CTRL_XIPSEL_Pos                (20U)
#define QSPI_CTRL_XIPSEL_Msk                (0x1U << QSPI_CTRL_XIPSEL_Pos)          /*!< 0x00100000 */
#define QSPI_CTRL_XIPSEL                    QSPI_CTRL_XIPSEL_Msk                    /*!< XIP port selection */
#define QSPI_CTRL_KEYEN_Pos                 (21U)
#define QSPI_CTRL_KEYEN_Msk                 (0x1U << QSPI_CTRL_KEYEN_Pos)           /*!< 0x00200000 */
#define QSPI_CTRL_KEYEN                     QSPI_CTRL_KEYEN_Msk                     /*!< SPI data encryption key enable */

/*****************  Bit definition for QSPI_FIFOSTS register  *****************/
#define QSPI_FIFOSTS_TXFIFORDY_Pos          (0U)
#define QSPI_FIFOSTS_TXFIFORDY_Msk          (0x1U << QSPI_FIFOSTS_TXFIFORDY_Pos)    /*!< 0x00000001 */
#define QSPI_FIFOSTS_TXFIFORDY              QSPI_FIFOSTS_TXFIFORDY_Msk              /*!< TX FIFO ready status */
#define QSPI_FIFOSTS_RXFIFORDY_Pos          (1U)
#define QSPI_FIFOSTS_RXFIFORDY_Msk          (0x1U << QSPI_FIFOSTS_RXFIFORDY_Pos)    /*!< 0x00000002 */
#define QSPI_FIFOSTS_RXFIFORDY              QSPI_FIFOSTS_RXFIFORDY_Msk              /*!< RX FIFO ready status */

/******************  Bit definition for QSPI_CTRL2 register  ******************/
#define QSPI_CTRL2_DMAEN_Pos                (0U)
#define QSPI_CTRL2_DMAEN_Msk                (0x1U << QSPI_CTRL2_DMAEN_Pos)          /*!< 0x00000001 */
#define QSPI_CTRL2_DMAEN                    QSPI_CTRL2_DMAEN_Msk                    /*!< DMA enable */
#define QSPI_CTRL2_CMDIE_Pos                (1U)
#define QSPI_CTRL2_CMDIE_Msk                (0x1U << QSPI_CTRL2_CMDIE_Pos)          /*!< 0x00000002 */
#define QSPI_CTRL2_CMDIE                    QSPI_CTRL2_CMDIE_Msk                    /*!< Command complete Interrupt enable */

/*!< TXFIFO_THOD congiguration */
#define QSPI_CTRL2_TXFIFO_THOD_Pos          (8U)
#define QSPI_CTRL2_TXFIFO_THOD_Msk          (0x3U << QSPI_CTRL2_TXFIFO_THOD_Pos)    /*!< 0x00000300 */
#define QSPI_CTRL2_TXFIFO_THOD              QSPI_CTRL2_TXFIFO_THOD_Msk              /*!< TXFIFO_THOD[1:0] bits (Program the level value to trigger TX FIFO threshold IRQ) */
#define QSPI_CTRL2_TXFIFO_THOD_0            (0x1U << QSPI_CTRL2_TXFIFO_THOD_Pos)    /*!< 0x00000100 */
#define QSPI_CTRL2_TXFIFO_THOD_1            (0x2U << QSPI_CTRL2_TXFIFO_THOD_Pos)    /*!< 0x00000200 */

#define QSPI_CTRL2_TXFIFO_THOD_8WORD        0x00000000U                             /*!< 8 WORD */
#define QSPI_CTRL2_TXFIFO_THOD_16WORD       0x00000100U                             /*!< 16 WORD */
#define QSPI_CTRL2_TXFIFO_THOD_24WORD       0x00000200U                             /*!< 24 WORD */

/*!< RXFIFO_THOD congiguration */
#define QSPI_CTRL2_RXFIFO_THOD_Pos          (12U)
#define QSPI_CTRL2_RXFIFO_THOD_Msk          (0x3U << QSPI_CTRL2_RXFIFO_THOD_Pos)    /*!< 0x00003000 */
#define QSPI_CTRL2_RXFIFO_THOD              QSPI_CTRL2_RXFIFO_THOD_Msk              /*!< RXFIFO_THOD[1:0] bits (Program the level value to trigger RX FIFO threshold IRQ) */
#define QSPI_CTRL2_RXFIFO_THOD_0            (0x1U << QSPI_CTRL2_RXFIFO_THOD_Pos)    /*!< 0x00001000 */
#define QSPI_CTRL2_RXFIFO_THOD_1            (0x2U << QSPI_CTRL2_RXFIFO_THOD_Pos)    /*!< 0x00002000 */

#define QSPI_CTRL2_RXFIFO_THOD_8WORD        0x00000000U                             /*!< 8 WORD */
#define QSPI_CTRL2_RXFIFO_THOD_16WORD       0x00001000U                             /*!< 16 WORD */
#define QSPI_CTRL2_RXFIFO_THOD_24WORD       0x00002000U                             /*!< 24 WORD */

/*****************  Bit definition for QSPI_CMDSTS register  ******************/
#define QSPI_CMDSTS_CMDSTS_Pos              (0U)
#define QSPI_CMDSTS_CMDSTS_Msk              (0x1U << QSPI_CMDSTS_CMDSTS_Pos)        /*!< 0x00000001 */
#define QSPI_CMDSTS_CMDSTS                  QSPI_CMDSTS_CMDSTS_Msk                  /*!< Command complete status */

/******************  Bit definition for QSPI_RSTS register  *******************/
#define QSPI_RSTS_SPISTS_Pos                (0U)
#define QSPI_RSTS_SPISTS_Msk                (0xFFU << QSPI_RSTS_SPISTS_Pos)         /*!< 0x000000FF */
#define QSPI_RSTS_SPISTS                    QSPI_RSTS_SPISTS_Msk                    /*!< SPI read status */

/******************  Bit definition for QSPI_FSIZE register  ******************/
#define QSPI_FSIZE_SPIFSIZE_Pos             (0U)                                    /*!< 0xFFFFFFFF */
#define QSPI_FSIZE_SPIFSIZE_Msk             (0xFFFFFFFFU << QSPI_FSIZE_SPIFSIZE_Pos)
#define QSPI_FSIZE_SPIFSIZE                 QSPI_FSIZE_SPIFSIZE_Msk                 /*!< SPI flash size */

/***************  Bit definition for QSPI_XIP_CMD_W0 register  ****************/
/*!< XIPR_DUM2 congiguration */
#define QSPI_XIP_CMD_W0_XIPR_DUM2_Pos       (0U)
#define QSPI_XIP_CMD_W0_XIPR_DUM2_Msk       (0xFFU << QSPI_XIP_CMD_W0_XIPR_DUM2_Pos) /*!< 0x000000FF */
#define QSPI_XIP_CMD_W0_XIPR_DUM2           QSPI_XIP_CMD_W0_XIPR_DUM2_Msk            /*!< XIPR_DUM2[7:0] bits (XIP read second dummy cycle) */
#define QSPI_XIP_CMD_W0_XIPR_DUM2_0         (0x01U << QSPI_XIP_CMD_W0_XIPR_DUM2_Pos) /*!< 0x00000001 */
#define QSPI_XIP_CMD_W0_XIPR_DUM2_1         (0x02U << QSPI_XIP_CMD_W0_XIPR_DUM2_Pos) /*!< 0x00000002 */
#define QSPI_XIP_CMD_W0_XIPR_DUM2_2         (0x04U << QSPI_XIP_CMD_W0_XIPR_DUM2_Pos) /*!< 0x00000004 */
#define QSPI_XIP_CMD_W0_XIPR_DUM2_3         (0x08U << QSPI_XIP_CMD_W0_XIPR_DUM2_Pos) /*!< 0x00000008 */
#define QSPI_XIP_CMD_W0_XIPR_DUM2_4         (0x10U << QSPI_XIP_CMD_W0_XIPR_DUM2_Pos) /*!< 0x00000010 */
#define QSPI_XIP_CMD_W0_XIPR_DUM2_5         (0x20U << QSPI_XIP_CMD_W0_XIPR_DUM2_Pos) /*!< 0x00000020 */
#define QSPI_XIP_CMD_W0_XIPR_DUM2_6         (0x40U << QSPI_XIP_CMD_W0_XIPR_DUM2_Pos) /*!< 0x00000040 */
#define QSPI_XIP_CMD_W0_XIPR_DUM2_7         (0x80U << QSPI_XIP_CMD_W0_XIPR_DUM2_Pos) /*!< 0x00000080 */

/*!< XIPR_OPMODE congiguration */
#define QSPI_XIP_CMD_W0_XIPR_OPMODE_Pos     (8U)                                      /*!< 0x00000700 */
#define QSPI_XIP_CMD_W0_XIPR_OPMODE_Msk     (0x7U << QSPI_XIP_CMD_W0_XIPR_OPMODE_Pos)
#define QSPI_XIP_CMD_W0_XIPR_OPMODE         QSPI_XIP_CMD_W0_XIPR_OPMODE_Msk           /*!< XIPR_OPMODE[2:0] bits (XIP read operation mode) */
#define QSPI_XIP_CMD_W0_XIPR_OPMODE_0       (0x1U << QSPI_XIP_CMD_W0_XIPR_OPMODE_Pos) /*!< 0x00000100 */
#define QSPI_XIP_CMD_W0_XIPR_OPMODE_1       (0x2U << QSPI_XIP_CMD_W0_XIPR_OPMODE_Pos) /*!< 0x00000200 */
#define QSPI_XIP_CMD_W0_XIPR_OPMODE_2       (0x4U << QSPI_XIP_CMD_W0_XIPR_OPMODE_Pos) /*!< 0x00000400 */

#define QSPI_XIP_CMD_W0_XIPR_OPMODE_SERIAL  0x00000000U                             /*!< Serial mode (1-1-1) */
#define QSPI_XIP_CMD_W0_XIPR_OPMODE_DUAL    0x00000100U                             /*!< Dual-wire mode (1-1-2) */
#define QSPI_XIP_CMD_W0_XIPR_OPMODE_QUAD    0x00000200U                             /*!< Quad mode (1-1-4) */
#define QSPI_XIP_CMD_W0_XIPR_OPMODE_DUALIO  0x00000300U                             /*!< Dual-wire I/O mode (1-2-2) */
#define QSPI_XIP_CMD_W0_XIPR_OPMODE_QUADIO  0x00000400U                             /*!< Quad I/O mode (1-4-4) */
#define QSPI_XIP_CMD_W0_XIPR_OPMODE_DPI     0x00000500U                             /*!< DPI mode (2-2-2) */
#define QSPI_XIP_CMD_W0_XIPR_OPMODE_QPI     0x00000600U                             /*!< QPI mode (4-4-4) */

#define QSPI_XIP_CMD_W0_XIPR_ADRLEN_Pos     (11U)                                   /*!< 0x00000800 */
#define QSPI_XIP_CMD_W0_XIPR_ADRLEN_Msk     (0x1U << QSPI_XIP_CMD_W0_XIPR_ADRLEN_Pos)
#define QSPI_XIP_CMD_W0_XIPR_ADRLEN         QSPI_XIP_CMD_W0_XIPR_ADRLEN_Msk         /*!< XIP read address length */
#define QSPI_XIP_CMD_W0_XIPR_INSC_Pos       (12U)                                   /*!< 0x000FF000 */
#define QSPI_XIP_CMD_W0_XIPR_INSC_Msk       (0xFFU << QSPI_XIP_CMD_W0_XIPR_INSC_Pos)
#define QSPI_XIP_CMD_W0_XIPR_INSC           QSPI_XIP_CMD_W0_XIPR_INSC_Msk           /*!< XIP read instruction code */

/***************  Bit definition for QSPI_XIP_CMD_W1 register  ****************/
/*!< XIPW_DUM2 congiguration */
#define QSPI_XIP_CMD_W1_XIPW_DUM2_Pos       (0U)
#define QSPI_XIP_CMD_W1_XIPW_DUM2_Msk       (0xFFU << QSPI_XIP_CMD_W1_XIPW_DUM2_Pos) /*!< 0x000000FF */
#define QSPI_XIP_CMD_W1_XIPW_DUM2           QSPI_XIP_CMD_W1_XIPW_DUM2_Msk            /*!< XIPW_DUM2[7:0] bits (XIP write second dummy cycle) */
#define QSPI_XIP_CMD_W1_XIPW_DUM2_0         (0x01U << QSPI_XIP_CMD_W1_XIPW_DUM2_Pos) /*!< 0x00000001 */
#define QSPI_XIP_CMD_W1_XIPW_DUM2_1         (0x02U << QSPI_XIP_CMD_W1_XIPW_DUM2_Pos) /*!< 0x00000002 */
#define QSPI_XIP_CMD_W1_XIPW_DUM2_2         (0x04U << QSPI_XIP_CMD_W1_XIPW_DUM2_Pos) /*!< 0x00000004 */
#define QSPI_XIP_CMD_W1_XIPW_DUM2_3         (0x08U << QSPI_XIP_CMD_W1_XIPW_DUM2_Pos) /*!< 0x00000008 */
#define QSPI_XIP_CMD_W1_XIPW_DUM2_4         (0x10U << QSPI_XIP_CMD_W1_XIPW_DUM2_Pos) /*!< 0x00000010 */
#define QSPI_XIP_CMD_W1_XIPW_DUM2_5         (0x20U << QSPI_XIP_CMD_W1_XIPW_DUM2_Pos) /*!< 0x00000020 */
#define QSPI_XIP_CMD_W1_XIPW_DUM2_6         (0x40U << QSPI_XIP_CMD_W1_XIPW_DUM2_Pos) /*!< 0x00000040 */
#define QSPI_XIP_CMD_W1_XIPW_DUM2_7         (0x80U << QSPI_XIP_CMD_W1_XIPW_DUM2_Pos) /*!< 0x00000080 */

/*!< XIPW_OPMODE congiguration */
#define QSPI_XIP_CMD_W1_XIPW_OPMODE_Pos     (8U)                                      /*!< 0x00000700 */
#define QSPI_XIP_CMD_W1_XIPW_OPMODE_Msk     (0x7U << QSPI_XIP_CMD_W1_XIPW_OPMODE_Pos)
#define QSPI_XIP_CMD_W1_XIPW_OPMODE         QSPI_XIP_CMD_W1_XIPW_OPMODE_Msk           /*!< XIPW_OPMODE[2:0] bits (XIP write operation mode) */
#define QSPI_XIP_CMD_W1_XIPW_OPMODE_0       (0x1U << QSPI_XIP_CMD_W1_XIPW_OPMODE_Pos) /*!< 0x00000100 */
#define QSPI_XIP_CMD_W1_XIPW_OPMODE_1       (0x2U << QSPI_XIP_CMD_W1_XIPW_OPMODE_Pos) /*!< 0x00000200 */
#define QSPI_XIP_CMD_W1_XIPW_OPMODE_2       (0x4U << QSPI_XIP_CMD_W1_XIPW_OPMODE_Pos) /*!< 0x00000400 */

#define QSPI_XIP_CMD_W1_XIPW_OPMODE_SERIAL  0x00000000U                             /*!< Serial mode (1-1-1) */
#define QSPI_XIP_CMD_W1_XIPW_OPMODE_DUAL    0x00000100U                             /*!< Dual-wire mode (1-1-2) */
#define QSPI_XIP_CMD_W1_XIPW_OPMODE_QUAD    0x00000200U                             /*!< Quad mode (1-1-4) */
#define QSPI_XIP_CMD_W1_XIPW_OPMODE_DUALIO  0x00000300U                             /*!< Dual-wire I/O mode (1-2-2) */
#define QSPI_XIP_CMD_W1_XIPW_OPMODE_QUADIO  0x00000400U                             /*!< Quad I/O mode (1-4-4) */
#define QSPI_XIP_CMD_W1_XIPW_OPMODE_DPI     0x00000500U                             /*!< DPI mode (2-2-2) */
#define QSPI_XIP_CMD_W1_XIPW_OPMODE_QPI     0x00000600U                             /*!< QPI mode (4-4-4) */

#define QSPI_XIP_CMD_W1_XIPW_ADRLEN_Pos     (11U)                                   /*!< 0x00000800 */
#define QSPI_XIP_CMD_W1_XIPW_ADRLEN_Msk     (0x1U << QSPI_XIP_CMD_W1_XIPW_ADRLEN_Pos)
#define QSPI_XIP_CMD_W1_XIPW_ADRLEN         QSPI_XIP_CMD_W1_XIPW_ADRLEN_Msk         /*!< XIP write address length */
#define QSPI_XIP_CMD_W1_XIPW_INSC_Pos       (12U)                                   /*!< 0x000FF000 */
#define QSPI_XIP_CMD_W1_XIPW_INSC_Msk       (0xFFU << QSPI_XIP_CMD_W1_XIPW_INSC_Pos)
#define QSPI_XIP_CMD_W1_XIPW_INSC           QSPI_XIP_CMD_W1_XIPW_INSC_Msk           /*!< XIP write instruction code */

/***************  Bit definition for QSPI_XIP_CMD_W2 register  ****************/
#define QSPI_XIP_CMD_W2_XIPR_DCNT_Pos       (0U)                                    /*!< 0x0000003F */
#define QSPI_XIP_CMD_W2_XIPR_DCNT_Msk       (0x3FU << QSPI_XIP_CMD_W2_XIPR_DCNT_Pos)
#define QSPI_XIP_CMD_W2_XIPR_DCNT           QSPI_XIP_CMD_W2_XIPR_DCNT_Msk           /*!< Indicates the time counter to judge maximum data count in mode D */
#define QSPI_XIP_CMD_W2_XIPR_TCNT_Pos       (8U)                                    /*!< 0x00007F00 */
#define QSPI_XIP_CMD_W2_XIPR_TCNT_Msk       (0x7FU << QSPI_XIP_CMD_W2_XIPR_TCNT_Pos)
#define QSPI_XIP_CMD_W2_XIPR_TCNT           QSPI_XIP_CMD_W2_XIPR_TCNT_Msk           /*!< Indicates the time counter to judge time interval in mode T */
#define QSPI_XIP_CMD_W2_XIPR_SEL_Pos        (15U)
#define QSPI_XIP_CMD_W2_XIPR_SEL_Msk        (0x1U << QSPI_XIP_CMD_W2_XIPR_SEL_Pos)  /*!< 0x00008000 */
#define QSPI_XIP_CMD_W2_XIPR_SEL            QSPI_XIP_CMD_W2_XIPR_SEL_Msk            /*!< XIP read mode select */
#define QSPI_XIP_CMD_W2_XIPW_DCNT_Pos       (16U)                                   /*!< 0x003F0000 */
#define QSPI_XIP_CMD_W2_XIPW_DCNT_Msk       (0x3FU << QSPI_XIP_CMD_W2_XIPW_DCNT_Pos)
#define QSPI_XIP_CMD_W2_XIPW_DCNT           QSPI_XIP_CMD_W2_XIPW_DCNT_Msk           /*!< Indicates the time counter to judge maximum data count in mode D */
#define QSPI_XIP_CMD_W2_XIPW_TCNT_Pos       (24U)                                   /*!< 0x7F000000 */
#define QSPI_XIP_CMD_W2_XIPW_TCNT_Msk       (0x7FU << QSPI_XIP_CMD_W2_XIPW_TCNT_Pos)
#define QSPI_XIP_CMD_W2_XIPW_TCNT           QSPI_XIP_CMD_W2_XIPW_TCNT_Msk           /*!< Indicates the time counter to judge time interval in mode T */
#define QSPI_XIP_CMD_W2_XIPW_SEL_Pos        (31U)
#define QSPI_XIP_CMD_W2_XIPW_SEL_Msk        (0x1U << QSPI_XIP_CMD_W2_XIPW_SEL_Pos)  /*!< 0x80000000 */
#define QSPI_XIP_CMD_W2_XIPW_SEL            QSPI_XIP_CMD_W2_XIPW_SEL_Msk            /*!< XIP write mode select */

/***************  Bit definition for QSPI_XIP_CMD_W3 register  ****************/
#define QSPI_XIP_CMD_W3_BYPASSC_Pos         (0U)
#define QSPI_XIP_CMD_W3_BYPASSC_Msk         (0x1U << QSPI_XIP_CMD_W3_BYPASSC_Pos)   /*!< 0x00000001 */
#define QSPI_XIP_CMD_W3_BYPASSC             QSPI_XIP_CMD_W3_BYPASSC_Msk             /*!< Bypass cache function */
#define QSPI_XIP_CMD_W3_CSTS_Pos            (3U)
#define QSPI_XIP_CMD_W3_CSTS_Msk            (0x1U << QSPI_XIP_CMD_W3_CSTS_Pos)      /*!< 0x00000008 */
#define QSPI_XIP_CMD_W3_CSTS                QSPI_XIP_CMD_W3_CSTS_Msk                /*!< Cache status */

/******************  Bit definition for QSPI_CTRL3 register  ******************/
#define QSPI_CTRL3_ISPC_Pos                 (8U)
#define QSPI_CTRL3_ISPC_Msk                 (0x1U << QSPI_CTRL3_ISPC_Pos)           /*!< 0x00000100 */
#define QSPI_CTRL3_ISPC                     QSPI_CTRL3_ISPC_Msk                     /*!< ISPC */

/*******************  Bit definition for QSPI_REV register  *******************/
#define QSPI_REV_REV_Pos                    (0U)
#define QSPI_REV_REV_Msk                    (0xFFFFFFFFU << QSPI_REV_REV_Pos)       /*!< 0xFFFFFFFF */
#define QSPI_REV_REV                        QSPI_REV_REV_Msk                        /*!< Indicates IP version */

/*******************  Bit definition for QSPI_DT register  ********************/
#define QSPI_DT_DT_Pos                      (0U)
#define QSPI_DT_DT_Msk                      (0xFFFFFFFFU << QSPI_DT_DT_Pos)         /*!< 0xFFFFFFFF */
#define QSPI_DT_DT                          QSPI_DT_DT_Msk                          /*!< Data port register */

/******************************************************************************/
/*                                                                            */
/*                         SDIO interface(SDIO)                               */
/*                                                                            */
/******************************************************************************/
/*****************  Bit definition for SDIO_PWRCTRL register  *****************/
/*!< PS congiguration */
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

/*!< BUSWS congiguration */
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

/*!< RSPWT congiguration */
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

/*!< BLKSIZE congiguration */
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
/*                             Debug MCU (DEBUG)                              */
/*                                                                            */
/******************************************************************************/

/*****************  Bit definition for DEBUG_IDCODE register  *****************/
/*!< PID congiguration */
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

/***************  Bit definition for DEBUG_APB1_PAUSE register  ***************/
#define DEBUG_APB1_PAUSE_TMR2_PAUSE_Pos     (0U)                                    /*!< 0x00000001 */
#define DEBUG_APB1_PAUSE_TMR2_PAUSE_Msk     (0x1U << DEBUG_APB1_PAUSE_TMR2_PAUSE_Pos)
#define DEBUG_APB1_PAUSE_TMR2_PAUSE         DEBUG_APB1_PAUSE_TMR2_PAUSE_Msk         /*!< TMR2 pause control bit */
#define DEBUG_APB1_PAUSE_TMR3_PAUSE_Pos     (1U)                                    /*!< 0x00000002 */
#define DEBUG_APB1_PAUSE_TMR3_PAUSE_Msk     (0x1U << DEBUG_APB1_PAUSE_TMR3_PAUSE_Pos)
#define DEBUG_APB1_PAUSE_TMR3_PAUSE         DEBUG_APB1_PAUSE_TMR3_PAUSE_Msk         /*!< TMR3 pause control bit */
#define DEBUG_APB1_PAUSE_TMR4_PAUSE_Pos     (2U)                                    /*!< 0x00000004 */
#define DEBUG_APB1_PAUSE_TMR4_PAUSE_Msk     (0x1U << DEBUG_APB1_PAUSE_TMR4_PAUSE_Pos)
#define DEBUG_APB1_PAUSE_TMR4_PAUSE         DEBUG_APB1_PAUSE_TMR4_PAUSE_Msk         /*!< TMR4 pause control bit */
#define DEBUG_APB1_PAUSE_TMR5_PAUSE_Pos     (3U)                                    /*!< 0x00000008 */
#define DEBUG_APB1_PAUSE_TMR5_PAUSE_Msk     (0x1U << DEBUG_APB1_PAUSE_TMR5_PAUSE_Pos)
#define DEBUG_APB1_PAUSE_TMR5_PAUSE         DEBUG_APB1_PAUSE_TMR5_PAUSE_Msk         /*!< TMR5 pause control bit */
#define DEBUG_APB1_PAUSE_TMR6_PAUSE_Pos     (4U)                                    /*!< 0x00000010 */
#define DEBUG_APB1_PAUSE_TMR6_PAUSE_Msk     (0x1U << DEBUG_APB1_PAUSE_TMR6_PAUSE_Pos)
#define DEBUG_APB1_PAUSE_TMR6_PAUSE         DEBUG_APB1_PAUSE_TMR6_PAUSE_Msk         /*!< TMR6 pause control bit */
#define DEBUG_APB1_PAUSE_TMR7_PAUSE_Pos     (5U)                                    /*!< 0x00000020 */
#define DEBUG_APB1_PAUSE_TMR7_PAUSE_Msk     (0x1U << DEBUG_APB1_PAUSE_TMR7_PAUSE_Pos)
#define DEBUG_APB1_PAUSE_TMR7_PAUSE         DEBUG_APB1_PAUSE_TMR7_PAUSE_Msk         /*!< TMR7 pause control bit */
#define DEBUG_APB1_PAUSE_TMR12_PAUSE_Pos    (6U)                                    /*!< 0x00000040 */
#define DEBUG_APB1_PAUSE_TMR12_PAUSE_Msk    (0x1U << DEBUG_APB1_PAUSE_TMR12_PAUSE_Pos)
#define DEBUG_APB1_PAUSE_TMR12_PAUSE        DEBUG_APB1_PAUSE_TMR12_PAUSE_Msk        /*!< TMR12 pause control bit */
#define DEBUG_APB1_PAUSE_TMR13_PAUSE_Pos    (7U)                                    /*!< 0x00000080 */
#define DEBUG_APB1_PAUSE_TMR13_PAUSE_Msk    (0x1U << DEBUG_APB1_PAUSE_TMR13_PAUSE_Pos)
#define DEBUG_APB1_PAUSE_TMR13_PAUSE        DEBUG_APB1_PAUSE_TMR13_PAUSE_Msk        /*!< TMR13 pause control bit */
#define DEBUG_APB1_PAUSE_TMR14_PAUSE_Pos    (8U)                                    /*!< 0x00000100 */
#define DEBUG_APB1_PAUSE_TMR14_PAUSE_Msk    (0x1U << DEBUG_APB1_PAUSE_TMR14_PAUSE_Pos)
#define DEBUG_APB1_PAUSE_TMR14_PAUSE        DEBUG_APB1_PAUSE_TMR14_PAUSE_Msk        /*!< TMR14 pause control bit */
#define DEBUG_APB1_PAUSE_ERTC_PAUSE_Pos     (10U)                                   /*!< 0x00000400 */
#define DEBUG_APB1_PAUSE_ERTC_PAUSE_Msk     (0x1U << DEBUG_APB1_PAUSE_ERTC_PAUSE_Pos)
#define DEBUG_APB1_PAUSE_ERTC_PAUSE         DEBUG_APB1_PAUSE_ERTC_PAUSE_Msk         /*!< ERTC pause control bit */
#define DEBUG_APB1_PAUSE_WWDT_PAUSE_Pos     (11U)                                   /*!< 0x00000800 */
#define DEBUG_APB1_PAUSE_WWDT_PAUSE_Msk     (0x1U << DEBUG_APB1_PAUSE_WWDT_PAUSE_Pos)
#define DEBUG_APB1_PAUSE_WWDT_PAUSE         DEBUG_APB1_PAUSE_WWDT_PAUSE_Msk         /*!< Window watchdog pause control bit */
#define DEBUG_APB1_PAUSE_WDT_PAUSE_Pos      (12U)                                   /*!< 0x00001000 */
#define DEBUG_APB1_PAUSE_WDT_PAUSE_Msk      (0x1U << DEBUG_APB1_PAUSE_WDT_PAUSE_Pos)
#define DEBUG_APB1_PAUSE_WDT_PAUSE          DEBUG_APB1_PAUSE_WDT_PAUSE_Msk          /*!< Watchdog pause control bit */
#define DEBUG_APB1_PAUSE_I2C1_SMBUS_TIMEOUT_Pos (24U)                               /*!< 0x01000000 */
#define DEBUG_APB1_PAUSE_I2C1_SMBUS_TIMEOUT_Msk (0x1U << DEBUG_APB1_PAUSE_I2C1_SMBUS_TIMEOUT_Pos)
#define DEBUG_APB1_PAUSE_I2C1_SMBUS_TIMEOUT     DEBUG_APB1_PAUSE_I2C1_SMBUS_TIMEOUT_Msk /*!< I2C1 pause control bit */
#define DEBUG_APB1_PAUSE_CAN1_PAUSE_Pos     (25U)                                   /*!< 0x02000000 */
#define DEBUG_APB1_PAUSE_CAN1_PAUSE_Msk     (0x1U << DEBUG_APB1_PAUSE_CAN1_PAUSE_Pos)
#define DEBUG_APB1_PAUSE_CAN1_PAUSE         DEBUG_APB1_PAUSE_CAN1_PAUSE_Msk         /*!< CAN1 pause control bit */
#define DEBUG_APB1_PAUSE_CAN2_PAUSE_Pos     (26U)                                   /*!< 0x04000000 */
#define DEBUG_APB1_PAUSE_CAN2_PAUSE_Msk     (0x1U << DEBUG_APB1_PAUSE_CAN2_PAUSE_Pos)
#define DEBUG_APB1_PAUSE_CAN2_PAUSE         DEBUG_APB1_PAUSE_CAN2_PAUSE_Msk         /*!< CAN2 pause control bit */
#define DEBUG_APB1_PAUSE_I2C2_SMBUS_TIMEOUT_Pos (27U)                               /*!< 0x08000000 */
#define DEBUG_APB1_PAUSE_I2C2_SMBUS_TIMEOUT_Msk (0x1U << DEBUG_APB1_PAUSE_I2C2_SMBUS_TIMEOUT_Pos)
#define DEBUG_APB1_PAUSE_I2C2_SMBUS_TIMEOUT     DEBUG_APB1_PAUSE_I2C2_SMBUS_TIMEOUT_Msk /*!< I2C2 pause control bit */
#define DEBUG_APB1_PAUSE_I2C3_SMBUS_TIMEOUT_Pos (28U)                               /*!< 0x10000000 */
#define DEBUG_APB1_PAUSE_I2C3_SMBUS_TIMEOUT_Msk (0x1U << DEBUG_APB1_PAUSE_I2C3_SMBUS_TIMEOUT_Pos)
#define DEBUG_APB1_PAUSE_I2C3_SMBUS_TIMEOUT     DEBUG_APB1_PAUSE_I2C3_SMBUS_TIMEOUT_Msk /*!< I2C3 pause control bit */

/***************  Bit definition for DEBUG_APB2_PAUSE register  ***************/
#define DEBUG_APB2_PAUSE_TMR1_PAUSE_Pos     (0U)                                    /*!< 0x00000001 */
#define DEBUG_APB2_PAUSE_TMR1_PAUSE_Msk     (0x1U << DEBUG_APB2_PAUSE_TMR1_PAUSE_Pos)
#define DEBUG_APB2_PAUSE_TMR1_PAUSE         DEBUG_APB2_PAUSE_TMR1_PAUSE_Msk         /*!< TMR1 pause control bit */
#define DEBUG_APB2_PAUSE_TMR8_PAUSE_Pos     (1U)                                    /*!< 0x00000002 */
#define DEBUG_APB2_PAUSE_TMR8_PAUSE_Msk     (0x1U << DEBUG_APB2_PAUSE_TMR8_PAUSE_Pos)
#define DEBUG_APB2_PAUSE_TMR8_PAUSE         DEBUG_APB2_PAUSE_TMR8_PAUSE_Msk         /*!< TMR8 pause control bit */
#define DEBUG_APB2_PAUSE_TMR20_PAUSE_Pos    (1U)                                    /*!< 0x00000002 */
#define DEBUG_APB2_PAUSE_TMR20_PAUSE_Msk    (0x1U << DEBUG_APB2_PAUSE_TMR20_PAUSE_Pos)
#define DEBUG_APB2_PAUSE_TMR20_PAUSE        DEBUG_APB2_PAUSE_TMR20_PAUSE_Msk        /*!< TMR8 pause control bit */
#define DEBUG_APB2_PAUSE_TMR9_PAUSE_Pos     (16U)                                   /*!< 0x00010000 */
#define DEBUG_APB2_PAUSE_TMR9_PAUSE_Msk     (0x1U << DEBUG_APB2_PAUSE_TMR9_PAUSE_Pos)
#define DEBUG_APB2_PAUSE_TMR9_PAUSE         DEBUG_APB2_PAUSE_TMR9_PAUSE_Msk         /*!< TMR9 pause control bit */
#define DEBUG_APB2_PAUSE_TMR10_PAUSE_Pos    (17U)                                   /*!< 0x00020000 */
#define DEBUG_APB2_PAUSE_TMR10_PAUSE_Msk    (0x1U << DEBUG_APB2_PAUSE_TMR10_PAUSE_Pos)
#define DEBUG_APB2_PAUSE_TMR10_PAUSE        DEBUG_APB2_PAUSE_TMR10_PAUSE_Msk        /*!< TMR10 pause control bit */
#define DEBUG_APB2_PAUSE_TMR11_PAUSE_Pos    (18U)                                   /*!< 0x00040000 */
#define DEBUG_APB2_PAUSE_TMR11_PAUSE_Msk    (0x1U << DEBUG_APB2_PAUSE_TMR11_PAUSE_Pos)
#define DEBUG_APB2_PAUSE_TMR11_PAUSE        DEBUG_APB2_PAUSE_TMR11_PAUSE_Msk        /*!< TMR11 pause control bit */

/*****************  Bit definition for DEBUG_SER_ID register  *****************/
/*!< REV_ID congiguration */
#define DEBUG_SER_ID_REV_ID_Pos             (0U)
#define DEBUG_SER_ID_REV_ID_Msk             (0x7U << DEBUG_SER_ID_REV_ID_Pos)       /*!< 0x00000007 */
#define DEBUG_SER_ID_REV_ID                 DEBUG_SER_ID_REV_ID_Msk                 /*!< REV_ID[2:0] bits (Revision ID) */
#define DEBUG_SER_ID_REV_ID_0               (0x1U << DEBUG_SER_ID_REV_ID_Pos)       /*!< 0x00000001 */
#define DEBUG_SER_ID_REV_ID_1               (0x2U << DEBUG_SER_ID_REV_ID_Pos)       /*!< 0x00000002 */
#define DEBUG_SER_ID_REV_ID_2               (0x4U << DEBUG_SER_ID_REV_ID_Pos)       /*!< 0x00000004 */

/*!< SER_ID congiguration */
#define DEBUG_SER_ID_SER_ID_Pos             (8U)
#define DEBUG_SER_ID_SER_ID_Msk             (0xFFU << DEBUG_SER_ID_SER_ID_Pos)      /*!< 0x0000FF00 */
#define DEBUG_SER_ID_SER_ID                 DEBUG_SER_ID_SER_ID_Msk                 /*!< SER_ID[7:0] bits (Serial ID) */
#define DEBUG_SER_ID_SER_ID_0               (0x01U << DEBUG_SER_ID_SER_ID_Pos)      /*!< 0x00000100 */
#define DEBUG_SER_ID_SER_ID_1               (0x02U << DEBUG_SER_ID_SER_ID_Pos)      /*!< 0x00000200 */
#define DEBUG_SER_ID_SER_ID_2               (0x04U << DEBUG_SER_ID_SER_ID_Pos)      /*!< 0x00000400 */
#define DEBUG_SER_ID_SER_ID_3               (0x08U << DEBUG_SER_ID_SER_ID_Pos)      /*!< 0x00000800 */
#define DEBUG_SER_ID_SER_ID_4               (0x10U << DEBUG_SER_ID_SER_ID_Pos)      /*!< 0x00001000 */
#define DEBUG_SER_ID_SER_ID_5               (0x20U << DEBUG_SER_ID_SER_ID_Pos)      /*!< 0x00002000 */
#define DEBUG_SER_ID_SER_ID_6               (0x40U << DEBUG_SER_ID_SER_ID_Pos)      /*!< 0x00004000 */
#define DEBUG_SER_ID_SER_ID_7               (0x80U << DEBUG_SER_ID_SER_ID_Pos)      /*!< 0x00008000 */

/**
  * @}
  */

/**
  * @}
*/

/** @addtogroup Exported_macro
  * @{
  */

  #define CRM_HEXT_MIN       4000000U
  #define CRM_HEXT_MAX       25000000U
  
  #define CRM_MAX_FREQUENCY  288000000U
  
  /**
    * @}
    */
  
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __AT32F435_437Rx_H */
