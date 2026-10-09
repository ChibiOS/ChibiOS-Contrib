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

/*
 * EFR32FG14P drivers configuration.
 * The following settings override the default settings present in
 * the various device driver implementation headers.
 * Note that the settings for each driver only have effect if the whole
 * driver is enabled in halconf.h.
 */

#ifndef MCUCONF_H
#define MCUCONF_H

#define EFR32FG14P23X_MCUCONF

/*
 * HAL driver system settings.
 */
#define EFR32_LFXO_ENABLED                  TRUE
#define EFR32_HFXO_ENABLED                  FALSE
#define EFR32_LFRCO_ENABLED                 FALSE
#define EFR32_HFRCO_ENABLED                 TRUE

/*
 * Peripherals clock sources.
 */
#define EFR32_RTCCSEL                       EFR32_RTCCSEL_LFXO
#define EFR32_LETIM1SEL                     EFR32_LETIM1SEL_LFXO

/*
 * ST driver system settings.
 */
#define EFR32_ST_IRQ_PRIORITY               8
#define EFR32_ST_USE_TIMER                  1

#endif /* MCUCONF_H */
