/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

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
 * @file    GPIOv3/hal_pal_lld.h
 * @brief   SN32 PAL low level driver header.
 *
 * @addtogroup PAL
 * @{
 */

#ifndef HAL_PAL_LLD_H
#define HAL_PAL_LLD_H

#if HAL_USE_PAL || defined(__DOXYGEN__)

/*===========================================================================*/
/* Unsupported modes and specific modes                                      */
/*===========================================================================*/

// /* Specifies palInit() without parameter, required until all platforms will
//    be updated to the new style.*/
// // #define PAL_NEW_INIT


/* Discarded definitions from the ST headers, the PAL driver uses its own
   definitions in order to have an unified handling for all devices.
   Unfortunately the ST headers have no uniform definitions for the same
   objects across the various sub-families.*/
#undef GPIOA
#undef GPIOB
#undef GPIOC
#undef GPIOD


/*===========================================================================*/
/* I/O Ports Types and constants.                                            */
/*===========================================================================*/

/**
 * @name    GPIO ports definitions
 * @{
 */
#define GPIOA                         ((SN_GPIO0_Type *)SN_GPIO0_BASE)// SN_GPIO0//
#define GPIOB                         ((SN_GPIO0_Type *)SN_GPIO1_BASE)// SN_GPIO1//
#define GPIOC                         ((SN_GPIO0_Type *)SN_GPIO2_BASE)// SN_GPIO2//
#define GPIOD                         ((SN_GPIO0_Type *)SN_GPIO3_BASE)// SN_GPIO3//

/** @} */

/**
 * @name    Port related definitions
 * @{
 */
#define TOTAL_PORTS       4U
/**
 * @brief   Width, in bits, of an I/O port.
 */
#define PAL_IOPORTS_WIDTH 16U

/**
 * @brief   Whole port mask.
 * @details This macro specifies all the valid bits into a port.
 */
#define PAL_WHOLE_PORT ((ioportmask_t)0xFFFF)
/** @} */

/**
 * @name    Standard I/O mode flags
 * @{
 */
#undef PAL_MODE_RESET
#undef PAL_MODE_UNCONNECTED

/**
 * @brief   Implemented as input.
 */
#define PAL_MODE_RESET                  PAL_MODE_INPUT

/**
 * @brief   Implemented as input with DATA keep low.
 */
#define PAL_MODE_UNCONNECTED            PAL_MODE_INPUT_ANALOG

/**
 * @name    Line handling macros
 * @{
 */
/**
 * @brief   Forms a line identifier.
 * @details A port/pad pair are encoded into an @p ioline_t type. The encoding
 *          of this type is platform-dependent.
 * @note    In this driver the pad number is encoded in the lower 4 bits of
 *          the GPIO address which are guaranteed to be zero.
 */
#define PAL_LINE(port, pad)                                                 \
  ((ioline_t)((uint32_t)(port)) | ((uint32_t)(pad)))

/**
 * @brief   Decodes a port identifier from a line identifier.
 */
#define PAL_PORT(line)                                                      \
  ((SN_GPIO0_Type *)(((uint32_t)(line)) & 0xFFFFFFF0U))

/**
 * @brief   Decodes a pad identifier from a line identifier.
 */
#define PAL_PAD(line)                                                       \
  ((uint32_t)((uint32_t)(line) & 0x0000000FU))

/**
 * @brief   Value identifying an invalid line.
 */
#define PAL_NOLINE                      0U
/** @} */

/**
 * @brief   GPIO port setup info.
 */
typedef struct {
  /** Initial value for DATA register.*/
  uint32_t              data;
  /** Initial value for MODE register.*/
  uint32_t              mode;
  /** Initial value for CFG register.*/
  uint32_t              cfg;
  /** Initial value for IS register.*/
  uint32_t              is;
  /** Initial value for IBS register.*/
  uint32_t              ibs;
  /** Initial value for IEV register.*/
  uint32_t              iev;
  /** Initial value for IE register.*/
  uint32_t              ie;
  /** Initial value for RIS register.*/
  uint32_t              ris;
  /** Initial value for IC register.*/
  uint32_t              ic;
  /** Initial value for BSET register.*/
  uint32_t              bset;
  /** Initial value for BCLR register.*/
  uint32_t              bclr;
} sn32_gpio_setup_t;

/**
 * @brief   SN32 GPIO static initializer.
 * @details An instance of this structure must be passed to @p palInit() at
 *          system startup time in order to initialize the digital I/O
 *          subsystem. This represents only the initial setup, specific pads
 *          or whole ports can be reprogrammed at later time.
 */
typedef struct {
#if SN32_HAS_GPIOA || defined(__DOXYGEN__)
  /** @brief Port A setup data.*/
  sn32_gpio_setup_t    PAData;
#endif
#if SN32_HAS_GPIOB || defined(__DOXYGEN__)
  /** @brief Port B setup data.*/
  sn32_gpio_setup_t    PBData;
#endif
#if SN32_HAS_GPIOC || defined(__DOXYGEN__)
  /** @brief Port C setup data.*/
  sn32_gpio_setup_t    PCData;
#endif
#if SN32_HAS_GPIOD || defined(__DOXYGEN__)
  /** @brief Port D setup data.*/
  sn32_gpio_setup_t    PDData;
#endif
} PALConfig;

/**
 * @brief   Type of digital I/O port sized unsigned integer.
 */
typedef uint32_t ioportmask_t;

/**
 * @brief   Type of digital I/O modes.
 */
typedef uint32_t iomode_t;

/**
 * @brief   Type of an I/O line.
 */
typedef uint32_t ioline_t;

/**
 * @brief   Port Identifier.
 * @details This type can be a scalar or some kind of pointer, do not make
 *          any assumption about it, use the provided macros when populating
 *          variables of this type.
 */
typedef SN_GPIO0_Type * ioportid_t;

/**
 * @brief   Type of an pad identifier.
 */
typedef uint32_t iopadid_t;

/*===========================================================================*/
/* I/O Ports Identifiers.                                                    */
/* The low level driver wraps the definitions already present in the SN32   */
/* firmware library.                                                         */
/*===========================================================================*/

/**
 * @brief   GPIO port A identifier.
 */
#if SN32_HAS_GPIOA || defined(__DOXYGEN__)
#define IOPORT1         GPIOA
#endif

/**
 * @brief   GPIO port B identifier.
 */
#if SN32_HAS_GPIOB || defined(__DOXYGEN__)
#define IOPORT2         GPIOB
#endif

/**
 * @brief   GPIO port C identifier.
 */
#if SN32_HAS_GPIOC || defined(__DOXYGEN__)
#define IOPORT3         GPIOC
#endif

/**
 * @brief   GPIO port D identifier.
 */
#if SN32_HAS_GPIOD || defined(__DOXYGEN__)
#define IOPORT4         GPIOD
#endif

/**
 * @brief   GPIO port A interrupt priority level setting.
 */
#if !defined(SN32_GPIOA_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SN32_GPIOA_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIO port B interrupt priority level setting.
 */
#if !defined(SN32_GPIOB_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SN32_GPIOB_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIO port A interrupt priority level setting.
 */
#if !defined(SN32_GPIOC_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SN32_GPIOC_IRQ_PRIORITY         3
#endif

/**
 * @brief   GPIO port A interrupt priority level setting.
 */
#if !defined(SN32_GPIOD_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SN32_GPIOD_IRQ_PRIORITY         3
#endif

/*===========================================================================*/
/* Implementation, some of the following macros could be implemented as      */
/* functions, if so please put them in pal_lld.c.                            */
/*===========================================================================*/

/**
 * @brief   Low level PAL subsystem initialization.
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
#define pal_lld_readport(port) ((port)->DATA)

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
// #define pal_lld_readlatch(port) ((port)->RIS)

/**
 * @brief   Writes a bits mask on a I/O port.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be written on the specified port
 *
 * @notapi
 */
#define pal_lld_writeport(port, bits) ((port)->DATA = (uint16_t)(bits))

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
#define pal_lld_setport(port, bits) ((port)->BSET = (uint16_t)(bits))

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
#define pal_lld_clearport(port, bits) ((port)->BCLR = ~(uint16_t)(bits))

/**
 * @brief   Writes a group of bits.
 * @details This function is implemented by writing the GPIO BSET register, the
 *          implementation has no side effects.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    the group bit offset within the port
 * @param[in] bits      bits to be written. Values exceeding the group
 *                      width are masked.
 *
 * @notapi
 */
#define pal_lld_writegroup(port, mask, offset, bits) {                      \
  uint32_t w = ((~(uint32_t)(bits) & (uint32_t)(mask)) << (16U + (offset))) | \
               ((uint32_t)(bits) & (uint32_t)(mask)) << (offset);           \
  (port)->DATA = w;                                                       \
}

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
#define pal_lld_readpad(port, pad) (((port)->DATA >> pad) & 1)

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
#define pal_lld_writepad(port, pad, bit) do {    \
    if(bit > PAL_LOW) pal_lld_setpad(port, pad); \
    else pal_lld_clearpad(port, pad);            \
} while(0)

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
#define pal_lld_setpad(port, pad) ((port)->BSET = (0x1 << pad))

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
#define pal_lld_clearpad(port, pad) ((port)->BCLR = (0x1 << pad))

/**
 * @brief   Toggles a pad logical state.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */
// #define pal_lld_togglepad(port, pad)

/**
 * @brief   Pad mode setup.
 * @details This function programs a pad with the specified mode.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 * @note    Programming an unknown or unsupported mode is silently ignored.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 * @param[in] mode      pad mode
 *
 * @notapi
 */
// #define pal_lld_setpadmode(port, pad, mode) ((port)->MODE |= mode << pad)

#define pal_lld_setpadmode(port, pad, mode)                      \
  _pal_lld_setpadmode(port, pad, mode)


/**
 * @brief   Returns a PAL event structure associated to a pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */
#define pal_lld_get_pad_event(port, pad)                                \
  _pal_lld_get_pad_event(port, pad)

/**
 * @brief   Returns a PAL event structure associated to a line.
 *
 * @param[in] line      line identifier
 *
 * @notapi
 */
#define pal_lld_get_line_event(line)                                        \
  pal_lld_get_pad_event(PAL_PORT(line), PAL_PAD(line))

/**
 * @brief   Pad event enable.
 * @note    Programming an unknown or unsupported mode is silently ignored.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 * @param[in] mode      pad event mode
 *
 * @notapi
 */
#define pal_lld_enablepadevent(port, pad, mode)                             \
  _pal_lld_enablepadevent(port, pad, mode)

/**
 * @brief   Pad event disable.
 * @details This function disables previously programmed event callbacks.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */
#define pal_lld_disablepadevent(port, pad)                                  \
  _pal_lld_disablepadevent(port, pad)

/**
 * @brief   Pad event enable check.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 * @return              Pad event status.
 * @retval false        if the pad event is disabled.
 * @retval true         if the pad event is enabled.
 *
 * @notapi
 */
#define pal_lld_ispadeventenabled(port, pad)                                \
  _pal_lld_ispadeventenabled(port, pad)

#if !defined(__DOXYGEN__)
extern const PALConfig pal_default_config;
#if (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE)
extern palevent_t _pal_events[TOTAL_PORTS * PAL_IOPORTS_WIDTH];
#endif /* (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE) */
#endif

#ifdef __cplusplus
extern "C" {
#endif
  extern const PALConfig pal_default_config;
  void _pal_lld_init(const PALConfig *config);
  void _pal_lld_setpadmode(ioportid_t port,
                             iopadid_t pad,
                             iomode_t mode);
#if (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE)
  palevent_t* _pal_lld_get_pad_event(ioportid_t port,
                                      iopadid_t pad);
  void _pal_lld_enablepadevent(ioportid_t port,
                                iopadid_t pad,
                                iomode_t mode);
  void _pal_lld_disablepadevent(ioportid_t port,
                                iopadid_t pad);
  bool _pal_lld_ispadeventenabled(ioportid_t port,
                                  iopadid_t pad);
#endif /* (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE) */
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_PAL */

#endif /* HAL_PAL_LLD_H */

/** @} */
