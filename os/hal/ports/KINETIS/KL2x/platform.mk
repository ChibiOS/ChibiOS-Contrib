# List of all platform files.
PLATFORMSRC = ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/KINETIS/KL2x/hal_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/KINETIS/LLD/pal_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/KINETIS/LLD/serial_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/KINETIS/LLD/i2c_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/KINETIS/LLD/ext_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/KINETIS/LLD/adc_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/KINETIS/LLD/gpt_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/KINETIS/KL2x/pwm_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/KINETIS/LLD/st_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/KINETIS/LLD/usb_lld.c

# Required include directories
PLATFORMINC = ${CHIBIOS}/os/hal/ports/common/ARMCMx \
              ${CHIBIOS_CONTRIB}/os/hal/ports/KINETIS/KL2x \
              ${CHIBIOS_CONTRIB}/os/hal/ports/KINETIS/LLD
