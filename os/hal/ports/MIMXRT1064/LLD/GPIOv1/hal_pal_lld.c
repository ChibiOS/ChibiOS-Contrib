/*
    ChibiOS - Copyright (C) 2014-2015 Fabio Utzig

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
 * @file    GPIOv1/hal_pal_lld.c
 * @brief   PAL subsystem low level driver.
 *
 * @addtogroup PAL
 * @{
 */

#include "osal.h"
#include "hal.h"

#if HAL_USE_PAL || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

uint8_t bit_by_index[] =
  {
   EDGEPRO1_PIN0_BIT,
   EDGEPRO1_PIN1_BIT,
   EDGEPRO1_PIN2_BIT,
   EDGEPRO1_PIN3_BIT,
   EDGEPRO1_PIN4_BIT,
   EDGEPRO1_PIN5_BIT,
   EDGEPRO1_PIN6_BIT,
   EDGEPRO1_PIN7_BIT,
   EDGEPRO1_PIN8_BIT,
   EDGEPRO1_PIN9_BIT,
   EDGEPRO1_PIN10_BIT,
   EDGEPRO1_PIN11_BIT,
   EDGEPRO1_PIN12_BIT,
   EDGEPRO1_PIN13_BIT,
   EDGEPRO1_PIN14_BIT,
   EDGEPRO1_PIN15_BIT,
   EDGEPRO1_PIN16_BIT,
  };

uint8_t SW_MUX_CTL_PAD_by_index[] =
  {
   EDGEPRO1_PIN0_MUX,
   EDGEPRO1_PIN1_MUX,
   EDGEPRO1_PIN2_MUX,
   EDGEPRO1_PIN3_MUX,
   EDGEPRO1_PIN4_MUX,
   EDGEPRO1_PIN5_MUX,
   EDGEPRO1_PIN6_MUX,
   EDGEPRO1_PIN7_MUX,
   EDGEPRO1_PIN8_MUX,
   EDGEPRO1_PIN9_MUX,
   EDGEPRO1_PIN10_MUX,
   EDGEPRO1_PIN11_MUX,
   EDGEPRO1_PIN12_MUX,
   EDGEPRO1_PIN13_MUX,
   EDGEPRO1_PIN14_MUX,
   EDGEPRO1_PIN15_MUX,
   EDGEPRO1_PIN16_MUX,
  };

uint8_t SW_PAD_CTL_PAD_by_index[] =
  {
   EDGEPRO1_PIN0_PAD,
   EDGEPRO1_PIN1_PAD,
   EDGEPRO1_PIN2_PAD,
   EDGEPRO1_PIN3_PAD,
   EDGEPRO1_PIN4_PAD,
   EDGEPRO1_PIN5_PAD,
   EDGEPRO1_PIN6_PAD,
   EDGEPRO1_PIN7_PAD,
   EDGEPRO1_PIN8_PAD,
   EDGEPRO1_PIN9_PAD,
   EDGEPRO1_PIN10_PAD,
   EDGEPRO1_PIN11_PAD,
   EDGEPRO1_PIN12_PAD,
   EDGEPRO1_PIN13_PAD,
   EDGEPRO1_PIN14_PAD,
   EDGEPRO1_PIN15_PAD,
   EDGEPRO1_PIN16_PAD,
  };

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief Reads a logical state from an I/O pad.
 * @note The @ref PAL provides a default software implementation of this
 * functionality, implement this function if can optimize it by using
 * special hardware functionalities or special coding.
 *
 * @param[in] port port identifier
 * @param[in] pad pad number within the port
 * @return The logical state.
 * @retval PAL_LOW low logical state.
 * @retval PAL_HIGH high logical state.
 *
 * @notapi
 */
uint8_t _pal_lld_readpad(ioportid_t port,
                         uint8_t pad) {
  return (port->DR & ((uint32_t) 1 << bit_by_index[pad])) ? PAL_HIGH : PAL_LOW;
}

/**
 * @brief Writes a logical state on an output pad.
 * @note This function is not meant to be invoked directly by the
 * application code.
 * @note The @ref PAL provides a default software implementation of this
 * functionality, implement this function if can optimize it by using
 * special hardware functionalities or special coding.
 *
 * @param[in] port port identifier
 * @param[in] pad pad number within the port
 * @param[in] bit logical value, the value must be @p PAL_LOW or
 * @p PAL_HIGH
 *
 * @notapi
 */
void _pal_lld_writepad(ioportid_t port,
                       uint8_t pad,
                       uint8_t bit) {
  if (bit == PAL_HIGH)
    port->DR_SET = ((uint32_t) 1 << bit_by_index[pad]);
  else
    port->DR_CLEAR = ((uint32_t) 1 << bit_by_index[pad]);
}

void _pal_lld_togglepad(ioportid_t port,
                        uint8_t pad) {
  port->DR_TOGGLE = ((uint32_t) 1 << bit_by_index[pad]);
}

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
void _pal_lld_setpadmode(ioportid_t port,
                         uint8_t pad,
                         iomode_t mode) {
  osalDbgAssert(pad < PADS_PER_PORT, "pal_lld_setpadmode() #1, invalid pad");

  // see IMXRT1060RM Section 12.4.3 GPIO programming

  // Interrupt Mask Register (IMR)
  port->IMR &= ~((uint32_t) 1 << bit_by_index[pad]);

  // All GPIOs are on mode ALT5 as per Chapter 10, External Signals and Pin Multiplexing, Table 10-1
  const int altMode = 5;

  switch (mode) {
  case PAL_MODE_RESET:
  case PAL_MODE_INPUT:
  case PAL_MODE_OUTPUT_PUSHPULL:
    IOMUXC->SW_MUX_CTL_PAD[SW_MUX_CTL_PAD_by_index[pad]] =
      PIN_MUX_ALTERNATIVE(altMode);
    // need to always set PAD_CTL in case the pin was configured as input before
    IOMUXC->SW_PAD_CTL_PAD[SW_PAD_CTL_PAD_by_index[pad]] =
      IOMUXC_SW_PAD_CTL_PAD_DSE(6);
    //IOMUXC->SW_PAD_CTL_PAD[SW_PAD_CTL_PAD_by_index[pad]] = 0;
    break;

  case PAL_MODE_OUTPUT_OPENDRAIN:
    IOMUXC->SW_MUX_CTL_PAD[SW_MUX_CTL_PAD_by_index[pad]] =
      PIN_MUX_ALTERNATIVE(altMode);
    IOMUXC->SW_PAD_CTL_PAD[SW_PAD_CTL_PAD_by_index[pad]] =
      IOMUXC_SW_PAD_CTL_PAD_ODE(1); /* Open Drain Enable */
    break;

  case PAL_MODE_INPUT_PULLUP:
    IOMUXC->SW_MUX_CTL_PAD[SW_MUX_CTL_PAD_by_index[pad]] =
      PIN_MUX_ALTERNATIVE(altMode);

    IOMUXC->SW_PAD_CTL_PAD[SW_PAD_CTL_PAD_by_index[pad]] =
      IOMUXC_SW_PAD_CTL_PAD_PKE(1) | /* Pull/Keep Enable */
      IOMUXC_SW_PAD_CTL_PAD_PUS(1) | /* Pull Up/Down Config: 47k pull up */
      IOMUXC_SW_PAD_CTL_PAD_PUE(1); /* Pull/Keep Select: pull */

    break;

  case PAL_MODE_INPUT_PULLDOWN:
    IOMUXC->SW_MUX_CTL_PAD[SW_MUX_CTL_PAD_by_index[pad]] =
      PIN_MUX_ALTERNATIVE(altMode);

    IOMUXC->SW_PAD_CTL_PAD[SW_PAD_CTL_PAD_by_index[pad]] =
      IOMUXC_SW_PAD_CTL_PAD_PKE(1) | /* Pull/Keep Enable */
      IOMUXC_SW_PAD_CTL_PAD_PUS(0) | /* Pull Up/Down Config: 100k pull dn */
      IOMUXC_SW_PAD_CTL_PAD_PUE(1); /* Pull/Keep Select: pull */
    break;

  case PAL_MODE_UNCONNECTED:
  case PAL_MODE_INPUT_ANALOG:
    IOMUXC->SW_MUX_CTL_PAD[SW_MUX_CTL_PAD_by_index[pad]] =
      PIN_MUX_ALTERNATIVE(altMode);
    break;

  case PAL_MODE_ALTERNATIVE_1:
    IOMUXC->SW_MUX_CTL_PAD[SW_MUX_CTL_PAD_by_index[pad]] =
      PIN_MUX_ALTERNATIVE(1);
    break;

  case PAL_MODE_ALTERNATIVE_2:
    IOMUXC->SW_MUX_CTL_PAD[SW_MUX_CTL_PAD_by_index[pad]] =
      PIN_MUX_ALTERNATIVE(2);
    break;

  case PAL_MODE_ALTERNATIVE_3:
    IOMUXC->SW_MUX_CTL_PAD[SW_MUX_CTL_PAD_by_index[pad]] =
      PIN_MUX_ALTERNATIVE(3);
    break;

  case PAL_MODE_ALTERNATIVE_4:
    IOMUXC->SW_MUX_CTL_PAD[SW_MUX_CTL_PAD_by_index[pad]] =
      PIN_MUX_ALTERNATIVE(4);
    break;

  case PAL_MODE_ALTERNATIVE_5:
    IOMUXC->SW_MUX_CTL_PAD[SW_MUX_CTL_PAD_by_index[pad]] =
      PIN_MUX_ALTERNATIVE(5);
    break;

  case PAL_MODE_ALTERNATIVE_6:
    IOMUXC->SW_MUX_CTL_PAD[SW_MUX_CTL_PAD_by_index[pad]] =
      PIN_MUX_ALTERNATIVE(6);
    break;

  case PAL_MODE_ALTERNATIVE_7:
    IOMUXC->SW_MUX_CTL_PAD[SW_MUX_CTL_PAD_by_index[pad]] =
      PIN_MUX_ALTERNATIVE(7);
    break;
  }

  // GPIO direction register (GDIR)
  if (mode == PAL_MODE_OUTPUT_PUSHPULL) {
    port->GDIR |= ((uint32_t) 1 << bit_by_index[pad]);
  } else {
    port->GDIR &= ~((uint32_t) 1 << bit_by_index[pad]);
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   MIMXRT1064 I/O ports configuration.
 *
 * @param[in] config    the MIMXRT1064 ports configuration
 *
 * @notapi
 */
void _pal_lld_init(const PALConfig *config) {
  (void)config;
  /* Clocks are already enabled because MIMXRT1064_clock_init() enables GPIO
     earlier in the boot. */
}

#endif /* HAL_USE_PAL */

/** @} */
