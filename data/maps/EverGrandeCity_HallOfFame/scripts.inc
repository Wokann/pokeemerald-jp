@ EverGrandeCity_HallOfFame scripts (JP map g16 m11 @ 0x08211287)

EverGrandeCity_HallOfFame_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_HallOfFame_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_HallOfFame_OnWarp
	.byte 0

EverGrandeCity_HallOfFame_OnWarp:: @ 0x08211292
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_HallOfFame_EventScript_TurnPlayerNorth:: @ 0x0821129C
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_HallOfFame_OnFrame:: @ 0x082112A1
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame
	.2byte 0

EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame:: @ 0x082112AB
	lockall
	applymovement LOCALID_HALL_OF_FAME_WALLACE, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
	applymovement LOCALID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
	waitmovement 0
	applymovement LOCALID_HALL_OF_FAME_WALLACE, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox EverGrandeCity_HallOfFame_Text_HereWeHonorLeagueChampions, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HALL_OF_FAME_WALLACE, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
	applymovement LOCALID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
	waitmovement 0
	delay 0x14
	applymovement LOCALID_HALL_OF_FAME_WALLACE, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox EverGrandeCity_HallOfFame_Text_LetsRecordYouAndYourPartnersNames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HALL_OF_FAME_WALLACE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 0x14
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 0x28
	setvar VAR_TEMP_1, 1
	call EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_HallOfFame_EventScript_GameClearMale
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
	end

EverGrandeCity_HallOfFame_EventScript_GameClearMale:: @ 0x08211344
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	fadescreenspeed FADE_TO_BLACK, 0x18
	special GameClear
	releaseall
	end

EverGrandeCity_HallOfFame_EventScript_GameClearFemale:: @ 0x08211350
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	fadescreenspeed FADE_TO_BLACK, 0x18
	special GameClear
	releaseall
	end

EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_HallOfFame_Text_HereWeHonorLeagueChampions: @ 0x08211369
	.string "ミクリ“ここは⋯⋯\p"
	.string "はげしい　たたかいを　かちぬいた\n"
	.string "ポケモンを　きろくする　ばしょ\p"
	.string "リーグ　チャンピオンの\n"
	.string "えいこうを　たたえる　ための　へやさ！$"

EverGrandeCity_HallOfFame_Text_LetsRecordYouAndYourPartnersNames: @ 0x082113B4
	.string "ミクリ“さあ！　ポケモン　リーグを\n"
	.string "かちぬいた　きみの　なまえと\p"
	.string "ともに　たたかった　きみの　パートナーを\n"
	.string "この　マシンに　きろく　するのだ！$"
