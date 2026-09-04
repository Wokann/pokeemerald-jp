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
