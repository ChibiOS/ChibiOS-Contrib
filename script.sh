#!/bin/sh

set -ex

export PATH=/tmp/gcc-arm-none-eabi-4_9-2015q3/bin:$PATH

git checkout -- .
git clean -xfd
make -C demos/TIVA/RT-TM4C123G-LAUNCHPAD

git checkout -- .
git clean -xfd
make -C demos/TIVA/RT-TM4C1294-LAUNCHPAD

# This demo needs LWIP, it is disabled for now.
# git checkout -- .
# git clean -xfd
# make -C demos/TIVA/RT-TM4C1294-LAUNCHPAD-LWIP

git checkout -- .
git clean -xfd
make -C testhal/TIVA/TM4C123x/EXT/

git checkout -- .
git clean -xfd
make -C testhal/TIVA/TM4C123x/GPT

git checkout -- .
git clean -xfd
make -C testhal/TIVA/TM4C123x/I2C

git checkout -- .
git clean -xfd
make -C testhal/TIVA/TM4C123x/PWM

git checkout -- .
git clean -xfd
make -C testhal/TIVA/TM4C123x/SPI

git checkout -- .
git clean -xfd
make -C testhal/TIVA/TM4C123x/WDG
