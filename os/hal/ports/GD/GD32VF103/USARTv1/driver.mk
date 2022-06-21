ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_SERIAL TRUE,$(HALCONF)),)
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/USARTv1/hal_serial_lld.c
endif
ifneq ($(findstring HAL_USE_UART TRUE,$(HALCONF)),)
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/USARTv1/hal_uart_lld.c
endif
else
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/USARTv1/hal_serial_lld.c
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/USARTv1/hal_uart_lld.c
endif

PLATFORMINC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/USARTv1
