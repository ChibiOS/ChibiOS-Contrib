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
#ifndef _SAME54_USB_INSTANCE_
#define _SAME54_USB_INSTANCE_


/* ========== Instance Parameter definitions for USB peripheral ========== */
#define USB_AHB_2_USB_FIFO_DEPTH                 (4)        /* bytes number, should be at least 2, and 2^n (4,8,16 ...) */
#define USB_AHB_2_USB_RD_DATA_BITS               (8)        /* 8, 16 or 32, here : 8-bits is required as UTMI interface should work in 8-bits mode */
#define USB_AHB_2_USB_WR_DATA_BITS               (32)       /* 8, 16 or 32 : here, AHB transfer is made in word mode */
#define USB_AHB_2_USB_WR_THRESHOLD               (2)        /* as soon as there are N bytes-free inside the fifo, ahb read transfer is requested */
#define USB_DATA_BUS_16_8                        (0)        /* UTMI/SIE data bus size : 0 -> 8 bits, 1 -> 16 bits */
#define USB_EPNUM                                (8)        /* parameter for rtl : max of ENDPOINT and PIPE NUM */
#define USB_EPT_NUM                              (8)        /* Number of USB end points */
#define USB_GCLK_ID                              (10)       /* Index of Generic Clock */
#define USB_INITIAL_CONTROL_QOS                  (3)        /* CONTROL QOS RESET value */
#define USB_INITIAL_DATA_QOS                     (3)        /* DATA QOS RESET value */
#define USB_INSTANCE_ID                          (32)       /* Instance index for USB */
#define USB_MISSING_SOF_DET_IMPLEMENTED          (1)        /* 48 mHz xPLL feature implemented */
#define USB_PIPE_NUM                             (8)        /* Number of USB pipes */
#define USB_SYSTEM_CLOCK_IS_CKUSB                (0)        /* Dual (1'b0) or Single (1'b1) clock system */
#define USB_2_AHB_FIFO_DEPTH                     (4)        /* bytes number, should be at least 2, and 2^n (4,8,16 ...) */
#define USB_2_AHB_RD_DATA_BITS                   (16)       /* 8, 16 or 32, here : 8-bits is required as UTMI interface should work in 8-bits mode */
#define USB_2_AHB_RD_THRESHOLD                   (2)        /* as soon as there are 16 bytes-free inside the fifo, ahb read transfer is requested */
#define USB_2_AHB_WR_DATA_BITS                   (8)        /* 8, 16 or 32 : here : 8-bits is required as UTMI interface should work in 8-bits mode */

#endif /* _SAME54_USB_INSTANCE_ */
