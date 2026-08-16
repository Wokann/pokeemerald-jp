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
	.globl gMonBackPicTable
gMonBackPicTable: @ 0x82D6148
	.incbin "baserom_jp.gba", 0x2d6148, 0xdc0

	.globl gUnknown_82D6F08
gUnknown_82D6F08: @ 0x82D6F08
	.incbin "baserom_jp.gba", 0x2d6f08, 0xdc0

	.globl gUnknown_82D7CC8
gUnknown_82D7CC8: @ 0x82D7CC8
	.incbin "baserom_jp.gba", 0x2d7cc8, 0xdc0
