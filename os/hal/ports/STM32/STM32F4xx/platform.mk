include ${CHIBIOS}/os/hal/ports/STM32/STM32F4xx/platform.mk

PLATFORMSRC += ${CHIBIOS}/os/hal/ports/STM32/LLD/FSMCv1/fsmc.c \
               ${CHIBIOS}/os/hal/ports/STM32/LLD/FSMCv1/nand_lld.c \
               ${CHIBIOS}/os/hal/ports/STM32/LLD/FSMCv1/fsmc_sram.c

PLATFORMINC += ${CHIBIOS}/os/hal/ports/STM32/LLD/FSMCv1
