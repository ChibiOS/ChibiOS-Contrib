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
 * @file    SN32F240/sn32_sys1.h
 * @brief   SYS1 helper driver header.
 * @note    This file requires definitions from the SN32 header file
 *          @p SN32F240.h.
 *
 * @addtogroup SN32F24x_SYS1
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
 * @param[in] mask      APB0 peripherals mask
 *
 * @api
 */
#define sys1SelectAPB0(mask) {                                             \
  SN_SYS1->APBCP0 |= (mask);                                               \
  (void)SN_SYS1->APBCP0;                                                   \
}

/**
 * @brief   Selects the clock prescaler of one or more peripheral on the APB1 bus.
 *
 * @param[in] mask      APB1 peripherals mask
 *
 * @api
 */
#define sys1SelectAPB1(mask) {                                             \
  SN_SYS1->APBCP1 |= (mask);                                               \
  (void)SN_SYS1->APBCP1;                                                   \
}

/**
 * @brief   Selects the clock prescaler of one or more peripheral on the APB bus.
 *
 * @param[in] mask      APB2 peripherals mask
 *
 * @api
 */
#define sys1SelectAPB2(mask) {                                             \
  SN_SYS1->APBCP2 |= (mask);                                               \
  (void)SN_SYS1->APBCP2;                                                   \
}
/** @} */

/**
 * @name    GPIO peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the GPIO peripheral clock.
 *
 * @api
 */
#define sys1EnableGPIO() sys1EnableAHB(0x1<<0)

/**
 * @brief   Disables the GPIO peripheral clock.
 *
 * @api
 */
#define sys1DisableGPIO() sys1DisableAHB(0x1<<0)

/**
 * @brief   Resets the GPIOP0 peripheral.
 *
 * @api
 */
#define sys1ResetGPIOP0() sys1Reset(0x1<<0)

/**
 * @brief   Resets the GPIOP1 peripheral.
 *
 * @api
 */
#define sys1ResetGPIOP1() sys1Reset(0x1<<1)

/**
 * @brief   Resets the GPIOP2 peripheral.
 *
 * @api
 */
#define sys1ResetGPIOP2() sys1Reset(0x1<<2)

/**
 * @brief   Resets the GPIOP3 peripheral.
 *
 * @api
 */
#define sys1ResetGPIOP3() sys1Reset(0x1<<3)

/**
 * @name    USB peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the USB peripheral clock.
 *
 * @api
 */
#define sys1EnableUSB() sys1EnableAHB(0x1<<1)

/**
 * @brief   Disables the USB peripheral clock.
 *
 * @api
 */
#define sys1DisableUSB() sys1DisableAHB(0x1<<1)

/**
 * @brief   Resets the USB peripheral.
 *
 * @api
 */
#define sys1ResetUSB() sys1Reset(0x1<<25)

/**
 * @name    LCD peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the LCD peripheral clock.
 *
 * @api
 */
#define sys1EnableLCD() sys1EnableAHB(0x1<<2)

/**
 * @brief   Disables the LCD peripheral clock.
 *
 * @api
 */
#define sys1DisableLCD() sys1DisableAHB(0x1<<2)

/**
 * @brief   Resets the LCD peripheral.
 *
 * @api
 */
#define sys1ResetLCD() sys1Reset(0x1<<15)

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
 * @brief   Configures the CT16B0 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectCT16B0PRE(pre) {                                          \
  if(pre > 0)                                                               \
  sys1SelectAPB0(pre<<0)                                                    \
}

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
 * @brief   Configures the CT16B1 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectCT16B1PRE(pre) {                                          \
  if(pre > 0)                                                               \
  sys1SelectAPB0(pre<<4)                                                    \
}

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
 * @brief   Configures the CT16B2 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectCT16B2PRE(pre) {                                          \
  if(pre > 0)                                                               \
  sys1SelectAPB1(pre<<28)                                                   \
}

/**
 * @name    CT32B0 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the CT32B0 peripheral clock.
 *
 * @api
 */
#define sys1EnableCT32B0() sys1EnableAHB(0x1<<8)

/**
 * @brief   Disables the CT32B0 peripheral clock.
 *
 * @api
 */
#define sys1DisableCT32B0() sys1DisableAHB(0x1<<8)

/**
 * @brief   Resets the CT32B0 peripheral.
 *
 * @api
 */
#define sys1ResetCT32B0() sys1Reset(0x1<<8)

/**
 * @brief   Configures the CT32B0 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectCT32B0PRE(pre) {                                          \
  if(pre > 0)                                                               \
  sys1SelectAPB0(pre<<8)                                                    \
}

/**
 * @name    CT32B1 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the CT32B1 peripheral clock.
 *
 * @api
 */
#define sys1EnableCT32B1() sys1EnableAHB(0x1<<9)

/**
 * @brief   Disables the CT32B1 peripheral clock.
 *
 * @api
 */
#define sys1DisableCT32B1() sys1DisableAHB(0x1<<9)

/**
 * @brief   Resets the CT32B1 peripheral.
 *
 * @api
 */
#define sys1ResetCT32B1() sys1Reset(0x1<<9)

/**
 * @brief   Configures the CT32B1 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectCT32B1PRE(pre) {                                          \
  if(pre > 0)                                                               \
  sys1SelectAPB0(pre<<12)                                                   \
}

/**
 * @name    CT32B2 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the CT32B2 peripheral clock.
 *
 * @api
 */
#define sys1EnableCT32B2() sys1EnableAHB(0x1<<10)

/**
 * @brief   Disables the CT32B2 peripheral clock.
 *
 * @api
 */
#define sys1DisableCT32B2() sys1DisableAHB(0x1<<10)

/**
 * @brief   Resets the CT32B2 peripheral.
 *
 * @api
 */
#define sys1ResetCT32B2() sys1Reset(0x1<<10)

/**
 * @brief   Configures the CT32B2 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectCT32B2PRE(pre) {                                          \
  if(pre > 0)                                                               \
  sys1SelectAPB0(pre<<28)                                                   \
}

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
 * @brief   Configures the ADC peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectADCPRE(pre) {                                             \
  if(pre > 0)                                                               \
  sys1SelectAPB0(pre<<16)                                                   \
}

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
 * @brief   Configures the SPI0 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectSPI0PRE(pre) {                                            \
  if(pre > 0)                                                               \
  sys1SelectAPB0(pre<<20)                                                   \
}

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
 * @brief   Configures the SPI1 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectSPI1PRE(pre) {                                            \
  if(pre > 0)                                                               \
  sys1SelectAPB0(pre<<24)                                                   \
}

/**
 * @name    USART0 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the USART0 peripheral clock.
 *
 * @api
 */
#define sys1EnableUSART0() sys1EnableAHB(0x1<<16)

/**
 * @brief   Disables the USART0 peripheral clock.
 *
 * @api
 */
#define sys1DisableUSART0() sys1DisableAHB(0x1<<16)

/**
 * @brief   Resets the USART0 peripheral.
 *
 * @api
 */
#define sys1ResetUSART0() sys1Reset(0x1<<16)

/**
 * @brief   Configures the USART0 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectUSART0PRE(pre) {                                          \
  if(pre > 0)                                                               \
  sys1SelectAPB1(pre<<0)                                                    \
}

/**
 * @name    USART1 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the USART1 peripheral clock.
 *
 * @api
 */
#define sys1EnableUSART1() sys1EnableAHB(0x1<<17)

/**
 * @brief   Disables the USART1 peripheral clock.
 *
 * @api
 */
#define sys1DisableUSART1() sys1DisableAHB(0x1<<17)

/**
 * @brief   Resets the USART1 peripheral.
 *
 * @api
 */
#define sys1ResetUSART1() sys1Reset(0x1<<17)

/**
 * @brief   Configures the USART1 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectUSART1PRE(pre) {                                          \
  if(pre > 0)                                                               \
  sys1SelectAPB1(pre<<4)                                                    \
}

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
 * @brief   Configures the I2C1 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectI2C1PRE(pre) {                                            \
  if(pre > 0)                                                               \
  sys1SelectAPB1(pre<<24)                                                   \
}

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
 * @brief   Configures the I2C0 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectI2C0PRE(pre) {                                            \
  if(pre > 0)                                                               \
  sys1SelectAPB1(pre<<8)                                                    \
}

/**
 * @name    I2S peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the I2S peripheral clock.
 *
 * @api
 */
#define sys1EnableI2S() sys1EnableAHB(0x1<<22)

/**
 * @brief   Disables the I2S peripheral clock.
 *
 * @api
 */
#define sys1DisableI2S() sys1DisableAHB(0x1<<22)

/**
 * @brief   Resets the I2S peripheral.
 *
 * @api
 */
#define sys1ResetI2S() sys1Reset(0x1<<22)

/**
 * @brief   Configures the I2S peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectI2SPRE(pre) {                                             \
  if(pre > 0)                                                               \
  sys1SelectAPB1(pre<<12)                                                   \
}

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
 * @brief   Configures the WDT peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectWDTPRE(pre) {                                             \
  if(pre > 0)                                                               \
  sys1SelectAPB1(pre<<20)                                                   \
}

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
 * @brief   Configures the CLKOUT peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectCLKOUTPRE(pre) {                                          \
  if(pre > 0)                                                               \
  sys1SelectAPB2(pre<<0)                                                    \
}

/**
 * @brief   Configures the SYSTICK peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectSYSTICKPRE(pre) {                                         \
  if(pre > 0)                                                               \
  sys1SelectAPB1(pre<<16)                                                   \
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
