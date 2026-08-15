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

	.globl gUnknown_8566CC7
gUnknown_8566CC7: @ 0x8566CC7
	.incbin "baserom_jp.gba", 0x566cc7, 0x2

	.globl gUnknown_8566CC9
gUnknown_8566CC9: @ 0x8566CC9
	.incbin "baserom_jp.gba", 0x566cc9, 0x6

	.globl gUnknown_8566CCF
gUnknown_8566CCF: @ 0x8566CCF
	.incbin "baserom_jp.gba", 0x566ccf, 0x24

	.globl gUnknown_8566CF3
gUnknown_8566CF3: @ 0x8566CF3
	.incbin "baserom_jp.gba", 0x566cf3, 0x6

	.globl gUnknown_8566CF9
gUnknown_8566CF9: @ 0x8566CF9
	.incbin "baserom_jp.gba", 0x566cf9, 0xf

	.globl gUnknown_8566D08
gUnknown_8566D08: @ 0x8566D08
	.incbin "baserom_jp.gba", 0x566d08, 0x4

	.globl gUnknown_8566D0C
gUnknown_8566D0C: @ 0x8566D0C
	.incbin "baserom_jp.gba", 0x566d0c, 0x20
