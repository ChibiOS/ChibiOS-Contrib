include ${CHIBIOS}/os/hal/ports/STM32/STM32F0xx/platform.mk

PLATFORMSRC += ${CHIBIOS}/community/os/hal/ports/STM32/LLD/CRCv1/crc_lld.c

PLATFORMINC += ${CHIBIOS}/community/os/hal/ports/STM32/LLD/CRCv1 \
               ${CHIBIOS}/community/os/hal/ports/STM32/LLD
