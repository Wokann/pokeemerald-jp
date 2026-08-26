@ SeafloorCavern_Entrance scripts (JP map g24 m27 @ 0x0821844E)

SeafloorCavern_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SeafloorCavern_Entrance_OnResume
	.byte 0

SeafloorCavern_Entrance_OnResume:: @ 0x08218454
	setdivewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 6, 5
	setescapewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 6, 5
	end

SeafloorCavern_Entrance_EventScript_Grunt:: @ 0x08218465
	lockall
	goto_if_eq VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 0x1, SeafloorCavern_Entrance_EventScript_GruntSpeechShort
	waitse
	playse SE_PIN
	applymovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_Delay48
	waitmovement 0
	delay 20
	call_if_eq VAR_FACING, DIR_WEST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	call_if_eq VAR_FACING, DIR_EAST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	delay 30
	setvar VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 0x1
	copyobjectxytoperm LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntSpeechShort:: @ 0x082184CD
	call_if_eq VAR_FACING, DIR_WEST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	call_if_eq VAR_FACING, DIR_EAST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast:: @ 0x08218503
	applymovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest:: @ 0x0821850E
	applymovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth:: @ 0x08218519
	applymovement LOCALID_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep: @ 0x08218524
	.string "あーーーーーっ！\n"
	.string "みおぼえの　ある　そのかおは！\p"
	.string "こんな　ところまで　きたって　ことは\n"
	.string "また　オレたちの　ジャマをしに！？\p"
	.string "おまえ　ごときが　アクアだんに\n"
	.string "はむかおう　だなんて\l"
	.string "100おくまんねん　はえーんだよ！\p"
	.string "おまえにゃ　マグマだんが　おにあいさ！\p"
	.string "⋯⋯そういえば　トクサネの　ちかくで\n"
	.string "マグマだんを　みかけたっけな\p"
	.string "あいつら⋯⋯\n"
	.string "ほんっとーーに　うみが　にあわねえぜ！$"

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort: @ 0x082185E0
	.string "おまえ　ごときが　アクアだんに\n"
	.string "はむかおう　だなんて\l"
	.string "100おくまんねん　はえーんだよ！\p"
	.string "おまえにゃ　マグマだんが　おにあいさ！\p"
	.string "⋯⋯そういえば　トクサネの　ちかくで\n"
	.string "マグマだんを　みかけたっけな\p"
	.string "あいつら⋯⋯\n"
	.string "ほんっとーーに　うみが　にあわねえぜ！$"
