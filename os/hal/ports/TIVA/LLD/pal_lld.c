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
 * @file    TIVA/LLD/pal_lld.c
 * @brief   TM4C123x/TM4C129x PAL subsystem low level driver.
 *
 * @addtogroup PAL
 * @{
 */

#include "hal.h"

#if HAL_USE_PAL || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define RCGCGPIOA       (1 << 0)
#define RCGCGPIOB       (1 << 1)
#define RCGCGPIOC       (1 << 2)
#define RCGCGPIOD       (1 << 3)
#define RCGCGPIOE       (1 << 4)
#define RCGCGPIOF       (1 << 5)

#if TIVA_HAS_GPIOG || defined(__DOXYGEN__)
#define RCGCGPIOG       (1 << 6)
#else
#define RCGCGPIOG       0
#endif

#if TIVA_HAS_GPIOH || defined(__DOXYGEN__)
#define RCGCGPIOH       (1 << 7)
#else
#define RCGCGPIOH       0
#endif

#if TIVA_HAS_GPIOJ || defined(__DOXYGEN__)
#define RCGCGPIOJ       (1 << 8)
#else
#define RCGCGPIOJ       0
#endif

#if TIVA_HAS_GPIOK || defined(__DOXYGEN__)
#define RCGCGPIOK       (1 << 9)
#else
#define RCGCGPIOK       0
#endif

#if TIVA_HAS_GPIOL || defined(__DOXYGEN__)
#define RCGCGPIOL       (1 << 10)
#else
#define RCGCGPIOL       0
#endif

#if TIVA_HAS_GPIOM || defined(__DOXYGEN__)
#define RCGCGPIOM       (1 << 11)
#else
#define RCGCGPIOM       0
#endif

#if TIVA_HAS_GPION || defined(__DOXYGEN__)
#define RCGCGPION       (1 << 12)
#else
#define RCGCGPION       0
#endif

#if TIVA_HAS_GPIOP || defined(__DOXYGEN__)
#define RCGCGPIOP       (1 << 13)
#else
#define RCGCGPIOP       0
#endif

#if TIVA_HAS_GPIOQ || defined(__DOXYGEN__)
#define RCGCGPIOQ       (1 << 14)
#else
#define RCGCGPIOQ       0
#endif

#if TIVA_HAS_GPIOR || defined(__DOXYGEN__)
#define RCGCGPIOR       (1 << 15)
#else
#define RCGCGPIOR       0
#endif

#if TIVA_HAS_GPIOS || defined(__DOXYGEN__)
#define RCGCGPIOS       (1 << 16)
#else
#define RCGCGPIOS       0
#endif

#if TIVA_HAS_GPIOT || defined(__DOXYGEN__)
#define RCGCGPIOT       (1 << 17)
#else
#define RCGCGPIOT       0
#endif

#define RCGCGPIO_VALUE  (RCGCGPIOA | RCGCGPIOB | RCGCGPIOC | RCGCGPIOD |      \
                         RCGCGPIOE | RCGCGPIOF | RCGCGPIOG | RCGCGPIOH |      \
                         RCGCGPIOJ | RCGCGPIOK | RCGCGPIOL | RCGCGPIOM |      \
                         RCGCGPION | RCGCGPIOP | RCGCGPIOQ | RCGCGPIOR |      \
                         RCGCGPIOS | RCGCGPIOT)

/* GPIO lock password.*/
#define TIVA_GPIO_LOCK_PWD                  0x4C4F434B

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

void gpio_init (GPIO_TypeDef *gpiop, const tiva_gpio_setup_t *config)
{
  gpiop->DATA   = config->data;
  gpiop->DIR    = config->dir;
  gpiop->AFSEL  = config->afsel;
  gpiop->DR2R   = config->dr2r;
  gpiop->DR4R   = config->dr4r;
  gpiop->DR8R   = config->dr8r;
  gpiop->ODR    = config->odr;
  gpiop->PUR    = config->pur;
  gpiop->PDR    = config->pdr;
  gpiop->SLR    = config->slr;
  gpiop->DEN    = config->den;
  gpiop->AMSEL  = config->amsel;
  gpiop->PCTL   = config->pctl;
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   TIVA I/O ports configuration.
 * @details Ports A-F (G, H, J, K, L, M, N, P, Q, R, S, T) clocks enabled.
 *
 * @param[in] config    the TIVA ports configuration
 *
 * @notapi
 */
void _pal_lld_init(const PALConfig *config)
{
  SYSCTL->RCGCGPIO = RCGCGPIO_VALUE;

  __NOP();
  __NOP();
  __NOP();
  
  gpio_init(GPIOA, &config->PAData);

  gpio_init(GPIOB, &config->PBData);

  GPIOC->LOCK = TIVA_GPIO_LOCK_PWD;
  GPIOC->CR = 0x01;
  gpio_init(GPIOC, &config->PCData);
  GPIOC->LOCK = 0;

  gpio_init(GPIOD, &config->PDData);

  gpio_init(GPIOE, &config->PEData);

  GPIOF->LOCK = TIVA_GPIO_LOCK_PWD;
  GPIOF->CR = 0x01;
  gpio_init(GPIOF, &config->PFData);
  GPIOF->LOCK = 0;
  
#if TIVA_HAS_GPIOG || defined(__DOXYGEN__)
  gpio_init(GPIOG, &config->PGData);
#endif /* TIVA_HAS_GPIOG.*/
  
#if TIVA_HAS_GPIOH || defined(__DOXYGEN__)
  gpio_init(GPIOH, &config->PHData);
#endif /* TIVA_HAS_GPIOH.*/
  
#if TIVA_HAS_GPIOJ || defined(__DOXYGEN__)
  gpio_init(GPIOJ, &config->PJData);
#endif /* TIVA_HAS_GPIOJ.*/
  
#if TIVA_HAS_GPIOK || defined(__DOXYGEN__)
  gpio_init(GPIOK, &config->PKData);
#endif /* TIVA_HAS_GPIOK.*/
  
#if TIVA_HAS_GPIOL || defined(__DOXYGEN__)
  gpio_init(GPIOL, &config->PLData);
#endif /* TIVA_HAS_GPIOL.*/
  
#if TIVA_HAS_GPIOM || defined(__DOXYGEN__)
  gpio_init(GPIOM, &config->PMData);
#endif /* TIVA_HAS_GPIOM.*/
  
#if TIVA_HAS_GPION || defined(__DOXYGEN__)
  gpio_init(GPION, &config->PNData);
#endif /* TIVA_HAS_GPION.*/
  
#if TIVA_HAS_GPIOP || defined(__DOXYGEN__)
  gpio_init(GPIOP, &config->PPData);
#endif /* TIVA_HAS_GPIOP.*/
  
#if TIVA_HAS_GPIOQ || defined(__DOXYGEN__)
  gpio_init(GPIOQ, &config->PQData);
#endif /* TIVA_HAS_GPIOQ.*/

#if TIVA_HAS_GPIOR || defined(__DOXYGEN__)
  gpio_init(GPIOR, &config->PRData);
#endif /* TIVA_HAS_GPIOR.*/

#if TIVA_HAS_GPIOS || defined(__DOXYGEN__)
  gpio_init(GPIOS, &config->PSData);
#endif /* TIVA_HAS_GPIOS.*/

#if TIVA_HAS_GPIOT || defined(__DOXYGEN__)
  gpio_init(GPIOT, &config->PTData);
#endif /* TIVA_HAS_GPIOT.*/
}

/**
 * @brief   Pads mode setup.
 * @details This function programs a pads group belonging to the same port
 *          with the specified mode.
 *
 * @param[in] port      the port identifier
 * @param[in] mask      the group mask
 * @param[in] mode      the mode
 *
 * @notapi
 */
void _pal_lld_setgroupmode(ioportid_t port,
                           ioportmask_t mask,
                           iomode_t mode)
{
  /* TODO: What does this function exactly do? The pins are already configured
   * in board.h and initialized by the pal driver. */

  (void) port;
  (void) mask;
  (void) mode;

  /*
  switch (mode) {
  case PAL_MODE_UNCONNECTED:
  case PAL_MODE_INPUT_PULLUP:
    port->PUR |= mask;
  case PAL_MODE_INPUT:
    port->AFSEL &= ~mask;
    port->DIR &= ~mask;
    port->ODR &= ~mask;
    port->DEN |= mask;
    break;

  case PAL_MODE_INPUT_PULLDOWN:
    port->AFSEL &= ~mask;
    port->DIR &= ~mask;
    port->ODR &= ~mask;
    port->DEN |= mask;
    port->PDR |= mask;
    break;

  case PAL_MODE_RESET:
  case PAL_MODE_INPUT_ANALOG:
    port->AFSEL &= ~mask;
    port->DIR &= ~mask;
    port->ODR &= ~mask;
    port->DEN &= ~mask;
    port->PUR &= ~mask;
    port->PDR &= ~mask;
    break;

  case PAL_MODE_OUTPUT_PUSHPULL:
    port->AFSEL &= ~mask;
    port->DIR |= mask;
    port->ODR &= ~mask;
    port->DEN |= mask;
    break;

  case PAL_MODE_OUTPUT_OPENDRAIN:
    port->AFSEL &= ~mask;
    port->DIR |= mask;
    port->ODR |= mask;
    port->DEN |= mask;
    break;
  }*/
}

#endif /* HAL_USE_PAL */

/**
 * @}
 */
