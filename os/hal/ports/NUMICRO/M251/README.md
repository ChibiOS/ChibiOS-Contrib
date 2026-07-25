# Nuvoton M251/M252 HAL port

This directory contains the ChibiOS HAL low-level drivers for the Nuvoton
M251/M252 family. The current device registry describes the M252SD2AE used on
the NuMaker-M252SD board.

The port provides low-level drivers for:

- system clocks and reset;
- SysTick;
- GPIO and PAL events;
- UART;
- USB device;
- TIMER and BPWM;
- I2C and SPI;
- embedded flash;
- watchdog.

The drivers support both ChibiOS/RT 7 and ChibiOS/RT 8 APIs used by
ChibiOS-Contrib.

## Configuration

Applications select clocks, peripheral instances, and interrupt priorities in
`mcuconf.h`. The principal option groups are:

- `M251_HCLK_*`, `M251_PLL_*`, and `M251_USB_*` for system and USB clocks;
- `M251_ST_*` for the system timer;
- `M251_GPT_*`, `M251_PWM_*`, `M251_I2C_*`, `M251_SPI_*`, and
  `M251_SERIAL_*` for peripheral instances and interrupt priorities;
- `M251_NO_INIT` when clock and system initialization is performed externally.

The applications under
`testhal/NUMICRO/M251/NUMAKER_M252SD` provide complete configurations for each
supported driver.

## Current limitations

- The system timer supports periodic SysTick mode. Free-running mode is not
  implemented.
- SPI supports master mode only and does not support circular transfers.
- The SERIAL driver currently requires the direct 48 MHz HIRC clock.
- USB is available only on M252 devices containing the USBD peripheral.
- The USB driver exposes endpoint zero and five logical bidirectional
  endpoints through the device's 12 hardware endpoint slots.
- Isochronous USB endpoints are not supported.

Unsupported configurations are rejected by compile-time checks where
possible.
