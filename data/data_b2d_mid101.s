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


	.section .rodata.mid101_after_item_menu




	.globl sScrollDistances
sScrollDistances: @ 0x85E19DC
	.byte 0x01, 0x02, 0x04, 0x00

	.globl sFont_Braille
sFont_Braille: @ 0x85E19E0
	.incbin "graphics/fonts/braille.bin"

	.globl gUnknown_85E72E4
gUnknown_85E72E4: @ 0x85E72E4
	.incbin "baserom_jp.gba", 0x5e72e4, 0x48

	.globl gUnknown_85E732C
gUnknown_85E732C: @ 0x85E732C
	.incbin "baserom_jp.gba", 0x5e732c, 0x104

	.globl sMirageTower_Gfx
sMirageTower_Gfx: @ 0x85E7430
	.incbin "graphics/mirage_tower/sMirageTower_Gfx.bin"

	.globl sMirageTowerTilemap
sMirageTowerTilemap: @ 0x85E7D50
	.incbin "graphics/mirage_tower/sMirageTowerTilemap.bin"

	.globl sFossil_Gfx
sFossil_Gfx: @ 0x85E7E00
	.incbin "graphics/mirage_tower/sFossil_Gfx.bin"

	.globl sMirageTowerCrumbles_Gfx
sMirageTowerCrumbles_Gfx: @ 0x85E7E80
	.incbin "graphics/mirage_tower/sMirageTowerCrumbles_Gfx.bin"

	.globl gUnknown_85E7F00
gUnknown_85E7F00: @ 0x85E7F00
	.incbin "baserom_jp.gba", 0x5e7f00, 0x20


	.globl sCeilingCrumblePositions
sCeilingCrumblePositions: @ 0x85E7F20
	.hword 0x0000, 0x000A, 0x0041, 0x0011, 0x0003, 0x0032, 0xFFF4, 0x0000, 0x004B, 0x000A, 0x000F, 0x005A
	.hword 0x0007, 0x0008, 0x0041, 0xFFEE, 0x0005, 0x004B, 0x0016, 0xFFF6, 0x0037, 0xFFE8, 0xFFFC, 0x0041

	.globl sCeilingCrumbleSpriteSheets
sCeilingCrumbleSpriteSheets: @ 0x85E7F50
	.4byte 0x085E7E80
	.hword 0x0080, 0x0FA0
	.4byte 0
	.hword 0, 0

	.globl sInvisibleMirageTowerMetatiles
sInvisibleMirageTowerMetatiles: @ 0x85E7F60
	.byte 0x12, 0x35, 0x51, 0x02, 0x13, 0x35, 0x51, 0x02, 0x14, 0x35, 0x51, 0x02
	.byte 0x12, 0x36, 0x51, 0x02, 0x13, 0x36, 0x51, 0x02, 0x14, 0x36, 0x51, 0x02
	.byte 0x12, 0x37, 0x51, 0x02, 0x13, 0x37, 0x51, 0x02, 0x14, 0x37, 0x51, 0x02
	.byte 0x12, 0x38, 0x51, 0x02, 0x13, 0x38, 0x51, 0x02, 0x14, 0x38, 0x51, 0x02
	.byte 0x12, 0x39, 0x59, 0x02, 0x13, 0x39, 0x59, 0x02, 0x14, 0x39, 0x59, 0x02
	.byte 0x12, 0x3A, 0x21, 0x01, 0x13, 0x3A, 0x21, 0x01, 0x14, 0x3A, 0x21, 0x01

sSpriteAnim_FallingFossil: @ 0x85E7FA8
	.hword 0x0000, 0x0001, 0xFFFF, 0x0000

sOamData_FallingFossil: @ 0x85E7FB0
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0x30, 0x00, 0x00

sSpriteAnimTable_FallingFossil: @ 0x85E7FB8
	.4byte sSpriteAnim_FallingFossil

	.globl sSpriteTemplate_FallingFossil
sSpriteTemplate_FallingFossil: @ 0x85E7FBC
	.hword 0xFFFF, 0xFFFF
	.4byte sOamData_FallingFossil, sSpriteAnimTable_FallingFossil
	.4byte 0, gDummySpriteAffineAnimTable, 0x08007141

	.globl gMirageTowerPulseBlendSettings
gMirageTowerPulseBlendSettings: @ 0x85E7FD4
	.hword 0x433B, 0x0061
	.byte 0x0F, 0x05, 0xFF, 0x9B

sAnim_CeilingCrumbleSmall: @ 0x85E7FDC
	.hword 0x0000, 0x000C, 0xFFFE, 0x0000

sAnims_CeilingCrumbleSmall: @ 0x85E7FE4
	.4byte sAnim_CeilingCrumbleSmall

sOamData_CeilingCrumbleSmall: @ 0x85E7FE8
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.globl sSpriteTemplate_CeilingCrumbleSmall
sSpriteTemplate_CeilingCrumbleSmall: @ 0x85E7FF0
	.hword 0x0FA0, 0xFFFF
	.4byte sOamData_CeilingCrumbleSmall, sAnims_CeilingCrumbleSmall
	.globl gUnknown_85E7FFC
gUnknown_85E7FFC: @ 0x85E7FFC
	.4byte 0, gDummySpriteAffineAnimTable, 0x081BE775

sAnim_CeilingCrumbleLarge: @ 0x85E8008
	.hword 0x0000, 0x000C, 0xFFFE, 0x0000

sAnims_CeilingCrumbleLarge: @ 0x85E8010
	.4byte sAnim_CeilingCrumbleLarge

sOamData_CeilingCrumbleLarge: @ 0x85E8014
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00

	.globl sSpriteTemplate_CeilingCrumbleLarge
sSpriteTemplate_CeilingCrumbleLarge: @ 0x85E801C
	.hword 0x0FA0, 0xFFFF
	.4byte sOamData_CeilingCrumbleLarge, sAnims_CeilingCrumbleLarge
	.4byte 0, gDummySpriteAffineAnimTable, 0x081BE775

	.globl gUnknown_85E8034
gUnknown_85E8034: @ 0x85E8034
	.incbin "baserom_jp.gba", 0x5e8034, 0x4d70
