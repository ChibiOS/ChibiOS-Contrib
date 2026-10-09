POST_MAKE_ALL_RULE_HOOK: print-all-sections

print-all-sections: $(BUILDDIR)/$(PROJECT).elf
	$(SZ) -A -t $<

JLINK ?= JLinkExe
JLINK_GDB_SERVER ?= JLinkGDBServerCLExe

JLINK_SPEED ?= 4000
DEVICE_PART = EFR32FG23AXXXF256

#JLINK_ARGS ?= USB 12345678
#JLINK_GDB_SERVER_ARGS ?= -select 12345678
JLINK_ARGS ?=
JLINK_GDB_SERVER_ARGS ?=
JLINK_SCRIPT := $(shell mktemp)
program: $(BUILDDIR)/$(PROJECT).hex
	@echo 'Erase\nLoadFile $<\nReset\nExit\n' >$(JLINK_SCRIPT)
	$(JLINK) -NoGui 1 -AutoConnect 1 -Device $(DEVICE_PART) -Speed $(JLINK_SPEED) -If SWD $(JLINK_ARGS) -CommandFile $(JLINK_SCRIPT)

start_gdb: $(BUILDDIR)/$(PROJECT).hex
	$(JLINK_GDB_SERVER) -Device $(DEVICE_PART) -Speed $(JLINK_SPEED) -If SWD $(JLINK_ARGS) -localhostonly
