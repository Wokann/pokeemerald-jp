@ EverGrandeCity_PokemonCenter_1F scripts (JP map g16 m12 @ 0x082113FC)

EverGrandeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonCenter_1F_OnTransition:: @ 0x08211407
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY
	call_if_unset FLAG_MET_SCOTT_IN_EVERGRANDE, EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott
	end

EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott:: @ 0x08211414
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	return

EverGrandeCity_PokemonCenter_1F_EventScript_Nurse:: @ 0x08211421
	setvar VAR_0x800B, LOCALID_EVER_GRANDE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Woman:: @ 0x0821142F
	msgbox EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ExpertM:: @ 0x08211438
	msgbox EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Scott:: @ 0x08211441
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	call_if_eq VAR_FACING, DIR_WEST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	addvar VAR_SCOTT_STATE, 0x1
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	playse SE_EXIT
	waitse
	removeobject LOCALID_EVER_GRANDE_SCOTT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth:: @ 0x0821147E
	applymovement LOCALID_EVER_GRANDE_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit:: @ 0x08211489
	applymovement LOCALID_EVER_GRANDE_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExit
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Movement_ScottExit:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad: @ 0x082114A2
	.string "ポケモンリーグは\n"
	.string "チャンピオンロードを　ぬけると　すぐ！\p"
	.string "ここまで　きたら\n"
	.string "まえに　すすむしかないわ！$"

EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon: @ 0x082114D6
	.string "チャンピオンロードの\n"
	.string "ながくて　けわしい　みちのり⋯⋯\p"
	.string "まるで　いままで　あるいてきた　みちを\n"
	.string "おもいださせるかの　ようだな\p"
	.string "きみ　じぶんの　ポケモンを\n"
	.string "しんじて　がんばりたまえ！$"

EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou: @ 0x08211531
	.string "エニシダ“{PLAYER}{KUN}\n"
	.string "ついに　ポケモンリーグだね！\l"
	.string "わたしも　おうえん　した　かいがあったよ！\p"
	.string "もし　{PLAYER}{KUN}が\n"
	.string "ポケモンチャンピオンに　なったら⋯⋯\l"
	.string "そのときは　また　れんらく　するからね\p"
	.string "じゃ⋯⋯\n"
	.string "{PLAYER}{KUN}　がんばってね！$"
