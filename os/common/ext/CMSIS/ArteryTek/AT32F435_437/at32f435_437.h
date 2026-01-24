/**
  **************************************************************************
  * @file     at32f435_437.h
  * @author  Artery Technology & HorrorTroll & Zhaqian & Maxjta
  * @brief    at32f435_437 header file
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup AT32F435_437
  * @{
  */

#ifndef __AT32F435_437_H
#define __AT32F435_437_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined (__CC_ARM)
 #pragma anon_unions
#endif

/** @addtogroup Library_configuration_section
  * @{
  */

#ifndef USE_STDPERIPH_DRIVER
/**
  * @brief comment the line below if you will not use the peripherals drivers.
  * in this case, these drivers will not be included and the application code will
  * be based on direct access to peripherals registers
  */
  #ifdef _RTE_
    #include "RTE_Components.h"
    #ifdef RTE_DEVICE_STDPERIPH_FRAMEWORK
      #define USE_STDPERIPH_DRIVER
    #endif
  #endif
#endif

/** @addtogroup Device_Included
  * @{
  */
#if defined(AT32F435CC) || defined(AT32F435CG) ||                           \
    defined(AT32F435CM)
#include "at32f435_437cx.h"
#elif defined(AT32F435RC) || defined(AT32F435RG) ||                          \
      defined(AT32F435RM) || defined(AT32F437RC) ||                          \
      defined(AT32F437RG) || defined(AT32F437RM)
#include "at32f435_437rx.h"
#elif defined(AT32F435VC) || defined(AT32F435VG) ||                          \
      defined(AT32F435VM) || defined(AT32F437VC) ||                          \
      defined(AT32F437VG) || defined(AT32F437VM)
#include "at32f435_437vx.h"
#elif defined(AT32F435ZC) || defined(AT32F435ZG) ||                          \
      defined(AT32F435ZM) || defined(AT32F437ZC) ||                          \
      defined(AT32F437ZG) || defined(AT32F437ZM)
#include "at32f435_437zx.h"
#else
   #error "Please select first the target AT32F435_437 device used in your application (in at32f402_405.h file)"
#endif

/**
  * @}
  */

/** @addtogroup Exported_types
  * @{
  */

  typedef int32_t  INT32;
  typedef int16_t  INT16;
  typedef int8_t   INT8;
  typedef uint32_t UINT32;
  typedef uint16_t UINT16;
  typedef uint8_t  UINT8;
  
  typedef int32_t  s32;
  typedef int16_t  s16;
  typedef int8_t   s8;
  
  typedef const int32_t sc32;   /*!< read only */
  typedef const int16_t sc16;   /*!< read only */
  typedef const int8_t  sc8;    /*!< read only */
  
  typedef __IO int32_t  vs32;
  typedef __IO int16_t  vs16;
  typedef __IO int8_t   vs8;
  
  typedef __I int32_t vsc32;    /*!< read only */
  typedef __I int16_t vsc16;    /*!< read only */
  typedef __I int8_t  vsc8;     /*!< read only */
  
  typedef uint32_t u32;
  typedef uint16_t u16;
  typedef uint8_t  u8;
  
  typedef const uint32_t uc32;  /*!< read only */
  typedef const uint16_t uc16;  /*!< read only */
  typedef const uint8_t  uc8;   /*!< read only */
  
  typedef __IO uint32_t vu32;
  typedef __IO uint16_t vu16;
  typedef __IO uint8_t  vu8;
  
  typedef __I uint32_t vuc32;   /*!< read only */
  typedef __I uint16_t vuc16;   /*!< read only */
  typedef __I uint8_t  vuc8;    /*!< read only */
  
  /**
    * @brief flag status
    */
  typedef enum {RESET = 0, SET = !RESET} flag_status;
  
  /**
    * @brief confirm state
    */
  typedef enum {DISABLE = 0, ENABLE = !DISABLE} confirm_state;
  
  /**
    * @brief error status
    */
  typedef enum {ERROR = 0, SUCCESS = !ERROR} error_status;
  
  /**
    * @}
    */

/** @addtogroup Exported_macros
  * @{
  */

  #define REG8(addr)                       *(volatile uint8_t *)(addr)
  #define REG16(addr)                      *(volatile uint16_t *)(addr)
  #define REG32(addr)                      *(volatile uint32_t *)(addr)
  
  #define MAKE_VALUE(reg_offset, bit_num)  (uint32_t)(((reg_offset) << 16) | (bit_num & 0x1F))
  
  #define PERIPH_REG(periph_base, value)   REG32((periph_base + (value >> 16)))
  #define PERIPH_REG_BIT(value)            (0x1U << (value & 0x1F))
  
  /**
    * @}
    */  
 
  /**
    * @}
    */ 

#ifdef __cplusplus
}
#endif

#endif
/**
  * @}
  */

/**
  * @}
  */
 /*********************** (C) COPYRIGHT Artery Technology *****END OF FILE****/
