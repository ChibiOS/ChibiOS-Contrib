# List of all the NRF51x platform files.
PLATFORMSRC = ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/NRF51/NRF51822/hal_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/NRF51/NRF51822/pal_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/NRF51/NRF51822/serial_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/NRF51/NRF51822/st_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/NRF51/NRF51822/spi_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/NRF51/NRF51822/ext_lld_isr.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/NRF51/NRF51822/ext_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/NRF51/NRF51822/i2c_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/NRF51/NRF51822/adc_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/NRF51/NRF51822/gpt_lld.c

# Required include directories
PLATFORMINC = ${CHIBIOS}/os/hal/ports/common/ARMCMx \
              ${CHIBIOS_CONTRIB}/os/hal/ports/NRF51/NRF51822
