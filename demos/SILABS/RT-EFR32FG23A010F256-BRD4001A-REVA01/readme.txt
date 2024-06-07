*****************************************************************************
** ChibiOS/RT port for ARM-Cortex-M33 EFR32FG23.                           **
*****************************************************************************

** TARGET **

The demo runs on an CUSTOM board EFR32FG23 equipped with EFR32FG23A010F256QFN48.

** TODO **

HAL is far from complete. What is working:
  * SYSTICK
  * LETIMER0 for deep sleep and serial
  * serial IO (SIO) have been implemented

Implement export clocks in GPIOs.

Make HCLK DIV2 (CLKOUT) working.

Make radio driver with underlying rail lib.



** The Demo **

** Build Procedure **

** Notes **

Some files used by the demo are not part of ChibiOS/RT but are copyright of
Silicon Labs and are licensed under a different license. Also note that not
all the files present in the emlib library are distributed with ChibiOS/RT,
you can find the whole library on the ST web site:

                             http://www.silabs.com
