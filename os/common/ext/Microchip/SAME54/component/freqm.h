/*
 * Component description for FREQM
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
#ifndef _SAME54_FREQM_COMPONENT_H_
#define _SAME54_FREQM_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR FREQM                                        */
/* ************************************************************************** */

/* -------- FREQM_CTRLA : (FREQM Offset: 0x00) (R/W 8) Control A Register -------- */
#define FREQM_CTRLA_RESETVALUE                _UINT8_(0x00)                                        /*  (FREQM_CTRLA) Control A Register  Reset Value */

#define FREQM_CTRLA_SWRST_Pos                 _UINT8_(0)                                           /* (FREQM_CTRLA) Software Reset Position */
#define FREQM_CTRLA_SWRST_Msk                 (_UINT8_(0x1) << FREQM_CTRLA_SWRST_Pos)              /* (FREQM_CTRLA) Software Reset Mask */
#define FREQM_CTRLA_SWRST(value)              (FREQM_CTRLA_SWRST_Msk & (_UINT8_(value) << FREQM_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the FREQM_CTRLA register */
#define FREQM_CTRLA_ENABLE_Pos                _UINT8_(1)                                           /* (FREQM_CTRLA) Enable Position */
#define FREQM_CTRLA_ENABLE_Msk                (_UINT8_(0x1) << FREQM_CTRLA_ENABLE_Pos)             /* (FREQM_CTRLA) Enable Mask */
#define FREQM_CTRLA_ENABLE(value)             (FREQM_CTRLA_ENABLE_Msk & (_UINT8_(value) << FREQM_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the FREQM_CTRLA register */
#define FREQM_CTRLA_Msk                       _UINT8_(0x03)                                        /* (FREQM_CTRLA) Register Mask  */


/* -------- FREQM_CTRLB : (FREQM Offset: 0x01) ( /W 8) Control B Register -------- */
#define FREQM_CTRLB_RESETVALUE                _UINT8_(0x00)                                        /*  (FREQM_CTRLB) Control B Register  Reset Value */

#define FREQM_CTRLB_START_Pos                 _UINT8_(0)                                           /* (FREQM_CTRLB) Start Measurement Position */
#define FREQM_CTRLB_START_Msk                 (_UINT8_(0x1) << FREQM_CTRLB_START_Pos)              /* (FREQM_CTRLB) Start Measurement Mask */
#define FREQM_CTRLB_START(value)              (FREQM_CTRLB_START_Msk & (_UINT8_(value) << FREQM_CTRLB_START_Pos)) /* Assigment of value for START in the FREQM_CTRLB register */
#define FREQM_CTRLB_Msk                       _UINT8_(0x01)                                        /* (FREQM_CTRLB) Register Mask  */


/* -------- FREQM_CFGA : (FREQM Offset: 0x02) (R/W 16) Config A register -------- */
#define FREQM_CFGA_RESETVALUE                 _UINT16_(0x00)                                       /*  (FREQM_CFGA) Config A register  Reset Value */

#define FREQM_CFGA_REFNUM_Pos                 _UINT16_(0)                                          /* (FREQM_CFGA) Number of Reference Clock Cycles Position */
#define FREQM_CFGA_REFNUM_Msk                 (_UINT16_(0xFF) << FREQM_CFGA_REFNUM_Pos)            /* (FREQM_CFGA) Number of Reference Clock Cycles Mask */
#define FREQM_CFGA_REFNUM(value)              (FREQM_CFGA_REFNUM_Msk & (_UINT16_(value) << FREQM_CFGA_REFNUM_Pos)) /* Assigment of value for REFNUM in the FREQM_CFGA register */
#define FREQM_CFGA_Msk                        _UINT16_(0x00FF)                                     /* (FREQM_CFGA) Register Mask  */


/* -------- FREQM_INTENCLR : (FREQM Offset: 0x08) (R/W 8) Interrupt Enable Clear Register -------- */
#define FREQM_INTENCLR_RESETVALUE             _UINT8_(0x00)                                        /*  (FREQM_INTENCLR) Interrupt Enable Clear Register  Reset Value */

#define FREQM_INTENCLR_DONE_Pos               _UINT8_(0)                                           /* (FREQM_INTENCLR) Measurement Done Interrupt Enable Position */
#define FREQM_INTENCLR_DONE_Msk               (_UINT8_(0x1) << FREQM_INTENCLR_DONE_Pos)            /* (FREQM_INTENCLR) Measurement Done Interrupt Enable Mask */
#define FREQM_INTENCLR_DONE(value)            (FREQM_INTENCLR_DONE_Msk & (_UINT8_(value) << FREQM_INTENCLR_DONE_Pos)) /* Assigment of value for DONE in the FREQM_INTENCLR register */
#define FREQM_INTENCLR_Msk                    _UINT8_(0x01)                                        /* (FREQM_INTENCLR) Register Mask  */


/* -------- FREQM_INTENSET : (FREQM Offset: 0x09) (R/W 8) Interrupt Enable Set Register -------- */
#define FREQM_INTENSET_RESETVALUE             _UINT8_(0x00)                                        /*  (FREQM_INTENSET) Interrupt Enable Set Register  Reset Value */

#define FREQM_INTENSET_DONE_Pos               _UINT8_(0)                                           /* (FREQM_INTENSET) Measurement Done Interrupt Enable Position */
#define FREQM_INTENSET_DONE_Msk               (_UINT8_(0x1) << FREQM_INTENSET_DONE_Pos)            /* (FREQM_INTENSET) Measurement Done Interrupt Enable Mask */
#define FREQM_INTENSET_DONE(value)            (FREQM_INTENSET_DONE_Msk & (_UINT8_(value) << FREQM_INTENSET_DONE_Pos)) /* Assigment of value for DONE in the FREQM_INTENSET register */
#define FREQM_INTENSET_Msk                    _UINT8_(0x01)                                        /* (FREQM_INTENSET) Register Mask  */


/* -------- FREQM_INTFLAG : (FREQM Offset: 0x0A) (R/W 8) Interrupt Flag Register -------- */
#define FREQM_INTFLAG_RESETVALUE              _UINT8_(0x00)                                        /*  (FREQM_INTFLAG) Interrupt Flag Register  Reset Value */

#define FREQM_INTFLAG_DONE_Pos                _UINT8_(0)                                           /* (FREQM_INTFLAG) Measurement Done Position */
#define FREQM_INTFLAG_DONE_Msk                (_UINT8_(0x1) << FREQM_INTFLAG_DONE_Pos)             /* (FREQM_INTFLAG) Measurement Done Mask */
#define FREQM_INTFLAG_DONE(value)             (FREQM_INTFLAG_DONE_Msk & (_UINT8_(value) << FREQM_INTFLAG_DONE_Pos)) /* Assigment of value for DONE in the FREQM_INTFLAG register */
#define FREQM_INTFLAG_Msk                     _UINT8_(0x01)                                        /* (FREQM_INTFLAG) Register Mask  */


/* -------- FREQM_STATUS : (FREQM Offset: 0x0B) (R/W 8) Status Register -------- */
#define FREQM_STATUS_RESETVALUE               _UINT8_(0x00)                                        /*  (FREQM_STATUS) Status Register  Reset Value */

#define FREQM_STATUS_BUSY_Pos                 _UINT8_(0)                                           /* (FREQM_STATUS) FREQM Status Position */
#define FREQM_STATUS_BUSY_Msk                 (_UINT8_(0x1) << FREQM_STATUS_BUSY_Pos)              /* (FREQM_STATUS) FREQM Status Mask */
#define FREQM_STATUS_BUSY(value)              (FREQM_STATUS_BUSY_Msk & (_UINT8_(value) << FREQM_STATUS_BUSY_Pos)) /* Assigment of value for BUSY in the FREQM_STATUS register */
#define FREQM_STATUS_OVF_Pos                  _UINT8_(1)                                           /* (FREQM_STATUS) Sticky Count Value Overflow Position */
#define FREQM_STATUS_OVF_Msk                  (_UINT8_(0x1) << FREQM_STATUS_OVF_Pos)               /* (FREQM_STATUS) Sticky Count Value Overflow Mask */
#define FREQM_STATUS_OVF(value)               (FREQM_STATUS_OVF_Msk & (_UINT8_(value) << FREQM_STATUS_OVF_Pos)) /* Assigment of value for OVF in the FREQM_STATUS register */
#define FREQM_STATUS_Msk                      _UINT8_(0x03)                                        /* (FREQM_STATUS) Register Mask  */


/* -------- FREQM_SYNCBUSY : (FREQM Offset: 0x0C) ( R/ 32) Synchronization Busy Register -------- */
#define FREQM_SYNCBUSY_RESETVALUE             _UINT32_(0x00)                                       /*  (FREQM_SYNCBUSY) Synchronization Busy Register  Reset Value */

#define FREQM_SYNCBUSY_SWRST_Pos              _UINT32_(0)                                          /* (FREQM_SYNCBUSY) Software Reset Position */
#define FREQM_SYNCBUSY_SWRST_Msk              (_UINT32_(0x1) << FREQM_SYNCBUSY_SWRST_Pos)          /* (FREQM_SYNCBUSY) Software Reset Mask */
#define FREQM_SYNCBUSY_SWRST(value)           (FREQM_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << FREQM_SYNCBUSY_SWRST_Pos)) /* Assigment of value for SWRST in the FREQM_SYNCBUSY register */
#define FREQM_SYNCBUSY_ENABLE_Pos             _UINT32_(1)                                          /* (FREQM_SYNCBUSY) Enable Position */
#define FREQM_SYNCBUSY_ENABLE_Msk             (_UINT32_(0x1) << FREQM_SYNCBUSY_ENABLE_Pos)         /* (FREQM_SYNCBUSY) Enable Mask */
#define FREQM_SYNCBUSY_ENABLE(value)          (FREQM_SYNCBUSY_ENABLE_Msk & (_UINT32_(value) << FREQM_SYNCBUSY_ENABLE_Pos)) /* Assigment of value for ENABLE in the FREQM_SYNCBUSY register */
#define FREQM_SYNCBUSY_Msk                    _UINT32_(0x00000003)                                 /* (FREQM_SYNCBUSY) Register Mask  */


/* -------- FREQM_VALUE : (FREQM Offset: 0x10) ( R/ 32) Count Value Register -------- */
#define FREQM_VALUE_RESETVALUE                _UINT32_(0x00)                                       /*  (FREQM_VALUE) Count Value Register  Reset Value */

#define FREQM_VALUE_VALUE_Pos                 _UINT32_(0)                                          /* (FREQM_VALUE) Measurement Value Position */
#define FREQM_VALUE_VALUE_Msk                 (_UINT32_(0xFFFFFF) << FREQM_VALUE_VALUE_Pos)        /* (FREQM_VALUE) Measurement Value Mask */
#define FREQM_VALUE_VALUE(value)              (FREQM_VALUE_VALUE_Msk & (_UINT32_(value) << FREQM_VALUE_VALUE_Pos)) /* Assigment of value for VALUE in the FREQM_VALUE register */
#define FREQM_VALUE_Msk                       _UINT32_(0x00FFFFFF)                                 /* (FREQM_VALUE) Register Mask  */


/** \brief FREQM register offsets definitions */
#define FREQM_CTRLA_REG_OFST           _UINT32_(0x00)      /* (FREQM_CTRLA) Control A Register Offset */
#define FREQM_CTRLB_REG_OFST           _UINT32_(0x01)      /* (FREQM_CTRLB) Control B Register Offset */
#define FREQM_CFGA_REG_OFST            _UINT32_(0x02)      /* (FREQM_CFGA) Config A register Offset */
#define FREQM_INTENCLR_REG_OFST        _UINT32_(0x08)      /* (FREQM_INTENCLR) Interrupt Enable Clear Register Offset */
#define FREQM_INTENSET_REG_OFST        _UINT32_(0x09)      /* (FREQM_INTENSET) Interrupt Enable Set Register Offset */
#define FREQM_INTFLAG_REG_OFST         _UINT32_(0x0A)      /* (FREQM_INTFLAG) Interrupt Flag Register Offset */
#define FREQM_STATUS_REG_OFST          _UINT32_(0x0B)      /* (FREQM_STATUS) Status Register Offset */
#define FREQM_SYNCBUSY_REG_OFST        _UINT32_(0x0C)      /* (FREQM_SYNCBUSY) Synchronization Busy Register Offset */
#define FREQM_VALUE_REG_OFST           _UINT32_(0x10)      /* (FREQM_VALUE) Count Value Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief FREQM register API structure */
typedef struct
{  /* Frequency Meter */
  __IO  uint8_t                        FREQM_CTRLA;        /**< Offset: 0x00 (R/W  8) Control A Register */
  __O   uint8_t                        FREQM_CTRLB;        /**< Offset: 0x01 ( /W  8) Control B Register */
  __IO  uint16_t                       FREQM_CFGA;         /**< Offset: 0x02 (R/W  16) Config A register */
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint8_t                        FREQM_INTENCLR;     /**< Offset: 0x08 (R/W  8) Interrupt Enable Clear Register */
  __IO  uint8_t                        FREQM_INTENSET;     /**< Offset: 0x09 (R/W  8) Interrupt Enable Set Register */
  __IO  uint8_t                        FREQM_INTFLAG;      /**< Offset: 0x0A (R/W  8) Interrupt Flag Register */
  __IO  uint8_t                        FREQM_STATUS;       /**< Offset: 0x0B (R/W  8) Status Register */
  __I   uint32_t                       FREQM_SYNCBUSY;     /**< Offset: 0x0C (R/   32) Synchronization Busy Register */
  __I   uint32_t                       FREQM_VALUE;        /**< Offset: 0x10 (R/   32) Count Value Register */
} freqm_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAME54_FREQM_COMPONENT_H_ */
