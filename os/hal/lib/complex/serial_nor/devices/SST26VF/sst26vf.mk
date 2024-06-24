# List of all sst26vf device files.
SNORSRC := $(CHIBIOS)/os/hal/lib/complex/serial_nor/hal_serial_nor.c \
           $(CHIBIOS_CONTRIB)/os/hal/lib/complex/serial_nor/devices/SST26VF/hal_flash_device.c

# Required include directories
SNORINC := $(CHIBIOS)/os/hal/lib/complex/serial_nor \
           $(CHIBIOS_CONTRIB)/os/hal/lib/complex/serial_nor/devices/SST26VF

# Shared variables
ALLCSRC += $(SNORSRC)
ALLINC  += $(SNORINC)