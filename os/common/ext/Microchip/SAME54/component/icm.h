/*
 * Component description for ICM
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
#ifndef _SAME54_ICM_COMPONENT_H_
#define _SAME54_ICM_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR ICM                                          */
/* ************************************************************************** */

/* -------- ICM_RADDR : (ICM Offset: 0x00) (R/W 32) Region Start Address -------- */
#define ICM_RADDR_Msk                         _UINT32_(0x00000000)                                 /* (ICM_RADDR) Register Mask  */


/* -------- ICM_RCFG : (ICM Offset: 0x04) (R/W 32) Region Configuration -------- */
#define ICM_RCFG_RESETVALUE                   _UINT32_(0x00)                                       /*  (ICM_RCFG) Region Configuration  Reset Value */

#define ICM_RCFG_CDWBN_Pos                    _UINT32_(0)                                          /* (ICM_RCFG) Compare Digest Write Back Position */
#define ICM_RCFG_CDWBN_Msk                    (_UINT32_(0x1) << ICM_RCFG_CDWBN_Pos)                /* (ICM_RCFG) Compare Digest Write Back Mask */
#define ICM_RCFG_CDWBN(value)                 (ICM_RCFG_CDWBN_Msk & (_UINT32_(value) << ICM_RCFG_CDWBN_Pos)) /* Assigment of value for CDWBN in the ICM_RCFG register */
#define   ICM_RCFG_CDWBN_WRBA_Val             _UINT32_(0x0)                                        /* (ICM_RCFG)   */
#define   ICM_RCFG_CDWBN_COMP_Val             _UINT32_(0x1)                                        /* (ICM_RCFG)   */
#define ICM_RCFG_CDWBN_WRBA                   (ICM_RCFG_CDWBN_WRBA_Val << ICM_RCFG_CDWBN_Pos)      /* (ICM_RCFG)  Position  */
#define ICM_RCFG_CDWBN_COMP                   (ICM_RCFG_CDWBN_COMP_Val << ICM_RCFG_CDWBN_Pos)      /* (ICM_RCFG)  Position  */
#define ICM_RCFG_WRAP_Pos                     _UINT32_(1)                                          /* (ICM_RCFG) Region Wrap Position */
#define ICM_RCFG_WRAP_Msk                     (_UINT32_(0x1) << ICM_RCFG_WRAP_Pos)                 /* (ICM_RCFG) Region Wrap Mask */
#define ICM_RCFG_WRAP(value)                  (ICM_RCFG_WRAP_Msk & (_UINT32_(value) << ICM_RCFG_WRAP_Pos)) /* Assigment of value for WRAP in the ICM_RCFG register */
#define   ICM_RCFG_WRAP_NO_Val                _UINT32_(0x0)                                        /* (ICM_RCFG)   */
#define   ICM_RCFG_WRAP_YES_Val               _UINT32_(0x1)                                        /* (ICM_RCFG)   */
#define ICM_RCFG_WRAP_NO                      (ICM_RCFG_WRAP_NO_Val << ICM_RCFG_WRAP_Pos)          /* (ICM_RCFG)  Position  */
#define ICM_RCFG_WRAP_YES                     (ICM_RCFG_WRAP_YES_Val << ICM_RCFG_WRAP_Pos)         /* (ICM_RCFG)  Position  */
#define ICM_RCFG_EOM_Pos                      _UINT32_(2)                                          /* (ICM_RCFG) End of Monitoring Position */
#define ICM_RCFG_EOM_Msk                      (_UINT32_(0x1) << ICM_RCFG_EOM_Pos)                  /* (ICM_RCFG) End of Monitoring Mask */
#define ICM_RCFG_EOM(value)                   (ICM_RCFG_EOM_Msk & (_UINT32_(value) << ICM_RCFG_EOM_Pos)) /* Assigment of value for EOM in the ICM_RCFG register */
#define   ICM_RCFG_EOM_NO_Val                 _UINT32_(0x0)                                        /* (ICM_RCFG)   */
#define   ICM_RCFG_EOM_YES_Val                _UINT32_(0x1)                                        /* (ICM_RCFG)   */
#define ICM_RCFG_EOM_NO                       (ICM_RCFG_EOM_NO_Val << ICM_RCFG_EOM_Pos)            /* (ICM_RCFG)  Position  */
#define ICM_RCFG_EOM_YES                      (ICM_RCFG_EOM_YES_Val << ICM_RCFG_EOM_Pos)           /* (ICM_RCFG)  Position  */
#define ICM_RCFG_RHIEN_Pos                    _UINT32_(4)                                          /* (ICM_RCFG) Region Hash Interrupt Enable Position */
#define ICM_RCFG_RHIEN_Msk                    (_UINT32_(0x1) << ICM_RCFG_RHIEN_Pos)                /* (ICM_RCFG) Region Hash Interrupt Enable Mask */
#define ICM_RCFG_RHIEN(value)                 (ICM_RCFG_RHIEN_Msk & (_UINT32_(value) << ICM_RCFG_RHIEN_Pos)) /* Assigment of value for RHIEN in the ICM_RCFG register */
#define   ICM_RCFG_RHIEN_EN_Val               _UINT32_(0x0)                                        /* (ICM_RCFG)   */
#define   ICM_RCFG_RHIEN_DIS_Val              _UINT32_(0x1)                                        /* (ICM_RCFG)   */
#define ICM_RCFG_RHIEN_EN                     (ICM_RCFG_RHIEN_EN_Val << ICM_RCFG_RHIEN_Pos)        /* (ICM_RCFG)  Position  */
#define ICM_RCFG_RHIEN_DIS                    (ICM_RCFG_RHIEN_DIS_Val << ICM_RCFG_RHIEN_Pos)       /* (ICM_RCFG)  Position  */
#define ICM_RCFG_DMIEN_Pos                    _UINT32_(5)                                          /* (ICM_RCFG) Region Digest Mismatch Interrupt Enable Position */
#define ICM_RCFG_DMIEN_Msk                    (_UINT32_(0x1) << ICM_RCFG_DMIEN_Pos)                /* (ICM_RCFG) Region Digest Mismatch Interrupt Enable Mask */
#define ICM_RCFG_DMIEN(value)                 (ICM_RCFG_DMIEN_Msk & (_UINT32_(value) << ICM_RCFG_DMIEN_Pos)) /* Assigment of value for DMIEN in the ICM_RCFG register */
#define   ICM_RCFG_DMIEN_EN_Val               _UINT32_(0x0)                                        /* (ICM_RCFG)   */
#define   ICM_RCFG_DMIEN_DIS_Val              _UINT32_(0x1)                                        /* (ICM_RCFG)   */
#define ICM_RCFG_DMIEN_EN                     (ICM_RCFG_DMIEN_EN_Val << ICM_RCFG_DMIEN_Pos)        /* (ICM_RCFG)  Position  */
#define ICM_RCFG_DMIEN_DIS                    (ICM_RCFG_DMIEN_DIS_Val << ICM_RCFG_DMIEN_Pos)       /* (ICM_RCFG)  Position  */
#define ICM_RCFG_BEIEN_Pos                    _UINT32_(6)                                          /* (ICM_RCFG) Region Bus Error Interrupt Enable Position */
#define ICM_RCFG_BEIEN_Msk                    (_UINT32_(0x1) << ICM_RCFG_BEIEN_Pos)                /* (ICM_RCFG) Region Bus Error Interrupt Enable Mask */
#define ICM_RCFG_BEIEN(value)                 (ICM_RCFG_BEIEN_Msk & (_UINT32_(value) << ICM_RCFG_BEIEN_Pos)) /* Assigment of value for BEIEN in the ICM_RCFG register */
#define   ICM_RCFG_BEIEN_EN_Val               _UINT32_(0x0)                                        /* (ICM_RCFG)   */
#define   ICM_RCFG_BEIEN_DIS_Val              _UINT32_(0x1)                                        /* (ICM_RCFG)   */
#define ICM_RCFG_BEIEN_EN                     (ICM_RCFG_BEIEN_EN_Val << ICM_RCFG_BEIEN_Pos)        /* (ICM_RCFG)  Position  */
#define ICM_RCFG_BEIEN_DIS                    (ICM_RCFG_BEIEN_DIS_Val << ICM_RCFG_BEIEN_Pos)       /* (ICM_RCFG)  Position  */
#define ICM_RCFG_WCIEN_Pos                    _UINT32_(7)                                          /* (ICM_RCFG) Region Wrap Condition Detected Interrupt Enable Position */
#define ICM_RCFG_WCIEN_Msk                    (_UINT32_(0x1) << ICM_RCFG_WCIEN_Pos)                /* (ICM_RCFG) Region Wrap Condition Detected Interrupt Enable Mask */
#define ICM_RCFG_WCIEN(value)                 (ICM_RCFG_WCIEN_Msk & (_UINT32_(value) << ICM_RCFG_WCIEN_Pos)) /* Assigment of value for WCIEN in the ICM_RCFG register */
#define   ICM_RCFG_WCIEN_EN_Val               _UINT32_(0x0)                                        /* (ICM_RCFG)   */
#define   ICM_RCFG_WCIEN_DIS_Val              _UINT32_(0x1)                                        /* (ICM_RCFG)   */
#define ICM_RCFG_WCIEN_EN                     (ICM_RCFG_WCIEN_EN_Val << ICM_RCFG_WCIEN_Pos)        /* (ICM_RCFG)  Position  */
#define ICM_RCFG_WCIEN_DIS                    (ICM_RCFG_WCIEN_DIS_Val << ICM_RCFG_WCIEN_Pos)       /* (ICM_RCFG)  Position  */
#define ICM_RCFG_ECIEN_Pos                    _UINT32_(8)                                          /* (ICM_RCFG) Region End bit Condition detected Interrupt Enable Position */
#define ICM_RCFG_ECIEN_Msk                    (_UINT32_(0x1) << ICM_RCFG_ECIEN_Pos)                /* (ICM_RCFG) Region End bit Condition detected Interrupt Enable Mask */
#define ICM_RCFG_ECIEN(value)                 (ICM_RCFG_ECIEN_Msk & (_UINT32_(value) << ICM_RCFG_ECIEN_Pos)) /* Assigment of value for ECIEN in the ICM_RCFG register */
#define   ICM_RCFG_ECIEN_EN_Val               _UINT32_(0x0)                                        /* (ICM_RCFG)   */
#define   ICM_RCFG_ECIEN_DIS_Val              _UINT32_(0x1)                                        /* (ICM_RCFG)   */
#define ICM_RCFG_ECIEN_EN                     (ICM_RCFG_ECIEN_EN_Val << ICM_RCFG_ECIEN_Pos)        /* (ICM_RCFG)  Position  */
#define ICM_RCFG_ECIEN_DIS                    (ICM_RCFG_ECIEN_DIS_Val << ICM_RCFG_ECIEN_Pos)       /* (ICM_RCFG)  Position  */
#define ICM_RCFG_SUIEN_Pos                    _UINT32_(9)                                          /* (ICM_RCFG) Region Status Updated Interrupt Enable Position */
#define ICM_RCFG_SUIEN_Msk                    (_UINT32_(0x1) << ICM_RCFG_SUIEN_Pos)                /* (ICM_RCFG) Region Status Updated Interrupt Enable Mask */
#define ICM_RCFG_SUIEN(value)                 (ICM_RCFG_SUIEN_Msk & (_UINT32_(value) << ICM_RCFG_SUIEN_Pos)) /* Assigment of value for SUIEN in the ICM_RCFG register */
#define   ICM_RCFG_SUIEN_EN_Val               _UINT32_(0x0)                                        /* (ICM_RCFG)   */
#define   ICM_RCFG_SUIEN_DIS_Val              _UINT32_(0x1)                                        /* (ICM_RCFG)   */
#define ICM_RCFG_SUIEN_EN                     (ICM_RCFG_SUIEN_EN_Val << ICM_RCFG_SUIEN_Pos)        /* (ICM_RCFG)  Position  */
#define ICM_RCFG_SUIEN_DIS                    (ICM_RCFG_SUIEN_DIS_Val << ICM_RCFG_SUIEN_Pos)       /* (ICM_RCFG)  Position  */
#define ICM_RCFG_PROCDLY_Pos                  _UINT32_(10)                                         /* (ICM_RCFG) SHA Processing Delay Position */
#define ICM_RCFG_PROCDLY_Msk                  (_UINT32_(0x1) << ICM_RCFG_PROCDLY_Pos)              /* (ICM_RCFG) SHA Processing Delay Mask */
#define ICM_RCFG_PROCDLY(value)               (ICM_RCFG_PROCDLY_Msk & (_UINT32_(value) << ICM_RCFG_PROCDLY_Pos)) /* Assigment of value for PROCDLY in the ICM_RCFG register */
#define   ICM_RCFG_PROCDLY_SHORT_Val          _UINT32_(0x0)                                        /* (ICM_RCFG)   */
#define   ICM_RCFG_PROCDLY_LONG_Val           _UINT32_(0x1)                                        /* (ICM_RCFG)   */
#define ICM_RCFG_PROCDLY_SHORT                (ICM_RCFG_PROCDLY_SHORT_Val << ICM_RCFG_PROCDLY_Pos) /* (ICM_RCFG)  Position  */
#define ICM_RCFG_PROCDLY_LONG                 (ICM_RCFG_PROCDLY_LONG_Val << ICM_RCFG_PROCDLY_Pos)  /* (ICM_RCFG)  Position  */
#define ICM_RCFG_ALGO_Pos                     _UINT32_(12)                                         /* (ICM_RCFG) SHA Algorithm Position */
#define ICM_RCFG_ALGO_Msk                     (_UINT32_(0x7) << ICM_RCFG_ALGO_Pos)                 /* (ICM_RCFG) SHA Algorithm Mask */
#define ICM_RCFG_ALGO(value)                  (ICM_RCFG_ALGO_Msk & (_UINT32_(value) << ICM_RCFG_ALGO_Pos)) /* Assigment of value for ALGO in the ICM_RCFG register */
#define ICM_RCFG_MRPROT_Pos                   _UINT32_(24)                                         /* (ICM_RCFG) Memory Region AHB Protection Position */
#define ICM_RCFG_MRPROT_Msk                   (_UINT32_(0x3F) << ICM_RCFG_MRPROT_Pos)              /* (ICM_RCFG) Memory Region AHB Protection Mask */
#define ICM_RCFG_MRPROT(value)                (ICM_RCFG_MRPROT_Msk & (_UINT32_(value) << ICM_RCFG_MRPROT_Pos)) /* Assigment of value for MRPROT in the ICM_RCFG register */
#define ICM_RCFG_Msk                          _UINT32_(0x3F0077F7)                                 /* (ICM_RCFG) Register Mask  */


/* -------- ICM_RCTRL : (ICM Offset: 0x08) (R/W 32) Region Control -------- */
#define ICM_RCTRL_TRSIZE_Pos                  _UINT32_(0)                                          /* (ICM_RCTRL) Transfer Size Position */
#define ICM_RCTRL_TRSIZE_Msk                  (_UINT32_(0xFFFF) << ICM_RCTRL_TRSIZE_Pos)           /* (ICM_RCTRL) Transfer Size Mask */
#define ICM_RCTRL_TRSIZE(value)               (ICM_RCTRL_TRSIZE_Msk & (_UINT32_(value) << ICM_RCTRL_TRSIZE_Pos)) /* Assigment of value for TRSIZE in the ICM_RCTRL register */
#define ICM_RCTRL_Msk                         _UINT32_(0x0000FFFF)                                 /* (ICM_RCTRL) Register Mask  */


/* -------- ICM_RNEXT : (ICM Offset: 0x0C) (R/W 32) Region Next Address -------- */
#define ICM_RNEXT_Msk                         _UINT32_(0x00000000)                                 /* (ICM_RNEXT) Register Mask  */


/* -------- ICM_CFG : (ICM Offset: 0x00) (R/W 32) Configuration -------- */
#define ICM_CFG_RESETVALUE                    _UINT32_(0x00)                                       /*  (ICM_CFG) Configuration  Reset Value */

#define ICM_CFG_WBDIS_Pos                     _UINT32_(0)                                          /* (ICM_CFG) Write Back Disable Position */
#define ICM_CFG_WBDIS_Msk                     (_UINT32_(0x1) << ICM_CFG_WBDIS_Pos)                 /* (ICM_CFG) Write Back Disable Mask */
#define ICM_CFG_WBDIS(value)                  (ICM_CFG_WBDIS_Msk & (_UINT32_(value) << ICM_CFG_WBDIS_Pos)) /* Assigment of value for WBDIS in the ICM_CFG register */
#define ICM_CFG_EOMDIS_Pos                    _UINT32_(1)                                          /* (ICM_CFG) End of Monitoring Disable Position */
#define ICM_CFG_EOMDIS_Msk                    (_UINT32_(0x1) << ICM_CFG_EOMDIS_Pos)                /* (ICM_CFG) End of Monitoring Disable Mask */
#define ICM_CFG_EOMDIS(value)                 (ICM_CFG_EOMDIS_Msk & (_UINT32_(value) << ICM_CFG_EOMDIS_Pos)) /* Assigment of value for EOMDIS in the ICM_CFG register */
#define ICM_CFG_SLBDIS_Pos                    _UINT32_(2)                                          /* (ICM_CFG) Secondary List Branching Disable Position */
#define ICM_CFG_SLBDIS_Msk                    (_UINT32_(0x1) << ICM_CFG_SLBDIS_Pos)                /* (ICM_CFG) Secondary List Branching Disable Mask */
#define ICM_CFG_SLBDIS(value)                 (ICM_CFG_SLBDIS_Msk & (_UINT32_(value) << ICM_CFG_SLBDIS_Pos)) /* Assigment of value for SLBDIS in the ICM_CFG register */
#define ICM_CFG_BBC_Pos                       _UINT32_(4)                                          /* (ICM_CFG) Bus Burden Control Position */
#define ICM_CFG_BBC_Msk                       (_UINT32_(0xF) << ICM_CFG_BBC_Pos)                   /* (ICM_CFG) Bus Burden Control Mask */
#define ICM_CFG_BBC(value)                    (ICM_CFG_BBC_Msk & (_UINT32_(value) << ICM_CFG_BBC_Pos)) /* Assigment of value for BBC in the ICM_CFG register */
#define ICM_CFG_ASCD_Pos                      _UINT32_(8)                                          /* (ICM_CFG) Automatic Switch To Compare Digest Position */
#define ICM_CFG_ASCD_Msk                      (_UINT32_(0x1) << ICM_CFG_ASCD_Pos)                  /* (ICM_CFG) Automatic Switch To Compare Digest Mask */
#define ICM_CFG_ASCD(value)                   (ICM_CFG_ASCD_Msk & (_UINT32_(value) << ICM_CFG_ASCD_Pos)) /* Assigment of value for ASCD in the ICM_CFG register */
#define ICM_CFG_DUALBUFF_Pos                  _UINT32_(9)                                          /* (ICM_CFG) Dual Input Buffer Position */
#define ICM_CFG_DUALBUFF_Msk                  (_UINT32_(0x1) << ICM_CFG_DUALBUFF_Pos)              /* (ICM_CFG) Dual Input Buffer Mask */
#define ICM_CFG_DUALBUFF(value)               (ICM_CFG_DUALBUFF_Msk & (_UINT32_(value) << ICM_CFG_DUALBUFF_Pos)) /* Assigment of value for DUALBUFF in the ICM_CFG register */
#define ICM_CFG_UIHASH_Pos                    _UINT32_(12)                                         /* (ICM_CFG) User Initial Hash Value Position */
#define ICM_CFG_UIHASH_Msk                    (_UINT32_(0x1) << ICM_CFG_UIHASH_Pos)                /* (ICM_CFG) User Initial Hash Value Mask */
#define ICM_CFG_UIHASH(value)                 (ICM_CFG_UIHASH_Msk & (_UINT32_(value) << ICM_CFG_UIHASH_Pos)) /* Assigment of value for UIHASH in the ICM_CFG register */
#define ICM_CFG_UALGO_Pos                     _UINT32_(13)                                         /* (ICM_CFG) User SHA Algorithm Position */
#define ICM_CFG_UALGO_Msk                     (_UINT32_(0x7) << ICM_CFG_UALGO_Pos)                 /* (ICM_CFG) User SHA Algorithm Mask */
#define ICM_CFG_UALGO(value)                  (ICM_CFG_UALGO_Msk & (_UINT32_(value) << ICM_CFG_UALGO_Pos)) /* Assigment of value for UALGO in the ICM_CFG register */
#define   ICM_CFG_UALGO_SHA1_Val              _UINT32_(0x0)                                        /* (ICM_CFG) SHA1 Algorithm  */
#define   ICM_CFG_UALGO_SHA256_Val            _UINT32_(0x1)                                        /* (ICM_CFG) SHA256 Algorithm  */
#define   ICM_CFG_UALGO_SHA224_Val            _UINT32_(0x4)                                        /* (ICM_CFG) SHA224 Algorithm  */
#define ICM_CFG_UALGO_SHA1                    (ICM_CFG_UALGO_SHA1_Val << ICM_CFG_UALGO_Pos)        /* (ICM_CFG) SHA1 Algorithm Position  */
#define ICM_CFG_UALGO_SHA256                  (ICM_CFG_UALGO_SHA256_Val << ICM_CFG_UALGO_Pos)      /* (ICM_CFG) SHA256 Algorithm Position  */
#define ICM_CFG_UALGO_SHA224                  (ICM_CFG_UALGO_SHA224_Val << ICM_CFG_UALGO_Pos)      /* (ICM_CFG) SHA224 Algorithm Position  */
#define ICM_CFG_Msk                           _UINT32_(0x0000F3F7)                                 /* (ICM_CFG) Register Mask  */


/* -------- ICM_CTRL : (ICM Offset: 0x04) ( /W 32) Control -------- */
#define ICM_CTRL_ENABLE_Pos                   _UINT32_(0)                                          /* (ICM_CTRL) ICM Enable Position */
#define ICM_CTRL_ENABLE_Msk                   (_UINT32_(0x1) << ICM_CTRL_ENABLE_Pos)               /* (ICM_CTRL) ICM Enable Mask */
#define ICM_CTRL_ENABLE(value)                (ICM_CTRL_ENABLE_Msk & (_UINT32_(value) << ICM_CTRL_ENABLE_Pos)) /* Assigment of value for ENABLE in the ICM_CTRL register */
#define ICM_CTRL_DISABLE_Pos                  _UINT32_(1)                                          /* (ICM_CTRL) ICM Disable Register Position */
#define ICM_CTRL_DISABLE_Msk                  (_UINT32_(0x1) << ICM_CTRL_DISABLE_Pos)              /* (ICM_CTRL) ICM Disable Register Mask */
#define ICM_CTRL_DISABLE(value)               (ICM_CTRL_DISABLE_Msk & (_UINT32_(value) << ICM_CTRL_DISABLE_Pos)) /* Assigment of value for DISABLE in the ICM_CTRL register */
#define ICM_CTRL_SWRST_Pos                    _UINT32_(2)                                          /* (ICM_CTRL) Software Reset Position */
#define ICM_CTRL_SWRST_Msk                    (_UINT32_(0x1) << ICM_CTRL_SWRST_Pos)                /* (ICM_CTRL) Software Reset Mask */
#define ICM_CTRL_SWRST(value)                 (ICM_CTRL_SWRST_Msk & (_UINT32_(value) << ICM_CTRL_SWRST_Pos)) /* Assigment of value for SWRST in the ICM_CTRL register */
#define ICM_CTRL_REHASH_Pos                   _UINT32_(4)                                          /* (ICM_CTRL) Recompute Internal Hash Position */
#define ICM_CTRL_REHASH_Msk                   (_UINT32_(0xF) << ICM_CTRL_REHASH_Pos)               /* (ICM_CTRL) Recompute Internal Hash Mask */
#define ICM_CTRL_REHASH(value)                (ICM_CTRL_REHASH_Msk & (_UINT32_(value) << ICM_CTRL_REHASH_Pos)) /* Assigment of value for REHASH in the ICM_CTRL register */
#define ICM_CTRL_RMDIS_Pos                    _UINT32_(8)                                          /* (ICM_CTRL) Region Monitoring Disable Position */
#define ICM_CTRL_RMDIS_Msk                    (_UINT32_(0xF) << ICM_CTRL_RMDIS_Pos)                /* (ICM_CTRL) Region Monitoring Disable Mask */
#define ICM_CTRL_RMDIS(value)                 (ICM_CTRL_RMDIS_Msk & (_UINT32_(value) << ICM_CTRL_RMDIS_Pos)) /* Assigment of value for RMDIS in the ICM_CTRL register */
#define ICM_CTRL_RMEN_Pos                     _UINT32_(12)                                         /* (ICM_CTRL) Region Monitoring Enable Position */
#define ICM_CTRL_RMEN_Msk                     (_UINT32_(0xF) << ICM_CTRL_RMEN_Pos)                 /* (ICM_CTRL) Region Monitoring Enable Mask */
#define ICM_CTRL_RMEN(value)                  (ICM_CTRL_RMEN_Msk & (_UINT32_(value) << ICM_CTRL_RMEN_Pos)) /* Assigment of value for RMEN in the ICM_CTRL register */
#define ICM_CTRL_Msk                          _UINT32_(0x0000FFF7)                                 /* (ICM_CTRL) Register Mask  */


/* -------- ICM_SR : (ICM Offset: 0x08) ( R/ 32) Status -------- */
#define ICM_SR_RESETVALUE                     _UINT32_(0x00)                                       /*  (ICM_SR) Status  Reset Value */

#define ICM_SR_ENABLE_Pos                     _UINT32_(0)                                          /* (ICM_SR) ICM Controller Enable Register Position */
#define ICM_SR_ENABLE_Msk                     (_UINT32_(0x1) << ICM_SR_ENABLE_Pos)                 /* (ICM_SR) ICM Controller Enable Register Mask */
#define ICM_SR_ENABLE(value)                  (ICM_SR_ENABLE_Msk & (_UINT32_(value) << ICM_SR_ENABLE_Pos)) /* Assigment of value for ENABLE in the ICM_SR register */
#define ICM_SR_RAWRMDIS_Pos                   _UINT32_(8)                                          /* (ICM_SR) RAW Region Monitoring Disabled Status Position */
#define ICM_SR_RAWRMDIS_Msk                   (_UINT32_(0xF) << ICM_SR_RAWRMDIS_Pos)               /* (ICM_SR) RAW Region Monitoring Disabled Status Mask */
#define ICM_SR_RAWRMDIS(value)                (ICM_SR_RAWRMDIS_Msk & (_UINT32_(value) << ICM_SR_RAWRMDIS_Pos)) /* Assigment of value for RAWRMDIS in the ICM_SR register */
#define ICM_SR_RMDIS_Pos                      _UINT32_(12)                                         /* (ICM_SR) Region Monitoring Disabled Status Position */
#define ICM_SR_RMDIS_Msk                      (_UINT32_(0xF) << ICM_SR_RMDIS_Pos)                  /* (ICM_SR) Region Monitoring Disabled Status Mask */
#define ICM_SR_RMDIS(value)                   (ICM_SR_RMDIS_Msk & (_UINT32_(value) << ICM_SR_RMDIS_Pos)) /* Assigment of value for RMDIS in the ICM_SR register */
#define ICM_SR_Msk                            _UINT32_(0x0000FF01)                                 /* (ICM_SR) Register Mask  */


/* -------- ICM_IER : (ICM Offset: 0x10) ( /W 32) Interrupt Enable -------- */
#define ICM_IER_RHC_Pos                       _UINT32_(0)                                          /* (ICM_IER) Region Hash Completed Interrupt Enable Position */
#define ICM_IER_RHC_Msk                       (_UINT32_(0xF) << ICM_IER_RHC_Pos)                   /* (ICM_IER) Region Hash Completed Interrupt Enable Mask */
#define ICM_IER_RHC(value)                    (ICM_IER_RHC_Msk & (_UINT32_(value) << ICM_IER_RHC_Pos)) /* Assigment of value for RHC in the ICM_IER register */
#define ICM_IER_RDM_Pos                       _UINT32_(4)                                          /* (ICM_IER) Region Digest Mismatch Interrupt Enable Position */
#define ICM_IER_RDM_Msk                       (_UINT32_(0xF) << ICM_IER_RDM_Pos)                   /* (ICM_IER) Region Digest Mismatch Interrupt Enable Mask */
#define ICM_IER_RDM(value)                    (ICM_IER_RDM_Msk & (_UINT32_(value) << ICM_IER_RDM_Pos)) /* Assigment of value for RDM in the ICM_IER register */
#define ICM_IER_RBE_Pos                       _UINT32_(8)                                          /* (ICM_IER) Region Bus Error Interrupt Enable Position */
#define ICM_IER_RBE_Msk                       (_UINT32_(0xF) << ICM_IER_RBE_Pos)                   /* (ICM_IER) Region Bus Error Interrupt Enable Mask */
#define ICM_IER_RBE(value)                    (ICM_IER_RBE_Msk & (_UINT32_(value) << ICM_IER_RBE_Pos)) /* Assigment of value for RBE in the ICM_IER register */
#define ICM_IER_RWC_Pos                       _UINT32_(12)                                         /* (ICM_IER) Region Wrap Condition detected Interrupt Enable Position */
#define ICM_IER_RWC_Msk                       (_UINT32_(0xF) << ICM_IER_RWC_Pos)                   /* (ICM_IER) Region Wrap Condition detected Interrupt Enable Mask */
#define ICM_IER_RWC(value)                    (ICM_IER_RWC_Msk & (_UINT32_(value) << ICM_IER_RWC_Pos)) /* Assigment of value for RWC in the ICM_IER register */
#define ICM_IER_REC_Pos                       _UINT32_(16)                                         /* (ICM_IER) Region End bit Condition Detected Interrupt Enable Position */
#define ICM_IER_REC_Msk                       (_UINT32_(0xF) << ICM_IER_REC_Pos)                   /* (ICM_IER) Region End bit Condition Detected Interrupt Enable Mask */
#define ICM_IER_REC(value)                    (ICM_IER_REC_Msk & (_UINT32_(value) << ICM_IER_REC_Pos)) /* Assigment of value for REC in the ICM_IER register */
#define ICM_IER_RSU_Pos                       _UINT32_(20)                                         /* (ICM_IER) Region Status Updated Interrupt Disable Position */
#define ICM_IER_RSU_Msk                       (_UINT32_(0xF) << ICM_IER_RSU_Pos)                   /* (ICM_IER) Region Status Updated Interrupt Disable Mask */
#define ICM_IER_RSU(value)                    (ICM_IER_RSU_Msk & (_UINT32_(value) << ICM_IER_RSU_Pos)) /* Assigment of value for RSU in the ICM_IER register */
#define ICM_IER_URAD_Pos                      _UINT32_(24)                                         /* (ICM_IER) Undefined Register Access Detection Interrupt Enable Position */
#define ICM_IER_URAD_Msk                      (_UINT32_(0x1) << ICM_IER_URAD_Pos)                  /* (ICM_IER) Undefined Register Access Detection Interrupt Enable Mask */
#define ICM_IER_URAD(value)                   (ICM_IER_URAD_Msk & (_UINT32_(value) << ICM_IER_URAD_Pos)) /* Assigment of value for URAD in the ICM_IER register */
#define ICM_IER_Msk                           _UINT32_(0x01FFFFFF)                                 /* (ICM_IER) Register Mask  */


/* -------- ICM_IDR : (ICM Offset: 0x14) ( /W 32) Interrupt Disable -------- */
#define ICM_IDR_RESETVALUE                    _UINT32_(0x00)                                       /*  (ICM_IDR) Interrupt Disable  Reset Value */

#define ICM_IDR_RHC_Pos                       _UINT32_(0)                                          /* (ICM_IDR) Region Hash Completed Interrupt Disable Position */
#define ICM_IDR_RHC_Msk                       (_UINT32_(0xF) << ICM_IDR_RHC_Pos)                   /* (ICM_IDR) Region Hash Completed Interrupt Disable Mask */
#define ICM_IDR_RHC(value)                    (ICM_IDR_RHC_Msk & (_UINT32_(value) << ICM_IDR_RHC_Pos)) /* Assigment of value for RHC in the ICM_IDR register */
#define ICM_IDR_RDM_Pos                       _UINT32_(4)                                          /* (ICM_IDR) Region Digest Mismatch Interrupt Disable Position */
#define ICM_IDR_RDM_Msk                       (_UINT32_(0xF) << ICM_IDR_RDM_Pos)                   /* (ICM_IDR) Region Digest Mismatch Interrupt Disable Mask */
#define ICM_IDR_RDM(value)                    (ICM_IDR_RDM_Msk & (_UINT32_(value) << ICM_IDR_RDM_Pos)) /* Assigment of value for RDM in the ICM_IDR register */
#define ICM_IDR_RBE_Pos                       _UINT32_(8)                                          /* (ICM_IDR) Region Bus Error Interrupt Disable Position */
#define ICM_IDR_RBE_Msk                       (_UINT32_(0xF) << ICM_IDR_RBE_Pos)                   /* (ICM_IDR) Region Bus Error Interrupt Disable Mask */
#define ICM_IDR_RBE(value)                    (ICM_IDR_RBE_Msk & (_UINT32_(value) << ICM_IDR_RBE_Pos)) /* Assigment of value for RBE in the ICM_IDR register */
#define ICM_IDR_RWC_Pos                       _UINT32_(12)                                         /* (ICM_IDR) Region Wrap Condition Detected Interrupt Disable Position */
#define ICM_IDR_RWC_Msk                       (_UINT32_(0xF) << ICM_IDR_RWC_Pos)                   /* (ICM_IDR) Region Wrap Condition Detected Interrupt Disable Mask */
#define ICM_IDR_RWC(value)                    (ICM_IDR_RWC_Msk & (_UINT32_(value) << ICM_IDR_RWC_Pos)) /* Assigment of value for RWC in the ICM_IDR register */
#define ICM_IDR_REC_Pos                       _UINT32_(16)                                         /* (ICM_IDR) Region End bit Condition detected Interrupt Disable Position */
#define ICM_IDR_REC_Msk                       (_UINT32_(0xF) << ICM_IDR_REC_Pos)                   /* (ICM_IDR) Region End bit Condition detected Interrupt Disable Mask */
#define ICM_IDR_REC(value)                    (ICM_IDR_REC_Msk & (_UINT32_(value) << ICM_IDR_REC_Pos)) /* Assigment of value for REC in the ICM_IDR register */
#define ICM_IDR_RSU_Pos                       _UINT32_(20)                                         /* (ICM_IDR) Region Status Updated Interrupt Disable Position */
#define ICM_IDR_RSU_Msk                       (_UINT32_(0xF) << ICM_IDR_RSU_Pos)                   /* (ICM_IDR) Region Status Updated Interrupt Disable Mask */
#define ICM_IDR_RSU(value)                    (ICM_IDR_RSU_Msk & (_UINT32_(value) << ICM_IDR_RSU_Pos)) /* Assigment of value for RSU in the ICM_IDR register */
#define ICM_IDR_URAD_Pos                      _UINT32_(24)                                         /* (ICM_IDR) Undefined Register Access Detection Interrupt Disable Position */
#define ICM_IDR_URAD_Msk                      (_UINT32_(0x1) << ICM_IDR_URAD_Pos)                  /* (ICM_IDR) Undefined Register Access Detection Interrupt Disable Mask */
#define ICM_IDR_URAD(value)                   (ICM_IDR_URAD_Msk & (_UINT32_(value) << ICM_IDR_URAD_Pos)) /* Assigment of value for URAD in the ICM_IDR register */
#define ICM_IDR_Msk                           _UINT32_(0x01FFFFFF)                                 /* (ICM_IDR) Register Mask  */


/* -------- ICM_IMR : (ICM Offset: 0x18) ( R/ 32) Interrupt Mask -------- */
#define ICM_IMR_RESETVALUE                    _UINT32_(0x00)                                       /*  (ICM_IMR) Interrupt Mask  Reset Value */

#define ICM_IMR_RHC_Pos                       _UINT32_(0)                                          /* (ICM_IMR) Region Hash Completed Interrupt Mask Position */
#define ICM_IMR_RHC_Msk                       (_UINT32_(0xF) << ICM_IMR_RHC_Pos)                   /* (ICM_IMR) Region Hash Completed Interrupt Mask Mask */
#define ICM_IMR_RHC(value)                    (ICM_IMR_RHC_Msk & (_UINT32_(value) << ICM_IMR_RHC_Pos)) /* Assigment of value for RHC in the ICM_IMR register */
#define ICM_IMR_RDM_Pos                       _UINT32_(4)                                          /* (ICM_IMR) Region Digest Mismatch Interrupt Mask Position */
#define ICM_IMR_RDM_Msk                       (_UINT32_(0xF) << ICM_IMR_RDM_Pos)                   /* (ICM_IMR) Region Digest Mismatch Interrupt Mask Mask */
#define ICM_IMR_RDM(value)                    (ICM_IMR_RDM_Msk & (_UINT32_(value) << ICM_IMR_RDM_Pos)) /* Assigment of value for RDM in the ICM_IMR register */
#define ICM_IMR_RBE_Pos                       _UINT32_(8)                                          /* (ICM_IMR) Region Bus Error Interrupt Mask Position */
#define ICM_IMR_RBE_Msk                       (_UINT32_(0xF) << ICM_IMR_RBE_Pos)                   /* (ICM_IMR) Region Bus Error Interrupt Mask Mask */
#define ICM_IMR_RBE(value)                    (ICM_IMR_RBE_Msk & (_UINT32_(value) << ICM_IMR_RBE_Pos)) /* Assigment of value for RBE in the ICM_IMR register */
#define ICM_IMR_RWC_Pos                       _UINT32_(12)                                         /* (ICM_IMR) Region Wrap Condition Detected Interrupt Mask Position */
#define ICM_IMR_RWC_Msk                       (_UINT32_(0xF) << ICM_IMR_RWC_Pos)                   /* (ICM_IMR) Region Wrap Condition Detected Interrupt Mask Mask */
#define ICM_IMR_RWC(value)                    (ICM_IMR_RWC_Msk & (_UINT32_(value) << ICM_IMR_RWC_Pos)) /* Assigment of value for RWC in the ICM_IMR register */
#define ICM_IMR_REC_Pos                       _UINT32_(16)                                         /* (ICM_IMR) Region End bit Condition Detected Interrupt Mask Position */
#define ICM_IMR_REC_Msk                       (_UINT32_(0xF) << ICM_IMR_REC_Pos)                   /* (ICM_IMR) Region End bit Condition Detected Interrupt Mask Mask */
#define ICM_IMR_REC(value)                    (ICM_IMR_REC_Msk & (_UINT32_(value) << ICM_IMR_REC_Pos)) /* Assigment of value for REC in the ICM_IMR register */
#define ICM_IMR_RSU_Pos                       _UINT32_(20)                                         /* (ICM_IMR) Region Status Updated Interrupt Mask Position */
#define ICM_IMR_RSU_Msk                       (_UINT32_(0xF) << ICM_IMR_RSU_Pos)                   /* (ICM_IMR) Region Status Updated Interrupt Mask Mask */
#define ICM_IMR_RSU(value)                    (ICM_IMR_RSU_Msk & (_UINT32_(value) << ICM_IMR_RSU_Pos)) /* Assigment of value for RSU in the ICM_IMR register */
#define ICM_IMR_URAD_Pos                      _UINT32_(24)                                         /* (ICM_IMR) Undefined Register Access Detection Interrupt Mask Position */
#define ICM_IMR_URAD_Msk                      (_UINT32_(0x1) << ICM_IMR_URAD_Pos)                  /* (ICM_IMR) Undefined Register Access Detection Interrupt Mask Mask */
#define ICM_IMR_URAD(value)                   (ICM_IMR_URAD_Msk & (_UINT32_(value) << ICM_IMR_URAD_Pos)) /* Assigment of value for URAD in the ICM_IMR register */
#define ICM_IMR_Msk                           _UINT32_(0x01FFFFFF)                                 /* (ICM_IMR) Register Mask  */


/* -------- ICM_ISR : (ICM Offset: 0x1C) ( R/ 32) Interrupt Status -------- */
#define ICM_ISR_RESETVALUE                    _UINT32_(0x00)                                       /*  (ICM_ISR) Interrupt Status  Reset Value */

#define ICM_ISR_RHC_Pos                       _UINT32_(0)                                          /* (ICM_ISR) Region Hash Completed Position */
#define ICM_ISR_RHC_Msk                       (_UINT32_(0xF) << ICM_ISR_RHC_Pos)                   /* (ICM_ISR) Region Hash Completed Mask */
#define ICM_ISR_RHC(value)                    (ICM_ISR_RHC_Msk & (_UINT32_(value) << ICM_ISR_RHC_Pos)) /* Assigment of value for RHC in the ICM_ISR register */
#define ICM_ISR_RDM_Pos                       _UINT32_(4)                                          /* (ICM_ISR) Region Digest Mismatch Position */
#define ICM_ISR_RDM_Msk                       (_UINT32_(0xF) << ICM_ISR_RDM_Pos)                   /* (ICM_ISR) Region Digest Mismatch Mask */
#define ICM_ISR_RDM(value)                    (ICM_ISR_RDM_Msk & (_UINT32_(value) << ICM_ISR_RDM_Pos)) /* Assigment of value for RDM in the ICM_ISR register */
#define ICM_ISR_RBE_Pos                       _UINT32_(8)                                          /* (ICM_ISR) Region Bus Error Position */
#define ICM_ISR_RBE_Msk                       (_UINT32_(0xF) << ICM_ISR_RBE_Pos)                   /* (ICM_ISR) Region Bus Error Mask */
#define ICM_ISR_RBE(value)                    (ICM_ISR_RBE_Msk & (_UINT32_(value) << ICM_ISR_RBE_Pos)) /* Assigment of value for RBE in the ICM_ISR register */
#define ICM_ISR_RWC_Pos                       _UINT32_(12)                                         /* (ICM_ISR) Region Wrap Condition Detected Position */
#define ICM_ISR_RWC_Msk                       (_UINT32_(0xF) << ICM_ISR_RWC_Pos)                   /* (ICM_ISR) Region Wrap Condition Detected Mask */
#define ICM_ISR_RWC(value)                    (ICM_ISR_RWC_Msk & (_UINT32_(value) << ICM_ISR_RWC_Pos)) /* Assigment of value for RWC in the ICM_ISR register */
#define ICM_ISR_REC_Pos                       _UINT32_(16)                                         /* (ICM_ISR) Region End bit Condition Detected Position */
#define ICM_ISR_REC_Msk                       (_UINT32_(0xF) << ICM_ISR_REC_Pos)                   /* (ICM_ISR) Region End bit Condition Detected Mask */
#define ICM_ISR_REC(value)                    (ICM_ISR_REC_Msk & (_UINT32_(value) << ICM_ISR_REC_Pos)) /* Assigment of value for REC in the ICM_ISR register */
#define ICM_ISR_RSU_Pos                       _UINT32_(20)                                         /* (ICM_ISR) Region Status Updated Detected Position */
#define ICM_ISR_RSU_Msk                       (_UINT32_(0xF) << ICM_ISR_RSU_Pos)                   /* (ICM_ISR) Region Status Updated Detected Mask */
#define ICM_ISR_RSU(value)                    (ICM_ISR_RSU_Msk & (_UINT32_(value) << ICM_ISR_RSU_Pos)) /* Assigment of value for RSU in the ICM_ISR register */
#define ICM_ISR_URAD_Pos                      _UINT32_(24)                                         /* (ICM_ISR) Undefined Register Access Detection Status Position */
#define ICM_ISR_URAD_Msk                      (_UINT32_(0x1) << ICM_ISR_URAD_Pos)                  /* (ICM_ISR) Undefined Register Access Detection Status Mask */
#define ICM_ISR_URAD(value)                   (ICM_ISR_URAD_Msk & (_UINT32_(value) << ICM_ISR_URAD_Pos)) /* Assigment of value for URAD in the ICM_ISR register */
#define ICM_ISR_Msk                           _UINT32_(0x01FFFFFF)                                 /* (ICM_ISR) Register Mask  */


/* -------- ICM_UASR : (ICM Offset: 0x20) ( R/ 32) Undefined Access Status -------- */
#define ICM_UASR_RESETVALUE                   _UINT32_(0x00)                                       /*  (ICM_UASR) Undefined Access Status  Reset Value */

#define ICM_UASR_URAT_Pos                     _UINT32_(0)                                          /* (ICM_UASR) Undefined Register Access Trace Position */
#define ICM_UASR_URAT_Msk                     (_UINT32_(0x7) << ICM_UASR_URAT_Pos)                 /* (ICM_UASR) Undefined Register Access Trace Mask */
#define ICM_UASR_URAT(value)                  (ICM_UASR_URAT_Msk & (_UINT32_(value) << ICM_UASR_URAT_Pos)) /* Assigment of value for URAT in the ICM_UASR register */
#define   ICM_UASR_URAT_UNSPEC_STRUCT_MEMBER_Val _UINT32_(0x0)                                        /* (ICM_UASR) Unspecified structure member set to one detected when the descriptor is loaded  */
#define   ICM_UASR_URAT_CFG_MODIFIED_Val      _UINT32_(0x1)                                        /* (ICM_UASR) CFG modified during active monitoring  */
#define   ICM_UASR_URAT_DSCR_MODIFIED_Val     _UINT32_(0x2)                                        /* (ICM_UASR) DSCR modified during active monitoring  */
#define   ICM_UASR_URAT_HASH_MODIFIED_Val     _UINT32_(0x3)                                        /* (ICM_UASR) HASH modified during active monitoring  */
#define   ICM_UASR_URAT_READ_ACCESS_Val       _UINT32_(0x4)                                        /* (ICM_UASR) Write-only register read access  */
#define ICM_UASR_URAT_UNSPEC_STRUCT_MEMBER    (ICM_UASR_URAT_UNSPEC_STRUCT_MEMBER_Val << ICM_UASR_URAT_Pos) /* (ICM_UASR) Unspecified structure member set to one detected when the descriptor is loaded Position  */
#define ICM_UASR_URAT_CFG_MODIFIED            (ICM_UASR_URAT_CFG_MODIFIED_Val << ICM_UASR_URAT_Pos) /* (ICM_UASR) CFG modified during active monitoring Position  */
#define ICM_UASR_URAT_DSCR_MODIFIED           (ICM_UASR_URAT_DSCR_MODIFIED_Val << ICM_UASR_URAT_Pos) /* (ICM_UASR) DSCR modified during active monitoring Position  */
#define ICM_UASR_URAT_HASH_MODIFIED           (ICM_UASR_URAT_HASH_MODIFIED_Val << ICM_UASR_URAT_Pos) /* (ICM_UASR) HASH modified during active monitoring Position  */
#define ICM_UASR_URAT_READ_ACCESS             (ICM_UASR_URAT_READ_ACCESS_Val << ICM_UASR_URAT_Pos) /* (ICM_UASR) Write-only register read access Position  */
#define ICM_UASR_Msk                          _UINT32_(0x00000007)                                 /* (ICM_UASR) Register Mask  */


/* -------- ICM_DSCR : (ICM Offset: 0x30) (R/W 32) Region Descriptor Area Start Address -------- */
#define ICM_DSCR_RESETVALUE                   _UINT32_(0x00)                                       /*  (ICM_DSCR) Region Descriptor Area Start Address  Reset Value */

#define ICM_DSCR_DASA_Pos                     _UINT32_(6)                                          /* (ICM_DSCR) Descriptor Area Start Address Position */
#define ICM_DSCR_DASA_Msk                     (_UINT32_(0x3FFFFFF) << ICM_DSCR_DASA_Pos)           /* (ICM_DSCR) Descriptor Area Start Address Mask */
#define ICM_DSCR_DASA(value)                  (ICM_DSCR_DASA_Msk & (_UINT32_(value) << ICM_DSCR_DASA_Pos)) /* Assigment of value for DASA in the ICM_DSCR register */
#define ICM_DSCR_Msk                          _UINT32_(0xFFFFFFC0)                                 /* (ICM_DSCR) Register Mask  */


/* -------- ICM_HASH : (ICM Offset: 0x34) (R/W 32) Region Hash Area Start Address -------- */
#define ICM_HASH_RESETVALUE                   _UINT32_(0x00)                                       /*  (ICM_HASH) Region Hash Area Start Address  Reset Value */

#define ICM_HASH_HASA_Pos                     _UINT32_(7)                                          /* (ICM_HASH) Hash Area Start Address Position */
#define ICM_HASH_HASA_Msk                     (_UINT32_(0x1FFFFFF) << ICM_HASH_HASA_Pos)           /* (ICM_HASH) Hash Area Start Address Mask */
#define ICM_HASH_HASA(value)                  (ICM_HASH_HASA_Msk & (_UINT32_(value) << ICM_HASH_HASA_Pos)) /* Assigment of value for HASA in the ICM_HASH register */
#define ICM_HASH_Msk                          _UINT32_(0xFFFFFF80)                                 /* (ICM_HASH) Register Mask  */


/* -------- ICM_UIHVAL : (ICM Offset: 0x38) ( /W 32) User Initial Hash Value n -------- */
#define ICM_UIHVAL_RESETVALUE                 _UINT32_(0x00)                                       /*  (ICM_UIHVAL) User Initial Hash Value n  Reset Value */

#define ICM_UIHVAL_VAL_Pos                    _UINT32_(0)                                          /* (ICM_UIHVAL) Initial Hash Value Position */
#define ICM_UIHVAL_VAL_Msk                    (_UINT32_(0xFFFFFFFF) << ICM_UIHVAL_VAL_Pos)         /* (ICM_UIHVAL) Initial Hash Value Mask */
#define ICM_UIHVAL_VAL(value)                 (ICM_UIHVAL_VAL_Msk & (_UINT32_(value) << ICM_UIHVAL_VAL_Pos)) /* Assigment of value for VAL in the ICM_UIHVAL register */
#define ICM_UIHVAL_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (ICM_UIHVAL) Register Mask  */


/** \brief ICM register offsets definitions */
#define ICM_RADDR_REG_OFST             _UINT32_(0x00)      /* (ICM_RADDR) Region Start Address Offset */
#define ICM_RCFG_REG_OFST              _UINT32_(0x04)      /* (ICM_RCFG) Region Configuration Offset */
#define ICM_RCTRL_REG_OFST             _UINT32_(0x08)      /* (ICM_RCTRL) Region Control Offset */
#define ICM_RNEXT_REG_OFST             _UINT32_(0x0C)      /* (ICM_RNEXT) Region Next Address Offset */
#define ICM_CFG_REG_OFST               _UINT32_(0x00)      /* (ICM_CFG) Configuration Offset */
#define ICM_CTRL_REG_OFST              _UINT32_(0x04)      /* (ICM_CTRL) Control Offset */
#define ICM_SR_REG_OFST                _UINT32_(0x08)      /* (ICM_SR) Status Offset */
#define ICM_IER_REG_OFST               _UINT32_(0x10)      /* (ICM_IER) Interrupt Enable Offset */
#define ICM_IDR_REG_OFST               _UINT32_(0x14)      /* (ICM_IDR) Interrupt Disable Offset */
#define ICM_IMR_REG_OFST               _UINT32_(0x18)      /* (ICM_IMR) Interrupt Mask Offset */
#define ICM_ISR_REG_OFST               _UINT32_(0x1C)      /* (ICM_ISR) Interrupt Status Offset */
#define ICM_UASR_REG_OFST              _UINT32_(0x20)      /* (ICM_UASR) Undefined Access Status Offset */
#define ICM_DSCR_REG_OFST              _UINT32_(0x30)      /* (ICM_DSCR) Region Descriptor Area Start Address Offset */
#define ICM_HASH_REG_OFST              _UINT32_(0x34)      /* (ICM_HASH) Region Hash Area Start Address Offset */
#define ICM_UIHVAL_REG_OFST            _UINT32_(0x38)      /* (ICM_UIHVAL) User Initial Hash Value n Offset */
#define ICM_UIHVAL0_REG_OFST           _UINT32_(0x38)      /* (ICM_UIHVAL0) User Initial Hash Value n Offset */
#define ICM_UIHVAL1_REG_OFST           _UINT32_(0x3C)      /* (ICM_UIHVAL1) User Initial Hash Value n Offset */
#define ICM_UIHVAL2_REG_OFST           _UINT32_(0x40)      /* (ICM_UIHVAL2) User Initial Hash Value n Offset */
#define ICM_UIHVAL3_REG_OFST           _UINT32_(0x44)      /* (ICM_UIHVAL3) User Initial Hash Value n Offset */
#define ICM_UIHVAL4_REG_OFST           _UINT32_(0x48)      /* (ICM_UIHVAL4) User Initial Hash Value n Offset */
#define ICM_UIHVAL5_REG_OFST           _UINT32_(0x4C)      /* (ICM_UIHVAL5) User Initial Hash Value n Offset */
#define ICM_UIHVAL6_REG_OFST           _UINT32_(0x50)      /* (ICM_UIHVAL6) User Initial Hash Value n Offset */
#define ICM_UIHVAL7_REG_OFST           _UINT32_(0x54)      /* (ICM_UIHVAL7) User Initial Hash Value n Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief ICM_DESCRIPTOR register API structure */
typedef struct
{  /* Integrity Check Monitor */
  __IO  uint32_t                       ICM_RADDR;          /**< Offset: 0x00 (R/W  32) Region Start Address */
  __IO  uint32_t                       ICM_RCFG;           /**< Offset: 0x04 (R/W  32) Region Configuration */
  __IO  uint32_t                       ICM_RCTRL;          /**< Offset: 0x08 (R/W  32) Region Control */
  __IO  uint32_t                       ICM_RNEXT;          /**< Offset: 0x0C (R/W  32) Region Next Address */
} icm_descriptor_registers_t;

/** \brief ICM register API structure */
typedef struct
{  /* Integrity Check Monitor */
  __IO  uint32_t                       ICM_CFG;            /**< Offset: 0x00 (R/W  32) Configuration */
  __O   uint32_t                       ICM_CTRL;           /**< Offset: 0x04 ( /W  32) Control */
  __I   uint32_t                       ICM_SR;             /**< Offset: 0x08 (R/   32) Status */
  __I   uint8_t                        Reserved1[0x04];
  __O   uint32_t                       ICM_IER;            /**< Offset: 0x10 ( /W  32) Interrupt Enable */
  __O   uint32_t                       ICM_IDR;            /**< Offset: 0x14 ( /W  32) Interrupt Disable */
  __I   uint32_t                       ICM_IMR;            /**< Offset: 0x18 (R/   32) Interrupt Mask */
  __I   uint32_t                       ICM_ISR;            /**< Offset: 0x1C (R/   32) Interrupt Status */
  __I   uint32_t                       ICM_UASR;           /**< Offset: 0x20 (R/   32) Undefined Access Status */
  __I   uint8_t                        Reserved2[0x0C];
  __IO  uint32_t                       ICM_DSCR;           /**< Offset: 0x30 (R/W  32) Region Descriptor Area Start Address */
  __IO  uint32_t                       ICM_HASH;           /**< Offset: 0x34 (R/W  32) Region Hash Area Start Address */
  __O   uint32_t                       ICM_UIHVAL[8];      /**< Offset: 0x38 ( /W  32) User Initial Hash Value n */
} icm_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** \brief ICM_DESCRIPTOR memory section attribute */
#define SECTION_ICM_DESCRIPTOR

#endif /* _SAME54_ICM_COMPONENT_H_ */
