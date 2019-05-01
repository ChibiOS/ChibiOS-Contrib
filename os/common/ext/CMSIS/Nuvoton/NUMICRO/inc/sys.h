/**************************************************************************//**
 * @file     sys.h
 * @version  V3.00
 * $Revision: 41 $
 * $Date: 15/07/02 11:21a $
 * @brief    NUC123 Series SYS Driver Header File
 *
 * @note
 * Copyright (C) 2014~2015 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __SYS_H__
#define __SYS_H__

#ifdef __cplusplus
extern "C"
{
#endif

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup SYS_Driver SYS Driver
  @{
*/

/** @addtogroup SYS_EXPORTED_CONSTANTS SYS Exported Constants
  @{
*/


/*---------------------------------------------------------------------------------------------------------*/
/*  Module Reset Control Resister constant definitions.                                                    */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_RST    ((0x0<<24) | SYS_IPRSTC1_PDMA_RST_Pos  ) /*!< PDMA reset is one of the SYS_ResetModule parameter */
#define GPIO_RST    ((0x4<<24) | SYS_IPRSTC2_GPIO_RST_Pos  ) /*!< GPIO reset is one of the SYS_ResetModule parameter */
#define TMR0_RST    ((0x4<<24) | SYS_IPRSTC2_TMR0_RST_Pos  ) /*!< TMR0 reset is one of the SYS_ResetModule parameter */
#define TMR1_RST    ((0x4<<24) | SYS_IPRSTC2_TMR1_RST_Pos  ) /*!< TMR1 reset is one of the SYS_ResetModule parameter */
#define TMR2_RST    ((0x4<<24) | SYS_IPRSTC2_TMR2_RST_Pos  ) /*!< TMR2 reset is one of the SYS_ResetModule parameter */
#define TMR3_RST    ((0x4<<24) | SYS_IPRSTC2_TMR3_RST_Pos  ) /*!< TMR3 reset is one of the SYS_ResetModule parameter */
#define I2C0_RST    ((0x4<<24) | SYS_IPRSTC2_I2C0_RST_Pos  ) /*!< I2C0 reset is one of the SYS_ResetModule parameter */
#define I2C1_RST    ((0x4<<24) | SYS_IPRSTC2_I2C1_RST_Pos  ) /*!< I2C1 reset is one of the SYS_ResetModule parameter */
#define SPI0_RST    ((0x4<<24) | SYS_IPRSTC2_SPI0_RST_Pos  ) /*!< SPI0 reset is one of the SYS_ResetModule parameter */
#define SPI1_RST    ((0x4<<24) | SYS_IPRSTC2_SPI1_RST_Pos  ) /*!< SPI1 reset is one of the SYS_ResetModule parameter */
#define SPI2_RST    ((0x4<<24) | SYS_IPRSTC2_SPI2_RST_Pos  ) /*!< SPI2 reset is one of the SYS_ResetModule parameter */
#define UART0_RST   ((0x4<<24) | SYS_IPRSTC2_UART0_RST_Pos ) /*!< UART0 reset is one of the SYS_ResetModule parameter */
#define UART1_RST   ((0x4<<24) | SYS_IPRSTC2_UART1_RST_Pos ) /*!< UART1 reset is one of the SYS_ResetModule parameter */
#define PWM03_RST   ((0x4<<24) | SYS_IPRSTC2_PWM03_RST_Pos ) /*!< PWM03 reset is one of the SYS_ResetModule parameter */
#define PS2_RST     ((0x4<<24) | SYS_IPRSTC2_PS2_RST_Pos   ) /*!< PS2 reset is one of the SYS_ResetModule parameter */
#define USBD_RST    ((0x4<<24) | SYS_IPRSTC2_USBD_RST_Pos  ) /*!< USBD reset is one of the SYS_ResetModule parameter */
#define ADC_RST     ((0x4<<24) | SYS_IPRSTC2_ADC_RST_Pos   ) /*!< ADC reset is one of the SYS_ResetModule parameter */
#define I2S_RST     ((0x4<<24) | SYS_IPRSTC2_I2S_RST_Pos   ) /*!< I2S reset is one of the SYS_ResetModule parameter */


/*---------------------------------------------------------------------------------------------------------*/
/*  Brown Out Detector Threshold Voltage Selection constant definitions.                                   */
/*---------------------------------------------------------------------------------------------------------*/
#define SYS_BODCR_BOD_RST_EN            (1UL<<SYS_BODCR_BOD_RSTEN_Pos)    /*!< Brown-out Reset Enable */
#define SYS_BODCR_BOD_INTERRUPT_EN      (0UL<<SYS_BODCR_BOD_RSTEN_Pos)    /*!< Brown-out Interrupt Enable */
#define SYS_BODCR_BOD_VL_4_5V           (3UL<<SYS_BODCR_BOD_VL_Pos)       /*!< Setting Brown Out Detector Threshold Voltage as 4.5V */
#define SYS_BODCR_BOD_VL_3_8V           (2UL<<SYS_BODCR_BOD_VL_Pos)       /*!< Setting Brown Out Detector Threshold Voltage as 3.8V */
#define SYS_BODCR_BOD_VL_2_7V           (1UL<<SYS_BODCR_BOD_VL_Pos)       /*!< Setting Brown Out Detector Threshold Voltage as 2.7V */
#define SYS_BODCR_BOD_VL_2_2V           (0UL<<SYS_BODCR_BOD_VL_Pos)       /*!< Setting Brown Out Detector Threshold Voltage as 2.2V */


/*---------------------------------------------------------------------------------------------------------*/
/*  Multi-Function constant definitions.                                                                   */
/*---------------------------------------------------------------------------------------------------------*/

/* How to use below #define?
Example: If user want to set PA.10 as I2C1_SDA and PA.11 as I2C1_SCL in initial function,
         user can issue following command to achieve it.

         SYS->GPA_MFP &= ~(SYS_GPA_MFP_PA10_Msk | SYS_GPA_MFP_PA11_Msk);
         SYS->ALT_MFP &= ~(SYS_ALT_MFP_PA10_Msk | SYS_ALT_MFP_PA11_Msk);

         SYS->GPA_MFP |= (SYS_GPA_MFP_PA10_I2C1_SDA | SYS_GPA_MFP_PA11_I2C1_SCL);
         SYS->ALT_MFP |= (SYS_ALT_MFP_PA10_I2C1_SDA | SYS_ALT_MFP_PA11_I2C1_SCL);
*/

//PA.10
#define SYS_GPA_MFP_PA10_GPIO           0x00000000UL    /*!< GPA_MFP PA.10 setting for GPIO */
#define SYS_ALT_MFP_PA10_GPIO           0x00000000UL    /*!< ALT_MFP PA.10 setting for GPIO */
#define SYS_ALT_MFP1_PA10_GPIO          NULL            /*!< No ALT_MFP1 setting for PA.10 */

#define SYS_GPA_MFP_PA10_I2C1_SDA       (1UL<<10)       /*!< GPA_MFP PA.10 setting for I2C1_SDA */
#define SYS_ALT_MFP_PA10_I2C1_SDA       0x00000000UL    /*!< ALT_MFP PA.10 setting for I2C1_SDA */
#define SYS_ALT_MFP1_PA10_I2C1_SDA      NULL            /*!< No ALT_MFP1 setting for PA.10 */

#define SYS_GPA_MFP_PA10_SPI1_MISO0     0x00000000UL    /*!< GPA_MFP PA.10 setting for SPI1_MISO0 */
#define SYS_ALT_MFP_PA10_SPI1_MISO0     (1UL<<12)       /*!< ALT_MFP PA.10 setting for SPI1_MISO0 */
#define SYS_ALT_MFP1_PA10_SPI1_MISO0    NULL            /*!< No ALT_MFP1 setting for PA.10 */

#define SYS_GPA_MFP_PA10_SPI2_MISO0     (1UL<<10)       /*!< GPA_MFP PA.10 setting for SPI2_MISO0 */
#define SYS_ALT_MFP_PA10_SPI2_MISO0     (1UL<<12)       /*!< ALT_MFP PA.10 setting for SPI2_MISO0 */
#define SYS_ALT_MFP1_PA10_SPI2_MISO0    NULL            /*!< No ALT_MFP1 setting for PA.10 */

#define SYS_GPA_MFP_PA10_Msk            (1UL<<10)       /*!< GPA_MFP PA.10 mask */
#define SYS_ALT_MFP_PA10_Msk            (1UL<<12)       /*!< ALT_MFP PA.10 mask */
#define SYS_ALT_MFP1_PA10_Msk           NULL            /*!< No ALT_MFP1 PA.10 mask */

//PA.11
#define SYS_GPA_MFP_PA11_GPIO           0x00000000UL    /*!< GPA_MFP PA.11 setting for GPIO */
#define SYS_ALT_MFP_PA11_GPIO           0x00000000UL    /*!< ALT_MFP PA.11 setting for GPIO */
#define SYS_ALT_MFP1_PA11_GPIO          NULL            /*!< No ALT_MFP1 setting for PA.11 */

#define SYS_GPA_MFP_PA11_I2C1_SCL       (1UL<<11)       /*!< GPA_MFP PA.11 setting for I2C1_SCL */
#define SYS_ALT_MFP_PA11_I2C1_SCL       0x00000000UL    /*!< ALT_MFP PA.11 setting for I2C1_SCL */
#define SYS_ALT_MFP1_PA11_I2C1_SCL      NULL            /*!< No ALT_MFP1 setting for PA.11 */

#define SYS_GPA_MFP_PA11_SPI1_CLK       0x00000000UL    /*!< GPA_MFP PA.11 setting for SPI1_CLK */
#define SYS_ALT_MFP_PA11_SPI1_CLK       (1UL<<11)       /*!< ALT_MFP PA.11 setting for SPI1_CLK */
#define SYS_ALT_MFP1_PA11_SPI1_CLK      NULL            /*!< No ALT_MFP1 setting for PA.11 */

#define SYS_GPA_MFP_PA11_SPI2_MOSI0     (1UL<<11)       /*!< GPA_MFP PA.11 setting for MOSI20 */
#define SYS_ALT_MFP_PA11_SPI2_MOSI0     (1UL<<11)       /*!< ALT_MFP PA.11 setting for MOSI20 */
#define SYS_ALT_MFP1_PA11_SPI2_MOSI0    NULL            /*!< No ALT_MFP1 setting for PA.11 */

#define SYS_GPA_MFP_PA11_Msk            (1UL<<11)       /*!< GPA_MFP PA.11 mask */
#define SYS_ALT_MFP_PA11_Msk            (1UL<<11)       /*!< ALT_MFP PA.11 mask */
#define SYS_ALT_MFP1_PA11_Msk           NULL            /*!< No ALT_MFP1 PA.11 mask */

//PA.12
#define SYS_GPA_MFP_PA12_GPIO           0x00000000UL    /*!< GPA_MFP PA.12 setting for GPIO */
#define SYS_ALT_MFP_PA12_GPIO           NULL            /*!< No ALT_MFP setting for PA.12 */
#define SYS_ALT_MFP1_PA12_GPIO          NULL            /*!< No ALT_MFP1 setting for PA.12 */

#define SYS_GPA_MFP_PA12_PWM0           (1UL<<12)       /*!< GPA_MFP PA.12 setting for PWM0 */
#define SYS_ALT_MFP_PA12_PWM0           NULL            /*!< No ALT_MFP setting for PA.12 */
#define SYS_ALT_MFP1_PA12_PWM0          NULL            /*!< No ALT_MFP1 setting for PA.12 */

#define SYS_GPA_MFP_PA12_Msk            (1UL<<12)       /*!< GPA_MFP PA.12 mask */
#define SYS_ALT_MFP_PA12_Msk            NULL            /*!< No ALT_MFP PA.12 mask */
#define SYS_ALT_MFP1_PA12_Msk           NULL            /*!< No ALT_MFP1 PA.12 mask */

//PA.13
#define SYS_GPA_MFP_PA13_GPIO           0x00000000UL    /*!< GPA_MFP PA.13 setting for GPIO */
#define SYS_ALT_MFP_PA13_GPIO           NULL            /*!< no ALT_MFP setting for PA.13 */
#define SYS_ALT_MFP1_PA13_GPIO          NULL            /*!< No ALT_MFP1 setting for PA.13 */

#define SYS_GPA_MFP_PA13_PWM1           (1UL<<13)       /*!< GPA_MFP PA.13 setting for PWM1 */
#define SYS_ALT_MFP_PA13_PWM1           NULL            /*!< no ALT_MFP setting for PA.13 */
#define SYS_ALT_MFP1_PA13_PWM1          NULL            /*!< No ALT_MFP1 setting for PA.13 */

#define SYS_GPA_MFP_PA13_Msk            (1UL<<13)       /*!< GPA_MFP PA.13 mask */
#define SYS_ALT_MFP_PA13_Msk            NULL            /*!< no ALT_MFP PA.13 mask */
#define SYS_ALT_MFP1_PA13_Msk           NULL            /*!< No ALT_MFP1 PA.13 mask */

//PA.14
#define SYS_GPA_MFP_PA14_GPIO           0x00000000UL    /*!< GPA_MFP PA.14 setting for GPIO */
#define SYS_ALT_MFP_PA14_GPIO           NULL            /*!< No ALT_MFP setting for PA.14 */
#define SYS_ALT_MFP1_PA14_GPIO          NULL            /*!< No ALT_MFP1 setting for PA.14 */

#define SYS_GPA_MFP_PA14_PWM2           (1UL<<14)       /*!< GPA_MFP PA.14 setting for PWM2 */
#define SYS_ALT_MFP_PA14_PWM2           NULL            /*!< No ALT_MFP setting for PA.14 */
#define SYS_ALT_MFP1_PA14_PWM2          NULL            /*!< No ALT_MFP1 setting for PA.14 */

#define SYS_GPA_MFP_PA14_Msk            (1UL<<14)       /*!< GPA_MFP PA.14 mask */
#define SYS_ALT_MFP_PA14_Msk            NULL            /*!< No ALT_MFP PA.14 mask */
#define SYS_ALT_MFP1_PA14_Msk           NULL            /*!< No ALT_MFP1 PA.14 mask */

//PA.15
#define SYS_GPA_MFP_PA15_GPIO           0x00000000UL    /*!< GPA_MFP PA.15 setting for GPIO */
#define SYS_ALT_MFP_PA15_GPIO           0x00000000UL    /*!< ALT_MFP PA.15 setting for GPIO */
#define SYS_ALT_MFP1_PA15_GPIO          NULL            /*!< No ALT_MFP1 setting for PA.15 */

#define SYS_GPA_MFP_PA15_PWM3           (1UL<<15)       /*!< GPA_MFP PA.15 setting for PWM3 */
#define SYS_ALT_MFP_PA15_PWM3           0x00000000UL    /*!< ALT_MFP PA.15 setting for PWM3 */
#define SYS_ALT_MFP1_PA15_PWM3          NULL            /*!< No ALT_MFP1 setting for PA.15 */

#define SYS_GPA_MFP_PA15_CLKO           0x00000000UL    /*!< GPA_MFP PA.15 setting for CLKO */
#define SYS_ALT_MFP_PA15_CLKO           (1UL<<9)        /*!< ALT_MFP PA.15 setting for CLKO */
#define SYS_ALT_MFP1_PA15_CLKO          NULL            /*!< No ALT_MFP1 setting for PA.15 */

#define SYS_GPA_MFP_PA15_I2S_MCLK       (1UL<<15)       /*!< GPA_MFP PA.15 setting for I2S_MCLK */
#define SYS_ALT_MFP_PA15_I2S_MCLK       (1UL<<9)        /*!< ALT_MFP PA.15 setting for I2S_MCLK */
#define SYS_ALT_MFP1_PA15_I2S_MCLK      NULL            /*!< No ALT_MFP1 setting for PA.15 */

#define SYS_GPA_MFP_PA15_Msk            (1UL<<15)       /*!< GPA_MFP PA.15 mask */
#define SYS_ALT_MFP_PA15_Msk            (1UL<<9)        /*!< ALT_MFP PA.15 mask */
#define SYS_ALT_MFP1_PA15_Msk           NULL            /*!< No ALT_MFP1 PA.15 mask */

//PB.0
#define SYS_GPB_MFP_PB0_GPIO            0x00000000UL    /*!< GPB_MFP PB.0 setting for GPIO */
#define SYS_ALT_MFP_PB0_GPIO            NULL            /*!< No ALT_MFP setting for PB.0 */
#define SYS_ALT_MFP1_PB0_GPIO           NULL            /*!< No ALT_MFP1 setting for PB.0 */

#define SYS_GPB_MFP_PB0_UART0_RXD       (1UL<<0)        /*!< GPB_MFP PB.0 setting for UART0_RXD */
#define SYS_ALT_MFP_PB0_UART0_RXD       NULL            /*!< No ALT_MFP setting for PB.0 */
#define SYS_ALT_MFP1_PB0_UART0_RXD      NULL            /*!< No ALT_MFP1 setting for PB.0 */

#define SYS_GPB_MFP_PB0_Msk             (1UL<<0)        /*!< GPB_MFP PB.0 mask */
#define SYS_ALT_MFP_PB0_Msk             NULL            /*!< No ALT_MFP PB.0 mask */
#define SYS_ALT_MFP1_PB0_Msk            NULL            /*!< No ALT_MFP1 PB.0 mask */

//PB.1
#define SYS_GPB_MFP_PB1_GPIO            0x00000000UL    /*!< GPB_MFP PB.1 setting for GPIO */
#define SYS_ALT_MFP_PB1_GPIO            NULL            /*!< No ALT_MFP setting for PB.1 */
#define SYS_ALT_MFP1_PB1_GPIO           NULL            /*!< No ALT_MFP1 setting for PB.1 */

#define SYS_GPB_MFP_PB1_UART0_TXD       (1UL<<1)        /*!< GPB_MFP PB.1 setting for UART0_TXD */
#define SYS_ALT_MFP_PB1_UART0_TXD       NULL            /*!< No ALT_MFP setting for PB.1 */
#define SYS_ALT_MFP1_PB1_UART0_TXD      NULL            /*!< No ALT_MFP1 setting for PB.1 */

#define SYS_GPB_MFP_PB1_Msk             (1UL<<1)        /*!< GPB_MFP PB.1 mask */
#define SYS_ALT_MFP_PB1_Msk             NULL            /*!< No ALT_MFP PB.1 mask */
#define SYS_ALT_MFP1_PB1_Msk            NULL            /*!< No ALT_MFP1 PB.1 mask */

//PB.2
#define SYS_GPB_MFP_PB2_GPIO            0x00000000UL    /*!< GPB_MFP PB.2 setting for GPIO */
#define SYS_ALT_MFP_PB2_GPIO            0x00000000UL    /*!< ALT_MFP PB.2 setting for GPIO */
#define SYS_ALT_MFP1_PB2_GPIO           NULL            /*!< No ALT_MFP1 setting for PB.2 */

#define SYS_GPB_MFP_PB2_UART0_nRTS      (1UL<<2)        /*!< GPB_MFP PB.2 setting for UART0_nRTS */
#define SYS_ALT_MFP_PB2_UART0_nRTS      0x00000000UL    /*!< ALT_MFP PB.2 setting for UART0_nRTS */
#define SYS_ALT_MFP1_PB2_UART0_nRTS     NULL            /*!< No ALT_MFP1 setting for PB.2 */

#define SYS_GPB_MFP_PB2_TM2_EXT         (1UL<<2)        /*!< GPB_MFP PB.2 setting for TM2_EXT */
#define SYS_ALT_MFP_PB2_TM2_EXT         (1UL<<26)       /*!< ALT_MFP PB.2 setting for TM2_EXT */
#define SYS_ALT_MFP1_PB2_TM2_EXT        NULL            /*!< No ALT_MFP1 setting for PB.2 */

#define SYS_GPB_MFP_PB2_Msk             (1UL<<2)        /*!< GPB_MFP PB.2 mask */
#define SYS_ALT_MFP_PB2_Msk             (1UL<<26)       /*!< ALT_MFP PB.2 mask */
#define SYS_ALT_MFP1_PB2_Msk            NULL            /*!< No ALT_MFP1 PB.2 mask */

//PB.3
#define SYS_GPB_MFP_PB3_GPIO            0x00000000UL    /*!< GPB_MFP PB.3 setting for GPIO */
#define SYS_ALT_MFP_PB3_GPIO            0x00000000UL    /*!< ALT_MFP PB.3 setting for GPIO */
#define SYS_ALT_MFP1_PB3_GPIO           NULL            /*!< No ALT_MFP1 setting for PB.3 */

#define SYS_GPB_MFP_PB3_UART0_nCTS      (1UL<<3)        /*!< GPB_MFP PB.3 setting for UART0_nCTS */
#define SYS_ALT_MFP_PB3_UART0_nCTS      0x00000000UL    /*!< ALT_MFP PB.3 setting for UART0_nCTS */
#define SYS_ALT_MFP1_PB3_UART0_nCTS     NULL            /*!< No ALT_MFP1 setting for PB.3 */

#define SYS_GPB_MFP_PB3_TM3_EXT         (1UL<<3)        /*!< GPB_MFP PB.3 setting for TM3_EXT */
#define SYS_ALT_MFP_PB3_TM3_EXT         (1UL<<27)       /*!< ALT_MFP PB.3 setting for TM3_EXT */
#define SYS_ALT_MFP1_PB3_TM3_EXT        NULL            /*!< No ALT_MFP1 setting for PB.3 */

#define SYS_GPB_MFP_PB3_Msk             (1UL<<3)        /*!< GPB_MFP PB.3 mask */
#define SYS_ALT_MFP_PB3_Msk             (1UL<<27)       /*!< ALT_MFP PB.3 mask */
#define SYS_ALT_MFP1_PB3_Msk            NULL            /*!< No ALT_MFP1 PB.3 mask */

//PB.4
#define SYS_GPB_MFP_PB4_GPIO            0x00000000UL    /*!< GPB_MFP PB.4 setting for GPIO */
#define SYS_ALT_MFP_PB4_GPIO            0x00000000UL    /*!< ALT_MFP PB.4 setting for GPIO */
#define SYS_ALT_MFP1_PB4_GPIO           NULL            /*!< No ALT_MFP1 setting for PB.4 */

#define SYS_GPB_MFP_PB4_UART1_RXD       (1UL<<4)        /*!< GPB_MFP PB.4 setting for UART1_RXD */
#define SYS_ALT_MFP_PB4_UART1_RXD       0x00000000UL    /*!< ALT_MFP PB.4 setting for UART1_RXD */
#define SYS_ALT_MFP1_PB4_UART1_RXD      NULL            /*!< No ALT_MFP1 setting for PB.4 */

#define SYS_GPB_MFP_PB4_SPI2_SS0        0x00000000UL    /*!< GPB_MFP PB.4 setting for SPI2_SS0 */
#define SYS_ALT_MFP_PB4_SPI2_SS0        (1UL<<15)       /*!< ALT_MFP PB.4 setting for SPI2_SS0 */
#define SYS_ALT_MFP1_PB4_SPI2_SS0       NULL            /*!< No ALT_MFP1 setting for PB.4 */

#define SYS_GPB_MFP_PB4_SPI1_SS1        (1UL<<4)        /*!< GPB_MFP PB.4 setting for SPI1_SS1 */
#define SYS_ALT_MFP_PB4_SPI1_SS1        (1UL<<15)       /*!< ALT_MFP PB.4 setting for SPI1_SS1 */
#define SYS_ALT_MFP1_PB4_SPI1_SS1       NULL            /*!< No ALT_MFP1 setting for PB.4 */

#define SYS_GPB_MFP_PB4_Msk             (1UL<<4)        /*!< GPB_MFP PB.4 mask */
#define SYS_ALT_MFP_PB4_Msk             (1UL<<15)       /*!< ALT_MFP PB.4 mask */
#define SYS_ALT_MFP1_PB4_Msk            NULL            /*!< No ALT_MFP1 PB.4 mask */

//PB.5
#define SYS_GPB_MFP_PB5_GPIO            0x00000000UL    /*!< GPB_MFP PB.5 setting for GPIO */
#define SYS_ALT_MFP_PB5_GPIO            0x00000000UL    /*!< ALT_MFP PB.5 setting for GPIO */
#define SYS_ALT_MFP1_PB5_GPIO           NULL            /*!< No ALT_MFP1 setting for PB.5 */

#define SYS_GPB_MFP_PB5_UART1_TXD       (1UL<<5)        /*!< GPB_MFP PB.5 setting for UART1_TXD */
#define SYS_ALT_MFP_PB5_UART1_TXD       0x00000000UL    /*!< ALT_MFP PB.5 setting for UART1_TXD */
#define SYS_ALT_MFP1_PB5_UART1_TXD      NULL            /*!< No ALT_MFP1 setting for PB.5 */

#define SYS_GPB_MFP_PB5_SPI2_CLK        (1UL<<5)        /*!< GPB_MFP PB.5 setting for SPI2_CLK */
#define SYS_ALT_MFP_PB5_SPI2_CLK        (1UL<<18)       /*!< ALT_MFP PB.5 setting for SPI2_CLK */
#define SYS_ALT_MFP1_PB5_SPI2_CLK       NULL            /*!< No ALT_MFP1 setting for PB.5 */

#define SYS_GPB_MFP_PB5_Msk             (1UL<<5)        /*!< GPB_MFP PB.5 mask */
#define SYS_ALT_MFP_PB5_Msk             (1UL<<18)       /*!< ALT_MFP PB.5 mask */
#define SYS_ALT_MFP1_PB5_Msk            NULL            /*!< No ALT_MFP1 PB.5 mask */

//PB.6
#define SYS_GPB_MFP_PB6_GPIO            0x00000000UL    /*!< GPB_MFP PB.6 setting for GPIO */
#define SYS_ALT_MFP_PB6_GPIO            0x00000000UL    /*!< ALT_MFP PB.6 setting for GPIO */
#define SYS_ALT_MFP1_PB6_GPIO           NULL            /*!< No ALT_MFP1 setting for PB.6 */

#define SYS_GPB_MFP_PB6_UART1_nRTS      (1UL<<6)        /*!< GPB_MFP PB.6 setting for UART1_nRTS */
#define SYS_ALT_MFP_PB6_UART1_nRTS      0x00000000UL    /*!< ALT_MFP PB.6 setting for UART1_nRTS */
#define SYS_ALT_MFP1_PB6_UART1_nRTS     NULL            /*!< No ALT_MFP1 setting for PB.6 */

#define SYS_GPB_MFP_PB6_SPI2_MOSI0      (1UL<<6)        /*!< GPB_MFP PB.6 setting for SPI2_MOSI0 */
#define SYS_ALT_MFP_PB6_SPI2_MOSI0      (1UL<<17)       /*!< ALT_MFP PB.6 setting for SPI2_MOSI0 */
#define SYS_ALT_MFP1_PB6_SPI2_MOSI0     NULL            /*!< No ALT_MFP1 setting for PB.6 */

#define SYS_GPB_MFP_PB6_Msk             (1UL<<6)        /*!< GPB_MFP PB.6 mask */
#define SYS_ALT_MFP_PB6_Msk             (1UL<<17)       /*!< ALT_MFP PB.6 mask */
#define SYS_ALT_MFP1_PB6_Msk            NULL            /*!< No ALT_MFP1 PB.6 mask */

//PB.7
#define SYS_GPB_MFP_PB7_GPIO            0x00000000UL    /*!< GPB_MFP PB.7 setting for GPIO */
#define SYS_ALT_MFP_PB7_GPIO            0x00000000UL    /*!< ALT_MFP PB.7 setting for GPIO */
#define SYS_ALT_MFP1_PB7_GPIO           NULL            /*!< No ALT_MFP1 setting for PB.7 */

#define SYS_GPB_MFP_PB7_UART1_nCTS      (1UL<<7)        /*!< GPB_MFP PB.7 setting for UART1_nCTS */
#define SYS_ALT_MFP_PB7_UART1_nCTS      0x00000000UL    /*!< ALT_MFP PB.7 setting for UART1_nCTS */
#define SYS_ALT_MFP1_PB7_UART1_nCTS     NULL            /*!< No ALT_MFP1 setting for PB.7 */

#define SYS_GPB_MFP_PB7_SPI2_MISO0      (1UL<<7)        /*!< GPB_MFP PB.7 setting for SPI2_MISO0 */
#define SYS_ALT_MFP_PB7_SPI2_MISO0      (1UL<<16)       /*!< ALT_MFP PB.7 setting for SPI2_MISO0 */
#define SYS_ALT_MFP1_PB7_SPI2_MISO0     NULL            /*!< No ALT_MFP1 setting for PB.7 */

#define SYS_GPB_MFP_PB7_Msk             (1UL<<7)        /*!< GPB_MFP PB.7 mask */
#define SYS_ALT_MFP_PB7_Msk             (1UL<<16)       /*!< ALT_MFP PB.7 mask */
#define SYS_ALT_MFP1_PB7_Msk            NULL            /*!< No ALT_MFP1 PB.7 mask */

//PB.8
#define SYS_GPB_MFP_PB8_GPIO            0x00000000UL    /*!< GPB_MFP PB.8 setting for GPIO */
#define SYS_ALT_MFP_PB8_GPIO            NULL            /*!< No ALT_MFP setting for PB.8 */
#define SYS_ALT_MFP1_PB8_GPIO           NULL            /*!< No ALT_MFP1 setting for PB.8 */

#define SYS_GPB_MFP_PB8_TM0             (1UL<<8)        /*!< GPB_MFP PB.8 setting for TM0 */
#define SYS_ALT_MFP_PB8_TM0             NULL            /*!< No ALT_MFP setting for PB.8 */
#define SYS_ALT_MFP1_PB8_TM0            NULL            /*!< No ALT_MFP1 setting for PB.8 */

#define SYS_GPB_MFP_PB8_Msk             (1UL<<8)        /*!< GPB_MFP PB.8 mask */
#define SYS_ALT_MFP_PB8_Msk             NULL            /*!< No ALT_MFP PB.8 mask */
#define SYS_ALT_MFP1_PB8_Msk            NULL            /*!< No ALT_MFP1 PB.8 mask */

//PB.9
#define SYS_GPB_MFP_PB9_GPIO            0x00000000UL    /*!< GPB_MFP PB.9 setting for GPIO */
#define SYS_ALT_MFP_PB9_GPIO            0x00000000UL    /*!< ALT_MFP PB.9 setting for GPIO */
#define SYS_ALT_MFP1_PB9_GPIO           NULL            /*!< No ALT_MFP1 setting for PB.9 */

#define SYS_GPB_MFP_PB9_TM1             (1UL<<9)        /*!< GPB_MFP PB.9 setting for TM1 */
#define SYS_ALT_MFP_PB9_TM1             0x00000000UL    /*!< ALT_MFP PB.9 setting for TM1 */
#define SYS_ALT_MFP1_PB9_TM1            NULL            /*!< No ALT_MFP1 setting for PB.9 */

#define SYS_GPB_MFP_PB9_SPI1_SS1        (1UL<<9)        /*!< GPB_MFP PB.9 setting for SPI1_SS1 */
#define SYS_ALT_MFP_PB9_SPI1_SS1        (1UL<<1)        /*!< ALT_MFP PB.9 setting for SPI1_SS1 */
#define SYS_ALT_MFP1_PB9_SPI1_SS1       NULL            /*!< No ALT_MFP1 setting for PB.9 */

#define SYS_GPB_MFP_PB9_PWM1            0x00000000UL    /*!< GPB_MFP PB.9 setting for PWM1 (NUC123xxxAEx only) */
#define SYS_ALT_MFP_PB9_PWM1            (1UL<<1)        /*!< ALT_MFP PB.9 setting for PWM1 (NUC123xxxAEx only) */
#define SYS_ALT_MFP1_PB9_PWM1           NULL            /*!< No ALT_MFP1 setting for PB.9 */

#define SYS_GPB_MFP_PB9_Msk             (1UL<<9)        /*!< GPB_MFP PB.9 mask */
#define SYS_ALT_MFP_PB9_Msk             (1UL<<1)        /*!< ALT_MFP PB.9 mask */
#define SYS_ALT_MFP1_PB9_Msk            NULL            /*!< No ALT_MFP1 PB.9 mask */

//PB.10
#define SYS_GPB_MFP_PB10_GPIO           0x00000000UL    /*!< GPB_MFP PB.10 setting for GPIO */
#define SYS_ALT_MFP_PB10_GPIO           0x00000000UL    /*!< ALT_MFP PB.10 setting for GPIO */
#define SYS_ALT_MFP1_PB10_GPIO          NULL            /*!< No ALT_MFP1 setting for PB.10 */

#define SYS_GPB_MFP_PB10_TM2            (1UL<<10)       /*!< GPB_MFP PB.10 setting for TM2 */
#define SYS_ALT_MFP_PB10_TM2            0x00000000UL    /*!< ALT_MFP PB.10 setting for TM2 */
#define SYS_ALT_MFP1_PB10_TM2           NULL            /*!< No ALT_MFP1 setting for PB.10 */

#define SYS_GPB_MFP_PB10_SPI0_SS1       (1UL<<10)       /*!< GPB_MFP PB.10 setting for SPI0_SS1 */
#define SYS_ALT_MFP_PB10_SPI0_SS1       (1UL<<0)        /*!< ALT_MFP PB.10 setting for SPI0_SS1 */
#define SYS_ALT_MFP1_PB10_SPI0_SS1      NULL            /*!< No ALT_MFP1 setting for PB.10 */

#define SYS_GPB_MFP_PB10_Msk            (1UL<<10)       /*!< GPB_MFP PB.10 mask */
#define SYS_ALT_MFP_PB10_Msk            (1UL<<0)        /*!< ALT_MFP PB.10 mask */
#define SYS_ALT_MFP1_PB10_Msk           NULL            /*!< No ALT_MFP1 PB.10 mask */

//PB.12
#define SYS_GPB_MFP_PB12_GPIO           0x00000000UL    /*!< GPB_MFP PB.12 setting for GPIO */
#define SYS_ALT_MFP_PB12_GPIO           0x00000000UL    /*!< ALT_MFP PB.12 setting for GPIO */
#define SYS_ALT_MFP1_PB12_GPIO          NULL            /*!< No ALT_MFP1 setting for PB.12 */

#define SYS_GPB_MFP_PB12_SPI1_SS0       (1UL<<12)       /*!< GPB_MFP PB.12 setting for SPI1_SS0 */
#define SYS_ALT_MFP_PB12_SPI1_SS0       0x00000000UL    /*!< ALT_MFP PB.12 setting for SPI1_SS0 */
#define SYS_ALT_MFP1_PB12_SPI1_SS0      NULL            /*!< No ALT_MFP1 setting for PB.12 */

#define SYS_GPB_MFP_PB12_CLKO           (1UL<<12)       /*!< GPB_MFP PB.12 setting for CLKO */
#define SYS_ALT_MFP_PB12_CLKO           (1UL<<10)       /*!< ALT_MFP PB.12 setting for CLKO */
#define SYS_ALT_MFP1_PB12_CLKO          NULL            /*!< No ALT_MFP1 setting for PB.12 */

#define SYS_GPB_MFP_PB12_Msk            (1UL<<12)       /*!< GPB_MFP PB.12 mask */
#define SYS_ALT_MFP_PB12_Msk            (1UL<<10)       /*!< ALT_MFP PB.12 mask */
#define SYS_ALT_MFP1_PB12_Msk           NULL            /*!< No ALT_MFP1 PB.12 mask */

//PB.13
#define SYS_GPB_MFP_PB13_GPIO           0x00000000UL    /*!< GPB_MFP PB.13 setting for GPIO */
#define SYS_ALT_MFP_PB13_GPIO           NULL            /*!< No ALT_MFP setting for PB.13 */
#define SYS_ALT_MFP1_PB13_GPIO          NULL            /*!< No ALT_MFP1 setting for PB.13 */

#define SYS_GPB_MFP_PB13_Msk            (1UL<<13)       /*!< GPB_MFP PB.13 mask */
#define SYS_ALT_MFP_PB13_Msk            NULL            /*!< No ALT_MFP PB.13 mask */
#define SYS_ALT_MFP1_PB13_Msk           NULL            /*!< No ALT_MFP1 PB.13 mask */

//PB.14
#define SYS_GPB_MFP_PB14_GPIO           0x00000000UL    /*!< GPB_MFP PB.14 setting for GPIO */
#define SYS_ALT_MFP_PB14_GPIO           NULL            /*!< No ALT_MFP setting for PB.14 */
#define SYS_ALT_MFP1_PB14_GPIO          NULL            /*!< No ALT_MFP1 setting for PB.14 */

#define SYS_GPB_MFP_PB14_INT0           (1UL<<14)       /*!< GPB_MFP PB.14 setting for INT0 */
#define SYS_ALT_MFP_PB14_INT0           NULL            /*!< No ALT_MFP setting for PB.14 */
#define SYS_ALT_MFP1_PB14_INT0          NULL            /*!< No ALT_MFP1 setting for PB.14 */

#define SYS_GPB_MFP_PB14_Msk            (1UL<<14)       /*!< GPB_MFP PB.14 mask */
#define SYS_ALT_MFP_PB14_Msk            NULL            /*!< No ALT_MFP PB.14 mask */
#define SYS_ALT_MFP1_PB14_Msk           NULL            /*!< No ALT_MFP1 PB.14 mask */

//PB.15
#define SYS_GPB_MFP_PB15_GPIO           0x00000000UL    /*!< GPB_MFP PB.15 setting for GPIO */
#define SYS_ALT_MFP_PB15_GPIO           0x00000000UL    /*!< ALT_MFP PB.15 setting for GPIO */
#define SYS_ALT_MFP1_PB15_GPIO          NULL            /*!< No ALT_MFP1 setting for PB.15 */

#define SYS_GPB_MFP_PB15_INT1           (1UL<<15)       /*!< GPB_MFP PB.15 setting for INT1 */
#define SYS_ALT_MFP_PB15_INT1           0x00000000UL    /*!< ALT_MFP PB.15 setting for INT1 */
#define SYS_ALT_MFP1_PB15_INT1          NULL            /*!< No ALT_MFP1 setting for PB.15 */

#define SYS_GPB_MFP_PB15_TM0_EXT        (1UL<<15)       /*!< GPB_MFP PB.15 setting for TM0_EXT */
#define SYS_ALT_MFP_PB15_TM0_EXT        (1UL<<24)       /*!< ALT_MFP PB.15 setting for TM0_EXT */
#define SYS_ALT_MFP1_PB15_TM0_EXT       NULL            /*!< No ALT_MFP1 setting for PB.15 */

#define SYS_GPB_MFP_PB15_Msk            (1UL<<15)       /*!< GPB_MFP PB.15 mask */
#define SYS_ALT_MFP_PB15_Msk            (1UL<<24)       /*!< ALT_MFP PB.15 mask */
#define SYS_ALT_MFP1_PB15_Msk           NULL            /*!< No ALT_MFP1 PB.15 mask */

//PC.0
#define SYS_GPC_MFP_PC0_GPIO            0x00000000UL    /*!< GPB_MFP PC.0 setting for GPIO */
#define SYS_ALT_MFP_PC0_GPIO            0x00000000UL    /*!< ALT_MFP PC.0 setting for GPIO */
#define SYS_ALT_MFP1_PC0_GPIO           NULL            /*!< No ALT_MFP1 setting for PC.0 */

#define SYS_GPC_MFP_PC0_SPI0_SS0        (1UL<<0)        /*!< GPB_MFP PC.0 setting for SPI0_SS0 */
#define SYS_ALT_MFP_PC0_SPI0_SS0        0x00000000UL    /*!< ALT_MFP PC.0 setting for SPI0_SS0 */
#define SYS_ALT_MFP1_PC0_SPI0_SS0       NULL            /*!< No ALT_MFP1 setting for PC.0 */

#define SYS_GPC_MFP_PC0_I2S_LRCLK       (1UL<<0)        /*!< GPB_MFP PC.0 setting for I2S_LRCLK */
#define SYS_ALT_MFP_PC0_I2S_LRCLK       (1UL<<5)        /*!< ALT_MFP PC.0 setting for I2S_LRCLK */
#define SYS_ALT_MFP1_PC0_I2S_LRCLK      NULL            /*!< No ALT_MFP1 setting for PC.0 */

#define SYS_GPC_MFP_PC0_Msk             (1UL<<0)        /*!< GPC_MFP PC.0 mask */
#define SYS_ALT_MFP_PC0_Msk             (1UL<<5)        /*!< ALT_MFP PC.0 mask */
#define SYS_ALT_MFP1_PC0_Msk            NULL            /*!< No ALT_MFP1 PC.0 mask */

//PC.1
#define SYS_GPC_MFP_PC1_GPIO            0x00000000UL    /*!< GPC_MFP PC.1 setting for GPIO */
#define SYS_ALT_MFP_PC1_GPIO            0x00000000UL    /*!< ALT_MFP PC.1 setting for GPIO */
#define SYS_ALT_MFP1_PC1_GPIO           NULL            /*!< No ALT_MFP1 setting for PC.1 */

#define SYS_GPC_MFP_PC1_SPI0_CLK        (1UL<<1)        /*!< GPC_MFP PC.1 setting for SPI0_CLK */
#define SYS_ALT_MFP_PC1_SPI0_CLK        0x00000000UL    /*!< ALT_MFP PC.1 setting for SPI0_CLK */
#define SYS_ALT_MFP1_PC1_SPI0_CLK       NULL            /*!< No ALT_MFP1 setting for PC.1 */

#define SYS_GPC_MFP_PC1_I2S_BCLK        (1UL<<1)        /*!< GPC_MFP PC.1 setting for I2S_BCLK */
#define SYS_ALT_MFP_PC1_I2S_BCLK        (1UL<<6)        /*!< ALT_MFP PC.1 setting for I2S_BCLK */
#define SYS_ALT_MFP1_PC1_I2S_BCLK       NULL            /*!< No ALT_MFP1 setting for PC.1 */

#define SYS_GPC_MFP_PC1_Msk             (1UL<<1)        /*!< GPC_MFP PC.1 mask */
#define SYS_ALT_MFP_PC1_Msk             (1UL<<6)        /*!< ALT_MFP PC.1 mask */
#define SYS_ALT_MFP1_PC1_Msk            NULL            /*!< No ALT_MFP1 PC.1 mask */

//PC.2
#define SYS_GPC_MFP_PC2_GPIO            0x00000000UL    /*!< GPC_MFP PC.2 setting for GPIO */
#define SYS_ALT_MFP_PC2_GPIO            0x00000000UL    /*!< ALT_MFP PC.2 setting for GPIO */
#define SYS_ALT_MFP1_PC2_GPIO           NULL            /*!< No ALT_MFP1 setting for PC.2 */

#define SYS_GPC_MFP_PC2_SPI0_MISO0      (1UL<<2)        /*!< GPC_MFP PC.2 setting for SPI0_MISO0 */
#define SYS_ALT_MFP_PC2_SPI0_MISO0      0x00000000UL    /*!< ALT_MFP PC.2 setting for SPI0_MISO0 */
#define SYS_ALT_MFP1_PC2_SPI0_MISO0     NULL            /*!< No ALT_MFP1 setting for PC.2 */

#define SYS_GPC_MFP_PC2_I2S_DI          (1UL<<2)        /*!< GPC_MFP PC.2 setting for I2S_DI */
#define SYS_ALT_MFP_PC2_I2S_DI          (1UL<<7)        /*!< ALT_MFP PC.2 setting for I2S_DI */
#define SYS_ALT_MFP1_PC2_I2S_DI         NULL            /*!< No ALT_MFP1 setting for PC.2 */

#define SYS_GPC_MFP_PC2_Msk             (1UL<<2)        /*!< GPC_MFP PC.2 mask */
#define SYS_ALT_MFP_PC2_Msk             (1UL<<7)        /*!< ALT_MFP PC.2 mask */
#define SYS_ALT_MFP1_PC2_Msk            NULL            /*!< No ALT_MFP1 PC.2 mask */

//PC.3
#define SYS_GPC_MFP_PC3_GPIO            0x00000000UL    /*!< GPC_MFP PC.3 setting for GPIO */
#define SYS_ALT_MFP_PC3_GPIO            0x00000000UL    /*!< ALT_MFP PC.3 setting for GPIO */
#define SYS_ALT_MFP1_PC3_GPIO           NULL            /*!< No ALT_MFP1 setting for PC.3 */

#define SYS_GPC_MFP_PC3_SPI0_MOSI0      (1UL<<3)        /*!< GPC_MFP PC.3 setting for SPI0_MOSI0 */
#define SYS_ALT_MFP_PC3_SPI0_MOSI0      0x00000000UL    /*!< ALT_MFP PC.3 setting for SPI0_MOSI0 */
#define SYS_ALT_MFP1_PC3_SPI0_MOSI0     NULL            /*!< No ALT_MFP1 setting for PC.3 */

#define SYS_GPC_MFP_PC3_I2S_DO          (1UL<<3)        /*!< GPC_MFP PC.3 setting for I2S_DO */
#define SYS_ALT_MFP_PC3_I2S_DO          (1UL<<8)        /*!< ALT_MFP PC.3 setting for I2S_DO */
#define SYS_ALT_MFP1_PC3_I2S_DO         NULL            /*!< No ALT_MFP1 setting for PC.3 */

#define SYS_GPC_MFP_PC3_Msk             (1UL<<3)        /*!< GPC_MFP PC.3 mask */
#define SYS_ALT_MFP_PC3_Msk             (1UL<<8)        /*!< ALT_MFP PC.3 mask */
#define SYS_ALT_MFP1_PC3_Msk            NULL            /*!< No ALT_MFP1 PC.3 mask */

//PC.4
#define SYS_GPC_MFP_PC4_GPIO            0x00000000UL    /*!< GPC_MFP PC.4 setting for GPIO */
#define SYS_ALT_MFP_PC4_GPIO            0x00000000UL    /*!< ALT_MFP PC.4 setting for GPIO */
#define SYS_ALT_MFP1_PC4_GPIO           NULL            /*!< No ALT_MFP1 setting for PC.4 */

#define SYS_GPC_MFP_PC4_SPI0_MISO1      (1UL<<4)        /*!< GPC_MFP PC.4 setting for SPI0_MISO1 */
#define SYS_ALT_MFP_PC4_SPI0_MISO1      0x00000000UL    /*!< ALT_MFP PC.4 setting for SPI0_MISO1 */
#define SYS_ALT_MFP1_PC4_SPI0_MISO1     NULL            /*!< No ALT_MFP1 setting for PC.4 */

#define SYS_GPC_MFP_PC4_UART0_RXD       (1UL<<4)        /*!< GPC_MFP PC.4 setting for UART0_RXD */
#define SYS_ALT_MFP_PC4_UART0_RXD       (1UL<<29)       /*!< ALT_MFP PC.4 setting for UART0_RXD */
#define SYS_ALT_MFP1_PC4_UART0_RXD      NULL            /*!< No ALT_MFP1 setting for PC.4 */

#define SYS_GPC_MFP_PC4_Msk             (1UL<<4)        /*!< GPC_MFP PC.4 mask */
#define SYS_ALT_MFP_PC4_Msk             (1UL<<29)       /*!< ALT_MFP PC.4 mask */
#define SYS_ALT_MFP1_PC4_Msk            NULL            /*!< No ALT_MFP1 PC.4 mask */

//PC.5
#define SYS_GPC_MFP_PC5_GPIO            0x00000000UL    /*!< GPC_MFP PC.5 setting for GPIO */
#define SYS_ALT_MFP_PC5_GPIO            0x00000000UL    /*!< ALT_MFP PC.5 setting for GPIO */
#define SYS_ALT_MFP1_PC5_GPIO           NULL            /*!< No ALT_MFP1 setting for PC.5 */

#define SYS_GPC_MFP_PC5_SPI0_MOSI1      (1UL<<5)        /*!< GPC_MFP PC.5 setting for SPI0_MOSI1 */
#define SYS_ALT_MFP_PC5_SPI0_MOSI1      0x00000000UL    /*!< ALT_MFP PC.5 setting for SPI0_MOSI1 */
#define SYS_ALT_MFP1_PC5_SPI0_MOSI1     NULL            /*!< No ALT_MFP1 setting for PC.5 */

#define SYS_GPC_MFP_PC5_UART0_TXD       (1UL<<5)        /*!< GPC_MFP PC.5 setting for UART0_TXD */
#define SYS_ALT_MFP_PC5_UART0_TXD       (1UL<<30)       /*!< ALT_MFP PC.5 setting for UART0_TXD */
#define SYS_ALT_MFP1_PC5_UART0_TXD      NULL            /*!< No ALT_MFP1 setting for PC.5 */

#define SYS_GPC_MFP_PC5_Msk             (1UL<<5)        /*!< GPC_MFP PC.5 mask */
#define SYS_ALT_MFP_PC5_Msk             (1UL<<30)       /*!< ALT_MFP PC.5 mask */
#define SYS_ALT_MFP1_PC5_Msk            NULL            /*!< No ALT_MFP1 PC.5 mask */

//PC.8
#define SYS_GPC_MFP_PC8_GPIO            0x00000000UL    /*!< GPC_MFP PC.8 setting for GPIO */
#define SYS_ALT_MFP_PC8_GPIO            NULL            /*!< No ALT_MFP setting for PC.8 */
#define SYS_ALT_MFP1_PC8_GPIO           0x00000000UL    /*!< ALT_MFP1 PC.8 setting for GPIO */

#define SYS_GPC_MFP_PC8_SPI1_SS0        (1UL<<8)        /*!< GPC_MFP PC.8 setting for SPI1_SS0 */
#define SYS_ALT_MFP_PC8_SPI1_SS0        NULL            /*!< No ALT_MFP setting for PC.8 */
#define SYS_ALT_MFP1_PC8_SPI1_SS0       0x00000000UL    /*!< ALT_MFP1 PC.8 setting for SPI1_SS0 */

#define SYS_GPC_MFP_PC8_PWM0            (1UL<<8)        /*!< GPC_MFP PC.8 setting for PWM0 (NUC123xxxAEx only) */
#define SYS_ALT_MFP_PC8_PWM0            NULL            /*!< No ALT_MFP setting for PC.8 */
#define SYS_ALT_MFP1_PC8_PWM0           (1UL<<23)       /*!< ALT_MFP1 PC.8 setting for PWM0 (NUC123xxxAEx only) */

#define SYS_GPC_MFP_PC8_Msk             (1UL<<8)        /*!< GPC_MFP PC.8 mask */
#define SYS_ALT_MFP_PC8_Msk             NULL            /*!< No ALT_MFP PC.8 mask */
#define SYS_ALT_MFP1_PC8_Msk            (1UL<<23)       /*!< ALT_MFP1 PC.8 mask */

//PC.9
#define SYS_GPC_MFP_PC9_GPIO            0x00000000UL    /*!< GPC_MFP PC.9 setting for GPIO */
#define SYS_ALT_MFP_PC9_GPIO            NULL            /*!< No ALT_MFP setting for PC.9 */
#define SYS_ALT_MFP1_PC9_GPIO           NULL            /*!< No ALT_MFP1 setting for PC.9 */

#define SYS_GPC_MFP_PC9_SPI1_CLK        (1UL<<9)        /*!< GPC_MFP PC.9 setting for SPI1_CLK */
#define SYS_ALT_MFP_PC9_SPI1_CLK        NULL            /*!< No ALT_MFP setting for PC.9 */
#define SYS_ALT_MFP1_PC9_SPI1_CLK       NULL            /*!< No ALT_MFP1 setting for PC.9 */

#define SYS_GPC_MFP_PC9_Msk             (1UL<<9)        /*!< GPC_MFP PC.9 mask */
#define SYS_ALT_MFP_PC9_Msk             NULL            /*!< No ALT_MFP PC.9 mask */
#define SYS_ALT_MFP1_PC9_Msk            NULL            /*!< No ALT_MFP1 PC.9 mask */

//PC.10
#define SYS_GPC_MFP_PC10_GPIO           0x00000000UL    /*!< GPC_MFP PC.10 setting for GPIO */
#define SYS_ALT_MFP_PC10_GPIO           NULL            /*!< No ALT_MFP setting for PC.10 */
#define SYS_ALT_MFP1_PC10_GPIO          NULL            /*!< No ALT_MFP1 setting for PC.10 */

#define SYS_GPC_MFP_PC10_SPI1_MISO0     (1UL<<10)       /*!< GPC_MFP PC.10 setting for SPI1_MISO0 */
#define SYS_ALT_MFP_PC10_SPI1_MISO0     NULL            /*!< No ALT_MFP setting for PC.10 */
#define SYS_ALT_MFP1_PC10_SPI1_MISO0    NULL            /*!< No ALT_MFP1 setting for PC.10 */

#define SYS_GPC_MFP_PC10_Msk            (1UL<<10)       /*!< GPC_MFP PC.10 mask */
#define SYS_ALT_MFP_PC10_Msk            NULL            /*!< No ALT_MFP PC.10 mask */
#define SYS_ALT_MFP1_PC10_Msk           NULL            /*!< No ALT_MFP1 PC.10 mask */

//PC.11
#define SYS_GPC_MFP_PC11_GPIO           0x00000000UL    /*!< GPC_MFP PC.11 setting for GPIO */
#define SYS_ALT_MFP_PC11_GPIO           NULL            /*!< No ALT_MFP setting for PC.11 */
#define SYS_ALT_MFP1_PC11_GPIO          NULL            /*!< No ALT_MFP1 setting for PC.11 */

#define SYS_GPC_MFP_PC11_SPI1_MOSI0     (1UL<<11)       /*!< GPC_MFP PC.11 setting for SPI1_MOSI0 */
#define SYS_ALT_MFP_PC11_SPI1_MOSI0     NULL            /*!< No ALT_MFP setting for PC.11 */
#define SYS_ALT_MFP1_PC11_SPI1_MOSI0    NULL            /*!< No ALT_MFP1 setting for PC.11 */

#define SYS_GPC_MFP_PC11_Msk            (1UL<<11)       /*!< GPC_MFP PC.11 mask */
#define SYS_ALT_MFP_PC11_Msk            NULL            /*!< No ALT_MFP PC.11 mask */
#define SYS_ALT_MFP1_PC11_Msk           NULL            /*!< No ALT_MFP1 PC.11 mask */

//PC.12
#define SYS_GPC_MFP_PC12_GPIO           0x00000000UL    /*!< GPC_MFP PC.12 setting for GPIO */
#define SYS_ALT_MFP_PC12_GPIO           0x00000000UL    /*!< ALT_MFP PC.12 setting for GPIO */
#define SYS_ALT_MFP1_PC12_GPIO          NULL            /*!< No ALT_MFP1 setting for PC.12 */

#define SYS_GPC_MFP_PC12_SPI1_MISO1     (1UL<<12)       /*!< GPC_MFP PC.12 setting for SPI1_MISO1 */
#define SYS_ALT_MFP_PC12_SPI1_MISO1     0x00000000UL    /*!< ALT_MFP PC.12 setting for SPI1_MISO1 */
#define SYS_ALT_MFP1_PC12_SPI1_MISO1    NULL            /*!< No ALT_MFP1 setting for PC.12 */

#define SYS_GPC_MFP_PC12_I2S_MCLK       0x00000000UL    /*!< GPC_MFP PC.12 setting for I2S_MCLK */
#define SYS_ALT_MFP_PC12_I2S_MCLK       (1UL<<20)       /*!< ALT_MFP PC.12 setting for I2S_MCLK */
#define SYS_ALT_MFP1_PC12_I2S_MCLK      NULL            /*!< No ALT_MFP1 setting for PC.12 */

#define SYS_GPC_MFP_PC12_PWM2           (1UL<<12)       /*!< GPC_MFP PC.12 setting for PWM2 */
#define SYS_ALT_MFP_PC12_PWM2           (1UL<<20)       /*!< ALT_MFP PC.12 setting for PWM2 */
#define SYS_ALT_MFP1_PC12_PWM2          NULL            /*!< No ALT_MFP1 setting for PC.12 */

#define SYS_GPC_MFP_PC12_Msk            (1UL<<12)       /*!< GPC_MFP PC.12 mask */
#define SYS_ALT_MFP_PC12_Msk            (1UL<<20)       /*!< ALT_MFP PC.12 mask */
#define SYS_ALT_MFP1_PC12_Msk           NULL            /*!< No ALT_MFP1 PC.12 mask */

//PC.13
#define SYS_GPC_MFP_PC13_GPIO           0x00000000UL    /*!< GPC_MFP PC.13 setting for GPIO */
#define SYS_ALT_MFP_PC13_GPIO           0x00000000UL    /*!< ALT_MFP PC.13 setting for GPIO */
#define SYS_ALT_MFP1_PC13_GPIO          NULL            /*!< No ALT_MFP1 setting for PC.13 */

#define SYS_GPC_MFP_PC13_SPI1_MOSI1     (1UL<<13)       /*!< GPC_MFP PC.13 setting for SPI1_MOSI1 */
#define SYS_ALT_MFP_PC13_SPI1_MOSI1     0x00000000UL    /*!< ALT_MFP PC.13 setting for SPI1_MOSI1 */
#define SYS_ALT_MFP1_PC13_SPI1_MOSI1    NULL            /*!< No ALT_MFP1 setting for PC.13 */

#define SYS_GPC_MFP_PC13_CLKO           0x00000000UL    /*!< GPC_MFP PC.13 setting for CLKO */
#define SYS_ALT_MFP_PC13_CLKO           (1UL<<21)       /*!< ALT_MFP PC.13 setting for CLKO */
#define SYS_ALT_MFP1_PC13_CLKO          NULL            /*!< No ALT_MFP1 setting for PC.13 */

#define SYS_GPC_MFP_PC13_PWM3           (1UL<<13)       /*!< GPC_MFP PC.13 setting for PWM3 */
#define SYS_ALT_MFP_PC13_PWM3           (1UL<<21)       /*!< ALT_MFP PC.13 setting for PWM3 */
#define SYS_ALT_MFP1_PC13_PWM3          NULL            /*!< No ALT_MFP1 setting for PC.13 */

#define SYS_GPC_MFP_PC13_Msk            (1UL<<13)       /*!< GPC_MFP PC.13 mask */
#define SYS_ALT_MFP_PC13_Msk            (1UL<<21)       /*!< ALT_MFP PC.13 mask */
#define SYS_ALT_MFP1_PC13_Msk           NULL            /*!< No ALT_MFP1 PC.13 mask */

//PD.0
#define SYS_GPD_MFP_PD0_GPIO            0x00000000UL    /*!< GPD_MFP PD.0 setting for GPIO */
#define SYS_ALT_MFP_PD0_GPIO            NULL            /*!< No ALT_MFP setting for PD.0 */
#define SYS_ALT_MFP1_PD0_GPIO           0x00000000UL    /*!< ALT_MFP1 PD.0 setting for GPIO */

#define SYS_GPD_MFP_PD0_SPI2_SS0        0x00000000UL    /*!< GPD_MFP PD.0 setting for SPI2_SS0 */
#define SYS_ALT_MFP_PD0_SPI2_SS0        NULL            /*!< No ALT_MFP setting for PD.0 */
#define SYS_ALT_MFP1_PD0_SPI2_SS0       (1UL<<16)       /*!< ALT_MFP1 PD.0 setting for SPI2_SS0 */

#define SYS_GPD_MFP_PD0_ADC0            (1UL<<0)        /*!< GPD_MFP PD.0 setting for ADC0 */
#define SYS_ALT_MFP_PD0_ADC0            NULL            /*!< No ALT_MFP setting for PD.0 */
#define SYS_ALT_MFP1_PD0_ADC0           (1UL<<16)       /*!< ALT_MFP1 PD.0 setting for ADC0 */

#define SYS_GPD_MFP_PD0_Msk             (1UL<<0)        /*!< GPD_MFP PD.0 mask */
#define SYS_ALT_MFP_PD0_Msk             NULL            /*!< No ALT_MFP PD.0 mask */
#define SYS_ALT_MFP1_PD0_Msk            (1UL<<16)       /*!< ALT_MFP1 PD.0 mask */

//PD.1
#define SYS_GPD_MFP_PD1_GPIO            0x00000000UL    /*!< GPD_MFP PD.1 setting for GPIO */
#define SYS_ALT_MFP_PD1_GPIO            NULL            /*!< No ALT_MFP setting for PD.1 */
#define SYS_ALT_MFP1_PD1_GPIO           0x00000000UL    /*!< ALT_MFP1 PD.1 setting for GPIO */

#define SYS_GPD_MFP_PD1_SPI0_SS1        (1UL<<1)        /*!< GPD_MFP PD.1 setting for SPI0_SS1 */
#define SYS_ALT_MFP_PD1_SPI0_SS1        NULL            /*!< No ALT_MFP setting for PD.1 */
#define SYS_ALT_MFP1_PD1_SPI0_SS1       0x00000000UL    /*!< ALT_MFP1 PD.1 setting for SPI0_SS1 */

#define SYS_GPD_MFP_PD1_SPI2_CLK        0x00000000UL    /*!< GPD_MFP PD.1 setting for SPI2_CLK */
#define SYS_ALT_MFP_PD1_SPI2_CLK        NULL            /*!< No ALT_MFP setting for PD.1 */
#define SYS_ALT_MFP1_PD1_SPI2_CLK       (1UL<<17)       /*!< ALT_MFP1 PD.1 setting for SPI2_CLK */

#define SYS_GPD_MFP_PD1_ADC1            (1UL<<1)        /*!< GPD_MFP PD.1 setting for ADC1 */
#define SYS_ALT_MFP_PD1_ADC1            NULL            /*!< No ALT_MFP setting for PD.1 */
#define SYS_ALT_MFP1_PD1_ADC1           (1UL<<17)       /*!< ALT_MFP1 PD.1 setting for ADC1 */

#define SYS_GPD_MFP_PD1_Msk             (1UL<<1)        /*!< GPD_MFP PD.1 mask */
#define SYS_ALT_MFP_PD1_Msk             NULL            /*!< No ALT_MFP PD.1 mask */
#define SYS_ALT_MFP1_PD1_Msk            (1UL<<17)       /*!< ALT_MFP1 PD.1 mask */

//PD.2
#define SYS_GPD_MFP_PD2_GPIO            0x00000000UL    /*!< GPD_MFP PD.2 setting for GPIO */
#define SYS_ALT_MFP_PD2_GPIO            NULL            /*!< No ALT_MFP setting for PD.2 */
#define SYS_ALT_MFP1_PD2_GPIO           0x00000000UL    /*!< ALT_MFP1 PD.2 setting for GPIO */

#define SYS_GPD_MFP_PD2_SPI0_MISO1      (1UL<<2)        /*!< GPD_MFP PD.2 setting for SPI0_MISO1 */
#define SYS_ALT_MFP_PD2_SPI0_MISO1      NULL            /*!< No ALT_MFP setting for PD.2 */
#define SYS_ALT_MFP1_PD2_SPI0_MISO1     0x00000000UL    /*!< ALT_MFP1 PD.2 setting for SPI0_MISO1 */

#define SYS_GPD_MFP_PD2_SPI2_MISO0      0x00000000UL    /*!< GPD_MFP PD.2 setting for SPI2_MISO0 */
#define SYS_ALT_MFP_PD2_SPI2_MISO0      NULL            /*!< No ALT_MFP setting for PD.2 */
#define SYS_ALT_MFP1_PD2_SPI2_MISO0     (1UL<<18)       /*!< ALT_MFP1 PD.2 setting for SPI2_MISO0 */

#define SYS_GPD_MFP_PD2_ADC2            (1UL<<2)        /*!< GPD_MFP PD.2 setting for ADC2 */
#define SYS_ALT_MFP_PD2_ADC2            NULL            /*!< No ALT_MFP setting for PD.2 */
#define SYS_ALT_MFP1_PD2_ADC2           (1UL<<18)       /*!< ALT_MFP1 PD.2 setting for ADC2 */

#define SYS_GPD_MFP_PD2_Msk             (1UL<<2)        /*!< GPD_MFP PD.2 mask */
#define SYS_ALT_MFP_PD2_Msk             NULL            /*!< No ALT_MFP PD.2 mask */
#define SYS_ALT_MFP1_PD2_Msk            (1UL<<18)       /*!< ALT_MFP1 PD.2 mask */

//PD.3
#define SYS_GPD_MFP_PD3_GPIO            0x00000000UL    /*!< GPD_MFP PD.3 setting for GPIO */
#define SYS_ALT_MFP_PD3_GPIO            NULL            /*!< No ALT_MFP setting for PD.3 */
#define SYS_ALT_MFP1_PD3_GPIO           0x00000000UL    /*!< ALT_MFP1 PD.3 setting for GPIO */

#define SYS_GPD_MFP_PD3_SPI0_MOSI1      (1UL<<3)        /*!< GPD_MFP PD.3 setting for SPI0_MOSI1 */
#define SYS_ALT_MFP_PD3_SPI0_MOSI1      NULL            /*!< No ALT_MFP setting for PD.3 */
#define SYS_ALT_MFP1_PD3_SPI0_MOSI1     0x00000000UL    /*!< ALT_MFP1 PD.3 setting for SPI0_MOSI1 */

#define SYS_GPD_MFP_PD3_SPI2_MOSI0      0x00000000UL    /*!< GPD_MFP PD.3 setting for SPI2_MOSI0 */
#define SYS_ALT_MFP_PD3_SPI2_MOSI0      NULL            /*!< No ALT_MFP setting for PD.3 */
#define SYS_ALT_MFP1_PD3_SPI2_MOSI0     (1UL<<19)       /*!< ALT_MFP1 PD.3 setting for SPI2_MOSI0 */

#define SYS_GPD_MFP_PD3_ADC3            (1UL<<3)        /*!< GPD_MFP PD.3 setting for ADC3 */
#define SYS_ALT_MFP_PD3_ADC3            NULL            /*!< No ALT_MFP setting for PD.3 */
#define SYS_ALT_MFP1_PD3_ADC3           (1UL<<19)       /*!< ALT_MFP1 PD.3 setting for ADC3 */

#define SYS_GPD_MFP_PD3_Msk             (1UL<<3)        /*!< GPD_MFP PD.3 mask */
#define SYS_ALT_MFP_PD3_Msk             NULL            /*!< No ALT_MFP PD.3 mask */
#define SYS_ALT_MFP1_PD3_Msk            (1UL<<19)       /*!< ALT_MFP1 PD.3 mask */

//PD.4
#define SYS_GPD_MFP_PD4_GPIO            0x00000000UL    /*!< GPD_MFP PD.4 setting for GPIO */
#define SYS_ALT_MFP_PD4_GPIO            NULL            /*!< No ALT_MFP setting for PD.4 */
#define SYS_ALT_MFP1_PD4_GPIO           0x00000000UL    /*!< ALT_MFP1 PD.4 setting for GPIO */

#define SYS_GPD_MFP_PD4_SPI2_MISO1      0x00000000UL    /*!< GPD_MFP PD.4 setting for SPI2_MISO1 */
#define SYS_ALT_MFP_PD4_SPI2_MISO1      NULL            /*!< No ALT_MFP setting for PD.4 */
#define SYS_ALT_MFP1_PD4_SPI2_MISO1     (1UL<<20)       /*!< ALT_MFP1 PD.4 setting for SPI2_MISO1 */

#define SYS_GPD_MFP_PD4_ADC4            (1UL<<4)        /*!< GPD_MFP PD.4 setting for ADC4 */
#define SYS_ALT_MFP_PD4_ADC4            NULL            /*!< No ALT_MFP setting for PD.4 */
#define SYS_ALT_MFP1_PD4_ADC4           (1UL<<20)       /*!< ALT_MFP1 PD.4 setting for ADC4 */

#define SYS_GPD_MFP_PD4_Msk             (1UL<<4)        /*!< GPD_MFP PD.4 mask */
#define SYS_ALT_MFP_PD4_Msk             NULL            /*!< No ALT_MFP PD.4 mask */
#define SYS_ALT_MFP1_PD4_Msk            (1UL<<20)       /*!< ALT_MFP1 PD.4 mask */

//PD.5
#define SYS_GPD_MFP_PD5_GPIO            0x00000000UL    /*!< GPD_MFP PD.5 setting for GPIO */
#define SYS_ALT_MFP_PD5_GPIO            NULL            /*!< No ALT_MFP setting for PD.5 */
#define SYS_ALT_MFP1_PD5_GPIO           0x00000000UL    /*!< ALT_MFP1 PD.5 setting for GPIO */

#define SYS_GPD_MFP_PD5_SPI2_MOSI1      0x00000000UL    /*!< GPD_MFP PD.5 setting for SPI2_MOSI1 */
#define SYS_ALT_MFP_PD5_SPI2_MOSI1      NULL            /*!< No ALT_MFP setting for PD.5 */
#define SYS_ALT_MFP1_PD5_SPI2_MOSI1     (1UL<<21)       /*!< ALT_MFP1 PD.5 setting for SPI2_MOSI1 */

#define SYS_GPD_MFP_PD5_ADC5            (1UL<<5)        /*!< GPD_MFP PD.5 setting for ADC5 */
#define SYS_ALT_MFP_PD5_ADC5            NULL            /*!< No ALT_MFP setting for PD.5 */
#define SYS_ALT_MFP1_PD5_ADC5           (1UL<<21)       /*!< ALT_MFP1 PD.5 setting for ADC5 */

#define SYS_GPD_MFP_PD5_Msk             (1UL<<5)        /*!< GPD_MFP PD.5 mask */
#define SYS_ALT_MFP_PD5_Msk             NULL            /*!< No ALT_MFP PD.5 mask */
#define SYS_ALT_MFP1_PD5_Msk            (1UL<<21)       /*!< ALT_MFP1 PD.5 mask */

//PD.8
#define SYS_GPD_MFP_PD8_GPIO            0x00000000UL    /*!< GPD_MFP PD.8 setting for GPIO */
#define SYS_ALT_MFP_PD8_GPIO            NULL            /*!< No ALT_MFP setting for PD.8 */
#define SYS_ALT_MFP1_PD8_GPIO           NULL            /*!< No ALT_MFP1 setting for PD.8 */

#define SYS_GPD_MFP_PD8_SPI1_MOSI0      (1UL<<8)        /*!< GPD_MFP PD.8 setting for SPI1_MOSI0 */
#define SYS_ALT_MFP_PD8_SPI1_MOSI0      NULL            /*!< No ALT_MFP setting for PD.8 */
#define SYS_ALT_MFP1_PD8_SPI1_MOSI0     NULL            /*!< No ALT_MFP1 setting for PD.8 */

#define SYS_GPD_MFP_PD8_Msk             (1UL<<8)        /*!< GPD_MFP PD.8 mask */
#define SYS_ALT_MFP_PD8_Msk             NULL            /*!< No ALT_MFP PD.8 mask */
#define SYS_ALT_MFP1_PD8_Msk            NULL            /*!< No ALT_MFP1 PD.8 mask */

//PD.9
#define SYS_GPD_MFP_PD9_GPIO            0x00000000UL    /*!< GPD_MFP PD.9 setting for GPIO */
#define SYS_ALT_MFP_PD9_GPIO            NULL            /*!< No ALT_MFP setting for PD.9 */
#define SYS_ALT_MFP1_PD9_GPIO           NULL            /*!< No ALT_MFP1 setting for PD.9 */

#define SYS_GPD_MFP_PD9_Msk             (1UL<<9)        /*!< GPD_MFP PD.9 mask */
#define SYS_ALT_MFP_PD9_Msk             NULL            /*!< No ALT_MFP PD.9 mask */
#define SYS_ALT_MFP1_PD9_Msk            NULL            /*!< No ALT_MFP1 PD.9 mask */

//PD.10
#define SYS_GPD_MFP_PD10_GPIO           0x00000000UL    /*!< GPD_MFP PD.10 setting for GPIO */
#define SYS_ALT_MFP_PD10_GPIO           NULL            /*!< No ALT_MFP setting for PD.10 */
#define SYS_ALT_MFP1_PD10_GPIO          NULL            /*!< No ALT_MFP1 setting for PD.10 */

#define SYS_GPD_MFP_PD10_CLKO           (1UL<<10)       /*!< GPD_MFP PD.10 setting for CLKO */
#define SYS_ALT_MFP_PD10_CLKO           NULL            /*!< No ALT_MFP setting for PD.10 */
#define SYS_ALT_MFP1_PD10_CLKO          NULL            /*!< No ALT_MFP1 setting for PD.10 */

#define SYS_GPD_MFP_PD10_Msk            (1UL<<10)       /*!< GPD_MFP PD.10 mask */
#define SYS_ALT_MFP_PD10_Msk            NULL            /*!< No ALT_MFP PD.10 mask */
#define SYS_ALT_MFP1_PD10_Msk           NULL            /*!< No ALT_MFP1 PD.10 mask */

//PD.11
#define SYS_GPD_MFP_PD11_GPIO           0x00000000UL    /*!< GPD_MFP PD.11 setting for GPIO */
#define SYS_ALT_MFP_PD11_GPIO           NULL            /*!< No ALT_MFP setting for PD.11 */
#define SYS_ALT_MFP1_PD11_GPIO          NULL            /*!< No ALT_MFP1 setting for PD.11 */

#define SYS_GPD_MFP_PD11_INT1           (1UL<<11)       /*!< GPD_MFP PD.11 setting for INT1 */
#define SYS_ALT_MFP_PD11_INT1           NULL            /*!< No ALT_MFP setting for PD.11 */
#define SYS_ALT_MFP1_PD11_INT1          NULL            /*!< No ALT_MFP1 setting for PD.11 */

#define SYS_GPD_MFP_PD11_Msk            (1UL<<11)       /*!< GPD_MFP PD.11 mask */
#define SYS_ALT_MFP_PD11_Msk            NULL            /*!< No ALT_MFP PD.11 mask */
#define SYS_ALT_MFP1_PD11_Msk           NULL            /*!< No ALT_MFP1 PD.11 mask */

//PF.0
#define SYS_GPF_MFP_PF0_GPIO            0x00000000UL    /*!< GPF_MFP PF.0 setting for GPIO */
#define SYS_ALT_MFP_PF0_GPIO            NULL            /*!< No ALT_MFP setting for PF.0 */
#define SYS_ALT_MFP1_PF0_GPIO           NULL            /*!< No ALT_MFP1 setting for PF.0 */

#define SYS_GPF_MFP_PF0_XT1_OUT         (1UL<<0)        /*!< GPF_MFP PF.0 setting for XT1_OUT */
#define SYS_ALT_MFP_PF0_XT1_OUT         NULL            /*!< No ALT_MFP setting for PF.0 */
#define SYS_ALT_MFP1_PF0_XT1_OUT        NULL            /*!< No ALT_MFP1 setting for PF.0 */

#define SYS_GPF_MFP_PF0_Msk             (1UL<<0)        /*!< GPF_MFP PF.0 mask */
#define SYS_ALT_MFP_PF0_Msk             NULL            /*!< No ALT_MFP PF.0 mask */
#define SYS_ALT_MFP1_PF0_Msk            NULL            /*!< No ALT_MFP1 PF.0 mask */

//PF.1
#define SYS_GPF_MFP_PF1_GPIO            0x00000000UL    /*!< GPF_MFP PF.1 setting for GPIO */
#define SYS_ALT_MFP_PF1_GPIO            NULL            /*!< No ALT_MFP setting for PF.1 */
#define SYS_ALT_MFP1_PF1_GPIO           NULL            /*!< No ALT_MFP1 setting for PF.1 */

#define SYS_GPF_MFP_PF1_XT1_IN          (1UL<<1)        /*!< GPF_MFP PF.1 setting for XT1_IN */
#define SYS_ALT_MFP_PF1_XT1_IN          NULL            /*!< No ALT_MFP setting for PF.1 */
#define SYS_ALT_MFP1_PF1_XT1_IN         NULL            /*!< No ALT_MFP1 setting for PF.1 */

#define SYS_GPF_MFP_PF1_Msk             (1UL<<1)        /*!< GPF_MFP PF.1 mask */
#define SYS_ALT_MFP_PF1_Msk             NULL            /*!< No ALT_MFP PF.1 mask */
#define SYS_ALT_MFP1_PF1_Msk            NULL            /*!< No ALT_MFP1 PF.1 mask */

//PF.2
#define SYS_GPF_MFP_PF2_GPIO            0x00000000UL    /*!< GPF_MFP PF.2 setting for GPIO */
#define SYS_ALT_MFP_PF2_GPIO            NULL            /*!< No ALT_MFP setting for PF.2 */
#define SYS_ALT_MFP1_PF2_GPIO           0x00000000UL    /*!< ALT_MFP1 PF.2 setting for GPIO */

#define SYS_GPF_MFP_PF2_PS2_DAT         (1UL<<2)        /*!< GPF_MFP PF.2 setting for PS2_DAT */
#define SYS_ALT_MFP_PF2_PS2_DAT         NULL            /*!< No ALT_MFP setting for PF.2 */
#define SYS_ALT_MFP1_PF2_PS2_DAT        0x00000000UL    /*!< ALT_MFP1 PF.2 setting for PS2_DAT */

#define SYS_GPF_MFP_PF2_I2C0_SDA        (1UL<<2)        /*!< GPF_MFP PF.2 setting for I2C0_SDA */
#define SYS_ALT_MFP_PF2_I2C0_SDA        NULL            /*!< No ALT_MFP setting for PF.2 */
#define SYS_ALT_MFP1_PF2_I2C0_SDA       (0x2UL<<24)     /*!< ALT_MFP1 PF.2 setting for I2C0_SDA */

#define SYS_GPF_MFP_PF2_ADC6            (1UL<<2)        /*!< GPF_MFP PF.2 setting for ADC6 */
#define SYS_ALT_MFP_PF2_ADC6            NULL            /*!< No ALT_MFP setting for PF.2 */
#define SYS_ALT_MFP1_PF2_ADC6           (0x3UL<<24)     /*!< ALT_MFP1 PF.2 setting for ADC6 */

#define SYS_GPF_MFP_PF2_Msk             (1UL<<2)        /*!< GPF_MFP PF.2 mask */
#define SYS_ALT_MFP_PF2_Msk             NULL            /*!< No ALT_MFP PF.2 mask */
#define SYS_ALT_MFP1_PF2_Msk            (0x3UL<<24)     /*!< ALT_MFP1 PF.2 mask */

//PF.3
#define SYS_GPF_MFP_PF3_GPIO            0x00000000UL    /*!< GPF_MFP PF.3 setting for GPIO */
#define SYS_ALT_MFP_PF3_GPIO            NULL            /*!< No ALT_MFP setting for PF.3 */
#define SYS_ALT_MFP1_PF3_GPIO           0x00000000UL    /*!< ALT_MFP1 PF.3 setting for GPIO */

#define SYS_GPF_MFP_PF3_PS2_CLK         (1UL<<3)        /*!< GPF_MFP PF.3 setting for PS2_CLK */
#define SYS_ALT_MFP_PF3_PS2_CLK         NULL            /*!< No ALT_MFP setting for PF.3 */
#define SYS_ALT_MFP1_PF3_PS2_CLK        0x00000000UL    /*!< ALT_MFP1 PF.3 setting for PS2_CLK */

#define SYS_GPF_MFP_PF3_I2C0_SCL        (1UL<<3)        /*!< GPF_MFP PF.3 setting for I2C0_SCL */
#define SYS_ALT_MFP_PF3_I2C0_SCL        NULL            /*!< No ALT_MFP setting for PF.3 */
#define SYS_ALT_MFP1_PF3_I2C0_SCL       (0x2UL<<26)     /*!< ALT_MFP1 PF.3 setting for I2C0_SCL */

#define SYS_GPF_MFP_PF3_ADC7            (1UL<<3)        /*!< GPF_MFP PF.3 setting for ADC7 */
#define SYS_ALT_MFP_PF3_ADC7            NULL            /*!< No ALT_MFP setting for PF.3 */
#define SYS_ALT_MFP1_PF3_ADC7           (0x3UL<<26)     /*!< ALT_MFP1 PF.3 setting for ADC7 */

#define SYS_GPF_MFP_PF3_Msk             (1UL<<3)        /*!< GPF_MFP PF.3 mask */
#define SYS_ALT_MFP_PF3_Msk             NULL            /*!< No ALT_MFP PF.3 mask */
#define SYS_ALT_MFP1_PF3_Msk            (0x3UL<<26)     /*!< ALT_MFP1 PF.3 mask */


/*---------------------------------------------------------------------------------------------------------*/
/*  New Multi-Function constant definitions. (NUC123xxxAEx only)                                           */
/*---------------------------------------------------------------------------------------------------------*/

/* How to use below #define?
Example: If user want to set PA.10 as I2C1_SDA and PA.11 as I2C1_SCL in initial function,
         user can issue following command to achieve it.

         SYS->GPA_MFPH &= ~(SYS_GPA_MFPH_GPA10_MFP_Msk | SYS_GPA_MFPH_GPA11_MFP_Msk);
         SYS->GPA_MFPH |= (SYS_GPA_MFPH_GPA10_MFP_I2C1_SDA | SYS_GPA_MFPH_GPA11_MFP_I2C1_SCL);
*/

//GPA10_MFP
#define SYS_GPA_MFPH_GPA10_MFP_GPIO         (0x0UL<<SYS_GPA_MFPH_GPA10_MFP_Pos)     /*!< GPA_MFPH GPA10 setting for GPIO */
#define SYS_GPA_MFPH_GPA10_MFP_I2C1_SDA     (0x1UL<<SYS_GPA_MFPH_GPA10_MFP_Pos)     /*!< GPA_MFPH GPA10 setting for I2C1_SDA */
#define SYS_GPA_MFPH_GPA10_MFP_SPI1_MISO0   (0x2UL<<SYS_GPA_MFPH_GPA10_MFP_Pos)     /*!< GPA_MFPH GPA10 setting for SPI1_MISO0 */
#define SYS_GPA_MFPH_GPA10_MFP_SPI2_MISO0   (0x3UL<<SYS_GPA_MFPH_GPA10_MFP_Pos)     /*!< GPA_MFPH GPA10 setting for SPI2_MISO0 */

//GPA11_MFP
#define SYS_GPA_MFPH_GPA11_MFP_GPIO         (0x0UL<<SYS_GPA_MFPH_GPA11_MFP_Pos)     /*!< GPA_MFPH GPA11 setting for GPIO */
#define SYS_GPA_MFPH_GPA11_MFP_I2C1_SCL     (0x1UL<<SYS_GPA_MFPH_GPA11_MFP_Pos)     /*!< GPA_MFPH GPA11 setting for I2C1_SCL */
#define SYS_GPA_MFPH_GPA11_MFP_SPI1_CLK     (0x2UL<<SYS_GPA_MFPH_GPA11_MFP_Pos)     /*!< GPA_MFPH GPA11 setting for SPI1_CLK */
#define SYS_GPA_MFPH_GPA11_MFP_SPI2_MOSI0   (0x3UL<<SYS_GPA_MFPH_GPA11_MFP_Pos)     /*!< GPA_MFPH GPA11 setting for SPI2_MOSI0 */

//GPA12_MFP
#define SYS_GPA_MFPH_GPA12_MFP_GPIO         (0x0UL<<SYS_GPA_MFPH_GPA12_MFP_Pos)     /*!< GPA_MFPH GPA12 setting for GPIO */
#define SYS_GPA_MFPH_GPA12_MFP_PWM0         (0x1UL<<SYS_GPA_MFPH_GPA12_MFP_Pos)     /*!< GPA_MFPH GPA12 setting for PWM0 */

//GPA13_MFP
#define SYS_GPA_MFPH_GPA13_MFP_GPIO         (0x0UL<<SYS_GPA_MFPH_GPA13_MFP_Pos)     /*!< GPA_MFPH GPA13 setting for GPIO */
#define SYS_GPA_MFPH_GPA13_MFP_PWM1         (0x1UL<<SYS_GPA_MFPH_GPA13_MFP_Pos)     /*!< GPA_MFPH GPA13 setting for PWM1 */

//GPA14_MFP
#define SYS_GPA_MFPH_GPA14_MFP_GPIO         (0x0UL<<SYS_GPA_MFPH_GPA14_MFP_Pos)     /*!< GPA_MFPH GPA14 setting for GPIO */
#define SYS_GPA_MFPH_GPA14_MFP_PWM2         (0x1UL<<SYS_GPA_MFPH_GPA14_MFP_Pos)     /*!< GPA_MFPH GPA14 setting for PWM2 */

//GPA15_MFP
#define SYS_GPA_MFPH_GPA15_MFP_GPIO         (0x0UL<<SYS_GPA_MFPH_GPA15_MFP_Pos)     /*!< GPA_MFPH GPA15 setting for GPIO */
#define SYS_GPA_MFPH_GPA15_MFP_PWM3         (0x1UL<<SYS_GPA_MFPH_GPA15_MFP_Pos)     /*!< GPA_MFPH GPA15 setting for PWM3 */
#define SYS_GPA_MFPH_GPA15_MFP_CLKO         (0x2UL<<SYS_GPA_MFPH_GPA15_MFP_Pos)     /*!< GPA_MFPH GPA15 setting for CLKO */
#define SYS_GPA_MFPH_GPA15_MFP_I2S_MCLK     (0x3UL<<SYS_GPA_MFPH_GPA15_MFP_Pos)     /*!< GPA_MFPH GPA15 setting for I2S_MCLK */

//GPB0_MFP
#define SYS_GPB_MFPL_GPB0_MFP_GPIO          (0x0UL<<SYS_GPB_MFPL_GPB0_MFP_Pos)      /*!< GPB_MFPL GPB0 setting for GPIO */
#define SYS_GPB_MFPL_GPB0_MFP_UART0_RXD     (0x1UL<<SYS_GPB_MFPL_GPB0_MFP_Pos)      /*!< GPB_MFPL GPB0 setting for UART0_RXD */

//GPB1_MFP
#define SYS_GPB_MFPL_GPB1_MFP_GPIO          (0x0UL<<SYS_GPB_MFPL_GPB1_MFP_Pos)      /*!< GPB_MFPL GPB1 setting for GPIO */
#define SYS_GPB_MFPL_GPB1_MFP_UART0_TXD     (0x1UL<<SYS_GPB_MFPL_GPB1_MFP_Pos)      /*!< GPB_MFPL GPB1 setting for UART0_TXD */

//GPB2_MFP
#define SYS_GPB_MFPL_GPB2_MFP_GPIO          (0x0UL<<SYS_GPB_MFPL_GPB2_MFP_Pos)      /*!< GPB_MFPL GPB2 setting for GPIO */
#define SYS_GPB_MFPL_GPB2_MFP_UART0_nRTS    (0x1UL<<SYS_GPB_MFPL_GPB2_MFP_Pos)      /*!< GPB_MFPL GPB2 setting for UART0_nRTS */
#define SYS_GPB_MFPL_GPB2_MFP_TM2_EXT       (0x2UL<<SYS_GPB_MFPL_GPB2_MFP_Pos)      /*!< GPB_MFPL GPB2 setting for TM2_EXT */

//GPB3_MFP
#define SYS_GPB_MFPL_GPB3_MFP_GPIO          (0x0UL<<SYS_GPB_MFPL_GPB3_MFP_Pos)      /*!< GPB_MFPL GPB3 setting for GPIO */
#define SYS_GPB_MFPL_GPB3_MFP_UART0_nCTS    (0x1UL<<SYS_GPB_MFPL_GPB3_MFP_Pos)      /*!< GPB_MFPL GPB3 setting for UART0_nCTS */
#define SYS_GPB_MFPL_GPB3_MFP_TM3_EXT       (0x2UL<<SYS_GPB_MFPL_GPB3_MFP_Pos)      /*!< GPB_MFPL GPB3 setting for TM3_EXT */

//GPB4_MFP
#define SYS_GPB_MFPL_GPB4_MFP_GPIO          (0x0UL<<SYS_GPB_MFPL_GPB4_MFP_Pos)      /*!< GPB_MFPL GPB4 setting for GPIO */
#define SYS_GPB_MFPL_GPB4_MFP_UART1_RXD     (0x1UL<<SYS_GPB_MFPL_GPB4_MFP_Pos)      /*!< GPB_MFPL GPB4 setting for UART1_RXD */
#define SYS_GPB_MFPL_GPB4_MFP_SPI2_SS0      (0x2UL<<SYS_GPB_MFPL_GPB4_MFP_Pos)      /*!< GPB_MFPL GPB4 setting for SPI2_SS0 */
#define SYS_GPB_MFPL_GPB4_MFP_SPI1_SS1      (0x3UL<<SYS_GPB_MFPL_GPB4_MFP_Pos)      /*!< GPB_MFPL GPB4 setting for SPI1_SS1 */

//GPB5_MFP
#define SYS_GPB_MFPL_GPB5_MFP_GPIO          (0x0UL<<SYS_GPB_MFPL_GPB5_MFP_Pos)      /*!< GPB_MFPL GPB5 setting for GPIO */
#define SYS_GPB_MFPL_GPB5_MFP_UART1_TXD     (0x1UL<<SYS_GPB_MFPL_GPB5_MFP_Pos)      /*!< GPB_MFPL GPB5 setting for UART1_TXD */
#define SYS_GPB_MFPL_GPB5_MFP_SPI2_CLK      (0x2UL<<SYS_GPB_MFPL_GPB5_MFP_Pos)      /*!< GPB_MFPL GPB5 setting for SPI2_CLK */

//GPB6_MFP
#define SYS_GPB_MFPL_GPB6_MFP_GPIO          (0x0UL<<SYS_GPB_MFPL_GPB6_MFP_Pos)      /*!< GPB_MFPL GPB6 setting for GPIO */
#define SYS_GPB_MFPL_GPB6_MFP_UART1_nRTS    (0x1UL<<SYS_GPB_MFPL_GPB6_MFP_Pos)      /*!< GPB_MFPL GPB6 setting for UART1_nRTS */
#define SYS_GPB_MFPL_GPB6_MFP_SPI2_MOSI0    (0x2UL<<SYS_GPB_MFPL_GPB6_MFP_Pos)      /*!< GPB_MFPL GPB6 setting for SPI2_MOSI0 */

//GPB7_MFP
#define SYS_GPB_MFPL_GPB7_MFP_GPIO          (0x0UL<<SYS_GPB_MFPL_GPB7_MFP_Pos)      /*!< GPB_MFPL GPB7 setting for GPIO */
#define SYS_GPB_MFPL_GPB7_MFP_UART1_nCTS    (0x1UL<<SYS_GPB_MFPL_GPB7_MFP_Pos)      /*!< GPB_MFPL GPB7 setting for UART1_nCTS */
#define SYS_GPB_MFPL_GPB7_MFP_SPI2_MISO0    (0x2UL<<SYS_GPB_MFPL_GPB7_MFP_Pos)      /*!< GPB_MFPL GPB7 setting for SPI2_MISO0 */

//GPB8_MFP
#define SYS_GPB_MFPH_GPB8_MFP_GPIO          (0x0UL<<SYS_GPB_MFPH_GPB8_MFP_Pos)      /*!< GPB_MFPH GPB8 setting for GPIO */
#define SYS_GPB_MFPH_GPB8_MFP_TM0           (0x1UL<<SYS_GPB_MFPH_GPB8_MFP_Pos)      /*!< GPB_MFPH GPB8 setting for TM0 */

//GPB9_MFP
#define SYS_GPB_MFPH_GPB9_MFP_GPIO          (0x0UL<<SYS_GPB_MFPH_GPB9_MFP_Pos)      /*!< GPB_MFPH GPB9 setting for GPIO */
#define SYS_GPB_MFPH_GPB9_MFP_TM1           (0x1UL<<SYS_GPB_MFPH_GPB9_MFP_Pos)      /*!< GPB_MFPH GPB9 setting for TM1 */
#define SYS_GPB_MFPH_GPB9_MFP_SPI1_SS1      (0x2UL<<SYS_GPB_MFPH_GPB9_MFP_Pos)      /*!< GPB_MFPH GPB9 setting for SPI1_SS1 */
#define SYS_GPB_MFPH_GPB9_MFP_PWM1          (0x3UL<<SYS_GPB_MFPH_GPB9_MFP_Pos)      /*!< GPB_MFPH GPB9 setting for PWM1 */

//GPB10_MFP
#define SYS_GPB_MFPH_GPB10_MFP_GPIO         (0x0UL<<SYS_GPB_MFPH_GPB10_MFP_Pos)      /*!< GPB_MFPH GPB10 setting for GPIO */
#define SYS_GPB_MFPH_GPB10_MFP_TM2          (0x1UL<<SYS_GPB_MFPH_GPB10_MFP_Pos)      /*!< GPB_MFPH GPB10 setting for TM2 */
#define SYS_GPB_MFPH_GPB10_MFP_SPI0_SS1     (0x2UL<<SYS_GPB_MFPH_GPB10_MFP_Pos)      /*!< GPB_MFPH GPB10 setting for SPI0_SS1 */

//GPB12_MFP
#define SYS_GPB_MFPH_GPB12_MFP_GPIO         (0x0UL<<SYS_GPB_MFPH_GPB12_MFP_Pos)      /*!< GPB_MFPH GPB12 setting for GPIO */
#define SYS_GPB_MFPH_GPB12_MFP_SPI1_SS0     (0x1UL<<SYS_GPB_MFPH_GPB12_MFP_Pos)      /*!< GPB_MFPH GPB12 setting for SPI1_SS0 */
#define SYS_GPB_MFPH_GPB12_MFP_CLKO         (0x2UL<<SYS_GPB_MFPH_GPB12_MFP_Pos)      /*!< GPB_MFPH GPB12 setting for CLKO */

//GPB13_MFP
#define SYS_GPB_MFPH_GPB13_MFP_GPIO         (0x0UL<<SYS_GPB_MFPH_GPB13_MFP_Pos)      /*!< GPB_MFPH GPB13 setting for GPIO */

//GPB14_MFP
#define SYS_GPB_MFPH_GPB14_MFP_GPIO         (0x0UL<<SYS_GPB_MFPH_GPB14_MFP_Pos)      /*!< GPB_MFPH GPB14 setting for GPIO */
#define SYS_GPB_MFPH_GPB14_MFP_INT0         (0x1UL<<SYS_GPB_MFPH_GPB14_MFP_Pos)      /*!< GPB_MFPH GPB14 setting for INT0 */

//GPB15_MFP
#define SYS_GPB_MFPH_GPB15_MFP_GPIO         (0x0UL<<SYS_GPB_MFPH_GPB15_MFP_Pos)      /*!< GPB_MFPH GPB15 setting for GPIO */
#define SYS_GPB_MFPH_GPB15_MFP_INT1         (0x1UL<<SYS_GPB_MFPH_GPB15_MFP_Pos)      /*!< GPB_MFPH GPB15 setting for INT1 */
#define SYS_GPB_MFPH_GPB15_MFP_TM0_EXT      (0x2UL<<SYS_GPB_MFPH_GPB15_MFP_Pos)      /*!< GPB_MFPH GPB15 setting for TM0_EXT */

//GPC0_MFP
#define SYS_GPC_MFPL_GPC0_MFP_GPIO          (0x0UL<<SYS_GPC_MFPL_GPC0_MFP_Pos)       /*!< GPC_MFPL GPC0 setting for GPIO */
#define SYS_GPC_MFPL_GPC0_MFP_SPI0_SS0      (0x1UL<<SYS_GPC_MFPL_GPC0_MFP_Pos)       /*!< GPC_MFPL GPC0 setting for TM0_EXT */
#define SYS_GPC_MFPL_GPC0_MFP_I2S_LRCLK     (0x2UL<<SYS_GPC_MFPL_GPC0_MFP_Pos)       /*!< GPC_MFPL GPC0 setting for I2S_LRCLK */

//GPC1_MFP
#define SYS_GPC_MFPL_GPC1_MFP_GPIO          (0x0UL<<SYS_GPC_MFPL_GPC1_MFP_Pos)       /*!< GPC_MFPL GPC1 setting for GPIO */
#define SYS_GPC_MFPL_GPC1_MFP_SPI0_CLK      (0x1UL<<SYS_GPC_MFPL_GPC1_MFP_Pos)       /*!< GPC_MFPL GPC1 setting for SPI0_CLK */
#define SYS_GPC_MFPL_GPC1_MFP_I2S_BCLK      (0x2UL<<SYS_GPC_MFPL_GPC1_MFP_Pos)       /*!< GPC_MFPL GPC1 setting for I2S_BCLK */

//GPC2_MFP
#define SYS_GPC_MFPL_GPC2_MFP_GPIO          (0x0UL<<SYS_GPC_MFPL_GPC2_MFP_Pos)       /*!< GPC_MFPL GPC2 setting for GPIO */
#define SYS_GPC_MFPL_GPC2_MFP_SPI0_MISO0    (0x1UL<<SYS_GPC_MFPL_GPC2_MFP_Pos)       /*!< GPC_MFPL GPC2 setting for SPI0_MISO0 */
#define SYS_GPC_MFPL_GPC2_MFP_I2S_DI        (0x2UL<<SYS_GPC_MFPL_GPC2_MFP_Pos)       /*!< GPC_MFPL GPC2 setting for I2S_DI */

//GPC3_MFP
#define SYS_GPC_MFPL_GPC3_MFP_GPIO          (0x0UL<<SYS_GPC_MFPL_GPC3_MFP_Pos)       /*!< GPC_MFPL GPC3 setting for GPIO */
#define SYS_GPC_MFPL_GPC3_MFP_SPI0_MOSI0    (0x1UL<<SYS_GPC_MFPL_GPC3_MFP_Pos)       /*!< GPC_MFPL GPC3 setting for SPI0_MOSI0 */
#define SYS_GPC_MFPL_GPC3_MFP_I2S_DO        (0x2UL<<SYS_GPC_MFPL_GPC3_MFP_Pos)       /*!< GPC_MFPL GPC3 setting for I2S_DO */

//GPC4_MFP
#define SYS_GPC_MFPL_GPC4_MFP_GPIO          (0x0UL<<SYS_GPC_MFPL_GPC4_MFP_Pos)       /*!< GPC_MFPL GPC4 setting for GPIO */
#define SYS_GPC_MFPL_GPC4_MFP_SPI0_MISO1    (0x1UL<<SYS_GPC_MFPL_GPC4_MFP_Pos)       /*!< GPC_MFPL GPC4 setting for SPI0_MISO1 */
#define SYS_GPC_MFPL_GPC4_MFP_UART0_RXD     (0x2UL<<SYS_GPC_MFPL_GPC4_MFP_Pos)       /*!< GPC_MFPL GPC4 setting for UART0_RXD */

//GPC5_MFP
#define SYS_GPC_MFPL_GPC5_MFP_GPIO          (0x0UL<<SYS_GPC_MFPL_GPC5_MFP_Pos)       /*!< GPC_MFPL GPC5 setting for GPIO */
#define SYS_GPC_MFPL_GPC5_MFP_SPI0_MOSI1    (0x1UL<<SYS_GPC_MFPL_GPC5_MFP_Pos)       /*!< GPC_MFPL GPC5 setting for SPI0_MOSI1 */
#define SYS_GPC_MFPL_GPC5_MFP_UART0_TXD     (0x2UL<<SYS_GPC_MFPL_GPC5_MFP_Pos)       /*!< GPC_MFPL GPC5 setting for UART0_TXD */

//GPC8_MFP
#define SYS_GPC_MFPH_GPC8_MFP_GPIO          (0x0UL<<SYS_GPC_MFPH_GPC8_MFP_Pos)       /*!< GPC_MFPH GPC8 setting for GPIO */
#define SYS_GPC_MFPH_GPC8_MFP_SPI1_SS0      (0x1UL<<SYS_GPC_MFPH_GPC8_MFP_Pos)       /*!< GPC_MFPH GPC8 setting for SPI1_SS0 */
#define SYS_GPC_MFPH_GPC8_MFP_PWM0          (0x2UL<<SYS_GPC_MFPH_GPC8_MFP_Pos)       /*!< GPC_MFPH GPC8 setting for PWM0 */

//GPC9_MFP
#define SYS_GPC_MFPH_GPC9_MFP_GPIO          (0x0UL<<SYS_GPC_MFPH_GPC9_MFP_Pos)       /*!< GPC_MFPH GPC9 setting for GPIO */
#define SYS_GPC_MFPH_GPC9_MFP_SPI1_CLK      (0x1UL<<SYS_GPC_MFPH_GPC9_MFP_Pos)       /*!< GPC_MFPH GPC9 setting for SPI1_CLK */

//GPC10_MFP
#define SYS_GPC_MFPH_GPC10_MFP_GPIO         (0x0UL<<SYS_GPC_MFPH_GPC10_MFP_Pos)      /*!< GPC_MFPH GPC10 setting for GPIO */
#define SYS_GPC_MFPH_GPC10_MFP_SPI1_MISO0   (0x1UL<<SYS_GPC_MFPH_GPC10_MFP_Pos)      /*!< GPC_MFPH GPC10 setting for SPI1_MISO0 */

//GPC11_MFP
#define SYS_GPC_MFPH_GPC11_MFP_GPIO         (0x0UL<<SYS_GPC_MFPH_GPC11_MFP_Pos)      /*!< GPC_MFPH GPC11 setting for GPIO */
#define SYS_GPC_MFPH_GPC11_MFP_SPI1_MOSI0   (0x1UL<<SYS_GPC_MFPH_GPC11_MFP_Pos)      /*!< GPC_MFPH GPC11 setting for SPI1_MOSI0 */

//GPC12_MFP
#define SYS_GPC_MFPH_GPC12_MFP_GPIO         (0x0UL<<SYS_GPC_MFPH_GPC12_MFP_Pos)      /*!< GPC_MFPH GPC12 setting for GPIO */
#define SYS_GPC_MFPH_GPC12_MFP_SPI1_MISO1   (0x1UL<<SYS_GPC_MFPH_GPC12_MFP_Pos)      /*!< GPC_MFPH GPC12 setting for SPI1_MISO1 */
#define SYS_GPC_MFPH_GPC12_MFP_I2S_MCLK     (0x2UL<<SYS_GPC_MFPH_GPC12_MFP_Pos)      /*!< GPC_MFPH GPC12 setting for I2S_MCLK */
#define SYS_GPC_MFPH_GPC12_MFP_PWM2         (0x3UL<<SYS_GPC_MFPH_GPC12_MFP_Pos)      /*!< GPC_MFPH GPC12 setting for PWM2 */

//GPC13_MFP
#define SYS_GPC_MFPH_GPC13_MFP_GPIO         (0x0UL<<SYS_GPC_MFPH_GPC13_MFP_Pos)      /*!< GPC_MFPH GPC13 setting for GPIO */
#define SYS_GPC_MFPH_GPC13_MFP_SPI1_MOSI1   (0x1UL<<SYS_GPC_MFPH_GPC13_MFP_Pos)      /*!< GPC_MFPH GPC13 setting for SPI1_MOSI1 */
#define SYS_GPC_MFPH_GPC13_MFP_CLKO         (0x2UL<<SYS_GPC_MFPH_GPC13_MFP_Pos)      /*!< GPC_MFPH GPC13 setting for CLKO */
#define SYS_GPC_MFPH_GPC13_MFP_PWM3         (0x3UL<<SYS_GPC_MFPH_GPC13_MFP_Pos)      /*!< GPC_MFPH GPC13 setting for PWM3 */

//GPD0_MFP
#define SYS_GPD_MFPL_GPD0_MFP_GPIO          (0x0UL<<SYS_GPD_MFPL_GPD0_MFP_Pos)       /*!< GPD_MFPL GPD0 setting for GPIO */
#define SYS_GPD_MFPL_GPD0_MFP_SPI2_SS0      (0x1UL<<SYS_GPD_MFPL_GPD0_MFP_Pos)       /*!< GPD_MFPL GPD0 setting for SPI2_SS0 */
#define SYS_GPD_MFPL_GPD0_MFP_ADC0          (0x2UL<<SYS_GPD_MFPL_GPD0_MFP_Pos)       /*!< GPD_MFPL GPD0 setting for ADC0 */

//GPD1_MFP
#define SYS_GPD_MFPL_GPD1_MFP_GPIO          (0x0UL<<SYS_GPD_MFPL_GPD1_MFP_Pos)       /*!< GPD_MFPL GPD1 setting for GPIO */
#define SYS_GPD_MFPL_GPD1_MFP_SPI0_SS1      (0x1UL<<SYS_GPD_MFPL_GPD1_MFP_Pos)       /*!< GPD_MFPL GPD1 setting for SPI0_SS1 */
#define SYS_GPD_MFPL_GPD1_MFP_SPI2_CLK      (0x2UL<<SYS_GPD_MFPL_GPD1_MFP_Pos)       /*!< GPD_MFPL GPD1 setting for SPI2_CLK */
#define SYS_GPD_MFPL_GPD1_MFP_ADC1          (0x3UL<<SYS_GPD_MFPL_GPD1_MFP_Pos)       /*!< GPD_MFPL GPD1 setting for ADC1 */

//GPD2_MFP
#define SYS_GPD_MFPL_GPD2_MFP_GPIO          (0x0UL<<SYS_GPD_MFPL_GPD2_MFP_Pos)       /*!< GPD_MFPL GPD2 setting for GPIO */
#define SYS_GPD_MFPL_GPD2_MFP_SPI0_MISO1    (0x1UL<<SYS_GPD_MFPL_GPD2_MFP_Pos)       /*!< GPD_MFPL GPD2 setting for SPI0_MISO1 */
#define SYS_GPD_MFPL_GPD2_MFP_SPI2_MISO0    (0x2UL<<SYS_GPD_MFPL_GPD2_MFP_Pos)       /*!< GPD_MFPL GPD2 setting for SPI2_MISO0 */
#define SYS_GPD_MFPL_GPD2_MFP_ADC2          (0x3UL<<SYS_GPD_MFPL_GPD2_MFP_Pos)       /*!< GPD_MFPL GPD2 setting for ADC2 */

//GPD3_MFP
#define SYS_GPD_MFPL_GPD3_MFP_GPIO          (0x0UL<<SYS_GPD_MFPL_GPD3_MFP_Pos)       /*!< GPD_MFPL GPD3 setting for GPIO */
#define SYS_GPD_MFPL_GPD3_MFP_SPI0_MOSI1    (0x1UL<<SYS_GPD_MFPL_GPD3_MFP_Pos)       /*!< GPD_MFPL GPD3 setting for SPI0_MOSI1 */
#define SYS_GPD_MFPL_GPD3_MFP_SPI2_MOSI0    (0x2UL<<SYS_GPD_MFPL_GPD3_MFP_Pos)       /*!< GPD_MFPL GPD3 setting for SPI2_MOSI0 */
#define SYS_GPD_MFPL_GPD3_MFP_ADC3          (0x3UL<<SYS_GPD_MFPL_GPD3_MFP_Pos)       /*!< GPD_MFPL GPD3 setting for ADC3 */

//GPD4_MFP
#define SYS_GPD_MFPL_GPD4_MFP_GPIO          (0x0UL<<SYS_GPD_MFPL_GPD4_MFP_Pos)       /*!< GPD_MFPL GPD4 setting for GPIO */
#define SYS_GPD_MFPL_GPD4_MFP_SPI2_MISO1    (0x1UL<<SYS_GPD_MFPL_GPD4_MFP_Pos)       /*!< GPD_MFPL GPD4 setting for SPI2_MISO1 */
#define SYS_GPD_MFPL_GPD4_MFP_ADC4          (0x2UL<<SYS_GPD_MFPL_GPD4_MFP_Pos)       /*!< GPD_MFPL GPD4 setting for ADC4 */

//GPD5_MFP
#define SYS_GPD_MFPL_GPD5_MFP_GPIO          (0x0UL<<SYS_GPD_MFPL_GPD5_MFP_Pos)       /*!< GPD_MFPL GPD5 setting for GPIO */
#define SYS_GPD_MFPL_GPD5_MFP_SPI2_MOSI1    (0x1UL<<SYS_GPD_MFPL_GPD5_MFP_Pos)       /*!< GPD_MFPL GPD5 setting for SPI2_MOSI1 */
#define SYS_GPD_MFPL_GPD5_MFP_ADC5          (0x2UL<<SYS_GPD_MFPL_GPD5_MFP_Pos)       /*!< GPD_MFPL GPD5 setting for ADC5 */

//GPD8_MFP
#define SYS_GPD_MFPH_GPD8_MFP_GPIO          (0x0UL<<SYS_GPD_MFPH_GPD8_MFP_Pos)       /*!< GPD_MFPH GPD8 setting for GPIO */
#define SYS_GPD_MFPH_GPD8_MFP_SPI1_MOSI0    (0x1UL<<SYS_GPD_MFPH_GPD8_MFP_Pos)       /*!< GPD_MFPH GPD8 setting for SPI1_MOSI0 */

//GPD9_MFP
#define SYS_GPD_MFPH_GPD9_MFP_GPIO          (0x0UL<<SYS_GPD_MFPH_GPD9_MFP_Pos)       /*!< GPD_MFPH GPD9 setting for GPIO */

//GPD10_MFP
#define SYS_GPD_MFPH_GPD10_MFP_GPIO         (0x0UL<<SYS_GPD_MFPH_GPD10_MFP_Pos)      /*!< GPD_MFPH GPD10 setting for GPIO */
#define SYS_GPD_MFPH_GPD10_MFP_CLKO         (0x1UL<<SYS_GPD_MFPH_GPD10_MFP_Pos)      /*!< GPD_MFPH GPD10 setting for CLKO */

//GPD11_MFP
#define SYS_GPD_MFPH_GPD11_MFP_GPIO         (0x0UL<<SYS_GPD_MFPH_GPD11_MFP_Pos)      /*!< GPD_MFPH GPD11 setting for GPIO */
#define SYS_GPD_MFPH_GPD11_MFP_INT1         (0x1UL<<SYS_GPD_MFPH_GPD11_MFP_Pos)      /*!< GPD_MFPH GPD11 setting for INT1 */

//GPF0_MFP
#define SYS_GPF_MFPL_GPF0_MFP_GPIO          (0x0UL<<SYS_GPF_MFPL_GPF0_MFP_Pos)       /*!< GPF_MFPL GPF0 setting for GPIO */
#define SYS_GPF_MFPL_GPF0_MFP_XT1_OUT       (0x1UL<<SYS_GPF_MFPL_GPF0_MFP_Pos)       /*!< GPF_MFPL GPF0 setting for XT1_OUT */

//GPF1_MFP
#define SYS_GPF_MFPL_GPF1_MFP_GPIO          (0x0UL<<SYS_GPF_MFPL_GPF1_MFP_Pos)       /*!< GPF_MFPL GPF1 setting for GPIO */
#define SYS_GPF_MFPL_GPF1_MFP_XT1_IN        (0x1UL<<SYS_GPF_MFPL_GPF1_MFP_Pos)       /*!< GPF_MFPL GPF1 setting for XT1_IN */

//GPF2_MFP
#define SYS_GPF_MFPL_GPF2_MFP_GPIO          (0x0UL<<SYS_GPF_MFPL_GPF2_MFP_Pos)       /*!< GPF_MFPL GPF2 setting for GPIO */
#define SYS_GPF_MFPL_GPF2_MFP_PS2_DAT       (0x1UL<<SYS_GPF_MFPL_GPF2_MFP_Pos)       /*!< GPF_MFPL GPF2 setting for PS2_DAT */
#define SYS_GPF_MFPL_GPF2_MFP_I2C0_SDA      (0x2UL<<SYS_GPF_MFPL_GPF2_MFP_Pos)       /*!< GPF_MFPL GPF2 setting for I2C0_SDA */
#define SYS_GPF_MFPL_GPF2_MFP_ADC6          (0x3UL<<SYS_GPF_MFPL_GPF2_MFP_Pos)       /*!< GPF_MFPL GPF2 setting for ADC6 */

//GPF3_MFP
#define SYS_GPF_MFPL_GPF3_MFP_GPIO          (0x0UL<<SYS_GPF_MFPL_GPF3_MFP_Pos)       /*!< GPF_MFPL GPF3 setting for GPIO */
#define SYS_GPF_MFPL_GPF3_MFP_PS2_CLK       (0x1UL<<SYS_GPF_MFPL_GPF3_MFP_Pos)       /*!< GPF_MFPL GPF3 setting for PS2_CLK */
#define SYS_GPF_MFPL_GPF3_MFP_I2C0_SCL      (0x2UL<<SYS_GPF_MFPL_GPF3_MFP_Pos)       /*!< GPF_MFPL GPF3 setting for I2C0_SCL */
#define SYS_GPF_MFPL_GPF3_MFP_ADC7          (0x3UL<<SYS_GPF_MFPL_GPF3_MFP_Pos)       /*!< GPF_MFPL GPF3 setting for ADC7 */



/*@}*/ /* end of group SYS_EXPORTED_CONSTANTS */

/** @addtogroup SYS_EXPORTED_FUNCTIONS SYS Exported Functions
  @{
*/


/**
  * @brief      Clear Brown-out detector interrupt flag
  * @param      None
  * @return     None
  * @details    This macro clear Brown-out detector interrupt flag.
  */
#define SYS_CLEAR_BOD_INT_FLAG()        (SYS->BODCR |= SYS_BODCR_BOD_INTF_Msk)

/**
  * @brief      Set Brown-out detector function to normal mode
  * @param      None
  * @return     None
  * @details    This macro set Brown-out detector to normal mode.
  *             The register write-protection function should be disabled before using this macro.
  */
#define SYS_CLEAR_BOD_LPM()             (SYS->BODCR &= ~SYS_BODCR_BOD_LPM_Msk)

/**
  * @brief      Disable Brown-out detector function
  * @param      None
  * @return     None
  * @details    This macro disable Brown-out detector function.
  *             The register write-protection function should be disabled before using this macro.
  */
#define SYS_DISABLE_BOD()               (SYS->BODCR &= ~SYS_BODCR_BOD_EN_Msk)

/**
  * @brief      Enable Brown-out detector function
  * @param      None
  * @return     None
  * @details    This macro enable Brown-out detector function.
  *             The register write-protection function should be disabled before using this macro.
  */
#define SYS_ENABLE_BOD()                (SYS->BODCR |= SYS_BODCR_BOD_EN_Msk)

/**
  * @brief      Get Brown-out detector interrupt flag
  * @param      None
  * @retval     0   Brown-out detect interrupt flag is not set.
  * @retval     >=1 Brown-out detect interrupt flag is set.
  * @details    This macro get Brown-out detector interrupt flag.
  */
#define SYS_GET_BOD_INT_FLAG()          (SYS->BODCR & SYS_BODCR_BOD_INTF_Msk)

/**
  * @brief      Get Brown-out detector status
  * @param      None
  * @retval     0   System voltage is higher than BOD threshold voltage setting or BOD function is disabled.
  * @retval     >=1 System voltage is lower than BOD threshold voltage setting.
  * @details    This macro get Brown-out detector output status.
  *             If the BOD function is disabled, this function always return 0.
  */
#define SYS_GET_BOD_OUTPUT()            (SYS->BODCR & SYS_BODCR_BOD_OUT_Msk)

/**
  * @brief      Enable Brown-out detector interrupt function
  * @param      None
  * @return     None
  * @details    This macro enable Brown-out detector interrupt function.
  *             The register write-protection function should be disabled before using this macro.
  */
#define SYS_DISABLE_BOD_RST()           (SYS->BODCR &= ~SYS_BODCR_BOD_RSTEN_Msk)

/**
  * @brief      Enable Brown-out detector reset function
  * @param      None
  * @return     None
  * @details    This macro enable Brown-out detect reset function.
  *             The register write-protection function should be disabled before using this macro.
  */
#define SYS_ENABLE_BOD_RST()            (SYS->BODCR |= SYS_BODCR_BOD_RSTEN_Msk)

/**
  * @brief      Set Brown-out detector function low power mode
  * @param      None
  * @return     None
  * @details    This macro set Brown-out detector to low power mode.
  *             The register write-protection function should be disabled before using this macro.
  */
#define SYS_SET_BOD_LPM()               (SYS->BODCR |= SYS_BODCR_BOD_LPM_Msk)

/**
  * @brief      Set Brown-out detector voltage level
  * @param[in]  u32Level is Brown-out voltage level. Including :
  *             - \ref SYS_BODCR_BOD_VL_4_5V
  *             - \ref SYS_BODCR_BOD_VL_3_8V
  *             - \ref SYS_BODCR_BOD_VL_2_7V
  *             - \ref SYS_BODCR_BOD_VL_2_2V
  * @return     None
  * @details    This macro set Brown-out detector voltage level.
  *             The write-protection function should be disabled before using this macro.
  */
#define SYS_SET_BOD_LEVEL(u32Level)     (SYS->BODCR = (SYS->BODCR & ~SYS_BODCR_BOD_VL_Msk) | (u32Level))

/**
  * @brief      Get reset source is from Brown-out detector reset
  * @param      None
  * @retval     0   Previous reset source is not from Brown-out detector reset
  * @retval     >=1 Previous reset source is from Brown-out detector reset
  * @details    This macro get previous reset source is from Brown-out detect reset or not.
  */
#define SYS_IS_BOD_RST()                (SYS->RSTSRC & SYS_RSTSRC_RSTS_BOD_Msk)

/**
  * @brief      Get reset source is from CPU reset
  * @param      None
  * @retval     0   Previous reset source is not from CPU reset
  * @retval     >=1 Previous reset source is from CPU reset
  * @details    This macro get previous reset source is from CPU reset.
  */
#define SYS_IS_CPU_RST()                (SYS->RSTSRC & SYS_RSTSRC_RSTS_CPU_Msk)

/**
  * @brief      Get reset source is from Low-Voltage-Reset
  * @param      None     
  * @retval     0   Previous reset source is not from Low-Voltage-Reset
  * @retval     >=1 Previous reset source is from Low-Voltage-Reset
  * @details    This macro get previous reset source is from Low-Voltage-Reset.   
  */
#define SYS_IS_LVR_RST()                (SYS->RSTSRC & SYS_RSTSRC_RSTS_LVR_Msk)

/**
  * @brief      Get reset source is from Power-on Reset
  * @param      None
  * @retval     0   Previous reset source is not from Power-on Reset
  * @retval     >=1 Previous reset source is from Power-on Reset
  * @details    This macro get previous reset source is from Power-on Reset.
  */
#define SYS_IS_POR_RST()                (SYS->RSTSRC & SYS_RSTSRC_RSTS_POR_Msk)

/**
  * @brief      Get reset source is from reset pin reset
  * @param      None
  * @retval     0   Previous reset source is not from reset pin reset
  * @retval     >=1 Previous reset source is from reset pin reset
  * @details    This macro get previous reset source is from reset pin reset.
  */
#define SYS_IS_RSTPIN_RST()             (SYS->RSTSRC & SYS_RSTSRC_RSTS_RESET_Msk)

/**
  * @brief      Get reset source is from system reset
  * @param      None
  * @retval     0   Previous reset source is not from system reset
  * @retval     >=1 Previous reset source is from system reset
  * @details    This macro get previous reset source is from system reset.
  */
#define SYS_IS_SYSTEM_RST()             (SYS->RSTSRC & SYS_RSTSRC_RSTS_SYS_Msk)

/**
  * @brief      Get reset source is from window watch dog reset
  * @param      None
  * @retval     0   Previous reset source is not from window watch dog reset
  * @retval     >=1 Previous reset source is from window watch dog reset
  * @details    This macro get previous reset source is from window watch dog reset.
  */
#define SYS_IS_WDT_RST()                (SYS->RSTSRC & SYS_RSTSRC_RSTS_WDT_Msk)

/**
  * @brief      Disable Low-Voltage-Reset function
  * @param      None
  * @return     None
  * @details    This macro disable Low-Voltage-Reset function.
  *             The register write-protection function should be disabled before using this macro.
  */
#define SYS_DISABLE_LVR()               (SYS->BODCR &= ~SYS_BODCR_LVR_EN_Msk)

/**
  * @brief      Enable Low-Voltage-Reset function
  * @param      None
  * @return     None
  * @details    This macro enable Low-Voltage-Reset function.
  *             The register write-protection function should be disabled before using this macro.
  */
#define SYS_ENABLE_LVR()                (SYS->BODCR |= SYS_BODCR_LVR_EN_Msk)

/**
  * @brief      Disable Power-on Reset function
  * @param      None
  * @return     None
  * @details    This macro disable Power-on Reset function.
  *             The register write-protection function should be disabled before using this macro.
  */
#define SYS_DISABLE_POR()               (SYS->PORCR = 0x5AA5)

/**
  * @brief      Enable Power-on Reset function
  * @param      None
  * @return     None
  * @details    This macro enable Power-on Reset function.
  *             The register write-protection function should be disabled before using this macro.
  */
#define SYS_ENABLE_POR()                (SYS->PORCR = 0)

/**
  * @brief      Clear reset source flag
  * @param[in]  u32RstSrc is reset source. Including:
  *             - \ref SYS_RSTSRC_RSTS_CPU_Msk
  *             - \ref SYS_RSTSRC_RSTS_SYS_Msk
  *             - \ref SYS_RSTSRC_RSTS_BOD_Msk
  *             - \ref SYS_RSTSRC_RSTS_LVR_Msk
  *             - \ref SYS_RSTSRC_RSTS_WDT_Msk
  *             - \ref SYS_RSTSRC_RSTS_RESET_Msk
  *             - \ref SYS_RSTSRC_RSTS_POR_Msk
  * @return     None
  * @details    This macro clear reset source flag.
  */
#define SYS_CLEAR_RST_SOURCE(u32RstSrc) (SYS->RSTSRC = (u32RstSrc) )


/**
  * @brief      Enable register write-protection function
  * @param      None
  * @return     None
  * @details    This function enable register write-protection function.
  *             To lock the protected register to forbid write access.
  */
static __INLINE void SYS_LockReg(void)
{
    SYS->REGWRPROT = 0;
}

/**
  * @brief      Disable register write-protection function
  * @param      None
  * @return     None
  * @details    This function disable register write-protection function.
  *             To unlock the protected register to allow write access.
  *
  */
static __INLINE void SYS_UnlockReg(void)
{
    while(SYS->REGWRPROT != SYS_REGWRPROT_REGPROTDIS_Msk)
    {
        SYS->REGWRPROT = 0x59;
        SYS->REGWRPROT = 0x16;
        SYS->REGWRPROT = 0x88;
    }
}


void SYS_ClearResetSrc(uint32_t u32Src);
uint32_t SYS_GetBODStatus(void);
uint32_t SYS_GetResetSrc(void);
uint32_t SYS_IsRegLocked(void);
uint32_t  SYS_ReadPDID(void);
void SYS_ResetChip(void);
void SYS_ResetCPU(void);
void SYS_ResetModule(uint32_t u32ModuleIndex);
void SYS_EnableBOD(int32_t i32Mode, uint32_t u32BODLevel);
void SYS_DisableBOD(void);


/*@}*/ /* end of group SYS_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group SYS_Driver */

/*@}*/ /* end of group Standard_Driver */


#ifdef __cplusplus
}
#endif

#endif //__SYS_H__

/*** (C) COPYRIGHT 2014~2015 Nuvoton Technology Corp. ***/
