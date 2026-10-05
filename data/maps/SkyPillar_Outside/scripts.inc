@ SkyPillar_Outside scripts (JP map g24 m78 @ 0x0821BBED)

SkyPillar_Outside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Outside_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SkyPillar_Outside_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SkyPillar_Outside_OnFrame
	.byte 0

SkyPillar_Outside_OnTransition: @ 0x0821BBFD
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SkyPillar_Outside_EventScript_HideMapNamePopup
	call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, SkyPillar_Outside_EventScript_CheckSetAbnormalWeather
	end

SkyPillar_Outside_EventScript_HideMapNamePopup:: @ 0x0821BC14
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

SkyPillar_Outside_EventScript_CheckSetAbnormalWeather:: @ 0x0821BC18
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	return

SkyPillar_Outside_OnLoad: @ 0x0821BC22
	call_if_set FLAG_WALLACE_GOES_TO_SKY_PILLAR, SkyPillar_Outside_EventScript_OpenDoor
	end

SkyPillar_Outside_EventScript_OpenDoor:: @ 0x0821BC2C
	setmetatile 14, 4, METATILE_Pacifidlog_SkyPillar_DoorOpen_Top, FALSE
	setmetatile 14, 5, METATILE_Pacifidlog_SkyPillar_DoorOpen_Bottom, FALSE
	return

SkyPillar_Outside_OnFrame: @ 0x0821BC3F
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 3, SkyPillar_Outside_EventScript_WallaceScene
	.2byte 0

SkyPillar_Outside_EventScript_WallaceScene:: @ 0x0821BC49
	lockall
	applywaitmovement LOCALID_SKY_PILLAR_WALLACE, SkyPillar_Outside_Movement_WallaceApproachPlayer
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox SkyPillar_Outside_Text_OpenedDoorToSkyPillar, MSGBOX_DEFAULT
	closemessage
	delay 30
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	delay 40
	msgbox SkyPillar_Outside_Text_EarthquakeNotMomentToWaste, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SkyPillar_Outside_Movement_PlayerClimbSkyPillar
	applymovement LOCALID_SKY_PILLAR_WALLACE, SkyPillar_Outside_Movement_WallaceClimbSkyPillar
	waitmovement 0
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 3   @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 5   @ shake delay
	special ShakeCamera
	waitstate
	delay 20
	applywaitmovement LOCALID_SKY_PILLAR_WALLACE, Common_Movement_WalkInPlaceFasterLeft
	delay 10
	applywaitmovement LOCALID_SKY_PILLAR_WALLACE, Common_Movement_WalkInPlaceFasterRight
	delay 20
	applywaitmovement LOCALID_SKY_PILLAR_WALLACE, Common_Movement_WalkInPlaceFasterDown
	delay 30
	msgbox SkyPillar_Outside_Text_SituationGettingWorse, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_WEATHER_CTRL
	setweather WEATHER_ABNORMAL
	doweather
	special WaitWeather
	delay 30
	msgbox SkyPillar_Outside_Text_GotToGoBackForSootopolis, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenswapbuffers FADE_TO_BLACK
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SOOTOPOLIS_CITY_STATE, 4
	removeobject LOCALID_SKY_PILLAR_WALLACE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

SkyPillar_Outside_Movement_WallaceApproachPlayer: @ 0x0821BD18
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

SkyPillar_Outside_Movement_WallaceClimbSkyPillar: @ 0x0821BD23
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SkyPillar_Outside_Movement_PlayerClimbSkyPillar: @ 0x0821BD30
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

SkyPillar_Outside_EventScript_Wallace:: @ 0x0821BD3D
	end

SkyPillar_Outside_EventScript_ClosedDoor:: @ 0x0821BD3E
	msgbox SkyPillar_Outside_Text_DoorIsClosed, MSGBOX_SIGN
	end

SkyPillar_Outside_Text_DoorIsClosed: @ 0x0821BD47
	.string "とびらは　とざされて　いる！$"

SkyPillar_Outside_Text_OpenedDoorToSkyPillar: @ 0x0821BD56
	.string "ミクリ“やっ　ごめん　ごめん！\p"
	.string "あんまり　あわてた　ものだから\n"
	.string "きみを　おいてきて　しまったよ！\p"
	.string "しまっていた　そらのはしらの　とびらは\n"
	.string "わたしが　あけて　おいた\p"
	.string "{PLAYER}{KUN}　さあ　いこう！$"

SkyPillar_Outside_Text_EarthquakeNotMomentToWaste: @ 0x0821BDB5
	.string "ミクリ“じしんだ！\p"
	.string "こうしては　いられない\n"
	.string "さきを　いそごう！$"

SkyPillar_Outside_Text_SituationGettingWorse: @ 0x0821BDD5
	.string "ミクリ“うーむ　じょうきょうは\n"
	.string "だんだん　わるくなって　きている⋯⋯$"

SkyPillar_Outside_Text_GotToGoBackForSootopolis: @ 0x0821BDF8
	.string "ミクリ“まずいな⋯⋯\p"
	.string "てんこうの　みだれが　このあたりまで\n"
	.string "ひろがり　はじめている⋯⋯\p"
	.string "{PLAYER}{KUN}\p"
	.string "ここを　のぼって　いけば\n"
	.string "レックウザが　いるはずだ\p"
	.string "わたしは　まちのことが　しんぱい　だから\n"
	.string "さきに　ルネまで　もどっていよう！\p"
	.string "ここは　きみに　まかせるから\n"
	.string "しっかり　たのんだよ！$"
