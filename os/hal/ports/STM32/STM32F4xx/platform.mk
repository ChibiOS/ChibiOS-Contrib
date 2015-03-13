include ${CHIBIOS}/os/hal/ports/STM32/STM32F4xx/platform.mk

PLATFORMSRC += ${CHIBIOS}/community/os/hal/ports/STM32/LLD/FSMCv1/fsmc.c \
               ${CHIBIOS}/community/os/hal/ports/STM32/LLD/FSMCv1/nand_lld.c \
               ${CHIBIOS}/community/os/hal/ports/STM32/LLD/FSMCv1/fsmc_sram.c \
               ${CHIBIOS}/community/os/hal/ports/STM32/LLD/TIMv1/eicu_lld.c \
               ${CHIBIOS}/community/os/hal/src/fsmc_sdram.c

PLATFORMINC += ${CHIBIOS}/community/os/hal/ports/STM32/LLD/FSMCv1 \
               ${CHIBIOS}/community/os/hal/ports/STM32/LLD/TIMv1 \
               ${CHIBIOS}/community/os/hal/ports/STM32/LLD
