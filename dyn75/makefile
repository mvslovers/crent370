#
# makefile for crent370/dyn75 c files
#
# gccmvs compiler flags
INC1 := -I.
INC2 := -I/home/mike/repos/crent370/dyn75
INC3 := -I/home/mike/repos/crent370/include
CC := c2asm370
CFLAGS := -fverbose-asm -S -O1 $(INC1) $(INC2) $(INC3)
#CFLAGS := -S $(INC1) $(INC2) $(INC3)
#
# c source code files
C_FILES := \
    @@75.c \
    @@75acce.c \
    @@75bind.c \
    @@75clos.c \
    @@75conn.c \
    @@75exit.c \
    @@75gabn.c \
    @@75ghba.c \
    @@75ghbn.c \
    @@75init.c \
    @@75ioct.c \
    @@75list.c \
    @@75pnam.c \
    @@75recv.c \
    @@75sele.c \
    @@75selx.c \
    @@75send.c \
    @@75snam.c \
    @@75sock.c \
    @@75vect.c \
    asc2ebc.c \
    ebc2asc.c

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
%.s: %.c
	@echo "Compile $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

# remove generated files
clean:
	@rm -f $(S_FILES) $(O_FILES)
