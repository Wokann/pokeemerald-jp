@ LilycoveCity_PokemonTrainerFanClub scripts (JP map g13 m9 @ 0x0820839E)

LilycoveCity_PokemonTrainerFanClub_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_PokemonTrainerFanClub_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonTrainerFanClub_OnTransition
	.byte 0

LilycoveCity_PokemonTrainerFanClub_OnFrame: @ 0x082083A9
	map_script_2 VAR_LILYCOVE_FAN_CLUB_STATE, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans
	.2byte 0

LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans:: @ 0x082083B3
	lockall
	applymovement LOCALID_TRAINER_FAN_CLUB_LASS, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OhWowItsPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer
	applymovement LOCALID_TRAINER_FAN_CLUB_MAN, LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HeardAboutYouImYourFan, MSGBOX_DEFAULT
	applymovement LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer
	waitmovement 0
	setvar VAR_LILYCOVE_FAN_CLUB_STATE, 2
	releaseall
	end

LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer:
	delay_8
	walk_in_place_faster_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer:
	walk_down
	walk_in_place_faster_right
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer:
	jump_in_place_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_in_place_faster_down
	step_end

LilycoveCity_PokemonTrainerFanClub_OnTransition: @ 0x08208426
	call LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 2, LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions:: @ 0x08208442
	special TryLoseFansFromPlayTime
	call LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
	setvar VAR_0x8004, FANCLUB_MEMBER1
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER2
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER3
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER4
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER5
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER6
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER7
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER8
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer:: @ 0x082084F3
	specialvar VAR_RESULT, ShouldHideFanClubInterviewer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer
	clearflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
	clearflag FLAG_FAN_CLUB_STRENGTH_SHARED
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer:: @ 0x0820850A
	setflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow:: @ 0x0820850E
	setvar VAR_0x8005, NUM_TRAINER_FAN_CLUB_MEMBERS
	setvar VAR_0x8004, FANCLUB_MEMBER1
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER2
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER3
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER4
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER5
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER6
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER7
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER8
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	goto_if_ge VAR_0x8005, 5, LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan:: @ 0x082085C7
	subvar VAR_0x8005, 1
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow:: @ 0x082085CD
	special TryPutTrainerFanClubOnAir
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable:: @ 0x082085D1
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_LASS, 7, 5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable:: @ 0x082085D9
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_POKEFAN_M, 3, 4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable:: @ 0x082085E1
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, 7, 2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable:: @ 0x082085E9
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_NINJA_BOY, 5, 5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable:: @ 0x082085F1
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_BOY, 5, 2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable:: @ 0x082085F9
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_MAN, 8, 4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable:: @ 0x08208601
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_WOMAN, 3, 3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable:: @ 0x08208609
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_EXPERT_F, 8, 3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting:: @ 0x08208611
	call LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Man:: @ 0x08208630
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER6
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainersPowerIsOutOfTheOrdinary, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayersFan:: @ 0x0820866F
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan:: @ 0x08208689
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyNonFan:: @ 0x08208693
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayerNotChampion:: @ 0x0820869D
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Lass:: @ 0x082086A7
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ICantHelpLikingBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayersFan:: @ 0x082086E6
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan:: @ 0x08208700
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyNonFan:: @ 0x0820870A
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayerNotChampion:: @ 0x08208714
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanM:: @ 0x0820871E
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER2
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_LongWayToGoComparedToNorman, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayersFan:: @ 0x0820875D
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan:: @ 0x08208777
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyNonFan:: @ 0x08208781
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayerNotChampion:: @ 0x0820878B
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirl:: @ 0x08208795
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER3
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_EveryoneThinksTrainerIsCool, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan:: @ 0x082087D4
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan:: @ 0x082087EE
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan:: @ 0x082087F8
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion:: @ 0x08208802
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoy:: @ 0x0820880C
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER4
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsWickedlyCool, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyPlayersFan:: @ 0x08208840
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan:: @ 0x0820885A
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyNonFan:: @ 0x08208864
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Boy:: @ 0x0820886E
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER5
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_BoyPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThinkTrainerIsNumberOne, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyPlayersFan:: @ 0x082088A2
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan:: @ 0x082088BC
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyNonFan:: @ 0x082088C6
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Woman:: @ 0x082088D0
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER7
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsStandout, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan:: @ 0x08208904
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan:: @ 0x0820891E
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan:: @ 0x08208928
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertF:: @ 0x08208932
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER8
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaventRealizedPotential, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFPlayersFan:: @ 0x08208966
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan:: @ 0x08208980
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyNonFan:: @ 0x0820898A
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Interviewer:: @ 0x08208994
	lock
	faceplayer
	goto_if_set FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed
	goto_if_unset FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_Interview
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Interview:: @ 0x082089A9
	setvar VAR_0x8005, TVSHOW_FAN_CLUB_SPECIAL
	special InterviewBefore
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2
	copyvar VAR_0x800A, VAR_0x8006
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
	copyvar VAR_0x8005, VAR_0x800A
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion:: @ 0x082089F9
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThatsWhatYouThink, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion:: @ 0x08208A07
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion:: @ 0x08208A2E
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer2, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
	copyvar VAR_0x8005, VAR_0x800A
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer:: @ 0x08208A66
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	message LilycoveCity_PokemonTrainerFanClub_Text_HowStrongRateTrainer
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_POKEMON_FAN_CLUB_RATER
	special ShowScrollableMultichoice
	waitstate
	setvar VAR_0x8004, FANCLUB_MEMBER1
	switch VAR_RESULT
	case 11, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
	case MULTI_B_PRESSED, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	copyvar VAR_0x8006, VAR_0x800A
	copyvar VAR_0x8005, VAR_RESULT
	special PutFanClubSpecialOnTheAir
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_CompleteInterview
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer:: @ 0x08208AB8
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer:: @ 0x08208ADF
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouShouldMeetTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CompleteInterview:: @ 0x08208AF1
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThankYouIllShareThisInfo, MSGBOX_DEFAULT
	setflag FLAG_FAN_CLUB_STRENGTH_SHARED
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed:: @ 0x08208B06
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_HopeYouCatchTVSpecial, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2:: @ 0x08208B18
	end

LilycoveCity_PokemonTrainerFanClub_Text_OhWowItsPlayer: @ 0x08208B19
	.string "あ！\n"
	.string "{PLAYER}だ！！$"

LilycoveCity_PokemonTrainerFanClub_Text_HeardAboutYouImYourFan: @ 0x08208B22
	.string "きいたよ！\n"
	.string "きみ　つよいんだってな\p"
	.string "ここでは　みんな\n"
	.string "だれが　いちばん　つよい　トレーナーか\l"
	.string "はなしを　してるんだけど\p"
	.string "おれ　きみの　うわさを　きいて\n"
	.string "きみの　ファンに　なることに　したよ！\p"
	.string "これからも　つよい　トレーナーと\n"
	.string "バンバン　たたかって\p"
	.string "おれたちに　あつい\n"
	.string "たたかいを　みせてくれよ！\p"
	.string "そうすれば　きっと　みんなも\n"
	.string "きみの　ことを　みなおすと　おもうんだ\p"
	.string "じゃあ　きたい　してるよ！\n"
	.string "{PLAYER}！！$"

LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin: @ 0x08208BEC
	.string "おう　{PLAYER}！！\n"
	.string "おうえん　してるぞ！！$"

LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest: @ 0x08208C00
	.string "あいつらは　しらないんだ\n"
	.string "きみが　いちばん　すごいって　ことをさ！\p"
	.string "そうだろ　{PLAYER}！\n"
	.string "こんじょう　みせてくれ！$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainersPowerIsOutOfTheOrdinary: @ 0x08208C38
	.string "きみには　わるいけど　いま　いちばん\n"
	.string "ちゅうもくの　トレーナーは\l"
	.string "まちがいなく　{STR_VAR_1}　だね！\p"
	.string "あの　つよさは\n"
	.string "だたものじゃ　ないよ$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen: @ 0x08208C7A
	.string "くそー　いまは　{STR_VAR_1}が\n"
	.string "いちばん　つよいって　いってるのに\p"
	.string "だれも　きいて　くれない⋯⋯$"

LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer: @ 0x08208CA7
	.string "さいきん　つぎつぎと　ジムリーダーを\n"
	.string "たおしている　っていう\p"
	.string "つよい　トレーナーが\n"
	.string "あらわれた　らしいんだ\p"
	.string "きみ　しらないかい？$"

LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou: @ 0x08208CE8
	.string "あ！\n"
	.string "{PLAYER}！！\p"
	.string "がんばってね\n"
	.string "おうえん　してるから！$"

LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan: @ 0x08208D03
	.string "トウキさま⋯⋯\p"
	.string "あ！\n"
	.string "ちがう　ちがう！\p"
	.string "わたしは　あくまで　あなたの\n"
	.string "ファン　なんだからね！\p"
	.string "だから　あたしの　ために\n"
	.string "がんばってよ！$"

LilycoveCity_PokemonTrainerFanClub_Text_ICantHelpLikingBrawly: @ 0x08208D47
	.string "やっぱり　わたしは　トウキさま　しか\n"
	.string "すきに　なれないのよねー$"

LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly: @ 0x08208D67
	.string "だれも　トウキさまの\n"
	.string "みりょくを　わかって　くれないの⋯⋯\p"
	.string "いいわ！\p"
	.string "わたし　ひとりでも　トウキさまの　ことを\n"
	.string "おうえん　しつづけるから！$"

LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly: @ 0x08208DAD
	.string "わたしの　いちばん　すきな\n"
	.string "トレーナーは　なんと　いっても\p"
	.string "ムロの　ジムリーダー\n"
	.string "トウキさまよ！$"

LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather: @ 0x08208DDE
	.string "きみは　ついに　あらゆる　めんで\n"
	.string "きみの　おとうさんを　こえたな！\p"
	.string "この　わしが　いって　いるんだから\n"
	.string "まちがいない！$"

LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling: @ 0x08208E1A
	.string "きみの　おとうさんは　ピンチに　なっても\n"
	.string "あきらめずに　たたかって　いたよ⋯⋯\p"
	.string "わしは　しっているよ\p"
	.string "きみは　いくら　まけても　けっして\n"
	.string "あきらめない　という　ことを！\l"
	.string "だから　がんばってくれ！$"

LilycoveCity_PokemonTrainerFanClub_Text_LongWayToGoComparedToNorman: @ 0x08208E7C
	.string "きみより　センリさんの　ほうが\n"
	.string "もっと　つよくて　かっこよく\l"
	.string "みごたえの　ある　たたかいを　していたぞ！\p"
	.string "いくら　きみが　つよいと\n"
	.string "いわれて　いても\p"
	.string "きみの　おとうさんに　くらべたら\n"
	.string "まだまだ　だな$"

LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent: @ 0x08208EE0
	.string "きみも　センリさんと　おなじ　ふんいき\n"
	.string "というか　はくりょくが　でてきたね\p"
	.string "しかし　センリさん　とは　けっていてきに\n"
	.string "ちがう　ものが　ある！\p"
	.string "⋯⋯それは　わたしからは　いえない\n"
	.string "じぶんで　さがして　みるんだな$"

LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers: @ 0x08208F49
	.string "ここにいる　みんなは\n"
	.string "ポケモンしょうぶが　だいすきでね\p"
	.string "だれが　いちばん　つよい　トレーナーか\n"
	.string "はなしを　して　いるんだ！\p"
	.string "きみも　ゆうめいに　なれば\n"
	.string "みんな　ファンに　なるかもな！$"

LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer: @ 0x08208FA5
	.string "うわー！　{PLAYER}だー\n"
	.string "ほんもの　だー\p"
	.string "あくしゅ　してー\n"
	.string "あくしゅ！$"

LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou: @ 0x08208FC6
	.string "⋯⋯わたし　いつまでも　{PLAYER}の　こと\n"
	.string "おうえん　する　からね！\p"
	.string "わたし　もう　{PLAYER}の　まける\n"
	.string "とこなんて　みたくないよ\p"
	.string "{PLAYER}　ほんとは\n"
	.string "つよいんだ　もんね！$"

LilycoveCity_PokemonTrainerFanClub_Text_EveryoneThinksTrainerIsCool: @ 0x08209015
	.string "{STR_VAR_1}さん　って　かっこいい⋯⋯\p"
	.string "ねえ　みんなも\n"
	.string "そう　おもうでしょー？$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe: @ 0x08209039
	.string "{STR_VAR_1}さん　って　ほんとうに\n"
	.string "かっこいい　よねぇ⋯⋯\p"
	.string "わたし　ひとりに　なっても\n"
	.string "ずうっと　おうえん　するんだー！$"

LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat: @ 0x08209072
	.string "わたしのね\n"
	.string "すきな　トレーナーは\p"
	.string "かっこよくて\p"
	.string "つよくて\p"
	.string "それでいて　やさしい\p"
	.string "そんな　トレーナーが　いいなぁ⋯⋯$"

LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou: @ 0x082090AC
	.string "あ！　{PLAYER}だー！\n"
	.string "すげー！\p"
	.string "ぼくも　おおきく　なったら\n"
	.string "{PLAYER}　みたいに　つよく　なりたいよ！$"

LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou: @ 0x082090DB
	.string "⋯⋯\n"
	.string "ぼく　ひとりに　なったって\p"
	.string "ずっと　{PLAYER}の　ことを\n"
	.string "おうえん　するよ！\p"
	.string "だって　{PLAYER}の　こと\n"
	.string "しんじてるもん！$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsWickedlyCool: @ 0x08209116
	.string "{STR_VAR_1}って　かっこいいよねー\n"
	.string "ぼく　あくしゅ　してほしいなー$"

LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan: @ 0x08209134
	.string "⋯⋯\n"
	.string "ぼく　ひとりに　なったって\p"
	.string "ぜったい　{STR_VAR_1}の　ファンを\n"
	.string "やめない　からね！\p"
	.string "だって　ぼく　きいたんだもん\n"
	.string "{STR_VAR_1}は　ぜったいに　まけないって$"

LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll: @ 0x0820917D
	.string "{PLAYER}！\n"
	.string "やっぱり　すごいよ　きみは！\p"
	.string "ぼくは　きみを　はじめて　みたときから\n"
	.string "すごい　やつだって　おもってたよ！\l"
	.string "やはり　ぼくのめは　たしかな　ようだね！$"

LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner: @ 0x082091CB
	.string "まあ　ほかの　やつの\n"
	.string "ことなんて　きにするなよ\l"
	.string "ぼくが　ついて　いるんだ！\p"
	.string "きみは　しんぱい　しないで　いつもどおり\n"
	.string "たたかって　いれば　いいんだよ$"

LilycoveCity_PokemonTrainerFanClub_Text_ThinkTrainerIsNumberOne: @ 0x08209216
	.string "きみも　なかなか\n"
	.string "いい　トレーナーだと　おもうけど\p"
	.string "いまは　やっぱり　{STR_VAR_1}が\n"
	.string "いちばんだと　おもうんだ\p"
	.string "まあ　ぼくが　おもっている　だけだから\n"
	.string "あまり　きにしなくて　いいよ$"

LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer: @ 0x0820926D
	.string "きみは　ほんとうに　つよいな⋯⋯\n"
	.string "{STR_VAR_1}　より　つよいかも　しれない\p"
	.string "でも　{STR_VAR_1}　には\n"
	.string "ぼくが　ひつよう　なんだ\p"
	.string "だって　ぼくが　{STR_VAR_1}を\n"
	.string "おうえん　しなきゃ\l"
	.string "だれが　おうえん　するんだ！$"

LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind: @ 0x082092CA
	.string "みなおしたわ！\n"
	.string "あなたって　ほんとうに　つよいのね！\p"
	.string "どうしたら　そんなに　つよく　なれるのか\n"
	.string "おしえて　もらいたいわ$"

LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation: @ 0x08209306
	.string "あなたって　ピンチに　なれば　なるほど\n"
	.string "みりょくてきな　たたかいを　するのよね\l"
	.string "つぎの　たいせんが　たのしみだわ！$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsStandout: @ 0x08209340
	.string "さいきんの　トレーナーは\n"
	.string "やっぱり　{STR_VAR_1}よね！\l"
	.string "あの　つよさは　ただもの　じゃないわ\p"
	.string "あなたも　いいせん　いってるけど\n"
	.string "{STR_VAR_1}に　くらべたら　まだまだねー$"

LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger: @ 0x0820938D
	.string "あなたって　ほんとうに\n"
	.string "にんき　ものよね⋯⋯\p"
	.string "つよいし　ポケモンにも　やさしいし\n"
	.string "いうこと　ないわ\p"
	.string "でもね！　わたしは\n"
	.string "{STR_VAR_1}を　しんじているの！\p"
	.string "{STR_VAR_1}の　ほうが　ぜったいに\n"
	.string "つよいに　きまってるん　だから！$"

LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive: @ 0x082093F5
	.string "おぬし⋯⋯\p"
	.string "やるな！$"

LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth: @ 0x08209400
	.string "おぬしの　しんの　ちからは\n"
	.string "この　わしだけが　しっていれば　よいのじゃ\p"
	.string "みなには　その　ひめられた　ちから\n"
	.string "わかるまい⋯⋯$"

LilycoveCity_PokemonTrainerFanClub_Text_HaventRealizedPotential: @ 0x0820943E
	.string "うむ　おぬし　なかなかの\n"
	.string "めを　しておるな\p"
	.string "じゃが！\p"
	.string "⋯⋯うーむ\n"
	.string "まだまだの　ようじゃな$"

LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength: @ 0x0820946B
	.string "たしかに　おぬしは\n"
	.string "とてつもなく　つよいかも　しれない\p"
	.string "じゃが！\n"
	.string "わしには　わかる\p"
	.string "その　つよさは　まだ\n"
	.string "しんの　つよさとは　いわないのじゃ！\l"
	.string "しんの　つよさとは！\p"
	.string "⋯⋯\p"
	.string "じつは　わしも\n"
	.string "よく　わからんのじゃ$"
