Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "リーダーが　ここでの　けんきゅうに\n"
	.string "きょうみを　もったらしくて\l"
	.string "おれらを　よこしたんだ！　ジャマするな！$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "くそー\n"
	.string "こどもに　まけた⋯⋯$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "リーダーは　なんでも　しっている⋯⋯\p"
	.string "しかし　なにを　かんがえて　いるのか\n"
	.string "したっぱの　おれらには　さっぱりだ$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "あら？\n"
	.string "どうして　ここに　こどもが　いるのかしら？$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "あらー\n"
	.string "まけちゃったー！？$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "あらら⋯⋯\n"
	.string "こどもに　まけたら　おこられちゃう⋯⋯\p"
	.string "ベッドで　ねてようかしら？$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "ぼくが　ベッドで　ねてる　あいだに\n"
	.string "みんな　2かいに　いっちゃったよ$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "{STR_VAR_1}　つよいんだね！\p"
	.string "ぼくも　{STR_VAR_1}　みたいな\n"
	.string "ポケモントレーナーに　なりたいや！$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "はかせは　あめが　だいすき　なのです\p"
	.string "ですが　あめが　ふりつづくと\n"
	.string "こまってしまう　ひとも　いるわけです\p"
	.string "そこで　はかせは\n"
	.string "この　あめを　なにかに　つかえないか\l"
	.string "けんきゅう　なさっているのです$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "この　けんきゅうじょの　2かいでは\n"
	.string "ホウエンちほうの　てんきの\l"
	.string "うつりかわりを　しらべています\p"
	.string "さいきん　また　あちこちで\n"
	.string "いちじてきな　ひでりや　おおあめが\l"
	.string "かんそく　されている　ようですが⋯⋯$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "やあ！\n"
	.string "あなたの　おかげで　たすかりましたよ！\l"
	.string "それにしても⋯⋯\p"
	.string "アクアだんの　れんちゅうは\n"
	.string "なにを　するつもり　だったのでしょう？$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "ベッドが　ある⋯⋯\n"
	.string "やすんでいこう$"
