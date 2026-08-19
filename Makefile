AS := tools/binutils/bin/arm-none-eabi-as
LD := tools/binutils/bin/arm-none-eabi-ld
OBJCOPY := tools/binutils/bin/arm-none-eabi-objcopy
SHA1SUM := sha1sum -c
GBAFIX := tools/gbafix/gbafix
PREPROC := tools/preproc/preproc
CPP := cpp
CC := tools/agbcc/bin/agbcc
CPPFLAGS := -iquote include -Wno-trigraphs \
	-I tools/agbcc/include -I tools/agbcc \
	-nostdinc -undef -std=gnu89
SHELL := /bin/bash

# Compile with `make NONMATCHING=1` to use the readable C implementations
# instead of the byte-exact inline-asm versions (see include/config.h).
# Default (no NONMATCHING) keeps the ROM byte-identical to baserom_jp.gba.
ifdef NONMATCHING
CPPFLAGS += -DNONMATCHING
endif

ASFLAGS := -mcpu=arm7tdmi
CFLAGS := -mthumb-interwork -O2 -fhex-asm

# The per-file CFLAGS rules below would otherwise become the default goal;
# keep `make` (no target) building the ROM like the US pokeemerald Makefile.
.DEFAULT_GOAL := all

# Build flavor.  Keep the current decompilation build under
# build/pokeemerald-jp/; alternate builds (e.g. BUILD_NAME=pokeemerald-jp-rev10)
# get their own subdirectory under build/, like pokefirered's BUILD_NAME.
BUILD_NAME ?= pokeemerald-jp
OBJ_DIR := build/$(BUILD_NAME)

ASFILE := $(wildcard asm/*.s)
AS_OBJS := $(patsubst asm/%.s,$(OBJ_DIR)/asm/%.o,$(ASFILE))
# Assembly files that live under src/ like US pokeemerald
# (crt0.s, libgcnmultiboot.s, m4a_1.s).
C_ASM_SRCS := $(wildcard src/crt0.s src/libgcnmultiboot.s src/m4a_1.s)
C_ASM_OBJS := $(patsubst src/%.s,$(OBJ_DIR)/src/%.o,$(C_ASM_SRCS))
# Modules fully converted and wired into the build.  Add a module here
# once every function in its asm file has been converted to C (or the
# asm file has been split so the C functions fill a contiguous ROM
# range), then remove the asm object from ld_script_jp.txt.
# US sources copied for reference but not yet ported to JP: their functions
# still live in asm/, so exclude them from the build until converted.
UNPORTED_SRCS :=
C_SRCS := $(filter-out $(UNPORTED_SRCS),$(wildcard src/*.c src/*/*.c src/*/*/*.c))
C_BUILDDIR := $(OBJ_DIR)/src
C_OBJECTS := $(patsubst src/%.c,$(C_BUILDDIR)/%.o,$(C_SRCS))
C_OBJECTS := $(filter-out $(C_BUILDDIR)/libisagbprn.o,$(C_OBJECTS))
C_OBJECTS += $(C_BUILDDIR)/libisagbprn_a.o $(C_BUILDDIR)/libisagbprn_putc.o $(C_BUILDDIR)/libisagbprn_b.o
C_OBJECTS += $(C_BUILDDIR)/field_player_avatar_tail.o
C_OBJECTS += $(C_BUILDDIR)/pokenav_conditions_gfx_tail.o

# Match the official flash library builds: agb_flash uses -O (not -O2).
$(C_BUILDDIR)/agb_flash.o: CFLAGS := -O -mthumb-interwork -fhex-asm
$(C_BUILDDIR)/agb_flash_1m.o: CFLAGS := -O -mthumb-interwork -fhex-asm
$(C_BUILDDIR)/agb_flash_mx.o: CFLAGS := -O -mthumb-interwork -fhex-asm

# The RTC library (SIIRTC_V001) is compiled without optimization, like the
# official agbcc build (matches the US pokeemerald build flags).
$(C_BUILDDIR)/siirtc.o: CFLAGS := -mthumb-interwork -ffunction-sections

$(C_BUILDDIR)/braille_puzzles.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/title_screen.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/contest_effect.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/contest.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/trade.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/event_object_movement.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/pokemon_storage_system.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/party_menu.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/slot_machine.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/easy_chat.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/pokemon_animation.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/field_effect.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/overworld.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/scanline_effect.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/option_menu.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/credits.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/pokeball.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/mystery_event_menu.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/list_menu.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/daycare.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/shop.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/librfu_stwi.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/librfu_intr.o: CC1 := tools/agbcc/bin/agbcc_arm
$(C_BUILDDIR)/librfu_intr.o: CFLAGS := -O2 -mthumb-interwork -quiet
$(C_BUILDDIR)/libagbsyscall.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/m4a.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/trader_jp_only.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/field_player_avatar_tail.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/field_player_avatar_tail.o: CPPFLAGS += -DFIELD_PLAYER_AVATAR_TAIL
$(C_BUILDDIR)/field_player_avatar_tail.o: src/field_player_avatar.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $@.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $@.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $@.gen.s
$(C_BUILDDIR)/berry.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/field_weather_effect.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_ai_script_commands.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/contest_ai.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_controller_recorded_opponent.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/mauville_old_man.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_controller_safari.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/contest_util.o $(C_BUILDDIR)/script_pokemon_util.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/field_weather.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/item.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_anim.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/fldeff_misc.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/start_menu.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/player_pc.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_controller_wally.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_dome.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/intro.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/region_map.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/secret_base.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/librfu_rfu.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_controller_player_partner.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_controller_recorded_player.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_controller_link_partner.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_controller_link_opponent.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_controller_opponent.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_controller_player.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_tower.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/trainer_card.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/item_use.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/frontier_util.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/apprentice.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/pokemon.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/item_menu.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/pokemon_summary_screen.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/graphics.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_factory_screen.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/menu.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/naming_screen.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/pokedex.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/field_specials.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/decoration.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/roulette.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/lilycove_lady.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_anim_throw.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/cable_club.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/berry_blender.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/use_pokeblock.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/rayquaza_scene.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/recorded_battle.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/record_mixing.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/pokeblock.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/tileset_anims.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_transition.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/mystery_event_script.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/mystery_gift_server.o $(C_BUILDDIR)/mystery_gift_link.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/wonder_news.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/union_room_chat.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/berry_crush.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/dodrio_berry_picking.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/pokemon_jump.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/berry_fix_graphics.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/minigame_countdown.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/main_menu.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_controllers.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_main.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_util.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_script_commands.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_message.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/cable_car.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/palette_util.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_effects_3.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_effects_2.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_effects_1.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_mons.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_poison.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_bug.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_rock.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_ground.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_fight.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_ice.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_flying.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_psychic.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_electric.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_fire.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_ghost.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_dark.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_dragon.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_normal.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_water.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_sound_tasks.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_status_effects.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_mon_movement.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_utility_funcs.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/mail.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/starter_choose.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/move_relearner.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/title_screen.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_smokescreen.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/rotating_tile_puzzle.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_tv.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/tv.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/bard_music.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/pokedex_area_region_map.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/pokedex_area_region_map.o: CC1 = $(PREPROC) -i src/pokedex_area_region_map.c charmap.txt | $(CC)
$(C_BUILDDIR)/braille.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/libc/libc_rest_1b3.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/libc/libc_rest_2.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/libc/libc_rest_0.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/mystery_gift_client.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/librfu.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/berry_fix_program.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/contest_link_util.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/contest_link.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/mon_markings.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/sound.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/reset_rtc_screen.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/mirage_tower.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/match_call.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/wild_encounter.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/bike.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/event_object_lock.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/field_special_scene.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/trainer_pokemon_sprites.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/metatile_behavior.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/fieldmap.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/battle_setup.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/trainer_see.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/field_control_avatar.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/field_player_avatar.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

# Match the official agbcc newlib build: each libc function is compiled
# from its own newlib source with old_agbcc -O2 -fno-builtin.
$(C_BUILDDIR)/libc/%.o: src/libc/%.c
	@mkdir -p $(C_BUILDDIR)/libc
	@set -o pipefail; { cpp -I tools/agbcc-src/libc/include -I tools/agbcc-src/ginclude -nostdinc -undef -P -x c $< | tools/agbcc/bin/old_agbcc -O2 -fno-builtin -ffunction-sections -o - -; } > $(C_BUILDDIR)/libc/$*.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/libc/$*.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/libc/$*.gen.s

# The JP AGBPrint library was built unoptimised (-O0); AGBPutc lives in its
# own object compiled from the unified source with -O2 because agbcc's -O0 naked-asm handling would
# emit a spurious parameter spill before the function body.
$(C_BUILDDIR)/libisagbprn_a.o: CFLAGS := -O0 -mthumb-interwork -fhex-asm
$(C_BUILDDIR)/libisagbprn_putc.o: CFLAGS := -O2 -mthumb-interwork -fhex-asm
$(C_BUILDDIR)/libisagbprn_b.o: CFLAGS := -O0 -mthumb-interwork -fhex-asm
$(C_BUILDDIR)/libisagbprn_a.o: CPPFLAGS += -DLIBISAGBPRN_PART_A
$(C_BUILDDIR)/libisagbprn_putc.o: CPPFLAGS += -DLIBISAGBPRN_PART_PUTC
$(C_BUILDDIR)/libisagbprn_b.o: CPPFLAGS += -DLIBISAGBPRN_PART_B
$(C_BUILDDIR)/libisagbprn_a.o $(C_BUILDDIR)/libisagbprn_putc.o $(C_BUILDDIR)/libisagbprn_b.o: src/libisagbprn.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $@.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $@.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $@.gen.s

# battle_interface is wired function-by-function (see ld_script_jp.txt), so
# each function gets its own section and the still-asm functions stay in
# asm/battle_interface_mid.s.
$(C_BUILDDIR)/battle_interface.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

# link is wired function-by-function (see ld_script_jp.txt); the still-asm
# functions (ProcessRecvCmds onward) stay in asm/link_mid.s.
$(C_BUILDDIR)/link.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/AgbRfu_LinkManager.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/link_rfu_2.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/union_room.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/union_room_battle.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/union_room_player_avatar.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/wireless_communication_status_screen.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/mystery_gift.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/mystery_gift_menu.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/mystery_gift_view.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

# link_rfu_3 is wired function-by-function (see ld_script_jp.txt); the
# still-asm functions stay in asm/link_rfu.s.
$(C_BUILDDIR)/link_rfu_3.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

# AgbRfu_LinkManager is wired function-by-function (see ld_script_jp.txt); the
# still-asm Link Manager functions stay in asm/link_rfu.s.
$(C_BUILDDIR)/AgbRfu_LinkManager.o: src/AgbRfu_LinkManager.c
	@mkdir -p $(C_BUILDDIR)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(CC) $(CFLAGS) -o - -; \
		printf '.text\n\t.align\t2, 0\n'; } | awk '/^\t\.size\t/{print; print "\t.align\t2, 0"; next} {print}' | $(AS) $(ASFLAGS) -o $@ -

$(C_BUILDDIR)/link_rfu_3.o: src/link_rfu_3.c
	@mkdir -p $(C_BUILDDIR)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(CC) $(CFLAGS) -o - -; \
		printf '.text\n\t.align\t2, 0\n'; } | awk '/^\t\.size\t/{print; print "\t.align\t2, 0"; next} {print}' | $(AS) $(ASFLAGS) -o $@ -

$(C_BUILDDIR)/link_rfu_2.o: src/link_rfu_2.c
	@mkdir -p $(C_BUILDDIR)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(CC) $(CFLAGS) -o - -; \
		printf '.text\n\t.align\t2, 0\n'; } | awk '/^\t\.size\t/{print; print "\t.align\t2, 0"; next} {print}' | $(AS) $(ASFLAGS) -o $@ -

DATA_OBJS := $(OBJ_DIR)/data/event_scripts.o $(OBJ_DIR)/data/data.o $(OBJ_DIR)/data/data_b.o $(OBJ_DIR)/data/data_b_mid1.o $(OBJ_DIR)/data/data_b_mid2a.o $(OBJ_DIR)/data/data_b_mid2b.o $(OBJ_DIR)/data/data_b_mid2b3.o $(OBJ_DIR)/data/data_b_mid2b5.o $(OBJ_DIR)/data/data_b_mid2b6.o $(OBJ_DIR)/data/data_b2.o $(OBJ_DIR)/data/data_b2b.o $(OBJ_DIR)/data/data_b2d.o $(OBJ_DIR)/data/data_b2d_mid47.o $(OBJ_DIR)/data/data_b2d_mid51.o $(OBJ_DIR)/data/data_b2d_mid49.o $(OBJ_DIR)/data/data_b2d_mid50.o $(OBJ_DIR)/data/data_b2d_mid30.o $(OBJ_DIR)/data/data_b2d_mid28.o $(OBJ_DIR)/data/data_b2d_mid29.o $(OBJ_DIR)/data/data_b2d_mid31.o $(OBJ_DIR)/data/data_b2d_mid26.o $(OBJ_DIR)/data/data_b2d_mid15.o $(OBJ_DIR)/data/data_b2d_mid54.o $(OBJ_DIR)/data/data_b2d_mid55.o $(OBJ_DIR)/data/data_b2d_mid56.o $(OBJ_DIR)/data/data_b2d_mid57_a.o $(OBJ_DIR)/data/data_b2d_mid57_b.o $(OBJ_DIR)/data/data_b2d_mid58.o $(OBJ_DIR)/data/data_b2d_mid59.o $(OBJ_DIR)/data/data_b2d_mid37.o $(OBJ_DIR)/data/data_b2d_mid60.o $(OBJ_DIR)/data/data_b2d_mid61.o $(OBJ_DIR)/data/data_b2d_mid62.o $(OBJ_DIR)/data/data_b2d_mid38.o $(OBJ_DIR)/data/data_b2d_mid33.o $(OBJ_DIR)/data/data_b2d_mid64.o $(OBJ_DIR)/data/data_b2d_mid32.o $(OBJ_DIR)/data/data_b2d_mid65.o $(OBJ_DIR)/data/data_b2d_rest.o $(OBJ_DIR)/data/data_b2d_mid69.o $(OBJ_DIR)/data/data_b2d_mid70.o $(OBJ_DIR)/data/data_b2d_mid98.o $(OBJ_DIR)/data/data_b2d_mid100.o $(OBJ_DIR)/data/data_b2c_mid2.o $(OBJ_DIR)/data/data_b2c_mid3.o $(OBJ_DIR)/data/data_b2c_mid4.o $(OBJ_DIR)/data/data_b2c_mid5.o $(OBJ_DIR)/data/data_b2c_mid6.o $(OBJ_DIR)/data/data_b2c_mid7.o $(OBJ_DIR)/data/data_b2c_mid8.o $(OBJ_DIR)/data/data_b2c_mid8_tail.o $(OBJ_DIR)/data/data_rest.o $(OBJ_DIR)/data/data_rest2.o $(OBJ_DIR)/data/data_b2d_gfx_pokemon_none.o $(OBJ_DIR)/data/data_rest2b.o $(OBJ_DIR)/data/data_b2d_gfx_pokemon_main.o $(OBJ_DIR)/data/data_rest2c.o $(OBJ_DIR)/data/data_b2d_gfx_front.o $(OBJ_DIR)/data/multiboot_ereader.o $(OBJ_DIR)/data/multiboot_berry_glitch_fix.o
OBJFILE := $(AS_OBJS) $(C_ASM_OBJS) $(C_OBJECTS) $(DATA_OBJS)
OBJFILE_REL := $(patsubst $(OBJ_DIR)/%,%,$(OBJFILE))
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
	rm -rf build $(ROM) $(ELF)

$(ROM): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(ELF): %.elf: $(OBJFILE) ld_script_jp.txt sym_ewram_jp.txt sym_iwram_jp.txt
	cd $(OBJ_DIR) && ../../$(LD) -T ../../ld_script_jp.txt -Map ../../$*.map -o ../../$@ $(OBJFILE_REL) -L ../../tools/agbcc/lib -lgcc
	$(GBAFIX) -t"$(TITLE)" -c$(GAMECODE) -m01 --silent $@

$(AS_OBJS): $(OBJ_DIR)/asm/%.o: asm/%.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

$(C_ASM_OBJS): $(OBJ_DIR)/src/%.o: src/%.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

# Text data tables are written as _("...") charmap strings (US style);
# run them through preproc so the kana/control bytes are encoded.
$(C_BUILDDIR)/data/text/%.o: src/data/text/%.c src/data/text/%.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/$*.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/$*.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/$*.gen.s

$(C_BUILDDIR)/item.o: src/item.c src/data/items.h src/data/text/item_descriptions.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/item.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/item.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/item.gen.s

$(C_BUILDDIR)/pokenav_match_call_gfx.o: src/pokenav_match_call_gfx.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokenav_match_call_gfx.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokenav_match_call_gfx.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokenav_match_call_gfx.gen.s

$(C_BUILDDIR)/field_specials.o: src/field_specials.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/field_specials.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/field_specials.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/field_specials.gen.s

$(C_BUILDDIR)/pokenav_conditions_gfx_tail.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/pokenav_conditions_gfx_tail.o: CPPFLAGS += -DPOKENAV_CONDITIONS_GFX_TAIL
$(C_BUILDDIR)/pokenav_conditions_gfx_tail.o: src/pokenav_conditions_gfx.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $@.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $@.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $@.gen.s
$(C_BUILDDIR)/pokenav_conditions_gfx.o: src/pokenav_conditions_gfx.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokenav_conditions_gfx.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokenav_conditions_gfx.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokenav_conditions_gfx.gen.s

$(C_BUILDDIR)/pokenav_ribbons_summary.o: src/pokenav_ribbons_summary.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokenav_ribbons_summary.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokenav_ribbons_summary.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokenav_ribbons_summary.gen.s
$(C_BUILDDIR)/braille.o: src/braille.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/braille.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/braille.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/braille.gen.s
$(C_BUILDDIR)/mirage_tower.o: src/mirage_tower.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/mirage_tower.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/mirage_tower.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/mirage_tower.gen.s
graphics/summary_screen/%.png.4bpp: graphics/summary_screen/%.png
	tools/gbagfx/gbagfx $< $@
$(C_BUILDDIR)/pokemon_summary_screen.o: src/pokemon_summary_screen.c graphics/summary_screen/a_button.png.4bpp graphics/summary_screen/b_button.png.4bpp
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokemon_summary_screen.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokemon_summary_screen.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokemon_summary_screen.gen.s
$(C_BUILDDIR)/graphics.o: src/graphics.c graphics/summary_screen/effect_battle.bin graphics/summary_screen/effect_contest.bin graphics/summary_screen/effect_cancel.bin $(wildcard graphics/pokenav/*.lz graphics/pokenav/*.gbapal graphics/pokenav/left_headers/*.lz graphics/pokenav/left_headers/*.gbapal)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/graphics.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/graphics.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/graphics.gen.s
$(C_BUILDDIR)/pokenav_list.o: src/pokenav_list.c graphics/pokenav/list_arrows.gbapal graphics/pokenav/list_arrows.4bpp.lz
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokenav_list.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokenav_list.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokenav_list.gen.s




$(C_BUILDDIR)/menu_specialized.o: src/menu_specialized.c charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/menu_specialized.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/menu_specialized.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/menu_specialized.gen.s

$(C_BUILDDIR)/data/trainer_hill_templates.o: src/data/trainer_hill_templates.c charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/trainer_hill_templates.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/trainer_hill_templates.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/trainer_hill_templates.gen.s

$(C_BUILDDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/$*.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/$*.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/$*.gen.s

$(C_BUILDDIR)/battle_interface.o: src/battle_interface.c
	@mkdir -p $(C_BUILDDIR)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(CC) $(CFLAGS) -o - -; \
		printf '.text\n\t.align\t2, 0\n'; } | awk '/^\t\.size\t/{print; print "\t.align\t2, 0"; next} {print}' | $(AS) $(ASFLAGS) -o $@ -

$(C_BUILDDIR)/link.o: src/link.c
	@mkdir -p $(C_BUILDDIR)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(CC) $(CFLAGS) -o - -; \
		printf '.text\n\t.align\t2, 0\n'; } | awk '/^\t\.size\t/{print; print "\t.align\t2, 0"; next} {print}' | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/event_scripts.o: data/event_scripts.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data.o: data/data.s charmap.txt baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b.o: data/data_b.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b_mid1.o: data/data_b_mid1.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b_mid2a.o: data/data_b_mid2a.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b_mid2b.o: data/data_b_mid2b.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b_mid2b3.o: data/data_b_mid2b3.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b_mid2b5.o: data/data_b_mid2b5.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -
$(OBJ_DIR)/data/data_b_mid2b6.o: data/data_b_mid2b6.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -
# Union-room texts/RFU debug strings are _() charmap strings, so they go
# through the same preproc pipeline as the region_texts files.
$(C_BUILDDIR)/data/union_room.o: src/data/union_room.c src/data/union_room.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room.gen.s

$(C_BUILDDIR)/data/union_room2.o: src/data/union_room2.c src/data/union_room2.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room2.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room2.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room2.gen.s

$(C_BUILDDIR)/data/union_room3.o: src/data/union_room3.c src/data/union_room3.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room3.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room3.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room3.gen.s

$(C_BUILDDIR)/data/union_room4.o: src/data/union_room4.c src/data/union_room4.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room4.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room4.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room4.gen.s

$(C_BUILDDIR)/data/union_room5.o: src/data/union_room5.c src/data/union_room5.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room5.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room5.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room5.gen.s

$(C_BUILDDIR)/data/union_room6.o: src/data/union_room6.c src/data/union_room6.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room6.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room6.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room6.gen.s

$(C_BUILDDIR)/data/union_room7.o: src/data/union_room7.c src/data/union_room7.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room7.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room7.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room7.gen.s

$(C_BUILDDIR)/data/union_room8.o: src/data/union_room8.c src/data/union_room8.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8.gen.s

$(C_BUILDDIR)/data/union_room8b.o: src/data/union_room8b.c src/data/union_room8b.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8b.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8b.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8b.gen.s

$(C_BUILDDIR)/data/union_room8c.o: src/data/union_room8c.c src/data/union_room8c.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8c.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8c.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8c.gen.s

$(C_BUILDDIR)/data/union_room8d.o: src/data/union_room8d.c src/data/union_room8d.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8d.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8d.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8d.gen.s

$(C_BUILDDIR)/data/union_room8e.o: src/data/union_room8e.c src/data/union_room8e.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8e.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8e.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8e.gen.s

$(C_BUILDDIR)/data/union_room8f.o: src/data/union_room8f.c src/data/union_room8f.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8f.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8f.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8f.gen.s

$(C_BUILDDIR)/data/union_room8g.o: src/data/union_room8g.c src/data/union_room8g.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8g.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8g.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8g.gen.s

$(C_BUILDDIR)/data/union_room8h.o: src/data/union_room8h.c src/data/union_room8h.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8h.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8h.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8h.gen.s

$(C_BUILDDIR)/data/union_room8i.o: src/data/union_room8i.c src/data/union_room8i.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8i.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8i.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8i.gen.s

$(C_BUILDDIR)/data/union_room8j.o: src/data/union_room8j.c src/data/union_room8j.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8j.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8j.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8j.gen.s

$(C_BUILDDIR)/data/union_room8k.o: src/data/union_room8k.c src/data/union_room8k.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8k.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8k.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8k.gen.s

$(C_BUILDDIR)/data/union_room8l.o: src/data/union_room8l.c src/data/union_room8l.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8l.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8l.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8l.gen.s

$(C_BUILDDIR)/data/union_room8m.o: src/data/union_room8m.c src/data/union_room8m.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8m.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8m.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8m.gen.s

$(C_BUILDDIR)/data/union_room8n.o: src/data/union_room8n.c src/data/union_room8n.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8n.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8n.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8n.gen.s

$(C_BUILDDIR)/data/union_room8o.o: src/data/union_room8o.c src/data/union_room8o.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8o.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8o.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8o.gen.s

$(C_BUILDDIR)/data/union_room8p.o: src/data/union_room8p.c src/data/union_room8p.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8p.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8p.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8p.gen.s

$(C_BUILDDIR)/data/union_room8q.o: src/data/union_room8q.c src/data/union_room8q.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8q.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8q.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8q.gen.s

$(C_BUILDDIR)/data/union_room8q2.o: src/data/union_room8q2.c src/data/union_room8q2.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8q2.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8q2.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8q2.gen.s

$(C_BUILDDIR)/data/union_room8q3.o: src/data/union_room8q3.c src/data/union_room8q3.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8q3.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8q3.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8q3.gen.s

$(C_BUILDDIR)/data/union_room8q4.o: src/data/union_room8q4.c src/data/union_room8q4.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8q4.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8q4.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8q4.gen.s

$(C_BUILDDIR)/data/union_room8r.o: src/data/union_room8r.c src/data/union_room8r.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8r.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8r.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8r.gen.s

$(C_BUILDDIR)/data/union_room8s.o: src/data/union_room8s.c src/data/union_room8s.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8s.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8s.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8s.gen.s

$(C_BUILDDIR)/data/union_room8t.o: src/data/union_room8t.c src/data/union_room8t.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8t.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8t.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8t.gen.s

$(C_BUILDDIR)/data/union_room8u.o: src/data/union_room8u.c src/data/union_room8u.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8u.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8u.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8u.gen.s

$(C_BUILDDIR)/data/union_room8v.o: src/data/union_room8v.c src/data/union_room8v.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8v.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8v.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8v.gen.s

$(C_BUILDDIR)/data/union_room8w.o: src/data/union_room8w.c src/data/union_room8w.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8w.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8w.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8w.gen.s

$(C_BUILDDIR)/data/union_room8x.o: src/data/union_room8x.c src/data/union_room8x.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8x.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8x.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8x.gen.s

$(C_BUILDDIR)/data/union_room8y.o: src/data/union_room8y.c src/data/union_room8y.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8y.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8y.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8y.gen.s

$(C_BUILDDIR)/data/union_room8z.o: src/data/union_room8z.c src/data/union_room8z.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/union_room8z.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/union_room8z.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/union_room8z.gen.s

$(C_BUILDDIR)/data/berry_crush1.o: src/data/berry_crush1.c src/data/berry_crush1.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/berry_crush1.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/berry_crush1.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/berry_crush1.gen.s

$(C_BUILDDIR)/data/berry_crush2.o: src/data/berry_crush2.c src/data/berry_crush2.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/berry_crush2.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/berry_crush2.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/berry_crush2.gen.s

$(C_BUILDDIR)/data/berry_crush3.o: src/data/berry_crush3.c src/data/berry_crush3.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/berry_crush3.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/berry_crush3.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/berry_crush3.gen.s

$(C_BUILDDIR)/data/berry_crush4.o: src/data/berry_crush4.c src/data/berry_crush4.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/berry_crush4.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/berry_crush4.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/berry_crush4.gen.s

$(C_BUILDDIR)/data/dodrio1.o: src/data/dodrio1.c src/data/dodrio1.h src/data/dodrio1_dup_maps.inc
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/dodrio1.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/dodrio1.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/dodrio1.gen.s

$(C_BUILDDIR)/data/dodrio2.o: src/data/dodrio2.c src/data/dodrio2.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/dodrio2.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/dodrio2.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/dodrio2.gen.s

$(C_BUILDDIR)/data/pokejump1.o: src/data/pokejump1.c src/data/pokejump1.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/pokejump1.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/pokejump1.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/pokejump1.gen.s

$(C_BUILDDIR)/data/pokejump2.o: src/data/pokejump2.c src/data/pokejump2.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/pokejump2.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/pokejump2.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/pokejump2.gen.s

$(C_BUILDDIR)/data/pokejump3.o: src/data/pokejump3.c src/data/pokejump3.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/pokejump3.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/pokejump3.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/pokejump3.gen.s

$(C_BUILDDIR)/data/pokejump4.o: src/data/pokejump4.c src/data/pokejump4.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/pokejump4.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/pokejump4.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/pokejump4.gen.s

$(C_BUILDDIR)/data/minigame_countdown.o: src/data/minigame_countdown.c src/data/minigame_countdown.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/minigame_countdown.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/minigame_countdown.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/minigame_countdown.gen.s

$(C_BUILDDIR)/data/rtc_data.o: src/data/rtc_data.c src/data/rtc_data.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/rtc_data.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/rtc_data.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/rtc_data.gen.s

$(C_BUILDDIR)/data/main_menu_data.o: src/data/main_menu_data.c src/data/main_menu_data.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/main_menu_data.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/main_menu_data.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/main_menu_data.gen.s

$(C_BUILDDIR)/data/battle_affine.o: src/data/battle_affine.c src/data/battle_affine.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/battle_affine.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/battle_affine.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/battle_affine.gen.s

$(C_BUILDDIR)/data/unused_anims.o: src/data/unused_anims.c src/data/unused_anims.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/unused_anims.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/unused_anims.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/unused_anims.gen.s

$(C_BUILDDIR)/data/front_pic_coordinates.o: src/data/front_pic_coordinates.c src/data/front_pic_coordinates.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/front_pic_coordinates.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/front_pic_coordinates.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/front_pic_coordinates.gen.s

$(C_BUILDDIR)/data/back_pic_coordinates.o: src/data/back_pic_coordinates.c src/data/back_pic_coordinates.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/back_pic_coordinates.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/back_pic_coordinates.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/back_pic_coordinates.gen.s

$(C_BUILDDIR)/data/trainer_front_anims.o: src/data/trainer_front_anims.c src/data/trainer_front_anims.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/trainer_front_anims.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/trainer_front_anims.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/trainer_front_anims.gen.s

$(C_BUILDDIR)/data/trainer_front_pic_coords.o: src/data/trainer_front_pic_coords.c src/data/trainer_front_pic_coords.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/trainer_front_pic_coords.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/trainer_front_pic_coords.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/trainer_front_pic_coords.gen.s

$(C_BUILDDIR)/data/trainer_back_pic_coords.o: src/data/trainer_back_pic_coords.c src/data/trainer_back_pic_coords.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/trainer_back_pic_coords.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/trainer_back_pic_coords.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/trainer_back_pic_coords.gen.s

$(C_BUILDDIR)/data/enemy_mon_elevation.o: src/data/enemy_mon_elevation.c src/data/enemy_mon_elevation.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/enemy_mon_elevation.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/enemy_mon_elevation.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/enemy_mon_elevation.gen.s

$(C_BUILDDIR)/data/front_pic_anims.o: src/data/front_pic_anims.c src/data/front_pic_anims.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/front_pic_anims.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/front_pic_anims.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/front_pic_anims.gen.s

$(C_BUILDDIR)/data/front_pic_table.o: src/data/front_pic_table.c src/data/front_pic_table.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/front_pic_table.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/front_pic_table.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/front_pic_table.gen.s


$(C_BUILDDIR)/data/still_front_pic_table.o: src/data/still_front_pic_table.c src/data/still_front_pic_table.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/still_front_pic_table.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/still_front_pic_table.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/still_front_pic_table.gen.s

$(C_BUILDDIR)/data/back_pic_table.o: src/data/back_pic_table.c src/data/back_pic_table.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/back_pic_table.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/back_pic_table.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/back_pic_table.gen.s

$(C_BUILDDIR)/data/palette_table.o: src/data/palette_table.c src/data/palette_table.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/palette_table.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/palette_table.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/palette_table.gen.s

$(C_BUILDDIR)/data/shiny_palette_table.o: src/data/shiny_palette_table.c src/data/shiny_palette_table.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/shiny_palette_table.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/shiny_palette_table.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/shiny_palette_table.gen.s
$(C_BUILDDIR)/data/unknown_table.o: src/data/unknown_table.c src/data/unknown_table.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/unknown_table.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/unknown_table.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/unknown_table.gen.s


$(C_BUILDDIR)/data/trainer_parties.o: src/data/trainer_parties.c src/data/trainer_parties.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/trainer_parties.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/trainer_parties.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/trainer_parties.gen.s

$(C_BUILDDIR)/data/trainers.o: src/data/trainers.c src/data/trainers.h src/data/trainer_parties.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/trainers.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/trainers.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/trainers.gen.s
$(OBJ_DIR)/data/data_b2.o: data/data_b2.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2b.o: data/data_b2b.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d.o: data/data_b2d.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid15.o: data/data_b2d_mid15.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid26.o: data/data_b2d_mid26.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid28.o: data/data_b2d_mid28.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid29.o: data/data_b2d_mid29.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid30.o: data/data_b2d_mid30.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid31.o: data/data_b2d_mid31.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid32.o: data/data_b2d_mid32.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid33.o: data/data_b2d_mid33.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid37.o: data/data_b2d_mid37.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid38.o: data/data_b2d_mid38.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid47.o: data/data_b2d_mid47.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid49.o: data/data_b2d_mid49.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid50.o: data/data_b2d_mid50.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid51.o: data/data_b2d_mid51.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid54.o: data/data_b2d_mid54.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid55.o: data/data_b2d_mid55.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid56.o: data/data_b2d_mid56.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid57_a.o: data/data_b2d_mid57_a.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid57_b.o: data/data_b2d_mid57_b.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid58.o: data/data_b2d_mid58.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid59.o: data/data_b2d_mid59.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid60.o: data/data_b2d_mid60.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid61.o: data/data_b2d_mid61.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid62.o: data/data_b2d_mid62.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid64.o: data/data_b2d_mid64.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid65.o: data/data_b2d_mid65.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid69.o: data/data_b2d_mid69.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid70.o: data/data_b2d_mid70.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid98.o: data/data_b2d_mid98.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid100.o: data/data_b2d_mid100.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_rest.o: data/data_b2d_rest.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2c_mid2.o: data/data_b2c_mid2.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2c_mid3.o: data/data_b2c_mid3.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2c_mid4.o: data/data_b2c_mid4.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2c_mid5.o: data/data_b2c_mid5.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2c_mid6.o: data/data_b2c_mid6.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2c_mid7.o: data/data_b2c_mid7.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2c_mid8.o: data/data_b2c_mid8.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2c_mid8_tail.o: data/data_b2c_mid8_tail.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_rest.o: data/data_rest.s baserom_jp.gba
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

$(OBJ_DIR)/data/data_rest2.o: data/data_rest2.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -


$(OBJ_DIR)/data/data_rest2b.o: data/data_rest2b.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_rest2c.o: data/data_rest2c.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_gfx_pokemon_none.o: data/data_b2d_gfx_pokemon_none.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_gfx_pokemon_main.o: data/data_b2d_gfx_pokemon_main.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -
$(OBJ_DIR)/data/data_b2d_gfx_front.o: data/data_b2d_gfx_front.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/multiboot_ereader.o: data/multiboot_ereader.s data/mb_ereader.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/multiboot_berry_glitch_fix.o: data/multiboot_berry_glitch_fix.s data/mb_berry_fix.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(C_BUILDDIR)/libc/mprec.o: src/libc/mprec.c
	@mkdir -p $(C_BUILDDIR)/libc
	@set -o pipefail; { cpp -I tools/agbcc-src/libc/include -I tools/agbcc-src/ginclude -I tools/agbcc-src/libc/stdlib -D__IEEE_LITTLE_ENDIAN -nostdinc -undef -P -x c $< | tools/agbcc/bin/old_agbcc -O2 -fno-builtin -ffunction-sections -o - -; } > $(C_BUILDDIR)/libc/mprec_gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/libc/mprec_gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/libc/mprec_gen.s
