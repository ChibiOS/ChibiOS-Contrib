/**********************************************************************************
 *
 * @file    md_usb.h
 * @brief   header file of md_usb.c
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MD_USB_H__
#define __MD_USB_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

#if defined (USB)

/** @defgroup  USB  USB
  * @brief USB micro driver
  * @{
  */

/* Private types --------------------------------------------------------------*/
/* Private variables ----------------------------------------------------------*/
/* Private constants ----------------------------------------------------------*/
/* Private macros -------------------------------------------------------------*/

/* Public types ---------------------------------------------------------------*/
/** @defgroup MD_USB_Public_Types USB Public Types
  * @{
  */

/**
  * @} MD_USB_Public_Types
  */

/* Public constants -----------------------------------------------------------*/
/** @defgroup MD_USB_Public_Constants USB Public Constants
  * @{
  */

#define  MD_USB_DPDMCON_DPPUD_FLOATING          (0x00)   /** @brief DPDMCON DPPUD  */
#define  MD_USB_DPDMCON_DPPUD_PULLUP            (0x01)   /** @brief DPDMCON DPPUD  */
#define  MD_USB_DPDMCON_DPPUD_PULLDOWN          (0x02)   /** @brief DPDMCON DPPUD  */

#define  MD_USB_DPDMCON_DMPUD_FLOATING          (0x00)   /** @brief DPDMCON DMPUD  */
#define  MD_USB_DPDMCON_DMPUD_PULLUP            (0x01)   /** @brief DPDMCON DMPUD  */
#define  MD_USB_DPDMCON_DMPUD_PULLDOWN          (0x02)   /** @brief DPDMCON DMPPUD */

#define  MD_USB_SWCID_HOST_HOST                 (0x00)   /** @brief SWCID HOST     */
#define  MD_USB_SWCID_HOST_DEVICE               (0x01)   /** @brief SWCID HOST     */

#define  MD_USB_SWCID_CIDCTRL_HARDWARE          (0x00)   /** @brief SWCID CIDCTRL  */
#define  MD_USB_SWCID_CIDCTRL_SOFTWARE          (0x01)   /** @brief SWCID CIDCTRL  */

#define  MD_USB_SWVBUS_VALTH_LOWER_VBUS         (0x00)   /** @brief SWVBUS VALTH   */
#define  MD_USB_SWVBUS_VALTH_HIGHER_VBUS        (0x01)   /** @brief SWVBUS VALTH   */

#define  MD_USB_SWVBUS_SESVALTH_LOWER_SESVAL    (0x00)   /** @brief SWVBUS SESVALTH */
#define  MD_USB_SWVBUS_SESVALTH_HIGHER_SESVAL   (0x01)   /** @brief SWVBUS SESVALTH */

#define  MD_USB_SWVBUS_SESENDTH_LOWER_SESEND    (0x00)   /** @brief SWVBUS SESENDTH */
#define  MD_USB_SWVBUS_SESENDTH_HIGHER_SESEND   (0x01)   /** @brief SWVBUS SESENDTH */

#define  MD_USB_SWVBUS_SIGCTRL_HARDWARE         (0x00)   /** @brief SWVBUS SIGCTRL  */
#define  MD_USB_SWVBUS_SIGCTRL_SOFTWARE         (0x01)   /** @brief SWVBUS SIGCTRL  */

#define  MD_USB_TXTYPE_PROTOCOL_CONTROL         (0x00)   /** @brief TYPE PROTOCOL  */
#define  MD_USB_TXTYPE_PROTOCOL_ISOCHRONOUS     (0x01)   /** @brief TYPE PROTOCOL  */
#define  MD_USB_TXTYPE_PROTOCOL_BULK            (0x02)   /** @brief TYPE PROTOCOL  */
#define  MD_USB_TXTYPE_PROTOCOL_INTERRUPT       (0x03)   /** @brief TYPE PROTOCOL  */

#define  MD_USB_RXTYPE_PROTOCOL_CONTROL         (0x00)   /** @brief TYPE PROTOCOL  */
#define  MD_USB_RXTYPE_PROTOCOL_ISOCHRONOUS     (0x01)   /** @brief TYPE PROTOCOL  */
#define  MD_USB_RXTYPE_PROTOCOL_BULK            (0x02)   /** @brief TYPE PROTOCOL  */
#define  MD_USB_RXTYPE_PROTOCOL_INTERRUPT       (0x03)   /** @brief TYPE PROTOCOL  */

#define  MD_USB_TXFIFO2_MAXPKTSIZE_8            (0x00)   /** @brief FIFO MAXPKTSIZE  */
#define  MD_USB_TXFIFO2_MAXPKTSIZE_16           (0x01)   /** @brief FIFO MAXPKTSIZE  */
#define  MD_USB_TXFIFO2_MAXPKTSIZE_32           (0x02)   /** @brief FIFO MAXPKTSIZE  */
#define  MD_USB_TXFIFO2_MAXPKTSIZE_64           (0x03)   /** @brief FIFO MAXPKTSIZE  */
#define  MD_USB_TXFIFO2_MAXPKTSIZE_128          (0x04)   /** @brief FIFO MAXPKTSIZE  */
#define  MD_USB_TXFIFO2_MAXPKTSIZE_256          (0x05)   /** @brief FIFO MAXPKTSIZE  */
#define  MD_USB_TXFIFO2_MAXPKTSIZE_512          (0x06)   /** @brief FIFO MAXPKTSIZE  */
#define  MD_USB_TXFIFO2_MAXPKTSIZE_1024         (0x07)   /** @brief FIFO MAXPKTSIZE  */

#define  MD_USB_RXFIFO2_MAXPKTSIZE_8            (0x00)   /** @brief FIFO MAXPKTSIZE  */
#define  MD_USB_RXFIFO2_MAXPKTSIZE_16           (0x01)   /** @brief FIFO MAXPKTSIZE  */
#define  MD_USB_RXFIFO2_MAXPKTSIZE_32           (0x02)   /** @brief FIFO MAXPKTSIZE  */
#define  MD_USB_RXFIFO2_MAXPKTSIZE_64           (0x03)   /** @brief FIFO MAXPKTSIZE  */
#define  MD_USB_RXFIFO2_MAXPKTSIZE_128          (0x04)   /** @brief FIFO MAXPKTSIZE  */
#define  MD_USB_RXFIFO2_MAXPKTSIZE_256          (0x05)   /** @brief FIFO MAXPKTSIZE  */
#define  MD_USB_RXFIFO2_MAXPKTSIZE_512          (0x06)   /** @brief FIFO MAXPKTSIZE  */
#define  MD_USB_RXFIFO2_MAXPKTSIZE_1024         (0x07)   /** @brief FIFO MAXPKTSIZE  */

#define  MD_USB_TXCSRH_MODE_RX                  (0x00)           /** @brief TXCSRH MODE  */
#define  MD_USB_TXCSRH_MODE_TX                  (0x01)           /** @brief TXCSRH MODE  */

/**
  * @} MD_USB_Public_Constants
  */

/* Public macro ---------------------------------------------------------------*/
/** @defgroup MD_USB_Public_Macros USB Public Macros
  * @{
  */

///** @defgroup MD_USB_PM_WRITE_READ Common write and read registers Macros
//  * @{
//  */

///**
//  * @brief  Write a value in USB register
//  * @param  __INSTANCE__ USB Instance
//  * @param  __REG__ Register to be written
//  * @param  __VALUE__ Value to be written in the register
//  * @retval None
//  */
//#define MD_USB_WRITEREG(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

///**
//  * @brief  Read a value in USB register
//  * @param  __INSTANCE__ USB Instance
//  * @param  __REG__ Register to be read
//  * @retval Register value
//  */
//#define MD_USB_READREG(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)

///**
//  * @brief  Modify value in USB register
//  * @param  __INSTANCE__ USB Instance
//  * @param  __REG__ Register to be written
//  * @param  __MASK__ Mask value to be written in the register
//  * @param  __VALUE__ Value to be written in the register
//  * @retval None
//  */
//#define MD_USB_MODIFYREG(__INSTANCE__, __REG__, __MASK__, __VALUE__) MODIFY_REG(__INSTANCE__->__REG__, __MASK__, (__VALUE__))

///**
//  * @brief  Set bit value in USB register
//  * @param  __INSTANCE__ USB Instance
//  * @param  __REG__ Register to be written
//  * @param  __MASK__ Mask value to be set in the register
//  * @retval None
//  */
//#define MD_USB_SET_BIT(__INSTANCE__, __REG__, __MASK__) SET_BIT(__INSTANCE__->__REG__, __MASK__)

///**
//  * @brief  Clear bit value in USB register
//  * @param  __INSTANCE__ USB Instance
//  * @param  __REG__ Register to be written
//  * @param  __MASK__ Mask value to be cleared in the register
//  * @retval None
//  */
//#define MD_USB_CLEAR_BIT(__INSTANCE__, __REG__, __MASK__) CLEAR_BIT(__INSTANCE__->__REG__, __MASK__)

///**
//  * @brief  Read bit value in USB register
//  * @param  __INSTANCE__ USB Instance
//  * @param  __REG__ Register to be read
//  * @param  __MASK__ Mask value to be read in the register
//  * @retval Register bit value
//  */
//#define MD_USB_READBIT(__INSTANCE__, __REG__, __MASK__) READ_BIT(__INSTANCE__->__REG__, __MASK__)
///**
//  * @} MD_USB_PM_WRITE_READ
//  */

/** @defgroup MD_USB_Macro_Drivers USB Public Macro Drivers
  * @{
  */

/**
  * @brief  Set USB FADDR
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0x7f
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_device_address(USB_TypeDef *usb, uint8_t Addr)
{
    MODIFY_REG(usb->FADDR, USB_FADDR_ADDR, Addr);
}

/**
  * @brief  Get USB FADDR
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x7f
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_device_address(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->FADDR, USB_FADDR_ADDR));
}

/**
  * @brief  Set USB POWER
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_power(USB_TypeDef *usb, uint8_t power)
{
    WRITE_REG(usb->POWER, power);
}

/**
  * @brief  Get USB POWER
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_power(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->POWER));
}

/**
  * @brief  Enable USB POWER RESET
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_reset(USB_TypeDef *usb)
{
    SET_BIT(usb->POWER, USB_POWER_RESET);
}

/**
  * @brief  Disable USB POWER RESET
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_reset(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->POWER, USB_POWER_RESET);
}

/**
  * @brief  Is USB POWER RESET Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_reset(USB_TypeDef *usb)
{
    return (READ_BIT(usb->POWER, USB_POWER_RESET) == (USB_POWER_RESET));
}

/**
  * @brief  Enable USB POWER RESUME
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_resume(USB_TypeDef *usb)
{
    SET_BIT(usb->POWER, USB_POWER_RESUME);
}

/**
  * @brief  Disable USB POWER RESUME
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_resume(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->POWER, USB_POWER_RESUME);
}

/**
  * @brief  Is USB POWER RESUME Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_resume(USB_TypeDef *usb)
{
    return (READ_BIT(usb->POWER, USB_POWER_RESUME) == (USB_POWER_RESUME));
}

/**
  * @brief  Enable USB POWER SUSPEND
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_suspend(USB_TypeDef *usb)
{
    SET_BIT(usb->POWER, USB_POWER_SUSPEND);
}

/**
  * @brief  Disable USB POWER SUSPEND
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_suspend(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->POWER, USB_POWER_SUSPEND);
}

/**
  * @brief  Is USB POWER SUSPEND Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_suspend(USB_TypeDef *usb)
{
    return (READ_BIT(usb->POWER, USB_POWER_SUSPEND) == (USB_POWER_SUSPEND));
}

/**
  * @brief  Enable USB POWER ISOUDT
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_isochronous_update(USB_TypeDef *usb)
{
    SET_BIT(usb->POWER, USB_POWER_ISOUDT);
}

/**
  * @brief  Disable USB POWER ISOUDT
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_isochronous_update(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->POWER, USB_POWER_ISOUDT);
}

/**
  * @brief  Is USB POWER ISOUDT Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_isochronous_update(USB_TypeDef *usb)
{
    return (READ_BIT(usb->POWER, USB_POWER_ISOUDT) == (USB_POWER_ISOUDT));
}

/**
  * @brief  Enable USB POWER SUSPENDEN
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_entry_suspend_mode(USB_TypeDef *usb)
{
    SET_BIT(usb->POWER, USB_POWER_SUSPENDEN);
}

/**
  * @brief  Disable USB POWER SUSPENDEN
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_entry_suspend_mode(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->POWER, USB_POWER_SUSPENDEN);
}

/**
  * @brief  Is USB POWER SUSPENDEN Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_entry_suspend_mode(USB_TypeDef *usb)
{
    return (READ_BIT(usb->POWER, USB_POWER_SUSPENDEN) == (USB_POWER_SUSPENDEN));
}

/**
  * @brief  Set USB DPDMCON
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0x1f
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_dpdmcon(USB_TypeDef *usb, uint8_t dpdmcon)
{
    WRITE_REG(usb->DPDMCON, dpdmcon);
}

/**
  * @brief  Get USB DPDMCON
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x1f
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_dpdmcon(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->DPDMCON));
}

/**
  * @brief  Set USB DPDMCON DPPUD
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg @ref MD_USB_DPDMCON_DPPUD_FLOATING  (0x00) : Floating
  *         @arg @ref MD_USB_DPDMCON_DPPUD_PULLUP    (0x01) : Pull-Up
  *         @arg @ref MD_USB_DPDMCON_DPPUD_PULLDOWN  (0x02) : Pull-Down
  * @retval None
  */
__STATIC_INLINE void md_usb_set_dp_pull_up_pull_down(USB_TypeDef *usb, uint8_t Pud)
{
    MODIFY_REG(usb->DPDMCON, USB_DPDMCON_DPPUD, Pud << USB_DPDMCON_DPPUD_POSS);
}

/**
  * @brief  Get USB DPDMCON DPPUD
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_USB_DPDMCON_DPPUD_FLOATING  (0x00) : Floating
  *         @arg @ref MD_USB_DPDMCON_DPPUD_PULLUP    (0x01) : Pull-Up
  *         @arg @ref MD_USB_DPDMCON_DPPUD_PULLDOWN  (0x02) : Pull-Down
  */
__STATIC_INLINE uint8_t md_usb_get_dp_pull_up_pull_down(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->DPDMCON, USB_DPDMCON_DPPUD) >> USB_DPDMCON_DPPUD_POSS);
}

/**
  * @brief  Set USB DPDMCON DMPUD
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg @ref MD_USB_DPDMCON_DMPUD_FLOATING  (0x00) : Floating
  *         @arg @ref MD_USB_DPDMCON_DMPUD_PULLUP    (0x01) : Pull-Up
  *         @arg @ref MD_USB_DPDMCON_DMPUD_PULLDOWN  (0x02) : Pull-Down
  * @retval None
  */
__STATIC_INLINE void md_usb_set_dm_pull_up_pull_down(USB_TypeDef *usb, uint8_t Pud)
{
    MODIFY_REG(usb->DPDMCON, USB_DPDMCON_DMPUD, Pud << USB_DPDMCON_DMPUD_POSS);
}

/**
  * @brief  Get USB DPDMCON DMPUD
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_USB_DPDMCON_DMPUD_FLOATING  (0x00) : Floating
  *         @arg @ref MD_USB_DPDMCON_DMPUD_PULLUP    (0x01) : Pull-Up
  *         @arg @ref MD_USB_DPDMCON_DMPUD_PULLDOWN  (0x02) : Pull-Down
  */
__STATIC_INLINE uint8_t md_usb_get_dm_pull_up_pull_down(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->DPDMCON, USB_DPDMCON_DMPUD) >> USB_DPDMCON_DMPUD_POSS);
}

/**
  * @brief  Enable USB DPDMCON PHYPWREN
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_phy_power(USB_TypeDef *usb)
{
    SET_BIT(usb->DPDMCON, USB_DPDMCON_PHYPWREN);
}

/**
  * @brief  Disable USB DPDMCON PHYPWREN
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_phy_power(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->DPDMCON, USB_DPDMCON_PHYPWREN);
}

/**
  * @brief  Is USB DPDMCON PHYPWREN Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_phy_power(USB_TypeDef *usb)
{
    return (READ_BIT(usb->DPDMCON, USB_DPDMCON_PHYPWREN) == (USB_DPDMCON_PHYPWREN));
}

/**
  * @brief  Set USB SWCID
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0x3
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_swcid(USB_TypeDef *usb, uint8_t swcid)
{
    WRITE_REG(usb->SWCID, swcid);
}

/**
  * @brief  Get USB SWCID
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x3
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_swcid(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->SWCID));
}

/**
  * @brief  Set USB SWCID HOST Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_set_software_control_host_mode(USB_TypeDef *usb)
{
    MODIFY_REG(usb->SWCID, USB_SWCID_HOST, MD_USB_SWCID_HOST_HOST << USB_SWCID_HOST_POS);
}

/**
  * @brief  Set USB SWCID DEVICE Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_set_software_control_device_mode(USB_TypeDef *usb)
{
    MODIFY_REG(usb->SWCID, USB_SWCID_HOST, MD_USB_SWCID_HOST_DEVICE << USB_SWCID_HOST_POS);
}

/**
  * @brief  Get USB SWCID HOST/DEVICE Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_USB_SWCID_HOST_HOST
            @arg @ref MD_USB_SWCID_HOST_DEVICE
  */
__STATIC_INLINE uint8_t md_usb_get_software_control_mode(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->SWCID, USB_SWCID_HOST) >> USB_SWCID_HOST_POS);
}

/**
  * @brief  Set USB SWCID CIDCTRL
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_software_control_cid(USB_TypeDef *usb)
{
    MODIFY_REG(usb->SWCID, USB_SWCID_CIDCTRL, MD_USB_SWCID_CIDCTRL_SOFTWARE << USB_SWCID_CIDCTRL_POS);
}

/**
  * @brief  Set USB SWCID CIDCTRL
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_software_control_cid(USB_TypeDef *usb)
{
    MODIFY_REG(usb->SWCID, USB_SWCID_CIDCTRL, MD_USB_SWCID_CIDCTRL_HARDWARE << USB_SWCID_CIDCTRL_POS);
}

/**
  * @brief  Is USB SWCID CIDCTRL
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_software_control_cid(USB_TypeDef *usb)
{
    return (READ_BIT(usb->SWCID, USB_SWCID_CIDCTRL) == (USB_SWCID_CIDCTRL));
}

/**
  * @brief  Set USB SWVBUS
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xf
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_swvbus(USB_TypeDef *usb, uint8_t swvbus)
{
    WRITE_REG(usb->SWVBUS, swvbus);
}

/**
  * @brief  Get USB SWVBUS
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xf
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_swvbus(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->SWVBUS));
}

/**
  * @brief  Set USB SWVBUS VALTH
  * @param  usb USB Instance
  * @param  valth
            @arg @ref MD_USB_SWVBUS_VALTH_LOWER_VBUS
            @arg @ref MD_USB_SWVBUS_VALTH_HIGHER_VBUS
  * @retval None
  */
__STATIC_INLINE void md_usb_set_vbus_valid_threshold(USB_TypeDef *usb, uint8_t valth)
{
    MODIFY_REG(usb->SWVBUS, USB_SWVBUS_VALTH, valth << USB_SWVBUS_VALTH_POS);
}

/**
  * @brief  Get USB SWVBUS VALTH
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_USB_SWVBUS_VALTH_LOWER_VBUS
            @arg @ref MD_USB_SWVBUS_VALTH_HIGHER_VBUS
  */
__STATIC_INLINE uint8_t md_usb_get_vbus_valid_threshold(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->SWVBUS, USB_SWVBUS_VALTH) >> USB_SWVBUS_VALTH_POS);
}

/**
  * @brief  Set USB SWVBUS SESVALTH
  * @param  usb USB Instance
  * @param  sesvalth
            @arg @ref MD_USB_SWVBUS_SESVALTH_LOWER_SESVAL
            @arg @ref MD_USB_SWVBUS_SESVALTH_HIGHER_SESVAL
  * @retval None
  */
__STATIC_INLINE void md_usb_set_session_valid_threshold(USB_TypeDef *usb, uint8_t sesvalth)
{
    MODIFY_REG(usb->SWVBUS, USB_SWVBUS_SESVALTH, sesvalth << USB_SWVBUS_SESVALTH_POS);
}

/**
  * @brief  Get USB SWVBUS SESVALTH
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_USB_SWVBUS_SESVALTH_LOWER_SESVAL
            @arg @ref MD_USB_SWVBUS_SESVALTH_HIGHER_SESVAL
  */
__STATIC_INLINE uint8_t md_usb_get_session_valid_threshold(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->SWVBUS, USB_SWVBUS_SESVALTH) >> USB_SWVBUS_SESVALTH_POS);
}

/**
  * @brief  Set USB SWVBUS SESENDTH
  * @param  usb USB Instance
  * @param  sesendth
            @arg @ref MD_USB_SWVBUS_SESENDTH_LOWER_SESEND
            @arg @ref MD_USB_SWVBUS_SESENDTH_HIGHER_SESEND
  * @retval None
  */
__STATIC_INLINE void md_usb_set_session_end_threshold(USB_TypeDef *usb, uint8_t sesendth)
{
    MODIFY_REG(usb->SWVBUS, USB_SWVBUS_SESENDTH, sesendth << USB_SWVBUS_SESENDTH_POS);
}

/**
  * @brief  Get USB SWVBUS SESENDTH
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_USB_SWVBUS_SESENDTH_LOWER_SESEND
            @arg @ref MD_USB_SWVBUS_SESENDTH_HIGHER_SESEND
  */
__STATIC_INLINE uint8_t md_usb_get_session_end_threshold(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->SWVBUS, USB_SWVBUS_SESENDTH) >> USB_SWVBUS_SESENDTH_POS);
}

/**
  * @brief  Set USB SWVBUS Hardware Control
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_set_vbus_hardware_control(USB_TypeDef *usb)
{
    MODIFY_REG(usb->SWVBUS, USB_SWVBUS_SIGCTRL, MD_USB_SWVBUS_SIGCTRL_HARDWARE << USB_SWVBUS_SIGCTRL_POS);
}

/**
  * @brief  Set USB SWVBUS Software Control
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_set_vbus_software_control(USB_TypeDef *usb)
{
    MODIFY_REG(usb->SWVBUS, USB_SWVBUS_SIGCTRL, MD_USB_SWVBUS_SIGCTRL_SOFTWARE << USB_SWVBUS_SIGCTRL_POS);
}

/**
  * @brief  Get USB SWVBUS SIGCTRL
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_USB_SWVBUS_SIGCTRL_HARDWARE
            @arg @ref MD_USB_SWVBUS_SIGCTRL_SOFTWARE
  */
__STATIC_INLINE uint8_t md_usb_get_vbus_control_mode(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->SWVBUS, USB_SWVBUS_SIGCTRL) >> USB_SWVBUS_SIGCTRL_POS);
}

/**
  * @brief  Get USB FRAME COUNTER
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x7FF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint16_t md_usb_get_frame_number(USB_TypeDef *usb)
{
    return (uint16_t)((READ_BIT(usb->FRAME2, USB_FRAME2_UPFRAME) << 8) | (READ_BIT(usb->FRAME1, USB_FRAME1_LOWFRAME)));
}

/**
  * @brief  Set USB EPTIDX
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xf
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_epx_index(USB_TypeDef *usb, uint8_t Index)
{
    MODIFY_REG(usb->INDEX, USB_INDEX_EPTIDX, Index);
}

/**
  * @brief  Get USB EPTIDX
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xf
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_epx_index(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->INDEX, USB_INDEX_EPTIDX));
}

/**
  * @brief  Set USB DEVCON
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_devcon(USB_TypeDef *usb, uint8_t devcon)
{
    WRITE_REG(usb->DEVCON, devcon);
}

/**
  * @brief  Get USB DEVCON
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_devcon(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->DEVCON));
}

/**
  * @brief  Is USB DEVCON CID A TYPE Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : True
  *         @arg 0x0 : False
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_cid_a_type(USB_TypeDef *usb)
{
    return (READ_BIT(usb->DEVCON, USB_DEVCON_CID) != (USB_DEVCON_CID));
}

/**
  * @brief  Is USB DEVCON CID B TYPE Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : True
  *         @arg 0x0 : False
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_cid_b_type(USB_TypeDef *usb)
{
    return (READ_BIT(usb->DEVCON, USB_DEVCON_CID) == (USB_DEVCON_CID));
}

/**
  * @brief  Is USB DEVCON FSDEV Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : True
  *         @arg 0x0 : False
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_full_speed_detected(USB_TypeDef *usb)
{
    return (READ_BIT(usb->DEVCON, USB_DEVCON_FSDEV) == (USB_DEVCON_FSDEV));
}

/**
  * @brief  Is USB DEVCON LSDEV Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : True
  *         @arg 0x0 : False
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_low_speed_detected(USB_TypeDef *usb)
{
    return (READ_BIT(usb->DEVCON, USB_DEVCON_LSDEV) == (USB_DEVCON_LSDEV));
}

/**
  * @brief  Is USB DEVCON HOST MODE Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : True
  *         @arg 0x0 : False
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_host_mode(USB_TypeDef *usb)
{
    return (READ_BIT(usb->DEVCON, USB_DEVCON_HOST) == (USB_DEVCON_HOST));
}

/**
  * @brief  Is USB DEVCON DEVICE MODE Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : True
  *         @arg 0x0 : False
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_device_mode(USB_TypeDef *usb)
{
    return (READ_BIT(usb->DEVCON, USB_DEVCON_HOST) != (USB_DEVCON_HOST));
}

/**
  * @brief  Enable USB DEVCON HOSTREQ
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_host_request(USB_TypeDef *usb)
{
    SET_BIT(usb->DEVCON, USB_DEVCON_HOSTREQ);
}

/**
  * @brief  Disable USB DEVCON HOSTREQ
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_host_request(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->DEVCON, USB_DEVCON_HOSTREQ);
}

/**
  * @brief  Is USB DEVCON HOSTREQ Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_host_request(USB_TypeDef *usb)
{
    return (READ_BIT(usb->DEVCON, USB_DEVCON_HOSTREQ) == (USB_DEVCON_HOSTREQ));
}

/**
  * @brief  Enable USB DEVCON SESSION
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_session(USB_TypeDef *usb)
{
    SET_BIT(usb->DEVCON, USB_DEVCON_SESSION);
}

/**
  * @brief  Disable USB DEVCON SESSION
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_session(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->DEVCON, USB_DEVCON_SESSION);
}

/**
  * @brief  Is USB DEVCON SESSION Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_session(USB_TypeDef *usb)
{
    return (READ_BIT(usb->DEVCON, USB_DEVCON_SESSION) == (USB_DEVCON_SESSION));
}

/**
  * @brief  Set USB TXMAXP MAXSIZE
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_tx_max_packet_size(USB_TypeDef *usb, uint8_t Maxsize)
{
    MODIFY_REG(usb->TXMAXP, USB_TXMAXP_MAXSIZE, Maxsize);
}

/**
  * @brief  Get USB TXMAXP MAXSIZE
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_tx_max_packet_size(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->TXMAXP, USB_TXMAXP_MAXSIZE));
}

/**
  * @brief  Set USB CSR0L_TXCSRL
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_csr0l_txcsrl(USB_TypeDef *usb, uint8_t txcsrl)
{
    WRITE_REG(usb->CSR0L_TXCSRL, txcsrl);
}

/**
  * @brief  Get USB CSR0L_TXCSRL
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_csr0l_txcsrl(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->CSR0L_TXCSRL));
}

/**
  * @brief  Clear USB CSR0L NAKTO
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_ep0_nak_timeout(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_NAKTO);
}

/**
  * @brief  Is USB CSR0L NAKTO Active
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_ep0_nak_timeout(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_NAKTO) == (USB_CSR0L_NAKTO));
}

/**
  * @brief  Enable USB CSR0L STATUSPKT
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_ep0_send_status_packet(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_STATUSPKT);
}

/**
  * @brief  Disable USB CSR0L STATUSPKT
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_ep0_send_status_packet(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_STATUSPKT);
}

/**
  * @brief  Is USB CSR0L STATUSPKT Enabled
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_ep0_send_status_packet(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_STATUSPKT) == (USB_CSR0L_STATUSPKT));
}

/**
  * @brief  Enable USB CSR0L REQPKT
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_ep0_request_packet(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_REQPKT);
}

/**
  * @brief  Disable USB CSR0L REQPKT
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_ep0_request_packet(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_REQPKT);
}

/**
  * @brief  Is USB CSR0L REQPKT Enabled
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_ep0_request_packet(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_REQPKT) == (USB_CSR0L_REQPKT));
}

/**
  * @brief  Clear USB CSR0L ERROR
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_ep0_error(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_ERROR);
}

/**
  * @brief  Is USB CSR0L ERROR Active
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Error
  *         @arg 0x0 : No error
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_ep0_error(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_ERROR) == (USB_CSR0L_ERROR));
}

/**
  * @brief  Enable USB CSR0L SETUPPKT
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_ep0_send_setup_packet(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_SETUPPKT);
}

/**
  * @brief  Disable USB CSR0L SETUPPKT
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_ep0_send_setup_packet(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_SETUPPKT);
}

/**
  * @brief  Is USB CSR0L SETUPPKT Enabled
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_ep0_send_setup_packet(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_SETUPPKT) == (USB_CSR0L_SETUPPKT));
}

/**
  * @brief  Clear USB CSR0L STALLED
  * @note   CSR0L_TXCSRL in Endpoint 0 Host/Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_ep0_stalled(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_STALLED);
}

/**
  * @brief  Is USB CSR0L STALLED Active
  * @note   CSR0L_TXCSRL in Endpoint 0 Host/Device Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_ep0_stalled(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_STALLED) == (USB_CSR0L_STALLED));
}

/**
  * @brief  Enable USB CSR0L TXRDY
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_ep0_tx_ready(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_TXRDY);
}

/**
  * @brief  Is USB CSR0L TXRDY Enabled
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_ep0_tx_ready(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_TXRDY) == (USB_CSR0L_TXRDY));
}

/**
  * @brief  Clear USB CSR0L RXRDY
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_host_ep0_rx_ready(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_RXRDY);
}

/**
  * @brief  Is USB CSR0L RXRDY Active
  * @note   CSR0L_TXCSRL in Endpoint 0 Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_host_ep0_rx_ready(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_RXRDY) == (USB_CSR0L_RXRDY));
}

/**
  * @brief  Clear USB CSR0L SETENDC
  * @note   CSR0L_TXCSRL in Endpoint 0 Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_ep0_setup_end(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_SETENDC);
}

/**
  * @brief  Clear USB CSR0L RXRDYC
  * @note   CSR0L_TXCSRL in Endpoint 0 Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_device_ep0_rx_ready(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_RXRDYC);
}

/**
  * @brief  Set USB CSR0L SEND STALL
  * @note   CSR0L_TXCSRL in Endpoint 0 Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_set_ep0_send_stall(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_STALL);
}

/**
  * @brief  Is USB CSR0L SETEND Active
  * @note   CSR0L_TXCSRL in Endpoint 0 Device Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_ep0_setup_end(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_SETEND) == (USB_CSR0L_SETEND));
}

/**
  * @brief  Set CSR0L DATAEND
  * @note   CSR0L_TXCSRL in Endpoint 0 Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_set_ep0_data_end(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_DATAEND);
}

/**
  * @brief  Is USB CSR0L RXRDY Active
  * @note   CSR0L_TXCSRL in Endpoint 0 Device Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_device_ep0_rx_ready(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_CSR0L_RXRDY) == (USB_CSR0L_RXRDY));
}

/**
  * @brief  Clear USB TXCSRL NAKTO
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_epx_tx_nak_timeout(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_NAKTO);
}

/**
  * @brief  Is USB TXCSRL NAKTO Active
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : NAK Timeout
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_epx_tx_nak_timeout(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_NAKTO) == (USB_TXCSRL_NAKTO));
}

/**
  * @brief  Trigger USB TXCSRL CLRDT
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_trigger_epx_tx_clear_data_toggle(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_CLRDT);
}

/**
  * @brief  Clear USB TXCSRL STALLED
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_epx_tx_stalled(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_STALLED);
}

/**
  * @brief  Is USB TXCSRL STALLED Active
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_epx_tx_stalled(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_STALLED) == (USB_TXCSRL_STALLED));
}

/**
  * @brief  Trigger USB TXCSRL FLUSH
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_trigger_epx_tx_flush_fifo(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_FLUSH);
}

/**
  * @brief  Clear USB TXCSRL ERROR
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_epx_tx_error(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_ERROR);
}

/**
  * @brief  Is USB TXCSRL ERROR Active
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_epx_tx_error(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_ERROR) == (USB_TXCSRL_ERROR));
}

/**
  * @brief  Clear USB TXCSRL FIFONE
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_epx_tx_fifo_not_empty(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_FIFONE);
}

/**
  * @brief  Is USB TXCSRL FIFONE Active
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_epx_tx_fifo_not_empty(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_FIFONE) == (USB_TXCSRL_FIFONE));
}

/**
  * @brief  Enable USB TXCSRL TXRDY
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_epx_tx_ready(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_TXRDY);
}

/**
  * @brief  Is USB TXCSRL TXRDY Enabled
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_epx_tx_ready(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_TXRDY) == (USB_TXCSRL_TXRDY));
}

/**
  * @brief  Enable USB TXCSRL STALL
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_epx_tx_send_stall(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_STALL);
}

/**
  * @brief  Disable USB CSR0L TXCSRL
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_epx_tx_send_stall(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_STALL);
}

/**
  * @brief  Is USB CSR0L TXCSRL Enabled
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Device Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_epx_tx_send_stall(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_STALL) == (USB_TXCSRL_STALL));
}

/**
  * @brief  Clear USB TXCSRL UNDRUN
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_epx_tx_underrun(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_UNDRUN);
}

/**
  * @brief  Is USB TXCSRL UNDRUN Active
  * @note   CSR0L_TXCSRL in Endpoint 1~6 Device Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_epx_tx_underrun(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0L_TXCSRL, USB_TXCSRL_UNDRUN) == (USB_TXCSRL_UNDRUN));
}

/**
  * @brief  Set USB CSR0H_TXCSRH
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_csr0h_txcsrh(USB_TypeDef *usb, uint8_t txcsrh)
{
    WRITE_REG(usb->CSR0H_TXCSRH, txcsrh);
}

/**
  * @brief  Get USB CSR0H_TXCSRH
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_csr0h_txcsrh(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->CSR0H_TXCSRH));
}

/**
  * @brief  Trigger USB CSR0H FLUSH
  * @note   CSR0H_TXCSRH in Endpoint 0 Host/Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_trigger_ep0_flush_fifo(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0H_TXCSRH, USB_CSR0H_FLUSH);
}

/**
  * @brief  Enable USB TXCSRH AUTOSET
  * @note   CSR0H_TXCSRH in Endpoint 1~6 Host/Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_epx_autoset_tx_ready(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0H_TXCSRH, USB_TXCSRH_AUTOSET);
}

/**
  * @brief  Disable USB TXCSRH AUTOSET
  * @note       CSR0H_TXCSRH in Endpoint 1~6 Host/Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_epx_autoset_tx_ready(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0H_TXCSRH, USB_TXCSRH_AUTOSET);
}

/**
  * @brief  Is USB TXCSRH AUTOSET Enabled
  * @note   CSR0H_TXCSRH in Endpoint 1~6 Host/Device Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_epx_autoset_tx_ready(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0H_TXCSRH, USB_TXCSRH_AUTOSET) == (USB_TXCSRH_AUTOSET));
}

/**
  * @brief  Enable USB TXCSRH ISO
  * @note   CSR0H_TXCSRH in Endpoint 1~6 Host/Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_epx_tx_isochronous(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0H_TXCSRH, USB_TXCSRH_ISO);
}

/**
  * @brief  Disbale USB TXCSRH ISO
  * @note   CSR0H_TXCSRH in Endpoint 1~6 Host/Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_epx_tx_isochronous(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0H_TXCSRH, USB_TXCSRH_ISO);
}

/**
  * @brief  Is USB TXCSRH ISO Enabled
  * @note   CSR0H_TXCSRH in Endpoint 1~6 Host/Device Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_epx_tx_isochronous(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0H_TXCSRH, USB_TXCSRH_ISO) == (USB_TXCSRH_ISO));
}

/**
  * @brief  Set USB TXCSRH MODE
  * @note   CSR0H_TXCSRH in Endpoint 1~6 Host/Device Mode
  * @param  usb USB Instance
  * @param  mode
            @arg @ref MD_USB_TXCSRH_MODE_RX
            @arg @ref MD_USB_TXCSRH_MODE_TX
  * @retval None
  */
__STATIC_INLINE void md_usb_set_epx_mode(USB_TypeDef *usb, uint8_t mode)
{
    MODIFY_REG(usb->CSR0H_TXCSRH, USB_TXCSRH_MODE, mode << USB_TXCSRH_MODE_POS);
}

/**
  * @brief  Get USB TXCSRH MODE
  * @note   CSR0H_TXCSRH in Endpoint 1~6 Host/Device Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_USB_TXCSRH_MODE_RX
            @arg @ref MD_USB_TXCSRH_MODE_TX
  */
__STATIC_INLINE uint8_t md_usb_get_epx_mode(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->CSR0H_TXCSRH, USB_TXCSRH_MODE) >> USB_TXCSRH_MODE_POS);
}

/**
  * @brief  Enable USB TXCSRH FDT
  * @note   CSR0H_TXCSRH in Endpoint 1~6 Host/Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_epx_tx_force_data_toggle(USB_TypeDef *usb)
{
    SET_BIT(usb->CSR0H_TXCSRH, USB_TXCSRH_FDT);
}

/**
  * @brief  Disable USB TXCSRH FDT
  * @note   CSR0H_TXCSRH in Endpoint 1~6 Host/Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_epx_tx_force_data_toggle(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->CSR0H_TXCSRH, USB_TXCSRH_FDT);
}

/**
  * @brief  Is USB TXCSRH FDT Enabled
  * @note   CSR0H_TXCSRH in Endpoint 1~6 Host/Device Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_epx_tx_force_data_toggle(USB_TypeDef *usb)
{
    return (READ_BIT(usb->CSR0H_TXCSRH, USB_TXCSRH_FDT) == (USB_TXCSRH_FDT));
}

/**
  * @brief  Set USB RXMAXP
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_rx_max_packet_size(USB_TypeDef *usb, uint8_t rxmaxp)
{
    WRITE_REG(usb->RXMAXP, rxmaxp);
}

/**
  * @brief  Get USB RXMAXP
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_rx_max_packet_size(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->RXMAXP));
}

/**
  * @brief  Set USB RXCSRL
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_rxcsrl(USB_TypeDef *usb, uint8_t rxcsrl)
{
    WRITE_REG(usb->RXCSRL, rxcsrl);
}

/**
  * @brief  Get USB RXCSRL
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_rxcsrl(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->RXCSRL));
}

/**
  * @brief  Trigger USB RXCSRL CLRDT
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_trigger_epx_rx_clear_data_toggle(USB_TypeDef *usb)
{
    SET_BIT(usb->RXCSRL, USB_RXCSRL_CLRDT);
}

/**
  * @brief  Clear USB RXCSRL STALLED
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_epx_rx_stalled(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->RXCSRL, USB_RXCSRL_STALLED);
}

/**
  * @brief  Is USB RXCSRL STALLED Active
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_epx_rx_stalled(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXCSRL, USB_RXCSRL_STALLED) == (USB_RXCSRL_STALLED));
}

/**
  * @brief  Enable USB RXCSRL REQPKT
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_epx_rx_request_packet(USB_TypeDef *usb)
{
    SET_BIT(usb->RXCSRL, USB_RXCSRL_REQPKT);
}

/**
  * @brief  Disable USB RXCSRL REQPKT
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_epx_rx_request_packet(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->RXCSRL, USB_RXCSRL_REQPKT);
}

/**
  * @brief  Is USB RXCSRL REQPKT Enabled
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_epx_rx_request_packet(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXCSRL, USB_RXCSRL_REQPKT) == (USB_RXCSRL_REQPKT));
}

/**
  * @brief  Trigger USB RXCSRL FLUSH
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_trigger_epx_rx_flush_fifo(USB_TypeDef *usb)
{
    SET_BIT(usb->RXCSRL, USB_RXCSRL_FLUSH);
}

/**
  * @brief  Clear USB RXCSRL DATAERR
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_epx_rx_data_error(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->RXCSRL, USB_RXCSRL_DATAERR);
}

/**
  * @brief  Is USB RXCSRL DATAERR Active
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_epx_rx_data_error(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXCSRL, USB_RXCSRL_DATAERR) == (USB_RXCSRL_DATAERR));
}

/**
  * @brief  Clear USB RXCSRL NAKTO
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_epx_rx_nak_timeout(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->RXCSRL, USB_RXCSRL_NAKTO);
}

/**
  * @brief  Is USB RXCSRL NAKTO Active
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_epx_rx_nak_timeout(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXCSRL, USB_RXCSRL_NAKTO) == (USB_RXCSRL_NAKTO));
}

/**
  * @brief  Clear USB RXCSRL ERROR
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_epx_rx_error(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->RXCSRL, USB_RXCSRL_ERROR);
}

/**
  * @brief  Is USB RXCSRL ERROR Active
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_epx_rx_error(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXCSRL, USB_RXCSRL_ERROR) == (USB_RXCSRL_ERROR));
}

/**
  * @brief  Is USB RXCSRL FULL Active
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_epx_rx_fifo_full(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXCSRL, USB_RXCSRL_FULL) == (USB_RXCSRL_FULL));
}

/**
  * @brief  Clear USB RXCSRL RXRDY
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_epx_rx_ready(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->RXCSRL, USB_RXCSRL_RXRDY);
}

/**
  * @brief  Is USB RXCSRL RXRDY Active
  * @note   RXCSRL in Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_epx_rx_ready(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXCSRL, USB_RXCSRL_RXRDY) == (USB_RXCSRL_RXRDY));
}

/**
  * @brief  Enable USB RXCSRL STALL
  * @note   RXCSRL in Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_epx_rx_send_stall(USB_TypeDef *usb)
{
    SET_BIT(usb->RXCSRL, USB_RXCSRL_STALL);
}

/**
  * @brief  Disable USB RXCSRL STALL
  * @note   RXCSRL in Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_epx_rx_send_stall(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->RXCSRL, USB_RXCSRL_STALL);
}

/**
  * @brief  Is USB RXCSRL STALL Enabled
  * @note   RXCSRL in Device Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_epx_rx_send_stall(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXCSRL, USB_RXCSRL_STALL) == (USB_RXCSRL_STALL));
}

/**
  * @brief  Clear USB RXCSRL OVERRUN
  * @note   RXCSRL in Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_flag_epx_rx_overrun(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->RXCSRL, USB_RXCSRL_OVERRUN);
}

/**
  * @brief  Is USB RXCSRL OVERRUN Active
  * @note   RXCSRL in Device Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_flag_epx_rx_overrun(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXCSRL, USB_RXCSRL_OVERRUN) == (USB_RXCSRL_OVERRUN));
}

/**
  * @brief  Set USB RXCSRH
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_rxcsrh(USB_TypeDef *usb, uint8_t rxcsrh)
{
    WRITE_REG(usb->RXCSRH, rxcsrh);
}

/**
  * @brief  Get USB RXCSRH
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_rxcsrh(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->RXCSRH));
}

/**
  * @brief  Enable USB RXCSRH AUTOCLR
  * @note   RXCSRH in Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_epx_auto_clear_rx_ready(USB_TypeDef *usb)
{
    SET_BIT(usb->RXCSRH, USB_RXCSRH_AUTOCLR);
}

/**
  * @brief  Disable USB RXCSRH AUTOCLR
  * @note   RXCSRH in Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_epx_auto_clear_rx_ready(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->RXCSRH, USB_RXCSRH_AUTOCLR);
}

/**
  * @brief  Is USB RXCSRH AUTOCLR Enabled
  * @note   RXCSRH in Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_epx_auto_clear_rx_ready(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXCSRH, USB_RXCSRH_AUTOCLR) == (USB_RXCSRH_AUTOCLR));
}

/**
  * @brief  Enable USB RXCSRH AUTOREQ
  * @note   RXCSRH in Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_epx_rx_auto_request(USB_TypeDef *usb)
{
    SET_BIT(usb->RXCSRH, USB_RXCSRH_AUTOREQ);
}

/**
  * @brief  Disable USB RXCSRH AUTOREQ
  * @note   RXCSRH in Host Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_epx_rx_auto_request(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->RXCSRH, USB_RXCSRH_AUTOREQ);
}

/**
  * @brief  Is USB RXCSRH AUTOREQ Enabled
  * @note   RXCSRH in Host Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_epx_rx_auto_request(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXCSRH, USB_RXCSRH_AUTOREQ) == (USB_RXCSRH_AUTOREQ));
}

/**
  * @brief  Enable USB RXCSRH ISO
  * @note   RXCSRH in Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_epx_rx_isochronous(USB_TypeDef *usb)
{
    SET_BIT(usb->RXCSRH, USB_RXCSRH_ISO);
}

/**
  * @brief  Disable USB RXCSRH ISO
  * @note       RXCSRH in Device Mode
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_epx_rx_isochronous(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->RXCSRH, USB_RXCSRH_ISO);
}

/**
  * @brief  Is USB RXCSRH ISO Enabled
  * @note       RXCSRH in Device Mode
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_epx_rx_isochronous(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXCSRH, USB_RXCSRH_ISO) == (USB_RXCSRH_ISO));
}

/**
  * @brief  Get USB COUNT0_RX1 COUNT
  * @note   COUNT0_RX1 in Endpoint 0 Host/Device Mode (Enapoint 0)
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_ep0_data_count(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->COUNT0_RX1, USB_COUNT0_COUNT));
}

/**
  * @brief  Get USB COUNT0_RX1 PKT COUNT
  * @note   COUNT0_RX1 in Host/Device Mode (Enapoint 1~6)
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x7FF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint16_t md_usb_get_epx_packet_count(USB_TypeDef *usb)
{
    return (uint16_t)((READ_BIT(usb->RXCOUNT2, USB_RXCOUNT2_PKTHIGH) << 8) | (READ_BIT(usb->COUNT0_RX1, USB_RX1_PKTLOW)));
}

/**
  * @brief  Set USB TXTYPE PROTOCOL
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg @ref MD_USB_TXTYPE_PROTOCOL_CONTROL        (0x00) : Control
  *         @arg @ref MD_USB_TXTYPE_PROTOCOL_ISOCHRONOUS    (0x01) : Isochronous
  *         @arg @ref MD_USB_TXTYPE_PROTOCOL_BULK           (0x02) : Bulk
  *         @arg @ref MD_USB_TXTYPE_PROTOCOL_INTERRUPT      (0x03) : Interrupt
  * @retval None
  */
__STATIC_INLINE void md_usb_set_tx_protocol(USB_TypeDef *usb, uint8_t Protocol)
{
    MODIFY_REG(usb->TXTYPE, USB_TXTYPE_PROTOCOL, Protocol << USB_TXTYPE_PROTOCOL_POSS);
}

/**
  * @brief  Get USB TXTYPE PROTOCOL
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_USB_TXTYPE_PROTOCOL_CONTROL        (0x00) : Control
  *         @arg @ref MD_USB_TXTYPE_PROTOCOL_ISOCHRONOUS    (0x01) : Isochronous
  *         @arg @ref MD_USB_TXTYPE_PROTOCOL_BULK           (0x02) : Bulk
  *         @arg @ref MD_USB_TXTYPE_PROTOCOL_INTERRUPT      (0x03) : Interrupt
  */
__STATIC_INLINE uint8_t md_usb_get_tx_protocol(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->TXTYPE, USB_TXTYPE_PROTOCOL) >> USB_TXTYPE_PROTOCOL_POSS);
}

/**
  * @brief  Set USB TXTYPE TEPN
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xf
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_tx_target_endpoint(USB_TypeDef *usb, uint8_t TEPn)
{
    MODIFY_REG(usb->TXTYPE, USB_TXTYPE_TEPN, TEPn);
}

/**
  * @brief  Get USB TXTYPE TEPN
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xf
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_tx_target_endpoint(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->TXTYPE, USB_TXTYPE_TEPN));
}

/**
  * @brief  Set USB EP0 NAK LIMIT
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_ep0_nak_limit(USB_TypeDef *usb, uint8_t NAKLmt)
{
    MODIFY_REG(usb->NAKLIMIT0_TXINTERVAL, USB_NAKLIMIT0_NAKLMT, NAKLmt);
}

/**
  * @brief  Get USB EP0 NAK LIMIT
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_ep0_nak_limit(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->NAKLIMIT0_TXINTERVAL, USB_NAKLIMIT0_NAKLMT));
}

/**
  * @brief  Set USB EP1-6 NAK LIMIT
  * @note   NAK LIMIT in Control/BULK Transfer Type
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_epx_tx_nak_limit(USB_TypeDef *usb, uint8_t NAKLmt)
{
    MODIFY_REG(usb->NAKLIMIT0_TXINTERVAL, USB_TXINTERVAL_NAKLMT, NAKLmt);
}

/**
  * @brief  Get USB EP1-6 NAK LIMIT
  * @note   NAK LIMIT in Control/Bulk Transfer Type
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_epx_tx_nak_limit(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->NAKLIMIT0_TXINTERVAL, USB_TXINTERVAL_NAKLMT));
}

/**
  * @brief  Set USB EP1-6 TX polling
  * @note   TX polling in Interrupt/Isochronous Transfer Type
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x1
  * @retval None
  */
__STATIC_INLINE void md_usb_set_epx_tx_polling_interval(USB_TypeDef *usb, uint8_t TxPoll)
{
    MODIFY_REG(usb->NAKLIMIT0_TXINTERVAL, USB_TXINTERVAL_TXPOLL, TxPoll);
}

/**
  * @brief  Get USB EP1-6 TX polling
  * @note   TX polling in Interrupt/Isochronous Transfer Type
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x1
  */
__STATIC_INLINE uint8_t md_usb_get_epx_tx_polling_interval(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->NAKLIMIT0_TXINTERVAL, USB_TXINTERVAL_TXPOLL));
}

/**
  * @brief  Set USB RXTYPE PROTOCOL
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg @ref MD_USB_RXTYPE_PROTOCOL_CONTROL            (0x00) : Control
  *         @arg @ref MD_USB_RXTYPE_PROTOCOL_ISOCHRONOUS        (0x01) : Isochronous
  *         @arg @ref MD_USB_RXTYPE_PROTOCOL_BULK               (0x02) : Bulk
  *         @arg @ref MD_USB_RXTYPE_PROTOCOL_INTERRUPT          (0x03) : Interrupt
  * @retval None
  */
__STATIC_INLINE void md_usb_set_rx_protocol(USB_TypeDef *usb, uint8_t Protocol)
{
    MODIFY_REG(usb->RXTYPE, USB_RXTYPE_PROTOCOL, Protocol << USB_RXTYPE_PROTOCOL_POSS);
}

/**
  * @brief  Get USB RXTYPE PROTOCOL
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_USB_RXTYPE_PROTOCOL_CONTROL            (0x00) : Control
  *         @arg @ref MD_USB_RXTYPE_PROTOCOL_ISOCHRONOUS        (0x01) : Isochronous
  *         @arg @ref MD_USB_RXTYPE_PROTOCOL_BULK               (0x02) : Bulk
  *         @arg @ref MD_USB_RXTYPE_PROTOCOL_INTERRUPT          (0x03) : Interrupt
  */
__STATIC_INLINE uint8_t md_usb_get_rx_protocol(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->RXTYPE, USB_RXTYPE_PROTOCOL) >> USB_RXTYPE_PROTOCOL_POSS);
}

/**
  * @brief  Set USB RXTYPE TEPN
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xf
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_rx_target_endpoint(USB_TypeDef *usb, uint8_t TEPn)
{
    MODIFY_REG(usb->RXTYPE, USB_RXTYPE_TEPN, TEPn);
}

/**
  * @brief  Get USB RXTYPE TEPN
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xf
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_rx_target_endpoint(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->RXTYPE, USB_RXTYPE_TEPN));
}

/**
  * @brief  Set USB RXINTERVAL NAKLMT
  * @note   RXINTERVAL in Bulk Transfer Type
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_rx_nak_limit(USB_TypeDef *usb, uint8_t NAKLmt)
{
    MODIFY_REG(usb->RXINTERVAL, USB_RXINTERVAL_NAKLMT, NAKLmt);
}

/**
  * @brief  Get USB RXINTERVAL NAKLMT
  * @note   RXINTERVAL in Bulk Transfer Type
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_epx_rx_nak_limit(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->RXINTERVAL, USB_RXINTERVAL_NAKLMT));
}

/**
  * @brief  Set USB RXINTERVAL RXPOLL
  * @note   RXINTERVAL in Interrupt/Isochronous Transfer Type
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x1
  * @retval None
  */
__STATIC_INLINE void md_usb_set_rx_polling_interval(USB_TypeDef *usb, uint8_t RxPoll)
{
    MODIFY_REG(usb->RXINTERVAL, USB_RXINTERVAL_RXPOLL, RxPoll);
}

/**
  * @brief  Get USB RXINTERVAL RXPOLL
  * @note   RXINTERVAL in Interrupt/Isochronous Transfer Type
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x1
  */
__STATIC_INLINE uint8_t md_usb_get_epx_rx_polling_interval(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->RXINTERVAL, USB_RXINTERVAL_RXPOLL));
}

/**
  * @brief  Set USB TXFIFO1 START ADDRESS
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xfff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_tx_fifo_start_addr(USB_TypeDef *usb, uint16_t Addr)
{
    MODIFY_REG(usb->TXFIFO2, USB_TXFIFO2_ADDRH, (uint8_t)(Addr >> 8));
    MODIFY_REG(usb->TXFIFO1, USB_TXFIFO1_ADDRL, (uint8_t)(Addr & 0xff));
}

/**
  * @brief  Get USB TXFIFO1 START ADDRESS
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xfff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint16_t md_usb_get_tx_fifo_start_addr(USB_TypeDef *usb)
{
    return (uint16_t)((READ_BIT(usb->TXFIFO2, USB_TXFIFO2_ADDRH) << 8) | (READ_BIT(usb->TXFIFO1, USB_TXFIFO1_ADDRL)));
}

/**
  * @brief  Set USB TXFIFO2 MAXPKTSIZE
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_8       (0x00)
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_16      (0x01)
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_32      (0x02)
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_64      (0x03)
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_128     (0x04)
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_256     (0x05)
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_512     (0x06)
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_1024    (0x07)
  * @retval None
  */
__STATIC_INLINE void md_usb_set_tx_max_fifo_packet_size(USB_TypeDef *usb, uint8_t MaxPktSize)
{
    MODIFY_REG(usb->TXFIFO2, USB_TXFIFO2_MAXPKTSIZE, MaxPktSize << USB_TXFIFO2_MAXPKTSIZE_POSS);
}

/**
  * @brief  Get USB TXFIFO2 MAXPKTSIZE
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_8       (0x00)
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_16      (0x01)
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_32      (0x02)
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_64      (0x03)
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_128     (0x04)
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_256     (0x05)
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_512     (0x06)
  *         @arg @ref MD_USB_TXFIFO2_MAXPKTSIZE_1024    (0x07)
  */
__STATIC_INLINE uint8_t md_usb_get_tx_max_fifo_packet_size(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->TXFIFO2, USB_TXFIFO2_MAXPKTSIZE) >> USB_TXFIFO2_MAXPKTSIZE_POSS);
}

/**
  * @brief  Enable USB TXFIFO2 DPB
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_tx_double_packet(USB_TypeDef *usb)
{
    SET_BIT(usb->TXFIFO2, USB_TXFIFO2_DPB);
}

/**
  * @brief  Disable USB TXFIFO2 DPB
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_tx_double_packet(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->TXFIFO2, USB_TXFIFO2_DPB);
}

/**
  * @brief  Is USB TXFIFO2 DPB Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_tx_double_packet(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXFIFO2, USB_TXFIFO2_DPB) == (USB_TXFIFO2_DPB));
}

/**
  * @brief  Set USB RXFIFO1 START ADDRESS
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xfff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_rx_fifo_start_addr(USB_TypeDef *usb, uint16_t Addr)
{
    MODIFY_REG(usb->RXFIFO2, USB_RXFIFO2_ADDRH, (uint8_t)(Addr >> 8));
    MODIFY_REG(usb->RXFIFO1, USB_RXFIFO1_ADDRL, (uint8_t)(Addr & 0xff));
}

/**
  * @brief  Get USB RXFIFO1 START ADDRESS
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xfff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint16_t md_usb_get_rx_fifo_start_addr(USB_TypeDef *usb)
{
    return (uint16_t)((READ_BIT(usb->RXFIFO2, USB_RXFIFO2_ADDRH) << 8) | (READ_BIT(usb->RXFIFO1, USB_RXFIFO1_ADDRL)));
}

/**
  * @brief  Set USB RXFIFO2 MAXPKTSIZE
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_8       (0x00)
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_16      (0x01)
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_32      (0x02)
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_64      (0x03)
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_128     (0x04)
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_256     (0x05)
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_512     (0x06)
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_1024    (0x07)
  * @retval None
  */
__STATIC_INLINE void md_usb_set_rx_max_fifo_packet_size(USB_TypeDef *usb, uint8_t MaxPktSize)
{
    MODIFY_REG(usb->RXFIFO2, USB_RXFIFO2_MAXPKTSIZE, MaxPktSize << USB_RXFIFO2_MAXPKTSIZE_POSS);
}

/**
  * @brief  Get USB RXFIFO2 MAXPKTSIZE
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_8       (0x00)
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_16      (0x01)
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_32      (0x02)
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_64      (0x03)
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_128     (0x04)
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_256     (0x05)
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_512     (0x06)
  *         @arg @ref MD_USB_RXFIFO2_MAXPKTSIZE_1024    (0x07)
  */
__STATIC_INLINE uint8_t md_usb_get_rx_max_fifo_packet_size(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->RXFIFO2, USB_RXFIFO2_MAXPKTSIZE) >> USB_RXFIFO2_MAXPKTSIZE_POSS);
}

/**
  * @brief  Enable USB RXFIFO2 DPB
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_rx_double_packet(USB_TypeDef *usb)
{
    SET_BIT(usb->RXFIFO2, USB_RXFIFO2_DPB);
}

/**
  * @brief  Disable USB RXFIFO2 DPB
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disble_rx_double_packet(USB_TypeDef *usb)
{
    CLEAR_BIT(usb->RXFIFO2, USB_RXFIFO2_DPB);
}

/**
  * @brief  Is USB RXFIFO2 DPB Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_rx_double_packet(USB_TypeDef *usb)
{
    return (uint8_t)(READ_BIT(usb->RXFIFO2, USB_RXFIFO2_DPB) == (USB_RXFIFO2_DPB));
}

/**
  * @brief  Set USB EP0FIFO
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_ep0_fifo(USB_TypeDef *usb, uint8_t ep0fifo)
{
    WRITE_REG(usb->EP0FIFO, ep0fifo);
}

/**
  * @brief  Get USB EP0FIFO
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_ep0_fifo(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->EP0FIFO));
}

/**
  * @brief  Set USB EP1FIFO
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_ep1_fifo(USB_TypeDef *usb, uint8_t ep1fifo)
{
    WRITE_REG(usb->EP1FIFO, ep1fifo);
}

/**
  * @brief  Get USB EP1FIFO
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_ep1_fifo(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->EP1FIFO));
}

/**
  * @brief  Set USB EP2FIFO
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_ep2_fifo(USB_TypeDef *usb, uint8_t ep2fifo)
{
    WRITE_REG(usb->EP2FIFO, ep2fifo);
}

/**
  * @brief  Get USB EP2FIFO
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_ep2_fifo(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->EP2FIFO));
}

/**
  * @brief  Set USB EP3FIFO
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_ep3_fifo(USB_TypeDef *usb, uint8_t ep3fifo)
{
    WRITE_REG(usb->EP3FIFO, ep3fifo);
}

/**
  * @brief  Get USB EP3FIFO
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_ep3_fifo(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->EP3FIFO));
}

/**
  * @brief  Set USB EP4FIFO
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_ep4_fifo(USB_TypeDef *usb, uint8_t ep4fifo)
{
    WRITE_REG(usb->EP4FIFO, ep4fifo);
}

/**
  * @brief  Get USB EP4FIFO
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_ep4_fifo(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->EP4FIFO));
}

/**
  * @brief  Set USB EP5FIFO
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_ep5_fifo(USB_TypeDef *usb, uint8_t ep5fifo)
{
    WRITE_REG(usb->EP5FIFO, ep5fifo);
}

/**
  * @brief  Get USB EP5FIFO
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_ep5_fifo(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->EP5FIFO));
}

/**
  * @brief  Set USB EP6FIFO
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_ep6_fifo(USB_TypeDef *usb, uint8_t ep6fifo)
{
    WRITE_REG(usb->EP6FIFO, ep6fifo);
}

/**
  * @brief  Get USB EP6FIFO
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_ep6_fifo(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->EP6FIFO));
}

/**
  * @brief  Set USB TXIER
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0x7f
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_txier(USB_TypeDef *usb, uint8_t txier)
{
    WRITE_REG(usb->TXIER, txier);
}

/**
  * @brief  Enable USB TXIER EP6IE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_ep6_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXIER, USB_TXIER_EP6IE);
}

/**
  * @brief  Enable USB TXIER EP5IE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_ep5_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXIER, USB_TXIER_EP5IE);
}

/**
  * @brief  Enable USB TXIER EP4IE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_ep4_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXIER, USB_TXIER_EP4IE);
}

/**
  * @brief  Enable USB TXIER EP3IE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_ep3_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXIER, USB_TXIER_EP3IE);
}

/**
  * @brief  Enable USB TXIER EP2IE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_ep2_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXIER, USB_TXIER_EP2IE);
}

/**
  * @brief  Enable USB TXIER EP1IE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_ep1_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXIER, USB_TXIER_EP1IE);
}

/**
  * @brief  Enable USB TXIER EP0IE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_ep0(USB_TypeDef *usb)
{
    SET_BIT(usb->TXIER, USB_TXIER_EP0IE);
}

/**
  * @brief  Set USB RXIER
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0x7e
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_rxier(USB_TypeDef *usb, uint8_t rxier)
{
    WRITE_REG(usb->RXIER, rxier);
}

/**
  * @brief  Enable USB RXIER EP6IE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_ep6_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXIER, USB_RXIER_EP6IE);
}

/**
  * @brief  Enable USB RXIER EP5IE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_ep5_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXIER, USB_RXIER_EP5IE);
}

/**
  * @brief  Enable USB RXIER EP4IE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_ep4_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXIER, USB_RXIER_EP4IE);
}

/**
  * @brief  Enable USB RXIER EP3IE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_ep3_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXIER, USB_RXIER_EP3IE);
}

/**
  * @brief  Enable USB RXIER EP2IE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_ep2_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXIER, USB_RXIER_EP2IE);
}

/**
  * @brief  Enable USB RXIER EP1IE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_ep1_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXIER, USB_RXIER_EP1IE);
}

/**
  * @brief  Set USB TXIDR
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0x7f
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_txidr(USB_TypeDef *usb, uint8_t txidr)
{
    WRITE_REG(usb->TXIDR, txidr);
}

/**
  * @brief  Enable USB TXIDR EP6ID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_ep6_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXIDR, USB_TXIDR_EP6ID);
}

/**
  * @brief  Enable USB TXIDR EP5ID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_ep5_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXIDR, USB_TXIDR_EP5ID);
}

/**
  * @brief  Enable USB TXIDR EP4ID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_ep4_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXIDR, USB_TXIDR_EP4ID);
}

/**
  * @brief  Enable USB TXIDR EP3ID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_ep3_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXIDR, USB_TXIDR_EP3ID);
}

/**
  * @brief  Enable USB TXIDR EP2ID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_ep2_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXIDR, USB_TXIDR_EP2ID);
}

/**
  * @brief  Enable USB TXIDR EP1ID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_ep1_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXIDR, USB_TXIDR_EP1ID);
}

/**
  * @brief  Enable USB TXIDR EP0ID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_ep0(USB_TypeDef *usb)
{
    SET_BIT(usb->TXIDR, USB_TXIDR_EP0ID);
}

/**
  * @brief  Set USB RXIDR
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0x7e
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_rxidr(USB_TypeDef *usb, uint8_t rxidr)
{
    WRITE_REG(usb->RXIDR, rxidr);
}

/**
  * @brief  Enable USB RXIDR EP6ID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_ep6_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXIDR, USB_RXIDR_EP6ID);
}

/**
  * @brief  Enable USB RXIDR EP5ID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_ep5_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXIDR, USB_RXIDR_EP5ID);
}

/**
  * @brief  Enable USB RXIDR EP4ID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_ep4_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXIDR, USB_RXIDR_EP4ID);
}

/**
  * @brief  Enable USB RXIDR EP3ID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_ep3_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXIDR, USB_RXIDR_EP3ID);
}

/**
  * @brief  Enable USB RXIDR EP2ID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_ep2_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXIDR, USB_RXIDR_EP2ID);
}

/**
  * @brief  Enable USB RXIDR EP1ID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_ep1_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXIDR, USB_RXIDR_EP1ID);
}

/**
  * @brief  Get USB TXIVS
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x7f
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_txivs(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->TXIVS));
}

/**
  * @brief  Is USB TXIVS EP6IVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_ep6_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXIVS, USB_TXIVS_EP6IVS) == (USB_TXIVS_EP6IVS));
}

/**
  * @brief  Is USB TXIVS EP5IVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_ep5_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXIVS, USB_TXIVS_EP5IVS) == (USB_TXIVS_EP5IVS));
}

/**
  * @brief  Is USB TXIVS EP4IVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_ep4_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXIVS, USB_TXIVS_EP4IVS) == (USB_TXIVS_EP4IVS));
}

/**
  * @brief  Is USB TXIVS EP3IVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_ep3_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXIVS, USB_TXIVS_EP3IVS) == (USB_TXIVS_EP3IVS));
}

/**
  * @brief  Is USB TXIVS EP2IVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_ep2_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXIVS, USB_TXIVS_EP2IVS) == (USB_TXIVS_EP2IVS));
}

/**
  * @brief  Is USB TXIVS EP1IVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_ep1_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXIVS, USB_TXIVS_EP1IVS) == (USB_TXIVS_EP1IVS));
}

/**
  * @brief  Is USB TXIVS EP0IVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_ep0(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXIVS, USB_TXIVS_EP0IVS) == (USB_TXIVS_EP0IVS));
}

/**
  * @brief  Get USB RXIVS
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x7e
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_rxivs(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->RXIVS));
}

/**
  * @brief  Is USB RXIVS EP6IVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_ep6_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXIVS, USB_RXIVS_EP6IVS) == (USB_RXIVS_EP6IVS));
}

/**
  * @brief  Is USB RXIVS EP5IVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_ep5_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXIVS, USB_RXIVS_EP5IVS) == (USB_RXIVS_EP5IVS));
}

/**
  * @brief  Is USB RXIVS EP4IVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_ep4_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXIVS, USB_RXIVS_EP4IVS) == (USB_RXIVS_EP4IVS));
}

/**
  * @brief  Is USB RXIVS EP3IVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_ep3_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXIVS, USB_RXIVS_EP3IVS) == (USB_RXIVS_EP3IVS));
}

/**
  * @brief  Is USB RXIVS EP2IVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_ep2_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXIVS, USB_RXIVS_EP2IVS) == (USB_RXIVS_EP2IVS));
}

/**
  * @brief  Is USB RXIVS EP1IVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_ep1_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXIVS, USB_RXIVS_EP1IVS) == (USB_RXIVS_EP1IVS));
}

/**
  * @brief  Get USB TXRIF
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x7f
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_txrif(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->TXRIF));
}

/**
  * @brief  Is USB TXRIF EP6RIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_ep6_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXRIF, USB_TXRIF_EP6RIF) == (USB_TXRIF_EP6RIF));
}

/**
  * @brief  Is USB TXRIF EP5RIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_ep5_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXRIF, USB_TXRIF_EP5RIF) == (USB_TXRIF_EP5RIF));
}

/**
  * @brief  Is USB TXRIF EP4RIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_ep4_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXRIF, USB_TXRIF_EP4RIF) == (USB_TXRIF_EP4RIF));
}

/**
  * @brief  Is USB TXRIF EP3RIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_ep3_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXRIF, USB_TXRIF_EP3RIF) == (USB_TXRIF_EP3RIF));
}

/**
  * @brief  Is USB TXRIF EP2RIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_ep2_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXRIF, USB_TXRIF_EP2RIF) == (USB_TXRIF_EP2RIF));
}

/**
  * @brief  Is USB TXRIF EP1RIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_ep1_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXRIF, USB_TXRIF_EP1RIF) == (USB_TXRIF_EP1RIF));
}

/**
  * @brief  Is USB TXRIF EP0RIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_ep0(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXRIF, USB_TXRIF_EP0RIF) == (USB_TXRIF_EP0RIF));
}

/**
  * @brief  Get USB RXRIF
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x7e
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_rxrif(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->RXRIF));
}

/**
  * @brief  Is USB RXRIF EP6RIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_ep6_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXRIF, USB_RXRIF_EP6RIF) == (USB_RXRIF_EP6RIF));
}

/**
  * @brief  Is USB RXRIF EP5RIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_ep5_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXRIF, USB_RXRIF_EP5RIF) == (USB_RXRIF_EP5RIF));
}

/**
  * @brief  Is USB RXRIF EP4RIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_ep4_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXRIF, USB_RXRIF_EP4RIF) == (USB_RXRIF_EP4RIF));
}

/**
  * @brief  Is USB RXRIF EP3RIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_ep3_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXRIF, USB_RXRIF_EP3RIF) == (USB_RXRIF_EP3RIF));
}

/**
  * @brief  Is USB RXRIF EP2RIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_ep2_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXRIF, USB_RXRIF_EP2RIF) == (USB_RXRIF_EP2RIF));
}

/**
  * @brief  Is USB RXRIF EP1RIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_ep1_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXRIF, USB_RXRIF_EP1RIF) == (USB_RXRIF_EP1RIF));
}

/**
  * @brief  Get USB TXIFM
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x7f
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_txifm(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->TXIFM));
}

/**
  * @brief  Is USB TXIFM EP6IFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_ep6_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXIFM, USB_TXIFM_EP6IFM) == (USB_TXIFM_EP6IFM));
}

/**
  * @brief  Is USB TXIFM EP5IFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_ep5_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXIFM, USB_TXIFM_EP5IFM) == (USB_TXIFM_EP5IFM));
}

/**
  * @brief  Is USB TXIFM EP4IFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_ep4_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXIFM, USB_TXIFM_EP4IFM) == (USB_TXIFM_EP4IFM));
}

/**
  * @brief  Is USB TXIFM EP3IFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_ep3_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXIFM, USB_TXIFM_EP3IFM) == (USB_TXIFM_EP3IFM));
}

/**
  * @brief  Is USB TXIFM EP2IFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_ep2_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXIFM, USB_TXIFM_EP2IFM) == (USB_TXIFM_EP2IFM));
}

/**
  * @brief  Is USB TXIFM EP1IFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_ep1_tx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXIFM, USB_TXIFM_EP1IFM) == (USB_TXIFM_EP1IFM));
}

/**
  * @brief  Is USB TXIFM EP0IFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_ep0(USB_TypeDef *usb)
{
    return (READ_BIT(usb->TXIFM, USB_TXIFM_EP0IFM) == (USB_TXIFM_EP0IFM));
}

/**
  * @brief  Get USB RXIFM
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x7e
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_rxifm(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->RXIFM));
}

/**
  * @brief  Is USB RXRIF EP6IFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_ep6_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXIFM, USB_RXIFM_EP6IFM) == (USB_RXIFM_EP6IFM));
}

/**
  * @brief  Is USB RXRIF EP5IFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_ep5_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXIFM, USB_RXIFM_EP5IFM) == (USB_RXIFM_EP5IFM));
}

/**
  * @brief  Is USB RXRIF EP4IFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_ep4_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXIFM, USB_RXIFM_EP4IFM) == (USB_RXIFM_EP4IFM));
}

/**
  * @brief  Is USB RXRIF EP3IFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_ep3_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXIFM, USB_RXIFM_EP3IFM) == (USB_RXIFM_EP3IFM));
}

/**
  * @brief  Is USB RXRIF EP2IFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_ep2_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXIFM, USB_RXIFM_EP2IFM) == (USB_RXIFM_EP2IFM));
}

/**
  * @brief  Is USB RXRIF EP1IFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_ep1_rx(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RXIFM, USB_RXIFM_EP1IFM) == (USB_RXIFM_EP1IFM));
}

/**
  * @brief  Set USB TXICR
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0x7f
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_txicr(USB_TypeDef *usb, uint8_t txicr)
{
    WRITE_REG(usb->TXICR, txicr);
}

/**
  * @brief  Enable USB TXICR EP6ICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_ep6_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXICR, USB_TXICR_EP6ICR);
}

/**
  * @brief  Enable USB TXICR EP5ICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_ep5_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXICR, USB_TXICR_EP5ICR);
}

/**
  * @brief  Enable USB TXICR EP4ICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_ep4_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXICR, USB_TXICR_EP4ICR);
}

/**
  * @brief  Enable USB TXICR EP3ICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_ep3_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXICR, USB_TXICR_EP3ICR);
}

/**
  * @brief  Enable USB TXICR EP2ICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_ep2_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXICR, USB_TXICR_EP6ICR);
}

/**
  * @brief  Enable USB TXICR EP1ICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_ep1_tx(USB_TypeDef *usb)
{
    SET_BIT(usb->TXICR, USB_TXICR_EP1ICR);
}

/**
  * @brief  Enable USB TXICR EP0ICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_ep0(USB_TypeDef *usb)
{
    SET_BIT(usb->TXICR, USB_TXICR_EP0ICR);
}

/**
  * @brief  Set USB RXICR
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0x7e
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_rxicr(USB_TypeDef *usb, uint8_t U8)
{
    WRITE_REG(usb->RXICR, U8);
}

/**
  * @brief  Enable USB RXICR EP6ICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_ep6_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXICR, USB_RXICR_EP6ICR);
}

/**
  * @brief  Enable USB RXICR EP5ICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_ep5_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXICR, USB_RXICR_EP5ICR);
}

/**
  * @brief  Enable USB RXICR EP4ICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_ep4_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXICR, USB_RXICR_EP4ICR);
}

/**
  * @brief  Enable USB RXICR EP3ICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_ep3_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXICR, USB_RXICR_EP3ICR);
}

/**
  * @brief  Enable USB RXICR EP2ICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_ep2_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXICR, USB_RXICR_EP2ICR);
}

/**
  * @brief  Enable USB RXICR EP1ICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_ep1_rx(USB_TypeDef *usb)
{
    SET_BIT(usb->RXICR, USB_RXICR_EP1ICR);
}

/**
  * @brief  Set USB IER
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0x7e
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_ier(USB_TypeDef *usb, uint8_t ier)
{
    WRITE_REG(usb->IER, ier);
}

/**
  * @brief  Enable USB IER SESREQIE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_session_request(USB_TypeDef *usb)
{
    SET_BIT(usb->IER, USB_IER_SESREQIE);
}

/**
  * @brief  Enable USB IER DISCONIE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_disconnect(USB_TypeDef *usb)
{
    SET_BIT(usb->IER, USB_IER_DISCONIE);
}

/**
  * @brief  Enable USB IER CONIE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_connection(USB_TypeDef *usb)
{
    SET_BIT(usb->IER, USB_IER_CONIE);
}

/**
  * @brief  Enable USB IER SOFIE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_sof(USB_TypeDef *usb)
{
    SET_BIT(usb->IER, USB_IER_SOFIE);
}

/**
  * @brief  Enable USB IER BABIE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_babble(USB_TypeDef *usb)
{
    SET_BIT(usb->IER, USB_IER_BABIE);
}

/**
  * @brief  Enable USB IER RESIE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_resume(USB_TypeDef *usb)
{
    SET_BIT(usb->IER, USB_IER_RESIE);
}

/**
  * @brief  Enable USB IER RESTIE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_reset(USB_TypeDef *usb)
{
    SET_BIT(usb->IER, USB_IER_RESTIE);
}

/**
  * @brief  Enable USB IER SUSPDIE
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_enable_it_suspend(USB_TypeDef *usb)
{
    SET_BIT(usb->IER, USB_IER_SUSPDIE);
}

/**
  * @brief  Set USB IDR
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0x7e
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_idr(USB_TypeDef *usb, uint8_t idr)
{
    WRITE_REG(usb->IDR, idr);
}

/**
  * @brief  Enable USB IDR SESREQID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_session_request(USB_TypeDef *usb)
{
    SET_BIT(usb->IDR, USB_IDR_SESREQID);
}

/**
  * @brief  Enable USB IDR DISCONID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_disconnect(USB_TypeDef *usb)
{
    SET_BIT(usb->IDR, USB_IDR_DISCONID);
}

/**
  * @brief  Enable USB IDR CONID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_connection(USB_TypeDef *usb)
{
    SET_BIT(usb->IDR, USB_IDR_CONID);
}

/**
  * @brief  Enable USB IDR SOFID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_sof(USB_TypeDef *usb)
{
    SET_BIT(usb->IDR, USB_IDR_SOFID);
}

/**
  * @brief  Enable USB IDR BABID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_babble(USB_TypeDef *usb)
{
    SET_BIT(usb->IDR, USB_IDR_BABID);
}

/**
  * @brief  Enable USB IDR RESID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_resume(USB_TypeDef *usb)
{
    SET_BIT(usb->IDR, USB_IDR_RESID);
}

/**
  * @brief  Enable USB IDR RESTID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_reset(USB_TypeDef *usb)
{
    SET_BIT(usb->IDR, USB_IDR_RESTID);
}

/**
  * @brief  Enable USB IDR SUSPDID
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_disable_it_suspend(USB_TypeDef *usb)
{
    SET_BIT(usb->IDR, USB_IDR_SUSPDID);
}

/**
  * @brief  Get USB IVS
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x7e
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_ivs(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->IVS));
}

/**
  * @brief  Is USB IVS SESREQIVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_session_request(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IVS, USB_IVS_SESREQIVS) == (USB_IVS_SESREQIVS));
}

/**
  * @brief  Is USB IVS DISCONIVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_disconnect(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IVS, USB_IVS_DISCONIVS) == (USB_IVS_DISCONIVS));
}

/**
  * @brief  Is USB IVS CONIVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_connection(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IVS, USB_IVS_CONIVS) == (USB_IVS_CONIVS));
}

/**
  * @brief  Is USB IVS SOFIVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_sof(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IVS, USB_IVS_SOFIVS) == (USB_IVS_SOFIVS));
}

/**
  * @brief  Is USB IVS BABIVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_babble(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IVS, USB_IVS_BABIVS) == (USB_IVS_BABIVS));
}

/**
  * @brief  Is USB IVS RESIVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_resume(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IVS, USB_IVS_RESIVS) == (USB_IVS_RESIVS));
}

/**
  * @brief  Is USB IVS RESTIVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_reset(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IVS, USB_IVS_RESTIVS) == (USB_IVS_RESTIVS));
}

/**
  * @brief  Is USB IVS SUSPDIVS Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_enabled_it_suspend(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IVS, USB_IVS_SUSPDIVS) == (USB_IVS_SUSPDIVS));
}

/**
  * @brief  Get USB RIF
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x7e
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_rif(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->RIF));
}

/**
  * @brief  Is USB RIF SESREQRIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_session_request(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RIF, USB_RIF_SESREQRIF) == (USB_RIF_SESREQRIF));
}

/**
  * @brief  Is USB RIF DISCONRIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_disconnect(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RIF, USB_RIF_DISCONRIF) == (USB_RIF_DISCONRIF));
}

/**
  * @brief  Is USB RIF CONRIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_connection(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RIF, USB_RIF_CONRIF) == (USB_RIF_CONRIF));
}

/**
  * @brief  Is USB RIF SOFRIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_sof(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RIF, USB_RIF_SOFRIF) == (USB_RIF_SOFRIF));
}

/**
  * @brief  Is USB RIF BABRIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_babble(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RIF, USB_RIF_BABRIF) == (USB_RIF_BABRIF));
}

/**
  * @brief  Is USB RIF RESRIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_resume(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RIF, USB_RIF_RESRIF) == (USB_RIF_RESRIF));
}

/**
  * @brief  Is USB RIF RESTRIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_reset(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RIF, USB_RIF_RESTRIF) == (USB_RIF_RESTRIF));
}

/**
  * @brief  Is USB RIF SUSPDRIF Active
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Active
  *         @arg 0x0 : Not active
  */
__STATIC_INLINE uint8_t md_usb_is_active_it_suspend(USB_TypeDef *usb)
{
    return (READ_BIT(usb->RIF, USB_RIF_SUSPDRIF) == (USB_RIF_SUSPDRIF));
}

/**
  * @brief  Get USB IFM
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x7e
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_usb_get_ifm(USB_TypeDef *usb)
{
    return (uint8_t)(READ_REG(usb->IFM));
}

/**
  * @brief  Is USB IFM SESREQIFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_session_request(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IFM, USB_IFM_SESREQIFM) == (USB_IFM_SESREQIFM));
}

/**
  * @brief  Is USB IFM DISCONIFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_disconnect(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IFM, USB_IFM_DISCONIFM) == (USB_IFM_DISCONIFM));
}

/**
  * @brief  Is USB IFM CONIFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_connection(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IFM, USB_IFM_CONIFM) == (USB_IFM_CONIFM));
}

/**
  * @brief  Is USB IFM SOFIFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_sof(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IFM, USB_IFM_SOFIFM) == (USB_IFM_SOFIFM));
}

/**
  * @brief  Is USB IFM BABIFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_babble(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IFM, USB_IFM_BABIFM) == (USB_IFM_BABIFM));
}

/**
  * @brief  Is USB IFM RESIFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_resume(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IFM, USB_IFM_RESIFM) == (USB_IFM_RESIFM));
}

/**
  * @brief  Is USB IFM RESTIFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_reset(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IFM, USB_IFM_RESTIFM) == (USB_IFM_RESTIFM));
}

/**
  * @brief  Is USB IFM SUSPDIFM Enabled
  * @param  usb USB Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint8_t md_usb_is_masked_it_suspend(USB_TypeDef *usb)
{
    return (READ_BIT(usb->IFM, USB_IFM_SUSPDIFM) == (USB_IFM_SUSPDIFM));
}

/**
  * @brief  Set USB ICR
  * @param  usb USB Instance
  * @param  The param can be one of the following values:
  *         @arg Max Value 0x7e
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_usb_set_icr(USB_TypeDef *usb, uint8_t icr)
{
    WRITE_REG(usb->ICR, icr);
}

/**
  * @brief  Enable USB ICR SESREQICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_session_request(USB_TypeDef *usb)
{
    SET_BIT(usb->ICR, USB_ICR_SESREQICR);
}

/**
  * @brief  Enable USB ICR DISCONICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_disconnect(USB_TypeDef *usb)
{
    SET_BIT(usb->ICR, USB_ICR_DISCONICR);
}

/**
  * @brief  Enable USB ICR CONICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_connection(USB_TypeDef *usb)
{
    SET_BIT(usb->ICR, USB_ICR_CONICR);
}

/**
  * @brief  Enable USB ICR SOFICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_sof(USB_TypeDef *usb)
{
    SET_BIT(usb->ICR, USB_ICR_SOFICR);
}

/**
  * @brief  Enable USB ICR BABICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_babble(USB_TypeDef *usb)
{
    SET_BIT(usb->ICR, USB_ICR_BABICR);
}

/**
  * @brief  Enable USB ICR RESICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_resume(USB_TypeDef *usb)
{
    SET_BIT(usb->ICR, USB_ICR_RESICR);
}

/**
  * @brief  Enable USB ICR RESTICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_reset(USB_TypeDef *usb)
{
    SET_BIT(usb->ICR, USB_ICR_RESTICR);
}

/**
  * @brief  Enable USB ICR SUSPDICR
  * @param  usb USB Instance
  * @retval None
  */
__STATIC_INLINE void md_usb_clear_it_suspend(USB_TypeDef *usb)
{
    SET_BIT(usb->ICR, USB_ICR_SUSPDICR);
}

/**
  * @} MD_USB_Macro_Drivers
  */

/**
  * @} MD_USB_Public_Macros
  */

/* Public functions -----------------------------------------------------------*/
/** @defgroup MD_USB_Public_Functions USB Public Functions
  * @{
  */

/**
  * @}  MD_USB_Public_Functions
  */

#endif

/**
  * @}  USB
  */

/**
  * @}  Micro_Driver
  */

#ifdef __cplusplus
}
#endif

#endif

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/


