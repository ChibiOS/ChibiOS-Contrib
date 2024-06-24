/*
 * Component description for FUSES
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
#ifndef _SAME54_FUSES_COMPONENT_H_
#define _SAME54_FUSES_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR FUSES                                        */
/* ************************************************************************** */

/* -------- FUSES_TEMP_LOG_WORD_0 : (FUSES Offset: 0x00) ( R/ 32) TEMP_LOG Page Word 0 -------- */
#define FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_INT_Pos _UINT32_(0)                                          /* (FUSES_TEMP_LOG_WORD_0) Integer part of room temperature in oC Position */
#define FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_INT_Msk (_UINT32_(0xFF) << FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_INT_Pos) /* (FUSES_TEMP_LOG_WORD_0) Integer part of room temperature in oC Mask */
#define FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_INT(value) (FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_INT_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_INT_Pos)) /* Assigment of value for ROOM_TEMP_VAL_INT in the FUSES_TEMP_LOG_WORD_0 register */
#define FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_DEC_Pos _UINT32_(8)                                          /* (FUSES_TEMP_LOG_WORD_0) Decimal part of room temperature Position */
#define FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_DEC_Msk (_UINT32_(0xF) << FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_DEC_Pos) /* (FUSES_TEMP_LOG_WORD_0) Decimal part of room temperature Mask */
#define FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_DEC(value) (FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_DEC_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_0_ROOM_TEMP_VAL_DEC_Pos)) /* Assigment of value for ROOM_TEMP_VAL_DEC in the FUSES_TEMP_LOG_WORD_0 register */
#define FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_INT_Pos _UINT32_(12)                                         /* (FUSES_TEMP_LOG_WORD_0) Integer part of hot temperature in oC Position */
#define FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_INT_Msk (_UINT32_(0xFF) << FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_INT_Pos) /* (FUSES_TEMP_LOG_WORD_0) Integer part of hot temperature in oC Mask */
#define FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_INT(value) (FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_INT_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_INT_Pos)) /* Assigment of value for HOT_TEMP_VAL_INT in the FUSES_TEMP_LOG_WORD_0 register */
#define FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_DEC_Pos _UINT32_(20)                                         /* (FUSES_TEMP_LOG_WORD_0) Decimal part of hot temperature Position */
#define FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_DEC_Msk (_UINT32_(0xF) << FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_DEC_Pos) /* (FUSES_TEMP_LOG_WORD_0) Decimal part of hot temperature Mask */
#define FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_DEC(value) (FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_DEC_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_0_HOT_TEMP_VAL_DEC_Pos)) /* Assigment of value for HOT_TEMP_VAL_DEC in the FUSES_TEMP_LOG_WORD_0 register */
#define FUSES_TEMP_LOG_WORD_0_ROOM_INT1V_VAL_Pos _UINT32_(24)                                         /* (FUSES_TEMP_LOG_WORD_0) 2's complement of the internal 1V reference drift at room temperature (versus a 1.0 centered value) Position */
#define FUSES_TEMP_LOG_WORD_0_ROOM_INT1V_VAL_Msk (_UINT32_(0xFF) << FUSES_TEMP_LOG_WORD_0_ROOM_INT1V_VAL_Pos) /* (FUSES_TEMP_LOG_WORD_0) 2's complement of the internal 1V reference drift at room temperature (versus a 1.0 centered value) Mask */
#define FUSES_TEMP_LOG_WORD_0_ROOM_INT1V_VAL(value) (FUSES_TEMP_LOG_WORD_0_ROOM_INT1V_VAL_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_0_ROOM_INT1V_VAL_Pos)) /* Assigment of value for ROOM_INT1V_VAL in the FUSES_TEMP_LOG_WORD_0 register */
#define FUSES_TEMP_LOG_WORD_0_Msk             _UINT32_(0xFFFFFFFF)                                 /* (FUSES_TEMP_LOG_WORD_0) Register Mask  */


/* -------- FUSES_TEMP_LOG_WORD_1 : (FUSES Offset: 0x04) ( R/ 32) TEMP_LOG Page Word 1 -------- */
#define FUSES_TEMP_LOG_WORD_1_HOT_INT1V_VAL_Pos _UINT32_(0)                                          /* (FUSES_TEMP_LOG_WORD_1) 2's complement of the internal 1V reference drift at hot temperature (versus a 1.0 centered value) Position */
#define FUSES_TEMP_LOG_WORD_1_HOT_INT1V_VAL_Msk (_UINT32_(0xFF) << FUSES_TEMP_LOG_WORD_1_HOT_INT1V_VAL_Pos) /* (FUSES_TEMP_LOG_WORD_1) 2's complement of the internal 1V reference drift at hot temperature (versus a 1.0 centered value) Mask */
#define FUSES_TEMP_LOG_WORD_1_HOT_INT1V_VAL(value) (FUSES_TEMP_LOG_WORD_1_HOT_INT1V_VAL_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_1_HOT_INT1V_VAL_Pos)) /* Assigment of value for HOT_INT1V_VAL in the FUSES_TEMP_LOG_WORD_1 register */
#define FUSES_TEMP_LOG_WORD_1_ROOM_ADC_VAL_PTAT_Pos _UINT32_(8)                                          /* (FUSES_TEMP_LOG_WORD_1) 12-bit ADC conversion at room temperature PTAT Position */
#define FUSES_TEMP_LOG_WORD_1_ROOM_ADC_VAL_PTAT_Msk (_UINT32_(0xFFF) << FUSES_TEMP_LOG_WORD_1_ROOM_ADC_VAL_PTAT_Pos) /* (FUSES_TEMP_LOG_WORD_1) 12-bit ADC conversion at room temperature PTAT Mask */
#define FUSES_TEMP_LOG_WORD_1_ROOM_ADC_VAL_PTAT(value) (FUSES_TEMP_LOG_WORD_1_ROOM_ADC_VAL_PTAT_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_1_ROOM_ADC_VAL_PTAT_Pos)) /* Assigment of value for ROOM_ADC_VAL_PTAT in the FUSES_TEMP_LOG_WORD_1 register */
#define FUSES_TEMP_LOG_WORD_1_HOT_ADC_VAL_PTAT_Pos _UINT32_(20)                                         /* (FUSES_TEMP_LOG_WORD_1) 12-bit ADC conversion at hot temperature PTAT Position */
#define FUSES_TEMP_LOG_WORD_1_HOT_ADC_VAL_PTAT_Msk (_UINT32_(0xFFF) << FUSES_TEMP_LOG_WORD_1_HOT_ADC_VAL_PTAT_Pos) /* (FUSES_TEMP_LOG_WORD_1) 12-bit ADC conversion at hot temperature PTAT Mask */
#define FUSES_TEMP_LOG_WORD_1_HOT_ADC_VAL_PTAT(value) (FUSES_TEMP_LOG_WORD_1_HOT_ADC_VAL_PTAT_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_1_HOT_ADC_VAL_PTAT_Pos)) /* Assigment of value for HOT_ADC_VAL_PTAT in the FUSES_TEMP_LOG_WORD_1 register */
#define FUSES_TEMP_LOG_WORD_1_Msk             _UINT32_(0xFFFFFFFF)                                 /* (FUSES_TEMP_LOG_WORD_1) Register Mask  */


/* -------- FUSES_TEMP_LOG_WORD_2 : (FUSES Offset: 0x08) ( R/ 32) TEMP_LOG Page Word 2 -------- */
#define FUSES_TEMP_LOG_WORD_2_ROOM_ADC_VAL_CTAT_Pos _UINT32_(0)                                          /* (FUSES_TEMP_LOG_WORD_2) 12-bit ADC conversion at room temperature CTAT Position */
#define FUSES_TEMP_LOG_WORD_2_ROOM_ADC_VAL_CTAT_Msk (_UINT32_(0xFFF) << FUSES_TEMP_LOG_WORD_2_ROOM_ADC_VAL_CTAT_Pos) /* (FUSES_TEMP_LOG_WORD_2) 12-bit ADC conversion at room temperature CTAT Mask */
#define FUSES_TEMP_LOG_WORD_2_ROOM_ADC_VAL_CTAT(value) (FUSES_TEMP_LOG_WORD_2_ROOM_ADC_VAL_CTAT_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_2_ROOM_ADC_VAL_CTAT_Pos)) /* Assigment of value for ROOM_ADC_VAL_CTAT in the FUSES_TEMP_LOG_WORD_2 register */
#define FUSES_TEMP_LOG_WORD_2_HOT_ADC_VAL_CTAT_Pos _UINT32_(12)                                         /* (FUSES_TEMP_LOG_WORD_2) 12-bit ADC conversion at hot temperature CTAT Position */
#define FUSES_TEMP_LOG_WORD_2_HOT_ADC_VAL_CTAT_Msk (_UINT32_(0xFFF) << FUSES_TEMP_LOG_WORD_2_HOT_ADC_VAL_CTAT_Pos) /* (FUSES_TEMP_LOG_WORD_2) 12-bit ADC conversion at hot temperature CTAT Mask */
#define FUSES_TEMP_LOG_WORD_2_HOT_ADC_VAL_CTAT(value) (FUSES_TEMP_LOG_WORD_2_HOT_ADC_VAL_CTAT_Msk & (_UINT32_(value) << FUSES_TEMP_LOG_WORD_2_HOT_ADC_VAL_CTAT_Pos)) /* Assigment of value for HOT_ADC_VAL_CTAT in the FUSES_TEMP_LOG_WORD_2 register */
#define FUSES_TEMP_LOG_WORD_2_Msk             _UINT32_(0x00FFFFFF)                                 /* (FUSES_TEMP_LOG_WORD_2) Register Mask  */


/* -------- FUSES_SW0_WORD_0 : (FUSES Offset: 0x00) ( R/ 32) SW0 Page Word 0 -------- */
#define FUSES_SW0_WORD_0_AC_BIAS0_Pos         _UINT32_(0)                                          /* (FUSES_SW0_WORD_0) PAIR0 Bias Calibration Position */
#define FUSES_SW0_WORD_0_AC_BIAS0_Msk         (_UINT32_(0x3) << FUSES_SW0_WORD_0_AC_BIAS0_Pos)     /* (FUSES_SW0_WORD_0) PAIR0 Bias Calibration Mask */
#define FUSES_SW0_WORD_0_AC_BIAS0(value)      (FUSES_SW0_WORD_0_AC_BIAS0_Msk & (_UINT32_(value) << FUSES_SW0_WORD_0_AC_BIAS0_Pos)) /* Assigment of value for AC_BIAS0 in the FUSES_SW0_WORD_0 register */
#define FUSES_SW0_WORD_0_ADC0_BIASCOMP_Pos    _UINT32_(2)                                          /* (FUSES_SW0_WORD_0) ADC Comparator Scaling Position */
#define FUSES_SW0_WORD_0_ADC0_BIASCOMP_Msk    (_UINT32_(0x7) << FUSES_SW0_WORD_0_ADC0_BIASCOMP_Pos) /* (FUSES_SW0_WORD_0) ADC Comparator Scaling Mask */
#define FUSES_SW0_WORD_0_ADC0_BIASCOMP(value) (FUSES_SW0_WORD_0_ADC0_BIASCOMP_Msk & (_UINT32_(value) << FUSES_SW0_WORD_0_ADC0_BIASCOMP_Pos)) /* Assigment of value for ADC0_BIASCOMP in the FUSES_SW0_WORD_0 register */
#define FUSES_SW0_WORD_0_ADC0_BIASREFBUF_Pos  _UINT32_(5)                                          /* (FUSES_SW0_WORD_0) ADC Bias Reference Buffer Scaling Position */
#define FUSES_SW0_WORD_0_ADC0_BIASREFBUF_Msk  (_UINT32_(0x7) << FUSES_SW0_WORD_0_ADC0_BIASREFBUF_Pos) /* (FUSES_SW0_WORD_0) ADC Bias Reference Buffer Scaling Mask */
#define FUSES_SW0_WORD_0_ADC0_BIASREFBUF(value) (FUSES_SW0_WORD_0_ADC0_BIASREFBUF_Msk & (_UINT32_(value) << FUSES_SW0_WORD_0_ADC0_BIASREFBUF_Pos)) /* Assigment of value for ADC0_BIASREFBUF in the FUSES_SW0_WORD_0 register */
#define FUSES_SW0_WORD_0_ADC0_BIASR2R_Pos     _UINT32_(8)                                          /* (FUSES_SW0_WORD_0) ADC Bias R2R ampli scaling Position */
#define FUSES_SW0_WORD_0_ADC0_BIASR2R_Msk     (_UINT32_(0x7) << FUSES_SW0_WORD_0_ADC0_BIASR2R_Pos) /* (FUSES_SW0_WORD_0) ADC Bias R2R ampli scaling Mask */
#define FUSES_SW0_WORD_0_ADC0_BIASR2R(value)  (FUSES_SW0_WORD_0_ADC0_BIASR2R_Msk & (_UINT32_(value) << FUSES_SW0_WORD_0_ADC0_BIASR2R_Pos)) /* Assigment of value for ADC0_BIASR2R in the FUSES_SW0_WORD_0 register */
#define FUSES_SW0_WORD_0_ADC1_BIASCOMP_Pos    _UINT32_(16)                                         /* (FUSES_SW0_WORD_0) ADC Comparator Scaling Position */
#define FUSES_SW0_WORD_0_ADC1_BIASCOMP_Msk    (_UINT32_(0x7) << FUSES_SW0_WORD_0_ADC1_BIASCOMP_Pos) /* (FUSES_SW0_WORD_0) ADC Comparator Scaling Mask */
#define FUSES_SW0_WORD_0_ADC1_BIASCOMP(value) (FUSES_SW0_WORD_0_ADC1_BIASCOMP_Msk & (_UINT32_(value) << FUSES_SW0_WORD_0_ADC1_BIASCOMP_Pos)) /* Assigment of value for ADC1_BIASCOMP in the FUSES_SW0_WORD_0 register */
#define FUSES_SW0_WORD_0_ADC1_BIASREFBUF_Pos  _UINT32_(19)                                         /* (FUSES_SW0_WORD_0) ADC Bias Reference Buffer Scaling Position */
#define FUSES_SW0_WORD_0_ADC1_BIASREFBUF_Msk  (_UINT32_(0x7) << FUSES_SW0_WORD_0_ADC1_BIASREFBUF_Pos) /* (FUSES_SW0_WORD_0) ADC Bias Reference Buffer Scaling Mask */
#define FUSES_SW0_WORD_0_ADC1_BIASREFBUF(value) (FUSES_SW0_WORD_0_ADC1_BIASREFBUF_Msk & (_UINT32_(value) << FUSES_SW0_WORD_0_ADC1_BIASREFBUF_Pos)) /* Assigment of value for ADC1_BIASREFBUF in the FUSES_SW0_WORD_0 register */
#define FUSES_SW0_WORD_0_ADC1_BIASR2R_Pos     _UINT32_(22)                                         /* (FUSES_SW0_WORD_0) ADC Bias R2R ampli scaling Position */
#define FUSES_SW0_WORD_0_ADC1_BIASR2R_Msk     (_UINT32_(0x7) << FUSES_SW0_WORD_0_ADC1_BIASR2R_Pos) /* (FUSES_SW0_WORD_0) ADC Bias R2R ampli scaling Mask */
#define FUSES_SW0_WORD_0_ADC1_BIASR2R(value)  (FUSES_SW0_WORD_0_ADC1_BIASR2R_Msk & (_UINT32_(value) << FUSES_SW0_WORD_0_ADC1_BIASR2R_Pos)) /* Assigment of value for ADC1_BIASR2R in the FUSES_SW0_WORD_0 register */
#define FUSES_SW0_WORD_0_Msk                  _UINT32_(0x01FF07FF)                                 /* (FUSES_SW0_WORD_0) Register Mask  */


/* -------- FUSES_SW0_WORD_1 : (FUSES Offset: 0x04) ( R/ 32) SW0 Page Word 1 -------- */
#define FUSES_SW0_WORD_1_USB_TRANSN_Pos       _UINT32_(0)                                          /* (FUSES_SW0_WORD_1) USB pad Transn calibration Position */
#define FUSES_SW0_WORD_1_USB_TRANSN_Msk       (_UINT32_(0x1F) << FUSES_SW0_WORD_1_USB_TRANSN_Pos)  /* (FUSES_SW0_WORD_1) USB pad Transn calibration Mask */
#define FUSES_SW0_WORD_1_USB_TRANSN(value)    (FUSES_SW0_WORD_1_USB_TRANSN_Msk & (_UINT32_(value) << FUSES_SW0_WORD_1_USB_TRANSN_Pos)) /* Assigment of value for USB_TRANSN in the FUSES_SW0_WORD_1 register */
#define FUSES_SW0_WORD_1_USB_TRANSP_Pos       _UINT32_(5)                                          /* (FUSES_SW0_WORD_1) USB pad Transp calibration Position */
#define FUSES_SW0_WORD_1_USB_TRANSP_Msk       (_UINT32_(0x1F) << FUSES_SW0_WORD_1_USB_TRANSP_Pos)  /* (FUSES_SW0_WORD_1) USB pad Transp calibration Mask */
#define FUSES_SW0_WORD_1_USB_TRANSP(value)    (FUSES_SW0_WORD_1_USB_TRANSP_Msk & (_UINT32_(value) << FUSES_SW0_WORD_1_USB_TRANSP_Pos)) /* Assigment of value for USB_TRANSP in the FUSES_SW0_WORD_1 register */
#define FUSES_SW0_WORD_1_USB_TRIM_Pos         _UINT32_(10)                                         /* (FUSES_SW0_WORD_1) USB pad Trim calibration Position */
#define FUSES_SW0_WORD_1_USB_TRIM_Msk         (_UINT32_(0x7) << FUSES_SW0_WORD_1_USB_TRIM_Pos)     /* (FUSES_SW0_WORD_1) USB pad Trim calibration Mask */
#define FUSES_SW0_WORD_1_USB_TRIM(value)      (FUSES_SW0_WORD_1_USB_TRIM_Msk & (_UINT32_(value) << FUSES_SW0_WORD_1_USB_TRIM_Pos)) /* Assigment of value for USB_TRIM in the FUSES_SW0_WORD_1 register */
#define FUSES_SW0_WORD_1_Msk                  _UINT32_(0x00001FFF)                                 /* (FUSES_SW0_WORD_1) Register Mask  */


/* -------- FUSES_USER_WORD_0 : (FUSES Offset: 0x00) (R/W 32) USER Page Word 0 -------- */
#define FUSES_USER_WORD_0_BOD33_DIS_Pos       _UINT32_(0)                                          /* (FUSES_USER_WORD_0) BOD33 Disable Position */
#define FUSES_USER_WORD_0_BOD33_DIS_Msk       (_UINT32_(0x1) << FUSES_USER_WORD_0_BOD33_DIS_Pos)   /* (FUSES_USER_WORD_0) BOD33 Disable Mask */
#define FUSES_USER_WORD_0_BOD33_DIS(value)    (FUSES_USER_WORD_0_BOD33_DIS_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_BOD33_DIS_Pos)) /* Assigment of value for BOD33_DIS in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_BOD33USERLEVEL_Pos  _UINT32_(1)                                          /* (FUSES_USER_WORD_0) BOD33 User Level Position */
#define FUSES_USER_WORD_0_BOD33USERLEVEL_Msk  (_UINT32_(0xFF) << FUSES_USER_WORD_0_BOD33USERLEVEL_Pos) /* (FUSES_USER_WORD_0) BOD33 User Level Mask */
#define FUSES_USER_WORD_0_BOD33USERLEVEL(value) (FUSES_USER_WORD_0_BOD33USERLEVEL_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_BOD33USERLEVEL_Pos)) /* Assigment of value for BOD33USERLEVEL in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_BOD33_ACTION_Pos    _UINT32_(9)                                          /* (FUSES_USER_WORD_0) BOD33 Action Position */
#define FUSES_USER_WORD_0_BOD33_ACTION_Msk    (_UINT32_(0x3) << FUSES_USER_WORD_0_BOD33_ACTION_Pos) /* (FUSES_USER_WORD_0) BOD33 Action Mask */
#define FUSES_USER_WORD_0_BOD33_ACTION(value) (FUSES_USER_WORD_0_BOD33_ACTION_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_BOD33_ACTION_Pos)) /* Assigment of value for BOD33_ACTION in the FUSES_USER_WORD_0 register */
#define   FUSES_USER_WORD_0_BOD33_ACTION_NONE_Val _UINT32_(0x0)                                        /* (FUSES_USER_WORD_0) No action  */
#define   FUSES_USER_WORD_0_BOD33_ACTION_RESET_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_0) The BOD33 generates a reset  */
#define   FUSES_USER_WORD_0_BOD33_ACTION_INT_Val _UINT32_(0x2)                                        /* (FUSES_USER_WORD_0) The BOD33 generates an interrupt  */
#define   FUSES_USER_WORD_0_BOD33_ACTION_BKUP_Val _UINT32_(0x3)                                        /* (FUSES_USER_WORD_0) The BOD33 puts the device in backup sleep mode  */
#define FUSES_USER_WORD_0_BOD33_ACTION_NONE   (FUSES_USER_WORD_0_BOD33_ACTION_NONE_Val << FUSES_USER_WORD_0_BOD33_ACTION_Pos) /* (FUSES_USER_WORD_0) No action Position  */
#define FUSES_USER_WORD_0_BOD33_ACTION_RESET  (FUSES_USER_WORD_0_BOD33_ACTION_RESET_Val << FUSES_USER_WORD_0_BOD33_ACTION_Pos) /* (FUSES_USER_WORD_0) The BOD33 generates a reset Position  */
#define FUSES_USER_WORD_0_BOD33_ACTION_INT    (FUSES_USER_WORD_0_BOD33_ACTION_INT_Val << FUSES_USER_WORD_0_BOD33_ACTION_Pos) /* (FUSES_USER_WORD_0) The BOD33 generates an interrupt Position  */
#define FUSES_USER_WORD_0_BOD33_ACTION_BKUP   (FUSES_USER_WORD_0_BOD33_ACTION_BKUP_Val << FUSES_USER_WORD_0_BOD33_ACTION_Pos) /* (FUSES_USER_WORD_0) The BOD33 puts the device in backup sleep mode Position  */
#define FUSES_USER_WORD_0_BOD33_HYST_Pos      _UINT32_(11)                                         /* (FUSES_USER_WORD_0) BOD33 Hysteresis Position */
#define FUSES_USER_WORD_0_BOD33_HYST_Msk      (_UINT32_(0xF) << FUSES_USER_WORD_0_BOD33_HYST_Pos)  /* (FUSES_USER_WORD_0) BOD33 Hysteresis Mask */
#define FUSES_USER_WORD_0_BOD33_HYST(value)   (FUSES_USER_WORD_0_BOD33_HYST_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_BOD33_HYST_Pos)) /* Assigment of value for BOD33_HYST in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos _UINT32_(26)                                         /* (FUSES_USER_WORD_0) Bootloader Size Position */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Msk (_UINT32_(0xF) << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) Bootloader Size Mask */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT(value) (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos)) /* Assigment of value for NVMCTRL_BOOTPROT in the FUSES_USER_WORD_0 register */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_0_Val _UINT32_(0xF)                                        /* (FUSES_USER_WORD_0) 0 kbytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_8_Val _UINT32_(0xE)                                        /* (FUSES_USER_WORD_0) 8 kbytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_16_Val _UINT32_(0xD)                                        /* (FUSES_USER_WORD_0) 16 kbytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_24_Val _UINT32_(0xC)                                        /* (FUSES_USER_WORD_0) 24 kbytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_32_Val _UINT32_(0xB)                                        /* (FUSES_USER_WORD_0) 32 kbytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_40_Val _UINT32_(0xA)                                        /* (FUSES_USER_WORD_0) 40 kbytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_48_Val _UINT32_(0x9)                                        /* (FUSES_USER_WORD_0) 48 kbytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_56_Val _UINT32_(0x8)                                        /* (FUSES_USER_WORD_0) 56 kbytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_64_Val _UINT32_(0x7)                                        /* (FUSES_USER_WORD_0) 64 kbytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_72_Val _UINT32_(0x6)                                        /* (FUSES_USER_WORD_0) 72 kbytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_80_Val _UINT32_(0x5)                                        /* (FUSES_USER_WORD_0) 80 kbytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_88_Val _UINT32_(0x4)                                        /* (FUSES_USER_WORD_0) 88 kbytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_96_Val _UINT32_(0x3)                                        /* (FUSES_USER_WORD_0) 96 kbytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_104_Val _UINT32_(0x2)                                        /* (FUSES_USER_WORD_0) 104 kbytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_112_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_0) 112 kbytes  */
#define   FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_120_Val _UINT32_(0x0)                                        /* (FUSES_USER_WORD_0) 120 kbytes  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_0  (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_0_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 0 kbytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_8  (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_8_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 8 kbytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_16 (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_16_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 16 kbytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_24 (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_24_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 24 kbytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_32 (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_32_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 32 kbytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_40 (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_40_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 40 kbytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_48 (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_48_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 48 kbytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_56 (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_56_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 56 kbytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_64 (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_64_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 64 kbytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_72 (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_72_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 72 kbytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_80 (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_80_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 80 kbytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_88 (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_88_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 88 kbytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_96 (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_96_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 96 kbytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_104 (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_104_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 104 kbytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_112 (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_112_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 112 kbytes Position  */
#define FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_120 (FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_120_Val << FUSES_USER_WORD_0_NVMCTRL_BOOTPROT_Pos) /* (FUSES_USER_WORD_0) 120 kbytes Position  */
#define FUSES_USER_WORD_0_Msk                 _UINT32_(0x3C007FFF)                                 /* (FUSES_USER_WORD_0) Register Mask  */


/* -------- FUSES_USER_WORD_1 : (FUSES Offset: 0x04) (R/W 32) USER Page Word 1 -------- */
#define FUSES_USER_WORD_1_NVMCTRL_SEESBLK_Pos _UINT32_(0)                                          /* (FUSES_USER_WORD_1) Number Of Physical NVM Blocks Composing a SmartEEPROM Sector Position */
#define FUSES_USER_WORD_1_NVMCTRL_SEESBLK_Msk (_UINT32_(0xF) << FUSES_USER_WORD_1_NVMCTRL_SEESBLK_Pos) /* (FUSES_USER_WORD_1) Number Of Physical NVM Blocks Composing a SmartEEPROM Sector Mask */
#define FUSES_USER_WORD_1_NVMCTRL_SEESBLK(value) (FUSES_USER_WORD_1_NVMCTRL_SEESBLK_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_NVMCTRL_SEESBLK_Pos)) /* Assigment of value for NVMCTRL_SEESBLK in the FUSES_USER_WORD_1 register */
#define FUSES_USER_WORD_1_NVMCTRL_SEEPSZ_Pos  _UINT32_(4)                                          /* (FUSES_USER_WORD_1) Size Of SmartEEPROM Page Position */
#define FUSES_USER_WORD_1_NVMCTRL_SEEPSZ_Msk  (_UINT32_(0x7) << FUSES_USER_WORD_1_NVMCTRL_SEEPSZ_Pos) /* (FUSES_USER_WORD_1) Size Of SmartEEPROM Page Mask */
#define FUSES_USER_WORD_1_NVMCTRL_SEEPSZ(value) (FUSES_USER_WORD_1_NVMCTRL_SEEPSZ_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_NVMCTRL_SEEPSZ_Pos)) /* Assigment of value for NVMCTRL_SEEPSZ in the FUSES_USER_WORD_1 register */
#define FUSES_USER_WORD_1_RAMECC_ECCDIS_Pos   _UINT32_(7)                                          /* (FUSES_USER_WORD_1) RAM ECC Disable fuse Position */
#define FUSES_USER_WORD_1_RAMECC_ECCDIS_Msk   (_UINT32_(0x1) << FUSES_USER_WORD_1_RAMECC_ECCDIS_Pos) /* (FUSES_USER_WORD_1) RAM ECC Disable fuse Mask */
#define FUSES_USER_WORD_1_RAMECC_ECCDIS(value) (FUSES_USER_WORD_1_RAMECC_ECCDIS_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_RAMECC_ECCDIS_Pos)) /* Assigment of value for RAMECC_ECCDIS in the FUSES_USER_WORD_1 register */
#define FUSES_USER_WORD_1_WDT_ENABLE_Pos      _UINT32_(16)                                         /* (FUSES_USER_WORD_1) WDT Enable Position */
#define FUSES_USER_WORD_1_WDT_ENABLE_Msk      (_UINT32_(0x1) << FUSES_USER_WORD_1_WDT_ENABLE_Pos)  /* (FUSES_USER_WORD_1) WDT Enable Mask */
#define FUSES_USER_WORD_1_WDT_ENABLE(value)   (FUSES_USER_WORD_1_WDT_ENABLE_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_WDT_ENABLE_Pos)) /* Assigment of value for WDT_ENABLE in the FUSES_USER_WORD_1 register */
#define FUSES_USER_WORD_1_WDT_ALWAYSON_Pos    _UINT32_(17)                                         /* (FUSES_USER_WORD_1) WDT Always On Position */
#define FUSES_USER_WORD_1_WDT_ALWAYSON_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_1_WDT_ALWAYSON_Pos) /* (FUSES_USER_WORD_1) WDT Always On Mask */
#define FUSES_USER_WORD_1_WDT_ALWAYSON(value) (FUSES_USER_WORD_1_WDT_ALWAYSON_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_WDT_ALWAYSON_Pos)) /* Assigment of value for WDT_ALWAYSON in the FUSES_USER_WORD_1 register */
#define FUSES_USER_WORD_1_WDT_PER_Pos         _UINT32_(18)                                         /* (FUSES_USER_WORD_1) WDT Period Position */
#define FUSES_USER_WORD_1_WDT_PER_Msk         (_UINT32_(0xF) << FUSES_USER_WORD_1_WDT_PER_Pos)     /* (FUSES_USER_WORD_1) WDT Period Mask */
#define FUSES_USER_WORD_1_WDT_PER(value)      (FUSES_USER_WORD_1_WDT_PER_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_WDT_PER_Pos)) /* Assigment of value for WDT_PER in the FUSES_USER_WORD_1 register */
#define   FUSES_USER_WORD_1_WDT_PER_CYC8_Val  _UINT32_(0x0)                                        /* (FUSES_USER_WORD_1) 8 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_PER_CYC16_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_1) 16 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_PER_CYC32_Val _UINT32_(0x2)                                        /* (FUSES_USER_WORD_1) 32 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_PER_CYC64_Val _UINT32_(0x3)                                        /* (FUSES_USER_WORD_1) 64 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_PER_CYC128_Val _UINT32_(0x4)                                        /* (FUSES_USER_WORD_1) 128 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_PER_CYC256_Val _UINT32_(0x5)                                        /* (FUSES_USER_WORD_1) 256 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_PER_CYC512_Val _UINT32_(0x6)                                        /* (FUSES_USER_WORD_1) 512 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_PER_CYC1024_Val _UINT32_(0x7)                                        /* (FUSES_USER_WORD_1) 1024 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_PER_CYC2048_Val _UINT32_(0x8)                                        /* (FUSES_USER_WORD_1) 2048 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_PER_CYC4096_Val _UINT32_(0x9)                                        /* (FUSES_USER_WORD_1) 4096 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_PER_CYC8192_Val _UINT32_(0xA)                                        /* (FUSES_USER_WORD_1) 8192 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_PER_CYC16384_Val _UINT32_(0xB)                                        /* (FUSES_USER_WORD_1) 16384 clock cycles  */
#define FUSES_USER_WORD_1_WDT_PER_CYC8        (FUSES_USER_WORD_1_WDT_PER_CYC8_Val << FUSES_USER_WORD_1_WDT_PER_Pos) /* (FUSES_USER_WORD_1) 8 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_PER_CYC16       (FUSES_USER_WORD_1_WDT_PER_CYC16_Val << FUSES_USER_WORD_1_WDT_PER_Pos) /* (FUSES_USER_WORD_1) 16 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_PER_CYC32       (FUSES_USER_WORD_1_WDT_PER_CYC32_Val << FUSES_USER_WORD_1_WDT_PER_Pos) /* (FUSES_USER_WORD_1) 32 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_PER_CYC64       (FUSES_USER_WORD_1_WDT_PER_CYC64_Val << FUSES_USER_WORD_1_WDT_PER_Pos) /* (FUSES_USER_WORD_1) 64 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_PER_CYC128      (FUSES_USER_WORD_1_WDT_PER_CYC128_Val << FUSES_USER_WORD_1_WDT_PER_Pos) /* (FUSES_USER_WORD_1) 128 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_PER_CYC256      (FUSES_USER_WORD_1_WDT_PER_CYC256_Val << FUSES_USER_WORD_1_WDT_PER_Pos) /* (FUSES_USER_WORD_1) 256 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_PER_CYC512      (FUSES_USER_WORD_1_WDT_PER_CYC512_Val << FUSES_USER_WORD_1_WDT_PER_Pos) /* (FUSES_USER_WORD_1) 512 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_PER_CYC1024     (FUSES_USER_WORD_1_WDT_PER_CYC1024_Val << FUSES_USER_WORD_1_WDT_PER_Pos) /* (FUSES_USER_WORD_1) 1024 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_PER_CYC2048     (FUSES_USER_WORD_1_WDT_PER_CYC2048_Val << FUSES_USER_WORD_1_WDT_PER_Pos) /* (FUSES_USER_WORD_1) 2048 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_PER_CYC4096     (FUSES_USER_WORD_1_WDT_PER_CYC4096_Val << FUSES_USER_WORD_1_WDT_PER_Pos) /* (FUSES_USER_WORD_1) 4096 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_PER_CYC8192     (FUSES_USER_WORD_1_WDT_PER_CYC8192_Val << FUSES_USER_WORD_1_WDT_PER_Pos) /* (FUSES_USER_WORD_1) 8192 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_PER_CYC16384    (FUSES_USER_WORD_1_WDT_PER_CYC16384_Val << FUSES_USER_WORD_1_WDT_PER_Pos) /* (FUSES_USER_WORD_1) 16384 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_Pos      _UINT32_(22)                                         /* (FUSES_USER_WORD_1) WDT Window Position */
#define FUSES_USER_WORD_1_WDT_WINDOW_Msk      (_UINT32_(0xF) << FUSES_USER_WORD_1_WDT_WINDOW_Pos)  /* (FUSES_USER_WORD_1) WDT Window Mask */
#define FUSES_USER_WORD_1_WDT_WINDOW(value)   (FUSES_USER_WORD_1_WDT_WINDOW_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_WDT_WINDOW_Pos)) /* Assigment of value for WDT_WINDOW in the FUSES_USER_WORD_1 register */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC8_Val _UINT32_(0x0)                                        /* (FUSES_USER_WORD_1) 8 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC16_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_1) 16 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC32_Val _UINT32_(0x2)                                        /* (FUSES_USER_WORD_1) 32 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC64_Val _UINT32_(0x3)                                        /* (FUSES_USER_WORD_1) 64 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC128_Val _UINT32_(0x4)                                        /* (FUSES_USER_WORD_1) 128 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC256_Val _UINT32_(0x5)                                        /* (FUSES_USER_WORD_1) 256 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC512_Val _UINT32_(0x6)                                        /* (FUSES_USER_WORD_1) 512 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC1024_Val _UINT32_(0x7)                                        /* (FUSES_USER_WORD_1) 1024 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC2048_Val _UINT32_(0x8)                                        /* (FUSES_USER_WORD_1) 2048 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC4096_Val _UINT32_(0x9)                                        /* (FUSES_USER_WORD_1) 4096 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC8192_Val _UINT32_(0xA)                                        /* (FUSES_USER_WORD_1) 8192 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_WINDOW_CYC16384_Val _UINT32_(0xB)                                        /* (FUSES_USER_WORD_1) 16384 clock cycles  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC8     (FUSES_USER_WORD_1_WDT_WINDOW_CYC8_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 8 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC16    (FUSES_USER_WORD_1_WDT_WINDOW_CYC16_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 16 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC32    (FUSES_USER_WORD_1_WDT_WINDOW_CYC32_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 32 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC64    (FUSES_USER_WORD_1_WDT_WINDOW_CYC64_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 64 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC128   (FUSES_USER_WORD_1_WDT_WINDOW_CYC128_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 128 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC256   (FUSES_USER_WORD_1_WDT_WINDOW_CYC256_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 256 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC512   (FUSES_USER_WORD_1_WDT_WINDOW_CYC512_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 512 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC1024  (FUSES_USER_WORD_1_WDT_WINDOW_CYC1024_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 1024 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC2048  (FUSES_USER_WORD_1_WDT_WINDOW_CYC2048_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 2048 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC4096  (FUSES_USER_WORD_1_WDT_WINDOW_CYC4096_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 4096 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC8192  (FUSES_USER_WORD_1_WDT_WINDOW_CYC8192_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 8192 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WINDOW_CYC16384 (FUSES_USER_WORD_1_WDT_WINDOW_CYC16384_Val << FUSES_USER_WORD_1_WDT_WINDOW_Pos) /* (FUSES_USER_WORD_1) 16384 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_Pos    _UINT32_(26)                                         /* (FUSES_USER_WORD_1) WDT Early Warning Offset Position */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_Msk    (_UINT32_(0xF) << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) WDT Early Warning Offset Mask */
#define FUSES_USER_WORD_1_WDT_EWOFFSET(value) (FUSES_USER_WORD_1_WDT_EWOFFSET_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos)) /* Assigment of value for WDT_EWOFFSET in the FUSES_USER_WORD_1 register */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC8_Val _UINT32_(0x0)                                        /* (FUSES_USER_WORD_1) 8 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC16_Val _UINT32_(0x1)                                        /* (FUSES_USER_WORD_1) 16 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC32_Val _UINT32_(0x2)                                        /* (FUSES_USER_WORD_1) 32 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC64_Val _UINT32_(0x3)                                        /* (FUSES_USER_WORD_1) 64 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC128_Val _UINT32_(0x4)                                        /* (FUSES_USER_WORD_1) 128 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC256_Val _UINT32_(0x5)                                        /* (FUSES_USER_WORD_1) 256 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC512_Val _UINT32_(0x6)                                        /* (FUSES_USER_WORD_1) 512 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC1024_Val _UINT32_(0x7)                                        /* (FUSES_USER_WORD_1) 1024 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC2048_Val _UINT32_(0x8)                                        /* (FUSES_USER_WORD_1) 2048 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC4096_Val _UINT32_(0x9)                                        /* (FUSES_USER_WORD_1) 4096 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC8192_Val _UINT32_(0xA)                                        /* (FUSES_USER_WORD_1) 8192 clock cycles  */
#define   FUSES_USER_WORD_1_WDT_EWOFFSET_CYC16384_Val _UINT32_(0xB)                                        /* (FUSES_USER_WORD_1) 16384 clock cycles  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC8   (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC8_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 8 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC16  (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC16_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 16 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC32  (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC32_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 32 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC64  (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC64_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 64 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC128 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC128_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 128 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC256 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC256_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 256 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC512 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC512_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 512 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC1024 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC1024_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 1024 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC2048 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC2048_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 2048 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC4096 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC4096_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 4096 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC8192 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC8192_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 8192 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_CYC16384 (FUSES_USER_WORD_1_WDT_EWOFFSET_CYC16384_Val << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) 16384 clock cycles Position  */
#define FUSES_USER_WORD_1_WDT_WEN_Pos         _UINT32_(30)                                         /* (FUSES_USER_WORD_1) WDT Window Mode Enable Position */
#define FUSES_USER_WORD_1_WDT_WEN_Msk         (_UINT32_(0x1) << FUSES_USER_WORD_1_WDT_WEN_Pos)     /* (FUSES_USER_WORD_1) WDT Window Mode Enable Mask */
#define FUSES_USER_WORD_1_WDT_WEN(value)      (FUSES_USER_WORD_1_WDT_WEN_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_WDT_WEN_Pos)) /* Assigment of value for WDT_WEN in the FUSES_USER_WORD_1 register */
#define FUSES_USER_WORD_1_Msk                 _UINT32_(0x7FFF00FF)                                 /* (FUSES_USER_WORD_1) Register Mask  */


/* -------- FUSES_USER_WORD_2 : (FUSES Offset: 0x08) (R/W 32) USER Page Word 2 -------- */
#define FUSES_USER_WORD_2_NVMCTRL_REGION_LOCKS_Pos _UINT32_(0)                                          /* (FUSES_USER_WORD_2) NVM Region Locks Position */
#define FUSES_USER_WORD_2_NVMCTRL_REGION_LOCKS_Msk (_UINT32_(0xFFFFFFFF) << FUSES_USER_WORD_2_NVMCTRL_REGION_LOCKS_Pos) /* (FUSES_USER_WORD_2) NVM Region Locks Mask */
#define FUSES_USER_WORD_2_NVMCTRL_REGION_LOCKS(value) (FUSES_USER_WORD_2_NVMCTRL_REGION_LOCKS_Msk & (_UINT32_(value) << FUSES_USER_WORD_2_NVMCTRL_REGION_LOCKS_Pos)) /* Assigment of value for NVMCTRL_REGION_LOCKS in the FUSES_USER_WORD_2 register */
#define FUSES_USER_WORD_2_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (FUSES_USER_WORD_2) Register Mask  */


/** \brief FUSES register offsets definitions */
#define FUSES_TEMP_LOG_WORD_0_REG_OFST _UINT32_(0x00)      /* (FUSES_TEMP_LOG_WORD_0) TEMP_LOG Page Word 0 Offset */
#define FUSES_TEMP_LOG_WORD_1_REG_OFST _UINT32_(0x04)      /* (FUSES_TEMP_LOG_WORD_1) TEMP_LOG Page Word 1 Offset */
#define FUSES_TEMP_LOG_WORD_2_REG_OFST _UINT32_(0x08)      /* (FUSES_TEMP_LOG_WORD_2) TEMP_LOG Page Word 2 Offset */
#define FUSES_SW0_WORD_0_REG_OFST      _UINT32_(0x00)      /* (FUSES_SW0_WORD_0) SW0 Page Word 0 Offset */
#define FUSES_SW0_WORD_1_REG_OFST      _UINT32_(0x04)      /* (FUSES_SW0_WORD_1) SW0 Page Word 1 Offset */
#define FUSES_USER_WORD_0_REG_OFST     _UINT32_(0x00)      /* (FUSES_USER_WORD_0) USER Page Word 0 Offset */
#define FUSES_USER_WORD_1_REG_OFST     _UINT32_(0x04)      /* (FUSES_USER_WORD_1) USER Page Word 1 Offset */
#define FUSES_USER_WORD_2_REG_OFST     _UINT32_(0x08)      /* (FUSES_USER_WORD_2) USER Page Word 2 Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief TEMP_LOG_FUSES register API structure */
typedef struct
{
  __I   uint32_t                       FUSES_TEMP_LOG_WORD_0; /**< Offset: 0x00 (R/   32) TEMP_LOG Page Word 0 */
  __I   uint32_t                       FUSES_TEMP_LOG_WORD_1; /**< Offset: 0x04 (R/   32) TEMP_LOG Page Word 1 */
  __I   uint32_t                       FUSES_TEMP_LOG_WORD_2; /**< Offset: 0x08 (R/   32) TEMP_LOG Page Word 2 */
} fuses_temp_log_fuses_registers_t;

/** \brief SW0_FUSES register API structure */
typedef struct
{
  __I   uint32_t                       FUSES_SW0_WORD_0;   /**< Offset: 0x00 (R/   32) SW0 Page Word 0 */
  __I   uint32_t                       FUSES_SW0_WORD_1;   /**< Offset: 0x04 (R/   32) SW0 Page Word 1 */
} fuses_sw0_fuses_registers_t;

/** \brief USER_FUSES register API structure */
typedef struct
{
  __IO  uint32_t                       FUSES_USER_WORD_0;  /**< Offset: 0x00 (R/W  32) USER Page Word 0 */
  __IO  uint32_t                       FUSES_USER_WORD_1;  /**< Offset: 0x04 (R/W  32) USER Page Word 1 */
  __IO  uint32_t                       FUSES_USER_WORD_2;  /**< Offset: 0x08 (R/W  32) USER Page Word 2 */
} fuses_user_fuses_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAME54_FUSES_COMPONENT_H_ */
