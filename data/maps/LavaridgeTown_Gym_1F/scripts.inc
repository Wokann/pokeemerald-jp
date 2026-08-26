@ LavaridgeTown_Gym_1F scripts (JP map g4 m1 @ 0x081F42C7)

LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition: @ 0x081F42CD
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars:: @ 0x081F42D8
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1

LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar:: @ 0x081F42FF
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1

LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar:: @ 0x081F430D
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1

LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar:: @ 0x081F431B
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1

LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars:: @ 0x081F4329
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers:: @ 0x081F432A
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED

LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald:: @ 0x081F4337
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED

LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle:: @ 0x081F4344
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED

LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle:: @ 0x081F4351
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED

LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers:: @ 0x081F435E
	return

LavaridgeTown_Gym_1F_EventScript_Flannery:: @ 0x081F435F
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated:: @ 0x081F4394
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2:: @ 0x081F43F0
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat:: @ 0x081F4414
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch:: @ 0x081F4437
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole:: @ 0x081F4452
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript:: @ 0x081F446D
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle:: @ 0x081F4482
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan:: @ 0x081F449D
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle:: @ 0x081F44B8
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald:: @ 0x081F44D3
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace:: @ 0x081F44EE
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff:: @ 0x081F4509
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli:: @ 0x081F4524
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide:: @ 0x081F453F
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory:: @ 0x081F4554
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue:: @ 0x081F455E
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue:: @ 0x081F456E
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified:: @ 0x081F457E
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue:: @ 0x081F4588
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice: @ 0x081F4592
	.string "げんき　しとぉや！！\n"
	.string "チャンピオンを　めざす　{PLAYER}！！\p"
	.string "フエンタウン　ジムの　リーダー　アスナは\n"
	.string "ほのおタイプ　ポケモンの　つかいてだ！\p"
	.string "ポケモンに　たいする　じょうねつは\n"
	.string "かざん　よりも　はげしく　あちィ！\p"
	.string "うっかり　ちかづくと　やけど　するから\n"
	.string "みずで　ひやしながら\l"
	.string "きばってこー　な！！$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory: @ 0x081F4625
	.string "いやあー　あちィ　たたかい　だった！$"

LavaridgeTown_Gym_1F_Text_ColeIntro: @ 0x081F4638
	.string "あちちちちちっ！\n"
	.string "ぷはーっ！　あつかったーっ！$"

LavaridgeTown_Gym_1F_Text_ColeDefeat: @ 0x081F4650
	.string "あせが　めに　しみるぜ⋯⋯$"

LavaridgeTown_Gym_1F_Text_ColePostBattle: @ 0x081F465E
	.string "すなブロは　けっこうが　よくなって\n"
	.string "かんせつの　いたみに　こうかてき　だぜ！$"

LavaridgeTown_Gym_1F_Text_AxleIntro: @ 0x081F4685
	.string "ストレスを　かいしょう　する\n"
	.string "おれの　ひとときを　ジャマ　するなーっ！$"

LavaridgeTown_Gym_1F_Text_AxleDefeat: @ 0x081F46A9
	.string "アスナさんに　まけてしまえーっ！$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle: @ 0x081F46BA
	.string "はあ　ふう⋯⋯\p"
	.string "すなブロに　ながく　はいっていると\n"
	.string "けっこう　つかれちゃう　もんだよ⋯⋯$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro: @ 0x081F46E7
	.string "さすがに　つかれてきた　ようだね\n"
	.string "すなブロで　ひとやすみ　したいだろう？\p"
	.string "だが　きりょくを　たもつ　ことも\n"
	.string "トレーナーに　ひつような　さいのう　だよ$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat: @ 0x081F4732
	.string "ひあそびは　けがのもと　だったか⋯⋯$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle: @ 0x081F4745
	.string "きみの　ちからは　ほんものだ⋯⋯\n"
	.string "でも　リーダー　アスナさんは　つよいよ！\p"
	.string "あまく　みていると　おおやけど　するぜ！$"

LavaridgeTown_Gym_1F_Text_GeraldIntro: @ 0x081F4780
	.string "おまえの　ポケモン\n"
	.string "200どの　あつさに　たえられるかよ！？$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat: @ 0x081F479F
	.string "もえかたが　たりなかったか⋯⋯$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle: @ 0x081F47AF
	.string "200どの　あつさ　ってのは\n"
	.string "ようがんの　おんど！\p"
	.string "おまえの　ポケモン　おれに　かてたんだから\n"
	.string "ようがんの　なかでも　へいき　だろうな！$"

LavaridgeTown_Gym_1F_Text_DanielleIntro: @ 0x081F47F4
	.string "えーっと！\n"
	.string "じゃあ　しょうぶの　あいて　しますね！$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat: @ 0x081F480E
	.string "なんて　つよいの！？$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle: @ 0x081F4819
	.string "あたしも　アスナさんと　いっしょに\n"
	.string "きれいで　つよい　トレーナーに　なるんだ！$"

LavaridgeTown_Gym_B1F_Text_JaceIntro: @ 0x081F4841
	.string "ほら　ほらっ！\n"
	.string "きもちが　さめない　うちに　いくぜっ！$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat: @ 0x081F485D
	.string "こんなに　あついのに\n"
	.string "おれの　こころが　さむい⋯⋯$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle: @ 0x081F4877
	.string "そのくらい　とうしを　もやして　いれば\n"
	.string "もしかしたら　リーダーにも　かてるかもな$"

LavaridgeTown_Gym_B1F_Text_JeffIntro: @ 0x081F48A0
	.string "みよ　この　もえさかる　ほのおを！\n"
	.string "オレの　しょうりを　よげんして　いるのだ！$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat: @ 0x081F48C8
	.string "おかしいなあ$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle: @ 0x081F48CF
	.string "いいもんね！　オレなんて\n"
	.string "たきびの　うえを　はだしで　はしれるぜ！\p"
	.string "⋯⋯　おまえは　まね　するなよ$"

LavaridgeTown_Gym_B1F_Text_EliIntro: @ 0x081F4901
	.string "やまの　なかでも　とくに\n"
	.string "かざんが　だいすき　でして⋯⋯$"

LavaridgeTown_Gym_B1F_Text_EliDefeat: @ 0x081F491E
	.string "あれよ　あれよと　いうまに\n"
	.string "まけちまった　わけでして$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle: @ 0x081F4939
	.string "アスナさんの　つよさに　ほれて\n"
	.string "わしは　ここに　いるわけ　でして⋯⋯\l"
	.string "へへへへ$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro: @ 0x081F4961
	.string "ようこそ　⋯⋯じゃなくて\p"
	.string "よくぞ　ここまで　きた　ものだな！\p"
	.string "わたしは　ここの　ジムリーダーを\n"
	.string "つとめさせて　いただく　⋯⋯じゃなくて\p"
	.string "ジムリーダーを　まかされた　アスナだ！\p"
	.string "くう⋯⋯\n"
	.string "ジムリーダーに　なりたて　だからって\l"
	.string "ゆだん　など　しないことだ！\p"
	.string "おじいちゃん　ゆずりの　さいのうと\n"
	.string "このとちで　みがきあげた　ホットな　わざ\l"
	.string "あなたに　みせてやる！$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat: @ 0x081F4A13
	.string "くう⋯⋯\n"
	.string "かたに　ちから　はいっちゃって⋯⋯\p"
	.string "あたし⋯⋯\n"
	.string "ジムリーダーに　なりたて　だからって\l"
	.string "ちょっと　むり　していたのかな⋯⋯\p"
	.string "やっぱ　じぶんらしく　でないと\n"
	.string "いっしょに　たたかってくれる\l"
	.string "ポケモンも　こまっちゃうよね！\p"
	.string "それを　おしえてくれた\n"
	.string "あなたに　これ　あげる！$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge: @ 0x081F4A9D
	.string "{PLAYER}は　アスナから\n"
	.string "ヒートバッジを　もらった！$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis: @ 0x081F4AB5
	.string "ヒートバッジが　あれば\n"
	.string "レベル50　までなら\l"
	.string "ひとから　もらった　ポケモンでも\l"
	.string "いうことを　きいて　くれるんだ！\p"
	.string "それに　ひでんわざの　かいりき　が\n"
	.string "つかえるようにも　なるよ！\p"
	.string "これは　かんしゃの　きもち\n"
	.string "えんりょ　せずに　もらって！$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat: @ 0x081F4B2B
	.string "わざマシン50　には\n"
	.string "オーバーヒートが　はいってるよ！\p"
	.string "その　わざは　あいてに\n"
	.string "おおきな　ダメージを　あたえるんだ！\p"
	.string "だけど　とくこうが\n"
	.string "がくっと　さがっちゃう　から\l"
	.string "ながい　しょうぶには　むかないかも\p"
	.string "⋯⋯　⋯⋯　⋯⋯$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery: @ 0x081F4B9A
	.string "ジムリーダー　アスナを\n"
	.string "ポケナビに　とうろく　した！$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle: @ 0x081F4BB5
	.string "あなたの　つよさ\n"
	.string "だれかを　おもいださせるの　よね⋯⋯\p"
	.string "そうだ！　トウカシティの　ジムリーダー\n"
	.string "センリさんに　にているんだ！$"

LavaridgeTown_Gym_1F_Text_GymStatue: @ 0x081F4BF4
	.string "フエンタウン　ポケモンジム$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified: @ 0x081F4C02
	.string "フエンタウン　ポケモンジム\p"
	.string "アスナ　にんてい　トレーナー！\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch: @ 0x081F4C23
	.string "アスナ“しょうぶに　まけた　ぐらいで\n"
	.string "あたしは　へこたれたり　しない！\p"
	.string "なぜなら　あたしは　ポケモンが　すきで\n"
	.string "しょうぶを　するのが　すきで\l"
	.string "それに⋯⋯　このジムが　すきだから！\p"
	.string "さあ　もういちど　いっしょに\n"
	.string "ホットな　わざを　ぶつけあいましょう！$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat: @ 0x081F4CA0
	.string "ふぅ！　ばくはつ　すんぜん！$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch: @ 0x081F4CAF
	.string "アスナ“しょうぶには　まけたけど\n"
	.string "こんなに　ヒートする　たたかいが　できて\l"
	.string "あたしは　まんぞくよ！\p"
	.string "そのうち　また　しょうぶ　しましょうね！$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons: @ 0x081F4CF6
	.string "アスナ“しょうぶに　まけた　ぐらいで\n"
	.string "あたしは　へこたれたり　しない！\p"
	.string "なぜなら　あたしは　ポケモンが　すきで\n"
	.string "しょうぶを　するのが　すきで\l"
	.string "それに⋯⋯　このジムが　すきだから！\p"
	.string "さあ　もういちど　いっしょに\n"
	.string "ホットな　わざを　ぶつけあいましょう！\p"
	.string "⋯⋯あら？　たたかえる　ポケモンを\n"
	.string "1ひきしか　もって　いないんですね\p"
	.string "すみませんけど　2ひき　いじょうの\n"
	.string "ポケモンを　もって　きてください$"
