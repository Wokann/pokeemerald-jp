@ EverGrandeCity_DrakesRoom scripts (JP map g16 m3 @ 0x082106BE)

EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

EverGrandeCity_DrakesRoom_OnWarp:: @ 0x082106CE
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth:: @ 0x082106D8
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:: @ 0x082106DD
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor:: @ 0x082106E7
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:: @ 0x082106F4
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom:: @ 0x08210709
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor:: @ 0x0821070F
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake:: @ 0x08210715
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech:: @ 0x0821073C
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated:: @ 0x08210746
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech: @ 0x08210760
	.string "わしが　ポケモン　リーグ\n"
	.string "してんのう　さいごの　ひとり\l"
	.string "ドラゴンつかいの　ゲンジ！\p"
	.string "ポケモンは　もともと\n"
	.string "じゆうきままな　やせいの　いきもの\p"
	.string "ときとして　ひとを　こまらせ\n"
	.string "ときとして　ひとを　たすける\p"
	.string "そんな　ポケモンと　いっしょに　たたかうのに\n"
	.string "なにが　ひつようか\l"
	.string "おまえ　わかって　いるのか？\p"
	.string "わかって　いなければ\n"
	.string "この　わしに　かつことなど　できまい！$"

EverGrandeCity_DrakesRoom_Text_Defeat: @ 0x08210814
	.string "みごと！　というべきだな！$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech: @ 0x08210822
	.string "さすがは　ここまで\n"
	.string "やってきた　ポケモン　トレーナー\l"
	.string "ひつような　もの　わかっている　ようだな\p"
	.string "そう！　トレーナーに\n"
	.string "ひつよう　なのは　ただしい　こころ！\p"
	.string "ポケモンは　トレーナーの\n"
	.string "ただしい　こころに　ふれて\l"
	.string "ものごとの　ぜんあくを　はんだんし\l"
	.string "ただしい　こころに　ふれて　つよくなる！\p"
	.string "さあ　つぎに　すすめ！\n"
	.string "チャンピオンが　まって　おるぞ！！$"
