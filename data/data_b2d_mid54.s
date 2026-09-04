.include "sound/MPlayDef.s"
	.section .rodata.pokedex_prefix
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

.globl gUnknown_8539C0E
gUnknown_8539C0E: @ 0x8539C0E
	.incbin "baserom_jp.gba", 0x539c0e, 0x42

	.section .rodata.pokedex_suffix

	.globl gUnknown_854410C
gUnknown_854410C: @ 0x854410C
	.incbin "baserom_jp.gba", 0x54410c, 0x28

	.globl gUnknown_8544134
gUnknown_8544134: @ 0x8544134
	.incbin "baserom_jp.gba", 0x544134, 0x18

	.globl gUnknown_854414C
gUnknown_854414C: @ 0x854414C
	.incbin "baserom_jp.gba", 0x54414c, 0x54
