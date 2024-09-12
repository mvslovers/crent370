#
# makefile for crent370/time64 c files
#
# gccmvs compiler flags
INC1 := -I.
INC2 := -I/home/mike/repos/crent370/time64
INC3 := -I/home/mike/repos/crent370/include
DEPS := /home/mike/repos/crent370/include/clib64.h
CFLAGS := -fverbose-asm -S -O1 $(INC1) $(INC2) $(INC3)
#CFLAGS := -S $(INC1) $(INC2) $(INC3)
#
# c source code files
C_FILES := tm64asc.c \
	tm64ascr.c \
	tm64clck.c \
	tm64cti.c \
	tm64ctir.c \
	tm64dtim.c \
	tm64time.c \
	tm64tgm.c \
	tm64dim.c \
	tm64jdbm.c \
	tm64ltm.c \
	tm64ltmr.c \
	tm64mclk.c \
	tm64mcti.c \
	tm64mgmt.c \
	tm64mkt.c \
	tm64mltm.c \
	tm64mtim.c \
	tm64gmt.c \
	tm64gmtr.c \
	tm64syr.c \
	tm64sby.c \
	tm64test.c \
	tm64uclk.c \
	tm64utim.c \
	tm64ucti.c \
	tm64ultm.c \
	tm64ugmt.c

#deprecated:

# non-generated .asm assembler source files 
A_FILES := 

# generated .s assembler source files (one for each source file)
S_FILES := $(foreach filename,$(C_FILES),$(filename:.c=.s))

# object files (one for each .c and .asm source file)
O_FILES := $(foreach filename,$(C_FILES),$(filename:.c=.o)) \
           $(foreach filename,$(A_FILES),$(filename:.asm=.o))

# export MACn variables for mvsasm->jobasm script
export MAC1=FIX0MIG.CRENT370.MACLIB

# export dataset names used by mvsasm script
export MVSASM_PUNCH=FIX0MIG.CRENT370.OBJECT
export MVSASM_SYSLMOD=FIX0MIG.CRENT370.NCALIB

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

