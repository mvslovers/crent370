include ../../config.mk

CFLAGS += -I. -I$(INCLUDE_DIR)

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

A_FILES :=

# Rebuild .s files when clib64.h changes
%.s: %.c $(INCLUDE_DIR)/clib64.h
	@echo "Compile $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

include ../../rules.mk
