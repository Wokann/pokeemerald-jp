@ RustboroCity_DevonCorp_2F scripts (JP map g11 m1 @ 0x08201429)

RustboroCity_DevonCorp_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_EventScript_0020142F
	.byte 0

RustboroCity_DevonCorp_2F_EventScript_0020142F::
	compare_var_to_value 0x40C4, 0x1
	call_if 0x1, RustboroCity_DevonCorp_2F_EventScript_0020143B
	end

RustboroCity_DevonCorp_2F_EventScript_0020143B::
	setvar 0x40C4, 0x2
	return

RustboroCity_DevonCorp_2F_EventScript_00201441::
	lock
	faceplayer
	compare_var_to_value 0x40C4, 0x1
	call_if 0x1, RustboroCity_DevonCorp_2F_EventScript_0020143B
	loadword 0x0, gJPText_002017CD
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_00201458::
	lock
	faceplayer
	compare_var_to_value 0x40C4, 0x1
	call_if 0x1, RustboroCity_DevonCorp_2F_EventScript_0020143B
	checkflag 0x11F
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_00201478
	loadword 0x0, gJPText_002017FF
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_00201478::
	loadword 0x0, gJPText_00201831
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_00201482::
	lock
	faceplayer
	compare_var_to_value 0x40C4, 0x1
	call_if 0x1, RustboroCity_DevonCorp_2F_EventScript_0020143B
	checkflag 0xBC
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_002014A2
	loadword 0x0, gJPText_002018CD
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_002014A2::
	loadword 0x0, gJPText_00201908
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_002014AC::
	lock
	faceplayer
	compare_var_to_value 0x40C4, 0x1
	call_if 0x1, RustboroCity_DevonCorp_2F_EventScript_0020143B
	loadword 0x0, gJPText_00201983
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_002014C3::
	lock
	faceplayer
	compare_var_to_value 0x40C4, 0x2
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_002015D5
	compare_var_to_value 0x40C4, 0x1
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_002015CB
	loadword 0x0, gJPText_002019BF
	callstd 0x4
	checkitem 0x11E, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_00201505
	checkitem 0x11F, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_00201563
	release
	end

RustboroCity_DevonCorp_2F_EventScript_00201505::
	closemessage
	playse 0x15
	applymovement 0x5, 0x0824361B
	waitmovement 0x0
	applymovement 0x5, 0x0824361D
	waitmovement 0x0
	loadword 0x0, gJPText_002019FB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_002015C1
	checkitem 0x11F, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_00201756
	goto RustboroCity_DevonCorp_2F_EventScript_00201546
	end

RustboroCity_DevonCorp_2F_EventScript_00201546::
	bufferitemname 0x0, 0x11E
	loadword 0x0, gJPText_00201AB1
	callstd 0x4
	removeitem 0x11E, 0x1
	setvar 0x40C4, 0x1
	setvar 0x40C5, 0x1
	release
	end

RustboroCity_DevonCorp_2F_EventScript_00201563::
	closemessage
	playse 0x15
	applymovement 0x5, 0x0824361B
	waitmovement 0x0
	applymovement 0x5, 0x0824361D
	waitmovement 0x0
	loadword 0x0, gJPText_002019FB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_002015C1
	checkitem 0x11E, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_00201756
	goto RustboroCity_DevonCorp_2F_EventScript_002015A4
	end

RustboroCity_DevonCorp_2F_EventScript_002015A4::
	bufferitemname 0x0, 0x11F
	loadword 0x0, gJPText_00201AB1
	callstd 0x4
	removeitem 0x11F, 0x1
	setvar 0x40C4, 0x1
	setvar 0x40C5, 0x2
	release
	end

RustboroCity_DevonCorp_2F_EventScript_002015C1::
	loadword 0x0, gJPText_00201A42
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_002015CB::
	loadword 0x0, gJPText_00201ADF
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_002015D5::
	compare_var_to_value 0x40C5, 0x1
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_002015EC
	compare_var_to_value 0x40C5, 0x2
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_002015FE
	end

RustboroCity_DevonCorp_2F_EventScript_002015EC::
	bufferspeciesname 0x1, 0x184
	loadword 0x0, gJPText_00201B2F
	callstd 0x4
	goto RustboroCity_DevonCorp_2F_EventScript_00201610
	end

RustboroCity_DevonCorp_2F_EventScript_002015FE::
	bufferspeciesname 0x1, 0x186
	loadword 0x0, gJPText_00201B2F
	callstd 0x4
	goto RustboroCity_DevonCorp_2F_EventScript_002016B3
	end

RustboroCity_DevonCorp_2F_EventScript_00201610::
	setvar 0x4001, 0x184
	givemon 0x184, 0x14, 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_00201640
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_00201668
	goto 0x0824423B
	end

RustboroCity_DevonCorp_2F_EventScript_00201640::
	call RustboroCity_DevonCorp_2F_EventScript_00201696
	loadword 0x0, 0x08243EDB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_002016A9
	call 0x082441B5
	call 0x08243460
	goto RustboroCity_DevonCorp_2F_EventScript_002016A9
	end

RustboroCity_DevonCorp_2F_EventScript_00201668::
	call RustboroCity_DevonCorp_2F_EventScript_00201696
	loadword 0x0, 0x08243EDB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_0020168B
	call 0x082441C1
	goto RustboroCity_DevonCorp_2F_EventScript_0020168B
	end

RustboroCity_DevonCorp_2F_EventScript_0020168B::
	call 0x082441CA
	goto RustboroCity_DevonCorp_2F_EventScript_002016A9
	end

RustboroCity_DevonCorp_2F_EventScript_00201696::
	bufferspeciesname 0x1, 0x184
	playfanfare 0x172
	message gJPText_00201B65
	waitmessage
	waitfanfare
	bufferspeciesname 0x0, 0x184
	return

RustboroCity_DevonCorp_2F_EventScript_002016A9::
	setvar 0x40C4, 0x0
	setflag 0x10B
	release
	end

RustboroCity_DevonCorp_2F_EventScript_002016B3::
	setvar 0x4001, 0x186
	givemon 0x186, 0x14, 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_002016E3
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_0020170B
	goto 0x0824423B
	end

RustboroCity_DevonCorp_2F_EventScript_002016E3::
	call RustboroCity_DevonCorp_2F_EventScript_00201739
	loadword 0x0, 0x08243EDB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_0020174C
	call 0x082441B5
	call 0x08243460
	goto RustboroCity_DevonCorp_2F_EventScript_0020174C
	end

RustboroCity_DevonCorp_2F_EventScript_0020170B::
	call RustboroCity_DevonCorp_2F_EventScript_00201739
	loadword 0x0, 0x08243EDB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_0020172E
	call 0x082441C1
	goto RustboroCity_DevonCorp_2F_EventScript_0020172E
	end

RustboroCity_DevonCorp_2F_EventScript_0020172E::
	call 0x082441CA
	goto RustboroCity_DevonCorp_2F_EventScript_0020174C
	end

RustboroCity_DevonCorp_2F_EventScript_00201739::
	bufferspeciesname 0x1, 0x186
	playfanfare 0x172
	message gJPText_00201B65
	waitmessage
	waitfanfare
	bufferspeciesname 0x0, 0x186
	return

RustboroCity_DevonCorp_2F_EventScript_0020174C::
	setvar 0x40C4, 0x0
	setflag 0x10B
	release
	end

RustboroCity_DevonCorp_2F_EventScript_00201756::
	message gJPText_00201A5F
	waitmessage
	multichoice 0x11, 0x6, 0x5D, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_00201793
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_00201799
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_0020179F
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, RustboroCity_DevonCorp_2F_EventScript_0020179F
	end

RustboroCity_DevonCorp_2F_EventScript_00201793::
	goto RustboroCity_DevonCorp_2F_EventScript_002015A4
	end

RustboroCity_DevonCorp_2F_EventScript_00201799::
	goto RustboroCity_DevonCorp_2F_EventScript_00201546
	end

RustboroCity_DevonCorp_2F_EventScript_0020179F::
	release
	end

RustboroCity_DevonCorp_2F_EventScript_002017A1::
	lock
	faceplayer
	compare_var_to_value 0x40C4, 0x1
	call_if 0x1, RustboroCity_DevonCorp_2F_EventScript_0020143B
	compare_var_to_value 0x405A, 0x6
	goto_if 0x4, RustboroCity_DevonCorp_2F_EventScript_002017C3
	loadword 0x0, gJPText_00201B99
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_002017C3::
	loadword 0x0, gJPText_00201BCC
	callstd 0x4
	release
	end

	.globl gJPText_002017CD
gJPText_002017CD: @ 0x082017CD
	.string "いま　ポケモンと　はなせる　どうぐを\n"
	.string "かいはつ　しているのですが⋯⋯\p"
	.string "なかなか　うまく　いかないね$"

	.globl gJPText_002017FF
gJPText_002017FF: @ 0x082017FF
	.string "いま　しんがたの　モンスターボールを\n"
	.string "かいはつ　しているのですが⋯⋯\p"
	.string "なかなか　うまく　いかないね$"

	.globl gJPText_00201831
gJPText_00201831: @ 0x08201831
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

	.globl gJPText_002018CD
gJPText_002018CD: @ 0x082018CD
	.string "ポケナビを　つくったのは　わたし！\p"
	.string "いやー　あんな　すごいモノを　つくれると\n"
	.string "かいはつしゃ　みょうりに　つきますね！$"

	.globl gJPText_00201908
gJPText_00201908: @ 0x08201908
	.string "おお！　それは　ポケナビ！\p"
	.string "ポケモンの　きもちを　しりたい\n"
	.string "という　しゃちょうの　アイデアを\l"
	.string "じつげん　したのです！\p"
	.string "くわしい　せつめいを　しましょうか？\p"
	.string "⋯⋯　いやいや\n"
	.string "そのうちに　わかるでしょう！\l"
	.string "どんどん　ポケナビを　つかってくださいね！$"

	.globl gJPText_00201983
gJPText_00201983: @ 0x08201983
	.string "いま　ポケモンが　みている\n"
	.string "ゆめを　うつしだす　どうぐを\l"
	.string "かいはつ　しているのですが⋯⋯\p"
	.string "なかなか　うまく　いかないね$"

	.globl gJPText_002019BF
gJPText_002019BF: @ 0x082019BF
	.string "いま　ポケモンの　かせきを\n"
	.string "さいせい　する　そうちを\l"
	.string "かいはつ　していたのですが⋯⋯\p"
	.string "なかなか　うまく　いきましたよ！$"

	.globl gJPText_002019FB
gJPText_002019FB: @ 0x082019FB
	.string "きみの　もっている　それは\n"
	.string "ポケモンの　かせき！？\p"
	.string "よければ　わたしが　つくった\n"
	.string "カセキ　さいせい　マシンで\l"
	.string "いきかえらせて　みましょうか？$"

	.globl gJPText_00201A42
gJPText_00201A42: @ 0x08201A42
	.string "あー　そうですか\p"
	.string "デボンの　ぎじゅつは　すごいのにな⋯⋯$"

	.globl gJPText_00201A5F
gJPText_00201A5F: @ 0x08201A5F
	.string "なんとまあ！\n"
	.string "かせきを　ふたつも　もってるんですか！\p"
	.string "でも　わたしの　マシンでは\n"
	.string "ひとつづつ　しか　さいせい　できません\p"
	.string "どちらの　かせきを　かして　くれますか？$"

	.globl gJPText_00201AB1
gJPText_00201AB1: @ 0x08201AB1
	.string "わかりました！\n"
	.string "では　さっそく⋯⋯\p"
	.string "{STRING 0x01}は　デボンの　けんきゅういんに\n"
	.string "{STRING 0x02}を　あずけた！$"

	.globl gJPText_00201ADF
gJPText_00201ADF: @ 0x08201ADF
	.string "わたしが　つくった\n"
	.string "カセキ　さいせい　マシンは　すごいのですが\l"
	.string "じかんが　かかるのが　けってん⋯⋯\p"
	.string "すこし　そこらへんを\n"
	.string "けんがく　なされては　いかがですか？$"

	.globl gJPText_00201B2F
gJPText_00201B2F: @ 0x08201B2F
	.string "おまたせ　しました！\n"
	.string "カセキが　いきかえり　ましたよ！\p"
	.string "カセキは　おおむかしの　ポケモン\n"
	.string "{STRING 0x03}　でしたよ！$"

	.globl gJPText_00201B65
gJPText_00201B65: @ 0x08201B65
	.string "{STRING 0x01}は　デボンの　けんきゅういんから\n"
	.string "{STRING 0x03}を　うけとった！$"

	.globl gJPText_00201B83
gJPText_00201B83: @ 0x08201B83
	.string "あー　ポケモン　いっぱいで\n"
	.string "もてないですね$"

	.globl gJPText_00201B99
gJPText_00201B99: @ 0x08201B99
	.string "いま　ポケナビに　ついかする　きのうを\n"
	.string "かいはつ　しているのですが⋯⋯\p"
	.string "なかなか　うまく　いかないね$"

	.globl gJPText_00201BCC
gJPText_00201BCC: @ 0x08201BCC
	.string "さーて　つぎは　どんな　そうちを\n"
	.string "かいはつ　しようかな⋯⋯\p"
	.string "うちの　かいしゃは　ひらめいた　アイデアを\n"
	.string "どんどん　じつげん　させて　くれるから\l"
	.string "けんきゅうしゃ　みょうりに　つきますよ！$"
