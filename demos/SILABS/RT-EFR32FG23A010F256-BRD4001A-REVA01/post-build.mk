POST_MAKE_ALL_RULE_HOOK: print-all-sections

print-all-sections: $(BUILDDIR)/$(PROJECT).elf
	$(SZ) -A -t $<

JLINK_ARGS ?=
JLINK_SCRIPT := $(shell mktemp)
program: $(BUILDDIR)/$(PROJECT).hex
	@echo 'Erase\nLoadFile $<\nReset\nExit\n' >$(JLINK_SCRIPT)
	JLinkExe -NoGui 1 -AutoConnect 1 -Device EFR32FG23AXXXF256 -Speed 4000 -If SWD $(JLINK_ARGS) -CommandFile $(JLINK_SCRIPT)
