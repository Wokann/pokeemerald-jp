@ MtChimney scripts (JP map g24 m12 @ 0x08214B94)

MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:: @ 0x08214B9F
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:: @ 0x08214BA5
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie:: @ 0x08214BA8
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma:: @ 0x08214BCC
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting:: @ 0x08214BD5
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie:: @ 0x08214BDE
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast:: @ 0x08214C9A
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth:: @ 0x08214CA5
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast:: @ 0x08214CB0
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth:: @ 0x08214CBB
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady:: @ 0x08214CC6
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE, 1
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull:: @ 0x08214D24
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney:: @ 0x08214D31
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie:: @ 0x08214D3C
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney:: @ 0x08214D49
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1:: @ 0x08214E26
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2:: @ 0x08214E2F
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3:: @ 0x08214E38
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha:: @ 0x08214E41
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2:: @ 0x08214E58
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1:: @ 0x08214E6F
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2:: @ 0x08214E78
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3:: @ 0x08214E81
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4:: @ 0x08214E8A
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5:: @ 0x08214E93
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6:: @ 0x08214E9C
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena:: @ 0x08214EA5
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena:: @ 0x08214EAE
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine:: @ 0x08214EB7
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone:: @ 0x08214EF6
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff:: @ 0x08214F00
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn:: @ 0x08214F0A
	msgbox MtChimney_Text_MeteoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign:: @ 0x08214F14
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby:: @ 0x08214F1D
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby:: @ 0x08214F49
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby:: @ 0x08214F68
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa:: @ 0x08214F7F
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila:: @ 0x08214F96
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley:: @ 0x08214FAD
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1:: @ 0x08214FC4
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer:: @ 0x08214FDB
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated:: @ 0x08215007
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch:: @ 0x08215026
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano: @ 0x0821503D
	.string "いんせきに　ひめられた　ちから\p"
	.string "この　そうちで　ぞうふく　すれば\n"
	.string "たちまちの　うちに　えんとつやまの\l"
	.string "かざん　かつどうは　かっぱつになる⋯⋯\p"
	.string "その　エネルギーが\n"
	.string "かこうの　おくふかくに　はたらきかけ\l"
	.string "そして　ふふふ⋯⋯$"

MtChimney_Text_MaxieIntro: @ 0x082150AB
	.string "マツブサ“ん？　だれだ　おまえは\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "さいきん　アクアだんの　かつどうを\n"
	.string "じゃまする　こどもがいる　と\l"
	.string "アオギリの　やつが　ぼやいて　いたが\l"
	.string "それは　おまえの　ことか\p"
	.string "⋯⋯ふん！\n"
	.string "われわれ　マグマだんの　じゃまも\l"
	.string "してくれようって　わけだな！\p"
	.string "いいか？　いきものは　りくちに　あがり\n"
	.string "しんかを　くりかえしてきた\p"
	.string "そう　だいちこそが　すべてなのだ！\p"
	.string "だから　われわれ　マグマだんは\n"
	.string "だいちを　ふやすことで\l"
	.string "ひとと　ポケモンの　はってんを　めざす！\p"
	.string "そのために　ひつよう　なのが\n"
	.string "このやまに　ねむる　アイツ⋯⋯\p"
	.string "おっと！　そんなことまで\n"
	.string "おまえが　しる　ひつようは　なかったな\p"
	.string "そんなことより\n"
	.string "われわれの　じゃまを　したら　どうなるか\l"
	.string "おまえに　わからせて　やろう！$"

MtChimney_Text_MaxieDefeat: @ 0x08215207
	.string "なに！？\p"
	.string "この　マツブサとも　あろう　ものが\n"
	.string "ゆだん　したか！？$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma: @ 0x08215228
	.string "マツブサ“まあ　いい\n"
	.string "このばは　ひとまず　あきらめよう⋯⋯\p"
	.string "だが　マグマだんの　かつどうは\n"
	.string "これで　おわったわけでは　ないのだ！\p"
	.string "ふふふ⋯⋯\p"
	.string "いんせきなど　つかわなくとも\n"
	.string "あの　たまが　てにはいれば　ふふふ⋯⋯$"

MtChimney_Text_TabithaIntro: @ 0x08215292
	.string "ウヒョヒョ！\p"
	.string "おまえ　ここまで　きたのか！\p"
	.string "だけど　おそかったぜ\n"
	.string "りゅうせいのたきで　みつけた\l"
	.string "いんせきは　リーダーに　わたしたからな！$"

MtChimney_Text_TabithaDefeat: @ 0x082152D7
	.string "ウヒョヒョ⋯⋯\p"
	.string "オレが　まけても　リーダーが　ちゃんと\n"
	.string "アイツを　めざめさせて⋯⋯$"

MtChimney_Text_TabithaPostBattle: @ 0x08215301
	.string "リーダー！　はやく！\n"
	.string "いんせきの　パワーを　アイツに！\p"
	.string "ウヒョヒョ⋯⋯！$"

MtChimney_Text_Grunt2Intro: @ 0x08215326
	.string "オレら　マグマだんは\n"
	.string "みんなの　ために　がんばってるんだ！\p"
	.string "だって　アイツの　ちからで\n"
	.string "だいちが　ふえれば　みんなも\l"
	.string "すむところが　ふえて　うれしいだろ？$"

MtChimney_Text_Grunt2Defeat: @ 0x08215374
	.string "あれー？\n"
	.string "オレ　まけたのー！？$"

MtChimney_Text_Grunt2PostBattle: @ 0x08215384
	.string "オレらの　リーダーは\n"
	.string "‘みんなが　よろこぶ　ことだ’って\l"
	.string "いってるんだ！\p"
	.string "なのに　なんで　みんな　ジャマするんだ？$"

MtChimney_Text_Grunt1Intro: @ 0x082153BE
	.string "りくちが　ふえて　くれたら\n"
	.string "おおきな　マイホーム　だって　もてるわ！\p"
	.string "ようがんの　うえに　ひっこし　するのよ！$"

MtChimney_Text_Grunt1Defeat: @ 0x082153F6
	.string "わたしの　マイホームの　ゆめが⋯⋯$"

MtChimney_Text_Grunt1PostBattle: @ 0x08215408
	.string "あんた　なんか　うみに　プカプカ\n"
	.string "うかんで　いれば　いいのよ！$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans: @ 0x08215428
	.string "アクアだんの　やつらめ⋯⋯\n"
	.string "いちいち　オレたちの　じゃまを　しやがって！$"

MtChimney_Text_MeteoritesPackAmazingPower: @ 0x0821544D
	.string "いんせきには　すごい　パワーが　あるのだ！$"

MtChimney_Text_YouBetterNotMessWithUs: @ 0x08215463
	.string "オレたちの　じゃまを　するな！\p"
	.string "アイツを　ふっかつ　させるのは\n"
	.string "みんなの　ために　やってること　なんだ！$"

MtChimney_Text_AquasNameSimilar: @ 0x08215498
	.string "オレたちは　マグマだん！\p"
	.string "やつらは　アクアだん！\p"
	.string "にたような　なまえを　つけやがって\n"
	.string "いまいましい　やつらだ！$"

MtChimney_Text_DouseThemInFire: @ 0x082154D0
	.string "よーし！\n"
	.string "ほのおを　ぶっかけてやれー！！$"

MtChimney_Text_KeepMakingMoreLand: @ 0x082154E5
	.string "もっと　もっと　だいちを　ふやすぜ！！$"

MtChimney_Text_Bufoh: @ 0x082154F9
	.string "ぶふぉー！！$"

MtChimney_Text_ArchieGoStopTeamMagma: @ 0x08215500
	.string "アオギリ“むむむ　{PLAYER}！\n"
	.string "やっぱり　ここにも　あらわれたか！\p"
	.string "ほら！　マグマだんの　れんちゅうが\n"
	.string "なにを　たくらんで　いるのか　みてみろ！\p"
	.string "やつらは　うばった　いんせきの　パワーを\n"
	.string "かざんに　ながしこもうと　しているんだ！\p"
	.string "そんなことを　したら\n"
	.string "かざんが　だいふんか　するじゃないか！$"

MtChimney_Text_ArchieIHaveMyHandsFull: @ 0x0821558F
	.string "アオギリ“うーむ　むむむ！\p"
	.string "マツブサの　やつを　とめに　いきたいが\n"
	.string "さすがの　おれも\l"
	.string "3にん　どうじに　あいてを　していては\l"
	.string "てが　はなせない！$"

MtChimney_Text_ArchieThankYou: @ 0x082155D8
	.string "アオギリ“{PLAYER}⋯⋯　たすかったよ\n"
	.string "おまえの　おかげで　マグマだんの\l"
	.string "はかいかつどうを　ふせぐことが　できた\p"
	.string "だが　おまえは⋯⋯\n"
	.string "どちらの　みかた　なんだ⋯⋯\p"
	.string "まあ　いい\p"
	.string "われわれは　ひきつづき\n"
	.string "マグマだんを　おいかけると　しよう！\p"
	.string "{PLAYER}　おまえとは　また\n"
	.string "どこかで　あうことに　なりそうだな⋯⋯$"

MtChimney_Text_MagmaOutnumbersUs: @ 0x0821566C
	.string "くそう　マグマだんが　おおすぎる⋯⋯\n"
	.string "このままでは　まずいぞ！$"

MtChimney_Text_LessHabitatForWaterPokemon: @ 0x0821568C
	.string "だいちを　ふやしたら\n"
	.string "みずポケモンが　すむ　ばしょが\l"
	.string "へってしまう　じゃねーか！$"

MtChimney_Text_MagmasNameSimilar: @ 0x082156B5
	.string "オレたちは　アクアだん！\p"
	.string "やつらは　マグマだん！\p"
	.string "まぎらわしい　なまえを　つけやがって\n"
	.string "しゃくにさわる　やつらだ！$"

MtChimney_Text_Bushaa: @ 0x082156EF
	.string "ぷしゃー！！$"

MtChimney_Text_LavaCookiesJust200: @ 0x082156F6
	.string "えんとつやま　めいぶつ\n"
	.string "フエンせんべい　ひとつ　200えん！\l"
	.string "かって　おいきよ$"

MtChimney_Text_ThankYouDear: @ 0x0821571E
	.string "どうも　ありがとね$"

MtChimney_Text_YouveNotGotTheMoney: @ 0x08215728
	.string "おやまあ　おかねが　なくちゃ\n"
	.string "ものは　かえないよ$"

MtChimney_Text_OhFineThen: @ 0x08215741
	.string "あら　そうかい$"

MtChimney_Text_MeteoriteFittedOnMachine: @ 0x08215749
	.string "なぞの　そうちに\n"
	.string "いんせきが　はめられている⋯⋯\p"
	.string "なにかの　エネルギーを\n"
	.string "ためている　さいちゅうの　ようだ$"

MtChimney_Text_RemoveTheMeteorite: @ 0x0821577F
	.string "なぞの　そうちに\n"
	.string "いんせきが　はめられている⋯⋯\p"
	.string "いんせきを　とりますか？$"

MtChimney_Text_PlayerRemovedMeteorite: @ 0x082157A5
	.string "{PLAYER}は　いんせきを\n"
	.string "そうちから　とりはずした！$"

MtChimney_Text_PlayerLeftMeteorite: @ 0x082157BD
	.string "{PLAYER}は　いんせきを\n"
	.string "そのままに　しておいた$"

MtChimney_Text_MachineMakesNoResponse: @ 0x082157D3
	.string "なぞの　そうち⋯⋯\n"
	.string "まったく　はんのう　しない⋯⋯$"

MtChimney_Text_RouteSign: @ 0x082157ED
	.string "{DOWN_ARROW}　デコボコさんどう\n"
	.string "とおりぬけると　フエンタウン$"

MtChimney_Text_ShelbyIntro: @ 0x08215809
	.string "おんせんに　つかって\n"
	.string "リフレッシュ　してきたからねえ\l"
	.string "いまの　あたしゃあ　つよいよ！$"

MtChimney_Text_ShelbyDefeat: @ 0x08215834
	.string "おんや　まぁ\n"
	.string "たいした　もんだよ$"

MtChimney_Text_ShelbyPostBattle: @ 0x08215845
	.string "まけて　しもうたら\n"
	.string "たつじん　とは　いえないねえ$"

MtChimney_Text_ShelbyRegister: @ 0x0821585E
	.string "マゴと　たたかってる　ようで　たのしかった\n"
	.string "よかったら　また　あいてを　しておくれ！$"

MtChimney_Text_ShelbyRematchIntro: @ 0x08215889
	.string "ポケモンと　こころを　ひとつに　できれば\n"
	.string "すばらしいことが　できそうじゃの$"

MtChimney_Text_ShelbyRematchDefeat: @ 0x082158AF
	.string "おんや　まぁ\n"
	.string "たいした　もんだよ$"

MtChimney_Text_ShelbyPostRematch: @ 0x082158C0
	.string "おまえさんの　こころと\n"
	.string "ポケモンの　こころは　ひとつ　なのかもな$"

MtChimney_Text_MelissaIntro: @ 0x082158E1
	.string "なんだか　もえあがってきて\n"
	.string "たたかいたくて　たまらないのっ！$"

MtChimney_Text_MelissaDefeat: @ 0x08215900
	.string "あつい　たたかい　だったわ$"

MtChimney_Text_MelissaPostBattle: @ 0x0821590E
	.string "えんとつやまの　あつさが\n"
	.string "おんなを　もえあがらせるの$"

MtChimney_Text_SheilaIntro: @ 0x08215929
	.string "せっかく　えんとつやまに　きたんだから\n"
	.string "ここでも　ポケモンを　たたかわせたいの！$"

MtChimney_Text_SheilaDefeat: @ 0x08215952
	.string "その　たたかいかた\n"
	.string "まさに　えんとつやま　だいふんか！$"

MtChimney_Text_SheilaPostBattle: @ 0x0821596E
	.string "せっかく　えんとつやまに　きたんだから\n"
	.string "かんこう　だけじゃ　もったいないわ\p"
	.string "しょうぶも　たのしみたいし\n"
	.string "おみやげに　せんべい　かわなきゃ！$"

MtChimney_Text_ShirleyIntro: @ 0x082159B4
	.string "おんせんに　はいったら\n"
	.string "ちょうし　バッチリ　なのよね！\l"
	.string "ぜったい　かてるわ！$"

MtChimney_Text_ShirleyDefeat: @ 0x082159DB
	.string "うーん　ゆざめ　しちゃう$"

MtChimney_Text_ShirleyPostBattle: @ 0x082159E8
	.string "もういちど　おんせんに　はいらなきゃ！\n"
	.string "あなたも　いっしょに　はいる？\p"
	.string "なんてねっ！$"

MtChimney_Text_SawyerIntro: @ 0x08215A13
	.string "ここは　いい　やまだ！\n"
	.string "あっつい　おねいさんたちが　いっぱいだあ！$"

MtChimney_Text_SawyerDefeat: @ 0x08215A35
	.string "おおっ　あんたも　あついねぇ！$"

MtChimney_Text_SawyerPostBattle: @ 0x08215A45
	.string "いまから　あつい　おねいさんたちを　つれて\n"
	.string "フエンおんせん　でも　いこうかな$"

MtChimney_Text_SawyerRegister: @ 0x08215A6C
	.string "あつい　トレーナーは　すきだなあ！\n"
	.string "ポケナビに　とうろくしても　いいかい$"

MtChimney_Text_SawyerRematchIntro: @ 0x08215A91
	.string "あっつい　おねいさん　たちに\n"
	.string "かこまれて　しあわせな　おれは　まけんぜ！$"

MtChimney_Text_SawyerRematchDefeat: @ 0x08215AB6
	.string "おおっ　やっぱり\n"
	.string "あんたの　ほうが　あついねぇ！$"

MtChimney_Text_SawyerPostRematch: @ 0x08215ACF
	.string "しかし　ほんとに　あついや⋯⋯\n"
	.string "ふく　いっぱい　きすぎちゃった　かな$"
