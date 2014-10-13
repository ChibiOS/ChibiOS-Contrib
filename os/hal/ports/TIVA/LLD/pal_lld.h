/*
    Copyright (C) 2014 Marco Veeneman

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
 * @file    TIVA/LLD/pal_lld.h
 * @brief   TM4C123x/TM4C129x PAL subsystem low level driver header.
 *
 * @addtogroup PAL
 * @{
 */

#ifndef _PAL_LLD_H_
#define _PAL_LLD_H_

#if HAL_USE_PAL || defined(__DOXYGEN__)

/*===========================================================================*/
/* Unsupported modes and specific modes                                      */
/*===========================================================================*/

/*===========================================================================*/
/* I/O Ports Types and constants.                                            */
/*===========================================================================*/

/**	
 * @brief   GPIO port setup info.
 */
typedef struct 
{
  /** @brief Initial value for DATA register.*/
  uint32_t data;
  /** @brief Initial value for DIR register.*/
  uint32_t dir;
  /** @brief Initial value for AFSEL register.*/
  uint32_t afsel;
  /** @brief Initial value for DR2R register.*/
  uint32_t dr2r;
  /** @brief Initial value for DR4R register.*/
  uint32_t dr4r;
  /** @brief Initial value for DR8R register.*/
  uint32_t dr8r;
  /** @brief Initial value for ODR register.*/
  uint32_t odr;
  /** @brief Initial value for PUR register.*/
  uint32_t pur;
  /** @brief Initial value for PDR register.*/
  uint32_t pdr;
  /** @brief Initial value for SLR register.*/
  uint32_t slr;
  /** @brief Initial value for DEN register.*/
  uint32_t den;
  /** @brief Initial value for AMSEL register.*/
  uint32_t amsel;
  /** @brief Initial value for PCTL register.*/
  uint32_t pctl;
} tiva_gpio_setup_t;

/**
 * @brief   Tiva GPIO static initializer.
 * @details An instance of this structure must be passed to @p palInit() at
 *          system startup time in order to initialized the digital I/O
 *          subsystem. This represents only the initial setup, specific pads
 *          or whole ports can be reprogrammed at later time.
 */
typedef struct
{
  /** @brief Port A setup data.*/
  tiva_gpio_setup_t     PAData;
  /** @brief Port B setup data.*/
  tiva_gpio_setup_t     PBData;
  /** @brief Port C setup data.*/
  tiva_gpio_setup_t     PCData;
  /** @brief Port D setup data.*/
  tiva_gpio_setup_t     PDData;
  /** @brief Port E setup data.*/
  tiva_gpio_setup_t     PEData;
  /** @brief Port F setup data.*/
  tiva_gpio_setup_t     PFData;

#if TIVA_HAS_GPIOG || defined(__DOXYGEN__)
  /** @brief Port G setup data.*/
  tiva_gpio_setup_t     PGData;
#endif /* TIVA_HAS_GPIOG.*/

#if TIVA_HAS_GPIOH || defined(__DOXYGEN__)
  /** @brief Port H setup data.*/
  tiva_gpio_setup_t     PHData;
#endif /* TIVA_HAS_GPIOH.*/

#if TIVA_HAS_GPIOJ || defined(__DOXYGEN__)
  /** @brief Port J setup data.*/
  tiva_gpio_setup_t     PJData;
#endif /* TIVA_HAS_GPIOJ.*/

#if TIVA_HAS_GPIOK || defined(__DOXYGEN__)
  /** @brief Port K setup data.*/
  tiva_gpio_setup_t     PKData;
#endif /* TIVA_HAS_GPIOK.*/

#if TIVA_HAS_GPIOL || defined(__DOXYGEN__)
  /** @brief Port L setup data.*/
  tiva_gpio_setup_t     PLData;
#endif /* TIVA_HAS_GPIOL.*/

#if TIVA_HAS_GPIOM || defined(__DOXYGEN__)
  /** @brief Port M setup data.*/
  tiva_gpio_setup_t     PMData;
#endif /* TIVA_HAS_GPIOM.*/

#if TIVA_HAS_GPION || defined(__DOXYGEN__)
  /** @brief Port N setup data.*/
  tiva_gpio_setup_t     PNData;
#endif /* TIVA_HAS_GPION.*/

#if TIVA_HAS_GPIOP || defined(__DOXYGEN__)
  /** @brief Port P setup data.*/
  tiva_gpio_setup_t     PPData;
#endif /* TIVA_HAS_GPIOP.*/

#if TIVA_HAS_GPIOQ || defined(__DOXYGEN__)
  /** @brief Port Q setup data.*/
  tiva_gpio_setup_t     PQData;
#endif /* TIVA_HAS_GPIOQ.*/

#if TIVA_HAS_GPIOR || defined(__DOXYGEN__)
  /** @brief Port R setup data.*/
  tiva_gpio_setup_t     PRData;
#endif /* TIVA_HAS_GPIOR.*/

#if TIVA_HAS_GPIOS || defined(__DOXYGEN__)
  /** @brief Port S setup data.*/
  tiva_gpio_setup_t     PSData;
#endif /* TIVA_HAS_GPIOS.*/

#if TIVA_HAS_GPIOT || defined(__DOXYGEN__)
  /** @brief Port T setup data.*/
  tiva_gpio_setup_t     PTData;
#endif /* TIVA_HAS_GPIOT.*/
} PALConfig;

/**
 * @brief   Width, in bits, of an I/O port.
 */
#define PAL_IOPORTS_WIDTH 8

/**
 * @brief   Whole port mask.
 * @brief   This macro specifies all the valid bits into a port.
 */
#define PAL_WHOLE_PORT ((ioportmask_t)0xFF)

/**
 * @brief   Digital I/O port sized unsigned type.
 */
typedef uint32_t ioportmask_t;

/**
 * @brief   Digital I/O modes.
 */
typedef uint32_t iomode_t;

/**
 * @brief   Port Identifier.
 */
typedef GPIO_TypeDef *ioportid_t;

/*===========================================================================*/
/* I/O Ports Identifiers.                                                    */
/*===========================================================================*/

/** @brief   GPIOA port identifier.*/
#define IOPORT1         GPIOA

/** @brief   GPIOB port identifier.*/
#define IOPORT2         GPIOB

/** @brief   GPIOC port identifier.*/
#define IOPORT3         GPIOC

/** @brief   GPIOD port identifier.*/
#define IOPORT4         GPIOD

/** @brief   GPIOE port identifier.*/
#define IOPORT5         GPIOE

/** @brief   GPIOF port identifier.*/
#define IOPORT6         GPIOF

#if TIVA_HAS_GPIOG || defined(__DOXYGEN__)
/** @brief Port G setup data.*/
#define IOPORT7         GPIOG
#endif /* TIVA_HAS_GPIOG.*/

#if TIVA_HAS_GPIOH || defined(__DOXYGEN__)
/** @brief Port H setup data.*/
#define IOPORT8         GPIOH
#endif /* TIVA_HAS_GPIOH.*/

#if TIVA_HAS_GPIOJ || defined(__DOXYGEN__)
/** @brief Port J setup data.*/
#define IOPORT9         GPIOJ
#endif /* TIVA_HAS_GPIOJ.*/

#if TIVA_HAS_GPIOK || defined(__DOXYGEN__)
/** @brief Port K setup data.*/
#define IOPORT10        GPIOK
#endif /* TIVA_HAS_GPIOK.*/

#if TIVA_HAS_GPIOL || defined(__DOXYGEN__)
/** @brief Port L setup data.*/
#define IOPORT11        GPIOL
#endif /* TIVA_HAS_GPIOL.*/

#if TIVA_HAS_GPIOM || defined(__DOXYGEN__)
/** @brief Port M setup data.*/
#define IOPORT12        GPIOM
#endif /* TIVA_HAS_GPIOM.*/

#if TIVA_HAS_GPION || defined(__DOXYGEN__)
/** @brief Port N setup data.*/
#define IOPORT13        GPION
#endif /* TIVA_HAS_GPION.*/

#if TIVA_HAS_GPIOP || defined(__DOXYGEN__)
/** @brief Port P setup data.*/
#define IOPORT14        GPIOP
#endif /* TIVA_HAS_GPIOP.*/

#if TIVA_HAS_GPIOQ || defined(__DOXYGEN__)
/** @brief Port Q setup data.*/
#define IOPORT15        GPIOQ
#endif /* TIVA_HAS_GPIOQ.*/

#if TIVA_HAS_GPIOR || defined(__DOXYGEN__)
/** @brief Port R setup data.*/
#define IOPORT16        GPIOR
#endif /* TIVA_HAS_GPIOR.*/

#if TIVA_HAS_GPIOS || defined(__DOXYGEN__)
/** @brief Port S setup data.*/
#define IOPORT17        GPIOS
#endif /* TIVA_HAS_GPIOS.*/

#if TIVA_HAS_GPIOT || defined(__DOXYGEN__)
/** @brief Port T setup data.*/
#define IOPORT18        GPIOT
#endif /* TIVA_HAS_GPIOT.*/

/*===========================================================================*/
/* Implementation, some of the following macros could be implemented as      */
/* functions, if so please put them in pal_lld.c.                            */
/*===========================================================================*/

/**
 * @brief   Low level PAL subsystem initialization.
 *
 * @param[in] config    architecture-dependent ports configuration
 *
 * @notapi
 */
#define pal_lld_init(config) _pal_lld_init(config)

/**
 * @brief   Reads the physical I/O port states.
 *
 * @param[in] port      port identifier
 * @return              The port bits.
 *
 * @notapi
 */
#define pal_lld_readport(port)  ((port)->DATA)

/**
 * @brief   Reads the output latch.
 * @details The purpose of this function is to read back the latched output
 *          value.
 *
 * @param[in] port      port identifier
 * @return              The latched logical states.
 *
 * @notapi
 */
#define pal_lld_readlatch(port) ((port)->DATA)

/**
 * @brief   Writes a bits mask on a I/O port.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be written on the specified port
 *
 * @notapi
 */
#define pal_lld_writeport(port, bits)   ((port)->DATA = (bits))

/**
 * @brief   Sets a bits mask on a I/O port.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be ORed on the specified port
 *
 * @notapi
 */
#define pal_lld_setport(port, bits) ((port)->MASKED_ACCESS[bits] = 0xFF)

/**
 * @brief   Clears a bits mask on a I/O port.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be cleared on the specified port
 *
 * @notapi
 */
#define pal_lld_clearport(port, bits)   ((port)->MASKED_ACCESS[bits] = 0)

/**
 * @brief   Reads a group of bits.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    group bit offset within the port
 * @return              The group logical states.
 *
 * @notapi
 */
#define pal_lld_readgroup(port, mask, offset)   \
  ((port)->MASKED_ACCESS[(mask) << (offset)])

/**
 * @brief   Writes a group of bits.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    group bit offset within the port
 * @param[in] bits      bits to be written. Values exceeding the group width
 *                      are masked.
 *
 * @notapi
 */
#define pal_lld_writegroup(port, mask, offset, bits)    \
  ((port)->MASKED_ACCESS[(mask) << (offset)] = (bits))

/**
 * @brief   Pads group mode setup.
 * @details This function programs a pads group belonging to the same port
 *          with the specified mode.
 * @note    Programming an unknown or unsupported mode is silently ignored.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    group bit offset within the port
 * @param[in] mode      group mode
 *
 * @notapi
 */
#define pal_lld_setgroupmode(port, mask, offset, mode)                      \
  _pal_lld_setgroupmode(port, mask << offset, mode)

/**
 * @brief   Reads a logical state from an I/O pad.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 * @return              The logical state.
 * @retval PAL_LOW      low logical state.
 * @retval PAL_HIGH     high logical state.
 *
 * @notapi
 */
#define pal_lld_readpad(port, pad) ((port)->MASKED_ACCESS[1 << (pad)])

/**
 * @brief   Writes a logical state on an output pad.
 * @note    This function is not meant to be invoked directly by the
 *          application  code.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 * @param[in] bit       logical value, the value must be @p PAL_LOW or
 *                      @p PAL_HIGH
 *
 * @notapi
 */
#define pal_lld_writepad(port, pad, bit)    \
  ((port)->MASKED_ACCESS[1 << (pad)] = (bit))

/**
 * @brief   Sets a pad logical state to @p PAL_HIGH.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */
#define pal_lld_setpad(port, pad)   \
  ((port)->MASKED_ACCESS[1 << (pad)] = 1 << (pad))

/**
 * @brief   Clears a pad logical state to @p PAL_LOW.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */
#define pal_lld_clearpad(port, pad) \
  ((port)->MASKED_ACCESS[1 << (pad)] = 0)

#if !defined(__DOXYGEN__)
extern const PALConfig pal_default_config;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void _pal_lld_init(const PALConfig *config);
  void _pal_lld_setgroupmode(ioportid_t port,
                             ioportmask_t mask,
                             iomode_t mode);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_PAL */

#endif /* _PAL_LLD_H_ */

/**
 * @}
 */
