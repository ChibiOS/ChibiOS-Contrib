POST_MAKE_ALL_RULE_HOOK: print-all-sections

print-all-sections: $(BUILDDIR)/$(PROJECT).elf
	$(SZ) -A -t $<