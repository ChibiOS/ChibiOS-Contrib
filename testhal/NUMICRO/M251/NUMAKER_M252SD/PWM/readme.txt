****************************************************************************
** ChibiOS/HAL - PWM test for M252SD2AE.                                  **
****************************************************************************

** TARGET **

NuMaker-M252SD with an M252SD2AE MCU.

** The Test **

BPWM0 channel 0 drives PA.0 at approximately 1 kHz. The duty cycle repeats
through 1%, 10%, 25%, 50%, 75%, and 90%, holding each level for two seconds.
Startup also verifies periodic and channel callbacks and a stop/start cycle.

** Board Setup **

Connect Arduino D11 (PA.0) to JP6.11 or JP6.12 (PB.14) with one jumper. The
active-low on-board LED must show six increasing brightness levels repeatedly.

Use this jumper only with this image: other firmware can configure both pins as
outputs.

** Build Procedure **

Run `make` in this directory with an Arm GNU Toolchain in PATH.
