# Root of the repository (auto-detected)
ROOT_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

# Tools path (mvsasm etc.)
export PATH := $(ROOT_DIR)scripts:$(PATH)

# Cross-compiler
CC       := c2asm370 #or classic gccmvs
CFLAGS   := -fverbose-asm -S -O1

# Include paths
INCLUDE_DIR := $(ROOT_DIR)include

# MVS host dataset configuration
export MAC1           := <HQL>.CRENT370.MACLIB
export MAC2           := SYS2.MACLIB
export MVSASM_PUNCH   := <HLQ>.CRENT370.OBJECT
export MVSASM_SYSLMOD := <HLQ>.CRENT370.NCALIB

# JES job classes
export MVSASM_JOBCLASS    := A
export MVSASM_MSGCLASS    := H


# Keep generated JCL files for debugging (set to 1 to enable)
# export MVSASM_KEEP_JCL := 1

# Warning collection file
export BUILD_WARNINGS := $(ROOT_DIR).build-warnings
