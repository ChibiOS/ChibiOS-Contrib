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
 * @file    SN32F240C/sn32_sys1.h
 * @brief   SYS1 helper driver header.
 * @note    This file requires definitions from the SN32 header file
 *          @p SN32F240C.h.
 *
 * @addtogroup SN32F24xC_SYS1
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
 * @brief   Selects the clock prescaler of one or more peripheral on the APB0 bus.
 *
 * @param[in] mask      APB0 peripherals mask
 *
 * @api
 */
#define sys1SelectAPB0(mask) {                                            \
  SN_SYS1->APBCP0 |= (mask);                                              \
  (void)SN_SYS1->APBCP0;                                                  \
}

/**
 * @brief   Selects the clock prescaler of one or more peripheral on the APB1 bus.
 *
 * @param[in] mask      APB1 peripherals mask
 *
 * @api
 */
#define sys1SelectAPB1(mask) {                                            \
  SN_SYS1->APBCP1 |= (mask);                                              \
  (void)SN_SYS1->APBCP1;                                                  \
}

/** @} */
/**
 * @name    Dummy GPIO peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the GPIO peripherals clock.
 *
 * @api
 */
#define sys1EnableP0()
#define sys1EnableP1()
#define sys1EnableP2()
#define sys1EnableP3()
/**
 * @brief   Disables the GPIO peripherals clock.
 *
 * @api
 */
#define sys1DisableP0()
#define sys1DisableP1()
#define sys1DisableP2()
#define sys1DisableP3()

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
#define sys1EnableCT16B0() sys1EnableAHB(0x1<<6)

/**
 * @brief   Disables the CT16B0 peripheral clock.
 *
 * @api
 */
#define sys1DisableCT16B0() sys1DisableAHB(0x1<<6)

/**
 * @name    CT16B1 peripherals specific SYS1 operations
 * @{
 */
/**
 * @brief   Enables the CT16B1 peripheral clock.
 *
 * @api
 */
#define sys1EnableCT16B1() sys1EnableAHB(0x1<<7)

/**
 * @brief   Disables the CT16B0 peripheral clock.
 *
 * @api
 */
#define sys1DisableCT16B1() sys1DisableAHB(0x1<<7)

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
 * @brief   Configures the I2C0 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectI2C0PRE(pre) {                                             \
  if(pre > 0)                                                               \
  sys1SelectAPB1(pre<<8)                                                   \
}

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
 * @brief   Configures the I2C1 peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectI2C1PRE(pre) {                                             \
  if(pre > 0)                                                               \
  sys1SelectAPB1(pre<<24)                                                   \
}

/**
 * @brief   Configures the CLKOUT peripheral clock.
  *
 * @param[in] pre clock source prescaler
 * * @api
 */
#define sys1SelectCLKOUTPRE(pre) {                                           \
  if(pre > 0)                                                                \
  sys1SelectAPB1(pre<<28)                                                    \
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
