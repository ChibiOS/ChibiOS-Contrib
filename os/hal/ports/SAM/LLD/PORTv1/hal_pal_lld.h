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
 * @file    hal_pal_lld.h
 * @brief   PLATFORM PAL subsystem low level driver header.
 *
 * @addtogroup PAL
 * @{
 */

#ifndef HAL_PAL_LLD_H
#define HAL_PAL_LLD_H
// #include "cmparams.h"
#if (HAL_USE_PAL == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Unsupported modes and specific modes                                      */
/*===========================================================================*/

/* Specifies palInit() without parameter, required until all platforms will
   be updated to the new style.*/
// #define PAL_SAM_MODE_MASK             (3U << 0U)
// #define PAL_SAM_MODE_INPUT            (0U << 0U)
// #define PAL_SAM_MODE_OUTPUT           (1U << 0U)
// #define PAL_SAM_MODE_ALTERNATE        (2U << 0U)
// #define PAL_SAM_MODE_ANALOG           (3U << 0U)

// #define PAL_SAM_OTYPE_MASK            (1U << 2U)
// #define PAL_SAM_OTYPE_PUSHPULL        (0U << 2U)
// #define PAL_SAM_OTYPE_OPENDRAIN       (1U << 2U)

// #define PAL_SAM_OSPEED_MASK           (3U << 3U)
// #define PAL_SAM_OSPEED_LOWEST         (0U << 3U)
// #define PAL_SAM_OSPEED_HIGHEST        (3U << 3U)

// #define PAL_SAM_PUPDR_MASK            (3U << 5U)
// #define PAL_SAM_PUPDR_FLOATING        (0U << 5U)
// #define PAL_SAM_PUPDR_PULLUP          (1U << 5U)
// #define PAL_SAM_PUPDR_PULLDOWN        (2U << 5U)

// #define PAL_SAM_ALTERNATE_MASK        (15U << 7U)
// #define PAL_SAM_ALTERNATE(n)          ((n) << 7U)

#define PAL_SAM_PMUXEN_MASK               (1U << 0U)
#define PAL_SAM_PMUXEN_PMUX               (1U << 0U)
#define PAL_SAM_PMUXEN_IO                 (0U << 0U)

#define PAL_SAM_INEN_MASK                 (1U << 1U)
#define PAL_SAM_INEN_ENABLE               (1U << 1U)
#define PAL_SAM_INEN_DISABLE              (0U << 1U)

#define PAL_SAM_PULLEN_MASK               (1U << 2U)
#define PAL_SAM_PULLEN_ENABLE             (1U << 2U)
#define PAL_SAM_PULLEN_DISABLE            (0U << 2U)

#define PAL_SAM_DRVSTR_MASK               (1U << 3U)
#define PAL_SAM_DRVSTR_NORMAL             (0U << 3U)
#define PAL_SAM_DRVSTR_STRONGER           (1U << 3U)

#define PAL_SAM_DIR_MASK                  (1U << 4U)
#define PAL_SAM_DIR_OUT                   (1U << 4U)
#define PAL_SAM_DIR_IN                    (0U << 4U)

#define PAL_SAM_OUT_MASK                  (1U << 5U)
#define PAL_SAM_OUT_ENABLE                (1U << 5U)
#define PAL_SAM_OUT_DISABLE               (0U << 5U)

#define PAL_SAM_ALTERNATE_MASK            (7U  << 6U)
#define PAL_SAM_ALTERNATE(n)              ((n) << 6U)

#define PAL_NEW_INIT
#undef PAL_MODE_RESET
#undef PAL_MODE_UNCONNECTED
#undef PAL_MODE_INPUT
#undef PAL_MODE_INPUT_PULLUP
#undef PAL_MODE_INPUT_PULLDOWN
#undef PAL_MODE_INPUT_ANALOG
#undef PAL_MODE_OUTPUT_PUSHPULL
#undef PAL_MODE_OUTPUT_OPENDRAIN
// PORT RESET MODE

#define PAL_SAM_RESET                    (PAL_SAM_PMUXEN_IO | PAL_SAM_INEN_DISABLE | \
                                           PAL_SAM_PULLEN_DISABLE | PAL_SAM_DIR_IN)


/* PORT INPUT MODE: FLOAT, PULLUP, PULLDOWN pg 368 */

#define PAL_MODE_INPUT                    (PAL_SAM_PMUXEN_IO | PAL_SAM_INEN_ENABLE | \
                                           PAL_SAM_PULLEN_DISABLE | PAL_SAM_DIR_IN)

#define PAL_MODE_INPUT_PULLUP             (PAL_SAM_PMUXEN_IO | PAL_SAM_INEN_ENABLE | \
                                           PAL_SAM_PULLEN_ENABLE | PAL_SAM_DIR_IN | \
                                           PAL_SAM_OUT_ENABLE)

#define PAL_MODE_INPUT_PULLDOWN           (PAL_SAM_PMUXEN_IO | PAL_SAM_INEN_ENABLE | \
                                           PAL_SAM_PULLEN_ENABLE | PAL_SAM_DIR_IN | \
                                           PAL_SAM_OUT_DISABLE)  


/* PORT OUTPUT MODE pg 369 */

#define PAL_MODE_OUTPUT_OPENDRAIN         (PAL_SAM_PMUXEN_IO | PAL_SAM_INEN_DISABLE | \
                                           PAL_SAM_PULLEN_ENABLE | PAL_SAM_DIR_OUT)

#define PAL_MODE_OUTPUT_INBUFF            (PAL_SAM_PMUXEN_IO | PAL_SAM_INEN_ENABLE | \
                                           PAL_SAM_PULLEN_DISABLE | PAL_SAM_DIR_OUT | \
                                           PAL_SAM_OUT_ENABLE)

#define PAL_MODE_OUTPUT_PUSHPULL          (PAL_SAM_PMUXEN_IO | PAL_SAM_INEN_DISABLE | \
                                           PAL_SAM_PULLEN_DISABLE | PAL_SAM_DIR_OUT)

// PORT ALTERNATE MODE

#define PAL_MODE_ALTERNATE(n)             (PAL_SAM_PMUXEN_PMUX | PAL_SAM_ALTERNATE(n))


// PORT ANALOG MODE

#define PAL_MODE_ANALOG                   (PAL_SAM_RESET | PAL_MODE_ALTERNATE(1))
#define PAL_SAM_FUNC_A                    0
#define PAL_SAM_FUNC_B                    1
#define PAL_SAM_FUNC_C                    2
#define PAL_SAM_FUNC_D                    3
#define PAL_SAM_FUNC_E                    4
#define PAL_SAM_FUNC_F                    5
#define PAL_SAM_FUNC_G                    6
#define PAL_SAM_FUNC_H                    7
/*===========================================================================*/
/* I/O Ports Types and constants.                                            */
/*===========================================================================*/

/**
 * @name    Port related definitions
 * @{
 */
/**
 * @brief   Width, in bits, of an I/O port.
 */
#define PAL_IOPORTS_WIDTH           32U

/**
 * @brief   Whole port mask.
 * @details This macro specifies all the valid bits into a port.
 */
#define PAL_WHOLE_PORT              ((ioportmask_t)0xFFFFU)
/** @} */

/**
 * @name    Line handling macros
 * @{
 */
/**
 * @brief   Forms a line identifier.
 * @details A port/pad pair are encoded into an @p ioline_t type. The encoding
 *          of this type is platform-dependent.
 */
#define PAL_LINE(port, pad)                                                 \
  ((ioline_t)((uint32_t)(port)) | ((uint32_t)(pad)))

/**
 * @brief   Decodes a port identifier from a line identifier.
 */
#define PAL_PORT(line)                                                      \
  ((ioportid_t)(((uint32_t)(line)) & 0xFFFFFF80U))

/**
 * @brief   Decodes a pad identifier from a line identifier.
 */
#define PAL_PAD(line)                                                       \
  ((uint32_t)((uint32_t)(line) & 0x0000001FU))

/**
 * @brief   Value identifying an invalid line.
 */
#define PAL_NOLINE                      0U
/** @} */

/**
 * @brief   Generic I/O ports static initializer.
 * @details An instance of this structure must be passed to @p palInit() at
 *          system startup time in order to initialized the digital I/O
 *          subsystem. This represents only the initial setup, specific pads
 *          or whole ports can be reprogrammed at later time.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
typedef struct {

} PALConfig;

/**
 * @brief   Digital I/O port sized unsigned type.
 */
typedef uint32_t ioportmask_t;

/**
 * @brief   Digital I/O modes.
 */
typedef uint32_t iomode_t;

/**
 * @brief   Type of an I/O line.
 */
typedef uint32_t ioline_t;

/**
 * @brief   Type of an event mode.
 */
typedef uint8_t ioeventmode_t;

/**
 * @brief   Port Identifier.
 * @details This type can be a scalar or some kind of pointer, do not make
 *          any assumption about it, use the provided macros when populating
 *          variables of this type.
 */
typedef port_group_registers_t* ioportid_t;

/**
 * @brief   Type of an pad identifier.
 */
typedef uint8_t iopadid_t;

/*===========================================================================*/
/* I/O Ports Identifiers.                                                    */
/*===========================================================================*/

/**
 * @brief   First I/O port identifier.
 * @details Low level drivers can define multiple ports, it is suggested to
 *          use this naming convention.
 */
 
#if defined(SAM_HAS_GPIOA) || defined(__DOXYGEN__)
#define GPIOA			      &PORT_REGS->GROUP[0]
#define IOPORT1         &PORT_REGS->GROUP[0]
#endif

/**
 * @brief   GPIO port B identifier.
 */
#if defined(SAM_HAS_GPIOA) || defined(__DOXYGEN__)
#define GPIOB			      &PORT_REGS->GROUP[1]
#define IOPORT2         &PORT_REGS->GROUP[1]
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
#define pal_lld_init() _pal_lld_init()

/**
 * @brief   Reads the physical I/O port states.
 *
 * @param[in] port      port identifier
 * @return              The port bits.
 *
 * @notapi
 */
#define pal_lld_readport(port) ((ioportmask_t)(port)->PORT_IN)

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
#define pal_lld_readlatch(port) ((ioportmask_t)(port)->PORT_OUT)

/**
 * @brief   Writes a bits mask on a I/O port.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be written on the specified port
 *
 * @notapi
 */
#define pal_lld_writeport(port, bits) ((port)->PORT_OUT = bits)

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
#define pal_lld_setport(port, bits) ((port)->PORT_OUTSET = bits)

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
#define pal_lld_clearport(port, bits) ((port)->PORT_OUTCLR = bits)

/**
 * @brief   Toggles a bits mask on a I/O port.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be XORed on the specified port
 *
 * @notapi
 */
#define pal_lld_toggleport(port, bits) ((port)->PORT_OUTTGL = bits)
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
#define pal_lld_readgroup(port, mask, offset) ((port)->PORT_IN >> offset)

#define pal_lld_writegroup(port, mask, offset, bits) \
        _pal_lld_writegroup(port, mask, offset, bits)

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
#define pal_lld_setpad(port, pad) ((port)->PORT_OUTSET = (1 << pad))

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
#define pal_lld_clearpad(port, pad) ((port)->PORT_OUTCLR = (1 << pad))                                         

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
#define pal_lld_togglepad(port, pad) ((port)->PORT_OUTTGL = (1 << pad))   

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
 * @brief   Returns a PAL event structure associated to a pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */
#define pal_lld_get_pad_event(port, pad)                                    \
  _pal_lld_get_pad_event(port, pad)

/**
 * @brief   Returns a PAL event structure associated to a line.
 *
 * @param[in] line      line identifier
 *
 * @notapi
 */
#define pal_lld_get_line_event(line)                                        \
  _pal_lld_get_line_event(line)

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
#if (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE)
extern palevent_t _pal_events[16];
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void _pal_lld_init(void);
  void _pal_lld_setgroupmode(ioportid_t port,
                             ioportmask_t mask,
                             iomode_t mode);
  void _pal_lld_writegroup(ioportid_t port, 
                          ioportmask_t mask, 
                          uint32_t offset, 
                          uint32_t bits);
  void _pal_lld_enablepadevent(ioportid_t port,
                               iopadid_t pad,
                               ioeventmode_t mode);
  void _pal_lld_disablepadevent(ioportid_t port,
                                iopadid_t pad);
  bool _pal_lld_ispadeventenabled(ioportid_t port, iopadid_t pad);
  palevent_t* _pal_lld_get_line_event(ioline_t line);
  palevent_t* _pal_lld_get_pad_event(ioportid_t port, 
                                    iopadid_t pad);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_PAL == TRUE */

#endif /* HAL_PAL_LLD_H */

/** @} */
