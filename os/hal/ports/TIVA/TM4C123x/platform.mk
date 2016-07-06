# List of all the TM4C123x platform files.
PLATFORMSRC = ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/TM4C123x/hal_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPIO/hal_ext_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPIO/hal_pal_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPTM/hal_gpt_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPTM/hal_st_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/I2C/hal_i2c_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/PWM/hal_pwm_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/SSI/hal_spi_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/UART/hal_serial_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/uDMA/tiva_udma.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/WDT/hal_wdg_lld.c

# Required include directories
PLATFORMINC = ${CHIBIOS}/os/hal/ports/common/ARMCMx \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/TM4C123x \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPIO \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPTM \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/I2C \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/PWM \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/SSI \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/UART \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/uDMA \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/WDT
