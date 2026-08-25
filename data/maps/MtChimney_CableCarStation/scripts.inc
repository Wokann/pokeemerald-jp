@ MtChimney_CableCarStation scripts (JP map g19 m1 @ 0x0821201F)

MtChimney_CableCarStation_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_CableCarStation_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtChimney_CableCarStation_OnFrame
	.byte 0

MtChimney_CableCarStation_OnTransition:: @ 0x0821202A
	call_if_eq VAR_CABLE_CAR_STATION_STATE, 1, MtChimney_CableCarStation_EventScript_MoveAttendantAside
	end

MtChimney_CableCarStation_EventScript_MoveAttendantAside:: @ 0x08212036
	setobjectxyperm LOCALID_MT_CHIMNEY_CABLE_CAR_ATTENDANT, 0x5, 0x4
	setobjectmovementtype LOCALID_MT_CHIMNEY_CABLE_CAR_ATTENDANT, MOVEMENT_TYPE_FACE_RIGHT
	return

MtChimney_CableCarStation_OnFrame:: @ 0x08212042
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 1, MtChimney_CableCarStation_EventScript_ExitCableCar
	.2byte 0

MtChimney_CableCarStation_EventScript_ExitCableCar:: @ 0x0821204C
	lockall
	applymovement LOCALID_PLAYER, MtChimney_CableCarStation_Movement_ExitCableCar
	applymovement LOCALID_MT_CHIMNEY_CABLE_CAR_ATTENDANT, MtChimney_CableCarStation_Movement_FollowPlayerOutFromCableCar
	waitmovement 0
	setvar VAR_CABLE_CAR_STATION_STATE, 0
	setobjectxyperm LOCALID_MT_CHIMNEY_CABLE_CAR_ATTENDANT, 0x6, 0x7
	setobjectmovementtype LOCALID_MT_CHIMNEY_CABLE_CAR_ATTENDANT, MOVEMENT_TYPE_FACE_DOWN
	releaseall
	end

MtChimney_CableCarStation_EventScript_Attendant:: @ 0x08212070
	lock
	faceplayer
	msgbox MtChimney_CableCarStation_Text_CableCarReadyGetOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MtChimney_CableCarStation_EventScript_RideCableCar
	goto_if_eq VAR_RESULT, NO, MtChimney_CableCarStation_EventScript_DeclineRide
	end

MtChimney_CableCarStation_EventScript_RideCableCar:: @ 0x08212091
	msgbox MtChimney_CableCarStation_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MT_CHIMNEY_CABLE_CAR_ATTENDANT, MtChimney_CableCarStation_Movement_LeadPlayerToCableCar
	applymovement LOCALID_PLAYER, MtChimney_CableCarStation_Movement_BoardCableCar
	waitmovement 0
	setvar VAR_0x8004, TRUE
	setvar VAR_CABLE_CAR_STATION_STATE, 2
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
	special CableCarWarp
	special CableCar
	release
	end

MtChimney_CableCarStation_EventScript_DeclineRide:: @ 0x082120C0
	msgbox MtChimney_CableCarStation_Text_RideAnotherTime, MSGBOX_DEFAULT
	release
	end

MtChimney_CableCarStation_Movement_LeadPlayerToCableCar:
	walk_up
	walk_up
	walk_left
	walk_in_place_faster_right
	step_end

MtChimney_CableCarStation_Movement_FollowPlayerOutFromCableCar:
	delay_16
	walk_right
	walk_down
	walk_down
	step_end

MtChimney_CableCarStation_Movement_BoardCableCar:
	walk_up
	walk_up
	walk_up
	delay_16
	step_end

MtChimney_CableCarStation_Movement_ExitCableCar:
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

MtChimney_CableCarStation_Text_CableCarReadyGetOn: @ 0x082120DE
	.string "くだり　ロープウェイ\n"
	.string "まもなく　しゅっぱつ　です\l"
	.string "ごりように　なられますか？$"

MtChimney_CableCarStation_Text_StepThisWay: @ 0x08212105
	.string "では　こちらに　どうぞ！$"

MtChimney_CableCarStation_Text_RideAnotherTime: @ 0x08212112
	.string "またの　ごりようを\n"
	.string "よろしく　おねがい　しまーす！$"
