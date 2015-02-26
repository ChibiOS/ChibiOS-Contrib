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

#define RCGCGPIO_MASK   (RCGCGPIOA | RCGCGPIOB | RCGCGPIOC | RCGCGPIOD |      \
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
  SYSCTL->RCGCGPIO = RCGCGPIO_MASK;

  /* Datasheet chapter 5.2.6: "There must be a delay of 3 system clocks after a
   * peripheral module clock is enabled in the RCGC register before any module
   * registers are accessed." */
  __NOP();
  __NOP();
  __NOP();
  
  gpio_init(GPIOA, &config->PAData);

  gpio_init(GPIOB, &config->PBData);

  /* Unlock pin 0, 1, 2 and 3 */
  GPIOC->LOCK = TIVA_GPIO_LOCK_PWD;
  GPIOC->CR = 0x0F;
  gpio_init(GPIOC, &config->PCData);
  GPIOC->LOCK = 0;

  /* Unlock pin 7 */
  GPIOD->LOCK = TIVA_GPIO_LOCK_PWD;
  GPIOD->CR = 0x80;
  gpio_init(GPIOD, &config->PDData);
  GPIOC->LOCK = 0;

  gpio_init(GPIOE, &config->PEData);

  /* Unlock pin 0 */
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
void _pal_lld_setgroupmode(ioportid_t port, ioportmask_t mask, iomode_t mode)
{
  uint32_t dir   = (mode & PAL_TIVA_DIR_MASK)   >> 0;
  uint32_t afsel = (mode & PAL_TIVA_AFSEL_MASK) >> 1;
  uint32_t dr2r  = (mode & PAL_TIVA_DR2R_MASK)  >> 2;
  uint32_t dr4r  = (mode & PAL_TIVA_DR4R_MASK)  >> 3;
  uint32_t dr8r  = (mode & PAL_TIVA_DR8R_MASK)  >> 4;
  uint32_t odr   = (mode & PAL_TIVA_ODR_MASK)   >> 5;
  uint32_t pur   = (mode & PAL_TIVA_PUR_MASK)   >> 6;
  uint32_t pdr   = (mode & PAL_TIVA_PDR_MASK)   >> 7;
  uint32_t slr   = (mode & PAL_TIVA_SLR_MASK)   >> 8;
  uint32_t den   = (mode & PAL_TIVA_DEN_MASK)   >> 9;
  uint32_t amsel = (mode & PAL_TIVA_AMSEL_MASK) >> 10;
  uint32_t pctl  = (mode & PAL_TIVA_PCTL_MASK)  >> 11;
  uint32_t bit   = 0;

  while(TRUE) {
    uint32_t pctl_mask = (7 << (4 * bit));
    uint32_t bit_mask = (1 << bit);

    if ((mask & 1) != 0) {
      port->DIR   = (port->DIR   & ~bit_mask)  | dir;
      port->AFSEL = (port->AFSEL & ~bit_mask)  | afsel;
      port->DR2R  = (port->DR2R  & ~bit_mask)  | dr2r;
      port->DR4R  = (port->DR4R  & ~bit_mask)  | dr4r;
      port->DR8R  = (port->DR8R  & ~bit_mask)  | dr8r;
      port->ODR   = (port->ODR   & ~bit_mask)  | odr;
      port->PUR   = (port->PUR   & ~bit_mask)  | pur;
      port->PDR   = (port->PDR   & ~bit_mask)  | pdr;
      port->SLR   = (port->SLR   & ~bit_mask)  | slr;
      port->DEN   = (port->DEN   & ~bit_mask)  | den;
      port->AMSEL = (port->AMSEL & ~bit_mask)  | amsel;
      port->PCTL  = (port->PCTL  & ~pctl_mask) | pctl;
    }

    mask >>= 1;
    if (!mask) {
      return;
    }

    dir   <<= 1;
    afsel <<= 1;
    dr2r  <<= 1;
    dr4r  <<= 1;
    dr8r  <<= 1;
    odr   <<= 1;
    pur   <<= 1;
    pdr   <<= 1;
    slr   <<= 1;
    den   <<= 1;
    amsel <<= 1;
    pctl  <<= 4;

    bit++;
  }
}

#endif /* HAL_USE_PAL */

/**
 * @}
 */
