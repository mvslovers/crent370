# Derived file lists
S_FILES := $(C_FILES:.c=.s)
O_FILES := $(C_FILES:.c=.o) $(A_FILES:.asm=.o)

all: $(S_FILES) $(O_FILES)
	@if [ -s "$(BUILD_WARNINGS)" ]; then \
	  echo ""; \
	  echo "=== Assembly Warnings ==="; \
	  printf "%-10s %-10s %s\n" "MODULE" "JOBID" "STATUS"; \
	  printf "%-10s %-10s %s\n" "------" "------" "------"; \
	  cat "$(BUILD_WARNINGS)"; \
	  echo ""; \
	fi
	@echo "Done"
.PHONY: all clean

%.o: %.s
	@echo "mvsasm $(notdir $<)"
	@mvsasm "$<"
	@touch "$@"

%.o: %.asm
	@echo "mvsasm $(notdir $<)"
	@mvsasm "$<"
	@touch "$@"

%.s: %.c
	@echo "Compile $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(S_FILES) $(O_FILES) *.jcl
	@rm -f $(BUILD_WARNINGS)
