PLATFORMSRC_CONTRIB := \
    $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
    $(CHIBIOS_CONTRIB)/os/hal/ports/WCH/CH579/hal_lld.c \
    $(CHIBIOS_CONTRIB)/os/hal/ports/WCH/CH579/hal_pal_lld.c \
    $(CHIBIOS_CONTRIB)/os/hal/ports/WCH/CH579/hal_st_lld.c \
    $(CHIBIOS_CONTRIB)/os/hal/ports/WCH/CH579/hal_usb_lld.c

PLATFORMINC_CONTRIB := \
    $(CHIBIOS_CONTRIB)/os/hal/ports/WCH/CH579 \
    $(CHIBIOS)/os/hal/ports/common/ARMCMx

ALLCSRC += $(PLATFORMSRC_CONTRIB)
ALLINC  += $(PLATFORMINC_CONTRIB)
