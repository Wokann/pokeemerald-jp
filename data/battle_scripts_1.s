
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
	.globl gBattleScriptsForMoveEffects
gBattleScriptsForMoveEffects: @ 0x8286C30
	.incbin "baserom_jp.gba", 0x286c30, 0x388
	.globl BattleScript_HitFromCritCalc
BattleScript_HitFromCritCalc: @ 0x8286FB8
	.include "data/scripts/gUnknown_8286FB8.inc"

	.globl BattleScript_MoveEnd
BattleScript_MoveEnd: @ 0x8286FD6
	.include "data/scripts/gUnknown_8286FD6.inc"

	.globl BattleScript_MoveMissedPause
BattleScript_MoveMissedPause: @ 0x8286FE8
	.include "data/scripts/gUnknown_8286FE8.inc"

	.globl BattleScript_StatUp
BattleScript_StatUp: @ 0x828725C
	.include "data/scripts/gUnknown_828725C.inc"

	.globl BattleScript_StatDown
BattleScript_StatDown: @ 0x82872ED
	.include "data/scripts/gUnknown_82872ED.inc"

	.globl BattleScript_MoveUsedMustRecharge
BattleScript_MoveUsedMustRecharge: @ 0x82879EA
	.include "data/scripts/gUnknown_82879EA.inc"

	.globl BattleScript_PresentHealTarget
BattleScript_PresentHealTarget: @ 0x8288469
	.include "data/scripts/gUnknown_8288469.inc"

	.globl BattleScript_AlreadyAtFullHp
BattleScript_AlreadyAtFullHp: @ 0x8288483
	.include "data/scripts/gUnknown_8288483.inc"

	.globl BattleScript_ButItFailed
BattleScript_ButItFailed: @ 0x82884A4
	.include "data/scripts/gUnknown_82884A4.inc"

	.globl BattleScript_FaintAttacker
BattleScript_FaintAttacker: @ 0x8288D32
	.include "data/scripts/gUnknown_8288D32.inc"

	.globl BattleScript_FaintTarget
BattleScript_FaintTarget: @ 0x8288D3F
	.include "data/scripts/gUnknown_8288D3F.inc"

	.globl BattleScript_GiveExp
BattleScript_GiveExp: @ 0x8288D4C
	.include "data/scripts/gUnknown_8288D4C.inc"

	.globl BattleScript_HandleFaintedMon
BattleScript_HandleFaintedMon: @ 0x8288D55
	.include "data/scripts/gUnknown_8288D55.inc"

	.globl BattleScript_LocalTrainerBattleWon
BattleScript_LocalTrainerBattleWon: @ 0x8288EB5
	.include "data/scripts/gUnknown_8288EB5.inc"

	.globl BattleScript_PayDayMoneyAndPickUpItems
BattleScript_PayDayMoneyAndPickUpItems: @ 0x8288EF2
	.byte 0x91 @ givepaydaymoney
	.byte 0xE5 @ pickup
	.byte 0x3E @ end2

	.globl BattleScript_LocalBattleLost
BattleScript_LocalBattleLost: @ 0x8288EF5
	.include "data/scripts/gUnknown_8288EF5.inc"

	.globl BattleScript_FrontierLinkBattleLost
BattleScript_FrontierLinkBattleLost: @ 0x8288F93
	.include "data/scripts/gUnknown_8288F93.inc"

	.globl BattleScript_LinkBattleWonOrLost
BattleScript_LinkBattleWonOrLost: @ 0x8288FBD
	.include "data/scripts/gUnknown_8288FBD.inc"

	.globl BattleScript_FrontierTrainerBattleWon
BattleScript_FrontierTrainerBattleWon: @ 0x828900F
	.include "data/scripts/gUnknown_828900F.inc"

	.globl BattleScript_SmokeBallEscape
BattleScript_SmokeBallEscape: @ 0x8289063
	.include "data/scripts/gUnknown_8289063.inc"

	.globl BattleScript_RanAwayUsingMonAbility
BattleScript_RanAwayUsingMonAbility: @ 0x8289071
	.byte 0x10, 0x53, 0x01 @ printstring STRINGID_PKMNFLEDUSING
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

	.globl BattleScript_GotAwaySafely
BattleScript_GotAwaySafely: @ 0x8289078
	.byte 0x10, 0xDF, 0x00 @ printstring STRINGID_GOTAWAYSAFELY
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

	.globl BattleScript_WildMonFled
BattleScript_WildMonFled: @ 0x828907F
	.byte 0x10, 0xE0, 0x00 @ printstring STRINGID_WILDPKMNFLED
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

	.globl gUnknown_8289086
gUnknown_8289086: @ 0x8289086
	.byte 0x10, 0xE1, 0x00 @ printstring STRINGID_NORUNNINGFROMTRAINERS
	.byte 0x3E @ end2

	.globl BattleScript_PrintFailedToRunString
BattleScript_PrintFailedToRunString: @ 0x828908A
	.byte 0x13, 0xAA, 0xB9, 0x5A, 0x08 @ printfromtable 0x085AB9AA
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

	.globl gUnknown_8289093
gUnknown_8289093: @ 0x8289093
	.include "data/scripts/gUnknown_8289093.inc"

	.globl gUnknown_8289099
gUnknown_8289099: @ 0x8289099
	.byte 0x11, 0x58, 0x01 @ printselectionstring STRINGID_BOXISFULL
	.byte 0x44 @ endselectionscript

	.globl BattleScript_ActionSwitch
BattleScript_ActionSwitch: @ 0x828909D
	.include "data/scripts/gUnknown_828909D.inc"

	.globl BattleScript_Pausex20
BattleScript_Pausex20: @ 0x8289141
	.byte 0x39, 0x20, 0x00 @ pause 0x0020
	.byte 0x3C @ return

	.globl BattleScript_LevelUp
BattleScript_LevelUp: @ 0x8289145
	.include "data/scripts/gUnknown_8289145.inc"

	.globl BattleScript_RainContinuesOrEnds
BattleScript_RainContinuesOrEnds: @ 0x82891B4
	.include "data/scripts/gUnknown_82891B4.inc"

	.globl BattleScript_DamagingWeatherContinues
BattleScript_DamagingWeatherContinues: @ 0x82891CF
	.include "data/scripts/gUnknown_82891CF.inc"

	.globl BattleScript_SandStormHailEnds
BattleScript_SandStormHailEnds: @ 0x8289251
	.byte 0x13, 0xC8, 0xB9, 0x5A, 0x08 @ printfromtable 0x085AB9C8
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

	.globl BattleScript_SunlightContinues
BattleScript_SunlightContinues: @ 0x828925A
	.include "data/scripts/gUnknown_828925A.inc"

	.globl BattleScript_SunlightFaded
BattleScript_SunlightFaded: @ 0x8289268
	.byte 0x10, 0xF2, 0x00 @ printstring STRINGID_SUNLIGHTFADED
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

	.globl BattleScript_OverworldWeatherStarts
BattleScript_OverworldWeatherStarts: @ 0x828926F
	.include "data/scripts/gUnknown_828926F.inc"

	.globl BattleScript_SideStatusWoreOff
BattleScript_SideStatusWoreOff: @ 0x8289282
	.include "data/scripts/gUnknown_8289282.inc"

	.globl BattleScript_SafeguardEnds
BattleScript_SafeguardEnds: @ 0x8289293
	.include "data/scripts/gUnknown_8289293.inc"

	.globl BattleScript_LeechSeedTurnDrain
BattleScript_LeechSeedTurnDrain: @ 0x828929D
	.include "data/scripts/gUnknown_828929D.inc"

	.globl BattleScript_BideStoringEnergy
BattleScript_BideStoringEnergy: @ 0x82892F9
	.byte 0x10, 0x78, 0x00 @ printstring STRINGID_PKMNSTORINGENERGY
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto 0x08286FD6

	.globl BattleScript_BideAttack
BattleScript_BideAttack: @ 0x8289304
	.include "data/scripts/gUnknown_8289304.inc"

	.globl BattleScript_BideNoEnergyToAttack
BattleScript_BideNoEnergyToAttack: @ 0x828934C
	.include "data/scripts/gUnknown_828934C.inc"

	.globl BattleScript_SuccessForceOut
BattleScript_SuccessForceOut: @ 0x8289360
	.include "data/scripts/gUnknown_8289360.inc"

	.globl BattleScript_MistProtected
BattleScript_MistProtected: @ 0x828938B
	.include "data/scripts/gUnknown_828938B.inc"

	.globl BattleScript_RageIsBuilding
BattleScript_RageIsBuilding: @ 0x8289395
	.byte 0x10, 0x83, 0x00 @ printstring STRINGID_PKMNRAGEBUILDING
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

	.globl BattleScript_MoveUsedIsDisabled
BattleScript_MoveUsedIsDisabled: @ 0x828939C
	.byte 0x10, 0x85, 0x00 @ printstring STRINGID_PKMNMOVEISDISABLED
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto 0x08286FD6

	.globl BattleScript_SelectingDisabledMove
BattleScript_SelectingDisabledMove: @ 0x82893A7
	.byte 0x11, 0x85, 0x00 @ printselectionstring STRINGID_PKMNMOVEISDISABLED
	.byte 0x44 @ endselectionscript

	.globl BattleScript_DisabledNoMore
BattleScript_DisabledNoMore: @ 0x82893AB
	.byte 0x10, 0x86, 0x00 @ printstring STRINGID_PKMNMOVEDISABLEDNOMORE
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

	.globl BattleScript_SelectingDisabledMoveInPalace
BattleScript_SelectingDisabledMoveInPalace: @ 0x82893B2
	.include "data/scripts/gUnknown_82893B2.inc"

	.globl BattleScript_EncoredNoMore
BattleScript_EncoredNoMore: @ 0x82893BF
	.byte 0x10, 0x88, 0x00 @ printstring STRINGID_PKMNENCOREENDED
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

	.globl BattleScript_DestinyBondTakesLife
BattleScript_DestinyBondTakesLife: @ 0x82893C6
	.include "data/scripts/gUnknown_82893C6.inc"

	.globl BattleScript_SpikesOnAttacker
BattleScript_SpikesOnAttacker: @ 0x82893E1
	.include "data/scripts/gUnknown_82893E1.inc"

	.globl BattleScript_SpikesOnTarget
BattleScript_SpikesOnTarget: @ 0x8289418
	.include "data/scripts/gUnknown_8289418.inc"

	.globl BattleScript_SpikesOnFaintedBattler
BattleScript_SpikesOnFaintedBattler: @ 0x828944F
	.include "data/scripts/gUnknown_828944F.inc"

	.globl BattleScript_PerishSongTakesLife
BattleScript_PerishSongTakesLife: @ 0x828948D
	.include "data/scripts/gUnknown_828948D.inc"

	.globl BattleScript_PerishSongCountGoesDown
BattleScript_PerishSongCountGoesDown: @ 0x82894A8
	.byte 0x10, 0x97, 0x00 @ printstring STRINGID_PKMNPERISHCOUNTFELL
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

	.globl BattleScript_AllStatsUp
BattleScript_AllStatsUp: @ 0x82894AF
	.include "data/scripts/gUnknown_82894AF.inc"

	.globl BattleScript_RapidSpinAway
BattleScript_RapidSpinAway: @ 0x828954B
	.byte 0xBE @ rapidspinfree
	.byte 0x3C @ return

	.globl BattleScript_WrapFree
BattleScript_WrapFree: @ 0x828954D
	.include "data/scripts/gUnknown_828954D.inc"

	.globl BattleScript_LeechSeedFree
BattleScript_LeechSeedFree: @ 0x828955E
	.byte 0x10, 0x9E, 0x00 @ printstring STRINGID_PKMNSHEDLEECHSEED
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

	.globl BattleScript_SpikesFree
BattleScript_SpikesFree: @ 0x8289565
	.byte 0x10, 0x9F, 0x00 @ printstring STRINGID_PKMNBLEWAWAYSPIKES
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

	.globl BattleScript_MonTookFutureAttack
BattleScript_MonTookFutureAttack: @ 0x828956C
	.include "data/scripts/gUnknown_828956C.inc"

	.globl BattleScript_NoMovesLeft
BattleScript_NoMovesLeft: @ 0x82895FA
	.byte 0x11, 0xA8, 0x00 @ printselectionstring STRINGID_PKMNHASNOMOVESLEFT
	.byte 0x44 @ endselectionscript

	.globl BattleScript_SelectingMoveWithNoPP
BattleScript_SelectingMoveWithNoPP: @ 0x82895FE
	.byte 0x11, 0xFF, 0x00 @ printselectionstring STRINGID_NOPPLEFT
	.byte 0x44 @ endselectionscript

	.globl BattleScript_NoPPForMove
BattleScript_NoPPForMove: @ 0x8289602
	.include "data/scripts/gUnknown_8289602.inc"

	.globl BattleScript_SelectingTormentedMove
BattleScript_SelectingTormentedMove: @ 0x8289611
	.byte 0x11, 0xAA, 0x00 @ printselectionstring STRINGID_PKMNCANTUSEMOVETORMENT
	.byte 0x44 @ endselectionscript
	.byte 0x10, 0xAA, 0x00 @ printstring STRINGID_PKMNCANTUSEMOVETORMENT
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto 0x08286FD6

	.globl BattleScript_SelectingTormentedMoveInPalace
BattleScript_SelectingTormentedMoveInPalace: @ 0x8289620
	.byte 0x10, 0xAA, 0x00 @ printstring STRINGID_PKMNCANTUSEMOVETORMENT
	.byte 0x28, 0xB5, 0x93, 0x28, 0x08 @ goto 0x082893B5

	.globl BattleScript_SelectingNotAllowedMoveTaunt
BattleScript_SelectingNotAllowedMoveTaunt: @ 0x8289628
	.byte 0x11, 0xAD, 0x00 @ printselectionstring STRINGID_PKMNCANTUSEMOVETAUNT
	.byte 0x44 @ endselectionscript

	.globl BattleScript_MoveUsedIsTaunted
BattleScript_MoveUsedIsTaunted: @ 0x828962C
	.byte 0x10, 0xAD, 0x00 @ printstring STRINGID_PKMNCANTUSEMOVETAUNT
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto 0x08286FD6

	.globl BattleScript_SelectingNotAllowedMoveTauntInPalace
BattleScript_SelectingNotAllowedMoveTauntInPalace: @ 0x8289637
	.byte 0x10, 0xAD, 0x00 @ printstring STRINGID_PKMNCANTUSEMOVETAUNT
	.byte 0x28, 0xB5, 0x93, 0x28, 0x08 @ goto 0x082893B5

	.globl BattleScript_WishComesTrue
BattleScript_WishComesTrue: @ 0x828963F
	.include "data/scripts/gUnknown_828963F.inc"

	.globl BattleScript_IngrainTurnHeal
BattleScript_IngrainTurnHeal: @ 0x8289676
	.include "data/scripts/gUnknown_8289676.inc"

	.globl BattleScript_AtkDefDown
BattleScript_AtkDefDown: @ 0x828969F
	.include "data/scripts/gUnknown_828969F.inc"

	.globl BattleScript_KnockedOff
BattleScript_KnockedOff: @ 0x82896F0
	.include "data/scripts/gUnknown_82896F0.inc"

	.globl BattleScript_MoveUsedIsImprisoned
BattleScript_MoveUsedIsImprisoned: @ 0x82896FE
	.byte 0x10, 0xBA, 0x00 @ printstring STRINGID_PKMNCANTUSEMOVESEALED
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto 0x08286FD6

	.globl BattleScript_SelectingImprisonedMove
BattleScript_SelectingImprisonedMove: @ 0x8289709
	.byte 0x11, 0xBA, 0x00 @ printselectionstring STRINGID_PKMNCANTUSEMOVESEALED
	.byte 0x44 @ endselectionscript

	.globl BattleScript_SelectingImprisonedMoveInPalace
BattleScript_SelectingImprisonedMoveInPalace: @ 0x828970D
	.byte 0x10, 0xBA, 0x00 @ printstring STRINGID_PKMNCANTUSEMOVESEALED
	.byte 0x28, 0xB5, 0x93, 0x28, 0x08 @ goto 0x082893B5

	.globl BattleScript_GrudgeTakesPP
BattleScript_GrudgeTakesPP: @ 0x8289715
	.byte 0x10, 0xBC, 0x00 @ printstring STRINGID_PKMNLOSTPPGRUDGE
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

	.globl BattleScript_MagicCoatBounce
BattleScript_MagicCoatBounce: @ 0x828971C
	.include "data/scripts/gUnknown_828971C.inc"

	.globl BattleScript_SnatchedMove
BattleScript_SnatchedMove: @ 0x8289734
	.include "data/scripts/gUnknown_8289734.inc"

	.globl BattleScript_EnduredMsg
BattleScript_EnduredMsg: @ 0x828974F
	.byte 0x10, 0x99, 0x00 @ printstring STRINGID_PKMNENDUREDHIT
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

	.globl BattleScript_OneHitKOMsg
BattleScript_OneHitKOMsg: @ 0x8289756
	.byte 0x10, 0xDA, 0x00 @ printstring STRINGID_ONEHITKO
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

	.globl BattleScript_SAtkDown2
BattleScript_SAtkDown2: @ 0x828975D
	.include "data/scripts/gUnknown_828975D.inc"

	.globl BattleScript_FocusPunchSetUp
BattleScript_FocusPunchSetUp: @ 0x8289787
	.include "data/scripts/gUnknown_8289787.inc"

	.globl BattleScript_MoveUsedIsAsleep
BattleScript_MoveUsedIsAsleep: @ 0x828979B
	.include "data/scripts/gUnknown_828979B.inc"

	.globl BattleScript_MoveUsedWokeUp
BattleScript_MoveUsedWokeUp: @ 0x82897A8
	.include "data/scripts/gUnknown_82897A8.inc"

	.globl BattleScript_MonWokeUpInUproar
BattleScript_MonWokeUpInUproar: @ 0x82897BC
	.include "data/scripts/gUnknown_82897BC.inc"

	.globl BattleScript_PoisonTurnDmg
BattleScript_PoisonTurnDmg: @ 0x82897C5
	.include "data/scripts/gUnknown_82897C5.inc"

	.globl BattleScript_BurnTurnDmg
BattleScript_BurnTurnDmg: @ 0x82897E7
	.include "data/scripts/gUnknown_82897E7.inc"

	.globl BattleScript_MoveUsedIsFrozen
BattleScript_MoveUsedIsFrozen: @ 0x82897F2
	.include "data/scripts/gUnknown_82897F2.inc"

	.globl BattleScript_MoveUsedUnfroze
BattleScript_MoveUsedUnfroze: @ 0x82897FF
	.include "data/scripts/gUnknown_82897FF.inc"

	.globl BattleScript_DefrostedViaFireMove
BattleScript_DefrostedViaFireMove: @ 0x828980A
	.include "data/scripts/gUnknown_828980A.inc"

	.globl BattleScript_MoveUsedIsParalyzed
BattleScript_MoveUsedIsParalyzed: @ 0x8289813
	.include "data/scripts/gUnknown_8289813.inc"

	.globl BattleScript_MoveUsedFlinched
BattleScript_MoveUsedFlinched: @ 0x8289823
	.byte 0x10, 0x4A, 0x00 @ printstring STRINGID_PKMNFLINCHED
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto 0x08286FD6

	.globl BattleScript_PrintUproarOverTurns
BattleScript_PrintUproarOverTurns: @ 0x828982E
	.byte 0x13, 0xF2, 0xB9, 0x5A, 0x08 @ printfromtable 0x085AB9F2
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

	.globl BattleScript_ThrashConfuses
BattleScript_ThrashConfuses: @ 0x8289837
	.include "data/scripts/gUnknown_8289837.inc"

	.globl BattleScript_MoveUsedIsConfused
BattleScript_MoveUsedIsConfused: @ 0x8289845
	.include "data/scripts/gUnknown_8289845.inc"

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
	.include "data/scripts/gUnknown_8289896.inc"

	.globl BattleScript_WrapEnds
BattleScript_WrapEnds: @ 0x82898A8
	.byte 0x10, 0x5F, 0x00 @ printstring STRINGID_PKMNFREEDFROM
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2

	.globl BattleScript_MoveUsedIsInLove
BattleScript_MoveUsedIsInLove: @ 0x82898AF
	.include "data/scripts/gUnknown_82898AF.inc"

	.globl BattleScript_MoveUsedIsInLoveCantAttack
BattleScript_MoveUsedIsInLoveCantAttack: @ 0x82898BC
	.byte 0x10, 0x47, 0x00 @ printstring STRINGID_PKMNIMMOBILIZEDBYLOVE
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x28, 0xD6, 0x6F, 0x28, 0x08 @ goto 0x08286FD6

	.globl BattleScript_NightmareTurnDmg
BattleScript_NightmareTurnDmg: @ 0x82898C7
	.include "data/scripts/gUnknown_82898C7.inc"

	.globl BattleScript_CurseTurnDmg
BattleScript_CurseTurnDmg: @ 0x82898D8
	.include "data/scripts/gUnknown_82898D8.inc"

	.globl BattleScript_TargetPRLZHeal
BattleScript_TargetPRLZHeal: @ 0x82898E9
	.include "data/scripts/gUnknown_82898E9.inc"

	.globl BattleScript_YawnMakesAsleep
BattleScript_YawnMakesAsleep: @ 0x8289900
	.include "data/scripts/gUnknown_8289900.inc"

	.globl BattleScript_ItemSteal
BattleScript_ItemSteal: @ 0x82899AA
	.include "data/scripts/gUnknown_82899AA.inc"

	.globl BattleScript_DrizzleActivates
BattleScript_DrizzleActivates: @ 0x82899B8
	.include "data/scripts/gUnknown_82899B8.inc"

	.globl BattleScript_SpeedBoostActivates
BattleScript_SpeedBoostActivates: @ 0x82899CC
	.include "data/scripts/gUnknown_82899CC.inc"

	.globl BattleScript_TraceActivates
BattleScript_TraceActivates: @ 0x82899DA
	.include "data/scripts/gUnknown_82899DA.inc"

	.globl BattleScript_RainDishActivates
BattleScript_RainDishActivates: @ 0x82899E4
	.include "data/scripts/gUnknown_82899E4.inc"

	.globl BattleScript_SandstreamActivates
BattleScript_SandstreamActivates: @ 0x82899F8
	.include "data/scripts/gUnknown_82899F8.inc"

	.globl BattleScript_ShedSkinActivates
BattleScript_ShedSkinActivates: @ 0x8289A0C
	.include "data/scripts/gUnknown_8289A0C.inc"

	.globl BattleScript_CastformChange
BattleScript_CastformChange: @ 0x8289A31
	.byte 0x41, 0x37, 0x9A, 0x28, 0x08 @ call 0x08289A37
	.byte 0x3F @ end3
	.byte 0xE6 @ docastformchangeanimation
	.byte 0x3A @ waitstate
	.byte 0x10, 0x3A, 0x01 @ printstring STRINGID_PKMNTRANSFORMED
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3C @ return

	.globl BattleScript_IntimidateActivatesEnd3
BattleScript_IntimidateActivatesEnd3: @ 0x8289A40
	.include "data/scripts/gUnknown_8289A40.inc"

	.globl BattleScript_IntimidateActivates
BattleScript_IntimidateActivates: @ 0x8289A49
	.include "data/scripts/gUnknown_8289A49.inc"

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
