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
	.incbin "graphics/pokemon/question_mark/circled/front.4bpp.lz"

	.globl gMonBackPic_CircledQuestionMark
gMonBackPic_CircledQuestionMark: @ 0x8C009A0
	.incbin "graphics/pokemon/question_mark/circled/back.4bpp.lz"

	.globl gMonPalette_CircledQuestionMark
gMonPalette_CircledQuestionMark: @ 0x8C00BE8
	.incbin "graphics/pokemon/question_mark/circled/normal.gbapal.lz"

	.globl gMonShinyPalette_CircledQuestionMark
gMonShinyPalette_CircledQuestionMark: @ 0x8C00C00
	.incbin "graphics/pokemon/question_mark/circled/shiny.gbapal.lz"

	.section .rodata.data_b2d_gfx_pokemon_none_before_pokeballs
	.incbin "baserom_jp.gba", 0xc00c16, 0xb2e
