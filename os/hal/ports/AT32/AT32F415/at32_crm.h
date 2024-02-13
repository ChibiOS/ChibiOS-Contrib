/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian

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
 * @file    AT32F415/at32_crm.h
 * @brief   CRM helper driver header.
 * @note    This file requires definitions from the AT header file
 *          @p at32f415.h.
 *
 * @addtogroup AT32F415_CRM
 * @{
 */

#ifndef AT32_CRM_H
#define AT32_CRM_H

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
 * @name    Generic CRM operations
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
#define crmEnableAPB1(mask, lp) {                                           \
  CRM->APB1EN |= (mask);                                                    \
  (void)CRM->APB1EN;                                                        \
}

/**
 * @brief   Disables the clock of one or more peripheral on the APB1 bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      APB1 peripherals mask
 *
 * @api
 */
#define crmDisableAPB1(mask) {                                              \
  CRM->APB1EN &= ~(mask);                                                   \
  (void)CRM->APB1EN;                                                        \
}

/**
 * @brief   Resets one or more peripheral on the APB1 bus.
 *
 * @param[in] mask      APB1 peripherals mask
 *
 * @api
 */
#define crmResetAPB1(mask) {                                                \
  CRM->APB1RST |= (mask);                                                   \
  CRM->APB1RST &= ~(mask);                                                  \
  (void)CRM->APB1RST;                                                       \
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
#define crmEnableAPB2(mask, lp) {                                           \
  CRM->APB2EN |= (mask);                                                    \
  (void)CRM->APB2EN;                                                        \
}

/**
 * @brief   Disables the clock of one or more peripheral on the APB2 bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      APB2 peripherals mask
 *
 * @api
 */
#define crmDisableAPB2(mask) {                                              \
  CRM->APB2EN &= ~(mask);                                                   \
  (void)CRM->APB2EN;                                                        \
}

/**
 * @brief   Resets one or more peripheral on the APB2 bus.
 *
 * @param[in] mask      APB2 peripherals mask
 *
 * @api
 */
#define crmResetAPB2(mask) {                                                \
  CRM->APB2RST |= (mask);                                                   \
  CRM->APB2RST &= ~(mask);                                                  \
  (void)CRM->APB2RST;                                                       \
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
#define crmEnableAHB(mask, lp) {                                            \
  CRM->AHBEN |= (mask);                                                     \
  (void)CRM->AHBEN;                                                         \
}

/**
 * @brief   Disables the clock of one or more peripheral on the AHB bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      AHB peripherals mask
 *
 * @api
 */
#define crmDisableAHB(mask) {                                               \
  CRM->AHBEN &= ~(mask);                                                    \
  (void)CRM->AHBEN;                                                         \
}

/**
 * @brief   Resets one or more peripheral on the AHB bus.
 *
 * @param[in] mask      AHB peripherals mask
 *
 * @api
 */
#define crmResetAHB(mask) {                                                 \
  CRM->AHBRST |= (mask);                                                    \
  CRM->AHBRST &= ~(mask);                                                   \
  (void)CRM->AHBRST;                                                        \
}
/** @} */

/**
 * @name    ADC peripherals specific CRM operations
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
#define crmEnableADC1(lp) crmEnableAPB2(CRM_APB2EN_ADC1EN, lp)

/**
 * @brief   Disables the ADC1 peripheral clock.
 *
 * @api
 */
#define crmDisableADC1() crmDisableAPB2(CRM_APB2EN_ADC1EN)

/**
 * @brief   Resets the ADC1 peripheral.
 *
 * @api
 */
#define crmResetADC1() crmResetAPB2(CRM_APB2RST_ADC1RST)
/** @} */

/**
 * @name    PWC interface specific CRM operations
 * @{
 */
/**
 * @brief   Enables the PWC interface clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnablePWCInterface(lp) crmEnableAPB1(CRM_APB1EN_PWCEN, lp)

/**
 * @brief   Disables PWC interface clock.
 *
 * @api
 */
#define crmDisablePWCInterface() crmDisableAPB1(CRM_APB1EN_PWCEN)

/**
 * @brief   Resets the PWC interface.
 *
 * @api
 */
#define crmResetPWCInterface() crmResetAPB1(CRM_APB1RST_PWCRST)
/** @} */

/**
 * @name    CAN peripherals specific CRM operations
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
#define crmEnableCAN1(lp) crmEnableAPB1(CRM_APB1EN_CAN1EN, lp)

/**
 * @brief   Disables the CAN1 peripheral clock.
 *
 * @api
 */
#define crmDisableCAN1() crmDisableAPB1(CRM_APB1EN_CAN1EN)

/**
 * @brief   Resets the CAN1 peripheral.
 *
 * @api
 */
#define crmResetCAN1() crmResetAPB1(CRM_APB1RST_CAN1RST)

/**
 * @name    DMA peripherals specific CRM operations
 * @{
 */
/**
 * @brief   Enables the DMA1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableDMA1(lp) crmEnableAHB(CRM_AHBEN_DMA1EN, lp)

/**
 * @brief   Disables the DMA1 peripheral clock.
 *
 * @api
 */
#define crmDisableDMA1() crmDisableAHB(CRM_AHBEN_DMA1EN)

/**
 * @brief   Resets the DMA1 peripheral.
 * @note    Not supported in this family, does nothing.
 *
 * @api
 */
#define crmResetDMA1()

/**
 * @brief   Enables the DMA2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableDMA2(lp) crmEnableAHB(CRM_AHBEN_DMA2EN, lp)

/**
 * @brief   Disables the DMA2 peripheral clock.
 *
 * @api
 */
#define crmDisableDMA2() crmDisableAHB(CRM_AHBEN_DMA2EN)

/**
 * @brief   Resets the DMA1 peripheral.
 * @note    Not supported in this family, does nothing.
 *
 * @api
 */
#define crmResetDMA2()
/** @} */

/**
 * @name    I2C peripherals specific CRM operations
 * @{
 */
/**
 * @brief   Enables the I2C1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableI2C1(lp) crmEnableAPB1(CRM_APB1EN_I2C1EN, lp)

/**
 * @brief   Disables the I2C1 peripheral clock.
 *
 * @api
 */
#define crmDisableI2C1() crmDisableAPB1(CRM_APB1EN_I2C1EN)

/**
 * @brief   Resets the I2C1 peripheral.
 *
 * @api
 */
#define crmResetI2C1() crmResetAPB1(CRM_APB1RST_I2C1RST)

/**
 * @brief   Enables the I2C2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableI2C2(lp) crmEnableAPB1(CRM_APB1EN_I2C2EN, lp)

/**
 * @brief   Disables the I2C2 peripheral clock.
 *
 * @api
 */
#define crmDisableI2C2() crmDisableAPB1(CRM_APB1EN_I2C2EN)

/**
 * @brief   Resets the I2C2 peripheral.
 *
 * @api
 */
#define crmResetI2C2() crmResetAPB1(CRM_APB1RST_I2C2RST)
/** @} */

/**
 * @name    OTG peripherals specific CRM operations
 * @{
 */
/**
 * @brief   Enables the OTG_FS peripheral clock.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableOTG_FS(lp) crmEnableAHB(CRM_AHBEN_OTGFSEN, lp)

/**
 * @brief   Disables the OTG_FS peripheral clock.
 *
 * @api
 */
#define crmDisableOTG_FS() crmDisableAHB(CRM_AHBEN_OTGFSEN)

/**
 * @brief   Resets the OTG_FS peripheral.
 *
 * @api
 */
#define crmResetOTG_FS() crmResetAHB(CRM_AHBRST_OTGFSRST)
/** @} */

/**
 * @name    SDIO peripheral specific CRM operations
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
#define crmEnableSDIO(lp) crmEnableAHB(CRM_AHBEN_SDIOEN, lp)

/**
 * @brief   Disables the SDIO peripheral clock.
 *
 * @api
 */
#define crmDisableSDIO() crmDisableAHB(CRM_AHBEN_SDIOEN)

/**
 * @brief   Resets the SDIO peripheral.
 * @note    Not supported in this family, does nothing.
 *
 * @api
 */
#define crmResetSDIO()
/** @} */

/**
 * @name    SPI peripherals specific CRM operations
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
#define crmEnableSPI1(lp) crmEnableAPB2(CRM_APB2EN_SPI1EN, lp)

/**
 * @brief   Disables the SPI1 peripheral clock.
 *
 * @api
 */
#define crmDisableSPI1() crmDisableAPB2(CRM_APB2EN_SPI1EN)

/**
 * @brief   Resets the SPI1 peripheral.
 *
 * @api
 */
#define crmResetSPI1() crmResetAPB2(CRM_APB2RST_SPI1RST)

/**
 * @brief   Enables the SPI2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableSPI2(lp) crmEnableAPB1(CRM_APB1EN_SPI2EN, lp)

/**
 * @brief   Disables the SPI2 peripheral clock.
 *
 * @api
 */
#define crmDisableSPI2() crmDisableAPB1(CRM_APB1EN_SPI2EN)

/**
 * @brief   Resets the SPI2 peripheral.
 *
 * @api
 */
#define crmResetSPI2() crmResetAPB1(CRM_APB1RST_SPI2RST)

/**
 * @name    TMR peripherals specific CRM operations
 * @{
 */
/**
 * @brief   Enables the TMR1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR1(lp) crmEnableAPB2(CRM_APB2EN_TMR1EN, lp)

/**
 * @brief   Disables the TMR1 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR1() crmDisableAPB2(CRM_APB2EN_TMR1EN)

/**
 * @brief   Resets the TMR1 peripheral.
 *
 * @api
 */
#define crmResetTMR1() crmResetAPB2(CRM_APB2RST_TMR1RST)

/**
 * @brief   Enables the TMR2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR2(lp) crmEnableAPB1(CRM_APB1EN_TMR2EN, lp)

/**
 * @brief   Disables the TMR2 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR2() crmDisableAPB1(CRM_APB1EN_TMR2EN)

/**
 * @brief   Resets the TMR2 peripheral.
 *
 * @api
 */
#define crmResetTMR2() crmResetAPB1(CRM_APB1RST_TMR2RST)

/**
 * @brief   Enables the TMR3 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR3(lp) crmEnableAPB1(CRM_APB1EN_TMR3EN, lp)

/**
 * @brief   Disables the TMR3 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR3() crmDisableAPB1(CRM_APB1EN_TMR3EN)

/**
 * @brief   Resets the TMR3 peripheral.
 *
 * @api
 */
#define crmResetTMR3() crmResetAPB1(CRM_APB1RST_TMR3RST)

/**
 * @brief   Enables the TMR4 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR4(lp) crmEnableAPB1(CRM_APB1EN_TMR4EN, lp)

/**
 * @brief   Disables the TMR4 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR4() crmDisableAPB1(CRM_APB1EN_TMR4EN)

/**
 * @brief   Resets the TMR4 peripheral.
 *
 * @api
 */
#define crmResetTMR4() crmResetAPB1(CRM_APB1RST_TMR4RST)

/**
 * @brief   Enables the TMR5 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR5(lp) crmEnableAPB1(CRM_APB1EN_TMR5EN, lp)

/**
 * @brief   Disables the TMR5 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR5() crmDisableAPB1(CRM_APB1EN_TMR5EN)

/**
 * @brief   Resets the TMR5 peripheral.
 *
 * @api
 */
#define crmResetTMR5() crmResetAPB1(CRM_APB1RST_TMR5RST)

/**
 * @brief   Enables the TMR9 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR9(lp) crmEnableAPB2(CRM_APB2EN_TMR9EN, lp)

/**
 * @brief   Disables the TMR9 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR9() crmDisableAPB2(CRM_APB2EN_TMR9EN)

/**
 * @brief   Resets the TMR9 peripheral.
 *
 * @api
 */
#define crmResetTMR9() crmResetAPB2(CRM_APB2RST_TMR9RST)

/**
 * @brief   Enables the TMR10 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR10(lp) crmEnableAPB2(CRM_APB2EN_TMR10EN, lp)

/**
 * @brief   Disables the TMR10 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR10() crmDisableAPB2(CRM_APB2EN_TMR10EN)

/**
 * @brief   Resets the TMR10 peripheral.
 *
 * @api
 */
#define crmResetTMR10() crmResetAPB2(CRM_APB2RST_TMR10RST)

/**
 * @brief   Enables the TMR11 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR11(lp) crmEnableAPB2(CRM_APB2EN_TMR11EN, lp)

/**
 * @brief   Disables the TMR11 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR11() crmDisableAPB2(CRM_APB2EN_TMR11EN)

/**
 * @brief   Resets the TMR11 peripheral.
 *
 * @api
 */
#define crmResetTMR11() crmResetAPB2(CRM_APB2RST_TMR11RST)

/**
 * @name    USART/UART peripherals specific CRM operations
 * @{
 */
/**
 * @brief   Enables the USART1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableUSART1(lp) crmEnableAPB2(CRM_APB2EN_USART1EN, lp)

/**
 * @brief   Disables the USART1 peripheral clock.
 *
 * @api
 */
#define crmDisableUSART1() crmDisableAPB2(CRM_APB2EN_USART1EN)

/**
 * @brief   Resets the USART1 peripheral.
 *
 * @api
 */
#define crmResetUSART1() crmResetAPB2(CRM_APB2RST_USART1RST)

/**
 * @brief   Enables the USART2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableUSART2(lp) crmEnableAPB1(CRM_APB1EN_USART2EN, lp)

/**
 * @brief   Disables the USART2 peripheral clock.
 *
 * @api
 */
#define crmDisableUSART2() crmDisableAPB1(CRM_APB1EN_USART2EN)

/**
 * @brief   Resets the USART2 peripheral.
 *
 * @api
 */
#define crmResetUSART2() crmResetAPB1(CRM_APB1RST_USART2RST)

/**
 * @brief   Enables the USART3 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableUSART3(lp) crmEnableAPB1(CRM_APB1EN_USART3EN, lp)

/**
 * @brief   Disables the USART3 peripheral clock.
 *
 * @api
 */
#define crmDisableUSART3() crmDisableAPB1(CRM_APB1EN_USART3EN)

/**
 * @brief   Resets the USART3 peripheral.
 *
 * @api
 */
#define crmResetUSART3() crmResetAPB1(CRM_APB1RST_USART3RST)

/**
 * @brief   Enables the UART4 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableUART4(lp) crmEnableAPB1(CRM_APB1EN_UART4EN, lp)

/**
 * @brief   Disables the UART4 peripheral clock.
 *
 * @api
 */
#define crmDisableUART4() crmDisableAPB1(CRM_APB1EN_UART4EN)

/**
 * @brief   Resets the UART4 peripheral.
 *
 * @api
 */
#define crmResetUART4() crmResetAPB1(CRM_APB1RST_UART4RST)

/**
 * @brief   Enables the UART5 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableUART5(lp) crmEnableAPB1(CRM_APB1EN_UART5EN, lp)

/**
 * @brief   Disables the UART5 peripheral clock.
 *
 * @api
 */
#define crmDisableUART5() crmDisableAPB1(CRM_APB1EN_UART5EN)

/**
 * @brief   Resets the UART5 peripheral.
 *
 * @api
 */
#define crmResetUART5() crmResetAPB1(CRM_APB1RST_UART5RST)
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

#endif /* AT32_CRM_H */

/** @} */
