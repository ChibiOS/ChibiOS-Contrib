/*
  ChibiOS - Copyright (C) 2020 Alex Lewontin

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

#ifndef _MCUCONF_H_
#define _MCUCONF_H_

/*
 * Board setting
 */

/*
 * HAL driver system settings.
 */
// Old configuration
/*
#define NUC126_HSI48_ENABLED TRUE
#define NUC126_HSE_ENABLED FALSE
#define NUC126_PLL_ENABLED FALSE
//#define NUC126_HSE_ENABLED TRUE
//#define NUC126_PLL_ENABLED TRUE
//#define NUC126_PLLSRC NUC126_PLLSRC_HSE
#define NUC126_HCLKSRC NUC126_HCLKSRC_HSI48
#define NUC126_HCLKDIV 1
//#define NUC126_HCLKSRC NUC126_HCLKSRC_PLL
//#define NUC126_HCLKDIV 2
//#define NUC126_PLL_NF 144
#define NUC126_USB_USE_USB0 TRUE
#define NUC126_USB_USE_USB1 TRUE
*/
// New configuration
#define NUC126_HSE_ENABLED TRUE
#define NUC126_PLL_ENABLED TRUE
#define NUC126_PLLSRC NUC126_PLLSRC_HSE
#define NUC126_HCLKSRC NUC126_HCLKSRC_PLL
#define NUC126_HCLKDIV 2
#define NUC126_PLL_NF 144
#define NUC126_USB_USE_USB0 TRUE
#define NUC126_USB_USE_USB1 TRUE

#define NUC126_SERIAL_USE_UART0 TRUE
#define NUC126_SERIAL_CLKSRC NUC126_SERIAL_CLKSRC_HSI

#define NUC126_MCUCONF

#endif /* _MCUCONF_H_ */
