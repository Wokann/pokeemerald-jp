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

	.globl gMonStillFrontPic_CircledQuestionMark
gMonStillFrontPic_CircledQuestionMark: @ 0x8C00758
	.incbin "baserom_jp.gba", 0xc00758, 0x248

	.globl gMonBackPic_CircledQuestionMark
gMonBackPic_CircledQuestionMark: @ 0x8C009A0
	.incbin "baserom_jp.gba", 0xc009a0, 0x248

	.globl gMonPalette_CircledQuestionMark
gMonPalette_CircledQuestionMark: @ 0x8C00BE8
	.incbin "baserom_jp.gba", 0xc00be8, 0x18

	.globl gMonShinyPalette_CircledQuestionMark
gMonShinyPalette_CircledQuestionMark: @ 0x8C00C00
	.incbin "baserom_jp.gba", 0xc00c00, 0x1708
