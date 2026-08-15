	.section .rodata
	.globl gGameVersion
gGameVersion: @ 0x829BDA4
	.incbin "baserom_jp.gba", 0x29bda4, 0x1

	.globl gGameLanguage
gGameLanguage: @ 0x829BDA5
	.incbin "baserom_jp.gba", 0x29bda5, 0x17

	.globl gIntrTableTemplate
gIntrTableTemplate: @ 0x829BDBC
	.incbin "baserom_jp.gba", 0x29bdbc, 0x38

	.globl sMallocAssertFile
sMallocAssertFile: @ 0x829BDF4
	.incbin "baserom_jp.gba", 0x29bdf4, 0x14

	.globl sMallocAssertAlloc
sMallocAssertAlloc: @ 0x829BE08
	.incbin "baserom_jp.gba", 0x29be08, 0x4

	.globl sMallocAssertPNull
sMallocAssertPNull: @ 0x829BE0C
	.incbin "baserom_jp.gba", 0x29be0c, 0xc

	.globl sMallocAssertMagic
sMallocAssertMagic: @ 0x829BE18
	.incbin "baserom_jp.gba", 0x29be18, 0x28

	.globl sMallocAssertFlag
sMallocAssertFlag: @ 0x829BE40
	.incbin "baserom_jp.gba", 0x29be40, 0x14

	.globl sMallocAssertNextMagic
sMallocAssertNextMagic: @ 0x829BE54
	.incbin "baserom_jp.gba", 0x29be54, 0x2c

	.globl sMallocAssertPrevMagic
sMallocAssertPrevMagic: @ 0x829BE80
	.incbin "baserom_jp.gba", 0x29be80, 0x2c

	.globl gUnknown_829BEAC
gUnknown_829BEAC: @ 0x829BEAC
	.incbin "baserom_jp.gba", 0x29beac, 0x4

	.globl gUnknown_829BEB0
gUnknown_829BEB0: @ 0x829BEB0
	.incbin "baserom_jp.gba", 0x29beb0, 0x8

	.globl sGlyphPaletteIdxTable
sGlyphPaletteIdxTable: @ 0x829BEB8
	.incbin "baserom_jp.gba", 0x29beb8, 0x100

	.globl sDownArrowTiles
sDownArrowTiles: @ 0x829BFB8
	.incbin "baserom_jp.gba", 0x29bfb8, 0xc0

	.globl sDarkDownArrowTiles
sDarkDownArrowTiles: @ 0x829C078
	.incbin "baserom_jp.gba", 0x29c078, 0x5c0

	.globl sDownArrowYCoords
sDownArrowYCoords: @ 0x829C638
	.incbin "baserom_jp.gba", 0x29c638, 0x4

	.globl sWindowVerticalScrollSpeeds
sWindowVerticalScrollSpeeds: @ 0x829C63C
	.incbin "baserom_jp.gba", 0x29c63c, 0x4

	.globl sGlyphWidthFuncs
sGlyphWidthFuncs: @ 0x829C640
	.incbin "baserom_jp.gba", 0x29c640, 0x30

	.globl sKeypadIcons
sKeypadIcons: @ 0x829C670
	.incbin "baserom_jp.gba", 0x29c670, 0x34

	.globl sKeypadIconTiles
sKeypadIconTiles: @ 0x829C6A4
	.incbin "baserom_jp.gba", 0x29c6a4, 0x800

	.globl sFontInfos
sFontInfos: @ 0x829CEA4
	.incbin "baserom_jp.gba", 0x29cea4, 0x60

	.globl sMenuCursorDimensions
sMenuCursorDimensions: @ 0x829CF04
	.incbin "baserom_jp.gba", 0x29cf04, 0x10

	.globl sFontGlyphData_9CF14
sFontGlyphData_9CF14: @ 0x829CF14
	.incbin "baserom_jp.gba", 0x29cf14, 0x4000

	.globl sFontGlyphData_A0F14
sFontGlyphData_A0F14: @ 0x82A0F14
	.incbin "baserom_jp.gba", 0x2a0f14, 0x4000

	.globl sFontGlyphData_A4F14
sFontGlyphData_A4F14: @ 0x82A4F14
	.incbin "baserom_jp.gba", 0x2a4f14, 0x8000

	.globl sGlyphWidthTable_ACF14
sGlyphWidthTable_ACF14: @ 0x82ACF14
	.incbin "baserom_jp.gba", 0x2acf14, 0x118

	.globl sFontGlyphData_AD02C
sFontGlyphData_AD02C: @ 0x82AD02C
	.incbin "baserom_jp.gba", 0x2ad02c, 0x8000

	.globl sGlyphWidthTable_B502C
sGlyphWidthTable_B502C: @ 0x82B502C
	.incbin "baserom_jp.gba", 0x2b502c, 0x118

	.globl sFontGlyphData_B5144
sFontGlyphData_B5144: @ 0x82B5144
	.incbin "baserom_jp.gba", 0x2b5144, 0x8000

	.globl sGlyphWidthTable_BD144
sGlyphWidthTable_BD144: @ 0x82BD144
	.incbin "baserom_jp.gba", 0x2bd144, 0x118

	.globl sFontGlyphData_BD25C
sFontGlyphData_BD25C: @ 0x82BD25C
	.incbin "baserom_jp.gba", 0x2bd25c, 0x203d

	.globl sCenterToCornerVecTable
sCenterToCornerVecTable: @ 0x82BF299
	.incbin "baserom_jp.gba", 0x2bf299, 0x1b

	.globl gUnknown_82BF2B4
gUnknown_82BF2B4: @ 0x82BF2B4
	.string "ッ　ぃあ　し　　えÜろく　　　　たÜろくとÜろく　　　　だム　くぃあッ　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　$"
	.globl gDummyOamData
gDummyOamData: @ 0x82BF2F8
	.incbin "baserom_jp.gba", 0x2bf2f8, 0xc

	.globl gUnknown_82BF304
gUnknown_82BF304: @ 0x82BF304
	.incbin "baserom_jp.gba", 0x2bf304, 0xc

	.globl gDummySpriteAffineAnimTable
gDummySpriteAffineAnimTable: @ 0x82BF310
	.incbin "baserom_jp.gba", 0x2bf310, 0x4

	.globl gDummySpriteTemplate
gDummySpriteTemplate: @ 0x82BF314
	.incbin "baserom_jp.gba", 0x2bf314, 0x18

	.globl sAnimFuncs
sAnimFuncs: @ 0x82BF32C
	.incbin "baserom_jp.gba", 0x2bf32c, 0x8

	.globl sAffineAnimFuncs
sAffineAnimFuncs: @ 0x82BF334
	.incbin "baserom_jp.gba", 0x2bf334, 0x8

	.globl sAnimCmdFuncs
sAnimCmdFuncs: @ 0x82BF33C
	.incbin "baserom_jp.gba", 0x2bf33c, 0x10

	.globl sAffineAnimCmdFuncs
sAffineAnimCmdFuncs: @ 0x82BF34C
	.incbin "baserom_jp.gba", 0x2bf34c, 0x10

	.globl sOamDimensions32
sOamDimensions32: @ 0x82BF35C
	.incbin "baserom_jp.gba", 0x2bf35c, 0x60

	.globl sOamDimensions
sOamDimensions: @ 0x82BF3BC
	.incbin "baserom_jp.gba", 0x2bf3bc, 0x70

	.globl gUnknown_82BF42C
gUnknown_82BF42C: @ 0x82BF42C
	.incbin "baserom_jp.gba", 0x2bf42c, 0x8

	.globl gOrbEffectBackgroundLayerFlags
gOrbEffectBackgroundLayerFlags: @ 0x82BF434
	.incbin "baserom_jp.gba", 0x2bf434, 0x8

	.globl sDigits
sDigits: @ 0x82BF43C
	.incbin "baserom_jp.gba", 0x2bf43c, 0x10

	.globl sPowersOfTen
sPowersOfTen: @ 0x82BF44C
	.incbin "baserom_jp.gba", 0x2bf44c, 0x28

	.globl gUnknown_82BF474
gUnknown_82BF474: @ 0x82BF474
	.string "{FONT 6}$"
	.globl sBrailleGotoLine2
sBrailleGotoLine2: @ 0x82BF478
	.incbin "baserom_jp.gba", 0x2bf478, 0x8

	.globl sPlaceholderFuncs
sPlaceholderFuncs: @ 0x82BF480
	.incbin "baserom_jp.gba", 0x2bf480, 0x38

	.globl sWirelessLinkDisplayPal
sWirelessLinkDisplayPal: @ 0x82BF4B8
	.incbin "baserom_jp.gba", 0x2bf4b8, 0x20

	.globl sWirelessLinkDisplayGfx
sWirelessLinkDisplayGfx: @ 0x82BF4D8
	.incbin "baserom_jp.gba", 0x2bf4d8, 0x4a8

	.globl sWirelessLinkDisplayTilemap
sWirelessLinkDisplayTilemap: @ 0x82BF980
	.incbin "baserom_jp.gba", 0x2bf980, 0x1ec

	.globl sLinkTestDigitsPal
sLinkTestDigitsPal: @ 0x82BFB6C
	.incbin "baserom_jp.gba", 0x2bfb6c, 0x20

	.globl gUnknown_82BFB8C
gUnknown_82BFB8C: @ 0x82BFB8C
	.string "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　l　　　\n"
	.string "せ　l▶▶　\n"
	.string "せ\n"
	.string "せ\n"
	.string "せ\n"
	.string "せl▶▶　　\n"
	.string "せ　　l　　　　せ　　l▶　　l▶　　l▶　　l▶　　l▶　　l▶　　　せ　lzz　\n"
	.string "$$せlz\n"
	.string "せ　l▶　　\n"
	.string "せ　l▶z　\n"
	.string "$$せlzz　lzz　\n"
	.string "$$せlz\n"
	.string "せ　\n"
	.string "$せ　z\n"
	.string "せlz\n"
	.string "せ\n"
	.string "$$せlzz　l　せ　\n"
	.string "z▶　\n"
	.string "z▶　\n"
	.string "z▶　\n"
	.string "$$せlz▶　　l▶　　　せ　lzz　\n"
	.string "$$せ\n"
	.string "zz　\n"
	.string "$$せlz\n"
	.string "せlz\n"
	.string "せ\n"
	.string "$$せlzz　l　　　\n"
	.string "せ　　\n"
	.string "zz　\n"
	.string "$$せ\n"
	.string "z\n"
	.string "せ\n"
	.string "z\n"
	.string "せ\n"
	.string "$$せlzz　lzz　\n"
	.string "$$せ\n"
	.string "z\n"
	.string "せ\n"
	.string "せ\n"
	.string "せl　\n"
	.string "せ　　\n"
	.string "せ　　\n"
	.string "せ　　l　lzz　\n"
	.string "$$せ\n"
	.string "z\n"
	.string "せ\n"
	.string "$$せ\n"
	.string "z\n"
	.string "せ\n"
	.string "z\n"
	.string "せ\n"
	.string "$$せlzz　lzz　\n"
	.string "$$せ\n"
	.string "z\n"
	.string "せ\n"
	.string "z\n"
	.string "せ\n"
	.string "$$せlz\n"
	.string "せ　　\n"
	.string "せ　　z　lzz　\n"
	.string "$$せ\n"
	.string "z\n"
	.string "せ\n"
	.string "$$せ\n"
	.string "z\n"
	.string "せ\n"
	.string "せ\n"
	.string "せ\n"
	.string "せ\n"
	.string "せlせz　lz　　\n"
	.string "$せ　\n"
	.string "\n"
	.string "z　\n"
	.string "$$せ\n"
	.string "z\n"
	.string "せ\n"
	.string "z\n"
	.string "せ\n"
	.string "$$せlzz　lzz　\n"
	.string "$$せ\n"
	.string "zz　\n"
	.string "せ　　\n"
	.string "せ　　\n"
	.string "zz　\n"
	.string "$$せlzz　lz　　\n"
	.string "$せ　\n"
	.string "z▶　\n"
	.string "せ\n"
	.string "せ\n"
	.string "せ\n"
	.string "せ\n"
	.string "z▶　\n"
	.string "$せ　lz　　lzz　\n"
	.string "$$せ\n"
	.string "zz　\n"
	.string "$$せ\n"
	.string "zz　\n"
	.string "zz　\n"
	.string "$$せlzz　lzz　\n"
	.string "$$せ\n"
	.string "zz　\n"
	.string "$$せ\n"
	.string "zz　\n"
	.string "せ　　\n"
	.string "せ　　l　　　せつぞく　ちゅうです$　せつぞく　できません$　かくにん　ちゅうです$　かくにん　できました$　かくにん　できません$　かくにん　を　かくにん$かくにん　は　しっぱい$"
	.globl gUnknown_82BFE00
gUnknown_82BFE00: @ 0x82BFE00
	.string "　　つうしん　エラーが　はっせいしました\n"
	.string "　　　しゅうへんきき　との　せつぞくを\n"
	.string "　　　　きちんと　かくにん　してから\n"
	.string "　　　でんげんを　いれなおしてください$"
	.globl gUnknown_82BFE50
gUnknown_82BFE50: @ 0x82BFE50
	.string "つうしんエラーが　はっせいしました$"
	.globl gUnknown_82BFE62
gUnknown_82BFE62: @ 0x82BFE62
	.string "　つうしんあいてと　ちかづいて　ください\n"
	.string "しょうがいぶつが　ないように　してください$"
	.globl gUnknown_82BFE8D
gUnknown_82BFE8D: @ 0x82BFE8D
	.string "Aボタンで　うけつけに　もどります$"
	.globl gUnknown_82BFE9F
gUnknown_82BFE9F: @ 0x82BFE9F
	.string "Aボタンで　タイトルに　もどります${HIGHLIGHT 0}{COLOR 1}$"
	.globl sCommErrorBg_Gfx
sCommErrorBg_Gfx: @ 0x82BFEB8
	.incbin "baserom_jp.gba", 0x2bfeb8, 0x40
