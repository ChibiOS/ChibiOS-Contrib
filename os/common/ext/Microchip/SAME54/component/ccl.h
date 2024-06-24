/*
 * Component description for CCL
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
#ifndef _SAME54_CCL_COMPONENT_H_
#define _SAME54_CCL_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR CCL                                          */
/* ************************************************************************** */

/* -------- CCL_CTRL : (CCL Offset: 0x00) (R/W 8) Control -------- */
#define CCL_CTRL_RESETVALUE                   _UINT8_(0x00)                                        /*  (CCL_CTRL) Control  Reset Value */

#define CCL_CTRL_SWRST_Pos                    _UINT8_(0)                                           /* (CCL_CTRL) Software Reset Position */
#define CCL_CTRL_SWRST_Msk                    (_UINT8_(0x1) << CCL_CTRL_SWRST_Pos)                 /* (CCL_CTRL) Software Reset Mask */
#define CCL_CTRL_SWRST(value)                 (CCL_CTRL_SWRST_Msk & (_UINT8_(value) << CCL_CTRL_SWRST_Pos)) /* Assigment of value for SWRST in the CCL_CTRL register */
#define   CCL_CTRL_SWRST_DISABLE_Val          _UINT8_(0x0)                                         /* (CCL_CTRL) The peripheral is not reset  */
#define   CCL_CTRL_SWRST_ENABLE_Val           _UINT8_(0x1)                                         /* (CCL_CTRL) The peripheral is reset  */
#define CCL_CTRL_SWRST_DISABLE                (CCL_CTRL_SWRST_DISABLE_Val << CCL_CTRL_SWRST_Pos)   /* (CCL_CTRL) The peripheral is not reset Position  */
#define CCL_CTRL_SWRST_ENABLE                 (CCL_CTRL_SWRST_ENABLE_Val << CCL_CTRL_SWRST_Pos)    /* (CCL_CTRL) The peripheral is reset Position  */
#define CCL_CTRL_ENABLE_Pos                   _UINT8_(1)                                           /* (CCL_CTRL) Enable Position */
#define CCL_CTRL_ENABLE_Msk                   (_UINT8_(0x1) << CCL_CTRL_ENABLE_Pos)                /* (CCL_CTRL) Enable Mask */
#define CCL_CTRL_ENABLE(value)                (CCL_CTRL_ENABLE_Msk & (_UINT8_(value) << CCL_CTRL_ENABLE_Pos)) /* Assigment of value for ENABLE in the CCL_CTRL register */
#define   CCL_CTRL_ENABLE_DISABLE_Val         _UINT8_(0x0)                                         /* (CCL_CTRL) The peripheral is disabled  */
#define   CCL_CTRL_ENABLE_ENABLE_Val          _UINT8_(0x1)                                         /* (CCL_CTRL) The peripheral is enabled  */
#define CCL_CTRL_ENABLE_DISABLE               (CCL_CTRL_ENABLE_DISABLE_Val << CCL_CTRL_ENABLE_Pos) /* (CCL_CTRL) The peripheral is disabled Position  */
#define CCL_CTRL_ENABLE_ENABLE                (CCL_CTRL_ENABLE_ENABLE_Val << CCL_CTRL_ENABLE_Pos)  /* (CCL_CTRL) The peripheral is enabled Position  */
#define CCL_CTRL_RUNSTDBY_Pos                 _UINT8_(6)                                           /* (CCL_CTRL) Run in Standby Position */
#define CCL_CTRL_RUNSTDBY_Msk                 (_UINT8_(0x1) << CCL_CTRL_RUNSTDBY_Pos)              /* (CCL_CTRL) Run in Standby Mask */
#define CCL_CTRL_RUNSTDBY(value)              (CCL_CTRL_RUNSTDBY_Msk & (_UINT8_(value) << CCL_CTRL_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the CCL_CTRL register */
#define   CCL_CTRL_RUNSTDBY_DISABLE_Val       _UINT8_(0x0)                                         /* (CCL_CTRL) Generic clock is not required in standby sleep mode  */
#define   CCL_CTRL_RUNSTDBY_ENABLE_Val        _UINT8_(0x1)                                         /* (CCL_CTRL) Generic clock is  required in standby sleep mode  */
#define CCL_CTRL_RUNSTDBY_DISABLE             (CCL_CTRL_RUNSTDBY_DISABLE_Val << CCL_CTRL_RUNSTDBY_Pos) /* (CCL_CTRL) Generic clock is not required in standby sleep mode Position  */
#define CCL_CTRL_RUNSTDBY_ENABLE              (CCL_CTRL_RUNSTDBY_ENABLE_Val << CCL_CTRL_RUNSTDBY_Pos) /* (CCL_CTRL) Generic clock is  required in standby sleep mode Position  */
#define CCL_CTRL_Msk                          _UINT8_(0x43)                                        /* (CCL_CTRL) Register Mask  */


/* -------- CCL_SEQCTRL : (CCL Offset: 0x04) (R/W 8) SEQ Control x -------- */
#define CCL_SEQCTRL_RESETVALUE                _UINT8_(0x00)                                        /*  (CCL_SEQCTRL) SEQ Control x  Reset Value */

#define CCL_SEQCTRL_SEQSEL_Pos                _UINT8_(0)                                           /* (CCL_SEQCTRL) Sequential Selection Position */
#define CCL_SEQCTRL_SEQSEL_Msk                (_UINT8_(0xF) << CCL_SEQCTRL_SEQSEL_Pos)             /* (CCL_SEQCTRL) Sequential Selection Mask */
#define CCL_SEQCTRL_SEQSEL(value)             (CCL_SEQCTRL_SEQSEL_Msk & (_UINT8_(value) << CCL_SEQCTRL_SEQSEL_Pos)) /* Assigment of value for SEQSEL in the CCL_SEQCTRL register */
#define   CCL_SEQCTRL_SEQSEL_DISABLE_Val      _UINT8_(0x0)                                         /* (CCL_SEQCTRL) Sequential logic is disabled  */
#define   CCL_SEQCTRL_SEQSEL_DFF_Val          _UINT8_(0x1)                                         /* (CCL_SEQCTRL) D flip flop  */
#define   CCL_SEQCTRL_SEQSEL_JK_Val           _UINT8_(0x2)                                         /* (CCL_SEQCTRL) JK flip flop  */
#define   CCL_SEQCTRL_SEQSEL_LATCH_Val        _UINT8_(0x3)                                         /* (CCL_SEQCTRL) D latch  */
#define   CCL_SEQCTRL_SEQSEL_RS_Val           _UINT8_(0x4)                                         /* (CCL_SEQCTRL) RS latch  */
#define CCL_SEQCTRL_SEQSEL_DISABLE            (CCL_SEQCTRL_SEQSEL_DISABLE_Val << CCL_SEQCTRL_SEQSEL_Pos) /* (CCL_SEQCTRL) Sequential logic is disabled Position  */
#define CCL_SEQCTRL_SEQSEL_DFF                (CCL_SEQCTRL_SEQSEL_DFF_Val << CCL_SEQCTRL_SEQSEL_Pos) /* (CCL_SEQCTRL) D flip flop Position  */
#define CCL_SEQCTRL_SEQSEL_JK                 (CCL_SEQCTRL_SEQSEL_JK_Val << CCL_SEQCTRL_SEQSEL_Pos) /* (CCL_SEQCTRL) JK flip flop Position  */
#define CCL_SEQCTRL_SEQSEL_LATCH              (CCL_SEQCTRL_SEQSEL_LATCH_Val << CCL_SEQCTRL_SEQSEL_Pos) /* (CCL_SEQCTRL) D latch Position  */
#define CCL_SEQCTRL_SEQSEL_RS                 (CCL_SEQCTRL_SEQSEL_RS_Val << CCL_SEQCTRL_SEQSEL_Pos) /* (CCL_SEQCTRL) RS latch Position  */
#define CCL_SEQCTRL_Msk                       _UINT8_(0x0F)                                        /* (CCL_SEQCTRL) Register Mask  */


/* -------- CCL_LUTCTRL : (CCL Offset: 0x08) (R/W 32) LUT Control x -------- */
#define CCL_LUTCTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (CCL_LUTCTRL) LUT Control x  Reset Value */

#define CCL_LUTCTRL_ENABLE_Pos                _UINT32_(1)                                          /* (CCL_LUTCTRL) LUT Enable Position */
#define CCL_LUTCTRL_ENABLE_Msk                (_UINT32_(0x1) << CCL_LUTCTRL_ENABLE_Pos)            /* (CCL_LUTCTRL) LUT Enable Mask */
#define CCL_LUTCTRL_ENABLE(value)             (CCL_LUTCTRL_ENABLE_Msk & (_UINT32_(value) << CCL_LUTCTRL_ENABLE_Pos)) /* Assigment of value for ENABLE in the CCL_LUTCTRL register */
#define   CCL_LUTCTRL_ENABLE_DISABLE_Val      _UINT32_(0x0)                                        /* (CCL_LUTCTRL) LUT block is disabled  */
#define   CCL_LUTCTRL_ENABLE_ENABLE_Val       _UINT32_(0x1)                                        /* (CCL_LUTCTRL) LUT block is enabled  */
#define CCL_LUTCTRL_ENABLE_DISABLE            (CCL_LUTCTRL_ENABLE_DISABLE_Val << CCL_LUTCTRL_ENABLE_Pos) /* (CCL_LUTCTRL) LUT block is disabled Position  */
#define CCL_LUTCTRL_ENABLE_ENABLE             (CCL_LUTCTRL_ENABLE_ENABLE_Val << CCL_LUTCTRL_ENABLE_Pos) /* (CCL_LUTCTRL) LUT block is enabled Position  */
#define CCL_LUTCTRL_FILTSEL_Pos               _UINT32_(4)                                          /* (CCL_LUTCTRL) Filter Selection Position */
#define CCL_LUTCTRL_FILTSEL_Msk               (_UINT32_(0x3) << CCL_LUTCTRL_FILTSEL_Pos)           /* (CCL_LUTCTRL) Filter Selection Mask */
#define CCL_LUTCTRL_FILTSEL(value)            (CCL_LUTCTRL_FILTSEL_Msk & (_UINT32_(value) << CCL_LUTCTRL_FILTSEL_Pos)) /* Assigment of value for FILTSEL in the CCL_LUTCTRL register */
#define   CCL_LUTCTRL_FILTSEL_DISABLE_Val     _UINT32_(0x0)                                        /* (CCL_LUTCTRL) Filter disabled  */
#define   CCL_LUTCTRL_FILTSEL_SYNCH_Val       _UINT32_(0x1)                                        /* (CCL_LUTCTRL) Synchronizer enabled  */
#define   CCL_LUTCTRL_FILTSEL_FILTER_Val      _UINT32_(0x2)                                        /* (CCL_LUTCTRL) Filter enabled  */
#define CCL_LUTCTRL_FILTSEL_DISABLE           (CCL_LUTCTRL_FILTSEL_DISABLE_Val << CCL_LUTCTRL_FILTSEL_Pos) /* (CCL_LUTCTRL) Filter disabled Position  */
#define CCL_LUTCTRL_FILTSEL_SYNCH             (CCL_LUTCTRL_FILTSEL_SYNCH_Val << CCL_LUTCTRL_FILTSEL_Pos) /* (CCL_LUTCTRL) Synchronizer enabled Position  */
#define CCL_LUTCTRL_FILTSEL_FILTER            (CCL_LUTCTRL_FILTSEL_FILTER_Val << CCL_LUTCTRL_FILTSEL_Pos) /* (CCL_LUTCTRL) Filter enabled Position  */
#define CCL_LUTCTRL_EDGESEL_Pos               _UINT32_(7)                                          /* (CCL_LUTCTRL) Edge Selection Position */
#define CCL_LUTCTRL_EDGESEL_Msk               (_UINT32_(0x1) << CCL_LUTCTRL_EDGESEL_Pos)           /* (CCL_LUTCTRL) Edge Selection Mask */
#define CCL_LUTCTRL_EDGESEL(value)            (CCL_LUTCTRL_EDGESEL_Msk & (_UINT32_(value) << CCL_LUTCTRL_EDGESEL_Pos)) /* Assigment of value for EDGESEL in the CCL_LUTCTRL register */
#define   CCL_LUTCTRL_EDGESEL_DISABLE_Val     _UINT32_(0x0)                                        /* (CCL_LUTCTRL) Edge detector is disabled  */
#define   CCL_LUTCTRL_EDGESEL_ENABLE_Val      _UINT32_(0x1)                                        /* (CCL_LUTCTRL) Edge detector is enabled  */
#define CCL_LUTCTRL_EDGESEL_DISABLE           (CCL_LUTCTRL_EDGESEL_DISABLE_Val << CCL_LUTCTRL_EDGESEL_Pos) /* (CCL_LUTCTRL) Edge detector is disabled Position  */
#define CCL_LUTCTRL_EDGESEL_ENABLE            (CCL_LUTCTRL_EDGESEL_ENABLE_Val << CCL_LUTCTRL_EDGESEL_Pos) /* (CCL_LUTCTRL) Edge detector is enabled Position  */
#define CCL_LUTCTRL_INSEL0_Pos                _UINT32_(8)                                          /* (CCL_LUTCTRL) Input Selection 0 Position */
#define CCL_LUTCTRL_INSEL0_Msk                (_UINT32_(0xF) << CCL_LUTCTRL_INSEL0_Pos)            /* (CCL_LUTCTRL) Input Selection 0 Mask */
#define CCL_LUTCTRL_INSEL0(value)             (CCL_LUTCTRL_INSEL0_Msk & (_UINT32_(value) << CCL_LUTCTRL_INSEL0_Pos)) /* Assigment of value for INSEL0 in the CCL_LUTCTRL register */
#define   CCL_LUTCTRL_INSEL0_MASK_Val         _UINT32_(0x0)                                        /* (CCL_LUTCTRL) Masked input  */
#define   CCL_LUTCTRL_INSEL0_FEEDBACK_Val     _UINT32_(0x1)                                        /* (CCL_LUTCTRL) Feedback input source  */
#define   CCL_LUTCTRL_INSEL0_LINK_Val         _UINT32_(0x2)                                        /* (CCL_LUTCTRL) Linked LUT input source  */
#define   CCL_LUTCTRL_INSEL0_EVENT_Val        _UINT32_(0x3)                                        /* (CCL_LUTCTRL) Event input source  */
#define   CCL_LUTCTRL_INSEL0_IO_Val           _UINT32_(0x4)                                        /* (CCL_LUTCTRL) I/O pin input source  */
#define   CCL_LUTCTRL_INSEL0_AC_Val           _UINT32_(0x5)                                        /* (CCL_LUTCTRL) AC input source  */
#define   CCL_LUTCTRL_INSEL0_TC_Val           _UINT32_(0x6)                                        /* (CCL_LUTCTRL) TC input source  */
#define   CCL_LUTCTRL_INSEL0_ALTTC_Val        _UINT32_(0x7)                                        /* (CCL_LUTCTRL) Alternate TC input source  */
#define   CCL_LUTCTRL_INSEL0_TCC_Val          _UINT32_(0x8)                                        /* (CCL_LUTCTRL) TCC input source  */
#define   CCL_LUTCTRL_INSEL0_SERCOM_Val       _UINT32_(0x9)                                        /* (CCL_LUTCTRL) SERCOM input source  */
#define CCL_LUTCTRL_INSEL0_MASK               (CCL_LUTCTRL_INSEL0_MASK_Val << CCL_LUTCTRL_INSEL0_Pos) /* (CCL_LUTCTRL) Masked input Position  */
#define CCL_LUTCTRL_INSEL0_FEEDBACK           (CCL_LUTCTRL_INSEL0_FEEDBACK_Val << CCL_LUTCTRL_INSEL0_Pos) /* (CCL_LUTCTRL) Feedback input source Position  */
#define CCL_LUTCTRL_INSEL0_LINK               (CCL_LUTCTRL_INSEL0_LINK_Val << CCL_LUTCTRL_INSEL0_Pos) /* (CCL_LUTCTRL) Linked LUT input source Position  */
#define CCL_LUTCTRL_INSEL0_EVENT              (CCL_LUTCTRL_INSEL0_EVENT_Val << CCL_LUTCTRL_INSEL0_Pos) /* (CCL_LUTCTRL) Event input source Position  */
#define CCL_LUTCTRL_INSEL0_IO                 (CCL_LUTCTRL_INSEL0_IO_Val << CCL_LUTCTRL_INSEL0_Pos) /* (CCL_LUTCTRL) I/O pin input source Position  */
#define CCL_LUTCTRL_INSEL0_AC                 (CCL_LUTCTRL_INSEL0_AC_Val << CCL_LUTCTRL_INSEL0_Pos) /* (CCL_LUTCTRL) AC input source Position  */
#define CCL_LUTCTRL_INSEL0_TC                 (CCL_LUTCTRL_INSEL0_TC_Val << CCL_LUTCTRL_INSEL0_Pos) /* (CCL_LUTCTRL) TC input source Position  */
#define CCL_LUTCTRL_INSEL0_ALTTC              (CCL_LUTCTRL_INSEL0_ALTTC_Val << CCL_LUTCTRL_INSEL0_Pos) /* (CCL_LUTCTRL) Alternate TC input source Position  */
#define CCL_LUTCTRL_INSEL0_TCC                (CCL_LUTCTRL_INSEL0_TCC_Val << CCL_LUTCTRL_INSEL0_Pos) /* (CCL_LUTCTRL) TCC input source Position  */
#define CCL_LUTCTRL_INSEL0_SERCOM             (CCL_LUTCTRL_INSEL0_SERCOM_Val << CCL_LUTCTRL_INSEL0_Pos) /* (CCL_LUTCTRL) SERCOM input source Position  */
#define CCL_LUTCTRL_INSEL1_Pos                _UINT32_(12)                                         /* (CCL_LUTCTRL) Input Selection 1 Position */
#define CCL_LUTCTRL_INSEL1_Msk                (_UINT32_(0xF) << CCL_LUTCTRL_INSEL1_Pos)            /* (CCL_LUTCTRL) Input Selection 1 Mask */
#define CCL_LUTCTRL_INSEL1(value)             (CCL_LUTCTRL_INSEL1_Msk & (_UINT32_(value) << CCL_LUTCTRL_INSEL1_Pos)) /* Assigment of value for INSEL1 in the CCL_LUTCTRL register */
#define   CCL_LUTCTRL_INSEL1_MASK_Val         _UINT32_(0x0)                                        /* (CCL_LUTCTRL) Masked input  */
#define   CCL_LUTCTRL_INSEL1_FEEDBACK_Val     _UINT32_(0x1)                                        /* (CCL_LUTCTRL) Feedback input source  */
#define   CCL_LUTCTRL_INSEL1_LINK_Val         _UINT32_(0x2)                                        /* (CCL_LUTCTRL) Linked LUT input source  */
#define   CCL_LUTCTRL_INSEL1_EVENT_Val        _UINT32_(0x3)                                        /* (CCL_LUTCTRL) Event input source  */
#define   CCL_LUTCTRL_INSEL1_IO_Val           _UINT32_(0x4)                                        /* (CCL_LUTCTRL) I/O pin input source  */
#define   CCL_LUTCTRL_INSEL1_AC_Val           _UINT32_(0x5)                                        /* (CCL_LUTCTRL) AC input source  */
#define   CCL_LUTCTRL_INSEL1_TC_Val           _UINT32_(0x6)                                        /* (CCL_LUTCTRL) TC input source  */
#define   CCL_LUTCTRL_INSEL1_ALTTC_Val        _UINT32_(0x7)                                        /* (CCL_LUTCTRL) Alternate TC input source  */
#define   CCL_LUTCTRL_INSEL1_TCC_Val          _UINT32_(0x8)                                        /* (CCL_LUTCTRL) TCC input source  */
#define   CCL_LUTCTRL_INSEL1_SERCOM_Val       _UINT32_(0x9)                                        /* (CCL_LUTCTRL) SERCOM input source  */
#define CCL_LUTCTRL_INSEL1_MASK               (CCL_LUTCTRL_INSEL1_MASK_Val << CCL_LUTCTRL_INSEL1_Pos) /* (CCL_LUTCTRL) Masked input Position  */
#define CCL_LUTCTRL_INSEL1_FEEDBACK           (CCL_LUTCTRL_INSEL1_FEEDBACK_Val << CCL_LUTCTRL_INSEL1_Pos) /* (CCL_LUTCTRL) Feedback input source Position  */
#define CCL_LUTCTRL_INSEL1_LINK               (CCL_LUTCTRL_INSEL1_LINK_Val << CCL_LUTCTRL_INSEL1_Pos) /* (CCL_LUTCTRL) Linked LUT input source Position  */
#define CCL_LUTCTRL_INSEL1_EVENT              (CCL_LUTCTRL_INSEL1_EVENT_Val << CCL_LUTCTRL_INSEL1_Pos) /* (CCL_LUTCTRL) Event input source Position  */
#define CCL_LUTCTRL_INSEL1_IO                 (CCL_LUTCTRL_INSEL1_IO_Val << CCL_LUTCTRL_INSEL1_Pos) /* (CCL_LUTCTRL) I/O pin input source Position  */
#define CCL_LUTCTRL_INSEL1_AC                 (CCL_LUTCTRL_INSEL1_AC_Val << CCL_LUTCTRL_INSEL1_Pos) /* (CCL_LUTCTRL) AC input source Position  */
#define CCL_LUTCTRL_INSEL1_TC                 (CCL_LUTCTRL_INSEL1_TC_Val << CCL_LUTCTRL_INSEL1_Pos) /* (CCL_LUTCTRL) TC input source Position  */
#define CCL_LUTCTRL_INSEL1_ALTTC              (CCL_LUTCTRL_INSEL1_ALTTC_Val << CCL_LUTCTRL_INSEL1_Pos) /* (CCL_LUTCTRL) Alternate TC input source Position  */
#define CCL_LUTCTRL_INSEL1_TCC                (CCL_LUTCTRL_INSEL1_TCC_Val << CCL_LUTCTRL_INSEL1_Pos) /* (CCL_LUTCTRL) TCC input source Position  */
#define CCL_LUTCTRL_INSEL1_SERCOM             (CCL_LUTCTRL_INSEL1_SERCOM_Val << CCL_LUTCTRL_INSEL1_Pos) /* (CCL_LUTCTRL) SERCOM input source Position  */
#define CCL_LUTCTRL_INSEL2_Pos                _UINT32_(16)                                         /* (CCL_LUTCTRL) Input Selection 2 Position */
#define CCL_LUTCTRL_INSEL2_Msk                (_UINT32_(0xF) << CCL_LUTCTRL_INSEL2_Pos)            /* (CCL_LUTCTRL) Input Selection 2 Mask */
#define CCL_LUTCTRL_INSEL2(value)             (CCL_LUTCTRL_INSEL2_Msk & (_UINT32_(value) << CCL_LUTCTRL_INSEL2_Pos)) /* Assigment of value for INSEL2 in the CCL_LUTCTRL register */
#define   CCL_LUTCTRL_INSEL2_MASK_Val         _UINT32_(0x0)                                        /* (CCL_LUTCTRL) Masked input  */
#define   CCL_LUTCTRL_INSEL2_FEEDBACK_Val     _UINT32_(0x1)                                        /* (CCL_LUTCTRL) Feedback input source  */
#define   CCL_LUTCTRL_INSEL2_LINK_Val         _UINT32_(0x2)                                        /* (CCL_LUTCTRL) Linked LUT input source  */
#define   CCL_LUTCTRL_INSEL2_EVENT_Val        _UINT32_(0x3)                                        /* (CCL_LUTCTRL) Event input source  */
#define   CCL_LUTCTRL_INSEL2_IO_Val           _UINT32_(0x4)                                        /* (CCL_LUTCTRL) I/O pin input source  */
#define   CCL_LUTCTRL_INSEL2_AC_Val           _UINT32_(0x5)                                        /* (CCL_LUTCTRL) AC input source  */
#define   CCL_LUTCTRL_INSEL2_TC_Val           _UINT32_(0x6)                                        /* (CCL_LUTCTRL) TC input source  */
#define   CCL_LUTCTRL_INSEL2_ALTTC_Val        _UINT32_(0x7)                                        /* (CCL_LUTCTRL) Alternate TC input source  */
#define   CCL_LUTCTRL_INSEL2_TCC_Val          _UINT32_(0x8)                                        /* (CCL_LUTCTRL) TCC input source  */
#define   CCL_LUTCTRL_INSEL2_SERCOM_Val       _UINT32_(0x9)                                        /* (CCL_LUTCTRL) SERCOM input source  */
#define CCL_LUTCTRL_INSEL2_MASK               (CCL_LUTCTRL_INSEL2_MASK_Val << CCL_LUTCTRL_INSEL2_Pos) /* (CCL_LUTCTRL) Masked input Position  */
#define CCL_LUTCTRL_INSEL2_FEEDBACK           (CCL_LUTCTRL_INSEL2_FEEDBACK_Val << CCL_LUTCTRL_INSEL2_Pos) /* (CCL_LUTCTRL) Feedback input source Position  */
#define CCL_LUTCTRL_INSEL2_LINK               (CCL_LUTCTRL_INSEL2_LINK_Val << CCL_LUTCTRL_INSEL2_Pos) /* (CCL_LUTCTRL) Linked LUT input source Position  */
#define CCL_LUTCTRL_INSEL2_EVENT              (CCL_LUTCTRL_INSEL2_EVENT_Val << CCL_LUTCTRL_INSEL2_Pos) /* (CCL_LUTCTRL) Event input source Position  */
#define CCL_LUTCTRL_INSEL2_IO                 (CCL_LUTCTRL_INSEL2_IO_Val << CCL_LUTCTRL_INSEL2_Pos) /* (CCL_LUTCTRL) I/O pin input source Position  */
#define CCL_LUTCTRL_INSEL2_AC                 (CCL_LUTCTRL_INSEL2_AC_Val << CCL_LUTCTRL_INSEL2_Pos) /* (CCL_LUTCTRL) AC input source Position  */
#define CCL_LUTCTRL_INSEL2_TC                 (CCL_LUTCTRL_INSEL2_TC_Val << CCL_LUTCTRL_INSEL2_Pos) /* (CCL_LUTCTRL) TC input source Position  */
#define CCL_LUTCTRL_INSEL2_ALTTC              (CCL_LUTCTRL_INSEL2_ALTTC_Val << CCL_LUTCTRL_INSEL2_Pos) /* (CCL_LUTCTRL) Alternate TC input source Position  */
#define CCL_LUTCTRL_INSEL2_TCC                (CCL_LUTCTRL_INSEL2_TCC_Val << CCL_LUTCTRL_INSEL2_Pos) /* (CCL_LUTCTRL) TCC input source Position  */
#define CCL_LUTCTRL_INSEL2_SERCOM             (CCL_LUTCTRL_INSEL2_SERCOM_Val << CCL_LUTCTRL_INSEL2_Pos) /* (CCL_LUTCTRL) SERCOM input source Position  */
#define CCL_LUTCTRL_INVEI_Pos                 _UINT32_(20)                                         /* (CCL_LUTCTRL) Inverted Event Input Enable Position */
#define CCL_LUTCTRL_INVEI_Msk                 (_UINT32_(0x1) << CCL_LUTCTRL_INVEI_Pos)             /* (CCL_LUTCTRL) Inverted Event Input Enable Mask */
#define CCL_LUTCTRL_INVEI(value)              (CCL_LUTCTRL_INVEI_Msk & (_UINT32_(value) << CCL_LUTCTRL_INVEI_Pos)) /* Assigment of value for INVEI in the CCL_LUTCTRL register */
#define   CCL_LUTCTRL_INVEI_DISABLE_Val       _UINT32_(0x0)                                        /* (CCL_LUTCTRL) Incoming event is not inverted  */
#define   CCL_LUTCTRL_INVEI_ENABLE_Val        _UINT32_(0x1)                                        /* (CCL_LUTCTRL) Incoming event is inverted  */
#define CCL_LUTCTRL_INVEI_DISABLE             (CCL_LUTCTRL_INVEI_DISABLE_Val << CCL_LUTCTRL_INVEI_Pos) /* (CCL_LUTCTRL) Incoming event is not inverted Position  */
#define CCL_LUTCTRL_INVEI_ENABLE              (CCL_LUTCTRL_INVEI_ENABLE_Val << CCL_LUTCTRL_INVEI_Pos) /* (CCL_LUTCTRL) Incoming event is inverted Position  */
#define CCL_LUTCTRL_LUTEI_Pos                 _UINT32_(21)                                         /* (CCL_LUTCTRL) LUT Event Input Enable Position */
#define CCL_LUTCTRL_LUTEI_Msk                 (_UINT32_(0x1) << CCL_LUTCTRL_LUTEI_Pos)             /* (CCL_LUTCTRL) LUT Event Input Enable Mask */
#define CCL_LUTCTRL_LUTEI(value)              (CCL_LUTCTRL_LUTEI_Msk & (_UINT32_(value) << CCL_LUTCTRL_LUTEI_Pos)) /* Assigment of value for LUTEI in the CCL_LUTCTRL register */
#define   CCL_LUTCTRL_LUTEI_DISABLE_Val       _UINT32_(0x0)                                        /* (CCL_LUTCTRL) LUT incoming event is disabled  */
#define   CCL_LUTCTRL_LUTEI_ENABLE_Val        _UINT32_(0x1)                                        /* (CCL_LUTCTRL) LUT incoming event is enabled  */
#define CCL_LUTCTRL_LUTEI_DISABLE             (CCL_LUTCTRL_LUTEI_DISABLE_Val << CCL_LUTCTRL_LUTEI_Pos) /* (CCL_LUTCTRL) LUT incoming event is disabled Position  */
#define CCL_LUTCTRL_LUTEI_ENABLE              (CCL_LUTCTRL_LUTEI_ENABLE_Val << CCL_LUTCTRL_LUTEI_Pos) /* (CCL_LUTCTRL) LUT incoming event is enabled Position  */
#define CCL_LUTCTRL_LUTEO_Pos                 _UINT32_(22)                                         /* (CCL_LUTCTRL) LUT Event Output Enable Position */
#define CCL_LUTCTRL_LUTEO_Msk                 (_UINT32_(0x1) << CCL_LUTCTRL_LUTEO_Pos)             /* (CCL_LUTCTRL) LUT Event Output Enable Mask */
#define CCL_LUTCTRL_LUTEO(value)              (CCL_LUTCTRL_LUTEO_Msk & (_UINT32_(value) << CCL_LUTCTRL_LUTEO_Pos)) /* Assigment of value for LUTEO in the CCL_LUTCTRL register */
#define   CCL_LUTCTRL_LUTEO_DISABLE_Val       _UINT32_(0x0)                                        /* (CCL_LUTCTRL) LUT event output is disabled  */
#define   CCL_LUTCTRL_LUTEO_ENABLE_Val        _UINT32_(0x1)                                        /* (CCL_LUTCTRL) LUT event output is enabled  */
#define CCL_LUTCTRL_LUTEO_DISABLE             (CCL_LUTCTRL_LUTEO_DISABLE_Val << CCL_LUTCTRL_LUTEO_Pos) /* (CCL_LUTCTRL) LUT event output is disabled Position  */
#define CCL_LUTCTRL_LUTEO_ENABLE              (CCL_LUTCTRL_LUTEO_ENABLE_Val << CCL_LUTCTRL_LUTEO_Pos) /* (CCL_LUTCTRL) LUT event output is enabled Position  */
#define CCL_LUTCTRL_TRUTH_Pos                 _UINT32_(24)                                         /* (CCL_LUTCTRL) Truth Value Position */
#define CCL_LUTCTRL_TRUTH_Msk                 (_UINT32_(0xFF) << CCL_LUTCTRL_TRUTH_Pos)            /* (CCL_LUTCTRL) Truth Value Mask */
#define CCL_LUTCTRL_TRUTH(value)              (CCL_LUTCTRL_TRUTH_Msk & (_UINT32_(value) << CCL_LUTCTRL_TRUTH_Pos)) /* Assigment of value for TRUTH in the CCL_LUTCTRL register */
#define CCL_LUTCTRL_Msk                       _UINT32_(0xFF7FFFB2)                                 /* (CCL_LUTCTRL) Register Mask  */


/** \brief CCL register offsets definitions */
#define CCL_CTRL_REG_OFST              _UINT32_(0x00)      /* (CCL_CTRL) Control Offset */
#define CCL_SEQCTRL_REG_OFST           _UINT32_(0x04)      /* (CCL_SEQCTRL) SEQ Control x Offset */
#define CCL_SEQCTRL0_REG_OFST          _UINT32_(0x04)      /* (CCL_SEQCTRL0) SEQ Control x Offset */
#define CCL_SEQCTRL1_REG_OFST          _UINT32_(0x05)      /* (CCL_SEQCTRL1) SEQ Control x Offset */
#define CCL_LUTCTRL_REG_OFST           _UINT32_(0x08)      /* (CCL_LUTCTRL) LUT Control x Offset */
#define CCL_LUTCTRL0_REG_OFST          _UINT32_(0x08)      /* (CCL_LUTCTRL0) LUT Control x Offset */
#define CCL_LUTCTRL1_REG_OFST          _UINT32_(0x0C)      /* (CCL_LUTCTRL1) LUT Control x Offset */
#define CCL_LUTCTRL2_REG_OFST          _UINT32_(0x10)      /* (CCL_LUTCTRL2) LUT Control x Offset */
#define CCL_LUTCTRL3_REG_OFST          _UINT32_(0x14)      /* (CCL_LUTCTRL3) LUT Control x Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief CCL register API structure */
typedef struct
{  /* Configurable Custom Logic */
  __IO  uint8_t                        CCL_CTRL;           /**< Offset: 0x00 (R/W  8) Control */
  __I   uint8_t                        Reserved1[0x03];
  __IO  uint8_t                        CCL_SEQCTRL[2];     /**< Offset: 0x04 (R/W  8) SEQ Control x */
  __I   uint8_t                        Reserved2[0x02];
  __IO  uint32_t                       CCL_LUTCTRL[4];     /**< Offset: 0x08 (R/W  32) LUT Control x */
} ccl_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAME54_CCL_COMPONENT_H_ */
