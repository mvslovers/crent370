#
# makefile for IPC c files
#
# Location of IPC headers and source
TOP  := /home/projects/crent370
SRC  := $(TOP)/ipc
HDR  := $(TOP)/include
# includes
INCS  = -I.
INCS += -I$(HDR)
# dependencies
DEPS  = $(HDR)/ipc.h
DEPS += $(HDR)/ipci.h
# compiler command line
CFLAGS := -fverbose-asm -S -O1 $(INCS)
#
# C files
C_FILES := \
    @@iccap.c \
	@@icchp.c \
    @@icfch.c \
    @@icfms.c \
    @@icnw.c

#deprecated:

# non-generated .asm assembler source files 
A_FILES := 

# generated .s assembler source files (one for each source file)
S_FILES := $(foreach filename,$(C_FILES),$(filename:.c=.s))

# object files (one for each .c and .asm source file)
O_FILES := $(foreach filename,$(C_FILES),$(filename:.c=.o)) \
           $(foreach filename,$(A_FILES),$(filename:.asm=.o))

# export MACn variables for mvsasm->jobasm script
export MAC1=MDR.CRENT370.MACLIB

# export dataset names used by mvsasm script
export MVSASM_PUNCH=MDR.CRENT370.OBJECT
export MVSASM_SYSLMOD=MDR.CRENT370.NCALIB

all: $(S_FILES) $(O_FILES)
	@echo "Done"
# Note: PHONY is important here. Without it, implicit rules will try
#       to build the executable "all", since the prereqs are ".o" files.
.PHONY: all 

# build object files from the generated assembler files (.s)
%.o: %.s
	@echo "mvsasm $(notdir $<)"
	@mvsasm "$<"
	@touch "$@"

# build object files from assembler files (.asm)
%.o: %.asm
	@echo "mvsasm $(notdir $<)"
	@mvsasm "$<"
	@touch "$@"

# compile C source files (.c) into assembler files (.s)
%.s: %.c $(DEPS)
	@echo "Compile $(notdir $<)"
	c2asm370 $(CFLAGS) -c $< -o $@

# remove generated files
clean:
	@rm -f $(S_FILES) $(O_FILES)

