/**********************************************************************************
 *
 * @file    md_i2c.c
 * @brief   md_i2c C file
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov  2021    Ginger          the first version
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

/* Includes -------------------------------------------------------------------*/
#include "md_i2c.h"
#include "md_rcu.h"
#include <stdio.h>
#include "stdint.h"
/** @addtogroup Micro_Driver
  * @{
  */

/* Private types --------------------------------------------------------------*/
/* Private variables ----------------------------------------------------------*/
/* Private constants ----------------------------------------------------------*/
/* Private macros -------------------------------------------------------------*/

/**
  * @brief  This function is used when I2C uses DMA to import data into TXDATA.
            It is necessary to reset the I2C after first clearing the data in TXDATA after receiving the NACK signal.
  *         Note: When using this function, you need to wait for the stop signal and the stop flag in the RIF will be automatically cleared after use.
  * @param  hperh: Pointer to a ald_i2c_handle_t structure that contains
  *                the configuration information for the specified I2C.
  * @retval Status, see @ref ald_status_t.
  */
void md_i2c_clear_txbuff(I2C_TypeDef *I2Cx)
{
    while (!md_i2c_is_active_it_nack(I2Cx));

    md_i2c_clear_it_nack(I2Cx);

    while (!md_i2c_is_active_it_stop(I2Cx));

    md_i2c_clear_it_stop(I2Cx);
    md_i2c_disable_pe(I2Cx);
}

/**
  * @brief  De-initialize the I2C registers to their default reset values.
  * @param  I2Cx I2C Instance.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: I2C registers are de-initialized
  *          - ERROR: I2C registers are not de-initialized
  */
ErrorStatus md_i2c_deinit(I2C_TypeDef *I2Cx)
{
    ErrorStatus status = SUCCESS;

    if (I2Cx == I2C1)
    {
        /* Enable reset of I2C clock */
        md_rcu_enable_i2c1(RCU);

        /* Disable reset of I2C clock */
        md_rcu_disable_i2c1(RCU);
    }
    else if (I2Cx == I2C2)
    {
        /* Enable reset of I2C clock */
        md_rcu_enable_i2c2_reset(RCU);

        /* Disable reset of I2C clock */
        md_rcu_disable_i2c2_reset(RCU);
    }
    else
    {
        status = ERROR;
    }

    return status;
}


/**
  * @brief  Initialize the I2C registers according to the specified parameters in I2C_InitStruct.
  * @note   The parameters in md_i2c_init should be expected values. Otherwise, ERROR result will be returned.
  * @param  I2Cx I2C Instance
  * @param  I2C_InitStruct pointer to a @ref md_i2c_inittypedef structure
  * @retval An ErrorStatus enumeration value. (Return always SUCCESS)
  */
ErrorStatus md_i2c_init(I2C_TypeDef *I2Cx, md_i2c_inittypedef *I2C_InitStruct)
{
    ErrorStatus status = ERROR;

    /* Check the I2C Instance I2Cx */
    assert_param(IS_MD_I2C_ALL_INSTANCE(I2Cx));

    /* Check the I2C parameters from I2C_InitStruct */
    assert_param(IS_MD_I2C_TIMING(I2C_InitStruct->Timing));
    assert_param(IS_MD_I2C_ADDRSIZE(I2C_InitStruct->AddrSize));
    assert_param(IS_MD_I2C_ADDRESS1(I2C_InitStruct->Address1));
    assert_param(IS_MD_I2C_DUALADDRESSMODE(I2C_InitStruct->DualAddressMode));
    assert_param(IS_MD_I2C_ADDRESS2(I2C_InitStruct->Address2));
    assert_param(IS_MD_I2C_ADDRESS2MASKS(I2C_InitStruct->Address2Masks));
    /* Check the PLL clock, if not corrt, modify it */

    md_i2c_disable_pe(I2Cx);
    md_i2c_set_clock_prescaler(I2Cx, ((I2C_InitStruct->Timing) >> 28) & 0xF);
    md_i2c_set_data_setup_time(I2Cx, ((I2C_InitStruct->Timing) >> 20) & 0xF);
    md_i2c_set_data_hold_time(I2Cx, ((I2C_InitStruct->Timing) >> 16) & 0xF);
    md_i2c_set_clock_high_period(I2Cx, ((I2C_InitStruct->Timing) >> 8) & 0xFF);
    md_i2c_set_clock_low_period(I2Cx, ((I2C_InitStruct->Timing)) & 0xFF);

    md_i2c_enable_pe(I2Cx);

    md_i2c_disable_own1_addr(I2Cx);
    md_i2c_set_own1_addr(I2Cx, I2C_InitStruct->Address1);

    if (I2C_InitStruct->AddrSize == MD_I2C_OA1MODE_10BIT)
    {
        md_i2c_enable_own1_10_bit_addr(I2Cx);
    }
    else if (I2C_InitStruct->AddrSize == MD_I2C_OA1MODE_7BIT)
    {
        md_i2c_enable_own1_7_bit_addr(I2Cx);
    }

    md_i2c_enable_own1_addr(I2Cx);

    if (I2C_InitStruct->DualAddressMode == MD_I2C_OA2_ENABLE)
    {
        md_i2c_disable_own2_addr(I2Cx);
        md_i2c_set_own2_mask_addr(I2Cx, I2C_InitStruct->Address2Masks);
        md_i2c_set_own2_addr(I2Cx, I2C_InitStruct->Address2);
        md_i2c_enable_own2_addr(I2Cx);
    }

    status = SUCCESS;

    return status;
}

/**
  * @brief  Transmits in master mode an amount of data in blocking mode.
  * @param  I2Cx I2C Instance
  * @param  The number of bytes to be transmitted
  * @param  Enable/Disable 10-bit addressing mode
  * @param  Device(slave) address
  * @param  The pointer to a data buffer
  * @retval None
  */
void md_i2c_master_send(I2C_TypeDef *I2Cx, uint32_t Nbyte, uint32_t addr10, uint16_t DevAddr, uint8_t *txbuf)
{
    uint32_t Nbyte_bak = 0;
    md_i2c_master_setting(I2Cx, Nbyte, addr10, DevAddr, MD_I2C_WRITE);

    Nbyte_bak = Nbyte;

    while (Nbyte > 0)
    {
        while (!(md_i2c_is_active_flag_txe(I2Cx)));

        md_i2c_set_tx_reg_data(I2Cx, *txbuf++);

        Nbyte--;

        if (Nbyte_bak - Nbyte >= 65535)
        {
            while (!md_i2c_is_active_flag_tcr(I2Cx));

            md_i2c_clear_it_tcr(I2Cx);
            Nbyte_bak = Nbyte;

            if (Nbyte <= 65535)
            {
                md_i2c_handler_transfer(I2Cx, DevAddr, addr10, Nbyte, MD_I2C_MODE_AUTOEND, MD_I2C_REQUEST_NOSTARTSTOP);
            }
            else
            {
                md_i2c_handler_transfer(I2Cx, DevAddr, addr10, 0xFFFF, MD_I2C_MODE_RELOAD | MD_I2C_MODE_AUTOEND, MD_I2C_REQUEST_NOSTARTSTOP);
            }
        }
    }

}

/**
  * @brief  Transmits/Receive in master mode setting.
  * @param  I2Cx I2C Instance
  * @param  The number of bytes to be transmitted,When the number of receive exceeds 255, the reload function needs to be enabled
  * @param  Enable/Disable 10-bit addressing mode
  * @param  Device(slave) address
  * @param  The pointer to a data buffer
  * @param  Master is write mode or read mode
            @arg @ref MD_I2C_WRITE
            @arg @ref MD_I2C_READ
  * @retval None
  */
void md_i2c_master_setting(I2C_TypeDef *I2Cx, uint32_t Nbyte, uint32_t addr10, uint16_t DevAddr, uint8_t WriteRead)
{
    /* Config Device(slave) address */
    if (addr10 == MD_I2C_ADDRESSINGMODE_7BIT)
    {
        md_i2c_enable_addr_7_bit(I2Cx);
    }
    else if (addr10 == MD_I2C_ADDRESSINGMODE_10BIT)
    {
        md_i2c_enable_addr_10_bit(I2Cx);
    }

    md_i2c_set_slave_addr(I2Cx, DevAddr);

    if (WriteRead == MD_I2C_WRITE)
    {
        if (Nbyte > 65535)
            md_i2c_set_transmit_length(I2Cx, 0xFFFF);
        else
            md_i2c_set_transmit_length(I2Cx, Nbyte);

        md_i2c_enable_master_write(I2Cx);

        if (Nbyte > 65535)
            md_i2c_enable_reload(I2Cx);
        else
            md_i2c_disable_reload(I2Cx);
    }
    else
    {
        if (Nbyte > 255)
            md_i2c_set_transmit_length(I2Cx, 0xFF);
        else
            md_i2c_set_transmit_length(I2Cx, Nbyte);

        md_i2c_enable_master_read(I2Cx);

        if (Nbyte > 255)
            md_i2c_enable_reload(I2Cx);
        else
            md_i2c_disable_reload(I2Cx);
    }

    /* When NBYTES is matched, the communication will be automatically stop */
    md_i2c_enable_auto_end(I2Cx);
    /* Start the I2C communication */
    md_i2c_set_start(I2Cx);
}

/**
  * @brief  Receives in master mode an amount of data in blocking mode.
  * @param  I2Cx I2C Instance
  * @param  The number of bytes to be received,When the number of receive exceeds 255, the reload function needs to be enabled
  * @param  Enable/Disable 10-bit addressing mode
  * @param  Device(slave) address
  * @param  The pointer to a data buffer
  * @retval None
  */
void md_i2c_master_receive(I2C_TypeDef *I2Cx, uint32_t Nbyte, uint32_t addr10, uint16_t DevAddr, uint8_t *rxbuf)
{
    uint32_t Nbyte_bak = Nbyte;
    md_i2c_master_setting(I2Cx, Nbyte, addr10, DevAddr, MD_I2C_READ);

    while (Nbyte > 0)
    {
        /* Wait Rx FIFO non-empty */
        while (!(md_i2c_is_active_flag_rxne(I2Cx)));

        *rxbuf++ = md_i2c_get_rx_reg_data(I2Cx);
        Nbyte--;

        if (Nbyte_bak - Nbyte >= 255)
        {
            while (!md_i2c_is_active_flag_tcr(I2Cx));

            md_i2c_clear_it_tcr(I2Cx);
            Nbyte_bak = Nbyte;

            if (Nbyte <= 255)
            {
                md_i2c_handler_transfer(I2Cx, DevAddr, addr10, Nbyte, MD_I2C_MODE_AUTOEND, MD_I2C_REQUEST_NOSTARTSTOP);
            }
            else
            {
                md_i2c_handler_transfer(I2Cx, DevAddr, addr10, 0xFFFF, MD_I2C_MODE_RELOAD | MD_I2C_MODE_AUTOEND, MD_I2C_REQUEST_NOSTARTSTOP);
            }
        }
    }
}

/**
  * @brief  Transmits in slave mode an amount of data in blocking mode.
  * @param  I2Cx I2C Instance
  * @param  The number of bytes to be transmitted, not for NBYTES
  * @param  The pointer to a data buffer
  * @retval None
  */
void md_i2c_slave_send(I2C_TypeDef *I2Cx, uint32_t Num, uint8_t *txbuf)
{

    while (!(md_i2c_is_active_flag_busy(I2Cx)));

    while (Num > 0)
    {
        while (!(md_i2c_is_active_flag_txe(I2Cx)));

        md_i2c_set_tx_reg_data(I2Cx, *txbuf++);
        Num--;
    }
}

/**
  * @brief  Receives in slave mode an amount of data in blocking mode.
  * @param  I2Cx I2C Instance
  * @param  The number of bytes to be transmitted, not for NBYTES
  * @param  The pointer to a data buffer
  * @retval None
  */
void md_i2c_slave_receive(I2C_TypeDef *I2Cx, uint32_t Num, uint8_t *rxbuf)
{

    while (!(md_i2c_is_active_flag_busy(I2Cx)));

    printf("I2C1->STAT:%x\r\n", I2C1->STAT);

    while (Num > 0)
    {
        while (!(md_i2c_is_active_flag_rxne(I2Cx)));

        *rxbuf++ = md_i2c_get_rx_reg_data(I2Cx);
        Num--;
    }
}

/**
  * @} Micro_Driver
  */
