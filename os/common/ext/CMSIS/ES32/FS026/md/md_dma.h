/**********************************************************************************
 *
 * @file    md_dma.h
 * @brief   header file of md_dma.c
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov 2021     Ginger          the first version
 *          25 Mar 2022     AE Team         Modify MD Driver
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
#ifndef __MD_DMA_H__
#define __MD_DMA_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include "fs026.h"
#include "reg_dma.h"
/** @addtogroup Micro_Driver
  * @{
  */

#if defined (DMA1)

/** @defgroup DMA DMA
  * @brief DMA micro driver
  * @{
  */

/** @defgroup MD_DMA_Pubulic_Types GPIO Pubulic Types
  * @{
  */

/**
  * @brief MD DMA Init Structure definition
  */
typedef struct
{
    uint32_t type;                            /** DMA channal set type
                                                @ref MD_DMA_PRIMARY
                                                @ref MD_DMA_ALTERNATE
                                            */

    uint32_t channal;                         /** DMA channel macros define
                                                @ref MD_DMA_CHANNEL0
                                                @ref MD_DMA_CHANNEL1
                                                @ref MD_DMA_CHANNEL2
                                                @ref MD_DMA_CHANNEL3
                                                @ref MD_DMA_CHANNEL4
                                                @ref MD_DMA_CHANNEL5
                                            */
    uint32_t cycle_mode;                      /** DMA cycle_mode
                                                @ref MD_DMA_CHANNEL_CFG_MODE_STOP
                                                @ref MD_DMA_CHANNEL_CFG_MODE_BASIC
                                                @ref MD_DMA_CHANNEL_CFG_MODE_AUTO
                                                @ref MD_DMA_CHANNEL_CFG_MODE_PING_PONG
                                                @ref MD_DMA_CHANNEL_CFG_MODE_MEMORY_PRIMARY
                                                @ref MD_DMA_CHANNEL_CFG_MODE_MEMORY_ALTERNATE
                                                @ref MD_DMA_CHANNEL_CFG_MODE_PERIPHERAL_PRIMARY
                                                @ref MD_DMA_CHANNEL_CFG_MODE_PERIPHERAL_ALTERNATE
                                            */
    uint32_t r_power;                         /** DMA r_power
                                                @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_1
                                                @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_2
                                                @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_4
                                                @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_8
                                                @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_16
                                                @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_32
                                                @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_64
                                                @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_128
                                                @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_256
                                                @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_512
                                                @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_1024
                                            */
    uint32_t source_address_size;             /** DMA source_address_size
                                                @ref MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_BYTE
                                                @ref MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_HALF_WORD
                                                @ref MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_WORD
                                            */
    uint32_t source_address_incremental;      /** DMA source_address_incremental
                                                @ref MD_DMA_CHANNEL_CFG_SRCINC_BYTE
                                                @ref MD_DMA_CHANNEL_CFG_SRCINC_HALF_WORD
                                                @ref MD_DMA_CHANNEL_CFG_SRCINC_WORD
                                                @ref MD_DMA_CHANNEL_CFG_SRCINC_NO_INC
                                            */
    uint32_t destination_address_size;        /** DMA source_address_size
                                                @ref MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_BYTE
                                                @ref MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_HALF_WORD
                                                @ref MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_WORD
                                            */
    uint32_t destination_address_incremental; /** DMA source_address_incremental
                                                @ref MD_DMA_CHANNEL_CFG_DSTINC_BYTE
                                                @ref MD_DMA_CHANNEL_CFG_DSTINC_HALF_WORD
                                                @ref MD_DMA_CHANNEL_CFG_DSTINC_WORD
                                                @ref MD_DMA_CHANNEL_CFG_DSTINC_NO_INC
                                            */
    uint32_t transfer_number;                 /** DMA transfer_number
                                                @Note counting from 1.For example, if I want to send 5 pieces of information, just fill in 5.
                                            */
    uint32_t source_data_end_address;         /** DMA source_data_end_address
                                                @ref  md_dma_set_channel_data_start_address_and_length
                                            */
    uint32_t destination_data_end_address;    /** DMA destination_data_end_address
                                                @ref  md_dma_set_channel_data_start_address_and_length
                                            */
    bool disable_auto_software_enable_channel;/** disable software enable channel in DMA_init()*/
} md_dma_init_typedef;

typedef union
{
    struct
    {
        uint32_t cycle_mode:                                  3;
        uint32_t next_useburst:                               1;
        uint32_t transfer_number:                             10;
        uint32_t r_power :                                    4;
        uint32_t reserved0:                                   3;
        uint32_t reserved1:                                   3;
        uint32_t source_address_size:                         2;
        uint32_t source_address_incremental:                  2;
        uint32_t destination_address_size:                    2;
        uint32_t destination_address_incremental:             2;
    } md_dma_config_typedef;
    uint32_t word;
} md_dma_control_typedef;

typedef struct
{
    uint32_t source_data_end_address;               //0x00      Pointer to the end address of the source data
    uint32_t destination_data_end_address;          //0x04      Pointer to the end address of the destination data
    md_dma_control_typedef control;                 //0x08      Control data configuration
    uint32_t reserved;                              //0x0C      RESERVED
} md_dma_channel_config_typedef;
/**
  * @}
  */

/* Private types --------------------------------------------------------------*/
/* Private variables ----------------------------------------------------------*/
/* Private constants ----------------------------------------------------------*/
/* Private macros -------------------------------------------------------------*/

/* Public types ---------------------------------------------------------------*/
/* Public constants -----------------------------------------------------------*/
/** @defgroup MD_DMA_Public_Constants DMA Public Constants
  * @{
  */

/* DMA SELCON Index */
#define MD_DMA_SELCON_INDEX(DMAx, CH)               (*((uint32_t *)&DMAx->CH0_SELCON + CH))

/* DMA PRI_SRC_DATA_END_PTR Index */
#define MD_DMA_PRI_SRC_DATA_END_INDEX(DMAx, CH)     (*((uint32_t *)&DMAx->PRI_CH00_SRC_DATA_END_PTR + (CH * 4)))

/* DMA PRI_DST_DATA_END_PTR Index */
#define MD_DMA_PRI_DST_DATA_END_INDEX(DMAx, CH)     (*((uint32_t *)&DMAx->PRI_CH00_DST_DATA_END_PTR + (CH * 4)))

/* DMA PRI_CHANNEL_CFG Index */
#define MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, CH)      (*((uint32_t *)&DMAx->PRI_CH00_CHANNEL_CFG + (CH * 4)))

/* DMA ALT_SRC_DATA_END_PTR Index */
#define MD_DMA_ALT_SRC_DATA_END_INDEX(DMAx, CH)     (*((uint32_t *)&DMAx->ALT_CH00_SRC_DATA_END_PTR + (CH * 4)))

/* DMA ALT_DST_DATA_END_PTR Index */
#define MD_DMA_ALT_DST_DATA_END_INDEX(DMAx, CH)     (*((uint32_t *)&DMAx->ALT_CH00_DST_DATA_END_PTR + (CH * 4)))

/* DMA ALT_CHANNEL_CFG Index */
#define MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, CH)      (*((uint32_t *)&DMAx->ALT_CH00_CHANNEL_CFG + (CH * 4)))


/* DMA channel macros define */
#define MD_DMA_CHANNEL0            0
#define MD_DMA_CHANNEL1            1
#define MD_DMA_CHANNEL2            2
#define MD_DMA_CHANNEL3            3
#define MD_DMA_CHANNEL4            4
#define MD_DMA_CHANNEL5            5

/* DMA channel set macros define */
//#define MD_DMA_CHANNEL0_SET        (1 << 0)
//#define MD_DMA_CHANNEL1_SET        (1 << 1)
//#define MD_DMA_CHANNEL2_SET        (1 << 2)
//#define MD_DMA_CHANNEL3_SET        (1 << 3)
//#define MD_DMA_CHANNEL4_SET        (1 << 4)
//#define MD_DMA_CHANNEL5_SET        (1 << 5)

/* DMA peripheral request select macros define */
#define MD_DMA_PRS_UART1_TX        0
#define MD_DMA_PRS_UART2_TX        1
#define MD_DMA_PRS_UART3_TX        2
#define MD_DMA_PRS_UART4_TX        3
#define MD_DMA_PRS_SPI1_TX         5
#define MD_DMA_PRS_I2S1_TX         5
#define MD_DMA_PRS_SPI2_TX         6
#define MD_DMA_PRS_I2C1_TX         7
#define MD_DMA_PRS_I2C2_TX         8
#define MD_DMA_PRS_AES_IN          9
#define MD_DMA_PRS_CRC             11
#define MD_DMA_PRS_SPI3_TX         12
#define MD_DMA_PRS_UART1_RX        15
#define MD_DMA_PRS_UART2_RX        16
#define MD_DMA_PRS_UART3_RX        17
#define MD_DMA_PRS_UART4_RX        18
#define MD_DMA_PRS_SPI1_RX         20
#define MD_DMA_PRS_I2S1_RX         20
#define MD_DMA_PRS_SPI2_RX         21
#define MD_DMA_PRS_I2C1_RX         22
#define MD_DMA_PRS_I2C2_RX         23
#define MD_DMA_PRS_AES_OUT         24
#define MD_DMA_PRS_ADC             25
#define MD_DMA_PRS_SPI3_RX         29
#define MD_DMA_PRS_KBCU            31
#define MD_DMA_PRS_BS16T1_UP       32
#define MD_DMA_PRS_AD16C4T1_CH1    33
#define MD_DMA_PRS_AD16C4T1_CH2    34
#define MD_DMA_PRS_AD16C4T1_CH3    35
#define MD_DMA_PRS_AD16C4T1_CH4    36
#define MD_DMA_PRS_AD16C4T1_UP     37
#define MD_DMA_PRS_AD16C4T1_TRIG   38
#define MD_DMA_PRS_AD16C4T1_COM    39
#define MD_DMA_PRS_GP32C4T1_CH1    40
#define MD_DMA_PRS_GP32C4T1_CH2    41
#define MD_DMA_PRS_GP32C4T1_CH3    42
#define MD_DMA_PRS_GP32C4T1_CH4    43
#define MD_DMA_PRS_GP32C4T1_UP     44
#define MD_DMA_PRS_GP32C4T1_TRIG   45
#define MD_DMA_PRS_GP16C4T1_CH1    46
#define MD_DMA_PRS_GP16C4T1_CH2    47
#define MD_DMA_PRS_GP16C4T1_CH3    48
#define MD_DMA_PRS_GP16C4T1_CH4    49
#define MD_DMA_PRS_GP16C4T1_UP     50
#define MD_DMA_PRS_GP16C4T1_TRIG   51
#define MD_DMA_PRS_GP16C4T2_CH1    52
#define MD_DMA_PRS_GP16C4T2_CH2    53
#define MD_DMA_PRS_GP16C4T2_CH3    54
#define MD_DMA_PRS_GP16C4T2_CH4    55
#define MD_DMA_PRS_GP16C4T2_UP     56
#define MD_DMA_PRS_GP16C4T2_TRIG   57
#define MD_DMA_PRS_GP16C4T3_CH1    58
#define MD_DMA_PRS_GP16C4T3_CH2    59
#define MD_DMA_PRS_GP16C4T3_CH3    60
#define MD_DMA_PRS_GP16C4T3_CH4    61
#define MD_DMA_PRS_GP16C4T3_UP     62
#define MD_DMA_PRS_GP16C4T3_TRIG   63
#define MD_DMA_PRS_GP16C2T1_CH1    64
#define MD_DMA_PRS_GP16C2T1_CH2    65
#define MD_DMA_PRS_GP16C2T1_UP     66
#define MD_DMA_PRS_GP16C2T1_TRIG   67
#define MD_DMA_PRS_GP16C2T1_COM    68
#define MD_DMA_PRS_GP16C2T2_CH1    70
#define MD_DMA_PRS_GP16C2T2_CH2    71
#define MD_DMA_PRS_GP16C2T2_UP     72
#define MD_DMA_PRS_GP16C2T2_TRIG   73
#define MD_DMA_PRS_GP16C2T2_COM    74
#define MD_DMA_PRS_GP16C2T3_CH1    76
#define MD_DMA_PRS_GP16C2T3_CH2    77
#define MD_DMA_PRS_GP16C2T3_UP     78
#define MD_DMA_PRS_GP16C2T3_TRIG   79
#define MD_DMA_PRS_GP16C2T3_COM    80
#define MD_DMA_PRS_GP16C2T4_CH1    82
#define MD_DMA_PRS_GP16C2T4_CH2    83
#define MD_DMA_PRS_GP16C2T4_UP     84
#define MD_DMA_PRS_GP16C2T4_TRIG   85
#define MD_DMA_PRS_GP16C2T4_COM    86
#define MD_DMA_PRS_MEMORY          127

/* DMA destination address increment size*/
#define MD_DMA_CHANNEL_CFG_DSTINC_BYTE                  (0U)
#define MD_DMA_CHANNEL_CFG_DSTINC_HALF_WORD             (1U)
#define MD_DMA_CHANNEL_CFG_DSTINC_WORD                  (2U)
#define MD_DMA_CHANNEL_CFG_DSTINC_NO_INC                (3U)

/* DMA destination data size */
#define MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_BYTE            (0 )
#define MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_HALF_WORD       (1 )
#define MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_WORD            (2 )

/* DMA source address increment size*/
#define MD_DMA_CHANNEL_CFG_SRCINC_BYTE                  (0 )
#define MD_DMA_CHANNEL_CFG_SRCINC_HALF_WORD             (1 )
#define MD_DMA_CHANNEL_CFG_SRCINC_WORD                  (2 )
#define MD_DMA_CHANNEL_CFG_SRCINC_NO_INC                (3 )

/* DMA source data size */
#define MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_BYTE            (0 )
#define MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_HALF_WORD       (1 )
#define MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_WORD            (2 )

/* Number of times the DMA transfer every arbitration */
#define MD_DMA_CHANNEL_CFG_RPOWER_SIZE_1                (0 )
#define MD_DMA_CHANNEL_CFG_RPOWER_SIZE_2                (1 )
#define MD_DMA_CHANNEL_CFG_RPOWER_SIZE_4                (2 )
#define MD_DMA_CHANNEL_CFG_RPOWER_SIZE_8                (3 )
#define MD_DMA_CHANNEL_CFG_RPOWER_SIZE_16               (4 )
#define MD_DMA_CHANNEL_CFG_RPOWER_SIZE_32               (5 )
#define MD_DMA_CHANNEL_CFG_RPOWER_SIZE_64               (6 )
#define MD_DMA_CHANNEL_CFG_RPOWER_SIZE_128              (7 )
#define MD_DMA_CHANNEL_CFG_RPOWER_SIZE_256              (8 )
#define MD_DMA_CHANNEL_CFG_RPOWER_SIZE_512              (9 )
#define MD_DMA_CHANNEL_CFG_RPOWER_SIZE_1024             (10)

/* DMA mode */
#define MD_DMA_CHANNEL_CFG_MODE_STOP                    (0 )
#define MD_DMA_CHANNEL_CFG_MODE_BASIC                   (1 )
#define MD_DMA_CHANNEL_CFG_MODE_AUTO                    (2 )
#define MD_DMA_CHANNEL_CFG_MODE_PING_PONG               (3 )
#define MD_DMA_CHANNEL_CFG_MODE_MEMORY_PRIMARY          (4 )
#define MD_DMA_CHANNEL_CFG_MODE_MEMORY_ALTERNATE        (5 )
#define MD_DMA_CHANNEL_CFG_MODE_PERIPHERAL_PRIMARY      (6 )
#define MD_DMA_CHANNEL_CFG_MODE_PERIPHERAL_ALTERNATE    (7 )

/* DMA type */
#define MD_DMA_PRIMARY                                  (0)
#define MD_DMA_ALTERNATE                                (1)

/* DMA size */
#define MD_DMA_CHANNEL_SIZE_BYTE            (0)
#define MD_DMA_CHANNEL_SIZE_HALF_WORD       (1)
#define MD_DMA_CHANNEL_SIZE_WORD            (2)


/**
  * @} MD_DMA_Public_Constants
  */

/* Public macro ---------------------------------------------------------------*/
/** @defgroup MD_DMA_Public_Macros DMA Public Macros
  * @{
  */

/**
  * @brief  GET DMA STATUS register value.
  * @param  DMAx DMA instance
  * @retval DMA STATUS register value.
  */

__STATIC_INLINE uint32_t md_dma_get_status(DMA_TypeDef *DMAx)
{
    return (uint32_t)(READ_REG(DMAx->STATUS));
}

/**
  * @brief  GET DMA number of channel.
  * @param  DMAx DMA instance
  * @retval DMA available channel 0~12.
  */

__STATIC_INLINE uint32_t md_dma_get_available_channel_number(DMA_TypeDef *DMAx)
{
    return (uint32_t)(READ_BIT(DMAx->STATUS, DMA_STATUS_CHNLS_MINUS1) >> DMA_STATUS_CHNLS_MINUS1_POSS);
}

/**
  * @brief  GET DMA status.
  * @param  DMAx DMA instance
  * @retval The current state of the state machine.
  */

__STATIC_INLINE uint32_t md_dma_get_current_status(DMA_TypeDef *DMAx)
{
    return (uint32_t)(READ_BIT(DMAx->STATUS, DMA_STATUS_STATUS) >> DMA_STATUS_STATUS_POSS);
}

/**
  * @brief  Indicates whether the DMAx is enabled.
  * @param  DMAx DMA instance
  * @retval DMA master enable register value; State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_dma_is_enabled(DMA_TypeDef *DMAx)
{
    return (READ_BIT(DMAx->STATUS, DMA_STATUS_MASTER_ENABLE) == (DMA_STATUS_MASTER_ENABLE));
}

/**
  * @brief  DMA CFG setup.
  * @param  DMAx DMA instance
  * @param  value DMA configuration
  * @retval None
  */

__STATIC_INLINE void md_dma_set_configuration(DMA_TypeDef *DMAx, uint32_t value)
{
    WRITE_REG(DMAx->CFG, value);
}

/**
  * @brief  DMA channel protect setup.
  * @param  DMAx DMA instance
  * @param  CHProtect Channel protect setup
  * @retval None
  */

__STATIC_INLINE void md_dma_set_channel_hport_control(DMA_TypeDef *DMAx, uint32_t CHProtect)
{
    MODIFY_REG(DMAx->CFG, DMA_CFG_CHNL_PROT_CTRL, (CHProtect << DMA_CFG_CHNL_PROT_CTRL_POSS));
}

/**
  * @brief  DMA enable.
  * @param  DMAx DMA instance
  * @retval None
  */

__STATIC_INLINE void md_dma_enable_master(DMA_TypeDef *DMAx)
{
    SET_BIT(DMAx->CFG, DMA_CFG_MASTER_ENABLE);
}

/**
  * @brief  DMA disable.
  * @param  DMAx DMA instance
  * @retval None
  */

__STATIC_INLINE void md_dma_disable_master(DMA_TypeDef *DMAx)
{
    CLEAR_BIT(DMAx->CFG, DMA_CFG_MASTER_ENABLE);
}

/**
  * @brief  GET DMA channel request status.
  * @param  DMAx DMA instance
  * @retval Wait on request state
  */

__STATIC_INLINE uint32_t md_dma_get_channel_wait_on_request(DMA_TypeDef *DMAx)
{
    return (uint32_t)(READ_BIT(DMAx->CHWAITSTATUS, DMA_CHWAITSTATUS_DMA_WAITONREQ_STATUS));
}

/**
  * @brief  DMA CHSWREQ setup.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_enable_soft_request(DMA_TypeDef *DMAx, uint32_t channel)
{
    WRITE_REG(DMAx->CHSWREQ, (1 << channel));
}

/**
  * @brief  DMA CHUSEBURSTSET setup.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_enable_burst_request(DMA_TypeDef *DMAx, uint32_t channel)
{
    WRITE_REG(DMAx->CHUSEBURSTSET, (1 << channel));
}

/**
  * @brief  GET DMA CHUSEBURSTSET register value.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval DMA CHUSEBURSTSET register value; State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_dma_is_enabled_burst_request(DMA_TypeDef *DMAx, uint32_t channel)
{
    return (READ_BIT(DMAx->CHUSEBURSTSET, (1 << channel)) == (1 << channel));
}

/**
  * @brief  DMA CHUSEBURSTCLR setup.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_disable_burst_request(DMA_TypeDef *DMAx, uint32_t channel)
{
    WRITE_REG(DMAx->CHUSEBURSTCLR, (1 << channel));
}

/**
  * @brief  DMA CHREQMASKSET setup.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_disable_request(DMA_TypeDef *DMAx, uint32_t channel)
{
    WRITE_REG(DMAx->CHREQMASKSET, (1 << channel));
}

/**
  * @brief  GET DMA CHREQMASKSET register value.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval DMA CHREQMASKSET register value; State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_dma_is_enabled_request(DMA_TypeDef *DMAx, uint32_t channel)
{
    return ((READ_BIT(DMAx->CHREQMASKSET, (1 << channel)) != (1 << channel)));
}

/**
  * @brief  DMA CHREQMASKCLR setup.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_enable_request(DMA_TypeDef *DMAx, uint32_t channel)
{
    WRITE_REG(DMAx->CHREQMASKCLR, (1 << channel));
}

/**
  * @brief  DMA CHENSET setup.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_enable_channel(DMA_TypeDef *DMAx, uint32_t channel)
{
    WRITE_REG(DMAx->CHENSET, (1 << channel));
}

/**
  * @brief  GET DMA CHENSET register value.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval DMA CHENSET register value; State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_dma_is_enabled_channel(DMA_TypeDef *DMAx, uint32_t channel)
{
    return (READ_BIT(DMAx->CHENSET, (1 << channel)) == (1 << channel));
}

/**
  * @brief  DMA CHENCLR setup.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_disable_channel(DMA_TypeDef *DMAx, uint32_t channel)
{
    WRITE_REG(DMAx->CHENCLR, (1 << channel));
}

/**
  * @brief  DMA CHPRIALTSET setup.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_enable_alternate_mode(DMA_TypeDef *DMAx, uint32_t channel)
{
    WRITE_REG(DMAx->CHPRIALTSET, (1 << channel));
}

/**
  * @brief  GET DMA CHPRIALTSET register value.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval DMA CHPRIALTSET register value; State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_dma_is_enabled_alternate_mode(DMA_TypeDef *DMAx, uint32_t channel)
{
    return (READ_BIT(DMAx->CHPRIALTSET, (1 << channel)) == (1 << channel));
}

/**
  * @brief  DMA CHPRIALTCLR setup.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_enable_primary_mode(DMA_TypeDef *DMAx, uint32_t channel)
{
    WRITE_REG(DMAx->CHPRIALTCLR, (1 << channel));
}

/**
  * @brief  DMA CHPRSET setup.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_set_channel_priority(DMA_TypeDef *DMAx, uint32_t channel)
{
    WRITE_REG(DMAx->CHPRSET, (1 << channel));
}

/**
  * @brief  GET DMA CHPRSET register value.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval DMA CHPRSET register value. State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_dma_get_channel_priority(DMA_TypeDef *DMAx, uint32_t channel)
{
    return (READ_BIT(DMAx->CHPRSET, (1 << channel)));
}

/**
  * @brief  DMA CHPRCLR setup.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_set_channel_priority_default(DMA_TypeDef *DMAx, uint32_t channel)
{
    WRITE_REG(DMAx->CHPRCLR, (1 << channel));
}

/**
  * @brief  DMA IER setup.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_enable_it_channel_done(DMA_TypeDef *DMAx, uint32_t channel)
{
    SET_BIT(DMAx->IER, (1 << channel));
}

/**
  * @brief  DMA IDR setup.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_disable_it_channel_done(DMA_TypeDef *DMAx, uint32_t channel)
{
    SET_BIT(DMAx->IDR, (1 << channel));
}

/**
  * @brief  GET DMA IVS register value.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval DMA IVS register value. State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_dma_is_enabled_it_channel_done(DMA_TypeDef *DMAx, uint32_t channel)
{
    return (READ_BIT(DMAx->IVS, (1 << channel)) == (1 << channel));
}

/**
  * @brief  GET DMA RIF register value.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval DMA RIF register value. State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_dma_is_active_flag_channel_done(DMA_TypeDef *DMAx, uint32_t channel)
{
    return (READ_BIT(DMAx->RIF, (1 << channel)) == (1 << channel));
}

/**
  * @brief  GET DMA IFM register value.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval DMA IFM register value. State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_dma_is_masked_it_channel_done(DMA_TypeDef *DMAx, uint32_t channel)
{
    return (READ_BIT(DMAx->IFM, (1 << channel)) == (1 << channel));
}

/**
  * @brief  DMA ICR setup.
  * @param  DMAx DMA instance
  * @param  channel The channel can be one of the following values:
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_clear_it_channel_done(DMA_TypeDef *DMAx, uint32_t channel)
{
    SET_BIT(DMAx->ICR, (1 << channel));
}

/**
  * @brief  DMA CH_SELCON setup.
  * @param  DMAx DMA instance
  * @param  value MISGSEL
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_set_request_peripherals(DMA_TypeDef *DMAx, uint32_t ch, uint32_t value)
{
    WRITE_REG(MD_DMA_SELCON_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA CH_SELCON register value.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval DMAx->CH_SELCON[ch].MISGSEL register value.
  */

__STATIC_INLINE uint32_t md_dma_get_request_peripherals(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_REG(MD_DMA_SELCON_INDEX(DMAx, ch)));
}

/**
  * @brief  DMA PRI_CH_CHANNEL_CFG.scr setup.
  * @param  DMAx DMA instance
  * @param  value PRI_CH_CHANNEL_CFG.scr
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_set_primary_channel_source_data_end_address(DMA_TypeDef *DMAx, uint32_t ch, uint32_t value)
{
    while (READ_REG(MD_DMA_PRI_SRC_DATA_END_INDEX(DMAx, ch) != value))
        WRITE_REG(MD_DMA_PRI_SRC_DATA_END_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA DMA PRI_CH_CHANNEL_CFG.scr register value.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval DMA PRI_CH_CHANNEL_CFG.scr register value.
  */

__STATIC_INLINE uint32_t md_dma_get_primary_channel_source_data_end_address(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_REG(MD_DMA_PRI_SRC_DATA_END_INDEX(DMAx, ch)));
}

/**
  * @brief  DMA PRI_CH_CHANNEL_CFG.dst setup.
  * @param  DMAx DMA instance
  * @param  value PRI_CH_CHANNEL_CFG.dst
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_set_primary_channel_destination_data_end_address(DMA_TypeDef *DMAx, uint32_t ch, uint32_t value)
{
    while (READ_REG(MD_DMA_PRI_DST_DATA_END_INDEX(DMAx, ch) != value))
        WRITE_REG(MD_DMA_PRI_DST_DATA_END_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA PRI_CH_CHANNEL_CFG.dst register value.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval DMA PRI_CH_CHANNEL_CFG.dst register value.
  */

__STATIC_INLINE uint32_t md_dma_get_primary_channel_destination_data_end_address(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(MD_DMA_PRI_DST_DATA_END_INDEX(DMAx, ch));
}
/**
  * @brief  DMA PRI_CH_CHANNEL_CFG.cfg.word setup.
  * @param  DMAx DMA instance
  * @param  value PRI_CH_CHANNEL_CFG.cfg.word
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_set_primary_channel_channel_configuration(DMA_TypeDef *DMAx, uint32_t ch, uint32_t value)
{
    while (READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch) != value))
        WRITE_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA PRI_CH_CHANNEL_CFG.cfg.word register value.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval DMA PRI_CH_CHANNEL_CFG.cfg.word register value.
  */

__STATIC_INLINE uint32_t md_dma_get_primary_channel_channel_configuration(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)));
}

/**
  * @brief  DMA channel destination increment size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  DstInc channel destination increment size.
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_BYTE
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_NO_INC
  * @retval None
  */

__STATIC_INLINE void md_dma_set_primary_channel_destination_address_incremental(DMA_TypeDef *DMAx, uint32_t ch, uint32_t DstInc)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch) & ~(CHANNEL_CFG_DST_INC);
    value = CLEAR_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_DST_INC);
    value |= DstInc << CHANNEL_CFG_DST_INC_POSS;

    while (READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA channel destination increment size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval The retval can be one of the following values:
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_BYTE
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_NO_INC
  */

__STATIC_INLINE uint32_t md_dma_get_primary_channel_destination_address_incremental(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_DST_INC)) >> CHANNEL_CFG_DST_INC_POSS;
}

/**
  * @brief  DMA channel destination data size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  DstSize channel destination data size.
            @arg @ref MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_BYTE
            @arg @ref MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_WORD
  * @retval None
  */

__STATIC_INLINE void md_dma_set_primary_channel_destination_address_size(DMA_TypeDef *DMAx, uint32_t ch, uint32_t DstSize)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_DST_SIZE);
    value = CLEAR_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_DST_SIZE);
    value |= DstSize << CHANNEL_CFG_DST_SIZE_POSS;

    while (READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA channel destination data size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval The retval can be one of the following values:
            @arg @ref MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_BYTE
            @arg @ref MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_WORD
  */

__STATIC_INLINE uint32_t md_dma_get_primary_channel_destination_address_size(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_DST_SIZE)) >> CHANNEL_CFG_DST_SIZE_POSS;
}

/**
  * @brief  DMA channel source increment size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  SrcInc channel source increment size.
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_BYTE
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_NO_INC
  * @retval None
  */

__STATIC_INLINE void md_dma_set_primary_channel_source_address_incremental(DMA_TypeDef *DMAx, uint32_t ch, uint32_t SrcInc)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_SRC_INC);
    value = CLEAR_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_SRC_INC);
    value |= SrcInc << CHANNEL_CFG_SRC_INC_POSS;

    while (READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA channel source increment size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval The retval can be one of the following values:
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_BYTE
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_NO_INC
  */

__STATIC_INLINE uint32_t md_dma_get_primary_channel_source_address_incremental(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_SRC_INC)) >> CHANNEL_CFG_SRC_INC_POSS;
}

/**
  * @brief  DMA channel source data size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  SrcSize channel source data size.
            @arg @ref MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_BYTE
            @arg @ref MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_WORD
  * @retval None
  */

__STATIC_INLINE void md_dma_set_primary_channel_source_address_size(DMA_TypeDef *DMAx, uint32_t ch, uint32_t SrcSize)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_SRC_SIZE);
    value = CLEAR_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_SRC_SIZE);
    value |= SrcSize << CHANNEL_CFG_SRC_SIZE_POSS;

    while (READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA channel source data size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval The retval can be one of the following values:
            @arg @ref MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_BYTE
            @arg @ref MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_WORD
  */

__STATIC_INLINE uint32_t md_dma_get_primary_channel_source_address_size(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_SRC_SIZE)) >> CHANNEL_CFG_SRC_SIZE_POSS;
}

/**
  * @brief  Number of times the DMA channel 0 transfer Before the controller re-arbitrates.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  times Number of times the DMA channel transfer Before the controller re-arbitrates.
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_1
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_2
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_4
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_8
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_16
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_32
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_64
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_128
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_256
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_512
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_1024
  * @retval None
  */

__STATIC_INLINE void md_dma_set_primary_channel_r_power(DMA_TypeDef *DMAx, uint32_t ch, uint32_t times)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_R_POWER);
    value = CLEAR_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_R_POWER);
    value |= times << CHANNEL_CFG_R_POWER_POSS;

    while (READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET Number of times the DMA channel transfer Before the controller re-arbitrates.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval The retval can be one of the following values:
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_1
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_2
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_4
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_8
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_16
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_32
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_64
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_128
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_256
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_512
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_1024
  */

__STATIC_INLINE uint32_t md_dma_get_primary_channel_r_power(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_R_POWER)) >> CHANNEL_CFG_R_POWER_POSS;
}

/**
  * @brief  Number of times the DMA channel transfer.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  times Number of times the DMA channel transfer.
  *         @arg Max Value 1023
  *         @arg Min Value 0
  * @retval None
  */

__STATIC_INLINE void md_dma_set_primary_channel_transfer_number(DMA_TypeDef *DMAx, uint32_t ch, uint32_t times)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_N_MINUS_1);
    value = CLEAR_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_N_MINUS_1);
    value |= times << CHANNEL_CFG_N_MINUS_1_POSS;

    while (READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET Number of times the DMA channel transfer.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval Number of times the DMA channel transfer.
  *         @arg Max Value 1023
  *         @arg Min Value 0
  */

__STATIC_INLINE uint32_t md_dma_get_primary_channel_transfer_number(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_N_MINUS_1) >> CHANNEL_CFG_N_MINUS_1_POSS);
}

/**
  * @brief  DMA channel set CHNL_USEBURST_SET[C] enable.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_enable_primary_channel_next_burst_request(DMA_TypeDef *DMAx, uint32_t ch)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_NEXT_USEBURST);
    value = CLEAR_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_NEXT_USEBURST);
    value |= 1 << CHANNEL_CFG_NEXT_USEBURST_POS;

    while (READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  DMA channel set CHNL_USEBURST_SET[C] disable.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_disable_primary_channel_next_burst_request(DMA_TypeDef *DMAx, uint32_t ch)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_NEXT_USEBURST);
    value = CLEAR_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_NEXT_USEBURST);
    value &= ~(1 << CHANNEL_CFG_NEXT_USEBURST_POS);

    while (READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  Indicates whether the DMA channel set CHNL_USEBURST_SET[C] is enabled.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_dma_is_enabled_primary_channel_next_burst_request(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (READ_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_NEXT_USEBURST) == (CHANNEL_CFG_NEXT_USEBURST));
}

/**
  * @brief  DMA channel mode setup.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  mode DMA channel mode.
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_STOP
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_BASIC
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_AUTO
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_PING_PONG
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_MEMORY_PRIMARY
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_MEMORY_ALTERNATE
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_PERIPHERAL_PRIMARY
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_PERIPHERAL_ALTERNATE
  * @retval None
  */

__STATIC_INLINE void md_dma_set_primary_channel_cycle_mode(DMA_TypeDef *DMAx, uint32_t ch, uint32_t mode)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_CYCLE_CTRL);
    value = CLEAR_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_CYCLE_CTRL);
    value |= mode << CHANNEL_CFG_CYCLE_CTRL_POSS;

    while (READ_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA channel mode.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval The retval can be one of the following values:
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_STOP
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_BASIC
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_AUTO
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_PING_PONG
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_MEMORY_PRIMARY
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_MEMORY_ALTERNATE
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_PERIPHERAL_PRIMARY
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_PERIPHERAL_ALTERNATE
  */

__STATIC_INLINE uint32_t md_dma_get_primary_channel_cycle_mode(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_BIT(MD_DMA_PRI_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_CYCLE_CTRL)) >> CHANNEL_CFG_CYCLE_CTRL_POSS;
}


/**
  * @brief  DMA ALT_CH_CHANNEL_CFG.scr setup.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  value ALT_CH_CHANNEL_CFG.scr
  * @retval None
  */

__STATIC_INLINE void md_dma_set_alternate_channel_source_data_end_address(DMA_TypeDef *DMAx, uint32_t ch, uint32_t value)
{
    while (READ_REG(MD_DMA_ALT_SRC_DATA_END_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_ALT_SRC_DATA_END_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA DMA ALT_CH_CHANNEL_CFG.scr register value.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval DMA DMA ALT_CH_CHANNEL_CFG.scr register value.
  */

__STATIC_INLINE uint32_t md_dma_get_alternate_channel_source_data_end_address(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_REG(MD_DMA_ALT_SRC_DATA_END_INDEX(DMAx, ch)));
}

/**
  * @brief  DMA ALT_CH_CHANNEL_CFG.dst setup.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  value ALT_CH_CHANNEL_CFG.dst
  * @retval None
  */

__STATIC_INLINE void md_dma_set_alternate_channel_destination_data_end_address(DMA_TypeDef *DMAx, uint32_t ch, uint32_t value)
{
    while (READ_REG(MD_DMA_ALT_DST_DATA_END_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_ALT_DST_DATA_END_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA ALT_CH_CHANNEL_CFG.dst register value.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval DMA ALT_CH_CHANNEL_CFG.dst register value.
  */

__STATIC_INLINE uint32_t md_dma_get_alternate_channel_destination_data_end_address(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_REG(MD_DMA_ALT_DST_DATA_END_INDEX(DMAx, ch)));
}

/**
  * @brief  DMA ALT_CH_CHANNEL_CFG.cfg.word setup.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  value ALT_CH_CHANNEL_CFG.cfg.word
  * @retval None
  */

__STATIC_INLINE void md_dma_set_alternate_channel_channel_configuration(DMA_TypeDef *DMAx, uint32_t ch, uint32_t value)
{
    while (READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA ALT_CH_CHANNEL_CFG.cfg.word register value.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval DMA ALT_CH_CHANNEL_CFG.cfg.word register value.
  */

__STATIC_INLINE uint32_t md_dma_get_alternate_channel_channel_configuration(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)));
}

/**
  * @brief  DMA channel destination increment size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  DstInc channel destination increment size.
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_BYTE
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_NO_INC
  * @retval None
  */

__STATIC_INLINE void md_dma_set_alternate_channel_destination_address_incremental(DMA_TypeDef *DMAx, uint32_t ch, uint32_t DstInc)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_DST_INC);
    value = CLEAR_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_DST_INC);
    value |= DstInc << CHANNEL_CFG_DST_INC_POSS;

    while (READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA channel destination increment size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval The retval can be one of the following values:
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_BYTE
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_DSTINC_NO_INC
  */

__STATIC_INLINE uint32_t md_dma_get_alternate_channel_destination_address_incremental(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_DST_INC)) >> CHANNEL_CFG_DST_INC_POSS;
}

/**
  * @brief  DMA channel destination data size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  DstSize channel destination data size.
            @arg @ref MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_BYTE
            @arg @ref MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_WORD
  * @retval None
  */

__STATIC_INLINE void md_dma_set_alternate_channel_destination_address_size(DMA_TypeDef *DMAx, uint32_t ch, uint32_t DstSize)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_DST_SIZE);
    value = CLEAR_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_DST_SIZE);
    value |= DstSize << CHANNEL_CFG_DST_SIZE_POSS;

    while (READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA channel destination data size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval The retval can be one of the following values:
            @arg @ref MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_BYTE
            @arg @ref MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_DSTDATA_SIZE_WORD
  */

__STATIC_INLINE uint32_t md_dma_get_alternate_channel_destination_address_size(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_DST_SIZE)) >> CHANNEL_CFG_DST_SIZE_POSS;
}

/**
  * @brief  DMA channel source increment size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  SrcInc channel source increment size.
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_BYTE
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_NO_INC
  * @retval None
  */

__STATIC_INLINE void md_dma_set_alternate_channel_source_address_incremental(DMA_TypeDef *DMAx, uint32_t ch, uint32_t SrcInc)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_SRC_INC);
    value = CLEAR_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_SRC_INC);
    value |= SrcInc << CHANNEL_CFG_SRC_INC_POSS;

    while (READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA channel source increment size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval The retval can be one of the following values:
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_BYTE
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_SRCINC_NO_INC
  */

__STATIC_INLINE uint32_t md_dma_get_alternate_channel_source_address_incremental(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_SRC_INC)) >> CHANNEL_CFG_SRC_INC_POSS;
}

/**
  * @brief  DMA channel source data size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  SrcSize channel source data size.
            @arg @ref MD_DMA_CHANNEL_SRCDATA_SIZE_BYTE
            @arg @ref MD_DMA_CHANNEL_SRCDATA_SIZE_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_SRCDATA_SIZE_WORD
  * @retval None
  */

__STATIC_INLINE void md_dma_set_alternate_channel_source_address_size(DMA_TypeDef *DMAx, uint32_t ch, uint32_t SrcSize)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_SRC_SIZE);
    value = CLEAR_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_SRC_SIZE);
    value |= SrcSize << CHANNEL_CFG_SRC_SIZE_POSS;

    while (READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA channel source data size.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval The retval can be one of the following values:
            @arg @ref MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_BYTE
            @arg @ref MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_HALF_WORD
            @arg @ref MD_DMA_CHANNEL_CFG_SRCDATA_SIZE_WORD
  */

__STATIC_INLINE uint32_t md_dma_get_alternate_channel_source_address_size(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_SRC_SIZE)) >> CHANNEL_CFG_SRC_SIZE_POSS;
}

/**
  * @brief  Number of times the DMA channel 0 transfer Before the controller re-arbitrates.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  times Number of times the DMA channel transfer Before the controller re-arbitrates.
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_1
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_2
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_4
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_8
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_16
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_32
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_64
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_128
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_256
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_512
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_1024
  * @retval None
  */

__STATIC_INLINE void md_dma_set_alternate_channel_r_power(DMA_TypeDef *DMAx, uint32_t ch, uint32_t times)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_R_POWER);
    value = CLEAR_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_R_POWER);
    value |= times << CHANNEL_CFG_R_POWER_POSS;

    while (READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET Number of times the DMA channel transfer Before the controller re-arbitrates.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval The retval can be one of the following values:
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_1
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_2
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_4
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_8
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_16
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_32
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_64
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_128
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_256
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_512
            @arg @ref MD_DMA_CHANNEL_CFG_RPOWER_SIZE_1024
  */

__STATIC_INLINE uint32_t md_dma_get_alternate_channel_r_power(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_R_POWER)) >> CHANNEL_CFG_R_POWER_POSS;
}

/**
  * @brief  Number of times the DMA channel transfer.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  Number of times the DMA channel transfer.
  *         @arg Max Value 1023
  *         @arg Min Value 0
  * @retval None
  */

__STATIC_INLINE void md_dma_set_alternate_channel_transfer_number(DMA_TypeDef *DMAx, uint32_t ch, uint32_t times)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_N_MINUS_1);
    value = CLEAR_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_N_MINUS_1);
    value |= times << CHANNEL_CFG_N_MINUS_1_POSS;

    while (READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET Number of times the DMA channel transfer.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval Number of times the DMA channel transfer.
  *         @arg Max Value 1023
  *         @arg Min Value 0
  */

__STATIC_INLINE uint32_t md_dma_get_alternate_channel_transfer_number(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_N_MINUS_1) >> CHANNEL_CFG_N_MINUS_1_POSS);
}

/**
  * @brief  DMA channel set CHNL_USEBURST_SET[C] enable.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_enable_alternate_channel_next_burst_request(DMA_TypeDef *DMAx, uint32_t ch)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_NEXT_USEBURST);
    value = CLEAR_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_NEXT_USEBURST);
    value |= 1 << CHANNEL_CFG_NEXT_USEBURST_POS;

    while (READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  DMA channel set CHNL_USEBURST_SET[C] disable.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval None
  */

__STATIC_INLINE void md_dma_disable_alternate_channel_next_burst_request(DMA_TypeDef *DMAx, uint32_t ch)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_NEXT_USEBURST);
    value = CLEAR_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_NEXT_USEBURST);
    value &= ~(1 << CHANNEL_CFG_NEXT_USEBURST_POS);

    while (READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  Indicates whether the DMA channel set CHNL_USEBURST_SET[C] is enabled.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval State of bit (1 or 0).
  */

__STATIC_INLINE uint32_t md_dma_is_enabled_alternate_channel_next_burst_request(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (READ_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_NEXT_USEBURST) == (CHANNEL_CFG_NEXT_USEBURST));
}

/**
  * @brief  DMA channel mode setup.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @param  mode DMA channel mode.
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_STOP
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_BASIC
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_AUTO
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_PING_PONG
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_MEMORY_ALTMARY
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_MEMORY_ALTERNATE
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_PERIPHERAL_ALTMARY
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_PERIPHERAL_ALTERNATE
  * @retval None
  */

__STATIC_INLINE void md_dma_set_alternate_channel_cycle_mode(DMA_TypeDef *DMAx, uint32_t ch, uint32_t mode)
{
    uint32_t value;
//  value = READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) & ~(CHANNEL_CFG_CYCLE_CTRL);
    value = CLEAR_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_CYCLE_CTRL);
    value |= mode << CHANNEL_CFG_CYCLE_CTRL_POSS;

    while (READ_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch)) != value)
        WRITE_REG(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), value);
}

/**
  * @brief  GET DMA channel mode.
  * @param  DMAx DMA instance
  * @param  ch Channel select
            @arg @ref MD_DMA_CHANNEL0
            @arg @ref MD_DMA_CHANNEL1
            @arg @ref MD_DMA_CHANNEL2
            @arg @ref MD_DMA_CHANNEL3
            @arg @ref MD_DMA_CHANNEL4
            @arg @ref MD_DMA_CHANNEL5
  * @retval The retval can be one of the following values:
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_STOP
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_BASIC
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_AUTO
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_PING_PONG
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_MEMORY_ALTMARY
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_MEMORY_ALTERNATE
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_PERIPHERAL_ALTMARY
            @arg @ref MD_DMA_CHANNEL_CFG_MODE_PERIPHERAL_ALTERNATE
  */

__STATIC_INLINE uint32_t md_dma_get_alternate_channel_cycle_mode(DMA_TypeDef *DMAx, uint32_t ch)
{
    return (uint32_t)(READ_BIT(MD_DMA_ALT_CHANNEL_CFG_INDEX(DMAx, ch), CHANNEL_CFG_CYCLE_CTRL)) >> CHANNEL_CFG_CYCLE_CTRL_POSS;
}


/**
  * @} MD_DMA_Public_Macros
  */

/* Public functions -----------------------------------------------------------*/
/** @defgroup MD_DMA_Public_Functions DMA Public Functions
  * @{
  */

/** @defgroup MD_DMA_Basic_Configuration Basic Configuration
  * @{
  */

/**
  * @} MD_DMA_Basic_Configuration
  */


/**
  * @} MD_DMA_Public_Functions
  */
void md_dma_set_primary_channel_destination_data_start_address_and_length(DMA_TypeDef *DMAx, uint32_t ch, uint32_t addr, uint32_t len, uint32_t size);
void md_dma_set_primary_channel_source_data_start_address_and_length(DMA_TypeDef *DMAx, uint32_t ch, uint32_t addr, uint32_t len, uint32_t size);
uint32_t md_dma_set_channel_data_start_address_and_length(uint32_t addr, uint32_t len, uint32_t size);
void md_dma_init(DMA_TypeDef *DMAx, md_dma_init_typedef DMAx_init);
#endif

/**
  * @} DMA
  */

/**
  * @} Micro_Driver
  */


#ifdef __cplusplus
}
#endif

#endif

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
