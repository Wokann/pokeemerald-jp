# This controls building host executables in the `tools` folder.
# It follows pokeemerald's tool-chain layout while retaining the
# Japanese project's aif2pcm utility.

MAKEFLAGS += --no-print-directory

TOOLS_DIR := tools
TOOL_NAMES := aif2pcm bin2c gbafix gbagfx jsonproc mapjson mid2agb preproc ramscrgen rsfont scaninc wav2agb
TOOLDIRS := $(TOOL_NAMES:%=$(TOOLS_DIR)/%)

.PHONY: tools clean-tools $(TOOLDIRS)

tools: $(TOOLDIRS)

$(TOOLDIRS):
	@$(MAKE) -C $@ CC=cc

clean-tools:
	@$(foreach tooldir,$(TOOLDIRS),$(MAKE) clean -C $(tooldir);)
