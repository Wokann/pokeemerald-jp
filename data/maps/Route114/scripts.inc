@ Route114 scripts (JP map g0 m29 @ 0x081EB474)

Route114_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route114_OnFrame
	.byte 0

Route114_OnTransition::
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 0x1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH, 0x08244745
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH, 0x08244745
	end

Route114_OnLoad::
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH, 0x0824433D
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH, 0x08244350
	end

Route114_OnFrame::
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 0x1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route114_EventScript_Man::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_ROUTE_114_RECEIVED_BERRY, Route114_EventScript_ReceivedBerry
	msgbox 0x08263908, MSGBOX_DEFAULT
	random 0x5
	addvar VAR_RESULT, 0xF
	addvar VAR_RESULT, 0x85
	setorcopyvar VAR_0x8000, 0x800D
	setorcopyvar VAR_0x8001, 0x1
	callstd 0x0
	goto_if_eq VAR_RESULT, 0x0, 0x082430E0
	setflag FLAG_DAILY_ROUTE_114_RECEIVED_BERRY
	msgbox 0x0826393D, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_ReceivedBerry::
	msgbox 0x08263958, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_RoarGentleman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_ROAR, Route114_EventScript_ReceivedRoar
	msgbox Route114_Text_AllMyMonDoesIsRoarTakeThis, MSGBOX_DEFAULT
	setorcopyvar VAR_0x8000, ITEM_TM05
	setorcopyvar VAR_0x8001, 0x1
	callstd 0x0
	goto_if_eq VAR_RESULT, 0x0, 0x082430E0
	setflag FLAG_RECEIVED_TM_ROAR
	msgbox Route114_Text_ExplainRoar, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_ReceivedRoar::
	msgbox Route114_Text_ExplainRoar, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_Poochyena::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POOCHYENA, 0x2
	msgbox Route114_Text_Poochyena, MSGBOX_DEFAULT
	waitdooranim
	release
	end

Route114_EventScript_MeteorFallsSign::
	msgbox Route114_Text_MeteorFallsSign, MSGBOX_SIGN
	end

Route114_EventScript_FossilManiacsHouseSign::
	msgbox Route114_Text_FossilManiacsHouseSign, MSGBOX_SIGN
	end

Route114_EventScript_LanettesHouseSign::
	msgbox Route114_Text_LanettesHouse, MSGBOX_SIGN
	end

Route114_EventScript_Lenny::
	trainerbattle_single TRAINER_LENNY, Route114_Text_LennyIntro, Route114_Text_LennyDefeat
	msgbox Route114_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Lucas::
	trainerbattle_single TRAINER_LUCAS_1, Route114_Text_LucasIntro, Route114_Text_LucasDefeat
	msgbox Route114_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Shane::
	trainerbattle_single TRAINER_SHANE, Route114_Text_ShaneIntro, Route114_Text_ShaneDefeat
	msgbox Route114_Text_ShanePostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Nancy::
	trainerbattle_single TRAINER_NANCY, Route114_Text_NancyIntro, Route114_Text_NancyDefeat
	msgbox Route114_Text_NancyPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Steve::
	trainerbattle_single TRAINER_STEVE_1, Route114_Text_SteveIntro, Route114_Text_SteveDefeat, Route114_EventScript_RegisterSteve
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route114_EventScript_RematchSteve
	msgbox Route114_Text_StevePostBattle, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_RegisterSteve::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route114_Text_SteveRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_STEVE_1
	release
	end

Route114_EventScript_RematchSteve::
	trainerbattle_rematch TRAINER_STEVE_1, Route114_Text_SteveRematchIntro, Route114_Text_SteveRematchDefeat
	msgbox Route114_Text_StevePostRematch, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Bernie::
	trainerbattle_single TRAINER_BERNIE_1, Route114_Text_BernieIntro, Route114_Text_BernieDefeat, Route114_EventScript_RegisterBernie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route114_EventScript_RematchBernie
	msgbox Route114_Text_BerniePostBattle, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_RegisterBernie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route114_Text_BernieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BERNIE_1
	release
	end

Route114_EventScript_RematchBernie::
	trainerbattle_rematch TRAINER_BERNIE_1, Route114_Text_BernieRematchIntro, Route114_Text_BernieRematchDefeat
	msgbox Route114_Text_BerniePostRematch, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Claude::
	trainerbattle_single TRAINER_CLAUDE, Route114_Text_ClaudeIntro, Route114_Text_ClaudeDefeat
	msgbox Route114_Text_ClaudePostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Nolan::
	trainerbattle_single TRAINER_NOLAN, Route114_Text_NolanIntro, Route114_Text_NolanDefeat
	msgbox Route114_Text_NolanPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Tyra::
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_TyraIntro, Route114_Text_TyraDefeat, Route114_Text_TyraNotEnoughMons
	msgbox Route114_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Ivy::
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_IvyIntro, Route114_Text_IvyDefeat, Route114_Text_IvyNotEnoughMons
	msgbox Route114_Text_IvyPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Angelina::
	trainerbattle_single TRAINER_ANGELINA, Route114_Text_AngelinaIntro, Route114_Text_AngelinaDefeat
	msgbox Route114_Text_AngelinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Charlotte::
	trainerbattle_single TRAINER_CHARLOTTE, Route114_Text_CharlotteIntro, Route114_Text_CharlotteDefeat
	msgbox Route114_Text_CharlottePostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Kai::
	trainerbattle_single TRAINER_KAI, Route114_Text_KaiIntro, Route114_Text_KaiDefeat
	msgbox Route114_Text_KaiPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_Text_AllMyMonDoesIsRoarTakeThis: @ 0x081EB74E
	.string "わたしの　ポケモン　ほえてばかりで\n"
	.string "みんなが　にげてしまって⋯⋯\p"
	.string "あなた　よかったら\n"
	.string "この　わざマシン　もらってください$"

Route114_Text_ExplainRoar: @ 0x081EB78B
	.string "わざマシン05の　なかみは　ほえる　です\n"
	.string "ほえると　ポケモンも　にげだすのです$"

Route114_Text_Poochyena: @ 0x081EB7B3
	.string "ばうっ！！　ばばうっ！！$"

Route114_Text_MeteorFallsSign: @ 0x081EB7C0
	.string "ここは　りゅうせいのたき\n"
	.string "とおりぬけると　カナズミシティ$"

Route114_Text_FossilManiacsHouseSign: @ 0x081EB7DD
	.string "‘かせきマニアの　いえ’\n"
	.string "めずらしい　かせき　ください！$"

Route114_Text_LanettesHouse: @ 0x081EB7FA
	.string "‘マユミの　いえ’$"
