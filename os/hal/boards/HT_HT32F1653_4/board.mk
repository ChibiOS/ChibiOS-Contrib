# List of all the board related files.
BOARDSRC = $(CHIBIOS_CONTRIB)/os/hal/boards/HT_HT32F1653_4/board.c

# Required include directories
BOARDINC = $(CHIBIOS_CONTRIB)/os/hal/boards/HT_HT32F1653_4

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
