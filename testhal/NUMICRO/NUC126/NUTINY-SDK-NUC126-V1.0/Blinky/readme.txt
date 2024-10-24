*****************************************************************************
** ChibiOS/HAL - Blinky demo for NUC126.                                   **
*****************************************************************************

** TARGET **

The demo runs on a NUTINY-SDK-NUC126-V1.0 board with a NUC126VG4AE MCU.

** The Demo **

The application demonstrates the use of the NUC126 platform driver, and a little
bit of the PAL. A successful run of the test involves the on-board LED blinking at .5 Hz
(on for 1 second, then off for one second).

** Board Setup **

- None

** Build Procedure **

The demo has been tested using gcc version 10.3.1 (GNU Arm Embedded Toolchain 10.3-2021.07).
Just modify the TRGT line in the makefile in order to use different GCC ports.
