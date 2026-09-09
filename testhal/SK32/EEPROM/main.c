/*
 * EEPROM / flash persistence verification for the SK32F077 testhal.
 *
 * Copyright (C) 2026 QMK - Apache License 2.0.
 *
 * This test proves **cross-reset (power-cycle) persistence** of the internal
 * flash, which is the backing store used by the QMK wear-leveling EEPROM.
 *
 * On every start it:
 *   1. reads a 16-bit counter from the LAST 2 KB flash sector,
 *   2. increments it,
 *   3. erases that sector and programs the new value back,
 *   4. reads it back and checks it,
 *   5. blinks PB14 the read-back value mod 40 times (easy to eyeball), and
 *      drives PB15 high only when the whole round (erase+program+readback)
 *      succeeded.
 *
 * Because the value is committed to flash (not RAM), issuing a chip reset
 * (the ST-Link "virtual unplug" reset — no USB disconnect needed) must NOT
 * clear it: each reset makes the count tick up.  That is exactly the property
 * the wear-leveling EEPROM relies on.
 *
 * PB14 / PB15 are the same "user" LEDs used by the other SK32 testhals.
 */

#include "ch.h"
#include "hal.h"
#include "hal_efl.h"

/*===========================================================================*/
/* Application entry point.                                                   */
/*===========================================================================*/
int main(void) {

  /* The last flash sector is dedicated to the counter.  It sits at the very
     end of the 128 KB flash (0x0801F800 on the SK32F077xB), far from the
     bootloader (0x08004000 limit) and far from the application code. */
  enum {
    BLINK_SPAN   = 40U,          /* blink count is shown modulo this          */
    BLINK_ON_MS  = 150U,         /* LED on time per blink                     */
    BLINK_OFF_MS = 150U,         /* LED off time per blink                    */
    IDLE_MS      = 60U           /* pause before showing the next counter     */
  };

  BaseFlash            *fbp;
  const flash_descriptor_t *desc;
  flash_sector_t        sector;
  flash_offset_t        offset;
  volatile uint16_t    *slot;
  uint16_t              current, next;
  flash_error_t         err;
  unsigned int          blink, i;

  /*
   * System initializations.
   */
  halInit();
  chSysInit();

  /* PB14/PB15 as push-pull outputs, off by default. */
  palSetPadMode(GPIOB, 14U, PAL_MODE_OUTPUT_PUSHPULL);
  palSetPadMode(GPIOB, 15U, PAL_MODE_OUTPUT_PUSHPULL);
  palClearPad(GPIOB, 14U);
  palClearPad(GPIOB, 15U);

  /* Start the embedded-flash driver.  No vendor configuration structure is
     used by the SK32 EFL LLD, so NULL is passed. */
  eflStart(&EFLD1, NULL);
  fbp  = getBaseFlash(&EFLD1);
  desc = flashGetDescriptor(fbp);

  /* Pick the last sector and compute its offset (from flash base 0) and its
     absolute memory address. */
  sector = (flash_sector_t)(desc->sectors_count - 1U);
  offset = (flash_offset_t)sector * (flash_offset_t)desc->sectors_size;
  slot   = (volatile uint16_t *)(void *)(desc->address + (unsigned int)offset);

  current = *slot;
  if (current == 0xFFFFU) {
    /* Fresh erased sector: first run. */
    current = 0U;
  }
  next = (uint16_t)(current + 1U);

  /* Erase the counter sector. */
  err = flashStartEraseSector(fbp, sector);
  if (err == FLASH_NO_ERROR) {
    err = flashWaitErase(fbp);
  }

  /* Program the new value (2 bytes = one flash line on the SK32F077). */
  if (err == FLASH_NO_ERROR) {
    err = flashProgram(fbp, offset, (uint32_t)sizeof(next),
                       (const uint8_t *)&next);
  }

  /* Commit: verify the slot really reads back what we programmed. */
  if ((err == FLASH_NO_ERROR) && (*slot == next)) {
    /* Persistence round-trip OK: light PB15 solid. */
    palSetPad(GPIOB, 15U);
  }
  else {
    /* Erase/program/readback error: PB15 stays off; PB14 does one slow
       blink below as the failure indicator. */
    next = 0xFFFFU;
  }

  /* Show the programmed counter value on PB14 (blink count % BLINK_SPAN). */
  blink = (unsigned int)(next % BLINK_SPAN);
  if (next == 0xFFFFU) {
    blink = 1U; /* a single slow blink signals the error path */
  }

  for (i = 0U; i < blink; i++) {
    palSetPad(GPIOB, 14U);
    chThdSleepMilliseconds(BLINK_ON_MS);
    palClearPad(GPIOB, 14U);
    chThdSleepMilliseconds(BLINK_OFF_MS);
  }

  /* Idle; PB14 stays off, PB15 indicates last round success. */
  chThdSleepMilliseconds(IDLE_MS);

  while (true) {
    palTogglePad(GPIOB, 14U);
    chThdSleepMilliseconds(500U);
  }
}