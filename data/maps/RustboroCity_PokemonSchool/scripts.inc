@ RustboroCity_PokemonSchool scripts (JP map g11 m4 @ 0x08202C1A)

RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_00202C1B::
	lockall
	loadword 0x0, gJPText_00202E24
	callstd 0x4
	goto RustboroCity_PokemonSchool_EventScript_00202C2A
	end

RustboroCity_PokemonSchool_EventScript_00202C2A::
	message gJPText_00202E54
	waitmessage
	multichoicegrid 0x8, 0x1, 0xD, 0x3, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, RustboroCity_PokemonSchool_EventScript_00202C89
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, RustboroCity_PokemonSchool_EventScript_00202C97
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, RustboroCity_PokemonSchool_EventScript_00202CA5
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, RustboroCity_PokemonSchool_EventScript_00202CB3
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, RustboroCity_PokemonSchool_EventScript_00202CC1
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, RustboroCity_PokemonSchool_EventScript_00202CCF
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, RustboroCity_PokemonSchool_EventScript_00202CCF
	end

RustboroCity_PokemonSchool_EventScript_00202C89::
	loadword 0x0, gJPText_00202E63
	callstd 0x4
	goto RustboroCity_PokemonSchool_EventScript_00202C2A
	end

RustboroCity_PokemonSchool_EventScript_00202C97::
	loadword 0x0, gJPText_00202EAF
	callstd 0x4
	goto RustboroCity_PokemonSchool_EventScript_00202C2A
	end

RustboroCity_PokemonSchool_EventScript_00202CA5::
	loadword 0x0, gJPText_00202EF5
	callstd 0x4
	goto RustboroCity_PokemonSchool_EventScript_00202C2A
	end

RustboroCity_PokemonSchool_EventScript_00202CB3::
	loadword 0x0, gJPText_00202F56
	callstd 0x4
	goto RustboroCity_PokemonSchool_EventScript_00202C2A
	end

RustboroCity_PokemonSchool_EventScript_00202CC1::
	loadword 0x0, gJPText_00202FA7
	callstd 0x4
	goto RustboroCity_PokemonSchool_EventScript_00202C2A
	end

RustboroCity_PokemonSchool_EventScript_00202CCF::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_00202CD1::
	loadword 0x0, gJPText_002030B2
	callstd 0x2
	end

RustboroCity_PokemonSchool_EventScript_00202CDA::
	loadword 0x0, gJPText_002030CD
	callstd 0x2
	end

RustboroCity_PokemonSchool_EventScript_00202CE3::
	loadword 0x0, gJPText_002030EA
	callstd 0x2
	end

RustboroCity_PokemonSchool_EventScript_00202CEC::
	loadword 0x0, gJPText_00203128
	callstd 0x2
	end

RustboroCity_PokemonSchool_EventScript_00202CF5::
	loadword 0x0, gJPText_0020318A
	callstd 0x2
	end

RustboroCity_PokemonSchool_EventScript_00202CFE::
	loadword 0x0, gJPText_002031E4
	callstd 0x3
	end

RustboroCity_PokemonSchool_EventScript_00202D07::
	lock
	faceplayer
	checkflag 0x113
	goto_if 0x1, RustboroCity_PokemonSchool_EventScript_00202D6D
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, RustboroCity_PokemonSchool_EventScript_00202D57
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, RustboroCity_PokemonSchool_EventScript_00202D62
	loadword 0x0, gJPText_00202FE5
	callstd 0x4
	setorcopyvar 0x8000, 0xB7
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	closemessage
	applymovement 0x800F, 0x0824362D
	waitmovement 0x0
	setflag 0x113
	release
	end

RustboroCity_PokemonSchool_EventScript_00202D57::
	applymovement 0x800F, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0x0
	return

RustboroCity_PokemonSchool_EventScript_00202D62::
	applymovement 0x800F, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0x0
	return

RustboroCity_PokemonSchool_EventScript_00202D6D::
	loadword 0x0, gJPText_00203045
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x0824362D
	waitmovement 0x0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_00202DB2::
	lock
	faceplayer
	checkflag 0x1CB
	goto_if 0x1, RustboroCity_PokemonSchool_EventScript_00202E1A
	checkflag 0x136
	goto_if 0x1, RustboroCity_PokemonSchool_EventScript_00202DE1
	checkflag 0x867
	goto_if 0x1, RustboroCity_PokemonSchool_EventScript_00202DF4
	loadword 0x0, gJPText_00203274
	callstd 0x4
	addvar 0x40D1, 0x1
	setflag 0x136
	release
	end

RustboroCity_PokemonSchool_EventScript_00202DE1::
	checkflag 0x867
	goto_if 0x1, RustboroCity_PokemonSchool_EventScript_00202E02
	loadword 0x0, gJPText_00203339
	callstd 0x4
	release
	end

RustboroCity_PokemonSchool_EventScript_00202DF4::
	loadword 0x0, gJPText_002033DD
	callstd 0x4
	goto RustboroCity_PokemonSchool_EventScript_00202E10
	end

RustboroCity_PokemonSchool_EventScript_00202E02::
	loadword 0x0, gJPText_0020336D
	callstd 0x4
	goto RustboroCity_PokemonSchool_EventScript_00202E10
	end

RustboroCity_PokemonSchool_EventScript_00202E10::
	addvar 0x40D1, 0x1
	setflag 0x1CB
	release
	end

RustboroCity_PokemonSchool_EventScript_00202E1A::
	loadword 0x0, gJPText_00203339
	callstd 0x4
	release
	end

	.globl gJPText_00202E24
gJPText_00202E24: @ 0x08202E24
	.string "こくばんに\n"
	.string "ポケモンが　たたかってるときに　おこる\l"
	.string "たいちょうの　へんかに　ついて　かかれてる$"

	.globl gJPText_00202E54
gJPText_00202E54: @ 0x08202E54
	.string "どの　こうもくを　みますか？$"

	.globl gJPText_00202E63
gJPText_00202E63: @ 0x08202E63
	.string "どくを　うけると\n"
	.string "たいりょくが　へっていきます\p"
	.string "せんとうのあとも　どくは　のこるので\n"
	.string "あるくたびに　たいりょくが　へります\l"
	.string "どくけしで　なおしましょう$"

	.globl gJPText_00202EAF
gJPText_00202EAF: @ 0x08202EAF
	.string "まひすると　すばやさが　さがり\n"
	.string "ときどき　わざが　だせなくなります\p"
	.string "たたかい　おわっても　まひした　ままです\n"
	.string "まひなおしで　なおしましょう$"

	.globl gJPText_00202EF5
gJPText_00202EF5: @ 0x08202EF5
	.string "ねむって　しまうと\n"
	.string "その　あいだ　こうげき　できません\p"
	.string "じぶんで　めざめることも　ありますが\n"
	.string "ねむったまま　せんとうが　おわると\l"
	.string "ずっと　ねむっています\p"
	.string "ねむけざましで　おこして　あげましょう$"

	.globl gJPText_00202F56
gJPText_00202F56: @ 0x08202F56
	.string "やけどは　こうげきりょくが　さがるだけでなく\n"
	.string "たいりょくも　どんどん　へっていきます\p"
	.string "せんとうが　おわっても　やけどの　ままです\n"
	.string "やけどなおしで　なおしましょう$"

	.globl gJPText_00202FA7
gJPText_00202FA7: @ 0x08202FA7
	.string "こおって　しまうと　なにも　できなくなります\p"
	.string "たたかい　おわっても　こおりついた　ままです\n"
	.string "こおりなおしで　とかしましょう$"

	.globl gJPText_00202FE5
gJPText_00202FE5: @ 0x08202FE5
	.string "べんきょうを　しない　せいとは\n"
	.string "わたくしの　ツメの　あかを\l"
	.string "せんじて　のませるのです！\p"
	.string "きみが　べんきょう　する　しないは\n"
	.string "この　どうぐを　つかいこなせるか　どうかで\l"
	.string "わかること　でしょう！$"

	.globl gJPText_00203045
gJPText_00203045: @ 0x08203045
	.string "ポケモンに　せんせいのツメを　もたせると\n"
	.string "ときどき　ですが　すばやくなって\l"
	.string "せんせい　こうげきを　するのです！\p"
	.string "このように　ポケモンに　もたせる\n"
	.string "どうぐの　こと　だけでも\l"
	.string "べんきょう　することは　いっぱい　なのです！$"

	.globl gJPText_002030B2
gJPText_002030B2: @ 0x082030B2
	.string "いま　ともだちと\n"
	.string "ポケモンを　こうかん　してるんだ！$"

	.globl gJPText_002030CD
gJPText_002030CD: @ 0x082030CD
	.string "ほしかった　タネボーちゃん　が\n"
	.string "やっと　てに　はいるよ！$"

	.globl gJPText_002030EA
gJPText_002030EA: @ 0x082030EA
	.string "ポケモンも　どうぐ　もてるけど\n"
	.string "キズぐすりとか　どくけしとか\l"
	.string "ひとが　つくった　どうぐは\l"
	.string "つかいかたが　わからない　みたい$"

	.globl gJPText_00203128
gJPText_00203128: @ 0x08203128
	.string "ポケモンの　わざで\n"
	.string "こんらん　することが　あるでしょ？\p"
	.string "こんらん　すると　たまに　まちがえて\n"
	.string "じぶんを　こうげき　しちゃうの⋯⋯\p"
	.string "でも　いちどでも　せんとうから　はなれると\n"
	.string "もとに　もどるわよ！$"

	.globl gJPText_0020318A
gJPText_0020318A: @ 0x0820318A
	.string "⋯⋯ポケモンに　きのみを　もたせると\n"
	.string "じぶんで　たいりょくを　かいふくする\p"
	.string "ポケモンが　もてる　どうぐは\n"
	.string "ほかにも　たくさん⋯⋯\p"
	.string "ノートを　ちゃんと　とるのは\n"
	.string "たいへんだなあ⋯⋯$"

	.globl gJPText_002031E4
gJPText_002031E4: @ 0x082031E4
	.string "このこの　ノートだ⋯⋯\p"
	.string "ポケモンは　モンスターボールで　つかまえて\n"
	.string "どうじに　6ぴき　もちあるける\p"
	.string "そうして　つかまえた　ポケモンを\n"
	.string "そだてて　たたかわせる　ひとを\l"
	.string "ポケモントレーナーと　いう\p"
	.string "トレーナーの　もくひょうは\n"
	.string "かくちの　ポケモンジムに　いる\l"
	.string "つよい　トレーナーに　かつこと！$"

	.globl gJPText_00203274
gJPText_00203274: @ 0x08203274
	.string "おや？　きみとは　たしか\n"
	.string "トウカシティで　あった　きがするね\p"
	.string "わたしの　なまえは　エニシダ\p"
	.string "ポケモンしょうぶの　さいのうを　もった\n"
	.string "ゆうしゅうな　じんざいを　もとめて\l"
	.string "かくちを　たびして　いるのさ\p"
	.string "スクールを　のぞきにきた　ということは\n"
	.string "きみも　トレーナー？\p"
	.string "ならば　まずは　いあいぎりを\n"
	.string "ポケモンに　おぼえさせると　いいね！\p"
	.string "いあいぎりは　たしか　このまちの\n"
	.string "だれかが　もっていた　はずだよ$"

	.globl gJPText_00203339
gJPText_00203339: @ 0x08203339
	.string "エニシダ“うーん　ここに　いる\n"
	.string "せいとさん　たちの　さいのうは\l"
	.string "まだまだ　みちすう！　これから　だな！$"

	.globl gJPText_0020336D
gJPText_0020336D: @ 0x0820336D
	.string "エニシダ“ん　それは⋯⋯\n"
	.string "ストーンバッジ　だね\l"
	.string "なかなか　やるじゃ　ないか！\p"
	.string "だけど　できれば\n"
	.string "たたかっている　ところを　みたかったな\l"
	.string "リーグバッジ　だけでは　きみが\l"
	.string "どんな　トレーナー　なのかは\l"
	.string "よく　わからない　からね$"

	.globl gJPText_002033DD
gJPText_002033DD: @ 0x082033DD
	.string "おや？　きみとは　たしか\n"
	.string "トウカシティで　あった　きがするね\p"
	.string "わたしの　なまえは　エニシダ\p"
	.string "ポケモンしょうぶの　さいのうを　もった\n"
	.string "ゆうしゅうな　じんざいを　もとめて\l"
	.string "かくちを　たびして　いるのさ\p"
	.string "きみの　それは⋯⋯\n"
	.string "ストーンバッジ　だね\l"
	.string "トレーナーに　なりたてに　しては　やるね\p"
	.string "だけど　できれば\n"
	.string "たたかっている　ところを　みたかったな\l"
	.string "リーグバッジ　だけでは　きみが\l"
	.string "どんな　トレーナー　なのかは\l"
	.string "よく　わからない　からね$"
