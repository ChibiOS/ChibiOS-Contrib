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

#include "hal.h"

/**
 * @brief   PAL setup.
 * @details Digital I/O ports static configuration as defined in @p board.h.
 *          This variable is used by the HAL when initializing the PAL driver.
 */
#if HAL_USE_PAL || defined(__DOXYGEN__)
const PALConfig pal_default_config =
{
  .PAData = {
    .ctrlr =  PAL_EFR32_PORTA_CTRL_DEFAULT,
    .modelr = PAL_EFR32_PORTA_MODEL_DEFAULT,
    .modehr = PAL_EFR32_PORTA_MODEH_DEFAULT,
    .doutr =  PAL_EFR32_PORTA_DOUT_DEFAULT
  },

  .PBData = {
    .ctrlr =  PAL_EFR32_PORTB_CTRL_DEFAULT,
    .modelr = PAL_EFR32_PORTB_MODEL_DEFAULT,
    .modehr = PAL_EFR32_PORTB_MODEH_DEFAULT,
    .doutr =  PAL_EFR32_PORTB_DOUT_DEFAULT
  },

  .PCData = {
    .ctrlr =  PAL_EFR32_PORTC_CTRL_DEFAULT,
    .modelr = PAL_EFR32_PORTC_MODEL_DEFAULT,
    .modehr = PAL_EFR32_PORTC_MODEH_DEFAULT,
    .doutr =  PAL_EFR32_PORTC_DOUT_DEFAULT
  },

  .PDData = {
    .ctrlr =  PAL_EFR32_PORTD_CTRL_DEFAULT,
    .modelr = PAL_EFR32_PORTD_MODEL_DEFAULT,
    .modehr = PAL_EFR32_PORTD_MODEH_DEFAULT,
    .doutr =  PAL_EFR32_PORTD_DOUT_DEFAULT
  },
};
#endif

/*
 * Early initialization code.
 * This initialization must be performed just after stack setup and before
 * any other initialization.
 */
void __early_init(void) {

  efr32_escape_hatch();
  efr32_chip_init();
  efr32_clock_init();
}

/*
 * Board-specific initialization code.
 */
void boardInit(void) {

}
