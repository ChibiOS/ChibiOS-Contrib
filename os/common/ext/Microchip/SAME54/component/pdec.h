/*
 * Component description for PDEC
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
#ifndef _SAME54_PDEC_COMPONENT_H_
#define _SAME54_PDEC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PDEC                                         */
/* ************************************************************************** */

/* -------- PDEC_CTRLA : (PDEC Offset: 0x00) (R/W 32) Control A -------- */
#define PDEC_CTRLA_RESETVALUE                 _UINT32_(0x00)                                       /*  (PDEC_CTRLA) Control A  Reset Value */

#define PDEC_CTRLA_SWRST_Pos                  _UINT32_(0)                                          /* (PDEC_CTRLA) Software Reset Position */
#define PDEC_CTRLA_SWRST_Msk                  (_UINT32_(0x1) << PDEC_CTRLA_SWRST_Pos)              /* (PDEC_CTRLA) Software Reset Mask */
#define PDEC_CTRLA_SWRST(value)               (PDEC_CTRLA_SWRST_Msk & (_UINT32_(value) << PDEC_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the PDEC_CTRLA register */
#define PDEC_CTRLA_ENABLE_Pos                 _UINT32_(1)                                          /* (PDEC_CTRLA) Enable Position */
#define PDEC_CTRLA_ENABLE_Msk                 (_UINT32_(0x1) << PDEC_CTRLA_ENABLE_Pos)             /* (PDEC_CTRLA) Enable Mask */
#define PDEC_CTRLA_ENABLE(value)              (PDEC_CTRLA_ENABLE_Msk & (_UINT32_(value) << PDEC_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the PDEC_CTRLA register */
#define PDEC_CTRLA_MODE_Pos                   _UINT32_(2)                                          /* (PDEC_CTRLA) Operation Mode Position */
#define PDEC_CTRLA_MODE_Msk                   (_UINT32_(0x3) << PDEC_CTRLA_MODE_Pos)               /* (PDEC_CTRLA) Operation Mode Mask */
#define PDEC_CTRLA_MODE(value)                (PDEC_CTRLA_MODE_Msk & (_UINT32_(value) << PDEC_CTRLA_MODE_Pos)) /* Assigment of value for MODE in the PDEC_CTRLA register */
#define   PDEC_CTRLA_MODE_QDEC_Val            _UINT32_(0x0)                                        /* (PDEC_CTRLA) QDEC operating mode  */
#define   PDEC_CTRLA_MODE_HALL_Val            _UINT32_(0x1)                                        /* (PDEC_CTRLA) HALL operating mode  */
#define   PDEC_CTRLA_MODE_COUNTER_Val         _UINT32_(0x2)                                        /* (PDEC_CTRLA) COUNTER operating mode  */
#define PDEC_CTRLA_MODE_QDEC                  (PDEC_CTRLA_MODE_QDEC_Val << PDEC_CTRLA_MODE_Pos)    /* (PDEC_CTRLA) QDEC operating mode Position  */
#define PDEC_CTRLA_MODE_HALL                  (PDEC_CTRLA_MODE_HALL_Val << PDEC_CTRLA_MODE_Pos)    /* (PDEC_CTRLA) HALL operating mode Position  */
#define PDEC_CTRLA_MODE_COUNTER               (PDEC_CTRLA_MODE_COUNTER_Val << PDEC_CTRLA_MODE_Pos) /* (PDEC_CTRLA) COUNTER operating mode Position  */
#define PDEC_CTRLA_RUNSTDBY_Pos               _UINT32_(6)                                          /* (PDEC_CTRLA) Run in Standby Position */
#define PDEC_CTRLA_RUNSTDBY_Msk               (_UINT32_(0x1) << PDEC_CTRLA_RUNSTDBY_Pos)           /* (PDEC_CTRLA) Run in Standby Mask */
#define PDEC_CTRLA_RUNSTDBY(value)            (PDEC_CTRLA_RUNSTDBY_Msk & (_UINT32_(value) << PDEC_CTRLA_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the PDEC_CTRLA register */
#define PDEC_CTRLA_CONF_Pos                   _UINT32_(8)                                          /* (PDEC_CTRLA) PDEC Configuration Position */
#define PDEC_CTRLA_CONF_Msk                   (_UINT32_(0x7) << PDEC_CTRLA_CONF_Pos)               /* (PDEC_CTRLA) PDEC Configuration Mask */
#define PDEC_CTRLA_CONF(value)                (PDEC_CTRLA_CONF_Msk & (_UINT32_(value) << PDEC_CTRLA_CONF_Pos)) /* Assigment of value for CONF in the PDEC_CTRLA register */
#define   PDEC_CTRLA_CONF_X4_Val              _UINT32_(0x0)                                        /* (PDEC_CTRLA) Quadrature decoder direction  */
#define   PDEC_CTRLA_CONF_X4S_Val             _UINT32_(0x1)                                        /* (PDEC_CTRLA) Secure Quadrature decoder direction  */
#define   PDEC_CTRLA_CONF_X2_Val              _UINT32_(0x2)                                        /* (PDEC_CTRLA) Decoder direction  */
#define   PDEC_CTRLA_CONF_X2S_Val             _UINT32_(0x3)                                        /* (PDEC_CTRLA) Secure decoder direction  */
#define   PDEC_CTRLA_CONF_AUTOC_Val           _UINT32_(0x4)                                        /* (PDEC_CTRLA) Auto correction mode  */
#define PDEC_CTRLA_CONF_X4                    (PDEC_CTRLA_CONF_X4_Val << PDEC_CTRLA_CONF_Pos)      /* (PDEC_CTRLA) Quadrature decoder direction Position  */
#define PDEC_CTRLA_CONF_X4S                   (PDEC_CTRLA_CONF_X4S_Val << PDEC_CTRLA_CONF_Pos)     /* (PDEC_CTRLA) Secure Quadrature decoder direction Position  */
#define PDEC_CTRLA_CONF_X2                    (PDEC_CTRLA_CONF_X2_Val << PDEC_CTRLA_CONF_Pos)      /* (PDEC_CTRLA) Decoder direction Position  */
#define PDEC_CTRLA_CONF_X2S                   (PDEC_CTRLA_CONF_X2S_Val << PDEC_CTRLA_CONF_Pos)     /* (PDEC_CTRLA) Secure decoder direction Position  */
#define PDEC_CTRLA_CONF_AUTOC                 (PDEC_CTRLA_CONF_AUTOC_Val << PDEC_CTRLA_CONF_Pos)   /* (PDEC_CTRLA) Auto correction mode Position  */
#define PDEC_CTRLA_ALOCK_Pos                  _UINT32_(11)                                         /* (PDEC_CTRLA) Auto Lock Position */
#define PDEC_CTRLA_ALOCK_Msk                  (_UINT32_(0x1) << PDEC_CTRLA_ALOCK_Pos)              /* (PDEC_CTRLA) Auto Lock Mask */
#define PDEC_CTRLA_ALOCK(value)               (PDEC_CTRLA_ALOCK_Msk & (_UINT32_(value) << PDEC_CTRLA_ALOCK_Pos)) /* Assigment of value for ALOCK in the PDEC_CTRLA register */
#define PDEC_CTRLA_SWAP_Pos                   _UINT32_(14)                                         /* (PDEC_CTRLA) PDEC Phase A and B Swap Position */
#define PDEC_CTRLA_SWAP_Msk                   (_UINT32_(0x1) << PDEC_CTRLA_SWAP_Pos)               /* (PDEC_CTRLA) PDEC Phase A and B Swap Mask */
#define PDEC_CTRLA_SWAP(value)                (PDEC_CTRLA_SWAP_Msk & (_UINT32_(value) << PDEC_CTRLA_SWAP_Pos)) /* Assigment of value for SWAP in the PDEC_CTRLA register */
#define PDEC_CTRLA_PEREN_Pos                  _UINT32_(15)                                         /* (PDEC_CTRLA) Period Enable Position */
#define PDEC_CTRLA_PEREN_Msk                  (_UINT32_(0x1) << PDEC_CTRLA_PEREN_Pos)              /* (PDEC_CTRLA) Period Enable Mask */
#define PDEC_CTRLA_PEREN(value)               (PDEC_CTRLA_PEREN_Msk & (_UINT32_(value) << PDEC_CTRLA_PEREN_Pos)) /* Assigment of value for PEREN in the PDEC_CTRLA register */
#define PDEC_CTRLA_PINEN0_Pos                 _UINT32_(16)                                         /* (PDEC_CTRLA) PDEC Input From Pin 0 Enable Position */
#define PDEC_CTRLA_PINEN0_Msk                 (_UINT32_(0x1) << PDEC_CTRLA_PINEN0_Pos)             /* (PDEC_CTRLA) PDEC Input From Pin 0 Enable Mask */
#define PDEC_CTRLA_PINEN0(value)              (PDEC_CTRLA_PINEN0_Msk & (_UINT32_(value) << PDEC_CTRLA_PINEN0_Pos)) /* Assigment of value for PINEN0 in the PDEC_CTRLA register */
#define PDEC_CTRLA_PINEN1_Pos                 _UINT32_(17)                                         /* (PDEC_CTRLA) PDEC Input From Pin 1 Enable Position */
#define PDEC_CTRLA_PINEN1_Msk                 (_UINT32_(0x1) << PDEC_CTRLA_PINEN1_Pos)             /* (PDEC_CTRLA) PDEC Input From Pin 1 Enable Mask */
#define PDEC_CTRLA_PINEN1(value)              (PDEC_CTRLA_PINEN1_Msk & (_UINT32_(value) << PDEC_CTRLA_PINEN1_Pos)) /* Assigment of value for PINEN1 in the PDEC_CTRLA register */
#define PDEC_CTRLA_PINEN2_Pos                 _UINT32_(18)                                         /* (PDEC_CTRLA) PDEC Input From Pin 2 Enable Position */
#define PDEC_CTRLA_PINEN2_Msk                 (_UINT32_(0x1) << PDEC_CTRLA_PINEN2_Pos)             /* (PDEC_CTRLA) PDEC Input From Pin 2 Enable Mask */
#define PDEC_CTRLA_PINEN2(value)              (PDEC_CTRLA_PINEN2_Msk & (_UINT32_(value) << PDEC_CTRLA_PINEN2_Pos)) /* Assigment of value for PINEN2 in the PDEC_CTRLA register */
#define PDEC_CTRLA_PINVEN0_Pos                _UINT32_(20)                                         /* (PDEC_CTRLA) IO Pin 0 Invert Enable Position */
#define PDEC_CTRLA_PINVEN0_Msk                (_UINT32_(0x1) << PDEC_CTRLA_PINVEN0_Pos)            /* (PDEC_CTRLA) IO Pin 0 Invert Enable Mask */
#define PDEC_CTRLA_PINVEN0(value)             (PDEC_CTRLA_PINVEN0_Msk & (_UINT32_(value) << PDEC_CTRLA_PINVEN0_Pos)) /* Assigment of value for PINVEN0 in the PDEC_CTRLA register */
#define PDEC_CTRLA_PINVEN1_Pos                _UINT32_(21)                                         /* (PDEC_CTRLA) IO Pin 1 Invert Enable Position */
#define PDEC_CTRLA_PINVEN1_Msk                (_UINT32_(0x1) << PDEC_CTRLA_PINVEN1_Pos)            /* (PDEC_CTRLA) IO Pin 1 Invert Enable Mask */
#define PDEC_CTRLA_PINVEN1(value)             (PDEC_CTRLA_PINVEN1_Msk & (_UINT32_(value) << PDEC_CTRLA_PINVEN1_Pos)) /* Assigment of value for PINVEN1 in the PDEC_CTRLA register */
#define PDEC_CTRLA_PINVEN2_Pos                _UINT32_(22)                                         /* (PDEC_CTRLA) IO Pin 2 Invert Enable Position */
#define PDEC_CTRLA_PINVEN2_Msk                (_UINT32_(0x1) << PDEC_CTRLA_PINVEN2_Pos)            /* (PDEC_CTRLA) IO Pin 2 Invert Enable Mask */
#define PDEC_CTRLA_PINVEN2(value)             (PDEC_CTRLA_PINVEN2_Msk & (_UINT32_(value) << PDEC_CTRLA_PINVEN2_Pos)) /* Assigment of value for PINVEN2 in the PDEC_CTRLA register */
#define PDEC_CTRLA_ANGULAR_Pos                _UINT32_(24)                                         /* (PDEC_CTRLA) Angular Counter Length Position */
#define PDEC_CTRLA_ANGULAR_Msk                (_UINT32_(0x7) << PDEC_CTRLA_ANGULAR_Pos)            /* (PDEC_CTRLA) Angular Counter Length Mask */
#define PDEC_CTRLA_ANGULAR(value)             (PDEC_CTRLA_ANGULAR_Msk & (_UINT32_(value) << PDEC_CTRLA_ANGULAR_Pos)) /* Assigment of value for ANGULAR in the PDEC_CTRLA register */
#define PDEC_CTRLA_MAXCMP_Pos                 _UINT32_(28)                                         /* (PDEC_CTRLA) Maximum Consecutive Missing Pulses Position */
#define PDEC_CTRLA_MAXCMP_Msk                 (_UINT32_(0xF) << PDEC_CTRLA_MAXCMP_Pos)             /* (PDEC_CTRLA) Maximum Consecutive Missing Pulses Mask */
#define PDEC_CTRLA_MAXCMP(value)              (PDEC_CTRLA_MAXCMP_Msk & (_UINT32_(value) << PDEC_CTRLA_MAXCMP_Pos)) /* Assigment of value for MAXCMP in the PDEC_CTRLA register */
#define PDEC_CTRLA_Msk                        _UINT32_(0xF777CF4F)                                 /* (PDEC_CTRLA) Register Mask  */

#define PDEC_CTRLA_PINEN_Pos                  _UINT32_(16)                                         /* (PDEC_CTRLA Position) PDEC Input From Pin x Enable */
#define PDEC_CTRLA_PINEN_Msk                  (_UINT32_(0x7) << PDEC_CTRLA_PINEN_Pos)              /* (PDEC_CTRLA Mask) PINEN */
#define PDEC_CTRLA_PINEN(value)               (PDEC_CTRLA_PINEN_Msk & (_UINT32_(value) << PDEC_CTRLA_PINEN_Pos)) 
#define PDEC_CTRLA_PINVEN_Pos                 _UINT32_(20)                                         /* (PDEC_CTRLA Position) IO Pin x Invert Enable */
#define PDEC_CTRLA_PINVEN_Msk                 (_UINT32_(0x7) << PDEC_CTRLA_PINVEN_Pos)             /* (PDEC_CTRLA Mask) PINVEN */
#define PDEC_CTRLA_PINVEN(value)              (PDEC_CTRLA_PINVEN_Msk & (_UINT32_(value) << PDEC_CTRLA_PINVEN_Pos)) 

/* -------- PDEC_CTRLBCLR : (PDEC Offset: 0x04) (R/W 8) Control B Clear -------- */
#define PDEC_CTRLBCLR_RESETVALUE              _UINT8_(0x00)                                        /*  (PDEC_CTRLBCLR) Control B Clear  Reset Value */

#define PDEC_CTRLBCLR_LUPD_Pos                _UINT8_(1)                                           /* (PDEC_CTRLBCLR) Lock Update Position */
#define PDEC_CTRLBCLR_LUPD_Msk                (_UINT8_(0x1) << PDEC_CTRLBCLR_LUPD_Pos)             /* (PDEC_CTRLBCLR) Lock Update Mask */
#define PDEC_CTRLBCLR_LUPD(value)             (PDEC_CTRLBCLR_LUPD_Msk & (_UINT8_(value) << PDEC_CTRLBCLR_LUPD_Pos)) /* Assigment of value for LUPD in the PDEC_CTRLBCLR register */
#define PDEC_CTRLBCLR_CMD_Pos                 _UINT8_(5)                                           /* (PDEC_CTRLBCLR) Command Position */
#define PDEC_CTRLBCLR_CMD_Msk                 (_UINT8_(0x7) << PDEC_CTRLBCLR_CMD_Pos)              /* (PDEC_CTRLBCLR) Command Mask */
#define PDEC_CTRLBCLR_CMD(value)              (PDEC_CTRLBCLR_CMD_Msk & (_UINT8_(value) << PDEC_CTRLBCLR_CMD_Pos)) /* Assigment of value for CMD in the PDEC_CTRLBCLR register */
#define   PDEC_CTRLBCLR_CMD_NONE_Val          _UINT8_(0x0)                                         /* (PDEC_CTRLBCLR) No action  */
#define   PDEC_CTRLBCLR_CMD_RETRIGGER_Val     _UINT8_(0x1)                                         /* (PDEC_CTRLBCLR) Force a counter restart or retrigger  */
#define   PDEC_CTRLBCLR_CMD_UPDATE_Val        _UINT8_(0x2)                                         /* (PDEC_CTRLBCLR) Force update of double buffered registers  */
#define   PDEC_CTRLBCLR_CMD_READSYNC_Val      _UINT8_(0x3)                                         /* (PDEC_CTRLBCLR) Force a read synchronization of COUNT  */
#define   PDEC_CTRLBCLR_CMD_START_Val         _UINT8_(0x4)                                         /* (PDEC_CTRLBCLR) Start QDEC/HALL  */
#define   PDEC_CTRLBCLR_CMD_STOP_Val          _UINT8_(0x5)                                         /* (PDEC_CTRLBCLR) Stop QDEC/HALL  */
#define PDEC_CTRLBCLR_CMD_NONE                (PDEC_CTRLBCLR_CMD_NONE_Val << PDEC_CTRLBCLR_CMD_Pos) /* (PDEC_CTRLBCLR) No action Position  */
#define PDEC_CTRLBCLR_CMD_RETRIGGER           (PDEC_CTRLBCLR_CMD_RETRIGGER_Val << PDEC_CTRLBCLR_CMD_Pos) /* (PDEC_CTRLBCLR) Force a counter restart or retrigger Position  */
#define PDEC_CTRLBCLR_CMD_UPDATE              (PDEC_CTRLBCLR_CMD_UPDATE_Val << PDEC_CTRLBCLR_CMD_Pos) /* (PDEC_CTRLBCLR) Force update of double buffered registers Position  */
#define PDEC_CTRLBCLR_CMD_READSYNC            (PDEC_CTRLBCLR_CMD_READSYNC_Val << PDEC_CTRLBCLR_CMD_Pos) /* (PDEC_CTRLBCLR) Force a read synchronization of COUNT Position  */
#define PDEC_CTRLBCLR_CMD_START               (PDEC_CTRLBCLR_CMD_START_Val << PDEC_CTRLBCLR_CMD_Pos) /* (PDEC_CTRLBCLR) Start QDEC/HALL Position  */
#define PDEC_CTRLBCLR_CMD_STOP                (PDEC_CTRLBCLR_CMD_STOP_Val << PDEC_CTRLBCLR_CMD_Pos) /* (PDEC_CTRLBCLR) Stop QDEC/HALL Position  */
#define PDEC_CTRLBCLR_Msk                     _UINT8_(0xE2)                                        /* (PDEC_CTRLBCLR) Register Mask  */


/* -------- PDEC_CTRLBSET : (PDEC Offset: 0x05) (R/W 8) Control B Set -------- */
#define PDEC_CTRLBSET_RESETVALUE              _UINT8_(0x00)                                        /*  (PDEC_CTRLBSET) Control B Set  Reset Value */

#define PDEC_CTRLBSET_LUPD_Pos                _UINT8_(1)                                           /* (PDEC_CTRLBSET) Lock Update Position */
#define PDEC_CTRLBSET_LUPD_Msk                (_UINT8_(0x1) << PDEC_CTRLBSET_LUPD_Pos)             /* (PDEC_CTRLBSET) Lock Update Mask */
#define PDEC_CTRLBSET_LUPD(value)             (PDEC_CTRLBSET_LUPD_Msk & (_UINT8_(value) << PDEC_CTRLBSET_LUPD_Pos)) /* Assigment of value for LUPD in the PDEC_CTRLBSET register */
#define PDEC_CTRLBSET_CMD_Pos                 _UINT8_(5)                                           /* (PDEC_CTRLBSET) Command Position */
#define PDEC_CTRLBSET_CMD_Msk                 (_UINT8_(0x7) << PDEC_CTRLBSET_CMD_Pos)              /* (PDEC_CTRLBSET) Command Mask */
#define PDEC_CTRLBSET_CMD(value)              (PDEC_CTRLBSET_CMD_Msk & (_UINT8_(value) << PDEC_CTRLBSET_CMD_Pos)) /* Assigment of value for CMD in the PDEC_CTRLBSET register */
#define   PDEC_CTRLBSET_CMD_NONE_Val          _UINT8_(0x0)                                         /* (PDEC_CTRLBSET) No action  */
#define   PDEC_CTRLBSET_CMD_RETRIGGER_Val     _UINT8_(0x1)                                         /* (PDEC_CTRLBSET) Force a counter restart or retrigger  */
#define   PDEC_CTRLBSET_CMD_UPDATE_Val        _UINT8_(0x2)                                         /* (PDEC_CTRLBSET) Force update of double buffered registers  */
#define   PDEC_CTRLBSET_CMD_READSYNC_Val      _UINT8_(0x3)                                         /* (PDEC_CTRLBSET) Force a read synchronization of COUNT  */
#define   PDEC_CTRLBSET_CMD_START_Val         _UINT8_(0x4)                                         /* (PDEC_CTRLBSET) Start QDEC/HALL  */
#define   PDEC_CTRLBSET_CMD_STOP_Val          _UINT8_(0x5)                                         /* (PDEC_CTRLBSET) Stop QDEC/HALL  */
#define PDEC_CTRLBSET_CMD_NONE                (PDEC_CTRLBSET_CMD_NONE_Val << PDEC_CTRLBSET_CMD_Pos) /* (PDEC_CTRLBSET) No action Position  */
#define PDEC_CTRLBSET_CMD_RETRIGGER           (PDEC_CTRLBSET_CMD_RETRIGGER_Val << PDEC_CTRLBSET_CMD_Pos) /* (PDEC_CTRLBSET) Force a counter restart or retrigger Position  */
#define PDEC_CTRLBSET_CMD_UPDATE              (PDEC_CTRLBSET_CMD_UPDATE_Val << PDEC_CTRLBSET_CMD_Pos) /* (PDEC_CTRLBSET) Force update of double buffered registers Position  */
#define PDEC_CTRLBSET_CMD_READSYNC            (PDEC_CTRLBSET_CMD_READSYNC_Val << PDEC_CTRLBSET_CMD_Pos) /* (PDEC_CTRLBSET) Force a read synchronization of COUNT Position  */
#define PDEC_CTRLBSET_CMD_START               (PDEC_CTRLBSET_CMD_START_Val << PDEC_CTRLBSET_CMD_Pos) /* (PDEC_CTRLBSET) Start QDEC/HALL Position  */
#define PDEC_CTRLBSET_CMD_STOP                (PDEC_CTRLBSET_CMD_STOP_Val << PDEC_CTRLBSET_CMD_Pos) /* (PDEC_CTRLBSET) Stop QDEC/HALL Position  */
#define PDEC_CTRLBSET_Msk                     _UINT8_(0xE2)                                        /* (PDEC_CTRLBSET) Register Mask  */


/* -------- PDEC_EVCTRL : (PDEC Offset: 0x06) (R/W 16) Event Control -------- */
#define PDEC_EVCTRL_RESETVALUE                _UINT16_(0x00)                                       /*  (PDEC_EVCTRL) Event Control  Reset Value */

#define PDEC_EVCTRL_EVACT_Pos                 _UINT16_(0)                                          /* (PDEC_EVCTRL) Event Action Position */
#define PDEC_EVCTRL_EVACT_Msk                 (_UINT16_(0x3) << PDEC_EVCTRL_EVACT_Pos)             /* (PDEC_EVCTRL) Event Action Mask */
#define PDEC_EVCTRL_EVACT(value)              (PDEC_EVCTRL_EVACT_Msk & (_UINT16_(value) << PDEC_EVCTRL_EVACT_Pos)) /* Assigment of value for EVACT in the PDEC_EVCTRL register */
#define   PDEC_EVCTRL_EVACT_OFF_Val           _UINT16_(0x0)                                        /* (PDEC_EVCTRL) Event action disabled  */
#define   PDEC_EVCTRL_EVACT_RETRIGGER_Val     _UINT16_(0x1)                                        /* (PDEC_EVCTRL) Start, restart or retrigger on event  */
#define   PDEC_EVCTRL_EVACT_COUNT_Val         _UINT16_(0x2)                                        /* (PDEC_EVCTRL) Count on event  */
#define PDEC_EVCTRL_EVACT_OFF                 (PDEC_EVCTRL_EVACT_OFF_Val << PDEC_EVCTRL_EVACT_Pos) /* (PDEC_EVCTRL) Event action disabled Position  */
#define PDEC_EVCTRL_EVACT_RETRIGGER           (PDEC_EVCTRL_EVACT_RETRIGGER_Val << PDEC_EVCTRL_EVACT_Pos) /* (PDEC_EVCTRL) Start, restart or retrigger on event Position  */
#define PDEC_EVCTRL_EVACT_COUNT               (PDEC_EVCTRL_EVACT_COUNT_Val << PDEC_EVCTRL_EVACT_Pos) /* (PDEC_EVCTRL) Count on event Position  */
#define PDEC_EVCTRL_EVINV_Pos                 _UINT16_(2)                                          /* (PDEC_EVCTRL) Inverted Event Input Enable Position */
#define PDEC_EVCTRL_EVINV_Msk                 (_UINT16_(0x7) << PDEC_EVCTRL_EVINV_Pos)             /* (PDEC_EVCTRL) Inverted Event Input Enable Mask */
#define PDEC_EVCTRL_EVINV(value)              (PDEC_EVCTRL_EVINV_Msk & (_UINT16_(value) << PDEC_EVCTRL_EVINV_Pos)) /* Assigment of value for EVINV in the PDEC_EVCTRL register */
#define PDEC_EVCTRL_EVEI_Pos                  _UINT16_(5)                                          /* (PDEC_EVCTRL) Event Input Enable Position */
#define PDEC_EVCTRL_EVEI_Msk                  (_UINT16_(0x7) << PDEC_EVCTRL_EVEI_Pos)              /* (PDEC_EVCTRL) Event Input Enable Mask */
#define PDEC_EVCTRL_EVEI(value)               (PDEC_EVCTRL_EVEI_Msk & (_UINT16_(value) << PDEC_EVCTRL_EVEI_Pos)) /* Assigment of value for EVEI in the PDEC_EVCTRL register */
#define PDEC_EVCTRL_OVFEO_Pos                 _UINT16_(8)                                          /* (PDEC_EVCTRL) Overflow/Underflow Output Event Enable Position */
#define PDEC_EVCTRL_OVFEO_Msk                 (_UINT16_(0x1) << PDEC_EVCTRL_OVFEO_Pos)             /* (PDEC_EVCTRL) Overflow/Underflow Output Event Enable Mask */
#define PDEC_EVCTRL_OVFEO(value)              (PDEC_EVCTRL_OVFEO_Msk & (_UINT16_(value) << PDEC_EVCTRL_OVFEO_Pos)) /* Assigment of value for OVFEO in the PDEC_EVCTRL register */
#define PDEC_EVCTRL_ERREO_Pos                 _UINT16_(9)                                          /* (PDEC_EVCTRL) Error  Output Event Enable Position */
#define PDEC_EVCTRL_ERREO_Msk                 (_UINT16_(0x1) << PDEC_EVCTRL_ERREO_Pos)             /* (PDEC_EVCTRL) Error  Output Event Enable Mask */
#define PDEC_EVCTRL_ERREO(value)              (PDEC_EVCTRL_ERREO_Msk & (_UINT16_(value) << PDEC_EVCTRL_ERREO_Pos)) /* Assigment of value for ERREO in the PDEC_EVCTRL register */
#define PDEC_EVCTRL_DIREO_Pos                 _UINT16_(10)                                         /* (PDEC_EVCTRL) Direction Output Event Enable Position */
#define PDEC_EVCTRL_DIREO_Msk                 (_UINT16_(0x1) << PDEC_EVCTRL_DIREO_Pos)             /* (PDEC_EVCTRL) Direction Output Event Enable Mask */
#define PDEC_EVCTRL_DIREO(value)              (PDEC_EVCTRL_DIREO_Msk & (_UINT16_(value) << PDEC_EVCTRL_DIREO_Pos)) /* Assigment of value for DIREO in the PDEC_EVCTRL register */
#define PDEC_EVCTRL_VLCEO_Pos                 _UINT16_(11)                                         /* (PDEC_EVCTRL) Velocity Output Event Enable Position */
#define PDEC_EVCTRL_VLCEO_Msk                 (_UINT16_(0x1) << PDEC_EVCTRL_VLCEO_Pos)             /* (PDEC_EVCTRL) Velocity Output Event Enable Mask */
#define PDEC_EVCTRL_VLCEO(value)              (PDEC_EVCTRL_VLCEO_Msk & (_UINT16_(value) << PDEC_EVCTRL_VLCEO_Pos)) /* Assigment of value for VLCEO in the PDEC_EVCTRL register */
#define PDEC_EVCTRL_MCEO0_Pos                 _UINT16_(12)                                         /* (PDEC_EVCTRL) Match Channel 0 Event Output Enable Position */
#define PDEC_EVCTRL_MCEO0_Msk                 (_UINT16_(0x1) << PDEC_EVCTRL_MCEO0_Pos)             /* (PDEC_EVCTRL) Match Channel 0 Event Output Enable Mask */
#define PDEC_EVCTRL_MCEO0(value)              (PDEC_EVCTRL_MCEO0_Msk & (_UINT16_(value) << PDEC_EVCTRL_MCEO0_Pos)) /* Assigment of value for MCEO0 in the PDEC_EVCTRL register */
#define PDEC_EVCTRL_MCEO1_Pos                 _UINT16_(13)                                         /* (PDEC_EVCTRL) Match Channel 1 Event Output Enable Position */
#define PDEC_EVCTRL_MCEO1_Msk                 (_UINT16_(0x1) << PDEC_EVCTRL_MCEO1_Pos)             /* (PDEC_EVCTRL) Match Channel 1 Event Output Enable Mask */
#define PDEC_EVCTRL_MCEO1(value)              (PDEC_EVCTRL_MCEO1_Msk & (_UINT16_(value) << PDEC_EVCTRL_MCEO1_Pos)) /* Assigment of value for MCEO1 in the PDEC_EVCTRL register */
#define PDEC_EVCTRL_Msk                       _UINT16_(0x3FFF)                                     /* (PDEC_EVCTRL) Register Mask  */

#define PDEC_EVCTRL_MCEO_Pos                  _UINT16_(12)                                         /* (PDEC_EVCTRL Position) Match Channel x Event Output Enable */
#define PDEC_EVCTRL_MCEO_Msk                  (_UINT16_(0x3) << PDEC_EVCTRL_MCEO_Pos)              /* (PDEC_EVCTRL Mask) MCEO */
#define PDEC_EVCTRL_MCEO(value)               (PDEC_EVCTRL_MCEO_Msk & (_UINT16_(value) << PDEC_EVCTRL_MCEO_Pos)) 

/* -------- PDEC_INTENCLR : (PDEC Offset: 0x08) (R/W 8) Interrupt Enable Clear -------- */
#define PDEC_INTENCLR_RESETVALUE              _UINT8_(0x00)                                        /*  (PDEC_INTENCLR) Interrupt Enable Clear  Reset Value */

#define PDEC_INTENCLR_OVF_Pos                 _UINT8_(0)                                           /* (PDEC_INTENCLR) Overflow/Underflow Interrupt Disable Position */
#define PDEC_INTENCLR_OVF_Msk                 (_UINT8_(0x1) << PDEC_INTENCLR_OVF_Pos)              /* (PDEC_INTENCLR) Overflow/Underflow Interrupt Disable Mask */
#define PDEC_INTENCLR_OVF(value)              (PDEC_INTENCLR_OVF_Msk & (_UINT8_(value) << PDEC_INTENCLR_OVF_Pos)) /* Assigment of value for OVF in the PDEC_INTENCLR register */
#define PDEC_INTENCLR_ERR_Pos                 _UINT8_(1)                                           /* (PDEC_INTENCLR) Error Interrupt Disable Position */
#define PDEC_INTENCLR_ERR_Msk                 (_UINT8_(0x1) << PDEC_INTENCLR_ERR_Pos)              /* (PDEC_INTENCLR) Error Interrupt Disable Mask */
#define PDEC_INTENCLR_ERR(value)              (PDEC_INTENCLR_ERR_Msk & (_UINT8_(value) << PDEC_INTENCLR_ERR_Pos)) /* Assigment of value for ERR in the PDEC_INTENCLR register */
#define PDEC_INTENCLR_DIR_Pos                 _UINT8_(2)                                           /* (PDEC_INTENCLR) Direction Interrupt Disable Position */
#define PDEC_INTENCLR_DIR_Msk                 (_UINT8_(0x1) << PDEC_INTENCLR_DIR_Pos)              /* (PDEC_INTENCLR) Direction Interrupt Disable Mask */
#define PDEC_INTENCLR_DIR(value)              (PDEC_INTENCLR_DIR_Msk & (_UINT8_(value) << PDEC_INTENCLR_DIR_Pos)) /* Assigment of value for DIR in the PDEC_INTENCLR register */
#define PDEC_INTENCLR_VLC_Pos                 _UINT8_(3)                                           /* (PDEC_INTENCLR) Velocity Interrupt Disable Position */
#define PDEC_INTENCLR_VLC_Msk                 (_UINT8_(0x1) << PDEC_INTENCLR_VLC_Pos)              /* (PDEC_INTENCLR) Velocity Interrupt Disable Mask */
#define PDEC_INTENCLR_VLC(value)              (PDEC_INTENCLR_VLC_Msk & (_UINT8_(value) << PDEC_INTENCLR_VLC_Pos)) /* Assigment of value for VLC in the PDEC_INTENCLR register */
#define PDEC_INTENCLR_MC0_Pos                 _UINT8_(4)                                           /* (PDEC_INTENCLR) Channel 0 Compare Match Disable Position */
#define PDEC_INTENCLR_MC0_Msk                 (_UINT8_(0x1) << PDEC_INTENCLR_MC0_Pos)              /* (PDEC_INTENCLR) Channel 0 Compare Match Disable Mask */
#define PDEC_INTENCLR_MC0(value)              (PDEC_INTENCLR_MC0_Msk & (_UINT8_(value) << PDEC_INTENCLR_MC0_Pos)) /* Assigment of value for MC0 in the PDEC_INTENCLR register */
#define PDEC_INTENCLR_MC1_Pos                 _UINT8_(5)                                           /* (PDEC_INTENCLR) Channel 1 Compare Match Disable Position */
#define PDEC_INTENCLR_MC1_Msk                 (_UINT8_(0x1) << PDEC_INTENCLR_MC1_Pos)              /* (PDEC_INTENCLR) Channel 1 Compare Match Disable Mask */
#define PDEC_INTENCLR_MC1(value)              (PDEC_INTENCLR_MC1_Msk & (_UINT8_(value) << PDEC_INTENCLR_MC1_Pos)) /* Assigment of value for MC1 in the PDEC_INTENCLR register */
#define PDEC_INTENCLR_Msk                     _UINT8_(0x3F)                                        /* (PDEC_INTENCLR) Register Mask  */

#define PDEC_INTENCLR_MC_Pos                  _UINT8_(4)                                           /* (PDEC_INTENCLR Position) Channel x Compare Match Disable */
#define PDEC_INTENCLR_MC_Msk                  (_UINT8_(0x3) << PDEC_INTENCLR_MC_Pos)               /* (PDEC_INTENCLR Mask) MC */
#define PDEC_INTENCLR_MC(value)               (PDEC_INTENCLR_MC_Msk & (_UINT8_(value) << PDEC_INTENCLR_MC_Pos)) 

/* -------- PDEC_INTENSET : (PDEC Offset: 0x09) (R/W 8) Interrupt Enable Set -------- */
#define PDEC_INTENSET_RESETVALUE              _UINT8_(0x00)                                        /*  (PDEC_INTENSET) Interrupt Enable Set  Reset Value */

#define PDEC_INTENSET_OVF_Pos                 _UINT8_(0)                                           /* (PDEC_INTENSET) Overflow/Underflow Interrupt Enable Position */
#define PDEC_INTENSET_OVF_Msk                 (_UINT8_(0x1) << PDEC_INTENSET_OVF_Pos)              /* (PDEC_INTENSET) Overflow/Underflow Interrupt Enable Mask */
#define PDEC_INTENSET_OVF(value)              (PDEC_INTENSET_OVF_Msk & (_UINT8_(value) << PDEC_INTENSET_OVF_Pos)) /* Assigment of value for OVF in the PDEC_INTENSET register */
#define PDEC_INTENSET_ERR_Pos                 _UINT8_(1)                                           /* (PDEC_INTENSET) Error Interrupt Enable Position */
#define PDEC_INTENSET_ERR_Msk                 (_UINT8_(0x1) << PDEC_INTENSET_ERR_Pos)              /* (PDEC_INTENSET) Error Interrupt Enable Mask */
#define PDEC_INTENSET_ERR(value)              (PDEC_INTENSET_ERR_Msk & (_UINT8_(value) << PDEC_INTENSET_ERR_Pos)) /* Assigment of value for ERR in the PDEC_INTENSET register */
#define PDEC_INTENSET_DIR_Pos                 _UINT8_(2)                                           /* (PDEC_INTENSET) Direction Interrupt Enable Position */
#define PDEC_INTENSET_DIR_Msk                 (_UINT8_(0x1) << PDEC_INTENSET_DIR_Pos)              /* (PDEC_INTENSET) Direction Interrupt Enable Mask */
#define PDEC_INTENSET_DIR(value)              (PDEC_INTENSET_DIR_Msk & (_UINT8_(value) << PDEC_INTENSET_DIR_Pos)) /* Assigment of value for DIR in the PDEC_INTENSET register */
#define PDEC_INTENSET_VLC_Pos                 _UINT8_(3)                                           /* (PDEC_INTENSET) Velocity Interrupt Enable Position */
#define PDEC_INTENSET_VLC_Msk                 (_UINT8_(0x1) << PDEC_INTENSET_VLC_Pos)              /* (PDEC_INTENSET) Velocity Interrupt Enable Mask */
#define PDEC_INTENSET_VLC(value)              (PDEC_INTENSET_VLC_Msk & (_UINT8_(value) << PDEC_INTENSET_VLC_Pos)) /* Assigment of value for VLC in the PDEC_INTENSET register */
#define PDEC_INTENSET_MC0_Pos                 _UINT8_(4)                                           /* (PDEC_INTENSET) Channel 0 Compare Match Enable Position */
#define PDEC_INTENSET_MC0_Msk                 (_UINT8_(0x1) << PDEC_INTENSET_MC0_Pos)              /* (PDEC_INTENSET) Channel 0 Compare Match Enable Mask */
#define PDEC_INTENSET_MC0(value)              (PDEC_INTENSET_MC0_Msk & (_UINT8_(value) << PDEC_INTENSET_MC0_Pos)) /* Assigment of value for MC0 in the PDEC_INTENSET register */
#define PDEC_INTENSET_MC1_Pos                 _UINT8_(5)                                           /* (PDEC_INTENSET) Channel 1 Compare Match Enable Position */
#define PDEC_INTENSET_MC1_Msk                 (_UINT8_(0x1) << PDEC_INTENSET_MC1_Pos)              /* (PDEC_INTENSET) Channel 1 Compare Match Enable Mask */
#define PDEC_INTENSET_MC1(value)              (PDEC_INTENSET_MC1_Msk & (_UINT8_(value) << PDEC_INTENSET_MC1_Pos)) /* Assigment of value for MC1 in the PDEC_INTENSET register */
#define PDEC_INTENSET_Msk                     _UINT8_(0x3F)                                        /* (PDEC_INTENSET) Register Mask  */

#define PDEC_INTENSET_MC_Pos                  _UINT8_(4)                                           /* (PDEC_INTENSET Position) Channel x Compare Match Enable */
#define PDEC_INTENSET_MC_Msk                  (_UINT8_(0x3) << PDEC_INTENSET_MC_Pos)               /* (PDEC_INTENSET Mask) MC */
#define PDEC_INTENSET_MC(value)               (PDEC_INTENSET_MC_Msk & (_UINT8_(value) << PDEC_INTENSET_MC_Pos)) 

/* -------- PDEC_INTFLAG : (PDEC Offset: 0x0A) (R/W 8) Interrupt Flag Status and Clear -------- */
#define PDEC_INTFLAG_RESETVALUE               _UINT8_(0x00)                                        /*  (PDEC_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define PDEC_INTFLAG_OVF_Pos                  _UINT8_(0)                                           /* (PDEC_INTFLAG) Overflow/Underflow Position */
#define PDEC_INTFLAG_OVF_Msk                  (_UINT8_(0x1) << PDEC_INTFLAG_OVF_Pos)               /* (PDEC_INTFLAG) Overflow/Underflow Mask */
#define PDEC_INTFLAG_OVF(value)               (PDEC_INTFLAG_OVF_Msk & (_UINT8_(value) << PDEC_INTFLAG_OVF_Pos)) /* Assigment of value for OVF in the PDEC_INTFLAG register */
#define PDEC_INTFLAG_ERR_Pos                  _UINT8_(1)                                           /* (PDEC_INTFLAG) Error Position */
#define PDEC_INTFLAG_ERR_Msk                  (_UINT8_(0x1) << PDEC_INTFLAG_ERR_Pos)               /* (PDEC_INTFLAG) Error Mask */
#define PDEC_INTFLAG_ERR(value)               (PDEC_INTFLAG_ERR_Msk & (_UINT8_(value) << PDEC_INTFLAG_ERR_Pos)) /* Assigment of value for ERR in the PDEC_INTFLAG register */
#define PDEC_INTFLAG_DIR_Pos                  _UINT8_(2)                                           /* (PDEC_INTFLAG) Direction Change Position */
#define PDEC_INTFLAG_DIR_Msk                  (_UINT8_(0x1) << PDEC_INTFLAG_DIR_Pos)               /* (PDEC_INTFLAG) Direction Change Mask */
#define PDEC_INTFLAG_DIR(value)               (PDEC_INTFLAG_DIR_Msk & (_UINT8_(value) << PDEC_INTFLAG_DIR_Pos)) /* Assigment of value for DIR in the PDEC_INTFLAG register */
#define PDEC_INTFLAG_VLC_Pos                  _UINT8_(3)                                           /* (PDEC_INTFLAG) Velocity Position */
#define PDEC_INTFLAG_VLC_Msk                  (_UINT8_(0x1) << PDEC_INTFLAG_VLC_Pos)               /* (PDEC_INTFLAG) Velocity Mask */
#define PDEC_INTFLAG_VLC(value)               (PDEC_INTFLAG_VLC_Msk & (_UINT8_(value) << PDEC_INTFLAG_VLC_Pos)) /* Assigment of value for VLC in the PDEC_INTFLAG register */
#define PDEC_INTFLAG_MC0_Pos                  _UINT8_(4)                                           /* (PDEC_INTFLAG) Channel 0 Compare Match Position */
#define PDEC_INTFLAG_MC0_Msk                  (_UINT8_(0x1) << PDEC_INTFLAG_MC0_Pos)               /* (PDEC_INTFLAG) Channel 0 Compare Match Mask */
#define PDEC_INTFLAG_MC0(value)               (PDEC_INTFLAG_MC0_Msk & (_UINT8_(value) << PDEC_INTFLAG_MC0_Pos)) /* Assigment of value for MC0 in the PDEC_INTFLAG register */
#define PDEC_INTFLAG_MC1_Pos                  _UINT8_(5)                                           /* (PDEC_INTFLAG) Channel 1 Compare Match Position */
#define PDEC_INTFLAG_MC1_Msk                  (_UINT8_(0x1) << PDEC_INTFLAG_MC1_Pos)               /* (PDEC_INTFLAG) Channel 1 Compare Match Mask */
#define PDEC_INTFLAG_MC1(value)               (PDEC_INTFLAG_MC1_Msk & (_UINT8_(value) << PDEC_INTFLAG_MC1_Pos)) /* Assigment of value for MC1 in the PDEC_INTFLAG register */
#define PDEC_INTFLAG_Msk                      _UINT8_(0x3F)                                        /* (PDEC_INTFLAG) Register Mask  */

#define PDEC_INTFLAG_MC_Pos                   _UINT8_(4)                                           /* (PDEC_INTFLAG Position) Channel x Compare Match */
#define PDEC_INTFLAG_MC_Msk                   (_UINT8_(0x3) << PDEC_INTFLAG_MC_Pos)                /* (PDEC_INTFLAG Mask) MC */
#define PDEC_INTFLAG_MC(value)                (PDEC_INTFLAG_MC_Msk & (_UINT8_(value) << PDEC_INTFLAG_MC_Pos)) 

/* -------- PDEC_STATUS : (PDEC Offset: 0x0C) (R/W 16) Status -------- */
#define PDEC_STATUS_RESETVALUE                _UINT16_(0x40)                                       /*  (PDEC_STATUS) Status  Reset Value */

#define PDEC_STATUS_QERR_Pos                  _UINT16_(0)                                          /* (PDEC_STATUS) Quadrature Error Flag Position */
#define PDEC_STATUS_QERR_Msk                  (_UINT16_(0x1) << PDEC_STATUS_QERR_Pos)              /* (PDEC_STATUS) Quadrature Error Flag Mask */
#define PDEC_STATUS_QERR(value)               (PDEC_STATUS_QERR_Msk & (_UINT16_(value) << PDEC_STATUS_QERR_Pos)) /* Assigment of value for QERR in the PDEC_STATUS register */
#define PDEC_STATUS_IDXERR_Pos                _UINT16_(1)                                          /* (PDEC_STATUS) Index Error Flag Position */
#define PDEC_STATUS_IDXERR_Msk                (_UINT16_(0x1) << PDEC_STATUS_IDXERR_Pos)            /* (PDEC_STATUS) Index Error Flag Mask */
#define PDEC_STATUS_IDXERR(value)             (PDEC_STATUS_IDXERR_Msk & (_UINT16_(value) << PDEC_STATUS_IDXERR_Pos)) /* Assigment of value for IDXERR in the PDEC_STATUS register */
#define PDEC_STATUS_MPERR_Pos                 _UINT16_(2)                                          /* (PDEC_STATUS) Missing Pulse Error flag Position */
#define PDEC_STATUS_MPERR_Msk                 (_UINT16_(0x1) << PDEC_STATUS_MPERR_Pos)             /* (PDEC_STATUS) Missing Pulse Error flag Mask */
#define PDEC_STATUS_MPERR(value)              (PDEC_STATUS_MPERR_Msk & (_UINT16_(value) << PDEC_STATUS_MPERR_Pos)) /* Assigment of value for MPERR in the PDEC_STATUS register */
#define PDEC_STATUS_WINERR_Pos                _UINT16_(4)                                          /* (PDEC_STATUS) Window Error Flag Position */
#define PDEC_STATUS_WINERR_Msk                (_UINT16_(0x1) << PDEC_STATUS_WINERR_Pos)            /* (PDEC_STATUS) Window Error Flag Mask */
#define PDEC_STATUS_WINERR(value)             (PDEC_STATUS_WINERR_Msk & (_UINT16_(value) << PDEC_STATUS_WINERR_Pos)) /* Assigment of value for WINERR in the PDEC_STATUS register */
#define PDEC_STATUS_HERR_Pos                  _UINT16_(5)                                          /* (PDEC_STATUS) Hall Error Flag Position */
#define PDEC_STATUS_HERR_Msk                  (_UINT16_(0x1) << PDEC_STATUS_HERR_Pos)              /* (PDEC_STATUS) Hall Error Flag Mask */
#define PDEC_STATUS_HERR(value)               (PDEC_STATUS_HERR_Msk & (_UINT16_(value) << PDEC_STATUS_HERR_Pos)) /* Assigment of value for HERR in the PDEC_STATUS register */
#define PDEC_STATUS_STOP_Pos                  _UINT16_(6)                                          /* (PDEC_STATUS) Stop Position */
#define PDEC_STATUS_STOP_Msk                  (_UINT16_(0x1) << PDEC_STATUS_STOP_Pos)              /* (PDEC_STATUS) Stop Mask */
#define PDEC_STATUS_STOP(value)               (PDEC_STATUS_STOP_Msk & (_UINT16_(value) << PDEC_STATUS_STOP_Pos)) /* Assigment of value for STOP in the PDEC_STATUS register */
#define PDEC_STATUS_DIR_Pos                   _UINT16_(7)                                          /* (PDEC_STATUS) Direction Status Flag Position */
#define PDEC_STATUS_DIR_Msk                   (_UINT16_(0x1) << PDEC_STATUS_DIR_Pos)               /* (PDEC_STATUS) Direction Status Flag Mask */
#define PDEC_STATUS_DIR(value)                (PDEC_STATUS_DIR_Msk & (_UINT16_(value) << PDEC_STATUS_DIR_Pos)) /* Assigment of value for DIR in the PDEC_STATUS register */
#define PDEC_STATUS_PRESCBUFV_Pos             _UINT16_(8)                                          /* (PDEC_STATUS) Prescaler Buffer Valid Position */
#define PDEC_STATUS_PRESCBUFV_Msk             (_UINT16_(0x1) << PDEC_STATUS_PRESCBUFV_Pos)         /* (PDEC_STATUS) Prescaler Buffer Valid Mask */
#define PDEC_STATUS_PRESCBUFV(value)          (PDEC_STATUS_PRESCBUFV_Msk & (_UINT16_(value) << PDEC_STATUS_PRESCBUFV_Pos)) /* Assigment of value for PRESCBUFV in the PDEC_STATUS register */
#define PDEC_STATUS_FILTERBUFV_Pos            _UINT16_(9)                                          /* (PDEC_STATUS) Filter Buffer Valid Position */
#define PDEC_STATUS_FILTERBUFV_Msk            (_UINT16_(0x1) << PDEC_STATUS_FILTERBUFV_Pos)        /* (PDEC_STATUS) Filter Buffer Valid Mask */
#define PDEC_STATUS_FILTERBUFV(value)         (PDEC_STATUS_FILTERBUFV_Msk & (_UINT16_(value) << PDEC_STATUS_FILTERBUFV_Pos)) /* Assigment of value for FILTERBUFV in the PDEC_STATUS register */
#define PDEC_STATUS_CCBUFV0_Pos               _UINT16_(12)                                         /* (PDEC_STATUS) Compare Channel 0 Buffer Valid Position */
#define PDEC_STATUS_CCBUFV0_Msk               (_UINT16_(0x1) << PDEC_STATUS_CCBUFV0_Pos)           /* (PDEC_STATUS) Compare Channel 0 Buffer Valid Mask */
#define PDEC_STATUS_CCBUFV0(value)            (PDEC_STATUS_CCBUFV0_Msk & (_UINT16_(value) << PDEC_STATUS_CCBUFV0_Pos)) /* Assigment of value for CCBUFV0 in the PDEC_STATUS register */
#define PDEC_STATUS_CCBUFV1_Pos               _UINT16_(13)                                         /* (PDEC_STATUS) Compare Channel 1 Buffer Valid Position */
#define PDEC_STATUS_CCBUFV1_Msk               (_UINT16_(0x1) << PDEC_STATUS_CCBUFV1_Pos)           /* (PDEC_STATUS) Compare Channel 1 Buffer Valid Mask */
#define PDEC_STATUS_CCBUFV1(value)            (PDEC_STATUS_CCBUFV1_Msk & (_UINT16_(value) << PDEC_STATUS_CCBUFV1_Pos)) /* Assigment of value for CCBUFV1 in the PDEC_STATUS register */
#define PDEC_STATUS_Msk                       _UINT16_(0x33F7)                                     /* (PDEC_STATUS) Register Mask  */

#define PDEC_STATUS_CCBUFV_Pos                _UINT16_(12)                                         /* (PDEC_STATUS Position) Compare Channel x Buffer Valid */
#define PDEC_STATUS_CCBUFV_Msk                (_UINT16_(0x3) << PDEC_STATUS_CCBUFV_Pos)            /* (PDEC_STATUS Mask) CCBUFV */
#define PDEC_STATUS_CCBUFV(value)             (PDEC_STATUS_CCBUFV_Msk & (_UINT16_(value) << PDEC_STATUS_CCBUFV_Pos)) 

/* -------- PDEC_DBGCTRL : (PDEC Offset: 0x0F) (R/W 8) Debug Control -------- */
#define PDEC_DBGCTRL_RESETVALUE               _UINT8_(0x00)                                        /*  (PDEC_DBGCTRL) Debug Control  Reset Value */

#define PDEC_DBGCTRL_DBGRUN_Pos               _UINT8_(0)                                           /* (PDEC_DBGCTRL) Debug Run Mode Position */
#define PDEC_DBGCTRL_DBGRUN_Msk               (_UINT8_(0x1) << PDEC_DBGCTRL_DBGRUN_Pos)            /* (PDEC_DBGCTRL) Debug Run Mode Mask */
#define PDEC_DBGCTRL_DBGRUN(value)            (PDEC_DBGCTRL_DBGRUN_Msk & (_UINT8_(value) << PDEC_DBGCTRL_DBGRUN_Pos)) /* Assigment of value for DBGRUN in the PDEC_DBGCTRL register */
#define PDEC_DBGCTRL_Msk                      _UINT8_(0x01)                                        /* (PDEC_DBGCTRL) Register Mask  */


/* -------- PDEC_SYNCBUSY : (PDEC Offset: 0x10) ( R/ 32) Synchronization Status -------- */
#define PDEC_SYNCBUSY_RESETVALUE              _UINT32_(0x00)                                       /*  (PDEC_SYNCBUSY) Synchronization Status  Reset Value */

#define PDEC_SYNCBUSY_SWRST_Pos               _UINT32_(0)                                          /* (PDEC_SYNCBUSY) Software Reset Synchronization Busy Position */
#define PDEC_SYNCBUSY_SWRST_Msk               (_UINT32_(0x1) << PDEC_SYNCBUSY_SWRST_Pos)           /* (PDEC_SYNCBUSY) Software Reset Synchronization Busy Mask */
#define PDEC_SYNCBUSY_SWRST(value)            (PDEC_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << PDEC_SYNCBUSY_SWRST_Pos)) /* Assigment of value for SWRST in the PDEC_SYNCBUSY register */
#define PDEC_SYNCBUSY_ENABLE_Pos              _UINT32_(1)                                          /* (PDEC_SYNCBUSY) Enable Synchronization Busy Position */
#define PDEC_SYNCBUSY_ENABLE_Msk              (_UINT32_(0x1) << PDEC_SYNCBUSY_ENABLE_Pos)          /* (PDEC_SYNCBUSY) Enable Synchronization Busy Mask */
#define PDEC_SYNCBUSY_ENABLE(value)           (PDEC_SYNCBUSY_ENABLE_Msk & (_UINT32_(value) << PDEC_SYNCBUSY_ENABLE_Pos)) /* Assigment of value for ENABLE in the PDEC_SYNCBUSY register */
#define PDEC_SYNCBUSY_CTRLB_Pos               _UINT32_(2)                                          /* (PDEC_SYNCBUSY) Control B Synchronization Busy Position */
#define PDEC_SYNCBUSY_CTRLB_Msk               (_UINT32_(0x1) << PDEC_SYNCBUSY_CTRLB_Pos)           /* (PDEC_SYNCBUSY) Control B Synchronization Busy Mask */
#define PDEC_SYNCBUSY_CTRLB(value)            (PDEC_SYNCBUSY_CTRLB_Msk & (_UINT32_(value) << PDEC_SYNCBUSY_CTRLB_Pos)) /* Assigment of value for CTRLB in the PDEC_SYNCBUSY register */
#define PDEC_SYNCBUSY_STATUS_Pos              _UINT32_(3)                                          /* (PDEC_SYNCBUSY) Status Synchronization Busy Position */
#define PDEC_SYNCBUSY_STATUS_Msk              (_UINT32_(0x1) << PDEC_SYNCBUSY_STATUS_Pos)          /* (PDEC_SYNCBUSY) Status Synchronization Busy Mask */
#define PDEC_SYNCBUSY_STATUS(value)           (PDEC_SYNCBUSY_STATUS_Msk & (_UINT32_(value) << PDEC_SYNCBUSY_STATUS_Pos)) /* Assigment of value for STATUS in the PDEC_SYNCBUSY register */
#define PDEC_SYNCBUSY_PRESC_Pos               _UINT32_(4)                                          /* (PDEC_SYNCBUSY) Prescaler Synchronization Busy Position */
#define PDEC_SYNCBUSY_PRESC_Msk               (_UINT32_(0x1) << PDEC_SYNCBUSY_PRESC_Pos)           /* (PDEC_SYNCBUSY) Prescaler Synchronization Busy Mask */
#define PDEC_SYNCBUSY_PRESC(value)            (PDEC_SYNCBUSY_PRESC_Msk & (_UINT32_(value) << PDEC_SYNCBUSY_PRESC_Pos)) /* Assigment of value for PRESC in the PDEC_SYNCBUSY register */
#define PDEC_SYNCBUSY_FILTER_Pos              _UINT32_(5)                                          /* (PDEC_SYNCBUSY) Filter Synchronization Busy Position */
#define PDEC_SYNCBUSY_FILTER_Msk              (_UINT32_(0x1) << PDEC_SYNCBUSY_FILTER_Pos)          /* (PDEC_SYNCBUSY) Filter Synchronization Busy Mask */
#define PDEC_SYNCBUSY_FILTER(value)           (PDEC_SYNCBUSY_FILTER_Msk & (_UINT32_(value) << PDEC_SYNCBUSY_FILTER_Pos)) /* Assigment of value for FILTER in the PDEC_SYNCBUSY register */
#define PDEC_SYNCBUSY_COUNT_Pos               _UINT32_(6)                                          /* (PDEC_SYNCBUSY) Count Synchronization Busy Position */
#define PDEC_SYNCBUSY_COUNT_Msk               (_UINT32_(0x1) << PDEC_SYNCBUSY_COUNT_Pos)           /* (PDEC_SYNCBUSY) Count Synchronization Busy Mask */
#define PDEC_SYNCBUSY_COUNT(value)            (PDEC_SYNCBUSY_COUNT_Msk & (_UINT32_(value) << PDEC_SYNCBUSY_COUNT_Pos)) /* Assigment of value for COUNT in the PDEC_SYNCBUSY register */
#define PDEC_SYNCBUSY_CC0_Pos                 _UINT32_(7)                                          /* (PDEC_SYNCBUSY) Compare Channel 0 Synchronization Busy Position */
#define PDEC_SYNCBUSY_CC0_Msk                 (_UINT32_(0x1) << PDEC_SYNCBUSY_CC0_Pos)             /* (PDEC_SYNCBUSY) Compare Channel 0 Synchronization Busy Mask */
#define PDEC_SYNCBUSY_CC0(value)              (PDEC_SYNCBUSY_CC0_Msk & (_UINT32_(value) << PDEC_SYNCBUSY_CC0_Pos)) /* Assigment of value for CC0 in the PDEC_SYNCBUSY register */
#define PDEC_SYNCBUSY_CC1_Pos                 _UINT32_(8)                                          /* (PDEC_SYNCBUSY) Compare Channel 1 Synchronization Busy Position */
#define PDEC_SYNCBUSY_CC1_Msk                 (_UINT32_(0x1) << PDEC_SYNCBUSY_CC1_Pos)             /* (PDEC_SYNCBUSY) Compare Channel 1 Synchronization Busy Mask */
#define PDEC_SYNCBUSY_CC1(value)              (PDEC_SYNCBUSY_CC1_Msk & (_UINT32_(value) << PDEC_SYNCBUSY_CC1_Pos)) /* Assigment of value for CC1 in the PDEC_SYNCBUSY register */
#define PDEC_SYNCBUSY_Msk                     _UINT32_(0x000001FF)                                 /* (PDEC_SYNCBUSY) Register Mask  */

#define PDEC_SYNCBUSY_CC_Pos                  _UINT32_(7)                                          /* (PDEC_SYNCBUSY Position) Compare Channel x Synchronization Busy */
#define PDEC_SYNCBUSY_CC_Msk                  (_UINT32_(0x3) << PDEC_SYNCBUSY_CC_Pos)              /* (PDEC_SYNCBUSY Mask) CC */
#define PDEC_SYNCBUSY_CC(value)               (PDEC_SYNCBUSY_CC_Msk & (_UINT32_(value) << PDEC_SYNCBUSY_CC_Pos)) 

/* -------- PDEC_PRESC : (PDEC Offset: 0x14) (R/W 8) Prescaler Value -------- */
#define PDEC_PRESC_RESETVALUE                 _UINT8_(0x00)                                        /*  (PDEC_PRESC) Prescaler Value  Reset Value */

#define PDEC_PRESC_PRESC_Pos                  _UINT8_(0)                                           /* (PDEC_PRESC) Prescaler Value Position */
#define PDEC_PRESC_PRESC_Msk                  (_UINT8_(0xF) << PDEC_PRESC_PRESC_Pos)               /* (PDEC_PRESC) Prescaler Value Mask */
#define PDEC_PRESC_PRESC(value)               (PDEC_PRESC_PRESC_Msk & (_UINT8_(value) << PDEC_PRESC_PRESC_Pos)) /* Assigment of value for PRESC in the PDEC_PRESC register */
#define   PDEC_PRESC_PRESC_DIV1_Val           _UINT8_(0x0)                                         /* (PDEC_PRESC) No division  */
#define   PDEC_PRESC_PRESC_DIV2_Val           _UINT8_(0x1)                                         /* (PDEC_PRESC) Divide by 2  */
#define   PDEC_PRESC_PRESC_DIV4_Val           _UINT8_(0x2)                                         /* (PDEC_PRESC) Divide by 4  */
#define   PDEC_PRESC_PRESC_DIV8_Val           _UINT8_(0x3)                                         /* (PDEC_PRESC) Divide by 8  */
#define   PDEC_PRESC_PRESC_DIV16_Val          _UINT8_(0x4)                                         /* (PDEC_PRESC) Divide by 16  */
#define   PDEC_PRESC_PRESC_DIV32_Val          _UINT8_(0x5)                                         /* (PDEC_PRESC) Divide by 32  */
#define   PDEC_PRESC_PRESC_DIV64_Val          _UINT8_(0x6)                                         /* (PDEC_PRESC) Divide by 64  */
#define   PDEC_PRESC_PRESC_DIV128_Val         _UINT8_(0x7)                                         /* (PDEC_PRESC) Divide by 128  */
#define   PDEC_PRESC_PRESC_DIV256_Val         _UINT8_(0x8)                                         /* (PDEC_PRESC) Divide by 256  */
#define   PDEC_PRESC_PRESC_DIV512_Val         _UINT8_(0x9)                                         /* (PDEC_PRESC) Divide by 512  */
#define   PDEC_PRESC_PRESC_DIV1024_Val        _UINT8_(0xA)                                         /* (PDEC_PRESC) Divide by 1024  */
#define PDEC_PRESC_PRESC_DIV1                 (PDEC_PRESC_PRESC_DIV1_Val << PDEC_PRESC_PRESC_Pos)  /* (PDEC_PRESC) No division Position  */
#define PDEC_PRESC_PRESC_DIV2                 (PDEC_PRESC_PRESC_DIV2_Val << PDEC_PRESC_PRESC_Pos)  /* (PDEC_PRESC) Divide by 2 Position  */
#define PDEC_PRESC_PRESC_DIV4                 (PDEC_PRESC_PRESC_DIV4_Val << PDEC_PRESC_PRESC_Pos)  /* (PDEC_PRESC) Divide by 4 Position  */
#define PDEC_PRESC_PRESC_DIV8                 (PDEC_PRESC_PRESC_DIV8_Val << PDEC_PRESC_PRESC_Pos)  /* (PDEC_PRESC) Divide by 8 Position  */
#define PDEC_PRESC_PRESC_DIV16                (PDEC_PRESC_PRESC_DIV16_Val << PDEC_PRESC_PRESC_Pos) /* (PDEC_PRESC) Divide by 16 Position  */
#define PDEC_PRESC_PRESC_DIV32                (PDEC_PRESC_PRESC_DIV32_Val << PDEC_PRESC_PRESC_Pos) /* (PDEC_PRESC) Divide by 32 Position  */
#define PDEC_PRESC_PRESC_DIV64                (PDEC_PRESC_PRESC_DIV64_Val << PDEC_PRESC_PRESC_Pos) /* (PDEC_PRESC) Divide by 64 Position  */
#define PDEC_PRESC_PRESC_DIV128               (PDEC_PRESC_PRESC_DIV128_Val << PDEC_PRESC_PRESC_Pos) /* (PDEC_PRESC) Divide by 128 Position  */
#define PDEC_PRESC_PRESC_DIV256               (PDEC_PRESC_PRESC_DIV256_Val << PDEC_PRESC_PRESC_Pos) /* (PDEC_PRESC) Divide by 256 Position  */
#define PDEC_PRESC_PRESC_DIV512               (PDEC_PRESC_PRESC_DIV512_Val << PDEC_PRESC_PRESC_Pos) /* (PDEC_PRESC) Divide by 512 Position  */
#define PDEC_PRESC_PRESC_DIV1024              (PDEC_PRESC_PRESC_DIV1024_Val << PDEC_PRESC_PRESC_Pos) /* (PDEC_PRESC) Divide by 1024 Position  */
#define PDEC_PRESC_Msk                        _UINT8_(0x0F)                                        /* (PDEC_PRESC) Register Mask  */


/* -------- PDEC_FILTER : (PDEC Offset: 0x15) (R/W 8) Filter Value -------- */
#define PDEC_FILTER_RESETVALUE                _UINT8_(0x00)                                        /*  (PDEC_FILTER) Filter Value  Reset Value */

#define PDEC_FILTER_FILTER_Pos                _UINT8_(0)                                           /* (PDEC_FILTER) Filter Value Position */
#define PDEC_FILTER_FILTER_Msk                (_UINT8_(0xFF) << PDEC_FILTER_FILTER_Pos)            /* (PDEC_FILTER) Filter Value Mask */
#define PDEC_FILTER_FILTER(value)             (PDEC_FILTER_FILTER_Msk & (_UINT8_(value) << PDEC_FILTER_FILTER_Pos)) /* Assigment of value for FILTER in the PDEC_FILTER register */
#define PDEC_FILTER_Msk                       _UINT8_(0xFF)                                        /* (PDEC_FILTER) Register Mask  */


/* -------- PDEC_PRESCBUF : (PDEC Offset: 0x18) (R/W 8) Prescaler Buffer Value -------- */
#define PDEC_PRESCBUF_RESETVALUE              _UINT8_(0x00)                                        /*  (PDEC_PRESCBUF) Prescaler Buffer Value  Reset Value */

#define PDEC_PRESCBUF_PRESCBUF_Pos            _UINT8_(0)                                           /* (PDEC_PRESCBUF) Prescaler Buffer Value Position */
#define PDEC_PRESCBUF_PRESCBUF_Msk            (_UINT8_(0xF) << PDEC_PRESCBUF_PRESCBUF_Pos)         /* (PDEC_PRESCBUF) Prescaler Buffer Value Mask */
#define PDEC_PRESCBUF_PRESCBUF(value)         (PDEC_PRESCBUF_PRESCBUF_Msk & (_UINT8_(value) << PDEC_PRESCBUF_PRESCBUF_Pos)) /* Assigment of value for PRESCBUF in the PDEC_PRESCBUF register */
#define   PDEC_PRESCBUF_PRESCBUF_DIV1_Val     _UINT8_(0x0)                                         /* (PDEC_PRESCBUF) No division  */
#define   PDEC_PRESCBUF_PRESCBUF_DIV2_Val     _UINT8_(0x1)                                         /* (PDEC_PRESCBUF) Divide by 2  */
#define   PDEC_PRESCBUF_PRESCBUF_DIV4_Val     _UINT8_(0x2)                                         /* (PDEC_PRESCBUF) Divide by 4  */
#define   PDEC_PRESCBUF_PRESCBUF_DIV8_Val     _UINT8_(0x3)                                         /* (PDEC_PRESCBUF) Divide by 8  */
#define   PDEC_PRESCBUF_PRESCBUF_DIV16_Val    _UINT8_(0x4)                                         /* (PDEC_PRESCBUF) Divide by 16  */
#define   PDEC_PRESCBUF_PRESCBUF_DIV32_Val    _UINT8_(0x5)                                         /* (PDEC_PRESCBUF) Divide by 32  */
#define   PDEC_PRESCBUF_PRESCBUF_DIV64_Val    _UINT8_(0x6)                                         /* (PDEC_PRESCBUF) Divide by 64  */
#define   PDEC_PRESCBUF_PRESCBUF_DIV128_Val   _UINT8_(0x7)                                         /* (PDEC_PRESCBUF) Divide by 128  */
#define   PDEC_PRESCBUF_PRESCBUF_DIV256_Val   _UINT8_(0x8)                                         /* (PDEC_PRESCBUF) Divide by 256  */
#define   PDEC_PRESCBUF_PRESCBUF_DIV512_Val   _UINT8_(0x9)                                         /* (PDEC_PRESCBUF) Divide by 512  */
#define   PDEC_PRESCBUF_PRESCBUF_DIV1024_Val  _UINT8_(0xA)                                         /* (PDEC_PRESCBUF) Divide by 1024  */
#define PDEC_PRESCBUF_PRESCBUF_DIV1           (PDEC_PRESCBUF_PRESCBUF_DIV1_Val << PDEC_PRESCBUF_PRESCBUF_Pos) /* (PDEC_PRESCBUF) No division Position  */
#define PDEC_PRESCBUF_PRESCBUF_DIV2           (PDEC_PRESCBUF_PRESCBUF_DIV2_Val << PDEC_PRESCBUF_PRESCBUF_Pos) /* (PDEC_PRESCBUF) Divide by 2 Position  */
#define PDEC_PRESCBUF_PRESCBUF_DIV4           (PDEC_PRESCBUF_PRESCBUF_DIV4_Val << PDEC_PRESCBUF_PRESCBUF_Pos) /* (PDEC_PRESCBUF) Divide by 4 Position  */
#define PDEC_PRESCBUF_PRESCBUF_DIV8           (PDEC_PRESCBUF_PRESCBUF_DIV8_Val << PDEC_PRESCBUF_PRESCBUF_Pos) /* (PDEC_PRESCBUF) Divide by 8 Position  */
#define PDEC_PRESCBUF_PRESCBUF_DIV16          (PDEC_PRESCBUF_PRESCBUF_DIV16_Val << PDEC_PRESCBUF_PRESCBUF_Pos) /* (PDEC_PRESCBUF) Divide by 16 Position  */
#define PDEC_PRESCBUF_PRESCBUF_DIV32          (PDEC_PRESCBUF_PRESCBUF_DIV32_Val << PDEC_PRESCBUF_PRESCBUF_Pos) /* (PDEC_PRESCBUF) Divide by 32 Position  */
#define PDEC_PRESCBUF_PRESCBUF_DIV64          (PDEC_PRESCBUF_PRESCBUF_DIV64_Val << PDEC_PRESCBUF_PRESCBUF_Pos) /* (PDEC_PRESCBUF) Divide by 64 Position  */
#define PDEC_PRESCBUF_PRESCBUF_DIV128         (PDEC_PRESCBUF_PRESCBUF_DIV128_Val << PDEC_PRESCBUF_PRESCBUF_Pos) /* (PDEC_PRESCBUF) Divide by 128 Position  */
#define PDEC_PRESCBUF_PRESCBUF_DIV256         (PDEC_PRESCBUF_PRESCBUF_DIV256_Val << PDEC_PRESCBUF_PRESCBUF_Pos) /* (PDEC_PRESCBUF) Divide by 256 Position  */
#define PDEC_PRESCBUF_PRESCBUF_DIV512         (PDEC_PRESCBUF_PRESCBUF_DIV512_Val << PDEC_PRESCBUF_PRESCBUF_Pos) /* (PDEC_PRESCBUF) Divide by 512 Position  */
#define PDEC_PRESCBUF_PRESCBUF_DIV1024        (PDEC_PRESCBUF_PRESCBUF_DIV1024_Val << PDEC_PRESCBUF_PRESCBUF_Pos) /* (PDEC_PRESCBUF) Divide by 1024 Position  */
#define PDEC_PRESCBUF_Msk                     _UINT8_(0x0F)                                        /* (PDEC_PRESCBUF) Register Mask  */


/* -------- PDEC_FILTERBUF : (PDEC Offset: 0x19) (R/W 8) Filter Buffer Value -------- */
#define PDEC_FILTERBUF_RESETVALUE             _UINT8_(0x00)                                        /*  (PDEC_FILTERBUF) Filter Buffer Value  Reset Value */

#define PDEC_FILTERBUF_FILTERBUF_Pos          _UINT8_(0)                                           /* (PDEC_FILTERBUF) Filter Buffer Value Position */
#define PDEC_FILTERBUF_FILTERBUF_Msk          (_UINT8_(0xFF) << PDEC_FILTERBUF_FILTERBUF_Pos)      /* (PDEC_FILTERBUF) Filter Buffer Value Mask */
#define PDEC_FILTERBUF_FILTERBUF(value)       (PDEC_FILTERBUF_FILTERBUF_Msk & (_UINT8_(value) << PDEC_FILTERBUF_FILTERBUF_Pos)) /* Assigment of value for FILTERBUF in the PDEC_FILTERBUF register */
#define PDEC_FILTERBUF_Msk                    _UINT8_(0xFF)                                        /* (PDEC_FILTERBUF) Register Mask  */


/* -------- PDEC_COUNT : (PDEC Offset: 0x1C) (R/W 32) Counter Value -------- */
#define PDEC_COUNT_RESETVALUE                 _UINT32_(0x00)                                       /*  (PDEC_COUNT) Counter Value  Reset Value */

#define PDEC_COUNT_COUNT_Pos                  _UINT32_(0)                                          /* (PDEC_COUNT) Counter Value Position */
#define PDEC_COUNT_COUNT_Msk                  (_UINT32_(0xFFFF) << PDEC_COUNT_COUNT_Pos)           /* (PDEC_COUNT) Counter Value Mask */
#define PDEC_COUNT_COUNT(value)               (PDEC_COUNT_COUNT_Msk & (_UINT32_(value) << PDEC_COUNT_COUNT_Pos)) /* Assigment of value for COUNT in the PDEC_COUNT register */
#define PDEC_COUNT_Msk                        _UINT32_(0x0000FFFF)                                 /* (PDEC_COUNT) Register Mask  */


/* -------- PDEC_CC : (PDEC Offset: 0x20) (R/W 32) Channel n Compare Value -------- */
#define PDEC_CC_RESETVALUE                    _UINT32_(0x00)                                       /*  (PDEC_CC) Channel n Compare Value  Reset Value */

#define PDEC_CC_CC_Pos                        _UINT32_(0)                                          /* (PDEC_CC) Channel Compare Value Position */
#define PDEC_CC_CC_Msk                        (_UINT32_(0xFFFF) << PDEC_CC_CC_Pos)                 /* (PDEC_CC) Channel Compare Value Mask */
#define PDEC_CC_CC(value)                     (PDEC_CC_CC_Msk & (_UINT32_(value) << PDEC_CC_CC_Pos)) /* Assigment of value for CC in the PDEC_CC register */
#define PDEC_CC_Msk                           _UINT32_(0x0000FFFF)                                 /* (PDEC_CC) Register Mask  */


/* -------- PDEC_CCBUF : (PDEC Offset: 0x30) (R/W 32) Channel Compare Buffer Value -------- */
#define PDEC_CCBUF_RESETVALUE                 _UINT32_(0x00)                                       /*  (PDEC_CCBUF) Channel Compare Buffer Value  Reset Value */

#define PDEC_CCBUF_CCBUF_Pos                  _UINT32_(0)                                          /* (PDEC_CCBUF) Channel Compare Buffer Value Position */
#define PDEC_CCBUF_CCBUF_Msk                  (_UINT32_(0xFFFF) << PDEC_CCBUF_CCBUF_Pos)           /* (PDEC_CCBUF) Channel Compare Buffer Value Mask */
#define PDEC_CCBUF_CCBUF(value)               (PDEC_CCBUF_CCBUF_Msk & (_UINT32_(value) << PDEC_CCBUF_CCBUF_Pos)) /* Assigment of value for CCBUF in the PDEC_CCBUF register */
#define PDEC_CCBUF_Msk                        _UINT32_(0x0000FFFF)                                 /* (PDEC_CCBUF) Register Mask  */


/** \brief PDEC register offsets definitions */
#define PDEC_CTRLA_REG_OFST            _UINT32_(0x00)      /* (PDEC_CTRLA) Control A Offset */
#define PDEC_CTRLBCLR_REG_OFST         _UINT32_(0x04)      /* (PDEC_CTRLBCLR) Control B Clear Offset */
#define PDEC_CTRLBSET_REG_OFST         _UINT32_(0x05)      /* (PDEC_CTRLBSET) Control B Set Offset */
#define PDEC_EVCTRL_REG_OFST           _UINT32_(0x06)      /* (PDEC_EVCTRL) Event Control Offset */
#define PDEC_INTENCLR_REG_OFST         _UINT32_(0x08)      /* (PDEC_INTENCLR) Interrupt Enable Clear Offset */
#define PDEC_INTENSET_REG_OFST         _UINT32_(0x09)      /* (PDEC_INTENSET) Interrupt Enable Set Offset */
#define PDEC_INTFLAG_REG_OFST          _UINT32_(0x0A)      /* (PDEC_INTFLAG) Interrupt Flag Status and Clear Offset */
#define PDEC_STATUS_REG_OFST           _UINT32_(0x0C)      /* (PDEC_STATUS) Status Offset */
#define PDEC_DBGCTRL_REG_OFST          _UINT32_(0x0F)      /* (PDEC_DBGCTRL) Debug Control Offset */
#define PDEC_SYNCBUSY_REG_OFST         _UINT32_(0x10)      /* (PDEC_SYNCBUSY) Synchronization Status Offset */
#define PDEC_PRESC_REG_OFST            _UINT32_(0x14)      /* (PDEC_PRESC) Prescaler Value Offset */
#define PDEC_FILTER_REG_OFST           _UINT32_(0x15)      /* (PDEC_FILTER) Filter Value Offset */
#define PDEC_PRESCBUF_REG_OFST         _UINT32_(0x18)      /* (PDEC_PRESCBUF) Prescaler Buffer Value Offset */
#define PDEC_FILTERBUF_REG_OFST        _UINT32_(0x19)      /* (PDEC_FILTERBUF) Filter Buffer Value Offset */
#define PDEC_COUNT_REG_OFST            _UINT32_(0x1C)      /* (PDEC_COUNT) Counter Value Offset */
#define PDEC_CC_REG_OFST               _UINT32_(0x20)      /* (PDEC_CC) Channel n Compare Value Offset */
#define PDEC_CC0_REG_OFST              _UINT32_(0x20)      /* (PDEC_CC0) Channel n Compare Value Offset */
#define PDEC_CC1_REG_OFST              _UINT32_(0x24)      /* (PDEC_CC1) Channel n Compare Value Offset */
#define PDEC_CCBUF_REG_OFST            _UINT32_(0x30)      /* (PDEC_CCBUF) Channel Compare Buffer Value Offset */
#define PDEC_CCBUF0_REG_OFST           _UINT32_(0x30)      /* (PDEC_CCBUF0) Channel Compare Buffer Value Offset */
#define PDEC_CCBUF1_REG_OFST           _UINT32_(0x34)      /* (PDEC_CCBUF1) Channel Compare Buffer Value Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PDEC register API structure */
typedef struct
{  /* Quadrature Decodeur */
  __IO  uint32_t                       PDEC_CTRLA;         /**< Offset: 0x00 (R/W  32) Control A */
  __IO  uint8_t                        PDEC_CTRLBCLR;      /**< Offset: 0x04 (R/W  8) Control B Clear */
  __IO  uint8_t                        PDEC_CTRLBSET;      /**< Offset: 0x05 (R/W  8) Control B Set */
  __IO  uint16_t                       PDEC_EVCTRL;        /**< Offset: 0x06 (R/W  16) Event Control */
  __IO  uint8_t                        PDEC_INTENCLR;      /**< Offset: 0x08 (R/W  8) Interrupt Enable Clear */
  __IO  uint8_t                        PDEC_INTENSET;      /**< Offset: 0x09 (R/W  8) Interrupt Enable Set */
  __IO  uint8_t                        PDEC_INTFLAG;       /**< Offset: 0x0A (R/W  8) Interrupt Flag Status and Clear */
  __I   uint8_t                        Reserved1[0x01];
  __IO  uint16_t                       PDEC_STATUS;        /**< Offset: 0x0C (R/W  16) Status */
  __I   uint8_t                        Reserved2[0x01];
  __IO  uint8_t                        PDEC_DBGCTRL;       /**< Offset: 0x0F (R/W  8) Debug Control */
  __I   uint32_t                       PDEC_SYNCBUSY;      /**< Offset: 0x10 (R/   32) Synchronization Status */
  __IO  uint8_t                        PDEC_PRESC;         /**< Offset: 0x14 (R/W  8) Prescaler Value */
  __IO  uint8_t                        PDEC_FILTER;        /**< Offset: 0x15 (R/W  8) Filter Value */
  __I   uint8_t                        Reserved3[0x02];
  __IO  uint8_t                        PDEC_PRESCBUF;      /**< Offset: 0x18 (R/W  8) Prescaler Buffer Value */
  __IO  uint8_t                        PDEC_FILTERBUF;     /**< Offset: 0x19 (R/W  8) Filter Buffer Value */
  __I   uint8_t                        Reserved4[0x02];
  __IO  uint32_t                       PDEC_COUNT;         /**< Offset: 0x1C (R/W  32) Counter Value */
  __IO  uint32_t                       PDEC_CC[2];         /**< Offset: 0x20 (R/W  32) Channel n Compare Value */
  __I   uint8_t                        Reserved5[0x08];
  __IO  uint32_t                       PDEC_CCBUF[2];      /**< Offset: 0x30 (R/W  32) Channel Compare Buffer Value */
} pdec_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAME54_PDEC_COMPONENT_H_ */
