include ${CHIBIOS}/os/hal/ports/STM32/STM32F4xx/platform.mk

PLATFORMSRC += ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/DMA2Dv1/stm32_dma2d.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/FSMCv1/fsmc.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/FSMCv1/nand_lld.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/FSMCv1/fsmc_sram.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/LTDCv1/stm32_ltdc.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/TIMv1/eicu_lld.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/TIMv1/timcap_lld.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/USBHv1/usbh_lld.c \
               ${CHIBIOS_CONTRIB}/os/hal/src/fsmc_sdram.c \
               ${CHIBIOS_CONTRIB}/os/hal/src/usbh.c \
               ${CHIBIOS_CONTRIB}/os/hal/src/usbh/usbh_debug.c \
               ${CHIBIOS_CONTRIB}/os/hal/src/usbh/usbh_desciter.c \
               ${CHIBIOS_CONTRIB}/os/hal/src/usbh/usbh_hub.c \
               ${CHIBIOS_CONTRIB}/os/hal/src/usbh/usbh_msd.c \
               ${CHIBIOS_CONTRIB}/os/hal/src/usbh/usbh_ftdi.c \
               ${CHIBIOS_CONTRIB}/os/hal/src/usbh/usbh_uvc.c 

PLATFORMINC += ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/DMA2Dv1 \
               ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/FSMCv1 \
               ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/LTDCv1 \
               ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/TIMv1 \
               ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD/USBHv1 \
               ${CHIBIOS_CONTRIB}/os/hal/ports/STM32/LLD
