include ${CHIBIOS}/os/hal/hal.mk

HALSRC += ${CHIBIOS_CONTRIB}/os/hal/src/hal_community.c \
          ${CHIBIOS_CONTRIB}/os/hal/src/nand.c \
          ${CHIBIOS_CONTRIB}/os/hal/src/onewire.c \
          ${CHIBIOS_CONTRIB}/os/hal/src/eicu.c \
          ${CHIBIOS_CONTRIB}/os/hal/src/crc.c

HALINC += ${CHIBIOS_CONTRIB}/os/hal/include
