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

	.globl sDigitalDisplayRegBonusDelays
sDigitalDisplayRegBonusDelays: @ 0x85845D2
	.incbin "baserom_jp.gba", 0x5845d2, 0x10

	.globl sDigitalDisplayBigBonusOffsets
sDigitalDisplayBigBonusOffsets: @ 0x85845E2
	.incbin "baserom_jp.gba", 0x5845e2, 0x10

	.section .rodata.8584638
	.globl sInitialReelPositions
sInitialReelPositions: @ 0x8584638
	.incbin "baserom_jp.gba", 0x584638, 0xc

	.globl sSpecialDrawOdds
sSpecialDrawOdds: @ 0x8584644
	.incbin "baserom_jp.gba", 0x584644, 0x12

	.globl sBiasProbabilities_Special
sBiasProbabilities_Special: @ 0x8584656
	.incbin "baserom_jp.gba", 0x584656, 0x12

	.globl sBiasProbabilities_Regular
sBiasProbabilities_Regular: @ 0x8584668
	.incbin "baserom_jp.gba", 0x584668, 0x1e

	.globl sReelTimeProbabilities_NormalGame
sReelTimeProbabilities_NormalGame: @ 0x8584686
	.incbin "baserom_jp.gba", 0x584686, 0x66

	.globl sReelTimeProbabilities_LuckyGame
sReelTimeProbabilities_LuckyGame: @ 0x85846EC
	.incbin "baserom_jp.gba", 0x5846ec, 0x66

	.section .rodata.858475C
	.globl sReelTimeSpeed_Probabilities
sReelTimeSpeed_Probabilities: @ 0x858475C
	.incbin "baserom_jp.gba", 0x58475c, 0x14

	.globl sQuarterSpeed_ProbabilityBoost
sQuarterSpeed_ProbabilityBoost: @ 0x8584770
	.incbin "baserom_jp.gba", 0x584770, 0xa

	.section .rodata.8584782
	.globl sBiasesSpecial
sBiasesSpecial: @ 0x8584782
	.incbin "baserom_jp.gba", 0x584782, 0x6

	.globl sBiasesRegular
sBiasesRegular: @ 0x8584788
	.incbin "baserom_jp.gba", 0x584788, 0xa

	.section .rodata.85847BE
	.globl sDigitalDisplay_SpriteCoords
sDigitalDisplay_SpriteCoords: @ 0x85847BE
	.incbin "baserom_jp.gba", 0x5847be, 0x8e

	.globl sDigitalDisplay_SpriteCallbacks
sDigitalDisplay_SpriteCallbacks: @ 0x858484C
	.incbin "baserom_jp.gba", 0x58484c, 0x8c

	.section .rodata.85849C0
	.globl gUnknown_85849C0
gUnknown_85849C0: @ 0x85849C0
	.incbin "baserom_jp.gba", 0x5849c0, 0x2a4

	.globl sSpriteTemplate_ReelSymbol
sSpriteTemplate_ReelSymbol: @ 0x8584C64
	.incbin "baserom_jp.gba", 0x584c64, 0x18

	.globl sSpriteTemplate_CoinNumber
sSpriteTemplate_CoinNumber: @ 0x8584C7C
	.incbin "baserom_jp.gba", 0x584c7c, 0x18

	.globl sSpriteTemplate_ReelBackground
sSpriteTemplate_ReelBackground: @ 0x8584C94
	.incbin "baserom_jp.gba", 0x584c94, 0x18

	.globl sSpriteTemplate_ReelTimePikachu
sSpriteTemplate_ReelTimePikachu: @ 0x8584CAC
	.incbin "baserom_jp.gba", 0x584cac, 0x18

	.globl sSpriteTemplate_ReelTimeMachineAntennae
sSpriteTemplate_ReelTimeMachineAntennae: @ 0x8584CC4
	.incbin "baserom_jp.gba", 0x584cc4, 0x18

	.globl sSpriteTemplate_ReelTimeMachine
sSpriteTemplate_ReelTimeMachine: @ 0x8584CDC
	.incbin "baserom_jp.gba", 0x584cdc, 0x18

	.globl sSpriteTemplate_BrokenReelTimeMachine
sSpriteTemplate_BrokenReelTimeMachine: @ 0x8584CF4
	.incbin "baserom_jp.gba", 0x584cf4, 0x18

	.globl sSpriteTemplate_ReelTimeNumbers
sSpriteTemplate_ReelTimeNumbers: @ 0x8584D0C
	.incbin "baserom_jp.gba", 0x584d0c, 0x18

	.globl sSpriteTemplate_ReelTimeShadow
sSpriteTemplate_ReelTimeShadow: @ 0x8584D24
	.incbin "baserom_jp.gba", 0x584d24, 0x18

	.globl sSpriteTemplate_ReelTimeNumberGap
sSpriteTemplate_ReelTimeNumberGap: @ 0x8584D3C
	.incbin "baserom_jp.gba", 0x584d3c, 0x18

	.globl sSpriteTemplate_ReelTimeBolt
sSpriteTemplate_ReelTimeBolt: @ 0x8584D54
	.incbin "baserom_jp.gba", 0x584d54, 0x18

	.globl sSpriteTemplate_ReelTimePikachuAura
sSpriteTemplate_ReelTimePikachuAura: @ 0x8584D6C
	.incbin "baserom_jp.gba", 0x584d6c, 0x18

	.globl sSpriteTemplate_ReelTimeExplosion
sSpriteTemplate_ReelTimeExplosion: @ 0x8584D84
	.incbin "baserom_jp.gba", 0x584d84, 0x18

	.globl sSpriteTemplate_ReelTimeDuck
sSpriteTemplate_ReelTimeDuck: @ 0x8584D9C
	.incbin "baserom_jp.gba", 0x584d9c, 0x18

	.globl sSpriteTemplate_ReelTimeSmoke
sSpriteTemplate_ReelTimeSmoke: @ 0x8584DB4
	.incbin "baserom_jp.gba", 0x584db4, 0x168

	.globl sSpriteTemplate_PikaPowerBolt
sSpriteTemplate_PikaPowerBolt: @ 0x8584F1C
	.incbin "baserom_jp.gba", 0x584f1c, 0x28

	.globl sSubspriteTable_ReelBackground
sSubspriteTable_ReelBackground: @ 0x8584F44
	.incbin "baserom_jp.gba", 0x584f44, 0x20

	.globl sSubspriteTable_ReelTimeMachineAntennae
sSubspriteTable_ReelTimeMachineAntennae: @ 0x8584F64
	.incbin "baserom_jp.gba", 0x584f64, 0x14

	.globl sSubspriteTable_ReelTimeMachine
sSubspriteTable_ReelTimeMachine: @ 0x8584F78
	.incbin "baserom_jp.gba", 0x584f78, 0x1c

	.globl sSubspriteTable_BrokenReelTimeMachine
sSubspriteTable_BrokenReelTimeMachine: @ 0x8584F94
	.incbin "baserom_jp.gba", 0x584f94, 0x18

	.globl sSubspriteTable_ReelTimeShadow
sSubspriteTable_ReelTimeShadow: @ 0x8584FAC
	.incbin "baserom_jp.gba", 0x584fac, 0x14

	.globl sSubspriteTable_ReelTimeNumberGap
sSubspriteTable_ReelTimeNumberGap: @ 0x8584FC0
	.incbin "baserom_jp.gba", 0x584fc0, 0x228

	.globl sSpriteTemplates_DigitalDisplay
sSpriteTemplates_DigitalDisplay: @ 0x85851E8
	.incbin "baserom_jp.gba", 0x5851e8, 0x68

	.globl sSubspriteTables_DigitalDisplay
sSubspriteTables_DigitalDisplay: @ 0x8585250
	.incbin "baserom_jp.gba", 0x585250, 0x68

	.globl sSlotMachineSpriteSheets
sSlotMachineSpriteSheets: @ 0x85852B8
	.incbin "baserom_jp.gba", 0x5852b8, 0xb0

	.globl sReelBackground_Tilemap
sReelBackground_Tilemap: @ 0x8585368
	.incbin "baserom_jp.gba", 0x585368, 0xe4

	.globl gSlotMachineMenu_Pal
gSlotMachineMenu_Pal: @ 0x858544C
	.incbin "baserom_jp.gba", 0x58544c, 0x94

	.section .rodata.85854EC
	.globl gUnknown_85854EC
gUnknown_85854EC: @ 0x85854EC
	.incbin "baserom_jp.gba", 0x5854ec, 0x14

	.section .rodata.8585542
	.globl gUnknown_8585542
gUnknown_8585542: @ 0x8585542
	.incbin "baserom_jp.gba", 0x585542, 0x62

	.section .rodata.85855B4
	.globl gUnknown_85855B4
gUnknown_85855B4: @ 0x85855B4
	.incbin "baserom_jp.gba", 0x5855b4, 0x60

	.globl sPokeballShiningPalTable
sPokeballShiningPalTable: @ 0x8585614
	.incbin "baserom_jp.gba", 0x585614, 0x10

	.globl sDigitalDisplay_Pal
sDigitalDisplay_Pal: @ 0x8585624
	.incbin "baserom_jp.gba", 0x585624, 0x4

	.globl sUnkPalette
sUnkPalette: @ 0x8585628
	.incbin "baserom_jp.gba", 0x585628, 0x20

	.globl sSlotMachineSpritePalettes
sSlotMachineSpritePalettes: @ 0x8585648
	.incbin "baserom_jp.gba", 0x585648, 0x48

	.globl gSlotMachineDigitalDisplay_Gfx
gSlotMachineDigitalDisplay_Gfx: @ 0x8585690
	.incbin "baserom_jp.gba", 0x585690, 0x768

	.globl sReelTimeGfx
sReelTimeGfx: @ 0x8585DF8
	.incbin "baserom_jp.gba", 0x585df8, 0x1154

	.globl gSlotMachineMenu_Gfx
gSlotMachineMenu_Gfx: @ 0x8586F4C
	.incbin "baserom_jp.gba", 0x586f4c, 0xba0

	.globl gSlotMachineMenu_Tilemap
gSlotMachineMenu_Tilemap: @ 0x8587AEC
	.incbin "baserom_jp.gba", 0x587aec, 0x4b0

	.section .rodata.8588154
	.globl gSlotMachineInfoBox_Tilemap
gSlotMachineInfoBox_Tilemap: @ 0x8588154
	.incbin "baserom_jp.gba", 0x588154, 0x4b0
