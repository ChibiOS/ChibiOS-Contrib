/*
    Copyright (C) 2026 Nicolas
    Modifications copyright (C) 2026 Belonit

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
 * M252SD2AE memory setup for the EFL/MFS demo.
 * The final 4 KiB of APROM is excluded from flash0 and split into two 2 KiB
 * MFS banks.
 */
MEMORY
{
    flash0 (rx) : org = 0x00000000, len = 0xF000        /* APROM minus MFS */
    flash1 (rx) : org = 0x00000000, len = 0             /* Data flash placeholder */
    flash2 (rx) : org = 0x00100000, len = 0x1000        /* LDROM */
    flash3 (rx) : org = 0x00300000, len = 4             /* Config0 */
    flash4 (rx) : org = 0x00300004, len = 4             /* Config1 */
    flash5 (rx) : org = 0x00300008, len = 4             /* Config2 */
    flash6 (rx) : org = 0x00000000, len = 0
    flash7 (rx) : org = 0x00000000, len = 0
    ram0   (wx) : org = 0x20000000, len = 0x3000
    ram1   (wx) : org = 0x00000000, len = 0
    ram2   (wx) : org = 0x00000000, len = 0
    ram3   (wx) : org = 0x00000000, len = 0
    ram4   (wx) : org = 0x00000000, len = 0
    ram5   (wx) : org = 0x00000000, len = 0
    ram6   (wx) : org = 0x00000000, len = 0
    ram7   (wx) : org = 0x00000000, len = 0
}

__mfs_start__ = 0x0000F000;
__mfs_end__ = 0x00010000;

ASSERT(ORIGIN(flash0) + LENGTH(flash0) == __mfs_start__,
       "MFS banks must immediately follow linked APROM")

REGION_ALIAS("CONFIG0", flash3);
REGION_ALIAS("CONFIG1", flash4);
REGION_ALIAS("CONFIG2", flash5);

SECTIONS
{
    .m251_config0 : ALIGN(4)
    {
        KEEP(*(.m251_config0))
    } > CONFIG0

    .m251_config1 : ALIGN(4)
    {
        KEEP(*(.m251_config1))
    } > CONFIG1

    .m251_config2 : ALIGN(4)
    {
        KEEP(*(.m251_config2))
    } > CONFIG2
}

REGION_ALIAS("VECTORS_FLASH", flash0);
REGION_ALIAS("VECTORS_FLASH_LMA", flash0);
REGION_ALIAS("XTORS_FLASH", flash0);
REGION_ALIAS("XTORS_FLASH_LMA", flash0);
REGION_ALIAS("TEXT_FLASH", flash0);
REGION_ALIAS("TEXT_FLASH_LMA", flash0);
REGION_ALIAS("RODATA_FLASH", flash0);
REGION_ALIAS("RODATA_FLASH_LMA", flash0);
REGION_ALIAS("VARIOUS_FLASH", flash0);
REGION_ALIAS("VARIOUS_FLASH_LMA", flash0);
REGION_ALIAS("RAM_INIT_FLASH_LMA", flash0);
REGION_ALIAS("MAIN_STACK_RAM", ram0);
REGION_ALIAS("PROCESS_STACK_RAM", ram0);
REGION_ALIAS("DATA_RAM", ram0);
REGION_ALIAS("DATA_RAM_LMA", flash0);
REGION_ALIAS("BSS_RAM", ram0);
REGION_ALIAS("HEAP_RAM", ram0);

INCLUDE rules.ld
