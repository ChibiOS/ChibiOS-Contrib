/*
    ChibiOS/RT - Copyright (C) 2014 Uladzimir Pylinsky aka barthess

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
 * @file    hal_community.h
 * @brief   HAL subsystem header (community part).
 *
 * @addtogroup HAL_COMMUNITY
 * @{
 */

#ifndef _HAL_COMMUNITY_H_
#define _HAL_COMMUNITY_H_

/* Abstract interfaces.*/

/* Shared headers.*/

/* Normal drivers.*/
#include "nand.h"
#include "eicu.h"
#include "usbh.h"
#include "timcap.h"

/* Complex drivers.*/
#include "onewire.h"
#include "crc.h"
#include "eeprom.h"

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

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void halCommunityInit(void);
#ifdef __cplusplus
}
#endif

#endif /* _HAL_COMMUNITY_H_ */

/** @} */
