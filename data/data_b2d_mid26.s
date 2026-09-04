#include "constants/global.h"
#include "constants/event_bg.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/secret_bases.h"
#include "constants/trainer_types.h"
#include "constants/berry.h"
#include "constants/vars.h"
#include "constants/weather.h"

#define NULL 0

.include "sound/MPlayDef.s"
	.section .rodata.data_b2d_mid26_before_tileset_anims_data
	.include "asm/macros.inc"

#include "constants/tms_hms.inc"

	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"


	.section .rodata.data_b2d_mid26_after_tileset_anims_data_before_palette_static_data

	.section .rodata.data_b2d_mid26_after_palette_static_data_before_sound_fanfare_data

	.section .rodata.data_b2d_mid26_after_sound_fanfare_data_before_battle_anim_oam_data

	.section .rodata.data_b2d_mid26_after_battle_anim_background_data_before_battle_anim_script_cmd_data

	.section .rodata.data_b2d_mid26_after_battle_anim_script_cmd_data_before_battle_anim_mons_static_data

	.section .rodata.data_b2d_mid26_after_field_weather_drought_before_field_weather_static_data

	.globl gWeatherPtr
gWeatherPtr: @ 0x8526DE8
	.4byte gUnknown_20380F4 @ &gWeather

	.section .rodata.data_b2d_mid26_after_wild_encounter_data
	.globl gBattlePyramid_1_LandMons
gBattlePyramid_1_LandMons: @ 0x852E3B8
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.globl gBattlePyramid_1_LandMonsInfo
gBattlePyramid_1_LandMonsInfo: @ 0x852E3E8
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_1_LandMons
	.globl gBattlePyramid_2_LandMons
gBattlePyramid_2_LandMons: @ 0x852E3F0
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.globl gBattlePyramid_2_LandMonsInfo
gBattlePyramid_2_LandMonsInfo: @ 0x852E420
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_2_LandMons
	.globl gBattlePyramid_3_LandMons
gBattlePyramid_3_LandMons: @ 0x852E428
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.globl gBattlePyramid_3_LandMonsInfo
gBattlePyramid_3_LandMonsInfo: @ 0x852E458
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_3_LandMons
	.globl gBattlePyramid_4_LandMons
gBattlePyramid_4_LandMons: @ 0x852E460
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.globl gBattlePyramid_4_LandMonsInfo
gBattlePyramid_4_LandMonsInfo: @ 0x852E490
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_4_LandMons
	.globl gBattlePyramid_5_LandMons
gBattlePyramid_5_LandMons: @ 0x852E498
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.globl gBattlePyramid_5_LandMonsInfo
gBattlePyramid_5_LandMonsInfo: @ 0x852E4C8
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_5_LandMons
	.globl gBattlePyramid_6_LandMons
gBattlePyramid_6_LandMons: @ 0x852E4D0
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.globl gBattlePyramid_6_LandMonsInfo
gBattlePyramid_6_LandMonsInfo: @ 0x852E500
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_6_LandMons
	.globl gBattlePyramid_7_LandMons
gBattlePyramid_7_LandMons: @ 0x852E508
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.globl gBattlePyramid_7_LandMonsInfo
gBattlePyramid_7_LandMonsInfo: @ 0x852E538
	.byte 8
	.byte 0, 0, 0
	.4byte gBattlePyramid_7_LandMons

	.globl gBattlePyramidWildMonHeaders
gBattlePyramidWildMonHeaders: @ 0x852E540
	.byte 0, 1 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_1_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 2 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_2_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 3 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_3_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 4 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_4_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 5 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_5_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 6 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_6_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 7 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_7_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 255, 255
	.hword 0
	.4byte 0 @ landMonsInfo NULL
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.globl gBattlePike_1_LandMons
gBattlePike_1_LandMons: @ 0x852E5E0
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_1_LandMonsInfo
gBattlePike_1_LandMonsInfo: @ 0x852E610
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_1_LandMons
	.globl gBattlePike_2_LandMons
gBattlePike_2_LandMons: @ 0x852E618
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_2_LandMonsInfo
gBattlePike_2_LandMonsInfo: @ 0x852E648
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_2_LandMons
	.globl gBattlePike_3_LandMons
gBattlePike_3_LandMons: @ 0x852E650
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_3_LandMonsInfo
gBattlePike_3_LandMonsInfo: @ 0x852E680
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_3_LandMons
	.globl gBattlePike_4_LandMons
gBattlePike_4_LandMons: @ 0x852E688
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_4_LandMonsInfo
gBattlePike_4_LandMonsInfo: @ 0x852E6B8
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_4_LandMons

	.globl gBattlePikeWildMonHeaders
gBattlePikeWildMonHeaders: @ 0x852E6C0
	.byte 0, 1 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_1_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 0, 2 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_2_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 0, 3 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_3_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 0, 4 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_4_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 255, 255
	.hword 0
	.4byte 0 @ landMonsInfo NULL
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL

	.section .rodata.data_b2d_mid26_after_wild_encounter_route119_data
	.align 2

	.section .rodata.data_b2d_mid26_after_field_effect_script_funcs
	.align 2
