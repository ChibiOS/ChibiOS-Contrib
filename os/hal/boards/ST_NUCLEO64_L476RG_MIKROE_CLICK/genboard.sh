#!/bin/sh

fmpp -C cfg/board.fmpp

sed -i 's/$(CHIBIOS)/$(CHIBIOS_CONTRIB)/g' board.mk
