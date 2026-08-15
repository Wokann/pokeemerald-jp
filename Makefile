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
$(C_BUILDDIR)/credits.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/pokeball.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/list_menu.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/daycare.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/shop.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/librfu_stwi.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/libagbsyscall.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/m4a.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/m4a_tail2.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/m4a_tail3.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/m4a_tail4.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/m4a_tail5.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/m4a_tail6.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/m4a_tail7.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/m4a_tail8.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/scanline_effect_stub.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/ghost_mid.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/bike_stub_face.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/bike_stub_44.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/trader_jp_only.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_palace_jp_only.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_message_tail.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_message_tail2.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/field_player_avatar_tail.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/berry.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/field_weather_effect.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_ai_script_commands.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/contest_ai.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_controller_recorded_opponent.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/mauville_old_man.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_controller_safari.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/script_pokemon_util_80F87D8.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
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
$(C_BUILDDIR)/battle_factory_screen.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/menu.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/naming_screen.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/pokedex.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/field_specials.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/decoration.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/roulette.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/lilycove_lady.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_anim_special.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/cable_club.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/berry_blender.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/use_pokeblock.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/rayquaza_scene.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/recorded_battle.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/record_mixing.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/pokeblock.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/tileset_anims.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/battle_transition.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/mystery_event_script.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/mystery_event_server.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/wonder_news.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/union_room_chat.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/berry_crush.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/dodrio_berry_picking.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/pokemon_jump.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/main_menu.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_controllers.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_main.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_util.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_script_commands.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_message.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/cable_car.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/roulette_util.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
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
$(C_BUILDDIR)/braille.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/libc/libc_rest_1b3.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/libc/libc_rest_2.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/libc/libc_rest_0.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/mevent_client.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/mevent_server_helpers.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_controllers_ps.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_interface_tail.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_main_turnfuncs.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
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

DATA_OBJS := $(OBJ_DIR)/data/event_scripts.o $(OBJ_DIR)/data/data.o $(OBJ_DIR)/data/data_tail.o $(OBJ_DIR)/data/data_b.o $(OBJ_DIR)/data/data_b_tail.o $(OBJ_DIR)/data/data_b2.o $(OBJ_DIR)/data/data_b2b.o $(OBJ_DIR)/data/data_b2d.o $(OBJ_DIR)/data/data_b2d_mid2.o $(OBJ_DIR)/data/data_b2d_mid6.o $(OBJ_DIR)/data/data_b2d_mid3.o $(OBJ_DIR)/data/data_b2d_mid5.o $(OBJ_DIR)/data/data_b2d_mid.o $(OBJ_DIR)/data/data_b2d_mid4.o $(OBJ_DIR)/data/data_b2d_mid7.o $(OBJ_DIR)/data/data_b2d_rest.o $(OBJ_DIR)/data/data_b2c.o $(OBJ_DIR)/data/data_rest.o $(OBJ_DIR)/data/multiboot_ereader.o $(OBJ_DIR)/data/multiboot_berry_glitch_fix.o
OBJFILE := $(AS_OBJS) $(C_OBJECTS) $(DATA_OBJS)
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

# Text data tables are written as _("...") charmap strings (US style);
# run them through preproc so the kana/control bytes are encoded.
$(C_BUILDDIR)/data/text/%.o: src/data/text/%.c src/data/text/%.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/$*.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/$*.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/$*.gen.s

$(C_BUILDDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/$*.gen.s
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

$(OBJ_DIR)/data/data_tail.o: data/data_tail.s charmap.txt baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b.o: data/data_b.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b_tail.o: data/data_b_tail.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2.o: data/data_b2.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2b.o: data/data_b2b.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d.o: data/data_b2d.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid2.o: data/data_b2d_mid2.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid6.o: data/data_b2d_mid6.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid3.o: data/data_b2d_mid3.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid5.o: data/data_b2d_mid5.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid.o: data/data_b2d_mid.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid4.o: data/data_b2d_mid4.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid7.o: data/data_b2d_mid7.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_rest.o: data/data_b2d_rest.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2c.o: data/data_b2c.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_rest.o: data/data_rest.s baserom_jp.gba
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

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
