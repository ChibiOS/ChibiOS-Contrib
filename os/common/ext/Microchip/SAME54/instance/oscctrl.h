/*
 * Instance header file for ATSAME54P20A
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
#ifndef _SAME54_OSCCTRL_INSTANCE_
#define _SAME54_OSCCTRL_INSTANCE_


/* ========== Instance Parameter definitions for OSCCTRL peripheral ========== */
#define OSCCTRL_DFLL48M_BIASTESTPT_IMPLEMENTED   (0)        /* DFLL48M bias test mode implemented */
#define OSCCTRL_DFLL48M_CDACSTEPSIZE_SIZE        (2)        /* Size COARSE DAC STEP */
#define OSCCTRL_DFLL48M_COARSE_RESET_VALUE       (32)       /* DFLL48M Frequency Coarse Reset Value (Before Calibration) */
#define OSCCTRL_DFLL48M_COARSE_SIZE              (6)        /* Size COARSE CALIBRATION */
#define OSCCTRL_DFLL48M_ENABLE_RESET_VALUE       (1)        /* Run oscillator at reset */
#define OSCCTRL_DFLL48M_FDACSTEPSIZE_SIZE        (2)        /* Size FINE DAC STEP */
#define OSCCTRL_DFLL48M_FINE_RESET_VALUE         (128)      /* DFLL48M Frequency Fine Reset Value (Before Calibration) */
#define OSCCTRL_DFLL48M_FINE_SIZE                (8)        /* Size FINE CALIBRATION */
#define OSCCTRL_DFLL48M_ONDEMAND_RESET_VALUE     (1)        /* Run oscillator always or only when requested */
#define OSCCTRL_DFLL48M_RUNSTDBY_RESET_VALUE     (0)        /* Run oscillator even if standby mode */
#define OSCCTRL_DFLL48M_TCAL_SIZE                (4)        /* Size TEMP CALIBRATION */
#define OSCCTRL_DFLL48M_TCBIAS_SIZE              (2)        /* Size TC BIAS CALIBRATION */
#define OSCCTRL_DFLL48M_TESTPTSEL_SIZE           (3)        /* Size TEST POINT SELECTOR */
#define OSCCTRL_DFLL48M_VERSION                  (0x100)    
#define OSCCTRL_DFLL48M_WAITLOCK_ACTIVE          (1)        /* Enable Wait Lock Feature */
#define OSCCTRL_DFLLS_NUM                        (1)        /* Number of DFLLs */
#define OSCCTRL_DFLL_IMPLEMENTED                 (1)        /* DFLL implemented */
#define OSCCTRL_DPLL0_I12ND_I12NDFRAC_PAD_CONTROL (0)        /* NOT_IMPLEMENTED: The ND and NDFRAC pad tests are not used, use registers instead */
#define OSCCTRL_DPLL0_IMPLEMENTED                (1)        /* DPLL0 implemented */
#define OSCCTRL_DPLL0_OCC_IMPLEMENTED            (1)        /* DPLL0 OCC Implemented */
#define OSCCTRL_DPLL1_I12ND_I12NDFRAC_PAD_CONTROL (0)        /* NOT_IMPLEMENTED: The ND and NDFRAC pad tests are not used, use registers instead */
#define OSCCTRL_DPLL1_IMPLEMENTED                (1)        /* DPLL1 implemented */
#define OSCCTRL_DPLL1_OCC_IMPLEMENTED            (0)        /* DPLL1 OCC Implemented */
#define OSCCTRL_DPLLS_NUM                        (2)        /* Number of DPLLs */
#define OSCCTRL_FDPLL_VERSION                    (0x100)    
#define OSCCTRL_GCLK_ID_DFLL48                   (0)        /* Index of Generic Clock for DFLL48 */
#define OSCCTRL_GCLK_ID_FDPLL0                   (1)        /* Index of Generic Clock for DPLL0 */
#define OSCCTRL_GCLK_ID_FDPLL032K                (3)        /* Index of Generic Clock for DPLL0 32K */
#define OSCCTRL_GCLK_ID_FDPLL1                   (2)        /* Index of Generic Clock for DPLL1 */
#define OSCCTRL_GCLK_ID_FDPLL132K                (3)        /* Index of Generic Clock for DPLL1 32K */
#define OSCCTRL_INSTANCE_ID                      (4)        /* Instance index for OSCCTRL */
#define OSCCTRL_OSC16M_IMPLEMENTED               (0)        /* OSC16M implemented */
#define OSCCTRL_OSC48M_IMPLEMENTED               (0)        /* OSC48M implemented */
#define OSCCTRL_OSC48M_NUM                       (1)        
#define OSCCTRL_RCOSCS_NUM                       (1)        /* Number of RCOSCs (min 1) */
#define OSCCTRL_XOSC0_CFD_CLK_SELECT_SIZE        (4)        /* Clock fail prescaler size */
#define OSCCTRL_XOSC0_CFD_IMPLEMENTED            (1)        /* Clock fail detected for xosc implemented */
#define OSCCTRL_XOSC0_IMPLEMENTED                (1)        /* XOSC0 implemented */
#define OSCCTRL_XOSC0_ONDEMAND_RESET_VALUE       (1)        /* Run oscillator always or only when requested */
#define OSCCTRL_XOSC0_RUNSTDBY_RESET_VALUE       (0)        /* Run oscillator even if standby mode */
#define OSCCTRL_XOSC1_CFD_CLK_SELECT_SIZE        (4)        /* Clock fail prescaler size */
#define OSCCTRL_XOSC1_CFD_IMPLEMENTED            (1)        /* Clock fail detected for xosc implemented */
#define OSCCTRL_XOSC1_IMPLEMENTED                (1)        /* XOSC1 implemented */
#define OSCCTRL_XOSC1_ONDEMAND_RESET_VALUE       (1)        /* Run oscillator always or only when requested */
#define OSCCTRL_XOSC1_RUNSTDBY_RESET_VALUE       (0)        /* Run oscillator even if standby mode */
#define OSCCTRL_XOSCS_NUM                        (2)        /* Number of XOSCs */
#define OSCCTRL_XOSC_VERSION                     (0x100)    

#endif /* _SAME54_OSCCTRL_INSTANCE_ */
