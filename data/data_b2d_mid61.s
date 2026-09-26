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

	.section .rodata.data_b2d_mid61_between_mon_markings_and_mail_data

	.globl gUnknown_857AC08
gUnknown_857AC08: @ 0x857AC08
	.incbin "baserom_jp.gba", 0x57ac08, 0xc

	.globl sGiddyAdjectives
sGiddyAdjectives: @ 0x857AC14
	.4byte GiddyText_SoPretty, GiddyText_SoDarling, GiddyText_SoRelaxed, GiddyText_SoSunny
	.4byte GiddyText_SoDesirable, GiddyText_SoExciting, GiddyText_SoAmusing, GiddyText_SoMagical

	.globl sGiddyQuestions
sGiddyQuestions: @ 0x857AC34
	.4byte GiddyText_ISoWantToGoOnAVacation, GiddyText_IBoughtCrayonsWith120Colors
	.4byte GiddyText_WouldntItBeNiceIfWeCouldFloat, GiddyText_WhenYouWriteOnASandyBeach
	.4byte GiddyText_WhatsTheBottomOfTheSeaLike, GiddyText_WhenYouSeeTheSettingSunDoesIt
	.4byte GiddyText_LyingBackInTheGreenGrass, GiddyText_SecretBasesAreSoWonderful

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

	.section .rodata.data_b2d_mid61_after_swap_line

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
