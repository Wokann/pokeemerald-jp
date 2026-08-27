
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

	@ Reviewed semantic names for shared event/text entries that still live
	@ inside retained JP blocks.  Keeping these aliases in the owning event
	@ object lets map sources use the same names as pokeemerald without moving
	@ or duplicating any ROM bytes.
	@ Verdanturf Battle Tent Lobby shares these retained JP text/script blocks.
	@ The local map source therefore keeps the pokeemerald semantic labels.
	@ Mauville's dynamic old-man interaction remains in its retained JP owner.
	@ Expose the map-local pokeemerald label for generated object events.
	.globl MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan
	.set MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan, 0x08254D6B
	@ The Rollout tutor remains in the retained shared move-tutor byte block.
	@ Export its pokeemerald map-event label without relocating the JP bytes.
	.globl MauvilleCity_EventScript_RolloutTutor
	.set MauvilleCity_EventScript_RolloutTutor, 0x0827689A
	@ Shared Battle Tent text remains in its existing JP byte owners; expose
	@ the matching US semantic labels for Slateport's map scripts.
	.globl SlateportCity_BattleTentLobby_Text_WelcomeToBattleTent
	.set SlateportCity_BattleTentLobby_Text_WelcomeToBattleTent, 0x08275307
	.globl SlateportCity_BattleTentLobby_Text_TakeChallenge
	.set SlateportCity_BattleTentLobby_Text_TakeChallenge, 0x08275335
	.globl SlateportCity_BattleTentLobby_Text_ExplainSlateportTent
	.set SlateportCity_BattleTentLobby_Text_ExplainSlateportTent, 0x0827534A
	.globl SlateportCity_BattleTentLobby_Text_LookForwardToNextVisit
	.set SlateportCity_BattleTentLobby_Text_LookForwardToNextVisit, 0x0827549D
	.globl SlateportCity_BattleTentLobby_Text_StepThisWay
	.set SlateportCity_BattleTentLobby_Text_StepThisWay, 0x08275515
	.globl SlateportCity_BattleTentLobby_Text_ReturnRentalMonsSaveResults
	.set SlateportCity_BattleTentLobby_Text_ReturnRentalMonsSaveResults, 0x08275524
	.globl SlateportCity_BattleTentLobby_Text_WonThreeMatchesReturnMons
	.set SlateportCity_BattleTentLobby_Text_WonThreeMatchesReturnMons, 0x08275596
	.globl SlateportCity_BattleTentLobby_Text_AwardYouThisPrize
	.set SlateportCity_BattleTentLobby_Text_AwardYouThisPrize, 0x082755EC
	.globl SlateportCity_BattleTentLobby_Text_NoRoomInBagMakeRoom
	.set SlateportCity_BattleTentLobby_Text_NoRoomInBagMakeRoom, 0x08275607
	.globl SlateportCity_BattleTentLobby_Text_BeenWaitingForYou
	.set SlateportCity_BattleTentLobby_Text_BeenWaitingForYou, 0x08275634
	.globl SlateportCity_BattleTentLobby_Text_DidntSaveBeforeQuitting
	.set SlateportCity_BattleTentLobby_Text_DidntSaveBeforeQuitting, 0x08275660
	.globl SlateportCity_BattleTentLobby_Text_SaveBeforeChallenge
	.set SlateportCity_BattleTentLobby_Text_SaveBeforeChallenge, 0x082754D7
	.globl SlateportCity_BattleTentLobby_Text_ExplainBasicRules
	.set SlateportCity_BattleTentLobby_Text_ExplainBasicRules, 0x082756F3
	.globl SlateportCity_BattleTentLobby_Text_ExplainSwapPartnerRules
	.set SlateportCity_BattleTentLobby_Text_ExplainSwapPartnerRules, 0x08275757
	.globl SlateportCity_BattleTentLobby_Text_ExplainSwapNumberRules
	.set SlateportCity_BattleTentLobby_Text_ExplainSwapNumberRules, 0x082757A8
	.globl SlateportCity_BattleTentLobby_Text_ExplainSwapNotes
	.set SlateportCity_BattleTentLobby_Text_ExplainSwapNotes, 0x08275803
	.globl SlateportCity_BattleTentLobby_Text_ExplainMonRules
	.set SlateportCity_BattleTentLobby_Text_ExplainMonRules, 0x0827589C
	@ Fallarbor's Battle Tent lobby references retained text in the same shared
	@ JP owner.  These names mirror the matching pokeemerald lobby source.
	.globl FallarborTown_BattleTentLobby_Text_WelcomeToBattleTent
	.set FallarborTown_BattleTentLobby_Text_WelcomeToBattleTent, 0x08274A30
	.globl FallarborTown_BattleTentLobby_Text_TakeChallenge
	.set FallarborTown_BattleTentLobby_Text_TakeChallenge, 0x08274A71
	.globl FallarborTown_BattleTentLobby_Text_AwaitAnotherChallenge
	.set FallarborTown_BattleTentLobby_Text_AwaitAnotherChallenge, 0x08274A8B
	.globl FallarborTown_BattleTentLobby_Text_ExplainFallarborTent
	.set FallarborTown_BattleTentLobby_Text_ExplainFallarborTent, 0x08274AA3
	.globl FallarborTown_BattleTentLobby_Text_SaveBeforeChallenge
	.set FallarborTown_BattleTentLobby_Text_SaveBeforeChallenge, 0x08274C14
	.globl FallarborTown_BattleTentLobby_Text_SelectThreeMons
	.set FallarborTown_BattleTentLobby_Text_SelectThreeMons, 0x08274C64
	.globl FallarborTown_BattleTentLobby_Text_NotEnoughValidMonsLv50
	.set FallarborTown_BattleTentLobby_Text_NotEnoughValidMonsLv50, 0x08274C84
	.globl FallarborTown_BattleTentLobby_Text_NotEnoughValidMonsLvOpen
	.set FallarborTown_BattleTentLobby_Text_NotEnoughValidMonsLvOpen, 0x08274CFD
	.globl FallarborTown_BattleTentLobby_Text_GuideYouToBattleTent
	.set FallarborTown_BattleTentLobby_Text_GuideYouToBattleTent, 0x08274DA3
	.globl FallarborTown_BattleTentLobby_Text_DidntSaveBeforeQuitting
	.set FallarborTown_BattleTentLobby_Text_DidntSaveBeforeQuitting, 0x08274DB9
	.globl FallarborTown_BattleTentLobby_Text_BeatThreeTrainers
	.set FallarborTown_BattleTentLobby_Text_BeatThreeTrainers, 0x08274E1B
	.globl FallarborTown_BattleTentLobby_Text_WaitWhileSaveGame
	.set FallarborTown_BattleTentLobby_Text_WaitWhileSaveGame, 0x08274E34
	.globl FallarborTown_BattleTentLobby_Text_PresentYouWithPrize
	.set FallarborTown_BattleTentLobby_Text_PresentYouWithPrize, 0x08274E4A
	.globl FallarborTown_BattleTentLobby_Text_ReceivedPrize
	.set FallarborTown_BattleTentLobby_Text_ReceivedPrize, 0x08274E74
	.globl FallarborTown_BattleTentLobby_Text_BagFullReturnForPrize
	.set FallarborTown_BattleTentLobby_Text_BagFullReturnForPrize, 0x08274E82
	.globl FallarborTown_BattleTentLobby_Text_ThankYouWaitWhileSaving
	.set FallarborTown_BattleTentLobby_Text_ThankYouWaitWhileSaving, 0x08274EB4
	.globl FallarborTown_BattleTentLobby_Text_AwaitAnotherChallenge2
	.set FallarborTown_BattleTentLobby_Text_AwaitAnotherChallenge2, 0x08274ED5
	.globl FallarborTown_BattleTentLobby_Text_LookingForwardToArrival
	.set FallarborTown_BattleTentLobby_Text_LookingForwardToArrival, 0x08274EED
	.globl BattleFrontier_BattleArenaLobby_Text_RulesAreListed
	.set BattleFrontier_BattleArenaLobby_Text_RulesAreListed, 0x0822FD87
	.globl BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	.set BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading, 0x0822FDA0
	.globl BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules
	.set BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, 0x0822FDB0
	.globl BattleFrontier_BattleArenaLobby_Text_ExplainMindRules
	.set BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, 0x0822FE72
	.globl BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules
	.set BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, 0x0822FECB
	.globl BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules
	.set BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, 0x0822FFB6
	@ The Slateport Tent corridor reuses retained Battle Factory pre-battle
	@ text blocks. Keep their US semantic names without moving their JP bytes.
	.globl BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection
	.set BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, 0x082323B3
	.globl BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons
	.set BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, 0x082323F8
	.globl BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	.set BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent, 0x08232415
	.globl BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	.set BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent, 0x08232433
	.globl BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame
	.set BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, 0x082324CA
	.globl BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	.set BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge, 0x082324E3
	.globl BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon
	.set BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, 0x08232839
	.globl BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete
	.set BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, 0x0823285F
	.globl BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay
	.set BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, 0x0823287D
	.globl BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	.set BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait, 0x0823288B
	@ These Fan Club object scripts remain in their existing shared JP owners.
	.globl SlateportCity_PokemonFanClub_EventScript_Reporter
	.set SlateportCity_PokemonFanClub_EventScript_Reporter, 0x08253D5B
	.globl SlateportCity_OceanicMuseum_1F_EventScript_Reporter
	.set SlateportCity_OceanicMuseum_1F_EventScript_Reporter, 0x08253C9B
	.globl SlateportCity_PokemonFanClub_EventScript_SwaggerTutor
	.set SlateportCity_PokemonFanClub_EventScript_SwaggerTutor, 0x08276832
	.globl BattleFrontier_BattleTowerLobby_Text_ReceivedPrize
	.set BattleFrontier_BattleTowerLobby_Text_ReceivedPrize, 0x0822064B
	.globl BattleFrontier_BattleDomeLobby_Text_ReceivedPrize
	.set BattleFrontier_BattleDomeLobby_Text_ReceivedPrize, 0x08227865
	.globl BattleTentLobby_Text_ExplainLevelRules
	.set BattleTentLobby_Text_ExplainLevelRules, 0x08275BCD
	.globl VerdanturfTown_BattleTentLobby_Text_AchievedThreeWinStreak
	.set VerdanturfTown_BattleTentLobby_Text_AchievedThreeWinStreak, 0x082752A6
	.globl VerdanturfTown_BattleTentLobby_Text_FeatWillBeRecorded
	.set VerdanturfTown_BattleTentLobby_Text_FeatWillBeRecorded, 0x082752D8
	.globl VerdanturfTown_BattleTentLobby_Text_PresentYouWithPrize
	.set VerdanturfTown_BattleTentLobby_Text_PresentYouWithPrize, 0x082752ED
	.globl VerdanturfTown_BattleTentLobby_Text_ReturnFortified
	.set VerdanturfTown_BattleTentLobby_Text_ReturnFortified, 0x082750A3
	.globl VerdanturfTown_BattleTentLobby_Text_ResultsWillBeRecorded
	.set VerdanturfTown_BattleTentLobby_Text_ResultsWillBeRecorded, 0x0827527B
	.globl VerdanturfTown_BattleTentLobby_Text_WelcomeToBattleTent
	.set VerdanturfTown_BattleTentLobby_Text_WelcomeToBattleTent, 0x08274F21
	.globl VerdanturfTown_BattleTentLobby_Text_TakeChallenge
	.set VerdanturfTown_BattleTentLobby_Text_TakeChallenge, 0x08274F55
	.globl VerdanturfTown_BattleTentLobby_Text_ExplainVerdanturfTent
	.set VerdanturfTown_BattleTentLobby_Text_ExplainVerdanturfTent, 0x08274F71
	.globl VerdanturfTown_BattleTentLobby_Text_SelectThreeMons
	.set VerdanturfTown_BattleTentLobby_Text_SelectThreeMons, 0x0827522E
	.globl VerdanturfTown_BattleTentLobby_Text_SaveBeforeChallenge
	.set VerdanturfTown_BattleTentLobby_Text_SaveBeforeChallenge, 0x0827524A
	.globl VerdanturfTown_BattleTentLobby_Text_NowFollowMe
	.set VerdanturfTown_BattleTentLobby_Text_NowFollowMe, 0x0827526A
	.globl VerdanturfTown_BattleTentLobby_Text_NotEnoughValidMonsLv50
	.set VerdanturfTown_BattleTentLobby_Text_NotEnoughValidMonsLv50, 0x082750F0
	.globl VerdanturfTown_BattleTentLobby_Text_NotEnoughValidMonsLvOpen
	.set VerdanturfTown_BattleTentLobby_Text_NotEnoughValidMonsLvOpen, 0x0827518F
	.globl VerdanturfTown_BattleTentLobby_Text_RulesAreListed
	.set VerdanturfTown_BattleTentLobby_Text_RulesAreListed, 0x08275C42
	@ The Verdanturf Pokémon Center references the retained Fury Cutter tutor.
	.globl VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor
	.set VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor, 0x08276902
	@ The Pacifidlog Pokémon Center references the retained Explosion tutor.
	.globl PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor
	.set PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor, 0x08276BDA
	@ The Mossdeep event table references the retained DynamicPunch tutor script.
	.globl MossdeepCity_EventScript_DynamicPunchTutor
	.set MossdeepCity_EventScript_DynamicPunchTutor, 0x08276B0A
	.globl ProfBirch_EventScript_RatePokedexOrRegister
	.set ProfBirch_EventScript_RatePokedexOrRegister, 0x082431CD
	@ Champion-room story code calls this retained standalone Pokédex rating branch.
	.globl ProfBirch_EventScript_RatePokedex
	.set ProfBirch_EventScript_RatePokedex, 0x08243207
	@ The four-step shared player approach remains in the retained movement block.
	.globl Common_Movement_WalkUp4
	.set Common_Movement_WalkUp4, 0x08243644
	.globl gText_PokemonTrainerSchoolEmail
	.set gText_PokemonTrainerSchoolEmail, 0x08243AA2
	.globl gText_PlayerHouseBootPC
	.set gText_PlayerHouseBootPC, 0x08243B10
	@ The Rooftop event table points to the retained Substitute tutor script.
	.globl LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTutor
	.set LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTutor, 0x08276AA2
	@ The Sootopolis Center event table points to the retained Double-Edge tutor script.
	.globl SootopolisCity_PokemonCenter_1F_EventScript_DoubleEdgeTutor
	.set SootopolisCity_PokemonCenter_1F_EventScript_DoubleEdgeTutor, 0x08276B72
	.globl gText_ComeBackWithSecretPower
	.set gText_ComeBackWithSecretPower, 0x08243B96
	@ Space Center 2F's post-battle calls target retained Match Call text.
	.globl MatchCall_Text_MayRayquazaCall
	.set MatchCall_Text_MayRayquazaCall, 0x0826AB1B
	.globl MatchCall_Text_BrendanRayquazaCall
	.set MatchCall_Text_BrendanRayquazaCall, 0x0826ABC8
	@ This shared movement stream remains in the retained JP movement block.
	.globl Common_Movement_QuestionMark
	.set Common_Movement_QuestionMark, 0x08243619
	.globl Common_EventScript_UpdateBrineyLocation
	.set Common_EventScript_UpdateBrineyLocation, 0x08242978
	.globl Common_EventScript_PkmnCenterNurse
	.set Common_EventScript_PkmnCenterNurse, 0x082429B8
	.globl ProfileMan_EventScript_Man
	.set ProfileMan_EventScript_Man, 0x08257290
	.globl PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
	.set PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet, 0x08257EE8
	.globl PlayersHouse_1F_EventScript_EnterHouseMovingIn
	.set PlayersHouse_1F_EventScript_EnterHouseMovingIn, 0x08257EEE
	.globl PlayersHouse_1F_EventScript_MomGoSeeRoom
	.set PlayersHouse_1F_EventScript_MomGoSeeRoom, 0x08257F4F
	.globl LittlerootTown_BrendansHouse_2F_EventScript_WallClock
	.set LittlerootTown_BrendansHouse_2F_EventScript_WallClock, 0x08257F6B
	.globl LittlerootTown_MaysHouse_2F_EventScript_WallClock
	.set LittlerootTown_MaysHouse_2F_EventScript_WallClock, 0x08257F77
	.globl PlayersHouse_1F_EventScript_PetalburgGymReportMale
	.set PlayersHouse_1F_EventScript_PetalburgGymReportMale, 0x08258057
	.globl PlayersHouse_1F_EventScript_PetalburgGymReportFemale
	.set PlayersHouse_1F_EventScript_PetalburgGymReportFemale, 0x082580C6
	.globl PlayersHouse_1F_EventScript_Mom
	.set PlayersHouse_1F_EventScript_Mom, 0x082581AF
	.globl PlayersHouse_1F_EventScript_Vigoroth1
	.set PlayersHouse_1F_EventScript_Vigoroth1, 0x082582A4
	.globl PlayersHouse_1F_EventScript_Vigoroth2
	.set PlayersHouse_1F_EventScript_Vigoroth2, 0x082582B7
	.globl PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.set PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV, 0x082582DC
	.globl MatchCall_Text_BirchRegisterCall
	.set MatchCall_Text_BirchRegisterCall, 0x0826C1AF
	.globl MatchCall_Text_RegisteredBirch
	.set MatchCall_Text_RegisteredBirch, 0x0826C23E

	.set ALLOCATE_SCRIPT_CMD_TABLE, 1
	.include "data/script_cmd_table.inc"

gSpecialVars:: @ 0x81DAF34
	.4byte 0x02037278, 0x0203727A, 0x0203727C, 0x0203727E
	.4byte 0x02037280, 0x02037282, 0x02037284, 0x02037286
	.4byte 0x02037288, 0x0203728A, 0x0203728C, 0x0203728E
	.4byte 0x02037294, 0x02037290, 0x0203CB48, 0x02037292
	.4byte 0x02039BCE, 0x02039BCC, 0x02037296, 0x02037298
	.4byte 0x0203729A, 0x0203886A

	.set ALLOCATE_SPECIAL_TABLE, 1
	.include "data/specials.inc"

gStdScripts:: @ 0x81DB7BC
	.4byte Std_ObtainItem              @ STD_OBTAIN_ITEM
	.4byte Std_FindItem                @ STD_FIND_ITEM
	.4byte Std_MsgboxNPC               @ MSGBOX_NPC
	.4byte Std_MsgboxSign              @ MSGBOX_SIGN
	.4byte Std_MsgboxDefault           @ MSGBOX_DEFAULT
	.4byte Std_MsgboxYesNo             @ MSGBOX_YESNO
	.4byte Std_MsgboxAutoclose         @ MSGBOX_AUTOCLOSE
	.4byte Std_ObtainDecoration        @ STD_OBTAIN_DECORATION
	.4byte Std_RegisteredInMatchCall   @ STD_REGISTER_MATCH_CALL
	.4byte Std_MsgboxGetPoints         @ MSGBOX_GETPOINTS
	.4byte Std_MsgboxPokenav           @ MSGBOX_POKENAV
gStdScripts_End:: @ 0x81DB7E8
	.include "data/maps/PetalburgCity/scripts.inc"
	.include "data/maps/SlateportCity/scripts.inc"
	.include "data/maps/MauvilleCity/scripts.inc"
	.include "data/maps/RustboroCity/scripts.inc"
	.include "data/maps/FortreeCity/scripts.inc"
	.include "data/maps/LilycoveCity/scripts.inc"
	.include "data/maps/MossdeepCity/scripts.inc"
	.include "data/maps/SootopolisCity/scripts.inc"
	.include "data/maps/EverGrandeCity/scripts.inc"
	.include "data/maps/LittlerootTown/scripts.inc"
	.include "data/maps/OldaleTown/scripts.inc"
	.include "data/maps/DewfordTown/scripts.inc"
	.include "data/maps/LavaridgeTown/scripts.inc"
	.include "data/maps/FallarborTown/scripts.inc"
	.include "data/maps/VerdanturfTown/scripts.inc"
	.include "data/maps/PacifidlogTown/scripts.inc"
	.include "data/maps/Route101/scripts.inc"
	.include "data/maps/Route102/scripts.inc"
	.include "data/maps/Route103/scripts.inc"
	.include "data/maps/Route104/scripts.inc"
	.include "data/maps/Route105/scripts.inc"
	.include "data/maps/Route106/scripts.inc"
	.include "data/maps/Route107/scripts.inc"
	.include "data/maps/Route108/scripts.inc"
	.include "data/maps/Route109/scripts.inc"
	.include "data/maps/Route110/scripts.inc"
	.include "data/maps/Route111/scripts.inc"
	.include "data/maps/Route112/scripts.inc"
	.include "data/maps/Route113/scripts.inc"
	.include "data/maps/Route114/scripts.inc"
	.include "data/maps/Route115/scripts.inc"
	.include "data/maps/Route116/scripts.inc"
	.include "data/maps/Route117/scripts.inc"
	.include "data/maps/Route118/scripts.inc"
	.include "data/maps/Route119/scripts.inc"
	.include "data/maps/Route120/scripts.inc"
	.include "data/maps/Route121/scripts.inc"
	.include "data/maps/Route122/scripts.inc"
	.include "data/maps/Route123/scripts.inc"
	.include "data/maps/Route124/scripts.inc"
	.include "data/maps/Route125/scripts.inc"
	.include "data/maps/Route126/scripts.inc"
	.include "data/maps/Route127/scripts.inc"
	.include "data/maps/Route128/scripts.inc"
	.include "data/maps/Route129/scripts.inc"
	.include "data/maps/Route130/scripts.inc"
	.include "data/maps/Route131/scripts.inc"
	.include "data/maps/Route132/scripts.inc"
	.include "data/maps/Route133/scripts.inc"
	.include "data/maps/Route134/scripts.inc"
	.include "data/maps/Underwater_Route124/scripts.inc"
	.include "data/maps/Underwater_Route126/scripts.inc"
	.include "data/maps/Underwater_Route127/scripts.inc"
	.include "data/maps/Underwater_Route128/scripts.inc"
	.include "data/maps/Underwater_Route129/scripts.inc"
	.include "data/maps/Underwater_Route105/scripts.inc"
	.include "data/maps/Underwater_Route125/scripts.inc"
	.include "data/maps/LittlerootTown_BrendansHouse_1F/scripts.inc"
	.include "data/maps/LittlerootTown_BrendansHouse_2F/scripts.inc"
	.include "data/maps/LittlerootTown_MaysHouse_1F/scripts.inc"
	.include "data/maps/LittlerootTown_MaysHouse_2F/scripts.inc"
	.include "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.inc"
	.include "data/maps/OldaleTown_House1/scripts.inc"
	.include "data/maps/OldaleTown_House2/scripts.inc"
	.include "data/maps/OldaleTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/OldaleTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/OldaleTown_Mart/scripts.inc"
	.include "data/maps/DewfordTown_House1/scripts.inc"
	.include "data/maps/DewfordTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/DewfordTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/DewfordTown_Gym/scripts.inc"
	.include "data/maps/DewfordTown_Hall/scripts.inc"
	.include "data/maps/DewfordTown_House2/scripts.inc"
	.include "data/maps/LavaridgeTown_HerbShop/scripts.inc"
	.include "data/maps/LavaridgeTown_Gym_1F/scripts.inc"
	.include "data/maps/LavaridgeTown_Gym_B1F/scripts.inc"
	.include "data/maps/LavaridgeTown_House/scripts.inc"
	.include "data/maps/LavaridgeTown_Mart/scripts.inc"
	.include "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/LavaridgeTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/FallarborTown_Mart/scripts.inc"
	.include "data/maps/FallarborTown_BattleTentLobby/scripts.inc"
	.include "data/maps/FallarborTown_BattleTentCorridor/scripts.inc"
	.include "data/maps/FallarborTown_BattleTentBattleRoom/scripts.inc"
	.include "data/maps/FallarborTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/FallarborTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/FallarborTown_CozmosHouse/scripts.inc"
	.include "data/maps/FallarborTown_MoveRelearnersHouse/scripts.inc"
	.include "data/maps/VerdanturfTown_BattleTentLobby/scripts.inc"
	.include "data/maps/VerdanturfTown_BattleTentCorridor/scripts.inc"
	.include "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.inc"
	.include "data/maps/VerdanturfTown_Mart/scripts.inc"
	.include "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/VerdanturfTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/VerdanturfTown_WandasHouse/scripts.inc"
	.include "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.inc"
	.include "data/maps/VerdanturfTown_House/scripts.inc"
	.include "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/PacifidlogTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/PacifidlogTown_House1/scripts.inc"
	.include "data/maps/PacifidlogTown_House2/scripts.inc"
	.include "data/maps/PacifidlogTown_House3/scripts.inc"
	.include "data/maps/PacifidlogTown_House4/scripts.inc"
	.include "data/maps/PacifidlogTown_House5/scripts.inc"
	.include "data/maps/PetalburgCity_WallysHouse/scripts.inc"
	.include "data/maps/PetalburgCity_Gym/scripts.inc"
	.include "data/maps/PetalburgCity_House1/scripts.inc"
	.include "data/maps/PetalburgCity_House2/scripts.inc"
	.include "data/maps/PetalburgCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/PetalburgCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/PetalburgCity_Mart/scripts.inc"
	.include "data/maps/SlateportCity_SternsShipyard_1F/scripts.inc"
	.include "data/maps/SlateportCity_SternsShipyard_2F/scripts.inc"
	.include "data/maps/SlateportCity_BattleTentLobby/scripts.inc"
	.include "data/maps/SlateportCity_BattleTentCorridor/scripts.inc"
	.include "data/maps/SlateportCity_BattleTentBattleRoom/scripts.inc"
	.include "data/maps/SlateportCity_NameRatersHouse/scripts.inc"
	.include "data/maps/SlateportCity_PokemonFanClub/scripts.inc"
	.include "data/maps/SlateportCity_OceanicMuseum_1F/scripts.inc"
	.include "data/maps/SlateportCity_OceanicMuseum_2F/scripts.inc"
	.include "data/maps/SlateportCity_Harbor/scripts.inc"
	.include "data/maps/SlateportCity_House/scripts.inc"
	.include "data/maps/SlateportCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/SlateportCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/SlateportCity_Mart/scripts.inc"
	.include "data/maps/MauvilleCity_Gym/scripts.inc"
	.include "data/maps/MauvilleCity_BikeShop/scripts.inc"
	.include "data/maps/MauvilleCity_House1/scripts.inc"
	.include "data/maps/MauvilleCity_GameCorner/scripts.inc"
	.include "data/maps/MauvilleCity_House2/scripts.inc"
	.include "data/maps/MauvilleCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/MauvilleCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/MauvilleCity_Mart/scripts.inc"
	.include "data/maps/RustboroCity_DevonCorp_1F/scripts.inc"
	.include "data/maps/RustboroCity_DevonCorp_2F/scripts.inc"
	.include "data/maps/RustboroCity_DevonCorp_3F/scripts.inc"
	.include "data/maps/RustboroCity_Gym/scripts.inc"
	.include "data/maps/RustboroCity_PokemonSchool/scripts.inc"
	.include "data/maps/RustboroCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/RustboroCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/RustboroCity_Mart/scripts.inc"
	.include "data/maps/RustboroCity_Flat1_1F/scripts.inc"
	.include "data/maps/RustboroCity_Flat1_2F/scripts.inc"
	.include "data/maps/RustboroCity_House1/scripts.inc"
	.include "data/maps/RustboroCity_CuttersHouse/scripts.inc"
	.include "data/maps/RustboroCity_House2/scripts.inc"
	.include "data/maps/RustboroCity_Flat2_1F/scripts.inc"
	.include "data/maps/RustboroCity_Flat2_2F/scripts.inc"
	.include "data/maps/RustboroCity_Flat2_3F/scripts.inc"
	.include "data/maps/RustboroCity_House3/scripts.inc"
	.include "data/maps/FortreeCity_House1/scripts.inc"
	.include "data/maps/FortreeCity_Gym/scripts.inc"
	.include "data/maps/FortreeCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/FortreeCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/FortreeCity_Mart/scripts.inc"
	.include "data/maps/FortreeCity_House2/scripts.inc"
	.include "data/maps/FortreeCity_House3/scripts.inc"
	.include "data/maps/FortreeCity_House4/scripts.inc"
	.include "data/maps/FortreeCity_House5/scripts.inc"
	.include "data/maps/FortreeCity_DecorationShop/scripts.inc"
	.include "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.inc"
	.include "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.inc"
	.include "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.inc"
	.include "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.inc"
	.include "data/maps/LilycoveCity_ContestLobby/scripts.inc"
	.include "data/maps/LilycoveCity_ContestHall/scripts.inc"
	.include "data/maps/LilycoveCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/LilycoveCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/LilycoveCity_UnusedMart/scripts.inc"
	.include "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.inc"
	.include "data/maps/LilycoveCity_Harbor/scripts.inc"
	.include "data/maps/LilycoveCity_MoveDeletersHouse/scripts.inc"
	.include "data/maps/LilycoveCity_House1/scripts.inc"
	.include "data/maps/LilycoveCity_House2/scripts.inc"
	.include "data/maps/LilycoveCity_House3/scripts.inc"
	.include "data/maps/LilycoveCity_House4/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_1F/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_2F/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_3F/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_4F/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_5F/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.inc"
	.include "data/maps/MossdeepCity_Gym/scripts.inc"
	.include "data/maps/MossdeepCity_House1/scripts.inc"
	.include "data/maps/MossdeepCity_House2/scripts.inc"
	.include "data/maps/MossdeepCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/MossdeepCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/MossdeepCity_Mart/scripts.inc"
	.include "data/maps/MossdeepCity_House3/scripts.inc"
	.include "data/maps/MossdeepCity_StevensHouse/scripts.inc"
	.include "data/maps/MossdeepCity_House4/scripts.inc"
	.include "data/maps/MossdeepCity_SpaceCenter_1F/scripts.inc"
	.include "data/maps/MossdeepCity_SpaceCenter_2F/scripts.inc"
	.include "data/maps/MossdeepCity_GameCorner_1F/scripts.inc"
	.include "data/maps/MossdeepCity_GameCorner_B1F/scripts.inc"
	.include "data/maps/SootopolisCity_Gym_1F/scripts.inc"
	.include "data/maps/SootopolisCity_Gym_B1F/scripts.inc"
	.include "data/maps/SootopolisCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/SootopolisCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/SootopolisCity_Mart/scripts.inc"
	.include "data/maps/SootopolisCity_House1/scripts.inc"
	.include "data/maps/SootopolisCity_House2/scripts.inc"
	.include "data/maps/SootopolisCity_House3/scripts.inc"
	.include "data/maps/SootopolisCity_House4/scripts.inc"
	.include "data/maps/SootopolisCity_House5/scripts.inc"
	.include "data/maps/SootopolisCity_House6/scripts.inc"
	.include "data/maps/SootopolisCity_House7/scripts.inc"
	.include "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.inc"
	.include "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.inc"
	.include "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.inc"
	.include "data/maps/EverGrandeCity_SidneysRoom/scripts.inc"
	.include "data/maps/EverGrandeCity_PhoebesRoom/scripts.inc"
	.include "data/maps/EverGrandeCity_GlaciasRoom/scripts.inc"
	.include "data/maps/EverGrandeCity_DrakesRoom/scripts.inc"
	.include "data/maps/EverGrandeCity_ChampionsRoom/scripts.inc"
	.include "data/maps/EverGrandeCity_Hall1/scripts.inc"
	.include "data/maps/EverGrandeCity_Hall2/scripts.inc"
	.include "data/maps/EverGrandeCity_Hall3/scripts.inc"
	.include "data/maps/EverGrandeCity_Hall4/scripts.inc"
	.include "data/maps/EverGrandeCity_Hall5/scripts.inc"
	.include "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.inc"
	.include "data/maps/EverGrandeCity_HallOfFame/scripts.inc"
	.include "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/EverGrandeCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/EverGrandeCity_PokemonLeague_2F/scripts.inc"
	.include "data/maps/Route104_MrBrineysHouse/scripts.inc"
	.include "data/maps/Route104_PrettyPetalFlowerShop/scripts.inc"
	.include "data/maps/Route111_WinstrateFamilysHouse/scripts.inc"
	.include "data/maps/Route111_OldLadysRestStop/scripts.inc"
	.include "data/maps/Route112_CableCarStation/scripts.inc"
	.include "data/maps/MtChimney_CableCarStation/scripts.inc"
	.include "data/maps/Route114_FossilManiacsHouse/scripts.inc"
	.include "data/maps/Route114_FossilManiacsTunnel/scripts.inc"
	.include "data/maps/Route114_LanettesHouse/scripts.inc"
	.include "data/maps/Route116_TunnelersRestHouse/scripts.inc"
	.include "data/maps/Route117_PokemonDayCare/scripts.inc"
	.include "data/maps/Route121_SafariZoneEntrance/scripts.inc"
	.include "data/maps/MeteorFalls_1F_1R/scripts.inc"
	.include "data/maps/MeteorFalls_1F_2R/scripts.inc"
	.include "data/maps/MeteorFalls_B1F_1R/scripts.inc"
	.include "data/maps/MeteorFalls_B1F_2R/scripts.inc"
	.include "data/maps/RusturfTunnel/scripts.inc"
	.include "data/maps/Underwater_SootopolisCity/scripts.inc"
	.include "data/maps/DesertRuins/scripts.inc"
	.include "data/maps/GraniteCave_1F/scripts.inc"
	.include "data/maps/GraniteCave_B1F/scripts.inc"
	.include "data/maps/GraniteCave_B2F/scripts.inc"
	.include "data/maps/GraniteCave_StevensRoom/scripts.inc"
	.include "data/maps/PetalburgWoods/scripts.inc"
	.include "data/maps/MtChimney/scripts.inc"
	.include "data/maps/JaggedPass/scripts.inc"
	.include "data/maps/FieryPath/scripts.inc"
	.include "data/maps/MtPyre_1F/scripts.inc"
	.include "data/maps/MtPyre_2F/scripts.inc"
	.include "data/maps/MtPyre_3F/scripts.inc"
	.include "data/maps/MtPyre_4F/scripts.inc"
	.include "data/maps/MtPyre_5F/scripts.inc"
	.include "data/maps/MtPyre_6F/scripts.inc"
	.include "data/maps/MtPyre_Exterior/scripts.inc"
	.include "data/maps/MtPyre_Summit/scripts.inc"
	.include "data/maps/AquaHideout_1F/scripts.inc"
	.include "data/maps/AquaHideout_B1F/scripts.inc"
	.include "data/maps/AquaHideout_B2F/scripts.inc"
	.include "data/maps/Underwater_SeafloorCavern/scripts.inc"
	.include "data/maps/SeafloorCavern_Entrance/scripts.inc"
	.include "data/maps/SeafloorCavern_Room1/scripts.inc"
	.include "data/maps/SeafloorCavern_Room2/scripts.inc"
	.include "data/maps/SeafloorCavern_Room3/scripts.inc"
	.include "data/maps/SeafloorCavern_Room4/scripts.inc"
	.include "data/maps/SeafloorCavern_Room5/scripts.inc"
	.include "data/maps/SeafloorCavern_Room6/scripts.inc"
	.include "data/maps/SeafloorCavern_Room7/scripts.inc"
	.include "data/maps/SeafloorCavern_Room8/scripts.inc"
	.include "data/maps/SeafloorCavern_Room9/scripts.inc"
	.include "data/maps/CaveOfOrigin_Entrance/scripts.inc"
	.include "data/maps/CaveOfOrigin_1F/scripts.inc"
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.inc"
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.inc"
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.inc"
	.include "data/maps/CaveOfOrigin_B1F/scripts.inc"
	.include "data/maps/VictoryRoad_1F/scripts.inc"
	.include "data/maps/VictoryRoad_B1F/scripts.inc"
	.include "data/maps/VictoryRoad_B2F/scripts.inc"
	.include "data/maps/ShoalCave_LowTideEntranceRoom/scripts.inc"
	.include "data/maps/ShoalCave_LowTideInnerRoom/scripts.inc"
	.include "data/maps/ShoalCave_LowTideStairsRoom/scripts.inc"
	.include "data/maps/ShoalCave_LowTideLowerRoom/scripts.inc"
	.include "data/maps/ShoalCave_HighTideEntranceRoom/scripts.inc"
	.include "data/maps/ShoalCave_HighTideInnerRoom/scripts.inc"
	.include "data/maps/NewMauville_Entrance/scripts.inc"
	.include "data/maps/NewMauville_Inside/scripts.inc"
	.include "data/maps/AbandonedShip_Deck/scripts.inc"
	.include "data/maps/AbandonedShip_Corridors_1F/scripts.inc"
	.include "data/maps/AbandonedShip_Rooms_1F/scripts.inc"
	.include "data/maps/AbandonedShip_Corridors_B1F/scripts.inc"
	.include "data/maps/AbandonedShip_Rooms_B1F/scripts.inc"
	.include "data/maps/AbandonedShip_Rooms2_B1F/scripts.inc"
	.include "data/maps/AbandonedShip_Underwater1/scripts.inc"
	.include "data/maps/AbandonedShip_Room_B1F/scripts.inc"
	.include "data/maps/AbandonedShip_Rooms2_1F/scripts.inc"
	.include "data/maps/AbandonedShip_CaptainsOffice/scripts.inc"
	.include "data/maps/AbandonedShip_Underwater2/scripts.inc"
	.include "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.inc"
	.include "data/maps/AbandonedShip_HiddenFloorRooms/scripts.inc"
	.include "data/maps/IslandCave/scripts.inc"
	.include "data/maps/AncientTomb/scripts.inc"
	.include "data/maps/Underwater_Route134/scripts.inc"
	.include "data/maps/Underwater_SealedChamber/scripts.inc"
	.include "data/maps/SealedChamber_OuterRoom/scripts.inc"
	.include "data/maps/SealedChamber_InnerRoom/scripts.inc"
	.include "data/maps/ScorchedSlab/scripts.inc"
	.include "data/maps/AquaHideout_UnusedRubyMap1/scripts.inc"
	.include "data/maps/AquaHideout_UnusedRubyMap2/scripts.inc"
	.include "data/maps/AquaHideout_UnusedRubyMap3/scripts.inc"
	.include "data/maps/SkyPillar_Entrance/scripts.inc"
	.include "data/maps/SkyPillar_Outside/scripts.inc"
	.include "data/maps/SkyPillar_1F/scripts.inc"
	.include "data/maps/SkyPillar_2F/scripts.inc"
	.include "data/maps/SkyPillar_3F/scripts.inc"
	.include "data/maps/SkyPillar_4F/scripts.inc"
	.include "data/maps/ShoalCave_LowTideIceRoom/scripts.inc"
	.include "data/maps/SkyPillar_5F/scripts.inc"
	.include "data/maps/SkyPillar_Top/scripts.inc"
	.include "data/maps/MagmaHideout_1F/scripts.inc"
	.include "data/maps/MagmaHideout_2F_1R/scripts.inc"
	.include "data/maps/MagmaHideout_2F_2R/scripts.inc"
	.include "data/maps/MagmaHideout_3F_1R/scripts.inc"
	.include "data/maps/MagmaHideout_3F_2R/scripts.inc"
	.include "data/maps/MagmaHideout_4F/scripts.inc"
	.include "data/maps/MagmaHideout_3F_3R/scripts.inc"
	.include "data/maps/MagmaHideout_2F_3R/scripts.inc"
	.include "data/maps/MirageTower_1F/scripts.inc"
	.include "data/maps/MirageTower_2F/scripts.inc"
	.include "data/maps/MirageTower_3F/scripts.inc"
	.include "data/maps/MirageTower_4F/scripts.inc"
	.include "data/maps/DesertUnderpass/scripts.inc"
	.include "data/maps/ArtisanCave_B1F/scripts.inc"
	.include "data/maps/ArtisanCave_1F/scripts.inc"
	.include "data/maps/Underwater_MarineCave/scripts.inc"
	.include "data/maps/MarineCave_Entrance/scripts.inc"
	.include "data/maps/MarineCave_End/scripts.inc"
	.include "data/maps/TerraCave_Entrance/scripts.inc"
	.include "data/maps/TerraCave_End/scripts.inc"
	.include "data/maps/AlteringCave/scripts.inc"
	.include "data/maps/MeteorFalls_StevensCave/scripts.inc"
	.include "data/scripts/shared_secret_base.inc"
	.include "data/maps/BattleColosseum_2P/scripts.inc"
	.include "data/maps/TradeCenter/scripts.inc"
	.include "data/maps/RecordCorner/scripts.inc"
	.include "data/maps/BattleColosseum_4P/scripts.inc"
	.include "data/maps/ContestHall/scripts.inc"
	.include "data/maps/InsideOfTruck/scripts.inc"
	.include "data/maps/SSTidalCorridor/scripts.inc"
	.include "data/maps/SSTidalLowerDeck/scripts.inc"
	.include "data/maps/SSTidalRooms/scripts.inc"
	.include "data/maps/BattlePyramidSquare01/scripts.inc"
	.include "data/maps/UnionRoom/scripts.inc"
	.include "data/maps/SafariZone_Northwest/scripts.inc"
	.include "data/maps/SafariZone_North/scripts.inc"
	.include "data/maps/SafariZone_Southwest/scripts.inc"
	.include "data/maps/SafariZone_South/scripts.inc"
	.include "data/maps/BattleFrontier_OutsideWest/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerElevator/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.inc"
	.include "data/maps/SouthernIsland_Exterior/scripts.inc"
	.include "data/maps/SouthernIsland_Interior/scripts.inc"
	.include "data/maps/SafariZone_RestHouse/scripts.inc"
	.include "data/maps/SafariZone_Northeast/scripts.inc"
	.include "data/maps/SafariZone_Southeast/scripts.inc"
	.include "data/maps/BattleFrontier_OutsideEast/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomeLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomeCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePalaceLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePyramidLobby/scripts.inc"
	@ Battle Pyramid Lobby rule-board texts are physically stored after the map range.
BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
	.string "バトルアドベンチャーの\n"
	.string "ルールが　かかれている！$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "どの　せつめいを　よみますか？$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "ピラミッドの　なかで　でてくる\n"
	.string "やせい　ポケモンは\l"
	.string "ピラミッドを　せいはすると　かわります\p"
	.string "どんな　ポケモンが　でてくるのかは\n"
	.string "じっさいに　ぼうけんして　おぼえましょう$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "ピラミッドの　なかには\n"
	.string "トレーナーが　まちかまえて　います\p"
	.string "1つの　だんには　さいこうで\n"
	.string "8にんの　トレーナーが　います\p"
	.string "また　トレーナーに　かつと\n"
	.string "ちょっと　ぼうけんに　やくだつ\l"
	.string "ヒントが　もらえます$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "ピラミッドの　めいろは\n"
	.string "はいる　たびに　かわります\p"
	.string "なかは　とても　くらく　なっているので\n"
	.string "しんちょうに　すすみましょう\p"
	.string "また　やせいポケモンや　トレーナーとの\n"
	.string "たたかいに　かつと\l"
	.string "ちょっとだけ　まわりが　あかるくなります$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "バトルバッグは　ピラミッドに　いる　あいだ\n"
	.string "つかうことが　できます\p"
	.string "レベル50と　オープンレベルの\n"
	.string "バッグが　それぞれ　ようい　されていて\l"
	.string "10しゅるいの　どうぐを\l"
	.string "99こ　まで　いれることが　できます\p"
	.string "また　バッグの　なかみは　ぼうけんに\n"
	.string "しっぱい　すると　なくなって　しまいます$"

	.include "data/maps/BattleFrontier_BattlePyramidFloor/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePyramidTop/scripts.inc"
	.include "data/maps/BattleFrontier_BattleArenaLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleArenaCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleFactoryLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeThreePathRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.inc"
	.include "data/maps/BattleFrontier_RankingHall/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge1/scripts.inc"
	.include "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge2/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge3/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge4/scripts.inc"
	.include "data/maps/BattleFrontier_ScottsHouse/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge5/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge6/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge7/scripts.inc"
	.include "data/maps/BattleFrontier_ReceptionGate/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge8/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge9/scripts.inc"
	.include "data/maps/BattleFrontier_PokemonCenter_1F/scripts.inc"
	.include "data/maps/BattleFrontier_PokemonCenter_2F/scripts.inc"
	.include "data/maps/BattleFrontier_Mart/scripts.inc"
	.include "data/maps/FarawayIsland_Entrance/scripts.inc"
	.include "data/maps/FarawayIsland_Interior/scripts.inc"
	.include "data/maps/BirthIsland_Exterior/scripts.inc"
	.include "data/maps/BirthIsland_Harbor/scripts.inc"
	.include "data/maps/TrainerHill_Entrance/scripts.inc"
	.include "data/maps/TrainerHill_1F/scripts.inc"
	.include "data/maps/TrainerHill_2F/scripts.inc"
	.include "data/maps/TrainerHill_3F/scripts.inc"
	.include "data/maps/TrainerHill_4F/scripts.inc"
	.include "data/maps/TrainerHill_Roof/scripts.inc"
	.include "data/maps/NavelRock_Exterior/scripts.inc"
	.include "data/maps/NavelRock_Harbor/scripts.inc"
	.include "data/maps/NavelRock_Entrance/scripts.inc"
	.include "data/maps/NavelRock_B1F/scripts.inc"
	.include "data/maps/NavelRock_Fork/scripts.inc"
	.include "data/maps/NavelRock_Up1/scripts.inc"
	.include "data/maps/NavelRock_Up2/scripts.inc"
	.include "data/maps/NavelRock_Up3/scripts.inc"
	.include "data/maps/NavelRock_Up4/scripts.inc"
	.include "data/maps/NavelRock_Top/scripts.inc"
	.include "data/maps/NavelRock_Down01/scripts.inc"
	.include "data/maps/NavelRock_Down02/scripts.inc"
	.include "data/maps/NavelRock_Down03/scripts.inc"
	.include "data/maps/NavelRock_Down04/scripts.inc"
	.include "data/maps/NavelRock_Down05/scripts.inc"
	.include "data/maps/NavelRock_Down06/scripts.inc"
	.include "data/maps/NavelRock_Down07/scripts.inc"
	.include "data/maps/NavelRock_Down08/scripts.inc"
	.include "data/maps/NavelRock_Down09/scripts.inc"
	.include "data/maps/NavelRock_Down10/scripts.inc"
	.include "data/maps/NavelRock_Down11/scripts.inc"
	.include "data/maps/NavelRock_Bottom/scripts.inc"
	.include "data/maps/TrainerHill_Elevator/scripts.inc"
	.include "data/maps/Route104_Prototype/scripts.inc"
	.include "data/maps/Route104_PrototypePrettyPetalFlowerShop/scripts.inc"
	.include "data/maps/Route109_SeashoreHouse/scripts.inc"
	.include "data/maps/Route110_TrickHouseEntrance/scripts.inc"
	.include "data/maps/Route110_TrickHouseEnd/scripts.inc"
	.include "data/maps/Route110_TrickHouseCorridor/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle1/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle2/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle3/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle4/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle5/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle6/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle7/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle8/scripts.inc"
	.include "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.inc"
	.include "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.inc"
	.include "data/maps/Route113_GlassWorkshop/scripts.inc"
	.include "data/maps/Route123_BerryMastersHouse/scripts.inc"
	.include "data/maps/Route119_WeatherInstitute_1F/scripts.inc"
	.include "data/maps/Route119_WeatherInstitute_2F/scripts.inc"
	.include "data/maps/Route119_House/scripts.inc"
	.include "data/maps/Route124_DivingTreasureHuntersHouse/scripts.inc"
	.include "data/scripts/std_msgbox.inc"

	.globl EventScript_StartTrainerApproach
	.globl EventScript_TryDoNormalTrainerBattle
	.globl EventScript_TryDoDoubleTrainerBattle
	.globl EventScript_DoNoIntroTrainerBattle
	.globl EventScript_TryDoRematchBattle
	.globl EventScript_TryDoDoubleRematchBattle
	.include "data/scripts/trainer_battle.inc"
	.include "data/scripts/std_msgbox_autoclose.inc"
	.include "data/scripts/new_game.inc"
	.include "data/scripts/hall_of_fame.inc"

	.include "data/scripts/white_out.inc"

	.include "data/scripts/pkmn_center_nurse.inc"
	.include "data/scripts/obtain_item.inc"
	.include "data/scripts/record_mix_prompt.inc"
	.include "data/scripts/pc.inc"

Common_EventScript_ShowPokemartSign::
	@ The JP text data remains in its later physical owner at 0x082439D6.
	msgbox 0x082439D6, MSGBOX_SIGN
	end

Common_EventScript_ShowPokemonCenterSign::
	msgbox 0x082439F5, MSGBOX_SIGN
	end

Common_ShowEasyChatScreen::
	fadescreen FADE_TO_BLACK
	special ShowEasyChatScreen
	fadescreen FADE_FROM_BLACK
	return

Common_EventScript_ReadyPetalburgGymForBattle::
	clearflag FLAG_HIDE_PETALBURG_GYM_GREETER
	setflag FLAG_PETALBURG_MART_EXPANDED_ITEMS
	return

Common_EventScript_BufferTrendyPhrase::
	dotimebasedevents
	setvar VAR_0x8004, 0
	special BufferTrendyPhraseString
	return

EventScript_BackupMrBrineyLocation::
	copyvar VAR_0x8008, VAR_BRINEY_LOCATION
	setvar VAR_BRINEY_LOCATION, 0
	return

	.include "data/scripts/surf.inc"
	.include "data/scripts/rival_graphics.inc"
	.include "data/scripts/set_gym_trainers.inc"

Common_EventScript_ShowBagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end

Common_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	return

Common_EventScript_ShowNoRoomForDecor::
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	release
	end

Common_EventScript_NoRoomForDecor::
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	return

Common_EventScript_SetAbnormalWeather::
	setweather WEATHER_ABNORMAL
	return

Common_EventScript_PlayGymBadgeFanfare::
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	return

Common_EventScript_OutOfCenterPartyHeal::
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	return

	@ These Fan Club interview strings remain in the later shared TV-text raw
	@ owner. Export semantic aliases until that physical text owner is split.
	.globl LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer
	.set LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer, 0x0824DE14
	.globl LilycoveCity_PokemonTrainerFanClub_Text_ThatsWhatYouThink
	.set LilycoveCity_PokemonTrainerFanClub_Text_ThatsWhatYouThink, 0x0824DE37
	.globl LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer
	.set LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer, 0x0824DE51
	.globl LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer2
	.set LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer2, 0x0824DE64
	.globl LilycoveCity_PokemonTrainerFanClub_Text_HowStrongRateTrainer
	.set LilycoveCity_PokemonTrainerFanClub_Text_HowStrongRateTrainer, 0x0824DE82
	.globl LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer2
	.set LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer2, 0x0824DEA3
	.globl LilycoveCity_PokemonTrainerFanClub_Text_YouShouldMeetTrainer
	.set LilycoveCity_PokemonTrainerFanClub_Text_YouShouldMeetTrainer, 0x0824DEB6
	.globl LilycoveCity_PokemonTrainerFanClub_Text_ThankYouIllShareThisInfo
	.set LilycoveCity_PokemonTrainerFanClub_Text_ThankYouIllShareThisInfo, 0x0824DEE0
	.globl LilycoveCity_PokemonTrainerFanClub_HopeYouCatchTVSpecial
	.set LilycoveCity_PokemonTrainerFanClub_HopeYouCatchTVSpecial, 0x0824DF29
	.globl EventTicket_Text_OldSeaMapTooFar
	.set EventTicket_Text_OldSeaMapTooFar, 0x08275C60
	.globl EventTicket_Text_BrineyHoldOnASecond
	.set EventTicket_Text_BrineyHoldOnASecond, 0x08275CB6
	.globl EventTicket_Text_BrineyLetsSail
	.set EventTicket_Text_BrineyLetsSail, 0x08275CDA
	.globl EventTicket_Text_OddTicketGetOnBoard
	.set EventTicket_Text_OddTicketGetOnBoard, 0x08275D2A
	.globl EventTicket_Text_OddTicketsWhereTo
	.set EventTicket_Text_OddTicketsWhereTo, 0x08275DF2
	.globl Roulette_EventScript_Table1
	.set Roulette_EventScript_Table1, 0x08262C92
	.globl Roulette_EventScript_Table2
	.set Roulette_EventScript_Table2, 0x08262CC0
	.globl EventScript_GotoTrainerScript
	.set EventScript_GotoTrainerScript, 0x08244D20
	@ The Lavaridge House event table references the shared Mimic tutor script.
	.globl LavaridgeTown_House_EventScript_MimicTutor
	.set LavaridgeTown_House_EventScript_MimicTutor, 0x0827696A
	@ The Fallarbor Mart event table references the shared Metronome tutor script.
	.globl FallarborTown_Mart_EventScript_MetronomeTutor
	.set FallarborTown_Mart_EventScript_MetronomeTutor, 0x082769D2

EventScript_RegionMap::
	lockall
	msgbox Common_Text_LookCloserAtMap, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special FieldShowRegionMap
	releaseall
	end

Common_EventScript_PlayBrineysBoatMusic::
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_SAILING, FALSE
	return

Common_EventScript_StopBrineysBoatMusic::
	clearflag FLAG_DONT_TRANSITION_MUSIC
	fadedefaultbgm
	return

	.include "data/scripts/prof_birch.inc"

Common_EventScript_FerryDepart::
	delay 60
	applymovement VAR_0x8004, Movement_FerryDepart
	waitmovement 0
	return

Movement_FerryDepart:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

EventScript_HideMrBriney::
	setflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 0
	return

RusturfTunnel_EventScript_SetRusturfTunnelOpen::
	removeobject LOCALID_RUSTURF_TUNNEL_WANDAS_BF
	removeobject LOCALID_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDA
	setvar VAR_RUSTURF_TUNNEL_STATE, 6
	setflag FLAG_RUSTURF_TUNNEL_OPENED
	return

EventScript_UnusedBoardFerry::
	delay 30
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	showplayer
	delay 30
	applymovement LOCALID_PLAYER, Movement_UnusedBoardFerry
	waitmovement 0
	delay 30
	return

Movement_UnusedBoardFerry:
	walk_up
	step_end

Common_EventScript_FerryDepartIsland::
	call_if_eq VAR_FACING, DIR_SOUTH, Ferry_EventScript_DepartIslandSouth
	call_if_eq VAR_FACING, DIR_WEST, Ferry_EventScript_DepartIslandWest
	delay 30
	hideplayer
	call Common_EventScript_FerryDepart
	return

	.include "data/scripts/cave_of_origin.inc"
	.include "data/scripts/kecleon.inc"

Common_EventScript_NameReceivedPartyMon::
	fadescreen FADE_TO_BLACK
	special ChangePokemonNickname
	@ The JP nickname screen script waits for the special task here.
	waitstate
	return

Common_EventScript_PlayerHandedOverTheItem::
	bufferitemname STR_VAR_1, VAR_0x8004
	playfanfare MUS_OBTAIN_TMHM
	@ The JP text data remains in its later physical owner at 0x08243D82.
	message 0x08243D82
	waitmessage
	waitfanfare
	removeitem VAR_0x8004
	return

	.include "data/scripts/elite_four.inc"
	.include "data/scripts/movement.inc"
	.include "data/scripts/check_furniture.inc"

	@ 0x08243690-0x082436B8 is still unstructured shared script data.
	.incbin "baserom_jp.gba", 0x243690, 0x28

	.globl gJPText_002436B8
gJPText_002436B8: @ 0x082436B8
	.string "{MUS_RG_VS_TRAINER}は\n"
	.string "パソコンの　スイッチを　いれた！$"

gUnknown_82436CD:: @ 0x082436CD
	@ 0x082436CD-0x0824390F remains unstructured shared text data.
	.incbin "baserom_jp.gba", 0x2436cd, 0x242

	@ 0x0824390F
	.include "data/text/mart_clerk.inc"
	@ 0x0824393C
	.include "data/text/obtain_item.inc"

	@ 0x0824398A-0x082439A8 remains unstructured shared text data.
	.incbin "baserom_jp.gba", 0x24398a, 0x1e

gText_NoRoomLeftForAnother:: @ 0x082439A8
	.incbin "baserom_jp.gba", 0x2439a8, 0x9f

gText_WhichFloorWouldYouLike:: @ 0x08243A47
	.string "ミナモ　デパートへ　ようこそ！\p"
	.string "なんかいへ　いきますか？$"

gText_SandstormIsVicious:: @ 0x08243A64
	.string "さばくの　すなあらしが　ひどくて\n"
	.string "さきに　すすめない！$"

gText_SelectWithoutRegisteredItem:: @ 0x08243A80
	.string "バッグに　いれてある　どうぐを\n"
	.string "べんりボタンに　とうろく　できます$"

	@ 0x08243AA2-0x08243B4E remains unstructured shared text data.
	.incbin "baserom_jp.gba", 0x243aa2, 0xac

gText_PlayerWhitedOut:: @ 0x08243B4E
	.incbin "baserom_jp.gba", 0x243b4e, 0x31

gText_RegisteredTrainerinPokeNav:: @ 0x08243B7F
	.string "{B_COPY_VAR_1}の　{B_COPY_VAR_2}を\n"
	.string "ポケナビに　とうろく　した！$"

	@ 0x08243B96-0x08243C8B remains unstructured shared text data.
	.incbin "baserom_jp.gba", 0x243b96, 0xf5

	@ 0x08243C8B
	.include "data/text/surf.inc"

gText_DoorOpenedFarAway:: @ 0x08243CBE
	.incbin "baserom_jp.gba", 0x243cbe, 0x1c

gText_BigHoleInTheWall:: @ 0x08243CDA
	.incbin "baserom_jp.gba", 0x243cda, 0x14

	@ 0x08243CEE-0x08243D90 remains unstructured shared text data.
	.incbin "baserom_jp.gba", 0x243cee, 0xa2

gText_ThankYouForAccessingMysteryGift:: @ 0x08243D90
	.string "ふしぎな　おくりものを　ごりよう\n"
	.string "いただき　ありがとう　ございます！$"

	@ 0x08243DB3-0x08243DC6 remains unstructured shared text data.
	.incbin "baserom_jp.gba", 0x243db3, 0x13

gText_Sudowoodo_Attacked:: @ 0x08243DC6
	.string "おかしな　きは\n"
	.string "ホエルコじょうろを　いやがっている！\p"
	.string "おかしな　きが　おそいかかってきた！$"

gText_LegendaryFlewAway:: @ 0x08243DF4
	.string "{B_COPY_VAR_1}は\n"
	.string "どこかへ　とびさって　いった！$"

	@ 0x08243E08
	.include "data/text/pc_transfer.inc"

	@ 0x08243EEE
	.include "data/text/questionnaire.inc"

MysteryGift_Text_TheresATicketForYou:: @ 0x08244040
	.string "ふしぎなできごと　を　ごりよう\n"
	.string "いただき　ありがとう　ございます！\l"
	.string "{PLAYER}さま　ですね\p"
	.string "あなたさま　あてに\n"
	.string "この　チケットが\l"
	.string "おくられて　きました$"

MysteryGift_Text_TryUsingItAtLilycovePort:: @ 0x08244089
	.string "ミナモシティの　ふなつきば　で\n"
	.string "つかえる　ようですね\p"
	.string "ぜひ　ごりよう　してみては\n"
	.string "いかがでしょうか？$"

	@ 0x082440BC
	.include "data/text/abnormal_weather.inc"

EventScript_SelectWithoutRegisteredItem:: @ 0x082440DD
	msgbox gText_SelectWithoutRegisteredItem, MSGBOX_SIGN
	end

	.include "data/scripts/field_poison.inc"

Common_EventScript_NopReturn::
	return

@ Unused
EventScript_CableClub_SetVarResult1::
	setvar VAR_RESULT, TRUE
	return

EventScript_CableClub_SetVarResult0::
	setvar VAR_RESULT, FALSE
	return

Common_EventScript_UnionRoomAttendant::
	call CableClub_EventScript_UnionRoomAttendant
	end

Common_EventScript_WirelessClubAttendant::
	call CableClub_EventScript_WirelessClubAttendant
	end

Common_EventScript_DirectCornerAttendant::
	call CableClub_EventScript_DirectCornerAttendant
	end

Common_EventScript_RemoveStaticPokemon::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

Common_EventScript_LegendaryFlewAway::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	release
	end

	@ 0x082441B5
	.include "data/scripts/pc_transfer.inc"

	@ 0x08244245
	.include "data/scripts/questionnaire.inc"

	@ 0x0824433D
	.include "data/scripts/abnormal_weather.inc"

	.include "data/scripts/trainer_script.inc"

	.include "data/scripts/berry_tree.inc"

	@ 0x08244F02
	.include "data/text/berry_tree.inc"

	@ 0x0824506B
	.include "data/scripts/secret_base.inc"

	@ 0x08246378
	.include "data/scripts/secret_power_tm.inc"

	@ 0x082465BD
	.include "data/text/shared_secret_base.inc"

	@ 0x082467CD
	.include "data/scripts/cable_club.inc"

	@ 0x08247869-0x08247B80 is structured in data/scripts/cable_club.inc.
ScriptData_Raw_08247B80: @ 0x08247B80
	@ 0x08247B80-0x08247C79 remains unstructured script_data.
	.incbin "baserom_jp.gba", 0x247B80, 0xF9

	.globl gUnknown_8247C79
gUnknown_8247C79: @ 0x8247C79
	.include "data/scripts/gUnknown_8247C79.inc"

	.globl gText_PleaseWaitForLink
	.set gText_PleaseWaitForLink, gUnknown_8247C79

	.globl gUnknown_8247C97
gUnknown_8247C97: @ 0x8247C97
	.include "data/scripts/gUnknown_8247C97.inc"

	.globl gUnknown_8247CB5
gUnknown_8247CB5: @ 0x8247CB5
	.include "data/scripts/gUnknown_8247CB5.inc"

	.globl gUnknown_8247CDA
gUnknown_8247CDA: @ 0x8247CDA
	.include "data/scripts/gUnknown_8247CDA.inc"

	.globl gText_ConfirmLinkWhenPlayersReady
	.set gText_ConfirmLinkWhenPlayersReady, gUnknown_8247C97

	.globl gText_ConfirmStartLinkWithXPlayers
	.set gText_ConfirmStartLinkWithXPlayers, gUnknown_8247CB5

	.globl gText_AwaitingLinkup
	.set gText_AwaitingLinkup, gUnknown_8247CDA

	.globl CableClub_Text_TradeUsingLinkCable
	.set CableClub_Text_TradeUsingLinkCable, EventScript_WirelessBoxResults + 0x34A
	.globl CableClub_Text_BattleUsingLinkCable
	.set CableClub_Text_BattleUsingLinkCable, EventScript_WirelessBoxResults + 0x36C
	.globl CableClub_Text_RecordCornerUsingLinkCable
	.set CableClub_Text_RecordCornerUsingLinkCable, EventScript_WirelessBoxResults + 0x38E
	.globl CableClub_Text_CancelSelectedItem
	.set CableClub_Text_CancelSelectedItem, EventScript_WirelessBoxResults + 0x834
	.globl CableClub_Text_YouMayTradeHere
	.set CableClub_Text_YouMayTradeHere, EventScript_WirelessBoxResults + 0x7AB
	.globl CableClub_Text_YouMayBattleHere
	.set CableClub_Text_YouMayBattleHere, EventScript_WirelessBoxResults + 0x7C4
	.globl CableClub_Text_CanMixRecords
	.set CableClub_Text_CanMixRecords, EventScript_WirelessBoxResults + 0x7FD
	.globl CableClub_Text_CanMakeBerryPowder
	.set CableClub_Text_CanMakeBerryPowder, EventScript_WirelessBoxResults + 0x7DD

	.globl gText_HighlyAppealingMove
	.set gText_HighlyAppealingMove, gUnknown_8247CDA + 0x2FEF
	.globl gText_UserMoreEasilyStartled
	.set gText_UserMoreEasilyStartled, gUnknown_8247CDA + 0x2FFD
	.globl gText_GreatAppealButNoMoreToEnd
	.set gText_GreatAppealButNoMoreToEnd, gUnknown_8247CDA + 0x301A
	.globl gText_UsedRepeatedlyWithoutBoringJudge
	.set gText_UsedRepeatedlyWithoutBoringJudge, gUnknown_8247CDA + 0x303D
	.globl gText_AvoidStartledByOthersOnce
	.set gText_AvoidStartledByOthersOnce, gUnknown_8247CDA + 0x305E
	.globl gText_AvoidStartledByOthers
	.set gText_AvoidStartledByOthers, gUnknown_8247CDA + 0x307F
	.globl gText_AvoidStartledByOthersLittle
	.set gText_AvoidStartledByOthersLittle, gUnknown_8247CDA + 0x3098
	.globl gText_UserLessEasilyStartled
	.set gText_UserLessEasilyStartled, gUnknown_8247CDA + 0x30BB
	.globl gText_SlightlyStartleFrontMon
	.set gText_SlightlyStartleFrontMon, gUnknown_8247CDA + 0x30D9
	.globl gText_SlightlyStartleAppealed
	.set gText_SlightlyStartleAppealed, gUnknown_8247CDA + 0x30FA
	.globl gText_StartleAppealedBeforeUser
	.set gText_StartleAppealedBeforeUser, gUnknown_8247CDA + 0x311C
	.globl gText_StartleAllAppealed
	.set gText_StartleAllAppealed, gUnknown_8247CDA + 0x3138
	.globl gText_BadlyStartleFrontMon
	.set gText_BadlyStartleFrontMon, gUnknown_8247CDA + 0x3155
	.globl gText_BadlyStartleAppealed
	.set gText_BadlyStartleAppealed, gUnknown_8247CDA + 0x3175
	.globl gText_StartleAppealedBeforeUser2
	.set gText_StartleAppealedBeforeUser2, gUnknown_8247CDA + 0x3196
	.globl gText_StartleAllAppealed2
	.set gText_StartleAllAppealed2, gUnknown_8247CDA + 0x31B2
	.globl gText_ShiftJudgesAttentionFromOthers
	.set gText_ShiftJudgesAttentionFromOthers, gUnknown_8247CDA + 0x31CF
	.globl gText_StartleMonHasJudgesAttention
	.set gText_StartleMonHasJudgesAttention, gUnknown_8247CDA + 0x31F3
	.globl gText_JamOthersMissesTurn
	.set gText_JamOthersMissesTurn, gUnknown_8247CDA + 0x3216
	.globl gText_StartleMonsMadeSameTypeAppeal
	.set gText_StartleMonsMadeSameTypeAppeal, gUnknown_8247CDA + 0x3238
	.globl gText_BadlyStartleCoolAppeals
	.set gText_BadlyStartleCoolAppeals, gUnknown_8247CDA + 0x325A
	.globl gText_BadlyStartleBeautyAppeals
	.set gText_BadlyStartleBeautyAppeals, gUnknown_8247CDA + 0x3279
	.globl gText_BadlyStartleCuteAppeals
	.set gText_BadlyStartleCuteAppeals, gUnknown_8247CDA + 0x3298
	.globl gText_BadlyStartleSmartAppeals
	.set gText_BadlyStartleSmartAppeals, gUnknown_8247CDA + 0x32B6
	.globl gText_BadlyStartleToughAppeals
	.set gText_BadlyStartleToughAppeals, gUnknown_8247CDA + 0x32D4
	.globl gText_MakeMonAfterUserNervous
	.set gText_MakeMonAfterUserNervous, gUnknown_8247CDA + 0x32F3
	.globl gText_MakeAllMonsAfterUserNervous
	.set gText_MakeAllMonsAfterUserNervous, gUnknown_8247CDA + 0x3313
	.globl gText_WorsenConditionOfThoseMadeAppeals
	.set gText_WorsenConditionOfThoseMadeAppeals, gUnknown_8247CDA + 0x3333
	.globl gText_BadlyStartleMonsGoodCondition
	.set gText_BadlyStartleMonsGoodCondition, gUnknown_8247CDA + 0x334E
	.globl gText_AppealGreatIfPerformedFirst
	.set gText_AppealGreatIfPerformedFirst, gUnknown_8247CDA + 0x336B
	.globl gText_AppealGreatIfPerformedLast
	.set gText_AppealGreatIfPerformedLast, gUnknown_8247CDA + 0x338C
	.globl gText_AppealAsGoodAsThoseBeforeIt
	.set gText_AppealAsGoodAsThoseBeforeIt, gUnknown_8247CDA + 0x33AD
	.globl gText_AppealAsGoodAsOneBeforeIt
	.set gText_AppealAsGoodAsOneBeforeIt, gUnknown_8247CDA + 0x33D1
	.globl gText_AppealBetterLaterItsPerformed
	.set gText_AppealBetterLaterItsPerformed, gUnknown_8247CDA + 0x33F2
	.globl gText_AppealVariesDependingOnTiming
	.set gText_AppealVariesDependingOnTiming, gUnknown_8247CDA + 0x3414
	.globl gText_WorksWellIfSameTypeAsBefore
	.set gText_WorksWellIfSameTypeAsBefore, gUnknown_8247CDA + 0x3435
	.globl gText_WorksWellIfDifferentTypeAsBefore
	.set gText_WorksWellIfDifferentTypeAsBefore, gUnknown_8247CDA + 0x3459
	.globl gText_AffectedByAppealInFront
	.set gText_AffectedByAppealInFront, gUnknown_8247CDA + 0x347D
	.globl gText_UpsConditionHelpsPreventNervousness
	.set gText_UpsConditionHelpsPreventNervousness, gUnknown_8247CDA + 0x349E
	.globl gText_AppealWorksWellIfConditionGood
	.set gText_AppealWorksWellIfConditionGood, gUnknown_8247CDA + 0x34BC
	.globl gText_NextAppealMadeEarlier
	.set gText_NextAppealMadeEarlier, gUnknown_8247CDA + 0x34DC
	.globl gText_NextAppealMadeLater
	.set gText_NextAppealMadeLater, gUnknown_8247CDA + 0x34FB
	.globl gText_TurnOrderMoreEasilyScrambled
	.set gText_TurnOrderMoreEasilyScrambled, gUnknown_8247CDA + 0x351A
	.globl gText_ScrambleOrderOfNextAppeals
	.set gText_ScrambleOrderOfNextAppeals, gUnknown_8247CDA + 0x3537
	.globl gText_AppealExcitesAudienceInAnyContest
	.set gText_AppealExcitesAudienceInAnyContest, gUnknown_8247CDA + 0x3555
	.globl gText_BadlyStartlesMonsGoodAppeals
	.set gText_BadlyStartlesMonsGoodAppeals, gUnknown_8247CDA + 0x3574
	.globl gText_AppealBestMoreCrowdExcited
	.set gText_AppealBestMoreCrowdExcited, gUnknown_8247CDA + 0x3595
	.globl gText_TemporarilyStopCrowdExcited
	.set gText_TemporarilyStopCrowdExcited, gUnknown_8247CDA + 0x35B5
	.globl gText_RainDance
	.set gText_RainDance, gUnknown_8247CDA + 0x35D6
	.globl gText_Rage
	.set gText_Rage, gUnknown_8247CDA + 0x35DB
	.globl gText_FocusEnergy
	.set gText_FocusEnergy, gUnknown_8247CDA + 0x35DF
	.globl gText_Hypnosis
	.set gText_Hypnosis, gUnknown_8247CDA + 0x35E5
	.globl gText_Softboiled
	.set gText_Softboiled, gUnknown_8247CDA + 0x35ED
	.globl gText_HornAttack
	.set gText_HornAttack, gUnknown_8247CDA + 0x35F3
	.globl gText_SwordsDance
	.set gText_SwordsDance, gUnknown_8247CDA + 0x35F9
	.globl gText_Conversion
	.set gText_Conversion, gUnknown_8247CDA + 0x3600
	.globl gText_SunnyDay
	.set gText_SunnyDay, gUnknown_8247CDA + 0x3607
	.globl gText_Rest2
	.set gText_Rest2, gUnknown_8247CDA + 0x360D
	.globl gText_Vicegrip
	.set gText_Vicegrip, gUnknown_8247CDA + 0x3611
	.globl gText_DefenseCurl
	.set gText_DefenseCurl, gUnknown_8247CDA + 0x3615
	.globl gText_LockOn
	.set gText_LockOn, gUnknown_8247CDA + 0x361B
	.globl gContestMoveTypeCoolText
	.set gContestMoveTypeCoolText, gUnknown_8247CDA + 0x3621
	.globl gContestMoveTypeBeautyText
	.set gContestMoveTypeBeautyText, gUnknown_8247CDA + 0x3627
	.globl gContestMoveTypeCuteText
	.set gContestMoveTypeCuteText, gUnknown_8247CDA + 0x362D
	.globl gContestMoveTypeSmartText
	.set gContestMoveTypeSmartText, gUnknown_8247CDA + 0x3632
	.globl gContestMoveTypeToughText
	.set gContestMoveTypeToughText, gUnknown_8247CDA + 0x3637
	.globl gText_ButAppealWasJammed
	.set gText_ButAppealWasJammed, gUnknown_8247CDA + 0x36B1
	.globl gText_FollowedAnotherMonsLead
	.set gText_FollowedAnotherMonsLead, gUnknown_8247CDA + 0x36BF
	.globl gText_ButItMessedUp
	.set gText_ButItMessedUp, gUnknown_8247CDA + 0x36CF
	.globl gText_WentBetterThanUsual
	.set gText_WentBetterThanUsual, gUnknown_8247CDA + 0x36E0
	.globl gText_JudgeLookedAwayForSomeReason
	.set gText_JudgeLookedAwayForSomeReason, gUnknown_8247CDA + 0x36EF
	.globl gText_WorkedHardToBuildOnPastMistakes
	.set gText_WorkedHardToBuildOnPastMistakes, gUnknown_8247CDA + 0x3703
	.globl gText_CantMakeAnyMoreMoves
	.set gText_CantMakeAnyMoreMoves, gUnknown_8247CDA + 0x371D
	.globl gText_WorkedFrighteninglyWell
	.set gText_WorkedFrighteninglyWell, gUnknown_8247CDA + 0x3731
	.globl gText_WorkedHardAsStandoutMon
	.set gText_WorkedHardAsStandoutMon, gUnknown_8247CDA + 0x3741
	.globl gText_JudgedLookedOnExpectantly
	.set gText_JudgedLookedOnExpectantly, gUnknown_8247CDA + 0x375C
	.globl gText_WorkedRatherWell
	.set gText_WorkedRatherWell, gUnknown_8247CDA + 0x3775
	.globl gText_WorkedLittleBetterThanUsual
	.set gText_WorkedLittleBetterThanUsual, gUnknown_8247CDA + 0x3782

	.globl gUnknown_824B317
gUnknown_824B317: @ 0x824B317
	.include "data/scripts/gUnknown_824B317.inc"

	.globl gUnknown_824B32D
gUnknown_824B32D: @ 0x824B32D
	.include "data/scripts/gUnknown_824B32D.inc"

	.globl gUnknown_824B346
gUnknown_824B346: @ 0x824B346
	.string "{B_COPY_VAR_1}は\n{B_COPY_VAR_2}で　アピール！$"

	.globl gUnknown_824B354
gUnknown_824B354: @ 0x824B354
	.include "data/scripts/gUnknown_824B354.inc"

	.globl gUnknown_824B36F
gUnknown_824B36F: @ 0x824B36F
	.include "data/scripts/gUnknown_824B36F.inc"

	.globl gUnknown_824BCCF
gUnknown_824BCCF: @ 0x824BCCF
	.include "data/scripts/gUnknown_824BCCF.inc"

	.globl gUnknown_824BCF2
gUnknown_824BCF2: @ 0x824BCF2
	.include "data/scripts/gUnknown_824BCF2.inc"

	.globl gUnknown_824BD18
gUnknown_824BD18: @ 0x824BD18
	.include "data/scripts/gUnknown_824BD18.inc"

	.globl gUnknown_824BD3E
gUnknown_824BD3E: @ 0x824BD3E
	.include "data/scripts/gUnknown_824BD3E.inc"

	.globl gUnknown_824BEC1
gUnknown_824BEC1: @ 0x824BEC1
	.include "data/scripts/gUnknown_824BEC1.inc"

	.globl gUnknown_824BFBE
gUnknown_824BFBE: @ 0x824BFBE
	.include "data/scripts/gUnknown_824BFBE.inc"

	.globl gUnknown_824BFE6
gUnknown_824BFE6: @ 0x824BFE6
	.include "data/scripts/gUnknown_824BFE6.inc"

	.globl gUnknown_824C008
gUnknown_824C008: @ 0x824C008
	.include "data/scripts/gUnknown_824C008.inc"

	.globl gUnknown_824C029
gUnknown_824C029: @ 0x824C029
	.include "data/scripts/gUnknown_824C029.inc"

	.globl gUnknown_824C04A
gUnknown_824C04A: @ 0x824C04A
	.include "data/scripts/gUnknown_824C04A.inc"

	.globl gUnknown_824C091
gUnknown_824C091: @ 0x824C091
	.include "data/scripts/gUnknown_824C091.inc"

	.globl gUnknown_824C0B1
gUnknown_824C0B1: @ 0x824C0B1
	.include "data/scripts/gUnknown_824C0B1.inc"

	.globl gUnknown_824C0D2
gUnknown_824C0D2: @ 0x824C0D2
	.include "data/scripts/gUnknown_824C0D2.inc"

	.globl gUnknown_824C0D7
gUnknown_824C0D7: @ 0x824C0D7
	.string "ドキドキ$"

	.globl gUnknown_824C0DC
gUnknown_824C0DC: @ 0x824C0DC
	.string "デレデレ$"

	.globl gUnknown_824C0E1
gUnknown_824C0E1: @ 0x824C0E1
	.string "オロオロ$"

	.globl gUnknown_824C0E6
gUnknown_824C0E6: @ 0x824C0E6
	.include "data/scripts/gUnknown_824C0E6.inc"

	.globl gUnknown_824C140
gUnknown_824C140: @ 0x824C140
	.include "data/scripts/gUnknown_824C140.inc"

	.globl gUnknown_824C1F5
gUnknown_824C1F5: @ 0x824C1F5
	.include "data/scripts/gUnknown_824C1F5.inc"

	.globl gUnknown_824C200
gUnknown_824C200: @ 0x824C200
	.include "data/scripts/gUnknown_824C200.inc"

	@ Script Menu semantic aliases for the embedded Trick House choice text.
	.globl gTrickHouse_Mechadoll_Oddish
	.set gTrickHouse_Mechadoll_Oddish, gUnknown_824C200 + 0x195
	.globl gTrickHouse_Mechadoll_Poochyena
	.set gTrickHouse_Mechadoll_Poochyena, gUnknown_824C200 + 0x19B
	.globl gTrickHouse_Mechadoll_Taillow
	.set gTrickHouse_Mechadoll_Taillow, gUnknown_824C200 + 0x1A0
	.globl gTrickHouse_Mechadoll_Azurill
	.set gTrickHouse_Mechadoll_Azurill, gUnknown_824C200 + 0x1A4
	.globl gTrickHouse_Mechadoll_Lotad
	.set gTrickHouse_Mechadoll_Lotad, gUnknown_824C200 + 0x1A8
	.globl gTrickHouse_Mechadoll_Wingull
	.set gTrickHouse_Mechadoll_Wingull, gUnknown_824C200 + 0x1AD
	.globl gTrickHouse_Mechadoll_Dustox
	.set gTrickHouse_Mechadoll_Dustox, gUnknown_824C200 + 0x1B2
	.globl gTrickHouse_Mechadoll_Zubat
	.set gTrickHouse_Mechadoll_Zubat, gUnknown_824C200 + 0x1B8
	.globl gTrickHouse_Mechadoll_Nincada
	.set gTrickHouse_Mechadoll_Nincada, gUnknown_824C200 + 0x1BD
	.globl gTrickHouse_Mechadoll_Ralts
	.set gTrickHouse_Mechadoll_Ralts, gUnknown_824C200 + 0x1C2
	.globl gTrickHouse_Mechadoll_Zigzagoon
	.set gTrickHouse_Mechadoll_Zigzagoon, gUnknown_824C200 + 0x1C7
	.globl gTrickHouse_Mechadoll_Slakoth
	.set gTrickHouse_Mechadoll_Slakoth, gUnknown_824C200 + 0x1CD
	.globl gTrickHouse_Mechadoll_Poochyena2
	.set gTrickHouse_Mechadoll_Poochyena2, gUnknown_824C200 + 0x1D2
	.globl gTrickHouse_Mechadoll_Shroomish
	.set gTrickHouse_Mechadoll_Shroomish, gUnknown_824C200 + 0x1D7
	.globl gTrickHouse_Mechadoll_Zigzagoon2
	.set gTrickHouse_Mechadoll_Zigzagoon2, gUnknown_824C200 + 0x1DC
	.globl gTrickHouse_Mechadoll_Poochyena3
	.set gTrickHouse_Mechadoll_Poochyena3, gUnknown_824C200 + 0x1E2
	.globl gTrickHouse_Mechadoll_Zubat2
	.set gTrickHouse_Mechadoll_Zubat2, gUnknown_824C200 + 0x1E7
	.globl gTrickHouse_Mechadoll_Carvanha
	.set gTrickHouse_Mechadoll_Carvanha, gUnknown_824C200 + 0x1EC
	.globl gTrickHouse_Mechadoll_BurnHeal
	.set gTrickHouse_Mechadoll_BurnHeal, gUnknown_824C200 + 0x1F1
	.globl gTrickHouse_Mechadoll_HarborMail
	.set gTrickHouse_Mechadoll_HarborMail, gUnknown_824C200 + 0x1F8
	.globl gTrickHouse_Mechadoll_SamePrice
	.set gTrickHouse_Mechadoll_SamePrice, gUnknown_824C200 + 0x200
	.globl gTrickHouse_Mechadoll_60Yen
	.set gTrickHouse_Mechadoll_60Yen, gUnknown_824C200 + 0x207
	.globl gTrickHouse_Mechadoll_55Yen
	.set gTrickHouse_Mechadoll_55Yen, gUnknown_824C200 + 0x20C
	.globl gTrickHouse_Mechadoll_Nothing
	.set gTrickHouse_Mechadoll_Nothing, gUnknown_824C200 + 0x211
	.globl gTrickHouse_Mechadoll_CostMore
	.set gTrickHouse_Mechadoll_CostMore, gUnknown_824C200 + 0x217
	.globl gTrickHouse_Mechadoll_CostLess
	.set gTrickHouse_Mechadoll_CostLess, gUnknown_824C200 + 0x21D
	.globl gTrickHouse_Mechadoll_SamePrice2
	.set gTrickHouse_Mechadoll_SamePrice2, gUnknown_824C200 + 0x223
	.globl gTrickHouse_Mechadoll_Male
	.set gTrickHouse_Mechadoll_Male, gUnknown_824C200 + 0x22A
	.globl gTrickHouse_Mechadoll_Female
	.set gTrickHouse_Mechadoll_Female, gUnknown_824C200 + 0x22F
	.globl gTrickHouse_Mechadoll_Neither
	.set gTrickHouse_Mechadoll_Neither, gUnknown_824C200 + 0x234
	.globl gTrickHouse_Mechadoll_ElderlyMen
	.set gTrickHouse_Mechadoll_ElderlyMen, gUnknown_824C200 + 0x23C
	.globl gTrickHouse_Mechadoll_ElderlyLadies
	.set gTrickHouse_Mechadoll_ElderlyLadies, gUnknown_824C200 + 0x242
	.globl gTrickHouse_Mechadoll_SameNumber
	.set gTrickHouse_Mechadoll_SameNumber, gUnknown_824C200 + 0x248
	.globl gTrickHouse_Mechadoll_None
	.set gTrickHouse_Mechadoll_None, gUnknown_824C200 + 0x24E
	.globl gTrickHouse_Mechadoll_One
	.set gTrickHouse_Mechadoll_One, gUnknown_824C200 + 0x252
	.globl gTrickHouse_Mechadoll_Two
	.set gTrickHouse_Mechadoll_Two, gUnknown_824C200 + 0x256
	.globl gTrickHouse_Mechadoll_Two2
	.set gTrickHouse_Mechadoll_Two2, gUnknown_824C200 + 0x25A
	.globl gTrickHouse_Mechadoll_Three
	.set gTrickHouse_Mechadoll_Three, gUnknown_824C200 + 0x25E
	.globl gTrickHouse_Mechadoll_Four
	.set gTrickHouse_Mechadoll_Four, gUnknown_824C200 + 0x262
	.globl gTrickHouse_Mechadoll_Six
	.set gTrickHouse_Mechadoll_Six, gUnknown_824C200 + 0x266
	.globl gTrickHouse_Mechadoll_Seven
	.set gTrickHouse_Mechadoll_Seven, gUnknown_824C200 + 0x269
	.globl gTrickHouse_Mechadoll_Eight
	.set gTrickHouse_Mechadoll_Eight, gUnknown_824C200 + 0x26C
	.globl gTrickHouse_Mechadoll_Six2
	.set gTrickHouse_Mechadoll_Six2, gUnknown_824C200 + 0x26F
	.globl gTrickHouse_Mechadoll_Seven2
	.set gTrickHouse_Mechadoll_Seven2, gUnknown_824C200 + 0x273
	.globl gTrickHouse_Mechadoll_Eight2
	.set gTrickHouse_Mechadoll_Eight2, gUnknown_824C200 + 0x277

	.globl EventScript_TV
EventScript_TV: @ 0x824C47B
	.include "data/scripts/gUnknown_824C47B.inc"

	.globl EventScript_UseCut
EventScript_UseCut: @ 0x8256612
	.include "data/scripts/gUnknown_8256612.inc"
	@ Smashable-rock map events share this retained field-move script.
	.globl EventScript_RockSmash
	.set EventScript_RockSmash, 0x0825667C

	.globl EventScript_UseRockSmash
EventScript_UseRockSmash: @ 0x82566C6
	.include "data/scripts/gUnknown_82566C6.inc"

	.globl EventScript_UseStrength
EventScript_UseStrength: @ 0x8256797
	.include "data/scripts/gUnknown_8256797.inc"

	.globl EventScript_UseWaterfall
EventScript_UseWaterfall: @ 0x825685D
	.include "data/scripts/gUnknown_825685D.inc"

	.globl EventScript_CannotUseWaterfall
EventScript_CannotUseWaterfall: @ 0x8256897
	.include "data/scripts/gUnknown_8256897.inc"

	.globl EventScript_UseDive
EventScript_UseDive: @ 0x82568EA
	.include "data/scripts/gUnknown_82568EA.inc"

	.globl EventScript_UseDiveUnderwater
EventScript_UseDiveUnderwater: @ 0x8256935
	.include "data/scripts/gUnknown_8256935.inc"

	.globl EventScript_FailSweetScent
EventScript_FailSweetScent: @ 0x8256A14
	.include "data/scripts/gUnknown_8256A14.inc"
	@ These item-ball entries remain inside the later shared raw owner.
	@ Export the matching US map-event names without moving that owner early.
	.globl MeteorFalls_1F_1R_EventScript_ItemTMIronTail
	.set MeteorFalls_1F_1R_EventScript_ItemTMIronTail, 0x08256F02
	.globl MeteorFalls_1F_1R_EventScript_ItemFullHeal
	.set MeteorFalls_1F_1R_EventScript_ItemFullHeal, 0x08256F0F
	.globl MeteorFalls_1F_1R_EventScript_ItemMoonStone
	.set MeteorFalls_1F_1R_EventScript_ItemMoonStone, 0x08256F1C
	.globl MeteorFalls_1F_1R_EventScript_ItemPPUP
	.set MeteorFalls_1F_1R_EventScript_ItemPPUP, 0x08256F29
	.globl MeteorFalls_B1F_2R_EventScript_ItemTMDragonClaw
	.set MeteorFalls_B1F_2R_EventScript_ItemTMDragonClaw, 0x08256F36
	.globl RusturfTunnel_EventScript_ItemPokeBall
	.set RusturfTunnel_EventScript_ItemPokeBall, 0x08256E8D
	.globl RusturfTunnel_EventScript_ItemMaxEther
	.set RusturfTunnel_EventScript_ItemMaxEther, 0x08256E9A
	.globl GraniteCave_1F_EventScript_ItemEscapeRope
	.set GraniteCave_1F_EventScript_ItemEscapeRope, 0x08256EA7
	.globl GraniteCave_B1F_EventScript_ItemPokeBall
	.set GraniteCave_B1F_EventScript_ItemPokeBall, 0x08256EB4
	.globl GraniteCave_B2F_EventScript_ItemRepel
	.set GraniteCave_B2F_EventScript_ItemRepel, 0x08256EC1
	.globl GraniteCave_B2F_EventScript_ItemRareCandy
	.set GraniteCave_B2F_EventScript_ItemRareCandy, 0x08256ECE
	@ Petalburg Woods event entries point into later shared field/item owners.
	@ Its cut-tree target now has a physical label in gUnknown_824C47B.inc.
	.globl PetalburgWoods_EventScript_ItemXAttack
	.set PetalburgWoods_EventScript_ItemXAttack, 0x08256E59
	.globl PetalburgWoods_EventScript_ItemGreatBall
	.set PetalburgWoods_EventScript_ItemGreatBall, 0x08256E66
	.globl PetalburgWoods_EventScript_ItemEther
	.set PetalburgWoods_EventScript_ItemEther, 0x08256E73
	.globl PetalburgWoods_EventScript_ItemParalyzeHeal
	.set PetalburgWoods_EventScript_ItemParalyzeHeal, 0x08256E80
	@ Jagged Pass's Burn Heal entry remains in the later shared item-script
	@ owner; export the reviewed map-event name without moving that range.
	.globl JaggedPass_EventScript_ItemBurnHeal
	.set JaggedPass_EventScript_ItemBurnHeal, 0x08256EDB
	@ Fiery Path's item entries remain in the later shared item owner.
	@ Their map-event names remain exported here until that owner is split.
	.globl FieryPath_EventScript_ItemFireStone
	.set FieryPath_EventScript_ItemFireStone, 0x08256EE8
	.globl FieryPath_EventScript_ItemTMToxic
	.set FieryPath_EventScript_ItemTMToxic, 0x08256EF5
	@ Mt. Pyre 2F's Ultra Ball entry remains in a later shared item owner.
	.globl MtPyre_2F_EventScript_ItemUltraBall
	.set MtPyre_2F_EventScript_ItemUltraBall, 0x08257054
	@ Mt. Pyre 3F's Super Repel entry remains in the same later shared owner.
	.globl MtPyre_3F_EventScript_ItemSuperRepel
	.set MtPyre_3F_EventScript_ItemSuperRepel, 0x08257061
	@ Mt. Pyre 4F/5F item entries remain in that later shared owner.
	.globl MtPyre_4F_EventScript_ItemSeaIncense
	.set MtPyre_4F_EventScript_ItemSeaIncense, 0x0825706E
	.globl MtPyre_5F_EventScript_ItemLaxIncense
	.set MtPyre_5F_EventScript_ItemLaxIncense, 0x0825707B
	@ Mt. Pyre 6F's Shadow Ball entry remains in the later shared item owner.
	.globl MtPyre_6F_EventScript_ItemTMShadowBall
	.set MtPyre_6F_EventScript_ItemTMShadowBall, 0x08257088
	@ Mt. Pyre Exterior item entries remain in the later shared item owner.
	.globl MtPyre_Exterior_EventScript_ItemMaxPotion
	.set MtPyre_Exterior_EventScript_ItemMaxPotion, 0x08257095
	.globl MtPyre_Exterior_EventScript_ItemTMSkillSwap
	.set MtPyre_Exterior_EventScript_ItemTMSkillSwap, 0x082570A2
	@ Aqua Hideout B1F item entries remain in the later shared item owner.
	.globl AquaHideout_B1F_EventScript_ItemMasterBall
	.set AquaHideout_B1F_EventScript_ItemMasterBall, 0x082570AF
	.globl AquaHideout_B1F_EventScript_ItemNugget
	.set AquaHideout_B1F_EventScript_ItemNugget, 0x082570BC
	.globl AquaHideout_B1F_EventScript_ItemMaxElixir
	.set AquaHideout_B1F_EventScript_ItemMaxElixir, 0x082570C9
	@ Aqua Hideout B2F's Nest Ball entry remains in the later shared item owner.
	.globl AquaHideout_B2F_EventScript_ItemNestBall
	.set AquaHideout_B2F_EventScript_ItemNestBall, 0x082570D6
	@ The cracked-floor hooks remain in their later shared physical owner.
	.globl CaveHole_CheckFallDownHole
	.set CaveHole_CheckFallDownHole, 0x0826432F
	.globl CaveHole_FixCrackedGround
	.set CaveHole_FixCrackedGround, 0x08264339
	@ The Day-Care Woman logic remains inside the later shared raw owner.
	@ Export its reviewed map-event entry without moving that owner early.
	.globl Route117_PokemonDayCare_EventScript_DaycareWoman
	.set Route117_PokemonDayCare_EventScript_DaycareWoman, 0x082577DA

	.globl EventScript_EggHatch
EventScript_EggHatch: @ 0x8257A89
	.include "data/scripts/gUnknown_8257A89.inc"

	.globl EventScript_UseFlash
EventScript_UseFlash: @ 0x8257EE2
	.include "data/scripts/gUnknown_8257EE2.inc"

	.globl EventScript_RunningShoesManual
EventScript_RunningShoesManual: @ 0x82585CF
	.include "data/scripts/gUnknown_82585CF.inc"

	.globl gUnknown_825941C
gUnknown_825941C: @ 0x825941C
	.string "って$"

	.globl gUnknown_825941F
gUnknown_825941F: @ 0x825941F
	.include "data/text/trainers.inc"

	.globl EventScript_RepelWoreOff
EventScript_RepelWoreOff: @ 0x8262393
	.include "data/scripts/gUnknown_8262393.inc"

	.globl SafariZone_EventScript_OutOfBallsMidBattle
SafariZone_EventScript_OutOfBallsMidBattle: @ 0x82623AA
	.include "data/scripts/SafariZone_EventScript_Exit.inc"

	.globl SafariZone_EventScript_RetirePrompt
SafariZone_EventScript_RetirePrompt: @ 0x82623CD
	.include "data/scripts/gUnknown_82623CD.inc"

	.globl SafariZone_EventScript_TimesUp
SafariZone_EventScript_TimesUp: @ 0x82623E8
	.include "data/scripts/gUnknown_82623E8.inc"

	.globl SafariZone_EventScript_OutOfBalls
SafariZone_EventScript_OutOfBalls: @ 0x82623F9
	.include "data/scripts/gUnknown_82623F9.inc"

	.globl EventScript_PokeBlockFeeder
EventScript_PokeBlockFeeder: @ 0x826240A
	.include "data/scripts/safari_zone.inc"
	.incbin "baserom_jp.gba", 0x262C92, 0x61

	.globl gUnknown_8262CF3
gUnknown_8262CF3: @ 0x8262CF3
	.include "data/scripts/gUnknown_8262CF3.inc"

	.globl gUnknown_8262D18
gUnknown_8262D18: @ 0x8262D18
	.include "data/scripts/gUnknown_8262D18.inc"

	.globl gUnknown_8262D23
gUnknown_8262D23: @ 0x8262D23
	.include "data/scripts/gUnknown_8262D23.inc"

	.globl gUnknown_8262D3F
gUnknown_8262D3F: @ 0x8262D3F
	.include "data/scripts/gUnknown_8262D3F.inc"

	.globl gUnknown_8262D66
gUnknown_8262D66: @ 0x8262D66
	.string "あたりー！$"

	.globl gUnknown_8262D6C
gUnknown_8262D6C: @ 0x8262D6C
	.include "data/scripts/gUnknown_8262D6C.inc"

	.globl gUnknown_8262D74
gUnknown_8262D74: @ 0x8262D74
	.include "data/scripts/gUnknown_8262D74.inc"

	.globl gUnknown_8262D79
gUnknown_8262D79: @ 0x8262D79
	.include "data/scripts/gUnknown_8262D79.inc"

	.globl gUnknown_8262D96
gUnknown_8262D96: @ 0x8262D96
	.include "data/scripts/gUnknown_8262D96.inc"

	.globl gUnknown_8262DA3
gUnknown_8262DA3: @ 0x8262DA3
	.string "つづけて　あそびますか？$"

	.globl gUnknown_8262DB0
gUnknown_8262DB0: @ 0x8262DB0
	.include "data/scripts/gUnknown_8262DB0.inc"

	.globl gUnknown_8262DD5
gUnknown_8262DD5: @ 0x8262DD5
	.include "data/scripts/gUnknown_8262DD5.inc"

	.globl gBirchDexRatingText_AreYouCurious
gBirchDexRatingText_AreYouCurious: @ 0x8262DF5
	.include "data/scripts/gUnknown_8262DF5.inc"

	.globl gBirchDexRatingText_SoYouveSeenAndCaught
gBirchDexRatingText_SoYouveSeenAndCaught: @ 0x8262E39
	.include "data/scripts/gUnknown_8262E39.inc"

	.globl gBirchDexRatingText_LessThan10
gBirchDexRatingText_LessThan10: @ 0x8262E5F
	.include "data/scripts/gUnknown_8262E5F.inc"

	.globl gBirchDexRatingText_LessThan20
gBirchDexRatingText_LessThan20: @ 0x8262E81
	.include "data/scripts/gUnknown_8262E81.inc"

	.globl gBirchDexRatingText_LessThan30
gBirchDexRatingText_LessThan30: @ 0x8262EA6
	.include "data/scripts/gUnknown_8262EA6.inc"

	.globl gBirchDexRatingText_LessThan40
gBirchDexRatingText_LessThan40: @ 0x8262ECF
	.include "data/scripts/gUnknown_8262ECF.inc"

	.globl gBirchDexRatingText_LessThan50
gBirchDexRatingText_LessThan50: @ 0x8262EF5
	.include "data/scripts/gUnknown_8262EF5.inc"

	.globl gBirchDexRatingText_LessThan60
gBirchDexRatingText_LessThan60: @ 0x8262F18
	.include "data/scripts/gUnknown_8262F18.inc"

	.globl gBirchDexRatingText_LessThan70
gBirchDexRatingText_LessThan70: @ 0x8262F3F
	.include "data/scripts/gUnknown_8262F3F.inc"

	.globl gBirchDexRatingText_LessThan80
gBirchDexRatingText_LessThan80: @ 0x8262F61
	.include "data/scripts/gUnknown_8262F61.inc"

	.globl gBirchDexRatingText_LessThan90
gBirchDexRatingText_LessThan90: @ 0x8262F8A
	.include "data/scripts/gUnknown_8262F8A.inc"

	.globl gBirchDexRatingText_LessThan100
gBirchDexRatingText_LessThan100: @ 0x8262FAD
	.include "data/scripts/gUnknown_8262FAD.inc"

	.globl gBirchDexRatingText_LessThan110
gBirchDexRatingText_LessThan110: @ 0x8262FE1
	.include "data/scripts/gUnknown_8262FE1.inc"

	.globl gBirchDexRatingText_LessThan120
gBirchDexRatingText_LessThan120: @ 0x826300C
	.include "data/scripts/gUnknown_826300C.inc"

	.globl gBirchDexRatingText_LessThan130
gBirchDexRatingText_LessThan130: @ 0x8263032
	.include "data/scripts/gUnknown_8263032.inc"

	.globl gBirchDexRatingText_LessThan140
gBirchDexRatingText_LessThan140: @ 0x8263050
	.include "data/scripts/gUnknown_8263050.inc"

	.globl gBirchDexRatingText_LessThan150
gBirchDexRatingText_LessThan150: @ 0x8263072
	.include "data/scripts/gUnknown_8263072.inc"

	.globl gBirchDexRatingText_LessThan160
gBirchDexRatingText_LessThan160: @ 0x8263095
	.include "data/scripts/gUnknown_8263095.inc"

	.globl gBirchDexRatingText_LessThan170
gBirchDexRatingText_LessThan170: @ 0x82630C7
	.include "data/scripts/gUnknown_82630C7.inc"

	.globl gBirchDexRatingText_LessThan180
gBirchDexRatingText_LessThan180: @ 0x82630F0
	.include "data/scripts/gUnknown_82630F0.inc"

	.globl gBirchDexRatingText_LessThan190
gBirchDexRatingText_LessThan190: @ 0x826310C
	.include "data/scripts/gUnknown_826310C.inc"

	.globl gBirchDexRatingText_LessThan200
gBirchDexRatingText_LessThan200: @ 0x826312D
	.include "data/scripts/gUnknown_826312D.inc"

	.globl gBirchDexRatingText_DexCompleted
gBirchDexRatingText_DexCompleted: @ 0x826314F
	.include "data/scripts/gUnknown_826314F.inc"

	.globl gBirchDexRatingText_OnANationwideBasis
gBirchDexRatingText_OnANationwideBasis: @ 0x826316A
	.include "data/scripts/gUnknown_826316A.inc"

	.globl EventScript_FallDownHole
EventScript_FallDownHole: @ 0x826433F
	.include "data/scripts/gUnknown_826433F.inc"

	.globl EventScript_FallDownHoleMtPyre
EventScript_FallDownHoleMtPyre: @ 0x8264358
	.include "data/scripts/gUnknown_8264358.inc"

	.globl EventScript_TrainerHillTimer
EventScript_TrainerHillTimer: @ 0x8276CAF
	.include "data/scripts/gUnknown_8276CAF.inc"

	.globl TrainerHill_EventScript_TrainerBattle
TrainerHill_EventScript_TrainerBattle: @ 0x8276D0C
	.include "data/scripts/gUnknown_8276D0C.inc"

	.globl EventScript_TestSignpostMsg
EventScript_TestSignpostMsg: @ 0x8276D3D
	.include "data/scripts/gUnknown_8276D3D.inc"

	.globl gUnknown_8276F58
gUnknown_8276F58: @ 0x8276F58
	.include "data/scripts/gUnknown_8276F58.inc"

	.globl gUnknown_8276F77
gUnknown_8276F77: @ 0x8276F77
	.include "data/scripts/gUnknown_8276F77.inc"

	.globl gUnknown_8276F97
gUnknown_8276F97: @ 0x8276F97
	.include "data/scripts/gUnknown_8276F97.inc"

	.globl gUnknown_8276FBB
gUnknown_8276FBB: @ 0x8276FBB
	.include "data/scripts/gUnknown_8276FBB.inc"

	.globl gUnknown_8276FD3
gUnknown_8276FD3: @ 0x8276FD3
	.include "data/scripts/gUnknown_8276FD3.inc"

	.globl gUnknown_8277048
gUnknown_8277048: @ 0x8277048
	.include "data/scripts/gUnknown_8277048.inc"

	.globl gText_SavingDontTurnOffPower
gText_SavingDontTurnOffPower: @ 0x8277071
	.include "data/scripts/gUnknown_8277071.inc"

	.globl gUnknown_8277095
gUnknown_8277095: @ 0x8277095
	.include "data/scripts/gUnknown_8277095.inc"

	.globl gUnknown_8277102
gUnknown_8277102: @ 0x8277102
	.include "data/scripts/gUnknown_8277102.inc"

	.globl gUnknown_82771F4
gUnknown_82771F4: @ 0x82771F4
	.include "data/scripts/gUnknown_82771F4.inc"

	.globl gUnknown_8277200
gUnknown_8277200: @ 0x8277200
	.include "data/scripts/gUnknown_8277200.inc"

	.globl gUnknown_8277213
gUnknown_8277213: @ 0x8277213
	.include "data/scripts/gUnknown_8277213.inc"

	.globl gText_Birch_SoItsPlayer
gText_Birch_SoItsPlayer: @ 0x8277224
	.string "{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}　だね？$"

	.globl gUnknown_827722D
gUnknown_827722D: @ 0x827722D
	.include "data/scripts/gUnknown_827722D.inc"

	.globl gUnknown_8277265
gUnknown_8277265: @ 0x8277265
	.include "data/scripts/gUnknown_8277265.inc"

	.globl gUnknown_82772F0
gUnknown_82772F0: @ 0x82772F0
	.include "data/scripts/gUnknown_82772F0.inc"

	.globl gUnknown_82772F8
gUnknown_82772F8: @ 0x82772F8
	.4byte gUnknown_8277924                  @ 000
	.4byte gUnknown_8277924                  @ 001
	.4byte gUnknown_828063A                  @ 002
	.4byte gUnknown_8277955                  @ 003
	.4byte gUnknown_827884F                  @ 004
	.4byte gUnknown_82786D9                  @ 005
	.4byte gUnknown_8279E41                  @ 006
	.4byte gUnknown_8281204                  @ 007
	.4byte gUnknown_827DC85                  @ 008
	.4byte gUnknown_827E01B                  @ 009
	.4byte gUnknown_827E2CB                  @ 010
	.4byte gUnknown_8279D6D                  @ 011
	.4byte gUnknown_8279DB5                  @ 012
	.4byte gUnknown_8281F08                  @ 013
	.4byte gUnknown_8279030                  @ 014
	.4byte gUnknown_8278D16                  @ 015
	.4byte gUnknown_827FF98                  @ 016
	.4byte gUnknown_827FFE9                  @ 017
	.4byte gUnknown_827A375                  @ 018
	.4byte gUnknown_828056D                  @ 019
	.4byte gUnknown_828164F                  @ 020
	.4byte gUnknown_8279495                  @ 021
	.4byte gUnknown_827951D                  @ 022
	.4byte gUnknown_8278CB6                  @ 023
	.4byte gUnknown_82807E8                  @ 024
	.4byte gUnknown_82787B3                  @ 025
	.4byte gUnknown_82806F5                  @ 026
	.4byte gUnknown_827ABC6                  @ 027
	.4byte gUnknown_827E873                  @ 028
	.4byte gUnknown_827AC49                  @ 029
	.4byte gUnknown_827ACA6                  @ 030
	.4byte gUnknown_827AD13                  @ 031
	.4byte gUnknown_827AD90                  @ 032
	.4byte gUnknown_8277E82                  @ 033
	.4byte gUnknown_8277EC0                  @ 034
	.4byte gUnknown_8281689                  @ 035
	.4byte gUnknown_8278276                  @ 036
	.4byte gUnknown_827AF0D                  @ 037
	.4byte gUnknown_8278306                  @ 038
	.4byte gUnknown_8278CFD                  @ 039
	.4byte gUnknown_8278419                  @ 040
	.4byte gUnknown_827846E                  @ 041
	.4byte gUnknown_82780EC                  @ 042
	.4byte gUnknown_8281317                  @ 043
	.4byte gUnknown_827EAE1                  @ 044
	.4byte gUnknown_827E4A8                  @ 045
	.4byte gUnknown_827E411                  @ 046
	.4byte gUnknown_827AF8C                  @ 047
	.4byte gUnknown_8277F4D                  @ 048
	.4byte gUnknown_82788C7                  @ 049
	.4byte gUnknown_8281FEE                  @ 050
	.4byte gUnknown_827FC59                  @ 051
	.4byte gUnknown_8278665                  @ 052
	.4byte gUnknown_8280365                  @ 053
	.4byte gUnknown_8281170                  @ 054
	.4byte gUnknown_82801CA                  @ 055
	.4byte gUnknown_827F33F                  @ 056
	.4byte gUnknown_8280351                  @ 057
	.4byte gUnknown_827EC4C                  @ 058
	.4byte gUnknown_827F0B9                  @ 059
	.4byte gUnknown_828169F                  @ 060
	.4byte gUnknown_827A6FF                  @ 061
	.4byte gUnknown_827ED90                  @ 062
	.4byte gUnknown_82832F7                  @ 063
	.4byte gUnknown_8280086                  @ 064
	.4byte gUnknown_8279554                  @ 065
	.4byte gUnknown_8280BEB                  @ 066
	.4byte gUnknown_827B060                  @ 067
	.4byte gUnknown_82809A9                  @ 068
	.4byte gUnknown_8285087                  @ 069
	.4byte gUnknown_8277DEE                  @ 070
	.4byte gUnknown_827F526                  @ 071
	.4byte gUnknown_827F63E                  @ 072
	.4byte gUnknown_827860F                  @ 073
	.4byte gUnknown_827A33F                  @ 074
	.4byte gUnknown_8280EDB                  @ 075
	.4byte gUnknown_827EE64                  @ 076
	.4byte gUnknown_82779A8                  @ 077
	.4byte gUnknown_8277AD9                  @ 078
	.4byte gUnknown_8277C07                  @ 079
	.4byte gUnknown_8280DA3                  @ 080
	.4byte gUnknown_8281D95                  @ 081
	.4byte gUnknown_827E9B9                  @ 082
	.4byte gUnknown_8279222                  @ 083
	.4byte gUnknown_8278928                  @ 084
	.4byte gUnknown_8278996                  @ 085
	.4byte gUnknown_8278B4C                  @ 086
	.4byte gUnknown_827DEC1                  @ 087
	.4byte gUnknown_827A4EB                  @ 088
	.4byte gUnknown_827B0BD                  @ 089
	.4byte gUnknown_827B10A                  @ 090
	.4byte gUnknown_827B22D                  @ 091
	.4byte gUnknown_827FA82                  @ 092
	.4byte gUnknown_827DDB0                  @ 093
	.4byte gUnknown_827DE11                  @ 094
	.4byte gUnknown_8281739                  @ 095
	.4byte gUnknown_827B349                  @ 096
	.4byte gUnknown_827B366                  @ 097
	.4byte gUnknown_827B3B0                  @ 098
	.4byte gUnknown_827B408                  @ 099
	.4byte gUnknown_827B47E                  @ 100
	.4byte gUnknown_8281B0A                  @ 101
	.4byte gUnknown_82820C6                  @ 102
	.4byte gUnknown_8277FA5                  @ 103
	.4byte gUnknown_827B497                  @ 104
	.4byte gUnknown_828201C                  @ 105
	.4byte gUnknown_827DA50                  @ 106
	.4byte gUnknown_827B4DE                  @ 107
	.4byte gUnknown_827A89C                  @ 108
	.4byte gUnknown_827A41D                  @ 109
	.4byte gUnknown_827ED83                  @ 110
	.4byte gUnknown_8279908                  @ 111
	.4byte gUnknown_827E67E                  @ 112
	.4byte gUnknown_827E579                  @ 113
	.4byte gUnknown_82811D1                  @ 114
	.4byte gUnknown_827E62B                  @ 115
	.4byte gUnknown_8281C56                  @ 116
	.4byte gUnknown_8281C96                  @ 117
	.4byte gUnknown_827B4F1                  @ 118
	.4byte gUnknown_8277924                  @ 119
	.4byte gUnknown_82793A5                  @ 120
	.4byte gUnknown_8281B52                  @ 121
	.4byte gUnknown_8281C2F                  @ 122
	.4byte gUnknown_827E771                  @ 123
	.4byte gUnknown_827FAF1                  @ 124
	.4byte gUnknown_827FDA7                  @ 125
	.4byte gUnknown_82784E1                  @ 126
	.4byte gUnknown_82795AD                  @ 127
	.4byte gUnknown_827EBEF                  @ 128
	.4byte gUnknown_8277D35                  @ 129
	.4byte gUnknown_827B51B                  @ 130
	.4byte gUnknown_8278F7D                  @ 131
	.4byte gUnknown_8282111                  @ 132
	.4byte gUnknown_827B5E1                  @ 133
	.4byte gUnknown_827B605                  @ 134
	.4byte gUnknown_8282239                  @ 135
	.4byte gUnknown_8280752                  @ 136
	.4byte gUnknown_827B656                  @ 137
	.4byte gUnknown_828136E                  @ 138
	.4byte gUnknown_8281571                  @ 139
	.4byte gUnknown_827B6BF                  @ 140
	.4byte gUnknown_827F9D6                  @ 141
	.4byte gUnknown_82825BC                  @ 142
	.4byte gUnknown_827B707                  @ 143
	.4byte gUnknown_8283161                  @ 144
	.4byte gUnknown_827E69B                  @ 145
	.4byte gUnknown_82790E8                  @ 146
	.4byte gUnknown_8280D3E                  @ 147
	.4byte gUnknown_827B89F                  @ 148
	.4byte gUnknown_8281799                  @ 149
	.4byte gUnknown_827B8AC                  @ 150
	.4byte gUnknown_827B8C1                  @ 151
	.4byte gUnknown_8280257                  @ 152
	.4byte gUnknown_8279801                  @ 153
	.4byte gUnknown_8282603                  @ 154
	.4byte gUnknown_827FD53                  @ 155
	.4byte gUnknown_827DD70                  @ 156
	.4byte gUnknown_827A577                  @ 157
	.4byte gUnknown_8282AB5                  @ 158
	.4byte gUnknown_827B8DA                  @ 159
	.4byte gUnknown_827A995                  @ 160
	.4byte gUnknown_8282B1C                  @ 161
	.4byte gUnknown_827B8E6                  @ 162
	.4byte gUnknown_827B967                  @ 163
	.4byte gUnknown_8283D8E                  @ 164
	.4byte gUnknown_827B9A1                  @ 165
	.4byte gUnknown_827BA07                  @ 166
	.4byte gUnknown_828081A                  @ 167
	.4byte gUnknown_827A6B8                  @ 168
	.4byte gUnknown_8281E67                  @ 169
	.4byte gUnknown_827DB4D                  @ 170
	.4byte gUnknown_827BA2F                  @ 171
	.4byte gUnknown_8277FF2                  @ 172
	.4byte gUnknown_827E4E9                  @ 173
	.4byte gUnknown_8282179                  @ 174
	.4byte gUnknown_827BA85                  @ 175
	.4byte gUnknown_827AAAA                  @ 176
	.4byte gUnknown_82800AD                  @ 177
	.4byte gUnknown_8280CE4                  @ 178
	.4byte gUnknown_8278E31                  @ 179
	.4byte gUnknown_827BAC2                  @ 180
	.4byte gUnknown_827F245                  @ 181
	.4byte gUnknown_8279941                  @ 182
	.4byte gUnknown_827BAF1                  @ 183
	.4byte gUnknown_82824F0                  @ 184
	.4byte gUnknown_827E7EC                  @ 185
	.4byte gUnknown_8282553                  @ 186
	.4byte gUnknown_827DA65                  @ 187
	.4byte gUnknown_827FB33                  @ 188
	.4byte gUnknown_827E91B                  @ 189
	.4byte gUnknown_828110A                  @ 190
	.4byte gUnknown_827FE54                  @ 191
	.4byte gUnknown_828181F                  @ 192
	.4byte gUnknown_827BB79                  @ 193
	.4byte gUnknown_827BBB8                  @ 194
	.4byte gUnknown_8282891                  @ 195
	.4byte gUnknown_827A7DC                  @ 196
	.4byte gUnknown_827995E                  @ 197
	.4byte gUnknown_827FE09                  @ 198
	.4byte gUnknown_827A470                  @ 199
	.4byte gUnknown_8279E94                  @ 200
	.4byte gUnknown_8280402                  @ 201
	.4byte gUnknown_827F7CE                  @ 202
	.4byte gUnknown_827BC13                  @ 203
	.4byte gUnknown_827BCA7                  @ 204
	.4byte gUnknown_827BCEA                  @ 205
	.4byte gUnknown_827BD2B                  @ 206
	.4byte gUnknown_827BDB2                  @ 207
	.4byte gUnknown_827BDFA                  @ 208
	.4byte gUnknown_827A02F                  @ 209
	.4byte gUnknown_82792D6                  @ 210
	.4byte gUnknown_8281904                  @ 211
	.4byte gUnknown_827A4A6                  @ 212
	.4byte gUnknown_827A246                  @ 213
	.4byte gUnknown_82829FA                  @ 214
	.4byte gUnknown_82822BB                  @ 215
	.4byte gUnknown_8284055                  @ 216
	.4byte gUnknown_8282718                  @ 217
	.4byte gUnknown_82799BC                  @ 218
	.4byte gUnknown_8279C83                  @ 219
	.4byte gUnknown_8279CC5                  @ 220
	.4byte gUnknown_827E0E4                  @ 221
	.4byte gUnknown_827BE3C                  @ 222
	.4byte gUnknown_82808E1                  @ 223
	.4byte gUnknown_827FEAB                  @ 224
	.4byte gUnknown_827E2FD                  @ 225
	.4byte gUnknown_828286F                  @ 226
	.4byte gUnknown_8282D4E                  @ 227
	.4byte gUnknown_8278F0C                  @ 228
	.4byte gUnknown_827BECD                  @ 229
	.4byte gUnknown_828320D                  @ 230
	.4byte gUnknown_82819B3                  @ 231
	.4byte gUnknown_8281A77                  @ 232
	.4byte gUnknown_8280A78                  @ 233
	.4byte gUnknown_8283179                  @ 234
	.4byte gUnknown_827FA58                  @ 235
	.4byte gUnknown_827BF3A                  @ 236
	.4byte gUnknown_8278D48                  @ 237
	.4byte gUnknown_828068C                  @ 238
	.4byte gUnknown_82855AB                  @ 239
	.4byte gUnknown_827EA96                  @ 240
	.4byte gUnknown_8280C8E                  @ 241
	.4byte gUnknown_827EB3F                  @ 242
	.4byte gUnknown_827E605                  @ 243
	.4byte gUnknown_8279076                  @ 244
	.4byte gUnknown_827BFCA                  @ 245
	.4byte gUnknown_8280FE2                  @ 246
	.4byte gUnknown_8281BEC                  @ 247
	.4byte gUnknown_827DE74                  @ 248
	.4byte gUnknown_8280AF3                  @ 249
	.4byte gUnknown_828048A                  @ 250
	.4byte gUnknown_8278BBB                  @ 251
	.4byte gUnknown_82824B5                  @ 252
	.4byte gUnknown_827C088                  @ 253
	.4byte gUnknown_8282EBB                  @ 254
	.4byte gUnknown_8282F72                  @ 255
	.4byte gUnknown_82830B5                  @ 256
	.4byte gUnknown_827C152                  @ 257
	.4byte gUnknown_827C202                  @ 258
	.4byte gUnknown_827C23A                  @ 259
	.4byte gUnknown_8283439                  @ 260
	.4byte gUnknown_8282C90                  @ 261
	.4byte gUnknown_827C27E                  @ 262
	.4byte gUnknown_827C2C2                  @ 263
	.4byte gUnknown_8283F8E                  @ 264
	.4byte gUnknown_827C2E2                  @ 265
	.4byte gUnknown_827C33D                  @ 266
	.4byte gUnknown_8280FE2                  @ 267
	.4byte gUnknown_827C35C                  @ 268
	.4byte gUnknown_827C3F7                  @ 269
	.4byte gUnknown_827C44B                  @ 270
	.4byte gUnknown_8282DF5                  @ 271
	.4byte gUnknown_8283535                  @ 272
	.4byte gUnknown_8282E73                  @ 273
	.4byte gUnknown_827C4BE                  @ 274
	.4byte gUnknown_8282667                  @ 275
	.4byte gUnknown_827C52F                  @ 276
	.4byte gUnknown_82851E4                  @ 277
	.4byte gUnknown_827C5EA                  @ 278
	.4byte gUnknown_8283CB8                  @ 279
	.4byte gUnknown_827C61E                  @ 280
	.4byte gUnknown_827C7DF                  @ 281
	.4byte gUnknown_828536A                  @ 282
	.4byte gUnknown_827C822                  @ 283
	.4byte gUnknown_827C897                  @ 284
	.4byte gUnknown_827C964                  @ 285
	.4byte gUnknown_827C9AF                  @ 286
	.4byte gUnknown_8283592                  @ 287
	.4byte gUnknown_827C9F2                  @ 288
	.4byte gUnknown_8284AAA                  @ 289
	.4byte gUnknown_8285557                  @ 290
	.4byte gUnknown_8284AC4                  @ 291
	.4byte gUnknown_82837EE                  @ 292
	.4byte gUnknown_827CA1A                  @ 293
	.4byte gUnknown_827CA60                  @ 294
	.4byte gUnknown_827CAA3                  @ 295
	.4byte gUnknown_827CBBA                  @ 296
	.4byte gUnknown_827CC49                  @ 297
	.4byte gUnknown_827CD19                  @ 298
	.4byte gUnknown_82835D5                  @ 299
	.4byte gUnknown_827CD84                  @ 300
	.4byte gUnknown_828582B                  @ 301
	.4byte gUnknown_827CEBB                  @ 302
	.4byte gUnknown_827D06B                  @ 303
	.4byte gUnknown_828365D                  @ 304
	.4byte gUnknown_8283D4F                  @ 305
	.4byte gUnknown_827D083                  @ 306
	.4byte gUnknown_8284569                  @ 307
	.4byte gUnknown_8284F0D                  @ 308
	.4byte gUnknown_8283C31                  @ 309
	.4byte gUnknown_828503F                  @ 310
	.4byte gUnknown_82859FA                  @ 311
	.4byte gUnknown_827D0F2                  @ 312
	.4byte gUnknown_827D254                  @ 313
	.4byte gUnknown_827D2E4                  @ 314
	.4byte gUnknown_8284C1B                  @ 315
	.4byte gUnknown_827D346                  @ 316
	.4byte gUnknown_82847AB                  @ 317
	.4byte gUnknown_8284892                  @ 318
	.4byte gUnknown_8283F3E                  @ 319
	.4byte gUnknown_827D390                  @ 320
	.4byte gUnknown_827D483                  @ 321
	.4byte gUnknown_82844E4                  @ 322
	.4byte gUnknown_827D4EF                  @ 323
	.4byte gUnknown_827F43E                  @ 324
	.4byte gUnknown_827D51D                  @ 325
	.4byte gUnknown_827D578                  @ 326
	.4byte gUnknown_828545E                  @ 327
	.4byte gUnknown_82836F1                  @ 328
	.4byte gUnknown_82837C9                  @ 329
	.4byte gUnknown_8283883                  @ 330
	.4byte gUnknown_8283895                  @ 331
	.4byte gUnknown_827D5E0                  @ 332
	.4byte gUnknown_82781B1                  @ 333
	.4byte gUnknown_827D64A                  @ 334
	.4byte gUnknown_827D674                  @ 335
	.4byte gUnknown_827D683                  @ 336
	.4byte gUnknown_828392B                  @ 337
	.4byte gUnknown_8283D9A                  @ 338
	.4byte gUnknown_827D6A5                  @ 339
	.4byte gUnknown_82805D7                  @ 340
	.4byte gUnknown_8283B94                  @ 341
	.4byte gUnknown_8281A11                  @ 342
	.4byte gUnknown_827D6C3                  @ 343
	.4byte gUnknown_827D720                  @ 344
	.4byte gUnknown_828570A                  @ 345
	.4byte gUnknown_827D818                  @ 346
	.4byte gUnknown_827D83E                  @ 347
	.4byte gUnknown_827D8BC                  @ 348
	.4byte gUnknown_827D93F                  @ 349
	.4byte gUnknown_8284B7E                  @ 350
	.4byte gUnknown_827D9AE                  @ 351
	.4byte gUnknown_8285201                  @ 352
	.4byte gUnknown_82853FA                  @ 353
	.4byte gUnknown_82852F6                  @ 354
	.4byte gUnknown_8285C76                  @ 355

	.globl gBattleAnims_StatusConditions
gBattleAnims_StatusConditions: @ 0x8277888
	.4byte gUnknown_82862E1                  @ 000
	.4byte gUnknown_828630C                  @ 001
	.4byte gUnknown_8286315                  @ 002
	.4byte gUnknown_8286345                  @ 003
	.4byte gUnknown_828637A                  @ 004
	.4byte gUnknown_82863A6                  @ 005
	.4byte gUnknown_82863C0                  @ 006
	.4byte gUnknown_82863DB                  @ 007
	.4byte gUnknown_8286400                  @ 008

	.globl gUnknown_82778AC
gUnknown_82778AC: @ 0x82778AC
	.4byte gUnknown_8286425                  @ 000
	.4byte gUnknown_828645B                  @ 001
	.4byte gUnknown_8286464                  @ 002
	.4byte gUnknown_82864A1                  @ 003
	.4byte gUnknown_82864A9                  @ 004
	.4byte gUnknown_82864F1                  @ 005
	.4byte gUnknown_82864FC                  @ 006
	.4byte gUnknown_828668F                  @ 007
	.4byte gUnknown_8286703                  @ 008
	.4byte gUnknown_82867DF                  @ 009
	.4byte gUnknown_828682C                  @ 010
	.4byte gUnknown_8286875                  @ 011
	.4byte gUnknown_828687A                  @ 012
	.4byte gUnknown_828687F                  @ 013
	.4byte gUnknown_8286884                  @ 014
	.4byte gUnknown_8286892                  @ 015
	.4byte gUnknown_82868C3                  @ 016
	.4byte gUnknown_82868E8                  @ 017
	.4byte gUnknown_8286946                  @ 018
	.4byte gUnknown_82869A5                  @ 019
	.4byte gUnknown_8286A6A                  @ 020
	.4byte gUnknown_8286AAA                  @ 021
	.4byte gUnknown_8286AED                  @ 022

	.globl gUnknown_8277908
gUnknown_8277908: @ 0x8277908
	.4byte 0x08286B6A, 0x08286B8B, 0x08286B9C, 0x08286BAD, 0x08286C01, 0x08286C1A, 0x08286C24
gUnknown_8277924: @ 0x8277924
	.include "data/scripts/gUnknown_8277924.inc"
gUnknown_8277955: @ 0x8277955
	.include "data/scripts/gUnknown_8277955.inc"
gUnknown_82779A8: @ 0x82779A8
	.include "data/scripts/gUnknown_82779A8.inc"
gUnknown_8277AD9: @ 0x8277AD9
	.include "data/scripts/gUnknown_8277AD9.inc"
gUnknown_8277C07: @ 0x8277C07
	.include "data/scripts/gUnknown_8277C07.inc"
gUnknown_8277D35: @ 0x8277D35
	.include "data/scripts/gUnknown_8277D35.inc"
gUnknown_8277DEE: @ 0x8277DEE
	.include "data/scripts/gUnknown_8277DEE.inc"
gUnknown_8277E82: @ 0x8277E82
	.include "data/scripts/gUnknown_8277E82.inc"
gUnknown_8277EC0: @ 0x8277EC0
	.include "data/scripts/gUnknown_8277EC0.inc"
gUnknown_8277F4D: @ 0x8277F4D
	.include "data/scripts/gUnknown_8277F4D.inc"
gUnknown_8277FA5: @ 0x8277FA5
	.include "data/scripts/gUnknown_8277FA5.inc"
gUnknown_8277FF2: @ 0x8277FF2
	.include "data/scripts/gUnknown_8277FF2.inc"
gUnknown_82780EC: @ 0x82780EC
	.include "data/scripts/gUnknown_82780EC.inc"
gUnknown_82781B1: @ 0x82781B1
	.include "data/scripts/gUnknown_82781B1.inc"
gUnknown_8278276: @ 0x8278276
	.include "data/scripts/gUnknown_8278276.inc"
gUnknown_8278306: @ 0x8278306
	.include "data/scripts/gUnknown_8278306.inc"
gUnknown_8278419: @ 0x8278419
	.include "data/scripts/gUnknown_8278419.inc"
gUnknown_827846E: @ 0x827846E
	.include "data/scripts/gUnknown_827846E.inc"
gUnknown_82784E1: @ 0x82784E1
	.include "data/scripts/gUnknown_82784E1.inc"
gUnknown_827860F: @ 0x827860F
	.include "data/scripts/gUnknown_827860F.inc"
gUnknown_8278665: @ 0x8278665
	.include "data/scripts/gUnknown_8278665.inc"
gUnknown_82786D9: @ 0x82786D9
	.include "data/scripts/gUnknown_82786D9.inc"
gUnknown_82787B3: @ 0x82787B3
	.include "data/scripts/gUnknown_82787B3.inc"
gUnknown_827884F: @ 0x827884F
	.include "data/scripts/gUnknown_827884F.inc"
gUnknown_82788C7: @ 0x82788C7
	.include "data/scripts/gUnknown_82788C7.inc"
gUnknown_8278928: @ 0x8278928
	.include "data/scripts/gUnknown_8278928.inc"
gUnknown_8278996: @ 0x8278996
	.include "data/scripts/gUnknown_8278996.inc"
gUnknown_8278B4C: @ 0x8278B4C
	.include "data/scripts/gUnknown_8278B4C.inc"
gUnknown_8278BBB: @ 0x8278BBB
	.include "data/scripts/gUnknown_8278BBB.inc"
gUnknown_8278CB6: @ 0x8278CB6
	.include "data/scripts/gUnknown_8278CB6.inc"
gUnknown_8278CFD: @ 0x8278CFD
	.include "data/scripts/gUnknown_8278CFD.inc"
gUnknown_8278D16: @ 0x8278D16
	.include "data/scripts/gUnknown_8278D16.inc"
gUnknown_8278D48: @ 0x8278D48
	.include "data/scripts/gUnknown_8278D48.inc"
gUnknown_8278E31: @ 0x8278E31
	.include "data/scripts/gUnknown_8278E31.inc"
gUnknown_8278F0C: @ 0x8278F0C
	.include "data/scripts/gUnknown_8278F0C.inc"
gUnknown_8278F7D: @ 0x8278F7D
	.include "data/scripts/gUnknown_8278F7D.inc"
gUnknown_8279030: @ 0x8279030
	.include "data/scripts/gUnknown_8279030.inc"
gUnknown_8279076: @ 0x8279076
	.include "data/scripts/gUnknown_8279076.inc"
gUnknown_82790E8: @ 0x82790E8
	.include "data/scripts/gUnknown_82790E8.inc"
gUnknown_8279222: @ 0x8279222
	.include "data/scripts/gUnknown_8279222.inc"
gUnknown_82792D6: @ 0x82792D6
	.include "data/scripts/gUnknown_82792D6.inc"
gUnknown_82793A5: @ 0x82793A5
	.include "data/scripts/gUnknown_82793A5.inc"
gUnknown_8279495: @ 0x8279495
	.include "data/scripts/gUnknown_8279495.inc"
gUnknown_827951D: @ 0x827951D
	.include "data/scripts/gUnknown_827951D.inc"
gUnknown_8279554: @ 0x8279554
	.include "data/scripts/gUnknown_8279554.inc"
gUnknown_82795AD: @ 0x82795AD
	.include "data/scripts/gUnknown_82795AD.inc"
gUnknown_8279801: @ 0x8279801
	.include "data/scripts/gUnknown_8279801.inc"
gUnknown_8279908: @ 0x8279908
	.include "data/scripts/gUnknown_8279908.inc"
gUnknown_8279941: @ 0x8279941
	.include "data/scripts/gUnknown_8279941.inc"
gUnknown_827995E: @ 0x827995E
	.include "data/scripts/gUnknown_827995E.inc"
gUnknown_82799BC: @ 0x82799BC
	.include "data/scripts/gUnknown_82799BC.inc"
gUnknown_8279C83: @ 0x8279C83
	.include "data/scripts/gUnknown_8279C83.inc"
gUnknown_8279CC5: @ 0x8279CC5
	.include "data/scripts/gUnknown_8279CC5.inc"
gUnknown_8279D6D: @ 0x8279D6D
	.include "data/scripts/gUnknown_8279D6D.inc"
gUnknown_8279DB5: @ 0x8279DB5
	.include "data/scripts/gUnknown_8279DB5.inc"
gUnknown_8279E41: @ 0x8279E41
	.include "data/scripts/gUnknown_8279E41.inc"
gUnknown_8279E94: @ 0x8279E94
	.include "data/scripts/gUnknown_8279E94.inc"
gUnknown_827A02F: @ 0x827A02F
	.include "data/scripts/gUnknown_827A02F.inc"
gUnknown_827A246: @ 0x827A246
	.include "data/scripts/gUnknown_827A246.inc"
gUnknown_827A33F: @ 0x827A33F
	.include "data/scripts/gUnknown_827A33F.inc"
gUnknown_827A375: @ 0x827A375
	.include "data/scripts/gUnknown_827A375.inc"
gUnknown_827A41D: @ 0x827A41D
	.include "data/scripts/gUnknown_827A41D.inc"
gUnknown_827A470: @ 0x827A470
	.include "data/scripts/gUnknown_827A470.inc"
gUnknown_827A4A6: @ 0x827A4A6
	.include "data/scripts/gUnknown_827A4A6.inc"
gUnknown_827A4EB: @ 0x827A4EB
	.include "data/scripts/gUnknown_827A4EB.inc"
gUnknown_827A577: @ 0x827A577
	.include "data/scripts/gUnknown_827A577.inc"
gUnknown_827A6B8: @ 0x827A6B8
	.include "data/scripts/gUnknown_827A6B8.inc"
gUnknown_827A6FF: @ 0x827A6FF
	.include "data/scripts/gUnknown_827A6FF.inc"
gUnknown_827A7DC: @ 0x827A7DC
	.include "data/scripts/gUnknown_827A7DC.inc"
gUnknown_827A89C: @ 0x827A89C
	.include "data/scripts/gUnknown_827A89C.inc"
gUnknown_827A995: @ 0x827A995
	.include "data/scripts/gUnknown_827A995.inc"
gUnknown_827AAAA: @ 0x827AAAA
	.include "data/scripts/gUnknown_827AAAA.inc"
gUnknown_827ABC6: @ 0x827ABC6
	.include "data/scripts/gUnknown_827ABC6.inc"
gUnknown_827AC49: @ 0x827AC49
	.include "data/scripts/gUnknown_827AC49.inc"
gUnknown_827ACA6: @ 0x827ACA6
	.include "data/scripts/gUnknown_827ACA6.inc"
gUnknown_827AD13: @ 0x827AD13
	.include "data/scripts/gUnknown_827AD13.inc"
gUnknown_827AD90: @ 0x827AD90
	.include "data/scripts/gUnknown_827AD90.inc"
gUnknown_827AF0D: @ 0x827AF0D
	.include "data/scripts/gUnknown_827AF0D.inc"
gUnknown_827AF8C: @ 0x827AF8C
	.include "data/scripts/gUnknown_827AF8C.inc"
gUnknown_827B060: @ 0x827B060
	.include "data/scripts/gUnknown_827B060.inc"
gUnknown_827B0BD: @ 0x827B0BD
	.include "data/scripts/gUnknown_827B0BD.inc"
gUnknown_827B10A: @ 0x827B10A
	.include "data/scripts/gUnknown_827B10A.inc"
gUnknown_827B22D: @ 0x827B22D
	.include "data/scripts/gUnknown_827B22D.inc"
gUnknown_827B349: @ 0x827B349
	.include "data/scripts/gUnknown_827B349.inc"
gUnknown_827B366: @ 0x827B366
	.include "data/scripts/gUnknown_827B366.inc"
gUnknown_827B3B0: @ 0x827B3B0
	.include "data/scripts/gUnknown_827B3B0.inc"
gUnknown_827B408: @ 0x827B408
	.include "data/scripts/gUnknown_827B408.inc"
gUnknown_827B47E: @ 0x827B47E
	.include "data/scripts/gUnknown_827B47E.inc"
gUnknown_827B497: @ 0x827B497
	.include "data/scripts/gUnknown_827B497.inc"
gUnknown_827B4DE: @ 0x827B4DE
	.include "data/scripts/gUnknown_827B4DE.inc"
gUnknown_827B4F1: @ 0x827B4F1
	.include "data/scripts/gUnknown_827B4F1.inc"
gUnknown_827B51B: @ 0x827B51B
	.include "data/scripts/gUnknown_827B51B.inc"
gUnknown_827B5E1: @ 0x827B5E1
	.include "data/scripts/gUnknown_827B5E1.inc"
gUnknown_827B605: @ 0x827B605
	.include "data/scripts/gUnknown_827B605.inc"
gUnknown_827B656: @ 0x827B656
	.include "data/scripts/gUnknown_827B656.inc"
gUnknown_827B6BF: @ 0x827B6BF
	.include "data/scripts/gUnknown_827B6BF.inc"
gUnknown_827B707: @ 0x827B707
	.include "data/scripts/gUnknown_827B707.inc"
gUnknown_827B89F: @ 0x827B89F
	.include "data/scripts/gUnknown_827B89F.inc"
gUnknown_827B8AC: @ 0x827B8AC
	.include "data/scripts/gUnknown_827B8AC.inc"
gUnknown_827B8C1: @ 0x827B8C1
	.include "data/scripts/gUnknown_827B8C1.inc"
gUnknown_827B8DA: @ 0x827B8DA
	.4byte 0x0227C900, 0x0856E9C8, 0x08050002
gUnknown_827B8E6: @ 0x827B8E6
	.include "data/scripts/gUnknown_827B8E6.inc"
gUnknown_827B967: @ 0x827B967
	.include "data/scripts/gUnknown_827B967.inc"
gUnknown_827B9A1: @ 0x827B9A1
	.include "data/scripts/gUnknown_827B9A1.inc"
gUnknown_827BA07: @ 0x827BA07
	.include "data/scripts/gUnknown_827BA07.inc"
gUnknown_827BA2F: @ 0x827BA2F
	.include "data/scripts/gUnknown_827BA2F.inc"
gUnknown_827BA85: @ 0x827BA85
	.include "data/scripts/gUnknown_827BA85.inc"
gUnknown_827BAC2: @ 0x827BAC2
	.include "data/scripts/gUnknown_827BAC2.inc"
gUnknown_827BAF1: @ 0x827BAF1
	.include "data/scripts/gUnknown_827BAF1.inc"
gUnknown_827BB79: @ 0x827BB79
	.include "data/scripts/gUnknown_827BB79.inc"
gUnknown_827BBB8: @ 0x827BBB8
	.include "data/scripts/gUnknown_827BBB8.inc"
gUnknown_827BC13: @ 0x827BC13
	.include "data/scripts/gUnknown_827BC13.inc"
gUnknown_827BCA7: @ 0x827BCA7
	.include "data/scripts/gUnknown_827BCA7.inc"
gUnknown_827BCEA: @ 0x827BCEA
	.include "data/scripts/gUnknown_827BCEA.inc"
gUnknown_827BD2B: @ 0x827BD2B
	.include "data/scripts/gUnknown_827BD2B.inc"
gUnknown_827BDB2: @ 0x827BDB2
	.include "data/scripts/gUnknown_827BDB2.inc"
gUnknown_827BDFA: @ 0x827BDFA
	.include "data/scripts/gUnknown_827BDFA.inc"
gUnknown_827BE3C: @ 0x827BE3C
	.include "data/scripts/gUnknown_827BE3C.inc"
gUnknown_827BECD: @ 0x827BECD
	.include "data/scripts/gUnknown_827BECD.inc"
gUnknown_827BF3A: @ 0x827BF3A
	.include "data/scripts/gUnknown_827BF3A.inc"
gUnknown_827BFCA: @ 0x827BFCA
	.include "data/scripts/gUnknown_827BFCA.inc"
gUnknown_827C088: @ 0x827C088
	.include "data/scripts/gUnknown_827C088.inc"
gUnknown_827C152: @ 0x827C152
	.include "data/scripts/gUnknown_827C152.inc"
gUnknown_827C202: @ 0x827C202
	.include "data/scripts/gUnknown_827C202.inc"
gUnknown_827C23A: @ 0x827C23A
	.include "data/scripts/gUnknown_827C23A.inc"
gUnknown_827C27E: @ 0x827C27E
	.include "data/scripts/gUnknown_827C27E.inc"
gUnknown_827C2C2: @ 0x827C2C2
	.include "data/scripts/gUnknown_827C2C2.inc"
gUnknown_827C2E2: @ 0x827C2E2
	.include "data/scripts/gUnknown_827C2E2.inc"
gUnknown_827C33D: @ 0x827C33D
	.include "data/scripts/gUnknown_827C33D.inc"
gUnknown_827C35C: @ 0x827C35C
	.include "data/scripts/gUnknown_827C35C.inc"
gUnknown_827C3F7: @ 0x827C3F7
	.include "data/scripts/gUnknown_827C3F7.inc"
gUnknown_827C44B: @ 0x827C44B
	.include "data/scripts/gUnknown_827C44B.inc"
gUnknown_827C4BE: @ 0x827C4BE
	.include "data/scripts/gUnknown_827C4BE.inc"
gUnknown_827C52F: @ 0x827C52F
	.include "data/scripts/gUnknown_827C52F.inc"
gUnknown_827C5EA: @ 0x827C5EA
	.include "data/scripts/gUnknown_827C5EA.inc"
gUnknown_827C61E: @ 0x827C61E
	.include "data/scripts/gUnknown_827C61E.inc"
gUnknown_827C7DF: @ 0x827C7DF
	.include "data/scripts/gUnknown_827C7DF.inc"
gUnknown_827C822: @ 0x827C822
	.include "data/scripts/gUnknown_827C822.inc"
gUnknown_827C897: @ 0x827C897
	.include "data/scripts/gUnknown_827C897.inc"
gUnknown_827C964: @ 0x827C964
	.include "data/scripts/gUnknown_827C964.inc"
gUnknown_827C9AF: @ 0x827C9AF
	.include "data/scripts/gUnknown_827C9AF.inc"
gUnknown_827C9F2: @ 0x827C9F2
	.include "data/scripts/gUnknown_827C9F2.inc"
gUnknown_827CA1A: @ 0x827CA1A
	.include "data/scripts/gUnknown_827CA1A.inc"
gUnknown_827CA60: @ 0x827CA60
	.include "data/scripts/gUnknown_827CA60.inc"
gUnknown_827CAA3: @ 0x827CAA3
	.include "data/scripts/gUnknown_827CAA3.inc"
gUnknown_827CBBA: @ 0x827CBBA
	.include "data/scripts/gUnknown_827CBBA.inc"
gUnknown_827CC49: @ 0x827CC49
	.include "data/scripts/gUnknown_827CC49.inc"
gUnknown_827CD19: @ 0x827CD19
	.include "data/scripts/gUnknown_827CD19.inc"
gUnknown_827CD84: @ 0x827CD84
	.include "data/scripts/gUnknown_827CD84.inc"
gUnknown_827CEBB: @ 0x827CEBB
	.include "data/scripts/gUnknown_827CEBB.inc"
gUnknown_827D06B: @ 0x827D06B
	.include "data/scripts/gUnknown_827D06B.inc"
gUnknown_827D083: @ 0x827D083
	.include "data/scripts/gUnknown_827D083.inc"
gUnknown_827D0F2: @ 0x827D0F2
	.include "data/scripts/gUnknown_827D0F2.inc"
gUnknown_827D254: @ 0x827D254
	.include "data/scripts/gUnknown_827D254.inc"
gUnknown_827D2E4: @ 0x827D2E4
	.include "data/scripts/gUnknown_827D2E4.inc"
gUnknown_827D346: @ 0x827D346
	.include "data/scripts/gUnknown_827D346.inc"
gUnknown_827D390: @ 0x827D390
	.include "data/scripts/gUnknown_827D390.inc"
gUnknown_827D483: @ 0x827D483
	.include "data/scripts/gUnknown_827D483.inc"
gUnknown_827D4EF: @ 0x827D4EF
	.include "data/scripts/gUnknown_827D4EF.inc"
gUnknown_827D51D: @ 0x827D51D
	.include "data/scripts/gUnknown_827D51D.inc"
gUnknown_827D578: @ 0x827D578
	.include "data/scripts/gUnknown_827D578.inc"
gUnknown_827D5E0: @ 0x827D5E0
	.include "data/scripts/gUnknown_827D5E0.inc"
gUnknown_827D64A: @ 0x827D64A
	.include "data/scripts/gUnknown_827D64A.inc"
gUnknown_827D674: @ 0x827D674
	.include "data/scripts/gUnknown_827D674.inc"
gUnknown_827D683: @ 0x827D683
	.include "data/scripts/gUnknown_827D683.inc"
gUnknown_827D6A5: @ 0x827D6A5
	.include "data/scripts/gUnknown_827D6A5.inc"
gUnknown_827D6C3: @ 0x827D6C3
	.include "data/scripts/gUnknown_827D6C3.inc"
gUnknown_827D720: @ 0x827D720
	.include "data/scripts/gUnknown_827D720.inc"
gUnknown_827D818: @ 0x827D818
	.include "data/scripts/gUnknown_827D818.inc"
gUnknown_827D83E: @ 0x827D83E
	.include "data/scripts/gUnknown_827D83E.inc"
gUnknown_827D8BC: @ 0x827D8BC
	.include "data/scripts/gUnknown_827D8BC.inc"
gUnknown_827D93F: @ 0x827D93F
	.include "data/scripts/gUnknown_827D93F.inc"
gUnknown_827D9AE: @ 0x827D9AE
	.include "data/scripts/gUnknown_827D9AE.inc"
gUnknown_827DA50: @ 0x827DA50
	.include "data/scripts/gUnknown_827DA50.inc"
gUnknown_827DA65: @ 0x827DA65
	.include "data/scripts/gUnknown_827DA65.inc"
gUnknown_827DB4D: @ 0x827DB4D
	.include "data/scripts/gUnknown_827DB4D.inc"
gUnknown_827DC85: @ 0x827DC85
	.include "data/scripts/gUnknown_827DC85.inc"
gUnknown_827DD70: @ 0x827DD70
	.include "data/scripts/gUnknown_827DD70.inc"
gUnknown_827DDB0: @ 0x827DDB0
	.include "data/scripts/gUnknown_827DDB0.inc"
gUnknown_827DE11: @ 0x827DE11
	.include "data/scripts/gUnknown_827DE11.inc"
gUnknown_827DE74: @ 0x827DE74
	.include "data/scripts/gUnknown_827DE74.inc"
gUnknown_827DEC1: @ 0x827DEC1
	.include "data/scripts/gUnknown_827DEC1.inc"
gUnknown_827E01B: @ 0x827E01B
	.include "data/scripts/gUnknown_827E01B.inc"
gUnknown_827E0E4: @ 0x827E0E4
	.include "data/scripts/gUnknown_827E0E4.inc"
gUnknown_827E2CB: @ 0x827E2CB
	.include "data/scripts/gUnknown_827E2CB.inc"
gUnknown_827E2FD: @ 0x827E2FD
	.include "data/scripts/gUnknown_827E2FD.inc"
gUnknown_827E411: @ 0x827E411
	.include "data/scripts/gUnknown_827E411.inc"
gUnknown_827E4A8: @ 0x827E4A8
	.include "data/scripts/gUnknown_827E4A8.inc"
gUnknown_827E4E9: @ 0x827E4E9
	.include "data/scripts/gUnknown_827E4E9.inc"
gUnknown_827E579: @ 0x827E579
	.include "data/scripts/gUnknown_827E579.inc"
gUnknown_827E605: @ 0x827E605
	.include "data/scripts/gUnknown_827E605.inc"
gUnknown_827E62B: @ 0x827E62B
	.include "data/scripts/gUnknown_827E62B.inc"
gUnknown_827E67E: @ 0x827E67E
	.include "data/scripts/gUnknown_827E67E.inc"
gUnknown_827E69B: @ 0x827E69B
	.include "data/scripts/gUnknown_827E69B.inc"
gUnknown_827E771: @ 0x827E771
	.include "data/scripts/gUnknown_827E771.inc"
gUnknown_827E7EC: @ 0x827E7EC
	.include "data/scripts/gUnknown_827E7EC.inc"
gUnknown_827E873: @ 0x827E873
	.include "data/scripts/gUnknown_827E873.inc"
gUnknown_827E91B: @ 0x827E91B
	.include "data/scripts/gUnknown_827E91B.inc"
gUnknown_827E9B9: @ 0x827E9B9
	.include "data/scripts/gUnknown_827E9B9.inc"
gUnknown_827EA96: @ 0x827EA96
	.include "data/scripts/gUnknown_827EA96.inc"
gUnknown_827EAE1: @ 0x827EAE1
	.include "data/scripts/gUnknown_827EAE1.inc"
gUnknown_827EB3F: @ 0x827EB3F
	.include "data/scripts/gUnknown_827EB3F.inc"
gUnknown_827EBEF: @ 0x827EBEF
	.include "data/scripts/gUnknown_827EBEF.inc"
gUnknown_827EC4C: @ 0x827EC4C
	.include "data/scripts/gUnknown_827EC4C.inc"
gUnknown_827ED83: @ 0x827ED83
	.4byte 0xC000A219, 0x103EF103, 0x05000508
	.byte 0x08
gUnknown_827ED90: @ 0x827ED90
	.include "data/scripts/gUnknown_827ED90.inc"
gUnknown_827EE64: @ 0x827EE64
	.include "data/scripts/gUnknown_827EE64.inc"
gUnknown_827F0B9: @ 0x827F0B9
	.include "data/scripts/gUnknown_827F0B9.inc"
gUnknown_827F245: @ 0x827F245
	.include "data/scripts/gUnknown_827F245.inc"
gUnknown_827F33F: @ 0x827F33F
	.include "data/scripts/gUnknown_827F33F.inc"
gUnknown_827F43E: @ 0x827F43E
	.include "data/scripts/gUnknown_827F43E.inc"
gUnknown_827F526: @ 0x827F526
	.include "data/scripts/gUnknown_827F526.inc"
gUnknown_827F63E: @ 0x827F63E
	.include "data/scripts/gUnknown_827F63E.inc"
gUnknown_827F7CE: @ 0x827F7CE
	.include "data/scripts/gUnknown_827F7CE.inc"
gUnknown_827F9D6: @ 0x827F9D6
	.include "data/scripts/gUnknown_827F9D6.inc"
gUnknown_827FA58: @ 0x827FA58
	.include "data/scripts/gUnknown_827FA58.inc"
gUnknown_827FA82: @ 0x827FA82
	.include "data/scripts/gUnknown_827FA82.inc"
gUnknown_827FAF1: @ 0x827FAF1
	.include "data/scripts/gUnknown_827FAF1.inc"
gUnknown_827FB33: @ 0x827FB33
	.include "data/scripts/gUnknown_827FB33.inc"
gUnknown_827FC59: @ 0x827FC59
	.include "data/scripts/gUnknown_827FC59.inc"
gUnknown_827FD53: @ 0x827FD53
	.include "data/scripts/gUnknown_827FD53.inc"
gUnknown_827FDA7: @ 0x827FDA7
	.include "data/scripts/gUnknown_827FDA7.inc"
gUnknown_827FE09: @ 0x827FE09
	.include "data/scripts/gUnknown_827FE09.inc"
gUnknown_827FE54: @ 0x827FE54
	.include "data/scripts/gUnknown_827FE54.inc"
gUnknown_827FEAB: @ 0x827FEAB
	.include "data/scripts/gUnknown_827FEAB.inc"
gUnknown_827FF98: @ 0x827FF98
	.include "data/scripts/gUnknown_827FF98.inc"
gUnknown_827FFE9: @ 0x827FFE9
	.include "data/scripts/gUnknown_827FFE9.inc"
gUnknown_8280086: @ 0x8280086
	.include "data/scripts/gUnknown_8280086.inc"
gUnknown_82800AD: @ 0x82800AD
	.include "data/scripts/gUnknown_82800AD.inc"
gUnknown_82801CA: @ 0x82801CA
	.include "data/scripts/gUnknown_82801CA.inc"
gUnknown_8280257: @ 0x8280257
	.include "data/scripts/gUnknown_8280257.inc"
gUnknown_8280351: @ 0x8280351
	.include "data/scripts/gUnknown_8280351.inc"
gUnknown_8280365: @ 0x8280365
	.include "data/scripts/gUnknown_8280365.inc"
gUnknown_8280402: @ 0x8280402
	.include "data/scripts/gUnknown_8280402.inc"
gUnknown_828048A: @ 0x828048A
	.include "data/scripts/gUnknown_828048A.inc"
gUnknown_828056D: @ 0x828056D
	.include "data/scripts/gUnknown_828056D.inc"
gUnknown_82805D7: @ 0x82805D7
	.include "data/scripts/gUnknown_82805D7.inc"
gUnknown_828063A: @ 0x828063A
	.include "data/scripts/gUnknown_828063A.inc"
gUnknown_828068C: @ 0x828068C
	.include "data/scripts/gUnknown_828068C.inc"
gUnknown_82806F5: @ 0x82806F5
	.include "data/scripts/gUnknown_82806F5.inc"
gUnknown_8280752: @ 0x8280752
	.include "data/scripts/gUnknown_8280752.inc"
gUnknown_82807E8: @ 0x82807E8
	.include "data/scripts/gUnknown_82807E8.inc"
gUnknown_828081A: @ 0x828081A
	.include "data/scripts/gUnknown_828081A.inc"
gUnknown_82808E1: @ 0x82808E1
	.include "data/scripts/gUnknown_82808E1.inc"
gUnknown_82809A9: @ 0x82809A9
	.include "data/scripts/gUnknown_82809A9.inc"
gUnknown_8280A78: @ 0x8280A78
	.include "data/scripts/gUnknown_8280A78.inc"
gUnknown_8280AF3: @ 0x8280AF3
	.include "data/scripts/gUnknown_8280AF3.inc"
gUnknown_8280BEB: @ 0x8280BEB
	.include "data/scripts/gUnknown_8280BEB.inc"
gUnknown_8280C8E: @ 0x8280C8E
	.include "data/scripts/gUnknown_8280C8E.inc"
gUnknown_8280CE4: @ 0x8280CE4
	.include "data/scripts/gUnknown_8280CE4.inc"
gUnknown_8280D3E: @ 0x8280D3E
	.include "data/scripts/gUnknown_8280D3E.inc"
gUnknown_8280DA3: @ 0x8280DA3
	.include "data/scripts/gUnknown_8280DA3.inc"
gUnknown_8280EDB: @ 0x8280EDB
	.include "data/scripts/gUnknown_8280EDB.inc"
gUnknown_8280FE2: @ 0x8280FE2
	.include "data/scripts/gUnknown_8280FE2.inc"
gUnknown_828110A: @ 0x828110A
	.include "data/scripts/gUnknown_828110A.inc"
gUnknown_8281170: @ 0x8281170
	.include "data/scripts/gUnknown_8281170.inc"
gUnknown_82811D1: @ 0x82811D1
	.include "data/scripts/gUnknown_82811D1.inc"
gUnknown_8281204: @ 0x8281204
	.include "data/scripts/gUnknown_8281204.inc"
gUnknown_8281317: @ 0x8281317
	.include "data/scripts/gUnknown_8281317.inc"
gUnknown_828136E: @ 0x828136E
	.include "data/scripts/gUnknown_828136E.inc"
gUnknown_8281571: @ 0x8281571
	.include "data/scripts/gUnknown_8281571.inc"
gUnknown_828164F: @ 0x828164F
	.include "data/scripts/gUnknown_828164F.inc"
gUnknown_8281689: @ 0x8281689
	.include "data/scripts/gUnknown_8281689.inc"
gUnknown_828169F: @ 0x828169F
	.include "data/scripts/gUnknown_828169F.inc"
gUnknown_8281739: @ 0x8281739
	.include "data/scripts/gUnknown_8281739.inc"
gUnknown_8281799: @ 0x8281799
	.include "data/scripts/gUnknown_8281799.inc"
gUnknown_828181F: @ 0x828181F
	.include "data/scripts/gUnknown_828181F.inc"
gUnknown_8281904: @ 0x8281904
	.include "data/scripts/gUnknown_8281904.inc"
gUnknown_82819B3: @ 0x82819B3
	.include "data/scripts/gUnknown_82819B3.inc"
gUnknown_8281A11: @ 0x8281A11
	.include "data/scripts/gUnknown_8281A11.inc"
gUnknown_8281A77: @ 0x8281A77
	.include "data/scripts/gUnknown_8281A77.inc"
gUnknown_8281B0A: @ 0x8281B0A
	.include "data/scripts/gUnknown_8281B0A.inc"
gUnknown_8281B52: @ 0x8281B52
	.include "data/scripts/gUnknown_8281B52.inc"
gUnknown_8281BEC: @ 0x8281BEC
	.include "data/scripts/gUnknown_8281BEC.inc"
gUnknown_8281C2F: @ 0x8281C2F
	.include "data/scripts/gUnknown_8281C2F.inc"
gUnknown_8281C56: @ 0x8281C56
	.include "data/scripts/gUnknown_8281C56.inc"
gUnknown_8281C96: @ 0x8281C96
	.include "data/scripts/gUnknown_8281C96.inc"
gUnknown_8281D95: @ 0x8281D95
	.include "data/scripts/gUnknown_8281D95.inc"
gUnknown_8281E67: @ 0x8281E67
	.include "data/scripts/gUnknown_8281E67.inc"
gUnknown_8281F08: @ 0x8281F08
	.include "data/scripts/gUnknown_8281F08.inc"
gUnknown_8281FEE: @ 0x8281FEE
	.include "data/scripts/gUnknown_8281FEE.inc"
gUnknown_828201C: @ 0x828201C
	.include "data/scripts/gUnknown_828201C.inc"
gUnknown_82820C6: @ 0x82820C6
	.include "data/scripts/gUnknown_82820C6.inc"
gUnknown_8282111: @ 0x8282111
	.include "data/scripts/gUnknown_8282111.inc"
gUnknown_8282179: @ 0x8282179
	.include "data/scripts/gUnknown_8282179.inc"
gUnknown_8282239: @ 0x8282239
	.include "data/scripts/gUnknown_8282239.inc"
gUnknown_82822BB: @ 0x82822BB
	.include "data/scripts/gUnknown_82822BB.inc"
gUnknown_82824B5: @ 0x82824B5
	.include "data/scripts/gUnknown_82824B5.inc"
gUnknown_82824F0: @ 0x82824F0
	.include "data/scripts/gUnknown_82824F0.inc"
gUnknown_8282553: @ 0x8282553
	.include "data/scripts/gUnknown_8282553.inc"
gUnknown_82825BC: @ 0x82825BC
	.include "data/scripts/gUnknown_82825BC.inc"
gUnknown_8282603: @ 0x8282603
	.include "data/scripts/gUnknown_8282603.inc"
gUnknown_8282667: @ 0x8282667
	.include "data/scripts/gUnknown_8282667.inc"
gUnknown_8282718: @ 0x8282718
	.include "data/scripts/gUnknown_8282718.inc"
gUnknown_828286F: @ 0x828286F
	.include "data/scripts/gUnknown_828286F.inc"
gUnknown_8282891: @ 0x8282891
	.include "data/scripts/gUnknown_8282891.inc"
gUnknown_82829FA: @ 0x82829FA
	.include "data/scripts/gUnknown_82829FA.inc"
gUnknown_8282AB5: @ 0x8282AB5
	.include "data/scripts/gUnknown_8282AB5.inc"
gUnknown_8282B1C: @ 0x8282B1C
	.include "data/scripts/gUnknown_8282B1C.inc"
gUnknown_8282C90: @ 0x8282C90
	.include "data/scripts/gUnknown_8282C90.inc"
gUnknown_8282D4E: @ 0x8282D4E
	.include "data/scripts/gUnknown_8282D4E.inc"
gUnknown_8282DF5: @ 0x8282DF5
	.include "data/scripts/gUnknown_8282DF5.inc"
gUnknown_8282E73: @ 0x8282E73
	.include "data/scripts/gUnknown_8282E73.inc"
gUnknown_8282EBB: @ 0x8282EBB
	.include "data/scripts/gUnknown_8282EBB.inc"
gUnknown_8282F72: @ 0x8282F72
	.include "data/scripts/gUnknown_8282F72.inc"
gUnknown_82830B5: @ 0x82830B5
	.include "data/scripts/gUnknown_82830B5.inc"
gUnknown_8283161: @ 0x8283161
	.include "data/scripts/gUnknown_8283161.inc"
gUnknown_8283179: @ 0x8283179
	.include "data/scripts/gUnknown_8283179.inc"
gUnknown_828320D: @ 0x828320D
	.include "data/scripts/gUnknown_828320D.inc"
gUnknown_82832F7: @ 0x82832F7
	.include "data/scripts/gUnknown_82832F7.inc"
gUnknown_8283439: @ 0x8283439
	.include "data/scripts/gUnknown_8283439.inc"
gUnknown_8283535: @ 0x8283535
	.include "data/scripts/gUnknown_8283535.inc"
gUnknown_8283592: @ 0x8283592
	.include "data/scripts/gUnknown_8283592.inc"
gUnknown_82835D5: @ 0x82835D5
	.include "data/scripts/gUnknown_82835D5.inc"
gUnknown_828365D: @ 0x828365D
	.include "data/scripts/gUnknown_828365D.inc"
gUnknown_82836F1: @ 0x82836F1
	.include "data/scripts/gUnknown_82836F1.inc"
gUnknown_82837C9: @ 0x82837C9
	.include "data/scripts/gUnknown_82837C9.inc"
gUnknown_82837EE: @ 0x82837EE
	.include "data/scripts/gUnknown_82837EE.inc"
gUnknown_8283883: @ 0x8283883
	.include "data/scripts/gUnknown_8283883.inc"
gUnknown_8283895: @ 0x8283895
	.include "data/scripts/gUnknown_8283895.inc"
gUnknown_828392B: @ 0x828392B
	.include "data/scripts/gUnknown_828392B.inc"
gUnknown_8283B94: @ 0x8283B94
	.include "data/scripts/gUnknown_8283B94.inc"
gUnknown_8283C31: @ 0x8283C31
	.include "data/scripts/gUnknown_8283C31.inc"
gUnknown_8283CB8: @ 0x8283CB8
	.include "data/scripts/gUnknown_8283CB8.inc"
gUnknown_8283D4F: @ 0x8283D4F
	.include "data/scripts/gUnknown_8283D4F.inc"
gUnknown_8283D8E: @ 0x8283D8E
	.include "data/scripts/gUnknown_8283D8E.inc"
gUnknown_8283D9A: @ 0x8283D9A
	.include "data/scripts/gUnknown_8283D9A.inc"
gUnknown_8283F3E: @ 0x8283F3E
	.include "data/scripts/gUnknown_8283F3E.inc"
gUnknown_8283F8E: @ 0x8283F8E
	.include "data/scripts/gUnknown_8283F8E.inc"
gUnknown_8284055: @ 0x8284055
	.include "data/scripts/gUnknown_8284055.inc"
gUnknown_82844E4: @ 0x82844E4
	.include "data/scripts/gUnknown_82844E4.inc"
gUnknown_8284569: @ 0x8284569
	.include "data/scripts/gUnknown_8284569.inc"
gUnknown_82847AB: @ 0x82847AB
	.include "data/scripts/gUnknown_82847AB.inc"
gUnknown_8284892: @ 0x8284892
	.include "data/scripts/gUnknown_8284892.inc"
gUnknown_8284AAA: @ 0x8284AAA
	.include "data/scripts/gUnknown_8284AAA.inc"
gUnknown_8284AC4: @ 0x8284AC4
	.include "data/scripts/gUnknown_8284AC4.inc"
gUnknown_8284B7E: @ 0x8284B7E
	.include "data/scripts/gUnknown_8284B7E.inc"
gUnknown_8284C1B: @ 0x8284C1B
	.include "data/scripts/gUnknown_8284C1B.inc"
gUnknown_8284F0D: @ 0x8284F0D
	.include "data/scripts/gUnknown_8284F0D.inc"
gUnknown_828503F: @ 0x828503F
	.include "data/scripts/gUnknown_828503F.inc"
gUnknown_8285087: @ 0x8285087
	.include "data/scripts/gUnknown_8285087.inc"
gUnknown_82851E4: @ 0x82851E4
	.include "data/scripts/gUnknown_82851E4.inc"
gUnknown_8285201: @ 0x8285201
	.include "data/scripts/gUnknown_8285201.inc"
gUnknown_82852F6: @ 0x82852F6
	.include "data/scripts/gUnknown_82852F6.inc"
gUnknown_828536A: @ 0x828536A
	.include "data/scripts/gUnknown_828536A.inc"
gUnknown_82853FA: @ 0x82853FA
	.include "data/scripts/gUnknown_82853FA.inc"
gUnknown_828545E: @ 0x828545E
	.include "data/scripts/gUnknown_828545E.inc"
gUnknown_8285557: @ 0x8285557
	.include "data/scripts/gUnknown_8285557.inc"
gUnknown_82855AB: @ 0x82855AB
	.include "data/scripts/gUnknown_82855AB.inc"
gUnknown_828570A: @ 0x828570A
	.include "data/scripts/gUnknown_828570A.inc"
gUnknown_828582B: @ 0x828582B
	.include "data/scripts/gUnknown_828582B.inc"
gUnknown_82859FA: @ 0x82859FA
	.include "data/scripts/gUnknown_82859FA.inc"
gUnknown_8285C76: @ 0x8285C76
	.include "data/scripts/gUnknown_8285C76.inc"
gUnknown_82862E1: @ 0x82862E1
	.include "data/scripts/gUnknown_82862E1.inc"
gUnknown_828630C: @ 0x828630C
	.include "data/scripts/gUnknown_828630C.inc"
gUnknown_8286315: @ 0x8286315
	.include "data/scripts/gUnknown_8286315.inc"
gUnknown_8286345: @ 0x8286345
	.include "data/scripts/gUnknown_8286345.inc"
gUnknown_828637A: @ 0x828637A
	.include "data/scripts/gUnknown_828637A.inc"
gUnknown_82863A6: @ 0x82863A6
	.include "data/scripts/gUnknown_82863A6.inc"
gUnknown_82863C0: @ 0x82863C0
	.include "data/scripts/gUnknown_82863C0.inc"
gUnknown_82863DB: @ 0x82863DB
	.include "data/scripts/gUnknown_82863DB.inc"
gUnknown_8286400: @ 0x8286400
	.include "data/scripts/gUnknown_8286400.inc"
gUnknown_8286425: @ 0x8286425
	.include "data/scripts/gUnknown_8286425.inc"
gUnknown_828645B: @ 0x828645B
	.include "data/scripts/gUnknown_828645B.inc"
gUnknown_8286464: @ 0x8286464
	.include "data/scripts/gUnknown_8286464.inc"
gUnknown_82864A1: @ 0x82864A1
	.include "data/scripts/gUnknown_82864A1.inc"
gUnknown_82864A9: @ 0x82864A9
	.include "data/scripts/gUnknown_82864A9.inc"
gUnknown_82864F1: @ 0x82864F1
	.include "data/scripts/gUnknown_82864F1.inc"
gUnknown_82864FC: @ 0x82864FC
	.include "data/scripts/gUnknown_82864FC.inc"
gUnknown_828668F: @ 0x828668F
	.include "data/scripts/gUnknown_828668F.inc"
gUnknown_8286703: @ 0x8286703
	.include "data/scripts/gUnknown_8286703.inc"
gUnknown_82867DF: @ 0x82867DF
	.include "data/scripts/gUnknown_82867DF.inc"
gUnknown_828682C: @ 0x828682C
	.include "data/scripts/gUnknown_828682C.inc"
gUnknown_8286875: @ 0x8286875
	.byte 0x13, 0x8E, 0x0C, 0x28, 0x08
gUnknown_828687A: @ 0x828687A
	.byte 0x13, 0x02, 0x04, 0x28, 0x08
gUnknown_828687F: @ 0x828687F
	.include "data/scripts/gUnknown_828687F.inc"
gUnknown_8286884: @ 0x8286884
	.include "data/scripts/gUnknown_8286884.inc"
gUnknown_8286892: @ 0x8286892
	.include "data/scripts/gUnknown_8286892.inc"
gUnknown_82868C3: @ 0x82868C3
	.include "data/scripts/gUnknown_82868C3.inc"
gUnknown_82868E8: @ 0x82868E8
	.include "data/scripts/gUnknown_82868E8.inc"
gUnknown_8286946: @ 0x8286946
	.include "data/scripts/gUnknown_8286946.inc"
gUnknown_82869A5: @ 0x82869A5
	.include "data/scripts/gUnknown_82869A5.inc"
gUnknown_8286A6A: @ 0x8286A6A
	.include "data/scripts/gUnknown_8286A6A.inc"
gUnknown_8286AAA: @ 0x8286AAA
	.include "data/scripts/gUnknown_8286AAA.inc"
gUnknown_8286AED: @ 0x8286AED
	.include "data/scripts/gUnknown_8286AED.inc"

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

	.globl gUnknown_8289F5C
gUnknown_8289F5C: @ 0x8289F5C
	.include "data/scripts/gUnknown_8289F5C.inc"

	.globl gBattlescriptsForBallThrow
gBattlescriptsForBallThrow: @ 0x828A290
	.4byte gUnknown_828A2F0                  @ 000
	.4byte gUnknown_828A2F0                  @ 001
	.4byte gUnknown_828A2F0                  @ 002
	.4byte gUnknown_828A2F0                  @ 003
	.4byte gUnknown_828A2F0                  @ 004
	.4byte gUnknown_828A306                  @ 005
	.4byte gUnknown_828A2F0                  @ 006
	.4byte gUnknown_828A2F0                  @ 007
	.4byte gUnknown_828A2F0                  @ 008
	.4byte gUnknown_828A2F0                  @ 009
	.4byte gUnknown_828A2F0                  @ 010
	.4byte gUnknown_828A2F0                  @ 011
	.4byte gUnknown_828A2F0                  @ 012

	.globl gBattlescriptsForUsingItem
gBattlescriptsForUsingItem: @ 0x828A2C4
	.4byte gUnknown_828A39A                  @ 000
	.4byte gUnknown_828A3A4                  @ 001
	.4byte gUnknown_828A3A4                  @ 002
	.4byte gUnknown_828A3D3                  @ 003
	.4byte gUnknown_828A3F7                  @ 004
	.4byte gUnknown_828A419                  @ 005

	.globl gBattlescriptsForRunningByItem
gBattlescriptsForRunningByItem: @ 0x828A2DC
	.4byte gUnknown_828A43B                  @ 000

	.globl gBattlescriptsForSafariActions
gBattlescriptsForSafariActions: @ 0x828A2E0
	.4byte gUnknown_828A445 @ BattleScript_ActionWatchesCarefully
	.4byte gUnknown_828A44C @ BattleScript_ActionGetNear
	.4byte gUnknown_828A455 @ BattleScript_ActionThrowPokeblock
	.4byte gUnknown_828A46B @ BattleScript_ActionWallyThrow
gUnknown_828A2F0: @ 0x828A2F0
	.include "data/scripts/gUnknown_828A2F0.inc"
gUnknown_828A306: @ 0x828A306
	.include "data/scripts/gUnknown_828A306.inc"

	.globl BattleScript_SuccessBallThrow
BattleScript_SuccessBallThrow: @ 0x828A30C
	.include "data/scripts/gUnknown_828A30C.inc"

	.globl BattleScript_WallyBallThrow
BattleScript_WallyBallThrow: @ 0x828A352
	.include "data/scripts/gUnknown_828A352.inc"

	.globl BattleScript_ShakeBallThrow
BattleScript_ShakeBallThrow: @ 0x828A35C
	.include "data/scripts/gUnknown_828A35C.inc"

	.globl BattleScript_TrainerBallBlock
BattleScript_TrainerBallBlock: @ 0x828A38A
	.include "data/scripts/gUnknown_828A38A.inc"
gUnknown_828A39A: @ 0x828A39A
	.include "data/scripts/gUnknown_828A39A.inc"
gUnknown_828A3A4: @ 0x828A3A4
	.include "data/scripts/gUnknown_828A3A4.inc"
gUnknown_828A3D3: @ 0x828A3D3
	.include "data/scripts/gUnknown_828A3D3.inc"
gUnknown_828A3F7: @ 0x828A3F7
	.include "data/scripts/gUnknown_828A3F7.inc"
gUnknown_828A419: @ 0x828A419
	.include "data/scripts/gUnknown_828A419.inc"
gUnknown_828A43B: @ 0x828A43B @ running-by-item script
	.byte 0x54, 0x11, 0x00, 0x2E, 0xDE, 0x3F, 0x02, 0x02, 0x04, 0xF7
gUnknown_828A445: @ 0x828A445 @ BattleScript_ActionWatchesCarefully
	.byte 0x10, 0x1D, 0x01 @ printstring STRINGID_PKMNWATCHINGCAREFULLY
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2
gUnknown_828A44C: @ 0x828A44C @ BattleScript_ActionGetNear
	.byte 0x13, 0xB0, 0xBA, 0x5A, 0x08 @ printfromtable 0x085ABAB0
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2
gUnknown_828A455: @ 0x828A455 @ BattleScript_ActionThrowPokeblock
	.byte 0x10, 0x21, 0x01 @ printstring STRINGID_THREWPOKEBLOCKATPKMN
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x45, 0x01, 0x04, 0x00, 0x00, 0x00, 0x00 @ playanimation 0x01, 0x04, 0x00000000
	.byte 0x13, 0xB4, 0xBA, 0x5A, 0x08 @ printfromtable 0x085ABAB4
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2
gUnknown_828A46B: @ 0x828A46B @ BattleScript_ActionWallyThrow
	.byte 0x10, 0x02, 0x00 @ printstring STRINGID_RETURNMON
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x4B @ returnatktoball
	.byte 0x3A @ waitstate
	.byte 0x53, 0x00 @ trainerslidein 0x00
	.byte 0x3A @ waitstate
	.byte 0x10, 0x4D, 0x01 @ printstring STRINGID_YOUTHROWABALLNOWRIGHT
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2
	.byte 0x00 @ attackcanceler
	.byte 0x00 @ attackcanceler
	.byte 0x00 @ attackcanceler

	.globl gUnknown_828A480
gUnknown_828A480: @ 0x828A480
	.include "data/scripts/gUnknown_828A480.inc"

	.globl gUnknown_828C8D8
gUnknown_828C8D8: @ 0x828C8D8
	.include "data/scripts/gUnknown_828C8D8.inc"
