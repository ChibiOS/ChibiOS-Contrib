ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_CRC TRUE,$(HALCONF)),)
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/CRCv1/hal_crc_lld.c \
               ${CHIBIOS_CONTRIB}/os/various/crcsw.c
endif
else
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/CRCv1/hal_crc_lld.c \
               ${CHIBIOS_CONTRIB}/os/various/crcsw.c
endif

PLATFORMINC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/CRCv1
