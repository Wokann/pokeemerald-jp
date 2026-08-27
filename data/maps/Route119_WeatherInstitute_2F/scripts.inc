Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
	end

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 1, 6
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 4, 6
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 2, 2
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_ShellyDefeated::
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3
	applymovement LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
	applymovement LOCALID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SHELLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SHELLY, Common_Movement_Delay48
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_1
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_2
	removeobject LOCALID_WEATHER_INSTITUTE_2F_SHELLY
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_4
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3
	applymovement LOCALID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 25, ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end

Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM
	return

Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Both defeated
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_faster_down
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
	slide_down
	walk_in_place_faster_left
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_Text_Grunt2Intro:
	.string "この　けんきゅうじょで　うみだされた\n"
	.string "ポケモンは　てんきと　かんけいある　って\l"
	.string "きいたから　いただきに　きたのさ！$"

Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
	.string "こんな　こどもに　じゃま　されるのか！？$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
	.string "ここで　うみだされた　ポケモンが\n"
	.string "もし　てんきを　じゆうに　あやつれるなら\l"
	.string "ぜったい　アクアだんに　ひつよう　だぜ！$"

Route119_WeatherInstitute_2F_Text_Grunt3Intro:
	.string "おれたち　アクアだん！\n"
	.string "めずらしい　ものが　ある　ところなら\l"
	.string "どこにでも　あらわれる！$"

Route119_WeatherInstitute_2F_Text_Grunt3Defeat:
	.string "こいつは　まいった！$"

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle:
	.string "アクアだんの　りそうを　しらないくせに\n"
	.string "じゃま　するんじゃ　ないよ！$"

Route119_WeatherInstitute_2F_Text_Grunt5Intro:
	.string "あなたも　てんきに　かんけいのある\n"
	.string "ポケモンを　さがしに　きたの？\p"
	.string "だめよ！\n"
	.string "あたしたちが　さきに　いただくんだから！$"

Route119_WeatherInstitute_2F_Text_Grunt5Defeat:
	.string "んもー　ポケモンがー$"

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle:
	.string "ふん　いいさ！\p"
	.string "あたしたちが　ほんとうに　ほしいのは\n"
	.string "もっと　ほかに⋯⋯　イヒヒヒ$"

Route119_WeatherInstitute_2F_Text_ShellyIntro:
	.string "オーッホッホ！\p"
	.string "われわれ　アクアだんの\n"
	.string "じゃまを　しようと　いうの！？\p"
	.string "もう　こわいものしらず　といおうか\n"
	.string "ただの　おろかものと　いおうか⋯⋯\p"
	.string "かわいすぎて　にくらしく　なっちゃう！\n"
	.string "やっつけて　あげるわね！$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat:
	.string "オーッホッホ！\n"
	.string "つよくて　にくらしく　なっちゃうわ！$"

Route119_WeatherInstitute_2F_Text_ShellyPostBattle:
	.string "マグマだん　だけでも　めざわり　なのに\n"
	.string "あなた　どうして　わたしたちの　まわりを\l"
	.string "チョロチョロ　かぎまわって　いるの！$"

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
	.string "たいへんです！\p"
	.string "たったいま　マグマだんの　れんちゅうが\n"
	.string "てんきけんきゅうじょを　つうかして\l"
	.string "おくりびやま　ほうめんに\l"
	.string "むかって　いきました！$"

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
	.string "なんですって！\p"
	.string "えーい　こうしちゃ　いられない\n"
	.string "われわれも　おくりびやまに　いそぐわよ！\p"
	.string "オーッホッホ！\n"
	.string "マグマだんめ　まってなさーい！$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
	.string "ありがとうよ\n"
	.string "きみの　おかげで　たすかったよ\p"
	.string "おれいと　いっては　なんだが\n"
	.string "この　ポケモンを　もらって　おくれ$"

@ Unused
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon:
	.string "あら？　それいじょう\n"
	.string "ポケモンを　もてないようだよ$"

Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform:
	.string "{PLAYER}は\n"
	.string "ポワルンを　もらった！$"

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather:
	.string "そいつは　そのときの　てんきに　よって\n"
	.string "すがたを　かえる　ポケモン　なんだよ\p"
	.string "けんきゅうじょ　には　たくさん　いるから\n"
	.string "えんりょせずに　もらって　おくれよ$"

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
	.string "わたしも　ながい　あいだ\n"
	.string "あめの　けんきゅうを　してるが\l"
	.string "てんきを　じゆうじざいに　かえるだなんて\l"
	.string "にんげんには　むりな　はなし　だよ$"

Route119_WeatherInstitute_2F_Text_GroudonWeather:
	.string "わたしは　ホウエンちほうの　てんきを\n"
	.string "かんそく　しています\p"
	.string "げんざい　{STR_VAR_1}で\n"
	.string "ひでりが　はっせい　しています！\p"
	.string "ということは\n"
	.string "{STR_VAR_1}の　どこかに⋯⋯？$"

Route119_WeatherInstitute_2F_Text_KyogreWeather:
	.string "わたしは　ホウエンちほうの　てんきを\n"
	.string "かんそく　しています\p"
	.string "げんざい　{STR_VAR_1}で\n"
	.string "はげしい　おおあめが　ふっています！\p"
	.string "ということは\n"
	.string "{STR_VAR_1}の　どこかに⋯⋯？$"

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
	.string "いじょう　きしょうは\n"
	.string "もう　かんそく　されなく　なりました\p"
	.string "たまに　あめが　ふっても\n"
	.string "それは　めぐみのあめと　いえるでしょう！$"
