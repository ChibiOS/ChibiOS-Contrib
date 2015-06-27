include ${CHIBIOS}/os/hal/hal.mk

HALSRC += ${CHIBIOS}/community/os/hal/src/hal_community.c \
          ${CHIBIOS}/community/os/hal/src/nand.c \
          ${CHIBIOS}/community/os/hal/src/onewire.c \
          ${CHIBIOS}/community/os/hal/src/eicu.c

HALINC += ${CHIBIOS}/community/os/hal/include
