# M251/M252 M251BSP Vendor Headers

The imported files are from the official M251BSP release **V3.02.009**, commit
[`01ded248c420f27230214582883aa74a46553d81`](https://github.com/OpenNuvoton/M251BSP/commit/01ded248c420f27230214582883aa74a46553d81).

Device-specific CMSIS headers (`M251.h`, `system_M251.h`, `NuMicro.h`,
`*_reg.h`) are taken from:

https://github.com/OpenNuvoton/M251BSP/tree/01ded248c420f27230214582883aa74a46553d81/Library/Device/Nuvoton/M251/Include

## stddriver/

StdDriver peripheral driver API headers are taken from:

https://github.com/OpenNuvoton/M251BSP/tree/01ded248c420f27230214582883aa74a46553d81/Library/StdDriver/inc

They are kept under `stddriver/` so all M251BSP-imported headers live in the
same external vendor tree and remain separate from the ChibiOS HAL port code.

The files under `stddriver/` are retained unchanged. Consumers include the
specific required header through its relocated path, for example
`M251/stddriver/clk.h`; the ChibiOS port does not use the StdDriver functions.

`M251.h` has one documented integration adaptation: its final aggregate
StdDriver include block is commented out. This keeps the CMSIS device header
usable without injecting the complete StdDriver API and avoids collisions
with ChibiOS HAL identifiers. The original include list remains in the file
as a comment for direct comparison with M251BSP.

## License

Licensed under **Apache 2.0** by Nuvoton Technology Corp. See `LICENSE` and
`NOTICE` files in this directory.
