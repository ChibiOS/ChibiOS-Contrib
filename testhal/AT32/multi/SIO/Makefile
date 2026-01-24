##############################################################################
# Multi-project makefile rules
#

all:
	@echo
	@echo === Building for AT-START-F402 =====================================
	+@make --no-print-directory -f ./make/at-start-f402.make all
	@echo ====================================================================
	@echo
	@echo === Building for AT-START-F405 =====================================
	+@make --no-print-directory -f ./make/at-start-f405.make all
	@echo ====================================================================
	@echo

clean:
	@echo
	+@make --no-print-directory -f ./make/at-start-f402.make clean
	@echo
	+@make --no-print-directory -f ./make/at-start-f405.make clean
	@echo

#
##############################################################################
