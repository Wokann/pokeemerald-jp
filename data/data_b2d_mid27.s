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

	.globl gUnknown_846F9D6
gUnknown_846F9D6: @ 0x846F9D6
	.incbin "baserom_jp.gba", 0x46f9d6, 0x6

	.globl gUnknown_846F9DC
gUnknown_846F9DC: @ 0x846F9DC
	.incbin "baserom_jp.gba", 0x46f9dc, 0xc
