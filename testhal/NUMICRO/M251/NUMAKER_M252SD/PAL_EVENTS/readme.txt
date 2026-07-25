****************************************************************************
** ChibiOS/HAL - PAL edge-event test for M252SD2AE.                       **
****************************************************************************

** TARGET **

NuMaker-M252SD with an M252SD2AE MCU.

** The Test **

The test drives PA.3/D10 once per second and receives it through PA.0/D11.
PA.0 has a pull-down and a PAL callback on both edges. VCOM at 115200 8N1
prints the levels, rising and falling counts, and `OK` or `ERROR`.

The startup disable/re-enable check must print
`disable/re-enable self-test: PASS`. Thereafter every transition must report
matching levels and exactly one increment of the expected edge counter.

** Board Setup **

Connect Arduino D10/SS (PA.3) to Arduino D11/MOSI (PA.0). Do not connect
either signal to GND or a power rail. Connect Nu-Link VCOM at 115200 8N1 with
flow control disabled.

** Build Procedure **

Run `make` in this directory with an Arm GNU Toolchain in PATH.
