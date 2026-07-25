****************************************************************************
** ChibiOS/HAL - Blinky test for M252SD2AE.                               **
****************************************************************************

** TARGET **

NuMaker-M252SD with an M252SD2AE MCU.

** The Test **

The active-low on-board LED on PB.14 toggles once per second. Before the
normal loop, the test verifies nested protected-register unlock/lock handling.
The LED must blink at 0.5 Hz (one second on, one second off).

** Board Setup **

- None.

** Build Procedure **

Run `make` in this directory with an Arm GNU Toolchain in PATH.
