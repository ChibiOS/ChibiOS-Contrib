ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_PAL TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SN32/LLD/SN32F24x/GPIO/hal_pal_lld.c
endif
else
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SN32/LLD/SN32F24x/GPIO/hal_pal_lld.c
endif

PLATFORMINC += $(CHIBIOS_CONTRIB)/os/hal/ports/SN32/LLD/SN32F24x/GPIO