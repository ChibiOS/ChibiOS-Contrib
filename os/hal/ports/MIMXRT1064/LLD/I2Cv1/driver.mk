I2CSRC = ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1064/LLD/I2Cv1/hal_i2c_lld.c \
          ${CHIBIOS_CONTRIB}/ext/mcux-sdk/drivers/lpi2c/fsl_lpi2c.c \
          ${CHIBIOS_CONTRIB}/ext/mcux-sdk/devices/MIMXRT1064/drivers/fsl_clock.c

ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_I2C TRUE,$(HALCONF)),)
PLATFORMSRC_CONTRIB += $(I2CSRC)
endif
else
PLATFORMSRC_CONTRIB += $(I2CSRC)
endif

PLATFORMINC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1064/LLD/I2Cv1 \
                       ${CHIBIOS_CONTRIB}/ext/mcux-sdk/drivers/common \
                       ${CHIBIOS_CONTRIB}/ext/mcux-sdk/drivers/lpi2c \
                       ${CHIBIOS_CONTRIB}/ext/mcux-sdk/devices/MIMXRT1064
