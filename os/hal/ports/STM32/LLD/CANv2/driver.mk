ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_CAN TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/STM32/LLD/CANv2/hal_can_lld.c
endif
else
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/STM32/LLD/CANv2/hal_can_lld.c
endif

PLATFORMINC += $(CHIBIOS_CONTRIB)/os/hal/ports/STM32/LLD/CANv2
