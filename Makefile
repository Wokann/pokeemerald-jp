AS := tools/binutils/bin/arm-none-eabi-as
LD := tools/binutils/bin/arm-none-eabi-ld
OBJCOPY := tools/binutils/bin/arm-none-eabi-objcopy
SHA1SUM := sha1sum -c
GBAFIX := tools/gbafix/gbafix
PREPROC := tools/preproc/preproc
CPP := cpp
CC := ../pokeemerald/tools/agbcc/bin/agbcc
CPPFLAGS := -iquote include -Wno-trigraphs \
	-I ../pokeemerald/tools/agbcc/include -I ../pokeemerald/tools/agbcc \
	-nostdinc -undef -std=gnu89
SHELL := /bin/bash

ASFLAGS := -mcpu=arm7tdmi
CFLAGS := -mthumb-interwork -O2 -fhex-asm

ASFILE := $(wildcard asm/*.s)
# Modules fully converted and wired into the build.  Add a module here
# once every function in its asm file has been converted to C (or the
# asm file has been split so the C functions fill a contiguous ROM
# range), then remove the asm object from ld_script_jp.txt.
C_SRCS := src/load_save.c src/hof_pc.c src/decompress.c src/util.c src/text.c src/text_window.c src/random.c src/heal_location.c src/landmark.c src/trig.c src/dynamic_placeholder_text_util.c src/gym_leader_rematch.c src/birch_pc.c src/fldeff_strength.c src/fldeff_teleport.c src/fldeff_rocksmash.c src/fldeff_dig.c src/fldeff_sweetscent.c src/fldeff_softboiled.c src/fldeff_flash.c src/fldeff_cut.c src/fldeff_escalator.c src/field_poison.c src/pokemon_size_record.c src/give_gift_ribbon_to_party.c src/field_door.c src/rotating_gate.c src/field_message_box.c src/field_tasks.c src/field_camera.c src/field_camera_rest.c src/berry_powder.c src/field_region_map.c src/coord_event_weather.c src/event_data.c src/field_screen_effect.c src/field_effect_helpers.c src/field_effect_helpers_get.c src/field_effect_helpers_rest.c src/coins.c src/math_util.c src/save_location.c src/clock.c src/play_time.c src/post_battle_event_funcs.c src/time_events.c src/money.c src/diploma.c src/item_icon.c
C_BUILDDIR := build/src
C_OBJECTS := $(patsubst src/%.c,$(C_BUILDDIR)/%.o,$(C_SRCS))
OBJFILE := $(ASFILE:.s=.o) $(C_OBJECTS) data/event_scripts.o data/data.o
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
	rm -rf build $(ROM) $(ELF) $(OBJFILE) $(DATA_BIN)

$(ROM): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(DATA_BIN): tools/extract_baserom_data.py baserom_jp.gba
	mkdir -p build/data
	python3 tools/extract_baserom_data.py

$(ELF): %.elf: $(OBJFILE) ld_script_jp.txt sym_ewram_jp.txt sym_iwram_jp.txt
	$(LD) -T ld_script_jp.txt -Map $*.map -o $@ $(OBJFILE) -L tools/agbcc/lib -lgcc -lc
	$(GBAFIX) -t"$(TITLE)" -c$(GAMECODE) -m01 --silent $@

$(ASFILE:.s=.o): %.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(C_BUILDDIR)/%.o: src/%.c
	@mkdir -p $(C_BUILDDIR)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(CC) $(CFLAGS) -o - -; \
		printf '.text\n\t.align\t2, 0\n'; } | $(AS) $(ASFLAGS) -o $@ -

data/event_scripts.o: data/event_scripts.s build/data/event_scripts.bin
	$(AS) $(ASFLAGS) -o $@ $<

data/data.o: data/data.s charmap.txt
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -
