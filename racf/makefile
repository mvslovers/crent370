#
# makefile for crent370/racf c files
#
# gccmvs compiler flags
INC1 := -I.
INC2 := -I/home/mike/repos/crent370/racf
INC3 := -I/home/mike/repos/crent370/include
CFLAGS := -S -O1 $(INC1) $(INC2) $(INC3)
#
# c source code files
C_FILES := racauth.c \
	racgacee.c \
	raclgout.c \
	raclogin.c \
	racsacee.c

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
%.s: %.c
	@echo "Compile $(notdir $<)"
	c2asm370 $(CFLAGS) -c $< -o $@

# remove generated files
clean:
	@rm -f $(S_FILES) $(O_FILES)

