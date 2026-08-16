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
	.globl sPokeJumpMons
sPokeJumpMons: @ 0x82CECF0
	.2byte 1, 2  @ SPECIES_BULBASAUR
	.2byte 4, 1  @ SPECIES_CHARMANDER
	.2byte 7, 0  @ SPECIES_SQUIRTLE
	.2byte 10, 1  @ SPECIES_CATERPIE
	.2byte 11, 1  @ SPECIES_METAPOD
	.2byte 13, 1  @ SPECIES_WEEDLE
	.2byte 14, 1  @ SPECIES_KAKUNA
	.2byte 19, 1  @ SPECIES_RATTATA
	.2byte 20, 1  @ SPECIES_RATICATE
	.2byte 25, 0  @ SPECIES_PIKACHU
	.2byte 27, 0  @ SPECIES_SANDSHREW
	.2byte 29, 0  @ SPECIES_NIDORAN_F
	.2byte 32, 0  @ SPECIES_NIDORAN_M
	.2byte 35, 0  @ SPECIES_CLEFAIRY
	.2byte 37, 0  @ SPECIES_VULPIX
	.2byte 39, 2  @ SPECIES_JIGGLYPUFF
	.2byte 43, 2  @ SPECIES_ODDISH
	.2byte 46, 1  @ SPECIES_PARAS
	.2byte 52, 0  @ SPECIES_MEOWTH
	.2byte 54, 2  @ SPECIES_PSYDUCK
	.2byte 56, 1  @ SPECIES_MANKEY
	.2byte 58, 1  @ SPECIES_GROWLITHE
	.2byte 60, 2  @ SPECIES_POLIWAG
	.2byte 69, 2  @ SPECIES_BELLSPROUT
	.2byte 90, 1  @ SPECIES_SHELLDER
	.2byte 98, 1  @ SPECIES_KRABBY
	.2byte 102, 2  @ SPECIES_EXEGGCUTE
	.2byte 104, 0  @ SPECIES_CUBONE
	.2byte 132, 2  @ SPECIES_DITTO
	.2byte 133, 0  @ SPECIES_EEVEE
	.2byte 138, 1  @ SPECIES_OMANYTE
	.2byte 140, 1  @ SPECIES_KABUTO
	.2byte 152, 2  @ SPECIES_CHIKORITA
	.2byte 155, 1  @ SPECIES_CYNDAQUIL
	.2byte 158, 0  @ SPECIES_TOTODILE
	.2byte 167, 1  @ SPECIES_SPINARAK
	.2byte 172, 0  @ SPECIES_PICHU
	.2byte 173, 0  @ SPECIES_CLEFFA
	.2byte 174, 2  @ SPECIES_IGGLYBUFF
	.2byte 175, 2  @ SPECIES_TOGEPI
	.2byte 179, 0  @ SPECIES_MAREEP
	.2byte 182, 2  @ SPECIES_BELLOSSOM
	.2byte 183, 2  @ SPECIES_MARILL
	.2byte 191, 2  @ SPECIES_SUNKERN
	.2byte 194, 2  @ SPECIES_WOOPER
	.2byte 204, 2  @ SPECIES_PINECO
	.2byte 209, 0  @ SPECIES_SNUBBULL
	.2byte 213, 2  @ SPECIES_SHUCKLE
	.2byte 216, 0  @ SPECIES_TEDDIURSA
	.2byte 218, 2  @ SPECIES_SLUGMA
	.2byte 220, 0  @ SPECIES_SWINUB
	.2byte 228, 1  @ SPECIES_HOUNDOUR
	.2byte 231, 0  @ SPECIES_PHANPY
	.2byte 233, 0  @ SPECIES_PORYGON2
	.2byte 236, 1  @ SPECIES_TYROGUE
	.2byte 238, 2  @ SPECIES_SMOOCHUM
	.2byte 239, 1  @ SPECIES_ELEKID
	.2byte 240, 1  @ SPECIES_MAGBY
	.2byte 246, 1  @ SPECIES_LARVITAR
	.2byte 277, 1  @ SPECIES_TREECKO
	.2byte 280, 2  @ SPECIES_TORCHIC
	.2byte 283, 0  @ SPECIES_MUDKIP
	.2byte 284, 0  @ SPECIES_MARSHTOMP
	.2byte 286, 1  @ SPECIES_POOCHYENA
	.2byte 288, 0  @ SPECIES_ZIGZAGOON
	.2byte 289, 0  @ SPECIES_LINOONE
	.2byte 290, 1  @ SPECIES_WURMPLE
	.2byte 291, 2  @ SPECIES_SILCOON
	.2byte 293, 2  @ SPECIES_CASCOON
	.2byte 295, 2  @ SPECIES_LOTAD
	.2byte 298, 1  @ SPECIES_SEEDOT
	.2byte 392, 0  @ SPECIES_RALTS
	.2byte 393, 0  @ SPECIES_KIRLIA
	.2byte 311, 2  @ SPECIES_SURSKIT
	.2byte 306, 2  @ SPECIES_SHROOMISH
	.2byte 301, 1  @ SPECIES_NINCADA
	.2byte 370, 0  @ SPECIES_WHISMUR
	.2byte 350, 2  @ SPECIES_AZURILL
	.2byte 315, 0  @ SPECIES_SKITTY
	.2byte 322, 0  @ SPECIES_SABLEYE
	.2byte 355, 0  @ SPECIES_MAWILE
	.2byte 382, 1  @ SPECIES_ARON
	.2byte 356, 2  @ SPECIES_MEDITITE
	.2byte 337, 1  @ SPECIES_ELECTRIKE
	.2byte 353, 1  @ SPECIES_PLUSLE
	.2byte 354, 1  @ SPECIES_MINUN
	.2byte 386, 0  @ SPECIES_VOLBEAT
	.2byte 387, 0  @ SPECIES_ILLUMISE
	.2byte 363, 2  @ SPECIES_ROSELIA
	.2byte 367, 2  @ SPECIES_GULPIN
	.2byte 339, 2  @ SPECIES_NUMEL
	.2byte 321, 2  @ SPECIES_TORKOAL
	.2byte 351, 0  @ SPECIES_SPOINK
	.2byte 332, 2  @ SPECIES_TRAPINCH
	.2byte 344, 2  @ SPECIES_CACNEA
	.2byte 390, 1  @ SPECIES_ANORITH
	.2byte 360, 0  @ SPECIES_WYNAUT
	.2byte 346, 0  @ SPECIES_SNORUNT
	.2byte 373, 1  @ SPECIES_CLAMPERL
	.2byte 395, 1  @ SPECIES_BAGON


	.globl sPokeJumpLeaderFuncs
sPokeJumpLeaderFuncs: @ 0x82CEE80
	.4byte sub_0802AF3C @ FUNC_GAME_INTRO (US GameIntro_Leader)
	.4byte sub_0802AFC8 @ FUNC_WAIT_ROUND (US WaitRound_Leader)
	.4byte sub_0802B05C @ FUNC_GAME_ROUND (US GameRound_Leader)
	.4byte sub_0802B0C8 @ FUNC_GAME_OVER (US GameOver_Leader)
	.4byte sub_0802B1C0 @ FUNC_ASK_PLAY_AGAIN (US AskPlayAgain_Leader)
	.4byte sub_0802B2BC @ FUNC_RESET_GAME (US ResetGame_Leader)
	.4byte sub_0802B358 @ FUNC_EXIT (US ExitGame)
	.4byte sub_0802B3AC @ FUNC_GIVE_PRIZE (US GivePrize_Leader)
	.4byte sub_0802B414 @ FUNC_SAVE (US SavePokeJump)

	.globl sPokeJumpMemberFuncs
sPokeJumpMemberFuncs: @ 0x82CEEA4
	.4byte sub_0802AF90 @ FUNC_GAME_INTRO (US GameIntro_Member)
	.4byte sub_0802B010 @ FUNC_WAIT_ROUND (US WaitRound_Member)
	.4byte sub_0802B0A8 @ FUNC_GAME_ROUND (US GameRound_Member)
	.4byte sub_0802B164 @ FUNC_GAME_OVER (US GameOver_Member)
	.4byte sub_0802B25C @ FUNC_ASK_PLAY_AGAIN (US AskPlayAgain_Member)
	.4byte sub_0802B31C @ FUNC_RESET_GAME (US ResetGame_Member)
	.4byte sub_0802B358 @ FUNC_EXIT (US ExitGame)
	.4byte sub_0802B3F8 @ FUNC_GIVE_PRIZE (US GivePrize_Member)
	.4byte sub_0802B414 @ FUNC_SAVE (US SavePokeJump)

	.globl sVineBaseSpeeds
sVineBaseSpeeds: @ 0x82CEEC8
	.2byte 26, 31, 36, 41, 46, 51, 56, 61

	.globl sVineSpeedDelays
sVineSpeedDelays: @ 0x82CEED8
	.2byte 0, 1, 1, 2

	.globl sSoundEffects
sSoundEffects: @ 0x82CEEE0
	.hword SE_SHOP @ 0x005F
	.hword SE_SHINY @ 0x0066
	.hword SE_M_MORNING_SUN @ 0x00E4
	.hword SE_RG_POKE_JUMP_SUCCESS @ 0x0105

	.globl sJumpOffsets
sJumpOffsets: @ 0x82CEEE8
	.byte 253, 250, 248, 246, 243, 241, 239, 237, 235, 233, 231, 229, 228, 227, 226, 226, 226, 228, 229, 230, 231, 233, 234, 236, 238, 239, 241, 243, 245, 248, 250, 252, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  @ row 0 (NORMAL=0 FAST=1 SLOW=2)
	.byte 253, 250, 247, 245, 242, 240, 238, 236, 234, 232, 230, 228, 227, 226, 226, 228, 230, 232, 234, 236, 238, 240, 242, 245, 247, 250, 252, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  @ row 1 (NORMAL=0 FAST=1 SLOW=2)
	.byte 253, 250, 247, 245, 243, 241, 239, 237, 235, 233, 231, 229, 228, 227, 226, 226, 226, 226, 227, 227, 228, 228, 229, 229, 230, 231, 232, 234, 236, 238, 240, 242, 244, 245, 247, 250, 252, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  @ row 2 (NORMAL=0 FAST=1 SLOW=2)


	.globl sScoreBonuses
sScoreBonuses: @ 0x82CEF78
	.4byte 0 @ 0 players
	.4byte 0 @ 1 players
	.4byte 50 @ 2 players
	.4byte 100 @ 3 players
	.4byte 200 @ 4 players
	.4byte 500 @ 5 players

	.globl sPrizeItems
sPrizeItems: @ 0x82CEF90
	.2byte 138  @ ITEM_LEPPA_BERRY
	.2byte 141  @ ITEM_LUM_BERRY
	.2byte 142  @ ITEM_SITRUS_BERRY
	.2byte 143  @ ITEM_FIGY_BERRY
	.2byte 144  @ ITEM_WIKI_BERRY
	.2byte 145  @ ITEM_MAGO_BERRY
	.2byte 146  @ ITEM_AGUAV_BERRY
	.2byte 147  @ ITEM_IAPAPA_BERRY


	.globl gUnknown_82CEFA0
gUnknown_82CEFA0: @ 0x82CEFA0
	.incbin "baserom_jp.gba", 0x2cefa0, 0x6f4

	.globl gUnknown_82CF694
gUnknown_82CF694: @ 0x82CF694
	.incbin "baserom_jp.gba", 0x2cf694, 0x28

	.globl gUnknown_82CF6BC
gUnknown_82CF6BC: @ 0x82CF6BC
	.incbin "baserom_jp.gba", 0x2cf6bc, 0x10

	.globl gUnknown_82CF6CC
gUnknown_82CF6CC: @ 0x82CF6CC
	.incbin "baserom_jp.gba", 0x2cf6cc, 0x18

	.globl sVineYCoords
sVineYCoords: @ 0x82CF6E4
	.2byte 96, 96, 96, 114, 120, 120, 120, 114
	.2byte 96, 96, 70, 80, 96, 114, 120, 128
	.2byte 120, 114, 96, 80, 50, 72, 96, 114
	.2byte 128, 136, 128, 114, 96, 72, 42, 72
	.2byte 96, 114, 128, 136, 128, 114, 96, 72

	.globl sVineXCoords
sVineXCoords: @ 0x82CF734
	.2byte 16, 40, 72, 104, 136, 168, 200, 224


	.globl gUnknown_82CF744
gUnknown_82CF744: @ 0x82CF744
	.incbin "baserom_jp.gba", 0x2cf744, 0x154

	.globl gUnknown_82CF898
gUnknown_82CF898: @ 0x82CF898
	.incbin "baserom_jp.gba", 0x2cf898, 0x18

	.globl gUnknown_82CF8B0
gUnknown_82CF8B0: @ 0x82CF8B0
	.incbin "baserom_jp.gba", 0x2cf8b0, 0x20

	.globl gUnknown_82CF8D0
gUnknown_82CF8D0: @ 0x82CF8D0
	.incbin "baserom_jp.gba", 0x2cf8d0, 0x20

	.globl gUnknown_82CF8F0
gUnknown_82CF8F0: @ 0x82CF8F0
	.incbin "baserom_jp.gba", 0x2cf8f0, 0x22c

	.globl gUnknown_82CFB1C
gUnknown_82CFB1C: @ 0x82CFB1C
	.incbin "baserom_jp.gba", 0x2cfb1c, 0x1b0

	.globl gUnknown_82CFCCC
gUnknown_82CFCCC: @ 0x82CFCCC
	.incbin "baserom_jp.gba", 0x2cfccc, 0x20

	.globl gUnknown_82CFCEC
gUnknown_82CFCEC: @ 0x82CFCEC
	.incbin "baserom_jp.gba", 0x2cfcec, 0x950

	.globl gUnknown_82D063C
gUnknown_82D063C: @ 0x82D063C
	.incbin "baserom_jp.gba", 0x2d063c, 0x3b8

	.globl gUnknown_82D09F4
gUnknown_82D09F4: @ 0x82D09F4
	.incbin "baserom_jp.gba", 0x2d09f4, 0x20

	.globl gUnknown_82D0A14
gUnknown_82D0A14: @ 0x82D0A14
	.incbin "baserom_jp.gba", 0x2d0a14, 0xab0

	.globl gUnknown_82D14C4
gUnknown_82D14C4: @ 0x82D14C4
	.incbin "baserom_jp.gba", 0x2d14c4, 0x52c

	.globl sPokeJumpBgTemplates
sPokeJumpBgTemplates: @ 0x82D19F0
	.hword 0x01B0 @ bg=0 charBaseIndex=0 mapBaseIndex=27 screenSize=0 paletteMode=0 priority=0
	.hword 0x0000 @ baseTile
	.hword 0x25E6 @ bg=2 charBaseIndex=1 mapBaseIndex=30 screenSize=2 paletteMode=0 priority=2
	.hword 0x0000 @ baseTile
	.hword 0x16C9 @ bg=1 charBaseIndex=2 mapBaseIndex=12 screenSize=3 paletteMode=0 priority=1
	.hword 0x0000 @ baseTile
	.hword 0x31DF @ bg=3 charBaseIndex=3 mapBaseIndex=29 screenSize=0 paletteMode=0 priority=3
	.hword 0x0000 @ baseTile

	.globl sPokeJumpWindowTemplates
sPokeJumpWindowTemplates: @ 0x82D1A00
	.byte 0 @ [0] bg
	.byte 19 @ [0] tilemapLeft
	.byte 0 @ [0] tilemapTop
	.byte 2 @ [0] width
	.byte 2 @ [0] height
	.byte 2 @ [0] paletteNum
	.hword 0x0013 @ [0] baseBlock
	.byte 0 @ [1] bg
	.byte 8 @ [1] tilemapLeft
	.byte 0 @ [1] tilemapTop
	.byte 2 @ [1] width
	.byte 2 @ [1] height
	.byte 2 @ [1] paletteNum
	.hword 0x0017 @ [1] baseBlock
	.byte 255 @ [2] bg
	.byte 0 @ [2] tilemapLeft
	.byte 0 @ [2] tilemapTop
	.byte 0 @ [2] width
	.byte 0 @ [2] height
	.byte 0 @ [2] paletteNum
	.hword 0x0000 @ [2] baseBlock

	.globl gUnknown_82D1A18
gUnknown_82D1A18: @ 0x82D1A18
	.incbin "baserom_jp.gba", 0x2d1a18, 0x50

	.globl gUnknown_82D1A68
gUnknown_82D1A68: @ 0x82D1A68
	.byte 0x00, 0x02, 0x03

	.globl sVenusaurStates
sVenusaurStates: @ 0x82D1A6B
	.byte 2 @ VINE_HIGHEST -> VENUSAUR_UP
	.byte 2 @ VINE_DOWNSWING_HIGHER -> VENUSAUR_UP
	.byte 0 @ VINE_DOWNSWING_HIGH -> VENUSAUR_NEUTRAL
	.byte 0 @ VINE_DOWNSWING_LOW -> VENUSAUR_NEUTRAL
	.byte 1 @ VINE_DOWNSWING_LOWER -> VENUSAUR_DOWN
	.byte 1 @ VINE_LOWEST -> VENUSAUR_DOWN
	.byte 1 @ VINE_UPSWING_LOWER -> VENUSAUR_DOWN
	.byte 0 @ VINE_UPSWING_LOW -> VENUSAUR_NEUTRAL
	.byte 0 @ VINE_UPSWING_HIGH -> VENUSAUR_NEUTRAL
	.byte 2 @ VINE_UPSWING_HIGHER -> VENUSAUR_UP
	.byte 0 @ JP trailing entry 10
	.byte 0 @ JP trailing entry 11
	.byte 0 @ JP trailing entry 12

	.globl gUnknown_82D1A78
gUnknown_82D1A78: @ 0x82D1A78
	.incbin "baserom_jp.gba", 0x2d1a78, 0x8

	.globl sSpritePalette_Digits
sSpritePalette_Digits: @ 0x82D1A80
	.4byte 0x082D2A68 @ gMinigameDigits_Pal
	.4byte 0x0320 @ TAG_DIGITS
	.globl sPlayerNameWindowCoords_2Players
sPlayerNameWindowCoords_2Players: @ 0x82D1A88
	.hword 6, 8 @ player 0 x, y
	.hword 16, 8 @ player 1 x, y
	.globl sPlayerNameWindowCoords_3Players
sPlayerNameWindowCoords_3Players: @ 0x82D1A90
	.hword 6, 8 @ player 0 x, y
	.hword 11, 6 @ player 1 x, y
	.hword 16, 8 @ player 2 x, y
	.globl sPlayerNameWindowCoords_4Players
sPlayerNameWindowCoords_4Players: @ 0x82D1A9C
	.hword 2, 6 @ player 0 x, y
	.hword 6, 8 @ player 1 x, y
	.hword 16, 8 @ player 2 x, y
	.hword 20, 6 @ player 3 x, y
	.globl sPlayerNameWindowCoords_5Players
sPlayerNameWindowCoords_5Players: @ 0x82D1AAC
	.hword 2, 6 @ player 0 x, y
	.hword 6, 8 @ player 1 x, y
	.hword 11, 6 @ player 2 x, y
	.hword 16, 8 @ player 3 x, y
	.hword 20, 6 @ player 4 x, y

	.globl sPlayerNameWindowCoords
sPlayerNameWindowCoords: @ 0x82D1AC0
	.4byte sPlayerNameWindowCoords_2Players @ 0x082D1A88
	.4byte sPlayerNameWindowCoords_3Players @ 0x082D1A90
	.4byte sPlayerNameWindowCoords_4Players @ 0x082D1A9C
	.4byte sPlayerNameWindowCoords_5Players @ 0x082D1AAC
	.globl sMonXCoords_2Players
sMonXCoords_2Players: @ 0x82D1AD0
	.hword 88 @ player 0 x
	.hword 152 @ player 1 x
	.globl sMonXCoords_3Players
sMonXCoords_3Players: @ 0x82D1AD4
	.hword 88 @ player 0 x
	.hword 120 @ player 1 x
	.hword 152 @ player 2 x
	.globl sMonXCoords_4Players
sMonXCoords_4Players: @ 0x82D1ADA
	.hword 56 @ player 0 x
	.hword 88 @ player 1 x
	.hword 152 @ player 2 x
	.hword 184 @ player 3 x
	.globl sMonXCoords_5Players
sMonXCoords_5Players: @ 0x82D1AE2
	.hword 56 @ player 0 x
	.hword 88 @ player 1 x
	.hword 120 @ player 2 x
	.hword 152 @ player 3 x
	.hword 184 @ player 4 x

	.globl sMonXCoords
sMonXCoords: @ 0x82D1AEC
	.4byte sMonXCoords_2Players @ 0x082D1AD0
	.4byte sMonXCoords_3Players @ 0x082D1AD4
	.4byte sMonXCoords_4Players @ 0x082D1ADA
	.4byte sMonXCoords_5Players @ 0x082D1AE2

	.globl gUnknown_82D1AFC
gUnknown_82D1AFC: @ 0x82D1AFC
	.incbin "baserom_jp.gba", 0x2d1afc, 0x8

	.globl gUnknown_82D1B04
gUnknown_82D1B04: @ 0x82D1B04
	.incbin "baserom_jp.gba", 0x2d1b04, 0x450

	.globl gUnknown_82D1F54
gUnknown_82D1F54: @ 0x82D1F54
	.incbin "baserom_jp.gba", 0x2d1f54, 0x10

	.globl gUnknown_82D1F64
gUnknown_82D1F64: @ 0x82D1F64
	.incbin "baserom_jp.gba", 0x2d1f64, 0x58

	.globl gUnknown_82D1FBC
gUnknown_82D1FBC: @ 0x82D1FBC
	.incbin "baserom_jp.gba", 0x2d1fbc, 0x18

	.globl gUnknown_82D1FD4
gUnknown_82D1FD4: @ 0x82D1FD4
	.incbin "baserom_jp.gba", 0x2d1fd4, 0x484

	.globl gUnknown_82D2458
gUnknown_82D2458: @ 0x82D2458
	.incbin "baserom_jp.gba", 0x2d2458, 0x8

	.globl gUnknown_82D2460
gUnknown_82D2460: @ 0x82D2460
	.incbin "baserom_jp.gba", 0x2d2460, 0xbc

	.globl gUnknown_82D251C
gUnknown_82D251C: @ 0x82D251C
	.incbin "baserom_jp.gba", 0x2d251c, 0x18

	.globl gUnknown_82D2534
gUnknown_82D2534: @ 0x82D2534
	.incbin "baserom_jp.gba", 0x2d2534, 0x18

	.globl gUnknown_82D254C
gUnknown_82D254C: @ 0x82D254C
	.incbin "baserom_jp.gba", 0x2d254c, 0xc

	.globl gUnknown_82D2558
gUnknown_82D2558: @ 0x82D2558
	.4byte 0x0000001F, 0x0000001C, 0x0000001F, 0x0000001E, 0x0000001F, 0x0000001E, 0x0000001F, 0x0000001F, 0x0000001E, 0x0000001F, 0x0000001E, 0x0000001F

	.globl sBirchSpeechBgPals
sBirchSpeechBgPals: @ 0x82D2588
	.hword 0x0000 @ pal 0, color 0
	.hword 0x53FF @ pal 0, color 1
	.hword 0x37FF @ pal 0, color 2
	.hword 0x2F7B @ pal 0, color 3
	.hword 0x26F7 @ pal 0, color 4
	.hword 0x1E73 @ pal 0, color 5
	.hword 0x19EF @ pal 0, color 6
	.hword 0x116B @ pal 0, color 7
	.hword 0x08E7 @ pal 0, color 8
	.hword 0x67F8 @ pal 0, color 9
	.hword 0x43EF @ pal 0, color 10
	.hword 0x376E @ pal 0, color 11
	.hword 0x2EED @ pal 0, color 12
	.hword 0x226C @ pal 0, color 13
	.hword 0x19EB @ pal 0, color 14
	.hword 0x0000 @ pal 0, color 15
	.hword 0x0000 @ pal 1, color 0
	.hword 0x53FF @ pal 1, color 1
	.hword 0x37FF @ pal 1, color 2
	.hword 0x2F7B @ pal 1, color 3
	.hword 0x26F7 @ pal 1, color 4
	.hword 0x1E73 @ pal 1, color 5
	.hword 0x19EF @ pal 1, color 6
	.hword 0x116B @ pal 1, color 7
	.hword 0x08E7 @ pal 1, color 8
	.hword 0x67F8 @ pal 1, color 9
	.hword 0x43EF @ pal 1, color 10
	.hword 0x376E @ pal 1, color 11
	.hword 0x2EED @ pal 1, color 12
	.hword 0x226C @ pal 1, color 13
	.hword 0x19EB @ pal 1, color 14
	.hword 0x0000 @ pal 1, color 15

	.globl gUnknown_82D25C8
gUnknown_82D25C8: @ 0x82D25C8
	.incbin "baserom_jp.gba", 0x2d25c8, 0x1b4

	.globl gUnknown_82D277C
gUnknown_82D277C: @ 0x82D277C
	.incbin "baserom_jp.gba", 0x2d277c, 0x12a

	.globl sBirchSpeechBgGradientPal
sBirchSpeechBgGradientPal: @ 0x82D28A6
	.hword 0x53FF @ color 0
	.hword 0x37FF @ color 1
	.hword 0x2F7B @ color 2
	.hword 0x26F7 @ color 3
	.hword 0x1E73 @ color 4
	.hword 0x19EF @ color 5
	.hword 0x116B @ color 6
	.hword 0x08E7 @ color 7
	.hword 0x0000 @ color 8
	.hword 0x0000 @ color 9
	.hword 0x0000 @ color 10
	.hword 0x0000 @ color 11
	.hword 0x0000 @ color 12
	.hword 0x0000 @ color 13
	.hword 0x0000 @ color 14
	.hword 0x0000 @ color 15
	.globl gUnknown_82D28C6
gUnknown_82D28C6: @ 0x82D28C6
	.incbin "baserom_jp.gba", 0x2d28c6, 0x2

	.globl gUnknown_82D28C8
gUnknown_82D28C8: @ 0x82D28C8
	.incbin "baserom_jp.gba", 0x2d28c8, 0x10

	.globl gUnknown_82D28D8
gUnknown_82D28D8: @ 0x82D28D8
	.incbin "baserom_jp.gba", 0x2d28d8, 0x28

	.globl gUnknown_82D2900
gUnknown_82D2900: @ 0x82D2900
	.incbin "baserom_jp.gba", 0x2d2900, 0x10

	.globl sNewGameBirchSpeechTextWindows
sNewGameBirchSpeechTextWindows: @ 0x82D2910
	.byte 0 @ [0] bg
	.byte 4 @ [0] tilemapLeft
	.byte 15 @ [0] tilemapTop
	.byte 22 @ [0] width
	.byte 4 @ [0] height
	.byte 15 @ [0] paletteNum
	.hword 0x0001 @ [0] baseBlock
	.byte 0 @ [1] bg
	.byte 3 @ [1] tilemapLeft
	.byte 5 @ [1] tilemapTop
	.byte 5 @ [1] width
	.byte 4 @ [1] height
	.byte 15 @ [1] paletteNum
	.hword 0x0059 @ [1] baseBlock
	.byte 0 @ [2] bg
	.byte 3 @ [2] tilemapLeft
	.byte 2 @ [2] tilemapTop
	.byte 9 @ [2] width
	.byte 10 @ [2] height
	.byte 15 @ [2] paletteNum
	.hword 0x006D @ [2] baseBlock
	.byte 255 @ [3] bg
	.byte 0 @ [3] tilemapLeft
	.byte 0 @ [3] tilemapTop
	.byte 0 @ [3] width
	.byte 0 @ [3] height
	.byte 0 @ [3] paletteNum
	.hword 0x0000 @ [3] baseBlock

	.globl sMainMenuBgPal
sMainMenuBgPal: @ 0x82D2930
	.hword 0x7E51 @ color 0
	.hword 0x7FFF @ color 1
	.hword 0x28E6 @ color 2
	.hword 0x398B @ color 3
	.hword 0x0821 @ color 4
	.hword 0x5672 @ color 5
	.hword 0x7779 @ color 6
	.hword 0x5ED6 @ color 7
	.hword 0x6F37 @ color 8
	.hword 0x1884 @ color 9
	.hword 0x460F @ color 10
	.hword 0x3D46 @ color 11
	.hword 0x61E5 @ color 12
	.hword 0x6A27 @ color 13
	.hword 0x728B @ color 14
	.hword 0x7B11 @ color 15

	.globl sMainMenuTextPal
sMainMenuTextPal: @ 0x82D2950
	.hword 0x7FFF @ color 0
	.hword 0x7FFF @ color 1
	.hword 0x318C @ color 2
	.hword 0x675A @ color 3
	.hword 0x043C @ color 4
	.hword 0x3AFF @ color 5
	.hword 0x0664 @ color 6
	.hword 0x4BD2 @ color 7
	.hword 0x6546 @ color 8
	.hword 0x7B14 @ color 9
	.hword 0x0000 @ color 10
	.hword 0x0000 @ color 11
	.hword 0x0000 @ color 12
	.hword 0x0000 @ color 13
	.hword 0x0000 @ color 14
	.hword 0x0000 @ color 15

	.globl sTextColor_Headers
sTextColor_Headers: @ 0x82D2970
	.byte 0xA @ TEXT_DYNAMIC_COLOR_1
	.byte 0xB @ TEXT_DYNAMIC_COLOR_2
	.byte 0xC @ TEXT_DYNAMIC_COLOR_3

	.globl sTextColor_Savegame
sTextColor_Savegame: @ 0x82D2973
	.byte 0xA @ TEXT_DYNAMIC_COLOR_1
	.byte 0x1 @ TEXT_COLOR_WHITE
	.byte 0xC @ TEXT_DYNAMIC_COLOR_3
	.byte 0, 0 @ JP trailing entries

	.globl sMainMenuBgTemplates
sMainMenuBgTemplates: @ 0x82D2978
	.hword 0x01E8 @ bg=0 charBaseIndex=2 mapBaseIndex=30 screenSize=0 paletteMode=0 priority=0
	.hword 0x0000 @ baseTile
	.hword 0x3071 @ bg=1 charBaseIndex=0 mapBaseIndex=7 screenSize=0 paletteMode=0 priority=3
	.hword 0x0000 @ baseTile

	.globl sBirchBgTemplate
sBirchBgTemplate: @ 0x82D2980
	.hword 0x01EC @ bg=0 charBaseIndex=3 mapBaseIndex=30 screenSize=0 paletteMode=0 priority=0
	.hword 0x0000 @ baseTile

	.globl sScrollArrowsTemplate_MainMenu
sScrollArrowsTemplate_MainMenu: @ 0x82D2984
	.byte 2 @ firstArrowType
	.byte 0x78 @ firstX
	.byte 8 @ firstY
	.byte 3 @ secondArrowType
	.byte 0x78 @ secondX
	.byte 0x98 @ secondY
	.hword 3 @ fullyUpThreshold
	.hword 4 @ fullyDownThreshold
	.hword 1 @ tileTag
	.hword 1 @ palTag
	.byte 0 @ palNum
	.byte 0 @ padding
	.globl sSpriteAffineAnim_PlayerShrink
sSpriteAffineAnim_PlayerShrink: @ 0x82D2994
	.hword 0xFFFE @ AFFINEANIMCMD_FRAME scaleX -2
	.hword 0xFFFE @ scaleY -2
	.hword 0x3000 @ JP frame duration/x field
	.hword 0x0000 @ x, y
	.hword 0x7FFF @ AFFINEANIMCMD_END
	.hword 0x0000 @ pad
	.hword 0x0000 @ pad
	.hword 0x0000 @ pad

	.globl sSpriteAffineAnimTable_PlayerShrink
sSpriteAffineAnimTable_PlayerShrink: @ 0x82D29A4
	.4byte sSpriteAffineAnim_PlayerShrink

	.globl sMenuActions_Gender
sMenuActions_Gender: @ 0x82D29A8
	.4byte gText_BirchBoy @ text (US gText_BirchBoy)
	.4byte 0 @ func NULL
	.4byte gText_BirchGirl @ text (US gText_BirchGirl)
	.4byte 0 @ func NULL

	.globl sMalePresetNames
sMalePresetNames: @ 0x82D29B8
	.4byte gText_DefaultName_Itsuo @ 0x85C8E9A
	.4byte gText_DefaultName_Gyoku @ 0x85C8EA0
	.4byte gText_DefaultName_Kei @ 0x85C8EA6
	.4byte gText_DefaultName_Shuusaku @ 0x85C8EAC
	.4byte gText_DefaultName_Seigo @ 0x85C8EB2
	.4byte gText_DefaultName_Daisaku @ 0x85C8EB8
	.4byte gText_DefaultName_Takahito @ 0x85C8EBE
	.4byte gText_DefaultName_Tatsuya @ 0x85C8EC4
	.4byte gText_DefaultName_Daniel @ 0x85C8ECA
	.4byte gText_DefaultName_Teruki @ 0x85C8ED0
	.4byte gText_DefaultName_Tom @ 0x85C8ED6
	.4byte gText_DefaultName_Tomoya @ 0x85C8EDC
	.4byte gText_DefaultName_Hitoshi @ 0x85C8EE2
	.4byte gText_DefaultName_Hiroaki @ 0x85C8EE8
	.4byte gText_DefaultName_Yukihiko @ 0x85C8EEE
	.4byte gText_DefaultName_Raldo @ 0x85C8EF4
	.4byte gText_DefaultName_Rikuya @ 0x85C8EFA
	.4byte gText_DefaultName_Richard @ 0x85C8F00
	.4byte gText_DefaultName_Ryuu @ 0x85C8F06
	.4byte gText_DefaultName_Ryouta @ 0x85C8F0C
	.globl sFemalePresetNames
sFemalePresetNames: @ 0x82D2A08
	.4byte gText_DefaultName_Aiko @ 0x85C8F12
	.4byte gText_DefaultName_Ayana @ 0x85C8F18
	.4byte gText_DefaultName_Ann @ 0x85C8F1E
	.4byte gText_DefaultName_Emii @ 0x85C8F24
	.4byte gText_DefaultName_Kaori @ 0x85C8F28
	.4byte gText_DefaultName_Karen @ 0x85C8F2E
	.4byte gText_DefaultName_Kyouko @ 0x85C8F34
	.4byte gText_DefaultName_Sae @ 0x85C8F3A
	.4byte gText_DefaultName_Sui @ 0x85C8F40
	.4byte gText_DefaultName_Juri @ 0x85C8F46
	.4byte gText_DefaultName_Chiemi @ 0x85C8F4C
	.4byte gText_DefaultName_Chiyoko @ 0x85C8F52
	.4byte gText_DefaultName_Teruko @ 0x85C8F58
	.4byte gText_DefaultName_Nanae @ 0x85C8F5E
	.4byte gText_DefaultName_Hina @ 0x85C8F64
	.4byte gText_DefaultName_Makiko @ 0x85C8F6A
	.4byte gText_DefaultName_Misako @ 0x85C8F70
	.4byte gText_DefaultName_Mutsumi @ 0x85C8F76
	.4byte gText_DefaultName_Monica @ 0x85C8F7C
	.4byte gText_DefaultName_Yuume @ 0x85C8F82
	.globl sTilesPerImage
sTilesPerImage: @ 0x82D2A58 (JP: digit_obj_util.c sTilesPerImage[4][4])
	.incbin "graphics/misc/sTilesPerImage.bin"

	.globl gUnknown_82D2A68
gUnknown_82D2A68: @ 0x82D2A68
	.incbin "baserom_jp.gba", 0x2d2a68, 0x440

	.globl gAffineAnims_BattleSpritePlayerSide
gAffineAnims_BattleSpritePlayerSide: @ 0x82D2EA8
	.4byte 0x082D2DD8 @ BATTLER_AFFINE_NORMAL
	.4byte 0x082D2DF8 @ BATTLER_AFFINE_EMERGE
	.4byte 0x082D2E10 @ BATTLER_AFFINE_RETURN
	.4byte 0x082D2E28 @ sAffineAnim_Battler_HorizontalSquishLoop
	.4byte 0x082D2E48 @ sAffineAnim_Battler_Grow
	.4byte 0x082D2E58 @ sAffineAnim_Battler_Shrink
	.4byte 0x082D2E80 @ sAffineAnim_Battler_GrowLarge
	.4byte 0x082D2E90 @ sAffineAnim_Battler_TipRight
	.4byte 0x082D2E68 @ sAffineAnim_Battler_BigToSmall
	.globl gUnknown_82D2ECC
gUnknown_82D2ECC: @ 0x82D2ECC
	.incbin "baserom_jp.gba", 0x2d2ecc, 0x58

	.globl gAffineAnims_BattleSpriteOpponentSide
gAffineAnims_BattleSpriteOpponentSide: @ 0x82D2F24
	.4byte 0x082D2DD8 @ BATTLER_AFFINE_NORMAL
	.4byte 0x082D2DF8 @ BATTLER_AFFINE_EMERGE
	.4byte 0x082D2E10 @ BATTLER_AFFINE_RETURN
	.4byte 0x082D2E28 @ sAffineAnim_Battler_HorizontalSquishLoop
	.4byte 0x082D2E48 @ sAffineAnim_Battler_Grow
	.4byte 0x082D2E58 @ sAffineAnim_Battler_Shrink
	.4byte 0x082D2ECC @ sAffineAnim_Battler_SpinShrink
	.4byte 0x082D2EDC @ sAffineAnim_Battler_TipLeft
	.4byte 0x082D2EF4 @ sAffineAnim_Battler_RotateUpAndBack
	.4byte 0x082D2E68 @ sAffineAnim_Battler_BigToSmall
	.4byte 0x082D2F14 @ sAffineAnim_Battler_Spin

	.globl gAffineAnims_BattleSpriteContest
gAffineAnims_BattleSpriteContest: @ 0x82D2F50
	.incbin "baserom_jp.gba", 0x2d2f50, 0x4c

	.globl gUnknown_82D2F9C
gUnknown_82D2F9C: @ 0x82D2F9C
	.incbin "baserom_jp.gba", 0x2d2f9c, 0x162c

	.globl gUnknown_82D45C8
	.set gUnknown_82D45C8, gMonFrontPicCoords  @ 0x82D45C8
	.globl gMonFrontPicCoords
gMonFrontPicCoords: @ 0x82D45C8
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_NONE (64x64, y=0)
	.byte 0x45, 0x0E, 0x00, 0x00  @ SPECIES_BULBASAUR (32x40, y=14)
	.byte 0x56, 0x0A, 0x00, 0x00  @ SPECIES_IVYSAUR (40x48, y=10)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_VENUSAUR (64x64, y=3)
	.byte 0x55, 0x0C, 0x00, 0x00  @ SPECIES_CHARMANDER (40x40, y=12)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_CHARMELEON (48x48, y=9)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_CHARIZARD (64x64, y=1)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_SQUIRTLE (48x40, y=13)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_WARTORTLE (48x48, y=8)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_BLASTOISE (64x64, y=0)
	.byte 0x45, 0x10, 0x00, 0x00  @ SPECIES_CATERPIE (32x40, y=16)
	.byte 0x54, 0x14, 0x00, 0x00  @ SPECIES_METAPOD (40x32, y=20)
	.byte 0x76, 0x09, 0x00, 0x00  @ SPECIES_BUTTERFREE (56x48, y=9)
	.byte 0x54, 0x12, 0x00, 0x00  @ SPECIES_WEEDLE (40x32, y=18)
	.byte 0x45, 0x0E, 0x00, 0x00  @ SPECIES_KAKUNA (32x40, y=14)
	.byte 0x86, 0x09, 0x00, 0x00  @ SPECIES_BEEDRILL (64x48, y=9)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_PIDGEY (48x40, y=13)
	.byte 0x67, 0x0B, 0x00, 0x00  @ SPECIES_PIDGEOTTO (48x56, y=11)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_PIDGEOT (64x64, y=1)
	.byte 0x44, 0x10, 0x00, 0x00  @ SPECIES_RATTATA (32x32, y=16)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_RATICATE (48x48, y=11)
	.byte 0x45, 0x0F, 0x00, 0x00  @ SPECIES_SPEAROW (32x40, y=15)
	.byte 0x78, 0x00, 0x00, 0x00  @ SPECIES_FEAROW (56x64, y=0)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_EKANS (48x40, y=12)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_ARBOK (64x64, y=2)
	.byte 0x67, 0x09, 0x00, 0x00  @ SPECIES_PIKACHU (48x56, y=9)
	.byte 0x67, 0x04, 0x00, 0x00  @ SPECIES_RAICHU (48x56, y=4)
	.byte 0x55, 0x0E, 0x00, 0x00  @ SPECIES_SANDSHREW (40x40, y=14)
	.byte 0x76, 0x09, 0x00, 0x00  @ SPECIES_SANDSLASH (56x48, y=9)
	.byte 0x45, 0x0F, 0x00, 0x00  @ SPECIES_NIDORAN_F (32x40, y=15)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_NIDORINA (48x48, y=11)
	.byte 0x78, 0x03, 0x00, 0x00  @ SPECIES_NIDOQUEEN (56x64, y=3)
	.byte 0x55, 0x0C, 0x00, 0x00  @ SPECIES_NIDORAN_M (40x40, y=12)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_NIDORINO (48x48, y=9)
	.byte 0x78, 0x02, 0x00, 0x00  @ SPECIES_NIDOKING (56x64, y=2)
	.byte 0x55, 0x10, 0x00, 0x00  @ SPECIES_CLEFAIRY (40x40, y=16)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_CLEFABLE (48x48, y=8)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_VULPIX (48x40, y=12)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_NINETALES (64x64, y=3)
	.byte 0x45, 0x10, 0x00, 0x00  @ SPECIES_JIGGLYPUFF (32x40, y=16)
	.byte 0x67, 0x08, 0x00, 0x00  @ SPECIES_WIGGLYTUFF (48x56, y=8)
	.byte 0x67, 0x06, 0x00, 0x00  @ SPECIES_ZUBAT (48x56, y=6)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_GOLBAT (64x64, y=3)
	.byte 0x45, 0x0F, 0x00, 0x00  @ SPECIES_ODDISH (32x40, y=15)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_GLOOM (48x48, y=10)
	.byte 0x77, 0x06, 0x00, 0x00  @ SPECIES_VILEPLUME (56x56, y=6)
	.byte 0x55, 0x0F, 0x00, 0x00  @ SPECIES_PARAS (40x40, y=15)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_PARASECT (64x48, y=8)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_VENONAT (48x48, y=8)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_VENOMOTH (64x64, y=2)
	.byte 0x54, 0x12, 0x00, 0x00  @ SPECIES_DIGLETT (40x32, y=18)
	.byte 0x75, 0x0D, 0x00, 0x00  @ SPECIES_DUGTRIO (56x40, y=13)
	.byte 0x55, 0x0C, 0x00, 0x00  @ SPECIES_MEOWTH (40x40, y=12)
	.byte 0x77, 0x07, 0x00, 0x00  @ SPECIES_PERSIAN (56x56, y=7)
	.byte 0x56, 0x09, 0x00, 0x00  @ SPECIES_PSYDUCK (40x48, y=9)
	.byte 0x78, 0x02, 0x00, 0x00  @ SPECIES_GOLDUCK (56x64, y=2)
	.byte 0x65, 0x0E, 0x00, 0x00  @ SPECIES_MANKEY (48x40, y=14)
	.byte 0x77, 0x07, 0x00, 0x00  @ SPECIES_PRIMEAPE (56x56, y=7)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_GROWLITHE (48x48, y=11)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_ARCANINE (64x64, y=2)
	.byte 0x74, 0x13, 0x00, 0x00  @ SPECIES_POLIWAG (56x32, y=19)
	.byte 0x76, 0x0A, 0x00, 0x00  @ SPECIES_POLIWHIRL (56x48, y=10)
	.byte 0x76, 0x08, 0x00, 0x00  @ SPECIES_POLIWRATH (56x48, y=8)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_ABRA (48x48, y=11)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_KADABRA (56x56, y=5)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_ALAKAZAM (64x56, y=4)
	.byte 0x56, 0x0B, 0x00, 0x00  @ SPECIES_MACHOP (40x48, y=11)
	.byte 0x67, 0x06, 0x00, 0x00  @ SPECIES_MACHOKE (48x56, y=6)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_MACHAMP (64x64, y=1)
	.byte 0x65, 0x0F, 0x00, 0x00  @ SPECIES_BELLSPROUT (48x40, y=15)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_WEEPINBELL (48x48, y=11)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_VICTREEBEL (56x56, y=5)
	.byte 0x46, 0x09, 0x00, 0x00  @ SPECIES_TENTACOOL (32x48, y=9)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_TENTACRUEL (64x56, y=4)
	.byte 0x54, 0x12, 0x00, 0x00  @ SPECIES_GEODUDE (40x32, y=18)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_GRAVELER (64x56, y=4)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_GOLEM (56x56, y=5)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_PONYTA (48x48, y=8)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_RAPIDASH (64x64, y=1)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_SLOWPOKE (48x48, y=11)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_SLOWBRO (64x48, y=8)
	.byte 0x43, 0x15, 0x00, 0x00  @ SPECIES_MAGNEMITE (32x24, y=21)
	.byte 0x76, 0x08, 0x00, 0x00  @ SPECIES_MAGNETON (56x48, y=8)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_FARFETCHD (48x48, y=9)
	.byte 0x57, 0x05, 0x00, 0x00  @ SPECIES_DODUO (40x56, y=5)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_DODRIO (64x64, y=0)
	.byte 0x76, 0x0A, 0x00, 0x00  @ SPECIES_SEEL (56x48, y=10)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_DEWGONG (64x56, y=7)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_GRIMER (48x40, y=12)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_MUK (64x56, y=4)
	.byte 0x55, 0x10, 0x00, 0x00  @ SPECIES_SHELLDER (40x40, y=16)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_CLOYSTER (64x56, y=5)
	.byte 0x77, 0x06, 0x00, 0x00  @ SPECIES_GASTLY (56x56, y=6)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_HAUNTER (56x56, y=5)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_GENGAR (56x56, y=5)
	.byte 0x78, 0x02, 0x00, 0x00  @ SPECIES_ONIX (56x64, y=2)
	.byte 0x77, 0x07, 0x00, 0x00  @ SPECIES_DROWZEE (56x56, y=7)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_HYPNO (56x56, y=4)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_KRABBY (48x40, y=13)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_KINGLER (64x64, y=3)
	.byte 0x44, 0x13, 0x00, 0x00  @ SPECIES_VOLTORB (32x32, y=19)
	.byte 0x55, 0x0E, 0x00, 0x00  @ SPECIES_ELECTRODE (40x40, y=14)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_EXEGGCUTE (64x56, y=7)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_EXEGGUTOR (64x64, y=0)
	.byte 0x55, 0x0F, 0x00, 0x00  @ SPECIES_CUBONE (40x40, y=15)
	.byte 0x76, 0x0B, 0x00, 0x00  @ SPECIES_MAROWAK (56x48, y=11)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_HITMONLEE (64x56, y=4)
	.byte 0x67, 0x04, 0x00, 0x00  @ SPECIES_HITMONCHAN (48x56, y=4)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_LICKITUNG (64x48, y=8)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_KOFFING (48x48, y=8)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_WEEZING (64x64, y=2)
	.byte 0x76, 0x09, 0x00, 0x00  @ SPECIES_RHYHORN (56x48, y=9)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_RHYDON (64x64, y=2)
	.byte 0x76, 0x09, 0x00, 0x00  @ SPECIES_CHANSEY (56x48, y=9)
	.byte 0x67, 0x07, 0x00, 0x00  @ SPECIES_TANGELA (48x56, y=7)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_KANGASKHAN (64x64, y=0)
	.byte 0x45, 0x0F, 0x00, 0x00  @ SPECIES_HORSEA (32x40, y=15)
	.byte 0x67, 0x07, 0x00, 0x00  @ SPECIES_SEADRA (48x56, y=7)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_GOLDEEN (48x48, y=10)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_SEAKING (56x56, y=4)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_STARYU (48x48, y=10)
	.byte 0x77, 0x06, 0x00, 0x00  @ SPECIES_STARMIE (56x56, y=6)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_MR_MIME (48x48, y=8)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_SCYTHER (64x64, y=0)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_JYNX (56x56, y=4)
	.byte 0x78, 0x02, 0x00, 0x00  @ SPECIES_ELECTABUZZ (56x64, y=2)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_MAGMAR (56x56, y=4)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_PINSIR (56x56, y=4)
	.byte 0x78, 0x00, 0x00, 0x00  @ SPECIES_TAUROS (56x64, y=0)
	.byte 0x67, 0x06, 0x00, 0x00  @ SPECIES_MAGIKARP (48x56, y=6)
	.byte 0x88, 0x08, 0x00, 0x00  @ SPECIES_GYARADOS (64x64, y=8)
	.byte 0x85, 0x0D, 0x00, 0x00  @ SPECIES_LAPRAS (64x40, y=13)
	.byte 0x54, 0x11, 0x00, 0x00  @ SPECIES_DITTO (40x32, y=17)
	.byte 0x56, 0x09, 0x00, 0x00  @ SPECIES_EEVEE (40x48, y=9)
	.byte 0x67, 0x06, 0x00, 0x00  @ SPECIES_VAPOREON (48x56, y=6)
	.byte 0x76, 0x09, 0x00, 0x00  @ SPECIES_JOLTEON (56x48, y=9)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_FLAREON (48x48, y=10)
	.byte 0x55, 0x0D, 0x00, 0x00  @ SPECIES_PORYGON (40x40, y=13)
	.byte 0x45, 0x0F, 0x00, 0x00  @ SPECIES_OMANYTE (32x40, y=15)
	.byte 0x67, 0x07, 0x00, 0x00  @ SPECIES_OMASTAR (48x56, y=7)
	.byte 0x54, 0x11, 0x00, 0x00  @ SPECIES_KABUTO (40x32, y=17)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_KABUTOPS (64x64, y=3)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_AERODACTYL (64x64, y=1)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_SNORLAX (64x56, y=5)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_ARTICUNO (64x64, y=3)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_ZAPDOS (64x56, y=4)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_MOLTRES (64x64, y=0)
	.byte 0x75, 0x0E, 0x00, 0x00  @ SPECIES_DRATINI (56x40, y=14)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_DRAGONAIR (64x56, y=6)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_DRAGONITE (64x64, y=0)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_MEWTWO (64x64, y=0)
	.byte 0x55, 0x0D, 0x00, 0x00  @ SPECIES_MEW (40x40, y=13)
	.byte 0x75, 0x0D, 0x00, 0x00  @ SPECIES_CHIKORITA (56x40, y=13)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_BAYLEEF (56x56, y=4)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_MEGANIUM (64x64, y=0)
	.byte 0x55, 0x0E, 0x00, 0x00  @ SPECIES_CYNDAQUIL (40x40, y=14)
	.byte 0x76, 0x08, 0x00, 0x00  @ SPECIES_QUILAVA (56x48, y=8)
	.byte 0x78, 0x00, 0x00, 0x00  @ SPECIES_TYPHLOSION (56x64, y=0)
	.byte 0x55, 0x0F, 0x00, 0x00  @ SPECIES_TOTODILE (40x40, y=15)
	.byte 0x67, 0x06, 0x00, 0x00  @ SPECIES_CROCONAW (48x56, y=6)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_FERALIGATR (64x64, y=0)
	.byte 0x47, 0x04, 0x00, 0x00  @ SPECIES_SENTRET (32x56, y=4)
	.byte 0x67, 0x07, 0x00, 0x00  @ SPECIES_FURRET (48x56, y=7)
	.byte 0x55, 0x0D, 0x00, 0x00  @ SPECIES_HOOTHOOT (40x40, y=13)
	.byte 0x58, 0x03, 0x00, 0x00  @ SPECIES_NOCTOWL (40x64, y=3)
	.byte 0x56, 0x0C, 0x00, 0x00  @ SPECIES_LEDYBA (40x48, y=12)
	.byte 0x67, 0x04, 0x00, 0x00  @ SPECIES_LEDIAN (48x56, y=4)
	.byte 0x54, 0x13, 0x00, 0x00  @ SPECIES_SPINARAK (40x32, y=19)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_ARIADOS (64x56, y=5)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_CROBAT (64x64, y=0)
	.byte 0x75, 0x10, 0x00, 0x00  @ SPECIES_CHINCHOU (56x40, y=16)
	.byte 0x87, 0x0B, 0x00, 0x00  @ SPECIES_LANTURN (64x56, y=11)
	.byte 0x45, 0x0C, 0x00, 0x00  @ SPECIES_PICHU (32x40, y=12)
	.byte 0x44, 0x14, 0x00, 0x00  @ SPECIES_CLEFFA (32x32, y=20)
	.byte 0x44, 0x12, 0x00, 0x00  @ SPECIES_IGGLYBUFF (32x32, y=18)
	.byte 0x34, 0x14, 0x00, 0x00  @ SPECIES_TOGEPI (24x32, y=20)
	.byte 0x46, 0x09, 0x00, 0x00  @ SPECIES_TOGETIC (32x48, y=9)
	.byte 0x44, 0x14, 0x00, 0x00  @ SPECIES_NATU (32x32, y=20)
	.byte 0x47, 0x07, 0x00, 0x00  @ SPECIES_XATU (32x56, y=7)
	.byte 0x55, 0x10, 0x00, 0x00  @ SPECIES_MAREEP (40x40, y=16)
	.byte 0x56, 0x0A, 0x00, 0x00  @ SPECIES_FLAAFFY (40x48, y=10)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_AMPHAROS (56x56, y=5)
	.byte 0x45, 0x0E, 0x00, 0x00  @ SPECIES_BELLOSSOM (32x40, y=14)
	.byte 0x65, 0x0E, 0x00, 0x00  @ SPECIES_MARILL (48x40, y=14)
	.byte 0x76, 0x09, 0x00, 0x00  @ SPECIES_AZUMARILL (56x48, y=9)
	.byte 0x67, 0x06, 0x00, 0x00  @ SPECIES_SUDOWOODO (48x56, y=6)
	.byte 0x67, 0x06, 0x00, 0x00  @ SPECIES_POLITOED (48x56, y=6)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_HOPPIP (48x48, y=10)
	.byte 0x55, 0x0F, 0x00, 0x00  @ SPECIES_SKIPLOOM (40x40, y=15)
	.byte 0x77, 0x07, 0x00, 0x00  @ SPECIES_JUMPLUFF (56x56, y=7)
	.byte 0x58, 0x03, 0x00, 0x00  @ SPECIES_AIPOM (40x64, y=3)
	.byte 0x44, 0x10, 0x00, 0x00  @ SPECIES_SUNKERN (32x32, y=16)
	.byte 0x56, 0x08, 0x00, 0x00  @ SPECIES_SUNFLORA (40x48, y=8)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_YANMA (64x48, y=10)
	.byte 0x54, 0x10, 0x00, 0x00  @ SPECIES_WOOPER (40x32, y=16)
	.byte 0x77, 0x07, 0x00, 0x00  @ SPECIES_QUAGSIRE (56x56, y=7)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_ESPEON (48x48, y=8)
	.byte 0x67, 0x08, 0x00, 0x00  @ SPECIES_UMBREON (48x56, y=8)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_MURKROW (48x48, y=11)
	.byte 0x58, 0x01, 0x00, 0x00  @ SPECIES_SLOWKING (40x64, y=1)
	.byte 0x55, 0x0C, 0x00, 0x00  @ SPECIES_MISDREAVUS (40x40, y=12)
	.byte 0x35, 0x0F, 0x00, 0x00  @ SPECIES_UNOWN (24x40, y=15)
	.byte 0x77, 0x06, 0x00, 0x00  @ SPECIES_WOBBUFFET (56x56, y=6)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_GIRAFARIG (64x64, y=3)
	.byte 0x56, 0x0A, 0x00, 0x00  @ SPECIES_PINECO (40x48, y=10)
	.byte 0x76, 0x09, 0x00, 0x00  @ SPECIES_FORRETRESS (56x48, y=9)
	.byte 0x74, 0x11, 0x00, 0x00  @ SPECIES_DUNSPARCE (56x32, y=17)
	.byte 0x78, 0x03, 0x00, 0x00  @ SPECIES_GLIGAR (56x64, y=3)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_STEELIX (64x64, y=0)
	.byte 0x55, 0x0D, 0x00, 0x00  @ SPECIES_SNUBBULL (40x40, y=13)
	.byte 0x57, 0x06, 0x00, 0x00  @ SPECIES_GRANBULL (40x56, y=6)
	.byte 0x56, 0x0A, 0x00, 0x00  @ SPECIES_QWILFISH (40x48, y=10)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_SCIZOR (64x64, y=0)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_SHUCKLE (48x48, y=9)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_HERACROSS (64x64, y=3)
	.byte 0x67, 0x05, 0x00, 0x00  @ SPECIES_SNEASEL (48x56, y=5)
	.byte 0x45, 0x0D, 0x00, 0x00  @ SPECIES_TEDDIURSA (32x40, y=13)
	.byte 0x78, 0x01, 0x00, 0x00  @ SPECIES_URSARING (56x64, y=1)
	.byte 0x45, 0x0D, 0x00, 0x00  @ SPECIES_SLUGMA (32x40, y=13)
	.byte 0x57, 0x0D, 0x00, 0x00  @ SPECIES_MAGCARGO (40x56, y=13)
	.byte 0x43, 0x14, 0x00, 0x00  @ SPECIES_SWINUB (32x24, y=20)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_PILOSWINE (48x48, y=8)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_CORSOLA (48x40, y=12)
	.byte 0x55, 0x0E, 0x00, 0x00  @ SPECIES_REMORAID (40x40, y=14)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_OCTILLERY (48x48, y=10)
	.byte 0x56, 0x08, 0x00, 0x00  @ SPECIES_DELIBIRD (40x48, y=8)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_MANTINE (64x64, y=1)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_SKARMORY (64x64, y=0)
	.byte 0x56, 0x0B, 0x00, 0x00  @ SPECIES_HOUNDOUR (40x48, y=11)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_HOUNDOOM (56x56, y=5)
	.byte 0x78, 0x04, 0x00, 0x00  @ SPECIES_KINGDRA (56x64, y=4)
	.byte 0x54, 0x10, 0x00, 0x00  @ SPECIES_PHANPY (40x32, y=16)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_DONPHAN (64x48, y=8)
	.byte 0x55, 0x0F, 0x00, 0x00  @ SPECIES_PORYGON2 (40x40, y=15)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_STANTLER (64x64, y=0)
	.byte 0x77, 0x06, 0x00, 0x00  @ SPECIES_SMEARGLE (56x56, y=6)
	.byte 0x46, 0x09, 0x00, 0x00  @ SPECIES_TYROGUE (32x48, y=9)
	.byte 0x67, 0x05, 0x00, 0x00  @ SPECIES_HITMONTOP (48x56, y=5)
	.byte 0x35, 0x0F, 0x00, 0x00  @ SPECIES_SMOOCHUM (24x40, y=15)
	.byte 0x76, 0x0A, 0x00, 0x00  @ SPECIES_ELEKID (56x48, y=10)
	.byte 0x45, 0x0D, 0x00, 0x00  @ SPECIES_MAGBY (32x40, y=13)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_MILTANK (56x56, y=4)
	.byte 0x77, 0x06, 0x00, 0x00  @ SPECIES_BLISSEY (56x56, y=6)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_RAIKOU (64x64, y=0)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_ENTEI (64x64, y=0)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_SUICUNE (64x64, y=0)
	.byte 0x46, 0x09, 0x00, 0x00  @ SPECIES_LARVITAR (32x48, y=9)
	.byte 0x56, 0x09, 0x00, 0x00  @ SPECIES_PUPITAR (40x48, y=9)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_TYRANITAR (64x64, y=0)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_LUGIA (64x64, y=0)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_HO_OH (64x64, y=0)
	.byte 0x55, 0x0E, 0x00, 0x00  @ SPECIES_CELEBI (40x40, y=14)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_B (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_C (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_D (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_E (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_F (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_G (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_H (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_I (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_J (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_K (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_L (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_M (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_N (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_O (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_P (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_Q (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_R (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_S (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_T (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_U (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_V (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_W (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_X (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_Y (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_OLD_UNOWN_Z (64x56, y=4)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_TREECKO (48x48, y=8)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_GROVYLE (64x56, y=4)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_SCEPTILE (64x64, y=0)
	.byte 0x56, 0x08, 0x00, 0x00  @ SPECIES_TORCHIC (40x48, y=8)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_COMBUSKEN (64x64, y=1)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_BLAZIKEN (64x64, y=0)
	.byte 0x56, 0x0C, 0x00, 0x00  @ SPECIES_MUDKIP (40x48, y=12)
	.byte 0x67, 0x06, 0x00, 0x00  @ SPECIES_MARSHTOMP (48x56, y=6)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_SWAMPERT (64x64, y=0)
	.byte 0x55, 0x0C, 0x00, 0x00  @ SPECIES_POOCHYENA (40x40, y=12)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_MIGHTYENA (64x56, y=4)
	.byte 0x85, 0x0F, 0x00, 0x00  @ SPECIES_ZIGZAGOON (64x40, y=15)
	.byte 0x78, 0x03, 0x00, 0x00  @ SPECIES_LINOONE (56x64, y=3)
	.byte 0x45, 0x0E, 0x00, 0x00  @ SPECIES_WURMPLE (32x40, y=14)
	.byte 0x75, 0x11, 0x00, 0x00  @ SPECIES_SILCOON (56x40, y=17)
	.byte 0x86, 0x09, 0x00, 0x00  @ SPECIES_BEAUTIFLY (64x48, y=9)
	.byte 0x74, 0x10, 0x00, 0x00  @ SPECIES_CASCOON (56x32, y=16)
	.byte 0x86, 0x0F, 0x00, 0x00  @ SPECIES_DUSTOX (64x48, y=15)
	.byte 0x65, 0x0E, 0x00, 0x00  @ SPECIES_LOTAD (48x40, y=14)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_LOMBRE (48x48, y=9)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_LUDICOLO (64x64, y=0)
	.byte 0x46, 0x10, 0x00, 0x00  @ SPECIES_SEEDOT (32x48, y=16)
	.byte 0x56, 0x08, 0x00, 0x00  @ SPECIES_NUZLEAF (40x48, y=8)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_SHIFTRY (64x64, y=2)
	.byte 0x74, 0x12, 0x00, 0x00  @ SPECIES_NINCADA (56x32, y=18)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_NINJASK (64x48, y=10)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_SHEDINJA (48x48, y=10)
	.byte 0x64, 0x10, 0x00, 0x00  @ SPECIES_TAILLOW (48x32, y=16)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_SWELLOW (64x56, y=6)
	.byte 0x54, 0x10, 0x00, 0x00  @ SPECIES_SHROOMISH (40x32, y=16)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_BRELOOM (56x56, y=4)
	.byte 0x68, 0x08, 0x00, 0x00  @ SPECIES_SPINDA (48x64, y=8)
	.byte 0x84, 0x18, 0x00, 0x00  @ SPECIES_WINGULL (64x32, y=24)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_PELIPPER (56x56, y=4)
	.byte 0x65, 0x0F, 0x00, 0x00  @ SPECIES_SURSKIT (48x40, y=15)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_MASQUERAIN (64x64, y=1)
	.byte 0x75, 0x0F, 0x00, 0x00  @ SPECIES_WAILMER (56x40, y=15)
	.byte 0x87, 0x0A, 0x00, 0x00  @ SPECIES_WAILORD (64x56, y=10)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_SKITTY (48x48, y=11)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_DELCATTY (48x48, y=8)
	.byte 0x67, 0x07, 0x00, 0x00  @ SPECIES_KECLEON (48x56, y=7)
	.byte 0x55, 0x10, 0x00, 0x00  @ SPECIES_BALTOY (40x40, y=16)
	.byte 0x78, 0x06, 0x00, 0x00  @ SPECIES_CLAYDOL (56x64, y=6)
	.byte 0x56, 0x0C, 0x00, 0x00  @ SPECIES_NOSEPASS (40x48, y=12)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_TORKOAL (64x64, y=2)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_SABLEYE (48x48, y=9)
	.byte 0x46, 0x0B, 0x00, 0x00  @ SPECIES_BARBOACH (32x48, y=11)
	.byte 0x76, 0x09, 0x00, 0x00  @ SPECIES_WHISCASH (56x48, y=9)
	.byte 0x46, 0x18, 0x00, 0x00  @ SPECIES_LUVDISC (32x48, y=24)
	.byte 0x66, 0x0C, 0x00, 0x00  @ SPECIES_CORPHISH (48x48, y=12)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_CRAWDAUNT (64x64, y=1)
	.byte 0x46, 0x0D, 0x00, 0x00  @ SPECIES_FEEBAS (32x48, y=13)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_MILOTIC (64x64, y=0)
	.byte 0x67, 0x06, 0x00, 0x00  @ SPECIES_CARVANHA (48x56, y=6)
	.byte 0x78, 0x03, 0x00, 0x00  @ SPECIES_SHARPEDO (56x64, y=3)
	.byte 0x54, 0x10, 0x00, 0x00  @ SPECIES_TRAPINCH (40x32, y=16)
	.byte 0x86, 0x0C, 0x00, 0x00  @ SPECIES_VIBRAVA (64x48, y=12)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_FLYGON (64x64, y=1)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_MAKUHITA (48x40, y=12)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_HARIYAMA (64x64, y=1)
	.byte 0x64, 0x12, 0x00, 0x00  @ SPECIES_ELECTRIKE (48x32, y=18)
	.byte 0x67, 0x04, 0x00, 0x00  @ SPECIES_MANECTRIC (48x56, y=4)
	.byte 0x65, 0x0F, 0x00, 0x00  @ SPECIES_NUMEL (48x40, y=15)
	.byte 0x87, 0x09, 0x00, 0x00  @ SPECIES_CAMERUPT (64x56, y=9)
	.byte 0x65, 0x10, 0x00, 0x00  @ SPECIES_SPHEAL (48x40, y=16)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_SEALEO (64x48, y=10)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_WALREIN (64x64, y=1)
	.byte 0x74, 0x10, 0x00, 0x00  @ SPECIES_CACNEA (56x32, y=16)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_CACTURNE (64x64, y=0)
	.byte 0x56, 0x0B, 0x00, 0x00  @ SPECIES_SNORUNT (40x48, y=11)
	.byte 0x76, 0x0A, 0x00, 0x00  @ SPECIES_GLALIE (56x48, y=10)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_LUNATONE (48x48, y=9)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_SOLROCK (64x64, y=1)
	.byte 0x55, 0x0F, 0x00, 0x00  @ SPECIES_AZURILL (40x40, y=15)
	.byte 0x46, 0x09, 0x00, 0x00  @ SPECIES_SPOINK (32x48, y=9)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_GRUMPIG (56x56, y=5)
	.byte 0x56, 0x0E, 0x00, 0x00  @ SPECIES_PLUSLE (40x48, y=14)
	.byte 0x66, 0x0C, 0x00, 0x00  @ SPECIES_MINUN (48x48, y=12)
	.byte 0x76, 0x08, 0x00, 0x00  @ SPECIES_MAWILE (56x48, y=8)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_MEDITITE (48x40, y=12)
	.byte 0x68, 0x01, 0x00, 0x00  @ SPECIES_MEDICHAM (48x64, y=1)
	.byte 0x76, 0x11, 0x00, 0x00  @ SPECIES_SWABLU (56x48, y=17)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_ALTARIA (64x64, y=2)
	.byte 0x55, 0x0C, 0x00, 0x00  @ SPECIES_WYNAUT (40x40, y=12)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_DUSKULL (48x48, y=10)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_DUSCLOPS (56x56, y=5)
	.byte 0x76, 0x08, 0x00, 0x00  @ SPECIES_ROSELIA (56x48, y=8)
	.byte 0x74, 0x12, 0x00, 0x00  @ SPECIES_SLAKOTH (56x32, y=18)
	.byte 0x78, 0x00, 0x00, 0x00  @ SPECIES_VIGOROTH (56x64, y=0)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_SLAKING (64x48, y=8)
	.byte 0x55, 0x12, 0x00, 0x00  @ SPECIES_GULPIN (40x40, y=18)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_SWALOT (48x48, y=8)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_TROPIUS (64x64, y=0)
	.byte 0x55, 0x0E, 0x00, 0x00  @ SPECIES_WHISMUR (40x40, y=14)
	.byte 0x78, 0x03, 0x00, 0x00  @ SPECIES_LOUDRED (56x64, y=3)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_EXPLOUD (64x64, y=1)
	.byte 0x55, 0x0E, 0x00, 0x00  @ SPECIES_CLAMPERL (40x40, y=14)
	.byte 0x78, 0x03, 0x00, 0x00  @ SPECIES_HUNTAIL (56x64, y=3)
	.byte 0x86, 0x0B, 0x00, 0x00  @ SPECIES_GOREBYSS (64x48, y=11)
	.byte 0x68, 0x00, 0x00, 0x00  @ SPECIES_ABSOL (48x64, y=0)
	.byte 0x56, 0x0E, 0x00, 0x00  @ SPECIES_SHUPPET (40x48, y=14)
	.byte 0x55, 0x0C, 0x00, 0x00  @ SPECIES_BANETTE (40x40, y=12)
	.byte 0x77, 0x08, 0x00, 0x00  @ SPECIES_SEVIPER (56x56, y=8)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_ZANGOOSE (64x56, y=5)
	.byte 0x77, 0x0B, 0x00, 0x00  @ SPECIES_RELICANTH (56x56, y=11)
	.byte 0x43, 0x14, 0x00, 0x00  @ SPECIES_ARON (32x24, y=20)
	.byte 0x75, 0x0D, 0x00, 0x00  @ SPECIES_LAIRON (56x40, y=13)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_AGGRON (64x64, y=0)
	.byte 0x34, 0x11, 0x00, 0x00  @ SPECIES_CASTFORM (24x32, y=17)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_VOLBEAT (48x48, y=8)
	.byte 0x56, 0x08, 0x00, 0x00  @ SPECIES_ILLUMISE (40x48, y=8)
	.byte 0x67, 0x07, 0x00, 0x00  @ SPECIES_LILEEP (48x56, y=7)
	.byte 0x78, 0x00, 0x00, 0x00  @ SPECIES_CRADILY (56x64, y=0)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_ANORITH (48x48, y=8)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_ARMALDO (64x64, y=0)
	.byte 0x35, 0x0F, 0x00, 0x00  @ SPECIES_RALTS (24x40, y=15)
	.byte 0x47, 0x06, 0x00, 0x00  @ SPECIES_KIRLIA (32x56, y=6)
	.byte 0x78, 0x01, 0x00, 0x00  @ SPECIES_GARDEVOIR (56x64, y=1)
	.byte 0x56, 0x0B, 0x00, 0x00  @ SPECIES_BAGON (40x48, y=11)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_SHELGON (48x48, y=9)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_SALAMENCE (64x56, y=4)
	.byte 0x55, 0x0F, 0x00, 0x00  @ SPECIES_BELDUM (40x40, y=15)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_METANG (64x56, y=7)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_METAGROSS (64x56, y=6)
	.byte 0x78, 0x04, 0x00, 0x00  @ SPECIES_REGIROCK (56x64, y=4)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_REGICE (64x64, y=2)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_REGISTEEL (64x64, y=3)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_KYOGRE (64x56, y=4)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_GROUDON (64x64, y=1)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_RAYQUAZA (64x64, y=0)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_LATIAS (64x64, y=1)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_LATIOS (64x64, y=2)
	.byte 0x66, 0x0D, 0x00, 0x00  @ SPECIES_JIRACHI (48x48, y=13)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_DEOXYS (64x64, y=1)
	.byte 0x37, 0x06, 0x00, 0x00  @ SPECIES_CHIMECHO (24x56, y=6)
	.byte 0x33, 0x14, 0x00, 0x00  @ SPECIES_EGG (24x24, y=20)
	.byte 0x34, 0x10, 0x00, 0x00  @ SPECIES_UNUSED_413 (24x32, y=16)
	.byte 0x44, 0x10, 0x00, 0x00  @ SPECIES_UNUSED_414 (32x32, y=16)
	.byte 0x44, 0x10, 0x00, 0x00  @ SPECIES_UNUSED_415 (32x32, y=16)
	.byte 0x44, 0x11, 0x00, 0x00  @ SPECIES_UNUSED_416 (32x32, y=17)
	.byte 0x44, 0x11, 0x00, 0x00  @ SPECIES_UNUSED_417 (32x32, y=17)
	.byte 0x35, 0x0E, 0x00, 0x00  @ SPECIES_UNUSED_418 (24x40, y=14)
	.byte 0x44, 0x10, 0x00, 0x00  @ SPECIES_UNUSED_419 (32x32, y=16)
	.byte 0x34, 0x10, 0x00, 0x00  @ SPECIES_UNUSED_420 (24x32, y=16)
	.byte 0x34, 0x11, 0x00, 0x00  @ SPECIES_UNUSED_421 (24x32, y=17)
	.byte 0x44, 0x11, 0x00, 0x00  @ SPECIES_UNUSED_422 (32x32, y=17)
	.byte 0x34, 0x13, 0x00, 0x00  @ SPECIES_UNUSED_423 (24x32, y=19)
	.byte 0x44, 0x13, 0x00, 0x00  @ SPECIES_UNUSED_424 (32x32, y=19)
	.byte 0x43, 0x14, 0x00, 0x00  @ SPECIES_UNUSED_425 (32x24, y=20)
	.byte 0x44, 0x10, 0x00, 0x00  @ SPECIES_UNUSED_426 (32x32, y=16)
	.byte 0x34, 0x13, 0x00, 0x00  @ SPECIES_UNUSED_427 (24x32, y=19)
	.byte 0x43, 0x15, 0x00, 0x00  @ SPECIES_UNUSED_428 (32x24, y=21)
	.byte 0x34, 0x13, 0x00, 0x00  @ SPECIES_UNUSED_429 (24x32, y=19)
	.byte 0x45, 0x0C, 0x00, 0x00  @ SPECIES_UNUSED_430 (32x40, y=12)
	.byte 0x34, 0x12, 0x00, 0x00  @ SPECIES_UNUSED_431 (24x32, y=18)
	.byte 0x44, 0x12, 0x00, 0x00  @ SPECIES_UNUSED_432 (32x32, y=18)
	.byte 0x44, 0x12, 0x00, 0x00  @ SPECIES_UNUSED_433 (32x32, y=18)
	.byte 0x44, 0x13, 0x00, 0x00  @ SPECIES_UNUSED_434 (32x32, y=19)
	.byte 0x33, 0x15, 0x00, 0x00  @ SPECIES_UNUSED_435 (24x24, y=21)
	.byte 0x34, 0x11, 0x00, 0x00  @ SPECIES_UNUSED_436 (24x32, y=17)
	.byte 0x34, 0x10, 0x00, 0x00  @ SPECIES_UNUSED_437 (24x32, y=16)
	.byte 0x35, 0x0F, 0x00, 0x00  @ SPECIES_UNUSED_438 (24x40, y=15)
	.byte 0x35, 0x0D, 0x00, 0x00  @ SPECIES_UNUSED_439 (24x40, y=13)

	.globl gUnknown_82D4CA8
gUnknown_82D4CA8: @ 0x82D4CA8
	.incbin "baserom_jp.gba", 0x2d4ca8, 0xdc0

	.globl gMonBackPicCoords
gMonBackPicCoords: @ 0x82D5A68
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_NONE (64x64, y=0)
	.byte 0x64, 0x10, 0x00, 0x00  @ SPECIES_BULBASAUR (48x32, y=16)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_IVYSAUR (48x48, y=9)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_VENUSAUR (64x56, y=7)
	.byte 0x65, 0x0E, 0x00, 0x00  @ SPECIES_CHARMANDER (48x40, y=14)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_CHARMELEON (48x48, y=9)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_CHARIZARD (64x56, y=4)
	.byte 0x65, 0x0E, 0x00, 0x00  @ SPECIES_SQUIRTLE (48x40, y=14)
	.byte 0x76, 0x0A, 0x00, 0x00  @ SPECIES_WARTORTLE (56x48, y=10)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_BLASTOISE (64x48, y=8)
	.byte 0x55, 0x0F, 0x00, 0x00  @ SPECIES_CATERPIE (40x40, y=15)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_METAPOD (48x40, y=12)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_BUTTERFREE (64x56, y=6)
	.byte 0x56, 0x0B, 0x00, 0x00  @ SPECIES_WEEDLE (40x48, y=11)
	.byte 0x46, 0x0A, 0x00, 0x00  @ SPECIES_KAKUNA (32x48, y=10)
	.byte 0x86, 0x09, 0x00, 0x00  @ SPECIES_BEEDRILL (64x48, y=9)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_PIDGEY (48x48, y=8)
	.byte 0x85, 0x0C, 0x00, 0x00  @ SPECIES_PIDGEOTTO (64x40, y=12)
	.byte 0x78, 0x02, 0x00, 0x00  @ SPECIES_PIDGEOT (56x64, y=2)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_RATTATA (48x40, y=13)
	.byte 0x75, 0x0D, 0x00, 0x00  @ SPECIES_RATICATE (56x40, y=13)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_SPEAROW (48x40, y=12)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_FEAROW (64x56, y=5)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_EKANS (48x48, y=9)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_ARBOK (56x56, y=4)
	.byte 0x77, 0x07, 0x00, 0x00  @ SPECIES_PIKACHU (56x56, y=7)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_RAICHU (48x48, y=8)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_SANDSHREW (48x40, y=13)
	.byte 0x86, 0x09, 0x00, 0x00  @ SPECIES_SANDSLASH (64x48, y=9)
	.byte 0x55, 0x0C, 0x00, 0x00  @ SPECIES_NIDORAN_F (40x40, y=12)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_NIDORINA (64x48, y=10)
	.byte 0x77, 0x06, 0x00, 0x00  @ SPECIES_NIDOQUEEN (56x56, y=6)
	.byte 0x56, 0x08, 0x00, 0x00  @ SPECIES_NIDORAN_M (40x48, y=8)
	.byte 0x86, 0x09, 0x00, 0x00  @ SPECIES_NIDORINO (64x48, y=9)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_NIDOKING (64x64, y=3)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_CLEFAIRY (48x40, y=13)
	.byte 0x76, 0x0A, 0x00, 0x00  @ SPECIES_CLEFABLE (56x48, y=10)
	.byte 0x76, 0x09, 0x00, 0x00  @ SPECIES_VULPIX (56x48, y=9)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_NINETALES (56x56, y=5)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_JIGGLYPUFF (48x40, y=13)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_WIGGLYTUFF (48x48, y=8)
	.byte 0x76, 0x0B, 0x00, 0x00  @ SPECIES_ZUBAT (56x48, y=11)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_GOLBAT (64x56, y=6)
	.byte 0x56, 0x0B, 0x00, 0x00  @ SPECIES_ODDISH (40x48, y=11)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_GLOOM (48x48, y=10)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_VILEPLUME (64x56, y=7)
	.byte 0x63, 0x14, 0x00, 0x00  @ SPECIES_PARAS (48x24, y=20)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_PARASECT (64x56, y=7)
	.byte 0x77, 0x06, 0x00, 0x00  @ SPECIES_VENONAT (56x56, y=6)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_VENOMOTH (56x56, y=4)
	.byte 0x54, 0x10, 0x00, 0x00  @ SPECIES_DIGLETT (40x32, y=16)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_DUGTRIO (48x48, y=11)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_MEOWTH (48x40, y=12)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_PERSIAN (64x56, y=7)
	.byte 0x67, 0x07, 0x00, 0x00  @ SPECIES_PSYDUCK (48x56, y=7)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_GOLDUCK (56x56, y=5)
	.byte 0x76, 0x0B, 0x00, 0x00  @ SPECIES_MANKEY (56x48, y=11)
	.byte 0x77, 0x07, 0x00, 0x00  @ SPECIES_PRIMEAPE (56x56, y=7)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_GROWLITHE (48x48, y=8)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_ARCANINE (64x56, y=6)
	.byte 0x74, 0x10, 0x00, 0x00  @ SPECIES_POLIWAG (56x32, y=16)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_POLIWHIRL (48x40, y=12)
	.byte 0x86, 0x0B, 0x00, 0x00  @ SPECIES_POLIWRATH (64x48, y=11)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_ABRA (48x48, y=11)
	.byte 0x76, 0x08, 0x00, 0x00  @ SPECIES_KADABRA (56x48, y=8)
	.byte 0x67, 0x05, 0x00, 0x00  @ SPECIES_ALAKAZAM (48x56, y=5)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_MACHOP (48x40, y=12)
	.byte 0x76, 0x09, 0x00, 0x00  @ SPECIES_MACHOKE (56x48, y=9)
	.byte 0x67, 0x04, 0x00, 0x00  @ SPECIES_MACHAMP (48x56, y=4)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_BELLSPROUT (48x48, y=10)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_WEEPINBELL (48x48, y=9)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_VICTREEBEL (64x56, y=6)
	.byte 0x56, 0x0A, 0x00, 0x00  @ SPECIES_TENTACOOL (40x48, y=10)
	.byte 0x86, 0x0B, 0x00, 0x00  @ SPECIES_TENTACRUEL (64x48, y=11)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_GEODUDE (48x48, y=11)
	.byte 0x75, 0x0C, 0x00, 0x00  @ SPECIES_GRAVELER (56x40, y=12)
	.byte 0x84, 0x10, 0x00, 0x00  @ SPECIES_GOLEM (64x32, y=16)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_PONYTA (48x48, y=9)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_RAPIDASH (64x56, y=5)
	.byte 0x85, 0x0E, 0x00, 0x00  @ SPECIES_SLOWPOKE (64x40, y=14)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_SLOWBRO (64x48, y=10)
	.byte 0x43, 0x14, 0x00, 0x00  @ SPECIES_MAGNEMITE (32x24, y=20)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_MAGNETON (48x48, y=10)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_FARFETCHD (48x48, y=10)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_DODUO (48x48, y=8)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_DODRIO (64x64, y=1)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_SEEL (48x48, y=10)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_DEWGONG (56x56, y=5)
	.byte 0x75, 0x0C, 0x00, 0x00  @ SPECIES_GRIMER (56x40, y=12)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_MUK (64x56, y=5)
	.byte 0x76, 0x0B, 0x00, 0x00  @ SPECIES_SHELLDER (56x48, y=11)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_CLOYSTER (64x56, y=6)
	.byte 0x85, 0x0E, 0x00, 0x00  @ SPECIES_GASTLY (64x40, y=14)
	.byte 0x76, 0x08, 0x00, 0x00  @ SPECIES_HAUNTER (56x48, y=8)
	.byte 0x76, 0x09, 0x00, 0x00  @ SPECIES_GENGAR (56x48, y=9)
	.byte 0x78, 0x00, 0x00, 0x00  @ SPECIES_ONIX (56x64, y=0)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_DROWZEE (48x40, y=13)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_HYPNO (48x48, y=9)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_KRABBY (48x48, y=10)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_KINGLER (56x56, y=4)
	.byte 0x55, 0x0E, 0x00, 0x00  @ SPECIES_VOLTORB (40x40, y=14)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_ELECTRODE (48x40, y=13)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_EXEGGCUTE (48x40, y=13)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_EXEGGUTOR (64x56, y=4)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_CUBONE (48x48, y=10)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_MAROWAK (48x48, y=8)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_HITMONLEE (48x40, y=12)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_HITMONCHAN (48x40, y=12)
	.byte 0x65, 0x0E, 0x00, 0x00  @ SPECIES_LICKITUNG (48x40, y=14)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_KOFFING (48x48, y=9)
	.byte 0x77, 0x06, 0x00, 0x00  @ SPECIES_WEEZING (56x56, y=6)
	.byte 0x85, 0x0C, 0x00, 0x00  @ SPECIES_RHYHORN (64x40, y=12)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_RHYDON (64x64, y=3)
	.byte 0x86, 0x0B, 0x00, 0x00  @ SPECIES_CHANSEY (64x48, y=11)
	.byte 0x85, 0x0E, 0x00, 0x00  @ SPECIES_TANGELA (64x40, y=14)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_KANGASKHAN (56x56, y=5)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_HORSEA (48x48, y=9)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_SEADRA (48x48, y=8)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_GOLDEEN (48x48, y=8)
	.byte 0x76, 0x0B, 0x00, 0x00  @ SPECIES_SEAKING (56x48, y=11)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_STARYU (48x40, y=13)
	.byte 0x85, 0x0E, 0x00, 0x00  @ SPECIES_STARMIE (64x40, y=14)
	.byte 0x85, 0x0D, 0x00, 0x00  @ SPECIES_MR_MIME (64x40, y=13)
	.byte 0x77, 0x07, 0x00, 0x00  @ SPECIES_SCYTHER (56x56, y=7)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_JYNX (64x48, y=10)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_ELECTABUZZ (48x48, y=8)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_MAGMAR (48x48, y=8)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_PINSIR (48x48, y=9)
	.byte 0x85, 0x0D, 0x00, 0x00  @ SPECIES_TAUROS (64x40, y=13)
	.byte 0x76, 0x09, 0x00, 0x00  @ SPECIES_MAGIKARP (56x48, y=9)
	.byte 0x78, 0x00, 0x00, 0x00  @ SPECIES_GYARADOS (56x64, y=0)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_LAPRAS (56x56, y=4)
	.byte 0x54, 0x11, 0x00, 0x00  @ SPECIES_DITTO (40x32, y=17)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_EEVEE (48x48, y=10)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_VAPOREON (48x48, y=10)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_JOLTEON (64x56, y=6)
	.byte 0x67, 0x05, 0x00, 0x00  @ SPECIES_FLAREON (48x56, y=5)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_PORYGON (48x40, y=13)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_OMANYTE (48x48, y=10)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_OMASTAR (48x48, y=8)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_KABUTO (48x40, y=13)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_KABUTOPS (56x56, y=5)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_AERODACTYL (64x48, y=8)
	.byte 0x86, 0x0B, 0x00, 0x00  @ SPECIES_SNORLAX (64x48, y=11)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_ARTICUNO (48x40, y=12)
	.byte 0x76, 0x0B, 0x00, 0x00  @ SPECIES_ZAPDOS (56x48, y=11)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_MOLTRES (64x56, y=4)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_DRATINI (48x48, y=9)
	.byte 0x78, 0x00, 0x00, 0x00  @ SPECIES_DRAGONAIR (56x64, y=0)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_DRAGONITE (64x56, y=6)
	.byte 0x78, 0x01, 0x00, 0x00  @ SPECIES_MEWTWO (56x64, y=1)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_MEW (48x48, y=8)
	.byte 0x56, 0x0A, 0x00, 0x00  @ SPECIES_CHIKORITA (40x48, y=10)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_BAYLEEF (48x48, y=8)
	.byte 0x78, 0x00, 0x00, 0x00  @ SPECIES_MEGANIUM (56x64, y=0)
	.byte 0x76, 0x09, 0x00, 0x00  @ SPECIES_CYNDAQUIL (56x48, y=9)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_QUILAVA (64x56, y=4)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_TYPHLOSION (64x56, y=4)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_TOTODILE (48x48, y=11)
	.byte 0x67, 0x07, 0x00, 0x00  @ SPECIES_CROCONAW (48x56, y=7)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_FERALIGATR (64x64, y=1)
	.byte 0x67, 0x05, 0x00, 0x00  @ SPECIES_SENTRET (48x56, y=5)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_FURRET (48x48, y=8)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_HOOTHOOT (48x48, y=8)
	.byte 0x68, 0x03, 0x00, 0x00  @ SPECIES_NOCTOWL (48x64, y=3)
	.byte 0x76, 0x0B, 0x00, 0x00  @ SPECIES_LEDYBA (56x48, y=11)
	.byte 0x77, 0x07, 0x00, 0x00  @ SPECIES_LEDIAN (56x56, y=7)
	.byte 0x73, 0x15, 0x00, 0x00  @ SPECIES_SPINARAK (56x24, y=21)
	.byte 0x86, 0x0B, 0x00, 0x00  @ SPECIES_ARIADOS (64x48, y=11)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_CROBAT (64x56, y=5)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_CHINCHOU (64x48, y=8)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_LANTURN (64x48, y=8)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_PICHU (48x48, y=11)
	.byte 0x65, 0x0F, 0x00, 0x00  @ SPECIES_CLEFFA (48x40, y=15)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_IGGLYBUFF (48x48, y=11)
	.byte 0x54, 0x10, 0x00, 0x00  @ SPECIES_TOGEPI (40x32, y=16)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_TOGETIC (48x48, y=8)
	.byte 0x54, 0x11, 0x00, 0x00  @ SPECIES_NATU (40x32, y=17)
	.byte 0x76, 0x08, 0x00, 0x00  @ SPECIES_XATU (56x48, y=8)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_MAREEP (48x48, y=9)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_FLAAFFY (48x48, y=9)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_AMPHAROS (64x64, y=1)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_BELLOSSOM (48x48, y=11)
	.byte 0x75, 0x0C, 0x00, 0x00  @ SPECIES_MARILL (56x40, y=12)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_AZUMARILL (64x48, y=8)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_SUDOWOODO (48x48, y=8)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_POLITOED (48x48, y=9)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_HOPPIP (48x48, y=11)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_SKIPLOOM (48x40, y=13)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_JUMPLUFF (64x56, y=4)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_AIPOM (48x48, y=9)
	.byte 0x56, 0x0A, 0x00, 0x00  @ SPECIES_SUNKERN (40x48, y=10)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_SUNFLORA (48x48, y=8)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_YANMA (56x56, y=4)
	.byte 0x85, 0x0F, 0x00, 0x00  @ SPECIES_WOOPER (64x40, y=15)
	.byte 0x76, 0x08, 0x00, 0x00  @ SPECIES_QUAGSIRE (56x48, y=8)
	.byte 0x76, 0x0B, 0x00, 0x00  @ SPECIES_ESPEON (56x48, y=11)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_UMBREON (64x56, y=4)
	.byte 0x66, 0x09, 0x00, 0x00  @ SPECIES_MURKROW (48x48, y=9)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_SLOWKING (48x48, y=8)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_MISDREAVUS (48x48, y=10)
	.byte 0x36, 0x08, 0x00, 0x00  @ SPECIES_UNOWN (24x48, y=8)
	.byte 0x75, 0x0C, 0x00, 0x00  @ SPECIES_WOBBUFFET (56x40, y=12)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_GIRAFARIG (64x56, y=5)
	.byte 0x65, 0x0F, 0x00, 0x00  @ SPECIES_PINECO (48x40, y=15)
	.byte 0x84, 0x10, 0x00, 0x00  @ SPECIES_FORRETRESS (64x32, y=16)
	.byte 0x85, 0x0F, 0x00, 0x00  @ SPECIES_DUNSPARCE (64x40, y=15)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_GLIGAR (64x56, y=5)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_STEELIX (64x64, y=0)
	.byte 0x76, 0x0A, 0x00, 0x00  @ SPECIES_SNUBBULL (56x48, y=10)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_GRANBULL (64x56, y=5)
	.byte 0x77, 0x07, 0x00, 0x00  @ SPECIES_QWILFISH (56x56, y=7)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_SCIZOR (56x56, y=4)
	.byte 0x56, 0x0B, 0x00, 0x00  @ SPECIES_SHUCKLE (40x48, y=11)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_HERACROSS (56x56, y=4)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_SNEASEL (48x48, y=8)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_TEDDIURSA (48x48, y=8)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_URSARING (64x64, y=3)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_SLUGMA (48x48, y=8)
	.byte 0x76, 0x09, 0x00, 0x00  @ SPECIES_MAGCARGO (56x48, y=9)
	.byte 0x63, 0x15, 0x00, 0x00  @ SPECIES_SWINUB (48x24, y=21)
	.byte 0x75, 0x0D, 0x00, 0x00  @ SPECIES_PILOSWINE (56x40, y=13)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_CORSOLA (48x40, y=12)
	.byte 0x75, 0x0D, 0x00, 0x00  @ SPECIES_REMORAID (56x40, y=13)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_OCTILLERY (48x48, y=10)
	.byte 0x67, 0x06, 0x00, 0x00  @ SPECIES_DELIBIRD (48x56, y=6)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_MANTINE (64x56, y=7)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_SKARMORY (64x56, y=4)
	.byte 0x55, 0x0C, 0x00, 0x00  @ SPECIES_HOUNDOUR (40x40, y=12)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_HOUNDOOM (64x56, y=7)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_KINGDRA (64x56, y=6)
	.byte 0x65, 0x0E, 0x00, 0x00  @ SPECIES_PHANPY (48x40, y=14)
	.byte 0x85, 0x0D, 0x00, 0x00  @ SPECIES_DONPHAN (64x40, y=13)
	.byte 0x76, 0x0A, 0x00, 0x00  @ SPECIES_PORYGON2 (56x48, y=10)
	.byte 0x78, 0x03, 0x00, 0x00  @ SPECIES_STANTLER (56x64, y=3)
	.byte 0x76, 0x0A, 0x00, 0x00  @ SPECIES_SMEARGLE (56x48, y=10)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_TYROGUE (48x48, y=8)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_HITMONTOP (64x56, y=5)
	.byte 0x56, 0x09, 0x00, 0x00  @ SPECIES_SMOOCHUM (40x48, y=9)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_ELEKID (48x48, y=8)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_MAGBY (48x48, y=11)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_MILTANK (64x56, y=7)
	.byte 0x85, 0x0D, 0x00, 0x00  @ SPECIES_BLISSEY (64x40, y=13)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_RAIKOU (64x48, y=10)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_ENTEI (64x56, y=6)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_SUICUNE (64x64, y=3)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_LARVITAR (48x48, y=8)
	.byte 0x67, 0x05, 0x00, 0x00  @ SPECIES_PUPITAR (48x56, y=5)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_TYRANITAR (64x64, y=0)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_LUGIA (64x64, y=1)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_HO_OH (64x64, y=1)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_CELEBI (48x48, y=8)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_B (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_C (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_D (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_E (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_F (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_G (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_H (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_I (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_J (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_K (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_L (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_M (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_N (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_O (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_P (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_Q (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_R (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_S (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_T (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_U (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_V (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_W (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_X (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_Y (64x64, y=2)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_OLD_UNOWN_Z (64x64, y=2)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_TREECKO (64x56, y=6)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_GROVYLE (64x48, y=8)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_SCEPTILE (64x64, y=1)
	.byte 0x67, 0x05, 0x00, 0x00  @ SPECIES_TORCHIC (48x56, y=5)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_COMBUSKEN (64x64, y=0)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_BLAZIKEN (64x64, y=0)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_MUDKIP (56x56, y=5)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_MARSHTOMP (64x56, y=4)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_SWAMPERT (64x56, y=5)
	.byte 0x76, 0x09, 0x00, 0x00  @ SPECIES_POOCHYENA (56x48, y=9)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_MIGHTYENA (64x56, y=4)
	.byte 0x76, 0x0B, 0x00, 0x00  @ SPECIES_ZIGZAGOON (56x48, y=11)
	.byte 0x85, 0x0F, 0x00, 0x00  @ SPECIES_LINOONE (64x40, y=15)
	.byte 0x76, 0x0B, 0x00, 0x00  @ SPECIES_WURMPLE (56x48, y=11)
	.byte 0x83, 0x15, 0x00, 0x00  @ SPECIES_SILCOON (64x24, y=21)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_BEAUTIFLY (64x64, y=0)
	.byte 0x73, 0x14, 0x00, 0x00  @ SPECIES_CASCOON (56x24, y=20)
	.byte 0x83, 0x14, 0x00, 0x00  @ SPECIES_DUSTOX (64x24, y=20)
	.byte 0x75, 0x0F, 0x00, 0x00  @ SPECIES_LOTAD (56x40, y=15)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_LOMBRE (64x48, y=8)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_LUDICOLO (64x48, y=10)
	.byte 0x86, 0x09, 0x00, 0x00  @ SPECIES_SEEDOT (64x48, y=9)
	.byte 0x76, 0x0A, 0x00, 0x00  @ SPECIES_NUZLEAF (56x48, y=10)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_SHIFTRY (64x48, y=8)
	.byte 0x83, 0x14, 0x00, 0x00  @ SPECIES_NINCADA (64x24, y=20)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_NINJASK (64x48, y=8)
	.byte 0x77, 0x06, 0x00, 0x00  @ SPECIES_SHEDINJA (56x56, y=6)
	.byte 0x64, 0x11, 0x00, 0x00  @ SPECIES_TAILLOW (48x32, y=17)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_SWELLOW (64x48, y=8)
	.byte 0x85, 0x0D, 0x00, 0x00  @ SPECIES_SHROOMISH (64x40, y=13)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_BRELOOM (64x56, y=4)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_SPINDA (56x56, y=4)
	.byte 0x85, 0x0E, 0x00, 0x00  @ SPECIES_WINGULL (64x40, y=14)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_PELIPPER (64x56, y=6)
	.byte 0x86, 0x0B, 0x00, 0x00  @ SPECIES_SURSKIT (64x48, y=11)
	.byte 0x88, 0x00, 0x00, 0x00  @ SPECIES_MASQUERAIN (64x64, y=0)
	.byte 0x83, 0x15, 0x00, 0x00  @ SPECIES_WAILMER (64x24, y=21)
	.byte 0x83, 0x16, 0x00, 0x00  @ SPECIES_WAILORD (64x24, y=22)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_SKITTY (64x48, y=10)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_DELCATTY (64x48, y=8)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_KECLEON (64x56, y=6)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_BALTOY (64x48, y=8)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_CLAYDOL (64x56, y=7)
	.byte 0x85, 0x0C, 0x00, 0x00  @ SPECIES_NOSEPASS (64x40, y=12)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_TORKOAL (64x48, y=10)
	.byte 0x76, 0x08, 0x00, 0x00  @ SPECIES_SABLEYE (56x48, y=8)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_BARBOACH (48x48, y=10)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_WHISCASH (64x48, y=10)
	.byte 0x46, 0x0A, 0x00, 0x00  @ SPECIES_LUVDISC (32x48, y=10)
	.byte 0x77, 0x07, 0x00, 0x00  @ SPECIES_CORPHISH (56x56, y=7)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_CRAWDAUNT (64x56, y=5)
	.byte 0x67, 0x07, 0x00, 0x00  @ SPECIES_FEEBAS (48x56, y=7)
	.byte 0x68, 0x02, 0x00, 0x00  @ SPECIES_MILOTIC (48x64, y=2)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_CARVANHA (64x56, y=7)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_SHARPEDO (64x64, y=2)
	.byte 0x75, 0x0E, 0x00, 0x00  @ SPECIES_TRAPINCH (56x40, y=14)
	.byte 0x74, 0x11, 0x00, 0x00  @ SPECIES_VIBRAVA (56x32, y=17)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_FLYGON (64x64, y=2)
	.byte 0x76, 0x0B, 0x00, 0x00  @ SPECIES_MAKUHITA (56x48, y=11)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_HARIYAMA (64x56, y=7)
	.byte 0x84, 0x10, 0x00, 0x00  @ SPECIES_ELECTRIKE (64x32, y=16)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_MANECTRIC (64x56, y=4)
	.byte 0x86, 0x0B, 0x00, 0x00  @ SPECIES_NUMEL (64x48, y=11)
	.byte 0x84, 0x13, 0x00, 0x00  @ SPECIES_CAMERUPT (64x32, y=19)
	.byte 0x64, 0x12, 0x00, 0x00  @ SPECIES_SPHEAL (48x32, y=18)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_SEALEO (64x48, y=10)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_WALREIN (64x56, y=6)
	.byte 0x85, 0x0F, 0x00, 0x00  @ SPECIES_CACNEA (64x40, y=15)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_CACTURNE (64x56, y=7)
	.byte 0x76, 0x0A, 0x00, 0x00  @ SPECIES_SNORUNT (56x48, y=10)
	.byte 0x85, 0x0C, 0x00, 0x00  @ SPECIES_GLALIE (64x40, y=12)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_LUNATONE (64x56, y=5)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_SOLROCK (64x56, y=5)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_AZURILL (64x48, y=10)
	.byte 0x56, 0x0B, 0x00, 0x00  @ SPECIES_SPOINK (40x48, y=11)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_GRUMPIG (64x56, y=4)
	.byte 0x76, 0x08, 0x00, 0x00  @ SPECIES_PLUSLE (56x48, y=8)
	.byte 0x76, 0x08, 0x00, 0x00  @ SPECIES_MINUN (56x48, y=8)
	.byte 0x87, 0x04, 0x00, 0x00  @ SPECIES_MAWILE (64x56, y=4)
	.byte 0x76, 0x0B, 0x00, 0x00  @ SPECIES_MEDITITE (56x48, y=11)
	.byte 0x68, 0x03, 0x00, 0x00  @ SPECIES_MEDICHAM (48x64, y=3)
	.byte 0x86, 0x09, 0x00, 0x00  @ SPECIES_SWABLU (64x48, y=9)
	.byte 0x87, 0x06, 0x00, 0x00  @ SPECIES_ALTARIA (64x56, y=6)
	.byte 0x77, 0x07, 0x00, 0x00  @ SPECIES_WYNAUT (56x56, y=7)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_DUSKULL (48x48, y=11)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_DUSCLOPS (64x48, y=8)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_ROSELIA (64x48, y=8)
	.byte 0x85, 0x0F, 0x00, 0x00  @ SPECIES_SLAKOTH (64x40, y=15)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_VIGOROTH (64x48, y=10)
	.byte 0x86, 0x08, 0x00, 0x00  @ SPECIES_SLAKING (64x48, y=8)
	.byte 0x66, 0x0B, 0x00, 0x00  @ SPECIES_GULPIN (48x48, y=11)
	.byte 0x77, 0x06, 0x00, 0x00  @ SPECIES_SWALOT (56x56, y=6)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_TROPIUS (64x56, y=7)
	.byte 0x85, 0x0D, 0x00, 0x00  @ SPECIES_WHISMUR (64x40, y=13)
	.byte 0x86, 0x09, 0x00, 0x00  @ SPECIES_LOUDRED (64x48, y=9)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_EXPLOUD (64x64, y=3)
	.byte 0x85, 0x0D, 0x00, 0x00  @ SPECIES_CLAMPERL (64x40, y=13)
	.byte 0x68, 0x02, 0x00, 0x00  @ SPECIES_HUNTAIL (48x64, y=2)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_GOREBYSS (56x56, y=5)
	.byte 0x78, 0x03, 0x00, 0x00  @ SPECIES_ABSOL (56x64, y=3)
	.byte 0x77, 0x06, 0x00, 0x00  @ SPECIES_SHUPPET (56x56, y=6)
	.byte 0x65, 0x0C, 0x00, 0x00  @ SPECIES_BANETTE (48x40, y=12)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_SEVIPER (64x64, y=3)
	.byte 0x88, 0x01, 0x00, 0x00  @ SPECIES_ZANGOOSE (64x64, y=1)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_RELICANTH (64x48, y=10)
	.byte 0x54, 0x11, 0x00, 0x00  @ SPECIES_ARON (40x32, y=17)
	.byte 0x84, 0x11, 0x00, 0x00  @ SPECIES_LAIRON (64x32, y=17)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_AGGRON (64x56, y=7)
	.byte 0x45, 0x0D, 0x00, 0x00  @ SPECIES_CASTFORM (32x40, y=13)
	.byte 0x76, 0x08, 0x00, 0x00  @ SPECIES_VOLBEAT (56x48, y=8)
	.byte 0x67, 0x06, 0x00, 0x00  @ SPECIES_ILLUMISE (48x56, y=6)
	.byte 0x86, 0x09, 0x00, 0x00  @ SPECIES_LILEEP (64x48, y=9)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_CRADILY (56x56, y=4)
	.byte 0x83, 0x17, 0x00, 0x00  @ SPECIES_ANORITH (64x24, y=23)
	.byte 0x77, 0x05, 0x00, 0x00  @ SPECIES_ARMALDO (56x56, y=5)
	.byte 0x45, 0x0D, 0x00, 0x00  @ SPECIES_RALTS (32x40, y=13)
	.byte 0x57, 0x06, 0x00, 0x00  @ SPECIES_KIRLIA (40x56, y=6)
	.byte 0x77, 0x04, 0x00, 0x00  @ SPECIES_GARDEVOIR (56x56, y=4)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_BAGON (48x48, y=8)
	.byte 0x85, 0x0D, 0x00, 0x00  @ SPECIES_SHELGON (64x40, y=13)
	.byte 0x77, 0x06, 0x00, 0x00  @ SPECIES_SALAMENCE (56x56, y=6)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_BELDUM (48x48, y=10)
	.byte 0x84, 0x10, 0x00, 0x00  @ SPECIES_METANG (64x32, y=16)
	.byte 0x83, 0x14, 0x00, 0x00  @ SPECIES_METAGROSS (64x24, y=20)
	.byte 0x86, 0x0A, 0x00, 0x00  @ SPECIES_REGIROCK (64x48, y=10)
	.byte 0x85, 0x0E, 0x00, 0x00  @ SPECIES_REGICE (64x40, y=14)
	.byte 0x85, 0x0E, 0x00, 0x00  @ SPECIES_REGISTEEL (64x40, y=14)
	.byte 0x84, 0x13, 0x00, 0x00  @ SPECIES_KYOGRE (64x32, y=19)
	.byte 0x87, 0x07, 0x00, 0x00  @ SPECIES_GROUDON (64x56, y=7)
	.byte 0x78, 0x00, 0x00, 0x00  @ SPECIES_RAYQUAZA (56x64, y=0)
	.byte 0x88, 0x02, 0x00, 0x00  @ SPECIES_LATIAS (64x64, y=2)
	.byte 0x88, 0x03, 0x00, 0x00  @ SPECIES_LATIOS (64x64, y=3)
	.byte 0x87, 0x05, 0x00, 0x00  @ SPECIES_JIRACHI (64x56, y=5)
	.byte 0x86, 0x09, 0x00, 0x00  @ SPECIES_DEOXYS (64x48, y=9)
	.byte 0x47, 0x07, 0x00, 0x00  @ SPECIES_CHIMECHO (32x56, y=7)
	.byte 0x36, 0x0A, 0x00, 0x00  @ SPECIES_EGG (24x48, y=10)
	.byte 0x56, 0x09, 0x00, 0x00  @ SPECIES_UNUSED_413 (40x48, y=9)
	.byte 0x67, 0x06, 0x00, 0x00  @ SPECIES_UNUSED_414 (48x56, y=6)
	.byte 0x56, 0x08, 0x00, 0x00  @ SPECIES_UNUSED_415 (40x48, y=8)
	.byte 0x56, 0x0A, 0x00, 0x00  @ SPECIES_UNUSED_416 (40x48, y=10)
	.byte 0x66, 0x0A, 0x00, 0x00  @ SPECIES_UNUSED_417 (48x48, y=10)
	.byte 0x57, 0x05, 0x00, 0x00  @ SPECIES_UNUSED_418 (40x56, y=5)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_UNUSED_419 (48x48, y=8)
	.byte 0x37, 0x07, 0x00, 0x00  @ SPECIES_UNUSED_420 (24x56, y=7)
	.byte 0x46, 0x09, 0x00, 0x00  @ SPECIES_UNUSED_421 (32x48, y=9)
	.byte 0x57, 0x07, 0x00, 0x00  @ SPECIES_UNUSED_422 (40x56, y=7)
	.byte 0x46, 0x0A, 0x00, 0x00  @ SPECIES_UNUSED_423 (32x48, y=10)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_UNUSED_424 (48x40, y=13)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_UNUSED_425 (48x40, y=13)
	.byte 0x66, 0x08, 0x00, 0x00  @ SPECIES_UNUSED_426 (48x48, y=8)
	.byte 0x46, 0x0A, 0x00, 0x00  @ SPECIES_UNUSED_427 (32x48, y=10)
	.byte 0x55, 0x0F, 0x00, 0x00  @ SPECIES_UNUSED_428 (40x40, y=15)
	.byte 0x45, 0x0C, 0x00, 0x00  @ SPECIES_UNUSED_429 (32x40, y=12)
	.byte 0x57, 0x04, 0x00, 0x00  @ SPECIES_UNUSED_430 (40x56, y=4)
	.byte 0x45, 0x0D, 0x00, 0x00  @ SPECIES_UNUSED_431 (32x40, y=13)
	.byte 0x65, 0x0D, 0x00, 0x00  @ SPECIES_UNUSED_432 (48x40, y=13)
	.byte 0x56, 0x0B, 0x00, 0x00  @ SPECIES_UNUSED_433 (40x48, y=11)
	.byte 0x55, 0x0D, 0x00, 0x00  @ SPECIES_UNUSED_434 (40x40, y=13)
	.byte 0x55, 0x0F, 0x00, 0x00  @ SPECIES_UNUSED_435 (40x40, y=15)
	.byte 0x46, 0x0A, 0x00, 0x00  @ SPECIES_UNUSED_436 (32x48, y=10)
	.byte 0x46, 0x0A, 0x00, 0x00  @ SPECIES_UNUSED_437 (32x48, y=10)
	.byte 0x37, 0x06, 0x00, 0x00  @ SPECIES_UNUSED_438 (24x56, y=6)
	.byte 0x47, 0x06, 0x00, 0x00  @ SPECIES_UNUSED_439 (32x56, y=6)

	.globl gMonBackPicTable
gMonBackPicTable: @ 0x82D6148
	.incbin "baserom_jp.gba", 0x2d6148, 0xdc0

	.globl gUnknown_82D6F08
gUnknown_82D6F08: @ 0x82D6F08
	.incbin "baserom_jp.gba", 0x2d6f08, 0xdc0

	.globl gUnknown_82D7CC8
gUnknown_82D7CC8: @ 0x82D7CC8
	.incbin "baserom_jp.gba", 0x2d7cc8, 0xf34

	.globl gTrainerFrontAnimsPtrTable
gTrainerFrontAnimsPtrTable: @ 0x82D8BFC
	.4byte 0x082D8A88 @ TRAINER_PIC_HIKER
	.4byte 0x082D8A8C @ TRAINER_PIC_AQUA_GRUNT_M
	.4byte 0x082D8A90 @ TRAINER_PIC_POKEMON_BREEDER_F
	.4byte 0x082D8A94 @ TRAINER_PIC_COOLTRAINER_M
	.4byte 0x082D8A98 @ TRAINER_PIC_BIRD_KEEPER
	.4byte 0x082D8A9C @ TRAINER_PIC_COLLECTOR
	.4byte 0x082D8AA0 @ TRAINER_PIC_AQUA_GRUNT_F
	.4byte 0x082D8AA4 @ TRAINER_PIC_SWIMMER_M
	.4byte 0x082D8AA8 @ TRAINER_PIC_MAGMA_GRUNT_M
	.4byte 0x082D8AAC @ TRAINER_PIC_EXPERT_M
	.4byte 0x082D8AB0 @ TRAINER_PIC_AQUA_ADMIN_M
	.4byte 0x082D8AB4 @ TRAINER_PIC_BLACK_BELT
	.4byte 0x082D8AB8 @ TRAINER_PIC_AQUA_ADMIN_F
	.4byte 0x082D8ABC @ TRAINER_PIC_AQUA_LEADER_ARCHIE
	.4byte 0x082D8AC0 @ TRAINER_PIC_HEX_MANIAC
	.4byte 0x082D8AC4 @ TRAINER_PIC_AROMA_LADY
	.4byte 0x082D8AC8 @ TRAINER_PIC_RUIN_MANIAC
	.4byte 0x082D8ACC @ TRAINER_PIC_INTERVIEWER
	.4byte 0x082D8AD0 @ TRAINER_PIC_TUBER_F
	.4byte 0x082D8AD4 @ TRAINER_PIC_TUBER_M
	.4byte 0x082D8AD8 @ TRAINER_PIC_COOLTRAINER_F
	.4byte 0x082D8ADC @ TRAINER_PIC_LADY
	.4byte 0x082D8AE0 @ TRAINER_PIC_BEAUTY
	.4byte 0x082D8AE4 @ TRAINER_PIC_RICH_BOY
	.4byte 0x082D8AE8 @ TRAINER_PIC_EXPERT_F
	.4byte 0x082D8AEC @ TRAINER_PIC_POKEMANIAC
	.4byte 0x082D8AF0 @ TRAINER_PIC_MAGMA_GRUNT_F
	.4byte 0x082D8AF4 @ TRAINER_PIC_GUITARIST
	.4byte 0x082D8AF8 @ TRAINER_PIC_KINDLER
	.4byte 0x082D8AFC @ TRAINER_PIC_CAMPER
	.4byte 0x082D8B00 @ TRAINER_PIC_PICNICKER
	.4byte 0x082D8B04 @ TRAINER_PIC_BUG_MANIAC
	.4byte 0x082D8B08 @ TRAINER_PIC_POKEMON_BREEDER_M
	.4byte 0x082D8B0C @ TRAINER_PIC_PSYCHIC_M
	.4byte 0x082D8B10 @ TRAINER_PIC_PSYCHIC_F
	.4byte 0x082D8B14 @ TRAINER_PIC_GENTLEMAN
	.4byte 0x082D8B18 @ TRAINER_PIC_ELITE_FOUR_SIDNEY
	.4byte 0x082D8B1C @ TRAINER_PIC_ELITE_FOUR_PHOEBE
	.4byte 0x082D8B20 @ TRAINER_PIC_ELITE_FOUR_GLACIA
	.4byte 0x082D8B24 @ TRAINER_PIC_ELITE_FOUR_DRAKE
	.4byte 0x082D8B28 @ TRAINER_PIC_LEADER_ROXANNE
	.4byte 0x082D8B2C @ TRAINER_PIC_LEADER_BRAWLY
	.4byte 0x082D8B30 @ TRAINER_PIC_LEADER_WATTSON
	.4byte 0x082D8B34 @ TRAINER_PIC_LEADER_FLANNERY
	.4byte 0x082D8B38 @ TRAINER_PIC_LEADER_NORMAN
	.4byte 0x082D8B3C @ TRAINER_PIC_LEADER_WINONA
	.4byte 0x082D8B40 @ TRAINER_PIC_LEADER_TATE_AND_LIZA
	.4byte 0x082D8B44 @ TRAINER_PIC_LEADER_JUAN
	.4byte 0x082D8B48 @ TRAINER_PIC_SCHOOL_KID_M
	.4byte 0x082D8B4C @ TRAINER_PIC_SCHOOL_KID_F
	.4byte 0x082D8B50 @ TRAINER_PIC_SR_AND_JR
	.4byte 0x082D8B54 @ TRAINER_PIC_POKEFAN_M
	.4byte 0x082D8B58 @ TRAINER_PIC_POKEFAN_F
	.4byte 0x082D8B5C @ TRAINER_PIC_YOUNGSTER
	.4byte 0x082D8B60 @ TRAINER_PIC_CHAMPION_WALLACE
	.4byte 0x082D8B64 @ TRAINER_PIC_FISHERMAN
	.4byte 0x082D8B68 @ TRAINER_PIC_CYCLING_TRIATHLETE_M
	.4byte 0x082D8B6C @ TRAINER_PIC_CYCLING_TRIATHLETE_F
	.4byte 0x082D8B70 @ TRAINER_PIC_RUNNING_TRIATHLETE_M
	.4byte 0x082D8B74 @ TRAINER_PIC_RUNNING_TRIATHLETE_F
	.4byte 0x082D8B78 @ TRAINER_PIC_SWIMMING_TRIATHLETE_M
	.4byte 0x082D8B7C @ TRAINER_PIC_SWIMMING_TRIATHLETE_F
	.4byte 0x082D8B80 @ TRAINER_PIC_DRAGON_TAMER
	.4byte 0x082D8B84 @ TRAINER_PIC_NINJA_BOY
	.4byte 0x082D8B88 @ TRAINER_PIC_BATTLE_GIRL
	.4byte 0x082D8B8C @ TRAINER_PIC_PARASOL_LADY
	.4byte 0x082D8B90 @ TRAINER_PIC_SWIMMER_F
	.4byte 0x082D8B94 @ TRAINER_PIC_TWINS
	.4byte 0x082D8B98 @ TRAINER_PIC_SAILOR
	.4byte 0x082D8B9C @ TRAINER_PIC_MAGMA_ADMIN
	.4byte 0x082D8BA0 @ TRAINER_PIC_WALLY
	.4byte 0x082D8BA4 @ TRAINER_PIC_BRENDAN
	.4byte 0x082D8BA8 @ TRAINER_PIC_MAY
	.4byte 0x082D8BAC @ TRAINER_PIC_BUG_CATCHER
	.4byte 0x082D8BB0 @ TRAINER_PIC_POKEMON_RANGER_M
	.4byte 0x082D8BB4 @ TRAINER_PIC_POKEMON_RANGER_F
	.4byte 0x082D8BB8 @ TRAINER_PIC_MAGMA_LEADER_MAXIE
	.4byte 0x082D8BBC @ TRAINER_PIC_LASS
	.4byte 0x082D8BC0 @ TRAINER_PIC_YOUNG_COUPLE
	.4byte 0x082D8BC4 @ TRAINER_PIC_OLD_COUPLE
	.4byte 0x082D8BC8 @ TRAINER_PIC_SIS_AND_BRO
	.4byte 0x082D8BCC @ TRAINER_PIC_STEVEN
	.4byte 0x082D8BD0 @ TRAINER_PIC_SALON_MAIDEN_ANABEL
	.4byte 0x082D8BD4 @ TRAINER_PIC_DOME_ACE_TUCKER
	.4byte 0x082D8BD8 @ TRAINER_PIC_PALACE_MAVEN_SPENSER
	.4byte 0x082D8BDC @ TRAINER_PIC_ARENA_TYCOON_GRETA
	.4byte 0x082D8BE0 @ TRAINER_PIC_FACTORY_HEAD_NOLAND
	.4byte 0x082D8BE4 @ TRAINER_PIC_PIKE_QUEEN_LUCY
	.4byte 0x082D8BE8 @ TRAINER_PIC_PYRAMID_KING_BRANDON
	.4byte 0x082D8BEC @ TRAINER_PIC_RED
	.4byte 0x082D8BF0 @ TRAINER_PIC_LEAF
	.4byte 0x082D8BF4 @ TRAINER_PIC_RS_BRENDAN
	.4byte 0x082D8BF8 @ TRAINER_PIC_RS_MAY

	.globl gUnknown_82D8D70
gUnknown_82D8D70: @ 0x82D8D70
	.incbin "baserom_jp.gba", 0x2d8d70, 0x174

	.globl gTrainerFrontPicTable
gTrainerFrontPicTable: @ 0x82D8EE4
	.incbin "baserom_jp.gba", 0x2d8ee4, 0x2e8

	.globl gTrainerFrontPicPaletteTable
gTrainerFrontPicPaletteTable: @ 0x82D91CC
	.incbin "baserom_jp.gba", 0x2d91cc, 0x3d0

	.globl gUnknown_82D959C
gUnknown_82D959C: @ 0x82D959C
	.incbin "baserom_jp.gba", 0x2d959c, 0x20

	.globl gTrainerBackPicCoords
gTrainerBackPicCoords: @ 0x82D95BC
	.byte 8 @ TRAINER_BACK_PIC_BRENDAN.size
	.byte 4 @ TRAINER_BACK_PIC_BRENDAN.y_offset
	.hword 0
	.byte 8 @ TRAINER_BACK_PIC_MAY.size
	.byte 4 @ TRAINER_BACK_PIC_MAY.y_offset
	.hword 0
	.byte 8 @ TRAINER_BACK_PIC_RED.size
	.byte 5 @ TRAINER_BACK_PIC_RED.y_offset
	.hword 0
	.byte 8 @ TRAINER_BACK_PIC_LEAF.size
	.byte 5 @ TRAINER_BACK_PIC_LEAF.y_offset
	.hword 0
	.byte 8 @ TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN.size
	.byte 4 @ TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN.y_offset
	.hword 0
	.byte 8 @ TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY.size
	.byte 4 @ TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY.y_offset
	.hword 0
	.byte 8 @ TRAINER_BACK_PIC_WALLY.size
	.byte 4 @ TRAINER_BACK_PIC_WALLY.y_offset
	.hword 0
	.byte 8 @ TRAINER_BACK_PIC_STEVEN.size
	.byte 4 @ TRAINER_BACK_PIC_STEVEN.y_offset
	.hword 0

	.globl gTrainerBackPicTable
gTrainerBackPicTable: @ 0x82D95DC
	.incbin "baserom_jp.gba", 0x2d95dc, 0x40

	.globl gUnknown_82D961C
gUnknown_82D961C: @ 0x82D961C
	.incbin "baserom_jp.gba", 0x2d961c, 0x40

	.globl gEnemyMonElevation
gEnemyMonElevation: @ 0x82D965C
	.byte 0x00  @ SPECIES_NONE
	.byte 0x00  @ SPECIES_BULBASAUR
	.byte 0x00  @ SPECIES_IVYSAUR
	.byte 0x00  @ SPECIES_VENUSAUR
	.byte 0x00  @ SPECIES_CHARMANDER
	.byte 0x00  @ SPECIES_CHARMELEON
	.byte 0x00  @ SPECIES_CHARIZARD
	.byte 0x00  @ SPECIES_SQUIRTLE
	.byte 0x00  @ SPECIES_WARTORTLE
	.byte 0x00  @ SPECIES_BLASTOISE
	.byte 0x00  @ SPECIES_CATERPIE
	.byte 0x00  @ SPECIES_METAPOD
	.byte 0x08  @ SPECIES_BUTTERFREE
	.byte 0x00  @ SPECIES_WEEDLE
	.byte 0x00  @ SPECIES_KAKUNA
	.byte 0x08  @ SPECIES_BEEDRILL
	.byte 0x10  @ SPECIES_PIDGEY
	.byte 0x00  @ SPECIES_PIDGEOTTO
	.byte 0x04  @ SPECIES_PIDGEOT
	.byte 0x00  @ SPECIES_RATTATA
	.byte 0x00  @ SPECIES_RATICATE
	.byte 0x00  @ SPECIES_SPEAROW
	.byte 0x06  @ SPECIES_FEAROW
	.byte 0x00  @ SPECIES_EKANS
	.byte 0x00  @ SPECIES_ARBOK
	.byte 0x00  @ SPECIES_PIKACHU
	.byte 0x00  @ SPECIES_RAICHU
	.byte 0x00  @ SPECIES_SANDSHREW
	.byte 0x00  @ SPECIES_SANDSLASH
	.byte 0x00  @ SPECIES_NIDORAN_F
	.byte 0x00  @ SPECIES_NIDORINA
	.byte 0x00  @ SPECIES_NIDOQUEEN
	.byte 0x00  @ SPECIES_NIDORAN_M
	.byte 0x00  @ SPECIES_NIDORINO
	.byte 0x00  @ SPECIES_NIDOKING
	.byte 0x00  @ SPECIES_CLEFAIRY
	.byte 0x00  @ SPECIES_CLEFABLE
	.byte 0x00  @ SPECIES_VULPIX
	.byte 0x00  @ SPECIES_NINETALES
	.byte 0x00  @ SPECIES_JIGGLYPUFF
	.byte 0x00  @ SPECIES_WIGGLYTUFF
	.byte 0x08  @ SPECIES_ZUBAT
	.byte 0x08  @ SPECIES_GOLBAT
	.byte 0x00  @ SPECIES_ODDISH
	.byte 0x00  @ SPECIES_GLOOM
	.byte 0x00  @ SPECIES_VILEPLUME
	.byte 0x00  @ SPECIES_PARAS
	.byte 0x00  @ SPECIES_PARASECT
	.byte 0x00  @ SPECIES_VENONAT
	.byte 0x08  @ SPECIES_VENOMOTH
	.byte 0x00  @ SPECIES_DIGLETT
	.byte 0x00  @ SPECIES_DUGTRIO
	.byte 0x00  @ SPECIES_MEOWTH
	.byte 0x00  @ SPECIES_PERSIAN
	.byte 0x00  @ SPECIES_PSYDUCK
	.byte 0x00  @ SPECIES_GOLDUCK
	.byte 0x00  @ SPECIES_MANKEY
	.byte 0x00  @ SPECIES_PRIMEAPE
	.byte 0x00  @ SPECIES_GROWLITHE
	.byte 0x00  @ SPECIES_ARCANINE
	.byte 0x00  @ SPECIES_POLIWAG
	.byte 0x00  @ SPECIES_POLIWHIRL
	.byte 0x00  @ SPECIES_POLIWRATH
	.byte 0x00  @ SPECIES_ABRA
	.byte 0x00  @ SPECIES_KADABRA
	.byte 0x00  @ SPECIES_ALAKAZAM
	.byte 0x00  @ SPECIES_MACHOP
	.byte 0x00  @ SPECIES_MACHOKE
	.byte 0x00  @ SPECIES_MACHAMP
	.byte 0x00  @ SPECIES_BELLSPROUT
	.byte 0x00  @ SPECIES_WEEPINBELL
	.byte 0x00  @ SPECIES_VICTREEBEL
	.byte 0x00  @ SPECIES_TENTACOOL
	.byte 0x00  @ SPECIES_TENTACRUEL
	.byte 0x10  @ SPECIES_GEODUDE
	.byte 0x00  @ SPECIES_GRAVELER
	.byte 0x00  @ SPECIES_GOLEM
	.byte 0x00  @ SPECIES_PONYTA
	.byte 0x00  @ SPECIES_RAPIDASH
	.byte 0x00  @ SPECIES_SLOWPOKE
	.byte 0x00  @ SPECIES_SLOWBRO
	.byte 0x10  @ SPECIES_MAGNEMITE
	.byte 0x08  @ SPECIES_MAGNETON
	.byte 0x00  @ SPECIES_FARFETCHD
	.byte 0x00  @ SPECIES_DODUO
	.byte 0x00  @ SPECIES_DODRIO
	.byte 0x00  @ SPECIES_SEEL
	.byte 0x00  @ SPECIES_DEWGONG
	.byte 0x00  @ SPECIES_GRIMER
	.byte 0x00  @ SPECIES_MUK
	.byte 0x00  @ SPECIES_SHELLDER
	.byte 0x00  @ SPECIES_CLOYSTER
	.byte 0x04  @ SPECIES_GASTLY
	.byte 0x04  @ SPECIES_HAUNTER
	.byte 0x00  @ SPECIES_GENGAR
	.byte 0x00  @ SPECIES_ONIX
	.byte 0x00  @ SPECIES_DROWZEE
	.byte 0x00  @ SPECIES_HYPNO
	.byte 0x00  @ SPECIES_KRABBY
	.byte 0x00  @ SPECIES_KINGLER
	.byte 0x0A  @ SPECIES_VOLTORB
	.byte 0x0C  @ SPECIES_ELECTRODE
	.byte 0x00  @ SPECIES_EXEGGCUTE
	.byte 0x00  @ SPECIES_EXEGGUTOR
	.byte 0x00  @ SPECIES_CUBONE
	.byte 0x00  @ SPECIES_MAROWAK
	.byte 0x00  @ SPECIES_HITMONLEE
	.byte 0x00  @ SPECIES_HITMONCHAN
	.byte 0x00  @ SPECIES_LICKITUNG
	.byte 0x08  @ SPECIES_KOFFING
	.byte 0x06  @ SPECIES_WEEZING
	.byte 0x00  @ SPECIES_RHYHORN
	.byte 0x00  @ SPECIES_RHYDON
	.byte 0x00  @ SPECIES_CHANSEY
	.byte 0x00  @ SPECIES_TANGELA
	.byte 0x00  @ SPECIES_KANGASKHAN
	.byte 0x00  @ SPECIES_HORSEA
	.byte 0x00  @ SPECIES_SEADRA
	.byte 0x00  @ SPECIES_GOLDEEN
	.byte 0x00  @ SPECIES_SEAKING
	.byte 0x00  @ SPECIES_STARYU
	.byte 0x00  @ SPECIES_STARMIE
	.byte 0x00  @ SPECIES_MR_MIME
	.byte 0x00  @ SPECIES_SCYTHER
	.byte 0x00  @ SPECIES_JYNX
	.byte 0x00  @ SPECIES_ELECTABUZZ
	.byte 0x00  @ SPECIES_MAGMAR
	.byte 0x00  @ SPECIES_PINSIR
	.byte 0x00  @ SPECIES_TAUROS
	.byte 0x00  @ SPECIES_MAGIKARP
	.byte 0x00  @ SPECIES_GYARADOS
	.byte 0x00  @ SPECIES_LAPRAS
	.byte 0x00  @ SPECIES_DITTO
	.byte 0x00  @ SPECIES_EEVEE
	.byte 0x00  @ SPECIES_VAPOREON
	.byte 0x00  @ SPECIES_JOLTEON
	.byte 0x00  @ SPECIES_FLAREON
	.byte 0x00  @ SPECIES_PORYGON
	.byte 0x00  @ SPECIES_OMANYTE
	.byte 0x00  @ SPECIES_OMASTAR
	.byte 0x00  @ SPECIES_KABUTO
	.byte 0x00  @ SPECIES_KABUTOPS
	.byte 0x07  @ SPECIES_AERODACTYL
	.byte 0x00  @ SPECIES_SNORLAX
	.byte 0x06  @ SPECIES_ARTICUNO
	.byte 0x08  @ SPECIES_ZAPDOS
	.byte 0x05  @ SPECIES_MOLTRES
	.byte 0x00  @ SPECIES_DRATINI
	.byte 0x00  @ SPECIES_DRAGONAIR
	.byte 0x06  @ SPECIES_DRAGONITE
	.byte 0x00  @ SPECIES_MEWTWO
	.byte 0x08  @ SPECIES_MEW
	.byte 0x00  @ SPECIES_CHIKORITA
	.byte 0x00  @ SPECIES_BAYLEEF
	.byte 0x00  @ SPECIES_MEGANIUM
	.byte 0x00  @ SPECIES_CYNDAQUIL
	.byte 0x00  @ SPECIES_QUILAVA
	.byte 0x00  @ SPECIES_TYPHLOSION
	.byte 0x00  @ SPECIES_TOTODILE
	.byte 0x00  @ SPECIES_CROCONAW
	.byte 0x00  @ SPECIES_FERALIGATR
	.byte 0x00  @ SPECIES_SENTRET
	.byte 0x00  @ SPECIES_FURRET
	.byte 0x00  @ SPECIES_HOOTHOOT
	.byte 0x00  @ SPECIES_NOCTOWL
	.byte 0x00  @ SPECIES_LEDYBA
	.byte 0x08  @ SPECIES_LEDIAN
	.byte 0x00  @ SPECIES_SPINARAK
	.byte 0x00  @ SPECIES_ARIADOS
	.byte 0x06  @ SPECIES_CROBAT
	.byte 0x00  @ SPECIES_CHINCHOU
	.byte 0x00  @ SPECIES_LANTURN
	.byte 0x00  @ SPECIES_PICHU
	.byte 0x00  @ SPECIES_CLEFFA
	.byte 0x00  @ SPECIES_IGGLYBUFF
	.byte 0x00  @ SPECIES_TOGEPI
	.byte 0x00  @ SPECIES_TOGETIC
	.byte 0x00  @ SPECIES_NATU
	.byte 0x00  @ SPECIES_XATU
	.byte 0x00  @ SPECIES_MAREEP
	.byte 0x00  @ SPECIES_FLAAFFY
	.byte 0x00  @ SPECIES_AMPHAROS
	.byte 0x00  @ SPECIES_BELLOSSOM
	.byte 0x00  @ SPECIES_MARILL
	.byte 0x00  @ SPECIES_AZUMARILL
	.byte 0x00  @ SPECIES_SUDOWOODO
	.byte 0x00  @ SPECIES_POLITOED
	.byte 0x0B  @ SPECIES_HOPPIP
	.byte 0x0C  @ SPECIES_SKIPLOOM
	.byte 0x09  @ SPECIES_JUMPLUFF
	.byte 0x00  @ SPECIES_AIPOM
	.byte 0x00  @ SPECIES_SUNKERN
	.byte 0x00  @ SPECIES_SUNFLORA
	.byte 0x08  @ SPECIES_YANMA
	.byte 0x00  @ SPECIES_WOOPER
	.byte 0x00  @ SPECIES_QUAGSIRE
	.byte 0x00  @ SPECIES_ESPEON
	.byte 0x00  @ SPECIES_UMBREON
	.byte 0x00  @ SPECIES_MURKROW
	.byte 0x00  @ SPECIES_SLOWKING
	.byte 0x08  @ SPECIES_MISDREAVUS
	.byte 0x08  @ SPECIES_UNOWN
	.byte 0x00  @ SPECIES_WOBBUFFET
	.byte 0x00  @ SPECIES_GIRAFARIG
	.byte 0x00  @ SPECIES_PINECO
	.byte 0x00  @ SPECIES_FORRETRESS
	.byte 0x00  @ SPECIES_DUNSPARCE
	.byte 0x06  @ SPECIES_GLIGAR
	.byte 0x00  @ SPECIES_STEELIX
	.byte 0x00  @ SPECIES_SNUBBULL
	.byte 0x00  @ SPECIES_GRANBULL
	.byte 0x00  @ SPECIES_QWILFISH
	.byte 0x00  @ SPECIES_SCIZOR
	.byte 0x00  @ SPECIES_SHUCKLE
	.byte 0x00  @ SPECIES_HERACROSS
	.byte 0x00  @ SPECIES_SNEASEL
	.byte 0x00  @ SPECIES_TEDDIURSA
	.byte 0x00  @ SPECIES_URSARING
	.byte 0x00  @ SPECIES_SLUGMA
	.byte 0x00  @ SPECIES_MAGCARGO
	.byte 0x00  @ SPECIES_SWINUB
	.byte 0x00  @ SPECIES_PILOSWINE
	.byte 0x00  @ SPECIES_CORSOLA
	.byte 0x00  @ SPECIES_REMORAID
	.byte 0x00  @ SPECIES_OCTILLERY
	.byte 0x00  @ SPECIES_DELIBIRD
	.byte 0x00  @ SPECIES_MANTINE
	.byte 0x00  @ SPECIES_SKARMORY
	.byte 0x00  @ SPECIES_HOUNDOUR
	.byte 0x00  @ SPECIES_HOUNDOOM
	.byte 0x00  @ SPECIES_KINGDRA
	.byte 0x00  @ SPECIES_PHANPY
	.byte 0x00  @ SPECIES_DONPHAN
	.byte 0x00  @ SPECIES_PORYGON2
	.byte 0x00  @ SPECIES_STANTLER
	.byte 0x00  @ SPECIES_SMEARGLE
	.byte 0x00  @ SPECIES_TYROGUE
	.byte 0x00  @ SPECIES_HITMONTOP
	.byte 0x00  @ SPECIES_SMOOCHUM
	.byte 0x00  @ SPECIES_ELEKID
	.byte 0x00  @ SPECIES_MAGBY
	.byte 0x00  @ SPECIES_MILTANK
	.byte 0x00  @ SPECIES_BLISSEY
	.byte 0x00  @ SPECIES_RAIKOU
	.byte 0x00  @ SPECIES_ENTEI
	.byte 0x00  @ SPECIES_SUICUNE
	.byte 0x00  @ SPECIES_LARVITAR
	.byte 0x00  @ SPECIES_PUPITAR
	.byte 0x00  @ SPECIES_TYRANITAR
	.byte 0x06  @ SPECIES_LUGIA
	.byte 0x06  @ SPECIES_HO_OH
	.byte 0x0F  @ SPECIES_CELEBI
	.byte 0x00  @ SPECIES_OLD_UNOWN_B
	.byte 0x00  @ SPECIES_OLD_UNOWN_C
	.byte 0x00  @ SPECIES_OLD_UNOWN_D
	.byte 0x00  @ SPECIES_OLD_UNOWN_E
	.byte 0x00  @ SPECIES_OLD_UNOWN_F
	.byte 0x00  @ SPECIES_OLD_UNOWN_G
	.byte 0x00  @ SPECIES_OLD_UNOWN_H
	.byte 0x00  @ SPECIES_OLD_UNOWN_I
	.byte 0x00  @ SPECIES_OLD_UNOWN_J
	.byte 0x00  @ SPECIES_OLD_UNOWN_K
	.byte 0x00  @ SPECIES_OLD_UNOWN_L
	.byte 0x00  @ SPECIES_OLD_UNOWN_M
	.byte 0x00  @ SPECIES_OLD_UNOWN_N
	.byte 0x00  @ SPECIES_OLD_UNOWN_O
	.byte 0x00  @ SPECIES_OLD_UNOWN_P
	.byte 0x00  @ SPECIES_OLD_UNOWN_Q
	.byte 0x00  @ SPECIES_OLD_UNOWN_R
	.byte 0x00  @ SPECIES_OLD_UNOWN_S
	.byte 0x00  @ SPECIES_OLD_UNOWN_T
	.byte 0x00  @ SPECIES_OLD_UNOWN_U
	.byte 0x00  @ SPECIES_OLD_UNOWN_V
	.byte 0x00  @ SPECIES_OLD_UNOWN_W
	.byte 0x00  @ SPECIES_OLD_UNOWN_X
	.byte 0x00  @ SPECIES_OLD_UNOWN_Y
	.byte 0x00  @ SPECIES_OLD_UNOWN_Z
	.byte 0x00  @ SPECIES_TREECKO
	.byte 0x00  @ SPECIES_GROVYLE
	.byte 0x00  @ SPECIES_SCEPTILE
	.byte 0x00  @ SPECIES_TORCHIC
	.byte 0x00  @ SPECIES_COMBUSKEN
	.byte 0x00  @ SPECIES_BLAZIKEN
	.byte 0x00  @ SPECIES_MUDKIP
	.byte 0x00  @ SPECIES_MARSHTOMP
	.byte 0x00  @ SPECIES_SWAMPERT
	.byte 0x00  @ SPECIES_POOCHYENA
	.byte 0x00  @ SPECIES_MIGHTYENA
	.byte 0x00  @ SPECIES_ZIGZAGOON
	.byte 0x00  @ SPECIES_LINOONE
	.byte 0x00  @ SPECIES_WURMPLE
	.byte 0x00  @ SPECIES_SILCOON
	.byte 0x08  @ SPECIES_BEAUTIFLY
	.byte 0x00  @ SPECIES_CASCOON
	.byte 0x0A  @ SPECIES_DUSTOX
	.byte 0x00  @ SPECIES_LOTAD
	.byte 0x00  @ SPECIES_LOMBRE
	.byte 0x00  @ SPECIES_LUDICOLO
	.byte 0x00  @ SPECIES_SEEDOT
	.byte 0x00  @ SPECIES_NUZLEAF
	.byte 0x00  @ SPECIES_SHIFTRY
	.byte 0x00  @ SPECIES_NINCADA
	.byte 0x0A  @ SPECIES_NINJASK
	.byte 0x08  @ SPECIES_SHEDINJA
	.byte 0x00  @ SPECIES_TAILLOW
	.byte 0x00  @ SPECIES_SWELLOW
	.byte 0x00  @ SPECIES_SHROOMISH
	.byte 0x00  @ SPECIES_BRELOOM
	.byte 0x00  @ SPECIES_SPINDA
	.byte 0x10  @ SPECIES_WINGULL
	.byte 0x08  @ SPECIES_PELIPPER
	.byte 0x00  @ SPECIES_SURSKIT
	.byte 0x0A  @ SPECIES_MASQUERAIN
	.byte 0x00  @ SPECIES_WAILMER
	.byte 0x00  @ SPECIES_WAILORD
	.byte 0x00  @ SPECIES_SKITTY
	.byte 0x00  @ SPECIES_DELCATTY
	.byte 0x00  @ SPECIES_KECLEON
	.byte 0x04  @ SPECIES_BALTOY
	.byte 0x0A  @ SPECIES_CLAYDOL
	.byte 0x00  @ SPECIES_NOSEPASS
	.byte 0x00  @ SPECIES_TORKOAL
	.byte 0x00  @ SPECIES_SABLEYE
	.byte 0x00  @ SPECIES_BARBOACH
	.byte 0x00  @ SPECIES_WHISCASH
	.byte 0x00  @ SPECIES_LUVDISC
	.byte 0x00  @ SPECIES_CORPHISH
	.byte 0x00  @ SPECIES_CRAWDAUNT
	.byte 0x00  @ SPECIES_FEEBAS
	.byte 0x00  @ SPECIES_MILOTIC
	.byte 0x00  @ SPECIES_CARVANHA
	.byte 0x00  @ SPECIES_SHARPEDO
	.byte 0x00  @ SPECIES_TRAPINCH
	.byte 0x00  @ SPECIES_VIBRAVA
	.byte 0x07  @ SPECIES_FLYGON
	.byte 0x00  @ SPECIES_MAKUHITA
	.byte 0x00  @ SPECIES_HARIYAMA
	.byte 0x00  @ SPECIES_ELECTRIKE
	.byte 0x00  @ SPECIES_MANECTRIC
	.byte 0x00  @ SPECIES_NUMEL
	.byte 0x00  @ SPECIES_CAMERUPT
	.byte 0x00  @ SPECIES_SPHEAL
	.byte 0x00  @ SPECIES_SEALEO
	.byte 0x00  @ SPECIES_WALREIN
	.byte 0x00  @ SPECIES_CACNEA
	.byte 0x00  @ SPECIES_CACTURNE
	.byte 0x00  @ SPECIES_SNORUNT
	.byte 0x0C  @ SPECIES_GLALIE
	.byte 0x0D  @ SPECIES_LUNATONE
	.byte 0x04  @ SPECIES_SOLROCK
	.byte 0x00  @ SPECIES_AZURILL
	.byte 0x00  @ SPECIES_SPOINK
	.byte 0x00  @ SPECIES_GRUMPIG
	.byte 0x00  @ SPECIES_PLUSLE
	.byte 0x00  @ SPECIES_MINUN
	.byte 0x00  @ SPECIES_MAWILE
	.byte 0x00  @ SPECIES_MEDITITE
	.byte 0x00  @ SPECIES_MEDICHAM
	.byte 0x0C  @ SPECIES_SWABLU
	.byte 0x08  @ SPECIES_ALTARIA
	.byte 0x00  @ SPECIES_WYNAUT
	.byte 0x09  @ SPECIES_DUSKULL
	.byte 0x00  @ SPECIES_DUSCLOPS
	.byte 0x00  @ SPECIES_ROSELIA
	.byte 0x00  @ SPECIES_SLAKOTH
	.byte 0x00  @ SPECIES_VIGOROTH
	.byte 0x00  @ SPECIES_SLAKING
	.byte 0x00  @ SPECIES_GULPIN
	.byte 0x00  @ SPECIES_SWALOT
	.byte 0x00  @ SPECIES_TROPIUS
	.byte 0x00  @ SPECIES_WHISMUR
	.byte 0x00  @ SPECIES_LOUDRED
	.byte 0x00  @ SPECIES_EXPLOUD
	.byte 0x00  @ SPECIES_CLAMPERL
	.byte 0x00  @ SPECIES_HUNTAIL
	.byte 0x00  @ SPECIES_GOREBYSS
	.byte 0x00  @ SPECIES_ABSOL
	.byte 0x0C  @ SPECIES_SHUPPET
	.byte 0x08  @ SPECIES_BANETTE
	.byte 0x00  @ SPECIES_SEVIPER
	.byte 0x00  @ SPECIES_ZANGOOSE
	.byte 0x00  @ SPECIES_RELICANTH
	.byte 0x00  @ SPECIES_ARON
	.byte 0x00  @ SPECIES_LAIRON
	.byte 0x00  @ SPECIES_AGGRON
	.byte 0x10  @ SPECIES_CASTFORM
	.byte 0x00  @ SPECIES_VOLBEAT
	.byte 0x00  @ SPECIES_ILLUMISE
	.byte 0x00  @ SPECIES_LILEEP
	.byte 0x00  @ SPECIES_CRADILY
	.byte 0x00  @ SPECIES_ANORITH
	.byte 0x00  @ SPECIES_ARMALDO
	.byte 0x00  @ SPECIES_RALTS
	.byte 0x00  @ SPECIES_KIRLIA
	.byte 0x00  @ SPECIES_GARDEVOIR
	.byte 0x00  @ SPECIES_BAGON
	.byte 0x00  @ SPECIES_SHELGON
	.byte 0x00  @ SPECIES_SALAMENCE
	.byte 0x08  @ SPECIES_BELDUM
	.byte 0x00  @ SPECIES_METANG
	.byte 0x00  @ SPECIES_METAGROSS
	.byte 0x00  @ SPECIES_REGIROCK
	.byte 0x00  @ SPECIES_REGICE
	.byte 0x00  @ SPECIES_REGISTEEL
	.byte 0x00  @ SPECIES_KYOGRE
	.byte 0x00  @ SPECIES_GROUDON
	.byte 0x06  @ SPECIES_RAYQUAZA
	.byte 0x06  @ SPECIES_LATIAS
	.byte 0x06  @ SPECIES_LATIOS
	.byte 0x0C  @ SPECIES_JIRACHI
	.byte 0x08  @ SPECIES_DEOXYS
	.byte 0x0C  @ SPECIES_CHIMECHO
	.byte 0x00  @ SPECIES_EGG
	.incbin "baserom_jp.gba", 0x2D97F9, 0x3B43  @ trailing data

	.globl gUnknown_82DD33C
gUnknown_82DD33C: @ 0x82DD33C
	.incbin "baserom_jp.gba", 0x2dd33c, 0x6e0

	.globl gMonFrontPicTable
gMonFrontPicTable: @ 0x82DDA1C
	.incbin "baserom_jp.gba", 0x2dda1c, 0x5b48



