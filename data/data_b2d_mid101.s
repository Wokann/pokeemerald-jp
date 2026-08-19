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


	.section .rodata.mid101_after_item_menu




	.globl gUnknown_85E72E4
gUnknown_85E72E4: @ 0x85E72E4
	.incbin "baserom_jp.gba", 0x5e72e4, 0x48

	.globl gUnknown_85E732C
gUnknown_85E732C: @ 0x85E732C
	.incbin "baserom_jp.gba", 0x5e732c, 0x104


	.section .rodata.mid101_after_mirage
