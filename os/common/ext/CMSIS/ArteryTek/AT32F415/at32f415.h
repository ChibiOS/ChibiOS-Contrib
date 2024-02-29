/**
  ******************************************************************************
  * @file    at32f415.h
  * @author  Artery Technology & HorrorTroll & Zhaqian
  * @brief   AT32F415 header file
  *
  ******************************************************************************
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

/** @addtogroup at32f415
  * @{
  */
    
#ifndef __AT32F415_H
#define __AT32F415_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

#if defined (__CC_ARM)
 #pragma anon_unions
#endif

/** @addtogroup Library_configuration_section
  * @{
  */

/**
  * @brief AT32 Family
  */
#if !defined (AT32F415)
#define AT32F415
#endif /* AT32F415 */

/* Uncomment the line below according to the target AT32 device used in your
   application 
  */

#if !defined(AT32F415KB) && !defined(AT32F415KC) && !defined(AT32F415CB) && \
    !defined(AT32F415CC) && !defined(AT32F415RB) && !defined(AT32F415RC)
   /* #define AT32F415KB */     /*!< AT32F415K8 and AT32F415KB */
   /* #define AT32F415KC */     /*!< AT32F415KC */
   /* #define AT32F415CB */     /*!< AT32F415C8 and AT32F415CB */
   /* #define AT32F415CC */     /*!< AT32F415CC */
   /* #define AT32F415RB */     /*!< AT32F415R8 and AT32F415RB */
   /* #define AT32F415RC */     /*!< AT32F415RC */
#endif

/*  Tip: To avoid modifying this file each time you need to switch between these
        devices, you can define the device in your toolchain compiler preprocessor.
  */
  
#ifndef USE_STDPERIPH_DRIVER
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
   In this case, these drivers will not be included and the application code will 
   be based on direct access to peripherals registers 
   */
   #ifdef _RTE_
       #include "RTE_Components.h"
       #ifdef RTE_DEVICE_STDPERIPH_FRAMEWORK
           #define USE_STDPERIPH_DRIVER
       #endif
   #endif
#endif /* USE_STDPERIPH_DRIVER */

/** @addtogroup Device_Included
  * @{
  */

#if defined(AT32F415KB)
   #include "at32f415kx.h"
#elif defined(AT32F415KC)
   #include "at32f415kx.h"
#elif defined(AT32F415CB)
   #include "at32f415cx.h"
#elif defined(AT32F415CC)
   #include "at32f415cx.h"
#elif defined(AT32F415RB)
   #include "at32f415rx.h"
#elif defined(AT32F415RC)
   #include "at32f415rx.h"
#else
   #error "Please select first the target AT32F415 device used in your application (in at32f415.h file)"
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

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __AT32F415_H */

/**
  * @}
  */

/**
  * @}
  */

/*********************** (C) COPYRIGHT Artery Technology *****END OF FILE****/
