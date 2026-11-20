*****************************************************************************
** ChibiOS/RT port for ARM-Cortex-M33 EFR32FG23.                           **
*****************************************************************************

** TARGET **

The demo runs on a CUSTOM board EFR32FG23 equipped with EFR32FG23A010F256QFN48.

** TODO **

HAL in general. Currently the HAL is far from being complete.

Get RMU reset cause; factory default.

Use BURTC for time keeping; implement calendar.

Implement user data page write/read.

Implement DC/DC mode switching.

Make HCLK DIV4/8... (CLKOUT) working.

Create radio driver with underlying RAIL lib.

** The Demo **

What is working now:
  * SYSTICK
  * LETIMER0 for deep sleep and serial
  * serial IO (SIO) implemented
  * BURTC works as (software) RTC

** Build Procedure **

** Notes **

Some files used by the demo are not part of ChibiOS/RT but are copyright of
Silicon Labs and are licensed under a different license. Also note that not
all the files present in the emlib library are distributed with ChibiOS/RT,
you can find the whole library on the Silicon Labs web site:

                             https://www.silabs.com
