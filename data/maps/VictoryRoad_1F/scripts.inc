@ VictoryRoad_1F scripts (JP map g24 m43 @ 0x0821949C)

VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:: @ 0x082194A2
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1:: @ 0x082194B9
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 2, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2:: @ 0x082194C5
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 3, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1:: @ 0x082194D1
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2:: @ 0x082194EA
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle:: @ 0x08219503
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_EventScript_EntranceWally:: @ 0x0821954E
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

VictoryRoad_1F_EventScript_ExitWally:: @ 0x08219557
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally:: @ 0x0821957E
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar:: @ 0x08219595
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert:: @ 0x082195AC
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope:: @ 0x082195C3
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy:: @ 0x082195DA
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn:: @ 0x082195F1
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore: @ 0x08219608
	.string "ミツル“あっ！　{PLAYER}さん！\p"
	.string "ぼくが　こんな　ところに　いるなんて\n"
	.string "おどろいた　でしょ！\p"
	.string "ぼくが　ここまで　これたのは\n"
	.string "{PLAYER}さんの　おかげだよ！\p"
	.string "あのとき　{PLAYER}さんに　まけたから\n"
	.string "ぼくは　つよく　なれたんだ！\p"
	.string "⋯⋯だけど！\n"
	.string "ぼくは　もう　まけない\p"
	.string "ぼくに　ゆうきと　げんきを　くれた\n"
	.string "ポケモンの　ためにも　かつんだ！\p"
	.string "それでは⋯⋯　いきますよ！$"

VictoryRoad_1F_Text_WallyEntranceDefeat: @ 0x082196B4
	.string "うわぁ！\n"
	.string "やっぱり　{PLAYER}さんは　つよいよ！$"

VictoryRoad_1F_Text_WallyPostEntranceBattle: @ 0x082196CA
	.string "ミツル“⋯⋯　こんかいは\n"
	.string "{PLAYER}さんに　かてなかった　けど\l"
	.string "いつか　きっと　おいついて　みせるからね！$"

VictoryRoad_1F_Text_WallyIntro: @ 0x082196FD
	.string "ミツル“あっ！　{PLAYER}さん！\p"
	.string "ぼく　あれから　つよくなった　はずだよ！\n"
	.string "それを　{PLAYER}さんに\l"
	.string "みてもらいたいんだ！\p"
	.string "それでは⋯⋯　いきますよ！$"

VictoryRoad_1F_Text_WallyDefeat: @ 0x08219743
	.string "うわぁ！\n"
	.string "やっぱり　{PLAYER}さんは　つよいよ！$"

VictoryRoad_1F_Text_WallyPostBattle: @ 0x08219759
	.string "ミツル“⋯⋯　こんかいも\n"
	.string "{PLAYER}さんに　かてなかった　けど\l"
	.string "いつか　きっと　おいついて⋯⋯\p"
	.string "ポケモンリーグに　ちょうせん　するんだ！$"

VictoryRoad_1F_Text_EdgarIntro: @ 0x0821979B
	.string "ここまでは　なんとか　これたが\n"
	.string "あと　すこしが　とても　とおいよ⋯⋯$"

VictoryRoad_1F_Text_EdgarDefeat: @ 0x082197BE
	.string "ここで　おわったか⋯⋯$"

VictoryRoad_1F_Text_EdgarPostBattle: @ 0x082197CA
	.string "ここまで　きたなら\n"
	.string "いきおいで　チャンピオンに　なれよ！\l"
	.string "きみなら　できるさ！$"

VictoryRoad_1F_Text_AlbertIntro: @ 0x082197F2
	.string "せっかく　ここまで　きたんだ\n"
	.string "いまさら　まけるなんて　ありえないよ！$"

VictoryRoad_1F_Text_AlbertDefeat: @ 0x08219815
	.string "まさか⋯⋯\n"
	.string "まけたのか⋯⋯？$"

VictoryRoad_1F_Text_AlbertPostBattle: @ 0x08219824
	.string "ここで　まけた⋯⋯\p"
	.string "ということは　まだ　チャンピオンに　なる\n"
	.string "しかくが　なかったと　いうことか⋯⋯$"

VictoryRoad_1F_Text_HopeIntro: @ 0x08219856
	.string "この　はてしなく　けわしい　みち　こそ\n"
	.string "まさに　チャンピオンへの　みち　なのよ！$"

VictoryRoad_1F_Text_HopeDefeat: @ 0x0821987F
	.string "すばらしい　たたかいかた　ね⋯⋯$"

VictoryRoad_1F_Text_HopePostBattle: @ 0x08219890
	.string "あなたには　チャンピオンに　なれる\n"
	.string "かのうせいが　あるみたいね$"

VictoryRoad_1F_Text_QuincyIntro: @ 0x082198B0
	.string "チャンピオンロード　とは　なにか？\n"
	.string "かてたら　おしえてやろう！$"

VictoryRoad_1F_Text_QuincyDefeat: @ 0x082198D0
	.string "うん　いいだろう！$"

VictoryRoad_1F_Text_QuincyPostBattle: @ 0x082198DA
	.string "ここを　ぶじに　ぬけきるって　ことが\n"
	.string "ポケモンチャンピオンを　めざす　やつの\l"
	.string "さいごの　しれん　なんだ！\p"
	.string "だから　チャンピオンロードと\n"
	.string "よばれて　いるのさ$"

VictoryRoad_1F_Text_KatelynnIntro: @ 0x08219928
	.string "ここまで　きた　ひとに\n"
	.string "なにも　いうことは　ない⋯⋯　いくわよ！$"

VictoryRoad_1F_Text_KatelynnDefeat: @ 0x08219949
	.string "くやしいわ⋯⋯！$"

VictoryRoad_1F_Text_KatelynnPostBattle: @ 0x08219952
	.string "ふん⋯⋯　いいわよ\n"
	.string "あなた　から　さきに　いきなさいよ$"
