.include "sound/MPlayDef.s"
	.section .rodata.menu_specialized_mid8_prefix
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl gUnknown_85F7C98
gUnknown_85F7C98: @ 0x85F7C98
	.incbin "baserom_jp.gba", 0x5f7c98, 0x1e40

	.section .rodata.menu_specialized_mid8_middle

	.globl gUnknown_85FA0D8
gUnknown_85FA0D8: @ 0x85FA0D8
	.incbin "baserom_jp.gba", 0x5fa0d8, 0x798

