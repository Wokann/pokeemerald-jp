@ SlateportCity_OceanicMuseum_1F scripts (JP map g9 m7 @ 0x081FCA3E)

SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_001FCA3F::
	loadword 0x0, gJPText_001FCCC1
	callstd 0x2
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCA48::
	lockall
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	goto SlateportCity_OceanicMuseum_1F_EventScript_001FCA6A
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCA59::
	lockall
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	goto SlateportCity_OceanicMuseum_1F_EventScript_001FCA6A
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCA6A::
	showmoneybox 0x0, 0x0, 0x0
	loadword 0x0, gJPText_001FCC7E
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, SlateportCity_OceanicMuseum_1F_EventScript_001FCA91
	closemessage
	hidemoneybox
	applymovement 0xFF, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0x0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCA91::
	checkmoney 0x32, 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SlateportCity_OceanicMuseum_1F_EventScript_001FCAC1
	playse 0x5F
	takemoney 0x32, 0x0
	updatemoneybox 0x0
	loadword 0x0, gJPText_001FCCC1
	callstd 0x4
	setvar 0x40AA, 0x1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCAC1::
	checkflag 0x95
	goto_if 0x0, SlateportCity_OceanicMuseum_1F_EventScript_001FCAE2
	loadword 0x0, gJPText_001FCCCC
	callstd 0x4
	closemessage
	hidemoneybox
	applymovement 0xFF, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0x0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCAE2::
	loadword 0x0, gJPText_001FCCDD
	callstd 0x4
	setvar 0x40AA, 0x1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_001FCAF6::
	loadword 0x0, gJPText_001FCD12
	callstd 0x2
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCAFF::
	loadword 0x0, gJPText_001FCD2D
	callstd 0x2
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB08::
	loadword 0x0, gJPText_001FCD60
	callstd 0x2
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB11::
	loadword 0x0, gJPText_001FCD7C
	callstd 0x3
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB1A::
	loadword 0x0, gJPText_001FCD97
	callstd 0x2
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB23::
	loadword 0x0, gJPText_001FCDBB
	callstd 0x2
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB2C::
	loadword 0x0, gJPText_001FCF51
	callstd 0x3
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB35::
	loadword 0x0, gJPText_001FCF9B
	callstd 0x3
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB3E::
	loadword 0x0, gJPText_001FCFEB
	callstd 0x3
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB47::
	loadword 0x0, gJPText_001FD062
	callstd 0x3
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB50::
	loadword 0x0, gJPText_001FD0D7
	callstd 0x3
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB59::
	loadword 0x0, gJPText_001FD16B
	callstd 0x3
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB62::
	loadword 0x0, gJPText_001FD1EA
	callstd 0x3
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB6B::
	loadword 0x0, gJPText_001FD258
	callstd 0x3
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB74::
	loadword 0x0, gJPText_001FD2CF
	callstd 0x3
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB7D::
	loadword 0x0, gJPText_001FCDDF
	callstd 0x2
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB86::
	loadword 0x0, gJPText_001FCE00
	callstd 0x2
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB8F::
	loadword 0x0, gJPText_001FCE4A
	callstd 0x2
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCB98::
	loadword 0x0, gJPText_001FCE86
	callstd 0x2
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCBA1::
	lock
	faceplayer
	delay 0x8
	playse 0x15
	applymovement 0xD, 0x0824361B
	waitmovement 0x0
	applymovement 0xD, 0x0824361D
	waitmovement 0x0
	loadword 0x0, gJPText_001FCEBA
	callstd 0x4
	setorcopyvar 0x8000, 0x14E
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SlateportCity_OceanicMuseum_1F_EventScript_001FCC5E
	setflag 0x10D
	loadword 0x0, gJPText_001FCF12
	callstd 0x4
	closemessage
	compare_var_to_value 0x800C, 0x2
	goto_if 0x1, SlateportCity_OceanicMuseum_1F_EventScript_001FCC15
	compare_var_to_value 0x800C, 0x1
	goto_if 0x1, SlateportCity_OceanicMuseum_1F_EventScript_001FCC2C
	compare_var_to_value 0x800C, 0x3
	goto_if 0x1, SlateportCity_OceanicMuseum_1F_EventScript_001FCC3C
	compare_var_to_value 0x800C, 0x4
	goto_if 0x1, SlateportCity_OceanicMuseum_1F_EventScript_001FCC3C
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCC15::
	applymovement 0xFF, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement 0xD, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0x0
	goto SlateportCity_OceanicMuseum_1F_EventScript_001FCC53
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCC2C::
	applymovement 0xD, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0x0
	goto SlateportCity_OceanicMuseum_1F_EventScript_001FCC53
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCC3C::
	applymovement 0xFF, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement 0xD, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0x0
	goto SlateportCity_OceanicMuseum_1F_EventScript_001FCC53
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCC53::
	setflag 0x3C5
	playse 0x9
	removeobject 0xD
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_001FCC5E::
	loadword 0x0, gJPText_001FCF3A
	callstd 0x4
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

	.globl gJPText_001FCC7E
gJPText_001FCC7E: @ 0x081FCC7E
	.string "うみの　かがく　はくぶつかんへ\n"
	.string "ようこそ　いらっしゃいませ！\p"
	.string "にゅうじょうりょう　50えんに　なります\n"
	.string "けんがく　して　いきますか？$"

	.globl gJPText_001FCCC1
gJPText_001FCCC1: @ 0x081FCCC1
	.string "ごゆっくり　どうぞ！$"

	.globl gJPText_001FCCCC
gJPText_001FCCCC: @ 0x081FCCCC
	.string "⋯⋯あら　おかねが　たりませんわ$"

	.globl gJPText_001FCCDD
gJPText_001FCCDD: @ 0x081FCCDD
	.string "⋯⋯あら　さっきの　だんたいさん？\n"
	.string "あなただけ　おくれちゃって　しかたないわね\l"
	.string "はやく　とおっちゃって！$"

	.globl gJPText_001FCD12
gJPText_001FCD12: @ 0x081FCD12
	.string "みんなの　ために\n"
	.string "われわれ　アクアだんは　いるのよ！$"

	.globl gJPText_001FCD2D
gJPText_001FCD2D: @ 0x081FCD2D
	.string "げんちしゅうごう　で\n"
	.string "ここに　あつまったのは　いいけど⋯⋯\p"
	.string "かんじんの　リーダーが　まだ　こないんだ$"

	.globl gJPText_001FCD60
gJPText_001FCD60: @ 0x081FCD60
	.string "ここに　おいてある　もの\n"
	.string "かっぱらうと　もうかるかな？$"

	.globl gJPText_001FCD7C
gJPText_001FCD7C: @ 0x081FCD7C
	.string "この　ちしきを　いかして\n"
	.string "わるいこと　してやるか⋯⋯$"

	.globl gJPText_001FCD97
gJPText_001FCD97: @ 0x081FCD97
	.string "なかまが　カナズミで　ドジらなければ\n"
	.string "ここに　こなくて　すんだのによ！$"

	.globl gJPText_001FCDBB
gJPText_001FCDBB: @ 0x081FCDBB
	.string "さっき　50えんが　なくて\n"
	.string "うけつけで　すごい　じかん　かかったよ⋯⋯$"

	.globl gJPText_001FCDDF
gJPText_001FCDDF: @ 0x081FCDDF
	.string "うみのこと　べんきょう　して\n"
	.string "ポケモンしょうぶに　やくだてたいの$"

	.globl gJPText_001FCE00
gJPText_001FCE00: @ 0x081FCE00
	.string "わたくしッ\n"
	.string "うみを　みると　こうふん　するのですッ！\p"
	.string "そんな　わたくしに　とって\n"
	.string "クスノキかんちょうは\l"
	.string "あこがれの　ひと　ナンバー1　なのですッ！$"

	.globl gJPText_001FCE4A
gJPText_001FCE4A: @ 0x081FCE4A
	.string "うみは　はてしなく　ひろく\n"
	.string "どこまでも　ふかい⋯⋯\p"
	.string "きっと　われわれが　しらない　ポケモンも\n"
	.string "いっぱい　いるのだろうね$"

	.globl gJPText_001FCE86
gJPText_001FCE86: @ 0x081FCE86
	.string "あたし　うみの　ポケモンが　ほしいの\p"
	.string "だって　ひんやりと　してて\n"
	.string "だきしめたら　きもちよさそう　だもの$"

	.globl gJPText_001FCEBA
gJPText_001FCEBA: @ 0x081FCEBA
	.string "ひえー！！\n"
	.string "なんで　おまえ　ここに　いるんだよ！？\p"
	.string "おれ？　おれは　カナシダ　トンネルで\n"
	.string "おまえに　コテンパンに　された\l"
	.string "アクアだん　だよ\p"
	.string "これを　やるから　ゆるしてくれよ！$"

	.globl gJPText_001FCF12
gJPText_001FCF12: @ 0x081FCF12
	.string "その　わざマシン\n"
	.string "おれより　おまえのほうが　にあうぜ！\p"
	.string "じゃあな　わはははー！$"

	.globl gJPText_001FCF3A
gJPText_001FCF3A: @ 0x081FCF3A
	.string "たのむから\n"
	.string "なんとかして　うけとってくれよ！$"

	.globl gJPText_001FCF51
gJPText_001FCF51: @ 0x081FCF51
	.string "ガラスの　なかで　あおい　みずが\n"
	.string "くるくると　まわって　いる！\p"
	.string "‘これは　かぜの　ちからで　じんこうてきに\n"
	.string "　うずしおを　おこす　じっけん　です’$"

	.globl gJPText_001FCF9B
gJPText_001FCF9B: @ 0x081FCF9B
	.string "ガラスの　なかで　あかい　ボールが\n"
	.string "うかんだり　しずんだり　している！\p"
	.string "‘これは　ボールの　ふりょくを　りようした\n"
	.string "　たきのぼりの　げんりの　じっけん　です’$"

	.globl gJPText_001FCFEB
gJPText_001FCFEB: @ 0x081FCFEB
	.string "うみの　そこの　つちの　みほんだ！\p"
	.string "‘かいていには　ながい　ねんげつを　かけて\n"
	.string "　せいぶつの　しがいが　ふりつもり\l"
	.string "　ちそうが　かたち　づくられて　いきます’\p"
	.string "‘これらを　ぶんせき　することで\n"
	.string "　とおい　むかしの　ことが　わかるのです’$"

	.globl gJPText_001FD062
gJPText_001FD062: @ 0x081FD062
	.string "うみべの　すなの　みほんだ！\p"
	.string "‘やまから　かわを　つたって　きた　いしは\n"
	.string "　みずの　なかで　ころがる　うちに\l"
	.string "　くだかれたり　けずれたり　していきます’\p"
	.string "‘それらが　ちいさな　つぶに　なって\n"
	.string "　うみべの　すなが　できて　いくのです’$"

	.globl gJPText_001FD0D7
gJPText_001FD0D7: @ 0x081FD0D7
	.string "‘うみの　まめちしき　その1\n"
	.string "　なぜ　うみの　みずは　あおいの？’\p"
	.string "‘ひかりには　いくつもの　いろが　あって\n"
	.string "　ほとんどの　ひかりは　みずに　はいると\l"
	.string "　その　いろが　なくなって　いきます’\p"
	.string "‘けれど　あおい　ひかり　だけは\n"
	.string "　そのままの　いろで　のこる　ため\l"
	.string "　うみは　あおく　みえるのです’$"

	.globl gJPText_001FD16B
gJPText_001FD16B: @ 0x081FD16B
	.string "‘うみの　まめちしき　その2\n"
	.string "　なぜ　うみの　みずは　しょっぱいの？’\p"
	.string "‘かいすい　には　いわから　にじみでた\p"
	.string "　しおの　もとに　なる\n"
	.string "　ナトリウムイオン　と　えんそイオン\l"
	.string "　という　ぶっしつが　おおく　ふくまれ\l"
	.string "　だから　なめると　しょっぱいのです’$"

	.globl gJPText_001FD1EA
gJPText_001FD1EA: @ 0x081FD1EA
	.string "‘うみの　まめちしき　その3\n"
	.string "　うみと　りくは　どちらが　ひろいの？’\p"
	.string "‘だいたい　うみが　70パーセントで\n"
	.string "　りくが　30パーセント　くらいです\p"
	.string "　りくちに　くらべて　うみは\n"
	.string "　その　2ばい　いじょうも　あるのです’$"

	.globl gJPText_001FD258
gJPText_001FD258: @ 0x081FD258
	.string "デコボコに　なみうった　かせきが　ある！\p"
	.string "‘うみの　そこに　たまった　つちには\n"
	.string "　かいすいが　ながれる　えいきょうで\l"
	.string "　なみの　ような　もようが　できます’\p"
	.string "‘それが　そのまま　かせきに　なったものを\n"
	.string "　リップルマークと　よんでいます’$"

	.globl gJPText_001FD2CF
gJPText_001FD2CF: @ 0x081FD2CF
	.string "まるい　ドームの　なかで　なんだか\n"
	.string "よく　わからない　きかいが　まわってる！\p"
	.string "なにかの　ふかさを　しらべるのかな？$"
