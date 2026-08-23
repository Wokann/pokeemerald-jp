@ SeafloorCavern_Room3 scripts (JP map g24 m30 @ 0x0821873E)

SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_SHELLY_SEAFLOOR_CAVERN, 0x0, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_GRUNT_SEAFLOOR_CAVERN_5, 0x0, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro: @ 0x0821876D
	.string "オーッホッホ！\p"
	.string "せんすいていも　ないのに\n"
	.string "よく　ここまで　おいかけて　きたわね！\l"
	.string "たいした　おこさま　だわ！\p"
	.string "でもね⋯⋯\n"
	.string "ジャマされると　めんどう　なのよね\p"
	.string "てんき　けんきゅうじょ　での\n"
	.string "かりも　かえしたいし⋯⋯\p"
	.string "ちょっと　いたい　おもい　させちゃうから\n"
	.string "かくご　しなさーい！！$"

SeafloorCavern_Room3_Text_ShellyDefeat: @ 0x082187F9
	.string "オーッホッホ！\p"
	.string "いったーい！$"

SeafloorCavern_Room3_Text_ShellyPostBattle: @ 0x08218808
	.string "オーッホッホ！\p"
	.string "あなた　そんなに　つよいんだもの\n"
	.string "アクアだんの　なかま　じゃなくて\l"
	.string "とっても　ざんねんだわ\p"
	.string "リーダーが　じつげん　してくれる\n"
	.string "すばらしい　せかいを\l"
	.string "いっしょに　たのしむことが　できたのに$"

SeafloorCavern_Room3_Text_Grunt5Intro: @ 0x0821886E
	.string "オレたちの　やぼうの　ために\n"
	.string "ポケモンは　ひつような　ものだが\p"
	.string "ポケモンの　ちからを　かりて\n"
	.string "おまえの　ような　やつが\l"
	.string "こんな　ところまで　ジャマしに　くる！\p"
	.string "よのなか　うまく　いかない　もんだ！$"

SeafloorCavern_Room3_Text_Grunt5Defeat: @ 0x082188D1
	.string "ぐはっ！$"

SeafloorCavern_Room3_Text_Grunt5PostBattle: @ 0x082188D6
	.string "オレたちが　あたまの　あがらない\n"
	.string "あの　リーダーに\p"
	.string "よくも　まあ　おまえの　ような\n"
	.string "こどもが　さからえる　もんだよな！\p"
	.string "もしかして　おまえって\n"
	.string "とんでもないやつ⋯⋯　なのか？$"
