/*
 * Component description for PCC
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
#ifndef _SAME54_PCC_COMPONENT_H_
#define _SAME54_PCC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PCC                                          */
/* ************************************************************************** */

/* -------- PCC_MR : (PCC Offset: 0x00) (R/W 32) Mode Register -------- */
#define PCC_MR_RESETVALUE                     _UINT32_(0x00)                                       /*  (PCC_MR) Mode Register  Reset Value */

#define PCC_MR_PCEN_Pos                       _UINT32_(0)                                          /* (PCC_MR) Parallel Capture Enable Position */
#define PCC_MR_PCEN_Msk                       (_UINT32_(0x1) << PCC_MR_PCEN_Pos)                   /* (PCC_MR) Parallel Capture Enable Mask */
#define PCC_MR_PCEN(value)                    (PCC_MR_PCEN_Msk & (_UINT32_(value) << PCC_MR_PCEN_Pos)) /* Assigment of value for PCEN in the PCC_MR register */
#define PCC_MR_DSIZE_Pos                      _UINT32_(4)                                          /* (PCC_MR) Data size Position */
#define PCC_MR_DSIZE_Msk                      (_UINT32_(0x3) << PCC_MR_DSIZE_Pos)                  /* (PCC_MR) Data size Mask */
#define PCC_MR_DSIZE(value)                   (PCC_MR_DSIZE_Msk & (_UINT32_(value) << PCC_MR_DSIZE_Pos)) /* Assigment of value for DSIZE in the PCC_MR register */
#define   PCC_MR_DSIZE_1DATA_Val              _UINT32_(0x0)                                        /* (PCC_MR) 1 data is read in the PCC_RHR  */
#define   PCC_MR_DSIZE_2DATA_Val              _UINT32_(0x1)                                        /* (PCC_MR) 2 data is read in the PCC_RHR  */
#define   PCC_MR_DSIZE_4DATA_Val              _UINT32_(0x2)                                        /* (PCC_MR) 4 data are read in the PCC_RHR (only for 8 bits data size, ISIZE = 0)  */
#define PCC_MR_DSIZE_1DATA                    (PCC_MR_DSIZE_1DATA_Val << PCC_MR_DSIZE_Pos)         /* (PCC_MR) 1 data is read in the PCC_RHR Position  */
#define PCC_MR_DSIZE_2DATA                    (PCC_MR_DSIZE_2DATA_Val << PCC_MR_DSIZE_Pos)         /* (PCC_MR) 2 data is read in the PCC_RHR Position  */
#define PCC_MR_DSIZE_4DATA                    (PCC_MR_DSIZE_4DATA_Val << PCC_MR_DSIZE_Pos)         /* (PCC_MR) 4 data are read in the PCC_RHR (only for 8 bits data size, ISIZE = 0) Position  */
#define PCC_MR_SCALE_Pos                      _UINT32_(8)                                          /* (PCC_MR) Scale data Position */
#define PCC_MR_SCALE_Msk                      (_UINT32_(0x1) << PCC_MR_SCALE_Pos)                  /* (PCC_MR) Scale data Mask */
#define PCC_MR_SCALE(value)                   (PCC_MR_SCALE_Msk & (_UINT32_(value) << PCC_MR_SCALE_Pos)) /* Assigment of value for SCALE in the PCC_MR register */
#define PCC_MR_ALWYS_Pos                      _UINT32_(9)                                          /* (PCC_MR) Always Sampling Position */
#define PCC_MR_ALWYS_Msk                      (_UINT32_(0x1) << PCC_MR_ALWYS_Pos)                  /* (PCC_MR) Always Sampling Mask */
#define PCC_MR_ALWYS(value)                   (PCC_MR_ALWYS_Msk & (_UINT32_(value) << PCC_MR_ALWYS_Pos)) /* Assigment of value for ALWYS in the PCC_MR register */
#define PCC_MR_HALFS_Pos                      _UINT32_(10)                                         /* (PCC_MR) Half Sampling Position */
#define PCC_MR_HALFS_Msk                      (_UINT32_(0x1) << PCC_MR_HALFS_Pos)                  /* (PCC_MR) Half Sampling Mask */
#define PCC_MR_HALFS(value)                   (PCC_MR_HALFS_Msk & (_UINT32_(value) << PCC_MR_HALFS_Pos)) /* Assigment of value for HALFS in the PCC_MR register */
#define PCC_MR_FRSTS_Pos                      _UINT32_(11)                                         /* (PCC_MR) First sample Position */
#define PCC_MR_FRSTS_Msk                      (_UINT32_(0x1) << PCC_MR_FRSTS_Pos)                  /* (PCC_MR) First sample Mask */
#define PCC_MR_FRSTS(value)                   (PCC_MR_FRSTS_Msk & (_UINT32_(value) << PCC_MR_FRSTS_Pos)) /* Assigment of value for FRSTS in the PCC_MR register */
#define PCC_MR_ISIZE_Pos                      _UINT32_(16)                                         /* (PCC_MR) Input Data Size Position */
#define PCC_MR_ISIZE_Msk                      (_UINT32_(0x7) << PCC_MR_ISIZE_Pos)                  /* (PCC_MR) Input Data Size Mask */
#define PCC_MR_ISIZE(value)                   (PCC_MR_ISIZE_Msk & (_UINT32_(value) << PCC_MR_ISIZE_Pos)) /* Assigment of value for ISIZE in the PCC_MR register */
#define   PCC_MR_ISIZE_8BITS_Val              _UINT32_(0x0)                                        /* (PCC_MR) Input data bus size is 8 bits  */
#define   PCC_MR_ISIZE_10BITS_Val             _UINT32_(0x1)                                        /* (PCC_MR) Input data bus size is 10 bits  */
#define   PCC_MR_ISIZE_12BITS_Val             _UINT32_(0x2)                                        /* (PCC_MR) Input data bus size is 12 bits  */
#define   PCC_MR_ISIZE_14BITS_Val             _UINT32_(0x3)                                        /* (PCC_MR) Input data bus size is 14 bits  */
#define PCC_MR_ISIZE_8BITS                    (PCC_MR_ISIZE_8BITS_Val << PCC_MR_ISIZE_Pos)         /* (PCC_MR) Input data bus size is 8 bits Position  */
#define PCC_MR_ISIZE_10BITS                   (PCC_MR_ISIZE_10BITS_Val << PCC_MR_ISIZE_Pos)        /* (PCC_MR) Input data bus size is 10 bits Position  */
#define PCC_MR_ISIZE_12BITS                   (PCC_MR_ISIZE_12BITS_Val << PCC_MR_ISIZE_Pos)        /* (PCC_MR) Input data bus size is 12 bits Position  */
#define PCC_MR_ISIZE_14BITS                   (PCC_MR_ISIZE_14BITS_Val << PCC_MR_ISIZE_Pos)        /* (PCC_MR) Input data bus size is 14 bits Position  */
#define PCC_MR_CID_Pos                        _UINT32_(30)                                         /* (PCC_MR) Clear If Disabled Position */
#define PCC_MR_CID_Msk                        (_UINT32_(0x3) << PCC_MR_CID_Pos)                    /* (PCC_MR) Clear If Disabled Mask */
#define PCC_MR_CID(value)                     (PCC_MR_CID_Msk & (_UINT32_(value) << PCC_MR_CID_Pos)) /* Assigment of value for CID in the PCC_MR register */
#define PCC_MR_Msk                            _UINT32_(0xC0070F31)                                 /* (PCC_MR) Register Mask  */


/* -------- PCC_IER : (PCC Offset: 0x04) ( /W 32) Interrupt Enable Register -------- */
#define PCC_IER_RESETVALUE                    _UINT32_(0x00)                                       /*  (PCC_IER) Interrupt Enable Register  Reset Value */

#define PCC_IER_DRDY_Pos                      _UINT32_(0)                                          /* (PCC_IER) Data Ready Interrupt Enable Position */
#define PCC_IER_DRDY_Msk                      (_UINT32_(0x1) << PCC_IER_DRDY_Pos)                  /* (PCC_IER) Data Ready Interrupt Enable Mask */
#define PCC_IER_DRDY(value)                   (PCC_IER_DRDY_Msk & (_UINT32_(value) << PCC_IER_DRDY_Pos)) /* Assigment of value for DRDY in the PCC_IER register */
#define PCC_IER_OVRE_Pos                      _UINT32_(1)                                          /* (PCC_IER) Overrun Error Interrupt Enable Position */
#define PCC_IER_OVRE_Msk                      (_UINT32_(0x1) << PCC_IER_OVRE_Pos)                  /* (PCC_IER) Overrun Error Interrupt Enable Mask */
#define PCC_IER_OVRE(value)                   (PCC_IER_OVRE_Msk & (_UINT32_(value) << PCC_IER_OVRE_Pos)) /* Assigment of value for OVRE in the PCC_IER register */
#define PCC_IER_Msk                           _UINT32_(0x00000003)                                 /* (PCC_IER) Register Mask  */


/* -------- PCC_IDR : (PCC Offset: 0x08) ( /W 32) Interrupt Disable Register -------- */
#define PCC_IDR_RESETVALUE                    _UINT32_(0x00)                                       /*  (PCC_IDR) Interrupt Disable Register  Reset Value */

#define PCC_IDR_DRDY_Pos                      _UINT32_(0)                                          /* (PCC_IDR) Data Ready Interrupt Disable Position */
#define PCC_IDR_DRDY_Msk                      (_UINT32_(0x1) << PCC_IDR_DRDY_Pos)                  /* (PCC_IDR) Data Ready Interrupt Disable Mask */
#define PCC_IDR_DRDY(value)                   (PCC_IDR_DRDY_Msk & (_UINT32_(value) << PCC_IDR_DRDY_Pos)) /* Assigment of value for DRDY in the PCC_IDR register */
#define PCC_IDR_OVRE_Pos                      _UINT32_(1)                                          /* (PCC_IDR) Overrun Error Interrupt Disable Position */
#define PCC_IDR_OVRE_Msk                      (_UINT32_(0x1) << PCC_IDR_OVRE_Pos)                  /* (PCC_IDR) Overrun Error Interrupt Disable Mask */
#define PCC_IDR_OVRE(value)                   (PCC_IDR_OVRE_Msk & (_UINT32_(value) << PCC_IDR_OVRE_Pos)) /* Assigment of value for OVRE in the PCC_IDR register */
#define PCC_IDR_Msk                           _UINT32_(0x00000003)                                 /* (PCC_IDR) Register Mask  */


/* -------- PCC_IMR : (PCC Offset: 0x0C) ( R/ 32) Interrupt Mask Register -------- */
#define PCC_IMR_RESETVALUE                    _UINT32_(0x00)                                       /*  (PCC_IMR) Interrupt Mask Register  Reset Value */

#define PCC_IMR_DRDY_Pos                      _UINT32_(0)                                          /* (PCC_IMR) Data Ready Interrupt Mask Position */
#define PCC_IMR_DRDY_Msk                      (_UINT32_(0x1) << PCC_IMR_DRDY_Pos)                  /* (PCC_IMR) Data Ready Interrupt Mask Mask */
#define PCC_IMR_DRDY(value)                   (PCC_IMR_DRDY_Msk & (_UINT32_(value) << PCC_IMR_DRDY_Pos)) /* Assigment of value for DRDY in the PCC_IMR register */
#define PCC_IMR_OVRE_Pos                      _UINT32_(1)                                          /* (PCC_IMR) Overrun Error Interrupt Mask Position */
#define PCC_IMR_OVRE_Msk                      (_UINT32_(0x1) << PCC_IMR_OVRE_Pos)                  /* (PCC_IMR) Overrun Error Interrupt Mask Mask */
#define PCC_IMR_OVRE(value)                   (PCC_IMR_OVRE_Msk & (_UINT32_(value) << PCC_IMR_OVRE_Pos)) /* Assigment of value for OVRE in the PCC_IMR register */
#define PCC_IMR_Msk                           _UINT32_(0x00000003)                                 /* (PCC_IMR) Register Mask  */


/* -------- PCC_ISR : (PCC Offset: 0x10) ( R/ 32) Interrupt Status Register -------- */
#define PCC_ISR_RESETVALUE                    _UINT32_(0x00)                                       /*  (PCC_ISR) Interrupt Status Register  Reset Value */

#define PCC_ISR_DRDY_Pos                      _UINT32_(0)                                          /* (PCC_ISR) Data Ready Interrupt Status Position */
#define PCC_ISR_DRDY_Msk                      (_UINT32_(0x1) << PCC_ISR_DRDY_Pos)                  /* (PCC_ISR) Data Ready Interrupt Status Mask */
#define PCC_ISR_DRDY(value)                   (PCC_ISR_DRDY_Msk & (_UINT32_(value) << PCC_ISR_DRDY_Pos)) /* Assigment of value for DRDY in the PCC_ISR register */
#define PCC_ISR_OVRE_Pos                      _UINT32_(1)                                          /* (PCC_ISR) Overrun Error Interrupt Status Position */
#define PCC_ISR_OVRE_Msk                      (_UINT32_(0x1) << PCC_ISR_OVRE_Pos)                  /* (PCC_ISR) Overrun Error Interrupt Status Mask */
#define PCC_ISR_OVRE(value)                   (PCC_ISR_OVRE_Msk & (_UINT32_(value) << PCC_ISR_OVRE_Pos)) /* Assigment of value for OVRE in the PCC_ISR register */
#define PCC_ISR_Msk                           _UINT32_(0x00000003)                                 /* (PCC_ISR) Register Mask  */


/* -------- PCC_RHR : (PCC Offset: 0x14) ( R/ 32) Reception Holding Register -------- */
#define PCC_RHR_RESETVALUE                    _UINT32_(0x00)                                       /*  (PCC_RHR) Reception Holding Register  Reset Value */

#define PCC_RHR_RDATA_Pos                     _UINT32_(0)                                          /* (PCC_RHR) Reception Data Position */
#define PCC_RHR_RDATA_Msk                     (_UINT32_(0xFFFFFFFF) << PCC_RHR_RDATA_Pos)          /* (PCC_RHR) Reception Data Mask */
#define PCC_RHR_RDATA(value)                  (PCC_RHR_RDATA_Msk & (_UINT32_(value) << PCC_RHR_RDATA_Pos)) /* Assigment of value for RDATA in the PCC_RHR register */
#define PCC_RHR_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (PCC_RHR) Register Mask  */


/* -------- PCC_WPMR : (PCC Offset: 0xE0) (R/W 32) Write Protection Mode Register -------- */
#define PCC_WPMR_RESETVALUE                   _UINT32_(0x00)                                       /*  (PCC_WPMR) Write Protection Mode Register  Reset Value */

#define PCC_WPMR_WPEN_Pos                     _UINT32_(0)                                          /* (PCC_WPMR) Write Protection Enable Position */
#define PCC_WPMR_WPEN_Msk                     (_UINT32_(0x1) << PCC_WPMR_WPEN_Pos)                 /* (PCC_WPMR) Write Protection Enable Mask */
#define PCC_WPMR_WPEN(value)                  (PCC_WPMR_WPEN_Msk & (_UINT32_(value) << PCC_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the PCC_WPMR register */
#define PCC_WPMR_WPKEY_Pos                    _UINT32_(8)                                          /* (PCC_WPMR) Write Protection Key Position */
#define PCC_WPMR_WPKEY_Msk                    (_UINT32_(0xFFFFFF) << PCC_WPMR_WPKEY_Pos)           /* (PCC_WPMR) Write Protection Key Mask */
#define PCC_WPMR_WPKEY(value)                 (PCC_WPMR_WPKEY_Msk & (_UINT32_(value) << PCC_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the PCC_WPMR register */
#define   PCC_WPMR_WPKEY_PASSWD_Val           _UINT32_(0x504343)                                   /* (PCC_WPMR) Write Protection Key  */
#define PCC_WPMR_WPKEY_PASSWD                 (PCC_WPMR_WPKEY_PASSWD_Val << PCC_WPMR_WPKEY_Pos)    /* (PCC_WPMR) Write Protection Key Position  */
#define PCC_WPMR_Msk                          _UINT32_(0xFFFFFF01)                                 /* (PCC_WPMR) Register Mask  */


/* -------- PCC_WPSR : (PCC Offset: 0xE4) ( R/ 32) Write Protection Status Register -------- */
#define PCC_WPSR_RESETVALUE                   _UINT32_(0x00)                                       /*  (PCC_WPSR) Write Protection Status Register  Reset Value */

#define PCC_WPSR_WPVS_Pos                     _UINT32_(0)                                          /* (PCC_WPSR) Write Protection Violation Source Position */
#define PCC_WPSR_WPVS_Msk                     (_UINT32_(0x1) << PCC_WPSR_WPVS_Pos)                 /* (PCC_WPSR) Write Protection Violation Source Mask */
#define PCC_WPSR_WPVS(value)                  (PCC_WPSR_WPVS_Msk & (_UINT32_(value) << PCC_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the PCC_WPSR register */
#define PCC_WPSR_WPVSRC_Pos                   _UINT32_(8)                                          /* (PCC_WPSR) Write Protection Violation Status Position */
#define PCC_WPSR_WPVSRC_Msk                   (_UINT32_(0xFFFF) << PCC_WPSR_WPVSRC_Pos)            /* (PCC_WPSR) Write Protection Violation Status Mask */
#define PCC_WPSR_WPVSRC(value)                (PCC_WPSR_WPVSRC_Msk & (_UINT32_(value) << PCC_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the PCC_WPSR register */
#define PCC_WPSR_Msk                          _UINT32_(0x00FFFF01)                                 /* (PCC_WPSR) Register Mask  */


/** \brief PCC register offsets definitions */
#define PCC_MR_REG_OFST                _UINT32_(0x00)      /* (PCC_MR) Mode Register Offset */
#define PCC_IER_REG_OFST               _UINT32_(0x04)      /* (PCC_IER) Interrupt Enable Register Offset */
#define PCC_IDR_REG_OFST               _UINT32_(0x08)      /* (PCC_IDR) Interrupt Disable Register Offset */
#define PCC_IMR_REG_OFST               _UINT32_(0x0C)      /* (PCC_IMR) Interrupt Mask Register Offset */
#define PCC_ISR_REG_OFST               _UINT32_(0x10)      /* (PCC_ISR) Interrupt Status Register Offset */
#define PCC_RHR_REG_OFST               _UINT32_(0x14)      /* (PCC_RHR) Reception Holding Register Offset */
#define PCC_WPMR_REG_OFST              _UINT32_(0xE0)      /* (PCC_WPMR) Write Protection Mode Register Offset */
#define PCC_WPSR_REG_OFST              _UINT32_(0xE4)      /* (PCC_WPSR) Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PCC register API structure */
typedef struct
{  /* Parallel Capture Controller */
  __IO  uint32_t                       PCC_MR;             /**< Offset: 0x00 (R/W  32) Mode Register */
  __O   uint32_t                       PCC_IER;            /**< Offset: 0x04 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       PCC_IDR;            /**< Offset: 0x08 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       PCC_IMR;            /**< Offset: 0x0C (R/   32) Interrupt Mask Register */
  __I   uint32_t                       PCC_ISR;            /**< Offset: 0x10 (R/   32) Interrupt Status Register */
  __I   uint32_t                       PCC_RHR;            /**< Offset: 0x14 (R/   32) Reception Holding Register */
  __I   uint8_t                        Reserved1[0xC8];
  __IO  uint32_t                       PCC_WPMR;           /**< Offset: 0xE0 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       PCC_WPSR;           /**< Offset: 0xE4 (R/   32) Write Protection Status Register */
} pcc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAME54_PCC_COMPONENT_H_ */
