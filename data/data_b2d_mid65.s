.include "sound/MPlayDef.s"
	.section .rodata.battle_transition_sprite_template_prefix, "a", %progbits
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl gUnknown_85A8918
gUnknown_85A8918: @ 0x85A8918
	.incbin "baserom_jp.gba", 0x5a8918, 0x6c

	.section .rodata

	.globl gUnknown_85A9544
gUnknown_85A9544: @ 0x85A9544
	.incbin "baserom_jp.gba", 0x5a9544, 0x7d1
