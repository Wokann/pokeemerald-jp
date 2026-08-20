.include "sound/MPlayDef.s"
	.section .rodata.mid57a_suffix
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.incbin "baserom_jp.gba", 0x55a028, 0x4c

	.globl sBattlePyramid_MapHeaderStrings
sBattlePyramid_MapHeaderStrings: @ 0x855A074
	.4byte 0x0855A028, 0x0855A032, 0x0855A03C, 0x0855A046
	.4byte 0x0855A050, 0x0855A05A, 0x0855A064, 0x0855A06E
	.incbin "baserom_jp.gba", 0x55a094, 0x5d0

	.globl gUnknown_855A664
gUnknown_855A664: @ 0x855A664
	.incbin "baserom_jp.gba", 0x55a664, 0x8

	.globl gUnknown_855A66C
gUnknown_855A66C: @ 0x855A66C
	.incbin "baserom_jp.gba", 0x55a66c, 0x8

	.globl gUnknown_855A674
gUnknown_855A674: @ 0x855A674
	.incbin "baserom_jp.gba", 0x55a674, 0x8

	.globl gUnknown_855A67C
gUnknown_855A67C: @ 0x855A67C
	.incbin "baserom_jp.gba", 0x55a67c, 0x4c

	.globl gUnknown_855A6C8
gUnknown_855A6C8: @ 0x855A6C8
	.incbin "baserom_jp.gba", 0x55a6c8, 0x4

	.globl gUnknown_855A6CC
gUnknown_855A6CC: @ 0x855A6CC
	.incbin "baserom_jp.gba", 0x55a6cc, 0x4

	.globl gUnknown_855A6D0
gUnknown_855A6D0: @ 0x855A6D0
	.incbin "baserom_jp.gba", 0x55a6d0, 0x8

	.globl gUnknown_855A6D8
gUnknown_855A6D8: @ 0x855A6D8
	.incbin "baserom_jp.gba", 0x55a6d8, 0x8

	.globl gUnknown_855A6E0
gUnknown_855A6E0: @ 0x855A6E0
	.incbin "baserom_jp.gba", 0x55a6e0, 0x3c

	.globl gUnknown_855A71C
gUnknown_855A71C: @ 0x855A71C
	.incbin "baserom_jp.gba", 0x55a71c, 0x90

	.globl gUnknown_855A7AC
gUnknown_855A7AC: @ 0x855A7AC
	.incbin "baserom_jp.gba", 0x55a7ac, 0x18

	.globl gUnknown_855A7C4
gUnknown_855A7C4: @ 0x855A7C4
	.incbin "baserom_jp.gba", 0x55a7c4, 0x158

	.globl gBerryCheckCircleSpriteSheet
gBerryCheckCircleSpriteSheet: @ 0x855A91C
	.4byte 0x08D9C4F4
	.hword 0x0800, 0x2710

	.globl gBerryCheckCirclePaletteTable
gBerryCheckCirclePaletteTable: @ 0x855A924
	.4byte 0x08D9C1AC
	.hword 0x2710, 0x0000
	.4byte 0x80000000
	.hword 0x0400, 0x0000
	.hword 0x0000, 0x0000
	.hword 0xFFFF, 0x0000
	.4byte 0x0855A934
