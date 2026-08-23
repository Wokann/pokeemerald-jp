@ Route119 scripts (JP map g0 m34 @ 0x081ECCE5)

Route119_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

Route119_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
	end

Route119_EventScript_TryRemoveKecleon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, 0x08244178
	removeobject VAR_LAST_TALKED
	return

Route119_OnTransition::
	call 0x08242F63
	call 0x08242F87
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0x1, Route119_EventScript_MoveInstituteWorkersDownstairs
	special SetRoute119Weather
	end

Route119_EventScript_MoveInstituteWorkersDownstairs::
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	setvar VAR_WEATHER_INSTITUTE_STATE, 0x2
	return

Route119_EventScript_RivalTrigger1::
	setvar VAR_TEMP_1, 0x1
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalTrigger2::
	setvar VAR_TEMP_1, 0x2
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalEncounter::
	lockall
	addobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route119_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route119_EventScript_PlayBrendanMusic
	delay 0x41
	call_if_eq VAR_TEMP_1, 0x1, Route119_EventScript_RivalEnter1
	call_if_eq VAR_TEMP_1, 0x2, Route119_EventScript_RivalEnter2
	applymovement LOCALID_PLAYER, 0x0824362D
	waitmovement 0x0
	delay 0x1E
	call_if_eq VAR_TEMP_1, 0x1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 0x2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	addobject LOCALID_ROUTE119_RIVAL
	delay 0x1E
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route119_EventScript_BattleMay
	goto_if_eq VAR_RESULT, FEMALE, Route119_EventScript_BattleBrendan
	releaseall
	end

Route119_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route119_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route119_EventScript_BattleMay::
	msgbox Route119_Text_MayIntro, MSGBOX_DEFAULT
	copyvar VAR_0x8000, VAR_STARTER_MON
	goto_if_eq VAR_0x8000, 0x0, Route119_EventScript_BattleMayTreecko
	goto_if_eq VAR_0x8000, 0x1, Route119_EventScript_BattleMayTorchic
	goto_if_eq VAR_0x8000, 0x2, Route119_EventScript_BattleMayMudkip
	end

Route119_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_DefeatedMay::
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExitScottArrive
	end

Route119_EventScript_BattleBrendan::
	msgbox Route119_Text_BrendanIntro, MSGBOX_DEFAULT
	copyvar VAR_0x8000, VAR_STARTER_MON
	goto_if_eq VAR_0x8000, 0x0, Route119_EventScript_BattleBrendanTreecko
	goto_if_eq VAR_0x8000, 0x1, Route119_EventScript_BattleBrendanTorchic
	goto_if_eq VAR_0x8000, 0x2, Route119_EventScript_BattleBrendanMudkip
	end

Route119_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_DefeatedBrendan::
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExitScottArrive
	end

Route119_EventScript_GiveFlyHM::
	setorcopyvar VAR_0x8000, ITEM_HM02
	setorcopyvar VAR_0x8001, 0x1
	callstd 0x0
	setflag FLAG_RECEIVED_HM_FLY
	return

Route119_EventScript_RivalExitScottArrive::
	closemessage
	call_if_eq VAR_TEMP_1, 0x1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 0x2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_ROUTE119_RIVAL
	addobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	delay 0x1E
	call_if_eq VAR_TEMP_1, 0x1, Route119_EventScript_RivalExit1
	call_if_eq VAR_TEMP_1, 0x2, Route119_EventScript_RivalExit2
	removeobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	setvar VAR_ROUTE119_STATE, 0x1
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 0x3C
	call_if_eq VAR_TEMP_1, 0x1, Route119_EventScript_SetScottPos1
	call_if_eq VAR_TEMP_1, 0x2, Route119_EventScript_SetScottPos2
	addobject LOCALID_ROUTE119_SCOTT
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottEnter
	waitmovement 0x0
	addvar VAR_SCOTT_STATE, 0x1
	msgbox Route119_Text_ScottWayToGoBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 0x1, Route119_EventScript_ScottExit1
	call_if_eq VAR_TEMP_1, 0x2, Route119_EventScript_ScottExit2
	removeobject LOCALID_ROUTE119_SCOTT
	releaseall
	end

Route119_EventScript_SetScottPos1::
	setobjectxyperm LOCALID_ROUTE119_SCOTT, 0x1B, 0x19
	return

Route119_EventScript_SetScottPos2::
	setobjectxyperm LOCALID_ROUTE119_SCOTT, 0x1C, 0x19
	return

Route119_EventScript_ScottExit1::
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottExit1
	waitmovement 0x0
	return

Route119_EventScript_ScottExit2::
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottExit2
	waitmovement 0x0
	return

Route119_EventScript_RivalEnter1::
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalEnter1
	waitmovement 0x0
	return

Route119_EventScript_RivalEnter2::
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalEnter2
	waitmovement 0x0
	return

Route119_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, Route119_Movement_PlayerWatchRivalExit1
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalExit1
	waitmovement 0x0
	return

Route119_EventScript_RivalExit2::
	applymovement LOCALID_PLAYER, Route119_Movement_PlayerWatchRivalExit2
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalExit2
	waitmovement 0x0
	return

Route119_EventScript_SetRivalPos1::
	setobjectxyperm LOCALID_ROUTE119_RIVAL, 0x19, 0x20
	setobjectxyperm LOCALID_ROUTE119_RIVAL_ON_BIKE, 0x19, 0x20
	return

Route119_EventScript_SetRivalPos2::
	setobjectxyperm LOCALID_ROUTE119_RIVAL, 0x1A, 0x20
	setobjectxyperm LOCALID_ROUTE119_RIVAL_ON_BIKE, 0x1A, 0x20
	return

Route119_Movement_PlayerWatchRivalExit1:
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_PlayerWatchRivalExit2:
	delay_16
	walk_in_place_faster_left
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_RivalEnter1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalEnter2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalExit1:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_RivalExit2:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route119_Movement_ScottExit1:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_Movement_ScottExit2:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_EventScript_CyclingTriathleteM::
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
	end

Route119_EventScript_RouteSignFortree::
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
	end

Route119_EventScript_WeatherInstituteSign::
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
	end

Route119_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Taylor::
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Doug::
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Greg::
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Kent::
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Jackson::
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchJackson
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterJackson::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKSON_1
	release
	end

Route119_EventScript_RematchJackson::
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Catherine::
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchCatherine
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterCatherine::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CATHERINE_1
	release
	end

Route119_EventScript_RematchCatherine::
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hugh::
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Yasu::
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Takashi::
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hideo::
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Chris::
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Fabian::
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Dayton::
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Rachel::
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_BridgeAquaGrunt1::
	lock
	faceplayer
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, 0x08243625
	waitmovement 0x0
	release
	end

Route119_EventScript_BridgeAquaGrunt2::
	lock
	faceplayer
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, 0x08243625
	waitmovement 0x0
	release
	end

Route119_EventScript_Boy1::
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
	end

Route119_EventScript_Boy2::
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
	end

Route119_EventScript_TrainerTipsDecoration::
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
	end

Route119_EventScript_ScottWonAtFortreeGymCall:: @ 0x081ED2AD
Route119_EventScript_ScottWonAtFortreeGymCall::
	lockall
	pokenavcall Route119_Text_ScottYouWonAtFortreeGym
	waitmessage
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
	addvar VAR_SCOTT_STATE, 0x1
	releaseall
	end

Route119_Text_MayIntro: @ 0x081ED2BE
	.string "ハルカ“{STRING 0x01}{STRING 0x05}！\n"
	.string "どこに　いたのよ？　さがしたわ！\p"
	.string "どれくらい　つよく　なったのか\n"
	.string "ちょっと　ためして　あげる！\p"
	.string "ポケモンの　じゅんびは⋯⋯\n"
	.string "いいに　きまってるよね！　それっ！$"

Route119_Text_MayDefeat: @ 0x081ED318
	.string "あっちゃー！\n"
	.string "{STRING 0x01}{STRING 0x05}　つよい　じゃない！\p"
	.string "ポケモン　そだってなくて\n"
	.string "こまってるかも　って　しんぱい　してたのに$"

Route119_Text_MayPresentForYou: @ 0x081ED351
	.string "ハルカ“ぜんぜん　だいじょうぶ！\n"
	.string "その　ちょうしで　がんばってね！\p"
	.string "これは　あたし　からの　プレゼントよ！$"

Route119_Text_MayExplainFly: @ 0x081ED387
	.string "ハルカ“そらをとぶを　つかえば\n"
	.string "いちど　いった　まちなら　いっしゅんで\l"
	.string "とんでいく　ことが　できるの！\p"
	.string "でも　そらをとぶを　つかうには\n"
	.string "ヒワマキの　ジムバッジが　いるのよ\l"
	.string "これ　だいじだから　わすれないでね！\p"
	.string "たまには　そらをとぶで\n"
	.string "ミシロに　かえるのも　いいんじゃない？\p"
	.string "{STRING 0x01}{STRING 0x05}の　おかあさん\n"
	.string "しんぱい　してるかも　しれないし⋯⋯\p"
	.string "じゃあ\n"
	.string "また　どこかで　あおうね！$"

Route119_Text_BrendanIntro: @ 0x081ED441
	.string "ユウキ“{STRING 0x01}！\n"
	.string "ここで　ポケモン　さがしてたのか？\p"
	.string "どれくらい　つよく　なったか\n"
	.string "ためして　やるよ\p"
	.string "さあ！\n"
	.string "しょうぶ　しょうぶ　だぜ！$"

Route119_Text_BrendanDefeat: @ 0x081ED485
	.string "ふうん⋯⋯\n"
	.string "けっこう　つよく　なってるんだな$"

Route119_Text_BrendanIllGiveYouThis: @ 0x081ED49C
	.string "ユウキ“それなら　どこで　ポケモン\n"
	.string "さがしても　だいじょうぶ　だな\p"
	.string "これ　やるから　つかってみろよ！$"

Route119_Text_BrendanExplainFly: @ 0x081ED4CF
	.string "ユウキ“そらをとぶを　つかえば\n"
	.string "いちど　いった　まちなら\l"
	.string "いっしゅんで　とんでいける\p"
	.string "もっとも　ヒワマキの\n"
	.string "ジムバッジが　ひつよう　だけど⋯⋯\p"
	.string "じゃ　オレ　さきにいくよ$"

Route119_Text_ScottWayToGoBeSeeingYou: @ 0x081ED524
	.string "エニシダ“うふふ！\n"
	.string "やるねえ　{STRING 0x01}{STRING 0x05}⋯⋯！\p"
	.string "いま　じてんしゃに　のった　トレーナーと\n"
	.string "すれちがったん　だけどさ\l"
	.string "きみ　あのトレーナーに　かったんだろ？\l"
	.string "わかるよー！\p"
	.string "だって　あのコ　まっかな　かおして\n"
	.string "すっごく　くやしそう　だったからね！\p"
	.string "それにしても　きみとは\n"
	.string "いろいろな　ところで　あうね！\l"
	.string "この　あとは　ヒワマキジムに　いくのかな？\p"
	.string "ジムせんも　きたい　してるよ！\n"
	.string "じゃ　また　あおうね！$"

Route119_Text_ScottYouWonAtFortreeGym: @ 0x081ED5EB
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯　ピッ！\p"
	.string "エニシダ“やあどうも\n"
	.string "{STRING 0x01}{STRING 0x05}　わたしだよ！\p"
	.string "おもった　とおり！\n"
	.string "ヒワマキジム　でも　きみは　かったね！\p"
	.string "きみの　その　つよさ　もしかしたら⋯⋯\n"
	.string "わたしの　もとめている　トレーナーは\l"
	.string "ほんとうに　きみかも　しれないな！\p"
	.string "うん　きみのこと　これからも\n"
	.string "かげながら　おうえん　しているから！\l"
	.string "じゃ　がんばってよ！\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯　ツー$"

Route119_Text_StayAwayFromWeatherInstitute: @ 0x081ED6B1
	.string "オレたち　ここで　みはりを　しているのさ\p"
	.string "おい　おまえ！　あぶないから\n"
	.string "てんき　けんきゅうじょ　には　ちかづくなよ$"

Route119_Text_DontGoNearWeatherInstitute: @ 0x081ED6EB
	.string "みはりって　いがいと　ヒマだなあ⋯⋯\p"
	.string "おい　おまえ！　おねがいだから\n"
	.string "てんき　けんきゅうじょ　には　ちかづくなよ$"

Route119_Text_ThoughtFlyByCatchingBirdMons: @ 0x081ED724
	.string "とりポケモンを　たくさん　あつめて\n"
	.string "それに　つかまれば\l"
	.string "そらを　とべると　おもって　いたんだ\p"
	.string "そしたらさ　‘そらをとぶ’っていう\n"
	.string "ひでんわざが　あるんだってね！？\p"
	.string "もっと　はやく　しりたかったよ⋯⋯$"

Route119_Text_TallGrassSnaresBikeTires: @ 0x081ED788
	.string "まいったぜ⋯⋯\p"
	.string "ながい　くさが　タイヤに　からまるから\n"
	.string "じてんしゃに　のれないよ⋯⋯$"

Route119_Text_CanYourMonMakeSecretBase: @ 0x081ED7B3
	.string "きみの　ポケモン\n"
	.string "ひみつのちから　つかって\l"
	.string "おおきな　くさの　かたまりに\l"
	.string "ひみつきちを　つくれるかい？$"

Route119_Text_RouteSignFortree: @ 0x081ED7E7
	.string "ここは　119ばん　どうろ\n"
	.string "{ESCAPE 0x03}　ヒワマキシティ$"

Route119_Text_WeatherInstitute: @ 0x081ED801
	.string "‘てんき　けんきゅうじょ’$"

Route119_Text_TrainerTipsDecoration: @ 0x081ED80F
	.string "おとくな　けいじばん！！\p"
	.string "ひみつきち　には　グッズを\n"
	.string "16こ　まで　おけます！\p"
	.string "すきな　グッズを　えらんで\n"
	.string "あなただけの　おきにいりの\l"
	.string "ひみつきち　を　つくりましょう！$"
