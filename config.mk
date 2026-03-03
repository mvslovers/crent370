# Root of the repository (auto-detected)
ROOT_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

# Load personalizable settings from .env
-include $(ROOT_DIR).env

export MVS_HOST MVS_PORT MVS_USER MVS_PASS
export MVS_JOBCLASS MVS_MSGCLASS
export CRENT_MACLIB CRENT_SYS2_MACLIB CRENT_PUNCH CRENT_SYSLMOD

# Tools path (mvsasm etc.)
export PATH := $(ROOT_DIR)scripts:$(PATH)

# Cross-compiler
CC       := c2asm370
CFLAGS   := -fverbose-asm -S -O1

# Include paths
INC_DIR  := $(ROOT_DIR)include

# Map .env variables to mvsasm exports
export MAC1=$(CRENT_MACLIB)
export MAC2=$(CRENT_SYS2_MACLIB)
export MVSASM_PUNCH=$(CRENT_PUNCH)
export MVSASM_SYSLMOD=$(CRENT_SYSLMOD)

# Keep generated JCL files for debugging (set to 1 to enable)
# export MVSASM_KEEP_JCL := 1

# Warning collection file
export BUILD_WARNINGS := $(ROOT_DIR).build-warnings
