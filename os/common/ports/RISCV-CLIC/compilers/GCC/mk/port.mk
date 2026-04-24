# List of the ChibiOS/RT RISCV generic port files.
PORTSRC = $(CHIBIOS_CONTRIB)/os/common/ports/RISCV-CLIC/chcore.c

PORTASM = $(CHIBIOS_CONTRIB)/os/common/ports/RISCV-CLIC/compilers/GCC/chcoreasm.S

PORTINC = $(CHIBIOS_CONTRIB)/os/common/ports/RISCV-CLIC \
          $(CHIBIOS)/os/common/ports/RISCV-CLIC/compilers/GCC

# Shared variables
ALLXASMSRC += $(PORTASM)
ALLCSRC    += $(PORTSRC)
ALLINC     += $(PORTINC)
