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
C_SRCS := src/main.c src/malloc.c src/sprite.c src/string_util.c src/link.c src/load_save.c src/hof_pc.c src/decompress.c src/util.c src/text.c src/text_window.c src/random.c src/heal_location.c src/landmark.c src/trig.c src/dynamic_placeholder_text_util.c src/gym_leader_rematch.c src/birch_pc.c src/fldeff_strength.c src/fldeff_teleport.c src/fldeff_rocksmash.c src/fldeff_dig.c src/fldeff_sweetscent.c src/fldeff_softboiled.c src/fldeff_flash.c src/fldeff_cut.c src/fldeff_escalator.c src/field_poison.c src/pokemon_size_record.c src/give_gift_ribbon_to_party.c src/field_door.c src/rotating_gate.c src/field_message_box.c src/field_tasks.c src/field_camera.c src/field_camera_rest.c src/berry_powder.c src/field_region_map.c src/coord_event_weather.c src/event_data.c src/field_screen_effect.c src/field_effect_helpers.c src/field_effect_helpers_get.c src/field_effect_helpers_rest.c src/coins.c src/math_util.c src/save_location.c src/clock.c src/play_time.c src/post_battle_event_funcs.c src/time_events.c src/money.c src/diploma.c src/item_icon.c src/clear_save_data_screen.c src/new_game.c src/gpu_regs.c src/task.c src/lottery_corner.c src/union_room_player_avatar.c src/roamer.c src/dma3_manager.c src/mail_data.c src/map_name_popup.c src/script_movement.c src/script.c src/safari_zone.c src/decoration_inventory.c src/trader.c src/mon_markings.c src/blit.c src/battle_util2.c src/battle_palace.c src/battle_records.c src/wallclock.c src/pokemon_icon.c src/battle_tent.c src/pokenav.c src/pokenav_main_menu.c src/pokenav_menu_handler.c src/pokenav_menu_handler_gfx.c src/pokenav_list.c src/pokenav_match_call_list.c src/pokenav_match_call_data.c src/pokenav_region_map.c src/pokenav_match_call_gfx.c src/pokenav_conditions.c src/pokenav_conditions_tail.c src/pokenav_ribbons_summary.c src/menu_specialized.c src/ereader_helpers.c src/ereader_screen.c src/faraway_island.c src/dewford_trend.c src/pokedex_cry_screen.c src/save_failed_screen.c src/scrcmd.c src/agb_flash.c src/agb_flash_1m.c src/agb_flash_mx.c src/libisagbprn_a.c src/libisagbprn_putc.c src/libisagbprn_b.c src/save.c src/reload_save.c src/rtc.c src/menu_helpers.c src/window.c src/bg.c src/palette.c src/multiboot.c src/reshow_battle_screen.c src/battle_intro.c src/battle_interface.c src/libc/memcpy.c src/libc/strcmp.c src/libc/strcpy.c src/libc/strlen.c src/libc/memchr.c src/libc/memmove.c src/libc/mlock.c src/libc/mprec.c src/siirtc.c src/braille_puzzles.c src/contest_effect.c
C_BUILDDIR := build/src
C_OBJECTS := $(patsubst src/%.c,$(C_BUILDDIR)/%.o,$(C_SRCS))

# Match the official flash library builds: agb_flash uses -O (not -O2).
$(C_BUILDDIR)/agb_flash.o: CFLAGS := -O -mthumb-interwork -fhex-asm
$(C_BUILDDIR)/agb_flash_1m.o: CFLAGS := -O -mthumb-interwork -fhex-asm
$(C_BUILDDIR)/agb_flash_mx.o: CFLAGS := -O -mthumb-interwork -fhex-asm

# The RTC library (SIIRTC_V001) is compiled without optimization, like the
# official agbcc build (matches the US pokeemerald build flags).
$(C_BUILDDIR)/siirtc.o: CFLAGS := -mthumb-interwork -ffunction-sections
$(C_BUILDDIR)/siirtc.o: src/siirtc.c
	@mkdir -p $(C_BUILDDIR)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/siirtc_gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/siirtc_gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/siirtc_gen.s

$(C_BUILDDIR)/braille_puzzles.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/braille_puzzles.o: src/braille_puzzles.c
	@mkdir -p $(C_BUILDDIR)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/braille_puzzles_gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/braille_puzzles_gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/braille_puzzles_gen.s

$(C_BUILDDIR)/title_screen.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/title_screen.o: src/title_screen.c
	@mkdir -p $(C_BUILDDIR)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/title_screen_gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/title_screen_gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/title_screen_gen.s

$(C_BUILDDIR)/contest_effect.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/contest_effect.o: src/contest_effect.c
	@mkdir -p $(C_BUILDDIR)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/contest_effect_gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/contest_effect_gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/contest_effect_gen.s

# Match the official agbcc newlib build: each libc function is compiled
# from its own newlib source with old_agbcc -O2 -fno-builtin.
$(C_BUILDDIR)/libc/%.o: src/libc/%.c
	@mkdir -p $(C_BUILDDIR)/libc
	@set -o pipefail; { cpp -I ../agbcc/libc/include -I ../agbcc/ginclude -nostdinc -undef -P -x c $< | ../pokeemerald/tools/agbcc/bin/old_agbcc -O2 -fno-builtin -ffunction-sections -o - -; } > $(C_BUILDDIR)/libc/$*.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/libc/$*.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/libc/$*.gen.s

# The JP AGBPrint library was built unoptimised (-O0); AGBPutc lives in its
# own file compiled with -O2 because agbcc's -O0 naked-asm handling would
# emit a spurious parameter spill before the function body.
$(C_BUILDDIR)/libisagbprn_a.o: CFLAGS := -O0 -mthumb-interwork -fhex-asm
$(C_BUILDDIR)/libisagbprn_putc.o: CFLAGS := -O2 -mthumb-interwork -fhex-asm
$(C_BUILDDIR)/libisagbprn_b.o: CFLAGS := -O0 -mthumb-interwork -fhex-asm

# battle_interface is wired function-by-function (see ld_script_jp.txt), so
# each function gets its own section and the still-asm functions stay in
# asm/battle_interface_mid.s.
$(C_BUILDDIR)/battle_interface.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

# link is wired function-by-function (see ld_script_jp.txt); the still-asm
# functions (ProcessRecvCmds onward) stay in asm/link_mid.s.
$(C_BUILDDIR)/link.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

OBJFILE := $(ASFILE:.s=.o) $(C_OBJECTS) data/event_scripts.o data/data.o data/data_rest.o data/multiboot_ereader.o data/multiboot_berry_glitch_fix.o
DATA_BIN := build/data/event_scripts.bin build/data/data.bin build/data/data_rest.bin build/data/mb_ereader.gba build/data/mb_berry_fix.gba
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
	$(LD) -T ld_script_jp.txt -Map $*.map -o $@ $(OBJFILE) -L tools/agbcc/lib -lgcc
	$(GBAFIX) -t"$(TITLE)" -c$(GAMECODE) -m01 --silent $@

$(ASFILE:.s=.o): %.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(C_BUILDDIR)/%.o: src/%.c
	@mkdir -p $(C_BUILDDIR)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(CC) $(CFLAGS) -o - -; \
		printf '.text\n\t.align\t2, 0\n'; } | $(AS) $(ASFLAGS) -o $@ -

$(C_BUILDDIR)/battle_interface.o: src/battle_interface.c
	@mkdir -p $(C_BUILDDIR)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(CC) $(CFLAGS) -o - -; \
		printf '.text\n\t.align\t2, 0\n'; } | awk '/^\t\.size\t/{print; print "\t.align\t2, 0"; next} {print}' | $(AS) $(ASFLAGS) -o $@ -

$(C_BUILDDIR)/link.o: src/link.c
	@mkdir -p $(C_BUILDDIR)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(CC) $(CFLAGS) -o - -; \
		printf '.text\n\t.align\t2, 0\n'; } | awk '/^\t\.size\t/{print; print "\t.align\t2, 0"; next} {print}' | $(AS) $(ASFLAGS) -o $@ -

data/event_scripts.o: data/event_scripts.s build/data/event_scripts.bin
	$(AS) $(ASFLAGS) -o $@ $<

data/data.o: data/data.s charmap.txt
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

data/data_rest.o: data/data_rest.s build/data/data_rest.bin
	$(AS) $(ASFLAGS) -o $@ $<

data/multiboot_ereader.o: data/multiboot_ereader.s build/data/mb_ereader.gba
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

data/multiboot_berry_glitch_fix.o: data/multiboot_berry_glitch_fix.s build/data/mb_berry_fix.gba
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(C_BUILDDIR)/libc/mprec.o: src/libc/mprec.c
	@mkdir -p $(C_BUILDDIR)/libc
	@set -o pipefail; { cpp -I ../agbcc/libc/include -I ../agbcc/ginclude -I ../agbcc/libc/stdlib -D__IEEE_LITTLE_ENDIAN -nostdinc -undef -P -x c $< | ../pokeemerald/tools/agbcc/bin/old_agbcc -O2 -fno-builtin -ffunction-sections -o - -; } > $(C_BUILDDIR)/libc/mprec_gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/libc/mprec_gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/libc/mprec_gen.s
