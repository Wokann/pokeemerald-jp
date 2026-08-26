@ MtPyre_3F scripts (JP map g24 m17 @ 0x082165F1)

MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William:: @ 0x082165F2
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla:: @ 0x08216609
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle:: @ 0x08216620
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle:: @ 0x0821664C
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle:: @ 0x0821666B
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro: @ 0x08216682
	.string "れいげん　あらたかな　やまの　ちからで\n"
	.string "サイコパワーの　アップした　わたしに\l"
	.string "こどもの　おまえが　かてるかな！？$"

MtPyre_3F_Text_WilliamDefeat: @ 0x082166BB
	.string "アップ　アップ⋯⋯$"

MtPyre_3F_Text_WilliamPostBattle: @ 0x082166C5
	.string "わたしの　サイコパワーは　かくじつに\n"
	.string "つよく　なっている　はずなのに⋯⋯$"

MtPyre_3F_Text_KaylaIntro: @ 0x082166EA
	.string "おほほほほっ！\p"
	.string "ここは　あなたの　ような　こどもが\n"
	.string "くる　ばしょ　では　ないのよっ！$"

MtPyre_3F_Text_KaylaDefeat: @ 0x08216715
	.string "あっさり　まけたわっ⋯⋯！$"

MtPyre_3F_Text_KaylaPostBattle: @ 0x08216723
	.string "まだまだ　しゅぎょうが　たりないのね⋯⋯\n"
	.string "さんちょうを　めざすわよ⋯⋯！\p"
	.string "ファイト！　わたし！$"

MtPyre_3F_Text_GabrielleIntro: @ 0x08216753
	.string "あなたは　なぜ　ここへ⋯⋯？$"

MtPyre_3F_Text_GabrielleDefeat: @ 0x08216762
	.string "すごいわ！\n"
	.string "あなたは　すてきな　トレーナーさんね$"

MtPyre_3F_Text_GabriellePostBattle: @ 0x0821677B
	.string "いまはもう　いない　ポケモン\n"
	.string "いま　いっしょに　いる　ポケモン\p"
	.string "それに\n"
	.string "これから　であう　ポケモン⋯⋯\p"
	.string "すべて　たいせつな　ポケモン　なのよ\n"
	.string "おぼえて　おいて　くださいね$"

MtPyre_3F_Text_GabrielleRegister: @ 0x082167D1
	.string "あなたの　ポケモンが　そだったら\n"
	.string "みてみたいわ⋯⋯\l"
	.string "さあ　ポケナビを　だして$"

MtPyre_3F_Text_GabrielleRematchIntro: @ 0x082167F8
	.string "あら　あなたは⋯⋯\n"
	.string "そだてた　ポケモン　みせてくれるの？$"

MtPyre_3F_Text_GabrielleRematchDefeat: @ 0x08216815
	.string "ほんとうに　すごいわ！\n"
	.string "あなたは　すてきね$"

MtPyre_3F_Text_GabriellePostRematch: @ 0x0821682B
	.string "いまはもう　いない　ポケモン\n"
	.string "いま　いっしょに　いる　ポケモン\p"
	.string "それに\n"
	.string "これから　であう　ポケモン⋯⋯\p"
	.string "すべて　たいせつな　ポケモン　なのよ\n"
	.string "おぼえて　くれて　いたのね$"
