include config.mk

MODULES := asm src/clib src/cmtt src/crypto src/dyn75 src/jes src/os src/racf src/thdmgr src/time64

include bootstrap.mk

all:
	@rm -f .build-warnings
	@for dir in $(MODULES); do $(MAKE) -C $$dir $@ || exit 1; done

clean:
	@for dir in $(MODULES); do $(MAKE) -C $$dir $@; done
	@rm -f .build-warnings
	@rm -f compile_commands.json

# link-edit (stub — not yet implemented for crent370)
link:
	@echo "link: not yet implemented for crent370"

# install (stub — not yet implemented for crent370)
install:
	@echo "install: not yet implemented for crent370"

# package (stub — not yet implemented for crent370)
package:
	@echo "package: not yet implemented for crent370"

# generate compile_commands.json for clangd
compiledb:
	@echo "Generating compile_commands.json"
	@{ \
		echo "["; \
		first=1; \
		for f in $$(find src -name '*.c' | sort); do \
			abs_file="$(CURDIR)/$$f"; \
			if [ $$first -eq 0 ]; then echo ","; fi; \
			first=0; \
			echo "  {"; \
			echo "    \"directory\": \"$(CURDIR)\","; \
			echo "    \"file\": \"$$abs_file\","; \
			echo "    \"arguments\": [\"clang\", \"-c\", \"-std=c89\", \"-I$(CURDIR)/include\", \"$$abs_file\"]"; \
			echo "  }"; \
		done; \
		echo "]"; \
	} > compile_commands.json

.PHONY: all clean link install package compiledb
