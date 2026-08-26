@ RustboroCity_DevonCorp_2F scripts (JP map g11 m1 @ 0x08201429)

RustboroCity_DevonCorp_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
	.byte 0

RustboroCity_DevonCorp_2F_OnTransition:: @ 0x0820142F
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	end

RustboroCity_DevonCorp_2F_EventScript_SetFossilReady:: @ 0x0820143B
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
	return

RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist:: @ 0x08201441
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_BallScientist:: @ 0x08201458
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls:: @ 0x08201478
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokenavScientist:: @ 0x08201482
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_HasPokenav:: @ 0x082014A2
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist:: @ 0x082014AC
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist:: @ 0x082014C3
	lock
	faceplayer
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil
	release
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil:: @ 0x08201505
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil:: @ 0x08201546
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_ROOT_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
	release
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil:: @ 0x08201563
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil:: @ 0x082015A4
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_CLAW_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
	release
	end

RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil:: @ 0x082015C1
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_StillRegenerating:: @ 0x082015CB
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilMonReady:: @ 0x082015D5
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, RustboroCity_DevonCorp_2F_EventScript_LileepReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, RustboroCity_DevonCorp_2F_EventScript_AnorithReady
	end

RustboroCity_DevonCorp_2F_EventScript_LileepReady:: @ 0x082015EC
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep
	end

RustboroCity_DevonCorp_2F_EventScript_AnorithReady:: @ 0x082015FE
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep:: @ 0x08201610
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LILEEP
	givemon SPECIES_LILEEP, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty:: @ 0x08201640
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC:: @ 0x08201668
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
	end

RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC:: @ 0x0820168B
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare:: @ 0x08201696
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
	return

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep:: @ 0x082016A9
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith:: @ 0x082016B3
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ANORITH
	givemon SPECIES_ANORITH, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty:: @ 0x082016E3
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC:: @ 0x0820170B
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
	end

RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC:: @ 0x0820172E
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare:: @ 0x08201739
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
	return

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith:: @ 0x0820174C
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseFossil:: @ 0x08201756
	message RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne
	waitmessage
	multichoice 17, 6, MULTI_FOSSIL, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil
	case 1, RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil
	case 2, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil:: @ 0x08201793
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil:: @ 0x08201799
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
	end

RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect:: @ 0x0820179F
	release
	end

RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist:: @ 0x082017A1
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_ge VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_WorkOnNext:: @ 0x082017C3
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon: @ 0x082017CD
	.string "いま　ポケモンと　はなせる　どうぐを\n"
	.string "かいはつ　しているのですが⋯⋯\p"
	.string "なかなか　うまく　いかないね$"

RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls: @ 0x082017FF
	.string "いま　しんがたの　モンスターボールを\n"
	.string "かいはつ　しているのですが⋯⋯\p"
	.string "なかなか　うまく　いかないね$"

RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls: @ 0x08201831
	.string "しんがたの　モンスターボールが\n"
	.string "ついに　かんせい　したのです！\p"
	.string "リピートボールを　つかうと\n"
	.string "いちど　つかまえた　ポケモンが\l"
	.string "つかまえやすく　なります！\p"
	.string "タイマーボールは　ポケモンとの\n"
	.string "たたかいが　ながびけば　ながびくほど\l"
	.string "つかまえやすく　なります！\p"
	.string "どちらも　わがしゃの　じしんさく\n"
	.string "ぜひ　つかって　ください！$"

RustboroCity_DevonCorp_2F_Text_IMadePokenav: @ 0x082018CD
	.string "ポケナビを　つくったのは　わたし！\p"
	.string "いやー　あんな　すごいモノを　つくれると\n"
	.string "かいはつしゃ　みょうりに　つきますね！$"

RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav: @ 0x08201908
	.string "おお！　それは　ポケナビ！\p"
	.string "ポケモンの　きもちを　しりたい\n"
	.string "という　しゃちょうの　アイデアを\l"
	.string "じつげん　したのです！\p"
	.string "くわしい　せつめいを　しましょうか？\p"
	.string "⋯⋯　いやいや\n"
	.string "そのうちに　わかるでしょう！\l"
	.string "どんどん　ポケナビを　つかってくださいね！$"

RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams: @ 0x08201983
	.string "いま　ポケモンが　みている\n"
	.string "ゆめを　うつしだす　どうぐを\l"
	.string "かいはつ　しているのですが⋯⋯\p"
	.string "なかなか　うまく　いかないね$"

RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils: @ 0x082019BF
	.string "いま　ポケモンの　かせきを\n"
	.string "さいせい　する　そうちを\l"
	.string "かいはつ　していたのですが⋯⋯\p"
	.string "なかなか　うまく　いきましたよ！$"

RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife: @ 0x082019FB
	.string "きみの　もっている　それは\n"
	.string "ポケモンの　かせき！？\p"
	.string "よければ　わたしが　つくった\n"
	.string "カセキ　さいせい　マシンで\l"
	.string "いきかえらせて　みましょうか？$"

RustboroCity_DevonCorp_2F_Text_OhIsThatSo: @ 0x08201A42
	.string "あー　そうですか\p"
	.string "デボンの　ぎじゅつは　すごいのにな⋯⋯$"

RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne: @ 0x08201A5F
	.string "なんとまあ！\n"
	.string "かせきを　ふたつも　もってるんですか！\p"
	.string "でも　わたしの　マシンでは\n"
	.string "ひとつづつ　しか　さいせい　できません\p"
	.string "どちらの　かせきを　かして　くれますか？$"

RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher: @ 0x08201AB1
	.string "わかりました！\n"
	.string "では　さっそく⋯⋯\p"
	.string "{PLAYER}は　デボンの　けんきゅういんに\n"
	.string "{STR_VAR_1}を　あずけた！$"

RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime: @ 0x08201ADF
	.string "わたしが　つくった\n"
	.string "カセキ　さいせい　マシンは　すごいのですが\l"
	.string "じかんが　かかるのが　けってん⋯⋯\p"
	.string "すこし　そこらへんを\n"
	.string "けんがく　なされては　いかがですか？$"

RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife: @ 0x08201B2F
	.string "おまたせ　しました！\n"
	.string "カセキが　いきかえり　ましたよ！\p"
	.string "カセキは　おおむかしの　ポケモン\n"
	.string "{STR_VAR_2}　でしたよ！$"

RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher: @ 0x08201B65
	.string "{PLAYER}は　デボンの　けんきゅういんから\n"
	.string "{STR_VAR_2}を　うけとった！$"

RustboroCity_DevonCorp_2F_Text_TooManyPokemon: @ 0x08201B83
	.string "あー　ポケモン　いっぱいで\n"
	.string "もてないですね$"

RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature: @ 0x08201B99
	.string "いま　ポケナビに　ついかする　きのうを\n"
	.string "かいはつ　しているのですが⋯⋯\p"
	.string "なかなか　うまく　いかないね$"

RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext: @ 0x08201BCC
	.string "さーて　つぎは　どんな　そうちを\n"
	.string "かいはつ　しようかな⋯⋯\p"
	.string "うちの　かいしゃは　ひらめいた　アイデアを\n"
	.string "どんどん　じつげん　させて　くれるから\l"
	.string "けんきゅうしゃ　みょうりに　つきますよ！$"
