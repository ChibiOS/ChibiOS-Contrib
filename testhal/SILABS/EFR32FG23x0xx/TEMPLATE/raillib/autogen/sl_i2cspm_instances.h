/***************************************************************************//**
 * @file
 * @brief I2C simple poll-based master mode driver instances
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/
 
#ifndef SL_I2CSPM_INSTANCES_H
#define SL_I2CSPM_INSTANCES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sl_i2cspm.h"


#define SL_I2CSPM_SENSOR_PRESENT


extern sl_i2cspm_t *sl_i2cspm_sensor;

void sl_i2cspm_init_instances(void);

#ifdef __cplusplus
}
#endif

#endif // SL_I2CSPM_INSTANCES_H
