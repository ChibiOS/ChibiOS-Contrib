# List of all the TM4C129x platform files.
ifeq ($(USE_SMART_BUILD),yes)
HALCONF := $(strip $(shell cat halconf.h | egrep -e "\#define"))

PLATFORMSRC := $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/TM4C129x/hal_lld.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/uDMA/tiva_udma.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPTM/hal_st_lld.c
ifneq ($(findstring HAL_USE_EXT TRUE,$(HALCONF)),)
PLATFORMSRC += ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPIO/hal_ext_lld.c
endif
ifneq ($(findstring HAL_USE_PAL TRUE,$(HALCONF)),)
PLATFORMSRC += ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPIO/hal_pal_lld.c
endif
ifneq ($(findstring HAL_USE_I2C TRUE,$(HALCONF)),)
PLATFORMSRC += ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/I2C/hal_i2c_lld.c
endif
ifneq ($(findstring HAL_USE_MAC TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/TIVA/LLD/MAC/hal_mac_lld.c
endif
ifneq ($(findstring HAL_USE_SPI TRUE,$(HALCONF)),)
PLATFORMSRC += ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/SSI/hal_spi_lld.c
endif
ifneq ($(findstring HAL_USE_GPT TRUE,$(HALCONF)),)
PLATFORMSRC += ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPTM/hal_gpt_lld.c
endif
ifneq ($(findstring HAL_USE_PWM TRUE,$(HALCONF)),)
PLATFORMSRC += ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/PWM/hal_pwm_lld.c
endif
ifneq ($(findstring HAL_USE_SERIAL TRUE,$(HALCONF)),)
PLATFORMSRC += ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/UART/hal_serial_lld.c
endif
ifneq ($(findstring HAL_USE_WDG TRUE,$(HALCONF)),)
PLATFORMSRC += ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/WDT/hal_wdg_lld.c
endif
else
PLATFORMSRC := ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/TM4C129x/hal_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPIO/hal_ext_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPIO/hal_pal_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPTM/hal_gpt_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPTM/hal_st_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/I2C/hal_i2c_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/MAC/hal_mac_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/PWM/hal_pwm_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/SSI/hal_spi_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/UART/hal_serial_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/uDMA/tiva_udma.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/WDT/hal_wdg_lld.c
endif

# Required include directories
PLATFORMINC := ${CHIBIOS}/os/hal/ports/common/ARMCMx \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/TM4C129x \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPIO \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/GPTM \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/I2C \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/MAC \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/PWM \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/SSI \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/UART \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/uDMA \
              ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/LLD/WDT
