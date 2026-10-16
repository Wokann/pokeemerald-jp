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

# Match pokeemerald's JSON source chain for the world wild-encounter owner.
src/data/wild_encounters.h: src/data/wild_encounters.json src/data/wild_encounters.json.txt | tools
	$(JSONPROC) $^ $@

$(C_BUILDDIR)/wild_encounter.o: src/data/wild_encounters.h

JP_GENERATED_HEAL_LOCATION_HEADERS := src/data/heal_locations.h include/constants/heal_locations.h

src/data/heal_locations.h: src/data/heal_locations.json src/data/heal_locations.json.txt | tools
	$(JSONPROC) $^ $@

include/constants/heal_locations.h: src/data/heal_locations.json src/data/heal_locations.constants.json.txt | tools
	$(JSONPROC) $^ $@

$(C_BUILDDIR)/heal_location.o: $(JP_GENERATED_HEAL_LOCATION_HEADERS)
$(C_BUILDDIR)/post_battle_event_funcs.o: include/constants/heal_locations.h
$(OBJ_DIR)/data/event_scripts.o $(OBJ_DIR)/data/battle_scripts_1.o \
$(OBJ_DIR)/data/event_scripts.d $(OBJ_DIR)/data/battle_scripts_1.d: include/constants/heal_locations.h

JP_GENERATED_REGION_MAP_HEADERS := src/data/region_map/region_map_entries.h include/constants/region_map_sections.h
JP_REGION_MAP_ASSETS := graphics/pokenav/region_map/cursor.gbapal \
	graphics/pokenav/region_map/cursor_small.4bpp.lz \
	graphics/pokenav/region_map/cursor_large.4bpp.lz \
	graphics/pokenav/region_map/map.gbapal graphics/pokenav/region_map/map.8bpp.lz \
	graphics/pokenav/region_map/map.bin.lz \
	graphics/pokenav/region_map/brendan_icon.gbapal graphics/pokenav/region_map/brendan_icon.4bpp \
	graphics/pokenav/region_map/may_icon.gbapal graphics/pokenav/region_map/may_icon.4bpp \
	graphics/pokenav/region_map/frame.gbapal graphics/pokenav/region_map/frame.4bpp.lz \
	graphics/pokenav/region_map/frame.bin.lz \
	graphics/pokenav/region_map/fly_target_icons.gbapal graphics/pokenav/region_map/fly_target_icons.4bpp.lz

JP_REGION_MAP_INTERMEDIATES := graphics/pokenav/region_map/map.8bpp \
	graphics/pokenav/region_map/cursor_small.4bpp graphics/pokenav/region_map/cursor_large.4bpp \
	graphics/pokenav/region_map/frame.4bpp graphics/pokenav/region_map/fly_target_icons.4bpp

src/data/region_map/region_map_entries.h: src/data/region_map/region_map_sections.json src/data/region_map/region_map_sections.json.txt | tools
	$(JSONPROC) $^ $@

include/constants/region_map_sections.h: src/data/region_map/region_map_sections.json src/data/region_map/region_map_sections.constants.json.txt | tools
	$(JSONPROC) $^ $@

$(C_BUILDDIR)/region_map.o: src/region_map.c $(JP_GENERATED_REGION_MAP_HEADERS) $(JP_REGION_MAP_ASSETS) include/constants/heal_locations.h charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/region_map.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/region_map.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/region_map.gen.s

graphics/pokenav/region_map/map.8bpp: graphics/pokenav/region_map/map.png | tools
	$(GFX) $< $@ -num_tiles 233 -Wnum_tiles

$(OBJ_DIR)/data/event_scripts.d $(OBJ_DIR)/data/battle_scripts_1.d: include/constants/region_map_sections.h

$(OBJ_DIR)/data/event_scripts.o $(OBJ_DIR)/data/battle_scripts_1.o: include/constants/region_map_sections.h

JP_DECORATION_ICON_ASSETS := graphics/decorations/heavy_desk.4bpp.lz \
	graphics/decorations/heavy_desk.gbapal.lz \
	graphics/decorations/ragged_desk.4bpp.lz \
	graphics/decorations/ragged_desk.gbapal.lz \
	graphics/decorations/comfort_desk.4bpp.lz \
	graphics/decorations/comfort_desk.gbapal.lz \
	graphics/decorations/pretty_desk.4bpp.lz \
	graphics/decorations/pretty_desk.gbapal.lz \
	graphics/decorations/brick_desk.4bpp.lz \
	graphics/decorations/brick_desk.gbapal.lz \
	graphics/decorations/camp_desk.4bpp.lz \
	graphics/decorations/camp_desk.gbapal.lz \
	graphics/decorations/hard_desk.4bpp.lz \
	graphics/decorations/hard_desk.gbapal.lz \
	graphics/decorations/red_plant.4bpp.lz \
	graphics/decorations/red_plant.gbapal.lz \
	graphics/decorations/tropical_plant.4bpp.lz \
	graphics/decorations/tropical_plant.gbapal.lz \
	graphics/decorations/pretty_flowers.4bpp.lz \
	graphics/decorations/pretty_flowers.gbapal.lz \
	graphics/decorations/colorful_plant.4bpp.lz \
	graphics/decorations/colorful_plant.gbapal.lz \
	graphics/decorations/big_plant.4bpp.lz \
	graphics/decorations/big_plant.gbapal.lz \
	graphics/decorations/gorgeous_plant.4bpp.lz \
	graphics/decorations/gorgeous_plant.gbapal.lz \
	graphics/decorations/red_brick.4bpp.lz \
	graphics/decorations/red_brick.gbapal.lz \
	graphics/decorations/yellow_brick.4bpp.lz \
	graphics/decorations/yellow_brick.gbapal.lz \
	graphics/decorations/blue_brick.4bpp.lz \
	graphics/decorations/blue_brick.gbapal.lz \
	graphics/decorations/red_tent.4bpp.lz \
	graphics/decorations/red_tent.gbapal.lz \
	graphics/decorations/blue_tent.4bpp.lz \
	graphics/decorations/blue_tent.gbapal.lz \
	graphics/decorations/solid_board.4bpp.lz \
	graphics/decorations/solid_board.gbapal.lz \
	graphics/decorations/slide.4bpp.lz \
	graphics/decorations/slide.gbapal.lz \
	graphics/decorations/tire.4bpp.lz \
	graphics/decorations/tire.gbapal.lz \
	graphics/decorations/stand.4bpp.lz \
	graphics/decorations/stand.gbapal.lz \
	graphics/decorations/breakable_door.4bpp.lz \
	graphics/decorations/breakable_door.gbapal.lz \
	graphics/decorations/sand_ornament.4bpp.lz \
	graphics/decorations/sand_ornament.gbapal.lz \
	graphics/decorations/glass_ornament.4bpp.lz \
	graphics/decorations/glass_ornament.gbapal.lz \
	graphics/decorations/surf_mat.4bpp.lz \
	graphics/decorations/surf_mat.gbapal.lz \
	graphics/decorations/thunder_mat.4bpp.lz \
	graphics/decorations/thunder_mat.gbapal.lz \
	graphics/decorations/fire_blast_mat.4bpp.lz \
	graphics/decorations/fire_blast_mat.gbapal.lz \
	graphics/decorations/powder_snow_mat.4bpp.lz \
	graphics/decorations/powder_snow_mat.gbapal.lz \
	graphics/decorations/attract_mat.4bpp.lz \
	graphics/decorations/attract_mat.gbapal.lz \
	graphics/decorations/fissure_mat.4bpp.lz \
	graphics/decorations/fissure_mat.gbapal.lz \
	graphics/decorations/spikes_mat.4bpp.lz \
	graphics/decorations/spikes_mat.gbapal.lz \
	graphics/decorations/snorlax_doll.4bpp.lz \
	graphics/decorations/snorlax_doll.gbapal.lz \
	graphics/decorations/rhydon_doll.4bpp.lz \
	graphics/decorations/rhydon_doll.gbapal.lz \
	graphics/decorations/lapras_doll.4bpp.lz \
	graphics/decorations/lapras_doll.gbapal.lz \
	graphics/decorations/venusaur_doll.4bpp.lz \
	graphics/decorations/venusaur_doll.gbapal.lz \
	graphics/decorations/charizard_doll.4bpp.lz \
	graphics/decorations/charizard_doll.gbapal.lz \
	graphics/decorations/blastoise_doll.4bpp.lz \
	graphics/decorations/blastoise_doll.gbapal.lz \
	graphics/decorations/wailmer_doll.4bpp.lz \
	graphics/decorations/wailmer_doll.gbapal.lz \
	graphics/decorations/regice_doll.4bpp.lz \
	graphics/decorations/regice_doll.gbapal.lz \
	graphics/decorations/regirock_doll.4bpp.lz \
	graphics/decorations/regirock_doll.gbapal.lz \
	graphics/decorations/registeel_doll.4bpp.lz \
	graphics/decorations/registeel_doll.gbapal.lz
JP_DECORATION_CORE_ASSETS := graphics/decorations/decoration_menu.gbapal \
	graphics/decorations/brendan.gbapal \
	graphics/decorations/may.gbapal \
	graphics/decorations/put_away_cursor.4bpp
JP_DECORATION_ICON_INTERMEDIATES := $(JP_DECORATION_ICON_ASSETS:.lz=)

$(C_BUILDDIR)/graphics.o: src/graphics.c src/data/graphics/decorations.h $(JP_DECORATION_ICON_ASSETS)

$(C_BUILDDIR)/image_processing_effects.o: src/image_processing_effects.c src/data/pointillism_points.h

$(C_BUILDDIR)/decoration.o: src/decoration.c charmap.txt $(JP_DECORATION_CORE_ASSETS) \
	src/data/decoration/tiles.h src/data/decoration/description.h src/data/decoration/header.h \
	src/data/decoration/icon.h src/data/decoration/tilemaps.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/decoration.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/decoration.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/decoration.gen.s


# Maps already migrated to the canonical map.json event-data structure.
# Layout metadata and every map header/connection now share their local JSON
# source of truth; this list only controls the remaining event-data migration.
JP_STRUCTURED_MAPS := Route101 Route102 Route103 Route104 Route104_MrBrineysHouse Route104_PrettyPetalFlowerShop Route105 Route106 Route107 Route108 Route109 Route111_WinstrateFamilysHouse Route111_OldLadysRestStop Route112_CableCarStation MtChimney_CableCarStation Route114_FossilManiacsHouse Route114_FossilManiacsTunnel Route114_LanettesHouse Route116_TunnelersRestHouse Route117_PokemonDayCare Route121_SafariZoneEntrance MeteorFalls_1F_1R MeteorFalls_1F_2R MeteorFalls_B1F_1R MeteorFalls_B1F_2R RusturfTunnel Underwater_SootopolisCity DesertRuins GraniteCave_1F GraniteCave_B1F GraniteCave_B2F GraniteCave_StevensRoom PetalburgWoods MtChimney JaggedPass FieryPath MtPyre_1F MtPyre_2F MtPyre_3F MtPyre_4F MtPyre_5F MtPyre_6F MtPyre_Exterior MtPyre_Summit AquaHideout_1F AquaHideout_B1F AquaHideout_B2F Underwater_SeafloorCavern SeafloorCavern_Entrance SeafloorCavern_Room1 SeafloorCavern_Room2 SeafloorCavern_Room3 SeafloorCavern_Room4 SeafloorCavern_Room5 SeafloorCavern_Room6 SeafloorCavern_Room7 SeafloorCavern_Room8 SeafloorCavern_Room9 CaveOfOrigin_Entrance CaveOfOrigin_B1F VictoryRoad_1F VictoryRoad_B1F VictoryRoad_B2F Route123 Route124 Route125 Route126 Route127 Route128 Route129 Route130 Route131 Route132 Route133 Route134 \
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
	DewfordTown_House1 \
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
	FallarborTown_BattleTentLobby \
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
	PetalburgCity_Gym \
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
	EverGrandeCity_Hall1 \
	EverGrandeCity_Hall2 \
	EverGrandeCity_Hall3 \
	EverGrandeCity_Hall4 \
	EverGrandeCity_Hall5 \
	EverGrandeCity_PokemonLeague_1F \
	EverGrandeCity_HallOfFame \
	EverGrandeCity_PokemonCenter_1F \
	EverGrandeCity_PokemonCenter_2F \
	EverGrandeCity_PokemonLeague_2F \
	EverGrandeCity \
	LittlerootTown
JP_STRUCTURED_MAPS += Route110
JP_STRUCTURED_MAPS += Route111
JP_STRUCTURED_MAPS += Route112
JP_STRUCTURED_MAPS += Route113
JP_STRUCTURED_MAPS += Route114
JP_STRUCTURED_MAPS += Route115
JP_STRUCTURED_MAPS += Route116
JP_STRUCTURED_MAPS += Route117
JP_STRUCTURED_MAPS += Route118
JP_STRUCTURED_MAPS += Route119
JP_STRUCTURED_MAPS += Route120
JP_STRUCTURED_MAPS += Route121
JP_STRUCTURED_MAPS += Route122
JP_STRUCTURED_MAPS += ShoalCave_LowTideEntranceRoom ShoalCave_LowTideInnerRoom ShoalCave_LowTideStairsRoom ShoalCave_LowTideLowerRoom ShoalCave_HighTideEntranceRoom ShoalCave_HighTideInnerRoom NewMauville_Entrance NewMauville_Inside
JP_STRUCTURED_MAPS += AbandonedShip_Deck AbandonedShip_Corridors_1F AbandonedShip_Rooms_1F AbandonedShip_Corridors_B1F \
	AbandonedShip_Rooms_B1F AbandonedShip_Rooms2_B1F AbandonedShip_Underwater1 AbandonedShip_Room_B1F \
	AbandonedShip_Rooms2_1F AbandonedShip_CaptainsOffice AbandonedShip_Underwater2 \
	AbandonedShip_HiddenFloorCorridors AbandonedShip_HiddenFloorRooms
JP_STRUCTURED_MAPS += IslandCave AncientTomb Underwater_SealedChamber \
	SealedChamber_OuterRoom SealedChamber_InnerRoom ScorchedSlab
JP_STRUCTURED_MAPS += CaveOfOrigin_1F CaveOfOrigin_UnusedRubySapphireMap1 \
	CaveOfOrigin_UnusedRubySapphireMap2 CaveOfOrigin_UnusedRubySapphireMap3
JP_STRUCTURED_MAPS += AquaHideout_UnusedRubyMap1 AquaHideout_UnusedRubyMap2 AquaHideout_UnusedRubyMap3
JP_STRUCTURED_MAPS += SkyPillar_Entrance SkyPillar_Outside SkyPillar_1F SkyPillar_2F SkyPillar_3F SkyPillar_4F
JP_STRUCTURED_MAPS += ShoalCave_LowTideIceRoom
JP_STRUCTURED_MAPS += SkyPillar_5F SkyPillar_Top
JP_STRUCTURED_MAPS += MagmaHideout_1F MagmaHideout_2F_1R MagmaHideout_2F_2R MagmaHideout_3F_1R \
	MagmaHideout_3F_2R MagmaHideout_4F MagmaHideout_3F_3R MagmaHideout_2F_3R
JP_STRUCTURED_MAPS += MirageTower_1F MirageTower_2F MirageTower_3F MirageTower_4F
JP_STRUCTURED_MAPS += DesertUnderpass
JP_STRUCTURED_MAPS += ArtisanCave_B1F ArtisanCave_1F
JP_STRUCTURED_MAPS += Underwater_MarineCave MarineCave_Entrance MarineCave_End
JP_STRUCTURED_MAPS += TerraCave_Entrance TerraCave_End
JP_STRUCTURED_MAPS += AlteringCave
JP_STRUCTURED_MAPS += MeteorFalls_StevensCave
JP_STRUCTURED_MAPS += SecretBase_RedCave1 SecretBase_BrownCave1 SecretBase_BlueCave1 SecretBase_YellowCave1 SecretBase_Tree1 SecretBase_Shrub1 \
	SecretBase_RedCave2 SecretBase_BrownCave2 SecretBase_BlueCave2 SecretBase_YellowCave2 SecretBase_Tree2 SecretBase_Shrub2 \
	SecretBase_RedCave3 SecretBase_BrownCave3 SecretBase_BlueCave3 SecretBase_YellowCave3 SecretBase_Tree3 SecretBase_Shrub3 \
	SecretBase_RedCave4 SecretBase_BrownCave4 SecretBase_BlueCave4 SecretBase_YellowCave4 SecretBase_Tree4 SecretBase_Shrub4
JP_STRUCTURED_MAPS += BattleColosseum_2P TradeCenter RecordCorner BattleColosseum_4P
# Contest Hall's alternate layouts share ContestHall_MapEvents. Keep their
# empty, map.json-generated events.inc stubs tracked; data/map_events.s emits
# the aggregate once, and the empty stubs add no ROM data.
JP_STRUCTURED_MAPS += ContestHall ContestHallBeauty ContestHallCool ContestHallCute ContestHallSmart ContestHallTough \
	UnusedContestHall1 UnusedContestHall2 UnusedContestHall3 UnusedContestHall4 UnusedContestHall5 UnusedContestHall6
JP_STRUCTURED_MAPS += InsideOfTruck
JP_STRUCTURED_MAPS += SSTidalCorridor SSTidalLowerDeck SSTidalRooms
JP_STRUCTURED_MAPS += BattlePyramidSquare01 BattlePyramidSquare02 BattlePyramidSquare03 BattlePyramidSquare04 \
	BattlePyramidSquare05 BattlePyramidSquare06 BattlePyramidSquare07 BattlePyramidSquare08 \
	BattlePyramidSquare09 BattlePyramidSquare10 BattlePyramidSquare11 BattlePyramidSquare12 \
	BattlePyramidSquare13 BattlePyramidSquare14 BattlePyramidSquare15 BattlePyramidSquare16
JP_STRUCTURED_MAPS += UnionRoom
JP_STRUCTURED_MAPS += SafariZone_Northwest SafariZone_North SafariZone_Southwest SafariZone_South
JP_STRUCTURED_MAPS += BattleFrontier_OutsideWest BattleFrontier_BattleTowerLobby BattleFrontier_BattleTowerElevator \
	BattleFrontier_BattleTowerCorridor BattleFrontier_BattleTowerBattleRoom
JP_STRUCTURED_MAPS += SouthernIsland_Exterior SouthernIsland_Interior
JP_STRUCTURED_MAPS += SafariZone_RestHouse SafariZone_Northeast SafariZone_Southeast
JP_STRUCTURED_MAPS += BattleFrontier_OutsideEast BattleFrontier_BattleTowerMultiPartnerRoom \
	BattleFrontier_BattleTowerMultiCorridor BattleFrontier_BattleTowerMultiBattleRoom
JP_STRUCTURED_MAPS += BattleFrontier_BattleDomeLobby BattleFrontier_BattleDomeCorridor \
	BattleFrontier_BattleDomePreBattleRoom BattleFrontier_BattleDomeBattleRoom
JP_STRUCTURED_MAPS += BattleFrontier_BattlePalaceLobby BattleFrontier_BattlePalaceCorridor \
	BattleFrontier_BattlePalaceBattleRoom
JP_STRUCTURED_MAPS += BattleFrontier_BattlePyramidLobby BattleFrontier_BattlePyramidFloor \
	BattleFrontier_BattlePyramidTop
JP_STRUCTURED_MAPS += BattleFrontier_BattleArenaLobby BattleFrontier_BattleArenaCorridor \
	BattleFrontier_BattleArenaBattleRoom
JP_STRUCTURED_MAPS += BattleFrontier_BattleFactoryLobby BattleFrontier_BattleFactoryPreBattleRoom \
	BattleFrontier_BattleFactoryBattleRoom BattleFrontier_BattlePikeLobby \
	BattleFrontier_BattlePikeCorridor BattleFrontier_BattlePikeThreePathRoom \
	BattleFrontier_BattlePikeRoomNormal BattleFrontier_BattlePikeRoomFinal \
	BattleFrontier_BattlePikeRoomWildMons BattleFrontier_RankingHall \
	BattleFrontier_Lounge1 BattleFrontier_ExchangeServiceCorner BattleFrontier_Lounge2 \
	BattleFrontier_Lounge3 BattleFrontier_Lounge4 BattleFrontier_ScottsHouse \
	BattleFrontier_Lounge5 BattleFrontier_Lounge6 BattleFrontier_Lounge7 \
	BattleFrontier_ReceptionGate BattleFrontier_Lounge8 BattleFrontier_Lounge9 \
	BattleFrontier_PokemonCenter_1F BattleFrontier_PokemonCenter_2F BattleFrontier_Mart
JP_STRUCTURED_MAPS += FarawayIsland_Entrance FarawayIsland_Interior BirthIsland_Exterior BirthIsland_Harbor
JP_STRUCTURED_MAPS += TrainerHill_Entrance TrainerHill_1F TrainerHill_2F TrainerHill_3F TrainerHill_4F TrainerHill_Roof TrainerHill_Elevator
JP_STRUCTURED_MAPS += NavelRock_Exterior NavelRock_Harbor NavelRock_Entrance NavelRock_B1F NavelRock_Fork \
	NavelRock_Up1 NavelRock_Up2 NavelRock_Up3 NavelRock_Up4 NavelRock_Top \
	NavelRock_Down01 NavelRock_Down02 NavelRock_Down03 NavelRock_Down04 NavelRock_Down05 \
	NavelRock_Down06 NavelRock_Down07 NavelRock_Down08 NavelRock_Down09 NavelRock_Down10 \
	NavelRock_Down11 NavelRock_Bottom
JP_STRUCTURED_MAPS += Route104_Prototype Route104_PrototypePrettyPetalFlowerShop
JP_STRUCTURED_MAPS += Route109_SeashoreHouse
JP_STRUCTURED_MAPS += Route110_TrickHouseEntrance Route110_TrickHouseEnd Route110_TrickHouseCorridor \
	Route110_TrickHousePuzzle1 Route110_TrickHousePuzzle2 Route110_TrickHousePuzzle3 \
	Route110_TrickHousePuzzle4 Route110_TrickHousePuzzle5 Route110_TrickHousePuzzle6 \
	Route110_TrickHousePuzzle7 Route110_TrickHousePuzzle8
JP_STRUCTURED_MAPS += Route110_SeasideCyclingRoadSouthEntrance Route110_SeasideCyclingRoadNorthEntrance
JP_STRUCTURED_MAPS += Route113_GlassWorkshop
JP_STRUCTURED_MAPS += Route123_BerryMastersHouse
JP_STRUCTURED_MAPS += Route119_WeatherInstitute_1F Route119_WeatherInstitute_2F Route119_House
JP_STRUCTURED_MAPS += Route124_DivingTreasureHuntersHouse
JP_STRUCTURED_MAP_EVENTS := $(JP_STRUCTURED_MAPS:%=data/maps/%/events.inc)

$(JP_STRUCTURED_MAP_EVENTS): data/maps/%/events.inc: data/maps/%/map.json | tools
	$(MAPJSON) events emerald $< $(@D)

# Match pokeemerald's aggregate map hierarchy. These four files are generated
# together from canonical group order; data/maps.s consumes headers, groups,
# and connections while data/map_events.s consumes events.
JP_MAP_GROUP_AGGREGATES := data/maps/connections.inc data/maps/events.inc data/maps/groups.inc data/maps/headers.inc

$(JP_MAP_GROUP_AGGREGATES) &: data/maps/map_groups.json | tools
	$(MAPJSON) groups emerald $< data/maps include/constants

# These maps also own local headers and connections. The JP layout table is
# still centralized, so the local generator directly references its existing
# gMapLayout_* labels while keeping canonical sources beside each map.json.
JP_STRUCTURED_MAP_METADATA_MAPS := CaveOfOrigin_B1F VictoryRoad_1F VictoryRoad_B1F VictoryRoad_B2F Underwater_Route124 Underwater_Route126 \
	Underwater_Route127 Underwater_Route128 Underwater_Route129 \
	Underwater_Route105 Underwater_Route125
JP_STRUCTURED_MAP_METADATA_MAPS += ShoalCave_LowTideEntranceRoom ShoalCave_LowTideInnerRoom ShoalCave_LowTideStairsRoom ShoalCave_LowTideLowerRoom ShoalCave_HighTideEntranceRoom ShoalCave_HighTideInnerRoom NewMauville_Entrance NewMauville_Inside
JP_STRUCTURED_MAP_METADATA_MAPS += AbandonedShip_Deck AbandonedShip_Corridors_1F AbandonedShip_Rooms_1F AbandonedShip_Corridors_B1F \
	AbandonedShip_Rooms_B1F AbandonedShip_Rooms2_B1F AbandonedShip_Underwater1 AbandonedShip_Room_B1F \
	AbandonedShip_Rooms2_1F AbandonedShip_CaptainsOffice AbandonedShip_Underwater2 \
	AbandonedShip_HiddenFloorCorridors AbandonedShip_HiddenFloorRooms
JP_STRUCTURED_MAP_METADATA_MAPS += IslandCave AncientTomb Underwater_Route134 Underwater_SealedChamber \
	SealedChamber_OuterRoom SealedChamber_InnerRoom ScorchedSlab
JP_STRUCTURED_MAP_METADATA_MAPS += PetalburgCity SlateportCity MauvilleCity RustboroCity FortreeCity \
	LilycoveCity MossdeepCity SootopolisCity EverGrandeCity
JP_STRUCTURED_MAP_METADATA_MAPS += LittlerootTown OldaleTown DewfordTown LavaridgeTown FallarborTown \
	VerdanturfTown PacifidlogTown
JP_STRUCTURED_MAP_METADATA_MAPS += Route101 Route102 Route103 Route104 Route105 Route106 Route107 Route108 \
	Route109 Route110
JP_STRUCTURED_MAP_METADATA_MAPS += Route111 Route112 Route113 Route114 Route115 Route116 Route117 Route118 \
	Route119 Route120
JP_STRUCTURED_MAP_METADATA_MAPS += Route121 Route122 Route123 Route124 Route125 Route126 Route127 Route128
JP_STRUCTURED_MAP_METADATA_MAPS += Route129 Route130 Route131 Route132 Route133 Route134
JP_STRUCTURED_MAP_METADATA_MAPS += LittlerootTown_BrendansHouse_1F LittlerootTown_BrendansHouse_2F \
	LittlerootTown_MaysHouse_1F LittlerootTown_MaysHouse_2F LittlerootTown_ProfessorBirchsLab
JP_STRUCTURED_MAP_METADATA_MAPS += OldaleTown_House1 OldaleTown_House2 OldaleTown_PokemonCenter_1F \
	OldaleTown_PokemonCenter_2F OldaleTown_Mart
JP_STRUCTURED_MAP_METADATA_MAPS += DewfordTown_House1 DewfordTown_PokemonCenter_1F DewfordTown_PokemonCenter_2F \
	DewfordTown_Gym DewfordTown_Hall DewfordTown_House2
JP_STRUCTURED_MAP_METADATA_MAPS += LavaridgeTown_HerbShop LavaridgeTown_Gym_1F LavaridgeTown_Gym_B1F \
	LavaridgeTown_House LavaridgeTown_Mart LavaridgeTown_PokemonCenter_1F LavaridgeTown_PokemonCenter_2F
JP_STRUCTURED_MAP_METADATA_MAPS += FallarborTown_Mart FallarborTown_BattleTentLobby FallarborTown_BattleTentCorridor \
	FallarborTown_BattleTentBattleRoom FallarborTown_PokemonCenter_1F FallarborTown_PokemonCenter_2F \
	FallarborTown_CozmosHouse FallarborTown_MoveRelearnersHouse
JP_STRUCTURED_MAP_METADATA_MAPS += VerdanturfTown_BattleTentLobby VerdanturfTown_BattleTentCorridor \
	VerdanturfTown_BattleTentBattleRoom VerdanturfTown_Mart VerdanturfTown_PokemonCenter_1F \
	VerdanturfTown_PokemonCenter_2F VerdanturfTown_WandasHouse VerdanturfTown_FriendshipRatersHouse \
	VerdanturfTown_House
JP_STRUCTURED_MAP_METADATA_MAPS += PacifidlogTown_PokemonCenter_1F PacifidlogTown_PokemonCenter_2F \
	PacifidlogTown_House1 PacifidlogTown_House2 PacifidlogTown_House3 PacifidlogTown_House4 \
	PacifidlogTown_House5
JP_STRUCTURED_MAP_METADATA_MAPS += PetalburgCity_WallysHouse PetalburgCity_Gym PetalburgCity_House1 \
	PetalburgCity_House2 PetalburgCity_PokemonCenter_1F PetalburgCity_PokemonCenter_2F \
	PetalburgCity_Mart
JP_STRUCTURED_MAP_METADATA_MAPS += SlateportCity_SternsShipyard_1F SlateportCity_SternsShipyard_2F \
	SlateportCity_BattleTentLobby SlateportCity_BattleTentCorridor SlateportCity_BattleTentBattleRoom \
	SlateportCity_NameRatersHouse SlateportCity_PokemonFanClub SlateportCity_OceanicMuseum_1F \
	SlateportCity_OceanicMuseum_2F SlateportCity_Harbor SlateportCity_House \
	SlateportCity_PokemonCenter_1F SlateportCity_PokemonCenter_2F SlateportCity_Mart
JP_STRUCTURED_MAP_METADATA_MAPS += MauvilleCity_Gym MauvilleCity_BikeShop MauvilleCity_House1 \
	MauvilleCity_GameCorner MauvilleCity_House2 MauvilleCity_PokemonCenter_1F \
	MauvilleCity_PokemonCenter_2F MauvilleCity_Mart
JP_STRUCTURED_MAP_METADATA_MAPS += RustboroCity_DevonCorp_1F RustboroCity_DevonCorp_2F \
	RustboroCity_DevonCorp_3F RustboroCity_Gym RustboroCity_PokemonSchool \
	RustboroCity_PokemonCenter_1F RustboroCity_PokemonCenter_2F RustboroCity_Mart \
	RustboroCity_Flat1_1F RustboroCity_Flat1_2F RustboroCity_House1 \
	RustboroCity_CuttersHouse RustboroCity_House2 RustboroCity_Flat2_1F \
	RustboroCity_Flat2_2F RustboroCity_Flat2_3F RustboroCity_House3
JP_STRUCTURED_MAP_METADATA_MAPS += FortreeCity_House1 FortreeCity_Gym \
	FortreeCity_PokemonCenter_1F FortreeCity_PokemonCenter_2F FortreeCity_Mart \
	FortreeCity_House2 FortreeCity_House3 FortreeCity_House4 FortreeCity_House5 \
	FortreeCity_DecorationShop
JP_STRUCTURED_MAP_METADATA_MAPS += LilycoveCity_CoveLilyMotel_1F LilycoveCity_CoveLilyMotel_2F \
	LilycoveCity_LilycoveMuseum_1F LilycoveCity_LilycoveMuseum_2F \
	LilycoveCity_ContestLobby LilycoveCity_ContestHall LilycoveCity_PokemonCenter_1F \
	LilycoveCity_PokemonCenter_2F LilycoveCity_UnusedMart \
	LilycoveCity_PokemonTrainerFanClub LilycoveCity_Harbor LilycoveCity_MoveDeletersHouse \
	LilycoveCity_House1 LilycoveCity_House2 LilycoveCity_House3 LilycoveCity_House4 \
	LilycoveCity_DepartmentStore_1F LilycoveCity_DepartmentStore_2F \
	LilycoveCity_DepartmentStore_3F LilycoveCity_DepartmentStore_4F \
	LilycoveCity_DepartmentStore_5F LilycoveCity_DepartmentStoreRooftop \
	LilycoveCity_DepartmentStoreElevator
JP_STRUCTURED_MAP_METADATA_MAPS += MossdeepCity_Gym MossdeepCity_House1 MossdeepCity_House2 \
	MossdeepCity_PokemonCenter_1F MossdeepCity_PokemonCenter_2F MossdeepCity_Mart \
	MossdeepCity_House3 MossdeepCity_StevensHouse MossdeepCity_House4 \
	MossdeepCity_SpaceCenter_1F MossdeepCity_SpaceCenter_2F \
	MossdeepCity_GameCorner_1F MossdeepCity_GameCorner_B1F
JP_STRUCTURED_MAP_METADATA_MAPS += SootopolisCity_Gym_1F SootopolisCity_Gym_B1F \
	SootopolisCity_PokemonCenter_1F SootopolisCity_PokemonCenter_2F SootopolisCity_Mart \
	SootopolisCity_House1 SootopolisCity_House2 SootopolisCity_House3 SootopolisCity_House4 \
	SootopolisCity_House5 SootopolisCity_House6 SootopolisCity_House7 \
	SootopolisCity_LotadAndSeedotHouse SootopolisCity_MysteryEventsHouse_1F \
	SootopolisCity_MysteryEventsHouse_B1F
JP_STRUCTURED_MAP_METADATA_MAPS += EverGrandeCity_SidneysRoom EverGrandeCity_PhoebesRoom \
	EverGrandeCity_GlaciasRoom EverGrandeCity_DrakesRoom EverGrandeCity_ChampionsRoom \
	EverGrandeCity_Hall1 EverGrandeCity_Hall2 EverGrandeCity_Hall3 EverGrandeCity_Hall4 \
	EverGrandeCity_Hall5 EverGrandeCity_PokemonLeague_1F EverGrandeCity_HallOfFame \
	EverGrandeCity_PokemonCenter_1F EverGrandeCity_PokemonCenter_2F \
	EverGrandeCity_PokemonLeague_2F
JP_STRUCTURED_MAP_METADATA_MAPS += Route104_MrBrineysHouse Route104_PrettyPetalFlowerShop
JP_STRUCTURED_MAP_METADATA_MAPS += Route111_WinstrateFamilysHouse Route111_OldLadysRestStop
JP_STRUCTURED_MAP_METADATA_MAPS += Route112_CableCarStation MtChimney_CableCarStation
JP_STRUCTURED_MAP_METADATA_MAPS += Route114_FossilManiacsHouse Route114_FossilManiacsTunnel \
	Route114_LanettesHouse
JP_STRUCTURED_MAP_METADATA_MAPS += Route116_TunnelersRestHouse
JP_STRUCTURED_MAP_METADATA_MAPS += Route117_PokemonDayCare
JP_STRUCTURED_MAP_METADATA_MAPS += Route121_SafariZoneEntrance
JP_STRUCTURED_MAP_METADATA_MAPS += MeteorFalls_1F_1R MeteorFalls_1F_2R MeteorFalls_B1F_1R \
	MeteorFalls_B1F_2R
JP_STRUCTURED_MAP_METADATA_MAPS += RusturfTunnel
JP_STRUCTURED_MAP_METADATA_MAPS += Underwater_SootopolisCity
JP_STRUCTURED_MAP_METADATA_MAPS += DesertRuins
JP_STRUCTURED_MAP_METADATA_MAPS += GraniteCave_1F GraniteCave_B1F GraniteCave_B2F \
	GraniteCave_StevensRoom
JP_STRUCTURED_MAP_METADATA_MAPS += PetalburgWoods
JP_STRUCTURED_MAP_METADATA_MAPS += MtChimney JaggedPass FieryPath
JP_STRUCTURED_MAP_METADATA_MAPS += MtPyre_1F MtPyre_2F MtPyre_3F MtPyre_4F MtPyre_5F \
	MtPyre_6F MtPyre_Exterior MtPyre_Summit
JP_STRUCTURED_MAP_METADATA_MAPS += AquaHideout_1F AquaHideout_B1F AquaHideout_B2F
JP_STRUCTURED_MAP_METADATA_MAPS += Underwater_SeafloorCavern SeafloorCavern_Entrance \
	SeafloorCavern_Room1 SeafloorCavern_Room2 SeafloorCavern_Room3 SeafloorCavern_Room4
JP_STRUCTURED_MAP_METADATA_MAPS += SeafloorCavern_Room5 SeafloorCavern_Room6 \
	SeafloorCavern_Room7 SeafloorCavern_Room8 SeafloorCavern_Room9
JP_STRUCTURED_MAP_METADATA_MAPS += CaveOfOrigin_Entrance CaveOfOrigin_1F \
	CaveOfOrigin_UnusedRubySapphireMap1 CaveOfOrigin_UnusedRubySapphireMap2 \
	CaveOfOrigin_UnusedRubySapphireMap3
JP_STRUCTURED_MAP_METADATA_MAPS += AquaHideout_UnusedRubyMap1 AquaHideout_UnusedRubyMap2 \
	AquaHideout_UnusedRubyMap3
JP_STRUCTURED_MAP_METADATA_MAPS += SkyPillar_Entrance SkyPillar_Outside SkyPillar_1F \
	SkyPillar_2F SkyPillar_3F SkyPillar_4F
JP_STRUCTURED_MAP_METADATA_MAPS += ShoalCave_LowTideIceRoom
JP_STRUCTURED_MAP_METADATA_MAPS += SkyPillar_5F SkyPillar_Top
JP_STRUCTURED_MAP_METADATA_MAPS += MagmaHideout_1F MagmaHideout_2F_1R MagmaHideout_2F_2R \
	MagmaHideout_3F_1R MagmaHideout_3F_2R MagmaHideout_4F MagmaHideout_3F_3R \
	MagmaHideout_2F_3R
JP_STRUCTURED_MAP_METADATA_MAPS += MirageTower_1F MirageTower_2F MirageTower_3F MirageTower_4F
JP_STRUCTURED_MAP_METADATA_MAPS += DesertUnderpass
JP_STRUCTURED_MAP_METADATA_MAPS += ArtisanCave_B1F ArtisanCave_1F
JP_STRUCTURED_MAP_METADATA_MAPS += Underwater_MarineCave MarineCave_Entrance MarineCave_End
JP_STRUCTURED_MAP_METADATA_MAPS += TerraCave_Entrance TerraCave_End
JP_STRUCTURED_MAP_METADATA_MAPS += AlteringCave
JP_STRUCTURED_MAP_METADATA_MAPS += MeteorFalls_StevensCave
JP_STRUCTURED_MAP_METADATA_MAPS += SecretBase_RedCave1 SecretBase_BrownCave1 SecretBase_BlueCave1 SecretBase_YellowCave1 SecretBase_Tree1 SecretBase_Shrub1 \
	SecretBase_RedCave2 SecretBase_BrownCave2 SecretBase_BlueCave2 SecretBase_YellowCave2 SecretBase_Tree2 SecretBase_Shrub2 \
	SecretBase_RedCave3 SecretBase_BrownCave3 SecretBase_BlueCave3 SecretBase_YellowCave3 SecretBase_Tree3 SecretBase_Shrub3 \
	SecretBase_RedCave4 SecretBase_BrownCave4 SecretBase_BlueCave4 SecretBase_YellowCave4 SecretBase_Tree4 SecretBase_Shrub4
JP_STRUCTURED_MAP_METADATA_MAPS += BattleColosseum_2P TradeCenter RecordCorner BattleColosseum_4P
JP_STRUCTURED_MAP_METADATA_MAPS += ContestHall UnusedContestHall1 UnusedContestHall2 UnusedContestHall3 UnusedContestHall4 UnusedContestHall5 UnusedContestHall6 \
	ContestHallBeauty ContestHallTough ContestHallCool ContestHallSmart ContestHallCute
JP_STRUCTURED_MAP_METADATA_MAPS += InsideOfTruck
JP_STRUCTURED_MAP_METADATA_MAPS += SSTidalCorridor SSTidalLowerDeck SSTidalRooms
JP_STRUCTURED_MAP_METADATA_MAPS += BattlePyramidSquare01 BattlePyramidSquare02 BattlePyramidSquare03 BattlePyramidSquare04 \
	BattlePyramidSquare05 BattlePyramidSquare06 BattlePyramidSquare07 BattlePyramidSquare08 \
	BattlePyramidSquare09 BattlePyramidSquare10 BattlePyramidSquare11 BattlePyramidSquare12 \
	BattlePyramidSquare13 BattlePyramidSquare14 BattlePyramidSquare15 BattlePyramidSquare16
JP_STRUCTURED_MAP_METADATA_MAPS += UnionRoom
JP_STRUCTURED_MAP_METADATA_MAPS += SafariZone_Northwest SafariZone_North SafariZone_Southwest SafariZone_South
JP_STRUCTURED_MAP_METADATA_MAPS += BattleFrontier_OutsideWest BattleFrontier_BattleTowerLobby BattleFrontier_BattleTowerElevator \
	BattleFrontier_BattleTowerCorridor BattleFrontier_BattleTowerBattleRoom
JP_STRUCTURED_MAP_METADATA_MAPS += SouthernIsland_Exterior SouthernIsland_Interior
JP_STRUCTURED_MAP_METADATA_MAPS += SafariZone_RestHouse SafariZone_Northeast SafariZone_Southeast
JP_STRUCTURED_MAP_METADATA_MAPS += BattleFrontier_OutsideEast BattleFrontier_BattleTowerMultiPartnerRoom \
	BattleFrontier_BattleTowerMultiCorridor BattleFrontier_BattleTowerMultiBattleRoom
JP_STRUCTURED_MAP_METADATA_MAPS += BattleFrontier_BattleDomeLobby BattleFrontier_BattleDomeCorridor \
	BattleFrontier_BattleDomePreBattleRoom BattleFrontier_BattleDomeBattleRoom
JP_STRUCTURED_MAP_METADATA_MAPS += BattleFrontier_BattlePalaceLobby BattleFrontier_BattlePalaceCorridor \
	BattleFrontier_BattlePalaceBattleRoom
JP_STRUCTURED_MAP_METADATA_MAPS += BattleFrontier_BattlePyramidLobby BattleFrontier_BattlePyramidFloor \
	BattleFrontier_BattlePyramidTop
JP_STRUCTURED_MAP_METADATA_MAPS += BattleFrontier_BattleArenaLobby BattleFrontier_BattleArenaCorridor \
	BattleFrontier_BattleArenaBattleRoom
JP_STRUCTURED_MAP_METADATA_MAPS += BattleFrontier_BattleFactoryLobby BattleFrontier_BattleFactoryPreBattleRoom \
	BattleFrontier_BattleFactoryBattleRoom BattleFrontier_BattlePikeLobby \
	BattleFrontier_BattlePikeCorridor BattleFrontier_BattlePikeThreePathRoom \
	BattleFrontier_BattlePikeRoomNormal BattleFrontier_BattlePikeRoomFinal \
	BattleFrontier_BattlePikeRoomWildMons BattleFrontier_RankingHall \
	BattleFrontier_Lounge1 BattleFrontier_ExchangeServiceCorner BattleFrontier_Lounge2 \
	BattleFrontier_Lounge3 BattleFrontier_Lounge4 BattleFrontier_ScottsHouse \
	BattleFrontier_Lounge5 BattleFrontier_Lounge6 BattleFrontier_Lounge7 \
	BattleFrontier_ReceptionGate BattleFrontier_Lounge8 BattleFrontier_Lounge9 \
	BattleFrontier_PokemonCenter_1F BattleFrontier_PokemonCenter_2F BattleFrontier_Mart
JP_STRUCTURED_MAP_METADATA_MAPS += FarawayIsland_Entrance FarawayIsland_Interior BirthIsland_Exterior BirthIsland_Harbor
JP_STRUCTURED_MAP_METADATA_MAPS += TrainerHill_Entrance TrainerHill_1F TrainerHill_2F TrainerHill_3F TrainerHill_4F TrainerHill_Roof TrainerHill_Elevator
JP_STRUCTURED_MAP_METADATA_MAPS += NavelRock_Exterior NavelRock_Harbor NavelRock_Entrance NavelRock_B1F NavelRock_Fork \
	NavelRock_Up1 NavelRock_Up2 NavelRock_Up3 NavelRock_Up4 NavelRock_Top \
	NavelRock_Down01 NavelRock_Down02 NavelRock_Down03 NavelRock_Down04 NavelRock_Down05 \
	NavelRock_Down06 NavelRock_Down07 NavelRock_Down08 NavelRock_Down09 NavelRock_Down10 \
	NavelRock_Down11 NavelRock_Bottom
JP_STRUCTURED_MAP_METADATA_MAPS += Route104_Prototype Route104_PrototypePrettyPetalFlowerShop
JP_STRUCTURED_MAP_METADATA_MAPS += Route109_SeashoreHouse
JP_STRUCTURED_MAP_METADATA_MAPS += Route110_TrickHouseEntrance Route110_TrickHouseEnd Route110_TrickHouseCorridor \
	Route110_TrickHousePuzzle1 Route110_TrickHousePuzzle2 Route110_TrickHousePuzzle3 \
	Route110_TrickHousePuzzle4 Route110_TrickHousePuzzle5 Route110_TrickHousePuzzle6 \
	Route110_TrickHousePuzzle7 Route110_TrickHousePuzzle8
JP_STRUCTURED_MAP_METADATA_MAPS += Route110_SeasideCyclingRoadSouthEntrance Route110_SeasideCyclingRoadNorthEntrance
JP_STRUCTURED_MAP_METADATA_MAPS += Route113_GlassWorkshop
JP_STRUCTURED_MAP_METADATA_MAPS += Route123_BerryMastersHouse
JP_STRUCTURED_MAP_METADATA_MAPS += Route119_WeatherInstitute_1F Route119_WeatherInstitute_2F Route119_House
JP_STRUCTURED_MAP_METADATA_MAPS += Route124_DivingTreasureHuntersHouse
JP_STRUCTURED_MAP_HEADERS := $(JP_STRUCTURED_MAP_METADATA_MAPS:%=data/maps/%/header.inc)
JP_STRUCTURED_MAP_CONNECTIONS := $(JP_STRUCTURED_MAP_METADATA_MAPS:%=data/maps/%/connections.inc)
JP_STRUCTURED_MAP_METADATA := $(JP_STRUCTURED_MAP_HEADERS) $(JP_STRUCTURED_MAP_CONNECTIONS)

data/maps/%/header.inc data/maps/%/connections.inc &: data/maps/%/map.json tools/jp_map_metadata.py
	python3 tools/jp_map_metadata.py $< $(@D)

# Keep JP map and field data owners ordered after the tileset owner. State the
# ordering directly so a changed map.json cannot race its generated metadata
# during make -j.
$(OBJ_DIR)/data/maps.o: $(JP_STRUCTURED_MAP_METADATA) $(JP_MAP_GROUP_AGGREGATES)
$(OBJ_DIR)/data/fieldmap.o: data/fieldmap.inc
$(OBJ_DIR)/data/metatile_behavior.o: data/metatile_behavior.inc graphics/misc/sTileBitAttributes.bin
$(OBJ_DIR)/data/field_door.o: data/field_door.inc graphics/misc/sTileBitAttributes.bin \
	graphics/misc/sDoorOpenAnimFrames.bin graphics/misc/sDoorCloseAnimFrames.bin \
	graphics/misc/sBigDoorOpenAnimFrames.bin
data/layouts/layouts.inc data/layouts/layouts_table.inc include/constants/layouts.h &: data/layouts/layouts.json tools/jp_generate_layouts.py tools/mapjson/mapjson
	python3 tools/jp_generate_layouts.py

$(OBJ_DIR)/data/maps.o: data/layouts/layouts.inc data/layouts/layouts_table.inc \
	data/layouts/FallarborTown_LeftoverRSContestLobby/border.bin \
	data/layouts/FallarborTown_LeftoverRSContestLobby/map.bin \
	data/layouts/FallarborTown_LeftoverRSContestHall/border.bin \
	data/layouts/FallarborTown_LeftoverRSContestHall/map.bin \
	data/layouts/Route130_MirageIsland/border.bin \
	data/layouts/Route130_MirageIsland/map.bin \
	data/layouts/UnusedContestRoom1/border.bin \
	data/layouts/UnusedContestRoom1/map.bin \
	data/layouts/UnusedContestRoom2/border.bin \
	data/layouts/UnusedContestRoom2/map.bin \
	data/layouts/UnusedContestRoom3/border.bin \
	data/layouts/UnusedContestRoom3/map.bin \
	data/layouts/UnusedCave1/border.bin \
	data/layouts/UnusedCave1/map.bin \
	data/layouts/UnusedCave2/border.bin \
	data/layouts/UnusedCave2/map.bin \
	data/layouts/UnusedCave3/border.bin \
	data/layouts/UnusedCave3/map.bin \
	data/layouts/UnusedCave4/border.bin \
	data/layouts/UnusedCave4/map.bin \
	data/layouts/UnusedCave5/border.bin \
	data/layouts/UnusedCave5/map.bin \
	data/layouts/UnusedCave6/border.bin \
	data/layouts/UnusedCave6/map.bin \
	data/layouts/UnusedCave7/border.bin \
	data/layouts/UnusedCave7/map.bin \
	data/layouts/UnusedCave8/border.bin \
	data/layouts/UnusedCave8/map.bin \
	data/layouts/UnusedCave9/border.bin \
	data/layouts/UnusedCave9/map.bin \
	data/layouts/UnusedCave10/border.bin \
	data/layouts/UnusedCave10/map.bin \
	data/layouts/UnusedCave11/border.bin \
	data/layouts/UnusedCave11/map.bin \
	data/layouts/UnusedCave12/border.bin \
	data/layouts/UnusedCave12/map.bin \
	data/layouts/UnusedCave13/border.bin \
	data/layouts/UnusedCave13/map.bin \
	data/layouts/UnusedCave14/border.bin \
	data/layouts/UnusedCave14/map.bin \
	data/layouts/UnusedOutdoorArea/border.bin \
	data/layouts/UnusedOutdoorArea/map.bin \
	data/layouts/Route109_SeashoreHouse/border.bin \
	data/layouts/Route109_SeashoreHouse/map.bin \
	data/layouts/Route110_TrickHouseEntrance/border.bin \
	data/layouts/Route110_TrickHouseEntrance/map.bin \
	data/layouts/Route110_TrickHouseEnd/border.bin \
	data/layouts/Route110_TrickHouseEnd/map.bin \
	data/layouts/Route110_TrickHouseCorridor/border.bin \
	data/layouts/Route110_TrickHouseCorridor/map.bin \
	data/layouts/Route110_TrickHousePuzzle1/border.bin \
	data/layouts/Route110_TrickHousePuzzle1/map.bin \
	data/layouts/Route110_TrickHousePuzzle2/border.bin \
	data/layouts/Route110_TrickHousePuzzle2/map.bin \
	data/layouts/Route110_TrickHousePuzzle3/border.bin \
	data/layouts/Route110_TrickHousePuzzle3/map.bin \
	data/layouts/Route110_TrickHousePuzzle4/border.bin \
	data/layouts/Route110_TrickHousePuzzle5/border.bin \
	data/layouts/Route110_TrickHousePuzzle5/map.bin \
	data/layouts/Route110_TrickHousePuzzle6/border.bin \
	data/layouts/Route110_TrickHousePuzzle6/map.bin \
	data/layouts/Route110_TrickHousePuzzle7/border.bin \
	data/layouts/Route110_TrickHousePuzzle7/map.bin \
	data/layouts/Route110_TrickHousePuzzle8/border.bin \
	data/layouts/Route110_TrickHousePuzzle8/map.bin \
	data/layouts/Route110_SeasideCyclingRoadEntrance/border.bin \
	data/layouts/Route110_SeasideCyclingRoadEntrance/map.bin \
	data/layouts/Route119_WeatherInstitute_1F/border.bin \
	data/layouts/Route119_WeatherInstitute_1F/map.bin \
	data/layouts/Route119_WeatherInstitute_2F/border.bin \
	data/layouts/Route119_WeatherInstitute_2F/map.bin \
	data/layouts/Route104_Prototype/border.bin \
	data/layouts/Route104_Prototype/map.bin \
	data/layouts/Route124_DivingTreasureHuntersHouse/border.bin \
	data/layouts/Route124_DivingTreasureHuntersHouse/map.bin \
	data/layouts/CaveOfOrigin_Unused_B4F_Lava/border.bin \
	data/layouts/CaveOfOrigin_Unused_B4F_Lava/map.bin \
	data/layouts/Route131_SkyPillar/border.bin \
	data/layouts/Route131_SkyPillar/map.bin \
	data/layouts/SeafloorCavern_Room9_Lava/border.bin \
	data/layouts/SeafloorCavern_Room9_Lava/map.bin \
	data/layouts/BattleFrontier_BattlePikeLobby/border.bin \
	data/layouts/BattleFrontier_BattlePikeLobby/map.bin \
	data/layouts/BattleFrontier_BattlePikeCorridor/border.bin \
	data/layouts/BattleFrontier_BattlePikeCorridor/map.bin \
	data/layouts/BattleFrontier_BattlePikeThreePathRoom/border.bin \
	data/layouts/BattleFrontier_BattlePikeThreePathRoom/map.bin \
	data/layouts/BattleFrontier_BattlePikeRoomNormal/border.bin \
	data/layouts/BattleFrontier_BattlePikeRoomNormal/map.bin \
	data/layouts/BattleFrontier_BattlePikeRoomFinal/border.bin \
	data/layouts/BattleFrontier_BattlePikeRoomFinal/map.bin \
	data/layouts/BattleFrontier_BattlePikeRoomWildMons/border.bin \
	data/layouts/BattleFrontier_BattlePikeRoomWildMons/map.bin \
	data/layouts/BattleFrontier_BattlePikeRoomUnused/border.bin \
	data/layouts/BattleFrontier_BattlePikeRoomUnused/map.bin \
	data/layouts/SootopolisCity_LegendsBattle/border.bin \
	data/layouts/SootopolisCity_LegendsBattle/map.bin \
	data/layouts/Route111_NoMirageTower/border.bin \
	data/layouts/Route111_NoMirageTower/map.bin \
	data/layouts/BattleFrontier_RankingHall/border.bin \
	data/layouts/BattleFrontier_RankingHall/map.bin \
	data/layouts/BattleFrontier_Lounge1/border.bin \
	data/layouts/BattleFrontier_Lounge1/map.bin \
	data/layouts/BattleFrontier_ExchangeServiceCorner/border.bin \
	data/layouts/BattleFrontier_ExchangeServiceCorner/map.bin \
	data/layouts/BattleFrontier_ReceptionGate/border.bin \
	data/layouts/BattleFrontier_ReceptionGate/map.bin \
	data/layouts/FarawayIsland_Entrance/border.bin \
	data/layouts/FarawayIsland_Entrance/map.bin \
	data/layouts/FarawayIsland_Interior/border.bin \
	data/layouts/FarawayIsland_Interior/map.bin \
	data/layouts/BirthIsland_Exterior/border.bin \
	data/layouts/BirthIsland_Exterior/map.bin \
	data/layouts/IslandHarbor/border.bin \
	data/layouts/IslandHarbor/map.bin \
	data/layouts/TrainerHill_Entrance/border.bin \
	data/layouts/TrainerHill_Entrance/map.bin \
	data/layouts/TrainerHill_1F/border.bin \
	data/layouts/TrainerHill_1F/map.bin \
	data/layouts/TrainerHill_2F/border.bin \
	data/layouts/TrainerHill_2F/map.bin \
	data/layouts/TrainerHill_3F/border.bin \
	data/layouts/TrainerHill_3F/map.bin \
	data/layouts/TrainerHill_4F/border.bin \
	data/layouts/TrainerHill_4F/map.bin \
	data/layouts/TrainerHill_Roof/border.bin \
	data/layouts/TrainerHill_Roof/map.bin \
	data/layouts/NavelRock_Exterior/border.bin \
	data/layouts/NavelRock_Exterior/map.bin \
	data/layouts/NavelRock_Entrance/border.bin \
	data/layouts/NavelRock_Entrance/map.bin \
	data/layouts/NavelRock_Top/border.bin \
	data/layouts/NavelRock_Top/map.bin \
	data/layouts/NavelRock_Bottom/border.bin \
	data/layouts/NavelRock_Bottom/map.bin \
	data/layouts/NavelRock_LadderRoom1/border.bin \
	data/layouts/NavelRock_LadderRoom1/map.bin \
	data/layouts/NavelRock_LadderRoom2/border.bin \
	data/layouts/NavelRock_LadderRoom2/map.bin \
	data/layouts/NavelRock_B1F/border.bin \
	data/layouts/NavelRock_B1F/map.bin \
	data/layouts/NavelRock_Fork/border.bin \
	data/layouts/NavelRock_Fork/map.bin \
	data/layouts/BattleFrontier_Lounge2/border.bin \
	data/layouts/BattleFrontier_Lounge2/map.bin \
	data/layouts/BattleFrontier_ScottsHouse/border.bin \
	data/layouts/BattleFrontier_ScottsHouse/map.bin \
	data/layouts/LittlerootTown_ProfessorBirchsLabWithTable/border.bin \
	data/layouts/LittlerootTown_ProfessorBirchsLabWithTable/map.bin \
	data/layouts/SkyPillar_1F_Clean/border.bin \
	data/layouts/SkyPillar_1F_Clean/map.bin \
	data/layouts/SkyPillar_2F_Clean/border.bin \
	data/layouts/SkyPillar_2F_Clean/map.bin \
	data/layouts/SkyPillar_3F_Clean/border.bin \
	data/layouts/SkyPillar_3F_Clean/map.bin \
	data/layouts/SkyPillar_4F_Clean/border.bin \
	data/layouts/SkyPillar_4F_Clean/map.bin \
	data/layouts/SkyPillar_5F_Clean/border.bin \
	data/layouts/SkyPillar_5F_Clean/map.bin \
	data/layouts/SkyPillar_Top_Clean/border.bin \
	data/layouts/SkyPillar_Top_Clean/map.bin \
	data/layouts/SootopolisCity_MysteryEventsHouse_1F_StairsUnblocked/border.bin \
	data/layouts/SootopolisCity_MysteryEventsHouse_1F_StairsUnblocked/map.bin

JP_TILESET_ASM_RESOURCES := $(shell find data/tilesets -type f \( -name '*.4bpp.lz' -o -name '*.gbapal' -o -name '*.bin' \) -print)
$(OBJ_DIR)/data/tilesets.o: data/tilesets.s data/tilesets/graphics.inc data/tilesets/metatiles.inc data/tilesets/headers.inc baserom_jp.gba $(JP_TILESET_ASM_RESOURCES)

# Match the official flash library builds: agb_flash uses -O (not -O2).
$(C_BUILDDIR)/agb_flash.o: CFLAGS := -O -mthumb-interwork -fhex-asm
$(C_BUILDDIR)/agb_flash_1m.o: CFLAGS := -O -mthumb-interwork -fhex-asm
$(C_BUILDDIR)/agb_flash_mx.o: CFLAGS := -O -mthumb-interwork -fhex-asm

# The RTC library (SIIRTC_V001) is compiled without optimization, like the
# official agbcc build (matches the US pokeemerald build flags).
$(C_BUILDDIR)/siirtc.o: CFLAGS := -mthumb-interwork -ffunction-sections

$(C_BUILDDIR)/braille_puzzles.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

$(C_BUILDDIR)/title_screen.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections

# JP byte matching requires agbcc's debug flag for GenerateInitialRentalMons
# to retain the original 0x180-byte register allocation.
$(C_BUILDDIR)/battle_tent.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -g

$(C_BUILDDIR)/title_screen_assets.o: src/title_screen_assets.c graphics/title_screen/rayquaza.4bpp.lz graphics/title_screen/rayquaza.bin.lz \
	graphics/title_screen/logo_shine.4bpp.lz graphics/title_screen/clouds.4bpp.lz
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) -P -x c $< > $(C_BUILDDIR)/title_screen_assets.pre.c
	@$(PREPROC) -i $< charmap.txt < $(C_BUILDDIR)/title_screen_assets.pre.c > $(C_BUILDDIR)/title_screen_assets.preproc.c
	@$(CC) $(CFLAGS) -o $(C_BUILDDIR)/title_screen_assets.gen.s $(C_BUILDDIR)/title_screen_assets.preproc.c
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/title_screen_assets.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/title_screen_assets.pre.c $(C_BUILDDIR)/title_screen_assets.preproc.c $(C_BUILDDIR)/title_screen_assets.gen.s

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
$(C_BUILDDIR)/field_player_avatar_tail.o: src/field_player_avatar.c src/data/field_player_avatar.h charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $@.gen.s
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
$(C_BUILDDIR)/battle_dome.o: include/global.h include/battle_dome.h include/bg.h \
	include/constants/battle_dome.h include/constants/moves.h include/event_data.h include/window.h \
	include/graphics.h include/sprite.h include/scanline_effect.h include/strings.h include/constants/frontier_util.h
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
$(C_BUILDDIR)/battle_factory_screen.o: \
	graphics/battle_frontier/factory_screen/pokeball_gray.pal.gbapal \
	graphics/battle_frontier/factory_screen/pokeball_selected.pal.gbapal \
	graphics/battle_frontier/factory_screen/interface.pal.gbapal \
	graphics/battle_frontier/factory_screen/pokeball.png.4bpp \
	graphics/battle_frontier/factory_screen/arrow.png.4bpp \
	graphics/battle_frontier/factory_screen/menu_highlight_left.png.4bpp \
	graphics/battle_frontier/factory_screen/menu_highlight_right.png.4bpp \
	graphics/battle_frontier/factory_screen/action_box_left.png.4bpp \
	graphics/battle_frontier/factory_screen/action_box_right.png.4bpp \
	graphics/battle_frontier/factory_screen/action_highlight_left.png.4bpp \
	graphics/battle_frontier/factory_screen/action_highlight_middle.png.4bpp \
	graphics/battle_frontier/factory_screen/action_highlight_right.png.4bpp \
	graphics/battle_frontier/factory_screen/mon_pic_bg_anim.png.4bpp \
	graphics/battle_frontier/factory_screen/mon_pic_bg.bin \
	graphics/battle_frontier/factory_screen/mon_pic_bg.png.4bpp \
	graphics/battle_frontier/factory_screen/mon_pic_bg.pal.gbapal
$(C_BUILDDIR)/menu.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
$(C_BUILDDIR)/menu.o: graphics/interface/std_menu.pal.gbapal
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
$(C_BUILDDIR)/sound_check.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm
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
$(C_BUILDDIR)/battle_anim_water.o: src/battle_anim_water.c \
	graphics/battle_anims/unused/water_gfx.4bpp graphics/battle_anims/unused/water.bin
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/battle_anim_water.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/battle_anim_water.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/battle_anim_water.gen.s
$(C_BUILDDIR)/battle_anim_sound_tasks.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_status_effects.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_mon_movement.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_utility_funcs.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/mail.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/starter_choose.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/starter_choose.o: \
	graphics/starter_choose/tiles.gbapal \
	graphics/starter_choose/pokeball_selection.gbapal \
	graphics/starter_choose/starter_circle.gbapal \
	graphics/starter_choose/birch_bag.bin.lz \
	graphics/starter_choose/birch_grass.bin.lz \
	graphics/starter_choose/tiles.png.4bpp.lz \
	graphics/starter_choose/pokeball_selection.png.4bpp.lz \
	graphics/starter_choose/starter_circle.png.4bpp.lz
$(C_BUILDDIR)/wallclock.o: \
	graphics/wallclock/male.gbapal \
	graphics/wallclock/female.gbapal \
	graphics/wallclock/text_prompt.gbapal \
	graphics/wallclock/clock_start.bin.lz \
	graphics/wallclock/clock_view.bin.lz \
	graphics/wallclock/clock.png.4bpp.lz \
	graphics/wallclock/hand.png.4bpp.lz
$(C_BUILDDIR)/fldeff_flash.o: \
	graphics/cave_transition/white.pal.gbapal \
	graphics/cave_transition/black.pal.gbapal \
	graphics/cave_transition/enter.pal.gbapal \
	graphics/cave_transition/tilemap.bin.lz \
	graphics/cave_transition/tiles.png.4bpp.lz
$(C_BUILDDIR)/move_relearner.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/title_screen.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_anim_smokescreen.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/rotating_tile_puzzle.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_tv.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/tv.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/bard_music.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/pokedex_area_region_map.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/battle_message.o: CC1 = $(PREPROC) -i src/battle_message.c charmap.txt | $(CC)
$(C_BUILDDIR)/diploma.o: CC1 = $(PREPROC) -i src/diploma.c charmap.txt | $(CC)
$(C_BUILDDIR)/landmark.o: CC1 = $(PREPROC) -i src/landmark.c charmap.txt | $(CC)
$(C_BUILDDIR)/pokedex_area_region_map.o: CC1 = $(PREPROC) -i src/pokedex_area_region_map.c charmap.txt | $(CC)
$(C_BUILDDIR)/pokedex_cry_screen.o: CC1 = $(PREPROC) -i src/pokedex_cry_screen.c charmap.txt | $(CC)
$(C_BUILDDIR)/move_relearner.o: CC1 = $(PREPROC) -i src/move_relearner.c charmap.txt | $(CC)
$(C_BUILDDIR)/pokeblock.o: CC1 = $(PREPROC) -i src/pokeblock.c charmap.txt | $(CC)
$(C_BUILDDIR)/lilycove_lady.o: CC1 = $(PREPROC) -i src/lilycove_lady.c charmap.txt | $(CC)
$(C_BUILDDIR)/apprentice.o: CC1 = $(PREPROC) -i src/apprentice.c charmap.txt | $(CC)
$(C_BUILDDIR)/battle_tower.o: CC1 = $(PREPROC) -i src/battle_tower.c charmap.txt | $(CC)
$(C_BUILDDIR)/braille.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/libc/libc_rest_1b3.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/libc/libc_rest_2.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/libc/libc_rest_0.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/mystery_gift_client.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
$(C_BUILDDIR)/librfu_sio32id.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections
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

$(C_BUILDDIR)/link_rfu_3.o: src/link_rfu_3.c graphics/link/jp/wireless_icon.gbapal graphics/link/jp/wireless_icon.4bpp.lz
	@mkdir -p $(C_BUILDDIR)
	@$(CPP) $(CPPFLAGS) -P -x c $< > $(C_BUILDDIR)/link_rfu_3.pre.c
	@$(PREPROC) -i $< charmap.txt < $(C_BUILDDIR)/link_rfu_3.pre.c > $(C_BUILDDIR)/link_rfu_3.preproc.c
	@$(CC) $(CFLAGS) -o $(C_BUILDDIR)/link_rfu_3.gen.s $(C_BUILDDIR)/link_rfu_3.preproc.c
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/link_rfu_3.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/link_rfu_3.pre.c $(C_BUILDDIR)/link_rfu_3.preproc.c $(C_BUILDDIR)/link_rfu_3.gen.s

$(C_BUILDDIR)/link_rfu_2.o: src/link_rfu_2.c
	@mkdir -p $(C_BUILDDIR)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(CC) $(CFLAGS) -o - -; \
		printf '.text\n\t.align\t2, 0\n'; } | awk '/^\t\.size\t/{print; print "\t.align\t2, 0"; next} {print}' | $(AS) $(ASFLAGS) -o $@ -

include sound/song_order.mk
SONG_OBJS := $(patsubst sound/songs/midi/%.s,$(OBJ_DIR)/sound/songs/midi/%.o,$(SONG_SRCS))

DATA_OBJS := $(OBJ_DIR)/data/event_scripts.o $(OBJ_DIR)/data/battle_anim_scripts.o $(OBJ_DIR)/data/battle_scripts_1.o $(OBJ_DIR)/data/field_effect_scripts.o $(OBJ_DIR)/data/battle_scripts_2.o $(OBJ_DIR)/data/battle_ai_scripts.o $(OBJ_DIR)/data/contest_ai_scripts.o $(OBJ_DIR)/data/mystery_event_script_cmd_table.o $(OBJ_DIR)/data/data.o $(OBJ_DIR)/data/data_b.o $(OBJ_DIR)/data/data_b_mid2a.o $(OBJ_DIR)/data/data_b_mid2b.o $(OBJ_DIR)/data/data_b2.o $(OBJ_DIR)/data/data_b2b.o $(OBJ_DIR)/data/data_b2d.o $(OBJ_DIR)/data/tilesets.o $(OBJ_DIR)/data/maps.o $(OBJ_DIR)/data/fieldmap.o $(OBJ_DIR)/data/metatile_behavior.o $(OBJ_DIR)/data/field_door.o $(OBJ_DIR)/data/map_events.o $(OBJ_DIR)/data/data_b2d_mid55.o $(OBJ_DIR)/data/data_b2d_mid56.o $(OBJ_DIR)/data/data_b2d_mid57_b.o $(OBJ_DIR)/data/data_b2d_mid58.o $(OBJ_DIR)/data/data_b2d_mid59.o $(OBJ_DIR)/data/data_b2d_mid60.o $(OBJ_DIR)/data/data_b2d_mid62.o $(OBJ_DIR)/data/data_b2d_mid33.o $(OBJ_DIR)/data/battle_transition_tilemaps.o $(OBJ_DIR)/data/data_b2d_mid70.o $(OBJ_DIR)/data/mystery_gift.o $(OBJ_DIR)/data/sound_data.o $(OBJ_DIR)/data/rom_padding.o $(OBJ_DIR)/data/battle_textbox.o $(OBJ_DIR)/data/data_b2d_gfx_pokemon_none.o $(OBJ_DIR)/data/data_b2d_gfx_pokemon_main.o $(OBJ_DIR)/data/data_rest2c.o $(OBJ_DIR)/data/data_b2d_gfx_front.o $(OBJ_DIR)/data/multiboot_ereader.o $(OBJ_DIR)/data/multiboot_berry_glitch_fix.o
# Migrated data files now build from C or no longer contribute data.
DATA_OBJS := $(filter-out $(OBJ_DIR)/data/data_b_mid2a.o $(OBJ_DIR)/data/data_b_mid2b.o $(OBJ_DIR)/data/data_b_mid2b5.o $(OBJ_DIR)/data/data_b_mid2b6.o $(OBJ_DIR)/data/data_b2d_mid55.o $(OBJ_DIR)/data/data_b2d_mid56.o $(OBJ_DIR)/data/data_b2d_mid57_b.o $(OBJ_DIR)/data/data_b2d_mid58.o $(OBJ_DIR)/data/data_b2d_mid59.o $(OBJ_DIR)/data/data_b2d_mid62.o,$(DATA_OBJS))
DATA_OBJS := $(filter-out $(OBJ_DIR)/data/data_b2d_mid33.o,$(DATA_OBJS))
DATA_OBJS += $(OBJ_DIR)/data/tv.o
DATA_OBJS += $(OBJ_DIR)/data/battle_transition_regis_resources.o
DATA_OBJS += $(OBJ_DIR)/data/battle_transition_legendary_resources.o
DATA_OBJS += $(OBJ_DIR)/data/battle_transition_frontier_resources.o
DATA_OBJS += $(OBJ_DIR)/data/battle_transition_pre_regi_resources.o
DATA_OBJS += $(OBJ_DIR)/data/graphics/pokedex_area_screen.o

OBJFILE := $(AS_OBJS) $(C_ASM_OBJS) $(C_OBJECTS) $(SONG_OBJS) $(DATA_OBJS)
OBJFILE_REL := $(patsubst $(OBJ_DIR)/%,%,$(OBJFILE))
NAME := pokeemerald_jp
ROM := $(NAME).gba
ELF := $(NAME).elf
TITLE := POKEMON EMER
GAMECODE := BPEJ

.PHONY: all compare clean check-map-script-owners check-map-json-events

all: $(ROM)

check-map-script-owners:
	python3 tools/audit_map_script_owners.py --strict

check-map-json-events:
	python3 tools/audit_map_event_generation.py

compare: $(ROM)
	$(SHA1SUM) rom_jp.sha1

clean: clean-tools
	rm -rf build $(ROM) $(ELF)
	rm -f $(JP_MAP_GROUP_AGGREGATES)
	rm -f $(JP_STRUCTURED_MAP_EVENTS)
	rm -f $(JP_GENERATED_HEAL_LOCATION_HEADERS)
	rm -f $(JP_GENERATED_REGION_MAP_HEADERS) $(JP_REGION_MAP_ASSETS) $(JP_REGION_MAP_INTERMEDIATES)
	rm -f $(JP_DECORATION_ICON_ASSETS) $(JP_DECORATION_CORE_ASSETS) $(JP_DECORATION_ICON_INTERMEDIATES)
	rm -f $(JP_SLOT_MACHINE_ASSETS) $(JP_SLOT_MACHINE_INTERMEDIATES)
	rm -f $(JP_CONTEST_PAINTING_ASSETS) $(JP_CONTEST_PAINTING_INTERMEDIATES)
	rm -f $(JP_BATTLE_RECORDS_ASSETS)
	rm -f $(JP_MON_MARKINGS_ASSETS)
	rm -f $(JP_USE_POKEBLOCK_ASSETS) $(JP_USE_POKEBLOCK_INTERMEDIATES)
	rm -f $(JP_UNUSED_POKENAV_ASSETS) $(JP_UNUSED_POKENAV_INTERMEDIATES)
	rm -f $(JP_FLDEFF_MISC_ASSETS)
	rm -f $(JP_BATTLE_ANIM_FAMILY_ASSETS) $(JP_BATTLE_ANIM_FAMILY_INTERMEDIATES)
	rm -f $(JP_EVOLUTION_SCENE_ASSETS) $(JP_EVOLUTION_SCENE_INTERMEDIATES)
	rm -f $(JP_INTRO_SCENE_ASSETS) $(JP_INTRO_SCENE_INTERMEDIATES)
	rm -f $(JP_INTRO_CREDITS_ASSETS) $(JP_INTRO_CREDITS_INTERMEDIATES)
	rm -f $(JP_BATTLE_ENTRY_ASSETS) $(JP_BATTLE_ENTRY_INTERMEDIATES)
	rm -f $(JP_BATTLE_ANIM_REMAINING_ASSETS) $(JP_BATTLE_ANIM_REMAINING_INTERMEDIATES)
	rm -f $(JP_CONTEST_ASSETS) $(JP_CONTEST_INTERMEDIATES)
	rm -f $(JP_ITEM_ICON_ASSETS) $(JP_ITEM_ICON_INTERMEDIATES)
	rm -f $(JP_ROULETTE_ASSETS) $(JP_ROULETTE_INTERMEDIATES)
	rm -f $(JP_MAIL_ASSETS) $(JP_MAIL_INTERMEDIATES)
	rm -f $(JP_CONTEST_RESULTS_ASSETS)
	rm -f $(JP_FRONTIER_UI_ASSETS) $(JP_FRONTIER_UI_INTERMEDIATES)

# All build artifacts wait for the host-tool chain, so a fresh checkout can
# safely use `make -j` without racing the C/asset rules against tool builds.
$(OBJFILE) $(ELF) $(ROM): | tools
$(OBJFILE): | include/constants/region_map_sections.h

# Match pokeemerald's generic LZ77 asset rule.  Individual C targets declare
# their generated .lz prerequisites so a clean checkout rebuilds them safely.
%.lz: % | tools
	$(GFX) $< $@

graphics/birch_speech/unused_beauty.4bpp: graphics/birch_speech/unused_beauty.png | tools
	$(GFX) $< $@ -num_tiles 822 -Wnum_tiles

%.4bpp: %.png | tools
	$(GFX) $< $@

graphics/easy_chat/%.png.4bpp: graphics/easy_chat/%.png | tools
	$(GFX) $< $@

graphics/easy_chat/%.png.gbapal: graphics/easy_chat/%.png | tools
	$(GFX) $< $@

graphics/easy_chat/%.pal.gbapal: graphics/easy_chat/%.pal | tools
	$(GFX) $< $@

graphics/rotating_gates/%.png.4bpp: graphics/rotating_gates/%.png | tools
	$(GFX) $< $@

graphics/battle_frontier/factory_screen/%.png.4bpp: graphics/battle_frontier/factory_screen/%.png | tools
	$(GFX) $< $@

graphics/starter_choose/%.png.4bpp: graphics/starter_choose/%.png | tools
	$(GFX) $< $@

graphics/wallclock/%.png.4bpp: graphics/wallclock/%.png | tools
	$(GFX) $< $@

graphics/cave_transition/%.png.4bpp: graphics/cave_transition/%.png | tools
	$(GFX) $< $@

graphics/cave_transition/%.pal.gbapal: graphics/cave_transition/%.pal | tools
	$(GFX) $< $@

graphics/battle_frontier/factory_screen/%.pal.gbapal: graphics/battle_frontier/factory_screen/%.pal | tools
	$(GFX) $< $@

graphics/field_effects/pics/%.png.4bpp: graphics/field_effects/pics/%.png | tools
	$(GFX) $< $@

graphics/field_effects/palettes/%.pal.gbapal: graphics/field_effects/palettes/%.pal | tools
	$(GFX) $< $@

graphics/field_effects/pics/%.png_mwidth_2__mheight_1.4bpp: graphics/field_effects/pics/%.png | tools
	$(GFX) $< $@ -mwidth 2 -mheight 1

graphics/field_effects/pics/%.png_mwidth_2__mheight_2.4bpp: graphics/field_effects/pics/%.png | tools
	$(GFX) $< $@ -mwidth 2 -mheight 2

graphics/field_effects/pics/%.png_mwidth_2__mheight_4.4bpp: graphics/field_effects/pics/%.png | tools
	$(GFX) $< $@ -mwidth 2 -mheight 4

graphics/field_effects/pics/%.png_mwidth_4__mheight_4.4bpp: graphics/field_effects/pics/%.png | tools
	$(GFX) $< $@ -mwidth 4 -mheight 4

graphics/object_events/pics/%.png.4bpp: graphics/object_events/pics/%.png | tools
	$(GFX) $< $@

graphics/object_events/palettes/%.pal.gbapal: graphics/object_events/palettes/%.pal | tools
	$(GFX) $< $@

graphics/object_events/pics/pokemon/%.png_mwidth_2__mheight_4.4bpp: graphics/object_events/pics/pokemon/%.png | tools
	$(GFX) $< $@ -mwidth 2 -mheight 4

graphics/object_events/pics/pokemon/%.png_mwidth_4__mheight_4.4bpp: graphics/object_events/pics/pokemon/%.png | tools
	$(GFX) $< $@ -mwidth 4 -mheight 4

graphics/object_events/pics/people/%.png_mwidth_2__mheight_4.4bpp: graphics/object_events/pics/people/%.png | tools
	$(GFX) $< $@ -mwidth 2 -mheight 4

graphics/object_events/pics/people/%.png_mwidth_4__mheight_4.4bpp: graphics/object_events/pics/people/%.png | tools
	$(GFX) $< $@ -mwidth 4 -mheight 4

graphics/object_events/pics/berry_trees/%.png_mwidth_2__mheight_2.4bpp: graphics/object_events/pics/berry_trees/%.png | tools
	$(GFX) $< $@ -mwidth 2 -mheight 2

graphics/object_events/pics/berry_trees/%.png_mwidth_2__mheight_4.4bpp: graphics/object_events/pics/berry_trees/%.png | tools
	$(GFX) $< $@ -mwidth 2 -mheight 4


%.gbapal: %.pal | tools
	$(GFX) $< $@

%.gbapal: %.png | tools
	$(GFX) $< $@

graphics/interface/%.pal.gbapal: graphics/interface/%.pal | tools
	$(GFX) $< $@

graphics/interface/%.png.4bpp: graphics/interface/%.png | tools
	$(GFX) $< $@

graphics/interface/%.png.gbapal: graphics/interface/%.png | tools
	$(GFX) $< $@

# Keep the JP Egg Hatch graphics reproducible from tracked PNG/PAL inputs.
$(C_BUILDDIR)/egg_hatch.d: src/egg_hatch.c | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(C_BUILDDIR)/egg_hatch.d

$(C_BUILDDIR)/egg_hatch.o: src/egg_hatch.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/egg_hatch.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/egg_hatch.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/egg_hatch.gen.s

# Keep Evolution Sparkle graphics reproducible from the tracked PNG input.
$(C_BUILDDIR)/evolution_graphics.d: src/evolution_graphics.c | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(C_BUILDDIR)/evolution_graphics.d

$(C_BUILDDIR)/evolution_graphics.o: src/evolution_graphics.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/evolution_graphics.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/evolution_graphics.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/evolution_graphics.gen.s

# Keep Match Call UI graphics reproducible from tracked PNG inputs.
$(C_BUILDDIR)/match_call.d: src/match_call.c | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(C_BUILDDIR)/match_call.d

$(C_BUILDDIR)/match_call.o: src/match_call.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/match_call.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/match_call.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/match_call.gen.s

# Keep the Pokedex caught-ball graphic reproducible from its tracked PNG input.
$(C_BUILDDIR)/pokedex.d: src/pokedex.c | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(C_BUILDDIR)/pokedex.d

$(C_BUILDDIR)/pokedex.o: src/pokedex.c charmap.txt include/battle_main.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokedex.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokedex.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokedex.gen.s

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

$(C_BUILDDIR)/field_specials.o: src/field_specials.c src/data/field_specials.h src/data/battle_frontier/battle_frontier_exchange_corner.h $(wildcard data/field_specials/jp/*)
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
$(C_BUILDDIR)/pokemon_summary_screen.o: src/pokemon_summary_screen.c charmap.txt \
	src/data/text/move_descriptions.h include/pokemon_summary_screen.h \
	include/constants/moves.h include/graphics.h \
	graphics/summary_screen/a_button.png.4bpp graphics/summary_screen/b_button.png.4bpp
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokemon_summary_screen.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokemon_summary_screen.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokemon_summary_screen.gen.s
$(C_BUILDDIR)/graphics.o: src/graphics.c src/data/graphics/berries.h src/data/graphics/pokeballs.h src/data/text_window.h src/data/scrcmd_data.h \
	graphics/easy_chat/rectangle_cursor.png.gbapal graphics/easy_chat/rectangle_cursor.png.4bpp.lz \
	graphics/easy_chat/button_window.png.gbapal graphics/easy_chat/mode.png.gbapal graphics/easy_chat/mode.png.4bpp.lz graphics/easy_chat/window.png.4bpp.lz graphics/easy_chat/window.bin.lz graphics/easy_chat/button_window.png.4bpp.lz \
	graphics/text_window/message_box_jp.4bpp \
	graphics/interface/menu_info1.gbapal graphics/interface/menu_info2.gbapal graphics/interface/menu_info3.gbapal graphics/interface/menu_info.4bpp \
	graphics/battle_frontier/factory_screen/menu.png.4bpp graphics/battle_frontier/factory_screen/menu.bin graphics/battle_frontier/factory_screen/menu.pal.gbapal \
	graphics/title_screen/press_start.gbapal graphics/title_screen/press_start.4bpp.lz \
	graphics/title_screen/pokemon_logo.gbapal graphics/title_screen/pokemon_logo.bin.lz graphics/title_screen/pokemon_logo.8bpp.lz \
	graphics/title_screen/emerald_version.8bpp.lz graphics/title_screen/clouds.bin.lz \
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
	graphics/pokedex/interface.4bpp.lz graphics/pokedex/search_menu.gbapal \
	graphics/pokedex/search_menu.4bpp.lz graphics/pokedex/search_menu_national.bin.lz \
	graphics/pokedex/search_menu_hoenn.bin.lz \
	graphics/intro/scene_2/player.pal.gbapal \
	graphics/intro/scene_2/volbeat.png.gbapal graphics/intro/scene_2/torchic.png.gbapal \
	graphics/intro/scene_2/manectric.png.gbapal graphics/intro/scene_2/flygon.png.gbapal \
	graphics/intro/scene_2/volbeat.png.4bpp.lz graphics/intro/scene_2/torchic.png.4bpp.lz \
	graphics/intro/scene_2/manectric.png.4bpp.lz graphics/intro/scene_2/flygon.png.4bpp.lz \
	graphics/intro/scene_2/brendan.png.4bpp.lz graphics/intro/scene_2/may.png.4bpp.lz \
	graphics/intro/scene_3/groudon.png.8bpp.lz graphics/intro/scene_3/groudon.bin.lz \
	graphics/intro/scene_3/kyogre.png.8bpp.lz graphics/intro/scene_3/kyogre.bin.lz \
	graphics/intro/scene_3/legend_bg.png.4bpp.lz graphics/intro/scene_3/groudon_bg.bin.lz \
	graphics/intro/scene_3/kyogre_bg.bin.lz graphics/intro/scene_3/clouds.png.4bpp.lz \
	graphics/intro/scene_3/clouds_left.bin.lz graphics/intro/scene_3/clouds_right.bin.lz \
	graphics/intro/scene_3/clouds_sun.bin.lz \
	graphics/intro/scene_3/rayquaza.png.4bpp.lz graphics/intro/scene_3/rayquaza.bin.lz \
	graphics/intro/scene_3/unused_1.bin.lz graphics/intro/scene_3/unused_2.bin.lz \
	graphics/intro/scene_3/rayquaza_clouds.png.4bpp.lz graphics/intro/scene_3/rayquaza_clouds.bin.lz \
	graphics/intro/scene_3/lightning.png.4bpp.lz graphics/intro/scene_3/lightning.png.gbapal \
	graphics/intro/scene_3/bubbles.png.4bpp.lz graphics/intro/scene_3/bubbles.png.gbapal \
	graphics/intro/scene_1/flygon.png.4bpp.lz graphics/intro/scene_1/sparkle.png.4bpp.lz \
	graphics/battle_anims/sprites/flying_dirt.png.4bpp.lz graphics/battle_anims/sprites/flying_dirt.png.gbapal.lz \
	graphics/battle_anims/backgrounds/sandstorm_brew.bin.lz graphics/battle_anims/backgrounds/sandstorm_brew.png.4bpp.lz \
	graphics/battle_anims/sprites/metal_sound_waves.png.4bpp.lz graphics/battle_anims/sprites/metal_sound_waves.png.gbapal.lz \
	graphics/battle_anims/backgrounds/ice.png.4bpp.lz graphics/battle_anims/backgrounds/ice.png.gbapal.lz \
	graphics/battle_anims/backgrounds/ice.bin.lz graphics/battle_anims/sprites/icicle_spear.png.4bpp.lz \
	graphics/battle_anims/sprites/icicle_spear.png.gbapal.lz \
	graphics/contest/nextturn.png.4bpp.lz graphics/contest/nextturn_numbers.png.4bpp \
	graphics/contest/nextturn_random.png.4bpp \
	graphics/contest/applause.png.4bpp.lz graphics/contest/applause_meter.png.4bpp \
	graphics/contest/nextturn.png.gbapal \
	  \
	  \
	  \
	 \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	 \
	  \
	 \
	  \
	  \
	 \
	  \
	  \
	  \
	 \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	  \
	 \
	  \
	  \
	  \
	  \
	 \
	  \
	  \
	graphics/battle_anims/unused/unknown_1.bin graphics/battle_anims/unused/unknown_2.bin graphics/battle_anims/unused/unknown_3.bin \
	  \
	 \
	  \
	graphics/battle_anims/sprites/splash.png.4bpp.lz graphics/battle_anims/sprites/splash.png.gbapal.lz \
	graphics/battle_anims/sprites/sweat_bead.png.4bpp.lz graphics/battle_anims/sprites/pokeblock.png.4bpp.lz \
	graphics/battle_anims/sprites/pokeblock.png.gbapal.lz graphics/battle_anims/sprites/gem_1.png.4bpp.lz \
	graphics/battle_anims/sprites/gem_2.png.4bpp.lz graphics/battle_anims/sprites/gem_3.png.4bpp.lz \
	graphics/battle_anims/sprites/gem_1.png.gbapal.lz graphics/battle_anims/backgrounds/in_air.png.4bpp.lz \
	graphics/battle_anims/backgrounds/in_air.png.gbapal.lz graphics/battle_anims/backgrounds/in_air.bin.lz \
	graphics/battle_anims/sprites/protect.png.4bpp.lz graphics/battle_anims/sprites/protect.png.gbapal.lz \
	graphics/battle_anims/backgrounds/water_muddy.pal.gbapal.lz graphics/battle_interface/ball_status_bar.4bpp.lz \
	graphics/pokemon/egg/icon.png.4bpp graphics/battle_anims/backgrounds/ghost.png.4bpp.lz \
	graphics/battle_anims/backgrounds/ghost.png.gbapal.lz graphics/battle_anims/backgrounds/ghost.bin.lz \
	graphics/battle_anims/sprites/whip_hit.pal.gbapal.lz graphics/battle_anims/backgrounds/solarbeam.pal.gbapal.lz \
	graphics/battle_anims/backgrounds/solarbeam.bin.lz \
	graphics/battle_anims/backgrounds/cosmic.png.gbapal.lz graphics/battle_anims/backgrounds/cosmic.png.4bpp.lz \
	graphics/battle_anims/backgrounds/cosmic.bin.lz graphics/battle_anims/sprites/slam_hit_2.png.gbapal.lz \
	graphics/battle_anims/sprites/slam_hit_2.png.4bpp.lz \
	graphics/battle_anims/backgrounds/fog.bin.lz graphics/battle_anims/sprites/weather_ball.png.gbapal.lz \
	graphics/battle_anims/sprites/weather_ball.png.4bpp.lz graphics/battle_anims/backgrounds/scary_face_player.bin.lz \
	graphics/battle_anims/backgrounds/scary_face_opponent.bin.lz graphics/battle_anims/backgrounds/scary_face_contest.bin.lz \
	graphics/battle_anims/sprites/hail.png.4bpp.lz graphics/battle_anims/sprites/hail.png.gbapal.lz \
	graphics/battle_anims/sprites/green_spike.png.4bpp.lz graphics/battle_anims/sprites/green_spike.png.gbapal.lz \
	graphics/battle_anims/sprites/white_circle_of_light.pal.gbapal.lz graphics/battle_anims/sprites/glowy_blue_orb.pal.gbapal.lz \
	graphics/battle_anims/sprites/recycle.png.4bpp.lz graphics/battle_anims/sprites/recycle.png.gbapal.lz \
	graphics/battle_anims/sprites/red_particles.png.4bpp.lz graphics/battle_anims/sprites/red_particles.png.gbapal.lz \
	graphics/battle_anims/sprites/dirt_mound.png.4bpp.lz graphics/battle_anims/sprites/dirt_mound.png.gbapal.lz \
	graphics/battle_anims/backgrounds/fissure.png.4bpp.lz graphics/battle_anims/backgrounds/fissure.png.gbapal.lz \
	graphics/battle_anims/backgrounds/fissure.bin.lz graphics/battle_anims/sprites/bird.png.4bpp.lz \
	graphics/battle_anims/sprites/bird.png.gbapal.lz graphics/battle_anims/sprites/cross_impact.png.4bpp.lz \
	graphics/battle_anims/sprites/cross_impact.png.gbapal.lz \
	graphics/battle_anims/backgrounds/water.png.4bpp.lz graphics/battle_anims/backgrounds/water.png.gbapal.lz \
	graphics/battle_anims/backgrounds/water_opponent.bin.lz graphics/battle_anims/backgrounds/water_player.bin.lz \
	graphics/battle_anims/backgrounds/water_contest.bin.lz graphics/battle_anims/sprites/slash_2.pal.gbapal.lz \
	graphics/battle_anims/sprites/white_shadow.png.4bpp.lz graphics/battle_anims/sprites/white_shadow.png.gbapal.lz \
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
	$(wildcard graphics/bag/* graphics/berries/* graphics/pokeblock/* graphics/pokenav/*.lz graphics/pokenav/*.gbapal graphics/pokenav/left_headers/*.lz graphics/pokenav/left_headers/*.gbapal graphics/unused/cherry.* graphics/unused/jp/menu_specialized/* graphics/pokemon/icon_palettes/*.gbapal data/tilesets/primary/general/tiles.4bpp.lz data/tilesets/primary/general/palettes/*.gbapal)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/graphics.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/graphics.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/graphics.gen.s

$(C_BUILDDIR)/battle_factory_screen.o: src/battle_factory_screen.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/battle_factory_screen.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/battle_factory_screen.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/battle_factory_screen.gen.s

$(C_BUILDDIR)/menu.o: src/menu.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/menu.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/menu.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/menu.gen.s

$(C_BUILDDIR)/starter_choose.o: src/starter_choose.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/starter_choose.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/starter_choose.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/starter_choose.gen.s

$(C_BUILDDIR)/wallclock.o: src/wallclock.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/wallclock.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/wallclock.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/wallclock.gen.s

$(C_BUILDDIR)/fldeff_flash.o: src/fldeff_flash.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/fldeff_flash.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/fldeff_flash.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/fldeff_flash.gen.s

$(C_BUILDDIR)/text_window.o: src/text_window.c graphics/text_window/gTextWindowFrame1_Gfx.bin graphics/text_window/gTextWindowFrame1_Pal.bin
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/text_window.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/text_window.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/text_window.gen.s

$(C_BUILDDIR)/berry_crush.o: src/berry_crush.c graphics/berry_crush/gBerryCrush_Crusher_Pal.bin graphics/berry_crush/gBerryCrush_Crusher_Gfx.bin graphics/berry_crush/sCrusherTop_Tilemap.bin graphics/misc/sContainerCap_Tilemap.bin graphics/misc/sBg_Tilemap.bin graphics/naming_screen/sPlayerNameWindowGfx.bin
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/berry_crush.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/berry_crush.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/berry_crush.gen.s

$(C_BUILDDIR)/sound_check.o: src/sound_check.c src/data/sound_check.h charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/sound_check.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/sound_check.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/sound_check.gen.s

$(C_BUILDDIR)/berry_blender.o: src/berry_blender.c charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/berry_blender.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/berry_blender.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/berry_blender.gen.s

$(C_BUILDDIR)/dodrio_berry_picking.o: src/dodrio_berry_picking.c graphics/misc/sBg_Pal.bin graphics/dodrio/sDodrioNormalPal.bin graphics/dodrio/sDodrioShinyPal.bin graphics/misc/sBerry_Gfx.bin graphics/misc/sBg_Gfx.bin graphics/misc/sTreeBorder_Gfx.bin graphics/battle_anims/sStatus_Gfx.bin graphics/misc/sCloud_Gfx.bin graphics/dodrio/sDodrio_Gfx.bin graphics/dodrio/sDodrioBg_Tilemap.bin graphics/misc/sTreeBorderRight_Tilemap.bin graphics/misc/sTreeBorderLeft_Tilemap.bin
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/dodrio_berry_picking.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/dodrio_berry_picking.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/dodrio_berry_picking.gen.s

$(C_BUILDDIR)/field_weather.o: src/field_weather.c $(wildcard graphics/weather/drought/*)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/field_weather.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/field_weather.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/field_weather.gen.s

$(C_BUILDDIR)/field_weather_effect.o: src/field_weather_effect.c $(wildcard graphics/weather/*.4bpp graphics/weather/*.gbapal)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/field_weather_effect.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/field_weather_effect.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/field_weather_effect.gen.s

$(C_BUILDDIR)/field_effect.o: src/field_effect.c \
	graphics/birch_speech/birch.4bpp graphics/birch_speech/unused_beauty.4bpp graphics/birch_speech/birch.gbapal \
	graphics/field_effects/pics/pokeball_glow.4bpp graphics/field_effects/palettes/pokeball_glow.gbapal \
	graphics/field_effects/pics/pokecenter_monitor/0.4bpp graphics/field_effects/pics/pokecenter_monitor/1.4bpp \
	graphics/field_effects/pics/hof_monitor_big.4bpp graphics/field_effects/pics/hof_monitor_small.4bpp graphics/field_effects/palettes/hof_monitor.gbapal \
	graphics/field_effects/pics/field_move_streaks.4bpp graphics/field_effects/pics/field_move_streaks.gbapal graphics/field_effects/pics/field_move_streaks.bin \
	graphics/field_effects/pics/field_move_streaks_indoors.4bpp graphics/field_effects/pics/field_move_streaks_indoors.gbapal graphics/field_effects/pics/field_move_streaks_indoors.bin \
	graphics/field_effects/pics/spotlight.4bpp graphics/field_effects/pics/spotlight.gbapal \
	graphics/field_effects/pics/deoxys_rock_fragment_top_left.4bpp graphics/field_effects/pics/deoxys_rock_fragment_top_right.4bpp \
	graphics/field_effects/pics/deoxys_rock_fragment_bottom_left.4bpp graphics/field_effects/pics/deoxys_rock_fragment_bottom_right.4bpp
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/field_effect.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/field_effect.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/field_effect.gen.s

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

$(C_BUILDDIR)/menu_specialized.o: src/menu_specialized.c charmap.txt include/pokemon_summary_screen.h $(wildcard graphics/pokenav/condition/*)
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

$(C_BUILDDIR)/data/trade.d: src/data/trade.h | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(C_BUILDDIR)/data/trade.d

$(C_BUILDDIR)/data/trade.o: src/data/trade.c src/data/trade.h charmap.txt graphics/trade/cursor.png $(wildcard graphics/trade/jp/menu/* graphics/trade/jp/animation/*)
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

$(C_BUILDDIR)/text_input_strings.o: src/text_input_strings.c charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/text_input_strings.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/text_input_strings.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/text_input_strings.gen.s

$(C_BUILDDIR)/naming_screen.o: src/naming_screen.c charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/naming_screen.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/naming_screen.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/naming_screen.gen.s

$(C_BUILDDIR)/reset_rtc_screen.o: src/reset_rtc_screen.c charmap.txt graphics/reset_rtc_screen/arrow_down.4bpp graphics/reset_rtc_screen/arrow_right.4bpp graphics/reset_rtc_screen/arrow.gbapal
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/reset_rtc_screen.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/reset_rtc_screen.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/reset_rtc_screen.gen.s

$(C_BUILDDIR)/data/pokedex.o: src/data/pokedex.c include/pokedex.h charmap.txt src/data/pokemon/pokedex_orders.h \
	src/data/pokemon/pokedex_text.h src/data/pokemon/pokedex_entries.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -I include -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/data/pokedex.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/data/pokedex.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/data/pokedex.gen.s

JP_TRAINER_CARD_ASSETS := graphics/trainer_card/bronze.pal.gbapal \
	graphics/trainer_card/copper.pal.gbapal \
	graphics/trainer_card/frlg/blue.pal.gbapal \
	graphics/trainer_card/frlg/bronze.pal.gbapal \
	graphics/trainer_card/frlg/gold.pal.gbapal \
	graphics/trainer_card/frlg/green.pal.gbapal \
	graphics/trainer_card/frlg/silver.pal.gbapal \
	graphics/trainer_card/gold.pal.gbapal \
	graphics/trainer_card/green.pal.gbapal \
	graphics/trainer_card/silver.pal.gbapal \
	graphics/trainer_card/unused.pal.gbapal \
	graphics/trainer_card/frlg/bg.bin.lz

graphics/trainer_card/%.pal.gbapal: graphics/trainer_card/%.pal | tools
	$(GFX) $< $@

JP_TRAINER_CARD_INPUTS := $(wildcard graphics/trainer_card/*.gbapal graphics/trainer_card/*.4bpp.lz graphics/trainer_card/*.bin.lz \
	graphics/trainer_card/frlg/*.gbapal graphics/trainer_card/frlg/*.4bpp.lz graphics/trainer_card/frlg/*.bin.lz)

$(C_BUILDDIR)/graphics.o: $(JP_TRAINER_CARD_ASSETS) $(JP_TRAINER_CARD_INPUTS)
$(C_BUILDDIR)/trainer_card.o: src/trainer_card.c charmap.txt $(JP_TRAINER_CARD_ASSETS) $(JP_TRAINER_CARD_INPUTS)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/trainer_card.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/trainer_card.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/trainer_card.gen.s

clean: clean-trainer-card-assets
.PHONY: clean-trainer-card-assets
clean-trainer-card-assets:
	rm -f $(JP_TRAINER_CARD_ASSETS)

JP_FRONTIER_PASS_ASSETS := $(wildcard graphics/frontier_pass/*)

$(C_BUILDDIR)/graphics.o: $(JP_FRONTIER_PASS_ASSETS)
$(C_BUILDDIR)/frontier_pass.o: src/frontier_pass.c charmap.txt $(JP_FRONTIER_PASS_ASSETS)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/frontier_pass.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/frontier_pass.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/frontier_pass.gen.s

JP_STORAGE_INTERFACE_ASSETS := graphics/pokemon_storage/scrolling_bg.png.4bpp.lz \
	graphics/pokemon_storage/scrolling_bg.bin.lz \
	graphics/pokemon_storage/display_menu.pal.gbapal \
	graphics/pokemon_storage/display_menu.bin.lz \
	graphics/pokemon_storage/interface.pal.gbapal \
	graphics/pokemon_storage/pkmn_data_gray.pal.gbapal \
	graphics/pokemon_storage/party_menu.pal.gbapal \
	graphics/pokemon_storage/scrolling_bg.pal.gbapal \
	graphics/pokemon_storage/scrolling_bg_move_items.pal.gbapal \
	graphics/pokemon_storage/waveform.png.gbapal \
	graphics/pokemon_storage/waveform.png.4bpp \
	graphics/pokemon_storage/unused.pal.gbapal \
	graphics/pokemon_storage/text_windows.pal.gbapal \
	graphics/pokemon_storage/menu.png.4bpp.lz \
	graphics/pokemon_storage/party_menu.bin.lz

graphics/pokemon_storage/menu.png.4bpp: graphics/pokemon_storage/menu.png | tools
	$(GFX) $< $@

graphics/pokemon_storage/menu.png.4bpp.lz: graphics/pokemon_storage/menu.png.4bpp | tools
	$(GFX) $< $@

graphics/pokemon_storage/party_menu.bin.lz: graphics/pokemon_storage/party_menu.bin | tools
	$(GFX) $< $@

$(C_BUILDDIR)/graphics.o: graphics/pokemon_storage/party_menu.pal.gbapal \
	graphics/pokemon_storage/menu.png.4bpp.lz graphics/pokemon_storage/party_menu.bin.lz

clean: clean-storage-interface-assets
.PHONY: clean-storage-interface-assets
clean-storage-interface-assets:
	rm -f graphics/pokemon_storage/menu.png.4bpp graphics/pokemon_storage/menu.png.4bpp.lz graphics/pokemon_storage/party_menu.bin.lz

$(C_BUILDDIR)/pokemon_storage_system.o: src/pokemon_storage_system.c charmap.txt $(JP_STORAGE_INTERFACE_ASSETS) \
	graphics/pokemon_storage/box_selection_popup.pal.gbapal \
	graphics/pokemon_storage/box_selection_popup_center.png.4bpp \
	graphics/pokemon_storage/box_selection_popup_sides.png.4bpp
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokemon_storage_system.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokemon_storage_system.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokemon_storage_system.gen.s

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

$(C_BUILDDIR)/option_menu.o: src/option_menu.c charmap.txt \
	graphics/interface/option_menu_text.gbapal \
	graphics/interface/option_menu_equals_sign.4bpp
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

$(C_BUILDDIR)/event_object_movement.o: src/event_object_movement.c src/data/object_events/object_event_graphics.h src/data/object_events/object_event_pic_tables.h src/data/object_events/object_event_anims.h src/data/object_events/base_oam.h src/data/object_events/object_event_subsprites.h src/data/object_events/object_event_graphics_info.h charmap.txt \
	graphics/field_effects/pics/cut_grass.4bpp graphics/field_effects/palettes/cut_grass.gbapal \
	graphics/field_effects/pics/ripple.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/ash.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/arrow.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/surf_blob.png_mwidth_4__mheight_4.4bpp \
	graphics/object_events/pics/people/quinty_plump.png_mwidth_4__mheight_4.4bpp \
	graphics/object_events/palettes/quinty_plump.gbapal \
	graphics/object_events/palettes/quinty_plump_reflection.gbapal \
	graphics/field_effects/pics/shadow_small.png.4bpp \
	graphics/field_effects/pics/shadow_medium.png.4bpp \
	graphics/field_effects/pics/shadow_large.png.4bpp \
	graphics/field_effects/pics/shadow_extra_large.png.4bpp \
	graphics/field_effects/pics/ground_impact_dust.png_mwidth_2__mheight_1.4bpp \
	graphics/field_effects/pics/jump_tall_grass.png_mwidth_2__mheight_1.4bpp \
	graphics/field_effects/pics/unused_grass_3.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/jump_long_grass.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/unknown_17.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/unused_grass_2.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/long_grass.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/tall_grass.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/short_grass.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/sand_footprints.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/deep_sand_footprints.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/bike_tire_tracks.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/unused_sand.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/sand_pile.png_mwidth_2__mheight_1.4bpp \
	graphics/field_effects/pics/jump_big_splash.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/splash.png.4bpp \
	graphics/field_effects/pics/jump_small_splash.png_mwidth_2__mheight_1.4bpp \
	graphics/field_effects/pics/water_surfacing.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/tree_disguise.png_mwidth_2__mheight_4.4bpp \
	graphics/field_effects/pics/mountain_disguise.png_mwidth_2__mheight_4.4bpp \
	graphics/field_effects/pics/sand_disguise_placeholder.png_mwidth_2__mheight_4.4bpp \
	graphics/field_effects/pics/hot_springs_water.png.4bpp \
	graphics/field_effects/palettes/ash.pal.gbapal \
	graphics/field_effects/pics/ash_puff.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/ash_launch.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/bubbles.png_mwidth_2__mheight_4.4bpp \
	graphics/field_effects/pics/sparkle.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/small_sparkle.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/palettes/small_sparkle.pal.gbapal \
	graphics/field_effects/pics/bird.png.4bpp \
	graphics/object_events/pics/people/gym_leaders/juan.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/people/scott.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/misc/statue.png.4bpp \
	graphics/object_events/pics/pokemon/kirlia.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/pokemon/dusclops.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/people/mystery_event_deliveryman.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/people/union_room_attendant.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/misc/moving_box.png.4bpp \
	graphics/object_events/palettes/moving_box.pal.gbapal \
	graphics/object_events/pics/pokemon/sudowoodo.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/pokemon/mew.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/palettes/red_leaf.pal.gbapal \
	graphics/object_events/pics/people/red.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/people/leaf.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/palettes/birth_island_stone.pal.gbapal \
	graphics/object_events/pics/misc/birth_island_stone.png.4bpp \
	graphics/object_events/palettes/deoxys.pal.gbapal \
	graphics/object_events/pics/pokemon/deoxys.png_mwidth_4__mheight_4.4bpp \
	graphics/object_events/pics/people/frontier_brains/anabel.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/people/frontier_brains/tucker.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/people/frontier_brains/spenser.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/people/frontier_brains/greta.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/people/frontier_brains/noland.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/people/frontier_brains/lucy.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/people/frontier_brains/brandon.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/pokemon/lugia.png_mwidth_4__mheight_4.4bpp \
	graphics/object_events/palettes/lugia.pal.gbapal \
	graphics/object_events/pics/pokemon/ho_oh.png_mwidth_4__mheight_4.4bpp \
	graphics/object_events/palettes/ho_oh.pal.gbapal \
	graphics/object_events/pics/pokemon/vigoroth.png_mwidth_4__mheight_4.4bpp \
	graphics/object_events/palettes/vigoroth.gbapal \
	graphics/object_events/pics/misc/birchs_bag.4bpp \
	graphics/object_events/pics/pokemon/enemy_zigzagoon.png_mwidth_4__mheight_4.4bpp \
	graphics/object_events/palettes/enemy_zigzagoon.gbapal \
	graphics/object_events/pics/pokemon/poochyena.png_mwidth_4__mheight_4.4bpp \
	graphics/object_events/palettes/poochyena.gbapal \
	graphics/object_events/pics/misc/cable_car.4bpp \
	graphics/object_events/palettes/cable_car.gbapal \
	graphics/object_events/pics/misc/ss_tidal.4bpp \
	graphics/object_events/palettes/ss_tidal.gbapal \
	graphics/object_events/pics/berry_trees/dirt_pile.4bpp \
	graphics/object_events/pics/berry_trees/sprout.png_mwidth_2__mheight_2.4bpp \
	graphics/object_events/pics/berry_trees/pecha.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/kelpsy.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/wepear.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/iapapa.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/cheri.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/figy.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/mago.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/lum.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/razz.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/grepa.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/rabuta.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/nomel.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/leppa.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/liechi.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/hondew.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/aguav.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/wiki.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/pomeg.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/rawst.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/spelon.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/chesto.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/oran.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/persim.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/sitrus.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/aspear.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/pamtre.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/cornn.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/lansat.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/durin.png_mwidth_2__mheight_4.4bpp \
	graphics/object_events/pics/berry_trees/tamato.png_mwidth_2__mheight_4.4bpp \
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

$(C_BUILDDIR)/tileset_anims.d: src/tileset_anims.c | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(C_BUILDDIR)/tileset_anims.d

$(C_BUILDDIR)/tileset_anims.o: src/tileset_anims.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/tileset_anims.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/tileset_anims.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/tileset_anims.gen.s

$(C_BUILDDIR)/rotating_gate.o: src/rotating_gate.c graphics/rotating_gates/l1.png.4bpp graphics/rotating_gates/l2.png.4bpp graphics/rotating_gates/l3.png.4bpp graphics/rotating_gates/l4.png.4bpp graphics/rotating_gates/t1.png.4bpp graphics/rotating_gates/t2.png.4bpp graphics/rotating_gates/t3.png.4bpp graphics/rotating_gates/t4.png.4bpp
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/rotating_gate.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/rotating_gate.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/rotating_gate.gen.s

$(C_BUILDDIR)/easy_chat.o: src/easy_chat.c graphics/easy_chat/scroll_indicator.png.4bpp graphics/easy_chat/start_select_buttons.png.4bpp \
	graphics/easy_chat/interview_frame.png.gbapal graphics/easy_chat/interview_frame.png.4bpp.lz \
	graphics/easy_chat/text_input_frame_orange.pal.gbapal graphics/easy_chat/text_input_frame_green.pal.gbapal graphics/easy_chat/text_input_frame.png.4bpp.lz \
	graphics/easy_chat/title_text.pal.gbapal graphics/easy_chat/text.pal.gbapal
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/easy_chat.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/easy_chat.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/easy_chat.gen.s

$(C_BUILDDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/$*.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/$*.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/$*.gen.s

$(C_BUILDDIR)/trainer_see.o: src/trainer_see.c graphics/field_effects/pics/jp/emotion_exclamation.4bpp graphics/field_effects/pics/jp/emotion_question.4bpp graphics/field_effects/pics/jp/emotion_heart.4bpp
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) -P -x c $< > $(C_BUILDDIR)/trainer_see.pre.c
	@$(PREPROC) -i $< charmap.txt < $(C_BUILDDIR)/trainer_see.pre.c > $(C_BUILDDIR)/trainer_see.preproc.c
	@$(CC) $(CFLAGS) -o $(C_BUILDDIR)/trainer_see.gen.s $(C_BUILDDIR)/trainer_see.preproc.c
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/trainer_see.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/trainer_see.pre.c $(C_BUILDDIR)/trainer_see.preproc.c $(C_BUILDDIR)/trainer_see.gen.s

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

$(OBJ_DIR)/data/battle_anim_scripts.d: data/battle_anim_scripts.s | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(OBJ_DIR)/data/battle_anim_scripts.d

$(OBJ_DIR)/data/battle_anim_scripts.o: data/battle_anim_scripts.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(CPP) $(CPPFLAGS) - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/battle_scripts_1.d: data/battle_scripts_1.s | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(OBJ_DIR)/data/battle_scripts_1.d

$(OBJ_DIR)/data/battle_scripts_1.o: data/battle_scripts_1.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(CPP) $(CPPFLAGS) - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/field_effect_scripts.d: data/field_effect_scripts.s | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(OBJ_DIR)/data/field_effect_scripts.d

$(OBJ_DIR)/data/field_effect_scripts.o: data/field_effect_scripts.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(CPP) $(CPPFLAGS) - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/battle_scripts_2.d: data/battle_scripts_2.s | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(OBJ_DIR)/data/battle_scripts_2.d

$(OBJ_DIR)/data/battle_scripts_2.o: data/battle_scripts_2.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(CPP) $(CPPFLAGS) - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/battle_ai_scripts.d: data/battle_ai_scripts.s | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(OBJ_DIR)/data/battle_ai_scripts.d

$(OBJ_DIR)/data/battle_ai_scripts.o: data/battle_ai_scripts.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(CPP) $(CPPFLAGS) - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/contest_ai_scripts.d: data/contest_ai_scripts.s | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(OBJ_DIR)/data/contest_ai_scripts.d

$(OBJ_DIR)/data/contest_ai_scripts.o: data/contest_ai_scripts.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(CPP) $(CPPFLAGS) - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/mystery_event_script_cmd_table.d: data/mystery_event_script_cmd_table.s | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(OBJ_DIR)/data/mystery_event_script_cmd_table.d

$(OBJ_DIR)/data/mystery_event_script_cmd_table.o: data/mystery_event_script_cmd_table.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(CPP) $(CPPFLAGS) - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data.o: data/data.s charmap.txt baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b.o: data/data_b.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

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

$(OBJ_DIR)/data/map_events.o: data/map_events.s baserom_jp.gba data/maps/events.inc $(JP_STRUCTURED_MAP_EVENTS)
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(CPP) -I include - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/tilesets.o: data/tilesets.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/maps.o: data/maps.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/fieldmap.o: data/fieldmap.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/metatile_behavior.o: data/metatile_behavior.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/field_door.o: data/field_door.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -


$(OBJ_DIR)/data/graphics/pokedex_area_screen.o: data/graphics/pokedex_area_screen.s baserom_jp.gba
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

$(OBJ_DIR)/data/tv.o: data/tv.s data/tv/text_groups.inc
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -



	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid60.o: data/data_b2d_mid60.s baserom_jp.gba
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/battle_transition_tilemaps.o: data/battle_transition_tilemaps.s graphics/battle_transitions/big_pokeball_map.bin graphics/battle_transitions/elite_four_bg_map.bin
	@mkdir -p $(dir $@)
	@set -o pipefail; $(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

$(OBJ_DIR)/data/data_b2d_mid70.o: data/data_b2d_mid70.s baserom_jp.gba
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

JP_SLOT_MACHINE_ASSETS := graphics/slot_machine/bolt.4bpp \
    graphics/slot_machine/digital_display.4bpp.lz \
    graphics/slot_machine/digital_display.gbapal \
    graphics/slot_machine/duck.4bpp \
    graphics/slot_machine/flashing_lights_inside.gbapal \
    graphics/slot_machine/flashing_lights_middle.gbapal \
    graphics/slot_machine/flashing_lights_outside.gbapal \
    graphics/slot_machine/large_bolt/0.4bpp \
    graphics/slot_machine/large_bolt/1.4bpp \
    graphics/slot_machine/menu.4bpp.lz \
    graphics/slot_machine/menu.gbapal \
    graphics/slot_machine/numbers/0.4bpp \
    graphics/slot_machine/numbers/1.4bpp \
    graphics/slot_machine/numbers/2.4bpp \
    graphics/slot_machine/numbers/3.4bpp \
    graphics/slot_machine/numbers/4.4bpp \
    graphics/slot_machine/numbers/5.4bpp \
    graphics/slot_machine/numbers/6.4bpp \
    graphics/slot_machine/numbers/7.4bpp \
    graphics/slot_machine/numbers/8.4bpp \
    graphics/slot_machine/numbers/9.4bpp \
    graphics/slot_machine/pika_aura.4bpp \
    graphics/slot_machine/pokeball_shining_0.gbapal \
    graphics/slot_machine/pokeball_shining_1.gbapal \
    graphics/slot_machine/pokeball_shining_2.gbapal \
    graphics/slot_machine/reel_symbols/1.4bpp \
    graphics/slot_machine/reel_symbols/1.gbapal \
    graphics/slot_machine/reel_symbols/2.4bpp \
    graphics/slot_machine/reel_symbols/3.4bpp \
    graphics/slot_machine/reel_symbols/4.4bpp \
    graphics/slot_machine/reel_symbols/5.4bpp \
    graphics/slot_machine/reel_symbols/6.4bpp \
    graphics/slot_machine/reel_symbols/7.4bpp \
    graphics/slot_machine/reel_time_explosion/0.4bpp \
    graphics/slot_machine/reel_time_explosion/0.gbapal \
    graphics/slot_machine/reel_time_explosion/1.4bpp \
    graphics/slot_machine/reel_time_gfx.4bpp.lz \
    graphics/slot_machine/reel_time_machine.gbapal \
    graphics/slot_machine/reel_time_number_gap.4bpp \
    graphics/slot_machine/reel_time_numbers/0.4bpp \
    graphics/slot_machine/reel_time_numbers/1.4bpp \
    graphics/slot_machine/reel_time_numbers/2.4bpp \
    graphics/slot_machine/reel_time_numbers/3.4bpp \
    graphics/slot_machine/reel_time_numbers/4.4bpp \
    graphics/slot_machine/reel_time_numbers/5.4bpp \
    graphics/slot_machine/reel_time_pikachu.gbapal \
    graphics/slot_machine/shadow.4bpp \
    graphics/slot_machine/shadow.gbapal \
    graphics/slot_machine/smoke.4bpp \
    graphics/slot_machine/smoke.gbapal
JP_SLOT_MACHINE_INTERMEDIATES := graphics/slot_machine/digital_display.4bpp \
    graphics/slot_machine/menu.4bpp \
    graphics/slot_machine/reel_time_gfx.4bpp \
    graphics/slot_machine/reel_time_machine.4bpp \
    graphics/slot_machine/reel_time_pikachu.4bpp

$(C_BUILDDIR)/slot_machine.o: src/slot_machine.c $(JP_SLOT_MACHINE_ASSETS) graphics/slot_machine/reel_time_window.bin
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/slot_machine.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/slot_machine.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/slot_machine.gen.s
$(C_BUILDDIR)/graphics.o: src/data/graphics/slot_machine.h $(JP_SLOT_MACHINE_ASSETS)

graphics/slot_machine/reel_time_gfx.4bpp: graphics/slot_machine/reel_time_pikachu.4bpp \
                                          graphics/slot_machine/reel_time_machine.4bpp | tools
	@cat $^ >$@

JP_CONTEST_PAINTING_ASSETS := graphics/picture_frame/bg.gbapal \
    graphics/picture_frame/cool.4bpp.rl \
    graphics/picture_frame/beauty.4bpp.rl \
    graphics/picture_frame/cute.4bpp.rl \
    graphics/picture_frame/smart.4bpp.rl \
    graphics/picture_frame/tough.4bpp.rl \
    graphics/picture_frame/lobby.4bpp.rl \
    graphics/picture_frame/cool_map.bin.rl \
    graphics/picture_frame/beauty_map.bin.rl \
    graphics/picture_frame/cute_map.bin.rl \
    graphics/picture_frame/smart_map.bin.rl \
    graphics/picture_frame/tough_map.bin.rl \
    graphics/picture_frame/lobby_map.bin.rl
JP_CONTEST_PAINTING_INTERMEDIATES := graphics/picture_frame/cool.4bpp \
    graphics/picture_frame/beauty.4bpp \
    graphics/picture_frame/cute.4bpp \
    graphics/picture_frame/smart.4bpp \
    graphics/picture_frame/tough.4bpp \
    graphics/picture_frame/lobby.4bpp

$(C_BUILDDIR)/contest_painting.o: src/contest_painting.c charmap.txt $(JP_CONTEST_PAINTING_ASSETS)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/contest_painting.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/contest_painting.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/contest_painting.gen.s

graphics/picture_frame/lobby.4bpp: graphics/picture_frame/lobby.png | tools
	$(GFX) $< $@ -num_tiles 86

graphics/picture_frame/%.rl: graphics/picture_frame/% | tools
	$(GFX) $< $@

JP_BATTLE_RECORDS_ASSETS := graphics/trainer_hill/records_window.4bpp \
    graphics/trainer_hill/records_window.gbapal

JP_MON_MARKINGS_MENU_ASSETS := graphics/interface/mon_markings_menu.png.gbapal \
    graphics/interface/mon_markings_menu.png.4bpp
JP_MON_MARKINGS_COMBO_ASSETS := graphics/interface/mon_markings.png.gbapal \
    graphics/interface/mon_markings.png.4bpp
JP_MON_MARKINGS_ASSETS := $(JP_MON_MARKINGS_MENU_ASSETS) $(JP_MON_MARKINGS_COMBO_ASSETS)

$(C_BUILDDIR)/graphics.o: $(JP_MON_MARKINGS_MENU_ASSETS)

JP_USE_POKEBLOCK_ASSETS := graphics/pokeblock/use_screen/updown.png.gbapal \
    graphics/pokeblock/use_screen/updown.png.4bpp \
    graphics/pokeblock/use_screen/condition.png.4bpp.lz \
    graphics/pokeblock/use_screen/condition.png.gbapal \
    graphics/pokeblock/use_screen/mon_frame.png.4bpp \
    graphics/pokeblock/use_screen/mon_frame.bin.lz \
    graphics/pokeblock/use_screen/graph.png.gbapal \
    graphics/pokeblock/use_screen/graph.png.4bpp.lz \
    graphics/pokeblock/use_screen/graph.bin.lz \
    graphics/pokeblock/use_screen/nature.pal.gbapal \
    graphics/pokeblock/use_screen/graph_data.bin.lz
JP_USE_POKEBLOCK_INTERMEDIATES := graphics/pokeblock/use_screen/condition.png.4bpp \
    graphics/pokeblock/use_screen/graph.png.4bpp

graphics/pokeblock/use_screen/%.png.4bpp: graphics/pokeblock/use_screen/%.png | tools
	$(GFX) $< $@

graphics/pokeblock/use_screen/%.png.gbapal: graphics/pokeblock/use_screen/%.png | tools
	$(GFX) $< $@

# The native JP graph contains 125 tiles, rather than the US 208-tile image.
graphics/pokeblock/use_screen/graph.png.4bpp: graphics/pokeblock/use_screen/graph.png | tools
	$(GFX) $< $@ -num_tiles 125

graphics/pokeblock/use_screen/nature.pal.gbapal: graphics/pokeblock/use_screen/nature.pal | tools
	$(GFX) $< $@

$(C_BUILDDIR)/graphics.o: $(JP_USE_POKEBLOCK_ASSETS)
$(C_BUILDDIR)/use_pokeblock.o: $(JP_USE_POKEBLOCK_ASSETS) graphics/pokeblock/use_screen/mon_frame_pal.bin

$(C_BUILDDIR)/use_pokeblock.o: src/use_pokeblock.c charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/use_pokeblock.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/use_pokeblock.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/use_pokeblock.gen.s

$(C_BUILDDIR)/mon_markings.d: src/mon_markings.c | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(C_BUILDDIR)/mon_markings.d

$(C_BUILDDIR)/mon_markings.o: src/mon_markings.c charmap.txt $(JP_MON_MARKINGS_COMBO_ASSETS)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/mon_markings.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/mon_markings.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/mon_markings.gen.s

$(C_BUILDDIR)/battle_records.o: src/battle_records.c charmap.txt $(JP_BATTLE_RECORDS_ASSETS) graphics/trainer_hill/records_window.bin
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/battle_records.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/battle_records.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/battle_records.gen.s

include graphics_file_rules.mk

JP_STORAGE_WALLPAPER_ASSETS := graphics/pokemon_storage/arrow.png.4bpp \
	graphics/pokemon_storage/wallpapers/azumarill/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/azumarill/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/azumarill/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/beach/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/beach/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/beach/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/beach/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/blank/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/blank/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/block/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/block/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/block/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/cave/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/cave/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/cave/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/cave/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/circles/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/circles/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/circles/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/city/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/city/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/city/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/city/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/crag/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/crag/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/crag/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/crag/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/desert/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/desert/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/desert/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/desert/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/diagonal/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/diagonal/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/diagonal/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/dusclops/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/dusclops/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/dusclops/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/forest/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/forest/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/forest/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/forest/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/frame/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/frame/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/frame/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/friends_frame1.png.gbapal \
	graphics/pokemon_storage/wallpapers/friends_frame2.png.gbapal \
	graphics/pokemon_storage/wallpapers/horizontal/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/horizontal/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/horizontal/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/aqua.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/asterisk.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/big_asterisk.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/bolt.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/brick.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/circle.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/cross.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/crystal.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/diglett.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/dot.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/five_star.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/footprint.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/four_circles.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/four_star.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/heart.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/koffing.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/latis.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/line_circle.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/lotad.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/luvdisc.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/magma.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/maze.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/minun.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/pichu.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/plusle.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/pokeball.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/ribbon.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/spinda.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/star_in_circle.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/icons/togepi.png.4bpp.lz \
	graphics/pokemon_storage/wallpapers/legendary/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/legendary/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/legendary/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/ludicolo/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/ludicolo/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/ludicolo/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/machine/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/machine/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/machine/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/machine/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/pikachu/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/pikachu/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/pikachu/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/plain/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/plain/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/plain/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/plain/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/pokecenter/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/pokecenter/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/pokecenter/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/pokecenter/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/pokecenter2/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/pokecenter2/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/pokecenter2/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/polkadot/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/polkadot/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/polkadot/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/polkadot/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/ribbon/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/ribbon/frame.pal.gbapal \
	graphics/pokemon_storage/wallpapers/ribbon/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/ribbon/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/river/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/river/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/river/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/river/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/savanna/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/savanna/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/savanna/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/savanna/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/screen/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/screen/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/screen/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/seafloor/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/seafloor/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/seafloor/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/seafloor/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/sky/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/sky/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/sky/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/sky/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/snow/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/snow/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/snow/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/snow/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/volcano/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/volcano/frame.png.gbapal \
	graphics/pokemon_storage/wallpapers/volcano/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/volcano/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/whiscash/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/whiscash/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/whiscash/tiles.4bpp.lz \
	graphics/pokemon_storage/wallpapers/zigzagoon/bg.png.gbapal \
	graphics/pokemon_storage/wallpapers/zigzagoon/tilemap.bin.lz \
	graphics/pokemon_storage/wallpapers/zigzagoon/tiles.4bpp.lz

JP_STORAGE_WALLPAPER_INTERMEDIATES := graphics/pokemon_storage/wallpapers/azumarill/bg.4bpp \
	graphics/pokemon_storage/wallpapers/azumarill/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/beach/bg.4bpp \
	graphics/pokemon_storage/wallpapers/beach/frame.4bpp \
	graphics/pokemon_storage/wallpapers/beach/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/blank/bg.4bpp \
	graphics/pokemon_storage/wallpapers/blank/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/block/bg.4bpp \
	graphics/pokemon_storage/wallpapers/block/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/cave/bg.4bpp \
	graphics/pokemon_storage/wallpapers/cave/frame.4bpp \
	graphics/pokemon_storage/wallpapers/cave/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/circles/bg.4bpp \
	graphics/pokemon_storage/wallpapers/circles/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/city/bg.4bpp \
	graphics/pokemon_storage/wallpapers/city/frame.4bpp \
	graphics/pokemon_storage/wallpapers/city/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/crag/bg.4bpp \
	graphics/pokemon_storage/wallpapers/crag/frame.4bpp \
	graphics/pokemon_storage/wallpapers/crag/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/desert/bg.4bpp \
	graphics/pokemon_storage/wallpapers/desert/frame.4bpp \
	graphics/pokemon_storage/wallpapers/desert/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/diagonal/bg.4bpp \
	graphics/pokemon_storage/wallpapers/diagonal/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/dusclops/bg.4bpp \
	graphics/pokemon_storage/wallpapers/dusclops/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/forest/bg.4bpp \
	graphics/pokemon_storage/wallpapers/forest/frame.4bpp \
	graphics/pokemon_storage/wallpapers/forest/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/frame/bg.4bpp \
	graphics/pokemon_storage/wallpapers/frame/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/friends_frame1.4bpp \
	graphics/pokemon_storage/wallpapers/friends_frame2.4bpp \
	graphics/pokemon_storage/wallpapers/horizontal/bg.4bpp \
	graphics/pokemon_storage/wallpapers/horizontal/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/legendary/bg.4bpp \
	graphics/pokemon_storage/wallpapers/legendary/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/ludicolo/bg.4bpp \
	graphics/pokemon_storage/wallpapers/ludicolo/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/machine/bg.4bpp \
	graphics/pokemon_storage/wallpapers/machine/frame.4bpp \
	graphics/pokemon_storage/wallpapers/machine/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/pikachu/bg.4bpp \
	graphics/pokemon_storage/wallpapers/pikachu/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/plain/bg.4bpp \
	graphics/pokemon_storage/wallpapers/plain/frame.4bpp \
	graphics/pokemon_storage/wallpapers/plain/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/pokecenter/bg.4bpp \
	graphics/pokemon_storage/wallpapers/pokecenter/frame.4bpp \
	graphics/pokemon_storage/wallpapers/pokecenter/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/pokecenter2/bg.4bpp \
	graphics/pokemon_storage/wallpapers/pokecenter2/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/polkadot/bg.4bpp \
	graphics/pokemon_storage/wallpapers/polkadot/frame.4bpp \
	graphics/pokemon_storage/wallpapers/polkadot/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/ribbon/bg.4bpp \
	graphics/pokemon_storage/wallpapers/ribbon/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/river/bg.4bpp \
	graphics/pokemon_storage/wallpapers/river/frame.4bpp \
	graphics/pokemon_storage/wallpapers/river/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/savanna/bg.4bpp \
	graphics/pokemon_storage/wallpapers/savanna/frame.4bpp \
	graphics/pokemon_storage/wallpapers/savanna/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/screen/bg.4bpp \
	graphics/pokemon_storage/wallpapers/screen/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/seafloor/bg.4bpp \
	graphics/pokemon_storage/wallpapers/seafloor/frame.4bpp \
	graphics/pokemon_storage/wallpapers/seafloor/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/sky/bg.4bpp \
	graphics/pokemon_storage/wallpapers/sky/frame.4bpp \
	graphics/pokemon_storage/wallpapers/sky/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/snow/bg.4bpp \
	graphics/pokemon_storage/wallpapers/snow/frame.4bpp \
	graphics/pokemon_storage/wallpapers/snow/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/volcano/bg.4bpp \
	graphics/pokemon_storage/wallpapers/volcano/frame.4bpp \
	graphics/pokemon_storage/wallpapers/volcano/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/whiscash/bg.4bpp \
	graphics/pokemon_storage/wallpapers/whiscash/tiles.4bpp \
	graphics/pokemon_storage/wallpapers/zigzagoon/bg.4bpp \
	graphics/pokemon_storage/wallpapers/zigzagoon/tiles.4bpp

$(JP_STORAGE_WALLPAPER_ASSETS) $(JP_STORAGE_WALLPAPER_INTERMEDIATES): graphics_file_rules.mk | tools
.SECONDARY: $(JP_STORAGE_WALLPAPER_INTERMEDIATES)

$(C_BUILDDIR)/pokemon_storage_system.o: src/data/wallpapers.h \
	graphics/pokemon_storage/wallpapers/unused.bin $(JP_STORAGE_WALLPAPER_ASSETS)
$(C_BUILDDIR)/graphics.o: $(JP_STORAGE_WALLPAPER_ASSETS)

clean: clean-storage-wallpaper-assets
.PHONY: clean-storage-wallpaper-assets
clean-storage-wallpaper-assets:
	rm -f $(JP_STORAGE_WALLPAPER_ASSETS) $(JP_STORAGE_WALLPAPER_INTERMEDIATES)

JP_STORAGE_CURSOR_GFX := graphics/pokemon_storage/hand_cursor.png.4bpp \
	graphics/pokemon_storage/hand_cursor_shadow.png.4bpp \
	graphics/pokemon_storage/item_info_frame.png.4bpp
JP_STORAGE_CURSOR_ASSETS := graphics/pokemon_storage/hand_cursor.png.gbapal $(JP_STORAGE_CURSOR_GFX)

$(JP_STORAGE_CURSOR_GFX): %.png.4bpp: %.png | tools
	$(GFX) $< $@

graphics/pokemon_storage/hand_cursor.png.gbapal: graphics/pokemon_storage/hand_cursor.png | tools
	$(GFX) $< $@

$(C_BUILDDIR)/pokemon_storage_system.o: $(JP_STORAGE_CURSOR_ASSETS) \
	include/constants/moves.h include/constants/maps.h include/constants/map_groups.h

clean: clean-storage-cursor-assets
.PHONY: clean-storage-cursor-assets
clean-storage-cursor-assets:
	rm -f $(JP_STORAGE_CURSOR_ASSETS)

JP_MON_ICON_GFX := graphics/pokemon/abra/icon.png.4bpp \
	graphics/pokemon/absol/icon.png.4bpp \
	graphics/pokemon/aerodactyl/icon.png.4bpp \
	graphics/pokemon/aggron/icon.png.4bpp \
	graphics/pokemon/aipom/icon.png.4bpp \
	graphics/pokemon/alakazam/icon.png.4bpp \
	graphics/pokemon/altaria/icon.png.4bpp \
	graphics/pokemon/ampharos/icon.png.4bpp \
	graphics/pokemon/anorith/icon.png.4bpp \
	graphics/pokemon/arbok/icon.png.4bpp \
	graphics/pokemon/arcanine/icon.png.4bpp \
	graphics/pokemon/ariados/icon.png.4bpp \
	graphics/pokemon/armaldo/icon.png.4bpp \
	graphics/pokemon/aron/icon.png.4bpp \
	graphics/pokemon/articuno/icon.png.4bpp \
	graphics/pokemon/azumarill/icon.png.4bpp \
	graphics/pokemon/azurill/icon.png.4bpp \
	graphics/pokemon/bagon/icon.png.4bpp \
	graphics/pokemon/baltoy/icon.png.4bpp \
	graphics/pokemon/banette/icon.png.4bpp \
	graphics/pokemon/barboach/icon.png.4bpp \
	graphics/pokemon/bayleef/icon.png.4bpp \
	graphics/pokemon/beautifly/icon.png.4bpp \
	graphics/pokemon/beedrill/icon.png.4bpp \
	graphics/pokemon/beldum/icon.png.4bpp \
	graphics/pokemon/bellossom/icon.png.4bpp \
	graphics/pokemon/bellsprout/icon.png.4bpp \
	graphics/pokemon/blastoise/icon.png.4bpp \
	graphics/pokemon/blaziken/icon.png.4bpp \
	graphics/pokemon/blissey/icon.png.4bpp \
	graphics/pokemon/breloom/icon.png.4bpp \
	graphics/pokemon/bulbasaur/icon.png.4bpp \
	graphics/pokemon/butterfree/icon.png.4bpp \
	graphics/pokemon/cacnea/icon.png.4bpp \
	graphics/pokemon/cacturne/icon.png.4bpp \
	graphics/pokemon/camerupt/icon.png.4bpp \
	graphics/pokemon/carvanha/icon.png.4bpp \
	graphics/pokemon/cascoon/icon.png.4bpp \
	graphics/pokemon/castform/icon.png.4bpp \
	graphics/pokemon/caterpie/icon.png.4bpp \
	graphics/pokemon/celebi/icon.png.4bpp \
	graphics/pokemon/chansey/icon.png.4bpp \
	graphics/pokemon/charizard/icon.png.4bpp \
	graphics/pokemon/charmander/icon.png.4bpp \
	graphics/pokemon/charmeleon/icon.png.4bpp \
	graphics/pokemon/chikorita/icon.png.4bpp \
	graphics/pokemon/chimecho/icon.png.4bpp \
	graphics/pokemon/chinchou/icon.png.4bpp \
	graphics/pokemon/clamperl/icon.png.4bpp \
	graphics/pokemon/claydol/icon.png.4bpp \
	graphics/pokemon/clefable/icon.png.4bpp \
	graphics/pokemon/clefairy/icon.png.4bpp \
	graphics/pokemon/cleffa/icon.png.4bpp \
	graphics/pokemon/cloyster/icon.png.4bpp \
	graphics/pokemon/combusken/icon.png.4bpp \
	graphics/pokemon/corphish/icon.png.4bpp \
	graphics/pokemon/corsola/icon.png.4bpp \
	graphics/pokemon/cradily/icon.png.4bpp \
	graphics/pokemon/crawdaunt/icon.png.4bpp \
	graphics/pokemon/crobat/icon.png.4bpp \
	graphics/pokemon/croconaw/icon.png.4bpp \
	graphics/pokemon/cubone/icon.png.4bpp \
	graphics/pokemon/cyndaquil/icon.png.4bpp \
	graphics/pokemon/delcatty/icon.png.4bpp \
	graphics/pokemon/delibird/icon.png.4bpp \
	graphics/pokemon/deoxys/icon.png.4bpp \
	graphics/pokemon/deoxys/icon_speed.png.4bpp \
	graphics/pokemon/deoxys/icon_speed_wide.png.4bpp \
	graphics/pokemon/dewgong/icon.png.4bpp \
	graphics/pokemon/diglett/icon.png.4bpp \
	graphics/pokemon/ditto/icon.png.4bpp \
	graphics/pokemon/dodrio/icon.png.4bpp \
	graphics/pokemon/doduo/icon.png.4bpp \
	graphics/pokemon/donphan/icon.png.4bpp \
	graphics/pokemon/dragonair/icon.png.4bpp \
	graphics/pokemon/dragonite/icon.png.4bpp \
	graphics/pokemon/dratini/icon.png.4bpp \
	graphics/pokemon/drowzee/icon.png.4bpp \
	graphics/pokemon/dugtrio/icon.png.4bpp \
	graphics/pokemon/dunsparce/icon.png.4bpp \
	graphics/pokemon/dusclops/icon.png.4bpp \
	graphics/pokemon/duskull/icon.png.4bpp \
	graphics/pokemon/dustox/icon.png.4bpp \
	graphics/pokemon/eevee/icon.png.4bpp \
	graphics/pokemon/egg/icon.png.4bpp \
	graphics/pokemon/ekans/icon.png.4bpp \
	graphics/pokemon/electabuzz/icon.png.4bpp \
	graphics/pokemon/electrike/icon.png.4bpp \
	graphics/pokemon/electrode/icon.png.4bpp \
	graphics/pokemon/elekid/icon.png.4bpp \
	graphics/pokemon/entei/icon.png.4bpp \
	graphics/pokemon/espeon/icon.png.4bpp \
	graphics/pokemon/exeggcute/icon.png.4bpp \
	graphics/pokemon/exeggutor/icon.png.4bpp \
	graphics/pokemon/exploud/icon.png.4bpp \
	graphics/pokemon/farfetchd/icon.png.4bpp \
	graphics/pokemon/fearow/icon.png.4bpp \
	graphics/pokemon/feebas/icon.png.4bpp \
	graphics/pokemon/feraligatr/icon.png.4bpp \
	graphics/pokemon/flaaffy/icon.png.4bpp \
	graphics/pokemon/flareon/icon.png.4bpp \
	graphics/pokemon/flygon/icon.png.4bpp \
	graphics/pokemon/forretress/icon.png.4bpp \
	graphics/pokemon/furret/icon.png.4bpp \
	graphics/pokemon/gardevoir/icon.png.4bpp \
	graphics/pokemon/gastly/icon.png.4bpp \
	graphics/pokemon/gengar/icon.png.4bpp \
	graphics/pokemon/geodude/icon.png.4bpp \
	graphics/pokemon/girafarig/icon.png.4bpp \
	graphics/pokemon/glalie/icon.png.4bpp \
	graphics/pokemon/gligar/icon.png.4bpp \
	graphics/pokemon/gloom/icon.png.4bpp \
	graphics/pokemon/golbat/icon.png.4bpp \
	graphics/pokemon/goldeen/icon.png.4bpp \
	graphics/pokemon/golduck/icon.png.4bpp \
	graphics/pokemon/golem/icon.png.4bpp \
	graphics/pokemon/gorebyss/icon.png.4bpp \
	graphics/pokemon/granbull/icon.png.4bpp \
	graphics/pokemon/graveler/icon.png.4bpp \
	graphics/pokemon/grimer/icon.png.4bpp \
	graphics/pokemon/groudon/icon.png.4bpp \
	graphics/pokemon/grovyle/icon.png.4bpp \
	graphics/pokemon/growlithe/icon.png.4bpp \
	graphics/pokemon/grumpig/icon.png.4bpp \
	graphics/pokemon/gulpin/icon.png.4bpp \
	graphics/pokemon/gyarados/icon.png.4bpp \
	graphics/pokemon/hariyama/icon.png.4bpp \
	graphics/pokemon/haunter/icon.png.4bpp \
	graphics/pokemon/heracross/icon.png.4bpp \
	graphics/pokemon/hitmonchan/icon.png.4bpp \
	graphics/pokemon/hitmonlee/icon.png.4bpp \
	graphics/pokemon/hitmontop/icon.png.4bpp \
	graphics/pokemon/ho_oh/icon.png.4bpp \
	graphics/pokemon/hoothoot/icon.png.4bpp \
	graphics/pokemon/hoppip/icon.png.4bpp \
	graphics/pokemon/horsea/icon.png.4bpp \
	graphics/pokemon/houndoom/icon.png.4bpp \
	graphics/pokemon/houndour/icon.png.4bpp \
	graphics/pokemon/huntail/icon.png.4bpp \
	graphics/pokemon/hypno/icon.png.4bpp \
	graphics/pokemon/igglybuff/icon.png.4bpp \
	graphics/pokemon/illumise/icon.png.4bpp \
	graphics/pokemon/ivysaur/icon.png.4bpp \
	graphics/pokemon/jigglypuff/icon.png.4bpp \
	graphics/pokemon/jirachi/icon.png.4bpp \
	graphics/pokemon/jolteon/icon.png.4bpp \
	graphics/pokemon/jumpluff/icon.png.4bpp \
	graphics/pokemon/jynx/icon.png.4bpp \
	graphics/pokemon/kabuto/icon.png.4bpp \
	graphics/pokemon/kabutops/icon.png.4bpp \
	graphics/pokemon/kadabra/icon.png.4bpp \
	graphics/pokemon/kakuna/icon.png.4bpp \
	graphics/pokemon/kangaskhan/icon.png.4bpp \
	graphics/pokemon/kecleon/icon.png.4bpp \
	graphics/pokemon/kingdra/icon.png.4bpp \
	graphics/pokemon/kingler/icon.png.4bpp \
	graphics/pokemon/kirlia/icon.png.4bpp \
	graphics/pokemon/koffing/icon.png.4bpp \
	graphics/pokemon/krabby/icon.png.4bpp \
	graphics/pokemon/kyogre/icon.png.4bpp \
	graphics/pokemon/lairon/icon.png.4bpp \
	graphics/pokemon/lanturn/icon.png.4bpp \
	graphics/pokemon/lapras/icon.png.4bpp \
	graphics/pokemon/larvitar/icon.png.4bpp \
	graphics/pokemon/latias/icon.png.4bpp \
	graphics/pokemon/latios/icon.png.4bpp \
	graphics/pokemon/ledian/icon.png.4bpp \
	graphics/pokemon/ledyba/icon.png.4bpp \
	graphics/pokemon/lickitung/icon.png.4bpp \
	graphics/pokemon/lileep/icon.png.4bpp \
	graphics/pokemon/linoone/icon.png.4bpp \
	graphics/pokemon/lombre/icon.png.4bpp \
	graphics/pokemon/lotad/icon.png.4bpp \
	graphics/pokemon/loudred/icon.png.4bpp \
	graphics/pokemon/ludicolo/icon.png.4bpp \
	graphics/pokemon/lugia/icon.png.4bpp \
	graphics/pokemon/lunatone/icon.png.4bpp \
	graphics/pokemon/luvdisc/icon.png.4bpp \
	graphics/pokemon/machamp/icon.png.4bpp \
	graphics/pokemon/machoke/icon.png.4bpp \
	graphics/pokemon/machop/icon.png.4bpp \
	graphics/pokemon/magby/icon.png.4bpp \
	graphics/pokemon/magcargo/icon.png.4bpp \
	graphics/pokemon/magikarp/icon.png.4bpp \
	graphics/pokemon/magmar/icon.png.4bpp \
	graphics/pokemon/magnemite/icon.png.4bpp \
	graphics/pokemon/magneton/icon.png.4bpp \
	graphics/pokemon/makuhita/icon.png.4bpp \
	graphics/pokemon/manectric/icon.png.4bpp \
	graphics/pokemon/mankey/icon.png.4bpp \
	graphics/pokemon/mantine/icon.png.4bpp \
	graphics/pokemon/mareep/icon.png.4bpp \
	graphics/pokemon/marill/icon.png.4bpp \
	graphics/pokemon/marowak/icon.png.4bpp \
	graphics/pokemon/marshtomp/icon.png.4bpp \
	graphics/pokemon/masquerain/icon.png.4bpp \
	graphics/pokemon/mawile/icon.png.4bpp \
	graphics/pokemon/medicham/icon.png.4bpp \
	graphics/pokemon/meditite/icon.png.4bpp \
	graphics/pokemon/meganium/icon.png.4bpp \
	graphics/pokemon/meowth/icon.png.4bpp \
	graphics/pokemon/metagross/icon.png.4bpp \
	graphics/pokemon/metang/icon.png.4bpp \
	graphics/pokemon/metapod/icon.png.4bpp \
	graphics/pokemon/mew/icon.png.4bpp \
	graphics/pokemon/mewtwo/icon.png.4bpp \
	graphics/pokemon/mightyena/icon.png.4bpp \
	graphics/pokemon/milotic/icon.png.4bpp \
	graphics/pokemon/miltank/icon.png.4bpp \
	graphics/pokemon/minun/icon.png.4bpp \
	graphics/pokemon/misdreavus/icon.png.4bpp \
	graphics/pokemon/moltres/icon.png.4bpp \
	graphics/pokemon/mr_mime/icon.png.4bpp \
	graphics/pokemon/mudkip/icon.png.4bpp \
	graphics/pokemon/muk/icon.png.4bpp \
	graphics/pokemon/murkrow/icon.png.4bpp \
	graphics/pokemon/natu/icon.png.4bpp \
	graphics/pokemon/nidoking/icon.png.4bpp \
	graphics/pokemon/nidoqueen/icon.png.4bpp \
	graphics/pokemon/nidoran_f/icon.png.4bpp \
	graphics/pokemon/nidoran_m/icon.png.4bpp \
	graphics/pokemon/nidorina/icon.png.4bpp \
	graphics/pokemon/nidorino/icon.png.4bpp \
	graphics/pokemon/nincada/icon.png.4bpp \
	graphics/pokemon/ninetales/icon.png.4bpp \
	graphics/pokemon/ninjask/icon.png.4bpp \
	graphics/pokemon/noctowl/icon.png.4bpp \
	graphics/pokemon/nosepass/icon.png.4bpp \
	graphics/pokemon/numel/icon.png.4bpp \
	graphics/pokemon/nuzleaf/icon.png.4bpp \
	graphics/pokemon/octillery/icon.png.4bpp \
	graphics/pokemon/oddish/icon.png.4bpp \
	graphics/pokemon/omanyte/icon.png.4bpp \
	graphics/pokemon/omastar/icon.png.4bpp \
	graphics/pokemon/onix/icon.png.4bpp \
	graphics/pokemon/paras/icon.png.4bpp \
	graphics/pokemon/parasect/icon.png.4bpp \
	graphics/pokemon/pelipper/icon.png.4bpp \
	graphics/pokemon/persian/icon.png.4bpp \
	graphics/pokemon/phanpy/icon.png.4bpp \
	graphics/pokemon/pichu/icon.png.4bpp \
	graphics/pokemon/pidgeot/icon.png.4bpp \
	graphics/pokemon/pidgeotto/icon.png.4bpp \
	graphics/pokemon/pidgey/icon.png.4bpp \
	graphics/pokemon/pikachu/icon.png.4bpp \
	graphics/pokemon/piloswine/icon.png.4bpp \
	graphics/pokemon/pineco/icon.png.4bpp \
	graphics/pokemon/pinsir/icon.png.4bpp \
	graphics/pokemon/plusle/icon.png.4bpp \
	graphics/pokemon/politoed/icon.png.4bpp \
	graphics/pokemon/poliwag/icon.png.4bpp \
	graphics/pokemon/poliwhirl/icon.png.4bpp \
	graphics/pokemon/poliwrath/icon.png.4bpp \
	graphics/pokemon/ponyta/icon.png.4bpp \
	graphics/pokemon/poochyena/icon.png.4bpp \
	graphics/pokemon/porygon/icon.png.4bpp \
	graphics/pokemon/porygon2/icon.png.4bpp \
	graphics/pokemon/primeape/icon.png.4bpp \
	graphics/pokemon/psyduck/icon.png.4bpp \
	graphics/pokemon/pupitar/icon.png.4bpp \
	graphics/pokemon/quagsire/icon.png.4bpp \
	graphics/pokemon/question_mark/icon.png.4bpp \
	graphics/pokemon/quilava/icon.png.4bpp \
	graphics/pokemon/qwilfish/icon.png.4bpp \
	graphics/pokemon/raichu/icon.png.4bpp \
	graphics/pokemon/raikou/icon.png.4bpp \
	graphics/pokemon/ralts/icon.png.4bpp \
	graphics/pokemon/rapidash/icon.png.4bpp \
	graphics/pokemon/raticate/icon.png.4bpp \
	graphics/pokemon/rattata/icon.png.4bpp \
	graphics/pokemon/rayquaza/icon.png.4bpp \
	graphics/pokemon/regice/icon.png.4bpp \
	graphics/pokemon/regirock/icon.png.4bpp \
	graphics/pokemon/registeel/icon.png.4bpp \
	graphics/pokemon/relicanth/icon.png.4bpp \
	graphics/pokemon/remoraid/icon.png.4bpp \
	graphics/pokemon/rhydon/icon.png.4bpp \
	graphics/pokemon/rhyhorn/icon.png.4bpp \
	graphics/pokemon/roselia/icon.png.4bpp \
	graphics/pokemon/sableye/icon.png.4bpp \
	graphics/pokemon/salamence/icon.png.4bpp \
	graphics/pokemon/sandshrew/icon.png.4bpp \
	graphics/pokemon/sandslash/icon.png.4bpp \
	graphics/pokemon/sceptile/icon.png.4bpp \
	graphics/pokemon/scizor/icon.png.4bpp \
	graphics/pokemon/scyther/icon.png.4bpp \
	graphics/pokemon/seadra/icon.png.4bpp \
	graphics/pokemon/seaking/icon.png.4bpp \
	graphics/pokemon/sealeo/icon.png.4bpp \
	graphics/pokemon/seedot/icon.png.4bpp \
	graphics/pokemon/seel/icon.png.4bpp \
	graphics/pokemon/sentret/icon.png.4bpp \
	graphics/pokemon/seviper/icon.png.4bpp \
	graphics/pokemon/sharpedo/icon.png.4bpp \
	graphics/pokemon/shedinja/icon.png.4bpp \
	graphics/pokemon/shelgon/icon.png.4bpp \
	graphics/pokemon/shellder/icon.png.4bpp \
	graphics/pokemon/shiftry/icon.png.4bpp \
	graphics/pokemon/shroomish/icon.png.4bpp \
	graphics/pokemon/shuckle/icon.png.4bpp \
	graphics/pokemon/shuppet/icon.png.4bpp \
	graphics/pokemon/silcoon/icon.png.4bpp \
	graphics/pokemon/skarmory/icon.png.4bpp \
	graphics/pokemon/skiploom/icon.png.4bpp \
	graphics/pokemon/skitty/icon.png.4bpp \
	graphics/pokemon/slaking/icon.png.4bpp \
	graphics/pokemon/slakoth/icon.png.4bpp \
	graphics/pokemon/slowbro/icon.png.4bpp \
	graphics/pokemon/slowking/icon.png.4bpp \
	graphics/pokemon/slowpoke/icon.png.4bpp \
	graphics/pokemon/slugma/icon.png.4bpp \
	graphics/pokemon/smeargle/icon.png.4bpp \
	graphics/pokemon/smoochum/icon.png.4bpp \
	graphics/pokemon/sneasel/icon.png.4bpp \
	graphics/pokemon/snorlax/icon.png.4bpp \
	graphics/pokemon/snorunt/icon.png.4bpp \
	graphics/pokemon/snubbull/icon.png.4bpp \
	graphics/pokemon/solrock/icon.png.4bpp \
	graphics/pokemon/spearow/icon.png.4bpp \
	graphics/pokemon/spheal/icon.png.4bpp \
	graphics/pokemon/spinarak/icon.png.4bpp \
	graphics/pokemon/spinda/icon.png.4bpp \
	graphics/pokemon/spoink/icon.png.4bpp \
	graphics/pokemon/squirtle/icon.png.4bpp \
	graphics/pokemon/stantler/icon.png.4bpp \
	graphics/pokemon/starmie/icon.png.4bpp \
	graphics/pokemon/staryu/icon.png.4bpp \
	graphics/pokemon/steelix/icon.png.4bpp \
	graphics/pokemon/sudowoodo/icon.png.4bpp \
	graphics/pokemon/suicune/icon.png.4bpp \
	graphics/pokemon/sunflora/icon.png.4bpp \
	graphics/pokemon/sunkern/icon.png.4bpp \
	graphics/pokemon/surskit/icon.png.4bpp \
	graphics/pokemon/swablu/icon.png.4bpp \
	graphics/pokemon/swalot/icon.png.4bpp \
	graphics/pokemon/swampert/icon.png.4bpp \
	graphics/pokemon/swellow/icon.png.4bpp \
	graphics/pokemon/swinub/icon.png.4bpp \
	graphics/pokemon/taillow/icon.png.4bpp \
	graphics/pokemon/tangela/icon.png.4bpp \
	graphics/pokemon/tauros/icon.png.4bpp \
	graphics/pokemon/teddiursa/icon.png.4bpp \
	graphics/pokemon/tentacool/icon.png.4bpp \
	graphics/pokemon/tentacruel/icon.png.4bpp \
	graphics/pokemon/togepi/icon.png.4bpp \
	graphics/pokemon/togetic/icon.png.4bpp \
	graphics/pokemon/torchic/icon.png.4bpp \
	graphics/pokemon/torkoal/icon.png.4bpp \
	graphics/pokemon/totodile/icon.png.4bpp \
	graphics/pokemon/trapinch/icon.png.4bpp \
	graphics/pokemon/treecko/icon.png.4bpp \
	graphics/pokemon/tropius/icon.png.4bpp \
	graphics/pokemon/typhlosion/icon.png.4bpp \
	graphics/pokemon/tyranitar/icon.png.4bpp \
	graphics/pokemon/tyrogue/icon.png.4bpp \
	graphics/pokemon/umbreon/icon.png.4bpp \
	graphics/pokemon/unown/a/icon.png.4bpp \
	graphics/pokemon/unown/b/icon.png.4bpp \
	graphics/pokemon/unown/c/icon.png.4bpp \
	graphics/pokemon/unown/d/icon.png.4bpp \
	graphics/pokemon/unown/e/icon.png.4bpp \
	graphics/pokemon/unown/exclamation_mark/icon.png.4bpp \
	graphics/pokemon/unown/f/icon.png.4bpp \
	graphics/pokemon/unown/g/icon.png.4bpp \
	graphics/pokemon/unown/h/icon.png.4bpp \
	graphics/pokemon/unown/i/icon.png.4bpp \
	graphics/pokemon/unown/j/icon.png.4bpp \
	graphics/pokemon/unown/k/icon.png.4bpp \
	graphics/pokemon/unown/l/icon.png.4bpp \
	graphics/pokemon/unown/m/icon.png.4bpp \
	graphics/pokemon/unown/n/icon.png.4bpp \
	graphics/pokemon/unown/o/icon.png.4bpp \
	graphics/pokemon/unown/p/icon.png.4bpp \
	graphics/pokemon/unown/q/icon.png.4bpp \
	graphics/pokemon/unown/question_mark/icon.png.4bpp \
	graphics/pokemon/unown/r/icon.png.4bpp \
	graphics/pokemon/unown/s/icon.png.4bpp \
	graphics/pokemon/unown/t/icon.png.4bpp \
	graphics/pokemon/unown/u/icon.png.4bpp \
	graphics/pokemon/unown/v/icon.png.4bpp \
	graphics/pokemon/unown/w/icon.png.4bpp \
	graphics/pokemon/unown/x/icon.png.4bpp \
	graphics/pokemon/unown/y/icon.png.4bpp \
	graphics/pokemon/unown/z/icon.png.4bpp \
	graphics/pokemon/ursaring/icon.png.4bpp \
	graphics/pokemon/vaporeon/icon.png.4bpp \
	graphics/pokemon/venomoth/icon.png.4bpp \
	graphics/pokemon/venonat/icon.png.4bpp \
	graphics/pokemon/venusaur/icon.png.4bpp \
	graphics/pokemon/vibrava/icon.png.4bpp \
	graphics/pokemon/victreebel/icon.png.4bpp \
	graphics/pokemon/vigoroth/icon.png.4bpp \
	graphics/pokemon/vileplume/icon.png.4bpp \
	graphics/pokemon/volbeat/icon.png.4bpp \
	graphics/pokemon/voltorb/icon.png.4bpp \
	graphics/pokemon/vulpix/icon.png.4bpp \
	graphics/pokemon/wailmer/icon.png.4bpp \
	graphics/pokemon/wailord/icon.png.4bpp \
	graphics/pokemon/walrein/icon.png.4bpp \
	graphics/pokemon/wartortle/icon.png.4bpp \
	graphics/pokemon/weedle/icon.png.4bpp \
	graphics/pokemon/weepinbell/icon.png.4bpp \
	graphics/pokemon/weezing/icon.png.4bpp \
	graphics/pokemon/whiscash/icon.png.4bpp \
	graphics/pokemon/whismur/icon.png.4bpp \
	graphics/pokemon/wigglytuff/icon.png.4bpp \
	graphics/pokemon/wingull/icon.png.4bpp \
	graphics/pokemon/wobbuffet/icon.png.4bpp \
	graphics/pokemon/wooper/icon.png.4bpp \
	graphics/pokemon/wurmple/icon.png.4bpp \
	graphics/pokemon/wynaut/icon.png.4bpp \
	graphics/pokemon/xatu/icon.png.4bpp \
	graphics/pokemon/yanma/icon.png.4bpp \
	graphics/pokemon/zangoose/icon.png.4bpp \
	graphics/pokemon/zapdos/icon.png.4bpp \
	graphics/pokemon/zigzagoon/icon.png.4bpp \
	graphics/pokemon/zubat/icon.png.4bpp

JP_MON_ICON_PALETTES := graphics/pokemon/icon_palettes/icon_palette_0.pal.gbapal \
	graphics/pokemon/icon_palettes/icon_palette_1.pal.gbapal \
	graphics/pokemon/icon_palettes/icon_palette_2.pal.gbapal

JP_MON_ICON_ASSETS := $(JP_MON_ICON_GFX) $(JP_MON_ICON_PALETTES) graphics/pokemon/question_mark/footprint.png.1bpp

$(JP_MON_ICON_GFX): %.png.4bpp: %.png | tools
	$(GFX) $< $@

$(JP_MON_ICON_PALETTES): %.pal.gbapal: %.pal | tools
	$(GFX) $< $@

graphics/pokemon/question_mark/footprint.png.1bpp: graphics/pokemon/question_mark/footprint.png | tools
	$(GFX) $< $@

$(C_BUILDDIR)/graphics.o: src/data/graphics/pokemon.h $(JP_MON_ICON_ASSETS)

clean: clean-mon-icon-assets
.PHONY: clean-mon-icon-assets
clean-mon-icon-assets:
	rm -f $(JP_MON_ICON_ASSETS)

JP_UNUSED_POKENAV_ASSETS := graphics/pokenav/unused/menu.png_num_tiles_127.4bpp.lz \
	graphics/pokenav/unused/menu.bin.lz \
	graphics/pokenav/unused/toolbar.png.4bpp \
	graphics/pokenav/unused/toolbar.bin.lz \
	graphics/pokenav/unused/backdrop.png.4bpp \
	graphics/pokenav/unused/backdrop.bin.lz \
	graphics/pokenav/unused/outline.png_num_tiles_43.4bpp.lz \
	graphics/pokenav/unused/outline.bin.lz
JP_UNUSED_POKENAV_INTERMEDIATES := graphics/pokenav/unused/menu.png_num_tiles_127.4bpp \
	graphics/pokenav/unused/outline.png_num_tiles_43.4bpp

# The rectangular PNGs retain zero tiles beyond the native JP streams.
graphics/pokenav/unused/menu.png_num_tiles_127.4bpp: graphics/pokenav/unused/menu.png | tools
	$(GFX) $< $@ -num_tiles 127

graphics/pokenav/unused/toolbar.png.4bpp: graphics/pokenav/unused/toolbar.png | tools
	$(GFX) $< $@

graphics/pokenav/unused/backdrop.png.4bpp: graphics/pokenav/unused/backdrop.png | tools
	$(GFX) $< $@

graphics/pokenav/unused/outline.png_num_tiles_43.4bpp: graphics/pokenav/unused/outline.png | tools
	$(GFX) $< $@ -num_tiles 43

$(C_BUILDDIR)/graphics.o: src/data/graphics/unused_pokenav.h include/constants/rgb.h $(JP_UNUSED_POKENAV_ASSETS)

JP_FLDEFF_MISC_ASSETS := graphics/field_effects/pics/secret_power_cave.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/palettes/secret_power_cave.pal.gbapal \
	graphics/field_effects/pics/secret_power_shrub.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/pics/secret_power_tree.png_mwidth_2__mheight_2.4bpp \
	graphics/field_effects/palettes/secret_power_plant.pal.gbapal \
	graphics/field_effects/pics/sand_pillar/0.png.4bpp \
	graphics/field_effects/pics/sand_pillar/1.png.4bpp \
	graphics/field_effects/pics/sand_pillar/2.png.4bpp \
	graphics/field_effects/pics/record_mix_lights.png_mwidth_4__mheight_1.4bpp \
	graphics/field_effects/palettes/record_mix_lights.pal.gbapal

graphics/field_effects/pics/secret_power_cave.png_mwidth_2__mheight_2.4bpp: graphics/field_effects/pics/secret_power_cave.png | tools
	$(GFX) $< $@ -mwidth 2 -mheight 2

graphics/field_effects/palettes/secret_power_cave.pal.gbapal: graphics/field_effects/palettes/secret_power_cave.pal | tools
	$(GFX) $< $@

graphics/field_effects/pics/secret_power_shrub.png_mwidth_2__mheight_2.4bpp: graphics/field_effects/pics/secret_power_shrub.png | tools
	$(GFX) $< $@ -mwidth 2 -mheight 2

graphics/field_effects/pics/secret_power_tree.png_mwidth_2__mheight_2.4bpp: graphics/field_effects/pics/secret_power_tree.png | tools
	$(GFX) $< $@ -mwidth 2 -mheight 2

graphics/field_effects/palettes/secret_power_plant.pal.gbapal: graphics/field_effects/palettes/secret_power_plant.pal | tools
	$(GFX) $< $@

graphics/field_effects/pics/sand_pillar/0.png.4bpp: graphics/field_effects/pics/sand_pillar/0.png | tools
	$(GFX) $< $@

graphics/field_effects/pics/sand_pillar/1.png.4bpp: graphics/field_effects/pics/sand_pillar/1.png | tools
	$(GFX) $< $@

graphics/field_effects/pics/sand_pillar/2.png.4bpp: graphics/field_effects/pics/sand_pillar/2.png | tools
	$(GFX) $< $@

graphics/field_effects/pics/record_mix_lights.png_mwidth_4__mheight_1.4bpp: graphics/field_effects/pics/record_mix_lights.png | tools
	$(GFX) $< $@ -mwidth 4 -mheight 1

graphics/field_effects/palettes/record_mix_lights.pal.gbapal: graphics/field_effects/palettes/record_mix_lights.pal | tools
	$(GFX) $< $@

$(C_BUILDDIR)/fldeff_misc.o: src/fldeff_misc.c charmap.txt $(JP_FLDEFF_MISC_ASSETS) include/fldeff_misc.h include/constants/field_effects.h include/event_object_movement.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/fldeff_misc.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/fldeff_misc.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/fldeff_misc.gen.s

JP_BATTLE_ANIM_FAMILY_ASSETS := graphics/interface/blank.png.4bpp.lz \
	graphics/battle_anims/sprites/bubble.png.4bpp.lz \
	graphics/battle_anims/sprites/bone.png.4bpp.lz \
	graphics/battle_anims/sprites/air_wave.png.4bpp.lz \
	graphics/battle_anims/sprites/orb.png.4bpp.lz \
	graphics/battle_anims/sprites/sword.png.4bpp.lz \
	graphics/battle_anims/sprites/seed.png.4bpp.lz \
	graphics/battle_anims/sprites/rain_drops.png.gbapal.lz \
	graphics/battle_anims/sprites/bone.png.gbapal.lz \
	graphics/battle_anims/sprites/air_wave.png.gbapal.lz \
	graphics/battle_anims/sprites/orb.png.gbapal.lz \
	graphics/battle_anims/sprites/sword.png.gbapal.lz \
	graphics/battle_anims/sprites/seed.png.gbapal.lz \
	graphics/battle_anims/sprites/needle.png.4bpp.lz \
	graphics/battle_anims/sprites/needle.png.gbapal.lz \
	graphics/battle_anims/sprites/explosion_6.png.4bpp.lz \
	graphics/battle_anims/sprites/explosion_6.png.gbapal.lz \
	graphics/battle_anims/sprites/pink_orb.png.4bpp.lz \
	graphics/battle_anims/sprites/pink_orb.png.gbapal.lz \
	graphics/battle_anims/sprites/ice_cube.pal.gbapal.lz \
	graphics/battle_anims/sprites/ice_cube.4bpp.lz \
	graphics/battle_anims/sprites/gust.png.4bpp.lz \
	graphics/battle_anims/sprites/gust.png.gbapal.lz \
	graphics/battle_anims/sprites/spark_2.png.4bpp.lz \
	graphics/battle_anims/sprites/spark_2.png.gbapal.lz \
	graphics/battle_anims/sprites/orange.png.4bpp.lz \
	graphics/battle_anims/sprites/orange.png.gbapal.lz \
	graphics/battle_anims/sprites/spikes.png.4bpp.lz \
	graphics/battle_anims/sprites/spikes.png.gbapal.lz \
	graphics/battle_anims/sprites/yellow_ball.png.4bpp.lz \
	graphics/battle_anims/sprites/yellow_ball.png.gbapal.lz \
	graphics/battle_anims/sprites/tied_bag.png.4bpp.lz \
	graphics/battle_anims/sprites/tied_bag.png.gbapal.lz \
	graphics/battle_anims/sprites/black_smoke.png.4bpp.lz \
	graphics/battle_anims/sprites/black_smoke.png.gbapal.lz \
	graphics/battle_anims/sprites/black_ball.png.4bpp.lz \
	graphics/battle_anims/sprites/black_ball.pal.gbapal.lz \
	graphics/battle_anims/sprites/glass.png.gbapal.lz \
	graphics/battle_anims/sprites/glass.png.4bpp.lz \
	graphics/battle_anims/sprites/horn_hit.png.4bpp.lz \
	graphics/battle_anims/sprites/horn_hit.png.gbapal.lz \
	graphics/battle_anims/sprites/blue_shards.png.gbapal.lz \
	graphics/battle_anims/sprites/blue_shards.png.4bpp.lz \
	graphics/battle_anims/unused/music_notes.pal.gbapal.lz \
	graphics/battle_anims/unused/music_notes.png.4bpp.lz \
	graphics/battle_anims/sprites/hit.png.gbapal.lz \
	graphics/battle_anims/sprites/hit.png.4bpp.lz \
	graphics/battle_anims/sprites/hit_2.pal.gbapal.lz \
	graphics/battle_anims/sprites/waving_hand.png.gbapal.lz \
	graphics/battle_anims/sprites/waving_hand.png.4bpp.lz \
	graphics/battle_anims/sprites/closing_eye.png.4bpp.lz \
	graphics/battle_anims/sprites/closing_eye.png.gbapal.lz \
	graphics/battle_anims/sprites/blue_star.png.4bpp.lz \
	graphics/battle_anims/sprites/blue_star.png.gbapal.lz \
	graphics/battle_anims/sprites/bubble_burst.png.gbapal.lz \
	graphics/battle_anims/sprites/bubble_burst.png.4bpp.lz \
	graphics/battle_anims/sprites/hit_duplicate.png.4bpp.lz \
	graphics/battle_anims/sprites/hit_duplicate.png.gbapal.lz \
	graphics/battle_anims/sprites/leer.png.gbapal.lz \
	graphics/battle_anims/sprites/leer.png.4bpp.lz \
	graphics/battle_anims/sprites/blue_burst.png.gbapal.lz \
	graphics/battle_anims/sprites/blue_burst.png.4bpp.lz \
	graphics/battle_anims/sprites/small_ember.png.4bpp.lz \
	graphics/battle_anims/sprites/small_ember.png.gbapal.lz \
	graphics/battle_anims/sprites/gray_smoke.png.4bpp.lz \
	graphics/battle_anims/sprites/gray_smoke.png.gbapal.lz \
	graphics/battle_anims/sprites/fire.png.gbapal.lz \
	graphics/battle_anims/sprites/fire.png.4bpp.lz \
	graphics/battle_anims/sprites/spinning_fire.png.4bpp.lz \
	graphics/battle_anims/sprites/fire_plume.png.4bpp.lz \
	graphics/battle_anims/sprites/lightning_2.png.gbapal.lz \
	graphics/battle_anims/sprites/lightning_2.png.4bpp.lz \
	graphics/battle_anims/sprites/lightning.png.4bpp.lz \
	graphics/battle_anims/unused/spinning_ball.png.4bpp.lz \
	graphics/battle_anims/unused/spinning_ball.png.gbapal.lz \
	graphics/battle_anims/unused/spinning_ball_2.pal.gbapal.lz \
	graphics/unused/obi1.4bpp.lz \
	graphics/unused/obi_palpak1.gbapal.lz \
	graphics/unused/old_pal4.pal.gbapal.lz \
	graphics/unused/obi_palpak3.gbapal.lz \
	graphics/unused/obi2.4bpp.lz \
	graphics/unused/old_battle_interface_tilemap.bin.lz \
	graphics/battle_anims/sprites/claw_slash_2.png.gbapal.lz \
	graphics/battle_anims/sprites/claw_slash.png.gbapal.lz \
	graphics/battle_anims/sprites/claw_slash_2.png.4bpp.lz \
	graphics/battle_anims/sprites/claw_slash.png.4bpp.lz \
	graphics/battle_anims/sprites/scratch_3.png.4bpp.lz \
	graphics/battle_anims/sprites/scratch_2.png.4bpp.lz \
	graphics/battle_interface/hpbar_unused.png.4bpp.lz \
	graphics/battle_anims/sprites/bubble_burst_2.png.4bpp.lz \
	graphics/battle_anims/sprites/bubble_burst_2.png.gbapal.lz \
	graphics/battle_anims/sprites/ice_chunk.png.4bpp.lz \
	graphics/battle_anims/sprites/ice_chunk.png.gbapal.lz \
	graphics/battle_anims/sprites/glass_2.png.gbapal.lz \
	graphics/battle_anims/sprites/glass_2.png.4bpp.lz \
	graphics/battle_anims/sprites/pink_heart_2.png.gbapal.lz \
	graphics/battle_anims/sprites/pink_heart_2.png.4bpp.lz \
	graphics/battle_interface/unused_window.png.4bpp.lz \
	graphics/battle_interface/unused_window.png.gbapal.lz \
	graphics/battle_interface/battle_bar.4bpp.lz \
	graphics/battle_anims/sprites/sap_drip.png.4bpp.lz \
	graphics/battle_anims/sprites/sap_drip.png.gbapal.lz \
	graphics/battle_anims/sprites/sap_drip_2.pal.gbapal.lz \
	graphics/battle_interface/unused_window2.png.4bpp.lz \
	graphics/battle_interface/unused_window2bar.png_num_tiles_5__Wnum_tiles.4bpp.lz \
	graphics/battle_anims/sprites/sparkle_1.png.4bpp.lz \
	graphics/battle_anims/sprites/sparkle_1.png.gbapal.lz \
	graphics/battle_anims/sprites/sparkle_2.pal.gbapal.lz \
	graphics/battle_anims/sprites/humanoid_foot.png.gbapal.lz \
	graphics/battle_anims/sprites/humanoid_foot.png.4bpp.lz \
	graphics/battle_anims/sprites/monster_foot.png.4bpp.lz \
	graphics/battle_anims/sprites/humanoid_hand.png.4bpp.lz \
	graphics/battle_anims/unused/line_sketch.png.4bpp.lz \
	graphics/battle_anims/unused/line_sketch.png.gbapal.lz \
	graphics/battle_anims/sprites/yellow_unk.png.4bpp.lz \
	graphics/battle_anims/sprites/yellow_unk.png.gbapal.lz \
	graphics/battle_anims/sprites/slam_hit.png.4bpp.lz \
	graphics/battle_anims/sprites/slam_hit.png.gbapal.lz \
	graphics/battle_anims/sprites/red_fist.png.4bpp.lz \
	graphics/battle_anims/sprites/ring.png.4bpp.lz \
	graphics/battle_anims/sprites/ring.png.gbapal.lz \
	graphics/battle_anims/sprites/rocks.png.4bpp.lz \
	graphics/battle_anims/sprites/rocks.png.gbapal.lz \
	graphics/battle_anims/sprites/z.png.4bpp.lz \
	graphics/battle_anims/sprites/z.png.gbapal.lz \
	graphics/battle_anims/sprites/yellow_unk_2.png.4bpp.lz \
	graphics/battle_anims/sprites/yellow_unk_2.png.gbapal.lz \
	graphics/battle_anims/sprites/air_slash.png.4bpp.lz \
	graphics/battle_anims/sprites/air_slash.png.gbapal.lz \
	graphics/battle_anims/sprites/spinning_green_orbs.png.4bpp.lz \
	graphics/battle_anims/sprites/spinning_green_orbs.png.gbapal.lz \
	graphics/battle_anims/sprites/leaf.png.4bpp.lz \
	graphics/battle_anims/sprites/leaf.png.gbapal.lz \
	graphics/battle_anims/unused/metronome_hand_small.png.4bpp.lz \
	graphics/battle_anims/sprites/clapping.png.gbapal.lz \
	graphics/battle_anims/sprites/poison_powder.png.4bpp.lz \
	graphics/battle_anims/sprites/poison_powder.png.gbapal.lz \
	graphics/battle_anims/sprites/brown_triangle.png.4bpp.lz \
	graphics/battle_anims/sprites/brown_triangle.png.gbapal.lz \
	graphics/battle_anims/sprites/sparkle_3.png.4bpp.lz \
	graphics/battle_anims/sprites/sparkle_3.png.gbapal.lz \
	graphics/battle_anims/sprites/sparkle_4.png.4bpp.lz \
	graphics/battle_anims/sprites/music_notes.png.4bpp.lz \
	graphics/battle_anims/sprites/music_notes.png.gbapal.lz \
	graphics/battle_anims/sprites/duck.png.4bpp.lz \
	graphics/battle_anims/sprites/duck.png.gbapal.lz \
	graphics/battle_anims/sprites/alert.png.4bpp.lz \
	graphics/battle_anims/sprites/alert.png.gbapal.lz \
	graphics/battle_anims/sprites/shock_4.png.4bpp.lz \
	graphics/battle_anims/sprites/shock_4.png.gbapal.lz \
	graphics/battle_anims/sprites/shock.png.4bpp.lz \
	graphics/battle_anims/sprites/bell_2.png.4bpp.lz \
	graphics/battle_anims/sprites/bell_2.png.gbapal.lz \
	graphics/battle_anims/sprites/pink_glove.png.4bpp.lz \
	graphics/battle_anims/sprites/pink_glove.png.gbapal.lz \
	graphics/battle_anims/unused/line_sketch_2.png.8bpp.lz \
	graphics/battle_anims/unused/line_sketch_2.pal.gbapal.lz \
	graphics/battle_anims/unused/line_sketch_2.bin.lz \
	graphics/battle_anims/sprites/blue_lines.png.4bpp.lz \
	graphics/battle_anims/sprites/blue_lines.png.gbapal.lz \
	graphics/battle_anims/sprites/impact_3.png.gbapal.lz \
	graphics/battle_anims/sprites/impact_2.png.gbapal.lz \
	graphics/battle_anims/sprites/reticle.png.gbapal.lz \
	graphics/battle_anims/sprites/breath.png.gbapal.lz \
	graphics/battle_anims/sprites/snowball.png.gbapal.lz \
	graphics/battle_anims/sprites/vine.png.gbapal.lz \
	graphics/battle_anims/sprites/sword_2.png.gbapal.lz \
	graphics/battle_anims/sprites/red_tube.png.gbapal.lz \
	graphics/battle_anims/sprites/amnesia.png.gbapal.lz \
	graphics/battle_anims/sprites/string_2.png.gbapal.lz \
	graphics/battle_anims/unused/unknown_4.bin.lz \
	graphics/battle_anims/sprites/pencil_2.png.gbapal.lz \
	graphics/battle_anims/sprites/petal.png.gbapal.lz \
	graphics/battle_anims/sprites/bent_spoon.png.gbapal.lz \
	graphics/battle_anims/sprites/coin.png.gbapal.lz \
	graphics/battle_anims/sprites/cracked_egg.png.gbapal.lz \
	graphics/battle_anims/sprites/fresh_egg.png.gbapal.lz \
	graphics/battle_anims/sprites/impact_3.png.4bpp.lz \
	graphics/battle_anims/sprites/impact_2.png.4bpp.lz \
	graphics/battle_anims/sprites/reticle.png.4bpp.lz \
	graphics/battle_anims/sprites/breath.png.4bpp.lz \
	graphics/battle_anims/sprites/snowball.png.4bpp.lz \
	graphics/battle_anims/sprites/vine.png.4bpp.lz \
	graphics/battle_anims/sprites/sword_2.png.4bpp.lz \
	graphics/battle_anims/sprites/clapping.png.4bpp.lz \
	graphics/battle_anims/sprites/red_tube.png.4bpp.lz \
	graphics/battle_anims/sprites/amnesia.png.4bpp.lz \
	graphics/battle_anims/sprites/string_2.png.4bpp.lz \
	graphics/battle_anims/sprites/pencil_2.png.4bpp.lz \
	graphics/battle_anims/sprites/petal.png.4bpp.lz \
	graphics/battle_anims/sprites/bent_spoon.png.4bpp.lz \
	graphics/battle_anims/sprites/web.png.4bpp.lz \
	graphics/battle_anims/sprites/coin.png.4bpp.lz \
	graphics/battle_anims/sprites/cracked_egg.png.4bpp.lz \
	graphics/battle_anims/sprites/hatched_egg.png.4bpp.lz \
	graphics/battle_anims/sprites/fresh_egg.png.4bpp.lz \
	graphics/battle_anims/sprites/fangs.png.4bpp.lz \
	graphics/battle_anims/sprites/fangs.png.gbapal.lz \
	graphics/battle_anims/sprites/explosion_2.png.4bpp.lz \
	graphics/battle_anims/sprites/explosion_2.png.gbapal.lz \
	graphics/battle_anims/sprites/explosion_3.png.4bpp.lz \
	graphics/battle_anims/sprites/water_droplet.png.4bpp.lz \
	graphics/battle_anims/sprites/water_droplet.png.gbapal.lz \
	graphics/battle_anims/sprites/water_droplet_2.png.4bpp.lz \
	graphics/battle_anims/sprites/seed_2.png.4bpp.lz \
	graphics/battle_anims/sprites/seed_2.png.gbapal.lz \
	graphics/battle_anims/sprites/sprout.png.4bpp.lz \
	graphics/battle_anims/sprites/red_wand.png.4bpp.lz \
	graphics/battle_anims/sprites/red_wand.png.gbapal.lz \
	graphics/battle_anims/sprites/purple_green_unk.png.4bpp.lz \
	graphics/battle_anims/sprites/purple_green_unk.png.gbapal.lz \
	graphics/battle_anims/sprites/water_column.png.4bpp.lz \
	graphics/battle_anims/sprites/water_column.png.gbapal.lz \
	graphics/battle_anims/sprites/mud_unk.png.4bpp.lz \
	graphics/battle_anims/sprites/mud_unk.png.gbapal.lz \
	graphics/unused/blue_frame.bin.lz \
	graphics/unused/redyellowgreen_frame.bin.lz \
	graphics/unused/color_frames.png_num_tiles_353__Wnum_tiles.4bpp.lz \
	graphics/unused/color_frames.png.gbapal.lz \
	graphics/battle_anims/sprites/rain_drops.png.4bpp.lz \
	graphics/battle_anims/unused/water_splash.png.8bpp.lz \
	graphics/battle_anims/unused/water_splash.bin.lz \
	graphics/battle_anims/unused/water_splash.png.gbapal.lz \
	graphics/unused/basic_frame.png.4bpp.lz \
	graphics/unused/basic_frame.png.gbapal.lz \
	graphics/unused/basic_frame.bin.lz \
	graphics/battle_interface/unused_window3.png.4bpp.lz \
	graphics/battle_interface/unused_window4.png.4bpp.lz \
	graphics/battle_anims/sprites/fury_swipes.png.4bpp.lz \
	graphics/battle_anims/sprites/fury_swipes.png.gbapal.lz \
	graphics/battle_anims/sprites/vine_2.png.4bpp.lz \
	graphics/battle_anims/sprites/vine_2.png.gbapal.lz \
	graphics/battle_anims/sprites/teeth.png.4bpp.lz \
	graphics/battle_anims/sprites/teeth.png.gbapal.lz \
	graphics/battle_anims/sprites/bone_2.png.4bpp.lz \
	graphics/battle_anims/sprites/bone_2.png.gbapal.lz \
	graphics/battle_anims/sprites/white_bag.png.4bpp.lz \
	graphics/battle_anims/sprites/white_bag.png.gbapal.lz \
	graphics/battle_anims/sprites/unknown.png.4bpp.lz \
	graphics/battle_anims/sprites/unknown.png.gbapal.lz \
	graphics/battle_anims/sprites/purple_coral.png.4bpp.lz \
	graphics/battle_anims/sprites/purple_coral.png.gbapal.lz \
	graphics/battle_anims/sprites/purple_droplet.png.4bpp.lz \
	graphics/battle_anims/sprites/shock_2.png.4bpp.lz \
	graphics/battle_anims/sprites/shock_2.png.gbapal.lz \
	graphics/battle_anims/sprites/closing_eye_2.png.4bpp.lz \
	graphics/battle_anims/sprites/closing_eye_2.png.gbapal.lz \
	graphics/battle_anims/sprites/metal_ball.png.4bpp.lz \
	graphics/battle_anims/sprites/metal_ball.png.gbapal.lz \
	graphics/battle_anims/sprites/monster_doll.png.4bpp.lz \
	graphics/battle_anims/sprites/monster_doll.png.gbapal.lz \
	graphics/battle_anims/sprites/whirlwind.png.4bpp.lz \
	graphics/battle_anims/sprites/whirlwind.png.gbapal.lz \
	graphics/battle_anims/sprites/whirlwind_2.png.4bpp.lz \
	graphics/battle_anims/sprites/explosion_4.png.4bpp.lz \
	graphics/battle_anims/sprites/explosion_4.png.gbapal.lz \
	graphics/battle_anims/sprites/explosion_5.png.4bpp.lz \
	graphics/battle_anims/sprites/tongue.png.4bpp.lz \
	graphics/battle_anims/sprites/tongue.png.gbapal.lz \
	graphics/battle_anims/sprites/smoke.png.4bpp.lz \
	graphics/battle_anims/sprites/smoke.png.gbapal.lz \
	graphics/battle_anims/sprites/smoke_2.png.4bpp.lz \
	graphics/battle_anims/sprites/blue_flames.png.4bpp.lz \
	graphics/battle_anims/sprites/blue_flames.png.gbapal.lz \
	graphics/battle_anims/sprites/blue_flames_2.png.4bpp.lz
JP_BATTLE_ANIM_FAMILY_INTERMEDIATES := graphics/battle_anims/sprites/air_slash.png.4bpp \
	graphics/battle_anims/sprites/air_slash.png.gbapal \
	graphics/battle_anims/sprites/air_wave.png.4bpp \
	graphics/battle_anims/sprites/air_wave.png.gbapal \
	graphics/battle_anims/sprites/alert.png.4bpp \
	graphics/battle_anims/sprites/alert.png.gbapal \
	graphics/battle_anims/sprites/amnesia.png.4bpp \
	graphics/battle_anims/sprites/amnesia.png.gbapal \
	graphics/battle_anims/sprites/bell_2.png.4bpp \
	graphics/battle_anims/sprites/bell_2.png.gbapal \
	graphics/battle_anims/sprites/bent_spoon.png.4bpp \
	graphics/battle_anims/sprites/bent_spoon.png.gbapal \
	graphics/battle_anims/sprites/black_ball.pal.gbapal \
	graphics/battle_anims/sprites/black_ball.png.4bpp \
	graphics/battle_anims/sprites/black_smoke.png.4bpp \
	graphics/battle_anims/sprites/black_smoke.png.gbapal \
	graphics/battle_anims/sprites/blue_burst.png.4bpp \
	graphics/battle_anims/sprites/blue_burst.png.gbapal \
	graphics/battle_anims/sprites/blue_flames.png.4bpp \
	graphics/battle_anims/sprites/blue_flames.png.gbapal \
	graphics/battle_anims/sprites/blue_flames_2.png.4bpp \
	graphics/battle_anims/sprites/blue_lines.png.4bpp \
	graphics/battle_anims/sprites/blue_lines.png.gbapal \
	graphics/battle_anims/sprites/blue_shards.png.4bpp \
	graphics/battle_anims/sprites/blue_shards.png.gbapal \
	graphics/battle_anims/sprites/blue_star.png.4bpp \
	graphics/battle_anims/sprites/blue_star.png.gbapal \
	graphics/battle_anims/sprites/bone.png.4bpp \
	graphics/battle_anims/sprites/bone.png.gbapal \
	graphics/battle_anims/sprites/bone_2.png.4bpp \
	graphics/battle_anims/sprites/bone_2.png.gbapal \
	graphics/battle_anims/sprites/breath.png.4bpp \
	graphics/battle_anims/sprites/breath.png.gbapal \
	graphics/battle_anims/sprites/brown_triangle.png.4bpp \
	graphics/battle_anims/sprites/brown_triangle.png.gbapal \
	graphics/battle_anims/sprites/bubble.png.4bpp \
	graphics/battle_anims/sprites/bubble_burst.png.4bpp \
	graphics/battle_anims/sprites/bubble_burst.png.gbapal \
	graphics/battle_anims/sprites/bubble_burst_2.png.4bpp \
	graphics/battle_anims/sprites/bubble_burst_2.png.gbapal \
	graphics/battle_anims/sprites/clapping.png.4bpp \
	graphics/battle_anims/sprites/clapping.png.gbapal \
	graphics/battle_anims/sprites/claw_slash.png.4bpp \
	graphics/battle_anims/sprites/claw_slash.png.gbapal \
	graphics/battle_anims/sprites/claw_slash_2.png.4bpp \
	graphics/battle_anims/sprites/claw_slash_2.png.gbapal \
	graphics/battle_anims/sprites/closing_eye.png.4bpp \
	graphics/battle_anims/sprites/closing_eye.png.gbapal \
	graphics/battle_anims/sprites/closing_eye_2.png.4bpp \
	graphics/battle_anims/sprites/closing_eye_2.png.gbapal \
	graphics/battle_anims/sprites/coin.png.4bpp \
	graphics/battle_anims/sprites/coin.png.gbapal \
	graphics/battle_anims/sprites/cracked_egg.png.4bpp \
	graphics/battle_anims/sprites/cracked_egg.png.gbapal \
	graphics/battle_anims/sprites/duck.png.4bpp \
	graphics/battle_anims/sprites/duck.png.gbapal \
	graphics/battle_anims/sprites/explosion_2.png.4bpp \
	graphics/battle_anims/sprites/explosion_2.png.gbapal \
	graphics/battle_anims/sprites/explosion_3.png.4bpp \
	graphics/battle_anims/sprites/explosion_4.png.4bpp \
	graphics/battle_anims/sprites/explosion_4.png.gbapal \
	graphics/battle_anims/sprites/explosion_5.png.4bpp \
	graphics/battle_anims/sprites/explosion_6.png.4bpp \
	graphics/battle_anims/sprites/explosion_6.png.gbapal \
	graphics/battle_anims/sprites/fangs.png.4bpp \
	graphics/battle_anims/sprites/fangs.png.gbapal \
	graphics/battle_anims/sprites/fire.png.4bpp \
	graphics/battle_anims/sprites/fire.png.gbapal \
	graphics/battle_anims/sprites/fire_plume.png.4bpp \
	graphics/battle_anims/sprites/fresh_egg.png.4bpp \
	graphics/battle_anims/sprites/fresh_egg.png.gbapal \
	graphics/battle_anims/sprites/fury_swipes.png.4bpp \
	graphics/battle_anims/sprites/fury_swipes.png.gbapal \
	graphics/battle_anims/sprites/glass.png.4bpp \
	graphics/battle_anims/sprites/glass.png.gbapal \
	graphics/battle_anims/sprites/glass_2.png.4bpp \
	graphics/battle_anims/sprites/glass_2.png.gbapal \
	graphics/battle_anims/sprites/gray_smoke.png.4bpp \
	graphics/battle_anims/sprites/gray_smoke.png.gbapal \
	graphics/battle_anims/sprites/gust.png.4bpp \
	graphics/battle_anims/sprites/gust.png.gbapal \
	graphics/battle_anims/sprites/hatched_egg.png.4bpp \
	graphics/battle_anims/sprites/hit.png.4bpp \
	graphics/battle_anims/sprites/hit.png.gbapal \
	graphics/battle_anims/sprites/hit_2.pal.gbapal \
	graphics/battle_anims/sprites/hit_duplicate.png.4bpp \
	graphics/battle_anims/sprites/hit_duplicate.png.gbapal \
	graphics/battle_anims/sprites/horn_hit.png.4bpp \
	graphics/battle_anims/sprites/horn_hit.png.gbapal \
	graphics/battle_anims/sprites/humanoid_foot.png.4bpp \
	graphics/battle_anims/sprites/humanoid_foot.png.gbapal \
	graphics/battle_anims/sprites/humanoid_hand.png.4bpp \
	graphics/battle_anims/sprites/ice_chunk.png.4bpp \
	graphics/battle_anims/sprites/ice_chunk.png.gbapal \
	graphics/battle_anims/sprites/ice_cube.4bpp \
	graphics/battle_anims/sprites/ice_cube.pal.gbapal \
	graphics/battle_anims/sprites/ice_cube_0.png.4bpp \
	graphics/battle_anims/sprites/ice_cube_1.png.4bpp \
	graphics/battle_anims/sprites/ice_cube_2.png.4bpp \
	graphics/battle_anims/sprites/ice_cube_3.png.4bpp \
	graphics/battle_anims/sprites/impact_2.png.4bpp \
	graphics/battle_anims/sprites/impact_2.png.gbapal \
	graphics/battle_anims/sprites/impact_3.png.4bpp \
	graphics/battle_anims/sprites/impact_3.png.gbapal \
	graphics/battle_anims/sprites/leaf.png.4bpp \
	graphics/battle_anims/sprites/leaf.png.gbapal \
	graphics/battle_anims/sprites/leer.png.4bpp \
	graphics/battle_anims/sprites/leer.png.gbapal \
	graphics/battle_anims/sprites/lightning.png.4bpp \
	graphics/battle_anims/sprites/lightning_2.png.4bpp \
	graphics/battle_anims/sprites/lightning_2.png.gbapal \
	graphics/battle_anims/sprites/metal_ball.png.4bpp \
	graphics/battle_anims/sprites/metal_ball.png.gbapal \
	graphics/battle_anims/sprites/monster_doll.png.4bpp \
	graphics/battle_anims/sprites/monster_doll.png.gbapal \
	graphics/battle_anims/sprites/monster_foot.png.4bpp \
	graphics/battle_anims/sprites/mud_unk.png.4bpp \
	graphics/battle_anims/sprites/mud_unk.png.gbapal \
	graphics/battle_anims/sprites/music_notes.png.4bpp \
	graphics/battle_anims/sprites/music_notes.png.gbapal \
	graphics/battle_anims/sprites/needle.png.4bpp \
	graphics/battle_anims/sprites/needle.png.gbapal \
	graphics/battle_anims/sprites/orange.png.4bpp \
	graphics/battle_anims/sprites/orange.png.gbapal \
	graphics/battle_anims/sprites/orb.png.4bpp \
	graphics/battle_anims/sprites/orb.png.gbapal \
	graphics/battle_anims/sprites/pencil_2.png.4bpp \
	graphics/battle_anims/sprites/pencil_2.png.gbapal \
	graphics/battle_anims/sprites/petal.png.4bpp \
	graphics/battle_anims/sprites/petal.png.gbapal \
	graphics/battle_anims/sprites/pink_glove.png.4bpp \
	graphics/battle_anims/sprites/pink_glove.png.gbapal \
	graphics/battle_anims/sprites/pink_heart_2.png.4bpp \
	graphics/battle_anims/sprites/pink_heart_2.png.gbapal \
	graphics/battle_anims/sprites/pink_orb.png.4bpp \
	graphics/battle_anims/sprites/pink_orb.png.gbapal \
	graphics/battle_anims/sprites/poison_powder.png.4bpp \
	graphics/battle_anims/sprites/poison_powder.png.gbapal \
	graphics/battle_anims/sprites/purple_coral.png.4bpp \
	graphics/battle_anims/sprites/purple_coral.png.gbapal \
	graphics/battle_anims/sprites/purple_droplet.png.4bpp \
	graphics/battle_anims/sprites/purple_green_unk.png.4bpp \
	graphics/battle_anims/sprites/purple_green_unk.png.gbapal \
	graphics/battle_anims/sprites/rain_drops.png.4bpp \
	graphics/battle_anims/sprites/rain_drops.png.gbapal \
	graphics/battle_anims/sprites/red_fist.png.4bpp \
	graphics/battle_anims/sprites/red_tube.png.4bpp \
	graphics/battle_anims/sprites/red_tube.png.gbapal \
	graphics/battle_anims/sprites/red_wand.png.4bpp \
	graphics/battle_anims/sprites/red_wand.png.gbapal \
	graphics/battle_anims/sprites/reticle.png.4bpp \
	graphics/battle_anims/sprites/reticle.png.gbapal \
	graphics/battle_anims/sprites/ring.png.4bpp \
	graphics/battle_anims/sprites/ring.png.gbapal \
	graphics/battle_anims/sprites/rocks.png.4bpp \
	graphics/battle_anims/sprites/rocks.png.gbapal \
	graphics/battle_anims/sprites/sap_drip.png.4bpp \
	graphics/battle_anims/sprites/sap_drip.png.gbapal \
	graphics/battle_anims/sprites/sap_drip_2.pal.gbapal \
	graphics/battle_anims/sprites/scratch_2.png.4bpp \
	graphics/battle_anims/sprites/scratch_3.png.4bpp \
	graphics/battle_anims/sprites/seed.png.4bpp \
	graphics/battle_anims/sprites/seed.png.gbapal \
	graphics/battle_anims/sprites/seed_2.png.4bpp \
	graphics/battle_anims/sprites/seed_2.png.gbapal \
	graphics/battle_anims/sprites/shock.png.4bpp \
	graphics/battle_anims/sprites/shock_2.png.4bpp \
	graphics/battle_anims/sprites/shock_2.png.gbapal \
	graphics/battle_anims/sprites/shock_4.png.4bpp \
	graphics/battle_anims/sprites/shock_4.png.gbapal \
	graphics/battle_anims/sprites/slam_hit.png.4bpp \
	graphics/battle_anims/sprites/slam_hit.png.gbapal \
	graphics/battle_anims/sprites/small_ember.png.4bpp \
	graphics/battle_anims/sprites/small_ember.png.gbapal \
	graphics/battle_anims/sprites/smoke.png.4bpp \
	graphics/battle_anims/sprites/smoke.png.gbapal \
	graphics/battle_anims/sprites/smoke_2.png.4bpp \
	graphics/battle_anims/sprites/snowball.png.4bpp \
	graphics/battle_anims/sprites/snowball.png.gbapal \
	graphics/battle_anims/sprites/spark_2.png.4bpp \
	graphics/battle_anims/sprites/spark_2.png.gbapal \
	graphics/battle_anims/sprites/sparkle_1.png.4bpp \
	graphics/battle_anims/sprites/sparkle_1.png.gbapal \
	graphics/battle_anims/sprites/sparkle_2.pal.gbapal \
	graphics/battle_anims/sprites/sparkle_3.png.4bpp \
	graphics/battle_anims/sprites/sparkle_3.png.gbapal \
	graphics/battle_anims/sprites/sparkle_4.png.4bpp \
	graphics/battle_anims/sprites/spikes.png.4bpp \
	graphics/battle_anims/sprites/spikes.png.gbapal \
	graphics/battle_anims/sprites/spinning_fire.png.4bpp \
	graphics/battle_anims/sprites/spinning_green_orbs.png.4bpp \
	graphics/battle_anims/sprites/spinning_green_orbs.png.gbapal \
	graphics/battle_anims/sprites/sprout.png.4bpp \
	graphics/battle_anims/sprites/string_2.png.4bpp \
	graphics/battle_anims/sprites/string_2.png.gbapal \
	graphics/battle_anims/sprites/sword.png.4bpp \
	graphics/battle_anims/sprites/sword.png.gbapal \
	graphics/battle_anims/sprites/sword_2.png.4bpp \
	graphics/battle_anims/sprites/sword_2.png.gbapal \
	graphics/battle_anims/sprites/teeth.png.4bpp \
	graphics/battle_anims/sprites/teeth.png.gbapal \
	graphics/battle_anims/sprites/tied_bag.png.4bpp \
	graphics/battle_anims/sprites/tied_bag.png.gbapal \
	graphics/battle_anims/sprites/tongue.png.4bpp \
	graphics/battle_anims/sprites/tongue.png.gbapal \
	graphics/battle_anims/sprites/unknown.png.4bpp \
	graphics/battle_anims/sprites/unknown.png.gbapal \
	graphics/battle_anims/sprites/vine.png.4bpp \
	graphics/battle_anims/sprites/vine.png.gbapal \
	graphics/battle_anims/sprites/vine_2.png.4bpp \
	graphics/battle_anims/sprites/vine_2.png.gbapal \
	graphics/battle_anims/sprites/water_column.png.4bpp \
	graphics/battle_anims/sprites/water_column.png.gbapal \
	graphics/battle_anims/sprites/water_droplet.png.4bpp \
	graphics/battle_anims/sprites/water_droplet.png.gbapal \
	graphics/battle_anims/sprites/water_droplet_2.png.4bpp \
	graphics/battle_anims/sprites/waving_hand.png.4bpp \
	graphics/battle_anims/sprites/waving_hand.png.gbapal \
	graphics/battle_anims/sprites/web.png.4bpp \
	graphics/battle_anims/sprites/whirlwind.png.4bpp \
	graphics/battle_anims/sprites/whirlwind.png.gbapal \
	graphics/battle_anims/sprites/whirlwind_2.png.4bpp \
	graphics/battle_anims/sprites/white_bag.png.4bpp \
	graphics/battle_anims/sprites/white_bag.png.gbapal \
	graphics/battle_anims/sprites/yellow_ball.png.4bpp \
	graphics/battle_anims/sprites/yellow_ball.png.gbapal \
	graphics/battle_anims/sprites/yellow_unk.png.4bpp \
	graphics/battle_anims/sprites/yellow_unk.png.gbapal \
	graphics/battle_anims/sprites/yellow_unk_2.png.4bpp \
	graphics/battle_anims/sprites/yellow_unk_2.png.gbapal \
	graphics/battle_anims/sprites/z.png.4bpp \
	graphics/battle_anims/sprites/z.png.gbapal \
	graphics/battle_anims/unused/line_sketch.png.4bpp \
	graphics/battle_anims/unused/line_sketch.png.gbapal \
	graphics/battle_anims/unused/line_sketch_2.pal.gbapal \
	graphics/battle_anims/unused/line_sketch_2.png.8bpp \
	graphics/battle_anims/unused/metronome_hand_small.png.4bpp \
	graphics/battle_anims/unused/music_notes.pal.gbapal \
	graphics/battle_anims/unused/music_notes.png.4bpp \
	graphics/battle_anims/unused/spinning_ball.png.4bpp \
	graphics/battle_anims/unused/spinning_ball.png.gbapal \
	graphics/battle_anims/unused/spinning_ball_2.pal.gbapal \
	graphics/battle_anims/unused/water_splash.png.8bpp \
	graphics/battle_anims/unused/water_splash.png.gbapal \
	graphics/battle_interface/battle_bar.4bpp \
	graphics/battle_interface/hpbar_anim_unused.png.4bpp \
	graphics/battle_interface/hpbar_unused.png.4bpp \
	graphics/battle_interface/numbers1.png.4bpp \
	graphics/battle_interface/numbers2.png.4bpp \
	graphics/battle_interface/unused_window.png.4bpp \
	graphics/battle_interface/unused_window.png.gbapal \
	graphics/battle_interface/unused_window2.png.4bpp \
	graphics/battle_interface/unused_window2bar.png_num_tiles_5__Wnum_tiles.4bpp \
	graphics/battle_interface/unused_window3.png.4bpp \
	graphics/battle_interface/unused_window4.png.4bpp \
	graphics/interface/blank.png.4bpp \
	graphics/unused/basic_frame.png.4bpp \
	graphics/unused/basic_frame.png.gbapal \
	graphics/unused/color_frames.png.gbapal \
	graphics/unused/color_frames.png_num_tiles_353__Wnum_tiles.4bpp \
	graphics/unused/obi1.4bpp \
	graphics/unused/obi2.4bpp \
	graphics/unused/obi_palpak1.gbapal \
	graphics/unused/obi_palpak3.gbapal \
	graphics/unused/old_battle_interface_1.png.4bpp \
	graphics/unused/old_battle_interface_2.png.4bpp \
	graphics/unused/old_battle_interface_3.png.4bpp \
	graphics/unused/old_bulbasaur.png.4bpp \
	graphics/unused/old_bulbasaur2.png.4bpp \
	graphics/unused/old_charizard.png.4bpp \
	graphics/unused/old_pal1.pal.gbapal \
	graphics/unused/old_pal2.pal.gbapal \
	graphics/unused/old_pal3.pal.gbapal \
	graphics/unused/old_pal4.pal.gbapal \
	graphics/unused/old_pal5.pal.gbapal \
	graphics/unused/old_pal6.pal.gbapal \
	graphics/unused/old_pal7.pal.gbapal \
	graphics/unused/redyellowgreen_frame.bin

$(filter %.pal.gbapal,$(JP_BATTLE_ANIM_FAMILY_INTERMEDIATES)): %.pal.gbapal: %.pal Makefile | tools
	$(GFX) $< $@

$(filter %.png.4bpp,$(JP_BATTLE_ANIM_FAMILY_INTERMEDIATES)): %.png.4bpp: %.png Makefile | tools
	$(GFX) $< $@

$(filter %.png.8bpp,$(JP_BATTLE_ANIM_FAMILY_INTERMEDIATES)): %.png.8bpp: %.png Makefile | tools
	$(GFX) $< $@

$(filter %.png.gbapal,$(JP_BATTLE_ANIM_FAMILY_INTERMEDIATES)): %.png.gbapal: %.png Makefile | tools
	$(GFX) $< $@

graphics/battle_interface/unused_window2bar.png_num_tiles_5__Wnum_tiles.4bpp: graphics/battle_interface/unused_window2bar.png Makefile | tools
	$(GFX) $< $@ -num_tiles 5 -Wnum_tiles

graphics/unused/color_frames.png_num_tiles_353__Wnum_tiles.4bpp: graphics/unused/color_frames.png Makefile | tools
	$(GFX) $< $@ -num_tiles 353 -Wnum_tiles

$(JP_BATTLE_ANIM_FAMILY_ASSETS): %.lz: % Makefile | tools
	$(GFX) $< $@

$(C_BUILDDIR)/graphics.o: $(JP_BATTLE_ANIM_FAMILY_ASSETS)

JP_EVOLUTION_SCENE_ASSETS := graphics/evolution_scene/unused_1.pal.gbapal \
	graphics/evolution_scene/bg.png.4bpp.lz \
	graphics/evolution_scene/bg_inner.bin.lz \
	graphics/evolution_scene/bg_outer.bin.lz \
	graphics/evolution_scene/bg_anim_intro.pal.gbapal \
	graphics/evolution_scene/unused_2.pal.gbapal \
	graphics/evolution_scene/unused_3.pal.gbapal \
	graphics/evolution_scene/unused_4.pal.gbapal \
	graphics/evolution_scene/bg_anim.pal.gbapal
JP_EVOLUTION_SCENE_INTERMEDIATES := graphics/evolution_scene/bg.png.4bpp

$(filter %.pal.gbapal,$(JP_EVOLUTION_SCENE_ASSETS)): %.pal.gbapal: %.pal Makefile | tools
	$(GFX) $< $@

graphics/evolution_scene/bg.png.4bpp: graphics/evolution_scene/bg.png Makefile | tools
	$(GFX) $< $@

$(filter %.lz,$(JP_EVOLUTION_SCENE_ASSETS)): %.lz: % Makefile | tools
	$(GFX) $< $@

$(C_BUILDDIR)/evolution_scene.o: src/evolution_scene.c charmap.txt $(JP_EVOLUTION_SCENE_ASSETS)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/evolution_scene.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/evolution_scene.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/evolution_scene.gen.s

$(C_BUILDDIR)/pokemon.o: src/pokemon.c charmap.txt
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/pokemon.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/pokemon.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/pokemon.gen.s

JP_FRONTIER_UI_ASSETS := graphics/battle_frontier/arena_judgment_symbols.png.4bpp.lz \
	graphics/battle_frontier/arena_judgment_symbols.png.gbapal.lz \
	graphics/battle_frontier/dome_anim1.pal.gbapal \
	graphics/battle_frontier/dome_anim2.pal.gbapal \
	graphics/battle_frontier/dome_anim3.pal.gbapal \
	graphics/battle_frontier/dome_anim4.pal.gbapal \
	graphics/battle_frontier/multi_battle_intro_bg_opponent.bin.lz \
	graphics/battle_frontier/multi_battle_intro_bg_player.bin.lz \
	graphics/battle_frontier/pyramid_floor.pal.gbapal \
	graphics/battle_frontier/tourney_buttons.pal.gbapal.lz \
	graphics/battle_frontier/tourney_buttons.png.4bpp.lz \
	graphics/battle_frontier/tourney_info_card.png.4bpp.lz \
	graphics/battle_frontier/tourney_info_card_bg.bin.lz \
	graphics/battle_frontier/tourney_info_card_tilemap.bin.lz \
	graphics/battle_frontier/tourney_line.png.4bpp.lz \
	graphics/battle_frontier/tourney_line_down_map.bin.lz \
	graphics/battle_frontier/tourney_line_up_map.bin.lz \
	graphics/battle_frontier/tourney_match_card_bg.pal.gbapal.lz \
	graphics/battle_frontier/tourney_tree.bin.lz \
	graphics/battle_frontier/tourney_tree.png.4bpp.lz \
	graphics/battle_frontier/tourney_tree.png.gbapal.lz \
	graphics/battle_interface/text.pal.gbapal.lz \
	graphics/battle_interface/text_pp.pal.gbapal \
	graphics/intro/scene_1/text.pal.gbapal \
	graphics/intro/scene_2/player.pal.gbapal

JP_FRONTIER_UI_INTERMEDIATES := graphics/battle_frontier/arena_judgment_symbols.png.4bpp \
	graphics/battle_frontier/arena_judgment_symbols.png.gbapal \
	graphics/battle_frontier/tourney_buttons.pal.gbapal \
	graphics/battle_frontier/tourney_buttons.png.4bpp \
	graphics/battle_frontier/tourney_info_card.png.4bpp \
	graphics/battle_frontier/tourney_line.png.4bpp \
	graphics/battle_frontier/tourney_match_card_bg.pal.gbapal \
	graphics/battle_frontier/tourney_tree.png.4bpp \
	graphics/battle_frontier/tourney_tree.png.gbapal \
	graphics/battle_interface/text.pal.gbapal

graphics/battle_frontier/arena_judgment_symbols.png.4bpp graphics/battle_frontier/tourney_buttons.png.4bpp graphics/battle_frontier/tourney_info_card.png.4bpp graphics/battle_frontier/tourney_line.png.4bpp graphics/battle_frontier/tourney_tree.png.4bpp: %.png.4bpp: %.png Makefile | tools
	$(GFX) $< $@

graphics/battle_frontier/arena_judgment_symbols.png.gbapal graphics/battle_frontier/tourney_tree.png.gbapal: %.png.gbapal: %.png Makefile | tools
	$(GFX) $< $@

graphics/battle_frontier/dome_anim1.pal.gbapal graphics/battle_frontier/dome_anim2.pal.gbapal graphics/battle_frontier/dome_anim3.pal.gbapal graphics/battle_frontier/dome_anim4.pal.gbapal graphics/battle_frontier/pyramid_floor.pal.gbapal graphics/battle_frontier/tourney_buttons.pal.gbapal graphics/battle_frontier/tourney_match_card_bg.pal.gbapal graphics/battle_interface/text.pal.gbapal graphics/battle_interface/text_pp.pal.gbapal graphics/intro/scene_1/text.pal.gbapal graphics/intro/scene_2/player.pal.gbapal: %.pal.gbapal: %.pal Makefile | tools
	$(GFX) $< $@

$(filter %.lz,$(JP_FRONTIER_UI_ASSETS)): %.lz: % Makefile | tools
	$(GFX) $< $@

$(C_BUILDDIR)/graphics.o: $(JP_FRONTIER_UI_ASSETS)

JP_INTRO_SCENE_ASSETS := graphics/intro/scene_1/flygon.png.4bpp.lz \
	graphics/intro/scene_1/sparkle.png.4bpp.lz \
	graphics/intro/scene_1/text.pal.gbapal \
	graphics/intro/scene_2/brendan.png.4bpp.lz \
	graphics/intro/scene_2/flygon.png.4bpp.lz \
	graphics/intro/scene_2/flygon.png.gbapal \
	graphics/intro/scene_2/manectric.png.4bpp.lz \
	graphics/intro/scene_2/manectric.png.gbapal \
	graphics/intro/scene_2/may.png.4bpp.lz \
	graphics/intro/scene_2/player.pal.gbapal \
	graphics/intro/scene_2/torchic.png.4bpp.lz \
	graphics/intro/scene_2/torchic.png.gbapal \
	graphics/intro/scene_2/volbeat.png.4bpp.lz \
	graphics/intro/scene_2/volbeat.png.gbapal \
	graphics/intro/scene_3/bg.pal.gbapal \
	graphics/intro/scene_3/bubbles.png.4bpp.lz \
	graphics/intro/scene_3/bubbles.png.gbapal \
	graphics/intro/scene_3/clouds.png.4bpp.lz \
	graphics/intro/scene_3/clouds_left.bin.lz \
	graphics/intro/scene_3/clouds_right.bin.lz \
	graphics/intro/scene_3/clouds_sun.bin.lz \
	graphics/intro/scene_3/groudon.bin.lz \
	graphics/intro/scene_3/groudon.png.8bpp.lz \
	graphics/intro/scene_3/groudon_bg.bin.lz \
	graphics/intro/scene_3/kyogre.bin.lz \
	graphics/intro/scene_3/kyogre.png.8bpp.lz \
	graphics/intro/scene_3/kyogre_bg.bin.lz \
	graphics/intro/scene_3/legend_bg.png.4bpp.lz \
	graphics/intro/scene_3/lightning.png.4bpp.lz \
	graphics/intro/scene_3/lightning.png.gbapal \
	graphics/intro/scene_3/rayquaza.bin.lz \
	graphics/intro/scene_3/rayquaza.png.4bpp.lz \
	graphics/intro/scene_3/rayquaza_clouds.bin.lz \
	graphics/intro/scene_3/rayquaza_clouds.png.4bpp.lz \
	graphics/intro/scene_3/unused_1.bin.lz \
	graphics/intro/scene_3/unused_2.bin.lz

JP_INTRO_SCENE_INTERMEDIATES := graphics/intro/scene_1/flygon.png.4bpp \
	graphics/intro/scene_1/sparkle.png.4bpp \
	graphics/intro/scene_2/brendan.png.4bpp \
	graphics/intro/scene_2/flygon.png.4bpp \
	graphics/intro/scene_2/manectric.png.4bpp \
	graphics/intro/scene_2/may.png.4bpp \
	graphics/intro/scene_2/torchic.png.4bpp \
	graphics/intro/scene_2/volbeat.png.4bpp \
	graphics/intro/scene_3/bubbles.png.4bpp \
	graphics/intro/scene_3/clouds.png.4bpp \
	graphics/intro/scene_3/groudon.png.8bpp \
	graphics/intro/scene_3/kyogre.png.8bpp \
	graphics/intro/scene_3/legend_bg.png.4bpp \
	graphics/intro/scene_3/lightning.png.4bpp \
	graphics/intro/scene_3/rayquaza.png.4bpp \
	graphics/intro/scene_3/rayquaza_clouds.png.4bpp

graphics/intro/scene_1/flygon.png.4bpp graphics/intro/scene_1/sparkle.png.4bpp graphics/intro/scene_2/brendan.png.4bpp graphics/intro/scene_2/flygon.png.4bpp graphics/intro/scene_2/manectric.png.4bpp graphics/intro/scene_2/may.png.4bpp graphics/intro/scene_2/torchic.png.4bpp graphics/intro/scene_2/volbeat.png.4bpp graphics/intro/scene_3/bubbles.png.4bpp graphics/intro/scene_3/clouds.png.4bpp graphics/intro/scene_3/legend_bg.png.4bpp graphics/intro/scene_3/lightning.png.4bpp graphics/intro/scene_3/rayquaza.png.4bpp graphics/intro/scene_3/rayquaza_clouds.png.4bpp: %.png.4bpp: %.png Makefile | tools
	$(GFX) $< $@

graphics/intro/scene_3/groudon.png.8bpp graphics/intro/scene_3/kyogre.png.8bpp: %.png.8bpp: %.png Makefile | tools
	$(GFX) $< $@

graphics/intro/scene_2/flygon.png.gbapal graphics/intro/scene_2/manectric.png.gbapal graphics/intro/scene_2/torchic.png.gbapal graphics/intro/scene_2/volbeat.png.gbapal graphics/intro/scene_3/bubbles.png.gbapal graphics/intro/scene_3/lightning.png.gbapal: %.png.gbapal: %.png Makefile | tools
	$(GFX) $< $@

graphics/intro/scene_3/bg.pal.gbapal: %.pal.gbapal: %.pal Makefile | tools
	$(GFX) $< $@

$(filter %.lz,$(JP_INTRO_SCENE_ASSETS)): %.lz: % Makefile | tools
	$(GFX) $< $@

$(C_BUILDDIR)/graphics.o: src/data/graphics/intro_scene.h $(JP_INTRO_SCENE_ASSETS)

JP_INTRO_CREDITS_ASSETS := graphics/intro/scene_2/bicycle.png.4bpp.lz \
	graphics/intro/scene_2/brendan_credits.png.4bpp.lz \
	graphics/intro/scene_2/brendan_credits.png.gbapal \
	graphics/intro/scene_2/clouds.png.4bpp.lz \
	graphics/intro/scene_2/clouds.png.gbapal \
	graphics/intro/scene_2/clouds_bg.pal.gbapal \
	graphics/intro/scene_2/clouds_bg.png.4bpp.lz \
	graphics/intro/scene_2/clouds_bg_map.bin.lz \
	graphics/intro/scene_2/clouds_bg_sunset.pal.gbapal \
	graphics/intro/scene_2/clouds_sunset.pal.gbapal \
	graphics/intro/scene_2/grass.png.4bpp.lz \
	graphics/intro/scene_2/grass.png.gbapal \
	graphics/intro/scene_2/grass_map.bin.lz \
	graphics/intro/scene_2/grass_night.pal.gbapal \
	graphics/intro/scene_2/grass_sunset.pal.gbapal \
	graphics/intro/scene_2/house_silhouette.png.4bpp.lz \
	graphics/intro/scene_2/house_silhouette.png.gbapal \
	graphics/intro/scene_2/houses.pal.gbapal \
	graphics/intro/scene_2/houses.png.4bpp.lz \
	graphics/intro/scene_2/houses_map.bin.lz \
	graphics/intro/scene_2/latias.png.4bpp.lz \
	graphics/intro/scene_2/latias.png.gbapal \
	graphics/intro/scene_2/latios.png.4bpp.lz \
	graphics/intro/scene_2/latios.png.gbapal \
	graphics/intro/scene_2/may_credits.png.4bpp.lz \
	graphics/intro/scene_2/may_credits.png.gbapal \
	graphics/intro/scene_2/trees.png.4bpp.lz \
	graphics/intro/scene_2/trees.png.gbapal \
	graphics/intro/scene_2/trees_map.bin.lz \
	graphics/intro/scene_2/trees_small.png.4bpp.lz \
	graphics/intro/scene_2/trees_small.png.gbapal \
	graphics/intro/scene_2/trees_sunset.pal.gbapal

JP_INTRO_CREDITS_INTERMEDIATES := graphics/intro/scene_2/bicycle.png.4bpp \
	graphics/intro/scene_2/brendan_credits.png.4bpp \
	graphics/intro/scene_2/clouds.png.4bpp \
	graphics/intro/scene_2/clouds_bg.png.4bpp \
	graphics/intro/scene_2/grass.png.4bpp \
	graphics/intro/scene_2/house_silhouette.png.4bpp \
	graphics/intro/scene_2/houses.png.4bpp \
	graphics/intro/scene_2/latias.png.4bpp \
	graphics/intro/scene_2/latios.png.4bpp \
	graphics/intro/scene_2/may_credits.png.4bpp \
	graphics/intro/scene_2/trees.png.4bpp \
	graphics/intro/scene_2/trees_small.png.4bpp

graphics/intro/scene_2/bicycle.png.4bpp graphics/intro/scene_2/brendan_credits.png.4bpp graphics/intro/scene_2/clouds.png.4bpp graphics/intro/scene_2/clouds_bg.png.4bpp graphics/intro/scene_2/grass.png.4bpp graphics/intro/scene_2/house_silhouette.png.4bpp graphics/intro/scene_2/houses.png.4bpp graphics/intro/scene_2/latias.png.4bpp graphics/intro/scene_2/latios.png.4bpp graphics/intro/scene_2/may_credits.png.4bpp graphics/intro/scene_2/trees.png.4bpp graphics/intro/scene_2/trees_small.png.4bpp: %.png.4bpp: %.png Makefile | tools
	$(GFX) $< $@

graphics/intro/scene_2/brendan_credits.png.gbapal graphics/intro/scene_2/clouds.png.gbapal graphics/intro/scene_2/grass.png.gbapal graphics/intro/scene_2/house_silhouette.png.gbapal graphics/intro/scene_2/latias.png.gbapal graphics/intro/scene_2/latios.png.gbapal graphics/intro/scene_2/may_credits.png.gbapal graphics/intro/scene_2/trees.png.gbapal graphics/intro/scene_2/trees_small.png.gbapal: %.png.gbapal: %.png Makefile | tools
	$(GFX) $< $@

graphics/intro/scene_2/clouds_bg.pal.gbapal graphics/intro/scene_2/clouds_bg_sunset.pal.gbapal graphics/intro/scene_2/clouds_sunset.pal.gbapal graphics/intro/scene_2/grass_night.pal.gbapal graphics/intro/scene_2/grass_sunset.pal.gbapal graphics/intro/scene_2/houses.pal.gbapal graphics/intro/scene_2/trees_sunset.pal.gbapal: %.pal.gbapal: %.pal Makefile | tools
	$(GFX) $< $@

$(filter %.lz,$(JP_INTRO_CREDITS_ASSETS)): %.lz: % Makefile | tools
	$(GFX) $< $@

$(C_BUILDDIR)/intro_credits_graphics.o: src/intro_credits_graphics.c charmap.txt include/intro_credits_graphics.h include/graphics.h $(JP_INTRO_CREDITS_ASSETS)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/intro_credits_graphics.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/intro_credits_graphics.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/intro_credits_graphics.gen.s

JP_BATTLE_ENTRY_ASSETS := graphics/battle_environment/building/anim_map.bin.lz \
	graphics/battle_environment/building/anim_tiles.png.4bpp.lz \
	graphics/battle_environment/building/gym.pal.gbapal.lz \
	graphics/battle_environment/building/leader.pal.gbapal.lz \
	graphics/battle_environment/building/map.bin.lz \
	graphics/battle_environment/building/palette.pal.gbapal.lz \
	graphics/battle_environment/building/tiles.png.4bpp.lz \
	graphics/battle_environment/cave/anim_map.bin.lz \
	graphics/battle_environment/cave/anim_tiles.png.4bpp.lz \
	graphics/battle_environment/cave/groudon.pal.gbapal.lz \
	graphics/battle_environment/cave/map.bin.lz \
	graphics/battle_environment/cave/palette.pal.gbapal.lz \
	graphics/battle_environment/cave/tiles.png.4bpp.lz \
	graphics/battle_environment/long_grass/anim_map.bin.lz \
	graphics/battle_environment/long_grass/anim_tiles.png.4bpp.lz \
	graphics/battle_environment/long_grass/map.bin.lz \
	graphics/battle_environment/long_grass/palette.pal.gbapal.lz \
	graphics/battle_environment/long_grass/tiles.png.4bpp.lz \
	graphics/battle_environment/plain/palette.pal.gbapal.lz \
	graphics/battle_environment/pond_water/anim_map.bin.lz \
	graphics/battle_environment/pond_water/anim_tiles.png.4bpp.lz \
	graphics/battle_environment/pond_water/map.bin.lz \
	graphics/battle_environment/pond_water/palette.pal.gbapal.lz \
	graphics/battle_environment/pond_water/tiles.png.4bpp.lz \
	graphics/battle_environment/rock/anim_map.bin.lz \
	graphics/battle_environment/rock/anim_tiles.png.4bpp.lz \
	graphics/battle_environment/rock/map.bin.lz \
	graphics/battle_environment/rock/palette.pal.gbapal.lz \
	graphics/battle_environment/rock/tiles.png.4bpp.lz \
	graphics/battle_environment/sand/anim_map.bin.lz \
	graphics/battle_environment/sand/anim_tiles.png.4bpp.lz \
	graphics/battle_environment/sand/map.bin.lz \
	graphics/battle_environment/sand/palette.pal.gbapal.lz \
	graphics/battle_environment/sand/tiles.png.4bpp.lz \
	graphics/battle_environment/sky/anim_map.bin.lz \
	graphics/battle_environment/sky/anim_tiles.png.4bpp.lz \
	graphics/battle_environment/sky/map.bin.lz \
	graphics/battle_environment/sky/palette.pal.gbapal.lz \
	graphics/battle_environment/sky/tiles.png.4bpp.lz \
	graphics/battle_environment/stadium/aqua.pal.gbapal.lz \
	graphics/battle_environment/stadium/battle_frontier.pal.gbapal.lz \
	graphics/battle_environment/stadium/drake.pal.gbapal.lz \
	graphics/battle_environment/stadium/glacia.pal.gbapal.lz \
	graphics/battle_environment/stadium/magma.pal.gbapal.lz \
	graphics/battle_environment/stadium/map.bin.lz \
	graphics/battle_environment/stadium/phoebe.pal.gbapal.lz \
	graphics/battle_environment/stadium/sidney.pal.gbapal.lz \
	graphics/battle_environment/stadium/tiles.png.4bpp.lz \
	graphics/battle_environment/stadium/wallace.pal.gbapal.lz \
	graphics/battle_environment/tall_grass/anim_map.bin.lz \
	graphics/battle_environment/tall_grass/anim_tiles.png.4bpp.lz \
	graphics/battle_environment/tall_grass/map.bin.lz \
	graphics/battle_environment/tall_grass/palette.pal.gbapal.lz \
	graphics/battle_environment/tall_grass/tiles.png.4bpp.lz \
	graphics/battle_environment/underwater/anim_map.bin.lz \
	graphics/battle_environment/underwater/anim_tiles.png.4bpp.lz \
	graphics/battle_environment/underwater/map.bin.lz \
	graphics/battle_environment/underwater/palette.pal.gbapal.lz \
	graphics/battle_environment/underwater/tiles.png.4bpp.lz \
	graphics/battle_environment/water/anim_map.bin.lz \
	graphics/battle_environment/water/anim_tiles.png.4bpp.lz \
	graphics/battle_environment/water/kyogre.pal.gbapal.lz \
	graphics/battle_environment/water/map.bin.lz \
	graphics/battle_environment/water/palette.pal.gbapal.lz \
	graphics/battle_environment/water/tiles.png.4bpp.lz \
	graphics/battle_transitions/vs.png.4bpp.lz \
	graphics/battle_transitions/vs_frame.bin.lz \
	graphics/battle_transitions/vs_frame.png.gbapal.lz \
	graphics/battle_transitions/vs_frame.png_num_tiles_16__Wnum_tiles.4bpp.lz

JP_BATTLE_ENTRY_INTERMEDIATES := graphics/battle_environment/building/anim_tiles.png.4bpp \
	graphics/battle_environment/building/gym.pal.gbapal \
	graphics/battle_environment/building/leader.pal.gbapal \
	graphics/battle_environment/building/palette.pal.gbapal \
	graphics/battle_environment/building/tiles.png.4bpp \
	graphics/battle_environment/cave/anim_tiles.png.4bpp \
	graphics/battle_environment/cave/groudon.pal.gbapal \
	graphics/battle_environment/cave/palette.pal.gbapal \
	graphics/battle_environment/cave/tiles.png.4bpp \
	graphics/battle_environment/long_grass/anim_tiles.png.4bpp \
	graphics/battle_environment/long_grass/palette.pal.gbapal \
	graphics/battle_environment/long_grass/tiles.png.4bpp \
	graphics/battle_environment/plain/palette.pal.gbapal \
	graphics/battle_environment/pond_water/anim_tiles.png.4bpp \
	graphics/battle_environment/pond_water/palette.pal.gbapal \
	graphics/battle_environment/pond_water/tiles.png.4bpp \
	graphics/battle_environment/rock/anim_tiles.png.4bpp \
	graphics/battle_environment/rock/palette.pal.gbapal \
	graphics/battle_environment/rock/tiles.png.4bpp \
	graphics/battle_environment/sand/anim_tiles.png.4bpp \
	graphics/battle_environment/sand/palette.pal.gbapal \
	graphics/battle_environment/sand/tiles.png.4bpp \
	graphics/battle_environment/sky/anim_tiles.png.4bpp \
	graphics/battle_environment/sky/palette.pal.gbapal \
	graphics/battle_environment/sky/tiles.png.4bpp \
	graphics/battle_environment/stadium/aqua.pal.gbapal \
	graphics/battle_environment/stadium/battle_frontier.pal.gbapal \
	graphics/battle_environment/stadium/drake.pal.gbapal \
	graphics/battle_environment/stadium/glacia.pal.gbapal \
	graphics/battle_environment/stadium/magma.pal.gbapal \
	graphics/battle_environment/stadium/phoebe.pal.gbapal \
	graphics/battle_environment/stadium/sidney.pal.gbapal \
	graphics/battle_environment/stadium/tiles.png.4bpp \
	graphics/battle_environment/stadium/wallace.pal.gbapal \
	graphics/battle_environment/tall_grass/anim_tiles.png.4bpp \
	graphics/battle_environment/tall_grass/palette.pal.gbapal \
	graphics/battle_environment/tall_grass/tiles.png.4bpp \
	graphics/battle_environment/underwater/anim_tiles.png.4bpp \
	graphics/battle_environment/underwater/palette.pal.gbapal \
	graphics/battle_environment/underwater/tiles.png.4bpp \
	graphics/battle_environment/water/anim_tiles.png.4bpp \
	graphics/battle_environment/water/kyogre.pal.gbapal \
	graphics/battle_environment/water/palette.pal.gbapal \
	graphics/battle_environment/water/tiles.png.4bpp \
	graphics/battle_transitions/vs.png.4bpp \
	graphics/battle_transitions/vs_frame.png.gbapal \
	graphics/battle_transitions/vs_frame.png_num_tiles_16__Wnum_tiles.4bpp

graphics/battle_environment/building/anim_tiles.png.4bpp graphics/battle_environment/building/tiles.png.4bpp graphics/battle_environment/cave/anim_tiles.png.4bpp graphics/battle_environment/cave/tiles.png.4bpp graphics/battle_environment/long_grass/anim_tiles.png.4bpp graphics/battle_environment/long_grass/tiles.png.4bpp graphics/battle_environment/pond_water/anim_tiles.png.4bpp graphics/battle_environment/pond_water/tiles.png.4bpp graphics/battle_environment/rock/anim_tiles.png.4bpp graphics/battle_environment/rock/tiles.png.4bpp graphics/battle_environment/sand/anim_tiles.png.4bpp graphics/battle_environment/sand/tiles.png.4bpp graphics/battle_environment/sky/anim_tiles.png.4bpp graphics/battle_environment/sky/tiles.png.4bpp graphics/battle_environment/stadium/tiles.png.4bpp graphics/battle_environment/tall_grass/anim_tiles.png.4bpp graphics/battle_environment/tall_grass/tiles.png.4bpp graphics/battle_environment/underwater/anim_tiles.png.4bpp graphics/battle_environment/underwater/tiles.png.4bpp graphics/battle_environment/water/anim_tiles.png.4bpp graphics/battle_environment/water/tiles.png.4bpp graphics/battle_transitions/vs.png.4bpp: %.png.4bpp: %.png Makefile | tools
	$(GFX) $< $@

graphics/battle_transitions/vs_frame.png.gbapal: %.png.gbapal: %.png Makefile | tools
	$(GFX) $< $@

graphics/battle_environment/building/gym.pal.gbapal graphics/battle_environment/building/leader.pal.gbapal graphics/battle_environment/building/palette.pal.gbapal graphics/battle_environment/cave/groudon.pal.gbapal graphics/battle_environment/cave/palette.pal.gbapal graphics/battle_environment/long_grass/palette.pal.gbapal graphics/battle_environment/plain/palette.pal.gbapal graphics/battle_environment/pond_water/palette.pal.gbapal graphics/battle_environment/rock/palette.pal.gbapal graphics/battle_environment/sand/palette.pal.gbapal graphics/battle_environment/sky/palette.pal.gbapal graphics/battle_environment/stadium/aqua.pal.gbapal graphics/battle_environment/stadium/battle_frontier.pal.gbapal graphics/battle_environment/stadium/drake.pal.gbapal graphics/battle_environment/stadium/glacia.pal.gbapal graphics/battle_environment/stadium/magma.pal.gbapal graphics/battle_environment/stadium/phoebe.pal.gbapal graphics/battle_environment/stadium/sidney.pal.gbapal graphics/battle_environment/stadium/wallace.pal.gbapal graphics/battle_environment/tall_grass/palette.pal.gbapal graphics/battle_environment/underwater/palette.pal.gbapal graphics/battle_environment/water/kyogre.pal.gbapal graphics/battle_environment/water/palette.pal.gbapal: %.pal.gbapal: %.pal Makefile | tools
	$(GFX) $< $@

graphics/battle_transitions/vs_frame.png_num_tiles_16__Wnum_tiles.4bpp: graphics/battle_transitions/vs_frame.png Makefile | tools
	$(GFX) $< $@ -num_tiles 16 -Wnum_tiles

$(JP_BATTLE_ENTRY_ASSETS): %.lz: % Makefile | tools
	$(GFX) $< $@

$(C_BUILDDIR)/graphics.o: src/data/graphics/battle_environment.h $(JP_BATTLE_ENTRY_ASSETS)

JP_BATTLE_ANIM_REMAINING_ASSETS := graphics/battle_anims/backgrounds/attract.bin.lz \
	graphics/battle_anims/backgrounds/attract.png.4bpp.lz \
	graphics/battle_anims/backgrounds/attract.png.gbapal.lz \
	graphics/battle_anims/backgrounds/aurora.bin.lz \
	graphics/battle_anims/backgrounds/aurora.png.4bpp.lz \
	graphics/battle_anims/backgrounds/aurora.png.gbapal.lz \
	graphics/battle_anims/backgrounds/bug.pal.gbapal.lz \
	graphics/battle_anims/backgrounds/cosmic.bin.lz \
	graphics/battle_anims/backgrounds/cosmic.png.4bpp.lz \
	graphics/battle_anims/backgrounds/cosmic.png.gbapal.lz \
	graphics/battle_anims/backgrounds/dark.bin.lz \
	graphics/battle_anims/backgrounds/dark.png.4bpp.lz \
	graphics/battle_anims/backgrounds/dark.png.gbapal.lz \
	graphics/battle_anims/backgrounds/drill.bin.lz \
	graphics/battle_anims/backgrounds/drill.png.4bpp.lz \
	graphics/battle_anims/backgrounds/drill.png.gbapal.lz \
	graphics/battle_anims/backgrounds/drill_contests.bin.lz \
	graphics/battle_anims/backgrounds/fissure.bin.lz \
	graphics/battle_anims/backgrounds/fissure.png.4bpp.lz \
	graphics/battle_anims/backgrounds/fissure.png.gbapal.lz \
	graphics/battle_anims/backgrounds/fog.bin.lz \
	graphics/battle_anims/backgrounds/ghost.bin.lz \
	graphics/battle_anims/backgrounds/ghost.png.4bpp.lz \
	graphics/battle_anims/backgrounds/ghost.png.gbapal.lz \
	graphics/battle_anims/backgrounds/guillotine.png.4bpp.lz \
	graphics/battle_anims/backgrounds/guillotine.png.gbapal.lz \
	graphics/battle_anims/backgrounds/guillotine_contests.bin.lz \
	graphics/battle_anims/backgrounds/guillotine_opponent.bin.lz \
	graphics/battle_anims/backgrounds/guillotine_player.bin.lz \
	graphics/battle_anims/backgrounds/highspeed.png.4bpp.lz \
	graphics/battle_anims/backgrounds/highspeed.png.gbapal.lz \
	graphics/battle_anims/backgrounds/highspeed_opponent.bin.lz \
	graphics/battle_anims/backgrounds/highspeed_player.bin.lz \
	graphics/battle_anims/backgrounds/ice.bin.lz \
	graphics/battle_anims/backgrounds/ice.png.4bpp.lz \
	graphics/battle_anims/backgrounds/ice.png.gbapal.lz \
	graphics/battle_anims/backgrounds/impact.png.4bpp.lz \
	graphics/battle_anims/backgrounds/impact.png.gbapal.lz \
	graphics/battle_anims/backgrounds/impact_contests.bin.lz \
	graphics/battle_anims/backgrounds/impact_opponent.bin.lz \
	graphics/battle_anims/backgrounds/impact_player.bin.lz \
	graphics/battle_anims/backgrounds/in_air.bin.lz \
	graphics/battle_anims/backgrounds/in_air.png.4bpp.lz \
	graphics/battle_anims/backgrounds/in_air.png.gbapal.lz \
	graphics/battle_anims/backgrounds/psychic.bin.lz \
	graphics/battle_anims/backgrounds/psychic.png.4bpp.lz \
	graphics/battle_anims/backgrounds/psychic.png.gbapal.lz \
	graphics/battle_anims/backgrounds/sandstorm_brew.bin.lz \
	graphics/battle_anims/backgrounds/sandstorm_brew.png.4bpp.lz \
	graphics/battle_anims/backgrounds/scary_face.png.4bpp.lz \
	graphics/battle_anims/backgrounds/scary_face.png.gbapal.lz \
	graphics/battle_anims/backgrounds/scary_face_contest.bin.lz \
	graphics/battle_anims/backgrounds/scary_face_opponent.bin.lz \
	graphics/battle_anims/backgrounds/scary_face_player.bin.lz \
	graphics/battle_anims/backgrounds/sky.pal.gbapal.lz \
	graphics/battle_anims/backgrounds/solarbeam.bin.lz \
	graphics/battle_anims/backgrounds/solarbeam.pal.gbapal.lz \
	graphics/battle_anims/backgrounds/thunder.bin.lz \
	graphics/battle_anims/backgrounds/thunder.png.4bpp.lz \
	graphics/battle_anims/backgrounds/thunder.png.gbapal.lz \
	graphics/battle_anims/backgrounds/water.png.4bpp.lz \
	graphics/battle_anims/backgrounds/water.png.gbapal.lz \
	graphics/battle_anims/backgrounds/water_contest.bin.lz \
	graphics/battle_anims/backgrounds/water_muddy.pal.gbapal.lz \
	graphics/battle_anims/backgrounds/water_opponent.bin.lz \
	graphics/battle_anims/backgrounds/water_player.bin.lz \
	graphics/battle_anims/masks/cure_bubbles.bin.lz \
	graphics/battle_anims/masks/cure_bubbles.png.4bpp.lz \
	graphics/battle_anims/masks/cure_bubbles.png.gbapal.lz \
	graphics/battle_anims/masks/curse.bin.lz \
	graphics/battle_anims/masks/curse.png.4bpp.lz \
	graphics/battle_anims/masks/light_beam.bin.lz \
	graphics/battle_anims/masks/light_beam.png.4bpp.lz \
	graphics/battle_anims/masks/light_beam.png.gbapal.lz \
	graphics/battle_anims/masks/metal_shine.bin.lz \
	graphics/battle_anims/masks/metal_shine.png.4bpp.lz \
	graphics/battle_anims/masks/metal_shine.png.gbapal.lz \
	graphics/battle_anims/masks/unused_level_up.bin.lz \
	graphics/battle_anims/masks/unused_level_up.png_num_tiles_14__Wnum_tiles.4bpp.lz \
	graphics/battle_anims/sprites/air_wave_2.png.4bpp.lz \
	graphics/battle_anims/sprites/air_wave_2.png.gbapal.lz \
	graphics/battle_anims/sprites/angel.png.4bpp.lz \
	graphics/battle_anims/sprites/angel.png.gbapal.lz \
	graphics/battle_anims/sprites/anger.png.4bpp.lz \
	graphics/battle_anims/sprites/anger.png.gbapal.lz \
	graphics/battle_anims/sprites/bell.png.4bpp.lz \
	graphics/battle_anims/sprites/bell.png.gbapal.lz \
	graphics/battle_anims/sprites/bird.png.4bpp.lz \
	graphics/battle_anims/sprites/bird.png.gbapal.lz \
	graphics/battle_anims/sprites/black_ball_2.png.4bpp.lz \
	graphics/battle_anims/sprites/black_ball_2.png.gbapal.lz \
	graphics/battle_anims/sprites/blue_light_wall.pal.gbapal.lz \
	graphics/battle_anims/sprites/blue_orb.pal.gbapal.lz \
	graphics/battle_anims/sprites/blue_ring.pal.gbapal.lz \
	graphics/battle_anims/sprites/blue_ring_2.pal.gbapal.lz \
	graphics/battle_anims/sprites/bluegreen_orb.png.4bpp.lz \
	graphics/battle_anims/sprites/bluegreen_orb.png.gbapal.lz \
	graphics/battle_anims/sprites/breaking_egg.png.4bpp.lz \
	graphics/battle_anims/sprites/breaking_egg.png.gbapal.lz \
	graphics/battle_anims/sprites/brown_orb.pal.gbapal.lz \
	graphics/battle_anims/sprites/circle_impact.png.4bpp.lz \
	graphics/battle_anims/sprites/circle_impact.png.gbapal.lz \
	graphics/battle_anims/sprites/circle_of_light.png.4bpp.lz \
	graphics/battle_anims/sprites/clamp.png.4bpp.lz \
	graphics/battle_anims/sprites/confetti.png.4bpp.lz \
	graphics/battle_anims/sprites/confetti.png.gbapal.lz \
	graphics/battle_anims/sprites/conversion.png.4bpp.lz \
	graphics/battle_anims/sprites/conversion.png.gbapal.lz \
	graphics/battle_anims/sprites/cross_impact.png.4bpp.lz \
	graphics/battle_anims/sprites/cross_impact.png.gbapal.lz \
	graphics/battle_anims/sprites/cut.png.4bpp.lz \
	graphics/battle_anims/sprites/devil.png.4bpp.lz \
	graphics/battle_anims/sprites/devil.png.gbapal.lz \
	graphics/battle_anims/sprites/dirt_mound.png.4bpp.lz \
	graphics/battle_anims/sprites/dirt_mound.png.gbapal.lz \
	graphics/battle_anims/sprites/eclipsing_orb.png.4bpp.lz \
	graphics/battle_anims/sprites/eclipsing_orb.png.gbapal.lz \
	graphics/battle_anims/sprites/electric_orbs.png.4bpp.lz \
	graphics/battle_anims/sprites/electric_orbs.png.gbapal.lz \
	graphics/battle_anims/sprites/electricity.png.4bpp.lz \
	graphics/battle_anims/sprites/explosion.png.4bpp.lz \
	graphics/battle_anims/sprites/explosion.png.gbapal.lz \
	graphics/battle_anims/sprites/eye.png.4bpp.lz \
	graphics/battle_anims/sprites/eye.png.gbapal.lz \
	graphics/battle_anims/sprites/eye_sparkle.png.4bpp.lz \
	graphics/battle_anims/sprites/eye_sparkle.png.gbapal.lz \
	graphics/battle_anims/sprites/fang_attack.png.4bpp.lz \
	graphics/battle_anims/sprites/fang_attack.png.gbapal.lz \
	graphics/battle_anims/sprites/finger.png.4bpp.lz \
	graphics/battle_anims/sprites/finger.png.gbapal.lz \
	graphics/battle_anims/sprites/finger_2.png.4bpp.lz \
	graphics/battle_anims/sprites/flat_rock.png.4bpp.lz \
	graphics/battle_anims/sprites/flat_rock.png.gbapal.lz \
	graphics/battle_anims/sprites/flower.4bpp.lz \
	graphics/battle_anims/sprites/flower.pal.gbapal.lz \
	graphics/battle_anims/sprites/flying_dirt.png.4bpp.lz \
	graphics/battle_anims/sprites/flying_dirt.png.gbapal.lz \
	graphics/battle_anims/sprites/focus_energy.png.4bpp.lz \
	graphics/battle_anims/sprites/focus_energy.png.gbapal.lz \
	graphics/battle_anims/sprites/gem_1.png.4bpp.lz \
	graphics/battle_anims/sprites/gem_1.png.gbapal.lz \
	graphics/battle_anims/sprites/gem_2.png.4bpp.lz \
	graphics/battle_anims/sprites/gem_3.png.4bpp.lz \
	graphics/battle_anims/sprites/ghostly_spirit.png.4bpp.lz \
	graphics/battle_anims/sprites/ghostly_spirit.png.gbapal.lz \
	graphics/battle_anims/sprites/glowy_blue_orb.pal.gbapal.lz \
	graphics/battle_anims/sprites/glowy_green_orb.pal.gbapal.lz \
	graphics/battle_anims/sprites/glowy_red_orb.png.4bpp.lz \
	graphics/battle_anims/sprites/glowy_red_orb.png.gbapal.lz \
	graphics/battle_anims/sprites/gold_ring.png.4bpp.lz \
	graphics/battle_anims/sprites/gold_ring.png.gbapal.lz \
	graphics/battle_anims/sprites/gold_stars.png.4bpp.lz \
	graphics/battle_anims/sprites/gold_stars.png.gbapal.lz \
	graphics/battle_anims/sprites/gray_light_wall.pal.gbapal.lz \
	graphics/battle_anims/sprites/gray_orb.png.4bpp.lz \
	graphics/battle_anims/sprites/gray_orb.png.gbapal.lz \
	graphics/battle_anims/sprites/green_light_wall.png.4bpp.lz \
	graphics/battle_anims/sprites/green_light_wall.png.gbapal.lz \
	graphics/battle_anims/sprites/green_sparkle.png.4bpp.lz \
	graphics/battle_anims/sprites/green_sparkle.png.gbapal.lz \
	graphics/battle_anims/sprites/green_spike.png.4bpp.lz \
	graphics/battle_anims/sprites/green_spike.png.gbapal.lz \
	graphics/battle_anims/sprites/green_star.png.4bpp.lz \
	graphics/battle_anims/sprites/green_star.png.gbapal.lz \
	graphics/battle_anims/sprites/guard_ring.png.4bpp.lz \
	graphics/battle_anims/sprites/guard_ring.png.gbapal.lz \
	graphics/battle_anims/sprites/hail.png.4bpp.lz \
	graphics/battle_anims/sprites/hail.png.gbapal.lz \
	graphics/battle_anims/sprites/hands_and_feet.png.4bpp.lz \
	graphics/battle_anims/sprites/hands_and_feet.png.gbapal.lz \
	graphics/battle_anims/sprites/hollow_orb.png.4bpp.lz \
	graphics/battle_anims/sprites/hollow_orb.png.gbapal.lz \
	graphics/battle_anims/sprites/horn_hit_2.png.4bpp.lz \
	graphics/battle_anims/sprites/horn_hit_2.png.gbapal.lz \
	graphics/battle_anims/sprites/ice_crystals.4bpp.lz \
	graphics/battle_anims/sprites/ice_crystals.pal.gbapal.lz \
	graphics/battle_anims/sprites/ice_spikes.png.4bpp.lz \
	graphics/battle_anims/sprites/icicle_spear.png.4bpp.lz \
	graphics/battle_anims/sprites/icicle_spear.png.gbapal.lz \
	graphics/battle_anims/sprites/impact.png.4bpp.lz \
	graphics/battle_anims/sprites/impact.png.gbapal.lz \
	graphics/battle_anims/sprites/item_bag.png.4bpp.lz \
	graphics/battle_anims/sprites/item_bag.png.gbapal.lz \
	graphics/battle_anims/sprites/jagged_music_note.png.4bpp.lz \
	graphics/battle_anims/sprites/jagged_music_note.png.gbapal.lz \
	graphics/battle_anims/sprites/large_fresh_egg.png.4bpp.lz \
	graphics/battle_anims/sprites/large_fresh_egg.png.gbapal.lz \
	graphics/battle_anims/sprites/letter_z.png.4bpp.lz \
	graphics/battle_anims/sprites/letter_z.png.gbapal.lz \
	graphics/battle_anims/sprites/lick.png.4bpp.lz \
	graphics/battle_anims/sprites/lick.png.gbapal.lz \
	graphics/battle_anims/sprites/lightbulb.png.4bpp.lz \
	graphics/battle_anims/sprites/lightbulb.png.gbapal.lz \
	graphics/battle_anims/sprites/lock_on.png.4bpp.lz \
	graphics/battle_anims/sprites/lock_on.png.gbapal.lz \
	graphics/battle_anims/sprites/magenta_heart.png.4bpp.lz \
	graphics/battle_anims/sprites/magenta_heart.png.gbapal.lz \
	graphics/battle_anims/sprites/magnifying_glass.png.4bpp.lz \
	graphics/battle_anims/sprites/magnifying_glass.png.gbapal.lz \
	graphics/battle_anims/sprites/metal_sound_waves.png.4bpp.lz \
	graphics/battle_anims/sprites/metal_sound_waves.png.gbapal.lz \
	graphics/battle_anims/sprites/meteor.png.4bpp.lz \
	graphics/battle_anims/sprites/meteor.png.gbapal.lz \
	graphics/battle_anims/sprites/milk_bottle.png.4bpp.lz \
	graphics/battle_anims/sprites/milk_bottle.png.gbapal.lz \
	graphics/battle_anims/sprites/mist_cloud.png.4bpp.lz \
	graphics/battle_anims/sprites/mist_cloud.png.gbapal.lz \
	graphics/battle_anims/sprites/moon.png.4bpp.lz \
	graphics/battle_anims/sprites/moon.png.gbapal.lz \
	graphics/battle_anims/sprites/movement_waves.png.4bpp.lz \
	graphics/battle_anims/sprites/movement_waves.png.gbapal.lz \
	graphics/battle_anims/sprites/mud_sand.4bpp.lz \
	graphics/battle_anims/sprites/mud_sand.pal.gbapal.lz \
	graphics/battle_anims/sprites/music_notes_2.pal.gbapal.lz \
	graphics/battle_anims/sprites/music_notes_2.png.4bpp.lz \
	graphics/battle_anims/sprites/nail.png.4bpp.lz \
	graphics/battle_anims/sprites/nail.png.gbapal.lz \
	graphics/battle_anims/sprites/noise_line.png.4bpp.lz \
	graphics/battle_anims/sprites/opening_eye.png.4bpp.lz \
	graphics/battle_anims/sprites/opening_eye.png.gbapal.lz \
	graphics/battle_anims/sprites/orange_light_wall.pal.gbapal.lz \
	graphics/battle_anims/sprites/orbs.png.4bpp.lz \
	graphics/battle_anims/sprites/orbs.png.gbapal.lz \
	graphics/battle_anims/sprites/pain_split.png.4bpp.lz \
	graphics/battle_anims/sprites/pain_split.png.gbapal.lz \
	graphics/battle_anims/sprites/particles.png.4bpp.lz \
	graphics/battle_anims/sprites/paw_print.png.4bpp.lz \
	graphics/battle_anims/sprites/paw_print.png.gbapal.lz \
	graphics/battle_anims/sprites/pencil.png.4bpp.lz \
	graphics/battle_anims/sprites/pencil.png.gbapal.lz \
	graphics/battle_anims/sprites/pink_cloud.png.4bpp.lz \
	graphics/battle_anims/sprites/pink_cloud.png.gbapal.lz \
	graphics/battle_anims/sprites/pink_heart.pal.gbapal.lz \
	graphics/battle_anims/sprites/pink_petal.png.4bpp.lz \
	graphics/battle_anims/sprites/pink_petal.png.gbapal.lz \
	graphics/battle_anims/sprites/poison_bubble.png.4bpp.lz \
	graphics/battle_anims/sprites/poison_bubble.png.gbapal.lz \
	graphics/battle_anims/sprites/pokeball.png.4bpp.lz \
	graphics/battle_anims/sprites/pokeball.png.gbapal.lz \
	graphics/battle_anims/sprites/pokeblock.png.4bpp.lz \
	graphics/battle_anims/sprites/pokeblock.png.gbapal.lz \
	graphics/battle_anims/sprites/protect.png.4bpp.lz \
	graphics/battle_anims/sprites/protect.png.gbapal.lz \
	graphics/battle_anims/sprites/punch_impact.png.4bpp.lz \
	graphics/battle_anims/sprites/punch_impact.png.gbapal.lz \
	graphics/battle_anims/sprites/purple_flame.png.4bpp.lz \
	graphics/battle_anims/sprites/purple_flame.png.gbapal.lz \
	graphics/battle_anims/sprites/purple_gas_cloud.pal.gbapal.lz \
	graphics/battle_anims/sprites/purple_hand_outline.png.4bpp.lz \
	graphics/battle_anims/sprites/purple_hand_outline.png.gbapal.lz \
	graphics/battle_anims/sprites/purple_ring.pal.gbapal.lz \
	graphics/battle_anims/sprites/purple_scratch.png.4bpp.lz \
	graphics/battle_anims/sprites/purple_scratch.png.gbapal.lz \
	graphics/battle_anims/sprites/purple_swipe.png.4bpp.lz \
	graphics/battle_anims/sprites/rainbow_rings.png.4bpp.lz \
	graphics/battle_anims/sprites/rainbow_rings.png.gbapal.lz \
	graphics/battle_anims/sprites/rapid_spin.png.4bpp.lz \
	graphics/battle_anims/sprites/rapid_spin.png.gbapal.lz \
	graphics/battle_anims/sprites/razor_leaf.png.4bpp.lz \
	graphics/battle_anims/sprites/razor_leaf.png.gbapal.lz \
	graphics/battle_anims/sprites/recycle.png.4bpp.lz \
	graphics/battle_anims/sprites/recycle.png.gbapal.lz \
	graphics/battle_anims/sprites/red_ball.png.4bpp.lz \
	graphics/battle_anims/sprites/red_ball.png.gbapal.lz \
	graphics/battle_anims/sprites/red_heart.pal.gbapal.lz \
	graphics/battle_anims/sprites/red_light_wall.pal.gbapal.lz \
	graphics/battle_anims/sprites/red_orb.png.4bpp.lz \
	graphics/battle_anims/sprites/red_orb.png.gbapal.lz \
	graphics/battle_anims/sprites/red_orb_2.pal.gbapal.lz \
	graphics/battle_anims/sprites/red_particles.png.4bpp.lz \
	graphics/battle_anims/sprites/red_particles.png.gbapal.lz \
	graphics/battle_anims/sprites/roots.png.4bpp.lz \
	graphics/battle_anims/sprites/roots.png.gbapal.lz \
	graphics/battle_anims/sprites/round_shadow.png.4bpp.lz \
	graphics/battle_anims/sprites/round_shadow.png.gbapal.lz \
	graphics/battle_anims/sprites/round_white_halo.png.4bpp.lz \
	graphics/battle_anims/sprites/round_white_halo.png.gbapal.lz \
	graphics/battle_anims/sprites/scratch.png.4bpp.lz \
	graphics/battle_anims/sprites/shadow_ball.png.4bpp.lz \
	graphics/battle_anims/sprites/shadow_ball.png.gbapal.lz \
	graphics/battle_anims/sprites/sharp_teeth.png.4bpp.lz \
	graphics/battle_anims/sprites/sharp_teeth.png.gbapal.lz \
	graphics/battle_anims/sprites/shock_3.png.4bpp.lz \
	graphics/battle_anims/sprites/shock_3.png.gbapal.lz \
	graphics/battle_anims/sprites/slam_hit_2.png.4bpp.lz \
	graphics/battle_anims/sprites/slam_hit_2.png.gbapal.lz \
	graphics/battle_anims/sprites/slash.png.4bpp.lz \
	graphics/battle_anims/sprites/slash.png.gbapal.lz \
	graphics/battle_anims/sprites/slash_2.pal.gbapal.lz \
	graphics/battle_anims/sprites/sleep_powder.pal.gbapal.lz \
	graphics/battle_anims/sprites/small_bubbles.png.4bpp.lz \
	graphics/battle_anims/sprites/small_bubbles.png.gbapal.lz \
	graphics/battle_anims/sprites/small_red_eye.png.4bpp.lz \
	graphics/battle_anims/sprites/small_red_eye.png.gbapal.lz \
	graphics/battle_anims/sprites/smellingsalt_effect.png.4bpp.lz \
	graphics/battle_anims/sprites/smellingsalt_effect.png.gbapal.lz \
	graphics/battle_anims/sprites/smokescreen_impact.png.4bpp.lz \
	graphics/battle_anims/sprites/smokescreen_impact.png.gbapal.lz \
	graphics/battle_anims/sprites/snore_z.png.4bpp.lz \
	graphics/battle_anims/sprites/snore_z.png.gbapal.lz \
	graphics/battle_anims/sprites/spark.4bpp.lz \
	graphics/battle_anims/sprites/spark.pal.gbapal.lz \
	graphics/battle_anims/sprites/spark_h.png.4bpp.lz \
	graphics/battle_anims/sprites/sparkle_6.png.4bpp.lz \
	graphics/battle_anims/sprites/sparkle_6.png.gbapal.lz \
	graphics/battle_anims/sprites/speed_dust.png.4bpp.lz \
	graphics/battle_anims/sprites/speed_dust.png.gbapal.lz \
	graphics/battle_anims/sprites/sphere_to_cube.png.4bpp.lz \
	graphics/battle_anims/sprites/sphere_to_cube.png.gbapal.lz \
	graphics/battle_anims/sprites/spider_web.png.4bpp.lz \
	graphics/battle_anims/sprites/spiral.png.4bpp.lz \
	graphics/battle_anims/sprites/spiral.png.gbapal.lz \
	graphics/battle_anims/sprites/splash.png.4bpp.lz \
	graphics/battle_anims/sprites/splash.png.gbapal.lz \
	graphics/battle_anims/sprites/spore.png.4bpp.lz \
	graphics/battle_anims/sprites/spore.png.gbapal.lz \
	graphics/battle_anims/sprites/spotlight.png.4bpp.lz \
	graphics/battle_anims/sprites/string.png.4bpp.lz \
	graphics/battle_anims/sprites/string.png.gbapal.lz \
	graphics/battle_anims/sprites/stun_spore.pal.gbapal.lz \
	graphics/battle_anims/sprites/substitute.png.4bpp.lz \
	graphics/battle_anims/sprites/substitute.png.gbapal.lz \
	graphics/battle_anims/sprites/substitute_back.png.4bpp.lz \
	graphics/battle_anims/sprites/sunlight.png.4bpp.lz \
	graphics/battle_anims/sprites/sunlight.png.gbapal.lz \
	graphics/battle_anims/sprites/sweat_bead.png.4bpp.lz \
	graphics/battle_anims/sprites/sweat_drop.png.4bpp.lz \
	graphics/battle_anims/sprites/sweat_drop.png.gbapal.lz \
	graphics/battle_anims/sprites/swipe.png.4bpp.lz \
	graphics/battle_anims/sprites/swipe.png.gbapal.lz \
	graphics/battle_anims/sprites/tag_hand.png.4bpp.lz \
	graphics/battle_anims/sprites/teal_alert.png.4bpp.lz \
	graphics/battle_anims/sprites/teal_alert.png.gbapal.lz \
	graphics/battle_anims/sprites/tendrils.png.4bpp.lz \
	graphics/battle_anims/sprites/tendrils.png.gbapal.lz \
	graphics/battle_anims/sprites/thin_ring.png.4bpp.lz \
	graphics/battle_anims/sprites/thin_ring.png.gbapal.lz \
	graphics/battle_anims/sprites/thought_bubble.png.4bpp.lz \
	graphics/battle_anims/sprites/thought_bubble.png.gbapal.lz \
	graphics/battle_anims/sprites/torn_metal.png.4bpp.lz \
	graphics/battle_anims/sprites/toxic_bubble.png.4bpp.lz \
	graphics/battle_anims/sprites/tri_attack_triangle.png.4bpp.lz \
	graphics/battle_anims/sprites/tri_attack_triangle.png.gbapal.lz \
	graphics/battle_anims/sprites/void_lines.png.4bpp.lz \
	graphics/battle_anims/sprites/void_lines.png.gbapal.lz \
	graphics/battle_anims/sprites/warm_rock.png.4bpp.lz \
	graphics/battle_anims/sprites/warm_rock.png.gbapal.lz \
	graphics/battle_anims/sprites/water_impact.png.4bpp.lz \
	graphics/battle_anims/sprites/water_impact.png.gbapal.lz \
	graphics/battle_anims/sprites/water_orb.png.4bpp.lz \
	graphics/battle_anims/sprites/weather_ball.png.4bpp.lz \
	graphics/battle_anims/sprites/weather_ball.png.gbapal.lz \
	graphics/battle_anims/sprites/web_thread.png.4bpp.lz \
	graphics/battle_anims/sprites/whip_hit.pal.gbapal.lz \
	graphics/battle_anims/sprites/whirlwind_lines.png.4bpp.lz \
	graphics/battle_anims/sprites/whirlwind_lines.png.gbapal.lz \
	graphics/battle_anims/sprites/white_circle_of_light.pal.gbapal.lz \
	graphics/battle_anims/sprites/white_feather.png.4bpp.lz \
	graphics/battle_anims/sprites/white_feather.png.gbapal.lz \
	graphics/battle_anims/sprites/white_shadow.png.4bpp.lz \
	graphics/battle_anims/sprites/white_shadow.png.gbapal.lz \
	graphics/battle_anims/sprites/wisp_fire.png.4bpp.lz \
	graphics/battle_anims/sprites/wisp_orb.png.4bpp.lz \
	graphics/battle_anims/sprites/wisp_orb.png.gbapal.lz \
	graphics/battle_anims/sprites/x_sign.png.4bpp.lz \
	graphics/battle_anims/sprites/yellow_star.png.4bpp.lz \
	graphics/battle_anims/sprites/yellow_star.png.gbapal.lz \
	graphics/battle_anims/stat_change/accuracy.pal.gbapal.lz \
	graphics/battle_anims/stat_change/attack.pal.gbapal.lz \
	graphics/battle_anims/stat_change/decrease.bin.lz \
	graphics/battle_anims/stat_change/defense.pal.gbapal.lz \
	graphics/battle_anims/stat_change/evasion.pal.gbapal.lz \
	graphics/battle_anims/stat_change/increase.bin.lz \
	graphics/battle_anims/stat_change/multiple.pal.gbapal.lz \
	graphics/battle_anims/stat_change/sp_attack.pal.gbapal.lz \
	graphics/battle_anims/stat_change/sp_defense.pal.gbapal.lz \
	graphics/battle_anims/stat_change/speed.pal.gbapal.lz \
	graphics/battle_anims/stat_change/tiles.png.4bpp.lz \
	graphics/battle_anims/unused/goosuto.bin.lz \
	graphics/battle_anims/unused/goosuto.png.4bpp.lz \
	graphics/battle_anims/unused/goosuto.png.gbapal.lz \
	graphics/battle_anims/unused/lights.bin.lz \
	graphics/battle_anims/unused/lights.png.4bpp.lz \
	graphics/battle_anims/unused/lights.png.gbapal.lz \
	graphics/battle_anims/unused/old_beatup.png.4bpp.lz \
	graphics/battle_anims/unused/old_beatup.png.gbapal.lz \
	graphics/battle_anims/unused/unknown_2.pal.gbapal.lz

JP_BATTLE_ANIM_REMAINING_INTERMEDIATES := graphics/battle_anims/backgrounds/attract.png.4bpp \
	graphics/battle_anims/backgrounds/attract.png.gbapal \
	graphics/battle_anims/backgrounds/aurora.png.4bpp \
	graphics/battle_anims/backgrounds/aurora.png.gbapal \
	graphics/battle_anims/backgrounds/bug.pal.gbapal \
	graphics/battle_anims/backgrounds/cosmic.png.4bpp \
	graphics/battle_anims/backgrounds/cosmic.png.gbapal \
	graphics/battle_anims/backgrounds/dark.png.4bpp \
	graphics/battle_anims/backgrounds/dark.png.gbapal \
	graphics/battle_anims/backgrounds/drill.png.4bpp \
	graphics/battle_anims/backgrounds/drill.png.gbapal \
	graphics/battle_anims/backgrounds/fissure.png.4bpp \
	graphics/battle_anims/backgrounds/fissure.png.gbapal \
	graphics/battle_anims/backgrounds/ghost.png.4bpp \
	graphics/battle_anims/backgrounds/ghost.png.gbapal \
	graphics/battle_anims/backgrounds/guillotine.png.4bpp \
	graphics/battle_anims/backgrounds/guillotine.png.gbapal \
	graphics/battle_anims/backgrounds/highspeed.png.4bpp \
	graphics/battle_anims/backgrounds/highspeed.png.gbapal \
	graphics/battle_anims/backgrounds/ice.png.4bpp \
	graphics/battle_anims/backgrounds/ice.png.gbapal \
	graphics/battle_anims/backgrounds/impact.png.4bpp \
	graphics/battle_anims/backgrounds/impact.png.gbapal \
	graphics/battle_anims/backgrounds/in_air.png.4bpp \
	graphics/battle_anims/backgrounds/in_air.png.gbapal \
	graphics/battle_anims/backgrounds/psychic.png.4bpp \
	graphics/battle_anims/backgrounds/psychic.png.gbapal \
	graphics/battle_anims/backgrounds/sandstorm_brew.png.4bpp \
	graphics/battle_anims/backgrounds/scary_face.png.4bpp \
	graphics/battle_anims/backgrounds/scary_face.png.gbapal \
	graphics/battle_anims/backgrounds/sky.pal.gbapal \
	graphics/battle_anims/backgrounds/solarbeam.pal.gbapal \
	graphics/battle_anims/backgrounds/thunder.png.4bpp \
	graphics/battle_anims/backgrounds/thunder.png.gbapal \
	graphics/battle_anims/backgrounds/water.png.4bpp \
	graphics/battle_anims/backgrounds/water.png.gbapal \
	graphics/battle_anims/backgrounds/water_muddy.pal.gbapal \
	graphics/battle_anims/masks/cure_bubbles.png.4bpp \
	graphics/battle_anims/masks/cure_bubbles.png.gbapal \
	graphics/battle_anims/masks/curse.png.4bpp \
	graphics/battle_anims/masks/light_beam.png.4bpp \
	graphics/battle_anims/masks/light_beam.png.gbapal \
	graphics/battle_anims/masks/metal_shine.png.4bpp \
	graphics/battle_anims/masks/metal_shine.png.gbapal \
	graphics/battle_anims/masks/unused_level_up.png_num_tiles_14__Wnum_tiles.4bpp \
	graphics/battle_anims/sprites/air_wave_2.png.4bpp \
	graphics/battle_anims/sprites/air_wave_2.png.gbapal \
	graphics/battle_anims/sprites/angel.png.4bpp \
	graphics/battle_anims/sprites/angel.png.gbapal \
	graphics/battle_anims/sprites/anger.png.4bpp \
	graphics/battle_anims/sprites/anger.png.gbapal \
	graphics/battle_anims/sprites/bell.png.4bpp \
	graphics/battle_anims/sprites/bell.png.gbapal \
	graphics/battle_anims/sprites/bird.png.4bpp \
	graphics/battle_anims/sprites/bird.png.gbapal \
	graphics/battle_anims/sprites/black_ball_2.png.4bpp \
	graphics/battle_anims/sprites/black_ball_2.png.gbapal \
	graphics/battle_anims/sprites/blue_light_wall.pal.gbapal \
	graphics/battle_anims/sprites/blue_orb.pal.gbapal \
	graphics/battle_anims/sprites/blue_ring.pal.gbapal \
	graphics/battle_anims/sprites/blue_ring_2.pal.gbapal \
	graphics/battle_anims/sprites/bluegreen_orb.png.4bpp \
	graphics/battle_anims/sprites/bluegreen_orb.png.gbapal \
	graphics/battle_anims/sprites/breaking_egg.png.4bpp \
	graphics/battle_anims/sprites/breaking_egg.png.gbapal \
	graphics/battle_anims/sprites/brown_orb.pal.gbapal \
	graphics/battle_anims/sprites/circle_impact.png.4bpp \
	graphics/battle_anims/sprites/circle_impact.png.gbapal \
	graphics/battle_anims/sprites/circle_of_light.png.4bpp \
	graphics/battle_anims/sprites/clamp.png.4bpp \
	graphics/battle_anims/sprites/confetti.png.4bpp \
	graphics/battle_anims/sprites/confetti.png.gbapal \
	graphics/battle_anims/sprites/conversion.png.4bpp \
	graphics/battle_anims/sprites/conversion.png.gbapal \
	graphics/battle_anims/sprites/cross_impact.png.4bpp \
	graphics/battle_anims/sprites/cross_impact.png.gbapal \
	graphics/battle_anims/sprites/cut.png.4bpp \
	graphics/battle_anims/sprites/devil.png.4bpp \
	graphics/battle_anims/sprites/devil.png.gbapal \
	graphics/battle_anims/sprites/dirt_mound.png.4bpp \
	graphics/battle_anims/sprites/dirt_mound.png.gbapal \
	graphics/battle_anims/sprites/eclipsing_orb.png.4bpp \
	graphics/battle_anims/sprites/eclipsing_orb.png.gbapal \
	graphics/battle_anims/sprites/electric_orbs.png.4bpp \
	graphics/battle_anims/sprites/electric_orbs.png.gbapal \
	graphics/battle_anims/sprites/electricity.png.4bpp \
	graphics/battle_anims/sprites/explosion.png.4bpp \
	graphics/battle_anims/sprites/explosion.png.gbapal \
	graphics/battle_anims/sprites/eye.png.4bpp \
	graphics/battle_anims/sprites/eye.png.gbapal \
	graphics/battle_anims/sprites/eye_sparkle.png.4bpp \
	graphics/battle_anims/sprites/eye_sparkle.png.gbapal \
	graphics/battle_anims/sprites/fang_attack.png.4bpp \
	graphics/battle_anims/sprites/fang_attack.png.gbapal \
	graphics/battle_anims/sprites/finger.png.4bpp \
	graphics/battle_anims/sprites/finger.png.gbapal \
	graphics/battle_anims/sprites/finger_2.png.4bpp \
	graphics/battle_anims/sprites/flat_rock.png.4bpp \
	graphics/battle_anims/sprites/flat_rock.png.gbapal \
	graphics/battle_anims/sprites/flower.4bpp \
	graphics/battle_anims/sprites/flower.pal.gbapal \
	graphics/battle_anims/sprites/flower_0.png.4bpp \
	graphics/battle_anims/sprites/flower_1.png.4bpp \
	graphics/battle_anims/sprites/flying_dirt.png.4bpp \
	graphics/battle_anims/sprites/flying_dirt.png.gbapal \
	graphics/battle_anims/sprites/focus_energy.png.4bpp \
	graphics/battle_anims/sprites/focus_energy.png.gbapal \
	graphics/battle_anims/sprites/gem_1.png.4bpp \
	graphics/battle_anims/sprites/gem_1.png.gbapal \
	graphics/battle_anims/sprites/gem_2.png.4bpp \
	graphics/battle_anims/sprites/gem_3.png.4bpp \
	graphics/battle_anims/sprites/ghostly_spirit.png.4bpp \
	graphics/battle_anims/sprites/ghostly_spirit.png.gbapal \
	graphics/battle_anims/sprites/glowy_blue_orb.pal.gbapal \
	graphics/battle_anims/sprites/glowy_green_orb.pal.gbapal \
	graphics/battle_anims/sprites/glowy_red_orb.png.4bpp \
	graphics/battle_anims/sprites/glowy_red_orb.png.gbapal \
	graphics/battle_anims/sprites/gold_ring.png.4bpp \
	graphics/battle_anims/sprites/gold_ring.png.gbapal \
	graphics/battle_anims/sprites/gold_stars.png.4bpp \
	graphics/battle_anims/sprites/gold_stars.png.gbapal \
	graphics/battle_anims/sprites/gray_light_wall.pal.gbapal \
	graphics/battle_anims/sprites/gray_orb.png.4bpp \
	graphics/battle_anims/sprites/gray_orb.png.gbapal \
	graphics/battle_anims/sprites/green_light_wall.png.4bpp \
	graphics/battle_anims/sprites/green_light_wall.png.gbapal \
	graphics/battle_anims/sprites/green_sparkle.png.4bpp \
	graphics/battle_anims/sprites/green_sparkle.png.gbapal \
	graphics/battle_anims/sprites/green_spike.png.4bpp \
	graphics/battle_anims/sprites/green_spike.png.gbapal \
	graphics/battle_anims/sprites/green_star.png.4bpp \
	graphics/battle_anims/sprites/green_star.png.gbapal \
	graphics/battle_anims/sprites/guard_ring.png.4bpp \
	graphics/battle_anims/sprites/guard_ring.png.gbapal \
	graphics/battle_anims/sprites/hail.png.4bpp \
	graphics/battle_anims/sprites/hail.png.gbapal \
	graphics/battle_anims/sprites/hands_and_feet.png.4bpp \
	graphics/battle_anims/sprites/hands_and_feet.png.gbapal \
	graphics/battle_anims/sprites/hollow_orb.png.4bpp \
	graphics/battle_anims/sprites/hollow_orb.png.gbapal \
	graphics/battle_anims/sprites/horn_hit_2.png.4bpp \
	graphics/battle_anims/sprites/horn_hit_2.png.gbapal \
	graphics/battle_anims/sprites/ice_crystals.4bpp \
	graphics/battle_anims/sprites/ice_crystals.pal.gbapal \
	graphics/battle_anims/sprites/ice_crystals_0.png.4bpp \
	graphics/battle_anims/sprites/ice_crystals_1.png.4bpp \
	graphics/battle_anims/sprites/ice_crystals_2.png.4bpp \
	graphics/battle_anims/sprites/ice_crystals_3.png.4bpp \
	graphics/battle_anims/sprites/ice_crystals_4.png.4bpp \
	graphics/battle_anims/sprites/ice_spikes.png.4bpp \
	graphics/battle_anims/sprites/icicle_spear.png.4bpp \
	graphics/battle_anims/sprites/icicle_spear.png.gbapal \
	graphics/battle_anims/sprites/impact.png.4bpp \
	graphics/battle_anims/sprites/impact.png.gbapal \
	graphics/battle_anims/sprites/item_bag.png.4bpp \
	graphics/battle_anims/sprites/item_bag.png.gbapal \
	graphics/battle_anims/sprites/jagged_music_note.png.4bpp \
	graphics/battle_anims/sprites/jagged_music_note.png.gbapal \
	graphics/battle_anims/sprites/large_fresh_egg.png.4bpp \
	graphics/battle_anims/sprites/large_fresh_egg.png.gbapal \
	graphics/battle_anims/sprites/letter_z.png.4bpp \
	graphics/battle_anims/sprites/letter_z.png.gbapal \
	graphics/battle_anims/sprites/lick.png.4bpp \
	graphics/battle_anims/sprites/lick.png.gbapal \
	graphics/battle_anims/sprites/lightbulb.png.4bpp \
	graphics/battle_anims/sprites/lightbulb.png.gbapal \
	graphics/battle_anims/sprites/lock_on.png.4bpp \
	graphics/battle_anims/sprites/lock_on.png.gbapal \
	graphics/battle_anims/sprites/magenta_heart.png.4bpp \
	graphics/battle_anims/sprites/magenta_heart.png.gbapal \
	graphics/battle_anims/sprites/magnifying_glass.png.4bpp \
	graphics/battle_anims/sprites/magnifying_glass.png.gbapal \
	graphics/battle_anims/sprites/metal_sound_waves.png.4bpp \
	graphics/battle_anims/sprites/metal_sound_waves.png.gbapal \
	graphics/battle_anims/sprites/meteor.png.4bpp \
	graphics/battle_anims/sprites/meteor.png.gbapal \
	graphics/battle_anims/sprites/milk_bottle.png.4bpp \
	graphics/battle_anims/sprites/milk_bottle.png.gbapal \
	graphics/battle_anims/sprites/mist_cloud.png.4bpp \
	graphics/battle_anims/sprites/mist_cloud.png.gbapal \
	graphics/battle_anims/sprites/moon.png.4bpp \
	graphics/battle_anims/sprites/moon.png.gbapal \
	graphics/battle_anims/sprites/movement_waves.png.4bpp \
	graphics/battle_anims/sprites/movement_waves.png.gbapal \
	graphics/battle_anims/sprites/mud_sand.4bpp \
	graphics/battle_anims/sprites/mud_sand.pal.gbapal \
	graphics/battle_anims/sprites/mud_sand_0.png.4bpp \
	graphics/battle_anims/sprites/mud_sand_1.png.4bpp \
	graphics/battle_anims/sprites/music_notes_2.pal.gbapal \
	graphics/battle_anims/sprites/music_notes_2.png.4bpp \
	graphics/battle_anims/sprites/nail.png.4bpp \
	graphics/battle_anims/sprites/nail.png.gbapal \
	graphics/battle_anims/sprites/noise_line.png.4bpp \
	graphics/battle_anims/sprites/opening_eye.png.4bpp \
	graphics/battle_anims/sprites/opening_eye.png.gbapal \
	graphics/battle_anims/sprites/orange_light_wall.pal.gbapal \
	graphics/battle_anims/sprites/orbs.png.4bpp \
	graphics/battle_anims/sprites/orbs.png.gbapal \
	graphics/battle_anims/sprites/pain_split.png.4bpp \
	graphics/battle_anims/sprites/pain_split.png.gbapal \
	graphics/battle_anims/sprites/particles.png.4bpp \
	graphics/battle_anims/sprites/paw_print.png.4bpp \
	graphics/battle_anims/sprites/paw_print.png.gbapal \
	graphics/battle_anims/sprites/pencil.png.4bpp \
	graphics/battle_anims/sprites/pencil.png.gbapal \
	graphics/battle_anims/sprites/pink_cloud.png.4bpp \
	graphics/battle_anims/sprites/pink_cloud.png.gbapal \
	graphics/battle_anims/sprites/pink_heart.pal.gbapal \
	graphics/battle_anims/sprites/pink_petal.png.4bpp \
	graphics/battle_anims/sprites/pink_petal.png.gbapal \
	graphics/battle_anims/sprites/poison_bubble.png.4bpp \
	graphics/battle_anims/sprites/poison_bubble.png.gbapal \
	graphics/battle_anims/sprites/pokeball.png.4bpp \
	graphics/battle_anims/sprites/pokeball.png.gbapal \
	graphics/battle_anims/sprites/pokeblock.png.4bpp \
	graphics/battle_anims/sprites/pokeblock.png.gbapal \
	graphics/battle_anims/sprites/protect.png.4bpp \
	graphics/battle_anims/sprites/protect.png.gbapal \
	graphics/battle_anims/sprites/punch_impact.png.4bpp \
	graphics/battle_anims/sprites/punch_impact.png.gbapal \
	graphics/battle_anims/sprites/purple_flame.png.4bpp \
	graphics/battle_anims/sprites/purple_flame.png.gbapal \
	graphics/battle_anims/sprites/purple_gas_cloud.pal.gbapal \
	graphics/battle_anims/sprites/purple_hand_outline.png.4bpp \
	graphics/battle_anims/sprites/purple_hand_outline.png.gbapal \
	graphics/battle_anims/sprites/purple_ring.pal.gbapal \
	graphics/battle_anims/sprites/purple_scratch.png.4bpp \
	graphics/battle_anims/sprites/purple_scratch.png.gbapal \
	graphics/battle_anims/sprites/purple_swipe.png.4bpp \
	graphics/battle_anims/sprites/rainbow_rings.png.4bpp \
	graphics/battle_anims/sprites/rainbow_rings.png.gbapal \
	graphics/battle_anims/sprites/rapid_spin.png.4bpp \
	graphics/battle_anims/sprites/rapid_spin.png.gbapal \
	graphics/battle_anims/sprites/razor_leaf.png.4bpp \
	graphics/battle_anims/sprites/razor_leaf.png.gbapal \
	graphics/battle_anims/sprites/recycle.png.4bpp \
	graphics/battle_anims/sprites/recycle.png.gbapal \
	graphics/battle_anims/sprites/red_ball.png.4bpp \
	graphics/battle_anims/sprites/red_ball.png.gbapal \
	graphics/battle_anims/sprites/red_heart.pal.gbapal \
	graphics/battle_anims/sprites/red_light_wall.pal.gbapal \
	graphics/battle_anims/sprites/red_orb.png.4bpp \
	graphics/battle_anims/sprites/red_orb.png.gbapal \
	graphics/battle_anims/sprites/red_orb_2.pal.gbapal \
	graphics/battle_anims/sprites/red_particles.png.4bpp \
	graphics/battle_anims/sprites/red_particles.png.gbapal \
	graphics/battle_anims/sprites/roots.png.4bpp \
	graphics/battle_anims/sprites/roots.png.gbapal \
	graphics/battle_anims/sprites/round_shadow.png.4bpp \
	graphics/battle_anims/sprites/round_shadow.png.gbapal \
	graphics/battle_anims/sprites/round_white_halo.png.4bpp \
	graphics/battle_anims/sprites/round_white_halo.png.gbapal \
	graphics/battle_anims/sprites/scratch.png.4bpp \
	graphics/battle_anims/sprites/shadow_ball.png.4bpp \
	graphics/battle_anims/sprites/shadow_ball.png.gbapal \
	graphics/battle_anims/sprites/sharp_teeth.png.4bpp \
	graphics/battle_anims/sprites/sharp_teeth.png.gbapal \
	graphics/battle_anims/sprites/shock_3.png.4bpp \
	graphics/battle_anims/sprites/shock_3.png.gbapal \
	graphics/battle_anims/sprites/slam_hit_2.png.4bpp \
	graphics/battle_anims/sprites/slam_hit_2.png.gbapal \
	graphics/battle_anims/sprites/slash.png.4bpp \
	graphics/battle_anims/sprites/slash.png.gbapal \
	graphics/battle_anims/sprites/slash_2.pal.gbapal \
	graphics/battle_anims/sprites/sleep_powder.pal.gbapal \
	graphics/battle_anims/sprites/small_bubbles.png.4bpp \
	graphics/battle_anims/sprites/small_bubbles.png.gbapal \
	graphics/battle_anims/sprites/small_red_eye.png.4bpp \
	graphics/battle_anims/sprites/small_red_eye.png.gbapal \
	graphics/battle_anims/sprites/smellingsalt_effect.png.4bpp \
	graphics/battle_anims/sprites/smellingsalt_effect.png.gbapal \
	graphics/battle_anims/sprites/smokescreen_impact.png.4bpp \
	graphics/battle_anims/sprites/smokescreen_impact.png.gbapal \
	graphics/battle_anims/sprites/snore_z.png.4bpp \
	graphics/battle_anims/sprites/snore_z.png.gbapal \
	graphics/battle_anims/sprites/spark.4bpp \
	graphics/battle_anims/sprites/spark.pal.gbapal \
	graphics/battle_anims/sprites/spark_0.png.4bpp \
	graphics/battle_anims/sprites/spark_1.png.4bpp \
	graphics/battle_anims/sprites/spark_h.png.4bpp \
	graphics/battle_anims/sprites/sparkle_6.png.4bpp \
	graphics/battle_anims/sprites/sparkle_6.png.gbapal \
	graphics/battle_anims/sprites/speed_dust.png.4bpp \
	graphics/battle_anims/sprites/speed_dust.png.gbapal \
	graphics/battle_anims/sprites/sphere_to_cube.png.4bpp \
	graphics/battle_anims/sprites/sphere_to_cube.png.gbapal \
	graphics/battle_anims/sprites/spider_web.png.4bpp \
	graphics/battle_anims/sprites/spiral.png.4bpp \
	graphics/battle_anims/sprites/spiral.png.gbapal \
	graphics/battle_anims/sprites/splash.png.4bpp \
	graphics/battle_anims/sprites/splash.png.gbapal \
	graphics/battle_anims/sprites/spore.png.4bpp \
	graphics/battle_anims/sprites/spore.png.gbapal \
	graphics/battle_anims/sprites/spotlight.png.4bpp \
	graphics/battle_anims/sprites/string.png.4bpp \
	graphics/battle_anims/sprites/string.png.gbapal \
	graphics/battle_anims/sprites/stun_spore.pal.gbapal \
	graphics/battle_anims/sprites/substitute.png.4bpp \
	graphics/battle_anims/sprites/substitute.png.gbapal \
	graphics/battle_anims/sprites/substitute_back.png.4bpp \
	graphics/battle_anims/sprites/sunlight.png.4bpp \
	graphics/battle_anims/sprites/sunlight.png.gbapal \
	graphics/battle_anims/sprites/sweat_bead.png.4bpp \
	graphics/battle_anims/sprites/sweat_drop.png.4bpp \
	graphics/battle_anims/sprites/sweat_drop.png.gbapal \
	graphics/battle_anims/sprites/swipe.png.4bpp \
	graphics/battle_anims/sprites/swipe.png.gbapal \
	graphics/battle_anims/sprites/tag_hand.png.4bpp \
	graphics/battle_anims/sprites/teal_alert.png.4bpp \
	graphics/battle_anims/sprites/teal_alert.png.gbapal \
	graphics/battle_anims/sprites/tendrils.png.4bpp \
	graphics/battle_anims/sprites/tendrils.png.gbapal \
	graphics/battle_anims/sprites/thin_ring.png.4bpp \
	graphics/battle_anims/sprites/thin_ring.png.gbapal \
	graphics/battle_anims/sprites/thought_bubble.png.4bpp \
	graphics/battle_anims/sprites/thought_bubble.png.gbapal \
	graphics/battle_anims/sprites/torn_metal.png.4bpp \
	graphics/battle_anims/sprites/toxic_bubble.png.4bpp \
	graphics/battle_anims/sprites/tri_attack_triangle.png.4bpp \
	graphics/battle_anims/sprites/tri_attack_triangle.png.gbapal \
	graphics/battle_anims/sprites/void_lines.png.4bpp \
	graphics/battle_anims/sprites/void_lines.png.gbapal \
	graphics/battle_anims/sprites/warm_rock.png.4bpp \
	graphics/battle_anims/sprites/warm_rock.png.gbapal \
	graphics/battle_anims/sprites/water_impact.png.4bpp \
	graphics/battle_anims/sprites/water_impact.png.gbapal \
	graphics/battle_anims/sprites/water_orb.png.4bpp \
	graphics/battle_anims/sprites/weather_ball.png.4bpp \
	graphics/battle_anims/sprites/weather_ball.png.gbapal \
	graphics/battle_anims/sprites/web_thread.png.4bpp \
	graphics/battle_anims/sprites/whip_hit.pal.gbapal \
	graphics/battle_anims/sprites/whirlwind_lines.png.4bpp \
	graphics/battle_anims/sprites/whirlwind_lines.png.gbapal \
	graphics/battle_anims/sprites/white_circle_of_light.pal.gbapal \
	graphics/battle_anims/sprites/white_feather.png.4bpp \
	graphics/battle_anims/sprites/white_feather.png.gbapal \
	graphics/battle_anims/sprites/white_shadow.png.4bpp \
	graphics/battle_anims/sprites/white_shadow.png.gbapal \
	graphics/battle_anims/sprites/wisp_fire.png.4bpp \
	graphics/battle_anims/sprites/wisp_orb.png.4bpp \
	graphics/battle_anims/sprites/wisp_orb.png.gbapal \
	graphics/battle_anims/sprites/x_sign.png.4bpp \
	graphics/battle_anims/sprites/yellow_star.png.4bpp \
	graphics/battle_anims/sprites/yellow_star.png.gbapal \
	graphics/battle_anims/stat_change/accuracy.pal.gbapal \
	graphics/battle_anims/stat_change/attack.pal.gbapal \
	graphics/battle_anims/stat_change/defense.pal.gbapal \
	graphics/battle_anims/stat_change/evasion.pal.gbapal \
	graphics/battle_anims/stat_change/multiple.pal.gbapal \
	graphics/battle_anims/stat_change/sp_attack.pal.gbapal \
	graphics/battle_anims/stat_change/sp_defense.pal.gbapal \
	graphics/battle_anims/stat_change/speed.pal.gbapal \
	graphics/battle_anims/stat_change/tiles.png.4bpp \
	graphics/battle_anims/unused/goosuto.png.4bpp \
	graphics/battle_anims/unused/goosuto.png.gbapal \
	graphics/battle_anims/unused/lights.png.4bpp \
	graphics/battle_anims/unused/lights.png.gbapal \
	graphics/battle_anims/unused/old_beatup.png.4bpp \
	graphics/battle_anims/unused/old_beatup.png.gbapal \
	graphics/battle_anims/unused/unknown_2.pal.gbapal

$(filter %.png.4bpp,$(JP_BATTLE_ANIM_REMAINING_INTERMEDIATES)): %.png.4bpp: %.png Makefile | tools
	$(GFX) $< $@

$(filter %.png.gbapal,$(JP_BATTLE_ANIM_REMAINING_INTERMEDIATES)): %.png.gbapal: %.png Makefile | tools
	$(GFX) $< $@

$(filter %.pal.gbapal,$(JP_BATTLE_ANIM_REMAINING_INTERMEDIATES)): %.pal.gbapal: %.pal Makefile | tools
	$(GFX) $< $@

graphics/battle_anims/masks/unused_level_up.png_num_tiles_14__Wnum_tiles.4bpp: graphics/battle_anims/masks/unused_level_up.png Makefile | tools
	$(GFX) $< $@ -num_tiles 14 -Wnum_tiles

graphics/battle_anims/sprites/ice_crystals.4bpp: graphics/battle_anims/sprites/ice_crystals_0.png.4bpp graphics/battle_anims/sprites/ice_crystals_1.png.4bpp graphics/battle_anims/sprites/ice_crystals_2.png.4bpp graphics/battle_anims/sprites/ice_crystals_3.png.4bpp graphics/battle_anims/sprites/ice_crystals_4.png.4bpp Makefile
	cat $(filter %.4bpp,$^) >$@

graphics/battle_anims/sprites/mud_sand.4bpp: graphics/battle_anims/sprites/mud_sand_0.png.4bpp graphics/battle_anims/sprites/mud_sand_1.png.4bpp Makefile
	cat $(filter %.4bpp,$^) >$@

graphics/battle_anims/sprites/flower.4bpp: graphics/battle_anims/sprites/flower_0.png.4bpp graphics/battle_anims/sprites/flower_1.png.4bpp Makefile
	cat $(filter %.4bpp,$^) >$@

graphics/battle_anims/sprites/spark.4bpp: graphics/battle_anims/sprites/spark_0.png.4bpp graphics/battle_anims/sprites/spark_1.png.4bpp Makefile
	cat $(filter %.4bpp,$^) >$@

$(JP_BATTLE_ANIM_REMAINING_ASSETS): %.lz: % Makefile | tools
	$(GFX) $< $@

$(C_BUILDDIR)/graphics.o: $(JP_BATTLE_ANIM_REMAINING_ASSETS)

JP_CONTEST_ASSETS := graphics/contest/applause.png.4bpp.lz \
	graphics/contest/applause_meter.png.4bpp \
	graphics/contest/audience.bin.lz \
	graphics/contest/audience.png.4bpp.lz \
	graphics/contest/curtain.bin.lz \
	graphics/contest/faces.png.4bpp.lz \
	graphics/contest/interface.bin.lz \
	graphics/contest/interface.png.4bpp.lz \
	graphics/contest/interface.png.gbapal.lz \
	graphics/contest/japanese/audience.bin.lz \
	graphics/contest/japanese/bg.bin.lz \
	graphics/contest/japanese/composite_1.4bpp.lz \
	graphics/contest/japanese/composite_2.4bpp.lz \
	graphics/contest/japanese/interface.bin.lz \
	graphics/contest/japanese/palette.pal.gbapal.lz \
	graphics/contest/japanese/voltage.png.gbapal.lz \
	graphics/contest/japanese/voltage.png_num_tiles_36__Wnum_tiles.4bpp.lz \
	graphics/contest/japanese/windows.bin.lz \
	graphics/contest/judge.png.4bpp.lz \
	graphics/contest/judge.png.gbapal.lz \
	graphics/contest/judge_symbols.png.4bpp.lz \
	graphics/contest/judge_symbols.png.gbapal.lz \
	graphics/contest/nextturn.png.4bpp.lz \
	graphics/contest/nextturn.png.gbapal \
	graphics/contest/nextturn_numbers.png.4bpp \
	graphics/contest/nextturn_random.png.4bpp \
	graphics/contest/results_screen/bg.bin.lz \
	graphics/contest/results_screen/interface.bin.lz \
	graphics/contest/results_screen/tiles.png.4bpp.lz \
	graphics/contest/results_screen/tiles.png.gbapal.lz \
	graphics/contest/results_screen/winner_banner.bin.lz \
	graphics/contest/slider_heart.png.4bpp

JP_CONTEST_INTERMEDIATES := graphics/contest/applause.png.4bpp \
	graphics/contest/audience.png.4bpp \
	graphics/contest/faces.png.4bpp \
	graphics/contest/interface.png.4bpp \
	graphics/contest/interface.png.gbapal \
	graphics/contest/japanese/audience.png.4bpp \
	graphics/contest/japanese/composite_1.4bpp \
	graphics/contest/japanese/composite_2.4bpp \
	graphics/contest/japanese/floor.png.4bpp \
	graphics/contest/japanese/frame_1.png.4bpp \
	graphics/contest/japanese/frame_2.png.4bpp \
	graphics/contest/japanese/interface.png.4bpp \
	graphics/contest/japanese/letters.png.4bpp \
	graphics/contest/japanese/meter.png.4bpp \
	graphics/contest/japanese/numbers.png.4bpp \
	graphics/contest/japanese/palette.pal.gbapal \
	graphics/contest/japanese/symbols.png.4bpp \
	graphics/contest/japanese/voltage.png.gbapal \
	graphics/contest/japanese/voltage.png_num_tiles_36__Wnum_tiles.4bpp \
	graphics/contest/judge.png.4bpp \
	graphics/contest/judge.png.gbapal \
	graphics/contest/judge_symbols.png.4bpp \
	graphics/contest/judge_symbols.png.gbapal \
	graphics/contest/nextturn.png.4bpp \
	graphics/contest/results_screen/tiles.png.4bpp \
	graphics/contest/results_screen/tiles.png.gbapal

graphics/contest/applause.png.4bpp graphics/contest/applause_meter.png.4bpp graphics/contest/audience.png.4bpp graphics/contest/faces.png.4bpp graphics/contest/interface.png.4bpp graphics/contest/japanese/audience.png.4bpp graphics/contest/japanese/floor.png.4bpp graphics/contest/japanese/frame_1.png.4bpp graphics/contest/japanese/frame_2.png.4bpp graphics/contest/japanese/interface.png.4bpp graphics/contest/japanese/letters.png.4bpp graphics/contest/japanese/meter.png.4bpp graphics/contest/japanese/numbers.png.4bpp graphics/contest/japanese/symbols.png.4bpp graphics/contest/judge.png.4bpp graphics/contest/judge_symbols.png.4bpp graphics/contest/nextturn.png.4bpp graphics/contest/nextturn_numbers.png.4bpp graphics/contest/nextturn_random.png.4bpp graphics/contest/results_screen/tiles.png.4bpp graphics/contest/slider_heart.png.4bpp: %.png.4bpp: %.png Makefile | tools
	$(GFX) $< $@

graphics/contest/interface.png.gbapal graphics/contest/japanese/voltage.png.gbapal graphics/contest/judge.png.gbapal graphics/contest/judge_symbols.png.gbapal graphics/contest/nextturn.png.gbapal graphics/contest/results_screen/tiles.png.gbapal: %.png.gbapal: %.png Makefile | tools
	$(GFX) $< $@

graphics/contest/japanese/palette.pal.gbapal: %.pal.gbapal: %.pal Makefile | tools
	$(GFX) $< $@

graphics/contest/japanese/voltage.png_num_tiles_36__Wnum_tiles.4bpp: graphics/contest/japanese/voltage.png Makefile | tools
	$(GFX) $< $@ -num_tiles 36 -Wnum_tiles

graphics/contest/japanese/composite_1.4bpp: graphics/contest/japanese/frame_1.png.4bpp graphics/contest/japanese/floor.png.4bpp graphics/contest/japanese/frame_2.png.4bpp graphics/contest/japanese/symbols.png.4bpp graphics/contest/japanese/meter.png.4bpp graphics/contest/japanese/letters.png.4bpp graphics/contest/japanese/numbers.png.4bpp Makefile
	cat $(filter %.4bpp,$^) >$@

graphics/contest/japanese/composite_2.4bpp: graphics/contest/japanese/interface.png.4bpp graphics/contest/japanese/audience.png.4bpp Makefile
	cat $(filter %.4bpp,$^) >$@

$(filter %.lz,$(JP_CONTEST_ASSETS)): %.lz: % Makefile | tools
	$(GFX) $< $@

$(C_BUILDDIR)/graphics.o: $(JP_CONTEST_ASSETS)

JP_CONTEST_RESULTS_ASSETS := graphics/contest/results_screen/text_window.pal.gbapal graphics/contest/results_screen/text_window.png.4bpp graphics/interface/blank.pal.gbapal

graphics/contest/results_screen/text_window.png.4bpp: %.png.4bpp: %.png Makefile | tools
	$(GFX) $< $@

graphics/contest/results_screen/text_window.pal.gbapal graphics/interface/blank.pal.gbapal: %.pal.gbapal: %.pal Makefile | tools
	$(GFX) $< $@

$(C_BUILDDIR)/contest_util.o: src/contest_util.c charmap.txt include/graphics.h include/sprite.h include/bg.h include/window.h include/util.h $(JP_CONTEST_RESULTS_ASSETS)
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(or $(CC1),$(CC)) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/contest_util.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/contest_util.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/contest_util.gen.s

JP_ITEM_ICON_ASSETS := graphics/items/icon_palettes/acro_bike.pal.gbapal.lz \
	graphics/items/icon_palettes/aguav_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/amulet_coin.pal.gbapal.lz \
	graphics/items/icon_palettes/antidote.pal.gbapal.lz \
	graphics/items/icon_palettes/apicot_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/aspear_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/aurora_ticket.pal.gbapal.lz \
	graphics/items/icon_palettes/awakening.pal.gbapal.lz \
	graphics/items/icon_palettes/bead_mail.pal.gbapal.lz \
	graphics/items/icon_palettes/belue_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/berry_juice.pal.gbapal.lz \
	graphics/items/icon_palettes/berry_pouch.pal.gbapal.lz \
	graphics/items/icon_palettes/bicycle.pal.gbapal.lz \
	graphics/items/icon_palettes/bike_voucher.pal.gbapal.lz \
	graphics/items/icon_palettes/black_flute.pal.gbapal.lz \
	graphics/items/icon_palettes/black_type_enhancing_item.pal.gbapal.lz \
	graphics/items/icon_palettes/blue_flute.pal.gbapal.lz \
	graphics/items/icon_palettes/blue_orb.pal.gbapal.lz \
	graphics/items/icon_palettes/blue_scarf.pal.gbapal.lz \
	graphics/items/icon_palettes/blue_shard.pal.gbapal.lz \
	graphics/items/icon_palettes/bluk_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/bright_powder.pal.gbapal.lz \
	graphics/items/icon_palettes/burn_heal.pal.gbapal.lz \
	graphics/items/icon_palettes/calcium.pal.gbapal.lz \
	graphics/items/icon_palettes/carbos.pal.gbapal.lz \
	graphics/items/icon_palettes/card_key.pal.gbapal.lz \
	graphics/items/icon_palettes/charcoal.pal.gbapal.lz \
	graphics/items/icon_palettes/cheri_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/chesto_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/choice_band.pal.gbapal.lz \
	graphics/items/icon_palettes/cleanse_tag.pal.gbapal.lz \
	graphics/items/icon_palettes/coin_case.pal.gbapal.lz \
	graphics/items/icon_palettes/contest_pass.pal.gbapal.lz \
	graphics/items/icon_palettes/cornn_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/dark_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/deep_sea_scale.pal.gbapal.lz \
	graphics/items/icon_palettes/deep_sea_tooth.pal.gbapal.lz \
	graphics/items/icon_palettes/devon_goods.pal.gbapal.lz \
	graphics/items/icon_palettes/devon_scope.pal.gbapal.lz \
	graphics/items/icon_palettes/dire_hit.pal.gbapal.lz \
	graphics/items/icon_palettes/dive_ball.pal.gbapal.lz \
	graphics/items/icon_palettes/dragon_fang.pal.gbapal.lz \
	graphics/items/icon_palettes/dragon_scale.pal.gbapal.lz \
	graphics/items/icon_palettes/dragon_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/dream_mail.pal.gbapal.lz \
	graphics/items/icon_palettes/durin_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/electric_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/elixir.pal.gbapal.lz \
	graphics/items/icon_palettes/energy_powder.pal.gbapal.lz \
	graphics/items/icon_palettes/energy_root.pal.gbapal.lz \
	graphics/items/icon_palettes/enigma_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/eon_ticket.pal.gbapal.lz \
	graphics/items/icon_palettes/escape_rope.pal.gbapal.lz \
	graphics/items/icon_palettes/ether.pal.gbapal.lz \
	graphics/items/icon_palettes/everstone.pal.gbapal.lz \
	graphics/items/icon_palettes/exp_share.pal.gbapal.lz \
	graphics/items/icon_palettes/fab_mail.pal.gbapal.lz \
	graphics/items/icon_palettes/fame_checker.pal.gbapal.lz \
	graphics/items/icon_palettes/fighting_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/figy_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/fire_stone.pal.gbapal.lz \
	graphics/items/icon_palettes/fire_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/fluffy_tail.pal.gbapal.lz \
	graphics/items/icon_palettes/flying_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/focus_band.pal.gbapal.lz \
	graphics/items/icon_palettes/fresh_water.pal.gbapal.lz \
	graphics/items/icon_palettes/full_heal.pal.gbapal.lz \
	graphics/items/icon_palettes/full_restore.pal.gbapal.lz \
	graphics/items/icon_palettes/ganlon_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/ghost_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/glitter_mail.pal.gbapal.lz \
	graphics/items/icon_palettes/go_goggles.pal.gbapal.lz \
	graphics/items/icon_palettes/gold_teeth.pal.gbapal.lz \
	graphics/items/icon_palettes/good_rod.pal.gbapal.lz \
	graphics/items/icon_palettes/grass_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/great_ball.pal.gbapal.lz \
	graphics/items/icon_palettes/green_scarf.pal.gbapal.lz \
	graphics/items/icon_palettes/green_shard.pal.gbapal.lz \
	graphics/items/icon_palettes/grepa_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/ground_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/guard_spec.pal.gbapal.lz \
	graphics/items/icon_palettes/harbor_mail.pal.gbapal.lz \
	graphics/items/icon_palettes/hard_stone.pal.gbapal.lz \
	graphics/items/icon_palettes/heal_powder.pal.gbapal.lz \
	graphics/items/icon_palettes/heart_scale.pal.gbapal.lz \
	graphics/items/icon_palettes/hoenn_fossil.pal.gbapal.lz \
	graphics/items/icon_palettes/hondew_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/hp_up.pal.gbapal.lz \
	graphics/items/icon_palettes/hyper_potion.pal.gbapal.lz \
	graphics/items/icon_palettes/iapapa_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/ice_heal.pal.gbapal.lz \
	graphics/items/icon_palettes/ice_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/iron.pal.gbapal.lz \
	graphics/items/icon_palettes/itemfinder.pal.gbapal.lz \
	graphics/items/icon_palettes/kanto_fossil.pal.gbapal.lz \
	graphics/items/icon_palettes/kelpsy_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/key.pal.gbapal.lz \
	graphics/items/icon_palettes/kings_rock.pal.gbapal.lz \
	graphics/items/icon_palettes/lansat_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/lava_cookie_and_letter.pal.gbapal.lz \
	graphics/items/icon_palettes/lax_incense.pal.gbapal.lz \
	graphics/items/icon_palettes/leaf_stone.pal.gbapal.lz \
	graphics/items/icon_palettes/leftovers.pal.gbapal.lz \
	graphics/items/icon_palettes/lemonade.pal.gbapal.lz \
	graphics/items/icon_palettes/leppa_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/liechi_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/light_ball.pal.gbapal.lz \
	graphics/items/icon_palettes/lucky_egg.pal.gbapal.lz \
	graphics/items/icon_palettes/lucky_punch.pal.gbapal.lz \
	graphics/items/icon_palettes/lum_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/luxury_ball.pal.gbapal.lz \
	graphics/items/icon_palettes/mach_bike.pal.gbapal.lz \
	graphics/items/icon_palettes/macho_brace.pal.gbapal.lz \
	graphics/items/icon_palettes/magma_emblem.pal.gbapal.lz \
	graphics/items/icon_palettes/magnet.pal.gbapal.lz \
	graphics/items/icon_palettes/mago_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/magost_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/master_ball.pal.gbapal.lz \
	graphics/items/icon_palettes/max_elixir.pal.gbapal.lz \
	graphics/items/icon_palettes/max_ether.pal.gbapal.lz \
	graphics/items/icon_palettes/max_potion.pal.gbapal.lz \
	graphics/items/icon_palettes/max_repel.pal.gbapal.lz \
	graphics/items/icon_palettes/mech_mail.pal.gbapal.lz \
	graphics/items/icon_palettes/mental_herb.pal.gbapal.lz \
	graphics/items/icon_palettes/metal_coat.pal.gbapal.lz \
	graphics/items/icon_palettes/metal_powder.pal.gbapal.lz \
	graphics/items/icon_palettes/meteorite.pal.gbapal.lz \
	graphics/items/icon_palettes/miracle_seed.pal.gbapal.lz \
	graphics/items/icon_palettes/moomoo_milk.pal.gbapal.lz \
	graphics/items/icon_palettes/moon_stone.pal.gbapal.lz \
	graphics/items/icon_palettes/mushroom.pal.gbapal.lz \
	graphics/items/icon_palettes/mystic_ticket.pal.gbapal.lz \
	graphics/items/icon_palettes/mystic_water.pal.gbapal.lz \
	graphics/items/icon_palettes/nanab_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/nest_ball.pal.gbapal.lz \
	graphics/items/icon_palettes/net_ball.pal.gbapal.lz \
	graphics/items/icon_palettes/never_melt_ice.pal.gbapal.lz \
	graphics/items/icon_palettes/nomel_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/normal_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/nugget.pal.gbapal.lz \
	graphics/items/icon_palettes/oaks_parcel.pal.gbapal.lz \
	graphics/items/icon_palettes/old_amber.pal.gbapal.lz \
	graphics/items/icon_palettes/old_key.pal.gbapal.lz \
	graphics/items/icon_palettes/old_rod.pal.gbapal.lz \
	graphics/items/icon_palettes/old_sea_map.pal.gbapal.lz \
	graphics/items/icon_palettes/oran_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/orange_mail.pal.gbapal.lz \
	graphics/items/icon_palettes/pamtre_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/paralyze_heal.pal.gbapal.lz \
	graphics/items/icon_palettes/pearl.pal.gbapal.lz \
	graphics/items/icon_palettes/pecha_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/persim_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/petaya_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/pinap_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/pink_scarf.pal.gbapal.lz \
	graphics/items/icon_palettes/poison_barb.pal.gbapal.lz \
	graphics/items/icon_palettes/poison_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/poke_ball.pal.gbapal.lz \
	graphics/items/icon_palettes/poke_doll.pal.gbapal.lz \
	graphics/items/icon_palettes/poke_flute.pal.gbapal.lz \
	graphics/items/icon_palettes/pokeblock_case.pal.gbapal.lz \
	graphics/items/icon_palettes/pomeg_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/potion.pal.gbapal.lz \
	graphics/items/icon_palettes/powder_jar.pal.gbapal.lz \
	graphics/items/icon_palettes/pp_max.pal.gbapal.lz \
	graphics/items/icon_palettes/pp_up.pal.gbapal.lz \
	graphics/items/icon_palettes/protein.pal.gbapal.lz \
	graphics/items/icon_palettes/psychic_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/qualot_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/question_mark.pal.gbapal.lz \
	graphics/items/icon_palettes/quick_claw.pal.gbapal.lz \
	graphics/items/icon_palettes/rabuta_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/rainbow_pass.pal.gbapal.lz \
	graphics/items/icon_palettes/rare_candy.pal.gbapal.lz \
	graphics/items/icon_palettes/rawst_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/razz_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/red_flute.pal.gbapal.lz \
	graphics/items/icon_palettes/red_orb.pal.gbapal.lz \
	graphics/items/icon_palettes/red_scarf.pal.gbapal.lz \
	graphics/items/icon_palettes/red_shard.pal.gbapal.lz \
	graphics/items/icon_palettes/repeat_ball.pal.gbapal.lz \
	graphics/items/icon_palettes/repel.pal.gbapal.lz \
	graphics/items/icon_palettes/retro_mail.pal.gbapal.lz \
	graphics/items/icon_palettes/return_to_field_arrow.pal.gbapal.lz \
	graphics/items/icon_palettes/revival_herb.pal.gbapal.lz \
	graphics/items/icon_palettes/revive.pal.gbapal.lz \
	graphics/items/icon_palettes/rock_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/ruby.pal.gbapal.lz \
	graphics/items/icon_palettes/sacred_ash.pal.gbapal.lz \
	graphics/items/icon_palettes/safari_ball.pal.gbapal.lz \
	graphics/items/icon_palettes/salac_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/sapphire.pal.gbapal.lz \
	graphics/items/icon_palettes/scanner.pal.gbapal.lz \
	graphics/items/icon_palettes/scope_lens.pal.gbapal.lz \
	graphics/items/icon_palettes/sea_incense.pal.gbapal.lz \
	graphics/items/icon_palettes/secret_key.pal.gbapal.lz \
	graphics/items/icon_palettes/shadow_mail.pal.gbapal.lz \
	graphics/items/icon_palettes/sharp_beak.pal.gbapal.lz \
	graphics/items/icon_palettes/shell.pal.gbapal.lz \
	graphics/items/icon_palettes/shoal_salt.pal.gbapal.lz \
	graphics/items/icon_palettes/silk_scarf.pal.gbapal.lz \
	graphics/items/icon_palettes/silph_scope.pal.gbapal.lz \
	graphics/items/icon_palettes/silver_powder.pal.gbapal.lz \
	graphics/items/icon_palettes/sitrus_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/smoke_ball.pal.gbapal.lz \
	graphics/items/icon_palettes/soda_pop.pal.gbapal.lz \
	graphics/items/icon_palettes/soft_sand.pal.gbapal.lz \
	graphics/items/icon_palettes/soot_sack.pal.gbapal.lz \
	graphics/items/icon_palettes/soothe_bell.pal.gbapal.lz \
	graphics/items/icon_palettes/soul_dew.pal.gbapal.lz \
	graphics/items/icon_palettes/spell_tag.pal.gbapal.lz \
	graphics/items/icon_palettes/spelon_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/ss_ticket.pal.gbapal.lz \
	graphics/items/icon_palettes/star.pal.gbapal.lz \
	graphics/items/icon_palettes/starf_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/steel_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/stick.pal.gbapal.lz \
	graphics/items/icon_palettes/sun_stone.pal.gbapal.lz \
	graphics/items/icon_palettes/super_potion.pal.gbapal.lz \
	graphics/items/icon_palettes/super_repel.pal.gbapal.lz \
	graphics/items/icon_palettes/super_rod.pal.gbapal.lz \
	graphics/items/icon_palettes/tamato_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/tea.pal.gbapal.lz \
	graphics/items/icon_palettes/teachy_tv.pal.gbapal.lz \
	graphics/items/icon_palettes/thick_club.pal.gbapal.lz \
	graphics/items/icon_palettes/thunder_stone.pal.gbapal.lz \
	graphics/items/icon_palettes/tm_case.pal.gbapal.lz \
	graphics/items/icon_palettes/town_map.pal.gbapal.lz \
	graphics/items/icon_palettes/tri_pass.pal.gbapal.lz \
	graphics/items/icon_palettes/tropic_mail.pal.gbapal.lz \
	graphics/items/icon_palettes/twisted_spoon.pal.gbapal.lz \
	graphics/items/icon_palettes/ultra_ball.pal.gbapal.lz \
	graphics/items/icon_palettes/up_grade.pal.gbapal.lz \
	graphics/items/icon_palettes/vs_seeker.pal.gbapal.lz \
	graphics/items/icon_palettes/wailmer_pail.pal.gbapal.lz \
	graphics/items/icon_palettes/water_stone.pal.gbapal.lz \
	graphics/items/icon_palettes/water_tm_hm.pal.gbapal.lz \
	graphics/items/icon_palettes/watmel_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/wave_mail.pal.gbapal.lz \
	graphics/items/icon_palettes/wepear_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/white_flute.pal.gbapal.lz \
	graphics/items/icon_palettes/white_herb.pal.gbapal.lz \
	graphics/items/icon_palettes/wiki_berry.pal.gbapal.lz \
	graphics/items/icon_palettes/wood_mail.pal.gbapal.lz \
	graphics/items/icon_palettes/x_accuracy.pal.gbapal.lz \
	graphics/items/icon_palettes/x_attack.pal.gbapal.lz \
	graphics/items/icon_palettes/x_defend.pal.gbapal.lz \
	graphics/items/icon_palettes/x_special.pal.gbapal.lz \
	graphics/items/icon_palettes/x_speed.pal.gbapal.lz \
	graphics/items/icon_palettes/yellow_flute.pal.gbapal.lz \
	graphics/items/icon_palettes/yellow_scarf.pal.gbapal.lz \
	graphics/items/icon_palettes/yellow_shard.pal.gbapal.lz \
	graphics/items/icon_palettes/zinc.pal.gbapal.lz \
	graphics/items/icons/acro_bike.png.4bpp.lz \
	graphics/items/icons/aguav_berry.png.4bpp.lz \
	graphics/items/icons/amulet_coin.png.4bpp.lz \
	graphics/items/icons/antidote.png.4bpp.lz \
	graphics/items/icons/apicot_berry.png.4bpp.lz \
	graphics/items/icons/aspear_berry.png.4bpp.lz \
	graphics/items/icons/aurora_ticket.png.4bpp.lz \
	graphics/items/icons/basement_key.png.4bpp.lz \
	graphics/items/icons/battle_stat_item.png.4bpp.lz \
	graphics/items/icons/bead_mail.png.4bpp.lz \
	graphics/items/icons/belue_berry.png.4bpp.lz \
	graphics/items/icons/berry_juice.png.4bpp.lz \
	graphics/items/icons/berry_pouch.png.4bpp.lz \
	graphics/items/icons/bicycle.png.4bpp.lz \
	graphics/items/icons/big_mushroom.png.4bpp.lz \
	graphics/items/icons/big_pearl.png.4bpp.lz \
	graphics/items/icons/bike_voucher.png.4bpp.lz \
	graphics/items/icons/black_belt.png.4bpp.lz \
	graphics/items/icons/black_glasses.png.4bpp.lz \
	graphics/items/icons/bluk_berry.png.4bpp.lz \
	graphics/items/icons/bright_powder.png.4bpp.lz \
	graphics/items/icons/card_key.png.4bpp.lz \
	graphics/items/icons/charcoal.png.4bpp.lz \
	graphics/items/icons/cheri_berry.png.4bpp.lz \
	graphics/items/icons/chesto_berry.png.4bpp.lz \
	graphics/items/icons/choice_band.png.4bpp.lz \
	graphics/items/icons/claw_fossil.png.4bpp.lz \
	graphics/items/icons/cleanse_tag.png.4bpp.lz \
	graphics/items/icons/coin_case.png.4bpp.lz \
	graphics/items/icons/contest_pass.png.4bpp.lz \
	graphics/items/icons/cornn_berry.png.4bpp.lz \
	graphics/items/icons/deep_sea_scale.png.4bpp.lz \
	graphics/items/icons/deep_sea_tooth.png.4bpp.lz \
	graphics/items/icons/devon_goods.png.4bpp.lz \
	graphics/items/icons/devon_scope.png.4bpp.lz \
	graphics/items/icons/dive_ball.png.4bpp.lz \
	graphics/items/icons/dome_fossil.png.4bpp.lz \
	graphics/items/icons/dragon_fang.png.4bpp.lz \
	graphics/items/icons/dragon_scale.png.4bpp.lz \
	graphics/items/icons/dream_mail.png.4bpp.lz \
	graphics/items/icons/durin_berry.png.4bpp.lz \
	graphics/items/icons/energy_root.png.4bpp.lz \
	graphics/items/icons/enigma_berry.png.4bpp.lz \
	graphics/items/icons/eon_ticket.png.4bpp.lz \
	graphics/items/icons/escape_rope.png.4bpp.lz \
	graphics/items/icons/ether.png.4bpp.lz \
	graphics/items/icons/everstone.png.4bpp.lz \
	graphics/items/icons/exp_share.png.4bpp.lz \
	graphics/items/icons/fab_mail.png.4bpp.lz \
	graphics/items/icons/fame_checker.png.4bpp.lz \
	graphics/items/icons/figy_berry.png.4bpp.lz \
	graphics/items/icons/fire_stone.png.4bpp.lz \
	graphics/items/icons/fluffy_tail.png.4bpp.lz \
	graphics/items/icons/flute.png.4bpp.lz \
	graphics/items/icons/focus_band.png.4bpp.lz \
	graphics/items/icons/fresh_water.png.4bpp.lz \
	graphics/items/icons/full_heal.png.4bpp.lz \
	graphics/items/icons/ganlon_berry.png.4bpp.lz \
	graphics/items/icons/gem.png.4bpp.lz \
	graphics/items/icons/glitter_mail.png.4bpp.lz \
	graphics/items/icons/go_goggles.png.4bpp.lz \
	graphics/items/icons/gold_teeth.png.4bpp.lz \
	graphics/items/icons/good_rod.png.4bpp.lz \
	graphics/items/icons/great_ball.png.4bpp.lz \
	graphics/items/icons/grepa_berry.png.4bpp.lz \
	graphics/items/icons/harbor_mail.png.4bpp.lz \
	graphics/items/icons/hard_stone.png.4bpp.lz \
	graphics/items/icons/heart_scale.png.4bpp.lz \
	graphics/items/icons/helix_fossil.png.4bpp.lz \
	graphics/items/icons/hm.png.4bpp.lz \
	graphics/items/icons/hondew_berry.png.4bpp.lz \
	graphics/items/icons/hp_up.png.4bpp.lz \
	graphics/items/icons/iapapa_berry.png.4bpp.lz \
	graphics/items/icons/in_battle_herb.png.4bpp.lz \
	graphics/items/icons/itemfinder.png.4bpp.lz \
	graphics/items/icons/kelpsy_berry.png.4bpp.lz \
	graphics/items/icons/kings_rock.png.4bpp.lz \
	graphics/items/icons/lansat_berry.png.4bpp.lz \
	graphics/items/icons/large_potion.png.4bpp.lz \
	graphics/items/icons/lava_cookie.png.4bpp.lz \
	graphics/items/icons/lax_incense.png.4bpp.lz \
	graphics/items/icons/leaf_stone.png.4bpp.lz \
	graphics/items/icons/leftovers.png.4bpp.lz \
	graphics/items/icons/lemonade.png.4bpp.lz \
	graphics/items/icons/leppa_berry.png.4bpp.lz \
	graphics/items/icons/letter.png.4bpp.lz \
	graphics/items/icons/liechi_berry.png.4bpp.lz \
	graphics/items/icons/lift_key.png.4bpp.lz \
	graphics/items/icons/light_ball.png.4bpp.lz \
	graphics/items/icons/lucky_egg.png.4bpp.lz \
	graphics/items/icons/lucky_punch.png.4bpp.lz \
	graphics/items/icons/lum_berry.png.4bpp.lz \
	graphics/items/icons/luxury_ball.png.4bpp.lz \
	graphics/items/icons/mach_bike.png.4bpp.lz \
	graphics/items/icons/macho_brace.png.4bpp.lz \
	graphics/items/icons/magma_emblem.png.4bpp.lz \
	graphics/items/icons/magnet.png.4bpp.lz \
	graphics/items/icons/mago_berry.png.4bpp.lz \
	graphics/items/icons/magost_berry.png.4bpp.lz \
	graphics/items/icons/master_ball.png.4bpp.lz \
	graphics/items/icons/max_revive.png.4bpp.lz \
	graphics/items/icons/mech_mail.png.4bpp.lz \
	graphics/items/icons/metal_coat.png.4bpp.lz \
	graphics/items/icons/metal_powder.png.4bpp.lz \
	graphics/items/icons/meteorite.png.4bpp.lz \
	graphics/items/icons/miracle_seed.png.4bpp.lz \
	graphics/items/icons/moomoo_milk.png.4bpp.lz \
	graphics/items/icons/moon_stone.png.4bpp.lz \
	graphics/items/icons/mystic_ticket.png.4bpp.lz \
	graphics/items/icons/mystic_water.png.4bpp.lz \
	graphics/items/icons/nanab_berry.png.4bpp.lz \
	graphics/items/icons/nest_ball.png.4bpp.lz \
	graphics/items/icons/net_ball.png.4bpp.lz \
	graphics/items/icons/never_melt_ice.png.4bpp.lz \
	graphics/items/icons/nomel_berry.png.4bpp.lz \
	graphics/items/icons/nugget.png.4bpp.lz \
	graphics/items/icons/oaks_parcel.png.4bpp.lz \
	graphics/items/icons/old_amber.png.4bpp.lz \
	graphics/items/icons/old_rod.png.4bpp.lz \
	graphics/items/icons/old_sea_map.png.4bpp.lz \
	graphics/items/icons/oran_berry.png.4bpp.lz \
	graphics/items/icons/orange_mail.png.4bpp.lz \
	graphics/items/icons/orb.png.4bpp.lz \
	graphics/items/icons/pamtre_berry.png.4bpp.lz \
	graphics/items/icons/pearl.png.4bpp.lz \
	graphics/items/icons/pecha_berry.png.4bpp.lz \
	graphics/items/icons/persim_berry.png.4bpp.lz \
	graphics/items/icons/petaya_berry.png.4bpp.lz \
	graphics/items/icons/pinap_berry.png.4bpp.lz \
	graphics/items/icons/poison_barb.png.4bpp.lz \
	graphics/items/icons/poke_ball.png.4bpp.lz \
	graphics/items/icons/poke_doll.png.4bpp.lz \
	graphics/items/icons/poke_flute.png.4bpp.lz \
	graphics/items/icons/pokeblock_case.png.4bpp.lz \
	graphics/items/icons/pomeg_berry.png.4bpp.lz \
	graphics/items/icons/potion.png.4bpp.lz \
	graphics/items/icons/powder.png.4bpp.lz \
	graphics/items/icons/powder_jar.png.4bpp.lz \
	graphics/items/icons/pp_max.png.4bpp.lz \
	graphics/items/icons/pp_up.png.4bpp.lz \
	graphics/items/icons/premier_ball.png.4bpp.lz \
	graphics/items/icons/qualot_berry.png.4bpp.lz \
	graphics/items/icons/question_mark.png.4bpp.lz \
	graphics/items/icons/quick_claw.png.4bpp.lz \
	graphics/items/icons/rabuta_berry.png.4bpp.lz \
	graphics/items/icons/rainbow_pass.png.4bpp.lz \
	graphics/items/icons/rare_candy.png.4bpp.lz \
	graphics/items/icons/rawst_berry.png.4bpp.lz \
	graphics/items/icons/razz_berry.png.4bpp.lz \
	graphics/items/icons/repeat_ball.png.4bpp.lz \
	graphics/items/icons/repel.png.4bpp.lz \
	graphics/items/icons/retro_mail.png.4bpp.lz \
	graphics/items/icons/return_to_field_arrow.png.4bpp.lz \
	graphics/items/icons/revival_herb.png.4bpp.lz \
	graphics/items/icons/revive.png.4bpp.lz \
	graphics/items/icons/room1_key.png.4bpp.lz \
	graphics/items/icons/room2_key.png.4bpp.lz \
	graphics/items/icons/room4_key.png.4bpp.lz \
	graphics/items/icons/room6_key.png.4bpp.lz \
	graphics/items/icons/root_fossil.png.4bpp.lz \
	graphics/items/icons/sacred_ash.png.4bpp.lz \
	graphics/items/icons/safari_ball.png.4bpp.lz \
	graphics/items/icons/salac_berry.png.4bpp.lz \
	graphics/items/icons/scanner.png.4bpp.lz \
	graphics/items/icons/scarf.png.4bpp.lz \
	graphics/items/icons/scope_lens.png.4bpp.lz \
	graphics/items/icons/sea_incense.png.4bpp.lz \
	graphics/items/icons/secret_key.png.4bpp.lz \
	graphics/items/icons/shadow_mail.png.4bpp.lz \
	graphics/items/icons/shard.png.4bpp.lz \
	graphics/items/icons/sharp_beak.png.4bpp.lz \
	graphics/items/icons/shell_bell.png.4bpp.lz \
	graphics/items/icons/shoal_shell.png.4bpp.lz \
	graphics/items/icons/silk_scarf.png.4bpp.lz \
	graphics/items/icons/silph_scope.png.4bpp.lz \
	graphics/items/icons/silver_powder.png.4bpp.lz \
	graphics/items/icons/sitrus_berry.png.4bpp.lz \
	graphics/items/icons/smoke_ball.png.4bpp.lz \
	graphics/items/icons/soda_pop.png.4bpp.lz \
	graphics/items/icons/soft_sand.png.4bpp.lz \
	graphics/items/icons/soot_sack.png.4bpp.lz \
	graphics/items/icons/soothe_bell.png.4bpp.lz \
	graphics/items/icons/soul_dew.png.4bpp.lz \
	graphics/items/icons/spell_tag.png.4bpp.lz \
	graphics/items/icons/spelon_berry.png.4bpp.lz \
	graphics/items/icons/ss_ticket.png.4bpp.lz \
	graphics/items/icons/star_piece.png.4bpp.lz \
	graphics/items/icons/stardust.png.4bpp.lz \
	graphics/items/icons/starf_berry.png.4bpp.lz \
	graphics/items/icons/status_heal.png.4bpp.lz \
	graphics/items/icons/stick.png.4bpp.lz \
	graphics/items/icons/storage_key.png.4bpp.lz \
	graphics/items/icons/sun_stone.png.4bpp.lz \
	graphics/items/icons/super_rod.png.4bpp.lz \
	graphics/items/icons/tamato_berry.png.4bpp.lz \
	graphics/items/icons/tea.png.4bpp.lz \
	graphics/items/icons/teachy_tv.png.4bpp.lz \
	graphics/items/icons/thick_club.png.4bpp.lz \
	graphics/items/icons/thunder_stone.png.4bpp.lz \
	graphics/items/icons/timer_ball.png.4bpp.lz \
	graphics/items/icons/tiny_mushroom.png.4bpp.lz \
	graphics/items/icons/tm.png.4bpp.lz \
	graphics/items/icons/tm_case.png.4bpp.lz \
	graphics/items/icons/town_map.png.4bpp.lz \
	graphics/items/icons/tri_pass.png.4bpp.lz \
	graphics/items/icons/tropic_mail.png.4bpp.lz \
	graphics/items/icons/twisted_spoon.png.4bpp.lz \
	graphics/items/icons/ultra_ball.png.4bpp.lz \
	graphics/items/icons/up_grade.png.4bpp.lz \
	graphics/items/icons/vitamin.png.4bpp.lz \
	graphics/items/icons/vs_seeker.png.4bpp.lz \
	graphics/items/icons/wailmer_pail.png.4bpp.lz \
	graphics/items/icons/water_stone.png.4bpp.lz \
	graphics/items/icons/watmel_berry.png.4bpp.lz \
	graphics/items/icons/wave_mail.png.4bpp.lz \
	graphics/items/icons/wepear_berry.png.4bpp.lz \
	graphics/items/icons/wiki_berry.png.4bpp.lz \
	graphics/items/icons/wood_mail.png.4bpp.lz

JP_ITEM_ICON_INTERMEDIATES := $(patsubst %.lz,%,$(JP_ITEM_ICON_ASSETS))

$(filter %.png.4bpp,$(JP_ITEM_ICON_INTERMEDIATES)): %.png.4bpp: %.png Makefile | tools
	$(GFX) $< $@

$(filter %.pal.gbapal,$(JP_ITEM_ICON_INTERMEDIATES)): %.pal.gbapal: %.pal Makefile | tools
	$(GFX) $< $@

$(JP_ITEM_ICON_ASSETS): %.lz: % Makefile | tools
	$(GFX) $< $@

$(C_BUILDDIR)/graphics.o: src/data/graphics/items.h $(JP_ITEM_ICON_ASSETS)
$(C_BUILDDIR)/item_icon.o: src/data/item_icon_table.h include/graphics.h

JP_ROULETTE_ASSETS := graphics/roulette/azurill.png.gbapal \
	graphics/roulette/ball.png.4bpp.lz \
	graphics/roulette/ball.png.gbapal \
	graphics/roulette/ball_counter.png.4bpp.lz \
	graphics/roulette/ball_counter.png.gbapal \
	graphics/roulette/center.png.4bpp.lz \
	graphics/roulette/credit.png.4bpp.lz \
	graphics/roulette/credit.png.gbapal \
	graphics/roulette/cursor.png.4bpp.lz \
	graphics/roulette/cursor.png.gbapal \
	graphics/roulette/grid.bin.lz \
	graphics/roulette/grid_icons.png.4bpp.lz \
	graphics/roulette/grid_icons.png.gbapal \
	graphics/roulette/headers.png.4bpp.lz \
	graphics/roulette/makuhita.png.gbapal \
	graphics/roulette/multiplier.png.4bpp.lz \
	graphics/roulette/numbers.png.4bpp.lz \
	graphics/roulette/roulette_tilt.4bpp.lz \
	graphics/roulette/shadow.png.4bpp.lz \
	graphics/roulette/shadow.png.gbapal \
	graphics/roulette/shroomish.png.gbapal \
	graphics/roulette/skitty.png.gbapal \
	graphics/roulette/tailow.png.gbapal \
	graphics/roulette/unused_1.pal.gbapal \
	graphics/roulette/unused_2.pal.gbapal \
	graphics/roulette/unused_3.pal.gbapal \
	graphics/roulette/unused_4.pal.gbapal \
	graphics/roulette/wheel.bin.lz \
	graphics/roulette/wheel.png.8bpp.lz \
	graphics/roulette/wheel.png.gbapal \
	graphics/roulette/wheel_icons.4bpp.lz \
	graphics/roulette/window.png.4bpp.lz \
	graphics/roulette/wynaut.png.gbapal

JP_ROULETTE_INTERMEDIATES := graphics/roulette/azurill.png.4bpp \
	graphics/roulette/ball.png.4bpp \
	graphics/roulette/ball_counter.png.4bpp \
	graphics/roulette/center.png.4bpp \
	graphics/roulette/credit.png.4bpp \
	graphics/roulette/cursor.png.4bpp \
	graphics/roulette/grid_icons.png.4bpp \
	graphics/roulette/headers.png.4bpp \
	graphics/roulette/makuhita.png.4bpp \
	graphics/roulette/multiplier.png.4bpp \
	graphics/roulette/numbers.png.4bpp \
	graphics/roulette/roulette_tilt.4bpp \
	graphics/roulette/shadow.png.4bpp \
	graphics/roulette/shroomish.png.4bpp \
	graphics/roulette/skitty.png.4bpp \
	graphics/roulette/tailow.png.4bpp \
	graphics/roulette/wheel.png.8bpp \
	graphics/roulette/wheel_icons.4bpp \
	graphics/roulette/window.png.4bpp \
	graphics/roulette/wynaut.png.4bpp

graphics/roulette/azurill.png.4bpp graphics/roulette/ball.png.4bpp graphics/roulette/ball_counter.png.4bpp graphics/roulette/center.png.4bpp graphics/roulette/credit.png.4bpp graphics/roulette/cursor.png.4bpp graphics/roulette/grid_icons.png.4bpp graphics/roulette/headers.png.4bpp graphics/roulette/makuhita.png.4bpp graphics/roulette/multiplier.png.4bpp graphics/roulette/numbers.png.4bpp graphics/roulette/shadow.png.4bpp graphics/roulette/shroomish.png.4bpp graphics/roulette/skitty.png.4bpp graphics/roulette/tailow.png.4bpp graphics/roulette/window.png.4bpp graphics/roulette/wynaut.png.4bpp: %.png.4bpp: %.png Makefile | tools
	$(GFX) $< $@

graphics/roulette/wheel.png.8bpp: %.png.8bpp: %.png Makefile | tools
	$(GFX) $< $@

graphics/roulette/azurill.png.gbapal graphics/roulette/ball.png.gbapal graphics/roulette/ball_counter.png.gbapal graphics/roulette/credit.png.gbapal graphics/roulette/cursor.png.gbapal graphics/roulette/grid_icons.png.gbapal graphics/roulette/makuhita.png.gbapal graphics/roulette/shadow.png.gbapal graphics/roulette/shroomish.png.gbapal graphics/roulette/skitty.png.gbapal graphics/roulette/tailow.png.gbapal graphics/roulette/wheel.png.gbapal graphics/roulette/wynaut.png.gbapal: %.png.gbapal: %.png Makefile | tools
	$(GFX) $< $@

graphics/roulette/unused_1.pal.gbapal graphics/roulette/unused_2.pal.gbapal graphics/roulette/unused_3.pal.gbapal graphics/roulette/unused_4.pal.gbapal: %.pal.gbapal: %.pal Makefile | tools
	$(GFX) $< $@

graphics/roulette/roulette_tilt.4bpp: graphics/roulette/shroomish.png.4bpp graphics/roulette/tailow.png.4bpp Makefile
	cat $(filter %.4bpp,$^) >$@

graphics/roulette/wheel_icons.4bpp: graphics/roulette/wynaut.png.4bpp graphics/roulette/azurill.png.4bpp graphics/roulette/skitty.png.4bpp graphics/roulette/makuhita.png.4bpp Makefile
	cat $(filter %.4bpp,$^) >$@

$(filter %.lz,$(JP_ROULETTE_ASSETS)): %.lz: % Makefile | tools
	$(GFX) $< $@

$(C_BUILDDIR)/graphics.o: $(JP_ROULETTE_ASSETS)

$(C_BUILDDIR)/roulette.d: src/roulette.c Makefile | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(C_BUILDDIR)/roulette.d

$(C_BUILDDIR)/roulette.o: src/roulette.c charmap.txt $(JP_ROULETTE_ASSETS) include/global.h include/malloc.h include/bg.h include/coins.h include/decompress.h include/event_data.h include/field_screen_effect.h include/gpu_regs.h include/graphics.h include/m4a.h include/main.h include/menu.h include/menu_helpers.h include/overworld.h include/palette.h include/palette_util.h include/random.h include/roulette.h include/rtc.h include/scanline_effect.h include/script.h include/sound.h include/sprite.h include/string_util.h include/strings.h include/task.h include/trig.h include/tv.h include/window.h include/constants/coins.h include/constants/rgb.h include/constants/roulette.h include/constants/songs.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/roulette.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/roulette.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/roulette.gen.s

JP_MAIL_ASSETS := graphics/mail/bead/map.bin.lz \
	graphics/mail/bead/palette.pal.gbapal \
	graphics/mail/bead/tiles.png.4bpp.lz \
	graphics/mail/dream/map.bin.lz \
	graphics/mail/dream/palette.pal.gbapal \
	graphics/mail/dream/tiles.png.4bpp.lz \
	graphics/mail/fab/map.bin.lz \
	graphics/mail/fab/palette.pal.gbapal \
	graphics/mail/fab/tiles.png.4bpp.lz \
	graphics/mail/glitter/map.bin.lz \
	graphics/mail/glitter/palette.pal.gbapal \
	graphics/mail/glitter/tiles.png.4bpp.lz \
	graphics/mail/harbor/map.bin.lz \
	graphics/mail/harbor/palette.pal.gbapal \
	graphics/mail/harbor/tiles.png.4bpp.lz \
	graphics/mail/mech/map.bin.lz \
	graphics/mail/mech/palette.pal.gbapal \
	graphics/mail/mech/tiles.png.4bpp.lz \
	graphics/mail/orange/map.bin.lz \
	graphics/mail/orange/palette.pal.gbapal \
	graphics/mail/orange/tiles.png.4bpp.lz \
	graphics/mail/retro/map.bin.lz \
	graphics/mail/retro/palette.pal.gbapal \
	graphics/mail/retro/tiles.png.4bpp.lz \
	graphics/mail/shadow/map.bin.lz \
	graphics/mail/shadow/palette.pal.gbapal \
	graphics/mail/shadow/tiles.png.4bpp.lz \
	graphics/mail/tropic/map.bin.lz \
	graphics/mail/tropic/palette.pal.gbapal \
	graphics/mail/tropic/tiles.png.4bpp.lz \
	graphics/mail/wave/map.bin.lz \
	graphics/mail/wave/palette.pal.gbapal \
	graphics/mail/wave/tiles.png.4bpp.lz \
	graphics/mail/wood/map.bin.lz \
	graphics/mail/wood/palette.pal.gbapal \
	graphics/mail/wood/tiles.png.4bpp.lz

JP_MAIL_INTERMEDIATES := graphics/mail/bead/tiles.png.4bpp \
	graphics/mail/dream/tiles.png.4bpp \
	graphics/mail/fab/tiles.png.4bpp \
	graphics/mail/glitter/tiles.png.4bpp \
	graphics/mail/harbor/tiles.png.4bpp \
	graphics/mail/mech/tiles.png.4bpp \
	graphics/mail/orange/tiles.png.4bpp \
	graphics/mail/retro/tiles.png.4bpp \
	graphics/mail/shadow/tiles.png.4bpp \
	graphics/mail/tropic/tiles.png.4bpp \
	graphics/mail/wave/tiles.png.4bpp \
	graphics/mail/wood/tiles.png.4bpp

graphics/mail/bead/tiles.png.4bpp graphics/mail/dream/tiles.png.4bpp graphics/mail/fab/tiles.png.4bpp graphics/mail/glitter/tiles.png.4bpp graphics/mail/harbor/tiles.png.4bpp graphics/mail/mech/tiles.png.4bpp graphics/mail/orange/tiles.png.4bpp graphics/mail/retro/tiles.png.4bpp graphics/mail/shadow/tiles.png.4bpp graphics/mail/tropic/tiles.png.4bpp graphics/mail/wave/tiles.png.4bpp graphics/mail/wood/tiles.png.4bpp: %.png.4bpp: %.png Makefile | tools
	$(GFX) $< $@

graphics/mail/bead/palette.pal.gbapal graphics/mail/dream/palette.pal.gbapal graphics/mail/fab/palette.pal.gbapal graphics/mail/glitter/palette.pal.gbapal graphics/mail/harbor/palette.pal.gbapal graphics/mail/mech/palette.pal.gbapal graphics/mail/orange/palette.pal.gbapal graphics/mail/retro/palette.pal.gbapal graphics/mail/shadow/palette.pal.gbapal graphics/mail/tropic/palette.pal.gbapal graphics/mail/wave/palette.pal.gbapal graphics/mail/wood/palette.pal.gbapal: %.pal.gbapal: %.pal Makefile | tools
	$(GFX) $< $@

$(filter %.lz,$(JP_MAIL_ASSETS)): %.lz: % Makefile | tools
	$(GFX) $< $@

$(C_BUILDDIR)/graphics.o: src/data/graphics/mail.h $(JP_MAIL_ASSETS)

$(C_BUILDDIR)/mail.d: src/mail.c Makefile | tools
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ -I include -I "" $<

-include $(C_BUILDDIR)/mail.d

$(C_BUILDDIR)/mail.o: src/mail.c charmap.txt include/graphics.h
	@mkdir -p $(dir $@)
	@set -o pipefail; { $(CPP) $(CPPFLAGS) -P -x c $< | $(PREPROC) -i $< charmap.txt | $(CC) $(CFLAGS) -o - -; } > $(C_BUILDDIR)/mail.gen.s
	@awk '/^\.Lfe[0-9]+:/{print "\t.align\t2, 0"} {print}' $(C_BUILDDIR)/mail.gen.s | $(AS) $(ASFLAGS) -o $@ -
	@rm -f $(C_BUILDDIR)/mail.gen.s
