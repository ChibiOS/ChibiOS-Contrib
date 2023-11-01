/*
    W5500 for ChibiOS/RT - Copyright (C) 2023 Xael South

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
 * @file    w5500_lld.h
 * @brief   W5500 Driver macros and structures.
 * @addtogroup WIZNET
 * @{
 */

#ifndef W5500_LLD_H
#define W5500_LLD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief    W5500 chip ID.
 */
#define W5500_CHIP_ID               0x04

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief    Size of ethernet frame without FCS: MTU + VLAN tag = 1500 + 4.
 */
#if !defined(W5500_ETH_MAX_FRAME_SIZE)
#define W5500_ETH_MAX_FRAME_SIZE    1504
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif
#ifdef __cplusplus
}
#endif

#endif /* W5500_LLD_H */

/** @} */
