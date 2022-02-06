##
##  make targets for the Black Magic Probe
##    See: https://github.com/blacksphere/blackmagic (Black Magic)
##    See: https://github.com/blacksphere/blackmagic/wiki/Frequently-Asked-Questions (Black Magic udev rules)
##
##  Provides the following targets:
##
##  all:        Wrapper for the elf binary
##  flash:      Uses GDB to flash the target via Black Magic
##  debug:      Flashes the target and allows for debugging using gdb and Black Magic
##  debug-tui:  Flashes the target and allows for debugging using gdb's TUI and Black Magic
##

GDB               ?= arm-none-eabi-gdb           # Path to the arm-none-eabi-gdb binary
GDB_PROGRAM       ?= $(BUILDDIR)/$(PROJECT).elf  # Path to the elf binary
GDB_BREAK         ?= main                        # Function to break at when starting the debugger

BMP_GDB           ?= /dev/ttyBmpGdb              # Device file for the Black Magic GDB devic

FLASH_MARKER      ?= $(strip $(GDB_PROGRAM)).flash

all: $(GDB_PROGRAM)

$(FLASH_MARKER): $(GDB_PROGRAM)
	$(GDB) $(GDB_PROGRAM) -nx --batch                  \
		-ex 'target extended-remote $(BMP_GDB)'    \
		-ex 'monitor swdp_scan'                    \
		-ex 'attach 1'                             \
		-ex 'load'                                 \
		-ex 'compare-sections'                     \
		-ex 'kill'
	touch $(FLASH_MARKER)

flash: $(FLASH_MARKER)

debug: flash
	$(GDB) $(GDB_PROGRAM) -nx                          \
		-ex 'target extended-remote $(BMP_GDB)'    \
		-ex 'monitor swdp_scan'                    \
		-ex 'attach 1'                             \
		-ex 'compare-sections'			   \
		-ex 'set mem inaccessible-by-default off'  \
		-ex 'break $(GDB_BREAK)'                   \
		-ex 'set confirm off'                      \
		-ex 'run'                                  \
		-ex 'set confirm off'                      \
		-ex 'set pagination on'

debug-tui: flash
	$(GDB) $(GDB_PROGRAM) -nx                         \
		-ex 'target extended-remote $(BMP_GDB)'   \
		-ex 'monitor swdp_scan'                   \
		-ex 'attach 1'                            \
		-ex 'compare-sections'                    \
		-ex 'set mem inaccessible-by-default off' \
		-ex 'set pagination off'                  \
		-ex 'focus cmd'	                          \
		-ex 'layout src'                          \
		-ex 'break $(GDB_BREAK)'                  \
		-ex 'set confirm off'                     \
		-ex 'run'                                 \
		-ex 'set confirm off'                     \
		-ex 'set pagination on'

.PHONY: all flash debug debug-tui
