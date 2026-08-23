@ Route118 scripts (JP map g0 m33 @ 0x081EC7E9)

Route118_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
	.byte 0

Route118_OnTransition::
	call 0x082540DF
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 0x1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, 0x08244745
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, 0x08244745
	end

Route118_OnLoad::
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, 0x082443AF
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, 0x082443C2
	end

Route118_OnFrame::
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 0x1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route118_EventScript_GoodRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route118_EventScript_ReceivedGoodRod
	msgbox Route118_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0x1, Route118_EventScript_ReceiveGoodRod
	goto_if_eq VAR_RESULT, 0x0, Route118_EventScript_DeclineGoodRod
	end

Route118_EventScript_ReceiveGoodRod::
	msgbox Route118_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
	setorcopyvar VAR_0x8000, ITEM_GOOD_ROD
	setorcopyvar VAR_0x8001, 0x1
	callstd 0x0
	setflag FLAG_RECEIVED_GOOD_ROD
	msgbox Route118_Text_TryYourLuckFishing, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_DeclineGoodRod::
	msgbox Route118_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_ReceivedGoodRod::
	msgbox Route118_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_Girl::
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
	end

Route118_EventScript_RouteSignMauville::
	msgbox Route118_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route118_EventScript_RouteSign119::
	msgbox Route118_Text_RouteSign119, MSGBOX_SIGN
	end

Route118_EventScript_StevenTrigger0::
	lockall
	setvar VAR_0x8008, 0x0
	applymovement LOCALID_PLAYER, 0x08243635
	waitmovement 0x0
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenApproachLedge0
	waitmovement 0x0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger1::
	lockall
	setvar VAR_0x8008, 0x1
	applymovement LOCALID_PLAYER, 0x08243635
	waitmovement 0x0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger2::
	lockall
	setvar VAR_0x8008, 0x2
	applymovement LOCALID_PLAYER, 0x08243635
	waitmovement 0x0
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenApproachLedge2
	waitmovement 0x0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger::
	playse SE_LEDGE
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenJumpLedge
	waitmovement 0x0
	delay 0x1E
	msgbox Route118_Text_StevenQuestions, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0x0, Route118_EventScript_StevenExit0
	call_if_eq VAR_0x8008, 0x1, Route118_EventScript_StevenExit1
	call_if_eq VAR_0x8008, 0x2, Route118_EventScript_StevenExit2
	setvar VAR_ROUTE118_STATE, 0x1
	removeobject LOCALID_ROUTE118_STEVEN
	releaseall
	end

Route118_EventScript_StevenExit0::
	applymovement LOCALID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenExit0
	waitmovement 0x0
	return

Route118_EventScript_StevenExit1::
	applymovement LOCALID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenExit1
	waitmovement 0x0
	return

Route118_EventScript_StevenExit2::
	applymovement LOCALID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenExit2
	waitmovement 0x0
	return

Route118_Movement_PlayerWatchStevenExit:
	delay_16
	walk_in_place_faster_right
	step_end

Route118_Movement_StevenApproachLedge0:
	walk_left
	step_end

Route118_Movement_StevenApproachLedge2:
	walk_right
	step_end

Route118_Movement_StevenJumpLedge:
	jump_2_down
	delay_16
	walk_down
	step_end

Route118_Movement_StevenExit0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_Movement_StevenExit1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_Movement_StevenExit2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_EventScript_Rose::
	trainerbattle_single TRAINER_ROSE_1, Route118_Text_RoseIntro, Route118_Text_RoseDefeat, Route118_EventScript_RegisterRose
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route118_EventScript_RematchRose
	msgbox Route118_Text_RosePostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_RegisterRose::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route118_Text_RoseRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ROSE_1
	release
	end

Route118_EventScript_RematchRose::
	trainerbattle_rematch TRAINER_ROSE_1, Route118_Text_RoseRematchIntro, Route118_Text_RoseRematchDefeat
	msgbox Route118_Text_RosePostRematch, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Barny::
	trainerbattle_single TRAINER_BARNY, Route118_Text_BarnyIntro, Route118_Text_BarnyDefeat
	msgbox Route118_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Wade::
	trainerbattle_single TRAINER_WADE, Route118_Text_WadeIntro, Route118_Text_WadeDefeat
	msgbox Route118_Text_WadePostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Dalton::
	trainerbattle_single TRAINER_DALTON_1, Route118_Text_DaltonIntro, Route118_Text_DaltonDefeat, Route118_EventScript_RegisterDalton
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route118_EventScript_RematchDalton
	msgbox Route118_Text_DaltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_RegisterDalton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route118_Text_DaltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DALTON_1
	release
	end

Route118_EventScript_RematchDalton::
	trainerbattle_rematch TRAINER_DALTON_1, Route118_Text_DaltonRematchIntro, Route118_Text_DaltonRematchDefeat
	msgbox Route118_Text_DaltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Perry::
	trainerbattle_single TRAINER_PERRY, Route118_Text_PerryIntro, Route118_Text_PerryDefeat
	msgbox Route118_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Chester::
	trainerbattle_single TRAINER_CHESTER, Route118_Text_ChesterIntro, Route118_Text_ChesterDefeat
	msgbox Route118_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Deandre::
	trainerbattle_single TRAINER_DEANDRE, Route118_Text_DeandreIntro, Route118_Text_DeandreDefeat
	msgbox Route118_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
	end

Route118_Text_StevenQuestions: @ 0x081ECAEB
	.string "ダイゴ“やあ　{STRING 0x01}{STRING 0x05}！\p"
	.string "ムロタウンの　どうくつで　あった\n"
	.string "ダイゴだよ！\p"
	.string "あれから　きみは　どれだけ\n"
	.string "たくさんの　ポケモンに　であったかな？\p"
	.string "この　ひろい　せかいには\n"
	.string "さまざまな　ポケモンが　いるんだ\p"
	.string "すきな　タイプの　ポケモン　ばかりを\n"
	.string "そだてるのも　いいだろう\p"
	.string "あるいは　いろんな　タイプの　ポケモンを\n"
	.string "そだてるのも　たのしい　だろう⋯⋯\p"
	.string "きみは　ポケモン　トレーナーとして\n"
	.string "どう　かんがえてる？\p"
	.string "ボクが　きにする　ことじゃない　けどね\p"
	.string "じゃあ\n"
	.string "また　あえると　いいね$"

Route118_Text_YouAgreeGoodRodIsGood: @ 0x081ECBD8
	.string "うむ！\n"
	.string "いいつりざおは　ほんとうに　いいよ！\p"
	.string "きみも　そう　おもうでしょ？$"

Route118_Text_IdenticalMindsTakeThis: @ 0x081ECBFE
	.string "うむ！\n"
	.string "きみとは　きが　あうよ！\p"
	.string "うむ！\n"
	.string "いいつりざおを　あげよう！$"

Route118_Text_TryYourLuckFishing: @ 0x081ECC21
	.string "みずの　ある　ところなら\n"
	.string "どこでも　つりを　すると　いいよ！$"

Route118_Text_DontYouLikeToFish: @ 0x081ECC40
	.string "つりは　きらい　かい？$"

Route118_Text_TryCatchingMonWithGoodRod: @ 0x081ECC4C
	.string "いいつりざおで\n"
	.string "いろんな　ポケモンを　つると　いいよ！$"

Route118_Text_CanCrossRiversWithSurf: @ 0x081ECC68
	.string "ふねを　もって　いなくても\n"
	.string "なみのりを　おぼえた　ポケモンが　いれば\l"
	.string "うみや　かわを　わたって　いけちゃうの！\p"
	.string "ポケモンって　たのもしーい！$"

Route118_Text_RouteSignMauville: @ 0x081ECCAF
	.string "ここは　118ばん　どうろ\n"
	.string "{ESCAPE 0x02}　キンセツシティ$"

Route118_Text_RouteSign119: @ 0x081ECCC9
	.string "ここは　118ばん　どうろ\n"
	.string "{ESCAPE 0x00}　119ばん　どうろ$"
