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
	field_eff_callnative FldEff_ExclamationMarkIcon
	field_eff_end

gFieldEffectScript_UseCutOnTallGrass: @ 0x828A06E
	field_eff_callnative FldEff_UseCutOnGrass
	field_eff_end

gFieldEffectScript_UseCutOnTree: @ 0x828A074
	field_eff_callnative FldEff_UseCutOnTree
	field_eff_end

gFieldEffectScript_Shadow: @ 0x828A07A
	field_eff_callnative FldEff_Shadow
	field_eff_end

gFieldEffectScript_TallGrass: @ 0x828A080
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_TallGrass
	field_eff_end

gFieldEffectScript_Ripple: @ 0x828A08A
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_Ripple
	field_eff_end

gFieldEffectScript_FieldMoveShowMon: @ 0x828A094
	field_eff_callnative FldEff_FieldMoveShowMon
	field_eff_end

gFieldEffectScript_Ash: @ 0x828A09A
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_Ash
	field_eff_end

gFieldEffectScript_SurfBlob: @ 0x828A0A4
	field_eff_callnative FldEff_SurfBlob
	field_eff_end

gFieldEffectScript_UseSurf: @ 0x828A0AA
	field_eff_callnative FldEff_UseSurf
	field_eff_end

gFieldEffectScript_GroundImpactDust: @ 0x828A0B0
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_Dust
	field_eff_end

gFieldEffectScript_UseSecretPowerCave: @ 0x828A0BA
	field_eff_callnative FldEff_UseSecretPowerCave
	field_eff_end

gFieldEffectScript_JumpTallGrass: @ 0x828A0C0
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_JumpTallGrass
	field_eff_end

gFieldEffectScript_SandFootprints: @ 0x828A0CA
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_SandFootprints
	field_eff_end

gFieldEffectScript_JumpBigSplash: @ 0x828A0D4
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_JumpBigSplash
	field_eff_end

gFieldEffectScript_Splash: @ 0x828A0DE
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_Splash
	field_eff_end

gFieldEffectScript_JumpSmallSplash: @ 0x828A0E8
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_JumpSmallSplash
	field_eff_end

gFieldEffectScript_LongGrass: @ 0x828A0F2
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_LongGrass
	field_eff_end

gFieldEffectScript_JumpLongGrass: @ 0x828A0FC
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_JumpLongGrass
	field_eff_end

gFieldEffectScript_UnusedGrass: @ 0x828A106
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_UnusedGrass
	field_eff_end

gFieldEffectScript_UnusedGrass2: @ 0x828A110
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_UnusedGrass2
	field_eff_end

gFieldEffectScript_UnusedSand: @ 0x828A11A
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_UnusedSand
	field_eff_end

gFieldEffectScript_WaterSurfacing: @ 0x828A124
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_WaterSurfacing
	field_eff_end

gFieldEffectScript_BerryTreeGrowthSparkle: @ 0x828A12E
	field_eff_callnative FldEff_BerryTreeGrowthSparkle
	field_eff_end

gFieldEffectScript_DeepSandFootprints: @ 0x828A134
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_DeepSandFootprints
	field_eff_end

gFieldEffectScript_PokeCenterHeal: @ 0x828A13E
	field_eff_loadfadedpal gSpritePalette_PokeballGlow
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_PokecenterHeal
	field_eff_end

gFieldEffectScript_UseSecretPowerTree: @ 0x828A14D
	field_eff_callnative FldEff_UseSecretPowerShrub
	field_eff_end

gFieldEffectScript_UseSecretPowerShrub: @ 0x828A153
	field_eff_callnative FldEff_UseSecretPowerTree
	field_eff_end

gFieldEffectScript_TreeDisguise: @ 0x828A159
	field_eff_callnative ShowTreeDisguiseFieldEffect
	field_eff_end

gFieldEffectScript_MountainDisguise: @ 0x828A15F
	field_eff_callnative ShowMountainDisguiseFieldEffect
	field_eff_end

gFieldEffectScript_NPCUseFly: @ 0x828A165
	field_eff_callnative FldEff_NPCFlyOut
	field_eff_end

gFieldEffectScript_UseFly: @ 0x828A16B
	field_eff_callnative FldEff_UseFly
	field_eff_end

gFieldEffectScript_FlyIn: @ 0x828A171
	field_eff_callnative FldEff_FlyIn
	field_eff_end

gFieldEffectScript_QuestionMarkIcon: @ 0x828A177
	field_eff_callnative FldEff_QuestionMarkIcon
	field_eff_end

gFieldEffectScript_FeetInFlowingWater: @ 0x828A17D
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_FeetInFlowingWater
	field_eff_end

gFieldEffectScript_BikeTireTracks: @ 0x828A187
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_BikeTireTracks
	field_eff_end

gFieldEffectScript_SandDisguisePlaceholder: @ 0x828A191
	field_eff_callnative ShowSandDisguiseFieldEffect
	field_eff_end

gFieldEffectScript_UseRockSmash: @ 0x828A197
	field_eff_callnative FldEff_UseRockSmash
	field_eff_end

gFieldEffectScript_UseStrength: @ 0x828A19D
	field_eff_callnative FldEff_UseStrength
	field_eff_end

gFieldEffectScript_UseDig: @ 0x828A1A3
	field_eff_callnative FldEff_UseDig
	field_eff_end

gFieldEffectScript_SandPile: @ 0x828A1A9
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_SandPile
	field_eff_end

gFieldEffectScript_ShortGrass: @ 0x828A1B3
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_ShortGrass
	field_eff_end

gFieldEffectScript_HotSpringsWater: @ 0x828A1BD
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_HotSpringsWater
	field_eff_end

gFieldEffectScript_UseWaterfall: @ 0x828A1C7
	field_eff_callnative FldEff_UseWaterfall
	field_eff_end

gFieldEffectScript_UseDive: @ 0x828A1CD
	field_eff_callnative FldEff_UseDive
	field_eff_end

gFieldEffectScript_PokeballTrail: @ 0x828A1D3
	field_eff_loadpal gSpritePalette_Pokeball
	field_eff_callnative FldEff_PokeballTrail
	field_eff_end

gFieldEffectScript_HeartIcon: @ 0x828A1DE
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_HeartIcon
	field_eff_end

gFieldEffectScript_Nop47: @ 0x828A1E8
	field_eff_callnative FldEff_NopA700
	field_eff_end

gFieldEffectScript_Nop48: @ 0x828A1EE
	field_eff_callnative FldEff_NopA6FC
	field_eff_end

gFieldEffectScript_AshPuff: @ 0x828A1F4
	field_eff_loadfadedpal_callnative gSpritePalette_Ash, FldEff_AshPuff
	field_eff_end

gFieldEffectScript_AshLaunch: @ 0x828A1FE
	field_eff_loadfadedpal_callnative gSpritePalette_Ash, FldEff_AshLaunch
	field_eff_end

gFieldEffectScript_SweetScent: @ 0x828A208
	field_eff_callnative FldEff_SweetScent
	field_eff_end

gFieldEffectScript_SandPillar: @ 0x828A20E
	field_eff_loadfadedpal_callnative gSpritePalette_SandPillar, FldEff_SandPillar
	field_eff_end

gFieldEffectScript_Bubbles: @ 0x828A218
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_Bubbles
	field_eff_end

gFieldEffectScript_Sparkle: @ 0x828A222
	field_eff_loadfadedpal_callnative gSpritePalette_SmallSparkle, FldEff_Sparkle
	field_eff_end

gFieldEffectScript_ShowSecretPowerCave: @ 0x828A22C
	field_eff_loadfadedpal_callnative gSpritePalette_SecretPower_Cave, FldEff_SecretPowerCave
	field_eff_end

gFieldEffectScript_ShowSecretPowerTree: @ 0x828A236
	field_eff_loadfadedpal_callnative gSpritePalette_SecretPower_Plant, FldEff_SecretPowerTree
	field_eff_end

gFieldEffectScript_ShowSecretPowerShrub: @ 0x828A240
	field_eff_loadfadedpal_callnative gSpritePalette_SecretPower_Plant, FldEff_SecretPowerShrub
	field_eff_end

gFieldEffectScript_ShowCutGrass: @ 0x828A24A
	field_eff_loadfadedpal_callnative gSpritePalette_CutGrass, FldEff_CutGrass
	field_eff_end

gFieldEffectScript_FieldMoveShowMonInit: @ 0x828A254
	field_eff_callnative FldEff_FieldMoveShowMonInit
	field_eff_end

gFieldEffectScript_UsePuzzleEffect: @ 0x828A25A
	field_eff_callnative FldEff_UsePuzzleEffect
	field_eff_end

gFieldEffectScript_SecretBaseBootPC: @ 0x828A260
	field_eff_callnative FldEff_SecretBasePCTurnOn
	field_eff_end

gFieldEffectScript_HallOfFameRecord: @ 0x828A266
	field_eff_loadfadedpal gSpritePalette_PokeballGlow
	field_eff_loadfadedpal_callnative gSpritePalette_HofMonitor, FldEff_HallOfFameRecord
	field_eff_end

gFieldEffectScript_UseTeleport: @ 0x828A275
	field_eff_callnative FldEff_UseTeleport
	field_eff_end

gFieldEffectScript_RayquazaSpotlight: @ 0x828A27B
	field_eff_callnative FldEff_RayquazaSpotlight
	field_eff_end

gFieldEffectScript_DestroyDeoxysRock: @ 0x828A281
	field_eff_callnative FldEff_DestroyDeoxysRock
	field_eff_end

gFieldEffectScript_MoveDeoxysRock: @ 0x828A287
	field_eff_callnative FldEff_MoveDeoxysRock
	field_eff_end
	.align 2, 0
