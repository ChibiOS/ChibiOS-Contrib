# List of all the board related files.
BOARDSRC = ${CHIBIOS_CONTRIB}/os/hal/boards/SILABS_EFR32FG23_DK2600A/board.c

# Required include directories
BOARDINC = ${CHIBIOS_CONTRIB}/os/hal/boards/SILABS_EFR32FG23_DK2600A

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
