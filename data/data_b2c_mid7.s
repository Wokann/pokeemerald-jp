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
	.4byte 0x081D0D45, 0x081D0D69, 0x081D0D8D, 0x081D0DB1
	.4byte 0x081D0DE9

	.globl sMatchCallGetMapSecFuncs
sMatchCallGetMapSecFuncs: @ 0x85F7A1C
	.4byte 0x081D0E31, 0x081D0E35, 0x081D0E39, 0x081D0E6D
	.4byte 0x081D0E71

	.globl sMatchCall_IsRematchableFunctions
sMatchCall_IsRematchableFunctions: @ 0x85F7A30
	.4byte 0x081D0EA9, 0x081D0EAD, 0x081D0EDD, 0x081D0EFD
	.4byte 0x081D0F01

	.globl sMatchCall_HasCheckPageFunctions
sMatchCall_HasCheckPageFunctions: @ 0x85F7A44
	.4byte 0x081D0F5D, 0x081D0F61, 0x081D0F65, 0x081D0F69
	.4byte 0x081D0F6D

	.globl sMatchCall_GetRematchTableIdxFunctions
sMatchCall_GetRematchTableIdxFunctions: @ 0x85F7A58
	.4byte 0x081D0FA5, 0x081D0FA9, 0x081D0FAD, 0x081D0FB1
	.4byte 0x081D0FB5

	.globl sMatchCall_GetMessageFunctions
sMatchCall_GetMessageFunctions: @ 0x85F7A6C
	.4byte 0x081D0FED, 0x081D0FF9, 0x081D1019, 0x081D1025
	.4byte 0x081D1031

	.globl sMatchCall_GetNameAndDescFunctions
sMatchCall_GetNameAndDescFunctions: @ 0x85F7A80
	.4byte 0x081D11B1, 0x081D11BD, 0x081D11DD, 0x081D11F5
	.4byte 0x081D1201

	.globl sCheckPageOverrides
sCheckPageOverrides: @ 0x85F7A94
	.incbin "baserom_jp.gba", 0x5f7a94, 0x60

