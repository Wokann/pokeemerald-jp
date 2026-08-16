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

	.globl gUnknown_85F737C
gUnknown_85F737C: @ 0x85F737C
	.incbin "baserom_jp.gba", 0x5f737c, 0x638

	.globl sMatchCallHeaders
sMatchCallHeaders: @ 0x85F79B4
	.incbin "baserom_jp.gba", 0x5f79b4, 0x54

	.globl sMatchCallGetEnabledFuncs
sMatchCallGetEnabledFuncs: @ 0x85F7A08
	.incbin "baserom_jp.gba", 0x5f7a08, 0x14

	.globl sMatchCallGetMapSecFuncs
sMatchCallGetMapSecFuncs: @ 0x85F7A1C
	.incbin "baserom_jp.gba", 0x5f7a1c, 0x14

	.globl sMatchCall_IsRematchableFunctions
sMatchCall_IsRematchableFunctions: @ 0x85F7A30
	.incbin "baserom_jp.gba", 0x5f7a30, 0x14

	.globl sMatchCall_HasCheckPageFunctions
sMatchCall_HasCheckPageFunctions: @ 0x85F7A44
	.incbin "baserom_jp.gba", 0x5f7a44, 0x14

	.globl sMatchCall_GetRematchTableIdxFunctions
sMatchCall_GetRematchTableIdxFunctions: @ 0x85F7A58
	.incbin "baserom_jp.gba", 0x5f7a58, 0x14

	.globl sMatchCall_GetMessageFunctions
sMatchCall_GetMessageFunctions: @ 0x85F7A6C
	.incbin "baserom_jp.gba", 0x5f7a6c, 0x14

	.globl sMatchCall_GetNameAndDescFunctions
sMatchCall_GetNameAndDescFunctions: @ 0x85F7A80
	.incbin "baserom_jp.gba", 0x5f7a80, 0x14

	.globl sCheckPageOverrides
sCheckPageOverrides: @ 0x85F7A94
	.incbin "baserom_jp.gba", 0x5f7a94, 0x60

