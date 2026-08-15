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

	.globl gUnknown_85926AC
gUnknown_85926AC: @ 0x85926AC
	.incbin "baserom_jp.gba", 0x5926ac, 0x78

	.globl gUnknown_8592724
gUnknown_8592724: @ 0x8592724
	.incbin "baserom_jp.gba", 0x592724, 0x14

	.globl gUnknown_8592738
gUnknown_8592738: @ 0x8592738
	.incbin "baserom_jp.gba", 0x592738, 0x14

	.globl gUnknown_859274C
gUnknown_859274C: @ 0x859274C
	.incbin "baserom_jp.gba", 0x59274c, 0x340

	.globl gUnknown_8592A8C
gUnknown_8592A8C: @ 0x8592A8C
	.incbin "baserom_jp.gba", 0x592a8c, 0x10

	.globl gUnknown_8592A9C
gUnknown_8592A9C: @ 0x8592A9C
	.incbin "baserom_jp.gba", 0x592a9c, 0x64

	.globl gUnknown_8592B00
gUnknown_8592B00: @ 0x8592B00
	.incbin "baserom_jp.gba", 0x592b00, 0x30

	.globl gUnknown_8592B30
gUnknown_8592B30: @ 0x8592B30
	.incbin "baserom_jp.gba", 0x592b30, 0x30

	.globl gUnknown_8592B60
gUnknown_8592B60: @ 0x8592B60
	.incbin "baserom_jp.gba", 0x592b60, 0x18

	.globl gUnknown_8592B78
gUnknown_8592B78: @ 0x8592B78
	.incbin "baserom_jp.gba", 0x592b78, 0x8

	.globl gUnknown_8592B80
gUnknown_8592B80: @ 0x8592B80
	.incbin "baserom_jp.gba", 0x592b80, 0x8
