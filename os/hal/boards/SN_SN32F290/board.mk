# List of all the board related files.
BOARDSRC = $(CHIBIOS_CONTRIB)/os/hal/boards/SN_SN32F290/board.c

# Required include directories
BOARDINC = $(CHIBIOS_CONTRIB)/os/hal/boards/SN_SN32F290

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)