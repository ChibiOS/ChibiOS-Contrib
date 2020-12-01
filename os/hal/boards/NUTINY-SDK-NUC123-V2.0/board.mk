# List of all the board related files.
BOARDSRC = $(CHIBIOS_CONTRIB)/os/hal/boards/NUTINY-SDK-NUC123-V2.0/board.c

# Required include directories
BOARDINC = $(CHIBIOS_CONTRIB)/os/hal/boards/NUTINY-SDK-NUC123-V2.0

# Define linker script file here, as the linker script is per chip variant, which should 
# remain constant per board
LDSCRIPT = $(STARTUPLD_CONTRIB)/NUC123SD4AN0.ld

ALLCSRC += $(BOARDSRC)
ALLINC += $(BOARDINC)
