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
 * @file    USB/sn32_usb.h
 * @brief   SN32 USB registers layout header.
 * @note    This file requires definitions from the SN32 header files
 *
 * @addtogroup USB
 * @{
 */

#ifndef SN32_USB_H
#define SN32_USB_H

#include "usbhw.h"

/**
 * @brief   Number of the available endpoints.
 * @details This value does not include the endpoint 0 which is always present.
 */
#define HAL_MAX_ENDPOINTS                  6
#if (defined(SN32F240B) || defined(SN32F260))
#define USB_ENDPOINTS_NUMBER               4
#define SN32_USB_PMA_SIZE                  256
#elif (defined(SN32F280) || defined(SN32F290))
#define USB_ENDPOINTS_NUMBER               HAL_MAX_ENDPOINTS
#define SN32_USB_PMA_SIZE                  512
#else
#error "USB driver not supported in the selected device"
#endif

/**
 * @brief   USB registers block.
 */
  typedef struct {
  volatile uint32_t INTEN;                       /*!< (@ 0x00000000) Offset:0x00 USB Interrupt Enable Register                  */
  volatile uint32_t INSTS;                       /*!< (@ 0x00000004) Offset:0x04 USB Interrupt Event Status Register            */
  volatile uint32_t INSTSC;                      /*!< (@ 0x00000008) Offset:0x08 USB Interrupt Event Status Clear Register      */
  volatile uint32_t ADDR;                        /*!< (@ 0x0000000C) Offset:0x0C USB Device Address Register                    */
  volatile uint32_t CFG;                         /*!< (@ 0x00000010) Offset:0x10 USB Configuration Register                     */
  volatile uint32_t SGCTL;                       /*!< (@ 0x00000014) Offset:0x14 USB Signal Control Register                    */
  volatile uint32_t EPCTL[HAL_MAX_ENDPOINTS +1]; /*!< (@ 0x00000018) Offset:0x18 USB Endpoint 0-6 Control Registers             */
  volatile uint32_t  RESERVED[2];
  volatile uint32_t EPTOGGLE;                    /*!< (@ 0x0000003C) Offset:0x3C USB Endpoint Data Toggle Register              */
  volatile uint32_t  RESERVED1[2];
  volatile uint32_t EPBUFOS[HAL_MAX_ENDPOINTS];  /*!< (@ 0x00000048) Offset:0x48 USB Endpoint 1-6 Buffer Offset Registers       */
  volatile uint32_t FRMNO;                       /*!< (@ 0x00000060) Offset:0x60 USB Frame Number Register                      */
  volatile uint32_t PHYPRM;                      /*!< (@ 0x00000064) Offset:0x64 USB PHY Parameter Register                     */
  volatile uint32_t  RESERVED3;
  volatile uint32_t PHYPRM2;                     /*!< (@ 0x0000006C) Offset:0x6C USB PHY Parameter 2 Register                   */
  volatile uint32_t PS2CTL;                      /*!< (@ 0x00000070) Offset:0x70 PS/2 Control Register                          */
  volatile uint32_t  RESERVED4;
  volatile uint32_t RWADDR;                      /*!< (@ 0x00000078) Offset:0x78 USB Read/Write Address Register                */
  volatile uint32_t RWDATA;                      /*!< (@ 0x0000007C) Offset:0x7C USB Read/Write Data Register                   */
  volatile uint32_t RWSTATUS;                    /*!< (@ 0x00000080) Offset:0x80 USB Read/Write Status Register                 */
  volatile uint32_t RWADDR2;                     /*!< (@ 0x00000084) Offset:0x84 USB Read/Write Address Register 2              */
  volatile uint32_t RWDATA2;                     /*!< (@ 0x00000088) Offset:0x88 USB Read/Write Data Register 2                 */
  volatile uint32_t RWSTATUS2;                   /*!< (@ 0x0000008C) Offset:0x8C USB Read/Write Status Register 2               */
} sn32_usb_t;                                  /*!< Size = 144 (0x90)                                                         */

/** @} */

/**
 * @brief USB registers block numeric address.
 */
#define SN32_USB_BASE          SN_USB_BASE

/**
 * @brief USB RAM numeric address.
 */
#define SN32_USBRAM_BASE       (SN_USB_BASE + 0x100)

/**
 * @brief Pointer to the USB registers block.
 */
#define SN32_USB               ((sn32_usb_t *)SN32_USB_BASE)

/**
 * @brief   Pointer to the USB RAM.
 */
#define SN32_USBRAM            ((sn32_usb_pma_t *)SN32_USBRAM_BASE)
#define mskEPn_NAK(ep)          (0x1<<(ep -1))
#define mskEPn_ACK(ep)          (0x1<<(8+(ep-1)))
#define mskEPn_DIR(ep)          (0x1<<(ep-1))
#define mskEPn_DATA_TOGGLE(ep)      (0x1<<(ep-1))

#define EPCTL_SET_STAT_ACK(ep, bBytecnt)                                  \
  SN32_USB->EPCTL[ep] = (mskEPn_ENDP_EN|mskEPn_ENDP_STATE_ACK|bBytecnt)
#define EPCTL_SET_STAT_NAK(ep)                                            \
  SN32_USB->EPCTL[ep] = (mskEPn_ENDP_EN)
#define EPCTL_SET_STAT_STALL(ep)                                          \
  SN32_USB->EPCTL[ep] = (mskEPn_ENDP_EN|mskEPn_ENDP_STATE_STALL)
#define EPCTL_TOGGLE(ep)                                                  \
  SN32_USB->EPTOGGLE = mskEPn_DATA_TOGGLE(ep)
#define USB_SET_BUFFER_OFST(ep, addr)                                     \
  SN32_USB->EPBUFOS[ep-1] = addr

#endif /* SN32_USB_H */

/** @} */
