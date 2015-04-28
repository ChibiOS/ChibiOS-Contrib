# List of all the TM4C129x platform files.
PLATFORMSRC = ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c \
              ${CHIBIOS}/community/os/hal/ports/TIVA/TM4C129x/hal_lld.c \
              ${CHIBIOS}/community/os/hal/ports/TIVA/LLD/st_lld.c \
              ${CHIBIOS}/community/os/hal/ports/TIVA/LLD/pal_lld.c \
              ${CHIBIOS}/community/os/hal/ports/TIVA/LLD/serial_lld.c \
              ${CHIBIOS}/community/os/hal/ports/TIVA/LLD/mac_lld.c \
              ${CHISIOS}/community/os/hal/ports/TIVA/LLD/ext_lld.c

# Required include directories
PLATFORMINC = ${CHIBIOS}/os/hal/ports/common/ARMCMx \
              ${CHIBIOS}/community/os/hal/ports/TIVA/TM4C129x \
              ${CHIBIOS}/community/os/hal/ports/TIVA/LLD
