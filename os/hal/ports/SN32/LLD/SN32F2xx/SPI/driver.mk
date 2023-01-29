ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_SPI TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SN32/LLD/SN32F2xx/SPI/hal_pal_v2_lld.c
endif
else
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SN32/LLD/SN32F2xx/SPI/hal_spi_v2_lld.c
endif

PLATFORMINC += $(CHIBIOS_CONTRIB)/os/hal/ports/SN32/LLD/SN32F2xx/SPI
