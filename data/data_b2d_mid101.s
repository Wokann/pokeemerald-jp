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

	.globl gUnknown_85DFB60
gUnknown_85DFB60: @ 0x85DFB60
	.incbin "baserom_jp.gba", 0x5dfb60, 0x20

	.globl gUnknown_85DFB80
gUnknown_85DFB80: @ 0x85DFB80
	.incbin "baserom_jp.gba", 0x5dfb80, 0x70

	.globl gUnknown_85DFBF0
gUnknown_85DFBF0: @ 0x85DFBF0
	.incbin "baserom_jp.gba", 0x5dfbf0, 0x40

	.globl gUnknown_85DFC30
gUnknown_85DFC30: @ 0x85DFC30
	.incbin "baserom_jp.gba", 0x5dfc30, 0x44

	.globl sSaveLocationPokeCenterList
sSaveLocationPokeCenterList: @ 0x85DFC74
	.string "いいういあういうおえかええおおおえかおか　きあきえくおくさけしけおこかこおさかさいしうしかすきすうせえせいそうそしたすたこたせたゅはょはねのののはのひの$$"
	.globl sSaveLocationReloadLocList
sSaveLocationReloadLocList: @ 0x85DFCC2
	.string "おは$$"
	.globl sEmptyMapList
sEmptyMapList: @ 0x85DFCC6
	.hword 0xFFFF

	.globl gItemIconTable
gItemIconTable: @ 0x85DFCC8
	.incbin "baserom_jp.gba", 0x5dfcc8, 0xbd0

sOamData_ItemIcon: @ 0x85E0898
	.byte 0x00, 0x00, 0x00, 0x80, 0x00, 0x24, 0x00, 0x00

sSpriteAnim_ItemIcon: @ 0x85E08A0
	.hword 0x0000, 0x0000, 0xFFFF, 0x0000

sSpriteAnimTable_ItemIcon: @ 0x85E08A8
	.4byte sSpriteAnim_ItemIcon

	.globl gItemIconSpriteTemplate
gItemIconSpriteTemplate: @ 0x85E08AC
	.hword 0, 0
	.4byte sOamData_ItemIcon, sSpriteAnimTable_ItemIcon
	.4byte 0, gDummySpriteAffineAnimTable, 0x08007141

	.globl gUnknown_85E08C4
gUnknown_85E08C4: @ 0x85E08C4
	.incbin "baserom_jp.gba", 0x5e08c4, 0x3c
	.globl gTutorMoves
	.set gTutorMoves, gUnknown_85E08C4

	.globl sTutorLearnsets
sTutorLearnsets: @ 0x85E0900
	.incbin "baserom_jp.gba", 0x5e0900, 0x670

	.globl gUnknown_85E0F70
gUnknown_85E0F70: @ 0x85E0F70
	.incbin "baserom_jp.gba", 0x5e0f70, 0x2c

	.globl gUnknown_85E0F9C
gUnknown_85E0F9C: @ 0x85E0F9C
	.incbin "baserom_jp.gba", 0x5e0f9c, 0x20

	.globl gUnknown_85E0FBC
gUnknown_85E0FBC: @ 0x85E0FBC
	.incbin "baserom_jp.gba", 0x5e0fbc, 0xc0

	.globl sConfirmButton_Tilemap
sConfirmButton_Tilemap: @ 0x85E107C
	.incbin "baserom_jp.gba", 0x5e107c, 0x1c

	.globl sCancelButton_Tilemap
sCancelButton_Tilemap: @ 0x85E1098
	.incbin "baserom_jp.gba", 0x5e1098, 0x1c

	.globl sFontColorTable
sFontColorTable: @ 0x85E10B4
	.incbin "baserom_jp.gba", 0x5e10b4, 0x14

	.globl sSinglePartyMenuWindowTemplate
sSinglePartyMenuWindowTemplate: @ 0x85E10C8
	.incbin "baserom_jp.gba", 0x5e10c8, 0x40

	.globl sDoublePartyMenuWindowTemplate
sDoublePartyMenuWindowTemplate: @ 0x85E1108
	.incbin "baserom_jp.gba", 0x5e1108, 0x40

	.globl sMultiPartyMenuWindowTemplate
sMultiPartyMenuWindowTemplate: @ 0x85E1148
	.incbin "baserom_jp.gba", 0x5e1148, 0x40

	.globl sShowcaseMultiPartyMenuWindowTemplate
sShowcaseMultiPartyMenuWindowTemplate: @ 0x85E1188
	.incbin "baserom_jp.gba", 0x5e1188, 0x38

	.globl sCancelButtonWindowTemplate
sCancelButtonWindowTemplate: @ 0x85E11C0
	.incbin "baserom_jp.gba", 0x5e11c0, 0x8

	.globl sMultiCancelButtonWindowTemplate
sMultiCancelButtonWindowTemplate: @ 0x85E11C8
	.incbin "baserom_jp.gba", 0x5e11c8, 0x8

	.globl sConfirmButtonWindowTemplate
sConfirmButtonWindowTemplate: @ 0x85E11D0
	.incbin "baserom_jp.gba", 0x5e11d0, 0x8

	.globl sDefaultPartyMsgWindowTemplate
sDefaultPartyMsgWindowTemplate: @ 0x85E11D8
	.incbin "baserom_jp.gba", 0x5e11d8, 0x8

	.globl sDoWhatWithMonMsgWindowTemplate
sDoWhatWithMonMsgWindowTemplate: @ 0x85E11E0
	.incbin "baserom_jp.gba", 0x5e11e0, 0x8

	.globl sDoWhatWithItemMsgWindowTemplate
sDoWhatWithItemMsgWindowTemplate: @ 0x85E11E8
	.incbin "baserom_jp.gba", 0x5e11e8, 0x8

	.globl sDoWhatWithMailMsgWindowTemplate
sDoWhatWithMailMsgWindowTemplate: @ 0x85E11F0
	.incbin "baserom_jp.gba", 0x5e11f0, 0x8

	.globl sWhichMoveMsgWindowTemplate
sWhichMoveMsgWindowTemplate: @ 0x85E11F8
	.incbin "baserom_jp.gba", 0x5e11f8, 0x8

	.globl sAlreadyHoldingOneMsgWindowTemplate
sAlreadyHoldingOneMsgWindowTemplate: @ 0x85E1200
	.incbin "baserom_jp.gba", 0x5e1200, 0x8

	.globl sItemGiveTakeWindowTemplate
sItemGiveTakeWindowTemplate: @ 0x85E1208
	.incbin "baserom_jp.gba", 0x5e1208, 0x8

	.globl sMailReadTakeWindowTemplate
sMailReadTakeWindowTemplate: @ 0x85E1210
	.incbin "baserom_jp.gba", 0x5e1210, 0x8

	.globl sMoveSelectWindowTemplate
sMoveSelectWindowTemplate: @ 0x85E1218
	.incbin "baserom_jp.gba", 0x5e1218, 0x8

	.globl sPartyMenuYesNoWindowTemplate
sPartyMenuYesNoWindowTemplate: @ 0x85E1220
	.incbin "baserom_jp.gba", 0x5e1220, 0x8

	.globl sLevelUpStatsWindowTemplate
sLevelUpStatsWindowTemplate: @ 0x85E1228
	.incbin "baserom_jp.gba", 0x5e1228, 0x18

	.globl sSlotTilemap_Main
sSlotTilemap_Main: @ 0x85E1240
	.incbin "baserom_jp.gba", 0x5e1240, 0x46

	.globl sSlotTilemap_MainNoHP
sSlotTilemap_MainNoHP: @ 0x85E1286
	.incbin "baserom_jp.gba", 0x5e1286, 0x46

	.globl sSlotTilemap_Wide
sSlotTilemap_Wide: @ 0x85E12CC
	.incbin "baserom_jp.gba", 0x5e12cc, 0x36

	.globl sSlotTilemap_WideNoHP
sSlotTilemap_WideNoHP: @ 0x85E1302
	.incbin "baserom_jp.gba", 0x5e1302, 0x36

	.globl sSlotTilemap_WideEmpty
sSlotTilemap_WideEmpty: @ 0x85E1338
	.incbin "baserom_jp.gba", 0x5e1338, 0x36

	.globl sGenderPalOffsets
sGenderPalOffsets: @ 0x85E136E
	.incbin "baserom_jp.gba", 0x5e136e, 0x2

	.globl sHPBarPalOffsets
sHPBarPalOffsets: @ 0x85E1370
	.incbin "baserom_jp.gba", 0x5e1370, 0x2

	.globl sPartyBoxPalOffsets1
sPartyBoxPalOffsets1: @ 0x85E1372
	.incbin "baserom_jp.gba", 0x5e1372, 0x3

	.globl sPartyBoxPalOffsets2
sPartyBoxPalOffsets2: @ 0x85E1375
	.incbin "baserom_jp.gba", 0x5e1375, 0x3

	.globl sPartyBoxNoMonPalOffsets
sPartyBoxNoMonPalOffsets: @ 0x85E1378
	.incbin "baserom_jp.gba", 0x5e1378, 0x3

	.globl sGenderMalePalIds
sGenderMalePalIds: @ 0x85E137B
	.incbin "baserom_jp.gba", 0x5e137b, 0x2

	.globl sGenderFemalePalIds
sGenderFemalePalIds: @ 0x85E137D
	.incbin "baserom_jp.gba", 0x5e137d, 0x2

	.globl sHPBarGreenPalIds
sHPBarGreenPalIds: @ 0x85E137F
	.incbin "baserom_jp.gba", 0x5e137f, 0x2

	.globl sHPBarYellowPalIds
sHPBarYellowPalIds: @ 0x85E1381
	.incbin "baserom_jp.gba", 0x5e1381, 0x2

	.globl sHPBarRedPalIds
sHPBarRedPalIds: @ 0x85E1383
	.incbin "baserom_jp.gba", 0x5e1383, 0x2

	.globl sPartyBoxEmptySlotPalIds1
sPartyBoxEmptySlotPalIds1: @ 0x85E1385
	.incbin "baserom_jp.gba", 0x5e1385, 0x3

	.globl sPartyBoxMultiPalIds1
sPartyBoxMultiPalIds1: @ 0x85E1388
	.incbin "baserom_jp.gba", 0x5e1388, 0x3

	.globl sPartyBoxFaintedPalIds1
sPartyBoxFaintedPalIds1: @ 0x85E138B
	.incbin "baserom_jp.gba", 0x5e138b, 0x3

	.globl sPartyBoxCurrSelectionPalIds1
sPartyBoxCurrSelectionPalIds1: @ 0x85E138E
	.incbin "baserom_jp.gba", 0x5e138e, 0x3

	.globl sPartyBoxCurrSelectionMultiPalIds
sPartyBoxCurrSelectionMultiPalIds: @ 0x85E1391
	.incbin "baserom_jp.gba", 0x5e1391, 0x3

	.globl sPartyBoxCurrSelectionFaintedPalIds
sPartyBoxCurrSelectionFaintedPalIds: @ 0x85E1394
	.incbin "baserom_jp.gba", 0x5e1394, 0x3

	.globl sPartyBoxSelectedForActionPalIds1
sPartyBoxSelectedForActionPalIds1: @ 0x85E1397
	.incbin "baserom_jp.gba", 0x5e1397, 0x3

	.globl sPartyBoxEmptySlotPalIds2
sPartyBoxEmptySlotPalIds2: @ 0x85E139A
	.incbin "baserom_jp.gba", 0x5e139a, 0x3

	.globl sPartyBoxMultiPalIds2
sPartyBoxMultiPalIds2: @ 0x85E139D
	.incbin "baserom_jp.gba", 0x5e139d, 0x3

	.globl sPartyBoxFaintedPalIds2
sPartyBoxFaintedPalIds2: @ 0x85E13A0
	.incbin "baserom_jp.gba", 0x5e13a0, 0x3

	.globl sPartyBoxCurrSelectionPalIds2
sPartyBoxCurrSelectionPalIds2: @ 0x85E13A3
	.incbin "baserom_jp.gba", 0x5e13a3, 0x3

	.globl sPartyBoxSelectedForActionPalIds2
sPartyBoxSelectedForActionPalIds2: @ 0x85E13A6
	.incbin "baserom_jp.gba", 0x5e13a6, 0x3

	.globl sPartyBoxNoMonPalIds
sPartyBoxNoMonPalIds: @ 0x85E13A9
	.incbin "baserom_jp.gba", 0x5e13a9, 0x3

	.globl sActionStringTable
sActionStringTable: @ 0x85E13AC
	.incbin "baserom_jp.gba", 0x5e13ac, 0x6c

	.globl sDescriptionStringTable
sDescriptionStringTable: @ 0x85E1418
	.incbin "baserom_jp.gba", 0x5e1418, 0xa8

	.globl sCursorOptions
sCursorOptions: @ 0x85E14C0
	.incbin "baserom_jp.gba", 0x5e14c0, 0x130

	.globl sPartyMenuActions
sPartyMenuActions: @ 0x85E15F0
	.incbin "baserom_jp.gba", 0x5e15f0, 0x38

	.globl sPartyMenuActionCounts
sPartyMenuActionCounts: @ 0x85E1628
	.incbin "baserom_jp.gba", 0x5e1628, 0xe

	.globl sFieldMoves
sFieldMoves: @ 0x85E1636
	.incbin "baserom_jp.gba", 0x5e1636, 0x1e

	.globl sFieldMoveCursorCallbacks
sFieldMoveCursorCallbacks: @ 0x85E1654
	.incbin "baserom_jp.gba", 0x5e1654, 0x70

	.globl sUnionRoomTradeMessages
sUnionRoomTradeMessages: @ 0x85E16C4
	.incbin "baserom_jp.gba", 0x5e16c4, 0xa4

	.globl sSpriteSheet_HeldItem
sSpriteSheet_HeldItem: @ 0x85E1768
	.incbin "baserom_jp.gba", 0x5e1768, 0x8

	.globl sSpritePalette_HeldItem
sSpritePalette_HeldItem: @ 0x85E1770
	.incbin "baserom_jp.gba", 0x5e1770, 0x8

	.globl sSpriteTemplate_HeldItem
sSpriteTemplate_HeldItem: @ 0x85E1778
	.incbin "baserom_jp.gba", 0x5e1778, 0x38

	.globl sSpriteSheet_MenuPokeball
sSpriteSheet_MenuPokeball: @ 0x85E17B0
	.incbin "baserom_jp.gba", 0x5e17b0, 0x8

	.globl sSpritePalette_MenuPokeball
sSpritePalette_MenuPokeball: @ 0x85E17B8
	.incbin "baserom_jp.gba", 0x5e17b8, 0x8

	.globl sSpriteTemplate_MenuPokeball
sSpriteTemplate_MenuPokeball: @ 0x85E17C0
	.incbin "baserom_jp.gba", 0x5e17c0, 0x68

	.globl sSpriteSheet_MenuPokeballSmall
sSpriteSheet_MenuPokeballSmall: @ 0x85E1828
	.incbin "baserom_jp.gba", 0x5e1828, 0x8

	.globl sSpriteTemplate_MenuPokeballSmall
sSpriteTemplate_MenuPokeballSmall: @ 0x85E1830
	.incbin "baserom_jp.gba", 0x5e1830, 0x80

	.globl sSpriteSheet_StatusIcons
sSpriteSheet_StatusIcons: @ 0x85E18B0
	.incbin "baserom_jp.gba", 0x5e18b0, 0x8

	.globl sSpritePalette_StatusIcons
sSpritePalette_StatusIcons: @ 0x85E18B8
	.incbin "baserom_jp.gba", 0x5e18b8, 0x8

	.globl sSpriteTemplate_StatusIcons
sSpriteTemplate_StatusIcons: @ 0x85E18C0
	.incbin "baserom_jp.gba", 0x5e18c0, 0x18

	.globl sMultiBattlePartnersPartyMask
sMultiBattlePartnersPartyMask: @ 0x85E18D8
	.incbin "baserom_jp.gba", 0x5e18d8, 0x20

	.globl gUnknown_85E18F8
gUnknown_85E18F8: @ 0x85E18F8
	.incbin "baserom_jp.gba", 0x5e18f8, 0x74
	.globl sTMHMMoves
	.set sTMHMMoves, gUnknown_85E18F8

	.globl sVerdanturfTentFuncs
sVerdanturfTentFuncs: @ 0x85E196C
	.4byte 0x081B9675, 0x081B96C9, 0x081B96E5, 0x081B9701
	.4byte 0x081B9731, 0x081B975D, 0x081B97A1, 0x081B97C9

	.globl sVerdanturfTentRewards
sVerdanturfTentRewards: @ 0x85E198C
	.hword 0x0008, 0x0000

	.globl sFallarborTentFuncs
sFallarborTentFuncs: @ 0x85E1990
	.4byte 0x081B9841, 0x081B9895, 0x081B98B1, 0x081B98CD
	.4byte 0x081B9911, 0x081B9939, 0x081B9991

	.globl sFallarborTentRewards
sFallarborTentRewards: @ 0x85E19AC
	.hword 0x0015, 0x0000

	.globl sSlateportTentFuncs
sSlateportTentFuncs: @ 0x85E19B0
	.incbin "baserom_jp.gba", 0x5e19b0, 0x28

	.globl sSlateportTentRewards
sSlateportTentRewards: @ 0x85E19D8
	.hword 0x0017, 0x0000

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
