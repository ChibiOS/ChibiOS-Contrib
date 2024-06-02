/*
    Copyright (C) 2022 Westberry Technology (ChangZhou) Corp., Ltd

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
 * @file    WB32FQ95xx/wb32_rcc.h
 * @brief   RCC helper driver header.
 * @note    This file requires definitions from the WB header file
 *          @p WB32fq95xx.h.
 *
 * @addtogroup WB32FQ95xx_RCC
 * @{
 */

#ifndef WB32_RCC_H
#define WB32_RCC_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/** @defgroup AHB_peripheral 
  * @{
  */
#define RCC_AHBPeriph_IWDG              ((uint32_t)0x00000004)
#define RCC_AHBPeriph_USB               ((uint32_t)0x00000200)
#define RCC_AHBPeriph_ISO               ((uint32_t)0x00000400)
#define RCC_AHBPeriph_FLASH             ((uint32_t)0x00000800)
#define RCC_AHBPeriph_CACHE             ((uint32_t)0x00001000)
#define RCC_AHBPeriph_SYS               ((uint32_t)0x00002000)
#define RCC_AHBPeriph_DMAC1Bridge       ((uint32_t)0x00004000)
#define RCC_AHBPeriph_DMAC2Bridge       ((uint32_t)0x00008000)
#define RCC_AHBPeriph_CRC_SFM           ((uint32_t)0x00010000)
#define RCC_AHBPeriph_BKP               ((uint32_t)0x04000000)
/**
  * @}
  */
 
/** @defgroup LSE_Configuration 
  * @{
  */
#define BKP_LSE_OFF                     ((uint32_t)0x00000000)
#define BKP_LSE_ON                      ((uint32_t)0x00000001)
#define BKP_LSE_Bypass                  ((uint32_t)0x00000004)
/**
  * @}
  */
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
 * @name    Generic RCC operations
 * @{
 */
/**
 * @brief   Enables the clock of one or more peripheral on the APB1 bus.
 *
 * @param[in] mask      APB1 peripherals mask
 *
 * @api
 */
#define rccEnableAPB1(mask) {                                               \
    RCC->APB1ENR |= (mask);                                                 \
    (void)RCC->APB1ENR;                                                     \
  }

/**
 * @brief   Disables the clock of one or more peripheral on the APB1 bus.
 *
 * @param[in] mask      APB1 peripherals mask
 *
 * @api
 */
#define rccDisableAPB1(mask) {                                              \
    RCC->APB1ENR &= ~(mask);                                                \
    (void)RCC->APB1ENR;                                                     \
  }

/**
 * @brief   Resets one or more peripheral on the APB1 bus.
 *
 * @param[in] mask      APB1 peripherals mask
 *
 * @api
 */
#define rccResetAPB1(mask) {                                                \
    RCC->APB1RSTR |= (mask);                                                \
    RCC->APB1RSTR &= ~(mask);                                               \
    (void)RCC->APB1RSTR;                                                    \
  }

/**
 * @brief   Enables the clock of one or more peripheral on the APB2 bus.
 *
 * @param[in] mask      APB2 peripherals mask
 *
 * @api
 */
#define rccEnableAPB2(mask) {                                               \
    RCC->APB2ENR |= (mask);                                                 \
    (void)RCC->APB2ENR;                                                     \
  }

/**
 * @brief   Disables the clock of one or more peripheral on the APB2 bus.
 *
 * @param[in] mask      APB2 peripherals mask
 *
 * @api
 */
#define rccDisableAPB2(mask) {                                              \
    RCC->APB2ENR &= ~(mask);                                                \
    (void)RCC->APB2ENR;                                                     \
  }

/**
 * @brief   Resets one or more peripheral on the APB2 bus.
 *
 * @param[in] mask      APB2 peripherals mask
 *
 * @api
 */
#define rccResetAPB2(mask) {                                                \
    RCC->APB2RSTR |= (mask);                                                \
    RCC->APB2RSTR &= ~(mask);                                               \
    (void)RCC->APB2RSTR;                                                    \
  }

/**
 * @brief   Enables the clock of one or more peripheral on the AHB bus.
 *
 * @param[in] mask      AHB peripherals mask
 *
 * @api
 */
#define rccEnableAHB(mask) {                                                \
    RCC->AHBENR1 |= (mask);                                                 \
    (void)RCC->AHBENR1;                                                     \
  }

/**
 * @brief   Disables the clock of one or more peripheral on the AHB bus.
 *
 * @param[in] mask      AHB peripherals mask
 *
 * @api
 */
#define rccDisableAHB(mask) {                                               \
    RCC->AHBENR1 &= ~(mask);                                                \
    (void)RCC->AHBENR1;                                                     \
  }

/**
 * @brief   Enables the clock of one or more peripheral on the AHB bus.
 *
 * @param[in] mask      AHB peripherals mask
 *
 * @api
 */
#define rccEnableAHB2(mask) {                                               \
    RCC->AHBENR2 |= (mask);                                                 \
    (void)RCC->AHBENR2;                                                     \
  }

/**
 * @brief   Disables the clock of one or more peripheral on the AHB bus.
 *
 * @param[in] mask      AHB peripherals mask
 *
 * @api
 */
#define rccDisableAHB2(mask) {                                              \
    RCC->AHBENR2 &= ~(mask);                                                \
    (void)RCC->AHBENR2;                                                     \
  }

/**
 * @brief   Resets one or more peripheral on the AHB bus.
 *
 * @param[in] mask      AHB peripherals mask
 *
 * @api
 */
#define rccResetAHB(mask) {                                                 \
    RCC->AHBRSTR1 |= (mask);                                                \
    RCC->AHBRSTR1 &= ~(mask);                                               \
    (void)RCC->AHBRSTR;                                                     \
  }
/** @} */

/**
 * @name    EXTI peripherals specific RCC operations
 * @{
 */
/**
 * @brief   Enables the EXTI peripheral clock.
 *
 * @api
 */
#define rccEnableEXTI() rccEnableAPB1(RCC_APB1ENR_EXTIEN | RCC_APB1ENR_AFIOEN)

/**
 * @brief   Disables the EXTI peripheral clock.
 *
 * @api
 */
#define rccDisableEXTI() rccDisableAPB1(RCC_APB1ENR_EXTIEN | RCC_APB1ENR_AFIOEN)

/**
 * @brief   Resets the EXTI peripheral.
 *
 * @api
 */
#define rccResetEXTI() rccResetAPB1(RCC_APB1RSTR_EXTIRST | RCC_APB1RSTR_AFIORST)
/** @} */


/**
 * @name    I2C peripherals specific RCC operations
 * @{
 */
/**
 * @brief   Enables the I2C1 peripheral clock.
 *
 * @api
 */
#define rccEnableI2C1() rccEnableAPB2(RCC_APB2ENR_I2C1EN)

/**
 * @brief   Disables the I2C1 peripheral clock.
 *
 * @api
 */
#define rccDisableI2C1() rccDisableAPB2(RCC_APB2ENR_I2C1EN)

/**
 * @brief   Resets the I2C1 peripheral.
 *
 * @api
 */
#define rccResetI2C1() rccResetAPB2(RCC_APB2RSTR_I2C1RST)

/**
 * @brief   Enables the I2C2 peripheral clock.
 *
 * @api
 */
#define rccEnableI2C2() rccEnableAPB2(RCC_APB2ENR_I2C2EN)

/**
 * @brief   Disables the I2C2 peripheral clock.
 *
 * @api
 */
#define rccDisableI2C2() rccDisableAPB2(RCC_APB2ENR_I2C2EN)

/**
 * @brief   Resets the I2C2 peripheral.
 *
 * @api
 */
#define rccResetI2C2() rccResetAPB2(RCC_APB2RSTR_I2C2RST)
/** @} */


/**
 * @name    SPI peripherals specific RCC operations
 * @{
 */
/**
 * @brief   Enables the QSPI peripheral clock.
 *
 * @api
 */
#define rccEnableQSPI() rccEnableAPB1(RCC_APB1ENR_QSPIEN)

/**
 * @brief   Disables the QSPI peripheral clock.
 *
 * @api
 */
#define rccDisableQSPI() rccDisableAPB1(RCC_APB1ENR_QSPIEN)

/**
 * @brief   Resets the QSPI peripheral.
 *
 * @api
 */
#define rccResetQSPI() rccResetAPB1(RCC_APB1RSTR_QSPIRST)

/**
 * @brief   Enables the SPIS1 peripheral clock.
 *
 * @api
 */
#define rccEnableSPIS1() do {                                               \
    rccEnableAPB1(RCC_APB1ENR_SPIS1EN);                                     \
    RCC->SPIS1CLKENR = RCC_SPIS1CLKENR_CLKEN;                               \
  } while (false)

/**
 * @brief   Disables the SPIS1 peripheral clock.
 *
 * @api
 */
#define rccDisableSPIS1() do {                                              \
    RCC->SPIS1CLKENR = 0x00;                                                \
    rccDisableAPB1(RCC_APB1ENR_SPIS1EN);                                    \
  } while (false)

/**
 * @brief   Resets the SPIS1 peripheral.
 *
 * @api
 */
#define rccResetSPIS1() rccResetAPB1(RCC_APB1RSTR_SPIS1RST)

/**
 * @brief   Enables the SPIM2 peripheral clock.
 *
 * @api
 */
#define rccEnableSPIM2() rccEnableAPB2(RCC_APB2ENR_SPIM2EN)

/**
 * @brief   Disables the SPIM2 peripheral clock.
 *
 * @api
 */
#define rccDisableSPIM2() rccDisableAPB2(RCC_APB2ENR_SPIM2EN)

/**
 * @brief   Resets the SPIM2 peripheral.
 *
 * @api
 */
#define rccResetSPIM2() rccResetAPB2(RCC_APB2RSTR_SPIM2RST)

/**
 * @brief   Enables the SPIS2 peripheral clock.
 *
 * @api
 */
#define rccEnableSPIS2() do {                                               \
    rccEnableAPB2(RCC_APB2ENR_SPIS2EN);                                     \
    RCC->SPIS2CLKENR = RCC_SPIS2CLKENR_CLKEN;                               \
  } while (false)

/**
 * @brief   Disables the SPIS2 peripheral clock.
 *
 * @api
 */
#define rccDisableSPIS2() do {                                              \
    RCC->SPIS2CLKENR = 0x00;                                                \
    rccDisableAPB2(RCC_APB2ENR_SPIS2EN);                                    \
  } while (false)

/**
 * @brief   Resets the SPIS2 peripheral.
 *
 * @api
 */
#define rccResetSPIS2() rccResetAPB2(RCC_APB2RSTR_SPIS2RST)

/** @} */


/**
 * @name    TIM peripherals specific RCC operations
 * @{
 */
/**
 * @brief   Enables the TIM1 peripheral clock.
 *
 * @api
 */
#define rccEnableTIM1() rccEnableAPB1(RCC_APB1ENR_TIM1EN)

/**
 * @brief   Disables the TIM1 peripheral clock.
 *
 * @api
 */
#define rccDisableTIM1() rccDisableAPB1(RCC_APB1ENR_TIM1EN)

/**
 * @brief   Resets the TIM1 peripheral.
 *
 * @api
 */
#define rccResetTIM1() rccResetAPB1(RCC_APB1RSTR_TIM1RST)

/**
 * @brief   Enables the TIM2 peripheral clock.
 *
 * @api
 */
#define rccEnableTIM2() rccEnableAPB1(RCC_APB1ENR_TIM2EN)

/**
 * @brief   Disables the TIM2 peripheral clock.
 *
 * @api
 */
#define rccDisableTIM2() rccDisableAPB1(RCC_APB1ENR_TIM2EN)

/**
 * @brief   Resets the TIM2 peripheral.
 *
 * @api
 */
#define rccResetTIM2() rccResetAPB1(RCC_APB1RSTR_TIM2RST)

/**
 * @brief   Enables the TIM3 peripheral clock.
 *
 * @api
 */
#define rccEnableTIM3() rccEnableAPB1(RCC_APB1ENR_TIM3EN)

/**
 * @brief   Disables the TIM3 peripheral clock.
 *
 * @api
 */
#define rccDisableTIM3() rccDisableAPB1(RCC_APB1ENR_TIM3EN)

/**
 * @brief   Resets the TIM3 peripheral.
 *
 * @api
 */
#define rccResetTIM3() rccResetAPB1(RCC_APB1RSTR_TIM3RST)

/**
 * @brief   Enables the TIM4 peripheral clock.
 *
 * @api
 */
#define rccEnableTIM4() rccEnableAPB1(RCC_APB1ENR_TIM4EN)

/**
 * @brief   Disables the TIM4 peripheral clock.
 *
 * @api
 */
#define rccDisableTIM4() rccDisableAPB1(RCC_APB1ENR_TIM4EN)

/**
 * @brief   Resets the TIM4 peripheral.
 *
 * @api
 */
#define rccResetTIM4() rccResetAPB1(RCC_APB1RSTR_TIM4RST)
/** @} */


/**
 * @name    UART peripherals specific RCC operations
 * @{
 */
/**
 * @brief   Enables the UART1 peripheral clock.
 *
 * @api
 */
#define rccEnableUART1() rccEnableAPB1(RCC_APB1ENR_UART1EN)

/**
 * @brief   Disables the UART1 peripheral clock.
 *
 * @api
 */
#define rccDisableUART1() rccDisableAPB1(RCC_APB1ENR_UART1EN)

/**
 * @brief   Resets the UART1 peripheral.
 *
 * @api
 */
#define rccResetUART1() rccResetAPB1(RCC_APB1RSTR_UART1RST)

/**
 * @brief   Enables the UART2 peripheral clock.
 *
 * @api
 */
#define rccEnableUART2() rccEnableAPB2(RCC_APB2ENR_UART2EN)

/**
 * @brief   Disables the UART2 peripheral clock.
 *
 * @api
 */
#define rccDisableUART2() rccDisableAPB2(RCC_APB2ENR_UART2EN)

/**
 * @brief   Resets the UART2 peripheral.
 *
 * @api
 */
#define rccResetUART2() rccResetAPB2(RCC_APB2RSTR_UART2RST)

/**
 * @brief   Enables the UART3 peripheral clock.
 *
 * @api
 */
#define rccEnableUART3() rccEnableAPB2(RCC_APB2ENR_UART3EN)

/**
 * @brief   Disables the UART3 peripheral clock.
 *
 * @api
 */
#define rccDisableUART3() rccDisableAPB2(RCC_APB2ENR_UART3EN)

/**
 * @brief   Resets the UART3 peripheral.
 *
 * @api
 */
#define rccResetUART3() rccResetAPB2(RCC_APB2RSTR_UART3RST)
/** @} */


/**
 * @name    ADC peripherals specific RCC operations
 * @{
 */
/**
 * @brief   Enables the ADC peripheral clock.
 *
 * @api
 */
#define rccEnableADC() rccEnableAPB1(RCC_APB1ENR_ADCEN)

/**
 * @brief   Disables the ADC peripheral clock.
 *
 * @api
 */
#define rccDisableADC() rccDisableAPB1(RCC_APB1ENR_ADCEN)

/**
 * @brief   Resets the ADC peripheral.
 *
 * @api
 */
#define rccResetADC() rccResetAPB1(RCC_APB1RSTR_ADCRST)
/** @} */


/**
 * @name    DMAC peripherals specific RCC operations
 * @{
 */
/**
 * @brief   Enables the DMAC1 peripheral clock.
 *
 * @api
 */
#define rccEnableDMAC1() do {                                               \
    rccEnableAHB(RCC_AHBENR1_DMAC1BREN);                                    \
    rccEnableAPB1(RCC_APB1ENR_DMAC1EN);                                     \
  } while (false)

/**
 * @brief   Disables the DMAC1 peripheral clock.
 *
 * @api
 */
#define rccDisableDMAC1() do {                                              \
    rccDisableAHB(RCC_AHBENR1_DMAC1BREN);                                   \
    rccDisableAPB1(RCC_APB1ENR_DMAC1EN);                                    \
  } while (false)

/**
 * @brief   Resets the DMAC1 peripheral.
 *
 * @api
 */
#define rccResetDMAC1() rccResetAPB1(RCC_APB1RSTR_DMAC1RST)

/**
 * @brief   Enables the DMAC2 peripheral clock.
 *
 * @api
 */
#define rccEnableDMAC2() do {                                               \
    rccEnableAHB(RCC_AHBENR1_DMAC2BREN);                                    \
    rccEnableAPB2(RCC_APB2ENR_DMAC2EN);                                     \
  } while (false)

/**
 * @brief   Disables the DMAC2 peripheral clock.
 *
 * @api
 */
#define rccDisableDMAC2() do {                                              \
    rccDisableAHB(RCC_AHBENR1_DMAC2BREN);                                   \
    rccDisableAPB2(RCC_APB2ENR_DMAC2EN);                                    \
  } while (false)

/**
 * @brief   Resets the DMAC2 peripheral.
 *
 * @api
 */
#define rccResetDMAC2() rccResetAPB2(RCC_APB2RSTR_DMAC2RST)
/** @} */

/**
 * @name    BKP peripherals specific RCC operations
 * @{
 */
/**
 * @brief   Enables the BKP peripheral clock.
 *
 * @api
 */
#define rccEnableBKP() do {                                               \
    rccEnableAHB2(RCC_AHBPeriph_BKP >> 24);                               \
  } while (false)

/**
 * @brief   Disables the BKP peripheral clock.
 *
 * @api
 */
#define rccDisableBKP() do {                                              \
    rccDisableAHB2(RCC_AHBPeriph_BKP >> 24);                              \
  } while (false)

/**
 * @brief   Resets the BKP peripheral.
 *
 * @api
 */
#define rccResetBKP() {                                                   \
    RCC->BDRSTR = (uint32_t)ENABLE;                                       \
    RCC->BDRSTR = (uint32_t)DISABLE;                                      \
    (void)RCC->BDRSTR;                                                    \
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

#endif /* WB32_RCC_H */

/** @} */
