@ SootopolisCity_MysteryEventsHouse_B1F scripts (JP map g15 m14 @ 0x08210134)

SootopolisCity_MysteryEventsHouse_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MysteryEventsHouse_B1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MysteryEventsHouse_B1F_OnFrame
	.byte 0

SootopolisCity_MysteryEventsHouse_B1F_OnTransition:: @ 0x0821013F
	special SetEReaderTrainerGfxId
	end

SootopolisCity_MysteryEventsHouse_B1F_OnFrame:: @ 0x08210143
	map_script_2 VAR_TEMP_1, 0, SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleVisitingTrainer
	.2byte 0

SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleVisitingTrainer:: @ 0x0821014D
	lockall
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerEnterBasement
	waitmovement 0
	special CopyEReaderTrainerGreeting
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, SPECIAL_BATTLE_EREADER
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	call_if_eq VAR_RESULT, B_OUTCOME_DREW, SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleTie
	call_if_eq VAR_RESULT, B_OUTCOME_WON, SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleWon
	call_if_eq VAR_RESULT, B_OUTCOME_LOST, SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleLost
	closemessage
	special HealPlayerParty
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerExitBasement
	waitmovement 0
	special LoadPlayerParty
	setvar VAR_TEMP_1, 1
	warp MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F, 0x3, 0x1
	waitstate
	releaseall
	end

SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleTie:: @ 0x082101B4
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_MatchEndedUpDraw, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleWon:: @ 0x082101C2
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	return

SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleLost:: @ 0x082101CD
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	return

SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerEnterBasement:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerExitBasement:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end
