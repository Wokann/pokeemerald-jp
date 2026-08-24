@ MossdeepCity scripts (JP map g0 m6 @ 0x081E1565)

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe: @ 0x081E17BC
	.string "これ⋯⋯　ダイゴさんに　もらったけど\n"
	.string "なんだか　よく　わかんないや！\p"
	.string "おうじゃのしるし　って　いうらしいけど\n"
	.string "おまえ　ほしい？$"

MossdeepCity_Text_YouCanKeepIt: @ 0x081E17FC
	.string "これが　ほしいなんて\n"
	.string "おまえも　かわってるよな！\p"
	.string "やるけど　そのかわり\n"
	.string "ダイゴさんには　ないしょ　だぜ！$"

MossdeepCity_Text_StevensHouseOverThere: @ 0x081E1831
	.string "ダイゴさんの　いえなら　すぐそこだよ！$"

MossdeepCity_Text_WhatToDoWithWeirdRock: @ 0x081E1845
	.string "そうだろ！　へんてこな　いしを\n"
	.string "もらっても　こまっちゃうよな！$"

MossdeepCity_Text_WailmerWatching: @ 0x081E1865
	.string "この　トクサネの　しゅうへん　では\n"
	.string "やせいの　ホエルコが　けんぶつ　できるんだ\p"
	.string "そーいうのを　えーと⋯⋯\n"
	.string "なんて　いったっけ　かな⋯⋯\p"
	.string "ホエ　ホエ　ホエ⋯⋯\p"
	.string "ホエルコ　ウオッチング　だ！$"

MossdeepCity_Text_SpaceCenterReceivedLetter: @ 0x081E18C3
	.string "しまの　うちゅうセンター　では\n"
	.string "すんごい　ロケット　とばしとるけど⋯⋯\p"
	.string "さいきん　あそこに\n"
	.string "おかしなてがみ　が　とどいた　とかで\l"
	.string "ちょっとした　さわぎに　なっとるのよ$"

MossdeepCity_Text_SpaceCenterLaunchingRockets: @ 0x081E1917
	.string "しまの　うちゅうセンター　では\n"
	.string "すんごい　ロケット　とばしとるのよ！$"

MossdeepCity_Text_MossdeepTargetedByMagma: @ 0x081E193A
	.string "ふなのりの　なかまから　きいたんだけど\n"
	.string "ミナモに　すみついていた　アクアだん\l"
	.string "だれかが　やっつけたんだってな！\p"
	.string "でも　こっちの　トクサネは\n"
	.string "マグマだんに　ねらわれてるんだよ⋯⋯\p"
	.string "あいつらが　なにをするき　なのかは\n"
	.string "うちゅうセンターに　いけば　わかるさ$"

MossdeepCity_Text_FeelReliefOnLand: @ 0x081E19B8
	.string "おれは　ふなのり　だから\n"
	.string "やっぱり　うみのほうが　だいじさ！\p"
	.string "でも　ひさしぶりに　りくに　あがると\n"
	.string "やっぱり　ホッと　するんだよな！$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers: @ 0x081E19FB
	.string "せかいじゅうの　すべてが！\p"
	.string "このしま　みたいに　くさばなで\n"
	.string "いっぱいに　なれば　いいのにね！$"

MossdeepCity_Text_LifeNeedsSeaToLive: @ 0x081E1A2A
	.string "いのちの　みなもとは　うみから　うまれて\n"
	.string "りくに　あがって　きた\p"
	.string "やくめを　おえた　いのちは\n"
	.string "つち　となって　だいちに　かえって　いく\p"
	.string "そして　うみと　だいちは\n"
	.string "いつでも　つながって　いる⋯⋯\p"
	.string "そう　この　かいがんせんの　ようにな$"

MossdeepCity_Text_SurfExhilarating: @ 0x081E1A9E
	.string "ふねのたびも　いいけどな\p"
	.string "ポケモンと　ともに　なみのりで\n"
	.string "うみを　わたるのは　なんとも　いえない\l"
	.string "きもちよさが　あるよな⋯⋯\p"
	.string "そう　おもわないか？　わかものよ$"

MossdeepCity_Text_SpecialSpaceCenterRock: @ 0x081E1AEE
	.string "この　いわ　って\n"
	.string "うちゅうセンターの　みんなに　とって\l"
	.string "だいじな　いわ　なの\p"
	.string "ロケットが　ぶじに　とぶように　ねがって\n"
	.string "ここに　おいたんだって！\p"
	.string "あなたは　ねがいごとを　かなえたいとき\n"
	.string "どうするの？\l"
	.string "ながれぼしに　ねがうの？\p"
	.string "あたしなら　たんざくに\n"
	.string "おねがいごとを　かくかな　やっぱ！$"

MossdeepCity_Text_ItsAWhiteRock: @ 0x081E1B7D
	.string "しろい　いわ　だ！$"

MossdeepCity_Text_GymSign: @ 0x081E1B87
	.string "トクサネ　シティ　ポケモンジム\n"
	.string "リーダー　フウ　ラン\l"
	.string "しんぴの　コンビネーション！！$"

MossdeepCity_Text_CitySign: @ 0x081E1BB2
	.string "ここは　トクサネ　シティ\n"
	.string "‘ポケモンを　たいせつに！’が　あいことば$"

MossdeepCity_Text_SpaceCenterSign: @ 0x081E1BD5
	.string "‘トクサネ　うちゅうセンター’\n"
	.string "うちゅうに　いちばん　ちかい　ばしょ$"

MossdeepCity_Text_ScottSomethingWrongWithTown: @ 0x081E1BF8
	.string "エニシダ“{PLAYER}{KUN}　げんき？\n"
	.string "わたしは　げんきさ！\p"
	.string "トクサネシティの　ジムリーダーが\n"
	.string "かなり　つよいって　きいてね\l"
	.string "のぞいてみようと　きて　みたら\l"
	.string "まちの　ようすが　なんだか　ヘンなんだ\p"
	.string "よこくじょうが　どうした　とか\n"
	.string "うちゅうセンターが　どうした　とか⋯⋯\p"
	.string "わたしには　かんけい　なさそうだなあ$"

MossdeepCity_Text_SootopolisNewGymLeader: @ 0x081E1C8D
	.string "あー　あしもとが　じゃぶじゃぶして\n"
	.string "きもちが　いい⋯⋯\p"
	.string "そうだ！　じゃぶじゃぶ　といえば\n"
	.string "ルネシティ　だけど\p"
	.string "あそこの　ジム\n"
	.string "リーダーが　かわった　らしいね\p"
	.string "なんでも　ミクリさんの\n"
	.string "おししょうさん　だとか⋯⋯$"
