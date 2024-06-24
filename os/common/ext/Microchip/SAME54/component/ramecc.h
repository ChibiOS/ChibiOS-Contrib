/*
 * Component description for RAMECC
 *
 * Copyright (c) 2024 Microchip Technology Inc. and its subsidiaries.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/* file generated from device description file (ATDF) version 2023-03-17T09:50:08Z */
#ifndef _SAME54_RAMECC_COMPONENT_H_
#define _SAME54_RAMECC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR RAMECC                                       */
/* ************************************************************************** */

/* -------- RAMECC_INTENCLR : (RAMECC Offset: 0x00) (R/W 8) Interrupt Enable Clear -------- */
#define RAMECC_INTENCLR_RESETVALUE            _UINT8_(0x00)                                        /*  (RAMECC_INTENCLR) Interrupt Enable Clear  Reset Value */

#define RAMECC_INTENCLR_SINGLEE_Pos           _UINT8_(0)                                           /* (RAMECC_INTENCLR) Single Bit ECC Error Interrupt Enable Clear Position */
#define RAMECC_INTENCLR_SINGLEE_Msk           (_UINT8_(0x1) << RAMECC_INTENCLR_SINGLEE_Pos)        /* (RAMECC_INTENCLR) Single Bit ECC Error Interrupt Enable Clear Mask */
#define RAMECC_INTENCLR_SINGLEE(value)        (RAMECC_INTENCLR_SINGLEE_Msk & (_UINT8_(value) << RAMECC_INTENCLR_SINGLEE_Pos)) /* Assigment of value for SINGLEE in the RAMECC_INTENCLR register */
#define RAMECC_INTENCLR_DUALE_Pos             _UINT8_(1)                                           /* (RAMECC_INTENCLR) Dual Bit ECC Error Interrupt Enable Clear Position */
#define RAMECC_INTENCLR_DUALE_Msk             (_UINT8_(0x1) << RAMECC_INTENCLR_DUALE_Pos)          /* (RAMECC_INTENCLR) Dual Bit ECC Error Interrupt Enable Clear Mask */
#define RAMECC_INTENCLR_DUALE(value)          (RAMECC_INTENCLR_DUALE_Msk & (_UINT8_(value) << RAMECC_INTENCLR_DUALE_Pos)) /* Assigment of value for DUALE in the RAMECC_INTENCLR register */
#define RAMECC_INTENCLR_Msk                   _UINT8_(0x03)                                        /* (RAMECC_INTENCLR) Register Mask  */


/* -------- RAMECC_INTENSET : (RAMECC Offset: 0x01) (R/W 8) Interrupt Enable Set -------- */
#define RAMECC_INTENSET_RESETVALUE            _UINT8_(0x00)                                        /*  (RAMECC_INTENSET) Interrupt Enable Set  Reset Value */

#define RAMECC_INTENSET_SINGLEE_Pos           _UINT8_(0)                                           /* (RAMECC_INTENSET) Single Bit ECC Error Interrupt Enable Set Position */
#define RAMECC_INTENSET_SINGLEE_Msk           (_UINT8_(0x1) << RAMECC_INTENSET_SINGLEE_Pos)        /* (RAMECC_INTENSET) Single Bit ECC Error Interrupt Enable Set Mask */
#define RAMECC_INTENSET_SINGLEE(value)        (RAMECC_INTENSET_SINGLEE_Msk & (_UINT8_(value) << RAMECC_INTENSET_SINGLEE_Pos)) /* Assigment of value for SINGLEE in the RAMECC_INTENSET register */
#define RAMECC_INTENSET_DUALE_Pos             _UINT8_(1)                                           /* (RAMECC_INTENSET) Dual Bit ECC Error Interrupt Enable Set Position */
#define RAMECC_INTENSET_DUALE_Msk             (_UINT8_(0x1) << RAMECC_INTENSET_DUALE_Pos)          /* (RAMECC_INTENSET) Dual Bit ECC Error Interrupt Enable Set Mask */
#define RAMECC_INTENSET_DUALE(value)          (RAMECC_INTENSET_DUALE_Msk & (_UINT8_(value) << RAMECC_INTENSET_DUALE_Pos)) /* Assigment of value for DUALE in the RAMECC_INTENSET register */
#define RAMECC_INTENSET_Msk                   _UINT8_(0x03)                                        /* (RAMECC_INTENSET) Register Mask  */


/* -------- RAMECC_INTFLAG : (RAMECC Offset: 0x02) (R/W 8) Interrupt Flag -------- */
#define RAMECC_INTFLAG_RESETVALUE             _UINT8_(0x00)                                        /*  (RAMECC_INTFLAG) Interrupt Flag  Reset Value */

#define RAMECC_INTFLAG_SINGLEE_Pos            _UINT8_(0)                                           /* (RAMECC_INTFLAG) Single Bit ECC Error Interrupt Position */
#define RAMECC_INTFLAG_SINGLEE_Msk            (_UINT8_(0x1) << RAMECC_INTFLAG_SINGLEE_Pos)         /* (RAMECC_INTFLAG) Single Bit ECC Error Interrupt Mask */
#define RAMECC_INTFLAG_SINGLEE(value)         (RAMECC_INTFLAG_SINGLEE_Msk & (_UINT8_(value) << RAMECC_INTFLAG_SINGLEE_Pos)) /* Assigment of value for SINGLEE in the RAMECC_INTFLAG register */
#define RAMECC_INTFLAG_DUALE_Pos              _UINT8_(1)                                           /* (RAMECC_INTFLAG) Dual Bit ECC Error Interrupt Position */
#define RAMECC_INTFLAG_DUALE_Msk              (_UINT8_(0x1) << RAMECC_INTFLAG_DUALE_Pos)           /* (RAMECC_INTFLAG) Dual Bit ECC Error Interrupt Mask */
#define RAMECC_INTFLAG_DUALE(value)           (RAMECC_INTFLAG_DUALE_Msk & (_UINT8_(value) << RAMECC_INTFLAG_DUALE_Pos)) /* Assigment of value for DUALE in the RAMECC_INTFLAG register */
#define RAMECC_INTFLAG_Msk                    _UINT8_(0x03)                                        /* (RAMECC_INTFLAG) Register Mask  */


/* -------- RAMECC_STATUS : (RAMECC Offset: 0x03) ( R/ 8) Status -------- */
#define RAMECC_STATUS_RESETVALUE              _UINT8_(0x00)                                        /*  (RAMECC_STATUS) Status  Reset Value */

#define RAMECC_STATUS_ECCDIS_Pos              _UINT8_(0)                                           /* (RAMECC_STATUS) ECC Disable Position */
#define RAMECC_STATUS_ECCDIS_Msk              (_UINT8_(0x1) << RAMECC_STATUS_ECCDIS_Pos)           /* (RAMECC_STATUS) ECC Disable Mask */
#define RAMECC_STATUS_ECCDIS(value)           (RAMECC_STATUS_ECCDIS_Msk & (_UINT8_(value) << RAMECC_STATUS_ECCDIS_Pos)) /* Assigment of value for ECCDIS in the RAMECC_STATUS register */
#define RAMECC_STATUS_Msk                     _UINT8_(0x01)                                        /* (RAMECC_STATUS) Register Mask  */


/* -------- RAMECC_ERRADDR : (RAMECC Offset: 0x04) ( R/ 32) Error Address -------- */
#define RAMECC_ERRADDR_RESETVALUE             _UINT32_(0x00)                                       /*  (RAMECC_ERRADDR) Error Address  Reset Value */

#define RAMECC_ERRADDR_ERRADDR_Pos            _UINT32_(0)                                          /* (RAMECC_ERRADDR) Error Address Position */
#define RAMECC_ERRADDR_ERRADDR_Msk            (_UINT32_(0x1FFFF) << RAMECC_ERRADDR_ERRADDR_Pos)    /* (RAMECC_ERRADDR) Error Address Mask */
#define RAMECC_ERRADDR_ERRADDR(value)         (RAMECC_ERRADDR_ERRADDR_Msk & (_UINT32_(value) << RAMECC_ERRADDR_ERRADDR_Pos)) /* Assigment of value for ERRADDR in the RAMECC_ERRADDR register */
#define RAMECC_ERRADDR_Msk                    _UINT32_(0x0001FFFF)                                 /* (RAMECC_ERRADDR) Register Mask  */


/* -------- RAMECC_DBGCTRL : (RAMECC Offset: 0x0F) (R/W 8) Debug Control -------- */
#define RAMECC_DBGCTRL_RESETVALUE             _UINT8_(0x00)                                        /*  (RAMECC_DBGCTRL) Debug Control  Reset Value */

#define RAMECC_DBGCTRL_ECCDIS_Pos             _UINT8_(0)                                           /* (RAMECC_DBGCTRL) ECC Disable Position */
#define RAMECC_DBGCTRL_ECCDIS_Msk             (_UINT8_(0x1) << RAMECC_DBGCTRL_ECCDIS_Pos)          /* (RAMECC_DBGCTRL) ECC Disable Mask */
#define RAMECC_DBGCTRL_ECCDIS(value)          (RAMECC_DBGCTRL_ECCDIS_Msk & (_UINT8_(value) << RAMECC_DBGCTRL_ECCDIS_Pos)) /* Assigment of value for ECCDIS in the RAMECC_DBGCTRL register */
#define RAMECC_DBGCTRL_ECCELOG_Pos            _UINT8_(1)                                           /* (RAMECC_DBGCTRL) ECC Error Log Position */
#define RAMECC_DBGCTRL_ECCELOG_Msk            (_UINT8_(0x1) << RAMECC_DBGCTRL_ECCELOG_Pos)         /* (RAMECC_DBGCTRL) ECC Error Log Mask */
#define RAMECC_DBGCTRL_ECCELOG(value)         (RAMECC_DBGCTRL_ECCELOG_Msk & (_UINT8_(value) << RAMECC_DBGCTRL_ECCELOG_Pos)) /* Assigment of value for ECCELOG in the RAMECC_DBGCTRL register */
#define RAMECC_DBGCTRL_Msk                    _UINT8_(0x03)                                        /* (RAMECC_DBGCTRL) Register Mask  */


/** \brief RAMECC register offsets definitions */
#define RAMECC_INTENCLR_REG_OFST       _UINT32_(0x00)      /* (RAMECC_INTENCLR) Interrupt Enable Clear Offset */
#define RAMECC_INTENSET_REG_OFST       _UINT32_(0x01)      /* (RAMECC_INTENSET) Interrupt Enable Set Offset */
#define RAMECC_INTFLAG_REG_OFST        _UINT32_(0x02)      /* (RAMECC_INTFLAG) Interrupt Flag Offset */
#define RAMECC_STATUS_REG_OFST         _UINT32_(0x03)      /* (RAMECC_STATUS) Status Offset */
#define RAMECC_ERRADDR_REG_OFST        _UINT32_(0x04)      /* (RAMECC_ERRADDR) Error Address Offset */
#define RAMECC_DBGCTRL_REG_OFST        _UINT32_(0x0F)      /* (RAMECC_DBGCTRL) Debug Control Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief RAMECC register API structure */
typedef struct
{  /* RAM ECC */
  __IO  uint8_t                        RAMECC_INTENCLR;    /**< Offset: 0x00 (R/W  8) Interrupt Enable Clear */
  __IO  uint8_t                        RAMECC_INTENSET;    /**< Offset: 0x01 (R/W  8) Interrupt Enable Set */
  __IO  uint8_t                        RAMECC_INTFLAG;     /**< Offset: 0x02 (R/W  8) Interrupt Flag */
  __I   uint8_t                        RAMECC_STATUS;      /**< Offset: 0x03 (R/   8) Status */
  __I   uint32_t                       RAMECC_ERRADDR;     /**< Offset: 0x04 (R/   32) Error Address */
  __I   uint8_t                        Reserved1[0x07];
  __IO  uint8_t                        RAMECC_DBGCTRL;     /**< Offset: 0x0F (R/W  8) Debug Control */
} ramecc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAME54_RAMECC_COMPONENT_H_ */
