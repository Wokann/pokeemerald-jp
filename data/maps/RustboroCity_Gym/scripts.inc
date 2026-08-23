@ RustboroCity_Gym scripts (JP map g11 m3 @ 0x082022C5)

RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_002022C6::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC, 0x109, 0x0, gJPText_00202722, gJPText_002027A3, RustboroCity_Gym_EventScript_002022FB
	specialvar 0x800D, ShouldTryRematchBattle
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, RustboroCity_Gym_EventScript_0020235D
	checkflag 0xA5
	goto_if 0x0, RustboroCity_Gym_EventScript_00202339
	loadword 0x0, gJPText_0020295A
	callstd 0x4
	release
	end

RustboroCity_Gym_EventScript_002022FB::
	message gJPText_00202830
	waitmessage
	call 0x0824310A
	loadword 0x0, gJPText_00202849
	callstd 0x4
	setflag 0x4F0
	setflag 0x867
	setvar 0x405A, 0x1
	addvar 0x4085, 0x1
	setvar 0x8008, 0x1
	call 0x08242FCF
	compare_var_to_value 0x4085, 0x6
	call_if 0x1, 0x08242F10
	goto RustboroCity_Gym_EventScript_00202339
	end

RustboroCity_Gym_EventScript_00202339::
	setorcopyvar 0x8000, 0x147
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0xA5
	loadword 0x0, gJPText_002028BA
	callstd 0x4
	release
	end

RustboroCity_Gym_EventScript_0020235D::
	trainerbattle TRAINER_BATTLE_REMATCH_DOUBLE, 0x109, 0x0, gJPText_00202ACB, gJPText_00202B2A, gJPText_00202B8B
	loadword 0x0, gJPText_00202B41
	callstd 0x6
	end

RustboroCity_Gym_EventScript_00202378::
	trainerbattle TRAINER_BATTLE_SINGLE, 0x140, 0x0, gJPText_00202612, gJPText_00202636
	loadword 0x0, gJPText_00202647
	callstd 0x6
	end

RustboroCity_Gym_EventScript_0020238F::
	trainerbattle TRAINER_BATTLE_SINGLE, 0x141, 0x0, gJPText_00202665, gJPText_0020268E
	loadword 0x0, gJPText_0020269A
	callstd 0x6
	end

RustboroCity_Gym_EventScript_002023A6::
	trainerbattle TRAINER_BATTLE_SINGLE, 0x23B, 0x0, gJPText_002026C0, gJPText_002026DB
	loadword 0x0, gJPText_002026F4
	callstd 0x6
	end

RustboroCity_Gym_EventScript_002023BD::
	lock
	faceplayer
	checkflag 0x4F0
	goto_if 0x1, RustboroCity_Gym_EventScript_002023D2
	loadword 0x0, gJPText_00202432
	callstd 0x4
	release
	end

RustboroCity_Gym_EventScript_002023D2::
	loadword 0x0, gJPText_00202581
	callstd 0x4
	release
	end

RustboroCity_Gym_EventScript_002023DC::
	lockall
	checkflag 0x867
	goto_if 0x1, RustboroCity_Gym_EventScript_002023FC
	goto RustboroCity_Gym_EventScript_00202406
	end

RustboroCity_Gym_EventScript_002023EC::
	lockall
	checkflag 0x867
	goto_if 0x1, RustboroCity_Gym_EventScript_002023FC
	goto RustboroCity_Gym_EventScript_00202406
	end

RustboroCity_Gym_EventScript_002023FC::
	loadword 0x0, gJPText_002029BA
	callstd 0x4
	releaseall
	end

RustboroCity_Gym_EventScript_00202406::
	loadword 0x0, gJPText_002029AB
	callstd 0x4
	releaseall
	end

RustboroCity_Gym_EventScript_00202410::
	lockall
	pokenavcall 0x082029DC
	waitmessage
	delay 0x1E
	playfanfare 0x1CC
	loadword 0x0, gJPText_00202AB0
	callstd 0x4
	waitfanfare
	closemessage
	delay 0x1E
	setflag 0x1D3
	clearflag 0x80
	releaseall
	end

	.globl gJPText_00202432
gJPText_00202432: @ 0x08202432
	.string "げんき　しとぉや！！\p"
	.string "いきなり　だが　きみぃ！\n"
	.string "チャンピオンを　めざして　みないか！\p"
	.string "ぼくは　トレーナー　じゃないけど\n"
	.string "かつ　ために　ばっちり\l"
	.string "アドバイス　できる！\p"
	.string "よし　きまった！　いっしょに\n"
	.string "ポケモン　チャンピオン　めざそう！\p"
	.string "トレーナーの　もくてき　といえば\n"
	.string "ジムバッジを　あつめること　だろう\l"
	.string "だが　ジムリーダーは　てごわい！\p"
	.string "そこで　ぼくの　でばん　というわけだ！\n"
	.string "きみに　ばっちり　アドバイス　するよ！\p"
	.string "ここの　ジムリーダー　ツツジは\n"
	.string "いわタイプの　ポケモンの　つかいて！\p"
	.string "いわタイプは　がんじょう　だけど\n"
	.string "みずタイプや　くさタイプの\l"
	.string "こうげきは　にがて　なんだよ！\p"
	.string "ジムリーダーに　かてたら\n"
	.string "また　ぼくに　はなしかけて　くれよ！\p"
	.string "じゃ　きばってこォー！！$"

	.globl gJPText_00202581
gJPText_00202581: @ 0x08202581
	.string "うおォ！　みごとな　しょうり！！\n"
	.string "ぼくの　おうえんが　よかったのか！？\p"
	.string "よし！　きみの\n"
	.string "トレーナーカードを　みたまえ！\p"
	.string "さっき　てにいれた　ストーンバッジが\n"
	.string "きちんと　きろく　されている　だろう\p"
	.string "つまり⋯⋯\p"
	.string "きみは　チャンピオンへの　かいだんを\n"
	.string "いっぽ　のぼったんだ！\p"
	.string "ごったましィー！！$"

	.globl gJPText_00202612
gJPText_00202612: @ 0x08202612
	.string "ジム　トレーナーを　なめるなよ！\n"
	.string "じつりょくの　ちがいを　みせてやる！$"

	.globl gJPText_00202636
gJPText_00202636: @ 0x08202636
	.string "じつりょくが　ちがいすぎた⋯⋯！$"

	.globl gJPText_00202647
gJPText_00202647: @ 0x08202647
	.string "いわタイプの　おそろしさ\n"
	.string "まだまだ　こんな　ものじゃない！$"

	.globl gJPText_00202665
gJPText_00202665: @ 0x08202665
	.string "ボクに　かてる　じつりょくが　ないと\n"
	.string "ツツジさん　には　ぜったい　かなわないよ！$"

	.globl gJPText_0020268E
gJPText_0020268E: @ 0x0820268E
	.string "すごい　じつりょくだ！$"

	.globl gJPText_0020269A
gJPText_0020269A: @ 0x0820269A
	.string "ツツジさんは　ボクの　すうばい　つよい！\n"
	.string "ゆだん　しない　ほうが　いいよ！$"

	.globl gJPText_002026C0
gJPText_002026C0: @ 0x082026C0
	.string "こんな　まちなか　でも\n"
	.string "いわタイプで　おおあばれだ！$"

	.globl gJPText_002026DB
gJPText_002026DB: @ 0x082026DB
	.string "おおーっ！\n"
	.string "いきの　いい　ちょうせんしゃ　だな！$"

	.globl gJPText_002026F4
gJPText_002026F4: @ 0x082026F4
	.string "わかくして　いわタイプに\n"
	.string "めを　つける　なんて\l"
	.string "うちの　ジムリーダーは　センスが　いいぜ！$"

	.globl gJPText_00202722
gJPText_00202722: @ 0x08202722
	.string "わたくし　カナズミ　ポケモンジム\n"
	.string "リーダーの　ツツジ　といいます\p"
	.string "トレーナーズ　スクールで\n"
	.string "まなんだこと　しょうぶに　いかしたくて\l"
	.string "ジムリーダーに　なったの\p"
	.string "あなた　どのような　ポケモンで\n"
	.string "どんなふうに　たたかうのか\l"
	.string "わたくしに　おしえて　くださるかしら？$"

	.globl gJPText_002027A3
gJPText_002027A3: @ 0x082027A3
	.string "わたくし　まけたのね⋯⋯\p"
	.string "もっと　おおくの　ことを\n"
	.string "まなぶ　ひつようが　あるみたい⋯⋯\p"
	.string "わかりましたわ\p"
	.string "ポケモンリーグの　きまりでは\n"
	.string "ジムリーダーに　かった　トレーナーに\l"
	.string "これを　わたすことに　なっています\p"
	.string "どうぞ　ポケモンリーグ　こうにんの\n"
	.string "ストーンバッジ　うけとって　ください$"

	.globl gJPText_00202830
gJPText_00202830: @ 0x08202830
	.string "{STRING 0x01}は　ツツジから\n"
	.string "ストーンバッジを　もらった！$"

	.globl gJPText_00202849
gJPText_00202849: @ 0x08202849
	.string "ストーンバッジ　には　あなたの\n"
	.string "ポケモンの　こうげきりょくを\l"
	.string "たかめる　こうかが　あるの\p"
	.string "あと　たたかっていない　ときでも\n"
	.string "ひでんわざの　いあいぎり　が\l"
	.string "つかえるようにも　なるわ\p"
	.string "それから⋯⋯\n"
	.string "これも　もっていって　ください$"

	.globl gJPText_002028BA
gJPText_002028BA: @ 0x082028BA
	.string "その　わざマシン39の　なかには\n"
	.string "がんせきふうじが　はいっているわ\p"
	.string "いわを　あいてに　むかって　おとして\n"
	.string "ダメージを　あたえる　だけでなくて\l"
	.string "すばやさも　さげる　わざ　なの\p"
	.string "ちなみに\n"
	.string "わざマシンを　つかえば　ポケモンに\l"
	.string "いっしゅんで　わざを　おしえられるの\p"
	.string "ただし　つかいすて　だから\n"
	.string "つかうときは　よく　かんがえてね$"

	.globl gJPText_0020295A
gJPText_0020295A: @ 0x0820295A
	.string "それだけ　つよいなら\n"
	.string "ほかの　ポケモンジムにも\l"
	.string "ちょうせん　したら　どうかしら？\p"
	.string "おおくの　トレーナーと\n"
	.string "しょうぶを　することで\l"
	.string "さまざまなこと　まなべるはずよ$"

	.globl gJPText_002029AB
gJPText_002029AB: @ 0x082029AB
	.string "カナズミシティ　ポケモンジム$"

	.globl gJPText_002029BA
gJPText_002029BA: @ 0x082029BA
	.string "カナズミシティ　ポケモンジム\p"
	.string "ツツジ　にんてい　トレーナー！\n"
	.string "{STRING 0x01}$"

	.globl gJPText_002029DC
gJPText_002029DC: @ 0x082029DC
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯　ピッ！\p"
	.string "ツツジ“あっ　{STRING 0x01}さん　ですか？\n"
	.string "わたくし　カナズミの　ツツジです！\p"
	.string "トウキさんから　ききましたよぉ\n"
	.string "あなた　すごい　いきおいで\l"
	.string "かちすすんで　いるらしい　ですね！\p"
	.string "こちらも　まけっぱなしでは　いられません\n"
	.string "もういちど　ジムを　きたえなおして\l"
	.string "いつかまた　ちょうせんを　うけますよ！\p"
	.string "そのひが　くるのを\n"
	.string "どうぞ　まっていて　くださいね！\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯　ツー$"

	.globl gJPText_00202AB0
gJPText_00202AB0: @ 0x08202AB0
	.string "ジムリーダー　ツツジを\n"
	.string "ポケナビに　とうろく　した！$"

	.globl gJPText_00202ACB
gJPText_00202ACB: @ 0x08202ACB
	.string "ツツジ“また　おめにかかれましたね\n"
	.string "ジムリーダーの　ツツジ　です\p"
	.string "あれから　おたがいに\n"
	.string "いくつもの　しょうぶを　けいけんし\l"
	.string "どれほど　つよく　なれたのか⋯⋯\p"
	.string "さあ　おてあわせ　ねがいます！$"

	.globl gJPText_00202B2A
gJPText_00202B2A: @ 0x08202B2A
	.string "くうぅ⋯⋯\n"
	.string "またしても　わたくしの　まけ⋯⋯$"

	.globl gJPText_00202B41
gJPText_00202B41: @ 0x08202B41
	.string "ツツジ“まだまだ　ポケモン　しょうぶは\n"
	.string "まなぶことが　たくさん　あるのですね\p"
	.string "わたくし⋯⋯　ポケモン　しょうぶが\n"
	.string "ますます　すきに　なりましたよ！$"

	.globl gJPText_00202B8B
gJPText_00202B8B: @ 0x08202B8B
	.string "ツツジ“また　おめにかかれましたね\n"
	.string "ジムリーダーの　ツツジ　です\p"
	.string "あれから　おたがいに\n"
	.string "いくつもの　しょうぶを　けいけんし\l"
	.string "どれほど　つよく　なれたのか⋯⋯\p"
	.string "⋯⋯あら？　たたかえる　ポケモンを\n"
	.string "1ひきしか　もっていませんね\p"
	.string "どうぞ　2ひき　いじょうの\n"
	.string "ポケモンを　もって　きてください$"
