GDB               ?= arm-none-eabi-gdb
GDB_PROGRAM       ?= $(BUILDDIR)/$(PROJECT).elf
GDB_PORT          ?= 2331
GDB_START_ADDRESS ?= 0
GDB_BREAK         ?= main
GDB_ARGS          ?=

gdb-debug:
	printf "target remote localhost:$(GDB_PORT)\nmem $(GDB_START_ADDRESS) 0\nbreak $(GDB_BREAK)\nload\nmon reset\ncontinue" > .gdbinit
	$(GDB) $(GDB_ARGS) --command=.gdbinit $(GDB_PROGRAM)



.PHONY: gdb-debug
