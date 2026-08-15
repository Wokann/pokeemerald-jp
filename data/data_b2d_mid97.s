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

	.globl gJPText_WriteErrorUnableToSaveData
gJPText_WriteErrorUnableToSaveData: @ 0x85CD043
	.string "かきこみ　エラー　です\n"
	.string "データが　ほぞん　できませんでした$あか$あお$　"
	.globl gUnknown_85CD068
gUnknown_85CD068: @ 0x85CD068
	.incbin "baserom_jp.gba", 0x5cd068, 0x10

	.globl gUnknown_85CD078
gUnknown_85CD078: @ 0x85CD078
	.incbin "baserom_jp.gba", 0x5cd078, 0x20

	.globl gUnknown_85CD098
gUnknown_85CD098: @ 0x85CD098
	.incbin "baserom_jp.gba", 0x5cd098, 0x8

	.globl gUnknown_85CD0A0
gUnknown_85CD0A0: @ 0x85CD0A0
	.incbin "baserom_jp.gba", 0x5cd0a0, 0x28

	.globl gUnknown_85CD0C8
gUnknown_85CD0C8: @ 0x85CD0C8
	.incbin "baserom_jp.gba", 0x5cd0c8, 0x14

	.globl gUnknown_85CD0DC
