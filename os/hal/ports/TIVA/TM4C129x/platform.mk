# List of all the TM4C129x platform files.
PLATFORMSRC = ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/TM4C129x/hal_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/st_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/pal_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/serial_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/mac_lld.c \
              ${CHISIOS_CONTRIB}/os/hal/ports/TIVA/LLD/ext_lld.c

# Required include directories
PLATFORMINC = ${CHIBIOS}/os/hal/ports/common/ARMCMx \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/TM4C129x \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD
