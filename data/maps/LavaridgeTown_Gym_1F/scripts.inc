LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
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

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "げんき　しとぉや！！\n"
	.string "チャンピオンを　めざす　{PLAYER}！！\p"
	.string "フエンタウン　ジムの　リーダー　アスナは\n"
	.string "ほのおタイプ　ポケモンの　つかいてだ！\p"
	.string "ポケモンに　たいする　じょうねつは\n"
	.string "かざん　よりも　はげしく　あちィ！\p"
	.string "うっかり　ちかづくと　やけど　するから\n"
	.string "みずで　ひやしながら\l"
	.string "きばってこー　な！！$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "いやあー　あちィ　たたかい　だった！$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "あちちちちちっ！\n"
	.string "ぷはーっ！　あつかったーっ！$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "あせが　めに　しみるぜ⋯⋯$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "すなブロは　けっこうが　よくなって\n"
	.string "かんせつの　いたみに　こうかてき　だぜ！$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "ストレスを　かいしょう　する\n"
	.string "おれの　ひとときを　ジャマ　するなーっ！$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "アスナさんに　まけてしまえーっ！$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "はあ　ふう⋯⋯\p"
	.string "すなブロに　ながく　はいっていると\n"
	.string "けっこう　つかれちゃう　もんだよ⋯⋯$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "さすがに　つかれてきた　ようだね\n"
	.string "すなブロで　ひとやすみ　したいだろう？\p"
	.string "だが　きりょくを　たもつ　ことも\n"
	.string "トレーナーに　ひつような　さいのう　だよ$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "ひあそびは　けがのもと　だったか⋯⋯$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "きみの　ちからは　ほんものだ⋯⋯\n"
	.string "でも　リーダー　アスナさんは　つよいよ！\p"
	.string "あまく　みていると　おおやけど　するぜ！$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "おまえの　ポケモン\n"
	.string "200どの　あつさに　たえられるかよ！？$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "もえかたが　たりなかったか⋯⋯$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "200どの　あつさ　ってのは\n"
	.string "ようがんの　おんど！\p"
	.string "おまえの　ポケモン　おれに　かてたんだから\n"
	.string "ようがんの　なかでも　へいき　だろうな！$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "えーっと！\n"
	.string "じゃあ　しょうぶの　あいて　しますね！$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "なんて　つよいの！？$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "あたしも　アスナさんと　いっしょに\n"
	.string "きれいで　つよい　トレーナーに　なるんだ！$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "ほら　ほらっ！\n"
	.string "きもちが　さめない　うちに　いくぜっ！$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "こんなに　あついのに\n"
	.string "おれの　こころが　さむい⋯⋯$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "そのくらい　とうしを　もやして　いれば\n"
	.string "もしかしたら　リーダーにも　かてるかもな$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "みよ　この　もえさかる　ほのおを！\n"
	.string "オレの　しょうりを　よげんして　いるのだ！$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "おかしいなあ$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "いいもんね！　オレなんて\n"
	.string "たきびの　うえを　はだしで　はしれるぜ！\p"
	.string "⋯⋯　おまえは　まね　するなよ$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "やまの　なかでも　とくに\n"
	.string "かざんが　だいすき　でして⋯⋯$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "あれよ　あれよと　いうまに\n"
	.string "まけちまった　わけでして$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "アスナさんの　つよさに　ほれて\n"
	.string "わしは　ここに　いるわけ　でして⋯⋯\l"
	.string "へへへへ$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
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

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
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

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER}は　アスナから\n"
	.string "ヒートバッジを　もらった！$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "ヒートバッジが　あれば\n"
	.string "レベル50　までなら\l"
	.string "ひとから　もらった　ポケモンでも\l"
	.string "いうことを　きいて　くれるんだ！\p"
	.string "それに　ひでんわざの　かいりき　が\n"
	.string "つかえるようにも　なるよ！\p"
	.string "これは　かんしゃの　きもち\n"
	.string "えんりょ　せずに　もらって！$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "わざマシン50　には\n"
	.string "オーバーヒートが　はいってるよ！\p"
	.string "その　わざは　あいてに\n"
	.string "おおきな　ダメージを　あたえるんだ！\p"
	.string "だけど　とくこうが\n"
	.string "がくっと　さがっちゃう　から\l"
	.string "ながい　しょうぶには　むかないかも\p"
	.string "⋯⋯　⋯⋯　⋯⋯$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "ジムリーダー　アスナを\n"
	.string "ポケナビに　とうろく　した！$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "あなたの　つよさ\n"
	.string "だれかを　おもいださせるの　よね⋯⋯\p"
	.string "そうだ！　トウカシティの　ジムリーダー\n"
	.string "センリさんに　にているんだ！$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "フエンタウン　ポケモンジム$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "フエンタウン　ポケモンジム\p"
	.string "アスナ　にんてい　トレーナー！\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "アスナ“しょうぶに　まけた　ぐらいで\n"
	.string "あたしは　へこたれたり　しない！\p"
	.string "なぜなら　あたしは　ポケモンが　すきで\n"
	.string "しょうぶを　するのが　すきで\l"
	.string "それに⋯⋯　このジムが　すきだから！\p"
	.string "さあ　もういちど　いっしょに\n"
	.string "ホットな　わざを　ぶつけあいましょう！$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "ふぅ！　ばくはつ　すんぜん！$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "アスナ“しょうぶには　まけたけど\n"
	.string "こんなに　ヒートする　たたかいが　できて\l"
	.string "あたしは　まんぞくよ！\p"
	.string "そのうち　また　しょうぶ　しましょうね！$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
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
