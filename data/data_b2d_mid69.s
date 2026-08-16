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

	.globl sGrammarMoveUsedTable
sGrammarMoveUsedTable: @ 0x85AC146
	.hword MOVE_SWORDS_DANCE
	.hword MOVE_STRENGTH
	.hword MOVE_GROWTH
	.hword MOVE_HARDEN
	.hword MOVE_MINIMIZE
	.hword MOVE_SMOKESCREEN
	.hword MOVE_WITHDRAW
	.hword MOVE_DEFENSE_CURL
	.hword MOVE_EGG_BOMB
	.hword MOVE_SMOG
	.hword MOVE_BONE_CLUB
	.hword MOVE_FLASH
	.hword MOVE_SPLASH
	.hword MOVE_ACID_ARMOR
	.hword MOVE_BONEMERANG
	.hword MOVE_REST
	.hword MOVE_SHARPEN
	.hword MOVE_SUBSTITUTE
	.hword MOVE_MIND_READER
	.hword MOVE_SNORE
	.hword MOVE_PROTECT
	.hword MOVE_SPIKES
	.hword MOVE_ENDURE
	.hword MOVE_ROLLOUT
	.hword MOVE_SWAGGER
	.hword MOVE_SLEEP_TALK
	.hword MOVE_HIDDEN_POWER
	.hword MOVE_PSYCH_UP
	.hword MOVE_EXTREME_SPEED
	.hword MOVE_FOLLOW_ME
	.hword MOVE_TRICK
	.hword MOVE_ASSIST
	.hword MOVE_INGRAIN
	.hword MOVE_KNOCK_OFF
	.hword MOVE_CAMOUFLAGE
	.hword MOVE_ASTONISH
	.hword MOVE_ODOR_SLEUTH
	.hword MOVE_GRASS_WHISTLE
	.hword MOVE_SHEER_COLD
	.hword MOVE_MUDDY_WATER
	.hword MOVE_IRON_DEFENSE
	.hword MOVE_BOUNCE
	.hword MOVE_NONE
	.hword MOVE_TELEPORT
	.hword MOVE_RECOVER
	.hword MOVE_BIDE
	.hword MOVE_AMNESIA
	.hword MOVE_FLAIL
	.hword MOVE_TAUNT
	.hword MOVE_BULK_UP
	.hword MOVE_NONE
	.hword MOVE_MEDITATE
	.hword MOVE_AGILITY
	.hword MOVE_MIMIC
	.hword MOVE_DOUBLE_TEAM
	.hword MOVE_BARRAGE
	.hword MOVE_TRANSFORM
	.hword MOVE_STRUGGLE
	.hword MOVE_SCARY_FACE
	.hword MOVE_CHARGE
	.hword MOVE_WISH
	.hword MOVE_BRICK_BREAK
	.hword MOVE_YAWN
	.hword MOVE_FEATHER_DANCE
	.hword MOVE_TEETER_DANCE
	.hword MOVE_MUD_SPORT
	.hword MOVE_FAKE_TEARS
	.hword MOVE_WATER_SPORT
	.hword MOVE_CALM_MIND
	.hword MOVE_NONE
	.hword MOVE_POUND
	.hword MOVE_SCRATCH
	.hword MOVE_VICE_GRIP
	.hword MOVE_WING_ATTACK
	.hword MOVE_FLY
	.hword MOVE_BIND
	.hword MOVE_SLAM
	.hword MOVE_HORN_ATTACK
	.hword MOVE_WRAP
	.hword MOVE_THRASH
	.hword MOVE_TAIL_WHIP
	.hword MOVE_LEER
	.hword MOVE_BITE
	.hword MOVE_GROWL
	.hword MOVE_ROAR
	.hword MOVE_SING
	.hword MOVE_PECK
	.hword MOVE_ABSORB
	.hword MOVE_STRING_SHOT
	.hword MOVE_EARTHQUAKE
	.hword MOVE_FISSURE
	.hword MOVE_DIG
	.hword MOVE_TOXIC
	.hword MOVE_SCREECH
	.hword MOVE_METRONOME
	.hword MOVE_LICK
	.hword MOVE_CLAMP
	.hword MOVE_CONSTRICT
	.hword MOVE_POISON_GAS
	.hword MOVE_BUBBLE
	.hword MOVE_SLASH
	.hword MOVE_SPIDER_WEB
	.hword MOVE_NIGHTMARE
	.hword MOVE_CURSE
	.hword MOVE_FORESIGHT
	.hword MOVE_CHARM
	.hword MOVE_ATTRACT
	.hword MOVE_ROCK_SMASH
	.hword MOVE_UPROAR
	.hword MOVE_SPIT_UP
	.hword MOVE_SWALLOW
	.hword MOVE_TORMENT
	.hword MOVE_FLATTER
	.hword MOVE_ROLE_PLAY
	.hword MOVE_ENDEAVOR
	.hword MOVE_TICKLE
	.hword MOVE_COVET
	.hword MOVE_NONE
	.globl gUnknown_85AC232
gUnknown_85AC232: @ 0x85AC232
	.incbin "baserom_jp.gba", 0x5ac232, 0x236

	.globl gUnknown_85AC468
gUnknown_85AC468: @ 0x85AC468
	.incbin "baserom_jp.gba", 0x5ac468, 0x8

	.globl gUnknown_85AC470
gUnknown_85AC470: @ 0x85AC470
	.incbin "baserom_jp.gba", 0x5ac470, 0x4

	.globl gUnknown_85AC474
gUnknown_85AC474: @ 0x85AC474
	.incbin "baserom_jp.gba", 0x5ac474, 0x10

	.globl gUnknown_85AC484
gUnknown_85AC484: @ 0x85AC484
	.incbin "baserom_jp.gba", 0x5ac484, 0x158

	.globl gUnknown_85AC5DC
gUnknown_85AC5DC: @ 0x85AC5DC
	.incbin "baserom_jp.gba", 0x5ac5dc, 0x184

	.globl gUnknown_85AC760
gUnknown_85AC760: @ 0x85AC760
	.incbin "baserom_jp.gba", 0x5ac760, 0x1c4

	.globl gUnknown_85AC924
gUnknown_85AC924: @ 0x85AC924
	.incbin "baserom_jp.gba", 0x5ac924, 0x14

	.globl gUnknown_85AC938
gUnknown_85AC938: @ 0x85AC938
	.incbin "baserom_jp.gba", 0x5ac938, 0x24

	.globl gUnknown_85AC95C
gUnknown_85AC95C: @ 0x85AC95C
	.incbin "baserom_jp.gba", 0x5ac95c, 0x20

	.globl gUnknown_85AC97C
gUnknown_85AC97C: @ 0x85AC97C
	.incbin "baserom_jp.gba", 0x5ac97c, 0x28

	.globl gUnknown_85AC9A4
gUnknown_85AC9A4: @ 0x85AC9A4
	.incbin "baserom_jp.gba", 0x5ac9a4, 0x30

	.globl gUnknown_85AC9D4
gUnknown_85AC9D4: @ 0x85AC9D4
	.incbin "baserom_jp.gba", 0x5ac9d4, 0x18

	.globl sCableCarPlayerGraphicsIds
sCableCarPlayerGraphicsIds: @ 0x85AC9EC
	.byte 100 @ player 0
	.byte 105 @ player 1

	.globl sCableCarHikerGraphicsIds
sCableCarHikerGraphicsIds: @ 0x85AC9EE
	.byte 55 @ hiker gfx 0
	.byte 31 @ hiker gfx 1
	.byte 32 @ hiker gfx 2
	.byte 98 @ hiker gfx 3

	.globl sCableCarHikerCoords
sCableCarHikerCoords: @ 0x85AC9F2
	.hword 0 @ coord 0
	.hword 80 @ coord 1
	.hword 240 @ coord 2
	.hword 146 @ coord 3

	.globl sCableCarHikerMovementDelayTable
sCableCarHikerMovementDelayTable: @ 0x85AC9FA
	.byte 0 @ delay 0
	.byte 60 @ delay 1
	.byte 120 @ delay 2
	.byte 170 @ delay 3
	.byte 0 @ delay 4
	.byte 0 @ delay 5

	.globl sCableCarHikerCallbacks
sCableCarHikerCallbacks: @ 0x85ACA00
	.4byte SpriteCB_HikerGoingUp
	.4byte SpriteCB_HikerGoingDown

	.globl gUnknown_85ACA08
gUnknown_85ACA08: @ 0x85ACA08
	.incbin "baserom_jp.gba", 0x5aca08, 0x38

	.globl sBridgeReflectionVerticalOffsets
sBridgeReflectionVerticalOffsets: @ 0x85ACA40
	.hword 0x000C, 0x001C, 0x002C

	.globl sShadowEffectTemplateIds
sShadowEffectTemplateIds: @ 0x85ACA46
	.byte 0x00, 0x01, 0x02, 0x03

	.globl gShadowVerticalOffsets
gShadowVerticalOffsets: @ 0x85ACA4A
	.hword 0x0004, 0x0004, 0x0004, 0x0010, 0x0000

	.globl gFadeFootprintsTireTracksFuncs
gFadeFootprintsTireTracksFuncs: @ 0x85ACA54
	.4byte 0x08154BB9, 0x08154BDD

	.globl gAshFieldEffectFuncs
gAshFieldEffectFuncs: @ 0x85ACA5C
	.4byte 0x081553B9, 0x081553E9, 0x08155449

	.globl sSurfBlobDirectionAnims
sSurfBlobDirectionAnims: @ 0x85ACA68
	.byte 0x00, 0x00, 0x01, 0x02, 0x03, 0x00, 0x00, 0x01, 0x01, 0x00

	.globl sBobbingIntervals
sBobbingIntervals: @ 0x85ACA72
	.hword 0x0003, 0x0007, 0x0201, 0x0202, 0x0202, 0x0202, 0x0202, 0x0102, 0x0202, 0x0201, 0x0102, 0x0202
	.hword 0x0201, 0x0101, 0x0102, 0x0201, 0x0101, 0x0102, 0x0201, 0x0101, 0x0101, 0x0101, 0x0101, 0x0101
	.hword 0x0101, 0x0101, 0x0100, 0x0101, 0x0100, 0x0001, 0x0001, 0x0001, 0x0001, 0x0000, 0x0100, 0x0000
	.hword 0x0000, 0x0000, 0x0000, 0x0001, 0x0100, 0x0000, 0x0001, 0x0101, 0x0100, 0x0001, 0x0101, 0x0100
	.hword 0x0001, 0x0101, 0x0000, 0x0001, 0x0100, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
	.hword 0x0000, 0x0000, 0x0000, 0x00FF, 0xFF00, 0x0000, 0x00FF, 0xFFFF, 0xFF00, 0x00FF, 0xFFFF, 0xFFFF
	.hword 0xFFFF, 0xFEFF, 0x0000

	.globl gUnknown_85ACB08
gUnknown_85ACB08: @ 0x85ACB08
	.incbin "baserom_jp.gba", 0x5acb08, 0x220

	.globl gUnknown_85ACD28
gUnknown_85ACD28: @ 0x85ACD28
	.incbin "baserom_jp.gba", 0x5acd28, 0x380

	.globl sAffineAnims_Torment
sAffineAnims_Torment: @ 0x85AD0A8
	.hword 0xFFF4, 0x0008, 0x0400, 0x0000
	.hword 0x0014, 0xFFEC, 0x0400, 0x0000
	.hword 0xFFF8, 0x000C, 0x0400, 0x0000
	.hword 0x7FFF, 0x0000, 0x0000, 0x0000

gUnknown_85AD0C8: @ 0x85AD0C8
	.incbin "baserom_jp.gba", 0x5ad0c8, 0x90

	.globl DefenseCurlDeformMonAffineAnimCmds
DefenseCurlDeformMonAffineAnimCmds: @ 0x85AD158
	.hword 0xFFF4, 0x0014, 0x0800, 0x0000
	.hword 0x000C, 0xFFEC, 0x0800, 0x0000
	.hword 0x7FFD, 0x0002, 0x0000, 0x0000
	.hword 0x7FFF, 0x0000, 0x0000, 0x0000

	.globl gUnknown_85AD178
gUnknown_85AD178: @ 0x85AD178
	.incbin "baserom_jp.gba", 0x5ad178, 0x18

	.globl gUnknown_85AD190
gUnknown_85AD190: @ 0x85AD190
	.incbin "baserom_jp.gba", 0x5ad190, 0x18

	.globl gMiniTwinklingStarSpriteTemplate
gMiniTwinklingStarSpriteTemplate: @ 0x85AD1A8
	.hword 0x27F9, 0x27F9
	.4byte 0x084FD010, gDummySpriteAnimTable
	.4byte 0, gDummySpriteAffineAnimTable, 0x0815B4AD

	.globl gStockpileDeformMonAffineAnimCmds
gStockpileDeformMonAffineAnimCmds: @ 0x85AD1C0
	.incbin "baserom_jp.gba", 0x5ad1c0, 0x28

	.globl gSpitUpDeformMonAffineAnimCmds
gSpitUpDeformMonAffineAnimCmds: @ 0x85AD1E8
	.incbin "baserom_jp.gba", 0x5ad1e8, 0x50

	.globl gSwallowDeformMonAffineAnimCmds
gSwallowDeformMonAffineAnimCmds: @ 0x85AD238
	.incbin "baserom_jp.gba", 0x5ad238, 0x30

	.globl gMorningSunLightBeamCoordsTable
gMorningSunLightBeamCoordsTable: @ 0x85AD268
	.byte 0xE8, 0x18, 0xFC, 0x00

	.globl gGreenStarAnimCmds1
gGreenStarAnimCmds1: @ 0x85AD26C
	.hword 0x0000, 0x0006, 0x0004, 0x0006
	.hword 0xFFFE, 0x0000

	.globl gGreenStarAnimCmds2
gGreenStarAnimCmds2: @ 0x85AD278
	.hword 0x0008, 0x0006, 0xFFFF, 0x0000

	.globl gGreenStarAnimCmds3
gGreenStarAnimCmds3: @ 0x85AD280
	.hword 0x000C, 0x0006, 0xFFFF, 0x0000

	.globl gGreenStarAnimTable
gGreenStarAnimTable: @ 0x85AD288
	.4byte gGreenStarAnimCmds1, gGreenStarAnimCmds2, gGreenStarAnimCmds3

	.globl gGreenStarSpriteTemplate
gGreenStarSpriteTemplate: @ 0x85AD294
	.hword 0x2801, 0x2801
	.4byte 0x084FD018, gGreenStarAnimTable
	.4byte 0, gDummySpriteAffineAnimTable, 0x0815BD41

	.globl gDoomDesireLightBeamCoordTable
gDoomDesireLightBeamCoordTable: @ 0x85AD2AC
	.byte 0x78, 0x50, 0x28, 0x00

	.globl gDoomDesireLightBeamDelayTable
gDoomDesireLightBeamDelayTable: @ 0x85AD2B0
	.byte 0x00, 0x00, 0x00, 0x00, 0x32

	.globl gUnknown_85AD2B5
gUnknown_85AD2B5: @ 0x85AD2B5
	.incbin "baserom_jp.gba", 0x5ad2b5, 0x3

	.globl gStrongFrustrationAffineAnimCmds
gStrongFrustrationAffineAnimCmds: @ 0x85AD2B8
	.hword 0x0000, 0xFFF1, 0x0700, 0x0000
	.hword 0x0000, 0x000F, 0x0700, 0x0000
	.hword 0x7FFD, 0x0002, 0x0000, 0x0000
	.hword 0x7FFF, 0x0000, 0x0000, 0x0000

	.globl gUnknown_85AD2D8
gUnknown_85AD2D8: @ 0x85AD2D8
	.incbin "baserom_jp.gba", 0x5ad2d8, 0x120

	.globl gDeepInhaleAffineAnimCmds
gDeepInhaleAffineAnimCmds: @ 0x85AD3F8
	.incbin "baserom_jp.gba", 0x5ad3f8, 0x30

	.globl gUnknown_85AD428
gUnknown_85AD428: @ 0x85AD428
	.incbin "baserom_jp.gba", 0x5ad428, 0x12c

	.globl gFacadeSquishAffineAnimCmds
gFacadeSquishAffineAnimCmds: @ 0x85AD554
	.hword 0xFFF0, 0x0010, 0x0600, 0x0000
	.hword 0x0010, 0xFFF0, 0x0C00, 0x0000
	.hword 0xFFF0, 0x0010, 0x0600, 0x0000
	.hword 0x7FFF, 0x0000, 0x0000, 0x0000

	.globl gFacadeSweatDropSpriteTemplate
gFacadeSweatDropSpriteTemplate: @ 0x85AD574
	.hword 0x2803, 0x2803
	.4byte 0x084FD010, gDummySpriteAnimTable
	.4byte 0, gDummySpriteAffineAnimTable, 0x0815DDF9

	.globl gFacadeBlendColors
gFacadeBlendColors: @ 0x85AD58C
	.hword 0x073C, 0x16BC, 0x225B, 0x2DDB, 0x3D5A, 0x48FA, 0x5479, 0x6419, 0x5C19, 0x5019, 0x4019, 0x3419
	.hword 0x281A, 0x181A, 0x0C1A, 0x001B, 0x003B, 0x00BB, 0x013B, 0x019B, 0x021C, 0x027C, 0x02FC, 0x037D
	.hword 0x0000, 0x0003

	.globl gUnknown_85AD5C0
gUnknown_85AD5C0: @ 0x85AD5C0
	.incbin "baserom_jp.gba", 0x5ad5c0, 0x34

	.globl gGlareEyeDotSpriteTemplate
gGlareEyeDotSpriteTemplate: @ 0x85AD5F4
	.hword 0x2808, 0x2808
	.4byte 0x084FD010, gDummySpriteAnimTable
	.4byte 0, gDummySpriteAffineAnimTable, 0x0815E33D

	.globl gUnknown_85AD60C
gUnknown_85AD60C: @ 0x85AD60C
	.incbin "baserom_jp.gba", 0x5ad60c, 0x48

	.globl gBarrageBallSpriteTemplate
gBarrageBallSpriteTemplate: @ 0x85AD654
	.hword 0x280E, 0x280E
	.4byte 0x084FD080, gDummySpriteAnimTable
	.4byte 0, 0x085AD64C, 0x08007141

	.globl gUnknown_85AD66C
gUnknown_85AD66C: @ 0x85AD66C
	.incbin "baserom_jp.gba", 0x5ad66c, 0x18

	.globl gSmellingSaltsSquishAffineAnimCmds
gSmellingSaltsSquishAffineAnimCmds: @ 0x85AD684
	.hword 0x0000, 0xFFF0, 0x0600, 0x0000
	.hword 0x0000, 0x0010, 0x0600, 0x0000
	.hword 0x7FFF, 0x0000, 0x0000, 0x0000

	.globl gUnknown_85AD69C
gUnknown_85AD69C: @ 0x85AD69C
	.incbin "baserom_jp.gba", 0x5ad69c, 0x134

	.globl gSlackOffSquishAffineAnimCmds
gSlackOffSquishAffineAnimCmds: @ 0x85AD7D0
	.incbin "baserom_jp.gba", 0x5ad7d0, 0x30

	.globl gUnknown_85AD800
gUnknown_85AD800: @ 0x85AD800
	.incbin "baserom_jp.gba", 0x5ad800, 0x1a0

	.globl gText_TeachWhichMoveToPkmn
