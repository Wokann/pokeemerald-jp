@ DewfordTown_Gym scripts (JP map g3 m3 @ 0x081F2D87)

DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition: @ 0x081F2D8D
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel:: @ 0x081F2D93
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0x0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 0x1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 0x2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 0x3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 0x4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 0x5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn:: @ 0x081F2DED
	setflashlevel 0
	return

DewfordTown_Gym_EventScript_SetFlashLevel1:: @ 0x081F2DF1
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2:: @ 0x081F2DF5
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3:: @ 0x081F2DF9
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4:: @ 0x081F2DFD
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5:: @ 0x081F2E01
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6:: @ 0x081F2E05
	setflashlevel 6
	return

DewfordTown_Gym_EventScript_SetFlashLevel7:: @ 0x081F2E09
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom:: @ 0x081F2E0D
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0x1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 0x2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 0x3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 0x4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 0x5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 0x6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange:: @ 0x081F2E65
	return

DewfordTown_Gym_EventScript_AnimateFlash1Trainer:: @ 0x081F2E66
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers:: @ 0x081F2E71
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers:: @ 0x081F2E7C
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers:: @ 0x081F2E87
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers:: @ 0x081F2E92
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers:: @ 0x081F2E9D
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness:: @ 0x081F2EA8
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated:: @ 0x081F2EB3
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1

DewfordTown_Gym_EventScript_CheckJocelyn:: @ 0x081F2EC6
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1

DewfordTown_Gym_EventScript_CheckLaura:: @ 0x081F2ED4
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1

DewfordTown_Gym_EventScript_CheckBrenden:: @ 0x081F2EE2
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1

DewfordTown_Gym_EventScript_CheckCristian:: @ 0x081F2EF0
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1

DewfordTown_Gym_EventScript_CheckLilith:: @ 0x081F2EFE
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1

DewfordTown_Gym_EventScript_StopCountingTrainers:: @ 0x081F2F0C
	return

DewfordTown_Gym_EventScript_Brawly:: @ 0x081F2F0D
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated:: @ 0x081F2F42
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 0x6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp:: @ 0x081F2FA0
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0x0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2: @ 0x081F2FC3
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0x0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch:: @ 0x081F2FE7
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao:: @ 0x081F3002
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom:: @ 0x081F301D
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn:: @ 0x081F3024
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom:: @ 0x081F303F
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura:: @ 0x081F3046
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom:: @ 0x081F3061
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden:: @ 0x081F3068
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom:: @ 0x081F3083
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian:: @ 0x081F308A
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom:: @ 0x081F30A5
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith:: @ 0x081F30AC
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom:: @ 0x081F30C7
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide:: @ 0x081F30CE
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory:: @ 0x081F30E3
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue:: @ 0x081F30ED
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue:: @ 0x081F30FD
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified:: @ 0x081F310D
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue:: @ 0x081F3117
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice: @ 0x081F3121
	.string "げんき　しとぉや！！\n"
	.string "チャンピオンを　めざす　{PLAYER}！！\p"
	.string "ムロタウン　ジムの　リーダー　トウキは\n"
	.string "かくとうタイプ　ポケモンの　つかいてだ！\p"
	.string "ノーマルタイプで　むかうと\n"
	.string "きびしぃー　いちげきを　くらうから\l"
	.string "きを　つけたほうが　いいぞ！\p"
	.string "しかも！　この　ジムの　なかは\n"
	.string "うみのそこ　みたいに　くらいんだ！\p"
	.string "でも！　トレーナーを　ひとり　たおすごとに\n"
	.string "だんだん　あかるく　なって　いくぞ！\p"
	.string "じゃ　きばってこォー！！$"

DewfordTown_Gym_Text_GymGuidePostVictory: @ 0x081F31ED
	.string "うおォ！　ずいぶん　あかるく　なったな！\p"
	.string "きみの　みらいも　あかるいぞ！$"

DewfordTown_Gym_Text_TakaoIntro: @ 0x081F3212
	.string "ちから　こそ　せいぎっ！\n"
	.string "ドリャーッ！！$"

DewfordTown_Gym_Text_TakaoDefeat: @ 0x081F3227
	.string "ちからぶそく　だった⋯⋯！$"

DewfordTown_Gym_Text_TakaoPostBattle: @ 0x081F3235
	.string "じゅう　よく　ごうを　せいす！\n"
	.string "みごとな　たたかいぶり　だった！$"

DewfordTown_Gym_Text_JocelynIntro: @ 0x081F3256
	.string "トウキさまと　たたかうまでも　ないわ！\n"
	.string "わたしが　たおして　あげる！$"

DewfordTown_Gym_Text_JocelynDefeat: @ 0x081F3279
	.string "まさか⋯⋯\n"
	.string "こんなに　かんたんに　やられるなんて$"

DewfordTown_Gym_Text_JocelynPostBattle: @ 0x081F3292
	.string "この　まけを　むだに　しないため\n"
	.string "もっと　とっくん　する！\p"
	.string "そして　いつかは　ジムリーダーに⋯⋯\p"
	.string "いえ　ポケモンリーグの\n"
	.string "チャンピオンに　なるわよ！$"

DewfordTown_Gym_Text_LauraIntro: @ 0x081F32DD
	.string "あたしを　あまく　みない　ことね！\n"
	.string "ないても　しらないわよ！$"

DewfordTown_Gym_Text_LauraDefeat: @ 0x081F32FC
	.string "わぁーーーん！\n"
	.string "まけたーーーっ！$"

DewfordTown_Gym_Text_LauraPostBattle: @ 0x081F330D
	.string "くらやみの　なかで　たたかうことで\n"
	.string "こころを　きたえるの\p"
	.string "でも　まっくら　だから\n"
	.string "トウキさまの　おかおを　みられない⋯⋯$"

DewfordTown_Gym_Text_LilithIntro: @ 0x081F334A
	.string "うふふ⋯⋯！\n"
	.string "くらくて　まよっているの　かな？$"

DewfordTown_Gym_Text_LilithDefeat: @ 0x081F3362
	.string "なによ　もう\n"
	.string "しらない！$"

DewfordTown_Gym_Text_LilithPostBattle: @ 0x081F336F
	.string "あなた　なんて　このまま　まよって\n"
	.string "いりぐちに　もどっちゃえば　いーのよ！$"

DewfordTown_Gym_Text_BrendenIntro: @ 0x081F3395
	.string "うみの　おとこの　いじを\n"
	.string "みせつけて　やるぜぃ！$"

DewfordTown_Gym_Text_BrendenDefeat: @ 0x081F33AE
	.string "どうしたぃ！\n"
	.string "おれと　した　ことが⋯⋯$"

DewfordTown_Gym_Text_BrendenPostBattle: @ 0x081F33C2
	.string "おう！　あんたなら\n"
	.string "ジムリーダーに　いどむに　ふさわしいぜぃ！$"

DewfordTown_Gym_Text_CristianIntro: @ 0x081F33E2
	.string "ここを　とおる　なら\n"
	.string "この　わしを　たおしてから　じゃ！$"

DewfordTown_Gym_Text_CristianDefeat: @ 0x081F33FF
	.string "むうーん！\n"
	.string "すごく　つよい⋯⋯！$"

DewfordTown_Gym_Text_CristianPostBattle: @ 0x081F3410
	.string "わしの　まけじゃ！\n"
	.string "がんばって　バッジ　とってこいよ！$"

DewfordTown_Gym_Text_BrawlyIntro: @ 0x081F342C
	.string "ボクは　ムロ　ポケモンジム\n"
	.string "リーダーの　トウキ！\p"
	.string "この　あたりの\n"
	.string "はげしい　なみに　もまれ⋯⋯\p"
	.string "くらい　どうくつで\n"
	.string "しゅぎょう　して　いるのさ！\p"
	.string "ボクに　ちょうせん　しよう　という\n"
	.string "キミの　じつりょく⋯⋯\l"
	.string "どれほどの　ものか　みせて　もらうよ！$"

DewfordTown_Gym_Text_BrawlyDefeat: @ 0x081F34A7
	.string "ううーん　よそう　していたより\n"
	.string "キミは　ビッグウェーブ！\p"
	.string "わかった！\n"
	.string "この　バッジを　もっていきな！$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge: @ 0x081F34DA
	.string "{PLAYER}は　トウキから\n"
	.string "ナックルバッジを　もらった！$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis: @ 0x081F34F3
	.string "ナックルバッジには\n"
	.string "レベル30までの　ポケモンなら\l"
	.string "ひとから　もらった　ポケモンでも\l"
	.string "すなおに　する　こうかが　ある！\p"
	.string "それに　たたかって　いなくても\n"
	.string "ひでんわざの　フラッシュを　つかえる！\p"
	.string "この　わざマシン\n"
	.string "よかったら　つかいな！$"

DewfordTown_Gym_Text_ExplainBulkUp: @ 0x081F3568
	.string "その　わざマシン08　には\n"
	.string "ビルドアップが　はいっている！\p"
	.string "こうげきりょくと　ぼうぎょりょくを\n"
	.string "あげる　わざ　なのさ！\p"
	.string "⋯⋯　⋯⋯　⋯⋯$"

DewfordTown_Gym_Text_RegisteredBrawly: @ 0x081F35AD
	.string "ジムリーダー　トウキを\n"
	.string "ポケナビに　とうろく　した！$"

DewfordTown_Gym_Text_BrawlyPostBattle: @ 0x081F35C8
	.string "キミの　さいのうは\n"
	.string "いつのひか　おおきな　なみと　なって\p"
	.string "ポケモン　トレーナーたちの　あいだに\n"
	.string "おどろきの　あらしを　まきおこすだろう！$"

DewfordTown_Gym_Text_GymStatue: @ 0x081F360D
	.string "ムロタウン　ポケモンジム$"

DewfordTown_Gym_Text_GymStatueCertified: @ 0x081F361A
	.string "ムロタウン　ポケモンジム\p"
	.string "トウキ　にんてい　トレーナー！\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch: @ 0x081F363A
	.string "トウキ“なみというのは　いちど　ひいても\n"
	.string "いつか　かならず　はまべに　もどってくる\p"
	.string "キミほどの　ビッグウェーブだ\n"
	.string "きっと　また　くると　おもっていたよ！\p"
	.string "さあ　どれほど　たかさを　ましたのか\n"
	.string "ボクに　みせてくれ！$"

DewfordTown_Gym_Text_BrawlyRematchDefeat: @ 0x081F36A5
	.string "わーおっ！\n"
	.string "キミに　のみこまれそうだ！$"

DewfordTown_Gym_Text_BrawlyPostRematch: @ 0x081F36B9
	.string "トウキ“やっぱり　ポケモン　しょうぶは\n"
	.string "そこが　みえないほど　ふかく　ひろい！\l"
	.string "まるで　ホウエンの　うみの　ようだね！$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons: @ 0x081F36F5
	.string "トウキ“なみというのは　いちど　ひいても\n"
	.string "いつか　かならず　はまべに　もどってくる\p"
	.string "キミほどの　ビッグウェーブだ\n"
	.string "きっと　また　くると　おもっていたよ！\p"
	.string "⋯⋯あれ？　たたかえる　ポケモンを\n"
	.string "1ひきしか　もっていないんだね\p"
	.string "すまないけど　2ひき　いじょうの\n"
	.string "ポケモンを　もって　また　きてくれよ$"
