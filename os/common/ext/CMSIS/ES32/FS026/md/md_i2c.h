/**********************************************************************************
 *
 * @file    md_i2c.h
 * @brief   header file of md_i2c.c
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov  2021    Ginger          the first version
 *          21 Mar  2022    AE Team         Modify MD Driver
 *
 * Copyright (C) Shanghai Eastsoft Microelectronics Co. Ltd. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 **********************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MD_I2C_H__
#define __MD_I2C_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_I2C I2C
  * @brief I2C micro driver
  * @{
  */

/** @defgroup MD_I2C_Pubulic_Types I2C Pubulic Types
  * @{
  */

/**
  * @brief   I2C Init structure.
  */
typedef struct
{
    uint32_t Timing;           /*!< Specifies the I2C_TIMINGR_register value.
                                  This parameter can be a value of @ref CLK100kHz8M
                                                                   @ref CLK400kHz8M
                                                                   @ref CLK500kHz8M
                                                                   @ref CLK10kHz16M
                                                                   @ref CLK100kHz16M
                                                                   @ref CLK400kHz16M
                                                                   @ref CLK1000kHz16M
                                                                   @ref CLK10kHz48M
                                                                   @ref CLK100kHz48M
                                                                   @ref CLK400kHz48M
                                                                   @ref CLK1000kHz48M  */

    uint32_t Address1;         /*!< Specifies the first device address.
                                  This parameter can be a 7-bit or 10-bit address. */

    uint32_t AddrSize;         /*!< Specifies the device address 1 size (7-bit or 10-bit).
                                  This parameter can be a value of @ref MD_I2C_OA1MODE_7BIT
                                                                   @ref MD_I2C_OA1MODE_10BIT */

    uint32_t DualAddressMode;  /*!< Specifies if dual addressing mode is selected. */

    uint32_t Address2;         /*!< Specifies the second device own address if dual addressing mode is selected
                               This parameter can be a 7-bit address. */

    uint32_t Address2Masks;    /*!< Specifies the acknowledge mask address second device own address if dual addressing mode is selected
                               This parameter can be a value of @ref MD_I2C_ADDR2_NOMASK
                                                                @ref MD_I2C_ADDR2_MASK01
                                                                @ref MD_I2C_ADDR2_MASK02
                                                                @ref MD_I2C_ADDR2_MASK03
                                                                @ref MD_I2C_ADDR2_MASK04
                                                                @ref MD_I2C_ADDR2_MASK05
                                                                @ref MD_I2C_ADDR2_MASK06
                                                                @ref MD_I2C_ADDR2_MASK07 */
} md_i2c_inittypedef;
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Macros I2C Public Macros
  * @{
  */

/* I2C_CON1 macros define*/

#define MD_I2C_DNF_DISABLE          (0x00000000U)
#define MD_I2C_DNF_1T               (0x00000001U)
#define MD_I2C_DNF_2T               (0x00000002U)
#define MD_I2C_DNF_3T               (0x00000003U)
#define MD_I2C_DNF_4T               (0x00000004U)
#define MD_I2C_DNF_5T               (0x00000005U)
#define MD_I2C_DNF_6T               (0x00000006U)
#define MD_I2C_DNF_7T               (0x00000007U)
#define MD_I2C_DNF_8T               (0x00000008U)
#define MD_I2C_DNF_9T               (0x00000009U)
#define MD_I2C_DNF_10T              (0x0000000AU)
#define MD_I2C_DNF_11T              (0x0000000BU)
#define MD_I2C_DNF_12T              (0x0000000CU)
#define MD_I2C_DNF_13T              (0x0000000DU)
#define MD_I2C_DNF_14T              (0x0000000EU)
#define MD_I2C_DNF_15T              (0x0000000FU)

/* I2C_CON2 macros define*/
#define MD_I2C_ACK_UPD_NO_UPDATE        (0x00000000U)
#define MD_I2C_ACK_UPD_UPDATE           (0x00000001U)

#define MD_I2C_ACK                      (0x00000000U)
#define MD_I2C_NACK                     (0x00000001U)

#define MD_I2C_STOP_NO                  (0x00000000U)
#define MD_I2C_STOP_GENERATION          (0x00000001U)

#define MD_I2C_START_NO                 (0x00000000U)
#define MD_I2C_START_GENERATION         (0x00000001U)

#define MD_I2C_ADDRESSINGMODE_7BIT      (0x00000000U)
#define MD_I2C_ADDRESSINGMODE_10BIT     (0x00000001U)

/* I2C_ADDR1 macros define*/

#define MD_I2C_OA1MODE_7BIT             (0x00000000U)
#define MD_I2C_OA1MODE_10BIT            (0x00000001U)

/* I2C_ADDR2 macros define*/
#define MD_I2C_OA2_DISABLE              (0x00000000U)
#define MD_I2C_OA2_ENABLE               (0x00000001U)

#define MD_I2C_ADDR2_NOMASK             (0x00U)
#define MD_I2C_ADDR2_MASK01             (0x01U)
#define MD_I2C_ADDR2_MASK02             (0x02U)
#define MD_I2C_ADDR2_MASK03             (0x03U)
#define MD_I2C_ADDR2_MASK04             (0x04U)
#define MD_I2C_ADDR2_MASK05             (0x05U)
#define MD_I2C_ADDR2_MASK06             (0x06U)
#define MD_I2C_ADDR2_MASK07             (0x07U)

/* I2C_TIMINGR macros define*/
/*                      presc       scldel     sdadel     sclh       scll      */
#define CLK10kHz8M      (0x1<<28)   |(0x4<<20) |(0x2<<16) |(0xC3<<8) |(0xC7)    /*!< APB = 8MHz; CLK = 10kHz */
#define CLK100kHz8M     (0x1<<28)   |(0x4<<20) |(0x2<<16) |(0xF<<8)  |(0x13)    /*!< APB = 8MHz; CLK = 100kHz */
#define CLK400kHz8M     (0x0<<28)   |(0x3<<20) |(0x1<<16) |(0x3<<8)  |(0x9)     /*!< APB = 8MHz; CLK = 400kHz */
#define CLK500kHz8M     (0x0<<28)   |(0x1<<20) |(0x0<<16) |(0x3<<8)  |(0x6)     /*!< APB = 8MHz; CLK = 500kHz */
#define CLK10kHz16M     (0x3<<28)   |(0x4<<20) |(0x2<<16) |(0xC3<<8) |(0xC7)    /*!< APB = 16MHz; CLK = 10kHz */
#define CLK100kHz16M    (0x3<<28)   |(0xF<<20) |(0x2<<16) |(0xF<<8)  |(0x13)    /*!< APB = 16MHz; CLK = 100kHz */
#define CLK400kHz16M    (0x1<<28)   |(0x3<<20) |(0x2<<16) |(0x3<<8)  |(0x9)     /*!< APB = 16MHz; CLK = 400kHz */
#define CLK1000kHz16M   (0x0<<28)   |(0x2<<20) |(0x0<<16) |(0x2<<8)  |(0x4)     /*!< APB = 16MHz; CLK = 1000kHz */
#define CLK10kHz48M     (0xBU<<28)  |(0x4<<20) |(0x2<<16) |(0xC3<<8) |(0xC7)    /*!< APB = 48MHz; CLK = 10kHz */
#define CLK100kHz48M    (0xBU<<28)  |(0x4<<20) |(0x2<<16) |(0xF<<8)  |(0x13)    /*!< APB = 48MHz; CLK = 100kHz */
#define CLK400kHz48M    (0x5<<28)   |(0x3<<20) |(0x3<<16) |(0x3<<8)  |(0x9)     /*!< APB = 48MHz; CLK = 400kHz */
#define CLK1000kHz48M   (0x5<<28)   |(0x1<<20) |(0x0<<16) |(0x1<<8)  |(0x3)     /*!< APB = 48MHz; CLK = 1000kHz */
#define CLK10kHz72M     (0xFU<<28)  |(0x4<<20) |(0x2<<16) |(0xDB<<8) |(0xE1)    /*!< APB = 72MHz; CLK = 10kHz */
#define CLK100kHz72M    (0x8U<<28)  |(0x6<<20) |(0x3<<16) |(0x23<<8) |(0x24)    /*!< APB = 72MHz; CLK = 100kHz */
#define CLK400kHz72M    (0x8U<<28)  |(0x3<<20) |(0x3<<16) |(0x3<<8)  |(0x7)     /*!< APB = 72MHz; CLK = 400kHz */
#define CLK1000kHz72M   (0x0U<<28)  |(0x1<<20) |(0x0<<16) |(0x2<<8)  |(0x4)     /*!< APB = 72MHz; CLK = 1000kHz */

#define MD_I2C_MODE_NONE                ((uint8_t)0x00U)             /*!< None */
#define MD_I2C_MODE_MASTER              ((uint8_t)0x10U)             /*!< Master */
#define MD_I2C_MODE_SLAVE               ((uint8_t)0x20U)             /*!< Slave */
#define MD_I2C_MODE_MEM                 ((uint8_t)0x40U)             /*!< Mem */

#define MD_I2C_MODE_RELOAD    (I2C_CON2_RELOAD)
#define MD_I2C_MODE_AUTOEND   (I2C_CON2_AUTOEND)
#define MD_I2C_MODE_SOFTEND   (0x0U)
#define MD_I2C_MODE_SMBUS_RELOAD  MD_I2C_MODE_RELOAD
#define MD_I2C_MODE_SMBUS_AUTOEND_NO_PEC    MD_I2C_MODE_AUTOEND
#define MD_I2C_MODE_SMBUS_SOFTEND_NO_PEC    MD_I2C_MODE_SOFTEND
#define MD_I2C_MODE_SMBUS_AUTOEND_WITH_PEC  (uint32_t)(MD_I2C_MODE_AUTOEND | I2C_CON2_PECBYTE)
#define MD_I2C_MODE_SMBUS_SOFTEND_WITH_PEC  (uint32_t)(MD_I2C_MODE_SOFTEND | I2C_CON2_PECBYTE)

#define MD_I2C_REQUEST_NOSTARTSTOP          (0x0U)
#define MD_I2C_REQUEST_STOP                 I2C_CON2_STOP
#define MD_I2C_REQUEST_START_READ           (uint32_t)(I2C_CON2_START|I2C_CON2_RD_WRN)
#define MD_I2C_REQUEST_START_WRITE          (uint32_t)(I2C_CON2_START)
#define MD_I2C_REQUEST_RESTART_7BIT_READ    (uint32_t)(I2C_CON2_START|I2C_CON2_RD_WRN)
#define MD_I2C_REQUEST_RESTART_7BIT_WRITE   (uint32_t)(I2C_CON2_START)
#define MD_I2C_REQUEST_RESTART_10BIT_READ   (uint32_t)(I2C_CON2_START|I2C_CON2_HEAD10R|I2C_CON2_RD_WRN);
#define MD_I2C_REQUEST_RESTART_10BIT_WRITE  (uint32_t)(I2C_CON2_START);

#define MD_I2C_ADDRESS_SIZE_7BIT  0
#define MD_I2C_ADDRESS_SIZE_10BIT 1


/* I2C_MASTER_WriteRead macros define*/
#define MD_I2C_WRITE 0
#define MD_I2C_READ  1
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions I2C Public Functions
  * @{
  */

/** @defgroup MD_I2C_Public_Functions_Group2 CON1
  * @{
  */
/**
  * @brief  I2C Set CON1
  * @note   These bits must be configured when the I2C is disabled (PE = 0) except TXDMAEN and RXDMAEN.
  * @param  I2Cx I2C Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_con1(I2C_TypeDef *I2Cx, uint32_t Reg_Value)
{
    WRITE_REG(I2Cx->CON1, Reg_Value);
}

/**
  * @brief  I2C Get CON1
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_i2c_get_con1(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_REG(I2Cx->CON1));
}

/**
  * @brief  Set I2C number of bytes
  * @note   The number of bytes to be transmitted/received is programmed there.
  *         This field is don't care in slave mode with SBC=0.
  *         Changing these bits when the START bit is set is not allowed.
  * @param  I2Cx I2C Instance
  * @param  nbytes number of bytes
  *         @arg Max Value 0xFFFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_transmit_length(I2C_TypeDef *I2Cx, uint32_t nbytes)
{
    nbytes &= 0xffff; //mask bit31~bit16

    if (nbytes >= 0xff)
    {
        MODIFY_REG(I2Cx->CON1, I2C_CON1_NBYTES, ((nbytes) >> 8) << I2C_CON1_NBYTES_POSS);
    }

    nbytes &= 0xff; //mask bit31~bit8
    MODIFY_REG(I2Cx->CON2, I2C_CON2_NBYTES, nbytes << I2C_CON2_NBYTES_POSS);
}

/**
  * @brief  Get I2C number of bytes
  * @note   The number of bytes to be transmitted/received is programmed there.
  *         This field is don't care in slave mode with SBC=0.
  *         Changing these bits when the START bit is set is not allowed.
  * @param  I2Cx I2C Instance
  * @retval The retval can be a value of the area:
  *         @arg Max Value 0xFFFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_i2c_get_transmit_length(I2C_TypeDef *I2Cx)
{
    uint32_t high_nbytes = ((READ_BIT(I2Cx->CON1, I2C_CON1_NBYTES) >> I2C_CON1_NBYTES_POSS) & 0Xff);
    uint32_t low_nbytes = ((READ_BIT(I2Cx->CON2, I2C_CON2_NBYTES) >> I2C_CON2_NBYTES_POSS) & 0xff);

    return (uint32_t)((high_nbytes << 8) | (low_nbytes));
}

/**
  * @brief  I2C PEC Enable
  * @note   If the SMBus feature is not supported,this bit is reserved and forced by hardware to 0.
  *         This register must be configured when the I2C is disabled (PE = 0).
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_smbus_pec(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON1, I2C_CON1_PECEN);
}

/**
  * @brief  I2C PEC Disable
  * @note   If the SMBus feature is not supported,this bit is reserved and forced by hardware to 0.
  *         This register must be configured when the I2C is disabled (PE = 0).
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_smbus_pec(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->CON1, I2C_CON1_PECEN);
}

/**
  * @brief  Indicate if I2C PEC is enabled
  * @note   If the SMBus feature is not supported,this bit is reserved and forced by hardware to '0'
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_smbus_pec(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON1, I2C_CON1_PECEN) == (I2C_CON1_PECEN));
}

/**
  * @brief  I2C Alert Enable
  * @note   When ALERTEN = 0, the SMBA pin can be used as a standard GPIO.If the SMBus feature is not supported, this bit is reserved and forced by hardware to 0.
  *         This register must be configured when the I2C is disabled (PE = 0).
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_smbus_alert(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON1, I2C_CON1_ALERTEN);
}

/**
  * @brief  I2C Alert Disable
  * @note   When ALERTEN = 0, the SMBA pin can be used as a standard GPIO.If the SMBus feature is not supported, this bit is reserved and forced by hardware to 0.
  *         This register must be configured when the I2C is disabled (PE = 0).
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_smbus_alert(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->CON1, I2C_CON1_ALERTEN);
}

/**
  * @brief  Indicate if I2C PEC is enabled
  * @note   When ALERTEN = 0, the SMBA pin can be used as a standard GPIO.If the SMBus feature is not supported, this bit is reserved and forced by hardware to 0.
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_smbus_alert(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON1, I2C_CON1_ALERTEN) == (I2C_CON1_ALERTEN));
}

/**
  * @brief  I2C SMBus Device Default address Enable
  * @note   If the SMBus feature is not supported,this bit is reserved and forced by hardware to 0. Device default address 0b1100 001.
  *         This register must be configured when the I2C is disabled (PE = 0).
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_smbus_slave_addr(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON1, I2C_CON1_SMBDEN);
}

/**
  * @brief  I2C SMBus Device Default address Disable
  * @note   If the SMBus feature is not supported,this bit is reserved and forced by hardware to 0. Device default address 0b1100 001.
  *         This register must be configured when the I2C is disabled (PE = 0).
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_smbus_slave_addr(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->CON1, I2C_CON1_SMBDEN);
}

/**
  * @brief  Indicate if I2C SMBus Device Default address is enabled
  * @note   If the SMBus feature is not supported,this bit is reserved and forced by hardware to 0. Device default address 0b1100 001.
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_smbus_slave_addr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON1, I2C_CON1_SMBDEN) == (I2C_CON1_SMBDEN));
}

/**
  * @brief  I2C SMBus Host address Enable
  * @note   If the SMBus feature is not supported,this bit is reserved and forced by hardware to 0. Host default address 0b0001 000.
  *         This register must be configured when the I2C is disabled (PE = 0).
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_smbus_host_addr(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON1, I2C_CON1_SMBHEN);
}

/**
  * @brief  I2C SMBus Host address Disable
  * @note   If the SMBus feature is not supported,this bit is reserved and forced by hardware to 0. Host default address 0b0001 000.
  *         This register must be configured when the I2C is disabled (PE = 0).
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_smbus_host_addr(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->CON1, I2C_CON1_SMBHEN);
}

/**
  * @brief  Indicate if I2C SMBus Host address is enabled
  * @note   If the SMBus feature is not supported,this bit is reserved and forced by hardware to 0. Host default address 0b0001 000.
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_smbus_host_addr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON1, I2C_CON1_SMBHEN) == (I2C_CON1_SMBHEN));
}

/**
  * @brief  I2C general call Enable
  * @note   This register must be configured when the I2C is disabled (PE = 0).
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_general_call(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON1, I2C_CON1_GCEN);
}

/**
  * @brief  I2C general call Disable
  * @note   This register must be configured when the I2C is disabled (PE = 0).
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_general_call(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->CON1, I2C_CON1_GCEN);
}

/**
  * @brief  Indicate if I2C general call is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_general_call(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON1, I2C_CON1_GCEN) == (I2C_CON1_GCEN));
}

/**
  * @brief  I2C clock stretching Disable
  * @note   Clock stretching disables. This bit can only be programmed when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_scl_nostretch(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON1, I2C_CON1_NOSTRETCH);
}

/**
  * @brief  I2C clock stretching Enable
  * @note   Clock stretching enables.This bit can only be programmed when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_scl_nostretch(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->CON1, I2C_CON1_NOSTRETCH);
}

/**
  * @brief  Indicate if I2C clock nostretching is enabled
  * @note   This bit can only be programmed when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_scl_nostretch(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON1, I2C_CON1_NOSTRETCH) == (I2C_CON1_NOSTRETCH));
}

/**
  * @brief  I2C slave byte control Enable
  * @note   This bit can only be programmed when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_slave_byte_control(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON1, I2C_CON1_SBC);
}

/**
  * @brief  I2C slave byte control Disable
  * @note   This bit can only be programmed when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_slave_byte_control(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->CON1, I2C_CON1_SBC);
}

/**
  * @brief  Indicate if I2C slave byte control is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_slave_byte_control(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON1, I2C_CON1_SBC) == (I2C_CON1_SBC));
}

/**
  * @brief  I2C DMA receiver requests Enable
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_dma_receive(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON1, I2C_CON1_RXDMAEN);
}

/**
  * @brief  I2C DMA receiver requests Disable
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_dma_receive(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->CON1, I2C_CON1_RXDMAEN);
}

/**
  * @brief  Indicate if I2C DMA receiver requests is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_dma_receive(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON1, I2C_CON1_RXDMAEN) == (I2C_CON1_RXDMAEN));
}

/**
  * @brief  I2C DMA transmitter requests Enable
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_dma_transmit(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON1, I2C_CON1_TXDMAEN);
}

/**
  * @brief  I2C DMA transmitter requests Disable
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_dma_transmit(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->CON1, I2C_CON1_TXDMAEN);
}

/**
  * @brief  Indicate if I2C DMA transmitter requests is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_dma_transmit(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON1, I2C_CON1_TXDMAEN) == (I2C_CON1_TXDMAEN));
}

/**
  * @brief  Set I2C digital noise filter
  * @note   If the analog filter is also enabled,the digital filter is added to the analog filter.
  *         This filter can only be programmed when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @param  filter_capability digital noise filter capability
  *         @arg @ref MD_I2C_DNF_DISABLE
  *         @arg @ref MD_I2C_DNF_1T
  *         @reg @ref MD_I2C_DNF_2T
  *         @reg @ref MD_I2C_DNF_3T
  *         @reg @ref MD_I2C_DNF_4T
  *         @reg @ref MD_I2C_DNF_5T
  *         @reg @ref MD_I2C_DNF_6T
  *         @reg @ref MD_I2C_DNF_7T
  *         @reg @ref MD_I2C_DNF_8T
  *         @reg @ref MD_I2C_DNF_9T
  *         @reg @ref MD_I2C_DNF_10T
  *         @reg @ref MD_I2C_DNF_11T
  *         @reg @ref MD_I2C_DNF_12T
  *         @reg @ref MD_I2C_DNF_13T
  *         @reg @ref MD_I2C_DNF_14T
  *         @reg @ref MD_I2C_DNF_15T
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_digit_filter(I2C_TypeDef *I2Cx, uint32_t filter_capability)
{
    MODIFY_REG(I2Cx->CON1, I2C_CON1_DNF, filter_capability << I2C_CON1_DNF_POSS);
}

/**
  * @brief  Get I2C digital noise filter
  * @note   If the analog filter is also enabled,the digital filter is added to the analog filter.
  *         This filter can only be programmed when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_I2C_DNF_DISABLE
  *         @arg @ref MD_I2C_DNF_1T
  *         @reg @ref MD_I2C_DNF_2T
  *         @reg @ref MD_I2C_DNF_3T
  *         @reg @ref MD_I2C_DNF_4T
  *         @reg @ref MD_I2C_DNF_5T
  *         @reg @ref MD_I2C_DNF_6T
  *         @reg @ref MD_I2C_DNF_7T
  *         @reg @ref MD_I2C_DNF_8T
  *         @reg @ref MD_I2C_DNF_9T
  *         @reg @ref MD_I2C_DNF_10T
  *         @reg @ref MD_I2C_DNF_11T
  *         @reg @ref MD_I2C_DNF_12T
  *         @reg @ref MD_I2C_DNF_13T
  *         @reg @ref MD_I2C_DNF_14T
  *         @reg @ref MD_I2C_DNF_15T
  */
__STATIC_INLINE uint32_t md_i2c_get_digit_filter(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->CON1, I2C_CON1_DNF) >> I2C_CON1_DNF_POSS);
}

/**
  * @brief  I2C Peripheral Enable
  * @note   When PE = 0, the I2C SCL and SDA lines are released.
  *         Internal state machines and status bits are put back to their reset value.
  *         When cleared, PE must be kept low for at least 3 APB clock cycles.
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_pe(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON1, I2C_CON1_PE);
}

/**
  * @brief  I2C Peripheral Disable
  * @note   When PE = 0, the I2C SCL and SDA lines are released.Internal state machines and status bits are put back to their reset value.When cleared,PE must be kept low for at least 3 APB clock cycles
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_pe(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->CON1, I2C_CON1_PE);
}

/**
  * @brief  Indicate if Peripheral is enabled
  * @note   When PE = 0, the I2C SCL and SDA lines are released.Internal state machines and status bits are put back to their reset value.When cleared,PE must be kept low for at least 3 APB clock cycles
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_pe(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON1, I2C_CON1_PE) == (I2C_CON1_PE));
}
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions_Group3 CON2
  * @{
  */
/**
  * @brief  I2C Set CON2
  * @note   None
  * @param  I2Cx I2C Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_con2(I2C_TypeDef *I2Cx, uint32_t Reg_Value)
{
    WRITE_REG(I2Cx->CON2, Reg_Value);
}

/**
  * @brief  I2C Get CON2
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_i2c_get_con2(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_REG(I2Cx->CON2));
}

/**
  * @brief  Enable I2C Packet error checking byte
  * @note   This bit is enable by software, and cleared by hardware when the PEC is transferred,
  *         or when a STOP condition or an Address matched is received, also when PE=0.
  *         Writing 0 to this bit has no effet. This bit has no effect when RELOAD is set,
  *         and when SBC is 0 in the slave mode.
  *         If the SMBus feature is not supported, this bit is reserved and forced by hardware to 0.
  * @param  I2Cx I2C Instance
  * @retval None

  */
__STATIC_INLINE void md_i2c_enable_pec_byte(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON2, I2C_CON2_PECBYTE);
}

/**
  * @brief  Check if the I2C Packet error checking byte is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_pec_byte(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON2, I2C_CON2_PECBYTE) == (I2C_CON2_PECBYTE));
}

/**
  * @brief  Enable I2C auto end function.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_auto_end(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON2, I2C_CON2_AUTOEND);
}

/**
  * @brief  Disable I2C auto end function.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_auto_end(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->CON2, I2C_CON2_AUTOEND);
}

/**
  * @brief  Check if I2C auto end function is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_auto_end(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON2, I2C_CON2_AUTOEND) == (I2C_CON2_AUTOEND));
}

/**
  * @brief  Enable I2C reload fuctions.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_reload(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON2, I2C_CON2_RELOAD);
}

/**
  * @brief  Disable I2C reload fuctions.
  * @param  I2Cx I2C Instance.
  * @retval None

  */
__STATIC_INLINE void md_i2c_disable_reload(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->CON2, I2C_CON2_RELOAD);
}

/**
  * @brief  Check if I2C reload fuctions is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).

  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_reload(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON2, I2C_CON2_RELOAD) == (I2C_CON2_RELOAD));
}

/**
  * @brief  Set I2C send NACK.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_nack(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON2, I2C_CON2_NACK);
}

/**
  * @brief  Get I2C NACK bit state(slave mode)
  * @note   NACK=1: will generate NACK
  *         NACK=0: will generate ACK
  * @param  I2Cx I2C Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_I2C_ACK
  *         @arg @ref MD_I2C_NACK
  */
__STATIC_INLINE uint32_t md_i2c_get_nack(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->CON2, I2C_CON2_NACK) >> I2C_CON2_NACK_POS);
}

/**
  * @brief  Set I2C Stop generation(master mode)
  * @note   Writing 0 to this bit has no effect.
  * @param  I2Cx I2C Instance
  * @retval None

  */
__STATIC_INLINE void md_i2c_set_stop(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON2, I2C_CON2_STOP);
}

/**
  * @brief  Get I2C state of STOP bit(master mode)
  * @note   Writing 0 to this bit has no effect.
  * @param  I2Cx I2C Instance
  * @retval The retval can be one of the following values:
  *         @arg MD_I2C_STOP_NO
  *         @arg MD_I2C_STOP_GENERATION
  */
__STATIC_INLINE uint32_t md_i2c_get_stop(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->CON2, I2C_CON2_STOP) >> I2C_CON2_STOP_POS);
}

/**
  * @brief  Set I2C Start generation
  * @note   Writing 0 to this bit has no effect.The START bit can be set even if the bus is BUSY or I2C is in slave mode.
  *         In 10-bit addressing mode, if a NACK is received on the first part of the address,
  *         the START bit is not cleared by hardware and the master will resend the address sequence.
  * @param  I2Cx I2C Instance
  * @retval None

 */
__STATIC_INLINE void md_i2c_set_start(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON2, I2C_CON2_START);
}

/**
  * @brief  Get I2C state of START bit
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval The retval can be one of the following values:
  *         @arg MD_I2C_START_NO
  *         @arg MD_I2C_START_GENERATION
  */
__STATIC_INLINE uint32_t md_i2c_get_start(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->CON2, I2C_CON2_START) >> I2C_CON2_START_POS);
}

/**
  * @brief  Enable i2c send 10-bit standard address header.
  * @param  I2Cx I2C Instance.
  * @retval None
  frome M950
  */
__STATIC_INLINE void md_i2c_enable_standard_10_bit_header(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON2, I2C_CON2_HEAD10R);
}

/**
  * @brief  Disable i2c send 10-bit standard address header.
  * @param  I2Cx I2C Instance.
  * @retval None

  */
__STATIC_INLINE void md_i2c_disable_standard_10_bit_header(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->CON2, I2C_CON2_HEAD10R);
}

/**
  * @brief  Check if i2c send 10-bit standard address header is enabled or disable.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).

  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_standard_10_bit_header(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON2, I2C_CON2_HEAD10R) == (I2C_CON2_HEAD10R));
}

/**
  * @brief  Enable 10-bit address mode.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_addr_10_bit(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON2, I2C_CON2_ADD10);
}

/**
  * @brief  Enable 7-bit address mode.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_addr_7_bit(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->CON2, I2C_CON2_ADD10);
}

/**
  * @brief  Check if is enabled 10-bit address mode.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_addr_10_bit(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON2, I2C_CON2_ADD10) == (I2C_CON2_ADD10));
}

/**
  * @brief  Check if is enabled 7-bit address mode.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_addr_7_bit(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON2, I2C_CON2_ADD10) != (I2C_CON2_ADD10));
}

/**
  * @brief  Enable i2c master read.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_master_read(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->CON2, I2C_CON2_RD_WRN);
}

/**
  * @brief  Enable i2c master write.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_master_write(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->CON2, I2C_CON2_RD_WRN);
}

/**
  * @brief  Check if is enabled master read.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_master_read(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON2, I2C_CON2_RD_WRN) == (I2C_CON2_RD_WRN));
}

/**
  * @brief  Check if is enabled master write.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_master_write(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->CON2, I2C_CON2_RD_WRN) != (I2C_CON2_RD_WRN));
}

/**
  * @brief  Set I2C slave address(master mode)
  * @note   Changing these bits when the START bit is set is not allowed
  *         For 7-bit mode, bit 7 to 1 are valid; for 10-bit mode, all 10 bits are valid.
  * @param  I2Cx I2C Instance
  * @param  slave_addr I2C slave address
  *         @arg Max Value 7-bit: 0xFE / 10-bit: 0x3FF
  *         @arg Min Value 7-bit: 0x2 / 10-bit: 0x0
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_slave_addr(I2C_TypeDef *I2Cx, uint32_t addr)
{
    MODIFY_REG(I2Cx->CON2, I2C_CON2_SADD, (addr << I2C_CON2_SADD_POSS));
}

/**
  * @brief  Get I2C slave address(master mode)
  * @note   Changing these bits when the START bit is set is not allowed
  *         For 7-bit mode, bit 7 to 1 are valid; for 10-bit mode, all 10 bits are valid.
  * @param  I2Cx I2C Instance
  * @retval I2C slave address
  *         @arg Max Value 7-bit: 0xFE / 10-bit: 0x3FF
  *         @arg Min Value 7-bit: 0x2 / 10-bit: 0x0
  */
__STATIC_INLINE uint32_t md_i2c_get_slave_addr(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->CON2, I2C_CON2_SADD));
}
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions_Group4 ADDR1
  * @{
  */
/**
  * @brief  Set I2C ADDR1
  * @note   These bits can be written only when OA1EN=0 except OA1EN.
  * @param  I2Cx I2C Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_addr1(I2C_TypeDef *I2Cx, uint32_t Reg_Value)
{
    WRITE_REG(I2Cx->ADDR1, Reg_Value);
}

/**
  * @brief  Get I2C ADDR1
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_i2c_get_addr1(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_REG(I2Cx->ADDR1));
}

/**
  * @brief  I2C address register 1 Enable
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_own1_addr(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ADDR1, I2C_ADDR1_OA1EN);
}

/**
  * @brief  I2C address register 1 Disable
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_own1_addr(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->ADDR1, I2C_ADDR1_OA1EN);
}

/**
  * @brief  Indicate if address register 1 is enabled
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_own1_addr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->ADDR1, I2C_ADDR1_OA1EN) == (I2C_ADDR1_OA1EN));
}



/**
  * @brief  Enable i2c own1 10_bit address.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_own1_10_bit_addr(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ADDR1, I2C_ADDR1_OA1MODE);
}

/**
  * @brief  Enable i2c own1 7_bit address.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_own1_7_bit_addr(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->ADDR1, I2C_ADDR1_OA1MODE);
}

/**
  * @brief  Check if is enabled i2c own1 10_bit address.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_own1_10_bit_addr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->ADDR1, I2C_ADDR1_OA1MODE) == (I2C_ADDR1_OA1MODE));
}

/**
  * @brief  Check if is enabled i2c own1 7_bit address.
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_own1_7_bit_addr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->ADDR1, I2C_ADDR1_OA1MODE) != (I2C_ADDR1_OA1MODE));
}

/**
  * @brief  Set I2C address1
  * @note   For 7-bit mode, bit 7 to 1 are valid; for 10-bit mode, all 10 bits are valid.
  * @param  I2Cx I2C Instance
  * @param  own_addr I2C own address1
  *         @arg Max Value 7-bit: 0xFE / 10-bit: 0x3FF
  *         @arg Min Value 7-bit: 0x2 / 10-bit: 0x0
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_own1_addr(I2C_TypeDef *I2Cx, uint32_t own_addr)
{
    MODIFY_REG(I2Cx->ADDR1, I2C_ADDR1_OA1, own_addr);
}

/**
  * @brief  Get I2C address1
  * @note   For 7-bit mode, bit 7 to 1 are valid; for 10-bit mode, all 10 bits are valid.
  * @param  I2Cx I2C Instance
  * @retval I2C own address1
  *         @arg Max Value 7-bit: 0xFE / 10-bit: 0x3FF
  *         @arg Min Value 7-bit: 0x2 / 10-bit: 0x0
  */
__STATIC_INLINE uint32_t md_i2c_get_own1_addr(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->ADDR1, I2C_ADDR1_OA1));
}
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions_Group5 ADDR2
  * @{
  */
/**
  * @brief  Set I2C ADDR2
  * @note   These bits can be written only when OA2EN=0 except OA2EN.
  * @param  I2Cx I2C Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_addr2(I2C_TypeDef *I2Cx, uint32_t Reg_Value)
{
    WRITE_REG(I2Cx->ADDR2, Reg_Value);
}

/**
  * @brief  Get I2C ADDR2
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_i2c_get_addr2(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_REG(I2Cx->ADDR2));
}

/**
  * @brief  I2C own address register 2 Enable
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_own2_addr(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ADDR2, I2C_ADDR2_OA2EN);
}

/**
  * @brief  I2C own address register 2 Disable
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_own2_addr(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->ADDR2, I2C_ADDR2_OA2EN);
}

/**
  * @brief  Indicate if address register 2 is enabled
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_own2_addr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->ADDR2, I2C_ADDR2_OA2EN) == (I2C_ADDR2_OA2EN));
}

/**
  * @brief  Set I2C own address2 mask
  * @note   These bits can be written only when OA2EN=0.
  *         As soon as OA2MSK is not equal to 0,the reserved I2C addresses(0b0000xxx and 0b1111xxx) are not acknowledged even if the comparison matches.
  * @param  I2Cx I2C Instance
  * @param  oa2_mask I2C own address2 mask
  *         @arg @ref MD_I2C_ADDR2_NOMASK
  *         @arg @ref MD_I2C_ADDR2_MASK01
  *         @arg @ref MD_I2C_ADDR2_MASK02
  *         @arg @ref MD_I2C_ADDR2_MASK03
  *         @arg @ref MD_I2C_ADDR2_MASK04
  *         @arg @ref MD_I2C_ADDR2_MASK05
  *         @arg @ref MD_I2C_ADDR2_MASK06
  *         @arg @ref MD_I2C_ADDR2_MASK07
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_own2_mask_addr(I2C_TypeDef *I2Cx, uint32_t oa2_mask)
{
    MODIFY_REG(I2Cx->ADDR2, I2C_ADDR2_OA2MSK, oa2_mask << I2C_ADDR2_OA2MSK_POSS);
}

/**
  * @brief  Get I2C address2 mask
  * @note   None
  *         As soon as OA2MSK is not equal to 0,the reserved I2C addresses(0b0000xxx and 0b1111xxx) are not acknowledged even if the comparison matches.
  * @param  I2Cx I2C Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_I2C_ADDR2_NOMASK
  *         @arg @ref MD_I2C_ADDR2_MASK01
  *         @arg @ref MD_I2C_ADDR2_MASK02
  *         @arg @ref MD_I2C_ADDR2_MASK03
  *         @arg @ref MD_I2C_ADDR2_MASK04
  *         @arg @ref MD_I2C_ADDR2_MASK05
  *         @arg @ref MD_I2C_ADDR2_MASK06
  *         @arg @ref MD_I2C_ADDR2_MASK07
  */
__STATIC_INLINE uint32_t md_i2c_get_own2_mask_addr(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->ADDR2, I2C_ADDR2_OA2MSK) >> I2C_ADDR2_OA2MSK_POSS);
}

/**
  * @brief  Set I2C own address2
  * @note   These bits can be written only when OA2EN=0.
  * @param  I2Cx I2C Instance
  * @param  own_addr I2C own address2
  *         @arg Max Value 0x7F
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_own2_addr(I2C_TypeDef *I2Cx, uint32_t own_addr)
{
    MODIFY_REG(I2Cx->ADDR2, I2C_ADDR2_OA2, own_addr << I2C_ADDR2_OA2_POSS);
}

/**
  * @brief  Get I2C own address2
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval I2C own address2
  *         @arg Max Value 0x7F
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_i2c_get_own2_addr(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->ADDR2, I2C_ADDR2_OA2) >> I2C_ADDR2_OA2_POSS);
}
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions_Group6 TIMINGR
  * @{
  */
/**
  * @brief  Set I2C TIMINGR
  * @note   These bits must be configured when the I2C is disabled (PE = 0).
  * @param  I2Cx I2C Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_timingr(I2C_TypeDef *I2Cx, uint32_t Reg_Value)
{
    WRITE_REG(I2Cx->TIMINGR, Reg_Value);
}

/**
  * @brief  Get I2C TIMINGR
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_i2c_get_timingr(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_REG(I2Cx->TIMINGR));
}

/**
  * @brief  Set I2C Timing prescaler
  * @note   This register must be configured when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @param  timing_prescaler
  *         @arg Max Value 0xF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_clock_prescaler(I2C_TypeDef *I2Cx, uint32_t timing_prescaler)
{
    MODIFY_REG(I2Cx->TIMINGR, I2C_TIMINGR_PRESC, timing_prescaler << I2C_TIMINGR_PRESC_POSS);
}

/**
  * @brief  Get I2C Timing prescaler
  * @note   This register must be configured when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @retval timing_prescaler
  *         @arg Max Value 0xF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_i2c_get_clock_prescaler(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->TIMINGR, I2C_TIMINGR_PRESC) >> I2C_TIMINGR_PRESC_POSS);
}

/**
  * @brief  Set I2C date setup time
  * @note   This register must be configured when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @param  data_setup_time
  *         @arg Max Value 0xF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_data_setup_time(I2C_TypeDef *I2Cx, uint32_t data_setup_time)
{
    MODIFY_REG(I2Cx->TIMINGR, I2C_TIMINGR_SCLDEL, data_setup_time << I2C_TIMINGR_SCLDEL_POSS);
}

/**
  * @brief  Get I2C date setup time
  * @note   This register must be configured when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @retval data_setup_time
  *         @arg Max Value 0xF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_i2c_get_data_setup_time(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->TIMINGR, I2C_TIMINGR_SCLDEL) >> I2C_TIMINGR_SCLDEL_POSS);
}

/**
  * @brief  Set I2C date hold time
  * @note   This register must be configured when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @param  data_hold_time
  *         @arg Max Value 0xF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_data_hold_time(I2C_TypeDef *I2Cx, uint32_t data_hold_time)
{
    MODIFY_REG(I2Cx->TIMINGR, I2C_TIMINGR_SDADEL, data_hold_time << I2C_TIMINGR_SDADEL_POSS);
}

/**
  * @brief  Get I2C date hold time
  * @note   This register must be configured when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @retval data_hold_time
  *         @arg Max Value 0xF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_i2c_get_data_hold_time(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->TIMINGR, I2C_TIMINGR_SDADEL) >> I2C_TIMINGR_SDADEL_POSS);
}

/**
  * @brief  Set I2C Clock high period(master mode)
  * @note   This register must be configured when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @param  SCL_hperiod
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_clock_high_period(I2C_TypeDef *I2Cx, uint32_t SCL_hperiod)
{
    MODIFY_REG(I2Cx->TIMINGR, I2C_TIMINGR_SCLH, SCL_hperiod << I2C_TIMINGR_SCLH_POSS);
}

/**
  * @brief  Get I2C Clock high period(master mode)
  * @note   This register must be configured when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @retval SCL_hperiod
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_i2c_get_clock_high_period(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->TIMINGR, I2C_TIMINGR_SCLH) >> I2C_TIMINGR_SCLH_POSS);
}

/**
  * @brief  Set I2C Clock low period(master mode)
  * @note   This register must be configured when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @param  SCL_lperiod
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_clock_low_period(I2C_TypeDef *I2Cx, uint32_t SCL_lperiod)
{
    MODIFY_REG(I2Cx->TIMINGR, I2C_TIMINGR_SCLL, SCL_lperiod << I2C_TIMINGR_SCLL_POSS);
}

/**
  * @brief  Get I2C Clock low period(master mode)
  * @note   This register must be configured when the I2C is disabled(PE = 0)
  * @param  I2Cx I2C Instance
  * @retval SCL_lperiod
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_i2c_get_clock_low_period(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->TIMINGR, I2C_TIMINGR_SCLL));
}
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions_Group7 TIMEOUTR
  * @{
  */
/**
  * @brief  Set I2C TIMEOUTR
  * @note   These bits can be written only when TEXTEN=0 and TIMEOUTEN=0 except TEXTEN and TIMEOUTEN.
  * @param  I2Cx I2C Instance
  * @param  Reg_Value is a 32-bit value
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_timeoutr(I2C_TypeDef *I2Cx, uint32_t Reg_Value)
{
    WRITE_REG(I2Cx->TIMEOUTR, Reg_Value);
}

/**
  * @brief  Get I2C TIMEOUTR
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_i2c_get_timeoutr(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_REG(I2Cx->TIMEOUTR));
}

/**
  * @brief  I2C Extended clock timeout Enable
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_texten(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TEXTEN);
}

/**
  * @brief  I2C Extended clock timeout Disable
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_texten(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TEXTEN);
}

/**
  * @brief  Indicate if I2C Extended clock timeout is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_texten(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TEXTEN) == (I2C_TIMEOUTR_TEXTEN));
}

/**
  * @brief  Set I2C Bus timeout B
  * @note   These bits can be written only when TEXTEN = 0
  * @param  I2Cx I2C Instance
  * @param  timeoutb Bus timeout B
  *         @arg Max Value 0xFFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_bus_timeout_b(I2C_TypeDef *I2Cx, uint32_t timeoutb)
{
    MODIFY_REG(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TIMEOUTB, timeoutb << I2C_TIMEOUTR_TIMEOUTB_POSS);
}

/**
  * @brief  Get I2C Bus timeout B
  * @note   These bits can be written only when TEXTEN = 0
  * @param  I2Cx I2C Instance
  * @retval Bus timeout B
  *         @arg Max Value 0xFFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_i2c_get_bus_timeout_b(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TIMEOUTB) >> I2C_TIMEOUTR_TIMEOUTB_POSS);
}

/**
  * @brief  I2C clock timeout Enable
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_timeouten(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TIMEOUTEN);
}

/**
  * @brief  I2C clock timeout Disable
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_timeouten(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TIMEOUTEN);
}

/**
  * @brief  Indicate if I2C clock timeout is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_timeouten(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TIMEOUTEN) == (I2C_TIMEOUTR_TIMEOUTEN));
}



/**
  * @brief  Enable i2c idle state timeout detect function.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_idle_timeout(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TIDLE);
}

/**
  * @brief  Enable i2c idle state timeout detect function.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_scl_low_timeout(I2C_TypeDef *I2Cx)
{
    CLEAR_BIT(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TIDLE);
}


/**
  * @brief  Check if is enabled i2c idle state timeout detect function
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_idle_timeout(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TIDLE) == (I2C_TIMEOUTR_TIDLE));
}

/**
  * @brief  Set I2C Bus timeout A
  * @note   These bits can be written only when TIMOUTEN = 0
  * @param  I2Cx I2C Instance
  * @param  timeouta Bus timeout A
  *         @arg Max Value 0xFFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_bus_timeout_a(I2C_TypeDef *I2Cx, uint32_t timeouta)
{
    MODIFY_REG(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TIMEOUTA, timeouta);
}

/**
  * @brief  Get I2C Bus timeout A
  * @note   These bits can be written only when TIMOUTEN = 0
  * @param  I2Cx I2C Instance
  * @retval Bus timeout A
  *         @arg Max Value 0xFFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_i2c_get_bus_timeout_a(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->TIMEOUTR, I2C_TIMEOUTR_TIMEOUTA));
}
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions_Group8 STAT
  * @{
  */
/**
  * @brief  Get I2C STAT
  * @note   All bits are read-only
  * @param  I2Cx I2C Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_i2c_get_stat(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_REG(I2Cx->STAT));
}

/**
  * @brief  Get address match code(slave mode)
  * @note   These bits are updated with the received address when an address match event occurs(ADDR=1).
  * @param  I2Cx I2C Instance
  * @retval 7-bit received address value
  */
__STATIC_INLINE uint32_t md_i2c_get_addr_match(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->STAT, I2C_STAT_ADDCODE) >> (I2C_STAT_ADDCODE_POSS));
}


/**
  * @brief  Get slave module write.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_flag_write(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->STAT, I2C_STAT_DIR) != (I2C_STAT_DIR));
}


/**
  * @brief  Get slave module read.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_flag_read(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->STAT, I2C_STAT_DIR) == (I2C_STAT_DIR));
}


/**
  * @brief  Indicate if I2C busy flag is active
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_flag_busy(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->STAT, I2C_STAT_BUSY) == (I2C_STAT_BUSY));
}

/**
  * @brief  Indicate if I2C transfer complete reload flag (TCR) is active
  * @note   This bit is cleared by hardware when PE = 0.
  *         This flag is only for master mode,or for slave mode when the SBC bit is set
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_flag_tcr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->STAT, I2C_STAT_TCR) == (I2C_STAT_TCR));
}

/**
  * @brief  Indicate if I2C transfer complete flag (TC) is active
  * @note   This bit is cleared by hardware when PE = 0.
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_flag_tc(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->STAT, I2C_STAT_TC) == (I2C_STAT_TC));
}

/**
  * @brief  Indicate if I2C Rx buffer underflow flag (RXUD) is active
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_flag_rxud(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->STAT, I2C_STAT_RXUD) == (I2C_STAT_RXUD));
}

/**
  * @brief  Indicate if I2C Rx buffer overflow flag (RXOV) is active
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_flag_rxov(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->STAT, I2C_STAT_RXOV) == (I2C_STAT_RXOV));
}

/**
  * @brief  Indicate if I2C Rx buffer not empty flag (RXNE) is active
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_flag_rxne(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->STAT, I2C_STAT_RXNE) == (I2C_STAT_RXNE));
}


/**
  * @brief  Indicate if I2C Tx buffer underflow flag (TXUD) is active
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_flag_txud(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->STAT, I2C_STAT_TXUD) == (I2C_STAT_TXUD));
}

/**
  * @brief  Indicate if I2C Tx buffer overflow flag (TXOV) is active
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_flag_txov(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->STAT, I2C_STAT_TXOV) == (I2C_STAT_TXOV));
}

/**
  * @brief  Indicate if I2C Tx buffer empty flag (TXE) is active
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_flag_txe(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->STAT, I2C_STAT_TXE) == (I2C_STAT_TXE));
}
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions_Group9 PECR
  * @{
  */
/**
  * @brief  Get packet error checking register
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval 8-bit pec value
  */
__STATIC_INLINE uint32_t md_i2c_get_rx_reg_pec(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_BIT(I2Cx->PECR, I2C_PECR_PEC));
}
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions_Group10 RXDATA
  * @{
  */
/**
  * @brief  Get receive data
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_i2c_get_rx_reg_data(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_REG(I2Cx->RXDATA));
}
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions_Group11 TXDATA
  * @{
  */
/**
  * @brief  8-bit transmit data
  * @note   These bits can be written only when TXE = 1.
  * @param  I2Cx I2C Instance
  * @param  txdata Transmit Data
  *         @arg Max value 0xFF
  *         @arg Min value 0
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_tx_reg_data(I2C_TypeDef *I2Cx, uint32_t txdata)
{
    MODIFY_REG(I2Cx->TXDATA, I2C_TXDATA_TXDATA, txdata);
}
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions_Group12 IER
  * @{
  */
/**
  * @brief  Set I2C IER
  * @note   None
  * @param  I2Cx I2C Instance
  * @param  ier
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_ier(I2C_TypeDef *I2Cx, uint32_t ier)
{
    WRITE_REG(I2Cx->IER, ier);
}

/**
  * @brief  Enable SMBus alert interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_alert(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_ALERT);
}

/**
  * @brief  Enable timeout interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_tout(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_TOUT);
}

/**
  * @brief  Enable PEC error interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_pece(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_PECE);
}

/**
  * @brief  Enable arbitration loss interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_arlo(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_ARLO);
}

/**
  * @brief  Enable bus error interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_berr(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_BERR);
}

/**
  * @brief  Enable stop detection interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_stop(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_STOP);
}

/**
  * @brief  Enable NACK receiver interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_nack(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_NACK);
}

/**
  * @brief  Enable address matched interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_addr(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_ADDR);
}

/**
  * @brief  Enable transfer complete and reload interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_tcr(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_TCR);
}

/**
  * @brief  Enable transfer complete interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_tc(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_TC);
}


/**
  * @brief  Enable receive buffer underrun interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_rxud(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_RXUD);
}

/**
  * @brief  Enable receive buffer ovrun interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_rxov(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_RXOV);
}

/**
  * @brief  Enable receive buffer not empty interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_rxne(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_RXNE);
}

/**
  * @brief  Enable transmit buffer underrun interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_txud(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_TXUD);
}

/**
  * @brief  Enable transmit buffer ovrun interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_txov(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_TXOV);
}

/**
  * @brief  Enable transmit buffer empty interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_enable_it_txe(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IER, I2C_IER_TXE);
}
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions_Group13 IDR
  * @{
  */
/**
  * @brief  Set I2C IDR
  * @note   None
  * @param  I2Cx I2C Instance
  * @param  idr
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_idr(I2C_TypeDef *I2Cx, uint32_t idr)
{
    WRITE_REG(I2Cx->IDR, idr);
}

/**
  * @brief  Disable SMBus alert interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_alert(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_ALERT);
}

/**
  * @brief  Disable timeout interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_tout(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_TOUT);
}

/**
  * @brief  Disable PEC error interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_pece(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_PECE);
}

/**
  * @brief  Disable arbitration loss interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_arlo(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_ARLO);
}

/**
  * @brief  Disable bus error interrupt.
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_berr(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_BERR);
}

/**
  * @brief  Disable stop detection interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_stop(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_STOP);
}

/**
  * @brief  Disable NACK receiver interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_nack(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_NACK);
}

/**
  * @brief  Disable address matched interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_addr(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_ADDR);
}

/**
  * @brief  Disable transfer complete and reload interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_tcr(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_TCR);
}

/**
  * @brief  Disable transfer complete interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_tc(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_TC);
}

/**
  * @brief  Disable receive buffer underrun interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_rxud(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_RXUD);
}

/**
  * @brief  Disable receive buffer ovrun interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_rxov(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_RXOV);
}

/**
  * @brief  Disable receive buffer not empty interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_rxne(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_RXNE);
}

/**
  * @brief  Disable transmit buffer underrun interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_txud(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_TXUD);
}

/**
  * @brief  Disable transmit buffer ovrun interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_txov(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_TXOV);
}

/**
  * @brief  Disable transmit buffer empty interrupt
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_disable_it_txe(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->IDR, I2C_IDR_TXE);
}
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions_Group14 IVS
  * @{
  */
/**
  * @brief  Get I2C IVS
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_i2c_get_ivs(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_REG(I2Cx->IVS));
}

/**
  * @brief  Check if SMBus alert interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_alert(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_ALERT) == (I2C_IVS_ALERT));
}

/**
  * @brief  Check if timeout interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_tout(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_TOUT) == (I2C_IVS_TOUT));
}

/**
  * @brief  Check if PEC error interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_pece(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_PECE) == (I2C_IVS_PECE));
}

/**
  * @brief  Check if arbitration loss interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_arlo(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_ARLO) == (I2C_IVS_ARLO));
}

/**
  * @brief  Check if bus error interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_berr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_BERR) == (I2C_IVS_BERR));
}

/**
  * @brief  Check if stop detection interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_stop(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_STOP) == (I2C_IVS_STOP));
}

/**
  * @brief  Check if NACK receiver interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_nack(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_NACK) == (I2C_IVS_NACK));
}

/**
  * @brief  Check if address matched interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_addr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_ADDR) == (I2C_IVS_ADDR));
}

/**
  * @brief  Check if transfer complete and reload interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_tcr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_TCR) == (I2C_IVS_TCR));
}

/**
  * @brief  Check if transfer complete interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_tc(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_TC) == (I2C_IVS_TC));
}

/**
  * @brief  Check if receive buffer underrun interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_rxud(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_RXUD) == (I2C_IVS_RXUD));
}

/**
  * @brief  Check if receive buffer ovrun interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_rxov(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_RXOV) == (I2C_IVS_RXOV));
}

/**
  * @brief  Check if receive buffer not empty interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_rxne(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_RXNE) == (I2C_IVS_RXNE));
}

/**
  * @brief  Check if transmit buffer underrun interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_txud(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_TXUD) == (I2C_IVS_TXUD));
}

/**
  * @brief  Check if transmit buffer ovrun interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_txov(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_TXOV) == (I2C_IVS_TXOV));
}

/**
  * @brief  Check if transmit buffer empty interrupt is enabled
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_enabled_it_txe(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IVS, I2C_IVS_TXE) == (I2C_IVS_TXE));
}
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions_Group15 RIF
  * @{
  */
/**
  * @brief  Get I2C RIF
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_i2c_get_rif(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_REG(I2Cx->RIF));
}

/**
  * @brief  Get SMBus alert raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_alert(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_ALERT) == (I2C_RIF_ALERT));
}

/**
  * @brief  Get timeout raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_tout(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_TOUT) == (I2C_RIF_TOUT));
}

/**
  * @brief  Get PEC error raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_pece(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_PECE) == (I2C_RIF_PECE));
}

/**
  * @brief  Get arbitration loss raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_arlo(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_ARLO) == (I2C_RIF_ARLO));
}

/**
  * @brief  Get bus error raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_berr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_BERR) == (I2C_RIF_BERR));
}

/**
  * @brief  Get stop detection raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_stop(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_STOP) == (I2C_RIF_STOP));
}

/**
  * @brief  Get NACK receiver raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_nack(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_NACK) == (I2C_RIF_NACK));
}

/**
  * @brief  Get address matched raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_addr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_ADDR) == (I2C_RIF_ADDR));
}

/**
  * @brief  Get transfer complete and reload raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_tcr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_TCR) == (I2C_RIF_TCR));
}

/**
  * @brief  Get transfer complete raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_tc(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_TC) == (I2C_RIF_TC));
}

/**
  * @brief  Get receive buffer underrun raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_rxud(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_RXUD) == (I2C_RIF_RXUD));
}

/**
  * @brief  Get receive buffer ovrun raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_rxov(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_RXOV) == (I2C_RIF_RXOV));
}



/**
  * @brief  Get receive buffer not empty raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_rxne(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_RXNE) == (I2C_RIF_RXNE));
}

/**
  * @brief  Get transmit buffer underrun raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_txud(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_TXUD) == (I2C_RIF_TXUD));
}

/**
  * @brief  Get transmit buffer ovrun raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_txov(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_TXOV) == (I2C_RIF_TXOV));
}

/**
  * @brief  Get transmit buffer empty raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_active_it_txe(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->RIF, I2C_RIF_TXE) == (I2C_RIF_TXE));
}
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions_Group16 IFM
  * @{
  */
/**
  * @brief  Get I2C IFM
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval a 32-bit value
  */
__STATIC_INLINE uint32_t md_i2c_get_ifm(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(READ_REG(I2Cx->IFM));
}

/**
  * @brief  Get SMBus alert interrupt flag massked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_alert(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_ALERT) == (I2C_IFM_ALERT));
}

/**
  * @brief  Get timeout interrupt flag masked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_tout(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_TOUT) == (I2C_IFM_TOUT));
}

/**
  * @brief  Get PEC error interrupt flag masked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_pece(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_PECE) == (I2C_IFM_PECE));
}

/**
  * @brief  Get arbitration loss interrupt flag masked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_arlo(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_ARLO) == (I2C_IFM_ARLO));
}

/**
  * @brief  Get bus error interrupt flag masked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_berr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_BERR) == (I2C_IFM_BERR));
}

/**
  * @brief  Get stop detection interrupt flag masked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_stop(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_STOP) == (I2C_IFM_STOP));
}

/**
  * @brief  Get NACK receiver interrupt flag masked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_nack(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_NACK) == (I2C_IFM_NACK));
}

/**
  * @brief  Get address matched interrupt flag masked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_addr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_ADDR) == (I2C_IFM_ADDR));
}

/**
  * @brief  Get transfer complete and reload interrupt flag masked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_tcr(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_TCR) == (I2C_IFM_TCR));
}

/**
  * @brief  Get transfer complete interrupt flag masked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_tc(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_TC) == (I2C_IFM_TC));
}

/**
  * @brief  Get receive buffer underrun interrupt flag masked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_rxud(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_RXUD) == (I2C_IFM_RXUD));
}

/**
  * @brief  Get receive buffer ovrun interrupt flag masked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_rxov(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_RXOV) == (I2C_IFM_RXOV));
}

/**
  * @brief  Get receive buffer not empty interrupt flag masked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_rxne(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_RXNE) == (I2C_IFM_RXNE));
}

/**
  * @brief  Get transmit buffer underrun interrupt flag masked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_txud(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_TXUD) == (I2C_IFM_TXUD));
}

/**
  * @brief  Get transmit buffer ovrun interrupt flag masked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_txov(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_TXOV) == (I2C_IFM_TXOV));
}

/**
  * @brief  Get transmit buffer empty interrupt flag masked status
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_i2c_is_masked_it_txe(I2C_TypeDef *I2Cx)
{
    return (READ_BIT(I2Cx->IFM, I2C_IFM_TXE) == (I2C_IFM_TXE));
}
/**
  * @}
  */

/** @defgroup MD_I2C_Public_Functions_Group17 ICR
  * @{
  */
/**
  * @brief  Set I2C ICR
  * @note   None
  * @param  I2Cx I2C Instance
  * @param  icr
  * @retval None
  */
__STATIC_INLINE void md_i2c_set_icr(I2C_TypeDef *I2Cx, uint32_t icr)
{
    WRITE_REG(I2Cx->ICR, icr);
}

/**
  * @brief  Clear SMBus alert raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_alert(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_ALERT);
}

/**
  * @brief  Clear timeout raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_tout(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_TOUT);
}

/**
  * @brief  Clear PEC error raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_pece(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_PECE);
}

/**
  * @brief  Clear arbitration loss raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_arlo(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_ARLO);
}

/**
  * @brief  Clear bus error raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_berr(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_BERR);
}

/**
  * @brief  Clear stop detection raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_stop(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_STOP);
}

/**
  * @brief  Clear NACK receiver raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_nack(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_NACK);
}

/**
  * @brief  Clear address matched raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_addr(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_ADDR);
}

/**
  * @brief  Clear transfer complete and reload raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_tcr(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_TCR);
}

/**
  * @brief  Clear transfer complete raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_tc(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_TC);
}

/**
  * @brief  Clear receive buffer underrun raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_rxud(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_RXUD);
}

/**
  * @brief  Clear receive buffer ovrun raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_rxov(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_RXOV);
}

/**
  * @brief  Clear receive buffer not empty raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_rxne(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_RXNE);
}

/**
  * @brief  Clear transmit buffer underrun raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_txud(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_TXUD);
}

/**
  * @brief  Clear transmit buffer ovrun raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_txov(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_TXOV);
}

/**
  * @brief  Clear transmit buffer empty raw interrupt flag
  * @note   None
  * @param  I2Cx I2C Instance
  * @retval None
  */
__STATIC_INLINE void md_i2c_clear_it_txe(I2C_TypeDef *I2Cx)
{
    SET_BIT(I2Cx->ICR, I2C_ICR_TXE);
}
/**
  * @}
  */

/**
  * @brief  Handles I2Cx communication when starting transfer or during transfer (TC or TCR flag are set).
  * @param  I2Cx I2C Instance.
  * @param  slave_address Specifies the slave address to be programmed.
  * @param  address_size This parameter can be one of the following values:
  *         @arg @ref MD_I2C_ADDRESS_SIZE_7BIT
  *         @arg @ref MD_I2C_ADDRESS_SIZE_10BIT
  * @param  transfer_size Specifies the number of bytes to be programmed.
  *                       This parameter must be a value between Min_Data=0 and Max_Data=65535.
  * @param  mode This parameter can be one of the following values:
  *         @arg @ref MD_I2C_MODE_RELOAD
  *         @arg @ref MD_I2C_MODE_AUTOEND
  *         @arg @ref MD_I2C_MODE_SOFTEND
  *         @arg @ref MD_I2C_MODE_SMBUS_RELOAD
  *         @arg @ref MD_I2C_MODE_SMBUS_AUTOEND_NO_PEC
  *         @arg @ref MD_I2C_MODE_SMBUS_SOFTEND_NO_PEC
  *         @arg @ref MD_I2C_MODE_SMBUS_AUTOEND_WITH_PEC
  *         @arg @ref MD_I2C_MODE_SMBUS_SOFTEND_WITH_PEC
  * @param  request This parameter can be one of the following values:
  *         @arg @ref MD_I2C_REQUEST_NOSTARTSTOP
  *         @arg @ref MD_I2C_REQUEST_STOP
  *         @arg @ref MD_I2C_REQUEST_START_READ
  *         @arg @ref MD_I2C_REQUEST_START_WRITE
  *         @arg @ref MD_I2C_REQUEST_RESTART_7BIT_READ
  *         @arg @ref MD_I2C_REQUEST_RESTART_7BIT_WRITE
  *         @arg @ref MD_I2C_REQUEST_RESTART_10BIT_READ
  *         @arg @ref MD_I2C_REQUEST_RESTART_10BIT_WRITE
  * @retval None
  */
__STATIC_INLINE void md_i2c_handler_transfer(I2C_TypeDef *I2Cx, uint32_t slave_address, uint32_t address_size, uint32_t transfer_size, uint32_t mode, uint32_t request)
{
    if (request & I2C_CON2_RD_WRN)
    {
        MODIFY_REG(I2Cx->CON2,
                   I2C_CON2_PECBYTE | I2C_CON2_AUTOEND | I2C_CON2_RELOAD | I2C_CON2_NBYTES | I2C_CON2_NACK | I2C_CON2_STOP | I2C_CON2_START | I2C_CON2_HEAD10R | I2C_CON2_ADD10 | I2C_CON2_RD_WRN | I2C_CON2_SADD,
                   mode | (transfer_size & 0xFF) << I2C_CON2_NBYTES_POSS | request | slave_address | address_size << I2C_CON2_ADD10_POS);
    }
    else
    {
        MODIFY_REG(I2Cx->CON1,
                   I2C_CON1_NBYTES,
                   ((transfer_size & 0xFF00) >> 2) << I2C_CON1_NBYTES_POSS);
        MODIFY_REG(I2Cx->CON2,
                   I2C_CON2_PECBYTE | I2C_CON2_AUTOEND | I2C_CON2_RELOAD | I2C_CON2_NBYTES | I2C_CON2_NACK | I2C_CON2_STOP | I2C_CON2_START | I2C_CON2_HEAD10R | I2C_CON2_ADD10 | I2C_CON2_RD_WRN | I2C_CON2_SADD,
                   mode | (transfer_size & 0xFF) << I2C_CON2_NBYTES_POSS | request | slave_address | address_size << I2C_CON2_ADD10_POS);
    }
}

/** @defgroup MD_I2C_Public_Functions_Group1 Initialization
  * @{
  */
//ErrorStatus md_i2c_deinit(I2C_TypeDef *I2Cx);
ErrorStatus md_i2c_init(I2C_TypeDef *I2Cx, md_i2c_inittypedef *I2C_InitStruct);
void        md_i2c_struct_init(md_i2c_inittypedef *I2C_InitStruct);
void        md_i2c_master_send(I2C_TypeDef *I2Cx, uint32_t Nbyte, uint32_t addr10, uint16_t DevAddr, uint8_t *txbuf);
void        md_i2c_master_receive(I2C_TypeDef *I2Cx, uint32_t Nbyte, uint32_t addr10, uint16_t DevAddr, uint8_t *rxbuf);
void        md_i2c_slave_send(I2C_TypeDef *I2Cx, uint32_t Num, uint8_t *txbuf);
void        md_i2c_slave_receive(I2C_TypeDef *I2Cx, uint32_t Num, uint8_t *rxbuf);
void        md_i2c_master_setting(I2C_TypeDef *I2Cx, uint32_t Nbyte, uint32_t addr10, uint16_t DevAddr, uint8_t WriteRead);
void md_i2c_clear_txbuff(I2C_TypeDef *I2Cx);
/**
  * @}
  */

/**
  * @}
  */


/** @defgroup MD_I2C_Private_Macro I2C Private Macros
  * @{
  */
#define IS_MD_I2C_ALL_INSTANCE(__INSTANCE__) ((__INSTANCE__ == I2C1)  \
        || (__INSTANCE__ == I2C2))

#define IS_MD_I2C_TIMING(__VALUE__) ((__VALUE__ == CLK10kHz8M)          \
                                     || (__VALUE__ == CLK100kHz8M)      \
                                     || (__VALUE__ == CLK400kHz8M)      \
                                     || (__VALUE__ == CLK500kHz8M)      \
                                     || (__VALUE__ == CLK10kHz16M)      \
                                     || (__VALUE__ == CLK100kHz16M)     \
                                     || (__VALUE__ == CLK400kHz16M)     \
                                     || (__VALUE__ == CLK1000kHz16M)    \
                                     || (__VALUE__ == CLK10kHz48M)      \
                                     || (__VALUE__ == CLK100kHz48M)     \
                                     || (__VALUE__ == CLK400kHz48M)     \
                                     || (__VALUE__ == CLK1000kHz48M))

#define IS_MD_I2C_ADDRSIZE(__VALUE__) ((__VALUE__ == MD_I2C_ADDRESSINGMODE_7BIT)  \
                                       || (__VALUE__ == MD_I2C_ADDRESSINGMODE_10BIT))

#define IS_MD_I2C_ADDRESS1(__VALUE__) (__VALUE__ <= 0x000003FFU)
#define IS_MD_I2C_ADDRESS2(__VALUE__) (__VALUE__ <= (uint16_t)0x00FFU)

#define IS_MD_I2C_DUALADDRESSMODE(__VALUE__)   ((__VALUE__ == MD_I2C_OA2_DISABLE)  \
        || (__VALUE__ == MD_I2C_OA2_ENABLE))
#define IS_MD_I2C_ADDRESS2MASKS(__VALUE__)  ((__VALUE__ == MD_I2C_ADDR2_NOMASK)  \
        || (__VALUE__ == MD_I2C_ADDR2_MASK01)  \
        || (__VALUE__ == MD_I2C_ADDR2_MASK02)  \
        || (__VALUE__ == MD_I2C_ADDR2_MASK03)  \
        || (__VALUE__ == MD_I2C_ADDR2_MASK04)  \
        || (__VALUE__ == MD_I2C_ADDR2_MASK05)  \
        || (__VALUE__ == MD_I2C_ADDR2_MASK06)  \
        || (__VALUE__ == MD_I2C_ADDR2_MASK07))

/**
  * @}
  */

/**
  * @}
  */

/**
  * @} Micro_Driver
  */


#ifdef __cplusplus
}
#endif
#endif

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
