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

	.section .rodata.data_b2d_mid26_after_field_screen_effect_flash_data_before_battle_setup_rematch_data

	.globl sBattleTransitionTable_Wild
sBattleTransitionTable_Wild: @ 0x852AB24
	.byte 0x08, 0x09, 0x05, 0x0A, 0x00, 0x0A, 0x07, 0x06

	.globl sBattleTransitionTable_Trainer
sBattleTransitionTable_Trainer: @ 0x852AB2C
	.byte 0x04, 0x0B, 0x02, 0x03, 0x00, 0x0A, 0x01, 0x06

	.globl sBattleTransitionTable_BattleFrontier
sBattleTransitionTable_BattleFrontier: @ 0x852AB34
	.byte 0x1D, 0x1E, 0x1F, 0x20, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29

	.globl sBattleTransitionTable_BattlePyramid
sBattleTransitionTable_BattlePyramid: @ 0x852AB40
	.byte 0x1F, 0x20, 0x21

	.globl sBattleTransitionTable_BattleDome
sBattleTransitionTable_BattleDome: @ 0x852AB43
	.byte 0x1D, 0x1F, 0x20, 0x21, 0x00

	.globl sOrdinaryBattleParams
sOrdinaryBattleParams: @ 0x0052AB48
	.4byte 0x02038868  @ varPtr
	.byte 0x00  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886A  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038874  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203887C  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038890  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C  @ varPtr
	.byte 0x06  @ ptrType
	.byte 0x00, 0x00, 0x00

	.globl sContinueScriptBattleParams
sContinueScriptBattleParams: @ 0x0052AB90
	.4byte 0x02038868  @ varPtr
	.byte 0x00  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886A  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038874  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203887C  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038890  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C  @ varPtr
	.byte 0x06  @ ptrType
	.byte 0x00, 0x00, 0x00

	.globl sDoubleBattleParams
sDoubleBattleParams: @ 0x0052ABD8
	.4byte 0x02038868  @ varPtr
	.byte 0x00  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886A  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038874  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203887C  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038890  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C  @ varPtr
	.byte 0x06  @ ptrType
	.byte 0x00, 0x00, 0x00

	.globl sOrdinaryNoIntroBattleParams
sOrdinaryNoIntroBattleParams: @ 0x0052AC20
	.4byte 0x02038868  @ varPtr
	.byte 0x00  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886A  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038874  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203887C  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038890  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C  @ varPtr
	.byte 0x06  @ ptrType
	.byte 0x00, 0x00, 0x00

	.globl sContinueScriptDoubleBattleParams
sContinueScriptDoubleBattleParams: @ 0x0052AC68
	.4byte 0x02038868
	.byte 0x00
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886A
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038874
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203887C
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038890
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C
	.byte 0x06
	.byte 0x00, 0x00, 0x00

	.globl sTrainerBOrdinaryBattleParams
sTrainerBOrdinaryBattleParams: @ 0x0052ACB0
	.4byte 0x02038868
	.byte 0x00
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886C
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038878
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038880
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038894
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C
	.byte 0x06
	.byte 0x00, 0x00, 0x00

	.globl sTrainerBContinueScriptBattleParams
sTrainerBContinueScriptBattleParams: @ 0x0052ACF8
	.4byte 0x02038868
	.byte 0x00
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886C
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038878
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038880
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038894
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C
	.byte 0x06
	.byte 0x00, 0x00, 0x00

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

	.section .rodata.data_b2d_mid26_after_field_effect_graphics_resource_data
	.align 2

	.globl gFieldEffectScriptFuncs
gFieldEffectScriptFuncs: @ 0x8536E9C
	.4byte FieldEffectCmd_loadtiles + 1, FieldEffectCmd_loadfadedpal + 1, FieldEffectCmd_loadpal + 1, FieldEffectCmd_callnative + 1, FieldEffectCmd_end + 1, FieldEffectCmd_loadgfx_callnative + 1, FieldEffectCmd_loadtiles_callnative + 1, FieldEffectCmd_loadfadedpal_callnative + 1

	.section .rodata.data_b2d_mid26_after_field_effect_script_funcs
	.align 2
