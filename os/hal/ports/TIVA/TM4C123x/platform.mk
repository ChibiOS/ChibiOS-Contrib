# List of all the TM4C123x platform files.
PLATFORMSRC = ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/TM4C123x/hal_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/st_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/pal_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/serial_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/i2c_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/gpt_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/pwm_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/spi_lld.c \
              ${CHISIOS_CONTRIB}/os/hal/ports/TIVA/LLD/tiva_udma.c \
              ${CHISIOS_CONTRIB}/os/hal/ports/TIVA/LLD/ext_lld.c

# Required include directories
PLATFORMINC = ${CHIBIOS}/os/hal/ports/common/ARMCMx \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/TM4C123x \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD
