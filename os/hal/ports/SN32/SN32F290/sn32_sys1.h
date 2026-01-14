/*
    Copyright (C) 2024 Dimitris Mantzouranis

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
 * @file    SN32F290/sn32_sys1.h
 * @brief   SYS1 helper driver header.
 * @note    This file requires definitions from the SN32 header file
 *          @p SN32F290.h.
 *
 * @addtogroup SN32F29x_SYS1
 * @{
 */

#ifndef SN32_SYS1_H
#define SN32_SYS1_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

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

/**
 * @name    Generic AHB operations
 * @{
 */
/**
 * @brief   Enables the clock of one or more peripheral on the AHB bus.
 *
 * @param[in] mask      AHB peripherals mask
 *
 * @api
 */
#define sys1EnableAHB(mask) {                                               \
  SN_SYS1->AHBCLKEN |= (mask);                                              \
  (void)SN_SYS1->AHBCLKEN;                                                  \
}

/**
 * @brief   Disables the clock of one or more peripheral on the AHB bus.
 *
 * @param[in] mask      AHB peripherals mask
 *
 * @api
 */
#define sys1DisableAHB(mask) {                                              \
  SN_SYS1->AHBCLKEN &= ~(mask);                                             \
  (void)SN_SYS1->AHBCLKEN;                                                  \
}

/**
 * @brief   Resets one or more peripheral.
 *
 * @param[in] mask      Reset peripherals mask
 *
 * @api
 */
#define sys1Reset(mask) {                                                   \
  SN_SYS1->PRST |= (mask);                                                  \
  SN_SYS1->PRST &= ~(mask);                                                 \
  (void)SN_SYS1->PRST;                                                      \
}

/**
 * @brief   Selects the clock prescaler of one or more peripheral on the APB0 bus.
 *
 * @param[in] mask      APB peripherals mask
 *
 * @api
 */
#define sys1SelectAPB0(mask) {                                             \
  SN_SYS1->APBCP0 |= (mask);                                              \
  (void)SN_SYS1->APBCP0;                                                  \
}

/**
 * @brief   Selects the clock prescaler of one or more peripheral on the APB1 bus.
 *
 * @param[in] mask      APB peripherals mask
 *
 * @api
 */
#define sys1SelectAPB1(mask) {                                             \
  SN_SYS1->APBCP1 |= (mask);                                              \
  (void)SN_SYS1->APBCP1;                                                  \
}

/** @} */
/**
 * @name    Dummy peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the GPIO peripherals clock.
 *
 * @api
 */
#define sys1EnableGPIO0()
#define sys1EnableGPIO1()
#define sys1EnableGPIO2()
#define sys1EnableGPIO3()
/**
 * @brief   Disables the GPIO peripherals clock.
 *
 * @api
 */
#define sys1DisableGPIO0()
#define sys1DisableGPIO1()
#define sys1DisableGPIO2()
#define sys1DisableGPIO3()

/** @} */

/**
 * @name    GPIO peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Resets the GPIO0 peripheral.
 *
 * @api
 */
#define sys1ResetGPIO0() sys1Reset(0x1<<0)

/**
 * @brief   Resets the GPIO1 peripheral.
 *
 * @api
 */
#define sys1ResetGPIO1() sys1Reset(0x1<<1)

/**
 * @brief   Resets the GPIO2 peripheral.
 *
 * @api
 */
#define sys1ResetGPIO2() sys1Reset(0x1<<2)

/**
 * @brief   Resets the GPIO3 peripheral.
 *
 * @api
 */
#define sys1ResetGPIO3() sys1Reset(0x1<<3)

/**
 * @name    OPA peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the OPA peripheral clock.
 *

 *
 * @api
 */
#define sys1EnableOPA() sys1EnableAHB(0x1<<3)

/**
 * @brief   Disables the OPA peripheral clock.
 *
 * @api
 */
#define sys1DisableOPA() sys1DisableAHB(0x1<<3)

/**
 * @brief   Resets the OPA peripheral.
 *
 * @api
 */
#define sys1ResetOPA() sys1Reset(0x1<<28)

/**
 * @name    USB peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the USB peripheral clock.
 *
 * @api
 */
#define sys1EnableUSB() sys1EnableAHB(0x1<<4)

/**
 * @brief   Disables the USB peripheral clock.
 *
 * @api
 */
#define sys1DisableUSB() sys1DisableAHB(0x1<<4)

/**
 * @name    CT16B0 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the CT16B0 peripheral clock.
 *
 * @api
 */
#define sys1EnableCT16B0() sys1EnableAHB(0x1<<5)

/**
 * @brief   Disables the CT16B0 peripheral clock.
 *
 * @api
 */
#define sys1DisableCT16B0() sys1DisableAHB(0x1<<5)

/**
 * @brief   Resets the CT16B0 peripheral.
 *
 * @api
 */
#define sys1ResetCT16B0() sys1Reset(0x1<<5)

/**
 * @name    CT16B1 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the CT16B1 peripheral clock.
 *
 * @api
 */
#define sys1EnableCT16B1() sys1EnableAHB(0x1<<6)

/**
 * @brief   Disables the CT16B1 peripheral clock.
 *
 * @api
 */
#define sys1DisableCT16B1() sys1DisableAHB(0x1<<6)

/**
 * @brief   Resets the CT16B1 peripheral.
 *
 * @api
 */
#define sys1ResetCT16B1() sys1Reset(0x1<<6)

/**
 * @name    CT16B2 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the CT16B2 peripheral clock.
 *
 * @api
 */
#define sys1EnableCT16B2() sys1EnableAHB(0x1<<7)

/**
 * @brief   Disables the CT16B2 peripheral clock.
 *
 * @api
 */
#define sys1DisableCT16B2() sys1DisableAHB(0x1<<7)

/**
 * @brief   Resets the CT16B2 peripheral.
 *
 * @api
 */
#define sys1ResetCT16B2() sys1Reset(0x1<<7)

/**
 * @name    CT16B3 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the CT16B3 peripheral clock.
 *
 * @api
 */
#define sys1EnableCT16B3() sys1EnableAHB(0x1<<8)

/**
 * @brief   Disables the CT16B3 peripheral clock.
 *
 * @api
 */
#define sys1DisableCT16B3() sys1DisableAHB(0x1<<8)

/**
 * @brief   Resets the CT16B3 peripheral.
 *
 * @api
 */
#define sys1ResetCT16B3() sys1Reset(0x1<<8)

/**
 * @name    CT16B4 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the CT16B4 peripheral clock.
 *
 * @api
 */
#define sys1EnableCT16B4() sys1EnableAHB(0x1<<9)

/**
 * @brief   Disables the CT16B4 peripheral clock.
 *
 * @api
 */
#define sys1DisableCT16B4() sys1DisableAHB(0x1<<9)

/**
 * @brief   Resets the CT16B4 peripheral.
 *
 * @api
 */
#define sys1ResetCT16B4() sys1Reset(0x1<<9)

/**
 * @name    CT16B5 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the CT16B5 peripheral clock.
 *
 * @api
 */
#define sys1EnableCT16B5() sys1EnableAHB(0x1<<10)

/**
 * @brief   Disables the CT16B5 peripheral clock.
 *
 * @api
 */
#define sys1DisableCT16B5() sys1DisableAHB(0x1<<10)

/**
 * @brief   Resets the CT16B5 peripheral.
 *
 * @api
 */
#define sys1ResetCT16B5() sys1Reset(0x1<<10)

/**
 * @name    ADC peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the ADC peripheral clock.
 *
 * @api
 */
#define sys1EnableADC() sys1EnableAHB(0x1<<11)

/**
 * @brief   Disables the ADC peripheral clock.
 *
 * @api
 */
#define sys1DisableADC() sys1DisableAHB(0x1<<11)

/**
 * @brief   Resets the ADC peripheral.
 *
 * @api
 */
#define sys1ResetADC() sys1Reset(0x1<<11)

/**
 * @name    SPI0 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the SPI0 peripheral clock.
 *
 * @api
 */
#define sys1EnableSPI0() sys1EnableAHB(0x1<<12)

/**
 * @brief   Disables the SPI0 peripheral clock.
 *
 * @api
 */
#define sys1DisableSPI0() sys1DisableAHB(0x1<<12)

/**
 * @brief   Resets the SPI0 peripheral.
 *
 * @api
 */
#define sys1ResetSPI0() sys1Reset(0x1<<12)

/**
 * @name    SPI1 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the SPI1 peripheral clock.
 *
 * @api
 */
#define sys1EnableSPI1() sys1EnableAHB(0x1<<13)

/**
 * @brief   Disables the SPI1 peripheral clock.
 *
 * @api
 */
#define sys1DisableSPI1() sys1DisableAHB(0x1<<13)

/**
 * @brief   Resets the SPI1 peripheral.
 *
 * @api
 */
#define sys1ResetSPI1() sys1Reset(0x1<<13)

/**
 * @name    CMP peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the CMP peripheral clock.
 *
 * @api
 */
#define sys1EnableCMP() sys1EnableAHB(0x1<<14)

/**
 * @brief   Disables the CMP peripheral clock.
 *
 * @api
 */
#define sys1DisableCMP() sys1DisableAHB(0x1<<14)

/**
 * @brief   Resets the CMP peripheral.
 *
 * @api
 */
#define sys1ResetCMP() sys1Reset(0x1<<14)

/**
 * @name    EBI peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the EBI peripheral clock.
 *
 * @api
 */
#define sys1EnableEBI() sys1EnableAHB(0x1<<15)

/**
 * @brief   Disables the EBI peripheral clock.
 *
 * @api
 */
#define sys1DisableEBI() sys1DisableAHB(0x1<<15)

/**
 * @brief   Resets the EBI peripheral.
 *
 * @api
 */
#define sys1ResetEBI() sys1Reset(0x1<<4)

/**
 * @name    UART0 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the UART0 peripheral clock.
 *
 * @api
 */
#define sys1EnableUART0() sys1EnableAHB(0x1<<16)

/**
 * @brief   Disables the UART0 peripheral clock.
 *
 * @api
 */
#define sys1DisableUART0() sys1DisableAHB(0x1<<16)

/**
 * @brief   Resets the UART0 peripheral.
 *
 * @api
 */
#define sys1ResetUART0() sys1Reset(0x1<<16)

/**
 * @name    UART1 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the UART1 peripheral clock.
 *
 * @api
 */
#define sys1EnableUART1() sys1EnableAHB(0x1<<17)

/**
 * @brief   Disables the UART1 peripheral clock.
 *
 * @api
 */
#define sys1DisableUART1() sys1DisableAHB(0x1<<17)

/**
 * @brief   Resets the UART1 peripheral.
 *
 * @api
 */
#define sys1ResetUART1() sys1Reset(0x1<<17)

/**
 * @name    UART2 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the UART2 peripheral clock.
 *
 * @api
 */
#define sys1EnableUART2() sys1EnableAHB(0x1<<18)

/**
 * @brief   Disables the UART2 peripheral clock.
 *
 * @api
 */
#define sys1DisableUART2() sys1DisableAHB(0x1<<18)

/**
 * @brief   Resets the UART2 peripheral.
 *
 * @api
 */
#define sys1ResetUART2() sys1Reset(0x1<<18)

/**
 * @name    UART3 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the UART3 peripheral clock.
 *
 * @api
 */
#define sys1EnableUART3() sys1EnableAHB(0x1<<19)

/**
 * @brief   Resets the UART3 peripheral.
 *
 * @api
 */
#define sys1ResetUART3() sys1Reset(0x1<<19)

/**
 * @brief   Disables the UART3 peripheral clock.
 *
 * @api
 */
#define sys1DisableUART3() sys1DisableAHB(0x1<<19)

/**
 * @name    I2C0 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the I2C0 peripheral clock.
 *
 * @api
 */
#define sys1EnableI2C0() sys1EnableAHB(0x1<<21)

/**
 * @brief   Disables the I2C0 peripheral clock.
 *
 * @api
 */
#define sys1DisableI2C0() sys1DisableAHB(0x1<<21)

/**
 * @brief   Resets the I2C0 peripheral.
 *
 * @api
 */
#define sys1ResetI2C0() sys1Reset(0x1<<21)

/**
 * @name    I2C1 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the I2C1 peripheral clock.
 *
 * @api
 */
#define sys1EnableI2C1() sys1EnableAHB(0x1<<20)

/**
 * @brief   Disables the I2C1 peripheral clock.
 *
 * @api
 */
#define sys1DisableI2C1() sys1DisableAHB(0x1<<20)

/**
 * @brief   Resets the I2C1 peripheral.
 *
 * @api
 */
#define sys1ResetI2C1() sys1Reset(0x1<<20)

/**
 * @name    I2S0 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the I2S0 peripheral clock.
 *
 * @api
 */
#define sys1EnableI2S0() sys1EnableAHB(0x1<<22)

/**
 * @brief   Disables the I2S0 peripheral clock.
 *
 * @api
 */
#define sys1DisableI2S0() sys1DisableAHB(0x1<<22)

/**
 * @brief   Resets the I2S0 peripheral.
 *
 * @api
 */
#define sys1ResetI2S0() sys1Reset(0x1<<22)

/**
 * @name    RTC peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the RTC peripheral clock.
 *
 * @api
 */
#define sys1EnableRTC() sys1EnableAHB(0x1<<23)

/**
 * @brief   Disables the RTC peripheral clock.
 *
 * @api
 */
#define sys1DisableRTC() sys1DisableAHB(0x1<<23)

/**
 * @brief   Resets the RTC peripheral.
 *
 * @api
 */
#define sys1ResetRTC() sys1Reset(0x1<<23)

/**
 * @name    WDT peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the WDT peripheral clock.
 *
 * @api
 */
#define sys1EnableWDT() sys1EnableAHB(0x1<<24)

/**
 * @brief   Disables the WDT peripheral clock.
 *
 * @api
 */
#define sys1DisableWDT() sys1DisableAHB(0x1<<24)

/**
 * @brief   Resets the WDT peripheral.
 *
 * @api
 */
#define sys1ResetWDT() sys1Reset(0x1<<24)

/**
 * @name    I2S1 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the I2S1 peripheral clock.
 *
 * @api
 */
#define sys1EnableI2S1() sys1EnableAHB(0x1<<25)

/**
 * @brief   Disables the I2S1 peripheral clock.
 *
 * @api
 */
#define sys1DisableI2S1() sys1DisableAHB(0x1<<25)

/**
 * @brief   Resets the I2S1 peripheral.
 *
 * @api
 */
#define sys1ResetI2S1() sys1Reset(0x1<<25)

/**
 * @name    LCD peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the LCD peripheral clock.
 *
 * @api
 */
#define sys1EnableLCD() sys1EnableAHB(0x1<<26)

/**
 * @brief   Disables the LCD peripheral clock.
 *
 * @api
 */
#define sys1DisableLCD() sys1DisableAHB(0x1<<26)

/**
 * @brief   Resets the LCD peripheral.
 *
 * @api
 */
#define sys1ResetLCD() sys1Reset(0x1<<15)

/**
 * @name    CRC peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the CRC peripheral clock.
 *
 * @api
 */
#define sys1EnableCRC() sys1EnableAHB(0x1<<27)

/**
 * @brief   Disables the CRC peripheral clock.
 *
 * @api
 */
#define sys1DisableCRC() sys1DisableAHB(0x1<<27)

/**
 * @brief   Resets the CRC peripheral.
 *
 * @api
 */
#define sys1ResetCRC() sys1Reset(0x1<<26)

/**
 * @name    CLKOUT peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the CLKOUT peripheral clock.
  *
 * @param[in] clkval clock output source
 * * @api
 */
#define sys1EnableCLKOUT(clkval) {                                          \
  if(clkval > 0)                                                            \
  sys1EnableAHB(clkval<<28)                                                 \
}

/**
 * @brief   Disables the CLKOUT peripheral clock.
 *
 * @api
 */
#define sys1DisableCLKOUT() {                                               \
  SN_SYS1->AHBCLKEN_b.CLKOUTSEL= 0;                                         \
  (void)SN_SYS1->AHBCLKEN;                                                  \
}

/**
 * @brief   Configures the I2C0 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectI2C0PRE(pre) {                                             \
  if(pre > 0)                                                               \
  sys1SelectAPB1(pre<<8)                                                    \
}

/**
 * @brief   Configures the I2S0 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectI2S0PRE(pre) {                                             \
  if(pre > 0)                                                               \
  sys1SelectAPB1(pre<<12)                                                    \
}

/**
 * @brief   Configures the I2S1 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectI2S1PRE(pre) {                                             \
  if(pre > 0)                                                               \
  sys1SelectAPB1(pre<<15)                                                    \
}

/**
 * @brief   Configures the WDT peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectWDTPRE(pre) {                                             \
  if(pre > 0)                                                               \
  sys1SelectAPB1(pre<<20)                                                    \
}

/**
 * @brief   Configures the I2C1 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectI2C1PRE(pre) {                                             \
  if(pre > 0)                                                               \
  sys1SelectAPB1(pre<<24)                                                    \
}

/**
 * @brief   Configures the CLKOUT peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectCLKOUTPRE(pre) {                                           \
  if(pre > 0)                                                                \
  sys1SelectAPB1(pre<<28)                                                     \
}

/**
 * @brief   Configures the ADC peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectADCPRE(pre) {                                             \
  if(pre > 0)                                                               \
  sys1SelectAPB0(pre<<16)                                                    \
}
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif

#endif /* SN32_SYS1_H */

/** @} */
