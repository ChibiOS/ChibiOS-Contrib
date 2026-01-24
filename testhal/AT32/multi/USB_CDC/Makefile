##############################################################################
# Multi-project makefile rules
#

all:
	@echo
	@echo === Building for AT-START-F402 =====================================
	+@make --no-print-directory -f ./make/at-start-f402.make all
	@echo ====================================================================
	@echo
	@echo === Building for AT-START-F405_USBFS ===============================
	+@make --no-print-directory -f ./make/at-start-f405_usbfs.make all
	@echo ====================================================================
	@echo
	@echo === Building for AT-START-F405_USBHS ===============================
	+@make --no-print-directory -f ./make/at-start-f405_usbhs.make all
	@echo ====================================================================
	@echo
	@echo === Building for AT-START-F405_USBHS-DMA ===========================
	+@make --no-print-directory -f ./make/at-start-f405_usbhs-dma.make all
	@echo ====================================================================
	@echo
	@echo === Building for AT-START-F415 =====================================
	+@make --no-print-directory -f ./make/at-start-f415.make all
	@echo ====================================================================
	@echo

clean:
	@echo
	+@make --no-print-directory -f ./make/at-start-f402.make clean
	@echo
	+@make --no-print-directory -f ./make/at-start-f405_usbfs.make clean
	@echo
	+@make --no-print-directory -f ./make/at-start-f405_usbhs.make clean
	@echo
	+@make --no-print-directory -f ./make/at-start-f405_usbhs-dma.make clean
	@echo
	+@make --no-print-directory -f ./make/at-start-f415.make clean
	@echo

#
##############################################################################
