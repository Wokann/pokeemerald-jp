@ SkyPillar_Top scripts (JP map g24 m85 @ 0x0821BF28)

SkyPillar_Top_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_Top_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Top_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SkyPillar_Top_OnWarp
	.byte 0

SkyPillar_Top_OnResume:: @ 0x0821BF38
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SkyPillar_Top_EventScript_TryRemoveRayquaza
	end

SkyPillar_Top_EventScript_TryRemoveRayquaza:: @ 0x0821BF42
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

SkyPillar_Top_OnTransition:: @ 0x0821BF56
	call_if_lt VAR_SKY_PILLAR_STATE, 2, SkyPillar_Top_EventScript_SetCleanLayout
	call_if_ge VAR_SKY_PILLAR_STATE, 2, SkyPillar_Top_EventScript_TryShowRayquaza
	end

SkyPillar_Top_EventScript_SetCleanLayout:: @ 0x0821BF6D
	setmaplayoutindex LAYOUT_SKY_PILLAR_TOP_CLEAN
	setobjectmovementtype LOCALID_RAYQUAZA_SLEEPING, MOVEMENT_TYPE_FACE_DOWN
	return

SkyPillar_Top_EventScript_TryShowRayquaza:: @ 0x0821BF75
	call_if_unset FLAG_DEFEATED_RAYQUAZA, SkyPillar_Top_EventScript_ShowRayquaza
	return

SkyPillar_Top_EventScript_ShowRayquaza:: @ 0x0821BF7F
	clearflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA_STILL
	return

SkyPillar_Top_OnWarp:: @ 0x0821BF83
	map_script_2 VAR_SKY_PILLAR_STATE, 0, SkyPillar_Top_EventScript_RayquazaFaceDown
	.2byte 0

SkyPillar_Top_EventScript_RayquazaFaceDown:: @ 0x0821BF8D
	turnobject LOCALID_RAYQUAZA_SLEEPING, DIR_SOUTH
	end

SkyPillar_Top_EventScript_Rayquaza:: @ 0x0821BF92
	lockall
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_RAYQUAZA, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SkyPillar_Top_EventScript_DefeatedRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SkyPillar_Top_EventScript_RanFromRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SkyPillar_Top_EventScript_RanFromRayquaza
	setflag FLAG_DEFEATED_RAYQUAZA
	releaseall
	end

SkyPillar_Top_EventScript_DefeatedRayquaza:: @ 0x0821BFD8
	setflag FLAG_DEFEATED_RAYQUAZA
	goto SkyPillar_Top_EventScript_DefeatedRayquaza2
	end

SkyPillar_Top_EventScript_RanFromRayquaza:: @ 0x0821BFE1
	setvar VAR_0x8004, SPECIES_RAYQUAZA
	goto SkyPillar_Top_EventScript_RanFromRayquaza2
	end

SkyPillar_Top_EventScript_DefeatedRayquaza2:: @ 0x0821BFEC
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

SkyPillar_Top_EventScript_RanFromRayquaza2:: @ 0x0821BFF5
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	releaseall
	end

SkyPillar_Top_EventScript_AwakenRayquaza:: @ 0x0821C00A
	lockall
	fadeoutbgm 1
	applywaitmovement LOCALID_PLAYER, Common_Movement_FaceUp
	special SpawnCameraObject
	applywaitmovement LOCALID_CAMERA, SkyPillar_Top_Movement_CameraPanUp
	special RemoveCameraObject
	applywaitmovement LOCALID_RAYQUAZA_SLEEPING, SkyPillar_Top_Movement_RayquazaStir
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	waitmoncry
	applywaitmovement LOCALID_RAYQUAZA_SLEEPING, SkyPillar_Top_Movement_RayquazaFlyOff
	removeobject LOCALID_RAYQUAZA_SLEEPING
	msgbox SkyPillar_Top_Text_RayquazaFlewOff, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadeinbgm 1
	special SpawnCameraObject
	applywaitmovement LOCALID_CAMERA, SkyPillar_Top_Movement_CameraPanDown
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 5
	setvar VAR_SKY_PILLAR_STATE, 1
	setvar VAR_SKY_PILLAR_RAYQUAZA_CRY_DONE, 1
	releaseall
	end

SkyPillar_Top_Movement_RayquazaStir:: @ 0x0821C0AA
	delay_16
	walk_in_place_fast_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_left
	delay_16
	walk_in_place_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SkyPillar_Top_Movement_RayquazaFlyOff:: @ 0x0821C0BB
	delay_16
	walk_in_place_down
	delay_8
	walk_in_place_right
	delay_8
	walk_faster_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

SkyPillar_Top_Movement_CameraPanUp:: @ 0x0821C0C8
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

SkyPillar_Top_Movement_CameraPanDown:: @ 0x0821C0CC
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

SkyPillar_Top_Text_RayquazaFlewOff:: @ 0x0821C0D0
	.string "めを　さました　レックウザは\n"
	.string "どこかへ　とんで　いって　しまった⋯⋯$"
