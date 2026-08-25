@ RustboroCity_Flat1_2F scripts (JP map g11 m9 @ 0x08203770)

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	goto_if_eq VAR_0x8004, 0x1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 0x2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0x0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard: @ 0x08203886
	.string "もうね　たいへん　なのよ！\p"
	.string "なにが　たいへんって\n"
	.string "そんなの　きまってるでしょ！\p"
	.string "まいにちの　おこんだて　よッ！\p"
	.string "まいにち　まいにち　かんがえるのって\n"
	.string "ほんとうに　たいへん　なんだからッ！$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase: @ 0x082038E4
	.string "やあ　いらっしゃい\n"
	.string "ハコガミけ　へ　ようこそ！\p"
	.string "ちょっと　しつもんが　あるんだけど\n"
	.string "きみ　こもり　したこと　ある？\p"
	.string "おじさん　はじめて\n"
	.string "いくじ　してるんだけどさ\p"
	.string "うちの　アヤノ\n"
	.string "なかなか　わらって　くれないんだよね\p"
	.string "おもしろーい　ことば　で\n"
	.string "わらって　くれないかなーって\l"
	.string "おもうんだけど\l"
	.string "おもしろーい　ことば　おしえて　くれない？$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase: @ 0x0820398A
	.string "いまは　{STR_VAR_1}　って\n"
	.string "ことばを　つかってるんだけど\p"
	.string "おもしろそうな　ことば\n"
	.string "みつけて　きたの？$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion: @ 0x082039B9
	.string "そうか　そうか\n"
	.string "じゃあ　さっそく　おしえて　くれよ$"

RustboroCity_Flat1_2F_Text_OhIsThatRight: @ 0x082039D3
	.string "そうか　そうか\n"
	.string "なにか　おもしろそうな　ことばを\l"
	.string "みつけたら　おしえて　くれよ$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2: @ 0x082039FB
	.string "なるほどー\n"
	.string "じゃあ　ためして　みようかな$"

RustboroCity_Flat1_2F_Text_OhShesLaughing: @ 0x08203A10
	.string "{STR_VAR_1}\n"
	.string "{STR_VAR_1}\p"
	.string "わらってる　わらってる！\n"
	.string "なんだか　うれしいなあ$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry: @ 0x08203A2F
	.string "なるほどー\n"
	.string "じゃあ　ためして　みようかな$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll: @ 0x08203A44
	.string "{STR_VAR_1}\n"
	.string "{STR_VAR_1}\p"
	.string "うーん　わらわないなあ\n"
	.string "このこ　クール　なのかな$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase: @ 0x08203A63
	.string "いい　ことば　しらないかー\n"
	.string "じゃあ　じぶんで　かんがえるかー\p"
	.string "うーん\n"
	.string "{STR_VAR_1}　とか　どうかな\l"
	.string "よし！　ためしてみよう$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2: @ 0x08203A9D
	.string "{STR_VAR_1}\n"
	.string "{STR_VAR_1}\p"
	.string "うーん　わらわないなあ\n"
	.string "このこ　クール　なのかな$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny: @ 0x08203ABC
	.string "いい　ことば　しらないかー\n"
	.string "じゃあ　まえの　ことばで\l"
	.string "がんばって　あやすかー\p"
	.string "おもしろそうな　ことば　みつけたら\n"
	.string "おじさんに　おしえてね$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper: @ 0x08203B01
	.string "ありがとう！\p"
	.string "きみの　おかげで　アヤノが\n"
	.string "わらって　くれたよ！\p"
	.string "じつは　おじさん\n"
	.string "こう　みえても\p"
	.string "デボンコーポレーションの\n"
	.string "すごうで　けんきゅういん　なんだよ\p"
	.string "そうだなー　じゃあ　おれいに\n"
	.string "きみが　ポケモンを　あずけている\l"
	.string "ボックスの　かべがみを\l"
	.string "ふやして　あげよう！\p"
	.string "かべがみの　なかから\n"
	.string "‘だいすき’って　いうのを　えらぶと\l"
	.string "あたらしい　かべがみが　えらべるよ！$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll: @ 0x08203BB9
	.string "ポケモンの　ぬいぐるみ　だ！$"
