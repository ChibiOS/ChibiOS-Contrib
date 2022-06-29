ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_RTC TRUE,$(HALCONF)),)
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/RTCv1/hal_rtc_lld.c
endif
else
PLATFORMSRC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/RTCv1/hal_rtc_lld.c
endif

PLATFORMINC_CONTRIB += ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/RTCv1
