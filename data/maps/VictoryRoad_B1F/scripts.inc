@ VictoryRoad_B1F scripts (JP map g24 m44 @ 0x0821996E)

VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel:: @ 0x0821996F
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon:: @ 0x08219986
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle:: @ 0x0821999D
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell:: @ 0x082199B4
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle:: @ 0x082199CB
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro: @ 0x082199E2
	.string "ポケモンリーグに　ちかづいていると　おもうと\n"
	.string "なんだか　ドキドキ　してきたよ⋯⋯$"

VictoryRoad_B1F_Text_SamuelDefeat: @ 0x08219A0B
	.string "なにも　できなかった⋯⋯$"

VictoryRoad_B1F_Text_SamuelPostBattle: @ 0x08219A18
	.string "ポケモンリーグが　とおのいたよ⋯⋯\n"
	.string "なんだか　がっかり　するな⋯⋯$"

VictoryRoad_B1F_Text_ShannonIntro: @ 0x08219A3A
	.string "ポケモンリーグで　かちぬくには\n"
	.string "ポケモンへの　しんらいが　ひつよう　なの$"

VictoryRoad_B1F_Text_ShannonDefeat: @ 0x08219A5F
	.string "しんらい　かんけい　バッチリね！$"

VictoryRoad_B1F_Text_ShannonPostBattle: @ 0x08219A70
	.string "いつも　いっしょに　いることで\n"
	.string "ポケモンと　トレーナーとの　あいだに\l"
	.string "しんらい　かんけいが　できるの$"

VictoryRoad_B1F_Text_MichelleIntro: @ 0x08219AA3
	.string "ここは　ゴール　じゃないの\n"
	.string "ポケモンリーグへの　つうかてん　よ！$"

VictoryRoad_B1F_Text_MichelleDefeat: @ 0x08219AC4
	.string "その　ちょうし！$"

VictoryRoad_B1F_Text_MichellePostBattle: @ 0x08219ACD
	.string "あなたなら　だいじょうぶよ　きっと！\n"
	.string "ポケモンも　やるき　まんまん　だしね！$"

VictoryRoad_B1F_Text_MitchellIntro: @ 0x08219AF4
	.string "わたしの　ポケモンは　すばらしいですよ！$"

VictoryRoad_B1F_Text_MitchellDefeat: @ 0x08219B09
	.string "あなた　みたいな　かた\n"
	.string "はじめて　です$"

VictoryRoad_B1F_Text_MitchellPostBattle: @ 0x08219B1D
	.string "あなたと　あなたの　ポケモンが\n"
	.string "いっしょに　いるだけで\l"
	.string "すごい　パワーを　かんじます$"

VictoryRoad_B1F_Text_HalleIntro: @ 0x08219B48
	.string "オーケイ　そんなに　かまえないで！\n"
	.string "リラックス　して　いきましょ！$"

VictoryRoad_B1F_Text_HalleDefeat: @ 0x08219B6A
	.string "ワンダフル！$"

VictoryRoad_B1F_Text_HallePostBattle: @ 0x08219B71
	.string "チャンピオンロード　だって\n"
	.string "いままでの　みちのりと　かわらないわ\l"
	.string "のこりも　エンジョイしてね$"
