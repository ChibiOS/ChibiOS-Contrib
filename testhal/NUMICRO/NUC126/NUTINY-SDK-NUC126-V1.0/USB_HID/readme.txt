*****************************************************************************
** ChibiOS/HAL - USB driver demo for NUC126.                               **
*****************************************************************************

** TARGET **

The demo runs on a NUTINY-SDK-NUC126-V1.0 board with a NUC126VG4AE MCU.

** The Demo **

The application demonstrates the use of the NUC126 USB driver. A successful run of the test
should begin with the on-board LED blinking slowly, then faster when the USB driver initializes.
The host should recognize the board as a USB HID, and when run with the appropriate VID/PID, the
supplied client application should communicate with the board.

** Board Setup **

- None

** Build Procedure **

The demo has been tested using gcc version 10.3.1 (GNU Arm Embedded Toolchain 10.3-2021.07).
Just modify the TRGT line in the makefile in order to use different GCC ports.

The client code was tested on Linux (TODO specify version). It uses the kernel's native hidraw API.

** Notes **

This test was adapted from Jonathan Struebel's USB_HID test for the KINETIS FRDM-KL25Z. All files 
are copyright their original authors, as indicated in the headers.

