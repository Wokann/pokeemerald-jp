
#include "config.h"
#include "constants/global.h"
#include "constants/abilities.h"
#include "constants/apprentice.h"
#include "constants/battle.h"
#include "constants/battle_anim.h"
#include "constants/battle_arena.h"
#include "constants/battle_dome.h"
#include "constants/battle_factory.h"
#include "constants/battle_frontier.h"
#include "constants/battle_palace.h"
#include "constants/battle_pike.h"
#include "constants/battle_pyramid.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_setup.h"
#include "constants/battle_string_ids.h"
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

	.include "asm/macros/battle_script.inc"
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
@ Script bodies are migrated in verified physical-ROM-order batches.
BattleScript_EffectHit:: @ 0x08286F88
	jumpifnotmove MOVE_SURF, BattleScript_HitFromAtkCanceler
	jumpifnostatus3 BS_TARGET, STATUS3_UNDERWATER, BattleScript_HitFromAtkCanceler
	orword gHitMarker, HITMARKER_IGNORE_UNDERWATER
	setbyte sDMG_MULTIPLIER, 2
BattleScript_HitFromAtkCanceler::
	attackcanceler
BattleScript_HitFromAccCheck::
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
BattleScript_HitFromAtkString::
	attackstring
	ppreduce

BattleScript_HitFromCritCalc:: @ 0x08286FB8
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
BattleScript_HitFromAtkAnimation::
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	seteffectwithchance
	tryfaintmon BS_TARGET

BattleScript_MoveEnd:: @ 0x08286FD6
	moveendall
	end

BattleScript_MakeMoveMissed::
	orbyte gMoveResultFlags, MOVE_RESULT_MISSED
BattleScript_PrintMoveMissed::
	attackstring
	ppreduce

BattleScript_MoveMissedPause:: @ 0x08286FE8
	pause B_WAIT_TIME_SHORT
BattleScript_MoveMissed::
	effectivenesssound
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSleep:: @ 0x08286FF5
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_AlreadyAsleep
	jumpifcantmakeasleep BattleScript_CantMakeAsleep
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_SLEEP
	seteffectprimary
	goto BattleScript_MoveEnd

BattleScript_AlreadyAsleep::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYASLEEP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_WasntAffected::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNWASNTAFFECTED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_CantMakeAsleep::
	pause B_WAIT_TIME_SHORT
	printfromtable gUproarAwakeStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPoisonHit:: @ 0x08287067
	setmoveeffect MOVE_EFFECT_POISON
	goto BattleScript_EffectHit

BattleScript_EffectAbsorb:: @ 0x08287072
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	negativedamage
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	jumpifability BS_TARGET, ABILITY_LIQUID_OOZE, BattleScript_AbsorbLiquidOoze
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABSORB
	goto BattleScript_AbsorbUpdateHp
BattleScript_AbsorbLiquidOoze::
	manipulatedamage DMG_CHANGE_SIGN
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABSORB_OOZE
BattleScript_AbsorbUpdateHp::
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	jumpifmovehadnoeffect BattleScript_AbsorbTryFainting
	printfromtable gAbsorbDrainStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AbsorbTryFainting::
	tryfaintmon BS_ATTACKER
	tryfaintmon BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_EffectBurnHit:: @ 0x082870E0
	setmoveeffect MOVE_EFFECT_BURN
	goto BattleScript_EffectHit

BattleScript_EffectFreezeHit:: @ 0x082870EB
	setmoveeffect MOVE_EFFECT_FREEZE
	goto BattleScript_EffectHit

BattleScript_EffectParalyzeHit:: @ 0x082870F6
	setmoveeffect MOVE_EFFECT_PARALYSIS
	goto BattleScript_EffectHit

BattleScript_EffectExplosion:: @ 0x08287101
	attackcanceler
	attackstring
	ppreduce
	tryexplosion
	setatkhptozero
	waitstate
	jumpifbyte CMP_NO_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_MISSED, BattleScript_ExplosionDoAnimStartLoop
	call BattleScript_PreserveMissedBitDoMoveAnim
	goto BattleScript_ExplosionLoop
BattleScript_ExplosionDoAnimStartLoop::
	attackanimation
	waitanimation
BattleScript_ExplosionLoop::
	movevaluescleanup
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
	accuracycheck BattleScript_ExplosionMissed, ACC_CURR_MOVE
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_ExplosionLoop
	tryfaintmon BS_ATTACKER
	end
BattleScript_ExplosionMissed::
	effectivenesssound
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_ExplosionLoop
	tryfaintmon BS_ATTACKER
	end

BattleScript_PreserveMissedBitDoMoveAnim::
	bicbyte gMoveResultFlags, MOVE_RESULT_MISSED
	attackanimation
	waitanimation
	orbyte gMoveResultFlags, MOVE_RESULT_MISSED
	return

BattleScript_EffectDreamEater:: @ 0x08287181
	attackcanceler
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_DreamEaterNoEffect
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_DreamEaterWorked
BattleScript_DreamEaterNoEffect::
	attackstring
	ppreduce
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_WasntAffected
BattleScript_DreamEaterWorked::
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	negativedamage
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	jumpifmovehadnoeffect BattleScript_DreamEaterTryFaintEnd
	printstring STRINGID_PKMNDREAMEATEN
	waitmessage B_WAIT_TIME_LONG
BattleScript_DreamEaterTryFaintEnd::
	tryfaintmon BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_EffectMirrorMove:: @ 0x082871EA
	attackcanceler
	attackstring
	pause B_WAIT_TIME_LONG
	trymirrormove
	ppreduce
	orbyte gMoveResultFlags, MOVE_RESULT_FAILED
	printstring STRINGID_MIRRORMOVEFAILED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAttackUp:: @ 0x08287202
	setstatchanger STAT_ATK, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectDefenseUp:: @ 0x0828720D
	setstatchanger STAT_DEF, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialAttackUp:: @ 0x08287218
	setstatchanger STAT_SPATK, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectEvasionUp:: @ 0x08287223
	setstatchanger STAT_EVASION, 1, FALSE
BattleScript_EffectStatUp::
	attackcanceler
BattleScript_EffectStatUpAfterAtkCanceler::
	attackstring
	ppreduce
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_StatUpEnd
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_StatUpAttackAnim
	pause B_WAIT_TIME_SHORT
	goto BattleScript_StatUpPrintString
BattleScript_StatUpAttackAnim::
	attackanimation
	waitanimation
BattleScript_StatUpDoAnim::
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_StatUpPrintString::
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_StatUpEnd::
	goto BattleScript_MoveEnd

BattleScript_StatUp:: @ 0x0828725C
	playanimation BS_EFFECT_BATTLER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectAttackDown:: @ 0x0828726C
	setstatchanger STAT_ATK, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectDefenseDown:: @ 0x08287277
	setstatchanger STAT_DEF, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpeedDown:: @ 0x08287282
	setstatchanger STAT_SPEED, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectAccuracyDown:: @ 0x0828728D
	setstatchanger STAT_ACC, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectEvasionDown:: @ 0x08287298
	setstatchanger STAT_EVASION, 1, TRUE
BattleScript_EffectStatDown::
	attackcanceler
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_StatDownEnd
	jumpifbyte CMP_LESS_THAN, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_StatDownDoAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_StatDownEnd
	pause B_WAIT_TIME_SHORT
	goto BattleScript_StatDownPrintString
BattleScript_StatDownDoAnim::
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_StatDownPrintString::
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_StatDownEnd::
	goto BattleScript_MoveEnd

BattleScript_StatDown:: @ 0x082872ED
	playanimation BS_EFFECT_BATTLER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectHaze:: @ 0x082872FD
	attackcanceler
	attackstring
	ppreduce
	attackanimation
	waitanimation
	normalisebuffs
	printstring STRINGID_STATCHANGESGONE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectBide:: @ 0x0828730E
	attackcanceler
	attackstring
	ppreduce
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_CHARGING
	setbide
	goto BattleScript_MoveEnd

BattleScript_EffectRampage:: @ 0x08287322
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_EffectRampage2
	ppreduce
BattleScript_EffectRampage2::
	confuseifrepeatingattackends
	goto BattleScript_HitFromCritCalc

BattleScript_EffectRoar:: @ 0x0828733C
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_SUCTION_CUPS, BattleScript_AbilityPreventsPhasingOut
	jumpifstatus3 BS_TARGET, STATUS3_ROOTED, BattleScript_PrintMonIsRooted
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_ButItFailed
	forcerandomswitch BattleScript_ButItFailed

BattleScript_EffectMultiHit:: @ 0x08287372
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setmultihitcounter 0
	initmultihitstring
	setbyte sMULTIHIT_EFFECT, 0
BattleScript_MultiHitLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_MultiHitEnd
	jumpifhasnohp BS_TARGET, BattleScript_MultiHitPrintStrings
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoMultiHit
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_MultiHitPrintStrings
BattleScript_DoMultiHit::
	movevaluescleanup
	copybyte cEFFECT_CHOOSER, sMULTIHIT_EFFECT
	critcalc
	damagecalc
	typecalc
	jumpifmovehadnoeffect BattleScript_MultiHitNoMoreHits
	adjustnormaldamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	addbyte sMULTIHIT_STRING + 4, 1
	moveendto MOVEEND_NEXT_TARGET
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_FOE_ENDURED, BattleScript_MultiHitPrintStrings
	decrementmultihit BattleScript_MultiHitLoop
	goto BattleScript_MultiHitPrintStrings
BattleScript_MultiHitNoMoreHits::
	pause B_WAIT_TIME_SHORT
BattleScript_MultiHitPrintStrings::
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifmovehadnoeffect BattleScript_MultiHitEnd
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	printstring STRINGID_HITXTIMES
	waitmessage B_WAIT_TIME_LONG
BattleScript_MultiHitEnd::
	seteffectwithchance
	tryfaintmon BS_TARGET
	moveendcase MOVEEND_SYNCHRONIZE_TARGET
	moveendfrom MOVEEND_IMMUNITY_ABILITIES
	end

BattleScript_EffectConversion:: @ 0x08287436
	attackcanceler
	attackstring
	ppreduce
	tryconversiontypechange BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFlinchHit:: @ 0x0828744B
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_EffectHit

BattleScript_EffectRestoreHp:: @ 0x08287456
	attackcanceler
	attackstring
	ppreduce
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_ATTACKER
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectToxic:: @ 0x08287479
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_IMMUNITY, BattleScript_ImmunityProtected
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_POISON, BattleScript_AlreadyPoisoned
	jumpifstatus BS_TARGET, STATUS1_TOXIC_POISON, BattleScript_AlreadyPoisoned
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	jumpiftype BS_TARGET, TYPE_POISON, BattleScript_NotAffected
	jumpiftype BS_TARGET, TYPE_STEEL, BattleScript_NotAffected
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_TOXIC
	seteffectprimary
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AlreadyPoisoned:: @ 0x082874DA
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_LONG
	printstring STRINGID_PKMNALREADYPOISONED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_ImmunityProtected:: @ 0x082874EB
	copybyte gEffectBattler, gBattlerTarget
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABILITY_PREVENTS_MOVE_STATUS
	call BattleScript_PSNPrevention
	goto BattleScript_MoveEnd

BattleScript_EffectPayDay:: @ 0x08287505
	setmoveeffect MOVE_EFFECT_PAYDAY
	goto BattleScript_EffectHit

BattleScript_EffectLightScreen:: @ 0x08287510
	attackcanceler
	attackstring
	ppreduce
	setlightscreen
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectTriAttack:: @ 0x08287519
	setmoveeffect MOVE_EFFECT_TRI_ATTACK
	goto BattleScript_EffectHit

BattleScript_EffectRest:: @ 0x08287524
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_RestIsAlreadyAsleep
	jumpifcantmakeasleep BattleScript_RestCantSleep
	trysetrest BattleScript_AlreadyAtFullHp
	pause B_WAIT_TIME_SHORT
	printfromtable gRestUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	waitstate
	goto BattleScript_PresentHealTarget

BattleScript_RestCantSleep:: @ 0x0828754E
	pause B_WAIT_TIME_LONG
	printfromtable gUproarAwakeStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_RestIsAlreadyAsleep:: @ 0x0828755E
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYASLEEP2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectOHKO:: @ 0x0828756F
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	typecalc
	jumpifmovehadnoeffect BattleScript_HitFromAtkAnimation
	tryKO BattleScript_KOFail
	trysetdestinybondtohappen
	goto BattleScript_HitFromAtkAnimation

BattleScript_KOFail:: @ 0x08287590
	pause B_WAIT_TIME_LONG
	printfromtable gKOFailedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRazorWind:: @ 0x082875A0
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_TwoTurnMovesSecondTurn
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING, BattleScript_TwoTurnMovesSecondTurn
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_RAZOR_WIND
	call BattleScriptFirstChargingTurn
	goto BattleScript_MoveEnd

BattleScript_TwoTurnMovesSecondTurn:: @ 0x082875C8
	attackcanceler
	setmoveeffect MOVE_EFFECT_CHARGING
	setbyte sB_ANIM_TURN, 1
	clearstatusfromeffect BS_ATTACKER
	orword gHitMarker, HITMARKER_NO_PPDEDUCT
	jumpifnotmove MOVE_SKY_ATTACK, BattleScript_HitFromAccCheck
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_HitFromAccCheck

BattleScriptFirstChargingTurn:: @ 0x082875F7
	attackcanceler
	printstring STRINGID_EMPTYSTRING3
	ppreduce
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_CHARGING
	setmoveeffect MOVE_EFFECT_CHARGING | MOVE_EFFECT_AFFECTS_USER
	seteffectprimary
	copybyte cMULTISTRING_CHOOSER, sTWOTURN_STRINGID
	printfromtable gFirstTurnOfTwoStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectSuperFang:: @ 0x08287621
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bicbyte gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	damagetohalftargethp
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectDragonRage:: @ 0x08287638
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bicbyte gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	setword gBattleMoveDamage, 40
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectTrap:: @ 0x08287667
	jumpifnotmove MOVE_WHIRLPOOL, BattleScript_DoWrapEffect
	jumpifnostatus3 BS_TARGET, STATUS3_UNDERWATER, BattleScript_DoWrapEffect
	orword gHitMarker, HITMARKER_IGNORE_UNDERWATER
	setbyte sDMG_MULTIPLIER, 2
BattleScript_DoWrapEffect:: @ 0x0828768D
	setmoveeffect MOVE_EFFECT_WRAP
	goto BattleScript_EffectHit

BattleScript_EffectDoubleHit:: @ 0x08287698
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setmultihitcounter 2
	initmultihitstring
	setbyte sMULTIHIT_EFFECT, 0
	goto BattleScript_MultiHitLoop

BattleScript_EffectRecoilIfMiss:: @ 0x082876B0
	attackcanceler
	accuracycheck BattleScript_MoveMissedDoDamage, ACC_CURR_MOVE
	goto BattleScript_HitFromAtkString
BattleScript_MoveMissedDoDamage:: @ 0x082876BC
	attackstring
	ppreduce
	pause B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE, BattleScript_MoveEnd
	printstring STRINGID_PKMNCRASHED
	waitmessage B_WAIT_TIME_LONG
	damagecalc
	typecalc
	adjustnormaldamage
	manipulatedamage DMG_RECOIL_FROM_MISS
	bicbyte gMoveResultFlags, MOVE_RESULT_MISSED
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER
	orbyte gMoveResultFlags, MOVE_RESULT_MISSED
	goto BattleScript_MoveEnd

BattleScript_EffectMist:: @ 0x08287701
	attackcanceler
	attackstring
	ppreduce
	setmist
	attackanimation
	waitanimation
	printfromtable gMistUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFocusEnergy:: @ 0x08287714
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_ATTACKER, STATUS2_FOCUS_ENERGY, BattleScript_ButItFailed
	setfocusenergy
	attackanimation
	waitanimation
	printfromtable gFocusEnergyUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRecoil:: @ 0x08287731
	setmoveeffect MOVE_EFFECT_RECOIL_25 | MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN
	jumpifnotmove MOVE_STRUGGLE, BattleScript_EffectHit
	incrementgamestat GAME_STAT_USED_STRUGGLE
	goto BattleScript_EffectHit

BattleScript_EffectConfuse:: @ 0x0828774A
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_OwnTempoPrevents
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	jumpifstatus2 BS_TARGET, STATUS2_CONFUSION, BattleScript_AlreadyConfused
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_CONFUSION
	seteffectprimary
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AlreadyConfused:: @ 0x08287789
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYCONFUSED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAttackUp2:: @ 0x0828779A
	setstatchanger STAT_ATK, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectDefenseUp2:: @ 0x082877A5
	setstatchanger STAT_DEF, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpeedUp2:: @ 0x082877B0
	setstatchanger STAT_SPEED, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialAttackUp2:: @ 0x082877BB
	setstatchanger STAT_SPATK, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialDefenseUp2:: @ 0x082877C6
	setstatchanger STAT_SPDEF, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectTransform:: @ 0x082877D1
	attackcanceler
	attackstring
	ppreduce
	transformdataexecution
	attackanimation
	waitanimation
	printfromtable gTransformUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAttackDown2:: @ 0x082877E4
	setstatchanger STAT_ATK, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectDefenseDown2:: @ 0x082877EF
	setstatchanger STAT_DEF, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpeedDown2:: @ 0x082877FA
	setstatchanger STAT_SPEED, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpecialDefenseDown2:: @ 0x08287805
	setstatchanger STAT_SPDEF, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectReflect:: @ 0x08287810
	attackcanceler
	attackstring
	ppreduce
	setreflect

BattleScript_PrintReflectLightScreenSafeguardString:: @ 0x08287814
	attackanimation
	waitanimation
	printfromtable gReflectLightScreenSafeguardStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPoison:: @ 0x08287823
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_IMMUNITY, BattleScript_ImmunityProtected
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_POISON, BattleScript_AlreadyPoisoned
	jumpifstatus BS_TARGET, STATUS1_TOXIC_POISON, BattleScript_AlreadyPoisoned
	jumpiftype BS_TARGET, TYPE_POISON, BattleScript_NotAffected
	jumpiftype BS_TARGET, TYPE_STEEL, BattleScript_NotAffected
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_POISON
	seteffectprimary
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectParalyze:: @ 0x08287884
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_LIMBER, BattleScript_LimberProtected
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	typecalc
	jumpifmovehadnoeffect BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_PARALYSIS, BattleScript_AlreadyParalyzed
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_PARALYSIS
	seteffectprimary
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AlreadyParalyzed:: @ 0x082878D9
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNISALREADYPARALYZED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_LimberProtected:: @ 0x082878EA
	copybyte gEffectBattler, gBattlerTarget
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABILITY_PREVENTS_MOVE_STATUS
	call BattleScript_PRLZPrevention
	goto BattleScript_MoveEnd

BattleScript_EffectAttackDownHit:: @ 0x08287904
	setmoveeffect MOVE_EFFECT_ATK_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectDefenseDownHit:: @ 0x0828790F
	setmoveeffect MOVE_EFFECT_DEF_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectSpeedDownHit:: @ 0x0828791A
	setmoveeffect MOVE_EFFECT_SPD_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectSpecialAttackDownHit:: @ 0x08287925
	setmoveeffect MOVE_EFFECT_SP_ATK_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectSpecialDefenseDownHit:: @ 0x08287930
	setmoveeffect MOVE_EFFECT_SP_DEF_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectAccuracyDownHit:: @ 0x0828793B
	setmoveeffect MOVE_EFFECT_ACC_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectSkyAttack:: @ 0x08287946
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_TwoTurnMovesSecondTurn
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING, BattleScript_TwoTurnMovesSecondTurn
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_SKY_ATTACK
	call BattleScriptFirstChargingTurn
	goto BattleScript_MoveEnd

BattleScript_EffectConfuseHit:: @ 0x0828796E
	setmoveeffect MOVE_EFFECT_CONFUSION
	goto BattleScript_EffectHit

BattleScript_EffectTwineedle:: @ 0x08287979
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	setbyte sMULTIHIT_EFFECT, MOVE_EFFECT_POISON
	attackstring
	ppreduce
	setmultihitcounter 2
	initmultihitstring
	goto BattleScript_MultiHitLoop

BattleScript_EffectSubstitute:: @ 0x08287991
	attackcanceler
	ppreduce
	attackstring
	waitstate
	jumpifstatus2 BS_ATTACKER, STATUS2_SUBSTITUTE, BattleScript_AlreadyHasSubstitute
	setsubstitute
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_SUBSTITUTE_FAILED, BattleScript_SubstituteAnim
	pause B_WAIT_TIME_SHORT
	goto BattleScript_SubstituteString
BattleScript_SubstituteAnim:: @ 0x082879B3
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
BattleScript_SubstituteString:: @ 0x082879B9
	printfromtable gSubstituteUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_AlreadyHasSubstitute:: @ 0x082879C6
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNHASSUBSTITUTE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRecharge:: @ 0x082879D7
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	setmoveeffect MOVE_EFFECT_RECHARGE | MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN
	goto BattleScript_HitFromAtkString

BattleScript_MoveUsedMustRecharge:: @ 0x082879EA
	printstring STRINGID_PKMNMUSTRECHARGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRage:: @ 0x082879F5
	attackcanceler
	accuracycheck BattleScript_RageMiss, ACC_CURR_MOVE
	setmoveeffect MOVE_EFFECT_RAGE
	seteffectprimary
	setmoveeffect 0
	goto BattleScript_HitFromAtkString

BattleScript_RageMiss:: @ 0x08287A0F
	setmoveeffect MOVE_EFFECT_RAGE
	clearstatusfromeffect BS_ATTACKER
	goto BattleScript_PrintMoveMissed

BattleScript_EffectMimic:: @ 0x08287A1C
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	mimicattackcopy BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNLEARNEDMOVE2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMetronome:: @ 0x08287A42
	attackcanceler
	attackstring
	pause B_WAIT_TIME_SHORT
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	metronome

BattleScript_EffectLeechSeed:: @ 0x08287A56
	attackcanceler
	attackstring
	pause B_WAIT_TIME_SHORT
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	accuracycheck BattleScript_DoLeechSeed, ACC_CURR_MOVE

BattleScript_DoLeechSeed:: @ 0x08287A6D
	setseeded
	attackanimation
	waitanimation
	printfromtable gLeechSeedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSplash:: @ 0x08287A7D
	attackcanceler
	attackstring
	ppreduce
	attackanimation
	waitanimation
	incrementgamestat GAME_STAT_USED_SPLASH
	printstring STRINGID_BUTNOTHINGHAPPENED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectDisable:: @ 0x08287A8F
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	disablelastusedattack BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNMOVEWASDISABLED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectLevelDamage:: @ 0x08287AAB
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bicbyte gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	dmgtolevel
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectPsywave:: @ 0x08287AC3
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bicbyte gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	psywavedamageeffect
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectCounter:: @ 0x08287ADB
	attackcanceler
	counterdamagecalculator BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc2
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectEncore:: @ 0x08287AF1
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	trysetencore BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNGOTENCORE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPainSplit:: @ 0x08287B0D
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	painsplitdmgcalc BattleScript_ButItFailed
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	copyword gBattleMoveDamage, sPAINSPLIT_HP
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_SHAREDPAIN
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSnore:: @ 0x08287B44
	attackcanceler
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_SnoreIsAsleep
	attackstring
	ppreduce
	goto BattleScript_ButItFailed

BattleScript_SnoreIsAsleep:: @ 0x08287B56
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoSnore
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER

BattleScript_DoSnore:: @ 0x08287B6A
	attackstring
	ppreduce
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_HitFromCritCalc

BattleScript_EffectConversion2:: @ 0x08287B7E
	attackcanceler
	attackstring
	ppreduce
	settypetorandomresistance BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectLockOn:: @ 0x08287B93
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	setalwayshitflag
	attackanimation
	waitanimation
	printstring STRINGID_PKMNTOOKAIM
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSketch:: @ 0x08287BB5
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	copymovepermanently BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSKETCHEDMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSleepTalk:: @ 0x08287BD4
	attackcanceler
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_SleepTalkIsAsleep
	attackstring
	ppreduce
	goto BattleScript_ButItFailed

BattleScript_SleepTalkIsAsleep:: @ 0x08287BE6
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
	attackstring
	ppreduce
	orword gHitMarker, HITMARKER_NO_PPDEDUCT
	trychoosesleeptalkmove BattleScript_SleepTalkUsingMove
	pause B_WAIT_TIME_LONG
	goto BattleScript_ButItFailed

BattleScript_SleepTalkUsingMove:: @ 0x08287C06
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	jumptocalledmove TRUE

BattleScript_EffectDestinyBond:: @ 0x08287C16
	attackcanceler
	attackstring
	ppreduce
	setdestinybond
	attackanimation
	waitanimation
	printstring STRINGID_PKMNTRYINGTOTAKEFOE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFlail:: @ 0x08287C27
	remaininghptopower
	goto BattleScript_EffectHit

BattleScript_EffectSpite:: @ 0x08287C2D
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	tryspiteppreduce BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNREDUCEDPP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHealBell:: @ 0x08287C49
	attackcanceler
	attackstring
	ppreduce
	healpartystatus
	waitstate
	attackanimation
	waitanimation
	printfromtable gPartyStatusHealStringIds
	waitmessage B_WAIT_TIME_LONG
	jumpifnotmove MOVE_HEAL_BELL, BattleScript_PartyHealEnd
	jumpifbyte CMP_NO_COMMON_BITS, cMULTISTRING_CHOOSER, B_MSG_BELL_SOUNDPROOF_ATTACKER, BattleScript_CheckHealBellMon2Unaffected
	printstring STRINGID_PKMNSXBLOCKSY
	waitmessage B_WAIT_TIME_LONG
BattleScript_CheckHealBellMon2Unaffected:
	jumpifbyte CMP_NO_COMMON_BITS, cMULTISTRING_CHOOSER, B_MSG_BELL_SOUNDPROOF_PARTNER, BattleScript_PartyHealEnd
	printstring STRINGID_PKMNSXBLOCKSY2
	waitmessage B_WAIT_TIME_LONG
BattleScript_PartyHealEnd:
	updatestatusicon BS_ATTACKER_WITH_PARTNER
	waitstate
	goto BattleScript_MoveEnd

BattleScript_EffectTripleKick:: @ 0x08287C8E
	attackcanceler
	attackstring
	ppreduce
	sethword sTRIPLE_KICK_POWER, 0
	initmultihitstring
	setmultihit 3
BattleScript_TripleKickLoop:
	jumpifhasnohp BS_ATTACKER, BattleScript_TripleKickEnd
	jumpifhasnohp BS_TARGET, BattleScript_TripleKickNoMoreHits
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoTripleKickAttack
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_TripleKickNoMoreHits
BattleScript_DoTripleKickAttack:
	accuracycheck BattleScript_TripleKickNoMoreHits, ACC_CURR_MOVE
	movevaluescleanup
	addbyte sTRIPLE_KICK_POWER, 10
	addbyte sMULTIHIT_STRING + 4, 1
	copyhword gDynamicBasePower, sTRIPLE_KICK_POWER
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
	jumpifmovehadnoeffect BattleScript_TripleKickNoMoreHits
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	moveendto MOVEEND_NEXT_TARGET
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_FOE_ENDURED, BattleScript_TripleKickPrintStrings
	decrementmultihit BattleScript_TripleKickLoop
	goto BattleScript_TripleKickPrintStrings
BattleScript_TripleKickNoMoreHits:
	pause B_WAIT_TIME_SHORT
	jumpifbyte CMP_EQUAL, sMULTIHIT_STRING + 4, 0, BattleScript_TripleKickPrintStrings
	bicbyte gMoveResultFlags, MOVE_RESULT_MISSED
BattleScript_TripleKickPrintStrings:
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifbyte CMP_EQUAL, sMULTIHIT_STRING + 4, 0, BattleScript_TripleKickEnd
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE, BattleScript_TripleKickEnd
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	printstring STRINGID_HITXTIMES
	waitmessage B_WAIT_TIME_LONG
BattleScript_TripleKickEnd:
	seteffectwithchance
	tryfaintmon BS_TARGET
	moveendfrom MOVEEND_UPDATE_LAST_MOVES
	end

BattleScript_EffectThief:: @ 0x08287D71
	setmoveeffect MOVE_EFFECT_STEAL_ITEM
	goto BattleScript_EffectHit

BattleScript_EffectMeanLook:: @ 0x08287D7C
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC
	jumpifstatus2 BS_TARGET, STATUS2_ESCAPE_PREVENTION, BattleScript_ButItFailed
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_PREVENT_ESCAPE
	seteffectprimary
	printstring STRINGID_TARGETCANTESCAPENOW
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectNightmare:: @ 0x08287DAE
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	jumpifstatus2 BS_TARGET, STATUS2_NIGHTMARE, BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_NightmareWorked
	goto BattleScript_ButItFailed
BattleScript_NightmareWorked:
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_NIGHTMARE
	seteffectprimary
	printstring STRINGID_PKMNFELLINTONIGHTMARE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMinimize:: @ 0x08287DE8
	attackcanceler
	setminimize
	setstatchanger STAT_EVASION, 1, FALSE
	goto BattleScript_EffectStatUpAfterAtkCanceler

BattleScript_EffectCurse:: @ 0x08287DF5
	jumpiftype2 BS_ATTACKER, TYPE_GHOST, BattleScript_GhostCurse
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_GREATER_THAN, STAT_SPEED, MIN_STAT_STAGE, BattleScript_CurseTrySpeed
	jumpifstat BS_ATTACKER, CMP_NOT_EQUAL, STAT_ATK, MAX_STAT_STAGE, BattleScript_CurseTrySpeed
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_DEF, MAX_STAT_STAGE, BattleScript_ButItFailed
BattleScript_CurseTrySpeed:
	copybyte gBattlerTarget, gBattlerAttacker
	setbyte sB_ANIM_TURN, 1
	attackanimation
	waitanimation
	setstatchanger STAT_SPEED, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CurseTryAttack
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CurseTryAttack:
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CurseTryDefense
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CurseTryDefense:
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CurseEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CurseEnd:
	goto BattleScript_MoveEnd
BattleScript_GhostCurse:
	jumpifbytenotequal gBattlerAttacker, gBattlerTarget, BattleScript_DoGhostCurse
	getmovetarget BS_ATTACKER
BattleScript_DoGhostCurse:
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	cursetarget BattleScript_ButItFailed
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	setbyte sB_ANIM_TURN, 0
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNLAIDCURSE
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectProtect:: @ 0x08287EBE
BattleScript_EffectEndure:: @ 0x08287EBE
	attackcanceler
	attackstring
	ppreduce
	setprotectlike
	attackanimation
	waitanimation
	printfromtable gProtectLikeUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSpikes:: @ 0x08287ED1
	attackcanceler
	trysetspikes BattleScript_FailedFromAtkString
	attackstring
	ppreduce
	attackanimation
	waitanimation
	printstring STRINGID_SPIKESSCATTERED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectForesight:: @ 0x08287EE6
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setforesight
	attackanimation
	waitanimation
	printstring STRINGID_PKMNIDENTIFIED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPerishSong:: @ 0x08287EFE
	attackcanceler
	attackstring
	ppreduce
	trysetperishsong BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_FAINTINTHREE
	waitmessage B_WAIT_TIME_LONG
	setbyte sBATTLER, 0
BattleScript_PerishSongLoop:
	jumpifability BS_SCRIPTING, ABILITY_SOUNDPROOF, BattleScript_PerishSongNotAffected
BattleScript_PerishSongLoopIncrement:
	addbyte sBATTLER, 1
	jumpifbytenotequal sBATTLER, gBattlersCount, BattleScript_PerishSongLoop
	goto BattleScript_MoveEnd

BattleScript_PerishSongNotAffected:
	printstring STRINGID_PKMNSXBLOCKSY2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_PerishSongLoopIncrement

BattleScript_EffectSandstorm:: @ 0x08287F3F
	attackcanceler
	attackstring
	ppreduce
	setsandstorm
	goto BattleScript_MoveWeatherChange

BattleScript_EffectRollout:: @ 0x08287F48
	attackcanceler
	attackstring
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_RolloutCheckAccuracy
	ppreduce
BattleScript_RolloutCheckAccuracy:
	accuracycheck BattleScript_RolloutHit, ACC_CURR_MOVE
BattleScript_RolloutHit:
	typecalc2
	rolloutdamagecalculation
	goto BattleScript_HitFromCritCalc

BattleScript_EffectSwagger:: @ 0x08287F63
	attackcanceler
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_MakeMoveMissed
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifconfusedandstatmaxed STAT_ATK, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setstatchanger STAT_ATK, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_SwaggerTryConfuse
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_SwaggerTryConfuse
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_SwaggerTryConfuse:
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_OwnTempoPrevents
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	setmoveeffect MOVE_EFFECT_CONFUSION
	seteffectprimary
	goto BattleScript_MoveEnd

BattleScript_EffectFuryCutter:: @ 0x08287FC1
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_FuryCutterHit, ACC_CURR_MOVE
BattleScript_FuryCutterHit:
	furycuttercalc
	critcalc
	damagecalc
	typecalc
	jumpifmovehadnoeffect BattleScript_FuryCutterHit
	adjustnormaldamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectAttract:: @ 0x08287FE0
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	tryinfatuating BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFELLINLOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectReturn:: @ 0x08287FFC
BattleScript_EffectFrustration:: @ 0x08287FFC
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	friendshiptodamagecalculation
	goto BattleScript_HitFromAtkString

BattleScript_EffectPresent:: @ 0x0828800A
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	presentdamagecalculation

BattleScript_EffectSafeguard:: @ 0x08288016
	attackcanceler
	attackstring
	ppreduce
	setsafeguard
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectThawHit:: @ 0x0828801F
	setmoveeffect MOVE_EFFECT_BURN
	goto BattleScript_EffectHit

BattleScript_EffectMagnitude:: @ 0x0828802A
	attackcanceler
	attackstring
	ppreduce
	selectfirstvalidtarget
	magnitudedamagecalculation
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_MAGNITUDESTRENGTH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_HitsAllWithUndergroundBonusLoop

BattleScript_EffectBatonPass:: @ 0x0828803D
	attackcanceler
	attackstring
	ppreduce
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_ButItFailed
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_ButItFailed
	attackanimation
	waitanimation
	openpartyscreen BS_ATTACKER, BattleScript_ButItFailed
	switchoutabilities BS_ATTACKER
	waitstate
	switchhandleorder BS_ATTACKER, 2
	returntoball BS_ATTACKER
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	printstring STRINGID_SWITCHINMON
	switchinanim BS_ATTACKER, TRUE
	waitstate
	switchineffects BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectRapidSpin:: @ 0x08288078
	setmoveeffect MOVE_EFFECT_RAPIDSPIN | MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectSonicboom:: @ 0x08288083
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bicbyte gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	setword gBattleMoveDamage, 20
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectMorningSun:: @ 0x082880B2
BattleScript_EffectSynthesis:: @ 0x082880B2
BattleScript_EffectMoonlight:: @ 0x082880B2
	attackcanceler
	attackstring
	ppreduce
	recoverbasedonsunlight BattleScript_AlreadyAtFullHp
	goto BattleScript_PresentHealTarget

BattleScript_EffectHiddenPower:: @ 0x082880BF
	hiddenpowercalc
	goto BattleScript_EffectHit

BattleScript_EffectRainDance:: @ 0x082880C5
	attackcanceler
	attackstring
	ppreduce
	setrain

BattleScript_MoveWeatherChange:: @ 0x082880C9
	attackanimation
	waitanimation
	printfromtable gMoveWeatherChangeStringIds
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_WeatherFormChanges
	goto BattleScript_MoveEnd

BattleScript_EffectSunnyDay:: @ 0x082880DD
	attackcanceler
	attackstring
	ppreduce
	setsunny
	goto BattleScript_MoveWeatherChange

BattleScript_EffectDefenseUpHit:: @ 0x082880E6
	setmoveeffect MOVE_EFFECT_DEF_PLUS_1 | MOVE_EFFECT_AFFECTS_USER
	goto BattleScript_EffectHit

BattleScript_EffectAttackUpHit:: @ 0x082880F1
	setmoveeffect MOVE_EFFECT_ATK_PLUS_1 | MOVE_EFFECT_AFFECTS_USER
	goto BattleScript_EffectHit

BattleScript_EffectAllStatsUpHit:: @ 0x082880FC
	setmoveeffect MOVE_EFFECT_ALL_STATS_UP | MOVE_EFFECT_AFFECTS_USER
	goto BattleScript_EffectHit

BattleScript_EffectBellyDrum:: @ 0x08288107
	attackcanceler
	attackstring
	ppreduce
	maxattackhalvehp BattleScript_ButItFailed
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNCUTHPMAXEDATTACK
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPsychUp:: @ 0x08288129
	attackcanceler
	attackstring
	ppreduce
	copyfoestats BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCOPIEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMirrorCoat:: @ 0x0828813E
	attackcanceler
	mirrorcoatdamagecalculator BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc2
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectSkullBash:: @ 0x08288154
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_TwoTurnMovesSecondTurn
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING, BattleScript_TwoTurnMovesSecondTurn
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_SKULL_BASH
	call BattleScriptFirstChargingTurn
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_SkullBashEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_SkullBashEnd
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_SkullBashEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectTwister:: @ 0x082881A3
	jumpifnostatus3 BS_TARGET, STATUS3_ON_AIR, BattleScript_FlinchEffect
	orword gHitMarker, HITMARKER_IGNORE_ON_AIR
	setbyte sDMG_MULTIPLIER, 2
BattleScript_FlinchEffect:: @ 0x082881BD
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_EffectHit

BattleScript_EffectEarthquake:: @ 0x082881C8
	attackcanceler
	attackstring
	ppreduce
	selectfirstvalidtarget

BattleScript_HitsAllWithUndergroundBonusLoop:: @ 0x082881CC
	movevaluescleanup
	jumpifnostatus3 BS_TARGET, STATUS3_UNDERGROUND, BattleScript_HitsAllNoUndergroundBonus
	orword gHitMarker, HITMARKER_IGNORE_UNDERGROUND
	setbyte sDMG_MULTIPLIER, 2
	goto BattleScript_DoHitAllWithUndergroundBonus
BattleScript_HitsAllNoUndergroundBonus::
	bicword gHitMarker, HITMARKER_IGNORE_UNDERGROUND
	setbyte sDMG_MULTIPLIER, 1
BattleScript_DoHitAllWithUndergroundBonus::
	accuracycheck BattleScript_HitAllWithUndergroundBonusMissed, ACC_CURR_MOVE
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	tryfaintmon BS_TARGET
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_HitsAllWithUndergroundBonusLoop
	end
BattleScript_HitAllWithUndergroundBonusMissed::
	pause B_WAIT_TIME_SHORT
	typecalc
	effectivenesssound
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_HitsAllWithUndergroundBonusLoop
	end

BattleScript_EffectFutureSight:: @ 0x0828824C
	attackcanceler
	attackstring
	ppreduce
	trysetfutureattack BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gFutureMoveUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectGust:: @ 0x08288263
	jumpifnostatus3 BS_TARGET, STATUS3_ON_AIR, BattleScript_EffectHit
	orword gHitMarker, HITMARKER_IGNORE_ON_AIR
	setbyte sDMG_MULTIPLIER, 2
	goto BattleScript_EffectHit

BattleScript_EffectStomp:: @ 0x08288282
	jumpifnostatus3 BS_TARGET, STATUS3_MINIMIZED, BattleScript_FlinchEffect
	setbyte sDMG_MULTIPLIER, 2
	goto BattleScript_FlinchEffect

BattleScript_EffectSolarBeam:: @ 0x08288298
	jumpifabilitypresent ABILITY_CLOUD_NINE, BattleScript_SolarBeamDecideTurn
	jumpifabilitypresent ABILITY_AIR_LOCK, BattleScript_SolarBeamDecideTurn
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, B_WEATHER_SUN, BattleScript_SolarBeamOnFirstTurn
BattleScript_SolarBeamDecideTurn::
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_TwoTurnMovesSecondTurn
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING, BattleScript_TwoTurnMovesSecondTurn
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_SOLAR_BEAM
	call BattleScriptFirstChargingTurn
	goto BattleScript_MoveEnd
BattleScript_SolarBeamOnFirstTurn::
	orword gHitMarker, HITMARKER_CHARGING
	setmoveeffect MOVE_EFFECT_CHARGING | MOVE_EFFECT_AFFECTS_USER
	seteffectprimary
	ppreduce
	goto BattleScript_TwoTurnMovesSecondTurn

BattleScript_EffectThunder:: @ 0x082882EE
	setmoveeffect MOVE_EFFECT_PARALYSIS
	orword gHitMarker, HITMARKER_IGNORE_ON_AIR
	goto BattleScript_EffectHit

BattleScript_EffectTeleport:: @ 0x08288302
	attackcanceler
	attackstring
	ppreduce
	jumpifbattletype BATTLE_TYPE_TRAINER, BattleScript_ButItFailed
	getifcantrunfrombattle BS_ATTACKER
	jumpifbyte CMP_EQUAL, gBattleCommunication, BATTLE_RUN_FORBIDDEN, BattleScript_ButItFailed
	jumpifbyte CMP_EQUAL, gBattleCommunication, BATTLE_RUN_FAILURE, BattleScript_PrintAbilityMadeIneffective
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFLEDFROMBATTLE
	waitmessage B_WAIT_TIME_LONG
	setoutcomeonteleport BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectBeatUp:: @ 0x0828833C
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	pause B_WAIT_TIME_SHORT
	ppreduce
	setbyte gBattleCommunication, 0
BattleScript_BeatUpLoop::
	movevaluescleanup
	trydobeatup BattleScript_BeatUpEnd, BattleScript_ButItFailed
	printstring STRINGID_PKMNATTACK
	critcalc
	jumpifbyte CMP_NOT_EQUAL, gCritMultiplier, 2, BattleScript_BeatUpAttack
	manipulatedamage DMG_DOUBLED
BattleScript_BeatUpAttack::
	adjustnormaldamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET
	moveendto MOVEEND_NEXT_TARGET
	goto BattleScript_BeatUpLoop
BattleScript_BeatUpEnd::
	end

BattleScript_EffectSemiInvulnerable:: @ 0x08288393
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_SecondTurnSemiInvulnerable
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING, BattleScript_SecondTurnSemiInvulnerable
	jumpifmove MOVE_FLY, BattleScript_FirstTurnFly
	jumpifmove MOVE_DIVE, BattleScript_FirstTurnDive
	jumpifmove MOVE_BOUNCE, BattleScript_FirstTurnBounce
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_DIG
	goto BattleScript_FirstTurnSemiInvulnerable

BattleScript_FirstTurnBounce::
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_BOUNCE
	goto BattleScript_FirstTurnSemiInvulnerable

BattleScript_FirstTurnDive::
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_DIVE
	goto BattleScript_FirstTurnSemiInvulnerable

BattleScript_FirstTurnFly::
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_FLY
BattleScript_FirstTurnSemiInvulnerable::
	call BattleScriptFirstChargingTurn
	setsemiinvulnerablebit
	goto BattleScript_MoveEnd

BattleScript_SecondTurnSemiInvulnerable::
	attackcanceler
	setmoveeffect MOVE_EFFECT_CHARGING
	setbyte sB_ANIM_TURN, 1
	clearstatusfromeffect BS_ATTACKER
	orword gHitMarker, HITMARKER_NO_PPDEDUCT
	jumpifnotmove MOVE_BOUNCE, BattleScript_SemiInvulnerableTryHit
	setmoveeffect MOVE_EFFECT_PARALYSIS
BattleScript_SemiInvulnerableTryHit::
	accuracycheck BattleScript_SemiInvulnerableMiss, ACC_CURR_MOVE
	clearsemiinvulnerablebit
	goto BattleScript_HitFromAtkString

BattleScript_SemiInvulnerableMiss::
	clearsemiinvulnerablebit
	goto BattleScript_PrintMoveMissed

BattleScript_EffectDefenseCurl:: @ 0x0828843E
	attackcanceler
	attackstring
	ppreduce
	setdefensecurlbit
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_DefenseCurlDoStatUpAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_StatUpPrintString
	attackanimation
	waitanimation
BattleScript_DefenseCurlDoStatUpAnim::
	goto BattleScript_StatUpDoAnim

BattleScript_EffectSoftboiled:: @ 0x08288460
	attackcanceler
	attackstring
	ppreduce
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_TARGET

BattleScript_PresentHealTarget:: @ 0x08288469
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AlreadyAtFullHp:: @ 0x08288483
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNHPFULL
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFakeOut:: @ 0x08288491
	attackcanceler
	jumpifnotfirstturn BattleScript_FailedFromAtkString
	setmoveeffect MOVE_EFFECT_FLINCH | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_FailedFromAtkString:: @ 0x082884A2
	attackstring

BattleScript_FailedFromPPReduce:: @ 0x082884A3
	ppreduce

BattleScript_ButItFailed:: @ 0x082884A4
	pause B_WAIT_TIME_SHORT
	orbyte gMoveResultFlags, MOVE_RESULT_FAILED
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_NotAffected:: @ 0x082884B6
	pause B_WAIT_TIME_SHORT
	orbyte gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectUproar:: @ 0x082884C8
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	setmoveeffect MOVE_EFFECT_UPROAR | MOVE_EFFECT_AFFECTS_USER
	attackstring
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_UproarHit
	ppreduce
BattleScript_UproarHit::
	nop
	goto BattleScript_HitFromCritCalc

BattleScript_EffectStockpile:: @ 0x082884E8
	attackcanceler
	attackstring
	ppreduce
	stockpile
	attackanimation
	waitanimation
	printfromtable gStockpileUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSpitUp:: @ 0x082884FB
	attackcanceler
	jumpifbyte CMP_EQUAL, cMISS_TYPE, B_MSG_PROTECTED, BattleScript_SpitUpFailProtect
	attackstring
	ppreduce
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	stockpiletobasedamage BattleScript_SpitUpFail
	typecalc
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation
BattleScript_SpitUpFail::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_FAILEDTOSPITUP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SpitUpFailProtect::
	attackstring
	ppreduce
	pause B_WAIT_TIME_LONG
	stockpiletobasedamage BattleScript_SpitUpFail
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSwallow:: @ 0x0828853D
	attackcanceler
	attackstring
	ppreduce
	stockpiletohpheal BattleScript_SwallowFail
	goto BattleScript_PresentHealTarget

BattleScript_SwallowFail::
	pause B_WAIT_TIME_SHORT
	printfromtable gSwallowFailStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHail:: @ 0x0828855A
	attackcanceler
	attackstring
	ppreduce
	sethail
	goto BattleScript_MoveWeatherChange

BattleScript_EffectTorment:: @ 0x08288563
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	settorment BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSUBJECTEDTOTORMENT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFlatter:: @ 0x0828857F
	attackcanceler
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_MakeMoveMissed
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifconfusedandstatmaxed STAT_SPATK, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_FlatterTryConfuse
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_FlatterTryConfuse
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_FlatterTryConfuse::
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_OwnTempoPrevents
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	setmoveeffect MOVE_EFFECT_CONFUSION
	seteffectprimary
	goto BattleScript_MoveEnd

BattleScript_EffectWillOWisp:: @ 0x082885DD
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_BURN, BattleScript_AlreadyBurned
	jumpiftype BS_TARGET, TYPE_FIRE, BattleScript_NotAffected
	jumpifability BS_TARGET, ABILITY_WATER_VEIL, BattleScript_WaterVeilPrevents
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_BURN
	seteffectprimary
	goto BattleScript_MoveEnd

BattleScript_WaterVeilPrevents::
	copybyte gEffectBattler, gBattlerTarget
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABILITY_PREVENTS_MOVE_STATUS
	call BattleScript_BRNPrevention
	goto BattleScript_MoveEnd

BattleScript_AlreadyBurned::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYHASBURN
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMemento:: @ 0x08288654
	attackcanceler
	jumpifbyte CMP_EQUAL, cMISS_TYPE, B_MSG_PROTECTED, BattleScript_MementoTargetProtect
	attackstring
	ppreduce
	trymemento BattleScript_ButItFailed
	setatkhptozero
	attackanimation
	waitanimation
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_EffectMementoPrintNoEffect
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, STAT_CHANGE_NEGATIVE | STAT_CHANGE_BY_TWO | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_ATK, STAT_CHANGE_NEGATIVE | STAT_CHANGE_BY_TWO
	setstatchanger STAT_ATK, 2, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectMementoTrySpAtk
@ Greater than B_MSG_DEFENDER_STAT_FELL is checking if the stat cannot decrease.
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_FELL, BattleScript_EffectMementoTrySpAtk
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectMementoTrySpAtk:
	playstatchangeanimation BS_TARGET, BIT_SPATK, STAT_CHANGE_NEGATIVE | STAT_CHANGE_BY_TWO
	setstatchanger STAT_SPATK, 2, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectMementoTryFaint
@ Greater than B_MSG_DEFENDER_STAT_FELL is checking if the stat cannot decrease.
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_FELL, BattleScript_EffectMementoTryFaint
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectMementoTryFaint:
	tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd
BattleScript_EffectMementoPrintNoEffect:
	printstring STRINGID_BUTNOEFFECT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_EffectMementoTryFaint
@ If the target is protected, the user faints without checking target stats or animating.
BattleScript_MementoTargetProtect:
	attackstring
	ppreduce
	trymemento BattleScript_MementoTargetProtectEnd
BattleScript_MementoTargetProtectEnd:
	setatkhptozero
	pause B_WAIT_TIME_LONG
	effectivenesssound
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectFacade:: @ 0x082886F7
	jumpifstatus BS_ATTACKER, STATUS1_POISON | STATUS1_BURN | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON, BattleScript_FacadeDoubleDmg
	goto BattleScript_EffectHit

BattleScript_FacadeDoubleDmg:
	setbyte sDMG_MULTIPLIER, 2
	goto BattleScript_EffectHit

BattleScript_EffectFocusPunch:: @ 0x08288711
	attackcanceler
	jumpifnodamage BattleScript_HitFromAccCheck
	ppreduce
	printstring STRINGID_PKMNLOSTFOCUS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSmellingsalt:: @ 0x08288723
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_EffectHit
	setmoveeffect MOVE_EFFECT_REMOVE_PARALYSIS | MOVE_EFFECT_CERTAIN
	jumpifstatus BS_TARGET, STATUS1_PARALYSIS, BattleScript_SmellingsaltDoubleDmg
	goto BattleScript_EffectHit
BattleScript_SmellingsaltDoubleDmg:
	setbyte sDMG_MULTIPLIER, 2
	goto BattleScript_EffectHit

BattleScript_EffectFollowMe:: @ 0x0828874D
	attackcanceler
	attackstring
	ppreduce
	setforcedtarget
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCENTERATTENTION
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectNaturePower:: @ 0x0828875E
	attackcanceler
	attackstring
	pause B_WAIT_TIME_SHORT
	callenvironmentattack
	printstring STRINGID_NATUREPOWERTURNEDINTO
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectCharge:: @ 0x0828876B
	attackcanceler
	attackstring
	ppreduce
	setcharge
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHARGINGPOWER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTaunt:: @ 0x0828877C
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	settaunt BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFELLFORTAUNT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHelpingHand:: @ 0x08288798
	attackcanceler
	attackstring
	ppreduce
	trysethelpinghand BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNREADYTOHELP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTrick:: @ 0x082887AD
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	tryswapitems BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDITEMS
	waitmessage B_WAIT_TIME_LONG
	printfromtable gItemSwapStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRolePlay:: @ 0x082887DB
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	trycopyability BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCOPIEDFOE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectWish:: @ 0x082887F7
	attackcanceler
	attackstring
	ppreduce
	trywish 0, BattleScript_ButItFailed
	attackanimation
	waitanimation
	goto BattleScript_MoveEnd

BattleScript_EffectAssist:: @ 0x08288807
	attackcanceler
	attackstring
	assistattackselect BattleScript_FailedFromPPReduce
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	jumptocalledmove TRUE

BattleScript_EffectIngrain:: @ 0x0828881E
	attackcanceler
	attackstring
	ppreduce
	trysetroots BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNPLANTEDROOTS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSuperpower:: @ 0x08288833
	setmoveeffect MOVE_EFFECT_ATK_DEF_DOWN | MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectMagicCoat:: @ 0x0828883E
	attackcanceler
	trysetmagiccoat BattleScript_FailedFromAtkString
	attackstring
	ppreduce
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSHROUDEDITSELF
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRecycle:: @ 0x08288853
	attackcanceler
	attackstring
	ppreduce
	tryrecycleitem BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_XFOUNDONEY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRevenge:: @ 0x08288868
	doubledamagedealtifdamaged
	goto BattleScript_EffectHit

BattleScript_EffectBrickBreak:: @ 0x0828886E
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	removelightscreenreflect
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
	jumpifbyte CMP_EQUAL, sB_ANIM_TURN, 0, BattleScript_BrickBreakAnim
	bicbyte gMoveResultFlags, MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE
BattleScript_BrickBreakAnim:
	attackanimation
	waitanimation
	jumpifbyte CMP_LESS_THAN, sB_ANIM_TURN, 2, BattleScript_BrickBreakDoHit
	printstring STRINGID_THEWALLSHATTERED
	waitmessage B_WAIT_TIME_LONG
BattleScript_BrickBreakDoHit:
	typecalc2
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	seteffectwithchance
	tryfaintmon BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_EffectYawn:: @ 0x082888BF
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_VITAL_SPIRIT, BattleScript_PrintBankAbilityMadeIneffective
	jumpifability BS_TARGET, ABILITY_INSOMNIA, BattleScript_PrintBankAbilityMadeIneffective
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifcantmakeasleep BattleScript_ButItFailed
	setyawn BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNWASMADEDROWSY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_PrintBankAbilityMadeIneffective:: @ 0x08288900
	copybyte sBATTLER, sBATTLER_WITH_ABILITY
BattleScript_PrintAbilityMadeIneffective:: @ 0x0828890A
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNSXMADEITINEFFECTIVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectKnockOff:: @ 0x08288918
	setmoveeffect MOVE_EFFECT_KNOCK_OFF
	goto BattleScript_EffectHit

BattleScript_EffectEndeavor:: @ 0x08288923
	attackcanceler
	attackstring
	ppreduce
	setdamagetohealthdifference BattleScript_ButItFailed
	copyword gHpDealt, gBattleMoveDamage
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	typecalc
	jumpifmovehadnoeffect BattleScript_HitFromAtkAnimation
	bicbyte gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	copyword gBattleMoveDamage, gHpDealt
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectEruption:: @ 0x0828895E
	scaledamagebyhealthratio
	goto BattleScript_EffectHit

BattleScript_EffectSkillSwap:: @ 0x08288964
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	tryswapabilities BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWAPPEDABILITIES
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectImprison:: @ 0x08288980
	attackcanceler
	attackstring
	ppreduce
	tryimprison BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSEALEDOPPONENTMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRefresh:: @ 0x08288995
	attackcanceler
	attackstring
	ppreduce
	cureifburnedparalyzedorpoisoned BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSTATUSNORMAL
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectGrudge:: @ 0x082889AC
	attackcanceler
	attackstring
	ppreduce
	trysetgrudge BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNWANTSGRUDGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSnatch:: @ 0x082889C1
	attackcanceler
	trysetsnatch BattleScript_FailedFromAtkString
	attackstring
	ppreduce
	attackanimation
	waitanimation
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNWAITSFORTARGET
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectLowKick:: @ 0x082889D9
	attackcanceler
	attackstring
	ppreduce
	weightdamagecalculation
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	goto BattleScript_HitFromCritCalc

BattleScript_EffectSecretPower:: @ 0x082889E9
	getsecretpowereffect
	goto BattleScript_EffectHit

BattleScript_EffectDoubleEdge:: @ 0x082889EF
	setmoveeffect MOVE_EFFECT_RECOIL_33 | MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectTeeterDance:: @ 0x082889FA
	attackcanceler
	attackstring
	ppreduce
	setbyte gBattlerTarget, 0
BattleScript_TeeterDanceLoop:
	movevaluescleanup
	setmoveeffect MOVE_EFFECT_CONFUSION
	jumpifbyteequal gBattlerAttacker, gBattlerTarget, BattleScript_TeeterDanceLoopIncrement
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_TeeterDanceOwnTempoPrevents
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_TeeterDanceSubstitutePrevents
	jumpifstatus2 BS_TARGET, STATUS2_CONFUSION, BattleScript_TeeterDanceAlreadyConfused
	jumpifhasnohp BS_TARGET, BattleScript_TeeterDanceLoopIncrement
	accuracycheck BattleScript_TeeterDanceMissed, ACC_CURR_MOVE
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_TeeterDanceSafeguardProtected
	attackanimation
	waitanimation
	seteffectprimary
	resultmessage
	waitmessage B_WAIT_TIME_LONG
BattleScript_TeeterDanceDoMoveEndIncrement:
	moveendto MOVEEND_NEXT_TARGET
BattleScript_TeeterDanceLoopIncrement:
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_TeeterDanceLoop
	end

BattleScript_TeeterDanceOwnTempoPrevents:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNPREVENTSCONFUSIONWITH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TeeterDanceDoMoveEndIncrement

BattleScript_TeeterDanceSafeguardProtected:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNUSEDSAFEGUARD
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TeeterDanceDoMoveEndIncrement

BattleScript_TeeterDanceSubstitutePrevents:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_BUTITFAILED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TeeterDanceDoMoveEndIncrement

BattleScript_TeeterDanceAlreadyConfused:
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYCONFUSED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TeeterDanceDoMoveEndIncrement

BattleScript_TeeterDanceMissed:
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TeeterDanceDoMoveEndIncrement

BattleScript_EffectMudSport:: @ 0x08288AB1
BattleScript_EffectWaterSport:: @ 0x08288AB1
	attackcanceler
	attackstring
	ppreduce
	settypebasedhalvers BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gSportsUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPoisonFang:: @ 0x08288AC8
	setmoveeffect MOVE_EFFECT_TOXIC
	goto BattleScript_EffectHit

BattleScript_EffectWeatherBall:: @ 0x08288AD3
	setweatherballtype
	goto BattleScript_EffectHit

BattleScript_EffectOverheat:: @ 0x08288AD9
	setmoveeffect MOVE_EFFECT_SP_ATK_TWO_DOWN | MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectTickle:: @ 0x08288AE4
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_TARGET, CMP_GREATER_THAN, STAT_ATK, MIN_STAT_STAGE, BattleScript_TickleDoMoveAnim
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_DEF, MIN_STAT_STAGE, BattleScript_CantLowerMultipleStats
BattleScript_TickleDoMoveAnim::
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_DEF, STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_ATK, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_ATK, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_TickleTryLowerDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_TickleTryLowerDef
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_TickleTryLowerDef::
	playstatchangeanimation BS_TARGET, BIT_DEF, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_TickleEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_TickleEnd
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_TickleEnd::
	goto BattleScript_MoveEnd

BattleScript_CantLowerMultipleStats::
	pause B_WAIT_TIME_SHORT
	orbyte gMoveResultFlags, MOVE_RESULT_FAILED
	printstring STRINGID_STATSWONTDECREASE2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectCosmicPower:: @ 0x08288B6B
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_CosmicPowerDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_CosmicPowerDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, 0
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CosmicPowerTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CosmicPowerTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CosmicPowerTrySpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CosmicPowerEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CosmicPowerEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CosmicPowerEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectSkyUppercut:: @ 0x08288BCF
	orword gHitMarker, HITMARKER_IGNORE_ON_AIR
	goto BattleScript_EffectHit

BattleScript_EffectBulkUp:: @ 0x08288BDD
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_BulkUpDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_DEF, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_BulkUpDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_BulkUpTryDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_BulkUpTryDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_BulkUpTryDef::
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_BulkUpEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_BulkUpEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_BulkUpEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectCalmMind:: @ 0x08288C41
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_CalmMindDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_CalmMindDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_SPDEF, 0
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CalmMindTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CalmMindTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CalmMindTrySpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CalmMindEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CalmMindEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CalmMindEnd::
	goto BattleScript_MoveEnd

BattleScript_CantRaiseMultipleStats::
	pause B_WAIT_TIME_SHORT
	orbyte gMoveResultFlags, MOVE_RESULT_FAILED
	printstring STRINGID_STATSWONTINCREASE2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectDragonDance:: @ 0x08288CB9
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_DragonDanceDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_DragonDanceDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPEED, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_DragonDanceTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_DragonDanceTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DragonDanceTrySpeed::
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_DragonDanceEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_DragonDanceEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DragonDanceEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectCamouflage:: @ 0x08288D1D
	attackcanceler
	attackstring
	ppreduce
	settypetoenvironment BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

@ Battle-end scripts. All visible JP entry points are named in their
@ physical order; raw spans remain until their battle-script macro conversion.
BattleScript_FaintAttacker:: @ 0x08288D32
	playfaintcry BS_ATTACKER
	pause B_WAIT_TIME_LONG
	dofaintanimation BS_ATTACKER
	cleareffectsonfaint BS_ATTACKER
	printstring STRINGID_ATTACKERFAINTED
	return

BattleScript_FaintTarget:: @ 0x08288D3F
	playfaintcry BS_TARGET
	pause B_WAIT_TIME_LONG
	dofaintanimation BS_TARGET
	cleareffectsonfaint BS_TARGET
	printstring STRINGID_TARGETFAINTED
	return

BattleScript_GiveExp:: @ 0x08288D4C
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
	end2

BattleScript_HandleFaintedMon:: @ 0x08288D55
	checkteamslost BattleScript_LinkHandleFaintedMonMultiple
	jumpifbyte CMP_NOT_EQUAL, gBattleOutcome, 0, BattleScript_FaintedMonEnd
	jumpifbattletype BATTLE_TYPE_TRAINER, BattleScript_FaintedMonTryChoose
	jumpifword CMP_NO_COMMON_BITS, gHitMarker, HITMARKER_PLAYER_FAINTED, BattleScript_FaintedMonTryChoose
@ Yes/No for sending out a new Pokémon if one is defeated in a wild battle
	printstring STRINGID_USENEXTPKMN
	setbyte gBattleCommunication, 0
	yesnobox
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, 0, BattleScript_FaintedMonTryChoose
@ Player said no, try to run
	jumpifplayerran BattleScript_FaintedMonEnd
	printstring STRINGID_CANTESCAPE2

BattleScript_FaintedMonTryChoose:: @ 0x08288D9E
	openpartyscreen BS_FAINTED, BattleScript_FaintedMonEnd
	switchhandleorder BS_FAINTED, 2
	jumpifnotbattletype BATTLE_TYPE_TRAINER, BattleScript_FaintedMonSendOutNew
	jumpifbattletype BATTLE_TYPE_LINK, BattleScript_FaintedMonSendOutNew
	jumpifbattletype BATTLE_TYPE_RECORDED_LINK, BattleScript_FaintedMonSendOutNew
	jumpifbattletype BATTLE_TYPE_FRONTIER, BattleScript_FaintedMonSendOutNew
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_FaintedMonSendOutNew
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_PLAYER_FAINTED, BattleScript_FaintedMonSendOutNew
	jumpifbyte CMP_EQUAL, sBATTLE_STYLE, OPTIONS_BATTLE_STYLE_SET, BattleScript_FaintedMonSendOutNew
	jumpifcantswitch BS_PLAYER1, BattleScript_FaintedMonSendOutNew
@ Yes/No for sending out a new Pokémon when the opponent is switching
	printstring STRINGID_ENEMYABOUTTOSWITCHPKMN
	setbyte gBattleCommunication, 0
	yesnobox
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, 1, BattleScript_FaintedMonSendOutNew
@ Player said yes, go to party screen (note optional flag, player may exit the menu instead)
	setatktoplayer0
	openpartyscreen BS_ATTACKER | PARTY_SCREEN_OPTIONAL, BattleScript_FaintedMonSendOutNew
	switchhandleorder BS_ATTACKER, 2
	jumpifbyte CMP_EQUAL, gBattleCommunication, PARTY_SIZE, BattleScript_FaintedMonSendOutNew
@ Switch Pokémon before opponent
	atknameinbuff1
	resetintimidatetracebits BS_ATTACKER
	hpthresholds2 BS_ATTACKER
	printstring STRINGID_RETURNMON
	switchoutabilities BS_ATTACKER
	waitstate
	returnatktoball
	waitstate
	drawpartystatussummary BS_ATTACKER
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_ATTACKER
	switchinanim BS_ATTACKER, 0
	waitstate
	switchineffects BS_ATTACKER
	resetsentmonsvalue

BattleScript_FaintedMonSendOutNew:: @ 0x08288E58
	drawpartystatussummary BS_FAINTED
	getswitchedmondata BS_FAINTED
	switchindataupdate BS_FAINTED
	hpthresholds BS_FAINTED
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_FAINTED
	switchinanim BS_FAINTED, FALSE
	waitstate
	resetplayerfainted
	switchineffects BS_FAINTED
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_FaintedMonEnd
	cancelallactions

BattleScript_FaintedMonEnd:: @ 0x08288E7D
	end2

BattleScript_LinkHandleFaintedMonMultiple:: @ 0x08288E7E
	openpartyscreen BS_FAINTED_LINK_MULTIPLE_1, BattleScript_LinkHandleFaintedMonMultipleStart

BattleScript_LinkHandleFaintedMonMultipleStart:: @ 0x08288E84
	switchhandleorder BS_FAINTED, 0
	openpartyscreen BS_FAINTED_LINK_MULTIPLE_2, BattleScript_LinkHandleFaintedMonMultipleEnd
	switchhandleorder BS_FAINTED, 0

BattleScript_LinkHandleFaintedMonLoop:: @ 0x08288E90
	switchhandleorder BS_FAINTED, 3
	drawpartystatussummary BS_FAINTED
	getswitchedmondata BS_FAINTED
	switchindataupdate BS_FAINTED
	hpthresholds BS_FAINTED
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_FAINTED
	switchinanim BS_FAINTED, FALSE
	waitstate
	switchineffects BS_FAINTED_LINK_MULTIPLE_1
	jumpifbytenotequal gBattlerFainted, gBattlersCount, BattleScript_LinkHandleFaintedMonLoop

BattleScript_LinkHandleFaintedMonMultipleEnd:: @ 0x08288EB4
	end2

BattleScript_LocalTrainerBattleWon:: @ 0x08288EB5
	jumpifbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_LocalTwoTrainersDefeated
	printstring STRINGID_PLAYERDEFEATEDTRAINER1
	goto BattleScript_LocalBattleWonLoseTexts

BattleScript_LocalTwoTrainersDefeated:: @ 0x08288ECB
	printstring STRINGID_TWOENEMIESDEFEATED

BattleScript_LocalBattleWonLoseTexts:: @ 0x08288ECE
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1LOSETEXT
	jumpifnotbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_LocalBattleWonReward
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	trainerslidein BS_FAINTED
	waitstate
	printstring STRINGID_TRAINER2LOSETEXT

BattleScript_LocalBattleWonReward:: @ 0x08288EEB
	getmoneyreward
	printstring STRINGID_PLAYERGOTMONEY
	waitmessage B_WAIT_TIME_LONG

BattleScript_PayDayMoneyAndPickUpItems:: @ 0x08288EF2
	givepaydaymoney
	pickup
	end2

BattleScript_LocalBattleLost:: @ 0x08288EF5
	jumpifbattletype BATTLE_TYPE_DOME, BattleScript_CheckDomeDrew
	jumpifbattletype BATTLE_TYPE_FRONTIER, BattleScript_LocalBattleLostPrintTrainersWinText
	jumpifbattletype BATTLE_TYPE_TRAINER_HILL, BattleScript_LocalBattleLostPrintTrainersWinText
	jumpifbattletype BATTLE_TYPE_EREADER_TRAINER, BattleScript_LocalBattleLostEnd
	jumpifhalfword CMP_EQUAL, gTrainerBattleOpponent_A, TRAINER_SECRET_BASE, BattleScript_LocalBattleLostEnd

BattleScript_LocalBattleLostPrintWhiteOut:: @ 0x08288F39
	printstring STRINGID_PLAYERWHITEOUT
	waitmessage B_WAIT_TIME_LONG
	printstring STRINGID_PLAYERWHITEOUT2
	waitmessage B_WAIT_TIME_LONG

BattleScript_LocalBattleLostEnd:: @ 0x08288F45
	end2

BattleScript_CheckDomeDrew:: @ 0x08288F46
	jumpifbyte CMP_EQUAL, gBattleOutcome, B_OUTCOME_DREW, BattleScript_LocalBattleLostEnd_

BattleScript_LocalBattleLostPrintTrainersWinText:: @ 0x08288F51
	jumpifnotbattletype BATTLE_TYPE_TRAINER, BattleScript_LocalBattleLostPrintWhiteOut
	returnopponentmon1toball BS_ATTACKER
	waitstate
	returnopponentmon2toball BS_ATTACKER
	waitstate
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1WINTEXT
	jumpifbattletype BATTLE_TYPE_TOWER_LINK_MULTI, BattleScript_LocalBattleLostDoTrainer2WinText
	jumpifnotbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_LocalBattleLostEnd_

BattleScript_LocalBattleLostDoTrainer2WinText:: @ 0x08288F89
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	trainerslidein BS_FAINTED
	waitstate
	printstring STRINGID_TRAINER2WINTEXT

BattleScript_LocalBattleLostEnd_:: @ 0x08288F92
	end2

BattleScript_FrontierLinkBattleLost:: @ 0x08288F93
	returnopponentmon1toball BS_ATTACKER
	waitstate
	returnopponentmon2toball BS_ATTACKER
	waitstate
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1WINTEXT
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	trainerslidein BS_FAINTED
	waitstate
	printstring STRINGID_TRAINER2WINTEXT
	jumpifbattletype BATTLE_TYPE_RECORDED, BattleScript_FrontierLinkBattleLostEnd
	endlinkbattle

BattleScript_FrontierLinkBattleLostEnd:: @ 0x08288FB9
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_LinkBattleWonOrLost:: @ 0x08288FBD
	jumpifbattletype BATTLE_TYPE_BATTLE_TOWER, BattleScript_TowerLinkBattleWon
	printstring STRINGID_BATTLEEND
	waitmessage B_WAIT_TIME_LONG
	jumpifbattletype BATTLE_TYPE_RECORDED, BattleScript_LinkBattleWonOrLostWaitEnd
	endlinkbattle

BattleScript_LinkBattleWonOrLostWaitEnd:: @ 0x08288FE0
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_TowerLinkBattleWon:: @ 0x08288FE4
	playtrainerdefeatbgm BS_ATTACKER
	printstring STRINGID_BATTLEEND
	waitmessage B_WAIT_TIME_LONG
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1LOSETEXT
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	trainerslidein BS_FAINTED
	waitstate
	printstring STRINGID_TRAINER2LOSETEXT
	jumpifbattletype BATTLE_TYPE_RECORDED, BattleScript_TowerLinkBattleWonEnd
	endlinkbattle

BattleScript_TowerLinkBattleWonEnd:: @ 0x0828900B
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_FrontierTrainerBattleWon:: @ 0x0828900F
	jumpifnotbattletype BATTLE_TYPE_TRAINER, BattleScript_PayDayMoneyAndPickUpItems
	jumpifbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_FrontierTrainerBattleWon_TwoDefeated
	printstring STRINGID_PLAYERDEFEATEDTRAINER1
	goto BattleScript_FrontierTrainerBattleWon_LoseTexts

BattleScript_FrontierTrainerBattleWon_TwoDefeated:: @ 0x08289033
	printstring STRINGID_TWOENEMIESDEFEATED

BattleScript_FrontierTrainerBattleWon_LoseTexts:: @ 0x08289036
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1LOSETEXT
	jumpifnotbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_TryPickUpItems
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	trainerslidein BS_FAINTED
	waitstate
	printstring STRINGID_TRAINER2LOSETEXT

BattleScript_TryPickUpItems:: @ 0x08289053
	jumpifnotbattletype BATTLE_TYPE_PYRAMID, BattleScript_FrontierTrainerBattleWon_End
	pickup

BattleScript_FrontierTrainerBattleWon_End:: @ 0x08289062
	end2

@ Escape, switch, and level-up scripts. All visible JP entry points are
@ named in physical order.
BattleScript_SmokeBallEscape:: @ 0x08289063
	playanimation BS_ATTACKER, B_ANIM_SMOKEBALL_ESCAPE, 0
	printstring STRINGID_PKMNFLEDUSINGITS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_RanAwayUsingMonAbility:: @ 0x08289071
	printstring STRINGID_PKMNFLEDUSING
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_GotAwaySafely:: @ 0x08289078
	printstring STRINGID_GOTAWAYSAFELY
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_WildMonFled:: @ 0x0828907F
	printstring STRINGID_WILDPKMNFLED
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_PrintCantRunFromTrainer:: @ 0x08289086
	printstring STRINGID_NORUNNINGFROMTRAINERS
	end2

BattleScript_PrintFailedToRunString:: @ 0x0828908A
	printfromtable gNoEscapeStringIds
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_PrintCantEscapeFromBattle:: @ 0x08289093
	printselectionstringfromtable gNoEscapeStringIds
	endselectionscript

BattleScript_PrintFullBox:: @ 0x08289099
	printselectionstring STRINGID_BOXISFULL
	endselectionscript

BattleScript_ActionSwitch:: @ 0x0828909D
	hpthresholds2 BS_ATTACKER
	printstring STRINGID_RETURNMON
	setbyte sDMG_MULTIPLIER, 2
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_PursuitSwitchDmgSetMultihit
	setmultihit 1
	goto BattleScript_PursuitSwitchDmgLoop

BattleScript_PursuitSwitchDmgSetMultihit:: @ 0x082890BD
	setmultihit 2

BattleScript_PursuitSwitchDmgLoop:: @ 0x082890BF
	jumpifnopursuitswitchdmg BattleScript_DoSwitchOut
	swapattackerwithtarget
	trysetdestinybondtohappen
	call BattleScript_PursuitDmgOnSwitchOut
	swapattackerwithtarget

BattleScript_DoSwitchOut:: @ 0x082890CC
	decrementmultihit BattleScript_PursuitSwitchDmgLoop
	switchoutabilities BS_ATTACKER
	waitstate
	returnatktoball
	waitstate
	drawpartystatussummary BS_ATTACKER
	switchhandleorder BS_ATTACKER, 1
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_ATTACKER
	switchinanim BS_ATTACKER, FALSE
	waitstate
	switchineffects BS_ATTACKER
	moveendcase MOVEEND_IMMUNITY_ABILITIES
	moveendcase MOVEEND_MIRROR_MOVE
	end2

BattleScript_PursuitDmgOnSwitchOut:: @ 0x082890FF
	pause B_WAIT_TIME_SHORT
	attackstring
	ppreduce
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET
	moveendfromto MOVEEND_ON_DAMAGE_ABILITIES, MOVEEND_CHOICE_MOVE
	getbattlerfainted BS_TARGET
	jumpifbyte CMP_EQUAL, gBattleCommunication, FALSE, BattleScript_PursuitDmgOnSwitchOutRet
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET

BattleScript_PursuitDmgOnSwitchOutRet:: @ 0x08289140
	return

BattleScript_Pausex20:: @ 0x08289141
	pause B_WAIT_TIME_SHORT
	return

BattleScript_LevelUp:: @ 0x08289145
	fanfare MUS_LEVEL_UP
	printstring STRINGID_PKMNGREWTOLV
	setbyte sLVLBOX_STATE, 0
	drawlvlupbox
	handlelearnnewmove BattleScript_LearnedNewMove, BattleScript_LearnMoveReturn, TRUE
	goto BattleScript_AskToLearnMove

BattleScript_TryLearnMoveLoop:: @ 0x08289161
	handlelearnnewmove BattleScript_LearnedNewMove, BattleScript_LearnMoveReturn, FALSE

BattleScript_AskToLearnMove:: @ 0x0828916B
	buffermovetolearn
	printstring STRINGID_TRYTOLEARNMOVE1
	printstring STRINGID_TRYTOLEARNMOVE2
	printstring STRINGID_TRYTOLEARNMOVE3
	waitstate
	setbyte sLEARNMOVE_STATE, 0
	yesnoboxlearnmove BattleScript_ForgotAndLearnedNewMove
	printstring STRINGID_STOPLEARNINGMOVE
	waitstate
	setbyte sLEARNMOVE_STATE, 0
	yesnoboxstoplearningmove BattleScript_AskToLearnMove
	printstring STRINGID_DIDNOTLEARNMOVE
	goto BattleScript_TryLearnMoveLoop

BattleScript_ForgotAndLearnedNewMove:: @ 0x08289198
	printstring STRINGID_123POOF
	printstring STRINGID_PKMNFORGOTMOVE
	printstring STRINGID_ANDELLIPSIS

BattleScript_LearnedNewMove:: @ 0x082891A1
	buffermovetolearn
	fanfare MUS_LEVEL_UP
	printstring STRINGID_PKMNLEARNEDMOVE
	waitmessage B_WAIT_TIME_LONG
	updatechoicemoveonlvlup BS_ATTACKER
	goto BattleScript_TryLearnMoveLoop

BattleScript_LearnMoveReturn:: @ 0x082891B3
	return

@ Weather-turn scripts. The physical entry points and loop labels are
@ retained explicitly.
BattleScript_RainContinuesOrEnds:: @ 0x082891B4
	printfromtable gRainContinuesStringIds
	waitmessage B_WAIT_TIME_LONG
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_RAIN_STOPPED, BattleScript_RainContinuesOrEndsEnd
	playanimation BS_ATTACKER, B_ANIM_RAIN_CONTINUES

BattleScript_RainContinuesOrEndsEnd:: @ 0x082891CE
	end2

BattleScript_DamagingWeatherContinues:: @ 0x082891CF
	printfromtable gSandStormHailContinuesStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation_var BS_ATTACKER, sB_ANIM_ARG1
	setbyte gBattleCommunication, 0

BattleScript_DamagingWeatherLoop:: @ 0x082891E7
	copyarraywithindex gBattlerAttacker, gBattlerByTurnOrder, gBattleCommunication, 1
	weatherdamage
	jumpifword CMP_EQUAL, gBattleMoveDamage, 0, BattleScript_DamagingWeatherLoopIncrement
	printfromtable gSandStormHailDmgStringIds
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_BIDE | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_HP_UPDATE | HITMARKER_GRUDGE
	effectivenesssound
	hitanimation BS_ATTACKER
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER
	checkteamslost BattleScript_DamagingWeatherLoopIncrement

BattleScript_DamagingWeatherLoopIncrement:: @ 0x08289228
	jumpifbyte CMP_NOT_EQUAL, gBattleOutcome, 0, BattleScript_DamagingWeatherContinuesEnd
	addbyte gBattleCommunication, 1
	jumpifbytenotequal gBattleCommunication, gBattlersCount, BattleScript_DamagingWeatherLoop

BattleScript_DamagingWeatherContinuesEnd:: @ 0x08289247
	bicword gHitMarker, HITMARKER_IGNORE_BIDE | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_HP_UPDATE | HITMARKER_GRUDGE
	end2

BattleScript_SandStormHailEnds:: @ 0x08289251
	printfromtable gSandStormHailEndStringIds
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SunlightContinues:: @ 0x0828925A
	printstring STRINGID_SUNLIGHTSTRONG
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_SUN_CONTINUES
	end2

BattleScript_SunlightFaded:: @ 0x08289268
	printstring STRINGID_SUNLIGHTFADED
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_OverworldWeatherStarts:: @ 0x0828926F
	printfromtable gWeatherStartsStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation_var BS_ATTACKER, sB_ANIM_ARG1
	end3

@ Turn-end side-status scripts. These physical entry points include the
@ safeguard and Leech Seed branches.
BattleScript_SideStatusWoreOff:: @ 0x08289282
	printstring STRINGID_PKMNSXWOREOFF
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SafeguardProtected:: @ 0x08289289
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNUSEDSAFEGUARD
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SafeguardEnds:: @ 0x08289293
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNSAFEGUARDEXPIRED
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_LeechSeedTurnDrain:: @ 0x0828929D
	playanimation BS_ATTACKER, B_ANIM_LEECH_SEED_DRAIN, sB_ANIM_ARG1
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_HP_UPDATE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	copyword gBattleMoveDamage, gHpDealt
	jumpifability BS_ATTACKER, ABILITY_LIQUID_OOZE, BattleScript_LeechSeedTurnPrintLiquidOoze
	manipulatedamage DMG_CHANGE_SIGN
	setbyte cMULTISTRING_CHOOSER, B_MSG_LEECH_SEED_DRAIN
	goto BattleScript_LeechSeedTurnPrintAndUpdateHp

BattleScript_LeechSeedTurnPrintLiquidOoze:: @ 0x082892CF
	setbyte cMULTISTRING_CHOOSER, B_MSG_LEECH_SEED_OOZE

BattleScript_LeechSeedTurnPrintAndUpdateHp:: @ 0x082892D5
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_HP_UPDATE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printfromtable gLeechSeedStringIds
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER
	tryfaintmon BS_TARGET
	end2

@ Bide's charge and release scripts. The complete three-path family stays
@ physically contiguous.
BattleScript_BideStoringEnergy:: @ 0x082892F9
	printstring STRINGID_PKMNSTORINGENERGY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_BideAttack:: @ 0x08289304
	attackcanceler
	setmoveeffect MOVE_EFFECT_CHARGING
	clearstatusfromeffect BS_ATTACKER
	printstring STRINGID_PKMNUNLEASHEDENERGY
	waitmessage B_WAIT_TIME_LONG
	accuracycheck BattleScript_MoveMissed, ACC_CURR_MOVE
	typecalc
	bicbyte gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	copyword gBattleMoveDamage, sBIDE_DMG
	adjustsetdamage
	setbyte sB_ANIM_TURN, 1
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_BideNoEnergyToAttack:: @ 0x0828934C
	attackcanceler
	setmoveeffect MOVE_EFFECT_CHARGING
	clearstatusfromeffect BS_ATTACKER
	printstring STRINGID_PKMNUNLEASHEDENERGY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_ButItFailed

@ Forced-switch scripts. The trainer branch begins at its actual JP entry
@ rather than remaining hidden inside a mixed EventScript container.
BattleScript_SuccessForceOut:: @ 0x08289360
	attackanimation
	waitanimation
	switchoutabilities BS_TARGET
	returntoball BS_TARGET
	waitstate
	jumpifbattletype BATTLE_TYPE_TRAINER, BattleScript_TrainerBattleForceOut
	setoutcomeonteleport BS_ATTACKER
	finishaction

BattleScript_TrainerBattleForceOut:: @ 0x08289379
	getswitchedmondata BS_TARGET
	switchindataupdate BS_TARGET
	switchinanim BS_TARGET, FALSE
	waitstate
	printstring STRINGID_PKMNWASDRAGGEDOUT
	switchineffects BS_TARGET
	goto BattleScript_MoveEnd

@ Status-block and status-expiry response scripts. Preserve the Battle
@ Palace selection branch as separate physical entries.
BattleScript_MistProtected:: @ 0x0828938B
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNPROTECTEDBYMIST
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_RageIsBuilding:: @ 0x08289395
	printstring STRINGID_PKMNRAGEBUILDING
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveUsedIsDisabled:: @ 0x0828939C
	printstring STRINGID_PKMNMOVEISDISABLED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingDisabledMove:: @ 0x082893A7
	printselectionstring STRINGID_PKMNMOVEISDISABLED
	endselectionscript

BattleScript_DisabledNoMore:: @ 0x082893AB
	printstring STRINGID_PKMNMOVEDISABLEDNOMORE
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SelectingDisabledMoveInPalace:: @ 0x082893B2
	printstring STRINGID_PKMNMOVEISDISABLED

BattleScript_SelectingUnusableMoveInPalace:: @ 0x082893B5
	moveendto MOVEEND_NEXT_TARGET
	end

BattleScript_EncoredNoMore:: @ 0x082893BF
	printstring STRINGID_PKMNENCOREENDED
	waitmessage B_WAIT_TIME_LONG
	end2

@ Delayed-faint scripts: Destiny Bond, Spikes, and Perish Song. Keep every
@ branch at its actual JP address, including the shared Spikes print path.
BattleScript_DestinyBondTakesLife:: @ 0x082893C6
	printstring STRINGID_PKMNTOOKFOE
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_HP_UPDATE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER
	return

BattleScript_SpikesOnAttacker:: @ 0x082893E1
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_HP_UPDATE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	call BattleScript_PrintHurtBySpikes
	tryfaintmon BS_ATTACKER
	tryfaintmon_spikes BS_ATTACKER, BattleScript_SpikesOnAttackerFainted
	return

BattleScript_SpikesOnAttackerFainted:: @ 0x08289402
	setbyte sGIVEEXP_STATE, 0
	getexp BS_ATTACKER
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_SpikesOnTarget:: @ 0x08289418
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_HP_UPDATE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	call BattleScript_PrintHurtBySpikes
	tryfaintmon BS_TARGET
	tryfaintmon_spikes BS_TARGET, BattleScript_SpikesOnTargetFainted
	return

BattleScript_SpikesOnTargetFainted:: @ 0x08289439
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_SpikesOnFaintedBattler:: @ 0x0828944F
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_HP_UPDATE
	healthbarupdate BS_FAINTED
	datahpupdate BS_FAINTED
	call BattleScript_PrintHurtBySpikes
	tryfaintmon BS_FAINTED
	tryfaintmon_spikes BS_FAINTED, BattleScript_SpikesOnFaintedBattlerFainted
	return

BattleScript_SpikesOnFaintedBattlerFainted:: @ 0x08289470
	setbyte sGIVEEXP_STATE, 0
	getexp BS_FAINTED
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_PrintHurtBySpikes:: @ 0x08289486
	printstring STRINGID_PKMNHURTBYSPIKES
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_PerishSongTakesLife:: @ 0x0828948D
	printstring STRINGID_PKMNPERISHCOUNTFELL
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_HP_UPDATE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER
	end2

BattleScript_PerishSongCountGoesDown:: @ 0x082894A8
	printstring STRINGID_PKMNPERISHCOUNTFELL
	waitmessage B_WAIT_TIME_LONG
	end2

@ All-stat boost script, split at each actual stat branch so the full
@ chained flow is visible.
BattleScript_AllStatsUp:: @ 0x082894AF
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPEED, MAX_STAT_STAGE, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_AllStatsUpRet

BattleScript_AllStatsUpAtk:: @ 0x082894DC
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF | BIT_SPEED | BIT_SPATK | BIT_SPDEF, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG

BattleScript_AllStatsUpDef:: @ 0x082894FA
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpSpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG

BattleScript_AllStatsUpSpeed:: @ 0x0828950E
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpSpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG

BattleScript_AllStatsUpSpAtk:: @ 0x08289522
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpSpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG

BattleScript_AllStatsUpSpDef:: @ 0x08289536
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpRet
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG

BattleScript_AllStatsUpRet:: @ 0x0828954A
	return

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
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0x4B, 0x01 @ printstring STRINGID_PKMNSXINTENSIFIEDSUN
	.byte 0x3A @ waitstate
	.byte 0x45, 0x07, 0x0B, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_BATTLER_0, B_ANIM_SUN_CONTINUES
	.byte 0x41, 0x15, 0x9A, 0x28, 0x08 @ call BattleScript_WeatherFormChanges
	.byte 0x3F @ end3

	.globl BattleScript_TookAttack
BattleScript_TookAttack: @ 0x8289AC6
	.byte 0x02 @ attackstring
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0x4E, 0x01 @ printstring STRINGID_PKMNSXTOOKATTACK
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x35, 0x24, 0x3F, 0x02, 0x02, 0x00, 0x04, 0x00, 0x00 @ orword gHitMarker, HITMARKER_ATTACKSTRING_PRINTED
	.byte 0x3C @ return

	.globl BattleScript_SturdyPreventsOHKO
BattleScript_SturdyPreventsOHKO: @ 0x8289ADA
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0xC3, 0x00 @ printstring STRINGID_PKMNPROTECTEDBY
	.byte 0x39, 0x40, 0x00 @ pause B_WAIT_TIME_LONG
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

	.globl BattleScript_DampStopsExplosion
BattleScript_DampStopsExplosion: @ 0x8289AE8
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0xC4, 0x00 @ printstring STRINGID_PKMNPREVENTSUSAGE
	.byte 0x39, 0x40, 0x00 @ pause B_WAIT_TIME_LONG
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

	.globl BattleScript_MoveHPDrain_PPLoss
BattleScript_MoveHPDrain_PPLoss: @ 0x8289AF6
	.byte 0x03 @ ppreduce

	.globl BattleScript_MoveHPDrain
BattleScript_MoveHPDrain: @ 0x8289AF7
	.byte 0x02 @ attackstring
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x35, 0x24, 0x3F, 0x02, 0x02, 0x00, 0x01, 0x00, 0x00 @ orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	.byte 0x0B, 0x00 @ healthbarupdate BS_TARGET
	.byte 0x0C, 0x00 @ datahpupdate BS_TARGET
	.byte 0x10, 0xC5, 0x00 @ printstring STRINGID_PKMNRESTOREDHPUSING
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x33, 0x20, 0x3F, 0x02, 0x02, 0x08 @ orbyte gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

	.globl BattleScript_MonMadeMoveUseless_PPLoss
BattleScript_MonMadeMoveUseless_PPLoss: @ 0x8289B19
	.byte 0x03 @ ppreduce

	.globl BattleScript_MonMadeMoveUseless
BattleScript_MonMadeMoveUseless: @ 0x8289B1A
	.byte 0x02 @ attackstring
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0x47, 0x01 @ printstring STRINGID_PKMNSXMADEYUSELESS
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x33, 0x20, 0x3F, 0x02, 0x02, 0x08 @ orbyte gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

	.globl BattleScript_FlashFireBoost_PPLoss
BattleScript_FlashFireBoost_PPLoss: @ 0x8289B2F
	.byte 0x03 @ ppreduce

	.globl BattleScript_FlashFireBoost
BattleScript_FlashFireBoost: @ 0x8289B30
	.byte 0x02 @ attackstring
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x13, 0xE2, 0xBA, 0x5A, 0x08 @ printfromtable gFlashFireStringIds
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

	.globl BattleScript_AbilityPreventsPhasingOut
BattleScript_AbilityPreventsPhasingOut: @ 0x8289B41
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0xCC, 0x00 @ printstring STRINGID_PKMNANCHORSITSELFWITH
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

	.globl BattleScript_AbilityNoStatLoss
BattleScript_AbilityNoStatLoss: @ 0x8289B4F
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0xCE, 0x00 @ printstring STRINGID_PKMNPREVENTSSTATLOSSWITH
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x3C @ return

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
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0xC8, 0x00 @ printstring STRINGID_PKMNPREVENTSROMANCEWITH
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

	.globl BattleScript_FlinchPrevention
BattleScript_FlinchPrevention: @ 0x8289B8B
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0x5B, 0x01 @ printstring STRINGID_PKMNSXPREVENTSFLINCHING
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

	.globl BattleScript_OwnTempoPrevents
BattleScript_OwnTempoPrevents: @ 0x8289B99
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0xCA, 0x00 @ printstring STRINGID_PKMNPREVENTSCONFUSIONWITH
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

	.globl BattleScript_SoundproofProtected
BattleScript_SoundproofProtected: @ 0x8289BA7
	.byte 0x02 @ attackstring
	.byte 0x03 @ ppreduce
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0x32, 0x01 @ printstring STRINGID_PKMNSXBLOCKSY
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

	.globl BattleScript_AbilityNoSpecificStatLoss
BattleScript_AbilityNoSpecificStatLoss: @ 0x8289BB7
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0x35, 0x01 @ printstring STRINGID_PKMNSXPREVENTSYLOSS
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x2E, 0xDB, 0x3F, 0x02, 0x02, 0x03 @ setbyte cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY
	.byte 0x3C @ return

	.globl BattleScript_StickyHoldActivates
BattleScript_StickyHoldActivates: @ 0x8289BC7
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0x37, 0x01 @ printstring STRINGID_PKMNSXMADEYINEFFECTIVE
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto BattleScript_MoveEnd

	.globl BattleScript_ColorChangeActivates
BattleScript_ColorChangeActivates: @ 0x8289BD5
	.byte 0x10, 0xC6, 0x00 @ printstring STRINGID_PKMNCHANGEDTYPEWITH
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

	.globl BattleScript_RoughSkinActivates
BattleScript_RoughSkinActivates: @ 0x8289BDC
	.byte 0x35, 0x24, 0x3F, 0x02, 0x02, 0x00, 0x01, 0x10, 0x00 @ orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_HP_UPDATE
	.byte 0x0B, 0x01 @ healthbarupdate BS_ATTACKER
	.byte 0x0C, 0x01 @ datahpupdate BS_ATTACKER
	.byte 0x10, 0xCF, 0x00 @ printstring STRINGID_PKMNHURTSWITH
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x19, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00 @ tryfaintmon BS_ATTACKER
	.byte 0x3C @ return

	.globl BattleScript_CuteCharmActivates
BattleScript_CuteCharmActivates: @ 0x8289BF7
	.byte 0x65, 0x01, 0x00, 0x00, 0x0F, 0x00 @ status2animation BS_ATTACKER, STATUS2_INFATUATION
	.byte 0x10, 0x36, 0x01 @ printstring STRINGID_PKMNSXINFATUATEDY
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x3C @ return

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
	.byte 0x39, 0x20, 0x00 @ pause B_WAIT_TIME_SHORT
	.byte 0x10, 0x37, 0x01 @ printstring STRINGID_PKMNSXMADEYINEFFECTIVE
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x3C @ return

	.globl BattleScript_AbilityCuredStatus
BattleScript_AbilityCuredStatus: @ 0x8289C14
	.byte 0x10, 0x64, 0x01 @ printstring STRINGID_PKMNSXCUREDITSYPROBLEM
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x98, 0x0A @ updatestatusicon BS_SCRIPTING
	.byte 0x3C @ return

	.globl BattleScript_IgnoresWhileAsleep
BattleScript_IgnoresWhileAsleep: @ 0x8289C1D
	.byte 0x10, 0x13, 0x01 @ printstring STRINGID_PKMNIGNORESASLEEP
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x2E, 0x2C, 0x41, 0x02, 0x02, 0x00 @ setbyte sMOVEEND_STATE, 0
	.byte 0x49, 0x02, 0x10 @ moveend 2, MOVEEND_NEXT_TARGET
	.byte 0x3D @ end

	.globl BattleScript_IgnoresAndUsesRandomMove
BattleScript_IgnoresAndUsesRandomMove: @ 0x8289C2D
	.byte 0x10, 0x14, 0x01 @ printstring STRINGID_PKMNIGNOREDORDERS
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x63, 0x00 @ jumptocalledmove FALSE

	.globl BattleScript_MoveUsedLoafingAround
BattleScript_MoveUsedLoafingAround: @ 0x8289C35
	.byte 0x29, 0x01, 0xDB, 0x3F, 0x02, 0x02, 0x04, 0x4F, 0x9C, 0x28, 0x08 @ jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_INCAPABLE_OF_POWER, BattleScript_MoveUsedLoafingAroundMsg
	.byte 0x2E, 0xD6, 0x3F, 0x02, 0x02, 0x00 @ setbyte gBattleCommunication, 0
	.byte 0x76, 0x01, 0x18 @ palacetryescapestatus BS_ATTACKER
	.byte 0x2E, 0xDB, 0x3F, 0x02, 0x02, 0x04 @ setbyte cMULTISTRING_CHOOSER, B_MSG_INCAPABLE_OF_POWER
BattleScript_MoveUsedLoafingAroundMsg: @ 0x8289C4F
	.byte 0x13, 0xA6, 0xBA, 0x5A, 0x08 @ printfromtable gInobedientStringIds
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x2E, 0x2C, 0x41, 0x02, 0x02, 0x00 @ setbyte sMOVEEND_STATE, 0
	.byte 0x49, 0x02, 0x10 @ moveend 2, MOVEEND_NEXT_TARGET
	.byte 0x3D @ end

	.globl BattleScript_IgnoresAndFallsAsleep
BattleScript_IgnoresAndFallsAsleep: @ 0x8289C61
	.byte 0x10, 0x15, 0x01 @ printstring STRINGID_PKMNBEGANTONAP
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x2E, 0xD9, 0x3F, 0x02, 0x02, 0x41 @ setbyte cEFFECT_CHOOSER, MOVE_EFFECT_SLEEP | MOVE_EFFECT_AFFECTS_USER
	.byte 0x16 @ seteffectprimary
	.byte 0x2E, 0x2C, 0x41, 0x02, 0x02, 0x00 @ setbyte sMOVEEND_STATE, 0
	.byte 0x49, 0x02, 0x10 @ moveend 2, MOVEEND_NEXT_TARGET
	.byte 0x3D @ end

	.globl BattleScript_IgnoresAndHitsItself
BattleScript_IgnoresAndHitsItself: @ 0x8289C78
	.byte 0x10, 0x17, 0x01 @ printstring STRINGID_PKMNWONTOBEY
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x28, 0x5C, 0x98, 0x28, 0x08 @ goto BattleScript_DoSelfConfusionDmg

	.globl BattleScript_SubstituteFade
BattleScript_SubstituteFade: @ 0x8289C83
	.byte 0x45, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_TARGET, B_ANIM_SUBSTITUTE_FADE
	.byte 0x10, 0x81, 0x00 @ printstring STRINGID_PKMNSUBSTITUTEFADED
	.byte 0x3C @ return

	.globl BattleScript_BerryCurePrlzEnd2
BattleScript_BerryCurePrlzEnd2: @ 0x8289C8E
	.byte 0x41, 0x94, 0x9C, 0x28, 0x08 @ call BattleScript_BerryCureParRet
	.byte 0x3E @ end2

	.globl BattleScript_BerryCureParRet
BattleScript_BerryCureParRet: @ 0x8289C94
	.byte 0x45, 0x0A, 0x07, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	.byte 0x10, 0x23, 0x01 @ printstring STRINGID_PKMNSITEMCUREDPARALYSIS
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x98, 0x0A @ updatestatusicon BS_SCRIPTING
	.byte 0x6A, 0x0A @ removeitem BS_SCRIPTING
	.byte 0x3C @ return

	.globl BattleScript_BerryCurePsnEnd2
BattleScript_BerryCurePsnEnd2: @ 0x8289CA6
	.byte 0x41, 0xAC, 0x9C, 0x28, 0x08 @ call BattleScript_BerryCurePsnRet
	.byte 0x3E @ end2

	.globl BattleScript_BerryCurePsnRet
BattleScript_BerryCurePsnRet: @ 0x8289CAC
	.byte 0x45, 0x0A, 0x07, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	.byte 0x10, 0x24, 0x01 @ printstring STRINGID_PKMNSITEMCUREDPOISON
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x98, 0x0A @ updatestatusicon BS_SCRIPTING
	.byte 0x6A, 0x0A @ removeitem BS_SCRIPTING
	.byte 0x3C @ return

	.globl BattleScript_BerryCureBrnEnd2
BattleScript_BerryCureBrnEnd2: @ 0x8289CBE
	.byte 0x41, 0xC4, 0x9C, 0x28, 0x08 @ call BattleScript_BerryCureBrnRet
	.byte 0x3E @ end2

	.globl BattleScript_BerryCureBrnRet
BattleScript_BerryCureBrnRet: @ 0x8289CC4
	.byte 0x45, 0x0A, 0x07, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	.byte 0x10, 0x25, 0x01 @ printstring STRINGID_PKMNSITEMHEALEDBURN
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x98, 0x0A @ updatestatusicon BS_SCRIPTING
	.byte 0x6A, 0x0A @ removeitem BS_SCRIPTING
	.byte 0x3C @ return

	.globl BattleScript_BerryCureFrzEnd2
BattleScript_BerryCureFrzEnd2: @ 0x8289CD6
	.byte 0x41, 0xDC, 0x9C, 0x28, 0x08 @ call BattleScript_BerryCureFrzRet
	.byte 0x3E @ end2

	.globl BattleScript_BerryCureFrzRet
BattleScript_BerryCureFrzRet: @ 0x8289CDC
	.byte 0x45, 0x0A, 0x07, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	.byte 0x10, 0x26, 0x01 @ printstring STRINGID_PKMNSITEMDEFROSTEDIT
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x98, 0x0A @ updatestatusicon BS_SCRIPTING
	.byte 0x6A, 0x0A @ removeitem BS_SCRIPTING
	.byte 0x3C @ return

	.globl BattleScript_BerryCureSlpEnd2
BattleScript_BerryCureSlpEnd2: @ 0x8289CEE
	.byte 0x41, 0xF4, 0x9C, 0x28, 0x08 @ call BattleScript_BerryCureSlpRet
	.byte 0x3E @ end2

	.globl BattleScript_BerryCureSlpRet
BattleScript_BerryCureSlpRet: @ 0x8289CF4
	.byte 0x45, 0x0A, 0x07, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	.byte 0x10, 0x27, 0x01 @ printstring STRINGID_PKMNSITEMWOKEIT
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x98, 0x0A @ updatestatusicon BS_SCRIPTING
	.byte 0x6A, 0x0A @ removeitem BS_SCRIPTING
	.byte 0x3C @ return

	.globl BattleScript_BerryCureConfusionEnd2
BattleScript_BerryCureConfusionEnd2: @ 0x8289D06
	.byte 0x41, 0x0C, 0x9D, 0x28, 0x08 @ call BattleScript_BerryCureConfusionRet
	.byte 0x3E @ end2

	.globl BattleScript_BerryCureConfusionRet
BattleScript_BerryCureConfusionRet: @ 0x8289D0C
	.byte 0x45, 0x0A, 0x07, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	.byte 0x10, 0x28, 0x01 @ printstring STRINGID_PKMNSITEMSNAPPEDOUT
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x6A, 0x0A @ removeitem BS_SCRIPTING
	.byte 0x3C @ return

	.globl BattleScript_BerryCureChosenStatusEnd2
BattleScript_BerryCureChosenStatusEnd2: @ 0x8289D1C
	.byte 0x41, 0x22, 0x9D, 0x28, 0x08 @ call BattleScript_BerryCureChosenStatusRet
	.byte 0x3E @ end2

	.globl BattleScript_BerryCureChosenStatusRet
BattleScript_BerryCureChosenStatusRet: @ 0x8289D22
	.byte 0x45, 0x0A, 0x07, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	.byte 0x13, 0xC6, 0xBA, 0x5A, 0x08 @ printfromtable gBerryEffectStringIds
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x98, 0x0A @ updatestatusicon BS_SCRIPTING
	.byte 0x6A, 0x0A @ removeitem BS_SCRIPTING
	.byte 0x3C @ return

	.globl BattleScript_WhiteHerbEnd2
BattleScript_WhiteHerbEnd2: @ 0x8289D36
	.byte 0x41, 0x3C, 0x9D, 0x28, 0x08 @ call BattleScript_WhiteHerbRet
	.byte 0x3E @ end2

	.globl BattleScript_WhiteHerbRet
BattleScript_WhiteHerbRet: @ 0x8289D3C
	.byte 0x45, 0x0A, 0x07, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	.byte 0x10, 0x2C, 0x01 @ printstring STRINGID_PKMNSITEMRESTOREDSTATUS
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x6A, 0x0A @ removeitem BS_SCRIPTING
	.byte 0x3C @ return

	.globl BattleScript_ItemHealHP_RemoveItem
BattleScript_ItemHealHP_RemoveItem: @ 0x8289D4C
	.byte 0x45, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	.byte 0x10, 0x2A, 0x01 @ printstring STRINGID_PKMNSITEMRESTOREDHEALTH
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x35, 0x24, 0x3F, 0x02, 0x02, 0x00, 0x01, 0x00, 0x00 @ orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	.byte 0x0B, 0x01 @ healthbarupdate BS_ATTACKER
	.byte 0x0C, 0x01 @ datahpupdate BS_ATTACKER
	.byte 0x6A, 0x01 @ removeitem BS_ATTACKER
	.byte 0x3E @ end2

	.globl BattleScript_BerryPPHealEnd2
BattleScript_BerryPPHealEnd2: @ 0x8289D69
	.byte 0x45, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	.byte 0x10, 0x2B, 0x01 @ printstring STRINGID_PKMNSITEMRESTOREDPP
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x6A, 0x01 @ removeitem BS_ATTACKER
	.byte 0x3E @ end2

	.globl BattleScript_ItemHealHP_End2
BattleScript_ItemHealHP_End2: @ 0x8289D79
	.byte 0x41, 0x7F, 0x9D, 0x28, 0x08 @ call BattleScript_ItemHealHP_Ret
	.byte 0x3E @ end2

	.globl BattleScript_ItemHealHP_Ret
BattleScript_ItemHealHP_Ret: @ 0x8289D7F
	.byte 0x45, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	.byte 0x10, 0x2D, 0x01 @ printstring STRINGID_PKMNSITEMRESTOREDHPALITTLE
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x35, 0x24, 0x3F, 0x02, 0x02, 0x00, 0x01, 0x00, 0x00 @ orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	.byte 0x0B, 0x01 @ healthbarupdate BS_ATTACKER
	.byte 0x0C, 0x01 @ datahpupdate BS_ATTACKER
	.byte 0x3C @ return

	.globl BattleScript_SelectingNotAllowedMoveChoiceItem
BattleScript_SelectingNotAllowedMoveChoiceItem: @ 0x8289D9A
	.byte 0x11, 0x2E, 0x01 @ printselectionstring STRINGID_ITEMALLOWSONLYYMOVE
	.byte 0x44 @ endselectionscript

	.globl BattleScript_FocusBandActivates
BattleScript_FocusBandActivates: @ 0x8289D9E
	.byte 0x45, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_TARGET, B_ANIM_FOCUS_BAND
	.byte 0x10, 0x2F, 0x01 @ printstring STRINGID_PKMNHUNGONWITHX
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x3C @ return

	.globl BattleScript_BerryConfuseHealEnd2
BattleScript_BerryConfuseHealEnd2: @ 0x8289DAC
	.byte 0x45, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	.byte 0x10, 0x2A, 0x01 @ printstring STRINGID_PKMNSITEMRESTOREDHEALTH
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x35, 0x24, 0x3F, 0x02, 0x02, 0x00, 0x01, 0x00, 0x00 @ orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	.byte 0x0B, 0x01 @ healthbarupdate BS_ATTACKER
	.byte 0x0C, 0x01 @ datahpupdate BS_ATTACKER
	.byte 0x10, 0x44, 0x01 @ printstring STRINGID_FORXCOMMAYZ
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x2E, 0xD9, 0x3F, 0x02, 0x02, 0x47 @ setbyte cEFFECT_CHOOSER, MOVE_EFFECT_CONFUSION | MOVE_EFFECT_AFFECTS_USER
	.byte 0x16 @ seteffectprimary
	.byte 0x6A, 0x01 @ removeitem BS_ATTACKER
	.byte 0x3E @ end2

	.globl BattleScript_BerryStatRaiseEnd2
BattleScript_BerryStatRaiseEnd2: @ 0x8289DD6
	.byte 0x45, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	.byte 0x89, 0x41, 0xE3, 0x9D, 0x28, 0x08 @ statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_BerryStatRaiseDoStatUp
BattleScript_BerryStatRaiseDoStatUp: @ 0x8289DE3
	.byte 0x2E, 0xDB, 0x3F, 0x02, 0x02, 0x04 @ setbyte cMULTISTRING_CHOOSER, B_MSG_STAT_ROSE_ITEM
	.byte 0x41, 0x5C, 0x72, 0x28, 0x08 @ call BattleScript_StatUp
	.byte 0x6A, 0x01 @ removeitem BS_ATTACKER
	.byte 0x3E @ end2

	.globl BattleScript_BerryFocusEnergyEnd2
BattleScript_BerryFocusEnergyEnd2: @ 0x8289DF1
	.byte 0x45, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00 @ playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	.byte 0x10, 0x46, 0x01 @ printstring STRINGID_PKMNUSEDXTOGETPUMPED
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x6A, 0x01 @ removeitem BS_ATTACKER
	.byte 0x3E @ end2

	.globl BattleScript_ActionSelectionItemsCantBeUsed
BattleScript_ActionSelectionItemsCantBeUsed: @ 0x8289E01
	.byte 0x11, 0x43, 0x01 @ printselectionstring STRINGID_ITEMSCANTBEUSEDNOW
	.byte 0x44 @ endselectionscript

	.globl BattleScript_FlushMessageBox
BattleScript_FlushMessageBox: @ 0x8289E05
	.byte 0x10, 0x30, 0x01 @ printstring STRINGID_EMPTYSTRING3
	.byte 0x3C @ return

	.globl BattleScript_PalacePrintFlavorText
BattleScript_PalacePrintFlavorText: @ 0x8289E09
	.byte 0x2E, 0xD7, 0x3F, 0x02, 0x02, 0x00 @ setbyte gBattleCommunication + 1, 0
BattleScript_PalaceTryBattlerFlavorText: @ 0x8289E0F
	.byte 0x76, 0x01, 0x08 @ palaceflavortext BS_ATTACKER
	.byte 0x29, 0x01, 0xD6, 0x3F, 0x02, 0x02, 0x01, 0x25, 0x9E, 0x28, 0x08 @ jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, TRUE, BattleScript_PalaceEndFlavorText
	.byte 0x13, 0xB4, 0xBE, 0x5A, 0x08 @ printfromtable gBattlePalaceFlavorTextTable
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
BattleScript_PalaceEndFlavorText: @ 0x8289E25
	.byte 0x2F, 0xD7, 0x3F, 0x02, 0x02, 0x01 @ addbyte gBattleCommunication + 1, 1
	.byte 0x2D, 0xD7, 0x3F, 0x02, 0x02, 0x10, 0x3D, 0x02, 0x02, 0x01, 0x0F, 0x9E, 0x28, 0x08 @ jumpifbytenotequal gBattleCommunication + 1, gBattlersCount, BattleScript_PalaceTryBattlerFlavorText
	.byte 0x2E, 0xD6, 0x3F, 0x02, 0x02, 0x00 @ setbyte gBattleCommunication, 0
	.byte 0x2E, 0xD7, 0x3F, 0x02, 0x02, 0x00 @ setbyte gBattleCommunication + 1, 0
	.byte 0x3E @ end2

	.globl BattleScript_ArenaTurnBeginning
BattleScript_ArenaTurnBeginning: @ 0x8289E46
	.byte 0x76, 0x01, 0x12 @ waitcry BS_ATTACKER
	.byte 0x76, 0x01, 0x15 @ volumedown
	.byte 0x54, 0x09, 0x01 @ playse SE_ARENA_TIMEUP1
	.byte 0x39, 0x08, 0x00 @ pause 8
	.byte 0x54, 0x09, 0x01 @ playse SE_ARENA_TIMEUP1
	.byte 0x76, 0x01, 0x0E @ arenadrawreftextbox
	.byte 0x76, 0x08, 0x10 @ arenajudgmentstring B_MSG_REF_COMMENCE_BATTLE
	.byte 0x76, 0x08, 0x11 @ arenawaitmessage B_MSG_REF_COMMENCE_BATTLE
	.byte 0x39, 0x40, 0x00 @ pause B_WAIT_TIME_LONG
	.byte 0x76, 0x01, 0x0F @ arenaerasereftextbox
	.byte 0x76, 0x01, 0x16 @ volumeup
	.byte 0x3E @ end2

@ Unused
BattleScript_ArenaNothingDecided: @ 0x8289E68
	.byte 0x54, 0x49, 0x00 @ playse SE_DING_DONG
	.byte 0x76, 0x01, 0x0E @ arenadrawreftextbox
	.byte 0x76, 0x00, 0x10 @ arenajudgmentstring B_MSG_REF_NOTHING_IS_DECIDED
	.byte 0x76, 0x00, 0x11 @ arenawaitmessage B_MSG_REF_NOTHING_IS_DECIDED
	.byte 0x39, 0x40, 0x00 @ pause B_WAIT_TIME_LONG
	.byte 0x76, 0x01, 0x0F @ arenaerasereftextbox
	.byte 0x3E @ end2

	.globl BattleScript_ArenaDoJudgment
BattleScript_ArenaDoJudgment: @ 0x8289E7B
	.byte 0x6F, 0x0B @ makevisible BS_PLAYER1
	.byte 0x3A @ waitstate
	.byte 0x6F, 0x0C @ makevisible BS_OPPONENT1
	.byte 0x3A @ waitstate
	.byte 0x76, 0x01, 0x15 @ volumedown
	.byte 0x54, 0x09, 0x01 @ playse SE_ARENA_TIMEUP1
	.byte 0x39, 0x08, 0x00 @ pause 8
	.byte 0x54, 0x09, 0x01 @ playse SE_ARENA_TIMEUP1
	.byte 0x39, 0x40, 0x00 @ pause B_WAIT_TIME_LONG
	.byte 0x76, 0x01, 0x0E @ arenadrawreftextbox
	.byte 0x76, 0x01, 0x10 @ arenajudgmentstring B_MSG_REF_THATS_IT
	.byte 0x76, 0x01, 0x11 @ arenawaitmessage B_MSG_REF_THATS_IT
	.byte 0x39, 0x40, 0x00 @ pause B_WAIT_TIME_LONG
	.byte 0x2E, 0xD6, 0x3F, 0x02, 0x02, 0x00 @ setbyte gBattleCommunication, 0
	.byte 0x76, 0x01, 0x09 @ arenajudgmentwindow
	.byte 0x39, 0x40, 0x00 @ pause B_WAIT_TIME_LONG
	.byte 0x76, 0x01, 0x09 @ arenajudgmentwindow
	.byte 0x76, 0x02, 0x10 @ arenajudgmentstring B_MSG_REF_JUDGE_MIND
	.byte 0x76, 0x02, 0x11 @ arenawaitmessage B_MSG_REF_JUDGE_MIND
	.byte 0x76, 0x01, 0x09 @ arenajudgmentwindow
	.byte 0x76, 0x03, 0x10 @ arenajudgmentstring B_MSG_REF_JUDGE_SKILL
	.byte 0x76, 0x03, 0x11 @ arenawaitmessage B_MSG_REF_JUDGE_SKILL
	.byte 0x76, 0x01, 0x09 @ arenajudgmentwindow
	.byte 0x76, 0x04, 0x10 @ arenajudgmentstring B_MSG_REF_JUDGE_BODY
	.byte 0x76, 0x04, 0x11 @ arenawaitmessage B_MSG_REF_JUDGE_BODY
	.byte 0x76, 0x01, 0x09 @ arenajudgmentwindow
	.byte 0x29, 0x00, 0xD7, 0x3F, 0x02, 0x02, 0x03, 0xFB, 0x9E, 0x28, 0x08 @ jumpifbyte CMP_EQUAL, gBattleCommunication + 1, ARENA_RESULT_PLAYER_LOST, BattleScript_ArenaJudgmentPlayerLoses
	.byte 0x29, 0x00, 0xD7, 0x3F, 0x02, 0x02, 0x04, 0x1A, 0x9F, 0x28, 0x08 @ jumpifbyte CMP_EQUAL, gBattleCommunication + 1, ARENA_RESULT_TIE, BattleScript_ArenaJudgmentDraw
	.byte 0x76, 0x05, 0x10 @ arenajudgmentstring B_MSG_REF_PLAYER_WON
	.byte 0x76, 0x05, 0x11 @ arenawaitmessage B_MSG_REF_PLAYER_WON
	.byte 0x76, 0x01, 0x09 @ arenajudgmentwindow
	.byte 0x76, 0x01, 0x0F @ arenaerasereftextbox
	.byte 0x10, 0x72, 0x01 @ printstring STRINGID_DEFEATEDOPPONENTBYREFEREE
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x56, 0x0C @ playfaintcry BS_OPPONENT1
	.byte 0x76, 0x01, 0x12 @ waitcry BS_ATTACKER
	.byte 0x1A, 0x0C @ dofaintanimation BS_OPPONENT1
	.byte 0x1B, 0x0C @ cleareffectsonfaint BS_OPPONENT1
	.byte 0x76, 0x01, 0x0A @ arenaopponentmonlost
	.byte 0x3E @ end2

BattleScript_ArenaJudgmentPlayerLoses: @ 0x8289EFB
	.byte 0x76, 0x06, 0x10 @ arenajudgmentstring B_MSG_REF_OPPONENT_WON
	.byte 0x76, 0x06, 0x11 @ arenawaitmessage B_MSG_REF_OPPONENT_WON
	.byte 0x76, 0x01, 0x09 @ arenajudgmentwindow
	.byte 0x76, 0x01, 0x0F @ arenaerasereftextbox
	.byte 0x10, 0x73, 0x01 @ printstring STRINGID_LOSTTOOPPONENTBYREFEREE
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x56, 0x0B @ playfaintcry BS_PLAYER1
	.byte 0x76, 0x01, 0x12 @ waitcry BS_ATTACKER
	.byte 0x1A, 0x0B @ dofaintanimation BS_PLAYER1
	.byte 0x1B, 0x0B @ cleareffectsonfaint BS_PLAYER1
	.byte 0x76, 0x01, 0x0B @ arenaplayermonlost
	.byte 0x3E @ end2

BattleScript_ArenaJudgmentDraw: @ 0x8289F1A
	.byte 0x76, 0x07, 0x10 @ arenajudgmentstring B_MSG_REF_DRAW
	.byte 0x76, 0x07, 0x11 @ arenawaitmessage B_MSG_REF_DRAW
	.byte 0x76, 0x01, 0x09 @ arenajudgmentwindow
	.byte 0x76, 0x01, 0x0F @ arenaerasereftextbox
	.byte 0x10, 0x74, 0x01 @ printstring STRINGID_TIEDOPPONENTBYREFEREE
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x56, 0x0B @ playfaintcry BS_PLAYER1
	.byte 0x76, 0x01, 0x12 @ waitcry BS_ATTACKER
	.byte 0x1A, 0x0B @ dofaintanimation BS_PLAYER1
	.byte 0x1B, 0x0B @ cleareffectsonfaint BS_PLAYER1
	.byte 0x56, 0x0C @ playfaintcry BS_OPPONENT1
	.byte 0x76, 0x01, 0x12 @ waitcry BS_ATTACKER
	.byte 0x1A, 0x0C @ dofaintanimation BS_OPPONENT1
	.byte 0x1B, 0x0C @ cleareffectsonfaint BS_OPPONENT1
	.byte 0x76, 0x01, 0x0C @ arenabothmonlost
	.byte 0x3E @ end2

	.globl BattleScript_AskIfWantsToForfeitMatch
BattleScript_AskIfWantsToForfeitMatch: @ 0x8289F42
	.byte 0x11, 0x75, 0x01 @ printselectionstring STRINGID_QUESTIONFORFEITMATCH
	.byte 0x76, 0x01, 0x0D @ forfeityesnobox BS_ATTACKER
	.byte 0x44 @ endselectionscript

	.globl BattleScript_PrintPlayerForfeited
BattleScript_PrintPlayerForfeited: @ 0x8289F49
	.byte 0x10, 0x76, 0x01 @ printstring STRINGID_FORFEITEDMATCH
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

	.globl BattleScript_PrintPlayerForfeitedLinkBattle
BattleScript_PrintPlayerForfeitedLinkBattle: @ 0x8289F50
	.byte 0x10, 0x76, 0x01 @ printstring STRINGID_FORFEITEDMATCH
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x57 @ endlinkbattle
	.byte 0x12, 0x40, 0x00 @ waitmessage B_WAIT_TIME_LONG
	.byte 0x3E @ end2
	.byte 0x00 @ alignment padding
