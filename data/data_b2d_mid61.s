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

	.globl sOamData_MenuWindow
sOamData_MenuWindow: @ 0x857AAA0
	.byte 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00

	.globl sOamData_8x8
sOamData_8x8: @ 0x857AAA8
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

sAnim_Marking_CircleOff: @ 0x857AAB0
	.hword 0x0000, 0x0005, 0xFFFF, 0x0000
sAnim_Marking_CircleOn: @ 0x857AAB8
	.hword 0x0001, 0x0005, 0xFFFF, 0x0000
sAnim_Marking_SquareOff: @ 0x857AAC0
	.hword 0x0002, 0x0005, 0xFFFF, 0x0000
sAnim_Marking_SquareOn: @ 0x857AAC8
	.hword 0x0003, 0x0005, 0xFFFF, 0x0000
sAnim_Marking_TriangleOff: @ 0x857AAD0
	.hword 0x0004, 0x0005, 0xFFFF, 0x0000
sAnim_Marking_TriangleOn: @ 0x857AAD8
	.hword 0x0005, 0x0005, 0xFFFF, 0x0000
sAnim_Marking_HeartOff: @ 0x857AAE0
	.hword 0x0006, 0x0005, 0xFFFF, 0x0000
sAnim_Marking_HeartOn: @ 0x857AAE8
	.hword 0x0007, 0x0005, 0xFFFF, 0x0000
sAnim_Cursor: @ 0x857AAF0
	.hword 0x0008, 0x0005, 0xFFFF, 0x0000
sAnim_OKCancelText: @ 0x857AAF8
	.hword 0x0009, 0x0005, 0xFFFF, 0x0000

	.globl sAnims_MenuSprite
sAnims_MenuSprite: @ 0x857AB00
	.4byte sAnim_Marking_CircleOff, sAnim_Marking_CircleOn, sAnim_Marking_SquareOff, sAnim_Marking_SquareOn
	.4byte sAnim_Marking_TriangleOff, sAnim_Marking_TriangleOn, sAnim_Marking_HeartOff, sAnim_Marking_HeartOn
	.4byte sAnim_Cursor, sAnim_OKCancelText

sAnim_MenuWindow_UpperHalf: @ 0x857AB28
	.hword 0x0000, 0x0005, 0xFFFF, 0x0000
sAnim_MenuWindow_LowerHalf: @ 0x857AB30
	.hword 0x0040, 0x0005, 0xFFFF, 0x0000

	.globl sAnims_MenuWindow
sAnims_MenuWindow: @ 0x857AB38
	.4byte sAnim_MenuWindow_UpperHalf, sAnim_MenuWindow_LowerHalf

	.globl sOamData_MarkingCombo
sOamData_MarkingCombo: @ 0x857AB40
	.byte 0x00, 0x40, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00

sAnim_MarkingCombo_AllOff: @ 0x857AB48
	.hword 0x0000, 0x0005, 0xFFFF, 0x0000
sAnim_MarkingCombo_Circle: @ 0x857AB50
	.hword 0x0004, 0x0005, 0xFFFF, 0x0000
sAnim_MarkingCombo_Square: @ 0x857AB58
	.hword 0x0008, 0x0005, 0xFFFF, 0x0000
sAnim_MarkingCombo_CircleSquare: @ 0x857AB60
	.hword 0x000C, 0x0005, 0xFFFF, 0x0000
sAnim_MarkingCombo_Triangle: @ 0x857AB68
	.hword 0x0010, 0x0005, 0xFFFF, 0x0000
sAnim_MarkingCombo_CircleTriangle: @ 0x857AB70
	.hword 0x0014, 0x0005, 0xFFFF, 0x0000
sAnim_MarkingCombo_SquareTriangle: @ 0x857AB78
	.hword 0x0018, 0x0005, 0xFFFF, 0x0000
sAnim_MarkingCombo_CircleSquareTriangle: @ 0x857AB80
	.hword 0x001C, 0x0005, 0xFFFF, 0x0000
sAnim_MarkingCombo_Heart: @ 0x857AB88
	.hword 0x0020, 0x0005, 0xFFFF, 0x0000
sAnim_MarkingCombo_CircleHeart: @ 0x857AB90
	.hword 0x0024, 0x0005, 0xFFFF, 0x0000
sAnim_MarkingCombo_SquareHeart: @ 0x857AB98
	.hword 0x0028, 0x0005, 0xFFFF, 0x0000
sAnim_MarkingCombo_CircleSquareHeart: @ 0x857ABA0
	.hword 0x002C, 0x0005, 0xFFFF, 0x0000
sAnim_MarkingCombo_TriangleHeart: @ 0x857ABA8
	.hword 0x0030, 0x0005, 0xFFFF, 0x0000
sAnim_MarkingCombo_CircleTriangleHeart: @ 0x857ABB0
	.hword 0x0034, 0x0005, 0xFFFF, 0x0000
sAnim_MarkingCombo_SquareTriangleHeart: @ 0x857ABB8
	.hword 0x0038, 0x0005, 0xFFFF, 0x0000
sAnim_MarkingCombo_AllOn: @ 0x857ABC0
	.hword 0x003C, 0x0005, 0xFFFF, 0x0000

	.globl sAnims_MarkingCombo
sAnims_MarkingCombo: @ 0x857ABC8
	.4byte sAnim_MarkingCombo_AllOff, sAnim_MarkingCombo_Circle, sAnim_MarkingCombo_Square, sAnim_MarkingCombo_CircleSquare
	.4byte sAnim_MarkingCombo_Triangle, sAnim_MarkingCombo_CircleTriangle, sAnim_MarkingCombo_SquareTriangle, sAnim_MarkingCombo_CircleSquareTriangle
	.4byte sAnim_MarkingCombo_Heart, sAnim_MarkingCombo_CircleHeart, sAnim_MarkingCombo_SquareHeart, sAnim_MarkingCombo_CircleSquareHeart
	.4byte sAnim_MarkingCombo_TriangleHeart, sAnim_MarkingCombo_CircleTriangleHeart, sAnim_MarkingCombo_SquareTriangleHeart, sAnim_MarkingCombo_AllOn

	.globl gUnknown_857AC08
gUnknown_857AC08: @ 0x857AC08
	.incbin "baserom_jp.gba", 0x57ac08, 0xc

	.globl gUnknown_857AC14
gUnknown_857AC14: @ 0x857AC14
	.incbin "baserom_jp.gba", 0x57ac14, 0x20

	.globl gUnknown_857AC34
gUnknown_857AC34: @ 0x857AC34
	.incbin "baserom_jp.gba", 0x57ac34, 0x20

	.globl gUnknown_857AC54
gUnknown_857AC54: @ 0x857AC54
	.incbin "baserom_jp.gba", 0x57ac54, 0x18

	.globl gUnknown_857AC6C
gUnknown_857AC6C: @ 0x857AC6C
	.incbin "baserom_jp.gba", 0x57ac6c, 0x230

	.globl gUnknown_857AE9C
gUnknown_857AE9C: @ 0x857AE9C
	.incbin "baserom_jp.gba", 0x57ae9c, 0x10

	.globl gUnknown_857AEAC
gUnknown_857AEAC: @ 0x857AEAC
	.incbin "baserom_jp.gba", 0x57aeac, 0x8

	.globl sMailBgTemplates
sMailBgTemplates: @ 0x857AEB4
	.byte 0xF8, 0x01, 0x00, 0x00, 0xE1, 0x11, 0x00, 0x00, 0xD2, 0x21, 0x00, 0x00

	.globl sMailWindowTemplates
sMailWindowTemplates: @ 0x857AEC0
	.byte 0x00, 0x03, 0x04, 0x18, 0x0A, 0x0F, 0x01, 0x00
	.byte 0x00, 0x0F, 0x0F, 0x0D, 0x03, 0x0F, 0xF2, 0x00
	.byte 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.globl sMailTextColors
sMailTextColors: @ 0x857AED8
	.byte 0x00, 0x0A, 0x0B, 0x00

	.globl sMailBgColors
sMailBgColors: @ 0x857AEDC
	.hword 0x6ACD, 0x51A5, 0x45FC, 0x38D4

	.globl sMailGraphics
sMailGraphics: @ 0x857AEE4
	.4byte 0x08DBEAC0, 0x08DBEC40, 0x08DBFE4C, 0x000002C0
	.hword 0x294A, 0x6739
	.4byte 0x08DBEAE0, 0x08DBEDE0, 0x08DBFF24, 0x000002E0
	.hword 0x7FFF, 0x4631
	.4byte 0x08DBEB00, 0x08DBEF1C, 0x08DC0004, 0x00000400
	.hword 0x294A, 0x6739
	.4byte 0x08DBEB20, 0x08DBF12C, 0x08DC0110, 0x000001E0
	.hword 0x7FFF, 0x4631
	.4byte 0x08DBEB40, 0x08DBF204, 0x08DC01EC, 0x000002E0
	.hword 0x7FFF, 0x4631
	.4byte 0x08DBEB60, 0x08DBF3FC, 0x08DC02DC, 0x00000300
	.hword 0x294A, 0x6739
	.4byte 0x08DBEB80, 0x08DBF57C, 0x08DC03BC, 0x00000140
	.hword 0x7FFF, 0x4631
	.4byte 0x08DBEBA0, 0x08DBF624, 0x08DC049C, 0x00000300
	.hword 0x7FFF, 0x4631
	.4byte 0x08DBEBC0, 0x08DBF7B4, 0x08DC05A8, 0x00000220
	.hword 0x294A, 0x6739
	.4byte 0x08DBEBE0, 0x08DBF8F4, 0x08DC0698, 0x00000340
	.hword 0x294A, 0x6739
	.4byte 0x08DBEC00, 0x08DBFA5C, 0x08DC0790, 0x000002A0
	.hword 0x294A, 0x6739
	.4byte 0x08DBEC20, 0x08DBFBAC, 0x08DC08A8, 0x00000520
	.hword 0x294A, 0x6739

sLineLayouts_Wide: @ 0x857AFD4
	.byte 0x03, 0x10, 0x00, 0x00
	.byte 0x03, 0x10, 0x00, 0x00
	.byte 0x03, 0x10, 0x00, 0x00

	.globl sMailLayouts_Wide
sMailLayouts_Wide: @ 0x857AFE0
	.byte 0x03, 0x00, 0x02, 0x04
	.4byte 0x0857AFD4
	.byte 0x03, 0x00, 0x02, 0x04
	.4byte 0x0857AFD4
	.byte 0x03, 0x00, 0x02, 0x04
	.4byte 0x0857AFD4
	.byte 0x03, 0x00, 0x02, 0x04
	.4byte 0x0857AFD4
	.byte 0x03, 0x00, 0x02, 0x04
	.4byte 0x0857AFD4
	.byte 0x03, 0x00, 0x02, 0x04
	.4byte 0x0857AFD4
	.byte 0x03, 0x00, 0x02, 0x04
	.4byte 0x0857AFD4
	.byte 0x03, 0x00, 0x02, 0x04
	.4byte 0x0857AFD4
	.byte 0x03, 0x00, 0x02, 0x04
	.4byte 0x0857AFD4
	.byte 0x03, 0x00, 0x02, 0x04
	.4byte 0x0857AFD4
	.byte 0x03, 0x08, 0x02, 0x04
	.4byte 0x0857AFD4
	.byte 0x03, 0x00, 0x02, 0x00
	.4byte 0x0857AFD4

sLineLayouts_Tall: @ 0x857B040
	.byte 0x02, 0x10, 0x00, 0x00
	.byte 0x02, 0x10, 0x00, 0x00
	.byte 0x02, 0x10, 0x00, 0x00
	.byte 0x02, 0x10, 0x00, 0x00
	.byte 0x01, 0x10, 0x00, 0x00

	.globl sMailLayouts_Tall
sMailLayouts_Tall: @ 0x857B054
	.byte 0x05, 0x00, 0x02, 0x00
	.4byte 0x0857B040
	.byte 0x05, 0x00, 0x02, 0x00
	.4byte 0x0857B040
	.byte 0x05, 0x80, 0x02, 0x00
	.4byte 0x0857B040
	.byte 0x05, 0x00, 0x02, 0x00
	.4byte 0x0857B040
	.byte 0x05, 0x00, 0x02, 0x00
	.4byte 0x0857B040
	.byte 0x05, 0x80, 0x02, 0x00
	.4byte 0x0857B040
	.byte 0x05, 0x80, 0x02, 0x00
	.4byte 0x0857B040
	.byte 0x05, 0x00, 0x02, 0x00
	.4byte 0x0857B040
	.byte 0x05, 0x00, 0x02, 0x00
	.4byte 0x0857B040
	.byte 0x05, 0x00, 0x02, 0x00
	.4byte 0x0857B040
	.byte 0x05, 0x08, 0x02, 0x00
	.4byte 0x0857B040
	.byte 0x05, 0x00, 0x02, 0x00
	.4byte 0x0857B040

	.globl sMailFromText
sMailFromText: @ 0x857B0B4
	.incbin "baserom_jp.gba", 0x57b0b4, 0x30

	.globl gUnknown_857B0E4
gUnknown_857B0E4: @ 0x857B0E4
	.incbin "baserom_jp.gba", 0x57b0e4, 0x8

	.globl gUnknown_857B0EC
gUnknown_857B0EC: @ 0x857B0EC
	.incbin "baserom_jp.gba", 0x57b0ec, 0x8

	.globl gUnknown_857B0F4
gUnknown_857B0F4: @ 0x857B0F4
	.incbin "baserom_jp.gba", 0x57b0f4, 0x10

	.globl sHealLocations
sHealLocations: @ 0x857B104
	.4byte gDummySpriteAffineAnimTable, 0x08007141

	.globl gUnknown_857B10C
gUnknown_857B10C: @ 0x857B10C
	.incbin "baserom_jp.gba", 0x57b10c, 0xd0

	.globl gUnknown_857B1DC
gUnknown_857B1DC: @ 0x857B1DC
	.incbin "baserom_jp.gba", 0x57b1dc, 0x44

	.globl gUnknown_857B220
gUnknown_857B220: @ 0x857B220
	.incbin "baserom_jp.gba", 0x57b220, 0xec

	.globl gUnknown_857B30C
gUnknown_857B30C: @ 0x857B30C
	.incbin "baserom_jp.gba", 0x57b30c, 0x40

	.globl gUnknown_857B34C
gUnknown_857B34C: @ 0x857B34C
	.incbin "baserom_jp.gba", 0x57b34c, 0xd64

	.globl gUnknown_857C0B0
gUnknown_857C0B0: @ 0x857C0B0
	.incbin "baserom_jp.gba", 0x57c0b0, 0x34c

	.globl gUnknown_857C3FC
gUnknown_857C3FC: @ 0x857C3FC
	.incbin "baserom_jp.gba", 0x57c3fc, 0x20

	.globl gUnknown_857C41C
gUnknown_857C41C: @ 0x857C41C
	.incbin "baserom_jp.gba", 0x57c41c, 0x80

	.globl gUnknown_857C49C
gUnknown_857C49C: @ 0x857C49C
	.incbin "baserom_jp.gba", 0x57c49c, 0x20

	.globl gUnknown_857C4BC
gUnknown_857C4BC: @ 0x857C4BC
	.incbin "baserom_jp.gba", 0x57c4bc, 0x80

	.globl gUnknown_857C53C
gUnknown_857C53C: @ 0x857C53C
	.incbin "baserom_jp.gba", 0x57c53c, 0x830

	.globl gUnknown_857CD6C
gUnknown_857CD6C: @ 0x857CD6C
	.incbin "baserom_jp.gba", 0x57cd6c, 0x6a8

	.section .rodata.857D49C
	.globl gUnknown_857D49C
gUnknown_857D49C: @ 0x857D49C
	.incbin "baserom_jp.gba", 0x57d49c, 0x20

	.globl gUnknown_857D4BC
gUnknown_857D4BC: @ 0x857D4BC
	.incbin "baserom_jp.gba", 0x57d4bc, 0x34

	.globl gUnknown_857D4F0
gUnknown_857D4F0: @ 0x857D4F0
	.incbin "baserom_jp.gba", 0x57d4f0, 0x8

	.globl gUnknown_857D4F8
gUnknown_857D4F8: @ 0x857D4F8
	.incbin "baserom_jp.gba", 0x57d4f8, 0x18

	.globl gUnknown_857D510
gUnknown_857D510: @ 0x857D510
	.incbin "baserom_jp.gba", 0x57d510, 0x10

	.globl gUnknown_857D520
gUnknown_857D520: @ 0x857D520
	.incbin "baserom_jp.gba", 0x57d520, 0x4

	.globl gUnknown_857D524
gUnknown_857D524: @ 0x857D524
	.incbin "baserom_jp.gba", 0x57d524, 0x4

	.globl gUnknown_857D528
gUnknown_857D528: @ 0x857D528
	.incbin "baserom_jp.gba", 0x57d528, 0x20

	.globl gUnknown_857D548
gUnknown_857D548: @ 0x857D548
	.incbin "baserom_jp.gba", 0x57d548, 0x38

	.globl gUnknown_857D580
gUnknown_857D580: @ 0x857D580
	.incbin "baserom_jp.gba", 0x57d580, 0xd8

	.globl gUnknown_857D658
gUnknown_857D658: @ 0x857D658
	.incbin "baserom_jp.gba", 0x57d658, 0xd4

	.globl gUnknown_857D72C
gUnknown_857D72C: @ 0x857D72C
	.incbin "baserom_jp.gba", 0x57d72c, 0xa0

	.globl gUnknown_857D7CC
gUnknown_857D7CC: @ 0x857D7CC
	.incbin "baserom_jp.gba", 0x57d7cc, 0x8

	.globl gUnknown_857D7D4
gUnknown_857D7D4: @ 0x857D7D4
	.incbin "baserom_jp.gba", 0x57d7d4, 0xc

	.globl gUnknown_857D7E0
gUnknown_857D7E0: @ 0x857D7E0
	.incbin "baserom_jp.gba", 0x57d7e0, 0x20

	.globl gUnknown_857D800
gUnknown_857D800: @ 0x857D800
	.incbin "baserom_jp.gba", 0x57d800, 0x8

	.globl gUnknown_857D808
gUnknown_857D808: @ 0x857D808
	.incbin "baserom_jp.gba", 0x57d808, 0x64

	.globl gUnknown_857D86C
gUnknown_857D86C: @ 0x857D86C
	.incbin "baserom_jp.gba", 0x57d86c, 0x18

	.globl gUnknown_857D884
gUnknown_857D884: @ 0x857D884
	.incbin "baserom_jp.gba", 0x57d884, 0x344c
	.globl gDecorations
gDecorations: @ 0x8580CD0
	.incbin "baserom_jp.gba", 0x580cd0, 0x1

	.globl gUnknown_8580CD1
gUnknown_8580CD1: @ 0x8580CD1
	.incbin "baserom_jp.gba", 0x580cd1, 0x17

	.globl gUnknown_8580CE8
gUnknown_8580CE8: @ 0x8580CE8
	.incbin "baserom_jp.gba", 0x580ce8, 0xd24

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

	.globl gUnknown_85843A8
gUnknown_85843A8: @ 0x85843A8
	.incbin "baserom_jp.gba", 0x5843a8, 0x10

	.globl gUnknown_85843B8
gUnknown_85843B8: @ 0x85843B8
	.incbin "baserom_jp.gba", 0x5843b8, 0x10

	.section .rodata.8584598
	.globl gUnknown_8584598
gUnknown_8584598: @ 0x8584598
	.incbin "baserom_jp.gba", 0x584598, 0x2

	.globl gUnknown_858459A
gUnknown_858459A: @ 0x858459A
	.incbin "baserom_jp.gba", 0x58459a, 0x8

	.globl gUnknown_85845A2
gUnknown_85845A2: @ 0x85845A2
	.incbin "baserom_jp.gba", 0x5845a2, 0x8

	.globl gUnknown_85845AA
gUnknown_85845AA: @ 0x85845AA
	.incbin "baserom_jp.gba", 0x5845aa, 0x8

	.globl gUnknown_85845B2
gUnknown_85845B2: @ 0x85845B2
	.incbin "baserom_jp.gba", 0x5845b2, 0x10
