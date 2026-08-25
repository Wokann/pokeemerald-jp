@ EverGrandeCity_PhoebesRoom scripts (JP map g16 m1 @ 0x08210371)

EverGrandeCity_PhoebesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_PhoebesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PhoebesRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_PhoebesRoom_OnFrame
	.byte 0

EverGrandeCity_PhoebesRoom_OnWarp:: @ 0x08210381
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth:: @ 0x0821038B
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_PhoebesRoom_OnFrame:: @ 0x08210390
	map_script_2 VAR_ELITE_4_STATE, 1, EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor:: @ 0x0821039A
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 2
	releaseall
	end

EverGrandeCity_PhoebesRoom_OnLoad:: @ 0x082103A7
	call_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 2, EverGrandeCity_PhoebesRoom_EventScript_CloseDoor
	end

EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom:: @ 0x082103BC
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_PhoebesRoom_EventScript_CloseDoor:: @ 0x082103C2
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_PhoebesRoom_EventScript_Phoebe:: @ 0x082103C8
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_PhoebesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PHOEBE, EverGrandeCity_PhoebesRoom_Text_Defeat
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end

EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech:: @ 0x082103EF
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_EventScript_Defeated:: @ 0x082103F9
	setflag FLAG_DEFEATED_ELITE_4_PHOEBE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_Text_IntroSpeech: @ 0x0821040B
	.string "アハハ！\p"
	.string "アタシ　してんのうの　フヨウ\p"
	.string "おくりびやまで　しゅぎょう　するうちに\n"
	.string "ゴーストタイプの　ポケモンと　きもちを\l"
	.string "かよわせる　ことが　できるように　なったの\p"
	.string "そう　アタシと　ポケモンの　きずな\n"
	.string "とっても　つよいんだ！\p"
	.string "そんな　アタシの　ポケモンたちに\n"
	.string "ダメージを　あたえる　ことが　できるか\l"
	.string "ためして　ごらんよ！$"

EverGrandeCity_PhoebesRoom_Text_Defeat: @ 0x082104AB
	.string "あーあ\n"
	.string "まけちゃった$"

EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech: @ 0x082104B6
	.string "あなたと　ポケモンとの　あいだにも\n"
	.string "たしかな　きずなが　あったのね\p"
	.string "それが　わからなかった\n"
	.string "アタシが　まけたのは　とうぜん\p"
	.string "ウン　あなたたちの　きずなが\n"
	.string "どこまで　つうじるか　みてみたいな\l"
	.string "つぎの　へやに　すすみなよ$"
