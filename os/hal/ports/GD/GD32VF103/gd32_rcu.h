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
 * @file    STM32F1xx/gd32_rcu.h
 * @brief   RCU helper driver header.
 * @note    This file requires definitions from the ST header file
 *          @p stm32f10x.h.
 *
 * @addtogroup STM32F1xx_RCU
 * @{
 */

#ifndef GD32_RCU_H
#define GD32_RCU_H

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
 * @name    Generic RCU operations
 * @{
 */
/**
 * @brief   Enables the clock of one or more peripheral on the APB1 bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      APB1 peripherals mask
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableAPB1(mask, lp) {                                           \
  RCU->APB1EN |= (mask);                                                   \
  (void)RCU->APB1EN;                                                       \
}

/**
 * @brief   Disables the clock of one or more peripheral on the APB1 bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      APB1 peripherals mask
 *
 * @api
 */
#define rcuDisableAPB1(mask) {                                              \
  RCU->APB1EN &= ~(mask);                                                  \
  (void)RCU->APB1EN;                                                       \
}

/**
 * @brief   Resets one or more peripheral on the APB1 bus.
 *
 * @param[in] mask      APB1 peripherals mask
 *
 * @api
 */
#define rcuResetAPB1(mask) {                                                \
  RCU->APB1RST |= (mask);                                                  \
  RCU->APB1RST &= ~(mask);                                                 \
  (void)RCU->APB1RST;                                                      \
}

/**
 * @brief   Enables the clock of one or more peripheral on the APB2 bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      APB2 peripherals mask
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableAPB2(mask, lp) {                                           \
  RCU->APB2EN |= (mask);                                                   \
  (void)RCU->APB2EN;                                                       \
}

/**
 * @brief   Disables the clock of one or more peripheral on the APB2 bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      APB2 peripherals mask
 *
 * @api
 */
#define rcuDisableAPB2(mask) {                                              \
  RCU->APB2EN &= ~(mask);                                                  \
  (void)RCU->APB2EN;                                                       \
}

/**
 * @brief   Resets one or more peripheral on the APB2 bus.
 *
 * @param[in] mask      APB2 peripherals mask
 *
 * @api
 */
#define rcuResetAPB2(mask) {                                                \
  RCU->APB2RST |= (mask);                                                  \
  RCU->APB2RST &= ~(mask);                                                 \
  (void)RCU->APB2RST;                                                      \
}

/**
 * @brief   Enables the clock of one or more peripheral on the AHB bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      AHB peripherals mask
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableAHB(mask, lp) {                                            \
  RCU->AHBEN |= (mask);                                                    \
  (void)RCU->AHBEN;                                                        \
}

/**
 * @brief   Disables the clock of one or more peripheral on the AHB bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      AHB peripherals mask
 *
 * @api
 */
#define rcuDisableAHB(mask) {                                               \
  RCU->AHBEN &= ~(mask);                                                   \
  (void)RCU->AHBEN;                                                        \
}

/**
 * @brief   Resets one or more peripheral on the AHB bus.
 *
 * @param[in] mask      AHB peripherals mask
 *
 * @api
 */
#define rcuResetAHB(mask) {                                                 \
  RCU->AHBRST |= (mask);                                                   \
  RCU->AHBRST &= ~(mask);                                                  \
  (void)RCU->AHBRST;                                                       \
}
/** @} */

/**
 * @name    ADC peripherals specific RCU operations
 * @{
 */
/**
 * @brief   Enables the ADC1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableADC1(lp) rcuEnableAPB2(RCU_APB2ENR_ADC1EN, lp)

/**
 * @brief   Disables the ADC1 peripheral clock.
 *
 * @api
 */
#define rcuDisableADC1() rcuDisableAPB2(RCU_APB2ENR_ADC1EN)

/**
 * @brief   Resets the ADC1 peripheral.
 *
 * @api
 */
#define rcuResetADC1() rcuResetAPB2(RCU_APB2RSTR_ADC1RST)
/** @} */

/**
 * @name    DAC peripheral specific RCU operations
 * @{
 */
/**
 * @brief   Enables the DAC1 peripheral clock.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableDAC1(lp) rcuEnableAPB1(RCU_APB1ENR_DACEN, lp)

/**
 * @brief   Disables the DAC1 peripheral clock.
 *
 * @api
 */
#define rcuDisableDAC1() rcuDisableAPB1(RCU_APB1ENR_DACEN)

/**
 * @brief   Resets the DAC1 peripheral.
 *
 * @api
 */
#define rcuResetDAC1() rcuResetAPB1(RCU_APB1RSTR_DACRST)
/** @} */

/**
 * @name    Backup domain interface specific RCU operations
 * @{
 */
/**
 * @brief   Enables the BKP interface clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableBKPInterface(lp) rcuEnableAPB1((RCU_APB1ENR_BKPEN), lp)

/**
 * @brief   Disables BKP interface clock.
 *
 * @api
 */
#define rcuDisableBKPInterface() rcuDisableAPB1(RCU_APB1ENR_BKPEN)

/**
 * @brief   Resets the Backup Domain interface.
 *
 * @api
 */
#define rcuResetBKPInterface() rcuResetAPB1(RCU_APB1ENR_BKPRST)

/**
 * @brief   Resets the entire Backup Domain.
 *
 * @api
 */
#define rcuResetBKP() (RCU->BDCTL |= RCU_BDCR_BDRST)
/** @} */

/**
 * @name    PMU interface specific RCU operations
 * @{
 */
/**
 * @brief   Enables the PMU interface clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnablePMUInterface(lp) rcuEnableAPB1(RCU_APB1ENR_PMUEN, lp)

/**
 * @brief   Disables PMU interface clock.
 *
 * @api
 */
#define rcuDisablePMUInterface() rcuDisableAPB1(RCU_APB1ENR_PMUEN)

/**
 * @brief   Resets the PMU interface.
 *
 * @api
 */
#define rcuResetPMUInterface() rcuResetAPB1(RCU_APB1RSTR_PMURST)
/** @} */

/**
 * @name    CAN peripherals specific RCU operations
 * @{
 */
/**
 * @brief   Enables the CAN1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableCAN1(lp) rcuEnableAPB1(RCU_APB1ENR_CAN1EN, lp)

/**
 * @brief   Disables the CAN1 peripheral clock.
 *
 * @api
 */
#define rcuDisableCAN1() rcuDisableAPB1(RCU_APB1ENR_CAN1EN)

/**
 * @brief   Resets the CAN1 peripheral.
 *
 * @api
 */
#define rcuResetCAN1() rcuResetAPB1(RCU_APB1RSTR_CAN1RST)

/**
 * @brief   Enables the CAN2 peripheral clock.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableCAN2(lp) rcuEnableAPB1(RCU_APB1ENR_CAN2EN, lp)

/**
 * @brief   Disables the CAN2 peripheral clock.
 *
 * @api
 */
#define rcuDisableCAN2() rcuDisableAPB1(RCU_APB1ENR_CAN2EN)

/**
 * @brief   Resets the CAN2 peripheral.
 *
 * @api
 */
#define rcuResetCAN2() rcuResetAPB1(RCU_APB1RSTR_CAN2RST)
/** @} */

/**
 * @name    DMA peripherals specific RCU operations
 * @{
 */
/**
 * @brief   Enables the DMA0 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableDMA0(lp) rcuEnableAHB(RCU_AHBENR_DMA0EN, lp)

/**
 * @brief   Disables the DMA0 peripheral clock.
 *
 * @api
 */
#define rcuDisableDMA0() rcuDisableAHB(RCU_AHBENR_DMA0EN)

/**
 * @brief   Resets the DMA0 peripheral.
 * @note    Not supported in this family, does nothing.
 *
 * @api
 */
#define rcuResetDMA0()

/**
 * @brief   Enables the DMA1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableDMA1(lp) rcuEnableAHB(RCU_AHBENR_DMA1EN, lp)

/**
 * @brief   Disables the DMA1 peripheral clock.
 *
 * @api
 */
#define rcuDisableDMA1() rcuDisableAHB(RCU_AHBENR_DMA1EN)

/**
 * @brief   Resets the DMA0 peripheral.
 * @note    Not supported in this family, does nothing.
 *
 * @api
 */
#define rcuResetDMA1()
/** @} */

/**
 * @name    ETH peripheral specific RCU operations
 * @{
 */
/**
 * @brief   Enables the ETH peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableETH(lp) rcuEnableAHB(RCU_AHBENR_ETHMACEN |                 \
                                      RCU_AHBENR_ETHMACTXEN |               \
                                      RCU_AHBENR_ETHMACRXEN, lp)

/**
 * @brief   Disables the ETH peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuDisableETH() rcuDisableAHB(RCU_AHBENR_ETHMACEN |                 \
                                      RCU_AHBENR_ETHMACTXEN |               \
                                      RCU_AHBENR_ETHMACRXEN)

/**
 * @brief   Resets the ETH peripheral.
 *
 * @api
 */
#define rcuResetETH() rcuResetAHB(RCU_AHBRSTR_ETHMACRST)
/** @} */

/**
 * @name    I2C peripherals specific RCU operations
 * @{
 */
/**
 * @brief   Enables the I2C0 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableI2C0(lp) rcuEnableAPB1(RCU_APB1ENR_I2C0EN, lp)

/**
 * @brief   Disables the I2C0 peripheral clock.
 *
 * @api
 */
#define rcuDisableI2C0() rcuDisableAPB1(RCU_APB1ENR_I2C0EN)

/**
 * @brief   Resets the I2C0 peripheral.
 *
 * @api
 */
#define rcuResetI2C0() rcuResetAPB1(RCU_APB1RSTR_I2C0RST)

/**
 * @brief   Enables the I2C1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableI2C1(lp) rcuEnableAPB1(RCU_APB1ENR_I2C1EN, lp)

/**
 * @brief   Disables the I2C1 peripheral clock.
 *
 * @api
 */
#define rcuDisableI2C1() rcuDisableAPB1(RCU_APB1ENR_I2C1EN)

/**
 * @brief   Resets the I2C1 peripheral.
 *
 * @api
 */
#define rcuResetI2C1() rcuResetAPB1(RCU_APB1RSTR_I2C1RST)
/** @} */

/**
 * @name    OTG peripherals specific RCU operations
 * @{
 */
/**
 * @brief   Enables the USBFS peripheral clock.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableUSBFS(lp) rcuEnableAHB(RCU_AHBENR_OTGFSEN, lp)

/**
 * @brief   Disables the USBFS peripheral clock.
 *
 * @api
 */
#define rcuDisableUSBFS() rcuDisableAHB(RCU_AHBENR_OTGFSEN)

/**
 * @brief   Resets the USBFS peripheral.
 *
 * @api
 */
#define rcuResetUSBFS() rcuResetAHB(RCU_AHBRSTR_OTGFSRST)
/** @} */

/**
 * @name    SDIO peripheral specific RCU operations
 * @{
 */
/**
 * @brief   Enables the SDIO peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableSDIO(lp) rcuEnableAHB(RCU_AHBENR_SDIOEN, lp)

/**
 * @brief   Disables the SDIO peripheral clock.
 *
 * @api
 */
#define rcuDisableSDIO() rcuDisableAHB(RCU_AHBENR_SDIOEN)

/**
 * @brief   Resets the SDIO peripheral.
 * @note    Not supported in this family, does nothing.
 *
 * @api
 */
#define rcuResetSDIO()
/** @} */

/**
 * @name    SPI peripherals specific RCU operations
 * @{
 */
/**
 * @brief   Enables the SPI1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableSPI1(lp) rcuEnableAPB2(RCU_APB2ENR_SPI1EN, lp)

/**
 * @brief   Disables the SPI1 peripheral clock.
 *
 * @api
 */
#define rcuDisableSPI1() rcuDisableAPB2(RCU_APB2ENR_SPI1EN)

/**
 * @brief   Resets the SPI1 peripheral.
 *
 * @api
 */
#define rcuResetSPI1() rcuResetAPB2(RCU_APB2RSTR_SPI1RST)

/**
 * @brief   Enables the SPI2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableSPI2(lp) rcuEnableAPB1(RCU_APB1ENR_SPI2EN, lp)

/**
 * @brief   Disables the SPI2 peripheral clock.
 *
 * @api
 */
#define rcuDisableSPI2() rcuDisableAPB1(RCU_APB1ENR_SPI2EN)

/**
 * @brief   Resets the SPI2 peripheral.
 *
 * @api
 */
#define rcuResetSPI2() rcuResetAPB1(RCU_APB1RSTR_SPI2RST)

/**
 * @brief   Enables the SPI3 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableSPI3(lp) rcuEnableAPB1(RCU_APB1ENR_SPI3EN, lp)

/**
 * @brief   Disables the SPI3 peripheral clock.
 *
 * @api
 */
#define rcuDisableSPI3() rcuDisableAPB1(RCU_APB1ENR_SPI3EN)

/**
 * @brief   Resets the SPI3 peripheral.
 *
 * @api
 */
#define rcuResetSPI3() rcuResetAPB1(RCU_APB1RSTR_SPI3RST)
/** @} */

/**
 * @name    TIM peripherals specific RCU operations
 * @{
 */
/**
 * @brief   Enables the TIM0 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableTIM0(lp) rcuEnableAPB2(RCU_APB2ENR_TIM0EN, lp)

/**
 * @brief   Disables the TIM0 peripheral clock.
 *
 * @api
 */
#define rcuDisableTIM0() rcuDisableAPB2(RCU_APB2ENR_TIM0EN)

/**
 * @brief   Resets the TIM0 peripheral.
 *
 * @api
 */
#define rcuResetTIM0() rcuResetAPB2(RCU_APB2RSTR_TIM0RST)

/**
 * @brief   Enables the TIM1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableTIM1(lp) rcuEnableAPB1(RCU_APB1ENR_TIM1EN, lp)

/**
 * @brief   Disables the TIM1 peripheral clock.
 *
 * @api
 */
#define rcuDisableTIM1() rcuDisableAPB1(RCU_APB1ENR_TIM1EN)

/**
 * @brief   Resets the TIM1 peripheral.
 *
 * @api
 */
#define rcuResetTIM1() rcuResetAPB1(RCU_APB1RSTR_TIM1RST)

/**
 * @brief   Enables the TIM2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableTIM2(lp) rcuEnableAPB1(RCU_APB1ENR_TIM2EN, lp)

/**
 * @brief   Disables the TIM2 peripheral clock.
 *
 * @api
 */
#define rcuDisableTIM2() rcuDisableAPB1(RCU_APB1ENR_TIM2EN)

/**
 * @brief   Resets the TIM2 peripheral.
 *
 * @api
 */
#define rcuResetTIM2() rcuResetAPB1(RCU_APB1RSTR_TIM2RST)

/**
 * @brief   Enables the TIM3 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableTIM3(lp) rcuEnableAPB1(RCU_APB1ENR_TIM3EN, lp)

/**
 * @brief   Disables the TIM3 peripheral clock.
 *
 * @api
 */
#define rcuDisableTIM3() rcuDisableAPB1(RCU_APB1ENR_TIM3EN)

/**
 * @brief   Resets the TIM3 peripheral.
 *
 * @api
 */
#define rcuResetTIM3() rcuResetAPB1(RCU_APB1RSTR_TIM3RST)

/**
 * @brief   Enables the TIM4 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableTIM4(lp) rcuEnableAPB1(RCU_APB1ENR_TIM4EN, lp)

/**
 * @brief   Disables the TIM4 peripheral clock.
 *
 * @api
 */
#define rcuDisableTIM4() rcuDisableAPB1(RCU_APB1ENR_TIM4EN)

/**
 * @brief   Resets the TIM4 peripheral.
 *
 * @api
 */
#define rcuResetTIM4() rcuResetAPB1(RCU_APB1RSTR_TIM4RST)

/**
 * @brief   Enables the TIM5 peripheral clock.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableTIM5(lp) rcuEnableAPB1(RCU_APB1ENR_TIM5EN, lp)

/**
 * @brief   Disables the TIM5 peripheral clock.
 *
 * @api
 */
#define rcuDisableTIM5() rcuDisableAPB1(RCU_APB1ENR_TIM5EN)

/**
 * @brief   Resets the TIM5 peripheral.
 *
 * @api
 */
#define rcuResetTIM5() rcuResetAPB1(RCU_APB1RSTR_TIM5RST)

/**
 * @brief   Enables the TIM6 peripheral clock.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableTIM6(lp) rcuEnableAPB1(RCU_APB1ENR_TIM6EN, lp)

/**
 * @brief   Disables the TIM6 peripheral clock.
 *
 * @api
 */
#define rcuDisableTIM6() rcuDisableAPB1(RCU_APB1ENR_TIM6EN)

/**
 * @brief   Resets the TIM6 peripheral.
 *
 * @api
 */
#define rcuResetTIM6() rcuResetAPB1(RCU_APB1RSTR_TIM6RST)


/** @} */

/**
 * @name    USART/UART peripherals specific RCU operations
 * @{
 */
/**
 * @brief   Enables the USART0 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableUSART0(lp) rcuEnableAPB2(RCU_APB2ENR_USART0EN, lp)

/**
 * @brief   Disables the USART0 peripheral clock.
 *
 * @api
 */
#define rcuDisableUSART0() rcuDisableAPB2(RCU_APB2ENR_USART0EN)

/**
 * @brief   Resets the USART0 peripheral.
 *
 * @api
 */
#define rcuResetUSART0() rcuResetAPB2(RCU_APB2RSTR_USART0RST)

/**
 * @brief   Enables the USART1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableUSART1(lp) rcuEnableAPB1(RCU_APB1ENR_USART1EN, lp)

/**
 * @brief   Disables the USART1 peripheral clock.
 *
 * @api
 */
#define rcuDisableUSART1() rcuDisableAPB1(RCU_APB1ENR_USART1EN)

/**
 * @brief   Resets the USART1 peripheral.
 *
 * @api
 */
#define rcuResetUSART1() rcuResetAPB1(RCU_APB1RSTR_USART1RST)

/**
 * @brief   Enables the USART2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableUSART2(lp) rcuEnableAPB1(RCU_APB1ENR_USART2EN, lp)

/**
 * @brief   Disables the USART2 peripheral clock.
 *
 * @api
 */
#define rcuDisableUSART2() rcuDisableAPB1(RCU_APB1ENR_USART2EN)

/**
 * @brief   Resets the USART2 peripheral.
 *
 * @api
 */
#define rcuResetUSART2() rcuResetAPB1(RCU_APB1RSTR_USART2RST)

/**
 * @brief   Enables the UART3 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableUART3(lp) rcuEnableAPB1(RCU_APB1ENR_UART3EN, lp)

/**
 * @brief   Disables the UART3 peripheral clock.
 *
 * @api
 */
#define rcuDisableUART3() rcuDisableAPB1(RCU_APB1ENR_UART3EN)

/**
 * @brief   Resets the UART3 peripheral.
 *
 * @api
 */
#define rcuResetUART3() rcuResetAPB1(RCU_APB1RSTR_UART3RST)

/**
 * @brief   Enables the UART4 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableUART4(lp) rcuEnableAPB1(RCU_APB1ENR_UART4EN, lp)

/**
 * @brief   Disables the UART4 peripheral clock.
 *
 * @api
 */
#define rcuDisableUART4() rcuDisableAPB1(RCU_APB1ENR_UART4EN)

/**
 * @brief   Resets the UART4 peripheral.
 *
 * @api
 */
#define rcuResetUART4() rcuResetAPB1(RCU_APB1RSTR_UART4RST)
/** @} */

/**
 * @name    USB peripheral specific RCU operations
 * @{
 */
/**
 * @brief   Enables the USB peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableUSB(lp) rcuEnableAPB1(RCU_APB1ENR_USBEN, lp)

/**
 * @brief   Disables the USB peripheral clock
 *
 * @api
 */
#define rcuDisableUSB() rcuDisableAPB1(RCU_APB1ENR_USBEN)

/**
 * @brief   Resets the USB peripheral.
 *
 * @api
 */
#define rcuResetUSB() rcuResetAPB1(RCU_APB1RSTR_USBRST)
/** @} */

/**
 * @name    FSMC peripherals specific RCU operations
 * @{
 */
/**
 * @brief   Enables the FSMC peripheral clock.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rcuEnableFSMC(lp) rcuEnableAHB(RCU_AHBENR_FSMCEN, lp)

/**
 * @brief   Disables the FSMC peripheral clock.
 *
 * @api
 */
#define rcuDisableFSMC() rcuDisableAHB(RCU_AHBENR_FSMCEN)
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

#endif /* GD32_RCU_H */

/** @} */
