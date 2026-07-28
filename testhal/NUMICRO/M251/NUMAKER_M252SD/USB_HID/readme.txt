****************************************************************************
** ChibiOS/HAL - USB HID test for M252SD2AE.                              **
****************************************************************************

** TARGET **

NuMaker-M252SD with an M252SD2AE MCU.

** The Test **

The application enumerates as vendor-defined HID `1209:0003` with one-byte IN
and OUT reports. It sends an incrementing byte every 10 ms and accepts one-byte
output reports. PB.14 blinks at 1 Hz before USB configuration and at 2 Hz once
configured.

** Board Setup **

Connect the NuMaker Device USB connector to the host. Nu-Link may remain
connected for power and programming.

On Linux, build and run the shared NUC123 client:

    cd ../../../NUC123/NUTINY-SDK-NUC123-V2.0/USB_HID/Client/linux
    make
    ./test-usb-hid /dev/hidrawX

The client must receive incrementing one-byte reports and exchange OUT data.
Repeat after reconnect and host suspend/resume; resolve `/dev/hidrawX` again
after every reconnect.

** Build Procedure **

Run `make` in this directory with an Arm GNU Toolchain in PATH.
