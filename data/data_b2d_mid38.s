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

	.globl gUnknown_8588651
gUnknown_8588651: @ 0x8588651
	.incbin "baserom_jp.gba", 0x588651, 0x5b

	.globl gUnknown_85886AC
gUnknown_85886AC: @ 0x85886AC
	.incbin "baserom_jp.gba", 0x5886ac, 0x200

	.globl gUnknown_85888AC
gUnknown_85888AC: @ 0x85888AC
	.incbin "baserom_jp.gba", 0x5888ac, 0x1084

	.globl gUnknown_8589930
gUnknown_8589930: @ 0x8589930
	.incbin "baserom_jp.gba", 0x589930, 0xc30

	.globl gUnknown_858A560
gUnknown_858A560: @ 0x858A560
	.incbin "baserom_jp.gba", 0x58a560, 0xb38

	.globl gUnknown_858B098
gUnknown_858B098: @ 0x858B098
	.incbin "baserom_jp.gba", 0x58b098, 0xfb8

	.globl gUnknown_858C050
gUnknown_858C050: @ 0x858C050
	.incbin "baserom_jp.gba", 0x58c050, 0x1130

	.globl gUnknown_858D180
gUnknown_858D180: @ 0x858D180
	.incbin "baserom_jp.gba", 0x58d180, 0x604

	.globl gUnknown_858D784
gUnknown_858D784: @ 0x858D784
	.incbin "baserom_jp.gba", 0x58d784, 0x50c

	.globl gUnknown_858DC90
gUnknown_858DC90: @ 0x858DC90
	.incbin "baserom_jp.gba", 0x58dc90, 0x50c

	.globl gUnknown_858E19C
gUnknown_858E19C: @ 0x858E19C
	.incbin "baserom_jp.gba", 0x58e19c, 0x50c

	.globl gUnknown_858E6A8
gUnknown_858E6A8: @ 0x858E6A8
	.incbin "baserom_jp.gba", 0x58e6a8, 0x50c

	.globl gUnknown_858EBB4
gUnknown_858EBB4: @ 0x858EBB4
	.incbin "baserom_jp.gba", 0x58ebb4, 0x50c

	.globl gUnknown_858F0C0
gUnknown_858F0C0: @ 0x858F0C0
	.incbin "baserom_jp.gba", 0x58f0c0, 0x510

	.globl gUnknown_858F5D0
gUnknown_858F5D0: @ 0x858F5D0
	.incbin "baserom_jp.gba", 0x58f5d0, 0x14

	.globl gUnknown_858F5E4
gUnknown_858F5E4: @ 0x858F5E4
	.incbin "baserom_jp.gba", 0x58f5e4, 0x14

	.globl gUnknown_858F5F8
gUnknown_858F5F8: @ 0x858F5F8
	.incbin "baserom_jp.gba", 0x58f5f8, 0x4

	.globl gUnknown_858F5FC
gUnknown_858F5FC: @ 0x858F5FC
	.incbin "baserom_jp.gba", 0x58f5fc, 0x8

	.globl gUnknown_858F604
gUnknown_858F604: @ 0x858F604
	.incbin "baserom_jp.gba", 0x58f604, 0x3c

	.globl gUnknown_858F640
gUnknown_858F640: @ 0x858F640
	.incbin "baserom_jp.gba", 0x58f640, 0x8

	.globl gUnknown_858F648
gUnknown_858F648: @ 0x858F648
	.incbin "baserom_jp.gba", 0x58f648, 0x4

	.globl gUnknown_858F64C
gUnknown_858F64C: @ 0x858F64C
	.incbin "baserom_jp.gba", 0x58f64c, 0x18c

	.globl gUnknown_858F7D8
gUnknown_858F7D8: @ 0x858F7D8
	.incbin "baserom_jp.gba", 0x58f7d8, 0x1c

	.globl sDefaultTraderNames
sDefaultTraderNames: @ 0x858F7F4
	.incbin "baserom_jp.gba", 0x58f7f4, 0x10

	.globl sDefaultTraderDecorations
sDefaultTraderDecorations: @ 0x858F804
	.byte 0x5B, 0x6B, 0x25, 0x15

	.globl sTraderWindowTemplate
sTraderWindowTemplate: @ 0x858F808
	.incbin "baserom_jp.gba", 0x58f808, 0x8

	.globl gBirchBagGrass_Pal
gBirchBagGrass_Pal: @ 0x858F810
	.incbin "graphics/jp/gBirchBagGrass_Pal.bin"

	.globl gUnknown_858F812
gUnknown_858F812: @ 0x858F812
	.incbin "baserom_jp.gba", 0x58f812, 0x7e

	.globl gBirchBagTilemap
gBirchBagTilemap: @ 0x858F890
	.incbin "graphics/jp/gBirchBagTilemap.bin"

	.globl gBirchGrassTilemap
gBirchGrassTilemap: @ 0x858FA1C
	.incbin "graphics/jp/gBirchGrassTilemap.bin"

	.globl gBirchBagGrass_Gfx
gBirchBagGrass_Gfx: @ 0x858FC14
	.incbin "graphics/jp/gBirchBagGrass_Gfx.bin"

	.globl sStarterWindowTemplates
sStarterWindowTemplates: @ 0x8590BDC
	.incbin "baserom_jp.gba", 0x590bdc, 0x10

	.globl sStarterWindowTemplate_ConfirmStarter
sStarterWindowTemplate_ConfirmStarter: @ 0x8590BEC
	.incbin "baserom_jp.gba", 0x590bec, 0x8

	.globl sStarterWindowTemplate_StarterLabel
sStarterWindowTemplate_StarterLabel: @ 0x8590BF4
	.incbin "baserom_jp.gba", 0x590bf4, 0x8

	.globl sStarterPokeballCoords
sStarterPokeballCoords: @ 0x8590BFC
	.byte 0x3C, 0x40, 0x78, 0x58, 0xB4, 0x40

	.globl sStarterLabelCoords
sStarterLabelCoords: @ 0x8590C02
	.byte 0x03, 0x09, 0x11, 0x0A, 0x0C, 0x04

	.globl sStarterMon
sStarterMon: @ 0x8590C08
	.hword 0x0115, 0x0118, 0x011B, 0x0000

	.globl sStarterBgTemplates
sStarterBgTemplates: @ 0x8590C10
	.incbin "baserom_jp.gba", 0x590c10, 0xc

	.globl sStarterTextColors
sStarterTextColors: @ 0x8590C1C
	.incbin "baserom_jp.gba", 0x590c1c, 0x1c

	.globl sStarterCursorCoords
sStarterCursorCoords: @ 0x8590C38
	.byte 0x3C, 0x20, 0x78, 0x38, 0xB4, 0x20, 0x00, 0x00, 0x30, 0x00, 0x1E, 0x00
	.byte 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0xFF, 0xFF, 0x00, 0x00
	.byte 0x10, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04, 0x00
	.byte 0x00, 0x00, 0x04, 0x00, 0x10, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00
	.byte 0x20, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x20, 0x00
	.byte 0x10, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x20, 0x00, 0x08, 0x00
	.byte 0x00, 0x00, 0x08, 0x00, 0x10, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x20, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0xFE, 0xFF, 0x00, 0x00
	.byte 0x00, 0x00, 0x08, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x40, 0x0C, 0x59, 0x08
	.byte 0x48, 0x0C, 0x59, 0x08, 0x50, 0x0C, 0x59, 0x08, 0x98, 0x0C, 0x59, 0x08
	.byte 0x10, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x10, 0x00
	.byte 0x00, 0x0F, 0x00, 0x00, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x14, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x14, 0x00
	.byte 0x00, 0x0F, 0x00, 0x00, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.globl sStarterAffineAnims_StarterPokemon
sStarterAffineAnims_StarterPokemon: @ 0x8590CE0
	.incbin "baserom_jp.gba", 0x590ce0, 0x8

	.globl sStarterSpriteSheet_PokeballSelect
sStarterSpriteSheet_PokeballSelect: @ 0x8590CE8
	.incbin "baserom_jp.gba", 0x590ce8, 0x10

	.globl sStarterSpriteSheet_StarterCircle
sStarterSpriteSheet_StarterCircle: @ 0x8590CF8
	.incbin "baserom_jp.gba", 0x590cf8, 0x10

	.globl sStarterSpritePalettes
sStarterSpritePalettes: @ 0x8590D08
	.incbin "graphics/jp/sStarterSpritePalettes.bin"

	.globl sStarterSpriteTemplate_Hand
sStarterSpriteTemplate_Hand: @ 0x8590D20
	.incbin "baserom_jp.gba", 0x590d20, 0x18

	.globl sStarterSpriteTemplate_Pokeball
sStarterSpriteTemplate_Pokeball: @ 0x8590D38
	.incbin "baserom_jp.gba", 0x590d38, 0x18

	.globl sStarterSpriteTemplate_StarterCircle
sStarterSpriteTemplate_StarterCircle: @ 0x8590D50
	.incbin "baserom_jp.gba", 0x590d50, 0x18

	.globl gWallClockMale_Pal
gWallClockMale_Pal: @ 0x8590D68
	.incbin "graphics/jp/gWallClockMale_Pal.bin"

	.globl gWallClockFemale_Pal
gWallClockFemale_Pal: @ 0x8590D88
	.incbin "graphics/jp/gWallClockFemale_Pal.bin"

	.globl gWallClockStart_Tilemap
gWallClockStart_Tilemap: @ 0x8590DA8
	.incbin "graphics/jp/gWallClockStart_Tilemap.bin"

	.globl gWallClockView_Tilemap
gWallClockView_Tilemap: @ 0x8591074
	.incbin "graphics/jp/gWallClockView_Tilemap.bin"

	.globl gWallClock_Gfx
gWallClock_Gfx: @ 0x859130C
	.incbin "graphics/jp/gWallClock_Gfx.bin"
