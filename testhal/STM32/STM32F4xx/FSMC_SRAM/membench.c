/*
    ChibiOS/RT - Copyright (C) 2013-2014 Uladzimir Pylinsky aka barthess

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

#include <string.h>

#include "ch.h"
#include "hal.h"

#include "membench.h"

/*
 ******************************************************************************
 * DEFINES
 ******************************************************************************
 */

/*
 ******************************************************************************
 * EXTERNS
 ******************************************************************************
 */

/*
 ******************************************************************************
 * PROTOTYPES
 ******************************************************************************
 */

/*
 ******************************************************************************
 * GLOBAL VARIABLES
 ******************************************************************************
 */
volatile int warning_suppressor;

/*
 ******************************************************************************
 ******************************************************************************
 * LOCAL FUNCTIONS
 ******************************************************************************
 ******************************************************************************
 */
/*
 * Calculates memory access time in MiB.
 */
double speed(const time_measurement_t *tmu, size_t len) {
  double size; // MiB
  double time; // sec

  size  = len;
  size /= 1024 * 1024;

  time  = tmu->last;
  time /= STM32_SYSCLK;

  return size / time;
}

/*
 ******************************************************************************
 * EXPORTED FUNCTIONS
 ******************************************************************************
 */

/*
 *
 */
void membench_run(membench_t *dest, const membench_t *src,
                  membench_result_t *result) {
  time_measurement_t mem_tmu;
  size_t len;

  if (src->size < dest->size)
    len = src->size;
  else
    len = dest->size;

  /* memset */
  chTMObjectInit(&mem_tmu);
  chTMStartMeasurementX(&mem_tmu);
  memset(dest->start, 0x55, dest->size);
  chTMStopMeasurementX(&mem_tmu);
  result->memset_spd = speed(&mem_tmu, dest->size);

  /* memcpy */
  chTMObjectInit(&mem_tmu);
  chTMStartMeasurementX(&mem_tmu);
  memcpy(dest->start, src->start, len);
  chTMStopMeasurementX(&mem_tmu);
  result->memcpy_spd = speed(&mem_tmu, len);

  /* memcmp */
  chTMObjectInit(&mem_tmu);
  chTMStartMeasurementX(&mem_tmu);
  warning_suppressor = memcmp(dest->start, src->start, len);
  chTMStopMeasurementX(&mem_tmu);
  result->memcmp_spd = speed(&mem_tmu, len);
}

