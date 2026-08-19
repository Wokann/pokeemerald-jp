.include "sound/MPlayDef.s"
	.section .rodata.match_call_prefix
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl gUnknown_85F737C
gUnknown_85F737C: @ 0x85F737C
	.incbin "baserom_jp.gba", 0x5f737c, 0x638

	.globl sMatchCallHeaders
sMatchCallHeaders: @ 0x85F79B4
	.incbin "baserom_jp.gba", 0x5f79b4, 0x54

	.section .rodata.match_call_suffix

	.globl sCheckPageOverrides
sCheckPageOverrides: @ 0x85F7A94
	.incbin "baserom_jp.gba", 0x5f7a94, 0x60

