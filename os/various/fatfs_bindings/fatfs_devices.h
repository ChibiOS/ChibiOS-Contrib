/*
    ChibiOS - Copyright (C) 2006..2017 Giovanni Di Sirio
              Copyright (C) 2015..2017 Diego Ismirlian, (dismirlian (at) google's mail)

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

#ifndef FATFS_DEVICES_H_
#define FATFS_DEVICES_H_

#include "hal.h"

#if HAL_USE_MMC_SPI && HAL_USE_SDC
#error "cannot specify both MMC_SPI and SDC drivers"
#endif

#if HAL_USE_MMC_SPI
extern MMCDriver MMCD1;
#elif HAL_USE_SDC
extern SDCDriver SDCD1;
#elif HAL_USBH_USE_MSD

#else
#error "MMC_SPI, SDC or USBH_MSD driver must be specified"
#endif

/*-----------------------------------------------------------------------*/
/* Correspondence between physical drive number and physical drive.      */
#if HAL_USE_MMC_SPI
#define FATFSDEV_MMC         0
#define FATFSDEV_MMC_DRIVE   "0:"
#endif

#if HAL_USE_SDC
#define FATFSDEV_SDC         0
#define FATFSDEV_SDC_DRIVE   "0:"
#endif

#if HAL_USBH_USE_MSD
#if defined(FATFSDEV_MMC) || defined(FATFSDEV_SDC)
#define FATFSDEV_MSDLUN0         1
#define FATFSDEV_MSDLUN0_DRIVE   "1:"
#else
#define FATFSDEV_MSDLUN0         0
#define FATFSDEV_MSDLUN0_DRIVE   "0:"
#endif
#endif

#endif /* FATFS_DEVICES_H_ */
