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
	.globl gTrainerFrontPicTable
gTrainerFrontPicTable: @ 0x82D8EE4
	.incbin "baserom_jp.gba", 0x2d8ee4, 0x2e8

	.globl gTrainerFrontPicPaletteTable
gTrainerFrontPicPaletteTable: @ 0x82D91CC
	.incbin "baserom_jp.gba", 0x2d91cc, 0x3d0

	.globl gUnknown_82D959C
gUnknown_82D959C: @ 0x82D959C
	.incbin "baserom_jp.gba", 0x2d959c, 0x20
