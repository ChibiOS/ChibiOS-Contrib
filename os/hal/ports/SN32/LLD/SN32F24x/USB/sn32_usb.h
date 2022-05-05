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
 * @file    USBv1/sn32_usb.h
 * @brief   SN32 USB registers layout header.
 * @note    This file requires definitions from the ST STM32 header files
 *          sn32f124x.h
 *
 * @addtogroup USB
 * @{
 */

#ifndef SN32_USB_H
#define SN32_USB_H

// TODO: ENDPOINTS nubmer is chip dependent and needs to be organized better
/**
 * @brief   Number of the available endpoints.
 * @details This value does not include the endpoint 0 which is always present.
 */
#define USB_MAX_ENDPOINTS		6

/**
 * @brief USB registers block numeric address.
 */
#define SN32_USB_BASE           SN_USB_BASE

/**
 * @brief USB RAM numeric address.
 */
#define SN32_USBRAM_BASE        SN_USB_BASE + 0x100

/**
 * @brief Pointer to the USB registers block.
 */
// #define SN32_USB             ((sn32_usb_t *)SN32_USB_BASE)

/**
 * @brief   Pointer to the USB RAM.
 */
#define SN32_USBRAM             ((sn32_usb_pma_t *)SN32_USBRAM_BASE)

#endif /* SN32_USB_H */

/** @} */