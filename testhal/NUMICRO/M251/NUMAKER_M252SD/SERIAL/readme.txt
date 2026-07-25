****************************************************************************
** ChibiOS/HAL - SERIAL driver demo for M252SD2AE.                        **
****************************************************************************

** TARGET **

NuMaker-M252SD with an M252SD2AE MCU.

** The Demo **

SD0 uses UART0 through Nu-Link VCOM. After `Serial stop/start PASS.` the demo
echoes every received character, applying a Caesar +1 shift to ASCII letters.
For example, `abc XYZ 123` returns `bcd YZA 123`.

** Board Setup **

Connect Nu-Link USB and open VCOM at 115200 8N1 with hardware and software
flow control disabled.

** Build Procedure **

Run `make` in this directory with an Arm GNU Toolchain in PATH.
