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

	.globl gUnknown_85CA3D8
gUnknown_85CA3D8: @ 0x85CA3D8
	.incbin "baserom_jp.gba", 0x5ca3d8, 0x1

	.globl gUnknown_85CA3D9
gUnknown_85CA3D9: @ 0x85CA3D9
	.string "$イベント$"

	.globl gUnknown_85CA3DF
