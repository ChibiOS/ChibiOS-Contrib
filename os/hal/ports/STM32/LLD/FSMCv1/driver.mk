ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_FSMC_SDRAM TRUE,$(HALCONF)),)
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/FSMCv1/hal_fsmc_sdram_lld.c
endif
ifneq ($(findstring HAL_USE_FSMC_SRAM TRUE,$(HALCONF)),)
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/FSMCv1/hal_fsmc_sram_lld.c
endif
ifneq ($(findstring HAL_USE_FSMC_NAND TRUE,$(HALCONF)),)
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/FSMCv1/hal_fsmc_nand_lld.c
endif
else
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/FSMCv1/hal_fsmc_sram_lld.c  \
                       ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/FSMCv1/hal_fsmc_sdram_lld.c \
                       ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/FSMCv1/hal_fsmc_nand_lld.c
endif

PLATFORMINC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/FSMCv1
