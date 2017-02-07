/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

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

#include "ch.h"
#include "hal.h"

void comp2_cb(COMPDriver *comp) {

  if (comp->reg->CSR & COMP_CSR_COMPxOUT) {


  }

}

void comp4_cb(COMPDriver *comp) {
  (void) comp;

}

static const COMPConfig comp2_conf = {
  COMP_OUTPUT_NORMAL,
  comp2_cb,
  COMP_CSR_COMPxINSEL_0 | COMP_CSR_COMPxOUTSEL_0 // CSR
};

static const COMPConfig comp4_conf = {
  COMP_OUTPUT_INVERTED,
  comp4_cb,
  COMP_CSR_COMPxINSEL_0 | COMP_CSR_COMPxOUTSEL_1 // CSR
};


/*
 * Application entry point.
 */
int main(void) {

  halInit();
  chSysInit();

  compStart(&COMPD2, &comp2_conf);
  compStart(&COMPD4, &comp4_conf);

  /*
   * Normal main() thread activity, it resets the watchdog.
   */
  while (true) {
    chThdSleepMilliseconds(500);
  }
  return 0;
}
