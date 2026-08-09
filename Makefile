AS := tools/binutils/bin/arm-none-eabi-as
LD := tools/binutils/bin/arm-none-eabi-ld
OBJCOPY := tools/binutils/bin/arm-none-eabi-objcopy
SHA1SUM := sha1sum -c
GBAFIX := tools/gbafix/gbafix
PREPROC := tools/preproc/preproc
SHELL := /bin/bash

ASFLAGS := -mcpu=arm7tdmi

ASFILE := $(wildcard asm/*.s)
OBJFILE := $(ASFILE:.s=.o) data/event_scripts.o data/data.o
DATA_BIN := build/data/event_scripts.bin build/data/data.bin
NAME := pokeemerald_jp
ROM := $(NAME).gba
ELF := $(NAME).elf
TITLE := POKEMON EMER
GAMECODE := BPEJ

.PHONY: all compare clean

all: $(ROM)

compare: $(ROM)
	$(SHA1SUM) rom_jp.sha1

clean:
	rm -f $(ROM) $(ELF) $(OBJFILE) $(DATA_BIN)

$(ROM): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(DATA_BIN): tools/extract_baserom_data.py baserom_jp.gba
	mkdir -p build/data
	python3 tools/extract_baserom_data.py

$(ELF): %.elf: $(OBJFILE) ld_script_jp.txt
	$(LD) -T ld_script_jp.txt -Map $*.map -o $@ $(OBJFILE) -L tools/agbcc/lib -lgcc -lc
	$(GBAFIX) -t"$(TITLE)" -c$(GAMECODE) -m01 --silent $@

$(ASFILE:.s=.o): %.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

data/event_scripts.o: data/event_scripts.s build/data/event_scripts.bin
	$(AS) $(ASFLAGS) -o $@ $<

data/data.o: data/data.s charmap.txt
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -
