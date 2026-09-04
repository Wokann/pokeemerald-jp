.include "sound/MPlayDef.s"
	.section .rodata.option_menu_suffix
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl gUnknown_853741E
gUnknown_853741E: @ 0x853741E
	.incbin "baserom_jp.gba", 0x53741e, 0x2

	.section .rodata.data_b2d_mid15_pokedex_unused_lz

	.globl gUnknown_8537E44
gUnknown_8537E44: @ 0x8537E44
	.incbin "baserom_jp.gba", 0x537e44, 0x48
