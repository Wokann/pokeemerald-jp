.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"
	.section .rodata.data_b2d_mid47_before_pokemon_battler_data

	.globl gUnknown_82FA6D0
gUnknown_82FA6D0: @ 0x82FA6D0
	.incbin "baserom_jp.gba", 0x2fa6d0, 0x6

	.section .rodata.data_b2d_mid47_between_pokemon_battler_and_hm_data

	@ Alignment before the following Pokemon static data.
	.byte 0

	.section .rodata.data_b2d_mid47_after_pokemon_hm_data


	.section .rodata.data_b2d_mid47_between_egg_moves_and_daycare_menu_data

	@ Alignment before the Day Care level-menu data.
	.byte 0, 0

	.section .rodata.data_b2d_mid47_between_daycare_text_and_compatibility_data

	@ Alignment before the Day Care compatibility-message pointer table.
	.byte 0, 0, 0
