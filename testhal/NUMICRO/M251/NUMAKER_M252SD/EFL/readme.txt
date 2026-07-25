****************************************************************************
** ChibiOS/HAL - EFL/MFS driver demo for M252SD2AE.                       **
****************************************************************************

** TARGET **

NuMaker-M252SD with an M252SD2AE MCU.

** The Demo **

The demo exposes an MFS key-value store through Nu-Link VCOM at 115200 8N1.
Storage occupies APROM `0x0000F000..0x0000FFFF`, split into two 2 KiB banks;
the linker script excludes this range from the application image.

Commands:

- `kvs_put key value` stores a string under key 1..16;
- `kvs_get key` reads a value;
- `kvs_erase key` erases one value;
- `kvs_erase --all` erases the complete store.

Values must survive reset. To test garbage collection and power-loss recovery,
keep one sentinel value, repeatedly replace another value, remove target power
at varying points, then verify both records after restart. A Nu-Link reset is
not a power-loss test if it still powers the target.

** Board Setup **

Connect Nu-Link USB and open VCOM at 115200 8N1 with flow control disabled.

** Build Procedure **

Run `make` in this directory with an Arm GNU Toolchain in PATH.
