# List of all the board related files.
BOARDSRC = $(CHIBIOS_CONTRIB)/os/hal/boards/ES32VF2264/board.c

# Required include directories
BOARDINC = $(CHIBIOS_CONTRIB)/os/hal/boards/ES32VF2264

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)