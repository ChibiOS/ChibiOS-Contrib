# List of all the board related files.
BOARDSRC = $(CHIBIOS_CONTRIB)/os/hal/boards/HT_HT32F52342_52/board.c

# Required include directories
BOARDINC = $(CHIBIOS_CONTRIB)/os/hal/boards/HT_HT32F52342_52

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
