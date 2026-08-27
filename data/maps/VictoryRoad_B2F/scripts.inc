@ VictoryRoad_B2F scripts (JP map g24 m45 @ 0x08219BA0)

VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito:: @ 0x08219BA1
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen:: @ 0x08219BB8
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline:: @ 0x08219BCF
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie:: @ 0x08219BE6
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix:: @ 0x08219BFD
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne:: @ 0x08219C14
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro: @ 0x08219C2B
	.string "かぞく　ぜんいんで\n"
	.string "ポケモンの　しゅぎょうを　してたんだ！\l"
	.string "だれにも　まけないぜ！$"

VictoryRoad_B2F_Text_VitoDefeat: @ 0x08219C55
	.string "おれの　かぞく　より　つよい！？\n"
	.string "そんなことって　あるのか！？$"

VictoryRoad_B2F_Text_VitoPostBattle: @ 0x08219C75
	.string "かぞくの　だれよりも　つよかった　おれ⋯⋯\n"
	.string "いままで　だれにも　まけなかった　おれ⋯⋯\p"
	.string "だけど　じしん　なくしちゃったよ\n"
	.string "いえに　かえろうかなあ$"

VictoryRoad_B2F_Text_OwenIntro: @ 0x08219CBE
	.string "つよい　こどもが　いるって　ウワサだ！\n"
	.string "それって　きみの　ことかい？$"

VictoryRoad_B2F_Text_OwenDefeat: @ 0x08219CE1
	.string "たしかに　つよい！$"

VictoryRoad_B2F_Text_OwenPostBattle: @ 0x08219CEB
	.string "おれが　きいた　ウワサだと\n"
	.string "その　つよい　こども　ってのは\l"
	.string "トウカ　しゅっしん　らしいな！$"

VictoryRoad_B2F_Text_CarolineIntro: @ 0x08219D19
	.string "そろそろ　へばって　きたかな？$"

VictoryRoad_B2F_Text_CarolineDefeat: @ 0x08219D29
	.string "ぜんぜん　へばってないわ！$"

VictoryRoad_B2F_Text_CarolinePostBattle: @ 0x08219D37
	.string "この　チャンピオンロードも\n"
	.string "ポケモンリーグも　ながちょうば！\l"
	.string "たいりょくには　ちゅうい　してね！$"

VictoryRoad_B2F_Text_JulieIntro: @ 0x08219D68
	.string "ジムバッジを　たくさん　もってるからって\n"
	.string "ゆだん　しないでよ\l"
	.string "うえには　うえが　いるんだから！$"

VictoryRoad_B2F_Text_JulieDefeat: @ 0x08219D98
	.string "あなたの　ほうが　うえね！$"

VictoryRoad_B2F_Text_JuliePostBattle: @ 0x08219DA6
	.string "じぶんの　あつめた　ジムバッジを　みて\n"
	.string "いままでの　トレーナーを　おもいだすのよ$"

VictoryRoad_B2F_Text_FelixIntro: @ 0x08219DCF
	.string "ここまで　きて\n"
	.string "きんちょう　して　おなかが　いたいんです！$"

VictoryRoad_B2F_Text_FelixDefeat: @ 0x08219DED
	.string "ああ\n"
	.string "⋯⋯いたい$"

VictoryRoad_B2F_Text_FelixPostBattle: @ 0x08219DF6
	.string "もうすぐ　ポケモンリーグと　おもうと\n"
	.string "きんちょう　して　きんちょう　して！\l"
	.string "みため　ごまかすのが　せいいっぱい　です$"

VictoryRoad_B2F_Text_DianneIntro: @ 0x08219E31
	.string "エリート　ちゅうの　エリートが　あつまる\n"
	.string "この　どうくつは　どうかしら？$"

VictoryRoad_B2F_Text_DianneDefeat: @ 0x08219E56
	.string "ぜんぜん　どうじて　いないわ⋯⋯！$"

VictoryRoad_B2F_Text_DiannePostBattle: @ 0x08219E68
	.string "あなた　どきょうが　あるのね\n"
	.string "きにいったわ　がんばって！$"
