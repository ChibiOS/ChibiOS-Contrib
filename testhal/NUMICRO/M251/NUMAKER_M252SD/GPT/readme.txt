****************************************************************************
** ChibiOS/HAL - GPT test for M252SD2AE.                                  **
****************************************************************************

** TARGET **

NuMaker-M252SD with an M252SD2AE MCU.

** The Test **

GPTD1 uses TIMER0 in continuous mode with a one-second interval. Its callback
toggles the active-low PB.14 LED. Startup verifies callback delivery, stop,
and restart before entering the normal loop.

The LED must blink at 0.5 Hz (one second on, one second off).

** Board Setup **

- None.

** Build Procedure **

Run `make` in this directory with an Arm GNU Toolchain in PATH.
