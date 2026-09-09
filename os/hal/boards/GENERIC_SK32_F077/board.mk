# List of all the board related files.
BOARDSRC = $(CHIBIOS_CONTRIB)/os/hal/boards/GENERIC_SK32_F077/board.c

# Required include directories
BOARDINC = $(CHIBIOS_CONTRIB)/os/hal/boards/GENERIC_SK32_F077

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
