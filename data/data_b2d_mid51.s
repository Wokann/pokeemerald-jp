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
	.section .rodata.battle_interface_before_egg_hatch

	.globl gUnknown_82FC0FE
gUnknown_82FC0FE: @ 0x82FC0FE
	.incbin "baserom_jp.gba", 0x2fc0fe, 0x8a6

	.section .rodata.pokeball_static_suffix
	.incbin "baserom_jp.gba", 0x2fd0b4, 0x18
