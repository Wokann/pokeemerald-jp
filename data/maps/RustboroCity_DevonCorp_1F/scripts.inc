@ RustboroCity_DevonCorp_1F scripts (JP map g11 m0 @ 0x08201030)

RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_EventScript_00201036
	.byte 0

RustboroCity_DevonCorp_1F_EventScript_00201036::
	checkflag 0x90
	call_if 0x0, RustboroCity_DevonCorp_1F_EventScript_00201040
	end

RustboroCity_DevonCorp_1F_EventScript_00201040::
	setobjectxyperm 0x2, 0xE, 0x2
	setobjectmovementtype 0x2, 0x8
	return

RustboroCity_DevonCorp_1F_EventScript_0020104C::
	lock
	faceplayer
	checkflag 0x90
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_00201074
	checkflag 0x8E
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_0020106A
	loadword 0x0, gJPText_00201162
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_0020106A::
	loadword 0x0, gJPText_002011A8
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_00201074::
	loadword 0x0, gJPText_00201208
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_0020107E::
	lock
	faceplayer
	checkflag 0x90
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_002010A5
	checkflag 0x8F
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_002010AF
	checkflag 0x8E
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_002010AF
	loadword 0x0, gJPText_00201222
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_002010A5::
	loadword 0x0, gJPText_0020126B
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_002010AF::
	loadword 0x0, gJPText_00201249
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_002010B9::
	lock
	faceplayer
	checkflag 0x90
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_002010E0
	checkflag 0x8F
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_002010EA
	checkflag 0x8E
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_002010EA
	loadword 0x0, gJPText_00201106
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_002010E0::
	loadword 0x0, gJPText_00201106
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_002010EA::
	loadword 0x0, gJPText_00201146
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_002010F4::
	loadword 0x0, gJPText_00201284
	callstd 0x3
	end

RustboroCity_DevonCorp_1F_EventScript_002010FD::
	loadword 0x0, gJPText_00201357
	callstd 0x3
	end

	.globl gJPText_00201106
gJPText_00201106: @ 0x08201106
	.string "いらっしゃいませ！\n"
	.string "デボン　コーポレーション　です！\p"
	.string "みなさまの　せいかつに　やくだつ\n"
	.string "どうぐや　くすりを　おつくりしてます！$"

	.globl gJPText_00201146
gJPText_00201146: @ 0x08201146
	.string "ドジな　けんきゅういんが\n"
	.string "にもつを　とられちゃって⋯⋯$"

	.globl gJPText_00201162
gJPText_00201162: @ 0x08201162
	.string "おっ！　ランニングシューズ！\p"
	.string "じぶんたちの　かいしゃの　しょうひんを\n"
	.string "じっさいに　つかっている　ひとを　みると\l"
	.string "すごく　うれしくなるよね！$"

	.globl gJPText_002011A8
gJPText_002011A8: @ 0x082011A8
	.string "たしかに　あの　にもつは\n"
	.string "だいじな　もの　だけど\l"
	.string "ほかの　ひとが　ぬすんでいっても\l"
	.string "つかえないと　おもうんだよね\p"
	.string "ぼくの　すいりでは　あの　どろぼう⋯⋯\n"
	.string "たんなる　マヌケ　なんじゃないかな？$"

	.globl gJPText_00201208
gJPText_00201208: @ 0x08201208
	.string "どうやら　デボンのにもつは\n"
	.string "もどってきた　らしいね$"

	.globl gJPText_00201222
gJPText_00201222: @ 0x08201222
	.string "おっと　かんけいしゃ　いがいの　かたは\n"
	.string "ここから　さきには　はいれませんよ！$"

	.globl gJPText_00201249
gJPText_00201249: @ 0x08201249
	.string "どろぼうに　にもつを　うばわれるなんて\n"
	.string "なんて　ドジなんだろう⋯⋯$"

	.globl gJPText_0020126B
gJPText_0020126B: @ 0x0820126B
	.string "やあ！\n"
	.string "きみなら　いつでも　だいかんげい　だよ！$"

	.globl gJPText_00201284
gJPText_00201284: @ 0x08201284
	.string "いしや　きんぞくの　サンプルが\n"
	.string "ガラスケースの　なかに　ならんでいる！\p"
	.string "パネルに　せつめいが　かいてあるから\n"
	.string "よんでみよう⋯⋯\p"
	.string "‘デボン　コーポレーションは　もともと\n"
	.string "　やまから　いしを　きりだしたり\p"
	.string "　さてつから　てつざいを　つくるために\n"
	.string "　せつりつ　された　かいしゃ　です’\p"
	.string "‘やがて　デボン　コーポレーションは\n"
	.string "　ざいりょう　だけに　とどまらず\p"
	.string "　さまざまな　こうぎょう　せいひんも\n"
	.string "　つくるように　なったのです’$"

	.globl gJPText_00201357
gJPText_00201357: @ 0x08201357
	.string "いろんな　どうぐの　しさくひんが\n"
	.string "ガラスケースの　なかに　ならんでいる！\p"
	.string "パネルに　せつめいが　かいてあるから\n"
	.string "よんでみよう⋯⋯\p"
	.string "‘げんざい　デボン　コーポレーションでは\n"
	.string "　こうぎょう　せいひんの　ほかにも\l"
	.string "　にちようひんや　くすりなど\p"
	.string "　ひとびとの　くらしに　やくだつ　ものを\n"
	.string "　かいはつ　しています’\p"
	.string "‘また　げんざいでは　モンスターボールや\n"
	.string "　ポケナビなどの　トレーナーようひんも\l"
	.string "　てがけるように　なりました’$"
