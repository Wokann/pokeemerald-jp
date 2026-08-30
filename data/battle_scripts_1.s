
#include "config.h"
#include "constants/global.h"
#include "constants/apprentice.h"
#include "constants/battle.h"
#include "constants/battle_arena.h"
#include "constants/battle_dome.h"
#include "constants/battle_factory.h"
#include "constants/battle_frontier.h"
#include "constants/battle_palace.h"
#include "constants/battle_pike.h"
#include "constants/battle_pyramid.h"
#include "constants/battle_setup.h"
#include "constants/battle_tent.h"
#include "constants/battle_tower.h"
#include "constants/berry.h"
#include "constants/cable_club.h"
#include "constants/coins.h"
#include "constants/comparison_operators.h"
#include "constants/contest.h"
#include "constants/daycare.h"
#include "constants/decorations.h"
#include "constants/easy_chat.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/field_poison.h"
#include "constants/field_specials.h"
#include "constants/field_tasks.h"
#include "constants/field_weather.h"
#include "constants/flags.h"
#include "constants/frontier_util.h"
#include "constants/game_stat.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/heal_locations.h"
#include "constants/layouts.h"
#include "constants/lilycove_lady.h"
#include "constants/map_scripts.h"
#include "constants/maps.h"
#include "constants/mauville_old_man.h"
#include "constants/metatile_labels.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/pokemon.h"
#include "constants/pokemon_size_record.h"
#include "constants/roulette.h"
#include "constants/script_menu.h"
#include "constants/secret_bases.h"
#include "constants/songs.h"
#include "constants/sound.h"
#include "constants/species.h"
#include "constants/trade.h"
#include "constants/trainer_hill.h"
#include "constants/trainers.h"
#include "constants/tv.h"
#include "constants/union_room.h"
#include "constants/vars.h"
#include "constants/weather.h"

	.section script_data, "aw", %progbits
	.include "asm/macros.inc"

#include "constants/tms_hms.inc"

	.include "asm/macros/event.inc"
	.include "constants/gba_constants.inc"
	.include "constants/global.inc"

@ This JP-located owner mirrors pokeemerald data/battle_scripts_1.s.
@ Unconverted ranges remain visible here in physical ROM order.
	.align 2
gBattleScriptsForMoveEffects:: @ 0x8286C30
	.4byte BattleScript_EffectHit                    @ EFFECT_HIT
	.4byte BattleScript_EffectSleep                  @ EFFECT_SLEEP
	.4byte BattleScript_EffectPoisonHit              @ EFFECT_POISON_HIT
	.4byte BattleScript_EffectAbsorb                 @ EFFECT_ABSORB
	.4byte BattleScript_EffectBurnHit                @ EFFECT_BURN_HIT
	.4byte BattleScript_EffectFreezeHit              @ EFFECT_FREEZE_HIT
	.4byte BattleScript_EffectParalyzeHit            @ EFFECT_PARALYZE_HIT
	.4byte BattleScript_EffectExplosion              @ EFFECT_EXPLOSION
	.4byte BattleScript_EffectDreamEater             @ EFFECT_DREAM_EATER
	.4byte BattleScript_EffectMirrorMove             @ EFFECT_MIRROR_MOVE
	.4byte BattleScript_EffectAttackUp               @ EFFECT_ATTACK_UP
	.4byte BattleScript_EffectDefenseUp              @ EFFECT_DEFENSE_UP
	.4byte BattleScript_EffectHit                    @ EFFECT_SPEED_UP
	.4byte BattleScript_EffectSpecialAttackUp        @ EFFECT_SPECIAL_ATTACK_UP
	.4byte BattleScript_EffectHit                    @ EFFECT_SPECIAL_DEFENSE_UP
	.4byte BattleScript_EffectHit                    @ EFFECT_ACCURACY_UP
	.4byte BattleScript_EffectEvasionUp              @ EFFECT_EVASION_UP
	.4byte BattleScript_EffectHit                    @ EFFECT_ALWAYS_HIT
	.4byte BattleScript_EffectAttackDown             @ EFFECT_ATTACK_DOWN
	.4byte BattleScript_EffectDefenseDown            @ EFFECT_DEFENSE_DOWN
	.4byte BattleScript_EffectSpeedDown              @ EFFECT_SPEED_DOWN
	.4byte BattleScript_EffectHit                    @ EFFECT_SPECIAL_ATTACK_DOWN
	.4byte BattleScript_EffectHit                    @ EFFECT_SPECIAL_DEFENSE_DOWN
	.4byte BattleScript_EffectAccuracyDown           @ EFFECT_ACCURACY_DOWN
	.4byte BattleScript_EffectEvasionDown            @ EFFECT_EVASION_DOWN
	.4byte BattleScript_EffectHaze                   @ EFFECT_HAZE
	.4byte BattleScript_EffectBide                   @ EFFECT_BIDE
	.4byte BattleScript_EffectRampage                @ EFFECT_RAMPAGE
	.4byte BattleScript_EffectRoar                   @ EFFECT_ROAR
	.4byte BattleScript_EffectMultiHit               @ EFFECT_MULTI_HIT
	.4byte BattleScript_EffectConversion             @ EFFECT_CONVERSION
	.4byte BattleScript_EffectFlinchHit              @ EFFECT_FLINCH_HIT
	.4byte BattleScript_EffectRestoreHp              @ EFFECT_RESTORE_HP
	.4byte BattleScript_EffectToxic                  @ EFFECT_TOXIC
	.4byte BattleScript_EffectPayDay                 @ EFFECT_PAY_DAY
	.4byte BattleScript_EffectLightScreen            @ EFFECT_LIGHT_SCREEN
	.4byte BattleScript_EffectTriAttack              @ EFFECT_TRI_ATTACK
	.4byte BattleScript_EffectRest                   @ EFFECT_REST
	.4byte BattleScript_EffectOHKO                   @ EFFECT_OHKO
	.4byte BattleScript_EffectRazorWind              @ EFFECT_RAZOR_WIND
	.4byte BattleScript_EffectSuperFang              @ EFFECT_SUPER_FANG
	.4byte BattleScript_EffectDragonRage             @ EFFECT_DRAGON_RAGE
	.4byte BattleScript_EffectTrap                   @ EFFECT_TRAP
	.4byte BattleScript_EffectHit                    @ EFFECT_HIGH_CRITICAL
	.4byte BattleScript_EffectDoubleHit              @ EFFECT_DOUBLE_HIT
	.4byte BattleScript_EffectRecoilIfMiss           @ EFFECT_RECOIL_IF_MISS
	.4byte BattleScript_EffectMist                   @ EFFECT_MIST
	.4byte BattleScript_EffectFocusEnergy            @ EFFECT_FOCUS_ENERGY
	.4byte BattleScript_EffectRecoil                 @ EFFECT_RECOIL
	.4byte BattleScript_EffectConfuse                @ EFFECT_CONFUSE
	.4byte BattleScript_EffectAttackUp2              @ EFFECT_ATTACK_UP_2
	.4byte BattleScript_EffectDefenseUp2             @ EFFECT_DEFENSE_UP_2
	.4byte BattleScript_EffectSpeedUp2               @ EFFECT_SPEED_UP_2
	.4byte BattleScript_EffectSpecialAttackUp2       @ EFFECT_SPECIAL_ATTACK_UP_2
	.4byte BattleScript_EffectSpecialDefenseUp2      @ EFFECT_SPECIAL_DEFENSE_UP_2
	.4byte BattleScript_EffectHit                    @ EFFECT_ACCURACY_UP_2
	.4byte BattleScript_EffectHit                    @ EFFECT_EVASION_UP_2
	.4byte BattleScript_EffectTransform              @ EFFECT_TRANSFORM
	.4byte BattleScript_EffectAttackDown2            @ EFFECT_ATTACK_DOWN_2
	.4byte BattleScript_EffectDefenseDown2           @ EFFECT_DEFENSE_DOWN_2
	.4byte BattleScript_EffectSpeedDown2             @ EFFECT_SPEED_DOWN_2
	.4byte BattleScript_EffectHit                    @ EFFECT_SPECIAL_ATTACK_DOWN_2
	.4byte BattleScript_EffectSpecialDefenseDown2    @ EFFECT_SPECIAL_DEFENSE_DOWN_2
	.4byte BattleScript_EffectHit                    @ EFFECT_ACCURACY_DOWN_2
	.4byte BattleScript_EffectHit                    @ EFFECT_EVASION_DOWN_2
	.4byte BattleScript_EffectReflect                @ EFFECT_REFLECT
	.4byte BattleScript_EffectPoison                 @ EFFECT_POISON
	.4byte BattleScript_EffectParalyze               @ EFFECT_PARALYZE
	.4byte BattleScript_EffectAttackDownHit          @ EFFECT_ATTACK_DOWN_HIT
	.4byte BattleScript_EffectDefenseDownHit         @ EFFECT_DEFENSE_DOWN_HIT
	.4byte BattleScript_EffectSpeedDownHit           @ EFFECT_SPEED_DOWN_HIT
	.4byte BattleScript_EffectSpecialAttackDownHit   @ EFFECT_SPECIAL_ATTACK_DOWN_HIT
	.4byte BattleScript_EffectSpecialDefenseDownHit  @ EFFECT_SPECIAL_DEFENSE_DOWN_HIT
	.4byte BattleScript_EffectAccuracyDownHit        @ EFFECT_ACCURACY_DOWN_HIT
	.4byte BattleScript_EffectHit                    @ EFFECT_EVASION_DOWN_HIT
	.4byte BattleScript_EffectSkyAttack              @ EFFECT_SKY_ATTACK
	.4byte BattleScript_EffectConfuseHit             @ EFFECT_CONFUSE_HIT
	.4byte BattleScript_EffectTwineedle              @ EFFECT_TWINEEDLE
	.4byte BattleScript_EffectHit                    @ EFFECT_VITAL_THROW
	.4byte BattleScript_EffectSubstitute             @ EFFECT_SUBSTITUTE
	.4byte BattleScript_EffectRecharge               @ EFFECT_RECHARGE
	.4byte BattleScript_EffectRage                   @ EFFECT_RAGE
	.4byte BattleScript_EffectMimic                  @ EFFECT_MIMIC
	.4byte BattleScript_EffectMetronome              @ EFFECT_METRONOME
	.4byte BattleScript_EffectLeechSeed              @ EFFECT_LEECH_SEED
	.4byte BattleScript_EffectSplash                 @ EFFECT_SPLASH
	.4byte BattleScript_EffectDisable                @ EFFECT_DISABLE
	.4byte BattleScript_EffectLevelDamage            @ EFFECT_LEVEL_DAMAGE
	.4byte BattleScript_EffectPsywave                @ EFFECT_PSYWAVE
	.4byte BattleScript_EffectCounter                @ EFFECT_COUNTER
	.4byte BattleScript_EffectEncore                 @ EFFECT_ENCORE
	.4byte BattleScript_EffectPainSplit              @ EFFECT_PAIN_SPLIT
	.4byte BattleScript_EffectSnore                  @ EFFECT_SNORE
	.4byte BattleScript_EffectConversion2            @ EFFECT_CONVERSION_2
	.4byte BattleScript_EffectLockOn                 @ EFFECT_LOCK_ON
	.4byte BattleScript_EffectSketch                 @ EFFECT_SKETCH
	.4byte BattleScript_EffectHit                    @ EFFECT_UNUSED_60
	.4byte BattleScript_EffectSleepTalk              @ EFFECT_SLEEP_TALK
	.4byte BattleScript_EffectDestinyBond            @ EFFECT_DESTINY_BOND
	.4byte BattleScript_EffectFlail                  @ EFFECT_FLAIL
	.4byte BattleScript_EffectSpite                  @ EFFECT_SPITE
	.4byte BattleScript_EffectHit                    @ EFFECT_FALSE_SWIPE
	.4byte BattleScript_EffectHealBell               @ EFFECT_HEAL_BELL
	.4byte BattleScript_EffectHit                    @ EFFECT_QUICK_ATTACK
	.4byte BattleScript_EffectTripleKick             @ EFFECT_TRIPLE_KICK
	.4byte BattleScript_EffectThief                  @ EFFECT_THIEF
	.4byte BattleScript_EffectMeanLook               @ EFFECT_MEAN_LOOK
	.4byte BattleScript_EffectNightmare              @ EFFECT_NIGHTMARE
	.4byte BattleScript_EffectMinimize               @ EFFECT_MINIMIZE
	.4byte BattleScript_EffectCurse                  @ EFFECT_CURSE
	.4byte BattleScript_EffectHit                    @ EFFECT_UNUSED_6E
	.4byte BattleScript_EffectProtect                @ EFFECT_PROTECT
	.4byte BattleScript_EffectSpikes                 @ EFFECT_SPIKES
	.4byte BattleScript_EffectForesight              @ EFFECT_FORESIGHT
	.4byte BattleScript_EffectPerishSong             @ EFFECT_PERISH_SONG
	.4byte BattleScript_EffectSandstorm              @ EFFECT_SANDSTORM
	.4byte BattleScript_EffectEndure                 @ EFFECT_ENDURE
	.4byte BattleScript_EffectRollout                @ EFFECT_ROLLOUT
	.4byte BattleScript_EffectSwagger                @ EFFECT_SWAGGER
	.4byte BattleScript_EffectFuryCutter             @ EFFECT_FURY_CUTTER
	.4byte BattleScript_EffectAttract                @ EFFECT_ATTRACT
	.4byte BattleScript_EffectReturn                 @ EFFECT_RETURN
	.4byte BattleScript_EffectPresent                @ EFFECT_PRESENT
	.4byte BattleScript_EffectFrustration            @ EFFECT_FRUSTRATION
	.4byte BattleScript_EffectSafeguard              @ EFFECT_SAFEGUARD
	.4byte BattleScript_EffectThawHit                @ EFFECT_THAW_HIT
	.4byte BattleScript_EffectMagnitude              @ EFFECT_MAGNITUDE
	.4byte BattleScript_EffectBatonPass              @ EFFECT_BATON_PASS
	.4byte BattleScript_EffectHit                    @ EFFECT_PURSUIT
	.4byte BattleScript_EffectRapidSpin              @ EFFECT_RAPID_SPIN
	.4byte BattleScript_EffectSonicboom              @ EFFECT_SONICBOOM
	.4byte BattleScript_EffectHit                    @ EFFECT_UNUSED_83
	.4byte BattleScript_EffectMorningSun             @ EFFECT_MORNING_SUN
	.4byte BattleScript_EffectSynthesis              @ EFFECT_SYNTHESIS
	.4byte BattleScript_EffectMoonlight              @ EFFECT_MOONLIGHT
	.4byte BattleScript_EffectHiddenPower            @ EFFECT_HIDDEN_POWER
	.4byte BattleScript_EffectRainDance              @ EFFECT_RAIN_DANCE
	.4byte BattleScript_EffectSunnyDay               @ EFFECT_SUNNY_DAY
	.4byte BattleScript_EffectDefenseUpHit           @ EFFECT_DEFENSE_UP_HIT
	.4byte BattleScript_EffectAttackUpHit            @ EFFECT_ATTACK_UP_HIT
	.4byte BattleScript_EffectAllStatsUpHit          @ EFFECT_ALL_STATS_UP_HIT
	.4byte BattleScript_EffectHit                    @ EFFECT_UNUSED_8D
	.4byte BattleScript_EffectBellyDrum              @ EFFECT_BELLY_DRUM
	.4byte BattleScript_EffectPsychUp                @ EFFECT_PSYCH_UP
	.4byte BattleScript_EffectMirrorCoat             @ EFFECT_MIRROR_COAT
	.4byte BattleScript_EffectSkullBash              @ EFFECT_SKULL_BASH
	.4byte BattleScript_EffectTwister                @ EFFECT_TWISTER
	.4byte BattleScript_EffectEarthquake             @ EFFECT_EARTHQUAKE
	.4byte BattleScript_EffectFutureSight            @ EFFECT_FUTURE_SIGHT
	.4byte BattleScript_EffectGust                   @ EFFECT_GUST
	.4byte BattleScript_EffectStomp                  @ EFFECT_FLINCH_MINIMIZE_HIT
	.4byte BattleScript_EffectSolarBeam              @ EFFECT_SOLAR_BEAM
	.4byte BattleScript_EffectThunder                @ EFFECT_THUNDER
	.4byte BattleScript_EffectTeleport               @ EFFECT_TELEPORT
	.4byte BattleScript_EffectBeatUp                 @ EFFECT_BEAT_UP
	.4byte BattleScript_EffectSemiInvulnerable       @ EFFECT_SEMI_INVULNERABLE
	.4byte BattleScript_EffectDefenseCurl            @ EFFECT_DEFENSE_CURL
	.4byte BattleScript_EffectSoftboiled             @ EFFECT_SOFTBOILED
	.4byte BattleScript_EffectFakeOut                @ EFFECT_FAKE_OUT
	.4byte BattleScript_EffectUproar                 @ EFFECT_UPROAR
	.4byte BattleScript_EffectStockpile              @ EFFECT_STOCKPILE
	.4byte BattleScript_EffectSpitUp                 @ EFFECT_SPIT_UP
	.4byte BattleScript_EffectSwallow                @ EFFECT_SWALLOW
	.4byte BattleScript_EffectHit                    @ EFFECT_UNUSED_A3
	.4byte BattleScript_EffectHail                   @ EFFECT_HAIL
	.4byte BattleScript_EffectTorment                @ EFFECT_TORMENT
	.4byte BattleScript_EffectFlatter                @ EFFECT_FLATTER
	.4byte BattleScript_EffectWillOWisp              @ EFFECT_WILL_O_WISP
	.4byte BattleScript_EffectMemento                @ EFFECT_MEMENTO
	.4byte BattleScript_EffectFacade                 @ EFFECT_FACADE
	.4byte BattleScript_EffectFocusPunch             @ EFFECT_FOCUS_PUNCH
	.4byte BattleScript_EffectSmellingsalt           @ EFFECT_SMELLINGSALT
	.4byte BattleScript_EffectFollowMe               @ EFFECT_FOLLOW_ME
	.4byte BattleScript_EffectNaturePower            @ EFFECT_NATURE_POWER
	.4byte BattleScript_EffectCharge                 @ EFFECT_CHARGE
	.4byte BattleScript_EffectTaunt                  @ EFFECT_TAUNT
	.4byte BattleScript_EffectHelpingHand            @ EFFECT_HELPING_HAND
	.4byte BattleScript_EffectTrick                  @ EFFECT_TRICK
	.4byte BattleScript_EffectRolePlay               @ EFFECT_ROLE_PLAY
	.4byte BattleScript_EffectWish                   @ EFFECT_WISH
	.4byte BattleScript_EffectAssist                 @ EFFECT_ASSIST
	.4byte BattleScript_EffectIngrain                @ EFFECT_INGRAIN
	.4byte BattleScript_EffectSuperpower             @ EFFECT_SUPERPOWER
	.4byte BattleScript_EffectMagicCoat              @ EFFECT_MAGIC_COAT
	.4byte BattleScript_EffectRecycle                @ EFFECT_RECYCLE
	.4byte BattleScript_EffectRevenge                @ EFFECT_REVENGE
	.4byte BattleScript_EffectBrickBreak             @ EFFECT_BRICK_BREAK
	.4byte BattleScript_EffectYawn                   @ EFFECT_YAWN
	.4byte BattleScript_EffectKnockOff               @ EFFECT_KNOCK_OFF
	.4byte BattleScript_EffectEndeavor               @ EFFECT_ENDEAVOR
	.4byte BattleScript_EffectEruption               @ EFFECT_ERUPTION
	.4byte BattleScript_EffectSkillSwap              @ EFFECT_SKILL_SWAP
	.4byte BattleScript_EffectImprison               @ EFFECT_IMPRISON
	.4byte BattleScript_EffectRefresh                @ EFFECT_REFRESH
	.4byte BattleScript_EffectGrudge                 @ EFFECT_GRUDGE
	.4byte BattleScript_EffectSnatch                 @ EFFECT_SNATCH
	.4byte BattleScript_EffectLowKick                @ EFFECT_LOW_KICK
	.4byte BattleScript_EffectSecretPower            @ EFFECT_SECRET_POWER
	.4byte BattleScript_EffectDoubleEdge             @ EFFECT_DOUBLE_EDGE
	.4byte BattleScript_EffectTeeterDance            @ EFFECT_TEETER_DANCE
	.4byte BattleScript_EffectBurnHit                @ EFFECT_BLAZE_KICK
	.4byte BattleScript_EffectMudSport               @ EFFECT_MUD_SPORT
	.4byte BattleScript_EffectPoisonFang             @ EFFECT_POISON_FANG
	.4byte BattleScript_EffectWeatherBall            @ EFFECT_WEATHER_BALL
	.4byte BattleScript_EffectOverheat               @ EFFECT_OVERHEAT
	.4byte BattleScript_EffectTickle                 @ EFFECT_TICKLE
	.4byte BattleScript_EffectCosmicPower            @ EFFECT_COSMIC_POWER
	.4byte BattleScript_EffectSkyUppercut            @ EFFECT_SKY_UPPERCUT
	.4byte BattleScript_EffectBulkUp                 @ EFFECT_BULK_UP
	.4byte BattleScript_EffectPoisonHit              @ EFFECT_POISON_TAIL
	.4byte BattleScript_EffectWaterSport             @ EFFECT_WATER_SPORT
	.4byte BattleScript_EffectCalmMind               @ EFFECT_CALM_MIND
	.4byte BattleScript_EffectDragonDance            @ EFFECT_DRAGON_DANCE
	.4byte BattleScript_EffectCamouflage             @ EFFECT_CAMOUFLAGE

@ The 214 JP dispatcher entries below use their real effect labels.
@ Each effect body remains a byte-exact raw span until its battle-script
@ macro conversion is independently verified.
BattleScript_EffectHit:: @ 0x08286F88
	.incbin "baserom_jp.gba", 0x286f88, 0x30

BattleScript_HitFromCritCalc:: @ 0x08286FB8
	.incbin "baserom_jp.gba", 0x286fb8, 0x1e

BattleScript_MoveEnd:: @ 0x08286FD6
	.incbin "baserom_jp.gba", 0x286fd6, 0x12

BattleScript_MoveMissedPause:: @ 0x08286FE8
	.incbin "baserom_jp.gba", 0x286fe8, 0xd

BattleScript_EffectSleep:: @ 0x08286FF5
	.incbin "baserom_jp.gba", 0x286ff5, 0x72

BattleScript_EffectPoisonHit:: @ 0x08287067
	.incbin "baserom_jp.gba", 0x287067, 0xb

BattleScript_EffectAbsorb:: @ 0x08287072
	.incbin "baserom_jp.gba", 0x287072, 0x6e

BattleScript_EffectBurnHit:: @ 0x082870E0
	.incbin "baserom_jp.gba", 0x2870e0, 0xb

BattleScript_EffectFreezeHit:: @ 0x082870EB
	.incbin "baserom_jp.gba", 0x2870eb, 0xb

BattleScript_EffectParalyzeHit:: @ 0x082870F6
	.incbin "baserom_jp.gba", 0x2870f6, 0xb

BattleScript_EffectExplosion:: @ 0x08287101
	.incbin "baserom_jp.gba", 0x287101, 0x80

BattleScript_EffectDreamEater:: @ 0x08287181
	.incbin "baserom_jp.gba", 0x287181, 0x69

BattleScript_EffectMirrorMove:: @ 0x082871EA
	.incbin "baserom_jp.gba", 0x2871ea, 0x18

BattleScript_EffectAttackUp:: @ 0x08287202
	.incbin "baserom_jp.gba", 0x287202, 0xb

BattleScript_EffectDefenseUp:: @ 0x0828720D
	.incbin "baserom_jp.gba", 0x28720d, 0xb

BattleScript_EffectSpecialAttackUp:: @ 0x08287218
	.incbin "baserom_jp.gba", 0x287218, 0xb

BattleScript_EffectEvasionUp:: @ 0x08287223
	.incbin "baserom_jp.gba", 0x287223, 0x39

BattleScript_StatUp:: @ 0x0828725C
	.incbin "baserom_jp.gba", 0x28725c, 0x10

BattleScript_EffectAttackDown:: @ 0x0828726C
	.incbin "baserom_jp.gba", 0x28726c, 0xb

BattleScript_EffectDefenseDown:: @ 0x08287277
	.incbin "baserom_jp.gba", 0x287277, 0xb

BattleScript_EffectSpeedDown:: @ 0x08287282
	.incbin "baserom_jp.gba", 0x287282, 0xb

BattleScript_EffectAccuracyDown:: @ 0x0828728D
	.incbin "baserom_jp.gba", 0x28728d, 0xb

BattleScript_EffectEvasionDown:: @ 0x08287298
	.incbin "baserom_jp.gba", 0x287298, 0x55

BattleScript_StatDown:: @ 0x082872ED
	.incbin "baserom_jp.gba", 0x2872ed, 0x10

BattleScript_EffectHaze:: @ 0x082872FD
	.incbin "baserom_jp.gba", 0x2872fd, 0x11

BattleScript_EffectBide:: @ 0x0828730E
	.incbin "baserom_jp.gba", 0x28730e, 0x14

BattleScript_EffectRampage:: @ 0x08287322
	.incbin "baserom_jp.gba", 0x287322, 0x1a

BattleScript_EffectRoar:: @ 0x0828733C
	.incbin "baserom_jp.gba", 0x28733c, 0x36

BattleScript_EffectMultiHit:: @ 0x08287372
	.incbin "baserom_jp.gba", 0x287372, 0xc4

BattleScript_EffectConversion:: @ 0x08287436
	.incbin "baserom_jp.gba", 0x287436, 0x15

BattleScript_EffectFlinchHit:: @ 0x0828744B
	.incbin "baserom_jp.gba", 0x28744b, 0xb

BattleScript_EffectRestoreHp:: @ 0x08287456
	.incbin "baserom_jp.gba", 0x287456, 0x23

BattleScript_EffectToxic:: @ 0x08287479
	.incbin "baserom_jp.gba", 0x287479, 0x8c

BattleScript_EffectPayDay:: @ 0x08287505
	.incbin "baserom_jp.gba", 0x287505, 0xb

BattleScript_EffectLightScreen:: @ 0x08287510
	.incbin "baserom_jp.gba", 0x287510, 0x9

BattleScript_EffectTriAttack:: @ 0x08287519
	.incbin "baserom_jp.gba", 0x287519, 0xb

BattleScript_EffectRest:: @ 0x08287524
	.incbin "baserom_jp.gba", 0x287524, 0x4b

BattleScript_EffectOHKO:: @ 0x0828756F
	.incbin "baserom_jp.gba", 0x28756f, 0x31

BattleScript_EffectRazorWind:: @ 0x082875A0
	.incbin "baserom_jp.gba", 0x2875a0, 0x81

BattleScript_EffectSuperFang:: @ 0x08287621
	.incbin "baserom_jp.gba", 0x287621, 0x17

BattleScript_EffectDragonRage:: @ 0x08287638
	.incbin "baserom_jp.gba", 0x287638, 0x2f

BattleScript_EffectTrap:: @ 0x08287667
	.incbin "baserom_jp.gba", 0x287667, 0x31

BattleScript_EffectDoubleHit:: @ 0x08287698
	.incbin "baserom_jp.gba", 0x287698, 0x18

BattleScript_EffectRecoilIfMiss:: @ 0x082876B0
	.incbin "baserom_jp.gba", 0x2876b0, 0x51

BattleScript_EffectMist:: @ 0x08287701
	.incbin "baserom_jp.gba", 0x287701, 0x13

BattleScript_EffectFocusEnergy:: @ 0x08287714
	.incbin "baserom_jp.gba", 0x287714, 0x1d

BattleScript_EffectRecoil:: @ 0x08287731
	.incbin "baserom_jp.gba", 0x287731, 0x19

BattleScript_EffectConfuse:: @ 0x0828774A
	.incbin "baserom_jp.gba", 0x28774a, 0x50

BattleScript_EffectAttackUp2:: @ 0x0828779A
	.incbin "baserom_jp.gba", 0x28779a, 0xb

BattleScript_EffectDefenseUp2:: @ 0x082877A5
	.incbin "baserom_jp.gba", 0x2877a5, 0xb

BattleScript_EffectSpeedUp2:: @ 0x082877B0
	.incbin "baserom_jp.gba", 0x2877b0, 0xb

BattleScript_EffectSpecialAttackUp2:: @ 0x082877BB
	.incbin "baserom_jp.gba", 0x2877bb, 0xb

BattleScript_EffectSpecialDefenseUp2:: @ 0x082877C6
	.incbin "baserom_jp.gba", 0x2877c6, 0xb

BattleScript_EffectTransform:: @ 0x082877D1
	.incbin "baserom_jp.gba", 0x2877d1, 0x13

BattleScript_EffectAttackDown2:: @ 0x082877E4
	.incbin "baserom_jp.gba", 0x2877e4, 0xb

BattleScript_EffectDefenseDown2:: @ 0x082877EF
	.incbin "baserom_jp.gba", 0x2877ef, 0xb

BattleScript_EffectSpeedDown2:: @ 0x082877FA
	.incbin "baserom_jp.gba", 0x2877fa, 0xb

BattleScript_EffectSpecialDefenseDown2:: @ 0x08287805
	.incbin "baserom_jp.gba", 0x287805, 0xb

BattleScript_EffectReflect:: @ 0x08287810
	.incbin "baserom_jp.gba", 0x287810, 0x13

BattleScript_EffectPoison:: @ 0x08287823
	.incbin "baserom_jp.gba", 0x287823, 0x61

BattleScript_EffectParalyze:: @ 0x08287884
	.incbin "baserom_jp.gba", 0x287884, 0x80

BattleScript_EffectAttackDownHit:: @ 0x08287904
	.incbin "baserom_jp.gba", 0x287904, 0xb

BattleScript_EffectDefenseDownHit:: @ 0x0828790F
	.incbin "baserom_jp.gba", 0x28790f, 0xb

BattleScript_EffectSpeedDownHit:: @ 0x0828791A
	.incbin "baserom_jp.gba", 0x28791a, 0xb

BattleScript_EffectSpecialAttackDownHit:: @ 0x08287925
	.incbin "baserom_jp.gba", 0x287925, 0xb

BattleScript_EffectSpecialDefenseDownHit:: @ 0x08287930
	.incbin "baserom_jp.gba", 0x287930, 0xb

BattleScript_EffectAccuracyDownHit:: @ 0x0828793B
	.incbin "baserom_jp.gba", 0x28793b, 0xb

BattleScript_EffectSkyAttack:: @ 0x08287946
	.incbin "baserom_jp.gba", 0x287946, 0x28

BattleScript_EffectConfuseHit:: @ 0x0828796E
	.incbin "baserom_jp.gba", 0x28796e, 0xb

BattleScript_EffectTwineedle:: @ 0x08287979
	.incbin "baserom_jp.gba", 0x287979, 0x18

BattleScript_EffectSubstitute:: @ 0x08287991
	.incbin "baserom_jp.gba", 0x287991, 0x46

BattleScript_EffectRecharge:: @ 0x082879D7
	.incbin "baserom_jp.gba", 0x2879d7, 0x13

BattleScript_MoveUsedMustRecharge:: @ 0x082879EA
	.incbin "baserom_jp.gba", 0x2879ea, 0xb

BattleScript_EffectRage:: @ 0x082879F5
	.incbin "baserom_jp.gba", 0x2879f5, 0x27

BattleScript_EffectMimic:: @ 0x08287A1C
	.incbin "baserom_jp.gba", 0x287a1c, 0x26

BattleScript_EffectMetronome:: @ 0x08287A42
	.incbin "baserom_jp.gba", 0x287a42, 0x14

BattleScript_EffectLeechSeed:: @ 0x08287A56
	.incbin "baserom_jp.gba", 0x287a56, 0x27

BattleScript_EffectSplash:: @ 0x08287A7D
	.incbin "baserom_jp.gba", 0x287a7d, 0x12

BattleScript_EffectDisable:: @ 0x08287A8F
	.incbin "baserom_jp.gba", 0x287a8f, 0x1c

BattleScript_EffectLevelDamage:: @ 0x08287AAB
	.incbin "baserom_jp.gba", 0x287aab, 0x18

BattleScript_EffectPsywave:: @ 0x08287AC3
	.incbin "baserom_jp.gba", 0x287ac3, 0x18

BattleScript_EffectCounter:: @ 0x08287ADB
	.incbin "baserom_jp.gba", 0x287adb, 0x16

BattleScript_EffectEncore:: @ 0x08287AF1
	.incbin "baserom_jp.gba", 0x287af1, 0x1c

BattleScript_EffectPainSplit:: @ 0x08287B0D
	.incbin "baserom_jp.gba", 0x287b0d, 0x37

BattleScript_EffectSnore:: @ 0x08287B44
	.incbin "baserom_jp.gba", 0x287b44, 0x3a

BattleScript_EffectConversion2:: @ 0x08287B7E
	.incbin "baserom_jp.gba", 0x287b7e, 0x15

BattleScript_EffectLockOn:: @ 0x08287B93
	.incbin "baserom_jp.gba", 0x287b93, 0x22

BattleScript_EffectSketch:: @ 0x08287BB5
	.incbin "baserom_jp.gba", 0x287bb5, 0x1f

BattleScript_EffectSleepTalk:: @ 0x08287BD4
	.incbin "baserom_jp.gba", 0x287bd4, 0x42

BattleScript_EffectDestinyBond:: @ 0x08287C16
	.incbin "baserom_jp.gba", 0x287c16, 0x11

BattleScript_EffectFlail:: @ 0x08287C27
	.incbin "baserom_jp.gba", 0x287c27, 0x6

BattleScript_EffectSpite:: @ 0x08287C2D
	.incbin "baserom_jp.gba", 0x287c2d, 0x1c

BattleScript_EffectHealBell:: @ 0x08287C49
	.incbin "baserom_jp.gba", 0x287c49, 0x45

BattleScript_EffectTripleKick:: @ 0x08287C8E
	.incbin "baserom_jp.gba", 0x287c8e, 0xe3

BattleScript_EffectThief:: @ 0x08287D71
	.incbin "baserom_jp.gba", 0x287d71, 0xb

BattleScript_EffectMeanLook:: @ 0x08287D7C
	.incbin "baserom_jp.gba", 0x287d7c, 0x32

BattleScript_EffectNightmare:: @ 0x08287DAE
	.incbin "baserom_jp.gba", 0x287dae, 0x3a

BattleScript_EffectMinimize:: @ 0x08287DE8
	.incbin "baserom_jp.gba", 0x287de8, 0xd

BattleScript_EffectCurse:: @ 0x08287DF5
	.incbin "baserom_jp.gba", 0x287df5, 0xc9

BattleScript_EffectProtect:: @ 0x08287EBE
BattleScript_EffectEndure:: @ 0x08287EBE
	.incbin "baserom_jp.gba", 0x287ebe, 0x13

BattleScript_EffectSpikes:: @ 0x08287ED1
	.incbin "baserom_jp.gba", 0x287ed1, 0x15

BattleScript_EffectForesight:: @ 0x08287EE6
	.incbin "baserom_jp.gba", 0x287ee6, 0x18

BattleScript_EffectPerishSong:: @ 0x08287EFE
	.incbin "baserom_jp.gba", 0x287efe, 0x41

BattleScript_EffectSandstorm:: @ 0x08287F3F
	.incbin "baserom_jp.gba", 0x287f3f, 0x9

BattleScript_EffectRollout:: @ 0x08287F48
	.incbin "baserom_jp.gba", 0x287f48, 0x1b

BattleScript_EffectSwagger:: @ 0x08287F63
	.incbin "baserom_jp.gba", 0x287f63, 0x5e

BattleScript_EffectFuryCutter:: @ 0x08287FC1
	.incbin "baserom_jp.gba", 0x287fc1, 0x1f

BattleScript_EffectAttract:: @ 0x08287FE0
	.incbin "baserom_jp.gba", 0x287fe0, 0x1c

BattleScript_EffectReturn:: @ 0x08287FFC
BattleScript_EffectFrustration:: @ 0x08287FFC
	.incbin "baserom_jp.gba", 0x287ffc, 0xe

BattleScript_EffectPresent:: @ 0x0828800A
	.incbin "baserom_jp.gba", 0x28800a, 0xc

BattleScript_EffectSafeguard:: @ 0x08288016
	.incbin "baserom_jp.gba", 0x288016, 0x9

BattleScript_EffectThawHit:: @ 0x0828801F
	.incbin "baserom_jp.gba", 0x28801f, 0xb

BattleScript_EffectMagnitude:: @ 0x0828802A
	.incbin "baserom_jp.gba", 0x28802a, 0x13

BattleScript_EffectBatonPass:: @ 0x0828803D
	.incbin "baserom_jp.gba", 0x28803d, 0x3b

BattleScript_EffectRapidSpin:: @ 0x08288078
	.incbin "baserom_jp.gba", 0x288078, 0xb

BattleScript_EffectSonicboom:: @ 0x08288083
	.incbin "baserom_jp.gba", 0x288083, 0x2f

BattleScript_EffectMorningSun:: @ 0x082880B2
BattleScript_EffectSynthesis:: @ 0x082880B2
BattleScript_EffectMoonlight:: @ 0x082880B2
	.incbin "baserom_jp.gba", 0x2880b2, 0xd

BattleScript_EffectHiddenPower:: @ 0x082880BF
	.incbin "baserom_jp.gba", 0x2880bf, 0x6

BattleScript_EffectRainDance:: @ 0x082880C5
	.incbin "baserom_jp.gba", 0x2880c5, 0x18

BattleScript_EffectSunnyDay:: @ 0x082880DD
	.incbin "baserom_jp.gba", 0x2880dd, 0x9

BattleScript_EffectDefenseUpHit:: @ 0x082880E6
	.incbin "baserom_jp.gba", 0x2880e6, 0xb

BattleScript_EffectAttackUpHit:: @ 0x082880F1
	.incbin "baserom_jp.gba", 0x2880f1, 0xb

BattleScript_EffectAllStatsUpHit:: @ 0x082880FC
	.incbin "baserom_jp.gba", 0x2880fc, 0xb

BattleScript_EffectBellyDrum:: @ 0x08288107
	.incbin "baserom_jp.gba", 0x288107, 0x22

BattleScript_EffectPsychUp:: @ 0x08288129
	.incbin "baserom_jp.gba", 0x288129, 0x15

BattleScript_EffectMirrorCoat:: @ 0x0828813E
	.incbin "baserom_jp.gba", 0x28813e, 0x16

BattleScript_EffectSkullBash:: @ 0x08288154
	.incbin "baserom_jp.gba", 0x288154, 0x4f

BattleScript_EffectTwister:: @ 0x082881A3
	.incbin "baserom_jp.gba", 0x2881a3, 0x25

BattleScript_EffectEarthquake:: @ 0x082881C8
	.incbin "baserom_jp.gba", 0x2881c8, 0x84

BattleScript_EffectFutureSight:: @ 0x0828824C
	.incbin "baserom_jp.gba", 0x28824c, 0x17

BattleScript_EffectGust:: @ 0x08288263
	.incbin "baserom_jp.gba", 0x288263, 0x1f

BattleScript_EffectStomp:: @ 0x08288282
	.incbin "baserom_jp.gba", 0x288282, 0x16

BattleScript_EffectSolarBeam:: @ 0x08288298
	.incbin "baserom_jp.gba", 0x288298, 0x56

BattleScript_EffectThunder:: @ 0x082882EE
	.incbin "baserom_jp.gba", 0x2882ee, 0x14

BattleScript_EffectTeleport:: @ 0x08288302
	.incbin "baserom_jp.gba", 0x288302, 0x3a

BattleScript_EffectBeatUp:: @ 0x0828833C
	.incbin "baserom_jp.gba", 0x28833c, 0x57

BattleScript_EffectSemiInvulnerable:: @ 0x08288393
	.incbin "baserom_jp.gba", 0x288393, 0xab

BattleScript_EffectDefenseCurl:: @ 0x0828843E
	.incbin "baserom_jp.gba", 0x28843e, 0x22

BattleScript_EffectSoftboiled:: @ 0x08288460
	.incbin "baserom_jp.gba", 0x288460, 0x9

BattleScript_PresentHealTarget:: @ 0x08288469
	.incbin "baserom_jp.gba", 0x288469, 0x1a

BattleScript_AlreadyAtFullHp:: @ 0x08288483
	.incbin "baserom_jp.gba", 0x288483, 0xe

BattleScript_EffectFakeOut:: @ 0x08288491
	.incbin "baserom_jp.gba", 0x288491, 0x13

BattleScript_ButItFailed:: @ 0x082884A4
	.incbin "baserom_jp.gba", 0x2884a4, 0x24

BattleScript_EffectUproar:: @ 0x082884C8
	.incbin "baserom_jp.gba", 0x2884c8, 0x20

BattleScript_EffectStockpile:: @ 0x082884E8
	.incbin "baserom_jp.gba", 0x2884e8, 0x13

BattleScript_EffectSpitUp:: @ 0x082884FB
	.incbin "baserom_jp.gba", 0x2884fb, 0x42

BattleScript_EffectSwallow:: @ 0x0828853D
	.incbin "baserom_jp.gba", 0x28853d, 0x1d

BattleScript_EffectHail:: @ 0x0828855A
	.incbin "baserom_jp.gba", 0x28855a, 0x9

BattleScript_EffectTorment:: @ 0x08288563
	.incbin "baserom_jp.gba", 0x288563, 0x1c

BattleScript_EffectFlatter:: @ 0x0828857F
	.incbin "baserom_jp.gba", 0x28857f, 0x5e

BattleScript_EffectWillOWisp:: @ 0x082885DD
	.incbin "baserom_jp.gba", 0x2885dd, 0x77

BattleScript_EffectMemento:: @ 0x08288654
	.incbin "baserom_jp.gba", 0x288654, 0xa3

BattleScript_EffectFacade:: @ 0x082886F7
	.incbin "baserom_jp.gba", 0x2886f7, 0x1a

BattleScript_EffectFocusPunch:: @ 0x08288711
	.incbin "baserom_jp.gba", 0x288711, 0x12

BattleScript_EffectSmellingsalt:: @ 0x08288723
	.incbin "baserom_jp.gba", 0x288723, 0x2a

BattleScript_EffectFollowMe:: @ 0x0828874D
	.incbin "baserom_jp.gba", 0x28874d, 0x11

BattleScript_EffectNaturePower:: @ 0x0828875E
	.incbin "baserom_jp.gba", 0x28875e, 0xd

BattleScript_EffectCharge:: @ 0x0828876B
	.incbin "baserom_jp.gba", 0x28876b, 0x11

BattleScript_EffectTaunt:: @ 0x0828877C
	.incbin "baserom_jp.gba", 0x28877c, 0x1c

BattleScript_EffectHelpingHand:: @ 0x08288798
	.incbin "baserom_jp.gba", 0x288798, 0x15

BattleScript_EffectTrick:: @ 0x082887AD
	.incbin "baserom_jp.gba", 0x2887ad, 0x2e

BattleScript_EffectRolePlay:: @ 0x082887DB
	.incbin "baserom_jp.gba", 0x2887db, 0x1c

BattleScript_EffectWish:: @ 0x082887F7
	.incbin "baserom_jp.gba", 0x2887f7, 0x10

BattleScript_EffectAssist:: @ 0x08288807
	.incbin "baserom_jp.gba", 0x288807, 0x17

BattleScript_EffectIngrain:: @ 0x0828881E
	.incbin "baserom_jp.gba", 0x28881e, 0x15

BattleScript_EffectSuperpower:: @ 0x08288833
	.incbin "baserom_jp.gba", 0x288833, 0xb

BattleScript_EffectMagicCoat:: @ 0x0828883E
	.incbin "baserom_jp.gba", 0x28883e, 0x15

BattleScript_EffectRecycle:: @ 0x08288853
	.incbin "baserom_jp.gba", 0x288853, 0x15

BattleScript_EffectRevenge:: @ 0x08288868
	.incbin "baserom_jp.gba", 0x288868, 0x6

BattleScript_EffectBrickBreak:: @ 0x0828886E
	.incbin "baserom_jp.gba", 0x28886e, 0x51

BattleScript_EffectYawn:: @ 0x082888BF
	.incbin "baserom_jp.gba", 0x2888bf, 0x59

BattleScript_EffectKnockOff:: @ 0x08288918
	.incbin "baserom_jp.gba", 0x288918, 0xb

BattleScript_EffectEndeavor:: @ 0x08288923
	.incbin "baserom_jp.gba", 0x288923, 0x3b

BattleScript_EffectEruption:: @ 0x0828895E
	.incbin "baserom_jp.gba", 0x28895e, 0x6

BattleScript_EffectSkillSwap:: @ 0x08288964
	.incbin "baserom_jp.gba", 0x288964, 0x1c

BattleScript_EffectImprison:: @ 0x08288980
	.incbin "baserom_jp.gba", 0x288980, 0x15

BattleScript_EffectRefresh:: @ 0x08288995
	.incbin "baserom_jp.gba", 0x288995, 0x17

BattleScript_EffectGrudge:: @ 0x082889AC
	.incbin "baserom_jp.gba", 0x2889ac, 0x15

BattleScript_EffectSnatch:: @ 0x082889C1
	.incbin "baserom_jp.gba", 0x2889c1, 0x18

BattleScript_EffectLowKick:: @ 0x082889D9
	.incbin "baserom_jp.gba", 0x2889d9, 0x10

BattleScript_EffectSecretPower:: @ 0x082889E9
	.incbin "baserom_jp.gba", 0x2889e9, 0x6

BattleScript_EffectDoubleEdge:: @ 0x082889EF
	.incbin "baserom_jp.gba", 0x2889ef, 0xb

BattleScript_EffectTeeterDance:: @ 0x082889FA
	.incbin "baserom_jp.gba", 0x2889fa, 0xb7

BattleScript_EffectMudSport:: @ 0x08288AB1
BattleScript_EffectWaterSport:: @ 0x08288AB1
	.incbin "baserom_jp.gba", 0x288ab1, 0x17

BattleScript_EffectPoisonFang:: @ 0x08288AC8
	.incbin "baserom_jp.gba", 0x288ac8, 0xb

BattleScript_EffectWeatherBall:: @ 0x08288AD3
	.incbin "baserom_jp.gba", 0x288ad3, 0x6

BattleScript_EffectOverheat:: @ 0x08288AD9
	.incbin "baserom_jp.gba", 0x288ad9, 0xb

BattleScript_EffectTickle:: @ 0x08288AE4
	.incbin "baserom_jp.gba", 0x288ae4, 0x87

BattleScript_EffectCosmicPower:: @ 0x08288B6B
	.incbin "baserom_jp.gba", 0x288b6b, 0x64

BattleScript_EffectSkyUppercut:: @ 0x08288BCF
	.incbin "baserom_jp.gba", 0x288bcf, 0xe

BattleScript_EffectBulkUp:: @ 0x08288BDD
	.incbin "baserom_jp.gba", 0x288bdd, 0x64

BattleScript_EffectCalmMind:: @ 0x08288C41
	.incbin "baserom_jp.gba", 0x288c41, 0x78

BattleScript_EffectDragonDance:: @ 0x08288CB9
	.incbin "baserom_jp.gba", 0x288cb9, 0x64

BattleScript_EffectCamouflage:: @ 0x08288D1D
	.incbin "baserom_jp.gba", 0x288d1d, 0x15

@ Battle-end scripts. All visible JP entry points are named in their
@ physical order; raw spans remain until their battle-script macro conversion.
BattleScript_FaintAttacker:: @ 0x08288D32
	.incbin "baserom_jp.gba", 0x288d32, 0xd

BattleScript_FaintTarget:: @ 0x08288D3F
	.incbin "baserom_jp.gba", 0x288d3f, 0xd

BattleScript_GiveExp:: @ 0x08288D4C
	.incbin "baserom_jp.gba", 0x288d4c, 0x9

BattleScript_HandleFaintedMon:: @ 0x08288D55
	.incbin "baserom_jp.gba", 0x288d55, 0x49

BattleScript_FaintedMonTryChoose:: @ 0x08288D9E
	.incbin "baserom_jp.gba", 0x288d9e, 0xba

BattleScript_FaintedMonSendOutNew:: @ 0x08288E58
	.incbin "baserom_jp.gba", 0x288e58, 0x25

BattleScript_FaintedMonEnd:: @ 0x08288E7D
	.incbin "baserom_jp.gba", 0x288e7d, 0x1

BattleScript_LinkHandleFaintedMonMultiple:: @ 0x08288E7E
	.incbin "baserom_jp.gba", 0x288e7e, 0x6

BattleScript_LinkHandleFaintedMonMultipleStart:: @ 0x08288E84
	.incbin "baserom_jp.gba", 0x288e84, 0xc

BattleScript_LinkHandleFaintedMonLoop:: @ 0x08288E90
	.incbin "baserom_jp.gba", 0x288e90, 0x24

BattleScript_LinkHandleFaintedMonMultipleEnd:: @ 0x08288EB4
	.incbin "baserom_jp.gba", 0x288eb4, 0x1

BattleScript_LocalTrainerBattleWon:: @ 0x08288EB5
	.incbin "baserom_jp.gba", 0x288eb5, 0x16

BattleScript_LocalTwoTrainersDefeated:: @ 0x08288ECB
	.incbin "baserom_jp.gba", 0x288ecb, 0x3

BattleScript_LocalBattleWonLoseTexts:: @ 0x08288ECE
	.incbin "baserom_jp.gba", 0x288ece, 0x1d

BattleScript_LocalBattleWonReward:: @ 0x08288EEB
	.incbin "baserom_jp.gba", 0x288eeb, 0x7

BattleScript_PayDayMoneyAndPickUpItems:: @ 0x08288EF2
	.byte 0x91 @ givepaydaymoney
	.byte 0xE5 @ pickup
	.byte 0x3E @ end2

BattleScript_LocalBattleLost:: @ 0x08288EF5
	.incbin "baserom_jp.gba", 0x288ef5, 0x44

BattleScript_LocalBattleLostPrintWhiteOut:: @ 0x08288F39
	.incbin "baserom_jp.gba", 0x288f39, 0xc

BattleScript_LocalBattleLostEnd:: @ 0x08288F45
	.incbin "baserom_jp.gba", 0x288f45, 0x1

BattleScript_CheckDomeDrew:: @ 0x08288F46
	.incbin "baserom_jp.gba", 0x288f46, 0xb

BattleScript_LocalBattleLostPrintTrainersWinText:: @ 0x08288F51
	.incbin "baserom_jp.gba", 0x288f51, 0x38

BattleScript_LocalBattleLostDoTrainer2WinText:: @ 0x08288F89
	.incbin "baserom_jp.gba", 0x288f89, 0x9

BattleScript_LocalBattleLostEnd_:: @ 0x08288F92
	.incbin "baserom_jp.gba", 0x288f92, 0x1

BattleScript_FrontierLinkBattleLost:: @ 0x08288F93
	.incbin "baserom_jp.gba", 0x288f93, 0x26

BattleScript_FrontierLinkBattleLostEnd:: @ 0x08288FB9
	.incbin "baserom_jp.gba", 0x288fb9, 0x4

BattleScript_LinkBattleWonOrLost:: @ 0x08288FBD
	.incbin "baserom_jp.gba", 0x288fbd, 0x23

BattleScript_LinkBattleWonOrLostWaitEnd:: @ 0x08288FE0
	.incbin "baserom_jp.gba", 0x288fe0, 0x4

BattleScript_TowerLinkBattleWon:: @ 0x08288FE4
	.incbin "baserom_jp.gba", 0x288fe4, 0x27

BattleScript_TowerLinkBattleWonEnd:: @ 0x0828900B
	.incbin "baserom_jp.gba", 0x28900b, 0x4

BattleScript_FrontierTrainerBattleWon:: @ 0x0828900F
	.incbin "baserom_jp.gba", 0x28900f, 0x54

@ Escape, switch, and level-up scripts. All visible JP entry points are
@ named in physical order; opaque byte spans await macro conversion.
BattleScript_SmokeBallEscape:: @ 0x08289063
	.incbin "baserom_jp.gba", 0x289063, 0xe

BattleScript_RanAwayUsingMonAbility:: @ 0x08289071
	.byte 0x10, 0x53, 0x01 @ printstring STRINGID_PKMNFLEDUSING
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

BattleScript_GotAwaySafely:: @ 0x08289078
	.byte 0x10, 0xDF, 0x00 @ printstring STRINGID_GOTAWAYSAFELY
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

BattleScript_WildMonFled:: @ 0x0828907F
	.byte 0x10, 0xE0, 0x00 @ printstring STRINGID_WILDPKMNFLED
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

BattleScript_PrintCantRunFromTrainer:: @ 0x08289086
	.byte 0x10, 0xE1, 0x00 @ printstring STRINGID_NORUNNINGFROMTRAINERS
	.byte 0x3E @ end2

BattleScript_PrintFailedToRunString:: @ 0x0828908A
	.byte 0x13, 0xAA, 0xB9, 0x5A, 0x08 @ printfromtable 0x085AB9AA
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

BattleScript_PrintCantEscapeFromBattle:: @ 0x08289093
	.incbin "baserom_jp.gba", 0x289093, 0x6

BattleScript_PrintFullBox:: @ 0x08289099
	.byte 0x11, 0x58, 0x01 @ printselectionstring STRINGID_BOXISFULL
	.byte 0x44 @ endselectionscript

BattleScript_ActionSwitch:: @ 0x0828909D
	.incbin "baserom_jp.gba", 0x28909d, 0x20

BattleScript_PursuitSwitchDmgSetMultihit:: @ 0x082890BD
	.incbin "baserom_jp.gba", 0x2890bd, 0x2

BattleScript_PursuitSwitchDmgLoop:: @ 0x082890BF
	.incbin "baserom_jp.gba", 0x2890bf, 0xd

BattleScript_DoSwitchOut:: @ 0x082890CC
	.incbin "baserom_jp.gba", 0x2890cc, 0x33

BattleScript_PursuitDmgOnSwitchOut:: @ 0x082890FF
	.incbin "baserom_jp.gba", 0x2890ff, 0x42

BattleScript_Pausex20:: @ 0x08289141
	.byte 0x39, 0x20, 0x00 @ pause 0x0020
	.byte 0x3C @ return

BattleScript_LevelUp:: @ 0x08289145
	.incbin "baserom_jp.gba", 0x289145, 0x1c

BattleScript_TryLearnMoveLoop:: @ 0x08289161
	.incbin "baserom_jp.gba", 0x289161, 0xa

BattleScript_AskToLearnMove:: @ 0x0828916B
	.incbin "baserom_jp.gba", 0x28916b, 0x2d

BattleScript_ForgotAndLearnedNewMove:: @ 0x08289198
	.incbin "baserom_jp.gba", 0x289198, 0x9

BattleScript_LearnedNewMove:: @ 0x082891A1
	.incbin "baserom_jp.gba", 0x2891a1, 0x12

BattleScript_LearnMoveReturn:: @ 0x082891B3
	.incbin "baserom_jp.gba", 0x2891b3, 0x1

@ Weather-turn scripts. The physical entry points and loop labels are
@ retained explicitly; byte spans await battle-script macro conversion.
BattleScript_RainContinuesOrEnds:: @ 0x082891B4
	.incbin "baserom_jp.gba", 0x2891b4, 0x1a

BattleScript_RainContinuesOrEndsEnd:: @ 0x082891CE
	.incbin "baserom_jp.gba", 0x2891ce, 0x1

BattleScript_DamagingWeatherContinues:: @ 0x082891CF
	.incbin "baserom_jp.gba", 0x2891cf, 0x18

BattleScript_DamagingWeatherLoop:: @ 0x082891E7
	.incbin "baserom_jp.gba", 0x2891e7, 0x41

BattleScript_DamagingWeatherLoopIncrement:: @ 0x08289228
	.incbin "baserom_jp.gba", 0x289228, 0x1f

BattleScript_DamagingWeatherContinuesEnd:: @ 0x08289247
	.incbin "baserom_jp.gba", 0x289247, 0xa

BattleScript_SandStormHailEnds:: @ 0x08289251
	.incbin "baserom_jp.gba", 0x289251, 0x9

BattleScript_SunlightContinues:: @ 0x0828925A
	.incbin "baserom_jp.gba", 0x28925a, 0xe

BattleScript_SunlightFaded:: @ 0x08289268
	.incbin "baserom_jp.gba", 0x289268, 0x7

BattleScript_OverworldWeatherStarts:: @ 0x0828926F
	.incbin "baserom_jp.gba", 0x28926f, 0x13

@ Turn-end side-status scripts. These physical entry points include the
@ safeguard and Leech Seed branches; byte spans remain JP-exact for now.
BattleScript_SideStatusWoreOff:: @ 0x08289282
	.incbin "baserom_jp.gba", 0x289282, 0x7

BattleScript_SafeguardProtected:: @ 0x08289289
	.incbin "baserom_jp.gba", 0x289289, 0xa

BattleScript_SafeguardEnds:: @ 0x08289293
	.incbin "baserom_jp.gba", 0x289293, 0xa

BattleScript_LeechSeedTurnDrain:: @ 0x0828929D
	.incbin "baserom_jp.gba", 0x28929d, 0x32

BattleScript_LeechSeedTurnPrintLiquidOoze:: @ 0x082892CF
	.incbin "baserom_jp.gba", 0x2892cf, 0x6

BattleScript_LeechSeedTurnPrintAndUpdateHp:: @ 0x082892D5
	.incbin "baserom_jp.gba", 0x2892d5, 0x24

@ Bide's charge and release scripts. The complete three-path family stays
@ physically contiguous while its raw battle commands await conversion.
BattleScript_BideStoringEnergy:: @ 0x082892F9
	.byte 0x10, 0x78, 0x00 @ printstring STRINGID_PKMNSTORINGENERGY
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto 0x08286FD6

BattleScript_BideAttack:: @ 0x08289304
	.incbin "baserom_jp.gba", 0x289304, 0x48

BattleScript_BideNoEnergyToAttack:: @ 0x0828934C
	.incbin "baserom_jp.gba", 0x28934c, 0x14

@ Forced-switch scripts. The trainer branch begins at its actual JP entry
@ rather than remaining hidden inside a mixed EventScript container.
BattleScript_SuccessForceOut:: @ 0x08289360
	.incbin "baserom_jp.gba", 0x289360, 0x19

BattleScript_TrainerBattleForceOut:: @ 0x08289379
	.incbin "baserom_jp.gba", 0x289379, 0x12

@ Status-block and status-expiry response scripts. Preserve the Battle
@ Palace selection branch as separate physical entries instead of a raw
@ mixed container.
BattleScript_MistProtected:: @ 0x0828938B
	.incbin "baserom_jp.gba", 0x28938b, 0xa

BattleScript_RageIsBuilding:: @ 0x08289395
	.byte 0x10, 0x83, 0x00 @ printstring STRINGID_PKMNRAGEBUILDING
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

BattleScript_MoveUsedIsDisabled:: @ 0x0828939C
	.byte 0x10, 0x85, 0x00 @ printstring STRINGID_PKMNMOVEISDISABLED
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto 0x08286FD6

BattleScript_SelectingDisabledMove:: @ 0x082893A7
	.byte 0x11, 0x85, 0x00 @ printselectionstring STRINGID_PKMNMOVEISDISABLED
	.byte 0x44 @ endselectionscript

BattleScript_DisabledNoMore:: @ 0x082893AB
	.byte 0x10, 0x86, 0x00 @ printstring STRINGID_PKMNMOVEDISABLEDNOMORE
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

BattleScript_SelectingDisabledMoveInPalace:: @ 0x082893B2
	.incbin "baserom_jp.gba", 0x2893b2, 0x3

BattleScript_SelectingUnusableMoveInPalace:: @ 0x082893B5
	.incbin "baserom_jp.gba", 0x2893b5, 0xa

BattleScript_EncoredNoMore:: @ 0x082893BF
	.byte 0x10, 0x88, 0x00 @ printstring STRINGID_PKMNENCOREENDED
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

@ Delayed-faint scripts: Destiny Bond, Spikes, and Perish Song. Keep every
@ branch at its actual JP address, including the shared Spikes print path.
BattleScript_DestinyBondTakesLife:: @ 0x082893C6
	.incbin "baserom_jp.gba", 0x2893c6, 0x1b

BattleScript_SpikesOnAttacker:: @ 0x082893E1
	.incbin "baserom_jp.gba", 0x2893e1, 0x21

BattleScript_SpikesOnAttackerFainted:: @ 0x08289402
	.incbin "baserom_jp.gba", 0x289402, 0x16

BattleScript_SpikesOnTarget:: @ 0x08289418
	.incbin "baserom_jp.gba", 0x289418, 0x21

BattleScript_SpikesOnTargetFainted:: @ 0x08289439
	.incbin "baserom_jp.gba", 0x289439, 0x16

BattleScript_SpikesOnFaintedBattler:: @ 0x0828944F
	.incbin "baserom_jp.gba", 0x28944f, 0x21

BattleScript_SpikesOnFaintedBattlerFainted:: @ 0x08289470
	.incbin "baserom_jp.gba", 0x289470, 0x16

BattleScript_PrintHurtBySpikes:: @ 0x08289486
	.incbin "baserom_jp.gba", 0x289486, 0x7

BattleScript_PerishSongTakesLife:: @ 0x0828948D
	.incbin "baserom_jp.gba", 0x28948d, 0x1b

BattleScript_PerishSongCountGoesDown:: @ 0x082894A8
	.incbin "baserom_jp.gba", 0x2894a8, 0x7

@ All-stat boost script, split at each actual stat branch so the full
@ chained flow is visible without retaining a gUnknown container.
BattleScript_AllStatsUp:: @ 0x082894AF
	.incbin "baserom_jp.gba", 0x2894af, 0x2d

BattleScript_AllStatsUpAtk:: @ 0x082894DC
	.incbin "baserom_jp.gba", 0x2894dc, 0x1e

BattleScript_AllStatsUpDef:: @ 0x082894FA
	.incbin "baserom_jp.gba", 0x2894fa, 0x14

BattleScript_AllStatsUpSpeed:: @ 0x0828950E
	.incbin "baserom_jp.gba", 0x28950e, 0x14

BattleScript_AllStatsUpSpAtk:: @ 0x08289522
	.incbin "baserom_jp.gba", 0x289522, 0x14

BattleScript_AllStatsUpSpDef:: @ 0x08289536
	.incbin "baserom_jp.gba", 0x289536, 0x14

BattleScript_AllStatsUpRet:: @ 0x0828954A
	.incbin "baserom_jp.gba", 0x28954a, 0x1

@ Residual-effect cleanup scripts used by Rapid Spin: free wrapping,
@ Leech Seed, and Spikes in physical JP order.
BattleScript_RapidSpinAway:: @ 0x0828954B
	.byte 0xBE @ rapidspinfree
	.byte 0x3C @ return

BattleScript_WrapFree:: @ 0x0828954D
	.incbin "baserom_jp.gba", 0x28954d, 0x11

BattleScript_LeechSeedFree:: @ 0x0828955E
	.byte 0x10, 0x9E, 0x00 @ printstring STRINGID_PKMNSHEDLEECHSEED
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

BattleScript_SpikesFree:: @ 0x08289565
	.byte 0x10, 0x9F, 0x00 @ printstring STRINGID_PKMNBLEWAWAYSPIKES
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

@ Future Sight / Doom Desire resolution. All hit, miss, animation, and
@ return paths remain explicit at their physical JP entry points.
BattleScript_MonTookFutureAttack:: @ 0x0828956C
	.incbin "baserom_jp.gba", 0x28956c, 0x1d

BattleScript_CheckDoomDesireMiss:: @ 0x08289589
	.incbin "baserom_jp.gba", 0x289589, 0x7

BattleScript_FutureAttackAnimate:: @ 0x08289590
	.incbin "baserom_jp.gba", 0x289590, 0x18

BattleScript_FutureHitAnimDoomDesire:: @ 0x082895A8
	.incbin "baserom_jp.gba", 0x2895a8, 0x7

BattleScript_DoFutureAttackHit:: @ 0x082895AF
	.incbin "baserom_jp.gba", 0x2895af, 0x18

BattleScript_FutureAttackEnd:: @ 0x082895C7
	.incbin "baserom_jp.gba", 0x2895c7, 0x19

BattleScript_FutureAttackMiss:: @ 0x082895E0
	.incbin "baserom_jp.gba", 0x2895e0, 0x1a

@ Move-selection rejection scripts. Keep the distinct selection and in-battle
@ paths explicit so the JP physical order matches the US script owner.
BattleScript_NoMovesLeft:: @ 0x082895FA
	.byte 0x11, 0xA8, 0x00 @ printselectionstring STRINGID_PKMNHASNOMOVESLEFT
	.byte 0x44 @ endselectionscript

BattleScript_SelectingMoveWithNoPP:: @ 0x082895FE
	.byte 0x11, 0xFF, 0x00 @ printselectionstring STRINGID_NOPPLEFT
	.byte 0x44 @ endselectionscript

BattleScript_NoPPForMove:: @ 0x08289602
	.byte 0x02 @ attackstring
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0x00, 0x01 @ printstring STRINGID_BUTNOPPLEFT
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

BattleScript_SelectingTormentedMove:: @ 0x08289611
	.byte 0x11, 0xAA, 0x00 @ printselectionstring STRINGID_PKMNCANTUSEMOVETORMENT
	.byte 0x44 @ endselectionscript

BattleScript_MoveUsedIsTormented:: @ 0x08289615
	.byte 0x10, 0xAA, 0x00 @ printstring STRINGID_PKMNCANTUSEMOVETORMENT
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

BattleScript_SelectingTormentedMoveInPalace:: @ 0x08289620
	.byte 0x10, 0xAA, 0x00 @ printstring STRINGID_PKMNCANTUSEMOVETORMENT
	.byte 0x28, 0xB5, 0x93, 0x28, 0x08 @ goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedMoveTaunt:: @ 0x08289628
	.byte 0x11, 0xAD, 0x00 @ printselectionstring STRINGID_PKMNCANTUSEMOVETAUNT
	.byte 0x44 @ endselectionscript

BattleScript_MoveUsedIsTaunted:: @ 0x0828962C
	.byte 0x10, 0xAD, 0x00 @ printstring STRINGID_PKMNCANTUSEMOVETAUNT
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedMoveTauntInPalace:: @ 0x08289637
	.byte 0x10, 0xAD, 0x00 @ printstring STRINGID_PKMNCANTUSEMOVETAUNT
	.byte 0x28, 0xB5, 0x93, 0x28, 0x08 @ goto BattleScript_SelectingUnusableMoveInPalace

@ Wish and Ingrain healing paths, including their physical fallback/status
@ entries. Preserve JP command bytes while exposing the US-aligned labels.
BattleScript_WishComesTrue:: @ 0x0828963F
	.incbin "baserom_jp.gba", 0x28963f, 0x27

BattleScript_WishButFullHp:: @ 0x08289666
	.incbin "baserom_jp.gba", 0x289666, 0x10

BattleScript_IngrainTurnHeal:: @ 0x08289676
	.incbin "baserom_jp.gba", 0x289676, 0x1b

BattleScript_PrintMonIsRooted:: @ 0x08289691
	.incbin "baserom_jp.gba", 0x289691, 0xe

@ Shared Attack-and-Defense stat reduction script and its two branch targets.
BattleScript_AtkDefDown:: @ 0x0828969F
	.incbin "baserom_jp.gba", 0x28969f, 0x2d

BattleScript_AtkDefDown_TryDef:: @ 0x082896CC
	.incbin "baserom_jp.gba", 0x2896cc, 0x23

BattleScript_AtkDefDown_End:: @ 0x082896EF
	.incbin "baserom_jp.gba", 0x2896ef, 0x1

BattleScript_KnockedOff:: @ 0x082896F0
	.byte 0x45, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_TARGET, B_ANIM_ITEM_KNOCKOFF
	.byte 0x10, 0xB7, 0x00 @ printstring STRINGID_PKMNKNOCKEDOFF
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x3C @ return

@ Imprison and Grudge response paths.
BattleScript_MoveUsedIsImprisoned:: @ 0x082896FE
	.byte 0x10, 0xBA, 0x00 @ printstring STRINGID_PKMNCANTUSEMOVESEALED
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

BattleScript_SelectingImprisonedMove:: @ 0x08289709
	.byte 0x11, 0xBA, 0x00 @ printselectionstring STRINGID_PKMNCANTUSEMOVESEALED
	.byte 0x44 @ endselectionscript

BattleScript_SelectingImprisonedMoveInPalace:: @ 0x0828970D
	.byte 0x10, 0xBA, 0x00 @ printstring STRINGID_PKMNCANTUSEMOVESEALED
	.byte 0x28, 0xB5, 0x93, 0x28, 0x08 @ goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_GrudgeTakesPP:: @ 0x08289715
	.byte 0x10, 0xBC, 0x00 @ printstring STRINGID_PKMNLOSTPPGRUDGE
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

@ Magic Coat and Snatch interception paths.
BattleScript_MagicCoatBounce:: @ 0x0828971C
	.incbin "baserom_jp.gba", 0x28971c, 0x18

BattleScript_SnatchedMove:: @ 0x08289734
	.incbin "baserom_jp.gba", 0x289734, 0x1b

@ Battle result messages for Endure and a one-hit KO.
BattleScript_EnduredMsg:: @ 0x0828974F
	.byte 0x10, 0x99, 0x00 @ printstring STRINGID_PKMNENDUREDHIT
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

BattleScript_OneHitKOMsg:: @ 0x08289756
	.byte 0x10, 0xDA, 0x00 @ printstring STRINGID_ONEHITKO
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

@ Two-stage Special Attack reduction and its shared return target.
BattleScript_SAtkDown2:: @ 0x0828975D
	.incbin "baserom_jp.gba", 0x28975d, 0x29

BattleScript_SAtkDown2End:: @ 0x08289786
	.incbin "baserom_jp.gba", 0x289786, 0x1

BattleScript_FocusPunchSetUp:: @ 0x08289787
	.incbin "baserom_jp.gba", 0x289787, 0x14

@ Sleep-status responses: still asleep, regular wake-up, and Uproar wake-up.
BattleScript_MoveUsedIsAsleep:: @ 0x0828979B
	.incbin "baserom_jp.gba", 0x28979b, 0xd

BattleScript_MoveUsedWokeUp:: @ 0x082897A8
	.incbin "baserom_jp.gba", 0x2897a8, 0x14

BattleScript_MonWokeUpInUproar:: @ 0x082897BC
	.incbin "baserom_jp.gba", 0x2897bc, 0x9

@ Poison and burn residual-damage paths with their shared status handlers.
BattleScript_PoisonTurnDmg:: @ 0x082897C5
	.incbin "baserom_jp.gba", 0x2897c5, 0x6

BattleScript_DoStatusTurnDmg:: @ 0x082897CB
	.incbin "baserom_jp.gba", 0x2897cb, 0x2

BattleScript_DoTurnDmg:: @ 0x082897CD
	.incbin "baserom_jp.gba", 0x2897cd, 0x19

BattleScript_DoTurnDmgEnd:: @ 0x082897E6
	.incbin "baserom_jp.gba", 0x2897e6, 0x1

BattleScript_BurnTurnDmg:: @ 0x082897E7
	.incbin "baserom_jp.gba", 0x2897e7, 0xb

@ Frozen-status responses: unable to move, ordinary thaw, and fire thaw.
BattleScript_MoveUsedIsFrozen:: @ 0x082897F2
	.incbin "baserom_jp.gba", 0x2897f2, 0xd

BattleScript_MoveUsedUnfroze:: @ 0x082897FF
	.incbin "baserom_jp.gba", 0x2897ff, 0xb

BattleScript_DefrostedViaFireMove:: @ 0x0828980A
	.incbin "baserom_jp.gba", 0x28980a, 0x9

@ Action-denial responses for paralysis and flinching.
BattleScript_MoveUsedIsParalyzed:: @ 0x08289813
	.byte 0x10, 0x39, 0x00 @ printstring STRINGID_PKMNISPARALYZED
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x64, 0x01 @ statusanimation BS_ATTACKER
	.byte 0x76, 0x01, 0x00 @ cancelmultiturnmoves BS_ATTACKER
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

BattleScript_MoveUsedFlinched:: @ 0x08289823
	.byte 0x10, 0x4A, 0x00 @ printstring STRINGID_PKMNFLINCHED
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

	.globl BattleScript_PrintUproarOverTurns
BattleScript_PrintUproarOverTurns: @ 0x828982E
	.byte 0x13, 0xF2, 0xB9, 0x5A, 0x08 @ printfromtable 0x085AB9F2
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

	.globl BattleScript_ThrashConfuses
BattleScript_ThrashConfuses: @ 0x8289837
	.byte 0x66, 0x01, 0x01, 0x07, 0x00, 0x00, 0x00 @ chosenstatus2animation BS_ATTACKER, STATUS2_CONFUSION
	.byte 0x10, 0x7A, 0x00 @ printstring STRINGID_PKMNFATIGUECONFUSION
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x3E @ end2

	.globl BattleScript_MoveUsedIsConfused
BattleScript_MoveUsedIsConfused: @ 0x8289845
	.byte 0x10, 0x41, 0x00 @ printstring STRINGID_PKMNISCONFUSED
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x65, 0x01, 0x07, 0x00, 0x00, 0x00 @ status2animation BS_ATTACKER, STATUS2_CONFUSION
	.byte 0x29, 0x00, 0xDB, 0x3F, 0x02, 0x02, 0x00, 0x87, 0x98, 0x28, 0x08 @ jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, FALSE, BattleScript_MoveUsedIsConfusedRet

	.globl BattleScript_DoSelfConfusionDmg
BattleScript_DoSelfConfusionDmg: @ 0x828985C
	.byte 0x76, 0x01, 0x00 @ cancelmultiturnmoves BS_ATTACKER
	.byte 0x08 @ adjustnormaldamage2
	.byte 0x10, 0xE6, 0x00 @ printstring STRINGID_ITHURTCONFUSION
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x0E @ effectivenesssound
	.byte 0x5C, 0x01 @ hitanimation BS_ATTACKER
	.byte 0x3A @ waitstate
	.byte 0x35, 0x24, 0x3F, 0x02, 0x02, 0x00, 0x01, 0x10, 0x00 @ orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_HP_UPDATE
	.byte 0x0B, 0x01 @ healthbarupdate BS_ATTACKER
	.byte 0x0C, 0x01 @ datahpupdate BS_ATTACKER
	.byte 0x0F @ resultmessage
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x19, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00 @ tryfaintmon BS_ATTACKER
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

	.globl BattleScript_MoveUsedIsConfusedRet
BattleScript_MoveUsedIsConfusedRet: @ 0x8289887
	.byte 0x3C @ return

	.globl BattleScript_MoveUsedIsConfusedNoMore
BattleScript_MoveUsedIsConfusedNoMore: @ 0x8289888
	.byte 0x10, 0x42, 0x00 @ printstring STRINGID_PKMNHEALEDCONFUSION
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

	.globl BattleScript_PrintPayDayMoneyString
BattleScript_PrintPayDayMoneyString: @ 0x828988F
	.byte 0x10, 0x7B, 0x00 @ printstring STRINGID_PLAYERPICKEDUPMONEY
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

	.globl BattleScript_WrapTurnDmg
BattleScript_WrapTurnDmg: @ 0x8289896
	.byte 0x45, 0x01, 0x06, 0x28, 0x41, 0x02, 0x02 @ playanimation BS_ATTACKER, B_ANIM_TURN_TRAP, sB_ANIM_ARG1
	.byte 0x10, 0x5E, 0x00 @ printstring STRINGID_PKMNHURTBY
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0xCD, 0x97, 0x28, 0x08 @ goto BattleScript_DoTurnDmg

	.globl BattleScript_WrapEnds
BattleScript_WrapEnds: @ 0x82898A8
	.byte 0x10, 0x5F, 0x00 @ printstring STRINGID_PKMNFREEDFROM
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

	.globl BattleScript_MoveUsedIsInLove
BattleScript_MoveUsedIsInLove: @ 0x82898AF
	.byte 0x10, 0x46, 0x00 @ printstring STRINGID_PKMNINLOVE
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x65, 0x01, 0x00, 0x00, 0x0F, 0x00 @ status2animation BS_ATTACKER, STATUS2_INFATUATION
	.byte 0x3C @ return

	.globl BattleScript_MoveUsedIsInLoveCantAttack
BattleScript_MoveUsedIsInLoveCantAttack: @ 0x82898BC
	.byte 0x10, 0x47, 0x00 @ printstring STRINGID_PKMNIMMOBILIZEDBYLOVE
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto 0x08286FD6

	.globl BattleScript_NightmareTurnDmg
BattleScript_NightmareTurnDmg: @ 0x82898C7
	.byte 0x10, 0x91, 0x00 @ printstring STRINGID_PKMNLOCKEDINNIGHTMARE
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x65, 0x01, 0x00, 0x00, 0x00, 0x08 @ status2animation BS_ATTACKER, STATUS2_NIGHTMARE
	.byte 0x28, 0xCD, 0x97, 0x28, 0x08 @ goto BattleScript_DoTurnDmg

	.globl BattleScript_CurseTurnDmg
BattleScript_CurseTurnDmg: @ 0x82898D8
	.byte 0x10, 0x93, 0x00 @ printstring STRINGID_PKMNAFFLICTEDBYCURSE
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x65, 0x01, 0x00, 0x00, 0x00, 0x10 @ status2animation BS_ATTACKER, STATUS2_CURSED
	.byte 0x28, 0xCD, 0x97, 0x28, 0x08 @ goto BattleScript_DoTurnDmg

	.globl BattleScript_TargetPRLZHeal
BattleScript_TargetPRLZHeal: @ 0x82898E9
	.byte 0x10, 0x3B, 0x00 @ printstring STRINGID_PKMNHEALEDPARALYSIS
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x98, 0x00 @ updatestatusicon BS_TARGET
	.byte 0x3C @ return

	.globl BattleScript_MoveEffectSleep
BattleScript_MoveEffectSleep: @ 0x82898F2
	.byte 0x64, 0x02 @ statusanimation BS_EFFECT_BATTLER
	.byte 0x13, 0x50, 0xBA, 0x5A, 0x08 @ printfromtable gFellAsleepStringIds
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG

	.globl BattleScript_UpdateEffectStatusIconRet
BattleScript_UpdateEffectStatusIconRet: @ 0x82898FC
	.byte 0x98, 0x02 @ updatestatusicon BS_EFFECT_BATTLER
	.byte 0x3A @ waitstate
	.byte 0x3C @ return

	.globl BattleScript_YawnMakesAsleep
BattleScript_YawnMakesAsleep: @ 0x8289900
	.byte 0x64, 0x02 @ statusanimation BS_EFFECT_BATTLER
	.byte 0x10, 0x23, 0x00 @ printstring STRINGID_PKMNFELLASLEEP
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x98, 0x02 @ updatestatusicon BS_EFFECT_BATTLER
	.byte 0x3A @ waitstate
	.byte 0x6F, 0x02 @ makevisible BS_EFFECT_BATTLER
	.byte 0x3E @ end2

	.globl BattleScript_MoveEffectPoison
BattleScript_MoveEffectPoison: @ 0x828990E
	.byte 0x64, 0x02 @ statusanimation BS_EFFECT_BATTLER
	.byte 0x13, 0x48, 0xBA, 0x5A, 0x08 @ printfromtable gGotPoisonedStringIds
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0xFC, 0x98, 0x28, 0x08 @ goto BattleScript_UpdateEffectStatusIconRet

	.globl BattleScript_MoveEffectBurn
BattleScript_MoveEffectBurn: @ 0x828991D
	.byte 0x64, 0x02 @ statusanimation BS_EFFECT_BATTLER
	.byte 0x13, 0x54, 0xBA, 0x5A, 0x08 @ printfromtable gGotBurnedStringIds
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0xFC, 0x98, 0x28, 0x08 @ goto BattleScript_UpdateEffectStatusIconRet

	.globl BattleScript_MoveEffectFreeze
BattleScript_MoveEffectFreeze: @ 0x828992C
	.byte 0x64, 0x02 @ statusanimation BS_EFFECT_BATTLER
	.byte 0x13, 0x58, 0xBA, 0x5A, 0x08 @ printfromtable gGotFrozenStringIds
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0xFC, 0x98, 0x28, 0x08 @ goto BattleScript_UpdateEffectStatusIconRet

	.globl BattleScript_MoveEffectParalysis
BattleScript_MoveEffectParalysis: @ 0x828993B
	.byte 0x64, 0x02 @ statusanimation BS_EFFECT_BATTLER
	.byte 0x13, 0x4C, 0xBA, 0x5A, 0x08 @ printfromtable gGotParalyzedStringIds
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0xFC, 0x98, 0x28, 0x08 @ goto BattleScript_UpdateEffectStatusIconRet

	.globl BattleScript_MoveEffectUproar
BattleScript_MoveEffectUproar: @ 0x828994A
	.byte 0x10, 0x6F, 0x00 @ printstring STRINGID_PKMNCAUSEDUPROAR
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x3C @ return

	.globl BattleScript_MoveEffectToxic
BattleScript_MoveEffectToxic: @ 0x8289951
	.byte 0x64, 0x02 @ statusanimation BS_EFFECT_BATTLER
	.byte 0x10, 0x2C, 0x00 @ printstring STRINGID_PKMNBADLYPOISONED
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0xFC, 0x98, 0x28, 0x08 @ goto BattleScript_UpdateEffectStatusIconRet

	.globl BattleScript_MoveEffectPayDay
BattleScript_MoveEffectPayDay: @ 0x828995E
	.byte 0x10, 0xFA, 0x00 @ printstring STRINGID_COINSSCATTERED
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x3C @ return

	.globl BattleScript_MoveEffectWrap
BattleScript_MoveEffectWrap: @ 0x8289965
	.byte 0x13, 0x2C, 0xBA, 0x5A, 0x08 @ printfromtable gWrappedStringIds
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x3C @ return

	.globl BattleScript_MoveEffectConfusion
BattleScript_MoveEffectConfusion: @ 0x828996E
	.byte 0x66, 0x02, 0x01, 0x07, 0x00, 0x00, 0x00 @ chosenstatus2animation BS_EFFECT_BATTLER, STATUS2_CONFUSION
	.byte 0x10, 0x43, 0x00 @ printstring STRINGID_PKMNWASCONFUSED
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x3C @ return

	.globl BattleScript_MoveEffectRecoil
BattleScript_MoveEffectRecoil: @ 0x828997C
	.byte 0x2A, 0x00, 0x8E, 0x3E, 0x02, 0x02, 0xA5, 0x00, 0x8F, 0x99, 0x28, 0x08 @ jumpifmove MOVE_STRUGGLE, BattleScript_DoRecoil
	.byte 0x1E, 0x01, 0x45, 0xA9, 0x99, 0x28, 0x08 @ jumpifability BS_ATTACKER, ABILITY_ROCK_HEAD, BattleScript_RecoilEnd

	.globl BattleScript_DoRecoil
BattleScript_DoRecoil: @ 0x828998F
	.byte 0x35, 0x24, 0x3F, 0x02, 0x02, 0x00, 0x01, 0x10, 0x00 @ orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_HP_UPDATE
	.byte 0x0B, 0x01 @ healthbarupdate BS_ATTACKER
	.byte 0x0C, 0x01 @ datahpupdate BS_ATTACKER
	.byte 0x10, 0x64, 0x00 @ printstring STRINGID_PKMNHITWITHRECOIL
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x19, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00 @ tryfaintmon BS_ATTACKER

	.globl BattleScript_RecoilEnd
BattleScript_RecoilEnd: @ 0x82899A9
	.byte 0x3C @ return

	.globl BattleScript_ItemSteal
BattleScript_ItemSteal: @ 0x82899AA
	.byte 0x45, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_TARGET, B_ANIM_ITEM_STEAL
	.byte 0x10, 0x8E, 0x00 @ printstring STRINGID_PKMNSTOLEITEM
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x3C @ return

	.globl BattleScript_DrizzleActivates
BattleScript_DrizzleActivates: @ 0x82899B8
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0xC1, 0x00 @ printstring STRINGID_PKMNMADEITRAIN
	.byte 0x3A @ waitstate
	.byte 0x45, 0x07, 0x0A, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_BATTLER_0, B_ANIM_RAIN_CONTINUES
	.byte 0x41, 0x15, 0x9A, 0x28, 0x08 @ call BattleScript_WeatherFormChanges
	.byte 0x3F @ end3

	.globl BattleScript_SpeedBoostActivates
BattleScript_SpeedBoostActivates: @ 0x82899CC
	.byte 0x45, 0x01, 0x01, 0x28, 0x41, 0x02, 0x02 @ playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	.byte 0x10, 0xC2, 0x00 @ printstring STRINGID_PKMNRAISEDSPEED
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x3F @ end3

	.globl BattleScript_TraceActivates
BattleScript_TraceActivates: @ 0x82899DA
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0xD0, 0x00 @ printstring STRINGID_PKMNTRACED
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x3F @ end3

	.globl BattleScript_RainDishActivates
BattleScript_RainDishActivates: @ 0x82899E4
	.byte 0x10, 0x33, 0x01 @ printstring STRINGID_PKMNSXRESTOREDHPALITTLE2
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x35, 0x24, 0x3F, 0x02, 0x02, 0x00, 0x01, 0x00, 0x00 @ orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	.byte 0x0B, 0x01 @ healthbarupdate BS_ATTACKER
	.byte 0x0C, 0x01 @ datahpupdate BS_ATTACKER
	.byte 0x3F @ end3

	.globl BattleScript_SandstreamActivates
BattleScript_SandstreamActivates: @ 0x82899F8
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0x34, 0x01 @ printstring STRINGID_PKMNSXWHIPPEDUPSANDSTORM
	.byte 0x3A @ waitstate
	.byte 0x45, 0x07, 0x0C, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_BATTLER_0, B_ANIM_SANDSTORM_CONTINUES
	.byte 0x41, 0x15, 0x9A, 0x28, 0x08 @ call BattleScript_WeatherFormChanges
	.byte 0x3F @ end3

	.globl BattleScript_ShedSkinActivates
BattleScript_ShedSkinActivates: @ 0x8289A0C
	.byte 0x10, 0x38, 0x01 @ printstring STRINGID_PKMNSXCUREDYPROBLEM
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x98, 0x01 @ updatestatusicon BS_ATTACKER
	.byte 0x3F @ end3

	.globl BattleScript_WeatherFormChanges
BattleScript_WeatherFormChanges: @ 0x8289A15
	.byte 0x2E, 0x2F, 0x41, 0x02, 0x02, 0x00 @ setbyte sBATTLER, 0

	.globl BattleScript_WeatherFormChangesLoop
BattleScript_WeatherFormChangesLoop: @ 0x8289A1B
	.byte 0xE7 @ trycastformdatachange
	.byte 0x2F, 0x2F, 0x41, 0x02, 0x02, 0x01 @ addbyte sBATTLER, 1
	.byte 0x2D, 0x2F, 0x41, 0x02, 0x02, 0x10, 0x3D, 0x02, 0x02, 0x01, 0x1B, 0x9A, 0x28, 0x08 @ jumpifbytenotequal sBATTLER, gBattlersCount, BattleScript_WeatherFormChangesLoop
	.byte 0x3C @ return

	.globl BattleScript_CastformChange
BattleScript_CastformChange: @ 0x8289A31
	.byte 0x41, 0x37, 0x9A, 0x28, 0x08 @ call BattleScript_DoCastformChange
	.byte 0x3F @ end3

	.globl BattleScript_DoCastformChange
BattleScript_DoCastformChange: @ 0x8289A37
	.byte 0xE6 @ docastformchangeanimation
	.byte 0x3A @ waitstate
	.byte 0x10, 0x3A, 0x01 @ printstring STRINGID_PKMNTRANSFORMED
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

	.globl BattleScript_IntimidateActivatesEnd3
BattleScript_IntimidateActivatesEnd3: @ 0x8289A40
	.byte 0x41, 0x46, 0x9A, 0x28, 0x08 @ call BattleScript_PauseIntimidateActivates
	.byte 0x3F @ end3

	.globl BattleScript_PauseIntimidateActivates
BattleScript_PauseIntimidateActivates: @ 0x8289A46
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT

	.globl BattleScript_IntimidateActivates
BattleScript_IntimidateActivates: @ 0x8289A49
	.byte 0x2E, 0xB0, 0x3E, 0x02, 0x02, 0x00 @ setbyte gBattlerTarget, 0
	.byte 0x2E, 0x32, 0x41, 0x02, 0x02, 0x91 @ setstatchanger STAT_ATK, 1, TRUE

	.globl BattleScript_IntimidateActivatesLoop
BattleScript_IntimidateActivatesLoop: @ 0x8289A55
	.byte 0xE1, 0xA3, 0x9A, 0x28, 0x08 @ trygetintimidatetarget BattleScript_IntimidateActivatesReturn
	.byte 0x1D, 0x00, 0x00, 0x00, 0x00, 0x01, 0x98, 0x9A, 0x28, 0x08 @ jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_IntimidateActivatesLoopIncrement
	.byte 0x1E, 0x00, 0x1D, 0xA4, 0x9A, 0x28, 0x08 @ jumpifability BS_TARGET, ABILITY_CLEAR_BODY, BattleScript_IntimidatePrevented
	.byte 0x1E, 0x00, 0x34, 0xA4, 0x9A, 0x28, 0x08 @ jumpifability BS_TARGET, ABILITY_HYPER_CUTTER, BattleScript_IntimidatePrevented
	.byte 0x1E, 0x00, 0x49, 0xA4, 0x9A, 0x28, 0x08 @ jumpifability BS_TARGET, ABILITY_WHITE_SMOKE, BattleScript_IntimidatePrevented
	.byte 0x89, 0x21, 0x98, 0x9A, 0x28, 0x08 @ statbuffchange STAT_CHANGE_NOT_PROTECT_AFFECTED | STAT_CHANGE_ALLOW_PTR, BattleScript_IntimidateActivatesLoopIncrement
	.byte 0x29, 0x02, 0xDB, 0x3F, 0x02, 0x02, 0x01, 0x98, 0x9A, 0x28, 0x08 @ jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, 1, BattleScript_IntimidateActivatesLoopIncrement
	.byte 0x47 @ setgraphicalstatchangevalues
	.byte 0x45, 0x00, 0x01, 0x28, 0x41, 0x02, 0x02 @ playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	.byte 0x10, 0xCD, 0x00 @ printstring STRINGID_PKMNCUTSATTACKWITH
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG

	.globl BattleScript_IntimidateActivatesLoopIncrement
BattleScript_IntimidateActivatesLoopIncrement: @ 0x8289A98
	.byte 0x2F, 0xB0, 0x3E, 0x02, 0x02, 0x01 @ addbyte gBattlerTarget, 1
	.byte 0x28, 0x55, 0x9A, 0x28, 0x08 @ goto BattleScript_IntimidateActivatesLoop

	.globl BattleScript_IntimidateActivatesReturn
BattleScript_IntimidateActivatesReturn: @ 0x8289AA3
	.byte 0x3C @ return

	.globl BattleScript_IntimidatePrevented
BattleScript_IntimidatePrevented: @ 0x8289AA4
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0x55, 0x01 @ printstring STRINGID_PREVENTEDFROMWORKING
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0x98, 0x9A, 0x28, 0x08 @ goto BattleScript_IntimidateActivatesLoopIncrement

	.globl BattleScript_DroughtActivates
BattleScript_DroughtActivates: @ 0x8289AB2
	.include "data/scripts/gUnknown_8289AB2.inc"

	.globl BattleScript_TookAttack
BattleScript_TookAttack: @ 0x8289AC6
	.include "data/scripts/gUnknown_8289AC6.inc"

	.globl BattleScript_SturdyPreventsOHKO
BattleScript_SturdyPreventsOHKO: @ 0x8289ADA
	.include "data/scripts/gUnknown_8289ADA.inc"

	.globl BattleScript_DampStopsExplosion
BattleScript_DampStopsExplosion: @ 0x8289AE8
	.include "data/scripts/gUnknown_8289AE8.inc"

	.globl BattleScript_MoveHPDrain_PPLoss
BattleScript_MoveHPDrain_PPLoss: @ 0x8289AF6
	.include "data/scripts/gUnknown_8289AF6.inc"

	.globl BattleScript_MoveHPDrain
BattleScript_MoveHPDrain: @ 0x8289AF7
	.include "data/scripts/gUnknown_8289AF7.inc"

	.globl BattleScript_MonMadeMoveUseless_PPLoss
BattleScript_MonMadeMoveUseless_PPLoss: @ 0x8289B19
	.include "data/scripts/gUnknown_8289B19.inc"

	.globl BattleScript_MonMadeMoveUseless
BattleScript_MonMadeMoveUseless: @ 0x8289B1A
	.include "data/scripts/gUnknown_8289B1A.inc"

	.globl BattleScript_FlashFireBoost_PPLoss
BattleScript_FlashFireBoost_PPLoss: @ 0x8289B2F
	.include "data/scripts/gUnknown_8289B2F.inc"

	.globl BattleScript_FlashFireBoost
BattleScript_FlashFireBoost: @ 0x8289B30
	.include "data/scripts/gUnknown_8289B30.inc"

	.globl BattleScript_AbilityNoStatLoss
BattleScript_AbilityNoStatLoss: @ 0x8289B4F
	.include "data/scripts/gUnknown_8289B4F.inc"

	.globl BattleScript_BRNPrevention
BattleScript_BRNPrevention: @ 0x8289B59
	.byte 0x39, 0x20, 0x00 @ pause 0x0020
	.byte 0x13, 0xCA, 0xBA, 0x5A, 0x08 @ printfromtable 0x085ABACA
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

	.globl BattleScript_PRLZPrevention
BattleScript_PRLZPrevention: @ 0x8289B65
	.byte 0x39, 0x20, 0x00 @ pause 0x0020
	.byte 0x13, 0xD0, 0xBA, 0x5A, 0x08 @ printfromtable 0x085ABAD0
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

	.globl BattleScript_PSNPrevention
BattleScript_PSNPrevention: @ 0x8289B71
	.byte 0x39, 0x20, 0x00 @ pause 0x0020
	.byte 0x13, 0xD6, 0xBA, 0x5A, 0x08 @ printfromtable 0x085ABAD6
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

	.globl BattleScript_ObliviousPreventsAttraction
BattleScript_ObliviousPreventsAttraction: @ 0x8289B7D
	.include "data/scripts/gUnknown_8289B7D.inc"

	.globl BattleScript_FlinchPrevention
BattleScript_FlinchPrevention: @ 0x8289B8B
	.include "data/scripts/gUnknown_8289B8B.inc"

	.globl BattleScript_SoundproofProtected
BattleScript_SoundproofProtected: @ 0x8289BA7
	.include "data/scripts/gUnknown_8289BA7.inc"

	.globl BattleScript_AbilityNoSpecificStatLoss
BattleScript_AbilityNoSpecificStatLoss: @ 0x8289BB7
	.include "data/scripts/gUnknown_8289BB7.inc"

	.globl BattleScript_StickyHoldActivates
BattleScript_StickyHoldActivates: @ 0x8289BC7
	.include "data/scripts/gUnknown_8289BC7.inc"

	.globl BattleScript_ColorChangeActivates
BattleScript_ColorChangeActivates: @ 0x8289BD5
	.byte 0x10, 0xC6, 0x00 @ printstring STRINGID_PKMNCHANGEDTYPEWITH
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

	.globl BattleScript_RoughSkinActivates
BattleScript_RoughSkinActivates: @ 0x8289BDC
	.include "data/scripts/gUnknown_8289BDC.inc"

	.globl BattleScript_CuteCharmActivates
BattleScript_CuteCharmActivates: @ 0x8289BF7
	.include "data/scripts/gUnknown_8289BF7.inc"

	.globl BattleScript_ApplySecondaryEffect
BattleScript_ApplySecondaryEffect: @ 0x8289C04
	.byte 0x3A @ waitstate
	.byte 0x17 @ seteffectsecondary
	.byte 0x3C @ return

	.globl BattleScript_SynchronizeActivates
BattleScript_SynchronizeActivates: @ 0x8289C07
	.byte 0x3A @ waitstate
	.byte 0x16 @ seteffectprimary
	.byte 0x3C @ return

	.globl BattleScript_NoItemSteal
BattleScript_NoItemSteal: @ 0x8289C0A
	.include "data/scripts/gUnknown_8289C0A.inc"

	.globl BattleScript_AbilityCuredStatus
BattleScript_AbilityCuredStatus: @ 0x8289C14
	.include "data/scripts/gUnknown_8289C14.inc"

	.globl BattleScript_IgnoresWhileAsleep
BattleScript_IgnoresWhileAsleep: @ 0x8289C1D
	.include "data/scripts/gUnknown_8289C1D.inc"

	.globl BattleScript_IgnoresAndUsesRandomMove
BattleScript_IgnoresAndUsesRandomMove: @ 0x8289C2D
	.include "data/scripts/gUnknown_8289C2D.inc"

	.globl BattleScript_MoveUsedLoafingAround
BattleScript_MoveUsedLoafingAround: @ 0x8289C35
	.include "data/scripts/gUnknown_8289C35.inc"

	.globl BattleScript_IgnoresAndFallsAsleep
BattleScript_IgnoresAndFallsAsleep: @ 0x8289C61
	.include "data/scripts/gUnknown_8289C61.inc"

	.globl BattleScript_IgnoresAndHitsItself
BattleScript_IgnoresAndHitsItself: @ 0x8289C78
	.include "data/scripts/gUnknown_8289C78.inc"

	.globl BattleScript_SubstituteFade
BattleScript_SubstituteFade: @ 0x8289C83
	.include "data/scripts/gUnknown_8289C83.inc"

	.globl BattleScript_BerryCurePrlzEnd2
BattleScript_BerryCurePrlzEnd2: @ 0x8289C8E
	.byte 0x41, 0x94, 0x9C, 0x28, 0x08 @ call 0x08289C94
	.byte 0x3E @ end2

	.globl BattleScript_BerryCureParRet
BattleScript_BerryCureParRet: @ 0x8289C94
	.include "data/scripts/gUnknown_8289C94.inc"

	.globl BattleScript_BerryCurePsnEnd2
BattleScript_BerryCurePsnEnd2: @ 0x8289CA6
	.byte 0x41, 0xAC, 0x9C, 0x28, 0x08 @ call 0x08289CAC
	.byte 0x3E @ end2

	.globl BattleScript_BerryCurePsnRet
BattleScript_BerryCurePsnRet: @ 0x8289CAC
	.include "data/scripts/gUnknown_8289CAC.inc"

	.globl BattleScript_BerryCureBrnEnd2
BattleScript_BerryCureBrnEnd2: @ 0x8289CBE
	.byte 0x41, 0xC4, 0x9C, 0x28, 0x08 @ call 0x08289CC4
	.byte 0x3E @ end2

	.globl BattleScript_BerryCureBrnRet
BattleScript_BerryCureBrnRet: @ 0x8289CC4
	.include "data/scripts/gUnknown_8289CC4.inc"

	.globl BattleScript_BerryCureFrzEnd2
BattleScript_BerryCureFrzEnd2: @ 0x8289CD6
	.include "data/scripts/gUnknown_8289CD6.inc"

	.globl BattleScript_BerryCureFrzRet
BattleScript_BerryCureFrzRet: @ 0x8289CDC
	.include "data/scripts/gUnknown_8289CDC.inc"

	.globl BattleScript_BerryCureSlpEnd2
BattleScript_BerryCureSlpEnd2: @ 0x8289CEE
	.byte 0x41, 0xF4, 0x9C, 0x28, 0x08 @ call 0x08289CF4
	.byte 0x3E @ end2

	.globl BattleScript_BerryCureSlpRet
BattleScript_BerryCureSlpRet: @ 0x8289CF4
	.include "data/scripts/gUnknown_8289CF4.inc"

	.globl BattleScript_BerryCureConfusionEnd2
BattleScript_BerryCureConfusionEnd2: @ 0x8289D06
	.include "data/scripts/gUnknown_8289D06.inc"

	.globl BattleScript_BerryCureConfusionRet
BattleScript_BerryCureConfusionRet: @ 0x8289D0C
	.include "data/scripts/gUnknown_8289D0C.inc"

	.globl BattleScript_BerryCureChosenStatusEnd2
BattleScript_BerryCureChosenStatusEnd2: @ 0x8289D1C
	.byte 0x41, 0x22, 0x9D, 0x28, 0x08 @ call 0x08289D22
	.byte 0x3E @ end2

	.globl BattleScript_BerryCureChosenStatusRet
BattleScript_BerryCureChosenStatusRet: @ 0x8289D22
	.include "data/scripts/gUnknown_8289D22.inc"

	.globl BattleScript_WhiteHerbEnd2
BattleScript_WhiteHerbEnd2: @ 0x8289D36
	.include "data/scripts/gUnknown_8289D36.inc"

	.globl BattleScript_WhiteHerbRet
BattleScript_WhiteHerbRet: @ 0x8289D3C
	.include "data/scripts/gUnknown_8289D3C.inc"

	.globl BattleScript_ItemHealHP_RemoveItem
BattleScript_ItemHealHP_RemoveItem: @ 0x8289D4C
	.include "data/scripts/gUnknown_8289D4C.inc"

	.globl BattleScript_BerryPPHealEnd2
BattleScript_BerryPPHealEnd2: @ 0x8289D69
	.include "data/scripts/gUnknown_8289D69.inc"

	.globl BattleScript_ItemHealHP_End2
BattleScript_ItemHealHP_End2: @ 0x8289D79
	.byte 0x41, 0x7F, 0x9D, 0x28, 0x08 @ call 0x08289D7F
	.byte 0x3E @ end2

	.globl BattleScript_ItemHealHP_Ret
BattleScript_ItemHealHP_Ret: @ 0x8289D7F
	.include "data/scripts/gUnknown_8289D7F.inc"

	.globl BattleScript_SelectingNotAllowedMoveChoiceItem
BattleScript_SelectingNotAllowedMoveChoiceItem: @ 0x8289D9A
	.byte 0x11, 0x2E, 0x01 @ printselectionstring STRINGID_ITEMALLOWSONLYYMOVE
	.byte 0x44 @ endselectionscript

	.globl BattleScript_FocusBandActivates
BattleScript_FocusBandActivates: @ 0x8289D9E
	.include "data/scripts/gUnknown_8289D9E.inc"

	.globl BattleScript_BerryConfuseHealEnd2
BattleScript_BerryConfuseHealEnd2: @ 0x8289DAC
	.include "data/scripts/gUnknown_8289DAC.inc"

	.globl BattleScript_BerryStatRaiseEnd2
BattleScript_BerryStatRaiseEnd2: @ 0x8289DD6
	.include "data/scripts/gUnknown_8289DD6.inc"

	.globl BattleScript_BerryFocusEnergyEnd2
BattleScript_BerryFocusEnergyEnd2: @ 0x8289DF1
	.include "data/scripts/gUnknown_8289DF1.inc"

	.globl gUnknown_8289E01
gUnknown_8289E01: @ 0x8289E01
	.byte 0x11, 0x43, 0x01 @ printselectionstring STRINGID_ITEMSCANTBEUSEDNOW
	.byte 0x44 @ endselectionscript

	.globl BattleScript_FlushMessageBox
BattleScript_FlushMessageBox: @ 0x8289E05
	.byte 0x10, 0x30, 0x01 @ printstring STRINGID_EMPTYSTRING3
	.byte 0x3C @ return

	.globl BattleScript_PalacePrintFlavorText
BattleScript_PalacePrintFlavorText: @ 0x8289E09
	.include "data/scripts/gUnknown_8289E09.inc"

	.globl BattleScript_ArenaTurnBeginning
BattleScript_ArenaTurnBeginning: @ 0x8289E46
	.include "data/scripts/gUnknown_8289E46.inc"

	.globl BattleScript_ArenaDoJudgment
BattleScript_ArenaDoJudgment: @ 0x8289E7B
	.include "data/scripts/gUnknown_8289E7B.inc"

	.globl gUnknown_8289F42
gUnknown_8289F42: @ 0x8289F42
	.byte 0x11, 0x75, 0x01 @ printselectionstring STRINGID_QUESTIONFORFEITMATCH
	.byte 0x76, 0x01, 0x0D @ various 0x01, 0x0D
	.byte 0x44 @ endselectionscript

	.globl BattleScript_PrintPlayerForfeited
BattleScript_PrintPlayerForfeited: @ 0x8289F49
	.byte 0x10, 0x76, 0x01 @ printstring STRINGID_FORFEITEDMATCH
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

	.globl BattleScript_PrintPlayerForfeitedLinkBattle
BattleScript_PrintPlayerForfeitedLinkBattle: @ 0x8289F50
	.include "data/scripts/gUnknown_8289F50.inc"
