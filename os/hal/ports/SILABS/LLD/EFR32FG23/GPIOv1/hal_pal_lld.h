/*
    ChibiOS - Copyright (C) 2024 Xael South

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
 * @file    GPIOv1/hal_pal_lld.h
 * @brief   EFR32 PAL low level driver header.
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

/**
 * @name    EFR32-specific I/O mode flags
 * @{
 */
#define PAL_EFR32_CTRL_SLEWRATE_DEFAULT        GPIO_P_CTRL_SLEWRATE_DEFAULT
#define PAL_EFR32_CTRL_DINDIS_DEFAULT          GPIO_P_CTRL_DINDIS_DEFAULT
#define PAL_EFR32_CTRL_SLEWRATEALT_DEFAULT     GPIO_P_CTRL_SLEWRATEALT_DEFAULT
#define PAL_EFR32_CTRL_DINDISALT_DEFAULT       GPIO_P_CTRL_DINDISALT_DEFAULT


#define PAL_EFR32_PORTA_CTRL_DEFAULT           (PAL_EFR32_CTRL_SLEWRATE_DEFAULT    | \
                                                PAL_EFR32_CTRL_DINDIS_DEFAULT      | \
                                                PAL_EFR32_CTRL_SLEWRATEALT_DEFAULT | \
                                                PAL_EFR32_CTRL_DINDISALT_DEFAULT)

#define PAL_EFR32_PORTB_CTRL_DEFAULT           (PAL_EFR32_CTRL_SLEWRATE_DEFAULT    | \
                                                PAL_EFR32_CTRL_DINDIS_DEFAULT      | \
                                                PAL_EFR32_CTRL_SLEWRATEALT_DEFAULT | \
                                                PAL_EFR32_CTRL_DINDISALT_DEFAULT)

#define PAL_EFR32_PORTC_CTRL_DEFAULT           (PAL_EFR32_CTRL_SLEWRATE_DEFAULT    | \
                                                PAL_EFR32_CTRL_DINDIS_DEFAULT      | \
                                                PAL_EFR32_CTRL_SLEWRATEALT_DEFAULT | \
                                                PAL_EFR32_CTRL_DINDISALT_DEFAULT)

#define PAL_EFR32_PORTD_CTRL_DEFAULT           (PAL_EFR32_CTRL_SLEWRATE_DEFAULT    | \
                                                PAL_EFR32_CTRL_DINDIS_DEFAULT      | \
                                                PAL_EFR32_CTRL_SLEWRATEALT_DEFAULT | \
                                                PAL_EFR32_CTRL_DINDISALT_DEFAULT)


#define PAL_EFR32_MODEL_DEFAULT                 GPIO_P_MODEL_MODE0_DEFAULT
#define PAL_EFR32_MODEL_DISABLED                GPIO_P_MODEL_MODE0_DISABLED
#define PAL_EFR32_MODEL_INPUT                   GPIO_P_MODEL_MODE0_INPUT
#define PAL_EFR32_MODEL_INPUTPULL               GPIO_P_MODEL_MODE0_INPUTPULL
#define PAL_EFR32_MODEL_INPUTPULLFILTER         GPIO_P_MODEL_MODE0_INPUTPULLFILTER
#define PAL_EFR32_MODEL_PUSHPULL                GPIO_P_MODEL_MODE0_PUSHPULL
#define PAL_EFR32_MODEL_PUSHPULLALT             GPIO_P_MODEL_MODE0_PUSHPULLALT
#define PAL_EFR32_MODEL_WIREDOR                 GPIO_P_MODEL_MODE0_WIREDOR
#define PAL_EFR32_MODEL_WIREDORPULLDOWN         GPIO_P_MODEL_MODE0_WIREDORPULLDOWN
#define PAL_EFR32_MODEL_WIREDAND                GPIO_P_MODEL_MODE0_WIREDAND
#define PAL_EFR32_MODEL_WIREDANDFILTER          GPIO_P_MODEL_MODE0_WIREDANDFILTER
#define PAL_EFR32_MODEL_WIREDANDPULLUP          GPIO_P_MODEL_MODE0_WIREDANDPULLUP
#define PAL_EFR32_MODEL_WIREDANDPULLUPFILTER    GPIO_P_MODEL_MODE0_WIREDANDPULLUPFILTER
#define PAL_EFR32_MODEL_WIREDANDALT             GPIO_P_MODEL_MODE0_WIREDANDALT
#define PAL_EFR32_MODEL_WIREDANDALTFILTER       GPIO_P_MODEL_MODE0_WIREDANDALTFILTER
#define PAL_EFR32_MODEL_WIREDANDALTPULLUP       GPIO_P_MODEL_MODE0_WIREDANDALTPULLUP
#define PAL_EFR32_MODEL_WIREDANDALTPULLUPFILTER GPIO_P_MODEL_MODE0_WIREDANDALTPULLUPFILTER


#define PAL_EFR32_PORTA_MODEL_DEFAULT           ((PAL_EFR32_MODEL_DEFAULT <<  0U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT <<  4U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT <<  8U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 12U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 16U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 20U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 24U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 28U))

#define PAL_EFR32_PORTB_MODEL_DEFAULT           ((PAL_EFR32_MODEL_DEFAULT <<  0U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT <<  4U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT <<  8U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 12U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 16U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 20U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 24U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 28U))

#define PAL_EFR32_PORTC_MODEL_DEFAULT           ((PAL_EFR32_MODEL_DEFAULT <<  0U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT <<  4U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT <<  8U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 12U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 16U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 20U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 24U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 28U))

#define PAL_EFR32_PORTD_MODEL_DEFAULT           ((PAL_EFR32_MODEL_DEFAULT <<  0U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT <<  4U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT <<  8U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 12U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 16U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 20U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 24U) | \
                                                 (PAL_EFR32_MODEL_DEFAULT << 28U))


#define PAL_EFR32_MODEH_DEFAULT                 GPIO_P_MODEH_MODE0_DEFAULT
#define PAL_EFR32_MODEH_DISABLED                GPIO_P_MODEH_MODE0_DISABLED
#define PAL_EFR32_MODEH_INPUT                   GPIO_P_MODEH_MODE0_INPUT
#define PAL_EFR32_MODEH_INPUTPULL               GPIO_P_MODEH_MODE0_INPUTPULL
#define PAL_EFR32_MODEH_INPUTPULLFILTER         GPIO_P_MODEH_MODE0_INPUTPULLFILTER
#define PAL_EFR32_MODEH_PUSHPULL                GPIO_P_MODEH_MODE0_PUSHPULL
#define PAL_EFR32_MODEH_PUSHPULLALT             GPIO_P_MODEH_MODE0_PUSHPULLALT
#define PAL_EFR32_MODEH_WIREDOR                 GPIO_P_MODEH_MODE0_WIREDOR
#define PAL_EFR32_MODEH_WIREDORPULLDOWN         GPIO_P_MODEH_MODE0_WIREDORPULLDOWN
#define PAL_EFR32_MODEH_WIREDAND                GPIO_P_MODEH_MODE0_WIREDAND
#define PAL_EFR32_MODEH_WIREDANDFILTER          GPIO_P_MODEH_MODE0_WIREDANDFILTER
#define PAL_EFR32_MODEH_WIREDANDPULLUP          GPIO_P_MODEH_MODE0_WIREDANDPULLUP
#define PAL_EFR32_MODEH_WIREDANDPULLUPFILTER    GPIO_P_MODEH_MODE0_WIREDANDPULLUPFILTER
#define PAL_EFR32_MODEH_WIREDANDALT             GPIO_P_MODEH_MODE0_WIREDANDALT
#define PAL_EFR32_MODEH_WIREDANDALTFILTER       GPIO_P_MODEH_MODE0_WIREDANDALTFILTER
#define PAL_EFR32_MODEH_WIREDANDALTPULLUP       GPIO_P_MODEH_MODE0_WIREDANDALTPULLUP
#define PAL_EFR32_MODEH_WIREDANDALTPULLUPFILTER GPIO_P_MODEH_MODE0_WIREDANDALTPULLUPFILTER


#define PAL_EFR32_PORTA_MODEH_DEFAULT           ((PAL_EFR32_MODEH_DEFAULT <<  0U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT <<  4U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT <<  8U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 12U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 16U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 20U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 24U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 28U))

#define PAL_EFR32_PORTB_MODEH_DEFAULT           ((PAL_EFR32_MODEH_DEFAULT <<  0U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT <<  4U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT <<  8U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 12U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 16U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 20U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 24U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 28U))

#define PAL_EFR32_PORTC_MODEH_DEFAULT           ((PAL_EFR32_MODEH_DEFAULT <<  0U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT <<  4U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT <<  8U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 12U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 16U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 20U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 24U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 28U))

#define PAL_EFR32_PORTD_MODEH_DEFAULT           ((PAL_EFR32_MODEH_DEFAULT <<  0U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT <<  4U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT <<  8U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 12U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 16U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 20U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 24U) | \
                                                 (PAL_EFR32_MODEH_DEFAULT << 28U))


#define PAL_EFR32_DINT_DEFAULT                  GPIO_P_DIN_DIN_DEFAULT
#define PAL_EFR32_PORTA_DIN_DEFAULT             PAL_EFR32_DIN_DEFAULT
#define PAL_EFR32_PORTB_DIN_DEFAULT             PAL_EFR32_DIN_DEFAULT
#define PAL_EFR32_PORTC_DIN_DEFAULT             PAL_EFR32_DIN_DEFAULT
#define PAL_EFR32_PORTD_DIN_DEFAULT             PAL_EFR32_DIN_DEFAULT


#define PAL_EFR32_DOUT_DEFAULT                  GPIO_P_DOUT_DOUT_DEFAULT
#define PAL_EFR32_PORTA_DOUT_DEFAULT            PAL_EFR32_DOUT_DEFAULT
#define PAL_EFR32_PORTB_DOUT_DEFAULT            PAL_EFR32_DOUT_DEFAULT
#define PAL_EFR32_PORTC_DOUT_DEFAULT            PAL_EFR32_DOUT_DEFAULT
#define PAL_EFR32_PORTD_DOUT_DEFAULT            PAL_EFR32_DOUT_DEFAULT


#define PAL_EFR32_MODE_SHIFT                      (0U)
#define PAL_EFR32_MODE_MASK                       (0xFU << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_DISABLED                   ( 0U << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_INPUT                      ( 1U << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_INPUTPULL                  ( 2U << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_INPUTPULL_FILTER           ( 3U << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_PUSHPULL                   ( 4U << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_PUSHPULL_ALT               ( 5U << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_WIREDOR                    ( 6U << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_WIREDOR_PULLDOWN           ( 7U << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_WIREDAND                   ( 8U << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_WIREDAND_FILTER            ( 9U << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_WIREDAND_PULLUP            (10U << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_WIREDAND_PULLUP_FILTER     (11U << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_WIREDAND_ALT               (12U << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_WIREDAND_ALT_FILTER        (13U << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_WIREDAND_ALT_PULLUP        (14U << PAL_EFR32_MODE_SHIFT)
#define PAL_EFR32_MODE_WIREDAND_ALT_PULLUP_FILTER (15U << PAL_EFR32_MODE_SHIFT)


#define PAL_EFR32_DOUT_SHIFT                    (4U)
#define PAL_EFR32_DOUT_MASK                     (1U << PAL_EFR32_DOUT_SHIFT)
#define PAL_EFR32_DOUT_LOW                      (0U << PAL_EFR32_DOUT_SHIFT)
#define PAL_EFR32_DOUT_PULLDOWN                 (0U << PAL_EFR32_DOUT_SHIFT)
#define PAL_EFR32_DOUT_FLOATING                 (0U << PAL_EFR32_DOUT_SHIFT)
#define PAL_EFR32_DOUT_HIGH                     (1U << PAL_EFR32_DOUT_SHIFT)
#define PAL_EFR32_DOUT_PULLUP                   (1U << PAL_EFR32_DOUT_SHIFT)
#define PAL_EFR32_DOUT_FILTER                   (1U << PAL_EFR32_DOUT_SHIFT)


#undef PAL_MODE_RESET
#undef PAL_MODE_UNCONNECTED
#undef PAL_MODE_INPUT
#undef PAL_MODE_INPUT_PULLUP
#undef PAL_MODE_INPUT_PULLDOWN
#undef PAL_MODE_INPUT_ANALOG
#undef PAL_MODE_OUTPUT_PUSHPULL
#undef PAL_MODE_OUTPUT_OPENDRAIN

#define PAL_MODE_RESET                          (PAL_EFR32_MODE_DISABLED  | \
                                                 PAL_EFR32_DOUT_FLOATING)

#define PAL_MODE_UNCONNECTED                    (PAL_EFR32_MODE_DISABLED  | \
                                                 PAL_EFR32_DOUT_FLOATING)

#define PAL_MODE_INPUT                          (PAL_EFR32_MODE_INPUT     | \
                                                 PAL_EFR32_DOUT_FLOATING)

#define PAL_MODE_INPUT_PULLUP                   (PAL_EFR32_MODE_INPUTPULL | \
                                                 PAL_EFR32_DOUT_PULLUP)

#define PAL_MODE_INPUT_PULLDOWN                 (PAL_EFR32_MODE_INPUTPULL | \
                                                 PAL_EFR32_DOUT_PULLDOWN)

#define PAL_MODE_INPUT_ANALOG                   (PAL_EFR32_MODE_INPUT     | \
                                                 PAL_EFR32_DOUT_FLOATING)

#define PAL_MODE_OUTPUT_PUSHPULL                (PAL_EFR32_MODE_PUSHPULL  | \
                                                 PAL_EFR32_DOUT_HIGH)

#define PAL_MODE_OUTPUT_OPENDRAIN               (PAL_EFR32_MODE_WIREDAND  | \
                                                 PAL_EFR32_DOUT_PULLUP)

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
#define PAL_IOPORTS_WIDTH           16U

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
 * @note    In this driver the pad number is encoded in the lower 4 bits of
 *          the GPIO address which are guaranteed to be zero.
 */
#define PAL_LINE(port, pad)                                                 \
  ((ioline_t)((uint32_t)(port)) | ((uint32_t)(pad)))

/**
 * @brief   Decodes a port identifier from a line identifier.
 */
#define PAL_PORT(line)                                                      \
  ((GPIO_PORT_TypeDef *)(((uint32_t)(line)) & 0xFFFFFFF0U))

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
  uint32_t              ctrlr;  /**< port control            */
  uint32_t              modelr; /**< mode low                */
  uint32_t              modehr; /**< mode high               */
  uint32_t              doutr;  /**< data out                */
} efr32_gpio_setup_t;

/**
 * @brief   EFR32 GPIO static initializer.
 * @details An instance of this structure must be passed to @p palInit() at
 *          system startup time in order to initialize the digital I/O
 *          subsystem. This represents only the initial setup, specific pads
 *          or whole ports can be reprogrammed at later time.
 */
typedef struct {
/** @brief Port A setup data.*/
  efr32_gpio_setup_t    PAData;
  /** @brief Port B setup data.*/
  efr32_gpio_setup_t    PBData;
  /** @brief Port C setup data.*/
  efr32_gpio_setup_t    PCData;
  /** @brief Port D setup data.*/
  efr32_gpio_setup_t    PDData;
} PALConfig;

/**
 * @brief Digital I/O port sized unsigned type.
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
typedef uint32_t ioeventmode_t;

/**
 * @brief   Port Identifier.
 * @details This type can be a scalar or some kind of pointer, do not make
 *          any assumption about it, use the provided macros when populating
 *          variables of this type.
 */
typedef GPIO_PORT_TypeDef* ioportid_t;

/**
 * @brief   Type of an pad identifier.
 */
typedef uint32_t iopadid_t;

/*===========================================================================*/
/* I/O Ports Identifiers.                                                    */
/* The low level driver wraps the definitions already present in the EFR32   */
/* firmware library.                                                         */
/*===========================================================================*/

/**
 * @brief   GPIO port A identifier.
 */
#if EFR32_HAS_GPIOA || defined(__DOXYGEN__)
#define GPIOA           (&(GPIO->P[GPIO_PA_INDEX]))
#define IOPORT1         GPIOA
#endif

/**
 * @brief   GPIO port B identifier.
 */
#if EFR32_HAS_GPIOB || defined(__DOXYGEN__)
#define GPIOB           (&(GPIO->P[GPIO_PB_INDEX]))
#define IOPORT2         GPIOB
#endif

/**
 * @brief   GPIO port C identifier.
 */
#if EFR32_HAS_GPIOC || defined(__DOXYGEN__)
#define GPIOC           (&(GPIO->P[GPIO_PC_INDEX]))
#define IOPORT3         GPIOC
#endif

/**
 * @brief   GPIO port D identifier.
 */
#if EFR32_HAS_GPIOD || defined(__DOXYGEN__)
#define GPIOD           (&(GPIO->P[GPIO_PD_INDEX]))
#define IOPORT4         GPIOD
#endif

#define GPIO_PORT_INDEX(port) ((port == GPIOA) ? GPIO_PA_INDEX : \
                               (port == GPIOB) ? GPIO_PB_INDEX : \
                               (port == GPIOC) ? GPIO_PC_INDEX : \
                               (port == GPIOD) ? GPIO_PD_INDEX : \
                               0)

#define GPIO_PIN_COUNT(port) ((port == GPIOA) ? GPIO_PA_COUNT : \
                              (port == GPIOB) ? GPIO_PB_COUNT : \
                              (port == GPIOC) ? GPIO_PC_COUNT : \
                              (port == GPIOD) ? GPIO_PD_COUNT : \
                              0)

#define GPIO_PORT_MASK(port) ((port == GPIOA) ? GPIO_PA_MASK : \
                              (port == GPIOB) ? GPIO_PB_MASK : \
                              (port == GPIOC) ? GPIO_PC_MASK : \
                              (port == GPIOD) ? GPIO_PD_MASK : \
                              0)

/*===========================================================================*/
/* Implementation, some of the following macros could be implemented as      */
/* functions, if so please put them in pal_lld.c.                            */
/*===========================================================================*/

/**
 * @brief   GPIO ports subsystem initialization.
 *
 * @notapi
 */
#define pal_lld_init(config) _pal_lld_init(config)

/**
 * @brief   Reads an I/O port.
 * @note    This function is not meant to be invoked directly by the application
 *          code.
 *
 * @param[in] port      port identifier
 * @return              The port bits.
 *
 * @notapi
 */
#define pal_lld_readport(port) ((ioportmask_t)(port->DIN))

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
#define pal_lld_readlatch(port) ((ioportmask_t)(port->DOUT))

/**
 * @brief   Writes a bits mask on a I/O port.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be written on the specified port
 *
 * @notapi
 */
#define pal_lld_writeport(port, bits) ((port->DOUT = (ioportmask_t)(bits)))

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
#define pal_lld_setport(port, bits) ((GPIO->P_SET[GPIO_PORT_INDEX(port)].DOUT = (ioportmask_t)(bits)))

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
#define pal_lld_clearport(port, bits) ((GPIO->P_CLR[GPIO_PORT_INDEX(port)].DOUT = (ioportmask_t)(bits)))

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
#define pal_lld_toggleport(port, bits) ((GPIO->P_TGL[GPIO_PORT_INDEX(port)].DOUT = (ioportmask_t)(bits)))

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
#define pal_lld_readpad(port, pad) ((((port->DIN >> pad) & 1) == 1) ? \
                                    PAL_HIGH : PAL_LOW)

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
#define pal_lld_writepad(port, pad, bit)                                    \
  do {                                                                      \
    if ((bit) == PAL_HIGH)                                                  \
      GPIO->P_SET[GPIO_PORT_INDEX(port)].DOUT = 1 << (pad);                 \
    else                                                                    \
      GPIO->P_CLR[GPIO_PORT_INDEX(port)].DOUT = 1 << (pad);                 \
  } while (false)

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
#define pal_lld_setpad(port, pad)                                           \
  do {                                                                      \
    if (!!PAL_HIGH)                                                         \
      GPIO->P_SET[GPIO_PORT_INDEX(port)].DOUT = 1 << (pad);                 \
    else                                                                    \
      GPIO->P_CLR[GPIO_PORT_INDEX(port)].DOUT = 1 << (pad);                 \
  } while (false)

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
#define pal_lld_clearpad(port, pad)                                         \
  do {                                                                      \
    if (!!PAL_HIGH)                                                         \
      GPIO->P_CLR[GPIO_PORT_INDEX(port)].DOUT = 1 << (pad);                 \
    else                                                                    \
      GPIO->P_SET[GPIO_PORT_INDEX(port)].DOUT = 1 << (pad);                 \
  } while (false)

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
#define pal_lld_togglepad(port, pad)                                        \
  do {                                                                      \
    GPIO->P_TGL[GPIO_PORT_INDEX(port)].DOUT = 1 << (pad);                   \
  } while (false)

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
#define pal_lld_setpadmode(port, pad, mode)                                \
  _pal_lld_setpadmode(port, pad, mode)

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
  &_pal_events[pad]; (void)(port)

/**
 * @brief   Returns a PAL event structure associated to a line.
 *
 * @param[in] line      line identifier
 *
 * @notapi
 */
#define pal_lld_get_line_event(line)                                        \
  &_pal_events[PAL_PAD(line)]

#if !defined(__DOXYGEN__)
extern const PALConfig pal_default_config;
#if (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE)
#define PAL_EVENTS_SIZE       16U
extern palevent_t _pal_events[PAL_EVENTS_SIZE];
#endif
#endif

#ifdef __cplusplus
extern "C"
{
#endif
void _pal_lld_init(const PALConfig* config);
void _pal_lld_setgroupmode(ioportid_t port, ioportmask_t mask, iomode_t mode);
void _pal_lld_setpadmode(ioportid_t port, iopadid_t pad, iomode_t mode);
void _pal_lld_enablepadevent(ioportid_t port, iopadid_t pad, ioeventmode_t mode);
void _pal_lld_disablepadevent(ioportid_t port, iopadid_t pad);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_PAL == TRUE */

#endif /* HAL_PAL_LLD_H */

/** @} */