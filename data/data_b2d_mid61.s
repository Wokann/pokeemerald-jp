.include "sound/MPlayDef.s"
	.section .rodata.data_b2d_mid61_before_mon_markings_data
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl gUnknown_8579F34
gUnknown_8579F34: @ 0x8579F34
	.incbin "baserom_jp.gba", 0x579f34, 0x4

	.globl gMonMarkingsMenu_Pal
gMonMarkingsMenu_Pal: @ 0x8579F38
	.incbin "graphics/mon_markings/gMonMarkingsMenu_Pal.bin"

	.globl gMonMarkingsMenu_Gfx
gMonMarkingsMenu_Gfx: @ 0x8579F58
	.incbin "graphics/mon_markings/gMonMarkingsMenu_Gfx.bin"

	.globl sMonMarkings_Pal
sMonMarkings_Pal: @ 0x857A278
	.incbin "graphics/mon_markings/sMonMarkings_Pal.bin"

	.globl sMonMarkings_Gfx
sMonMarkings_Gfx: @ 0x857A298
	.incbin "graphics/mon_markings/sMonMarkings_Gfx.bin"

	.section .rodata.data_b2d_mid61_after_region_map


	.globl gUnknown_857D884
gUnknown_857D884: @ 0x857D884
	.incbin "baserom_jp.gba", 0x57d884, 0x2580

	.include "data/decoration/tiles.inc"
	.include "data/decoration/description.inc"
	.include "data/decoration/header.inc"

	.globl gUnknown_8581A0C
gUnknown_8581A0C: @ 0x8581A0C
	.incbin "baserom_jp.gba", 0x581a0c, 0x20

	.globl gUnknown_8581A2C
gUnknown_8581A2C: @ 0x8581A2C
	.incbin "baserom_jp.gba", 0x581a2c, 0x20

	.globl gUnknown_8581A4C
gUnknown_8581A4C: @ 0x8581A4C
	.incbin "baserom_jp.gba", 0x581a4c, 0x10

	.globl gUnknown_8581A5C
gUnknown_8581A5C: @ 0x8581A5C
	.incbin "baserom_jp.gba", 0x581a5c, 0x18

	.globl gUnknown_8581A74
gUnknown_8581A74: @ 0x8581A74
	.incbin "baserom_jp.gba", 0x581a74, 0x20

	.globl gUnknown_8581A94
gUnknown_8581A94: @ 0x8581A94
	.incbin "baserom_jp.gba", 0x581a94, 0x20

	.globl gUnknown_8581AB4
gUnknown_8581AB4: @ 0x8581AB4
	.incbin "baserom_jp.gba", 0x581ab4, 0x18

	.globl gUnknown_8581ACC
gUnknown_8581ACC: @ 0x8581ACC
	.incbin "baserom_jp.gba", 0x581acc, 0x5c8

	.globl gUnknown_8582094
gUnknown_8582094: @ 0x8582094
	.incbin "baserom_jp.gba", 0x582094, 0xa0

	.globl gUnknown_8582134
gUnknown_8582134: @ 0x8582134
	.incbin "baserom_jp.gba", 0x582134, 0x3c

	.globl gUnknown_8582170
gUnknown_8582170: @ 0x8582170
	.incbin "baserom_jp.gba", 0x582170, 0x18

	.globl gUnknown_8582188
gUnknown_8582188: @ 0x8582188
	.incbin "baserom_jp.gba", 0x582188, 0x18

	.globl gUnknown_85821A0
gUnknown_85821A0: @ 0x85821A0
	.incbin "baserom_jp.gba", 0x5821a0, 0x8

	.globl gUnknown_85821A8
gUnknown_85821A8: @ 0x85821A8
	.incbin "baserom_jp.gba", 0x5821a8, 0x8

	.globl gUnknown_85821B0
gUnknown_85821B0: @ 0x85821B0
	.incbin "baserom_jp.gba", 0x5821b0, 0x8

	.globl gUnknown_85821B8
gUnknown_85821B8: @ 0x85821B8
	.incbin "baserom_jp.gba", 0x5821b8, 0x10

	.globl gUnknown_85821C8
gUnknown_85821C8: @ 0x85821C8
	.incbin "baserom_jp.gba", 0x5821c8, 0x8

	.globl gUnknown_85821D0
gUnknown_85821D0: @ 0x85821D0
	.incbin "baserom_jp.gba", 0x5821d0, 0x8

	.globl gUnknown_85821D8
gUnknown_85821D8: @ 0x85821D8
	.incbin "baserom_jp.gba", 0x5821d8, 0x54

	.globl gUnknown_858222C
gUnknown_858222C: @ 0x858222C
	.incbin "baserom_jp.gba", 0x58222c, 0x8

	.globl gUnknown_8582234
gUnknown_8582234: @ 0x8582234
	.incbin "baserom_jp.gba", 0x582234, 0x88

	.globl gUnknown_85822BC
gUnknown_85822BC: @ 0x85822BC
	.incbin "baserom_jp.gba", 0x5822bc, 0x8

	.globl gUnknown_85822C4
gUnknown_85822C4: @ 0x85822C4
	.incbin "baserom_jp.gba", 0x5822c4, 0x24

	.globl gUnknown_85822E8
gUnknown_85822E8: @ 0x85822E8
	.incbin "baserom_jp.gba", 0x5822e8, 0x18

	.globl gUnknown_8582300
gUnknown_8582300: @ 0x8582300
	.incbin "baserom_jp.gba", 0x582300, 0x20a8
