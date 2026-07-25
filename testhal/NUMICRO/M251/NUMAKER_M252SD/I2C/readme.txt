****************************************************************************
** ChibiOS/HAL - dual-controller I2C test for M252SD2AE.                  **
****************************************************************************

** TARGET **

NuMaker-M252SD with an M252SD2AE MCU, one SSD1306 OLED and one LCD1602 with a
standard PCF8574 backpack. Both displays are required and use separate I2C
controllers:

- I2C0: 128x64, PB.4/A3 SDA and PB.5/A2 SCL;
- I2C1: LCD1602, PB.0/A4 SDA and PB.1/A5 SCL.

** The Test **

I2C0 runs at 400 kHz and displays a scrolling logo. I2C1 runs at 100 kHz,
probes the PCF8574 backpack at `0x27` and `0x3F`, and displays a live counter.
PB.14 blinks throughout. A failed transfer triggers local bus recovery and
retry; a fault on one bus must not stop the other display or PB.14. The test
explicitly enables `M251_I2C_USE_HW_TIMEOUT` for stalled-bus recovery.

** Board Setup **

Disconnect power before wiring.

- I2C0 OLED: GND to board GND, VCC to 3.3 V, SCL to A2/PB.5, SDA to A3/PB.4.
- I2C1 LCD1602: GND to board GND, VCC to 5 V, SCL to A5/PB.1, SDA to
  A4/PB.0.

PB.0 and PB.1 are 5 V-tolerant when used as I2C open-drain pins, therefore a
PCF8574 backpack powered from 5 V can be connected directly without a level
shifter. Adjust the backpack contrast potentiometer after power-up.

The LCD1602 backpack must use the common PCF8574-to-HD44780 mapping:

- P0: RS;
- P1: R/W;
- P2: Enable;
- P3: backlight control;
- P4-P7: D4-D7.

The firmware probes only the seven-bit addresses `0x27` and `0x3F`. Configure
the backpack A0-A2 address straps for one of those addresses and verify the
result if the module documentation uses a different default. Other PCF8574
addresses and backpacks with a different signal mapping are not supported by
this test.

Do not use the dedicated Arduino SDA/SCL pins (PC.0/PC.1): they are not used
by this test. Pull the I2C0 OLED bus up to 3.3 V. The I2C1 LCD1602 backpack can
pull its bus up to its 5 V supply. If a module has no pull-ups, use
approximately 2.2-4.7 kOhm, chosen for the bus capacitance and clock rate.

** Expected Result **

The OLED shows a clean, continuously moving image. The LCD1602 shows
`ChibiOS M252` and an incrementing `I2C1 count` value. PB.14 keeps blinking.
After reset, power cycle, or a brief disconnection of one display's SDA, SCL,
VCC, or GND, the affected display must recover without stopping the other
display or the LED. Do not short signals or supplies to GND to simulate a
disconnected wire.

An alternate dual-SSD1306 configuration is available by building with
`I2C1_DISPLAY=SSD1306`. In that mode I2C1 expects a 128x32 SSD1306 at `0x3C` and
runs at 400 kHz.

** Build Procedure **

Run `make` in this directory with an Arm GNU Toolchain in PATH. The default
build uses the LCD1602 configuration and writes `build/lcd1602/i2c.bin` and
`build/lcd1602/i2c.hex`. The alternate build writes
`build/ssd1306/i2c.bin` and `build/ssd1306/i2c.hex`:

```
make I2C1_DISPLAY=SSD1306
```

The separate build and dependency directories make it safe to switch variants
without running `make clean`.
