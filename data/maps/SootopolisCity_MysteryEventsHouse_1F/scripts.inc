@ SootopolisCity_MysteryEventsHouse_1F scripts (JP map g15 m13 @ 0x0820FD60)

SootopolisCity_MysteryEventsHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MysteryEventsHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MysteryEventsHouse_1F_OnFrame
	.byte 0

SootopolisCity_MysteryEventsHouse_1F_OnTransition:: @ 0x0820FD6B
	frontier_checkvisittrainer
	call_if_eq VAR_RESULT, 0, SootopolisCity_MysteryEventsHouse_1F_EventScript_SetTrainerVisitingLayout
	call_if_ne VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 0, SootopolisCity_MysteryEventsHouse_1F_EventScript_MoveOldManToDoor
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_SetTrainerVisitingLayout:: @ 0x0820FD8A
	setvar VAR_TEMP_1, 0x1
	setobjectxyperm LOCALID_MYSTERY_EVENTS_OLD_MAN, 0x3, 0x2
	setobjectmovementtype LOCALID_MYSTERY_EVENTS_OLD_MAN, MOVEMENT_TYPE_FACE_DOWN
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_STAIRS_UNBLOCKED
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_MoveOldManToDoor:: @ 0x0820FD9E
	setobjectxyperm LOCALID_MYSTERY_EVENTS_OLD_MAN, 0x2, 0x2
	setobjectmovementtype LOCALID_MYSTERY_EVENTS_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
	return

SootopolisCity_MysteryEventsHouse_1F_OnFrame:: @ 0x0820FDAA
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
	.2byte 0

SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle:: @ 0x0820FDC4
	lockall
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerExitStairs
	waitmovement 0
	applymovement LOCALID_MYSTERY_EVENTS_OLD_MAN, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManWalkBehindPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_MYSTERY_EVENTS_OLD_MAN
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call_if_eq VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleWonComment
	call_if_eq VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2, SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleLostComment
	call_if_eq VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3, SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleTiedComment
	special LoadPlayerParty
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 0
	releaseall
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleWonComment:: @ 0x0820FE11
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_ThatWasSuperlative, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleLostComment:: @ 0x0820FE1A
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_TooBadForYou, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleTiedComment:: @ 0x0820FE23
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_BrilliantStandoff, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerExitStairs:
	walk_down
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_OldManWalkBehindPlayer:
	walk_right
	walk_in_place_faster_down
	step_end

SootopolisCity_MysteryEventsHouse_1F_EventScript_OldMan:: @ 0x0820FE31
	lock
	faceplayer
	frontier_checkvisittrainer
	goto_if_eq VAR_RESULT, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_InvalidVisitingTrainer
	goto_if_eq VAR_TEMP_1, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_TrainerVisiting
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_InvalidVisitingTrainer:: @ 0x0820FE5B
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_TrainerVisiting:: @ 0x0820FE65
	special SavePlayerParty
	special BufferEReaderTrainerName
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeVisitingTrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	call SootopolisCity_MysteryEventsHouse_1F_EventScript_ChooseParty
	goto_if_eq VAR_RESULT, 0, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_SaveProgressBeforeBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	special LoadPlayerParty
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	special SavePlayerParty
	special ReducePlayerPartyToSelectedMons
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_HopeToSeeGoodMatch, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementNorth
	call_if_eq VAR_FACING, DIR_EAST, SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementEast
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementWest
	warp MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F, 0x3, 0x1
	waitstate
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle:: @ 0x0820FEEF
	special LoadPlayerParty
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_YouWontBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_ChooseParty:: @ 0x0820FEFC
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_KeepItTo3On3, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementNorth:: @ 0x0820FF0B
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementNorth
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementEast:: @ 0x0820FF1D
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideRight
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementEast
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementWest:: @ 0x0820FF2F
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementWest
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementNorth:
	delay_16
	walk_up
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementEast:
	delay_16
	walk_right
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementWest:
	delay_16
	walk_left
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft:
	walk_left
	walk_in_place_faster_right
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideRight:
	walk_right
	walk_in_place_faster_left
	step_end

SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles: @ 0x0820FF53
	.string "わしも　わかいころは\n"
	.string "ポケモン　トレーナーとして\l"
	.string "せかいじゅうを　たび　していたのじゃ\p"
	.string "ジジイとなった　いまでは\n"
	.string "わかい　トレーナーの　しょうぶを　みるのが\l"
	.string "ゆいいつの　たのしみ　じゃ$"

SootopolisCity_MysteryEventsHouse_1F_Text_DoorAppearsToBeLocked: @ 0x0820FFB0
	.string "とびらには　かぎが　かかって　いるようだ！$"

SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeVisitingTrainer: @ 0x0820FFC6
	.string "いまは　{STR_VAR_1}　という　トレーナーが\n"
	.string "わしの　いえに　きておる！\p"
	.string "{STR_VAR_1}と　しょうぶ　してみたいのじゃな？$"

SootopolisCity_MysteryEventsHouse_1F_Text_YouWontBattle: @ 0x0820FFFA
	.string "しょうぶ　せんのか⋯⋯\n"
	.string "しょうぶを　みられなくて　ガッカリ⋯⋯$"

SootopolisCity_MysteryEventsHouse_1F_Text_KeepItTo3On3: @ 0x0821001A
	.string "おお　そうか　そうか！\p"
	.string "じゃが　この　いえは\n"
	.string "あんまり　がんじょう　じゃないから\p"
	.string "せめて　3たい3の\n"
	.string "しょうぶに　して　くれんかのう？$"

SootopolisCity_MysteryEventsHouse_1F_Text_SaveProgressBeforeBattle: @ 0x0821005E
	.string "じゃあ　しょうぶの　まえに\n"
	.string "レポートを　かいて　おいたほうが　よいぞ$"

SootopolisCity_MysteryEventsHouse_1F_Text_HopeToSeeGoodMatch: @ 0x08210081
	.string "よい　しょうぶを　きたい　しておるぞ！$"

SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Tie: @ 0x08210095
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_B1F_Text_MatchEndedUpDraw: @ 0x08210098
	.globl gJPText_00210098
gJPText_00210098:
	.string "しょうぶは　ひきわけに　おわった！$"

SootopolisCity_MysteryEventsHouse_1F_Text_BrilliantStandoff: @ 0x082100AA
	.string "ひきわけ　じゃったか！\p"
	.string "おたがい　いっぽも　ゆずらぬ\n"
	.string "すばらしい　しょうぶ　じゃったぞ！$"

SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Won: @ 0x082100D7
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_1F_Text_ThatWasSuperlative: @ 0x082100DA
	.string "みごと　じゃったぞ！\p"
	.string "まるで　わしの　わかい　ころを\n"
	.string "みている　ようじゃわい！$"

SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Lost: @ 0x08210102
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_1F_Text_TooBadForYou: @ 0x08210105
	.string "ざんねん　じゃったのう\n"
	.string "じゃが　よい　しょうぶ　じゃったぞ！\l"
	.string "つぎこそは　かてると　よいのう$"
