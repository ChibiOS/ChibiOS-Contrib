/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian

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
 * @file    TMRv1/at32_tmr.h
 * @brief   AT32 TMR units common header.
 * @note    This file requires definitions from the AT AT32 header file.
 *
 * @addtogroup AT32_TMRv1
 * @{
 */

#ifndef AT32_TMR_H
#define AT32_TMR_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    TMR_CTRL1 register
 * @{
 */
#define AT32_TMR_CTRL1_TMREN                (1U << 0)
#define AT32_TMR_CTRL1_OVFEN                (1U << 1)
#define AT32_TMR_CTRL1_OVFS                 (1U << 2)
#define AT32_TMR_CTRL1_OCMEN                (1U << 3)
#define AT32_TMR_CTRL1_OWCDIR               (1U << 4)

#define AT32_TMR_CTRL1_TWCMSEL_MASK         (3U << 5)
#define AT32_TMR_CTRL1_TWCMSEL(n)           ((n) << 5)

#define AT32_TMR_CTRL1_PRBEN                (1U << 7)

#define AT32_TMR_CTRL1_CLKDIV_MASK          (3U << 8)
#define AT32_TMR_CTRL1_CLKDIV(n)            ((n) << 8)

#define AT32_TMR_CTRL1_PMEN                 (1U << 10)
/** @} */

/**
 * @name    TMR_CTRL2 register
 * @{
 */
#define AT32_TMR_CTRL2_CBCTRL               (1U << 0)
#define AT32_TMR_CTRL2_CCFS                 (1U << 2)
#define AT32_TMR_CTRL2_DRS                  (1U << 3)

#define AT32_TMR_CTRL2_PTOS_MASK            (7U << 4)
#define AT32_TMR_CTRL2_PTOS(n)              ((n) << 4)

#define AT32_TMR_CTRL2_C1INSEL              (1U << 7)
#define AT32_TMR_CTRL2_C1IOS                (1U << 8)
#define AT32_TMR_CTRL2_C1CIOS               (1U << 9)
#define AT32_TMR_CTRL2_C2IOS                (1U << 10)
#define AT32_TMR_CTRL2_C2CIOS               (1U << 11)
#define AT32_TMR_CTRL2_C3IOS                (1U << 12)
#define AT32_TMR_CTRL2_C3CIOS               (1U << 13)
#define AT32_TMR_CTRL2_C4IOS                (1U << 14)
/** @} */

/**
 * @name    TMR_STCTRL register
 * @{
 */
#define AT32_TMR_STCTRL_SMSEL_MASK          (7U << 0)
#define AT32_TMR_STCTRL_SMSEL(n)            ((n) << 0)

#define AT32_TMR_STCTRL_COSSEL              (1U << 3)

#define AT32_TMR_STCTRL_STIS_MASK           (7U << 4)
#define AT32_TMR_STCTRL_STIS(n)             ((n) << 4)

#define AT32_TMR_STCTRL_STS                 (1U << 7)

#define AT32_TMR_STCTRL_ESF_MASK            (15U << 8)
#define AT32_TMR_STCTRL_ESF(n)              ((n) << 8)

#define AT32_TMR_STCTRL_ESDIV_MASK          (3U << 12)
#define AT32_TMR_STCTRL_ESDIV(n)            ((n) << 12)

#define AT32_TMR_STCTRL_ECMBEN              (1U << 14)
#define AT32_TMR_STCTRL_ESP                 (1U << 15)
/** @} */

/**
 * @name    TMR_IDEN register
 * @{
 */
#define AT32_TMR_IDEN_OVFIEN                (1U << 0)
#define AT32_TMR_IDEN_C1IEN                 (1U << 1)
#define AT32_TMR_IDEN_C2IEN                 (1U << 2)
#define AT32_TMR_IDEN_C3IEN                 (1U << 3)
#define AT32_TMR_IDEN_C4IEN                 (1U << 4)
#define AT32_TMR_IDEN_HALLIEN               (1U << 5)
#define AT32_TMR_IDEN_TIEN                  (1U << 6)
#define AT32_TMR_IDEN_BRKIE                 (1U << 7)
#define AT32_TMR_IDEN_OVFDEN                (1U << 8)
#define AT32_TMR_IDEN_C1DEN                 (1U << 9)
#define AT32_TMR_IDEN_C2DEN                 (1U << 10)
#define AT32_TMR_IDEN_C3DEN                 (1U << 11)
#define AT32_TMR_IDEN_C4DEN                 (1U << 12)
#define AT32_TMR_IDEN_HALLDE                (1U << 13)
#define AT32_TMR_IDEN_TDEN                  (1U << 14)

#define AT32_TMR_IDEN_IRQ_MASK              (AT32_TMR_IDEN_OVFIEN  |        \
                                             AT32_TMR_IDEN_C1IEN   |        \
                                             AT32_TMR_IDEN_C2IEN   |        \
                                             AT32_TMR_IDEN_C3IEN   |        \
                                             AT32_TMR_IDEN_C4IEN   |        \
                                             AT32_TMR_IDEN_HALLIEN |        \
                                             AT32_TMR_IDEN_TIEN    |        \
                                             AT32_TMR_IDEN_BRKIE)

/** @} */

/**
 * @name    TMR_ISTS register
 * @{
 */
#define AT32_TMR_ISTS_OVFIF                 (1U << 0)
#define AT32_TMR_ISTS_C1IF                  (1U << 1)
#define AT32_TMR_ISTS_C2IF                  (1U << 2)
#define AT32_TMR_ISTS_C3IF                  (1U << 3)
#define AT32_TMR_ISTS_C4IF                  (1U << 4)
#define AT32_TMR_ISTS_HALLIF                (1U << 5)
#define AT32_TMR_ISTS_TRGIF                 (1U << 6)
#define AT32_TMR_ISTS_BRKIF                 (1U << 7)
#define AT32_TMR_ISTS_C1RF                  (1U << 9)
#define AT32_TMR_ISTS_C2RF                  (1U << 10)
#define AT32_TMR_ISTS_C3RF                  (1U << 11)
#define AT32_TMR_ISTS_C4RF                  (1U << 12)
/** @} */

/**
 * @name    TMR_SWEVT register
 * @{
 */
#define AT32_TMR_SWEVT_OVFSWTR              (1U << 0)
#define AT32_TMR_SWEVT_C1SWTR               (1U << 1)
#define AT32_TMR_SWEVT_C2SWTR               (1U << 2)
#define AT32_TMR_SWEVT_C3SWTR               (1U << 3)
#define AT32_TMR_SWEVT_C4SWTR               (1U << 4)
#define AT32_TMR_SWEVT_HALLSWTR             (1U << 5)
#define AT32_TMR_SWEVT_TRGSWTR              (1U << 6)
#define AT32_TMR_SWEVT_BRKSWTR              (1U << 7)
/** @} */

/**
 * @name    TMR_CM1 register (output)
 * @{
 */
#define AT32_TMR_CM1_C1C_MASK               (3U << 0)
#define AT32_TMR_CM1_C1C(n)                 ((n) << 0)

#define AT32_TMR_CM1_C1OIEN                 (1U << 2)
#define AT32_TMR_CM1_C1OBEN                 (1U << 3)

#define AT32_TMR_CM1_C1OCTRL_MASK           (7U << 4)
#define AT32_TMR_CM1_C1OCTRL(n)             ((n) << 4)

#define AT32_TMR_CM1_C1OSEN                 (1U << 7)

#define AT32_TMR_CM1_C2C_MASK               (3U << 8)
#define AT32_TMR_CM1_C2C(n)                 ((n) << 8)

#define AT32_TMR_CM1_C2OIEN                 (1U << 10)
#define AT32_TMR_CM1_C2OBEN                 (1U << 11)

#define AT32_TMR_CM1_C2OCTRL_MASK           (7U << 12)
#define AT32_TMR_CM1_C2OCTRL(n)             ((n) << 12)

#define AT32_TMR_CM1_C2OSEN                 (1U << 15)
/** @} */

/**
 * @name    TMR_CM1 register (input)
 * @{
 */
#define AT32_TMR_CM1_C1IDIV_MASK            (3U << 2)
#define AT32_TMR_CM1_C1IDIV(n)              ((n) << 2)

#define AT32_TMR_CM1_C1DF_MASK              (15U << 4)
#define AT32_TMR_CM1_C1DF(n)                ((n) << 4)

#define AT32_TMR_CM1_C2IDIV_MASK            (3U << 10)
#define AT32_TMR_CM1_C2IDIV(n)              ((n) << 10)

#define AT32_TMR_CM1_C2DF_MASK              (15U << 12)
#define AT32_TMR_CM1_C2DF(n)                ((n) << 12)
/** @} */

/**
 * @name    TMR_CM2 register (output)
 * @{
 */
#define AT32_TMR_CM2_C3C_MASK               (3U << 0)
#define AT32_TMR_CM2_C3C(n)                 ((n) << 0)

#define AT32_TMR_CM2_C3OIEN                 (1U << 2)
#define AT32_TMR_CM2_C3OBEN                 (1U << 3)

#define AT32_TMR_CM2_C3OCTRL_MASK           (7U << 4)
#define AT32_TMR_CM2_C3OCTRL(n)             ((n) << 4)

#define AT32_TMR_CM2_C3OSEN                 (1U << 7)

#define AT32_TMR_CM2_C4C_MASK               (3U << 8)
#define AT32_TMR_CM2_C4C(n)                 ((n) << 8)

#define AT32_TMR_CM2_C4OIEN                 (1U << 10)
#define AT32_TMR_CM2_C4OBEN                 (1U << 11)

#define AT32_TMR_CM2_C4OCTRL_MASK           (7U << 12)
#define AT32_TMR_CM2_C4OCTRL(n)             ((n) << 12)

#define AT32_TMR_CM2_C4OSEN                 (1U << 15)
/** @} */

/**
 * @name    TMR_CM2 register (input)
 * @{
 */
#define AT32_TMR_CM2_C3IDIV_MASK            (3U << 2)
#define AT32_TMR_CM2_C3IDIV(n)              ((n) << 2)

#define AT32_TMR_CM2_C3DF_MASK              (15U << 4)
#define AT32_TMR_CM2_C3DF(n)                ((n) << 4)

#define AT32_TMR_CM2_C4IDIV_MASK            (3U << 10)
#define AT32_TMR_CM2_C4IDIV(n)              ((n) << 10)

#define AT32_TMR_CM2_C4DF_MASK              (15U << 12)
#define AT32_TMR_CM2_C4DF(n)                ((n) << 12)
/** @} */

/**
 * @name    TMR_CCTRL register
 * @{
 */
#define AT32_TMR_CCTRL_C1EN                 (1U << 0)
#define AT32_TMR_CCTRL_C1P                  (1U << 1)
#define AT32_TMR_CCTRL_C1CEN                (1U << 2)
#define AT32_TMR_CCTRL_C1CP                 (1U << 3)
#define AT32_TMR_CCTRL_C2EN                 (1U << 4)
#define AT32_TMR_CCTRL_C2P                  (1U << 5)
#define AT32_TMR_CCTRL_C2CEN                (1U << 6)
#define AT32_TMR_CCTRL_C2CP                 (1U << 7)
#define AT32_TMR_CCTRL_C3EN                 (1U << 8)
#define AT32_TMR_CCTRL_C3P                  (1U << 9)
#define AT32_TMR_CCTRL_C3CEN                (1U << 10)
#define AT32_TMR_CCTRL_C3CP                 (1U << 11)
#define AT32_TMR_CCTRL_C4EN                 (1U << 12)
#define AT32_TMR_CCTRL_C4P                  (1U << 13)
/** @} */

/**
 * @name    TMR_BRK register
 * @{
 */
#define AT32_TMR_BRK_DTC_MASK               (255U << 0)
#define AT32_TMR_BRK_DTC(n)                 ((n) << 0)

#define AT32_TMR_BRK_WPC_MASK               (3U << 8)
#define AT32_TMR_BRK_WPC(n)                 ((n) << 8)

#define AT32_TMR_BRK_FCSODIS                (1U << 10)
#define AT32_TMR_BRK_FCSOEN                 (1U << 11)
#define AT32_TMR_BRK_BRKEN                  (1U << 12)
#define AT32_TMR_BRK_BRKV                   (1U << 13)
#define AT32_TMR_BRK_AOEN                   (1U << 14)
#define AT32_TMR_BRK_OEN                    (1U << 15)
/** @} */

/**
 * @name    TMR_DMACTRL register
 * @{
 */
#define AT32_TMR_DMACTRL_ADDR_MASK          (31U << 0)
#define AT32_TMR_DMACTRL_ADDR(n)            ((n) << 0)

#define AT32_TMR_DMACTRL_DTB_MASK           (31U << 8)
#define AT32_TMR_DMACTRL_DTB(n)             ((n) << 8)
/** @} */

/**
 * @name    TMR units references
 * @{
 */
#define AT32_TMR1       ((at32_tmr_t *)TMR1_BASE)
#define AT32_TMR2       ((at32_tmr_t *)TMR2_BASE)
#define AT32_TMR3       ((at32_tmr_t *)TMR3_BASE)
#define AT32_TMR4       ((at32_tmr_t *)TMR4_BASE)
#define AT32_TMR5       ((at32_tmr_t *)TMR5_BASE)
#define AT32_TMR9       ((at32_tmr_t *)TMR9_BASE)
#define AT32_TMR10      ((at32_tmr_t *)TMR10_BASE)
#define AT32_TMR11      ((at32_tmr_t *)TMR11_BASE)
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   AT32 TMR registers block.
 * @note    This is the most general known form, not all timers have
 *          necessarily all registers and bits.
 */
typedef struct {
  volatile uint32_t     CTRL1;
  volatile uint32_t     CTRL2;
  volatile uint32_t     STCTRL;
  volatile uint32_t     IDEN;
  volatile uint32_t     ISTS;
  volatile uint32_t     SWEVT;
  volatile uint32_t     CM1;
  volatile uint32_t     CM2;
  volatile uint32_t     CCTRL;
  volatile uint32_t     CVAL;
  volatile uint32_t     DIV;
  volatile uint32_t     PR;
  volatile uint32_t     RPR;
  volatile uint32_t     CDT[4];
  volatile uint32_t     BRK;
  volatile uint32_t     DMACTRL;
  volatile uint32_t     DMADT;
} at32_tmr_t;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#endif /* AT32_TMR_H */

/** @} */
