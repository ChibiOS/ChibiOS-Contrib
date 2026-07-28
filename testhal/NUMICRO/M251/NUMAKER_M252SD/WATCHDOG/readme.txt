****************************************************************************
** ChibiOS/HAL - watchdog/reset test for M252SD2AE.                       **
****************************************************************************

** TARGET **

NuMaker-M252SD with an M252SD2AE MCU.

** The Test **

The test provides a shell through Nu-Link VCOM at 115200 8N1.

- `cause` shows reset flags captured at startup;
- `reset` requests a Cortex-M23 system reset and must produce `SYSRF`;
- `wdt_stop` verifies two watchdog start/stop cycles without a reset;
- `wdt` feeds WDGD1 three times, then waits for a watchdog reset and `WDTRF`.

The watchdog timeout is about 1.7 seconds after the final feed. This test does
not modify APROM, LDROM, or User Configuration.

** Board Setup **

Connect Nu-Link USB and open VCOM at 115200 8N1 with hardware and software
flow control disabled.

** Build Procedure **

Run `make` in this directory with an Arm GNU Toolchain in PATH.
