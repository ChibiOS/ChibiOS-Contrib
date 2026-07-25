/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.

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

#ifndef MCUCONF_H
#define MCUCONF_H

#define M251_MCUCONF                       TRUE

#define M251_NO_INIT                       FALSE
#define M251_HCLK                          __HIRC

#define M251_ST_IRQ_PRIORITY               3
#define M251_ST_CLK                        M251_HCLK

#define M251_USB_USE_USBD1                 TRUE
#define M251_USB_IRQ_PRIORITY              3
#define M251_USB_SRC                       M251_USBSRC_HIRC
#define M251_USB_DIV                       1
#define M251_USB_USE_HIRC_TRIM             TRUE
#define M251_USB_HIRC_TRIM_BOUNDARY        10U

#endif /* MCUCONF_H */
