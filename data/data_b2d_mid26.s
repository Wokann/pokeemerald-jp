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

	.section .rodata.data_b2d_mid26_after_wild_encounter_route119_data
	.align 2

	.section .rodata.data_b2d_mid26_after_field_effect_script_funcs
	.align 2
