/*
    Copyright (C) 2019 /u/KeepItUnder
    Modifications copyright (C) 2026 Belonit

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
 * @file    M251/hal_pal_lld.h
 * @brief   M251/M252 PAL subsystem low level driver header.
 *
 * @addtogroup PAL
 * @{
 */

#ifndef HAL_PAL_LLD_H
#define HAL_PAL_LLD_H

#if (HAL_USE_PAL == TRUE) || defined(__DOXYGEN__)

#include "M251/stddriver/gpio.h"

/**
 * @brief   Enables the new-style PAL initialization.
 */
#define PAL_NEW_INIT

#undef PAL_MODE_RESET
#undef PAL_MODE_UNCONNECTED
#undef PAL_MODE_INPUT
#undef PAL_MODE_INPUT_PULLUP
#undef PAL_MODE_INPUT_PULLDOWN
#undef PAL_MODE_INPUT_ANALOG
#undef PAL_MODE_OUTPUT_PUSHPULL
#undef PAL_MODE_OUTPUT_OPENDRAIN

/**
 * @name    M251 GPIO mode encodings
 * @{
 */
/** @brief Mask of the M251 GPIO mode field.*/
#define PAL_M251_MODE_MASK                0x03U
/** @brief Input mode.*/
#define PAL_M251_MODE_INPUT               GPIO_MODE_INPUT
/** @brief Push-pull output mode.*/
#define PAL_M251_MODE_OUTPUT              GPIO_MODE_OUTPUT
/** @brief Open-drain output mode.*/
#define PAL_M251_MODE_OPENDRAIN           GPIO_MODE_OPEN_DRAIN
/** @brief Quasi-bidirectional mode.*/
#define PAL_M251_MODE_QUASI               GPIO_MODE_QUASI
/** @}*/

/**
 * @brief   Encodes one pad mode for a direct GPIOx_MODE register update.
 *
 * @param[in] pad       pad number
 * @param[in] mode      M251 GPIO mode
 * @return              Encoded two-bit GPIOx_MODE field.
 */
#define PAL_M251_PAD_MODE(pad, mode)       \
  ((uint32_t)(mode) << ((uint32_t)(pad) * 2U))

/**
 * @brief   Returns the GPIOx_MODE mask for a pad.
 *
 * @param[in] pad       pad number
 * @return              Encoded GPIOx_MODE mask.
 */
#define PAL_M251_PAD_MODE_MASK(pad)        \
  PAL_M251_PAD_MODE(pad, PAL_M251_MODE_MASK)

/**
 * @brief   Returns the input GPIOx_MODE field for a pad.
 *
 * @param[in] pad       pad number
 * @return              Encoded GPIOx_MODE field.
 */
#define PAL_M251_PAD_MODE_INPUT(pad)       \
  PAL_M251_PAD_MODE(pad, PAL_M251_MODE_INPUT)

/**
 * @brief   Returns the output GPIOx_MODE field for a pad.
 *
 * @param[in] pad       pad number
 * @return              Encoded GPIOx_MODE field.
 */
#define PAL_M251_PAD_MODE_OUTPUT(pad)      \
  PAL_M251_PAD_MODE(pad, PAL_M251_MODE_OUTPUT)

/**
 * @brief   Returns the open-drain GPIOx_MODE field for a pad.
 *
 * @param[in] pad       pad number
 * @return              Encoded GPIOx_MODE field.
 */
#define PAL_M251_PAD_MODE_OPENDRAIN(pad)   \
  PAL_M251_PAD_MODE(pad, PAL_M251_MODE_OPENDRAIN)

/**
 * @brief   Returns the quasi-bidirectional GPIOx_MODE field for a pad.
 *
 * @param[in] pad       pad number
 * @return              Encoded GPIOx_MODE field.
 */
#define PAL_M251_PAD_MODE_QUASI(pad)       \
  PAL_M251_PAD_MODE(pad, PAL_M251_MODE_QUASI)

/*
 * Compile-time helpers for direct GPIO register updates. Each public macro
 * accepts one to sixteen integer constant pad numbers in the range 0..15.
 * An out-of-range pad causes a compile-time error.
 */
#define PAL_M251_PRIVATE_PP_CAT_(a, b) a##b
#define PAL_M251_PRIVATE_PP_CAT(a, b) PAL_M251_PRIVATE_PP_CAT_(a, b)
#define PAL_M251_PRIVATE_PP_NARG_(p1, p2, p3, p4, p5, p6, p7, p8,        \
                                  p9, p10, p11, p12, p13, p14, p15, p16, \
                                  n, ...) n

#define PAL_M251_PRIVATE_PP_NARG(...)                                    \
  PAL_M251_PRIVATE_PP_NARG_(__VA_ARGS__, 16, 15, 14, 13, 12, 11, 10, 9,  \
                            8, 7, 6, 5, 4, 3, 2, 1, 0)

#define PAL_M251_PRIVATE_MAP_OR_1(fn, p1) fn(p1)
#define PAL_M251_PRIVATE_MAP_OR_2(fn, p1, ...) \
  (fn(p1) | PAL_M251_PRIVATE_MAP_OR_1(fn, __VA_ARGS__))
#define PAL_M251_PRIVATE_MAP_OR_3(fn, p1, ...) \
  (fn(p1) | PAL_M251_PRIVATE_MAP_OR_2(fn, __VA_ARGS__))
#define PAL_M251_PRIVATE_MAP_OR_4(fn, p1, ...) \
  (fn(p1) | PAL_M251_PRIVATE_MAP_OR_3(fn, __VA_ARGS__))
#define PAL_M251_PRIVATE_MAP_OR_5(fn, p1, ...) \
  (fn(p1) | PAL_M251_PRIVATE_MAP_OR_4(fn, __VA_ARGS__))
#define PAL_M251_PRIVATE_MAP_OR_6(fn, p1, ...) \
  (fn(p1) | PAL_M251_PRIVATE_MAP_OR_5(fn, __VA_ARGS__))
#define PAL_M251_PRIVATE_MAP_OR_7(fn, p1, ...) \
  (fn(p1) | PAL_M251_PRIVATE_MAP_OR_6(fn, __VA_ARGS__))
#define PAL_M251_PRIVATE_MAP_OR_8(fn, p1, ...) \
  (fn(p1) | PAL_M251_PRIVATE_MAP_OR_7(fn, __VA_ARGS__))
#define PAL_M251_PRIVATE_MAP_OR_9(fn, p1, ...) \
  (fn(p1) | PAL_M251_PRIVATE_MAP_OR_8(fn, __VA_ARGS__))
#define PAL_M251_PRIVATE_MAP_OR_10(fn, p1, ...) \
  (fn(p1) | PAL_M251_PRIVATE_MAP_OR_9(fn, __VA_ARGS__))
#define PAL_M251_PRIVATE_MAP_OR_11(fn, p1, ...) \
  (fn(p1) | PAL_M251_PRIVATE_MAP_OR_10(fn, __VA_ARGS__))
#define PAL_M251_PRIVATE_MAP_OR_12(fn, p1, ...) \
  (fn(p1) | PAL_M251_PRIVATE_MAP_OR_11(fn, __VA_ARGS__))
#define PAL_M251_PRIVATE_MAP_OR_13(fn, p1, ...) \
  (fn(p1) | PAL_M251_PRIVATE_MAP_OR_12(fn, __VA_ARGS__))
#define PAL_M251_PRIVATE_MAP_OR_14(fn, p1, ...) \
  (fn(p1) | PAL_M251_PRIVATE_MAP_OR_13(fn, __VA_ARGS__))
#define PAL_M251_PRIVATE_MAP_OR_15(fn, p1, ...) \
  (fn(p1) | PAL_M251_PRIVATE_MAP_OR_14(fn, __VA_ARGS__))
#define PAL_M251_PRIVATE_MAP_OR_16(fn, p1, ...) \
  (fn(p1) | PAL_M251_PRIVATE_MAP_OR_15(fn, __VA_ARGS__))

#define PAL_M251_PRIVATE_MAP_OR(fn, ...)                         \
  PAL_M251_PRIVATE_PP_CAT(PAL_M251_PRIVATE_MAP_OR_,              \
                          PAL_M251_PRIVATE_PP_NARG(__VA_ARGS__)) \
  (fn, __VA_ARGS__)

#define PAL_M251_PRIVATE_CHECK_PAD(pad)                                          \
  (0U * sizeof(char[((pad) >= 0 && (pad) < PAL_IOPORTS_WIDTH) ? 1 : -1]))
#define PAL_M251_PRIVATE_VALID_PAD(pad) ((uint32_t)(pad) % PAL_IOPORTS_WIDTH)
#define PAL_M251_PRIVATE_PIN_MASK_ONE(pad)                                       \
  ((ioportmask_t)(PAL_M251_PRIVATE_CHECK_PAD(pad)                                \
                  + PAL_PORT_BIT(PAL_M251_PRIVATE_VALID_PAD(pad))))
#define PAL_M251_PRIVATE_MODE_FIELD_MASK_ONE(pad)                                \
  ((uint32_t)(PAL_M251_PRIVATE_CHECK_PAD(pad)                                    \
              + PAL_M251_PAD_MODE_MASK(PAL_M251_PRIVATE_VALID_PAD(pad))))
#define PAL_M251_PRIVATE_MODE_FIELD_INPUT_ONE(pad)                               \
  ((uint32_t)(PAL_M251_PRIVATE_CHECK_PAD(pad)                                    \
              + PAL_M251_PAD_MODE_INPUT(PAL_M251_PRIVATE_VALID_PAD(pad))))
#define PAL_M251_PRIVATE_MODE_FIELD_OUTPUT_ONE(pad)                              \
  ((uint32_t)(PAL_M251_PRIVATE_CHECK_PAD(pad)                                    \
              + PAL_M251_PAD_MODE_OUTPUT(PAL_M251_PRIVATE_VALID_PAD(pad))))
#define PAL_M251_PRIVATE_MODE_FIELD_OPENDRAIN_ONE(pad)                           \
  ((uint32_t)(PAL_M251_PRIVATE_CHECK_PAD(pad)                                    \
              + PAL_M251_PAD_MODE_OPENDRAIN(PAL_M251_PRIVATE_VALID_PAD(pad))))
#define PAL_M251_PRIVATE_MODE_FIELD_QUASI_ONE(pad)                               \
  ((uint32_t)(PAL_M251_PRIVATE_CHECK_PAD(pad)                                    \
              + PAL_M251_PAD_MODE_QUASI(PAL_M251_PRIVATE_VALID_PAD(pad))))

/**
 * @brief   Builds a mask from one to sixteen pad numbers.
 * @details Every pad number must be an integer constant in the range 0..15.
 *
 * @param[in] ...       pad numbers
 * @return              Port bit mask.
 */
#define PAL_M251_PIN_MASK(...)                                                  \
  PAL_M251_PRIVATE_MAP_OR(PAL_M251_PRIVATE_PIN_MASK_ONE, __VA_ARGS__)

/**
 * @brief   Builds a GPIOx_MODE mask from one to sixteen pad numbers.
 *
 * @param[in] ...       pad numbers
 * @return              GPIOx_MODE field mask.
 */
#define PAL_M251_MODE_FIELD_MASK(...)                                           \
  PAL_M251_PRIVATE_MAP_OR(PAL_M251_PRIVATE_MODE_FIELD_MASK_ONE, __VA_ARGS__)

/**
 * @brief   Builds input-mode fields for one to sixteen pad numbers.
 *
 * @param[in] ...       pad numbers
 * @return              GPIOx_MODE fields.
 */
#define PAL_M251_MODE_FIELD_INPUT(...)                                          \
  PAL_M251_PRIVATE_MAP_OR(PAL_M251_PRIVATE_MODE_FIELD_INPUT_ONE, __VA_ARGS__)

/**
 * @brief   Builds output-mode fields for one to sixteen pad numbers.
 *
 * @param[in] ...       pad numbers
 * @return              GPIOx_MODE fields.
 */
#define PAL_M251_MODE_FIELD_OUTPUT(...)                                         \
  PAL_M251_PRIVATE_MAP_OR(PAL_M251_PRIVATE_MODE_FIELD_OUTPUT_ONE, __VA_ARGS__)

/**
 * @brief   Builds open-drain fields for one to sixteen pad numbers.
 *
 * @param[in] ...       pad numbers
 * @return              GPIOx_MODE fields.
 */
#define PAL_M251_MODE_FIELD_OPENDRAIN(...)                                      \
  PAL_M251_PRIVATE_MAP_OR(PAL_M251_PRIVATE_MODE_FIELD_OPENDRAIN_ONE,            \
                          __VA_ARGS__)

/**
 * @brief   Builds quasi-bidirectional fields for one to sixteen pad numbers.
 *
 * @param[in] ...       pad numbers
 * @return              GPIOx_MODE fields.
 */
#define PAL_M251_MODE_FIELD_QUASI(...)                    \
  PAL_M251_PRIVATE_MAP_OR(PAL_M251_PRIVATE_MODE_FIELD_QUASI_ONE, __VA_ARGS__)

/**
 * @name    M251 GPIO mode flags
 * @{
 */
/** @brief Mask of the pull resistor selection field.*/
#define PAL_M251_PULL_MASK                (0x03U << 2U)
/** @brief Pull resistors disabled.*/
#define PAL_M251_PULL_DISABLE             (GPIO_PUSEL_DISABLE << 2U)
/** @brief Pull-up resistor enabled.*/
#define PAL_M251_PULL_UP                  (GPIO_PUSEL_PULL_UP << 2U)
/** @brief Pull-down resistor enabled.*/
#define PAL_M251_PULL_DOWN                (GPIO_PUSEL_PULL_DOWN << 2U)

/** @brief Digital input path disabled.*/
#define PAL_M251_DINOFF                   (1U << 4U)
/** @brief Preserves an already configured peripheral MFP route.*/
#define PAL_M251_MFP_PRESERVE             (1U << 5U)
/** @}*/

/**
 * @name    Standard PAL modes
 * @{
 */
/** @brief Default reset mode.*/
#define PAL_MODE_RESET                    (PAL_M251_MODE_INPUT |           \
                                           PAL_M251_PULL_DISABLE)
/** @brief Recommended mode for unconnected pads.*/
#define PAL_MODE_UNCONNECTED              PAL_MODE_INPUT_PULLUP
/** @brief Floating input mode.*/
#define PAL_MODE_INPUT                    (PAL_M251_MODE_INPUT |           \
                                           PAL_M251_PULL_DISABLE)
/** @brief Input mode with pull-up resistor.*/
#define PAL_MODE_INPUT_PULLUP             (PAL_M251_MODE_INPUT |           \
                                           PAL_M251_PULL_UP)
/** @brief Input mode with pull-down resistor.*/
#define PAL_MODE_INPUT_PULLDOWN           (PAL_M251_MODE_INPUT |           \
                                           PAL_M251_PULL_DOWN)
/** @brief Analog input mode with the digital path disabled.*/
#define PAL_MODE_INPUT_ANALOG             (PAL_M251_MODE_INPUT |           \
                                           PAL_M251_PULL_DISABLE |         \
                                           PAL_M251_DINOFF)
/** @brief Push-pull output mode.*/
#define PAL_MODE_OUTPUT_PUSHPULL          (PAL_M251_MODE_OUTPUT |          \
                                           PAL_M251_PULL_DISABLE)
/** @brief Open-drain output mode.*/
#define PAL_MODE_OUTPUT_OPENDRAIN         (PAL_M251_MODE_OPENDRAIN |       \
                                           PAL_M251_PULL_DISABLE)
/** @}*/

/** @brief Number of pads in an I/O port.*/
#define PAL_IOPORTS_WIDTH                 16U
/** @brief Mask selecting a whole I/O port.*/
#define PAL_WHOLE_PORT                    ((ioportmask_t)0xFFFFU)

/**
 * @brief   Builds a line identifier from a port and pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number
 * @return              Line identifier.
 */
#define PAL_LINE(port, pad)                                                   \
  ((ioline_t)((uint32_t)(port)) | ((uint32_t)(pad)))

/**
 * @brief   Extracts the port identifier from a line.
 *
 * @param[in] line      line identifier
 * @return              Port identifier.
 */
#define PAL_PORT(line)                                                        \
  ((GPIO_T *)(((uint32_t)(line)) & 0xFFFFFFF0U))

/**
 * @brief   Extracts the pad number from a line.
 *
 * @param[in] line      line identifier
 * @return              Pad number.
 */
#define PAL_PAD(line)                                                         \
  ((uint32_t)((uint32_t)(line) & 0x0000000FU))

/** @brief Invalid line identifier.*/
#define PAL_NOLINE                       0U

/** @brief Type of an I/O port mask.*/
typedef uint32_t ioportmask_t;
/** @brief Type of an I/O mode.*/
typedef uint32_t iomode_t;
/** @brief Type of an I/O line identifier.*/
typedef uint32_t ioline_t;
/** @brief Type of an I/O event mode.*/
typedef uint32_t ioeventmode_t;
/** @brief Type of an I/O port identifier.*/
typedef GPIO_T *ioportid_t;
/** @brief Type of an I/O pad identifier.*/
typedef uint32_t iopadid_t;

/**
 * @brief   Low-level PAL initialization.
 *
 * @notapi
 */
#define pal_lld_init()                   _pal_lld_init()

/**
 * @brief   Reads an I/O port.
 *
 * @param[in] port      port identifier
 * @return              Port input value.
 * @notapi
 */
#define pal_lld_readport(port)           ((port)->PIN)

/**
 * @brief   Reads an I/O port output latch.
 *
 * @param[in] port      port identifier
 * @return              Port output latch value.
 * @notapi
 */
#define pal_lld_readlatch(port)          ((port)->DOUT)

/**
 * @brief   Writes an I/O port output latch.
 *
 * @param[in] port      port identifier
 * @param[in] bits      value to write
 * @notapi
 */
#define pal_lld_writeport(port, bits)    ((port)->DOUT = (uint32_t)(bits))

/**
 * @brief   Sets bits in an I/O port output latch.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to set
 * @notapi
 */
#define pal_lld_setport(port, bits)      ((port)->DOUT |= (uint32_t)(bits))

/**
 * @brief   Clears bits in an I/O port output latch.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to clear
 * @notapi
 */
#define pal_lld_clearport(port, bits)    ((port)->DOUT &= ~(uint32_t)(bits))

/**
 * @brief   Toggles bits in an I/O port output latch.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to toggle
 * @notapi
 */
#define pal_lld_toggleport(port, bits)   ((port)->DOUT ^= (uint32_t)(bits))

/**
 * @brief   Reads a group of pads.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    group bit offset
 * @return              Group input value.
 * @notapi
 */
#define pal_lld_readgroup(port, mask, offset)                                \
  (((port)->PIN >> (offset)) & (mask))

/**
 * @brief   Reads a group from an I/O port output latch.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    group bit offset
 * @return              Group output latch value.
 * @notapi
 */
#define pal_lld_readgrouplatch(port, mask, offset)                           \
  (((port)->DOUT >> (offset)) & (mask))

/**
 * @brief   Writes a group to an I/O port output latch.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    group bit offset
 * @param[in] bits      value to write
 * @notapi
 */
#define pal_lld_writegroup(port, mask, offset, bits)                         \
  ((port)->DOUT = ((port)->DOUT & ~((uint32_t)(mask) << (offset))) |         \
                  (((uint32_t)(bits) & (uint32_t)(mask)) << (offset)))

/**
 * @brief   Configures the mode of a group of pads.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    group bit offset
 * @param[in] mode      group mode
 * @notapi
 */
#define pal_lld_setgroupmode(port, mask, offset, mode)                       \
  _pal_lld_setgroupmode(port,                                                \
                        (ioportmask_t)((uint32_t)(mask) << (offset)),        \
                        mode)

/**
 * @brief   Reads an I/O pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number
 * @return              Pad logical state.
 * @notapi
 */
#define pal_lld_readpad(port, pad)                                           \
  (((port)->PIN >> (pad)) & 1U)

/**
 * @brief   Writes an I/O pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number
 * @param[in] bit       logical state to write
 * @notapi
 */
#define pal_lld_writepad(port, pad, bit)                                     \
  do {                                                                       \
    if ((bit) != PAL_LOW) {                                                  \
      PAL_M251_PIN_DATA(port, pad) = 1U;                                     \
    }                                                                        \
    else {                                                                   \
      PAL_M251_PIN_DATA(port, pad) = 0U;                                     \
    }                                                                        \
  } while (false)

/**
 * @brief   Sets an I/O pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number
 * @notapi
 */
#define pal_lld_setpad(port, pad)                                            \
  (PAL_M251_PIN_DATA(port, pad) = 1U)

/**
 * @brief   Clears an I/O pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number
 * @notapi
 */
#define pal_lld_clearpad(port, pad)                                          \
  (PAL_M251_PIN_DATA(port, pad) = 0U)

/**
 * @brief   Toggles an I/O pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number
 * @notapi
 */
#define pal_lld_togglepad(port, pad)                                         \
  (PAL_M251_PIN_DATA(port, pad) ^= 1U)

/**
 * @brief   Configures the mode of an I/O pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number
 * @param[in] mode      pad mode
 * @notapi
 */
#define pal_lld_setpadmode(port, pad, mode)                                  \
  _pal_lld_setgroupmode(port, PAL_PORT_BIT(pad), mode)

/**
 * @brief   Returns the port bit mask for a pad.
 *
 * @param[in] pad       pad number
 * @return              Port bit mask.
 */
#define PAL_PORT_BIT(pad)                 (1UL << (pad))

/**
 * @brief   Accesses the bit-band data register for a pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number
 * @return              Pad data register lvalue.
 */
#define PAL_M251_PIN_DATA(port, pad)                                         \
  GPIO_PIN_DATA((((uint32_t)(port) - GPIOA_BASE) / 0x40U), (pad))

/** @brief Number of GPIO ports supported by the port.*/
#define M251_GPIO_PORT_COUNT              6
/** @brief Total number of PAL event objects.*/
#define M251_PAL_EVENT_TOTAL              (M251_GPIO_PORT_COUNT * PAL_IOPORTS_WIDTH)

#if (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   GPIO interrupt priority.
 * @note    The default is 3.
 */
#if !defined(M251_GPIO_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define M251_GPIO_IRQ_PRIORITY            3
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(M251_GPIO_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to GPIO"
#endif

extern palevent_t _pal_events[M251_PAL_EVENT_TOTAL];

/**
 * @brief   Returns the event object associated with a pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number
 * @return              Pointer to the associated event object.
 * @notapi
 */
#define pal_lld_get_pad_event(port, pad)                                     \
  (&_pal_events[(((uint32_t)(port) - GPIOA_BASE) / 0x40U) *                  \
                PAL_IOPORTS_WIDTH + (pad)])

/**
 * @brief   Returns the event object associated with a line.
 *
 * @param[in] line      line identifier
 * @return              Pointer to the associated event object.
 * @notapi
 */
#define pal_lld_get_line_event(line)                                         \
  pal_lld_get_pad_event(PAL_PORT(line), PAL_PAD(line))

/**
 * @brief   Enables events on a pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number
 * @param[in] mode      event mode
 * @notapi
 */
#define pal_lld_enablepadevent(port, pad, mode)                              \
  _pal_lld_enablepadevent(port, pad, mode)

/**
 * @brief   Disables events on a pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number
 * @notapi
 */
#define pal_lld_disablepadevent(port, pad)                                   \
  _pal_lld_disablepadevent(port, pad)

/**
 * @brief   Tests whether events are enabled on a pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number
 * @return              @p true if pad events are enabled.
 * @notapi
 */
#define pal_lld_ispadeventenabled(port, pad)                                 \
  _pal_lld_ispadeventenabled(port, pad)

/**
 * @brief   Enables events on a line.
 *
 * @param[in] line      line identifier
 * @param[in] mode      event mode
 * @notapi
 */
#define pal_lld_enablelineevent(line, mode)                                  \
  pal_lld_enablepadevent(PAL_PORT(line), PAL_PAD(line), mode)

/**
 * @brief   Disables events on a line.
 *
 * @param[in] line      line identifier
 * @notapi
 */
#define pal_lld_disablelineevent(line)                                       \
  pal_lld_disablepadevent(PAL_PORT(line), PAL_PAD(line))

/**
 * @brief   Tests whether events are enabled on a line.
 *
 * @param[in] line      line identifier
 * @return              @p true if line events are enabled.
 * @notapi
 */
#define pal_lld_islineeventenabled(line)                                     \
  pal_lld_ispadeventenabled(PAL_PORT(line), PAL_PAD(line))
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void _pal_lld_init(void);
  void _pal_lld_setgroupmode(ioportid_t port,
                             ioportmask_t mask,
                             iomode_t mode);
#if (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE) || defined(__DOXYGEN__)
  void _pal_lld_enablepadevent(ioportid_t port, iopadid_t pad,
                               ioeventmode_t mode);
  void _pal_lld_disablepadevent(ioportid_t port, iopadid_t pad);
  bool _pal_lld_ispadeventenabled(ioportid_t port, iopadid_t pad);
#endif
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_PAL == TRUE */

#endif /* HAL_PAL_LLD_H */

/** @}*/
