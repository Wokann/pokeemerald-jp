@ SootopolisCity scripts (JP map g0 m7 @ 0x081E1CF6)

SootopolisCity_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SootopolisCity_OnWarp
	.byte 0

@ These JP strings still reside in the shared event-text range. Keep the
@ map-local US names while that earlier range is converted separately.
.set SootopolisCity_Text_NameIsKiriHaveOneOfThese, 0x08263F33
.set SootopolisCity_Text_GiveYouThisBerryToo, 0x08263FB4
.set SootopolisCity_Text_WhatKindOfWishInYourName, 0x08263FD5
.set SootopolisCity_Text_LikeSeasonBornIn, 0x08263FF1
.set SootopolisCity_Text_ThenILoveAutumn, 0x08264025
.set SootopolisCity_Text_OhDoesntMatter, 0x0826404E

SootopolisCity_OnLoad::
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockGymDoor
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_EventScript_LegendariesNotArrived
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockHouseDoors
	end

SootopolisCity_EventScript_LegendariesNotArrived::
	end

SootopolisCity_EventScript_LockHouseDoors::
	setmetatile 9, 6, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 9, 17, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 9, 26, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 44, 17, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 8, 35, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 53, 28, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 45, 6, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 48, 25, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 51, 36, METATILE_Sootopolis_Door_Closed, TRUE
	return

SootopolisCity_EventScript_LockGymDoor::
	setmetatile 31, 32, METATILE_Sootopolis_GymDoor_Closed, TRUE
	return

SootopolisCity_OnTransition::
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x1, SootopolisCity_EventScript_HideMapNamePopup
	call_if_eq VAR_SKY_PILLAR_STATE, 0x1, SootopolisCity_EventScript_HideMapNamePopup
	call SootopolisCity_EventScript_SetWeather
	call SootopolisCity_EventScript_SetLayout
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x1, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x2, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x3, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x4, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x5, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x2, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x3, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x4, SootopolisCity_EventScript_SetExitCaveOfOriginObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x5, SootopolisCity_EventScript_SetOutsideGymObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x6, SootopolisCity_EventScript_SetExpertBlockCaveEntrance
	end

SootopolisCity_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

SootopolisCity_EventScript_SetBattleSpectators::
	setobjectxyperm LOCALID_KIRI, 13, 48
	setobjectxyperm LOCALID_SOOTOPOLIS_BOY_1, 46, 32
	setobjectxyperm LOCALID_SOOTOPOLIS_NINJA_BOY, 48, 41
	setobjectxyperm LOCALID_SOOTOPOLIS_WOMAN_1, 45, 43
	setobjectmovementtype LOCALID_KIRI, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SOOTOPOLIS_BOY_1, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_SOOTOPOLIS_NINJA_BOY, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_SOOTOPOLIS_WOMAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SootopolisCity_EventScript_SetLayout::
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x0, SootopolisCity_EventScript_SetNormalLayout
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 0x6, SootopolisCity_EventScript_SetNormalLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x1, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x2, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x3, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x4, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_le VAR_SKY_PILLAR_STATE, 0x1, SootopolisCity_EventScript_SetLegendariesLayout
	return

SootopolisCity_EventScript_SetNormalLayout::
	return

SootopolisCity_EventScript_SetLegendariesLayout::
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_LEGENDS_BATTLE
	return

SootopolisCity_EventScript_SetWeather::
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x0, SootopolisCity_EventScript_SetNormalWeather
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 0x6, SootopolisCity_EventScript_SetNormalWeather
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x1, SootopolisCity_EventScript_SetDownpour
	goto_if_eq VAR_SKY_PILLAR_STATE, 0x1, SootopolisCity_EventScript_SetDownpour
	goto_if_le VAR_SKY_PILLAR_STATE, 0x1, Common_EventScript_SetAbnormalWeather
	return

SootopolisCity_EventScript_SetNormalWeather::
	return

SootopolisCity_EventScript_SetDownpour::
	setweather WEATHER_DOWNPOUR
	return

SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos::
	goto_if_set FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos
	return

SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos::
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 30, 18
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 32, 18
	return

SootopolisCity_EventScript_SetExitCaveOfOriginObjPos::
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 30, 18
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 31, 18
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 32, 18
	end

SootopolisCity_EventScript_SetOutsideGymObjPos::
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 31, 18
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 29, 33
	setobjectxyperm LOCALID_SOOTOPOLIS_MAXIE, 33, 35
	setobjectxyperm LOCALID_SOOTOPOLIS_ARCHIE, 34, 35
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 0x0, SootopolisCity_EventScript_SetWallaceMiddle
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 0x1, SootopolisCity_EventScript_SetWallaceRight
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 0x2, SootopolisCity_EventScript_SetWallaceLeft
	return

SootopolisCity_EventScript_SetWallaceMiddle::
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 31, 33
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_SetWallaceRight::
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 32, 33
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_SetWallaceLeft::
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 30, 33
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_SetExpertBlockCaveEntrance::
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 31, 18
	return

SootopolisCity_OnWarp::
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 0x5, SootopolisCity_EventScript_PlayerFaceLegendaries
	.2byte 0

SootopolisCity_EventScript_PlayerFaceLegendaries::
	call_if_eq VAR_SKY_PILLAR_STATE, 0x1, SootopolisCity_EventScript_PlayerFaceLegendaries1
	call_if_eq VAR_SKY_PILLAR_STATE, 0x2, SootopolisCity_EventScript_PlayerFaceLegendaries2
	end

SootopolisCity_EventScript_PlayerFaceLegendaries1::
	turnobject LOCALID_PLAYER, DIR_NORTH
	return

SootopolisCity_EventScript_PlayerFaceLegendaries2::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setvar VAR_SKY_PILLAR_STATE, 0x3
	return

SootopolisCity_OnResume::
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 9, 6
	end

SootopolisCity_OnFrame::
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 0x1, SootopolisCity_EventScript_StartLegendariesScene
	map_script_2 VAR_SKY_PILLAR_STATE, 0x1, SootopolisCity_EventScript_StartRayquazaScene
	.2byte 0

SootopolisCity_EventScript_StartLegendariesScene::
	lockall
	special StorePlayerCoordsInVars
	goto_if_ne VAR_0x8004, 0x2B, SootopolisCity_EventScript_LegendariesSceneFromDive
	goto_if_ne VAR_0x8005, 0x20, SootopolisCity_EventScript_LegendariesSceneFromDive
	goto SootopolisCity_EventScript_LegendariesSceneFromPokeCenter
	end

SootopolisCity_EventScript_LegendariesSceneFromPokeCenter::
	delay 60
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	setweather WEATHER_ABNORMAL
	resetweather
	setvar VAR_0x8004, FALSE
	special Script_DoRayquazaScene
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 0x1
	setvar VAR_0x8005, 0x1
	setvar VAR_0x8006, 0x8
	setvar VAR_0x8007, 0x5
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
	waitmovement 0
	setvar VAR_0x8004, 0x1
	setvar VAR_0x8005, 0x1
	setvar VAR_0x8006, 0x8
	setvar VAR_0x8007, 0x5
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 0x1
	setvar VAR_0x8005, 0x1
	setvar VAR_0x8006, 0x8
	setvar VAR_0x8007, 0x5
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToPokeCenter
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 0x2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

SootopolisCity_Movement_PanToActionFromPokeCenter:
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_Movement_PanBackToPokeCenter:
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	step_end

SootopolisCity_EventScript_LegendariesSceneFromDive::
	delay 60
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	setweather WEATHER_ABNORMAL
	resetweather
	setvar VAR_0x8004, FALSE
	special Script_DoRayquazaScene
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 0x1
	setvar VAR_0x8005, 0x1
	setvar VAR_0x8006, 0x8
	setvar VAR_0x8007, 0x5
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
	waitmovement 0
	setvar VAR_0x8004, 0x1
	setvar VAR_0x8005, 0x1
	setvar VAR_0x8006, 0x8
	setvar VAR_0x8007, 0x5
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 0x1
	setvar VAR_0x8005, 0x1
	setvar VAR_0x8006, 0x8
	setvar VAR_0x8007, 0x5
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToDive
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 0x2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

SootopolisCity_Movement_PanToActionFromDive:
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PanBackToDive:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_Movement_KyogreAttack:
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end

SootopolisCity_Movement_KyogreDefend:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end

SootopolisCity_Movement_KyogreMoveBack:
	lock_facing_direction
	walk_right
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

SootopolisCity_Movement_KyogreIdle:
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	step_end

SootopolisCity_Movement_GroudonAttack:
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end

SootopolisCity_Movement_GroudonDefend:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end

SootopolisCity_Movement_GroudonMoveBack:
	lock_facing_direction
	walk_left
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

SootopolisCity_Movement_GroudonIdle:
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	step_end

SootopolisCity_EventScript_StartRayquazaScene::
	lockall
	special StorePlayerCoordsInVars
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_RayquazaSceneFromDive
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_RayquazaSceneFromDive
	goto SootopolisCity_EventScript_RayquazaSceneFromPokeCenter
	end

SootopolisCity_EventScript_RayquazaSceneFromPokeCenter::
	delay 60
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	call SootopolisCity_EventScript_SetRoughWater
	removeobject LOCALID_SOOTOPOLIS_GROUDON
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
	setvar VAR_0x8004, TRUE
	special Script_DoRayquazaScene
	playse SE_THUNDER
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
	waitmovement 0
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
	@ JP opcode 0xC5 is a verified Pokemon-cry wait at this site.
	waitmoncry_jp
	setweather WEATHER_NONE
	resetweather
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
	waitmovement 0
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
	special WaitWeather
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 3
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	fadenewbgm MUS_SOOTOPOLIS
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warpwhitefade MAP_SOOTOPOLIS_CITY, 43, 32
	waitstate
	end

SootopolisCity_EventScript_RayquazaSceneFromDive::
	delay 60
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	call SootopolisCity_EventScript_SetRoughWater
	removeobject LOCALID_SOOTOPOLIS_GROUDON
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
	setvar VAR_0x8004, TRUE
	special Script_DoRayquazaScene
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerApproachLegendaries
	waitmovement 0
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
	@ JP opcode 0xC5 is a verified Pokemon-cry wait at this site.
	waitmoncry_jp
	setweather WEATHER_NONE
	resetweather
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
	waitmovement 0
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
	special WaitWeather
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 2
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	fadenewbgm MUS_SURF
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warpwhitefade MAP_SOOTOPOLIS_CITY, 29, 53
	waitstate
	end

SootopolisCity_EventScript_SetRoughWater::
	setmetatile 27, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 28, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 29, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 30, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 27, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 28, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 29, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 30, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 27, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 28, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 29, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 30, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 32, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 33, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 34, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 35, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 32, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 33, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 34, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 35, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 32, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 33, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 34, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 35, 45, METATILE_Sootopolis_RoughWater, FALSE
	return

SootopolisCity_Movement_RayquazaFlyOff: @ 0x081E24F5
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

SootopolisCity_Movement_PanUp: @ 0x081E24FD
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PlayerApproachLegendaries: @ 0x081E2502
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ Unused
SootopolisCity_Movement_PlayerApproachLegendariesDown: @ 0x081E2507
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ Unused
SootopolisCity_Movement_UnusedPanUp: @ 0x081E250C
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

@ Unused
SootopolisCity_Movement_UnusedPanBack: @ 0x081E2519
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end
SootopolisCity_EventScript_CaveOfOriginExpert::
	lock
	faceplayer
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 0x6, SootopolisCity_EventScript_ExpertPostLegendaries
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x5, SootopolisCity_EventScript_ExpertLegendaries
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 0x2, SootopolisCity_EventScript_ExpertLeadToCave
	msgbox SootopolisCity_Text_CaveOfOriginPleaseLeave, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ExpertLeadToCave::
	msgbox SootopolisCity_Text_LeadSuperiorTrainerToCave, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ExpertPostLegendaries::
	msgbox SootopolisCity_Text_CaveOfOriginSleepsToo, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ExpertLegendaries::
	msgbox SootopolisCity_Text_AwakenedPokemonClash, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Kiri::
	lock
	faceplayer
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 0x1, SootopolisCity_EventScript_KiriGiveBerry
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 0x6, SootopolisCity_EventScript_KiriGiveBerry
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x5, SootopolisCity_EventScript_KiriRayquaza
	msgbox SootopolisCity_Text_BigPokemonFighting, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_KIRI, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_KiriRayquaza::
	msgbox SootopolisCity_Text_PrettyMonCameFromSky, MSGBOX_DEFAULT
	closemessage
	release
	end

SootopolisCity_EventScript_KiriGiveBerry::
	dotimebasedevents
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_KiriReceivedBerry
	msgbox SootopolisCity_Text_NameIsKiriHaveOneOfThese, MSGBOX_DEFAULT
	random NUM_KIRI_BERRIES
	addvar VAR_RESULT, NUM_KIRI_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
	msgbox SootopolisCity_Text_GiveYouThisBerryToo, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_EventScript_GiveFigyBerry
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_EventScript_GiveIapapaBerry
	end

SootopolisCity_EventScript_GiveFigyBerry::
	giveitem ITEM_FIGY_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GiveIapapaBerry::
	giveitem ITEM_IAPAPA_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_KiriReceivedBerry::
	msgbox SootopolisCity_Text_LikeSeasonBornIn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_EventScript_KiriLikeSeasonBornIn
	msgbox SootopolisCity_Text_OhDoesntMatter, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_KiriLikeSeasonBornIn::
	msgbox SootopolisCity_Text_ThenILoveAutumn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman2::
	lockall
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x5, SootopolisCity_EventScript_Woman2Rayquaza
	msgbox SootopolisCity_Text_WeatherWentWild, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_Woman2Rayquaza::
	msgbox SootopolisCity_Text_YouBroughtFlyingMon, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Man::
	lock
	faceplayer
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 0x6, SootopolisCity_EventScript_ManPostLegendaries
	msgbox SootopolisCity_Text_NoOrdinaryTourist, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ManPostLegendaries::
	msgbox SootopolisCity_Text_CityRegainedCalm, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 0x6, SootopolisCity_EventScript_Woman1PostLegendaries
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x5, SootopolisCity_EventScript_Woman1Rayquaza
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 0x2, SootopolisCity_EventScript_Woman1Legendaries
	msgbox SootopolisCity_Text_SootopolisSkyBeautiful, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1Legendaries::
	msgbox SootopolisCity_Text_GiganticPokemonFight, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_WOMAN_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_Woman1PostLegendaries::
	msgbox SootopolisCity_Text_NightSkyFavoriteScenery, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1Rayquaza::
	msgbox SootopolisCity_Text_FearedWorstWhenPokemonFlewDown, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_NinjaBoy::
	lockall
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x5, SootopolisCity_EventScript_NinjaBoyRayquaza
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 0x6, SootopolisCity_EventScript_NinjaBoyNormal
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 0x1, SootopolisCity_EventScript_NinjaBoyNormal
	msgbox SootopolisCity_Text_ThisIsWicked, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_NinjaBoyNormal::
	msgbox SootopolisCity_Text_WonderWhatWorldIsLike, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_NinjaBoyRayquaza::
	msgbox SootopolisCity_Text_ThatWasWicked, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1::
	lockall
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x5, SootopolisCity_EventScript_Boy1Rayquaza
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_EventScript_Boy1GameClear
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 0x6, SootopolisCity_EventScript_Boy1Normal
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 0x1, SootopolisCity_EventScript_Boy1Normal
	msgbox SootopolisCity_Text_GiantPokemonSuddenlyAppeared, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_Boy1Rayquaza::
	msgbox SootopolisCity_Text_WhatIsThatGreenPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1GameClear::
	msgbox SootopolisCity_Text_WhereDidLegendariesGo, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1Normal::
	msgbox SootopolisCity_Text_PhysicallyFitLivingHere, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GymSign::
	msgbox SootopolisCity_Text_GymSign, MSGBOX_SIGN
	end

SootopolisCity_EventScript_CitySign::
	msgbox SootopolisCity_Text_CitySign, MSGBOX_SIGN
	end

EventScript_ClosedSootopolisDoor:: @ 0x081E27F7
	msgbox SootopolisCity_Text_DoorIsClosed, MSGBOX_SIGN
	end
SootopolisCity_EventScript_Steven::
	lockall
	applymovement LOCALID_SOOTOPOLIS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	call_if_unset FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x2, SootopolisCity_EventScript_StevenHelpWallace
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x3, SootopolisCity_EventScript_StevenHelpedWallace
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x4, SootopolisCity_EventScript_StevenHelpedWallace
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_StevenMaxieArchieLeft
	msgbox SootopolisCity_Text_SoThatsRayquaza, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenHelpWallace::
	msgbox SootopolisCity_Text_KnowWhatsNeededToHelpHim, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenMaxieArchieLeft::
	msgbox SootopolisCity_Text_MaxieArchieLeft, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenHelpedWallace::
	msgbox SootopolisCity_Text_NeverBeenToSkyPillar, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin::
	msgbox SootopolisCity_Text_InvolvedWithCrisisComeWithMe, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_StartWalkToCaveOfOriginWest
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth
	msgbox SootopolisCity_Text_DoesThisMakeYourFearPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenWalkToCaveOfOrigin
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerWalkToCaveOfOrigin
	waitmovement 0
	delay 120
	applymovement LOCALID_SOOTOPOLIS_EXPERT, SootopolisCity_Movement_ExpertMoveAside
	waitmovement 0
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenArriveCaveEntrance
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerArriveCaveEntrance
	waitmovement 0
	msgbox SootopolisCity_Text_HereWereAreHelpWallace, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerEnterCaveOfOrigin
	waitmovement 0
	warp MAP_CAVE_OF_ORIGIN_ENTRANCE, 9, 20
	waitstate
	end

SootopolisCity_EventScript_StartWalkToCaveOfOriginWest::
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest
	waitmovement 0
	return

SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth::
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth
	waitmovement 0
	return

SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_StevenWalkToCaveOfOrigin:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	delay_4
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PlayerWalkToCaveOfOrigin:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SootopolisCity_Movement_ExpertMoveAside:
	walk_slow_left
	walk_in_place_faster_right
	step_end

SootopolisCity_Movement_StevenArriveCaveEntrance:
	walk_down
	walk_down
	walk_left
	delay_8
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_in_place_faster_left
	step_end

SootopolisCity_Movement_PlayerArriveCaveEntrance:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

SootopolisCity_Movement_PlayerEnterCaveOfOrigin:
	walk_up
	walk_up
	step_end

SootopolisCity_EventScript_Boy2::
	lockall
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x5, SootopolisCity_EventScript_Boy2Rayquaza
	msgbox SootopolisCity_Text_TwoPokemonArentAngry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_Boy2Rayquaza::
	msgbox SootopolisCity_Text_FlyingMonStoppedRampage, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_BlackBelt::
	lockall
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x5, SootopolisCity_EventScript_BlackBeltRayquaza
	msgbox SootopolisCity_Text_GoRedAndBlueMon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_DoYouKnowMonNames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_BlackBeltRayquaza::
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_GreenOneSettlesThings, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Girl::
	lockall
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x5, SootopolisCity_EventScript_GirlRayquaza
	msgbox SootopolisCity_Text_SootopolisWillBeWrecked, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_GirlRayquaza::
	msgbox SootopolisCity_Text_SootopolisDidntGetWrecked, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_Maniac::
	lockall
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x5, SootopolisCity_EventScript_ManiacRayquaza
	msgbox SootopolisCity_Text_SeeingLegendWithOwnEyes, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_ManiacRayquaza::
	msgbox SootopolisCity_Text_SawLegendWithOwnEyes, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Wallace::
	lock
	faceplayer
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x4, SootopolisCity_EventScript_GoToSkyPillar
	goto_if_set FLAG_RECEIVED_HM_WATERFALL, SootopolisCity_EventScript_GoToGym
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_GiveWaterfall
	msgbox SootopolisCity_Text_AquaMagmaDidntMeanHarm, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GiveWaterfall::
	msgbox SootopolisCity_Text_ThankYouForHelpAcceptThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_WATERFALL
	setflag FLAG_RECEIVED_HM_WATERFALL
	msgbox SootopolisCity_Text_ExplainWaterfallGoToGym, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_WallaceMoveFromGym
	call_if_eq VAR_FACING, DIR_EAST, SootopolisCity_EventScript_WallaceMoveFromGym
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_WallaceMoveFromGymWest
	release
	end

SootopolisCity_EventScript_WallaceMoveFromGym::
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGym
	waitmovement 0
	moveobjectoffscreen LOCALID_SOOTOPOLIS_WALLACE
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 0x1
	return

SootopolisCity_EventScript_WallaceMoveFromGymWest::
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGymWest
	waitmovement 0
	moveobjectoffscreen LOCALID_SOOTOPOLIS_WALLACE
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 0x2
	return

SootopolisCity_EventScript_GoToSkyPillar::
	msgbox SootopolisCity_Text_HaventYouScaledSkyPillar, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GoToGym::
	msgbox SootopolisCity_Text_DazzledByMentor, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Movement_WallaceMoveFromGym:
	walk_right
	walk_in_place_faster_down
	step_end

SootopolisCity_Movement_WallaceMoveFromGymWest:
	walk_left
	walk_in_place_faster_down
	step_end

SootopolisCity_EventScript_Maxie::
	lockall
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x5, SootopolisCity_EventScript_MaxieRayquaza
	msgbox SootopolisCity_Text_GroudonPleaseStop, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_MaxieRayquaza::
	msgbox SootopolisCity_Text_AfterAllOurScheming, MSGBOX_DEFAULT
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
	goto_if_set FLAG_MET_ARCHIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
	releaseall
	end

SootopolisCity_EventScript_Archie::
	lockall
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0x5, SootopolisCity_EventScript_ArchieRayquaza
	msgbox SootopolisCity_Text_KyogreCalmDown, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_ArchieRayquaza::
	msgbox SootopolisCity_Text_TryingMeaninglessToPokemon, MSGBOX_DEFAULT
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
	goto_if_set FLAG_MET_MAXIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
	releaseall
	end

SootopolisCity_EventScript_MaxieArchieLeave::
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setvar VAR_MT_PYRE_STATE, 0x2
	warpsilent MAP_SOOTOPOLIS_CITY, 31, 34
	waitstate
	releaseall
	end

@ Unused
SootopolisCity_Movement_Levitate: @ 0x081E2C05
	levitate
	step_end

@ Unused
SootopolisCity_Movement_DestroyTask: @ 0x081E2C07
	destroy_extra_task
	step_end

	.globl SootopolisCity_Text_GymSign
SootopolisCity_Text_GymSign: @ 0x081E2C09
	.string "ルネ　シティ　ポケモンジム\n"
	.string "リーダー　アダン\l"
	.string "みずも　したたる　ジムリーダー！$"

	.globl SootopolisCity_Text_CitySign
SootopolisCity_Text_CitySign: @ 0x081E2C31
	.string "ここは　ルネ　シティ\n"
	.string "れきしが　ねむる　しんぴの　まち$"

SootopolisCity_Text_DoorIsClosed: @ 0x081E2C4D
	.string "とびらは　とざされて　いる！$"
	.globl SootopolisCity_Text_PhysicallyFitLivingHere
SootopolisCity_Text_PhysicallyFitLivingHere: @ 0x081E2C5C
	.string "うみに　もぐったり\n"
	.string "かいだんを　のぼったり　おりたり⋯⋯\p"
	.string "このまちで　くらして　いると\n"
	.string "けっこう　たくましく　なるんだよね$"

	.globl SootopolisCity_Text_GiantPokemonSuddenlyAppeared
SootopolisCity_Text_GiantPokemonSuddenlyAppeared: @ 0x081E2C9A
	.string "おっきな　ポケモンが　とつぜん\n"
	.string "まちの　まんなかに　あらわれたんだ！\l"
	.string "しかも　みたことない　やつが　2ひきも！\p"
	.string "あの　2ひき⋯⋯\n"
	.string "どうして　ぶつかり　あってるの？\l"
	.string "ポケモンどうし　なかよく　できないの？$"

	.globl SootopolisCity_Text_WhatIsThatGreenPokemon
SootopolisCity_Text_WhatIsThatGreenPokemon: @ 0x081E2D00
	.string "なに？　なに？　なに？\n"
	.string "あの　みどりの　ポケモン　なにー！？$"

	.globl SootopolisCity_Text_WhereDidLegendariesGo
SootopolisCity_Text_WhereDidLegendariesGo: @ 0x081E2D1F
	.string "グラードンと　カイオーガ\n"
	.string "どこ　いっちゃったんだろう⋯⋯\p"
	.string "また　どこかで　ひでりに　したり\n"
	.string "おおあめ　ふらせたり　してるのかな？$"

	.globl SootopolisCity_Text_TwoPokemonArentAngry
SootopolisCity_Text_TwoPokemonArentAngry: @ 0x081E2D60
	.string "なんとなく　かんじるよ⋯⋯　あの2ひき\n"
	.string "おこってる　わけじゃ　ないみたい\p"
	.string "たぶん⋯⋯　じぶんの　ちからを\n"
	.string "コントロール　できなく　なってるんだ⋯⋯$"

	.globl SootopolisCity_Text_FlyingMonStoppedRampage
SootopolisCity_Text_FlyingMonStoppedRampage: @ 0x081E2DAA
	.string "そらから　きた　ポケモンが\n"
	.string "あばれていた　2ひきを\l"
	.string "おとなしく　させちゃった⋯⋯$"

	.globl SootopolisCity_Text_WonderWhatWorldIsLike
SootopolisCity_Text_WonderWhatWorldIsLike: @ 0x081E2DD3
	.string "ぼく⋯⋯　まだ　いちども　このまちから\n"
	.string "そとに　でたこと　ないんだ\p"
	.string "あの　まあるい　そらの　むこうには\n"
	.string "どんな　せかいが　あるのかな？$"

	.globl SootopolisCity_Text_ThisIsWicked
SootopolisCity_Text_ThisIsWicked: @ 0x081E2E17
	.string "すげー　だいはくりょく！$"

	.globl SootopolisCity_Text_ThatWasWicked
SootopolisCity_Text_ThatWasWicked: @ 0x081E2E24
	.string "すげー　だいはくりょく　だった！$"

	.globl SootopolisCity_Text_GoRedAndBlueMon
SootopolisCity_Text_GoRedAndBlueMon: @ 0x081E2E35
	.string "それいけ！　あかい　ポケモン！\n"
	.string "まけるな！　あおい　ポケモン！$"

	.globl SootopolisCity_Text_DoYouKnowMonNames
SootopolisCity_Text_DoYouKnowMonNames: @ 0x081E2E55
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "きみ　あそこで　たたかってる\n"
	.string "ポケモンたちの　なまえ　しってる？$"

	.globl SootopolisCity_Text_GreenOneSettlesThings
SootopolisCity_Text_GreenOneSettlesThings: @ 0x081E2E7F
	.string "あかい　ポケモンと　あおい　ポケモン\n"
	.string "どっちが　かつのかと　おもったら\l"
	.string "みどりの　ポケモンかよ！\p"
	.string "こりゃ　だいドンデンがえしだ！$"

	.globl SootopolisCity_Text_SeeingLegendWithOwnEyes
SootopolisCity_Text_SeeingLegendWithOwnEyes: @ 0x081E2EC0
	.string "ポケモンの　たたかいに　よって\n"
	.string "りくちと　うみが　つくられた　という\l"
	.string "おおむかし　からの　いいつたえが\p"
	.string "いま　めのまえで　さいげん　されている！\p"
	.string "うぉぉー！　こんな　すごいものを\n"
	.string "この　めで　みられる　なんてー！！$"

	.globl SootopolisCity_Text_SawLegendWithOwnEyes
SootopolisCity_Text_SawLegendWithOwnEyes: @ 0x081E2F2C
	.string "ポケモンの　たたかいに　よって\n"
	.string "りくちと　うみが　つくられた　という\l"
	.string "おおむかし　からの　いいつたえが\p"
	.string "いま　このまちで　さいげん　された！\p"
	.string "うぉぉー！　こんな　すごいものを\n"
	.string "この　めで　みられた　なんてー！！$"

	.globl SootopolisCity_Text_BigPokemonFighting
SootopolisCity_Text_BigPokemonFighting: @ 0x081E2F96
	.string "おっきな　ポケモンと　ポケモンが\n"
	.string "けんか　してるよ！\p"
	.string "だれか　とめて　あげて！$"

	.globl SootopolisCity_Text_PrettyMonCameFromSky
SootopolisCity_Text_PrettyMonCameFromSky: @ 0x081E2FBE
	.string "きれいな　ポケモン\n"
	.string "おそらから　おりて　きた⋯⋯$"

	.globl SootopolisCity_Text_SootopolisWillBeWrecked
SootopolisCity_Text_SootopolisWillBeWrecked: @ 0x081E2FD7
	.string "ひー　ルネシティが　こわれちゃうよー！$"

	.globl SootopolisCity_Text_SootopolisDidntGetWrecked
SootopolisCity_Text_SootopolisDidntGetWrecked: @ 0x081E2FEB
	.string "ルネシティ　こわれないで　すんだよー！$"

	.globl SootopolisCity_Text_NoOrdinaryTourist
SootopolisCity_Text_NoOrdinaryTourist: @ 0x081E2FFF
	.string "ほう！\n"
	.string "わざわざ　ルネに　やってくるとは\l"
	.string "ただの　かんこうきゃく　じゃ　ないな！\p"
	.string "だからといって　おかねを　はらった\n"
	.string "かんこうきゃく　でも　ないな⋯⋯$"

	.globl SootopolisCity_Text_CityRegainedCalm
SootopolisCity_Text_CityRegainedCalm: @ 0x081E304B
	.string "まちが　また　しずかに　なった⋯⋯$"

	.globl SootopolisCity_Text_CaveOfOriginPleaseLeave
SootopolisCity_Text_CaveOfOriginPleaseLeave: @ 0x081E305D
	.string "あなたは　なんですかな？\p"
	.string "ここは　めざめのほこら⋯⋯\p"
	.string "おくりびやまで　しずめられた\n"
	.string "ポケモンの　たましいが\l"
	.string "よみがえると　いわれる　ばしょ⋯⋯\p"
	.string "どうか　おひきとり　ください$"

	.globl SootopolisCity_Text_LeadSuperiorTrainerToCave
SootopolisCity_Text_LeadSuperiorTrainerToCave: @ 0x081E30B4
	.string "つよい　いしと　すぐれた　さいのう\p"
	.string "そして　たくさんの　ポケモンを　みてきた\n"
	.string "ちしきと　けいけん⋯⋯\p"
	.string "そんな　じんぶつが　やってきたら\n"
	.string "この　ほこらへ　あんない　するよう\l"
	.string "ミクリから　もうしつけられて　いたのです$"

	.globl SootopolisCity_Text_AwakenedPokemonClash
SootopolisCity_Text_AwakenedPokemonClash: @ 0x081E311F
	.string "おお⋯⋯\p"
	.string "めざめた　2ひきの　あらそいを\n"
	.string "もう　1ひきの　めざめが　しずめた⋯⋯$"

	.globl SootopolisCity_Text_CaveOfOriginSleepsToo
SootopolisCity_Text_CaveOfOriginSleepsToo: @ 0x081E3148
	.string "ここは　めざめのほこら⋯⋯\p"
	.string "けれど　わざわいが　きえさった　いま\n"
	.string "ほこらも　しずかに　ねむるのです⋯⋯$"

	.globl SootopolisCity_Text_SootopolisSkyBeautiful
SootopolisCity_Text_SootopolisSkyBeautiful: @ 0x081E317C
	.string "ルネは　かざんの\n"
	.string "かこうの　なかに　できた　まち\p"
	.string "うえを　みあげると\n"
	.string "かこうも　いっしょに　みえてしまって\l"
	.string "そらの　すべては　みえない\p"
	.string "でも　だからこそ\n"
	.string "ルネから　みえる　そらが\l"
	.string "いちばん　うつくしいの$"

	.globl SootopolisCity_Text_GiganticPokemonFight
SootopolisCity_Text_GiganticPokemonFight: @ 0x081E31E2
	.string "あんなに　おおきな　ポケモンが\n"
	.string "2ひきも　あばれている　なんて\l"
	.string "とても　わたしたちの　てに　おえないわ！$"

	.globl SootopolisCity_Text_FearedWorstWhenPokemonFlewDown
SootopolisCity_Text_FearedWorstWhenPokemonFlewDown: @ 0x081E3217
	.string "3ひきめの　おおきな　ポケモンが\n"
	.string "そらから　おりてきた　ときには\l"
	.string "もう　どうなることかと　おもったわ⋯⋯$"

	.globl SootopolisCity_Text_NightSkyFavoriteScenery
SootopolisCity_Text_NightSkyFavoriteScenery: @ 0x081E324C
	.string "かざんの　かこう　という\n"
	.string "わっかに　かこまれた　まるい　よぞら\p"
	.string "その　なかでは　たくさんの　ほしが\n"
	.string "いきている　みたいに　またたくの⋯⋯\l"
	.string "わたしが　いちばん　すきな　けしき$"

	.globl SootopolisCity_Text_WeatherWentWild
SootopolisCity_Text_WeatherWentWild: @ 0x081E32A3
	.string "きょうの　あさは　いいてんき　だったのよ\n"
	.string "それが⋯⋯\p"
	.string "とつぜん　くもり　はじめたと　おもったら\n"
	.string "つよい　あめが　ふりだして\l"
	.string "かみなりも　ゴロゴロ　なりだして\l"
	.string "てんきが　メチャメチャに　なっちゃったの\p"
	.string "それも　これも　ぜんぶ\n"
	.string "あの　ポケモンの　せい　かしら⋯⋯？$"

	.globl SootopolisCity_Text_YouBroughtFlyingMon
SootopolisCity_Text_YouBroughtFlyingMon: @ 0x081E3326
	.string "えっ！\p"
	.string "あの　そらから　おりてきた　ポケモンを\n"
	.string "つれてきたの　って　あなたなの！？\p"
	.string "⋯⋯へえ　やるじゃない！$"

	.globl SootopolisCity_Text_GroudonPleaseStop
SootopolisCity_Text_GroudonPleaseStop: @ 0x081E335D
	.string "マツブサ“グ⋯　グラードン⋯⋯\n"
	.string "たのむから　もう　やめてくれ！\p"
	.string "おまえの　ちからは　もう　わかった！\p"
	.string "このままでは　ルネ　だけじゃない\n"
	.string "ホウエンじゅうが\l"
	.string "めちゃめちゃに　なってしまう！$"

	.globl SootopolisCity_Text_AfterAllOurScheming
SootopolisCity_Text_AfterAllOurScheming: @ 0x081E33BA
	.string "マツブサ“ちょうこだい　ポケモンは\n"
	.string "グラードンと　カイオーガ　だけじゃ\l"
	.string "なかったと　いうのか⋯⋯\p"
	.string "われわれは　ひっしに　なって\n"
	.string "あれこれ　うごきまわって　きたが\l"
	.string "あの　ポケモンの　ひとはたらきで\l"
	.string "ぜんぶ　もとどおり　というわけか⋯⋯\p"
	.string "ふ⋯⋯　ふははは⋯⋯$"

	.globl SootopolisCity_Text_KyogreCalmDown
SootopolisCity_Text_KyogreCalmDown: @ 0x081E343A
	.string "アオギリ“カイオーガ！　どうした！？\n"
	.string "これを　みろ！　べにいろのたま　だぞ！\l"
	.string "おとなしくなるんだ！　カイオーガ！\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "だめだ！　ぜんぜん　きかない！$"

	.globl SootopolisCity_Text_TryingMeaninglessToPokemon
SootopolisCity_Text_TryingMeaninglessToPokemon: @ 0x081E3495
	.string "アオギリ“カイオーガと　グラードンは\n"
	.string "どこかへ　とびさって　しまった\p"
	.string "そして　ホウエンの　てんきも\n"
	.string "また　もとどおりに　なった⋯⋯\p"
	.string "はは　ははは⋯⋯\p"
	.string "おれたちの　やろうと　したことは\n"
	.string "ポケモンから　みれば\l"
	.string "ちっぽけなこと　だったの　かもな⋯⋯$"

	.globl SootopolisCity_Text_InvolvedWithCrisisComeWithMe
SootopolisCity_Text_InvolvedWithCrisisComeWithMe: @ 0x081E350F
	.string "ダイゴ“あそこで　たたかって　いるのは\n"
	.string "グラードン⋯⋯\l"
	.string "そして　カイオーガ⋯⋯\p"
	.string "ながい　ねむりから　めざめた\n"
	.string "2ひきの　ちょうこだい　ポケモンは\p"
	.string "やりばのない　エネルギーを\n"
	.string "おたがいに　ぶつけあっている⋯⋯\p"
	.string "⋯⋯{PLAYER}{KUN}\p"
	.string "ここまで　きた　ということは\n"
	.string "きみは　このじけんに　かかわる\l"
	.string "かくごが　できている　ということだね\p"
	.string "よし！　それなら\n"
	.string "きみに　あわせたい　ひとが　いるんだ\p"
	.string "ちょっと　ボクに　ついておいで$"

	.globl SootopolisCity_Text_DoesThisMakeYourFearPokemon
SootopolisCity_Text_DoesThisMakeYourFearPokemon: @ 0x081E35DC
	.string "ダイゴ“ねえ　{PLAYER}{KUN}\n"
	.string "グラードンと　カイオーガを　みて\l"
	.string "ポケモンは　こわいものだと　おもったかい？\p"
	.string "でも　そんなことは　ないんだよ\n"
	.string "ポケモンって　ほんとうは　もっと⋯⋯\p"
	.string "⋯⋯いや　きみなら　そんなことは\n"
	.string "もう　とっくに　きがついて　いるよね$"

	.globl SootopolisCity_Text_HereWereAreHelpWallace
SootopolisCity_Text_HereWereAreHelpWallace: @ 0x081E3656
	.string "ダイゴ“さあ　ついた！\p"
	.string "このおくに　ミクリさん　という\n"
	.string "ひとが　いるんだ\p"
	.string "きみなら　かれの　ちからに\n"
	.string "なって　あげられると　おもうよ⋯⋯$"

	.globl SootopolisCity_Text_KnowWhatsNeededToHelpHim
SootopolisCity_Text_KnowWhatsNeededToHelpHim: @ 0x081E369B
	.string "ダイゴ“きみなら　かれの　ちからに\n"
	.string "なって　あげられると　おもうよ⋯⋯$"

	.globl SootopolisCity_Text_NeverBeenToSkyPillar
SootopolisCity_Text_NeverBeenToSkyPillar: @ 0x081E36BF
	.string "ダイゴ“そらのはしら⋯⋯\n"
	.string "ボクも　まだ　いったことが　ないけど\l"
	.string "いったい　どこに　あるんだろうね$"

	.globl SootopolisCity_Text_SoThatsRayquaza
SootopolisCity_Text_SoThatsRayquaza: @ 0x081E36F0
	.string "ダイゴ“あれが　レックウザか⋯⋯\p"
	.string "あばれていた　2ひきが　おそれをなして\n"
	.string "さっていく　なんて　すごいや⋯⋯$"

	.globl SootopolisCity_Text_MaxieArchieLeft
SootopolisCity_Text_MaxieArchieLeft: @ 0x081E3726
	.string "ダイゴ“マツブサと　アオギリの　ふたりは\n"
	.string "どこかへ　いって　しまった　ようだね\p"
	.string "もしかすると　おくりびやまに\n"
	.string "たまを　かえしに　いったのかも⋯⋯$"

	.globl SootopolisCity_Text_HaventYouScaledSkyPillar
SootopolisCity_Text_HaventYouScaledSkyPillar: @ 0x081E376F
	.string "ミクリ“おや？　{PLAYER}{KUN}\p"
	.string "あれから　そらのはしらを　のぼって\n"
	.string "いかなかったのかい？\p"
	.string "きみなら　きっと　いけるさ\n"
	.string "そらのはしらの　おくじょうへ⋯⋯$"

	.globl SootopolisCity_Text_AquaMagmaDidntMeanHarm
SootopolisCity_Text_AquaMagmaDidntMeanHarm: @ 0x081E37B8
	.string "ミクリ“{PLAYER}{KUN}⋯⋯\p"
	.string "マグマだんと　アクアだんの　ふたりも\n"
	.string "きっと　わるぎは　なかったの　だろうね\p"
	.string "ちょっと　かれらの　はなしを\n"
	.string "きいてやって　みては　どうかな⋯⋯$"

	.globl SootopolisCity_Text_ThankYouForHelpAcceptThis
SootopolisCity_Text_ThankYouForHelpAcceptThis: @ 0x081E380B
	.string "ミクリ“{PLAYER}{KUN}⋯⋯\n"
	.string "やはり　わたしの　めは　ただしかった\p"
	.string "きみが　ちからを　かしてくれた　おかげで\n"
	.string "ルネシティは⋯⋯\l"
	.string "いや　ホウエンは　すくわれたんだよ\p"
	.string "まちの　みんなを　だいひょうして\n"
	.string "おれいを　いわせて　もらうよ\l"
	.string "⋯⋯ありがとう\p"
	.string "これは　わたしからの　プレゼントだ\n"
	.string "うけとって　くれたまえ！$"

	.globl SootopolisCity_Text_ExplainWaterfallGoToGym
SootopolisCity_Text_ExplainWaterfallGoToGym: @ 0x081E38A0
	.string "その　ひでんマシンは　たきのぼり！\p"
	.string "レインバッジを　もっていれば\n"
	.string "そのわざを　おぼえさせた　ポケモンが\l"
	.string "たきを　のぼれるように　なるのさ！\p"
	.string "そして⋯⋯　レインバッジは\n"
	.string "どこで　もらえるのか　というと⋯⋯\p"
	.string "もう　おわかりだね\n"
	.string "そう！　ルネの　ジムリーダーに　かつこと\p"
	.string "さあ　じゅんびが　できたら\n"
	.string "なかに　はいって　くれたまえ！$"

	.globl SootopolisCity_Text_DazzledByMentor
SootopolisCity_Text_DazzledByMentor: @ 0x081E3943
	.string "ミクリ“わたしの　ししょうの\n"
	.string "かれい　かつ　ゆうがな　たたかいぶりに\l"
	.string "きっと　きみは　おどろく　だろうよ！$"
