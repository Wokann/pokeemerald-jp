@ SootopolisCity_Gym_B1F scripts (JP map g15 m1 @ 0x0820EAC6)

SootopolisCity_Gym_B1F_MapScripts::
	.byte 0

SootopolisCity_Gym_B1F_EventScript_Andrea:: @ 0x0820EAC7
	trainerbattle_single TRAINER_ANDREA, SootopolisCity_Gym_B1F_Text_AndreaIntro, SootopolisCity_Gym_B1F_Text_AndreaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Crissy:: @ 0x0820EADE
	trainerbattle_single TRAINER_CRISSY, SootopolisCity_Gym_B1F_Text_CrissyIntro, SootopolisCity_Gym_B1F_Text_CrissyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Brianna:: @ 0x0820EAF5
	trainerbattle_single TRAINER_BRIANNA, SootopolisCity_Gym_B1F_Text_BriannaIntro, SootopolisCity_Gym_B1F_Text_BriannaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Connie:: @ 0x0820EB0C
	trainerbattle_single TRAINER_CONNIE, SootopolisCity_Gym_B1F_Text_ConnieIntro, SootopolisCity_Gym_B1F_Text_ConnieDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bridget:: @ 0x0820EB23
	trainerbattle_single TRAINER_BRIDGET, SootopolisCity_Gym_B1F_Text_BridgetIntro, SootopolisCity_Gym_B1F_Text_BridgetDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Olivia:: @ 0x0820EB3A
	trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Tiffany:: @ 0x0820EB51
	trainerbattle_single TRAINER_TIFFANY, SootopolisCity_Gym_B1F_Text_TiffanyIntro, SootopolisCity_Gym_B1F_Text_TiffanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bethany:: @ 0x0820EB68
	trainerbattle_single TRAINER_BETHANY, SootopolisCity_Gym_B1F_Text_BethanyIntro, SootopolisCity_Gym_B1F_Text_BethanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Annika:: @ 0x0820EB7F
	trainerbattle_single TRAINER_ANNIKA, SootopolisCity_Gym_B1F_Text_AnnikaIntro, SootopolisCity_Gym_B1F_Text_AnnikaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Daphne:: @ 0x0820EB96
	trainerbattle_single TRAINER_DAPHNE, SootopolisCity_Gym_B1F_Text_DaphneIntro, SootopolisCity_Gym_B1F_Text_DaphneDefeat
	msgbox SootopolisCity_Gym_B1F_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_AndreaIntro: @ 0x0820EBAD
	.string "ジムリーダー　アダンさまに　おしえてもらった\n"
	.string "かれいな　テクニックを　みせたげる！$"

SootopolisCity_Gym_B1F_Text_AndreaDefeat: @ 0x0820EBD7
	.string "アダンさま　ごめんね⋯⋯$"

SootopolisCity_Gym_B1F_Text_AndreaPostBattle: @ 0x0820EBE4
	.string "すべての　ゆかに　ヒビを　いれると\n"
	.string "なにかが　おこるわよ$"

SootopolisCity_Gym_B1F_Text_CrissyIntro: @ 0x0820EC01
	.string "せっかく　ここまで　これたのに\n"
	.string "あたしに　まけるから\l"
	.string "アダンさまに　あえないわね！$"

SootopolisCity_Gym_B1F_Text_CrissyDefeat: @ 0x0820EC2B
	.string "つよい　じゃない！！\n"
	.string "かわいい　みために　だまされたわ$"

SootopolisCity_Gym_B1F_Text_CrissyPostBattle: @ 0x0820EC47
	.string "あなたなら　アダンさまと　たたかっても\n"
	.string "いちげきで　やられなくて　すむかもね$"

SootopolisCity_Gym_B1F_Text_DaphneIntro: @ 0x0820EC6E
	.string "アダンさまの　たたかう　すがた⋯⋯\p"
	.string "その　うつくしさに　こころ　うばわれ\n"
	.string "わたくしも　ポケモンを　はじめましてよ$"

SootopolisCity_Gym_B1F_Text_DaphneDefeat: @ 0x0820ECA7
	.string "たたかう　すがたの\n"
	.string "うつくしさで　まけましたわ⋯⋯$"

SootopolisCity_Gym_B1F_Text_DaphnePostBattle: @ 0x0820ECC1
	.string "あなたさまの　たたかう　すがたも\n"
	.string "すばらしくってよ\p"
	.string "ああっ⋯⋯！\n"
	.string "ポケモンに　であえて　よかったですわ$"

SootopolisCity_Gym_B1F_Text_ConnieIntro: @ 0x0820ECF5
	.string "おねえさんが　しょうぶの　きびしさ\n"
	.string "いろいろと　おしえて　あげちゃおっかな$"

SootopolisCity_Gym_B1F_Text_ConnieDefeat: @ 0x0820ED1B
	.string "なんだ\n"
	.string "つよいんだ$"

SootopolisCity_Gym_B1F_Text_ConniePostBattle: @ 0x0820ED25
	.string "いいこと　おしえて　あげるね\p"
	.string "アダンさまに　あいたいのなら\n"
	.string "すべての　ゆかを　1かいずつ\l"
	.string "あるいて　いけば　いいの$"

SootopolisCity_Gym_B1F_Text_BridgetIntro: @ 0x0820ED5F
	.string "ホウエンちほうで　いちばん\n"
	.string "レベルの　たかい　ポケモンジム⋯⋯\p"
	.string "それが　ここ　ルネジムよ！$"

SootopolisCity_Gym_B1F_Text_BridgetDefeat: @ 0x0820ED8D
	.string "なんて　レベルの　たかい⋯⋯$"

SootopolisCity_Gym_B1F_Text_BridgetPostBattle: @ 0x0820ED9C
	.string "レベルの　たかい　ジムに　いることに\n"
	.string "まんぞく　しないで\l"
	.string "ほかにも　しゅぎょうに　いくほうが\l"
	.string "つよくなれそうだし　なにより　たのしそうね$"

SootopolisCity_Gym_B1F_Text_OliviaIntro: @ 0x0820EDE1
	.string "アダンさまと　いっしょに\n"
	.string "ポケモンを　きたえて　いるの\p"
	.string "かんたんに　たおせると　おもわないでね$"

SootopolisCity_Gym_B1F_Text_OliviaDefeat: @ 0x0820EE11
	.string "たおされちゃった⋯⋯$"

SootopolisCity_Gym_B1F_Text_OliviaPostBattle: @ 0x0820EE1C
	.string "あなた　みどころ　あると　おもうの\n"
	.string "いっしょに　ここで　ポケモン　きたえない？$"

SootopolisCity_Gym_B1F_Text_TiffanyIntro: @ 0x0820EE44
	.string "こおりの　うえでの　ひとふでがき\p"
	.string "それが　できる　トレーナーは\n"
	.string "エレガントに　うつくしいのよ！$"

SootopolisCity_Gym_B1F_Text_TiffanyDefeat: @ 0x0820EE74
	.string "ちょっとー！？$"

SootopolisCity_Gym_B1F_Text_TiffanyPostBattle: @ 0x0820EE7C
	.string "あたりまえ　だけど\n"
	.string "ポケモンの　つよさに\l"
	.string "おとなも　こどもも　かんけい　ないよ$"

SootopolisCity_Gym_B1F_Text_BethanyIntro: @ 0x0820EEA4
	.string "ポケモンと　いっしょに　いると\n"
	.string "じかんが　あっ　というまに　すぎるのよ！$"

SootopolisCity_Gym_B1F_Text_BethanyDefeat: @ 0x0820EEC9
	.string "あっ！$"

SootopolisCity_Gym_B1F_Text_BethanyPostBattle: @ 0x0820EECD
	.string "まけた　しょうぶも\n"
	.string "あっ　というまに　わすれたい⋯⋯$"

SootopolisCity_Gym_B1F_Text_AnnikaIntro: @ 0x0820EEE8
	.string "すっごく　めずらしい　ポケモンちゃんで\n"
	.string "たたかって　あげても　いいわよー！$"

SootopolisCity_Gym_B1F_Text_AnnikaDefeat: @ 0x0820EF0E
	.string "ちょっと！\n"
	.string "ポケモンちゃんも　ちゃんと　みてくれた？$"

SootopolisCity_Gym_B1F_Text_AnnikaPostBattle: @ 0x0820EF29
	.string "わたしが　このジムに　いるのは\n"
	.string "アダンさんが　わたしの　ポケモンちゃんを\l"
	.string "ほめて　くれたから　なのよぉ\p"
	.string "あーあ　ダンナに　であうまえに\n"
	.string "アダンさんに　であっていれば　いまごろは⋯$"

SootopolisCity_Gym_B1F_Text_BriannaIntro: @ 0x0820EF83
	.string "うふふ⋯⋯\n"
	.string "その　ひっしな　おかおが　ステキよ$"

SootopolisCity_Gym_B1F_Text_BriannaDefeat: @ 0x0820EF9B
	.string "あら\n"
	.string "てかげん　しすぎて　しまいましたわ⋯⋯$"

SootopolisCity_Gym_B1F_Text_BriannaPostBattle: @ 0x0820EFB2
	.string "あなたでは　アダンさまには\n"
	.string "きっと　はが　たちませんわよ　うふふ⋯⋯$"
