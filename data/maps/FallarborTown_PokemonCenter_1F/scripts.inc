@ FallarborTown_PokemonCenter_1F scripts (JP map g5 m4 @ 0x081F5C4E)

FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:: @ 0x081F5C59
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse:: @ 0x081F5C62
	setvar VAR_0x800B, LOCALID_FALLARBOR_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl:: @ 0x081F5C70
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM:: @ 0x081F5C79
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette:: @ 0x081F5C82
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth:: @ 0x081F5CA9
	applymovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest:: @ 0x081F5CB9
	applymovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited:: @ 0x081F5CC9
	playse SE_SLIDING_DOOR
	removeobject LOCALID_FALLARBOR_LANETTE
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_LanetteGreeting: @ 0x081F5CEC
	.string "あなたは⋯⋯？\p"
	.string "{PLAYER}{KUN}　というのですか\n"
	.string "あなた　トレーナー　なんですね\p"
	.string "ということは　あたしの　つくった\n"
	.string "あずかりシステム　つかってますね？\p"
	.string "だって　つかいたいから\n"
	.string "パソコンの　まえに　いる　あたしに\l"
	.string "はなしかけてきた　という　わけですよね\l"
	.string "かんたんな　すいり　です\p"
	.string "あっ　あたし　マユミ　といいます\p"
	.string "あずかりシステムを　つかっている\n"
	.string "トレーナーに　あえて　すごく　うれしいです\p"
	.string "よかったら　あたしの　いえにも\n"
	.string "あそびに　きてください\l"
	.string "114ばんどうろに　ありますから$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown: @ 0x081F5DD8
	.string "おおむかしの　ポケモンって\n"
	.string "どんな　すがた　だったのかしら？\p"
	.string "この　まちの　はずれにいる\n"
	.string "かせきマニアなら　おしえてくれるかも$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees: @ 0x081F5E18
	.string "この　ハジツゲの　はたけ　ではな\n"
	.string "かざんばいの　なかでも　そだつような\l"
	.string "じょうぶな　きの　なえを　うえてるんじゃ$"
