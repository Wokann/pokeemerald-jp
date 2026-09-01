@ Route111 scripts (JP map g0 m26 @ 0x081EA14D)

Route111_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route111_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route111_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route111_OnFrame
	.byte 0

Route111_OnLoad:: @ 0x081EA162
	call_if_unset FLAG_REGI_DOORS_OPENED, Route111_EventScript_CloseDesertRuins
	call_if_eq VAR_MIRAGE_TOWER_STATE, TRUE, Route111_EventScript_ShowTemporaryMirageTower
	end

Route111_EventScript_CloseDesertRuins:: @ 0x081EA177
	setmetatile 29, 86, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 29, 87, METATILE_General_RockWall_SandBase, TRUE
	return

Route111_EventScript_ShowTemporaryMirageTower:: @ 0x081EA18A
	setmetatile 18, 53, METATILE_Mauville_MirageTower_Tile0, FALSE
	setmetatile 19, 53, METATILE_Mauville_MirageTower_Tile1, FALSE
	setmetatile 20, 53, METATILE_Mauville_MirageTower_Tile2, FALSE
	setmetatile 18, 54, METATILE_Mauville_MirageTower_Tile3, FALSE
	setmetatile 19, 54, METATILE_Mauville_MirageTower_Tile4, FALSE
	setmetatile 20, 54, METATILE_Mauville_MirageTower_Tile5, FALSE
	setmetatile 18, 55, METATILE_Mauville_MirageTower_Tile6, FALSE
	setmetatile 19, 55, METATILE_Mauville_MirageTower_Tile7, FALSE
	setmetatile 20, 55, METATILE_Mauville_MirageTower_Tile8, FALSE
	setmetatile 18, 56, METATILE_Mauville_MirageTower_Tile9, FALSE
	setmetatile 19, 56, METATILE_Mauville_MirageTower_TileA, FALSE
	setmetatile 20, 56, METATILE_Mauville_MirageTower_TileB, FALSE
	setmetatile 18, 57, METATILE_Mauville_MirageTower_TileC, FALSE
	setmetatile 19, 57, METATILE_Mauville_MirageTower_TileD, FALSE
	setmetatile 20, 57, METATILE_Mauville_MirageTower_TileE, FALSE
	setmetatile 18, 58, METATILE_Mauville_MirageTower_TileF, FALSE
	setmetatile 19, 58, METATILE_Mauville_MirageTower_Tile10, FALSE
	setmetatile 20, 58, METATILE_Mauville_MirageTower_Tile11, FALSE
	return

Route111_OnTransition:: @ 0x081EA22D
	setvar VAR_TRAINER_HILL_IS_ACTIVE, FALSE
	special SetMirageTowerVisibility
	call_if_unset FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_SetLayoutNoMirageTower
	call_if_eq VAR_MIRAGE_TOWER_STATE, TRUE, Route111_EventScript_SetFallingPlayerGfx
	call_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_SetMirageTowerGone
	call Route111_EventScript_CheckSetSandstorm
	call GabbyAndTy_EventScript_UpdateLocation
	goto_if_not_defeated TRAINER_VICKY, Route111_EventScript_SetWinstratesNotDefeated
	end

Route111_EventScript_SetFallingPlayerGfx:: @ 0x081EA268
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route111_EventScript_SetFallingPlayerGfxMale
	goto_if_eq VAR_RESULT, FEMALE, Route111_EventScript_SetFallingPlayerGfxFemale
	return

Route111_EventScript_SetFallingPlayerGfxMale:: @ 0x081EA280
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

Route111_EventScript_SetFallingPlayerGfxFemale:: @ 0x081EA286
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

Route111_EventScript_CheckSetSandstorm:: @ 0x081EA28C
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, 34, Route111_EventScript_EndCheckSetSandstorm
	goto_if_gt VAR_TEMP_1, 107, Route111_EventScript_EndCheckSetSandstorm
	goto_if_gt VAR_TEMP_1, 72, Route111_EventScript_SetSandstorm
	goto_if_gt VAR_TEMP_0, 2000, Route111_EventScript_EndCheckSetSandstorm
	goto_if_lt VAR_TEMP_0, 8, Route111_EventScript_EndCheckSetSandstorm

Route111_EventScript_SetSandstorm:: @ 0x081EA2C8
	setweather WEATHER_SANDSTORM

Route111_EventScript_EndCheckSetSandstorm:: @ 0x081EA2CB
	return

Route111_EventScript_SetWinstratesNotDefeated:: @ 0x081EA2CC
	clearflag FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
	cleartrainerflag TRAINER_VICTOR
	cleartrainerflag TRAINER_VICTORIA
	cleartrainerflag TRAINER_VIVI
	end

Route111_EventScript_SetLayoutNoMirageTower:: @ 0x081EA2E2
	setmaplayoutindex LAYOUT_ROUTE111_NO_MIRAGE_TOWER
	return

Route111_EventScript_SetMirageTowerGone:: @ 0x081EA2E6
	setvar VAR_MIRAGE_TOWER_STATE, 3
	return

Route111_OnWarp:: @ 0x081EA2EC
	map_script_2 VAR_MIRAGE_TOWER_STATE, TRUE, Route111_EventScript_HidePlayerForMirageTower
	.2byte 0

Route111_EventScript_HidePlayerForMirageTower:: @ 0x081EA2F6
	hideobjectat LOCALID_PLAYER, MAP_LITTLEROOT_TOWN
	end

Route111_OnFrame:: @ 0x081EA2FC
	map_script_2 VAR_MIRAGE_TOWER_STATE, TRUE, Route111_EventScript_MirageTowerDisappear
	.2byte 0

Route111_EventScript_MirageTowerDisappear:: @ 0x081EA306
	lockall
	special StartMirageTowerShake
	delay 24
	playse SE_FALL
	addobject LOCALID_ROUTE111_PLAYER_FALLING
	special StartPlayerDescendMirageTower
	showobjectat LOCALID_PLAYER, MAP_LITTLEROOT_TOWN
	removeobject LOCALID_ROUTE111_PLAYER_FALLING
	delay 16
	turnobject LOCALID_PLAYER, DIR_NORTH
	delay 16
	special StartMirageTowerDisintegration
	special StartMirageTowerFossilFallAndSink
	setvar VAR_MIRAGE_TOWER_STATE, 2
	clearflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, Route111_EventScript_RootFossilDisappeared
	msgbox Route111_Text_ClawFossilDisappeared, MSGBOX_DEFAULT
	releaseall
	end

Route111_EventScript_RootFossilDisappeared:: @ 0x081EA34D
	msgbox Route111_Text_RootFossilDisappeared, MSGBOX_DEFAULT
	releaseall
	end

Route111_Movement_PlayerFall:
	lock_anim
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route111_EventScript_Girl:: @ 0x081EA35F
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_ROUTE_111_RECEIVED_BERRY, Route111_EventScript_ReceivedBerry
	msgbox Route111_Text_WateredPlantsEveryDayTakeBerry, MSGBOX_DEFAULT
	giveitem ITEM_RAZZ_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_ROUTE_111_RECEIVED_BERRY
	special GetPlayerBigGuyGirlString
	msgbox Route111_Text_GoingToTryToMakeDifferentColorBerries, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_ReceivedBerry:: @ 0x081EA39A
	msgbox Route111_Text_WhatColorBerriesToLookForToday, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_ViciousSandstormTriggerUp:: @ 0x081EA3A4
	lockall
	setvar VAR_0x8004, FALSE
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTriggerDown:: @ 0x081EA3B0
	lockall
	setvar VAR_0x8004, TRUE
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTriggerLeft:: @ 0x081EA3BC
	lockall
	setvar VAR_0x8004, 2
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTriggerRight:: @ 0x081EA3C8
	lockall
	setvar VAR_0x8004, 3
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTrigger:: @ 0x081EA3D4
	checkitem ITEM_GO_GOGGLES
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_PreventRouteAccess
	setvar VAR_TEMP_3, TRUE
	releaseall
	end

Route111_EventScript_PreventRouteAccess:: @ 0x081EA3EB
	msgbox gText_SandstormIsVicious, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8004, FALSE, Route111_EventScript_PushUpFromRoute
	call_if_eq VAR_0x8004, TRUE, Route111_EventScript_PushDownFromRoute
	call_if_eq VAR_0x8004, 2, Route111_EventScript_PushLeftFromRoute
	call_if_eq VAR_0x8004, 3, Route111_EventScript_PushRightFromRoute
	releaseall
	end

Route111_EventScript_PushUpFromRoute:: @ 0x081EA422
	applymovement LOCALID_PLAYER, Route111_Movement_PushUpFromRoute
	waitmovement 0
	return

Route111_EventScript_PushDownFromRoute:: @ 0x081EA42D
	applymovement LOCALID_PLAYER, Route111_Movement_PushDownFromRoute
	waitmovement 0
	return

Route111_EventScript_PushLeftFromRoute:: @ 0x081EA438
	applymovement LOCALID_PLAYER, Route111_Movement_PushLeftFromRoute
	waitmovement 0
	return

Route111_EventScript_PushRightFromRoute:: @ 0x081EA443
	applymovement LOCALID_PLAYER, Route111_Movement_PushRightFromRoute
	waitmovement 0
	return

Route111_Movement_PushUpFromRoute:
	walk_up
	step_end

Route111_Movement_PushDownFromRoute:
	walk_down
	step_end

Route111_Movement_PushLeftFromRoute:
	walk_left
	step_end

Route111_Movement_PushRightFromRoute:
	walk_right
	step_end

Route111_EventScript_SunTrigger:: @ 0x081EA456
	setweather WEATHER_SUNNY
	fadenewbgm MUS_ROUTE110
	resetweather
	setvar VAR_TEMP_3, FALSE
	end

Route111_EventScript_SandstormTrigger:: @ 0x081EA463
	setweather WEATHER_SANDSTORM
	fadenewbgm MUS_DESERT
	resetweather
	end

Route111_EventScript_Victor:: @ 0x081EA46B
	lock
	faceplayer
	setflag FLAG_LANDMARK_WINSTRATE_FAMILY
	msgbox Route111_Text_BattleOurFamily, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_BattleWinstrates
	msgbox Route111_Text_IsThatSo, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_BattleWinstrates:: @ 0x081EA48D
	msgbox Route111_Text_VictorIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICTOR, Route111_Text_VictorDefeat
	applymovement LOCALID_ROUTE111_VICTOR, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_VictorPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE111_VICTOR, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_ROUTE111_VICTOR
	call Route111_EventScript_CloseWinstrateDoor
	applymovement LOCALID_PLAYER, Route111_Movement_WaitForNextWinstrate
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	addobject LOCALID_ROUTE111_VICTORIA
	applymovement LOCALID_ROUTE111_VICTORIA, Route111_Movement_WinstrateExitHouse
	waitmovement 0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_VictoriaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICTORIA, Route111_Text_VictoriaDefeat
	applymovement LOCALID_ROUTE111_VICTORIA, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_VictoriaPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE111_VICTORIA, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_ROUTE111_VICTORIA
	call Route111_EventScript_CloseWinstrateDoor
	applymovement LOCALID_PLAYER, Route111_Movement_WaitForNextWinstrate
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	addobject LOCALID_ROUTE111_VIVI
	applymovement LOCALID_ROUTE111_VIVI, Route111_Movement_WinstrateExitHouse
	waitmovement 0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_ViviIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VIVI, Route111_Text_ViviDefeat
	applymovement LOCALID_ROUTE111_VIVI, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_ViviPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE111_VIVI, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_ROUTE111_VIVI
	call Route111_EventScript_CloseWinstrateDoor
	applymovement LOCALID_PLAYER, Route111_Movement_WaitForNextWinstrate
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	addobject LOCALID_ROUTE111_VICKY
	applymovement LOCALID_ROUTE111_VICKY, Route111_Movement_WinstrateExitHouse
	waitmovement 0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_VickyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICKY, Route111_Text_VickyDefeat
	msgbox Route111_Text_VickyPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE111_VICKY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	applymovement LOCALID_ROUTE111_VICKY, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_ROUTE111_VICKY
	call Route111_EventScript_CloseWinstrateDoor
	release
	end

Route111_EventScript_OpenWinstrateDoor:: @ 0x081EA5E2
	opendoor 13, 113
	waitdooranim_jp
	return

Route111_EventScript_CloseWinstrateDoor:: @ 0x081EA5E9
	closedoor 13, 113
	waitdooranim_jp
	return

Route111_Movement_WinstrateEnterHouse:
	walk_in_place_faster_up
	walk_up
	step_end

Route111_Movement_WinstrateExitHouse:
	walk_down
	step_end

Route111_Movement_WaitForNextWinstrate:
	delay_16
	delay_16
	delay_16
	step_end

Route111_EventScript_RouteSignMauville:: @ 0x081EA5F9
	msgbox Route111_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route111_EventScript_WinstrateHouseSign:: @ 0x081EA602
	msgbox Route111_Text_WinstrateHouseSign, MSGBOX_SIGN
	end

Route111_EventScript_RouteSign112:: @ 0x081EA60B
	msgbox Route111_Text_RouteSign112, MSGBOX_SIGN
	end

Route111_EventScript_RouteSign113:: @ 0x081EA614
	msgbox Route111_Text_RouteSign113, MSGBOX_SIGN
	end

Route111_EventScript_OldLadysRestStopSign:: @ 0x081EA61D
	msgbox Route111_Text_OldLadysRestStopSign, MSGBOX_SIGN
	end

Route111_EventScript_TrainerTipsSpAtkSpDef:: @ 0x081EA626
	msgbox Route111_Text_TrainerTipsSpAtkSpDef, MSGBOX_SIGN
	end

Route111_EventScript_Man1:: @ 0x081EA62F
	msgbox Route111_Text_ToughToKeepWinningUpTheRanks, MSGBOX_NPC
	end

Route111_EventScript_Man2:: @ 0x081EA638
	msgbox Route111_Text_WinstrateFamilyDestroyedMe, MSGBOX_NPC
	end

Route111_EventScript_Hiker:: @ 0x081EA641
	lock
	faceplayer
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 3, Route111_EventScript_HikerMirageTowerGone
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_HikerMirageTowerDisintegrated
	goto_if_set FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_HikerMirageTowerVisible
	msgbox Route111_Text_ShouldBeMirageTowerAroundHere, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerGone:: @ 0x081EA66C
	msgbox Route111_Text_MirageTowerHasntBeenSeenSince, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerDisintegrated:: @ 0x081EA676
	msgbox Route111_Text_ThatWasShockingSandRainedDown, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerVisible:: @ 0x081EA680
	msgbox Route111_Text_MirageTowerClearlyVisible, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RockSmashTipFatMan:: @ 0x081EA68A
	lockall
	applymovement LOCALID_ROUTE111_ROCK_SMASH_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route111_Text_MauvilleUncleToldMeToTakeRockSmash, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE111_ROCK_SMASH_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Route111_EventScript_Drew:: @ 0x081EA6AA
	trainerbattle_single TRAINER_DREW, Route111_Text_DrewIntro, Route111_Text_DrewDefeat
	msgbox Route111_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Heidi:: @ 0x081EA6C1
	trainerbattle_single TRAINER_HEIDI, Route111_Text_HeidiIntro, Route111_Text_HeidiDefeat
	msgbox Route111_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Beau:: @ 0x081EA6D8
	trainerbattle_single TRAINER_BEAU, Route111_Text_BeauIntro, Route111_Text_BeauDefeat
	msgbox Route111_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Becky:: @ 0x081EA6EF
	trainerbattle_single TRAINER_BECKY, Route111_Text_BeckyIntro, Route111_Text_BeckyDefeat
	msgbox Route111_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Dusty:: @ 0x081EA706
	trainerbattle_single TRAINER_DUSTY_1, Route111_Text_DustyIntro, Route111_Text_DustyDefeat, Route111_EventScript_RegisterDusty
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchDusty
	msgbox Route111_Text_DustyPostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RegisterDusty:: @ 0x081EA732
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route111_Text_DustyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DUSTY_1
	release
	end

Route111_EventScript_RematchDusty:: @ 0x081EA751
	trainerbattle_rematch TRAINER_DUSTY_1, Route111_Text_DustyRematchIntro, Route111_Text_DustyRematchDefeat
	msgbox Route111_Text_DustyPostRematch, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Travis:: @ 0x081EA768
	trainerbattle_single TRAINER_TRAVIS, Route111_Text_TravisIntro, Route111_Text_TravisDefeat
	msgbox Route111_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Irene:: @ 0x081EA77F
	trainerbattle_single TRAINER_IRENE, Route111_Text_IreneIntro, Route111_Text_IreneDefeat
	msgbox Route111_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Daisuke:: @ 0x081EA796
	trainerbattle_single TRAINER_DAISUKE, Route111_Text_DaisukeIntro, Route111_Text_DaisukeDefeat
	msgbox Route111_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Wilton:: @ 0x081EA7AD
	trainerbattle_single TRAINER_WILTON_1, Route111_Text_WiltonIntro, Route111_Text_WiltonDefeat, Route111_EventScript_RegisterWilton
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchWilton
	msgbox Route111_Text_WiltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RegisterWilton:: @ 0x081EA7D9
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route111_Text_WiltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WILTON_1
	release
	end

Route111_EventScript_RematchWilton:: @ 0x081EA7F8
	trainerbattle_rematch TRAINER_WILTON_1, Route111_Text_WiltonRematchIntro, Route111_Text_WiltonRematchDefeat
	msgbox Route111_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Brooke:: @ 0x081EA80F
	trainerbattle_single TRAINER_BROOKE_1, Route111_Text_BrookeIntro, Route111_Text_BrookeDefeat, Route111_EventScript_RegisterBrooke
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchBrooke
	msgbox Route111_Text_BrookePostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RegisterBrooke:: @ 0x081EA83B
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route111_Text_BrookeRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BROOKE_1
	release
	end

Route111_EventScript_RematchBrooke:: @ 0x081EA85A
	trainerbattle_rematch TRAINER_BROOKE_1, Route111_Text_BrookeRematchIntro, Route111_Text_BrookeRematchDefeat
	msgbox Route111_Text_BrookePostRematch, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Hayden:: @ 0x081EA871
	trainerbattle_single TRAINER_HAYDEN, Route111_Text_HaydenIntro, Route111_Text_HaydenDefeat
	msgbox Route111_Text_HaydenPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Bianca:: @ 0x081EA888
	trainerbattle_single TRAINER_BIANCA, Route111_Text_BiancaIntro, Route111_Text_BiancaDefeat
	msgbox Route111_Text_BiancaPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Tyron:: @ 0x081EA89F
	trainerbattle_single TRAINER_TYRON, Route111_Text_TyronIntro, Route111_Text_TyronDefeat
	msgbox Route111_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Celina:: @ 0x081EA8B6
	trainerbattle_single TRAINER_CELINA, Route111_Text_CelinaIntro, Route111_Text_CelinaDefeat
	msgbox Route111_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Celia:: @ 0x081EA8CD
	trainerbattle_single TRAINER_CELIA, Route111_Text_CeliaIntro, Route111_Text_CeliaDefeat
	msgbox Route111_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Bryan:: @ 0x081EA8E4
	trainerbattle_single TRAINER_BRYAN, Route111_Text_BryanIntro, Route111_Text_BryanDefeat
	msgbox Route111_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Branden:: @ 0x081EA8FB
	trainerbattle_single TRAINER_BRANDEN, Route111_Text_BrandenIntro, Route111_Text_BrandenDefeat
	msgbox Route111_Text_BrandenPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_TrainerHillSign:: @ 0x081EA912
	msgbox Route111_Text_TrainerHillSign, MSGBOX_SIGN
	end

Route111_Text_BattleOurFamily: @ 0x081EA91B
	.string "きみ！　たびの　とちゅう　だろうけれど\p"
	.string "どうだ？　ここは　ひとつ\n"
	.string "わたしたち　かぞく　4にんと\l"
	.string "ポケモン　しょうぶを　してみないか？$"

Route111_Text_IsThatSo: @ 0x081EA95E
	.string "あっそ！\n"
	.string "きが　むいたら　また　おいで！$"

Route111_Text_VictorIntro: @ 0x081EA973
	.string "いい　どきょうだ！　きにいったぞ！$"

Route111_Text_VictorDefeat: @ 0x081EA985
	.string "たはーっ！\n"
	.string "おもっていたより　つよいんだね　きみは！$"

Route111_Text_VictorPostBattle: @ 0x081EA9A0
	.string "おーい！\n"
	.string "なかなか　つよい　トレーナーが　いたぞー！$"

Route111_Text_VictoriaIntro: @ 0x081EA9BB
	.string "あれま！　いがいに　わかいのね！\p"
	.string "うちの　しゅじんに　かってしまう　とは\n"
	.string "なんと　すごうでの　トレーナー　なの！\p"
	.string "じゃあ　こんどは　わたしと　しょうぶよ！$"

Route111_Text_VictoriaDefeat: @ 0x081EAA09
	.string "んまーっ！\n"
	.string "あなたって　なんて　つよいのかしら！$"

Route111_Text_VictoriaPostBattle: @ 0x081EAA22
	.string "つよいわよー！\n"
	.string "このひと　すっごく　つよいわよー！$"

Route111_Text_ViviIntro: @ 0x081EAA3C
	.string "ママより　つよいなんて　すごーい！\p"
	.string "でも　あたし　だって　つよいんだから！\n"
	.string "ほんと　なんだってば！$"

Route111_Text_ViviDefeat: @ 0x081EAA6E
	.string "えっ　もしかして　まけちゃった⋯⋯$"

Route111_Text_ViviPostBattle: @ 0x081EAA80
	.string "くやしい⋯⋯\p"
	.string "⋯⋯　ぐっすん！　おばあちゃーん！！$"

Route111_Text_VickyIntro: @ 0x081EAA9A
	.string "こらーっ！\n"
	.string "わしの　かわいい　まごに　なにすんじゃ！\p"
	.string "こうなったら　わしが　おまえさんを\n"
	.string "メタメタに　してやるから　かくごせぇ！$"

Route111_Text_VickyDefeat: @ 0x081EAADB
	.string "フガッ！　つよいのう⋯⋯\n"
	.string "まごの　いうことは　ほんとう　じゃった$"

Route111_Text_VickyPostBattle: @ 0x081EAAFC
	.string "あんた⋯⋯　いそぎのたびで　ないのなら\n"
	.string "うちに　よっていって　おくれ⋯⋯$"

Route111_Text_ToughToKeepWinningUpTheRanks: @ 0x081EAB21
	.string "もっと　ポケモン　きたえないと\n"
	.string "かちぬくのは　きびしそうだ\p"
	.string "いままでの　ジムリーダーより\n"
	.string "はるかに　つよいと　きくからな\l"
	.string "ポケモンリーグにいる　してんのうは！$"

Route111_Text_WinstrateFamilyDestroyedMe: @ 0x081EAB71
	.string "カチヌキいっかに　いどんだけれど\n"
	.string "4にん　つづけての　ポケモンしょうぶは\l"
	.string "きびしいよな⋯⋯　ボロまけ　したよ$"

Route111_Text_RouteSignMauville: @ 0x081EABA8
	.string "ここは　111ばん　どうろ\n"
	.string "{DOWN_ARROW}　キンセツシティ$"

Route111_Text_WinstrateHouseSign: @ 0x081EABC2
	.string "われら　かぞくの　こころは　ひとつ\n"
	.string "‘カチヌキ　ファミリーの　いえ’$"

Route111_Text_RouteSign112: @ 0x081EABE5
	.string "ここは　111ばん　どうろ\n"
	.string "{LEFT_ARROW}　112ばん　どうろ$"

Route111_Text_RouteSign113: @ 0x081EAC01
	.string "ここは　111ばん　どうろ\n"
	.string "{LEFT_ARROW}　113ばん　どうろ$"

Route111_Text_OldLadysRestStopSign: @ 0x081EAC1D
	.string "‘ケンコーばあさんの　いえ’\n"
	.string "つかれたと　おもうなら　よってらっしゃい！$"

Route111_Text_TrainerTipsSpAtkSpDef: @ 0x081EAC42
	.string "おとくな　けいじばん！！\p"
	.string "ポケモンの　つよさを　あらわす　ことばで\n"
	.string "とくこう　とは\l"
	.string "とくしゅ　こうげきりょく　のこと！\p"
	.string "とくぼう　とは\n"
	.string "とくしゅ　ぼうぎょりょく　のこと　です！$"

Route111_Text_ShouldBeMirageTowerAroundHere: @ 0x081EAC9B
	.string "この　あたりに　すなで　できた\n"
	.string "とうが　たっている　はず　なんだが\p"
	.string "どうしたわけか\n"
	.string "みえるときと　みえないときが　あるのだ\p"
	.string "だから　わたしは　それを\n"
	.string "げんえいのとう　と　よんでいる⋯⋯$"

Route111_Text_MirageTowerClearlyVisible: @ 0x081EACF8
	.string "みえるぞ！　すなのとう　が！\n"
	.string "げんえい　と　よばれた　すなのとうが\n"
	.string "はっきりと　みえる！\p"
	.string "しかし　そのすがたは　はかなくて\n"
	.string "いまにも　くずれて　しまいそうだ⋯⋯\p"
	.string "うーん　はいって　みたいが\n"
	.string "こわくて　ゆうきが　でん！$"

Route111_Text_ThatWasShockingSandRainedDown: @ 0x081EAD65
	.string "はー　びっくりした⋯⋯\p"
	.string "いきなり　すなが　そらから\n"
	.string "バラバラと　ふって　きたんじゃ\p"
	.string "で　なかは　どうじゃった？\n"
	.string "やはり　すなの　オバケ　とか　でたか？$"

Route111_Text_MirageTowerHasntBeenSeenSince: @ 0x081EADB1
	.string "あれから\n"
	.string "すなのとう　は　みえなく　なった\p"
	.string "やはり　げんえいのとう　だったのか⋯⋯$"

Route111_Text_ClawFossilDisappeared: @ 0x081EADDB
	.string "ツメのかせきは\n"
	.string "すなに　もぐって　しまった⋯⋯$"

Route111_Text_RootFossilDisappeared: @ 0x081EADF3
	.string "ねっこのかせきは\n"
	.string "すなに　もぐって　しまった⋯⋯$"

Route111_Text_MauvilleUncleToldMeToTakeRockSmash: @ 0x081EAE0C
	.string "しまった！\p"
	.string "111ばんどうろに　いくなら\n"
	.string "いわくだきを　もっていけ　って\l"
	.string "キンセツの　おじさんに　いわれてたんだ！\p"
	.string "おじさん？　サイクルショップの\n"
	.string "むかいがわの　いえに　すんでるよ$"

Route111_Text_TrainerHillSign: @ 0x081EAE67
	.string "{RIGHT_ARROW}　トレーナーヒル　いりぐち\n"
	.string "かけあがれ！　あつき　トレーナーたち！$"
