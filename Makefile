AS := tools/binutils/bin/arm-none-eabi-as
LD := tools/binutils/bin/arm-none-eabi-ld
OBJCOPY := tools/binutils/bin/arm-none-eabi-objcopy
SHA1SUM := sha1sum -c
TOOLS_DIR := tools
BIN2C := $(TOOLS_DIR)/bin2c/bin2c
GBAFIX := $(TOOLS_DIR)/gbafix/gbafix
GFX := $(TOOLS_DIR)/gbagfx/gbagfx
JSONPROC := $(TOOLS_DIR)/jsonproc/jsonproc
MAPJSON := $(TOOLS_DIR)/mapjson/mapjson
MID := $(TOOLS_DIR)/mid2agb/mid2agb
PREPROC := $(TOOLS_DIR)/preproc/preproc
RAMSCRGEN := $(TOOLS_DIR)/ramscrgen/ramscrgen
RSFONT := $(TOOLS_DIR)/rsfont/rsfont
SCANINC := $(TOOLS_DIR)/scaninc/scaninc
WAV2AGB := $(TOOLS_DIR)/wav2agb/wav2agb
AIF2PCM := $(TOOLS_DIR)/aif2pcm/aif2pcm
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

# Build host tools through the same dedicated makefile chain as pokeemerald.
include make_tools.mk

# Build flavor.  Keep the current decompilation build under
# build/pokeemerald-jp/; alternate builds (e.g. BUILD_NAME=pokeemerald-jp-rev10)
# get their own subdirectory under build/, like pokefirered's BUILD_NAME.
BUILD_NAME ?= pokeemerald-jp
OBJ_DIR := build/$(BUILD_NAME)

ASFILE := $(wildcard asm/*.s)
AS_OBJS := $(patsubst asm/%.s,$(OBJ_DIR)/asm/%.o,$(ASFILE))
# Assembly files that live under src/ like US pokeemerald
# (crt0.s, libgcnmultiboot.s, m4a_1.s).
C_ASM_SRCS := $(wildcard src/crt0.s src/libgcnmultiboot.s src/m4a_1.s src/agb_flash_rodata.s src/librfu_rodata.s src/libisagbprn_rodata.s src/libc/libc_rodata.s)
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

# Maps already migrated to the canonical map.json event-data structure.
# The event-only mode keeps this first slice reproducible while the complete
# JP layouts.json and map header/connection tables are migrated separately.
JP_STRUCTURED_MAPS := Route101 Route102 Route103 Route104 Route104_MrBrineysHouse Route104_PrettyPetalFlowerShop Route105 Route106 Route107 Route108 Route109 Route111_WinstrateFamilysHouse Route111_OldLadysRestStop Route112_CableCarStation MtChimney_CableCarStation Route114_FossilManiacsHouse Route114_FossilManiacsTunnel Route114_LanettesHouse Route116_TunnelersRestHouse Route117_PokemonDayCare Route121_SafariZoneEntrance MeteorFalls_1F_1R MeteorFalls_1F_2R MeteorFalls_B1F_1R MeteorFalls_B1F_2R RusturfTunnel Underwater_SootopolisCity DesertRuins GraniteCave_1F GraniteCave_B1F GraniteCave_B2F GraniteCave_StevensRoom PetalburgWoods MtChimney JaggedPass FieryPath Route123 Route124 Route125 Route126 Route127 Route128 Route129 Route130 Route131 Route132 Route133 Route134 \
	Underwater_Route105 Underwater_Route124 Underwater_Route125 Underwater_Route126 \
	Underwater_Route127 Underwater_Route128 Underwater_Route129 Underwater_Route134 \
	LittlerootTown_BrendansHouse_1F LittlerootTown_BrendansHouse_2F \
	LittlerootTown_MaysHouse_1F LittlerootTown_MaysHouse_2F \
	LittlerootTown_ProfessorBirchsLab \
	OldaleTown OldaleTown_House1 OldaleTown_House2 OldaleTown_Mart \
	OldaleTown_PokemonCenter_1F \
	OldaleTown_PokemonCenter_2F \
	DewfordTown \
	DewfordTown_PokemonCenter_1F \
	DewfordTown_PokemonCenter_2F \
	DewfordTown_Gym \
	DewfordTown_Hall \
	DewfordTown_House2 \
	LavaridgeTown \
	LavaridgeTown_HerbShop \
	LavaridgeTown_Gym_1F \
	LavaridgeTown_Gym_B1F \
	LavaridgeTown_House \
	LavaridgeTown_Mart \
	LavaridgeTown_PokemonCenter_1F \
	LavaridgeTown_PokemonCenter_2F \
	FallarborTown \
	FallarborTown_Mart \
	FallarborTown_BattleTentCorridor \
	FallarborTown_BattleTentBattleRoom \
	FallarborTown_PokemonCenter_1F \
	FallarborTown_PokemonCenter_2F \
	FallarborTown_CozmosHouse \
	FallarborTown_MoveRelearnersHouse \
	VerdanturfTown \
	VerdanturfTown_BattleTentLobby \
	VerdanturfTown_BattleTentCorridor \
	VerdanturfTown_BattleTentBattleRoom \
	VerdanturfTown_Mart \
	VerdanturfTown_PokemonCenter_1F \
	VerdanturfTown_PokemonCenter_2F \
	VerdanturfTown_WandasHouse \
	VerdanturfTown_FriendshipRatersHouse \
	VerdanturfTown_House \
	PacifidlogTown \
	PacifidlogTown_PokemonCenter_1F \
	PacifidlogTown_PokemonCenter_2F \
	PacifidlogTown_House1 \
	PacifidlogTown_House2 \
	PacifidlogTown_House3 \
	PacifidlogTown_House4 \
	PacifidlogTown_House5 \
	PetalburgCity \
	PetalburgCity_WallysHouse \
	PetalburgCity_House1 \
	PetalburgCity_House2 \
	PetalburgCity_PokemonCenter_1F \
	PetalburgCity_PokemonCenter_2F \
	PetalburgCity_Mart \
	SlateportCity \
	SlateportCity_SternsShipyard_1F \
	SlateportCity_SternsShipyard_2F \
	SlateportCity_BattleTentLobby \
	SlateportCity_BattleTentCorridor \
	SlateportCity_BattleTentBattleRoom \
	SlateportCity_NameRatersHouse \
	SlateportCity_PokemonFanClub \
	SlateportCity_OceanicMuseum_1F \
	SlateportCity_OceanicMuseum_2F \
	SlateportCity_Harbor \
	SlateportCity_House \
	SlateportCity_PokemonCenter_1F \
	SlateportCity_PokemonCenter_2F \
	SlateportCity_Mart \
	MauvilleCity \
	MauvilleCity_Gym \
	MauvilleCity_BikeShop \
	MauvilleCity_House1 \
	MauvilleCity_GameCorner \
	MauvilleCity_House2 \
	MauvilleCity_PokemonCenter_1F \
	MauvilleCity_PokemonCenter_2F \
	MauvilleCity_Mart \
	RustboroCity \
	RustboroCity_DevonCorp_1F \
	RustboroCity_DevonCorp_2F \
	RustboroCity_DevonCorp_3F \
	RustboroCity_Gym \
	RustboroCity_PokemonSchool \
	RustboroCity_PokemonCenter_1F \
	RustboroCity_PokemonCenter_2F \
	RustboroCity_Mart \
	RustboroCity_Flat1_1F \
	RustboroCity_Flat1_2F \
	RustboroCity_House1 \
	RustboroCity_CuttersHouse \
	RustboroCity_House2 \
	RustboroCity_Flat2_1F \
	RustboroCity_Flat2_2F \
	RustboroCity_Flat2_3F \
	RustboroCity_House3 \
	FortreeCity \
	FortreeCity_House1 \
	FortreeCity_Gym \
	FortreeCity_PokemonCenter_1F \
	FortreeCity_PokemonCenter_2F \
	FortreeCity_Mart \
	FortreeCity_House2 \
	FortreeCity_House3 \
	FortreeCity_House4 \
	FortreeCity_House5 \
	FortreeCity_DecorationShop \
	LilycoveCity \
	LilycoveCity_CoveLilyMotel_1F \
	LilycoveCity_CoveLilyMotel_2F \
	LilycoveCity_LilycoveMuseum_1F \
	LilycoveCity_LilycoveMuseum_2F \
	LilycoveCity_ContestLobby \
	LilycoveCity_ContestHall \
	LilycoveCity_PokemonCenter_1F \
	LilycoveCity_PokemonCenter_2F \
	LilycoveCity_UnusedMart \
	LilycoveCity_PokemonTrainerFanClub \
	LilycoveCity_Harbor \
	LilycoveCity_MoveDeletersHouse \
	LilycoveCity_House1 \
	LilycoveCity_House2 \
	LilycoveCity_House3 \
	LilycoveCity_House4 \
	LilycoveCity_DepartmentStore_1F \
	LilycoveCity_DepartmentStore_2F \
	LilycoveCity_DepartmentStore_3F \
	LilycoveCity_DepartmentStore_4F \
	LilycoveCity_DepartmentStore_5F \
	LilycoveCity_DepartmentStoreRooftop \
	LilycoveCity_DepartmentStoreElevator \
	MossdeepCity \
	MossdeepCity_Gym \
	MossdeepCity_House1 \
	MossdeepCity_House2 \
	MossdeepCity_PokemonCenter_1F \
	MossdeepCity_PokemonCenter_2F \
	MossdeepCity_Mart \
	MossdeepCity_House3 \
	MossdeepCity_StevensHouse \
	MossdeepCity_House4 \
	MossdeepCity_SpaceCenter_1F \
	MossdeepCity_SpaceCenter_2F \
	MossdeepCity_GameCorner_1F \
	MossdeepCity_GameCorner_B1F \
	SootopolisCity \
	SootopolisCity_Gym_1F \
	SootopolisCity_Gym_B1F \
	SootopolisCity_PokemonCenter_1F \
	SootopolisCity_PokemonCenter_2F \
	SootopolisCity_Mart \
	SootopolisCity_House1 \
	SootopolisCity_House2 \
	SootopolisCity_House3 \
	SootopolisCity_House4 \
	SootopolisCity_House5 \
	SootopolisCity_House6 \
	SootopolisCity_House7 \
	SootopolisCity_LotadAndSeedotHouse \
	SootopolisCity_MysteryEventsHouse_1F \
	SootopolisCity_MysteryEventsHouse_B1F \
	EverGrandeCity_SidneysRoom \
	EverGrandeCity_PhoebesRoom \
	EverGrandeCity_GlaciasRoom \
	EverGrandeCity_DrakesRoom \
	EverGrandeCity_ChampionsRoom \
	EverGrandeCity_PokemonLeague_1F \
	EverGrandeCity_HallOfFame \
	EverGrandeCity_PokemonCenter_1F \
	EverGrandeCity_PokemonCenter_2F \
	EverGrandeCity_PokemonLeague_2F \
	EverGrandeCity \
	LittlerootTown
JP_STRUCTURED_MAP_EVENTS := $(JP_STRUCTURED_MAPS:%=data/maps/%/events.inc)

$(JP_STRUCTURED_MAP_EVENTS): data/maps/%/events.inc: data/maps/%/map.json | tools
	$(MAPJSON) events emerald $< $(@D)

# This adjacent underwater-route family also owns its map headers and
# connections. The JP layout table is still centralized, so the local
# generator emits zero-byte compatibility aliases while keeping the canonical
# US-style header and connection sources beside each map.json.
JP_STRUCTURED_MAP_METADATA_MAPS := Underwater_Route124 Underwater_Route126 \
	Underwater_Route127 Underwater_Route128 Underwater_Route129
JP_STRUCTURED_MAP_HEADERS := $(JP_STRUCTURED_MAP_METADATA_MAPS:%=data/maps/%/header.inc)
JP_STRUCTURED_MAP_CONNECTIONS := $(JP_STRUCTURED_MAP_METADATA_MAPS:%=data/maps/%/connections.inc)
JP_STRUCTURED_MAP_METADATA := $(JP_STRUCTURED_MAP_HEADERS) $(JP_STRUCTURED_MAP_CONNECTIONS)

data/maps/%/header.inc data/maps/%/connections.inc &: data/maps/%/map.json tools/jp_map_metadata.py
	python3 tools/jp_map_metadata.py $< $(@D)

# These sources are included by data_b2d_mid30.s. State the ordering directly
# so a changed map.json cannot race its generated metadata during make -j.
$(OBJ_DIR)/data/data_b2d_mid30.o: $(JP_STRUCTURED_MAP_METADATA)

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
$(C_BUILDDIR)/diploma.o: CC1 = $(PREPROC) -i src/diploma.c charmap.txt | $(CC)
$(C_BUILDDIR)/landmark.o: CC1 = $(PREPROC) -i src/landmark.c charmap.txt | $(CC)
$(C_BUILDDIR)/pokedex_area_region_map.o: CC1 = $(PREPROC) -i src/pokedex_area_region_map.c charmap.txt | $(CC)
$(C_BUILDDIR)/pokedex_cry_screen.o: CC1 = $(PREPROC) -i src/pokedex_cry_screen.c charmap.txt | $(CC)
$(C_BUILDDIR)/move_relearner.o: CC1 = $(PREPROC) -i src/move_relearner.c charmap.txt | $(CC)
$(C_BUILDDIR)/pokeblock.o: CC1 = $(PREPROC) -i src/pokeblock.c charmap.txt | $(CC)
$(C_BUILDDIR)/battle_tower.o: CC1 = $(PREPROC) -i src/battle_tower.c charmap.txt | $(CC)
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

include sound/song_order.mk
SONG_OBJS := $(patsubst sound/songs/midi/%.s,$(OBJ_DIR)/sound/songs/midi/%.o,$(SONG_SRCS))

DATA_OBJS := $(OBJ_DIR)/data/event_scripts.o $(OBJ_DIR)/data/data.o $(OBJ_DIR)/data/data_b.o $(OBJ_DIR)/data/data_b_mid1.o $(OBJ_DIR)/data/data_b_mid2a.o $(OBJ_DIR)/data/data_b_mid2b.o $(OBJ_DIR)/data/data_b_mid2b3.o $(OBJ_DIR)/data/data_b_mid2b5.o $(OBJ_DIR)/data/data_b_mid2b6.o $(OBJ_DIR)/data/data_b2.o $(OBJ_DIR)/data/data_b2b.o $(OBJ_DIR)/data/data_b2d.o $(OBJ_DIR)/data/data_b2d_mid47.o $(OBJ_DIR)/data/data_b2d_mid51.o $(OBJ_DIR)/data/data_b2d_mid30.o $(OBJ_DIR)/data/data_b2d_mid28.o $(OBJ_DIR)/data/data_b2d_mid26.o $(OBJ_DIR)/data/data_b2d_mid15.o $(OBJ_DIR)/data/data_b2d_mid54.o $(OBJ_DIR)/data/data_b2d_mid55.o $(OBJ_DIR)/data/data_b2d_mid56.o $(OBJ_DIR)/data/data_b2d_mid57_b.o $(OBJ_DIR)/data/data_b2d_mid58.o $(OBJ_DIR)/data/data_b2d_mid59.o $(OBJ_DIR)/data/data_b2d_mid37.o $(OBJ_DIR)/data/data_b2d_mid60.o $(OBJ_DIR)/data/data_b2d_mid61.o $(OBJ_DIR)/data/data_b2d_mid62.o $(OBJ_DIR)/data/data_b2d_mid38.o $(OBJ_DIR)/data/data_b2d_mid33.o $(OBJ_DIR)/data/data_b2d_mid32.o $(OBJ_DIR)/data/data_b2d_mid65.o $(OBJ_DIR)/data/battle_transition_tilemaps.o $(OBJ_DIR)/data/data_b2d_rest.o $(OBJ_DIR)/data/data_b2d_mid69.o $(OBJ_DIR)/data/data_b2d_mid70.o $(OBJ_DIR)/data/data_b2d_mid98.o $(OBJ_DIR)/data/data_b2d_mid100.o $(OBJ_DIR)/data/mystery_gift.o $(OBJ_DIR)/data/sound_data.o $(OBJ_DIR)/data/rom_padding.o $(OBJ_DIR)/data/battle_textbox.o $(OBJ_DIR)/data/data_b2d_gfx_pokemon_none.o $(OBJ_DIR)/data/data_rest2b.o $(OBJ_DIR)/data/data_b2d_gfx_pokemon_main.o $(OBJ_DIR)/data/data_rest2c.o $(OBJ_DIR)/data/data_b2d_gfx_front.o $(OBJ_DIR)/data/multiboot_ereader.o $(OBJ_DIR)/data/multiboot_berry_glitch_fix.o
# Migrated data files now build from C or no longer contribute data.
DATA_OBJS := $(filter-out $(OBJ_DIR)/data/data_b_mid2a.o $(OBJ_DIR)/data/data_b_mid2b.o $(OBJ_DIR)/data/data_b_mid2b5.o $(OBJ_DIR)/data/data_b_mid2b6.o $(OBJ_DIR)/data/data_b2d_mid55.o $(OBJ_DIR)/data/data_b2d_mid56.o $(OBJ_DIR)/data/data_b2d_mid57_b.o $(OBJ_DIR)/data/data_b2d_mid58.o $(OBJ_DIR)/data/data_b2d_mid59.o $(OBJ_DIR)/data/data_b2d_mid62.o,$(DATA_OBJS))
DATA_OBJS += $(OBJ_DIR)/data/battle_transition_regis_resources.o
DATA_OBJS += $(OBJ_DIR)/data/battle_transition_legendary_resources.o
DATA_OBJS += $(OBJ_DIR)/data/battle_transition_frontier_resources.o
DATA_OBJS += $(OBJ_DIR)/data/battle_transition_pre_regi_resources.o

OBJFILE := $(AS_OBJS) $(C_ASM_OBJS) $(C_OBJECTS) $(SONG_OBJS) $(DATA_OBJS)
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

clean: clean-tools
	rm -rf build $(ROM) $(ELF)

# All build artifacts wait for the host-tool chain, so a fresh checkout can
# safely use `make -j` without racing the C/asset rules against tool builds.
$(OBJFILE) $(ELF) $(ROM): | tools

# Match pokeemerald's generic LZ77 asset rule.  Individual C targets declare
# their generated .lz prerequisites so a clean checkout rebuilds them safely.
%.lz: % | tools
	$(GFX) $< $@

%.4bpp: %.png | tools
	$(GFX) $< $@

%.gbapal: %.pal | tools
	$(GFX) $< $@

%.gbapal: %.png | tools
	$(GFX) $< $@

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

$(SONG_OBJS): $(OBJ_DIR)/sound/songs/midi/%.o: sound/songs/midi/%.s
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

$(C_BUILDDIR)/pokenav_match_call_gfx.o: src/pokenav_match_call_gfx.c $(wildcard graphics/pokenav/match_call/*.lz graphics/pokenav/match_call/*.gbapal)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokenav_match_call_gfx.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokenav_match_call_gfx.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokenav_match_call_gfx.gen.s

$(C_BUILDDIR)/battle_script_commands.o: src/battle_script_commands.c charmap.txt \
	graphics/battle_interface/level_up_banner.png.4bpp.lz \
	graphics/battle_interface/level_up_banner.png.gbapal
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/battle_script_commands.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/battle_script_commands.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/battle_script_commands.gen.s

$(C_BUILDDIR)/pokenav_region_map.o: src/pokenav_region_map.c src/data/region_map/city_map_tilemaps.h $(wildcard graphics/pokenav/region_map/*.lz graphics/pokenav/region_map/*.gbapal graphics/pokenav/region_map/city_maps/*.lz)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokenav_region_map.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokenav_region_map.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokenav_region_map.gen.s

$(C_BUILDDIR)/field_specials.o: src/field_specials.c src/data/field_specials.h $(wildcard data/field_specials/jp/*)
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
$(C_BUILDDIR)/pokenav_conditions_gfx.o: src/pokenav_conditions_gfx.c $(wildcard graphics/pokenav/condition/* graphics/pokenav/options/options.bin)
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
$(C_BUILDDIR)/battle_transition_frontier.o: src/battle_transition_frontier.c $(wildcard graphics/battle_transitions/frontier_logo_center.* graphics/battle_transitions/frontier_logo_circles.*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/battle_transition_frontier.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/battle_transition_frontier.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/battle_transition_frontier.gen.s
$(C_BUILDDIR)/mystery_event_msg.o: src/mystery_event_msg.c charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/mystery_event_msg.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/mystery_event_msg.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/mystery_event_msg.gen.s
graphics/summary_screen/%.png.4bpp: graphics/summary_screen/%.png | tools
	$(GFX) $< $@
$(C_BUILDDIR)/pokemon_summary_screen.o: src/pokemon_summary_screen.c graphics/summary_screen/a_button.png.4bpp graphics/summary_screen/b_button.png.4bpp
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokemon_summary_screen.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokemon_summary_screen.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokemon_summary_screen.gen.s
$(C_BUILDDIR)/graphics.o: src/graphics.c src/data/graphics/berries.h src/data/graphics/pokeballs.h src/data/text_window.h src/data/scrcmd_data.h \
	graphics/text_window/message_box_jp.4bpp \
	graphics/balls/poke.4bpp.lz graphics/balls/poke.gbapal.lz \
	graphics/balls/great.4bpp.lz graphics/balls/great.gbapal.lz \
	graphics/balls/safari.4bpp.lz graphics/balls/safari.gbapal.lz \
	graphics/balls/ultra.4bpp.lz graphics/balls/ultra.gbapal.lz \
	graphics/balls/master.4bpp.lz graphics/balls/master.gbapal.lz \
	graphics/balls/net.4bpp.lz graphics/balls/net.gbapal.lz \
	graphics/balls/dive.4bpp.lz graphics/balls/dive.gbapal.lz \
	graphics/balls/nest.4bpp.lz graphics/balls/nest.gbapal.lz \
	graphics/balls/repeat.4bpp.lz graphics/balls/repeat.gbapal.lz \
	graphics/balls/timer.4bpp.lz graphics/balls/timer.gbapal.lz \
	graphics/balls/luxury.4bpp.lz graphics/balls/luxury.gbapal.lz \
	graphics/balls/premier.4bpp.lz graphics/balls/premier.gbapal.lz \
	graphics/balls/open.4bpp.lz \
	graphics/summary_screen/effect_battle.bin graphics/summary_screen/effect_contest.bin graphics/summary_screen/effect_cancel.bin \
	graphics/pokedex/start_menu_main.bin.lz graphics/pokedex/start_menu_search_results.bin.lz \
	graphics/pokedex/list.bin.lz graphics/pokedex/list_underlay.bin.lz \
	graphics/pokedex/info_screen.bin.lz graphics/pokedex/cry_screen.bin.lz \
	graphics/pokedex/size_screen.bin.lz graphics/pokedex/screen_select_bar_main.bin.lz \
	graphics/pokedex/screen_select_bar_submenu.bin.lz graphics/pokedex/menu.4bpp.lz \
	graphics/pokedex/interface.4bpp.lz \
	graphics/intro/scene_2/player.pal.gbapal \
	graphics/intro/scene_2/volbeat.png.gbapal graphics/intro/scene_2/torchic.png.gbapal \
	graphics/intro/scene_2/manectric.png.gbapal graphics/intro/scene_2/flygon.png.gbapal \
	graphics/intro/scene_2/volbeat.png.4bpp.lz graphics/intro/scene_2/torchic.png.4bpp.lz \
	graphics/intro/scene_2/manectric.png.4bpp.lz graphics/intro/scene_2/flygon.png.4bpp.lz \
	graphics/intro/scene_2/brendan.png.4bpp.lz graphics/intro/scene_2/may.png.4bpp.lz \
	graphics/intro/scene_3/groudon.8bpp.lz graphics/intro/scene_3/groudon.bin.lz \
	graphics/intro/scene_3/kyogre.8bpp.lz graphics/intro/scene_3/kyogre.bin.lz \
	graphics/intro/scene_3/legend_bg.4bpp.lz graphics/intro/scene_3/groudon_bg.bin.lz \
	graphics/intro/scene_3/kyogre_bg.bin.lz graphics/intro/scene_3/clouds.4bpp.lz \
	graphics/intro/scene_3/clouds_left.bin.lz graphics/intro/scene_3/clouds_right.bin.lz \
	graphics/intro/scene_3/clouds_sun.bin.lz \
	graphics/intro/scene_3/rayquaza.4bpp.lz graphics/intro/scene_3/rayquaza.bin.lz \
	graphics/intro/scene_3/unused_1.bin.lz graphics/intro/scene_3/unused_2.bin.lz \
	graphics/intro/scene_3/rayquaza_clouds.4bpp.lz graphics/intro/scene_3/rayquaza_clouds.bin.lz \
	graphics/intro/scene_3/lightning.png.4bpp.lz graphics/intro/scene_3/lightning.png.gbapal \
	graphics/intro/scene_3/bubbles.png.4bpp.lz graphics/intro/scene_3/bubbles.png.gbapal \
	graphics/intro/scene_1/flygon.png.4bpp.lz graphics/intro/scene_1/sparkle.png.4bpp.lz \
	graphics/battle_anims/sprites/flying_dirt.4bpp.lz graphics/battle_anims/sprites/flying_dirt.gbapal.lz \
	graphics/battle_anims/backgrounds/sandstorm_brew.bin.lz graphics/battle_anims/backgrounds/sandstorm_brew.4bpp.lz \
	graphics/battle_anims/sprites/metal_sound_waves.4bpp.lz graphics/battle_anims/sprites/metal_sound_waves.gbapal.lz \
	graphics/battle_anims/backgrounds/ice.4bpp.lz graphics/battle_anims/backgrounds/ice.gbapal.lz \
	graphics/battle_anims/backgrounds/ice.bin.lz graphics/battle_anims/sprites/icicle_spear.4bpp.lz \
	graphics/battle_anims/sprites/icicle_spear.gbapal.lz \
	graphics/contest/nextturn.4bpp.lz graphics/contest/nextturn_numbers.4bpp \
	graphics/contest/nextturn_random.4bpp \
	graphics/contest/applause.4bpp.lz graphics/contest/applause_meter.4bpp \
	graphics/contest/nextturn.gbapal \
	graphics/battle_anims/sprites/splash.4bpp.lz graphics/battle_anims/sprites/splash.gbapal.lz \
	graphics/battle_anims/sprites/sweat_bead.4bpp.lz graphics/battle_anims/sprites/pokeblock.4bpp.lz \
	graphics/battle_anims/sprites/pokeblock.gbapal.lz graphics/battle_anims/sprites/gem_1.4bpp.lz \
	graphics/battle_anims/sprites/gem_2.4bpp.lz graphics/battle_anims/sprites/gem_3.4bpp.lz \
	graphics/battle_anims/sprites/gem_1.gbapal.lz graphics/battle_anims/backgrounds/in_air.4bpp.lz \
	graphics/battle_anims/backgrounds/in_air.gbapal.lz graphics/battle_anims/backgrounds/in_air.bin.lz \
	graphics/battle_anims/sprites/protect.4bpp.lz graphics/battle_anims/sprites/protect.gbapal.lz \
	graphics/battle_anims/backgrounds/water_muddy.gbapal.lz graphics/battle_interface/ball_status_bar.4bpp.lz \
	graphics/pokemon/egg/icon.4bpp graphics/battle_anims/backgrounds/ghost.4bpp.lz \
	graphics/battle_anims/backgrounds/ghost.gbapal.lz graphics/battle_anims/backgrounds/ghost.bin.lz \
	graphics/battle_anims/sprites/whip_hit.gbapal.lz graphics/battle_anims/backgrounds/solarbeam.gbapal.lz \
	graphics/battle_anims/backgrounds/solarbeam.bin.lz \
	graphics/battle_anims/backgrounds/cosmic.gbapal.lz graphics/battle_anims/backgrounds/cosmic.4bpp.lz \
	graphics/battle_anims/backgrounds/cosmic.bin.lz graphics/battle_anims/sprites/slam_hit_2.gbapal.lz \
	graphics/battle_anims/sprites/slam_hit_2.4bpp.lz \
	graphics/battle_anims/backgrounds/fog.bin.lz graphics/battle_anims/sprites/weather_ball.gbapal.lz \
	graphics/battle_anims/sprites/weather_ball.4bpp.lz graphics/battle_anims/backgrounds/scary_face_player.bin.lz \
	graphics/battle_anims/backgrounds/scary_face_opponent.bin.lz graphics/battle_anims/backgrounds/scary_face_contest.bin.lz \
	graphics/battle_anims/sprites/hail.4bpp.lz graphics/battle_anims/sprites/hail.gbapal.lz \
	graphics/battle_anims/sprites/green_spike.4bpp.lz graphics/battle_anims/sprites/green_spike.gbapal.lz \
	graphics/battle_anims/sprites/white_circle_of_light.gbapal.lz graphics/battle_anims/sprites/glowy_blue_orb.gbapal.lz \
	graphics/battle_anims/sprites/recycle.4bpp.lz graphics/battle_anims/sprites/recycle.gbapal.lz \
	graphics/battle_anims/sprites/red_particles.4bpp.lz graphics/battle_anims/sprites/red_particles.gbapal.lz \
	graphics/battle_anims/sprites/dirt_mound.4bpp.lz graphics/battle_anims/sprites/dirt_mound.gbapal.lz \
	graphics/battle_anims/backgrounds/fissure.4bpp.lz graphics/battle_anims/backgrounds/fissure.gbapal.lz \
	graphics/battle_anims/backgrounds/fissure.bin.lz graphics/battle_anims/sprites/bird.4bpp.lz \
	graphics/battle_anims/sprites/bird.gbapal.lz graphics/battle_anims/sprites/cross_impact.4bpp.lz \
	graphics/battle_anims/sprites/cross_impact.gbapal.lz \
	graphics/battle_anims/backgrounds/water.4bpp.lz graphics/battle_anims/backgrounds/water.gbapal.lz \
	graphics/battle_anims/backgrounds/water_opponent.bin.lz graphics/battle_anims/backgrounds/water_player.bin.lz \
	graphics/battle_anims/backgrounds/water_contest.bin.lz graphics/battle_anims/sprites/slash_2.gbapal.lz \
	graphics/battle_anims/sprites/white_shadow.4bpp.lz graphics/battle_anims/sprites/white_shadow.gbapal.lz \
	graphics/party_menu/bg.4bpp.lz graphics/party_menu/bg.gbapal.lz graphics/party_menu/bg.bin.lz \
	graphics/party_menu/pokeball.4bpp.lz graphics/party_menu/pokeball_small.4bpp.lz graphics/party_menu/pokeball.gbapal.lz \
	graphics/interface/status_icons.4bpp.lz graphics/interface/status_icons.gbapal.lz \
	graphics/types/move_types.4bpp.lz graphics/types/move_types.gbapal.lz \
	graphics/summary_screen/move_select.4bpp.lz graphics/summary_screen/move_select.gbapal.lz \
	graphics/summary_screen/tiles.4bpp.lz graphics/summary_screen/tiles.gbapal.lz \
	graphics/summary_screen/page_info.bin.lz graphics/summary_screen/page_skills.bin.lz \
	graphics/summary_screen/page_battle_moves.bin.lz graphics/summary_screen/page_contest_moves.bin.lz \
	graphics/summary_screen/page_info_egg.bin.lz \
	graphics/shop/menu.4bpp.lz graphics/shop/menu.gbapal.lz graphics/shop/menu.bin.lz graphics/shop/money.4bpp.lz \
	$(wildcard graphics/bag/* graphics/berries/* graphics/pokeblock/* graphics/pokenav/*.lz graphics/pokenav/*.gbapal graphics/pokenav/left_headers/*.lz graphics/pokenav/left_headers/*.gbapal graphics/unused/cherry.* graphics/unused/jp/menu_specialized/* graphics/pokemon/icon_palettes/*.gbapal)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/graphics.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/graphics.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/graphics.gen.s
$(C_BUILDDIR)/berry_crush.o: src/berry_crush.c graphics/berry_crush/gBerryCrush_Crusher_Pal.bin graphics/berry_crush/gBerryCrush_Crusher_Gfx.bin graphics/berry_crush/sCrusherTop_Tilemap.bin graphics/misc/sContainerCap_Tilemap.bin graphics/misc/sBg_Tilemap.bin graphics/naming_screen/sPlayerNameWindowGfx.bin
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/berry_crush.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/berry_crush.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/berry_crush.gen.s
$(C_BUILDDIR)/dodrio_berry_picking.o: src/dodrio_berry_picking.c graphics/misc/sBg_Pal.bin graphics/dodrio/sDodrioNormalPal.bin graphics/dodrio/sDodrioShinyPal.bin graphics/misc/sBerry_Gfx.bin graphics/misc/sBg_Gfx.bin graphics/misc/sTreeBorder_Gfx.bin graphics/battle_anims/sStatus_Gfx.bin graphics/misc/sCloud_Gfx.bin graphics/dodrio/sDodrio_Gfx.bin graphics/dodrio/sDodrioBg_Tilemap.bin graphics/misc/sTreeBorderRight_Tilemap.bin graphics/misc/sTreeBorderLeft_Tilemap.bin
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/dodrio_berry_picking.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/dodrio_berry_picking.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/dodrio_berry_picking.gen.s

$(C_BUILDDIR)/map_name_popup.o: src/map_name_popup.c $(wildcard graphics/map_popup/*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/map_name_popup.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/map_name_popup.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/map_name_popup.gen.s
$(C_BUILDDIR)/item_menu_icons.o: src/item_menu_icons.c $(wildcard graphics/bag/rotating_ball.* graphics/unused/cherry.*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/item_menu_icons.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/item_menu_icons.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/item_menu_icons.gen.s
$(C_BUILDDIR)/pokenav_menu_handler_gfx.o: src/pokenav_menu_handler_gfx.c $(wildcard graphics/pokenav/*.lz graphics/pokenav/*.gbapal)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokenav_menu_handler_gfx.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokenav_menu_handler_gfx.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokenav_menu_handler_gfx.gen.s

$(C_BUILDDIR)/pokenav_list.o: src/pokenav_list.c graphics/pokenav/list_arrows.gbapal graphics/pokenav/list_arrows.4bpp.lz
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokenav_list.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokenav_list.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokenav_list.gen.s




$(C_BUILDDIR)/pokenav_match_call_list.o: src/pokenav_match_call_list.c src/data/text/match_call_messages.h charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokenav_match_call_list.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokenav_match_call_list.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokenav_match_call_list.gen.s

$(C_BUILDDIR)/menu_specialized.o: src/menu_specialized.c charmap.txt $(wildcard graphics/pokenav/condition/*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/menu_specialized.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/menu_specialized.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/menu_specialized.gen.s

$(C_BUILDDIR)/pokenav_match_call_data.o: src/pokenav_match_call_data.c charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokenav_match_call_data.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokenav_match_call_data.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokenav_match_call_data.gen.s

$(C_BUILDDIR)/trainer_hill.o: src/trainer_hill.c src/data/battle_frontier/trainer_hill.h charmap.txt graphics/trainer_hill/ereader.gbapal $(wildcard graphics/trainer_hill/maps_jp/floor_?/*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/trainer_hill.gen.s
	@awk '/^\.Lfe[0-9]:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/trainer_hill.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/trainer_hill.gen.s

$(C_BUILDDIR)/data/trainer_hill_templates.o: src/data/trainer_hill_templates.c charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/trainer_hill_templates.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/trainer_hill_templates.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/trainer_hill_templates.gen.s

$(C_BUILDDIR)/data/trade.o: src/data/trade.c src/data/trade.h $(wildcard graphics/trade/jp/menu/* graphics/trade/jp/animation/*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/trade.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/trade.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/trade.gen.s

$(C_BUILDDIR)/data/berry_blender.o: src/data/berry_blender.c src/data/berry_blender.h $(wildcard graphics/berry_blender/jp/*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/berry_blender.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/berry_blender.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/berry_blender.gen.s

$(C_BUILDDIR)/start_menu.o: src/start_menu.c src/data/start_menu.h $(wildcard data/start_menu/jp/*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/start_menu.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/start_menu.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/start_menu.gen.s

$(C_BUILDDIR)/contest.o: src/contest.c src/data/contest_opponents.h src/data/contest_text_tables.h charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/contest.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/contest.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/contest.gen.s

$(C_BUILDDIR)/berry.o: src/berry.c charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/berry.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/berry.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/berry.gen.s

# JP fixed-width default names in strings.c use _()/__() charmap literals.
$(C_BUILDDIR)/strings.o: src/strings.c charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/strings.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/strings.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/strings.gen.s

$(C_BUILDDIR)/data/battle_records.o: src/data/battle_records.c src/data/battle_records.h $(wildcard graphics/trainer_hill/* data/battle_records/jp/*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/battle_records.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/battle_records.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/battle_records.gen.s

$(C_BUILDDIR)/data/reset_rtc_screen.o: src/data/reset_rtc_screen.c src/data/reset_rtc_screen.h $(wildcard graphics/reset_rtc_screen/* data/reset_rtc_screen/jp/*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/reset_rtc_screen.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/reset_rtc_screen.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/reset_rtc_screen.gen.s

$(C_BUILDDIR)/data/slot_machine.o: src/data/slot_machine.c src/data/slot_machine.h $(wildcard graphics/slot_machine/* data/slot_machine/jp/*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/slot_machine.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/slot_machine.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/slot_machine.gen.s

$(C_BUILDDIR)/data/pokedex.o: src/data/pokedex.c src/data/pokedex.h src/data/pokemon/pokedex_orders.h \
	$(wildcard data/pokedex/jp/*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/pokedex.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/pokedex.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/pokedex.gen.s

$(C_BUILDDIR)/data/trainer_card.o: src/data/trainer_card.c src/data/trainer_card.h $(wildcard graphics/trainer_card/jp/* data/trainer_card/jp/*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/trainer_card.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/trainer_card.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/trainer_card.gen.s

$(C_BUILDDIR)/data/frontier_pass.o: src/data/frontier_pass.c src/data/frontier_pass.h $(wildcard graphics/frontier_pass/* data/frontier_pass/jp/*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/frontier_pass.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/frontier_pass.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/frontier_pass.gen.s

$(C_BUILDDIR)/data/pokemon_storage_system.o: src/data/pokemon_storage_system.c src/data/pokemon_storage_system.h $(shell find graphics/pokemon_storage data/pokemon_storage/jp -type f 2>/dev/null)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/pokemon_storage_system.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/pokemon_storage_system.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/pokemon_storage_system.gen.s

$(C_BUILDDIR)/pokedex_cry_screen.o: \
	graphics/pokedex/cry_meter_needle.4bpp \
	graphics/pokedex/cry_meter_needle.gbapal \
	graphics/pokedex/cry_meter_map.bin \
	graphics/pokedex/cry_meter.gbapal \
	graphics/pokedex/cry_meter.4bpp.lz \
	graphics/pokedex/cry_screen_bg.gbapal \
	graphics/pokedex/cry_screen_bg.4bpp

$(C_BUILDDIR)/move_relearner.o: \
	graphics/interface/ui_learn_move.4bpp \
	graphics/interface/ui_learn_move.gbapal

$(C_BUILDDIR)/cable_car.o: src/cable_car.c $(wildcard graphics/cable_car/*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/cable_car.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/cable_car.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/cable_car.gen.s

$(C_BUILDDIR)/intro.o: src/intro.c \
	graphics/intro/scene_1/drops.png.gbapal \
	graphics/intro/scene_1/logo.png.gbapal \
	graphics/intro/scene_1/drops_logo.png.4bpp.lz \
	graphics/intro/scene_1/bg.png.gbapal \
	graphics/intro/scene_1/bg0_map.bin.lz \
	graphics/intro/scene_1/bg1_map.bin.lz \
	graphics/intro/scene_1/bg2_map.bin.lz \
	graphics/intro/scene_1/bg3_map.bin.lz \
	graphics/intro/scene_1/bg.png.4bpp.lz \
	graphics/intro/scene_3/pokeball.png.gbapal \
	graphics/intro/scene_3/pokeball_map.bin.lz \
	graphics/intro/scene_3/pokeball.png.8bpp.lz \
	graphics/intro/scene_3/streaks.png.gbapal \
	graphics/intro/scene_3/streaks.png.4bpp.lz \
	graphics/intro/scene_3/streaks_map.bin.lz \
	graphics/intro/scene_3/rayquaza_orb.png.gbapal \
	graphics/intro/scene_3/misc.png.gbapal \
	graphics/intro/scene_3/misc.png.4bpp.lz \
	graphics/intro/scene_1/flygon.png.gbapal \
	graphics/intro/scene_1/lati.png.4bpp.lz
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/intro.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/intro.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/intro.gen.s

$(C_BUILDDIR)/field_region_map.o: src/field_region_map.c charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/field_region_map.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/field_region_map.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/field_region_map.gen.s

$(C_BUILDDIR)/option_menu.o: src/option_menu.c charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/option_menu.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/option_menu.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/option_menu.gen.s

$(C_BUILDDIR)/hall_of_fame.o: src/hall_of_fame.c charmap.txt \
	graphics/misc/japanese_hof.gbapal \
	graphics/misc/japanese_hof.4bpp.lz
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/hall_of_fame.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/hall_of_fame.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/hall_of_fame.gen.s

$(C_BUILDDIR)/credits.o: src/credits.c src/data/credits.h charmap.txt \
	graphics/credits/credits.gbapal \
	graphics/credits/the_end_copyright.4bpp.lz
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/credits.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/credits.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/credits.gen.s

$(C_BUILDDIR)/diploma.o: src/diploma.c charmap.txt \
	graphics/diploma/national.gbapal \
	graphics/diploma/hoenn.gbapal \
	graphics/diploma/tilemap.bin.lz \
	graphics/diploma/tiles.4bpp.lz
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/diploma.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/diploma.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/diploma.gen.s

$(C_BUILDDIR)/event_object_movement.o: src/event_object_movement.c src/data/object_events/object_event_graphics.h charmap.txt \
	graphics/field_effects/pics/cut_grass.4bpp graphics/field_effects/palettes/cut_grass.gbapal \
	graphics/object_events/pics/people/brendan/walking.4bpp graphics/object_events/pics/people/brendan/running.4bpp \
	graphics/object_events/palettes/brendan.gbapal \
	graphics/object_events/pics/people/ruby_sapphire_brendan/walking.4bpp \
	graphics/object_events/pics/people/ruby_sapphire_brendan/running.4bpp \
	graphics/object_events/palettes/ruby_sapphire_brendan.gbapal \
	graphics/object_events/palettes/brendan_reflection.gbapal graphics/object_events/palettes/bridge_reflection.gbapal \
	graphics/object_events/pics/people/brendan/field_move.4bpp graphics/object_events/pics/people/brendan/surfing.4bpp \
	graphics/object_events/pics/people/brendan/mach_bike.4bpp graphics/object_events/pics/people/brendan/acro_bike.4bpp \
	graphics/object_events/pics/people/brendan/fishing.4bpp graphics/object_events/pics/people/brendan/watering.4bpp \
	graphics/object_events/pics/people/brendan/decorating.4bpp graphics/object_events/pics/people/may/decorating.4bpp \
	graphics/object_events/pics/people/brendan/underwater.4bpp graphics/object_events/pics/people/may/underwater.4bpp \
	graphics/object_events/palettes/player_underwater.gbapal \
	graphics/object_events/pics/people/may/walking.4bpp graphics/object_events/pics/people/may/running.4bpp \
	graphics/object_events/palettes/may.gbapal graphics/object_events/palettes/may_reflection.gbapal \
	graphics/object_events/pics/people/ruby_sapphire_may/walking.4bpp \
	graphics/object_events/pics/people/ruby_sapphire_may/running.4bpp \
	graphics/object_events/palettes/ruby_sapphire_may.gbapal graphics/object_events/palettes/unused_palette.gbapal \
	graphics/object_events/pics/people/may/mach_bike.4bpp graphics/object_events/pics/people/may/acro_bike.4bpp \
	graphics/object_events/pics/people/may/surfing.4bpp graphics/object_events/pics/people/may/field_move.4bpp \
	graphics/object_events/pics/people/may/fishing.4bpp graphics/object_events/pics/people/may/watering.4bpp \
	graphics/object_events/palettes/npc_1.gbapal graphics/object_events/palettes/npc_2.gbapal \
	graphics/object_events/palettes/npc_3.gbapal graphics/object_events/palettes/npc_4.gbapal \
	graphics/object_events/palettes/npc_1_reflection.gbapal graphics/object_events/palettes/npc_2_reflection.gbapal \
	graphics/object_events/palettes/npc_3_reflection.gbapal graphics/object_events/palettes/npc_4_reflection.gbapal \
	graphics/object_events/pics/people/ninja_boy.4bpp graphics/object_events/pics/people/twin.4bpp \
	graphics/object_events/pics/people/boy_1.4bpp graphics/object_events/pics/people/girl_1.4bpp \
	graphics/object_events/pics/people/boy_2.4bpp graphics/object_events/pics/people/girl_2.4bpp \
	graphics/object_events/pics/people/little_boy.4bpp graphics/object_events/pics/people/little_girl.4bpp \
	graphics/object_events/pics/people/boy_3.4bpp graphics/object_events/pics/people/girl_3.4bpp \
	graphics/object_events/pics/people/rich_boy.4bpp graphics/object_events/pics/people/woman_1.4bpp \
	graphics/object_events/pics/people/fat_man.4bpp graphics/object_events/pics/people/pokefan_f.4bpp \
	graphics/object_events/pics/people/man_1.4bpp graphics/object_events/pics/people/woman_2.4bpp \
	graphics/object_events/pics/people/expert_m.4bpp graphics/object_events/pics/people/expert_f.4bpp \
	graphics/object_events/pics/people/man_2.4bpp graphics/object_events/pics/people/woman_3.4bpp \
	graphics/object_events/pics/people/pokefan_m.4bpp graphics/object_events/pics/people/woman_4.4bpp \
	graphics/object_events/pics/people/cook.4bpp graphics/object_events/pics/people/link_receptionist.4bpp \
	graphics/object_events/pics/people/old_man.4bpp graphics/object_events/pics/people/old_woman.4bpp \
	graphics/object_events/pics/people/camper.4bpp graphics/object_events/pics/people/picnicker.4bpp \
	graphics/object_events/pics/people/man_3.4bpp graphics/object_events/pics/people/woman_5.4bpp \
	graphics/object_events/pics/people/youngster.4bpp graphics/object_events/pics/people/bug_catcher.4bpp \
	graphics/object_events/pics/people/psychic_m.4bpp graphics/object_events/pics/people/school_kid_m.4bpp \
	graphics/object_events/pics/people/maniac.4bpp graphics/object_events/pics/people/hex_maniac.4bpp \
	graphics/object_events/pics/people/unused_woman.4bpp graphics/object_events/pics/people/swimmer_m.4bpp \
	graphics/object_events/pics/people/swimmer_f.4bpp graphics/object_events/pics/people/black_belt.4bpp \
	graphics/object_events/pics/people/beauty.4bpp graphics/object_events/pics/people/scientist_1.4bpp \
	graphics/object_events/pics/people/lass.4bpp graphics/object_events/pics/people/gentleman.4bpp \
	graphics/object_events/pics/people/sailor.4bpp graphics/object_events/pics/people/fisherman.4bpp \
	graphics/object_events/pics/people/running_triathlete_m.4bpp graphics/object_events/pics/people/running_triathlete_f.4bpp \
	graphics/object_events/pics/people/tuber_f.4bpp graphics/object_events/pics/people/tuber_m.4bpp \
	graphics/object_events/pics/people/hiker.4bpp graphics/object_events/pics/people/cycling_triathlete_m.4bpp \
	graphics/object_events/pics/people/cycling_triathlete_f.4bpp graphics/object_events/pics/people/man_4.4bpp \
	graphics/object_events/pics/people/man_5.4bpp graphics/object_events/pics/people/nurse.4bpp \
	graphics/object_events/pics/misc/item_ball.4bpp graphics/object_events/pics/people/prof_birch.4bpp \
	graphics/object_events/pics/people/reporter_m.4bpp graphics/object_events/pics/people/reporter_f.4bpp \
	graphics/object_events/pics/people/mauville_old_man_1.4bpp graphics/object_events/pics/people/mauville_old_man_2.4bpp \
	graphics/object_events/pics/people/mart_employee.4bpp graphics/object_events/pics/people/rooftop_sale_woman.4bpp \
	graphics/object_events/pics/people/teala.4bpp graphics/object_events/pics/people/artist.4bpp \
	graphics/object_events/pics/people/cameraman.4bpp graphics/object_events/pics/people/scientist_2.4bpp \
	graphics/object_events/pics/people/devon_employee.4bpp graphics/object_events/pics/people/team_aqua/aqua_member_m.4bpp \
	graphics/object_events/pics/people/team_aqua/aqua_member_f.4bpp graphics/object_events/pics/people/team_magma/magma_member_m.4bpp \
	graphics/object_events/pics/people/team_magma/magma_member_f.4bpp graphics/object_events/pics/people/elite_four/sidney.4bpp \
	graphics/object_events/pics/people/elite_four/phoebe.4bpp graphics/object_events/pics/people/elite_four/glacia.4bpp \
	graphics/object_events/pics/people/elite_four/drake.4bpp graphics/object_events/pics/people/gym_leaders/roxanne.4bpp \
	graphics/object_events/pics/people/gym_leaders/brawly.4bpp graphics/object_events/pics/people/gym_leaders/wattson.4bpp \
	graphics/object_events/pics/people/gym_leaders/flannery.4bpp graphics/object_events/pics/people/gym_leaders/norman.4bpp \
	graphics/object_events/pics/people/gym_leaders/winona.4bpp graphics/object_events/pics/people/gym_leaders/liza.4bpp \
	graphics/object_events/pics/people/gym_leaders/tate.4bpp graphics/object_events/pics/people/wallace.4bpp \
	graphics/object_events/pics/people/steven.4bpp graphics/object_events/pics/people/wally.4bpp \
	graphics/object_events/pics/people/rs_little_boy.4bpp graphics/object_events/pics/people/hot_springs_old_woman.4bpp \
	graphics/object_events/pics/pokemon/latias_latios.4bpp graphics/object_events/pics/people/gameboy_kid.4bpp \
	graphics/object_events/pics/people/contest_judge.4bpp graphics/object_events/pics/people/team_aqua/archie.4bpp \
	graphics/object_events/pics/people/team_magma/maxie.4bpp graphics/object_events/pics/pokemon/kyogre.4bpp \
	graphics/object_events/pics/pokemon/groudon.4bpp graphics/object_events/pics/pokemon/regi.4bpp \
	graphics/object_events/pics/pokemon/skitty.4bpp graphics/object_events/pics/pokemon/kecleon.4bpp \
	graphics/object_events/pics/pokemon/rayquaza.4bpp graphics/object_events/pics/pokemon/rayquaza_still.4bpp \
	graphics/object_events/pics/pokemon/zigzagoon.4bpp graphics/object_events/pics/pokemon/pikachu.4bpp \
	graphics/object_events/pics/pokemon/azumarill.4bpp graphics/object_events/pics/pokemon/wingull.4bpp \
	graphics/object_events/pics/people/tuber_m_swimming.4bpp graphics/object_events/pics/pokemon/azurill.4bpp \
	graphics/object_events/pics/people/mom.4bpp graphics/object_events/palettes/kyogre.gbapal \
	graphics/object_events/palettes/kyogre_reflection.gbapal graphics/object_events/palettes/groudon.gbapal \
	graphics/object_events/palettes/groudon_reflection.gbapal graphics/object_events/pics/dolls/unused_natu_doll.4bpp \
	graphics/object_events/pics/dolls/unused_magnemite_doll.4bpp graphics/object_events/pics/dolls/unused_squirtle_doll.4bpp \
	graphics/object_events/pics/dolls/unused_wooper_doll.4bpp graphics/object_events/pics/dolls/unused_pikachu_doll.4bpp \
	graphics/object_events/pics/dolls/unused_porygon2_doll.4bpp graphics/object_events/pics/dolls/pichu_doll.4bpp \
	graphics/object_events/pics/dolls/pikachu_doll.4bpp graphics/object_events/pics/dolls/marill_doll.4bpp \
	graphics/object_events/pics/dolls/togepi_doll.4bpp graphics/object_events/pics/dolls/cyndaquil_doll.4bpp \
	graphics/object_events/pics/dolls/chikorita_doll.4bpp graphics/object_events/pics/dolls/totodile_doll.4bpp \
	graphics/object_events/pics/dolls/jigglypuff_doll.4bpp graphics/object_events/pics/dolls/meowth_doll.4bpp \
	graphics/object_events/pics/dolls/clefairy_doll.4bpp graphics/object_events/pics/dolls/ditto_doll.4bpp \
	graphics/object_events/pics/dolls/smoochum_doll.4bpp graphics/object_events/pics/dolls/treecko_doll.4bpp \
	graphics/object_events/pics/dolls/torchic_doll.4bpp graphics/object_events/pics/dolls/mudkip_doll.4bpp \
	graphics/object_events/pics/dolls/duskull_doll.4bpp graphics/object_events/pics/dolls/wynaut_doll.4bpp \
	graphics/object_events/pics/dolls/baltoy_doll.4bpp graphics/object_events/pics/dolls/kecleon_doll.4bpp \
	graphics/object_events/pics/dolls/azurill_doll.4bpp graphics/object_events/pics/dolls/skitty_doll.4bpp \
	graphics/object_events/pics/dolls/swablu_doll.4bpp graphics/object_events/pics/dolls/gulpin_doll.4bpp \
	graphics/object_events/pics/dolls/lotad_doll.4bpp graphics/object_events/pics/dolls/seedot_doll.4bpp \
	graphics/object_events/pics/cushions/pika_cushion.4bpp graphics/object_events/pics/cushions/round_cushion.4bpp \
	graphics/object_events/pics/cushions/kiss_cushion.4bpp graphics/object_events/pics/cushions/zigzag_cushion.4bpp \
	graphics/object_events/pics/cushions/spin_cushion.4bpp graphics/object_events/pics/cushions/diamond_cushion.4bpp \
	graphics/object_events/pics/cushions/ball_cushion.4bpp graphics/object_events/pics/cushions/grass_cushion.4bpp \
	graphics/object_events/pics/cushions/fire_cushion.4bpp graphics/object_events/pics/cushions/water_cushion.4bpp \
	graphics/object_events/pics/dolls/big_snorlax_doll.4bpp graphics/object_events/pics/dolls/big_rhydon_doll.4bpp \
	graphics/object_events/pics/dolls/big_lapras_doll.4bpp graphics/object_events/pics/dolls/big_venusaur_doll.4bpp \
	graphics/object_events/pics/dolls/big_charizard_doll.4bpp graphics/object_events/pics/dolls/big_blastoise_doll.4bpp \
	graphics/object_events/pics/dolls/big_wailmer_doll.4bpp graphics/object_events/pics/dolls/big_regirock_doll.4bpp \
	graphics/object_events/pics/dolls/big_regice_doll.4bpp graphics/object_events/pics/dolls/big_registeel_doll.4bpp \
	graphics/object_events/pics/misc/cuttable_tree.4bpp graphics/object_events/pics/misc/breakable_rock.4bpp \
	graphics/object_events/pics/misc/pushable_boulder.4bpp graphics/object_events/pics/misc/mr_brineys_boat.4bpp \
	graphics/object_events/pics/misc/fossil.4bpp graphics/object_events/pics/misc/submarine_shadow.4bpp \
	graphics/object_events/palettes/submarine_shadow.gbapal graphics/object_events/pics/misc/truck.4bpp \
	graphics/object_events/palettes/truck.gbapal
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/event_object_movement.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/event_object_movement.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/event_object_movement.gen.s

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

$(OBJ_DIR)/data/event_scripts.d: data/event_scripts.s | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(OBJ_DIR)/data/event_scripts.d

$(OBJ_DIR)/data/event_scripts.o: data/event_scripts.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(CPP) $(CPPFLAGS) - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data.o: data/data.s charmap.txt baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b.o: data/data_b.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b_mid1.o: data/data_b_mid1.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b_mid2b3.o: data/data_b_mid2b3.s baserom_jp.gba
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

$(C_BUILDDIR)/data/trainer_front_pic_coords.o: src/data/trainer_front_pic_coords.c src/data/trainer_front_pic_coords.h src/data/trainer_graphics/front_pic_tables.h src/data/trainer_graphics/back_pic_anims.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/trainer_front_pic_coords.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/trainer_front_pic_coords.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/trainer_front_pic_coords.gen.s

$(C_BUILDDIR)/data/trainer_back_pic_coords.o: src/data/trainer_back_pic_coords.c src/data/trainer_back_pic_coords.h src/data/trainer_graphics/back_pic_tables.h
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

$(OBJ_DIR)/data/data_b2d_mid26.o: data/data_b2d_mid26.s baserom_jp.gba $(JP_STRUCTURED_MAP_EVENTS)
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(CPP) -I include - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid28.o: data/data_b2d_mid28.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid30.o: data/data_b2d_mid30.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid32.o: data/data_b2d_mid32.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/battle_transition_regis_resources.o: data/battle_transition_regis_resources.s graphics/battle_transitions/regis.4bpp graphics/battle_transitions/regice.gbapal graphics/battle_transitions/registeel.gbapal graphics/battle_transitions/regirock.gbapal graphics/battle_transitions/regice.bin graphics/battle_transitions/registeel.bin graphics/battle_transitions/regirock.bin graphics/battle_transitions/unused.gbapal
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/battle_transition_legendary_resources.o: data/battle_transition_legendary_resources.s graphics/battle_transitions/kyogre.4bpp.lz graphics/battle_transitions/kyogre.bin.lz graphics/battle_transitions/groudon.4bpp.lz graphics/battle_transitions/groudon.bin.lz graphics/battle_transitions/kyogre_pt1.gbapal graphics/battle_transitions/kyogre_pt2.gbapal graphics/battle_transitions/groudon_pt1.gbapal graphics/battle_transitions/groudon_pt2.gbapal graphics/battle_transitions/rayquaza.gbapal graphics/battle_transitions/rayquaza.4bpp graphics/battle_transitions/rayquaza.bin
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/battle_transition_frontier_resources.o: data/battle_transition_frontier_resources.s graphics/battle_transitions/frontier_logo.gbapal graphics/battle_transitions/frontier_logo.4bpp.lz graphics/battle_transitions/frontier_logo.bin.lz graphics/battle_transitions/frontier_squares_blanktiles.gbapal graphics/battle_transitions/frontier_square_1.4bpp.lz graphics/battle_transitions/frontier_square_2.4bpp.lz graphics/battle_transitions/frontier_square_3.4bpp.lz graphics/battle_transitions/frontier_square_4.4bpp.lz graphics/battle_transitions/frontier_squares.bin
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/battle_transition_pre_regi_resources.o: data/battle_transition_pre_regi_resources.s graphics/battle_transitions/big_pokeball.4bpp graphics/battle_transitions/pokeball_trail.4bpp graphics/battle_transitions/pokeball.4bpp graphics/battle_transitions/elite_four_bg.4bpp graphics/battle_transitions/unused_brendan.4bpp graphics/battle_transitions/unused_lass.4bpp graphics/battle_transitions/shrinking_box.4bpp graphics/battle_transitions/evil_team.gbapal graphics/battle_transitions/team_aqua.4bpp.lz graphics/battle_transitions/team_aqua.bin.lz graphics/battle_transitions/team_magma.4bpp.lz graphics/battle_transitions/team_magma.bin.lz
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

$(OBJ_DIR)/data/data_b2d_mid51.o: data/data_b2d_mid51.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid54.o: data/data_b2d_mid54.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid60.o: data/data_b2d_mid60.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid61.o: data/data_b2d_mid61.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid65.o: data/data_b2d_mid65.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/battle_transition_tilemaps.o: data/battle_transition_tilemaps.s graphics/battle_transitions/big_pokeball_map.bin graphics/battle_transitions/elite_four_bg_map.bin
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

$(OBJ_DIR)/data/data_b2c_mid8.o: data/data_b2c_mid8.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/mystery_gift.o: data/mystery_gift.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

$(OBJ_DIR)/data/sound_data.o: data/sound_data.s baserom_jp.gba
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

$(OBJ_DIR)/data/rom_padding.o: data/rom_padding.s baserom_jp.gba
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

$(OBJ_DIR)/data/battle_textbox.o: data/battle_textbox.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -


$(OBJ_DIR)/data/data_rest2b.o: data/data_rest2b.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_rest2c.o: data/data_rest2c.s baserom_jp.gba graphics/intro/scene_1/flygon.png.4bpp.lz
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
