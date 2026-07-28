****************************************************************************
** ChibiOS/HAL - SPI loopback test for M252SD2AE.                         **
****************************************************************************

** TARGET **

NuMaker-M252SD with an M252SD2AE MCU.

** The Test **

SPI0 runs as an 8-bit, MSB-first master. The test covers all four CPOL/CPHA
modes at 100 kHz, 1 MHz and 2 MHz, transfer sizes 1, 7, 8, 9, 64 and 257, and
the exchange, send, receive, ignore and polled APIs.

VCOM at 115200 8N1 reports progress. A complete pass ends with
`SPI0 LOOPBACK PASS`.

** Board Setup **

Connect Arduino D11/MOSI (PA.0) to Arduino D12/MISO (PA.1). Do not connect
either signal to GND or a power rail. D10/SS and D13/SCK require no jumper.
Connect Nu-Link VCOM at 115200 8N1 with flow control disabled.

** Build Procedure **

Run `make` in this directory with an Arm GNU Toolchain in PATH.
