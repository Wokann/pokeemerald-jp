@ Route116 scripts (JP map g0 m31 @ 0x081EBAB5)

Route116_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route116_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_OnFrame
	.byte 0

Route116_OnTransition::
	call_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_SetWandasBoyfriendPos
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 0x1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, 0x08244745
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, 0x08244745
	end

Route116_EventScript_SetWandasBoyfriendPos::
	setobjectxyperm LOCALID_ROUTE116_WANDAS_BF, 0x26, 0xA
	return

Route116_OnLoad::
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, 0x08244389
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, 0x0824439C
	end

Route116_OnFrame::
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 0x1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route116_EventScript_WandasBoyfriend::
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_BoyfriendGruntLeftTunnel::
	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_BoyfriendGruntInTunnel::
	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_DevonEmployee::
	lock
	faceplayer
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveRepeatBallAgain
	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
	goto Route116_EventScript_GiveRepeatBall
	end

Route116_EventScript_GiveRepeatBall::
	setflag FLAG_MET_DEVON_EMPLOYEE
	setorcopyvar VAR_0x8000, ITEM_REPEAT_BALL
	setorcopyvar VAR_0x8001, 0x1
	callstd 0x0
	goto_if_eq VAR_RESULT, 0x0, Route116_EventScript_NoRoomForRepeatBall
	msgbox Route116_Text_NewBallAvailableAtMart, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, 0x2, Route116_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, 0x1, Route116_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, 0x3, Route116_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, 0x4, Route116_EventScript_DevonEmployeeExitEast
	removeobject VAR_LAST_TALKED
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setflag FLAG_RECEIVED_REPEAT_BALL
	release
	end

Route116_EventScript_DevonEmployeeExit::
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
	waitmovement 0x0
	return

Route116_EventScript_DevonEmployeeExitEast::
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
	waitmovement 0x0
	return

Route116_EventScript_TryGiveRepeatBallAgain::
	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
	goto Route116_EventScript_GiveRepeatBall
	end

Route116_EventScript_NoRoomForRepeatBall::
	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
	release
	end

Route116_Movement_DevonEmployeeExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_Movement_DevonEmployeeExitEast:
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

Route116_EventScript_RouteSignRustboro::
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route116_EventScript_RusturfTunnelSign::
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

Route116_EventScript_TunnelersRestHouseSign::
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
	end

Route116_EventScript_TrainerTipsBToStopEvolution::
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
	end

Route116_EventScript_TrainerTipsBagHasPockets::
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
	end

Route116_EventScript_Briney::
	lock
	faceplayer
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	setvar VAR_ROUTE116_STATE, 0x2
	release
	end

Route116_EventScript_BrineyTrigger::
	lockall
	applymovement LOCALID_ROUTE116_BRINEY, 0x0824362B
	applymovement LOCALID_PLAYER, 0x08243627
	waitmovement 0x0
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	setvar VAR_ROUTE116_STATE, 0x2
	releaseall
	end

Route116_EventScript_GlassesMan::
	lock
	faceplayer
	checkitem 0xCE, 0x1
	goto_if_eq VAR_RESULT, 0x1, Route116_EventScript_PlayerHasGlasses
	specialvar VAR_RESULT, FoundBlackGlasses
	goto_if_eq VAR_RESULT, 0x1, Route116_EventScript_FoundGlassesNotOnPlayer
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_FoundGlassesNotOnPlayer::
	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_GlassesManExit
	end

Route116_EventScript_PlayerHasGlasses::
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
	specialvar VAR_RESULT, FoundBlackGlasses
	goto_if_eq VAR_RESULT, 0x1, Route116_EventScript_FoundGlassesOnPlayer
	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_FoundGlassesOnPlayer::
	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_GlassesManExit
	end

Route116_EventScript_GlassesManExit::
	delay 0x14
	call_if_eq VAR_FACING, 0x2, Route116_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, 0x1, Route116_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, 0x3, Route116_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, 0x4, Route116_EventScript_GlassesManExitEast
	removeobject VAR_LAST_TALKED
	release
	end

Route116_EventScript_GlassesManExitNormal::
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
	waitmovement 0x0
	return

Route116_EventScript_GlassesManExitEast::
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
	waitmovement 0x0
	return

Route116_Movement_GlassesManExit:
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

Route116_Movement_GlassesManExitEast:
	walk_up
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

Route116_EventScript_Joey::
	trainerbattle_single TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_JerryIntro, Route116_Text_JerryDefeat, Route116_EventScript_TryRegisterJerryAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchJerry
	setvar VAR_0x8004, TRAINER_JERRY_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, 0x0, Route116_EventScript_TryRegisterJerry
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_TryRegisterJerryAfterBattle::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerryAfterBattle
	release
	end

Route116_EventScript_RegisterJerryAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route116_Text_JerryRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JERRY_1
	release
	end

Route116_EventScript_TryRegisterJerry::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerry
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_RegisterJerry::
	msgbox Route116_Text_JerryRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JERRY_1
	release
	end

Route116_EventScript_RematchJerry::
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Clark::
	trainerbattle_single TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Janice::
	trainerbattle_single TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Karen::
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_KarenIntro, Route116_Text_KarenDefeat, Route116_EventScript_TryRegisterKarenAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchKaren
	setvar VAR_0x8004, TRAINER_KAREN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, 0x0, Route116_EventScript_TryRegisterKaren
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_TryRegisterKarenAfterBattle::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKarenAfterBattle
	release
	end

Route116_EventScript_RegisterKarenAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route116_Text_KarenRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route116_EventScript_TryRegisterKaren::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKaren
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_RegisterKaren::
	msgbox Route116_Text_KarenRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route116_EventScript_RematchKaren::
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Sarah::
	trainerbattle_single TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Dawson::
	trainerbattle_single TRAINER_DAWSON, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Devan::
	trainerbattle_single TRAINER_DEVAN, Route116_Text_DevanIntro, Route116_Text_DevanDefeat
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Johnson::
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_Text_ScoundrelMadeOffWithPeeko: @ 0x081EBF46
	.string "あああ　なんという　ことだ！\p"
	.string "ピーコちゃんと　さんぽを　していたら\n"
	.string "いきなり　おかしな　やつが　やってきて\p"
	.string "わしの　かわいい　ピーコちゃんが\n"
	.string "うばわれて　しまったのじゃ！\p"
	.string "うおー！　ピーコちゃーん！$"

Route116_Text_WantToDigTunnel: @ 0x081EBFAA
	.string "ぬぉー！！\p"
	.string "トンネル　ほりてー！！$"

Route116_Text_DiggingTunnelWhenGoonOrderedMeOut: @ 0x081EBFBC
	.string "ぬぉー！！\n"
	.string "なんて　ことだ！？\p"
	.string "どうぐも　なにも　つかわずに\n"
	.string "トンネルを　ほっていたのに\l"
	.string "へんな　おとこに　おいだされた！\p"
	.string "あの　トンネルには\n"
	.string "おおきな　ものおとに　はんのう　して\l"
	.string "さわぎだす　ポケモンが　いる\p"
	.string "だから　きかいを　つかっての\n"
	.string "かいはつ　こうじを　やめたのに⋯⋯\p"
	.string "へんに　さわぎを　おこされると\n"
	.string "ポケモンが　おびえないか　しんぱいだ！$"

Route116_Text_GoonHightailedItOutOfTunnel: @ 0x081EC06B
	.string "ぬぉー！！\p"
	.string "へんな　おとこが　とびだしていった！\n"
	.string "これで　トンネルを　ほれるよ！$"

Route116_Text_ThankYouTokenOfAppreciation: @ 0x081EC094
	.string "ああっ！\n"
	.string "きみは！！\p"
	.string "トウカのもりで　たすけてくれた　だけでなく\n"
	.string "ぬすまれた　にもつを　とりかえし\l"
	.string "はたまた　カイナへの　とどけものを\l"
	.string "こころよく　ひきうけてくれた　ひと！！\p"
	.string "クスノキかんちょう　から\n"
	.string "‘にもつが　とどいた’と\l"
	.string "れんらくが　ありましたよ！\p"
	.string "どうも　ありがとう　なのです！\n"
	.string "かんしゃ　かんげき　あめ　あられ　なのです\p"
	.string "そんな　すてきな　トレーナーさんに\n"
	.string "グッド　ニュース！\p"
	.string "さいきん　わがしゃ　では\n"
	.string "あたらしい　モンスターボールの\l"
	.string "かいはつに　せいこう　したのです！\p"
	.string "かんしゃの　きもちとして\n"
	.string "トレーナーさんにも　プレゼント　なのよね！$"

Route116_Text_NewBallAvailableAtMart: @ 0x081EC1A8
	.string "あたらしい　モンスターボールは\n"
	.string "カナズミの　フレンドリィ　ショップで\l"
	.string "うってますからね！\p"
	.string "ぜひ　つかって　みてください！\n"
	.string "ではでは⋯⋯$"

Route116_Text_BagIsJamPacked: @ 0x081EC1EC
	.string "どうぐ　いっぱいで\n"
	.string "リピートボール　あげられないね$"

Route116_Text_TokenOfAppreciation: @ 0x081EC206
	.string "にもつを　とどけてくれた　ことへの\n"
	.string "かんしゃの　きもちとして\l"
	.string "トレーナーさん　にも　あたらしい\l"
	.string "モンスターボールを　プレゼント　なのよね！$"

Route116_Text_CanYouHelpMeFindGlasses: @ 0x081EC24C
	.string "メガネを　おとしたんだ⋯⋯\n"
	.string "きみも　さがすの　てつだってよ$"

Route116_Text_MayISeeThoseGlasses: @ 0x081EC26A
	.string "その　メガネ⋯⋯？\n"
	.string "ちょっと　みせてよ！$"

Route116_Text_NotWhatImLookingForMaybeTheyArentHere: @ 0x081EC27F
	.string "うーむ⋯⋯\n"
	.string "これは　くろいメガネ　だね\l"
	.string "ぼくが　さがしているのと　ちがうなあ⋯⋯\p"
	.string "ここには　ぼくの　メガネ　ないのかなあ$"

Route116_Text_CantFindGlassesNotHere: @ 0x081EC2BC
	.string "うーむ⋯⋯\n"
	.string "どうにも　メガネが　みつからないんだ\l"
	.string "ここには　ぼくの　メガネ　ないのかなあ$"

Route116_Text_NotWhatImLookingFor: @ 0x081EC2E9
	.string "うーむ⋯⋯\n"
	.string "これは　くろいメガネ　だね\l"
	.string "ぼくが　さがしているのと　ちがうなあ⋯⋯$"

Route116_Text_RouteSignRustboro: @ 0x081EC312
	.string "ここは　116ばん　どうろ\n"
	.string "{ESCAPE 0x02}　カナズミシティ$"

Route116_Text_RusturfTunnelSign: @ 0x081EC32C
	.string "カナズミと　シダケを　むすぶ\n"
	.string "‘カナシダ　トンネル’\p"
	.string "かいつう　こうじは　ちゅうしに　なりました$"

Route116_Text_TunnelersRestHouse: @ 0x081EC35D
	.string "トンネルこうじ　さぎょういん　つめしょ$"

Route116_Text_TrainerTipsBToStopEvolution: @ 0x081EC371
	.string "おとくな　けいじばん！\p"
	.string "ポケモンが　しんか　しそうなとき\n"
	.string "Bボタンを　おすと\l"
	.string "びっくりして　しんかを　やめます！\p"
	.string "これを　しんかキャンセルと　いいます$"

Route116_Text_TrainerTipsBagHasPockets: @ 0x081EC3BD
	.string "おとくな　けいじばん！！\p"
	.string "バッグには　いくつかの　ポケットが　あり\n"
	.string "いれる　どうぐの　しゅるい　によって\l"
	.string "それぞれの　ポケットに\l"
	.string "オートで　ぶんるい　されます\p"
	.string "まさに　トレーナーの　ひつじゅひん　です！$"
