@ JaggedPass scripts (JP map g24 m13 @ 0x08215AF2)

JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:: @ 0x08215B02
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem:: @ 0x08215B10
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout:: @ 0x08215B21
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:: @ 0x08215B27
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh:: @ 0x08215B33
	setweather WEATHER_VOLCANIC_ASH
	resetweather
	return

JaggedPass_OnLoad:: @ 0x08215B38
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance:: @ 0x08215B44
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout:: @ 0x08215B57
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 16
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard:: @ 0x08215BB4
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated:: @ 0x08215C02
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric:: @ 0x08215C21
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana:: @ 0x08215C38
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana:: @ 0x08215C64
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch:: @ 0x08215C80
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan:: @ 0x08215C97
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan:: @ 0x08215CC3
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch:: @ 0x08215CDF
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio:: @ 0x08215CF6
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn:: @ 0x08215D0D
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro: @ 0x08215D24
	.string "えんとつやまの　デコボコさんどう\n"
	.string "まさに　わたしが　もとめていた　やま！\l"
	.string "この　デコボコした　ところが　たまらん！$"

JaggedPass_Text_EricDefeat: @ 0x08215D5E
	.string "まけて　くやしいぞ！$"

JaggedPass_Text_EricPostBattle: @ 0x08215D69
	.string "たしかに　ポケモンでは　まけた⋯⋯\p"
	.string "だが　やまを　あいする　きもちなら\n"
	.string "わたしの　ほうが　まさっているだろ！$"

JaggedPass_Text_DianaIntro: @ 0x08215DA0
	.string "ここは　きがるに　のぼって　いけないもの\n"
	.string "ちょっと　ピクニックむき　じゃないわ$"

JaggedPass_Text_DianaDefeat: @ 0x08215DC8
	.string "あーん　もう！\n"
	.string "したが　デコボコだから⋯⋯$"

JaggedPass_Text_DianaPostBattle: @ 0x08215DDE
	.string "こんな　デコボコしたところ\n"
	.string "じてんしゃで　じょうずに　のぼっていく\l"
	.string "ひとも　いるのよ！$"

JaggedPass_Text_DianaRegister: @ 0x08215E0A
	.string "また　ここに　くることって　あるかな？\n"
	.string "そしたら　わたしと　しょうぶしてね！$"

JaggedPass_Text_DianaRematchIntro: @ 0x08215E31
	.string "どんな　みちも　ピクニックは　たのしい！\n"
	.string "ポケモンも　いっしょ　だしね！$"

JaggedPass_Text_DianaRematchDefeat: @ 0x08215E56
	.string "まけたのは\n"
	.string "したが　デコボコだからよ！$"

JaggedPass_Text_DianaPostRematch: @ 0x08215E6A
	.string "まけたことは　さっさと　わすれて\n"
	.string "この　デコボコみちを　たのしんじゃお！$"

JaggedPass_Text_EthanIntro: @ 0x08215E8F
	.string "この　デコボコさんどうは　あるきにくい！\n"
	.string "ポケモンを　きたえるのに　むいてるよ！$"

JaggedPass_Text_EthanDefeat: @ 0x08215EB8
	.string "あしばを　きにしてる　うちに\n"
	.string "おわっちゃった　かんじだ⋯⋯$"

JaggedPass_Text_EthanPostBattle: @ 0x08215ED6
	.string "ぼくも　ダートじてんしゃ　もっていれば\n"
	.string "だんさを　とびこえて　いけるのにな$"

JaggedPass_Text_EthanRegister: @ 0x08215EFC
	.string "もうちょっと　デコボコに　なれたら\n"
	.string "こんどこそ　かつぞ！\l"
	.string "ぼくを　ポケナビに　とうろく　しといてよ$"

JaggedPass_Text_EthanRematchIntro: @ 0x08215F2E
	.string "デコボコに　なれちゃったから\n"
	.string "ちかごろだと　うたいながら　のぼるのさ！$"

JaggedPass_Text_EthanRematchDefeat: @ 0x08215F52
	.string "やっぱり　デコボコだと\n"
	.string "たたかいにくいよ⋯⋯$"

JaggedPass_Text_EthanPostRematch: @ 0x08215F69
	.string "ぼくも　キンセツで　カゼノさんから\n"
	.string "ダートじてんしゃ　もらおうかな$"

JaggedPass_Text_GruntIntro: @ 0x08215F8B
	.string "うわっ！？　⋯⋯なんだ　おまえ！\p"
	.string "オレが\n"
	.string "　　こんな\l"
	.string "　　　　ところで\l"
	.string "なにを\l"
	.string "　　してるか\l"
	.string "　　　　なんて\l"
	.string "おまえにゃ　カンケー\l"
	.string "な　い　だ　ろ　が！$"

JaggedPass_Text_GruntDefeat: @ 0x08215FD8
	.string "うぐぐ⋯⋯\p"
	.string "はやく\n"
	.string "　　アジトに\l"
	.string "　　　　にげこめば\l"
	.string "　　　　　　よかった⋯⋯$"

JaggedPass_Text_GoWhereverYouWant: @ 0x08216000
	.string "わかった　わかった！\n"
	.string "キミが　つよいのは　みとめて　やるよ！\p"
	.string "オレのことは　きにせず\n"
	.string "すきな　ところへ　いきな！$"

JaggedPass_Text_BoulderShakingInResponseToEmblem: @ 0x08216039
	.string "あ！　マグマのしるしに　はんのうして⋯⋯\n"
	.string "おおきな　いわが⋯⋯\l"
	.string "ブルブルと　しんどう　している！$"

JaggedPass_Text_JulioIntro: @ 0x0821606A
	.string "じてんしゃで　いっきに\n"
	.string "おりて　くると　こわいぃぃ！$"

JaggedPass_Text_JulioDefeat: @ 0x08216085
	.string "ガッタガタ$"

JaggedPass_Text_JulioPostBattle: @ 0x0821608B
	.string "じてんしゃが　おもいっきり\n"
	.string "バウンド　して　おしりが　イタイ⋯⋯$"

JaggedPass_Text_AutumnIntro: @ 0x082160AC
	.string "まいにち　ここを　のぼっているわ\n"
	.string "パワーには　じしん　あるんだから！$"

JaggedPass_Text_AutumnDefeat: @ 0x082160CF
	.string "んー　おっかしいな⋯⋯$"

JaggedPass_Text_AutumnPostBattle: @ 0x082160DB
	.string "すこし　のぼった　ところにある\n"
	.string "おかしな　でっぱりは　なにかしら⋯⋯？$"
