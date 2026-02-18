MODULES := asm src/clib src/cmtt src/dyn75 src/jes src/racf src/thdmgr src/time64

all:
	@rm -f .build-warnings
	@for dir in $(MODULES); do $(MAKE) -C $$dir $@ || exit 1; done

clean:
	@for dir in $(MODULES); do $(MAKE) -C $$dir $@; done
	@rm -f .build-warnings

.PHONY: all clean
