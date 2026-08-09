AS := tools/binutils/bin/arm-none-eabi-as
LD := tools/binutils/bin/arm-none-eabi-ld
OBJCOPY := tools/binutils/bin/arm-none-eabi-objcopy
SHA1SUM := sha1sum -c
GBAFIX := tools/gbafix/gbafix

ASFLAGS := -mcpu=arm7tdmi

ASFILE := $(wildcard asm/*.s data/*.s)
OBJFILE := $(ASFILE:.s=.o)
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

data/event_scripts.o: build/data/event_scripts.bin
data/data.o: build/data/data.bin

$(ELF): %.elf: $(OBJFILE) ld_script_jp.txt
	$(LD) -T ld_script_jp.txt -Map $*.map -o $@ $(OBJFILE) -L tools/agbcc/lib -lgcc -lc
	$(GBAFIX) -t"$(TITLE)" -c$(GAMECODE) -m01 --silent $@

$(OBJFILE): %.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<
