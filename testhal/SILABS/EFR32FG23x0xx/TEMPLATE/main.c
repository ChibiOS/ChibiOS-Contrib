/*
    ChibiOS - Copyright (C) 2024 Xael South

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
#include "cmsis_os.h"
#include "hal.h"
#include "hal_buram.h"

static void led_on(void)
{

  /* PB2 = LED */
  palSetPadMode(GPIOB, 2, PAL_MODE_OUTPUT_PUSHPULL);
  palSetPad(GPIOB, 2);
}

static void led_off(void)
{

  /* PB2 = LED */
  palSetPadMode(GPIOB, 2, PAL_MODE_OUTPUT_PUSHPULL);
  palClearPad(GPIOB, 2);
}

static int dma_calback_triggered;

static void dma_callback(void *ptr, uint32_t mask)
{

  (void)ptr;
  (void)mask;

  dma_calback_triggered++;
}

static void test_dma_check_stream_allocation(void)
{

  /* Check stream allocation. */
  const efr32_dma_stream_t *dmastp[EFR32_DMA_STREAMS + 1] = {
    dmaStreamAlloc(EFR32_DMA_STREAM_ID_ANY, 4, NULL, NULL),
    dmaStreamAlloc(EFR32_DMA_STREAM_ID_ANY, 4, NULL, NULL),
    dmaStreamAlloc(EFR32_DMA_STREAM_ID_ANY, 4, NULL, NULL),
    dmaStreamAlloc(EFR32_DMA_STREAM_ID_ANY, 4, NULL, NULL),

    dmaStreamAlloc(EFR32_DMA_STREAM_ID_ANY, 4, NULL, NULL),
    dmaStreamAlloc(EFR32_DMA_STREAM_ID_ANY, 4, NULL, NULL),
    dmaStreamAlloc(EFR32_DMA_STREAM_ID_ANY, 4, NULL, NULL),
    dmaStreamAlloc(EFR32_DMA_STREAM_ID_ANY, 4, NULL, NULL),

    dmaStreamAlloc(EFR32_DMA_STREAM_ID_ANY, 4, NULL, NULL),
  };

  for (unsigned i = 0; i < EFR32_DMA_STREAMS; i++)
  {
    osalDbgCheck(dmastp[i] != NULL);
  }

  /* Can't allocate more channels. */
  osalDbgCheck(dmastp[EFR32_DMA_STREAMS] == NULL);

  for (unsigned i = 0; i < EFR32_DMA_STREAMS; i++)
  {
    dmaStreamFree(dmastp[i]);
  }
}

static void test_dma_check_data_transfer(void)
{

  /* Check data transfer. */
  uint8_t dma_test_src[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 8, 7, 6, 5, 4, 3, 2, 1 };
  uint8_t dma_test_dst[32] = { 0 };

  const efr32_dma_stream_t *dmastp1 = dmaStreamAlloc(EFR32_DMA_STREAM_ID_ANY, 4, dma_callback, &dma_test_dst[0]);
  const efr32_dma_stream_t *dmastp2 = dmaStreamAlloc(EFR32_DMA_STREAM_ID_ANY, 4, dma_callback, &dma_test_dst[16]);

  dmaStartMemCopy(dmastp1, 0, &dma_test_src[0], &dma_test_dst[0], 8);
  dmaStartMemCopy(dmastp2, 0, &dma_test_src[8], &dma_test_dst[16], 8);

  dmaWaitCompletion(dmastp1);
  dmaWaitCompletion(dmastp2);

  dmaStreamFree(dmastp1);
  dmaStreamFree(dmastp2);

  for (size_t i = 0; i < 8; i++)
  {
    osalDbgCheck(dma_test_src[i] == dma_test_dst[i]);
    osalDbgCheck(dma_test_src[i + 8] == dma_test_dst[i + 16]);
  }

  for (size_t i = 8; i < 16; i++)
  {
    osalDbgCheck(dma_test_dst[i] == 0);
    osalDbgCheck(dma_test_dst[i + 16] == 0);
  }

  /* Check number of callbacks. */
  osalDbgCheck(dma_calback_triggered == 2);
}

/*
 * Application entry point.
 */
int main(void)
{

  int unused = 0;
  (void)unused;

  /* HAL initialization, this also initializes the configured device drivers
     and performs the board-specific initializations.*/
  halInit();

  /* The kernel is initialized but not started yet, this means that
     main() is executing with absolute priority but interrupts are
     already enabled.*/
  osKernelInitialize();

  /* Kernel started, the main() thread has priority osPriorityNormal
     by default.*/
  osKernelStart();

  led_off();
  test_dma_check_stream_allocation();
  test_dma_check_data_transfer();
  led_on();

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (true)
  {
    osDelay(1000);
  }
}