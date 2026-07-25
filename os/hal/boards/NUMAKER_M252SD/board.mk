# List of all the board related files.
BOARDSRC = $(CHIBIOS_CONTRIB)/os/hal/boards/NUMAKER_M252SD/board.c

# Required include directories.
BOARDINC = $(CHIBIOS_CONTRIB)/os/hal/boards/NUMAKER_M252SD

# Shared variables.
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
