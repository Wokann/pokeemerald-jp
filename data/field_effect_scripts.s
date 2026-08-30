	.section script_data, "aw", %progbits
	.include "asm/macros.inc"

@ This JP-located owner mirrors pokeemerald data/field_effect_scripts.s.
@ Unconverted bytes remain in their verified physical ROM span.
	.align 2
	.globl gFieldEffectScriptPointers
gFieldEffectScriptPointers: @ 0x8289F5C
	.4byte gFieldEffectScript_ExclamationMarkIcon1 @ FLDEFF_EXCLAMATION_MARK_ICON
	.4byte gFieldEffectScript_UseCutOnTallGrass @ FLDEFF_USE_CUT_ON_GRASS
	.4byte gFieldEffectScript_UseCutOnTree @ FLDEFF_USE_CUT_ON_TREE
	.4byte gFieldEffectScript_Shadow @ FLDEFF_SHADOW
	.4byte gFieldEffectScript_TallGrass @ FLDEFF_TALL_GRASS
	.4byte gFieldEffectScript_Ripple @ FLDEFF_RIPPLE
	.4byte gFieldEffectScript_FieldMoveShowMon @ FLDEFF_FIELD_MOVE_SHOW_MON
	.4byte gFieldEffectScript_Ash @ FLDEFF_ASH
	.4byte gFieldEffectScript_SurfBlob @ FLDEFF_SURF_BLOB
	.4byte gFieldEffectScript_UseSurf @ FLDEFF_USE_SURF
	.4byte gFieldEffectScript_GroundImpactDust @ FLDEFF_DUST
	.4byte gFieldEffectScript_UseSecretPowerCave @ FLDEFF_USE_SECRET_POWER_CAVE
	.4byte gFieldEffectScript_JumpTallGrass @ FLDEFF_JUMP_TALL_GRASS
	.4byte gFieldEffectScript_SandFootprints @ FLDEFF_SAND_FOOTPRINTS
	.4byte gFieldEffectScript_JumpBigSplash @ FLDEFF_JUMP_BIG_SPLASH
	.4byte gFieldEffectScript_Splash @ FLDEFF_SPLASH
	.4byte gFieldEffectScript_JumpSmallSplash @ FLDEFF_JUMP_SMALL_SPLASH
	.4byte gFieldEffectScript_LongGrass @ FLDEFF_LONG_GRASS
	.4byte gFieldEffectScript_JumpLongGrass @ FLDEFF_JUMP_LONG_GRASS
	.4byte gFieldEffectScript_UnusedGrass @ FLDEFF_UNUSED_GRASS
	.4byte gFieldEffectScript_UnusedGrass2 @ FLDEFF_UNUSED_GRASS_2
	.4byte gFieldEffectScript_UnusedSand @ FLDEFF_UNUSED_SAND
	.4byte gFieldEffectScript_WaterSurfacing @ FLDEFF_WATER_SURFACING
	.4byte gFieldEffectScript_BerryTreeGrowthSparkle @ FLDEFF_BERRY_TREE_GROWTH_SPARKLE
	.4byte gFieldEffectScript_DeepSandFootprints @ FLDEFF_DEEP_SAND_FOOTPRINTS
	.4byte gFieldEffectScript_PokeCenterHeal @ FLDEFF_POKECENTER_HEAL
	.4byte gFieldEffectScript_UseSecretPowerTree @ FLDEFF_USE_SECRET_POWER_TREE
	.4byte gFieldEffectScript_UseSecretPowerShrub @ FLDEFF_USE_SECRET_POWER_SHRUB
	.4byte gFieldEffectScript_TreeDisguise @ FLDEFF_TREE_DISGUISE
	.4byte gFieldEffectScript_MountainDisguise @ FLDEFF_MOUNTAIN_DISGUISE
	.4byte gFieldEffectScript_NPCUseFly @ FLDEFF_NPCFLY_OUT
	.4byte gFieldEffectScript_UseFly @ FLDEFF_USE_FLY
	.4byte gFieldEffectScript_FlyIn @ FLDEFF_FLY_IN
	.4byte gFieldEffectScript_QuestionMarkIcon @ FLDEFF_QUESTION_MARK_ICON
	.4byte gFieldEffectScript_FeetInFlowingWater @ FLDEFF_FEET_IN_FLOWING_WATER
	.4byte gFieldEffectScript_BikeTireTracks @ FLDEFF_BIKE_TIRE_TRACKS
	.4byte gFieldEffectScript_SandDisguisePlaceholder @ FLDEFF_SAND_DISGUISE
	.4byte gFieldEffectScript_UseRockSmash @ FLDEFF_USE_ROCK_SMASH
	.4byte gFieldEffectScript_UseDig @ FLDEFF_USE_DIG
	.4byte gFieldEffectScript_SandPile @ FLDEFF_SAND_PILE
	.4byte gFieldEffectScript_UseStrength @ FLDEFF_USE_STRENGTH
	.4byte gFieldEffectScript_ShortGrass @ FLDEFF_SHORT_GRASS
	.4byte gFieldEffectScript_HotSpringsWater @ FLDEFF_HOT_SPRINGS_WATER
	.4byte gFieldEffectScript_UseWaterfall @ FLDEFF_USE_WATERFALL
	.4byte gFieldEffectScript_UseDive @ FLDEFF_USE_DIVE
	.4byte gFieldEffectScript_PokeballTrail @ FLDEFF_POKEBALL_TRAIL
	.4byte gFieldEffectScript_HeartIcon @ FLDEFF_HEART_ICON
	.4byte gFieldEffectScript_Nop47 @ FLDEFF_NOP_47
	.4byte gFieldEffectScript_Nop48 @ FLDEFF_NOP_48
	.4byte gFieldEffectScript_AshPuff @ FLDEFF_ASH_PUFF
	.4byte gFieldEffectScript_AshLaunch @ FLDEFF_ASH_LAUNCH
	.4byte gFieldEffectScript_SweetScent @ FLDEFF_SWEET_SCENT
	.4byte gFieldEffectScript_SandPillar @ FLDEFF_SAND_PILLAR
	.4byte gFieldEffectScript_Bubbles @ FLDEFF_BUBBLES
	.4byte gFieldEffectScript_Sparkle @ FLDEFF_SPARKLE
	.4byte gFieldEffectScript_ShowSecretPowerCave @ FLDEFF_SECRET_POWER_CAVE
	.4byte gFieldEffectScript_ShowSecretPowerTree @ FLDEFF_SECRET_POWER_TREE
	.4byte gFieldEffectScript_ShowSecretPowerShrub @ FLDEFF_SECRET_POWER_SHRUB
	.4byte gFieldEffectScript_ShowCutGrass @ FLDEFF_CUT_GRASS
	.4byte gFieldEffectScript_FieldMoveShowMonInit @ FLDEFF_FIELD_MOVE_SHOW_MON_INIT
	.4byte gFieldEffectScript_UsePuzzleEffect @ FLDEFF_USE_TOMB_PUZZLE_EFFECT
	.4byte gFieldEffectScript_SecretBaseBootPC @ FLDEFF_PCTURN_ON
	.4byte gFieldEffectScript_HallOfFameRecord @ FLDEFF_HALL_OF_FAME_RECORD
	.4byte gFieldEffectScript_UseTeleport @ FLDEFF_USE_TELEPORT
	.4byte gFieldEffectScript_RayquazaSpotlight @ FLDEFF_RAYQUAZA_SPOTLIGHT
	.4byte gFieldEffectScript_DestroyDeoxysRock @ FLDEFF_DESTROY_DEOXYS_ROCK
	.4byte gFieldEffectScript_MoveDeoxysRock @ FLDEFF_MOVE_DEOXYS_ROCK

gFieldEffectScript_ExclamationMarkIcon1: @ 0x828A068
	.incbin "baserom_jp.gba", 0x28a068, 0x6

gFieldEffectScript_UseCutOnTallGrass: @ 0x828A06E
	.incbin "baserom_jp.gba", 0x28a06e, 0x6

gFieldEffectScript_UseCutOnTree: @ 0x828A074
	.incbin "baserom_jp.gba", 0x28a074, 0x6

gFieldEffectScript_Shadow: @ 0x828A07A
	.incbin "baserom_jp.gba", 0x28a07a, 0x6

gFieldEffectScript_TallGrass: @ 0x828A080
	.incbin "baserom_jp.gba", 0x28a080, 0xa

gFieldEffectScript_Ripple: @ 0x828A08A
	.incbin "baserom_jp.gba", 0x28a08a, 0xa

gFieldEffectScript_FieldMoveShowMon: @ 0x828A094
	.incbin "baserom_jp.gba", 0x28a094, 0x6

gFieldEffectScript_Ash: @ 0x828A09A
	.incbin "baserom_jp.gba", 0x28a09a, 0xa

gFieldEffectScript_SurfBlob: @ 0x828A0A4
	.incbin "baserom_jp.gba", 0x28a0a4, 0x6

gFieldEffectScript_UseSurf: @ 0x828A0AA
	.incbin "baserom_jp.gba", 0x28a0aa, 0x6

gFieldEffectScript_GroundImpactDust: @ 0x828A0B0
	.incbin "baserom_jp.gba", 0x28a0b0, 0xa

gFieldEffectScript_UseSecretPowerCave: @ 0x828A0BA
	.incbin "baserom_jp.gba", 0x28a0ba, 0x6

gFieldEffectScript_JumpTallGrass: @ 0x828A0C0
	.incbin "baserom_jp.gba", 0x28a0c0, 0xa

gFieldEffectScript_SandFootprints: @ 0x828A0CA
	.incbin "baserom_jp.gba", 0x28a0ca, 0xa

gFieldEffectScript_JumpBigSplash: @ 0x828A0D4
	.incbin "baserom_jp.gba", 0x28a0d4, 0xa

gFieldEffectScript_Splash: @ 0x828A0DE
	.incbin "baserom_jp.gba", 0x28a0de, 0xa

gFieldEffectScript_JumpSmallSplash: @ 0x828A0E8
	.incbin "baserom_jp.gba", 0x28a0e8, 0xa

gFieldEffectScript_LongGrass: @ 0x828A0F2
	.incbin "baserom_jp.gba", 0x28a0f2, 0xa

gFieldEffectScript_JumpLongGrass: @ 0x828A0FC
	.incbin "baserom_jp.gba", 0x28a0fc, 0xa

gFieldEffectScript_UnusedGrass: @ 0x828A106
	.incbin "baserom_jp.gba", 0x28a106, 0xa

gFieldEffectScript_UnusedGrass2: @ 0x828A110
	.incbin "baserom_jp.gba", 0x28a110, 0xa

gFieldEffectScript_UnusedSand: @ 0x828A11A
	.incbin "baserom_jp.gba", 0x28a11a, 0xa

gFieldEffectScript_WaterSurfacing: @ 0x828A124
	.incbin "baserom_jp.gba", 0x28a124, 0xa

gFieldEffectScript_BerryTreeGrowthSparkle: @ 0x828A12E
	.incbin "baserom_jp.gba", 0x28a12e, 0x6

gFieldEffectScript_DeepSandFootprints: @ 0x828A134
	.incbin "baserom_jp.gba", 0x28a134, 0xa

gFieldEffectScript_PokeCenterHeal: @ 0x828A13E
	.incbin "baserom_jp.gba", 0x28a13e, 0xf

gFieldEffectScript_UseSecretPowerTree: @ 0x828A14D
	.incbin "baserom_jp.gba", 0x28a14d, 0x6

gFieldEffectScript_UseSecretPowerShrub: @ 0x828A153
	.incbin "baserom_jp.gba", 0x28a153, 0x6

gFieldEffectScript_TreeDisguise: @ 0x828A159
	.incbin "baserom_jp.gba", 0x28a159, 0x6

gFieldEffectScript_MountainDisguise: @ 0x828A15F
	.incbin "baserom_jp.gba", 0x28a15f, 0x6

gFieldEffectScript_NPCUseFly: @ 0x828A165
	.incbin "baserom_jp.gba", 0x28a165, 0x6

gFieldEffectScript_UseFly: @ 0x828A16B
	.incbin "baserom_jp.gba", 0x28a16b, 0x6

gFieldEffectScript_FlyIn: @ 0x828A171
	.incbin "baserom_jp.gba", 0x28a171, 0x6

gFieldEffectScript_QuestionMarkIcon: @ 0x828A177
	.incbin "baserom_jp.gba", 0x28a177, 0x6

gFieldEffectScript_FeetInFlowingWater: @ 0x828A17D
	.incbin "baserom_jp.gba", 0x28a17d, 0xa

gFieldEffectScript_BikeTireTracks: @ 0x828A187
	.incbin "baserom_jp.gba", 0x28a187, 0xa

gFieldEffectScript_SandDisguisePlaceholder: @ 0x828A191
	.incbin "baserom_jp.gba", 0x28a191, 0x6

gFieldEffectScript_UseRockSmash: @ 0x828A197
	.incbin "baserom_jp.gba", 0x28a197, 0x6

gFieldEffectScript_UseStrength: @ 0x828A19D
	.incbin "baserom_jp.gba", 0x28a19d, 0x6

gFieldEffectScript_UseDig: @ 0x828A1A3
	.incbin "baserom_jp.gba", 0x28a1a3, 0x6

gFieldEffectScript_SandPile: @ 0x828A1A9
	.incbin "baserom_jp.gba", 0x28a1a9, 0xa

gFieldEffectScript_ShortGrass: @ 0x828A1B3
	.incbin "baserom_jp.gba", 0x28a1b3, 0xa

gFieldEffectScript_HotSpringsWater: @ 0x828A1BD
	.incbin "baserom_jp.gba", 0x28a1bd, 0xa

gFieldEffectScript_UseWaterfall: @ 0x828A1C7
	.incbin "baserom_jp.gba", 0x28a1c7, 0x6

gFieldEffectScript_UseDive: @ 0x828A1CD
	.incbin "baserom_jp.gba", 0x28a1cd, 0x6

gFieldEffectScript_PokeballTrail: @ 0x828A1D3
	.incbin "baserom_jp.gba", 0x28a1d3, 0xb

gFieldEffectScript_HeartIcon: @ 0x828A1DE
	.incbin "baserom_jp.gba", 0x28a1de, 0xa

gFieldEffectScript_Nop47: @ 0x828A1E8
	.incbin "baserom_jp.gba", 0x28a1e8, 0x6

gFieldEffectScript_Nop48: @ 0x828A1EE
	.incbin "baserom_jp.gba", 0x28a1ee, 0x6

gFieldEffectScript_AshPuff: @ 0x828A1F4
	.incbin "baserom_jp.gba", 0x28a1f4, 0xa

gFieldEffectScript_AshLaunch: @ 0x828A1FE
	.incbin "baserom_jp.gba", 0x28a1fe, 0xa

gFieldEffectScript_SweetScent: @ 0x828A208
	.incbin "baserom_jp.gba", 0x28a208, 0x6

gFieldEffectScript_SandPillar: @ 0x828A20E
	.incbin "baserom_jp.gba", 0x28a20e, 0xa

gFieldEffectScript_Bubbles: @ 0x828A218
	.incbin "baserom_jp.gba", 0x28a218, 0xa

gFieldEffectScript_Sparkle: @ 0x828A222
	.incbin "baserom_jp.gba", 0x28a222, 0xa

gFieldEffectScript_ShowSecretPowerCave: @ 0x828A22C
	.incbin "baserom_jp.gba", 0x28a22c, 0xa

gFieldEffectScript_ShowSecretPowerTree: @ 0x828A236
	.incbin "baserom_jp.gba", 0x28a236, 0xa

gFieldEffectScript_ShowSecretPowerShrub: @ 0x828A240
	.incbin "baserom_jp.gba", 0x28a240, 0xa

gFieldEffectScript_ShowCutGrass: @ 0x828A24A
	.incbin "baserom_jp.gba", 0x28a24a, 0xa

gFieldEffectScript_FieldMoveShowMonInit: @ 0x828A254
	.incbin "baserom_jp.gba", 0x28a254, 0x6

gFieldEffectScript_UsePuzzleEffect: @ 0x828A25A
	.incbin "baserom_jp.gba", 0x28a25a, 0x6

gFieldEffectScript_SecretBaseBootPC: @ 0x828A260
	.incbin "baserom_jp.gba", 0x28a260, 0x6

gFieldEffectScript_HallOfFameRecord: @ 0x828A266
	.incbin "baserom_jp.gba", 0x28a266, 0xf

gFieldEffectScript_UseTeleport: @ 0x828A275
	.incbin "baserom_jp.gba", 0x28a275, 0x6

gFieldEffectScript_RayquazaSpotlight: @ 0x828A27B
	.incbin "baserom_jp.gba", 0x28a27b, 0x6

gFieldEffectScript_DestroyDeoxysRock: @ 0x828A281
	.incbin "baserom_jp.gba", 0x28a281, 0x6

gFieldEffectScript_MoveDeoxysRock: @ 0x828A287
	.incbin "baserom_jp.gba", 0x28a287, 0x9
