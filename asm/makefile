#
# makefile for crent370/asm  (asm files)
#
# asm source code files
A_FILES := @@aclose.asm \
	@@aline.asm \
	@@anote.asm \
	@@aopen.asm \
	@@apoint.asm \
	@@aread.asm \
	@@atrout.asm \
	@@awrite.asm \
	@@crt0.asm \
	@@crt1.asm \
	@@crtm.asm \
	@@crtsvc.asm \
	dummy.asm \
	@@dynal.asm \
	@@exita.asm \
	@@freem.asm \
	@@getclk.asm \
	@@getm.asm \
	@@getpfx.asm \
	@@gettz.asm \
	gettzoff.asm \
	@@idcams.asm \
	@@longj.asm \
	@@ppaget.asm \
	@@setj.asm \
	@@ssctbn.asm \
	@@svc99.asm \
	@@system.asm 

#deprecated:

# object files (one for each .asm source file)
O_FILES := $(foreach filename,$(A_FILES),$(filename:.asm=.o))

# export MACn variables for mvsasm->jobasm script
export MAC1=FIX0MIG.CRENT370.MACLIB
export MAC2=SYS2.MACLIB

# export dataset names used by mvsasm script
export MVSASM_PUNCH=FIX0MIG.CRENT370.OBJECT
export MVSASM_SYSLMOD=FIX0MIG.CRENT370.NCALIB

all: $(O_FILES)
	@echo "Done"
# Note: PHONY is important here. Without it, implicit rules will try
#       to build the executable "all", since the prereqs are ".o" files.
.PHONY: all 

# build object files from assembler files (.asm)
%.o: %.asm
	@echo "mvsasm $(notdir $<)"
	@mvsasm "$<"
	@touch "$@"

# remove generated files
clean:
	@rm -f $(O_FILES)

