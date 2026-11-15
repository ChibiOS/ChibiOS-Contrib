/*
    ChibiOS - Copyright (C) 2023 Xael South

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

#define CC13x0_MCUCONF

/*
 * HAL driver system settings.
 */
#define TI_SCLK_LF_ENABLED                  FALSE
#define TI_SCLK_HF_ENABLED                  TRUE
#define TI_SCLK_LF_AUX_ENABLED              TI_SCLK_LF_ENABLED
#define TI_ACLK_ADC_ENABLED                 TI_SCLK_HF_ENABLED
#define TI_ACLK_REF_ENABLED                 FALSE
#define TI_ACLK_TDC_ENABLED                 FALSE



/*
 * Peripherals clock sources.
 */

#endif /* _MCUCONF_H_ */
