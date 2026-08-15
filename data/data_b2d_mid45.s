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

	.globl gUnknown_82F5AC0
gUnknown_82F5AC0: @ 0x82F5AC0
	.incbin "baserom_jp.gba", 0x2f5ac0, 0x16
	.globl gUnknown_82F5AD6
gUnknown_82F5AD6: @ 0x82F5AD6
	.incbin "baserom_jp.gba", 0x2f5ad6, 0x1c
	.globl gUnknown_82F5AF2
gUnknown_82F5AF2: @ 0x82F5AF2
	.incbin "baserom_jp.gba", 0x2f5af2, 0x1c
