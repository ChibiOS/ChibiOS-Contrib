ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_I2C TRUE,$(HALCONF)),)
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/SAM/LLD/SERCOMv1/hal_i2c_lld.c
endif
ifneq ($(findstring HAL_USE_SPI TRUE,$(HALCONF)),)
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/SAM/LLD/SERCOMv1/hal_spi_v2_lld.c
endif
ifneq ($(findstring HAL_USE_SIO TRUE,$(HALCONF)),)
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/SAM/LLD/SERCOMv1/hal_sio_lld.c
endif
else
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/SAM/LLD/SERCOMv1/hal_i2c_lld.c
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/SAM/LLD/SERCOMv1/hal_spi_v2_lld.c
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/SAM/LLD/SERCOMv1/hal_sio_lld.c
endif

PLATFORMINC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/SAM/LLD/SERCOMv1
