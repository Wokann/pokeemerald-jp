@ EverGrandeCity_SidneysRoom scripts (JP map g16 m0 @ 0x082101E6)

EverGrandeCity_SidneysRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_SidneysRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_OnFrame
	.byte 0

EverGrandeCity_SidneysRoom_OnTransition:: @ 0x082101FB
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	setflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	end

EverGrandeCity_SidneysRoom_OnLoad:: @ 0x08210202
	call_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 1, EverGrandeCity_SidneysRoom_EventScript_CloseDoor
	end

EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom:: @ 0x08210217
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_SidneysRoom_EventScript_CloseDoor:: @ 0x0821021D
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_SidneysRoom_OnWarp:: @ 0x08210223
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth:: @ 0x0821022D
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_SidneysRoom_OnFrame:: @ 0x08210232
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor:: @ 0x0821023C
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

EverGrandeCity_SidneysRoom_EventScript_Sidney:: @ 0x08210249
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_Defeat
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
	end

EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech:: @ 0x08210270
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_EventScript_Defeated:: @ 0x0821027A
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_Text_IntroSpeech: @ 0x0821028C
	.string "ようこそ　チャレンジャー！\n"
	.string "おれは　してんのうの　カゲツ\p"
	.string "うーん　いい　かお　してるな\n"
	.string "なかなか　たのしませて　くれそうだぞ！\l"
	.string "いいぞ！　いい　かんじだぞ！\p"
	.string "よーし！　おれと　おまえ　とで\n"
	.string "ポケモン　リーグでしか　できない\l"
	.string "たたかいを　たのしむと　しようぜ！！$"

EverGrandeCity_SidneysRoom_Text_Defeat: @ 0x0821030F
	.string "おやおや　まけちまったよ\n"
	.string "まっ　たのしんだから　いいんだけどよ$"

EverGrandeCity_SidneysRoom_Text_PostBattleSpeech: @ 0x0821032F
	.string "まけた　おれから　ひとこと\p"
	.string "おまえなら　もっと　さきに　すすめるぜ\n"
	.string "さあ　つぎの　へやに　いって\l"
	.string "たたかいを　たのしんで　きなよ！$"
